# OHExtDataHandle


## Overview

Defines the extended data handle.

**Related Modules:**

[NativeWindow](_native_window.md)


## Summary


### Member Variables

| Name | Description | 
| -------- | -------- |
| [fd](#fd) | File descriptor handle. The value **-1** indicates that the handle is not supported.  | 
| [reserveInts](#reserveints) | Number of reserved arrays.  | 
| [reserve](#reserve) [0] | Reserve array.  | 


## Member Variable Description 


### fd

  
```
int32_t OHExtDataHandle::fd
```
**Description**<br>
File descriptor handle. The value **-1** indicates that the handle is not supported.


### reserve

  
```
int32_t OHExtDataHandle::reserve[0]
```
**Description**<br>
Reserve array.


### reserveInts

  
```
uint32_t OHExtDataHandle::reserveInts
```
**Description**<br>
Number of reserved arrays.
