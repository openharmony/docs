# @ohos.enterprise.systemManager （系统管理）

本模块提供系统管理能力。

> **说明**：
> 
> 本模块首批接口从API version 12开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>
> 本模块接口仅可在Stage模型下使用。
>
> 本模块接口仅对[设备管理应用](../../mdm/mdm-kit-guide.md#功能介绍)开放，需将设备管理应用激活后调用，实现相应功能。

## 导入模块

```ts
import { systemManager } from '@kit.MDMKit';
```

## systemManager.setNTPServer

setNTPServer(admin: Want, server: string): void

设置NTP时间服务器。

**需要权限：** ohos.permission.ENTERPRISE_MANAGE_SYSTEM

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**参数：**

| 参数名   | 类型                                  | 必填   | 说明      |
| ----- | ----------------------------------- | ---- | ------- |
| admin | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | 是    | 企业设备管理扩展组件。 |
| server | string | 是 | NTP服务器地址（以","分隔，如"ntpserver1.com,ntpserver2.com"。最大长度96字节，包括结束符）。 |

**错误码**：

以下错误码的详细介绍请参见[企业设备管理错误码](errorcode-enterpriseDeviceManager.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                                      |
| ------- | ---------------------------------------------------------------------------- |
| 9200001 | The application is not an administrator application of the device. |
| 9200002 | The administrator application does not have permission to manage the device. |
| 201 | Permission verification failed. The application does not have the permission required to call the API. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**示例：**

```ts
import { systemManager } from '@kit.MDMKit';
import { Want } from '@kit.AbilityKit';
let wantTemp: Want = {
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility',
};
let server: string = "ntpserver.com";
try {
  systemManager.setNTPServer(wantTemp, server);
  console.info('Succeeded in setting NTPserver.');
} catch (err) {
  console.error(`Failed to set ntp server. Code is ${err.code}, message is ${err.message}`);
}
```

## systemManager.getNTPServer

getNTPServer(admin: Want): string

获取NTP时间服务器信息。

**需要权限：** ohos.permission.ENTERPRISE_MANAGE_SYSTEM

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**参数：**

| 参数名 | 类型                                                    | 必填 | 说明                   |
| ------ | ------------------------------------------------------- | ---- | ---------------------- |
| admin  | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | 是   | 企业设备管理扩展组件。 |

**返回值：**

| 类型   | 说明                                |
| ------ | ----------------------------------- |
| string | string对象，返回NTP时间服务器信息。 |

**错误码**：

以下错误码的详细介绍请参见[企业设备管理错误码](errorcode-enterpriseDeviceManager.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 9200001  | The application is not an administrator application of the device. |
| 9200002  | The administrator application does not have permission to manage the device. |
| 201      | Permission verification failed. The application does not have the permission required to call the API. |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**示例：**

```ts
import { systemManager } from '@kit.MDMKit';
import { Want } from '@kit.AbilityKit';
import { BusinessError } from '@ohos.base';
let wantTemp: Want = {
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility',
};
try {
  systemManager.getNTPServer(wantTemp);
  console.info('Succeeded in getting NTP server.');
} catch (err) {
  console.error(`Failed to get ntp server. Code is ${err.code}, message is ${err.message}`);
}
```

## systemManager.setOtaUpdatePolicy

setOtaUpdatePolicy(admin: Want, policy: OtaUpdatePolicy): void

设置升级策略。内网升级场景下，需要先调用[systemManager.notifyUpdatePackages](#systemmanagernotifyupdatepackages)接口通知系统更新包，再调用该接口设置升级策略。

**需要权限：** ohos.permission.ENTERPRISE_MANAGE_SYSTEM

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**参数：**

| 参数名   | 类型                                  | 必填   | 说明      |
| ----- | ----------------------------------- | ---- | ------- |
| admin | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | 是    | 企业设备管理扩展组件。 |
| policy | [OtaUpdatePolicy](#otaupdatepolicy) | 是 | 升级策略。 |

**错误码**：

以下错误码的详细介绍请参见[企业设备管理错误码](errorcode-enterpriseDeviceManager.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                                      |
| ------- | ---------------------------------------------------------------------------- |
| 9200001 | The application is not an administrator application of the device.                       |
| 9200002 | The administrator application does not have permission to manage the device. |
| 201 | Permission verification failed. The application does not have the permission required to call the API. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed.|

**示例：**

```ts
import { systemManager } from '@kit.MDMKit';
import { Want } from '@kit.AbilityKit';
let wantTemp: Want = {
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility',
};
// 默认升级策略
let otaUpdatePolicy1: systemManager.OtaUpdatePolicy = {
  "policyType": systemManager.PolicyType.DEFAULT,
  "version": "version_1.0.0.0",
};
try {
  systemManager.setOtaUpdatePolicy(wantTemp, otaUpdatePolicy1);
  console.info('Succeeded in setting ota update policy.');
} catch (err) {
  console.error(`Failed to set ota update policy. Code is ${err.code}, message is ${err.message}`);
}
// 禁止升级
let otaUpdatePolicy2: systemManager.OtaUpdatePolicy = {
  "policyType": systemManager.PolicyType.PROHIBIT,
  "version": "version_1.0.0.1",
};
try {
  systemManager.setOtaUpdatePolicy(wantTemp, otaUpdatePolicy2);
  console.info('Succeeded in setting ota update policy.');
} catch (err) {
  console.error(`Failed to set ota update policy. Code is ${err.code}, message is ${err.message}`);
}
// 强制升级
let otaUpdatePolicy3: systemManager.OtaUpdatePolicy = {
  "policyType": systemManager.PolicyType.UPDATE_TO_SPECIFIC_VERSION,
  "version": "version_1.0.0.2",
  "latestUpdateTime": 1716343200, // 时间戳
};
try {
  systemManager.setOtaUpdatePolicy(wantTemp, otaUpdatePolicy3);
  console.info('Succeeded in setting ota update policy.');
} catch (err) {
  console.error(`Failed to set ota update policy. Code is ${err.code}, message is ${err.message}`);
}
// 指定时间窗口升级
let otaUpdatePolicy4: systemManager.OtaUpdatePolicy = {
  "policyType": systemManager.PolicyType.WINDOWS,
  "version": "version_1.0.0.3",
  "installStartTime": 1716281049, // // 时间戳
  "installEndTime": 1716343200, // // 时间戳
};
try {
  systemManager.setOtaUpdatePolicy(wantTemp, otaUpdatePolicy4);
  console.info('Succeeded in setting ota update policy.');
} catch (err) {
  console.error(`Failed to set ota update policy. Code is ${err.code}, message is ${err.message}`);
}
// 延迟升级
let otaUpdatePolicy5: systemManager.OtaUpdatePolicy = {
  "policyType": systemManager.PolicyType.POSTPONE,
  "version": "version_1.0.0.4",
  "delayUpdateTime": 5, // 单位（小时）
};
try {
  systemManager.setOtaUpdatePolicy(wantTemp, otaUpdatePolicy5);
  console.info('Succeeded in setting ota update policy.');
} catch (err) {
  console.error(`Failed to set ota update policy. Code is ${err.code}, message is ${err.message}`);
}

```

## systemManager.getOtaUpdatePolicy

getOtaUpdatePolicy(admin: Want): OtaUpdatePolicy

查询升级策略。

**需要权限：** ohos.permission.ENTERPRISE_MANAGE_SYSTEM

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**参数：**

| 参数名 | 类型                                                    | 必填 | 说明               |
| ------ | ------------------------------------------------------- | ---- | ------------------ |
| admin  | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | 是   | 企业设备管理扩展组件。 |

**返回值：**

| 类型   | 说明                            |
| ------ | ------------------------------- |
| [OtaUpdatePolicy](#otaupdatepolicy) | OtaUpdatePolicy对象，返回升级策略。 |

**错误码**：

以下错误码的详细介绍请参见[企业设备管理错误码](errorcode-enterpriseDeviceManager.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 9200001  | The application is not an administrator application of the device.       |
| 9200002  | The administrator application does not have permission to manage the device. |
| 201 | Permission verification failed. The application does not have the permission required to call the API. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed.|

**示例：**

```ts
import { systemManager } from '@kit.MDMKit';
import { Want } from '@kit.AbilityKit';
let wantTemp: Want = {
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility',
};
try {
  let policy: systemManager.OtaUpdatePolicy= systemManager.getOtaUpdatePolicy(wantTemp);
  console.info(`Succeeded in getting update policy: ${JSON.stringify(policy)}`);
} catch (err) {
  console.error(`Failed to get update policy. Code is ${err.code}, message is ${err.message}`);
}
```

## systemManager.notifyUpdatePackages

notifyUpdatePackages(admin: Want, packageInfo: UpdatePackageInfo): Promise&lt;void&gt;

通知系统更新包信息。内网升级场景下，需要先调用该接口通知系统更新包，再调用[systemManager.setOtaUpdatePolicy](#systemmanagersetotaupdatepolicy)设置升级策略。

**需要权限：** ohos.permission.ENTERPRISE_MANAGE_SYSTEM

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**参数：**

| 参数名 | 类型                                | 必填 | 说明           |
| ------ | ----------------------------------- | ---- | -------------- |
| admin  | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | 是   | 企业设备管理扩展组件。 |
| packageInfo  | [UpdatePackageInfo](#updatepackageinfo) | 是   | 系统更新包信息。 |

**返回值：**

| 类型                   | 说明                      |
| --------------------- | ------------------------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。当通知系统更新包失败时会抛出错误对象。 |

**错误码**：

以下错误码的详细介绍请参见[企业设备管理错误码](errorcode-enterpriseDeviceManager.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 9200001  | The application is not an administrator application of the device.       |
| 9200002  | The administrator application does not have permission to manage the device. |
| 9201004  | The update packages do not exist or analyzing failed. |
| 201 | Permission verification failed. The application does not have the permission required to call the API. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed.|

**示例：**

```ts
import { systemManager } from '@kit.MDMKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { Want } from '@kit.AbilityKit';
let wantTemp: Want = {
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility',
};
let notify: systemManager.NotifyDescription = {
  "installTips": "installTips",
  "installTipsDetail": "installTips detail"
}
let description: systemManager.PackageDescription = {
  "notify": notify,
}
let updatePackages: Array<systemManager.Package> = [{
  "type": systemManager.PackageType.FIRMWARE,
  "path": "path",
  "fd": 60,
}]
let updatePackageInfo: systemManager.UpdatePackageInfo = {
  "version" : "1.0",
  "packages" : updatePackages,
  "description" : description,
};
systemManager.notifyUpdatePackages(wantTemp, updatePackageInfo).then(() => {
  console.info('Succeeded in notifying update packages.');
}).catch ((error: BusinessError) => {
  console.error(`Failed to notify update packages. Code is ${error.code},message is ${error.message}`);
});
```

## systemManager.getUpdateResult

getUpdateResult(admin: Want, version: string): Promise&lt;UpdateResult&gt;

获取系统更新结果。

**需要权限：** ohos.permission.ENTERPRISE_MANAGE_SYSTEM

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**参数：**

| 参数名 | 类型                                | 必填 | 说明           |
| ------ | ----------------------------------- | ---- | -------------- |
| admin  | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | 是   | 企业设备管理扩展组件。 |
| version  | string | 是   | 更新包版本号。 |

**返回值：**

| 类型                   | 说明                      |
| --------------------- | ------------------------- |
| Promise&lt;[UpdateResult](#updateresult)&gt; | Promise对象，返回系统更新结果。 |

**错误码**：

以下错误码的详细介绍请参见[企业设备管理错误码](errorcode-enterpriseDeviceManager.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 9200001  | The application is not an administrator application of the device.       |
| 9200002  | The administrator application does not have permission to manage the device. |
| 201 | Permission verification failed. The application does not have the permission required to call the API. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed.|

**示例：**

```ts
import { systemManager } from '@kit.MDMKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { Want } from '@kit.AbilityKit';
let wantTemp: Want = {
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility',
};
systemManager.getUpdateResult(wantTemp, "1.0").then((result:systemManager.UpdateResult) => {
    console.info(`Succeeded in getting update result: ${JSON.stringify(result)}`);
  }).catch((error: BusinessError) => {
    console.error(`Get update result failed. Code is ${error.code},message is ${error.message}`);
  });
```
## systemManager.getUpdateAuthData<sup>19+</sup>

getUpdateAuthData(admin: Want): Promise&lt;string&gt;

获取系统更新的鉴权数据，用于校验系统更新信息。使用Promise异步回调。

**需要权限：** ohos.permission.ENTERPRISE_MANAGE_SYSTEM

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**参数：**

| 参数名 | 类型                                | 必填 | 说明           |
| ------ | ----------------------------------- | ---- | -------------- |
| admin  | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | 是   | 企业设备管理扩展组件。 |

**返回值：**

| 类型                   | 说明                      |
| --------------------- | ------------------------- |
| Promise&lt;string&gt; | Promise对象，返回系统更新的鉴权数据。 |

**错误码**：

以下错误码的详细介绍请参见[企业设备管理错误码](errorcode-enterpriseDeviceManager.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 9200001  | The application is not an administrator application of the device.       |
| 9200002  | The administrator application does not have permission to manage the device. |
| 201 | Permission verification failed. The application does not have the permission required to call the API. |

**示例：**

```ts
import { systemManager } from '@kit.MDMKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { Want } from '@kit.AbilityKit';

let wantTemp: Want = {
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility',
};
systemManager.getUpdateAuthData(wantTemp).then((result: string) => {
    console.info(`Succeeded in getting update auth data: ${JSON.stringify(result)}`);
  }).catch((error: BusinessError) => {
    console.error(`Get update auth data failed. Code is ${error.code},message is ${error.message}`);
  });
```
## SystemUpdateInfo

待更新的系统版本信息。

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

| 名称                | 类型     | 必填  | 说明            |
| ----------------- | ------ | --- | ------------- |
| versionName       | string | 是   | 待更新的系统版本名称。   |
| firstReceivedTime | number | 是   | 首次收到系统更新包的时间。 |
| packageType       | string | 是   | 待更新的系统更新包类型。  |

## OtaUpdatePolicy

升级策略。

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

| 名称         | 类型     | 必填 | 说明                            |
| ----------- | --------| ---- | ------------------------------- |
| policyType        | [PolicyType](#policytype)   | 是   | 表示升级策略类型。 |
| version | string   | 是   | 表示待升级软件版本号。 |
| latestUpdateTime        | number   | 否   | 表示最晚升级时间（时间戳）。 |
| delayUpdateTime | number   | 否   | 表示延迟升级时间（单位：小时）。 |
| installStartTime        | number   | 否   | 表示指定安装窗口起始时间（时间戳）。 |
| installEndTime | number   | 否   | 表示指定安装窗口结束时间（时间戳）。 |

## PolicyType

升级策略类型枚举。

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

| 名称                | 值  | 说明    |
| ----------------- | ---- | ----- |
| DEFAULT | 0 | 默认升级策略。周期提示用户，用户确认后升级。 |
| PROHIBIT  | 1 | 禁止升级策略。 |
| UPDATE_TO_SPECIFIC_VERSION | 2 | 强制升级策略。需指定最晚升级时间（latestUpdateTime）参数。 |
| WINDOWS | 3 | 指定时间窗口升级策略。需指定时间窗口参数（installStartTime、installEndTime）。 |
| POSTPONE | 4 | 延迟升级策略。延迟指定时间（delayUpdateTime）后进入DEFAULT模式，周期提示用户升级。 |

## UpdatePackageInfo

系统更新包信息。

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

| 名称                | 类型     | 必填  | 说明            |
| ----------------- | ------ | --- | ------------- |
| version       | string | 是   | 系统更新包版本号。   |
| packages | Array&lt;[Package](#package)&gt; | 是   | 系统更新包详情。 |
| description       | [PackageDescription](#packagedescription) | 否   | 系统更新包描述信息。  |
| authInfo<sup>19+</sup> | string | 否 | 系统更新包的鉴权信息。 |

## Package

系统更新包详情。

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

| 名称                | 类型     | 必填  | 说明            |
| ----------------- | ------ | --- | ------------- |
| type       | [PackageType](#packagetype) | 是   | 系统更新包类型。   |
| path | string | 是   | 系统更新包文件路径。若传入fd参数，该参数传入更新包文件名。 |
| fd       | number | 否   | 系统更新包文件句柄。当前不支持只传入path参数，需要传入fd。  |

## PackageDescription

系统更新包描述信息。

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

| 名称                | 类型     | 必填  | 说明            |
| ----------------- | ------ | --- | ------------- |
| notify       | [NotifyDescription](#notifydescription) | 否   | 企业自定义更新通知说明。   |

## NotifyDescription

企业自定义更新通知说明。

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

| 名称                | 类型     | 必填  | 说明            |
| ----------------- | ------ | --- | ------------- |
| installTips       | string | 否   | 企业自定义更新提示。   |
| installTipsDetail       | string | 否   | 企业自定义更新提示详情。   |

## UpdateResult

系统更新结果信息。

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

| 名称                | 类型   | 可读  | 可写   | 说明            |
| ----------------- | ------ | ------ | ------ | ------------- |
| version       | string |  是 | 否 |系统当前版本号。   |
| status       | [UpdateStatus](#updatestatus) | 是 | 否 | 系统更新状态。   |
| errorInfo       | [ErrorInfo](#errorinfo) | 是 | 否 | 系统更新错误信息。   |

## ErrorInfo

系统更新错误信息。

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

| 名称                | 类型     | 可读  | 可写 | 说明            |
| ----------------- | ------ | ------ | ------ | ------------- |
| code       | number | 是 | 否 | 错误码。   |
| message       | string | 是 | 否 | 错误描述信息。   |

## PackageType

系统更新包类型。

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

| 名称                | 值  | 说明    |
| ----------------- | ---- | ----- |
| FIRMWARE | 1 | 固件。 |

## UpdateStatus

系统更新状态。

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

| 名称               | 值  | 说明    |
| -----------------  | ---- | ----- |
| NO_UPDATE_PACKAGE  | -4 | 指定版本系统更新包不存在。 |
| UPDATE_WAITING     | -3 | 系统更新包等待安装中。 |
| UPDATING           | -2 | 正在更新。 |
| UPDATE_FAILURE     | -1 | 更新失败。 |
| UPDATE_SUCCESS     | 0 | 更新成功。 |
