# @ohos.enterprise.usbManager（USB管理）
<!--Kit: MDM Kit-->
<!--Subsystem: Customization-->
<!--Owner: @huanleima-->
<!--SE: @liuzuming-->
<!--TSE: @lpw_work-->

本模块提供USB管理能力。

> **说明**：
>
> 本模块首批接口从API version 12开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>
> 本模块接口仅可在Stage模型下使用。
>
> 本模块接口仅对设备管理应用开放，且调用接口前需激活设备管理应用，具体请参考[MDM Kit开发指南](../../mdm/mdm-kit-guide.md)。
>
> 全局通用限制类策略由restrictions统一提供，若要全局禁用USB，请参考[@ohos.enterprise.restrictions（限制类策略）](js-apis-enterprise-restrictions.md)。

## 导入模块

```ts
import { usbManager } from '@kit.MDMKit';
```

## usbManager.addAllowedUsbDevices

addAllowedUsbDevices(admin: Want, usbDeviceIds: Array\<UsbDeviceId>): void

添加USB设备可用名单。

以下情况下，调用本接口会报策略冲突：

1. 已经通过[setDisallowedPolicy](js-apis-enterprise-restrictions.md#restrictionssetdisallowedpolicy)接口禁用了设备USB能力。
2. 已经通过[setUsbStorageDeviceAccessPolicy](#usbmanagersetusbstoragedeviceaccesspolicy)接口设置了USB存储设备访问策略为禁用。
3. 已经通过[addDisallowedUsbDevices](#usbmanageradddisallowedusbdevices14)接口添加了禁止使用的USB设备类型。

**需要权限：** ohos.permission.ENTERPRISE_MANAGE_USB

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**模型约束：** 此接口仅可在Stage模型下使用。


**参数：**

| 参数名       | 类型                                                    | 必填 | 说明                                                         |
| ------------ | ------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| admin        | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | 是   | 企业设备管理扩展组件。                                       |
| usbDeviceIds | Array<[UsbDeviceId](#usbdeviceid)>                      | 是   | USB设备ID数组，UsbDeviceId信息可以通过[getDevices](../apis-basic-services-kit/js-apis-usbManager.md#usbmanagergetdevices)接口获取。添加后的数组长度上限为1000。例如，若当前可用名单数组中已有300个USB设备ID，则最多支持通过该接口再添加700个。 |

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
import { usbManager } from '@kit.MDMKit';
import { Want } from '@kit.AbilityKit';

let wantTemp: Want = {
  // 需根据实际情况进行替换
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility'
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

移除USB设备可用名单。

**需要权限：** ohos.permission.ENTERPRISE_MANAGE_USB

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**模型约束：** 此接口仅可在Stage模型下使用。


**参数：**

| 参数名       | 类型                                                    | 必填 | 说明                                                         |
| ------------ | ------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| admin        | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | 是   | 企业设备管理扩展组件。                                       |
| usbDeviceIds | Array<[UsbDeviceId](#usbdeviceid)>                      | 是   | USB设备ID数组，UsbDeviceId信息可以通过[getDevices](../apis-basic-services-kit/js-apis-usbManager.md#usbmanagergetdevices)接口获取。 |

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
import { usbManager } from '@kit.MDMKit';
import { Want } from '@kit.AbilityKit';

let wantTemp: Want = {
  // 需根据实际情况进行替换
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility'
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

获取USB设备可用名单。

**需要权限：** ohos.permission.ENTERPRISE_MANAGE_USB

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**模型约束：** 此接口仅可在Stage模型下使用。


**参数：**

| 参数名 | 类型                                                    | 必填 | 说明                                   |
| ------ | ------------------------------------------------------- | ---- | -------------------------------------- |
| admin  | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | 是   | 企业设备管理扩展组件。 |

**返回值：**

| 类型                               | 说明                      |
| ---------------------------------- | ------------------------- |
| Array<[UsbDeviceId](#usbdeviceid)> | 可用USB允许名单设备ID数组。 |

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
import { usbManager } from '@kit.MDMKit';
import { Want } from '@kit.AbilityKit';

let wantTemp: Want = {
  // 需根据实际情况进行替换
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility'
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

设置USB存储设备访问策略。

以下情况下，通过本接口设置USB存储设备访问策略为可读可写/只读，会报策略冲突：

1. 已经通过[setDisallowedPolicy](js-apis-enterprise-restrictions.md#restrictionssetdisallowedpolicy)接口禁用了设备USB能力。
2. 已经通过[addDisallowedUsbDevices](#usbmanageradddisallowedusbdevices14)接口将存储类型的USB设备添加为禁止使用的USB设备类型。
3. 已经通过[setDisallowedPolicyForAccount](js-apis-enterprise-restrictions.md#restrictionssetdisallowedpolicyforaccount14)接口禁用了某用户USB存储设备写入能力。

以下情况下，通过本接口设置USB存储设备访问策略为禁用，会报策略冲突：

1. 已经通过[setDisallowedPolicy](js-apis-enterprise-restrictions.md#restrictionssetdisallowedpolicy)接口禁用了设备USB能力。
2. 已经通过[addAllowedUsbDevices](#usbmanageraddallowedusbdevices)接口添加了USB设备可用名单。
3. 已经通过[setDisallowedPolicyForAccount](js-apis-enterprise-restrictions.md#restrictionssetdisallowedpolicyforaccount14)接口禁用了某用户USB存储设备写入能力。

通过本接口设置，或者通过[addDisallowedUsbDevices](#usbmanageradddisallowedusbdevices14)接口添加存储类型的USB设备，均可禁用USB存储设备。推荐使用后者。

**需要权限：** ohos.permission.ENTERPRISE_MANAGE_USB

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**模型约束：** 此接口仅可在Stage模型下使用。


**参数：**

| 参数名    | 类型                                                    | 必填 | 说明                                   |
| --------- | ------------------------------------------------------- | ---- | -------------------------------------- |
| admin     | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | 是   | 企业设备管理扩展组件。 |
| usbPolicy | [UsbPolicy](#usbpolicy)                                 | 是   | USB存储设备访问策略。                  |

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
import { usbManager } from '@kit.MDMKit';
import { Want } from '@kit.AbilityKit';

let wantTemp: Want = {
  // 需根据实际情况进行替换
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility'
};
try {
  let policy: usbManager.UsbPolicy = usbManager.UsbPolicy.DISABLED;
  usbManager.setUsbStorageDeviceAccessPolicy(wantTemp, policy);
  console.info(`Succeeded in setting USB storage device access policy.`);
} catch (err) {
  console.error(`Failed to set USB storage device access policy. Code: ${err.code}, message: ${err.message}`);
}
```

## usbManager.getUsbStorageDeviceAccessPolicy

getUsbStorageDeviceAccessPolicy(admin: Want): UsbPolicy

获取USB存储设备访问策略。

**需要权限：** ohos.permission.ENTERPRISE_MANAGE_USB

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**模型约束：** 此接口仅可在Stage模型下使用。


**参数：**

| 参数名 | 类型                                                    | 必填 | 说明                                   |
| ------ | ------------------------------------------------------- | ---- | -------------------------------------- |
| admin  | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | 是   | 企业设备管理扩展组件。 |

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
import { usbManager } from '@kit.MDMKit';
import { Want } from '@kit.AbilityKit';

let wantTemp: Want = {
  // 需根据实际情况进行替换
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility'
};
try {
  let result: usbManager.UsbPolicy = usbManager.getUsbStorageDeviceAccessPolicy(wantTemp);
  console.info(`Succeeded in getting USB storage device access policy. Result: ${JSON.stringify(result)}`);
} catch (err) {
  console.error(`Failed to get USB storage device access policy. Code: ${err.code}, message: ${err.message}`);
}
```

## usbManager.addDisallowedUsbDevices<sup>14+</sup>

addDisallowedUsbDevices(admin: Want, usbDevices: Array\<UsbDeviceType>): void

添加禁止使用的USB设备类型。

以下情况下，调用本接口会报策略冲突：

1. 已经通过[setDisallowedPolicy](js-apis-enterprise-restrictions.md#restrictionssetdisallowedpolicy)接口禁用了设备USB能力。
2. 已经通过[addAllowedUsbDevices](#usbmanageraddallowedusbdevices)接口添加了USB设备可用名单。
3. 已经通过[setDisallowedPolicyForAccount](js-apis-enterprise-restrictions.md#restrictionssetdisallowedpolicyforaccount14)接口禁用了某用户USB存储设备写入能力。

**需要权限：** ohos.permission.ENTERPRISE_MANAGE_USB

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**模型约束：** 此接口仅可在Stage模型下使用。


**参数：**

| 参数名     | 类型                                                    | 必填 | 说明                                                         |
| ---------- | ------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| admin      | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | 是   | 企业设备管理扩展组件。                                       |
| usbDevices | Array<[UsbDeviceType](#usbdevicetype14)>                | 是   | 要添加的USB设备类型的数组，UsbDeviceType信息可以通过[getDevices](../apis-basic-services-kit/js-apis-usbManager.md#usbmanagergetdevices)接口获取。添加后的数组长度上限为200。例如，若当前禁用名单数组中已有100个USB设备ID，则最多支持通过该接口再添加100个。 |

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
import { usbManager } from '@kit.MDMKit';
import { Want } from '@kit.AbilityKit';

let wantTemp: Want = {
  // 需根据实际情况进行替换
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility'
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

移除禁止使用的USB设备类型。

**需要权限：** ohos.permission.ENTERPRISE_MANAGE_USB

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**模型约束：** 此接口仅可在Stage模型下使用。


**参数：**

| 参数名     | 类型                                                    | 必填 | 说明                                                         |
| ---------- | ------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| admin      | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | 是   | 企业设备管理扩展组件。                                       |
| usbDevices | Array<[UsbDeviceType](#usbdevicetype14)>                | 是   | 要移除的USB设备类型的数组，UsbDeviceType信息可以通过[getDevices](../apis-basic-services-kit/js-apis-usbManager.md#usbmanagergetdevices)接口获取。 |

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
import { usbManager } from '@kit.MDMKit';
import { Want } from '@kit.AbilityKit';

let wantTemp: Want = {
  // 需根据实际情况进行替换
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility'
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

获取禁止使用的USB设备类型。

**需要权限：** ohos.permission.ENTERPRISE_MANAGE_USB

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**模型约束：** 此接口仅可在Stage模型下使用。


**参数：**

| 参数名 | 类型                                                    | 必填 | 说明                                   |
| ------ | ------------------------------------------------------- | ---- | -------------------------------------- |
| admin  | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | 是   | 企业设备管理扩展组件。 |

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
import { usbManager } from '@kit.MDMKit';
import { Want } from '@kit.AbilityKit';

let wantTemp: Want = {
  // 需根据实际情况进行替换
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility'
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

| 名称      | 类型   | 只读 | 可选 | 说明     |
| --------- | ------ | ---- | ---- | -------- |
| vendorId  | number | 否   | 否 | 厂商ID。 |
| productId | number | 否   | 否 | 产品ID。 |

## UsbDeviceType<sup>14+</sup>

USB设备类型信息。其中具体编号可查询：[defined-class-codes](https://www.usb.org/defined-class-codes)。

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

| 名称       | 类型                        | 只读 | 可选 | 说明                                                         |
| ---------- | --------------------------- | ---- | ---- | ------------------------------------------------------------ |
| baseClass  | number                      | 否   | 否 | 类型编号，可通过[getDevices](../apis-basic-services-kit/js-apis-usbManager.md#usbmanagergetdevices)接口获取。若descriptor为DEVICE，则取返回值中的USBDevice.clazz字段，若descriptor为INTERFACE，则取返回值中的USBDevice.configs.interfaces.clazz字段。 |
| subClass   | number                      | 否   | 否 | 子类型编号，可通过[getDevices](../apis-basic-services-kit/js-apis-usbManager.md#usbmanagergetdevices)接口获取。若descriptor为DEVICE，则取返回值中的USBDevice.subClass字段，若descriptor为INTERFACE，则取返回值中的USBDevice.configs.interfaces.subClass字段。 |
| protocol   | number                      | 否   | 否 | 协议编号，可通过[getDevices](../apis-basic-services-kit/js-apis-usbManager.md#usbmanagergetdevices)接口获取。若descriptor为DEVICE，则取返回值中的USBDevice.protocol字段，若descriptor为INTERFACE，则取返回值中的USBDevice.configs.interfaces.protocol字段。 |
| descriptor | [Descriptor](#descriptor14) | 否   | 否 | USB描述符。须按照[defined-class-codes](https://www.usb.org/defined-class-codes)，取baseClass对应的Descriptor Usage值作为参数传入，若Descriptor Usage为Both，则设备级禁用时传入DEVICE、接口级禁用时传入INTERFACE。 |

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
