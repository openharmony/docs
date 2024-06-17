# @ohos.enterprise.locationManager（位置服务管理）

本模块提供设备位置服务策略管理的能力，包括设置和查询位置服务开关策略等。

> **说明：**
>
> 本模块首批接口从API version 12开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>
> 本模块接口仅可在Stage模型下使用。
>
> 本模块接口仅对[设备管理应用](../../mdm/mdm-kit-guide.md#功能介绍)开放，需将设备管理应用激活后调用，实现相应功能。
> 

## 导入模块

```ts
import { locationManager } from '@kit.MDMKit';
```

## locationManager.setLocationPolicy

setLocationPolicy(admin: Want, policy: LocationPolicy): void

以同步方法设置位置服务管理策略。失败抛出对应异常。

**需要权限：** ohos.permission.ENTERPRISE_MANAGE_LOCATION

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager


**参数：**

| 参数名   | 类型                                  | 必填   | 说明      |
| ----- | ----------------------------------- | ---- | ------- |
| admin | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | 是    | 设备管理应用。 |
| policy | [LocationPolicy](#locationpolicy) | 是    | 位置服务策略。<br>- 0：默认策略。<br>- 1：禁用。<br>- 2：强制启用。 |

**错误码**：

以下错误码的详细介绍请参见[企业设备管理错误码](errorcode-enterpriseDeviceManager.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                                     |
| ------- | ---------------------------------------------------------------------------- |
| 9200001 | The application is not an administrator application of the device. |
| 9200002 | The administrator application does not have permission to manage the device. |
| 201 | Permission verification failed. The application does not have the permission required to call the API. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**示例：**

```ts
import { Want } from '@kit.AbilityKit';
import { locationManager } from '@kit.MDMKit';

let wantTemp: Want = {
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility',
};

try {
    locationManager.setLocationPolicy(wantTemp, locationManager.LocationPolicy.DISALLOW_LOCATION_SERVICE);
    console.info(`Succeeded in setting location patch tag.`);
} catch(err) {
    console.error(`Failed to get location patch tag. Code: ${err.code}, message: ${err.message}`);
}
```
## locationManager.getLocationPolicy

getLocationPolicy(admin: Want): LocationPolicy

以同步方法查询位置服务策略。成功返回位置服务策略，失败抛出对应异常。

**需要权限：** ohos.permission.ENTERPRISE_MANAGE_LOCATION

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager


**参数：**

| 参数名      | 类型                                       | 必填   | 说明                       |
| -------- | ---------------------------------------- | ---- | ------------------------------- |
| admin    | [Want](../apis-ability-kit/js-apis-app-ability-want.md)     | 是    | 设备管理应用。                  |

**返回值：**

| 类型                              | 说明                                                 |
| --------------------------------- | ---------------------------------------------------- |
| [LocationPolicy](#locationpolicy) | 位置服务策略枚举值 0：默认策略 1：禁用 2：强制启用。 |

**错误码**：

以下错误码的详细介绍请参见[企业设备管理错误码](errorcode-enterpriseDeviceManager.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                                       |
| ------- | ---------------------------------------------------------------------------- |
| 9200001 | The application is not an administrator application of the device. |
| 9200002 | The administrator application does not have permission to manage the device. |
| 201 | Permission verification failed. The application does not have the permission required to call the API. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**示例：**

```ts
import { Want } from '@kit.AbilityKit';
import { locationManager } from '@kit.MDMKit';
let wantTemp: Want = {
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility',
};

try {
    let result: locationManager.LocationPolicy = locationManager.getLocationPolicy(wantTemp);
    console.info(`Succeeded in getting location policy. policy: ${result}`);
} catch(err) {
    console.error(`Failed to get device encryption status. Code: ${err.code}, message: ${err.message}`);
}
```

## LocationPolicy

位置服务策略值。

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager


**模型约束：** 此接口仅可在Stage模型下使用

| 名称                        | 值  | 说明    |
| ----------------------------| ----| ------------------------------- |
| DEFAULT_LOCATION_SERVICE    | 0   | 默认策略。 |
| DISALLOW_LOCATION_SERVICE | 1   | 禁用位置服务策略。 |
| FORCE_OPEN_LOCATION_SERVICE | 2   | 强制开启位置服务策略。 |

