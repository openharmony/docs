# OHExtDataHandle


## Overview

The **OHExtDataHandle** struct describes the extended data handle.

**Since**: 9

**Deprecated**: This struct is deprecated since API version 10. No substitute is provided.

**Related module**: [NativeWindow](_native_window.md)


## Summary


### Member Variables

| Name| Description| 
| -------- | -------- |
| int32_t [fd](#fd) | File descriptor handle. The value **-1** indicates that the handle is not supported.| 
| uint32_t [reserveInts](#reserveints) | Number of reserved arrays.| 
| int32_t [reserve](#reserve) [0] | Reserved array.| 


## Member Variable Description


### fd

```
int32_t OHExtDataHandle::fd
```

**Description**

File descriptor handle. The value **-1** indicates that the handle is not supported.


### reserve

```
int32_t OHExtDataHandle::reserve[0]
```

**Description**

Reserved array.


### reserveInts

```
uint32_t OHExtDataHandle::reserveInts
```

**Description**

Number of reserved arrays.
