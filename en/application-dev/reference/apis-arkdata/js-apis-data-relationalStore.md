# @ohos.data.relationalStore (RDB Store)

The relational database (RDB) store manages data based on relational models. The **relationalStore** module provides a complete mechanism for managing local databases based on the underlying SQLite. You can use the APIs to perform operations such as adding, deleting, modifying, and querying data, and directly run SQL statements. You can also use [ResultSet.getSendableRow](#getsendablerow12) to obtain sendable data for cross-thread transmission.

The maximum size of a data record is 2 MB. If a data record exceeds 2 MB, it can be inserted successfully but cannot be read.

Querying data from a large amount of data may take time or even cause application suspension. In this case, you can perform batch operations. For details, see [Batch Database Operations](../../arkts-utils/batch-database-operations-guide.md). Moreover, observe the following:
- The number of data records to be queried at a time should not exceed 5000.
- Use [TaskPool](../apis-arkts/js-apis-taskpool.md) if there is a large amount of data needs to be queried.
- Keep concatenated SQL statements as concise as possible.
- Query data in batches.

The **relationalStore** module provides the following functionality:

- [RdbPredicates](#rdbpredicates): provides predicates indicating the nature, feature, or relationship of a data entity in an RDB store. It is used to define the operation conditions for an RDB store.
- [RdbStore](#rdbstore): provides APIs for managing data in an RDB store.
- [Resultset](#resultset): provides APIs for accessing the result set obtained from the RDB store. 
- [Transaction](#transaction14): provides APIs for managing transaction objects.

> **NOTE**
> 
> The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```ts
import { relationalStore } from '@kit.ArkData';
```

## relationalStore.getRdbStore

getRdbStore(context: Context, config: StoreConfig, callback: AsyncCallback&lt;RdbStore&gt;): void

Obtains an RDB store. This API uses an asynchronous callback to return the result. You can set parameters for the RDB store based on service requirements and call APIs to perform data operations.

The parameter [encrypt](#storeconfig) takes effect only when the RDB store is created for the first time, and cannot be modified. It is important to set this parameter correctly.

| Encryption Type When the RDB Store Is Opened | Encryption Type When the RDB Store Is Created          | Behavior|
| ------- | -------------------------------- | ---- |
| Not encrypt| Encrypt                         | The RDB store is opened in encrypted mode.  |
|  Encrypt| Not encrypt                         | The RDB store is opened in non-encrypted mode.  |

Currently, **getRdbStore()** does not support multi-thread concurrent operations.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Parameters**

| Name  | Type                                          | Mandatory| Description                                                        |
| -------- | ---------------------------------------------- | ---- | ------------------------------------------------------------ |
| context  | Context                                        | Yes  | Application context.<br>For details about the application context of the FA model, see [Context](../apis-ability-kit/js-apis-inner-app-context.md).<br>For details about the application context of the stage model, see [Context](../apis-ability-kit/js-apis-inner-application-uiAbilityContext.md).|
| config   | [StoreConfig](#storeconfig)               | Yes  | Configuration of the RDB store.                               |
| callback | AsyncCallback&lt;[RdbStore](#rdbstore)&gt; | Yes  | Callback used to return the RDB store obtained.                  |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [RDB Store Error Codes](errorcode-data-rdb.md). For details about how to handle error 14800011, see [Database Backup and Restore](../../database/data-backup-and-restore.md).

| **ID**| **Error Message**  |
|-----------|---------|
| 401       | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 14800000  | Inner error.     |
| 14800010  | Invalid database path.   |
| 14800011  | Database corrupted.    |
| 14801001  | The operation is supported in the stage model only.    |
| 14801002  | Invalid data group ID.    |
| 14800017  | Config changed.   |
| 14800020  | The secret key is corrupted or lost.   |
| 14800021  | SQLite: Generic error.    |
| 14800022  | SQLite: Callback routine requested an abort.   |
| 14800023  | SQLite: Access permission denied.    |
| 14800027  | SQLite: Attempt to write a readonly database.   |
| 14800028  | SQLite: Some kind of disk I/O error occurred.     |
| 14800029  | SQLite: The database is full.  |
| 14800030  | SQLite: Unable to open the database file.   |

**Example**

FA model:

<!--code_no_check_fa-->
```js
import { featureAbility } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let store: relationalStore.RdbStore | undefined = undefined;
let context = featureAbility.getContext(); 

const STORE_CONFIG: relationalStore.StoreConfig = {
  name: "RdbTest.db",
  securityLevel: relationalStore.SecurityLevel.S3
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
import { UIAbility } from '@kit.AbilityKit';
import { window } from '@kit.ArkUI';
import { BusinessError } from '@kit.BasicServicesKit';

let store: relationalStore.RdbStore | undefined = undefined;

class EntryAbility extends UIAbility {
  onWindowStageCreate(windowStage: window.WindowStage) {
    const STORE_CONFIG: relationalStore.StoreConfig = {
      name: "RdbTest.db",
      securityLevel: relationalStore.SecurityLevel.S3
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

The parameter [encrypt](#storeconfig) takes effect only when the RDB store is created for the first time, and cannot be modified. It is important to set this parameter correctly.

| Encryption Type When the RDB Store Is Opened | Encryption Type When the RDB Store Is Created          | Behavior|
| ------- | -------------------------------- | ---- |
| Not encrypt| Encrypt                         | The RDB store is opened in encrypted mode.  |
|  Encrypt| Not encrypt                         | The RDB store is opened in non-encrypted mode.  |

Currently, **getRdbStore()** does not support multi-thread concurrent operations.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Parameters**

| Name | Type                            | Mandatory| Description                                                        |
| ------- | -------------------------------- | ---- | ------------------------------------------------------------ |
| context | Context                          | Yes  | Application context.<br>For details about the application context of the FA model, see [Context](../apis-ability-kit/js-apis-inner-app-context.md).<br>For details about the application context of the stage model, see [Context](../apis-ability-kit/js-apis-inner-application-uiAbilityContext.md).|
| config  | [StoreConfig](#storeconfig) | Yes  | Configuration of the RDB store.                               |

**Return value**

| Type                                     | Description                             |
| ----------------------------------------- | --------------------------------- |
| Promise&lt;[RdbStore](#rdbstore)&gt; | Promise used to return the **RdbStore** object obtained.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [RDB Store Error Codes](errorcode-data-rdb.md). For details about how to handle error 14800011, see [Database Backup and Restore](../../database/data-backup-and-restore.md).

| **ID**| **Error Message**                                                |
|-----------| ------------------------------------------------------------ |
| 401       | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 14800000  | Inner error. |
| 14800010  | Invalid database path. |
| 14800011  | Database corrupted.  |
| 14801001  | The operation is supported in the stage model only.                               |
| 14801002  | Invalid data group ID.                             |
| 14800017  | Config changed. |
| 14800020  | The secret key is corrupted or lost.   |
| 14800021  | SQLite: Generic error. |
| 14800022  | SQLite: Callback routine requested an abort.   |
| 14800023  | SQLite: Access permission denied.    |
| 14800027  | SQLite: Attempt to write a readonly database. |
| 14800028  | SQLite: Some kind of disk I/O error occurred. |
| 14800029  | SQLite: The database is full. |
| 14800030  | SQLite: Unable to open the database file. |

**Example**

FA model:

<!--code_no_check_fa-->
```js
import { featureAbility } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let store: relationalStore.RdbStore | undefined = undefined;
let context = featureAbility.getContext(); 

const STORE_CONFIG: relationalStore.StoreConfig = {
  name: "RdbTest.db",
  securityLevel: relationalStore.SecurityLevel.S3
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
import { UIAbility } from '@kit.AbilityKit';
import { window } from '@kit.ArkUI';
import { BusinessError } from '@kit.BasicServicesKit';

let store: relationalStore.RdbStore | undefined = undefined;

class EntryAbility extends UIAbility {
  onWindowStageCreate(windowStage: window.WindowStage) {
    const STORE_CONFIG: relationalStore.StoreConfig = {
      name: "RdbTest.db",
      securityLevel: relationalStore.SecurityLevel.S3
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
| context  | Context                   | Yes  | Application context.<br>For details about the application context of the FA model, see [Context](../apis-ability-kit/js-apis-inner-app-context.md).<br>For details about the application context of the stage model, see [Context](../apis-ability-kit/js-apis-inner-application-uiAbilityContext.md).|
| name     | string                    | Yes  | Name of the RDB store to delete.                                                |
| callback | AsyncCallback&lt;void&gt; | Yes  | Callback used to return the result.                                      |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [RDB Store Error Codes](errorcode-data-rdb.md).

| **ID**| **Error Message**                       |
|-----------|---------------------------------------|
| 401       | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 14800000  | Inner error.     |
| 14800010  | Failed to open or delete database by invalid database path. |

**Example**

FA model:

<!--code_no_check_fa-->
```js
import { featureAbility } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let store: relationalStore.RdbStore | undefined = undefined;
let context = featureAbility.getContext(); 

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
import { UIAbility } from '@kit.AbilityKit';
import { window } from '@kit.ArkUI';
import { BusinessError } from '@kit.BasicServicesKit';

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
| context | Context | Yes  | Application context.<br>For details about the application context of the FA model, see [Context](../apis-ability-kit/js-apis-inner-app-context.md).<br>For details about the application context of the stage model, see [Context](../apis-ability-kit/js-apis-inner-application-uiAbilityContext.md).|
| name    | string  | Yes  | Name of the RDB store to delete.                                                |

**Return value**

| Type               | Description                     |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [RDB Store Error Codes](errorcode-data-rdb.md).

| **ID**| **Error Message**                                                                        |
|-----------|----------------------------------------------------------------------------------|
| 401       | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 14800000  | Inner error.                                                                     |
| 14800010  | Invalid database path.                      |

**Example**

FA model:

<!--code_no_check_fa-->
```js
import { featureAbility } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let store: relationalStore.RdbStore | undefined = undefined;
let context = featureAbility.getContext(); 

relationalStore.deleteRdbStore(context, "RdbTest.db").then(()=>{
  store = undefined;
  console.info('Delete RdbStore successfully.');
}).catch((err: BusinessError) => {
  console.error(`Delete RdbStore failed, code is ${err.code},message is ${err.message}`);
})
```

Stage model:

```ts
import { UIAbility } from '@kit.AbilityKit';
import { window } from '@kit.ArkUI';
import { BusinessError } from '@kit.BasicServicesKit';

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
| context  | Context                     | Yes  | Application context.<br>For details about the application context of the FA model, see [Context](../apis-ability-kit/js-apis-inner-app-context.md).<br>For details about the application context of the stage model, see [Context](../apis-ability-kit/js-apis-inner-application-uiAbilityContext.md).|
| config   | [StoreConfig](#storeconfig) | Yes  | Configuration of the RDB store.                               |
| callback | AsyncCallback&lt;void&gt;   | Yes  | Callback used to return the result.                                      |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [RDB Store Error Codes](errorcode-data-rdb.md).

| **ID**| **Error Message**         |
|-----------|----------|
| 401       | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 14800000  | Inner error.        |
| 14800010  | Failed to open or delete database by invalid database path.        |
| 14801001  | The operation is supported in the stage model only.         |
| 14801002  | Invalid data group ID.        |

**Example**

FA model:

<!--code_no_check_fa-->
```js
import { featureAbility } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let store: relationalStore.RdbStore | undefined = undefined;
let context = featureAbility.getContext(); 

const STORE_CONFIG: relationalStore.StoreConfig = {
  name: "RdbTest.db",
  securityLevel: relationalStore.SecurityLevel.S3
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
import { UIAbility } from '@kit.AbilityKit';
import { window } from '@kit.ArkUI';
import { BusinessError } from '@kit.BasicServicesKit';

let store: relationalStore.RdbStore | undefined = undefined;

class EntryAbility extends UIAbility {
  onWindowStageCreate(windowStage: window.WindowStage){
    const STORE_CONFIG: relationalStore.StoreConfig = {
      name: "RdbTest.db",
      securityLevel: relationalStore.SecurityLevel.S3
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
| context | Context                     | Yes  | Application context.<br>For details about the application context of the FA model, see [Context](../apis-ability-kit/js-apis-inner-app-context.md).<br>For details about the application context of the stage model, see [Context](../apis-ability-kit/js-apis-inner-application-uiAbilityContext.md).|
| config  | [StoreConfig](#storeconfig) | Yes  | Configuration of the RDB store.                               |

**Return value**

| Type               | Description                     |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [RDB Error Codes](errorcode-data-rdb.md).

| **ID**| **Error Message**            |
|-----------|---------------------|
| 401       | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 801       | Capability not supported.      |
| 14800000  | Inner error.      |
| 14800010  | Invalid database path.   |
| 14801001  | The operation is supported in the stage model only.   |
| 14801002  | Invalid data group ID.   |

**Example**

FA model:

<!--code_no_check_fa-->
```js
import { featureAbility } from "@kit.AbilityKit";
import { BusinessError } from '@kit.BasicServicesKit';

let store: relationalStore.RdbStore | undefined = undefined;
let context = featureAbility.getContext(); 

const STORE_CONFIG: relationalStore.StoreConfig = {
  name: "RdbTest.db",
  securityLevel: relationalStore.SecurityLevel.S3
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
import { UIAbility } from '@kit.AbilityKit';
import { window } from '@kit.ArkUI';
import { BusinessError } from '@kit.BasicServicesKit';

let store: relationalStore.RdbStore | undefined = undefined;

class EntryAbility extends UIAbility {
  onWindowStageCreate(windowStage: window.WindowStage){
    const STORE_CONFIG: relationalStore.StoreConfig = {
      name: "RdbTest.db",
      securityLevel: relationalStore.SecurityLevel.S3
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
## relationalStore.isVectorSupported<sup>16+</sup>

isVectorSupported(): boolean

Checks whether the system supports vector stores.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Return value**

| Type   | Description                                             |
| ------- | ------------------------------------------------- |
| boolean | Returns **true** if the system supports vector stores; returns **false** otherwise.|

**Example**

```
let result = relationalStore.isVectorSupported();
```

## relationalStore.isTokenizerSupported<sup>16+</sup>

isTokenizerSupported(tokenizer: Tokenizer): boolean

Checks whether the specified tokenizer is supported. This API returns the result synchronously.

This API returns **true** if the specified tokenizer is supported; returns **false** otherwise.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Parameters**

| Name | Type                 | Mandatory| Description                                                        |
| ------- | --------------------- | ---- | ------------------------------------------------------------ |
| tokenizer | [Tokenizer](#tokenizer16)               | Yes  | Tokenizer to check.|

**Return value**

| Type               | Description                     |
| ------------------- | ------------------------- |
| boolean | Returns **true** if the specified tokenizer is supported; returns **false** otherwise.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| **ID**| **Error Message**            |
|-----------|---------------------|
| 401       | Parameter error. Possible causes: Incorrect parameter types. |


**Example**

```ts
import { relationalStore } from '@kit.ArkData'; // Import the relationalStore module.

let customType = relationalStore.Tokenizer.CUSTOM_TOKENIZER;
let customTypeSupported = relationalStore.isTokenizerSupported(customType);
console.info("custom tokenizer supported on current platform: " + customTypeSupported);
```

## StoreConfig

Defines the RDB store configuration.

| Name       | Type         | Mandatory| Description                                                     |
| ------------- | ------------- | ---- | --------------------------------------------------------- |
| name          | string        | Yes  | Database file name, which is the unique identifier of the database.<br>**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core  |
| securityLevel | [SecurityLevel](#securitylevel) | Yes  | Security level of the RDB store.<br>**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core|
| encrypt       | boolean       | No  | Whether to encrypt the RDB store.<br> The value **true** means to encrypt the RDB store; the value **false** (default) means the opposite.<br>**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core|
| dataGroupId<sup>10+</sup> | string | No| Application group ID, which needs to be obtained from AppGallery Connect (AGC). This parameter is not supported currently.<br>**Model restriction**: This attribute can be used only in the stage model.<br>This parameter is supported since API version 10. If this parameter is specified, the **RdbStore** instance will be created in the sandbox directory corresponding to the specified **dataGroupId**. The encrypted database in the sandbox directory corresponding to a **dataGroupId** does not support multi-process access. If this parameter is left blank, the **RdbStore** instance is created in the sandbox directory of the current application by default.<br>**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core|
| customDir<sup>11+</sup> | string | No| Customized path of the RDB store.<br>**Constraints**: The value cannot exceed 128 bytes.<br>This parameter is supported since API version 11. The RDB store directory is in the **context.databaseDir**/**rdb**/**customDir** format. **context.databaseDir** specifies the application sandbox path. **rdb** is a fixed field that indicates an RDB store. **customDir** specifies the customized path. If this parameter is not specified, the **RdbStore** instance is created in the sandbox directory of the application. Since API version 16, if the **rootDir** parameter is also configured, the RDB store in the following directory will be opened or deleted: rootDir + "/" + customDir + "/" + name.<br>**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core|
| rootDir<sup>16+</sup> | string | No| Root path of the database.<br>This parameter is supported since API version 16. The database in the **rootDir** + "/" + **customDir** directory will be opened or deleted. The database opened is read-only. Writing data to a read-only database will trigger error 801. If this parameter is set when you want to open or delete an RDB store, ensure that the database file exists in the corresponding path and the caller has the read permission. Otherwise, error 14800010 will be returned.<br>**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core|
| autoCleanDirtyData<sup>11+</sup> | boolean | No| Whether to automatically clear the dirty data (data that has been deleted from the cloud) from the local device. The value **true** means to clear the dirty data automatically. The value **false** means to clear the data manually. The default value is **true**.<br>This parameter applies to the RDB stores with device-cloud synergy. To manually clear the dirty data, use [cleanDirtyData<sup>11+</sup>](#cleandirtydata11).<br>This parameter is supported since API version 11.<br>**System capability**: SystemCapability.DistributedDataManager.CloudSync.Client|
| allowRebuild<sup>12+</sup> | boolean | No| Whether auto rebuild is allowed when the RDB store is corrupted. The default value is **false**.<br>The value **true** means auto rebuild is allowed.<br>The value **false** means the opposite.<br>This parameter is supported since API version 12.<br>**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core|
| isReadOnly<sup>12+</sup> | boolean | No| Whether the RDB store is read-only. The default value is **false**, which means the RDB store is readable and writeable.<br>If the value is **true** (read-only), writing data to the RDB store will throw error code 801.<br>The value **false** means the RDB store is readable and writeable.<br>This parameter is supported since API version 12.<br>**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core|
| pluginLibs<sup>12+</sup> | Array\<string> | No| Dynamic libraries with capabilities such as Full-Text Search (FTS).<br>**Constraints**<br>1. The maximum number of dynamic library names is 16. If the number of dynamic library names exceeds 16, the library fails to be opened and an error is returned.<br>2. The dynamic libraries must be those in the sandbox directory or system directory of the application. If a dynamic library fails to be loaded, the RDB store cannot be opened and an error will be returned.<br>3. The dynamic library name must be a complete path that can be loaded by SQLite.<br>Example: [context.bundleCodeDir + "/libs/arm64/" + libtokenizer.so], where **context.bundleCodeDir** indicates the application sandbox path, **/libs/arm64/** is the subdirectory, **libtokenizer.so** indicates the file name of the dynamic library. If this parameter is left blank, dynamic libraries are not loaded by default.<br>4. The dynamic library must contain all its dependencies to prevent the failure caused by the lack of dependencies.<br>For example, in an NDK project, the default compilation parameters are used to build **libtokenizer.so**, which depends on the C++ standard library. When the dynamic library is loaded, **libc++_shared.so** is linked by mistake because the namespace is different from that during compilation. As a result, the **__emutls_get_address** symbol cannot be found. To solve this problem, you need to statically link the C++ standard library during compilation. For details, see [NDK Project Building Overview](../../napi/build-with-ndk-overview.md).<br>**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core|
| cryptoParam<sup>14+</sup> | [CryptoParam](#cryptoparam14) | No| Custom encryption parameters.<br>If this parameter is left empty, the default encryption parameters are used. For details, see default values of [CryptoParam](#cryptoparam14).<br>This parameter is valid only when **encrypt** is **true**.<br>This parameter is supported since API version 14.<br>**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core|
| vector<sup>16+</sup> | boolean | No| Whether the RDB store is a vector store. The value **true** means the RDB store is a vector store, and the value **false** means the opposite.<br>The vector store is ideal for storing and managing high-dimensional vector data, while the relational database is optimal for storing and processing structured data.<br>Currently, vector stores support [execute](#execute12-1), [querySql](#querysql-1), [beginTrans](#begintrans12), [commit](#commit12), [rollback](#rollback12), [backup](#backup), [restore](#restore), and [ResultSet](#resultset) APIs. Before calling **deleteRdbStore** to delete a vector store, ensure that the vector store is properly closed. **System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core|
| tokenizer<sup>16+</sup> | [Tokenizer](#tokenizer16) | No| Type of the tokenizer to be used for FTS.<br>If this parameter is left blank, English tokenization is supported if FTS does not support Chinese or multi-language tokenization.<br>**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core|

## SecurityLevel

Enumerates the RDB store security levels. Use the enum name rather than the enum value. You cannot change the security level of an RDB store from a higher level to a lower one.

> **NOTE**
>
> To perform data sync operations, the RDB store security level must be lower than or equal to that of the peer device. For details, see [Access Control Mechanism in Cross-Device Sync](../../database/access-control-by-device-and-data-level.md#access-control-mechanism-in-cross-device-sync).

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

| Name| Value  | Description                                                        |
| ---- | ---- | ------------------------------------------------------------ |
| S1   | 1    | The RDB store security level is low. If data leakage occurs, minor impact will be caused on the database. For example, an RDB store that contains system data such as wallpapers.|
| S2   | 2    | The RDB store security level is medium. If data leakage occurs, moderate impact will be caused on the database. For example, an RDB store that contains information created by users or call records, such as audio or video clips.|
| S3   | 3    | The RDB store security level is high. If data leakage occurs, major impact will be caused on the database. For example, an RDB store that contains information such as user fitness, health, and location data.|
| S4   | 4    | The RDB store security level is critical. If data leakage occurs, severe impact will be caused on the database. For example, an RDB store that contains information such as authentication credentials and financial data.|

## CryptoParam<sup>14+</sup>

Represents the configuration of database encryption parameters. This parameter is valid only when **encrypt** in **StoreConfig** is **true**.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

| Name         | Type  | Mandatory| Description                                                        |
| ------------- | ------ | ---- | ------------------------------------------------------------ |
| encryptionKey | Uint8Array | Yes  | Key used for database encryption and decryption.<br>If this parameter is not specified, the RDB store generates a key, saves the key, and uses the key to open the database file.<br>If the key is not required, you need to set the key to 0s.|
| iterationCount | number | No| Number of iterations of the PBKDF2 algorithm used in the RDB store. The value is an integer. The default value is **10000**.<br>The value must be an integer greater than 0. If it is not an integer, the value is rounded down.<br>If this parameter is not specified or is set to **0**, the default value **10000** and the default encryption algorithm **AES_256_GCM** are used.|
| encryptionAlgo | [EncryptionAlgo](#encryptionalgo14) | No| Algorithm used for database encryption and decryption. The default value is **AES_256_GCM**.|
| hmacAlgo | [HmacAlgo](#hmacalgo14) | No| HMAC algorithm used for database encryption and decryption. The default value is **SHA256**.|
| kdfAlgo | [KdfAlgo](#kdfalgo14) | No| PBKDF2 algorithm used for database encryption and decryption. The default value is the same as the HMAC algorithm used.|
| cryptoPageSize | number | No| Page size used for database encryption and decryption. The default value is **1024** bytes.<br>The value must be an integer within the range of 1024 to 65536 and must be 2<sup>n</sup>. If the specified value is not an integer, the value is rounded down.|

## EncryptionAlgo<sup>14+</sup>

Enumerates the database encryption algorithms. Use the enum name rather than the enum value.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

| Name| Value  | Description|
| ---- | ---- | ---- |
| AES_256_GCM |  0    | AES_256_GCM.    |
| AES_256_CBC |  1    | AES_256_CBC.    |

## HmacAlgo<sup>14+</sup>

Enumerates the HMAC algorithms for the database. Use the enum name rather than the enum value.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

| Name| Value  | Description|
| ---- | ---- | ---- |
| SHA1 |  0    | HMAC_SHA1.    |
| SHA256 |  1    | HMAC_SHA256.    |
| SHA512 |  2    | HMAC_SHA512.   |

## KdfAlgo<sup>14+</sup>

Enumerates the PBKDF2 algorithms for the database. Use the enum name rather than the enum value.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

| Name| Value  | Description|
| ---- | ---- | ---- |
| KDF_SHA1 |  0    | PBKDF2_HMAC_SHA1.    |
| KDF_SHA256 |  1    | PBKDF2_HMAC_SHA256.    |
| KDF_SHA512 |  2    | PBKDF2_HMAC_SHA512.    |

## Tokenizer<sup>16+</sup>

Enumerates tokenizers that can be used for FTS. Use the enum name rather than the enum value.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

| Name                             | Value  | Description            |
| ------------------------------- | --- | -------------- |
| NONE_TOKENIZER     | 0  | No tokenizer is used.     |
| ICU_TOKENIZER | 1 | The ICU tokenizer is used, which supports Chinese and multiple languages. If the ICU tokenizer is used, you can set the language to use, for example, **zh_CN** for Chinese and **tr_TR** for Turkish. For details about the supported languages, see [ICU tokenizer](https://gitee.com/openharmony/third_party_icu/blob/master/icu4c/source/data/lang/en.txt). For details about the language abbreviations, see [locales](https://gitee.com/openharmony/third_party_icu/tree/master/icu4c/source/data/locales).|
| CUSTOM_TOKENIZER | 2 | A custom tokenizer is used. Chinese (simplified and traditional), English, and Arabic numerals are supported. Compared with **ICU_TOKENIZER**, **CUSTOM_TOKENIZER** has advantages in tokenization accuracy and resident memory usage.|

The table creation statement varies with the tokenizer in use.

**Example**

The following is an example of the table creation statement when **ICU_TOKENIZER** is used:

```ts
import { relationalStore } from '@kit.ArkData'; // Import the relationalStore module.
import { UIAbility } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { window } from '@kit.ArkUI';

// In this example, Ability is used to obtain an RdbStore instance in the stage model. You can use other implementations as required.
class EntryAbility extends UIAbility {
  onWindowStageCreate(windowStage: window.WindowStage) {
    let store: relationalStore.RdbStore | undefined = undefined;
    const STORE_CONFIG: relationalStore.StoreConfig = {
      name: "MyStore.db",
      securityLevel: relationalStore.SecurityLevel.S3,
      tokenizer: relationalStore.Tokenizer.ICU_TOKENIZER
    };
    store = await relationalStore.getRdbStore(this.context, STORE_CONFIG);

    const SQL_CREATE_TABLE = "CREATE VIRTUAL TABLE example USING fts4(name, content, tokenize=icu zh_CN)"
    if(store != undefined) {
      (store as relationalStore.RdbStore).executeSql(SQL_CREATE_TABLE, (err) => {
        if (err) {
          console.error(`ExecuteSql failed, code is ${err.code},message is ${err.message}`);
          return;
        }
        console.info('create virtual table done.');
      })
    }
  }
}
```

The following is an example of the table creation statement when **CUSTOM_TOKENIZER** is used:

```ts
import { relationalStore } from '@kit.ArkData'; // Import the relationalStore module.
import { UIAbility } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { window } from '@kit.ArkUI';

// In this example, Ability is used to obtain an RdbStore instance in the stage model. You can use other implementations as required.
class EntryAbility extends UIAbility {
  onWindowStageCreate(windowStage: window.WindowStage) {
    let store: relationalStore.RdbStore | undefined = undefined;
    const STORE_CONFIG: relationalStore.StoreConfig = {
      name: "MyStore.db",
      securityLevel: relationalStore.SecurityLevel.S3,
      tokenizer: relationalStore.Tokenizer.CUSTOM_TOKENIZER
    };
    store = await relationalStore.getRdbStore(this.context, STORE_CONFIG);

    const SQL_CREATE_TABLE = "CREATE VIRTUAL TABLE example USING fts5(name, content, tokenize='customtokenizer')"
    if(store != undefined) {
      (store as relationalStore.RdbStore).executeSql(SQL_CREATE_TABLE, (err) => {
        if (err) {
          console.error(`ExecuteSql failed, code is ${err.code},message is ${err.message}`);
          return;
        }
    		console.info('create virtual table done.');
      })
    }
  }
}
```

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

Defines information about an asset (such as a document, image, and video).

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

type Assets = Asset[]

Defines an array of the [Asset](#asset10) type.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

| Type   | Description                |
| ------- | -------------------- |
| [Asset](#asset10)[] | Array of assets.  |

## ValueType

type ValueType = null | number | string | boolean | Uint8Array | Asset | Assets | Float32Array | bigint

Enumerates the types of the value in a KV pair. The type varies with the parameter function.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

| Type   | Description                |
| ------- | -------------------- |
| null<sup>10+</sup>    | Null.  |
| number  | Number.  |
| string  | String. |
| boolean | Boolean.|
| Uint8Array<sup>10+</sup>           | Uint8 array.           |
| Asset<sup>10+</sup>  | [Asset](#asset10).<br>If the value type is Asset, the type in the SQL statement for creating a table must be ASSET.|
| Assets<sup>10+</sup> | [Assets](#assets10).<br>If the value type is Assets, the type in the SQL statement for creating a table must be ASSETS.|
| Float32Array<sup>12+</sup> | Array of 32-bit floating-point numbers.<br>If the field type is Float32Array, the type in the SQL statement for creating a table must be floatvector(128).|
| bigint<sup>12+</sup> | Integer of any length.<br>If the value type is bigint, the type in the SQL statement for creating a table must be **UNLIMITED INT**. For details, see [Persisting RDB Store Data](../../database/data-persistence-by-rdb-store.md).<br>**NOTE**<br>The bigint type does not support value comparison and cannot be used with the following predicates: **between**, **notBetween**, **greaterThanlessThan**, **greaterThanOrEqualTo**, **lessThanOrEqualTo**, **orderByAsc**, and **orderByDesc**<br>To write a value of bigint type, use **BigInt()** or add **n** to the end of the value, for example,'let data = BigInt(1234)' or 'let data = 1234n'.<br>If data of the number type is written to a bigint field, the type of the return value obtained (queried) is number but not bigint.|

## ValuesBucket

type ValuesBucket = Record<string, ValueType>

Defines the data in the form of a KV pair. **ValuesBucket** cannot be passed across threads.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

| Type             | Description                          |
| ---------------- | ---------------------------- |
| Record<string, [ValueType](#valuetype)> | Types of the key and value in a KV pair. The key type is string, and the value type is [ValueType](#valuetype).|

## PRIKeyType<sup>10+</sup> 

type PRIKeyType = number | string

Enumerates the types of the primary key in a row of a database table.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

| Type            | Description                              |
| ---------------- | ---------------------------------- |
| number | The primary key is a number.|
| string | The primary key is a string.|

## UTCTime<sup>10+</sup>

type UTCTime = Date

Represents the data type of the UTC time.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

| Type| Description           |
| ---- | --------------- |
| Date | UTC time.|

## ModifyTime<sup>10+</sup> 

type ModifyTime = Map<PRIKeyType, UTCTime>

Represents the data type of the primary key and modification time of a database table.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

| Type                                                   | Description                                                        |
| ------------------------------------------------------- | ------------------------------------------------------------ |
| Map<[PRIKeyType](#prikeytype10), [UTCTime](#utctime10)> | The key is the primary key of a row in the database table, and the value is the last modification time of the row in UTC format.|

## SyncMode

Enumerates the database sync modes. Use the enum name rather than the enum value.

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
| DELETED_FLAG_FIELD  | '#_deleted_flag' | Whether the dirty data (data deleted from the cloud) is cleared from the local device. It fills in the result set returned upon the cursor-based search.<br>The value **true** means the dirty data is cleared; the value **false** means the opposite.|
| DATA_STATUS_FIELD<sup>12+</sup>   | '#_data_status' | Data status in the cursor-based search result set. The value **0** indicates normal data status; **1** indicates that data is retained after the account is logged out; **2** indicates that data is deleted from the cloud; **3** indicates that data is deleted after the account is logged out.|
| OWNER_FIELD  | '#_cloud_owner' | Party who shares the data. It fills in the result set returned when the owner of the shared data is searched.|
| PRIVILEGE_FIELD  | '#_cloud_privilege' | Operation permission on the shared data. It fills in the result set returned when the permission on the shared data is searched.|
| SHARING_RESOURCE_FIELD   | '#_sharing_resource_field' | Resource shared. It fills in the result set returned when the shared resource is searched.|

## SubscribeType

Enumerates the subscription types. Use the enum name rather than the enum value.

| Name                 | Value  | Description              |
| --------------------- | ---- | ------------------ |
| SUBSCRIBE_TYPE_REMOTE | 0    | Subscribe to remote data changes.<br>**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core|
| SUBSCRIBE_TYPE_CLOUD<sup>10+</sup> | 1  | Subscribe to cloud data changes.<br>**System capability**: SystemCapability.DistributedDataManager.CloudSync.Client|
| SUBSCRIBE_TYPE_CLOUD_DETAILS<sup>10+</sup> | 2  | Subscribe to cloud data change details.<br>**System capability**: SystemCapability.DistributedDataManager.CloudSync.Client|
| SUBSCRIBE_TYPE_LOCAL_DETAILS<sup>12+</sup> | 3  | Subscribe to details of the local data change.<br>**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core|

## RebuildType<sup>12+</sup>

Enumerates the RDB store rebuild types. Use the enum name rather than the enum value.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

| Name   | Value  | Description                                                                                                            |
| ------- | ---- |----------------------------------------------------------------------------------------------------------------|
| NONE    | 0    | The RDB store is not rebuilt.                                                                                                   |
| REBUILT | 1    | Create an empty database to rebuild the RDB store. You need to create tables and restore data.                                                                            |
| REPAIRED | 2    | Restore uncorrupted data of the RDB store. Only [vector stores](#storeconfig) support this feature.|

## ChangeType<sup>10+</sup>

Enumerates data change types. Use the enum name rather than the enum value.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

| Name                        | Value  | Description                        |
| -------------------------- | --- | -------------------------- |
| DATA_CHANGE  | 0   | Data change.  |
| ASSET_CHANGE | 1   | Asset change.|

## ChangeInfo<sup>10+</sup>

Represents the detail information about the device-cloud sync process.

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

| Name               | Value  | Description                                                                                                |
| ------------------ | --- | -------------------------------------------------------------------------------------------------- |
| DISTRIBUTED_DEVICE | 0  | Distributed database table between devices.<br>**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core              |
| DISTRIBUTED_CLOUD  | 1   | Distributed database table between the device and the cloud.<br>**System capability**: SystemCapability.DistributedDataManager.CloudSync.Client|

## DistributedConfig<sup>10+</sup>

Defines the configuration of the distributed mode of tables.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

| Name    | Type   | Mandatory| Description                                                        |
| -------- | ------- | ---- | ------------------------------------------------------------ |
| autoSync   | boolean | Yes  | The value **true** means both auto sync and manual sync are supported for the table. The value **false** means only manual sync is supported for the table.|
| asyncDownloadAsset<sup>16+</sup> | boolean | No| Whether to download assets synchronously or asynchronously when device-cloud sync is being performed for the current RDB store. The value **true** means to use an asynchronous task to download assets after all data is downloaded. The value **false** means to downloaded assets synchronously. The default value is **false**.|

## ConflictResolution<sup>10+</sup>

Defines the resolution to use when a conflict occurs during data insertion or modification. Use the enum name rather than the enum value.

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

Enumerates the stages in the device-cloud sync progress. Use the enum name rather than the enum value.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

| Name            | Value  | Description                    |
| ---------------- | ---- | ------------------------ |
| SYNC_BEGIN       | 0    | The device-cloud sync starts.  |
| SYNC_IN_PROGRESS | 1    | The device-cloud sync is in progress.|
| SYNC_FINISH      | 2    | The device-cloud sync is complete.|

## Statistic<sup>10+</sup>

Represents the device-cloud sync statistics information.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

| Name      | Type  | Mandatory| Description                                    |
| ---------- | ------ | ---- | ---------------------------------------- |
| total      | number | Yes  | Total number of rows to be synchronized between the device and cloud in the database table.    |
| successful | number | Yes  | Number of rows that are successfully synchronized between the device and cloud in the database table.      |
| failed     | number | Yes  | Number of rows that failed to be synchronized between the device and cloud in the database table.      |
| remained   | number | Yes  | Number of rows that are not executed for device-cloud sync in the database table.|

## TableDetails<sup>10+</sup>

Represents the upload and download statistics of device-cloud sync tasks.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

| Name    | Type                     | Mandatory| Description                                      |
| -------- | ------------------------- | ---- | ------------------------------------------ |
| upload   | [Statistic](#statistic10) | Yes  | Statistics of the device-cloud upload tasks.|
| download | [Statistic](#statistic10) | Yes  | Statistics of the device-cloud download tasks.|

## ProgressCode<sup>10+</sup>

Enumerates the device-cloud sync states. Use the enum name rather than the enum value.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

| Name                 | Value  | Description                                                        |
| --------------------- | ---- | ------------------------------------------------------------ |
| SUCCESS               | 0    | The device-cloud sync is successful.                                      |
| UNKNOWN_ERROR         | 1    | An unknown error occurs during device-cloud sync.                              |
| NETWORK_ERROR         | 2    | A network error occurs during device-cloud sync.                              |
| CLOUD_DISABLED        | 3    | The cloud is unavailable.                                            |
| LOCKED_BY_OTHERS      | 4    | The device-cloud sync of another device is being performed.<br>Start device-cloud sync after checking that cloud resources are not occupied by other devices.|
| RECORD_LIMIT_EXCEEDED | 5    | The number of records or size of the data to be synchronized exceeds the maximum. The maximum value is configured on the cloud.|
| NO_SPACE_FOR_ASSET    | 6    | The remaining cloud space is less than the size of the data to be synchronized.                    |
| BLOCKED_BY_NETWORK_STRATEGY<sup>12+</sup>    | 7    | The device-cloud sync is blocked due to the network strategy.                    |

## ProgressDetails<sup>10+</sup>

Represents the statistics of the overall device-cloud sync (upload and download) tasks.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

| Name    | Type                                             | Mandatory| Description                                                        |
| -------- | ------------------------------------------------- | ---- | ------------------------------------------------------------ |
| schedule | [Progress](#progress10)                           | Yes  | Device-cloud sync progress.                                          |
| code     | [ProgressCode](#progresscode10)                   | Yes  | Device-cloud sync state.                                    |
| details  | Record<string, [TableDetails](#tabledetails10)> | Yes  | Statistics of each table.<br>The key indicates the table name, and the value indicates the device-cloud sync statistics of the table.|

## SqlExecutionInfo<sup>12+</sup>

Represents statistics about SQL statements executed by the database.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

| Name    | Type                                              | Read-Only| Optional |Description                                                        |
| -------- | ------------------------------------------------- | ---- | ---- | -------------------------------------------------------- |
| sql<sup>12+</sup>           | Array&lt;string&gt;            | Yes  |   No  | SQL statements executed. If the value of [batchInsert](#batchinsert) is too large, there may be multiple SQL statements.     |
| totalTime<sup>12+</sup>      | number                        | Yes  |   No  | Total time used to execute the SQL statements, in μs.                                   |
| waitTime<sup>12+</sup>       | number                        | Yes  |   No  | Time used to obtain the handle, in μs.                                        |
| prepareTime<sup>12+</sup>    | number                        | Yes  |   No  | Time used to get the SQL statements ready and bind parameters, in μs.                                |
| executeTime<sup>12+</sup>    | number                        | Yes  |   No  | Total time used to execute the SQL statements, in μs.|

## TransactionType<sup>14+</sup>

Enumerates the types of transaction objects that can be created. Use the enum name rather than the enum value.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

| Name            | Value  | Description                    |
| ---------------- | ---- | ------------------------ |
| DEFERRED       | 0    | Deferred transaction object. When a deferred transaction object is created, automatic commit is disabled and no transaction will start. A read or write transaction starts only when the first read or write operation is performed.  |
| IMMEDIATE | 1    | Immediate transaction object. When an immediate transaction object is created, a write transaction starts. If there is any uncommitted write transaction, the transaction object cannot be created and error 14800024 is returned.|
| EXCLUSIVE      | 2    | Exclusive transaction object. In WAL mode, the exclusive transaction object is the same as the immediate transaction object. In other log modes, this type of transaction can prevent the database from being read by other connections during the transaction.|

## TransactionOptions<sup>14+</sup>

Represents the configuration of a transaction object.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

| Name       | Type         | Mandatory| Description                                                     |
| ------------- | ------------- | ---- | --------------------------------------------------------- |
| transactionType          | [TransactionType](#transactiontype14)        | No  | Transaction object type. The default value is **DEFERRED**. |

## RdbPredicates

Defines the predicates for an RDB store. This class determines whether the conditional expression for the RDB store is true or false. Multiple predicates statements can be concatenated by using **and()** by default. **RdbPredicates** cannot be passed across threads.

### constructor

constructor(name: string)

A constructor used to create an **RdbPredicates** object.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Parameters**

| Name| Type  | Mandatory| Description        |
| ------ | ------ | ---- | ------------ |
| name   | string | Yes  | Database table name.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| **ID**| **Error Message**                                                                                                      |
| --------- |----------------------------------------------------------------------------------------------------------------|
| 401       | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified;  2. Incorrect parameter types. |

**Example**

```ts
let predicates = new relationalStore.RdbPredicates("EMPLOYEE");
```

### inDevices

inDevices(devices: Array&lt;string&gt;): RdbPredicates

Sets an **RdbPredicates** object to specify the remote devices to connect during the distributed database sync.

> **NOTE**
>
> **devices** can be obtained by [deviceManager.getAvailableDeviceListSync](../apis-distributedservice-kit/js-apis-distributedDeviceManager.md#getavailabledevicelistsync).
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

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| **ID**| **Error Message**                                                                                                      |
| --------- |----------------------------------------------------------------------------------------------------------------|
| 401       | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified;  2. Incorrect parameter types. |

**Example**

```ts
import { distributedDeviceManager } from '@kit.DistributedServiceKit';
import { BusinessError } from '@kit.BasicServicesKit';

let dmInstance: distributedDeviceManager.DeviceManager;
let deviceIds: Array<string> = [];

try {
  dmInstance = distributedDeviceManager.createDeviceManager("com.example.appdatamgrverify");
  let devices: Array<distributedDeviceManager.DeviceBasicInfo> = dmInstance.getAvailableDeviceListSync();
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
```

### inAllDevices

inAllDevices(): RdbPredicates

Sets an **RdbPredicates** instance to specify all remote devices to connect during the distributed database sync.


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

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| **ID**| **Error Message**                                                                                                      |
| --------- |----------------------------------------------------------------------------------------------------------------|
| 401       | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified;  2. Incorrect parameter types. |

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

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| **ID**| **Error Message**                                                                                                      |
| --------- |----------------------------------------------------------------------------------------------------------------|
| 401       | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified;  2. Incorrect parameter types. |

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

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| **ID**| **Error Message**                                                                                                      |
| --------- |----------------------------------------------------------------------------------------------------------------|
| 401       | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified;  2. Incorrect parameter types. |

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

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| **ID**| **Error Message**                                                                                                      |
| --------- |----------------------------------------------------------------------------------------------------------------|
| 401       | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified;  2. Incorrect parameter types. |

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

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| **ID**| **Error Message**                                                                                                      |
| --------- |----------------------------------------------------------------------------------------------------------------|
| 401       | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified;  2. Incorrect parameter types. |

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

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| **ID**| **Error Message**                                                                                                      |
| --------- |----------------------------------------------------------------------------------------------------------------|
| 401       | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified;  2. Incorrect parameter types. |

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

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| **ID**| **Error Message**                                                                                                      |
| --------- |----------------------------------------------------------------------------------------------------------------|
| 401       | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified;  2. Incorrect parameter types. |

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

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| **ID**| **Error Message**                                                                                                      |
| --------- |----------------------------------------------------------------------------------------------------------------|
| 401       | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified;  2. Incorrect parameter types. |

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

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| **ID**| **Error Message**                                                                                                      |
| --------- |----------------------------------------------------------------------------------------------------------------|
| 401       | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified;  2. Incorrect parameter types. |

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

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| **ID**| **Error Message**                                                                                                      |
| --------- |----------------------------------------------------------------------------------------------------------------|
| 401       | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified;  2. Incorrect parameter types. |

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

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| **ID**| **Error Message**                                                                                                      |
| --------- |----------------------------------------------------------------------------------------------------------------|
| 401       | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified;  2. Incorrect parameter types. |

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

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| **ID**| **Error Message**                                                                                                      |
| --------- |----------------------------------------------------------------------------------------------------------------|
| 401       | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified;  2. Incorrect parameter types. |

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

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| **ID**| **Error Message**                                                                                                      |
| --------- |----------------------------------------------------------------------------------------------------------------|
| 401       | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified;  2. Incorrect parameter types. |

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

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| **ID**| **Error Message**                                                                                                      |
| --------- |----------------------------------------------------------------------------------------------------------------|
| 401       | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified;  2. Incorrect parameter types. |

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

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| **ID**| **Error Message**                                                                                                      |
| --------- |----------------------------------------------------------------------------------------------------------------|
| 401       | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified;  2. Incorrect parameter types. |

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

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| **ID**| **Error Message**                                                                                                      |
| --------- |----------------------------------------------------------------------------------------------------------------|
| 401       | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified;  2. Incorrect parameter types. |

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

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| **ID**| **Error Message**                                                                                                      |
| --------- |----------------------------------------------------------------------------------------------------------------|
| 401       | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified;  2. Incorrect parameter types. |

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

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| **ID**| **Error Message**              |
| --------- |--------------------------|
| 401       | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified;  2. Incorrect parameter types. |

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

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| **ID**| **Error Message**                                                                                                      |
| --------- |----------------------------------------------------------------------------------------------------------------|
| 401       | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified;  2. Incorrect parameter types. |

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

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| **ID**| **Error Message**                                                                                                      |
| --------- |----------------------------------------------------------------------------------------------------------------|
| 401       | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified;  2. Incorrect parameter types. |

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

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| **ID**| **Error Message**                                                                                                      |
| --------- |----------------------------------------------------------------------------------------------------------------|
| 401       | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified;  2. Incorrect parameter types. |

**Example**

```ts
let predicates = new relationalStore.RdbPredicates("EMPLOYEE");
predicates.indexedBy("SALARY");
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

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| **ID**| **Error Message**                                                                                                      |
| --------- |----------------------------------------------------------------------------------------------------------------|
| 401       | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified;  2. Incorrect parameter types. |

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

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| **ID**| **Error Message**                                                                                                      |
| --------- |----------------------------------------------------------------------------------------------------------------|
| 401       | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified;  2. Incorrect parameter types. |

**Example**

```ts
// Locate data of all the employees except Lisa and Rose in the table.
let predicates = new relationalStore.RdbPredicates("EMPLOYEE");
predicates.notIn("NAME", ["Lisa", "Rose"]);
```

### notContains<sup>12+</sup>

notContains(field: string, value: string): RdbPredicates

Sets an **RdbPredicates** object to match the fields in the specified column that do not contain the given value.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Parameters**

| Name| Type  | Mandatory| Description                  |
| ------ | ------ | ---- | ---------------------- |
| field  | string | Yes  | Column name in the database table.    |
| value  | string | Yes  | Value to match the **RdbPredicates**.|

**Return value**

| Type                           | Description                      |
| ------------------------------- | -------------------------- |
| [RdbPredicates](#rdbpredicates) | **RdbPredicates** object created.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| **ID**| **Error Message**                                                                                                      |
| --------- |----------------------------------------------------------------------------------------------------------------|
| 401       | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified;  2. Incorrect parameter types. |

**Example**

```ts
// Match the fields that do not contain "os" in the NAME column of the data table, for example, Lisa in the list.
let predicates = new relationalStore.RdbPredicates("EMPLOYEE");
predicates.notContains("NAME", "os");
```

### notLike<sup>12+</sup>

notLike(field: string, value: string): RdbPredicates

Sets an **RdbPredicates** object to match the fields in the specified column that are not similar to the given value.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Parameters**

| Name| Type  | Mandatory| Description                  |
| ------ | ------ | ---- | ---------------------- |
| field  | string | Yes  | Column name in the database table.    |
| value  | string | Yes  | Value to match the **RdbPredicates**.|

**Return value**

| Type                           | Description                      |
| ------------------------------- | -------------------------- |
| [RdbPredicates](#rdbpredicates) | **RdbPredicates** object created.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| **ID**| **Error Message**                                                                                                      |
| --------- |----------------------------------------------------------------------------------------------------------------|
| 401       | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified;  2. Incorrect parameter types. |

**Example**

```ts
// Match the fields that are not "os" in the NAME column of the data table, for example, Rose in the list.
let predicates = new relationalStore.RdbPredicates("EMPLOYEE");
predicates.notLike("NAME", "os");
```



## RdbStore

Provides APIs to manage an RDB store.

Before using the APIs of this class, use [executeSql](#executesql) to initialize the database table structure and related data.

### Properties

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

| Name        | Type           | Read-Only      | Optional| Description                            |
| ------------ | ----------- | ---- | -------------------------------- | -------------------------------- |
| version<sup>10+</sup>  | number | No| No  | RDB store version, which is an integer greater than 0.      |
| rebuilt<sup>12+</sup> | [RebuildType](#rebuildtype12) | Yes| No| Whether the RDB store has been rebuilt or repaired.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [RDB Store Error Codes](errorcode-data-rdb.md).

| **ID**| **Error Message**                                                |
|-----------| ------------------------------------------------------------ |
| 401       | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 801       | Capability not supported. |
| 14800000  | Inner error. |
| 14800014  | Already closed. |
| 14800015  | The database does not respond. |
| 14800021  | SQLite: Generic error. |
| 14800023  | SQLite: Access permission denied. |
| 14800024  | SQLite: The database file is locked. |
| 14800025  | SQLite: A table in the database is locked. |
| 14800026  | SQLite: The database is out of memory. |
| 14800027  | SQLite: Attempt to write a readonly database. |
| 14800028  | SQLite: Some kind of disk I/O error occurred. |
| 14800029  | SQLite: The database is full. |
| 14800030  | SQLite: Unable to open the database file. |

**Example**

```ts
// Set the RDB store version.
if(store != undefined) {
  (store as relationalStore.RdbStore).version = 3;
  // Obtain the RDB store version.
  console.info(`RdbStore version is ${store.version}`);
  // Whether the RDB store has been rebuilt.
  console.info(`RdbStore rebuilt is ${store.rebuilt}`);
}
```

### insert

insert(table: string, values: ValuesBucket, callback: AsyncCallback&lt;number&gt;):void

Inserts a row of data into a table. This API uses an asynchronous callback to return the result. Due to the limit of the shared memory (max. 2 MB), a single data record cannot exceed 2 MB. Otherwise, the query operation will fail.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Parameters**

| Name  | Type                         | Mandatory| Description                                                      |
| -------- | ----------------------------- | ---- | ---------------------------------------------------------- |
| table    | string                        | Yes  | Name of the target table.                                          |
| values   | [ValuesBucket](#valuesbucket) | Yes  | Row of data to insert.                                |
| callback | AsyncCallback&lt;number&gt;   | Yes  | Callback used to return the result. If the operation is successful, the row ID will be returned. Otherwise, **-1** will be returned.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [RDB Store Error Codes](errorcode-data-rdb.md). For details about how to handle error 14800011, see [Database Backup and Restore](../../database/data-backup-and-restore.md).

| **ID**| **Error Message**                                                |
|-----------| ------------------------------------------------------------ |
| 401       | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 14800000  | Inner error. |
| 14800011  | Database corrupted. |
| 14800014  | Already closed. |
| 14800015  | The database does not respond. |
| 14800021  | SQLite: Generic error. |
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
let value1 = "Lisa";
let value2 = 18;
let value3 = 100.5;
let value4 = new Uint8Array([1, 2, 3, 4, 5]);

// You can use either of the following:
const valueBucket1: relationalStore.ValuesBucket = {
  'NAME': value1,
  'AGE': value2,
  'SALARY': value3,
  'CODES': value4,
};
const valueBucket2: relationalStore.ValuesBucket = {
  NAME: value1,
  AGE: value2,
  SALARY: value3,
  CODES: value4,
};
const valueBucket3: relationalStore.ValuesBucket = {
  "NAME": value1,
  "AGE": value2,
  "SALARY": value3,
  "CODES": value4,
};

if(store != undefined) {
  (store as relationalStore.RdbStore).insert("EMPLOYEE", valueBucket1, (err: BusinessError, rowId: number) => {
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

Inserts a row of data into a table. This API uses an asynchronous callback to return the result. Due to the limit of the shared memory (max. 2 MB), a single data record cannot exceed 2 MB. Otherwise, the query operation will fail.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Parameters**

| Name  | Type                                       | Mandatory| Description                                                      |
| -------- | ------------------------------------------- | ---- | ---------------------------------------------------------- |
| table    | string                                      | Yes  | Name of the target table.                                          |
| values   | [ValuesBucket](#valuesbucket)               | Yes  | Row of data to insert.                                |
| conflict | [ConflictResolution](#conflictresolution10) | Yes  | Resolution used to resolve the conflict.                                        |
| callback | AsyncCallback&lt;number&gt;                 | Yes  | Callback used to return the result. If the operation is successful, the row ID will be returned. Otherwise, **-1** will be returned.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [RDB Store Error Codes](errorcode-data-rdb.md). For details about how to handle error 14800011, see [Database Backup and Restore](../../database/data-backup-and-restore.md).

| **ID**| **Error Message**                                                |
|-----------| ---------------------------------------------------- |
| 401       | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 14800000  | Inner error. |
| 14800011  | Database corrupted. |
| 14800014  | Already closed. |
| 14800015  | The database does not respond. |
| 14800021  | SQLite: Generic error. |
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
let value1 = "Lisa";
let value2 = 18;
let value3 = 100.5;
let value4 = new Uint8Array([1, 2, 3, 4, 5]);

// You can use either of the following:
const valueBucket1: relationalStore.ValuesBucket = {
  'NAME': value1,
  'AGE': value2,
  'SALARY': value3,
  'CODES': value4,
};
const valueBucket2: relationalStore.ValuesBucket = {
  NAME: value1,
  AGE: value2,
  SALARY: value3,
  CODES: value4,
};
const valueBucket3: relationalStore.ValuesBucket = {
  "NAME": value1,
  "AGE": value2,
  "SALARY": value3,
  "CODES": value4,
};

if(store != undefined) {
  (store as relationalStore.RdbStore).insert("EMPLOYEE", valueBucket1, relationalStore.ConflictResolution.ON_CONFLICT_REPLACE,
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

Inserts a row of data into a table. This API uses a promise to return the result. Due to the limit of the shared memory (max. 2 MB), a single data record cannot exceed 2 MB. Otherwise, the query operation will fail.

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

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [RDB Store Error Codes](errorcode-data-rdb.md). For details about how to handle error 14800011, see [Database Backup and Restore](../../database/data-backup-and-restore.md).

| **ID**| **Error Message**                                                |
|-----------| ------------------------------------------------------------ |
| 401       | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 14800000  | Inner error. |
| 14800011  | Database corrupted. |
| 14800014  | Already closed. |
| 14800015  | The database does not respond. |
| 14800021  | SQLite: Generic error. |
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
import { BusinessError } from '@kit.BasicServicesKit';

let value1 = "Lisa";
let value2 = 18;
let value3 = 100.5;
let value4 = new Uint8Array([1, 2, 3, 4, 5]);

// You can use either of the following:
const valueBucket1: relationalStore.ValuesBucket = {
  'NAME': value1,
  'AGE': value2,
  'SALARY': value3,
  'CODES': value4,
};
const valueBucket2: relationalStore.ValuesBucket = {
  NAME: value1,
  AGE: value2,
  SALARY: value3,
  CODES: value4,
};
const valueBucket3: relationalStore.ValuesBucket = {
  "NAME": value1,
  "AGE": value2,
  "SALARY": value3,
  "CODES": value4,
};

if(store != undefined) {
  (store as relationalStore.RdbStore).insert("EMPLOYEE", valueBucket1).then((rowId: number) => {
    console.info(`Insert is successful, rowId = ${rowId}`);
  }).catch((err: BusinessError) => {
    console.error(`Insert is failed, code is ${err.code},message is ${err.message}`);
  })
}
```

### insert<sup>10+</sup>

insert(table: string, values: ValuesBucket,  conflict: ConflictResolution):Promise&lt;number&gt;

Inserts a row of data into a table. This API uses a promise to return the result. Due to the limit of the shared memory (max. 2 MB), a single data record cannot exceed 2 MB. Otherwise, the query operation will fail.

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

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [RDB Store Error Codes](errorcode-data-rdb.md). For details about how to handle error 14800011, see [Database Backup and Restore](../../database/data-backup-and-restore.md).

| **ID**| **Error Message**                                                |
|-----------| ------------------------------------------------------------ |
| 401       | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 14800000  | Inner error. |
| 14800011  | Database corrupted. |
| 14800014  | Already closed. |
| 14800015  | The database does not respond. |
| 14800021  | SQLite: Generic error. |
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
import { BusinessError } from '@kit.BasicServicesKit';

let value1 = "Lisa";
let value2 = 18;
let value3 = 100.5;
let value4 = new Uint8Array([1, 2, 3, 4, 5]);

// You can use either of the following:
const valueBucket1: relationalStore.ValuesBucket = {
  'NAME': value1,
  'AGE': value2,
  'SALARY': value3,
  'CODES': value4,
};
const valueBucket2: relationalStore.ValuesBucket = {
  NAME: value1,
  AGE: value2,
  SALARY: value3,
  CODES: value4,
};
const valueBucket3: relationalStore.ValuesBucket = {
  "NAME": value1,
  "AGE": value2,
  "SALARY": value3,
  "CODES": value4,
};

if(store != undefined) {
  (store as relationalStore.RdbStore).insert("EMPLOYEE", valueBucket1, relationalStore.ConflictResolution.ON_CONFLICT_REPLACE).then((rowId: number) => {
    console.info(`Insert is successful, rowId = ${rowId}`);
  }).catch((err: BusinessError) => {
    console.error(`Insert is failed, code is ${err.code},message is ${err.message}`);
  })
}
```

### insertSync<sup>12+</sup>

insertSync(table: string, values: ValuesBucket,  conflict?: ConflictResolution):number

Inserts a row of data into a table. Due to the limit of the shared memory (max. 2 MB), a single data record cannot exceed 2 MB. Otherwise, the query operation will fail.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Parameters**

| Name  | Type                                       | Mandatory| Description                                                        |
| -------- | ------------------------------------------- | ---- | ------------------------------------------------------------ |
| table    | string                                      | Yes  | Name of the target table.                                            |
| values   | [ValuesBucket](#valuesbucket)               | Yes  | Row of data to insert.                                  |
| conflict | [ConflictResolution](#conflictresolution10) | No  | Resolution used to resolve the conflict. The default value is **relationalStore.ConflictResolution.ON_CONFLICT_NONE**.|

**Return value**

| Type  | Description                                |
| ------ | ------------------------------------ |
| number | If the operation is successful, the row ID will be returned. Otherwise, **-1** will be returned.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [RDB Store Error Codes](errorcode-data-rdb.md). For details about how to handle error 14800011, see [Database Backup and Restore](../../database/data-backup-and-restore.md).

| **ID**| **Error Message**                                                |
| ------------ | ------------------------------------------------------------ |
| 401          | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 14800000     | Inner error.                                                 |
| 14800011     | Database corrupted.                                          |
| 14800014     | Already closed.                                              |
| 14800015     | The database does not respond.                                        |
| 14800021     | SQLite: Generic error.                                       |
| 14800022     | SQLite: Callback routine requested an abort.                 |
| 14800023     | SQLite: Access permission denied.                            |
| 14800024     | SQLite: The database file is locked.                         |
| 14800025     | SQLite: A table in the database is locked.                   |
| 14800026     | SQLite: The database is out of memory.                       |
| 14800027     | SQLite: Attempt to write a readonly database.                |
| 14800028     | SQLite: Some kind of disk I/O error occurred.                |
| 14800029     | SQLite: The database is full.                                |
| 14800030     | SQLite: Unable to open the database file.                    |
| 14800031     | SQLite: TEXT or BLOB exceeds size limit.                     |
| 14800032     | SQLite: Abort due to constraint violation.                   |
| 14800033     | SQLite: Data type mismatch.                                  |
| 14800034     | SQLite: Library used incorrectly.                            |
| 14800047     | The WAL file size exceeds the default limit.                 |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let value1 = "Lisa";
let value2 = 18;
let value3 = 100.5;
let value4 = new Uint8Array([1, 2, 3, 4, 5]);

// You can use either of the following:
const valueBucket1: relationalStore.ValuesBucket = {
  'NAME': value1,
  'AGE': value2,
  'SALARY': value3,
  'CODES': value4,
};
const valueBucket2: relationalStore.ValuesBucket = {
  NAME: value1,
  AGE: value2,
  SALARY: value3,
  CODES: value4,
};
const valueBucket3: relationalStore.ValuesBucket = {
  "NAME": value1,
  "AGE": value2,
  "SALARY": value3,
  "CODES": value4,
};

if(store != undefined) {
  try {
    let rowId : number = (store as relationalStore.RdbStore).insertSync("EMPLOYEE", valueBucket1, relationalStore.ConflictResolution.ON_CONFLICT_REPLACE);
    console.info(`Insert is successful, rowId = ${rowId}`);
  } catch (error) {
      console.error(`Insert is failed, code is ${error.code},message is ${error.message}`);
  }
}
```

### insertSync<sup>12+</sup>

insertSync(table: string, values: sendableRelationalStore.ValuesBucket, conflict?: ConflictResolution):number

Inserts a row of Sendable data into a table. This API returns the result synchronously. Due to the limit of the shared memory (max. 2 MB), a single data record cannot exceed 2 MB. Otherwise, the query operation will fail.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Parameters**

| Name  | Type                                                                                          | Mandatory| Description                                                                           |
| -------- | ---------------------------------------------------------------------------------------------- | ---- | ------------------------------------------------------------------------------- |
| table    | string                                                                                         | Yes  | Name of the target table.                                                               |
| values   | [sendableRelationalStore.ValuesBucket](./js-apis-data-sendableRelationalStore.md#valuesbucket) | Yes  | Sendable data to insert.                                           |
| conflict | [ConflictResolution](#conflictresolution10)                                                    | No  | Resolution used to resolve the conflict. The default value is **relationalStore.ConflictResolution.ON_CONFLICT_NONE**.|

**Return value**

| Type  | Description                                |
| ------ | ------------------------------------ |
| number | If the operation is successful, the row ID will be returned. Otherwise, **-1** will be returned.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [RDB Store Error Codes](errorcode-data-rdb.md). For details about how to handle error 14800011, see [Database Backup and Restore](../../database/data-backup-and-restore.md).

| **ID**| **Error Message**                                                |
| ------------ | ------------------------------------------------------------ |
| 401          | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 14800000     | Inner error.                                                 |
| 14800011     | Database corrupted.                                          |
| 14800014     | Already closed.                                              |
| 14800015     | The database does not respond.                                        |
| 14800021     | SQLite: Generic error.                                       |
| 14800022     | SQLite: Callback routine requested an abort.                 |
| 14800023     | SQLite: Access permission denied.                            |
| 14800024     | SQLite: The database file is locked.                         |
| 14800025     | SQLite: A table in the database is locked.                   |
| 14800026     | SQLite: The database is out of memory.                       |
| 14800027     | SQLite: Attempt to write a readonly database.                |
| 14800028     | SQLite: Some kind of disk I/O error occurred.                |
| 14800029     | SQLite: The database is full.                                |
| 14800030     | SQLite: Unable to open the database file.                    |
| 14800031     | SQLite: TEXT or BLOB exceeds size limit.                     |
| 14800032     | SQLite: Abort due to constraint violation.                   |
| 14800033     | SQLite: Data type mismatch.                                  |
| 14800034     | SQLite: Library used incorrectly.                            |
| 14800047     | The WAL file size exceeds the default limit.                 |

**Example**

```ts
import { sendableRelationalStore } from '@kit.ArkData';

const valuesBucket: relationalStore.ValuesBucket = {
  "NAME": 'hangman',
  "AGE": 18,
  "SALARY": 100.5,
  "CODES": new Uint8Array([1,2,3]),
};
const sendableValuesBucket = sendableRelationalStore.toSendableValuesBucket(valuesBucket);

if(store != undefined) {
  try {
    let rowId : number = (store as relationalStore.RdbStore).insertSync("EMPLOYEE", sendableValuesBucket, relationalStore.ConflictResolution.ON_CONFLICT_REPLACE);
    console.info(`Insert is successful, rowId = ${rowId}`);
  } catch (error) {
    console.error(`Insert is failed, code is ${error.code},message is ${error.message}`);
  }
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
| values   | Array&lt;[ValuesBucket](#valuesbucket)&gt; | Yes  | An array of data to insert.            |
| callback | AsyncCallback&lt;number&gt;                | Yes  | Callback used to return the result. If the operation is successful, the number of inserted data records is returned. Otherwise, **-1** is returned.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [RDB Store Error Codes](errorcode-data-rdb.md). For details about how to handle error 14800011, see [Database Backup and Restore](../../database/data-backup-and-restore.md).

| **ID**| **Error Message**                                                |
|-----------| ------------------------------------------------------------ |
| 401       | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 14800000  | Inner error. |
| 14800011  | Database corrupted. |
| 14800014  | Already closed. |
| 14800015  | The database does not respond. |
| 14800021  | SQLite: Generic error. |
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

const valueBucket1: relationalStore.ValuesBucket = {
  'NAME': value1,
  'AGE': value2,
  'SALARY': value3,
  'CODES': value4,
};
const valueBucket2: relationalStore.ValuesBucket = {
  'NAME': value5,
  'AGE': value6,
  'SALARY': value7,
  'CODES': value8,
};
const valueBucket3: relationalStore.ValuesBucket = {
  'NAME': value9,
  'AGE': value10,
  'SALARY': value11,
  'CODES': value12,
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

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [RDB Store Error Codes](errorcode-data-rdb.md). For details about how to handle error 14800011, see [Database Backup and Restore](../../database/data-backup-and-restore.md).

| **ID**| **Error Message**                                                |
|-----------| ------------------------------------------------------------ |
| 401       | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 14800000  | Inner error. |
| 14800011  | Database corrupted. |
| 14800014  | Already closed. |
| 14800015  | The database does not respond. |
| 14800021  | SQLite: Generic error. |
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
import { BusinessError } from '@kit.BasicServicesKit';

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

const valueBucket1: relationalStore.ValuesBucket = {
  'NAME': value1,
  'AGE': value2,
  'SALARY': value3,
  'CODES': value4,
};
const valueBucket2: relationalStore.ValuesBucket = {
  'NAME': value5,
  'AGE': value6,
  'SALARY': value7,
  'CODES': value8,
};
const valueBucket3: relationalStore.ValuesBucket = {
  'NAME': value9,
  'AGE': value10,
  'SALARY': value11,
  'CODES': value12,
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

### batchInsertSync<sup>12+</sup>

batchInsertSync(table: string, values: Array&lt;ValuesBucket&gt;):number

Inserts a row of data into a table.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Parameters**

| Name| Type                                      | Mandatory| Description                        |
| ------ | ------------------------------------------ | ---- | ---------------------------- |
| table  | string                                     | Yes  | Name of the target table.            |
| values | Array&lt;[ValuesBucket](#valuesbucket)&gt; | Yes  | An array of data to insert.|

**Return value**

| Type  | Description                                          |
| ------ | ---------------------------------------------- |
| number | If the operation is successful, the number of inserted data records is returned. Otherwise, **-1** is returned.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [RDB Store Error Codes](errorcode-data-rdb.md). For details about how to handle error 14800011, see [Database Backup and Restore](../../database/data-backup-and-restore.md).

| **ID**| **Error Message**                                                |
| ------------ | ------------------------------------------------------------ |
| 401          | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 14800000     | Inner error.                                                 |
| 14800011     | Database corrupted.                                          |
| 14800014     | Already closed.                                              |
| 14800015     | The database does not respond.                                        |
| 14800021     | SQLite: Generic error.                                       |
| 14800022     | SQLite: Callback routine requested an abort.                 |
| 14800023     | SQLite: Access permission denied.                            |
| 14800024     | SQLite: The database file is locked.                         |
| 14800025     | SQLite: A table in the database is locked.                   |
| 14800026     | SQLite: The database is out of memory.                       |
| 14800027     | SQLite: Attempt to write a readonly database.                |
| 14800028     | SQLite: Some kind of disk I/O error occurred.                |
| 14800029     | SQLite: The database is full.                                |
| 14800030     | SQLite: Unable to open the database file.                    |
| 14800031     | SQLite: TEXT or BLOB exceeds size limit.                     |
| 14800032     | SQLite: Abort due to constraint violation.                   |
| 14800033     | SQLite: Data type mismatch.                                  |
| 14800034     | SQLite: Library used incorrectly.                            |
| 14800047     | The WAL file size exceeds the default limit.                 |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

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

const valueBucket1: relationalStore.ValuesBucket = {
  'NAME': value1,
  'AGE': value2,
  'SALARY': value3,
  'CODES': value4,
};
const valueBucket2: relationalStore.ValuesBucket = {
  'NAME': value5,
  'AGE': value6,
  'SALARY': value7,
  'CODES': value8,
};
const valueBucket3: relationalStore.ValuesBucket = {
  'NAME': value9,
  'AGE': value10,
  'SALARY': value11,
  'CODES': value12,
};

let valueBuckets = new Array(valueBucket1, valueBucket2, valueBucket3);
if(store != undefined) {
  try {
    let insertNum: number = (store as relationalStore.RdbStore).batchInsertSync("EMPLOYEE", valueBuckets);
    console.info(`batchInsert is successful, the number of values that were inserted = ${insertNum}`);
  } catch (err) {
      console.error(`batchInsert is failed, code is ${err.code},message is ${err.message}`);
  }
}
```

### update

update(values: ValuesBucket, predicates: RdbPredicates, callback: AsyncCallback&lt;number&gt;):void

Updates data in the RDB store based on the specified **RdbPredicates** object. This API uses an asynchronous callback to return the result. Due to the limit of the shared memory (max. 2 MB), a single data record cannot exceed 2 MB. Otherwise, the query operation will fail.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Parameters**

| Name    | Type                                | Mandatory| Description                                                        |
| ---------- | ------------------------------------ | ---- | ------------------------------------------------------------ |
| values     | [ValuesBucket](#valuesbucket)        | Yes  | Rows of data to update in the RDB store. The key-value pair is associated with the column name in the target table.|
| predicates | [RdbPredicates](#rdbpredicates) | Yes  | Update conditions specified by the **RdbPredicates** object.                   |
| callback   | AsyncCallback&lt;number&gt;          | Yes  | Callback used to return the number of rows updated.                  |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [RDB Store Error Codes](errorcode-data-rdb.md). For details about how to handle error 14800011, see [Database Backup and Restore](../../database/data-backup-and-restore.md).

| **ID**| **Error Message**                                                |
|-----------| ------------------------------------------------------------ |
| 401       | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 14800000  | Inner error. |
| 14800011  | Database corrupted. |
| 14800014  | Already closed. |
| 14800015  | The database does not respond. |
| 14800021  | SQLite: Generic error. |
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

let value1 = "Rose";
let value2 = 22;
let value3 = 200.5;
let value4 = new Uint8Array([1, 2, 3, 4, 5]);

// You can use either of the following:
const valueBucket1: relationalStore.ValuesBucket = {
  'NAME': value1,
  'AGE': value2,
  'SALARY': value3,
  'CODES': value4,
};
const valueBucket2: relationalStore.ValuesBucket = {
  NAME: value1,
  AGE: value2,
  SALARY: value3,
  CODES: value4,
};
const valueBucket3: relationalStore.ValuesBucket = {
  "NAME": value1,
  "AGE": value2,
  "SALARY": value3,
  "CODES": value4,
};

let predicates = new relationalStore.RdbPredicates("EMPLOYEE");
predicates.equalTo("NAME", "Lisa");
if(store != undefined) {
  (store as relationalStore.RdbStore).update(valueBucket1, predicates,(err, rows) => {
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

Updates data in the RDB store based on the specified **RdbPredicates** object. This API uses an asynchronous callback to return the result. Due to the limit of the shared memory (max. 2 MB), a single data record cannot exceed 2 MB. Otherwise, the query operation will fail.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Parameters**

| Name    | Type                                       | Mandatory| Description                                                        |
| ---------- | ------------------------------------------- | ---- | ------------------------------------------------------------ |
| values     | [ValuesBucket](#valuesbucket)               | Yes  | Rows of data to update in the RDB store. The key-value pair is associated with the column name in the target table.|
| predicates | [RdbPredicates](#rdbpredicates)            | Yes  | Update conditions specified by the **RdbPredicates** object.                     |
| conflict   | [ConflictResolution](#conflictresolution10) | Yes  | Resolution used to resolve the conflict.                                          |
| callback   | AsyncCallback&lt;number&gt;                 | Yes  | Callback used to return the number of rows updated.                  |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [RDB Store Error Codes](errorcode-data-rdb.md). For details about how to handle error 14800011, see [Database Backup and Restore](../../database/data-backup-and-restore.md).

| **ID**| **Error Message**                                                |
|-----------| ------------------------------------------------------------ |
| 401       | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 14800000  | Inner error. |
| 14800011  | Database corrupted. |
| 14800014  | Already closed. |
| 14800015  | The database does not respond. |
| 14800021  | SQLite: Generic error. |
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

let value1 = "Rose";
let value2 = 22;
let value3 = 200.5;
let value4 = new Uint8Array([1, 2, 3, 4, 5]);

// You can use either of the following:
const valueBucket1: relationalStore.ValuesBucket = {
  'NAME': value1,
  'AGE': value2,
  'SALARY': value3,
  'CODES': value4,
};
const valueBucket2: relationalStore.ValuesBucket = {
  NAME: value1,
  AGE: value2,
  SALARY: value3,
  CODES: value4,
};
const valueBucket3: relationalStore.ValuesBucket = {
  "NAME": value1,
  "AGE": value2,
  "SALARY": value3,
  "CODES": value4,
};

let predicates = new relationalStore.RdbPredicates("EMPLOYEE");
predicates.equalTo("NAME", "Lisa");
if(store != undefined) {
  (store as relationalStore.RdbStore).update(valueBucket1, predicates, relationalStore.ConflictResolution.ON_CONFLICT_REPLACE, (err, rows) => {
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

Updates data based on the specified **RdbPredicates** object. This API uses a promise to return the result. Due to the limit of the shared memory (max. 2 MB), a single data record cannot exceed 2 MB. Otherwise, the query operation will fail.

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

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [RDB Store Error Codes](errorcode-data-rdb.md). For details about how to handle error 14800011, see [Database Backup and Restore](../../database/data-backup-and-restore.md).

| **ID**| **Error Message**                                                |
|-----------| ------------------------------------------------------------ |
| 401       | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 14800000  | Inner error. |
| 14800011  | Database corrupted. |
| 14800014  | Already closed. |
| 14800015  | The database does not respond. |
| 14800021  | SQLite: Generic error. |
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
import { BusinessError } from '@kit.BasicServicesKit';

let value1 = "Rose";
let value2 = 22;
let value3 = 200.5;
let value4 = new Uint8Array([1, 2, 3, 4, 5]);

// You can use either of the following:
const valueBucket1: relationalStore.ValuesBucket = {
  'NAME': value1,
  'AGE': value2,
  'SALARY': value3,
  'CODES': value4,
};
const valueBucket2: relationalStore.ValuesBucket = {
  NAME: value1,
  AGE: value2,
  SALARY: value3,
  CODES: value4,
};
const valueBucket3: relationalStore.ValuesBucket = {
  "NAME": value1,
  "AGE": value2,
  "SALARY": value3,
  "CODES": value4,
};

let predicates = new relationalStore.RdbPredicates("EMPLOYEE");
predicates.equalTo("NAME", "Lisa");
if(store != undefined) {
  (store as relationalStore.RdbStore).update(valueBucket1, predicates).then(async (rows: Number) => {
    console.info(`Updated row count: ${rows}`);
  }).catch((err: BusinessError) => {
    console.error(`Updated failed, code is ${err.code},message is ${err.message}`);
  })
}
```

### update<sup>10+</sup>

update(values: ValuesBucket, predicates: RdbPredicates, conflict: ConflictResolution):Promise&lt;number&gt;

Updates data based on the specified **RdbPredicates** object. This API uses a promise to return the result. Due to the limit of the shared memory (max. 2 MB), a single data record cannot exceed 2 MB. Otherwise, the query operation will fail.

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

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [RDB Store Error Codes](errorcode-data-rdb.md). For details about how to handle error 14800011, see [Database Backup and Restore](../../database/data-backup-and-restore.md).

| **ID**| **Error Message**                                                |
|-----------| ------------------------------------------------------------ |
| 401       | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 14800000  | Inner error. |
| 14800011  | Database corrupted. |
| 14800014  | Already closed. |
| 14800015  | The database does not respond. |
| 14800021  | SQLite: Generic error. |
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
import { BusinessError } from '@kit.BasicServicesKit';

let value1 = "Rose";
let value2 = 22;
let value3 = 200.5;
let value4 = new Uint8Array([1, 2, 3, 4, 5]);

// You can use either of the following:
const valueBucket1: relationalStore.ValuesBucket = {
  'NAME': value1,
  'AGE': value2,
  'SALARY': value3,
  'CODES': value4,
};
const valueBucket2: relationalStore.ValuesBucket = {
  NAME: value1,
  AGE: value2,
  SALARY: value3,
  CODES: value4,
};
const valueBucket3: relationalStore.ValuesBucket = {
  "NAME": value1,
  "AGE": value2,
  "SALARY": value3,
  "CODES": value4,
};

let predicates = new relationalStore.RdbPredicates("EMPLOYEE");
predicates.equalTo("NAME", "Lisa");
if(store != undefined) {
  (store as relationalStore.RdbStore).update(valueBucket1, predicates, relationalStore.ConflictResolution.ON_CONFLICT_REPLACE).then(async (rows: Number) => {
    console.info(`Updated row count: ${rows}`);
  }).catch((err: BusinessError) => {
    console.error(`Updated failed, code is ${err.code},message is ${err.message}`);
  })
}
```

### updateSync<sup>12+</sup>

updateSync(values: ValuesBucket, predicates: RdbPredicates, conflict?: ConflictResolution):number

Updates data in the RDB store based on the specified **RdbPredicates** instance. Due to the limit of the shared memory (max. 2 MB), a single data record cannot exceed 2 MB. Otherwise, the query operation will fail.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Parameters**

| Name    | Type                                       | Mandatory| Description                                                        |
| ---------- | ------------------------------------------- | ---- | ------------------------------------------------------------ |
| values     | [ValuesBucket](#valuesbucket)               | Yes  | Rows of data to update in the RDB store. The key-value pair is associated with the column name in the target table.|
| predicates | [RdbPredicates](#rdbpredicates)             | Yes  | Update conditions specified by the **RdbPredicates** object.                     |
| conflict   | [ConflictResolution](#conflictresolution10) | No  | Resolution used to resolve the conflict. The default value is **relationalStore.ConflictResolution.ON_CONFLICT_NONE**.|

**Return value**

| Type  | Description              |
| ------ | ------------------ |
| number | return the number of rows updated.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [RDB Store Error Codes](errorcode-data-rdb.md). For details about how to handle error 14800011, see [Database Backup and Restore](../../database/data-backup-and-restore.md).

| **ID**| **Error Message**                                                |
| ------------ | ------------------------------------------------------------ |
| 401          | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 14800000     | Inner error.                                                 |
| 14800011     | Database corrupted.                                          |
| 14800014     | Already closed.                                              |
| 14800015     | The database does not respond.                                        |
| 14800021     | SQLite: Generic error.                                       |
| 14800022     | SQLite: Callback routine requested an abort.                 |
| 14800023     | SQLite: Access permission denied.                            |
| 14800024     | SQLite: The database file is locked.                         |
| 14800025     | SQLite: A table in the database is locked.                   |
| 14800026     | SQLite: The database is out of memory.                       |
| 14800027     | SQLite: Attempt to write a readonly database.                |
| 14800028     | SQLite: Some kind of disk I/O error occurred.                |
| 14800029     | SQLite: The database is full.                                |
| 14800030     | SQLite: Unable to open the database file.                    |
| 14800031     | SQLite: TEXT or BLOB exceeds size limit.                     |
| 14800032     | SQLite: Abort due to constraint violation.                   |
| 14800033     | SQLite: Data type mismatch.                                  |
| 14800034     | SQLite: Library used incorrectly.                            |
| 14800047     | The WAL file size exceeds the default limit.                 |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let value1 = "Rose";
let value2 = 22;
let value3 = 200.5;
let value4 = new Uint8Array([1, 2, 3, 4, 5]);

// You can use either of the following:
const valueBucket1: relationalStore.ValuesBucket = {
  'NAME': value1,
  'AGE': value2,
  'SALARY': value3,
  'CODES': value4,
};
const valueBucket2: relationalStore.ValuesBucket = {
  NAME: value1,
  AGE: value2,
  SALARY: value3,
  CODES: value4,
};
const valueBucket3: relationalStore.ValuesBucket = {
  "NAME": value1,
  "AGE": value2,
  "SALARY": value3,
  "CODES": value4,
};

let predicates = new relationalStore.RdbPredicates("EMPLOYEE");
predicates.equalTo("NAME", "Lisa");
if(store != undefined) {
  try {
    let rows: Number = (store as relationalStore.RdbStore).updateSync(valueBucket1, predicates, relationalStore.ConflictResolution.ON_CONFLICT_REPLACE);
    console.info(`Updated row count: ${rows}`);
  } catch (error) {
    console.error(`Updated failed, code is ${error.code},message is ${error.message}`);
  }
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
| callback   | AsyncCallback&lt;number&gt;          | Yes  | Callback used to return the number of rows deleted. |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [RDB Store Error Codes](errorcode-data-rdb.md). For details about how to handle error 14800011, see [Database Backup and Restore](../../database/data-backup-and-restore.md).

| **ID**| **Error Message**                                                |
|-----------| ------------------------------------------------------------ |
| 401       | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 14800000  | Inner error. |
| 14800011  | Database corrupted. |
| 14800014  | Already closed. |
| 14800015  | The database does not respond. |
| 14800021  | SQLite: Generic error. |
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

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [RDB Store Error Codes](errorcode-data-rdb.md). For details about how to handle error 14800011, see [Database Backup and Restore](../../database/data-backup-and-restore.md).

| **ID**| **Error Message**                                                |
|-----------| ------------------------------------------------------------ |
| 401       | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 14800000  | Inner error. |
| 14800011  | Database corrupted. |
| 14800014  | Already closed. |
| 14800015  | The database does not respond. |
| 14800021  | SQLite: Generic error. |
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
import { BusinessError } from '@kit.BasicServicesKit';

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

### deleteSync<sup>12+</sup>

deleteSync(predicates: RdbPredicates):number

Deletes data from the RDB store based on the specified **RdbPredicates** object.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Parameters**

| Name    | Type                           | Mandatory| Description                                   |
| ---------- | ------------------------------- | ---- | --------------------------------------- |
| predicates | [RdbPredicates](#rdbpredicates) | Yes  | Conditions specified by the **RdbPredicates** object for deleting data.|

**Return value**

| Type  | Description              |
| ------ | ------------------ |
| number | return the number of rows updated.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [RDB Store Error Codes](errorcode-data-rdb.md). For details about how to handle error 14800011, see [Database Backup and Restore](../../database/data-backup-and-restore.md).

| **ID**| **Error Message**                                                |
| ------------ | ------------------------------------------------------------ |
| 401          | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 14800000     | Inner error.                                                 |
| 14800011     | Database corrupted.                                          |
| 14800014     | Already closed.                                              |
| 14800015     | The database does not respond.                                        |
| 14800021     | SQLite: Generic error.                                       |
| 14800022     | SQLite: Callback routine requested an abort.                 |
| 14800023     | SQLite: Access permission denied.                            |
| 14800024     | SQLite: The database file is locked.                         |
| 14800025     | SQLite: A table in the database is locked.                   |
| 14800026     | SQLite: The database is out of memory.                       |
| 14800027     | SQLite: Attempt to write a readonly database.                |
| 14800028     | SQLite: Some kind of disk I/O error occurred.                |
| 14800029     | SQLite: The database is full.                                |
| 14800030     | SQLite: Unable to open the database file.                    |
| 14800031     | SQLite: TEXT or BLOB exceeds size limit.                     |
| 14800032     | SQLite: Abort due to constraint violation.                   |
| 14800033     | SQLite: Data type mismatch.                                  |
| 14800034     | SQLite: Library used incorrectly.                            |
| 14800047     | The WAL file size exceeds the default limit.                 |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let predicates = new relationalStore.RdbPredicates("EMPLOYEE");
predicates.equalTo("NAME", "Lisa");
if(store != undefined) {
  try {
    let rows: Number = (store as relationalStore.RdbStore).deleteSync(predicates)
    console.info(`Delete rows: ${rows}`);
  } catch (err) {
    console.error(`Delete failed, code is ${err.code},message is ${err.message}`);
  }
}
```

### query<sup>10+</sup>

query(predicates: RdbPredicates, callback: AsyncCallback&lt;ResultSet&gt;):void

Queries data from the RDB store based on specified conditions. This API uses an asynchronous callback to return the result. Due to the limit of the shared memory (max. 2 MB), a single data record cannot exceed 2 MB. Otherwise, the query operation will fail.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Parameters**

| Name    | Type                                                        | Mandatory| Description                                                       |
| ---------- | ------------------------------------------------------------ | ---- | ----------------------------------------------------------- |
| predicates | [RdbPredicates](#rdbpredicates)                         | Yes  | Query conditions specified by the **RdbPredicates** object.                  |
| callback   | AsyncCallback&lt;[ResultSet](#resultset)&gt; | Yes  | Callback used to return the result. If the operation is successful, a **ResultSet** object will be returned.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [RDB Store Error Codes](errorcode-data-rdb.md).

| **ID**| **Error Message**                                                |
|-----------| ------------------------------------------------------------ |
| 401       | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 14800000  | Inner error. |
| 14800014  | Already closed. |
| 14800015  | The database does not respond. |

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
    // Release the memory of resultSet. If the memory is not released, FD or memory leaks may occur.
    resultSet.close();
  })
}
```

### query

query(predicates: RdbPredicates, columns: Array&lt;string&gt;, callback: AsyncCallback&lt;ResultSet&gt;):void

Queries data from the RDB store based on specified conditions. This API uses an asynchronous callback to return the result. Due to the limit of the shared memory (max. 2 MB), a single data record cannot exceed 2 MB. Otherwise, the query operation will fail.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Parameters**

| Name    | Type                                                        | Mandatory| Description                                                       |
| ---------- | ------------------------------------------------------------ | ---- | ----------------------------------------------------------- |
| predicates | [RdbPredicates](#rdbpredicates)                         | Yes  | Query conditions specified by the **RdbPredicates** object.                  |
| columns    | Array&lt;string&gt;                                          | Yes  | Columns to query. If this parameter is not specified, the query applies to all columns.           |
| callback   | AsyncCallback&lt;[ResultSet](#resultset)&gt; | Yes  | Callback used to return the result. If the operation is successful, a **ResultSet** object will be returned.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [RDB Store Error Codes](errorcode-data-rdb.md).

| **ID**| **Error Message**                                                |
|-----------| ------------------------------------------------------------ |
| 401       | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 14800000  | Inner error. |
| 14800014  | Already closed. |
| 14800015  | The database does not respond. |

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
    // Release the memory of resultSet. If the memory is not released, FD or memory leaks may occur.
    resultSet.close();
  })
}
```

### query

query(predicates: RdbPredicates, columns?: Array&lt;string&gt;):Promise&lt;ResultSet&gt;

Queries data from the RDB store based on specified conditions. This API uses a promise to return the result. Due to the limit of the shared memory (max. 2 MB), a single data record cannot exceed 2 MB. Otherwise, the query operation will fail.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Parameters**

| Name    | Type                                | Mandatory| Description                                            |
| ---------- | ------------------------------------ | ---- | ------------------------------------------------ |
| predicates | [RdbPredicates](#rdbpredicates) | Yes  | Query conditions specified by the **RdbPredicates** object.       |
| columns    | Array&lt;string&gt;                  | No  | Columns to query. If this parameter is not specified, the query applies to all columns.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [RDB Store Error Codes](errorcode-data-rdb.md).

| **ID**| **Error Message**                                                |
|-----------| ------------------------------------------------------------ |
| 401       | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 14800000  | Inner error. |
| 14800014  | Already closed. |
| 14800015  | The database does not respond. |

**Return value**

| Type                                                   | Description                                              |
| ------------------------------------------------------- | -------------------------------------------------- |
| Promise&lt;[ResultSet](#resultset)&gt; | Promise used to return the result. If the operation is successful, a **ResultSet** object will be returned.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

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
    // Release the memory of resultSet. If the memory is not released, FD or memory leaks may occur.
    resultSet.close();
  }).catch((err: BusinessError) => {
    console.error(`Query failed, code is ${err.code},message is ${err.message}`);
  })
}
```

### querySync<sup>12+</sup>

querySync(predicates: RdbPredicates, columns?: Array&lt;string&gt;):ResultSet

Queries data in the RDB store based on specified conditions. This API returns the result synchronously. If complex logic and a large number of loops are involved in the operations on the **resultSet** obtained by **querySync()**, the freeze problem may occur. You are advised to perform this operation in the [taskpool](../apis-arkts/js-apis-taskpool.md) thread.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Parameters**

| Name    | Type                           | Mandatory| Description                                                        |
| ---------- | ------------------------------- | ---- | ------------------------------------------------------------ |
| predicates | [RdbPredicates](#rdbpredicates) | Yes  | Query conditions specified by the **RdbPredicates** object.                     |
| columns    | Array&lt;string&gt;             | No  | Columns to query. If this parameter is not specified, the query applies to all columns. The default value is null.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [RDB Store Error Codes](errorcode-data-rdb.md).

| **ID**| **Error Message**                                                |
| ------------ | ------------------------------------------------------------ |
| 401          | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 14800000     | Inner error.                                                 |
| 14800014     | Already closed.                                              |
| 14800015     | The database does not respond.                                        |

**Return value**

| Type                   | Description                               |
| ----------------------- | ----------------------------------- |
| [ResultSet](#resultset) | If the operation is successful, a **ResultSet** object will be returned.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let predicates = new relationalStore.RdbPredicates("EMPLOYEE");
predicates.equalTo("NAME", "Rose");
if(store != undefined) {
  try {
    let resultSet: relationalStore.ResultSet = (store as relationalStore.RdbStore).querySync(predicates, ["ID", "NAME", "AGE", "SALARY", "CODES"]);
    console.info(`ResultSet column names: ${resultSet.columnNames}, column count: ${resultSet.columnCount}`);
    // resultSet is a cursor of a data set. By default, the cursor points to the -1st record. Valid data starts from 0.
    while (resultSet.goToNextRow()) {
      const id = resultSet.getLong(resultSet.getColumnIndex("ID"));
      const name = resultSet.getString(resultSet.getColumnIndex("NAME"));
      const age = resultSet.getLong(resultSet.getColumnIndex("AGE"));
      const salary = resultSet.getDouble(resultSet.getColumnIndex("SALARY"));
      console.info(`id=${id}, name=${name}, age=${age}, salary=${salary}`);
    }
    // Release the memory of resultSet. If the memory is not released, FD or memory leaks may occur.
    resultSet.close();
  } catch (err) {
    console.error(`Query failed, code is ${err.code},message is ${err.message}`);
  }
}
```

### remoteQuery

remoteQuery(device: string, table: string, predicates: RdbPredicates, columns: Array&lt;string&gt; , callback: AsyncCallback&lt;ResultSet&gt;): void

Queries data from the RDB store of a remote device based on specified conditions. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> **device** can be obtained by [deviceManager.getAvailableDeviceListSync](../apis-distributedservice-kit/js-apis-distributedDeviceManager.md#getavailabledevicelistsync).

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Parameters**

| Name    | Type                                        | Mandatory| Description                                                     |
| ---------- | -------------------------------------------- | ---- | --------------------------------------------------------- |
| device     | string                                       | Yes  | ID of the remote device.                                       |
| table      | string                                       | Yes  | Name of the target table.                                         |
| predicates | [RdbPredicates](#rdbpredicates)              | Yes  | Query conditions specified by the **RdbPredicates** object.                |
| columns    | Array&lt;string&gt;                          | Yes  | Columns to query. If this parameter is not specified, the query applies to all columns.         |
| callback   | AsyncCallback&lt;[ResultSet](#resultset)&gt; | Yes  | Callback used to return the result. If the operation is successful, a **ResultSet** object will be returned.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [RDB Store Error Codes](errorcode-data-rdb.md).

| **ID**| **Error Message**                                                |
|-----------| ------------------------------------------------------------ |
| 401       | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 801       | Capability not supported. |
| 14800000  | Inner error. |
| 14800014  | Already closed. |

**Example**

```ts
import { distributedDeviceManager } from '@kit.DistributedServiceKit';
import { BusinessError } from '@kit.BasicServicesKit';

let dmInstance: distributedDeviceManager.DeviceManager;
let deviceId: string | undefined = undefined;

try {
  dmInstance = distributedDeviceManager.createDeviceManager("com.example.appdatamgrverify");
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
    // Release the memory of resultSet. If the memory is not released, FD or memory leaks may occur.
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
> **device** can be obtained by [deviceManager.getAvailableDeviceListSync](../apis-distributedservice-kit/js-apis-distributedDeviceManager.md#getavailabledevicelistsync).

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

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [RDB Store Error Codes](errorcode-data-rdb.md).

| **ID**| **Error Message**                                                |
|-----------| ------------------------------------------------------------ |
| 401       | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 801       | Capability not supported. |
| 14800000  | Inner error. |
| 14800014  | Already closed. |

**Example**

```ts
import { distributedDeviceManager } from '@kit.DistributedServiceKit';
import { BusinessError } from '@kit.BasicServicesKit';

let dmInstance: distributedDeviceManager.DeviceManager;
let deviceId: string | undefined = undefined;

try {
  dmInstance = distributedDeviceManager.createDeviceManager("com.example.appdatamgrverify");
  let devices: Array<distributedDeviceManager.DeviceBasicInfo> = dmInstance.getAvailableDeviceListSync();
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
    // Release the memory of resultSet. If the memory is not released, FD or memory leaks may occur.
    resultSet.close();
  }).catch((err: BusinessError) => {
    console.error(`Failed to remoteQuery, code is ${err.code},message is ${err.message}`);
  })
}
```

### querySql<sup>10+</sup>

querySql(sql: string, callback: AsyncCallback&lt;ResultSet&gt;):void

Queries data in the RDB store using the specified SQL statement. The number of relational operators between expressions and operators in the SQL statement cannot exceed 1000. This API uses an asynchronous callback to return the result.

[vector stores](#storeconfig) support standard syntax like **where**, **limit**, **offset**, **order by**, **group by**, and **having**, and special syntax **<->** and **<=>**, which are used to calculate vector similarity and cosine distance, respectively.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Parameters**

| Name  | Type                                        | Mandatory| Description                                   |
| -------- | -------------------------------------------- | ---- |---------------------------------------|
| sql      | string                                       | Yes  | SQL statement to run.                         |
| callback | AsyncCallback&lt;[ResultSet](#resultset)&gt; | Yes  | Callback used to return the result. If the operation is successful, a **ResultSet** object will be returned.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [RDB Store Error Codes](errorcode-data-rdb.md).

| **ID**| **Error Message**                                                |
|-----------| ------------------------------------------------------------ |
| 401       | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 14800000  | Inner error. |
| 14800014  | Already closed. |
| 14800015  | The database does not respond. |

**Example**

RDB store:

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
    // Release the memory of resultSet. If the memory is not released, FD or memory leaks may occur.
    resultSet.close();
  })
}
```

Vector store:

```ts
// <-> means to calculate vector similarity, and <=> means to calculate the cosine distance.
const querySql = "select id, repr <-> '[1.5,5.6]' as distance from test ORDER BY repr <-> '[1.5,5.6]' limit 10 offset 1;";
let resultSet = await store.querySql(querySql);

// Aggregate query. GROUP BY supports multiple columns.
const querySql1 = "select id, repr from test group by id, repr having max(repr<=>[1.5,5.6]);";
let resultSet1 = await store.querySql(querySql1);

// Subquery. A maximum of 32 nested layers are supported.
const querySql2 = "select * from test where id in (select id from test1)";
let resultSet2 = await store.querySql(querySql2);
```

### querySql

querySql(sql: string, bindArgs: Array&lt;ValueType&gt;, callback: AsyncCallback&lt;ResultSet&gt;):void

Queries data in the RDB store using the specified SQL statement. The number of relational operators between expressions and operators in the SQL statement cannot exceed 1000. This API uses an asynchronous callback to return the result.

[vector stores](#storeconfig) support standard syntax like **where**, **limit**, **offset**, **order by**, **group by**, and **having**, and special syntax **<->** and **<=>**, which are used to calculate vector similarity and cosine distance, respectively.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Parameters**

| Name  | Type                                        | Mandatory| Description                                                        |
| -------- | -------------------------------------------- | ---- | ------------------------------------------------------------ |
| sql      | string                                       | Yes  | SQL statement to run.                                       |
| bindArgs | Array&lt;[ValueType](#valuetype)&gt;         | Yes  | Arguments in the SQL statement. The value corresponds to the placeholders in the SQL parameter statement. If the SQL parameter statement is complete, the value of this parameter must be an empty array.|
| callback | AsyncCallback&lt;[ResultSet](#resultset)&gt; | Yes  | Callback used to return the result. If the operation is successful, a **ResultSet** object will be returned.   |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [RDB Store Error Codes](errorcode-data-rdb.md).

| **ID**| **Error Message**                                                |
|-----------| ------------------------------------------------------------ |
| 401       | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 14800000  | Inner error. |
| 14800014  | Already closed. |
| 14800015  | The database does not respond. |

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
    // Release the memory of resultSet. If the memory is not released, FD or memory leaks may occur.
    resultSet.close();
  })
}
```

### querySql

querySql(sql: string, bindArgs?: Array&lt;ValueType&gt;):Promise&lt;ResultSet&gt;

Queries data in the RDB store using the specified SQL statement. The number of relational operators between expressions and operators in the SQL statement cannot exceed 1000. This API uses a promise to return the result.

[vector stores](#storeconfig) support standard syntax like **where**, **limit**, **offset**, **order by**, **group by**, and **having**, and special syntax **<->** and **<=>**, which are used to calculate vector similarity and cosine distance, respectively.

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

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [RDB Store Error Codes](errorcode-data-rdb.md).

| **ID**| **Error Message**                                                |
|-----------| ------------------------------------------------------------ |
| 401       | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 14800000  | Inner error. |
| 14800014  | Already closed. |
| 14800015  | The database does not respond. |

**Example**

RDB store:

```ts
import { BusinessError } from '@kit.BasicServicesKit';

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
    // Release the memory of resultSet. If the memory is not released, FD or memory leaks may occur.
    resultSet.close();
  }).catch((err: BusinessError) => {
    console.error(`Query failed, code is ${err.code},message is ${err.message}`);
  })
}
```

Vector store:

```ts
// Query the top 10 records with ID of 1 and the similarity to [1.5, 2.5] is less than 0.5, and sort them in ascending order by similarity.
const querySql = "select id, repr <-> ? as distance from test where id = ? and repr <-> ? < 0.5 ORDER BY repr <-> ? limit 10;";
const vectorValue: Float32Array = new Float32Array([1.5, 2.5]);
let resultSet = await store.querySql(querySql, [vectorValue, 1, vectorValue, vectorValue]); 
```

### querySqlSync<sup>12+</sup>

querySqlSync(sql: string, bindArgs?: Array&lt;ValueType&gt;):ResultSet

Queries data in the RDB store using the specified SQL statement. The number of relational operators between expressions and operators in the SQL statement cannot exceed 1000. If complex logic and a large number of loops are involved in the operations on the **resultSet** obtained by **querySync()**, the freeze problem may occur. You are advised to perform this operation in the [taskpool](../apis-arkts/js-apis-taskpool.md) thread.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Parameters**

| Name  | Type                                | Mandatory| Description                                                        |
| -------- | ------------------------------------ | ---- | ------------------------------------------------------------ |
| sql      | string                               | Yes  | SQL statement to run.                                       |
| bindArgs | Array&lt;[ValueType](#valuetype)&gt; | No  | Arguments in the SQL statement. The value corresponds to the placeholders in the SQL parameter statement. If the SQL parameter statement is complete, leave this parameter blank. The default value is null.|

**Return value**

| Type                   | Description                               |
| ----------------------- | ----------------------------------- |
| [ResultSet](#resultset) | If the operation is successful, a **ResultSet** object will be returned.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [RDB Store Error Codes](errorcode-data-rdb.md).

| **ID**| **Error Message**                                                |
| ------------ | ------------------------------------------------------------ |
| 401          | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 14800000     | Inner error.                                                 |
| 14800014     | Already closed.                                              |
| 14800015     | The database does not respond.                                        |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

if(store != undefined) {
  try {
    let resultSet: relationalStore.ResultSet = (store as relationalStore.RdbStore).querySqlSync("SELECT * FROM EMPLOYEE CROSS JOIN BOOK WHERE BOOK.NAME = 'sanguo'");
    console.info(`ResultSet column names: ${resultSet.columnNames}, column count: ${resultSet.columnCount}`);
    // resultSet is a cursor of a data set. By default, the cursor points to the -1st record. Valid data starts from 0.
    while (resultSet.goToNextRow()) {
      const id = resultSet.getLong(resultSet.getColumnIndex("ID"));
      const name = resultSet.getString(resultSet.getColumnIndex("NAME"));
      const age = resultSet.getLong(resultSet.getColumnIndex("AGE"));
      const salary = resultSet.getDouble(resultSet.getColumnIndex("SALARY"));
      console.info(`id=${id}, name=${name}, age=${age}, salary=${salary}`);
    }
    // Release the memory of resultSet. If the memory is not released, FD or memory leaks may occur.
    resultSet.close();
  } catch (err) {
    console.error(`Query failed, code is ${err.code},message is ${err.message}`);
  }
}
```

### executeSql<sup>10+</sup>

executeSql(sql: string, callback: AsyncCallback&lt;void&gt;):void

Executes an SQL statement that contains specified arguments but returns no value. The number of relational operators between expressions and operators in the statement cannot exceed 1000. This API uses an asynchronous callback to return the result.

This API does not support query, attach, or transaction operations. To perform these operations, use [querySql](#querysql10), [query](#query10), [attach](#attach12), [beginTransaction](#begintransaction), and [commit](#commit).

Statements separated by semicolons (\;) are not supported.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Parameters**

| Name  | Type                                | Mandatory| Description                                                        |
| -------- | ------------------------------------ | ---- | ------------------------------------------------------------ |
| sql      | string                               | Yes  | SQL statement to run.                                       |
| callback | AsyncCallback&lt;void&gt;            | Yes  | Callback used to return the result.                                      |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [RDB Store Error Codes](errorcode-data-rdb.md). For details about how to handle error 14800011, see [Database Backup and Restore](../../database/data-backup-and-restore.md).

| **ID**| **Error Message**                                                |
|-----------| ------------------------------------------------------------ |
| 401       | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 801       | Capability not supported the sql(attach,begin,commit,rollback etc.). |
| 14800000  | Inner error. |
| 14800011  | Database corrupted. |
| 14800014  | Already closed. |
| 14800015  | The database does not respond. |
| 14800021  | SQLite: Generic error. |
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

Executes an SQL statement that contains specified arguments but returns no value. The number of relational operators between expressions and operators in the statement cannot exceed 1000. This API uses an asynchronous callback to return the result.

This API does not support query, attach, or transaction operations. To perform these operations, use [querySql](#querysql10), [query](#query10), [attach](#attach12), [beginTransaction](#begintransaction), and [commit](#commit).

Statements separated by semicolons (\;) are not supported.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Parameters**

| Name  | Type                                | Mandatory| Description                                                        |
| -------- | ------------------------------------ | ---- | ------------------------------------------------------------ |
| sql      | string                               | Yes  | SQL statement to run.                                       |
| bindArgs | Array&lt;[ValueType](#valuetype)&gt; | Yes  | Arguments in the SQL statement. The value corresponds to the placeholders in the SQL parameter statement. If the SQL parameter statement is complete, the value of this parameter must be an empty array.|
| callback | AsyncCallback&lt;void&gt;            | Yes  | Callback used to return the result.                                      |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [RDB Store Error Codes](errorcode-data-rdb.md). For details about how to handle error 14800011, see [Database Backup and Restore](../../database/data-backup-and-restore.md).

| **ID**| **Error Message**                                                |
|-----------| ------------------------------------------------------------ |
| 401       | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 801       | Capability not supported the sql(attach,begin,commit,rollback etc.). |
| 14800000  | Inner error. |
| 14800011  | Database corrupted. |
| 14800014  | Already closed. |
| 14800015  | The database does not respond. |
| 14800021  | SQLite: Generic error. |
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

Executes an SQL statement that contains specified arguments but returns no value. The number of relational operators between expressions and operators in the statement cannot exceed 1000. This API uses a promise to return the result.

This API does not support query, attach, or transaction operations. To perform these operations, use [querySql](#querysql10), [query](#query10), [attach](#attach12), [beginTransaction](#begintransaction), and [commit](#commit).

Statements separated by semicolons (\;) are not supported.

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

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [RDB Store Error Codes](errorcode-data-rdb.md). For details about how to handle error 14800011, see [Database Backup and Restore](../../database/data-backup-and-restore.md).

| **ID**| **Error Message**                                                |
|-----------| ------------------------------------------------------------ |
| 401       | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 801       | Capability not supported the sql(attach,begin,commit,rollback etc.). |
| 14800000  | Inner error. |
| 14800011  | Database corrupted. |
| 14800014  | Already closed. |
| 14800015  | The database does not respond. |
| 14800021  | SQLite: Generic error. |
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
import { BusinessError } from '@kit.BasicServicesKit';

const SQL_DELETE_TABLE = "DELETE FROM test WHERE name = 'zhangsan'"
if(store != undefined) {
  (store as relationalStore.RdbStore).executeSql(SQL_DELETE_TABLE).then(() => {
    console.info('Delete table done.');
  }).catch((err: BusinessError) => {
    console.error(`ExecuteSql failed, code is ${err.code},message is ${err.message}`);
  })
}
```

### execute<sup>12+</sup>

execute(sql: string, args?: Array&lt;ValueType&gt;):Promise&lt;ValueType&gt;

Executes an SQL statement that contains specified arguments. The number of relational operators between expressions and operators in the statement cannot exceed 1000. This API uses a promise to return a value of the ValueType type.

This API can be used to add, delete, and modify data, run SQL statements of the PRAGMA syntax, and create, delete, and modify a table. The type of the return value varies, depending on the execution result.

This API does not support query, attach, or transaction operations. To perform these operations, use [querySql](#querysql10), [query](#query10), [attach](#attach12), [beginTransaction](#begintransaction), and [commit](#commit).

Statements separated by semicolons (\;) are not supported.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Parameters**

| Name  | Type                                | Mandatory| Description                                                        |
| -------- | ------------------------------------ | ---- | ------------------------------------------------------------ |
| sql      | string                               | Yes  | SQL statement to run.                                       |
| args | Array&lt;[ValueType](#valuetype)&gt; | No  | Arguments in the SQL statement. The value corresponds to the placeholders in the SQL parameter statement. If the SQL parameter statement is complete, leave this parameter blank.|

**Return value**

| Type               | Description                     |
| ------------------- | ------------------------- |
| Promise&lt;[ValueType](#valuetype)&gt; | Promise used to return the SQL execution result.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [RDB Store Error Codes](errorcode-data-rdb.md). For details about how to handle error 14800011, see [Database Backup and Restore](../../database/data-backup-and-restore.md).

| **ID**| **Error Message**                                                |
|-----------| ------------------------------------------------------------ |
| 401       | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 801       | Capability not supported the sql(attach,begin,commit,rollback etc.). |
| 14800000  | Inner error. |
| 14800011  | Database corrupted. |
| 14800014  | Already closed. |
| 14800015  | The database does not respond. |
| 14800021  | SQLite: Generic error. |
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

RDB store:

```ts
import { BusinessError } from '@kit.BasicServicesKit';

// Check the RDB store integrity.
if(store != undefined) {
  const SQL_CHECK_INTEGRITY = 'PRAGMA integrity_check';
  (store as relationalStore.RdbStore).execute(SQL_CHECK_INTEGRITY).then((data) => {
    console.info(`check result: ${data}`);
  }).catch((err: BusinessError) => {
    console.error(`check failed, code is ${err.code}, message is ${err.message}`);
  })
}

// Delete all data from the table.
if(store != undefined) {
  const SQL_DELETE_TABLE = 'DELETE FROM test';
  (store as relationalStore.RdbStore).execute(SQL_DELETE_TABLE).then((data) => {
    console.info(`delete result: ${data}`);
  }).catch((err: BusinessError) => {
    console.error(`delete failed, code is ${err.code}, message is ${err.message}`);
  })
}

// Delete a table.
if(store != undefined) {
  const SQL_DROP_TABLE = 'DROP TABLE test';
  (store as relationalStore.RdbStore).execute(SQL_DROP_TABLE).then((data) => {
    console.info(`drop result: ${data}`);
  }).catch((err: BusinessError) => {
    console.error(`drop failed, code is ${err.code}, message is ${err.message}`);
  })
}
```

Vector store:

```ts
// FLOATVECTOR(2) is a vector property with a dimension of 2. The subsequent repr operation should be performed based on this dimension.
let createSql = "CREATE TABLE test (ID text PRIMARY KEY,REPR FLOATVECTOR(2));";
// Create a table.
await store!.execute(createSql);
// Insert data using parameter binding.
let insertSql= "insert into test VALUES(?, ?);";
const vectorValue: Float32Array = Float32Array.from([1.5, 6.6]);
await store!.execute(insertSql, [0, vectorValue]); 
// Execute without using bound parameters.
await store!.execute("insert into test values(1, '[3.5, 1.8]');");
```

### execute<sup>12+</sup>

execute(sql: string, txId: number, args?: Array&lt;ValueType&gt;): Promise&lt;ValueType&gt;

Executes an SQL statement that contains specified arguments. The number of relational operators between expressions and operators in the statement cannot exceed 1000. This API uses a promise to return the result.

This API supports only [vector stores](#storeconfig).

This API does not support data query. To query data, use [querySql](#querysql10).

Statements separated by semicolons (\;) are not supported.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Parameters**

| Name  | Type                                | Mandatory| Description                                                        |
| -------- | ------------------------------------ | ---- | ------------------------------------------------------------ |
| sql      | string                               | Yes  | SQL statement to run.                                       |
| txId      | number                               | Yes  | Transaction ID obtained via [beginTrans](#begintrans12). If the value is **0**, the SQL statement is executed in a separate transaction by default.                                     |
| args | Array&lt;[ValueType](#valuetype)&gt; | No  | Arguments in the SQL statement. The value corresponds to the placeholders in the SQL parameter statement. If this parameter is left blank or set to **null** or **undefined**, the SQL statement is complete.|

**Return value**

| Type               | Description                     |
| ------------------- | ------------------------- |
| Promise&lt;[ValueType](#valuetype)&gt; | Promise that returns **null**.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [RDB Store Error Codes](errorcode-data-rdb.md). For details about how to handle error 14800011, see [Database Backup and Restore](../../database/data-backup-and-restore.md).

| **ID**| **Error Message**                                                |
|-----------| ------------------------------------------------------------ |
| 401       | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 801       | Capability not supported the sql(attach,begin,commit,rollback etc.). |
| 14800000  | Inner error. |
| 14800011  | Database corrupted. |
| 14800014  | Already closed. |
| 14800015  | The database does not respond. |
| 14800021  | SQLite: Generic error. |
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
import { BusinessError } from '@kit.BasicServicesKit';
if(store != null) {
  let txId : number;
  (store as relationalStore.RdbStore).beginTrans().then((txId : number) => {
    (store as relationalStore.RdbStore).execute("DELETE FROM TEST WHERE age = ? OR age = ?", txId, ["18", "20"])
      .then(() => {
        (store as relationalStore.RdbStore).commit(txId);
    })
    .catch((err: BusinessError) => {
      (store as relationalStore.RdbStore).rollback(txId)
      console.error(`execute sql failed, code is ${err.code},message is ${err.message}`);
    });
  });
}
```

### executeSync<sup>12+</sup>

executeSync(sql: string, args?: Array&lt;ValueType&gt;): ValueType

Executes an SQL statement that contains specified arguments. The number of relational operators between expressions and operators in the statement cannot exceed 1000. This API returns a value of theValueType type.

This API can be used to add, delete, and modify data, run SQL statements of the PRAGMA syntax, and create, delete, and modify a table. The type of the return value varies, depending on the execution result.

This API does not support query, attach, or transaction operations. To perform these operations, use [querySql](#querysql10), [query](#query10), [attach](#attach12), [beginTransaction](#begintransaction), and [commit](#commit).

Statements separated by semicolons (\;) are not supported.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Parameters**

| Name| Type                                | Mandatory| Description                                                        |
| ------ | ------------------------------------ | ---- | ------------------------------------------------------------ |
| sql    | string                               | Yes  | SQL statement to run.                                       |
| args   | Array&lt;[ValueType](#valuetype)&gt; | No  | Arguments in the SQL statement. The value corresponds to the placeholders in the SQL parameter statement. If this parameter is left blank or set to **null** or **undefined**, the SQL statement is complete. The default value is null.|

**Return value**

| Type                   | Description               |
| ----------------------- | ------------------- |
| [ValueType](#valuetype) | SQL execution result.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [RDB Store Error Codes](errorcode-data-rdb.md). For details about how to handle error 14800011, see [Database Backup and Restore](../../database/data-backup-and-restore.md).

| **ID**| **Error Message**                                                |
| ------------ | ------------------------------------------------------------ |
| 401          | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 14800000     | Inner error.                                                 |
| 14800011     | Database corrupted.                                          |
| 14800014     | Already closed.                                              |
| 14800015     | The database does not respond.                               |
| 14800021     | SQLite: Generic error.                                       |
| 14800022     | SQLite: Callback routine requested an abort.                 |
| 14800023     | SQLite: Access permission denied.                            |
| 14800024     | SQLite: The database file is locked.                         |
| 14800025     | SQLite: A table in the database is locked.                   |
| 14800026     | SQLite: The database is out of memory.                       |
| 14800027     | SQLite: Attempt to write a readonly database.                |
| 14800028     | SQLite: Some kind of disk I/O error occurred.                |
| 14800029     | SQLite: The database is full.                                |
| 14800030     | SQLite: Unable to open the database file.                    |
| 14800031     | SQLite: TEXT or BLOB exceeds size limit.                     |
| 14800032     | SQLite: Abort due to constraint violation.                   |
| 14800033     | SQLite: Data type mismatch.                                  |
| 14800034     | SQLite: Library used incorrectly.                            |
| 14800047     | The WAL file size exceeds the default limit.                 |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

// Check the RDB store integrity.
if(store != undefined) {
  const SQL_CHECK_INTEGRITY = 'PRAGMA integrity_check';
  try {
    let data = (store as relationalStore.RdbStore).executeSync(SQL_CHECK_INTEGRITY)
    console.info(`check result: ${data}`);
  } catch (err) {
    console.error(`check failed, code is ${err.code}, message is ${err.message}`);
  }
}

// Delete all data from the table.
if(store != undefined) {
  const SQL_DELETE_TABLE = 'DELETE FROM test';
  try {
    let data = (store as relationalStore.RdbStore).executeSync(SQL_DELETE_TABLE)
    console.info(`delete result: ${data}`);
  } catch (err) {
    console.error(`delete failed, code is ${err.code}, message is ${err.message}`);
  }
}

// Delete a table.
if(store != undefined) {
  const SQL_DROP_TABLE = 'DROP TABLE test';
  try {
    let data = (store as relationalStore.RdbStore).executeSync(SQL_DROP_TABLE)
    console.info(`drop result: ${data}`);
  } catch (err) {
    console.error(`drop failed, code is ${err.code}, message is ${err.message}`);
  }
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
| callback    | AsyncCallback&lt;[ModifyTime](#modifytime10)&gt; | Yes  | Callback used to return the result. If the operation is successful, the **ModifyTime** object is returned.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [RDB Store Error Codes](errorcode-data-rdb.md). For details about how to handle error 14800011, see [Database Backup and Restore](../../database/data-backup-and-restore.md).

| **ID**| **Error Message**                                                |
|-----------| ------------------------------------------------------------ |
| 401       | Parameter error. Possible causes: 1. Need 3 - 4  parameter(s)! 2. The RdbStore must be not nullptr.3. The tablesNames must be not empty string. 4. The columnName must be not empty string. 5. The PRIKey must be number or string. |
| 801       | Capability not supported. |
| 14800000  | Inner error. |
| 14800011  | Database corrupted. |
| 14800014  | Already closed. |
| 14800015  | The database does not respond. |
| 14800021  | SQLite: Generic error. |
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
let PRIKey = [1, 4, 2, 3];
if(store != undefined) {
  (store as relationalStore.RdbStore).getModifyTime("EMPLOYEE", "NAME", PRIKey, (err, modifyTime: relationalStore.ModifyTime) => {
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

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [RDB Store Error Codes](errorcode-data-rdb.md). For details about how to handle error 14800011, see [Database Backup and Restore](../../database/data-backup-and-restore.md).

| **ID**| **Error Message**                                                |
|-----------| ------------------------------------------------------------ |
| 401       | Parameter error. Possible causes: 1. Need 3 - 4  parameter(s)! 2. The RdbStore must be not nullptr.3. The tablesNames must be not empty string. 4. The columnName must be not empty string. 5. The PRIKey must be number or string. |
| 801       | Capability not supported. |
| 14800000  | Inner error. |
| 14800011  | Database corrupted. |
| 14800014  | Already closed. |
| 14800015  | The database does not respond. |
| 14800021  | SQLite: Generic error. |
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

let PRIKey = [1, 2, 3];
if(store != undefined) {
  (store as relationalStore.RdbStore).getModifyTime("EMPLOYEE", "NAME", PRIKey)
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

Begins a transaction before executing an SQL statement.
This API does not allow nested transactions and cannot be used across processes or threads.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [RDB Store Error Codes](errorcode-data-rdb.md). For details about how to handle error 14800011, see [Database Backup and Restore](../../database/data-backup-and-restore.md).

| **ID**| **Error Message**                                                |
|-----------| ------------------------------------------------------------ |
| 401       | Parameter error. The store must not be nullptr. |
| 14800000  | Inner error. |
| 14800011  | Database corrupted. |
| 14800014  | Already closed. |
| 14800015  | The database does not respond. |
| 14800021  | SQLite: Generic error. |
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

let value1 = "Lisa";
let value2 = 18;
let value3 = 100.5;
let value4 = new Uint8Array([1, 2, 3]);

if(store != undefined) {
  (store as relationalStore.RdbStore).beginTransaction();
  const valueBucket: relationalStore.ValuesBucket = {
    'NAME': value1,
    'AGE': value2,
    'SALARY': value3,
    'CODES': value4,
  };
  (store as relationalStore.RdbStore).insert("test", valueBucket);
  (store as relationalStore.RdbStore).commit();
}
```

### beginTrans<sup>12+</sup>

beginTrans(): Promise&lt;number&gt;

Begins a transaction before executing the SQL statement. This API uses a promise to return the result.

Different from [beginTransaction](#begintransaction), this API returns a transaction ID. [execute](#execute12-1) can specify the transaction ID to isolate different transactions.

This API supports only [vector stores](#storeconfig).

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Return value**

| Type               | Description                     |
| ------------------- | ------------------------- |
| Promise&lt;number&gt; | Promise used to return the transaction ID.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [RDB Store Error Codes](errorcode-data-rdb.md). For details about how to handle error 14800011, see [Database Backup and Restore](../../database/data-backup-and-restore.md).

| **ID**| **Error Message**                                                |
|-----------| ------------------------------------------------------------ |
| 401       | Parameter error. The store must not be nullptr. |
| 801       | Capability not supported the sql(attach,begin,commit,rollback etc.). |
| 14800000  | Inner error. |
| 14800011  | Database corrupted. |
| 14800014  | Already closed. |
| 14800015  | The database does not respond. |
| 14800021  | SQLite: Generic error. |
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
import { BusinessError } from '@kit.BasicServicesKit';
if(store != null) {
  let txId : number;
  (store as relationalStore.RdbStore).beginTrans().then((txId : number) => {
    (store as relationalStore.RdbStore).execute("DELETE FROM TEST WHERE age = ? OR age = ?", txId, ["18", "20"])
      .then(() => {
        (store as relationalStore.RdbStore).commit(txId);
    })
    .catch((err: BusinessError) => {
      (store as relationalStore.RdbStore).rollback(txId)
      console.error(`execute sql failed, code is ${err.code},message is ${err.message}`);
    });
  });
}
```

### createTransaction<sup>14+</sup>

createTransaction(options?: TransactionOptions): Promise&lt;Transaction&gt;

Creates a transaction object and starts a transaction. This API uses a promise to return the result.

Different from [beginTransaction](#begintransaction), **createTransaction()** returns a transaction object, which is isolated from other transaction objects. A store supports a maximum of four transaction objects at a time. Exceeding the limit will return error 14800015. If this occurs, check for the transaction object that is being held too long or if there are too many concurrent transactions. If optimization is not possible, wait for other transactions to be released before creating a transaction object again.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Parameters**

| Name     | Type                         | Mandatory| Description                                                        |
| ----------- | ----------------------------- | ---- | ------------------------------------------------------------ |
| options       | [TransactionOptions](#transactionoptions14)           | No  | Configuration of the transaction object to create.                                |

**Return value**

| Type               | Description                     |
| ------------------- | ------------------------- |
| Promise&lt;[Transaction](#transaction14)&gt; | Promise used to return the transaction object created.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [RDB Store Error Codes](errorcode-data-rdb.md). For details about how to handle error 14800011, see [Database Backup and Restore](../../database/data-backup-and-restore.md).

| **ID**| **Error Message**                                                |
|-----------| ------------------------------------------------------------ |
| 14800000  | Inner error. |
| 14800011  | Database corrupted. |
| 14800014  | Already closed. |
| 14800015  | The database is busy.              |
| 14800023  | SQLite: Access permission denied. |
| 14800024  | SQLite: The database file is locked. |
| 14800026  | SQLite: The database is out of memory. |
| 14800028  | SQLite: Some kind of disk I/O error occurred. |
| 14800029  | SQLite: The database is full. |
| 14800030  | SQLite: Unable to open the database file. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

if(store != undefined) {
  (store as relationalStore.RdbStore).createTransaction().then((transaction: relationalStore.Transaction) => {
    transaction.execute("DELETE FROM test WHERE age = ? OR age = ?", [21, 20]).then(() => {
      transaction.commit();
    }).catch((e: BusinessError) => {
      transaction.rollback();
      console.error(`execute sql failed, code is ${e.code},message is ${e.message}`);
    });
  }).catch((err: BusinessError) => {
    console.error(`createTransaction faided, code is ${err.code},message is ${err.message}`);
  });
}
```

### commit

commit():void

Commits the executed SQL statement. This API must be used with [beginTransaction](#begintransaction).
This API does not allow nested transactions and cannot be used across processes or threads.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [RDB Store Error Codes](errorcode-data-rdb.md). For details about how to handle error 14800011, see [Database Backup and Restore](../../database/data-backup-and-restore.md).

| **ID**| **Error Message**                                                |
|-----------| ------------------------------------------------------------ |
| 401       | Parameter error. The store must not be nullptr. |
| 14800000  | Inner error. |
| 14800011  | Database corrupted. |
| 14800014  | Already closed. |
| 14800015  | The database does not respond. |
| 14800021  | SQLite: Generic error. |
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

let value1 = "Lisa";
let value2 = 18;
let value3 = 100.5;
let value4 = new Uint8Array([1, 2, 3]);

if(store != undefined) {
  (store as relationalStore.RdbStore).beginTransaction();
  const valueBucket: relationalStore.ValuesBucket = {
    'NAME': value1,
    'AGE': value2,
    'SALARY': value3,
    'CODES': value4,
  };
  (store as relationalStore.RdbStore).insert("test", valueBucket);
  (store as relationalStore.RdbStore).commit();
}
```

### commit<sup>12+</sup>

commit(txId : number):Promise&lt;void&gt;

Commits the executed SQL statement. This API must be used with [beginTrans](#begintrans12).

This API supports only [vector stores](#storeconfig).

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Parameters**

| Name  | Type                                | Mandatory| Description                                                        |
| -------- | ------------------------------------ | ---- | ------------------------------------------------------------ |
| txId      | number                               | Yes  | Transaction ID obtained via [beginTrans](#begintrans12).                                       |

**Return value**

| Type               | Description                     |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [RDB Store Error Codes](errorcode-data-rdb.md). For details about how to handle error 14800011, see [Database Backup and Restore](../../database/data-backup-and-restore.md).

| **ID**| **Error Message**                                                |
|-----------| ------------------------------------------------------------ |
| 401       | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 14800000  | Inner error. |
| 14800011  | Database corrupted. |
| 14800014  | Already closed. |
| 14800015  | The database does not respond. |
| 14800021  | SQLite: Generic error. |
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
if(store != null) {
  let txId : number;
  (store as relationalStore.RdbStore).beginTrans().then((txId : number) => {
    (store as relationalStore.RdbStore).execute("DELETE FROM TEST WHERE age = ? OR age = ?", txId, ["18", "20"])
      .then(() => {
        (store as relationalStore.RdbStore).commit(txId);
    })
    .catch((err: BusinessError) => {
      (store as relationalStore.RdbStore).rollback(txId)
      console.error(`execute sql failed, code is ${err.code},message is ${err.message}`);
    });
  });
}
```

### rollBack

rollBack():void

Rolls back the executed SQL statement.
This API does not allow nested transactions and cannot be used across processes or threads.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [RDB Store Error Codes](errorcode-data-rdb.md). For details about how to handle error 14800011, see [Database Backup and Restore](../../database/data-backup-and-restore.md).

| **ID**| **Error Message**                                                |
|-----------| ------------------------------------------------------------ |
| 401       | Parameter error. The store must not be nullptr. |
| 14800000  | Inner error. |
| 14800011  | Database corrupted. |
| 14800014  | Already closed. |
| 14800015  | The database does not respond. |
| 14800021  | SQLite: Generic error. |
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

let value1 = "Lisa";
let value2 = 18;
let value3 = 100.5;
let value4 = new Uint8Array([1, 2, 3]);

if(store != undefined) {
  try {
    (store as relationalStore.RdbStore).beginTransaction()
    const valueBucket: relationalStore.ValuesBucket = {
      'NAME': value1,
      'AGE': value2,
      'SALARY': value3,
      'CODES': value4,
    };
    (store as relationalStore.RdbStore).insert("test", valueBucket);
    (store as relationalStore.RdbStore).commit();
  } catch (err) {
    let code = (err as BusinessError).code;
    let message = (err as BusinessError).message
    console.error(`Transaction failed, code is ${code},message is ${message}`);
    (store as relationalStore.RdbStore).rollBack();
  }
}
```

### rollback<sup>12+</sup>

rollback(txId : number):Promise&lt;void&gt;

Rolls back the executed SQL statement. This API must be used with [beginTrans](#begintrans12).

This API supports only [vector stores](#storeconfig).

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Parameters**

| Name  | Type                                | Mandatory| Description                                                        |
| -------- | ------------------------------------ | ---- | ------------------------------------------------------------ |
| txId      | number                               | Yes  | Transaction ID obtained via [beginTrans](#begintrans12).                                       |

**Return value**

| Type               | Description                     |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [RDB Store Error Codes](errorcode-data-rdb.md). For details about how to handle error 14800011, see [Database Backup and Restore](../../database/data-backup-and-restore.md).

| **ID**| **Error Message**                                                |
|-----------| ------------------------------------------------------------ |
| 401       | Parameter error. The store must not be nullptr. |
| 14800000  | Inner error. |
| 14800011  | Database corrupted. |
| 14800014  | Already closed. |
| 14800015  | The database does not respond. |
| 14800021  | SQLite: Generic error. |
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
if(store != null) {
  let txId : number;
  (store as relationalStore.RdbStore).beginTrans().then((txId : number) => {
    (store as relationalStore.RdbStore).execute("DELETE FROM TEST WHERE age = ? OR age = ?", txId, ["18", "20"])
      .then(() => {
        (store as relationalStore.RdbStore).commit(txId);
    })
    .catch((err: BusinessError) => {
      (store as relationalStore.RdbStore).rollback(txId)
      console.error(`execute sql failed, code is ${err.code},message is ${err.message}`);
    });
  });
}
```

### backup

backup(destName:string, callback: AsyncCallback&lt;void&gt;):void

Backs up an RDB store. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Parameters**

| Name  | Type                     | Mandatory| Description                    |
| -------- | ------------------------- | ---- | ------------------------ |
| destName | string                    | Yes  | Name of the RDB store backup file.|
| callback | AsyncCallback&lt;void&gt; | Yes  | Callback used to return the result.  |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [RDB Store Error Codes](errorcode-data-rdb.md). For details about how to handle error 14800011, see [Database Backup and Restore](../../database/data-backup-and-restore.md).

| **ID**| **Error Message**                                                |
|-----------| ------------------------------------------------------------ |
| 401       | Parameter error. The store must not be nullptr. |
| 14800000  | Inner error. |
| 14800010  | Invalid database path. |
| 14800011  | Database corrupted. |
| 14800014  | Already closed. |
| 14800015  | The database does not respond. |
| 14800021  | SQLite: Generic error. |
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

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [RDB Store Error Codes](errorcode-data-rdb.md). For details about how to handle error 14800011, see [Database Backup and Restore](../../database/data-backup-and-restore.md).

| **ID**| **Error Message**                                                |
|-----------| ------------------------------------------------------------ |
| 401       | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 14800000  | Inner error. |
| 14800011  | Database corrupted. |
| 14800014  | Already closed. |
| 14800015  | The database does not respond. |
| 14800021  | SQLite: Generic error. |
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
| callback | AsyncCallback&lt;void&gt; | Yes  | Callback used to return the result.  |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [RDB Store Error Codes](errorcode-data-rdb.md). For details about how to handle error 14800011, see [Database Backup and Restore](../../database/data-backup-and-restore.md).

| **ID**| **Error Message**                                                |
|-----------| ------------------------------------------------------------ |
| 401       | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 14800000  | Inner error. |
| 14800011  | Database corrupted. |
| 14800014  | Already closed. |
| 14800015  | The database does not respond. |
| 14800021  | SQLite: Generic error. |
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

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [RDB Store Error Codes](errorcode-data-rdb.md). For details about how to handle error 14800011, see [Database Backup and Restore](../../database/data-backup-and-restore.md).

| **ID**| **Error Message**                                                |
|-----------| ------------------------------------------------------------ |
| 401       | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 14800000  | Inner error. |
| 14800011  | Database corrupted. |
| 14800014  | Already closed. |
| 14800015  | The database does not respond. |
| 14800021  | SQLite: Generic error. |
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
| callback | AsyncCallback&lt;void&gt; | Yes  | Callback used to return the result.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [RDB Store Error Codes](errorcode-data-rdb.md).

| **ID**| **Error Message**                                                |
|-----------| ------------------------------------------------------------ |
| 401       | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 801       | Capability not supported. |
| 14800000  | Inner error. |
| 14800014  | Already closed. |

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

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [RDB Store Error Codes](errorcode-data-rdb.md).

| **ID**| **Error Message**                                                |
|-----------| ------------------------------------------------------------ |
| 401       | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 801       | Capability not supported. |
| 14800000  | Inner error. |
| 14800014  | Already closed. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

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
| callback | AsyncCallback&lt;void&gt;             | Yes  | Callback used to return the result.      |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [RDB Store Error Codes](errorcode-data-rdb.md).

| **ID**| **Error Message**                                                |
|-----------| ------------------------------------------------------------ |
| 401       | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 801       | Capability not supported. |
| 14800000  | Inner error. |
| 14800014  | Already closed. |
| 14800051  | The type of the distributed table does not match. |

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
| callback | AsyncCallback&lt;void&gt;           | Yes  | Callback used to return the result.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [RDB Store Error Codes](errorcode-data-rdb.md).

| **ID**| **Error Message**                                                |
|-----------| ------------------------------------------------------------ |
| 401       | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 801       | Capability not supported. |
| 14800000  | Inner error. |
| 14800014  | Already closed. |
| 14800051  | The type of the distributed table does not match. |

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
| config | [DistributedConfig](#distributedconfig10) | No  | Configuration of the distributed mode. If this parameter is not specified, the value of **autoSync** is **false** by default, which means only manual sync is supported.|

**Return value**

| Type               | Description                     |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [RDB Store Error Codes](errorcode-data-rdb.md).

| **ID**| **Error Message**                                                |
|-----------| ------------------------------------------------------------ |
| 401       | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 801       | Capability not supported. |
| 14800000  | Inner error. |
| 14800014  | Already closed. |
| 14800051  | The type of the distributed table does not match. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

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
> **device** can be obtained by [deviceManager.getAvailableDeviceListSync](../apis-distributedservice-kit/js-apis-distributedDeviceManager.md#getavailabledevicelistsync).

**Required permissions**: ohos.permission.DISTRIBUTED_DATASYNC

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Parameters**

| Name  | Type                       | Mandatory| Description                                                        |
| -------- | --------------------------- | ---- | ------------------------------------------------------------ |
| device   | string                      | Yes  | ID of the remote device.                                               |
| table    | string                      | Yes  | Local table name of the remote device.                                        |
| callback | AsyncCallback&lt;string&gt; | Yes  | Callback used to return the result. If the operation succeeds, the distributed table name of the remote device is returned.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [RDB Store Error Codes](errorcode-data-rdb.md).

| **ID**| **Error Message**                                                |
|-----------| ------------------------------------------------------------ |
| 401       | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 801       | Capability not supported. |
| 14800000  | Inner error. |
| 14800014  | Already closed. |

**Example**

```ts
import { distributedDeviceManager } from '@kit.DistributedServiceKit';
import { BusinessError } from '@kit.BasicServicesKit';

let dmInstance: distributedDeviceManager.DeviceManager;
let deviceId: string | undefined = undefined;

try {
  dmInstance = distributedDeviceManager.createDeviceManager("com.example.appdatamgrverify");
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
> **device** can be obtained by [deviceManager.getAvailableDeviceListSync](../apis-distributedservice-kit/js-apis-distributedDeviceManager.md#getavailabledevicelistsync).

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

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [RDB Store Error Codes](errorcode-data-rdb.md).

| **ID**| **Error Message**                                                |
|-----------| ------------------------------------------------------------ |
| 401       | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 801       | Capability not supported. |
| 14800000  | Inner error. |
| 14800014  | Already closed. |

**Example**

```ts
import { distributedDeviceManager } from '@kit.DistributedServiceKit';
import { BusinessError } from '@kit.BasicServicesKit';

let dmInstance: distributedDeviceManager.DeviceManager;
let deviceId: string | undefined = undefined;

try {
  dmInstance = distributedDeviceManager.createDeviceManager("com.example.appdatamgrverify");
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
| mode       | [SyncMode](#syncmode)                             | Yes  | Data sync mode. The value can be **relationalStore.SyncMode.SYNC_MODE_PUSH** or **relationalStore.SyncMode.SYNC_MODE_PULL**.                              |
| predicates | [RdbPredicates](#rdbpredicates)               | Yes  | **RdbPredicates** object that specifies the data and devices to synchronize.                                        |
| callback   | AsyncCallback&lt;Array&lt;[string, number]&gt;&gt; | Yes  | Callback used to send the sync result to the caller. <br>**string** indicates the device ID. <br>**number** indicates the sync status of that device. The value **0** indicates a successful sync. Other values indicate a sync failure. |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [RDB Store Error Codes](errorcode-data-rdb.md).

| **ID**| **Error Message**                                                |
|-----------| ------------------------------------------------------------ |
| 401       | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 801       | Capability not supported. |
| 14800000  | Inner error. |
| 14800014  | Already closed. |

**Example**

```ts
import { distributedDeviceManager } from '@kit.DistributedServiceKit';
import { BusinessError } from '@kit.BasicServicesKit';

let dmInstance: distributedDeviceManager.DeviceManager;
let deviceIds: Array<string> = [];

try {
  dmInstance = distributedDeviceManager.createDeviceManager("com.example.appdatamgrverify");
  let devices: Array<distributedDeviceManager.DeviceBasicInfo> = dmInstance.getAvailableDeviceListSync();
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
| mode       | [SyncMode](#syncmode)               | Yes  | Data sync mode. The value can be **relationalStore.SyncMode.SYNC_MODE_PUSH** or **relationalStore.SyncMode.SYNC_MODE_PULL**.|
| predicates | [RdbPredicates](#rdbpredicates) | Yes  | **RdbPredicates** object that specifies the data and devices to synchronize.          |

**Return value**

| Type                                        | Description                                                        |
| -------------------------------------------- | ------------------------------------------------------------ |
| Promise&lt;Array&lt;[string, number]&gt;&gt; | Promise used to send the sync result. <br>**string** indicates the device ID. <br>**number** indicates the sync status of that device. The value **0** indicates a successful sync. Other values indicate a sync failure. |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [RDB Store Error Codes](errorcode-data-rdb.md).

| **ID**| **Error Message**                                                |
|-----------| ------------------------------------------------------------ |
| 401       | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 801       | Capability not supported. |
| 14800000  | Inner error. |
| 14800014  | Already closed. |

**Example**

```ts
import { distributedDeviceManager } from '@kit.DistributedServiceKit';
import { BusinessError } from '@kit.BasicServicesKit';

let dmInstance: distributedDeviceManager.DeviceManager;
let deviceIds: Array<string> = [];

try {
  dmInstance = distributedDeviceManager.createDeviceManager("com.example.appdatamgrverify");
  let devices: Array<distributedDeviceManager.DeviceBasicInfo> = dmInstance.getAvailableDeviceListSync();
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

Manually starts device-cloud sync for all distributed tables. This API uses an asynchronous callback to return the result. Before using this API, ensure that the cloud service must be available.

**System capability**: SystemCapability.DistributedDataManager.CloudSync.Client

**Parameters**

| Name  | Type                                                 | Mandatory| Description                                              |
| -------- | ----------------------------------------------------- | ---- | -------------------------------------------------- |
| mode     | [SyncMode](#syncmode)                                 | Yes  | Sync mode of the database.                            |
| progress | Callback&lt;[ProgressDetails](#progressdetails10)&gt; | Yes  | Callback used to process database sync details.            |
| callback | AsyncCallback&lt;void&gt;                             | Yes  | Callback used to send the sync result to the caller.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [RDB Store Error Codes](errorcode-data-rdb.md).

| **ID**| **Error Message**       |
|-----------|-------|
| 401       | Parameter error. Possible causes: 1. Need 2 - 4  parameter(s). 2. The RdbStore must be not nullptr. 3. The mode must be a SyncMode of cloud. 4. The progress must be a callback type. 5. The callback must be a function. |
| 801       | Capability not supported.       |
| 14800014  | Already closed.        |

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

Manually starts device-cloud sync for all distributed tables. This API uses a promise to return the result. Before using this API, ensure that the cloud service must be available.

**System capability**: SystemCapability.DistributedDataManager.CloudSync.Client

**Parameters**

| Name  | Type                                                 | Mandatory| Description                                  |
| -------- | ----------------------------------------------------- | ---- | -------------------------------------- |
| mode     | [SyncMode](#syncmode)                                 | Yes  | Sync mode of the database.                |
| progress | Callback&lt;[ProgressDetails](#progressdetails10)&gt; | Yes  | Callback used to process database sync details.|

**Return value**

| Type               | Description                                   |
| ------------------- | --------------------------------------- |
| Promise&lt;void&gt; | Promise used to send the sync result.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [RDB Store Error Codes](errorcode-data-rdb.md).

| **ID**| **Error Message**   |
|-----------|------------------|
| 401       | Parameter error. Possible causes: 1. Need 2 - 4  parameter(s). 2. The RdbStore must be not nullptr. 3. The mode must be a SyncMode of cloud. 4. The progress must be a callback type. |
| 801       | Capability not supported.   |
| 14800014  | Already closed.           |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

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

Manually starts device-cloud sync of the specified table. This API uses an asynchronous callback to return the result. Before using this API, ensure that the cloud service must be available.

**System capability**: SystemCapability.DistributedDataManager.CloudSync.Client

**Parameters**

| Name  | Type                                                 | Mandatory| Description                                              |
| -------- | ----------------------------------------------------- | ---- | -------------------------------------------------- |
| mode     | [SyncMode](#syncmode)                                 | Yes  | Sync mode of the database.                            |
| tables   | string[]                                              | Yes  | Name of the table to synchronize.                                  |
| progress | Callback&lt;[ProgressDetails](#progressdetails10)&gt; | Yes  | Callback used to process database sync details.            |
| callback | AsyncCallback&lt;void&gt;                             | Yes  | Callback used to send the sync result to the caller.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [RDB Store Error Codes](errorcode-data-rdb.md).

| **ID**| **Error Message**                                                                                                                                                                                                                 |
|-----------|-------|
| 401       | Parameter error. Possible causes: 1. Need 2 - 4  parameter(s). 2. The RdbStore must be not nullptr. 3. The mode must be a SyncMode of cloud. 4. The tablesNames must be not empty. 5. The progress must be a callback type. 6.The callback must be a function.|
| 801       | Capability not supported.   |
| 14800014  | Already closed.   |

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

Manually starts device-cloud sync of the specified table. This API uses a promise to return the result. Before using this API, ensure that the cloud service must be available.

**System capability**: SystemCapability.DistributedDataManager.CloudSync.Client

**Parameters**

| Name  | Type                                                 | Mandatory| Description                                  |
| -------- | ----------------------------------------------------- | ---- | -------------------------------------- |
| mode     | [SyncMode](#syncmode)                                 | Yes  | Sync mode of the database.                |
| tables   | string[]                                              | Yes  | Name of the table to synchronize.                      |
| progress | Callback&lt;[ProgressDetails](#progressdetails10)&gt; | Yes  | Callback used to process database sync details.|

**Return value**

| Type               | Description                                   |
| ------------------- | --------------------------------------- |
| Promise&lt;void&gt; | Promise used to send the sync result.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [RDB Store Error Codes](errorcode-data-rdb.md).

| **ID**| **Error Message**    |
|-----------|---------------|
| 401       | Parameter error. Possible causes: 1. Need 2 - 4  parameter(s). 2. The RdbStore must be not nullptr. 3. The mode must be a SyncMode of cloud. 4. The tablesNames must be not empty. 5. The progress must be a callback type |
| 801       | Capability not supported.    |
| 14800014  | Already closed.  |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

const tables = ["table1", "table2"];

if(store != undefined) {
  (store as relationalStore.RdbStore).cloudSync(relationalStore.SyncMode.SYNC_MODE_CLOUD_FIRST, tables, (progressDetail: relationalStore.ProgressDetails) => {
    console.info(`progress: ${progressDetail}`);
  }).then(() => {
    console.info('Cloud sync succeeded');
  }).catch((err: BusinessError) => {
    console.error(`cloudSync failed, code is ${err.code},message is ${err.message}`);
  });
};
```

### on('dataChange')

on(event: 'dataChange', type: SubscribeType, observer: Callback&lt;Array&lt;string&gt;&gt;): void

Subscribes to data changes of specified devices. When the data of the specified devices changes, a callback is invoked to return the data change.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Parameters**

| Name  | Type                                                        | Mandatory| Description                                                        |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| event    | string                                                       | Yes  | Event type. The value is **'dataChange'**, which indicates data changes.                          |
| type     | [SubscribeType](#subscribetype)                              | Yes  | Type of data change to observe.                                                  |
| observer | Callback&lt;Array&lt;string&gt;&gt;                          | Yes  | Callback used to return the data change. Array&lt;string&gt; holds the IDs of the peer devices whose data is changed.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [RDB Store Error Codes](errorcode-data-rdb.md).

| **ID**| **Error Message**       |
|-----------|-------------|
| 401       | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 801       | Capability not supported. |
| 14800014  | Already closed.    |

**Example**

```ts
import { distributedDeviceManager } from '@kit.DistributedServiceKit';
import { BusinessError } from '@kit.BasicServicesKit';

let storeObserver = (devices: Array<string>) => {
  if (devices != undefined) {
    for (let i = 0; i < devices.length; i++) {
      console.info(`device= ${devices[i]} data changed`);
    }
  }
}

try {
  if (store != undefined) {
    (store as relationalStore.RdbStore).on('dataChange', relationalStore.SubscribeType.SUBSCRIBE_TYPE_REMOTE, storeObserver)
  }
} catch (err) {
    let code = (err as BusinessError).code;
    let message = (err as BusinessError).message
    console.error(`Register observer failed, code is ${code},message is ${message}`);
}
```

### on('dataChange')<sup>10+</sup>

on(event: 'dataChange', type: SubscribeType, observer: Callback&lt;Array&lt;string&gt;&gt;\| Callback&lt;Array&lt;ChangeInfo&gt;&gt;): void

Subscribes to data changes of the specified devices. The registered callback will be called when data in a distributed or local RDB store changes.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Parameters**

| Name  | Type                               | Mandatory| Description                                       |
| -------- | ----------------------------------- | ---- | ------------------------------------------- |
| event    | string                              | Yes  | Event type. The value is **'dataChange'**, which indicates data changes.         |
| type     | [SubscribeType](#subscribetype)    | Yes  | Type of data change to observe.|
| observer | Callback&lt;Array&lt;string&gt;&gt; \| Callback&lt;Array&lt;[ChangeInfo](#changeinfo10)&gt;&gt; | Yes  | Callback used to return the data change.<br>- If **type** is **SUBSCRIBE_TYPE_REMOTE**, **observer** must be **Callback&lt;Array&lt;string&gt;&gt;**, where **Array&lt;string&gt;** holds the IDs of the peer devices with data changes.<br> - If **type** is **SUBSCRIBE_TYPE_CLOUD**, **observer** must be **Callback&lt;Array&lt;string&gt;&gt;**, where **Array&lt;string&gt;** holds the cloud accounts with data changes.<br> - If **type** is **SUBSCRIBE_TYPE_CLOUD_DETAILS**, **observer** must be **Callback&lt;Array&lt;ChangeInfo&gt;&gt;**, where **Array&lt;ChangeInfo&gt;** holds the details about the device-cloud sync.<br>If **type** is **SUBSCRIBE_TYPE_LOCAL_DETAILS**, **observer** must be **Callback&lt;Array&lt;ChangeInfo&gt;&gt;**, where **Array&lt;ChangeInfo&gt;** holds the data change details in the local RDB store.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [RDB Store Error Codes](errorcode-data-rdb.md).

| **ID**| **Error Message**       |
|-----------|-------------|
| 202       | Permission verification failed, application which is not a system application uses system API. |
| 401       | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 801       | Capability not supported. |
| 14800014  | Already closed.    |

Example 1: **type** is **SUBSCRIBE_TYPE_REMOTE**.

```ts
import { distributedDeviceManager } from '@kit.DistributedServiceKit';
import { BusinessError } from '@kit.BasicServicesKit';

let storeObserver = (devices: Array<string>) => {
  if (devices != undefined) {
    for (let i = 0; i < devices.length; i++) {
      console.info(`device= ${devices[i]} data changed`);
    }
  }
}

try {
  if(store != undefined) {
    (store as relationalStore.RdbStore).on('dataChange', relationalStore.SubscribeType.SUBSCRIBE_TYPE_REMOTE, storeObserver);
  }
} catch (err) {
  let code = (err as BusinessError).code;
  let message = (err as BusinessError).message;
  console.error(`Register observer failed, code is ${code},message is ${message}`);
}
```

Example 2: **type** is **SUBSCRIBE_TYPE_LOCAL_DETAILS**.

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let changeInfos = (changeInfos: Array<relationalStore.ChangeInfo>) => {
  for (let i = 0; i < changeInfos.length; i++) {
    console.info(`changeInfos = ${changeInfos[i]}`);
  }
}

try {
  if(store != undefined) {
    (store as relationalStore.RdbStore).on('dataChange', relationalStore.SubscribeType.SUBSCRIBE_TYPE_LOCAL_DETAILS, changeInfos);
  }
} catch (err) {
  let code = (err as BusinessError).code;
  let message = (err as BusinessError).message;
  console.error(`on dataChange fail, code is ${code},message is ${message}`);
}

let value1 = "Lisa";
let value2 = 18;
let value3 = 100.5;
let value4 = new Uint8Array([1, 2, 3]);

try {
  const valueBucket: relationalStore.ValuesBucket = {
    'name': value1,
    'age': value2,
    'salary': value3,
    'blobType': value4,
  };

  if(store != undefined) {
    (store as relationalStore.RdbStore).insert('test', valueBucket);
  }
} catch (err) {
  let code = (err as BusinessError).code;
  let message = (err as BusinessError).message;
  console.error(`insert fail, code is ${code},message is ${message}`);
}
```

### on<sup>10+</sup>

on(event: string, interProcess: boolean, observer: Callback\<void>): void

Subscribes to process events. This callback is invoked by [emit](#emit10).

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Parameters**

| Name      | Type           | Mandatory| Description                                                        |
| ------------ | --------------- | ---- | ------------------------------------------------------------ |
| event        | string          | Yes  | Event name to observe.                                              |
| interProcess | boolean         | Yes  | Type of the data to observe.<br> The value **true** means inter-process events.<br> The value **false** means intra-process events.|
| observer     | Callback\<void> | Yes  | Callback used to return the result.                                                  |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [RDB Store Error Codes](errorcode-data-rdb.md).

| **ID**| **Error Message**       |
|-----------|-------------|
| 401       | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 801       | Capability not supported. |
| 14800000  | Inner error.    |
| 14800014  | Already closed.    |
| 14800050  | Failed to obtain the subscription service.    |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let storeObserver = () => {
  console.info(`storeObserver`);
}

try {
  if(store != undefined) {
    (store as relationalStore.RdbStore).on('storeObserver', false, storeObserver);
  }
} catch (err) {
  let code = (err as BusinessError).code;
  let message = (err as BusinessError).message
  console.error(`Register observer failed, code is ${code},message is ${message}`);
}
```

### on('autoSyncProgress')<sup>11+</sup>

on(event: 'autoSyncProgress', progress: Callback&lt;ProgressDetails&gt;): void

Subscribes to the auto sync progress. This API can be called only when device-cloud sync is enabled and the network connection is normal. When auto sync is performed, a callback will be invoked to send a notification of the sync progress.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Parameters**

| Name      | Type                             | Mandatory| Description                               |
| ------------ |---------------------------------| ---- |-----------------------------------|
| event        | string                          | Yes  | Event type. The value is **'autoSyncProgress'**, which indicates the auto sync progress.|
| progress     | Callback&lt;[ProgressDetails](#progressdetails10)&gt; | Yes  | Callback used to return the auto sync progress.                            |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [RDB Store Error Codes](errorcode-data-rdb.md).

| **ID**| **Error Message**   |
|-----------|--------|
| 401       | Parameter error. Possible causes: 1. Need 2 - 3  parameter(s)! 2. The RdbStore must be valid. 3. The event must be a not empty string. 4. The progress must be function. |
| 801       | Capability not supported.  |
| 14800014  | Already closed.     |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let progressDetail = (progressDetail: relationalStore.ProgressDetails) => {
  console.info(`progress: ${progressDetail}`);
}

try {
  if(store != undefined) {
    (store as relationalStore.RdbStore).on('autoSyncProgress', progressDetail)
  }
} catch (err) {
  let code = (err as BusinessError).code;
  let message = (err as BusinessError).message
  console.error(`Register observer failed, code is ${code},message is ${message}`);
}
```

### on('statistics')<sup>12+</sup>

on(event: 'statistics', observer: Callback&lt;SqlExecutionInfo&gt;): void

Subscribes to SQL statistics.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Parameters**

| Name      | Type                             | Mandatory| Description                               |
| ------------ |---------------------------------| ---- |-----------------------------------|
| event        | string                          | Yes  | Event type. The value is **'statistics'**, which indicates the statistics of the SQL execution time.|
| observer     | Callback&lt;[SqlExecutionInfo](#sqlexecutioninfo12)&gt; | Yes  | Callback used to return the statistics about the SQL execution time in the database. |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [RDB Store Error Codes](errorcode-data-rdb.md).

| **ID**| **Error Message**   |
|-----------|--------|
| 401       | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |
| 801       | Capability not supported.  |
| 14800000  | Inner error.  |
| 14800014  | Already closed.     |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let sqlExecutionInfo = (sqlExecutionInfo: relationalStore.SqlExecutionInfo) => {
  console.info(`sql: ${sqlExecutionInfo.sql[0]}`);
  console.info(`totalTime: ${sqlExecutionInfo.totalTime}`);
  console.info(`waitTime: ${sqlExecutionInfo.waitTime}`);
  console.info(`prepareTime: ${sqlExecutionInfo.prepareTime}`);
  console.info(`executeTime: ${sqlExecutionInfo.executeTime}`);
}

try {
  if(store != undefined) {
    (store as relationalStore.RdbStore).on('statistics', sqlExecutionInfo);
  }
} catch (err) {
  let code = (err as BusinessError).code;
  let message = (err as BusinessError).message;
  console.error(`Register observer failed, code is ${code},message is ${message}`);
}

try {
  let value1 = "Lisa";
  let value2 = 18;
  let value3 = 100.5;
  let value4 = new Uint8Array([1, 2, 3, 4, 5]);

  const valueBucket: relationalStore.ValuesBucket = {
    'NAME': value1,
    'AGE': value2,
    'SALARY': value3,
    'CODES': value4,
  };
  if(store != undefined) {
    (store as relationalStore.RdbStore).insert('test', valueBucket);
  }
} catch (err) {
  console.error(`insert fail, code:${err.code}, message: ${err.message}`);
}
```

### off('dataChange')

off(event:'dataChange', type: SubscribeType, observer: Callback&lt;Array&lt;string&gt;&gt;): void

Unsubscribes from data changes of the specified devices.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Parameters**

| Name  | Type                                                        | Mandatory| Description                                                        |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| event    | string                                                       | Yes  | Event type. The value is **'dataChange'**, which indicates data changes.                          |
| type     | [SubscribeType](#subscribetype) | Yes  | Type of data change to observe.                                                  |
| observer | Callback&lt;Array&lt;string&gt;&gt;                          | Yes  | Callback to unregister. **Array&lt;string&gt;** holds the IDs of the peer devices whose data is changed.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [RDB Store Error Codes](errorcode-data-rdb.md).

| **ID**| **Error Message**       |
|-----------|-------------|
| 401       | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 801       | Capability not supported. |
| 14800014  | Already closed.    |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let storeObserver = (devices: Array<string>) => {
  if (devices != undefined) {
    for (let i = 0; i < devices.length; i++) {
      console.info(`device= ${devices[i]} data changed`);
    }
  }
}

try {
  if (store != undefined) {
    // The Lambda expression cannot be used here.
    (store as relationalStore.RdbStore).on('dataChange', relationalStore.SubscribeType.SUBSCRIBE_TYPE_REMOTE, storeObserver)
  }
} catch (err) {
    let code = (err as BusinessError).code;
    let message = (err as BusinessError).message
    console.error(`Register observer failed, code is ${code},message is ${message}`);
}

try {
  if(store != undefined) {
    (store as relationalStore.RdbStore).off('dataChange', relationalStore.SubscribeType.SUBSCRIBE_TYPE_REMOTE, storeObserver);
  }
} catch (err) {
  let code = (err as BusinessError).code;
  let message = (err as BusinessError).message
  console.error(`Unregister observer failed, code is ${code},message is ${message}`);
}
```

### off('dataChange')<sup>10+</sup>

off(event:'dataChange', type: SubscribeType, observer?: Callback&lt;Array&lt;string&gt;&gt;\| Callback&lt;Array&lt;ChangeInfo&gt;&gt;): void

Unsubscribes from data changes of this RDB store.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Parameters**

| Name  | Type                               | Mandatory| Description                                       |
| -------- | ---------------------------------- | ---- | ------------------------------------------ |
| event    | string                              | Yes  | Event type. The value is **'dataChange'**, which indicates data changes.         |
| type     | [SubscribeType](#subscribetype)     | Yes  | Type of data change to observe.                                |
| observer | Callback&lt;Array&lt;string&gt;&gt;\| Callback&lt;Array&lt;[ChangeInfo](#changeinfo10)&gt;&gt; | No| Callback to unregister.<br>- If **type** is **SUBSCRIBE_TYPE_REMOTE**, **observer** must be **Callback&lt;Array&lt;string&gt;&gt;**, where **Array&lt;string&gt;** holds the IDs of the peer devices with data changes.<br> - If **type** is **SUBSCRIBE_TYPE_CLOUD**, **observer** must be **Callback&lt;Array&lt;string&gt;&gt;**, where **Array&lt;string&gt;** holds the cloud accounts with data changes.<br> - If **type** is **SUBSCRIBE_TYPE_CLOUD_DETAILS**, **observer** must be **Callback&lt;Array&lt;ChangeInfo&gt;&gt;**, where **Array&lt;ChangeInfo&gt;** holds the details about the device-cloud sync.<br>- If **type** is **SUBSCRIBE_TYPE_LOCAL_DETAILS**, **observer** must be **Callback&lt;Array&lt;ChangeInfo&gt;&gt;**, where **Array&lt;ChangeInfo&gt;** holds the data change details in the local RDB store.<br> If **observer** is not specified, this API unregisters all callbacks for data changes of the specified **type**.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [RDB Store Error Codes](errorcode-data-rdb.md).

| **ID**| **Error Message**       |
|-----------|-------------|
| 202       | Permission verification failed, application which is not a system application uses system API. |
| 401       | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 801       | Capability not supported. |
| 14800014  | Already closed.    |

**Example**

```ts
import { distributedDeviceManager } from '@kit.DistributedServiceKit';
import { BusinessError } from '@kit.BasicServicesKit';

let storeObserver = (devices: Array<string>) => {
  if (devices != undefined) {
    for (let i = 0; i < devices.length; i++) {
      console.info(`device= ${devices[i]} data changed`);
    }
  }
}

try {
  if(store != undefined) {
    (store as relationalStore.RdbStore).on('dataChange', relationalStore.SubscribeType.SUBSCRIBE_TYPE_REMOTE, storeObserver);
  }
} catch (err) {
  let code = (err as BusinessError).code;
  let message = (err as BusinessError).message;
  console.error(`Register observer failed, code is ${code},message is ${message}`);
}

try {
  if(store != undefined) {
    (store as relationalStore.RdbStore).off('dataChange', relationalStore.SubscribeType.SUBSCRIBE_TYPE_REMOTE, storeObserver);
  }
} catch (err) {
  let code = (err as BusinessError).code;
  let message = (err as BusinessError).message
  console.error(`Unregister observer failed, code is ${code},message is ${message}`);
}
```

### off<sup>10+</sup>

off(event: string, interProcess: boolean, observer?: Callback\<void>): void

Unsubscribes from process events.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Parameters**

| Name      | Type           | Mandatory| Description                                                        |
| ------------ | --------------- | ---- | ------------------------------------------------------------ |
| event        | string          | Yes  | Name of the event.                                          |
| interProcess | boolean         | Yes  | Type of the data to observe.<br> The value **true** means inter-process events.<br> The value **false** means intra-process events.|
| observer     | Callback\<void> | No  | Callback to unregister. If this parameter is not specified, this API unregisters all callbacks for the specified event.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [RDB Store Error Codes](errorcode-data-rdb.md).

| **ID**| **Error Message**                          |
| ------------ | -------------------------------------- |
| 401       | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 801       | Capability not supported. |
| 14800000     | Inner error.                           |
| 14800014  | Already closed.    |
| 14800050     | Failed to obtain the subscription service. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let storeObserver = () => {
  console.info(`storeObserver`);
}

try {
  if(store != undefined) {
    (store as relationalStore.RdbStore).on('storeObserver', false, storeObserver);
  }
} catch (err) {
  let code = (err as BusinessError).code;
  let message = (err as BusinessError).message
  console.error(`Register observer failed, code is ${code},message is ${message}`);
}

try {
  if(store != undefined) {
    (store as relationalStore.RdbStore).off('storeObserver', false, storeObserver);
  }
} catch (err) {
  let code = (err as BusinessError).code;
  let message = (err as BusinessError).message
  console.error(`Unregister observer failed, code is ${code},message is ${message}`);
}
```

### off('autoSyncProgress')<sup>11+</sup>

off(event: 'autoSyncProgress', progress?: Callback&lt;ProgressDetails&gt;): void

Unsubscribes from the auto sync progress.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Parameters**

| Name      | Type                             | Mandatory| Description                                                              |
| ------------ |---------------------------------| ---- |------------------------------------------------------------------|
| event        | string                          | Yes  | Event type. The value is **'autoSyncProgress'**, which indicates the auto sync progress.                               |
| progress     | Callback&lt;[ProgressDetails](#progressdetails10)&gt; | No  | Callback to unregister. If this parameter is **null** or **undefined** or not specified, this API unregisters all callbacks for the auto sync progress.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [RDB Store Error Codes](errorcode-data-rdb.md).

| **ID**| **Error Message**        |
| ------------ |--------------------|
| 401       | Parameter error. Possible causes: 1. Need 1 - 3  parameter(s)! 2. The RdbStore must be valid. 3. The event must be a not empty string. 4. The progress must be function. |
| 801       | Capability not supported.  |
| 14800014  | Already closed.       |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let progressDetail = (progressDetail: relationalStore.ProgressDetails) => {
  console.info(`progress: ${progressDetail}`);
}

try {
  if(store != undefined) {
    (store as relationalStore.RdbStore).on('autoSyncProgress', progressDetail)
  }
} catch (err) {
  let code = (err as BusinessError).code;
  let message = (err as BusinessError).message
  console.error(`Register observer failed, code is ${code},message is ${message}`);
}

try {
  if(store != undefined) {
    (store as relationalStore.RdbStore).off('autoSyncProgress', progressDetail);
  }
} catch (err) {
  let code = (err as BusinessError).code;
  let message = (err as BusinessError).message;
  console.error(`Unregister failed, code is ${code},message is ${message}`);
}
```

### off('statistics')<sup>12+</sup>

off(event: 'statistics', observer?: Callback&lt;SqlExecutionInfo&gt;): void

Unsubscribes from SQL statistics.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Parameters**

| Name      | Type                             | Mandatory| Description                               |
| ------------ |---------------------------------| ---- |-----------------------------------|
| event        | string                          | Yes  | Event type. The value is **'statistics'**, which indicates the statistics of the SQL execution time.|
| observer     | Callback&lt;[SqlExecutionInfo](#sqlexecutioninfo12)&gt; | No  | Callback to unregister. If this parameter is not specified, this API unregisters all callbacks for the specified event. |


**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [RDB Store Error Codes](errorcode-data-rdb.md).

| **ID**| **Error Message**   |
|-----------|--------|
| 401       | Parameter error.  |
| 801       | Capability not supported.  |
| 14800000  | Inner error.  |
| 14800014  | Already closed.     |

```ts
import { BusinessError } from '@kit.BasicServicesKit';

try {
  if(store != undefined) {
    (store as relationalStore.RdbStore).off('statistics');
  }
} catch (err) {
  let code = (err as BusinessError).code;
  let message = (err as BusinessError).message;
  console.error(`Unregister observer failed, code is ${code},message is ${message}`);
}
```

### emit<sup>10+</sup>

emit(event: string): void

Triggers the inter-process or intra-process event listener registered in [on](#on10).

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Parameters**

| Name| Type  | Mandatory| Description                |
| ------ | ------ | ---- | -------------------- |
| event  | string | Yes  | Name of the event.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [RDB Store Error Codes](errorcode-data-rdb.md).

| **ID**| **Error Message**                                                                                                     |
| --------- |---------------------------------------------------------------------------------------------------------------|
| 401       | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 801       | Capability not supported.     |
| 14800000  | Inner error.   |
| 14800014  | Already closed.     |
| 14800050  | Failed to obtain the subscription service.    |


**Example**

```ts
if(store != undefined) {
  (store as relationalStore.RdbStore).emit('storeObserver');
}
```

### cleanDirtyData<sup>11+</sup>

cleanDirtyData(table: string, cursor: number, callback: AsyncCallback&lt;void&gt;): void

Clears the dirty data whose cursor is smaller than the specified cursor from the local device. The dirty data is the data that has been deleted from the cloud.

**System capability**: SystemCapability.DistributedDataManager.CloudSync.Client

**Parameters**

| Name  | Type                                                 | Mandatory| Description                                              |
| -------- | ----------------------------------------------------- | ---- | -------------------------------------------------- |
| table     | string                        | Yes  | Name of the table in the RDB store.                            |
| cursor    | number                        | Yes  | Cursor of the data, which is an integer. All the dirty data with the cursor smaller than the specified value will be cleared.    |
| callback  | AsyncCallback&lt;void&gt;     | Yes  | Callback used to return the result.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [RDB Store Error Codes](errorcode-data-rdb.md). For details about how to handle error 14800011, see [Database Backup and Restore](../../database/data-backup-and-restore.md).

| **ID**| **Error Message**    |
|-----------|---------------|
| 401       | Parameter error. Possible causes: 1. Need 1 - 3  parameter(s)! 2. The RdbStore must be not nullptr. 3. The tablesNames must be not empty string. 4. The cursor must be valid cursor. |
| 801       | Capability not supported. |
| 14800000  | Inner error. |
| 14800011  | Database corrupted. |
| 14800014  | Already closed. |
| 14800015  | The database does not respond. |
| 14800021  | SQLite: Generic error. |
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
| callback  | AsyncCallback&lt;void&gt;     | Yes  | Callback used to return the result.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [RDB Store Error Codes](errorcode-data-rdb.md). For details about how to handle error 14800011, see [Database Backup and Restore](../../database/data-backup-and-restore.md).

| **ID**| **Error Message**      |
|-----------|---------|
| 401       | Parameter error. Possible causes: 1. Need 1 - 3  parameter(s). 2. The RdbStore must be not nullptr. 3. The tablesNames must be not empty string. |
| 801       | Capability not supported.    |
| 14800000  | Inner error.        |
| 14800011  | Database corrupted.   |
| 14800014  | Already closed.       |
| 14800015  | The database does not respond.      |
| 14800021  | SQLite: Generic error.     |
| 14800022  | SQLite: Callback routine requested an abort. |
| 14800023  | SQLite: Access permission denied.           |
| 14800024  | SQLite: The database file is locked.        |
| 14800025  | SQLite: A table in the database is locked.  |
| 14800026  | SQLite: The database is out of memory.      |
| 14800027  | SQLite: Attempt to write a readonly database.   |
| 14800028  | SQLite: Some kind of disk I/O error occurred.  |
| 14800029  | SQLite: The database is full.                |
| 14800030  | SQLite: Unable to open the database file.            |
| 14800031  | SQLite: TEXT or BLOB exceeds size limit.             |
| 14800032  | SQLite: Abort due to constraint violation.   |
| 14800033  | SQLite: Data type mismatch.                  |
| 14800034  | SQLite: Library used incorrectly.          |

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

Clears the dirty data whose cursor is smaller than the specified cursor from the local device. The dirty data is the data that has been deleted from the cloud. If **cursor** is not specified, all the dirty data will be cleared.

**System capability**: SystemCapability.DistributedDataManager.CloudSync.Client

**Parameters**

| Name  | Type                                                 | Mandatory| Description                                              |
| -------- | ----------------------------------------------------- | ---- | -------------------------------------------------- |
| table     | string           | Yes  | Name of the table in the RDB store.          |
| cursor    | number           | No  | Cursor of the data, which is an integer. All the dirty data with the cursor smaller than the specified value will be cleared. If this parameter is not specified, all dirty data in the current table will be cleared.|

**Return value**
| Name   | Description                                              |
| -------- | ------------------------------------------------- |
| Promise\<void> | Promise that returns no value.       |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [RDB Store Error Codes](errorcode-data-rdb.md). For details about how to handle error 14800011, see [Database Backup and Restore](../../database/data-backup-and-restore.md).

| **ID**| **Error Message**                                                                                                                                                                     |
|-----------|-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| 401       | Parameter error. Possible causes: 1. Need 1 - 3  parameter(s)! 2. The RdbStore must be not nullptr. 3. The tablesNames must be not empty string. 4. The cursor must be valid cursor. |
| 801       | Capability not supported. |
| 14800000  | Inner error.            |
| 14800011  | Database corrupted.   |
| 14800014  | Already closed. |
| 14800015  | The database does not respond.   |
| 14800021  | SQLite: Generic error.   |
| 14800022  | SQLite: Callback routine requested an abort. |
| 14800023  | SQLite: Access permission denied.          |
| 14800024  | SQLite: The database file is locked.      |
| 14800025  | SQLite: A table in the database is locked. |
| 14800026  | SQLite: The database is out of memory.   |
| 14800027  | SQLite: Attempt to write a readonly database. |
| 14800028  | SQLite: Some kind of disk I/O error occurred. |
| 14800029  | SQLite: The database is full.   |
| 14800030  | SQLite: Unable to open the database file. |
| 14800031  | SQLite: TEXT or BLOB exceeds size limit. |
| 14800032  | SQLite: Abort due to constraint violation. |
| 14800033  | SQLite: Data type mismatch. |
| 14800034  | SQLite: Library used incorrectly. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

if(store != undefined) {
    (store as relationalStore.RdbStore).cleanDirtyData('test_table', 100).then(() => {
        console.info('clean dirty data  succeeded');
    }).catch ((err: BusinessError) => {
        console.error(`clean dirty data failed, code is ${err.code},message is ${err.message}`);
    })
}
```

### attach<sup>12+</sup>

attach(fullPath: string, attachName: string, waitTime?: number) : Promise&lt;number&gt;

Attaches an RDB store to this RDB store so that the data in the attached RDB store can be directly accessed using the SQL statement.

The RDB store is attached via a database file. This API cannot be used for encrypted RDB stores. After the **attach()** API is called, the RDB store is switched to the non-WAL mode, which may affect the performance.

Before the RDB store is switched to the non-WAL mode, ensure that all **ResultSet**s are closed and all write operations are complete. Otherwise, error 14800015 will be reported.

The **attach()** API cannot be called concurrently. Concurrent calls may cause the system to become unresponsive and trigger 14800015. If this occurs, try to call **attach()** again later.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Parameters**

| Name       | Type    | Mandatory | Description          |
| ----------- | ------ | --- | ------------ |
| fullPath | string | Yes  | Path of the database file to attach.|
| attachName | string | Yes  | Alias of the RDB store formed after the attach operation.|
| waitTime | number | No  | Maximum time period (in seconds) allowed for attaching the database file. <br>Value range: 1 to 300<br>Default value: 2|

**Return value**

| Type             | Description                          |
| ---------------- | ---------------------------- |
|  Promise&lt;number&gt; | Promise used to return the number of attached RDB stores.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [RDB Store Error Codes](errorcode-data-rdb.md). For details about how to handle error 14800011, see [Database Backup and Restore](../../database/data-backup-and-restore.md).

| **ID**| **Error Message**                                                |
|-----------| ------------------------------------------------------------ |
| 401       | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 801       | Capability not supported. |
| 14800000  | Inner error. |
| 14800010  | Invalid database path.               |
| 14800011  | Database corrupted. |
| 14800014  | Already closed. |
| 14800015  | The database does not respond.                 |
| 14800016  | The database alias already exists.                |
| 14800021  | SQLite: Generic error. |
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
// Attach a non-encrypted RDB store to a non-encrypted RDB store.
import { BusinessError } from '@kit.BasicServicesKit';

if(store != undefined) {
    (store as relationalStore.RdbStore).attach("/path/rdbstore1.db", "attachDB").then((number: number) => {
        console.info('attach succeeded');
    }).catch ((err: BusinessError) => {
        console.error(`attach failed, code is ${err.code},message is ${err.message}`);
    })
}
```

### attach<sup>12+</sup>

attach(context: Context, config: StoreConfig, attachName: string, waitTime?: number) : Promise&lt;number&gt;

Attaches an RDB store to this RDB store so that the data in the attached RDB store can be directly accessed using the SQL statement.

This API cannot be used to attach a non-encrypted RDB store to an encrypted RDB store. After the **attach()** API is called, the RDB store is switched to non-WAL mode, which may affect the performance.

Before the RDB store is switched to non-WAL mode, ensure that all **ResultSet**s are closed and all write operations are complete. Otherwise, error 14800015 will be reported.

The **attach()** API cannot be called concurrently. Concurrent calls may cause the system to become unresponsive and trigger 14800015. If this occurs, try to call **attach()** again later. In addition, when an encrypted database is attached, the database may fail to be decrypted due to concurrency and error 14800011 is reported. In this case, explicitly specify encryption parameters and try again.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Parameters**

| Name       | Type    | Mandatory | Description          |
| ----------- | ------ | --- | ------------ |
| context | Context                          | Yes  | Application context.<br>For details about the application context of the FA model, see [Context](../apis-ability-kit/js-apis-inner-app-context.md).<br>For details about the application context of the stage model, see [Context](../apis-ability-kit/js-apis-inner-application-uiAbilityContext.md).|
| config  | [StoreConfig](#storeconfig) | Yes  | Configuration of the RDB store to attach.                               |
| attachName | string | Yes  | Alias of the RDB store formed after the attach operation.|
| waitTime | number | No  | Maximum time period (in seconds) allowed for attaching the database file. <br>Value range: 1 to 300<br>Default value: 2|

**Return value**

| Type             | Description                          |
| ---------------- | ---------------------------- |
|  Promise&lt;number&gt; | Promise used to return the number of attached RDB stores.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [RDB Store Error Codes](errorcode-data-rdb.md). For details about how to handle error 14800011, see [Database Backup and Restore](../../database/data-backup-and-restore.md).

| **ID**| **Error Message**                                                |
|-----------| ------------------------------------------------------------ |
| 401       | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 801       | Capability not supported. |
| 14800000  | Inner error. |
| 14800010  | Invalid database path.               |
| 14800011  | Database corrupted. |
| 14800014  | Already closed. |
| 14800015  | The database does not respond.                 |
| 14800016  | The database alias already exists.                |
| 14801001  | The operation is supported in the stage model only.                 |
| 14801002  | Invalid data group ID.                |
| 14800021  | SQLite: Generic error. |
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

Example 1: Attach a non-encrypted RDB store to a non-encrypted RDB store.

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let attachStore: relationalStore.RdbStore | undefined = undefined;

const STORE_CONFIG1: relationalStore.StoreConfig = {
    name: "rdbstore1.db",
    securityLevel: relationalStore.SecurityLevel.S3,
}

relationalStore.getRdbStore(this.context, STORE_CONFIG1).then(async (rdbStore: relationalStore.RdbStore) => {
    attachStore = rdbStore;
    console.info('Get RdbStore successfully.')
}).catch((err: BusinessError) => {
    console.error(`Get RdbStore failed, code is ${err.code},message is ${err.message}`);
})

if(store != undefined) {
    (store as relationalStore.RdbStore).attach(this.context, STORE_CONFIG1, "attachDB").then((number: number) => {
        console.info(`attach succeeded, number is ${number}`);
    }).catch ((err: BusinessError) => {
        console.error(`attach failed, code is ${err.code},message is ${err.message}`);
    })
}
```

Example 2: Attach an encrypted RDB store to a non-encrypted RDB store.

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let attachStore: relationalStore.RdbStore | undefined = undefined;


const STORE_CONFIG2: relationalStore.StoreConfig = {
    name: "rdbstore2.db",
    encrypt: true,
    securityLevel: relationalStore.SecurityLevel.S3,
}

relationalStore.getRdbStore(this.context, STORE_CONFIG2).then(async (rdbStore: relationalStore.RdbStore) => {
    attachStore = rdbStore;
    console.info('Get RdbStore successfully.')
}).catch((err: BusinessError) => {
    console.error(`Get RdbStore failed, code is ${err.code},message is ${err.message}`);
})

if(store != undefined) {
    (store as relationalStore.RdbStore).attach(this.context, STORE_CONFIG2, "attachDB2", 10).then((number: number) => {
        console.info(`attach succeeded, number is ${number}`);
    }).catch ((err: BusinessError) => {
        console.error(`attach failed, code is ${err.code},message is ${err.message}`);
    })
}
```

### detach<sup>12+</sup>

detach(attachName: string, waitTime?: number) : Promise&lt;number&gt;

Detaches an RDB store from this RDB store.

After all attached RDB stores are detached, the RDB is switched to the WAL mode.

Before calling **detach()**, ensure that all database operations are complete and all **ResultSet**s are closed. In addition, **detach()** cannot be called concurrently. Concurrent calls may cause the system to become unresponsive. If this occurs, try to call **detach()** again later.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Parameters**

| Name       | Type    | Mandatory | Description          |
| ----------- | ------ | --- | ------------ |
| attachName | string | Yes  | Alias of the RDB store formed after the attach operation.|
| waitTime | number | No  | Maximum time period (in seconds) allowed for detaching the RDB store. <br>Value range: 1 to 300<br>Default value: 2|

**Return value**

| Type             | Description                          |
| ---------------- | ---------------------------- |
|  Promise&lt;number&gt; | Promise used to return the number of remaining attached RDB stores.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [RDB Store Error Codes](errorcode-data-rdb.md). For details about how to handle error 14800011, see [Database Backup and Restore](../../database/data-backup-and-restore.md).

| **ID**| **Error Message**      |
|-----------|------------------------|
| 401       | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 14800000  | Inner error.            |
| 14800011  | Database corrupted.         |
| 14800014  | Already closed.        |
| 14800015  | The database does not respond.         |
| 14800021  | SQLite: Generic error.            |
| 14800022  | SQLite: Callback routine requested an abort.       |
| 14800023  | SQLite: Access permission denied.           |
| 14800024  | SQLite: The database file is locked.        |
| 14800025  | SQLite: A table in the database is locked.       |
| 14800026  | SQLite: The database is out of memory.     |
| 14800027  | SQLite: Attempt to write a readonly database.        |
| 14800028  | SQLite: Some kind of disk I/O error occurred.    |
| 14800029  | SQLite: The database is full.      |
| 14800030  | SQLite: Unable to open the database file.       |
| 14800031  | SQLite: TEXT or BLOB exceeds size limit.      |
| 14800032  | SQLite: Abort due to constraint violation.    |
| 14800033  | SQLite: Data type mismatch.       |
| 14800034  | SQLite: Library used incorrectly.       |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

if(store != undefined) {
    (store as relationalStore.RdbStore).detach("attachDB").then((number: number) => {
        console.info(`detach succeeded, number is ${number}`);
    }).catch ((err: BusinessError) => {
        console.error(`detach failed, code is ${err.code},message is ${err.message}`);
    })
}
```

### lockRow<sup>12+</sup>

lockRow(predicates: RdbPredicates):Promise&lt;void&gt;

Locks data in this RDB store. This API uses a promise to return the result. The locked data is blocked from device-cloud sync.

This API supports only the tables with the primary keys of the basic types. It is not available to shared tables, tables without primary keys, or tables with primary keys of composite types.
This API does not support lock transfer between tables with dependencies. If this table has dependent tables, you need to call this API for the related tables based on the dependency relationships.
This API cannot be used for deleted data.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Parameters**

| Name    | Type                                | Mandatory| Description                                     |
| ---------- | ------------------------------------ | ---- | ----------------------------------------- |
| predicates | [RdbPredicates](#rdbpredicates) | Yes  | Conditions for locking data.|

**Return value**

| Type                 | Description                           |
| --------------------- | ------------------------------- |
| Promise&lt;void&gt;   | Promise that returns no value.       |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [RDB Store Error Codes](errorcode-data-rdb.md). For details about how to handle error 14800011, see [Database Backup and Restore](../../database/data-backup-and-restore.md).

| **ID**| **Error Message**                                                                                    |
|-----------|----------------------------------------------------------------------------------------------|
| 401       | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 14800000  | Inner error.                                                                                 |
| 14800011  | Database corrupted.                                                                          |
| 14800014  | Already closed.                                                                              |
| 14800015  | The database does not respond.                                                                        |
| 14800018  | No data meets the condition.                                                                 |
| 14800021  | SQLite: Generic error.                                                                       |
| 14800022  | SQLite: Callback routine requested an abort.                                                 |
| 14800023  | SQLite: Access permission denied.                                                            |
| 14800024  | SQLite: The database file is locked.                                                         |
| 14800025  | SQLite: A table in the database is locked.                                                   |
| 14800026  | SQLite: The database is out of memory.                                                       |
| 14800027  | SQLite: Attempt to write a readonly database.                                                |
| 14800028  | SQLite: Some kind of disk I/O error occurred.                                                |
| 14800029  | SQLite: The database is full.                                                                |
| 14800030  | SQLite: Unable to open the database file.                                                    |
| 14800031  | SQLite: TEXT or BLOB exceeds size limit.                                                     |
| 14800032  | SQLite: Abort due to constraint violation.                                                   |
| 14800033  | SQLite: Data type mismatch.                                                                  |
| 14800034  | SQLite: Library used incorrectly.                                                            |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let predicates = new relationalStore.RdbPredicates("EMPLOYEE");
predicates.equalTo("NAME", "Lisa");
if(store != undefined) {
  (store as relationalStore.RdbStore).lockRow(predicates).then(() => {
    console.info(`Lock success`);
  }).catch((err: BusinessError) => {
    console.error(`Lock failed, code is ${err.code},message is ${err.message}`);
  })
}
```

### unlockRow<sup>12+</sup>

unlockRow(predicates: RdbPredicates):Promise&lt;void&gt;

Unlocks data in this RDB store. This API uses a promise to return the result.

This API supports only the tables with the primary keys of the basic types. It is not available to shared tables, tables without primary keys, or tables with primary keys of composite types.
This API does not support lock transfer between tables with dependencies. If this table has dependent tables, you need to call this API for the related tables based on the dependency relationships.
This API cannot be used for deleted data.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Parameters**

| Name    | Type                                | Mandatory| Description                                     |
| ---------- | ------------------------------------ | ---- | ----------------------------------------- |
| predicates | [RdbPredicates](#rdbpredicates) | Yes  | Conditions for unlocking data.|

**Return value**

| Type                 | Description                           |
| --------------------- | ------------------------------- |
| Promise&lt;void&gt;   | Promise that returns no value.       |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [RDB Store Error Codes](errorcode-data-rdb.md). For details about how to handle error 14800011, see [Database Backup and Restore](../../database/data-backup-and-restore.md).

| **ID**| **Error Message**                                                |
|-----------| ------------------------------------------------------------ |
| 401       | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 14800000  | Inner error. |
| 14800011  | Database corrupted. |
| 14800014  | Already closed. |
| 14800015  | The database does not respond.                 |
| 14800018  | No data meets the condition.                |
| 14800021  | SQLite: Generic error. |
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

let predicates = new relationalStore.RdbPredicates("EMPLOYEE");
predicates.equalTo("NAME", "Lisa");
if(store != undefined) {
  (store as relationalStore.RdbStore).unlockRow(predicates).then(() => {
    console.info(`Unlock success`);
  }).catch((err: BusinessError) => {
    console.error(`Unlock failed, code is ${err.code},message is ${err.message}`);
  })
}
```

### queryLockedRow<sup>12+</sup>

queryLockedRow(predicates: RdbPredicates, columns?: Array&lt;string&gt;):Promise&lt;ResultSet&gt;

Queries the locked data in this RDB store. This API uses a promise to return the result.
Due to the limit of the shared memory (max. 2 MB), a single data record cannot exceed 2 MB. Otherwise, the query operation will fail.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Parameters**

| Name    | Type                                | Mandatory| Description                                            |
| ---------- | ------------------------------------ | ---- | ------------------------------------------------ |
| predicates | [RdbPredicates](#rdbpredicates) | Yes  | Query conditions specified by the **RdbPredicates** object.       |
| columns    | Array&lt;string&gt;                  | No  | Columns to query. If this parameter is not specified, the query applies to all columns.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [RDB Store Error Codes](errorcode-data-rdb.md). For details about how to handle error 14800011, see [Database Backup and Restore](../../database/data-backup-and-restore.md).

| **ID**| **Error Message**                                                |
|-----------| ------------------------------------------------------------ |
| 401       | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 14800000  | Inner error. |
| 14800011  | Database corrupted. |
| 14800014  | Already closed. |
| 14800015  | The database does not respond.                 |
| 14800021  | SQLite: Generic error. |
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

**Return value**

| Type                                                   | Description                                              |
| ------------------------------------------------------- | -------------------------------------------------- |
| Promise&lt;[ResultSet](#resultset)&gt; | Promise used to return the result. If the operation is successful, a **ResultSet** object will be returned.|

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let predicates = new relationalStore.RdbPredicates("EMPLOYEE");
predicates.equalTo("NAME", "Rose");
if(store != undefined) {
  (store as relationalStore.RdbStore).queryLockedRow(predicates, ["ID", "NAME", "AGE", "SALARY", "CODES"]).then((resultSet: relationalStore.ResultSet) => {
    console.info(`ResultSet column names: ${resultSet.columnNames}, column count: ${resultSet.columnCount}`);
    // resultSet is a cursor of a data set. By default, the cursor points to the -1st record. Valid data starts from 0.
    while (resultSet.goToNextRow()) {
      const id = resultSet.getLong(resultSet.getColumnIndex("ID"));
      const name = resultSet.getString(resultSet.getColumnIndex("NAME"));
      const age = resultSet.getLong(resultSet.getColumnIndex("AGE"));
      const salary = resultSet.getDouble(resultSet.getColumnIndex("SALARY"));
      console.info(`id=${id}, name=${name}, age=${age}, salary=${salary}`);
    }
    // Release the memory of resultSet. If the memory is not released, FD or memory leaks may occur.
    resultSet.close();
  }).catch((err: BusinessError) => {
    console.error(`Query failed, code is ${err.code},message is ${err.message}`);
  })
}
```
### close<sup>12+</sup>

close(): Promise&lt;void&gt;

Closes this RDB store. This API uses a promise to return the result.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Return value**

| Type               | Description         |
| ------------------- | ------------- |
| Promise&lt;void&gt; | Promise used to|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [RDB Store Error Codes](errorcode-data-rdb.md).

| **ID**| **Error Message**                                   |
| ------------ | ----------------------------------------------- |
| 401          | Parameter error. The store must not be nullptr. |
| 14800000     | Inner error.                                    |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

if(store != undefined) {
    (store as relationalStore.RdbStore).close().then(() => {
        console.info(`close succeeded`);
    }).catch ((err: BusinessError) => {
        console.error(`close failed, code is ${err.code},message is ${err.message}`);
    })
}
```

## ResultSet

Provides APIs to access the **resultSet** object returned by **query()**.

### Usage

Obtain the **resultSet** object first.

**Example**

<!--code_no_check-->
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

### Properties

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

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [RDB Store Error Codes](errorcode-data-rdb.md). For details about how to handle error 14800011, see [Database Backup and Restore](../../database/data-backup-and-restore.md).

| **ID**| **Error Message**                                                |
|-----------| ------------------------------------------------------------ |
| 401       | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 14800000  | Inner error. |
| 14800011  | Database corrupted. |
| 14800013  | Column out of bounds. |
| 14800014  | Already closed. |
| 14800019  | The SQL must be a query statement. |
| 14800021  | SQLite: Generic error. |
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

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [RDB Store Error Codes](errorcode-data-rdb.md). For details about how to handle error 14800011, see [Database Backup and Restore](../../database/data-backup-and-restore.md).

| **ID**| **Error Message**                                                |
|-----------| ------------------------------------------------------------ |
| 401       | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 14800000  | Inner error. |
| 14800011  | Database corrupted. |
| 14800013  | Column out of bounds. |
| 14800014  | Already closed. |
| 14800019  | The SQL must be a query statement. |
| 14800021  | SQLite: Generic error. |
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

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [RDB Store Error Codes](errorcode-data-rdb.md). For details about how to handle error 14800011, see [Database Backup and Restore](../../database/data-backup-and-restore.md).

| **ID**| **Error Message**                                                |
|-----------| ------------------------------------------------------------ |
| 401       | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 14800000  | Inner error. |
| 14800011  | Database corrupted. |
| 14800012  | Row out of bounds. |
| 14800014  | Already closed. |
| 14800019  | The SQL must be a query statement. |
| 14800021  | SQLite: Generic error. |
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

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [RDB Store Error Codes](errorcode-data-rdb.md). For details about how to handle error 14800011, see [Database Backup and Restore](../../database/data-backup-and-restore.md).

| **ID**| **Error Message**                                                |
|-----------| ------------------------------------------------------------ |
| 401       | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 14800000  | Inner error. |
| 14800011  | Database corrupted. |
| 14800012  | Row out of bounds. |
| 14800014  | Already closed. |
| 14800019  | The SQL must be a query statement. |
| 14800021  | SQLite: Generic error. |
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

For details about the error codes, see [RDB Error Codes](errorcode-data-rdb.md). For details about how to handle error 14800011, see [Database Backup and Restore](../../database/data-backup-and-restore.md).

| **ID**| **Error Message**                                                |
|-----------| ------------------------------------------------------------ |
| 14800000  | Inner error. |
| 14800011  | Database corrupted. |
| 14800012  | Row out of bounds. |
| 14800014  | Already closed. |
| 14800019  | The SQL must be a query statement. |
| 14800021  | SQLite: Generic error. |
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

For details about the error codes, see [RDB Error Codes](errorcode-data-rdb.md). For details about how to handle error 14800011, see [Database Backup and Restore](../../database/data-backup-and-restore.md).

| **ID**| **Error Message**                                                |
|-----------| ------------------------------------------------------------ |
| 14800000  | Inner error. |
| 14800011  | Database corrupted. |
| 14800012  | Row out of bounds. |
| 14800014  | Already closed. |
| 14800019  | The SQL must be a query statement. |
| 14800021  | SQLite: Generic error. |
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

For details about the error codes, see [RDB Error Codes](errorcode-data-rdb.md). For details about how to handle error 14800011, see [Database Backup and Restore](../../database/data-backup-and-restore.md).

| **ID**| **Error Message**                                                |
|-----------| ------------------------------------------------------------ |
| 14800000  | Inner error. |
| 14800011  | Database corrupted. |
| 14800012  | Row out of bounds. |
| 14800014  | Already closed. |
| 14800019  | The SQL must be a query statement. |
| 14800021  | SQLite: Generic error. |
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

For details about the error codes, see [RDB Error Codes](errorcode-data-rdb.md). For details about how to handle error 14800011, see [Database Backup and Restore](../../database/data-backup-and-restore.md).

| **ID**| **Error Message**                                                |
|-----------| ------------------------------------------------------------ |
| 14800000  | Inner error. |
| 14800011  | Database corrupted. |
| 14800012  | Row out of bounds. |
| 14800014  | Already closed. |
| 14800019  | The SQL must be a query statement. |
| 14800021  | SQLite: Generic error. |
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
if(resultSet != undefined) {
  (resultSet as relationalStore.ResultSet).goToPreviousRow();
}
```

### getValue<sup>12+</sup>

getValue(columnIndex: number): ValueType

Obtains the value from the specified column and current row. If the value type is any of **ValueType**, the value of the corresponding type will be returned. Otherwise, **14800000** will be returned.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Parameters**

| Name     | Type  | Mandatory| Description                   |
| ----------- | ------ | ---- | ----------------------- |
| columnIndex | number | Yes  | Index of the target column, starting from 0.|

**Return value**

| Type      | Description                            |
| ---------- | -------------------------------- |
| [ValueType](#valuetype) | Value obtained. |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [RDB Store Error Codes](errorcode-data-rdb.md). For details about how to handle error 14800011, see [Database Backup and Restore](../../database/data-backup-and-restore.md).

| **ID**| **Error Message**    |
|-----------|---------|
| 401       | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 14800000  | Inner error.      |
| 14800011  | Database corrupted.        |
| 14800012  | Row out of bounds.       |
| 14800013  | Column out of bounds.   |
| 14800014  | Already closed.       |
| 14800021  | SQLite: Generic error.    |
| 14800022  | SQLite: Callback routine requested an abort.     |
| 14800023  | SQLite: Access permission denied.    |
| 14800024  | SQLite: The database file is locked.    |
| 14800025  | SQLite: A table in the database is locked.  |
| 14800026  | SQLite: The database is out of memory.    |
| 14800027  | SQLite: Attempt to write a readonly database.    |
| 14800028  | SQLite: Some kind of disk I/O error occurred.    |
| 14800029  | SQLite: The database is full.   |
| 14800030  | SQLite: Unable to open the database file.    |
| 14800031  | SQLite: TEXT or BLOB exceeds size limit.    |
| 14800032  | SQLite: Abort due to constraint violation.   |
| 14800033  | SQLite: Data type mismatch.      |
| 14800034  | SQLite: Library used incorrectly.    |

**Example**

```ts
if(resultSet != undefined) {
  const codes = (resultSet as relationalStore.ResultSet).getValue((resultSet as relationalStore.ResultSet).getColumnIndex("BIGINT_COLUMN"));
}
```

### getBlob

getBlob(columnIndex: number): Uint8Array


Obtains the value from the specified column and current row, and returns it in a byte array.<br>If the type of the value in the specified column is INTEGER, DOUBLE, TEXT, or BLOB, the value will be converted into a byte array and returned. If the column is empty, an empty byte array will be returned. If the value is of any other type, **14800000** will be returned.

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

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [RDB Store Error Codes](errorcode-data-rdb.md). For details about how to handle error 14800011, see [Database Backup and Restore](../../database/data-backup-and-restore.md).

| **ID**| **Error Message**                                                |
|-----------| ------------------------------------------------------------ |
| 401       | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 14800000  | Inner error. |
| 14800011  | Database corrupted. |
| 14800012  | Row out of bounds. |
| 14800013  | Column out of bounds. |
| 14800014  | Already closed. |
| 14800021  | SQLite: Generic error. |
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
if(resultSet != undefined) {
  const codes = (resultSet as relationalStore.ResultSet).getBlob((resultSet as relationalStore.ResultSet).getColumnIndex("CODES"));
}
```

### getString

getString(columnIndex: number): string

Obtains the value from the specified column and current row, and returns it in the form of a string.<br>If the type of the value in the specified column is INTEGER, DOUBLE, TEXT, or BLOB, a string will be returned. If the value type is INTEGER and the column is empty, an empty string will be returned. If the value is of any other type, **14800000** will be returned. If the value in the current column is of the DOUBLE type, the precision may be lost. You are advised to use [getDouble](#getdouble) to obtain the value.

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

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [RDB Store Error Codes](errorcode-data-rdb.md). For details about how to handle error 14800011, see [Database Backup and Restore](../../database/data-backup-and-restore.md).

| **ID**| **Error Message**                                                |
|-----------| ------------------------------------------------------------ |
| 401       | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 14800000  | Inner error. |
| 14800011  | Database corrupted. |
| 14800012  | Row out of bounds. |
| 14800013  | Column out of bounds. |
| 14800014  | Already closed. |
| 14800021  | SQLite: Generic error. |
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
if(resultSet != undefined) {
  const name = (resultSet as relationalStore.ResultSet).getString((resultSet as relationalStore.ResultSet).getColumnIndex("NAME"));
}
```

### getLong

getLong(columnIndex: number): number

Obtains the value from the specified column and current row, and returns a value of Long type.<br>If the type of the value in the specified column is INTEGER, DOUBLE, TEXT, or BLOB, a value of Long type will be returned. If the column is empty, **0** will be returned. If the value is of any other type, **14800000** will be returned.

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

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [RDB Store Error Codes](errorcode-data-rdb.md). For details about how to handle error 14800011, see [Database Backup and Restore](../../database/data-backup-and-restore.md).

| **ID**| **Error Message**                                                |
|-----------| ------------------------------------------------------------ |
| 401       | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 14800000  | Inner error. |
| 14800011  | Database corrupted. |
| 14800012  | Row out of bounds. |
| 14800013  | Column out of bounds. |
| 14800014  | Already closed. |
| 14800021  | SQLite: Generic error. |
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
if(resultSet != undefined) {
  const age = (resultSet as relationalStore.ResultSet).getLong((resultSet as relationalStore.ResultSet).getColumnIndex("AGE"));
 }
```

### getDouble

getDouble(columnIndex: number): number

Obtains the value from the specified column and current row, and returns a value of double type.<br>If the type of the value in the specified column is INTEGER, DOUBLE, TEXT, or BLOB, a value of double type will be returned. If the column is empty, **0.0** will be returned. If the value is of any other type, **14800000** will be returned.

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

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [RDB Store Error Codes](errorcode-data-rdb.md). For details about how to handle error 14800011, see [Database Backup and Restore](../../database/data-backup-and-restore.md).

| **ID**| **Error Message**                                                |
|-----------| ------------------------------------------------------------ |
| 401       | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 14800000  | Inner error. |
| 14800011  | Database corrupted. |
| 14800012  | Row out of bounds. |
| 14800013  | Column out of bounds. |
| 14800014  | Already closed. |
| 14800021  | SQLite: Generic error. |
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
if(resultSet != undefined) {
  const salary = (resultSet as relationalStore.ResultSet).getDouble((resultSet as relationalStore.ResultSet).getColumnIndex("SALARY"));
}
```

### getAsset<sup>10+</sup>

getAsset(columnIndex: number): Asset

Obtains the value from the specified column and current row, and returns the value in the [Asset](#asset10) format. If the type of the value in the column is **Asset**, the value of the Asset type is returned. If the value in the column is null, **null** is returned. If the value in the column is of other types, **14800000** is returned.

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

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [RDB Store Error Codes](errorcode-data-rdb.md). For details about how to handle error 14800011, see [Database Backup and Restore](../../database/data-backup-and-restore.md).

| **ID**| **Error Message**                                                |
|-----------| ------------------------------------------------------------ |
| 401       | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 14800000  | Inner error. |
| 14800011  | Database corrupted. |
| 14800012  | Row out of bounds. |
| 14800013  | Column out of bounds. |
| 14800014  | Already closed. |
| 14800021  | SQLite: Generic error. |
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
if(resultSet != undefined) {
  const doc = (resultSet as relationalStore.ResultSet).getAsset((resultSet as relationalStore.ResultSet).getColumnIndex("DOC"));
}
```

### getAssets<sup>10+</sup>

getAssets(columnIndex: number): Assets

Obtains the value from the specified column and current row, and returns the value in the [Assets](#assets10) format. If the type of the value in the column is **Assets**, the value of the Assets type is returned. If the value in the column is null, **null** is returned. If the value in the column is of other types, **14800000** is returned.

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

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [RDB Store Error Codes](errorcode-data-rdb.md). For details about how to handle error 14800011, see [Database Backup and Restore](../../database/data-backup-and-restore.md).

| **ID**| **Error Message**                                                |
|-----------| ------------------------------------------------------------ |
| 401       | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 14800000  | Inner error. |
| 14800011  | Database corrupted. |
| 14800012  | Row out of bounds. |
| 14800013  | Column out of bounds. |
| 14800014  | Already closed. |
| 14800021  | SQLite: Generic error. |
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
if(resultSet != undefined) {
  const docs = (resultSet as relationalStore.ResultSet).getAssets((resultSet as relationalStore.ResultSet).getColumnIndex("DOCS"));
}
```

### getRow<sup>11+</sup>

getRow(): ValuesBucket

Obtains the data in the current row.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Return value**

| Type             | Description                          |
| ---------------- | ---------------------------- |
| [ValuesBucket](#valuesbucket) | Data obtained.|

**Error codes**

For details about the error codes, see [RDB Error Codes](errorcode-data-rdb.md). For details about how to handle error 14800011, see [Database Backup and Restore](../../database/data-backup-and-restore.md).

| **ID**| **Error Message**                                                |
|-----------| ------------------------------------------------------------ |
| 14800000  | Inner error. |
| 14800011  | Database corrupted. |
| 14800012  | Row out of bounds. |
| 14800013  | Column out of bounds. |
| 14800014  | Already closed. |
| 14800021  | SQLite: Generic error. |
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
if(resultSet != undefined) {
  const row = (resultSet as relationalStore.ResultSet).getRow();
}
```

### getRows<sup>16+</sup>

getRows(maxCount: number, position?: number): Promise<Array\<ValuesBucket>>

Obtains a specified amount of data from the result set. This API uses a promise to return the result. Do not call this API concurrently with other APIs of [ResultSet](#resultset). Otherwise, unexpected data may be obtained.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Parameters**

| Name     | Type  | Mandatory| Description                   |
| ----------- | ------ | ---- | ----------------------- |
| maxCount | number | Yes  | Number of rows to obtain. The value is a positive integer. If the value is not a positive integer, error 401 will be thrown.|
| position | number | No  | Start position for obtaining data from the result set. The value is a non-negative integer. If this parameter is not specified, data is obtained from the current row of the result set (by default, it is the first row of the current result set when data is obtained for the first time). If it is not a non-negative integer, error 401 will be thrown.|


**Return value**

| Type             | Description                          |
| ---------------- | ---------------------------- |
| Promise<Array<[ValuesBucket](#valuesbucket)>> | Promise used to return **maxCount** rows of data obtained. If the number of remaining records is less than **maxCount**, the remaining records are returned. Returning an empty array indicates that the end of the result set is reached.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [RDB Store Error Codes](errorcode-data-rdb.md). For details about how to handle error 14800011, see [Database Backup and Restore](../../database/data-backup-and-restore.md).

| **ID**| **Error Message**                                                |
|-----------| ------------------------------------------------------------ |
| 401  | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 14800000  | Inner error. |
| 14800011  | Database corrupted. |
| 14800012  | Row out of bounds. |
| 14800013  | Column out of bounds. |
| 14800014  | Already closed. |
| 14800021  | SQLite: Generic error. |
| 14800022  | SQLite: Callback routine requested an abort. |
| 14800023  | SQLite: Access permission denied. |
| 14800024  | SQLite: The database file is locked. |
| 14800025  | SQLite: A table in the database is locked. |
| 14800026  | SQLite: The database is out of memory. |
| 14800028  | SQLite: Some kind of disk I/O error occurred. |
| 14800029  | SQLite: The database is full. |
| 14800031  | SQLite: TEXT or BLOB exceeds size limit. |
| 14800032  | SQLite: Abort due to constraint violation. |
| 14800033  | SQLite: Data type mismatch. |

**Example**

```ts
// Obtain 100 rows of data.
async function proccessRows(resultSet: relationalStore.ResultSet) {
  // Example 1: Specify only maxCount.
  if (resultSet != undefined) {
    let rows:Array<relationalStore.ValuesBucket>
    let maxCount:number = 50
    // Obtain data from the current row of the result set. By default, the first fetch starts from the first row of the current result set. Subsequent fetches start from the row following the last row retrieved.
    // getRows automatically moves the current row of the result set to the row following the last row retrieved by the previous getRows call. You do not need to use APIs such as goToFirstRow and goToNextRow.
    while ((rows = await (resultSet as relationalStore.ResultSet).getRows(maxCount)).length != 0) {
      console.info(JSON.stringify(rows[0]))
    }
  }

  // Example 2: Specify maxCount and position.
  if (resultSet != undefined) {
    let rows:Array<relationalStore.ValuesBucket>
    let maxCount:number = 50
    let position:number = 50
    while ((rows = await (resultSet as relationalStore.ResultSet).getRows(maxCount, position)).length != 0) {
      console.info(JSON.stringify(rows[0]))
      position += rows.length
    }
  }
}
```

### getSendableRow<sup>12+</sup>

getSendableRow(): sendableRelationalStore.ValuesBucket

Obtains the sendable data from the current row. The sendable data can be passed across threads.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Return value**

| Type                                                                                          | Description                                          |
| ---------------------------------------------------------------------------------------------- | ---------------------------------------------- |
| [sendableRelationalStore.ValuesBucket](./js-apis-data-sendableRelationalStore.md#valuesbucket) | Sendable data obtained for cross-thread transfer.|

**Error codes**

For details about the error codes, see [RDB Error Codes](errorcode-data-rdb.md). For details about how to handle error 14800011, see [Database Backup and Restore](../../database/data-backup-and-restore.md).

| **ID**| **Error Message**                                 |
| ------------ | --------------------------------------------- |
| 14800000     | Inner error.                                  |
| 14800011     | Database corrupted.                           |
| 14800012     | Row out of bounds.                            |
| 14800013     | Column out of bounds.                         |
| 14800014     | Already closed.                               |
| 14800021     | SQLite: Generic error.                        |
| 14800022     | SQLite: Callback routine requested an abort.  |
| 14800023     | SQLite: Access permission denied.             |
| 14800024     | SQLite: The database file is locked.          |
| 14800025     | SQLite: A table in the database is locked.    |
| 14800026     | SQLite: The database is out of memory.        |
| 14800027     | SQLite: Attempt to write a readonly database. |
| 14800028     | SQLite: Some kind of disk I/O error occurred. |
| 14800029     | SQLite: The database is full.                 |
| 14800030     | SQLite: Unable to open the database file.     |
| 14800031     | SQLite: TEXT or BLOB exceeds size limit.      |
| 14800032     | SQLite: Abort due to constraint violation.    |
| 14800033     | SQLite: Data type mismatch.                   |
| 14800034     | SQLite: Library used incorrectly.             |

**Example**

```ts
import { taskpool } from '@kit.ArkTS';
import type ctx from '@ohos.app.ability.common';
import { sendableRelationalStore } from '@kit.ArkData';

@Concurrent
async function getDataByName(name: string, context: ctx.UIAbilityContext) {
  const STORE_CONFIG: relationalStore.StoreConfig = {
    name: "RdbTest.db",
    securityLevel: relationalStore.SecurityLevel.S3
  };
  const store = await relationalStore.getRdbStore(context, STORE_CONFIG);
  const predicates = new relationalStore.RdbPredicates("EMPLOYEE");
  predicates.equalTo("NAME", name);
  const resultSet = store.querySync(predicates);

  if (resultSet.rowCount > 0) {
    resultSet.goToFirstRow();
    const sendableValuesBucket = resultSet.getSendableRow();
    return sendableValuesBucket;
  } else {
    return null;
  }
}

async function run() {
  const task = new taskpool.Task(getDataByName, 'Lisa', getContext());
  const sendableValuesBucket  = await taskpool.execute(task) as sendableRelationalStore.ValuesBucket;

  if (sendableValuesBucket) {
    const columnCount = sendableValuesBucket.size;
    const age = sendableValuesBucket.get('age');
    const name = sendableValuesBucket.get('name');
    console.info(`Query data in taskpool succeeded, name is "${name}", age is "${age}"`)
  }
}

run()
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

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [RDB Store Error Codes](errorcode-data-rdb.md). For details about how to handle error 14800011, see [Database Backup and Restore](../../database/data-backup-and-restore.md).

| **ID**| **Error Message**                                                |
|-----------| ------------------------------------------------------- |
| 401       | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 14800000  | Inner error. |
| 14800011  | Database corrupted. |
| 14800012  | Row out of bounds. |
| 14800013  | Column out of bounds. |
| 14800014  | Already closed. |
| 14800021  | SQLite: Generic error. |
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
if(resultSet != undefined) {
  const isColumnNull = (resultSet as relationalStore.ResultSet).isColumnNull((resultSet as relationalStore.ResultSet).getColumnIndex("CODES"));
}
```

### close

close(): void

Closes this **resultSet** to release memory. If the **resultSet** is not closed, FD or memory leaks may occur.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Example**

```ts
if(resultSet != undefined) {
  (resultSet as relationalStore.ResultSet).close();
}
```

**Error codes**

For details about the error codes, see [RDB Error Codes](errorcode-data-rdb.md).

| **ID**| **Error Message**                                                |
|-----------| ------------------------------------------------------------ |
| 14800000  | Inner error. |
| 14800012  | Row out of bounds. |

## Transaction<sup>14+</sup>

Provides API for managing databases in transaction mode. A transaction object is created by using [createTransaction](#createtransaction14). Operations on different transaction objects are isolated. For details about the transaction types, see [TransactionType](#transactiontype14).

Currently, an RDB store supports only one write transaction at a time. If the current [RdbStore](#rdbstore) has a write transaction that is not released, creating an **IMMEDIATE** or **EXCLUSIVE** transaction object will return error 14800024. If a **DEFERRED** transaction object is created, error 14800024 may be returned when it is used to invoke a write operation for the first time. After a write transaction is created using **IMMEDIATE** or **EXCLUSIVE**, or a **DEFERRED** transaction is upgraded to a write transaction, write operations in the [RdbStore](#rdbstore) will also return error 14800024.

When the number of concurrent transactions is large and the write transaction duration is long, the frequency of returning error 14800024 may increase. You can reduce the occurrence of error 14800024 by shortening the transaction duration or by handling the error 14800024 through retries.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let store: relationalStore.RdbStore | undefined = undefined;

if(store != undefined) {
  (store as relationalStore.RdbStore).createTransaction().then((transaction: relationalStore.Transaction) => {
    console.info(`createTransaction success`);
  }).catch((err: BusinessError) => {
    console.error(`createTransaction failed, code is ${err.code},message is ${err.message}`);
  });
}
```

### commit<sup>14+</sup>

commit(): Promise&lt;void&gt;

Commits the executed SQL statements. When using asynchronous APIs to execute SQL statements, ensure that **commit()** is called after the asynchronous API execution is completed. Otherwise, the SQL operations may be lost. After **commit()** is called, the transaction object and the created **ResultSet** object will be closed.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Return value**

| Type               | Description                     |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [RDB Store Error Codes](errorcode-data-rdb.md). For details about how to handle error 14800011, see [Database Backup and Restore](../../database/data-backup-and-restore.md).

| **ID**| **Error Message**                                                |
|-----------| ------------------------------------------------------------ |
| 14800000  | Inner error. |
| 14800011  | Database corrupted. |
| 14800014  | Already closed. |
| 14800023  | SQLite: Access permission denied. |
| 14800024  | SQLite: The database file is locked. |
| 14800026  | SQLite: The database is out of memory. |
| 14800027  | SQLite: Attempt to write a readonly database. |
| 14800028  | SQLite: Some kind of disk I/O error occurred. |
| 14800029  | SQLite: The database is full. |

**Example**

```ts
let value1 = "Lisa";
let value2 = 18;
let value3 = 100.5;
let value4 = new Uint8Array([1, 2, 3]);

if(store != undefined) {
  const valueBucket: relationalStore.ValuesBucket = {
    'NAME': value1,
    'AGE': value2,
    'SALARY': value3,
    'CODES': value4,
  };
  (store as relationalStore.RdbStore).createTransaction().then((transaction: relationalStore.Transaction) => {
    transaction.execute("DELETE FROM TEST WHERE age = ? OR age = ?", ["18", "20"]).then(() => {
      transaction.commit();
    }).catch((e: BusinessError) => {
      transaction.rollback();
      console.error(`execute sql failed, code is ${e.code},message is ${e.message}`);
    });
  }).catch((err: BusinessError) => {
    console.error(`createTransaction failed, code is ${err.code},message is ${err.message}`);
  });
}
```

### rollback<sup>14+</sup>

rollback(): Promise&lt;void&gt;

Rolls back the executed SQL statement. After **rollback()** is called, the transaction object and the created **ResultSet** object will be closed.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Return value**

| Type               | Description                     |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [RDB Store Error Codes](errorcode-data-rdb.md). For details about how to handle error 14800011, see [Database Backup and Restore](../../database/data-backup-and-restore.md).

| **ID**| **Error Message**                                                |
|-----------| ------------------------------------------------------------ |
| 14800000  | Inner error. |
| 14800011  | Database corrupted. |
| 14800014  | Already closed. |
| 14800023  | SQLite: Access permission denied. |
| 14800024  | SQLite: The database file is locked. |
| 14800026  | SQLite: The database is out of memory. |
| 14800027  | SQLite: Attempt to write a readonly database. |
| 14800028  | SQLite: Some kind of disk I/O error occurred. |
| 14800029  | SQLite: The database is full. |

**Example**

```ts
if(store != undefined) {
  (store as relationalStore.RdbStore).createTransaction().then((transaction: relationalStore.Transaction) => {
    transaction.execute("DELETE FROM TEST WHERE age = ? OR age = ?", ["18", "20"]).then(() => {
      transaction.commit();
    }).catch((e: BusinessError) => {
      transaction.rollback();
      console.error(`execute sql failed, code is ${e.code},message is ${e.message}`);
    });
  }).catch((err: BusinessError) => {
    console.error(`createTransaction failed, code is ${err.code},message is ${err.message}`);
  });
}

```

### insert<sup>14+</sup>

insert(table: string, values: ValuesBucket, conflict?: ConflictResolution): Promise&lt;number&gt;

Inserts a row of data into a table. This API uses a promise to return the result. Due to the limit of the shared memory (max. 2 MB), a single data record cannot exceed 2 MB. Otherwise, the query operation will fail.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Parameters**

| Name  | Type                                       | Mandatory| Description                      |
| -------- | ------------------------------------------- | ---- | -------------------------- |
| table    | string                                      | Yes  | Name of the target table.          |
| values   | [ValuesBucket](#valuesbucket)               | Yes  | Row of data to insert.|
| conflict | [ConflictResolution](#conflictresolution10) | No  | Resolution used to resolve the conflict. The default value is **relationalStore.ConflictResolution.ON_CONFLICT_NONE**.        |

**Return value**

| Type                 | Description                                             |
| --------------------- | ------------------------------------------------- |
| Promise&lt;number&gt; | Promise used to return the result. If the operation is successful, the row ID will be returned. Otherwise, **-1** will be returned.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [RDB Store Error Codes](errorcode-data-rdb.md). For details about how to handle error 14800011, see [Database Backup and Restore](../../database/data-backup-and-restore.md).

| **ID**| **Error Message**                                                |
|-----------| ------------------------------------------------------------ |
| 401       | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 14800000  | Inner error. |
| 14800011  | Database corrupted. |
| 14800014  | Already closed. |
| 14800021  | SQLite: Generic error. |
| 14800023  | SQLite: Access permission denied. |
| 14800024  | SQLite: The database file is locked. |
| 14800025  | SQLite: A table in the database is locked. |
| 14800026  | SQLite: The database is out of memory. |
| 14800027  | SQLite: Attempt to write a readonly database. |
| 14800028  | SQLite: Some kind of disk I/O error occurred. |
| 14800029  | SQLite: The database is full. |
| 14800031  | SQLite: TEXT or BLOB exceeds size limit. |
| 14800033  | SQLite: Data type mismatch. |
| 14800047  | The WAL file size exceeds the default limit. |

**Example**

```ts
let value1 = "Lisa";
let value2 = 18;
let value3 = 100.5;
let value4 = new Uint8Array([1, 2, 3, 4, 5]);

// You can use either of the following:
const valueBucket1: relationalStore.ValuesBucket = {
  'NAME': value1,
  'AGE': value2,
  'SALARY': value3,
  'CODES': value4,
};
const valueBucket2: relationalStore.ValuesBucket = {
  NAME: value1,
  AGE: value2,
  SALARY: value3,
  CODES: value4,
};
const valueBucket3: relationalStore.ValuesBucket = {
  "NAME": value1,
  "AGE": value2,
  "SALARY": value3,
  "CODES": value4,
};

if(store != undefined) {
  (store as relationalStore.RdbStore).createTransaction().then((transaction: relationalStore.Transaction) => {
    transaction.insert("EMPLOYEE", valueBucket1, relationalStore.ConflictResolution.ON_CONFLICT_REPLACE).then((rowId: number) => {
      transaction.commit();
      console.info(`Insert is successful, rowId = ${rowId}`);
    }).catch((e: BusinessError) => {
      transaction.rollback();
      console.error(`Insert is failed, code is ${e.code},message is ${e.message}`);
    });
  }).catch((err: BusinessError) => {
    console.error(`createTransaction failed, code is ${err.code},message is ${err.message}`);
  });
}
```

### insertSync<sup>14+</sup>

insertSync(table: string, values: ValuesBucket | sendableRelationalStore.ValuesBucket, conflict?: ConflictResolution): number

Inserts a row of data into a table. Due to the limit of the shared memory (max. 2 MB), a single data record cannot exceed 2 MB. Otherwise, the query operation will fail.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Parameters**

| Name  | Type                                       | Mandatory| Description                                                        |
| -------- | ------------------------------------------- | ---- | ------------------------------------------------------------ |
| table    | string                                      | Yes  | Name of the target table.                                            |
| values   | [ValuesBucket](#valuesbucket) \| [sendableRelationalStore.ValuesBucket](./js-apis-data-sendableRelationalStore.md#valuesbucket)   | Yes  | Row of data to insert.                                  |
| conflict | [ConflictResolution](#conflictresolution10) | No  | Resolution used to resolve the conflict. The default value is **relationalStore.ConflictResolution.ON_CONFLICT_NONE**.|

**Return value**

| Type  | Description                                |
| ------ | ------------------------------------ |
| number | If the operation is successful, the row ID will be returned. Otherwise, **-1** will be returned.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [RDB Store Error Codes](errorcode-data-rdb.md). For details about how to handle error 14800011, see [Database Backup and Restore](../../database/data-backup-and-restore.md).

| **ID**| **Error Message**                                                |
| ------------ | ------------------------------------------------------------ |
| 401          | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 14800000     | Inner error.                                                 |
| 14800011     | Database corrupted.                                          |
| 14800014     | Already closed.                                              |
| 14800021     | SQLite: Generic error.                                       |
| 14800023     | SQLite: Access permission denied.                            |
| 14800024     | SQLite: The database file is locked.                         |
| 14800025     | SQLite: A table in the database is locked.                   |
| 14800026     | SQLite: The database is out of memory.                       |
| 14800027     | SQLite: Attempt to write a readonly database.                |
| 14800028     | SQLite: Some kind of disk I/O error occurred.                |
| 14800029     | SQLite: The database is full.                                |
| 14800031     | SQLite: TEXT or BLOB exceeds size limit.                     |
| 14800033     | SQLite: Data type mismatch.                                  |
| 14800047     | The WAL file size exceeds the default limit.                 |

**Example**

```ts
let value1 = "Lisa";
let value2 = 18;
let value3 = 100.5;
let value4 = new Uint8Array([1, 2, 3, 4, 5]);

// You can use either of the following:
const valueBucket1: relationalStore.ValuesBucket = {
  'NAME': value1,
  'AGE': value2,
  'SALARY': value3,
  'CODES': value4,
};
const valueBucket2: relationalStore.ValuesBucket = {
  NAME: value1,
  AGE: value2,
  SALARY: value3,
  CODES: value4,
};
const valueBucket3: relationalStore.ValuesBucket = {
  "NAME": value1,
  "AGE": value2,
  "SALARY": value3,
  "CODES": value4,
};

if(store != undefined) {
  (store as relationalStore.RdbStore).createTransaction().then((transaction: relationalStore.Transaction) => {
    try {
      let rowId: number = (transaction as relationalStore.Transaction).insertSync("EMPLOYEE", valueBucket1, relationalStore.ConflictResolution.ON_CONFLICT_REPLACE);
      transaction.commit();
      console.info(`Insert is successful, rowId = ${rowId}`);
    } catch (e: BusinessError) {
      transaction.rollback();
      console.error(`Insert is failed, code is ${e.code},message is ${e.message}`);
    };
  }).catch((err: BusinessError) => {
    console.error(`createTransaction failed, code is ${err.code},message is ${err.message}`);
  });
}
```

### batchInsert<sup>14+</sup>

batchInsert(table: string, values: Array&lt;ValuesBucket&gt;): Promise&lt;number&gt;

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

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [RDB Store Error Codes](errorcode-data-rdb.md). For details about how to handle error 14800011, see [Database Backup and Restore](../../database/data-backup-and-restore.md).

| **ID**| **Error Message**                                                |
|-----------| ------------------------------------------------------------ |
| 401       | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 14800000  | Inner error. |
| 14800011  | Database corrupted. |
| 14800014  | Already closed. |
| 14800021  | SQLite: Generic error. |
| 14800023  | SQLite: Access permission denied. |
| 14800024  | SQLite: The database file is locked. |
| 14800025  | SQLite: A table in the database is locked. |
| 14800026  | SQLite: The database is out of memory. |
| 14800027  | SQLite: Attempt to write a readonly database. |
| 14800028  | SQLite: Some kind of disk I/O error occurred. |
| 14800029  | SQLite: The database is full. |
| 14800031  | SQLite: TEXT or BLOB exceeds size limit. |
| 14800033  | SQLite: Data type mismatch. |
| 14800047  | The WAL file size exceeds the default limit. |

**Example**

```ts
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

const valueBucket1: relationalStore.ValuesBucket = {
  'NAME': value1,
  'AGE': value2,
  'SALARY': value3,
  'CODES': value4,
};
const valueBucket2: relationalStore.ValuesBucket = {
  'NAME': value5,
  'AGE': value6,
  'SALARY': value7,
  'CODES': value8,
};
const valueBucket3: relationalStore.ValuesBucket = {
  'NAME': value9,
  'AGE': value10,
  'SALARY': value11,
  'CODES': value12,
};

let valueBuckets = new Array(valueBucket1, valueBucket2, valueBucket3);
if(store != undefined) {
  (store as relationalStore.RdbStore).createTransaction().then((transaction: relationalStore.Transaction) => {
    transaction.batchInsert("EMPLOYEE", valueBuckets).then((insertNum: number) => {
      transaction.commit();
      console.info(`batchInsert is successful, the number of values that were inserted = ${insertNum}`);
    }).catch((e: BusinessError) => {
      transaction.rollback();
      console.error(`batchInsert is failed, code is ${e.code},message is ${e.message}`);
    });
  }).catch((err: BusinessError) => {
    console.error(`createTransaction failed, code is ${err.code},message is ${err.message}`);
  });
}
```

### batchInsertSync<sup>14+</sup>

batchInsertSync(table: string, values: Array&lt;ValuesBucket&gt;): number

Inserts a group of data into a table.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Parameters**

| Name| Type                                      | Mandatory| Description                        |
| ------ | ------------------------------------------ | ---- | ---------------------------- |
| table  | string                                     | Yes  | Name of the target table.            |
| values | Array&lt;[ValuesBucket](#valuesbucket)&gt; | Yes  | An array of data to insert.|

**Return value**

| Type  | Description                                          |
| ------ | ---------------------------------------------- |
| number | If the operation is successful, the number of inserted data records is returned. Otherwise, **-1** is returned.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [RDB Store Error Codes](errorcode-data-rdb.md). For details about how to handle error 14800011, see [Database Backup and Restore](../../database/data-backup-and-restore.md).

| **ID**| **Error Message**                                                |
| ------------ | ------------------------------------------------------------ |
| 401          | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 14800000     | Inner error.                                                 |
| 14800011     | Database corrupted.                                          |
| 14800014     | Already closed.                                              |
| 14800021     | SQLite: Generic error.                                       |
| 14800023     | SQLite: Access permission denied.                            |
| 14800024     | SQLite: The database file is locked.                         |
| 14800025     | SQLite: A table in the database is locked.                   |
| 14800026     | SQLite: The database is out of memory.                       |
| 14800027     | SQLite: Attempt to write a readonly database.                |
| 14800028     | SQLite: Some kind of disk I/O error occurred.                |
| 14800029     | SQLite: The database is full.                                |
| 14800031     | SQLite: TEXT or BLOB exceeds size limit.                     |
| 14800033     | SQLite: Data type mismatch.                                  |
| 14800047     | The WAL file size exceeds the default limit.                 |

**Example**

```ts
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

const valueBucket1: relationalStore.ValuesBucket = {
  'NAME': value1,
  'AGE': value2,
  'SALARY': value3,
  'CODES': value4,
};
const valueBucket2: relationalStore.ValuesBucket = {
  'NAME': value5,
  'AGE': value6,
  'SALARY': value7,
  'CODES': value8,
};
const valueBucket3: relationalStore.ValuesBucket = {
  'NAME': value9,
  'AGE': value10,
  'SALARY': value11,
  'CODES': value12,
};

let valueBuckets = new Array(valueBucket1, valueBucket2, valueBucket3);
if(store != undefined) {
  (store as relationalStore.RdbStore).createTransaction().then((transaction: relationalStore.Transaction) => {
    try {
      let insertNum: number = (transaction as relationalStore.Transaction).batchInsertSync("EMPLOYEE", valueBuckets);
      transaction.commit();
      console.info(`batchInsert is successful, the number of values that were inserted = ${insertNum}`);
    } catch (e) {
      transaction.rollback();
      console.error(`batchInsert is failed, code is ${e.code},message is ${e.message}`);
    };
  }).catch((err: BusinessError) => {
    console.error(`createTransaction failed, code is ${err.code},message is ${err.message}`);
  });
}
```

### update<sup>14+</sup>

update(values: ValuesBucket, predicates: RdbPredicates, conflict?: ConflictResolution): Promise&lt;number&gt;

Updates data based on the specified **RdbPredicates** object. This API uses a promise to return the result. Due to the limit of the shared memory (max. 2 MB), a single data record cannot exceed 2 MB. Otherwise, the query operation will fail.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Parameters**

| Name    | Type                                       | Mandatory| Description                                                        |
| ---------- | ------------------------------------------- | ---- | ------------------------------------------------------------ |
| values     | [ValuesBucket](#valuesbucket)               | Yes  | Rows of data to update in the RDB store. The key-value pair is associated with the column name in the target table.|
| predicates | [RdbPredicates](#rdbpredicates)            | Yes  | Update conditions specified by the **RdbPredicates** object.                     |
| conflict   | [ConflictResolution](#conflictresolution10) | No  | Resolution used to resolve the conflict. The default value is **relationalStore.ConflictResolution.ON_CONFLICT_NONE**.                                         |

**Return value**

| Type                 | Description                                     |
| --------------------- | ----------------------------------------- |
| Promise&lt;number&gt; | Promise used to return the number of rows updated.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [RDB Store Error Codes](errorcode-data-rdb.md). For details about how to handle error 14800011, see [Database Backup and Restore](../../database/data-backup-and-restore.md).

| **ID**| **Error Message**                                                |
|-----------| ------------------------------------------------------------ |
| 401       | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 14800000  | Inner error. |
| 14800011  | Database corrupted. |
| 14800014  | Already closed. |
| 14800021  | SQLite: Generic error. |
| 14800023  | SQLite: Access permission denied. |
| 14800024  | SQLite: The database file is locked. |
| 14800025  | SQLite: A table in the database is locked. |
| 14800026  | SQLite: The database is out of memory. |
| 14800027  | SQLite: Attempt to write a readonly database. |
| 14800028  | SQLite: Some kind of disk I/O error occurred. |
| 14800029  | SQLite: The database is full. |
| 14800031  | SQLite: TEXT or BLOB exceeds size limit. |
| 14800033  | SQLite: Data type mismatch. |
| 14800047  | The WAL file size exceeds the default limit. |

**Example**

```ts
let value1 = "Rose";
let value2 = 22;
let value3 = 200.5;
let value4 = new Uint8Array([1, 2, 3, 4, 5]);

// You can use either of the following:
const valueBucket1: relationalStore.ValuesBucket = {
  'NAME': value1,
  'AGE': value2,
  'SALARY': value3,
  'CODES': value4,
};
const valueBucket2: relationalStore.ValuesBucket = {
  NAME: value1,
  AGE: value2,
  SALARY: value3,
  CODES: value4,
};
const valueBucket3: relationalStore.ValuesBucket = {
  "NAME": value1,
  "AGE": value2,
  "SALARY": value3,
  "CODES": value4,
};

let predicates = new relationalStore.RdbPredicates('EMPLOYEE');
predicates.equalTo("NAME", "Lisa");

if(store != undefined) {
  (store as relationalStore.RdbStore).createTransaction().then((transaction: relationalStore.Transaction) => {
    transaction.update(valueBucket1, predicates, relationalStore.ConflictResolution.ON_CONFLICT_REPLACE).then(async (rows: Number) => {
      transaction.commit();
      console.info(`Updated row count: ${rows}`);
    }).catch((e: BusinessError) => {
      transaction.rollback();
      console.error(`Updated failed, code is ${e.code},message is ${e.message}`);
    });
  }).catch((err: BusinessError) => {
    console.error(`createTransaction failed, code is ${err.code},message is ${err.message}`);
  });
}
```

### updateSync<sup>14+</sup>

updateSync(values: ValuesBucket, predicates: RdbPredicates, conflict?: ConflictResolution): number

Updates data in the database based on the specified **RdbPredicates** instance. Due to the limit of the shared memory (max. 2 MB), a single data record cannot exceed 2 MB. Otherwise, the query operation will fail.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Parameters**

| Name    | Type                                       | Mandatory| Description                                                        |
| ---------- | ------------------------------------------- | ---- | ------------------------------------------------------------ |
| values     | [ValuesBucket](#valuesbucket)               | Yes  | Rows of data to update in the RDB store. The key-value pair is associated with the column name in the target table.|
| predicates | [RdbPredicates](#rdbpredicates)             | Yes  | Update conditions specified by the **RdbPredicates** object.                     |
| conflict   | [ConflictResolution](#conflictresolution10) | No  | Resolution used to resolve the conflict. The default value is **relationalStore.ConflictResolution.ON_CONFLICT_NONE**.|

**Return value**

| Type  | Description              |
| ------ | ------------------ |
| number | return the number of rows updated.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [RDB Store Error Codes](errorcode-data-rdb.md). For details about how to handle error 14800011, see [Database Backup and Restore](../../database/data-backup-and-restore.md).

| **ID**| **Error Message**                                                |
| ------------ | ------------------------------------------------------------ |
| 401          | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 14800000     | Inner error.                                                 |
| 14800011     | Database corrupted.                                          |
| 14800014     | Already closed.                                              |
| 14800021     | SQLite: Generic error.                                       |
| 14800023     | SQLite: Access permission denied.                            |
| 14800024     | SQLite: The database file is locked.                         |
| 14800025     | SQLite: A table in the database is locked.                   |
| 14800026     | SQLite: The database is out of memory.                       |
| 14800027     | SQLite: Attempt to write a readonly database.                |
| 14800028     | SQLite: Some kind of disk I/O error occurred.                |
| 14800029     | SQLite: The database is full.                                |
| 14800031     | SQLite: TEXT or BLOB exceeds size limit.                     |
| 14800033     | SQLite: Data type mismatch.                                  |
| 14800047     | The WAL file size exceeds the default limit.                 |

**Example**

```ts
let value1 = "Rose";
let value2 = 22;
let value3 = 200.5;
let value4 = new Uint8Array([1, 2, 3, 4, 5]);

// You can use either of the following:
const valueBucket1: relationalStore.ValuesBucket = {
  'NAME': value1,
  'AGE': value2,
  'SALARY': value3,
  'CODES': value4,
};
const valueBucket2: relationalStore.ValuesBucket = {
  NAME: value1,
  AGE: value2,
  SALARY: value3,
  CODES: value4,
};
const valueBucket3: relationalStore.ValuesBucket = {
  "NAME": value1,
  "AGE": value2,
  "SALARY": value3,
  "CODES": value4,
};

let predicates = new relationalStore.RdbPredicates("EMPLOYEE");
predicates.equalTo("NAME", "Lisa");

if(store != undefined) {
  (store as relationalStore.RdbStore).createTransaction().then((transaction: relationalStore.Transaction) => {
    try {
      let rows: Number = (transaction as relationalStore.Transaction).updateSync(valueBucket1, predicates, relationalStore.ConflictResolution.ON_CONFLICT_REPLACE);
      transaction.commit();
      console.info(`Updated row count: ${rows}`);
    } catch (e) {
      transaction.rollback();
      console.error(`Updated failed, code is ${e.code},message is ${e.message}`);
    };
  }).catch((err: BusinessError) => {
    console.error(`createTransaction failed, code is ${err.code},message is ${err.message}`);
  });
}
```

### delete<sup>14+</sup>

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

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [RDB Store Error Codes](errorcode-data-rdb.md). For details about how to handle error 14800011, see [Database Backup and Restore](../../database/data-backup-and-restore.md).

| **ID**| **Error Message**                                                |
|-----------| ------------------------------------------------------------ |
| 401       | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 14800000  | Inner error. |
| 14800011  | Database corrupted. |
| 14800014  | Already closed. |
| 14800021  | SQLite: Generic error. |
| 14800023  | SQLite: Access permission denied. |
| 14800024  | SQLite: The database file is locked. |
| 14800025  | SQLite: A table in the database is locked. |
| 14800026  | SQLite: The database is out of memory. |
| 14800027  | SQLite: Attempt to write a readonly database. |
| 14800028  | SQLite: Some kind of disk I/O error occurred. |
| 14800029  | SQLite: The database is full. |
| 14800031  | SQLite: TEXT or BLOB exceeds size limit. |
| 14800033  | SQLite: Data type mismatch. |
| 14800047  | The WAL file size exceeds the default limit. |

**Example**

```ts
let predicates = new relationalStore.RdbPredicates("EMPLOYEE");
predicates.equalTo("NAME", "Lisa");

if(store != undefined) {
  (store as relationalStore.RdbStore).createTransaction().then((transaction: relationalStore.Transaction) => {
    transaction.delete(predicates).then((rows: Number) => {
      transaction.commit();
      console.info(`Delete rows: ${rows}`);
    }).catch((e: BusinessError) => {
      transaction.rollback();
      console.error(`Delete failed, code is ${e.code},message is ${e.message}`);
    });
  }).catch((err: BusinessError) => {
    console.error(`createTransaction failed, code is ${err.code},message is ${err.message}`);
  });
}
```

### deleteSync<sup>14+</sup>

deleteSync(predicates: RdbPredicates): number

Deletes data from the database based on the specified **RdbPredicates** object.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Parameters**

| Name    | Type                           | Mandatory| Description                                   |
| ---------- | ------------------------------- | ---- | --------------------------------------- |
| predicates | [RdbPredicates](#rdbpredicates) | Yes  | Conditions specified by the **RdbPredicates** object for deleting data.|

**Return value**

| Type  | Description              |
| ------ | ------------------ |
| number | return the number of rows updated.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [RDB Store Error Codes](errorcode-data-rdb.md). For details about how to handle error 14800011, see [Database Backup and Restore](../../database/data-backup-and-restore.md).

| **ID**| **Error Message**                                                |
| ------------ | ------------------------------------------------------------ |
| 401          | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 14800000  | Inner error. |
| 14800011  | Database corrupted. |
| 14800014  | Already closed. |
| 14800021  | SQLite: Generic error. |
| 14800023  | SQLite: Access permission denied. |
| 14800024  | SQLite: The database file is locked. |
| 14800025  | SQLite: A table in the database is locked. |
| 14800026  | SQLite: The database is out of memory. |
| 14800027  | SQLite: Attempt to write a readonly database. |
| 14800028  | SQLite: Some kind of disk I/O error occurred. |
| 14800029  | SQLite: The database is full. |
| 14800031  | SQLite: TEXT or BLOB exceeds size limit. |
| 14800033  | SQLite: Data type mismatch. |
| 14800047  | The WAL file size exceeds the default limit. |

**Example**

```ts
let predicates = new relationalStore.RdbPredicates("EMPLOYEE");
predicates.equalTo("NAME", "Lisa");

if(store != undefined) {
  (store as relationalStore.RdbStore).createTransaction().then((transaction: relationalStore.Transaction) => {
    try {
      let rows: Number = (transaction as relationalStore.Transaction).deleteSync(predicates);
      transaction.commit();
      console.info(`Delete rows: ${rows}`);
    } catch (e) {
      transaction.rollback();
      console.error(`Delete failed, code is ${e.code},message is ${e.message}`);
    };
  }).catch((err: BusinessError) => {
    console.error(`createTransaction failed, code is ${err.code},message is ${err.message}`);
  });
}
```

### query<sup>14+</sup>

query(predicates: RdbPredicates, columns?: Array&lt;string&gt;): Promise&lt;ResultSet&gt;

Queries data from the RDB store based on specified conditions. This API uses a promise to return the result. Due to the limit of the shared memory (max. 2 MB), a single data record cannot exceed 2 MB. Otherwise, the query operation will fail.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Parameters**

| Name    | Type                                | Mandatory| Description                                            |
| ---------- | ------------------------------------ | ---- | ------------------------------------------------ |
| predicates | [RdbPredicates](#rdbpredicates) | Yes  | Query conditions specified by the **RdbPredicates** object.       |
| columns    | Array&lt;string&gt;                  | No  | Columns to query. If this parameter is not specified, the query applies to all columns.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [RDB Store Error Codes](errorcode-data-rdb.md).

| **ID**| **Error Message**                                                |
|-----------| ------------------------------------------------------------ |
| 401       | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 14800000  | Inner error. |
| 14800011  | Database corrupted. |
| 14800014  | Already closed. |
| 14800021  | SQLite: Generic error. |
| 14800023  | SQLite: Access permission denied. |
| 14800024  | SQLite: The database file is locked. |
| 14800026  | SQLite: The database is out of memory. |
| 14800028  | SQLite: Some kind of disk I/O error occurred. |
| 14800047  | The WAL file size exceeds the default limit. |

**Return value**

| Type                                                   | Description                                              |
| ------------------------------------------------------- | -------------------------------------------------- |
| Promise&lt;[ResultSet](#resultset)&gt; | Promise used to return the result. If the operation is successful, a **ResultSet** object will be returned.|

**Example**

```ts
let predicates = new relationalStore.RdbPredicates("EMPLOYEE");
predicates.equalTo("NAME", "Rose");

if(store != undefined) {
  (store as relationalStore.RdbStore).createTransaction().then((transaction: relationalStore.Transaction) => {
    transaction.query(predicates, ["ID", "NAME", "AGE", "SALARY", "CODES"]).then((resultSet: relationalStore.ResultSet) => {
      console.info(`ResultSet column names: ${resultSet.columnNames}, column count: ${resultSet.columnCount}`);
      // resultSet is a cursor of a data set. By default, the cursor points to the -1st record. Valid data starts from 0.
      while (resultSet.goToNextRow()) {
        const id = resultSet.getLong(resultSet.getColumnIndex("ID"));
        const name = resultSet.getString(resultSet.getColumnIndex("NAME"));
        const age = resultSet.getLong(resultSet.getColumnIndex("AGE"));
        const salary = resultSet.getDouble(resultSet.getColumnIndex("SALARY"));
        console.info(`id=${id}, name=${name}, age=${age}, salary=${salary}`);
      }
      // Release the memory of resultSet. If the memory is not released, FD or memory leaks may occur.
      resultSet.close();
      transaction.commit();
    }).catch((e: BusinessError) => {
      transaction.rollback();
      console.error(`Query failed, code is ${e.code},message is ${e.message}`);
    });
  }).catch((err: BusinessError) => {
    console.error(`createTransaction failed, code is ${err.code},message is ${err.message}`);
  });
}
```

### querySync<sup>14+</sup>

querySync(predicates: RdbPredicates, columns?: Array&lt;string&gt;): ResultSet

Queries data in a database based on specified conditions. This API returns the result synchronously. If complex logic and a large number of loops are involved in the operations on the **resultSet** obtained by **querySync()**, the freeze problem may occur. You are advised to perform this operation in the [taskpool](../apis-arkts/js-apis-taskpool.md) thread.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Parameters**

| Name    | Type                           | Mandatory| Description                                                        |
| ---------- | ------------------------------- | ---- | ------------------------------------------------------------ |
| predicates | [RdbPredicates](#rdbpredicates) | Yes  | Query conditions specified by the **RdbPredicates** object.                     |
| columns    | Array&lt;string&gt;             | No  | Columns to query. If this parameter is not specified, the query applies to all columns. The default value is null.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [RDB Store Error Codes](errorcode-data-rdb.md).

| **ID**| **Error Message**                                                |
| ------------ | ------------------------------------------------------------ |
| 401          | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 14800000  | Inner error. |
| 14800011  | Database corrupted. |
| 14800014  | Already closed. |
| 14800021  | SQLite: Generic error. |
| 14800023  | SQLite: Access permission denied. |
| 14800024  | SQLite: The database file is locked. |
| 14800025  | SQLite: A table in the database is locked. |
| 14800026  | SQLite: The database is out of memory. |
| 14800028  | SQLite: Some kind of disk I/O error occurred. |
| 14800047  | The WAL file size exceeds the default limit. |

**Return value**

| Type                   | Description                               |
| ----------------------- | ----------------------------------- |
| [ResultSet](#resultset) | If the operation is successful, a **ResultSet** object will be returned.|

**Example**

```ts
let predicates = new relationalStore.RdbPredicates("EMPLOYEE");
predicates.equalTo("NAME", "Rose");

if(store != undefined) {
  (store as relationalStore.RdbStore).createTransaction().then((transaction: relationalStore.Transaction) => {
    try {
      let resultSet: relationalStore.ResultSet = (transaction as relationalStore.Transaction).querySync(predicates, ["ID", "NAME", "AGE", "SALARY", "CODES"]);
      console.info(`ResultSet column names: ${resultSet.columnNames}, column count: ${resultSet.columnCount}`);
      // resultSet is a cursor of a data set. By default, the cursor points to the -1st record. Valid data starts from 0.
      while (resultSet.goToNextRow()) {
        const id = resultSet.getLong(resultSet.getColumnIndex("ID"));
        const name = resultSet.getString(resultSet.getColumnIndex("NAME"));
        const age = resultSet.getLong(resultSet.getColumnIndex("AGE"));
        const salary = resultSet.getDouble(resultSet.getColumnIndex("SALARY"));
        console.info(`id=${id}, name=${name}, age=${age}, salary=${salary}`);
      }
      // Release the memory of resultSet. If the memory is not released, FD or memory leaks may occur.
      resultSet.close();
      transaction.commit();
    } catch (e) {
      transaction.rollback();
      console.error(`Query failed, code is ${e.code},message is ${e.message}`);
    };
  }).catch((err: BusinessError) => {
    console.error(`createTransaction failed, code is ${err.code},message is ${err.message}`);
  });
}
```

### querySql<sup>14+</sup>

querySql(sql: string, args?: Array&lt;ValueType&gt;): Promise&lt;ResultSet&gt;

Queries data in the RDB store using the specified SQL statement. The number of relational operators between expressions and operators in the SQL statement cannot exceed 1000. This API uses a promise to return the result.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Parameters**

| Name  | Type                                | Mandatory| Description                                                        |
| -------- | ------------------------------------ | ---- | ------------------------------------------------------------ |
| sql      | string                               | Yes  | SQL statement to run.                                       |
| args | Array&lt;[ValueType](#valuetype)&gt; | No  | Arguments in the SQL statement. The value corresponds to the placeholders in the SQL parameter statement. If the SQL parameter statement is complete, leave this parameter blank.|

**Return value**

| Type                                                   | Description                                              |
| ------------------------------------------------------- | -------------------------------------------------- |
| Promise&lt;[ResultSet](#resultset)&gt; | Promise used to return the result. If the operation is successful, a **ResultSet** object will be returned.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [RDB Store Error Codes](errorcode-data-rdb.md).

| **ID**| **Error Message**                                                |
|-----------| ------------------------------------------------------------ |
| 401       | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 14800000  | Inner error. |
| 14800011  | Database corrupted. |
| 14800014  | Already closed. |
| 14800021  | SQLite: Generic error. |
| 14800023  | SQLite: Access permission denied. |
| 14800024  | SQLite: The database file is locked. |
| 14800025  | SQLite: A table in the database is locked. |
| 14800026  | SQLite: The database is out of memory. |
| 14800028  | SQLite: Some kind of disk I/O error occurred. |
| 14800047  | The WAL file size exceeds the default limit. |

**Example**

```ts
if(store != undefined) {
  (store as relationalStore.RdbStore).createTransaction().then((transaction: relationalStore.Transaction) => {
    transaction.querySql("SELECT * FROM EMPLOYEE CROSS JOIN BOOK WHERE BOOK.NAME = 'sanguo'").then((resultSet: relationalStore.ResultSet) => {
      console.info(`ResultSet column names: ${resultSet.columnNames}, column count: ${resultSet.columnCount}`);
      // resultSet is a cursor of a data set. By default, the cursor points to the -1st record. Valid data starts from 0.
      while (resultSet.goToNextRow()) {
        const id = resultSet.getLong(resultSet.getColumnIndex("ID"));
        const name = resultSet.getString(resultSet.getColumnIndex("NAME"));
        const age = resultSet.getLong(resultSet.getColumnIndex("AGE"));
        const salary = resultSet.getDouble(resultSet.getColumnIndex("SALARY"));
        console.info(`id=${id}, name=${name}, age=${age}, salary=${salary}`);
      }
      // Release the memory of resultSet. If the memory is not released, FD or memory leaks may occur.
      resultSet.close();
      transaction.commit();
    }).catch((e: BusinessError) => {
      transaction.rollback();
      console.error(`Query failed, code is ${e.code},message is ${e.message}`);
    });
  }).catch((err: BusinessError) => {
    console.error(`createTransaction failed, code is ${err.code},message is ${err.message}`);
  });
}
```

### querySqlSync<sup>14+</sup>

querySqlSync(sql: string, args?: Array&lt;ValueType&gt;): ResultSet

Queries data in the RDB store using the specified SQL statement. The number of relational operators between expressions and operators in the SQL statement cannot exceed 1000. If complex logic and a large number of loops are involved in the operations on the **resultSet** obtained by **querySync()**, the freeze problem may occur. You are advised to perform this operation in the [taskpool](../apis-arkts/js-apis-taskpool.md) thread.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Parameters**

| Name  | Type                                | Mandatory| Description                                                        |
| -------- | ------------------------------------ | ---- | ------------------------------------------------------------ |
| sql      | string                               | Yes  | SQL statement to run.                                       |
| args | Array&lt;[ValueType](#valuetype)&gt; | No  | Arguments in the SQL statement. The value corresponds to the placeholders in the SQL parameter statement. If the SQL parameter statement is complete, leave this parameter blank. The default value is null.|

**Return value**

| Type                   | Description                               |
| ----------------------- | ----------------------------------- |
| [ResultSet](#resultset) | If the operation is successful, a **ResultSet** object will be returned.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [RDB Store Error Codes](errorcode-data-rdb.md).

| **ID**| **Error Message**                                                |
| ------------ | ------------------------------------------------------------ |
| 401          | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 14800000  | Inner error. |
| 14800011  | Database corrupted. |
| 14800014  | Already closed. |
| 14800021  | SQLite: Generic error. |
| 14800023  | SQLite: Access permission denied. |
| 14800024  | SQLite: The database file is locked. |
| 14800025  | SQLite: A table in the database is locked. |
| 14800026  | SQLite: The database is out of memory. |
| 14800028  | SQLite: Some kind of disk I/O error occurred. |
| 14800047  | The WAL file size exceeds the default limit. |

**Example**

```ts
if(store != undefined) {
  (store as relationalStore.RdbStore).createTransaction().then((transaction: relationalStore.Transaction) => {
    try {
      let resultSet: relationalStore.ResultSet = (transaction as relationalStore.Transaction).querySqlSync("SELECT * FROM EMPLOYEE CROSS JOIN BOOK WHERE BOOK.NAME = 'sanguo'");
      console.info(`ResultSet column names: ${resultSet.columnNames}, column count: ${resultSet.columnCount}`);
      // resultSet is a cursor of a data set. By default, the cursor points to the -1st record. Valid data starts from 0.
      while (resultSet.goToNextRow()) {
        const id = resultSet.getLong(resultSet.getColumnIndex("ID"));
        const name = resultSet.getString(resultSet.getColumnIndex("NAME"));
        const age = resultSet.getLong(resultSet.getColumnIndex("AGE"));
        const salary = resultSet.getDouble(resultSet.getColumnIndex("SALARY"));
        console.info(`id=${id}, name=${name}, age=${age}, salary=${salary}`);
      }
      // Release the memory of resultSet. If the memory is not released, FD or memory leaks may occur.
      resultSet.close();
      transaction.commit();
    } catch (e) {
      transaction.rollback();
      console.error(`Query failed, code is ${e.code},message is ${e.message}`);
    };
  }).catch((err: BusinessError) => {
    console.error(`createTransaction failed, code is ${err.code},message is ${err.message}`);
  });
}
```

### execute<sup>14+</sup>

execute(sql: string, args?: Array&lt;ValueType&gt;): Promise&lt;ValueType&gt;

Executes an SQL statement that contains specified arguments. The number of relational operators between expressions and operators in the statement cannot exceed 1000. This API uses a promise to return a value of the ValueType type.

This API can be used to add, delete, and modify data, run SQL statements of the PRAGMA syntax, and create, delete, and modify a table. The type of the return value varies, depending on the execution result.

This API does not support query, database attachment, and transaction operations. You can use [querySql](#querysql14) or [query](#query14) to query data, and use [attach](#attach12) to attach a database.

Statements separated by semicolons (\;) are not supported.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Parameters**

| Name  | Type                                | Mandatory| Description                                                        |
| -------- | ------------------------------------ | ---- | ------------------------------------------------------------ |
| sql      | string                               | Yes  | SQL statement to run.                                       |
| args | Array&lt;[ValueType](#valuetype)&gt; | No  | Arguments in the SQL statement. The value corresponds to the placeholders in the SQL parameter statement. If the SQL parameter statement is complete, leave this parameter blank.|

**Return value**

| Type               | Description                     |
| ------------------- | ------------------------- |
| Promise&lt;[ValueType](#valuetype)&gt; | Promise used to return the SQL execution result.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [RDB Store Error Codes](errorcode-data-rdb.md). For details about how to handle error 14800011, see [Database Backup and Restore](../../database/data-backup-and-restore.md).

| **ID**| **Error Message**                                                |
|-----------| ------------------------------------------------------------ |
| 401       | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 801       | Capability not supported the sql(attach,begin,commit,rollback etc.). |
| 14800000  | Inner error. |
| 14800011  | Database corrupted. |
| 14800014  | Already closed. |
| 14800021  | SQLite: Generic error. |
| 14800023  | SQLite: Access permission denied. |
| 14800024  | SQLite: The database file is locked. |
| 14800025  | SQLite: A table in the database is locked. |
| 14800026  | SQLite: The database is out of memory. |
| 14800027  | SQLite: Attempt to write a readonly database. |
| 14800028  | SQLite: Some kind of disk I/O error occurred. |
| 14800029  | SQLite: The database is full. |
| 14800031  | SQLite: TEXT or BLOB exceeds size limit. |
| 14800033  | SQLite: Data type mismatch. |
| 14800047  | The WAL file size exceeds the default limit. |

**Example**

```ts
// Delete all data from the table.
if(store != undefined) {
  const SQL_DELETE_TABLE = 'DELETE FROM test';
  (store as relationalStore.RdbStore).createTransaction().then((transaction: relationalStore.Transaction) => {
    transaction.execute(SQL_DELETE_TABLE).then((data) => {
      transaction.commit();
      console.info(`delete result: ${data}`);
    }).catch((e: BusinessError) => {
      transaction.rollback();
      console.error(`delete failed, code is ${e.code}, message is ${e.message}`);
    });
  }).catch((err: BusinessError) => {
    console.error(`createTransaction failed, code is ${err.code},message is ${err.message}`);
  });
}
```

### executeSync<sup>14+</sup>

executeSync(sql: string, args?: Array&lt;ValueType&gt;): ValueType

Executes an SQL statement that contains specified arguments. The number of relational operators between expressions and operators in the statement cannot exceed 1000. This API returns a value of theValueType type.

This API can be used to add, delete, and modify data, run SQL statements of the PRAGMA syntax, and create, delete, and modify a table. The type of the return value varies, depending on the execution result.

This API does not support query, database attachment, and transaction operations. You can use [querySql](#querysql14) or [query](#query14) to query data, and use [attach](#attach12) to attach a database.

Statements separated by semicolons (\;) are not supported.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Parameters**

| Name| Type                                | Mandatory| Description                                                        |
| ------ | ------------------------------------ | ---- | ------------------------------------------------------------ |
| sql    | string                               | Yes  | SQL statement to run.                                       |
| args   | Array&lt;[ValueType](#valuetype)&gt; | No  | Arguments in the SQL statement. The value corresponds to the placeholders in the SQL parameter statement. If this parameter is left blank or set to **null** or **undefined**, the SQL statement is complete. The default value is null.|

**Return value**

| Type                   | Description               |
| ----------------------- | ------------------- |
| [ValueType](#valuetype) | SQL execution result.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [RDB Store Error Codes](errorcode-data-rdb.md). For details about how to handle error 14800011, see [Database Backup and Restore](../../database/data-backup-and-restore.md).

| **ID**| **Error Message**                                                |
| ------------ | ------------------------------------------------------------ |
| 401          | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 801       | Capability not supported the sql(attach,begin,commit,rollback etc.). |
| 14800000     | Inner error.                                                 |
| 14800011     | Database corrupted.                                          |
| 14800014     | Already closed.                                              |
| 14800021     | SQLite: Generic error.                                       |
| 14800023     | SQLite: Access permission denied.                            |
| 14800024     | SQLite: The database file is locked.                         |
| 14800025     | SQLite: A table in the database is locked.                   |
| 14800026     | SQLite: The database is out of memory.                       |
| 14800027     | SQLite: Attempt to write a readonly database.                |
| 14800028     | SQLite: Some kind of disk I/O error occurred.                |
| 14800029     | SQLite: The database is full.                                |
| 14800031     | SQLite: TEXT or BLOB exceeds size limit.                     |
| 14800033     | SQLite: Data type mismatch.                                  |
| 14800047     | The WAL file size exceeds the default limit.                 |

**Example**

```ts
// Delete all data from the table.
if(store != undefined) {
  (store as relationalStore.RdbStore).createTransaction().then((transaction: relationalStore.Transaction) => {
    const SQL_DELETE_TABLE = 'DELETE FROM test';
    try {
      let data = (transaction as relationalStore.Transaction).executeSync(SQL_DELETE_TABLE);
      transaction.commit();
      console.info(`delete result: ${data}`);
    } catch (e) {
      transaction.rollback();
      console.error(`delete failed, code is ${e.code}, message is ${e.message}`);
    };
  }).catch((err: BusinessError) => {
    console.error(`createTransaction failed, code is ${err.code},message is ${err.message}`);
  });
}
```
