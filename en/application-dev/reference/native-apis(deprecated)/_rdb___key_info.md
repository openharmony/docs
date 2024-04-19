# Rdb_KeyInfo


## Overview

Defines a struct for the primary key or row number of the row that changes.

**Since**: 11

**Related modules**: [RDB](_r_d_b.md)


## Summary


### Structs

| Name| Description|
| -------- | -------- |
| [Rdb_KeyData](union_rdb___key_info_1_1_rdb___key_data.md) | Changed data.|


### Member Variables

| Name| Description|
| -------- | -------- |
| [count](_r_d_b.md#count) | Number of the changed primary keys or row numbers.|
| [type](_r_d_b.md#type) | Primary key type (OH_ColumnType).|
| **data** | [Rdb_KeyInfo::Rdb_KeyData](union_rdb___key_info_1_1_rdb___key_data.md) that holds the changed data.|
