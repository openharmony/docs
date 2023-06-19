# @ohos.data.rdb (RDB)

The relational database (RDB) manages data based on relational models. With the underlying SQLite database, the RDB provides a complete mechanism for managing local databases. To satisfy different needs in complicated scenarios, the RDB offers a series of methods for performing operations such as adding, deleting, modifying, and querying data, and supports direct execution of SQL statements. The worker threads are not supported.

This module provides the following RDB-related functions:

- [RdbPredicates](#rdbpredicates): provides predicates indicating the nature, feature, or relationship of a data entity in an RDB store. It is used to define the operation conditions for an RDB store.
- [RdbStore](#rdbstore): provides APIs for managing an RDB store.

> **NOTE**
>
> - The initial APIs of this module are supported since API version 7. Newly added APIs will be marked with a superscript to indicate their earliest API version.
> - The APIs of this module are no longer maintained since API version 9. You are advised to use [@ohos.data.relationalStore](js-apis-data-relationalStore.md).


## Modules to Import

```js
import data_rdb from '@ohos.data.rdb';
```
## data_rdb.getRdbStore

getRdbStore(context: Context, config: StoreConfig, version: number, callback: AsyncCallback&lt;RdbStore&gt;): void

Obtains an RDB store. This API uses an asynchronous callback to return the result. You can set parameters for the RDB store based on service requirements and call APIs to perform data operations.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Parameters**

| Name  | Type                                      | Mandatory| Description                                                        |
| -------- | ------------------------------------------ | ---- | ------------------------------------------------------------ |
| context  | Context                                    | Yes  | Application context.<br>For details about the application context of the FA model, see [Context](js-apis-inner-app-context.md).<br>For details about the application context of the stage model, see [Context](js-apis-inner-app-context.md).|
| config   | [StoreConfig](#storeconfig)                | Yes  | Configuration of the RDB store.                               |
| version  | number                                     | Yes  | RDB store version.<br>Currently, automatic RDB upgrades and downgrades performed based on **version** is not supported.                                                |
| callback | AsyncCallback&lt;[RdbStore](#rdbstore)&gt; | Yes  | Callback invoked to return the RDB store obtained.                    |

**Example**

FA model:

```js
// Obtain the context.
import featureAbility from '@ohos.ability.featureAbility'
let context = featureAbility.getContext()

// Call getRdbStore.
const STORE_CONFIG = { name: "RdbTest.db"}
data_rdb.getRdbStore(context, STORE_CONFIG, 1, function (err, rdbStore) {
    if (err) {
        console.info("Failed to get RdbStore, err: " + err)
        return
    }
    console.log("Got RdbStore successfully.")
})
```

Stage model:

```ts
// Obtain the context.
import UIAbility from '@ohos.app.ability.UIAbility';

let context;
class EntryAbility extends UIAbility {
    onWindowStageCreate(windowStage){
        context = this.context
    }
}

// Call getRdbStore.
const STORE_CONFIG = { name: "RdbTest.db"}
data_rdb.getRdbStore(context, STORE_CONFIG, 1, function (err, rdbStore) {
    if (err) {
        console.info("Failed to get RdbStore, err: " + err)
        return
    }
    console.log("Got RdbStore successfully.")
})
```

## data_rdb.getRdbStore

getRdbStore(context: Context, config: StoreConfig, version: number): Promise&lt;RdbStore&gt;

Obtains an RDB store. This API uses a promise to return the result. You can set parameters for the RDB store based on service requirements and call APIs to perform data operations.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Parameters**

| Name | Type                       | Mandatory| Description                                                        |
| ------- | --------------------------- | ---- | ------------------------------------------------------------ |
| context | Context                     | Yes  | Application context.<br>For details about the application context of the FA model, see [Context](js-apis-inner-app-context.md).<br>For details about the application context of the stage model, see [Context](js-apis-inner-app-context.md).|
| config  | [StoreConfig](#storeconfig) | Yes  | Configuration of the RDB store.                               |
| version | number                      | Yes  | RDB store version.<br>Currently, automatic RDB upgrades and downgrades performed based on **version** is not supported.                                                |

**Return value**

| Type                                | Description                           |
| ------------------------------------ | ------------------------------- |
| Promise&lt;[RdbStore](#rdbstore)&gt; | Promise used to return the RDB store obtained.|

**Example**

FA model:

```js
// Obtain the context.
import featureAbility from '@ohos.ability.featureAbility'
let context = featureAbility.getContext()

// Call getRdbStore.
const STORE_CONFIG = { name: "RdbTest.db" }
let promise = data_rdb.getRdbStore(context, STORE_CONFIG, 1);
promise.then(async (rdbStore) => {
    console.log("Got RdbStore successfully.")
}).catch((err) => {
    console.log("Failed to get RdbStore, err: " + err)
})
```

Stage model:

```ts
// Obtain the context.
import UIAbility from '@ohos.app.ability.UIAbility';

let context;
class EntryAbility extends UIAbility {
    onWindowStageCreate(windowStage){
        context = this.context
    }
}

// Call getRdbStore.
const STORE_CONFIG = { name: "RdbTest.db" }
let promise = data_rdb.getRdbStore(context, STORE_CONFIG, 1);
promise.then(async (rdbStore) => {
    console.log("Got RdbStore successfully.")
}).catch((err) => {
    console.log("Failed to get RdbStore, err: " + err)
})
```

## data_rdb.deleteRdbStore

deleteRdbStore(context: Context, name: string, callback: AsyncCallback&lt;void&gt;): void

Deletes an RDB store. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Parameters**

| Name  | Type                     | Mandatory| Description                                                        |
| -------- | ------------------------- | ---- | ------------------------------------------------------------ |
| context  | Context                   | Yes  | Application context.<br>For details about the application context of the FA model, see [Context](js-apis-inner-app-context.md).<br>For details about the application context of the stage model, see [Context](js-apis-inner-app-context.md).|
| name     | string                    | Yes  | Name of the RDB store to delete.                                                |
| callback | AsyncCallback&lt;void&gt; | Yes  | Callback invoked to return the result.                                      |

**Example**

FA model:

```js
// Obtain the context.
import featureAbility from '@ohos.ability.featureAbility'
let context = featureAbility.getContext()

// Call deleteRdbStore.
data_rdb.deleteRdbStore(context, "RdbTest.db", function (err) {
    if (err) {
        console.info("Failed to delete RdbStore, err: " + err)
        return
    }
    console.log("Deleted RdbStore successfully.")
})
```

Stage model:

```ts
// Obtain the context.
import UIAbility from '@ohos.app.ability.UIAbility';

let context;
class EntryAbility extends UIAbility {
    onWindowStageCreate(windowStage){
        context = this.context
    }
}

// Call deleteRdbStore.
data_rdb.deleteRdbStore(context, "RdbTest.db", function (err) {
    if (err) {
        console.info("Failed to delete RdbStore, err: " + err)
        return
    }
    console.log("Deleted RdbStore successfully.")
})
```

## data_rdb.deleteRdbStore

deleteRdbStore(context: Context, name: string): Promise&lt;void&gt;

Deletes an RDB store. This API uses a promise to return the result.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Parameters**

| Name | Type   | Mandatory| Description                                                        |
| ------- | ------- | ---- | ------------------------------------------------------------ |
| context | Context | Yes  | Application context.<br>For details about the application context of the FA model, see [Context](js-apis-inner-app-context.md).<br>For details about the application context of the stage model, see [Context](js-apis-inner-app-context.md).|
| name    | string  | Yes  | Name of the RDB store to delete.                                                |

**Return value**

| Type               | Description                     |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Example**

FA model:

```js
// Obtain the context.
import featureAbility from '@ohos.ability.featureAbility'
let context = featureAbility.getContext()

// Call deleteRdbStore.
let promise = data_rdb.deleteRdbStore(context, "RdbTest.db")
promise.then(() => {
    console.log("Deleted RdbStore successfully.")
}).catch((err) => {
    console.info("Failed to delete RdbStore, err: " + err)
})
```

Stage model:

```ts
// Obtain the context.
import UIAbility from '@ohos.app.ability.UIAbility';

let context;
class EntryAbility extends UIAbility {
    onWindowStageCreate(windowStage){
        context = this.context
    }
}

// Call deleteRdbStore.
let promise = data_rdb.deleteRdbStore(context, "RdbTest.db")
promise.then(()=>{
    console.log("Deleted RdbStore successfully.")
}).catch((err) => {
    console.info("Failed to delete RdbStore, err: " + err)
})
```

## ValueType

Defines the data types allowed.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

| Type   | Description                |
| ------- | -------------------- |
| number  | Number.  |
| string  | String.  |
| boolean | Boolean.|


## ValuesBucket

Defines the types of the key and value in a KV pair.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

| Key Type| Value Type                                                     |
| ------ | ----------------------------------------------------------- |
| string | [ValueType](#valuetype)\|&nbsp;Uint8Array&nbsp;\|&nbsp;null |

## SyncMode<sup>8+</sup>

Defines the database synchronization mode.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

| Name          | Value  | Description                              |
| -------------- | ---- | ---------------------------------- |
| SYNC_MODE_PUSH | 0    | Data is pushed from a local device to a remote device.|
| SYNC_MODE_PULL | 1    | Data is pulled from a remote device to a local device.  |

## SubscribeType<sup>8+</sup>

Defines the subscription type.

**Required permissions**: ohos.permission.DISTRIBUTED_DATASYNC

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

| Name                 | Value  | Description              |
| --------------------- | ---- | ------------------ |
| SUBSCRIBE_TYPE_REMOTE | 0    | Subscribe to remote data changes.|

## StoreConfig

Defines the RDB store configuration.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| name | string | Yes| Database file name.|

## RdbPredicates

Defines predicates for an RDB store. This class determines whether the conditional expression for the RDB store is true or false.

### constructor

constructor(name: string)

A constructor used to create an **RdbPredicates** object.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| name | string | Yes| Database table name.|

**Example**

```js
let predicates = new data_rdb.RdbPredicates("EMPLOYEE")
```

### inDevices<sup>8+</sup>

inDevices(devices: Array&lt;string&gt;): RdbPredicates

Sets an **RdbPredicates** to specify the remote devices to connect on the network during distributed database synchronization.

> **NOTE**
>
> The value of **devices** is obtained by [deviceManager.getTrustedDeviceListSync](js-apis-device-manager.md#gettrusteddevicelistsync). The APIs of the **deviceManager** module are system interfaces and available only to system applications. 

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| devices | Array&lt;string&gt; | Yes| IDs of the remote devices in the same network.|

**Return value**

| Type| Description|
| -------- | -------- |
| [RdbPredicates](#rdbpredicates) | **RdbPredicates** object created.|

**Example**

```js
import deviceManager from '@ohos.distributedHardware.deviceManager';
let dmInstance = null;
let deviceIds = [];

deviceManager.createDeviceManager("com.example.appdatamgrverify", (err, manager) => {
    if (err) {
        console.log("create device manager failed, err=" + err);
        return;
    }
    dmInstance = manager;
    let devices = dmInstance.getTrustedDeviceListSync();
    for (var i = 0; i < devices.length; i++) {
        deviceIds[i] = devices[i].deviceId;
    }
})
                                  
let predicates = new data_rdb.RdbPredicates("EMPLOYEE");
predicates.inDevices(deviceIds);
```

### inAllDevices<sup>8+</sup>

inAllDevices(): RdbPredicates

Sets an **RdbPredicates** to specify all remote devices on the network to connect during distributed database synchronization.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Return value**

| Type| Description|
| -------- | -------- |
| [RdbPredicates](#rdbpredicates) | **RdbPredicates** object created.|

**Example**

```js
let predicates = new data_rdb.RdbPredicates("EMPLOYEE")
predicates.inAllDevices()
```

### equalTo

equalTo(field: string, value: ValueType): RdbPredicates

Sets an **RdbPredicates** to match the field with data type **ValueType** and value equal to the specified value.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| field | string | Yes| Column name in the database table.|
| value | [ValueType](#valuetype) | Yes| Value to match the **RdbPredicates**.|

**Return value**

| Type| Description|
| -------- | -------- |
| [RdbPredicates](#rdbpredicates) | **RdbPredicates** object created.|

**Example**

```js
let predicates = new data_rdb.RdbPredicates("EMPLOYEE")
predicates.equalTo("NAME", "lisi")
```


### notEqualTo

notEqualTo(field: string, value: ValueType): RdbPredicates

Sets an **RdbPredicates** to match the field with data type **ValueType** and value not equal to the specified value.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| field | string | Yes| Column name in the database table.|
| value | [ValueType](#valuetype) | Yes| Value to match the **RdbPredicates**.|

**Return value**

| Type| Description|
| -------- | -------- |
| [RdbPredicates](#rdbpredicates) | **RdbPredicates** object created.|

**Example**

```js
let predicates = new data_rdb.RdbPredicates("EMPLOYEE")
predicates.notEqualTo("NAME", "lisi")
```


### beginWrap

beginWrap(): RdbPredicates

Adds a left parenthesis to the **RdbPredicates**.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Return value**

| Type| Description|
| -------- | -------- |
| [RdbPredicates](#rdbpredicates) | **RdbPredicates** with a left parenthesis.|

**Example**

```js
let predicates = new data_rdb.RdbPredicates("EMPLOYEE")
predicates.equalTo("NAME", "lisi")
    .beginWrap()
    .equalTo("AGE", 18)
    .or()
    .equalTo("SALARY", 200.5)
    .endWrap()
```

### endWrap

endWrap(): RdbPredicates

Adds a right parenthesis to the **RdbPredicates**.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Return value**

| Type| Description|
| -------- | -------- |
| [RdbPredicates](#rdbpredicates) | **RdbPredicates** with a right parenthesis.|

**Example**

```js
let predicates = new data_rdb.RdbPredicates("EMPLOYEE")
predicates.equalTo("NAME", "lisi")
    .beginWrap()
    .equalTo("AGE", 18)
    .or()
    .equalTo("SALARY", 200.5)
    .endWrap()
```

### or

or(): RdbPredicates

Adds the OR condition to the **RdbPredicates**.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Return value**

| Type| Description|
| -------- | -------- |
| [RdbPredicates](#rdbpredicates) | **RdbPredicates** with the OR condition.|

**Example**

```js
let predicates = new data_rdb.RdbPredicates("EMPLOYEE")
predicates.equalTo("NAME", "Lisa")
    .or()
    .equalTo("NAME", "Rose")
```

### and

and(): RdbPredicates

Adds the AND condition to the **RdbPredicates**.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Return value**

| Type| Description|
| -------- | -------- |
| [RdbPredicates](#rdbpredicates) | **RdbPredicates** with the AND condition.|

**Example**

```js
let predicates = new data_rdb.RdbPredicates("EMPLOYEE")
predicates.equalTo("NAME", "Lisa")
    .and()
    .equalTo("SALARY", 200.5)
```

### contains

contains(field: string, value: string): RdbPredicates

Sets an **RdbPredicates** to match a string containing the specified value.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| field | string | Yes| Column name in the database table.|
| value | string | Yes| Value to match the **RdbPredicates**.|

**Return value**

| Type| Description|
| -------- | -------- |
| [RdbPredicates](#rdbpredicates) | **RdbPredicates** object created.|

**Example**

```js
let predicates = new data_rdb.RdbPredicates("EMPLOYEE")
predicates.contains("NAME", "os")
```

### beginsWith

beginsWith(field: string, value: string): RdbPredicates

Sets an **RdbPredicates** to match a string that starts with the specified value.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| field | string | Yes| Column name in the database table.|
| value | string | Yes| Value to match the **RdbPredicates**.|

**Return value**

| Type| Description|
| -------- | -------- |
| [RdbPredicates](#rdbpredicates) | **RdbPredicates** object created.|

**Example**

```js
let predicates = new data_rdb.RdbPredicates("EMPLOYEE")
predicates.beginsWith("NAME", "os")
```

### endsWith

endsWith(field: string, value: string): RdbPredicates

Sets an **RdbPredicates** to match a string that ends with the specified value.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| field | string | Yes| Column name in the database table.|
| value | string | Yes| Value to match the **RdbPredicates**.|

**Return value**

| Type| Description|
| -------- | -------- |
| [RdbPredicates](#rdbpredicates) | **RdbPredicates** object created.|

**Example**

```js
let predicates = new data_rdb.RdbPredicates("EMPLOYEE")
predicates.endsWith("NAME", "se")
```

### isNull

isNull(field: string): RdbPredicates

Sets an **RdbPredicates** to match the field whose value is null.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| field | string | Yes| Column name in the database table.|

**Return value**

| Type| Description|
| -------- | -------- |
| [RdbPredicates](#rdbpredicates) | **RdbPredicates** object created.|

**Example**
```js
let predicates = new data_rdb.RdbPredicates("EMPLOYEE")
predicates.isNull("NAME")
```

### isNotNull

isNotNull(field: string): RdbPredicates

Sets an **RdbPredicates** to match the field whose value is not null.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| field | string | Yes| Column name in the database table.|

**Return value**

| Type| Description|
| -------- | -------- |
| [RdbPredicates](#rdbpredicates) | **RdbPredicates** object created.|

**Example**

```js
let predicates = new data_rdb.RdbPredicates("EMPLOYEE")
predicates.isNotNull("NAME")
```

### like

like(field: string, value: string): RdbPredicates

Sets an **RdbPredicates** to match a string that is similar to the specified value.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| field | string | Yes| Column name in the database table.|
| value | string | Yes| Value to match the **RdbPredicates**.|

**Return value**

| Type| Description|
| -------- | -------- |
| [RdbPredicates](#rdbpredicates) | **RdbPredicates** object created.|

**Example**

```js
let predicates = new data_rdb.RdbPredicates("EMPLOYEE")
predicates.like("NAME", "%os%")
```

### glob

glob(field: string, value: string): RdbPredicates

Sets an **RdbPredicates** to match the specified string.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| field | string | Yes| Column name in the database table.|
| value | string | Yes| Value to match the **RdbPredicates**.<br><br>Wildcards are supported. * indicates zero, one, or multiple digits or characters. **?** indicates a single digit or character.|

**Return value**

| Type| Description|
| -------- | -------- |
| [RdbPredicates](#rdbpredicates) | **RdbPredicates** object created.|

**Example**

```js
let predicates = new data_rdb.RdbPredicates("EMPLOYEE")
predicates.glob("NAME", "?h*g")
```

### between

between(field: string, low: ValueType, high: ValueType): RdbPredicates

Sets an **RdbPredicates** to match the field with data type **ValueType** and value within the specified range.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| field | string | Yes| Column name in the database table.|
| low | [ValueType](#valuetype) | Yes| Minimum value to match the **RdbPredicates**.|
| high | [ValueType](#valuetype) | Yes| Maximum value to match the **RdbPredicates**.|

**Return value**

| Type| Description|
| -------- | -------- |
| [RdbPredicates](#rdbpredicates) | **RdbPredicates** object created.|

**Example**

```js
let predicates = new data_rdb.RdbPredicates("EMPLOYEE")
predicates.between("AGE", 10, 50)
```

### notBetween

notBetween(field: string, low: ValueType, high: ValueType): RdbPredicates

Sets an **RdbPredicates** to match the field with data type **ValueType** and value out of the specified range.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| field | string | Yes| Column name in the database table.|
| low | [ValueType](#valuetype) | Yes| Minimum value to match the **RdbPredicates**.|
| high | [ValueType](#valuetype) | Yes| Maximum value to match the **RdbPredicates**.|

**Return value**

| Type| Description|
| -------- | -------- |
| [RdbPredicates](#rdbpredicates) | **RdbPredicates** object created.|

**Example**

```js
let predicates = new data_rdb.RdbPredicates("EMPLOYEE")
predicates.notBetween("AGE", 10, 50)
```

### greaterThan

greaterThan(field: string, value: ValueType): RdbPredicates

Sets an **RdbPredicates** to match the field with data type **ValueType** and value greater than the specified value.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| field | string | Yes| Column name in the database table.|
| value | [ValueType](#valuetype) | Yes| Value to match the **RdbPredicates**.|

**Return value**

| Type| Description|
| -------- | -------- |
| [RdbPredicates](#rdbpredicates) | **RdbPredicates** object created.|

**Example**

```js
let predicates = new data_rdb.RdbPredicates("EMPLOYEE")
predicates.greaterThan("AGE", 18)
```

### lessThan

lessThan(field: string, value: ValueType): RdbPredicates

Sets an **RdbPredicates** to match the field with data type **ValueType** and value less than the specified value.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| field | string | Yes| Column name in the database table.|
| value | [ValueType](#valuetype) | Yes| Value to match the **RdbPredicates**.|

**Return value**

| Type| Description|
| -------- | -------- |
| [RdbPredicates](#rdbpredicates) | **RdbPredicates** object created.|

**Example**

```js
let predicates = new data_rdb.RdbPredicates("EMPLOYEE")
predicates.lessThan("AGE", 20)
```

### greaterThanOrEqualTo

greaterThanOrEqualTo(field: string, value: ValueType): RdbPredicates

Sets an **RdbPredicates** to match the field with data type **ValueType** and value greater than or equal to the specified value.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| field | string | Yes| Column name in the database table.|
| value | [ValueType](#valuetype) | Yes| Value to match the **RdbPredicates**.|

**Return value**

| Type| Description|
| -------- | -------- |
| [RdbPredicates](#rdbpredicates) | **RdbPredicates** object created.|

**Example**

```js
let predicates = new data_rdb.RdbPredicates("EMPLOYEE")
predicates.greaterThanOrEqualTo("AGE", 18)
```

### lessThanOrEqualTo

lessThanOrEqualTo(field: string, value: ValueType): RdbPredicates

Sets an **RdbPredicates** to match the field with data type **ValueType** and value less than or equal to the specified value.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| field | string | Yes| Column name in the database table.|
| value | [ValueType](#valuetype) | Yes| Value to match the **RdbPredicates**.|

**Return value**

| Type| Description|
| -------- | -------- |
| [RdbPredicates](#rdbpredicates) | **RdbPredicates** object created.|

**Example**

```js
let predicates = new data_rdb.RdbPredicates("EMPLOYEE")
predicates.lessThanOrEqualTo("AGE", 20)
```

### orderByAsc

orderByAsc(field: string): RdbPredicates

Sets an **RdbPredicates** to match the column with values sorted in ascending order.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| field | string | Yes| Column name in the database table.|

**Return value**

| Type| Description|
| -------- | -------- |
| [RdbPredicates](#rdbpredicates) | **RdbPredicates** object created.|

**Example**

```js
let predicates = new data_rdb.RdbPredicates("EMPLOYEE")
predicates.orderByAsc("NAME")
```

### orderByDesc

orderByDesc(field: string): RdbPredicates

Sets an **RdbPredicates** to match the column with values sorted in descending order.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| field | string | Yes| Column name in the database table.|

**Return value**

| Type| Description|
| -------- | -------- |
| [RdbPredicates](#rdbpredicates) | **RdbPredicates** object created.|

**Example**

```js
let predicates = new data_rdb.RdbPredicates("EMPLOYEE")
predicates.orderByDesc("AGE")
```

### distinct

distinct(): RdbPredicates

Sets an **RdbPredicates** to filter out duplicate records.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Return value**

| Type| Description|
| -------- | -------- |
| [RdbPredicates](#rdbpredicates) | **RdbPredicates** object that can filter out duplicate records.|

**Example**

```js
let predicates = new data_rdb.RdbPredicates("EMPLOYEE")
predicates.equalTo("NAME", "Rose").distinct()
```

### limitAs

limitAs(value: number): RdbPredicates

Sets an **RdbPredicates** to specify the maximum number of records.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| value | number | Yes| Maximum number of records.|

**Return value**

| Type| Description|
| -------- | -------- |
| [RdbPredicates](#rdbpredicates) | **RdbPredicates** object that specifies the maximum number of records.|

**Example**

```js
let predicates = new data_rdb.RdbPredicates("EMPLOYEE")
predicates.equalTo("NAME", "Rose").limitAs(3)
```

### offsetAs

offsetAs(rowOffset: number): RdbPredicates

Sets an **RdbPredicates** to specify the start position of the returned result.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| rowOffset | number | Yes| Number of rows to offset from the beginning. The value is a positive integer.|

**Return value**

| Type| Description|
| -------- | -------- |
| [RdbPredicates](#rdbpredicates) | **RdbPredicates** object that specifies the start position of the returned result.|

**Example**

```js
let predicates = new data_rdb.RdbPredicates("EMPLOYEE")
predicates.equalTo("NAME", "Rose").offsetAs(3)
```

### groupBy

groupBy(fields: Array&lt;string&gt;): RdbPredicates

Sets an **RdbPredicates** to group rows that have the same value into summary rows.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| fields | Array&lt;string&gt; | Yes| Names of columns to group.|

**Return value**

| Type| Description|
| -------- | -------- |
| [RdbPredicates](#rdbpredicates) | **RdbPredicates** object that groups rows with the same value.|

**Example**

```js
let predicates = new data_rdb.RdbPredicates("EMPLOYEE")
predicates.groupBy(["AGE", "NAME"])
```

### indexedBy

indexedBy(field: string): RdbPredicates

Sets an **RdbPredicates** object to specify the index column.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| field | string | Yes| Name of the index column.|

**Return value**


| Type| Description|
| -------- | -------- |
| [RdbPredicates](#rdbpredicates) | **RdbPredicates** object that specifies the index column.|

**Example**

```js
let predicates = new data_rdb.RdbPredicates("EMPLOYEE")
predicates.indexedBy("SALARY_INDEX")
```

### in

in(field: string, value: Array&lt;ValueType&gt;): RdbPredicates

Sets an **RdbPredicates** to match the field with data type **Array&#60;ValueType&#62;** and value within the specified range.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| field | string | Yes| Column name in the database table.|
| value | Array&lt;[ValueType](#valuetype)&gt; | Yes| Array of **ValueType**s to match.|

**Return value**

| Type| Description|
| -------- | -------- |
| [RdbPredicates](#rdbpredicates) | **RdbPredicates** object created.|

**Example**

```js
let predicates = new data_rdb.RdbPredicates("EMPLOYEE")
predicates.in("AGE", [18, 20])
```

### notIn

notIn(field: string, value: Array&lt;ValueType&gt;): RdbPredicates

Sets an **RdbPredicates** to match the field with data type **Array&#60;ValueType&#62;** and value out of the specified range.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| field | string | Yes| Column name in the database table.|
| value | Array&lt;[ValueType](#valuetype)&gt; | Yes| Array of **ValueType**s to match.|

**Return value**

| Type| Description|
| -------- | -------- |
| [RdbPredicates](#rdbpredicates) | **RdbPredicates** object created.|

**Example**

```js
let predicates = new data_rdb.RdbPredicates("EMPLOYEE")
predicates.notIn("NAME", ["Lisa", "Rose"])
```

## RdbStore

Provides methods to manage an RDB store.

Before using the APIs of this class, use [executeSql](#executesql) to initialize the database table structure and related data.

### insert

insert(table: string, values: ValuesBucket, callback: AsyncCallback&lt;number&gt;):void

Inserts a row of data into a table. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| table | string | Yes| Name of the target table.|
| values | [ValuesBucket](#valuesbucket) | Yes| Row of data to insert.|
| callback | AsyncCallback&lt;number&gt; | Yes| Callback invoked to return the result. If the operation is successful, the row ID will be returned. Otherwise, **-1** will be returned.|

**Example**

```js
const valueBucket = {
    "NAME": "Lisa",
    "AGE": 18,
    "SALARY": 100.5,
    "CODES": new Uint8Array([1, 2, 3, 4, 5]),
}
rdbStore.insert("EMPLOYEE", valueBucket, function (status, rowId) {
    if (status) {
        console.log("Failed to insert data");
        return;
    }
    console.log("Inserted data successfully, rowId = " + rowId);
})
```

### insert

insert(table: string, values: ValuesBucket):Promise&lt;number&gt;

Inserts a row of data into a table. This API uses a promise to return the result.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| table | string | Yes| Name of the target table.|
| values | [ValuesBucket](#valuesbucket) | Yes| Row of data to insert.|

**Return value**

| Type| Description|
| -------- | -------- |
| Promise&lt;number&gt; | Promise used to return the result. If the operation is successful, the row ID will be returned. Otherwise, **-1** will be returned.|

**Example**

```js
const valueBucket = {
    "NAME": "Lisa",
    "AGE": 18,
    "SALARY": 100.5,
    "CODES": new Uint8Array([1, 2, 3, 4, 5]),
}
let promise = rdbStore.insert("EMPLOYEE", valueBucket)
promise.then((rowId) => {
    console.log("Inserted data successfully, rowId = " + rowId);
}).catch((status) => {
    console.log("Failed to insert data");
})
```

### batchInsert

batchInsert(table: string, values: Array&lt;ValuesBucket&gt;, callback: AsyncCallback&lt;number&gt;):void

Batch inserts data into a table. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| table | string | Yes| Name of the target table.|
| values | Array&lt;[ValuesBucket](#valuesbucket)&gt; | Yes| An array of data to insert.|
| callback | AsyncCallback&lt;number&gt; | Yes| Callback invoked to return the result. If the operation is successful, the number of inserted data records is returned. Otherwise, **-1** is returned.|

**Example**

```js
const valueBucket1 = {
    "NAME": "Lisa",
    "AGE": 18,
    "SALARY": 100.5,
    "CODES": new Uint8Array([1, 2, 3, 4, 5])
}
const valueBucket2 = {
    "NAME": "Jack",
    "AGE": 19,
    "SALARY": 101.5,
    "CODES": new Uint8Array([6, 7, 8, 9, 10])
}
const valueBucket3 = {
    "NAME": "Tom",
    "AGE": 20,
    "SALARY": 102.5,
    "CODES": new Uint8Array([11, 12, 13, 14, 15])
}

let valueBuckets = new Array(valueBucket1, valueBucket2, valueBucket3);
rdbStore.batchInsert("EMPLOYEE", valueBuckets, function(status, insertNum) {
    if (status) {
        console.log("batchInsert is failed, status = " + status);
        return;
    }
    console.log("batchInsert is successful, the number of values that were inserted = " + insertNum);
})
```

### batchInsert

batchInsert(table: string, values: Array&lt;ValuesBucket&gt;):Promise&lt;number&gt;

Batch inserts data into a table. This API uses a promise to return the result.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| table | string | Yes| Name of the target table.|
| values | Array&lt;[ValuesBucket](#valuesbucket)&gt; | Yes| An array of data to insert.|

**Return value**

| Type| Description|
| -------- | -------- |
| Promise&lt;number&gt; | Promise used to return the result. If the operation is successful, the number of inserted data records is returned. Otherwise, **-1** is returned.|

**Example**

```js
const valueBucket1 = {
    "NAME": "Lisa",
    "AGE": 18,
    "SALARY": 100.5,
    "CODES": new Uint8Array([1, 2, 3, 4, 5])
}
const valueBucket2 = {
    "NAME": "Jack",
    "AGE": 19,
    "SALARY": 101.5,
    "CODES": new Uint8Array([6, 7, 8, 9, 10])
}
const valueBucket3 = {
    "NAME": "Tom",
    "AGE": 20,
    "SALARY": 102.5,
    "CODES": new Uint8Array([11, 12, 13, 14, 15])
}

let valueBuckets = new Array(valueBucket1, valueBucket2, valueBucket3);
let promise = rdbStore.batchInsert("EMPLOYEE", valueBuckets);
promise.then((insertNum) => {
    console.log("batchInsert is successful, the number of values that were inserted = " + insertNum);
}).catch((status) => {
    console.log("batchInsert is failed, status = " + status);
})
```

### update

update(values: ValuesBucket, predicates: RdbPredicates, callback: AsyncCallback&lt;number&gt;):void

Updates data in the RDB store based on the specified **RdbPredicates** object. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| values | [ValuesBucket](#valuesbucket) | Yes| Rows of data to update in the RDB store. The key-value pair is associated with the column name in the target table.|
| predicates | [RdbPredicates](#rdbpredicates) | Yes| Update conditions specified by the **RdbPredicates** object.|
| callback | AsyncCallback&lt;number&gt; | Yes| Callback invoked to return the number of rows updated.|

**Example**

```js
const valueBucket = {
    "NAME": "Rose",
    "AGE": 22,
    "SALARY": 200.5,
    "CODES": new Uint8Array([1, 2, 3, 4, 5]),
}
let predicates = new data_rdb.RdbPredicates("EMPLOYEE")
predicates.equalTo("NAME", "Lisa")
rdbStore.update(valueBucket, predicates, function (err, rows) {
    if (err) {
        console.info("Failed to update data, err: " + err)
        return
    }
    console.log("Updated row count: " + rows)
})
```

### update

update(values: ValuesBucket, predicates: RdbPredicates):Promise&lt;number&gt;

Updates data based on the specified **RdbPredicates** object. This API uses a promise to return the result.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| values | [ValuesBucket](#valuesbucket) | Yes| Rows of data to update in the RDB store. The key-value pair is associated with the column name in the target table.|
| predicates | [RdbPredicates](#rdbpredicates) | Yes| Update conditions specified by the **RdbPredicates** object.|

**Return value**

| Type| Description|
| -------- | -------- |
| Promise&lt;number&gt; | Promise used to return the number of rows updated.|

**Example**

```js
const valueBucket = {
    "NAME": "Rose",
    "AGE": 22,
    "SALARY": 200.5,
    "CODES": new Uint8Array([1, 2, 3, 4, 5]),
}
let predicates = new data_rdb.RdbPredicates("EMPLOYEE")
predicates.equalTo("NAME", "Lisa")
let promise = rdbStore.update(valueBucket, predicates)
promise.then(async (rows) => {
    console.log("Updated row count: " + rows)
}).catch((err) => {
    console.info("Failed to update data, err: " + err)
})
```

### delete

delete(predicates: RdbPredicates, callback: AsyncCallback&lt;number&gt;):void

Deletes data from the RDB store based on the specified **RdbPredicates** object. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| predicates | [RdbPredicates](#rdbpredicates) | Yes| Conditions specified by the **RdbPredicates** object for deleting data.|
| callback | AsyncCallback&lt;number&gt; | Yes| Callback invoked to return the number of rows deleted.|

**Example**

```js
let predicates = new data_rdb.RdbPredicates("EMPLOYEE")
predicates.equalTo("NAME", "Lisa")
rdbStore.delete(predicates, function (err, rows) {
    if (err) {
        console.info("Failed to delete data, err: " + err)
        return
    }
    console.log("Deleted rows: " + rows)
})
```

### delete

delete(predicates: RdbPredicates):Promise&lt;number&gt;

Deletes data from the RDB store based on the specified **RdbPredicates** object. This API uses a promise to return the result.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| predicates | [RdbPredicates](#rdbpredicates) | Yes| Conditions specified by the **RdbPredicates** object for deleting data.|

**Return value**

| Type| Description|
| -------- | -------- |
| Promise&lt;number&gt; | Promise used to return the number of rows deleted.|

**Example**

```js
let predicates = new data_rdb.RdbPredicates("EMPLOYEE")
predicates.equalTo("NAME", "Lisa")
let promise = rdbStore.delete(predicates)
promise.then((rows) => {
    console.log("Deleted rows: " + rows)
}).catch((err) => {
    console.info("Failed to delete data, err: " + err)
})
```

### query

query(predicates: RdbPredicates, columns: Array&lt;string&gt;, callback: AsyncCallback&lt;ResultSet&gt;):void

Queries data from the RDB store based on specified conditions. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| predicates | [RdbPredicates](#rdbpredicates) | Yes| Query conditions specified by the **RdbPredicates** object.|
| columns | Array&lt;string&gt; | Yes| Columns to query. If this parameter is not specified, the query applies to all columns.|
| callback | AsyncCallback&lt;[ResultSet](js-apis-data-resultset.md)&gt; | Yes| Callback invoked to return the result. If the operation is successful, a **ResultSet** object will be returned.|

**Example**

```js
let predicates = new data_rdb.RdbPredicates("EMPLOYEE")
predicates.equalTo("NAME", "Rose")
rdbStore.query(predicates, ["ID", "NAME", "AGE", "SALARY", "CODES"], function (err, resultSet) {
    if (err) {
        console.info("Failed to query data, err: " + err)
        return
    }
    console.log("ResultSet column names: " + resultSet.columnNames)
    console.log("ResultSet column count: " + resultSet.columnCount)
})
```

### query

query(predicates: RdbPredicates, columns?: Array&lt;string&gt;):Promise&lt;ResultSet&gt;

Queries data from the RDB store based on specified conditions. This API uses a promise to return the result.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| predicates | [RdbPredicates](#rdbpredicates) | Yes| Query conditions specified by the **RdbPredicates** object.|
| columns | Array&lt;string&gt; | No| Columns to query. If this parameter is not specified, the query applies to all columns.|

**Return value**

| Type| Description|
| -------- | -------- |
| Promise&lt;[ResultSet](js-apis-data-resultset.md)&gt; | Promise used to return the result. If the operation is successful, a **ResultSet** object will be returned.|

**Example**

  ```js
  let predicates = new data_rdb.RdbPredicates("EMPLOYEE")
  predicates.equalTo("NAME", "Rose")
  let promise = rdbStore.query(predicates, ["ID", "NAME", "AGE", "SALARY", "CODES"])
  promise.then((resultSet) => {
      console.log("ResultSet column names: " + resultSet.columnNames)
      console.log("ResultSet column count: " + resultSet.columnCount)
  }).catch((err) => {
      console.info("Failed to query data, err: " + err)
  })
  ```

### querySql<sup>8+</sup>

querySql(sql: string, bindArgs: Array&lt;ValueType&gt;, callback: AsyncCallback&lt;ResultSet&gt;):void

Queries data in the RDB store using the specified SQL statement. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| sql | string | Yes| SQL statement to run.|
| bindArgs | Array&lt;[ValueType](#valuetype)&gt; | Yes| Arguments in the SQL statement. The value corresponds to the placeholders in the SQL parameter statement. If the SQL parameter statement is complete, the value of this parameter must be an empty array.|
| callback | AsyncCallback&lt;[ResultSet](js-apis-data-resultset.md)&gt; | Yes| Callback invoked to return the result. If the operation is successful, a **ResultSet** object will be returned.|

**Example**

```js
rdbStore.querySql("SELECT * FROM EMPLOYEE CROSS JOIN BOOK WHERE BOOK.NAME = ?", ['sanguo'], function (err, resultSet) {
    if (err) {
        console.info("Failed to query data, err: " + err)
        return
    }
    console.log("ResultSet column names: " + resultSet.columnNames)
    console.log("ResultSet column count: " + resultSet.columnCount)
})
```

### querySql<sup>8+</sup>

querySql(sql: string, bindArgs?: Array&lt;ValueType&gt;):Promise&lt;ResultSet&gt;

Queries data in the RDB store using the specified SQL statement. This API uses a promise to return the result.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| sql | string | Yes| SQL statement to run.|
| bindArgs | Array&lt;[ValueType](#valuetype)&gt; | No| Arguments in the SQL statement. The value corresponds to the placeholders in the SQL parameter statement. If the SQL parameter statement is complete, leave this parameter blank.|

**Return value**

| Type| Description|
| -------- | -------- |
| Promise&lt;[ResultSet](js-apis-data-resultset.md)&gt; | Promise used to return the result. If the operation is successful, a **ResultSet** object will be returned.|

**Example**

```js
let promise = rdbStore.querySql("SELECT * FROM EMPLOYEE CROSS JOIN BOOK WHERE BOOK.NAME = 'sanguo'")
promise.then((resultSet) => {
    console.log("ResultSet column names: " + resultSet.columnNames)
    console.log("ResultSet column count: " + resultSet.columnCount)
}).catch((err) => {
    console.info("Failed to query data, err: " + err)
})
```

### executeSql<sup>8+</sup>

executeSql(sql: string, bindArgs: Array&lt;ValueType&gt;, callback: AsyncCallback&lt;void&gt;):void

Executes an SQL statement that contains specified arguments but returns no value. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| sql | string | Yes| SQL statement to run.|
| bindArgs | Array&lt;[ValueType](#valuetype)&gt; | Yes| Arguments in the SQL statement. The value corresponds to the placeholders in the SQL parameter statement. If the SQL parameter statement is complete, the value of this parameter must be an empty array.|
| callback | AsyncCallback&lt;void&gt; | Yes| Callback invoked to return the result.|

**Example**

```js
const SQL_CREATE_TABLE = "CREATE TABLE IF NOT EXISTS EMPLOYEE (ID INTEGER PRIMARY KEY AUTOINCREMENT, NAME TEXT NOT NULL, AGE INTEGER, SALARY REAL, CODES BLOB)"
rdbStore.executeSql(SQL_CREATE_TABLE, null, function(err) {
    if (err) {
        console.info("Failed to execute SQL, err: " + err)
        return
    }
    console.info('Create table done.')
})
```

### executeSql<sup>8+</sup>

executeSql(sql: string, bindArgs?: Array&lt;ValueType&gt;):Promise&lt;void&gt;

Executes an SQL statement that contains specified arguments but returns no value. This API uses a promise to return the result.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| sql | string | Yes| SQL statement to run.|
| bindArgs | Array&lt;[ValueType](#valuetype)&gt; | No| Arguments in the SQL statement. The value corresponds to the placeholders in the SQL parameter statement. If the SQL parameter statement is complete, leave this parameter blank.|

**Return value**

| Type| Description|
| -------- | -------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Example**

```js
const SQL_DELETE_TABLE = "DELETE FROM test WHERE name = 'zhangsan'"
let promise = rdbStore.executeSql(SQL_DELETE_TABLE)
promise.then(() => {
    console.info('Delete table done.')
}).catch((err) => {
    console.info("Failed to execute SQL, err: " + err)
})
```

### beginTransaction<sup>8+</sup>

beginTransaction():void

Starts the transaction before executing an SQL statement.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Example**

```js
import featureAbility from '@ohos.ability.featureAbility'
let context = featureAbility.getContext()
const STORE_CONFIG = { name: "RdbTest.db"}
data_rdb.getRdbStore(context, STORE_CONFIG, 1, async function (err, rdbStore) {
    rdbStore.beginTransaction()
	const valueBucket = {
		"name": "lisi",
		"age": 18,
		"salary": 100.5,
		"blobType": new Uint8Array([1, 2, 3]),
	}
	await rdbStore.insert("test", valueBucket)
	rdbStore.commit()
})
```

### commit<sup>8+</sup>

commit():void

Commits the executed SQL statements.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Example**

```js
import featureAbility from '@ohos.ability.featureAbility'
let context = featureAbility.getContext()
const STORE_CONFIG = { name: "RdbTest.db"}
data_rdb.getRdbStore(context, STORE_CONFIG, 1, async function (err, rdbStore) {
    rdbStore.beginTransaction()
	const valueBucket = {
		"name": "lisi",
		"age": 18,
		"salary": 100.5,
		"blobType": new Uint8Array([1, 2, 3]),
	}
	await rdbStore.insert("test", valueBucket)
	rdbStore.commit()
})
```

### rollBack<sup>8+</sup>

rollBack():void

Rolls back the SQL statements that have been executed.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Example**

```js
import featureAbility from '@ohos.ability.featureAbility'
let context = featureAbility.getContext()
const STORE_CONFIG = { name: "RdbTest.db"}
data_rdb.getRdbStore(context, STORE_CONFIG, 1, async function (err, rdbStore) {
    try {
		rdbStore.beginTransaction()
		const valueBucket = {
			"id": 1,
			"name": "lisi",
			"age": 18,
			"salary": 100.5,
			"blobType": new Uint8Array([1, 2, 3]),
		}
		await rdbStore.insert("test", valueBucket)
		rdbStore.commit()
	} catch (e) {
		rdbStore.rollBack()
	}
})
```

### setDistributedTables<sup>8+</sup>

setDistributedTables(tables: Array&lt;string&gt;, callback: AsyncCallback&lt;void&gt;): void

Sets distributed tables. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.DISTRIBUTED_DATASYNC

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| tables | Array&lt;string&gt; | Yes| Names of the distributed tables to set.|
| callback | AsyncCallback&lt;void&gt; | Yes| Callback invoked to return the result.|

**Example**

```js
rdbStore.setDistributedTables(["EMPLOYEE"], function (err) {
    if (err) {
        console.info('Failed to set distributed tables, err: ' + err)
        return
    }
    console.info('Set distributed tables successfully.')
})
```

### setDistributedTables<sup>8+</sup>

 setDistributedTables(tables: Array&lt;string&gt;): Promise&lt;void&gt;

Sets distributed tables. This API uses a promise to return the result.

**Required permissions**: ohos.permission.DISTRIBUTED_DATASYNC

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| tables | Array&lt;string&gt; | Yes| Names of the distributed tables to set.|

**Return value**

| Type| Description|
| -------- | -------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Example**

```js
let promise = rdbStore.setDistributedTables(["EMPLOYEE"])
promise.then(() => {
    console.info("Set distributed tables successfully.")
}).catch((err) => {
    console.info("Failed to set distributed tables, err: " + err)
})
```

### obtainDistributedTableName<sup>8+</sup>

obtainDistributedTableName(device: string, table: string, callback: AsyncCallback&lt;string&gt;): void

Obtains the distributed table name of a remote device based on the local table name of the device. The distributed table name is required when the RDB store of a remote device is queried.

> **NOTE**
>
> The value of **device** is obtained by [deviceManager.getTrustedDeviceListSync](js-apis-device-manager.md#gettrusteddevicelistsync). The APIs of the **deviceManager** module are system interfaces and available only to system applications. 

**Required permissions**: ohos.permission.DISTRIBUTED_DATASYNC

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| device | string | Yes| ID of the remote device.|
| table | string | Yes| Local table name of the remote device.|
| callback | AsyncCallback&lt;string&gt; | Yes| Callback invoked to return the result. If the operation succeeds, the distributed table name of the remote device is returned.|

**Example**

```js
import deviceManager from '@ohos.distributedHardware.deviceManager';
let dmInstance = null;
let deviceId = null;

deviceManager.createDeviceManager("com.example.appdatamgrverify", (err, manager) => {
    if (err) {
        console.log("create device manager failed, err=" + err);
        return;
    }
    dmInstance = manager;
    let devices = dmInstance.getTrustedDeviceListSync();
    deviceId = devices[0].deviceId;
})


rdbStore.obtainDistributedTableName(deviceId, "EMPLOYEE", function (err, tableName) {
    if (err) {
        console.info('Failed to obtain DistributedTableName, err: ' + err)
        return
    }
    console.info('Obtained distributed table name successfully, tableName=.' + tableName)
})
```

### obtainDistributedTableName<sup>8+</sup>

 obtainDistributedTableName(device: string, table: string): Promise&lt;string&gt;

Obtains the distributed table name of a remote device based on the local table name of the device. The distributed table name is required when the RDB store of a remote device is queried.

> **NOTE**
>
> The value of **device** is obtained by [deviceManager.getTrustedDeviceListSync](js-apis-device-manager.md#gettrusteddevicelistsync). The APIs of the **deviceManager** module are system interfaces and available only to system applications. 

**Required permissions**: ohos.permission.DISTRIBUTED_DATASYNC

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| device | string | Yes| ID of the remote device.|
| table | string | Yes| Local table name of the remote device.|

**Return value**

| Type| Description|
| -------- | -------- |
| Promise&lt;string&gt; | Promise used to return the result. If the operation succeeds, the distributed table name of the remote device is returned.|

**Example**

```js
import deviceManager from '@ohos.distributedHardware.deviceManager';
let dmInstance = null;
let deviceId = null;

deviceManager.createDeviceManager("com.example.appdatamgrverify", (err, manager) => {
    if (err) {
        console.log("create device manager failed, err=" + err);
        return;
    }
    dmInstance = manager;
    let devices = dmInstance.getTrustedDeviceListSync();
    deviceId = devices[0].deviceId;
})

let promise = rdbStore.obtainDistributedTableName(deviceId, "EMPLOYEE")
promise.then((tableName) => {
    console.info('Obtained distributed table name successfully, tableName= ' + tableName)
}).catch((err) => {
    console.info('Failed to obtain DistributedTableName, err: ' + err)
})
```

### sync<sup>8+</sup>

sync(mode: SyncMode, predicates: RdbPredicates, callback: AsyncCallback&lt;Array&lt;[string, number]&gt;&gt;): void

Synchronizes data between devices. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.DISTRIBUTED_DATASYNC

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| mode | [SyncMode](#syncmode8) | Yes| Data synchronization mode. The value can be **push** or **pull**.|
| predicates | [RdbPredicates](#rdbpredicates) | Yes| **RdbPredicates** object that specifies the data and devices to synchronize.|
| callback | AsyncCallback&lt;Array&lt;[string, number]&gt;&gt; | Yes| Callback invoked to send the synchronization result to the caller. <br>**string** indicates the device ID. <br>**number** indicates the synchronization status of that device. The value **0** indicates a successful synchronization. Other values indicate a synchronization failure. |

**Example**

```js
import deviceManager from '@ohos.distributedHardware.deviceManager';
let dmInstance = null;
let deviceIds = [];

deviceManager.createDeviceManager("com.example.appdatamgrverify", (err, manager) => {
    if (err) {
        console.log("create device manager failed, err=" + err);
        return;
    }
    dmInstance = manager;
    let devices = dmInstance.getTrustedDeviceListSync();
    for (var i = 0; i < devices.length; i++) {
        deviceIds[i] = devices[i].deviceId;
    }
})

let predicates = new data_rdb.RdbPredicates('EMPLOYEE')
predicates.inDevices(deviceIds)
rdbStore.sync(data_rdb.SyncMode.SYNC_MODE_PUSH, predicates, function (err, result) {
    if (err) {
        console.log('Sync failed, err: ' + err)
        return
    }
    console.log('Sync done.')
    for (let i = 0; i < result.length; i++) {
        console.log('device=' + result[i][0] + ' status=' + result[i][1])
    }
})
```

### sync<sup>8+</sup>

 sync(mode: SyncMode, predicates: RdbPredicates): Promise&lt;Array&lt;[string, number]&gt;&gt;

Synchronizes data between devices. This API uses a promise to return the result.

**Required permissions**: ohos.permission.DISTRIBUTED_DATASYNC

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| mode | [SyncMode](#syncmode8) | Yes| Data synchronization mode. The value can be **push** or **pull**.|
| predicates | [RdbPredicates](#rdbpredicates) | Yes| **RdbPredicates** object that specifies the data and devices to synchronize.|

**Return value**

| Type| Description|
| -------- | -------- |
| Promise&lt;Array&lt;[string, number]&gt;&gt; | Promise used to return the synchronization result. <br>**string** indicates the device ID. <br>**number** indicates the synchronization status of that device. The value **0** indicates a successful synchronization. Other values indicate a synchronization failure. |

**Example**

```js
import deviceManager from '@ohos.distributedHardware.deviceManager';
let dmInstance = null;
let deviceIds = [];

deviceManager.createDeviceManager("com.example.appdatamgrverify", (err, manager) => {
    if (err) {
        console.log("create device manager failed, err=" + err);
        return;
    }
    dmInstance = manager;
    let devices = dmInstance.getTrustedDeviceListSync();
    for (var i = 0; i < devices.length; i++) {
        deviceIds[i] = devices[i].deviceId;
    }
})

let predicates = new data_rdb.RdbPredicates('EMPLOYEE')
predicates.inDevices(deviceIds)
let promise = rdbStore.sync(data_rdb.SyncMode.SYNC_MODE_PUSH, predicates)
promise.then((result) =>{
    console.log('Sync done.')
    for (let i = 0; i < result.length; i++) {
        console.log('device=' + result[i][0] + ' status=' + result[i][1])
    }
}).catch((err) => {
    console.log('Sync failed')
})
```

### on('dataChange')<sup>8+</sup>

on(event: 'dataChange', type: SubscribeType, observer: Callback&lt;Array&lt;string&gt;&gt;): void

Registers an observer for this RDB store. When the data in the RDB store changes, a callback is invoked to return the data changes.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| event | string | Yes| The value is'dataChange', which indicates a data change event.|
| type | [SubscribeType](#subscribetype8) | Yes| Subscription type to register.|
| observer | Callback&lt;Array&lt;string&gt;&gt; | Yes| Observer that listens for the data changes in the RDB store. **Array<string>** indicates the IDs of the peer devices whose data in the database is changed.|

**Example**

```js
function storeObserver(devices) {
    for (let i = 0; i < devices.length; i++) {
        console.log('device=' + devices[i] + ' data changed')
    }
}
try {
    rdbStore.on('dataChange', data_rdb.SubscribeType.SUBSCRIBE_TYPE_REMOTE, storeObserver)
} catch (err) {
    console.log('Failed to register observer')
}
```

### off('dataChange')<sup>8+</sup>

off(event:'dataChange', type: SubscribeType, observer: Callback&lt;Array&lt;string&gt;&gt;): void

Unregisters the observer of the specified type from the RDB store. This API uses a callback to return the result.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| event | string | Yes| The value is'dataChange', which indicates a data change event.|
| type | [SubscribeType](#subscribetype8)    | Yes| Subscription type to unregister.|
| observer | Callback&lt;Array&lt;string&gt;&gt; | Yes| Data change observer to unregister. **Array<string>** indicates the IDs of the peer devices whose data in the database is changed.|

**Example**

```js
function storeObserver(devices) {
    for (let i = 0; i < devices.length; i++) {
        console.log('device=' + devices[i] + ' data changed')
    }
}
try {
    rdbStore.off('dataChange', data_rdb.SubscribeType.SUBSCRIBE_TYPE_REMOTE, storeObserver)
} catch (err) {
    console.log('Failed to unregister observer')
}
```
