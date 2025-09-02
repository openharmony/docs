# RawFileDescriptor

## Overview

Defines the file descriptor of a rawfile. **RawFileDescriptor** is an output parameter of [OH_ResourceManager_GetRawFileDescriptor](capi-raw-file-h.md#oh_resourcemanager_getrawfiledescriptor). It contains the file descriptor of a rawfile and the start position and length of the rawfile in the HAP.

**Since**: 8

**Related module**: [rawfile](capi-rawfile.md)

**Header file**: [raw_file.h](capi-raw-file-h.md)

## Summary

### Member Variables

| Name| Description|
| -- | -- |
| int fd | File descriptor of the rawfile, in int.|
| long start | Start position of the rawfile in the HAP, in long.|
| long length | Length of the rawfile in the HAP, in long.|
