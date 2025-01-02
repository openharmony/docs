# AbilityAccessControl


## Overview

Provides the system capability for implementing process access control.

**Since**: 12


## Summary


### Files

| Name| Description|
| -------- | -------- |
| [ability_access_control.h](ability__access__control_8h.md) | Declares the APIs for implementing process access control. |


### Functions

| Name| Description|
| -------- | -------- |
| bool [OH_AT_CheckSelfPermission](#oh_at_checkselfpermission)(const char \*permission) | Checks whether the specified permission is granted to the application. |


## Function Description


### OH_AT_CheckSelfPermission()

```
bool OH_AT_CheckSelfPermission(const char* permission)
```
**Description**

Checks whether the specified permission is granted to the application.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| permission | Permission to check. For details about the permissions, see the application permission list. |

**Returns**

Returns **true** if the permission has been granted to the application; returns **false** otherwise.
