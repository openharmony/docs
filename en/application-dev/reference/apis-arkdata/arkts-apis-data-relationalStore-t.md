# Types
<!--Kit: ArkData-->
<!--Subsystem: DistributedDataManager-->
<!--Owner: @baijidong-->
<!--Designer: @widecode; @htt1997-->
<!--Tester: @yippo; @logic42-->
<!--Adviser: @ge-yafang-->

> **NOTE**
> 
> The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Assets<sup>10+</sup>

type Assets = Asset[]

Indicates an [Asset](arkts-apis-data-relationalStore-i.md#asset10) array.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

| Type   | Description                |
| ------- | -------------------- |
| [Asset](arkts-apis-data-relationalStore-i.md#asset10)[] | Array of assets.  |

## ValueType

type ValueType = null | number | string | boolean | Uint8Array | Asset | Assets | Float32Array | bigint

Defines the types of the value in a KV pair. The type varies with the parameter function.

**System capability**: SystemCapability.DistributedDataManager.RelationalStore.Core

| Type   | Description                |
| ------- | -------------------- |
| null<sup>10+</sup>    | Null.  |
| number  | Number.  |
| string  | String. |
| boolean | Boolean.|
| Uint8Array<sup>10+</sup>           | Uint8 array.           |
| Asset<sup>10+</sup>  | [Asset](arkts-apis-data-relationalStore-i.md#asset10).<br>If the value type is Asset, the type in the SQL statement for creating a table must be ASSET.|
| Assets<sup>10+</sup> | [Assets](#assets10).<br>If the value type is Assets, the type in the SQL statement for creating a table must be ASSETS.|
| Float32Array<sup>12+</sup> | Array of 32-bit floating-point numbers.<br>If the field type is Float32Array, the type in the SQL statement for creating a table must be floatvector(128).|
| bigint<sup>12+</sup> | Integer of any length.<br>If the value type is bigint, the type in the SQL statement for creating a table must be **UNLIMITED INT**. For details, see [Persisting RDB Store Data](../../database/data-persistence-by-rdb-store.md).<br>Note: The bigint type does not support value comparison and cannot be used with the following predicates: **between**, **notBetween**, **greaterThan**, **lessThan**, **greaterThanOrEqualTo**, **lessThanOrEqualTo**, **orderByAsc**, and **orderByDesc**<br>To write a value of bigint type, use **BigInt()** or add **n** to the end of the value, for example,'let data = BigInt(1234)' or 'let data = 1234n'.<br>If data of the number type is written to a bigint field, the type of the return value obtained (queried) is number but not bigint. |

## ValuesBucket

type ValuesBucket = Record<string, ValueType>

Defines the data in the form of a KV pair. **ValuesBucket** cannot be passed across threads using Sendable.

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
