# syscap_ndk.h


## Overview

Provides the API for querying whether a SystemCapability (SysCap) is supported. SysCap refers to a standalone feature in the operating system. Different devices support different SysCap sets. Each SysCap corresponds to one or more APIs. You can determine whether an API can be used by checking SysCap support.

**Since**

8

**Related module**

[Init](init.md)


## Summary


### Functions

| Name| Description|
| -------- | -------- |
| [canIUse](init.md#caniuse) (const char \*cap) | Checks whether a SysCap is supported.|
