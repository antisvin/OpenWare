#ifndef __FlashStorage_hpp__
#define __FlashStorage_hpp__

#include <inttypes.h>
#include <string.h>
#include "device.h"
#include "BaseStorage.hpp"
#include "FlashStorageBlock.hpp"
#include "eepromcontrol.h"
#include "message.h"

extern char _FLASH_STORAGE_BEGIN;
extern char _FLASH_STORAGE_END;
#define EEPROM_PAGE_BEGIN ((uint32_t)&_FLASH_STORAGE_BEGIN)
#define EEPROM_PAGE_END ((uint32_t)&_FLASH_STORAGE_END)

#ifdef OWL_ARCH_L4
#define EEPROM_PAGE_SIZE (8 * 1024)
#else
#define EEPROM_PAGE_SIZE (128 * 1024)
#endif

using StorageBlock = FlashStorageBlock;
using Storage = BaseStorage<FlashStorageBlock>;


#if 0
// This probably belongs to BaseStorages template, however we must not run it in some
// cases (i.e. for readonly Qspi). We might add something like .isWritable() method
// to storage for such cases.
template<>
inline void Storage::recover(){
  StorageBlock block = getLastBlock();
  if(!block.isFree() && !block.isValidSize()){
    // count backwards to see how much free space (0xff words) there is
    uint32_t* top = (uint32_t*)block.getData();
    uint32_t* ptr = (uint32_t*)(end_page);
    uint32_t free = 0;
    while(--ptr > top && *ptr == 0xffffffff)
      free += 4;
    uint32_t size = (ptr-top)*4;
    // write size to last block, and update magick to deleted
    block.setSize(size);
    block.setDeleted();
    // add empty block to end
    if(count+1 < max_blocks)
      blocks[count++] = createBlock(ptr, 4); // createBlock(ptr+4);
  }
}
#endif


// erase entire allocated FLASH memory
template<>
inline void Storage::erase() {
  uint32_t page = start_page;
  eeprom_unlock();
  while (page < end_page) {
    eeprom_erase(page);
    page += EEPROM_PAGE_SIZE;
  }
  eeprom_lock();
  init();
}

template<>
inline void Storage::defrag(void *buffer, uint32_t size) {
  // ASSERT(size >= getWrittenSize(), "Insufficient space for full defrag");
  uint8_t *ptr = (uint8_t *)buffer;
  if (getDeletedSize() > 0 && getWrittenSize() > 0) {
    uint32_t offset = 0;
    for (uint8_t i = 0; i < count && offset < size; ++i) {
      if (blocks[i].verify()) {
        memcpy(ptr + offset, blocks[i].getBlock(), blocks[i].getBlockSize());
        offset += blocks[i].getBlockSize();
      }
    }
    erase();
    eeprom_unlock();
    eeprom_write_block(start_page, buffer, offset);
    eeprom_lock();
    init();
  }
}

extern Storage storage;

#endif // __FlashStorage_hpp__
