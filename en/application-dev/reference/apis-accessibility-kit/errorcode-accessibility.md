# Accessibility Error Codes

> **NOTE**
>
> This topic describes only module-specific error codes. For details about universal error codes, see [Universal Error Codes](../errorcode-universal.md).
<!--Del-->
## 9300001 Invalid Bundle Name or Ability Name

**Error Message**

Invalid bundle name or ability name.

**Description**

This error code is reported when the entered bundle name or ability name is invalid.

**Possible Causes**

 
1. The bundle name does not exist.
2. The bundle does not contain the target ability.

**Solution**

1. Verify the bundle name.
2. Check whether the ability name corresponding to the bundle name is correct.

## 9300002 Target Ability Already Enabled

**Error Message**

Target ability already enabled.

**Description**

This error code is reported when the target ability is already enabled.

**Possible Causes**

The target ability is already enabled and cannot be enabled again.

**Solution**

1. Stop the target ability.
2. Re-enable the target ability.
<!--DelEnd-->
## 9300003 No Accessibility Permission to Perform the Operation

**Error Message**

No accessibility permission to perform the operation.

**Description**

This error code is reported when an application performs an accessibility operation for which the related permission has not been granted.

**Possible Causes**

The permission for performing the accessibility operation is not granted when the accessibility application is enabled.

**Solution**

1. Request from the user the permission for performing the accessibility operation, stating the reason for the request.
2. Have the accessibility application re-enabled and the required accessibility operation enabled.

## 9300004 Attribute Not Found

**Error Message**

This property does not exist.

**Description**

This error code is reported when the entered attribute of the accessibility element does not exist.

**Possible Causes**

The attribute does not exist in the accessibility element.

**Solution**

Make sure the accessibility element has the target attribute.

## 9300005 Operation Not Supported

**Error Message**

This action is not supported.

**Description**

This error code is reported when the application performs an operation that is not supported by the accessibility element.

**Possible Causes**

The accessibility element does not support the target operation.

**Solution**

Make sure the operation is included in the list of operations supported by the accessibility element.
