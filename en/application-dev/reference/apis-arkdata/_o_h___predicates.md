# OH_Predicates


## Overview

Defines the predicates for RDB stores.

**Since**: 10

**Related module**: [RDB](_r_d_b.md)


## Summary


### Member Variables

| Name| Description|
| -------- | -------- |
| [id](_r_d_b.md#id-25) | Unique identifier of the **OH_Predicates** struct.|
| [equalTo](_r_d_b.md#equalto) | Pointer to the function used to set a predicates object to match the field whose value is equal to the specified value.|
| [notEqualTo](_r_d_b.md#notequalto) | Pointer to the function used to set a predicates object to match the field whose value is not equal to the specified value.|
| [beginWrap](_r_d_b.md#beginwrap) | Pointer to the function used to add a left parenthesis to the predicates.|
| [endWrap](_r_d_b.md#endwrap) | Pointer to the function used to add a right parenthesis to the predicates.|
| [orOperate](_r_d_b.md#oroperate) | Pointer to the function used to add the OR operator to the predicates.|
| [andOperate](_r_d_b.md#andoperate) | Pointer to the function used to add the AND operator to the predicates.|
| [isNull](_r_d_b.md#isnull-22) | Pointer to the function used to set a predicates object to match the field whose value is null.|
| [isNotNull](_r_d_b.md#isnotnull) | Pointer to the function used to set a predicates object to match the field whose value is not null.|
| [like](_r_d_b.md#like) | Pointer to the function used to set a predicates object to match a string that is similar to the specified value.|
| [between](_r_d_b.md#between) | Pointer to the function used to set a predicates object to match the field whose value is within the specified range.|
| [notBetween](_r_d_b.md#notbetween) | Pointer to the function used to set a predicates object to match the field whose value is out of the specified range.|
| [greaterThan](_r_d_b.md#greaterthan) | Pointer to the function used to set a predicates object to match the field with value greater than the specified value.|
| [lessThan](_r_d_b.md#lessthan) | Pointer to the function used to set a predicates object to match the field with value less than the specified value.|
| [greaterThanOrEqualTo](_r_d_b.md#greaterthanorequalto) | Pointer to the function used to set a predicates object to match the field with value greater than or equal to the specified value.|
| [lessThanOrEqualTo](_r_d_b.md#lessthanorequalto) | Pointer to the function used to set a predicates object to match the field with value less than or equal to the specified value.|
| [orderBy](_r_d_b.md#orderby) | Pointer to the function used to set a predicates object to sort the values in a column in ascending or descending order.|
| [distinct](_r_d_b.md#distinct) | Pointer to the function used to set a predicates object to filter out duplicate records.|
| [limit](_r_d_b.md#limit) | Pointer to the function used to set a predicates object to specify the maximum number of records.|
| [offset](_r_d_b.md#offset) | Pointer to the function used to set a predicates object to specify the start position of the returned result.|
| [groupBy](_r_d_b.md#groupby) | Pointer to the function used to set a predicates object to group rows that have the same value into summary rows.|
| [in](_r_d_b.md#in) | Pointer to the function used to set a predicates object to match the field with the value within the specified range.|
| [notIn](_r_d_b.md#notin) | Pointer to the function used to set a predicates object to match the field with the value out of the specified range.|
| [clear](_r_d_b.md#clear-12) | Pointer to the function used to clear a predicates instance.|
| [destroy](_r_d_b.md#destroy-24) | Destroys an **OH_Predicates** object and reclaims the memory occupied.|
