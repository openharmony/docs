# @ohos.data.relationalStore (RDB Store) (System API)
<!--Kit: ArkData-->
<!--Subsystem: DistributedDataManager-->
<!--Owner: @baijidong-->
<!--Designer: @widecode; @htt1997-->
<!--Tester: @yippo; @logic42-->
<!--Adviser: @ge-yafang-->

The relational database (RDB) store manages data based on relational models. It provides a complete mechanism for managing local databases based on the underlying SQLite. To satisfy different needs in complicated scenarios, the RDB store offers a series of APIs for performing operations such as adding, deleting, modifying, and querying data, and supports direct execution of SQL statements. The worker threads are not supported.
ArkTS supports the following basic data types: number, string, binary data, and boolean. The maximum size of a data record is 2 MB. If a data record exceeds 2 MB, it can be inserted successfully but cannot be read.

The **relationalStore** module provides the following functions:

- [RdbPredicates](arkts-apis-data-relationalStore-RdbPredicates.md): provides predicates indicating the nature, feature, or relationship of a data entity in an RDB store. It is used to define the operation conditions for an RDB store.
- [RdbStore](arkts-apis-data-relationalStore-RdbStore.md): provides APIs for managing data in an RDB store.
- [ResultSet](arkts-apis-data-relationalStore-ResultSet.md): provides APIs for accessing the result set obtained from the RDB store.

> **NOTE**
> 
> - The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
> - This topic describes only the system APIs provided by the module. For details about its public APIs, see [@ohos.data.relationalStore](arkts-apis-data-relationalStore.md).

## Modules to Import

```ts
import { relationalStore } from '@kit.ArkData';
```

## StoreConfig

Defines the configuration of an RDB store.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

