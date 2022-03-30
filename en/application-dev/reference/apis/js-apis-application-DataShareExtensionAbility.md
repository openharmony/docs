# DataShareExtensionAbility

> ![icon-note.gif](public_sys-resources/icon-note.gif) **NOTE**
> The APIs of this module are supported since API 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.


Provides the Extension ability for data sharing.


## Modules to Import

  
```
import DataShareExtensionAbility from '@ohos.application.DataShareExtensionAbility';
```

## Attributes

**System capability**: SystemCapability.DistributedDataManager.DataShare.Provider

| Name| Readable| Writable| Type| Mandatory| Description| 
| -------- | -------- | -------- | -------- | -------- | -------- |
| context | Yes| No| ExtensionContext | No| Context of the Data Share Extension ability.| 


## DataShareExtensionAbility.onCreate

onCreate?(want: Want): void;

Called when the Data Share Extension ability is initialized.

**System capability**: SystemCapability.DistributedDataManager.DataShare.Provider

**Parameters**

  | Name| Type| Mandatory| Description| 
  | -------- | -------- | -------- | -------- |
  | want | Want | Yes| Connection information about the Data Share Extension ability.|

**Example**
    
  ```js
  class myAbility extends DataShareExtensionAbility {
      onCreate(want) {
          console.log('onCreate, want:' + want.abilityName);
      }
  }
  ```

## DataShareExtensionAbility.getFileTypes

getFileTypes?(uri: string, mimeTypeFilter: string, callback: AsyncCallback<Array\<string>>): void

Obtains the supported MIME types of a specified file. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.DistributedDataManager.DataShare.Provider

**Parameters**

| Name          | Type                          | Mandatory| Description                              |
| -------------- | ------------------------------ | ---- | ---------------------------------- |
| uri            | string                         | Yes  | URI of the file.          |
| mimeTypeFilter | string                         | Yes  | MIME type of the file.      |
| callback       | AsyncCallback\<Array\<string>> | Yes  | Callback used to return the supported MIME types.|

**Example**

```js
import featureAbility from '@ohos.ability.featureAbility'
var DAHelper = featureAbility.acquireDataAbilityHelper(
    "dataability:///com.example.DataAbility"
);
DAHelper.getFileTypes(
    "dataability:///com.example.DataAbility",
    "image/*",
    (err, data) => {
		console.info("==========================>Called=======================>");
});
```

## DataShareExtensionAbility.insert

insert?(uri: string, valueBucket: rdb.ValuesBucket, callback: AsyncCallback\<number>): void

Inserts a single data record into the database. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.DistributedDataManager.DataShare.Provider

**Parameters**

| Name        | Type                  | Mandatory| Description                                                  |
| ------------ | ---------------------- | ---- | ------------------------------------------------------ |
| uri          | string                 | Yes  | URI of the data to insert.                              |
| valuesBucket | rdb.ValuesBucket       | Yes  | Data record to insert. If this parameter is **null**, a blank row will be inserted.|
| callback     | AsyncCallback\<number> | Yes  | Callback used to return the index of the inserted data record.                    |

**Example**

```js
import featureAbility from '@ohos.ability.featureAbility'
var DAHelper = featureAbility.acquireDataAbilityHelper(
    "dataability:///com.example.DataAbility"
);
const valueBucket = {
    "name": "rose",
    "age": 22,
    "salary": 200.5,
    "blobType": u8,
}
DAHelper.insert(
    "dataability:///com.example.DataAbility",
    valueBucket,
    (err, data) => {
		console.info("==========================>Called=======================>");
});
```

## DataShareExtensionAbility.update

update?(uri: string, valueBucket: rdb.ValuesBucket, predicates: dataAbility.DataAbilityPredicates, callback: AsyncCallback\<number>): void

Updates one or more data records in the database. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.DistributedDataManager.DataShare.Provider

**Parameters**

