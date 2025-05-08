# oh_rdb_types.h


## Overview

Provides type definitions related to data values.

**Library**: libnative_rdb_ndk.z.so

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Since**: 18

**Related module**: [RDB](_r_d_b.md)


## Summary


### Types

| Name| Description| 
| -------- | -------- |
| typedef enum [Rdb_ConflictResolution](_r_d_b.md#rdb_conflictresolution) [Rdb_ConflictResolution](_r_d_b.md#rdb_conflictresolution) | Defines an enum for conflict resolution policies. | 


### Enums

| Name| Description| 
| -------- | -------- |
| [Rdb_ConflictResolution](_r_d_b.md#rdb_conflictresolution-1) {<br>RDB_CONFLICT_NONE = 1, RDB_CONFLICT_ROLLBACK, RDB_CONFLICT_ABORT, RDB_CONFLICT_FAIL,<br>RDB_CONFLICT_IGNORE, RDB_CONFLICT_REPLACE<br>} | Enumerates the conflict resolution policies. | 
