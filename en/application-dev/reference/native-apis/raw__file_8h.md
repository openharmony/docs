# raw_file.h


## Overview

Provides functions for operating rawfiles.

These functions include searching, reading, and closing rawfiles.

**Since:**
8

**Related Modules:**

[Rawfile](rawfile.md)


## Summary


### Structs

| Name | Description | 
| -------- | -------- |
| [RawFileDescriptor](_raw_file_descriptor.md) | Provides rawfile descriptor information.  | 


### Types

| Name | Description | 
| -------- | -------- |
| [RawFile](rawfile.md#rawfile) | Provides the function of accessing rawfiles.  | 


### Functions

| Name | Description | 
| -------- | -------- |
| [OH_ResourceManager_ReadRawFile](rawfile.md#oh_resourcemanager_readrawfile) (const [RawFile](rawfile.md#rawfile) \*rawFile, void \*buf, size_t length) |Reads a rawfile.  | 
| [OH_ResourceManager_SeekRawFile](rawfile.md#oh_resourcemanager_seekrawfile) (const [RawFile](rawfile.md#rawfile) \*rawFile, long offset, int whence) |Seeks for the data read/write position in the rawfile based on the specified offset.  | 
| [OH_ResourceManager_GetRawFileSize](rawfile.md#oh_resourcemanager_getrawfilesize) ([RawFile](rawfile.md#rawfile) \*rawFile) | Obtains the length of a rawfile in int32_t.  | 
| [OH_ResourceManager_CloseRawFile](rawfile.md#oh_resourcemanager_closerawfile) ([RawFile](rawfile.md#rawfile) \*rawFile) | Closes an opened [RawFile](rawfile.md#rawfile) and releases all associated resources.  | 
| [OH_ResourceManager_GetRawFileOffset](rawfile.md#oh_resourcemanager_getrawfileoffset) (const [RawFile](rawfile.md#rawfile) \*rawFile) | Obtains the current offset of the rawfile in int32_t.  | 
| [OH_ResourceManager_GetRawFileDescriptor](rawfile.md#oh_resourcemanager_getrawfiledescriptor) (const [RawFile](rawfile.md#rawfile) \*rawFile, [RawFileDescriptor](_raw_file_descriptor.md) &amp;descriptor) | Opens a rawfile descriptor.  | 
| [OH_ResourceManager_ReleaseRawFileDescriptor](rawfile.md#oh_resourcemanager_releaserawfiledescriptor) (const [RawFileDescriptor](_raw_file_descriptor.md) &amp;descriptor) | Closes a rawfile descriptor.  | 
