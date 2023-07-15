# RawFileDescriptor


## Overview

Provides rawfile descriptor information.

**RawFileDescriptor** is an output parameter of [OH_ResourceManager_GetRawFileDescriptor](rawfile.md#oh_resourcemanager_getrawfiledescriptor). It provides information including the rawfile descriptor and the start position and length of the rawfile in the HAP package.

**Since:**
8

**Related Modules:**

[Rawfile](rawfile.md)


## Summary


### Member Variables

| Name | Description | 
| -------- | -------- |
| [fd](#fd) |rawfile descriptor  | 
| [start](#start) | Start position of rawfile in the HAP package  | 
| [length](#length) | Length of rawfile in the HAP package  | 


## Member Variable Description 


### fd

  
```
int RawFileDescriptor::fd
```
**Description**<br>
rawfile descriptor


### length

  
```
long RawFileDescriptor::length
```
**Description**<br>
Length of rawfile in the HAP package


### start

  
```
long RawFileDescriptor::start
```
**Description**<br>
Start position of rawfile in the HAP package
