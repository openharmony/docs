# oh_cursor.h


## Overview

Provides APIs to access the result set obtained by querying the RDB store.

A result set is a set of results returned by **query()**.

**File to include**: <database/rdb/oh_cursor.h>

**Library**: libnative_rdb_ndk.z.so

**Since**: 10

**Related module**: [RDB](_r_d_b.md)


## Summary


### Structs

| Name| Description|
| -------- | -------- |
| [OH_Cursor](_o_h___cursor.md) | Defines a result set. |


### Types

| Name| Description|
| -------- | -------- |
| typedef struct [OH_Cursor](_o_h___cursor.md) [OH_Cursor](_r_d_b.md#oh_cursor) | Defines a result set.| 

### Functions

| Name| Description| 
| -------- | -------- |
| int [OH_Cursor_GetFloatVectorCount](_r_d_b.md#oh_cursor_getfloatvectorcount) ([OH_Cursor](_o_h___cursor.md) \*cursor, int32_t columnIndex, size_t \*length) | Obtains the length of a floating-point array in the specified column of the current row.| 
| int [OH_Cursor_GetFloatVector](_r_d_b.md#oh_cursor_getfloatvector) ([OH_Cursor](_o_h___cursor.md) \*cursor, int32_t columnIndex, float \*val, size_t inLen, size_t \*outLen) | Obtains the value in the specified column of the current row in the form of a floating-point array.| 
