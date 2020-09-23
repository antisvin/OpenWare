#include <string.h>
#include <stdlib.h>
#include <stdio.h>
//#include "Daisy.h"
#include "device.h"
#include "Owl.h"
#include "Graphics.h"
//#include "errorhandlers.h"
#include "message.h"
#include "gpio.h"
#include "qspicontrol.h"
#include "ProgramManager.h"
#include "PatchRegistry.h"
#include "OpenWareMidiControl.h"
#include "SoftwareEncoder.hpp"


static SoftwareEncoder encoder(
  ENC_A_GPIO_Port, ENC_A_Pin,
  ENC_B_GPIO_Port, ENC_B_Pin, 
  ENC_CLICK_GPIO_Port, ENC_CLICK_Pin);


extern "C" void updateEncoderCounter(){
  encoder.updateCounter();
}

void setGateValue(uint8_t ch, int16_t value){
  switch(ch){
  case PUSHBUTTON:
  case BUTTON_A:
    HAL_GPIO_WritePin(GATE_OUT_GPIO_Port, GATE_OUT_Pin, value ? GPIO_PIN_SET :  GPIO_PIN_RESET);
    break;
  }
}


void updateParameters(int16_t* parameter_values, size_t parameter_len, uint16_t* adc_values, size_t adc_len){
#ifdef USE_CACHE
  SCB_InvalidateDCache_by_Addr((uint32_t*)adc_values, sizeof(adc_values));
#endif
  // Note that updateValue will apply smoothing, so we don't have to do it here
  graphics.params.updateValue(0, 4095 - adc_values[0]);
  graphics.params.updateValue(1, 4095 - adc_values[0]);
  graphics.params.updateValue(2, 4095 - adc_values[0]);
  graphics.params.updateValue(3, 4095 - adc_values[0]);
}


void setup(){
  HAL_GPIO_WritePin(OLED_RST_GPIO_Port, OLED_RST_Pin, GPIO_PIN_RESET); // OLED off

  if (qspi_init(QSPI_MODE_MEMORY_MAPPED) != MEMORY_OK){
    // We can end here only if QSPI settings are misconfigured
    error(RUNTIME_ERROR, "Flash init error");
  }

  extern SPI_HandleTypeDef OLED_SPI;
  graphics.begin(&OLED_SPI);

  owl_setup();
}

static int16_t enc_data[2];

void loop(void){
#ifdef USE_CACHE
  #ifdef USE_SCREEN
  SCB_CleanInvalidateDCache_by_Addr((uint32_t*)&graphics.params.user, sizeof(graphics.params.user));
  #endif
#endif

  encoder.debounce();
  enc_data[0] = int16_t(encoder.isFallingEdge() | encoder.isLongPress() << 1);
  enc_data[1] = int16_t(encoder.getValue());
  graphics.params.updateEncoders(enc_data, 1);

  for(int i = NOF_ADC_VALUES; i < NOF_PARAMETERS; ++i) {
    graphics.params.updateValue(i, 0);
  }

  
  owl_loop();
}
