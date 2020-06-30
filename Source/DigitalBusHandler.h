#ifndef _DigitalBusHandler_h_
#define _DigitalBusHandler_h_

#include "bus.h"
#include "MidiReader.h"
#include "OpenWareMidiControl.h"

class DigitalBusHandler : public MidiReader {
public:
  enum DigitalBusStatus {
    IDLE = BUS_STATUS_IDLE,
    DISCOVER = BUS_STATUS_DISCOVER,
    CONNECTED = BUS_STATUS_CONNECTED,
    ERROR = BUS_STATUS_ERROR
  };
protected:
  uint32_t token;
  uint8_t peers;
  uint16_t parameterOffset;
  DigitalBusStatus status;  
  uint8_t* UUID;
  static const uint8_t VERSION = 0x01; // protocol version
  static const uint8_t PRODUCT = 0x01;  // product id
  static const uint8_t PARAMETERS = 5; // number of parameters defined by this product
  static const uint8_t NO_UID = 0xff;
  static const uint32_t NO_TOKEN = 0xffffffff;
public:
  DigitalBusHandler();
  bool connected();
  DigitalBusStatus getStatus(){
    return status;
  }
  const char* getStatusString();
  uint32_t generateToken();
  uint8_t getPeers(){ return peers; }
  void startDiscover();
  void sendDiscover(uint8_t seq, uint32_t token);
  void handleDiscover(uint8_t seq, uint32_t other);
  void sendParameterChange(uint8_t pid, int16_t value);
  void handleParameterChange(uint8_t pid, int16_t value);
  void sendButtonChange(uint8_t bid, int16_t value);
  void handleButtonChange(uint8_t bid, int16_t value);
  void sendCommand(uint8_t cmd, int16_t data);
  void handleCommand(uint8_t cmd, int16_t data);
  void sendMessage(const char* msg);
  void handleMessage(const char* msg);
  void sendData(const uint8_t* data, uint32_t len);
  void handleData(const uint8_t* data, uint32_t len);
  void sendReset();
  bool rxError(const char* reason);
  bool txError(const char* reason);
  // send a 4-byte bus or midi message
  void sendFrame(uint8_t d1, uint8_t d2, uint8_t d3, uint8_t d4);
  void sendFrame(uint8_t* frame);
  static bool isMidiFrame(uint8_t* frame);
  void (*discoverCallback)(void);
  void (*commandCallback)(uint8_t cmd, int16_t data);
  void (*messageCallback)(const char* msg);
  void (*dataCallback)(const uint8_t* data, uint16_t size);
  void setDiscoverCallback(void *callback) {
    discoverCallback = (void (*)(void))callback;
  }
  void setCommandCallback(void *callback) {
    commandCallback = (void (*)(uint8_t, int16_t))callback;
  }
  void setMessageCallback(void *callback) {
    messageCallback = (void (*)(const char *))callback;
  }
  void setDataCallback(void *callback) {
    dataCallback = (void (*)(const uint8_t*, uint16_t))callback;
  }
};

#endif /* _DigitalBusHandler_h_ */
