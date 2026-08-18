# syscap_ndk.h

<!--Kit: ArkUI-->
<!--Subsystem: Startup-->
<!--Owner: @chenjinxiang3-->
<!--Designer: @chenjinxiang3-->
<!--Tester: @liuhaonan2-->
<!--Adviser: @fang-jinxu-->
<!-- md-trans-meta sourceCommit=ccde620ca84562a446f5c2984b0afdb96762428b translatedAt=2026-08-18T12:10:23.681Z pushedAt=2026-08-18T12:14:46.874Z -->

## Overview

Provides the API for querying whether a single system capability (SystemCapability) is supported. You can query at runtime whether a device supports a specific system capability to implement differentiated feature adaptation. Typical use cases include adapting features to different device models, controlling feature degradation switches, and branching conditional features. This API is lightweight and efficient, helping you avoid crashes caused by calling APIs that the device does not support, and improving app compatibility and stability across different devices.

**Header file:** <syscap_ndk.h>

**System capability:** SystemCapability.Startup.SystemInfo

**Since:** 8

**Related module:** [Init](init.md)

## Summary

### Functions

| Name| Description|
| -------- | -------- |
| bool [canIUse](#caniuse) (const char \*cap) | Returns whether the specified system capability is supported. The value **true** indicates that it is supported, and **false** indicates that it is not. The **cap** parameter specifies the system capability name in the format of "SystemCapability.xxx.xxx". <br>A system capability (SystemCapability, or SysCap for short) refers to each relatively independent feature in the operating system. Different devices have different system capability sets, and each system capability corresponds to one or more APIs. You can determine whether an API can be used based on the system capability. <br>**Since:** 8 |

## Function Description

### canIUse()

```c
bool canIUse (const char * cap)
```

**Description**

Queries whether a specified system capability is supported. A system capability refers to each relatively independent feature in an operating system. Different devices correspond to different system capability sets, and each system capability corresponds to one or more APIs. You can determine whether an API can be used based on the system capability.

**Since:** 8

**Parameters**

| Name | Description | 
| -------- | -------- |
| cap | Name of the system capability to query. | 

**Returns**

| Type | Description | 
| -------- | -------- |
| bool | Query result of the system capability. The value **true** indicates that the system has the capability, and **false** indicates that it does not. | 