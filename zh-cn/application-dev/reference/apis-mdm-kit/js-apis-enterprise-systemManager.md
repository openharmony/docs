# @ohos.enterprise.systemManager （系统管理）

本模块提供系统管理能力。

> **说明**：
> 
> 本模块首批接口从API version 12开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>
> 本模块接口仅可在Stage模型下使用。
>
> 本模块接口仅对[设备管理应用](enterpriseDeviceManagement-overview.md#基本概念)开放，需将设备管理应用激活后调用，实现相应功能。
> 

## 导入模块

```ts
import { systemManager } from '@kit.MDMKit';
```

## systemManager.setNTPServer

setNTPServer(admin: Want, server: string): void

指定设备管理应用设置NTP服务器的策略。

**需要权限：** ohos.permission.ENTERPRISE_MANAGE_SYSTEM

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**参数：**

| 参数名   | 类型                                  | 必填   | 说明      |
| ----- | ----------------------------------- | ---- | ------- |
| admin | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | 是    | 设备管理应用。 |
| server | string | 是 | NTP服务器地址（以","分隔，如"ntpserver1.com,ntpserver2.com"）。 |

**错误码**：

以下错误码的详细介绍请参见[企业设备管理错误码](errorcode-enterpriseDeviceManager.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                                      |
| ------- | ---------------------------------------------------------------------------- |
| 9200001 | The application is not an administrator application of the device. |
| 9200002 | the administrator application does not have permission to manage the device. |
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
  console.error(`Failed to set usb policy. Code is ${err.code}, message is ${err.message}`);
}
```

## systemManager.getNTPServer

getNTPServer(admin: Want): string

指定设备管理应用获取NTP服务器信息。

**需要权限：** ohos.permission.ENTERPRISE_MANAGE_SYSTEM

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**参数：**

| 参数名 | 类型                                | 必填 | 说明           |
| ------ | ----------------------------------- | ---- | -------------- |
| admin  | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | 是   | 设备管理应用。 |

**返回值：**

| 类型   | 说明                            |
| ------ | ------------------------------- |
| string | string对象，返回NTP服务器信息。 |

**错误码**：

以下错误码的详细介绍请参见[企业设备管理错误码](errorcode-enterpriseDeviceManager.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 9200001  | The application is not an administrator application of the device. |
| 9200002  | the administrator application does not have permission to manage the device. |
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
  console.error(`Failed to set usb policy. Code is ${err.code}, message is ${err.message}`);
}
```

## SystemUpdateInfo

待更新的系统版本信息。

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

| 名称                | 类型     | 必填  | 说明            |
| ----------------- | ------ | --- | ------------- |
| versionName       | string | 是   | 待更新的系统版本名称。   |
| firstReceivedTime | number | 是   | 首次收到系统更新包的时间。 |
| packageType       | string | 是   | 待更新的系统更新包类型。  |
