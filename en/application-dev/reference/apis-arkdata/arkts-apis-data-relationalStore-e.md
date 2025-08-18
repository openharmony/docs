# Enums

> **NOTE**
> 
> The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## SecurityLevel

Enumerates the KV store security levels. Use the enum name rather than the enum value. You cannot change the security level of an RDB store from a higher level to a lower one.

> **NOTE**
>
> To perform data sync operations, the RDB store security level must be lower than or equal to that of the peer device. For details, see [Access Control Mechanism in Cross-Device Sync](../../database/sync-app-data-across-devices-overview.md#access-control-mechanism-in-cross-device-sync).

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

| Name| Value  | Description                                                        |
| ---- | ---- | ------------------------------------------------------------ |
| S1   | 1    | The RDB store security level is low. If data leakage occurs, minor impact will be caused on the database. An example would be a graph store containing non-sensitive system data such as wallpapers.|
| S2   | 2    | The RDB store security level is medium. If data leakage occurs, moderate impact will be caused on the database. An example would be a graph store containing audio and video data created by users or call logs.|
| S3   | 3    | The RDB store security level is high. If data leakage occurs, major impact will be caused on the database. An example would be a graph store containing user fitness, health, and location data.|
| S4   | 4    | The RDB store security level is critical. If data leakage occurs, severe impact will be caused on the database. An example would be a graph store containing authentication credentials and financial data.|

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

## Tokenizer<sup>17+</sup>

Enumerates tokenizers that can be used for FTS. Use the enum name rather than the enum value.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

| Name                             | Value  | Description            |
| ------------------------------- | --- | -------------- |
| NONE_TOKENIZER     | 0  | No tokenizer is used.     |
| ICU_TOKENIZER | 1 | The ICU tokenizer is used, which supports Chinese and multiple languages. If the ICU tokenizer is used, you can set the language to use, for example, **zh_CN** for Chinese and **tr_TR** for Turkish. For details about the supported languages, see [ICU tokenizer](https://gitee.com/openharmony/third_party_icu/blob/master/icu4c/source/data/lang/en.txt). For details about the language abbreviations, see [locales](https://gitee.com/openharmony/third_party_icu/tree/master/icu4c/source/data/locales).|
| CUSTOM_TOKENIZER<sup>18+</sup> | 2 | A custom tokenizer is used. Chinese (simplified and traditional), English, and Arabic numerals are supported. Compared with **ICU_TOKENIZER**, **CUSTOM_TOKENIZER** has advantages in tokenization accuracy and resident memory usage. The self-developed tokenizer supports two modes: default tokenization mode and short word tokenization mode (short_words). You can use the cut_mode parameter to specify the mode. If no mode is specified, the default mode is used.|

The table creation statement varies with the tokenizer in use.

**Example**:

The following is an example of the table creation statement when **ICU_TOKENIZER** is used:

```ts
import { relationalStore } from '@kit.ArkData'; // Import the relationalStore module.
import { UIAbility } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { window } from '@kit.ArkUI';

// In this example, Ability is used to obtain an RdbStore instance in the stage model. You can use other implementations as required.
class EntryAbility extends UIAbility {
  async onWindowStageCreate(windowStage: window.WindowStage) {
    let store: relationalStore.RdbStore | undefined = undefined;
    const STORE_CONFIG: relationalStore.StoreConfig = {
      name: "MyStore.db",
      securityLevel: relationalStore.SecurityLevel.S3,
      tokenizer: relationalStore.Tokenizer.ICU_TOKENIZER
    };
    store = await relationalStore.getRdbStore(this.context, STORE_CONFIG);

    const SQL_CREATE_TABLE = "CREATE VIRTUAL TABLE example USING fts4(name, content, tokenize=icu zh_CN)";
    if (store != undefined) {
      (store as relationalStore.RdbStore).executeSql(SQL_CREATE_TABLE, (err) => {
        if (err) {
          console.error(`ExecuteSql failed, code is ${err.code},message is ${err.message}`);
          return;
        }
        console.info('create virtual table done.');
      });
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
  async onWindowStageCreate(windowStage: window.WindowStage) {
    let store: relationalStore.RdbStore | undefined = undefined;
    const STORE_CONFIG: relationalStore.StoreConfig = {
      name: "MyStore.db",
      securityLevel: relationalStore.SecurityLevel.S3,
      tokenizer: relationalStore.Tokenizer.CUSTOM_TOKENIZER
    };
    store = await relationalStore.getRdbStore(this.context, STORE_CONFIG);

    const SQL_CREATE_TABLE = "CREATE VIRTUAL TABLE example USING fts5(name, content, tokenize='customtokenizer')";
    if (store != undefined) {
      (store as relationalStore.RdbStore).executeSql(SQL_CREATE_TABLE, (err) => {
        if (err) {
          console.error(`ExecuteSql failed, code is ${err.code},message is ${err.message}`);
          return;
        }
        console.info('create virtual table done.');
      });
    }
  }
}
```

The following is an example of the table creation statement when **CUSTOM_TOKENIZER** is used:

```ts
import { relationalStore } from '@kit.ArkData'; // Import the relationalStore module.
import { UIAbility } from '@kit.AbilityKit';
import { window } from '@kit.ArkUI';

export default class EntryAbility extends UIAbility {
  async onWindowStageCreate(windowStage: window.WindowStage) {
    console.info('custom tokenizer example: window stage create begin.');
    let store: relationalStore.RdbStore | undefined = undefined;
    const storeConfig: relationalStore.StoreConfig = {
      name: "MyStore.db",
      securityLevel: relationalStore.SecurityLevel.S3
    };
    let customType = relationalStore.Tokenizer.CUSTOM_TOKENIZER;
    let customTypeSupported = relationalStore.isTokenizerSupported(customType);
    if (customTypeSupported) {
      storeConfig.tokenizer = customType;
    } else {
      console.info('custom tokenizer example: not support custom tokenizer.');
      return;
    }
    store = await relationalStore.getRdbStore(this.context, storeConfig);

    const sqlCreateTable =
      "CREATE VIRTUAL TABLE example USING fts5(name, content, tokenize='customtokenizer cut_mode short_words')";
    if (store != undefined) {
      (store as relationalStore.RdbStore).executeSql(sqlCreateTable, (err) => {
        if (err) {
          console.error(`custom tokenizer example: ExecuteSql failed, code is ${err.code},message is ${err.message}`);
          return;
        }
        console.info('custom tokenizer example: create virtual table done.');
      });
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

## SyncMode

Defines the database synchronization mode. Use the enum name rather than the enum value.

| Name          | Value  | Description                              |
| -------------- | ---- | ---------------------------------- |
| SYNC_MODE_PUSH                       | 0   | Data is pushed from a local device to a remote device.<br>**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core|
| SYNC_MODE_PULL                       | 1   | Data is pulled from a remote device to a local device.<br>**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core|
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

Enumerates predicates used as query conditions. Use the enum name rather than the enum value.

**System capability**: SystemCapability.DistributedDataManager.CloudSync.Client

| Name          | Value  | Description                              |
| -------------- | ---- | ---------------------------------- |
| CURSOR_FIELD        | '#_cursor'     | Field name used for cursor-based search.|
| ORIGIN_FIELD        | '#_origin'     | Field name used to specify the data source in cursor-based search.   |
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
| SUBSCRIBE_TYPE_CLOUD_DETAILS<sup>10+</sup> | 2  | Subscribe to details of the cloud data change.<br>**System capability**: SystemCapability.DistributedDataManager.CloudSync.Client|
| SUBSCRIBE_TYPE_LOCAL_DETAILS<sup>12+</sup> | 3  | Subscribe to details of the local data change.<br>**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core|

## RebuildType<sup>12+</sup>

Enumerates the RDB store rebuild types. Use the enum name rather than the enum value.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

| Name   | Value  | Description                                                                                                            |
| ------- | ---- |----------------------------------------------------------------------------------------------------------------|
| NONE    | 0    | The RDB store is not rebuilt.                                                                                                   |
| REBUILT | 1    | The RDB store is rebuilt and creates an empty database. You need to create tables and restore data.                                                                            |
| REPAIRED | 2    | The database is repaired and the undamaged data is restored. Currently, only the [vector store](arkts-apis-data-relationalStore-i.md#storeconfig) supports this capability.|

## ChangeType<sup>10+</sup>

Enumerates data change types. Use the enum name rather than the enum value.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

| Name                        | Value  | Description                        |
| -------------------------- | --- | -------------------------- |
| DATA_CHANGE  | 0   | Data change.  |
| ASSET_CHANGE | 1   | Asset change.|

## DistributedType<sup>10+</sup>

Enumerates the distributed database table types. Use the enum name rather than the enum value.

| Name               | Value  | Description                                                                                                |
| ------------------ | --- | -------------------------------------------------------------------------------------------------- |
| DISTRIBUTED_DEVICE | 0  | Distributed database table synced between devices.<br>**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core              |
| DISTRIBUTED_CLOUD  | 1   | Distributed database table synced between a device and the cloud.<br>**System capability**: SystemCapability.DistributedDataManager.CloudSync.Client|

## ConflictResolution<sup>10+</sup>

Enumerates the resolutions used when a conflict occurs during data insertion or modification. Use the enum name rather than the enum value.

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
| SYNC_FINISH      | 2    | The device-cloud sync is finished.|

## ProgressCode<sup>10+</sup>

Enumerates the device-cloud sync states. Use the enum name rather than the enum value.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

| Name                 | Value  | Description                                                        |
| --------------------- | ---- | ------------------------------------------------------------ |
| SUCCESS               | 0    | The device-cloud sync is successful.                                      |
| UNKNOWN_ERROR         | 1    | An unknown error occurs during the device-cloud sync.                              |
| NETWORK_ERROR         | 2    | A network error occurs during the device-cloud sync.                              |
| CLOUD_DISABLED        | 3    | The cloud is unavailable.                                            |
| LOCKED_BY_OTHERS      | 4    | The device-cloud sync of another device is being performed.<br>The sync of the local device can be performed only when the cloud resources are available.|
| RECORD_LIMIT_EXCEEDED | 5    | The number of records or size of the data to be synced exceeds the maximum. The maximum value is configured on the cloud.|
| NO_SPACE_FOR_ASSET    | 6    | The remaining cloud space is less than the size of the data to be synced.                    |
| BLOCKED_BY_NETWORK_STRATEGY<sup>12+</sup>    | 7    | The device-cloud sync is blocked due to the network strategy.                    |

## TransactionType<sup>14+</sup>

Enumerates the types of transaction objects that can be created. Use the enum name rather than the enum value.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

| Name            | Value  | Description                    |
| ---------------- | ---- | ------------------------ |
| DEFERRED       | 0    | Deferred transaction object. When a deferred transaction object is created, automatic commit is disabled and no transaction will start. A read or write transaction starts only when the first read or write operation is performed.  |
| IMMEDIATE | 1    | Immediate transaction object. When an immediate transaction object is created, a write transaction starts. If there is any uncommitted write transaction, the transaction object cannot be created and error 14800024 is returned.|
| EXCLUSIVE      | 2    | Exclusive transaction object. In WAL mode, the exclusive transaction object is the same as the immediate transaction object. In other log modes, this type of transaction can prevent the database from being read by other connections during the transaction.|

## ColumnType<sup>18+</sup>

Enumerates the types of the column data. Use the enum name rather than the enum value.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

| Name         | Value  | Description                                                        |
| ------------- | ---- | ------------------------------------------------------------ |
| NULL          | 0    | NULL.                                      |
| INTEGER       | 1    | 64-bit integer. <br>The column can hold 8-bit (including Boolean values), 16-bit, 32-bit, and 64-bit integers. If the 64-bit integer is greater than 2^53 or less than -2^53, use [getString](arkts-apis-data-relationalStore-ResultSet.md#getstring) to convert the 64-bit integer to a string.|
| REAL          | 2    | Floating-point number.                                        |
| TEXT          | 3    | String.                                        |
| BLOB          | 4    | Uint8Array.                                    |
| ASSET         | 5    | [Asset](arkts-apis-data-relationalStore-i.md#asset10).                             |
| ASSETS        | 6    | [Assets](arkts-apis-data-relationalStore-t.md#assets10).                           |
| FLOAT_VECTOR  | 7    | Float32Array.                                  |
| UNLIMITED_INT | 8    | Bigint.                                        |
