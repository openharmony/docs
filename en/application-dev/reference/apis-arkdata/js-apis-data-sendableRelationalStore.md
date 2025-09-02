# @ohos.data.sendableRelationalStore (Shared RDB Store)

The **sendableRelationalStore** module provides APIs for obtaining **ValuesBucket** of the sendable type from the query result set and transferring it between concurrent instances.

> **NOTE**
> 
> The initial APIs of this module are supported since API version 12. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## When to Use

When [taskpool](../../arkts-utils/taskpool-introduction.md) is used for multi-thread computing, data storage containers such as **ValuesBucket**, **Asset**, and **Assets** of the RDB store cannot be used for cross-thread transfer due to the restriction on data types.

This module provides conversion functions for converting the types between common data storage containers and data storage containers that can be passed across threads.

## Modules to Import

```ts
import { sendableRelationalStore } from '@kit.ArkData';
```

## sendableRelationalStore.toSendableValuesBucket

toSendableValuesBucket(valuesBucket: NonSendableBucket): ValuesBucket

Converts a key-value (KV) pair that cannot be passed across threads into the data that can be passed across threads.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Parameters**

| Name      | Type                                   | Mandatory| Description                              |
| ------------ | --------------------------------------- | ---- | :--------------------------------- |
| valuesBucket | [NonSendableBucket](#nonsendablebucket) | Yes  | Data that cannot be passed across threads.|

**Return value**

| Type                         | Description                                |
| ----------------------------- | ------------------------------------ |
| [ValuesBucket](#valuesbucket) | Data that can be passed across threads.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [RDB Store Error Codes](errorcode-data-rdb.md).

| **ID**| **Error Message**                                                                                                                                   |
| ------------ | ----------------------------------------------------------------------------------------------------------------------------------------------- |
| 401          | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 14800000     | Inner error.                                                                                                                                    |

**Example**

```ts
const asset1: sendableRelationalStore.NonSendableAsset = {
  name: 'hangman',
  uri: '//path/example',
  path: '//path/example',
  createTime: 'createTime1',
  modifyTime: 'modifyTime1',
  size: 'size1'
};
const asset2: sendableRelationalStore.NonSendableAsset = {
  name: 'hangman',
  uri: '//path/example',
  path: '//path/example',
  createTime: 'createTime1',
  modifyTime: 'modifyTime1',
  size: 'size1'
};
const u8 = new Uint8Array([1, 2, 3]);
const valuesBucket: sendableRelationalStore.NonSendableBucket = {
  age: 18,
  name: "hangman",
  salary: 100.5,
  passed: true,
  data1: asset1,
  blobType: u8,
  bigValue: BigInt("15822401018187971961171"),
  data2: [asset1, asset2]
};

const sendableValuesBucket = sendableRelationalStore.toSendableValuesBucket(valuesBucket);
```

## sendableRelationalStore.fromSendableValuesBucket

fromSendableValuesBucket(valuesBucket: ValuesBucket): NonSendableBucket

Converts a KV pair that can be passed across threads into the data that cannot be passed across threads.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Parameters**

| Name      | Type                         | Mandatory| Description                                |
| ------------ | ----------------------------- | ---- | :----------------------------------- |
| valuesBucket | [ValuesBucket](#valuesbucket) | Yes  | Data that can be passed across threads.|

**Return value**

| Type                                   | Description                              |
| --------------------------------------- | ---------------------------------- |
| [NonSendableBucket](#nonsendablebucket) | Data that cannot be passed across threads.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [RDB Store Error Codes](errorcode-data-rdb.md).

| **ID**| **Error Message**                                                                                                 |
| ------------ | ------------------------------------------------------------------------------------------------------------- |
| 401          | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 14800000     | Inner error.                                                                                                  |

**Example**

```ts
const asset1: sendableRelationalStore.NonSendableAsset = {
  name: 'hangman',
  uri: '//path/example',
  path: '//path/example',
  createTime: 'createTime1',
  modifyTime: 'modifyTime1',
  size: 'size1'
};
const asset2: sendableRelationalStore.NonSendableAsset = {
  name: 'hangman',
  uri: '//path/example',
  path: '//path/example',
  createTime: 'createTime1',
  modifyTime: 'modifyTime1',
  size: 'size1'
};
const u8 = new Uint8Array([1, 2, 3]);

const sendableValuesBucket = sendableRelationalStore.toSendableValuesBucket({
  age: 18,
  name: "hangman",
  salary: 100.5,
  passed: true,
  data1: asset1,
  blobType: u8,
  bigValue: BigInt("15822401018187971961171"),
  data2: [asset1, asset2]
});
const nonSendableBucket = sendableRelationalStore.fromSendableValuesBucket(sendableValuesBucket);
```

## sendableRelationalStore.toSendableAsset

function toSendableAsset(asset: NonSendableAsset): Asset

Converts the asset data that cannot be passed across threads into the data that can be passed across threads.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Parameters**

| Name| Type                                  | Mandatory| Description                       |
| ------ | -------------------------------------- | ---- | :-------------------------- |
| asset  | [NonSendableAsset](#nonsendablebucket) | Yes  | Asset data that cannot be passed across threads.|

**Return value**

| Type           | Description                     |
| --------------- | ------------------------- |
| [Asset](#asset) | Asset data that can be passed across threads.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [RDB Store Error Codes](errorcode-data-rdb.md).

| **ID**| **Error Message**                                                                                                 |
| ------------ | ------------------------------------------------------------------------------------------------------------- |
| 401          | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 14800000     | Inner error.                                                                                                  |

**Example**

```ts
const asset1: sendableRelationalStore.NonSendableAsset = {
  name: 'hangman',
  uri: '//path/example',
  path: '//path/example',
  createTime: 'createTime1',
  modifyTime: 'modifyTime1',
  size: 'size1'
};
const sendableAsset = sendableRelationalStore.toSendableAsset(asset1);
```

## sendableRelationalStore.fromSendableAsset

function fromSendableAsset(asset: Asset): NonSendableAsset

Converts the asset data that can be passed across threads into the data that cannot be passed across threads.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Parameters**

| Name| Type           | Mandatory| Description                     |
| ------ | --------------- | ---- | :------------------------ |
| asset  | [Asset](#asset) | Yes  | Asset data that can be passed across threads.|

**Return value**

| Type                                  | Description                       |
| -------------------------------------- | --------------------------- |
| [NonSendableAsset](#nonsendablebucket) | Asset data that cannot be passed across threads.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [RDB Store Error Codes](errorcode-data-rdb.md).

| **ID**| **Error Message**                                                                                                 |
| ------------ | ------------------------------------------------------------------------------------------------------------- |
| 401          | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 14800000     | Inner error.                                                                                                  |

**Example**

```ts
const asset1: sendableRelationalStore.NonSendableAsset = {
  name: 'hangman',
  uri: '//path/example',
  path: '//path/example',
  createTime: 'createTime1',
  modifyTime: 'modifyTime1',
  size: 'size1'
};
const sendableAsset = sendableRelationalStore.toSendableAsset(asset1);
const normalAsset = sendableRelationalStore.fromSendableAsset(sendableAsset);
```

## sendableRelationalStore.fromSendableValues<sup>20+</sup>

fromSendableValues(values: collections.Array\<ValueType>): NonSendableValues

Converts the array data that can be passed across threads into the data that cannot be passed across threads.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Parameters**

| Name| Type           | Mandatory| Description                     |
| ------ | --------------- | ---- | :------------------------ |
| values  | collections.Array\<[ValueType](arkts-apis-data-relationalStore-t.md#valuetype)> | Yes  | Array data that can be passed across threads.|

**Return value**

| Type                                  | Description                       |
| -------------------------------------- | --------------------------- |
| [NonSendableValues](#nonsendablevalues20) | Array data that cannot be passed across threads.|

**Error codes**

For details about the error codes, see [RDB Error Codes](errorcode-data-rdb.md).

| **ID**| **Error Message**                                                                                                 |
| ------------ | ------------------------------------------------------------------------------------------------------------- |
| 14800000     | Inner error.                                                                                                  |

**Example**

```ts
import { sendableRelationalStore } from '@kit.ArkData';
import { collections } from '@kit.ArkTS';
const array = new collections.Array<sendableRelationalStore.ValueType>();
array.push("a");
array.push("b");
array.push(1);
array.push(2);
const values = sendableRelationalStore.fromSendableValues(array);
```

## sendableRelationalStore.toSendableValues<sup>20+</sup>

toSendableValues(values: NonSendableValues): collections.Array\<ValueType>

Converts the array data that cannot be passed across threads into the data that can be passed across threads.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

**Parameters**

| Name| Type           | Mandatory| Description                     |
| ------ | --------------- | ---- | :------------------------ |
| values  | [NonSendableValues](#nonsendablevalues20) | Yes  | Array data that cannot be passed across threads.|

**Return value**

| Type                                  | Description                       |
| -------------------------------------- | --------------------------- |
| collections.Array\<[ValueType](arkts-apis-data-relationalStore-t.md#valuetype)> | Array data that can be passed across threads.|

**Error codes**

For details about the error codes, see [RDB Error Codes](errorcode-data-rdb.md).

| **ID**| **Error Message**                                                                                                 |
| ------------ | ------------------------------------------------------------------------------------------------------------- |
| 14800000     | Inner error.                                                                                                  |

**Example**

```ts
import { relationalStore, sendableRelationalStore } from '@kit.ArkData';
const array: relationalStore.ValueType[] = [];
array.push(1);
array.push(2);
array.push("aaaaaa")
const values = sendableRelationalStore.toSendableValues(array);
```

## Asset

Represent the asset (such as a document, image, or video). **Asset** inherits from [lang.ISendable](../apis-arkts/js-apis-arkts-lang.md#langisendable) and is used to implement cross-thread transfer of asset data. The asset data does not support **Datashare** APIs. Use [sendableRelationalStore.toSendableAsset](#sendablerelationalstoretosendableasset) to create an **Asset** instance.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

| Name      | Type  | Read-Only| Optional| Description                              |
| ---------- | ------ | ---  | ---- | ---------------------------------- |
| name       | string | No  | No  | Asset name.                      |
| uri        | string | No  | No  | Asset URI, which is an absolute path in the system.   |
| path       | string | No  | No  | Application sandbox path of the asset.          |
| createTime | string | No  | No  | Time when the asset was created.            |
| modifyTime | string | No  | No  | Time when the asset was last modified.        |
| size       | string | No  | No  | Size of the asset.              |
| status     | number | No  | Yes  | Asset status. For details, see [relationalStore.AssetStatus](arkts-apis-data-relationalStore-e.md#assetstatus10). The default value is **relationalStore.AssetStatus.ASSET_NORMAL**.|


## Assets

type Assets = collections.Array\<Asset>

Represent an array of [Assets](#asset), which allows assets to be passed across threads.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

| Type                                                                                              | Description                             |
| -------------------------------------------------------------------------------------------------- | --------------------------------- |
| [collections.Array](../apis-arkts/js-apis-arkts-collections.md#collectionsarray)\<[Asset](#asset)> | Array of assets.|

## ValueType

type ValueType = null | number | string | boolean | collection.Uint8Array | Asset | Assets | collection.Float32Array | bigint

Defines the types of the value in a KV pair. The type varies with the parameter function.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

| Type   | Description                |
| ------- | -------------------- |
| null    | The value is null.    |
| number  | The value is a number.  |
| string  | The value is a string.|
| boolean | The value is **true** or **false**.|
| [collection.Uint8Array](../apis-arkts/js-apis-arkts-collections.md#collectionstypedarray) | The value is a Uint8 array.|
| [Asset](#asset)  | The value is an asset.<br>If the value type is **Asset**, the type in the SQL statement for creating a table must be **ASSET**.            |
| [Assets](#assets) | The value is an array of assets.<br>If the value type is **Assets**, the type in the SQL statement for creating a table must be **ASSETS**.|
| [collection.Float32Array](../apis-arkts/js-apis-arkts-collections.md#collectionstypedarray) | The value is an array of 32-bit floating-point numbers.<br>If the value type is **collection.Float32Array**, the type in the SQL statement for creating a table must be **floatvector(128)**.|
| bigint | The value is an integer of any length.<br>If the value type is bigint, the type in the SQL statement for creating a table must be **UNLIMITED INT**. For details, see [Persisting RDB Store Data](../../database/data-persistence-by-rdb-store.md).<br>**NOTE**<br>The bigint type does not support value comparison and cannot be used with the following predicates: **between**, **notBetween**, **greaterThan**, **lessThan**, **greaterThanOrEqualTo**, **lessThanOrEqualTo**, **orderByAsc**, and **orderByDesc**<br>To write a value of bigint type, use **BigInt()** or add **n** to the end of the value, for example,'let data = BigInt(1234)' or 'let data = 1234n'.<br>If data of the number type is written to a bigint field, the type of the return value obtained (queried) is number but not bigint. |

## ValuesBucket

type ValuesBucket = collections.Map<string, ValueType>

Represents the KV pair of the [ValueType](#valuetype) data that can be passed across threads.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

| Type                                                                                                         | Description                                                                   |
| ------------------------------------------------------------------------------------------------------------- | ----------------------------------------------------------------------- |
| [collections.Map](../apis-arkts/js-apis-arkts-collections.md#collectionsmap)<string, [ValueType](#valuetype)> | KV pair that can be passed across threads. The key must be a string, and the value is of the **ValueType** type.|

## NonSendableBucket

type NonSendableBucket = relationalStore.ValuesBucket

Represents the KV pair that cannot be passed across threads.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

| Type                                                                          | Description                        |
| ------------------------------------------------------------------------------ | ---------------------------- |
| [relationalStore.ValuesBucket](arkts-apis-data-relationalStore-t.md#valuesbucket) | KV pair that cannot be passed across threads.|

## NonSendableValues<sup>20+</sup>

type NonSendableValues = Array\<relationalStore.ValueType>

Represents the [ValueType](arkts-apis-data-relationalStore-t.md#valuetype) array that cannot be passed across threads.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

| Type                                                              | Description                          |
| ------------------------------------------------------------------ | ------------------------------ |
| Array\<[relationalStore.ValueType](arkts-apis-data-relationalStore-t.md#valuetype)> | Array that cannot be passed across threads. The value type is **ValueType**.|

## NonSendableAsset

type NonSendableAsset = relationalStore.Asset

Represents the asset (such as a document, image, or video) that cannot be passed across threads.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

| Type                                                              | Description                          |
| ------------------------------------------------------------------ | ------------------------------ |
| [relationalStore.Asset](arkts-apis-data-relationalStore-i.md#asset10) | Asset that cannot be passed across threads.|

## Example of Cross-Thread Data Passing

When invoking TaskPool for data insertion, the main thread calls the **toSendableValuesBucket** method to convert data into a cross-thread transferable type, which is then passed to TaskPool for processing.

When invoking TaskPool for data query operations, call the **getSendableRow** method of **ResultSet** to obtain cross-thread transferable data rows, which are then returned to the main thread. In the main thread, invoke the **fromSendableValuesBucket** method to convert these rows into the standard **ValuesBucket** format for subsequent processing.

```ts
// Index.ets
import { relationalStore, sendableRelationalStore } from '@kit.ArkData';
import { taskpool } from '@kit.ArkTS';

@Concurrent
async function insert(context: Context, dataItem: sendableRelationalStore.ValuesBucket) {
  const CONFIG: relationalStore.StoreConfig = {
    name: "Store.db",
    securityLevel: relationalStore.SecurityLevel.S3,
  };

  let store = await relationalStore.getRdbStore(context, CONFIG);
  console.info(`Get store successfully!`);

  const CREATE_TABLE_SQL = "CREATE TABLE IF NOT EXISTS test (" +
    "id INTEGER PRIMARY KEY AUTOINCREMENT, " +
    "name TEXT NOT NULL, " +
    "age INTEGER, " +
    "salary REAL, " +
    "blobType BLOB)";
  await store.executeSql(CREATE_TABLE_SQL);
  console.info(`Create table test successfully!`);

  // Insert data.
  const rowId = await store.insertSync("test", dataItem);
  await store.close();
  return rowId;
}

@Concurrent
async function queryByName(context: Context, name: string) {
  const CONFIG: relationalStore.StoreConfig = {
    name: "Store.db",
    securityLevel: relationalStore.SecurityLevel.S3,
  };

  let store = await relationalStore.getRdbStore(context, CONFIG);
  console.info(`Get store successfully!`);

  const predicates = new relationalStore.RdbPredicates("test");
  predicates.equalTo("name", name);

  const resultSet = await store.query(predicates);
  if (resultSet.rowCount > 0 && resultSet.goToFirstRow()) {
    // Obtain the cross-thread transferable ValuesBucket to return the query result.
    return resultSet.getSendableRow();
  }
  return null;
}


@Entry
@Component
struct Index {
  @State message: string = 'Hello World';

  build() {
    RelativeContainer() {
      Text(this.message)
        .id('HelloWorld')
        .fontSize(50)
        .fontWeight(FontWeight.Bold)
        .alignRules({
          center: { anchor: '__container__', align: VerticalAlign.Center },
          middle: { anchor: '__container__', align: HorizontalAlign.Center }
        })
        .onClick(async () => {
          let context: Context = this.getUIContext().getHostContext() as Context;

          const item: relationalStore.ValuesBucket = {
            name: "zhangsan",
            age: 20,
            salary: 5000
          }
          // Call toSendableValuesBucket to convert the data type for cross-thread passing.
          const sendableItem = sendableRelationalStore.toSendableValuesBucket(item);
          const insertRowId = await taskpool.execute(insert, context, sendableItem) as number;
          console.info(`Insert data success, row id is: ${insertRowId}`);

          const rowData = await taskpool.execute(queryByName, context, "zhangsan");
          if (rowData) {
            const row =
              sendableRelationalStore.fromSendableValuesBucket(rowData as sendableRelationalStore.ValuesBucket);
            console.info(`Query success, name is ${row['name']}, age is ${row['age']}.`);
          } else {
            console.error(`Query failed.`)
          }
        })
    }
    .height('100%')
    .width('100%')
  }
}
```
