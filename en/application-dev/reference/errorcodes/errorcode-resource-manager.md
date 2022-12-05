# Resource Manager Error Codes

## 9001001 Invalid Resource ID

**Error Message**

The resId invalid.

**Description**

This error code is reported if the specified resource ID meets the type requirement but the resource ID does not exist.

**Possible Causes**

The specified resource ID does not exist.

**Solution**

Check whether the specified resource ID exists.

## 9001002 Matching Resource Not Found Based on the Specified Resource ID

**Error Message**

The resource not found by resId.

**Description**

This error code is reported if the specified resource ID meets the type requirement but the no resource is found based on the resource ID.

**Possible Causes**

1. The specified resource ID is incorrect.

2. Resource parsing is incorrect.

**Solution**

Check whether the specified resource ID is correct.

## 9001003 Invalid Resource Name

**Error Message**

The resName invalid.

**Description**

This error code is reported if the specified resource name meets the type requirement but the resource name does not exist.

**Possible Causes**

The specified resource name does not exist.

**Solution**

Check whether the specified resource name is correct.

## 9001004 Matching Resource Not Found Based on the Specified Resource Name

**Error Message**

The resource not found by resName.

**Description**

This error code is reported if the specified resource ID meets the type requirement but the no resource is found based on the resource ID.

**Possible Causes**

1. The specified resource name is incorrect.

2. Resource parsing is incorrect.

**Solution**

Check whether the specified resource name is correct.

## 9001005 Invalid Relative Path

**Error Message**

The resource not found by path.

**Description**

This error code is reported if no resource is found based on the specified relative path.

**Possible Causes**

The specified relative path is incorrect.

**Solution**

Check whether the specified relative path is correct.

## 9001006 Cyclic Reference

**Error Message**

the resource re-ref too much.

**Description**

This error code is reported if resources are referenced cyclically.

**Possible Causes**

Resources are referenced cyclically.

**Solution**

Check the reference of resource $, and remove the cyclic reference, if any.
