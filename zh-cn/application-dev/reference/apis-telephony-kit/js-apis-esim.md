# @ohos.telephony.esim (eSIM卡管理)
<!--Kit: Telephony Kit-->
<!--Subsystem: Telephony-->
<!--Owner: @Fanyl8-->
<!--Designer: @ghxbob-->
<!--Tester: @weitiantian-->
<!--Adviser: @zhang_yixin13-->

本模块提供了eSIM卡管理的基础能力，包括获取指定卡槽是否支持eSIM功能，如果支持则允许用户添加单个配置文件。

> **说明：**
>
> 本模块首批接口从API version 18开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>

## 导入模块

```ts
import { eSIM } from '@kit.TelephonyKit';
```

## eSIM.isSupported

isSupported\(slotId: number\): boolean

获取指定卡槽是否支持eSIM功能。

**系统能力**：SystemCapability.Telephony.CoreService.Esim

**参数：**

| 参数名 | 类型   | 必填 | 说明                                   |
| ------ | ------ | ---- | -------------------------------------- |
| slotId | number | 是   | 卡槽ID。<br/>- 0：卡槽1。<br/>- 1：卡槽2。 |

**返回值：**

| 类型                  | 说明                               |
| --------------------- | ---------------------------------- |
| boolean | 返回指定卡槽是否支持eSIM功能，如果支持返回true，不支持返回false。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)。

| 错误码ID              | 错误信息                           |
| --------------------- | ---------------------------------- |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verification failed.   |
|3120001| Service connection failed. |
|3120002| System internal error.     |

**示例：**

```ts
import { eSIM } from '@kit.TelephonyKit';

let isSupported: boolean = eSIM.isSupported(1);
console.info(`the esim is Supported:` + isSupported);
```

## eSIM.addProfile

addProfile\(profile: DownloadableProfile\): Promise\<boolean\>

当用户需要激活新eSIM（如新开卡或换卡）时，调用此接口引导完成配置文件的下载与添加流程。使用Promise异步回调。

**需要权限**：ohos.permission.SET_TELEPHONY_ESIM_STATE_OPEN

**系统能力**：SystemCapability.Telephony.CoreService.Esim

**参数：**

| 参数名 | 类型                                            | 必填 | 说明                                   |
| ------ |-----------------------------------------------| ---- | -------------------------------------- |
| profile | [DownloadableProfile](#downloadableprofile) | 是   | 可下载的配置文件信息。 |

**返回值：**

| 类型                  | 说明                               |
| --------------------- | ---------------------------------- |
| Promise\<boolean\> | 以Promise形式返回用户添加单个配置文件的结果。返回true表示成功，false表示失败。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)。

| 错误码ID              | 错误信息                           |
| --------------------- | ---------------------------------- |
| 201 | Permission denied.           |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verification failed.     |
| 801 | Capability not supported.    |
|3120001| Service connection failed. |
|3120002| System internal error.     |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { eSIM } from '@kit.TelephonyKit';

let profile: eSIM.DownloadableProfile = {
  activationCode:'1',
  confirmationCode:'1',
  carrierName:'test',
  accessRules:[{
    certificateHashHexStr:'test',
    packageName:'com.example.testcoreservice',
    accessType:0
  }]
};

eSIM.addProfile(profile).then(() => {
    console.info(`addProfile invoking succeeded.`);
}).catch((err: BusinessError<void>) => {
    console.error(`addProfile, promise: err->${JSON.stringify(err)}`);
});
```

## DownloadableProfile

可下载的配置文件。

**系统能力**：SystemCapability.Telephony.CoreService.Esim

| 名称 | 类型                                   |  只读 | 可选 | 说明 |
| ----- |--------------------------------------| ----- | ---- | -----|
| activationCode   | string                               |  否  |  否  | 激活码。对于不基于激活码的配置文件，可能为空。 |
| confirmationCode | string                               |  否  |  是  | 确认码。不传入时默认为空字符串。     |
| carrierName      | string                               |  否  |  是  | 订阅名称。不传入时默认为空字符串。   |
| accessRules      | Array\<[AccessRule](#accessrule20)\> |  否  |  是  | 访问规则数组。不传入时默认为空数组。 |

## AccessRule<sup>20+</sup>

访问规则。

**系统能力**：SystemCapability.Telephony.CoreService.Esim

| 名称 | 类型 | 只读 | 可选 | 说明 |
| ----- | ----- |----|----| -----|
| certificateHashHexStr | string  | 否  | 否  | 证书哈希的十六进制字符串，仅包含数字0-9和字母a-f（或A-F），长度为40或64个字符。 |
| packageName           | string  | 否  | 否  | 规则适用的程序包名称。 |
| accessType            | number  | 否  | 否  | 规则的类型。 |
