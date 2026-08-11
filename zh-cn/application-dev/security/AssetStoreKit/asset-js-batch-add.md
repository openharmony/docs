# 批量新增关键资产(ArkTS)

<!--Kit: Asset Store Kit-->
<!--Subsystem: Security-->
<!--Owner: @HarMonkey-->
<!--Designer: @wkr321_ent-->
<!--Tester: @nacyli-->
<!--Adviser: @zengyawen-->

## 接口介绍

从版本26.0.0开始，系统提供异步接口[batchAdd](../../reference/apis-asset-store-kit/js-apis-asset.md#assetbatchadd)以便开发者批量新增关键资产。

在批量新增关键资产时，关键资产属性的内容（AssetMap）参数如下表所示：

> **注意：**
>
> 下表中“ALIAS”和名称包含“DATA_LABEL”的关键资产属性，用于存储业务自定义信息，其内容不会被加密，请勿存放敏感个人数据。

| 属性名称（Tag）        | 属性内容（Value）                                             | 是否必选  | 说明                                                         |
| --------------------- | ------------------------------------------------------------ | -------- | ------------------------------------------------------------ |
| SECRET                | 类型为Uint8Array，长度为1-1024字节。                           | 必选     | 关键资产明文。                                              |
| ALIAS                 | 类型为Uint8Array，长度为1-256字节。                            | 必选     | 关键资产别名，每条关键资产的唯一索引。                        |
| ACCESSIBILITY         | 类型为number，取值范围详见[Accessibility](../../reference/apis-asset-store-kit/js-apis-asset.md#accessibility)。 | 可选     | 基于锁屏状态的访问控制，默认值为DEVICE_FIRST_UNLOCKED，即首次解锁后可访问。      |
| REQUIRE_PASSWORD_SET  | 类型为boolean。                                                   | 可选     | 是否仅在设置了锁屏密码的情况下，可访问关键资产。为true时，表示仅在用户设置了锁屏密码的情况下，关键资产才允许被访问；为false时，表示无论用户是否设置锁屏密码，关键资产均允许被访问。默认值为false。              |
| AUTH_TYPE             | 类型为number，取值范围详见[AuthType](../../reference/apis-asset-store-kit/js-apis-asset.md#authtype)。 | 可选     | 访问关键资产所需的用户认证类型，默认值为NONE，即访问关键资产前无需用户认证。         |
| SYNC_TYPE             | 类型为number，取值范围详见[SyncType](../../reference/apis-asset-store-kit/js-apis-asset.md#synctype)。 | 可选     | 关键资产支持的同步类型，默认值为NEVER，即不允许同步该关键资产。                |
| IS_PERSISTENT         | 类型为boolean。                                                   | 可选     | 在应用卸载时是否需要保留关键资产。为true时表示应用卸载后，应用存储的关键资产将被保留；为false时表示应用卸载后，应用存储的关键资产将被删除。默认值为false。<br>**注意：** 设置此属性时，需[申请权限](../AccessToken/declare-permissions.md)ohos.permission.STORE_PERSISTENT_DATA。 |
| DATA_LABEL_CRITICAL_1 | 类型为Uint8Array，长度为1-2048字节。                         | 可选     | 关键资产附属信息，内容由业务自定义且有完整性保护。<br/>**说明：** 在API version 12及之前版本，长度为1-512字节。 |
| DATA_LABEL_CRITICAL_2 | 类型为Uint8Array，长度为1-2048字节。                       | 可选     | 关键资产附属信息，内容由业务自定义且有完整性保护。<br/>**说明：** 在API version 12及之前版本，长度为1-512字节。 |
| DATA_LABEL_CRITICAL_3 | 类型为Uint8Array，长度为1-2048字节。                        | 可选     | 关键资产附属信息，内容由业务自定义且有完整性保护。<br/>**说明：** 在API version 12及之前版本，长度为1-512字节。 |
| DATA_LABEL_CRITICAL_4 | 类型为Uint8Array，长度为1-2048字节。                        | 可选     | 关键资产附属信息，内容由业务自定义且有完整性保护。<br/>**说明：** 在API version 12及之前版本，长度为1-512字节。 |
| DATA_LABEL_NORMAL_1   | 类型为Uint8Array，长度为1-2048字节。                        | 可选     | 关键资产附属信息，内容由业务自定义且无完整性保护。<br/>**说明：** 在API version 12及之前版本，长度为1-512字节。 |
| DATA_LABEL_NORMAL_2   | 类型为Uint8Array，长度为1-2048字节。                        | 可选     | 关键资产附属信息，内容由业务自定义且无完整性保护。<br/>**说明：** 在API version 12及之前版本，长度为1-512字节。 |
| DATA_LABEL_NORMAL_3   | 类型为Uint8Array，长度为1-2048字节。                        | 可选     | 关键资产附属信息，内容由业务自定义且无完整性保护。<br/>**说明：** 在API version 12及之前版本，长度为1-512字节。 |
| DATA_LABEL_NORMAL_4   | 类型为Uint8Array，长度为1-2048字节。                        | 可选     | 关键资产附属信息，内容由业务自定义且无完整性保护。<br/>**说明：** 在API version 12及之前版本，长度为1-512字节。 |
| DATA_LABEL_NORMAL_LOCAL_1<sup>12+</sup> | 类型为Uint8Array，长度为1-2048字节。 | 可选 | 关键资产附属的本地信息，内容由业务自定义且无完整性保护，该项信息不会进行同步。 |
| DATA_LABEL_NORMAL_LOCAL_2<sup>12+</sup> | 类型为Uint8Array，长度为1-2048字节。 | 可选 | 关键资产附属的本地信息，内容由业务自定义且无完整性保护，该项信息不会进行同步。 |
| DATA_LABEL_NORMAL_LOCAL_3<sup>12+</sup> | 类型为Uint8Array，长度为1-2048字节。 | 可选 | 关键资产附属的本地信息，内容由业务自定义且无完整性保护，该项信息不会进行同步。 |
| DATA_LABEL_NORMAL_LOCAL_4<sup>12+</sup> | 类型为Uint8Array，长度为1-2048字节。 | 可选 | 关键资产附属的本地信息，内容由业务自定义且无完整性保护，该项信息不会进行同步。 |
| CONFLICT_RESOLUTION   | 类型为number，取值范围详见[ConflictResolution](../../reference/apis-asset-store-kit/js-apis-asset.md#conflictresolution)。 | 可选     | 新增关键资产时的冲突（如：别名相同）处理策略，默认值为THROW_ERROR，即抛出异常，由业务进行后续处理。  |
| REQUIRE_ATTR_ENCRYPTED<sup>14+</sup> | 类型为boolean。 | 可选 | 是否加密业务自定义附属信息。为true时表示业务自定义附属信息加密存储，为false时表示业务自定义附属信息不加密存储。默认值为false。|
| GROUP_ID<sup>18+</sup> | 类型为Uint8Array，长度为7-127字节。 | 可选 | 待新增的关键资产所属群组，默认新增不属于任何群组的关键资产。|
| WRAP_TYPE<sup>18+</sup> | 类型为number，取值范围详见[WrapType](../../reference/apis-asset-store-kit/js-apis-asset.md#wraptype18)。 | 可选 | 关键资产支持的加密导入导出类型，默认值为NEVER，即不允许加密导入导出关键资产。|

## 约束和限制

- 基于别名的访问。

  关键资产以密文的形式存储在ASSET数据库中，以业务身份 + 别名作为唯一索引。故业务需要保证每条关键资产的别名唯一。

- 业务自定义数据存储。

  ASSET为业务预留了12个关键资产自定义属性，名称以“DATA_LABEL”开头。对于超过12个自定义属性的情况，业务可以将多段数据按照一定的格式（如JSON）拼接到同一个ASSET属性中。

  ASSET对以“DATA_LABEL_CRITICAL”开头的属性提供完整性保护，写入后不可更新。

- 批量新增限制。

  批量新增的关键资产必须具有相同的[GROUP_ID](../../reference/apis-asset-store-kit/js-apis-asset.md#tag)和[REQUIRE_ATTR_ENCRYPTED](../../reference/apis-asset-store-kit/js-apis-asset.md#tag)属性。

  批量新增的关键资产数量最大值为100。

## 开发步骤

> **说明：**
>
> 以下为批量新增接口的使用示例。

批量新增两条关键资产，密码分别为demo_pwd1和demo_pwd2，别名分别为demo_alias1和demo_alias2。

1. 引用头文件，定义工具函数。
   <!-- @[import](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Security/AssetStoreKit/AssetStoreArkTS/entry/src/main/ets/operations/batch_operation.ets) -->
   
   ``` TypeScript
   import { asset } from '@kit.AssetStoreKit';
   import { util } from '@kit.ArkTS';
   import { BusinessError } from '@kit.BasicServicesKit';
   
   function stringToArray(str: string): Uint8Array {
     let textEncoder = new util.TextEncoder();
     return textEncoder.encodeInto(str);
   }
   ```

2. 参考如下示例代码，进行业务功能开发。
   <!-- @[batch_add](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Security/AssetStoreKit/AssetStoreArkTS/entry/src/main/ets/operations/batch_operation.ets) -->
   
   ``` TypeScript
   let attributesArray: asset.AssetMap[] = [];
   let attr1: asset.AssetMap = new Map();
   attr1.set(asset.Tag.SECRET, stringToArray('demo_pwd1'));
   attr1.set(asset.Tag.ALIAS, stringToArray('demo_alias1'));
   attributesArray.push(attr1);
   
   let attr2: asset.AssetMap = new Map();
   attr2.set(asset.Tag.SECRET, stringToArray('demo_pwd2'));
   attr2.set(asset.Tag.ALIAS, stringToArray('demo_alias2'));
   attributesArray.push(attr2);
   
   try {
     asset.batchAdd(attributesArray).then((res: asset.BatchResult) => {
       console.info(`Succeeded in batch adding Asset, failedCount: ${res.failedCount}`);
       if (res.failedCount > 0) {
         for (let i = 0; i < res.failedErrorInfos.length; i++) {
           console.error(`Failed to add Asset at index ${res.failedErrorInfos[i].index},
             errCode: ${res.failedErrorInfos[i].errCode}, message: ${res.failedErrorInfos[i].message}`);
         }
       }
     }).catch((err: BusinessError) => {
       console.error(`Failed to batch add Asset. Code is ${err.code}, message is ${err.message}`);
     })
   } catch (error) {
     let err = error as BusinessError;
     console.error(`Failed to batch add Asset. Code is ${err.code}, message is ${err.message}`);
   }
   ```