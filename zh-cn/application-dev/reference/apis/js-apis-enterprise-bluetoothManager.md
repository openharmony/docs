# @ohos.enterprise.bluetoothManager（蓝牙管理）

本模块提供设备蓝牙管理的能力，包括设置和查询蓝牙信息等。

> **说明：**
>
> 本模块首批接口从API version 11开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>
> 本模块接口仅可在Stage模型下使用。
>
> 本模块接口仅对[设备管理应用](enterpriseDeviceManagement-overview.md#基本概念)开放，需将[设备管理应用激活](js-apis-enterprise-adminManager.md#adminmanagerenableadmin)后调用，实现相应功能。

## 导入模块

```ts
import bluetoothManager from '@ohos.enterprise.bluetoothManager';
```

## bluetoothManager.getBluetoothInfo

getBluetoothInfo(admin: Want): BluetoothInfo;

以同步方法查询设备蓝牙信息。成功返回设备蓝牙信息，失败抛出对应异常。

**需要权限：** ohos.permission.ENTERPRISE_MANAGE_BLUETOOTH

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**系统API：** 此接口为系统接口

**参数：**

| 参数名      | 类型                                       | 必填   | 说明                       |
| -------- | ---------------------------------------- | ---- | ------------------------------- |
| admin    | [Want](js-apis-app-ability-want.md)     | 是    | 设备管理应用。                  |

**返回值：**

| 类型             | 说明                                                   |
| ---------------- | ------------------------------------------------------ |
| BluetoothInfo (js-apis-enterprise-bluetoothManager.md)| 蓝牙信息，包含蓝牙名称、蓝牙状态和蓝牙连接状态。 |

**错误码**：

以下错误码的详细介绍请参见[企业设备管理错误码](../errorcodes/errorcode-enterpriseDeviceManager.md)

| 错误码ID | 错误信息                                                                       |          
| ------- | ---------------------------------------------------------------------------- |
| 9200001 | the application is not an administrator of the device.                        |
| 9200002 | the administrator application does not have permission to manage the device. |

**示例：**

```ts
import Want from '@ohos.app.ability.Want';
let wantTemp: Want = {
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility',
};

try {
    let result: bluetoothManager.BluetoothInfo = bluetoothManager.getBluetoothInfo(wantTemp);
    console.info(`Succeeded in getting bluetooth info. `);
} catch(err) {
    console.error(`Failed to get bluetooth info. Code: ${err.code}, message: ${err.message}`);
}
```

## BluetoothInfo

设备的蓝牙信息。

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**系统API: ** 此接口为系统接口

**模型约束: ** 此接口仅可在Stage模型下使用

| 名称         | 类型     | 必填 | 说明                            |
| ----------- | --------| ---- | ------------------------------- |
| name        | string   | 是   | 表示设备的蓝牙名称。 |
| state |access.BluetoothState (js-apis-bluetooth-access.md)  | 是   | 表示设备的蓝牙状态。 |
| connectionState | constant.ProfileConnectionState (js-apis-bluetooth-constant.md)  | 是   | 表示设备的蓝牙连接状态。 |