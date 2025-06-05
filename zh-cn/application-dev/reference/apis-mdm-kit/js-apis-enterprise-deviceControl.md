# @ohos.enterprise.deviceControl（设备控制管理）

本模块提供设备控制能力。

> **说明**：
>
> 本模块首批接口从API version 12 开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>
> 本模块接口仅可在Stage模型下使用。
>
> 本模块接口仅对设备管理应用开放，且调用接口前需激活设备管理应用，具体请参考[MDM Kit开发指南](../../mdm/mdm-kit-guide.md)。

## 导入模块

```ts
import { deviceControl } from '@kit.MDMKit';
```

## deviceControl.operateDevice

operateDevice(admin: Want, operate: string, addition?: string): void

允许管理员操作设备。

**需要权限：** ohos.permission.ENTERPRISE_OPERATE_DEVICE

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager


**参数：**

| 参数名   | 类型                                                    | 必填 | 说明                                                         |
| -------- | ------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| admin    | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | 是   | 企业设备管理扩展组件。                                               |
| operate  | string                                                  | 是   | 要执行的操作。<br/>- resetFactory：设备恢复出厂设置。<br/>- reboot：设备重启。<br/>- shutDown：设备关机。<br/>- lockScreen：设备屏幕锁定。 <!--RP1--><!--RP1End-->|
| addition | string                                                  | 否   | <!--RP2-->执行时附加参数。目前无需传入。<!--RP2End-->       |

**错误码：**

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
  deviceControl.operateDevice(wantTemp, 'resetFactory');
} catch (err) {
  console.error(`Failed to reset factory. Code is ${err.code}, message is ${err.message}`);
}
```
