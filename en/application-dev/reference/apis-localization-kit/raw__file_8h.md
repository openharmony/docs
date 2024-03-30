# raw_file.h


## Overview

Provides functions related to rawfiles, including searching for, reading, and closing rawfiles.

**Since**: 8

**Related module**: [Rawfile] (rawfile.md)


## Summary


### Structs

| Name| Description| 
| -------- | -------- |
| [RawFileDescriptor](_raw_file_descriptor.md) | Defines the file descriptor of a rawfile.| 
| [RawFileDescriptor64](_raw_file_descriptor64.md) | Defines the file descriptor of a large rawfile.<br>**NOTE**<br>This new API supports large rawfiles and provides better performance.| 


### Types

| Name| Description| 
| -------- | -------- |
| [RawFile](rawfile.md#rawfile) | Provides access to the rawfiles in the **rawfile** directory.| 
| [RawFile64](rawfile.md#rawfile64) | Provides access to the rawfiles in the **rawfile** directory.<br>**NOTE**<br>This new API supports large rawfiles and provides better performance.| 


### Function

| Name| Description| 
| -------- | -------- |
| [OH_ResourceManager_ReadRawFile](rawfile.md#oh_resourcemanager_readrawfile) (const [RawFile](rawfile.md#rawfile) \*rawFile, void \*buf, size_t length) | Reads data of the specified length from the current position in a rawfile.| 
| [OH_ResourceManager_SeekRawFile](rawfile.md#oh_resourcemanager_seekrawfile) (const [RawFile](rawfile.md#rawfile) \*rawFile, long offset, int whence) | Searches for the data read/write position based on the specified offset (in long) in a rawfile.| 
| [OH_ResourceManager_GetRawFileSize](rawfile.md#oh_resourcemanager_getrawfilesize) ([RawFile](rawfile.md#rawfile) \*rawFile) | Obtains the length of the rawfile, in long.| 
| [OH_ResourceManager_GetRawFileRemainingLength](rawfile.md#oh_resourcemanager_getrawfileremaininglength) (const [RawFile](rawfile.md#rawfile) \*rawFile) | Obtains the remaining length of the rawfile, in long.| 
| [OH_ResourceManager_CloseRawFile](rawfile.md#oh_resourcemanager_closerawfile) ([RawFile](rawfile.md#rawfile) \*rawFile) | Closes a [RawFile](rawfile.md#rawfile) and releases all associated resources.| 
| [OH_ResourceManager_GetRawFileOffset](rawfile.md#oh_resourcemanager_getrawfileoffset) (const [RawFile](rawfile.md#rawfile) \*rawFile) | Obtains the current offset of a rawfile, in long.| 
| [OH_ResourceManager_GetRawFileDescriptor](rawfile.md#oh_resourcemanager_getrawfiledescriptor) (const [RawFile](rawfile.md#rawfile) \*rawFile, [RawFileDescriptor](_raw_file_descriptor.md) &amp;descriptor) | Opens a rawfile based on the specified offset and file length and obtains the file descriptor.| 
| [OH_ResourceManager_ReleaseRawFileDescriptor](rawfile.md#oh_resourcemanager_releaserawfiledescriptor) (const [RawFileDescriptor](_raw_file_descriptor.md) &amp;descriptor) | Releases the file descriptor of a rawfile.| 
| [OH_ResourceManager_ReadRawFile64](rawfile.md#oh_resourcemanager_readrawfile64) (const [RawFile64](rawfile.md#rawfile64) \*rawFile, void \*buf, int64_t length) | Reads data of the specified length from the current position in a rawfile.<br>**NOTE**<br>This new API supports large rawfiles and provides better performance.| 
| [OH_ResourceManager_SeekRawFile64](rawfile.md#oh_resourcemanager_seekrawfile64) (const [RawFile64](rawfile.md#rawfile64) \*rawFile, int64_t offset, int whence) | Searches for the data read/write position based on the specified offset (in int64_t) in a large rawfile.| 
| [OH_ResourceManager_GetRawFileSize64](rawfile.md#oh_resourcemanager_getrawfilesize64) ([RawFile64](rawfile.md#rawfile64) \*rawFile) | Obtains the length of a large rawfile, in int64_t.| 
| [OH_ResourceManager_GetRawFileRemainingLength64](rawfile.md#oh_resourcemanager_getrawfileremaininglength64) (const [RawFile64](rawfile.md#rawfile64) \*rawFile) | Obtains the remaining length of a rawfile, in long.| 
| [OH_ResourceManager_CloseRawFile64](rawfile.md#oh_resourcemanager_closerawfile64) ([RawFile64](rawfile.md#rawfile64) \*rawFile) | Closes a [RawFile64](rawfile.md#rawfile) and releases all associated resources.| 
| [OH_ResourceManager_GetRawFileOffset64](rawfile.md#oh_resourcemanager_getrawfileoffset64) (const [RawFile64](rawfile.md#rawfile64) \*rawFile) | Obtains the offset of a large rawfile, in int64_t.| 
| [OH_ResourceManager_GetRawFileDescriptor64](rawfile.md#oh_resourcemanager_getrawfiledescriptor64) (const [RawFile64](rawfile.md#rawfile64) \*rawFile, [RawFileDescriptor64](_raw_file_descriptor64.md) \*descriptor) | Opens a rawfile based on the specified offset and file length and obtains the file descriptor.| 
| [OH_ResourceManager_ReleaseRawFileDescriptor64](rawfile.md#oh_resourcemanager_releaserawfiledescriptor64) (const [RawFileDescriptor64](_raw_file_descriptor64.md) \*descriptor) | Releases the file descriptor of a rawfile.| 
