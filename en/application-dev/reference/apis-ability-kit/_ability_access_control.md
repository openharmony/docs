# AbilityAccessControl


## Overview

Provides the system capability for implementing application access control.

**Since**: 12


## Summary


### Files

| Name| Description|
| -------- | -------- |
| [ability_access_control.h](ability__access__control_8h.md) | Declares the APIs for implementing application access control. |


### Functions

| Name| Description|
| -------- | -------- |
| bool [OH_AT_CheckSelfPermission](#oh_at_checkselfpermission)(const char \*permission) | Checks whether a permission is granted to this application. |


## Function Description


### OH_AT_CheckSelfPermission()

```
bool OH_AT_CheckSelfPermission(const char* permission)
```
**Description**
Checks whether a permission is granted to this application.

**Since**: 12

**Parameters**

| Name| Description|
| -------- | -------- |
| permission | Pointer to the permission to check. For details about the permission, see the application permission list. |

**Returns**

Returns **true** if the permission has been granted to the application; returns **false** otherwise.