| Name        | Type                             | Mandatory| Description                                            |
| ------------ | --------------------------------- | ---- | ------------------------------------------------ |
| uri          | string                            | Yes  | URI of the data to update.                        |
| valuesBucket | rdb.ValuesBucket                  | Yes  | New data.                              |
| predicates   | dataAbility.DataAbilityPredicates | Yes  | Filter criteria. You should define the processing logic when this parameter is **null**.|
| callback     | AsyncCallback\<number>            | Yes  | Callback used to return the number of updated data records.                |

**Example**

```js
import featureAbility from '@ohos.ability.featureAbility'
import ohos_data_ability from '@ohos.data.dataability'
var DAHelper = featureAbility.acquireDataAbilityHelper(
    "dataability:///com.example.DataAbility"
);
const va = {
    "name": "roe1",
    "age": 21,
    "salary": 20.5,
    "blobType": u8,
}
let da = new ohos_data_ability.DataAbilityPredicates()
DAHelper.update(
    "dataability:///com.example.DataAbility",
    va,
    da,
    (err, data) => {
		console.info("==========================>Called=======================>");
});
```

## DataShareExtensionAbility.delete

delete?(uri: string, predicates: dataAbility.DataAbilityPredicates, callback: AsyncCallback\<number>): void

Deletes one or more data records from the database. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.DistributedDataManager.DataShare.Provider

**Parameters**

| Name        | Type                             | Mandatory| Description                                            |
| ------------ | --------------------------------- | ---- | ------------------------------------------------ |
| uri          | string                            | Yes  | URI of the data to delete.                        |
| valuesBucket | dataAbility.DataAbilityPredicates | Yes  | Filter criteria. You should define the processing logic when this parameter is **null**.|
| callback     | AsyncCallback\<number>            | Yes  | Callback used to return the number of deleted data records.              |

**Example**

```js
import featureAbility from '@ohos.ability.featureAbility'
import ohos_data_ability from '@ohos.data.dataability'
var DAHelper = featureAbility.acquireDataAbilityHelper(
    "dataability:///com.example.DataAbility"
);
let da = new ohos_data_ability.DataAbilityPredicates()
DAHelper.delete(
    "dataability:///com.example.DataAbility",
    da,
    (err, data) => {
		console.info("==========================>Called=======================>");
});
```

## DataShareExtensionAbility.query

query?(uri: string, columns: Array\<string>, predicates: dataAbility.DataAbilityPredicates, callback: AsyncCallback\<ResultSet>): void

Queries data in the database. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.DistributedDataManager.DataShare.Provider

**Parameters**

| Name      | Type                             | Mandatory| Description                                            |
| ---------- | --------------------------------- | ---- | ------------------------------------------------ |
| uri        | string                            | Yes  | URI of the data to query.                        |
| columns    | rdb.ValuesBucket                  | Yes  | Columns to query. If this parameter is **null**, all columns will be queried.  |
| predicates | dataAbility.DataAbilityPredicates | Yes  | Filter criteria. You should define the processing logic when this parameter is **null**.|
| callback   | AsyncCallback\<ResultSet>         | Yes  | Callback used to return the query result.                        |

**Example**

```js
import featureAbility from '@ohos.ability.featureAbility'
import ohos_data_ability from '@ohos.data.dataability'
var DAHelper = featureAbility.acquireDataAbilityHelper(
    "dataability:///com.example.DataAbility"
);
var cars=new Array("value1", "value2", "value3", "value4");
let da = new ohos_data_ability.DataAbilityPredicates()
DAHelper.query(
    "dataability:///com.example.DataAbility",
    cars,
    da,
    (err, data) => {
		console.info("==========================>Called=======================>");
});
```

## DataShareExtensionAbility.getType

getType?(uri: string, callback: AsyncCallback\<string>): void

Obtains the MIME type of the data specified by a given URI. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.DistributedDataManager.DataShare.Provider

