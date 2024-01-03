# @ohos.enterprise.locationManager（位置服务管理）

本模块提供设备位置服务策略管理的能力，包括设置和查询位置服务开关策略等。

> **说明：**
>
> 本模块首批接口从API version 11开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>
> 本模块接口仅可在Stage模型下使用。
>
> 本模块接口仅对[设备管理应用](enterpriseDeviceManagement-overview.md#基本概念)开放，需将[设备管理应用激活](js-apis-enterprise-adminManager.md#adminmanagerenableadmin)后调用，实现相应功能。

## 导入模块

```ts
import locationManager from '@ohos.enterprise.locationManager';
```

## locationManager.setLocationPolicy

setLocationPolicy(admin: Want, policy: LocationPolicy): void

以同步方法设置位置服务管理策略。失败抛出对应异常。

**需要权限：** ohos.permission.ENTERPRISE_MANAGE_LOCATION

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**系统API：** 此接口为系统接口

**参数：**

| 参数名   | 类型                                  | 必填   | 说明      |
| ----- | ----------------------------------- | ---- | ------- |
| admin | [Want](js-apis-app-ability-want.md) | 是    | 设备管理应用。 |
| policy | [LocationPolicy](js-apis-enterprise-locationManager.md) | 是    | 位置服务策略。<br>- 0：默认策略<br>- 1：禁用<br>- 2：强制启用。 |

**错误码**：

以下错误码的详细介绍请参见[企业设备管理错误码](../errorcodes/errorcode-enterpriseDeviceManager.md)

| 错误码ID | 错误信息                                                                     |          
| ------- | ---------------------------------------------------------------------------- |
| 9200001 | the application is not an administrator of the device.                        |
| 9200002 | the administrator application does not have permission to manage the device. |

**示例：**

```ts
import Want from '@ohos.app.ability.Want';
import locationManager from '@ohos.enterprise.locationManager';

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

**系统API：** 此接口为系统接口

**参数：**

| 参数名      | 类型                                       | 必填   | 说明                       |
| -------- | ---------------------------------------- | ---- | ------------------------------- |
| admin    | [Want](js-apis-app-ability-want.md)     | 是    | 设备管理应用。                  |

**返回值：**

| 类型             | 说明                                                   |
| ---------------- | ------------------------------------------------------ |
| LocationPolicy | 位置服务策略枚举值 0：默认策略 1：禁用 2：强制启用。 |

**错误码**：

以下错误码的详细介绍请参见[企业设备管理错误码](../errorcodes/errorcode-enterpriseDeviceManager.md)

| 错误码ID | 错误信息                                                                       |          
| ------- | ---------------------------------------------------------------------------- |
| 9200001 | the application is not an administrator of the device.                        |
| 9200002 | the administrator application does not have permission to manage the device. |

**示例：**

```ts
import Want from '@ohos.app.ability.Want';
import locationManager from '@ohos.enterprise.locationManager';
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

**系统API：** 此接口为系统接口

**模型约束：** 此接口仅可在Stage模型下使用

| 名称                        | 值  | 说明    |
| ----------------------------| ----| ------------------------------- |
| DEFAULT_LOCATION_SERVICE    | 0   | 默认策略。 |
| DISALLOW_LOCATION_SERVICE | 1   | 禁用位置服务策略。 |
| FORCE_OPEN_LOCATION_SERVICE | 2   | 强制开启位置服务策略。 |

