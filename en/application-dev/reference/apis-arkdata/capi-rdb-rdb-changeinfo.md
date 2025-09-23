# Rdb_ChangeInfo
<!--Kit: ArkData-->
<!--Subsystem: DistributedDataManager-->
<!--Owner: @baijidong-->
<!--Designer: @widecode; @htt1997-->
<!--Tester: @yippo; @logic42-->
<!--Adviser: @ge-yafang-->

## Overview

Defines a struct for the details about the device-cloud sync process.

**Since**: 11

**Related module**: [RDB](capi-rdb.md)

**Header file**: [relational_store.h](capi-relational-store-h.md)

## Summary

### Member Variables

| Name                                       | Description                                                        |
| ------------------------------------------- | ------------------------------------------------------------ |
| int version                                 | Version of the **Rdb_DistributedConfig** struct.               |
| const char* tableName                       | Name of the table with data changes.                                    |
| int ChangeType                              | Type of the data changed, which can be data or asset.        |
| [Rdb_KeyInfo](capi-rdb-rdb-keyinfo.md) inserted | Location where data is inserted. If the primary key of the table is of the string type, it is the value of the primary key. Otherwise, it is the row number of the inserted data.|
| [Rdb_KeyInfo](capi-rdb-rdb-keyinfo.md) updated  | Location where data is updated. If the primary key of the table is of the string type, it is the value of the primary key. Otherwise, it is the row number of the updated data.|
| [Rdb_KeyInfo](capi-rdb-rdb-keyinfo.md) deleted  | Location where data is deleted. If the primary key of the table is of the string type, it is the value of the primary key. Otherwise, it is the row number of the deleted data.|
