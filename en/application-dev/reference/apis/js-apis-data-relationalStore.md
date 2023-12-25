# @ohos.data.relationalStore (RDB Store)

The relational database (RDB) store manages data based on relational models. It provides a complete mechanism for managing local databases based on the underlying SQLite. To satisfy different needs in complicated scenarios, the RDB store offers a series of APIs for performing operations such as adding, deleting, modifying, and querying data, and supports direct execution of SQL statements. The worker threads are not supported.

ArkTS supports the following basic data types: number, string, binary data, and Boolean. 

To ensure successful read and write of data, the data size cannot exceed 2 MB. If a data record exceeds 2 MB, it can be inserted successfully but cannot be read.

The **relationalStore** module provides the following functions:

- [RdbPredicates](#rdbpredicates): provides predicates indicating the nature, feature, or relationship of a data entity in an RDB store. It is used to define the operation conditions for an RDB store.
- [RdbStore](#rdbstore): provides APIs for managing data in an RDB store.
- [Resultset](#resultset): provides APIs for accessing the result set obtained from the RDB store. 

> **NOTE**
> 
> The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```ts
import relationalStore from '@ohos.data.relationalStore';
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

| **ID**| **Error Message**                                               |
| ------------ | ----------------------------------------------------------- |
| 14800010     | Failed to open or delete database by invalid database path. |
| 14800011     | Failed to open database by database corrupted.              |
| 14800000     | Inner error.                                                |
| 14801001     | Only supported in stage mode.                               |
| 14801002     | The data group id is not valid.                             |

**Example**

FA model:

```js
import featureAbility from '@ohos.ability.featureAbility';
import { BusinessError } from "@ohos.base";

let store: relationalStore.RdbStore | undefined = undefined;
let context = getContext(this);

const STORE_CONFIG: relationalStore.StoreConfig = {
  name: "RdbTest.db",
  securityLevel: relationalStore.SecurityLevel.S1
};

relationalStore.getRdbStore(context, STORE_CONFIG, (err: BusinessError, rdbStore: relationalStore.RdbStore) => {
  store = rdbStore;
  if (err) {
    console.error(`Get RdbStore failed, code is ${err.code},message is ${err.message}`);
    return;
  }
  console.info('Get RdbStore successfully.');
})
```

Stage model:

```ts
import UIAbility from '@ohos.app.ability.UIAbility';
import window from '@ohos.window';
import { BusinessError } from "@ohos.base";

let store: relationalStore.RdbStore | undefined = undefined;

class EntryAbility extends UIAbility {
  onWindowStageCreate(windowStage: window.WindowStage) {
    const STORE_CONFIG: relationalStore.StoreConfig = {
      name: "RdbTest.db",
      securityLevel: relationalStore.SecurityLevel.S1
    };
        
    relationalStore.getRdbStore(this.context, STORE_CONFIG, (err: BusinessError, rdbStore: relationalStore.RdbStore) => {
      store = rdbStore;
      if (err) {
        console.error(`Get RdbStore failed, code is ${err.code},message is ${err.message}`);
        return;
      }
      console.info('Get RdbStore successfully.');
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

| **ID**| **Error Message**                                               |
| ------------ | ----------------------------------------------------------- |
| 14800010     | Failed to open or delete database by invalid database path. |
| 14800011     | Failed to open database by database corrupted.              |
| 14800000     | Inner error.                                                |
| 14801001     | Only supported in stage mode.                               |
| 14801002     | The data group id is not valid.                             |

**Example**

FA model:

```js
import featureAbility from '@ohos.ability.featureAbility';
import { BusinessError } from "@ohos.base";

let store: relationalStore.RdbStore | undefined = undefined;
let context = getContext(this);

const STORE_CONFIG: relationalStore.StoreConfig = {
  name: "RdbTest.db",
  securityLevel: relationalStore.SecurityLevel.S1
};

relationalStore.getRdbStore(context, STORE_CONFIG).then(async (rdbStore: relationalStore.RdbStore) => {
  store = rdbStore;
  console.info('Get RdbStore successfully.')
}).catch((err: BusinessError) => {
  console.error(`Get RdbStore failed, code is ${err.code},message is ${err.message}`);
})
```

Stage model:

```ts
import UIAbility from '@ohos.app.ability.UIAbility';
import window from '@ohos.window';
import { BusinessError } from "@ohos.base";

let store: relationalStore.RdbStore | undefined = undefined;

class EntryAbility extends UIAbility {
  onWindowStageCreate(windowStage: window.WindowStage) {
    const STORE_CONFIG: relationalStore.StoreConfig = {
      name: "RdbTest.db",
      securityLevel: relationalStore.SecurityLevel.S1
    };

    relationalStore.getRdbStore(this.context, STORE_CONFIG).then(async (rdbStore: relationalStore.RdbStore) => {
      store = rdbStore;
      console.info('Get RdbStore successfully.')
    }).catch((err: BusinessError) => {
      console.error(`Get RdbStore failed, code is ${err.code},message is ${err.message}`);
    })
  }
}
```

## relationalStore.deleteRdbStore

deleteRdbStore(context: Context, name: string, callback: AsyncCallback&lt;void&gt;): void

Deletes an RDB store. This API uses an asynchronous callback to return the result.

After the deletion, you are advised to set the database object to null. If a customized path is set in [StoreConfig](#storeconfig) when an RDB store is created, using this API cannot delete the RDB store. Use [deleteRdbStore<sup>10+</sup>](#relationalstoredeleterdbstore10) instead.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Parameters**

| Name  | Type                     | Mandatory| Description                                                        |
| -------- | ------------------------- | ---- | ------------------------------------------------------------ |
| context  | Context                   | Yes  | Application context.<br>For details about the application context of the FA model, see [Context](js-apis-inner-app-context.md).<br>For details about the application context of the stage model, see [Context](js-apis-inner-application-uiAbilityContext.md).|
| name     | string                    | Yes  | Name of the RDB store to delete.                                                |
| callback | AsyncCallback&lt;void&gt; | Yes  | Callback invoked to return the result.                                      |

**Error codes**

For details about the error codes, see [RDB Error Codes](../errorcodes/errorcode-data-rdb.md).

| **ID**| **Error Message**                                               |
| ------------ | ----------------------------------------------------------- |
| 14800010     | Failed to open or delete database by invalid database path. |
| 14800000     | Inner error.                                                |

**Example**

FA model:

```js
import featureAbility from '@ohos.ability.featureAbility';
import { BusinessError } from "@ohos.base";

let store: relationalStore.RdbStore | undefined = undefined;
let context = getContext(this);

relationalStore.deleteRdbStore(context, "RdbTest.db", (err: BusinessError) => {
  if (err) {
    console.error(`Delete RdbStore failed, code is ${err.code},message is ${err.message}`);
    return;
  }
  store = undefined;
  console.info('Delete RdbStore successfully.');
})
```

Stage model:

```ts
import UIAbility from '@ohos.app.ability.UIAbility';
import window from '@ohos.window';
import { BusinessError } from "@ohos.base";

let store: relationalStore.RdbStore | undefined = undefined;

class EntryAbility extends UIAbility {
  onWindowStageCreate(windowStage: window.WindowStage){
    relationalStore.deleteRdbStore(this.context, "RdbTest.db", (err: BusinessError) => {
      if (err) {
        console.error(`Delete RdbStore failed, code is ${err.code},message is ${err.message}`);
        return;
      }
      store = undefined;
      console.info('Delete RdbStore successfully.');
    })
  }
}
```

## relationalStore.deleteRdbStore

deleteRdbStore(context: Context, name: string): Promise&lt;void&gt;

Deletes an RDB store. This API uses a promise to return the result.

After the deletion, you are advised to set the database object to null. If a customized path is set in [StoreConfig](#storeconfig) when an RDB store is created, using this API cannot delete the RDB store. Use [deleteRdbStore<sup>10+</sup>](#relationalstoredeleterdbstore10-1) instead.

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

| **ID**| **Error Message**                                               |
| ------------ | ----------------------------------------------------------- |
| 14800010     | Failed to open or delete database by invalid database path. |
| 14800000     | Inner error.                                                |

**Example**

FA model:

```js
import featureAbility from '@ohos.ability.featureAbility';
import { BusinessError } from "@ohos.base";

let store: relationalStore.RdbStore | undefined = undefined;
let context = getContext(this);

relationalStore.deleteRdbStore(context, "RdbTest.db").then(()=>{
  store = undefined;
  console.info('Delete RdbStore successfully.');
}).catch((err: BusinessError) => {
  console.error(`Delete RdbStore failed, code is ${err.code},message is ${err.message}`);
})
```

Stage model:

```ts
import UIAbility from '@ohos.app.ability.UIAbility';
import window from '@ohos.window';
import { BusinessError } from "@ohos.base";

let store: relationalStore.RdbStore | undefined = undefined;

class EntryAbility extends UIAbility {
  onWindowStageCreate(windowStage: window.WindowStage){
    relationalStore.deleteRdbStore(this.context, "RdbTest.db").then(()=>{
      store = undefined;
      console.info('Delete RdbStore successfully.');
    }).catch((err: BusinessError) => {
      console.error(`Delete RdbStore failed, code is ${err.code},message is ${err.message}`);
    })
  }
}
```

## relationalStore.deleteRdbStore<sup>10+</sup>

deleteRdbStore(context: Context, config: StoreConfig, callback: AsyncCallback\<void>): void

Deletes an RDB store. This API uses an asynchronous callback to return the result.

After the deletion, you are advised to set the database object to null. If the database file is in the public sandbox directory, you must use this API to delete the database. If the database is accessed by multiple processes at the same time, you are advised to send a database deletion notification to other processes. Use this API to delete the RDB store that has a customized path set in [StoreConfig](#storeconfig).

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Parameters**

| Name  | Type                       | Mandatory| Description                                                        |
| -------- | --------------------------- | ---- | ------------------------------------------------------------ |
| context  | Context                     | Yes  | Application context.<br>For details about the application context of the FA model, see [Context](js-apis-inner-app-context.md).<br>For details about the application context of the stage model, see [Context](js-apis-inner-application-uiAbilityContext.md).|
| config   | [StoreConfig](#storeconfig) | Yes  | Configuration of the RDB store.                               |
| callback | AsyncCallback&lt;void&gt;   | Yes  | Callback invoked to return the result.                                      |

**Error codes**

For details about the error codes, see [RDB Error Codes](../errorcodes/errorcode-data-rdb.md).

| **ID**| **Error Message**                                               |
| ------------ | ----------------------------------------------------------- |
| 14800010     | Failed to open or delete database by invalid database path. |
| 14800000     | Inner error.                                                |
| 14801001     | Only supported in stage mode.                               |
| 14801002     | The data group id is not valid.                             |

**Example**

FA model:

```js
import featureAbility from '@ohos.ability.featureAbility';
import { BusinessError } from "@ohos.base";

let store: relationalStore.RdbStore | undefined = undefined;
let context = getContext(this);

const STORE_CONFIG: relationalStore.StoreConfig = {
  name: "RdbTest.db",
  securityLevel: relationalStore.SecurityLevel.S1
};

relationalStore.deleteRdbStore(context, STORE_CONFIG, (err: BusinessError) => {
  if (err) {
    console.error(`Delete RdbStore failed, code is ${err.code},message is ${err.message}`);
    return;
  }
  store = undefined;
  console.info('Delete RdbStore successfully.');
})
```

Stage model:

```ts
import UIAbility from '@ohos.app.ability.UIAbility';
import window from '@ohos.window';
import { BusinessError } from "@ohos.base";

let store: relationalStore.RdbStore | undefined = undefined;

class EntryAbility extends UIAbility {
  onWindowStageCreate(windowStage: window.WindowStage){
    const STORE_CONFIG: relationalStore.StoreConfig = {
      name: "RdbTest.db",
      securityLevel: relationalStore.SecurityLevel.S1
    };
    relationalStore.deleteRdbStore(this.context, STORE_CONFIG, (err: BusinessError) => {
      if (err) {
        console.error(`Delete RdbStore failed, code is ${err.code},message is ${err.message}`);
        return;
      }
      store = undefined;
      console.info('Delete RdbStore successfully.');
    })
  }
}

```

## relationalStore.deleteRdbStore<sup>10+</sup>

deleteRdbStore(context: Context, config: StoreConfig): Promise\<void>

Deletes an RDB store. This API uses a promise to return the result.

After the deletion, you are advised to set the database object to null. If the database file is in the public sandbox directory, you must use this API to delete the database. If the database is accessed by multiple processes at the same time, you are advised to send a database deletion notification to other processes. Use this API to delete the RDB store that has a customized path set in [StoreConfig](#storeconfig).

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Parameters**

| Name | Type                       | Mandatory| Description                                                        |
| ------- | --------------------------- | ---- | ------------------------------------------------------------ |
| context | Context                     | Yes  | Application context.<br>For details about the application context of the FA model, see [Context](js-apis-inner-app-context.md).<br>For details about the application context of the stage model, see [Context](js-apis-inner-application-uiAbilityContext.md).|
| config  | [StoreConfig](#storeconfig) | Yes  | Configuration of the RDB store.                               |

**Return value**

| Type               | Description                     |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [RDB Error Codes](../errorcodes/errorcode-data-rdb.md).

| **ID**| **Error Message**                                               |
| ------------ | ----------------------------------------------------------- |
| 14800010     | Failed to open or delete database by invalid database path. |
| 14800000     | Inner error.                                                |
| 14801001     | Only supported in stage mode.                               |
| 14801002     | The data group id is not valid.                             |

**Example**

FA model:

```js
import featureAbility from '@ohos.ability.featureAbility';
import { BusinessError } from "@ohos.base";

let store: relationalStore.RdbStore | undefined = undefined;
let context = getContext(this);

const STORE_CONFIG: relationalStore.StoreConfig = {
  name: "RdbTest.db",
  securityLevel: relationalStore.SecurityLevel.S1
};

relationalStore.deleteRdbStore(context, STORE_CONFIG).then(()=>{
  store = undefined;
  console.info('Delete RdbStore successfully.');
}).catch((err: BusinessError) => {
  console.error(`Delete RdbStore failed, code is ${err.code},message is ${err.message}`);
})
```

Stage model:

```ts
import UIAbility from '@ohos.app.ability.UIAbility';
import window from '@ohos.window';
import { BusinessError } from "@ohos.base";

let store: relationalStore.RdbStore | undefined = undefined;

class EntryAbility extends UIAbility {
  onWindowStageCreate(windowStage: window.WindowStage){
    const STORE_CONFIG: relationalStore.StoreConfig = {
      name: "RdbTest.db",
      securityLevel: relationalStore.SecurityLevel.S1
    };
    relationalStore.deleteRdbStore(this.context, STORE_CONFIG).then(()=>{
      store = undefined;
      console.info('Delete RdbStore successfully.');
    }).catch((err: BusinessError) => {
      console.error(`Delete RdbStore failed, code is ${err.code},message is ${err.message}`);
    })
  }
}
```

## StoreConfig

Defines the RDB store configuration.

| Name       | Type         | Mandatory| Description                                                     |
| ------------- | ------------- | ---- | --------------------------------------------------------- |
| name          | string        | Yes  | Database file name.<br>**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core  |
| securityLevel | [SecurityLevel](#securitylevel) | Yes  | Security level of the RDB store.<br>**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core|
| encrypt       | boolean       | No  | Whether to encrypt the RDB store.<br>The value **true** means to encrypt the RDB store; the value **false** (default) means the opposite.<br>**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core|
| dataGroupId<sup>10+</sup> | string | No| Application group ID, which needs to be obtained from AppGallery.<br>**Model restriction**: This attribute can be used only in the stage model.<br>This parameter is supported since API version 10. The **RdbStore** instance is created in the sandbox directory corresponding to the specified **dataGroupId**. If this parameter is not specified, the **RdbStore** instance is created in the sandbox directory of the application.<br>**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core|
| customDir<sup>11+</sup> | string | No| Customized path of the RDB store.<br>**Constraints**: The value cannot exceed 128 bytes.<br>This parameter is supported since API version 11. The RDB store directory is in the **context.databaseDir**/**rdb**/**customDir** format. **context.databaseDir** specifies the application sandbox path. **rdb** is a fixed field that indicates an RDB store. **customDir** specifies the customized path. If this parameter is not specified, the **RdbStore** instance is created in the sandbox directory of the application.<br>**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core|
| isSearchable<sup>11+</sup> | boolean | No| Whether the RDB store is searchable. The value **true** means the RDB store is searchable; the value **false** means the opposite. The default value is **false**.<br>**System API**: This is a system API.<br>This parameter is supported since API version 11.<br>**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core|
| autoCleanDirtyData<sup>11+<sup> | boolean | No| Whether to automatically clear the dirty data (data that has been deleted from the cloud) from the local device. The value **true** means to clear the dirty data automatically. The value **false** means to clear the data manually. The default value is **true**.<br>This parameter applies to the RDB stores with device-cloud synergy. To manually clear the dirty data, use [cleanDirtyData<sup>11+</sup>](#cleandirtydata11).<br>This parameter is supported since API version 11.<br>**System capability**: SystemCapability.DistributedDataManager.CloudSync.Client|

## SecurityLevel

Enumerates the RDB store security levels. Use the enum name rather than the enum value.

> **NOTE**
>
> To perform data synchronization operations, the RDB store security level must be lower than or equal to that of the peer device. For details, see the [Access Control Mechanism in Cross-Device Synchronization](../../database/access-control-by-device-and-data-level.md#access-control-mechanism-in-cross-device-synchronization).

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

| Name| Value  | Description                                                        |
| ---- | ---- | ------------------------------------------------------------ |
| S1   | 1    | The RDB store security level is low. If data leakage occurs, minor impact will be caused on the database. For example, an RDB store that contains system data such as wallpapers.|
| S2   | 2    | The RDB store security level is medium. If data leakage occurs, moderate impact will be caused on the database. For example, an RDB store that contains information created by users or call records, such as audio or video clips.|
| S3   | 3    | The RDB store security level is high. If data leakage occurs, major impact will be caused on the database. For example, an RDB store that contains information such as user fitness, health, and location data.|
| S4   | 4    | The RDB store security level is critical. If data leakage occurs, severe impact will be caused on the database. For example, an RDB store that contains information such as authentication credentials and financial data.|

## AssetStatus<sup>10+</sup>

Enumerates the asset statuses. Use the enum name rather than the enum value.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

| Name                             | Value  | Description            |
| ------------------------------- | --- | -------------- |
| ASSET_NORMAL     | 1  | The asset is in normal status.     |
| ASSET_INSERT | 2 | The asset is to be inserted to the cloud.|
| ASSET_UPDATE | 3 | The asset is to be updated to the cloud.|
| ASSET_DELETE | 4 | The asset is to be deleted from the cloud.|
| ASSET_ABNORMAL    | 5   | The asset is in abnormal status.     |
| ASSET_DOWNLOADING | 6   | The asset is being downloaded to a local device.|

## Asset<sup>10+</sup>

Defines information about an asset (such as a document, image, and video). The asset APIs do not support **Datashare**.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

| Name         | Type                         | Mandatory | Description          |
| ----------- | --------------------------- | --- | ------------ |
| name        | string                      | Yes  | Asset name.      |
| uri         | string                      | Yes  | Asset URI, which is an absolute path in the system.      |
| path        | string                      | Yes  | Application sandbox path of the asset.      |
| createTime  | string                      | Yes  | Time when the asset was created.  |
| modifyTime  | string                      | Yes  | Time when the asset was last modified.|
| size        | string                      | Yes  | Size of the asset.   |
| status      | [AssetStatus](#assetstatus10) | No  | Asset status. The default value is **ASSET_NORMAL**.       |

## Assets<sup>10+</sup>

Defines an array of the [Asset](#asset10) type.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

| Type   | Description                |
| ------- | -------------------- |
| [Asset](#asset10)[] | Array of assets.  |

## ValueType

Enumerates the types of the value in a KV pair. The type varies with the parameter function.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

| Type   | Description                |
| ------- | -------------------- |
| null<sup>10+</sup>    | Null.  |
| number  | Number.  |
| string  | String.  |
| boolean | Boolean.|
| Uint8Array<sup>10+</sup>           | Uint8 array.           |
| Asset<sup>10+</sup>  | [Asset](#asset10).    |
| Assets<sup>10+</sup> | [Assets](#assets10).|

## ValuesBucket

Enumerates the types of the key in a KV pair. This type is not multi-thread safe. If a **ValuesBucket** instance is operated by multiple threads at the same time in an application, use a lock for the instance.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

| Key Type| Value Type                  |
| ------ | ----------------------- |
| number | The primary key is a number.|
| string | The primary key is a string.|

## PRIKeyType<sup>10+</sup> 

Enumerates the types of the primary key in a row of a database table.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

| Type            | Description                              |
| ---------------- | ---------------------------------- |
| number | The primary key is a number.|
| string | The primary key is a string.|

## UTCTime<sup>10+</sup>

Represents the data type of the UTC time.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

| Type| Description           |
| ---- | --------------- |
| Date | UTC time.|

## ModifyTime<sup>10+</sup> 

Represents the data type of the primary key and modification time of a database table.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

| Type                                                   | Description                                                        |
| ------------------------------------------------------- | ------------------------------------------------------------ |
| Map<[PRIKeyType](#prikeytype10), [UTCTime](#utctime10)> | The key is the primary key of a row in the database table, and the value is the last modification time of the row in UTC format.|

## SyncMode

Enumerates the database synchronization modes. Use the enum name rather than the enum value.

| Name          | Value  | Description                              |
| -------------- | ---- | ---------------------------------- |
| SYNC_MODE_PUSH                       | 0   | Push data from a local device to a remote device.<br>**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core|
| SYNC_MODE_PULL                       | 1   | Pull data from a remote device to a local device.<br>**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core|
| SYNC_MODE_TIME_FIRST<sup>10+</sup>   | 4   | Synchronize with the data with the latest modification time.<br>**System capability**: SystemCapability.DistributedDataManager.CloudSync.Client|
| SYNC_MODE_NATIVE_FIRST<sup>10+</sup> | 5   | Synchronize data from a local device to the cloud.<br>**System capability**: SystemCapability.DistributedDataManager.CloudSync.Client|
| SYNC_MODE_CLOUD_FIRST<sup>10+</sup>  | 6   | Synchronize data from the cloud to a local device.<br>**System capability**: SystemCapability.DistributedDataManager.CloudSync.Client|

## Origin<sup>11+</sup>

Enumerates the data sources. Use the enum name rather than the enum value.

**System capability**: SystemCapability.DistributedDataManager.CloudSync.Client

| Name          | Value  | Description                              |
| -------------- | ---- | ---------------------------------- |
| LOCAL       | 0   | Local data.     |
| CLOUD       | 1   | Cloud data.    |
| REMOTE      | 2   | Remote device data.|

## Field<sup>11+</sup>

Enumerates the special fields used in predicates. Use the enum name rather than the enum value.

**System capability**: SystemCapability.DistributedDataManager.CloudSync.Client

| Name          | Value  | Description                              |
| -------------- | ---- | ---------------------------------- |
| CURSOR_FIELD        | '#_cursor'     | Field name to be searched based on the cursor.|
| ORIGIN_FIELD        | '#_origin'     | Data source to be searched based on the cursor.   |
| DELETED_FLAG_FIELD  | '#_deleted_flag' | Whether the dirty data (data deleted from the cloud) is cleared from the local device. It fills in the result set returned on the search based on the cursor. <br>The value **true** means the dirty data is cleared; the value **false** means the opposite.|
| OWNER_FIELD  | '#_cloud_owner' | Party who shares the data. It fills in the result set returned when the owner of the shared data is searched.|
| PRIVILEGE_FIELD  | '#_cloud_privilege' | Operation permission on the shared data. It fills in the result set returned when the permission on the shared data is searched.|
| SHARING_RESOURCE_FIELD   | '#_sharing_resource_field' | Resource shared. It fills in the result set returned when the shared resource is searched.|

## SubscribeType

Enumerates the subscription types. Use the enum name rather than the enum value.

**Required permissions**: ohos.permission.DISTRIBUTED_DATASYNC

| Name                 | Value  | Description              |
| --------------------- | ---- | ------------------ |
| SUBSCRIBE_TYPE_REMOTE | 0    | Subscribe to remote data changes.<br>**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core|
| SUBSCRIBE_TYPE_CLOUD<sup>10+</sup> | 1  | Subscribe to cloud data changes.<br>**System capability**: SystemCapability.DistributedDataManager.CloudSync.Client|
| SUBSCRIBE_TYPE_CLOUD_DETAILS<sup>10+</sup> | 2  | Subscribe to cloud data change details.<br>**System capability**: SystemCapability.DistributedDataManager.CloudSync.Client|

## ChangeType<sup>10+</sup>

Enumerates data change types. Use the enum name rather than the enum value.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Required permissions**: ohos.permission.DISTRIBUTED_DATASYNC

| Name                        | Value  | Description                        |
| -------------------------- | --- | -------------------------- |
| DATA_CHANGE  | 0   | Data change.  |
| ASSET_CHANGE | 1   | Asset change.|

## ChangeInfo<sup>10+</sup>

Defines the details about the device-cloud synchronization process.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

| Name    | Type                              | Mandatory| Description                                                        |
| -------- | ---------------------------------- | ---- | ------------------------------------------------------------ |
| table    | string                             | Yes  | Name of the table with data changes.                                    |
| type     | [ChangeType](#changetype10)        | Yes  | Type of the data changed, which can be data or asset.        |
| inserted | Array\<string\> \| Array\<number\> | Yes  | Location where data is inserted. If the primary key of the table is of the string type, the value is the value of the primary key. Otherwise, the value is the row number of the inserted data.|
| updated  | Array\<string\> \| Array\<number\> | Yes  | Location where data is updated. If the primary key of the table is of the string type, the value is the value of the primary key. Otherwise, the value is the row number of the updated data.|
| deleted  | Array\<string\> \| Array\<number\> | Yes  | Location where data is deleted. If the primary key of the table is of the string type, the value is the value of the primary key. Otherwise, the value is the row number of the deleted data.|

## DistributedType<sup>10+</sup>

Enumerates the distributed table types. Use the enum name rather than the enum value.

**Required permissions**: ohos.permission.DISTRIBUTED_DATASYNC

| Name               | Value  | Description                                                                                                |
| ------------------ | --- | -------------------------------------------------------------------------------------------------- |
| DISTRIBUTED_DEVICE | 0  | Distributed database table synchronized between devices.<br>**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core              |
| DISTRIBUTED_CLOUD  | 1   | Distributed database table synchronized between the device and the cloud.<br>**System capability**: SystemCapability.DistributedDataManager.CloudSync.Client|

## Reference<sup>11+</sup>

Represents the reference between tables by field. If table **b** references table **a**, table **a** is the source table and **b** is the target table.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**System API**: This is a system API.

| Name      | Type  | Mandatory| Description                                    |
| ---------- | ------ | ---- | ---------------------------------------- |
| sourceTable | string | Yes  | Source table.  |
| targetTable | string | Yes  | Target table.  |
| refFields   | {[src: string]: string} | Yes  | Fields referenced. In a KV pair, the key indicates the field in the source table, and the value indicates the field in the target table.      |

## DistributedConfig<sup>10+</sup>

Defines the configuration of the distributed mode of tables.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

| Name    | Type   | Mandatory| Description                                                        |
| -------- | ------- | ---- | ------------------------------------------------------------ |
| autoSync   | boolean | Yes  | The value **true** means both automatic synchronization and manual synchronization are supported for the table. The value **false** means only manual synchronization is supported for the table.|
| references<sup>11+</sup> | Array&lt;[Reference](#reference11)&gt; | No  | References between tables. You can reference multiple fields, and their values must be the same in the source and target tables. By default, database tables are not referenced with each other.<br>**System API**: This is a system API.<br>This parameter is supported since API version 11.|

## ConflictResolution<sup>10+</sup>

Defines the resolution to use when **insert()** and **update()** conflict. Use the enum name rather than the enum value.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

| Name                | Value  | Description                                                        |
| -------------------- | ---- | ------------------------------------------------------------ |
| ON_CONFLICT_NONE | 0 | No operation is performed.|
| ON_CONFLICT_ROLLBACK | 1    | Abort the SQL statement and roll back the current transaction.               |
| ON_CONFLICT_ABORT    | 2    | Abort the current SQL statement and revert any changes made by the current SQL statement. However, the changes made by the previous SQL statement in the same transaction are retained and the transaction remains active.|
| ON_CONFLICT_FAIL     | 3    | Abort the current SQL statement. The **FAIL** resolution does not revert previous changes made by the failed SQL statement or end the transaction.|
| ON_CONFLICT_IGNORE   | 4    | Skip the rows that contain constraint violations and continue to process the subsequent rows of the SQL statement.|
| ON_CONFLICT_REPLACE  | 5    | Delete pre-existing rows that cause the constraint violation before inserting or updating the current row, and continue to execute the command normally.|

## Progress<sup>10+</sup>

Enumerates the device-cloud synchronization processes. Use the enum name rather than the enum value.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

| Name            | Value  | Description                    |
| ---------------- | ---- | ------------------------ |
| SYNC_BEGIN       | 0    | The device-cloud synchronization starts.  |
| SYNC_IN_PROGRESS | 1    | The device-cloud synchronization is in progress.|
| SYNC_FINISH      | 2    | The device-cloud synchronization is complete.|

## Statistic<sup>10+</sup>

Represents the device-cloud synchronization statistics information.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

| Name      | Type  | Mandatory| Description                                    |
| ---------- | ------ | ---- | ---------------------------------------- |
| total      | number | Yes  | Total number of rows to be synchronized between the device and cloud in the database table.    |
| successful | number | Yes  | Number of rows that are successfully synchronized between the device and cloud in the database table.      |
| failed     | number | Yes  | Number of rows that failed to be synchronized between the device and cloud in the database table.      |
| remained   | number | Yes  | Number of rows that are not executed for device-cloud synchronization in the database table.|

## TableDetails<sup>10+</sup>

Represents the upload and download statistics of device-cloud synchronization tasks.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

| Name    | Type                     | Mandatory| Description                                      |
| -------- | ------------------------- | ---- | ------------------------------------------ |
| upload   | [Statistic](#statistic10) | Yes  | Statistics of the device-cloud upload tasks.|
| download | [Statistic](#statistic10) | Yes  | Statistics of the device-cloud download tasks.|

## ProgressCode<sup>10+</sup>

Enumerates the device-cloud synchronization states. Use the enum name rather than the enum value.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

| Name                 | Value  | Description                                                        |
| --------------------- | ---- | ------------------------------------------------------------ |
| SUCCESS               | 0    | The device-cloud synchronization is successful.                                      |
| UNKNOWN_ERROR         | 1    | An unknown error occurs during device-cloud synchronization.                              |
| NETWORK_ERROR         | 2    | A network error occurs during device-cloud synchronization.                              |
| CLOUD_DISABLED        | 3    | The cloud is unavailable.                                            |
| LOCKED_BY_OTHERS      | 4    | The device-cloud synchronization of another device is being performed.<br>Start device-cloud synchronization after checking that cloud resources are not occupied by other devices.|
| RECORD_LIMIT_EXCEEDED | 5    | The number of records or size of the data to be synchronized exceeds the maximum. The maximum value is configured on the cloud.|
| NO_SPACE_FOR_ASSET    | 6    | The remaining cloud space is less than the size of the data to be synchronized.                    |

## ProgressDetails<sup>10+</sup>

Represents the statistics of the overall device-cloud synchronization (upload and download) tasks.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

| Name    | Type                                             | Mandatory| Description                                                        |
| -------- | ------------------------------------------------- | ---- | ------------------------------------------------------------ |
| schedule | [Progress](#progress10)                           | Yes  | Device-cloud synchronization process.                                          |
| code     | [ProgressCode](#progresscode10)                   | Yes  | Device-cloud synchronization state.                                    |
| details  | [table: string] : [TableDetails](#tabledetails10) | Yes  | Statistics of each table.<br>The key indicates the table name, and the value indicates the device-cloud synchronization statistics of the table.|

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

```ts
let predicates = new relationalStore.RdbPredicates("EMPLOYEE");
```

### inDevices

inDevices(devices: Array&lt;string&gt;): RdbPredicates

Sets an **RdbPredicates** to specify the remote devices to connect on the network during distributed database synchronization.

> **NOTE**
>
> The value of **devices** can be obtained by [deviceManager.getAvailableDeviceListSync](js-apis-distributedDeviceManager.md#getavailabledevicelistsync).
If **inDevices** is specified in **predicates** when **sync()** is called, data is synchronized with the specified device. If **inDevices** is not specified, data is synchronized with all devices on the network by default.

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

```ts
import deviceManager from '@ohos.distributedDeviceManager';

let dmInstance: deviceManager.DeviceManager;
let deviceIds: Array<string> = [];

try {
  dmInstance = deviceManager.createDeviceManager("com.example.appdatamgrverify");
  let devices: Array<deviceManager.DeviceBasicInfo> = dmInstance.getAvailableDeviceListSync();
  for (let i = 0; i < devices.length; i++) {
    deviceIds[i] = devices[i].networkId!;
  }
} catch (err) {
  let code = (err as BusinessError).code;
  let message = (err as BusinessError).message
  console.error("createDeviceManager errCode:" + code + ",errMessage:" + message);
}

let predicates = new relationalStore.RdbPredicates("EMPLOYEE");
predicates.inDevices(deviceIds);

if(store != undefined) {
  // Set the RDB store version.
  (store as relationalStore.RdbStore).version = 3;
  // Obtain the RDB store version.
  console.info(`RdbStore version is ${(store as relationalStore.RdbStore).version}`);
}
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

```ts
let predicates = new relationalStore.RdbPredicates("EMPLOYEE");
predicates.inAllDevices();
```

### equalTo

equalTo(field: string, value: ValueType): RdbPredicates


Sets an **RdbPredicates** object to match the fields in the specified column that are equal to the given value.

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

```ts
// Locate data of Lisa in the EMPLOYEE table.
let predicates = new relationalStore.RdbPredicates("EMPLOYEE");
predicates.equalTo("NAME", "Lisa");
```


### notEqualTo

notEqualTo(field: string, value: ValueType): RdbPredicates


Sets an **RdbPredicates** object to match the fields in the specified column that are not equal to the given value.

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

```ts
// Locate data of the employees whose name is not Lisa in the table.
let predicates = new relationalStore.RdbPredicates("EMPLOYEE");
predicates.notEqualTo("NAME", "Lisa");
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

```ts
let predicates = new relationalStore.RdbPredicates("EMPLOYEE");
predicates.equalTo("NAME", "Lisa")
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

```ts
let predicates = new relationalStore.RdbPredicates("EMPLOYEE");
predicates.equalTo("NAME", "Lisa")
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

```ts
// Locate the employees named Lisa or Rose in the table.
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

```ts
// Locate the field with name of Lisa and salary of 200.5 in the table.
let predicates = new relationalStore.RdbPredicates("EMPLOYEE");
predicates.equalTo("NAME", "Lisa")
    .and()
    .equalTo("SALARY", 200.5)
```

### contains

contains(field: string, value: string): RdbPredicates

Sets an **RdbPredicates** object to match the fields in the specified column that contain the given value.

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

```ts
// Locate data of the employees whose name contains os, for example, Rose, in the table.
let predicates = new relationalStore.RdbPredicates("EMPLOYEE");
predicates.contains("NAME", "os");
```

### beginsWith

beginsWith(field: string, value: string): RdbPredicates

Sets an **RdbPredicates** object to match the fields in the specified column that begin with the given value.

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

```ts
// Locate data of the employees whose name begins with Li, for example, Lisa, in the table.
let predicates = new relationalStore.RdbPredicates("EMPLOYEE");
predicates.beginsWith("NAME", "Li");
```

### endsWith

endsWith(field: string, value: string): RdbPredicates

Sets an **RdbPredicates** object to match the fields in the specified column that end with the given value.

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

```ts
// Locate data of the employees whose name ends with se, for example, Rose, in the table.
let predicates = new relationalStore.RdbPredicates("EMPLOYEE");
predicates.endsWith("NAME", "se");
```

### isNull

isNull(field: string): RdbPredicates

Sets an **RdbPredicates** object to match the fields in the specified column that are **null**.

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

```ts
let predicates = new relationalStore.RdbPredicates("EMPLOYEE");
predicates.isNull("NAME");
```

### isNotNull

isNotNull(field: string): RdbPredicates

Sets an **RdbPredicates** object to match the fields in the specified column that are not **null**.

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

```ts
let predicates = new relationalStore.RdbPredicates("EMPLOYEE");
predicates.isNotNull("NAME");
```

### like

like(field: string, value: string): RdbPredicates

Sets an **RdbPredicates** object to match the fields in the specified column that are similar to the given value.

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

```ts
// Locate data of the employees whose name is similar to os in the table, for example, Rose.
let predicates = new relationalStore.RdbPredicates("EMPLOYEE");
predicates.like("NAME", "%os%");
```

### glob

glob(field: string, value: string): RdbPredicates

Sets an **RdbPredicates** object to locate the fields in the specified column that match the given string.

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

```ts
// Locate data of the employees whose name matches the "?h*g" string in the table.
let predicates = new relationalStore.RdbPredicates("EMPLOYEE");
predicates.glob("NAME", "?h*g");
```

### between

between(field: string, low: ValueType, high: ValueType): RdbPredicates

Sets an **RdbPredicates** object to match the fields in the specified column that are within the given range (including the min. and max. values).

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Parameters**

| Name| Type                   | Mandatory| Description                      |
| ------ | ----------------------- | ---- | -------------------------- |
| field  | string                  | Yes  | Column name in the database table.        |
| low    | [ValueType](#valuetype) | Yes  | Minimum value to match.  |
| high   | [ValueType](#valuetype) | Yes  | Maximum value to match.|

**Return value**

| Type                                | Description                      |
| ------------------------------------ | -------------------------- |
| [RdbPredicates](#rdbpredicates) | **RdbPredicates** object created.|

**Example**

```ts
// Locate data of the employees with age between 10 and 50 (including 10 and 50) in the table.
let predicates = new relationalStore.RdbPredicates("EMPLOYEE");
predicates.between("AGE", 10, 50);
```

### notBetween

notBetween(field: string, low: ValueType, high: ValueType): RdbPredicates

Sets an **RdbPredicates** object to match the fields in the specified column that are out of the given range (excluding the min. and max. values).

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Parameters**

| Name| Type                   | Mandatory| Description                      |
| ------ | ----------------------- | ---- | -------------------------- |
| field  | string                  | Yes  | Column name in the database table.        |
| low    | [ValueType](#valuetype) | Yes  | Minimum value to match.  |
| high   | [ValueType](#valuetype) | Yes  | Maximum value to match.|

**Return value**

| Type                                | Description                      |
| ------------------------------------ | -------------------------- |
| [RdbPredicates](#rdbpredicates) | **RdbPredicates** object created.|

**Example**

```ts
// Locate data of the employees who are younger than 10 or older than 50 in the table.
let predicates = new relationalStore.RdbPredicates("EMPLOYEE");
predicates.notBetween("AGE", 10, 50);
```

### greaterThan

greaterThan(field: string, value: ValueType): RdbPredicates

Sets an **RdbPredicates** object to match the fields in the specified column that are greater than the given value.

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

```ts
// Locate data of the employees who are older than 18 in the table.
let predicates = new relationalStore.RdbPredicates("EMPLOYEE");
predicates.greaterThan("AGE", 18);
```

### lessThan

lessThan(field: string, value: ValueType): RdbPredicates

Sets an **RdbPredicates** object to match the fields in the specified column that are less than the given value.

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

```ts
// Locate data of the employees who are younger than 20 in the table.
let predicates = new relationalStore.RdbPredicates("EMPLOYEE");
predicates.lessThan("AGE", 20);
```

### greaterThanOrEqualTo

greaterThanOrEqualTo(field: string, value: ValueType): RdbPredicates

Sets an **RdbPredicates** object to match the fields in the specified column that are greater than or equal to the given value.

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

```ts
// Locate data of the employees who are 18 or older in the table.
let predicates = new relationalStore.RdbPredicates("EMPLOYEE");
predicates.greaterThanOrEqualTo("AGE", 18);
```

### lessThanOrEqualTo

lessThanOrEqualTo(field: string, value: ValueType): RdbPredicates

Sets an **RdbPredicates** object to match the fields in the specified column that are less than or equal to the given value.

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

```ts
// Locate data of the employees who are 20 or younger in the table.
let predicates = new relationalStore.RdbPredicates("EMPLOYEE");
predicates.lessThanOrEqualTo("AGE", 20);
```

### orderByAsc

orderByAsc(field: string): RdbPredicates

Sets an **RdbPredicates** object to sort the fields in the specified column in ascending order.

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

```ts
let predicates = new relationalStore.RdbPredicates("EMPLOYEE");
predicates.orderByAsc("NAME");
```

### orderByDesc

orderByDesc(field: string): RdbPredicates

Sets an **RdbPredicates** object to sort the fields in the specified column in descending order.

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

```ts
let predicates = new relationalStore.RdbPredicates("EMPLOYEE");
predicates.orderByDesc("AGE");
```

### distinct

distinct(): RdbPredicates

Sets an **RdbPredicates** object to filter out duplicate records.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Return value**

| Type                                | Description                          |
| ------------------------------------ | ------------------------------ |
| [RdbPredicates](#rdbpredicates) | **RdbPredicates** object that can filter out duplicate records.|

**Example**

```ts
let predicates = new relationalStore.RdbPredicates("EMPLOYEE");
predicates.equalTo("NAME", "Rose").distinct();
```

### limitAs

limitAs(value: number): RdbPredicates

Sets an **RdbPredicates** object to specify the maximum number of records.

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

```ts
let predicates = new relationalStore.RdbPredicates("EMPLOYEE");
predicates.equalTo("NAME", "Rose").limitAs(3);
```

### offsetAs

offsetAs(rowOffset: number): RdbPredicates

Sets an **RdbPredicates** object to specify the start position of the returned result.

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

```ts
let predicates = new relationalStore.RdbPredicates("EMPLOYEE");
predicates.equalTo("NAME", "Rose").offsetAs(3);
```

### groupBy

groupBy(fields: Array&lt;string&gt;): RdbPredicates

Sets an **RdbPredicates** object to group rows that have the same value into summary rows.

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

```ts
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

```ts
let predicates = new relationalStore.RdbPredicates("EMPLOYEE");
predicates.indexedBy("SALARY_INDEX");
```

### in

in(field: string, value: Array&lt;ValueType&gt;): RdbPredicates

Sets an **RdbPredicates** object to match the fields in the specified column that are in the given range.

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

```ts
// Locate data of the employees with age of [18, 20] in the table.
let predicates = new relationalStore.RdbPredicates("EMPLOYEE");
predicates.in("AGE", [18, 20]);
```

### notIn

notIn(field: string, value: Array&lt;ValueType&gt;): RdbPredicates

Sets an **RdbPredicates** object to match the fields in the specified column that are out of the given range.

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

```ts
// Locate data of all the employees except Lisa and Rose in the table.
let predicates = new relationalStore.RdbPredicates("EMPLOYEE");
predicates.notIn("NAME", ["Lisa", "Rose"]);
```

## RdbStore

Provides APIs to manage an RDB store.

Before using the APIs of this class, use [executeSql](#executesql) to initialize the database table structure and related data.

### Attributes<sup>10+</sup>

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

| Name        | Type           | Mandatory| Description                            |
| ------------ | ----------- | ---- | -------------------------------- |
| version<sup>10+</sup>  | number | Yes  | RDB store version, which is an integer greater than 0.      |

**Example**

```ts
// Set the RDB store version.
if(store != undefined) {
  (store as relationalStore.RdbStore).version = 3;
  // Obtain the RDB store version.
  console.info(`RdbStore version is ${store.version}`);
}
```

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

**Error codes**

For details about the error codes, see [RDB Error Codes](../errorcodes/errorcode-data-rdb.md).

| **ID**| **Error Message**                                |
| ------------ | -------------------------------------------- |
| 14800047     | The WAL file size exceeds the default limit. |
| 14800000     | Inner error.                                 |

**Example**

```ts
import { ValuesBucket } from '@ohos.data.ValuesBucket';

let key1 = "NAME";
let key2 = "AGE";
let key3 = "SALARY";
let key4 = "CODES";
let value1 = "Lisa";
let value2 = 18;
let value3 = 100.5;
let value4 = new Uint8Array([1, 2, 3, 4, 5]);
const valueBucket: ValuesBucket = {
  key1: value1,
  key2: value2,
  key3: value3,
  key4: value4,
};
if(store != undefined) {
  (store as relationalStore.RdbStore).insert("EMPLOYEE", valueBucket, (err: BusinessError, rowId: number) => {
    if (err) {
      console.error(`Insert is failed, code is ${err.code},message is ${err.message}`);
      return;
    }
    console.info(`Insert is successful, rowId = ${rowId}`);
  })
}
```

### insert<sup>10+</sup>

insert(table: string, values: ValuesBucket,  conflict: ConflictResolution, callback: AsyncCallback&lt;number&gt;):void

Inserts a row of data into a table. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Parameters**

| Name  | Type                                       | Mandatory| Description                                                      |
| -------- | ------------------------------------------- | ---- | ---------------------------------------------------------- |
| table    | string                                      | Yes  | Name of the target table.                                          |
| values   | [ValuesBucket](#valuesbucket)               | Yes  | Row of data to insert.                                |
| conflict | [ConflictResolution](#conflictresolution10) | Yes  | Resolution used to resolve the conflict.                                        |
| callback | AsyncCallback&lt;number&gt;                 | Yes  | Callback invoked to return the result. If the operation is successful, the row ID will be returned. Otherwise, **-1** will be returned.|

**Error codes**

For details about the error codes, see [RDB Error Codes](../errorcodes/errorcode-data-rdb.md).

| **ID**| **Error Message**                                |
| ------------ | -------------------------------------------- |
| 14800047     | The WAL file size exceeds the default limit. |
| 14800000     | Inner error.                                 |

**Example**

```ts
import { ValuesBucket } from '@ohos.data.ValuesBucket';

let key1 = "NAME";
let key2 = "AGE";
let key3 = "SALARY";
let key4 = "CODES";
let value1 = "Lisa";
let value2 = 18;
let value3 = 100.5;
let value4 = new Uint8Array([1, 2, 3, 4, 5]);
const valueBucket: ValuesBucket = {
  key1: value1,
  key2: value2,
  key3: value3,
  key4: value4,
};
if(store != undefined) {
  (store as relationalStore.RdbStore).insert("EMPLOYEE", valueBucket, relationalStore.ConflictResolution.ON_CONFLICT_REPLACE,
    (err: BusinessError, rowId: number) => {
      if (err) {
        console.error(`Insert is failed, code is ${err.code},message is ${err.message}`);
        return;
      }
      console.info(`Insert is successful, rowId = ${rowId}`);
  })
}
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
| 14800047     | The WAL file size exceeds the default limit. |
| 14800000     | Inner error.                                 |

**Example**

```ts
import { ValuesBucket } from '@ohos.data.ValuesBucket';
import { BusinessError } from "@ohos.base";

let key1 = "NAME";
let key2 = "AGE";
let key3 = "SALARY";
let key4 = "CODES";
let value1 = "Lisa";
let value2 = 18;
let value3 = 100.5;
let value4 = new Uint8Array([1, 2, 3, 4, 5]);
const valueBucket: ValuesBucket = {
  key1: value1,
  key2: value2,
  key3: value3,
  key4: value4,
};
if(store != undefined) {
  (store as relationalStore.RdbStore).insert("EMPLOYEE", valueBucket).then((rowId: number) => {
    console.info(`Insert is successful, rowId = ${rowId}`);
  }).catch((err: BusinessError) => {
    console.error(`Insert is failed, code is ${err.code},message is ${err.message}`);
  })
}
```

### insert<sup>10+</sup>

insert(table: string, values: ValuesBucket,  conflict: ConflictResolution):Promise&lt;number&gt;

Inserts a row of data into a table. This API uses a promise to return the result.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Parameters**

| Name  | Type                                       | Mandatory| Description                      |
| -------- | ------------------------------------------- | ---- | -------------------------- |
| table    | string                                      | Yes  | Name of the target table.          |
| values   | [ValuesBucket](#valuesbucket)               | Yes  | Row of data to insert.|
| conflict | [ConflictResolution](#conflictresolution10) | Yes  | Resolution used to resolve the conflict.        |

**Return value**

| Type                 | Description                                             |
| --------------------- | ------------------------------------------------- |
| Promise&lt;number&gt; | Promise used to return the result. If the operation is successful, the row ID will be returned. Otherwise, **-1** will be returned.|

**Error codes**

For details about the error codes, see [RDB Error Codes](../errorcodes/errorcode-data-rdb.md).

| **ID**| **Error Message**                                |
| ------------ | -------------------------------------------- |
| 14800047     | The WAL file size exceeds the default limit. |
| 14800000     | Inner error.                                 |

**Example**

```ts
import { ValuesBucket } from '@ohos.data.ValuesBucket';
import { BusinessError } from "@ohos.base";

let key1 = "NAME";
let key2 = "AGE";
let key3 = "SALARY";
let key4 = "CODES";
let value1 = "Lisa";
let value2 = 18;
let value3 = 100.5;
let value4 = new Uint8Array([1, 2, 3, 4, 5]);
const valueBucket: ValuesBucket = {
  key1: value1,
  key2: value2,
  key3: value3,
  key4: value4,
};
if(store != undefined) {
  (store as relationalStore.RdbStore).insert("EMPLOYEE", valueBucket, relationalStore.ConflictResolution.ON_CONFLICT_REPLACE).then((rowId: number) => {
    console.info(`Insert is successful, rowId = ${rowId}`);
  }).catch((err: BusinessError) => {
    console.error(`Insert is failed, code is ${err.code},message is ${err.message}`);
  })
}
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
| 14800047     | The WAL file size exceeds the default limit. |
| 14800000     | Inner error.                                 |

**Example**

```ts
import { ValuesBucket } from '@ohos.data.ValuesBucket';

let key1 = "NAME";
let key2 = "AGE";
let key3 = "SALARY";
let key4 = "CODES";
let value1 = "Lisa";
let value2 = 18;
let value3 = 100.5;
let value4 = new Uint8Array([1, 2, 3, 4, 5]);
let value5 = "Jack";
let value6 = 19;
let value7 = 101.5;
let value8 = new Uint8Array([6, 7, 8, 9, 10]);
let value9 = "Tom";
let value10 = 20;
let value11 = 102.5;
let value12 = new Uint8Array([11, 12, 13, 14, 15]);
const valueBucket1: ValuesBucket = {
  key1: value1,
  key2: value2,
  key3: value3,
  key4: value4,
};
const valueBucket2: ValuesBucket = {
  key1: value5,
  key2: value6,
  key3: value7,
  key4: value8,
};
const valueBucket3: ValuesBucket = {
  key1: value9,
  key2: value10,
  key3: value11,
  key4: value12,
};

let valueBuckets = new Array(valueBucket1, valueBucket2, valueBucket3);
if(store != undefined) {
  (store as relationalStore.RdbStore).batchInsert("EMPLOYEE", valueBuckets, (err, insertNum) => {
    if (err) {
      console.error(`batchInsert is failed, code is ${err.code},message is ${err.message}`);
      return;
    }
    console.info(`batchInsert is successful, the number of values that were inserted = ${insertNum}`);
  })
}
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
| 14800047     | The WAL file size exceeds the default limit. |
| 14800000     | Inner error.                                 |

**Example**

```ts
import { ValuesBucket } from '@ohos.data.ValuesBucket';
import { BusinessError } from "@ohos.base";

let key1 = "NAME";
let key2 = "AGE";
let key3 = "SALARY";
let key4 = "CODES";
let value1 = "Lisa";
let value2 = 18;
let value3 = 100.5;
let value4 = new Uint8Array([1, 2, 3, 4, 5]);
let value5 = "Jack";
let value6 = 19;
let value7 = 101.5;
let value8 = new Uint8Array([6, 7, 8, 9, 10]);
let value9 = "Tom";
let value10 = 20;
let value11 = 102.5;
let value12 = new Uint8Array([11, 12, 13, 14, 15]);
const valueBucket1: ValuesBucket = {
  key1: value1,
  key2: value2,
  key3: value3,
  key4: value4,
};
const valueBucket2: ValuesBucket = {
  key1: value5,
  key2: value6,
  key3: value7,
  key4: value8,
};
const valueBucket3: ValuesBucket = {
  key1: value9,
  key2: value10,
  key3: value11,
  key4: value12,
};

let valueBuckets = new Array(valueBucket1, valueBucket2, valueBucket3);
if(store != undefined) {
  (store as relationalStore.RdbStore).batchInsert("EMPLOYEE", valueBuckets).then((insertNum: number) => {
    console.info(`batchInsert is successful, the number of values that were inserted = ${insertNum}`);
  }).catch((err: BusinessError) => {
    console.error(`batchInsert is failed, code is ${err.code},message is ${err.message}`);
  })
}
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
| 14800047     | The WAL file size exceeds the default limit. |
| 14800000     | Inner error.                                 |

**Example**

```ts
import { ValuesBucket } from '@ohos.data.ValuesBucket';

let key1 = "NAME";
let key2 = "AGE";
let key3 = "SALARY";
let key4 = "CODES";
let value1 = "Rose";
let value2 = 22;
let value3 = 200.5;
let value4 = new Uint8Array([1, 2, 3, 4, 5]);
const valueBucket: ValuesBucket = {
  key1: value1,
  key2: value2,
  key3: value3,
  key4: value4,
};
let predicates = new relationalStore.RdbPredicates("EMPLOYEE");
predicates.equalTo("NAME", "Lisa");
if(store != undefined) {
  (store as relationalStore.RdbStore).update(valueBucket, predicates,(err, rows) => {
    if (err) {
      console.error(`Updated failed, code is ${err.code},message is ${err.message}`);
      return;
    }
    console.info(`Updated row count: ${rows}`);
  })
}
```

### update<sup>10+</sup>

update(values: ValuesBucket, predicates: RdbPredicates, conflict: ConflictResolution, callback: AsyncCallback&lt;number&gt;):void

Updates data in the RDB store based on the specified **RdbPredicates** object. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Parameters**

| Name    | Type                                       | Mandatory| Description                                                        |
| ---------- | ------------------------------------------- | ---- | ------------------------------------------------------------ |
| values     | [ValuesBucket](#valuesbucket)               | Yes  | Rows of data to update in the RDB store. The key-value pair is associated with the column name in the target table.|
| predicates | [RdbPredicates](#rdbpredicates)            | Yes  | Update conditions specified by the **RdbPredicates** object.                     |
| conflict   | [ConflictResolution](#conflictresolution10) | Yes  | Resolution used to resolve the conflict.                                          |
| callback   | AsyncCallback&lt;number&gt;                 | Yes  | Callback invoked to return the number of rows updated.                  |

**Error codes**

For details about the error codes, see [RDB Error Codes](../errorcodes/errorcode-data-rdb.md).

| **ID**| **Error Message**                                |
| ------------ | -------------------------------------------- |
| 14800047     | The WAL file size exceeds the default limit. |
| 14800000     | Inner error.                                 |

**Example**

```ts
import { ValuesBucket } from '@ohos.data.ValuesBucket';

let key1 = "NAME";
let key2 = "AGE";
let key3 = "SALARY";
let key4 = "CODES";
let value1 = "Rose";
let value2 = 22;
let value3 = 200.5;
let value4 = new Uint8Array([1, 2, 3, 4, 5]);
const valueBucket: ValuesBucket = {
  key1: value1,
  key2: value2,
  key3: value3,
  key4: value4,
};
let predicates = new relationalStore.RdbPredicates("EMPLOYEE");
predicates.equalTo("NAME", "Lisa");
if(store != undefined) {
  (store as relationalStore.RdbStore).update(valueBucket, predicates, relationalStore.ConflictResolution.ON_CONFLICT_REPLACE, (err, rows) => {
    if (err) {
      console.error(`Updated failed, code is ${err.code},message is ${err.message}`);
      return;
    }
    console.info(`Updated row count: ${rows}`);
  })
}
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
| 14800047     | The WAL file size exceeds the default limit. |
| 14800000     | Inner error.                                 |

**Example**

```ts
import { ValuesBucket } from '@ohos.data.ValuesBucket';
import { BusinessError } from "@ohos.base";

let key1 = "NAME";
let key2 = "AGE";
let key3 = "SALARY";
let key4 = "CODES";
let value1 = "Rose";
let value2 = 22;
let value3 = 200.5;
let value4 = new Uint8Array([1, 2, 3, 4, 5]);
const valueBucket: ValuesBucket = {
  key1: value1,
  key2: value2,
  key3: value3,
  key4: value4,
};
let predicates = new relationalStore.RdbPredicates("EMPLOYEE");
predicates.equalTo("NAME", "Lisa");
if(store != undefined) {
  (store as relationalStore.RdbStore).update(valueBucket, predicates).then(async (rows: Number) => {
    console.info(`Updated row count: ${rows}`);
  }).catch((err: BusinessError) => {
    console.error(`Updated failed, code is ${err.code},message is ${err.message}`);
  })
}
```

### update<sup>10+</sup>

update(values: ValuesBucket, predicates: RdbPredicates, conflict: ConflictResolution):Promise&lt;number&gt;

Updates data based on the specified **RdbPredicates** object. This API uses a promise to return the result.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Parameters**

| Name    | Type                                       | Mandatory| Description                                                        |
| ---------- | ------------------------------------------- | ---- | ------------------------------------------------------------ |
| values     | [ValuesBucket](#valuesbucket)               | Yes  | Rows of data to update in the RDB store. The key-value pair is associated with the column name in the target table.|
| predicates | [RdbPredicates](#rdbpredicates)            | Yes  | Update conditions specified by the **RdbPredicates** object.                     |
| conflict   | [ConflictResolution](#conflictresolution10) | Yes  | Resolution used to resolve the conflict.                                          |

**Return value**

| Type                 | Description                                     |
| --------------------- | ----------------------------------------- |
| Promise&lt;number&gt; | Promise used to return the number of rows updated.|

**Error codes**

For details about the error codes, see [RDB Error Codes](../errorcodes/errorcode-data-rdb.md).

| **ID**| **Error Message**                                |
| ------------ | -------------------------------------------- |
| 14800047     | The WAL file size exceeds the default limit. |
| 14800000     | Inner error.                                 |

**Example**

```ts
import { ValuesBucket } from '@ohos.data.ValuesBucket';
import { BusinessError } from "@ohos.base";

let key1 = "NAME";
let key2 = "AGE";
let key3 = "SALARY";
let key4 = "CODES";
let value1 = "Rose";
let value2 = 22;
let value3 = 200.5;
let value4 = new Uint8Array([1, 2, 3, 4, 5]);
const valueBucket: ValuesBucket = {
  key1: value1,
  key2: value2,
  key3: value3,
  key4: value4,
};
let predicates = new relationalStore.RdbPredicates("EMPLOYEE");
predicates.equalTo("NAME", "Lisa");
if(store != undefined) {
  (store as relationalStore.RdbStore).update(valueBucket, predicates, relationalStore.ConflictResolution.ON_CONFLICT_REPLACE).then(async (rows: Number) => {
    console.info(`Updated row count: ${rows}`);
  }).catch((err: BusinessError) => {
    console.error(`Updated failed, code is ${err.code},message is ${err.message}`);
  })
}
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
| 14800047     | The WAL file size exceeds the default limit. |
| 14800000     | Inner error.                                 |

**Example**

```ts
import dataSharePredicates from '@ohos.data.dataSharePredicates'
import { ValuesBucket } from '@ohos.data.ValuesBucket';

let key1 = "NAME";
let key2 = "AGE";
let key3 = "SALARY";
let key4 = "CODES";
let value1 = "Rose";
let value2 = 22;
let value3 = 200.5;
let value4 = new Uint8Array([1, 2, 3, 4, 5]);
const valueBucket: ValuesBucket = {
  key1: value1,
  key2: value2,
  key3: value3,
  key4: value4,
};
let predicates = new dataSharePredicates.DataSharePredicates();
predicates.equalTo("NAME", "Lisa");
if(store != undefined) {
  (store as relationalStore.RdbStore).update("EMPLOYEE", valueBucket, predicates, (err, rows) => {
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
| 14800047     | The WAL file size exceeds the default limit. |
| 14800000     | Inner error.                                 |

**Example**

```ts
import dataSharePredicates from '@ohos.data.dataSharePredicates';
import { ValuesBucket } from '@ohos.data.ValuesBucket';
import { BusinessError } from "@ohos.base";

let key1 = "NAME";
let key2 = "AGE";
let key3 = "SALARY";
let key4 = "CODES";
let value1 = "Rose";
let value2 = 22;
let value3 = 200.5;
let value4 = new Uint8Array([1, 2, 3, 4, 5]);
const valueBucket: ValuesBucket = {
  key1: value1,
  key2: value2,
  key3: value3,
  key4: value4,
};
let predicates = new dataSharePredicates.DataSharePredicates();
predicates.equalTo("NAME", "Lisa");
if(store != undefined) {
  (store as relationalStore.RdbStore).update("EMPLOYEE", valueBucket, predicates).then(async (rows: Number) => {
    console.info(`Updated row count: ${rows}`);
  }).catch((err: BusinessError) => {
    console.error(`Updated failed, code is ${err.code},message is ${err.message}`);
  })
}
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
| 14800047     | The WAL file size exceeds the default limit. |
| 14800000     | Inner error.                                 |

**Example**

```ts
let predicates = new relationalStore.RdbPredicates("EMPLOYEE");
predicates.equalTo("NAME", "Lisa");
if(store != undefined) {
  (store as relationalStore.RdbStore).delete(predicates, (err, rows) => {
    if (err) {
      console.error(`Delete failed, code is ${err.code},message is ${err.message}`);
      return;
    }
    console.info(`Delete rows: ${rows}`);
  })
}
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
| 14800047     | The WAL file size exceeds the default limit. |
| 14800000     | Inner error.                                 |

**Example**

```ts
import { BusinessError } from "@ohos.base";

let predicates = new relationalStore.RdbPredicates("EMPLOYEE");
predicates.equalTo("NAME", "Lisa");
if(store != undefined) {
  (store as relationalStore.RdbStore).delete(predicates).then((rows: Number) => {
    console.info(`Delete rows: ${rows}`);
  }).catch((err: BusinessError) => {
    console.error(`Delete failed, code is ${err.code},message is ${err.message}`);
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
| callback   | AsyncCallback&lt;number&gt;                                  | Yes  | Callback invoked to return the number of rows deleted.     |

**Error codes**

For details about the error codes, see [RDB Error Codes](../errorcodes/errorcode-data-rdb.md).

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

For details about the error codes, see [RDB Error Codes](../errorcodes/errorcode-data-rdb.md).

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

query(predicates: RdbPredicates, callback: AsyncCallback&lt;ResultSet&gt;):void

Queries data from the RDB store based on specified conditions. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Parameters**

| Name    | Type                                                        | Mandatory| Description                                                       |
| ---------- | ------------------------------------------------------------ | ---- | ----------------------------------------------------------- |
| predicates | [RdbPredicates](#rdbpredicates)                         | Yes  | Query conditions specified by the **RdbPredicates** object.                  |
| callback   | AsyncCallback&lt;[ResultSet](#resultset)&gt; | Yes  | Callback invoked to return the result. If the operation is successful, a **ResultSet** object will be returned.|

**Error codes**

For details about the error codes, see [RDB Error Codes](../errorcodes/errorcode-data-rdb.md).

| **ID**| **Error Message**                |
| ------------ | ---------------------------- |
| 14800000     | Inner error.                 |

**Example**

```ts
let predicates = new relationalStore.RdbPredicates("EMPLOYEE");
predicates.equalTo("NAME", "Rose");
if(store != undefined) {
  (store as relationalStore.RdbStore).query(predicates, (err, resultSet) => {
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

| **ID**| **Error Message**                |
| ------------ | ---------------------------- |
| 14800000     | Inner error.                 |

**Example**

```ts
let predicates = new relationalStore.RdbPredicates("EMPLOYEE");
predicates.equalTo("NAME", "Rose");
if(store != undefined) {
  (store as relationalStore.RdbStore).query(predicates, ["ID", "NAME", "AGE", "SALARY", "CODES"], (err, resultSet) => {
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

query(predicates: RdbPredicates, columns?: Array&lt;string&gt;):Promise&lt;ResultSet&gt;

Queries data from the RDB store based on specified conditions. This API uses a promise to return the result.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Parameters**

| Name    | Type                                | Mandatory| Description                                            |
| ---------- | ------------------------------------ | ---- | ------------------------------------------------ |
| predicates | [RdbPredicates](#rdbpredicates) | Yes  | Query conditions specified by the **RdbPredicates** object.       |
| columns    | Array&lt;string&gt;                  | No  | Columns to query. If this parameter is not specified, the query applies to all columns.|

**Error codes**

For details about the error codes, see [RDB Error Codes](../errorcodes/errorcode-data-rdb.md).

| **ID**| **Error Message**                |
| ------------ | ---------------------------- |
| 14800000     | Inner error.                 |

**Return value**

| Type                                                   | Description                                              |
| ------------------------------------------------------- | -------------------------------------------------- |
| Promise&lt;[ResultSet](#resultset)&gt; | Promise used to return the result. If the operation is successful, a **ResultSet** object will be returned.|

**Example**

```ts
import { BusinessError } from "@ohos.base";

let predicates = new relationalStore.RdbPredicates("EMPLOYEE");
predicates.equalTo("NAME", "Rose");
if(store != undefined) {
  (store as relationalStore.RdbStore).query(predicates, ["ID", "NAME", "AGE", "SALARY", "CODES"]).then((resultSet: relationalStore.ResultSet) => {
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

### query<sup>10+</sup>

query(table: string, predicates: dataSharePredicates.DataSharePredicates, callback: AsyncCallback&lt;ResultSet&gt;):void

Queries data from the RDB store based on specified conditions. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Model restriction**: This API can be used only in the stage model.

**System API**: This is a system API.

**Parameters**

| Name    | Type                                                        | Mandatory| Description                                                       |
| ---------- | ------------------------------------------------------------ | ---- | ----------------------------------------------------------- |
| table      | string                                                       | Yes  | Name of the target table.                                           |
| predicates | [dataSharePredicates.DataSharePredicates](js-apis-data-dataSharePredicates.md#datasharepredicates) | Yes  | Query conditions specified by the **DataSharePredicates** object.              |
| callback   | AsyncCallback&lt;[ResultSet](#resultset)&gt; | Yes  | Callback invoked to return the result. If the operation is successful, a **ResultSet** object will be returned.|

**Error codes**

For details about the error codes, see [RDB Error Codes](../errorcodes/errorcode-data-rdb.md).

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

### remoteQuery

remoteQuery(device: string, table: string, predicates: RdbPredicates, columns: Array&lt;string&gt; , callback: AsyncCallback&lt;ResultSet&gt;): void

Queries data from the RDB store of a remote device based on specified conditions. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> The value of **device** can be obtained by [deviceManager.getAvailableDeviceListSync](js-apis-distributedDeviceManager.md#getavailabledevicelistsync).

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

| **ID**| **Error Message**                |
| ------------ | ---------------------------- |
| 14800000     | Inner error.                 |

**Example**

```ts
import deviceManager from '@ohos.distributedDeviceManager';
import { BusinessError } from "@ohos.base";

let dmInstance: deviceManager.DeviceManager;
let deviceId: string | undefined = undefined;

try {
  dmInstance = deviceManager.createDeviceManager("com.example.appdatamgrverify");
  let devices = dmInstance.getAvailableDeviceListSync();
  if(deviceId != undefined) {
    deviceId = devices[0].networkId;
  }
} catch (err) {
  let code = (err as BusinessError).code;
  let message = (err as BusinessError).message;
  console.error("createDeviceManager errCode:" + code + ",errMessage:" + message);
}

let predicates = new relationalStore.RdbPredicates('EMPLOYEE');
predicates.greaterThan("id", 0);
if(store != undefined && deviceId != undefined) {
  (store as relationalStore.RdbStore).remoteQuery(deviceId, "EMPLOYEE", predicates, ["ID", "NAME", "AGE", "SALARY", "CODES"]).then((resultSet: relationalStore.ResultSet) => {
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
    console.error(`Failed to remoteQuery, code is ${err.code},message is ${err.message}`);
  })
}
```

### remoteQuery

remoteQuery(device: string, table: string, predicates: RdbPredicates, columns: Array&lt;string&gt;): Promise&lt;ResultSet&gt;

Queries data from the RDB store of a remote device based on specified conditions. This API uses a promise to return the result.

> **NOTE**
>
> The value of **device** can be obtained by [deviceManager.getAvailableDeviceListSync](js-apis-distributedDeviceManager.md#getavailabledevicelistsync).

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

| **ID**| **Error Message**                |
| ------------ | ---------------------------- |
| 14800000     | Inner error.                 |

**Example**

```ts
import deviceManager from '@ohos.distributedDeviceManager';
import { BusinessError } from "@ohos.base";

let dmInstance: deviceManager.DeviceManager;
let deviceId: string | undefined = undefined;

try {
  dmInstance = deviceManager.createDeviceManager("com.example.appdatamgrverify");
  let devices: Array<deviceManager.DeviceBasicInfo> = dmInstance.getAvailableDeviceListSync();
  if(devices != undefined) {
    deviceId = devices[0].networkId;
  }
} catch (err) {
  let code = (err as BusinessError).code;
  let message = (err as BusinessError).message;
  console.error("createDeviceManager errCode:" + code + ",errMessage:" + message);
}

let predicates = new relationalStore.RdbPredicates('EMPLOYEE');
predicates.greaterThan("id", 0);
if(store != undefined && deviceId != undefined) {
  (store as relationalStore.RdbStore).remoteQuery(deviceId, "EMPLOYEE", predicates, ["ID", "NAME", "AGE", "SALARY", "CODES"]).then((resultSet: relationalStore.ResultSet) => {
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
    console.error(`Failed to remoteQuery, code is ${err.code},message is ${err.message}`);
  })
}
```

### querySql<sup>10+</sup>

querySql(sql: string, callback: AsyncCallback&lt;ResultSet&gt;):void

Queries data using the specified SQL statement. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Parameters**

| Name  | Type                                        | Mandatory| Description                                                        |
| -------- | -------------------------------------------- | ---- | ------------------------------------------------------------ |
| sql      | string                                       | Yes  | SQL statement to run.                                       |
| callback | AsyncCallback&lt;[ResultSet](#resultset)&gt; | Yes  | Callback invoked to return the result. If the operation is successful, a **ResultSet** object will be returned.   |

**Error codes**

For details about the error codes, see [RDB Error Codes](../errorcodes/errorcode-data-rdb.md).

| **ID**| **Error Message**                |
| ------------ | ---------------------------- |
| 14800000     | Inner error.                 |

**Example**

```ts
if(store != undefined) {
  (store as relationalStore.RdbStore).querySql("SELECT * FROM EMPLOYEE CROSS JOIN BOOK WHERE BOOK.NAME = 'sanguo'", (err, resultSet) => {
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

| **ID**| **Error Message**                |
| ------------ | ---------------------------- |
| 14800000     | Inner error.                 |

**Example**

```ts
if(store != undefined) {
  (store as relationalStore.RdbStore).querySql("SELECT * FROM EMPLOYEE CROSS JOIN BOOK WHERE BOOK.NAME = ?", ['sanguo'], (err, resultSet) => {
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

| **ID**| **Error Message**                |
| ------------ | ---------------------------- |
| 14800000     | Inner error.                 |

**Example**

```ts
import { BusinessError } from "@ohos.base";

if(store != undefined) {
  (store as relationalStore.RdbStore).querySql("SELECT * FROM EMPLOYEE CROSS JOIN BOOK WHERE BOOK.NAME = 'sanguo'").then((resultSet: relationalStore.ResultSet) => {
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

### executeSql<sup>10+</sup>

executeSql(sql: string, callback: AsyncCallback&lt;void&gt;):void

Executes an SQL statement that contains specified arguments but returns no value. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Parameters**

| Name  | Type                                | Mandatory| Description                                                        |
| -------- | ------------------------------------ | ---- | ------------------------------------------------------------ |
| sql      | string                               | Yes  | SQL statement to run.                                       |
| callback | AsyncCallback&lt;void&gt;            | Yes  | Callback invoked to return the result.                                      |

**Error codes**

For details about the error codes, see [RDB Error Codes](../errorcodes/errorcode-data-rdb.md).

| **ID**| **Error Message**                                |
| ------------ | -------------------------------------------- |
| 14800047     | The WAL file size exceeds the default limit. |
| 14800000     | Inner error.                                 |

**Example**

```ts
const SQL_DELETE_TABLE = "DELETE FROM test WHERE name = 'zhangsan'"
if(store != undefined) {
  (store as relationalStore.RdbStore).executeSql(SQL_DELETE_TABLE, (err) => {
    if (err) {
      console.error(`ExecuteSql failed, code is ${err.code},message is ${err.message}`);
      return;
    }
    console.info('Delete table done.');
  })
}
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
| 14800047     | The WAL file size exceeds the default limit. |
| 14800000     | Inner error.                                 |

**Example**

```ts
const SQL_DELETE_TABLE = "DELETE FROM test WHERE name = ?"
if(store != undefined) {
  (store as relationalStore.RdbStore).executeSql(SQL_DELETE_TABLE, ['zhangsan'], (err) => {
    if (err) {
      console.error(`ExecuteSql failed, code is ${err.code},message is ${err.message}`);
      return;
    }
    console.info('Delete table done.');
  })
}
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
| 14800047     | The WAL file size exceeds the default limit. |
| 14800000     | Inner error.                                 |

**Example**

```ts
import { BusinessError } from "@ohos.base";

const SQL_DELETE_TABLE = "DELETE FROM test WHERE name = 'zhangsan'"
if(store != undefined) {
  (store as relationalStore.RdbStore).executeSql(SQL_DELETE_TABLE).then(() => {
    console.info('Delete table done.');
  }).catch((err: BusinessError) => {
    console.error(`ExecuteSql failed, code is ${err.code},message is ${err.message}`);
  })
}
```

### getModifyTime<sup>10+</sup>

getModifyTime(table: string, columnName: string, primaryKeys: PRIKeyType[], callback: AsyncCallback&lt;ModifyTime&gt;): void

Obtains the last modification time of the data in a table. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Parameters**

| Name     | Type                                            | Mandatory| Description                                                        |
| ----------- | ------------------------------------------------ | ---- | ------------------------------------------------------------ |
| table       | string                                           | Yes  | Name of the database table to query.                                |
| columnName  | string                                           | Yes  | Column name of the database table to query.                                |
| primaryKeys | [PRIKeyType](#prikeytype10)[]                    | Yes  | Primary keys of the rows to query.<br>If the database table has no primary key, **rowid** must be passed in through **columnName**. In this case, **primaryKeys** specifies the row numbers of the database table to query.<br>If the database table has no primary key and no **rowid** is passed in through **columnName**, an error code will be returned.|
| callback    | AsyncCallback&lt;[ModifyTime](#modifytime10)&gt; | Yes  | Callback invoked to return the result. If the operation is successful, the **ModifyTime** object is returned.|

**Error codes**

For details about the error codes, see [RDB Error Codes](../errorcodes/errorcode-data-rdb.md).

| **ID**| **Error Message**|
| ------------ | ------------ |
| 14800000     | Inner error. |

**Example**

```ts
let PRIKey = [1, 4, 2, 3];
if(store != undefined) {
  (store as relationalStore.RdbStore).getModifyTime("cloud_tasks", "uuid", PRIKey, (err, modifyTime: relationalStore.ModifyTime) => {
    if (err) {
      console.error(`getModifyTime failed, code is ${err.code},message is ${err.message}`);
      return;
    }
    let size = modifyTime.size;
  });
}
```

### getModifyTime<sup>10+</sup>

getModifyTime(table: string, columnName: string, primaryKeys: PRIKeyType[]): Promise&lt;ModifyTime&gt;

Obtains the last modification time of the data in a table. This API uses a promise to return the result.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Parameters**

| Name     | Type                         | Mandatory| Description                                                        |
| ----------- | ----------------------------- | ---- | ------------------------------------------------------------ |
| table       | string                        | Yes  | Name of the database table to query.                                |
| columnName  | string                        | Yes  | Column name of the database table to query.                                |
| primaryKeys | [PRIKeyType](#prikeytype10)[] | Yes  | Primary keys of the rows to query.<br>If the database table has no primary key, **rowid** must be passed in through **columnName**. In this case, **primaryKeys** specifies the row numbers of the database table to query.<br>If the database table has no primary key and no **rowid** is passed in through **columnName**, an error code will be returned.|

**Return value**

| Type                                      | Description                                                     |
| ------------------------------------------ | --------------------------------------------------------- |
| Promise&lt;[ModifyTime](#modifytime10)&gt; | Promise used to return the **ModifyTime** object.|

**Error codes**

For details about the error codes, see [RDB Error Codes](../errorcodes/errorcode-data-rdb.md).

| **ID**| **Error Message**|
| ------------ | ------------ |
| 14800000     | Inner error. |

**Example**

```ts
import { BusinessError } from "@ohos.base";

let PRIKey = [1, 2, 3];
if(store != undefined) {
  (store as relationalStore.RdbStore).getModifyTime("cloud_tasks", "uuid", PRIKey)
    .then((modifyTime: relationalStore.ModifyTime) => {
      let size = modifyTime.size;
    })
    .catch((err: BusinessError) => {
      console.error(`getModifyTime failed, code is ${err.code},message is ${err.message}`);
    });
}
```

### beginTransaction

beginTransaction():void

Starts the transaction before executing an SQL statement.
This API cannot be used in multi-process or multi-thread scenarios.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Error codes**

For details about the error codes, see [RDB Error Codes](../errorcodes/errorcode-data-rdb.md).

| **ID**| **Error Message**                                |
| ------------ | -------------------------------------------- |
| 14800047     | The WAL file size exceeds the default limit. |
| 14800000     | Inner error.                                 |

**Example**

```ts
import featureAbility from '@ohos.ability.featureAbility'
import { ValuesBucket } from '@ohos.data.ValuesBucket';

let context = getContext(this);

let key1 = "name";
let key2 = "age";
let key3 = "SALARY";
let key4 = "blobType";
let value1 = "Lisa";
let value2 = 18;
let value3 = 100.5;
let value4 = new Uint8Array([1, 2, 3]);
const STORE_CONFIG: relationalStore.StoreConfig = {
  name: "RdbTest.db",
  securityLevel: relationalStore.SecurityLevel.S1
};
relationalStore.getRdbStore(context, STORE_CONFIG, async (err, store) => {
  if (err) {
    console.error(`GetRdbStore failed, code is ${err.code},message is ${err.message}`);
    return;
  }
  store.beginTransaction();
  const valueBucket: ValuesBucket = {
    key1: value1,
    key2: value2,
    key3: value3,
    key4: value4,
  };
  await store.insert("test", valueBucket);
  store.commit();
})
```

### commit

commit():void

Commits the executed SQL statements.
This API cannot be used in multi-process or multi-thread scenarios.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Example**

```ts
import { ValuesBucket } from '@ohos.data.ValuesBucket';

let context = getContext(this);

let key1 = "name";
let key2 = "age";
let key3 = "SALARY";
let key4 = "blobType";
let value1 = "Lisa";
let value2 = 18;
let value3 = 100.5;
let value4 = new Uint8Array([1, 2, 3]);
const STORE_CONFIG: relationalStore.StoreConfig = {
  name: "RdbTest.db",
  securityLevel: relationalStore.SecurityLevel.S1
};
relationalStore.getRdbStore(context, STORE_CONFIG, async (err, store) => {
  if (err) {
    console.error(`GetRdbStore failed, code is ${err.code},message is ${err.message}`);
    return;
  }
  store.beginTransaction();
  const valueBucket: ValuesBucket = {
    key1: value1,
    key2: value2,
    key3: value3,
    key4: value4,
  };
  await store.insert("test", valueBucket);
  store.commit();
})
```

### rollBack

rollBack():void

Rolls back the SQL statements that have been executed.
This API cannot be used in multi-process or multi-thread scenarios.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Example**

```ts
import { ValuesBucket } from '@ohos.data.ValuesBucket';

let context = getContext(this);

let key1 = "name";
let key2 = "age";
let key3 = "SALARY";
let key4 = "blobType";
let value1 = "Lisa";
let value2 = 18;
let value3 = 100.5;
let value4 = new Uint8Array([1, 2, 3]);
const STORE_CONFIG: relationalStore.StoreConfig = {
  name: "RdbTest.db",
  securityLevel: relationalStore.SecurityLevel.S1
};
relationalStore.getRdbStore(context, STORE_CONFIG, async (err, store) => {
  if (err) {
    console.error(`GetRdbStore failed, code is ${err.code},message is ${err.message}`);
    return;
  }
  try {
    store.beginTransaction()
    const valueBucket: ValuesBucket = {
      key1: value1,
      key2: value2,
      key3: value3,
      key4: value4,
    };
    await store.insert("test", valueBucket);
    store.commit();
  } catch (err) {
    let code = (err as BusinessError).code;
    let message = (err as BusinessError).message
    console.error(`Transaction failed, code is ${code},message is ${message}`);
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

| **ID**| **Error Message**                |
| ------------ | ---------------------------- |
| 14800000     | Inner error.                 |

**Example**

```ts
if(store != undefined) {
  (store as relationalStore.RdbStore).backup("dbBackup.db", (err) => {
    if (err) {
      console.error(`Backup failed, code is ${err.code},message is ${err.message}`);
      return;
    }
    console.info('Backup success.');
  })
}
```

### backup

backup(destName:string): Promise&lt;void&gt;

Backs up an RDB store. This API uses a promise to return the result.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Parameters**

| Name  | Type  | Mandatory| Description                    |
| -------- | ------ | ---- | ------------------------ |
| destName | string | Yes  | Name of the RDB store backup file.|

**Return value**

| Type               | Description                     |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [RDB Error Codes](../errorcodes/errorcode-data-rdb.md).

| **ID**| **Error Message**                |
| ------------ | ---------------------------- |
| 14800000     | Inner error.                 |

**Example**

```ts
import { BusinessError } from "@ohos.base";

if(store != undefined) {
  let promiseBackup = (store as relationalStore.RdbStore).backup("dbBackup.db");
  promiseBackup.then(() => {
    console.info('Backup success.');
  }).catch((err: BusinessError) => {
    console.error(`Backup failed, code is ${err.code},message is ${err.message}`);
  })
}
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

| **ID**| **Error Message**                |
| ------------ | ---------------------------- |
| 14800000     | Inner error.                 |

**Example**

```ts
if(store != undefined) {
  (store as relationalStore.RdbStore).restore("dbBackup.db", (err) => {
    if (err) {
      console.error(`Restore failed, code is ${err.code},message is ${err.message}`);
      return;
    }
    console.info('Restore success.');
  })
}
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

| **ID**| **Error Message**                |
| ------------ | ---------------------------- |
| 14800000     | Inner error.                 |

**Example**

```ts
import { BusinessError } from "@ohos.base";

if(store != undefined) {
  let promiseRestore = (store as relationalStore.RdbStore).restore("dbBackup.db");
  promiseRestore.then(() => {
    console.info('Restore success.');
  }).catch((err: BusinessError) => {
    console.error(`Restore failed, code is ${err.code},message is ${err.message}`);
  })
}
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

| **ID**| **Error Message**                |
| ------------ | ---------------------------- |
| 14800000     | Inner error.                 |

**Example**

```ts
if(store != undefined) {
  (store as relationalStore.RdbStore).setDistributedTables(["EMPLOYEE"], (err) => {
    if (err) {
      console.error(`SetDistributedTables failed, code is ${err.code},message is ${err.message}`);
      return;
    }
    console.info('SetDistributedTables successfully.');
  })
}
```

### setDistributedTables

 setDistributedTables(tables: Array&lt;string&gt;): Promise&lt;void&gt;

Sets distributed tables. This API uses a promise to return the result.

**Required permissions**: ohos.permission.DISTRIBUTED_DATASYNC

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Parameters**

| Name| Type                    | Mandatory| Description                    |
| ------ | ------------------------ | ---- | ------------------------ |
| tables | ArrayArray&lt;string&gt; | Yes  | Names of the distributed tables to set.|

**Return value**

| Type               | Description                     |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [RDB Error Codes](../errorcodes/errorcode-data-rdb.md).

| **ID**| **Error Message**|
| ------------ | ------------ |
| 14800000     | Inner error. |

**Example**

```ts
import { BusinessError } from "@ohos.base";

if(store != undefined) {
  (store as relationalStore.RdbStore).setDistributedTables(["EMPLOYEE"]).then(() => {
    console.info('SetDistributedTables successfully.');
  }).catch((err: BusinessError) => {
    console.error(`SetDistributedTables failed, code is ${err.code},message is ${err.message}`);
  })
}
```

### setDistributedTables<sup>10+</sup>

setDistributedTables(tables: Array&lt;string&gt;, type: DistributedType, callback: AsyncCallback&lt;void&gt;): void

Sets distributed tables. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.DISTRIBUTED_DATASYNC

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Parameters**

| Name  | Type                                 | Mandatory| Description                        |
| -------- | ------------------------------------- | ---- | ---------------------------- |
| tables   | Array&lt;string&gt;                   | Yes  | Names of the distributed tables to set.|
| type     | [DistributedType](#distributedtype10) | Yes  | Distributed type of the tables.            |
| callback | AsyncCallback&lt;void&gt;             | Yes  | Callback invoked to return the result.      |

**Error codes**

For details about the error codes, see [RDB Error Codes](../errorcodes/errorcode-data-rdb.md).

| **ID**| **Error Message**|
| ------------ | ------------ |
| 14800000     | Inner error. |
| 14800051     |The type of the distributed table does not match.|

**Example**

```ts
if(store != undefined) {
  (store as relationalStore.RdbStore).setDistributedTables(["EMPLOYEE"], relationalStore.DistributedType.DISTRIBUTED_CLOUD, (err) => {
    if (err) {
      console.error(`SetDistributedTables failed, code is ${err.code},message is ${err.message}`);
      return;
    }
    console.info('SetDistributedTables successfully.');
  })
}
```

 

### setDistributedTables<sup>10+</sup>

setDistributedTables(tables: Array&lt;string&gt;, type: DistributedType, config: DistributedConfig, callback: AsyncCallback&lt;void&gt;): void

Sets distributed tables. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.DISTRIBUTED_DATASYNC

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Parameters**

| Name     | Type                                 | Mandatory | Description             |
| -------- | ----------------------------------- | --- | --------------- |
| tables   | Array&lt;string&gt;                 | Yes  | Names of the distributed tables to set.    |
| type     | [DistributedType](#distributedtype10) | Yes  | Distributed type of the tables.|
| config | [DistributedConfig](#distributedconfig10) | Yes| Configuration of the distributed mode.|
| callback | AsyncCallback&lt;void&gt;           | Yes  | Callback invoked to return the result.|

**Error codes**

For details about the error codes, see [RDB Error Codes](../errorcodes/errorcode-data-rdb.md).

| **ID**| **Error Message**                                     |
| ------------ | ------------------------------------------------- |
| 14800000     | Inner error.                                      |
| 14800051     | The type of the distributed table does not match. |

**Example**

```ts
if(store != undefined) {
  (store as relationalStore.RdbStore).setDistributedTables(["EMPLOYEE"], relationalStore.DistributedType.DISTRIBUTED_CLOUD, {
    autoSync: true
  }, (err) => {
    if (err) {
      console.error(`SetDistributedTables failed, code is ${err.code},message is ${err.message}`);
      return;
    }
    console.info('SetDistributedTables successfully.');
  })
}
```

### setDistributedTables<sup>10+</sup>

 setDistributedTables(tables: Array&lt;string>, type?: DistributedType, config?: DistributedConfig): Promise&lt;void>

Sets distributed tables. This API uses a promise to return the result.

**Required permissions**: ohos.permission.DISTRIBUTED_DATASYNC

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Parameters**

| Name| Type                                     | Mandatory| Description                                                        |
| ------ | ----------------------------------------- | ---- | ------------------------------------------------------------ |
| tables | Array&lt;string&gt;                       | Yes  | Names of the distributed tables to set.                                |
| type   | [DistributedType](#distributedtype10)     | No  | Distributed type of the tables. The default value is **relationalStore.DistributedType.DISTRIBUTED_DEVICE**.|
| config | [DistributedConfig](#distributedconfig10) | No  | Configuration of the distributed mode. If this parameter is not specified, the value of **autoSync** is **false** by default, which means only manual synchronization is supported.|

**Return value**

| Type               | Description                     |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [RDB Error Codes](../errorcodes/errorcode-data-rdb.md).

| **ID**| **Error Message**                                     |
| ------------ | ------------------------------------------------- |
| 14800000     | Inner error.                                      |
| 14800051     | The type of the distributed table does not match. |

**Example**

```ts
import { BusinessError } from "@ohos.base";

if(store != undefined) {
  (store as relationalStore.RdbStore).setDistributedTables(["EMPLOYEE"], relationalStore.DistributedType.DISTRIBUTED_CLOUD, {
    autoSync: true
  }).then(() => {
    console.info('SetDistributedTables successfully.');
  }).catch((err: BusinessError) => {
    console.error(`SetDistributedTables failed, code is ${err.code},message is ${err.message}`);
  })
}
```

### obtainDistributedTableName

obtainDistributedTableName(device: string, table: string, callback: AsyncCallback&lt;string&gt;): void

Obtains the distributed table name of a remote device based on the local table name of the device. The distributed table name is required when the RDB store of a remote device is queried.

> **NOTE**
>
> The value of **device** can be obtained by [deviceManager.getAvailableDeviceListSync](js-apis-distributedDeviceManager.md#getavailabledevicelistsync).

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

| **ID**| **Error Message**                |
| ------------ | ---------------------------- |
| 14800000     | Inner error.                 |

**Example**

```ts
import deviceManager from '@ohos.distributedDeviceManager';

let dmInstance: deviceManager.DeviceManager;
let deviceId: string | undefined = undefined;

try {
  dmInstance = deviceManager.createDeviceManager("com.example.appdatamgrverify");
  let devices = dmInstance.getAvailableDeviceListSync();
  deviceId = devices[0].networkId;
} catch (err) {
  let code = (err as BusinessError).code;
  let message = (err as BusinessError).message
  console.error("createDeviceManager errCode:" + code + ",errMessage:" + message);
}

if(store != undefined && deviceId != undefined) {
  (store as relationalStore.RdbStore).obtainDistributedTableName(deviceId, "EMPLOYEE", (err, tableName) => {
    if (err) {
      console.error(`ObtainDistributedTableName failed, code is ${err.code},message is ${err.message}`);
      return;
    }
    console.info(`ObtainDistributedTableName successfully, tableName= ${tableName}`);
  })
}
```

### obtainDistributedTableName

 obtainDistributedTableName(device: string, table: string): Promise&lt;string&gt;

Obtains the distributed table name of a remote device based on the local table name of the device. The distributed table name is required when the RDB store of a remote device is queried.

> **NOTE**
>
> The value of **device** can be obtained by [deviceManager.getAvailableDeviceListSync](js-apis-distributedDeviceManager.md#getavailabledevicelistsync).

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

| **ID**| **Error Message**                |
| ------------ | ---------------------------- |
| 14800000     | Inner error.                 |

**Example**

```ts
import deviceManager from '@ohos.distributedDeviceManager';
import { BusinessError } from "@ohos.base";

let dmInstance: deviceManager.DeviceManager;
let deviceId: string | undefined = undefined;

try {
  dmInstance = deviceManager.createDeviceManager("com.example.appdatamgrverify");
  let devices = dmInstance.getAvailableDeviceListSync();
  deviceId = devices[0].networkId;
} catch (err) {
  let code = (err as BusinessError).code;
  let message = (err as BusinessError).message
  console.error("createDeviceManager errCode:" + code + ",errMessage:" + message);
}

if(store != undefined && deviceId != undefined) {
  (store as relationalStore.RdbStore).obtainDistributedTableName(deviceId, "EMPLOYEE").then((tableName: string) => {
    console.info(`ObtainDistributedTableName successfully, tableName= ${tableName}`);
  }).catch((err: BusinessError) => {
    console.error(`ObtainDistributedTableName failed, code is ${err.code},message is ${err.message}`);
  })
}
```

### sync

sync(mode: SyncMode, predicates: RdbPredicates, callback: AsyncCallback&lt;Array&lt;[string, number]&gt;&gt;): void

Synchronizes data between devices. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.DISTRIBUTED_DATASYNC

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Parameters**

| Name    | Type                                              | Mandatory| Description                                                        |
| ---------- | -------------------------------------------------- | ---- | ------------------------------------------------------------ |
| mode       | [SyncMode](#syncmode)                             | Yes  | Data synchronization mode. The value can be **relationalStore.SyncMode.SYNC_MODE_PUSH** or **relationalStore.SyncMode.SYNC_MODE_PULL**.                              |
| predicates | [RdbPredicates](#rdbpredicates)               | Yes  | **RdbPredicates** object that specifies the data and devices to synchronize.                                        |
| callback   | AsyncCallback&lt;Array&lt;[string, number]&gt;&gt; | Yes  | Callback invoked to send the synchronization result to the caller. <br>**string** indicates the device ID. <br>**number** indicates the synchronization status of that device. The value **0** indicates a successful synchronization. Other values indicate a synchronization failure. |

**Error codes**

For details about the error codes, see [RDB Error Codes](../errorcodes/errorcode-data-rdb.md).

| **ID**| **Error Message**                |
| ------------ | ---------------------------- |
| 14800000     | Inner error.                 |

**Example**

```ts
import deviceManager from '@ohos.distributedDeviceManager';

let dmInstance: deviceManager.DeviceManager;
let deviceIds: Array<string> = [];

try {
  dmInstance = deviceManager.createDeviceManager("com.example.appdatamgrverify");
  let devices: Array<deviceManager.DeviceBasicInfo> = dmInstance.getAvailableDeviceListSync();
  for (let i = 0; i < devices.length; i++) {
    deviceIds[i] = devices[i].networkId!;
  }
} catch (err) {
  let code = (err as BusinessError).code;
  let message = (err as BusinessError).message
  console.error("createDeviceManager errCode:" + code + ",errMessage:" + message);
}

let predicates = new relationalStore.RdbPredicates('EMPLOYEE');
predicates.inDevices(deviceIds);
if(store != undefined) {
  (store as relationalStore.RdbStore).sync(relationalStore.SyncMode.SYNC_MODE_PUSH, predicates, (err, result) => {
    if (err) {
      console.error(`Sync failed, code is ${err.code},message is ${err.message}`);
      return;
    }
    console.info('Sync done.');
    for (let i = 0; i < result.length; i++) {
      console.info(`device= ${result[i][0]}, status= ${result[i][1]}`);
    }
  })
}
```

### sync

 sync(mode: SyncMode, predicates: RdbPredicates): Promise&lt;Array&lt;[string, number]&gt;&gt;

Synchronizes data between devices. This API uses a promise to return the result.

**Required permissions**: ohos.permission.DISTRIBUTED_DATASYNC

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Parameters**

| Name    | Type                                | Mandatory| Description                          |
| ---------- | ------------------------------------ | ---- | ------------------------------ |
| mode       | [SyncMode](#syncmode)               | Yes  | Data synchronization mode. The value can be **relationalStore.SyncMode.SYNC_MODE_PUSH** or **relationalStore.SyncMode.SYNC_MODE_PULL**.|
| predicates | [RdbPredicates](#rdbpredicates) | Yes  | **RdbPredicates** object that specifies the data and devices to synchronize.          |

**Return value**

| Type                                        | Description                                                        |
| -------------------------------------------- | ------------------------------------------------------------ |
| Promise&lt;Array&lt;[string, number]&gt;&gt; | Promise used to send the synchronization result. <br>**string** indicates the device ID. <br>**number** indicates the synchronization status of that device. The value **0** indicates a successful synchronization. Other values indicate a synchronization failure. |

**Error codes**

For details about the error codes, see [RDB Error Codes](../errorcodes/errorcode-data-rdb.md).

| **ID**| **Error Message**                |
| ------------ | ---------------------------- |
| 14800000     | Inner error.                 |

**Example**

```ts
import deviceManager from '@ohos.distributedDeviceManager';
import { BusinessError } from "@ohos.base";

let dmInstance: deviceManager.DeviceManager;
let deviceIds: Array<string> = [];

try {
  dmInstance = deviceManager.createDeviceManager("com.example.appdatamgrverify");
  let devices: Array<deviceManager.DeviceBasicInfo> = dmInstance.getAvailableDeviceListSync();
  for (let i = 0; i < devices.length; i++) {
    deviceIds[i] = devices[i].networkId!;
  }
} catch (err) {
  let code = (err as BusinessError).code;
  let message = (err as BusinessError).message
  console.error("createDeviceManager errCode:" + code + ",errMessage:" + message);
}

let predicates = new relationalStore.RdbPredicates('EMPLOYEE');
predicates.inDevices(deviceIds);
if(store != undefined) {
  (store as relationalStore.RdbStore).sync(relationalStore.SyncMode.SYNC_MODE_PUSH, predicates).then((result: Object[][]) => {
    console.info('Sync done.');
    for (let i = 0; i < result.length; i++) {
      console.info(`device= ${result[i][0]}, status= ${result[i][1]}`);
    }
  }).catch((err: BusinessError) => {
    console.error(`Sync failed, code is ${err.code},message is ${err.message}`);
  })
}
```

### cloudSync<sup>10+</sup>

cloudSync(mode: SyncMode, progress: Callback&lt;ProgressDetails&gt;, callback: AsyncCallback&lt;void&gt;): void

Manually starts device-cloud synchronization for all distributed tables. This API uses an asynchronous callback to return the result. Before using this API, ensure that the cloud service must be available.

**Required permissions**: ohos.permission.DISTRIBUTED_DATASYNC

**System capability**: SystemCapability.DistributedDataManager.CloudSync.Client

**Parameters**

| Name  | Type                                                 | Mandatory| Description                                              |
| -------- | ----------------------------------------------------- | ---- | -------------------------------------------------- |
| mode     | [SyncMode](#syncmode)                                 | Yes  | Synchronization mode of the database.                            |
| progress | Callback&lt;[ProgressDetails](#progressdetails10)&gt; | Yes  | Callback used to process database synchronization details.            |
| callback | AsyncCallback&lt;void&gt;                             | Yes  | Callback invoked to send the synchronization result to the caller.|

**Example**

```ts
if(store != undefined) {
  (store as relationalStore.RdbStore).cloudSync(relationalStore.SyncMode.SYNC_MODE_CLOUD_FIRST, (progressDetails) => {
    console.info(`Progess: ${progressDetails}`);
  }, (err) => {
    if (err) {
      console.error(`Cloud sync failed, code is ${err.code},message is ${err.message}`);
      return;
    }
    console.info('Cloud sync succeeded');
  });
}
```

### cloudSync<sup>10+</sup>

cloudSync(mode: SyncMode, progress: Callback&lt;ProgressDetails&gt;): Promise&lt;void&gt;

Manually starts device-cloud synchronization for all distributed tables. This API uses a promise to return the result. Before using this API, ensure that the cloud service must be available.

**Required permissions**: ohos.permission.DISTRIBUTED_DATASYNC

**System capability**: SystemCapability.DistributedDataManager.CloudSync.Client

**Parameters**

| Name  | Type                                                 | Mandatory| Description                                  |
| -------- | ----------------------------------------------------- | ---- | -------------------------------------- |
| mode     | [SyncMode](#syncmode)                                 | Yes  | Synchronization mode of the database.                |
| progress | Callback&lt;[ProgressDetails](#progressdetails10)&gt; | Yes  | Callback used to process database synchronization details.|

**Return value**

| Type               | Description                                   |
| ------------------- | --------------------------------------- |
| Promise&lt;void&gt; | Promise used to send the synchronization result.|

**Example**

```ts
import { BusinessError } from "@ohos.base";

if(store != undefined) {
  (store as relationalStore.RdbStore).cloudSync(relationalStore.SyncMode.SYNC_MODE_CLOUD_FIRST, (progressDetail: relationalStore.ProgressDetails) => {
    console.info(`progress: ${progressDetail}`);
  }).then(() => {
    console.info('Cloud sync succeeded');
  }).catch((err: BusinessError) => {
    console.error(`cloudSync failed, code is ${err.code},message is ${err.message}`);
  });
}
```

### cloudSync<sup>10+</sup>

cloudSync(mode: SyncMode, tables: string[], progress: Callback&lt;ProgressDetails&gt;, callback: AsyncCallback&lt;void&gt;): void

Manually starts device-cloud synchronization of the specified table. This API uses an asynchronous callback to return the result. Before using this API, ensure that the cloud service must be available.

**Required permissions**: ohos.permission.DISTRIBUTED_DATASYNC

**System capability**: SystemCapability.DistributedDataManager.CloudSync.Client

**Parameters**

| Name  | Type                                                 | Mandatory| Description                                              |
| -------- | ----------------------------------------------------- | ---- | -------------------------------------------------- |
| mode     | [SyncMode](#syncmode)                                 | Yes  | Synchronization mode of the database.                            |
| tables   | string[]                                              | Yes  | Name of the table to synchronize.                                  |
| progress | Callback&lt;[ProgressDetails](#progressdetails10)&gt; | Yes  | Callback used to process database synchronization details.            |
| callback | AsyncCallback&lt;void&gt;                             | Yes  | Callback invoked to send the synchronization result to the caller.|

**Example**

```ts
const tables = ["table1", "table2"];

if(store != undefined) {
  (store as relationalStore.RdbStore).cloudSync(relationalStore.SyncMode.SYNC_MODE_CLOUD_FIRST, tables, (progressDetail: relationalStore.ProgressDetails) => {
    console.info(`Progess: ${progressDetail}`);
  }, (err) => {
    if (err) {
      console.error(`Cloud sync failed, code is ${err.code},message is ${err.message}`);
      return;
    }
    console.info('Cloud sync succeeded');
  });
};
```

### cloudSync<sup>10+</sup>

cloudSync(mode: SyncMode, tables: string[], progress: Callback&lt;ProgressDetails&gt;): Promise&lt;void&gt;

Manually starts device-cloud synchronization of the specified table. This API uses a promise to return the result. Before using this API, ensure that the cloud service must be available.

**Required permissions**: ohos.permission.DISTRIBUTED_DATASYNC

**System capability**: SystemCapability.DistributedDataManager.CloudSync.Client

**Parameters**

| Name  | Type                                                 | Mandatory| Description                                  |
| -------- | ----------------------------------------------------- | ---- | -------------------------------------- |
| mode     | [SyncMode](#syncmode)                                 | Yes  | Synchronization mode of the database.                |
| tables   | string[]                                              | Yes  | Name of the table to synchronize.                      |
| progress | Callback&lt;[ProgressDetails](#progressdetails10)&gt; | Yes  | Callback used to process database synchronization details.|

**Return value**

| Type               | Description                                   |
| ------------------- | --------------------------------------- |
| Promise&lt;void&gt; | Promise used to send the synchronization result.|

**Example**

```ts
import { BusinessError } from "@ohos.base";

const tables = ["table1", "table2"];

if(store != undefined) {
  (store as relationalStore.RdbStore).cloudSync(relationalStore.SyncMode.SYNC_MODE_CLOUD_FIRST, (progressDetail: relationalStore.ProgressDetails) => {
    console.info(`progress: ${progressDetail}`);
  }).then(() => {
    console.info('Cloud sync succeeded');
  }).catch((err: BusinessError) => {
    console.error(`cloudSync failed, code is ${err.code},message is ${err.message}`);
  });
};
```

### cloudSync<sup>11+</sup>

cloudSync(mode: SyncMode, predicates: RdbPredicates, progress: Callback&lt;ProgressDetails&gt;, callback: AsyncCallback&lt;void&gt;): void

Manually performs device-cloud synchronization based on specified conditions. This API uses an asynchronous callback to return the result. The cloud synchronization function must be implemented. Otherwise, this API cannot be used.

**Required permissions**: ohos.permission.DISTRIBUTED_DATASYNC

**System capability**: SystemCapability.DistributedDataManager.CloudSync.Client

**System API**: This is a system API.

**Parameters**

| Name        | Type                            | Mandatory| Description                           |
|-------------|--------------------------------| ---- |-------------------------------|
| mode        | [SyncMode](#syncmode)          | Yes  | Synchronization mode of the database.                  |
| predicates  | [RdbPredicates](#rdbpredicates)                  | Yes  | Conditions for data synchronization.                 |
| progress    | Callback&lt;[ProgressDetails](#progressdetails10)&gt; | Yes  | Callback used to process database synchronization details.          |
| callback    | AsyncCallback&lt;void&gt;      | Yes  | Callback invoked to send the synchronization result to the caller.|

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

Manually performs device-cloud synchronization based on specified conditions. This API uses a promise to return the result. The cloud synchronization function must be implemented. Otherwise, this API cannot be used.

**Required permissions**: ohos.permission.DISTRIBUTED_DATASYNC

**System capability**: SystemCapability.DistributedDataManager.CloudSync.Client

**System API**: This is a system API.

**Parameters**

| Name       | Type                             | Mandatory| Description                 |
|------------|---------------------------------| ---- |---------------------|
| mode       | [SyncMode](#syncmode)           | Yes  | Synchronization mode of the database.        |
| predicates | [RdbPredicates](#rdbpredicates)                   | Yes  | Conditions for data synchronization.               |
| progress   | Callback&lt;[ProgressDetails](#progressdetails10)&gt; | Yes  | Callback used to process database synchronization details.|

**Return value**

| Type               | Description                                   |
| ------------------- | --------------------------------------- |
| Promise&lt;void&gt; | Promise used to return the synchronization result.|

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

### on('dataChange')

on(event: 'dataChange', type: SubscribeType, observer: Callback&lt;Array&lt;string&gt;&gt;): void

Registers a data change event listener for the RDB store. When the data in the RDB store changes, a callback is invoked to return the data changes.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Parameters**

| Name  | Type                                                        | Mandatory| Description                                                        |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| event    | string                                                       | Yes  | Event type. The value is **dataChange**, which indicates data changes.                     |
| type     | [SubscribeType](#subscribetype) | Yes  | Subscription type to register.                                                  |
| observer | Callback&lt;Array&lt;string&gt;&gt;                          | Yes  | Callback invoked to return the data change. **Array<string>** indicates the IDs of the peer devices whose data in the database is changed.|

**Example**

```ts
import deviceManager from '@ohos.distributedHardware.deviceManager';

let devices: string | undefined = undefined;

try {
  if (store != undefined) {
    (store as relationalStore.RdbStore).on('dataChange', relationalStore.SubscribeType.SUBSCRIBE_TYPE_REMOTE, (storeObserver) => {
      if (devices != undefined) {
        for (let i = 0; i < devices.length; i++) {
          console.info(`device= ${devices[i]} data changed`);
        }
      }
    })
  }
} catch (err) {
    let code = (err as BusinessError).code;
    let message = (err as BusinessError).message
    console.error(`Register observer failed, code is ${code},message is ${message}`);
}
```

### on('dataChange')<sup>10+</sup>

on(event: 'dataChange', type: SubscribeType, observer: Callback&lt;Array&lt;string&gt;&gt;\| Callback&lt;Array&lt;ChangeInfo&gt;&gt;): void

Registers a data change event listener for the RDB store. When the data in the RDB store changes, a callback is invoked to return the data changes.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Parameters**

| Name  | Type                               | Mandatory| Description                                       |
| -------- | ----------------------------------- | ---- | ------------------------------------------- |
| event    | string                              | Yes  | Event type. The value is **dataChange**, which indicates data changes.     |
| type     | [SubscribeType](#subscribetype)    | Yes  | Subscription type to register.|
| observer | Callback&lt;Array&lt;string&gt;&gt; \| Callback&lt;Array&lt;[ChangeInfo](#changeinfo10)&gt;&gt; | Yes  | Callback invoked to return the data change.<br>If **type** is **SUBSCRIBE_TYPE_REMOTE**, **observer** must be **Callback&lt;Array&lt;string&gt;&gt;**, where **Array&lt;string&gt;** specifies the IDs of the peer devices with data changes.<br>If **type** is **SUBSCRIBE_TYPE_CLOUD**, **observer** must be **Callback&lt;Array&lt;string&gt;&gt;**, where **Array&lt;string&gt;** specifies the cloud accounts with data changes.<br>If **type** is **SUBSCRIBE_TYPE_CLOUD_DETAILS**, **observer** must be **Callback&lt;Array&lt;ChangeInfo&gt;&gt;**, where **Array&lt;ChangeInfo&gt;** specifies the details about the device-cloud synchronization.|

**Example**

```ts
import deviceManager from '@ohos.distributedHardware.deviceManager';

let devices: string | undefined = undefined;

try {
  if(store != undefined) {
    (store as relationalStore.RdbStore).on('dataChange', relationalStore.SubscribeType.SUBSCRIBE_TYPE_REMOTE, storeObserver => {
      if (devices != undefined) {
        for (let i = 0; i < devices.length; i++) {
          console.info(`device= ${devices[i]} data changed`);
        }
      }
    });
  }
} catch (err) {
  let code = (err as BusinessError).code;
  let message = (err as BusinessError).message
  console.error(`Register observer failed, code is ${code},message is ${message}`);
}
```

### on<sup>10+</sup>

on(event: string, interProcess: boolean, observer: Callback\<void>): void

Registers an intra-process or inter-process event listener for the RDB store. This callback is invoked by [emit](#emit10).

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Parameters**

| Name      | Type           | Mandatory| Description                                                        |
| ------------ | --------------- | ---- | ------------------------------------------------------------ |
| event        | string          | Yes  | Event name to observe.                                              |
| interProcess | boolean         | Yes  | Type of the event to observe.<br>The value **true** means the inter-process event.<br>The value **false** means the intra-process event.|
| observer     | Callback\<void> | Yes  | Callback invoked to return the result.                                                  |

**Error codes**

For details about the error codes, see [RDB Error Codes](../errorcodes/errorcode-data-rdb.md).

| **ID**| **Error Message**                          |
| ------------ | -------------------------------------- |
| 14800000     | Inner error.                           |
| 14800050     | Failed to obtain subscription service. |

**Example**

```ts
try {
  if(store != undefined) {
    (store as relationalStore.RdbStore).on('storeObserver', false, (storeObserver) => {
      console.info(`storeObserver`);
    });
  }
} catch (err) {
  let code = (err as BusinessError).code;
  let message = (err as BusinessError).message
  console.error(`Register observer failed, code is ${code},message is ${message}`);
}
```

### on('autoSyncProgress')<sup>11+</sup>

on(event: 'autoSyncProgress', progress: Callback&lt;ProgressDetails&gt;): void

Registers a listener for the auto synchronization progress. This API can be called only when device-cloud synchronization is enabled and the network connection is normal. When auto synchronization is performed, a callback will be invoked to send a notification of the synchronization progress.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Parameters**

| Name      | Type                             | Mandatory| Description                               |
| ------------ |---------------------------------| ---- |-----------------------------------|
| event        | string                          | Yes  | Event type. The value is **autoSyncProgress**, which indicates the auto synchronization progress.|
| progress     | Callback&lt;[ProgressDetails](#progressdetails10)&gt; | Yes  | Callback invoked to return the auto synchronization progress.                            |

**Example**

```ts
import {BusinessError} from "@ohos.base";

try {
  if(store != undefined) {
    (store as relationalStore.RdbStore).on('autoSyncProgress', (progressDetail: relationalStore.ProgressDetails) => {
      console.info(`progress: ${progressDetail}`);
    });
  }
} catch (err) {
  let code = (err as BusinessError).code;
  let message = (err as BusinessError).message
  console.error(`Register observer failed, code is ${code},message is ${message}`);
}
```

### off('dataChange')

off(event:'dataChange', type: SubscribeType, observer: Callback&lt;Array&lt;string&gt;&gt;): void

Unregisters the data change event listener.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Parameters**

| Name  | Type                                                        | Mandatory| Description                                                        |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| event    | string                                                       | Yes  | Event type. The value is **dataChange**, which indicates data changes.                     |
| type     | [SubscribeType](#subscribetype) | Yes  | Subscription type to unregister.                                                |
| observer | Callback&lt;Array&lt;string&gt;&gt;                          | Yes  | Callback for the data change. **Array<string>** indicates the IDs of the peer devices whose data in the database is changed. |

**Example**

```ts
let devices: string | undefined = undefined;

try {
  if(store != undefined) {
    (store as relationalStore.RdbStore).off('dataChange', relationalStore.SubscribeType.SUBSCRIBE_TYPE_REMOTE, (storeObserver) => {
      if (devices != undefined){
        for (let i = 0; i < devices.length; i++) {
          console.info(`device= ${devices[i]} data changed`);
        }
      }
    });
  }
} catch (err) {
  let code = (err as BusinessError).code;
  let message = (err as BusinessError).message
  console.error(`Unregister observer failed, code is ${code},message is ${message}`);
}
```

### off('dataChange')<sup>10+</sup>

off(event:'dataChange', type: SubscribeType, observer?: Callback&lt;Array&lt;string&gt;&gt;\| Callback&lt;Array&lt;ChangeInfo&gt;&gt;): void

Unregisters the data change event listener.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Parameters**

| Name  | Type                               | Mandatory| Description                                       |
| -------- | ---------------------------------- | ---- | ------------------------------------------ |
| event    | string                              | Yes  | Event type. The value is **dataChange**, which indicates data changes.     |
| type     | [SubscribeType](#subscribetype)     | Yes  | Subscription type to unregister.                              |
| observer | Callback&lt;Array&lt;string&gt;&gt;\| Callback&lt;Array&lt;[ChangeInfo](#changeinfo10)&gt;&gt; | No| Callback for the data change.<br>If **type** is **SUBSCRIBE_TYPE_REMOTE**, **observer** must be **Callback&lt;Array&lt;string&gt;&gt;**, where **Array&lt;string&gt;** specifies the IDs of the peer devices with data changes.<br>If **type** is **SUBSCRIBE_TYPE_CLOUD**, **observer** must be **Callback&lt;Array&lt;string&gt;&gt;**, where **Array&lt;string&gt;** specifies the cloud accounts with data changes.<br>If **type** is **SUBSCRIBE_TYPE_CLOUD_DETAILS**, **observer** must be **Callback&lt;Array&lt;ChangeInfo&gt;&gt;**, where **Array&lt;ChangeInfo&gt;** specifies the details about the device-cloud synchronization.<br>If **observer** is not specified, listening for all data change events of the specified **type** will be canceled. |

**Example**

```ts
import deviceManager from '@ohos.distributedHardware.deviceManager';

let devices: string | undefined = undefined;

try {
  if(store != undefined) {
    (store as relationalStore.RdbStore).off('dataChange', relationalStore.SubscribeType.SUBSCRIBE_TYPE_REMOTE, (storeObserver) => {
      if (devices !=  undefined) {
        for (let i = 0; i < devices.length; i++) {
          console.info(`device= ${devices[i]} data changed`);
        }
      }
    });
  }
} catch (err) {
  let code = (err as BusinessError).code;
  let message = (err as BusinessError).message
  console.error(`Unregister observer failed, code is ${code},message is ${message}`);
}
```

### off<sup>10+</sup>

off(event: string, interProcess: boolean, observer?: Callback\<void>): void

Unregisters the data change event listener.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Parameters**

| Name      | Type           | Mandatory| Description                                                        |
| ------------ | --------------- | ---- | ------------------------------------------------------------ |
| event        | string          | Yes  | Name of the event.                                          |
| interProcess | boolean         | Yes  | Type of the event.<br>The value **true** means the inter-process event.<br>The value **false** means the intra-process event.|
| observer     | Callback\<void> | No  | Callback for the event to unregister.<br/>If this parameter is specified, the specified callback will be unregistered. If this parameter is not specified, all callbacks of the specified event will be unregistered. |

**Error codes**

For details about the error codes, see [RDB Error Codes](../errorcodes/errorcode-data-rdb.md).

| **ID**| **Error Message**                          |
| ------------ | -------------------------------------- |
| 14800000     | Inner error.                           |
| 14800050     | Failed to obtain subscription service. |

**Example**

```ts
try {
  if(store != undefined) {
    (store as relationalStore.RdbStore).off('storeObserver', false, (storeObserver) => {
      console.info(`storeObserver`);
    });
  }
} catch (err) {
  let code = (err as BusinessError).code;
  let message = (err as BusinessError).message
  console.error(`Unregister observer failed, code is ${code},message is ${message}`);
}
```

### off('autoSyncProgress')<sup>11+</sup>

off(event: 'autoSyncProgress', progress?: Callback&lt;ProgressDetails&gt;): void

Unregisters the listener for the auto synchronization progress.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Parameters**

| Name      | Type                             | Mandatory| Description                                                              |
| ------------ |---------------------------------| ---- |------------------------------------------------------------------|
| event        | string                          | Yes  | Event type. The value is **autoSyncProgress**, which indicates the auto synchronization progress.                               |
| observer     | Callback&lt;[ProgressDetails](#progressdetails10)&gt; | No  | Callback for the auto synchronization progress. If this parameter is specified, the specified callback will be unregistered. If this parameter is **null** or **undefined** or not specified, all callbacks for **autoSyncProgress** will be unregistered.|

**Example**

```ts
import {BusinessError} from "@ohos.base";

try {
  if(store != undefined) {
    (store as relationalStore.RdbStore).off('autoSyncProgress', (progressDetail: relationalStore.ProgressDetails) => {
      console.info(`progress: ${progressDetail}`);
    });
  }
} catch (err) {
  let code = (err as BusinessError).code;
  let message = (err as BusinessError).message;
  console.error(`Unregister failed, code is ${code},message is ${message}`);
}
```

### emit<sup>10+</sup>

emit(event: string): void

Triggers the inter-process or intra-process event listener registered through [on](#on10).

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Parameters**

| Name| Type  | Mandatory| Description                |
| ------ | ------ | ---- | -------------------- |
| event  | string | Yes  | Name of the event.|

**Error codes**

For details about the error codes, see [RDB Error Codes](../errorcodes/errorcode-data-rdb.md).

| **ID**| **Error Message**                          |
| ------------ | -------------------------------------- |
| 14800000     | Inner error.                           |
| 14800050     | Failed to obtain subscription service. |

**Example**

```ts
if(store != undefined) {
  (store as relationalStore.RdbStore).emit('storeObserver');
}
```

### cleanDirtyData<sup>11+</sup>

cleanDirtyData(table: string, cursor: number, callback: AsyncCallback&lt;void&gt;): void

Clears the dirty data with the cursor smaller than the specified cursor from the local device. The dirty data is the data that has been deleted from the cloud.

**System capability**: SystemCapability.DistributedDataManager.CloudSync.Client

**Parameters**

| Name  | Type                                                 | Mandatory| Description                                              |
| -------- | ----------------------------------------------------- | ---- | -------------------------------------------------- |
| table     | string                        | Yes  | Name of the table in the RDB store.                            |
| cursor    | number                        | Yes  | Cursor of the data, which is an integer. All the dirty data with the cursor smaller than the specified value will be cleared. |
| callback  | AsyncCallback&lt;void&gt;     | Yes  | Callback invoked to return the result.|

**Error codes**

For details about the error codes, see [RDB Error Codes](../errorcodes/errorcode-data-rdb.md).

| **ID**| **Error Message**                          |
| ------------ | -------------------------------------- |
| 14800000     | Inner error.                           |

**Example**

```ts
if(store != undefined) {
 (store as relationalStore.RdbStore).cleanDirtyData('test_table', 100, (err) => {
    if (err) {
      console.error(`clean dirty data failed, code is ${err.code},message is ${err.message}`);
      return;
    }
    console.info('clean dirty data succeeded');
  })
}
```

### cleanDirtyData<sup>11+</sup>

cleanDirtyData(table: string, callback: AsyncCallback&lt;void&gt;): void

Clears all dirty data from the local device. The dirty data is the data that has been deleted from the cloud.

**System capability**: SystemCapability.DistributedDataManager.CloudSync.Client

**Parameters**

| Name  | Type                                                 | Mandatory| Description                                              |
| -------- | ----------------------------------------------------- | ---- | -------------------------------------------------- |
| table     | string                        | Yes  | Name of the table in the RDB store.|
| callback  | AsyncCallback&lt;void&gt;     | Yes  | Callback invoked to return the result.|

**Error codes**

For details about the error codes, see [RDB Error Codes](../errorcodes/errorcode-data-rdb.md).

| **ID**| **Error Message**                          |
| ------------ | -------------------------------------- |
| 14800000     | Inner error.                           |

**Example**

```ts
if(store != undefined) {
  (store as relationalStore.RdbStore).cleanDirtyData('test_table', (err) => {
    if (err) {
      console.error(`clean dirty data failed, code is ${err.code},message is ${err.message}`);
      return;
    }
    console.info('clean dirty data succeeded');
  })
}
```

### cleanDirtyData<sup>11+</sup>

cleanDirtyData(table: string, cursor?: number): Promise&lt;void&gt;

Clears the dirty data with the cursor smaller than the specified cursor from the local device. The dirty data is the data that has been deleted from the cloud. If **cursor** is not specified, all the dirty data will be cleared.

**System capability**: SystemCapability.DistributedDataManager.CloudSync.Client

**Parameters**

| Name  | Type                                                 | Mandatory| Description                                              |
| -------- | ----------------------------------------------------- | ---- | -------------------------------------------------- |
| table     | string           | Yes  | Name of the table in the RDB store.          |
| cursor    | number           | No  | Cursor of the data, which is an integer. All the dirty data with the cursor smaller than the specified value will be cleared. If this parameter is not specified, all dirty data in the current table will be cleared. |

**Return value**
| Name   | Description                                              |
| -------- | ------------------------------------------------- |
| Promise<void> | Promise that returns no value.       |

**Error codes**

For details about the error codes, see [RDB Error Codes](../errorcodes/errorcode-data-rdb.md).

| **ID**| **Error Message**                          |
| ------------ | -------------------------------------- |
| 14800000     | Inner error.                           |

**Example**

```ts
import { BusinessError } from "@ohos.base";

if(store != undefined) {
    (store as relationalStore.RdbStore).cleanDirtyData('test_table', 100).then(() => {
        console.info('clean dirty data  succeeded');
    }).catch ((err: BusinessError) => {
        console.error(`clean dirty data failed, code is ${err.code},message is ${err.message}`);
    })
}
```

### querySharingResource<sup>11+</sup>

querySharingResource(predicates: RdbPredicates, columns?: Array&lt;string&gt;): Promise&lt;ResultSet&gt;

Queries the shared resource of the data matching the specified predicates. This API uses a promise to return the result set, which includes the shared resource ID and the column names if the column names are specified.

**System capability**: SystemCapability.DistributedDataManager.CloudSync.Client

**System API**: This is a system API.

**Parameters**

| Name  | Type                                                 | Mandatory| Description                                              |
| -------- | ----------------------------------------------------- | ---- | -------------------------------------------------- |
| predicates | [RdbPredicates](#rdbpredicates) | Yes  | Query conditions.   |
| columns    | Array&lt;string&gt;      | No  | Columns to be searched for. If this parameter is not specified, the returned result set contains only the shared resource ID.|

**Return value**

| Name   | Description                                              |
| -------- | ------------------------------------------------- |
| Promise&lt;[ResultSet](#resultset)&gt; | Promise used to return the result set.  |

**Error codes**

For details about the error codes, see [RDB Error Codes](../errorcodes/errorcode-data-rdb.md).

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

Queries the shared resource of the data matching the specified predicates. This API uses an asynchronous callback to return the result set.

**System capability**: SystemCapability.DistributedDataManager.CloudSync.Client

**System API**: This is a system API.

**Parameters**

| Name  | Type                                                 | Mandatory| Description                                              |
| -------- | ----------------------------------------------------- | ---- | -------------------------------------------------- |
| predicates | [RdbPredicates](#rdbpredicates)              | Yes  | Query conditions.          |
| callback   | AsyncCallback&lt;[ResultSet](#resultset)&gt; | Yes  | Callback invoked to return the result set.|

**Error codes**

For details about the error codes, see [RDB Error Codes](../errorcodes/errorcode-data-rdb.md).

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

Queries the shared resource of the data matching the specified predicates. This API uses an asynchronous callback to return the shared resource ID and the column names specified.

**System capability**: SystemCapability.DistributedDataManager.CloudSync.Client

**System API**: This is a system API.

**Parameters**

| Name  | Type                                                 | Mandatory| Description                                              |
| -------- | ----------------------------------------------------- | ---- | -------------------------------------------------- |
| predicates | [RdbPredicates](#rdbpredicates) | Yes  | **RdbPredicates** object.          |
| columns    | Array&lt;string&gt;              | Yes  | Columns to be searched for.          |
| callback   | AsyncCallback&lt;[ResultSet](#resultset)&gt;  | Yes  | Callback invoked to return the result set.|

**Error codes**

For details about the error codes, see [RDB Error Codes](../errorcodes/errorcode-data-rdb.md).

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

## ResultSet

Provides APIs to access the **resultSet** object returned by **query()**.

### Usage

Obtain the **resultSet** object first.

**Example**

```ts
let resultSet: relationalStore.ResultSet | undefined = undefined;
let predicates = new relationalStore.RdbPredicates("EMPLOYEE");
predicates.equalTo("AGE", 18);
if(store != undefined) {
  (store as relationalStore.RdbStore).query(predicates, ["ID", "NAME", "AGE", "SALARY", "CODES"]).then((result: relationalStore.ResultSet) => {
    resultSet = result;
    console.info(`resultSet columnNames: ${resultSet.columnNames}`);
    console.info(`resultSet columnCount: ${resultSet.columnCount}`);
  });
}
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

```ts
if(resultSet != undefined) {
  const id = (resultSet as relationalStore.ResultSet).getLong((resultSet as relationalStore.ResultSet).getColumnIndex("ID"));
  const name = (resultSet as relationalStore.ResultSet).getString((resultSet as relationalStore.ResultSet).getColumnIndex("NAME"));
  const age = (resultSet as relationalStore.ResultSet).getLong((resultSet as relationalStore.ResultSet).getColumnIndex("AGE"));
  const salary = (resultSet as relationalStore.ResultSet).getDouble((resultSet as relationalStore.ResultSet).getColumnIndex("SALARY"));
}
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

```ts
if(resultSet != undefined) {
  const id = (resultSet as relationalStore.ResultSet).getColumnName(0);
  const name = (resultSet as relationalStore.ResultSet).getColumnName(1);
  const age = (resultSet as relationalStore.ResultSet).getColumnName(2);
}
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

```ts
if(resultSet != undefined) {
  (resultSet as relationalStore.ResultSet).goTo(1);
}
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

```ts
if(resultSet != undefined) {
  (resultSet as relationalStore.ResultSet).goToRow(5);
}
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

```ts
if(resultSet != undefined) {
  (resultSet as relationalStore.ResultSet).goToFirstRow();
}
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

```ts
if(resultSet != undefined) {
  (resultSet as relationalStore.ResultSet).goToLastRow();
}
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

```ts
if(resultSet != undefined) {
  (resultSet as relationalStore.ResultSet).goToNextRow();
}
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

```ts
if(resultSet != undefined) {
  (resultSet as relationalStore.ResultSet).goToPreviousRow();
}
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

```ts
if(resultSet != undefined) {
  const codes = (resultSet as relationalStore.ResultSet).getBlob((resultSet as relationalStore.ResultSet).getColumnIndex("CODES"));
}
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

```ts
if(resultSet != undefined) {
  const name = (resultSet as relationalStore.ResultSet).getString((resultSet as relationalStore.ResultSet).getColumnIndex("NAME"));
}
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
| number | Value obtained.<br>The value range supported by this API is **Number.MIN_SAFE_INTEGER** to **Number.MAX_SAFE_INTEGER**. If the value is out of this range, use [getDouble](#getdouble).|

**Error codes**

For details about the error codes, see [RDB Error Codes](../errorcodes/errorcode-data-rdb.md).

| **ID**| **Error Message**                                                |
| ------------ | ------------------------------------------------------------ |
| 14800013     | The column value is null or the column type is incompatible. |

**Example**

```ts
if(resultSet != undefined) {
  const age = (resultSet as relationalStore.ResultSet).getLong((resultSet as relationalStore.ResultSet).getColumnIndex("AGE"));
 }
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
| number | Returns the value obtained.|

**Error codes**

For details about the error codes, see [RDB Error Codes](../errorcodes/errorcode-data-rdb.md).

| **ID**| **Error Message**                                                |
| ------------ | ------------------------------------------------------------ |
| 14800013     | The column value is null or the column type is incompatible. |

**Example**

```ts
if(resultSet != undefined) {
  const salary = (resultSet as relationalStore.ResultSet).getDouble((resultSet as relationalStore.ResultSet).getColumnIndex("SALARY"));
}
```

### getAsset<sup>10+</sup>

getAsset(columnIndex: number): Asset

Obtains the value in the [Asset](#asset10) format based on the specified column and current row.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Parameters**

| Name        | Type    | Mandatory | Description          |
| ----------- | ------ | --- | ------------ |
| columnIndex | number | Yes  | Index of the target column, starting from 0.|

**Return value**

| Type             | Description                        |
| --------------- | -------------------------- |
| [Asset](#asset10) | Returns the value obtained.|

**Error codes**

For details about the error codes, see [RDB Error Codes](../errorcodes/errorcode-data-rdb.md).

| **ID**| **Error Message**                                                    |
| --------- | ------------------------------------------------------------ |
| 14800013  | The column value is null or the column type is incompatible. |

**Example**

```ts
if(resultSet != undefined) {
  const doc = (resultSet as relationalStore.ResultSet).getAsset((resultSet as relationalStore.ResultSet).getColumnIndex("DOC"));
}
```

### getAssets<sup>10+</sup>

getAssets(columnIndex: number): Assets

Obtains the value in the [Assets](#assets10) format based on the specified column and current row.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Parameters**

| Name        | Type    | Mandatory | Description          |
| ----------- | ------ | --- | ------------ |
| columnIndex | number | Yes  | Index of the target column, starting from 0.|

**Return value**

| Type             | Description                          |
| ---------------- | ---------------------------- |
| [Assets](#assets10)| Returns the value obtained.|

**Error codes**

For details about the error codes, see [RDB Error Codes](../errorcodes/errorcode-data-rdb.md).

| **ID**| **Error Message**                                                |
| ------------ | ------------------------------------------------------------ |
| 14800013     | The column value is null or the column type is incompatible. |

**Example**

```ts
if(resultSet != undefined) {
  const docs = (resultSet as relationalStore.ResultSet).getAssets((resultSet as relationalStore.ResultSet).getColumnIndex("DOCS"));
}
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

```ts
if(resultSet != undefined) {
  const isColumnNull = (resultSet as relationalStore.ResultSet).isColumnNull((resultSet as relationalStore.ResultSet).getColumnIndex("CODES"));
}
```

### close

close(): void

Closes this result set.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Example**

```ts
if(resultSet != undefined) {
  (resultSet as relationalStore.ResultSet).close();
}
```

**Error codes**

For details about the error codes, see [RDB Error Codes](../errorcodes/errorcode-data-rdb.md).

| **ID**| **Error Message**                                                |
| ------------ | ------------------------------------------------------------ |
| 14800012     | The result set is empty or the specified location is invalid. |
