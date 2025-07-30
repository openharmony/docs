# Functions

> **NOTE**
> 
> The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Module to Import

```ts
import { relationalStore } from '@kit.ArkData';
```

## relationalStore.getRdbStore

getRdbStore(context: Context, config: StoreConfig, callback: AsyncCallback&lt;RdbStore&gt;): void

Obtains an RdbStore instance. You can set the **config** parameter as required and use **RdbStore** APIs to perform data operations. This API uses an asynchronous callback to return the result.

If no database file exists in the corresponding sandbox directory, a database file is created. For details, see [StoreConfig](arkts-apis-data-relationalStore-i.md#storeconfig). If a database file exists in the corresponding directory, the existing database file is opened.

When creating a database, you should consider whether to configure the [encrypt](arkts-apis-data-relationalStore-i.md#storeconfig) parameter. Once the database is created, you are not allowed to change this parameter.

| Encryption Type When the RDB Store Is Opened | Encryption Type When the RDB Store Is Created          | Result|
| ------- | -------------------------------- | ---- |
| Non-encryption| Encryption                         | The RDB store is opened in encrypted mode.  |
| Encryption| Non-encryption                         | The RDB store is opened in non-encrypted mode.  |

Currently, **getRdbStore()** does not support multi-thread concurrent operations.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Parameters**

| Name  | Type                                          | Mandatory| Description                                                        |
| -------- | ---------------------------------------------- | ---- | ------------------------------------------------------------ |
| context  | Context                                        | Yes  | Application context.<br>For details about the application context of the FA model, see [Context](../apis-ability-kit/js-apis-inner-app-context.md).<br>For details about the application context of the stage model, see [Context](../apis-ability-kit/js-apis-inner-application-uiAbilityContext.md).|
| config   | [StoreConfig](arkts-apis-data-relationalStore-i.md#storeconfig)               | Yes  | Configuration of the RDB store.                               |
| callback | AsyncCallback&lt;[RdbStore](arkts-apis-data-relationalStore-RdbStore.md)&gt; | Yes  | Callback invoked to return the RDB store obtained.                  |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [RDB Store Error Codes](errorcode-data-rdb.md). To handle error 14800011, you can refer to [Database Backup and Restore](../../database/data-backup-and-restore.md).

| **ID**| **Error Message**  |
|-----------|---------|
| 401       | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 14800000  | Inner error.     |
| 14800010  | Failed to open or delete the database by an invalid database path.   |
| 14800011  | Failed to open the database because it is corrupted.    |
| 14801001  | The operation is supported in the stage model only.    |
| 14801002  | Invalid data group ID.   |
| 14800017  | StoreConfig is changed. |
| 14800020  | The secret key is corrupted or lost.   |
| 14800021  | SQLite: Generic error. Possible causes: Insert failed or the updated data does not exist.    |
| 14800022  | SQLite: Callback routine requested an abort.   |
| 14800023  | SQLite: Access permission denied.    |
| 14800027  | SQLite: Attempt to write a readonly database.   |
| 14800028  | SQLite: Some kind of disk I/O error occurred.     |
| 14800029  | SQLite: The database is full.  |
| 14800030  | SQLite: Unable to open the database file.   |

**Example**:

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

relationalStore.getRdbStore(context, STORE_CONFIG, async (err: BusinessError, rdbStore: relationalStore.RdbStore) => {
  if (err) {
    console.error(`Get RdbStore failed, code is ${err.code},message is ${err.message}`);
    return;
  }
  console.info('Get RdbStore successfully.');
  store = rdbStore;
  // Perform subsequent operations after the rdbStore instance is successfully obtained.
});
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

    relationalStore.getRdbStore(this.context, STORE_CONFIG, async (err: BusinessError, rdbStore: relationalStore.RdbStore) => {
      if (err) {
        console.error(`Get RdbStore failed, code is ${err.code},message is ${err.message}`);
        return;
      }
      console.info('Get RdbStore successfully.');
      store = rdbStore;
      // Perform subsequent operations after the rdbStore instance is successfully obtained.
    });
  }
}
```

## relationalStore.getRdbStore

getRdbStore(context: Context, config: StoreConfig): Promise&lt;RdbStore&gt;

Obtains an RdbStore instance. You can set the **config** parameter as required and use **RdbStore** APIs to perform data operations. This API uses a promise to return the result.

If no database file exists in the corresponding sandbox directory, a database file is created. For details, see [StoreConfig](arkts-apis-data-relationalStore-i.md#storeconfig). If a database file exists in the corresponding directory, the existing database file is opened.

When creating a database, you should consider whether to configure the [encrypt](arkts-apis-data-relationalStore-i.md#storeconfig) parameter. Once the database is created, you are not allowed to change this parameter.

| Encryption Type When the RDB Store Is Opened | Encryption Type When the RDB Store Is Created          | Result|
| ------- | -------------------------------- | ---- |
| Non-encryption| Encryption                         | The RDB store is opened in encrypted mode.  |
| Encryption| Non-encryption                         | The RDB store is opened in non-encrypted mode.  |

Currently, **getRdbStore()** does not support multi-thread concurrent operations.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Parameters**

| Name | Type                            | Mandatory| Description                                                        |
| ------- | -------------------------------- | ---- | ------------------------------------------------------------ |
| context | Context                          | Yes  | Application context.<br>For details about the application context of the FA model, see [Context](../apis-ability-kit/js-apis-inner-app-context.md).<br>For details about the application context of the stage model, see [Context](../apis-ability-kit/js-apis-inner-application-uiAbilityContext.md).|
| config  | [StoreConfig](arkts-apis-data-relationalStore-i.md#storeconfig) | Yes  | Configuration of the RDB store.                               |

**Return value**

| Type                                     | Description                             |
| ----------------------------------------- | --------------------------------- |
| Promise&lt;[RdbStore](arkts-apis-data-relationalStore-RdbStore.md)&gt; | Promise used to return the **RdbStore** object.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [RDB Store Error Codes](errorcode-data-rdb.md). To handle error 14800011, you can refer to [Database Backup and Restore](../../database/data-backup-and-restore.md).

| **ID**| **Error Message**                                                |
|-----------| ------------------------------------------------------------ |
| 401       | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 14800000  | Inner error. |
| 14800010  | Failed to open or delete the database by an invalid database path. |
| 14800011  | Failed to open the database because it is corrupted.  |
| 14801001  | The operation is supported in the stage model only.                               |
| 14801002  | Invalid data group ID.                             |
| 14800017  | StoreConfig is changed. |
| 14800020  | The secret key is corrupted or lost.   |
| 14800021  | SQLite: Generic error. Possible causes: Insert failed or the updated data does not exist. |
| 14800022  | SQLite: Callback routine requested an abort.   |
| 14800023  | SQLite: Access permission denied.    |
| 14800027  | SQLite: Attempt to write a readonly database. |
| 14800028  | SQLite: Some kind of disk I/O error occurred. |
| 14800029  | SQLite: The database is full. |
| 14800030  | SQLite: Unable to open the database file. |

**Example**:

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
  console.info('Get RdbStore successfully.');
}).catch((err: BusinessError) => {
  console.error(`Get RdbStore failed, code is ${err.code},message is ${err.message}`);
});
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
      console.info('Get RdbStore successfully.');
    }).catch((err: BusinessError) => {
      console.error(`Get RdbStore failed, code is ${err.code},message is ${err.message}`);
    });
  }
}
```

## relationalStore.deleteRdbStore

deleteRdbStore(context: Context, name: string, callback: AsyncCallback&lt;void&gt;): void

Deletes an RDB store. This API uses an asynchronous callback to return the result.

After the deletion, you are advised to set the database object to null. If a custom path is set in [StoreConfig](arkts-apis-data-relationalStore-i.md#storeconfig) when an RDB store is created, using this API cannot delete the RDB store. Use [deleteRdbStore](#relationalstoredeleterdbstore10) instead.

Before calling **deleteRdbStore**, ensure that the **RdbStore** and **ResultSet** of the vector store have been closed.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Parameters**

| Name  | Type                     | Mandatory| Description                                                        |
| -------- | ------------------------- | ---- | ------------------------------------------------------------ |
| context  | Context                   | Yes  | Application context.<br>For details about the application context of the FA model, see [Context](../apis-ability-kit/js-apis-inner-app-context.md).<br>For details about the application context of the stage model, see [Context](../apis-ability-kit/js-apis-inner-application-uiAbilityContext.md).|
| name     | string                    | Yes  | Name of the RDB store to delete.                                                |
| callback | AsyncCallback&lt;void&gt; | Yes  | Callback invoked to return the result.                                      |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [RDB Store Error Codes](errorcode-data-rdb.md).

| **ID**| **Error Message**                       |
|-----------|---------------------------------------|
| 401       | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 14800000  | Inner error.     |
| 14800010  | Failed to open or delete the database by an invalid database path. |

**Example**:

FA model:

<!--code_no_check_fa-->
```js
import { featureAbility } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let context = featureAbility.getContext();

relationalStore.deleteRdbStore(context, "RdbTest.db", (err: BusinessError) => {
  if (err) {
    console.error(`Delete RdbStore failed, code is ${err.code},message is ${err.message}`);
    return;
  }
  // After the database is deleted, the initialized RdbStore instance cannot be used.
  // Clear the related variables to release resources in time.
  console.info('Delete RdbStore successfully.');
});
```

Stage model:

```ts
import { UIAbility } from '@kit.AbilityKit';
import { window } from '@kit.ArkUI';
import { BusinessError } from '@kit.BasicServicesKit';

class EntryAbility extends UIAbility {
  onWindowStageCreate(windowStage: window.WindowStage) {
    relationalStore.deleteRdbStore(this.context, "RdbTest.db", (err: BusinessError) => {
      if (err) {
        console.error(`Delete RdbStore failed, code is ${err.code},message is ${err.message}`);
        return;
      }
      // After the database is deleted, the initialized RdbStore instance cannot be used.
      // Clear the related variables to release resources in time.
      console.info('Delete RdbStore successfully.');
    });
  }
}
```

## relationalStore.deleteRdbStore

deleteRdbStore(context: Context, name: string): Promise&lt;void&gt;

Deletes an RDB store. This API uses a promise to return the result.

After the deletion, you are advised to set the database object to null. If a custom path is set in [StoreConfig](arkts-apis-data-relationalStore-i.md#storeconfig) when an RDB store is created, using this API cannot delete the RDB store. Use [deleteRdbStore](#relationalstoredeleterdbstore10-1) instead.

Before calling **deleteRdbStore**, ensure that the **RdbStore** and **ResultSet** of the vector store have been closed.

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
| 401       | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 14800000  | Inner error.                                                                     |
| 14800010  | Failed to open or delete the database by an invalid database path.                      |

**Example**:

FA model:

<!--code_no_check_fa-->
```js
import { featureAbility } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let context = featureAbility.getContext();

relationalStore.deleteRdbStore(context, "RdbTest.db").then(() => {
  // After the database is deleted, the initialized RdbStore instance cannot be used.
  // Clear the related variables to release resources in time.
  console.info('Delete RdbStore successfully.');
}).catch((err: BusinessError) => {
  console.error(`Delete RdbStore failed, code is ${err.code},message is ${err.message}`);
});
```

Stage model:

```ts
import { UIAbility } from '@kit.AbilityKit';
import { window } from '@kit.ArkUI';
import { BusinessError } from '@kit.BasicServicesKit';

class EntryAbility extends UIAbility {
  onWindowStageCreate(windowStage: window.WindowStage) {
    relationalStore.deleteRdbStore(this.context, "RdbTest.db").then(() => {
      // After the database is deleted, the initialized RdbStore instance cannot be used.
      // Clear the related variables to release resources in time.
      console.info('Delete RdbStore successfully.');
    }).catch((err: BusinessError) => {
      console.error(`Delete RdbStore failed, code is ${err.code},message is ${err.message}`);
    });
  }
}
```

## relationalStore.deleteRdbStore<sup>10+</sup>

deleteRdbStore(context: Context, config: StoreConfig, callback: AsyncCallback\<void>): void

Deletes an RDB store. This API uses an asynchronous callback to return the result.

After the deletion, you are advised to set the database object to null. If the database file is stored in the sandbox directory, use this API to delete the database. If multiple processes operate the same database, other processes should be notified about the database deletion so that they can detect and process the deletion. If a custom path is set in [StoreConfig](arkts-apis-data-relationalStore-i.md#storeconfig) during RDB store creation, using this API to delete the RDB store.

Before calling **deleteRdbStore**, ensure that the **RdbStore** and **ResultSet** of the vector store have been closed.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Parameters**

| Name  | Type                       | Mandatory| Description                                                        |
| -------- | --------------------------- | ---- | ------------------------------------------------------------ |
| context  | Context                     | Yes  | Application context.<br>For details about the application context of the FA model, see [Context](../apis-ability-kit/js-apis-inner-app-context.md).<br>For details about the application context of the stage model, see [Context](../apis-ability-kit/js-apis-inner-application-uiAbilityContext.md).|
| config   | [StoreConfig](arkts-apis-data-relationalStore-i.md#storeconfig) | Yes  | Configuration of the RDB store.                               |
| callback | AsyncCallback&lt;void&gt;   | Yes  | Callback invoked to return the result.                                      |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [RDB Store Error Codes](errorcode-data-rdb.md).

| **ID**| **Error Message**         |
|-----------|----------|
| 401       | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 14800000  | Inner error.        |
| 14800010  | Failed to open or delete the database by an invalid database path.        |
| 14801001  | The operation is supported in the stage model only.         |
| 14801002  | Invalid data group ID.        |

**Example**:

FA model:

<!--code_no_check_fa-->
```js
import { featureAbility } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

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
  // After the database is deleted, the initialized RdbStore instance cannot be used.
  // Clear the related variables to release resources in time.
  console.info('Delete RdbStore successfully.');
});
```

Stage model:

```ts
import { UIAbility } from '@kit.AbilityKit';
import { window } from '@kit.ArkUI';
import { BusinessError } from '@kit.BasicServicesKit';

class EntryAbility extends UIAbility {
  onWindowStageCreate(windowStage: window.WindowStage) {
    const STORE_CONFIG: relationalStore.StoreConfig = {
      name: "RdbTest.db",
      securityLevel: relationalStore.SecurityLevel.S3
    };
    relationalStore.deleteRdbStore(this.context, STORE_CONFIG, (err: BusinessError) => {
      if (err) {
        console.error(`Delete RdbStore failed, code is ${err.code},message is ${err.message}`);
        return;
      }
      // After the database is deleted, the initialized RdbStore instance cannot be used.
      // Clear the related variables to release resources in time.
      console.info('Delete RdbStore successfully.');
    });
  }
}
```

## relationalStore.deleteRdbStore<sup>10+</sup>

deleteRdbStore(context: Context, config: StoreConfig): Promise\<void>

Deletes an RDB store. This API uses a promise to return the result.

After the deletion, you are advised to set the database object to null. If the database file is stored in the sandbox directory, use this API to delete the database. If multiple processes operate the same database, other processes should be notified about the database deletion so that they can detect and process the deletion. If a custom path is set in [StoreConfig](arkts-apis-data-relationalStore-i.md#storeconfig) during RDB store creation, using this API to delete the RDB store.

Before calling **deleteRdbStore**, ensure that the **RdbStore** and **ResultSet** of the vector store have been closed.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Parameters**

| Name | Type                       | Mandatory| Description                                                        |
| ------- | --------------------------- | ---- | ------------------------------------------------------------ |
| context | Context                     | Yes  | Application context.<br>For details about the application context of the FA model, see [Context](../apis-ability-kit/js-apis-inner-app-context.md).<br>For details about the application context of the stage model, see [Context](../apis-ability-kit/js-apis-inner-application-uiAbilityContext.md).|
| config  | [StoreConfig](arkts-apis-data-relationalStore-i.md#storeconfig) | Yes  | Configuration of the RDB store.                               |

**Return value**

| Type               | Description                     |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [RDB Error Codes](errorcode-data-rdb.md).

| **ID**| **Error Message**            |
|-----------|---------------------|
| 401       | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 801       | Capability not supported.      |
| 14800000  | Inner error.      |
| 14800010  | Failed to open or delete the database by an invalid database path.   |
| 14801001  | The operation is supported in the stage model only.   |
| 14801002  | Invalid data group ID.   |

**Example**:

FA model:

<!--code_no_check_fa-->
```js
import { featureAbility } from "@kit.AbilityKit";
import { BusinessError } from '@kit.BasicServicesKit';

let context = featureAbility.getContext();

const STORE_CONFIG: relationalStore.StoreConfig = {
  name: "RdbTest.db",
  securityLevel: relationalStore.SecurityLevel.S3
};

relationalStore.deleteRdbStore(context, STORE_CONFIG).then(() => {
  // After the database is deleted, the initialized RdbStore instance cannot be used.
  // Clear the related variables to release resources in time.
  console.info('Delete RdbStore successfully.');
}).catch((err: BusinessError) => {
  console.error(`Delete RdbStore failed, code is ${err.code},message is ${err.message}`);
});
```

Stage model:

```ts
import { UIAbility } from '@kit.AbilityKit';
import { window } from '@kit.ArkUI';
import { BusinessError } from '@kit.BasicServicesKit';

class EntryAbility extends UIAbility {
  onWindowStageCreate(windowStage: window.WindowStage) {
    const STORE_CONFIG: relationalStore.StoreConfig = {
      name: "RdbTest.db",
      securityLevel: relationalStore.SecurityLevel.S3
    };
    relationalStore.deleteRdbStore(this.context, STORE_CONFIG).then(() => {
      // After the database is deleted, the initialized RdbStore instance cannot be used.
      // Clear the related variables to release resources in time.
      console.info('Delete RdbStore successfully.');
    }).catch((err: BusinessError) => {
      console.error(`Delete RdbStore failed, code is ${err.code},message is ${err.message}`);
    });
  }
}
```
## relationalStore.isVectorSupported<sup>18+</sup>

isVectorSupported(): boolean

Checks whether the system supports vector stores.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Return value**

| Type   | Description                                             |
| ------- | ------------------------------------------------- |
| boolean | Returns **true** if the system supports vector stores; returns **false** otherwise.|

**Example**:

```
let result = relationalStore.isVectorSupported();
```

## relationalStore.isTokenizerSupported<sup>18+</sup>

isTokenizerSupported(tokenizer: Tokenizer): boolean

Checks whether the specified tokenizer is supported. This API returns the result synchronously.

This API returns **true** if the specified tokenizer is supported; returns **false** otherwise.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Parameters**

| Name | Type                 | Mandatory| Description                                                        |
| ------- | --------------------- | ---- | ------------------------------------------------------------ |
| tokenizer | [Tokenizer](arkts-apis-data-relationalStore-e.md#tokenizer17)               | Yes  | Tokenizer to check.|

**Return Value**

| Type               | Description                     |
| ------------------- | ------------------------- |
| boolean | Returns **true** if the specified tokenizer is supported; returns **false** otherwise.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| **ID**| **Error Message**            |
|-----------|---------------------|
| 401       | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |


**Example**:

```ts
import { relationalStore } from '@kit.ArkData'; // Import the relationalStore module.

let customType = relationalStore.Tokenizer.CUSTOM_TOKENIZER;
let customTypeSupported = relationalStore.isTokenizerSupported(customType);
console.info("custom tokenizer supported on current platform: " + customTypeSupported);
```

## relationalStore.getInsertSqlInfo<sup>20+</sup>

getInsertSqlInfo(table: string, values: ValuesBucket, conflict?: ConflictResolution): SqlInfo

Obtains the SQL statement used to insert data. This API returns the result synchronously.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Parameters**

| Name | Type                 | Mandatory| Description                                                        |
| ------- | --------------------- | ---- | ------------------------------------------------------------ |
| table | string              | Yes  | Name of the database table to which data is to be written.|
| values | [ValuesBucket](arkts-apis-data-relationalStore-t.md#valuesbucket) | Yes| Field information and corresponding values of the data to be written to the database.|
| conflict | [ConflictResolution](arkts-apis-data-relationalStore-e.md#conflictresolution10) | No|Resolution used to resolve the conflict. <br>Default value: **relationalStore.ConflictResolution.ON_CONFLICT_NONE**.|

**Return Value**

| Type               | Description                     |
| ------------------- | ------------------------- |
| [SqlInfo](arkts-apis-data-relationalStore-i.md#sqlinfo20) | **SqlInfo** object. **sql** indicates the returned SQL statement, and **args** indicates the parameters in the executed SQL statement.|

**Error codes**

For details about the error codes, see [RDB Error Codes](errorcode-data-rdb.md).

| **ID**| **Error Message**            |
|-----------|---------------------|
| 14800001       | Invalid arguments. Possible causes: 1. Parameter is out of valid range. |


**Example**:

```ts
import { relationalStore } from '@kit.ArkData'; // Import the relationalStore module.
const bucket: relationalStore.ValuesBucket = {
  name: "Logitech",
  age: 18,
  sex: "man",
  desc: "asserter"
};
const sqlInfo: relationalStore.SqlInfo = relationalStore.getInsertSqlInfo(
  "USER",
  bucket,
  relationalStore.ConflictResolution.ON_CONFLICT_NONE
);
```

## relationalStore.getUpdateSqlInfo<sup>20+</sup>

getUpdateSqlInfo(predicates: RdbPredicates, values: ValuesBucket, conflict?: ConflictResolution): SqlInfo

Obtains the SQL statement used to update data. This API returns the result synchronously.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Parameters**

| Name | Type                 | Mandatory| Description                                                        |
| ------- | --------------------- | ---- | ------------------------------------------------------------ |
| predicates | [RdbPredicates](arkts-apis-data-relationalStore-RdbPredicates.md) | Yes  | **RdbPredicates** object that matches the specified field.|
| values | [ValuesBucket](arkts-apis-data-relationalStore-t.md#valuesbucket) | Yes| Field information and corresponding values of the data to be written to the database.|
| conflict | [ConflictResolution](arkts-apis-data-relationalStore-e.md#conflictresolution10) | No| Resolution used to resolve the conflict. <br>Default value: **relationalStore.ConflictResolution.ON_CONFLICT_NONE**.|

**Return Value**

| Type               | Description                     |
| ------------------- | ------------------------- |
| [SqlInfo](arkts-apis-data-relationalStore-i.md#sqlinfo20) | **SqlInfo** object. **sql** indicates the returned SQL statement, and **args** indicates the parameters in the executed SQL statement.|

**Error codes**

For details about the error codes, see [RDB Error Codes](errorcode-data-rdb.md).

| **ID**| **Error Message**            |
|-----------|---------------------|
| 14800001       | Invalid arguments. Possible causes: 1. Parameter is out of valid range. |


**Example**:

```ts
import { relationalStore } from '@kit.ArkData'; // Import the relationalStore module.

const bucket: relationalStore.ValuesBucket = {
  name: "Logitech",
  age: 18,
  sex: "man",
  desc: "asserter"
};
const predicates = new relationalStore.RdbPredicates("users");
const sqlInfo: relationalStore.SqlInfo = relationalStore.getUpdateSqlInfo(
  predicates,
  bucket,
  relationalStore.ConflictResolution.ON_CONFLICT_NONE
);
```

## relationalStore.getDeleteSqlInfo<sup>20+</sup>

getDeleteSqlInfo(predicates: RdbPredicates): SqlInfo

Obtains the SQL statement used to delete data. This API returns the result synchronously.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Parameters**

| Name | Type                 | Mandatory| Description                                                        |
| ------- | --------------------- | ---- | ------------------------------------------------------------ |
| predicates | [RdbPredicates](arkts-apis-data-relationalStore-RdbPredicates.md) | Yes  | **RdbPredicates** object that matches the specified field.|

**Return Value**

| Type               | Description                     |
| ------------------- | ------------------------- |
| [SqlInfo](arkts-apis-data-relationalStore-i.md#sqlinfo20) | **SqlInfo** object. **sql** indicates the returned SQL statement, and **args** indicates the parameters in the executed SQL statement.|

**Error codes**

For details about the error codes, see [RDB Error Codes](errorcode-data-rdb.md).

| **ID**| **Error Message**            |
|-----------|---------------------|
| 14800001       | Invalid arguments. Possible causes: 1. Parameter is out of valid range. |


**Example**:

```ts
import { relationalStore } from '@kit.ArkData'; // Import the relationalStore module.

const predicates = new relationalStore.RdbPredicates("users");
predicates.equalTo("tableName", "a");
predicates.notEqualTo("age", 18);
const sqlInfo: relationalStore.SqlInfo = relationalStore.getDeleteSqlInfo(predicates);
```

## relationalStore.getQuerySqlInfo<sup>20+</sup>

getQuerySqlInfo(predicates: RdbPredicates, columns?: Array\<string>): SqlInfo

Obtains the SQL statement used to query data. This API returns the result synchronously.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Parameters**

| Name | Type                 | Mandatory| Description                                                        |
| ------- | --------------------- | ---- | ------------------------------------------------------------ |
| predicates | [RdbPredicates](arkts-apis-data-relationalStore-RdbPredicates.md) | Yes  | **RdbPredicates** object that matches the specified field.|
| columns | Array\<string> | No| Columns to be queried. If this parameter is not specified, all columns are queried.|

**Return Value**

| Type               | Description                     |
| ------------------- | ------------------------- |
| [SqlInfo](arkts-apis-data-relationalStore-i.md#sqlinfo20) | **SqlInfo** object. **sql** indicates the returned SQL statement, and **args** indicates the parameters in the executed SQL statement.|

**Error codes**

For details about the error codes, see [RDB Error Codes](errorcode-data-rdb.md).

| **ID**| **Error Message**            |
|-----------|---------------------|
| 14800001       | Invalid arguments. Possible causes: 1. Parameter is out of valid range. |


**Example**:

```ts
import { relationalStore } from '@kit.ArkData'; // Import the relationalStore module.

const predicates = new relationalStore.RdbPredicates("users");
predicates.notEqualTo("age", 18);
predicates.equalTo("name", "zhangsan");
const sqlInfo: relationalStore.SqlInfo = relationalStore.getQuerySqlInfo(predicates);
```
