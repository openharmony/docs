# OHExtDataHandle


## Overview

The **OHExtDataHandle** module defines the extended data handle.

**Since**

9

**Related Modules**

[NativeWindow](_native_window.md)


## Summary


### Member Variables

| Name| Description:|
| -------- | -------- |
| [fd](#fd) | File descriptor handle. The value **-1** indicates that the handle is not supported.|
| [reserveInts](#reserveints) | Number of reserved arrays.|
| [reserve](#reserve) [0] | Reserved array.|


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
