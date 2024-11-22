# @ohos.telephony.esim (eSIM卡管理)

eSIM卡管理模块提供了eSIM卡管理的基础能力，包括获取指定卡槽是否支持eSIM功能, 如果支持则允许最终用户添加单个配置文件。

>**说明：** 
>
>本模块首批接口从API version 14开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>

## 导入模块

```ts
import { eSIM } from '@kit.TelephonyKit';
```

## eSIM.isSupported<sup>14+</sup>

isSupported\(slotId: number\): boolean

获取指定卡槽是否支持eSIM功能。

**系统能力**：SystemCapability.Telephony.CoreService.Esim

**参数：**

| 参数名 | 类型   | 必填 | 说明                                   |
| ------ | ------ | ---- | -------------------------------------- |
| slotId | number | 是   | 卡槽ID。<br/>- 0：卡槽1<br/>- 1：卡槽2 |

**返回值：**

| 类型                  | 说明                               |
| --------------------- | ---------------------------------- |
| boolean | 返回指定卡槽是否支持eSIM功能，如果支持返回true。 |
**错误码：**

| 错误码ID                 | 错误信息                               |
| --------------------- | ---------------------------------- |
| 401 | Parameter error. Possible causes: <br/>1. Mandatory parameters are left unspecified. <br/>    2. Incorrect parameter types. <br/>3. Invalid parameter value.|
|3120001| Service connection failed. |
|3120002| System internal error. |

**示例：**

```ts
import { eSIM } from '@kit.TelephonyKit';

let isSupported: boolean = eSIM.isSupported(0);
console.log(`the esim is Supported:` + isSupported);
````

## eSIM.addProfile<sup>14+</sup>

addProfile\(profile: DownloadableProfile\): Promise\<boolean\>

此界面将允许最终用户添加单个配置文件。

**系统能力**：SystemCapability.Telephony.CoreService.Esim

**参数：**

| 参数名 | 类型   | 必填 | 说明                                   |
| ------ | ------ | ---- | -------------------------------------- |
| profile | DownloadableProfile | 是   | SM-DP+服务器返回的绑定配置文件包数据 |

**返回值：**

| 类型                  | 说明                               |
| --------------------- | ---------------------------------- |
| Promise\<boolean\> | 以Promise形式返回最终用户添加单个配置文件是否成功或者返回错误码。 |

**错误码：**

| 错误码ID                 | 错误信息                               |
| --------------------- | ---------------------------------- |
| 401 | Parameter error. Possible causes: <br/>1. Mandatory parameters are left unspecified. <br/>    2. Incorrect parameter types. <br/>3. Invalid parameter value.|
| 801 | Service connection failed. |
|3120001| Service connection failed. |
|3120002| System internal error. |


**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { eSIM } from '@kit.TelephonyKit';

let profile: eSIM.DownloadableProfile={
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
    console.log(`addProfile invoking succeeded.`);
    }).catch((err: BusinessError) => {
    console.error(`addProfile, promise: err->${JSON.stringify(err)}`);
});
```

## AccessRule<sup>14+</sup>

访问规则。

**系统能力**：SystemCapability.Telephony.CoreService.Esim

| 名称 | 类型 | 必填 | 说明 |
| ----- | ----- | ----- | -----|
| certificateHashHexStr | string  |  是  | 证书哈希的十六进制字符串 |
| packageName | string  |  是  | 规则适用的程序包名称 |
| accessType | number |  是  | 规则的类型 |

## DownloadableProfile<sup>14+</sup>

可下载的配置文件。

**系统能力**：SystemCapability.Telephony.CoreService.Esim

| 名称 | 类型 | 必填 | 说明 |
| ----- | ----- | ----- | -----|
| activationCode | string  |  是  | 激活码，对于不基于激活码的配置文件，可能为空 |
| confirmationCode | string  |  否  | 确认码 |
| carrierName | string |  否  | 订阅名称 |
| accessRules | Array<AccessRule> |  否  | 访问规则数组 |