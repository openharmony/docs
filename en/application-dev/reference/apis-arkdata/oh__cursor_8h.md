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
| [OH_ColumnType](_r_d_b.md#oh_columntype) | Defines the field type in the database.  |
| [OH_Cursor](_r_d_b.md#oh_cursor) | Defines a result set.  |


### Enums

| Name| Description| 
| -------- | -------- |
| [OH_ColumnType](_r_d_b.md#oh_columntype-1) {<br/>TYPE_NULL = 0, TYPE_INT64, TYPE_REAL, TYPE_TEXT,<br/>TYPE_BLOB, TYPE_ASSET, TYPE_ASSETS<br/>} | Enumerates the types of the fields in the database.  |
