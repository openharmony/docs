# DataAbilityHelper

The **DataAbilityHelper** object is obtained through [acquireDataAbilityHelper](js-apis-ability-featureAbility.md#featureabilityacquiredataabilityhelper7).

> **NOTE**
> 
> The initial APIs of this module are supported since API version 7. Newly added APIs will be marked with a superscript to indicate their earliest API version. 
> The APIs of this module can be used only in the FA model. In the stage model, use the APIs provided by the [dataAbility](js-apis-data-ability.md) and [dataShare](js-apis-data-dataShare.md) modules instead.

## Modules to Import

```ts
import ability from '@ohos.ability.ability';
```

## Usage

Import the following modules based on the actual situation before using the current module:
```ts
import ohos_data_ability from '@ohos.data.dataAbility';
import relationalStore from '@ohos.data.relationalStore';
```

## DataAbilityHelper.openFile

openFile(uri: string, mode: string, callback: AsyncCallback\<number>): void

Opens a file with a specified URI. This API uses an asynchronous callback to return a file descriptor.

**System capability**: SystemCapability.Ability.AbilityRuntime.FAModel

**Note**: This API can be used only in the FA model. In the stage model, use [FileAccessHelper.openFile](js-apis-fileAccess.md#openfile-1) instead.

**Parameters**

| Name    | Type                  | Mandatory| Description                              |
| -------- | ---------------------- | ---- | ---------------------------------- |
| uri      | string                 | Yes  | URI of the file to open.          |
| mode     | string                 | Yes  | Mode for opening the file. The value **r** indicates read-only access, **w** indicates **write-only** access, and **rw** indicates read-write access.           |
| callback | AsyncCallback\<number> | Yes  | Callback used to return the file descriptor.|

**Example**

```ts
import ability from '@ohos.ability.ability';
import featureAbility from '@ohos.ability.featureAbility';

let DAHelper: ability.DataAbilityHelper = featureAbility.acquireDataAbilityHelper(
    'dataability:///com.example.DataAbility'
);
let mode = 'rw';
DAHelper.openFile('dataability:///com.example.DataAbility', mode, (error, data) => {
    if (error && error.code !== 0) {
        console.error(`openFile fail, error: ${JSON.stringify(error)}`);
    } else {
        console.log(`openFile success, data: ${JSON.stringify(data)}`);
    }
});
```

## DataAbilityHelper.openFile

openFile(uri: string, mode: string): Promise\<number>

Opens a file with a specified URI. This API uses a promise to return a file descriptor.

**System capability**: SystemCapability.Ability.AbilityRuntime.FAModel

**Note**: This API can be used only in the FA model. In the stage model, use [FileAccessHelper.openFile](js-apis-fileAccess.md#openfile) instead.

**Parameters**

| Name| Type  | Mandatory| Description                    |
| ---- | ------ | ---- | ------------------------ |
| uri  | string | Yes  | URI of the file to open.|
| mode | string | Yes  | Mode for opening the file. The value **r** indicates read-only access, **w** indicates **write-only** access, and **rw** indicates read-write access. |

**Return value**

| Type            | Description            |
| ---------------- | ---------------- |
| Promise\<number> | Promise used to return the file descriptor.|

**Example**

```ts
import ability from '@ohos.ability.ability';
import featureAbility from '@ohos.ability.featureAbility';

let DAHelper: ability.DataAbilityHelper = featureAbility.acquireDataAbilityHelper(
    'dataability:///com.example.DataAbility'
);
let mode = 'rw';
DAHelper.openFile('dataability:///com.example.DataAbility', mode).then((data) => {
    console.info(`openFile data: ${JSON.stringify(data)}`);
});
```

## DataAbilityHelper.on

on(type: 'dataChange', uri: string, callback: AsyncCallback\<void>): void

Registers an observer to listen for changes in the data specified by a given URI.

**System capability**: SystemCapability.Ability.AbilityRuntime.FAModel

**Note**: This API can be used only in the FA model. In the stage model, use [DataShareHelper.on('dataChange')](js-apis-data-dataShare.md#ondatachange) instead.

**Parameters**

| Name    | Type                | Mandatory| Description                    |
| -------- | -------------------- | ---- | ------------------------ |
| type     | string               | Yes  | The value **'dataChange'** means data changes.              |
| uri      | string               | Yes  | URI of the data.|
| callback | AsyncCallback\<void> | Yes  | Callback invoked when the data is changed.  |

**Example**

```ts
import ability from '@ohos.ability.ability';
import featureAbility from '@ohos.ability.featureAbility';

let DAHelper: ability.DataAbilityHelper = featureAbility.acquireDataAbilityHelper(
    'dataability:///com.example.DataAbility'
);
function onChangeNotify() {
    console.info('onChangeNotify call back');
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

**Note**: This API can be used only in the FA model. In the stage model, use [DataShareHelper.off('dataChange')](js-apis-data-dataShare.md#offdatachange) instead.

**Parameters**

| Name    | Type                | Mandatory| Description                    |
| -------- | -------------------- | ---- | ------------------------ |
| type     | string               | Yes  | The value **'dataChange'** means data changes.              |
| uri      | string               | Yes  | URI of the data.|
| callback | AsyncCallback\<void> | No  | Callback of the listener to deregister. If the callback is set to **null**, all data change listeners are canceled.      |

**Example**

```ts
import ability from '@ohos.ability.ability';
import featureAbility from '@ohos.ability.featureAbility';

let DAHelper: ability.DataAbilityHelper = featureAbility.acquireDataAbilityHelper(
    'dataability:///com.example.DataAbility'
);
function onChangeNotify() {
    console.info('onChangeNotify call back');
};
DAHelper.off(
    'dataChange',
    'dataability:///com.example.DataAbility',
    onChangeNotify
);
DAHelper.off(
    'dataChange',
    'dataability:///com.example.DataAbility',
);
```

## DataAbilityHelper.getType

getType(uri: string, callback: AsyncCallback\<string>): void

Obtains the media resource type of the data specified by a given URI. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.FAModel

**Parameters**

| Name    | Type                  | Mandatory| Description                                         |
| -------- | ---------------------- | ---- | --------------------------------------------- |
| uri      | string                 | Yes  | URI of the data.                     |
| callback | AsyncCallback\<string> | Yes  | Callback used to return the media resource type.|

**Example**

```ts
import ability from '@ohos.ability.ability';
import featureAbility from '@ohos.ability.featureAbility';

let DAHelper: ability.DataAbilityHelper = featureAbility.acquireDataAbilityHelper(
    'dataability:///com.example.DataAbility'
);
DAHelper.getType('dataability:///com.example.DataAbility', (error, data) => {
    if (error && error.code !== 0) {
        console.error(`getType fail, error: ${JSON.stringify(error)}`);
    } else {
        console.log(`getType success, data: ${JSON.stringify(data)}`);
    }
});
```

## DataAbilityHelper.getType

getType(uri: string): Promise\<string>

Obtains the media resource type of the data specified by a given URI. This API uses a promise to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.FAModel

**Parameters**

| Name| Type  | Mandatory| Description                    |
| ---- | ------ | ---- | ------------------------ |
| uri  | string | Yes  | URI of the data.|

**Return value**

| Type            | Description                               |
| ---------------- | ----------------------------------- |
| Promise\<string> | Promise used to return the media resource type.|

**Example**

```ts
import ability from '@ohos.ability.ability';
import featureAbility from '@ohos.ability.featureAbility';

let DAHelper: ability.DataAbilityHelper = featureAbility.acquireDataAbilityHelper(
    'dataability:///com.example.DataAbility'
);
DAHelper.getType('dataability:///com.example.DataAbility').then((data) => {
    console.info(`getType data: ${JSON.stringify(data)}`);
});
```

## DataAbilityHelper.getFileTypes

getFileTypes(uri: string, mimeTypeFilter: string, callback: AsyncCallback<Array\<string>>): void

Obtains the supported media resource types of a specified file. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.FAModel

**Parameters**

| Name          | Type                          | Mandatory| Description                              |
| -------------- | ------------------------------ | ---- | ---------------------------------- |
| uri            | string                         | Yes  | URI of the file.          |
| mimeTypeFilter | string                         | Yes  | Media resource type of the file to obtain.      |
| callback       | AsyncCallback\<Array\<string>> | Yes  | Callback used to return an array holding the media resource type.|

**Example**

```ts
import ability from '@ohos.ability.ability';
import featureAbility from '@ohos.ability.featureAbility';

let DAHelper: ability.DataAbilityHelper = featureAbility.acquireDataAbilityHelper(
    'dataability:///com.example.DataAbility'
);
DAHelper.getFileTypes( 'dataability:///com.example.DataAbility', 'image/*', (error, data) => {
    if (error && error.code !== 0) {
        console.error(`getFileTypes fail, error: ${JSON.stringify(error)}`);
    } else {
        console.log(`getFileTypes success, data: ${JSON.stringify(data)}`);
    }
});
```

## DataAbilityHelper.getFileTypes

getFileTypes(uri: string, mimeTypeFilter: string): Promise\<Array\<string>>

Obtains the supported media resource types of a specified file. This API uses a promise to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.FAModel

**Parameters**

| Name          | Type  | Mandatory| Description                        |
| -------------- | ------ | ---- | ---------------------------- |
| uri            | string | Yes  | URI of the file.    |
| mimeTypeFilter | string | Yes  | Media resource type of the file to obtain.|

**Return value**

| Type                    | Description                    |
| ------------------------ | ------------------------ |
| Promise\<Array\<string>> | Promise used to return an array holding the media resource type.|

**Example**

```ts
import ability from '@ohos.ability.ability';
import featureAbility from '@ohos.ability.featureAbility';

let DAHelper: ability.DataAbilityHelper = featureAbility.acquireDataAbilityHelper(
    'dataability:///com.example.DataAbility'
);
DAHelper.getFileTypes('dataability:///com.example.DataAbility', 'image/*').then((data) => {
    console.info(`getFileTypes data: ${JSON.stringify(data)}`);
});
```

## DataAbilityHelper.normalizeUri

normalizeUri(uri: string, callback: AsyncCallback\<string>): void

Converts the URI that refers to a Data ability into a normalized URI. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.FAModel

**Note**: This API can be used only in the FA model. In the stage model, use [DataShareHelper.normalizeUri](js-apis-data-dataShare.md#normalizeuri) instead.

**Parameters**

| Name    | Type                  | Mandatory| Description                                                        |
| -------- | ---------------------- | ---- | ------------------------------------------------------------ |
| uri      | string                 | Yes  | URI object to normalize.                                     |
| callback | AsyncCallback\<string> | Yes  | Callback used to return the normalized URI object if the Data ability supports URI normalization. If the Data ability does not support URI normalization, **null** is returned.|

**Example**

```ts
import ability from '@ohos.ability.ability';
import featureAbility from '@ohos.ability.featureAbility';

let DAHelper: ability.DataAbilityHelper = featureAbility.acquireDataAbilityHelper(
    'dataability:///com.example.DataAbility'
);
DAHelper.normalizeUri('dataability:///com.example.DataAbility', (error, data) => {
    if (error && error.code !== 0) {
        console.error(`normalizeUri fail, error: ${JSON.stringify(error)}`);
    } else {
        console.log(`normalizeUri success, data: ${JSON.stringify(data)}`);
    }
});
```

## DataAbilityHelper.normalizeUri

normalizeUri(uri: string): Promise\<string>

Converts the URI that refers to a Data ability into a normalized URI. This API uses a promise to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.FAModel

**Note**: This API can be used only in the FA model. In the stage model, use [DataShareHelper.normalizeUri](js-apis-data-dataShare.md#normalizeuri-1) instead.

**Parameters**

| Name| Type  | Mandatory| Description                   |
| ---- | ------ | ---- | ----------------------- |
| uri  | string | Yes  | URI object to normalize.|

**Return value**

| Type            | Description                                                  |
| ---------------- | ------------------------------------------------------ |
| Promise\<string> | Promise used to return the normalized URI object if the Data ability supports URI normalization. If the Data ability does not support URI normalization, **null** is returned.|

**Example**

```ts
import ability from '@ohos.ability.ability';
import featureAbility from '@ohos.ability.featureAbility';

let DAHelper: ability.DataAbilityHelper = featureAbility.acquireDataAbilityHelper(
    'dataability:///com.example.DataAbility'
);
DAHelper.normalizeUri('dataability:///com.example.DataAbility',).then((data) => {
    console.info(`normalizeUri data: ${JSON.stringify(data)}`);
});
```

## DataAbilityHelper.denormalizeUri

denormalizeUri(uri: string, callback: AsyncCallback\<string>): void

Converts a normalized URI generated by **DataAbilityHelper.normalizeUri(uri: string, callback: AsyncCallback\<string>)** to a denormalized one. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.FAModel

**Note**: This API can be used only in the FA model. In the stage model, use [DataShareHelper.denormalizeUri](js-apis-data-dataShare.md#denormalizeuri) instead.

**Parameters**

| Name    | Type                  | Mandatory| Description                                               |
| -------- | ---------------------- | ---- | --------------------------------------------------- |
| uri      | string                 | Yes  | URI object to denormalize.                            |
| callback | AsyncCallback\<string> | Yes  | Callback used to return the denormalized URI object.|

**Example**

```ts
import ability from '@ohos.ability.ability';
import featureAbility from '@ohos.ability.featureAbility';

let DAHelper: ability.DataAbilityHelper = featureAbility.acquireDataAbilityHelper(
    'dataability:///com.example.DataAbility'
);
DAHelper.denormalizeUri('dataability:///com.example.DataAbility', (error, data) => {
    if (error && error.code !== 0) {
        console.error(`denormalizeUri fail, error: ${JSON.stringify(error)}`);
    } else {
        console.log(`denormalizeUri success, data: ${JSON.stringify(data)}`);
    }
});
```

## DataAbilityHelper.denormalizeUri

denormalizeUri(uri: string): Promise\<string>

Converts a normalized URI generated by **DataAbilityHelper.normalizeUri(uri: string)** to a denormalized one. This API uses a promise to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.FAModel

**Note**: This API can be used only in the FA model. In the stage model, use [DataShareHelper.denormalizeUri](js-apis-data-dataShare.md#denormalizeuri-1) instead.

**Parameters**

| Name| Type  | Mandatory| Description                   |
| ---- | ------ | ---- | ----------------------- |
| uri  | string | Yes  | URI object to denormalize.|

**Return value**

| Type            | Description                                     |
| ---------------- | ----------------------------------------- |
| Promise\<string> | Promise used to return the denormalized URI object.|

**Example**

```ts
import ability from '@ohos.ability.ability';
import featureAbility from '@ohos.ability.featureAbility';

let DAHelper: ability.DataAbilityHelper = featureAbility.acquireDataAbilityHelper(
    'dataability:///com.example.DataAbility'
);
DAHelper.denormalizeUri('dataability:///com.example.DataAbility',).then((data) => {
    console.info(`denormalizeUri data: ${JSON.stringify(data)}`);
});
```

## DataAbilityHelper.notifyChange

notifyChange(uri: string, callback: AsyncCallback\<void>): void

Notifies the registered observer of a change to the data specified by the URI. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.FAModel

**Note**: This API can be used only in the FA model. In the stage model, use [DataShareHelper.notifyChange](js-apis-data-dataShare.md#notifychange) instead.

**Parameters**

| Name    | Type                | Mandatory| Description                    |
| -------- | -------------------- | ---- | ------------------------ |
| uri      | string               | Yes  | URI of the data that changes.|
| callback | AsyncCallback\<void> | Yes  | Callback used to return the result.              |

**Example**

```ts
import ability from '@ohos.ability.ability';
import featureAbility from '@ohos.ability.featureAbility';

let DAHelper: ability.DataAbilityHelper = featureAbility.acquireDataAbilityHelper(
    'dataability:///com.example.DataAbility'
);
DAHelper.notifyChange('dataability:///com.example.DataAbility', (error) => {
    if (error && error.code !== 0) {
        console.error(`notifyChange fail, error: ${JSON.stringify(error)}`);
    } else {
        console.log('notifyChange success');
    }
});
```

## DataAbilityHelper.notifyChange

notifyChange(uri: string): Promise\<void>

Notifies the registered observer of a change to the data specified by the URI. This API uses a promise to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.FAModel

**Note**: This API can be used only in the FA model. In the stage model, use [DataShareHelper.notifyChange](js-apis-data-dataShare.md#notifychange-1) instead.

**Parameters**

| Name| Type  | Mandatory| Description                    |
| ---- | ------ | ---- | ------------------------ |
| uri  | string | Yes  | URI of the data that changes.|

**Return value**

| Type          | Description                 |
| -------------- | --------------------- |
| Promise\<void> | Promise used to return the result.|

**Example**

```ts
import ability from '@ohos.ability.ability';
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

**Note**: This API can be used only in the FA model. In the stage model, use [DataShareHelper.insert](js-apis-data-dataShare.md#insert) instead.

**Parameters**

| Name        | Type                  | Mandatory| Description                                                  |
| ------------ | ---------------------- | ---- | ------------------------------------------------------ |
| uri          | string                 | Yes  | URI of the data to insert.                              |
| valuesBucket | rdb.ValuesBucket       | Yes  | Data record to insert. If this parameter is **null**, a blank row will be inserted.|
| callback     | AsyncCallback\<number> | Yes  | Callback used to return the index of the inserted data record.                    |

**Example**

```ts
import ability from '@ohos.ability.ability';
import featureAbility from '@ohos.ability.featureAbility';
import rdb from '@ohos.data.rdb';

let DAHelper: ability.DataAbilityHelper = featureAbility.acquireDataAbilityHelper(
    'dataability:///com.example.DataAbility'
);
const valueBucket: rdb.ValuesBucket = {
    'name': 'rose',
    'age': 22,
    'salary': 200.5,
    'blobType': 'u8',
};
DAHelper.insert('dataability:///com.example.DataAbility', valueBucket, (error, data) => {
    if (error && error.code !== 0) {
        console.error(`insert fail, error: ${JSON.stringify(error)}`);
    } else {
        console.log(`insert success, data: ${JSON.stringify(data)}`);
    }
});
```

## DataAbilityHelper.insert

insert(uri: string, valuesBucket: rdb.ValuesBucket): Promise\<number>

Inserts a single data record into the database. This API uses a promise to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.FAModel

**Note**: This API can be used only in the FA model. In the stage model, use [DataShareHelper.insert](js-apis-data-dataShare.md#insert-1) instead.

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
import ability from '@ohos.ability.ability';
import featureAbility from '@ohos.ability.featureAbility';
import rdb from '@ohos.data.rdb';

let DAHelper: ability.DataAbilityHelper = featureAbility.acquireDataAbilityHelper(
    'dataability:///com.example.DataAbility'
);
const valueBucket: rdb.ValuesBucket = {
    'name': 'rose1',
    'age': 221,
    'salary': 20.5,
    'blobType': 'u8',
};
DAHelper.insert('dataability:///com.example.DataAbility', valueBucket).then((data) => {
    console.info(`insert data: ${JSON.stringify(data)}`);
});
```

## DataAbilityHelper.batchInsert

batchInsert(uri: string, valuesBuckets: Array\<rdb.ValuesBucket>, callback: AsyncCallback\<number>): void

Inserts multiple data records into the database. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.FAModel

**Note**: This API can be used only in the FA model. In the stage model, use [DataShareHelper.batchInsert](js-apis-data-dataShare.md#batchinsert) instead.

**Parameters**

| Name        | Type                   | Mandatory| Description                            |
| ------------ | ----------------------- | ---- | -------------------------------- |
| uri          | string                  | Yes  | URI of the data to insert.        |
| valuesBucket | Array\<rdb.ValuesBucket> | Yes  | Data records to insert.          |
| callback     | AsyncCallback\<number>  | Yes  | Callback used to return the number of inserted data records.|

**Example**

```ts
import ability from '@ohos.ability.ability';
import featureAbility from '@ohos.ability.featureAbility';
import rdb from '@ohos.data.rdb';

let DAHelper: ability.DataAbilityHelper = featureAbility.acquireDataAbilityHelper(
    'dataability:///com.example.DataAbility'
);
let cars = new Array({'name': 'roe11', 'age': 21, 'salary': 20.5, 'blobType': 'u8',} as rdb.ValuesBucket,
                     {'name': 'roe12', 'age': 21, 'salary': 20.5, 'blobType': 'u8',} as rdb.ValuesBucket,
                     {'name': 'roe13', 'age': 21, 'salary': 20.5, 'blobType': 'u8',} as rdb.ValuesBucket);
DAHelper.batchInsert('dataability:///com.example.DataAbility', cars, (error, data) => {
    if (error && error.code !== 0) {
        console.error(`batchInsert fail, error: ${JSON.stringify(error)}`);
    } else {
        console.log(`batchInsert success, data: ${JSON.stringify(data)}`);
    }
});
```

## DataAbilityHelper.batchInsert

batchInsert(uri: string, valuesBuckets: Array<rdb.ValuesBucket>): Promise\<number>

Inserts multiple data records into the database. This API uses a promise to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.FAModel

**Note**: This API can be used only in the FA model. In the stage model, use [DataShareHelper.batchInsert](js-apis-data-dataShare.md#batchinsert-1) instead.

**Parameters**

| Name        | Type                   | Mandatory| Description                    |
| ------------ | ----------------------- | ---- | ------------------------ |
| uri          | string                  | Yes  | URI of the data to insert.|
| valuesBucket | Array<rdb.ValuesBucket> | Yes  | Data records to insert.  |

**Return value**

| Type            | Description                  |
| ---------------- | ---------------------- |
| Promise\<number> | Promise used to return the number of inserted data records.|

**Example**

```ts
import ability from '@ohos.ability.ability';
import featureAbility from '@ohos.ability.featureAbility';
import rdb from '@ohos.data.rdb';

let DAHelper: ability.DataAbilityHelper = featureAbility.acquireDataAbilityHelper(
    'dataability:///com.example.DataAbility'
);
let cars = new Array({'name': 'roe11', 'age': 21, 'salary': 20.5, 'blobType': 'u8',} as rdb.ValuesBucket,
                     {'name': 'roe12', 'age': 21, 'salary': 20.5, 'blobType': 'u8',} as rdb.ValuesBucket,
                     {'name': 'roe13', 'age': 21, 'salary': 20.5, 'blobType': 'u8',} as rdb.ValuesBucket);
DAHelper.batchInsert('dataability:///com.example.DataAbility', cars).then((data) => {
    console.info(`batchInsert data: ${JSON.stringify(data)}`);
});
```

## DataAbilityHelper.delete

delete(uri: string, predicates: dataAbility.DataAbilityPredicates, callback: AsyncCallback\<number>): void

Deletes one or more data records from the database. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.FAModel

**Note**: This API can be used only in the FA model. In the stage model, use [DataShareHelper.delete](js-apis-data-dataShare.md#delete) instead.

**Parameters**

| Name        | Type                             | Mandatory| Description                                            |
| ------------ | --------------------------------- | ---- | ------------------------------------------------ |
| uri          | string                            | Yes  | URI of the data to delete.                        |
| predicates | dataAbility.DataAbilityPredicates | Yes  | Filter criteria. You should define the processing logic when this parameter is **null**.|
| callback     | AsyncCallback\<number>            | Yes  | Callback used to return the number of deleted data records.              |

**Example**

```ts
import ability from '@ohos.ability.ability';
import featureAbility from '@ohos.ability.featureAbility';
import ohos_data_ability from '@ohos.data.dataAbility';

let DAHelper: ability.DataAbilityHelper = featureAbility.acquireDataAbilityHelper(
    'dataability:///com.example.DataAbility'
);
let da = new ohos_data_ability.DataAbilityPredicates();
DAHelper.delete('dataability:///com.example.DataAbility', da, (error, data) => {
    if (error && error.code !== 0) {
        console.error(`delete fail, error: ${JSON.stringify(error)}`);
    } else {
        console.log(`delete success, data: ${JSON.stringify(data)}`);
    }
});
```

## DataAbilityHelper.delete

delete(uri: string, predicates?: dataAbility.DataAbilityPredicates): Promise\<number>

Deletes one or more data records from the database. This API uses a promise to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.FAModel

**Note**: This API can be used only in the FA model. In the stage model, use [DataShareHelper.delete](js-apis-data-dataShare.md#delete-1) instead.

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
import ability from '@ohos.ability.ability';
import featureAbility from '@ohos.ability.featureAbility';
import ohos_data_ability from '@ohos.data.dataAbility';

let DAHelper: ability.DataAbilityHelper = featureAbility.acquireDataAbilityHelper(
    'dataability:///com.example.DataAbility'
);
let da = new ohos_data_ability.DataAbilityPredicates();
DAHelper.delete('dataability:///com.example.DataAbility', da).then((data) => {
    console.info(`delete data: ${JSON.stringify(data)}`);
});
```

## DataAbilityHelper.delete

delete(uri: string, callback: AsyncCallback\<number>): void

Uses a custom processing logic to delete data records from the database. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.FAModel

**Note**: This API can be used only in the FA model. In the stage model, use [DataShareHelper.delete](js-apis-data-dataShare.md#delete) instead.

**Parameters**

| Name        | Type                             | Mandatory| Description                                            |
| ------------ | --------------------------------- | ---- | ------------------------------------------------ |
| uri          | string                            | Yes  | URI of the data to delete.                        |
| callback     | AsyncCallback\<number>            | Yes  | Callback used to return the number of deleted data records.              |

**Example**

```ts
import ability from '@ohos.ability.ability';
import featureAbility from '@ohos.ability.featureAbility';

let DAHelper: ability.DataAbilityHelper = featureAbility.acquireDataAbilityHelper(
    'dataability:///com.example.DataAbility'
);
DAHelper.delete('dataability:///com.example.DataAbility', (error, data) => {
    if (error && error.code !== 0) {
        console.error(`delete fail, error: ${JSON.stringify(error)}`);
    } else {
        console.log(`delete success, data: ${JSON.stringify(data)}`);
    }
});
```

## DataAbilityHelper.update

update(uri: string, valuesBucket: rdb.ValuesBucket, predicates: dataAbility.DataAbilityPredicates, callback: AsyncCallback\<number>): void

Updates data records in the database. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.FAModel

**Note**: This API can be used only in the FA model. In the stage model, use [DataShareHelper.update](js-apis-data-dataShare.md#update) instead.

**Parameters**

| Name        | Type                             | Mandatory| Description                                            |
| ------------ | --------------------------------- | ---- | ------------------------------------------------ |
| uri          | string                            | Yes  | URI of the data to update.                        |
| valuesBucket | rdb.ValuesBucket                  | Yes  | New values.                              |
| predicates   | dataAbility.DataAbilityPredicates | Yes  | Filter criteria. You should define the processing logic when this parameter is **null**.|
| callback     | AsyncCallback\<number>            | Yes  | Callback used to return the number of updated data records.                |

**Example**

```ts
import ability from '@ohos.ability.ability';
import featureAbility from '@ohos.ability.featureAbility';
import ohos_data_ability from '@ohos.data.dataAbility';
import rdb from '@ohos.data.rdb';

let DAHelper: ability.DataAbilityHelper = featureAbility.acquireDataAbilityHelper(
    'dataability:///com.example.DataAbility'
);
const va: rdb.ValuesBucket = {
    'name': 'roe1',
    'age': 21,
    'salary': 20.5,
    'blobType': 'u8',
};
let da = new ohos_data_ability.DataAbilityPredicates();
DAHelper.update('dataability:///com.example.DataAbility', va, da, (error, data) => {
    if (error && error.code !== 0) {
        console.error(`update fail, error: ${JSON.stringify(error)}`);
    } else {
        console.log(`update success, data: ${JSON.stringify(data)}`);
    }
});
```

## DataAbilityHelper.update

update(uri: string, valuesBucket: rdb.ValuesBucket, predicates?: dataAbility.DataAbilityPredicates): Promise\<number>

Updates data records in the database. This API uses a promise to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.FAModel

**Note**: This API can be used only in the FA model. In the stage model, use [DataShareHelper.update](js-apis-data-dataShare.md#update-1) instead.

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
import ability from '@ohos.ability.ability';
import featureAbility from '@ohos.ability.featureAbility';
import ohos_data_ability from '@ohos.data.dataAbility';
import rdb from '@ohos.data.rdb';

let DAHelper: ability.DataAbilityHelper = featureAbility.acquireDataAbilityHelper(
    'dataability:///com.example.DataAbility'
);
const va: rdb.ValuesBucket = {
    'name': 'roe1',
    'age': 21,
    'salary': 20.5,
    'blobType': 'u8',
};
let da = new ohos_data_ability.DataAbilityPredicates();
DAHelper.update('dataability:///com.example.DataAbility', va, da).then((data) => {
    console.info(`update data: ${JSON.stringify(data)}`);
});
```

## DataAbilityHelper.update

update(uri: string, valuesBucket: rdb.ValuesBucket, callback: AsyncCallback\<number>): void

Uses a custom processing logic to update data records in the database. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.FAModel

**Note**: This API can be used only in the FA model. In the stage model, use [DataShareHelper.update](js-apis-data-dataShare.md#update) instead.

**Parameters**

| Name        | Type                             | Mandatory| Description                                            |
| ------------ | --------------------------------- | ---- | ------------------------------------------------ |
| uri          | string                            | Yes  | URI of the data to update.                        |
| valuesBucket | rdb.ValuesBucket                  | Yes  | New values.                              |
| callback     | AsyncCallback\<number>            | Yes  | Callback used to return the number of updated data records.                |

**Example**

```ts
import ability from '@ohos.ability.ability';
import featureAbility from '@ohos.ability.featureAbility';
import rdb from '@ohos.data.rdb';

let DAHelper: ability.DataAbilityHelper = featureAbility.acquireDataAbilityHelper(
    'dataability:///com.example.DataAbility'
);
const va: rdb.ValuesBucket = {
    'name': 'roe1',
    'age': 21,
    'salary': 20.5,
    'blobType': 'u8',
};
DAHelper.update('dataability:///com.example.DataAbility', va, (error, data) => {
    if (error && error.code !== 0) {
        console.error(`update fail, error: ${JSON.stringify(error)}`);
    } else {
        console.log(`update success, data: ${JSON.stringify(data)}`);
    }
});
```

## DataAbilityHelper.query

query(uri: string, columns: Array\<string>, predicates: dataAbility.DataAbilityPredicates, callback: AsyncCallback\<ResultSet>): void

Queries data in the database. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.FAModel

**Note**: This API can be used only in the FA model. In the stage model, use [DataShareHelper.query](js-apis-data-dataShare.md#query) instead.

**Parameters**

| Name      | Type                             | Mandatory| Description                                            |
| ---------- | --------------------------------- | ---- | ------------------------------------------------ |
| uri        | string                            | Yes  | URI of the data to query.                        |
| columns    | Array\<string>                | Yes  | Columns to query. If this parameter is **null**, all columns will be queried.  |
| predicates | dataAbility.DataAbilityPredicates | Yes  | Filter criteria. When **null** is passed in, you need to customize the logic for querying data in the database.|
| callback   | AsyncCallback\<ResultSet>         | Yes  | Callback used to return the data queried.                        |

**Example**

```ts
import ability from '@ohos.ability.ability';
import featureAbility from '@ohos.ability.featureAbility';
import ohos_data_ability from '@ohos.data.dataAbility';

let DAHelper: ability.DataAbilityHelper = featureAbility.acquireDataAbilityHelper(
    'dataability:///com.example.DataAbility'
);
let cars=new Array('value1', 'value2', 'value3', 'value4');
let da = new ohos_data_ability.DataAbilityPredicates();
DAHelper.query('dataability:///com.example.DataAbility', cars, da, (error, data) => {
    if (error && error.code !== 0) {
        console.error(`query fail, error: ${JSON.stringify(error)}`);
    } else {
        console.log(`query success, data: ${JSON.stringify(data)}`);
    }
});
```

## DataAbilityHelper.query

query(uri: string, callback: AsyncCallback\<ResultSet>): void

Queries data in the database. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.FAModel

**Note**: This API can be used only in the FA model. In the stage model, use [DataShareHelper.query](js-apis-data-dataShare.md#query) instead.

**Parameters**

| Name      | Type                             | Mandatory| Description                                            |
| ---------- | --------------------------------- | ---- | ------------------------------------------------ |
| uri        | string                            | Yes  | URI of the data to query.                        |
| callback   | AsyncCallback\<ResultSet>         | Yes  | Callback used to return the data queried.                        |

**Example**

```ts
import ability from '@ohos.ability.ability';
import featureAbility from '@ohos.ability.featureAbility';

let DAHelper: ability.DataAbilityHelper = featureAbility.acquireDataAbilityHelper(
    'dataability:///com.example.DataAbility'
);
DAHelper.query('dataability:///com.example.DataAbility', (error, data) => {
    if (error && error.code !== 0) {
        console.error(`query fail, error: ${JSON.stringify(error)}`);
    } else {
        console.log(`query success, data: ${JSON.stringify(data)}`);
    }
});
```

## DataAbilityHelper.query

query(uri: string, columns: Array\<string>, callback: AsyncCallback\<ResultSet>): void

Queries data in the database. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.FAModel

**Note**: This API can be used only in the FA model. In the stage model, use [DataShareHelper.query](js-apis-data-dataShare.md#query) instead.

**Parameters**

| Name      | Type                             | Mandatory| Description                                            |
| ---------- | --------------------------------- | ---- | ------------------------------------------------ |
| uri        | string                            | Yes  | URI of the data to query.                        |
| columns    | Array\<string>                | Yes  | Columns to query. If this parameter is **null**, all columns will be queried.  |
| callback   | AsyncCallback\<ResultSet>         | Yes  | Callback used to return the data queried.                        |

**Example**

```ts
import ability from '@ohos.ability.ability';
import featureAbility from '@ohos.ability.featureAbility';

let DAHelper: ability.DataAbilityHelper = featureAbility.acquireDataAbilityHelper(
    'dataability:///com.example.DataAbility'
);
let cars = new Array('value1', 'value2', 'value3', 'value4');
DAHelper.query('dataability:///com.example.DataAbility', cars, (error, data) => {
    if (error && error.code !== 0) {
        console.error(`query fail, error: ${JSON.stringify(error)}`);
    } else {
        console.log(`query success, data: ${JSON.stringify(data)}`);
    }
});
```

## DataAbilityHelper.query

query(uri: string, predicates: dataAbility.DataAbilityPredicates, callback: AsyncCallback\<ResultSet>): void

Queries data in the database. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.FAModel

**Note**: This API can be used only in the FA model. In the stage model, use [DataShareHelper.query](js-apis-data-dataShare.md#query) instead.

**Parameters**

| Name      | Type                             | Mandatory| Description                                            |
| ---------- | --------------------------------- | ---- | ------------------------------------------------ |
| uri        | string                            | Yes  | URI of the data to query.                        |
| predicates | dataAbility.DataAbilityPredicates | Yes  | Filter criteria. When **null** is passed in, you need to customize the logic for querying data in the database.|
| callback   | AsyncCallback\<ResultSet>         | Yes  | Callback used to return the data queried.                        |

**Example**

```ts
import ability from '@ohos.ability.ability';
import featureAbility from '@ohos.ability.featureAbility';
import ohos_data_ability from '@ohos.data.dataAbility';

let DAHelper: ability.DataAbilityHelper = featureAbility.acquireDataAbilityHelper(
    'dataability:///com.example.DataAbility'
);
let da = new ohos_data_ability.DataAbilityPredicates();
DAHelper.query('dataability:///com.example.DataAbility', da, (error, data) => {
    if (error && error.code !== 0) {
        console.error(`query fail, error: ${JSON.stringify(error)}`);
    } else {
        console.log(`query success, data: ${JSON.stringify(data)}`);
    }
});
```

## DataAbilityHelper.query

query(uri: string, columns?: Array\<string>, predicates?: dataAbility.DataAbilityPredicates): Promise\<ResultSet>

Queries data in the database. This API uses a promise to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.FAModel

**Note**: This API can be used only in the FA model. In the stage model, use [DataShareHelper.query](js-apis-data-dataShare.md#query-1) instead.

**Parameters**

| Name      | Type                             | Mandatory| Description                                            |
| ---------- | --------------------------------- | ---- | ------------------------------------------------ |
| uri        | string                            | Yes  | URI of the data to query.                        |
| columns    | Array\<string>               | No  | Columns to query. If this parameter is **null**, all columns will be queried.  |
| predicates | dataAbility.DataAbilityPredicates | No  | Filter criteria. When **null** is passed in, you need to customize the logic for querying data in the database.|

**Return value**

| Type               | Description          |
| ------------------- | -------------- |
| Promise\<ResultSet> | Promise used to return the data queried.|

**Example**

```ts
import ability from '@ohos.ability.ability';
import featureAbility from '@ohos.ability.featureAbility';
import ohos_data_ability from '@ohos.data.dataAbility';

let DAHelper: ability.DataAbilityHelper = featureAbility.acquireDataAbilityHelper(
    'dataability:///com.example.DataAbility'
);
let cars = new Array('value1', 'value2', 'value3', 'value4');
let da = new ohos_data_ability.DataAbilityPredicates();
DAHelper.query('dataability:///com.example.DataAbility', cars, da).then((data) => {
    console.info(`query data: ${JSON.stringify(data)}`);
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
| extras   | [PacMap](js-apis-inner-ability-dataAbilityHelper.md#pacmap)        | Yes  | Key-value pair parameter.      |
| callback | AsyncCallback\<[PacMap](js-apis-inner-ability-dataAbilityHelper.md#pacmap)> | Yes| Callback used to return the result.    |

**Example**

```ts
import ability from '@ohos.ability.ability';
import featureAbility from '@ohos.ability.featureAbility';

let dataAbilityHelper: ability.DataAbilityHelper = featureAbility.acquireDataAbilityHelper(
    'dataability:///com.example.jsapidemo.UserDataAbility'
);
dataAbilityHelper.call('dataability:///com.example.jsapidemo.UserDataAbility',
    'method', 'arg', {'key1':'value1'}, (error, data) => {
    if (error && error.code !== 0) {
        console.error(`call fail, error: ${JSON.stringify(error)}`);
    } else {
        console.log(`call success, data: ${JSON.stringify(data)}`);
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
| arg      | string                   | Yes  | Parameter to pass in.     |
| extras   | [PacMap](js-apis-inner-ability-dataAbilityHelper.md#pacmap)        | Yes  | Key-value pair parameter.      |

**Return value**

| Type| Description|
|------ | ------- |
|Promise\<[PacMap](js-apis-inner-ability-dataAbilityHelper.md#pacmap)> | Promise used to return the result.|

**Example**

```ts
import ability from '@ohos.ability.ability';
import featureAbility from '@ohos.ability.featureAbility';
import { BusinessError } from '@ohos.base';

let dataAbilityHelper: ability.DataAbilityHelper = featureAbility.acquireDataAbilityHelper(
    'dataability:///com.example.jsapidemo.UserDataAbility'
);
dataAbilityHelper.call('dataability:///com.example.jsapidemo.UserDataAbility',
    'method', 'arg', {'key1':'value1'}).then((data) => {
    console.info('call success, data: ${data}');
}).catch((error: BusinessError) => {
    console.error('call failed, error: ${error}');
});
```

## DataAbilityHelper.executeBatch

executeBatch(uri: string, operations: Array\<DataAbilityOperation>, callback: AsyncCallback\<Array\<DataAbilityResult>>): void

Operates data in the database in batches. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.FAModel

**Parameters**

| Name       | Type                         | Mandatory| Description                                            |
| ----------| ---------------------------------| ---- | ------------------------------------------------ |
| uri       | string                           | Yes  | URI of the DataAbility. Example: 'dataability:///com.example.xxx.xxxx'.|
| operations    |  Array\<[DataAbilityOperation](js-apis-inner-ability-dataAbilityOperation.md)>        | Yes  | An array holding the data operations on the database.  |
| callback      |  AsyncCallback\<Array\<[DataAbilityResult](js-apis-inner-ability-dataAbilityResult.md)>>    | Yes  | Callback used to return the result of each operation in the **DataAbilityResult** array.     |

**Example**

```ts
import ability from '@ohos.ability.ability';
import featureAbility from '@ohos.ability.featureAbility';

// Select the operations to be performed on the database according to the DataAbilityOperation array.
let op: Array<ability.DataAbilityOperation> = new Array();
let dataAbilityHelper: ability.DataAbilityHelper = featureAbility.acquireDataAbilityHelper(
    'dataability:///com.example.jsapidemo.UserDataAbility'
);
dataAbilityHelper.executeBatch('dataability:///com.example.jsapidemo.UserDataAbility', op, (error, data) => {
    if (error && error.code !== 0) {
        console.error(`executeBatch fail, error: ${JSON.stringify(error)}`);
    } else {
        console.log(`executeBatch success, data: ${JSON.stringify(data)}`);
    }
});
```

## DataAbilityHelper.executeBatch

executeBatch(uri: string, operations: Array\<DataAbilityOperation>): Promise\<Array\<DataAbilityResult>>

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
import ability from '@ohos.ability.ability';
import featureAbility from '@ohos.ability.featureAbility';
import { BusinessError } from '@ohos.base';

// Select the operations to be performed on the database according to the DataAbilityOperation array.
let op: Array<ability.DataAbilityOperation> = new Array();
let dataAbilityHelper: ability.DataAbilityHelper = featureAbility.acquireDataAbilityHelper(
    'dataability:///com.example.jsapidemo.UserDataAbility'
);
dataAbilityHelper.executeBatch('dataability:///com.example.jsapidemo.UserDataAbility', op).then((data) => {
    console.info('executeBatch success, data: ${data}');
}).catch((error: BusinessError) => {
    console.error('executeBatch failed, error: ${error}');
});

```

## PacMap<sup>11+</sup>

[key: string]: number | string | boolean | Array\<string | number | boolean> | null

Defines the **PacMap** type used for data storage.

**System capability**: SystemCapability.Ability.AbilityRuntime.FAModel

| Name| Type| Mandatory| Description|
| ------ | ------ | ------ | ------ |
| [key: string] | number \| string \| boolean \| Array\<string \| number \| boolean\> \| null | Yes| Data stored in key-value pairs.|
