#ifndef __PatchRegistry_h__
#define __PatchRegistry_h__

#include "device.h"
#include "PatchDefinition.hpp"
#include "StorageBlock.h"
#include "ResourceHeader.h"
#include "FlashStorage.h"

class PatchRegistry;

#ifndef DAISY
extern PatchRegistry registry;
#define settings_registry registry
#define patch_registry registry
#else
extern PatchRegistry settings_registry;
extern PatchRegistry patch_registry;
#endif

// This class should probably be refactored to separate resource management and patch registry

class PatchRegistry {
public:
  PatchRegistry();
  void init(FlashStorage* flash_storage);
  /* const char* getName(unsigned int index); */
  const char* getPatchName(unsigned int index);
  const char* getResourceName(unsigned int index);
  PatchDefinition* getPatchDefinition(unsigned int index);
  unsigned int getNumberOfPatches();
  void registerPatch(PatchDefinition* def);
  void setDynamicPatchDefinition(PatchDefinition* def){
    dynamicPatchDefinition = def;
  }
  ResourceHeader* getResource(uint8_t index);
  ResourceHeader* getResource(const char* name);
  void store(uint8_t index, uint8_t* data, size_t size);
private:
  FlashStorage* storage;
  bool isPresetBlock(StorageBlock block);
  StorageBlock patchblocks[MAX_NUMBER_OF_PATCHES];
  StorageBlock resourceblocks[MAX_NUMBER_OF_RESOURCES];
  PatchDefinition* defs[MAX_NUMBER_OF_PATCHES];
  uint8_t patchCount;
  PatchDefinition* dynamicPatchDefinition;
};

#endif // __PatchRegistry_h__
