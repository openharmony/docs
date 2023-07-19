# @ohos.enterprise.dateTimeManager (系统时间管理)

本模块提供系统时间管理能力。

> **说明**：
> 
> 本模块首批接口从API version 9 开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>
> 本模块接口仅可在Stage模型下使用。
>
> 本模块接口仅对[设备管理应用](enterpriseDeviceManagement-overview.md#基本概念)开放，需将[设备管理应用激活](js-apis-enterprise-adminManager.md#adminmanagerenableadmin)后调用，实现相应功能。

## 导入模块

```js
import dateTimeManager from '@ohos.enterprise.dateTimeManager'
```

## dateTimeManager.setDateTime

setDateTime(admin: Want, time: number, callback: AsyncCallback\<void>): void

指定设备管理应用设置系统时间。使用callback异步回调。 

**需要权限：** ohos.permission.ENTERPRISE_SET_DATETIME

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**系统API**: 此接口为系统接口。

**参数：**

| 参数名   | 类型                                  | 必填   | 说明      |
| ----- | ----------------------------------- | ---- | ------- |
| admin | [Want](js-apis-app-ability-want.md) | 是    | 设备管理应用。 |
| time  | number | 是 | 时间戳(ms)。 |
| callback | AsyncCallback\<void> | 是 | 回调函数。当接口调用成功，err为null，否则为错误对象。 |

**错误码**：

以下错误码的详细介绍请参见[企业设备管理错误码](../errorcodes/errorcode-enterpriseDeviceManager.md)

| 错误码ID | 错误信息                                                                      |
| ------- | ---------------------------------------------------------------------------- |
| 9200001 | the application is not an administrator of the device.                       |
| 9200002 | the administrator application does not have permission to manage the device. |

**示例：**

```js
let wantTemp = {
  bundleName: 'bundleName',
  abilityName: 'abilityName',
};

dateTimeManager.setDateTime(wantTemp, 1526003846000, (err) => {
  if (err) {
    console.error(`Failed to set date time. Code is ${err.code}, message is ${err.message}`);
    return;
  }
  console.info('Succeeded in setting date time');
})
```

## dateTimeManager.setDateTime

setDateTime(admin: Want, time: number): Promise\<void>

指定设备管理应用设置系统时间。使用Promise异步回调。

**需要权限：** ohos.permission.ENTERPRISE_SET_DATETIME

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**系统API**: 此接口为系统接口。

**参数：**

| 参数名   | 类型                                  | 必填   | 说明      |
| ----- | ----------------------------------- | ---- | ------- |
| admin | [Want](js-apis-app-ability-want.md) | 是    | 设备管理应用。 |
| time  | number | 是 | 时间戳(ms)。 |

**返回值：**

| 类型   | 说明                                  |
| ----- | ----------------------------------- |
| Promise\<void> | Promise对象。无返回结果的Promise对象。 |

**错误码**：

以下错误码的详细介绍请参见[企业设备管理错误码](../errorcodes/errorcode-enterpriseDeviceManager.md)

| 错误码ID | 错误信息                                                                      |
| ------- | ---------------------------------------------------------------------------- |
| 9200001 | the application is not an administrator of the device.                        |
| 9200002 | the administrator application does not have permission to manage the device. |

**示例：**

```js
let wantTemp = {
  bundleName: 'bundleName',
  abilityName: 'abilityName',
};

dateTimeManager.setDateTime(wantTemp, 1526003846000).then(() => {
  console.info('Succeeded in setting date time');
}).catch((err) => {
  console.error(`Failed to set date time. Code is ${err.code}, message is ${err.message}`);
})
```

## dateTimeManager.disallowModifyDateTime<sup>10+</sup>

disallowModifyDateTime(admin: Want, disallow: boolean, callback: AsyncCallback\<void>): void

指定设备管理应用禁止设备修改系统时间。使用callback异步回调。

**需要权限：** ohos.permission.ENTERPRISE_SET_DATETIME

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**系统API**: 此接口为系统接口。

**参数：**

| 参数名   | 类型                                  | 必填   | 说明      |
| ----- | ----------------------------------- | ---- | ------- |
| admin | [Want](js-apis-app-ability-want.md) | 是    | 设备管理应用。 |
| disallow  | boolean | 是 | true 表示禁止修改系统时间，false表示允许修改系统时间。 |
| callback | AsyncCallback\<void> | 是 | 回调函数。当接口调用成功，err为null，否则为错误对象。 |

**错误码**：

以下错误码的详细介绍请参见[企业设备管理错误码](../errorcodes/errorcode-enterpriseDeviceManager.md)

| 错误码ID | 错误信息                                                                      |
| ------- | ---------------------------------------------------------------------------- |
| 9200001 | the application is not an administrator of the device.                       |
| 9200002 | the administrator application does not have permission to manage the device. |

**示例：**

```js
let wantTemp = {
  bundleName: 'bundleName',
  abilityName: 'abilityName',
};

dateTimeManager.disallowModifyDateTime(wantTemp, true, (err) => {
  if (err) {
    console.error(`Failed to disallow modify date time. Code is ${err.code}, message is ${err.message}`);
    return;
  }
  console.info('Succeeded in disallowing modify date time');
})
```

## dateTimeManager.disallowModifyDateTime<sup>10+</sup>

disallowModifyDateTime(admin: Want, disallow: boolean): Promise\<void>

指定设备管理应用禁止设备修改系统时间。使用Promise异步回调。

**需要权限：** ohos.permission.ENTERPRISE_SET_DATETIME

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**系统API**: 此接口为系统接口。

**参数：**

| 参数名   | 类型                                  | 必填   | 说明      |
| ----- | ----------------------------------- | ---- | ------- |
| admin | [Want](js-apis-app-ability-want.md) | 是    | 设备管理应用。 |
| disallow  | boolean | 是 | true 表示禁止修改系统时间，false表示允许修改系统时间。 |

**返回值：**

| 类型   | 说明                                  |
| ----- | ----------------------------------- |
| Promise\<void> | 无返回结果的Promise对象。当指定设备管理应用禁止设备修改系统时间失败时，抛出错误对象。 |

**错误码**：

以下错误码的详细介绍请参见[企业设备管理错误码](../errorcodes/errorcode-enterpriseDeviceManager.md)

| 错误码ID | 错误信息                                                                      |
| ------- | ---------------------------------------------------------------------------- |
| 9200001 | the application is not an administrator of the device.                        |
| 9200002 | the administrator application does not have permission to manage the device. |

**示例：**

```js
let wantTemp = {
  bundleName: 'bundleName',
  abilityName: 'abilityName',
};

dateTimeManager.disallowModifyDateTime(wantTemp, true).then(() => {
  console.info('Succeeded in disallowing modify date time');
}).catch((err) => {
  console.error(`Failed to disallow modify date time. Code is ${err.code}, message is ${err.message}`);
})
```

## dateTimeManager.isModifyDateTimeDisallowed<sup>10+</sup>

isModifyDateTimeDisallowed(admin: Want, callback: AsyncCallback\<boolean>): void

指定设备管理应用查询设备是否允许修改系统时间。使用callback异步回调。

**需要权限：** ohos.permission.ENTERPRISE_SET_DATETIME

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**系统API**: 此接口为系统接口。

**参数：**

| 参数名   | 类型                                  | 必填   | 说明      |
| ----- | ----------------------------------- | ---- | ------- |
| admin | [Want](js-apis-app-ability-want.md) | 是    | 设备管理应用。 |
| callback | AsyncCallback\<boolean> | 是 | 回调函数，callbac方式返回是否禁止修改系统时间策略，true表示禁止修改系统时间，否则表示允许修改系统时间。 |

**错误码**：

以下错误码的详细介绍请参见[企业设备管理错误码](../errorcodes/errorcode-enterpriseDeviceManager.md)

| 错误码ID | 错误信息                                                                      |
| ------- | ---------------------------------------------------------------------------- |
| 9200001 | the application is not an administrator of the device.                       |
| 9200002 | the administrator application does not have permission to manage the device. |

**示例：**

```js
let wantTemp = {
  bundleName: 'bundleName',
  abilityName: 'abilityName',
};

dateTimeManager.isModifyDateTimeDisallowed(wantTemp, (err, result) => {
  if (err) {
    console.error(`Failed to query modify date time is disallowed or not. Code is ${err.code}, message is ${err.message}`);
    return;
  }
  console.info(`Succeeded in querying modify date time is disallowed : ${result}`);
})
```

## dateTimeManager.isModifyDateTimeDisallowed<sup>10+</sup>

isModifyDateTimeDisallowed(admin: Want): Promise\<boolean>

指定设备管理应用查询设备是否允许修改系统时间。使用Promise异步回调。

**需要权限：** ohos.permission.ENTERPRISE_SET_DATETIME

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager

**系统API**: 此接口为系统接口。

**参数：**

| 参数名   | 类型                                  | 必填   | 说明      |
| ----- | ----------------------------------- | ---- | ------- |
| admin | [Want](js-apis-app-ability-want.md) | 是    | 设备管理应用。 |

**返回值：**

| 类型   | 说明                                  |
| ----- | ----------------------------------- |
| Promise\<boolean> | Promise对象。promise方式返回是否禁止修改系统时间策略，true表示禁止修改系统时间，否则表示允许修改系统时间。 |

**错误码**：

以下错误码的详细介绍请参见[企业设备管理错误码](../errorcodes/errorcode-enterpriseDeviceManager.md)

| 错误码ID | 错误信息                                                                      |
| ------- | ---------------------------------------------------------------------------- |
| 9200001 | the application is not an administrator of the device.                        |
| 9200002 | the administrator application does not have permission to manage the device. |

**示例：**

```js
let wantTemp = {
  bundleName: 'bundleName',
  abilityName: 'abilityName',
};

dateTimeManager.isModifyDateTimeDisallowed(wantTemp).then((result) => {
  console.info(`Succeeded in querying modify date time is disallowed : ${result}`);
}).catch((err) => {
  console.error(`Failed to query modify date time is disallowed or not. Code is ${err.code}, message is ${err.message}`);
})
```