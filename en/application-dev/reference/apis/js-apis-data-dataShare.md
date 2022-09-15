# Data Sharing

The **DataShare** module allows an application to manage its own data and share data with other applications on the same device.

> **NOTE**
>
> The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
> The APIs provided by this module are system APIs.
>
> The APIs of this module can be used only in the stage model.


## Modules to Import

```ts
import dataShare from '@ohos.data.dataShare'
```


## dataShare.createDataShareHelper

createDataShareHelper(context: Context, uri: string, callback: AsyncCallback&lt;DataShareHelper&gt;): void

Creates a **DataShareHelper** instance. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.DistributedDataManager.DataShare.Consumer

**Parameters**

| Name  | Type                                                | Mandatory| Description                                                        |
| -------- | -------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| context  | [Context](js-apis-application-context.md#context)        | Yes  | Context of an application.                                          |
| uri      | string                                                   | Yes  | Uniform Resource Identifier (URI) of the server application to connect.                              |
| callback | AsyncCallback&lt;[DataShareHelper](#datasharehelper)&gt; | Yes  | Callback invoked to return the result. If the operation is successful, **err** is **undefined** and **data** is the **DataShareHelper** instance created. Otherwise, **err** is an error object.|

**Example**

```ts
import Ability from '@ohos.application.Ability'

let uri = ("datashare:///com.samples.datasharetest.DataShare");
let dataShareHelper;
dataShare.createDataShareHelper(this.context, uri, (err, data) => {
    if (err != undefined) {
        console.info("createDataShareHelper failed, error message : " + err);
    } else {
        console.info("createDataShareHelper succeed, data : " + data);
        dataShareHelper = data;
    }
});
```

## dataShare.createDataShareHelper

createDataShareHelper(context: Context, uri: string): Promise&lt;DataShareHelper&gt;

Creates a **DataShareHelper** instance. This API uses a promise to return the result.

**System capability**: SystemCapability.DistributedDataManager.DataShare.Consumer

**Parameters**

| Name | Type                                         | Mandatory| Description                          |
| ------- | ------------------------------------------------- | ---- | ------------------------------ |
| context | [Context](js-apis-application-context.md#context) | Yes  | Context of an application.            |
| uri     | string                                            | Yes  | URI of the server application to connect.|

**Return value**

| Type                                              | Description                                  |
| -------------------------------------------------- | -------------------------------------- |
| Promise&lt;[DataShareHelper](#datasharehelper)&gt; | Promise used to return the **DataShareHelper** instance created.|

**Example**

```ts
import Ability from '@ohos.application.Ability'

let uri = ("datashare:///com.samples.datasharetest.DataShare");
let dataShareHelper;
dataShare.createDataShareHelper(this.context, uri).then((data) => {
    console.info("createDataShareHelper succeed, data : " + data);
    dataShareHelper = data;
}).catch((err) => {
	console.info("createDataShareHelper failed, error message : " + err); 
})
```

## DataShareHelper

Provides a **DataShareHelper** instance to access or manage data on the server. Before calling an API provided by **DataShareHelper**, you must create a **DataShareHelper** instance using [createDataShareHelper](#datasharecreatedatasharehelper).

### on('dataChange')

on(type: 'dataChange', uri: string, callback: AsyncCallback&lt;void&gt;): void

Subscribes to changes of the specified data. After an observer is registered, the subscriber will receive a notification when the change notification is triggered (the **notifyChange()** method is called). This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.DistributedDataManager.DataShare.Consumer

**Parameters**

| Name    | Type                | Mandatory| Description                    |
| -------- | -------------------- | ---- | ------------------------ |
| type     | string               | Yes  | Event type to subscribe to. The value is **dataChange**, which indicates data change events.|
| uri      | string               | Yes  | URI of the data.|
| callback | AsyncCallback&lt;void&gt; | Yes  | Callback invoked to return the result. If the data is changed, the value of **err** is **undefined**. Otherwise, this callback is not invoked or the value of **err** is an error object.|

**Example**

```ts
import Ability from '@ohos.application.Ability'
function onCallback() {
    console.info("**** Observer on callback ****");
}
let uri = ("datashare:///com.samples.datasharetest.DataShare");
dataShareHelper.on("dataChange", uri, onCallback);
```

### off('dataChange')

off(type: 'dataChange', uri: string, callback?: AsyncCallback&lt;void&gt;): void

Unsubscribes from the changes of the specified data. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.DistributedDataManager.DataShare.Consumer

**Parameters**

| Name    | Type                | Mandatory| Description                    |
| -------- | -------------------- | ---- | ------------------------ |
| type     | string               | Yes  | Event type to unsubscribe from. The value is **dataChange**, which indicates data change events.|
| uri      | string               | Yes  | URI of the data.|
| callback | AsyncCallback&lt;void&gt; | No  | Callback used to return the result. If the operation is successful, **err** is **undefined**. Otherwise, **err** is an error object.|

**Example**

```ts
import Ability from '@ohos.application.Ability'
function offCallback() {
    console.info("**** Observer off callback ****");
}
let uri = ("datashare:///com.samples.datasharetest.DataShare");
dataShareHelper.off("dataChange", uri, offCallback);
```

### insert

insert(uri: string, value: ValuesBucket, callback: AsyncCallback&lt;number&gt;): void

Inserts a single data record into the database. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.DistributedDataManager.DataShare.Consumer

**Parameters**

| Name    | Type                                                     | Mandatory| Description                                                        |
| -------- | --------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| uri      | string                                                    | Yes  | URI of the data to insert.                                    |
| value    | [ValuesBucket](js-apis-data-ValuesBucket.md#valuesbucket) | Yes  | Data to insert. If this parameter is empty, a blank row will be inserted.          |
| callback | AsyncCallback&lt;number&gt;                               | Yes  | Callback invoked to return the result. If the operation is successful, **err** is **undefined** and **data** is the index of the inserted data record. Otherwise, **err** is an error object.<br>The data index is not returned if the APIs of the database in use, for example, the key-value database (KVDB), do not support the return of indexes.|

**Example**

```ts
import Ability from '@ohos.application.Ability'
let uri = ("datashare:///com.samples.datasharetest.DataShare");
const valueBucket = {
    "name": "rose",
    "age": 22,
    "salary": 200.5,
}
dataShareHelper.insert(uri, valueBucket, (err, data) => {
    if (err != undefined) {
        console.log("insert failed, error message : " + err);
    }else{
        console.log("insert succeed, data : " + data);
    }
});
```

### insert

insert(uri: string, value: ValuesBucket): Promise&lt;number&gt;

Inserts a single data record into the database. This API uses a promise to return the result.

**System capability**: SystemCapability.DistributedDataManager.DataShare.Consumer

**Parameters**

| Name | Type                                                     | Mandatory| Description                                              |
| ----- | --------------------------------------------------------- | ---- | -------------------------------------------------- |
| uri   | string                                                    | Yes  | URI of the data to insert.                          |
| value | [ValuesBucket](js-apis-data-ValuesBucket.md#valuesbucket) | Yes  | Data to insert. If this parameter is empty, a blank row will be inserted.|

**Return value**

| Type            | Description                                                        |
| ---------------- | ------------------------------------------------------------ |
| Promise&lt;number&gt; | Promise used to return the index of the inserted data record.<br>The data index is not returned if the APIs of the database in use (for example, KVDB) do not support the return of indexes.|

**Example**

```ts
import Ability from '@ohos.application.Ability'
let uri = ("datashare:///com.samples.datasharetest.DataShare");
const valueBucket = {
    "name": "rose1",
    "age": 221,
    "salary": 20.5,
}
dataShareHelper.insert(uri, valueBucket).then((data) => {
    console.log("insert succeed, data : " + data);
}).catch((err) => {
    console.log("insert failed, error message : " + err);
});
```

### delete

delete(uri: string, predicates: dataSharePredicates.DataSharePredicates, callback: AsyncCallback&lt;number&gt;): void

Deletes one or more data records from the database. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.DistributedDataManager.DataShare.Consumer

**Parameters**

| Name      | Type                                                        | Mandatory| Description                                                        |
| ---------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| uri        | string                                                       | Yes  | URI of the data to delete.                                    |
| predicates | [DataSharePredicates](js-apis-data-dataSharePredicates.md#datasharepredicates) | Yes  | Filter criteria.<br>The predicate methods supported by **delete()** vary depending on the database in use. For example, the KVDB supports only **inKeys**.|
| callback   | AsyncCallback&lt;number&gt;                                  | Yes  | Callback invoked to return the result. If the operation is successful, **err** is **undefined** and **data** is the number of deleted data records. Otherwise, **err** is an error object.<br>The number of deleted data records is not returned if the APIs of the database in use (for example, KVDB) do not support this return.|

**Example**

```ts
import Ability from '@ohos.application.Ability'
import dataSharePredicates from '@ohos.data.dataSharePredicates'

let uri = ("datashare:///com.samples.datasharetest.DataShare");
let da = new dataSharePredicates.DataSharePredicates();
da.equalTo("name", "ZhangSan");
dataShareHelper.delete(uri, da, (err, data) => {
    if (err != undefined) {
        console.log("delete failed, error message : " + err);
    }else{
        console.log("delete succeed, data : " + data);
    }
});
```

### delete

delete(uri: string, predicates: dataSharePredicates.DataSharePredicates): Promise&lt;number&gt;

Deletes one or more data records from the database. This API uses a promise to return the result.

**System capability**: SystemCapability.DistributedDataManager.DataShare.Consumer

**Parameters**

| Name      | Type                                                        | Mandatory| Description                                                        |
| ---------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| uri        | string                                                       | Yes  | URI of the data to delete.                                    |
| predicates | [DataSharePredicates](js-apis-data-dataSharePredicates.md#datasharepredicates) | Yes  | Filter criteria.<br>The predicate methods supported by **delete()** vary depending on the database in use. For example, the KVDB supports only **inKeys**.|

**Return value**

| Type            | Description                                                        |
| ---------------- | ------------------------------------------------------------ |
| Promise&lt;number&gt; | Promise used to return the number of deleted data records.<br>The number of deleted data records is not returned if the APIs of the database in use (for example, KVDB) do not support this return.|

**Example**

```ts
import Ability from '@ohos.application.Ability'
import dataSharePredicates from '@ohos.data.dataSharePredicates'

let uri = ("datashare:///com.samples.datasharetest.DataShare");
let da = new dataSharePredicates.DataSharePredicates();
da.equalTo("name", "ZhangSan");
dataShareHelper.delete(uri, da).then((data) => {
    console.log("delete succeed, data : " + data);
}).catch((err) => {
    console.log("delete failed, error message : " + err);
});
```

### query

query(uri: string, predicates: dataSharePredicates.DataSharePredicates, columns: Array&lt;string&gt;, callback: AsyncCallback&lt;DataShareResultSet&gt;): void

Queries data in the database. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.DistributedDataManager.DataShare.Consumer

**Parameters**

| Name      | Type                                                        | Mandatory| Description                                                        |
| ---------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| uri        | string                                                       | Yes  | URI of the data to query.                                    |
| predicates | [DataSharePredicates](js-apis-data-dataSharePredicates.md#datasharepredicates) | Yes  | Filter criteria.<br>The predicate methods supported by **query()** vary depending on the database used. For example, the KVDB supports only **inKeys** and **prefixKey**.|
| columns    | Array&lt;string&gt;                                          | Yes  | Columns to query. If this parameter is empty, all columns will be queried.              |
| callback   | AsyncCallback&lt;[DataShareResultSet](js-apis-data-DataShareResultSet.md#datashareresultset)&gt; | Yes  | Callback invoked to return the result. If the operation is successful, **err** is **undefined** and **data** is the result set obtained. Otherwise, **err** is an error object.|

**Example**

```ts
import Ability from '@ohos.application.Ability'
import dataSharePredicates from '@ohos.data.dataSharePredicates'

let uri = ("datashare:///com.samples.datasharetest.DataShare");
let columns = ["*"];
let da = new dataSharePredicates.DataSharePredicates();
da.equalTo("name", "ZhangSan");
dataShareHelper.query(uri, da, columns, (err, data) => {
    if (err != undefined) {
        console.log("query failed, error message : " + err);
    }else{
        console.log("query succeed, rowCount : " + data.rowCount);
    }
});
```

### query

query(uri: string, predicates: dataSharePredicates.DataSharePredicates, columns: Array&lt;string&gt;): Promise&lt;DataShareResultSet&gt;

Queries data in the database. This API uses a promise to return the result.

**System capability**: SystemCapability.DistributedDataManager.DataShare.Consumer

**Parameters**

| Name      | Type                                                        | Mandatory| Description                                                        |
| ---------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| uri        | string                                                       | Yes  | URI of the data to query.                                    |
| predicates | [DataSharePredicates](js-apis-data-dataSharePredicates.md#datasharepredicates) | Yes  | Filter criteria.<br>The predicate methods supported by **query()** vary depending on the database used. For example, the KVDB supports only **inKeys** and **prefixKey**.|
| columns    | Array&lt;string&gt;                                          | Yes  | Columns to query. If this parameter is empty, all columns will be queried.              |

**Return value**

| Type                                                        | Description                             |
| ------------------------------------------------------------ | --------------------------------- |
| Promise&lt;[DataShareResultSet](js-apis-data-DataShareResultSet.md#datashareresultset)&gt; | Promise used to return the result set obtained.|

**Example**

```ts
import Ability from '@ohos.application.Ability'
import dataSharePredicates from '@ohos.data.dataSharePredicates'

let uri = ("datashare:///com.samples.datasharetest.DataShare");
let columns = ["*"];
let da = new dataSharePredicates.DataSharePredicates();
da.equalTo("name", "ZhangSan");
dataShareHelper.query(uri, da, columns).then((data) => {
    console.log("query succeed, rowCount : " + data.rowCount);
}).catch((err) => {
    console.log("query failed, error message : " + err);
});
```

### update

update(uri: string, predicates: dataSharePredicates.DataSharePredicates, value: ValuesBucket, callback: AsyncCallback&lt;number&gt;): void

Updates data in the database. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.DistributedDataManager.DataShare.Consumer

**Parameters**

| Name      | Type                                                        | Mandatory| Description                                                        |
| ---------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| uri        | string                                                       | Yes  | URI of the data to update.                                    |
| predicates | [DataSharePredicates](js-apis-data-dataSharePredicates.md#datasharepredicates) | Yes  | Filter criteria.<br>The predicate methods supported by **update()** vary depending on the database in use. For example, only the relational database (RDB) supports predicates.|
| value      | [ValuesBucket](js-apis-data-ValuesBucket.md#valuesbucket)    | Yes  | New data.                                          |
| callback   | AsyncCallback&lt;number&gt;                                  | Yes  | Callback invoked to return the result. If the operation is successful, **err** is **undefined** and **data** is the number of updated data records. Otherwise, **err** is an error object.<br>The number of updated data records is not returned if the APIs of the database in use (for example, KVDB) do not support this return.|

**Example**

```ts
import Ability from '@ohos.application.Ability'
import dataSharePredicates from '@ohos.data.dataSharePredicates'

let uri = ("datashare:///com.samples.datasharetest.DataShare");
let da = new dataSharePredicates.DataSharePredicates();
da.equalTo("name", "ZhangSan");
const va = {
    "name": "roe1",
    "age": 21,
    "salary": 20.5,
   
}
dataShareHelper.update(uri, da, va, (err, data) => {
    if (err != undefined) {
        console.log("update failed, error message : " + err);
    }else{
        console.log("update succeed, data : " + data);
    }
});
```

### update

update(uri: string, predicates: dataSharePredicates.DataSharePredicates, value: ValuesBucket): Promise&lt;number&gt;

Updates data in the database. This API uses a promise to return the result.

**System capability**: SystemCapability.DistributedDataManager.DataShare.Consumer

**Parameters**

| Name      | Type                                                        | Mandatory| Description                                                        |
| ---------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| uri        | string                                                       | Yes  | URI of the data to update.                                    |
| predicates | [DataSharePredicates](js-apis-data-dataSharePredicates.md#datasharepredicates) | Yes  | Filter criteria.<br>The predicate methods supported by **update()** vary depending on the database in use. For example, only the relational database (RDB) supports predicates.|
| value      | [ValuesBucket](js-apis-data-ValuesBucket.md#valuesbucket)    | Yes  | New data.                                          |

**Return value**

| Type            | Description                                                        |
| ---------------- | ------------------------------------------------------------ |
| Promise&lt;number&gt; | Promise used to return the number of data records updated.<br>The number of updated data records is not returned if the APIs of the database in use (for example, KVDB) do not support this return.|

**Example**

```ts
import Ability from '@ohos.application.Ability'
import dataSharePredicates from '@ohos.data.dataSharePredicates'

let uri = ("datashare:///com.samples.datasharetest.DataShare");
let da = new dataSharePredicates.DataSharePredicates();
da.equalTo("name", "ZhangSan");
const va = {
    "name": "roe1",
    "age": 21,
    "salary": 20.5,
   
}
dataShareHelper.update(uri, da, va).then((data) => {
    console.log("update succeed, data : " + data);
}).catch((err) => {
    console.log("update failed, error message : " + err);
});
```

### batchInsert

batchInsert(uri: string, values: Array&lt;ValuesBucket&gt;, callback: AsyncCallback&lt;number&gt;): void

Batch inserts data into the database. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.DistributedDataManager.DataShare.Consumer

**Parameters**

| Name    | Type                                                        | Mandatory| Description                                                        |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| uri      | string                                                       | Yes  | URI of the data to insert.                                    |
| values   | Array&lt;[ValuesBucket](js-apis-data-ValuesBucket.md#valuesbucket)&gt; | Yes  | Data to insert.                                          |
| callback | AsyncCallback&lt;number&gt;                                  | Yes  | Callback invoked to return the result. If the operation is successful, **err** is **undefined** and **data** is the number of data records inserted. Otherwise, **err** is an error object.<br>The number of inserted data records is not returned if the APIs of the database in use (for example, KVDB) do not support this return.|

**Example**

```ts
import Ability from '@ohos.application.Ability'
let uri = ("datashare:///com.samples.datasharetest.DataShare");
let vbs = new Array({"name": "roe11", "age": 21, "salary": 20.5,},
                     {"name": "roe12", "age": 21, "salary": 20.5,},
                     {"name": "roe13", "age": 21, "salary": 20.5,})
dataShareHelper.batchInsert(uri, vbs, (err, data) => {
    if (err != undefined) {
        console.log("batchInsert failed, error message : " + err);
    }else{
        console.log("batchInsert succeed, data : " + data);
    }
});
```

### batchInsert

batchInsert(uri: string, values: Array&lt;ValuesBucket&gt;): Promise&lt;number&gt;

Batch inserts data into the database. This API uses a promise to return the result.

**System capability**: SystemCapability.DistributedDataManager.DataShare.Consumer

**Parameters**

| Name  | Type                                                        | Mandatory| Description                    |
| ------ | ------------------------------------------------------------ | ---- | ------------------------ |
| uri    | string                                                       | Yes  | URI of the data to insert.|
| values | Array&lt;[ValuesBucket](js-apis-data-ValuesBucket.md#valuesbucket)&gt; | Yes  | Data to insert.      |

**Return value**

| Type            | Description                                                        |
| ---------------- | ------------------------------------------------------------ |
| Promise&lt;number&gt; | Promise used to return the number of data records inserted.<br>The number of inserted data records is not returned if the APIs of the database (for example, KVDB) in use do not the return of the number of data records.|

**Example**

```ts
import Ability from '@ohos.application.Ability'
let uri = ("datashare:///com.samples.datasharetest.DataShare");
let vbs = new Array({"name": "roe11", "age": 21, "salary": 20.5,},
                     {"name": "roe12", "age": 21, "salary": 20.5,},
                     {"name": "roe13", "age": 21, "salary": 20.5,})
dataShareHelper.batchInsert(uri, vbs).then((data) => {
    console.log("batchInsert succeed, data : " + data);
}).catch((err) => {
    console.log("batchInsert failed, error message : " + err);
});
```

### normalizeUri

normalizeUri(uri: string, callback: AsyncCallback&lt;string&gt;): void

Normalizes a **DataShare** URI. The **DataShare** URI can be used only by the local device, but the normalized URI can be used across devices. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.DistributedDataManager.DataShare.Consumer

**Parameters**

| Name    | Type                  | Mandatory| Description                                                    |
| -------- | ---------------------- | ---- | -------------------------------------------------------- |
| uri      | string                 | Yes  | [URI](js-apis-uri.md#uri) to normalize.     |
| callback | AsyncCallback&lt;string&gt; | Yes  | Callback invoked to return the result. If the operation is successful, **err** is **undefined** and **data** is the normalized URI (if **null** is returned, URI normalization is not supported). Otherwise, **err** is an error object.|

**Example**

```ts
import Ability from '@ohos.application.Ability'
let uri = ("datashare:///com.samples.datasharetest.DataShare");
dataShareHelper.normalizeUri(uri, (err, data) => {
    if (err != undefined) {
        console.log("normalizeUri failed, error message : " + err);
    }else{
        console.log("normalizeUri = " + data);
    }
});
```

### normalizeUri

normalizeUri(uri: string): Promise&lt;string&gt;

Normalizes a **DataShare** URI. The **DataShare** URI can be used only by the local device, but the normalized URI can be used across devices. This API uses a promise to return the result.

**System capability**: SystemCapability.DistributedDataManager.DataShare.Consumer

**Parameters**

| Name| Type  | Mandatory| Description                                     |
| ---- | ------ | ---- | ----------------------------------------- |
| uri  | string | Yes  | [URI](js-apis-uri.md#uri) to normalize.|

**Return value**

| Type            | Description                                          |
| ---------------- | ---------------------------------------------- |
| Promise&lt;string&gt; | Promise used to return the result. If URI normalization is supported, the normalized URI is returned. Otherwise, **null** is returned.|

**Example**

```ts
import Ability from '@ohos.application.Ability'
let uri = ("datashare:///com.samples.datasharetest.DataShare");
dataShareHelper.normalizeUri(uri).then((data) => {
    console.log("normalizeUri = " + data);
}).catch((err) => {
    console.log("normalizeUri failed, error message : " + err);
});
```

### denormalizeUri

denormalizeUri(uri: string, callback: AsyncCallback&lt;string&gt;): void

Denormalizes a URI. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.DistributedDataManager.DataShare.Consumer

**Parameters**

| Name    | Type                  | Mandatory| Description                                               |
| -------- | ---------------------- | ---- | --------------------------------------------------- |
| uri      | string                 | Yes  | [URI](js-apis-uri.md#uri) to denormalize.|
| callback | AsyncCallback&lt;string&gt; | Yes  | Callback invoked to return the result. If the operation is successful, **err** is **undefined** and **data** is the URI obtained. If the original URI is returned, denormalization is not required. If **null** is returned, denormalization is not supported. If the operation fails, **err** is an error object.|

**Example**

```ts
import Ability from '@ohos.application.Ability'
let uri = ("datashare:///com.samples.datasharetest.DataShare");
dataShareHelper.denormalizeUri(uri, (err, data) => {
    if (err != undefined) {
        console.log("denormalizeUri failed, error message : " + err);
    }else{
        console.log("denormalizeUri = " + data);
    }
});
```

### denormalizeUri

denormalizeUri(uri: string): Promise&lt;string&gt;

Denormalizes a URI. This API uses a promise to return the result.

**System capability**: SystemCapability.DistributedDataManager.DataShare.Consumer

**Parameters**

| Name| Type  | Mandatory| Description                                       |
| ---- | ------ | ---- | ------------------------------------------- |
| uri  | string | Yes  | [URI](js-apis-uri.md#uri) to denormalize.|

**Return value**

| Type            | Description                                     |
| ---------------- | ----------------------------------------- |
| Promise&lt;string&gt; | Promise used to return the result. If the denormalization is successful, the URI obtained is returned. If no operation is required, the original URI is returned. If denormalization is not supported, **null** is returned.|

**Example**

```ts
import Ability from '@ohos.application.Ability'
let uri = ("datashare:///com.samples.datasharetest.DataShare");
dataShareHelper.denormalizeUri(uri).then((data) => {
    console.log("denormalizeUri = " + data);
}).catch((err) => {
    console.log("denormalizeUri failed, error message : " + err);
});
```

### notifyChange

notifyChange(uri: string, callback: AsyncCallback&lt;void&gt;): void

Notifies the registered observer of data changes. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.DistributedDataManager.DataShare.Consumer

**Parameters**

| Name    | Type                | Mandatory| Description                    |
| -------- | -------------------- | ---- | ------------------------ |
| uri      | string               | Yes  | URI of the data.|
| callback | AsyncCallback&lt;void&gt; | Yes  | Callback invoked to return the result. If the observer is notified of the data changes, **err** is **undefined**. Otherwise, **err** is an error object.|

**Example**

```ts
import Ability from '@ohos.application.Ability'
let uri = ("datashare:///com.samples.datasharetest.DataShare");
dataShareHelper.notifyChange(uri, () => {
    console.log("***** notifyChange *****");
});
```

### notifyChange

notifyChange(uri: string): Promise&lt;void&gt;

Notifies the registered observer of data changes. This API uses a promise to return the result.

**System capability**: SystemCapability.DistributedDataManager.DataShare.Consumer

**Parameters**

| Name| Type  | Mandatory| Description                |
| ---- | ------ | ---- | -------------------- |
| uri  | string | Yes  | URI of the data.|

**Return value**

| Type          | Description                 |
| -------------- | --------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Example**

```ts
import Ability from '@ohos.application.Ability'
let uri = ("datashare:///com.samples.datasharetest.DataShare");
dataShareHelper.notifyChange(uri);
```
