# Rdb_TableDetails
<!--Kit: ArkData-->
<!--Subsystem: DistributedDataManager-->
<!--Owner: @baijidong-->
<!--Designer: @widecode; @htt1997-->
<!--Tester: @yippo; @logic42-->
<!--Adviser: @ge-yafang-->

## Overview

Defines a struct for statistics of device-cloud upload and download tasks of a database table.

**Since**: 11

**Related module**: [RDB](capi-rdb.md)

**Header file**: [relational_store.h](capi-relational-store-h.md)

## Summary

### Member Variables

| Name                                           | Description                                      |
| ----------------------------------------------- | ------------------------------------------ |
| const char* table                               | Database table name.                              |
| [Rdb_Statistic](capi-rdb-rdb-statistic.md) upload   | Statistics of the device-cloud upload tasks.|
| [Rdb_Statistic](capi-rdb-rdb-statistic.md) download | Statistics of the device-cloud download tasks.|
