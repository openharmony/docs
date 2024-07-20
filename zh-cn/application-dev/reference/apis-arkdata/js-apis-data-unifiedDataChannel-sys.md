# @ohos.data.unifiedDataChannel (标准化数据通路)(系统接口)

本模块为统一数据管理框架（Unified Data Management Framework,UDMF）的组成部分，针对拖拽通道的数据分享的范围，提供应用级别的管控，允许设置应用内数据的拖拽范围。

> **说明：**
>
> - 本模块首批接口从API version 10开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>
> - 当前页面仅包含本模块的系统接口，其他公开接口参见[ @ohos.data.unifiedDataChannel](js-apis-data-unifiedDataChannel.md)。

## 导入模块

```ts
import { unifiedDataChannel } from '@kit.ArkData';
```

## Intention

UDMF已经支持的数据通路枚举类型。其主要用途是标识各种UDMF数据通路所面向的不同业务场景。

**系统能力：** SystemCapability.DistributedDataManager.UDMF.Core

| 名称 | 值     | 说明                                |
| ---- | ------ | ----------------------------------- |
| DRAG<sup>12+</sup> | 'Drag' | 拖拽类型数据通道。<br/>**模型约束：** 此接口仅可在Stage模型下使用。<br/>**系统接口：** 此接口为系统接口。 |

## unifiedDataChannel.setAppShareOptions<sup>12+</sup>

setAppShareOptions(intention: Intention, shareOptions: ShareOptions): void

设置应用内拖拽通道数据可使用的范围[ShareOptions](js-apis-data-unifiedDataChannel.md#shareoptions12)，目前仅支持DRAG类型数据通道的管控设置。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.DistributedDataManager.UDMF.Core

**参数：**

| 参数名      | 类型                         | 必填 | 说明                           |
|----------|----------------------------|----|------------------------------|
| intention | [Intention](#intention) | 是  | 表示数据操作相关的数据通路类型，目前仅支持DRAG类型数据通道。 |
| shareOptions | [ShareOptions](js-apis-data-unifiedDataChannel.md#shareoptions12) | 是  | 指示[UnifiedData](js-apis-data-unifiedDataChannel.md#unifieddata)支持的设备内使用范围。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[统一数据管理框架错误码](errorcode-udmf.md)。

| **错误码ID** | **错误信息**                                                 |
| ------------ | ------------------------------------------------------------ |
| 202          | Permission verification failed, application which is not a system application uses system API. |
| 401          | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 20400001     | Settings already exist.                                      |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
try {
  unifiedDataChannel.setAppShareOptions(unifiedDataChannel.Intention.DRAG, unifiedDataChannel.ShareOptions.IN_APP);
  console.info(`[UDMF]setAppShareOptions success. `);
}catch (e){
  let error: BusinessError = e as BusinessError;
  console.error(`[UDMF]setAppShareOptions throws an exception. code is ${error.code},message is ${error.message} `);
}
```

## unifiedDataChannel.removeAppShareOptions<sup>12+</sup>

removeAppShareOptions(intention: Intention): void

清除[setAppShareOptions](#unifieddatachannelsetappshareoptions12)设置的管控信息。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.DistributedDataManager.UDMF.Core

**参数：**

| 参数名    | 类型                    | 必填 | 说明                                                         |
| --------- | ----------------------- | ---- | ------------------------------------------------------------ |
| intention | [Intention](#intention) | 是   | 表示数据操作相关的数据通路类型，目前仅支持DRAG类型数据通道。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| **错误码ID** | **错误信息**                                                 |
| ------------ | ------------------------------------------------------------ |
| 202          | Permission verification failed, application which is not a system application uses system API. |
| 401          | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
try {
  unifiedDataChannel.removeAppShareOptions(unifiedDataChannel.Intention.DRAG);
  console.info(`[UDMF]removeAppShareOptions success. `);
}catch (e){
  let error: BusinessError = e as BusinessError;
  console.error(`[UDMF]removeAppShareOptions throws an exception. code is ${error.code},message is ${error.message} `);
}
```
