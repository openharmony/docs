# @ohos.enterprise.usbManager（USB管理）

本模块提供USB管理能力。

> **说明**：
>
> 本模块首批接口从API version 12开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>
> 本模块接口仅可在Stage模型下使用。
>
> 本模块接口仅对[设备管理应用](../../mdm/mdm-kit-guide.md#功能介绍)开放，需将设备管理应用激活后调用，实现相应功能。
>
> 全局通用限制类策略由restrictions统一提供，若要全局禁用USB，请参考[@ohos.enterprise.restrictions（限制类策略）](js-apis-enterprise-restrictions.md)。

## 导入模块

```ts
import { usbManager } from '@kit.MDMKit';
```

## usbManager.addAllowedUsbDevices

addAllowedUsbDevices(admin: Want, usbDeviceIds: Array\<UsbDeviceId>): void

指定设备管理应用添加USB设备可用白名单。

**需要权限：** ohos.permission.ENTERPRISE_MANAGE_USB

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager



**参数：**

| 参数名       | 类型                                                    | 必填 | 说明                                        |
| ------------ | ------------------------------------------------------- | ---- | ------------------------------------------- |
| admin        | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | 是   | 设备管理应用。                              |
| usbDeviceIds | Array<[UsbDeviceId](#usbdeviceid)>                      | 是   | USB设备ID数组。添加后的数组长度上限为1000。 |

**错误码**：

以下错误码的详细介绍请参见[企业设备管理错误码](errorcode-enterpriseDeviceManager.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 9200001  | The application is not an administrator application of the device. |
| 9200002  | The administrator application does not have permission to manage the device. |
| 9200010  | A conflict policy has been configured.                       |
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
  let usbDeviceIds: Array<usbManager.UsbDeviceId> = [{
      vendorId: 1,
      productId: 1
  }];
  usbManager.addAllowedUsbDevices(wantTemp, usbDeviceIds);
  console.info(`Succeeded in adding allowed USB devices.`);
} catch (err) {
  console.error(`Failed to add allowed USB devices. Code: ${err.code}, message: ${err.message}`);
}
```

## usbManager.removeAllowedUsbDevices

removeAllowedUsbDevices(admin: Want, usbDeviceIds: Array\<UsbDeviceId>): void

指定设备管理应用移除USB设备可用白名单。

**需要权限：** ohos.permission.ENTERPRISE_MANAGE_USB

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager



**参数：**

| 参数名       | 类型                                                    | 必填 | 说明            |
| ------------ | ------------------------------------------------------- | ---- | --------------- |
| admin        | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | 是   | 设备管理应用。  |
| usbDeviceIds | Array<[UsbDeviceId](#usbdeviceid)>                      | 是   | USB设备ID数组。 |

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
  let usbDeviceIds: Array<usbManager.UsbDeviceId> = [{
      vendorId: 1,
      productId: 1
  }];
  usbManager.removeAllowedUsbDevices(wantTemp, usbDeviceIds);
  console.info(`Succeeded in removing allowed USB devices.`);
} catch (err) {
  console.error(`Failed to remove allowed USB devices. Code: ${err.code}, message: ${err.message}`);
}
```

## usbManager.getAllowedUsbDevices

getAllowedUsbDevices(admin: Want): Array\<UsbDeviceId>

指定设备管理应用获取USB设备可用白名单。

**需要权限：** ohos.permission.ENTERPRISE_MANAGE_USB

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager



**参数：**

| 参数名 | 类型                                                    | 必填 | 说明           |
| ------ | ------------------------------------------------------- | ---- | -------------- |
| admin  | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | 是   | 设备管理应用。 |

**返回值：**

| 类型                               | 说明                      |
| ---------------------------------- | ------------------------- |
| Array<[UsbDeviceId](#usbdeviceid)> | 可用USB白名单设备ID数组。 |

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
  let result: Array<usbManager.UsbDeviceId> = usbManager.getAllowedUsbDevices(wantTemp);
  console.info(`Succeeded in getting allowed USB devices. Result: ${JSON.stringify(result)}`);
} catch (err) {
  console.error(`Failed to get allowed USB devices. Code: ${err.code}, message: ${err.message}`);
}
```

## usbManager.setUsbStorageDeviceAccessPolicy

setUsbStorageDeviceAccessPolicy(admin: Want, usbPolicy: UsbPolicy): void

指定设备管理应用设置USB存储设备访问策略。

**需要权限：** ohos.permission.ENTERPRISE_MANAGE_USB

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager



**参数：**

| 参数名    | 类型                                                    | 必填 | 说明                  |
| --------- | ------------------------------------------------------- | ---- | --------------------- |
| admin     | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | 是   | 设备管理应用。        |
| usbPolicy | [UsbPolicy](#usbpolicy)                                 | 是   | USB存储设备访问策略。 |

**错误码**：

以下错误码的详细介绍请参见[企业设备管理错误码](errorcode-enterpriseDeviceManager.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 9200001  | The application is not an administrator application of the device. |
| 9200002  | The administrator application does not have permission to manage the device. |
| 9200010  | A conflict policy has been configured.                       |
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
  let policy: usbManager.UsbPolicy = usbManager.UsbPolicy.DISABLED;
  usbManager.setUsbStorageDeviceAccessPolicy(wantTemp, policy);
  console.info(`Succeeded in setting USB storage device access policy.`);
} catch (err) {
  console.error(`Failed to setting USB storage device access policy. Code: ${err.code}, message: ${err.message}`);
}
```

## usbManager.getUsbStorageDeviceAccessPolicy

getUsbStorageDeviceAccessPolicy(admin: Want): UsbPolicy

指定设备管理应用获取USB存储设备访问策略。

**需要权限：** ohos.permission.ENTERPRISE_MANAGE_USB

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager



**参数：**

| 参数名 | 类型                                                    | 必填 | 说明           |
| ------ | ------------------------------------------------------- | ---- | -------------- |
| admin  | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | 是   | 设备管理应用。 |

**返回值：**

| 类型                    | 说明                  |
| ----------------------- | --------------------- |
| [UsbPolicy](#usbpolicy) | USB存储设备访问策略。 |

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
  let result: usbManager.UsbPolicy = usbManager.getUsbStorageDeviceAccessPolicy(wantTemp);
  console.info(`Succeeded in getting USB storage device access policy. Result: ${JSON.stringify(result)}`);
} catch (err) {
  console.error(`Failed togetting USB storage device access policy. Code: ${err.code}, message: ${err.message}`);
}
```

## usbManager.addDisallowedUsbDevices<sup>14+</sup>

addDisallowedUsbDevices(admin: Want, usbDevices: Array\<UsbDeviceType>): void

指定设备管理应用添加禁止使用的USB设备类型。

**需要权限：** ohos.permission.ENTERPRISE_MANAGE_USB

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager



**参数：**

| 参数名     | 类型                                                    | 必填 | 说明                                                   |
| ---------- | ------------------------------------------------------- | ---- | ------------------------------------------------------ |
| admin      | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | 是   | 设备管理应用。                                         |
| usbDevices | Array<[UsbDeviceType](#usbdevicetype14)>                | 是   | 要添加的USB设备类型的数组。添加后的数组长度上限为200。 |

**错误码**：

以下错误码的详细介绍请参见[企业设备管理错误码](errorcode-enterpriseDeviceManager.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 9200001  | The application is not an administrator application of the device. |
| 9200002  | The administrator application does not have permission to manage the device. |
| 9200010  | A conflict policy has been configured.                       |
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
  let usbDevices: Array<usbManager.UsbDeviceType> = [{
      baseClass: 8,
      subClass: 0,
      protocol: 0,
      descriptor: usbManager.Descriptor.INTERFACE
  }];
  usbManager.addDisallowedUsbDevices(wantTemp, usbDevices);
  console.info(`Succeeded in adding disallowed USB devices.`);
} catch (err) {
  console.error(`Failed to add disallowed USB devices. Code: ${err.code}, message: ${err.message}`);
}
```

## usbManager.removeDisallowedUsbDevices<sup>14+</sup>

removeDisallowedUsbDevices(admin: Want, usbDevices: Array\<UsbDeviceType>): void

指定设备管理应用移除禁止使用的USB设备类型。

**需要权限：** ohos.permission.ENTERPRISE_MANAGE_USB

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager



**参数：**

| 参数名     | 类型                                                    | 必填 | 说明                        |
| ---------- | ------------------------------------------------------- | ---- | --------------------------- |
| admin      | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | 是   | 设备管理应用。              |
| usbDevices | Array<[UsbDeviceType](#usbdevicetype14)>                | 是   | 要移除的USB设备类型的数组。 |

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
  let usbDevices: Array<usbManager.UsbDeviceType> = [{
      baseClass: 8,
      subClass: 0,
      protocol: 0,
      descriptor: usbManager.Descriptor.INTERFACE
  }];
  usbManager.removeDisallowedUsbDevices(wantTemp, usbDevices);
  console.info(`Succeeded in removing disallowed USB devices.`);
} catch (err) {
  console.error(`Failed to remove disallowed USB devices. Code: ${err.code}, message: ${err.message}`);
}
```

## usbManager.getDisallowedUsbDevices<sup>14+</sup>

getDisallowedUsbDevices(admin: Want): Array\<UsbDeviceType>

指定设备管理应用获取禁止使用的USB设备类型。

**需要权限：** ohos.permission.ENTERPRISE_MANAGE_USB

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager



**参数：**

| 参数名 | 类型                                                    | 必填 | 说明           |
| ------ | ------------------------------------------------------- | ---- | -------------- |
| admin  | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | 是   | 设备管理应用。 |

**返回值：**

| 类型                                     | 说明                    |
| ---------------------------------------- | ----------------------- |
| Array<[UsbDeviceType](#usbdevicetype14)> | 禁止使用的USB设备类型。 |

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
  let result: Array<usbManager.UsbDeviceType> = usbManager.getDisallowedUsbDevices(wantTemp);
  console.info(`Succeeded in getting disallowed USB devices. Result: ${JSON.stringify(result)}`);
} catch (err) {
  console.error(`Failed to get disallowed USB devices. Code: ${err.code}, message: ${err.message}`);
}
```

## UsbDeviceId

USB设备ID信息。

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

| 名称      | 类型   | 必填 | 说明     |
| --------- | ------ | ---- | -------- |
| vendorId  | number | 是   | 厂商ID。 |
| productId | number | 是   | 产品ID。 |

## UsbDeviceType<sup>14+</sup>

USB设备类型信息。其中具体编号可查询：https://www.usb.org/defined-class-codes

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

| 名称       | 类型                        | 必填 | 说明         |
| ---------- | --------------------------- | ---- | ------------ |
| baseClass  | number                      | 是   | 类型编号。   |
| subClass   | number                      | 是   | 子类型编号。 |
| protocol   | number                      | 是   | 协议编号。   |
| descriptor | [Descriptor](#descriptor14) | 是   | USB描述符。  |

## UsbPolicy

USB读写策略的枚举。

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

| 名称       | 值   | 说明       |
| ---------- | ---- | ---------- |
| READ_WRITE | 0    | 可读可写。 |
| READ_ONLY  | 1    | 只读。     |
| DISABLED   | 2    | 禁用。     |

## Descriptor<sup>14+</sup>

USB描述符的枚举。

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

| 名称      | 值   | 说明         |
| --------- | ---- | ------------ |
| INTERFACE | 0    | 接口描述符。 |
| DEVICE    | 1    | 设备描述符。 |
