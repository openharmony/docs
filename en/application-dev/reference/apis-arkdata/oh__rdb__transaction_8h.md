# oh_rdb_transaction.h


## Overview

Defines APIs and enums related to database transactions.

**File to include**: &lt;database/rdb/oh_rdb_transaction.h&gt;

**Library**: libnative_rdb_ndk.z.so

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Since**: 16

**Related module**: [RDB](_r_d_b.md)


## Summary


### Types

| Name| Description| 
| -------- | -------- |
| typedef enum [OH_RDB_TransType](_r_d_b.md#oh_rdb_transtype) [OH_RDB_TransType](_r_d_b.md#oh_rdb_transtype) | Defines an enum for transaction types.| 
| typedef struct [OH_RDB_TransOptions](_r_d_b.md#oh_rdb_transoptions) [OH_RDB_TransOptions](_r_d_b.md#oh_rdb_transoptions) | Defines the [OH_RDB_TransOptions](_r_d_b.md#oh_rdb_transoptions) struct.| 
| typedef struct [OH_Rdb_Transaction](_r_d_b.md#oh_rdb_transaction) [OH_Rdb_Transaction](_r_d_b.md#oh_rdb_transaction) | Defines the [OH_Rdb_Transaction](_r_d_b.md#oh_rdb_transaction) struct.| 


### Enums

| Name| Description| 
| -------- | -------- |
| [OH_RDB_TransType](_r_d_b.md#oh_rdb_transtype-1) { RDB_TRANS_DEFERRED = 0, RDB_TRANS_IMMEDIATE, RDB_TRANS_EXCLUSIVE, RDB_TRANS_BUTT } | Enumerates the transaction types of an RDB store.| 


### Functions

| Name| Description| 
| -------- | -------- |
| [OH_RDB_TransOptions](_r_d_b.md#oh_rdb_transoptions) \* [OH_RdbTrans_CreateOptions](_r_d_b.md#oh_rdbtrans_createoptions) (void) | Create a transaction configuration object.| 
| int [OH_RdbTrans_DestroyOptions](_r_d_b.md#oh_rdbtrans_destroyoptions) ([OH_RDB_TransOptions](_r_d_b.md#oh_rdb_transoptions) \*opitons) | Destroys a transaction configuration instance.| 
| int [OH_RdbTransOption_SetType](_r_d_b.md#oh_rdbtransoption_settype) ([OH_RDB_TransOptions](_r_d_b.md#oh_rdb_transoptions) \*opitons, [OH_RDB_TransType](_r_d_b.md#oh_rdb_transtype) type) | Sets the transaction type of an RDB store.| 
| int [OH_RdbTrans_Commit](_r_d_b.md#oh_rdbtrans_commit) ([OH_Rdb_Transaction](_r_d_b.md#oh_rdb_transaction) \*trans) | Commits a transaction.| 
| int [OH_RdbTrans_Rollback](_r_d_b.md#oh_rdbtrans_rollback) ([OH_Rdb_Transaction](_r_d_b.md#oh_rdb_transaction) \*trans) | Rolls back a transaction.| 
| int [OH_RdbTrans_Insert](_r_d_b.md#oh_rdbtrans_insert) ([OH_Rdb_Transaction](_r_d_b.md#oh_rdb_transaction) \*trans, const char \*table, const [OH_VBucket](_o_h___v_bucket.md) \*row, int64_t \*rowId) | Inserts a row of data into a table.| 
| int [OH_RdbTrans_BatchInsert](_r_d_b.md#oh_rdbtrans_batchinsert) ([OH_Rdb_Transaction](_r_d_b.md#oh_rdb_transaction) \*trans, const char \*table, const [OH_Data_VBuckets](_r_d_b.md#oh_data_vbuckets) \*rows, int64_t \*changes) | Batch inserts data into a table.| 
| int [OH_RdbTrans_Update](_r_d_b.md#oh_rdbtrans_update) ([OH_Rdb_Transaction](_r_d_b.md#oh_rdb_transaction) \*trans, const [OH_VBucket](_o_h___v_bucket.md) \*row, const [OH_Predicates](_o_h___predicates.md) \*predicates, int64_t \*changes) | Updates data in an RDB store based on specified conditions.| 
| int [OH_RdbTrans_Delete](_r_d_b.md#oh_rdbtrans_delete) ([OH_Rdb_Transaction](_r_d_b.md#oh_rdb_transaction) \*trans, const [OH_Predicates](_o_h___predicates.md) \*predicates, int64_t \*changes) | Deletes data from the database based on the specified conditions.| 
| [OH_Cursor](_o_h___cursor.md) \* [OH_RdbTrans_Query](_r_d_b.md#oh_rdbtrans_query) ([OH_Rdb_Transaction](_r_d_b.md#oh_rdb_transaction) \*trans, const [OH_Predicates](_o_h___predicates.md) \*predicates, const char \*columns[], int len) | Queries data in the database based on specified conditions.| 
| [OH_Cursor](_o_h___cursor.md) \* [OH_RdbTrans_QuerySql](_r_d_b.md#oh_rdbtrans_querysql) ([OH_Rdb_Transaction](_r_d_b.md#oh_rdb_transaction) \*trans, const char \*sql, const [OH_Data_Values](_r_d_b.md#oh_data_values) \*args) | Queries data in the database using the specified SQL statement.| 
| int [OH_RdbTrans_Execute](_r_d_b.md#oh_rdbtrans_execute) ([OH_Rdb_Transaction](_r_d_b.md#oh_rdb_transaction) \*trans, const char \*sql, const [OH_Data_Values](_r_d_b.md#oh_data_values) \*args, [OH_Data_Value](_r_d_b.md#oh_data_value) \*\*result) | Executes an SQL statement that contains specified parameters.| 
| int [OH_RdbTrans_Destroy](_r_d_b.md#oh_rdbtrans_destroy) ([OH_Rdb_Transaction](_r_d_b.md#oh_rdb_transaction) \*trans) | Destroys a transaction object.| 
