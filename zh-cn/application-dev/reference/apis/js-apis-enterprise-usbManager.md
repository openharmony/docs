# @ohos.enterprise.usbManager (USB管理)

本模块提供USB管理能力。

> **说明**：
> 
> 本模块首批接口从API version 10开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>
> 本模块接口仅可在Stage模型下使用。
>
> 本模块接口仅对[设备管理应用](enterpriseDeviceManagement-overview.md#基本概念)开放，需将[设备管理应用激活](js-apis-enterprise-adminManager.md#adminmanagerenableadmin)后调用，实现相应功能。

## 导入模块

```ts
import usbManager from '@ohos.enterprise.usbManager';
```

## usbManager.setUsbPolicy

setUsbPolicy(admin: Want, usbPolicy: UsbPolicy, callback: AsyncCallback\<void>): void

指定设备管理应用设置USB的读写策略。使用callback异步回调。

**需要权限：** ohos.permission.ENTERPRISE_MANAGE_USB

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**系统API**: 此接口为系统接口。

**参数：**

| 参数名   | 类型                                  | 必填   | 说明      |
| ----- | ----------------------------------- | ---- | ------- |
| admin | [Want](js-apis-app-ability-want.md) | 是    | 设备管理应用。 |
| usbPolicy  | [UsbPolicy](#usbpolicy) | 是 | USB读写策略（此接口只支持READ_WRITE和READ_ONLY）。 |
| callback | AsyncCallback\<void> | 是 | 回调函数。当接口调用成功，err为null，否则为错误对象。 |

**错误码**：

以下错误码的详细介绍请参见[企业设备管理错误码](../errorcodes/errorcode-enterpriseDeviceManager.md)

| 错误码ID | 错误信息                                                                      |
| ------- | ---------------------------------------------------------------------------- |
| 9200001 | the application is not an administrator of the device.                       |
| 9200002 | the administrator application does not have permission to manage the device. |

**示例：**

```ts
import Want from '@ohos.app.ability.Want';
let wantTemp: Want = {
  bundleName: 'bundleName',
  abilityName: 'abilityName',
};
let policy: usbManager.UsbPolicy = usbManager.UsbPolicy.READ_WRITE

usbManager.setUsbPolicy(wantTemp, policy, (err) => {
  if (err) {
    console.error(`Failed to set usb policy. Code is ${err.code}, message is ${err.message}`);
    return;
  }
  console.info('Succeeded in setting usb policy');
})
```

## usbManager.setUsbPolicy

setUsbPolicy(admin: Want, usbPolicy: UsbPolicy): Promise\<void>

指定设备管理应用设置USB的读写策略。使用Promise异步回调。

**需要权限：** ohos.permission.ENTERPRISE_MANAGE_USB

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**系统API**: 此接口为系统接口。

**参数：**

| 参数名   | 类型                                  | 必填   | 说明      |
| ----- | ----------------------------------- | ---- | ------- |
| admin | [Want](js-apis-app-ability-want.md) | 是    | 设备管理应用。 |
| usbPolicy  | [UsbPolicy](#usbpolicy) | 是 | USB读写策略（此接口只支持READ_WRITE和READ_ONLY）。 |

**返回值：**

| 类型   | 说明                                  |
| ----- | ----------------------------------- |
| Promise\<void> | 无返回结果的Promise对象。当指定设备管理应用设置USB策略失败时抛出错误对象。 |

**错误码**：

以下错误码的详细介绍请参见[企业设备管理错误码](../errorcodes/errorcode-enterpriseDeviceManager.md)

| 错误码ID | 错误信息                                                                      |
| ------- | ---------------------------------------------------------------------------- |
| 9200001 | the application is not an administrator of the device.                        |
| 9200002 | the administrator application does not have permission to manage the device. |

**示例：**

```ts
import Want from '@ohos.app.ability.Want';
import { BusinessError } from '@ohos.base';
let wantTemp: Want = {
  bundleName: 'bundleName',
  abilityName: 'abilityName',
};
let policy: usbManager.UsbPolicy = usbManager.UsbPolicy.READ_WRITE

usbManager.setUsbPolicy(wantTemp, policy).then(() => {
  console.info('Succeeded in setting usb policy');
}).catch((err: BusinessError) => {
  console.error(`Failed to set usb policy. Code is ${err.code}, message is ${err.message}`);
})
```

## UsbPolicy

USB读写策略的枚举。

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**系统API**: 此接口为系统接口。

| 名称 | 值 | 说明 |
| -------- | -------- | -------- |
| READ_WRITE | 0 | 可读可写。 |
| READ_ONLY | 1 | 只读。 |
| DISABLED<sup>11+</sup> | 2 | 禁用。 |

## UsbDeviceId<sup>11+</sup>

USB设备ID信息。

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**系统API**: 此接口为系统接口。

| 名称      | 类型   | 必填 | 说明     |
| --------- | ------ | ---- | -------- |
| vendorId  | number | 是   | 厂商ID。 |
| productId | number | 是   | 产品ID。 |

## usbManager.disableUsb<sup>11+</sup>

disableUsb(admin: Want, disable: boolean): void

指定设备管理应用设置禁用或启用USB。

**需要权限：** ohos.permission.ENTERPRISE_MANAGE_USB

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**系统API**: 此接口为系统接口。

**参数：**

| 参数名  | 类型                                | 必填 | 说明                                             |
| ------- | ----------------------------------- | ---- | ------------------------------------------------ |
| admin   | [Want](js-apis-app-ability-want.md) | 是   | 设备管理应用。                                   |
| disable | boolean                             | 是   | 是否禁用USB设备，true表示禁用，false表示不禁用。 |

**错误码**：

以下错误码的详细介绍请参见[企业设备管理错误码](../errorcodes/errorcode-enterpriseDeviceManager.md)

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 9200001  | the application is not an administrator of the device.       |
| 9200002  | the administrator application does not have permission to manage the device. |

**示例：**

```ts
import Want from '@ohos.app.ability.Want';
let wantTemp: Want = {
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility',
};
try {
  usbManager.disableUsb(wantTemp, true);
  console.info(`Succeeded in disabling USB`);
} catch (err) {
  console.error(`Failed to disabling USB. Code: ${err.code}, message: ${err.message}`);
}
```

## usbManager.isUsbDisabled<sup>11+</sup>

isUsbDevicesDisallowed(admin: Want): boolean

指定设备管理应用查询USB是否禁用。

**需要权限：** ohos.permission.ENTERPRISE_MANAGE_USB

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**系统API**: 此接口为系统接口。

**参数：**

| 参数名 | 类型                                | 必填 | 说明           |
| ------ | ----------------------------------- | ---- | -------------- |
| admin  | [Want](js-apis-app-ability-want.md) | 是   | 设备管理应用。 |

**返回值：**

| 类型    | 说明                                                   |
| ------- | ------------------------------------------------------ |
| boolean | 返回true表示USB被禁用，<br/>返回false表示USB未被禁用。 |

**错误码**：

以下错误码的详细介绍请参见[企业设备管理错误码](../errorcodes/errorcode-enterpriseDeviceManager.md)

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 9200001  | the application is not an administrator of the device.       |
| 9200002  | the administrator application does not have permission to manage the device. |

**示例：**

```ts
import Want from '@ohos.app.ability.Want';
let wantTemp: Want = {
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility',
};
try {
  let isDisabled = usbManager.isUsbDisabled(wantTemp);
  console.info(`Succeeded in querying if USB is disabled: ${isDisabled}`);
} catch (err) {
  console.error(`Failed to query if USB is disabled. Code: ${err.code}, message: ${err.message}`);
}
```

## usbManager.addAllowedUsbDevices<sup>11+</sup>

addAllowedUsbDevices(admin: Want, usbDeviceIds: Array<usbManager.UsbDeviceId>): void

指定设备管理应用添加USB设备可用白名单。

**需要权限：** ohos.permission.ENTERPRISE_MANAGE_USB

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**系统API**: 此接口为系统接口。

**参数：**

| 参数名       | 类型                                            | 必填 | 说明                                        |
| ------------ | ----------------------------------------------- | ---- | ------------------------------------------- |
| admin        | [Want](js-apis-app-ability-want.md)             | 是   | 设备管理应用。                              |
| usbDeviceIds | Array<[usbManager.UsbDeviceId](#usbdeviceid11)> | 是   | USB设备ID数组。添加后的数组长度上限为1000。 |

**错误码**：

以下错误码的详细介绍请参见[企业设备管理错误码](../errorcodes/errorcode-enterpriseDeviceManager.md)

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 9200001  | the application is not an administrator of the device.       |
| 9200002  | the administrator application does not have permission to manage the device. |

**示例：**

```ts
import Want from '@ohos.app.ability.Want';
let wantTemp: Want = {
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility',
};
try {
  let usbDeviceIds: Array<usbManager.UsbDeviceId> = [{
      vendorId: 1,
      productId: 1
  }];
  usbManager.addAllowedUsbDevices(wantTemp, usbDeviceIds);
  console.info(`Succeeded in adding allowed USB devices`);
} catch (err) {
  console.error(`Failed to adding allowed USB devices. Code: ${err.code}, message: ${err.message}`);
}
```

## usbManager.removeAllowedUsbDevices<sup>11+</sup>

removeAllowedUsbDevices(admin: Want, usbDeviceIds: Array<usbManager.UsbDeviceId>): void

指定设备管理应用移除USB设备可用白名单。

**需要权限：** ohos.permission.ENTERPRISE_MANAGE_USB

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**系统API**: 此接口为系统接口。

**参数：**

| 参数名       | 类型                                            | 必填 | 说明            |
| ------------ | ----------------------------------------------- | ---- | --------------- |
| admin        | [Want](js-apis-app-ability-want.md)             | 是   | 设备管理应用。  |
| usbDeviceIds | Array<[usbManager.UsbDeviceId](#usbdeviceid11)> | 是   | USB设备ID数组。 |

**错误码**：

以下错误码的详细介绍请参见[企业设备管理错误码](../errorcodes/errorcode-enterpriseDeviceManager.md)

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 9200001  | the application is not an administrator of the device.       |
| 9200002  | the administrator application does not have permission to manage the device. |

**示例：**

```ts
import Want from '@ohos.app.ability.Want';
let wantTemp: Want = {
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility',
};
try {
  let usbDeviceIds: Array<usbManager.UsbDeviceId> = [{
      vendorId: 1,
      productId: 1
  }];
  usbManager.removeAllowedUsbDevices(wantTemp, usbDeviceIds);
  console.info(`Succeeded in removing allowed USB devices`);
} catch (err) {
  console.error(`Failed to removing allowed USB devices. Code: ${err.code}, message: ${err.message}`);
}
```

## usbManager.getAllowedUsbDevices<sup>11+</sup>

getAllowedUsbDevices(admin: Want): Array<usbManager.UsbDeviceId>

指定设备管理应用获取USB设备可用白名单。

**需要权限：** ohos.permission.ENTERPRISE_MANAGE_USB

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**系统API**: 此接口为系统接口。

**参数：**

| 参数名 | 类型                                | 必填 | 说明           |
| ------ | ----------------------------------- | ---- | -------------- |
| admin  | [Want](js-apis-app-ability-want.md) | 是   | 设备管理应用。 |

**返回值：**

| 类型                                            | 说明                      |
| ----------------------------------------------- | ------------------------- |
| Array<[usbManager.UsbDeviceId](#usbdeviceid11)> | 可用USB白名单设备ID数组。 |

**错误码**：

以下错误码的详细介绍请参见[企业设备管理错误码](../errorcodes/errorcode-enterpriseDeviceManager.md)

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 9200001  | the application is not an administrator of the device.       |
| 9200002  | the administrator application does not have permission to manage the device. |

**示例：**

```ts
import Want from '@ohos.app.ability.Want';
let wantTemp: Want = {
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility',
};
try {
  let result: Array<usbManager.UsbDeviceId> = usbManager.getAllowedUsbDevices(wantTemp);
  console.info(`Succeeded in removing allowed USB devices. Result: ${JSON.stringify(result)}`);
} catch (err) {
  console.error(`Failed to removing allowed USB devices. Code: ${err.code}, message: ${err.message}`);
}
```

## usbManager.setUsbStorageDeviceAccessPolicy<sup>11+</sup>

setUsbStorageDeviceAccessPolicy(admin: Want, usbPolicy: UsbPolicy): void

指定设备管理应用设置USB存储设备访问策略。

**需要权限：** ohos.permission.ENTERPRISE_MANAGE_USB

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**系统API**: 此接口为系统接口。

**参数：**

| 参数名    | 类型                                | 必填 | 说明                  |
| --------- | ----------------------------------- | ---- | --------------------- |
| admin     | [Want](js-apis-app-ability-want.md) | 是   | 设备管理应用。        |
| usbPolicy | [UsbPolicy](#usbpolicy)             | 是   | USB存储设备访问策略。 |

**错误码**：

以下错误码的详细介绍请参见[企业设备管理错误码](../errorcodes/errorcode-enterpriseDeviceManager.md)

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 9200001  | the application is not an administrator of the device.       |
| 9200002  | the administrator application does not have permission to manage the device. |

**示例：**

```ts
import Want from '@ohos.app.ability.Want';
let wantTemp: Want = {
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility',
};
try {
  let policy: usbManager.UsbPolicy = usbManager.UsbPolicy.DISABLED;
  usbManager.setUsbStorageDeviceAccessPolicy(wantTemp, policy);
  console.info(`Succeeded in setting USB storage device access policy`);
} catch (err) {
  console.error(`Failed to setting USB storage device access policy. Code: ${err.code}, message: ${err.message}`);
}
```

## usbManager.getUsbStorageDeviceAccessPolicy<sup>11+</sup>

getUsbStorageDeviceAccessPolicy(admin: Want): Array<usbManager.UsbDeviceId>

指定设备管理应用获取USB存储设备访问策略。

**需要权限：** ohos.permission.ENTERPRISE_MANAGE_USB

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**系统API**: 此接口为系统接口。

**参数：**

| 参数名 | 类型                                | 必填 | 说明           |
| ------ | ----------------------------------- | ---- | -------------- |
| admin  | [Want](js-apis-app-ability-want.md) | 是   | 设备管理应用。 |

**返回值：**

| 类型                    | 说明                  |
| ----------------------- | --------------------- |
| [UsbPolicy](#usbpolicy) | USB存储设备访问策略。 |

**错误码**：

以下错误码的详细介绍请参见[企业设备管理错误码](../errorcodes/errorcode-enterpriseDeviceManager.md)

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 9200001  | the application is not an administrator of the device.       |
| 9200002  | the administrator application does not have permission to manage the device. |

**示例：**

```ts
import Want from '@ohos.app.ability.Want';
let wantTemp: Want = {
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility',
};
try {
  let result: usbManager.UsbPolicy = usbManager.getUsbStorageDeviceAccessPolicy(wantTemp);
  console.info(`Succeeded in getting USB storage device access policy. Result: ${JSON.stringify(result)}`);
} catch (err) {
  console.error(`Failed togetting USB storage device access policy. Code: ${err.code}, message: ${err.message}`);
}
```
