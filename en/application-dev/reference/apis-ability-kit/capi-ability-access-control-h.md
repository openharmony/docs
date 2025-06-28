# ability_access_control.h

## Overview

Declares the APIs for implementing application access control.

**Library**: ability_access_control.so

**File to include**: <accesstoken/ability_access_control.h>

**System capability**: SystemCapability.Security.AccessToken

**Since**: 12

**Related module**: [AbilityAccessControl](capi-abilityaccesscontrol.md)

## Summary

### Functions

| Name| Description|
| -- | -- |
| [bool OH_AT_CheckSelfPermission(const char *permission)](#oh_at_checkselfpermission) | Checks whether a permission is granted to this application.|

## Function Description

### OH_AT_CheckSelfPermission()

```
bool OH_AT_CheckSelfPermission(const char *permission)
```

**Description**

Checks whether a permission is granted to this application.

**Since**: 12


**Parameters**

| Name| Description|
| -- | -- |
| const char *permission | Pointer to the permission to check. For details about the permission, see the application permission list.|

**Returns**

| Type| Description|
| -- | -- |
| bool | Returns **true** if the permission has been granted to the application.<br>         Returns **false** otherwise.|