| Name       | Type         | Mandatory| Description                                                     |
| ------------- | ------------- | ---- | --------------------------------------------------------- |
| isSearchable<sup>11+</sup> | boolean | No| Whether the RDB store is searchable. The value **true** means the RDB store is searchable; the value **false** means the opposite. The default value is **false**.<br>**System API**: This is a system API.<br>This parameter is supported since API version 11. |
| haMode<sup>12+</sup> | [HAMode](#hamode12) | No| High availability (HA) mode.<br>The value **SINGLE** means data can be written only to a single RDB store. The value **MAIN_REPLICA** means data can be written to the main and replica RDB stores to ensure HA. However, this mode is not supported in encryption and attach scenarios. The default value is **SINGLE**. The value **MAIN_REPLICA** may affect the database write performance.<br>**System API**: This is a system API.<br>This parameter is supported since API version 12. |

## HAMode<sup>12+</sup>

Enumerates the HA modes of an RDB store.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

| Name                             | Value  | Description            |
| ------------------------------- | --- | -------------- |
| SINGLE      | 0 | Allows data to be written to a single RDB store.     |
| MAIN_REPLICA | 1 | Allows data to be written to the main and replica RDB stores for HA. This mode is not supported in encryption and attach scenarios.|

## Reference<sup>11+</sup>

Represents the reference between tables by field. If table **b** references table **a**, table **a** is the source table and **b** is the target table.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**System API**: This is a system API.

| Name      | Type  | Mandatory| Description                                    |
| ---------- | ------ | ---- | ---------------------------------------- |
| sourceTable | string | Yes  | Name of the table referenced.  |
| targetTable | string | Yes  | Name of the table that references the source table.  |
| refFields   | Record<string, string> | Yes  | Fields referenced. In a KV pair, the key indicates the field in the source table, and the value indicates the field in the target table.      |

## DistributedConfig<sup>10+</sup>

Defines the configuration of the distributed mode of tables.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

| Name    | Type   | Mandatory| Description                                                        |
| -------- | ------- | ---- | ------------------------------------------------------------ |
| references<sup>11+</sup> | Array&lt;[Reference](#reference11)&gt; | No  | References between tables. You can reference multiple fields, and their values must be the same in the source and target tables. By default, database tables are not referenced with each other.<br>**System API**: This is a system API.<br>This parameter is supported since API version 11.|

## RdbStore

Provides APIs for managing data in an RDB store.

Before using the following APIs, you should obtain a **RdbStore** instance by calling the [getRdbStore](arkts-apis-data-relationalStore-f.md#relationalstoregetrdbstore-1) method and then call the corresponding method through the instance.

In addition, use [execute](arkts-apis-data-relationalStore-RdbStore.md#execute12) to initialize the database table structure and related data first, ensuring that the prerequisites for related API calls are met.

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
| values     | [ValuesBucket](arkts-apis-data-relationalStore-t.md#valuesbucket)                                | Yes  | Rows of data to update in the RDB store. The key-value pair is associated with the column name in the target table.|
| predicates | [dataSharePredicates.DataSharePredicates](js-apis-data-dataSharePredicates.md#datasharepredicates) | Yes  | Update conditions specified by the **DataSharePredicates** object.               |
| callback   | AsyncCallback&lt;number&gt;                                  | Yes  | Callback used to return the number of rows updated.                  |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [RDB Store Error Codes](errorcode-data-rdb.md).

| **ID**| **Error Message**                                                |
|-----------| ------------------------------------------------------------ |
| 202       | Permission verification failed, application which is not a system application uses system API. |
| 401       | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 14800000  | Inner error. |
| 14800011  | Failed to open the database because it is corrupted. |
| 14800014  | The RdbStore or ResultSet is already closed. |
| 14800015  | The database does not respond. |
| 14800021  | SQLite: Generic error. Possible causes: Insert failed or the updated data does not exist. |
| 14800022  | SQLite: Callback routine requested an abort. |
| 14800023  | SQLite: Access permission denied. |
| 14800024  | SQLite: The database file is locked. |
| 14800025  | SQLite: A table in the database is locked. |
| 14800026  | SQLite: The database is out of memory. |
| 14800027  | SQLite: Attempt to write a readonly database. |
| 14800028  | SQLite: Some kind of disk I/O error occurred. |
| 14800029  | SQLite: The database is full. |
| 14800030  | SQLite: Unable to open the database file. |
| 14800031  | SQLite: TEXT or BLOB exceeds size limit. |
| 14800032  | SQLite: Abort due to constraint violation. |
| 14800033  | SQLite: Data type mismatch. |
| 14800034  | SQLite: Library used incorrectly. |
| 14800047  | The WAL file size exceeds the default limit. |

**Example**

```ts
import { dataSharePredicates } from '@kit.ArkData';
import { ValuesBucket } from '@kit.ArkData';

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
if (store != undefined) {
  (store as relationalStore.RdbStore).update("EMPLOYEE", valueBucket1, predicates, (err, rows) => {
    if (err) {
      console.error(`Updated failed, code is ${err.code},message is ${err.message}`);
      return;
    }
    console.info(`Updated row count: ${rows}`);
  });
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
| values     | [ValuesBucket](arkts-apis-data-relationalStore-t.md#valuesbucket)                                | Yes  | Rows of data to update in the RDB store. The key-value pair is associated with the column name in the target table.|
| predicates | [dataSharePredicates.DataSharePredicates](js-apis-data-dataSharePredicates.md#datasharepredicates) | Yes  | Update conditions specified by the **DataSharePredicates** object.               |

**Return value**

| Type                 | Description                                     |
| --------------------- | ----------------------------------------- |
| Promise&lt;number&gt; | Promise used to return the number of rows updated.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [RDB Store Error Codes](errorcode-data-rdb.md).

| **ID**| **Error Message**                                                |
|-----------| ------------------------------------------------------------ |
| 202       | Permission verification failed, application which is not a system application uses system API. |
| 401       | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 14800000  | Inner error. |
| 14800011  | Failed to open the database because it is corrupted. |
| 14800014  | The RdbStore or ResultSet is already closed. |
| 14800015  | The database does not respond. |
| 14800021  | SQLite: Generic error. Possible causes: Insert failed or the updated data does not exist. |
| 14800022  | SQLite: Callback routine requested an abort. |
| 14800023  | SQLite: Access permission denied. |
| 14800024  | SQLite: The database file is locked. |
| 14800025  | SQLite: A table in the database is locked. |
| 14800026  | SQLite: The database is out of memory. |
| 14800027  | SQLite: Attempt to write a readonly database. |
| 14800028  | SQLite: Some kind of disk I/O error occurred. |
| 14800029  | SQLite: The database is full. |
| 14800030  | SQLite: Unable to open the database file. |
| 14800031  | SQLite: TEXT or BLOB exceeds size limit. |
| 14800032  | SQLite: Abort due to constraint violation. |
| 14800033  | SQLite: Data type mismatch. |
| 14800034  | SQLite: Library used incorrectly. |
| 14800047  | The WAL file size exceeds the default limit. |

**Example**

```ts
import { dataSharePredicates } from '@kit.ArkData';
import { ValuesBucket } from '@kit.ArkData';
import { BusinessError } from '@kit.BasicServicesKit';

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
if (store != undefined) {
  (store as relationalStore.RdbStore).update("EMPLOYEE", valueBucket1, predicates).then(async (rows: number) => {
    console.info(`Updated row count: ${rows}`);
  }).catch((err: BusinessError) => {
    console.error(`Updated failed, code is ${err.code},message is ${err.message}`);
  });
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
| table      | string                                                       | Yes  | Name of the target table, which cannot be an empty string.             |
| predicates | [dataSharePredicates.DataSharePredicates](js-apis-data-dataSharePredicates.md#datasharepredicates) | Yes  | Deletion conditions specified by the **DataSharePredicates** object.|
| callback   | AsyncCallback&lt;number&gt;                                  | Yes  | Callback used to return the number of rows deleted.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [RDB Store Error Codes](errorcode-data-rdb.md).

| **ID**| **Error Message**                                                |
|-----------| ------------------------------------------------------------ |
| 202       | Permission verification failed, application which is not a system application uses system API. |
| 401       | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 14800000  | Inner error. |
| 14800011  | Failed to open the database because it is corrupted. |
| 14800014  | The RdbStore or ResultSet is already closed. |
| 14800015  | The database does not respond. |
| 14800021  | SQLite: Generic error. Possible causes: Insert failed or the updated data does not exist. |
| 14800022  | SQLite: Callback routine requested an abort. |
| 14800023  | SQLite: Access permission denied. |
| 14800024  | SQLite: The database file is locked. |
| 14800025  | SQLite: A table in the database is locked. |
| 14800026  | SQLite: The database is out of memory. |
| 14800027  | SQLite: Attempt to write a readonly database. |
| 14800028  | SQLite: Some kind of disk I/O error occurred. |
| 14800029  | SQLite: The database is full. |
| 14800030  | SQLite: Unable to open the database file. |
| 14800031  | SQLite: TEXT or BLOB exceeds size limit. |
| 14800032  | SQLite: Abort due to constraint violation. |
| 14800033  | SQLite: Data type mismatch. |
| 14800034  | SQLite: Library used incorrectly. |
| 14800047  | The WAL file size exceeds the default limit. |

**Example**

```ts
import { dataSharePredicates } from '@kit.ArkData';

let predicates = new dataSharePredicates.DataSharePredicates();
predicates.equalTo("NAME", "Lisa");
if (store != undefined) {
  (store as relationalStore.RdbStore).delete("EMPLOYEE", predicates, (err, rows) => {
    if (err) {
      console.error(`Delete failed, code is ${err.code},message is ${err.message}`);
      return;
    }
    console.info(`Delete rows: ${rows}`);
  });
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
| predicates | [dataSharePredicates.DataSharePredicates](js-apis-data-dataSharePredicates.md#datasharepredicates) | Yes  | Deletion conditions specified by the **DataSharePredicates** object.|

**Return value**

| Type                 | Description                           |
| --------------------- | ------------------------------- |
| Promise&lt;number&gt; | Promise used to return the number of rows deleted.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [RDB Store Error Codes](errorcode-data-rdb.md).

| **ID**| **Error Message**     |
|-----------| --------------------- |
| 202       | Permission verification failed, application which is not a system application uses system API. |
| 401       | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 14800000  | Inner error. |
| 14800011  | Failed to open the database because it is corrupted. |
| 14800014  | The RdbStore or ResultSet is already closed. |
| 14800015  | The database does not respond. |
| 14800021  | SQLite: Generic error. Possible causes: Insert failed or the updated data does not exist. |
| 14800022  | SQLite: Callback routine requested an abort. |
| 14800023  | SQLite: Access permission denied. |
| 14800024  | SQLite: The database file is locked. |
| 14800025  | SQLite: A table in the database is locked. |
| 14800026  | SQLite: The database is out of memory. |
| 14800027  | SQLite: Attempt to write a readonly database. |
| 14800028  | SQLite: Some kind of disk I/O error occurred. |
| 14800029  | SQLite: The database is full. |
| 14800030  | SQLite: Unable to open the database file. |
| 14800031  | SQLite: TEXT or BLOB exceeds size limit. |
| 14800032  | SQLite: Abort due to constraint violation. |
| 14800033  | SQLite: Data type mismatch. |
| 14800034  | SQLite: Library used incorrectly. |
| 14800047  | The WAL file size exceeds the default limit. |

**Example**

```ts
import { dataSharePredicates } from '@kit.ArkData';
import { BusinessError } from '@kit.BasicServicesKit';

let predicates = new dataSharePredicates.DataSharePredicates();
predicates.equalTo("NAME", "Lisa");
if (store != undefined) {
  (store as relationalStore.RdbStore).delete("EMPLOYEE", predicates).then((rows: number) => {
    console.info(`Delete rows: ${rows}`);
  }).catch((err: BusinessError) => {
    console.error(`Delete failed, code is ${err.code},message is ${err.message}`);
  });
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
| callback   | AsyncCallback&lt;[ResultSet](arkts-apis-data-relationalStore-ResultSet.md)&gt; | Yes  | Callback used to return the result. If the operation is successful, a **ResultSet** object will be returned.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [RDB Store Error Codes](errorcode-data-rdb.md).

| **ID**| **Error Message**          |
|-----------| ------------------ |
| 202       | Permission verification failed, application which is not a system application uses system API. |
| 401       | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 14800000  | Inner error. |
| 14800014  | The RdbStore or ResultSet is already closed. |
| 14800015  | The database does not respond. |

**Example**

```ts
import { dataSharePredicates } from '@kit.ArkData';

let predicates = new dataSharePredicates.DataSharePredicates();
predicates.equalTo("NAME", "Rose");
if (store != undefined) {
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
  });
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
| callback   | AsyncCallback&lt;[ResultSet](arkts-apis-data-relationalStore-ResultSet.md)&gt; | Yes  | Callback used to return the result. If the operation is successful, a **ResultSet** object will be returned.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [RDB Store Error Codes](errorcode-data-rdb.md).

| **ID**| **Error Message**     |
|-----------| --------------- |
| 202       | Permission verification failed, application which is not a system application uses system API. |
| 401       | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 14800000  | Inner error. |
| 14800014  | The RdbStore or ResultSet is already closed. |
| 14800015  | The database does not respond. |

**Example**

```ts
import { dataSharePredicates } from '@kit.ArkData';

let predicates = new dataSharePredicates.DataSharePredicates();
predicates.equalTo("NAME", "Rose");
if (store != undefined) {
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
  });
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
| Promise&lt;[ResultSet](arkts-apis-data-relationalStore-ResultSet.md)&gt; | Promise used to return the result. If the operation is successful, a **ResultSet** object will be returned.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [RDB Store Error Codes](errorcode-data-rdb.md).

| **ID**| **Error Message**        |
|-----------| ----------- |
| 202       | Permission verification failed, application which is not a system application uses system API. |
| 401       | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 14800000  | Inner error. |
| 14800014  | The RdbStore or ResultSet is already closed. |
| 14800015  | The database does not respond. |

**Example**

```ts
import { dataSharePredicates } from '@kit.ArkData';
import { BusinessError } from '@kit.BasicServicesKit';

let predicates = new dataSharePredicates.DataSharePredicates();
predicates.equalTo("NAME", "Rose");
if (store != undefined) {
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
  });
}
```

### cloudSync<sup>11+</sup>

cloudSync(mode: SyncMode, predicates: RdbPredicates, progress: Callback&lt;ProgressDetails&gt;, callback: AsyncCallback&lt;void&gt;): void

Manually performs device-cloud sync based on specified conditions. This API uses an asynchronous callback to return the result. The cloud sync function must be implemented. Otherwise, this API cannot be used.

> **NOTE**
>
> Since API version 18, you can specify assets in predicates when performing manual device-cloud sync. In this case, the sync mode must be **relationalStore.SyncMode.SYNC_MODE_CLOUD_FIRST**.
>
> When specifying the predicates, you can use the primary key (mandatory) and asset (optional) as sync conditions. If assets are specified, the predicate supports only [equalTo](arkts-apis-data-relationalStore-RdbPredicates.md#equalto), with a limit of 50 assets. If more assets are involved, you are advised to use only the primary key as the sync condition.

**System capability**: SystemCapability.DistributedDataManager.CloudSync.Client

**System API**: This is a system API.

**Parameters**

| Name        | Type                            | Mandatory| Description                           |
|-------------|--------------------------------| ---- |-------------------------------|
| mode        | [SyncMode](arkts-apis-data-relationalStore-e.md#syncmode)          | Yes  | Sync mode of the database.                  |
| predicates  | [RdbPredicates](arkts-apis-data-relationalStore-RdbPredicates.md)                  | Yes  | Conditions for data sync.                 |
| progress    | Callback&lt;[ProgressDetails](arkts-apis-data-relationalStore-i.md#progressdetails10)&gt; | Yes  | Callback used to process database sync details.          |
| callback    | AsyncCallback&lt;void&gt;      | Yes  | Callback used to return the sync result to the caller.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [RDB Store Error Codes](errorcode-data-rdb.md).

| **ID**| **Error Message**    |
|-----------|--------------|
| 202       | if permission verification failed, application which is not a system application uses system API. |
| 401       | Parameter error. Possible causes: 1. Need 2 - 4  parameter(s). 2. The RdbStore must be not nullptr. 3. The mode must be a SyncMode of cloud. 4. The tablesNames must be not empty. 5. The progress must be a callback type. 6.The callback must be a function.|
| 801       | Capability not supported.  |
| 14800014  | The RdbStore or ResultSet is already closed.      |

**Example 1**: Manually sync data on the local device with the cloud.

```ts
let predicates = new relationalStore.RdbPredicates("EMPLOYEE");
predicates.in("id", ["id1", "id2"]);

if (store != undefined) {
  (store as relationalStore.RdbStore).cloudSync(relationalStore.SyncMode.SYNC_MODE_CLOUD_FIRST, predicates, (progressDetail: relationalStore.ProgressDetails) => {
    console.info(`progress: ${progressDetail.schedule}`);
  }, (err) => {
    if (err) {
      console.error(`cloudSync failed, code is ${err.code}, message is ${err.message}`);
      return;
    }
    console.info('Cloud sync succeeded');
  });
};
```
**Example 2**: Download the specified asset.
```ts
let predicates = new relationalStore.RdbPredicates("EMPLOYEE");
let asset: relationalStore.Asset = {
  name: "name",
  uri: "uri",
  path: "path",
  createTime: new Date().getTime().toString(),
  modifyTime: new Date().getTime().toString(),
  size: "1024"
};
// Specify the primary key and asset (asset column in the database) in the predicates.
predicates.beginWrap().equalTo("id", "id1").and().equalTo("asset", asset).endWrap();

if (store != undefined) {
  (store as relationalStore.RdbStore).cloudSync(relationalStore.SyncMode.SYNC_MODE_CLOUD_FIRST, predicates, (progressDetail: relationalStore.ProgressDetails) => {
    console.info(`progress: ${progressDetail.schedule}`);
  }, (err) => {
    if (err) {
      console.error(`cloud sync failed, code is ${err.code}, message is ${err.message}`);
      return;
    }
    console.info('cloud sync succeeded');
  });
};
```

### cloudSync<sup>11+</sup>

cloudSync(mode: SyncMode, predicates: RdbPredicates, progress: Callback&lt;ProgressDetails&gt;): Promise&lt;void&gt;

Manually performs device-cloud sync based on specified conditions. This API uses a promise to return the result. The cloud sync function must be implemented. Otherwise, this API cannot be used.

> **NOTE**
>
> Since API version 18, you can specify assets in predicates when performing manual device-cloud sync. In this case, the sync mode must be **relationalStore.SyncMode.SYNC_MODE_CLOUD_FIRST**.
>
> When specifying the predicates, you can use the primary key (mandatory) and asset (optional) as sync conditions. If assets are specified, the predicate supports only [equalTo](arkts-apis-data-relationalStore-RdbPredicates.md#equalto), with a limit of 50 assets. If more assets are involved, you are advised to use only the primary key as the sync condition.

**System capability**: SystemCapability.DistributedDataManager.CloudSync.Client

**System API**: This is a system API.

**Parameters**

| Name       | Type                             | Mandatory| Description                 |
|------------|---------------------------------| ---- |---------------------|
| mode       | [SyncMode](arkts-apis-data-relationalStore-e.md#syncmode)           | Yes  | Sync mode of the database.        |
| predicates | [RdbPredicates](arkts-apis-data-relationalStore-RdbPredicates.md)                   | Yes  | Conditions for data sync.               |
| progress   | Callback&lt;[ProgressDetails](arkts-apis-data-relationalStore-i.md#progressdetails10)&gt; | Yes  | Callback used to process database sync details.|

**Return value**

| Type               | Description                                   |
| ------------------- | --------------------------------------- |
| Promise&lt;void&gt; | Promise used to return the sync result.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [RDB Store Error Codes](errorcode-data-rdb.md).

| **ID**| **Error Message**           |
|-----------|---------------------------|
| 202       | if permission verification failed, application which is not a system application uses system API.  |
| 401       | Parameter error. Possible causes: 1. Need 2 - 4  parameter(s). 2. The RdbStore must be not nullptr. 3. The mode must be a SyncMode of cloud. 4. The tablesNames must be not empty. 5. The progress must be a callback type. |
| 801       | Capability not supported.       |
| 14800014  | The RdbStore or ResultSet is already closed.      |

**Example 1**: Manually sync data on the local device with the cloud.

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let predicates = new relationalStore.RdbPredicates("EMPLOYEE");
predicates.in("id", ["id1", "id2"]);

if (store != undefined) {
  (store as relationalStore.RdbStore).cloudSync(relationalStore.SyncMode.SYNC_MODE_CLOUD_FIRST, predicates, (progressDetail: relationalStore.ProgressDetails) => {
    console.info(`progress: ${progressDetail.schedule}`);
  }).then(() => {
    console.info('cloud sync succeeded');
  }).catch((err: BusinessError) => {
    console.error(`cloud sync failed, code is ${err.code}, message is ${err.message}`);
  });
};
```
**Example 2**: Download the specified asset.
```ts
import { BusinessError } from '@kit.BasicServicesKit';

let predicates = new relationalStore.RdbPredicates("EMPLOYEE");
let asset: relationalStore.Asset = {
  name: "name",
  uri: "uri",
  path: "path",
  createTime: new Date().getTime().toString(),
  modifyTime: new Date().getTime().toString(),
  size: "1024"
};
// Specify the primary key and asset (asset column in the database) in the predicates.
predicates.beginWrap().equalTo("id", "id1").and().equalTo("asset", asset).endWrap();

if (store != undefined) {
  (store as relationalStore.RdbStore).cloudSync(relationalStore.SyncMode.SYNC_MODE_CLOUD_FIRST, predicates, (progressDetail: relationalStore.ProgressDetails) => {
    console.info(`progress: ${progressDetail.schedule}`);
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
| predicates | [RdbPredicates](arkts-apis-data-relationalStore-RdbPredicates.md) | Yes  | Query conditions.   |
| columns    | Array&lt;string&gt;      | No  | Columns to be searched for. If this parameter is not specified, the returned result set contains only the shared resource ID.|

**Return value**

| Name   | Description                                              |
| -------- | ------------------------------------------------- |
| Promise&lt;[ResultSet](arkts-apis-data-relationalStore-ResultSet.md)&gt; | Promise used to return the result set.  |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [RDB Store Error Codes](errorcode-data-rdb.md).

| **ID**| **Error Message**          |
|-----------|-------------|
| 401       | Parameter error. Possible causes: 1. Need 1 - 3  parameter(s)! 2. The RdbStore must be not nullptr. 3. The predicates must be an RdbPredicates. 4. The columns must be a string array. |
| 801       | Capability not supported.       |
| 14800000  | Inner error.                      |
| 14800011  | Failed to open the database because it is corrupted.           |
| 14800014  | The RdbStore or ResultSet is already closed.                        |
| 14800015  | The database does not respond.          |
| 14800021  | SQLite: Generic error. Possible causes: Insert failed or the updated data does not exist.             |
| 14800022  | SQLite: Callback routine requested an abort.          |
| 14800023  | SQLite: Access permission denied.         |
| 14800024  | SQLite: The database file is locked.         |
| 14800025  | SQLite: A table in the database is locked.           |
| 14800026  | SQLite: The database is out of memory.            |
| 14800027  | SQLite: Attempt to write a readonly database.         |
| 14800028  | SQLite: Some kind of disk I/O error occurred.             |
| 14800029  | SQLite: The database is full.           |
| 14800030  | SQLite: Unable to open the database file.        |
| 14800031  | SQLite: TEXT or BLOB exceeds size limit.           |
| 14800032  | SQLite: Abort due to constraint violation.        |
| 14800033  | SQLite: Data type mismatch.             |
| 14800034  | SQLite: Library used incorrectly.          |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let sharingResource: string;
let predicates = new relationalStore.RdbPredicates('test_table');
predicates.equalTo('data', 'data_test');
if (store != undefined) {
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
  });
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
| predicates | [RdbPredicates](arkts-apis-data-relationalStore-RdbPredicates.md)              | Yes  | Query conditions.          |
| callback   | AsyncCallback&lt;[ResultSet](arkts-apis-data-relationalStore-ResultSet.md)&gt; | Yes  | Callback used to return the result set.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [RDB Store Error Codes](errorcode-data-rdb.md).

| **ID**| **Error Message**     |
|-----------|------|
| 401       | Parameter error. Possible causes: 1. Need 1 - 3  parameter(s)! 2. The RdbStore must be not nullptr. 3. The predicates must be an RdbPredicates. 4. The columns must be a string array. |
| 801       | Capability not supported.                 |
| 14800000  | Inner error.          |
| 14800011  | Failed to open the database because it is corrupted.       |
| 14800014  | The RdbStore or ResultSet is already closed.      |
| 14800015  | The database does not respond.        |
| 14800021  | SQLite: Generic error. Possible causes: Insert failed or the updated data does not exist.        |
| 14800022  | SQLite: Callback routine requested an abort.         |
| 14800023  | SQLite: Access permission denied.                    |
| 14800024  | SQLite: The database file is locked.            |
| 14800025  | SQLite: A table in the database is locked.           |
| 14800026  | SQLite: The database is out of memory.           |
| 14800027  | SQLite: Attempt to write a readonly database.            |
| 14800028  | SQLite: Some kind of disk I/O error occurred.         |
| 14800029  | SQLite: The database is full.       |
| 14800030  | SQLite: Unable to open the database file.       |
| 14800031  | SQLite: TEXT or BLOB exceeds size limit.         |
| 14800032  | SQLite: Abort due to constraint violation.      |
| 14800033  | SQLite: Data type mismatch.         |
| 14800034  | SQLite: Library used incorrectly.     |


**Example**

```ts
let sharingResource: string;
let predicates = new relationalStore.RdbPredicates('test_table');
predicates.equalTo('data', 'data_test');
if (store != undefined) {
  (store as relationalStore.RdbStore).querySharingResource(predicates, (err, resultSet) => {
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
  });
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
| predicates | [RdbPredicates](arkts-apis-data-relationalStore-RdbPredicates.md) | Yes  | Query conditions.          |
| columns    | Array&lt;string&gt;              | Yes  | Columns to be searched for.          |
| callback   | AsyncCallback&lt;[ResultSet](arkts-apis-data-relationalStore-ResultSet.md)&gt;  | Yes  | Callback used to return the result set.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [RDB Store Error Codes](errorcode-data-rdb.md).

| **ID**| **Error Message**      |
|-----------|--------------|
| 401       | Parameter error. Possible causes: 1. Need 1 - 3  parameter(s)! 2. The RdbStore must be not nullptr. 3. The predicates must be an RdbPredicates. 4. The columns must be a string array. |
| 801       | Capability not supported.       |
| 14800000  | Inner error.            |
| 14800011  | Failed to open the database because it is corrupted.         |
| 14800014  | The RdbStore or ResultSet is already closed.          |
| 14800015  | The database does not respond.          |
| 14800021  | SQLite: Generic error. Possible causes: Insert failed or the updated data does not exist.           |
| 14800022  | SQLite: Callback routine requested an abort.    |
| 14800023  | SQLite: Access permission denied.     |
| 14800024  | SQLite: The database file is locked.     |
| 14800025  | SQLite: A table in the database is locked.       |
| 14800026  | SQLite: The database is out of memory.      |
| 14800027  | SQLite: Attempt to write a readonly database.    |
| 14800028  | SQLite: Some kind of disk I/O error occurred.       |
| 14800029  | SQLite: The database is full.       |
| 14800030  | SQLite: Unable to open the database file.       |
| 14800031  | SQLite: TEXT or BLOB exceeds size limit.      |
| 14800032  | SQLite: Abort due to constraint violation.       |
| 14800033  | SQLite: Data type mismatch.        |
| 14800034  | SQLite: Library used incorrectly.          |


**Example**

```ts
let sharingResource: string;
let predicates = new relationalStore.RdbPredicates('test_table');
predicates.equalTo('data', 'data_test');
if (store != undefined) {
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
  });
}
```


### lockCloudContainer<sup>12+</sup>

lockCloudContainer(): Promise&lt;number&gt;

Manually locks the cloud database of an application. This API uses a promise to return the result.

> **NOTE**
>
> After the cloud database is locked, data of the same application logged in with the same account on other devices cannot be synced to the cloud. The cloud sync function must be implemented. Otherwise, this API cannot be used.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**System API**: This is a system API.

**Return value**

| Type               | Description                                   |
| ------------------- | ---------------------------------------|
| Promise&lt;number&gt; | Promise used to return the lock validity period (in ms) if the operation is successful. If the operation fails, **0** is returned.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| **ID**| **Error Message**           |
|-----------|---------------------------|
| 202       | Permission verification failed, application which is not a system application uses system API.  |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

if (store != undefined) {
  (store as relationalStore.RdbStore).lockCloudContainer().then((time: number) => {
    console.info('lockCloudContainer succeeded time:' + time);
  }).catch((err: BusinessError) => {
    console.error(`lockCloudContainer failed, code is ${err.code},message is ${err.message}`);
  });
}
```

### unlockCloudContainer<sup>12+</sup>

unlockCloudContainer(): Promise&lt;void&gt;

Manually unlocks the cloud database of an application. This API uses a promise to return the result. The cloud sync function must be implemented. Otherwise, this API cannot be used.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**System API**: This is a system API.

**Return value**

| Type               | Description                                   |
| ------------------- | --------------------------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| **ID**| **Error Message**           |
|-----------|---------------------------|
| 202       | Permission verification failed, application which is not a system application uses system API.  |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

if (store != undefined) {
  (store as relationalStore.RdbStore).unlockCloudContainer().then(() => {
    console.info('unlockCloudContainer succeeded');
  }).catch((err: BusinessError) => {
    console.error(`unlockCloudContainer failed, code is ${err.code},message is ${err.message}`);
  });
}
```

### restore<sup>12+</sup>

restore(): Promise&lt;void&gt;

Restores data from a replica RDB store file. This API uses a promise to return the result. This API can be used only when [HAMode](#hamode12) is **MAIN_REPLICA**, and cannot be used in transactions.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**System API**: This is a system API.

**Return value**

| Type               | Description                     |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [RDB Store Error Codes](errorcode-data-rdb.md).

| **ID**| **Error Message**                                                |
|-----------| ------------------------------------------------------------ |
| 202       | Permission verification failed, application which is not a system application uses system API. |
| 14800000  | Inner error. |
| 14800010  | Failed to open or delete the database by an invalid database path. |
| 14800011  | Failed to open the database because it is corrupted. |
| 14800014  | The RdbStore or ResultSet is already closed. |
| 14800015  | The database does not respond. |
| 14800021  | SQLite: Generic error. Possible causes: Insert failed or the updated data does not exist. |
| 14800022  | SQLite: Callback routine requested an abort. |
| 14800023  | SQLite: Access permission denied. |
| 14800024  | SQLite: The database file is locked. |
| 14800025  | SQLite: A table in the database is locked. |
| 14800026  | SQLite: The database is out of memory. |
| 14800027  | SQLite: Attempt to write a readonly database. |
| 14800028  | SQLite: Some kind of disk I/O error occurred. |
| 14800029  | SQLite: The database is full. |
| 14800030  | SQLite: Unable to open the database file. |
| 14800031  | SQLite: TEXT or BLOB exceeds size limit. |
| 14800032  | SQLite: Abort due to constraint violation. |
| 14800033  | SQLite: Data type mismatch. |
| 14800034  | SQLite: Library used incorrectly. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

if (store != undefined) {
  let promiseRestore = (store as relationalStore.RdbStore).restore();
  promiseRestore.then(() => {
    console.info('Succeeded in restoring.');
  }).catch((err: BusinessError) => {
    console.error(`Failed to restore, code is ${err.code},message is ${err.message}`);
  });
}
```

## ResultSet

Provides APIs to access the **resultSet** object returned by **query()**.

### getFloat32Array<sup>12+</sup>

getFloat32Array(columnIndex: number): Float32Array

Obtains the value from the specified column in the current row and outputs it in a Float32Array (array of 32-bit floating-point numbers). This API is available only for a [vector database](#storeconfig).

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Parameters**

| Name     | Type  | Mandatory| Description                   |
| ----------- | ------ | ---- | ----------------------- |
| columnIndex | number | Yes  | Index of the target column, starting from 0.|

**Return value**

| Type      | Description                            |
| ---------- | -------------------------------- |
| Float32Array | Value obtained, in a Float32Array.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [RDB Store Error Codes](errorcode-data-rdb.md).

| **ID**| **Error Message**         |
|-----------| ------------ |
| 401       | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 801       | The capability is not supported because the database is not a vector DB. |
| 14800011  | Failed to open the database because it is corrupted. |
| 14800013  | ResultSet is empty or column index is out of bounds. |
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
| 14800030  | SQLite: Unable to open the database file. |
| 14800031  | SQLite: TEXT or BLOB exceeds size limit. |
| 14800032  | SQLite: Abort due to constraint violation. |
| 14800033  | SQLite: Data type mismatch. |
| 14800034  | SQLite: Library used incorrectly. |

**Example**

```ts
let resultSet: relationalStore.ResultSet | undefined;
if (resultSet != undefined) {
  const id = (resultSet as relationalStore.ResultSet).getFloat32Array(0);
}
```
