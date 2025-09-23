# Interface (Transaction)
<!--Kit: ArkData-->
<!--Subsystem: DistributedDataManager-->
<!--Owner: @baijidong-->
<!--Designer: @widecode; @htt1997-->
<!--Tester: @yippo; @logic42-->
<!--Adviser: @ge-yafang-->

> **NOTE**
> 
> - The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
> - The initial APIs of this module are supported since API version 14.

Provides APIs for managing databases in transaction mode. A transaction object is created by using [createTransaction](arkts-apis-data-relationalStore-RdbStore.md#createtransaction14). Operations on different transaction objects are isolated. For details about the transaction types, see [TransactionType](arkts-apis-data-relationalStore-e.md#transactiontype14).

Currently, an RDB store supports only one write transaction at a time. If the current [RdbStore](arkts-apis-data-relationalStore-RdbStore.md) has a write transaction that is not released, creating an **IMMEDIATE** or **EXCLUSIVE** transaction object will return error 14800024. If a **DEFERRED** transaction object is created, error 14800024 may be returned when it is used to invoke a write operation for the first time. After a write transaction is created using **IMMEDIATE** or **EXCLUSIVE**, or a **DEFERRED** transaction is upgraded to a write transaction, write operations in the [RdbStore](arkts-apis-data-relationalStore-RdbStore.md) will also return error 14800024.

When the number of concurrent transactions is large and the write transaction duration is long, the frequency of returning error 14800024 may increase. You can reduce the occurrence of error 14800024 by shortening the transaction duration or by handling the error 14800024 through retries.

Before using the following APIs, you should obtain a **Transaction** instance by calling the [createTransaction](./arkts-apis-data-relationalStore-RdbStore.md#createtransaction14) method and then call the corresponding method through the instance.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Example**:

```ts
import { UIAbility } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { window } from '@kit.ArkUI';

let store: relationalStore.RdbStore | undefined = undefined;

export default class EntryAbility extends UIAbility {
  async onWindowStageCreate(windowStage: window.WindowStage) {
    const STORE_CONFIG: relationalStore.StoreConfig = {
      name: 'RdbTest.db',
      securityLevel: relationalStore.SecurityLevel.S3
    };

    try {
      const rdbStore = await relationalStore.getRdbStore(this.context, STORE_CONFIG);
      store = rdbStore;
      console.info('Get RdbStore successfully.');
    } catch (error) {
      const err = error as BusinessError;
      console.error(`Get RdbStore failed, code is ${err.code},message is ${err.message}`);
    }

    if (store != undefined) {
      await store.executeSql('CREATE TABLE IF NOT EXISTS EMPLOYEE (ID INTEGER PRIMARY KEY AUTOINCREMENT, NAME TEXT NOT NULL, AGE INTEGER, SALARY REAL, CODES BLOB, IDENTITY UNLIMITED INT, ASSETDATA ASSET, ASSETSDATA ASSETS, FLOATARRAY floatvector(128))');
      store.createTransaction().then(async (transaction: relationalStore.Transaction) => {
        console.info(`createTransaction success`);
        // Perform subsequent operations after the transaction instance is successfully obtained.
      }).catch((err: BusinessError) => {
        console.error(`createTransaction failed, code is ${err.code},message is ${err.message}`);
      });
    }
  }
}
```

## Module to Import

```ts
import { relationalStore } from '@kit.ArkData';
```

## commit<sup>14+</sup>

commit(): Promise&lt;void&gt;

Commits the executed SQL statements. When using asynchronous APIs to execute SQL statements, ensure that **commit()** is called after the asynchronous API execution is completed. Otherwise, the SQL operations may be lost. After **commit()** is called, the transaction object and the created **ResultSet** object will be closed.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Return value**

| Type               | Description                     |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [RDB Store Error Codes](errorcode-data-rdb.md). For details about how to handle error 14800011, see [Database Backup and Restore](../../database/data-backup-and-restore.md).

| **ID**| **Error Message**                                                |
|-----------| ------------------------------------------------------------ |
| 14800000  | Inner error. |
| 14800011  | Failed to open the database because it is corrupted. |
| 14800014  | The RdbStore or ResultSet is already closed. |
| 14800023  | SQLite: Access permission denied. |
| 14800024  | SQLite: The database file is locked. |
| 14800026  | SQLite: The database is out of memory. |
| 14800027  | SQLite: Attempt to write a readonly database. |
| 14800028  | SQLite: Some kind of disk I/O error occurred. |
| 14800029  | SQLite: The database is full. |

**Example**:

```ts
if (store != undefined) {
  try {
    const transaction = await store.createTransaction();
    try {
      await transaction.execute('CREATE TABLE IF NOT EXISTS test (id INTEGER PRIMARY KEY AUTOINCREMENT, name TEXT NOT NULL, age INTEGER, salary REAL)');
      await transaction.commit();
    } catch (error) {
      const err = error as BusinessError;
      await transaction.rollback();
      console.error(`execute sql failed, code is ${err.code},message is ${err.message}`);
    }
  } catch (error) {
    const err = error as BusinessError;
    console.error(`createTransaction failed, code is ${err.code},message is ${err.message}`);
  }
}
```

## rollback<sup>14+</sup>

rollback(): Promise&lt;void&gt;

Rolls back the SQL statements that have been executed. After **rollback()** is called, the transaction object and the created **ResultSet** object will be closed.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Return value**

| Type               | Description                     |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [RDB Store Error Codes](errorcode-data-rdb.md). For details about how to handle error 14800011, see [Database Backup and Restore](../../database/data-backup-and-restore.md).

| **ID**| **Error Message**                                                |
|-----------| ------------------------------------------------------------ |
| 14800000  | Inner error. |
| 14800011  | Failed to open the database because it is corrupted. |
| 14800014  | The RdbStore or ResultSet is already closed. |
| 14800023  | SQLite: Access permission denied. |
| 14800024  | SQLite: The database file is locked. |
| 14800026  | SQLite: The database is out of memory. |
| 14800027  | SQLite: Attempt to write a readonly database. |
| 14800028  | SQLite: Some kind of disk I/O error occurred. |
| 14800029  | SQLite: The database is full. |

**Example**:

```ts
if (store != undefined) {
  try {
    const transaction = await store.createTransaction();
    try {
      await transaction.execute('DELETE FROM TEST WHERE age = ? OR age = ?', ['18', '20']);
      await transaction.commit();
    } catch (error) {
      const err = error as BusinessError;
      await transaction.rollback();
      console.error(`execute sql failed, code is ${err.code},message is ${err.message}`);
    }
  } catch (error) {
    const err = error as BusinessError;
    console.error(`createTransaction failed, code is ${err.code},message is ${err.message}`);
  }
}
```

## insert<sup>14+</sup>

insert(table: string, values: ValuesBucket, conflict?: ConflictResolution): Promise&lt;number&gt;

Inserts a row of data into a table. This API uses a promise to return the result. Due to the limit of the shared memory (max. 2 MB), a single data record cannot exceed 2 MB. Otherwise, the query operation will fail.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Parameters**

| Name  | Type                                       | Mandatory| Description                      |
| -------- | ------------------------------------------- | ---- | -------------------------- |
| table    | string                                      | Yes  | Name of the target table.          |
| values   | [ValuesBucket](arkts-apis-data-relationalStore-t.md#valuesbucket)               | Yes  | Row of data to insert.|
| conflict | [ConflictResolution](arkts-apis-data-relationalStore-e.md#conflictresolution10)| No  | Resolution used to resolve the conflict. <br>Default value: **relationalStore.ConflictResolution.ON_CONFLICT_NONE**.        |

**Return value**

| Type                 | Description                                             |
| --------------------- | ------------------------------------------------- |
| Promise&lt;number&gt; | Promise used to return the result. If the operation is successful, the row ID will be returned. Otherwise, **-1** will be returned.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [RDB Store Error Codes](errorcode-data-rdb.md). For details about how to handle error 14800011, see [Database Backup and Restore](../../database/data-backup-and-restore.md).

| **ID**| **Error Message**                                                |
|-----------| ------------------------------------------------------------ |
| 401       | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 14800000  | Inner error. |
| 14800011  | Failed to open the database because it is corrupted. |
| 14800014  | The RdbStore or ResultSet is already closed. |
| 14800021  | SQLite: Generic error. Possible causes: Insert failed or the updated data does not exist. |
| 14800023  | SQLite: Access permission denied. |
| 14800024  | SQLite: The database file is locked. |
| 14800025  | SQLite: A table in the database is locked. |
| 14800026  | SQLite: The database is out of memory. |
| 14800027  | SQLite: Attempt to write a readonly database. |
| 14800028  | SQLite: Some kind of disk I/O error occurred. |
| 14800029  | SQLite: The database is full. |
| 14800031  | SQLite: TEXT or BLOB exceeds size limit. |
| 14800033  | SQLite: Data type mismatch. |
| 14800047  | The WAL file size exceeds the default limit. |

**Example**:

```ts
const valueBucket1: relationalStore.ValuesBucket = {
  NAME: 'Lisa',
  AGE: 18,
  SALARY: 100.5,
  CODES: new Uint8Array([1, 2, 3, 4, 5])
};

if (store != undefined) {
  try {
    const transaction = await store.createTransaction();
    try {
      const rowId = await transaction.insert('EMPLOYEE', valueBucket1, relationalStore.ConflictResolution.ON_CONFLICT_REPLACE);
      await transaction.commit();
      console.info(`Insert is successful, rowId = ${rowId}`);
    } catch (error) {
      const err = error as BusinessError;
      await transaction.rollback();
      console.error(`Insert is failed, code is ${err.code},message is ${err.message}`);
    }
  } catch (error) {
    const err = error as BusinessError;
    console.error(`createTransaction failed, code is ${err.code},message is ${err.message}`);
  }
}
```

## insertSync<sup>14+</sup>

insertSync(table: string, values: ValuesBucket | sendableRelationalStore.ValuesBucket, conflict?: ConflictResolution): number

Inserts a row of data into a table. This API returns the result synchronously. Due to the limit of the shared memory (max. 2 MB), a single data record cannot exceed 2 MB. Otherwise, the query operation will fail.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Parameters**

| Name  | Type                                       | Mandatory| Description                                                        |
| -------- | ------------------------------------------- | ---- | ------------------------------------------------------------ |
| table    | string                                      | Yes  | Name of the target table.                                            |
| values   | [ValuesBucket](arkts-apis-data-relationalStore-t.md#valuesbucket) \| [sendableRelationalStore.ValuesBucket](./js-apis-data-sendableRelationalStore.md#valuesbucket)   | Yes  | Row of data to insert.                                  |
| conflict | [ConflictResolution](arkts-apis-data-relationalStore-e.md#conflictresolution10)| No  | Resolution used to resolve the conflict. <br>Default value: **relationalStore.ConflictResolution.ON_CONFLICT_NONE**.|

**Return value**

| Type  | Description                                |
| ------ | ------------------------------------ |
| number | If the operation is successful, the row ID will be returned. Otherwise, **-1** will be returned.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [RDB Store Error Codes](errorcode-data-rdb.md). For details about how to handle error 14800011, see [Database Backup and Restore](../../database/data-backup-and-restore.md).

| **ID**| **Error Message**                                                |
| ------------ | ------------------------------------------------------------ |
| 401          | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 14800000     | Inner error.                                                 |
| 14800011     | Failed to open the database because it is corrupted.                                          |
| 14800014     | The RdbStore or ResultSet is already closed.                                              |
| 14800021     | SQLite: Generic error. Possible causes: Insert failed or the updated data does not exist.                                       |
| 14800023     | SQLite: Access permission denied.                            |
| 14800024     | SQLite: The database file is locked.                         |
| 14800025     | SQLite: A table in the database is locked.                   |
| 14800026     | SQLite: The database is out of memory.                       |
| 14800027     | SQLite: Attempt to write a readonly database.                |
| 14800028     | SQLite: Some kind of disk I/O error occurred.                |
| 14800029     | SQLite: The database is full.                                |
| 14800031     | SQLite: TEXT or BLOB exceeds size limit.                     |
| 14800033     | SQLite: Data type mismatch.                                  |
| 14800047     | The WAL file size exceeds the default limit.                 |

**Example**:

```ts
let value5 = 'Lisa';
let value6 = 18;
let value7 = 100.5;
let value8 = new Uint8Array([1, 2, 3, 4, 5]);

const valueBucket2: relationalStore.ValuesBucket = {
  NAME: value5,
  AGE: value6,
  SALARY: value7,
  CODES: value8
};
if (store != undefined) {
  try {
    const transaction = await store.createTransaction();
    try {
      let rowId: number = transaction.insertSync(
        'EMPLOYEE',
        valueBucket2,
        relationalStore.ConflictResolution.ON_CONFLICT_REPLACE
      );
      await transaction.commit();
      console.info(`Insert is successful, rowId = ${rowId}`);
    } catch (e) {
      await transaction.rollback();
      console.error(`Insert is failed, code is ${e.code},message is ${e.message}`);
    }
  } catch (error) {
    const err = error as BusinessError;
    console.error(`createTransaction failed, code is ${err.code},message is ${err.message}`);
  }
}
```

## batchInsert<sup>14+</sup>

batchInsert(table: string, values: Array&lt;ValuesBucket&gt;): Promise&lt;number&gt;

Batch inserts data into a table. This API uses a promise to return the result.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Parameters**

| Name| Type                                      | Mandatory| Description                        |
| ------ | ------------------------------------------ | ---- | ---------------------------- |
| table  | string                                     | Yes  | Name of the target table.            |
| values | Array&lt;[ValuesBucket](arkts-apis-data-relationalStore-t.md#valuesbucket)&gt; | Yes  | An array of data to insert.|

**Return value**

| Type                 | Description                                                       |
| --------------------- | ----------------------------------------------------------- |
| Promise&lt;number&gt; | Promise used to return the result. If the operation is successful, the number of inserted data records is returned. Otherwise, **-1** is returned.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [RDB Store Error Codes](errorcode-data-rdb.md). For details about how to handle error 14800011, see [Database Backup and Restore](../../database/data-backup-and-restore.md).

| **ID**| **Error Message**                                                |
|-----------| ------------------------------------------------------------ |
| 401       | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 14800000  | Inner error. |
| 14800011  | Failed to open the database because it is corrupted. |
| 14800014  | The RdbStore or ResultSet is already closed. |
| 14800021  | SQLite: Generic error. Possible causes: Insert failed or the updated data does not exist. |
| 14800023  | SQLite: Access permission denied. |
| 14800024  | SQLite: The database file is locked. |
| 14800025  | SQLite: A table in the database is locked. |
| 14800026  | SQLite: The database is out of memory. |
| 14800027  | SQLite: Attempt to write a readonly database. |
| 14800028  | SQLite: Some kind of disk I/O error occurred. |
| 14800029  | SQLite: The database is full. |
| 14800031  | SQLite: TEXT or BLOB exceeds size limit. |
| 14800033  | SQLite: Data type mismatch. |
| 14800047  | The WAL file size exceeds the default limit. |

**Example**:

```ts
const valueBucket3: relationalStore.ValuesBucket = {
  NAME: 'Lisa',
  AGE: 18,
  SALARY: 100.5,
  CODES: new Uint8Array([1, 2, 3, 4, 5])
};
const valueBucket4: relationalStore.ValuesBucket = {
  NAME: 'Jack',
  AGE: 19,
  SALARY: 101.5,
  CODES: new Uint8Array([6, 7, 8, 9, 10])
};
const valueBucket5: relationalStore.ValuesBucket = {
  NAME: 'Tom',
  AGE: 20,
  SALARY: 102.5,
  CODES: new Uint8Array([11, 12, 13, 14, 15])
};

let valueBuckets = new Array(valueBucket3, valueBucket4, valueBucket5);
if (store != undefined) {
  try {
    const transaction = await store.createTransaction();
    try {
      const insertNum = await transaction.batchInsert('EMPLOYEE', valueBuckets);
      await transaction.commit();
      console.info(`batchInsert is successful, the number of values that were inserted = ${insertNum}`);
    } catch (error) {
      const err = error as BusinessError;
      await transaction.rollback();
      console.error(`batchInsert is failed, code is ${err.code},message is ${err.message}`);
    }
  } catch (error) {
    const err = error as BusinessError;
    console.error(`createTransaction failed, code is ${err.code},message is ${err.message}`);
  }
}
```

## batchInsertSync<sup>14+</sup>

batchInsertSync(table: string, values: Array&lt;ValuesBucket&gt;): number

Batch inserts data into a table. This API returns the result synchronously.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Parameters**

| Name| Type                                      | Mandatory| Description                        |
| ------ | ------------------------------------------ | ---- | ---------------------------- |
| table  | string                                     | Yes  | Name of the target table.            |
| values | Array&lt;[ValuesBucket](arkts-apis-data-relationalStore-t.md#valuesbucket)&gt; | Yes  | An array of data to insert.|

**Return value**

| Type  | Description                                          |
| ------ | ---------------------------------------------- |
| number | If the operation is successful, the number of inserted data records is returned. Otherwise, **-1** is returned.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [RDB Store Error Codes](errorcode-data-rdb.md). For details about how to handle error 14800011, see [Database Backup and Restore](../../database/data-backup-and-restore.md).

| **ID**| **Error Message**                                                |
| ------------ | ------------------------------------------------------------ |
| 401          | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 14800000     | Inner error.                                                 |
| 14800011     | Failed to open the database because it is corrupted.                                          |
| 14800014     | The RdbStore or ResultSet is already closed.                                              |
| 14800021     | SQLite: Generic error. Possible causes: Insert failed or the updated data does not exist.                                       |
| 14800023     | SQLite: Access permission denied.                            |
| 14800024     | SQLite: The database file is locked.                         |
| 14800025     | SQLite: A table in the database is locked.                   |
| 14800026     | SQLite: The database is out of memory.                       |
| 14800027     | SQLite: Attempt to write a readonly database.                |
| 14800028     | SQLite: Some kind of disk I/O error occurred.                |
| 14800029     | SQLite: The database is full.                                |
| 14800031     | SQLite: TEXT or BLOB exceeds size limit.                     |
| 14800033     | SQLite: Data type mismatch.                                  |
| 14800047     | The WAL file size exceeds the default limit.                 |

**Example**:

```ts
const valueBucket6: relationalStore.ValuesBucket = {
  NAME: 'Lisa',
  AGE: 18,
  SALARY: 100.5,
  CODES: new Uint8Array([1, 2, 3, 4, 5])
};
const valueBucket7: relationalStore.ValuesBucket = {
  NAME: 'Jack',
  AGE: 19,
  SALARY: 101.5,
  CODES: new Uint8Array([6, 7, 8, 9, 10])
};
const valueBucket8: relationalStore.ValuesBucket = {
  NAME: 'Tom',
  AGE: 20,
  SALARY: 102.5,
  CODES: new Uint8Array([11, 12, 13, 14, 15])
};

let valueBuckets2 = new Array(valueBucket6, valueBucket7, valueBucket8);
if (store != undefined) {
  try {
    const transaction = await store.createTransaction();
    try {
      let insertNum: number = (transaction as relationalStore.Transaction).batchInsertSync('EMPLOYEE', valueBuckets2);
      await transaction.commit();
      console.info(`batchInsert is successful, the number of values that were inserted = ${insertNum}`);
    } catch (error) {
      const err = error as BusinessError;
      await transaction.rollback();
      console.error(`batchInsert is failed, code is ${err.code},message is ${err.message}`);
    }
  } catch (error) {
    const err = error as BusinessError;
    console.error(`createTransaction failed, code is ${err.code},message is ${err.message}`);
  }
}
```

## batchInsertWithConflictResolution<sup>18+</sup>

batchInsertWithConflictResolution(table: string, values: Array&lt;ValuesBucket&gt;, conflict: ConflictResolution): Promise&lt;number&gt;

Batch inserts data into a table with conflict resolutions. This API uses a promise to return the result.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Parameters**

| Name| Type                                      | Mandatory| Description                        |
| ------ | ------------------------------------------ | ---- | ---------------------------- |
| table  | string                                     | Yes  | Name of the target table.            |
| values | Array&lt;[ValuesBucket](arkts-apis-data-relationalStore-t.md#valuesbucket)&gt; | Yes  | An array of data to insert.|
| conflict | [ConflictResolution](arkts-apis-data-relationalStore-e.md#conflictresolution10)| Yes  | Resolution used to resolve the conflict. If **ON_CONFLICT_ROLLBACK** is used, the transaction will be rolled back when a conflict occurs.|

**Return value**

| Type                 | Description                                                       |
| --------------------- | ----------------------------------------------------------- |
| Promise&lt;number&gt; | Promise used to return the result. If the operation is successful, the number of inserted data records is returned. Otherwise, **-1** is returned.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [RDB Store Error Codes](errorcode-data-rdb.md). For details about how to handle error 14800011, see [Database Backup and Restore](../../database/data-backup-and-restore.md).

| **ID**| **Error Message**                                                |
|-----------| ------------------------------------------------------------ |
| 401       | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 14800000  | Inner error. |
| 14800011  | Failed to open the database because it is corrupted. |
| 14800014  | The RdbStore or ResultSet is already closed. |
| 14800021  | SQLite: Generic error. Possible causes: Insert failed or the updated data does not exist. |
| 14800022  | SQLite: Callback routine requested an abort. |
| 14800023  | SQLite: Access permission denied. |
| 14800024  | SQLite: The database file is locked. |
| 14800025  | SQLite: A table in the database is locked. |
| 14800026  | SQLite: The database is out of memory. |
| 14800027  | SQLite: Attempt to write a readonly database. |
| 14800028  | SQLite: Some kind of disk I/O error occurred. |
| 14800029  | SQLite: The database is full. |
| 14800031  | SQLite: TEXT or BLOB exceeds size limit. |
| 14800032  | SQLite: Abort due to constraint violation. |
| 14800033  | SQLite: Data type mismatch. |
| 14800034  | SQLite: Library used incorrectly. |
| 14800047  | The WAL file size exceeds the default limit. |

**Example**:

```ts
const valueBucket9: relationalStore.ValuesBucket = {
  NAME: 'Lisa',
  AGE: 18,
  SALARY: 100.5,
  CODES: new Uint8Array([1, 2, 3, 4, 5])
};
const valueBucketA: relationalStore.ValuesBucket = {
  NAME: 'Jack',
  AGE: 19,
  SALARY: 101.5,
  CODES: new Uint8Array([6, 7, 8, 9, 10])
};
const valueBucketB: relationalStore.ValuesBucket = {
  NAME: 'Tom',
  AGE: 20,
  SALARY: 102.5,
  CODES: new Uint8Array([11, 12, 13, 14, 15])
};

let valueBuckets3 = new Array(valueBucket9, valueBucketA, valueBucketB);

if (store != undefined) {
  try {
    const transaction = await store.createTransaction();
    try {
      const insertNum = await transaction.batchInsertWithConflictResolution(
        'EMPLOYEE',
        valueBuckets3,
        relationalStore.ConflictResolution.ON_CONFLICT_REPLACE
      );
      await transaction.commit();
      console.info(`batchInsert is successful, the number of values that were inserted = ${insertNum}`);
    } catch (error) {
      const err = error as BusinessError;
      await transaction.rollback();
      console.error(`batchInsert is failed, code is ${err.code},message is ${err.message}`);
    }
  } catch (error) {
    const err = error as BusinessError;
    console.error(`createTransaction failed, code is ${err.code},message is ${err.message}`);
  }
}
```

## batchInsertWithConflictResolutionSync<sup>18+</sup>

batchInsertWithConflictResolutionSync(table: string, values: Array&lt;ValuesBucket&gt;, conflict: ConflictResolution): number

Batch inserts data into a table with conflict resolutions. This API returns the result synchronously.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Parameters**

| Name| Type                                      | Mandatory| Description                        |
| ------ | ------------------------------------------ | ---- | ---------------------------- |
| table  | string                                     | Yes  | Name of the target table.            |
| values | Array&lt;[ValuesBucket](arkts-apis-data-relationalStore-t.md#valuesbucket)&gt; | Yes  | An array of data to insert.|
| conflict | [ConflictResolution](arkts-apis-data-relationalStore-e.md#conflictresolution10)| Yes  | Resolution used to resolve the conflict. If **ON_CONFLICT_ROLLBACK** is used, the transaction will be rolled back when a conflict occurs.|

**Return value**

| Type  | Description                                          |
| ------ | ---------------------------------------------- |
| number | If the operation is successful, the number of inserted data records is returned. Otherwise, **-1** is returned.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [RDB Store Error Codes](errorcode-data-rdb.md). For details about how to handle error 14800011, see [Database Backup and Restore](../../database/data-backup-and-restore.md).

| **ID**| **Error Message**                                                |
| ------------ | ------------------------------------------------------------ |
| 401          | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 14800000  | Inner error. |
| 14800011  | Failed to open the database because it is corrupted. |
| 14800014  | The RdbStore or ResultSet is already closed. |
| 14800021  | SQLite: Generic error. Possible causes: Insert failed or the updated data does not exist. |
| 14800022  | SQLite: Callback routine requested an abort. |
| 14800023  | SQLite: Access permission denied. |
| 14800024  | SQLite: The database file is locked. |
| 14800025  | SQLite: A table in the database is locked. |
| 14800026  | SQLite: The database is out of memory. |
| 14800027  | SQLite: Attempt to write a readonly database. |
| 14800028  | SQLite: Some kind of disk I/O error occurred. |
| 14800029  | SQLite: The database is full. |
| 14800031  | SQLite: TEXT or BLOB exceeds size limit. |
| 14800032  | SQLite: Abort due to constraint violation. |
| 14800033  | SQLite: Data type mismatch. |
| 14800034  | SQLite: Library used incorrectly. |
| 14800047  | The WAL file size exceeds the default limit. |

**Example**:

```ts
const valueBucketC: relationalStore.ValuesBucket = {
  NAME: 'Lisa',
  AGE: 18,
  SALARY: 100.5,
  CODES: new Uint8Array([1, 2, 3, 4, 5])
};
const valueBucketD: relationalStore.ValuesBucket = {
  NAME: 'Jack',
  AGE: 19,
  SALARY: 101.5,
  CODES: new Uint8Array([6, 7, 8, 9, 10])
};
const valueBucketE: relationalStore.ValuesBucket = {
  NAME: 'Tom',
  AGE: 20,
  SALARY: 102.5,
  CODES: new Uint8Array([11, 12, 13, 14, 15])
};

let valueBuckets4 = new Array(valueBucketC, valueBucketD, valueBucketE);
if (store != undefined) {
  try {
    const transaction = await store.createTransaction();
    try {
      const insertNum = transaction.batchInsertWithConflictResolutionSync(
        'EMPLOYEE',
        valueBuckets4,
        relationalStore.ConflictResolution.ON_CONFLICT_REPLACE
      );
      await transaction.commit();
      console.info(`batchInsert is successful, the number of values that were inserted = ${insertNum}`);
    } catch (error) {
      const err = error as BusinessError;
      await transaction.rollback();
      console.error(`batchInsert is failed, code is ${err.code},message is ${err.message}`);
    }
  } catch (error) {
    const err = error as BusinessError;
    console.error(`createTransaction failed, code is ${err.code},message is ${err.message}`);
  }
}
```

## update<sup>14+</sup>

update(values: ValuesBucket, predicates: RdbPredicates, conflict?: ConflictResolution): Promise&lt;number&gt;

Updates data based on the specified **RdbPredicates** object. This API uses a promise to return the result. Due to the limit of the shared memory (max. 2 MB), a single data record cannot exceed 2 MB. Otherwise, the query operation will fail.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Parameters**

| Name    | Type                                       | Mandatory| Description                                                        |
| ---------- | ------------------------------------------- | ---- | ------------------------------------------------------------ |
| values     | [ValuesBucket](arkts-apis-data-relationalStore-t.md#valuesbucket)               | Yes  | Rows of data to update in the RDB store. The key-value pair is associated with the column name in the target table.|
| predicates | [RdbPredicates](arkts-apis-data-relationalStore-RdbPredicates.md)            | Yes  | Update conditions specified by the **RdbPredicates** object.                     |
| conflict   | [ConflictResolution](arkts-apis-data-relationalStore-e.md#conflictresolution10)| No  | Resolution used to resolve the conflict. <br>Default value: **relationalStore.ConflictResolution.ON_CONFLICT_NONE**.                                         |

**Return value**

| Type                 | Description                                     |
| --------------------- | ----------------------------------------- |
| Promise&lt;number&gt; | Promise used to return the number of rows updated.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [RDB Store Error Codes](errorcode-data-rdb.md). For details about how to handle error 14800011, see [Database Backup and Restore](../../database/data-backup-and-restore.md).

| **ID**| **Error Message**                                                |
|-----------| ------------------------------------------------------------ |
| 401       | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 14800000  | Inner error. |
| 14800011  | Failed to open the database because it is corrupted. |
| 14800014  | The RdbStore or ResultSet is already closed. |
| 14800021  | SQLite: Generic error. Possible causes: Insert failed or the updated data does not exist. |
| 14800023  | SQLite: Access permission denied. |
| 14800024  | SQLite: The database file is locked. |
| 14800025  | SQLite: A table in the database is locked. |
| 14800026  | SQLite: The database is out of memory. |
| 14800027  | SQLite: Attempt to write a readonly database. |
| 14800028  | SQLite: Some kind of disk I/O error occurred. |
| 14800029  | SQLite: The database is full. |
| 14800031  | SQLite: TEXT or BLOB exceeds size limit. |
| 14800033  | SQLite: Data type mismatch. |
| 14800047  | The WAL file size exceeds the default limit. |

**Example**:

```ts
const valueBucketF: relationalStore.ValuesBucket = {
  NAME: 'Rose',
  AGE: 22,
  SALARY: 200.5,
  CODES: new Uint8Array([1, 2, 3, 4, 5])
};
let predicates = new relationalStore.RdbPredicates('EMPLOYEE');
predicates.equalTo('NAME', 'Lisa');

if (store != undefined) {
  try {
    const transaction = await store.createTransaction();
    try {
      const rows = await transaction.update(valueBucketF, predicates, relationalStore.ConflictResolution.ON_CONFLICT_REPLACE);
      await transaction.commit();
      console.info(`Updated row count: ${rows}`);
    } catch (error) {
      const err = error as BusinessError;
      await transaction.rollback();
      console.error(`Updated failed, code is ${err.code},message is ${err.message}`);
    }
  } catch (error) {
    const err = error as BusinessError;
    console.error(`createTransaction failed, code is ${err.code},message is ${err.message}`);
  }
}
```

## updateSync<sup>14+</sup>

updateSync(values: ValuesBucket, predicates: RdbPredicates, conflict?: ConflictResolution): number

Updates data in the RDB store based on the specified **RdbPredicates** object. This API returns the result synchronously. Due to the limit of the shared memory (max. 2 MB), a single data record cannot exceed 2 MB. Otherwise, the query operation will fail.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Parameters**

| Name    | Type                                       | Mandatory| Description                                                        |
| ---------- | ------------------------------------------- | ---- | ------------------------------------------------------------ |
| values     | [ValuesBucket](arkts-apis-data-relationalStore-t.md#valuesbucket)               | Yes  | Rows of data to update in the RDB store. The key-value pair is associated with the column name in the target table.|
| predicates | [RdbPredicates](arkts-apis-data-relationalStore-RdbPredicates.md)             | Yes  | Update conditions specified by the **RdbPredicates** object.                     |
| conflict   | [ConflictResolution](arkts-apis-data-relationalStore-e.md#conflictresolution10)| No  | Resolution used to resolve the conflict. <br>Default value: **relationalStore.ConflictResolution.ON_CONFLICT_NONE**.|

**Return value**

| Type  | Description              |
| ------ | ------------------ |
| number | Number of rows updated.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [RDB Store Error Codes](errorcode-data-rdb.md). For details about how to handle error 14800011, see [Database Backup and Restore](../../database/data-backup-and-restore.md).

| **ID**| **Error Message**                                                |
| ------------ | ------------------------------------------------------------ |
| 401          | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 14800000     | Inner error.                                                 |
| 14800011     | Failed to open the database because it is corrupted.                                          |
| 14800014     | The RdbStore or ResultSet is already closed.                                              |
| 14800021     | SQLite: Generic error. Possible causes: Insert failed or the updated data does not exist.                                       |
| 14800023     | SQLite: Access permission denied.                            |
| 14800024     | SQLite: The database file is locked.                         |
| 14800025     | SQLite: A table in the database is locked.                   |
| 14800026     | SQLite: The database is out of memory.                       |
| 14800027     | SQLite: Attempt to write a readonly database.                |
| 14800028     | SQLite: Some kind of disk I/O error occurred.                |
| 14800029     | SQLite: The database is full.                                |
| 14800031     | SQLite: TEXT or BLOB exceeds size limit.                     |
| 14800033     | SQLite: Data type mismatch.                                  |
| 14800047     | The WAL file size exceeds the default limit.                 |

**Example**:

```ts
const valueBucketG: relationalStore.ValuesBucket = {
  NAME: 'Rose',
  AGE: 22,
  SALARY: 200.5,
  CODES: new Uint8Array([1, 2, 3, 4, 5])
};
let predicates1 = new relationalStore.RdbPredicates('EMPLOYEE');
predicates1.equalTo('NAME', 'Lisa');

if (store != undefined) {
  try {
    const transaction = await store.createTransaction();
    try {
      let rows = transaction.updateSync(valueBucketG, predicates1, relationalStore.ConflictResolution.ON_CONFLICT_REPLACE);
      await transaction.commit();
      console.info(`Updated row count: ${rows}`);
    } catch (error) {
      const err = error as BusinessError;
      await transaction.rollback();
      console.error(`Updated failed, code is ${err.code},message is ${err.message}`);
    }
  } catch (error) {
    const err = error as BusinessError;
    console.error(`createTransaction failed, code is ${err.code},message is ${err.message}`);
  }
}
```

## delete<sup>14+</sup>

delete(predicates: RdbPredicates):Promise&lt;number&gt;

Deletes data from the RDB store based on the specified **RdbPredicates** object. This API uses a promise to return the result.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Parameters**

| Name    | Type                                | Mandatory| Description                                     |
| ---------- | ------------------------------------ | ---- | ----------------------------------------- |
| predicates | [RdbPredicates](arkts-apis-data-relationalStore-RdbPredicates.md) | Yes  | Deletion conditions specified by the **RdbPredicates** object.|

**Return value**

| Type                 | Description                           |
| --------------------- | ------------------------------- |
| Promise&lt;number&gt; | Promise used to return the number of rows deleted.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [RDB Store Error Codes](errorcode-data-rdb.md). For details about how to handle error 14800011, see [Database Backup and Restore](../../database/data-backup-and-restore.md).

| **ID**| **Error Message**                                                |
|-----------| ------------------------------------------------------------ |
| 401       | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 14800000  | Inner error. |
| 14800011  | Failed to open the database because it is corrupted. |
| 14800014  | The RdbStore or ResultSet is already closed. |
| 14800021  | SQLite: Generic error. Possible causes: Insert failed or the updated data does not exist. |
| 14800023  | SQLite: Access permission denied. |
| 14800024  | SQLite: The database file is locked. |
| 14800025  | SQLite: A table in the database is locked. |
| 14800026  | SQLite: The database is out of memory. |
| 14800027  | SQLite: Attempt to write a readonly database. |
| 14800028  | SQLite: Some kind of disk I/O error occurred. |
| 14800029  | SQLite: The database is full. |
| 14800031  | SQLite: TEXT or BLOB exceeds size limit. |
| 14800033  | SQLite: Data type mismatch. |
| 14800047  | The WAL file size exceeds the default limit. |

**Example**:

```ts
let predicates2 = new relationalStore.RdbPredicates('EMPLOYEE');
predicates2.equalTo('NAME', 'Lisa');

if (store != undefined) {
  try {
    const transaction = await store.createTransaction();
    try {
      const rows = await transaction.delete(predicates2);
      await transaction.commit();
      console.info(`Delete rows: ${rows}`);
    } catch (error) {
      const err = error as BusinessError;
      await transaction.rollback();
      console.error(`Delete failed, code is ${err.code},message is ${err.message}`);
    }
  } catch (error) {
    const err = error as BusinessError;
    console.error(`createTransaction failed, code is ${err.code},message is ${err.message}`);
  }
}
```

## deleteSync<sup>14+</sup>

deleteSync(predicates: RdbPredicates): number

Deletes data from the RDB store based on the specified **RdbPredicates** object. This API returns the result synchronously.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Parameters**

| Name    | Type                           | Mandatory| Description                                   |
| ---------- | ------------------------------- | ---- | --------------------------------------- |
| predicates | [RdbPredicates](arkts-apis-data-relationalStore-RdbPredicates.md) | Yes  | Deletion conditions specified by the **RdbPredicates** object.|

**Return value**

| Type  | Description              |
| ------ | ------------------ |
| number | Number of rows deleted.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [RDB Store Error Codes](errorcode-data-rdb.md). For details about how to handle error 14800011, see [Database Backup and Restore](../../database/data-backup-and-restore.md).

| **ID**| **Error Message**                                                |
| ------------ | ------------------------------------------------------------ |
| 401          | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 14800000  | Inner error. |
| 14800011  | Failed to open the database because it is corrupted. |
| 14800014  | The RdbStore or ResultSet is already closed. |
| 14800021  | SQLite: Generic error. Possible causes: Insert failed or the updated data does not exist. |
| 14800023  | SQLite: Access permission denied. |
| 14800024  | SQLite: The database file is locked. |
| 14800025  | SQLite: A table in the database is locked. |
| 14800026  | SQLite: The database is out of memory. |
| 14800027  | SQLite: Attempt to write a readonly database. |
| 14800028  | SQLite: Some kind of disk I/O error occurred. |
| 14800029  | SQLite: The database is full. |
| 14800031  | SQLite: TEXT or BLOB exceeds size limit. |
| 14800033  | SQLite: Data type mismatch. |
| 14800047  | The WAL file size exceeds the default limit. |

**Example**:

```ts
let predicates3 = new relationalStore.RdbPredicates('EMPLOYEE');
predicates3.equalTo('NAME', 'Lisa');
if (store != undefined) {
  try {
    const transaction = await store.createTransaction();
    try {
      let rows = transaction.deleteSync(predicates3);
      await transaction.commit();
      console.info(`Delete rows: ${rows}`);
    } catch (error) {
      const err = error as BusinessError;
      await transaction.rollback();
      console.error(`Delete failed, code is ${err.code},message is ${err.message}`);
    }
  } catch (error) {
    const err = error as BusinessError;
    console.error(`createTransaction failed, code is ${err.code},message is ${err.message}`);
  }
}
```

## query<sup>14+</sup>

query(predicates: RdbPredicates, columns?: Array&lt;string&gt;): Promise&lt;ResultSet&gt;

Queries data from the RDB store based on specified conditions. This API uses a promise to return the result. Due to the limit of the shared memory (max. 2 MB), a single data record cannot exceed 2 MB. Otherwise, the query operation will fail.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Parameters**

| Name    | Type                                | Mandatory| Description                                            |
| ---------- | ------------------------------------ | ---- | ------------------------------------------------ |
| predicates | [RdbPredicates](arkts-apis-data-relationalStore-RdbPredicates.md) | Yes  | Query conditions specified by the **RdbPredicates** object.       |
| columns    | Array&lt;string&gt;                  | No  | Columns to query. If this parameter is not specified, the query applies to all columns.|

**Return value**

| Type                                                   | Description                                              |
| ------------------------------------------------------- | -------------------------------------------------- |
| Promise&lt;[ResultSet](arkts-apis-data-relationalStore-ResultSet.md)&gt; | Promise used to return the result. If the operation is successful, a **ResultSet** object will be returned.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [RDB Store Error Codes](errorcode-data-rdb.md).

| **ID**| **Error Message**                                                |
|-----------| ------------------------------------------------------------ |
| 401       | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 14800000  | Inner error. |
| 14800011  | Failed to open the database because it is corrupted. |
| 14800014  | The RdbStore or ResultSet is already closed. |
| 14800021  | SQLite: Generic error. Possible causes: Insert failed or the updated data does not exist. |
| 14800023  | SQLite: Access permission denied. |
| 14800024  | SQLite: The database file is locked. |
| 14800026  | SQLite: The database is out of memory. |
| 14800028  | SQLite: Some kind of disk I/O error occurred. |
| 14800047  | The WAL file size exceeds the default limit. |


**Example**:

```ts
let predicates4 = new relationalStore.RdbPredicates('EMPLOYEE');
predicates4.equalTo('NAME', 'Rose');

if (store != undefined) {
  try {
    const transaction = await store.createTransaction();
    try {
      const resultSet = await transaction.query(predicates4, ['ID', 'NAME', 'AGE', 'SALARY', 'CODES']);
      console.info(`ResultSet column names: ${resultSet.columnNames}, column count: ${resultSet.columnCount}`);
      // resultSet is a cursor of a data set. By default, the cursor points to the -1st record. Valid data starts from 0.
      while (resultSet.goToNextRow()) {
        const id = resultSet.getLong(resultSet.getColumnIndex('ID'));
        const name = resultSet.getString(resultSet.getColumnIndex('NAME'));
        const age = resultSet.getLong(resultSet.getColumnIndex('AGE'));
        const salary = resultSet.getDouble(resultSet.getColumnIndex('SALARY'));
        console.info(`id=${id}, name=${name}, age=${age}, salary=${salary}`);
      }
      // Release the memory of resultSet. If the memory is not released, FD or memory leaks may occur.
      resultSet.close();
      await transaction.commit();
    } catch (error) {
      const err = error as BusinessError;
      await transaction.rollback();
      console.error(`Query failed, code is ${err.code},message is ${err.message}`);
    }
  } catch (error) {
    const err = error as BusinessError;
    console.error(`createTransaction failed, code is ${err.code},message is ${err.message}`);
  }
}
```

## querySync<sup>14+</sup>

querySync(predicates: RdbPredicates, columns?: Array&lt;string&gt;): ResultSet

Queries data in a database based on specified conditions. This API returns the result synchronously. If complex logic and a large number of loops are involved in the operations on the **resultSet** obtained by **querySync**, the freeze problem may occur. You are advised to perform this operation in the [taskpool](../apis-arkts/js-apis-taskpool.md) thread.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Parameters**

| Name    | Type                           | Mandatory| Description                                                        |
| ---------- | ------------------------------- | ---- | ------------------------------------------------------------ |
| predicates | [RdbPredicates](arkts-apis-data-relationalStore-RdbPredicates.md) | Yes  | Query conditions specified by the **RdbPredicates** object.                     |
| columns    | Array&lt;string&gt;             | No  | Columns to query. If this parameter is not specified, the query applies to all columns. The default value is null.|

**Return value**

| Type                   | Description                               |
| ----------------------- | ----------------------------------- |
| [ResultSet](arkts-apis-data-relationalStore-ResultSet.md) | If the operation is successful, a **ResultSet** object will be returned.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [RDB Store Error Codes](errorcode-data-rdb.md).

| **ID**| **Error Message**                                                |
| ------------ | ------------------------------------------------------------ |
| 401          | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 14800000  | Inner error. |
| 14800011  | Failed to open the database because it is corrupted. |
| 14800014  | The RdbStore or ResultSet is already closed. |
| 14800021  | SQLite: Generic error. Possible causes: Insert failed or the updated data does not exist. |
| 14800023  | SQLite: Access permission denied. |
| 14800024  | SQLite: The database file is locked. |
| 14800025  | SQLite: A table in the database is locked. |
| 14800026  | SQLite: The database is out of memory. |
| 14800028  | SQLite: Some kind of disk I/O error occurred. |
| 14800047  | The WAL file size exceeds the default limit. |

**Example**:

```ts
let predicates5 = new relationalStore.RdbPredicates('EMPLOYEE');
predicates5.equalTo('NAME', 'Rose');

if (store != undefined) {
  try {
    const transaction = await store.createTransaction();
    try {
      let resultSet = transaction.querySync(predicates5, ['ID', 'NAME', 'AGE', 'SALARY', 'CODES']);
      console.info(`ResultSet column names: ${resultSet.columnNames}, column count: ${resultSet.columnCount}`);
      // resultSet is a cursor of a data set. By default, the cursor points to the -1st record. Valid data starts from 0.
      while (resultSet.goToNextRow()) {
        const id = resultSet.getLong(resultSet.getColumnIndex('ID'));
        const name = resultSet.getString(resultSet.getColumnIndex('NAME'));
        const age = resultSet.getLong(resultSet.getColumnIndex('AGE'));
        const salary = resultSet.getDouble(resultSet.getColumnIndex('SALARY'));
        console.info(`id=${id}, name=${name}, age=${age}, salary=${salary}`);
      }
      // Release the memory of resultSet. If the memory is not released, FD or memory leaks may occur.
      resultSet.close();
      await transaction.commit();
    } catch (error) {
      const err = error as BusinessError;
      await transaction.rollback();
      console.error(`Query failed, code is ${err.code},message is ${err.message}`);
    }
  } catch (error) {
    const err = error as BusinessError;
    console.error(`createTransaction failed, code is ${err.code},message is ${err.message}`);
  }
}
```

## querySql<sup>14+</sup>

querySql(sql: string, args?: Array&lt;ValueType&gt;): Promise&lt;ResultSet&gt;

Queries data in the RDB store using the specified SQL statement. The number of relational operators between expressions and operators in the SQL statement cannot exceed 1000. This API uses a promise to return the result.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Parameters**

| Name  | Type                                | Mandatory| Description                                                        |
| -------- | ------------------------------------ | ---- | ------------------------------------------------------------ |
| sql      | string                               | Yes  | SQL statement to run.                                       |
| args | Array&lt;[ValueType](arkts-apis-data-relationalStore-t.md#valuetype)&gt; | No  | Arguments in the SQL statement. The value corresponds to the placeholders in the SQL parameter statement. If the SQL parameter statement is complete, leave this parameter blank.|

**Return value**

| Type                                                   | Description                                              |
| ------------------------------------------------------- | -------------------------------------------------- |
| Promise&lt;[ResultSet](arkts-apis-data-relationalStore-ResultSet.md)&gt; | Promise used to return the result. If the operation is successful, a **ResultSet** object will be returned.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [RDB Store Error Codes](errorcode-data-rdb.md).

| **ID**| **Error Message**                                                |
|-----------| ------------------------------------------------------------ |
| 401       | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 14800000  | Inner error. |
| 14800011  | Failed to open the database because it is corrupted. |
| 14800014  | The RdbStore or ResultSet is already closed. |
| 14800021  | SQLite: Generic error. Possible causes: Insert failed or the updated data does not exist. |
| 14800023  | SQLite: Access permission denied. |
| 14800024  | SQLite: The database file is locked. |
| 14800025  | SQLite: A table in the database is locked. |
| 14800026  | SQLite: The database is out of memory. |
| 14800028  | SQLite: Some kind of disk I/O error occurred. |
| 14800047  | The WAL file size exceeds the default limit. |

**Example**:

```ts
if (store != undefined) {
  try {
    const transaction = await store.createTransaction();
    try {
      const resultSet = await transaction.querySql("SELECT * FROM EMPLOYEE CROSS JOIN BOOK WHERE BOOK.NAME = 'sanguo'");
      console.info(`ResultSet column names: ${resultSet.columnNames}, column count: ${resultSet.columnCount}`);
      // resultSet is a cursor of a data set. By default, the cursor points to the -1st record. Valid data starts from 0.
      while (resultSet.goToNextRow()) {
        const id = resultSet.getLong(resultSet.getColumnIndex('ID'));
        const name = resultSet.getString(resultSet.getColumnIndex('NAME'));
        const age = resultSet.getLong(resultSet.getColumnIndex('AGE'));
        const salary = resultSet.getDouble(resultSet.getColumnIndex('SALARY'));
        console.info(`id=${id}, name=${name}, age=${age}, salary=${salary}`);
      }
      // Release the memory of resultSet. If the memory is not released, FD or memory leaks may occur.
      resultSet.close();
      await transaction.commit();
    } catch (error) {
      const err = error as BusinessError;
      await transaction.rollback();
      console.error(`Query failed, code is ${err.code},message is ${err.message}`);
    }
  } catch (error) {
    const err = error as BusinessError;
    console.error(`createTransaction failed, code is ${err.code},message is ${err.message}`);
  }
}
```

## querySqlSync<sup>14+</sup>

querySqlSync(sql: string, args?: Array&lt;ValueType&gt;): ResultSet

Queries data in the RDB store using the specified SQL statement. The number of relational operators between expressions and operators in the SQL statement cannot exceed 1000. If complex logic and a large number of loops are involved in the operations on the **resultSet** obtained by **querySqlSync**, the freeze problem may occur. You are advised to perform this operation in the [taskpool](../apis-arkts/js-apis-taskpool.md) thread.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Parameters**

| Name  | Type                                | Mandatory| Description                                                        |
| -------- | ------------------------------------ | ---- | ------------------------------------------------------------ |
| sql      | string                               | Yes  | SQL statement to run.                                       |
| args | Array&lt;[ValueType](arkts-apis-data-relationalStore-t.md#valuetype)&gt; | No  | Arguments in the SQL statement. The value corresponds to the placeholders in the SQL parameter statement. If the SQL parameter statement is complete, leave this parameter blank. The default value is null.|

**Return value**

| Type                   | Description                               |
| ----------------------- | ----------------------------------- |
| [ResultSet](arkts-apis-data-relationalStore-ResultSet.md) | If the operation is successful, a **ResultSet** object will be returned.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [RDB Store Error Codes](errorcode-data-rdb.md).

| **ID**| **Error Message**                                                |
| ------------ | ------------------------------------------------------------ |
| 401          | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 14800000  | Inner error. |
| 14800011  | Failed to open the database because it is corrupted. |
| 14800014  | The RdbStore or ResultSet is already closed. |
| 14800021  | SQLite: Generic error. Possible causes: Insert failed or the updated data does not exist. |
| 14800023  | SQLite: Access permission denied. |
| 14800024  | SQLite: The database file is locked. |
| 14800025  | SQLite: A table in the database is locked. |
| 14800026  | SQLite: The database is out of memory. |
| 14800028  | SQLite: Some kind of disk I/O error occurred. |
| 14800047  | The WAL file size exceeds the default limit. |

**Example**:

```ts
if (store != undefined) {
  try {
    const transaction = await store.createTransaction();
    try {
      let resultSet = transaction.querySqlSync("SELECT * FROM EMPLOYEE CROSS JOIN BOOK WHERE BOOK.NAME = 'sanguo'");
      console.info(`ResultSet column names: ${resultSet.columnNames}, column count: ${resultSet.columnCount}`);
      // resultSet is a cursor of a data set. By default, the cursor points to the -1st record. Valid data starts from 0.
      while (resultSet.goToNextRow()) {
        const id = resultSet.getLong(resultSet.getColumnIndex('ID'));
        const name = resultSet.getString(resultSet.getColumnIndex('NAME'));
        const age = resultSet.getLong(resultSet.getColumnIndex('AGE'));
        const salary = resultSet.getDouble(resultSet.getColumnIndex('SALARY'));
        console.info(`id=${id}, name=${name}, age=${age}, salary=${salary}`);
      }
      // Release the memory of resultSet. If the memory is not released, FD or memory leaks may occur.
      resultSet.close();
      await transaction.commit();
    } catch (error) {
      const err = error as BusinessError;
      await transaction.rollback();
      console.error(`Query failed, code is ${err.code},message is ${err.message}`);
    }
  } catch (error) {
    const err = error as BusinessError;
    console.error(`createTransaction failed, code is ${err.code},message is ${err.message}`);
  }
}
```

## execute<sup>14+</sup>

execute(sql: string, args?: Array&lt;ValueType&gt;): Promise&lt;ValueType&gt;

Executes an SQL statement that contains specified arguments. The number of relational operators between expressions and operators in the statement cannot exceed 1000. This API uses a promise to return a value of the ValueType type.

This API can be used to add, delete, and modify data, run SQL statements of the PRAGMA syntax, and create, delete, and modify a table. The type of the return value varies, depending on the execution result.

This API does not support query, database attachment, and transaction operations. You can use [querySql](#querysql14) or [query](#query14) to query data, and use [attach](arkts-apis-data-relationalStore-RdbStore.md#attach12) to attach a database.

Statements separated by semicolons (\;) are not supported.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Parameters**

| Name  | Type                                | Mandatory| Description                                                        |
| -------- | ------------------------------------ | ---- | ------------------------------------------------------------ |
| sql      | string                               | Yes  | SQL statement to run.                                       |
| args | Array&lt;[ValueType](arkts-apis-data-relationalStore-t.md#valuetype)&gt; | No  | Arguments in the SQL statement. The value corresponds to the placeholders in the SQL parameter statement. If the SQL parameter statement is complete, leave this parameter blank.|

**Return value**

| Type               | Description                     |
| ------------------- | ------------------------- |
| Promise&lt;[ValueType](arkts-apis-data-relationalStore-t.md#valuetype)&gt; | Promise used to return the SQL execution result.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [RDB Store Error Codes](errorcode-data-rdb.md). For details about how to handle error 14800011, see [Database Backup and Restore](../../database/data-backup-and-restore.md).

| **ID**| **Error Message**                                                |
|-----------| ------------------------------------------------------------ |
| 401       | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 801       | Capability not supported the sql(attach,begin,commit,rollback etc.). |
| 14800000  | Inner error. |
| 14800011  | Failed to open the database because it is corrupted. |
| 14800014  | The RdbStore or ResultSet is already closed. |
| 14800021  | SQLite: Generic error. Possible causes: Insert failed or the updated data does not exist. |
| 14800023  | SQLite: Access permission denied. |
| 14800024  | SQLite: The database file is locked. |
| 14800025  | SQLite: A table in the database is locked. |
| 14800026  | SQLite: The database is out of memory. |
| 14800027  | SQLite: Attempt to write a readonly database. |
| 14800028  | SQLite: Some kind of disk I/O error occurred. |
| 14800029  | SQLite: The database is full. |
| 14800031  | SQLite: TEXT or BLOB exceeds size limit. |
| 14800033  | SQLite: Data type mismatch. |
| 14800047  | The WAL file size exceeds the default limit. |

**Example**:

```ts
if (store != undefined) {
  try {
    const transaction = await store.createTransaction();
    try {
      // Delete all data from the table.
      const SQL_DELETE_TABLE = 'DELETE FROM EMPLOYEE';
      const data = await transaction.execute(SQL_DELETE_TABLE);
      await transaction.commit();
      console.info(`delete result: ${data}`);
    } catch (error) {
      const err = error as BusinessError;
      await transaction.rollback();
      console.error(`delete failed, code is ${err.code}, message is ${err.message}`);
    }
  } catch (error) {
    const err = error as BusinessError;
    console.error(`createTransaction failed, code is ${err.code},message is ${err.message}`);
  }
}
```

## executeSync<sup>14+</sup>

executeSync(sql: string, args?: Array&lt;ValueType&gt;): ValueType

Executes an SQL statement that contains specified arguments. The number of relational operators between expressions and operators in the statement cannot exceed 1000. This API returns a value of theValueType type.

This API can be used to add, delete, and modify data, run SQL statements of the PRAGMA syntax, and create, delete, and modify a table. The type of the return value varies, depending on the execution result.

This API does not support query, database attachment, and transaction operations. You can use [querySql](#querysql14) or [query](#query14) to query data, and use [attach](arkts-apis-data-relationalStore-RdbStore.md#attach12) to attach a database.

Statements separated by semicolons (\;) are not supported.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Parameters**

| Name| Type                                | Mandatory| Description                                                        |
| ------ | ------------------------------------ | ---- | ------------------------------------------------------------ |
| sql    | string                               | Yes  | SQL statement to run.                                       |
| args   | Array&lt;[ValueType](arkts-apis-data-relationalStore-t.md#valuetype)&gt; | No  | Arguments in the SQL statement. The value corresponds to the placeholders in the SQL parameter statement. If this parameter is left blank or set to **null** or **undefined**, the SQL statement is complete. The default value is null.|

**Return value**

| Type                   | Description               |
| ----------------------- | ------------------- |
| [ValueType](arkts-apis-data-relationalStore-t.md#valuetype) | SQL execution result.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [RDB Store Error Codes](errorcode-data-rdb.md). For details about how to handle error 14800011, see [Database Backup and Restore](../../database/data-backup-and-restore.md).

| **ID**| **Error Message**                                                |
| ------------ | ------------------------------------------------------------ |
| 401          | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 801       | Capability not supported the sql(attach,begin,commit,rollback etc.). |
| 14800000     | Inner error.                                                 |
| 14800011     | Failed to open the database because it is corrupted.                                          |
| 14800014     | The RdbStore or ResultSet is already closed.                                              |
| 14800021     | SQLite: Generic error. Possible causes: Insert failed or the updated data does not exist.                                       |
| 14800023     | SQLite: Access permission denied.                            |
| 14800024     | SQLite: The database file is locked.                         |
| 14800025     | SQLite: A table in the database is locked.                   |
| 14800026     | SQLite: The database is out of memory.                       |
| 14800027     | SQLite: Attempt to write a readonly database.                |
| 14800028     | SQLite: Some kind of disk I/O error occurred.                |
| 14800029     | SQLite: The database is full.                                |
| 14800031     | SQLite: TEXT or BLOB exceeds size limit.                     |
| 14800033     | SQLite: Data type mismatch.                                  |
| 14800047     | The WAL file size exceeds the default limit.                 |

**Example**:

```ts
// Delete all data from the table.
if (store != undefined) {
  try {
    const transaction = await store.createTransaction();
    try {
      const SQL_DELETE_TABLE = 'DELETE FROM EMPLOYEE';
      let data = transaction.executeSync(SQL_DELETE_TABLE);
      await transaction.commit();
      console.info(`delete result: ${data}`);
    } catch (error) {
      const err = error as BusinessError;
      await transaction.rollback();
      console.error(`delete failed, code is ${err.code}, message is ${err.message}`);
    }
  } catch (error) {
    const err = error as BusinessError;
    console.error(`createTransaction failed, code is ${err.code},message is ${err.message}`);
  }
}
```
