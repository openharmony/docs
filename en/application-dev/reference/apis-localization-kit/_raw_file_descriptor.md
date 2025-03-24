# RawFileDescriptor


## Overview

Defines the file descriptor of a rawfile.

**RawFileDescriptor** is an output parameter of [OH_ResourceManager_GetRawFileDescriptor()](rawfile.md#oh_resourcemanager_getrawfiledescriptor). It contains the file descriptor of a raw file and the start position and length of the raw file in the HAP.

**Since**: 8

**Related module**: [Rawfile] (rawfile.md)


## Summary


### Member Variables

| Name| Description| 
| -------- | -------- |
| int [fd](#fd) | File descriptor of the rawfile, in int. | 
| long [start](#start) | Start position of the rawfile in the HAP, in long. | 
| long [length](#length) | Length of the rawfile in the HAP, in long. | 


## Member Variable Description


### fd

```
int RawFileDescriptor::fd
```
**Description**

File descriptor of the rawfile, in int.


### length

```
long RawFileDescriptor::length
```
**Description**

Length of the rawfile in the HAP, in long.


### start

```
long RawFileDescriptor::start
```
**Description**

Start position of the rawfile in the HAP, in long.
