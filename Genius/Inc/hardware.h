#include "main.h"
#include "stm32h7xx_hal.h"

#define OWL_GENIUS
#define HARDWARE_ID                  GENIUS_HARDWARE
#define HARDWARE_VERSION             "Genius"

#define hdac hdac1

#define USE_SCREEN
#define SSD1309
/* #define OLED_DMA */
#define OLED_SOFT_CS
#define OLED_SPI hspi2
#define USE_CODEC
#define USE_CS4271
#define CODEC_SPI hspi4

/* USB audio settings */
#define AUDIO_BITS_PER_SAMPLE       16
#define AUDIO_BYTES_PER_SAMPLE      (AUDIO_BITS_PER_SAMPLE/8)
#define AUDIO_CHANNELS              2
#define USB_AUDIO_CHANNELS          2
#define AUDIO_INT32_TO_SAMPLE(x)    ((x)>>8)
#define AUDIO_SAMPLE_TO_INT32(x)    ((int32_t)(x)<<8)

#define MAIN_LOOP_SLEEP_MS          20

/* #define USE_USBD_AUDIO */
/* #define USE_USBD_AUDIO_TX  // microphone */
/* #define USE_USBD_AUDIO_RX // speaker */
#define USE_USBD_HS
#define USBD_HANDLE hUsbDeviceHS
#define USBH_HANDLE hUsbHostFS
#define USE_USB_HOST
#define USB_HOST_RX_BUFF_SIZE 256  /* Max Received data 64 bytes */
#define USE_USBH_MIDI

#define USE_ADC
#define ADC_PERIPH hadc1
#define ADC_A 0
#define ADC_B 1
#define NOF_ADC_VALUES               2
#define NOF_PARAMETERS               20
#define NOF_BUTTONS                  (2+2)
#define USE_DAC

