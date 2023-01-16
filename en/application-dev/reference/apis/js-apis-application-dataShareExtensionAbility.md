# Data Share Extension Ability

The **DataShareExtensionAbility** module provides Extension abilities for data share services.

>**NOTE**
>
> The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
> The APIs provided by this module are system APIs.
>
> The APIs of this module can be used only in the stage model.


## Modules to Import

```ts
import DataShareExtensionAbility from '@ohos.application.DataShareExtensionAbility'
```

## Attributes

**System capability**: SystemCapability.DistributedDataManager.DataShare.Provider

| Name| Type| Readable| Writable| Description| 
| -------- | -------- | -------- | -------- | -------- |
| context | [ExtensionContext](js-apis-extension-context.md)  | Yes| No|Context of the DataShare Extension ability.| 

## onCreate

onCreate?(want: Want, callback: AsyncCallback&lt;void&gt;): void

Called by the server to initialize service logic when the DataShare client connects to the DataShareExtensionAbility server. This API can be overridden as required.

**System capability**: SystemCapability.DistributedDataManager.DataShare.Provider

**Parameters**

| Name| Type| Mandatory| Description|
| ----- | ------ | ------ | ------ |
| want | [Want](js-apis-application-Want.md#want) | Yes | **Want** information, including the ability name and bundle name.|
| callback | AsyncCallback&lt;void&gt; | Yes| Callback that returns no value.|

**Example**

```ts
import rdb from '@ohos.data.rdb';

let DB_NAME = "DB00.db";
let TBL_NAME = "TBL00";
let DDL_TBL_CREATE = "CREATE TABLE IF NOT EXISTS "
    + TBL_NAME
    + " (id INTEGER PRIMARY KEY AUTOINCREMENT, name TEXT, age INTEGER, phoneNumber DOUBLE, isStudent BOOLEAN, Binary BINARY)";
let rdbStore;

export default class DataShareExtAbility extends DataShareExtensionAbility {
    onCreate(want, callback) {
        rdb.getRdbStore(this.context, {
            name: DB_NAME
        }, 1, function (err, data) {
            console.log('getRdbStore done, data : ' + data);
            rdbStore = data;
            rdbStore.executeSql(DDL_TBL_CREATE, [], function (err) {
                console.log('executeSql done, error message : ' + err);
            });
            if (callback) {
                callback();
            }
        });
    }
};
```

## insert

insert?(uri: string, valueBucket: ValuesBucket, callback: AsyncCallback&lt;number&gt;): void

Inserts data into the database. This API can be overridden as required.

**System capability**: SystemCapability.DistributedDataManager.DataShare.Provider

**Parameters**

| Name| Type| Mandatory| Description|
| ----- | ------ | ------ | ------ |
| uri |string | Yes | URI of the data to insert.|
| valueBucket |[ValuesBucket](js-apis-data-ValuesBucket.md#valuesbucket) | Yes| Data to insert.|
| callback |AsyncCallback&lt;number&gt; | Yes| Callback invoked to return the index of the data inserted.|

**Example**

```ts
import rdb from '@ohos.data.rdb';

let DB_NAME = "DB00.db";
let TBL_NAME = "TBL00";
let DDL_TBL_CREATE = "CREATE TABLE IF NOT EXISTS "
    + TBL_NAME
    + " (id INTEGER PRIMARY KEY AUTOINCREMENT, name TEXT, age INTEGER, phoneNumber DOUBLE, isStudent BOOLEAN, Binary BINARY)";
let rdbStore;

export default class DataShareExtAbility extends DataShareExtensionAbility {
    insert(uri, valueBucket, callback) {
        if (valueBucket == null) {
            console.info('invalid valueBuckets');
            return;
        }
        rdbStore.insert(TBL_NAME, valueBucket, function (err, ret) {
            console.info('callback ret:' + ret);
            if (callback != undefined) {
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
| predicates | [DataSharePredicates](js-apis-data-dataSharePredicates.md#datasharepredicates) | Yes | Filter criteria for updating data.|
| valueBucket | [ValuesBucket](js-apis-data-ValuesBucket.md#valuesbucket) | Yes| New data.|
| callback | AsyncCallback&lt;number&gt; | Yes| Callback invoked to return the number of updated data records.|

**Example**

```ts
import rdb from '@ohos.data.rdb';

let DB_NAME = "DB00.db";
let TBL_NAME = "TBL00";
let DDL_TBL_CREATE = "CREATE TABLE IF NOT EXISTS "
    + TBL_NAME
    + " (id INTEGER PRIMARY KEY AUTOINCREMENT, name TEXT, age INTEGER, phoneNumber DOUBLE, isStudent BOOLEAN, Binary BINARY)";
let rdbStore;

export default class DataShareExtAbility extends DataShareExtensionAbility {
    update(uri, predicates, valueBucket, callback) {
        if (predicates == null || predicates == undefined) {
            return;
        }
        rdbStore.update(TBL_NAME, valueBucket, predicates, function (err, ret) {
            if (callback != undefined) {
                callback(err, ret);
            }
        });
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
| predicates | [DataSharePredicates](js-apis-data-dataSharePredicates.md#datasharepredicates) | Yes  | Filter criteria for deleting data.                    |
| callback   | AsyncCallback&lt;number&gt;                                  | Yes  | Callback invoked to return the number of data records deleted.|

**Example**

```ts
import rdb from '@ohos.data.rdb';

let DB_NAME = "DB00.db";
let TBL_NAME = "TBL00";
let DDL_TBL_CREATE = "CREATE TABLE IF NOT EXISTS "
    + TBL_NAME
    + " (id INTEGER PRIMARY KEY AUTOINCREMENT, name TEXT, age INTEGER, phoneNumber DOUBLE, isStudent BOOLEAN, Binary BINARY)";
let rdbStore;

export default class DataShareExtAbility extends DataShareExtensionAbility {
    delete(uri, predicates, callback) {
        if (predicates == null || predicates == undefined) {
            return;
        }
        rdbStore.delete(TBL_NAME, predicates, function (err, ret) {
            if (callback != undefined) {
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
| predicates | [DataSharePredicates](js-apis-data-dataSharePredicates.md#datasharepredicates) | Yes | Filter criteria for querying data.|
| columns | Array&lt;string&gt; | Yes| Columns to query. If this parameter is empty, all columns will be queried.|
| callback | AsyncCallback&lt;Object&gt; | Yes| Callback invoked to return the result set.|

**Example**

```ts
import rdb from '@ohos.data.rdb';

let DB_NAME = "DB00.db";
let TBL_NAME = "TBL00";
let DDL_TBL_CREATE = "CREATE TABLE IF NOT EXISTS "
    + TBL_NAME
    + " (id INTEGER PRIMARY KEY AUTOINCREMENT, name TEXT, age INTEGER, phoneNumber DOUBLE, isStudent BOOLEAN, Binary BINARY)";
let rdbStore;

export default class DataShareExtAbility extends DataShareExtensionAbility {
    query(uri, predicates, columns, callback) {
        if (predicates == null || predicates == undefined) {
            return;
        }
        rdbStore.query(TBL_NAME, predicates, columns, function (err, resultSet) {
            if (resultSet != undefined) {
                console.info('resultSet.rowCount: ' + resultSet.rowCount);
            }
            if (callback != undefined) {
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

| Name        | Type                                                    | Mandatory| Description                            |
| ------------ | ------------------------------------------------------------ | ---- | -------------------------------- |
| uri          | string                                                       | Yes  | URI of the data to insert.    |
| valueBuckets | Array&lt;[ValuesBucket](js-apis-data-ValuesBucket.md#valuesbucket)&gt; | Yes  | Data to insert.          |
| callback     | AsyncCallback&lt;number&gt;                                  | Yes  | Callback invoked to return the number of inserted data records.|

**Example**

```ts
import rdb from '@ohos.data.rdb';

let DB_NAME = "DB00.db";
let TBL_NAME = "TBL00";
let DDL_TBL_CREATE = "CREATE TABLE IF NOT EXISTS "
    + TBL_NAME
    + " (id INTEGER PRIMARY KEY AUTOINCREMENT, name TEXT, age INTEGER, phoneNumber DOUBLE, isStudent BOOLEAN, Binary BINARY)";
let rdbStore;

export default class DataShareExtAbility extends DataShareExtensionAbility {
    batchInsert(uri, valueBuckets, callback) {
        if (valueBuckets == null || valueBuckets.length == undefined) {
            console.info('invalid valueBuckets');
            return;
        }
        let resultNum = valueBuckets.length
        valueBuckets.forEach(vb => {
            rdbStore.insert(TBL_NAME, vb, function (err, ret) {
                if (callback != undefined) {
                    callback(err, resultNum);
                }
            });
        });
    }
};
```

## normalizeUri

normalizeUri?(uri: string, callback: AsyncCallback&lt;string&gt;): void

Normalizes a URI. This API can be overridden as required.

**System capability**: SystemCapability.DistributedDataManager.DataShare.Provider

**Parameters**

| Name    | Type                 | Mandatory| Description                   |
| -------- | --------------------- | ---- | ----------------------- |
| uri      | string                | Yes  | [URI](js-apis-uri.md#uri) to normalize.|
| callback | AsyncCallback&lt;string&gt; | Yes  | Callback used to return the result. If the operation is successful, the normalized URI is returned. Otherwise, **null** is returned.|

**Example**

```ts
export default class DataShareExtAbility extends DataShareExtensionAbility {
    normalizeUri(uri, callback) {
        let err = {"code":0};
        let ret = "normalize+" + uri;
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
| uri      | string                | Yes  | [URI](js-apis-uri.md#uri) to denormalize.|
| callback | AsyncCallback&lt;string&gt; | Yes  | Callback used to return the result. If the operation is successful, the denormalized URI is returned. If the URI passed in is returned, denormalization is not required. If denormalization is not supported, **null** is returned.|

**Example**

```ts
export default class DataShareExtAbility extends DataShareExtensionAbility {
    denormalizeUri(uri, callback) {
        let err = {"code":0};
        let ret = "denormalize+" + uri;
        callback(err, ret);
    }
};
```
