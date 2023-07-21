# @ohos.data.relationalStore (RDB Store)

The relational database (RDB) store manages data based on relational models. With the underlying SQLite database, the RDB store provides a complete mechanism for managing local databases. To satisfy different needs in complicated scenarios, the RDB store offers a series of APIs for performing operations such as adding, deleting, modifying, and querying data, and supports direct execution of SQL statements. The worker threads are not supported.

The **relationalStore** module provides the following functions:

- [RdbPredicates](#rdbpredicates): provides predicates indicating the nature, feature, or relationship of a data entity in an RDB store. It is used to define the operation conditions for an RDB store.
- [RdbStore](#rdbstore): provides APIs for managing data in an RDB store.
- [Resultset](#resultset): provides APIs for accessing the result set obtained from the RDB store. 

> **NOTE**
> 
> The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```js
import relationalStore from '@ohos.data.relationalStore'
```

## relationalStore.getRdbStore

getRdbStore(context: Context, config: StoreConfig, callback: AsyncCallback&lt;RdbStore&gt;): void

Obtains an RDB store. This API uses an asynchronous callback to return the result. You can set parameters for the RDB store based on service requirements and call APIs to perform data operations.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Parameters**

| Name  | Type                                          | Mandatory| Description                                                        |
| -------- | ---------------------------------------------- | ---- | ------------------------------------------------------------ |
| context  | Context                                        | Yes  | Application context.<br>For details about the application context of the FA model, see [Context](js-apis-inner-app-context.md).<br>For details about the application context of the stage model, see [Context](js-apis-inner-application-uiAbilityContext.md).|
| config   | [StoreConfig](#storeconfig)               | Yes  | Configuration of the RDB store.                               |
| callback | AsyncCallback&lt;[RdbStore](#rdbstore)&gt; | Yes  | Callback invoked to return the RDB store obtained.                  |

**Error codes**

For details about the error codes, see [RDB Error Codes](../errorcodes/errorcode-data-rdb.md).

| **ID**| **Error Message**                                     |
| ------------ | ------------------------------------------------- |
| 14800010     | Failed to open or delete database by invalid database path. |
| 14800011     | Failed open database, database corrupted.         |
| 14800000     | The inner error is occurred.                      |

**Example**

FA model:

```js

import featureAbility from '@ohos.ability.featureAbility'

var store;

// Obtain the context.
let context = featureAbility.getContext();

const STORE_CONFIG = {
  name: "RdbTest.db",
  securityLevel: relationalStore.SecurityLevel.S1
};

relationalStore.getRdbStore(context, STORE_CONFIG, function (err, rdbStore) {
  store = rdbStore;
  if (err) {
    console.error(`Get RdbStore failed, code is ${err.code},message is ${err.message}`);
    return;
  }
  console.info(`Get RdbStore successfully.`);
})
```

Stage model:

```ts
import UIAbility from '@ohos.app.ability.UIAbility'

class EntryAbility extends UIAbility {
  onWindowStageCreate(windowStage) {
    var store;
    const STORE_CONFIG = {
      name: "RdbTest.db",
      securityLevel: relationalStore.SecurityLevel.S1
    };
        
    relationalStore.getRdbStore(this.context, STORE_CONFIG, function (err, rdbStore) {
      store = rdbStore;
      if (err) {
        console.error(`Get RdbStore failed, code is ${err.code},message is ${err.message}`);
        return;
      }
      console.info(`Get RdbStore successfully.`);
    })
  }
}
```

## relationalStore.getRdbStore

getRdbStore(context: Context, config: StoreConfig): Promise&lt;RdbStore&gt;

Obtains an RDB store. This API uses a promise to return the result. You can set parameters for the RDB store based on service requirements and call APIs to perform data operations.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Parameters**

| Name | Type                            | Mandatory| Description                                                        |
| ------- | -------------------------------- | ---- | ------------------------------------------------------------ |
| context | Context                          | Yes  | Application context.<br>For details about the application context of the FA model, see [Context](js-apis-inner-app-context.md).<br>For details about the application context of the stage model, see [Context](js-apis-inner-application-uiAbilityContext.md).|
| config  | [StoreConfig](#storeconfig) | Yes  | Configuration of the RDB store.                               |

**Return value**

| Type                                     | Description                             |
| ----------------------------------------- | --------------------------------- |
| Promise&lt;[RdbStore](#rdbstore)&gt; | Promise used to return the **RdbStore** object.|

**Error codes**

For details about the error codes, see [RDB Error Codes](../errorcodes/errorcode-data-rdb.md).

| **ID**| **Error Message**                                     |
| ------------ | ------------------------------------------------- |
| 14800010     | Failed to open or delete database by invalid database path. |
| 14800011     | Failed open database, database corrupted.         |
| 14800000     | The inner error is occurred.                      |

**Example**

FA model:

```js
import featureAbility from '@ohos.ability.featureAbility'

var store;

// Obtain the context.
let context = featureAbility.getContext();

const STORE_CONFIG = {
  name: "RdbTest.db",
  securityLevel: relationalStore.SecurityLevel.S1
};

let promise = relationalStore.getRdbStore(context, STORE_CONFIG);
promise.then(async (rdbStore) => {
  store = rdbStore;
  console.info(`Get RdbStore successfully.`);
}).catch((err) => {
  console.error(`Get RdbStore failed, code is ${err.code},message is ${err.message}`);
})
```

Stage model:

```ts
import UIAbility from '@ohos.app.ability.UIAbility'

class EntryAbility extends UIAbility {
  onWindowStageCreate(windowStage) {
    var store;
    const STORE_CONFIG = {
      name: "RdbTest.db",
      securityLevel: relationalStore.SecurityLevel.S1
    };
        
    let promise = relationalStore.getRdbStore(this.context, STORE_CONFIG);
    promise.then(async (rdbStore) => {
      store = rdbStore;
      console.info(`Get RdbStore successfully.`)
    }).catch((err) => {
      console.error(`Get RdbStore failed, code is ${err.code},message is ${err.message}`);
    })
  }
}
```

## relationalStore.deleteRdbStore

deleteRdbStore(context: Context, name: string, callback: AsyncCallback&lt;void&gt;): void

Deletes an RDB store. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Parameters**

| Name  | Type                     | Mandatory| Description                                                        |
| -------- | ------------------------- | ---- | ------------------------------------------------------------ |
| context  | Context                   | Yes  | Application context.<br>For details about the application context of the FA model, see [Context](js-apis-inner-app-context.md).<br>For details about the application context of the stage model, see [Context](js-apis-inner-application-uiAbilityContext.md).|
| name     | string                    | Yes  | Name of the RDB store to delete.                                                |
| callback | AsyncCallback&lt;void&gt; | Yes  | Callback invoked to return the result.                                      |

**Error codes**

For details about the error codes, see [RDB Error Codes](../errorcodes/errorcode-data-rdb.md).

| **ID**| **Error Message**                                     |
| ------------ | ------------------------------------------------- |
| 14800010     | Failed to open or delete database by invalid database path. |
| 14800000     | The inner error is occurred.                      |

**Example**

FA model:

```js
import featureAbility from '@ohos.ability.featureAbility'

// Obtain the context.
let context = featureAbility.getContext()

relationalStore.deleteRdbStore(context, "RdbTest.db", function (err) {
  if (err) {
    console.error(`Delete RdbStore failed, code is ${err.code},message is ${err.message}`);
    return;
  }
  console.info(`Delete RdbStore successfully.`);
})
```

Stage model:

```ts
import UIAbility from '@ohos.app.ability.UIAbility'

class EntryAbility extends UIAbility {
  onWindowStageCreate(windowStage){
    relationalStore.deleteRdbStore(this.context, "RdbTest.db", function (err) {
      if (err) {
        console.error(`Delete RdbStore failed, code is ${err.code},message is ${err.message}`);
        return;
      }
      console.info(`Delete RdbStore successfully.`);
    })
  }
}
```

## relationalStore.deleteRdbStore

deleteRdbStore(context: Context, name: string): Promise&lt;void&gt;

Deletes an RDB store. This API uses a promise to return the result.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Parameters**

| Name | Type   | Mandatory| Description                                                        |
| ------- | ------- | ---- | ------------------------------------------------------------ |
| context | Context | Yes  | Application context.<br>For details about the application context of the FA model, see [Context](js-apis-inner-app-context.md).<br>For details about the application context of the stage model, see [Context](js-apis-inner-application-uiAbilityContext.md).|
| name    | string  | Yes  | Name of the RDB store to delete.                                                |

**Return value**

| Type               | Description                     |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [RDB Error Codes](../errorcodes/errorcode-data-rdb.md).

| **ID**| **Error Message**                                     |
| ------------ | ------------------------------------------------- |
| 14800010     | Failed to open or delete database by invalid database path. |
| 14800000     | The inner error is occurred.                      |

**Example**

FA model:

```js
import featureAbility from '@ohos.ability.featureAbility'

// Obtain the context.
let context = featureAbility.getContext();

let promise = relationalStore.deleteRdbStore(context, "RdbTest.db");
promise.then(()=>{
  console.info(`Delete RdbStore successfully.`);
}).catch((err) => {
  console.error(`Delete RdbStore failed, code is ${err.code},message is ${err.message}`);
})
```

Stage model:

```ts
import UIAbility from '@ohos.app.ability.UIAbility'

class EntryAbility extends UIAbility {
  onWindowStageCreate(windowStage){
    let promise = relationalStore.deleteRdbStore(this.context, "RdbTest.db");
    promise.then(()=>{
      console.info(`Delete RdbStore successfully.`);
    }).catch((err) => {
      console.error(`Delete RdbStore failed, code is ${err.code},message is ${err.message}`);
    })
  }
}
```

## StoreConfig

Defines the RDB store configuration.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

| Name       | Type         | Mandatory| Description                                                     |
| ------------- | ------------- | ---- | --------------------------------------------------------- |
| name          | string        | Yes  | Database file name.                                           |
| securityLevel | [SecurityLevel](#securitylevel) | Yes  | Security level of the RDB store.                                       |
| encrypt       | boolean       | No  | Whether to encrypt the RDB store.<br> The value **true** means to encrypt the RDB store;<br> the value **false** (default) means the opposite.|

## SecurityLevel

Enumerates the RDB store security levels.

> **NOTE**
>
> To perform data synchronization operations, the RDB store security level must be lower than or equal to that of the peer device. For details, see the [Cross-Device Data Synchronization Mechanism]( ../../database/sync-app-data-across-devices-overview.md#cross-device-data-synchronization-mechanism).

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

| Name| Value  | Description                                                        |
| ---- | ---- | ------------------------------------------------------------ |
| S1   | 1    | The RDB store security level is low. If data leakage occurs, minor impact will be caused on the database. For example, an RDB store that contains system data such as wallpapers.|
| S2   | 2    | The RDB store security level is medium. If data leakage occurs, moderate impact will be caused on the database. For example, an RDB store that contains information created by users or call records, such as audio or video clips.|
| S3   | 3    | The RDB store security level is high. If data leakage occurs, major impact will be caused on the database. For example, an RDB store that contains information such as user fitness, health, and location data.|
| S4   | 4    | The RDB store security level is critical. If data leakage occurs, severe impact will be caused on the database. For example, an RDB store that contains information such as authentication credentials and financial data.|

## ValueType

Defines the data types allowed.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

| Type   | Description                |
| ------- | -------------------- |
| number  | Number.  |
| string  | String.  |
| boolean | Boolean.|

## ValuesBucket

Defines the types of the key and value in a KV pair. This type is not multi-thread safe. If a **ValuesBucket** instance is operated by multiple threads at the same time in an application, use a lock for the instance.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

| Key Type| Value Type                                                     |
| ------ | ----------------------------------------------------------- |
| string | [ValueType](#valuetype)\|&nbsp;Uint8Array&nbsp;\|&nbsp;null |

## SyncMode

Defines the database synchronization mode.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

| Name          | Value  | Description                              |
| -------------- | ---- | ---------------------------------- |
| SYNC_MODE_PUSH | 0    | Data is pushed from a local device to a remote device.|
| SYNC_MODE_PULL | 1    | Data is pulled from a remote device to a local device.  |

## SubscribeType

Defines the subscription type.

**Required permissions**: ohos.permission.DISTRIBUTED_DATASYNC

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

| Name                 | Value  | Description              |
| --------------------- | ---- | ------------------ |
| SUBSCRIBE_TYPE_REMOTE | 0    | Subscribe to remote data changes.|

## RdbPredicates

Defines the predicates for an RDB store. This class determines whether the conditional expression for the RDB store is true or false. This type is not multi-thread safe. If an **RdbPredicates** instance is operated by multiple threads at the same time in an application, use a lock for the instance.

### constructor

constructor(name: string)

A constructor used to create an **RdbPredicates** object.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Parameters**

| Name| Type  | Mandatory| Description        |
| ------ | ------ | ---- | ------------ |
| name   | string | Yes  | Database table name.|

**Example**

```js
let predicates = new relationalStore.RdbPredicates("EMPLOYEE");
```

### inDevices

inDevices(devices: Array&lt;string&gt;): RdbPredicates

Sets an **RdbPredicates** to specify the remote devices to connect on the network during distributed database synchronization.

> **NOTE**
>
> The value of **devices** is obtained by [deviceManager.getTrustedDeviceListSync](js-apis-device-manager.md#gettrusteddevicelistsync). The APIs of the **deviceManager** module are system interfaces and available only to system applications.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Parameters**

| Name | Type               | Mandatory| Description                      |
| ------- | ------------------- | ---- | -------------------------- |
| devices | Array&lt;string&gt; | Yes  | IDs of the remote devices in the same network.|

**Return value**

| Type                                | Description                      |
| ------------------------------------ | -------------------------- |
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
                                  
let predicates = new relationalStore.RdbPredicates("EMPLOYEE");
predicates.inDevices(deviceIds);
```

### inAllDevices

inAllDevices(): RdbPredicates


Sets an **RdbPredicates** to specify all remote devices on the network to connect during distributed database synchronization.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Return value**

| Type                                | Description                      |
| ------------------------------------ | -------------------------- |
| [RdbPredicates](#rdbpredicates) | **RdbPredicates** object created.|

**Example**

```js
let predicates = new relationalStore.RdbPredicates("EMPLOYEE");
predicates.inAllDevices();
```

### equalTo

equalTo(field: string, value: ValueType): RdbPredicates


Sets an **RdbPredicates** to match the field with data type **ValueType** and value equal to the specified value.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Parameters**

| Name| Type                   | Mandatory| Description                  |
| ------ | ----------------------- | ---- | ---------------------- |
| field  | string                  | Yes  | Column name in the database table.    |
| value  | [ValueType](#valuetype) | Yes  | Value to match the **RdbPredicates**.|

**Return value**

| Type                                | Description                      |
| ------------------------------------ | -------------------------- |
| [RdbPredicates](#rdbpredicates) | **RdbPredicates** object created.|

**Example**

```js
let predicates = new relationalStore.RdbPredicates("EMPLOYEE");
predicates.equalTo("NAME", "lisi");
```


### notEqualTo

notEqualTo(field: string, value: ValueType): RdbPredicates


Sets an **RdbPredicates** to match the field with data type **ValueType** and value not equal to the specified value.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Parameters**

| Name| Type                   | Mandatory| Description                  |
| ------ | ----------------------- | ---- | ---------------------- |
| field  | string                  | Yes  | Column name in the database table.    |
| value  | [ValueType](#valuetype) | Yes  | Value to match the **RdbPredicates**.|

**Return value**

| Type                                | Description                      |
| ------------------------------------ | -------------------------- |
| [RdbPredicates](#rdbpredicates) | **RdbPredicates** object created.|

**Example**

```js
let predicates = new relationalStore.RdbPredicates("EMPLOYEE");
predicates.notEqualTo("NAME", "lisi");
```


### beginWrap

beginWrap(): RdbPredicates


Adds a left parenthesis to the **RdbPredicates**.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Return value**

| Type                                | Description                     |
| ------------------------------------ | ------------------------- |
| [RdbPredicates](#rdbpredicates) | **RdbPredicates** with a left parenthesis.|

**Example**

```js
let predicates = new relationalStore.RdbPredicates("EMPLOYEE");
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

| Type                                | Description                     |
| ------------------------------------ | ------------------------- |
| [RdbPredicates](#rdbpredicates) | **RdbPredicates** with a right parenthesis.|

**Example**

```js
let predicates = new relationalStore.RdbPredicates("EMPLOYEE");
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

| Type                                | Description                     |
| ------------------------------------ | ------------------------- |
| [RdbPredicates](#rdbpredicates) | **RdbPredicates** with the OR condition.|

**Example**

```js
let predicates = new relationalStore.RdbPredicates("EMPLOYEE");
predicates.equalTo("NAME", "Lisa")
    .or()
    .equalTo("NAME", "Rose")
```

### and

and(): RdbPredicates

Adds the AND condition to the **RdbPredicates**.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Return value**

| Type                                | Description                     |
| ------------------------------------ | ------------------------- |
| [RdbPredicates](#rdbpredicates) | **RdbPredicates** with the AND condition.|

**Example**

```js
let predicates = new relationalStore.RdbPredicates("EMPLOYEE");
predicates.equalTo("NAME", "Lisa")
    .and()
    .equalTo("SALARY", 200.5)
```

### contains

contains(field: string, value: string): RdbPredicates

Sets an **RdbPredicates** to match a string containing the specified value.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Parameters**

| Name| Type  | Mandatory| Description                  |
| ------ | ------ | ---- | ---------------------- |
| field  | string | Yes  | Column name in the database table.    |
| value  | string | Yes  | Value to match the **RdbPredicates**.|

**Return value**

| Type                                | Description                      |
| ------------------------------------ | -------------------------- |
| [RdbPredicates](#rdbpredicates) | **RdbPredicates** object created.|

**Example**

```js
let predicates = new relationalStore.RdbPredicates("EMPLOYEE");
predicates.contains("NAME", "os");
```

### beginsWith

beginsWith(field: string, value: string): RdbPredicates

Sets an **RdbPredicates** to match a string that starts with the specified value.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Parameters**

| Name| Type  | Mandatory| Description                  |
| ------ | ------ | ---- | ---------------------- |
| field  | string | Yes  | Column name in the database table.    |
| value  | string | Yes  | Value to match the **RdbPredicates**.|

**Return value**

| Type                                | Description                      |
| ------------------------------------ | -------------------------- |
| [RdbPredicates](#rdbpredicates) | **RdbPredicates** object created.|

**Example**

```js
let predicates = new relationalStore.RdbPredicates("EMPLOYEE");
predicates.beginsWith("NAME", "os");
```

### endsWith

endsWith(field: string, value: string): RdbPredicates

Sets an **RdbPredicates** to match a string that ends with the specified value.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Parameters**

| Name| Type  | Mandatory| Description                  |
| ------ | ------ | ---- | ---------------------- |
| field  | string | Yes  | Column name in the database table.    |
| value  | string | Yes  | Value to match the **RdbPredicates**.|

**Return value**

| Type                                | Description                      |
| ------------------------------------ | -------------------------- |
| [RdbPredicates](#rdbpredicates) | **RdbPredicates** object created.|

**Example**

```js
let predicates = new relationalStore.RdbPredicates("EMPLOYEE");
predicates.endsWith("NAME", "se");
```

### isNull

isNull(field: string): RdbPredicates

Sets an **RdbPredicates** to match the field whose value is null.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Parameters**

| Name| Type  | Mandatory| Description              |
| ------ | ------ | ---- | ------------------ |
| field  | string | Yes  | Column name in the database table.|

**Return value**

| Type                                | Description                      |
| ------------------------------------ | -------------------------- |
| [RdbPredicates](#rdbpredicates) | **RdbPredicates** object created.|

**Example**

```js
let predicates = new relationalStore.RdbPredicates("EMPLOYEE");
predicates.isNull("NAME");
```

### isNotNull

isNotNull(field: string): RdbPredicates

Sets an **RdbPredicates** to match the field whose value is not null.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Parameters**

| Name| Type  | Mandatory| Description              |
| ------ | ------ | ---- | ------------------ |
| field  | string | Yes  | Column name in the database table.|

**Return value**

| Type                                | Description                      |
| ------------------------------------ | -------------------------- |
| [RdbPredicates](#rdbpredicates) | **RdbPredicates** object created.|

**Example**

```js
let predicates = new relationalStore.RdbPredicates("EMPLOYEE");
predicates.isNotNull("NAME");
```

### like

like(field: string, value: string): RdbPredicates

Sets an **RdbPredicates** to match a string that is similar to the specified value.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Parameters**

| Name| Type  | Mandatory| Description                  |
| ------ | ------ | ---- | ---------------------- |
| field  | string | Yes  | Column name in the database table.    |
| value  | string | Yes  | Value to match the **RdbPredicates**.|

**Return value**

| Type                                | Description                      |
| ------------------------------------ | -------------------------- |
| [RdbPredicates](#rdbpredicates) | **RdbPredicates** object created.|

**Example**

```js
let predicates = new relationalStore.RdbPredicates("EMPLOYEE");
predicates.like("NAME", "%os%");
```

### glob

glob(field: string, value: string): RdbPredicates

Sets an **RdbPredicates** to match the specified string.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Parameters**

| Name| Type  | Mandatory| Description                                                        |
| ------ | ------ | ---- | ------------------------------------------------------------ |
| field  | string | Yes  | Column name in the database table.                                          |
| value  | string | Yes  | Value to match the **RdbPredicates**.<br><br>Wildcards are supported. * indicates zero, one, or multiple digits or characters. **?** indicates a single digit or character.|

**Return value**

| Type                                | Description                      |
| ------------------------------------ | -------------------------- |
| [RdbPredicates](#rdbpredicates) | **RdbPredicates** object created.|

**Example**

```js
let predicates = new relationalStore.RdbPredicates("EMPLOYEE");
predicates.glob("NAME", "?h*g");
```

### between

between(field: string, low: ValueType, high: ValueType): RdbPredicates

Sets an **RdbPredicates** to match the field with data type **ValueType** and value within the specified range.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Parameters**

| Name| Type                   | Mandatory| Description                      |
| ------ | ----------------------- | ---- | -------------------------- |
| field  | string                  | Yes  | Column name in the database table.        |
| low    | [ValueType](#valuetype) | Yes  | Minimum value to match the **RdbPredicates**.  |
| high   | [ValueType](#valuetype) | Yes  | Maximum value to match the **RdbPredicates**.|

**Return value**

| Type                                | Description                      |
| ------------------------------------ | -------------------------- |
| [RdbPredicates](#rdbpredicates) | **RdbPredicates** object created.|

**Example**

```js
let predicates = new relationalStore.RdbPredicates("EMPLOYEE");
predicates.between("AGE", 10, 50);
```

### notBetween

notBetween(field: string, low: ValueType, high: ValueType): RdbPredicates

Sets an **RdbPredicates** to match the field with data type **ValueType** and value out of the specified range.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Parameters**

| Name| Type                   | Mandatory| Description                      |
| ------ | ----------------------- | ---- | -------------------------- |
| field  | string                  | Yes  | Column name in the database table.        |
| low    | [ValueType](#valuetype) | Yes  | Minimum value to match the **RdbPredicates**.  |
| high   | [ValueType](#valuetype) | Yes  | Maximum value to match the **RdbPredicates**.|

**Return value**

| Type                                | Description                      |
| ------------------------------------ | -------------------------- |
| [RdbPredicates](#rdbpredicates) | **RdbPredicates** object created.|

**Example**

```js
let predicates = new relationalStore.RdbPredicates("EMPLOYEE");
predicates.notBetween("AGE", 10, 50);
```

### greaterThan

greaterThan(field: string, value: ValueType): RdbPredicates

Sets an **RdbPredicates** to match the field with data type **ValueType** and value greater than the specified value.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Parameters**

| Name| Type                   | Mandatory| Description                  |
| ------ | ----------------------- | ---- | ---------------------- |
| field  | string                  | Yes  | Column name in the database table.    |
| value  | [ValueType](#valuetype) | Yes  | Value to match the **RdbPredicates**.|

**Return value**

| Type                                | Description                      |
| ------------------------------------ | -------------------------- |
| [RdbPredicates](#rdbpredicates) | **RdbPredicates** object created.|

**Example**

```js
let predicates = new relationalStore.RdbPredicates("EMPLOYEE");
predicates.greaterThan("AGE", 18);
```

### lessThan

lessThan(field: string, value: ValueType): RdbPredicates

Sets an **RdbPredicates** to match the field with data type **ValueType** and value less than the specified value.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Parameters**

| Name| Type                   | Mandatory| Description                  |
| ------ | ----------------------- | ---- | ---------------------- |
| field  | string                  | Yes  | Column name in the database table.    |
| value  | [ValueType](#valuetype) | Yes  | Value to match the **RdbPredicates**.|

**Return value**

| Type                                | Description                      |
| ------------------------------------ | -------------------------- |
| [RdbPredicates](#rdbpredicates) | **RdbPredicates** object created.|

**Example**

```js
let predicates = new relationalStore.RdbPredicates("EMPLOYEE");
predicates.lessThan("AGE", 20);
```

### greaterThanOrEqualTo

greaterThanOrEqualTo(field: string, value: ValueType): RdbPredicates

Sets an **RdbPredicates** to match the field with data type **ValueType** and value greater than or equal to the specified value.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Parameters**

| Name| Type                   | Mandatory| Description                  |
| ------ | ----------------------- | ---- | ---------------------- |
| field  | string                  | Yes  | Column name in the database table.    |
| value  | [ValueType](#valuetype) | Yes  | Value to match the **RdbPredicates**.|

**Return value**

| Type                                | Description                      |
| ------------------------------------ | -------------------------- |
| [RdbPredicates](#rdbpredicates) | **RdbPredicates** object created.|

**Example**

```js
let predicates = new relationalStore.RdbPredicates("EMPLOYEE");
predicates.greaterThanOrEqualTo("AGE", 18);
```

### lessThanOrEqualTo

lessThanOrEqualTo(field: string, value: ValueType): RdbPredicates

Sets an **RdbPredicates** to match the field with data type **ValueType** and value less than or equal to the specified value.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Parameters**

| Name| Type                   | Mandatory| Description                  |
| ------ | ----------------------- | ---- | ---------------------- |
| field  | string                  | Yes  | Column name in the database table.    |
| value  | [ValueType](#valuetype) | Yes  | Value to match the **RdbPredicates**.|

**Return value**

| Type                                | Description                      |
| ------------------------------------ | -------------------------- |
| [RdbPredicates](#rdbpredicates) | **RdbPredicates** object created.|

**Example**

```js
let predicates = new relationalStore.RdbPredicates("EMPLOYEE");
predicates.lessThanOrEqualTo("AGE", 20);
```

### orderByAsc

orderByAsc(field: string): RdbPredicates

Sets an **RdbPredicates** to match the column with values sorted in ascending order.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Parameters**

| Name| Type  | Mandatory| Description              |
| ------ | ------ | ---- | ------------------ |
| field  | string | Yes  | Column name in the database table.|

**Return value**

| Type                                | Description                      |
| ------------------------------------ | -------------------------- |
| [RdbPredicates](#rdbpredicates) | **RdbPredicates** object created.|

**Example**

```js
let predicates = new relationalStore.RdbPredicates("EMPLOYEE");
predicates.orderByAsc("NAME");
```

### orderByDesc

orderByDesc(field: string): RdbPredicates

Sets an **RdbPredicates** to match the column with values sorted in descending order.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Parameters**

| Name| Type  | Mandatory| Description              |
| ------ | ------ | ---- | ------------------ |
| field  | string | Yes  | Column name in the database table.|

**Return value**

| Type                                | Description                      |
| ------------------------------------ | -------------------------- |
| [RdbPredicates](#rdbpredicates) | **RdbPredicates** object created.|

**Example**

```js
let predicates = new relationalStore.RdbPredicates("EMPLOYEE");
predicates.orderByDesc("AGE");
```

### distinct

distinct(): RdbPredicates

Sets an **RdbPredicates** to filter out duplicate records.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Return value**

| Type                                | Description                          |
| ------------------------------------ | ------------------------------ |
| [RdbPredicates](#rdbpredicates) | **RdbPredicates** object that can filter out duplicate records.|

**Example**

```js
let predicates = new relationalStore.RdbPredicates("EMPLOYEE");
predicates.equalTo("NAME", "Rose").distinct();
```

### limitAs

limitAs(value: number): RdbPredicates

Sets an **RdbPredicates** to specify the maximum number of records.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Parameters**

| Name| Type  | Mandatory| Description            |
| ------ | ------ | ---- | ---------------- |
| value  | number | Yes  | Maximum number of records.|

**Return value**

| Type                                | Description                                |
| ------------------------------------ | ------------------------------------ |
| [RdbPredicates](#rdbpredicates) | **RdbPredicates** object that specifies the maximum number of records.|

**Example**

```js
let predicates = new relationalStore.RdbPredicates("EMPLOYEE");
predicates.equalTo("NAME", "Rose").limitAs(3);
```

### offsetAs

offsetAs(rowOffset: number): RdbPredicates

Sets an **RdbPredicates** to specify the start position of the returned result.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Parameters**

| Name   | Type  | Mandatory| Description                              |
| --------- | ------ | ---- | ---------------------------------- |
| rowOffset | number | Yes  | Number of rows to offset from the beginning. The value is a positive integer.|

**Return value**

| Type                                | Description                                |
| ------------------------------------ | ------------------------------------ |
| [RdbPredicates](#rdbpredicates) | **RdbPredicates** object that specifies the start position of the returned result.|

**Example**

```js
let predicates = new relationalStore.RdbPredicates("EMPLOYEE");
predicates.equalTo("NAME", "Rose").offsetAs(3);
```

### groupBy

groupBy(fields: Array&lt;string&gt;): RdbPredicates

Sets an **RdbPredicates** to group rows that have the same value into summary rows.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Parameters**

| Name| Type               | Mandatory| Description                |
| ------ | ------------------- | ---- | -------------------- |
| fields | Array&lt;string&gt; | Yes  | Names of columns to group.|

**Return value**

| Type                                | Description                  |
| ------------------------------------ | ---------------------- |
| [RdbPredicates](#rdbpredicates) | **RdbPredicates** object that groups rows with the same value.|

**Example**

```js
let predicates = new relationalStore.RdbPredicates("EMPLOYEE");
predicates.groupBy(["AGE", "NAME"]);
```

### indexedBy

indexedBy(field: string): RdbPredicates

Sets an **RdbPredicates** object to specify the index column.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Parameters**

| Name| Type  | Mandatory| Description          |
| ------ | ------ | ---- | -------------- |
| field  | string | Yes  | Name of the index column.|

**Return value**


| Type                                | Description                                 |
| ------------------------------------ | ------------------------------------- |
| [RdbPredicates](#rdbpredicates) | **RdbPredicates** object that specifies the index column.|

**Example**

```js
let predicates = new relationalStore.RdbPredicates("EMPLOYEE");
predicates.indexedBy("SALARY_INDEX");
```

### in

in(field: string, value: Array&lt;ValueType&gt;): RdbPredicates

Sets an **RdbPredicates** to match the field with data type **Array&#60;ValueType&#62;** and value within the specified range.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Parameters**

| Name| Type                                | Mandatory| Description                                   |
| ------ | ------------------------------------ | ---- | --------------------------------------- |
| field  | string                               | Yes  | Column name in the database table.                     |
| value  | Array&lt;[ValueType](#valuetype)&gt; | Yes  | Array of **ValueType**s to match.|

**Return value**

| Type                                | Description                      |
| ------------------------------------ | -------------------------- |
| [RdbPredicates](#rdbpredicates) | **RdbPredicates** object created.|

**Example**

```js
let predicates = new relationalStore.RdbPredicates("EMPLOYEE");
predicates.in("AGE", [18, 20]);
```

### notIn

notIn(field: string, value: Array&lt;ValueType&gt;): RdbPredicates

Sets an **RdbPredicates** to match the field with data type **Array&#60;ValueType&#62;** and value out of the specified range.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Parameters**

| Name| Type                                | Mandatory| Description                                 |
| ------ | ------------------------------------ | ---- | ------------------------------------- |
| field  | string                               | Yes  | Column name in the database table.                   |
| value  | Array&lt;[ValueType](#valuetype)&gt; | Yes  | Array of **ValueType**s to match.|

**Return value**

| Type                                | Description                      |
| ------------------------------------ | -------------------------- |
| [RdbPredicates](#rdbpredicates) | **RdbPredicates** object created.|

**Example**

```js
let predicates = new relationalStore.RdbPredicates("EMPLOYEE");
predicates.notIn("NAME", ["Lisa", "Rose"]);
```

## RdbStore

Provides APIs to manage an RDB store.

Before using the APIs of this class, use [executeSql](#executesql) to initialize the database table structure and related data.

### insert

insert(table: string, values: ValuesBucket, callback: AsyncCallback&lt;number&gt;):void

Inserts a row of data into a table. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Parameters**

| Name  | Type                         | Mandatory| Description                                                      |
| -------- | ----------------------------- | ---- | ---------------------------------------------------------- |
| table    | string                        | Yes  | Name of the target table.                                          |
| values   | [ValuesBucket](#valuesbucket) | Yes  | Row of data to insert.                                |
| callback | AsyncCallback&lt;number&gt;   | Yes  | Callback invoked to return the result. If the operation is successful, the row ID will be returned. Otherwise, **-1** will be returned.|

**Example**

```js
const valueBucket = {
  "NAME": "Lisa",
  "AGE": 18,
  "SALARY": 100.5,
  "CODES": new Uint8Array([1, 2, 3, 4, 5]),
};
store.insert("EMPLOYEE", valueBucket, function (err, rowId) {
  if (err) {
    console.error(`Insert is failed, code is ${err.code},message is ${err.message}`);
    return;
  }
  console.info(`Insert is successful, rowId = ${rowId}`);
})
```


### insert

insert(table: string, values: ValuesBucket):Promise&lt;number&gt;

Inserts a row of data into a table. This API uses a promise to return the result.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Parameters**

| Name| Type                         | Mandatory| Description                      |
| ------ | ----------------------------- | ---- | -------------------------- |
| table  | string                        | Yes  | Name of the target table.          |
| values | [ValuesBucket](#valuesbucket) | Yes  | Row of data to insert.|

**Return value**

| Type                 | Description                                             |
| --------------------- | ------------------------------------------------- |
| Promise&lt;number&gt; | Promise used to return the result. If the operation is successful, the row ID will be returned. Otherwise, **-1** will be returned.|

**Error codes**

For details about the error codes, see [RDB Error Codes](../errorcodes/errorcode-data-rdb.md).

| **ID**| **Error Message**                                |
| ------------ | -------------------------------------------- |
| 14800000     | The inner error is occurred.                 |

**Example**

```js
const valueBucket = {
  "NAME": "Lisa",
  "AGE": 18,
  "SALARY": 100.5,
  "CODES": new Uint8Array([1, 2, 3, 4, 5]),
};
let promise = store.insert("EMPLOYEE", valueBucket);
promise.then((rowId) => {
  console.info(`Insert is successful, rowId = ${rowId}`);
}).catch((err) => {
  console.error(`Insert is failed, code is ${err.code},message is ${err.message}`);
})
```


### batchInsert

batchInsert(table: string, values: Array&lt;ValuesBucket&gt;, callback: AsyncCallback&lt;number&gt;):void

Batch inserts data into a table. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Parameters**

| Name  | Type                                      | Mandatory| Description                                                        |
| -------- | ------------------------------------------ | ---- | ------------------------------------------------------------ |
| table    | string                                     | Yes  | Name of the target table.                                            |
| values   | Array&lt;[ValuesBucket](#valuesbucket)&gt; | Yes  | An array of data to insert.                                |
| callback | AsyncCallback&lt;number&gt;                | Yes  | Callback invoked to return the result. If the operation is successful, the number of inserted data records is returned. Otherwise, **-1** is returned.|

**Error codes**

For details about the error codes, see [RDB Error Codes](../errorcodes/errorcode-data-rdb.md).

| **ID**| **Error Message**                                |
| ------------ | -------------------------------------------- |
| 14800000     | The inner error is occurred.                 |

**Example**

```js
const valueBucket1 = {
  "NAME": "Lisa",
  "AGE": 18,
  "SALARY": 100.5,
  "CODES": new Uint8Array([1, 2, 3, 4, 5])
};
const valueBucket2 = {
  "NAME": "Jack",
  "AGE": 19,
  "SALARY": 101.5,
  "CODES": new Uint8Array([6, 7, 8, 9, 10])
};
const valueBucket3 = {
  "NAME": "Tom",
  "AGE": 20,
  "SALARY": 102.5,
  "CODES": new Uint8Array([11, 12, 13, 14, 15])
};

let valueBuckets = new Array(valueBucket1, valueBucket2, valueBucket3);
store.batchInsert("EMPLOYEE", valueBuckets, function(err, insertNum) {
  if (err) {
    console.error(`batchInsert is failed, code is ${err.code},message is ${err.message}`);
    return;
  }
  console.info(`batchInsert is successful, the number of values that were inserted = ${insertNum}`);
})
```

### batchInsert

batchInsert(table: string, values: Array&lt;ValuesBucket&gt;):Promise&lt;number&gt;

Batch inserts data into a table. This API uses a promise to return the result.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Parameters**

| Name| Type                                      | Mandatory| Description                        |
| ------ | ------------------------------------------ | ---- | ---------------------------- |
| table  | string                                     | Yes  | Name of the target table.            |
| values | Array&lt;[ValuesBucket](#valuesbucket)&gt; | Yes  | An array of data to insert.|

**Return value**

| Type                 | Description                                                       |
| --------------------- | ----------------------------------------------------------- |
| Promise&lt;number&gt; | Promise used to return the result. If the operation is successful, the number of inserted data records is returned. Otherwise, **-1** is returned.|

**Error codes**

For details about the error codes, see [RDB Error Codes](../errorcodes/errorcode-data-rdb.md).

| **ID**| **Error Message**                                |
| ------------ | -------------------------------------------- |
| 14800000     | The inner error is occurred.                 |

**Example**

```js
const valueBucket1 = {
  "NAME": "Lisa",
  "AGE": 18,
  "SALARY": 100.5,
  "CODES": new Uint8Array([1, 2, 3, 4, 5])
};
const valueBucket2 = {
  "NAME": "Jack",
  "AGE": 19,
  "SALARY": 101.5,
  "CODES": new Uint8Array([6, 7, 8, 9, 10])
};
const valueBucket3 = {
  "NAME": "Tom",
  "AGE": 20,
  "SALARY": 102.5,
  "CODES": new Uint8Array([11, 12, 13, 14, 15])
};

let valueBuckets = new Array(valueBucket1, valueBucket2, valueBucket3);
let promise = store.batchInsert("EMPLOYEE", valueBuckets);
promise.then((insertNum) => {
  console.info(`batchInsert is successful, the number of values that were inserted = ${insertNum}`);
}).catch((err) => {
  console.error(`batchInsert is failed, code is ${err.code},message is ${err.message}`);
})
```

### update

update(values: ValuesBucket, predicates: RdbPredicates, callback: AsyncCallback&lt;number&gt;):void

Updates data in the RDB store based on the specified **RdbPredicates** object. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Parameters**

| Name    | Type                                | Mandatory| Description                                                        |
| ---------- | ------------------------------------ | ---- | ------------------------------------------------------------ |
| values     | [ValuesBucket](#valuesbucket)        | Yes  | Rows of data to update in the RDB store. The key-value pair is associated with the column name in the target table.|
| predicates | [RdbPredicates](#rdbpredicates) | Yes  | Update conditions specified by the **RdbPredicates** object.                   |
| callback   | AsyncCallback&lt;number&gt;          | Yes  | Callback invoked to return the number of rows updated.                  |


**Error codes**

For details about the error codes, see [RDB Error Codes](../errorcodes/errorcode-data-rdb.md).

| **ID**| **Error Message**                                |
| ------------ | -------------------------------------------- |
| 14800000     | The inner error is occurred.                 |

**Example**

```js
const valueBucket = {
  "NAME": "Rose",
  "AGE": 22,
  "SALARY": 200.5,
  "CODES": new Uint8Array([1, 2, 3, 4, 5]),
};
let predicates = new relationalStore.RdbPredicates("EMPLOYEE");
predicates.equalTo("NAME", "Lisa");
store.update(valueBucket, predicates, function (err, rows) {
  if (err) {
    console.error(`Updated failed, code is ${err.code},message is ${err.message}`);
    return;
  }
  console.info(`Updated row count: ${rows}`);
})
```


### update

update(values: ValuesBucket, predicates: RdbPredicates):Promise&lt;number&gt;

Updates data based on the specified **RdbPredicates** object. This API uses a promise to return the result.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Parameters**

| Name      | Type                                | Mandatory| Description                                                        |
| ------------ | ------------------------------------ | ---- | ------------------------------------------------------------ |
| values       | [ValuesBucket](#valuesbucket)        | Yes  | Rows of data to update in the RDB store. The key-value pair is associated with the column name in the target table.|
| predicates | [RdbPredicates](#rdbpredicates) | Yes  | Update conditions specified by the **RdbPredicates** object.                   |

**Return value**

| Type                 | Description                                     |
| --------------------- | ----------------------------------------- |
| Promise&lt;number&gt; | Promise used to return the number of rows updated.|

**Error codes**

For details about the error codes, see [RDB Error Codes](../errorcodes/errorcode-data-rdb.md).

| **ID**| **Error Message**                                |
| ------------ | -------------------------------------------- |
| 14800000     | The inner error is occurred.                 |

**Example**

```js
const valueBucket = {
  "NAME": "Rose",
  "AGE": 22,
  "SALARY": 200.5,
  "CODES": new Uint8Array([1, 2, 3, 4, 5]),
};
let predicates = new relationalStore.RdbPredicates("EMPLOYEE");
predicates.equalTo("NAME", "Lisa");
let promise = store.update(valueBucket, predicates);
promise.then(async (rows) => {
  console.info(`Updated row count: ${rows}`);
}).catch((err) => {
  console.error(`Updated failed, code is ${err.code},message is ${err.message}`);
})
```


### update

update(table: string, values: ValuesBucket, predicates: dataSharePredicates.DataSharePredicates, callback: AsyncCallback&lt;number&gt;):void

Updates data based on the specified **DataSharePredicates** object. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Model restriction**: This API can be used only in the stage model.

**System API**: This is a system API.

**Parameters**

| Name    | Type                                                        | Mandatory| Description                                                        |
| ---------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| table      | string                                                       | Yes  | Name of the target table.                                            |
| values     | [ValuesBucket](#valuesbucket)                                | Yes  | Rows of data to update in the RDB store. The key-value pair is associated with the column name in the target table.|
| predicates | [dataSharePredicates.DataSharePredicates](js-apis-data-dataSharePredicates.md#datasharepredicates) | Yes  | Update conditions specified by the **DataSharePredicates** object.               |
| callback   | AsyncCallback&lt;number&gt;                                  | Yes  | Callback invoked to return the number of rows updated.                  |

**Error codes**

For details about the error codes, see [RDB Error Codes](../errorcodes/errorcode-data-rdb.md).

| **ID**| **Error Message**                                |
| ------------ | -------------------------------------------- |
| 14800000     | The inner error is occurred.                 |

**Example**

```js
import dataSharePredicates from '@ohos.data.dataSharePredicates'
const valueBucket = {
    "NAME": "Rose",
    "AGE": 22,
    "SALARY": 200.5,
    "CODES": new Uint8Array([1, 2, 3, 4, 5]),
};
let predicates = new dataSharePredicates.DataSharePredicates();
predicates.equalTo("NAME", "Lisa");
store.update("EMPLOYEE", valueBucket, predicates, function (err, rows) {
  if (err) {
    console.error(`Updated failed, code is ${err.code},message is ${err.message}`);
    return;
  }
  console.info(`Updated row count: ${rows}`);
})
```

### update

update(table: string, values: ValuesBucket, predicates: dataSharePredicates.DataSharePredicates):Promise&lt;number&gt;

Updates data based on the specified **DataSharePredicates** object. This API uses a promise to return the result.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Model restriction**: This API can be used only in the stage model.

**System API**: This is a system API.

**Parameters**

| Name    | Type                                                        | Mandatory| Description                                                        |
| ---------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| table      | string                                                       | Yes  | Name of the target table.                                            |
| values     | [ValuesBucket](#valuesbucket)                                | Yes  | Rows of data to update in the RDB store. The key-value pair is associated with the column name in the target table.|
| predicates | [dataSharePredicates.DataSharePredicates](js-apis-data-dataSharePredicates.md#datasharepredicates) | Yes  | Update conditions specified by the **DataSharePredicates** object.               |

**Return value**

| Type                 | Description                                     |
| --------------------- | ----------------------------------------- |
| Promise&lt;number&gt; | Promise used to return the number of rows updated.|

**Error codes**

For details about the error codes, see [RDB Error Codes](../errorcodes/errorcode-data-rdb.md).

| **ID**| **Error Message**                                |
| ------------ | -------------------------------------------- |
| 14800000     | The inner error is occurred.                 |

**Example**

```js
import dataSharePredicates from '@ohos.data.dataSharePredicates'
const valueBucket = {
  "NAME": "Rose",
  "AGE": 22,
  "SALARY": 200.5,
  "CODES": new Uint8Array([1, 2, 3, 4, 5]),
};
let predicates = new dataSharePredicates.DataSharePredicates();
predicates.equalTo("NAME", "Lisa");
let promise = store.update("EMPLOYEE", valueBucket, predicates);
promise.then(async (rows) => {
  console.info(`Updated row count: ${rows}`);
}).catch((err) => {
  console.error(`Updated failed, code is ${err.code},message is ${err.message}`);
})
```

### delete

delete(predicates: RdbPredicates, callback: AsyncCallback&lt;number&gt;):void

Deletes data from the RDB store based on the specified **RdbPredicates** object. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Parameters**

| Name    | Type                                | Mandatory| Description                                     |
| ---------- | ------------------------------------ | ---- | ----------------------------------------- |
| predicates | [RdbPredicates](#rdbpredicates) | Yes  | Conditions specified by the **RdbPredicates** object for deleting data.|
| callback   | AsyncCallback&lt;number&gt;          | Yes  | Callback invoked to return the number of rows deleted. |

**Error codes**

For details about the error codes, see [RDB Error Codes](../errorcodes/errorcode-data-rdb.md).

| **ID**| **Error Message**                                |
| ------------ | -------------------------------------------- |
| 14800000     | The inner error is occurred.                 |

**Example**

```js
let predicates = new relationalStore.RdbPredicates("EMPLOYEE");
predicates.equalTo("NAME", "Lisa");
store.delete(predicates, function (err, rows) {
  if (err) {
    console.error(`Delete failed, code is ${err.code},message is ${err.message}`);
    return;
  }
  console.info(`Delete rows: ${rows}`);
})
```

### delete

delete(predicates: RdbPredicates):Promise&lt;number&gt;

Deletes data from the RDB store based on the specified **RdbPredicates** object. This API uses a promise to return the result.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Parameters**

| Name    | Type                                | Mandatory| Description                                     |
| ---------- | ------------------------------------ | ---- | ----------------------------------------- |
| predicates | [RdbPredicates](#rdbpredicates) | Yes  | Conditions specified by the **RdbPredicates** object for deleting data.|

**Return value**

| Type                 | Description                           |
| --------------------- | ------------------------------- |
| Promise&lt;number&gt; | Promise used to return the number of rows deleted.|

**Error codes**

For details about the error codes, see [RDB Error Codes](../errorcodes/errorcode-data-rdb.md).

| **ID**| **Error Message**                                |
| ------------ | -------------------------------------------- |
| 14800000     | The inner error is occurred.                 |

**Example**

```js
let predicates = new relationalStore.RdbPredicates("EMPLOYEE");
predicates.equalTo("NAME", "Lisa");
let promise = store.delete(predicates);
promise.then((rows) => {
  console.info(`Delete rows: ${rows}`);
}).catch((err) => {
  console.error(`Delete failed, code is ${err.code},message is ${err.message}`);
})
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
| callback   | AsyncCallback&lt;number&gt;                                  | Yes  | Callback invoked to return the number of rows deleted.     |

**Error codes**

For details about the error codes, see [RDB Error Codes](../errorcodes/errorcode-data-rdb.md).

| **ID**| **Error Message**                                |
| ------------ | -------------------------------------------- |
| 14800000     | The inner error is occurred.                 |

**Example**

```js
import dataSharePredicates from '@ohos.data.dataSharePredicates'
let predicates = new dataSharePredicates.DataSharePredicates();
predicates.equalTo("NAME", "Lisa");
store.delete("EMPLOYEE", predicates, function (err, rows) {
  if (err) {
    console.error(`Delete failed, code is ${err.code},message is ${err.message}`);
    return;
  }
  console.info(`Delete rows: ${rows}`);
})
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

For details about the error codes, see [RDB Error Codes](../errorcodes/errorcode-data-rdb.md).

| **ID**| **Error Message**                                |
| ------------ | -------------------------------------------- |
| 14800000     | The inner error is occurred.                 |

**Example**

```js
import dataSharePredicates from '@ohos.data.dataSharePredicates'
let predicates = new dataSharePredicates.DataSharePredicates();
predicates.equalTo("NAME", "Lisa");
let promise = store.delete("EMPLOYEE", predicates);
promise.then((rows) => {
  console.info(`Delete rows: ${rows}`);
}).catch((err) => {
  console.error(`Delete failed, code is ${err.code},message is ${err.message}`);
})
```

### query

query(predicates: RdbPredicates, columns: Array&lt;string&gt;, callback: AsyncCallback&lt;ResultSet&gt;):void

Queries data from the RDB store based on specified conditions. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Parameters**

| Name    | Type                                                        | Mandatory| Description                                                       |
| ---------- | ------------------------------------------------------------ | ---- | ----------------------------------------------------------- |
| predicates | [RdbPredicates](#rdbpredicates)                         | Yes  | Query conditions specified by the **RdbPredicates** object.                  |
| columns    | Array&lt;string&gt;                                          | Yes  | Columns to query. If this parameter is not specified, the query applies to all columns.           |
| callback   | AsyncCallback&lt;[ResultSet](#resultset)&gt; | Yes  | Callback invoked to return the result. If the operation is successful, a **ResultSet** object will be returned.|

**Error codes**

For details about the error codes, see [RDB Error Codes](../errorcodes/errorcode-data-rdb.md).

| **ID**| **Error Message**                                |
| ------------ | -------------------------------------------- |
| 14800000     | The inner error is occurred.                 |

**Example**

```js
let predicates = new relationalStore.RdbPredicates("EMPLOYEE");
predicates.equalTo("NAME", "Rose");
store.query(predicates, ["ID", "NAME", "AGE", "SALARY", "CODES"], function (err, resultSet) {
  if (err) {
    console.error(`Query failed, code is ${err.code},message is ${err.message}`);
    return;
  }
  console.info(`ResultSet column names: ${resultSet.columnNames}`);
  console.info(`ResultSet column count: ${resultSet.columnCount}`);
})
```

### query

query(predicates: RdbPredicates, columns?: Array&lt;string&gt;):Promise&lt;ResultSet&gt;

Queries data from the RDB store based on specified conditions. This API uses a promise to return the result.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Parameters**

| Name    | Type                                | Mandatory| Description                                            |
| ---------- | ------------------------------------ | ---- | ------------------------------------------------ |
| predicates | [RdbPredicates](#rdbpredicates) | Yes  | Query conditions specified by the **RdbPredicates** object.       |
| columns    | Array&lt;string&gt;                  | No  | Columns to query. If this parameter is not specified, the query applies to all columns.|

**Return value**

| Type                                                   | Description                                              |
| ------------------------------------------------------- | -------------------------------------------------- |
| Promise&lt;[ResultSet](#resultset)&gt; | Promise used to return the result. If the operation is successful, a **ResultSet** object will be returned.|

**Error codes**

For details about the error codes, see [RDB Error Codes](../errorcodes/errorcode-data-rdb.md).

| **ID**| **Error Message**                                |
| ------------ | -------------------------------------------- |
| 14800000     | The inner error is occurred.                 |

**Example**

  ```js
let predicates = new relationalStore.RdbPredicates("EMPLOYEE");
predicates.equalTo("NAME", "Rose");
let promise = store.query(predicates, ["ID", "NAME", "AGE", "SALARY", "CODES"]);
promise.then((resultSet) => {
  console.info(`ResultSet column names: ${resultSet.columnNames}`);
  console.info(`ResultSet column count: ${resultSet.columnCount}`);
}).catch((err) => {
  console.error(`Query failed, code is ${err.code},message is ${err.message}`);
})
  ```

### query

query(table: string, predicates: dataSharePredicates.DataSharePredicates, columns: Array&lt;string&gt;, callback: AsyncCallback&lt;ResultSet&gt;):void

Queries data from the RDB store based on specified conditions. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Model restriction**: This API can be used only in the stage model.

**System API**: This is a system API.

**Parameters**

| Name    | Type                                                        | Mandatory| Description                                                       |
| ---------- | ------------------------------------------------------------ | ---- | ----------------------------------------------------------- |
| table      | string                                                       | Yes  | Name of the target table.                                           |
| predicates | [dataSharePredicates.DataSharePredicates](js-apis-data-dataSharePredicates.md#datasharepredicates) | Yes  | Query conditions specified by the **DataSharePredicates** object.              |
| columns    | Array&lt;string&gt;                                          | Yes  | Columns to query. If this parameter is not specified, the query applies to all columns.           |
| callback   | AsyncCallback&lt;[ResultSet](#resultset)&gt; | Yes  | Callback invoked to return the result. If the operation is successful, a **ResultSet** object will be returned.|

**Error codes**

For details about the error codes, see [RDB Error Codes](../errorcodes/errorcode-data-rdb.md).

| **ID**| **Error Message**                                |
| ------------ | -------------------------------------------- |
| 14800000     | The inner error is occurred.                 |

**Example**

```js
import dataSharePredicates from '@ohos.data.dataSharePredicates'
let predicates = new dataSharePredicates.DataSharePredicates();
predicates.equalTo("NAME", "Rose");
store.query("EMPLOYEE", predicates, ["ID", "NAME", "AGE", "SALARY", "CODES"], function (err, resultSet) {
  if (err) {
    console.error(`Query failed, code is ${err.code},message is ${err.message}`);
    return;
  }
  console.info(`ResultSet column names: ${resultSet.columnNames}`);
  console.info(`ResultSet column count: ${resultSet.columnCount}`);
})
```

### query

query(table: string, predicates: dataSharePredicates.DataSharePredicates, columns?: Array&lt;string&gt;):Promise&lt;ResultSet&gt;

Queries data from the RDB store based on specified conditions. This API uses a promise to return the result.

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

For details about the error codes, see [RDB Error Codes](../errorcodes/errorcode-data-rdb.md).

| **ID**| **Error Message**                                |
| ------------ | -------------------------------------------- |
| 14800000     | The inner error is occurred.                 |

**Example**

```js
import dataSharePredicates from '@ohos.data.dataSharePredicates'
let predicates = new dataSharePredicates.DataSharePredicates();
predicates.equalTo("NAME", "Rose");
let promise = store.query("EMPLOYEE", predicates, ["ID", "NAME", "AGE", "SALARY", "CODES"]);
promise.then((resultSet) => {
  console.info(`ResultSet column names: ${resultSet.columnNames}`);
  console.info(`ResultSet column count: ${resultSet.columnCount}`);
}).catch((err) => {
  console.error(`Query failed, code is ${err.code},message is ${err.message}`);
})
```

### remoteQuery

remoteQuery(device: string, table: string, predicates: RdbPredicates, columns: Array&lt;string&gt; , callback: AsyncCallback&lt;ResultSet&gt;): void

Queries data from the RDB store of a remote device based on specified conditions. This API uses an asynchronous callback to return the result.

> **NOTE**<br/>
>
> The value of **device** is obtained by [deviceManager.getTrustedDeviceListSync](js-apis-device-manager.md#gettrusteddevicelistsync). The APIs of the **deviceManager** module are system interfaces and available only to system applications.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Parameters**

| Name    | Type                                        | Mandatory| Description                                                     |
| ---------- | -------------------------------------------- | ---- | --------------------------------------------------------- |
| device     | string                                       | Yes  | ID of the remote device.                                       |
| table      | string                                       | Yes  | Name of the target table.                                         |
| predicates | [RdbPredicates](#rdbpredicates)              | Yes  | Query conditions specified by the **RdbPredicates** object.                |
| columns    | Array&lt;string&gt;                          | Yes  | Columns to query. If this parameter is not specified, the query applies to all columns.         |
| callback   | AsyncCallback&lt;[ResultSet](#resultset)&gt; | Yes  | Callback invoked to return the result. If the operation is successful, a **ResultSet** object will be returned.|

**Error codes**

For details about the error codes, see [RDB Error Codes](../errorcodes/errorcode-data-rdb.md).

| **ID**| **Error Message**                                |
| ------------ | -------------------------------------------- |
| 14800000     | The inner error is occurred.                 |

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

let predicates = new relationalStore.RdbPredicates('EMPLOYEE');
predicates.greaterThan("id", 0);
store.remoteQuery(deviceId, "EMPLOYEE", predicates, ["ID", "NAME", "AGE", "SALARY", "CODES"],
  function(err, resultSet) {
    if (err) {
      console.error(`Failed to remoteQuery, code is ${err.code},message is ${err.message}`);
      return;
    }
    console.info(`ResultSet column names: ${resultSet.columnNames}`);
    console.info(`ResultSet column count: ${resultSet.columnCount}`);
  }
)
```

### remoteQuery

remoteQuery(device: string, table: string, predicates: RdbPredicates, columns: Array&lt;string&gt;): Promise&lt;ResultSet&gt;

Queries data from the RDB store of a remote device based on specified conditions. This API uses a promise to return the result.

> **NOTE**<br/>
>
> The value of **device** is obtained by [deviceManager.getTrustedDeviceListSync](js-apis-device-manager.md#gettrusteddevicelistsync). The APIs of the **deviceManager** module are system interfaces and available only to system applications.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Parameters**

| Name    | Type                                | Mandatory| Description                                            |
| ---------- | ------------------------------------ | ---- | ------------------------------------------------ |
| device     | string                               | Yes  | ID of the remote device.                  |
| table      | string                               | Yes  | Name of the target table.                                |
| predicates | [RdbPredicates](#rdbpredicates) | Yes  | Query conditions specified by the **RdbPredicates** object.     |
| columns    | Array&lt;string&gt;                  | Yes  | Columns to query. If this parameter is not specified, the query applies to all columns.|

**Return value**

| Type                                                        | Description                                              |
| ------------------------------------------------------------ | -------------------------------------------------- |
| Promise&lt;[ResultSet](#resultset)&gt; | Promise used to return the result. If the operation is successful, a **ResultSet** object will be returned.|

**Error codes**

For details about the error codes, see [RDB Error Codes](../errorcodes/errorcode-data-rdb.md).

| **ID**| **Error Message**                                |
| ------------ | -------------------------------------------- |
| 14800000     | The inner error is occurred.                 |

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

let predicates = new relationalStore.RdbPredicates('EMPLOYEE');
predicates.greaterThan("id", 0);
let promise = store.remoteQuery(deviceId, "EMPLOYEE", predicates, ["ID", "NAME", "AGE", "SALARY", "CODES"]);
promise.then((resultSet) => {
  console.info(`ResultSet column names: ${resultSet.columnNames}`);
  console.info(`ResultSet column count: ${resultSet.columnCount}`);
}).catch((err) => {
  console.error(`Failed to remoteQuery, code is ${err.code},message is ${err.message}`);
})
```

### querySql

querySql(sql: string, bindArgs: Array&lt;ValueType&gt;, callback: AsyncCallback&lt;ResultSet&gt;):void

Queries data using the specified SQL statement. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Parameters**

| Name  | Type                                        | Mandatory| Description                                                        |
| -------- | -------------------------------------------- | ---- | ------------------------------------------------------------ |
| sql      | string                                       | Yes  | SQL statement to run.                                       |
| bindArgs | Array&lt;[ValueType](#valuetype)&gt;         | Yes  | Arguments in the SQL statement. The value corresponds to the placeholders in the SQL parameter statement. If the SQL parameter statement is complete, the value of this parameter must be an empty array.|
| callback | AsyncCallback&lt;[ResultSet](#resultset)&gt; | Yes  | Callback invoked to return the result. If the operation is successful, a **ResultSet** object will be returned.   |

**Error codes**

For details about the error codes, see [RDB Error Codes](../errorcodes/errorcode-data-rdb.md).

| **ID**| **Error Message**                                |
| ------------ | -------------------------------------------- |
| 14800000     | The inner error is occurred.                 |

**Example**

```js
store.querySql("SELECT * FROM EMPLOYEE CROSS JOIN BOOK WHERE BOOK.NAME = ?", ['sanguo'], function (err, resultSet) {
  if (err) {
    console.error(`Query failed, code is ${err.code},message is ${err.message}`);
    return;
  }
  console.info(`ResultSet column names: ${resultSet.columnNames}`);
  console.info(`ResultSet column count: ${resultSet.columnCount}`);
})
```

### querySql

querySql(sql: string, bindArgs?: Array&lt;ValueType&gt;):Promise&lt;ResultSet&gt;

Queries data using the specified SQL statement. This API uses a promise to return the result.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Parameters**

| Name  | Type                                | Mandatory| Description                                                        |
| -------- | ------------------------------------ | ---- | ------------------------------------------------------------ |
| sql      | string                               | Yes  | SQL statement to run.                                       |
| bindArgs | Array&lt;[ValueType](#valuetype)&gt; | No  | Arguments in the SQL statement. The value corresponds to the placeholders in the SQL parameter statement. If the SQL parameter statement is complete, leave this parameter blank.|

**Return value**

| Type                                                   | Description                                              |
| ------------------------------------------------------- | -------------------------------------------------- |
| Promise&lt;[ResultSet](#resultset)&gt; | Promise used to return the result. If the operation is successful, a **ResultSet** object will be returned.|

**Error codes**

For details about the error codes, see [RDB Error Codes](../errorcodes/errorcode-data-rdb.md).

| **ID**| **Error Message**                                |
| ------------ | -------------------------------------------- |
| 14800000     | The inner error is occurred.                 |

**Example**

```js
let promise = store.querySql("SELECT * FROM EMPLOYEE CROSS JOIN BOOK WHERE BOOK.NAME = 'sanguo'");
promise.then((resultSet) => {
  console.info(`ResultSet column names: ${resultSet.columnNames}`);
  console.info(`ResultSet column count: ${resultSet.columnCount}`);
}).catch((err) => {
  console.error(`Query failed, code is ${err.code},message is ${err.message}`);
})
```

### executeSql

executeSql(sql: string, bindArgs: Array&lt;ValueType&gt;, callback: AsyncCallback&lt;void&gt;):void

Executes an SQL statement that contains specified arguments but returns no value. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Parameters**

| Name  | Type                                | Mandatory| Description                                                        |
| -------- | ------------------------------------ | ---- | ------------------------------------------------------------ |
| sql      | string                               | Yes  | SQL statement to run.                                       |
| bindArgs | Array&lt;[ValueType](#valuetype)&gt; | Yes  | Arguments in the SQL statement. The value corresponds to the placeholders in the SQL parameter statement. If the SQL parameter statement is complete, the value of this parameter must be an empty array.|
| callback | AsyncCallback&lt;void&gt;            | Yes  | Callback invoked to return the result.                                      |

**Error codes**

For details about the error codes, see [RDB Error Codes](../errorcodes/errorcode-data-rdb.md).

| **ID**| **Error Message**                                |
| ------------ | -------------------------------------------- |
| 14800000     | The inner error is occurred.                 |

**Example**

```js
const SQL_DELETE_TABLE = "DELETE FROM test WHERE name = ?"
store.executeSql(SQL_DELETE_TABLE, ['zhangsan'], function(err) {
  if (err) {
    console.error(`ExecuteSql failed, code is ${err.code},message is ${err.message}`);
    return;
  }
  console.info(`Delete table done.`);
})
```

### executeSql

executeSql(sql: string, bindArgs?: Array&lt;ValueType&gt;):Promise&lt;void&gt;

Executes an SQL statement that contains specified arguments but returns no value. This API uses a promise to return the result.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Parameters**

| Name  | Type                                | Mandatory| Description                                                        |
| -------- | ------------------------------------ | ---- | ------------------------------------------------------------ |
| sql      | string                               | Yes  | SQL statement to run.                                       |
| bindArgs | Array&lt;[ValueType](#valuetype)&gt; | No  | Arguments in the SQL statement. The value corresponds to the placeholders in the SQL parameter statement. If the SQL parameter statement is complete, leave this parameter blank.|

**Return value**

| Type               | Description                     |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [RDB Error Codes](../errorcodes/errorcode-data-rdb.md).

| **ID**| **Error Message**                                |
| ------------ | -------------------------------------------- |
| 14800000     | The inner error is occurred.                 |

**Example**

```js
const SQL_DELETE_TABLE = "DELETE FROM test WHERE name = 'zhangsan'"
let promise = store.executeSql(SQL_DELETE_TABLE);
promise.then(() => {
    console.info(`Delete table done.`);
}).catch((err) => {
    console.error(`ExecuteSql failed, code is ${err.code},message is ${err.message}`);
})
```

### beginTransaction

beginTransaction():void

Starts the transaction before executing an SQL statement.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Error codes**

For details about the error codes, see [RDB Error Codes](../errorcodes/errorcode-data-rdb.md).

| **ID**| **Error Message**                                |
| ------------ | -------------------------------------------- |
| 14800000     | The inner error is occurred.                 |

**Example**

```js
import featureAbility from '@ohos.ability.featureAbility'
let context = featureAbility.getContext();
const STORE_CONFIG = { 
  name: "RdbTest.db",
  securityLevel: relationalStore.SecurityLevel.S1
};
relationalStore.getRdbStore(context, STORE_CONFIG, async function (err, store) {
  if (err) {
    console.error(`GetRdbStore failed, code is ${err.code},message is ${err.message}`);
    return;
  }
  store.beginTransaction();
  const valueBucket = {
    "name": "lisi",
	"age": 18,
	"salary": 100.5,
	"blobType": new Uint8Array([1, 2, 3]),
  };
  await store.insert("test", valueBucket);
  store.commit();
})
```

### commit

commit():void

Commits the executed SQL statements.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Example**

```js
import featureAbility from '@ohos.ability.featureAbility'
let context = featureAbility.getContext();
const STORE_CONFIG = { 
  name: "RdbTest.db",
  securityLevel: relationalStore.SecurityLevel.S1
};
relationalStore.getRdbStore(context, STORE_CONFIG, async function (err, store) {
  if (err) {
     console.error(`GetRdbStore failed, code is ${err.code},message is ${err.message}`);
     return;
  }
  store.beginTransaction();
  const valueBucket = {
	"name": "lisi",
	"age": 18,
	"salary": 100.5,
	"blobType": new Uint8Array([1, 2, 3]),
  };
  await store.insert("test", valueBucket);
  store.commit();
})
```

### rollBack

rollBack():void

Rolls back the SQL statements that have been executed.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Example**

```js
import featureAbility from '@ohos.ability.featureAbility'
let context = featureAbility.getContext();
const STORE_CONFIG = { 
  name: "RdbTest.db",
  securityLevel: relationalStore.SecurityLevel.S1
};
relationalStore.getRdbStore(context, STORE_CONFIG, async function (err, store) {
  if (err) {
    console.error(`GetRdbStore failed, code is ${err.code},message is ${err.message}`);
    return;
  }
  try {
    store.beginTransaction()
    const valueBucket = {
	  "id": 1,
	  "name": "lisi",
	  "age": 18,
	  "salary": 100.5,
	  "blobType": new Uint8Array([1, 2, 3]),
	};
	await store.insert("test", valueBucket);
    store.commit();
  } catch (err) {
    console.error(`Transaction failed, code is ${err.code},message is ${err.message}`);
    store.rollBack();
  }
})
```

### backup

backup(destName:string, callback: AsyncCallback&lt;void&gt;):void

Backs up an RDB store. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Parameters**

| Name  | Type                     | Mandatory| Description                    |
| -------- | ------------------------- | ---- | ------------------------ |
| destName | string                    | Yes  | Name of the RDB store backup file.|
| callback | AsyncCallback&lt;void&gt; | Yes  | Callback invoked to return the result.  |

**Error codes**

For details about the error codes, see [RDB Error Codes](../errorcodes/errorcode-data-rdb.md).

| **ID**| **Error Message**                                |
| ------------ | -------------------------------------------- |
| 14800000     | The inner error is occurred.                 |

**Example**

```js
store.backup("dbBackup.db", function(err) {
  if (err) {
    console.error(`Backup failed, code is ${err.code},message is ${err.message}`);
    return;
  }
  console.info(`Backup success.`);
})
```

### backup

backup(destName:string): Promise&lt;void&gt;

Backs up an RDB store. This API uses a promise to return the result.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Parameters**

| Name  | Type  | Mandatory| Description                    |
| -------- | ------ | ---- | ------------------------ |
| destName | string | Yes  | Name of the RDB store backup file.|

**Error codes**

For details about the error codes, see [RDB Error Codes](../errorcodes/errorcode-data-rdb.md).

| **ID**| **Error Message**                                |
| ------------ | -------------------------------------------- |
| 14800000     | The inner error is occurred.                 |

**Return value**

| Type               | Description                     |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Example**

```js
let promiseBackup = store.backup("dbBackup.db");
promiseBackup.then(()=>{
  console.info(`Backup success.`);
}).catch((err)=>{
  console.error(`Backup failed, code is ${err.code},message is ${err.message}`);
})
```

### restore

restore(srcName:string, callback: AsyncCallback&lt;void&gt;):void

Restores an RDB store from a backup file. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Parameters**

| Name  | Type                     | Mandatory| Description                    |
| -------- | ------------------------- | ---- | ------------------------ |
| srcName  | string                    | Yes  | Name of the RDB store backup file.|
| callback | AsyncCallback&lt;void&gt; | Yes  | Callback invoked to return the result.  |

**Error codes**

For details about the error codes, see [RDB Error Codes](../errorcodes/errorcode-data-rdb.md).

| **ID**| **Error Message**                                |
| ------------ | -------------------------------------------- |
| 14800000     | The inner error is occurred.                 |

**Example**

```js
store.restore("dbBackup.db", function(err) {
  if (err) {
    console.error(`Restore failed, code is ${err.code},message is ${err.message}`);
    return;
  }
  console.info(`Restore success.`);
})
```

### restore

restore(srcName:string): Promise&lt;void&gt;

Restores an RDB store from a backup file. This API uses a promise to return the result.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Parameters**

| Name | Type  | Mandatory| Description                    |
| ------- | ------ | ---- | ------------------------ |
| srcName | string | Yes  | Name of the RDB store backup file.|

**Return value**

| Type               | Description                     |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [RDB Error Codes](../errorcodes/errorcode-data-rdb.md).

| **ID**| **Error Message**                                |
| ------------ | -------------------------------------------- |
| 14800000     | The inner error is occurred.                 |

**Example**

```js
let promiseRestore = store.restore("dbBackup.db");
promiseRestore.then(()=>{
  console.info(`Restore success.`);
}).catch((err)=>{
  console.error(`Restore failed, code is ${err.code},message is ${err.message}`);
})
```

### setDistributedTables

setDistributedTables(tables: Array&lt;string&gt;, callback: AsyncCallback&lt;void&gt;): void

Sets distributed tables. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.DISTRIBUTED_DATASYNC

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Parameters**

| Name  | Type                     | Mandatory| Description                  |
| -------- | ------------------------- | ---- | ---------------------- |
| tables   | Array&lt;string&gt;       | Yes  | Names of the distributed tables to set.|
| callback | AsyncCallback&lt;void&gt; | Yes  | Callback invoked to return the result.|

**Error codes**

For details about the error codes, see [RDB Error Codes](../errorcodes/errorcode-data-rdb.md).

| **ID**| **Error Message**                                |
| ------------ | -------------------------------------------- |
| 14800000     | The inner error is occurred.                 |

**Example**

```js
store.setDistributedTables(["EMPLOYEE"], function (err) {
  if (err) {
    console.error(`SetDistributedTables failed, code is ${err.code},message is ${err.message}`);
    return;
  }
  console.info(`SetDistributedTables successfully.`);
})
```

### setDistributedTables

 setDistributedTables(tables: Array&lt;string&gt;): Promise&lt;void&gt;

Sets distributed tables. This API uses a promise to return the result.

**Required permissions**: ohos.permission.DISTRIBUTED_DATASYNC

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Parameters**

| Name| Type               | Mandatory| Description                    |
| ------ | ------------------- | ---- | ------------------------ |
| tables | Array&lt;string&gt; | Yes  | Names of the distributed tables to set.|

**Return value**

| Type               | Description                     |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [RDB Error Codes](../errorcodes/errorcode-data-rdb.md).

| **ID**| **Error Message**                                |
| ------------ | -------------------------------------------- |
| 14800000     | The inner error is occurred.                 |

**Example**

```js
let promise = store.setDistributedTables(["EMPLOYEE"]);
promise.then(() => {
  console.info(`SetDistributedTables successfully.`);
}).catch((err) => {
  console.error(`SetDistributedTables failed, code is ${err.code},message is ${err.message}`);
})
```

### obtainDistributedTableName

obtainDistributedTableName(device: string, table: string, callback: AsyncCallback&lt;string&gt;): void

Obtains the distributed table name of a remote device based on the local table name of the device. The distributed table name is required when the RDB store of a remote device is queried.

> **NOTE**<br/>
>
> The value of **device** is obtained by [deviceManager.getTrustedDeviceListSync](js-apis-device-manager.md#gettrusteddevicelistsync). The APIs of the **deviceManager** module are system interfaces and available only to system applications.

**Required permissions**: ohos.permission.DISTRIBUTED_DATASYNC

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Parameters**

| Name  | Type                       | Mandatory| Description                                                        |
| -------- | --------------------------- | ---- | ------------------------------------------------------------ |
| device   | string                      | Yes  | ID of the remote device.                                               |
| table    | string                      | Yes  | Local table name of the remote device.                                        |
| callback | AsyncCallback&lt;string&gt; | Yes  | Callback invoked to return the result. If the operation succeeds, the distributed table name of the remote device is returned.|

**Error codes**

For details about the error codes, see [RDB Error Codes](../errorcodes/errorcode-data-rdb.md).

| **ID**| **Error Message**                                |
| ------------ | -------------------------------------------- |
| 14800000     | The inner error is occurred.                 |

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

store.obtainDistributedTableName(deviceId, "EMPLOYEE", function (err, tableName) {
    if (err) {
        console.error(`ObtainDistributedTableName failed, code is ${err.code},message is ${err.message}`);
        return;
    }
    console.info(`ObtainDistributedTableName successfully, tableName= ${tableName}`);
})
```

### obtainDistributedTableName

 obtainDistributedTableName(device: string, table: string): Promise&lt;string&gt;

Obtains the distributed table name of a remote device based on the local table name of the device. The distributed table name is required when the RDB store of a remote device is queried.

> **NOTE**<br/>
>
> The value of **device** is obtained by [deviceManager.getTrustedDeviceListSync](js-apis-device-manager.md#gettrusteddevicelistsync). The APIs of the **deviceManager** module are system interfaces and available only to system applications.

**Required permissions**: ohos.permission.DISTRIBUTED_DATASYNC

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Parameters**

| Name| Type  | Mandatory| Description                |
| ------ | ------ | ---- | -------------------- |
| device | string | Yes  | ID of the remote device.        |
| table  | string | Yes  | Local table name of the remote device.|

**Return value**

| Type                 | Description                                                 |
| --------------------- | ----------------------------------------------------- |
| Promise&lt;string&gt; | Promise used to return the result. If the operation succeeds, the distributed table name of the remote device is returned.|

**Error codes**

For details about the error codes, see [RDB Error Codes](../errorcodes/errorcode-data-rdb.md).

| **ID**| **Error Message**                                |
| ------------ | -------------------------------------------- |
| 14800000     | The inner error is occurred.                 |

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

let promise = store.obtainDistributedTableName(deviceId, "EMPLOYEE");
promise.then((tableName) => {
  console.info(`ObtainDistributedTableName successfully, tableName= ${tableName}`);
}).catch((err) => {
  console.error(`ObtainDistributedTableName failed, code is ${err.code},message is ${err.message}`);
})
```

### sync

sync(mode: SyncMode, predicates: RdbPredicates, callback: AsyncCallback&lt;Array&lt;[string, number]&gt;&gt;): void

Synchronizes data between devices. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.DISTRIBUTED_DATASYNC

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Parameters**

| Name    | Type                                              | Mandatory| Description                                                        |
| ---------- | -------------------------------------------------- | ---- | ------------------------------------------------------------ |
| mode       | [SyncMode](#syncmode)                             | Yes  | Data synchronization mode. The value can be **push** or **pull**.                              |
| predicates | [RdbPredicates](#rdbpredicates)               | Yes  | **RdbPredicates** object that specifies the data and devices to synchronize.                                        |
| callback   | AsyncCallback&lt;Array&lt;[string, number]&gt;&gt; | Yes  | Callback invoked to send the synchronization result to the caller. <br>**string** indicates the device ID. <br>**number** indicates the synchronization status of that device. The value **0** indicates a successful synchronization. Other values indicate a synchronization failure. |

**Error codes**

For details about the error codes, see [RDB Error Codes](../errorcodes/errorcode-data-rdb.md).

| **ID**| **Error Message**                                |
| ------------ | -------------------------------------------- |
| 14800000     | The inner error is occurred.                 |

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

let predicates = new relationalStore.RdbPredicates('EMPLOYEE');
predicates.inDevices(deviceIds);
store.sync(relationalStore.SyncMode.SYNC_MODE_PUSH, predicates, function (err, result) {
  if (err) {
    console.error(`Sync failed, code is ${err.code},message is ${err.message}`);
    return;
  }
  console.info(`Sync done.`);
  for (let i = 0; i < result.length; i++) {
    console.info(`device= ${result[i][0]}, status= ${result[i][1]}`);
  }
})
```

### sync

 sync(mode: SyncMode, predicates: RdbPredicates): Promise&lt;Array&lt;[string, number]&gt;&gt;

Synchronizes data between devices. This API uses a promise to return the result.

**Required permissions**: ohos.permission.DISTRIBUTED_DATASYNC

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Parameters**

| Name    | Type                                | Mandatory| Description                          |
| ---------- | ------------------------------------ | ---- | ------------------------------ |
| mode       | [SyncMode](#syncmode)               | Yes  | Data synchronization mode. The value can be **push** or **pull**.|
| predicates | [RdbPredicates](#rdbpredicates) | Yes  | **RdbPredicates** object that specifies the data and devices to synchronize.          |

**Return value**

| Type                                        | Description                                                        |
| -------------------------------------------- | ------------------------------------------------------------ |
| Promise&lt;Array&lt;[string, number]&gt;&gt; | Promise used to send the synchronization result. <br>**string** indicates the device ID. <br>**number** indicates the synchronization status of that device. The value **0** indicates a successful synchronization. Other values indicate a synchronization failure. |

**Error codes**

For details about the error codes, see [RDB Error Codes](../errorcodes/errorcode-data-rdb.md).

| **ID**| **Error Message**                                |
| ------------ | -------------------------------------------- |
| 14800000     | The inner error is occurred.                 |

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

let predicates = new relationalStore.RdbPredicates('EMPLOYEE');
predicates.inDevices(deviceIds);
let promise = store.sync(relationalStore.SyncMode.SYNC_MODE_PUSH, predicates);
promise.then((result) =>{
  console.info(`Sync done.`);
  for (let i = 0; i < result.length; i++) {
    console.info(`device= ${result[i][0]}, status= ${result[i][1]}`);
  }
}).catch((err) => {
  console.error(`Sync failed, code is ${err.code},message is ${err.message}`);
})
```

### on('dataChange')

on(event: 'dataChange', type: SubscribeType, observer: Callback&lt;Array&lt;string&gt;&gt;): void

Registers an observer for this RDB store. When the data in the RDB store changes, a callback is invoked to return the data changes.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Parameters**

| Name  | Type                               | Mandatory| Description                                       |
| -------- | ----------------------------------- | ---- | ------------------------------------------- |
| event    | string                              | Yes  | Event to observe. The value is **dataChange**, which indicates a data change event.         |
| type     | [SubscribeType](#subscribetype)    | Yes  | Subscription type to register.|
| observer | Callback&lt;Array&lt;string&gt;&gt; | Yes  | Callback invoked to return the data change event. **Array<string>** indicates the IDs of the peer devices whose data in the database is changed.|

**Example**

```js
function storeObserver(devices) {
  for (let i = 0; i < devices.length; i++) {
    console.info(`device= ${devices[i]} data changed`);
  }
}
try {
  store.on('dataChange', relationalStore.SubscribeType.SUBSCRIBE_TYPE_REMOTE, storeObserver);
} catch (err) {
  console.error(`Register observer failed, code is ${err.code},message is ${err.message}`);
}
```

### off('dataChange')

off(event:'dataChange', type: SubscribeType, observer: Callback&lt;Array&lt;string&gt;&gt;): void

Unregisters the observer of the specified type.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Parameters**

| Name  | Type                               | Mandatory| Description                                       |
| -------- | ---------------------------------- | ---- | ------------------------------------------ |
| event    | string                              | Yes  | Event type. The value is **dataChange**, which indicates a data change event.         |
| type     | [SubscribeType](#subscribetype)     | Yes  | Subscription type to unregister.                                |
| observer | Callback&lt;Array&lt;string&gt;&gt; | Yes  | Callback for the data change event. **Array<string>** indicates the IDs of the peer devices whose data in the database is changed.|

**Example**

```js
function storeObserver(devices) {
  for (let i = 0; i < devices.length; i++) {
    console.info(`device= ${devices[i]} data changed`);
  }
}
try {
  store.off('dataChange', relationalStore.SubscribeType.SUBSCRIBE_TYPE_REMOTE, storeObserver);
} catch (err) {
  console.error(`Unregister observer failed, code is ${err.code},message is ${err.message}`);
}
```

## ResultSet

Provides APIs to access the result set obtained by querying the RDB store. A result set is a set of results returned after **query()** is called.

### Usage

Obtain the **resultSet** object first.

```js
let resultSet = null;
let predicates = new relationalStore.RdbPredicates("EMPLOYEE");
predicates.equalTo("AGE", 18);
let promise = store.query(predicates, ["ID", "NAME", "AGE", "SALARY", "CODES"]);
promise.then((result) => {
  resultSet = result;
  console.info(`resultSet columnNames: ${resultSet.columnNames}`);
  console.info(`resultSet columnCount: ${resultSet.columnCount}`);
});
```

### Attributes

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

| Name        | Type           | Mandatory| Description                            |
| ------------ | ------------------- | ---- | -------------------------------- |
| columnNames  | Array&lt;string&gt; | Yes  | Names of all columns in the result set.      |
| columnCount  | number              | Yes  | Number of columns in the result set.            |
| rowCount     | number              | Yes  | Number of rows in the result set.            |
| rowIndex     | number              | Yes  | Index of the current row in the result set.        |
| isAtFirstRow | boolean             | Yes  | Whether the cursor is in the first row of the result set.      |
| isAtLastRow  | boolean             | Yes  | Whether the cursor is in the last row of the result set.    |
| isEnded      | boolean             | Yes  | Whether the cursor is after the last row of the result set.|
| isStarted    | boolean             | Yes  | Whether the cursor has been moved.            |
| isClosed     | boolean             | Yes  | Whether the result set is closed.        |

### getColumnIndex

getColumnIndex(columnName: string): number

Obtains the column index based on the column name.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Parameters**

| Name    | Type  | Mandatory| Description                      |
| ---------- | ------ | ---- | -------------------------- |
| columnName | string | Yes  | Column name.|

**Return value**

| Type  | Description              |
| ------ | ------------------ |
| number | Column index obtained.|

**Error codes**

For details about the error codes, see [RDB Error Codes](../errorcodes/errorcode-data-rdb.md).

| **ID**| **Error Message**                                                |
| ------------ | ------------------------------------------------------------ |
| 14800013     | The column value is null or the column type is incompatible. |

**Example**

  ```js
resultSet.goToFirstRow();
const id = resultSet.getLong(resultSet.getColumnIndex("ID"));
const name = resultSet.getString(resultSet.getColumnIndex("NAME"));
const age = resultSet.getLong(resultSet.getColumnIndex("AGE"));
const salary = resultSet.getDouble(resultSet.getColumnIndex("SALARY"));
  ```

### getColumnName

getColumnName(columnIndex: number): string

Obtains the column name based on the specified column index.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Parameters**

| Name     | Type  | Mandatory| Description                      |
| ----------- | ------ | ---- | -------------------------- |
| columnIndex | number | Yes  | Column index.|

**Return value**

| Type  | Description              |
| ------ | ------------------ |
| string | Column name obtained.|

**Error codes**

For details about the error codes, see [RDB Error Codes](../errorcodes/errorcode-data-rdb.md).

| **ID**| **Error Message**                                                |
| ------------ | ------------------------------------------------------------ |
| 14800013     | The column value is null or the column type is incompatible. |

**Example**

  ```js
const id = resultSet.getColumnName(0);
const name = resultSet.getColumnName(1);
const age = resultSet.getColumnName(2);
  ```

### goTo

goTo(offset:number): boolean

Moves the cursor to the row based on the specified offset.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Parameters**

| Name| Type  | Mandatory| Description                        |
| ------ | ------ | ---- | ---------------------------- |
| offset | number | Yes  | Offset relative to the current position.|

**Return value**

| Type   | Description                                         |
| ------- | --------------------------------------------- |
| boolean | Returns **true** if the operation is successful; returns **false** otherwise.|

**Error codes**

For details about the error codes, see [RDB Error Codes](../errorcodes/errorcode-data-rdb.md).

| **ID**| **Error Message**                                                |
| ------------ | ------------------------------------------------------------ |
| 14800012     | The result set is empty or the specified location is invalid. |

**Example**

  ```js
let predicates = new relationalStore.RdbPredicates("EMPLOYEE");
let promise= store.query(predicates, ["ID", "NAME", "AGE", "SALARY", "CODES"]);
promise.then((resultSet) => {
  resultSet.goTo(1);
  resultSet.close();
}).catch((err) => {
  console.error(`query failed, code is ${err.code},message is ${err.message}`);
});
  ```

### goToRow

goToRow(position: number): boolean

Moves to the specified row in the result set.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Parameters**

| Name  | Type  | Mandatory| Description                    |
| -------- | ------ | ---- | ------------------------ |
| position | number | Yes  | Destination position to move to.|

**Return value**

| Type   | Description                                         |
| ------- | --------------------------------------------- |
| boolean | Returns **true** if the operation is successful; returns **false** otherwise.|

**Error codes**

For details about the error codes, see [RDB Error Codes](../errorcodes/errorcode-data-rdb.md).

| **ID**| **Error Message**                                                |
| ------------ | ------------------------------------------------------------ |
| 14800012     | The result set is empty or the specified location is invalid. |

**Example**

  ```js
let predicates = new relationalStore.RdbPredicates("EMPLOYEE");
let promise = store.query(predicates, ["ID", "NAME", "AGE", "SALARY", "CODES"]);
promise.then((resultSet) => {
  resultSet.goToRow(5);
  resultSet.close();
}).catch((err) => {
  console.error(`query failed, code is ${err.code},message is ${err.message}`);
});
  ```

### goToFirstRow

goToFirstRow(): boolean


Moves to the first row of the result set.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Return value**

| Type   | Description                                         |
| ------- | --------------------------------------------- |
| boolean | Returns **true** if the operation is successful; returns **false** otherwise.|

**Error codes**

For details about the error codes, see [RDB Error Codes](../errorcodes/errorcode-data-rdb.md).

| **ID**| **Error Message**                                                |
| ------------ | ------------------------------------------------------------ |
| 14800012     | The result set is empty or the specified location is invalid. |

**Example**

  ```js
let predicates = new relationalStore.RdbPredicates("EMPLOYEE");
let promise = store.query(predicates, ["ID", "NAME", "AGE", "SALARY", "CODES"]);
promise.then((resultSet) => {
  resultSet.goToFirstRow();
  resultSet.close();
}).catch((err) => {
  console.error(`query failed, code is ${err.code},message is ${err.message}`);
});
  ```

### goToLastRow

goToLastRow(): boolean

Moves to the last row of the result set.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Return value**

| Type   | Description                                         |
| ------- | --------------------------------------------- |
| boolean | Returns **true** if the operation is successful; returns **false** otherwise.|

**Error codes**

For details about the error codes, see [RDB Error Codes](../errorcodes/errorcode-data-rdb.md).

| **ID**| **Error Message**                                                |
| ------------ | ------------------------------------------------------------ |
| 14800012     | The result set is empty or the specified location is invalid. |

**Example**

  ```js
let predicates = new relationalStore.RdbPredicates("EMPLOYEE");
let promise = store.query(predicates, ["ID", "NAME", "AGE", "SALARY", "CODES"]);
promise.then((resultSet) => {
  resultSet.goToLastRow();
  resultSet.close();
}).catch((err) => {
  console.error(`query failed, code is ${err.code},message is ${err.message}`);
});
  ```

### goToNextRow

goToNextRow(): boolean

Moves to the next row in the result set.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Return value**

| Type   | Description                                         |
| ------- | --------------------------------------------- |
| boolean | Returns **true** if the operation is successful; returns **false** otherwise.|

**Error codes**

For details about the error codes, see [RDB Error Codes](../errorcodes/errorcode-data-rdb.md).

| **ID**| **Error Message**                                                |
| ------------ | ------------------------------------------------------------ |
| 14800012     | The result set is empty or the specified location is invalid. |

**Example**

  ```js
let predicates = new relationalStore.RdbPredicates("EMPLOYEE");
let promise = store.query(predicates, ["ID", "NAME", "AGE", "SALARY", "CODES"]);
promise.then((resultSet) => {
  resultSet.goToNextRow();
  resultSet.close();
}).catch((err) => {
  console.error(`query failed, code is ${err.code},message is ${err.message}`);
});
  ```

### goToPreviousRow

goToPreviousRow(): boolean

Moves to the previous row in the result set.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Return value**

| Type   | Description                                         |
| ------- | --------------------------------------------- |
| boolean | Returns **true** if the operation is successful; returns **false** otherwise.|

**Error codes**

For details about the error codes, see [RDB Error Codes](../errorcodes/errorcode-data-rdb.md).

| **ID**| **Error Message**                                                |
| ------------ | ------------------------------------------------------------ |
| 14800012     | The result set is empty or the specified location is invalid. |

**Example**

  ```js
let predicates = new relationalStore.RdbPredicates("EMPLOYEE");
let promise = store.query(predicates, ["ID", "NAME", "AGE", "SALARY", "CODES"]);
promise.then((resultSet) => {
  resultSet.goToPreviousRow();
  resultSet.close();
}).catch((err) => {
  console.error(`query failed, code is ${err.code},message is ${err.message}`);
});
  ```

### getBlob

getBlob(columnIndex: number): Uint8Array

Obtains the value in the form of a byte array based on the specified column and the current row.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Parameters**

| Name     | Type  | Mandatory| Description                   |
| ----------- | ------ | ---- | ----------------------- |
| columnIndex | number | Yes  | Index of the target column, starting from 0.|

**Return value**

| Type      | Description                            |
| ---------- | -------------------------------- |
| Uint8Array | Value obtained.|

**Error codes**

For details about the error codes, see [RDB Error Codes](../errorcodes/errorcode-data-rdb.md).

| **ID**| **Error Message**                                                |
| ------------ | ------------------------------------------------------------ |
| 14800013     | The column value is null or the column type is incompatible. |

**Example**

  ```js
const codes = resultSet.getBlob(resultSet.getColumnIndex("CODES"));
  ```

### getString

getString(columnIndex: number): string

Obtains the value in the form of a string based on the specified column and the current row.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Parameters**

| Name     | Type  | Mandatory| Description                   |
| ----------- | ------ | ---- | ----------------------- |
| columnIndex | number | Yes  | Index of the target column, starting from 0.|

**Return value**

| Type  | Description                        |
| ------ | ---------------------------- |
| string | String obtained.|

**Error codes**

For details about the error codes, see [RDB Error Codes](../errorcodes/errorcode-data-rdb.md).

| **ID**| **Error Message**                                                |
| ------------ | ------------------------------------------------------------ |
| 14800013     | The column value is null or the column type is incompatible. |

**Example**

  ```js
const name = resultSet.getString(resultSet.getColumnIndex("NAME"));
  ```

### getLong

getLong(columnIndex: number): number

Obtains the value of the Long type based on the specified column and the current row.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Parameters**

| Name     | Type  | Mandatory| Description                   |
| ----------- | ------ | ---- | ----------------------- |
| columnIndex | number | Yes  | Index of the target column, starting from 0.|

**Return value**

| Type  | Description                                                        |
| ------ | ------------------------------------------------------------ |
| number | Value obtained.<br>The value range supported by API is **Number.MIN_SAFE_INTEGER** to **Number.MAX_SAFE_INTEGER**. If the value is out of this range, use [getDouble](#getdouble).|

**Error codes**

For details about the error codes, see [RDB Error Codes](../errorcodes/errorcode-data-rdb.md).

| **ID**| **Error Message**                                                |
| ------------ | ------------------------------------------------------------ |
| 14800013     | The column value is null or the column type is incompatible. |

**Example**

  ```js
const age = resultSet.getLong(resultSet.getColumnIndex("AGE"));
  ```

### getDouble

getDouble(columnIndex: number): number

Obtains the value of the double type based on the specified column and the current row.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Parameters**

| Name     | Type  | Mandatory| Description                   |
| ----------- | ------ | ---- | ----------------------- |
| columnIndex | number | Yes  | Index of the target column, starting from 0.|

**Return value**

| Type  | Description                        |
| ------ | ---------------------------- |
| number | Value obtained.|

**Error codes**

For details about the error codes, see [RDB Error Codes](../errorcodes/errorcode-data-rdb.md).

| **ID**| **Error Message**                                                |
| ------------ | ------------------------------------------------------------ |
| 14800013     | The column value is null or the column type is incompatible. |

**Example**

  ```js
const salary = resultSet.getDouble(resultSet.getColumnIndex("SALARY"));
  ```

### isColumnNull

isColumnNull(columnIndex: number): boolean

Checks whether the value in the specified column is null.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Parameters**

| Name     | Type  | Mandatory| Description                   |
| ----------- | ------ | ---- | ----------------------- |
| columnIndex | number | Yes  | Index of the target column, starting from 0.|

**Return value**

| Type   | Description                                                     |
| ------- | --------------------------------------------------------- |
| boolean | Returns **true** if the value is null; returns **false** otherwise.|

**Error codes**

For details about the error codes, see [RDB Error Codes](../errorcodes/errorcode-data-rdb.md).

| **ID**| **Error Message**                                                |
| ------------ | ------------------------------------------------------------ |
| 14800013     | The column value is null or the column type is incompatible. |

**Example**

  ```js
const isColumnNull = resultSet.isColumnNull(resultSet.getColumnIndex("CODES"));
  ```

### close

close(): void

Closes this result set.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Example**

  ```js
let predicatesClose = new relationalStore.RdbPredicates("EMPLOYEE");
let promiseClose = store.query(predicatesClose, ["ID", "NAME", "AGE", "SALARY", "CODES"]);
promiseClose.then((resultSet) => {
  resultSet.close();
}).catch((err) => {
  console.error(`resultset close failed, code is ${err.code},message is ${err.message}`);
});
  ```

**Error codes**

For details about the error codes, see [RDB Error Codes](../errorcodes/errorcode-data-rdb.md).

| **ID**| **Error Message**                                                |
| ------------ | ------------------------------------------------------------ |
| 14800012     | The result set is empty or the specified location is invalid. |
