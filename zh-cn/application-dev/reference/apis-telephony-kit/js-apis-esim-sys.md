# @ohos.telephony.esim (eSIM卡管理) (系统接口)

穿戴设备支持eSIM，电话服务提供API给eSIM卡管理和eSIM卡服务使用。

> **说明：**
>
> 本模块首批接口从API version 18开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
> 当前页面仅包含本模块的系统接口，其他公开接口参见[@ohos.telephony.esim (eSIM卡管理)](js-apis-esim.md)。

## 导入模块

```ts
import { eSIM } from '@kit.TelephonyKit';
```

## eSIM.getEid<sup>18+</sup>

getEid\(slotId: number\): Promise\<string\>

获取指定卡槽标识eUICC硬件的EID。

**系统接口：** 此接口为系统接口。

**需要权限**： ohos.permission.GET_TELEPHONY_ESIM_STATE

**系统能力**：SystemCapability.Telephony.CoreService.Esim

**参数：**

| 参数名 | 类型   | 必填 | 说明                                     |
| ------ | ------ | ---- | -------------------------------------- |
| slotId | number | 是   | 卡槽ID。<br/>- 0：卡槽1。<br/>- 1：卡槽2。   |

**返回值：**

| 类型                  | 说明                                |
| --------------------- | ---------------------------------- |
| Promise\<string\> | 返回指定卡槽标识eUICC硬件的EID。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)。

| 错误码ID                 | 错误信息                         |
| --------------------- | ---------------------------------- |
| 201 | Permission denied. |
| 202 | Non-system applications use system APIs. |
| 401 | Invalid parameter value.|
| 801 | Capability not supported. |
|3120001| Service connection failed. |
|3120002| System internal error. |

**示例：**

```ts
import { eSIM } from '@kit.TelephonyKit';

let eid: string = eSIM.getEid(0);
console.log(`the EID is:` + eid);
```

## eSIM.getOsuStatus<sup>18+</sup>

getOsuStatus\(slotId: number\): Promise\<OsuStatus\>

获取指定卡槽操作系统升级的状态。使用Promise异步回调。

**系统接口：** 此接口为系统接口。

**需要权限**： ohos.permission.GET_TELEPHONY_ESIM_STATE

**系统能力**：SystemCapability.Telephony.CoreService.Esim

**参数：**

| 参数名 | 类型   | 必填 | 说明                                   |
| ------ | ------ | ---- | -------------------------------------- |
| slotId | number | 是   | 卡槽ID。<br/>- 0：卡槽1。<br/>- 1：卡槽2。 |

**返回值：**

