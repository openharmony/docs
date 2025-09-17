# native_fence.h
<!--Kit: ArkGraphics 2D-->
<!--Subsystem: Graphics-->
<!--Owner: @Flix-fangyang; @li_hui180; @ding-panyun-->
<!--Designer: @conan13234-->
<!--Tester: @nobuggers-->
<!--Adviser: @ge-yafang-->
## Overview

Defines functions for obtaining and using NativeFence.

**File to import**: <native_fence/native_fence.h>

**Library**: libnative_fence.so

**System capability**: SystemCapability.Graphic.Graphic2D.NativeFence

**Since**: 20

**Related module**: [NativeFence](capi-nativefence.md)

## Total

### Functions

| Name                                                        | Description                                                        |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| [bool OH_NativeFence_IsValid(int fenceFd)](#oh_nativefence_isvalid) | Checks whether fenceFd is valid.                                       |
| [bool OH_NativeFence_Wait(int fenceFd, uint32_t timeout)](#oh_nativefence_wait) | Blocks the input fenceFd. The maximum blocking time is determined by the timeout parameter. The input fenceFd needs to be closed by the user.|
| [bool OH_NativeFence_WaitForever(int fenceFd)](#oh_nativefence_waitforever) | Permanently blocks the input fenceFd. The input fenceFd needs to be closed by the user.      |
| [void OH_NativeFence_Close(int fenceFd)](#oh_nativefence_close) | Closes fenceFd.                                               |

## Function Description

### OH_NativeFence_IsValid()

```
bool OH_NativeFence_IsValid(int fenceFd)
```

**Description**

Checks whether fenceFd is valid.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeFence

**Since**: 20


**Parameters**

| Name     | Description                              |
| ----------- | ---------------------------------- |
| int fenceFd | File descriptor for timing synchronization.|

**Return value**

| Type| Description                                                    |
| ---- | -------------------------------------------------------- |
| bool | true if fenceFd is valid; false if fenceFd is a negative integer.|

### OH_NativeFence_Wait()

```
bool OH_NativeFence_Wait(int fenceFd, uint32_t timeout)
```

**Description**

Blocks the input fenceFd. The maximum blocking time is determined by the timeout parameter. You need to close the input fenceFd by yourself.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeFence

**Since**: 20


**Parameters**

| Name          | Description                                                        |
| ---------------- | ------------------------------------------------------------ |
| int fenceFd      | File descriptor for timing synchronization.                          |
| uint32_t timeout | Waiting time. The unit is millisecond. The value –1 indicates permanent waiting, and the value 0 indicates that the API returns immediately.|

**Return value**

| Type| Description                                                        |
| ---- | ------------------------------------------------------------ |
| bool | true if the corresponding fenceFd is triggered by a signal.<br>false in the following cases:<br>1. The input fenceFd is a negative integer.<br>2. No signal is triggered within the specified timeout period.<br>3. The underlying poll API fails to be called.<br>4. The timeout period is set to 0.<br>5. The file descriptor fails to be copied in the API.|

### OH_NativeFence_WaitForever()

```
bool OH_NativeFence_WaitForever(int fenceFd)
```

**Description**

Permanently blocks the input fenceFd. You need to close the input fenceFd by yourself.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeFence

**Since**: 20


**Parameters**

| Name     | Description                              |
| ----------- | ---------------------------------- |
| int fenceFd | File descriptor for timing synchronization.|

**Return value**

| Type| Description                                                        |
| ---- | ------------------------------------------------------------ |
| bool | true if the corresponding fenceFd is triggered by a signal.<br>false in the following cases:<br>1. The input fenceFd is a negative integer.<br>2. No signal is triggered within the specified timeout period, and permanent waiting occurs.<br>3. The file descriptor fails to be copied in the API.|

### OH_NativeFence_Close()

```
void OH_NativeFence_Close(int fenceFd)
```

**Description**

Closes a fence file descriptor.

**System capability**: SystemCapability.Graphic.Graphic2D.NativeFence

**Since**: 20


**Parameters**

| Name     | Description                                                  |
| ----------- | ------------------------------------------------------ |
| int fenceFd | File descriptor for periodic synchronization. The value is a non-negative integer.|