**Parameters**

| Name    | Type                  | Mandatory| Description                                         |
| -------- | ---------------------- | ---- | --------------------------------------------- |
| uri      | string                 | Yes  | URI of the data.                     |
| callback | AsyncCallback\<string> | Yes  | Callback used to return the MIME type.|

**Example**

```js
import featureAbility from '@ohos.ability.featureAbility'
var DAHelper = featureAbility.acquireDataAbilityHelper(
    "dataability:///com.example.DataAbility"
);
DAHelper.getType(
    "dataability:///com.example.DataAbility",
    (err, data) => {
		console.info("==========================>Called=======================>");
});
```

## DataShareExtensionAbility.batchInsert

batchInsert?(uri: string, valueBuckets: Array<rdb.ValuesBucket>, callback: AsyncCallback\<number>): void

Inserts multiple data records into the database. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.DistributedDataManager.DataShare.Provider

**Parameters**

| Name        | Type                   | Mandatory| Description                            |
| ------------ | ----------------------- | ---- | -------------------------------- |
| uri          | string                  | Yes  | URI of the data to insert.        |
| valuesBucket | Array<rdb.ValuesBucket> | Yes  | Data record to insert.          |
| callback     | AsyncCallback\<number>  | Yes  | Callback used to return the number of inserted data records.|

**Example**

```js
import featureAbility from '@ohos.ability.featureAbility'
var DAHelper = featureAbility.acquireDataAbilityHelper(
    "dataability:///com.example.DataAbility"
);
var cars = new Array({"name": "roe11", "age": 21, "salary": 20.5, "blobType": u8,},
                     {"name": "roe12", "age": 21, "salary": 20.5, "blobType": u8,},
                     {"name": "roe13", "age": 21, "salary": 20.5, "blobType": u8,})
DAHelper.batchInsert(
    "dataability:///com.example.DataAbility",
    cars,
    (err, data) => {
		console.info("==========================>Called=======================>");
});
```

## DataShareExtensionAbility.normalizeUri

normalizeUri?(uri: string, callback: AsyncCallback\<string>): void

Converts the URI that refers to the Data ability into a normalized URI. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.DistributedDataManager.DataShare.Provider

**Parameters**

| Name    | Type                  | Mandatory| Description                                                        |
| -------- | ---------------------- | ---- | ------------------------------------------------------------ |
| uri      | string                 | Yes  | URI object to normalize.                                     |
| callback | AsyncCallback\<string> | Yes  | Callback used to return the normalized URI object if the Data ability supports URI normalization. If the Data ability does not support URI normalization, **null** is returned.|

**Example**

```js
import featureAbility from '@ohos.ability.featureAbility'
var DAHelper = featureAbility.acquireDataAbilityHelper(
    "dataability:///com.example.DataAbility"
);
DAHelper.normalizeUri(
    "dataability:///com.example.DataAbility",
    (err, data) => {
		console.info("==========================>Called=======================>");
});
```

## DataShareExtensionAbility.denormalizeUri

denormalizeUri?(uri: string, callback: AsyncCallback\<string>): void

Converts a normalized URI generated by **normalizeUri** to a denormalized one. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.DistributedDataManager.DataShare.Provider

**Parameters**

| Name    | Type                  | Mandatory| Description                                               |
| -------- | ---------------------- | ---- | --------------------------------------------------- |
| uri      | string                 | Yes  | URI object to denormalize.                            |
| callback | AsyncCallback\<string> | Yes  | Callback used to return the denormalized URI object.|

**Example**

```js
import featureAbility from '@ohos.ability.featureAbility'
var DAHelper = featureAbility.acquireDataAbilityHelper(
    "dataability:///com.example.DataAbility"
);
DAHelper.denormalizeUri(
    "dataability:///com.example.DataAbility",
    (err, data) => {
		console.info("==========================>Called=======================>");
});
```
