# RawFileDescriptor64


## Overview

Defines the file descriptor of a large rawfile.

**RawFileDescriptor** is an output parameter of [OH_ResourceManager_GetRawFileDescriptor64](rawfile.md#oh_resourcemanager_getrawfiledescriptor64). It contains the file descriptor of a rawfile and the start position and length of the rawfile in the HAP.

**Since**: 11

**Related module**: [Rawfile] (rawfile.md)

**Header file**: [raw_file.h](raw__file_8h.md)

## Summary


### Member Variables

| Name| Description| 
| -------- | -------- |
| int [fd](#fd) | File descriptor of the rawfile, in int. | 
| int64_t [start](#start) | Start position of the rawfile in the HAP, in int64_t. | 
| int64_t [length](#length) | Length of the rawfile in the HAP, in int64_t. | 


## Member Variable Description


### fd

```
int RawFileDescriptor64::fd
```
**Description**

File descriptor of the rawfile, in int.


### length

```
int64_t RawFileDescriptor64::length
```
**Description**

Length of the rawfile in the HAP, in int64_t.


### start

```
int64_t RawFileDescriptor64::start
```
**Description**

Start position of the rawfile in the HAP, in int64_t.
