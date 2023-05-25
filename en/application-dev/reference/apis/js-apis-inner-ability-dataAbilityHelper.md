# DataAbilityHelper

The **DataAbilityHelper** object is obtained through [acquireDataAbilityHelper](js-apis-ability-featureAbility.md#featureabilityacquiredataabilityhelper7).

> **NOTE**
> 
> The initial APIs of this module are supported since API version 7. Newly added APIs will be marked with a superscript to indicate their earliest API version. 
> The APIs of this module can be used only in the FA model.

## Modules to Import

```ts
import ability from '@ohos.ability.ability';
```

## Usage

Import the following modules based on the actual situation before using the current module:
```ts
import ohos_data_ability from '@ohos.data.dataAbility';
import ohos_data_rdb from '@ohos.data.rdb';
```

## DataAbilityHelper.openFile

openFile(uri: string, mode: string, callback: AsyncCallback\<number>): void

Opens a file with a specified URI. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.FAModel

**Parameters**

| Name    | Type                  | Mandatory| Description                              |
| -------- | ---------------------- | ---- | ---------------------------------- |
| uri      | string                 | Yes  | URI of the file to open.          |
| mode     | string                 | Yes  | Mode for opening the file. The value can be **rwt**.           |
| callback | AsyncCallback\<number> | Yes  | Callback used to return the file descriptor.|

**Example**

```ts
import featureAbility from '@ohos.ability.featureAbility';
let DAHelper: ability.DataAbilityHelper = featureAbility.acquireDataAbilityHelper(
    'dataability:///com.example.DataAbility'
);
let mode = 'rwt';
DAHelper.openFile('dataability:///com.example.DataAbility', mode, (err) => {
    console.info('==========================>Called=======================>');
});
```

## DataAbilityHelper.openFile

openFile(uri: string, mode: string): Promise\<number>

Opens a file with a specified URI. This API uses a promise to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.FAModel

**Parameters**

| Name| Type  | Mandatory| Description                    |
| ---- | ------ | ---- | ------------------------ |
| uri  | string | Yes  | URI of the file to open.|
| mode | string | Yes  | Mode for opening the file. The value can be **rwt**. |

**Return value**

| Type            | Description            |
| ---------------- | ---------------- |
| Promise\<number> | Promise used to return the file descriptor.|

**Example**

```ts
import featureAbility from '@ohos.ability.featureAbility';
let DAHelper: ability.DataAbilityHelper = featureAbility.acquireDataAbilityHelper(
    'dataability:///com.example.DataAbility'
);
let mode = 'rwt';
DAHelper.openFile('dataability:///com.example.DataAbility', mode).then((data) => {
	console.info('==========================>openFileCallback=======================>');
});
```

## DataAbilityHelper.on

on(type: 'dataChange', uri: string, callback: AsyncCallback\<void>): void

Registers an observer to listen for changes in the data specified by a given URI.

**System capability**: SystemCapability.Ability.AbilityRuntime.FAModel

**Parameters**

| Name    | Type                | Mandatory| Description                    |
| -------- | -------------------- | ---- | ------------------------ |
| type     | string               | Yes  | Event type. The value is **dataChange**.              |
| uri      | string               | Yes  | URI of the data.|
| callback | AsyncCallback\<void> | Yes  | Callback invoked when the data is changed.  |

**Example**

```ts
import featureAbility from '@ohos.ability.featureAbility';
let DAHelper: ability.DataAbilityHelper = featureAbility.acquireDataAbilityHelper(
    'dataability:///com.example.DataAbility'
);
function onChangeNotify() {
    console.info('==========================>onChangeNotify=======================>');
};
DAHelper.on(
    'dataChange',
    'dataability:///com.example.DataAbility',
    onChangeNotify
);
```

## DataAbilityHelper.off

off(type: 'dataChange', uri: string, callback?: AsyncCallback\<void>): void

Deregisters the observer that listens for changes in the data specified by a given URI.

**System capability**: SystemCapability.Ability.AbilityRuntime.FAModel

**Parameters**

| Name    | Type                | Mandatory| Description                    |
| -------- | -------------------- | ---- | ------------------------ |
| type     | string               | Yes  | Event type. The value is **dataChange**.              |
| uri      | string               | Yes  | URI of the data.|
| callback | AsyncCallback\<void> | No  | Callback used to return the result.      |

**Example**

```ts
import featureAbility from '@ohos.ability.featureAbility';
let DAHelper: ability.DataAbilityHelper = featureAbility.acquireDataAbilityHelper(
    'dataability:///com.example.DataAbility'
);
function onChangeNotify() {
    console.info('==========================>onChangeNotify=======================>');
};
DAHelper.off(
    'dataChange',
    'dataability:///com.example.DataAbility',
);
DAHelper.off(
    'dataChange',
    'dataability:///com.example.DataAbility',
    onChangeNotify
);
```

## DataAbilityHelper.getType

getType(uri: string, callback: AsyncCallback\<string>): void

Obtains the MIME type of the data specified by a given URI. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.FAModel

**Parameters**

| Name    | Type                  | Mandatory| Description                                         |
| -------- | ---------------------- | ---- | --------------------------------------------- |
| uri      | string                 | Yes  | URI of the data.                     |
| callback | AsyncCallback\<string> | Yes  | Callback used to return the MIME type.|

**Example**

```ts
import featureAbility from '@ohos.ability.featureAbility';
let DAHelper: ability.DataAbilityHelper = featureAbility.acquireDataAbilityHelper(
    'dataability:///com.example.DataAbility'
);
DAHelper.getType('dataability:///com.example.DataAbility', (err, data) => {
    console.info('==========================>Called=======================>');
});
```

## DataAbilityHelper.getType

getType(uri: string): Promise\<string>

Obtains the MIME type of the data specified by a given URI. This API uses a promise to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.FAModel

**Parameters**

| Name| Type  | Mandatory| Description                    |
| ---- | ------ | ---- | ------------------------ |
| uri  | string | Yes  | URI of the data.|

**Return value**

| Type            | Description                               |
| ---------------- | ----------------------------------- |
| Promise\<string> | Promise used to return the MIME type.|

**Example**

```ts
import featureAbility from '@ohos.ability.featureAbility';
let DAHelper: ability.DataAbilityHelper = featureAbility.acquireDataAbilityHelper(
    'dataability:///com.example.DataAbility'
);
DAHelper.getType('dataability:///com.example.DataAbility').then((data) => {
	console.info('==========================>getTypeCallback=======================>');
});
```

## DataAbilityHelper.getFileTypes

getFileTypes(uri: string, mimeTypeFilter: string, callback: AsyncCallback<Array\<string>>): void

Obtains the supported MIME types of a specified file. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.FAModel

**Parameters**

| Name          | Type                          | Mandatory| Description                              |
| -------------- | ------------------------------ | ---- | ---------------------------------- |
| uri            | string                         | Yes  | URI of the file.          |
| mimeTypeFilter | string                         | Yes  | MIME types to match.      |
| callback       | AsyncCallback\<Array\<string>> | Yes  | Callback used to return the supported MIME types.|

**Example**

```ts
import featureAbility from '@ohos.ability.featureAbility';
let DAHelper: ability.DataAbilityHelper = featureAbility.acquireDataAbilityHelper(
    'dataability:///com.example.DataAbility'
);
DAHelper.getFileTypes( 'dataability:///com.example.DataAbility',
    'image/*', (err, data) => {
    console.info('==========================>Called=======================>');
});
```



## DataAbilityHelper.getFileTypes

getFileTypes(uri: string, mimeTypeFilter: string): Promise\<Array\<string>>

Obtains the supported MIME types of a specified file. This API uses a promise to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.FAModel

**Parameters**

| Name          | Type  | Mandatory| Description                        |
| -------------- | ------ | ---- | ---------------------------- |
| uri            | string | Yes  | URI of the file.    |
| mimeTypeFilter | string | Yes  | MIME types to match.|

**Return value**

| Type                    | Description                    |
| ------------------------ | ------------------------ |
| Promise\<Array\<string>> | Promise used to return the supported MIME types.|

**Example**

```ts
import featureAbility from '@ohos.ability.featureAbility';
let DAHelper: ability.DataAbilityHelper = featureAbility.acquireDataAbilityHelper(
    'dataability:///com.example.DataAbility'
);
DAHelper.getFileTypes('dataability:///com.example.DataAbility',
    'image/*').then((data) => {
     console.info('===================>getFileTypesCallback================>');
});
```

## DataAbilityHelper.normalizeUri

normalizeUri(uri: string, callback: AsyncCallback\<string>): void

Converts the URI that refers to a DataAbility into a normalized URI. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.FAModel

**Parameters**

| Name    | Type                  | Mandatory| Description                                                        |
| -------- | ---------------------- | ---- | ------------------------------------------------------------ |
| uri      | string                 | Yes  | URI object to normalize.                                     |
| callback | AsyncCallback\<string> | Yes  | Callback used to return the normalized URI object if the DataAbility supports URI normalization. If the DataAbility does not support URI normalization, **null** is returned.|

**Example**

```ts
import featureAbility from '@ohos.ability.featureAbility';
let DAHelper: ability.DataAbilityHelper = featureAbility.acquireDataAbilityHelper(
    'dataability:///com.example.DataAbility'
);
DAHelper.normalizeUri('dataability:///com.example.DataAbility', (err, data) => {
    console.info('==========================>Called=======================>');
});
```

## DataAbilityHelper.normalizeUri

normalizeUri(uri: string): Promise\<string>

Converts the URI that refers to a DataAbility into a normalized URI. This API uses a promise to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.FAModel

**Parameters**

| Name| Type  | Mandatory| Description                   |
| ---- | ------ | ---- | ----------------------- |
| uri  | string | Yes  | URI object to normalize.|

**Return value**

| Type            | Description                                                  |
| ---------------- | ------------------------------------------------------ |
| Promise\<string> | Promise used to return the normalized URI object if the DataAbility supports URI normalization. If the DataAbility does not support URI normalization, **null** is returned.|

**Example**

```ts
import featureAbility from '@ohos.ability.featureAbility';
let DAHelper: ability.DataAbilityHelper = featureAbility.acquireDataAbilityHelper(
    'dataability:///com.example.DataAbility'
);
DAHelper.normalizeUri('dataability:///com.example.DataAbility',).then((data) => {
    console.info('=================>normalizeUriCallback=======================>');
});
```

## DataAbilityHelper.denormalizeUri

denormalizeUri(uri: string, callback: AsyncCallback\<string>): void

Converts a normalized URI generated by **DataAbilityHelper.normalizeUri(uri: string, callback: AsyncCallback\<string>)** to a denormalized one. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.FAModel

**Parameters**

| Name    | Type                  | Mandatory| Description                                               |
| -------- | ---------------------- | ---- | --------------------------------------------------- |
| uri      | string                 | Yes  | URI object to normalize.                            |
| callback | AsyncCallback\<string> | Yes  | Callback used to return the denormalized URI object.|

**Example**

```ts
import featureAbility from '@ohos.ability.featureAbility';
let DAHelper: ability.DataAbilityHelper = featureAbility.acquireDataAbilityHelper(
    'dataability:///com.example.DataAbility'
);
DAHelper.denormalizeUri('dataability:///com.example.DataAbility', (err, data) => {
    console.info('==========================>Called=======================>');
});
```



## DataAbilityHelper.denormalizeUri

denormalizeUri(uri: string): Promise\<string>

Converts a normalized URI generated by **DataAbilityHelper.normalizeUri(uri: string)** to a denormalized one. This API uses a promise to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.FAModel

**Parameters**

| Name| Type  | Mandatory| Description                   |
| ---- | ------ | ---- | ----------------------- |
| uri  | string | Yes  | URI object to normalize.|

**Return value**

| Type            | Description                                     |
| ---------------- | ----------------------------------------- |
| Promise\<string> | Promise used to return the denormalized URI object.|

**Example**

```ts
import featureAbility from '@ohos.ability.featureAbility';
let DAHelper: ability.DataAbilityHelper = featureAbility.acquireDataAbilityHelper(
    'dataability:///com.example.DataAbility'
);
DAHelper.denormalizeUri('dataability:///com.example.DataAbility',).then((data) => {
    console.info('===============>denormalizeUriCallback=======================>');
});
```

## DataAbilityHelper.notifyChange

notifyChange(uri: string, callback: AsyncCallback\<void>): void

Notifies the registered observer of a change to the data specified by the URI. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.FAModel

**Parameters**

| Name    | Type                | Mandatory| Description                    |
| -------- | -------------------- | ---- | ------------------------ |
| uri      | string               | Yes  | URI of the data.|
| callback | AsyncCallback\<void> | Yes  | Callback used to return the result.              |

**Example**

```ts
import featureAbility from '@ohos.ability.featureAbility';
let DAHelper: ability.DataAbilityHelper = featureAbility.acquireDataAbilityHelper(
    'dataability:///com.example.DataAbility'
);
DAHelper.notifyChange('dataability:///com.example.DataAbility', (err) => {
    console.info('==========================>Called=======================>');
});
```

## DataAbilityHelper.notifyChange

notifyChange(uri: string): Promise\<void>

Notifies the registered observer of a change to the data specified by the URI. This API uses a promise to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.FAModel

**Parameters**

| Name| Type  | Mandatory| Description                    |
| ---- | ------ | ---- | ------------------------ |
| uri  | string | Yes  | URI of the data.|

**Return value**

| Type          | Description                 |
| -------------- | --------------------- |
| Promise\<void> | Promise used to return the result.|

**Example**

```ts
import featureAbility from '@ohos.ability.featureAbility';
let DAHelper: ability.DataAbilityHelper = featureAbility.acquireDataAbilityHelper(
    'dataability:///com.example.DataAbility'
);
DAHelper.notifyChange('dataability:///com.example.DataAbility').then(() => {
    console.info('================>notifyChangeCallback================>');
});
```

## DataAbilityHelper.insert

insert(uri: string, valuesBucket: rdb.ValuesBucket, callback: AsyncCallback\<number>): void

Inserts a single data record into the database. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.FAModel

**Parameters**

| Name        | Type                  | Mandatory| Description                                                  |
| ------------ | ---------------------- | ---- | ------------------------------------------------------ |
| uri          | string                 | Yes  | URI of the data to insert.                              |
| valuesBucket | rdb.ValuesBucket       | Yes  | Data record to insert. If this parameter is **null**, a blank row will be inserted.|
| callback     | AsyncCallback\<number> | Yes  | Callback used to return the index of the inserted data record.                    |

**Example**

```ts
import featureAbility from '@ohos.ability.featureAbility';
let DAHelper: ability.DataAbilityHelper = featureAbility.acquireDataAbilityHelper(
    'dataability:///com.example.DataAbility'
);
const valueBucket = {
    'name': 'rose',
    'age': 22,
    'salary': 200.5,
    'blobType': 'u8',
};
DAHelper.insert('dataability:///com.example.DataAbility', valueBucket,
    (err, data) => {
    console.info('==========================>Called=======================>');
});
```

## DataAbilityHelper.insert

insert(uri: string, valuesBucket: rdb.ValuesBucket): Promise\<number>

Inserts a single data record into the database. This API uses a promise to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.FAModel

**Parameters**

| Name        | Type            | Mandatory| Description                                                  |
| ------------ | ---------------- | ---- | ------------------------------------------------------ |
| uri          | string           | Yes  | URI of the data to insert.                              |
| valuesBucket | rdb.ValuesBucket | Yes  | Data record to insert. If this parameter is **null**, a blank row will be inserted.|

**Return value**

| Type            | Description                    |
| ---------------- | ------------------------ |
| Promise\<number> | Promise used to return the index of the inserted data record.|

**Example**

```ts
import featureAbility from '@ohos.ability.featureAbility';
let DAHelper: ability.DataAbilityHelper = featureAbility.acquireDataAbilityHelper(
    'dataability:///com.example.DataAbility'
);
const valueBucket = {
    'name': 'rose1',
    'age': 221,
    'salary': 20.5,
    'blobType': 'u8',
};
DAHelper.insert('dataability:///com.example.DataAbility', valueBucket).then((data) => {
    console.info('====================>insertCallback=======================>');
});
```

## DataAbilityHelper.batchInsert

batchInsert(uri: string, valuesBuckets: Array\<rdb.ValuesBucket>, callback: AsyncCallback\<number>): void

Inserts multiple data records into the database. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.FAModel

**Parameters**

| Name        | Type                   | Mandatory| Description                            |
| ------------ | ----------------------- | ---- | -------------------------------- |
| uri          | string                  | Yes  | URI of the data to insert.        |
| valuesBucket | Array\<rdb.ValuesBucket> | Yes  | Data record to insert.          |
| callback     | AsyncCallback\<number>  | Yes  | Callback used to return the number of inserted data records.|

**Example**

```ts
import featureAbility from '@ohos.ability.featureAbility';
let DAHelper: ability.DataAbilityHelper = featureAbility.acquireDataAbilityHelper(
    'dataability:///com.example.DataAbility'
);
let cars = new Array({'name': 'roe11', 'age': 21, 'salary': 20.5, 'blobType': 'u8',},
                     {'name': 'roe12', 'age': 21, 'salary': 20.5, 'blobType': 'u8',},
                     {'name': 'roe13', 'age': 21, 'salary': 20.5, 'blobType': 'u8',});
DAHelper.batchInsert('dataability:///com.example.DataAbility', cars,
    (err, data) => {
    console.info('==========================>Called=======================>');
});
```

## DataAbilityHelper.batchInsert

batchInsert(uri: string, valuesBuckets: Array<rdb.ValuesBucket>): Promise\<number>

Inserts multiple data records into the database. This API uses a promise to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.FAModel

**Parameters**

| Name        | Type                   | Mandatory| Description                    |
| ------------ | ----------------------- | ---- | ------------------------ |
| uri          | string                  | Yes  | URI of the data to insert.|
| valuesBucket | Array<rdb.ValuesBucket> | Yes  | Data record to insert.  |

**Return value**

| Type            | Description                  |
| ---------------- | ---------------------- |
| Promise\<number> | Promise used to return the number of inserted data records.|

**Example**

```ts
import featureAbility from '@ohos.ability.featureAbility';
let DAHelper: ability.DataAbilityHelper = featureAbility.acquireDataAbilityHelper(
    'dataability:///com.example.DataAbility'
);
let cars = new Array({'name': 'roe11', 'age': 21, 'salary': 20.5, 'blobType': 'u8',},
                     {'name': 'roe12', 'age': 21, 'salary': 20.5, 'blobType': 'u8',},
                     {'name': 'roe13', 'age': 21, 'salary': 20.5, 'blobType': 'u8',});
DAHelper.batchInsert('dataability:///com.example.DataAbility', cars).then((data) => {
    console.info('==================>batchInsertCallback=======================>');
});
```

## DataAbilityHelper.delete

delete(uri: string, predicates: dataAbility.DataAbilityPredicates, callback: AsyncCallback\<number>): void

Deletes one or more data records from the database. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.FAModel

**Parameters**

| Name        | Type                             | Mandatory| Description                                            |
| ------------ | --------------------------------- | ---- | ------------------------------------------------ |
| uri          | string                            | Yes  | URI of the data to delete.                        |
| predicates | dataAbility.DataAbilityPredicates | Yes  | Filter criteria. You should define the processing logic when this parameter is **null**.|
| callback     | AsyncCallback\<number>            | Yes  | Callback used to return the number of deleted data records.              |

**Example**

```ts
import featureAbility from '@ohos.ability.featureAbility';
import ohos_data_ability from '@ohos.data.dataAbility';
let DAHelper: ability.DataAbilityHelper = featureAbility.acquireDataAbilityHelper(
    'dataability:///com.example.DataAbility'
);
let da = new ohos_data_ability.DataAbilityPredicates();
DAHelper.delete('dataability:///com.example.DataAbility', da,
    (err, data) => {
    console.info('==========================>Called=======================>');
});
```

## DataAbilityHelper.delete

delete(uri: string, predicates?: dataAbility.DataAbilityPredicates): Promise\<number>;

Deletes one or more data records from the database. This API uses a promise to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.FAModel

**Parameters**

| Name        | Type                             | Mandatory| Description                                            |
| ------------ | --------------------------------- | ---- | ------------------------------------------------ |
| uri          | string                            | Yes  | URI of the data to delete.                        |
| predicates | dataAbility.DataAbilityPredicates | No  | Filter criteria. You should define the processing logic when this parameter is **null**.|

**Return value**

| Type            | Description                    |
| ---------------- | ------------------------ |
| Promise\<number> | Promise used to return the number of deleted data records.|

**Example**

```ts
import featureAbility from '@ohos.ability.featureAbility';
import ohos_data_ability from '@ohos.data.dataAbility';
let DAHelper: ability.DataAbilityHelper = featureAbility.acquireDataAbilityHelper(
    'dataability:///com.example.DataAbility'
);
let da = new ohos_data_ability.DataAbilityPredicates();
DAHelper.delete('dataability:///com.example.DataAbility', da).then((data) => {
    console.info('==========================>deleteCallback=======================>');
});
```

## DataAbilityHelper.update

update(uri: string, valuesBucket: rdb.ValuesBucket, predicates: dataAbility.DataAbilityPredicates, callback: AsyncCallback\<number>): void

Updates data records in the database. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.FAModel

**Parameters**

| Name        | Type                             | Mandatory| Description                                            |
| ------------ | --------------------------------- | ---- | ------------------------------------------------ |
| uri          | string                            | Yes  | URI of the data to update.                        |
| valuesBucket | rdb.ValuesBucket                  | Yes  | New values.                              |
| predicates   | dataAbility.DataAbilityPredicates | Yes  | Filter criteria. You should define the processing logic when this parameter is **null**.|
| callback     | AsyncCallback\<number>            | Yes  | Callback used to return the number of updated data records.                |

**Example**

```ts
import featureAbility from '@ohos.ability.featureAbility';
import ohos_data_ability from '@ohos.data.dataAbility';
let DAHelper: ability.DataAbilityHelper = featureAbility.acquireDataAbilityHelper(
    'dataability:///com.example.DataAbility'
);
const va = {
    'name': 'roe1',
    'age': 21,
    'salary': 20.5,
    'blobType': 'u8',
};
let da = new ohos_data_ability.DataAbilityPredicates();
DAHelper.update('dataability:///com.example.DataAbility', va, da, (err, data) => {
    console.info('==========================>Called=======================>');
});
```

## DataAbilityHelper.update

update(uri: string, valuesBucket: rdb.ValuesBucket, predicates?: dataAbility.DataAbilityPredicates): Promise\<number>;

Updates data records in the database. This API uses a promise to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.FAModel

**Parameters**

| Name        | Type                             | Mandatory| Description                                            |
| ------------ | --------------------------------- | ---- | ------------------------------------------------ |
| uri          | string                            | Yes  | URI of the data to update.                        |
| valuesBucket | rdb.ValuesBucket                  | Yes  | New values.                              |
| predicates   | dataAbility.DataAbilityPredicates | No  | Filter criteria. You should define the processing logic when this parameter is **null**.|

**Return value**

| Type            | Description                                        |
| ---------------- | -------------------------------------------- |
| Promise\<number> | Promise used to return the number of updated data records.  |

**Example**

```ts
import featureAbility from '@ohos.ability.featureAbility';
import ohos_data_ability from '@ohos.data.dataAbility';
let DAHelper: ability.DataAbilityHelper = featureAbility.acquireDataAbilityHelper(
    'dataability:///com.example.DataAbility'
);
const va = {
    'name': 'roe1',
    'age': 21,
    'salary': 20.5,
    'blobType': 'u8',
};
let da = new ohos_data_ability.DataAbilityPredicates();
DAHelper.update('dataability:///com.example.DataAbility', va, da).then((data) => {
    console.info('==========================>updateCallback=======================>');
});
```

## DataAbilityHelper.query

query(uri: string, columns: Array\<string>, predicates: dataAbility.DataAbilityPredicates, callback: AsyncCallback\<ResultSet>): void

Queries data in the database. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.FAModel

**Parameters**

| Name      | Type                             | Mandatory| Description                                            |
| ---------- | --------------------------------- | ---- | ------------------------------------------------ |
| uri        | string                            | Yes  | URI of the data to query.                        |
| columns    | Array\<string>                | Yes  | Columns to query. If this parameter is **null**, all columns will be queried.  |
| predicates | dataAbility.DataAbilityPredicates | Yes  | Filter criteria. You should define the processing logic when this parameter is **null**.|
| callback   | AsyncCallback\<ResultSet>         | Yes  | Callback used to return the data queried.                        |

**Example**

```ts
import featureAbility from '@ohos.ability.featureAbility';
import ohos_data_ability from '@ohos.data.dataAbility';
let DAHelper: ability.DataAbilityHelper = featureAbility.acquireDataAbilityHelper(
    'dataability:///com.example.DataAbility'
);
let cars=new Array('value1', 'value2', 'value3', 'value4');
let da = new ohos_data_ability.DataAbilityPredicates();
DAHelper.query('dataability:///com.example.DataAbility', cars, da, (err, data) => {
    console.info('==========================>Called=======================>');
});
```



## DataAbilityHelper.query

query(uri: string, columns?: Array\<string>, predicates?: dataAbility.DataAbilityPredicates): Promise\<ResultSet>;

Queries data in the database. This API uses a promise to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.FAModel

**Parameters**

| Name      | Type                             | Mandatory| Description                                            |
| ---------- | --------------------------------- | ---- | ------------------------------------------------ |
| uri        | string                            | Yes  | URI of the data to query.                        |
| columns    | Array\<string>               | No  | Columns to query. If this parameter is **null**, all columns will be queried.  |
| predicates | dataAbility.DataAbilityPredicates | No  | Filter criteria. You should define the processing logic when this parameter is **null**.|

**Return value**

| Type               | Description          |
| ------------------- | -------------- |
| Promise\<ResultSet> | Promise used to return the data queried.|

**Example**

```ts
import featureAbility from '@ohos.ability.featureAbility';
import ohos_data_ability from '@ohos.data.dataAbility';
let DAHelper: ability.DataAbilityHelper = featureAbility.acquireDataAbilityHelper(
    'dataability:///com.example.DataAbility'
);
let cars = new Array('value1', 'value2', 'value3', 'value4');
let da = new ohos_data_ability.DataAbilityPredicates();
DAHelper.query('dataability:///com.example.DataAbility', cars, da).then((data) => {
    console.info('query data: ${JSON.stringify(data)}');
});
```

## DataAbilityHelper.call

call(uri: string, method: string, arg: string, extras: PacMap, callback: AsyncCallback\<PacMap>): void

Calls an extended API of the DataAbility. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.FAModel

**Parameters**

| Name      | Type                             | Mandatory| Description                                            |
| ---------- | --------------------------------- | ---- | ------------------------------------------------ |
| uri        | string                 | Yes  | URI of the DataAbility. Example: 'dataability:///com.example.xxx.xxxx'.          |
| method    | string                  | Yes  | Name of the API to call.  |
| arg      | string                   | Yes  | Parameter to pass in.     |
| extras   | [PacMap](#pacmap)        | Yes  | Key-value pair parameter.      |
| callback | AsyncCallback\<[PacMap](#pacmap)> | Yes| Callback used to return the result.    |

**Example**

```ts
import featureAbility from '@ohos.ability.featureAbility';

let dataAbilityHelper: ability.DataAbilityHelper = featureAbility.acquireDataAbilityHelper(
    'dataability:///com.example.jsapidemo.UserDataAbility'
);
dataAbilityHelper.call('dataability:///com.example.jsapidemo.UserDataAbility',
    'method', 'arg', {'key1':'value1'}, (error, data) => {
    if (error && error.code !== 0) {
        console.error('call fail, error: ${JSON.stringify(error)}');
    } else {
        console.log('call success, data: ${JSON.stringify(data)}');
    }
});
```

## DataAbilityHelper.call

call(uri: string, method: string, arg: string, extras: PacMap): Promise\<PacMap>

Calls an extended API of the DataAbility. This API uses a promise to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.FAModel

**Parameters**

| Name      | Type                             | Mandatory| Description                                            |
| ---------- | --------------------------------- | ---- | ------------------------------------------------ |
| uri        | string                 | Yes  | URI of the DataAbility. Example: 'dataability:///com.example.xxx.xxxx'.          |
| method    | string                  | Yes  | Name of the API to call.  |
| arg      | string                   | Yes  |Parameter to pass in.     |
| extras   | [PacMap](#pacmap)        | Yes  | Key-value pair parameter.      |

**Return value**

| Type| Description|
|------ | ------- |
|Promise\<[PacMap](#pacmap)> | Promise used to return the result.|

**Example**

```ts
import featureAbility from '@ohos.ability.featureAbility';

let dataAbilityHelper: ability.DataAbilityHelper = featureAbility.acquireDataAbilityHelper(
    'dataability:///com.example.jsapidemo.UserDataAbility'
);
dataAbilityHelper.call('dataability:///com.example.jsapidemo.UserDataAbility',
    'method', 'arg', {'key1':'value1'}).then((data) => {
    console.info('Operation succeeded: ' + data);
}).catch((error) => {
    console.error('Operation failed. Cause: ' + error);
});
```

## DataAbilityHelper.call

call(uri: string, method: string, arg: string, extras: PacMap, callback: AsyncCallback\<PacMap>): void

Calls an extended API of the DataAbility. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.FAModel

**Parameters**

| Name      | Type                             | Mandatory| Description                                            |
| ---------- | --------------------------------- | ---- | ------------------------------------------------ |
| uri        | string                 | Yes  | URI of the DataAbility. Example: 'dataability:///com.example.xxx.xxxx'.          |
| method    | string                  | Yes  | Name of the API to call.  |
| arg      | string                   | Yes  |Parameter to pass in.     |
| extras   | [PacMap](#pacmap)        | Yes  | Key-value pair parameter.      |
| callback | AsyncCallback\<[PacMap](#pacmap)> | Yes| Callback used to return the result.    |

**Example**

```ts
import featureAbility from '@ohos.ability.featureAbility';

let dataAbilityHelper = featureAbility.acquireDataAbilityHelper(
    'dataability:///com.example.jsapidemo.UserDataAbility');
dataAbilityHelper.call('dataability:///com.example.jsapidemo.UserDataAbility',
    'method', 'arg', {'key1':'value1'}, (err, data) => {
    if (err) {
        console.error('Operation failed. Cause: ' + err);
        return;
    }
    console.info('Operation succeeded: ' + data);
});
```

## DataAbilityHelper.executeBatch

executeBatch(uri: string, operations: Array\<DataAbilityOperation>, callback: AsyncCallback\<Array\<DataAbilityResult>>): void;

Operates data in the database in batches. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.FAModel

**Parameters**

| Name           | Type                                        | Mandatory| Description                                            |
| ----------    | ---------------------------------             | ---- | ------------------------------------------------ |
| uri           | string                                        | Yes  | URI of the DataAbility. Example: 'dataability:///com.example.xxx.xxxx'.|
| operations    |  Array\<[DataAbilityOperation](js-apis-inner-ability-dataAbilityOperation.md)>               | Yes  | An array holding the data operations on the database.  |
| callback      |  AsyncCallback\<Array\<[DataAbilityResult](js-apis-inner-ability-dataAbilityResult.md)>>    | Yes  | Callback used to return the result of each operation in the **DataAbilityResult** array.     |

**Example**

```ts
import featureAbility from '@ohos.ability.featureAbility';

// Select the operations to be performed on the database according to the DataAbilityOperation array.
let op=new Array();
let dataAbilityHelper: ability.DataAbilityHelper = featureAbility.acquireDataAbilityHelper(
    'dataability:///com.example.jsapidemo.UserDataAbility'
);
dataAbilityHelper.executeBatch('dataability:///com.example.jsapidemo.UserDataAbility', op, (error, data) => {
    if (error && error.code !== 0) {
        console.error('executeBatch fail, error: ${JSON.stringify(error)}');
    } else {
        console.log('executeBatch success, data: ${JSON.stringify(data)}');
    }
    console.info('Operation succeeded: ' + data);
});
```

## DataAbilityHelper.executeBatch

executeBatch(uri: string, operations: Array\<DataAbilityOperation>): Promise\<Array\<DataAbilityResult>>;

Operates data in the database in batches. This API uses a promise to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.FAModel

**Parameters**

| Name         | Type                           | Mandatory| Description                                            |
| ----------    | -------------------------------| ---- | ------------------------------------------------ |
| uri           | string                         | Yes  | URI of the DataAbility. Example: 'dataability:///com.example.xxx.xxxx'.|
| operations    |  Array\<[DataAbilityOperation](js-apis-inner-ability-dataAbilityOperation.md)>  | Yes  | An array holding the data operations on the database.  |

**Return value**

| Type| Description|
|------ | ------- |
|Promise\<Array\<[DataAbilityResult](js-apis-inner-ability-dataAbilityResult.md)>> | Promise used to return the result of each operation in the **DataAbilityResult** array.|

**Example**

```ts
import featureAbility from '@ohos.ability.featureAbility';

// Select the operations to be performed on the database according to the DataAbilityOperation array.
let op=new Array();
let dataAbilityHelper: ability.DataAbilityHelper = featureAbility.acquireDataAbilityHelper(
    'dataability:///com.example.jsapidemo.UserDataAbility'
);
dataAbilityHelper.executeBatch('dataability:///com.example.jsapidemo.UserDataAbility', op).then((data) => {
    console.info('executeBatch success, data: ${data}');
}).catch((error) => {
    console.error('Operation failed. Cause: ' + error);
});

```

## PacMap

[key: string]: number | string | boolean | Array\<string | number | boolean> | null;

**System capability**: SystemCapability.Ability.AbilityRuntime.FAModel

| Name| Type| Mandatory| Description|
| ------ | ------ | ------ | ------ |
| [key: string] | number \| string \| boolean \| Array\<string \| number \| boolean\> \| null | Yes| Data stored in key-value pairs.|
