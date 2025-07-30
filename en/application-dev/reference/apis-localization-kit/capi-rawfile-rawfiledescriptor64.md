# RawFileDescriptor64

## Overview

Defines the file descriptor of a large rawfile. **RawFileDescriptor64** is an output parameter of [OH_ResourceManager_GetRawFileDescriptor64](capi-raw-file-h.md#oh_resourcemanager_getrawfiledescriptor64). It contains the file descriptor of a rawfile and the start position and length of the rawfile in the HAP.

**Since**: 11

**Related module**: [rawfile](capi-rawfile.md)

**Header file**: [raw_file.h](capi-raw-file-h.md)

## Summary

### Member Variables

| Name| Description|
| -- | -- |
| int fd | File descriptor of the rawfile, in int.|
| int64_t start | Start position of the rawfile in the HAP, in int64_t.|
| int64_t length | Length of the rawfile in the HAP, in int64_t.|
