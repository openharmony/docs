# Rdb_KeyInfo

## Overview

Defines a struct for the primary key or number of the row that changes.

**Since**: 11

**Related module**: [RDB](capi-rdb.md)

**Header file**: [relational_store.h](capi-relational-store-h.md)

## Summary

### Member Variables

| Name                                         | Description                                                  |
| -------------------------------------------- | ------------------------------------------------------------ |
| int count                                    | Number of the changed primary keys or row numbers.           |
| int type                                     | Type of the primary key. For details, see [OH_ColumnType](capi-oh-data-value-h.md#oh_columntype). |
| [Rdb_KeyData](capi-rdb-rdb-keydata.md)* data | Holds the changed data.                                      |
