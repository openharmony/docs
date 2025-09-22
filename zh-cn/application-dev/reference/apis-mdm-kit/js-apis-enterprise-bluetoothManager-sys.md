# @ohos.enterprise.bluetoothManager（蓝牙管理）(系统接口)
<!--Kit: MDM Kit-->
<!--Subsystem: Customization-->
<!--Owner: @huanleima-->
<!--Designer: @liuzuming-->
<!--Tester: @lpw_work-->
<!--Adviser: @Brilliantry_Rui-->

本模块提供设备蓝牙管理的能力，包括设置和查询蓝牙信息等。

> **说明：**
>
> 本模块首批接口从API version 11开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>
> 本模块接口仅可在Stage模型下使用。
>
> 本模块接口仅对[设备管理应用](../../mdm/mdm-kit-term.md#mdm应用设备管理应用)开放，需将[设备管理应用激活](js-apis-enterprise-adminManager-sys.md#adminmanagerenableadmin-2)后调用。
> 
> 当前页面仅包含本模块的系统接口，其他公开接口参见[@ohos.enterprise.bluetoothManager](js-apis-enterprise-bluetoothManager.md)。

## 导入模块

```ts
import { bluetoothManager } from '@kit.MDMKit';
```

## bluetoothManager.isBluetoothDisabled

isBluetoothDisabled(admin: Want): boolean

查询蓝牙是否被禁用。

**需要权限：** ohos.permission.ENTERPRISE_MANAGE_BLUETOOTH

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**模型约束：** 此接口仅可在Stage模型下使用。

**系统接口：** 此接口为系统接口。

**参数：**

| 参数名 | 类型                                                    | 必填 | 说明                   |
| ------ | ------------------------------------------------------- | ---- | ---------------------- |
| admin  | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | 是   | 企业设备管理扩展组件。 |

**返回值：**

| 类型                   | 说明                      |
| :-------------------- | ------------------------- |
| boolean | 返回蓝牙禁用状态，true表示蓝牙被禁用，false表示蓝牙未被禁用。 |

**错误码：**

以下的错误码的详细介绍请参见[企业设备管理错误码](errorcode-enterpriseDeviceManager.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                                     |
| ------- | ---------------------------------------------------------------------------- |
| 9200001 | The application is not an administrator application of the device. |
| 9200002 | The administrator application does not have permission to manage the device. |
| 201 | Permission verification failed. The application does not have the permission required to call the API. |
| 202 | Permission verification failed. A non-system application calls a system API. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**示例：**

```ts
import { bluetoothManager } from '@kit.MDMKit';
import { Want } from '@kit.AbilityKit';

let wantTemp: Want = {
  // 需根据实际情况进行替换
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility'
};

try {
  let isDisabled: boolean = bluetoothManager.isBluetoothDisabled(wantTemp);
  console.info(`Succeeded in querying the bluetooth is disabled or not, isDisabled : ${isDisabled}`);
} catch(err) {
  console.error(`Failed to query the bluetooth is disabled or not. Code: ${err.code}, message: ${err.message}`);
};
```

## bluetoothManager.setBluetoothDisabled

setBluetoothDisabled(admin: Want, disabled: boolean): void

设置禁用蓝牙策略。

**需要权限：** ohos.permission.ENTERPRISE_MANAGE_BLUETOOTH

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**模型约束：** 此接口仅可在Stage模型下使用。

**系统接口：** 此接口为系统接口。

**参数：**

| 参数名   | 类型                                                    | 必填 | 说明                                      |
| -------- | ------------------------------------------------------- | ---- | ----------------------------------------- |
| admin    | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | 是   | 企业设备管理扩展组件。                    |
| disabled | boolean                                                 | 是   | true表示禁用蓝牙，false表示解除蓝牙禁用。 |

**错误码：**

以下的错误码的详细介绍请参见[企业设备管理错误码](errorcode-enterpriseDeviceManager.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 9200001  | The application is not an administrator application of the device. |
| 9200002  | The administrator application does not have permission to manage the device. |
| 201      | Permission verification failed. The application does not have the permission required to call the API. |
| 202      | Permission verification failed. A non-system application calls a system API. |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**示例：**

```ts
import { bluetoothManager } from '@kit.MDMKit';
import { Want } from '@kit.AbilityKit';

let wantTemp: Want = {
  // 需根据实际情况进行替换
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility'
};

try {
  bluetoothManager.setBluetoothDisabled(wantTemp, true);
  console.info('Succeeded in setting the bluetooth disabled.');
} catch(err) {
  console.error(`Failed to set the bluetooth disabled. Code: ${err.code}, message: ${err.message}`);
};
```
