# @ohos.enterprise.restrictions (限制类策略)

本模块提供设置通用限制类策略能力，包括禁用或启用设备打印、HDC等能力。

> **说明**：
> 
> 本模块首批接口从API version 10 开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>
> 本模块接口仅可在Stage模型下使用。
>
> 本模块接口仅对[设备管理应用](enterpriseDeviceManagement-overview.md#基本概念)开放，需将[设备管理应用激活](js-apis-enterprise-adminManager.md#adminmanagerenableadmin)后调用，实现相应功能。

## 导入模块

```ts
import restrictions from '@ohos.enterprise.restrictions';
```

## restrictions.setPrinterDisabled

setPrinterDisabled(admin: Want, disabled: boolean, callback: AsyncCallback\<void>): void

指定设备管理应用使设备禁用或启用打印能力。使用callback异步回调。 

**需要权限：** ohos.permission.ENTERPRISE_RESTRICT_POLICY

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**系统API**: 此接口为系统接口。

**参数：**

| 参数名   | 类型                                  | 必填   | 说明      |
| ----- | ----------------------------------- | ---- | ------- |
| admin | [Want](js-apis-app-ability-want.md) | 是    | 设备管理应用。 |
| disabled  | boolean | 是 | true表示禁止使用打印能力，false表示允许使用打印能力。 |
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

restrictions.setPrinterDisabled(wantTemp, true, (err) => {
  if (err) {
    console.error(`Failed to set printer disabled. Code is ${err.code}, message is ${err.message}`);
    return;
  }
  console.info('Succeeded in setting printer disabled');
})
```

## restrictions.setPrinterDisabled

setPrinterDisabled(admin: Want, disabled: boolean): Promise\<void>

指定设备管理应用使设备禁用或启用打印能力。使用Promise异步回调。

**需要权限：** ohos.permission.ENTERPRISE_RESTRICT_POLICY

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**系统API**: 此接口为系统接口。

**参数：**

| 参数名   | 类型                                  | 必填   | 说明      |
| ----- | ----------------------------------- | ---- | ------- |
| admin | [Want](js-apis-app-ability-want.md) | 是    | 设备管理应用。 |
| disabled  | boolean | 是 | true表示禁止使用打印能力，false表示允许使用打印能力。 |

**返回值：**

| 类型   | 说明                                  |
| ----- | ----------------------------------- |
| Promise\<void> | 无返回结果的Promise对象。当指定设备管理应用禁止或允许使用打印能力失败时抛出错误对象。 |

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

restrictions.setPrinterDisabled(wantTemp, true).then(() => {
  console.info('Succeeded in setting printer disabled');
}).catch((err: BusinessError) => {
  console.error(`Failed to set printer disabled. Code is ${err.code}, message is ${err.message}`);
})
```

## restrictions.isPrinterDisabled

isPrinterDisabled(admin: Want, callback: AsyncCallback\<boolean>): void

指定设备管理应用查询设备打印能力是否被禁用。使用callback异步回调。

**需要权限：** ohos.permission.ENTERPRISE_RESTRICT_POLICY

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**系统API**: 此接口为系统接口。

**参数：**

| 参数名   | 类型                                  | 必填   | 说明      |
| ----- | ----------------------------------- | ---- | ------- |
| admin | [Want](js-apis-app-ability-want.md) | 是    | 设备管理应用。 |
| callback | AsyncCallback\<boolean> | 是 | 回调函数，callback方式返回设备打印能力是否被禁用，true表示设备打印能力被禁用，false表示设备打印能力未被禁用。 |

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

restrictions.isPrinterDisabled(wantTemp, (err, result) => {
  if (err) {
    console.error(`Failed to query is the printing function disabled or not. Code is ${err.code}, message is ${err.message}`);
    return;
  }
  console.info(`Succeeded in querying is the printing function disabled : ${result}`);
})
```

## restrictions.isPrinterDisabled

isPrinterDisabled(admin: Want): Promise\<boolean>

指定设备管理应用查询设备打印能力是否被禁用。使用Promise异步回调。

**需要权限：** ohos.permission.ENTERPRISE_RESTRICT_POLICY

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**系统API**: 此接口为系统接口。

**参数：**

| 参数名   | 类型                                  | 必填   | 说明      |
| ----- | ----------------------------------- | ---- | ------- |
| admin | [Want](js-apis-app-ability-want.md) | 是    | 设备管理应用。 |

**返回值：**

| 类型   | 说明                                  |
| ----- | ----------------------------------- |
| Promise\<boolean> | Promise对象。promise方式返回设备打印能力是否被禁用，true表示设备打印能力被禁用，false表示设备打印能力未被禁用。 |

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

restrictions.isPrinterDisabled(wantTemp).then((result) => {
  console.info(`Succeeded in querying is the printing function disabled : ${result}`);
}).catch((err: BusinessError) => {
  console.error(`Failed to query is the printing function disabled or not. Code is ${err.code}, message is ${err.message}`);
})
```

## restrictions.setHdcDisabled

setHdcDisabled(admin: Want, disabled: boolean, callback: AsyncCallback\<void>): void

指定设备管理应用使设备禁用或启用HDC。使用callback异步回调。 

**需要权限：** ohos.permission.ENTERPRISE_RESTRICT_POLICY

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**系统API**: 此接口为系统接口。

**参数：**

| 参数名   | 类型                                  | 必填   | 说明      |
| ----- | ----------------------------------- | ---- | ------- |
| admin | [Want](js-apis-app-ability-want.md) | 是    | 设备管理应用。 |
| disabled  | boolean | 是 | true表示禁止使用HDC，false表示允许使用HDC。 |
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

restrictions.setHdcDisabled(wantTemp, true, (err) => {
  if (err) {
    console.error(`Failed to set hdc disabled. Code is ${err.code}, message is ${err.message}`);
    return;
  }
  console.info('Succeeded in setting hdc disabled');
})
```

## restrictions.setHdcDisabled

setHdcDisabled(admin: Want, disabled: boolean): Promise\<void>

指定设备管理应用使设备禁用或启用HDC。使用Promise异步回调。

**需要权限：** ohos.permission.ENTERPRISE_RESTRICT_POLICY

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**系统API**: 此接口为系统接口。

**参数：**

| 参数名   | 类型                                  | 必填   | 说明      |
| ----- | ----------------------------------- | ---- | ------- |
| admin | [Want](js-apis-app-ability-want.md) | 是    | 设备管理应用。 |
| disabled  | boolean | 是 | true表示禁止使用HDC，false表示允许使用HDC。 |

**返回值：**

| 类型   | 说明                                  |
| ----- | ----------------------------------- |
| Promise\<void> | 无返回结果的Promise对象。当指定设备管理应用禁止或允许使用HDC失败时，抛出错误对象。 |

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

restrictions.setHdcDisabled(wantTemp, true).then(() => {
  console.info('Succeeded in setting hdc disabled');
}).catch((err: BusinessError) => {
  console.error(`Failed to set hdc disabled. Code is ${err.code}, message is ${err.message}`);
})
```

## restrictions.isHdcDisabled

isHdcDisabled(admin: Want, callback: AsyncCallback\<boolean>): void

指定设备管理应用查询HDC是否被禁用。使用callback异步回调。

**需要权限：** ohos.permission.ENTERPRISE_RESTRICT_POLICY

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**系统API**: 此接口为系统接口。

**参数：**

| 参数名   | 类型                                  | 必填   | 说明      |
| ----- | ----------------------------------- | ---- | ------- |
| admin | [Want](js-apis-app-ability-want.md) | 是    | 设备管理应用。 |
| callback | AsyncCallback\<boolean> | 是 | 回调函数，callbac方式返回HDC是否被禁用，true表示HDC被禁用，false表示HDC未被禁用。 |

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

restrictions.isHdcDisabled(wantTemp, (err, result) => {
  if (err) {
    console.error(`Failed to query is hdc disabled or not. Code is ${err.code}, message is ${err.message}`);
    return;
  }
  console.info(`Succeeded in querying is hdc disabled : ${result}`);
})
```

## restrictions.isHdcDisabled

isHdcDisabled(admin: Want): Promise\<boolean>

指定设备管理应用查询HDC是否被禁用。使用Promise异步回调。

**需要权限：** ohos.permission.ENTERPRISE_RESTRICT_POLICY

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**系统API**: 此接口为系统接口。

**参数：**

| 参数名   | 类型                                  | 必填   | 说明      |
| ----- | ----------------------------------- | ---- | ------- |
| admin | [Want](js-apis-app-ability-want.md) | 是    | 设备管理应用。 |

**返回值：**

| 类型   | 说明                                  |
| ----- | ----------------------------------- |
| Promise\<boolean> | Promise对象。promise方式返回HDC是否被禁用，true表示HDC被禁用，false表示HDC未被禁用。 |

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

restrictions.isHdcDisabled(wantTemp).then((result) => {
  console.info(`Succeeded in querying is hdc disabled : ${result}`);
}).catch((err: BusinessError) => {
  console.error(`Failed to query is hdc disabled or not. Code is ${err.code}, message is ${err.message}`);
})
```

## restrictions.isMicrophoneDisallowed<sup>11+</sup>

isMicrophoneDisallowed(admin: Want): boolean

指定设备管理应用查询麦克风是否被禁用。

**需要权限：** ohos.permission.ENTERPRISE_MANAGE_RESTRICTIONS

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**系统API**: 此接口为系统接口。

**参数：**

| 参数名   | 类型                                  | 必填   | 说明      |
| ----- | ----------------------------------- | ---- | ------- |
| admin | [Want](js-apis-app-ability-want.md) | 是    | 设备管理应用。 |

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

try {
  let result = restrictions.isMicrophoneDisallowed(wantTemp);
} catch (err) {
  console.error(`Failed to isMicrophoneDisallowed. Code is ${err.code}, message is ${err.message}`);
}
```

## restrictions.disallowMicrophone<sup>11+</sup>

disallowMicrophone(admin: Want, isDisallowed: boolean): void

指定设备管理应用使设备禁用或启用HDC。使用Promise异步回调。

**需要权限：** ohos.permission.ENTERPRISE_MANAGE_RESTRICTIONS

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**系统API**: 此接口为系统接口。

**参数：**

| 参数名   | 类型                                  | 必填   | 说明      |
| ----- | ----------------------------------- | ---- | ------- |
| admin | [Want](js-apis-app-ability-want.md) | 是    | 设备管理应用。 |
| isDisallowed  | boolean | 是 | true表示禁止使用HDC，false表示允许使用HDC。 |

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

try {
  restrictions.disallowMicrophone(wantTemp, true);
} catch (err) {
  console.error(`Failed to lock screen. Code is ${err.code}, message is ${err.message}`);
}
```
