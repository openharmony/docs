# @ohos.application.DataShareExtensionAbility (DataShare ExtensionAbility) (System API)

The **DataShareExtensionAbility** module provides data share services based on the ExtensionAbility.

>**NOTE**
>
> - The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
> - The APIs provided by this module are system APIs.
>
> - The APIs of this module can be used only in the stage model.


## Modules to Import

```ts
import { DataShareExtensionAbility } from '@kit.ArkData';
```

## Properties

**System capability**: SystemCapability.DistributedDataManager.DataShare.Provider

| Name| Type| Readable| Writable| Description| 
| -------- | -------- | -------- | -------- | -------- |
| context<sup>10+</sup> | [ExtensionContext](../apis-ability-kit/js-apis-inner-application-extensionContext.md)  | Yes| No|Context of the DataShare ExtensionAbility.|

## onCreate

onCreate?(want: Want, callback: AsyncCallback&lt;void&gt;): void

Called by the server to initialize service logic when the DataShare client connects to the DataShareExtensionAbility server. This API can be overridden as required.

**System capability**: SystemCapability.DistributedDataManager.DataShare.Provider

**Parameters**

| Name| Type| Mandatory| Description|
| ----- | ------ | ------ | ------ |
| want | [Want](../apis-ability-kit/js-apis-app-ability-want.md#want) | Yes | Want information, including the ability name and bundle name.|
| callback | AsyncCallback&lt;void&gt; | Yes| Callback that returns no value.|

**Example**

```ts
import { DataShareExtensionAbility, relationalStore } from '@kit.ArkData';
import { Want } from '@kit.AbilityKit';

let DB_NAME = 'DB00.db';
let TBL_NAME = 'TBL00';
let DDL_TBL_CREATE = 'CREATE TABLE IF NOT EXISTS '
  + TBL_NAME
  + ' (id INTEGER PRIMARY KEY AUTOINCREMENT, name TEXT, age INTEGER, phoneNumber DOUBLE, isStudent BOOLEAN, Binary BINARY)';
let rdbStore: relationalStore.RdbStore;

export default class DataShareExtAbility extends DataShareExtensionAbility {
  onCreate(want: Want, callback: Function) {
    relationalStore.getRdbStore(this.context, {
      name: DB_NAME,
      securityLevel: relationalStore.SecurityLevel.S3
    }, (err, data) => {
      console.info(`getRdbStore done, data : ${data}`);
      rdbStore = data;
      rdbStore.executeSql(DDL_TBL_CREATE, [], (err) => {
        console.error(`executeSql done, error message : ${err}`);
      });
      if (callback) {
        callback();
      }
    });
  }
};
```

## UpdateOperation<sup>12+</sup>

Represents the batch update operation information.

**System capability**: SystemCapability.DistributedDataManager.DataShare.Provider

| Name           | Type                                                        | Mandatory| Description          |
| --------------- | ------------------------------------------------------------ | ---- | -------------- |
| UpdateOperation | [dataShare.UpdateOperation](js-apis-data-dataShare-sys.md#updateoperation12) | Yes  | Data to update.|

## insert

insert?(uri: string, valueBucket: ValuesBucket, callback: AsyncCallback&lt;number&gt;): void

Inserts data into the database. This API can be overridden as required.

**System capability**: SystemCapability.DistributedDataManager.DataShare.Provider

**Parameters**

| Name| Type| Mandatory| Description|
| ----- | ------ | ------ | ------ |
| uri |string | Yes | URI of the data to insert.|
| valueBucket |[ValuesBucket](js-apis-data-valuesBucket.md#valuesbucket) | Yes| Data to insert.|
| callback |AsyncCallback&lt;number&gt; | Yes| Callback used to return the index of the data inserted.|

**Example**

```ts
import { DataShareExtensionAbility, relationalStore, ValuesBucket } from '@kit.ArkData';

let TBL_NAME = 'TBL00';
let rdbStore: relationalStore.RdbStore;

export default class DataShareExtAbility extends DataShareExtensionAbility {
  insert(uri: string, valueBucket: ValuesBucket, callback: Function) {
    if (valueBucket === null) {
      console.error('invalid valueBuckets');
      return;
    }
    rdbStore.insert(TBL_NAME, valueBucket, (err, ret) => {
      console.info(`callback ret: ${ret}`);
      if (callback !== undefined) {
        callback(err, ret);
      }
    });
  }
};
```

## update

update?(uri: string, predicates: dataSharePredicates.DataSharePredicates, valueBucket: ValuesBucket, callback: AsyncCallback&lt;number&gt;): void

Updates data in the database. This API can be overridden as required.

**System capability**: SystemCapability.DistributedDataManager.DataShare.Provider

**Parameters**

| Name| Type| Mandatory| Description|
| ----- | ------ | ------ | ------ |
| uri | string | Yes | URI of the data to update.|
| predicates | [dataSharePredicates.DataSharePredicates](js-apis-data-dataSharePredicates.md#datasharepredicates) | Yes | Filter criteria for updating data.|
| valueBucket | [ValuesBucket](js-apis-data-valuesBucket.md#valuesbucket) | Yes| New data.|
| callback | AsyncCallback&lt;number&gt; | Yes| Callback used to return the number of updated data records.|

**Example**

```ts
import { DataShareExtensionAbility, relationalStore, dataSharePredicates, ValuesBucket } from '@kit.ArkData';

let TBL_NAME = 'TBL00';
let rdbStore: relationalStore.RdbStore;

export default class DataShareExtAbility extends DataShareExtensionAbility {
  update(uri: string, predicates: dataSharePredicates.DataSharePredicates, valueBucket: ValuesBucket, callback: Function) {
    if (predicates === null || predicates === undefined) {
      return;
    }
    rdbStore.update(TBL_NAME, valueBucket, predicates, (err, ret) => {
      if (callback !== undefined) {
        callback(err, ret);
      }
    });
  }
};
```

## batchUpdate<sup>12+</sup>

batchUpdate?( operations: Record&lt;string, Array&lt;UpdateOperation&gt;&gt; , callback:  AsyncCallback&lt;Record&lt;string, Array&lt;number&gt;&gt;&gt;): void

Batch updates data into the database. This API is called by the server and can be overridden as required.

**System capability**: SystemCapability.DistributedDataManager.DataShare.Provider

**Parameters**

| Name    | Type                                                        | Mandatory| Description                                                  |
| ---------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------ |
| operations | Record&lt;string, Array&lt;[UpdateOperation](#updateoperation12)&gt;&gt; | Yes  | Collection of the path of the data to update, update conditions, and new data.                |
| callback   | AsyncCallback&lt;Record&lt;string, Array&lt;number&gt;&gt;&gt;  | Yes  | Callback used to return an array of updated data records. The value **-1** means the update operation fails.|

**Example**

```ts
import { DataShareExtensionAbility, relationalStore, dataShare } from '@kit.ArkData';
import { BusinessError } from '@kit.BasicServicesKit'

let TBL_NAME = 'TBL00';
let rdbStore: relationalStore.RdbStore;

export default class DataShareExtAbility extends DataShareExtensionAbility {
  batchUpdate(operations:Record<string, Array<dataShare.UpdateOperation>>, callback:Function) {
    let recordOps : Record<string, Array<dataShare.UpdateOperation>> = operations;
    let results : Record<string, Array<number>> = {};
    let a = Object.entries(recordOps);
    for (let i = 0; i < a.length; i++) {
      let key = a[i][0];
      let values = a[i][1];
      let result : number[] = [];
      for (const value of values) {
        rdbStore.update(TBL_NAME, value.values, value.predicates).then(async (rows) => {
          console.info('Update row count is ' + rows);
          result.push(rows);
        }).catch((err:BusinessError) => {
          console.info('Update failed, err is ' + JSON.stringify(err));
          result.push(-1)
        })
      }
      results[key] = result;
    }
    callback(null, results);
  }
};
```

## delete

delete?(uri: string, predicates: dataSharePredicates.DataSharePredicates, callback: AsyncCallback&lt;number&gt;): void

Deletes data from the database. This API can be overridden as required.

**System capability**: SystemCapability.DistributedDataManager.DataShare.Provider

**Parameters**

| Name      | Type                                                    | Mandatory| Description                              |
| ---------- | ------------------------------------------------------------ | ---- | ---------------------------------- |
| uri        | string                                                       | Yes  | URI of the data to delete.          |
| predicates | [dataSharePredicates.DataSharePredicates](js-apis-data-dataSharePredicates.md#datasharepredicates) | Yes  | Filter criteria for deleting data.                    |
| callback   | AsyncCallback&lt;number&gt;                                  | Yes  | Callback used to return the number of data records deleted.|

**Example**

```ts
import { DataShareExtensionAbility, relationalStore, dataSharePredicates } from '@kit.ArkData';

let TBL_NAME = 'TBL00';
let rdbStore: relationalStore.RdbStore;

export default class DataShareExtAbility extends DataShareExtensionAbility {
  delete(uri: string, predicates: dataSharePredicates.DataSharePredicates, callback: Function) {
    if (predicates === null || predicates === undefined) {
      return;
    }
    rdbStore.delete(TBL_NAME, predicates, (err, ret) => {
      if (callback !== undefined) {
        callback(err, ret);
      }
    });
  }
};
```

## query

query?(uri: string, predicates: dataSharePredicates.DataSharePredicates, columns: Array&lt;string&gt;, callback: AsyncCallback&lt;Object&gt;): void

Queries data from the database. This API can be overridden as required.

**System capability**: SystemCapability.DistributedDataManager.DataShare.Provider

**Parameters**

| Name| Type| Mandatory| Description|
| ----- | ------ | ------ | ------ |
| uri | string | Yes | URI of the data to query.|
| predicates | [dataSharePredicates.DataSharePredicates](js-apis-data-dataSharePredicates.md#datasharepredicates) | Yes | Filter criteria for querying data.|
| columns | Array&lt;string&gt; | Yes| Columns to query. If this parameter is empty, all columns will be queried.|
| callback | AsyncCallback&lt;Object&gt; | Yes| Callback used to return the result set obtained.|

**Example**

```ts
import { DataShareExtensionAbility, relationalStore, dataSharePredicates } from '@kit.ArkData';

let TBL_NAME = 'TBL00';
let rdbStore: relationalStore.RdbStore;

export default class DataShareExtAbility extends DataShareExtensionAbility {
  query(uri: string, predicates: dataSharePredicates.DataSharePredicates, columns: Array<string>, callback: Function) {
    if (predicates === null || predicates === undefined) {
      return;
    }
    rdbStore.query(TBL_NAME, predicates, columns, (err, resultSet) => {
      if (resultSet !== undefined) {
        console.info(`resultSet.rowCount: ${resultSet.rowCount}`);
      }
      if (callback !== undefined) {
        callback(err, resultSet);
      }
    });
  }
};
```

## batchInsert

batchInsert?(uri: string, valueBuckets: Array&lt;ValuesBucket&gt;, callback: AsyncCallback&lt;number&gt;): void

Batch inserts data into the database. This API is called by the server and can be overridden as required.

**System capability**: SystemCapability.DistributedDataManager.DataShare.Provider

**Parameters**

| Name       | Type                                                    | Mandatory| Description                            |
| ------------ | ------------------------------------------------------------ | ---- | -------------------------------- |
| uri          | string                                                       | Yes  | URI of the data to insert.    |
| valueBuckets | Array&lt;[ValuesBucket](js-apis-data-valuesBucket.md#valuesbucket)&gt; | Yes  | Data to insert.          |
| callback     | AsyncCallback&lt;number&gt;                                  | Yes  | Callback used to return the number of inserted data records.|

**Example**

```ts
import { DataShareExtensionAbility, relationalStore, ValuesBucket } from '@kit.ArkData';

let TBL_NAME = 'TBL00';
let rdbStore: relationalStore.RdbStore;

export default class DataShareExtAbility extends DataShareExtensionAbility {
  batchInsert(uri: string, valueBuckets: Array<ValuesBucket>, callback: Function) {
    if (valueBuckets === null || valueBuckets.length === undefined) {
      console.error('invalid valueBuckets');
      return;
    }
    rdbStore.batchInsert(TBL_NAME, valueBuckets, (err, ret) => {
      if (callback !== undefined) {
        callback(err, ret);
      }
    });
  };
};
```

## normalizeUri

normalizeUri?(uri: string, callback: AsyncCallback&lt;string&gt;): void

Normalizes a URI. This API can be overridden as required.

**System capability**: SystemCapability.DistributedDataManager.DataShare.Provider

**Parameters**

| Name    | Type                 | Mandatory| Description                   |
| -------- | --------------------- | ---- | ----------------------- |
| uri      | string                | Yes  | [URI](../apis-arkts/js-apis-uri.md#uri) to normalize.|
| callback | AsyncCallback&lt;string&gt; | Yes  | Callback used to return the result. If the operation is successful, the normalized URI is returned. Otherwise, **null** is returned.|

**Example**

```ts
import { DataShareExtensionAbility } from '@kit.ArkData';
import { BusinessError } from '@kit.BasicServicesKit'

export default class DataShareExtAbility extends DataShareExtensionAbility {
  normalizeUri(uri: string, callback: Function) {
    let key = 'code';
    let value = 0;
    let err: BusinessError = {
      code: value,
      name: key,
      message: key
    };
    let ret: string = `normalize: ${uri}`;
    callback(err, ret);
  }
};
```

## denormalizeUri

denormalizeUri?(uri: string, callback: AsyncCallback&lt;string&gt;): void

Denormalizes a URI. This API can be overridden as required.

**System capability**: SystemCapability.DistributedDataManager.DataShare.Provider

**Parameters**

| Name    | Type                 | Mandatory| Description                   |
| -------- | --------------------- | ---- | ----------------------- |
| uri      | string                | Yes  | [URI](../apis-arkts/js-apis-uri.md#uri) to denormalize.|
| callback | AsyncCallback&lt;string&gt; | Yes  | Callback used to return the result. If the operation is successful, the denormalized URI is returned. If the URI passed in is returned, denormalization is not required. If denormalization is not supported, **null** is returned.|

**Example**

```ts
import { DataShareExtensionAbility } from '@kit.ArkData';
import { BusinessError } from '@kit.BasicServicesKit'

export default class DataShareExtAbility extends DataShareExtensionAbility {
  denormalizeUri(uri: string, callback: Function) {
    let key = 'code';
    let value = 0;
    let err: BusinessError = {
      code: value,
      name: key,
      message: key
    };
      let ret = `denormalize ${uri}`;
      callback(err, ret);
  }
};
```
