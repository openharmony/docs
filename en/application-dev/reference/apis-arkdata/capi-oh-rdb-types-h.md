# oh_rdb_types.h
<!--Kit: ArkData-->
<!--Subsystem: DistributedDataManager-->
<!--Owner: @baijidong-->
<!--Designer: @widecode; @htt1997-->
<!--Tester: @yippo; @logic42-->
<!--Adviser: @ge-yafang-->

## Overview

Defines types related to data values.

**File to include**: <database/rdb/oh_rdb_types.h>

**Library**: libnative_rdb_ndk.z.so

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Since**: 18

**Related module**: [RDB](capi-rdb.md)

## Summary

### Enums

| Name                                             | typedef Keyword         | Description                    |
| ------------------------------------------------- | ---------------------- | ------------------------ |
| [Rdb_ConflictResolution](#rdb_conflictresolution) | Rdb_ConflictResolution | Enumerates the conflict resolution policies.|

## Enum Description

### Rdb_ConflictResolution

```
enum Rdb_ConflictResolution
```

**Description**

Enumerates the conflict resolution policies.

**Since**: 18

| Enum Item               | Description                                                        |
| --------------------- | ------------------------------------------------------------ |
| RDB_CONFLICT_NONE = 1 | No operation is performed when a conflict occurs.                                  |
| RDB_CONFLICT_ROLLBACK | Throw an error and roll back the transaction.                      |
| RDB_CONFLICT_ABORT    | Throw an error and roll back the current change.                      |
| RDB_CONFLICT_FAIL     | Throw an error and abort the current change without rolling back the modifications before the conflict.    |
| RDB_CONFLICT_IGNORE   | Ignore the conflicted data and resolve the conflict later.                |
| RDB_CONFLICT_REPLACE  | Delete the data and then insert the data. If the conflict persists, apply **RDB_CONFLICT_ABORT**.|
