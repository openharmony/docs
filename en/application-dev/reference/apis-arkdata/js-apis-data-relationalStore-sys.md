# @ohos.data.relationalStore (RDB Store) (System API)

The relational database (RDB) store manages data based on relational models. It provides a complete mechanism for managing local databases based on the underlying SQLite. To satisfy different needs in complicated scenarios, the RDB store offers a series of APIs for performing operations such as adding, deleting, modifying, and querying data, and supports direct execution of SQL statements. The worker threads are not supported.

ArkTS supports the following basic data types: number, string, binary data, and boolean. The maximum size of a data record is 2 MB. If a data record exceeds 2 MB, it can be inserted successfully but cannot be read.

The **relationalStore** module provides the following:

- [RdbPredicates](js-apis-data-relationalStore.md#rdbpredicates): provides predicates indicating the nature, feature, or relationship of a data entity in an RDB store. It is used to define the operation conditions for an RDB store.
- [RdbStore](#rdbstore): provides APIs for managing data in an RDB store.
- [ResultSet](js-apis-data-relationalStore.md#resultset): provides APIs for accessing the result set obtained from the RDB store.

> **NOTE**
> 
> - The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
> - This topic describes only the system APIs provided by the module. For details about its public APIs, see [@ohos.data.relationalStore](js-apis-data-relationalStore.md).

## Modules to Import

```ts
import relationalStore from '@ohos.data.relationalStore';
```

## StoreConfig

Defines the RDB store configuration.

| Name       | Type         | Mandatory| Description                                                     |
| ------------- | ------------- | ---- | --------------------------------------------------------- |
| isSearchable<sup>11+</sup> | boolean | No| Whether the RDB store is searchable. The value **true** means the RDB store is searchable; the value **false** means the opposite. The default value is **false**.<br>**System API**: This is a system API.<br>This parameter is supported since API version 11.<br>**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core|

## Reference<sup>11+</sup>

Represents the reference between tables by field. If table **b** references table **a**, table **a** is the source table and **b** is the target table.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**System API**: This is a system API.

| Name      | Type  | Mandatory| Description                                    |
| ---------- | ------ | ---- | ---------------------------------------- |
| sourceTable | string | Yes  | Source table.  |
| targetTable | string | Yes  | Target table.  |
| refFields   | Record<string, string> | Yes  | Fields referenced. In a KV pair, the key indicates the field in the source table, and the value indicates the field in the target table.      |

## DistributedConfig<sup>10+</sup>

Defines the configuration of the distributed mode of tables.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

| Name    | Type   | Mandatory| Description                                                        |
| -------- | ------- | ---- | ------------------------------------------------------------ |
| references<sup>11+</sup> | Array&lt;[Reference](#reference11)&gt; | No  | References between tables. You can reference multiple fields, and their values must be the same in the source and target tables. By default, database tables are not referenced with each other.<br>**System API**: This is a system API.<br>This parameter is supported since API version 11.|

## RdbStore

Provides APIs for managing data in an RDB store.
Before using the **RdbStore** APIs, use [executeSql](js-apis-data-relationalStore.md#executesql) to initialize the database table structure and related data.

### update

update(table: string, values: ValuesBucket, predicates: dataSharePredicates.DataSharePredicates, callback: AsyncCallback&lt;number&gt;):void

Updates data based on the specified **DataSharePredicates** object. This API uses an asynchronous callback to return the result. Due to the limit of the shared memory (max. 2 MB), a single data record cannot exceed 2 MB. Otherwise, the query operation will fail.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Model restriction**: This API can be used only in the stage model.

**System API**: This is a system API.

**Parameters**

| Name    | Type                                                        | Mandatory| Description                                                        |
| ---------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| table      | string                                                       | Yes  | Name of the target table.                                            |
| values     | [ValuesBucket](js-apis-data-relationalStore.md#valuesbucket)                                | Yes  | Rows of data to update in the RDB store. The key-value pair is associated with the column name in the target table.|
| predicates | [dataSharePredicates.DataSharePredicates](js-apis-data-dataSharePredicates.md#datasharepredicates) | Yes  | Update conditions specified by the **DataSharePredicates** object.               |
| callback   | AsyncCallback&lt;number&gt;                                  | Yes  | Callback used to return the number of rows updated.                  |

**Error codes**

For details about the error codes, see [RDB Error Codes](errorcode-data-rdb.md).

| **ID**| **Error Message**                                |
| ------------ | -------------------------------------------- |
| 14800047     | The WAL file size exceeds the default limit. |
| 14800000     | Inner error.                                 |

**Example**

```ts
import dataSharePredicates from '@ohos.data.dataSharePredicates'
import { ValuesBucket } from '@ohos.data.ValuesBucket';

let value1 = "Rose";
let value2 = 22;
let value3 = 200.5;
let value4 = new Uint8Array([1, 2, 3, 4, 5]);

// You can use either of the following:
const valueBucket1: ValuesBucket = {
  'NAME': value1,
  'AGE': value2,
  'SALARY': value3,
  'CODES': value4,
};
const valueBucket2: ValuesBucket = {
  NAME: value1,
  AGE: value2,
  SALARY: value3,
  CODES: value4,
};
const valueBucket3: ValuesBucket = {
  "NAME": value1,
  "AGE": value2,
  "SALARY": value3,
  "CODES": value4,
};

let predicates = new dataSharePredicates.DataSharePredicates();
predicates.equalTo("NAME", "Lisa");
if(store != undefined) {
  (store as relationalStore.RdbStore).update("EMPLOYEE", valueBucket1, predicates, (err, rows) => {
    if (err) {
      console.error(`Updated failed, code is ${err.code},message is ${err.message}`);
      return;
    }
    console.info(`Updated row count: ${rows}`);
  })
}
```

### update

update(table: string, values: ValuesBucket, predicates: dataSharePredicates.DataSharePredicates):Promise&lt;number&gt;

Updates data based on the specified **DataSharePredicates** object. This API uses a promise to return the result. Due to the limit of the shared memory (max. 2 MB), a single data record cannot exceed 2 MB. Otherwise, the query operation will fail.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Model restriction**: This API can be used only in the stage model.

**System API**: This is a system API.

**Parameters**

| Name    | Type                                                        | Mandatory| Description                                                        |
| ---------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| table      | string                                                       | Yes  | Name of the target table.                                            |
| values     | [ValuesBucket](js-apis-data-relationalStore.md#valuesbucket)                                | Yes  | Rows of data to update in the RDB store. The key-value pair is associated with the column name in the target table.|
| predicates | [dataSharePredicates.DataSharePredicates](js-apis-data-dataSharePredicates.md#datasharepredicates) | Yes  | Update conditions specified by the **DataSharePredicates** object.               |

**Return value**

| Type                 | Description                                     |
| --------------------- | ----------------------------------------- |
| Promise&lt;number&gt; | Promise used to return the number of rows updated.|

**Error codes**

For details about the error codes, see [RDB Error Codes](errorcode-data-rdb.md).

| **ID**| **Error Message**                                |
| ------------ | -------------------------------------------- |
| 14800047     | The WAL file size exceeds the default limit. |
| 14800000     | Inner error.                                 |

**Example**

```ts
import dataSharePredicates from '@ohos.data.dataSharePredicates';
import { ValuesBucket } from '@ohos.data.ValuesBucket';
import { BusinessError } from "@ohos.base";

let value1 = "Rose";
let value2 = 22;
let value3 = 200.5;
let value4 = new Uint8Array([1, 2, 3, 4, 5]);

// You can use either of the following:
const valueBucket1: ValuesBucket = {
  'NAME': value1,
  'AGE': value2,
  'SALARY': value3,
  'CODES': value4,
};
const valueBucket2: ValuesBucket = {
  NAME: value1,
  AGE: value2,
  SALARY: value3,
  CODES: value4,
};
const valueBucket3: ValuesBucket = {
  "NAME": value1,
  "AGE": value2,
  "SALARY": value3,
  "CODES": value4,
};

let predicates = new dataSharePredicates.DataSharePredicates();
predicates.equalTo("NAME", "Lisa");
if(store != undefined) {
  (store as relationalStore.RdbStore).update("EMPLOYEE", valueBucket1, predicates).then(async (rows: Number) => {
    console.info(`Updated row count: ${rows}`);
  }).catch((err: BusinessError) => {
    console.error(`Updated failed, code is ${err.code},message is ${err.message}`);
  })
}
```

### delete

delete(table: string, predicates: dataSharePredicates.DataSharePredicates, callback: AsyncCallback&lt;number&gt;):void

Deletes data from the RDB store based on the specified **DataSharePredicates** object. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Model restriction**: This API can be used only in the stage model.

**System API**: This is a system API.

**Parameters**

| Name    | Type                                                        | Mandatory| Description                                         |
| ---------- | ------------------------------------------------------------ | ---- | --------------------------------------------- |
| table      | string                                                       | Yes  | Name of the target table.                             |
| predicates | [dataSharePredicates.DataSharePredicates](js-apis-data-dataSharePredicates.md#datasharepredicates) | Yes  | Conditions specified by the **DataSharePredicates** object for deleting data.|
| callback   | AsyncCallback&lt;number&gt;                                  | Yes  | Callback used to return the number of rows deleted.     |

**Error codes**

For details about the error codes, see [RDB Error Codes](errorcode-data-rdb.md).

| **ID**| **Error Message**                                |
| ------------ | -------------------------------------------- |
| 14800047     | The WAL file size exceeds the default limit. |
| 14800000     | Inner error.                                 |

**Example**

```ts
import dataSharePredicates from '@ohos.data.dataSharePredicates';

let predicates = new dataSharePredicates.DataSharePredicates();
predicates.equalTo("NAME", "Lisa");
if(store != undefined) {
  (store as relationalStore.RdbStore).delete("EMPLOYEE", predicates, (err, rows) => {
    if (err) {
      console.error(`Delete failed, code is ${err.code},message is ${err.message}`);
      return;
    }
    console.info(`Delete rows: ${rows}`);
  })
}
```

### delete

delete(table: string, predicates: dataSharePredicates.DataSharePredicates):Promise&lt;number&gt;

Deletes data from the RDB store based on the specified **DataSharePredicates** object. This API uses a promise to return the result.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Model restriction**: This API can be used only in the stage model.

**System API**: This is a system API.

**Parameters**

| Name    | Type                                                        | Mandatory| Description                                         |
| ---------- | ------------------------------------------------------------ | ---- | --------------------------------------------- |
| table      | string                                                       | Yes  | Name of the target table.                             |
| predicates | [dataSharePredicates.DataSharePredicates](js-apis-data-dataSharePredicates.md#datasharepredicates) | Yes  | Conditions specified by the **DataSharePredicates** object for deleting data.|

**Return value**

| Type                 | Description                           |
| --------------------- | ------------------------------- |
| Promise&lt;number&gt; | Promise used to return the number of rows deleted.|

**Error codes**

For details about the error codes, see [RDB Error Codes](errorcode-data-rdb.md).

| **ID**| **Error Message**                                |
| ------------ | -------------------------------------------- |
| 14800047     | The WAL file size exceeds the default limit. |
| 14800000     | Inner error.                                 |

**Example**

```ts
import dataSharePredicates from '@ohos.data.dataSharePredicates';
import { BusinessError } from "@ohos.base";

let predicates = new dataSharePredicates.DataSharePredicates();
predicates.equalTo("NAME", "Lisa");
if(store != undefined) {
  (store as relationalStore.RdbStore).delete("EMPLOYEE", predicates).then((rows: Number) => {
    console.info(`Delete rows: ${rows}`);
  }).catch((err: BusinessError) => {
    console.error(`Delete failed, code is ${err.code},message is ${err.message}`);
  })
}
```

### query<sup>10+</sup>

query(table: string, predicates: dataSharePredicates.DataSharePredicates, callback: AsyncCallback&lt;ResultSet&gt;):void

Queries data from the RDB store based on specified conditions. This API uses an asynchronous callback to return the result. Due to the limit of the shared memory (max. 2 MB), a single data record cannot exceed 2 MB. Otherwise, the query operation will fail.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Model restriction**: This API can be used only in the stage model.

**System API**: This is a system API.

**Parameters**

| Name    | Type                                                        | Mandatory| Description                                                       |
| ---------- | ------------------------------------------------------------ | ---- | ----------------------------------------------------------- |
| table      | string                                                       | Yes  | Name of the target table.                                           |
| predicates | [dataSharePredicates.DataSharePredicates](js-apis-data-dataSharePredicates.md#datasharepredicates) | Yes  | Query conditions specified by the **DataSharePredicates** object.              |
| callback   | AsyncCallback&lt;[ResultSet](#resultset)&gt; | Yes  | Callback used to return the result. If the operation is successful, a **ResultSet** object will be returned.|

**Error codes**

For details about the error codes, see [RDB Error Codes](errorcode-data-rdb.md).

| **ID**| **Error Message**                |
| ------------ | ---------------------------- |
| 14800000     | Inner error.                 |

**Example**

```ts
import dataSharePredicates from '@ohos.data.dataSharePredicates';

let predicates = new dataSharePredicates.DataSharePredicates();
predicates.equalTo("NAME", "Rose");
if(store != undefined) {
  (store as relationalStore.RdbStore).query("EMPLOYEE", predicates, (err, resultSet) => {
    if (err) {
      console.error(`Query failed, code is ${err.code},message is ${err.message}`);
      return;
    }
    console.info(`ResultSet column names: ${resultSet.columnNames}, column count: ${resultSet.columnCount}`);
    // resultSet is a cursor of a data set. By default, the cursor points to the -1st record. Valid data starts from 0.
    while (resultSet.goToNextRow()) {
      const id = resultSet.getLong(resultSet.getColumnIndex("ID"));
      const name = resultSet.getString(resultSet.getColumnIndex("NAME"));
      const age = resultSet.getLong(resultSet.getColumnIndex("AGE"));
      const salary = resultSet.getDouble(resultSet.getColumnIndex("SALARY"));
      console.info(`id=${id}, name=${name}, age=${age}, salary=${salary}`);
    }
    // Release the dataset memory.
    resultSet.close();
  })
}
```

### query

query(table: string, predicates: dataSharePredicates.DataSharePredicates, columns: Array&lt;string&gt;, callback: AsyncCallback&lt;ResultSet&gt;):void

Queries data from the RDB store based on specified conditions. This API uses an asynchronous callback to return the result. Due to the limit of the shared memory (max. 2 MB), a single data record cannot exceed 2 MB. Otherwise, the query operation will fail.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Model restriction**: This API can be used only in the stage model.

**System API**: This is a system API.

**Parameters**

| Name    | Type                                                        | Mandatory| Description                                                       |
| ---------- | ------------------------------------------------------------ | ---- | ----------------------------------------------------------- |
| table      | string                                                       | Yes  | Name of the target table.                                           |
| predicates | [dataSharePredicates.DataSharePredicates](js-apis-data-dataSharePredicates.md#datasharepredicates) | Yes  | Query conditions specified by the **DataSharePredicates** object.              |
| columns    | Array&lt;string&gt;                                          | Yes  | Columns to query. If this parameter is not specified, the query applies to all columns.           |
| callback   | AsyncCallback&lt;[ResultSet](#resultset)&gt; | Yes  | Callback used to return the result. If the operation is successful, a **ResultSet** object will be returned.|

**Error codes**

For details about the error codes, see [RDB Error Codes](errorcode-data-rdb.md).

| **ID**| **Error Message**                |
| ------------ | ---------------------------- |
| 14800000     | Inner error.                 |

**Example**

```ts
import dataSharePredicates from '@ohos.data.dataSharePredicates';

let predicates = new dataSharePredicates.DataSharePredicates();
predicates.equalTo("NAME", "Rose");
if(store != undefined) {
  (store as relationalStore.RdbStore).query("EMPLOYEE", predicates, ["ID", "NAME", "AGE", "SALARY", "CODES"], (err, resultSet) => {
    if (err) {
      console.error(`Query failed, code is ${err.code},message is ${err.message}`);
      return;
    }
    console.info(`ResultSet column names: ${resultSet.columnNames}, column count: ${resultSet.columnCount}`);
    // resultSet is a cursor of a data set. By default, the cursor points to the -1st record. Valid data starts from 0.
    while (resultSet.goToNextRow()) {
      const id = resultSet.getLong(resultSet.getColumnIndex("ID"));
      const name = resultSet.getString(resultSet.getColumnIndex("NAME"));
      const age = resultSet.getLong(resultSet.getColumnIndex("AGE"));
      const salary = resultSet.getDouble(resultSet.getColumnIndex("SALARY"));
      console.info(`id=${id}, name=${name}, age=${age}, salary=${salary}`);
    }
    // Release the dataset memory.
    resultSet.close();
  })
}
```

### query

query(table: string, predicates: dataSharePredicates.DataSharePredicates, columns?: Array&lt;string&gt;):Promise&lt;ResultSet&gt;

Queries data from the RDB store based on specified conditions. This API uses a promise to return the result. Due to the limit of the shared memory (max. 2 MB), a single data record cannot exceed 2 MB. Otherwise, the query operation will fail.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Model restriction**: This API can be used only in the stage model.

**System API**: This is a system API.

**Parameters**

| Name    | Type                                                        | Mandatory| Description                                            |
| ---------- | ------------------------------------------------------------ | ---- | ------------------------------------------------ |
| table      | string                                                       | Yes  | Name of the target table.                                |
| predicates | [dataSharePredicates.DataSharePredicates](js-apis-data-dataSharePredicates.md#datasharepredicates) | Yes  | Query conditions specified by the **DataSharePredicates** object.   |
| columns    | Array&lt;string&gt;                                          | No  | Columns to query. If this parameter is not specified, the query applies to all columns.|

**Return value**

| Type                                                   | Description                                              |
| ------------------------------------------------------- | -------------------------------------------------- |
| Promise&lt;[ResultSet](#resultset)&gt; | Promise used to return the result. If the operation is successful, a **ResultSet** object will be returned.|

**Error codes**

For details about the error codes, see [RDB Error Codes](errorcode-data-rdb.md).

| **ID**| **Error Message**                |
| ------------ | ---------------------------- |
| 14800000     | Inner error.                 |

**Example**

```ts
import dataSharePredicates from '@ohos.data.dataSharePredicates';
import { BusinessError } from "@ohos.base";

let predicates = new dataSharePredicates.DataSharePredicates();
predicates.equalTo("NAME", "Rose");
if(store != undefined) {
  (store as relationalStore.RdbStore).query("EMPLOYEE", predicates, ["ID", "NAME", "AGE", "SALARY", "CODES"]).then((resultSet: relationalStore.ResultSet) => {
    console.info(`ResultSet column names: ${resultSet.columnNames}, column count: ${resultSet.columnCount}`);
    // resultSet is a cursor of a data set. By default, the cursor points to the -1st record. Valid data starts from 0.
    while (resultSet.goToNextRow()) {
      const id = resultSet.getLong(resultSet.getColumnIndex("ID"));
      const name = resultSet.getString(resultSet.getColumnIndex("NAME"));
      const age = resultSet.getLong(resultSet.getColumnIndex("AGE"));
      const salary = resultSet.getDouble(resultSet.getColumnIndex("SALARY"));
      console.info(`id=${id}, name=${name}, age=${age}, salary=${salary}`);
    }
    // Release the dataset memory.
    resultSet.close();
  }).catch((err: BusinessError) => {
    console.error(`Query failed, code is ${err.code},message is ${err.message}`);
  })
}
```

### cloudSync<sup>11+</sup>

cloudSync(mode: SyncMode, predicates: RdbPredicates, progress: Callback&lt;ProgressDetails&gt;, callback: AsyncCallback&lt;void&gt;): void

Manually performs device-cloud sync based on specified conditions. This API uses an asynchronous callback to return the result. The cloud sync function must be implemented. Otherwise, this API cannot be used.

**System capability**: SystemCapability.DistributedDataManager.CloudSync.Client

**System API**: This is a system API.

**Parameters**

| Name        | Type                            | Mandatory| Description                           |
|-------------|--------------------------------| ---- |-------------------------------|
| mode        | [SyncMode](js-apis-data-relationalStore.md#syncmode)          | Yes  | Sync mode of the database.                  |
| predicates  | [RdbPredicates](js-apis-data-relationalStore.md#rdbpredicates)                  | Yes  | Conditions for data sync.                 |
| progress    | Callback&lt;[ProgressDetails](js-apis-data-relationalStore.md#details10)&gt; | Yes  | Callback used to process database sync details.          |
| callback    | AsyncCallback&lt;void&gt;      | Yes  | Callback used to send the sync result to the caller.|

**Example**

```ts
let predicates = new relationalStore.RdbPredicates("EMPLOYEE");
predicates.in("id", ["id1", "id2"]);

if(store != undefined) {
  (store as relationalStore.RdbStore).cloudSync(relationalStore.SyncMode.SYNC_MODE_CLOUD_FIRST, predicates, (progressDetail: relationalStore.ProgressDetails) => {
    console.info(`progress: ${progressDetail}`);
   }, (err) => {
     if (err) {
       console.error(`cloudSync failed, code is ${err.code},message is ${err.message}}`);
       return;
     }
     console.info('Cloud sync succeeded');
  });
};
```

### cloudSync<sup>11+</sup>

cloudSync(mode: SyncMode, predicates: RdbPredicates, progress: Callback&lt;ProgressDetails&gt;): Promise&lt;void&gt;

Manually performs device-cloud sync based on specified conditions. This API uses a promise to return the result. The cloud sync function must be implemented. Otherwise, this API cannot be used.

**System capability**: SystemCapability.DistributedDataManager.CloudSync.Client

**System API**: This is a system API.

**Parameters**

| Name       | Type                             | Mandatory| Description                 |
|------------|---------------------------------| ---- |---------------------|
| mode       | [SyncMode](js-apis-data-relationalStore.md#syncmode)           | Yes  | Sync mode of the database.        |
| predicates | [RdbPredicates](js-apis-data-relationalStore.md#rdbpredicates)                   | Yes  | Conditions for data sync.               |
| progress   | Callback&lt;[ProgressDetails](js-apis-data-relationalStore.md#progressdetails10)&gt; | Yes  | Callback used to process database sync details.|

**Return value**

| Type               | Description                                   |
| ------------------- | --------------------------------------- |
| Promise&lt;void&gt; | Promise used to return the sync result.|

**Example**

```ts
import {BusinessError} from "@ohos.base";

let predicates = new relationalStore.RdbPredicates("EMPLOYEE");
predicates.in("id", ["id1", "id2"]);

if(store != undefined) {
  (store as relationalStore.RdbStore).cloudSync(relationalStore.SyncMode.SYNC_MODE_CLOUD_FIRST, predicates, (progressDetail: relationalStore.ProgressDetails) => {
    console.info(`progress: ${progressDetail}`);
  }).then(() => {
    console.info('Cloud sync succeeded');
  }).catch((err: BusinessError) => {
    console.error(`cloudSync failed, code is ${err.code},message is ${err.message}}`);
  });
};
```

### querySharingResource<sup>11+</sup>

querySharingResource(predicates: RdbPredicates, columns?: Array&lt;string&gt;): Promise&lt;ResultSet&gt;

Queries the shared resource of the data matching the specified conditions. This API uses a promise to return the result set, which includes the shared resource ID and the column names if the column names are specified.

**System capability**: SystemCapability.DistributedDataManager.CloudSync.Client

**System API**: This is a system API.

**Parameters**

| Name  | Type                                                 | Mandatory| Description                                              |
| -------- | ----------------------------------------------------- | ---- | -------------------------------------------------- |
| predicates | [RdbPredicates](js-apis-data-relationalStore.md#rdbpredicates) | Yes  | Query conditions.   |
| columns    | Array&lt;string&gt;      | No  | Columns to be searched for. If this parameter is not specified, the returned result set contains only the shared resource ID.|

**Return value**

| Name   | Description                                              |
| -------- | ------------------------------------------------- |
| Promise&lt;[ResultSet](#resultset)&gt; | Promise used to return the result set.  |

**Error codes**

For details about the error codes, see [RDB Error Codes](errorcode-data-rdb.md).

| **ID**| **Error Message**                          |
| ------------ | -------------------------------------- |
| 14800000     | Inner error.                           |

**Example**

```ts
import { BusinessError } from "@ohos.base";

let sharingResource: string;
let predicates = new relationalStore.RdbPredicates('test_table');
predicates.equalTo('data', 'data_test');
if(store != undefined) {
  (store as relationalStore.RdbStore).querySharingResource(predicates, ['uuid', 'data']).then((resultSet) => {
    if (!resultSet.goToFirstRow()) {
      console.error(`resultSet error`);
      return;
    }
    const res = resultSet.getString(resultSet.getColumnIndex(relationalStore.Field.SHARING_RESOURCE_FIELD));
    console.info(`sharing resource: ${res}`);
    sharingResource = res;
  }).catch((err: BusinessError) => {
    console.error(`query sharing resource failed, code is ${err.code},message is ${err.message}`);
  })
}

```

### querySharingResource<sup>11+</sup>

querySharingResource(predicates: RdbPredicates, callback: AsyncCallback&lt;ResultSet&gt;): void

Queries the shared resource of the data matching the specified conditions. This API uses an asynchronous callback to return the result set.

**System capability**: SystemCapability.DistributedDataManager.CloudSync.Client

**System API**: This is a system API.

**Parameters**

| Name  | Type                                                 | Mandatory| Description                                              |
| -------- | ----------------------------------------------------- | ---- | -------------------------------------------------- |
| predicates | [RdbPredicates](js-apis-data-relationalStore.md#rdbpredicates)              | Yes  | Query conditions.          |
| callback   | AsyncCallback&lt;[ResultSet](#resultset)&gt; | Yes  | Callback used to return the result set.|

**Error codes**

For details about the error codes, see [RDB Error Codes](errorcode-data-rdb.md).

| **ID**| **Error Message**                          |
| ------------ | -------------------------------------- |
| 14800000     | Inner error.                           |

**Example**

```ts
let sharingResource: string;
let predicates = new relationalStore.RdbPredicates('test_table');
predicates.equalTo('data', 'data_test');
if(store != undefined) {
  (store as relationalStore.RdbStore).querySharingResource(predicates,(err, resultSet) => {
    if (err) {
      console.error(`sharing resource failed, code is ${err.code},message is ${err.message}`);
      return;
    }
    if (!resultSet.goToFirstRow()) {
      console.error(`resultSet error`);
      return;
    }
    const res = resultSet.getString(resultSet.getColumnIndex(relationalStore.Field.SHARING_RESOURCE_FIELD));
    console.info(`sharing resource: ${res}`);
    sharingResource = res;
  })
}

```

### querySharingResource<sup>11+</sup>

querySharingResource(predicates: RdbPredicates, columns: Array&lt;string&gt;, callback: AsyncCallback&lt;ResultSet&gt;): void

Queries the shared resource of the data matching the specified conditions. This API uses an asynchronous callback to return the shared resource ID and the column names specified.

**System capability**: SystemCapability.DistributedDataManager.CloudSync.Client

**System API**: This is a system API.

**Parameters**

| Name  | Type                                                 | Mandatory| Description                                              |
| -------- | ----------------------------------------------------- | ---- | -------------------------------------------------- |
| predicates | [RdbPredicates](js-apis-data-relationalStore.md#rdbpredicates) | Yes  | Query conditions.          |
| columns    | Array&lt;string&gt;              | Yes  | Columns to be searched for.          |
| callback   | AsyncCallback&lt;[ResultSet](#resultset)&gt;  | Yes  | Callback used to return the result set.|

**Error codes**

For details about the error codes, see [RDB Error Codes](errorcode-data-rdb.md).

| **ID**| **Error Message**                          |
| ------------ | -------------------------------------- |
| 14800000     | Inner error.                           |

**Example**

```ts
let sharingResource: string;
let predicates = new relationalStore.RdbPredicates('test_table');
predicates.equalTo('data', 'data_test');
if(store != undefined) {
  (store as relationalStore.RdbStore).querySharingResource(predicates, ['uuid', 'data'], (err, resultSet) => {
    if (err) {
      console.error(`sharing resource failed, code is ${err.code},message is ${err.message}`);
      return;
    }
    if (!resultSet.goToFirstRow()) {
      console.error(`resultSet error`);
      return;
    }
    const res = resultSet.getString(resultSet.getColumnIndex(relationalStore.Field.SHARING_RESOURCE_FIELD));
    console.info(`sharing resource: ${res}`);
    sharingResource = res;
  })
}

```
