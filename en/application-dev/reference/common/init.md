# Init


## Overview

Provides the API for querying the support for a SystemCapability (SysCap), which refers to a standalone feature in the operating system. Different devices support different SysCap sets. Each SysCap corresponds to one or more APIs.

The result is returned by checking the SysCap configuration file.

**Since**

8


## Summary


### Files

| Name| Description|
| -------- | -------- |
| [syscap_ndk.h](syscap__ndk_8h.md) | Provides the API for querying whether a SysCap is supported.<br>**File to include**: <syscap_ndk.h><br>**Library**: libdeviceinfo_ndk.z.so|


### Functions

| Name| Description|
| -------- | -------- |
| [canIUse](#caniuse) (const char \*cap) | Checks whether a SysCap is supported. |


## Function Description


### canIUse()


```
bool canIUse (const char * cap)
```

**Description**

Checks whether a SysCap is supported.

**Parameters**

| Name| Description|
| -------- | -------- |
| cap | Pointer to the SysCap to check. |

**Returns**

Returns **true** if the SysCap is supported; returns **false** otherwise.
