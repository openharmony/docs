# relational_store.h


## Overview

Provides APIs to manage a relational database (RDB) store.

**Since**

10

**Related Modules**

[RDB](_r_d_b.md)


## Summary


### Structs

| Name| Description|
| -------- | -------- |
| [OH_Rdb_Config](_o_h___rdb___config.md) | Defines the RDB store configuration.|
| [OH_Rdb_Store](_o_h___rdb___store.md) | Defines the RDB store type.|


### Types

| Name| Description|
| -------- | -------- |
| [OH_Rdb_SecurityLevel](_r_d_b.md#oh_rdb_securitylevel) | Defines the RDB store security levels. |


### Enums

| Name| Description|
| -------- | -------- |
| [OH_Rdb_SecurityLevel](_r_d_b.md#oh_rdb_securitylevel) { S1 = 1, S2, S3, S4 } | Enumerates the RDB store security levels.|


### Functions

| Name| Description|
| -------- | -------- |
| [OH_Rdb_CreateValueObject](_r_d_b.md#oh_rdb_createvalueobject) (void) | Creates an [OH_VObject](_o_h___v_object.md) instance.|
| [OH_Rdb_CreateValuesBucket](_r_d_b.md#oh_rdb_createvaluesbucket) (void) | Creates an [OH_VBucket](_o_h___v_bucket.md) instance.|
| [OH_Rdb_CreatePredicates](_r_d_b.md#oh_rdb_createpredicates) (const char \*table) | Creates an [OH_Predicates](_o_h___predicates.md) instance.|
| [OH_Rdb_GetOrOpen](_r_d_b.md#oh_rdb_getoropen) (const [OH_Rdb_Config](_o_h___rdb___config.md) \*config, int \*errCode) | Obtains an [OH_Rdb_Store](_o_h___rdb___store.md) instance for RDB store operations.|
| [OH_Rdb_CloseStore](_r_d_b.md#oh_rdb_closestore) ([OH_Rdb_Store](_o_h___rdb___store.md) \*store) | Destroys an [OH_Rdb_Store](_o_h___rdb___store.md) object and reclaims the memory occupied by the object.|
| [OH_Rdb_DeleteStore](_r_d_b.md#oh_rdb_deletestore) (const [OH_Rdb_Config](_o_h___rdb___config.md) \*config) | Deletes an RDB store with the specified database file configuration.|
| [OH_Rdb_Insert](_r_d_b.md#oh_rdb_insert) ([OH_Rdb_Store](_o_h___rdb___store.md) \*store, const char \*table, [OH_VBucket](_o_h___v_bucket.md) \*valuesBucket) | Inserts a row of data into a table.|
| [OH_Rdb_Update](_r_d_b.md#oh_rdb_update) ([OH_Rdb_Store](_o_h___rdb___store.md) \*store, [OH_VBucket](_o_h___v_bucket.md) \*valuesBucket, [OH_Predicates](_o_h___predicates.md) \*predicates) | Updates data in an RDB store based on specified conditions.|
| [OH_Rdb_Delete](_r_d_b.md#oh_rdb_delete) ([OH_Rdb_Store](_o_h___rdb___store.md) \*store, [OH_Predicates](_o_h___predicates.md) \*predicates) | Deletes data from an RDB store based on specified conditions.|
| [OH_Rdb_Query](_r_d_b.md#oh_rdb_query) ([OH_Rdb_Store](_o_h___rdb___store.md) \*store, [OH_Predicates](_o_h___predicates.md) \*predicates, const char \*const \*columnNames, int length) | Queries data in an RDB store based on specified conditions.|
| [OH_Rdb_Execute](_r_d_b.md#oh_rdb_execute) ([OH_Rdb_Store](_o_h___rdb___store.md) \*store, const char \*sql) | Executes the SQL statement that returns no value.|
| [OH_Rdb_ExecuteQuery](_r_d_b.md#oh_rdb_executequery) ([OH_Rdb_Store](_o_h___rdb___store.md) \*store, const char \*sql) | Queries data in an RDB store based on the SQL statements executed.|
| [OH_Rdb_BeginTransaction](_r_d_b.md#oh_rdb_begintransaction) ([OH_Rdb_Store](_o_h___rdb___store.md) \*store) | Starts the transaction before executing the SQL statements.|
| [OH_Rdb_RollBack](_r_d_b.md#oh_rdb_rollback) ([OH_Rdb_Store](_o_h___rdb___store.md) \*store) | Rolls back the SQL statements executed. |
| [OH_Rdb_Commit](_r_d_b.md#oh_rdb_commit) ([OH_Rdb_Store](_o_h___rdb___store.md) \*store) | Commits the executed SQL statements.|
| [OH_Rdb_Backup](_r_d_b.md#oh_rdb_backup) ([OH_Rdb_Store](_o_h___rdb___store.md) \*store, const char \*databasePath) | Backs up the RDB store in the specified path.|
| [OH_Rdb_Restore](_r_d_b.md#oh_rdb_restore) ([OH_Rdb_Store](_o_h___rdb___store.md) \*store, const char \*databasePath) | Restores an RDB store from the specified database backup file.|
| [OH_Rdb_GetVersion](_r_d_b.md#oh_rdb_getversion) ([OH_Rdb_Store](_o_h___rdb___store.md) \*store, int \*version) | Obtains the RDB store version.|
| [OH_Rdb_SetVersion](_r_d_b.md#oh_rdb_setversion) ([OH_Rdb_Store](_o_h___rdb___store.md) \*store, int version) | Sets the RDB store version.|
