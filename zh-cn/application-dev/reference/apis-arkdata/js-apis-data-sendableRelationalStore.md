# @ohos.data.sendableRelationalStore (共享关系型数据库)

该模块针对关系型数据库（Relational Database，RDB）提供了sendable支持。支持从查询结果集中获取sendable类型ValuesBucket用于并发实例间传递。

> **说明：**
> 
> 本模块首批接口从API version 12开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## 导入模块

```ts
import { sendableRelationalStore } from '@kit.ArkData';
```

## sendableRelationalStore.toSendableValuesBucket

toSendableValuesBucket(valuesBucket: NonSendableBucket): ValuesBucket

将不能用于跨线程传递的键值对数据，转换为可用于跨线程传递的键值对数据。

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

**参数：**

| 参数名       | 类型                                    | 必填 | 说明                               |
| ------------ | --------------------------------------- | ---- | :--------------------------------- |
| valuesBucket | [NonSendableBucket](#nonsendablebucket) | 是   | 不可跨线程传递的ValuesBucket数据。 |

**返回值**：

| 类型                          | 说明                                 |
| ----------------------------- | ------------------------------------ |
| [ValuesBucket](#valuesbucket) | 可用于跨线程传递的ValuesBucket数据。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[关系型数据库错误码](errorcode-data-rdb.md)。

| **错误码ID** | **错误信息**                                                                                                                                    |
| ------------ | ----------------------------------------------------------------------------------------------------------------------------------------------- |
| 401          | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 14800000     | Inner error.                                                                                                                                    |

**示例：**

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

将可用于跨线程传递的键值对数据，转换为不能用于跨线程传递的键值对数据。

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

**参数：**

| 参数名       | 类型                          | 必填 | 说明                                 |
| ------------ | ----------------------------- | ---- | :----------------------------------- |
| valuesBucket | [ValuesBucket](#valuesbucket) | 是   | 可用于跨线程传递的ValuesBucket数据。 |

**返回值**：

| 类型                                    | 说明                               |
| --------------------------------------- | ---------------------------------- |
| [NonSendableBucket](#nonsendablebucket) | 不可跨线程传递的ValuesBucket数据。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[关系型数据库错误码](errorcode-data-rdb.md)。

| **错误码ID** | **错误信息**                                                                                                  |
| ------------ | ------------------------------------------------------------------------------------------------------------- |
| 401          | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 14800000     | Inner error.                                                                                                  |

**示例：**

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

将不可跨线程传递的附件数据，转换为可跨线程传递的附件数据。

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

**参数：**

| 参数名 | 类型                                   | 必填 | 说明                        |
| ------ | -------------------------------------- | ---- | :-------------------------- |
| asset  | [NonSendableAsset](#nonsendablebucket) | 是   | 不可跨线程传递的Asset数据。 |

**返回值**：

| 类型            | 说明                      |
| --------------- | ------------------------- |
| [Asset](#asset) | 可跨线程传递的Asset数据。 |

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[关系型数据库错误码](errorcode-data-rdb.md)。

| **错误码ID** | **错误信息**                                                                                                  |
| ------------ | ------------------------------------------------------------------------------------------------------------- |
| 401          | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 14800000     | Inner error.                                                                                                  |

**示例：**

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

将可跨线程传递的附件数据，转换为不可跨线程传递的附件数据。

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

**参数：**

| 参数名 | 类型            | 必填 | 说明                      |
| ------ | --------------- | ---- | :------------------------ |
| asset  | [Asset](#asset) | 是   | 可跨线程传递的Asset数据。 |

**返回值**：

| 类型                                   | 说明                        |
| -------------------------------------- | --------------------------- |
| [NonSendableAsset](#nonsendablebucket) | 不可跨线程传递的Asset数据。 |


以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[关系型数据库错误码](errorcode-data-rdb.md)。

| **错误码ID** | **错误信息**                                                                                                  |
| ------------ | ------------------------------------------------------------------------------------------------------------- |
| 401          | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 14800000     | Inner error.                                                                                                  |

**示例：**

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

记录资产附件（文件、图片、视频等类型文件）的相关信息。用于支持资产数据跨线程传递，继承自[lang.ISendable](../apis-arkts/js-apis-arkts-lang.md#langisendable)。资产类型的相关接口暂不支持Datashare。使用[sendableRelationalStore.toSendableAsset](#sendablerelationalstoretosendableasset)方法创建。

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

| 名称       | 类型   | 只读 | 可选 | 说明                               |
| ---------- | ------ | ---  | ---- | ---------------------------------- |
| name       | string | 否   | 否   | 资产的名称。                       |
| uri        | string | 否   | 否   | 资产的uri，在系统里的绝对路径。    |
| path       | string | 否   | 否   | 资产在应用沙箱里的路径。           |
| createTime | string | 否   | 否   | 资产被创建出来的时间。             |
| modifyTime | string | 否   | 否   | 资产最后一次被修改的时间。         |
| size       | string | 否   | 否   | 资产占用空间的大小。               |
| status     | number | 否   | 是   | 资产的状态, 取值与[relationalStore.AssetStatus](./js-apis-data-relationalStore.md#assetstatus10)枚举值保持一致，默认值为relationalStore.AssetStatus.ASSET_NORMAL。|


## Assets

type Assets = collections.Array\<Asset>

表示[Asset](#asset)类型数据的集合。用于支持Asset数据集合跨线程传递。

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

| 类型                                                                                               | 说明                              |
| -------------------------------------------------------------------------------------------------- | --------------------------------- |
| [collections.Array](../apis-arkts/js-apis-arkts-collections.md#collectionsarray)\<[Asset](#asset)> | 用于并发场景的Asset附件数据集合。 |

## ValueType

type ValueType = null | number | string | boolean | collection.Uint8Array | Asset | Assets | collection.Float32Array | bigint

用于表示允许的数据字段类型，接口参数具体类型根据其功能而定。

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

| 类型    | 说明                 |
| ------- | -------------------- |
| null    | 表示值类型为空。     |
| number  | 表示值类型为数字。   |
| string  | 表示值类型为字符串。 |
| boolean | 表示值类型为布尔值。 |
| [collection.Uint8Array](../apis-arkts/js-apis-arkts-collections.md#collectionstypedarray) | 表示值类型为Uint8类型的数组。|
| [Asset](#asset)  | 表示值类型为附件Asset。<br/>当字段类型是Asset时，在创建表的sql语句中，类型应当为：ASSET。             |
| [Assets](#assets) | 表示值类型为附件数据集合Assets。<br/>当字段类型是Assets时，在创建表的sql语句中，类型应当为：ASSETS。 |
| [collection.Float32Array](../apis-arkts/js-apis-arkts-collections.md#collectionstypedarray) | 表示值类型为浮点数组。<br/>当字段类型是collection.Float32Array时，在创建表的sql语句中，类型应当为：floatvector(128)。 |
| bigint | 表示值类型为任意长度的整数。<br/>当字段类型是bigint时，在创建表的sql语句中，类型应当为：UNLIMITED INT, 详见[通过关系型数据库实现数据持久化](../../database/data-persistence-by-rdb-store.md)。<br/>**说明：** bigint类型当前不支持比较大小，不支持如下谓词：between、notBetween、greaterThanlessThan、greaterThanOrEqualTo、lessThanOrEqualTo、orderByAsc、orderByDesc。<br/>bigint类型字段的数据写入时，需通过BigInt()方法或在数据尾部添加'n'的方式明确为bigint类型，如'let data = BigInt(1234)'或'let data = 1234n'。<br/>bigint字段如果写入number类型的数据，则查询该数据的返回类型为number，而非bigint。 |

## ValuesBucket

type ValuesBucket = collections.Map<string, ValueType>

表示[ValueType](#valuetype)数据的键值对存储，用于支持ValueType数据跨线程传递。

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

| 类型                                                                                                          | 说明                                                                    |
| ------------------------------------------------------------------------------------------------------------- | ----------------------------------------------------------------------- |
| [collections.Map](../apis-arkts/js-apis-arkts-collections.md#collectionsmap)<string, [ValueType](#valuetype)> | 并发场景的键值对数据存储，其中，键的类型为string，值的类型为ValueType。 |

## NonSendableBucket

type NonSendableBucket = relationalStore.ValuesBucket

用于存储键值对的类型。不支持跨线程传递。

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

| 类型                                                                           | 说明                         |
| ------------------------------------------------------------------------------ | ---------------------------- |
| [relationalStore.ValuesBucket](./js-apis-data-relationalStore.md#valuesbucket) | 非并发场景的键值对数据存储。 |

## NonSendableAsset

type NonSendableAsset = relationalStore.Asset

记录资产附件（文件、图片、视频等类型文件）的相关信息。不支持跨线程传递。

**系统能力：** SystemCapability.DistributedDataManager.RelationalStore.Core

| 类型                                                               | 说明                           |
| ------------------------------------------------------------------ | ------------------------------ |
| [relationalStore.Asset](./js-apis-data-relationalStore.md#asset10) | 非并发场景的资产附件数据存储。 |