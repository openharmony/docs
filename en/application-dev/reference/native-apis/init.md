# Init


## Overview

Provides APIs for checking SystemCapability (SycCap) support.

You can use the provided APIs to read the SycCap parameter file to check whether a specific SycCap is supported.

**Since:**

8


## Summary


### Files

| Name| Description|
| -------- | -------- |
| [syscap_ndk.h](syscap__ndk_8h.md) | Defines the APIs for checking SycCap support.|


### Functions

| Name| Description|
| -------- | -------- |
| [canIUse](#caniuse) (const char \*cap) | Checks whether a SysCap is supported. SystemCapability (SysCap) refers to a standalone feature in the operating system. Different devices support different SysCap sets. Each SysCap corresponds to one or more APIs. You can determine whether an API can be used by checking SysCap support.|


## Function Description


### canIUse()


```
bool canIUse (const char * cap)
```

**Description**

Checks whether a SysCap is supported. SystemCapability (SysCap) refers to a standalone feature in the operating system. Different devices support different SysCap sets. Each SysCap corresponds to one or more APIs. You can determine whether an API can be used by checking SysCap support.

**Parameters**

| Name| Description|
| -------- | -------- |
| cap | Name of the SysCap to check.|

**Returns**

Check result. The value **true** means that the SysCap is supported, and **false** means the opposite.
