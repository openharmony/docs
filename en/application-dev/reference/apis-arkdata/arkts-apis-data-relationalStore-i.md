# Interfaces (Others)
<!--Kit: ArkData-->
<!--Subsystem: DistributedDataManager-->
<!--Owner: @baijidong-->
<!--Designer: @widecode; @htt1997-->
<!--Tester: @yippo; @logic42-->
<!--Adviser: @ge-yafang-->

> **NOTE**
> 
> The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## StoreConfig

Defines the RDB store configuration.

| Name       | Type         | Mandatory| Description                                                     |
| ------------- | ------------- | ---- | --------------------------------------------------------- |
| name          | string        | Yes  | Database file name, which is the unique identifier of the RDB store.<br>**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core  |
| securityLevel | [SecurityLevel](arkts-apis-data-relationalStore-e.md#securitylevel) | Yes  | Security level of the RDB store.<br>**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core|
| encrypt       | boolean       | No  | Whether to encrypt the RDB store.<br>**true**: encrypt the RDB store.<br>**false** (default): not encrypt the RDB store.<br>**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core |
| dataGroupId<sup>10+</sup> | string | No| Application group ID. <!--RP1-->Currently, this parameter is not supported.<!--RP1End--><br>**Model restriction**: This parameter can be used only in the stage model.<br>This parameter is supported since API version 10. If **dataGroupId** is specified, the **RdbStore** instance will be created in the sandbox directory of the specified **dataGroupId**. However, the encrypted RDB store in this sandbox directory does not support multi-process access. If this parameter is left blank, the **RdbStore** instance will be created in the sandbox directory of the application by default.<br>**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core|
| customDir<sup>11+</sup> | string | No| Custom database path.<br>**Constraints**: The maximum length of the database path is 128 bytes. If the database path exceeds 128 bytes, the RDB store fails to be opened and an error is returned.<br>This parameter is supported since API version 11. The database is created in the following directory structure: **context.databaseDir** + **"/rdb/"** + **customDir**, where **context.databaseDir** indicates the path of the application sandbox, **"/rdb/"** indicates the RDB store created, and **customDir** indicates a user-defined path. If this parameter is left blank, the **RdbStore** instance will be created in the sandbox directory of the application by default. Since API version 18, if the **rootDir** parameter is also configured, the RDB store in the following directory will be opened or deleted: **rootDir** + "/" + **customDir** + "/" + **name**.<br>**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core|
| rootDir<sup>18+</sup> | string | No| Root path of the database.<br>This parameter is supported since API version 18. The database in the **rootDir** + "/" + **customDir** directory will be opened or deleted. The database opened is read-only. Writing data to a read-only database will trigger error 801. If this parameter is set when you want to open or delete an RDB store, ensure that the database file exists in the corresponding path and the caller has the read permission. Otherwise, error 14800010 will be returned.<br>**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core|
| autoCleanDirtyData<sup>11+</sup> | boolean | No| Whether to automatically clear the dirty data (data that has been deleted from the cloud) from the local device. The value **true** means to clear the dirty data automatically; **false** means to clear the data manually. <br>Default value: **true**.<br>For a database with device-cloud synergy, this parameter can be used to set whether to automatically clear the data deleted from the cloud on the device. You can manually clear the data by calling [cleanDirtyData<sup>11+</sup>](arkts-apis-data-relationalStore-RdbStore.md#cleandirtydata11).<br>This parameter is supported since API version 11.<br>**System capability**: SystemCapability.DistributedDataManager.CloudSync.Client|
| allowRebuild<sup>12+</sup> | boolean | No| Whether to automatically delete the RDB store and create an empty table in the case of an exception.<br>**true**: delete the RDB store and create an empty table in the case of an exception.<br>**false** (default): not delete the RDB store in the case of an exception.<br>This parameter is supported since API version 12.<br>**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core|
| isReadOnly<sup>12+</sup> | boolean | No| Whether the RDB store is read-only.<br>**true**: The RDB store is read-only. Writing data to the RDB store will result in error code 801.<br>**false** (default): The RDB store is readable and writeable.<br>This parameter is supported since API version 12.<br>**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core|
| pluginLibs<sup>12+</sup> | Array\<string> | No| Dynamic libraries with capabilities such as Full-Text Search (FTS).<br>**Constraints**<br>1. The maximum number of dynamic library names is 16. If the number of dynamic library names exceeds 16, the library fails to be opened and an error is returned.<br>2. The dynamic libraries must be those in the sandbox directory or system directory of the application. If a dynamic library fails to be loaded, the RDB store cannot be opened and an error will be returned.<br>3. The dynamic library name must be a complete path that can be loaded by SQLite.<br>Example: **[context.bundleCodeDir + "/libs/arm64/" + libtokenizer.so]**, where **context.bundleCodeDir** indicates the application sandbox path, **/libs/arm64/** indicates the subdirectory, **libtokenizer.so** indicates the file name of the dynamic library. If this parameter is left blank, dynamic libraries are not loaded by default.<br>4. The dynamic library must contain all its dependencies to prevent the failure caused by the lack of dependencies.<br>Example: In an NDK project, **libtokenizer.so** is built using the default compilation parameters and depends on the C++ standard library. When the dynamic library is loaded, **libc++_shared.so** is linked by mistake because the namespace is different from that during compilation. As a result, the **__emutls_get_address** symbol cannot be found. To solve this problem, you need to statically link the C++ standard library during compilation. For details, see [NDK Project Building Overview](../../napi/build-with-ndk-overview.md).<br>**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core|
| cryptoParam<sup>14+</sup> | [CryptoParam](#cryptoparam14) | No| Custom encryption parameters.<br>If this parameter is left empty, the default encryption parameters are used. For details, see default values of [CryptoParam](#cryptoparam14).<br>This parameter is valid only when **encrypt** is **true**.<br>This parameter is supported since API version 14.<br>**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core|
| vector<sup>18+</sup> | boolean | No| Whether the RDB store is a vector store. The value **true** means the RDB store is a vector store, and the value **false** means the opposite.<br>Default value: **false**.<br>The vector store is ideal for storing and managing high-dimensional vector data, while the RDB store is optimal for storing and processing structured data.<br>Before calling **deleteRdbStore**, ensure that the **RdbStore** and **ResultSet** of the vector store have been closed.<br>**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core|
| tokenizer<sup>17+</sup> | [Tokenizer](arkts-apis-data-relationalStore-e.md#tokenizer17) | No| Type of the tokenizer to be used for FTS.<br>If this parameter is left blank, English tokenization is supported if FTS does not support Chinese or multi-language tokenization.<br>**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core|
| persist<sup>18+</sup> | boolean | No| Sets whether to persist an RDB store. The value **true** means to persist the RDB store; **false** means the opposite (using an in-memory database). The default value is **true**.<br>An in-memory database does not support encryption, backup, restore, cross-process access, and distributed capabilities, with the **securityLevel** property ignored.<br>**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core|
| enableSemanticIndex<sup>20+</sup> | boolean | No| Whether to enable the semantic index processing feature for the database. The value **true** means to enable the semantic index processing feature; **false** means the opposite. The default value is **false**.<br>**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core|

## CryptoParam<sup>14+</sup>

Represents the configuration of database encryption parameters. This parameter is valid only when **encrypt** in **StoreConfig** is **true**.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

| Name         | Type  | Mandatory| Description                                                        |
| ------------- | ------ | ---- | ------------------------------------------------------------ |
| encryptionKey | Uint8Array | Yes  | Key used for database encryption and decryption.<br>If this parameter is not specified, the RDB store generates a key, saves the key, and uses the key to open the database file.<br>If the key is not required, you need to set the key to 0.|
| iterationCount | number | No| Number of iterations of the PBKDF2 algorithm used in the RDB store. The value is an integer. <br>Default value: **10000**.<br>The value must be an integer greater than 0. If it is not an integer, the value is rounded down.<br>If this parameter is not specified or is set to **0**, the default value **10000** and the default encryption algorithm **AES_256_GCM** are used.|
| encryptionAlgo | [EncryptionAlgo](arkts-apis-data-relationalStore-e.md#encryptionalgo14) | No| Algorithm used for database encryption and decryption. <br>Default value: **AES_256_GCM**.|
| hmacAlgo | [HmacAlgo](arkts-apis-data-relationalStore-e.md#hmacalgo14) | No| HMAC algorithm used for database encryption and decryption. <br>Default value: **SHA256**.|
| kdfAlgo | [KdfAlgo](arkts-apis-data-relationalStore-e.md#kdfalgo14) | No| PBKDF2 algorithm used for database encryption and decryption. <br>Default value: the same as the HMAC algorithm used.|
| cryptoPageSize | number | No| Page size used for database encryption and decryption, in bytes. <br>Default value: **1024**.<br>The value must be an integer within the range of 1024 to 65536 and must be 2<sup>n</sup>. If the specified value is not an integer, the value is rounded down.|

## Asset<sup>10+</sup>

Represents the asset (such as a document, image, or video).

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

| Name         | Type                         | Mandatory | Description          |
| ----------- | --------------------------- | --- | ------------ |
| name        | string                      | Yes  | Asset name.      |
| uri         | string                      | Yes  | Asset URI, which is an absolute path in the system.      |
| path        | string                      | Yes  | Path of an asset in the application sandbox.      |
| createTime  | string                      | Yes  | Time when an asset is created.  |
| modifyTime  | string                      | Yes  | Time when an asset is last modified.|
| size        | string                      | Yes  | Asset size.   |
| status      | [AssetStatus](arkts-apis-data-relationalStore-e.md#assetstatus10) | No  | Asset status. <br>Default value: **ASSET_NORMAL**.       |

## ChangeInfo<sup>10+</sup>

Defines a struct for the details about the device-cloud sync process.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

| Name    | Type                              | Mandatory| Description                                                        |
| -------- | ---------------------------------- | ---- | ------------------------------------------------------------ |
| table    | string                             | Yes  | Name of the table with data changes.                                    |
| type     | [ChangeType](arkts-apis-data-relationalStore-e.md#changetype10)        | Yes  | Type of the data changed, which can be data or asset.        |
| inserted | Array\<string\> \| Array\<number\> | Yes  | Location where data is inserted. If the primary key of the table is of the string type, it is the value of the primary key. Otherwise, it is the row number of the inserted data.|
| updated  | Array\<string\> \| Array\<number\> | Yes  | Location where data is updated. If the primary key of the table is of the string type, it is the value of the primary key. Otherwise, it is the row number of the updated data.|
| deleted  | Array\<string\> \| Array\<number\> | Yes  | Location where data is deleted. If the primary key of the table is of the string type, it is the value of the primary key. Otherwise, it is the row number of the deleted data.|

## DistributedConfig<sup>10+</sup>

Defines a struct for distributed configuration of a table.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

| Name    | Type   | Mandatory| Description                                                        |
| -------- | ------- | ---- | ------------------------------------------------------------ |
| autoSync   | boolean | Yes  | The value **true** means both auto sync and manual sync are supported for the table; **false** means only manual sync is supported for the table.|
| asyncDownloadAsset<sup>18+</sup> | boolean | No| Whether to download assets synchronously or asynchronously when device-cloud sync is being performed for the current RDB store. The value **true** means to use an asynchronous task to download assets after all data is downloaded; **false** means to downloaded assets synchronously. <br>Default value: **false**.|
| enableCloud<sup>18+</sup> | boolean | No| Whether to enable device-cloud sync for this RDB store. The value **true** means to enable device-cloud sync; **false** means the opposite. The default value is **true**.|

## Statistic<sup>10+</sup>

Defines a struct for the device-cloud sync statistics of a database table.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

| Name      | Type  | Mandatory| Description                                    |
| ---------- | ------ | ---- | ---------------------------------------- |
| total      | number | Yes  | Total number of rows to be synced between the device and cloud in the database table.    |
| successful | number | Yes  | Number of rows that are successfully synced between the device and cloud in the database table.      |
| failed     | number | Yes  | Number of rows that failed to be synced between the device and cloud in the database table.      |
| remained   | number | Yes  | Number of rows that are not executed for device-cloud sync in the database table.|

## TableDetails<sup>10+</sup>

Defines a struct for statistics of device-cloud upload and download tasks of a database table.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

| Name    | Type                     | Mandatory| Description                                      |
| -------- | ------------------------- | ---- | ------------------------------------------ |
| upload   | [Statistic](arkts-apis-data-relationalStore-i.md#statistic10) | Yes  | Statistics of the device-cloud upload tasks.|
| download | [Statistic](arkts-apis-data-relationalStore-i.md#statistic10) | Yes  | Statistics of the device-cloud download tasks.|

## ProgressDetails<sup>10+</sup>

Defines a struct for statistics of the overall device-cloud sync (upload and download) tasks of an RDB store.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

| Name    | Type                                             | Mandatory| Description                                                        |
| -------- | ------------------------------------------------- | ---- | ------------------------------------------------------------ |
| schedule | [Progress](arkts-apis-data-relationalStore-e.md#progress10)                            | Yes  | Device-cloud sync process.                                          |
| code     | [ProgressCode](arkts-apis-data-relationalStore-e.md#progresscode10)                  | Yes  | Device-cloud sync state.                                    |
| details  | Record<string, [TableDetails](#tabledetails10)> | Yes  | Statistics of each table.<br>The key indicates the table name, and the value indicates the device-cloud sync statistics of the table.|

## SqlExecutionInfo<sup>12+</sup>

Represents statistics about SQL statements executed by the database.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

| Name    | Type                                              | Read-Only| Optional |Description                                                        |
| -------- | ------------------------------------------------- | ---- | ---- | -------------------------------------------------------- |
| sql<sup>12+</sup>           | Array&lt;string&gt;            | Yes  |   No  | SQL statements executed. If the value of [batchInsert](arkts-apis-data-relationalStore-RdbStore.md#batchinsert) is too large, multiple SQL statements may be executed.     |
| totalTime<sup>12+</sup>      | number                        | Yes  |   No  | Total time used to execute the SQL statements, in μs.                                   |
| waitTime<sup>12+</sup>       | number                        | Yes  |   No  | Time used to obtain the handle, in μs.                                        |
| prepareTime<sup>12+</sup>    | number                        | Yes  |   No  | Time used to get the SQL statements ready and bind parameters, in μs.                                |
| executeTime<sup>12+</sup>    | number                        | Yes  |   No  | Time used to execute the SQL statements, in μs.|

## SqlInfo<sup>20+</sup>

Represents details about the SQL statement executed by the database.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

| Name    | Type                                              | Read-Only| Optional |Description                                                        |
| -------- | ------------------------------------------------- | ---- | ---- | -------------------------------------------------------- |
| sql<sup>20+</sup>           | string           | Yes  |   No  | SQL statements to be executed.     |
| args<sup>20+</sup>      | Array&lt;[ValueType](arkts-apis-data-relationalStore-t.md#valuetype)&gt;                        | Yes  |   No  | Parameters in the SQL statements to be executed.                                   |

## ExceptionMessage<sup>20+</sup>

Represents an exception message about the SQL statement executed by the database.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

| Name    | Type                                              | Read-Only| Optional |Description                                                        |
| -------- | ------------------------------------------------- | ---- | ---- | -------------------------------------------------------- |
| code<sup>20+</sup>      | number                        | Yes  |   No  | Error code returned by the executed SQL statement. For details about the values and meanings, see [SQLite Error Codes](https://www.sqlite.org/rescode.html).|
| message<sup>20+</sup>       | string                        | Yes  |   No  | Exception message returned by the executed SQL statement.                                        |
| sql<sup>20+</sup>    | string                        | Yes  |   No  | SQL statement that reports the error.                        |

## TransactionOptions<sup>14+</sup>

Represents the configuration of a transaction object.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

| Name       | Type         | Mandatory| Description                                                     |
| ------------- | ------------- | ---- | --------------------------------------------------------- |
| transactionType          | [TransactionType](arkts-apis-data-relationalStore-e.md#transactiontype14)        | No  | Transaction object type. <br>Default value: **DEFERRED**. |
