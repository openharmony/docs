# OH_VObject
<!--Kit: ArkData-->
<!--Subsystem: DistributedDataManager-->
<!--Owner: @baijidong-->
<!--Designer: @widecode; @htt1997-->
<!--Tester: @yippo; @logic42-->
<!--Adviser: @ge-yafang-->

## Overview

Defines a struct for allowed data types.

**Since**: 10

**Related module**: [RDB](capi-rdb.md)

**Header file**: [oh_value_object.h](capi-oh-value-object-h.md)

## Summary

### Member Variables

| Name      | Description                          |
| ---------- | ------------------------------ |
| int64_t id | Unique identifier of the **OH_VObject** struct.|

### Member Functions

| Name                                                        | Description                                                    |
| ------------------------------------------------------------ | -------------------------------------------------------- |
| [int (*putInt64)(OH_VObject *valueObject, int64_t *value, uint32_t count))](#putint64) | Converts a single parameter or an array of the int64 type into a value of the OH_VObject type. |
| [int (*putDouble)(OH_VObject *valueObject, double *value, uint32_t count)](#putdouble) | Converts a single parameter or an array of the double type into a value of the OH_VObject type.|
| [int (*putText)(OH_VObject *valueObject, const char *value)](#puttext) | Converts a character array of the char * type to a value of the OH_VObject type.        |
| [int (*putTexts)(OH_VObject *valueObject, const char **value, uint32_t count)](#puttexts) | Converts a string array of the char * type to a value of the OH_VObject type.      |
| [int (*destroy)(OH_VObject *valueObject)](#destroy)          | Destroys an **OH_VObject** object and reclaims the memory occupied.                    |

## Member Function Description

### putInt64()

```
int (*putInt64)(OH_VObject *valueObject, int64_t *value, uint32_t count))
```

**Description**

Converts a single parameter or an array of the int64 type into a value of the OH_VObject type.

**Since**: 10

**Parameters**

| Name                 | Description                                                        |
| ----------------------- | ------------------------------------------------------------ |
| OH_VObject *valueObject | Pointer to the **OH_VObject** instance.                              |
| int64_t *value          | Pointer to the data to covert.               |
| uint32_t count          | If **value** points to a single parameter, **count** is **1**. If **value** points to an array, **count** specifies the length of the array.|

**Returns**

| Type| Description                                      |
| ---- | ------------------------------------------ |
| int  | Returns **RDB_OK** if the operation is successful; returns an error code otherwise.|

### putDouble()

```
int (*putDouble)(OH_VObject *valueObject, double *value, uint32_t count)
```

**Description**

Converts a single parameter or an array of the double type into a value of the OH_VObject type.

**Since**: 10

**Parameters**

| Name                 | Description                                                        |
| ----------------------- | ------------------------------------------------------------ |
| OH_VObject *valueObject | Pointer to the **OH_VObject** instance.                              |
| double *value           | Pointer to the data to covert.                |
| uint32_t count          | If **value** points to a single parameter, **count** is **1**. If **value** points to an array, **count** specifies the length of the array.|

**Returns**

| Type| Description                                      |
| ---- | ------------------------------------------ |
| int  | Returns **RDB_OK** if the operation is successful; returns an error code otherwise.|

### putText()

```
int (*putText)(OH_VObject *valueObject, const char *value)
```

**Description**

Converts a character array of the char * type to a value of the OH_VObject type.

**Since**: 10

**Parameters**

| Name                 | Description                          |
| ----------------------- | ------------------------------ |
| OH_VObject *valueObject | Pointer to the **OH_VObject** instance.|
| const char *value       | Pointer to the character array to convert.            |

**Returns**

| Type| Description                                      |
| ---- | ------------------------------------------ |
| int  | Returns **RDB_OK** if the operation is successful; returns an error code otherwise.|

### putTexts()

```
int (*putTexts)(OH_VObject *valueObject, const char **value, uint32_t count)
```

**Description**

Converts a string array of the char * type to a value of the OH_VObject type.

**Since**: 10

**Parameters**

| Name                 | Description                           |
| ----------------------- | ------------------------------- |
| OH_VObject *valueObject | Pointer to the **OH_VObject** instance. |
| const char **value      | Double pointer to the string array to convert.           |
| uint32_t count          | Length of the string array to convert.|

**Returns**

| Type| Description                                      |
| ---- | ------------------------------------------ |
| int  | Returns **RDB_OK** if the operation is successful; returns an error code otherwise.|

### destroy()

```
int (*destroy)(OH_VObject *valueObject)
```

**Description**

Destroys an **OH_VObject** object and reclaims the memory occupied.

**Since**: 10

**Parameters**

| Name                 | Description                          |
| ----------------------- | ------------------------------ |
| OH_VObject *valueObject | Pointer to the **OH_VObject** instance.|

**Returns**

| Type| Description                                      |
| ---- | ------------------------------------------ |
| int  | Returns **RDB_OK** if the operation is successful; returns an error code otherwise.|
