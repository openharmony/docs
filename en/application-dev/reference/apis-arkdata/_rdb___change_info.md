# Rdb_ChangeInfo


## Overview

Defines a struct for the details about the device-cloud sync process.

**Since**: 11

**Related module**: [RDB](_r_d_b.md)


## Summary


### Member Variables

| Name| Description|
| -------- | -------- |
| [version](_r_d_b.md#version-23) | Version of the **Rdb_DistributedConfig** struct.|
| [tableName](_r_d_b.md#tablename) | Name of the table with data changes.|
| [ChangeType](_r_d_b.md#changetype) | Type of the data changed, which can be data or asset.|
| [inserted](_r_d_b.md#inserted) | Location where data is inserted. If the primary key of the table is of the string type, the value is the value of the primary key. Otherwise, the value is the row number of the inserted data.|
| [updated](_r_d_b.md#updated) | Location where data is updated. If the primary key of the table is of the string type, the value is the value of the primary key. Otherwise, the value is the row number of the updated data.|
| [deleted](_r_d_b.md#deleted) | Location where data is deleted. If the primary key of the table is of the string type, the value is the value of the primary key. Otherwise, the value is the row number of the deleted data.|
