# @ohos.data.sendableRelationalStore (Shared RDB Store)

The **sendableRelationalStore** module provides APIs for obtaining **ValuesBucket** of the sendable type from the query result set and transferring it between concurrent instances.

> **NOTE**
> 
> The initial APIs of this module are supported since API version 12. Newly added APIs will be marked with a superscript to indicate their earliest API version.

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
| valuesBucket | [NonSendableBucket](#nonsendablebucket) | Yes  | Data that cannot be passed across threads. |

**Return value**

| Type                         | Description                                |
| ----------------------------- | ------------------------------------ |
| [ValuesBucket](#valuesbucket) | Data that can be passed across threads. |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [RDB Store Error Codes](errorcode-data-rdb.md).

| **Error Code**| **Error Message**                                                                                                                                   |
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
  size: 'size1',
};
const asset2: sendableRelationalStore.NonSendableAsset = {
  name: 'hangman',
  uri: '//path/example',
  path: '//path/example',
  createTime: 'createTime1',
  modifyTime: 'modifyTime1',
  size: 'size1',
}
const u8 = new Uint8Array([1, 2, 3]);
const valuesBucket: sendableRelationalStore.NonSendableBucket = {
  age: 18,
  name: "hangman",
  salary: 100.5,
  passed: true,
  data1: asset1,
  blobType: u8,
  bigValue: BigInt("15822401018187971961171"),
  data2: [asset1, asset2],
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
| valuesBucket | [ValuesBucket](#valuesbucket) | Yes  | Data that can be passed across threads. |

**Return value**

| Type                                   | Description                              |
| --------------------------------------- | ---------------------------------- |
| [NonSendableBucket](#nonsendablebucket) | Data that cannot be passed across threads. |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [RDB Store Error Codes](errorcode-data-rdb.md).

| **Error Code**| **Error Message**                                                                                                 |
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
  size: 'size1',
};
const asset2: sendableRelationalStore.NonSendableAsset = {
  name: 'hangman',
  uri: '//path/example',
  path: '//path/example',
  createTime: 'createTime1',
  modifyTime: 'modifyTime1',
  size: 'size1',
}
const u8 = new Uint8Array([1, 2, 3]);

const sendableValuesBucket = sendableRelationalStore.toSendableValuesBucket({
  age: 18,
  name: "hangman",
  salary: 100.5,
  passed: true,
  data1: asset1,
  blobType: u8,
  bigValue: BigInt("15822401018187971961171"),
  data2: [asset1, asset2],
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
| asset  | [NonSendableAsset](#nonsendablebucket) | Yes  | Asset data that cannot be passed across threads. |

**Return value**

| Type           | Description                     |
| --------------- | ------------------------- |
| [Asset](#asset) | Asset data that can be passed across threads. |

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [RDB Store Error Codes](errorcode-data-rdb.md).

| **Error Code**| **Error Message**                                                                                                 |
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
  size: 'size1',
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
| asset  | [Asset](#asset) | Yes  | Asset data that can be passed across threads. |

**Return value**

| Type                                  | Description                       |
| -------------------------------------- | --------------------------- |
| [NonSendableAsset](#nonsendablebucket) | Asset data that cannot be passed across threads. |


For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [RDB Store Error Codes](errorcode-data-rdb.md).

| **Error Code**| **Error Message**                                                                                                 |
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
  size: 'size1',
};
const sendableAsset = sendableRelationalStore.toSendableAsset(asset1);
const normalAsset = sendableRelationalStore.fromSendableAsset(sendableAsset);
```

## Asset

Represent information about an asset (such as a document, image, or video). **Asset** inherits from [lang.ISendable](../apis-arkts/js-apis-arkts-lang.md#langisendable) and is used to implement cross-thread transfer of asset data. The asset data does not support **Datashare** APIs. Use [sendableRelationalStore.toSendableAsset](#sendablerelationalstoretosendableasset) to create an **Asset** instance.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

| Name      | Type  | Read-Only| Optional| Description                              |
| ---------- | ------ | ---  | ---- | ---------------------------------- |
| name       | string | No  | No  | Asset name.                      |
| uri        | string | No  | No  | Asset URI, which is an absolute path in the system.   |
| path       | string | No  | No  | Application sandbox path of the asset.          |
| createTime | string | No  | No  | Time when the asset was created.            |
| modifyTime | string | No  | No  | Time when the asset was last modified.        |
| size       | string | No  | No  | Size of the asset.              |
| status     | number | No  | Yes  | Asset status. For details, see [relationalStore.AssetStatus](./js-apis-data-relationalStore.md#assetstatus10). The default value is **relationalStore.AssetStatus.ASSET_NORMAL**.|


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
| bigint | The value is an integer of any length.<br>If the value type is bigint, the type in the SQL statement for creating a table must be **UNLIMITED INT**. For details, see [Persisting RDB Store Data](../../database/data-persistence-by-rdb-store.md).<br>**NOTE**<br><br>The bigint type does not support value comparison and cannot be used with the following predicates: **between**, **notBetween**, **greaterThanlessThan**, **greaterThanOrEqualTo**, **lessThanOrEqualTo**, **orderByAsc**, and **orderByDesc**<br>To write a value of bigint type, use **BigInt()** or add **n** to the end of the value, for example, 'let data = BigInt(1234)' or 'let data = 1234n'.<br>If data of the number type is written to a bigint field, the type of the return value obtained (queried) is number but not bigint. |

## ValuesBucket

type ValuesBucket = collections.Map<string, ValueType>

Represents the KV pair that can be passed across threads.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

| Type                                                         | Description                                                  |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| [collections.Map](../apis-arkts/js-apis-arkts-collections.md#collectionsmap)<string, [ValueType](#valuetype)> | KV pair that can be passed across threads. The key must be a string, and the value is of the **ValueType** type. |

## NonSendableBucket

type NonSendableBucket = relationalStore.ValuesBucket

Represents the KV pair that cannot be passed across threads.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

| Type                                                                          | Description                        |
| ------------------------------------------------------------------------------ | ---------------------------- |
| [relationalStore.ValuesBucket](./js-apis-data-relationalStore.md#valuesbucket) | KV pair that cannot be passed across threads. |

## NonSendableAsset

type NonSendableAsset = relationalStore.Asset

Represent the asset (such as a document, image, or video) that cannot be passed across threads.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

| Type                                                              | Description                          |
| ------------------------------------------------------------------ | ------------------------------ |
| [relationalStore.Asset](./js-apis-data-relationalStore.md#asset10) | Asset that cannot be passed across threads. |
