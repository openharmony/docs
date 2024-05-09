# RawFileDescriptor


## Overview

Defines the file descriptor information of a file in the **rawfile** directory.

**RawFileDescriptor** is an output parameter of [OH_ResourceManager_GetRawFileDescriptor()](rawfile.md#oh_resourcemanager_getrawfiledescriptor). It contains the file descriptor of a raw file and the start position and length of the raw file in the HAP.

**Since**

8

**Related module**

[Rawfile](rawfile.md)


## Summary


### Member Variables

| Name| Description|
| -------- | -------- |
| [fd](#fd) | File descriptor of the raw file.|
| [start](#start) | Start position of the raw file in the HAP.|
| [length](#length) | Length of the raw file in the HAP.|


## Member Variable Description


### fd


```
int RawFileDescriptor::fd
```

**Description**

File descriptor of the raw file.


### length


```
long RawFileDescriptor::length
```

**Description**

Length of the raw file in the HAP.


### start


```
long RawFileDescriptor::start
```

**Description**

Start position of the raw file in the HAP.
