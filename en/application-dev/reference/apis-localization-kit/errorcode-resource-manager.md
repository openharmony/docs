# Resource Manager Error Codes

> **NOTE**
>
> This topic describes only module-specific error codes. For details about universal error codes, see [Universal Error Codes](../errorcode-universal.md).

## 9001001 Invalid Resource ID

**Error Message**

Invalid resource ID.

**Description**

This error code is reported if the specified resId meets the type requirement but the **resId** does not exist.

**Possible Causes**

The specified **resId** does not exist.

**Solution**

Check whether the specified **resId** exists.

## 9001002 Matching Resource Not Found Based on the Specified Resource ID

**Error Message**

No matching resource is found based on the resource ID.

**Description**

This error code is reported if the specified **resId** meets the type requirement but no resource is found based on the **resId**.

**Possible Causes**

1. The specified **resId** is incorrect.

2. Resource parsing is incorrect.

**Solution**

Check whether the specified **resId** is correct.

## 9001003 Invalid Resource Name

**Error Message**

Invalid resource name.

**Description**

This error code is reported if the specified **resName** meets the type requirement but the **resName** does not exist.

**Possible Causes**

The specified **resName** does not exist.

**Solution**

Check whether the specified **resName** is correct.

## 9001004 Matching Resource Not Found Based on the Specified Resource Name

**Error Message**

No matching resource is found based on the resource name.

**Description**

This error code is reported if the specified resId meets the type requirement but no resource is found based on the **resId**.

**Possible Causes**

1. The specified **resName** is incorrect.

2. Resource parsing is incorrect.

**Solution**

Check whether the specified **resName** is correct.

## 9001005 Invalid Relative Path

**Error Message**

Invalid relative path.

**Description**

This error code is reported if no resource is found based on the specified relative path.

**Possible Causes**

The specified relative path is incorrect.

**Solution**

Check whether the specified relative path is correct.

## 9001006 Cyclic Reference

**Error Message**

The resource is referenced cyclically.

**Description**

This error code is reported if resources are referenced cyclically.

**Possible Causes**

Resources are referenced cyclically.

**Solution**

Check the reference of resource $, and remove the cyclic reference, if any.

## 9001007 Failed to Format the Resource Obtained Based on resId

**Error Message**

Failed to format the resource obtained based on the resource ID.

**Description**

This error code is reported in the case of a failure to format the string resource obtained based on **resId**.

**Possible Causes**

1. The parameter type is not supported.

2. The numbers of parameters and placeholders are inconsistent.

3. The parameter does not match the placeholder type.

**Solution**

Check whether the number and type of **args** parameters are the same as those of placeholders.

## 9001008 Failed to Format the Resource Obtained Based on resName

**Error Message**

Failed to format the resource obtained based on the resource Name.

**Description**

This error code is reported in the case of a failure to format the string resource obtained based on **resName**.

**Possible Causes**

1. The parameter type is not supported.

2. The numbers of parameters and placeholders are inconsistent.

3. The parameter does not match the placeholder type.

**Solution**

Check whether the number and type of **args** parameters are the same as those of placeholders.

## 9001009 Failed to Obtain a ResourceManager Object

**Error Message**

Failed to access the system resource.

**Description**

This error code is reported in the case of a failure to obtain a ResourceManager object.

**Possible Causes**

System resources are not loaded to the sandbox path of the application process.

**Solution**

Check whether the application process contains the sandbox path of system resources.

## 9001010 Invalid Overlay Path

**Error Message**

Invalid overlay path.

**Description**

This error code is reported if the specified overlay path is invalid.

**Possible Causes**

The path does not exist or is not in the installation path of the application.

**Solution**

Check the location of the specified overlay path.