| 类型                  | 说明                               |
| --------------------- | ---------------------------------- |
| Promise\<[OsuStatus](#osustatus18)\> |  Promise对象，返回操作系统升级的状态。<br/> 1. 正在升级。 <br/>   2. 升级失败。<br/>  3. 升级成功。<br/>  4. 当前版本是最新版本。<br/> 5. 升级服务不可用。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)。

| 错误码ID                 | 错误信息                               |
| --------------------- | ---------------------------------- |
| 201 | Permission denied. |
| 202 | Non-system applications use system APIs. |
| 401 | Invalid parameter value.|
| 801 | Capability not supported. |
|3120001| Service connection failed. |
|3120002| System internal error. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { eSIM } from '@kit.TelephonyKit';

eSIM.getOsuStatus(0).then(() => {
    console.log(`getOsuStatus invoking succeeded.`);
}).catch((err: BusinessError) => {
    console.error(`getOsuStatus, promise: err->${JSON.stringify(err)}`);
});
```

## eSIM.startOsu<sup>18+</sup>

startOsu\(slotId: number\): Promise\<OsuStatus\>

如果指定卡槽的操作系统不是最新的，则执行操作系统升级。使用Promise异步回调。

**系统接口：** 此接口为系统接口。

**需要权限**： ohos.permission.SET_TELEPHONY_ESIM_STATE

**系统能力**：SystemCapability.Telephony.CoreService.Esim

**参数：**

| 参数名 | 类型   | 必填 | 说明                                   |
| ------ | ------ | ---- | -------------------------------------- |
| slotId | number | 是   | 卡槽ID。<br/>- 0：卡槽1。<br/>- 1：卡槽2。 |

**返回值：**

| 类型                  | 说明                               |
| --------------------- | ---------------------------------- |
| Promise\<[OsuStatus](#osustatus18)\> |  Promise对象，返回操作系统升级的状态。<br/> 1. 正在升级。 <br/>   2. 升级失败。<br/>  3. 升级成功。<br/>  4. 当前版本是最新版本。<br/> 5. 升级服务不可用。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)。

| 错误码ID                 | 错误信息                               |
| --------------------- | ---------------------------------- |
| 201 | Permission denied. |
| 202 | Non-system applications use system APIs. |
| 401 | Invalid parameter value.|
| 801 | Capability not supported. |
|3120001| Service connection failed. |
|3120002| System internal error. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { eSIM } from '@kit.TelephonyKit';

eSIM.startOsu(0).then(() => {
    console.log(`startOsu invoking succeeded.`);
}).catch((err: BusinessError) => {
    console.error(`startOsu, ErrorState: err->${JSON.stringify(err)}`);
});
```

## eSIM.getDownloadableProfileMetadata<sup>18+</sup>

getDownloadableProfileMetadata\(slotId: number, portIndex: number, profile: DownloadableProfile, forceDisableProfile: boolean\): Promise\<GetDownloadableProfileMetadataResult\>

填充可下载配置文件的元数据。使用Promise异步回调。

**系统接口：** 此接口为系统接口。

**需要权限**： ohos.permission.SET_TELEPHONY_ESIM_STATE

**系统能力**：SystemCapability.Telephony.CoreService.Esim

**参数：**

| 参数名 | 类型 | 必填 | 说明                                                                                                   |
| ------ | ------ | ----- |------------------------------------------------------------------------------------------------------|
| slotId              | number                                        | 是 | 卡槽ID。<br/>- 0：卡槽1。<br/>- 1：卡槽2。                                                                      |
| portIndex           | number                                        | 是 | 插槽的端口索引。                                                                                             |
| profile             | [DownloadableProfile](./js-apis-esim.md#downloadableprofile18) | 是 | 可下载的配置文件信息。                                                                                          |
| forceDisableProfile | boolean | 是 | 是否可直接去激活配置文件。true表示切换配置文件时，如果需要去激活当前的配置文件，则可以直接操作。false表示如果需要去激活当前的配置文件，则会返回错误，并得到用户授权后再继续调用该接口，执行切换配置文件操作。 |

**返回值：**

| 类型                  | 说明                               |
| --------------------- | ---------------------------------- |
| Promise\<[GetDownloadableProfileMetadataResult](#getdownloadableprofilemetadataresult18)\> | Promise对象，返回填充可下载配置文件的元数据。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)。

| 错误码ID                 | 错误信息                               |
| --------------------- | ---------------------------------- |
| 201 | Permission denied. |
| 202 | Non-system applications use system APIs. |
| 401 | Invalid parameter value.|
| 801 | Capability not supported. |
|3120001| Service connection failed. |
|3120002| System internal error. |

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

eSIM.getDownloadableProfileMetadata(0, 0, profile, true).then((data: eSIM.GetDownloadableProfileMetadataResult) => {
    console.log(`getDownloadableProfileMetadata, GetDownloadableProfileMetadataResult: data->${JSON.stringify(data)}`);
}).catch((err: BusinessError) => {
    console.error(`getDownloadableProfileMetadata, GetDownloadableProfileMetadataResult: err->${JSON.stringify(err)}`);
});
```

## eSIM.getDownloadableProfiles<sup>18+</sup>

getDownloadableProfiles\(slotId: number, portIndex: number,
forceDisableProfile: boolean\): Promise\<GetDownloadableProfilesResult\>

获取可用的可下载配置文件列表。使用Promise异步回调。

**系统接口：** 此接口为系统接口。

**需要权限**： ohos.permission.GET_TELEPHONY_ESIM_STATE

**系统能力**：SystemCapability.Telephony.CoreService.Esim

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| ------ | ------ | ----- | ----- |
| slotId              | number  | 是 | 卡槽ID。<br/>- 0：卡槽1。<br/>- 1：卡槽2。 |
| portIndex           | number  | 是 | 插槽的端口索引。 |
| forceDisableProfile | boolean | 是 | 是否可直接去激活配置文件。true表示切换配置文件时，如果需要去激活当前的配置文件，则可以直接操作。false表示如果需要去激活当前的配置文件，则会返回错误，并得到用户授权后再继续调用该接口，执行切换配置文件操作。|

**返回值：**

| 类型                  | 说明                               |
| --------------------- | ---------------------------------- |
| Promise\<[GetDownloadableProfilesResult](#getdownloadableprofilesresult18)\> | Promise对象，返回可下载配置文件列表。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)。

| 错误码ID                 | 错误信息                               |
| --------------------- | ---------------------------------- |
| 201 | Permission denied. |
| 202 | Non-system applications use system APIs. |
| 401 | Invalid parameter value.|
| 801 | Capability not supported. |
|3120001| Service connection failed. |
|3120002| System internal error. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { eSIM } from '@kit.TelephonyKit';

eSIM.getDownloadableProfiles(0, 0, true).then((data: eSIM.GetDownloadableProfilesResult) => {
    console.log(`getDownloadableProfiles, GetDownloadableProfilesResult: data->${JSON.stringify(data)}`);
}).catch((err: BusinessError) => {
    console.error(`getDownloadableProfiles, GetDownloadableProfilesResult: err->${JSON.stringify(err)}`);
});
```

## eSIM.downloadProfile<sup>18+</sup>

downloadProfile\(slotId: number, portIndex: number, profile: DownloadableProfile,
configuration: DownloadConfiguration\): Promise\<DownloadProfileResult\>

下载配置文件。使用Promise异步回调。

**系统接口：** 此接口为系统接口。

**需要权限**： ohos.permission.SET_TELEPHONY_ESIM_STATE

**系统能力**：SystemCapability.Telephony.CoreService.Esim

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| ------ | ------ | ----- | ----- |
| slotId        | number                                            | 是 | 卡槽ID。<br/>- 0：卡槽1。<br/>- 1：卡槽2。 |
| portIndex     | number                                            | 是 | 插槽的端口索引。 |
| profile       | [DownloadableProfile](./js-apis-esim.md#downloadableprofile18)     | 是 | 可下载的配置文件信息。 |
| configuration | [DownloadConfiguration](#downloadconfiguration18) | 是 | 下载的配置信息。 |

**返回值：**

| 类型                  | 说明                               |
| --------------------- | ---------------------------------- |
| Promise\<[DownloadProfileResult](#downloadprofileresult18)\> | Promise对象，返回下载配置文件的结果。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)。

| 错误码ID                 | 错误信息                               |
| --------------------- | ---------------------------------- |
| 201 | Permission denied. |
| 202 | Non-system applications use system APIs. |
| 401 | Invalid parameter value.|
| 801 | Capability not supported. |
|3120001| Service connection failed. |
|3120002| System internal error. |

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

let configuration: eSIM.DownloadConfiguration = {
  switchAfterDownload: true,
  forceDisableProfile: true,
  isPprAllowed: true,
};

eSIM.downloadProfile(0, 0, profile, configuration).then((data: eSIM.DownloadProfileResult) => {
    console.log(`downloadProfile, DownloadProfileResult: data->${JSON.stringify(data)}`);
}).catch((err: BusinessError) => {
    console.error(`downloadProfile, DownloadProfileResult: err->${JSON.stringify(err)}`);
});
```

## eSIM.getEuiccProfileInfoList<sup>18+</sup>

getEuiccProfileInfoList\(slotId: number\): Promise\<GetEuiccProfileInfoListResult\>

获取配置文件信息列表。使用Promise异步回调。

**系统接口：** 此接口为系统接口。

**需要权限**： ohos.permission.GET_TELEPHONY_ESIM_STATE

**系统能力**：SystemCapability.Telephony.CoreService.Esim

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| ------ | ------ | ----- | ----- |
| slotId | number | 是 | 卡槽ID。<br/>- 0：卡槽1。<br/>- 1：卡槽2。 |

**返回值：**

| 类型                  | 说明                               |
| --------------------- | ---------------------------------- |
| Promise\<[GetEuiccProfileInfoListResult](#geteuiccprofileinfolistresult18)\> | Promise对象，返回配置文件信息列表。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)。

| 错误码ID                 | 错误信息                               |
| --------------------- | ---------------------------------- |
| 201 | Permission denied. |
| 202 | Non-system applications use system APIs. |
| 401 | Invalid parameter value.|
| 801 | Capability not supported. |
|3120001| Service connection failed. |
|3120002| System internal error. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { eSIM } from '@kit.TelephonyKit';

eSIM.getEuiccProfileInfoList(0).then((data: eSIM.GetEuiccProfileInfoListResult) => {
    console.log(`getEuiccProfileInfoList, GetEuiccProfileInfoListResult: data->${JSON.stringify(data)}`);
}).catch((err: BusinessError) => {
    console.error(`getEuiccProfileInfoList, GetEuiccProfileInfoListResult: err->${JSON.stringify(err)}`);
});
```

## eSIM.getEuiccInfo<sup>18+</sup>

getEuiccInfo\(slotId: number\): Promise\<EuiccInfo\>

获取eUICC信息。使用Promise异步回调。

**系统接口：** 此接口为系统接口。

**需要权限**： ohos.permission.GET_TELEPHONY_ESIM_STATE

**系统能力**：SystemCapability.Telephony.CoreService.Esim

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| ------ | ------ | ----- | ----- |
| slotId | number | 是 | 卡槽ID。<br/>- 0：卡槽1。<br/>- 1：卡槽2。 |

**返回值：**

| 类型                  | 说明                               |
| --------------------- | ---------------------------------- |
| Promise\<[EuiccInfo](#euiccinfo18)\> | Promise对象，返回eUicc信息。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)。

| 错误码ID                 | 错误信息                               |
| --------------------- | ---------------------------------- |
| 201 | Permission denied. |
| 202 | Non-system applications use system APIs. |
| 401 | Invalid parameter value.|
| 801 | Capability not supported. |
|3120001| Service connection failed. |
|3120002| System internal error. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { eSIM } from '@kit.TelephonyKit';

eSIM.getEuiccInfo(0).then((data: eSIM.EuiccInfo) => {
    console.log(`getEuiccInfo, EuiccInfo: data->${JSON.stringify(data)}`);
}).catch((err: BusinessError) => {
    console.error(`getEuiccInfo, EuiccInfo: err->${JSON.stringify(err)}`);
});
```

## eSIM.deleteProfile<sup>18+</sup>

deleteProfile\(slotId: number, iccid: string\): Promise\<ResultCode\>

删除配置文件。使用Promise异步回调。

**系统接口：** 此接口为系统接口。

**需要权限**： ohos.permission.SET_TELEPHONY_ESIM_STATE

**系统能力**：SystemCapability.Telephony.CoreService.Esim

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| ------ | ------ | ----- | ----- |
| slotId | number | 是 | 卡槽ID。<br/>- 0：卡槽1。<br/>- 1：卡槽2。 |
| iccid  | string | 是 | 配置文件的Id。 |

**返回值：**

| 类型                  | 说明                               |
| --------------------- | ---------------------------------- |
| Promise\<[ResultCode](#resultcode18)\> | Promise对象，返回删除配置文件的结果码。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)。

| 错误码ID                 | 错误信息                               |
| --------------------- | ---------------------------------- |
| 201 | Permission denied. |
| 202 | Non-system applications use system APIs. |
| 401 | Invalid parameter value.|
| 801 | Capability not supported. |
|3120001| Service connection failed. |
|3120002| System internal error. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { eSIM } from '@kit.TelephonyKit';

eSIM.deleteProfile(0, testId).then(() => {
    console.log(`deleteProfile invoking succeeded.`);
}).catch((err: BusinessError) => {
    console.error(`deleteProfile, ErrorState: err->${JSON.stringify(err)}`);
});
```

## eSIM.switchToProfile<sup>18+</sup>

switchToProfile\(slotId: number, portIndex: number, iccid: string,
forceDisableProfile: boolean\): Promise\<ResultCode\>

切换到(启用)给定的配置文件。使用Promise异步回调。

**系统接口：** 此接口为系统接口。

**需要权限**： ohos.permission.SET_TELEPHONY_ESIM_STATE

**系统能力**：SystemCapability.Telephony.CoreService.Esim

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| ------ | ------ | ----- | ----- |
| slotId              | number  | 是 | 卡槽ID。<br/>- 0：卡槽1。<br/>- 1：卡槽2。 |
| portIndex           | number  | 是 | 插槽的端口索引。 |
| iccid               | string  | 是 | 配置文件的Id。   |
| forceDisableProfile | boolean | 是 | 是否可直接去激活配置文件。true表示切换配置文件时，如果需要去激活当前的配置文件，则可以直接操作。false表示如果需要去激活当前的配置文件，则会返回错误，并得到用户授权后再继续调用该接口，执行切换配置文件操作。|

**返回值：**

| 类型                  | 说明                               |
| --------------------- | ---------------------------------- |
| Promise\<[ResultCode](#resultcode18)\> | Promise对象，返回切换配置文件的结果码。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)。

| 错误码ID                 | 错误信息                               |
| --------------------- | ---------------------------------- |
| 201 | Permission denied. |
| 202 | Non-system applications use system APIs. |
| 401 | Invalid parameter value.|
| 801 | Capability not supported. |
|3120001| Service connection failed. |
|3120002| System internal error. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { eSIM } from '@kit.TelephonyKit';

eSIM.switchToProfile(0, 0, testId, true).then(() => {
    console.log(`switchToProfile invoking succeeded.`);
}).catch((err: BusinessError) => {
    console.error(`switchToProfile, ErrorState: err->${JSON.stringify(err)}`);
});
```

## eSIM.setProfileNickname<sup>18+</sup>

setProfileNickname\(slotId: number, iccid: string, nickname: string\): Promise\<ResultCode\>

设置给定配置文件的昵称。使用Promise异步回调。

**系统接口：** 此接口为系统接口。

**需要权限**： ohos.permission.SET_TELEPHONY_ESIM_STATE

**系统能力**：SystemCapability.Telephony.CoreService.Esim

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| ------ | ------ | ----- | ----- |
| slotId   | number | 是 | 卡槽ID。<br/>- 0：卡槽1。<br/>- 1：卡槽2。 |
| iccid    | string | 是 | 配置文件的Id。 |
| nickname | string | 是 | 昵称。 |

**返回值：**

| 类型                  | 说明                               |
| --------------------- | ---------------------------------- |
| Promise\<[ResultCode](#resultcode18)\> | Promise对象，返回设置昵称的结果码。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)。

| 错误码ID                 | 错误信息                               |
| --------------------- | ---------------------------------- |
| 201 | Permission denied. |
| 202 | Non-system applications use system APIs. |
| 401 | Invalid parameter value.|
| 801 | Capability not supported. |
|3120001| Service connection failed. |
|3120002| System internal error. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { eSIM } from '@kit.TelephonyKit';

eSIM.setProfileNickname(0, testId, testName).then(() => {
    console.log(`setProfileNickname invoking succeeded.`);
}).catch((err: BusinessError) => {
    console.error(`setProfileNickname, ErrorState: err->${JSON.stringify(err)}`);
});
```

## eSIM.resetMemory<sup>18+</sup>

resetMemory\(slotId: number, options?: ResetOption\): Promise\<ResultCode\>

清除所有特定配置文件并重置eUICC。使用Promise异步回调。

**系统接口：** 此接口为系统接口。

**需要权限**： ohos.permission.SET_TELEPHONY_ESIM_STATE

**系统能力**：SystemCapability.Telephony.CoreService.Esim

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| ------ | ------ | ----- | ----- |
| slotId  | number                        | 是 | 卡槽ID。<br/>- 0：卡槽1。<br/>- 1：卡槽2。 |
| options | [ResetOption](#resetoption18) | 否 | 重置状态。 |

**返回值：**

| 类型                  | 说明                               |
| --------------------- | ---------------------------------- |
| Promise\<[ResultCode](#resultcode18)\> | Promise对象，返回重置的结果码。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)。

| 错误码ID                 | 错误信息                               |
| --------------------- | ---------------------------------- |
| 201 | Permission denied. |
| 202 | Non-system applications use system APIs. |
| 401 | Invalid parameter value.|
| 801 | Capability not supported. |
|3120001| Service connection failed. |
|3120002| System internal error. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { eSIM } from '@kit.TelephonyKit';

eSIM.resetMemory(0).then(() => {
    console.log(`resetMemory invoking succeeded.`);
}).catch((err: BusinessError) => {
    console.error(`resetMemory, ErrorState: err->${JSON.stringify(err)}`);
});
```

## eSIM.reserveProfilesForFactoryRestore<sup>18+</sup>

reserveProfilesForFactoryRestore\(slotId: number\): Promise\<ResultCode\>

恢复出厂设置，并保留profiles。使用Promise异步回调。

**系统接口：** 此接口为系统接口。

**需要权限**： ohos.permission.SET_TELEPHONY_ESIM_STATE

**系统能力**：SystemCapability.Telephony.CoreService.Esim

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| ------ | ------ | ----- | ----- |
| slotId | number | 是 | 卡槽ID。<br/>- 0：卡槽1。<br/>- 1：卡槽2。 |

**返回值：**

| 类型                  | 说明                               |
| --------------------- | ---------------------------------- |
| Promise\<[ResultCode](#resultcode18)\> | Promise对象，返回恢复出厂设置的结果码。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)。

| 错误码ID                 | 错误信息                               |
| --------------------- | ---------------------------------- |
| 201 | Permission denied. |
| 202 | Non-system applications use system APIs. |
| 401 | Invalid parameter value.|
| 801 | Capability not supported. |
|3120001| Service connection failed. |
|3120002| System internal error. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { eSIM } from '@kit.TelephonyKit';

eSIM.reserveProfilesForFactoryRestore(0).then(() => {
    console.log(`reserveProfilesForFactoryRestore invoking succeeded.`);
}).catch((err: BusinessError) => {
    console.error(`reserveProfilesForFactoryRestore, ErrorState: err->${JSON.stringify(err)}`);
});
```

## eSIM.setDefaultSmdpAddress<sup>18+</sup>

setDefaultSmdpAddress\(slotId: number, address: string\): Promise\<ResultCode\>

设置或更新eUICC中存储的默认SM-DP+地址。使用Promise异步回调。

**系统接口：** 此接口为系统接口。

**需要权限**： ohos.permission.SET_TELEPHONY_ESIM_STATE

**系统能力**：SystemCapability.Telephony.CoreService.Esim

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| ------ | ------ | ----- | ----- |
| slotId  | number | 是 | 卡槽ID。<br/>- 0：卡槽1。<br/>- 1：卡槽2。 |
| address | string | 是 | 要设置的默认SM-DP+地址。 |

**返回值：**

| 类型                  | 说明                               |
| --------------------- | ---------------------------------- |
| Promise\<[ResultCode](#resultcode18)\> | Promise对象，返回设置默认SM-DP+地址的结果码。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)。

| 错误码ID                 | 错误信息                               |
| --------------------- | ---------------------------------- |
| 201 | Permission denied. |
| 202 | Non-system applications use system APIs. |
| 401 | Invalid parameter value.|
| 801 | Capability not supported. |
|3120001| Service connection failed. |
|3120002| System internal error. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { eSIM } from '@kit.TelephonyKit';

eSIM.setDefaultSmdpAddress(0, testAddress).then(() => {
    console.log(`setDefaultSmdpAddress invoking succeeded.`);
}).catch((err: BusinessError) => {
    console.error(`setDefaultSmdpAddress, ErrorState: err->${JSON.stringify(err)}`);
});
```

## eSIM.getDefaultSmdpAddress<sup>18+</sup>

getDefaultSmdpAddress\(slotId: number\): Promise\<string\>

获取存储在eUICC中的默认SM-DP+地址。使用Promise异步回调。

**系统接口：** 此接口为系统接口。

**需要权限**： ohos.permission.GET_TELEPHONY_ESIM_STATE

**系统能力**：SystemCapability.Telephony.CoreService.Esim

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| ------ | ------ | ----- | ----- |
| slotId | number | 是 | 卡槽ID。<br/>- 0：卡槽1。<br/>- 1：卡槽2。 |

**返回值：**

| 类型                  | 说明                               |
| --------------------- | ---------------------------------- |
| Promise\<string\> | Promise对象，返回SM-DP+地址。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)。

| 错误码ID                 | 错误信息                               |
| --------------------- | ---------------------------------- |
| 201 | Permission denied. |
| 202 | Non-system applications use system APIs. |
| 401 | Invalid parameter value.|
| 801 | Capability not supported. |
|3120001| Service connection failed. |
|3120002| System internal error. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { eSIM } from '@kit.TelephonyKit';

eSIM.getDefaultSmdpAddress(0).then((data: string) => {
    console.log(`getDefaultSmdpAddress, result: data->${JSON.stringify(data)}`);
}).catch((err: BusinessError) => {
    console.error(`getDefaultSmdpAddress, ErrorState: err->${JSON.stringify(err)}`);
});
```

## eSIM.cancelSession<sup>18+</sup>

cancelSession\(slotId: number, transactionId: string, cancelReason: CancelReason\): Promise\<ResultCode\>

取消会话。使用Promise异步回调。

**系统接口：** 此接口为系统接口。

**需要权限**： ohos.permission.SET_TELEPHONY_ESIM_STATE

**系统能力**：SystemCapability.Telephony.CoreService.Esim

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| ------ | ------ | ----- | ----- |
| slotId        | number                          | 是 | 卡槽ID。<br/>- 0：卡槽1。<br/>- 1：卡槽2。 |
| transactionId | string                          | 是 | 业务ID。|
| cancelReason  | [CancelReason](#cancelreason18) | 是 | 取消会话的原因。|

**返回值：**

| 类型                  | 说明                               |
| --------------------- | ---------------------------------- |
| Promise\<[ResultCode](#resultcode18)\> | Promise对象，返回取消会话的结果码。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码说明文档](../errorcode-universal.md)。

| 错误码ID                 | 错误信息                               |
| --------------------- | ---------------------------------- |
| 201   | Permission denied. |
| 202   | Non-system applications use system APIs. |
| 401   | Invalid parameter value.|
| 801   | Capability not supported. |
|3120001| Service connection failed. |
|3120002| System internal error. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { eSIM } from '@kit.TelephonyKit';

eSIM.cancelSession(0, testId, CancelReason::CANCEL_REASON_END_USER_REJECTION).then((data: string) => {
    console.log(`cancelSession, result: data->${JSON.stringify(data)}`);
}).catch((err: BusinessError) => {
    console.error(`cancelSession execution failed: err->${JSON.stringify(err)}`);
});
```

## AccessRule<sup>18+</sup>

访问规则。

**系统接口：** 此接口为系统接口。

**系统能力**：SystemCapability.Telephony.CoreService.Esim

| 名称 | 类型 | 必填 | 说明 |
| ----- | ----- | ----- | -----|
| certificateHashHexStr | string  |  是  | 证书哈希的十六进制字符串。 |
| packageName           | string  |  是  | 规则适用的程序包名称。 |
| accessType            | number  |  是  | 规则的类型。 |

## GetDownloadableProfileMetadataResult<sup>18+</sup>

获取可下载配置文件的元数据。

**系统接口：** 此接口为系统接口。

**系统能力**：SystemCapability.Telephony.CoreService.Esim

| 名称 | 类型 | 必填 | 说明 |
| ----- | ----- | ----- | -----|
| downloadableProfile | DownloadableProfile  |  是  | 可下载的配置文件信息。   |
| pprType             | number               |  是  | 配置文件策略规则类型。 |
| pprFlag             | boolean              |  是  | 配置文件是否有策略规则。true表示有策略规则，false表示无策略规则。|
| iccid               | string               |  是  | 配置文件的iccId。     |
| serviceProviderName | string               |  是  | 配置文件的服务提供商名称。 |
| profileName         | string               |  是  | 配置文件名称。 |
| profileClass        | ProfileClass         |  是  | 配置文件类。   |
| solvableErrors      | SolvableErrors       |  是  | 可解决的错误。 |
| responseResult      | ResultCode           |  是  | 操作结果码。   |

## GetDownloadableProfilesResult<sup>18+</sup>

获取默认可下载配置文件的列表。

**系统接口：** 此接口为系统接口。

**系统能力**：SystemCapability.Telephony.CoreService.Esim

| 名称 | 类型 | 必填 | 说明 |
| ----- | ----- | ----- | -----|
| responseResult       | ResultCode                   |  是  | 返回操作结果码。     |
| downloadableProfiles | Array\<DownloadableProfile>  |  是  | 可下载配置文件数组。 |

## DownloadProfileResult<sup>18+</sup>

下载配置文件的结果。

**系统接口：** 此接口为系统接口。

**系统能力**：SystemCapability.Telephony.CoreService.Esim

| 名称 | 类型 | 必填 | 说明 |
| ----- | ----- | ----- | -----|
| responseResult | ResultCode     |  是  | 操作结果码。 |
| solvableErrors | SolvableErrors |  是  | 可解决错误。 |
| cardId         | number         |  是  | 获取卡Id。   |

## GetEuiccProfileInfoListResult<sup>18+</sup>

获取配置文件信息列表。

**系统接口：** 此接口为系统接口。

**系统能力**：SystemCapability.Telephony.CoreService.Esim

| 名称 | 类型 | 必填 | 说明 |
| ----- | ----- | ----- | -----|
| responseResult  |ResultCode            |  是  | 返回操作结果码。    |
| profiles        | Array\<EuiccProfile> |  是  | 配置文件数组。      |
| isRemovable     | boolean              |  是  | eUICC是否可移除。true表示可移除，false表示不可移除。|

## OperatorId<sup>18+</sup>

获取eUICC芯片/设备的相关信息。

**系统接口：** 此接口为系统接口。

**系统能力**：SystemCapability.Telephony.CoreService.Esim

| 名称 | 类型 | 必填 | 说明 |
| ----- | ----- | ----- | -----|
| mcc  | string |  是  | 移动国家代码。 |
| mnc  | string |  是  | 网络代码。     |
| gid1 | string |  是  | 组id级别1。   |
| gid2 | string |  是  | 组id级别2。   |

## EuiccProfile<sup>18+</sup>

配置文件信息。

**系统接口：** 此接口为系统接口。

**系统能力**：SystemCapability.Telephony.CoreService.Esim

| 名称 | 类型 | 必填 | 说明 |
| ----- | ----- | ----- | -----|
| iccid               | string             |  是  | 配置文件的iccId。 |
| nickName            | string             |  是  | 昵称。 |
| serviceProviderName | string             |  是  | 配置文件的服务提供商名称。 |
| profileName         | string             |  是  | 配置文件名称。   |
| state               | ProfileState       |  是  | 配置文件的状态。 |
| profileClass        | ProfileClass       |  是  | 配置文件类。     |
| operatorId          | OperatorId         |  是  | 配置文件的操作ID。|
| policyRules         | PolicyRules        |  是  | 配置文件策略。   |
| accessRules         | Array\<AccessRule> |  是  | 配置文件规则。   |

## EuiccInfo<sup>18+</sup>

euicc信息。

**系统接口：** 此接口为系统接口。

**系统能力**：SystemCapability.Telephony.CoreService.Esim

| 名称 | 类型 | 必填 | 说明 |
| ----- | ----- | ----- | -----|
| osVersion | string |  是  | 系统版本。 |

## ResetOption<sup>18+</sup>

重置状态。

**系统接口：** 此接口为系统接口。

**系统能力**：SystemCapability.Telephony.CoreService.Esim

| 名称 | 值 | 说明 |
| ----- | ----- | ----- |
|DELETE_OPERATIONAL_PROFILES       | 1      | 删除所有操作配置文件。 |
|DELETE_FIELD_LOADED_TEST_PROFILES | 1 << 1 | 删除所有字段加载的测试配置文件。 |
|RESET_DEFAULT_SMDP_ADDRESS        | 1 << 2 | 重置默认SM-DP+地址。 |

## OsuStatus<sup>18+</sup>

操作系统升级状态。

**系统接口：** 此接口为系统接口。

**系统能力**：SystemCapability.Telephony.CoreService.Esim

| 名称 | 值 | 说明 |
| ----- | ----- | ----- |
|EUICC_UPGRADE_IN_PROGRESS         | 1 | 升级中。 |
|EUICC_UPGRADE_FAILED              | 2 | 升级失败。 |
|EUICC_UPGRADE_SUCCESSFUL          | 3 | 升级成功。 |
|EUICC_UPGRADE_ALREADY_LATEST      | 4 | 当前为最新版本，无需升级 。|
|EUICC_UPGRADE_SERVICE_UNAVAILABLE | 5 | 升级服务不可用。 |

## ResultCode<sup>18+</sup>

结果码。

**系统接口：** 此接口为系统接口。

**系统能力**：SystemCapability.Telephony.CoreService.Esim

| 名称 | 值 | 说明 |
| ----- | ----- | ----- |
| RESULT_SOLVABLE_ERRORS                                   | -2  | 用户必须解决可解决的错误。        |
| RESULT_MUST_DISABLE_PROFILE                              | -1  | 必须禁用活动配置文件才能执行操作。 |
| RESULT_OK                                                | 0   | 成功。 |
| RESULT_GET_EID_FAILED                                    | 201 | 获取EID失败。 |
| RESULT_ACTIVATION_CODE_CHANGED                           | 203 | 最终用户确认后，激活码将被更改。   |
| RESULT_ACTIVATION_CODE_INVALID                           | 204 | 激活码无效。  |
| RESULT_SMDP_ADDRESS_INVALID                              | 205 | SM-DP+服务器地址非法。 |
| RESULT_EUICC_INFO_INVALID                                | 206 | 无效的eUICC信息。      |
| RESULT_TLS_HANDSHAKE_FAILED                              | 207 | TLS握手失败。          |
| RESULT_CERTIFICATE_IO_ERROR                              | 208 | 证书网络连接错误。      |
| RESULT_CERTIFICATE_RESPONSE_TIMEOUT                      | 209 | 证书地址无效或响应超时。 |
| RESULT_AUTHENTICATION_FAILED                             | 210 | 鉴权失败。     |
| RESULT_RESPONSE_HTTP_FAILED                              | 211 | HTTP响应失败。 |
| RESULT_CONFIRMATION_CODE_INCORRECT                       | 212 | 确认码不正确。 |
| RESULT_EXCEEDED_CONFIRMATION_CODE_TRY_LIMIT              | 213 | 已达到最大确认码尝试次数。      |
| RESULT_NO_PROFILE_ON_SERVER                              | 214 | 服务器上没有可供下载的配置文件。 |
| RESULT_TRANSACTION_ID_INVALID                            | 215 | 事务ID无效。    |
| RESULT_SERVER_ADDRESS_INVALID                            | 216 | 服务器地址无效。 |
| RESULT_GET_BOUND_PROFILE_PACKAGE_FAILED                  | 217 | 获取BPP失败。    |
| RESULT_USER_CANCEL_DOWNLOAD                              | 218 | 最终用户取消下载。   |
| RESULT_SERVER_UNAVAILABLE                                | 220 | 运营商服务器不可用。 |
| RESULT_PROFILE_NON_DELETE                                | 223 | PPR禁止删除文件。    |
| RESULT_SMDP_ADDRESS_INCORRECT                            | 226 | 认证响应服务器地址不匹配。   |
| RESULT_ANALYZE_AUTHENTICATION_SERVER_RESPONSE_FAILED     | 228 | 解析服务器身份验证响应错误。 |
| RESULT_ANALYZE_AUTHENTICATION_CLIENT_RESPONSE_FAILED     | 229 | 解析客户端身份验证响应错误。 |
| RESULT_ANALYZE_AUTHENTICATION_CLIENT_MATCHING_ID_REFUSED | 231 | 由于匹配ID被拒绝，解析客户端身份验证响应错误。 |
| RESULT_PROFILE_TYPE_ERROR_AUTHENTICATION_STOPPED         | 233 | 由于配置文件类型中的错误，身份验证已停止。     |
| RESULT_CARRIER_SERVER_REFUSED_ERRORS                     | 249 | 运营商服务器拒绝原因码为3.8的错误。 |
| RESULT_CERTIFICATE_INVALID                               | 251 | 证书无效。 |
| RESULT_OUT_OF_MEMORY                                     | 263 | 由于内存不足，配置文件安装失败。 |
| RESULT_PPR_FORBIDDEN                                     | 268 | PPR规则禁止此操作。 |
| RESULT_NOTHING_TO_DELETE                                 | 270 | 没有可删除的配置文件。 |
| RESULT_PPR_NOT_MATCH                                     | 276 | 与PPR约束不匹配。   |
| RESULT_CAT_BUSY                                          | 283 | 会话正在进行。   |
| RESULT_PROFILE_EID_INVALID                               | 284 | 此eSIM配置文件已被使用或无效。 |
| RESULT_DOWNLOAD_TIMEOUT                                  | 287 | 下载超时。                   |
| RESULT_SGP_22_OTHER                                      | 400 | SGP.22中定义的其他错误。      |

## CancelReason<sup>18+</sup>

取消会话的原因。

**系统接口：** 此接口为系统接口。

**系统能力**：SystemCapability.Telephony.CoreService.Esim

| 名称 | 值 | 说明 |
| ----- | ----- | ----- |
|CANCEL_REASON_END_USER_REJECTION | 0 | 最终用户已拒绝下载。          |
|CANCEL_REASON_POSTPONED          | 1 | 下载已推迟，稍后可以重新启动。 |
|CANCEL_REASON_TIMEOUT            | 2 | 下载已超时，稍后可以重新启动。 |
|CANCEL_REASON_PPR_NOT_ALLOWED    | 3 | 由于eUICC上的授权表或其他已安装的配置文件不允许其策略规则，因此无法安装。 |

## ProfileState<sup>18+</sup>

配置文件状态。

**系统接口：** 此接口为系统接口。

**系统能力**：SystemCapability.Telephony.CoreService.Esim

| 名称 | 值 | 说明 |
| ----- | ----- | ----- |
|PROFILE_STATE_UNSPECIFIED | -1 | 未设置配置文件状态。 |
|PROFILE_STATE_DISABLED    | 0  | 禁用配置文件。   |
|PROFILE_STATE_ENABLED     | 1  | 已启用配置文件。 |

## ProfileClass<sup>18+</sup>

配置文件类。

**系统接口：** 此接口为系统接口。

**系统能力**：SystemCapability.Telephony.CoreService.Esim

| 名称 | 值 | 说明 |
| ----- | ----- | ----- |
|PROFILE_CLASS_UNSPECIFIED  | -1 | 未设置配置文件类。           |
|PROFILE_CLASS_TEST         | 0  | 测试配置文件。               |
|PROFILE_CLASS_PROVISIONING | 1  | 预加载在eUICC上的配置文件。   |
|PROFILE_CLASS_OPERATIONAL  | 2  | 可预加载或下载的操作配置文件。 |

## PolicyRules<sup>18+</sup>

配置文件的策略规则。

**系统接口：** 此接口为系统接口。

**系统能力**：SystemCapability.Telephony.CoreService.Esim

| 名称 | 值 | 说明 |
| ----- | ----- | ----- |
|POLICY_RULE_DISABLE_NOT_ALLOWED | 1      | 启用此配置文件后，将无法禁用。 |
|POLICY_RULE_DELETE_NOT_ALLOWED  | 1 << 1 | 无法删除此配置文件。          |
|POLICY_RULE_DISABLE_AND_DELETE  | 1 << 2 | 禁用后应删除此配置文件。      |

## SolvableErrors<sup>18+</sup>

可解决错误码。

**系统接口：** 此接口为系统接口。

**系统能力**：SystemCapability.Telephony.CoreService.Esim

| 名称 | 值 | 说明 |
| ----- | ----- | ----- |
|SOLVABLE_ERROR_NEED_CONFIRMATION_CODE | 1 << 0 | 下载过程需要用户输入确认码。                |
|SOLVABLE_ERROR_NEED_POLICY_RULE       | 1 << 1 | 下载过程需要用户同意才能允许配置文件策略规则。|

## DownloadConfiguration<sup>18+</sup>

下载过程中的属性配置。

**系统接口：** 此接口为系统接口。

**系统能力**：SystemCapability.Telephony.CoreService.Esim

| 名称 | 类型 | 必填 | 说明 |
| ----- | ----- | ----- | -----|
|switchAfterDownload | boolean | 是 | 下载成功后是否启用配置文件。true表示启用，false表示不启用。|
|forceDisableProfile | boolean | 是 | 是否可直接去激活配置文件。true表示切换配置文件时，如果需要去激活当前的配置文件，则可以直接操作。false表示如果需要去激活当前的配置文件，则会返回错误，并得到用户授权后再继续调用该接口，执行切换配置文件操作。|
|isPprAllowed        | boolean | 是 | 是否得到用户授权。true表示得到用户授权，服务提供商可实施配置文件策略规则；false表示未得到用户授权，不允许实施配置文件策略规则。|

