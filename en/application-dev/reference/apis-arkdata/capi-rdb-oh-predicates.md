# OH_Predicates
<!--Kit: ArkData-->
<!--Subsystem: DistributedDataManager-->
<!--Owner: @baijidong-->
<!--Designer: @widecode; @htt1997-->
<!--Tester: @yippo; @logic42-->
<!--Adviser: @ge-yafang-->

## Overview

Defines a **predicates** object.

**Since**: 10

**Related module**: [RDB](capi-rdb.md)

**Header file**: [oh_predicates.h](capi-oh-predicates-h.md)

### Member Variables

| Name      | Description                            |
| ---------- | -------------------------------- |
| int64_t id | Unique identifier of the **H_Predicates** struct.|

### Member Functions

| Name                                                        | Description                                                        |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| [OH_Predicates *(*equalTo)(OH_Predicates *predicates, const char *field, OH_VObject *valueObject)](#equalto) | Pointer to the function used to create a predicates object to search for the field values that are equal to the specified value.          |
| [OH_Predicates *(*notEqualTo)(OH_Predicates *predicates, const char *field, OH_VObject *valueObject)](#notequalto) | Pointer to the function used to create a predicates object to search for the field values that are not equal to the specified value.<br>This method is equivalent to "!=" in SQL statements.|
| [OH_Predicates *(*beginWrap)(OH_Predicates *predicates)](#beginwrap) | Pointer to the function used to add a left parenthesis to the predicates.<br>This method is equivalent to "(" in SQL statements.|
| [OH_Predicates *(*endWrap)(OH_Predicates *predicates)](#endwrap) | Pointer to the function used to add a right parenthesis to the predicates.<br>This method is equivalent to ")" in SQL statements.|
| [OH_Predicates *(*orOperate)(OH_Predicates *predicates)](#oroperate) | Pointer to the function used to add the OR operator to the predicates.<br>This method is equivalent to **OR** in SQL statements.|
| [OH_Predicates *(*andOperate)(OH_Predicates *predicates)](#andoperate) | Pointer to the function used to add the AND operator to the predicates.<br>This method is equivalent to **AND** in SQL statements.|
| [OH_Predicates *(*isNull)(OH_Predicates *predicates, const char *field)](#isnull) | Pointer to the function used to create a predicates object to search for the field values that are null.<br>This method is equivalent to **IS NULL** in SQL statements.|
| [OH_Predicates *(*isNotNull)(OH_Predicates *predicates, const char *field)](#isnotnull) | Pointer to the function used to create a predicates object to search for the field values that are not null.<br>This method is equivalent to **IS NOT NULL** in SQL statements.|
| [OH_Predicates *(*like)(OH_Predicates *predicates, const char *field, OH_VObject *valueObject)](#like) | Pointer to the function used to create a predicates object to search for the field values that are similar to the specified string.<br>This method is equivalent to **LIKE** in SQL statements.|
| [OH_Predicates *(*between)(OH_Predicates *predicates, const char *field, OH_VObject *valueObject)](#between) | Pointer to the function used to create a predicates object to search for the field values that are within the specified range.<br>This method is equivalent to **BETWEEN** in SQL statements.|
| [OH_Predicates *(*notBetween)(OH_Predicates *predicates, const char *field, OH_VObject *valueObject)](#notbetween) | Pointer to the function used to create a predicates object to search for the field values that are out of the specified range.<br>This method is equivalent to **NOT BETWEEN** in SQL statements.|
| [OH_Predicates *(*greaterThan)(OH_Predicates *predicates, const char *field, OH_VObject *valueObject)](#greaterthan) | Pointer to the function used to create a predicates object to search for the field values that are greater than the specified value.<br>This method is equivalent to ">" in SQL statements.|
| [OH_Predicates *(*lessThan)(OH_Predicates *predicates, const char *field, OH_VObject *valueObject)](#lessthan) | Pointer to the function used to create a predicates object to search for the records that are less than the given value in the specified field.<br>This method is equivalent to "<" in SQL statements.|
| [OH_Predicates *(*greaterThanOrEqualTo)(OH_Predicates *predicates, const char *field, OH_VObject *valueObject)](#greaterthanorequalto) | Pointer to the function used to create a predicates object to search for the field values that are greater than or equal to the specified value.<br>This method is equivalent to ">=" in SQL statements.|
| [OH_Predicates *(*lessThanOrEqualTo)(OH_Predicates *predicates, const char *field, OH_VObject *valueObject)](#lessthanorequalto) | Pointer to the function used to create a predicates object to search for the records that are less than or equal to the specified **valueObject** in the specified field.<br>This method is equivalent to "<=" in SQL statements.|
| [OH_Predicates *(*orderBy)(OH_Predicates *predicates, const char *field, OH_OrderType type)](#orderby) | Pointer to the function used to create a predicates object to sort the values in the specified column in ascending or descending order.<br>This method is equivalent to **ORDER BY** in SQL statements.|
| [OH_Predicates *(*distinct)(OH_Predicates *predicates)](#distinct) | Pointer to the function used to create a predicates object to filter out duplicate records.<br>This method is equivalent to **DISTINCT** in SQL statements.|
| [OH_Predicates *(*limit)(OH_Predicates *predicates, unsigned int value)](#limit) | Pointer to the function used to create a predicates object to specify the maximum number of records.<br>This method is equivalent to **LIMIT** in SQL statements.|
| [OH_Predicates *(*offset)(OH_Predicates *predicates, unsigned int rowOffset)](#offset) | Pointer to the function used to create a predicates object to specify the start position of the query result.<br>This method is equivalent to **OFFSET** in SQL statements.|
| [OH_Predicates *(*groupBy)(OH_Predicates *predicates, char const *const *fields, int length)](#groupby) | Pointer to the function used to create a predicates object to group the results by the specified columns.<br>This method is equivalent to **GROUP BY** in SQL statements.|
| [OH_Predicates *(*in)(OH_Predicates *predicates, const char *field, OH_VObject *valueObject)](#in) | Pointer to the function used to create a predicates object to search for the field values that are within the specified range.<br>This method is equivalent to **IN** in SQL statements.|
| [OH_Predicates *(*notIn)(OH_Predicates *predicates, const char *field, OH_VObject *valueObject)](#notin) | Pointer to the function used to create a predicates object to search for the field values that are out of the specified range.<br>This method is equivalent to **NOT IN** in SQL statements.|
| [OH_Predicates *(*clear)(OH_Predicates *predicates)](#clear) | Pointer to the function used to clear a predicates instance.                                        |
| [int (*destroy)(OH_Predicates *predicates)](#destroy)        | Destroys an **OH_Predicates** object and reclaims the memory occupied.             |


## Member Function Description

### equalTo()

```
OH_Predicates *(*equalTo)(OH_Predicates *predicates, const char *field, OH_VObject *valueObject)
```

**Description**

Pointer to the function used to create a predicates object to search for the field values that are equal to the specified value.

**Since**: 10

**Parameters**

| Name                   | Description                                                        |
| ------------------------- | ------------------------------------------------------------ |
| OH_Predicates *predicates | Pointer to the **OH_Predicates** instance.                           |
| const char *field         | Pointer to the column name in the database table.                                            |
| [OH_VObject](capi-rdb-oh-vobject.md) *valueObject   | Pointer to an [OH_VObject](capi-rdb-oh-vobject.md) instance, indicating the value to be matched with the predicate.|

**Returns**

| Type           | Description                      |
| --------------- | -------------------------- |
| OH_Predicates * | Predicates that match the specified field.|

### notEqualTo()

```
OH_Predicates *(*notEqualTo)(OH_Predicates *predicates, const char *field, OH_VObject *valueObject)
```

**Description**

Pointer to the function used to create a predicates object to search for the field values that are not equal to the specified value.<br>This method is equivalent to "!=" in SQL statements.

**Since**: 10

**Parameters**

| Name                                       | Description                                                        |
| --------------------------------------------- | ------------------------------------------------------------ |
| OH_Predicates *predicates                     | Pointer to the **OH_Predicates** instance.                           |
| const char *field                             | Column name in the database table.                                          |
| [OH_VObject](capi-rdb-oh-vobject.md) *valueObject | Pointer to an [OH_VObject](capi-rdb-oh-vobject.md) instance, indicating the value to be matched with the predicate.|

**Returns**

| Type           | Description                      |
| --------------- | -------------------------- |
| OH_Predicates * | Predicates that match the specified field.|

### beginWrap()

```
OH_Predicates *(*beginWrap)(OH_Predicates *predicates)
```

**Description**

Pointer to the function used to add a left parenthesis to the predicates.<br>This method is equivalent to "(" in SQL statements.

**Since**: 10

**Parameters**

| Name                  | Description                             |
| ------------------------ | --------------------------------- |
| OH_Predicates *predicates | Pointer to the **OH_Predicates** instance.|

**Returns**

| Type           | Description                  |
| --------------- | ---------------------- |
| OH_Predicates * | Predicates with a left parenthesis.|

### endWrap()

```
OH_Predicates *(*endWrap)(OH_Predicates *predicates)
```

**Description**

Pointer to the function used to add a right parenthesis to the predicates.<br>This method is equivalent to ")" in SQL statements.

**Since**: 10

**Parameters**

| Name                   | Description                             |
| ------------------------- | --------------------------------- |
| OH_Predicates *predicates | Pointer to the **OH_Predicates** instance.|

**Returns**

| Type           | Description                  |
| --------------- | ---------------------- |
| OH_Predicates * | Predicates with a right parenthesis.|

### orOperate()

```
OH_Predicates *(*orOperate)(OH_Predicates *predicates)
```

**Description**

Pointer to the function used to add the OR operator to the predicates.<br>This method is equivalent to **OR** in SQL statements.

**Since**: 10

**Parameters**

| Name                   | Description                             |
| ------------------------- | --------------------------------- |
| OH_Predicates *predicates | Pointer to the **OH_Predicates** instance.|

**Returns**

| Type           | Description                  |
| --------------- | ---------------------- |
| OH_Predicates * | Predicates with the OR condition.|

### andOperate()

```
OH_Predicates *(*andOperate)(OH_Predicates *predicates)
```

**Description**

Pointer to the function used to add the AND operator to the predicates.<br>This method is equivalent to **AND** in SQL statements.

**Since**: 10

**Parameters**

| Name                   | Description                             |
| ------------------------- | --------------------------------- |
| OH_Predicates *predicates | Pointer to the **OH_Predicates** instance.|

**Returns**

| Type           | Description                  |
| --------------- | ---------------------- |
| OH_Predicates * | Predicates with the AND condition.|

### isNull()

```
OH_Predicates *(*isNull)(OH_Predicates *predicates, const char *field)
```

**Description**

Pointer to the function used to create a predicates object to search for the field values that are null.<br>This method is equivalent to **IS NULL** in SQL statements.

**Since**: 10

**Parameters**

| Name                   | Description                             |
| ------------------------- | --------------------------------- |
| OH_Predicates *predicates | Pointer to the **OH_Predicates** instance.|
| const char *field         | Column name in the database table.               |

**Returns**

| Type           | Description                      |
| --------------- | -------------------------- |
| OH_Predicates * | Predicates that match the specified field.|

### isNotNull()

```
OH_Predicates *(*isNotNull)(OH_Predicates *predicates, const char *field)
```

**Description**

Pointer to the function used to create a predicates object to search for the field values that are not null.<br>This method is equivalent to **IS NOT NULL** in SQL statements.

**Since**: 10

**Parameters**

| Name                   | Description                             |
| ------------------------- | --------------------------------- |
| OH_Predicates *predicates | Pointer to the **OH_Predicates** instance.|
| const char *field         | Column name in the database table.               |

**Returns**

| Type           | Description                      |
| --------------- | -------------------------- |
| OH_Predicates * | Predicates that match the specified field.|

### like()

```
OH_Predicates *(*like)(OH_Predicates *predicates, const char *field, OH_VObject *valueObject)
```

**Description**

Pointer to the function used to create a predicates object to search for the field values that are similar to the specified string.<br>This method is equivalent to **LIKE** in SQL statements.

**Since**: 10

**Parameters**

| Name                                       | Description                                                        |
| --------------------------------------------- | ------------------------------------------------------------ |
| OH_Predicates *predicates                     | Pointer to the **OH_Predicates** instance.                           |
| const char *field                             | Column name in the database table.                                          |
| [OH_VObject](capi-rdb-oh-vobject.md) *valueObject | Pointer to an [OH_VObject](capi-rdb-oh-vobject.md) instance, indicating the value to be matched with the predicate.|

**Returns**

| Type           | Description                      |
| --------------- | -------------------------- |
| OH_Predicates * | Predicates that match the specified field.|


### between()

```
OH_Predicates *(*between)(OH_Predicates *predicates, const char *field, OH_VObject *valueObject)
```

**Description**

Pointer to the function used to create a predicates object to search for the field values that are within the specified range.<br>This method is equivalent to **BETWEEN** in SQL statements.

**Since**: 10

**Parameters**

| Name                                       | Description                                                        |
| --------------------------------------------- | ------------------------------------------------------------ |
| OH_Predicates *predicates                     | Pointer to the **OH_Predicates** instance.                           |
| const char *field                             | Column name in the database table.                                          |
| [OH_VObject](capi-rdb-oh-vobject.md) *valueObject | Pointer to an [OH_VObject](capi-rdb-oh-vobject.md) instance, indicating the value to be matched with the predicate.|

**Returns**

| Type           | Description                      |
| --------------- | -------------------------- |
| OH_Predicates * | Predicates that match the specified field.|

### notBetween()

```
OH_Predicates *(*notBetween)(OH_Predicates *predicates, const char *field, OH_VObject *valueObject)
```

**Description**

Pointer to the function used to create a predicates object to search for the field values that are out of the specified range.<br>This method is equivalent to **NOT BETWEEN** in SQL statements.

**Since**: 10

**Parameters**

| Name                                       | Description                                                        |
| --------------------------------------------- | ------------------------------------------------------------ |
| OH_Predicates *predicates                     | Pointer to the **OH_Predicates** instance.                           |
| const char *field                             | Column name in the database table.                                          |
| [OH_VObject](capi-rdb-oh-vobject.md) *valueObject | Pointer to an [OH_VObject](capi-rdb-oh-vobject.md) instance, indicating the value to be matched with the predicate.|

**Returns**

| Type           | Description                      |
| --------------- | -------------------------- |
| OH_Predicates * | Predicates that match the specified field.|

### greaterThan()

```
OH_Predicates *(*greaterThan)(OH_Predicates *predicates, const char *field, OH_VObject *valueObject)
```

**Description**

Pointer to the function used to create a predicates object to search for the field values that are greater than the specified value.<br>This method is equivalent to ">" in SQL statements.

**Since**: 10

**Parameters**

| Name                                       | Description                                                        |
| --------------------------------------------- | ------------------------------------------------------------ |
| OH_Predicates *predicates                     | Pointer to the **OH_Predicates** instance.                           |
| const char *field                             | Column name in the database table.                                          |
| [OH_VObject](capi-rdb-oh-vobject.md) *valueObject | Pointer to an [OH_VObject](capi-rdb-oh-vobject.md) instance, indicating the value to be matched with the predicate.|

**Returns**

| Type           | Description                      |
| --------------- | -------------------------- |
| OH_Predicates * | Predicates that match the specified field.|

### lessThan()

```
OH_Predicates *(*lessThan)(OH_Predicates *predicates, const char *field, OH_VObject *valueObject)
```

**Description**

Pointer to the function used to create a predicates object to search for the records that are less than the given value in the specified field.<br>This method is equivalent to "<" in SQL statements.

**Since**: 10

**Parameters**

| Name                                       | Description                                                        |
| --------------------------------------------- | ------------------------------------------------------------ |
| OH_Predicates *predicates                     | Pointer to the **OH_Predicates** instance.                           |
| const char *field                             | Column name in the database table.                                          |
| [OH_VObject](capi-rdb-oh-vobject.md) *valueObject | Pointer to an [OH_VObject](capi-rdb-oh-vobject.md) instance, indicating the value to be matched with the predicate.|

**Returns**

| Type           | Description                      |
| --------------- | -------------------------- |
| OH_Predicates * | Predicates that match the specified field.|

### greaterThanOrEqualTo()

```
OH_Predicates *(*greaterThanOrEqualTo)(OH_Predicates *predicates, const char *field, OH_VObject *valueObject)
```

**Description**

Pointer to the function used to create a predicates object to search for the field values that are greater than or equal to the specified value.<br>This method is equivalent to ">=" in SQL statements.

**Since**: 10

**Parameters**

| Name                                       | Description                                                        |
| --------------------------------------------- | ------------------------------------------------------------ |
| OH_Predicates *predicates                     | Pointer to the **OH_Predicates** instance.                           |
| const char *field                             | Column name in the database table.                                          |
| [OH_VObject](capi-rdb-oh-vobject.md) *valueObject | Pointer to an [OH_VObject](capi-rdb-oh-vobject.md) instance, indicating the value to be matched with the predicate.|

**Returns**

| Type           | Description                      |
| --------------- | -------------------------- |
| OH_Predicates * | Predicates that match the specified field.|

### lessThanOrEqualTo()

```
OH_Predicates *(*lessThanOrEqualTo)(OH_Predicates *predicates, const char *field, OH_VObject *valueObject)
```

**Description**

Pointer to the function used to create a predicates object to search for the records that are less than or equal to the specified **valueObject** in the specified field.<br>This method is equivalent to "<=" in SQL statements.

**Since**: 10

**Parameters**

| Name                   | Description                                                        |
| ------------------------- | ------------------------------------------------------------ |
| OH_Predicates *predicates | Pointer to the **OH_Predicates** instance.                           |
| const char *field         | Column name in the database table.                                          |
| OH_VObject *valueObject   | Pointer to an [OH_VObject](capi-rdb-oh-vobject.md) instance, indicating the value to be matched with the predicate.|

**Returns**

| Type           | Description                      |
| --------------- | -------------------------- |
| OH_Predicates * | Predicates that match the specified field.|

### orderBy()

```
OH_Predicates *(*orderBy)(OH_Predicates *predicates, const char *field, OH_OrderType type)
```

**Description**

Pointer to the function used to create a predicates object to sort the values in the specified column in ascending or descending order.<br>This method is equivalent to **ORDER BY** in SQL statements.

**Since**: 10

**Parameters**

| Name                               | Description                                          |
| ------------------------------------- | ---------------------------------------------- |
| OH_Predicates *predicates             | Pointer to the **OH_Predicates** instance.             |
| const char *field                     | Column name in the database table.                            |
| [OH_VObject](capi-rdb-oh-vobject.md) type | Sorting type, which is an [OH_VObject](capi-rdb-oh-vobject.md).|

**Returns**

| Type           | Description                      |
| --------------- | -------------------------- |
| OH_Predicates * | Predicates that match the specified field.|

### distinct()

```
OH_Predicates *(*distinct)(OH_Predicates *predicates)
```

**Description**

Pointer to the function used to create a predicates object to filter out duplicate records.<br>This method is equivalent to **DISTINCT** in SQL statements.

**Since**: 10

**Parameters**

| Name                   | Description                             |
| ------------------------- | --------------------------------- |
| OH_Predicates *predicates | Pointer to the **OH_Predicates** instance.|

**Returns**

| Type           | Description                          |
| --------------- | ------------------------------ |
| OH_Predicates * | Predicates that can filter out duplicate records.|

### limit()

```
OH_Predicates *(*limit)(OH_Predicates *predicates, unsigned int value)
```

**Description**

Pointer to the function used to create a predicates object to specify the maximum number of records.<br>This method is equivalent to **LIMIT** in SQL statements.

**Since**: 10

**Parameters**

| Name                   | Description                             |
| ------------------------- | --------------------------------- |
| OH_Predicates *predicates | Pointer to the **OH_Predicates** instance.|
| unsigned int value        | Maximum number of data records.             |

**Returns**

| Type           | Description                                |
| --------------- | ------------------------------------ |
| OH_Predicates * | Predicates that specify the maximum number of records.|

### offset()

```
OH_Predicates *(*offset)(OH_Predicates *predicates, unsigned int rowOffset)
```

**Description**

Pointer to the function used to create a predicates object to specify the start position of the query result.<br>This method is equivalent to **OFFSET** in SQL statements.

**Since**: 10

**Parameters**

| Name                   | Description                              |
| ------------------------- | ---------------------------------- |
| OH_Predicates *predicates | Pointer to the **OH_Predicates** instance. |
| unsigned int rowOffset    | Start position, which is a positive integer.|

**Returns**

| Type           | Description                                |
| --------------- | ------------------------------------ |
| OH_Predicates * | Predicates that specify the start position of the returned result.|

### groupBy()

```
OH_Predicates *(*groupBy)(OH_Predicates *predicates, char const *const *fields, int length)
```

**Description**

Pointer to the function used to create a predicates object to group the results by the specified columns.<br>This method is equivalent to **GROUP BY** in SQL statements.

**Since**: 10

**Parameters**

| Name                   | Description                                                |
| ------------------------- | ---------------------------------------------------- |
| OH_Predicates *predicates | Pointer to the **OH_Predicates** instance.                   |
| char const *const *fields | Names of columns to group.                                |
| int length                | Length of **fields**.|

**Returns**

| Type           | Description                  |
| --------------- | ---------------------- |
| OH_Predicates * | Predicates that group rows with the same value.|

### in()

```
OH_Predicates *(*in)(OH_Predicates *predicates, const char *field, OH_VObject *valueObject)
```

**Description**

Pointer to the function used to create a predicates object to search for the field values that are within the specified range.<br>This method is equivalent to **IN** in SQL statements.

**Since**: 10

**Parameters**

| Name                                       | Description                                                        |
| --------------------------------------------- | ------------------------------------------------------------ |
| OH_Predicates *predicates                     | Pointer to the **OH_Predicates** instance.                           |
| const char *field                             | Pointer to the column name in the database table.                                      |
| [OH_VObject](capi-rdb-oh-vobject.md) *valueObject | Pointer to an [OH_VObject](capi-rdb-oh-vobject.md) instance, indicating the value to be matched with the predicate.|

**Returns**

| Type           | Description                      |
| --------------- | -------------------------- |
| OH_Predicates * | Predicates that match the specified field.|

### notIn()

```
OH_Predicates *(*notIn)(OH_Predicates *predicates, const char *field, OH_VObject *valueObject)
```

**Description**

Pointer to the function used to create a predicates object to search for the field values that are out of the specified range.<br>This method is equivalent to **NOT IN** in SQL statements.

**Since**: 10

**Parameters**

| Name                                       | Description                                                        |
| --------------------------------------------- | ------------------------------------------------------------ |
| OH_Predicates *predicates                     | Pointer to the **OH_Predicates** instance.                           |
| const char *field                             | Pointer to the column name in the database table.                                      |
| [OH_VObject](capi-rdb-oh-vobject.md) *valueObject | Pointer to an [OH_VObject](capi-rdb-oh-vobject.md) instance, indicating the value to be matched with the predicate.|

**Returns**

| Type           | Description                      |
| --------------- | -------------------------- |
| OH_Predicates * | Predicates that match the specified field.|

### clear()

```
OH_Predicates *(*clear)(OH_Predicates *predicates)
```

**Description**

Pointer to the function used to clear a predicates instance.

**Since**: 10

**Parameters**

| Name                   | Description                             |
| ------------------------- | --------------------------------- |
| OH_Predicates *predicates | Pointer to the **OH_Predicates** instance.|

**Returns**

| Type           | Description              |
| --------------- | ------------------ |
| OH_Predicates * | Cleared predicates.|

### destroy()

```
int (*destroy)(OH_Predicates *predicates)
```

**Description**

Pointer to the function used to destroy an **OH_Predicates** object and reclaim the memory occupied.

**Since**: 10

**Parameters**

| Name                   | Description                             |
| ------------------------- | --------------------------------- |
| OH_Predicates *predicates | Pointer to the **OH_Predicates** instance.|

**Returns**

| Type| Description                                      |
| ---- | ------------------------------------------ |
| int  | Returns **RDB_OK** if the operation is successful; returns an error code otherwise.|
