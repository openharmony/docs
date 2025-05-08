# Settings Error Codes

> **NOTE**
>
> This topic describes only module-specific error codes. For details about universal error codes, see [Universal Error Codes](../errorcode-universal.md).

## 14800000 Parameter Check Failed

**Error Message**

Parameter error. Possible causes: 1. Parameter verification failed.

**Description**

1. This error code is reported when the null parameter is incorrect.

2. This error code is reported when the parameter parsing fails.

**Possible Causes**

1. A null parameter is incorrect (Null Argument Error).

2. A value range is incorrect (Value Range Error).

**Solution**

Make sure all the mandatory parameters are passed. If parameter verification fails, read the parameter specifications and locate the fault based on the possible causes.

## 14800010 UIAbility Required

**Error Message**

Original service error.

**Description**

This error code is reported when the original service throws an error.

**Possible Causes**

The current context is not the UIAbility.

**Solution**

Perform the operation on UIAbility.
