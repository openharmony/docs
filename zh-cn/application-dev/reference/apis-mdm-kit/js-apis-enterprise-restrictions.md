# @ohos.enterprise.restrictions （限制类策略）

本模块提供设置通用限制类策略能力。可以全局禁用和解除禁用蓝牙、HDC、USB、Wi-Fi等特性。

> **说明**：
>
> 本模块首批接口从API version 12 开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>
> 本模块接口仅可在Stage模型下使用。
>
> 本模块接口仅对[设备管理应用](../../mdm/mdm-kit-guide.md#功能介绍)开放，需将设备管理应用激活后调用，实现相应功能。

## 导入模块

```ts
import { restrictions } from '@kit.MDMKit';
```

## restrictions.setDisallowedPolicy

setDisallowedPolicy(admin: Want, feature: string, disallow: boolean): void

设置禁用/启用某特性。 

**需要权限：** ohos.permission.ENTERPRISE_MANAGE_RESTRICTIONS

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**参数：**

| 参数名   | 类型                                                    | 必填 | 说明                                                         |
| -------- | ------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| admin    | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | 是   | 企业设备管理扩展组件。                                       |
| feature  | string                                                  | 是   | feature名称。<br/>- bluetooth：设备蓝牙能力。<br/>- modifyDateTime：设备修改系统时间能力，当前仅支持2in1设备使用。<br/>- printer：设备打印能力，当前仅支持2in1设备使用。<br/>- hdc：设备HDC能力。<br/>- microphone：设备麦克风能力。<br/>- fingerprint：设备指纹认证能力。<br/>- usb：设备USB能力。禁用后外接的USB设备无法使用，即在当前设备为HOST模式时，无法外接其他DEVICE设备。<br/>  以下两种情况再通过本接口禁用设备USB能力，会报策略冲突。<br/>  1）通过[addAllowedUsbDevices](js-apis-enterprise-usbManager.md#usbmanageraddallowedusbdevices)接口添加了USB设备可用白名单。<br/>  2）通过[setUsbStorageDeviceAccessPolicy](js-apis-enterprise-usbManager.md#usbmanagersetusbstoragedeviceaccesspolicy)接口设置了USB存储设备访问策略为只读/禁用。<br/>- wifi：设备WIFI能力。 <!--RP1--><!--RP1End--> |
| disallow | boolean                                                 | 是   | true表示禁止使用，false表示允许使用。                        |

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
import { Want } from '@kit.AbilityKit';
let wantTemp: Want = {
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility',
};

try {
  restrictions.setDisallowedPolicy(wantTemp, 'printer', true);
  console.info('Succeeded in setting printer disabled');
} catch (err) {
  console.error(`Failed to set printer disabled. Code is ${err.code}, message is ${err.message}`);
}
```

## restrictions.getDisallowedPolicy

getDisallowedPolicy(admin: Want, feature: string): boolean

获取某特性的禁用状态。 

**需要权限：** ohos.permission.ENTERPRISE_MANAGE_RESTRICTIONS

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**参数：**

| 参数名  | 类型                                                    | 必填 | 说明                                                         |
| ------- | ------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| admin   | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | 是   | 企业设备管理扩展组件。                                       |
| feature | string                                                  | 是   | feature名称。<br/>- bluetooth：设备蓝牙能力。<br/>- modifyDateTime：设备修改系统时间能力，当前仅支持2in1设备使用。<br/>- printer：设备打印能力，当前仅支持2in1设备使用。<br/>- hdc：设备HDC能力。<br/>- microphone：设备麦克风能力。<br/>- fingerprint：设备指纹认证能力。<br/>- usb：设备USB能力。禁用后外接的USB设备无法使用，即在当前设备为HOST模式时，无法外接其他DEVICE设备。<br/>- wifi：设备WIFI能力。<!--RP2--><!--RP2End--> |

**返回值：**

| 类型    | 说明                                                         |
| ------- | ------------------------------------------------------------ |
| boolean | 返回true表示feature对应的某种特性被禁用，false表示feature对应的某种特性未被禁用。 |

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
import { Want } from '@kit.AbilityKit';
let wantTemp: Want = {
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility',
};

try {
  let result: boolean = restrictions.getDisallowedPolicy(wantTemp, 'printer');
  console.info(`Succeeded in querying is the printing function disabled : ${result}`);
} catch (err) {
  console.error(`Failed to set printer disabled. Code is ${err.code}, message is ${err.message}`);
}
```
