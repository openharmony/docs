# @ohos.enterprise.bluetoothManager（蓝牙管理）

本模块提供设备蓝牙管理的能力，包括设置和查询蓝牙信息等。

> **说明：**
>
> 本模块首批接口从API version 12开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>
> 本模块接口仅可在Stage模型下使用。
>
> 本模块接口仅对[设备管理应用](enterpriseDeviceManagement-overview.md#基本概念)开放，需将设备管理应用激活后调用，实现相应功能。
>

## 导入模块

```ts
import bluetoothManager from '@ohos.enterprise.bluetoothManager';
```

## bluetoothManager.addAllowedBluetoothDevices

addAllowedBluetoothDevices(admin: Want, deviceIds: Array\<string>): void

指定设备管理应用添加蓝牙设备可用白名单。

**需要权限：** ohos.permission.ENTERPRISE_MANAGE_BLUETOOTH

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager



**参数：**

| 参数名    | 类型                                                    | 必填 | 说明                                                |
| --------- | ------------------------------------------------------- | ---- | --------------------------------------------------- |
| admin     | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | 是   | 设备管理应用。                                      |
| deviceIds | Array\<string>                                          | 是   | 蓝牙设备MAC地址的数组。添加后的数组长度上限为1000。 |

**错误码**：

以下错误码的详细介绍请参见[企业设备管理错误码](errorcode-enterpriseDeviceManager.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 9200001  | The application is not an administrator application of the device. |
| 9200002  | the administrator application does not have permission to manage the device. |
| 9200010  | a conflicting policy has been configured.                    |

**示例：**

```ts
import Want from '@ohos.app.ability.Want';
import bluetoothManager from '@ohos.enterprise.bluetoothManager';
let wantTemp: Want = {
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility',
};
let deviceIds: Array<string> = ["00:1A:2B:3C:4D:5E","AA:BB:CC:DD:EE:FF"];
try {
    bluetoothManager.addAllowedBluetoothDevices(wantTemp,deviceIds);
    console.info(`Succeeded in adding allowed bluetooth devices.`);
} catch(err) {
    console.error(`Failed to add allowed bluetooth devices. Code: ${err.code}, message: ${err.message}`);
}
```

## bluetoothManager.removeAllowedBluetoothDevices

removeAllowedBluetoothDevices(admin: Want, deviceIds: Array\<string>): void

指定设备管理应用移除蓝牙设备可用白名单。

**需要权限：** ohos.permission.ENTERPRISE_MANAGE_BLUETOOTH

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager



**参数：**

| 参数名    | 类型                                                    | 必填 | 说明                    |
| --------- | ------------------------------------------------------- | ---- | ----------------------- |
| admin     | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | 是   | 设备管理应用。          |
| deviceIds | Array\<string>                                          | 是   | 蓝牙设备MAC地址的数组。 |

**错误码**：

以下错误码的详细介绍请参见[企业设备管理错误码](errorcode-enterpriseDeviceManager.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 9200001  | The application is not an administrator application of the device. |
| 9200002  | the administrator application does not have permission to manage the device. |

**示例：**

```ts
import Want from '@ohos.app.ability.Want';
import bluetoothManager from '@ohos.enterprise.bluetoothManager';
let wantTemp: Want = {
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility',
};
let deviceIds: Array<string> = ["00:1A:2B:3C:4D:5E","AA:BB:CC:DD:EE:FF"];
try {
    bluetoothManager.removeAllowedBluetoothDevices(wantTemp,deviceIds);
    console.info(`Succeeded in removing allowed bluetooth devices.`);
} catch(err) {
    console.error(`Failed to remove allowed bluetooth devices. Code: ${err.code}, message: ${err.message}`);
}
```

## bluetoothManager.getAllowedBluetoothDevices

getAllowedBluetoothDevices(admin: Want): Array\<string>;

指定设备管理应用获取蓝牙设备可用白名单。

**需要权限：** ohos.permission.ENTERPRISE_MANAGE_BLUETOOTH

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager



**参数：**

| 参数名 | 类型                                                    | 必填 | 说明           |
| ------ | ------------------------------------------------------- | ---- | -------------- |
| admin  | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | 是   | 设备管理应用。 |

**返回值：**

| 类型           | 说明                                |
| -------------- | ----------------------------------- |
| Array\<string> | 可用白名单中蓝牙设备MAC地址的数组。 |

**错误码**：

以下错误码的详细介绍请参见[企业设备管理错误码](errorcode-enterpriseDeviceManager.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 9200001  | The application is not an administrator application of the device. |
| 9200002  | the administrator application does not have permission to manage the device. |

**示例：**

```ts
import Want from '@ohos.app.ability.Want';
import bluetoothManager from '@ohos.enterprise.bluetoothManager';
let wantTemp: Want = {
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility',
};
try {
    let result: Array<string> = bluetoothManager.getAllowedBluetoothDevices(wantTemp);
    console.info(`Succeeded in getting allowed bluetooth devices. Result: ${JSON.stringify(result)}`);
} catch(err) {
    console.error(`Failed to get allowed bluetooth devices. Code: ${err.code}, message: ${err.message}`);
}
```
