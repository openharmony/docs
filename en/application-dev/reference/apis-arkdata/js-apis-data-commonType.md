# @ohos.data.commonType (Common Data Types)
<!--Kit: ArkData-->
<!--Subsystem: DistributedDataManager-->
<!--Owner: @lvcong_oh-->
<!--Designer: @hollokin; @yuchaozhng-->
<!--Tester: @lj_liujing; @yippo; @logic42-->
<!--Adviser: @ge-yafang-->

The **commonType** module defines common data types in data management.

> **NOTE**
>
> The initial APIs of this module are supported since API version 11. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```ts
import { commonType } from '@kit.ArkData';
```

## AssetStatus

Enumerates the asset statuses. Use the enum name rather than the enum value.

**System capability**: SystemCapability.DistributedDataManager.CommonType

| Name             | Value | Description                        |
| ----------------- | --- | ---------------------------- |
| ASSET_NORMAL      | 1   | The asset is in normal status.          |
| ASSET_INSERT      | 2   | The asset is to be inserted to the cloud.    |
| ASSET_UPDATE      | 3   | The asset is to be updated to the cloud.    |
| ASSET_DELETE      | 4   | The asset is to be deleted from the cloud.    |
| ASSET_ABNORMAL    | 5   | The asset is in abnormal status.          |
| ASSET_DOWNLOADING | 6   | The asset is being downloaded to a local device.|

## Asset

Represents asset (such as a file, image, or video) information. For details, see the sample code in [Using Distributed Data Objects in Cross-Device Migration](../../database/data-sync-of-distributed-data-object.md#using-distributed-data-objects-in-cross-device-migration).

**System capability**: SystemCapability.DistributedDataManager.CommonType

| Name      | Type                       | Mandatory| Description                              |
| ---------- | --------------------------- | ---- | ---------------------------------- |
| name       | string                      | Yes  | Asset name.                      |
| uri        | string                      | Yes  | Asset URI, which is an absolute path in the system.   |
| path       | string                      | Yes  | Application sandbox path of the asset.          |
| createTime | string                      | Yes  | Time when the asset was created.            |
| modifyTime | string                      | Yes  | Time when the asset was last modified.        |
| size       | string                      | Yes  | Size of the asset.              |
| status     | [AssetStatus](#assetstatus) | No  | Asset status. The default value is **ASSET_NORMAL**.|

## Assets

type Assets = Array\<Asset>

Represents an array of [Assets](#asset).

**System capability**: SystemCapability.DistributedDataManager.CommonType

| Type                        | Description                 |
| ---------------------------- | --------------------- |
| Array&lt;[Asset](#asset)&gt; | Array of assets.|

## ValueType

type ValueType = null | number | string | boolean | Uint8Array | Asset | Assets

Enumerates the value types, which vary with the parameter function.

**System capability**: SystemCapability.DistributedDataManager.CommonType

| Type      | Description                                   |
| ---------- | --------------------------------------- |
| null       | The value is null.                       |
| number     | The value is a number.                     |
| string     | The value is a string.                   |
| boolean    | The value is true or false.                   |
| Uint8Array | The value is a Uint8 array.          |
| Asset      | The value is an [Asset](#asset).      |
| Assets     | The value is an array of [Assets](#assets).|

## ValuesBucket

type ValuesBucket = Record<string, ValueType>

Defines the types of the key and value in a KV pair. This type is not multi-thread safe. If a **ValuesBucket** instance is operated by multiple threads at the same time in an application, use a lock for the instance.

**System capability**: SystemCapability.DistributedDataManager.CommonType

| Type| Description                 |
| ------ | ----------------------- |
| Record<string, [ValueType](#valuetype)> | Types of the key and value in a KV pair. The key type is string, and the value type is [ValueType](#valuetype).|
