# @ohos.enterprise.adminManager（企业设备管理）(系统接口)

本模块提供企业设备管理能力，使设备具备企业场景下所需的定制能力。

> **说明：**
>
> 本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>
> 本模块接口仅对[设备管理应用](../../mdm/mdm-kit-guide.md#功能介绍)开放。
> 
> 当前页面仅包含本模块的系统接口，其他公开接口参见。其他公开接口参见[@ohos.enterprise.adminManager](js-apis-enterprise-adminManager.md)。

## 导入模块

```ts
import { adminManager } from '@kit.MDMKit';
```

## adminManager.enableAdmin

enableAdmin(admin: Want, enterpriseInfo: EnterpriseInfo, type: AdminType, callback: AsyncCallback\<void>): void

激活当前用户下指定的设备管理应用，其中超级设备管理应用仅能在管理员用户下被激活。使用callback异步回调。

**需要权限：** ohos.permission.MANAGE_ENTERPRISE_DEVICE_ADMIN

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager



**模型约束**: 此接口仅可在Stage模型下使用。

**参数**：

| 参数名            | 类型                                  | 必填   | 说明                 |
| -------------- | ----------------------------------- | ---- | ------------------ |
| admin          | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | 是    | 企业设备管理扩展组件。      |
| enterpriseInfo | [EnterpriseInfo](#enterpriseinfo)   | 是    | 设备管理应用的企业信息。      |
| type           | [AdminType](#admintype)             | 是    | 激活的设备管理应用类型。         |
| callback       | AsyncCallback\<void>                | 是    | 回调函数，当接口调用成功，err为null，否则为错误对象。 |

**错误码**：

以下错误码的详细介绍请参见[企业设备管理错误码](errorcode-enterpriseDeviceManager.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                         |
| ------- | --------------------------------------------------------------- |
| 9200003 | The administrator ability component is invalid.                 |
| 9200004 | Failed to activate the administrator application of the device.   |
| 9200007 | The system ability works abnormally. |
| 201 | Permission verification failed. The application does not have the permission required to call the API. |
| 202 | Permission verification failed. A non-system application calls a system API. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**示例**：

```ts
import { Want } from '@kit.AbilityKit';
let wantTemp: Want = {
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility',
};
let enterpriseInfo: adminManager.EnterpriseInfo = {
  name: 'enterprise name',
  description: 'enterprise description'
}

adminManager.enableAdmin(wantTemp, enterpriseInfo, adminManager.AdminType.ADMIN_TYPE_SUPER, (err) => {
  if (err) {
    console.error(`Failed to enable admin. Code: ${err.code}, message: ${err.message}`);
    return;
  }
  console.info('Succeeded in enabling admin');
});
```

## adminManager.enableAdmin

enableAdmin(admin: Want, enterpriseInfo: EnterpriseInfo, type: AdminType, userId: number, callback: AsyncCallback\<void>): void

激活指定用户（通过userId指定）下指定的设备管理应用，其中超级管理应用仅能在管理员用户下被激活。使用callback异步回调。

**需要权限：** ohos.permission.MANAGE_ENTERPRISE_DEVICE_ADMIN

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager



**模型约束**: 此接口仅可在Stage模型下使用。

**参数**：

| 参数名            | 类型                                  | 必填   | 说明                           |
| -------------- | ----------------------------------- | ---- | ---------------------------- |
| admin          | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | 是    | 企业设备管理扩展组件。                |
| enterpriseInfo | [EnterpriseInfo](#enterpriseinfo)   | 是    | 设备管理应用的企业信息。                 |
| type           | [AdminType](#admintype)             | 是    | 激活的设备管理应用类型。                  |
| userId         | number                              | 是    | 用户ID，指定具体用户，取值范围：大于等于0。<br>默认值：调用方所在用户。 |
| callback       | AsyncCallback\<void>                | 是    | 回调函数，当接口调用成功，err为null，否则为错误对象。       |

**错误码**:

以下错误码的详细介绍请参见[企业设备管理错误码](errorcode-enterpriseDeviceManager.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                         |
| ------- | --------------------------------------------------------------- |
| 9200003 | The administrator ability component is invalid.                 |
| 9200004 | Failed to activate the administrator application of the device.   |
| 9200007 | The system ability works abnormally. |
| 201 | Permission verification failed. The application does not have the permission required to call the API. |
| 202 | Permission verification failed. A non-system application calls a system API. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**示例**：

```ts
import { Want } from '@kit.AbilityKit';
let wantTemp: Want = {
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility',
};
let enterpriseInfo: adminManager.EnterpriseInfo = {
  name: 'enterprise name',
  description: 'enterprise description'
}

adminManager.enableAdmin(wantTemp, enterpriseInfo, adminManager.AdminType.ADMIN_TYPE_NORMAL, 100, (err) => {
  if (err) {
    console.error(`Failed to enable admin. Code: ${err.code}, message: ${err.message}`);
    return;
  }
  console.info('Succeeded in enabling admin');
});
```

## adminManager.enableAdmin

enableAdmin(admin: Want, enterpriseInfo: EnterpriseInfo, type: AdminType, userId?: number): Promise\<void>

激活当前/指定用户下指定的设备管理应用，其中超级管理应用仅能在管理员用户下被激活。使用promise异步回调。

**需要权限：** ohos.permission.MANAGE_ENTERPRISE_DEVICE_ADMIN

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager



**模型约束**: 此接口仅可在Stage模型下使用。

**参数**：

| 参数名            | 类型                                  | 必填   | 说明                           |
| -------------- | ----------------------------------- | ---- | ---------------------------- |
| admin          | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | 是    | 企业设备管理扩展组件。                |
| enterpriseInfo | [EnterpriseInfo](#enterpriseinfo)   | 是    | 设备管理应用的企业信息。                 |
| type           | [AdminType](#admintype)             | 是    | 激活的设备管理应用类型。                   |
| userId         | number                              | 否    | 用户ID，取值范围：大于等于0。<br> - 调用接口时，若传入userId，表示指定用户。<br> - 调用接口时，若未传入userId，表示当前用户。|

**返回值：**

| 类型                | 说明                |
| ----------------- | ----------------- |
| Promise\<void>    | 无返回结果的Promise对象。当激活设备管理应用失败时，会抛出错误对象。 |

**错误码**：

以下错误码的详细介绍请参见[企业设备管理错误码](errorcode-enterpriseDeviceManager.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                         |
| ------- | --------------------------------------------------------------- |
| 9200003 | The administrator ability component is invalid.                 |
| 9200004 | Failed to activate the administrator application of the device.   |
| 9200007 | The system ability works abnormally. |
| 201 | Permission verification failed. The application does not have the permission required to call the API. |
| 202 | Permission verification failed. A non-system application calls a system API. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**示例**：

```ts
import { Want } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
let wantTemp: Want = {
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility',
};
let enterpriseInfo: adminManager.EnterpriseInfo = {
  name: 'enterprise name',
  description: 'enterprise description'
}

adminManager.enableAdmin(wantTemp, enterpriseInfo, adminManager.AdminType.ADMIN_TYPE_NORMAL, 100).catch(
  (err: BusinessError) => {
    console.error(`Failed to enable admin. Code: ${err.code}, message: ${err.message}`);
  });
```

## adminManager.disableAdmin

disableAdmin(admin: Want, callback: AsyncCallback\<void>): void

将当前用户下指定的普通设备管理应用解除激活。使用callback异步回调。

**需要权限：** ohos.permission.MANAGE_ENTERPRISE_DEVICE_ADMIN

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager



**模型约束**: 此接口仅可在Stage模型下使用。

**参数**：

| 参数名      | 类型                                  | 必填   | 说明                  |
| -------- | ----------------------------------- | ---- | ------------------- |
| admin    | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | 是    | 企业设备管理扩展组件。 |
| callback | AsyncCallback\<void>                | 是    | 回调函数，当接口调用成功，err为null，否则为错误对象。 |

**错误码**:

以下的错误码的详细介绍请参见[企业设备管理错误码](errorcode-enterpriseDeviceManager.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                           |
| ------- | ----------------------------------------------------------------- |
| 9200005 | Failed to deactivate the administrator application of the device.    |
| 201 | Permission verification failed. The application does not have the permission required to call the API. |
| 202 | Permission verification failed. A non-system application calls a system API. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**示例**：

```ts
import { Want } from '@kit.AbilityKit';
let wantTemp: Want = {
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility',
};

adminManager.disableAdmin(wantTemp, (err) => {
  if (err) {
    console.error(`Failed to disable admin. Code: ${err.code}, message: ${err.message}`);
    return;
  }
  console.info('Succeeded in disabling admin');
});
```

## adminManager.disableAdmin

disableAdmin(admin: Want, userId: number, callback: AsyncCallback\<void>): void

将指定用户（通过userId指定）下指定的普通管理应用解除激活。使用callback异步回调。

**需要权限：** ohos.permission.MANAGE_ENTERPRISE_DEVICE_ADMIN

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager



**模型约束**: 此接口仅可在Stage模型下使用。

**参数**：

| 参数名      | 类型                                  | 必填   | 说明                           |
| -------- | ----------------------------------- | ---- | ---------------------------- |
| admin    | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | 是    | 企业设备管理扩展组件。              |
| userId   | number                              | 是    | 用户ID，指定具体用户，取值范围：大于等于0。<br>默认值：当前用户。 |
| callback | AsyncCallback\<void>                | 是    | 回调函数，当接口调用成功，err为null，否则为错误对象。        |

**错误码**:

以下错误码的详细介绍请参见[企业设备管理错误码](errorcode-enterpriseDeviceManager.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                           |
| ------- | ----------------------------------------------------------------- |
| 9200005 | Failed to deactivate the administrator application of the device.    |
| 201 | Permission verification failed. The application does not have the permission required to call the API. |
| 202 | Permission verification failed. A non-system application calls a system API. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**示例**：

```ts
import { Want } from '@kit.AbilityKit';
let wantTemp: Want = {
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility',
};

adminManager.disableAdmin(wantTemp, 100, (err) => {
  if (err) {
    console.error(`Failed to disable admin. Code: ${err.code}, message: ${err.message}`);
    return;
  }
  console.info('Succeeded in disabling admin');
});
```

## adminManager.disableSuperAdmin

disableSuperAdmin(bundleName: String, callback: AsyncCallback\<void>): void

根据bundleName将超级设备管理应用解除激活。使用callback异步回调。

**需要权限：** ohos.permission.MANAGE_ENTERPRISE_DEVICE_ADMIN

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager



**模型约束**: 此接口仅可在Stage模型下使用。

**参数**：

| 参数名        | 类型                      | 必填   | 说明                  |
| ---------- | ----------------------- | ---- | ------------------- |
| bundleName | String                  | 是    | 超级设备管理应用的包名。        |
| callback   | AsyncCallback\<void>    | 是    | 回调函数，当接口调用成功，err为null，否则为错误对象。 |

**错误码**:

以下的错误码的详细介绍请参见[企业设备管理错误码](errorcode-enterpriseDeviceManager.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                           |
| ------- | ----------------------------------------------------------------- |
| 9200005 | Failed to deactivate the administrator application of the device.    |
| 201 | Permission verification failed. The application does not have the permission required to call the API. |
| 202 | Permission verification failed. A non-system application calls a system API. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**示例**：

```ts
import { Want } from '@kit.AbilityKit';
let bundleName: string = 'com.example.myapplication';

adminManager.disableSuperAdmin(bundleName, (err) => {
  if (err) {
    console.error(`Failed to disable super admin. Code: ${err.code}, message: ${err.message}`);
    return;
  }
  console.info('Succeeded in disabling super admin');
});
```

## adminManager.disableSuperAdmin

disableSuperAdmin(bundleName: String): Promise\<void>

根据bundleName将超级设备管理应用解除激活。使用promise异步回调。

**需要权限：** ohos.permission.MANAGE_ENTERPRISE_DEVICE_ADMIN

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager



**模型约束**: 此接口仅可在Stage模型下使用。

**参数**：

| 参数名        | 类型     | 必填   | 说明           |
| ---------- | ------ | ---- | ------------ |
| bundleName | String | 是    | 超级设备管理应用的包名。 |

**返回值：**

| 类型                | 说明                |
| ----------------- | ----------------- |
| Promise\<void>    | 无返回结果的Promise对象。当解除激活超级设备管理应用失败时，会抛出错误对象。 |

**错误码**:

以下错误码的详细介绍请参见[企业设备管理错误码](errorcode-enterpriseDeviceManager.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                           |
| ------- | ----------------------------------------------------------------- |
| 9200005 | Failed to deactivate the administrator application of the device.    |
| 201 | Permission verification failed. The application does not have the permission required to call the API. |
| 202 | Permission verification failed. A non-system application calls a system API. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**示例**：

```ts
import { Want } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
let bundleName: string = 'com.example.myapplication';

adminManager.disableSuperAdmin(bundleName).catch((err: BusinessError) => {
  console.error(`Failed to disable super admin. Code: ${err.code}, message: ${err.message}`);
});
```

## adminManager.isAdminEnabled

isAdminEnabled(admin: Want, callback: AsyncCallback\<boolean>): void

查询当前用户下指定的设备管理应用是否被激活。使用callback异步回调。

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager



**模型约束**: 此接口仅可在Stage模型下使用。

**参数**：

| 参数名      | 类型                                  | 必填   | 说明                   |
| -------- | ----------------------------------- | ---- | -------------------- |
| admin    | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | 是    | 企业设备管理扩展组件。       |
| callback | AsyncCallback\<boolean>             | 是    | 回调函数，当接口调用成功，err为null，data为boolean值，true表示当前用户下指定的设备管理应用被激活，false表示当前用户下指定的设备管理应用未激活，否则err为错误对象。 |

**错误码**:

以下错误码的详细介绍请参见[企业设备管理错误码](errorcode-enterpriseDeviceManager.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 202      | Permission verification failed. A non-system application calls a system API. |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |

**示例**：

```ts
import { Want } from '@kit.AbilityKit';
let wantTemp: Want = {
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility',
};

adminManager.isAdminEnabled(wantTemp, (err, result) => {
  if (err) {
    console.error(`Failed to query admin is enabled or not. Code: ${err.code}, message: ${err.message}`);
    return;
  }
  console.info(`Succeeded in querying admin is enabled or not, result : ${result}`);
});
```

## adminManager.isAdminEnabled

isAdminEnabled(admin: Want, userId: number, callback: AsyncCallback\<boolean>): void

查询指定用户（通过userId指定）下指定的设备管理应用是否被激活。使用callback异步回调。

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager



**模型约束**: 此接口仅可在Stage模型下使用。

**参数**：

| 参数名      | 类型                                  | 必填   | 说明                           |
| -------- | ----------------------------------- | ---- | ---------------------------- |
| admin    | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | 是    | 企业设备管理扩展组件。                |
| userId   | number                              | 是    | 用户ID，指定具体用户，取值范围：大于等于0。<br> 默认值：当前用户。 |
| callback | AsyncCallback\<boolean>             | 是    | 回调函数，当接口调用成功，err为null，data为boolean值，true表示当前用户下指定的设备管理应用被激活，false表示当前用户下指定的设备管理应用未激活，否则err为错误对象。      |

**错误码**:

以下错误码的详细介绍请参见[企业设备管理错误码](errorcode-enterpriseDeviceManager.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 202      | Permission verification failed. A non-system application calls a system API. |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |

**示例**：

```ts
import { Want } from '@kit.AbilityKit';
let wantTemp: Want = {
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility',
};

adminManager.isAdminEnabled(wantTemp, 100, (err, result) => {
  if (err) {
    console.error(`Failed to query admin is enabled. Code: ${err.code}, message: ${err.message}`);
    return;
  }
  console.info(`Succeeded in querying admin is enabled or not, result : ${result}`);
});
```

## adminManager.isAdminEnabled

isAdminEnabled(admin: Want, userId?: number): Promise\<boolean>

查询当前/指定用户下指定的设备管理应用是否被激活。使用promise异步回调。

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager



**模型约束**: 此接口仅可在Stage模型下使用。

**参数**：

| 参数名 | 类型                                                    | 必填 | 说明                                                         |
| ------ | ------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| admin  | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | 是   | 企业设备管理扩展组件。                                       |
| userId | number                                                  | 否   | 用户ID，取值范围：大于等于0。<br> - 调用接口时，若传入userId，表示指定用户。<br> - 调用接口时，若未传入userId，表示当前用户。 |

**返回值：**

| 类型               | 说明                |
| ----------------- | ------------------- |
| Promise\<boolean> | Promise对象, 返回true表示指定的设备管理应用被激活，返回false表示指定的设备管理应用未激活。|

**错误码**:

以下错误码的详细介绍请参见[企业设备管理错误码](errorcode-enterpriseDeviceManager.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 202      | Permission verification failed. A non-system application calls a system API. |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |

**示例**：

```ts
import { Want } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
let wantTemp: Want = {
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility',
};

adminManager.isAdminEnabled(wantTemp, 100).then((result) => {
  console.info(`Succeeded in querying admin is enabled or not, result : ${result}`);
}).catch((err: BusinessError) => {
  console.error(`Failed to query admin is enabled or not. Code: ${err.code}, message: ${err.message}`);
});
```

## adminManager.isSuperAdmin

isSuperAdmin(bundleName: String, callback: AsyncCallback\<boolean>): void

根据bundleName查询管理员用户下的超级设备管理应用是否被激活。使用callback异步回调。

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager



**模型约束**: 此接口仅可在Stage模型下使用。

**参数**：

| 参数名        | 类型                      | 必填   | 说明                   |
| ---------- | ----------------------- | ---- | -------------------- |
| bundleName | String                  | 是    | 超级设备管理应用。              |
| callback   | AsyncCallback\<boolean> | 是    | 回调函数，当接口调用成功，err为null，data为boolean类型值，true表示当前用户下指定的设备管理应用被激活，false表示当前用户下指定的设备管理应用未激活，否则err为错误对象。 |

**错误码**:

以下错误码的详细介绍请参见[企业设备管理错误码](errorcode-enterpriseDeviceManager.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 202      | Permission verification failed. A non-system application calls a system API. |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |

**示例**：

```ts
import { Want } from '@kit.AbilityKit';
let bundleName: string = 'com.example.myapplication';

adminManager.isSuperAdmin(bundleName, (err, result) => {
  if (err) {
    console.error(`Failed to query admin is super admin or not. Code: ${err.code}, message: ${err.message}`);
    return;
  }
  console.info(`Succeeded in querying admin is super admin or not, result : ${result}`);
});
```

## adminManager.isSuperAdmin

isSuperAdmin(bundleName: String): Promise\<boolean>

根据bundleName查询管理员用户下的超级设备管理应用是否被激活。使用promise异步回调。

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager



**模型约束**: 此接口仅可在Stage模型下使用。

**参数**：

| 参数名        | 类型     | 必填   | 说明        |
| ---------- | ------ | ---- | --------- |
| bundleName | String | 是    | 超级设备管理应用。 |

**返回值：**

| 错误码ID           | 错误信息               |
| ----------------- | ------------------- |
| Promise\<boolean> | Promise对象, 返回true表示指定的超级设备管理应用被激活，返回false表示指定的超级设备管理应用未激活。 |

**错误码**:

以下错误码的详细介绍请参见[企业设备管理错误码](errorcode-enterpriseDeviceManager.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 202      | Permission verification failed. A non-system application calls a system API. |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |

**示例**：

```ts
import { Want } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
let bundleName: string = 'com.example.myapplication';

adminManager.isSuperAdmin(bundleName).then((result) => {
  console.info(`Succeeded in querying admin is super admin or not, result : ${result}`);
}).catch((err: BusinessError) => {
  console.error(`Failed to query admin is super admin or not. Code: ${err.code}, message: ${err.message}`);
});
```

## adminManager.getSuperAdmin<sup>12+</sup>

getSuperAdmin(): Promise\<Want>

查询管理员用户下的超级设备管理应用。使用promise异步回调。

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager



**模型约束**: 此接口仅可在Stage模型下使用。

**返回值：**

| 类型                                                         | 说明                                                         |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| Promise\<[Want](../apis-ability-kit/js-apis-app-ability-want.md)> | 返回超级设备管理应用的Promise对象。当设备没有激活超级管理应用时，返回的Promise中Want的bundleName与abilityName为空串。 |

**错误码**:

以下错误码的详细介绍请参见[企业设备管理错误码](errorcode-enterpriseDeviceManager.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 202      | Permission verification failed. A non-system application calls a system API. |

**示例**：

```ts
import { BusinessError } from '@kit.BasicServicesKit';

adminManager.getSuperAdmin().then((result) => {
  console.info(`Succeeded in getting super admin :${JSON.stringify(result)}`);
}).catch((err: BusinessError) => {
  console.error(`Failed to get super admin. Code: ${err.code}, message: ${err.message}`);
})
```

## adminManager.setEnterpriseInfo

setEnterpriseInfo(admin: Want, enterpriseInfo: EnterpriseInfo, callback: AsyncCallback\<void>): void

设置设备管理应用的企业信息。使用callback异步回调。

**需要权限：** ohos.permission.SET_ENTERPRISE_INFO

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager



**模型约束**: 此接口仅可在Stage模型下使用。

**参数：**

| 参数名            | 类型                                  | 必填   | 说明                     |
| -------------- | ----------------------------------- | ---- | ---------------------- |
| admin          | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | 是    | 企业设备管理扩展组件。          |
| enterpriseInfo | [EnterpriseInfo](#enterpriseinfo)   | 是    | 设备管理应用的企业信息。           |
| callback       | AsyncCallback\<void>              | 是    | 回调函数，当接口调用成功，err为null，否则为错误对象。 |

**错误码**：

以下错误码的详细介绍请参见[企业设备管理错误码](errorcode-enterpriseDeviceManager.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                               |
| ------- | ----------------------------------------------------- |
| 9200001 | The application is not an administrator application of the device. |
| 201 | Permission verification failed. The application does not have the permission required to call the API. |
| 202 | Permission verification failed. A non-system application calls a system API. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**示例：**

```ts
import { Want } from '@kit.AbilityKit';
let wantTemp: Want = {
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility',
};
let enterpriseInfo: adminManager.EnterpriseInfo = {
  name: 'enterprise name',
  description: 'enterprise description'
}

adminManager.setEnterpriseInfo(wantTemp, enterpriseInfo, (err) => {
  if (err) {
    console.error(`Failed to set enterprise info. Code: ${err.code}, message: ${err.message}`);
    return;
  }
  console.info('Succeeded in setting enterprise info');
});
```

## adminManager.setEnterpriseInfo

setEnterpriseInfo(admin: Want, enterpriseInfo: EnterpriseInfo): Promise\<void>

设置设备管理应用的企业信息。使用promise异步回调。

**需要权限：** ohos.permission.SET_ENTERPRISE_INFO

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager



**模型约束**: 此接口仅可在Stage模型下使用。

**参数：**

| 参数名            | 类型                                  | 必填   | 说明           |
| -------------- | ----------------------------------- | ---- | ------------ |
| admin          | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | 是    | 企业设备管理扩展组件。 |
| enterpriseInfo | [EnterpriseInfo](#enterpriseinfo)   | 是    | 设备管理应用的企业信息。 |

**返回值：**

| 类型                | 说明                    |
| ----------------- | --------------------- |
| Promise\<void>    | 无返回结果的Promise对象。当设置设备管理应用企业信息失败时，会抛出错误对象。 |

**错误码**：

以下错误码的详细介绍请参见[企业设备管理错误码](errorcode-enterpriseDeviceManager.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                               |
| ------- | ----------------------------------------------------- |
| 9200001 | The application is not an administrator application of the device. |
| 201 | Permission verification failed. The application does not have the permission required to call the API. |
| 202 | Permission verification failed. A non-system application calls a system API. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**示例：**

```ts
import { Want } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
let wantTemp: Want = {
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility',
};
let enterpriseInfo: adminManager.EnterpriseInfo = {
  name: 'enterprise name',
  description: 'enterprise description'
}

adminManager.setEnterpriseInfo(wantTemp, enterpriseInfo).catch((err: BusinessError) => {
  console.error(`Failed to set enterprise info. Code: ${err.code}, message: ${err.message}`);
});
```

## adminManager.getEnterpriseInfo

getEnterpriseInfo(admin: Want, callback: AsyncCallback&lt;EnterpriseInfo&gt;): void

获取设备管理应用的企业信息。使用callback异步回调。

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager



**模型约束**: 此接口仅可在Stage模型下使用。

**参数：**

| 参数名      | 类型                                       | 必填   | 说明                       |
| -------- | ---------------------------------------- | ---- | ------------------------ |
| admin    | [Want](../apis-ability-kit/js-apis-app-ability-want.md)      | 是    | 企业设备管理扩展组件。           |
| callback | AsyncCallback&lt;[EnterpriseInfo](#enterpriseinfo)&gt; | 是    | 回调函数，当接口调用成功，err为null，data为设备管理应用的企业信息，否则err为错误对象。 |

**错误码**：

以下错误码的详细介绍请参见[企业设备管理错误码](errorcode-enterpriseDeviceManager.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                               |
| ------- | ----------------------------------------------------- |
| 9200001 | The application is not an administrator application of the device. |
| 202 | Permission verification failed. A non-system application calls a system API. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**示例：**

```ts
import { Want } from '@kit.AbilityKit';
let wantTemp: Want = {
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility',
};

adminManager.getEnterpriseInfo(wantTemp, (err, result) => {
  if (err) {
    console.error(`Failed to get enterprise info. Code: ${err.code}, message: ${err.message}`);
    return;
  }
  console.info(`Succeeded in getting enterprise info, enterprise name : ${result.name}, enterprise description : ${result.description}`);
});
```

## adminManager.getEnterpriseInfo

getEnterpriseInfo(admin: Want): Promise&lt;EnterpriseInfo&gt;

获取设备管理应用的企业信息，使用promise异步回调。

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager



**模型约束**: 此接口仅可在Stage模型下使用。

**参数：**

| 参数名   | 类型                                  | 必填   | 说明      |
| ----- | ----------------------------------- | ---- | ------- |
| admin | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | 是    | 企业设备管理扩展组件。 |

**返回值：**

| 类型                                       | 说明                        |
| ---------------------------------------- | ------------------------- |
| Promise&lt;[EnterpriseInfo](#enterpriseinfo)&gt; | Promise对象，返回设备管理应用的企业信息。 |

**错误码**：

以下错误码的详细介绍请参见[企业设备管理错误码](errorcode-enterpriseDeviceManager.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                               |
| ------- | ----------------------------------------------------- |
| 9200001 | The application is not an administrator application of the device. |
| 202 | Permission verification failed. A non-system application calls a system API. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**示例：**

```ts
import { Want } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
let wantTemp: Want = {
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility',
};

adminManager.getEnterpriseInfo(wantTemp).then((result) => {
  console.info(`Succeeded in getting enterprise info, enterprise name : ${result.name}, enterprise description : ${result.description}`);
}).catch((err: BusinessError) => {
  console.error(`Failed to get enterprise info. Code: ${err.code}, message: ${err.message}`);
});
```

## adminManager.subscribeManagedEvent

subscribeManagedEvent(admin: Want, managedEvents: Array\<ManagedEvent>, callback: AsyncCallback\<void>): void

订阅系统管理事件。使用callback异步回调。

**需要权限：** ohos.permission.ENTERPRISE_SUBSCRIBE_MANAGED_EVENT

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager



**模型约束**: 此接口仅可在Stage模型下使用。

**参数：**

| 参数名   | 类型                                  | 必填   | 说明      |
| ----- | ----------------------------------- | ---- | ------- |
| admin | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | 是    | 企业设备管理扩展组件。 |
| managedEvents  | Array\<[ManagedEvent](js-apis-enterprise-adminManager.md#managedevent)> | 是 | 订阅事件数组。 |
| callback | AsyncCallback\<void> | 是 | 回调函数，当接口调用成功，err为null，否则为错误对象。 |

**错误码**：

以下错误码的详细介绍请参见[企业设备管理错误码](errorcode-enterpriseDeviceManager.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 9200001  | The application is not an administrator application of the device. |
| 9200008  | The specified system event is invalid.                       |
| 201      | Permission verification failed. The application does not have the permission required to call the API. |
| 202      | Permission verification failed. A non-system application calls a system API. |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**示例：**

```ts
import { Want } from '@kit.AbilityKit';
let wantTemp: Want = {
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility',
};
let events: Array<adminManager.ManagedEvent> = [adminManager.ManagedEvent.MANAGED_EVENT_BUNDLE_ADDED, adminManager.ManagedEvent.MANAGED_EVENT_BUNDLE_REMOVED];

adminManager.subscribeManagedEvent(wantTemp, events, (err) => {
  if (err) {
    console.error(`Failed to subscribe managed event. Code: ${err.code}, message: ${err.message}`);
    return;
  }
  console.info('Succeeded in subscribe managed event');
});
```

## adminManager.subscribeManagedEvent

subscribeManagedEvent(admin: Want, managedEvents: Array\<ManagedEvent>): Promise\<void>

订阅系统管理事件。使用Promise异步回调。

**需要权限：** ohos.permission.ENTERPRISE_SUBSCRIBE_MANAGED_EVENT

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager



**模型约束**: 此接口仅可在Stage模型下使用。

**参数：**

| 参数名   | 类型                                  | 必填   | 说明      |
| ----- | ----------------------------------- | ---- | ------- |
| admin | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | 是    | 企业设备管理扩展组件。 |
| managedEvents  | Array\<[ManagedEvent](js-apis-enterprise-adminManager.md#managedevent)> | 是 | 订阅事件数组。 |

**返回值：**

| 类型   | 说明                                  |
| ----- | ----------------------------------- |
| Promise\<void> | 无返回结果的Promise对象。当订阅系统事件失败时，会抛出错误对象。 |

**错误码**：

以下错误码的详细介绍请参见[企业设备管理错误码](errorcode-enterpriseDeviceManager.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                               |
| ------- | ----------------------------------------------------- |
| 9200001 | The application is not an administrator application of the device. |
| 9200008 | The specified system event is invalid.          |
| 201 | Permission verification failed. The application does not have the permission required to call the API. |
| 202 | Permission verification failed. A non-system application calls a system API. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**示例：**

```ts
import { Want } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
let wantTemp: Want = {
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility',
};
let events: Array<adminManager.ManagedEvent> = [adminManager.ManagedEvent.MANAGED_EVENT_BUNDLE_ADDED, adminManager.ManagedEvent.MANAGED_EVENT_BUNDLE_REMOVED];

adminManager.subscribeManagedEvent(wantTemp, events).then(() => {
}).catch((err: BusinessError) => {
  console.error(`Failed to subscribe managed event. Code: ${err.code}, message: ${err.message}`);
})
```

## adminManager.unsubscribeManagedEvent

unsubscribeManagedEvent(admin: Want, managedEvents: Array\<ManagedEvent>, callback: AsyncCallback\<void>): void

取消订阅系统管理事件。使用callback异步回调。

**需要权限：** ohos.permission.ENTERPRISE_SUBSCRIBE_MANAGED_EVENT

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager



**模型约束**: 此接口仅可在Stage模型下使用。

**参数：**

| 参数名   | 类型                                  | 必填   | 说明      |
| ----- | ----------------------------------- | ---- | ------- |
| admin | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | 是    | 企业设备管理扩展组件。 |
| managedEvents  | Array\<[ManagedEvent](js-apis-enterprise-adminManager.md#managedevent)> | 是 | 取消订阅事件数组。 |
| callback | AsyncCallback\<void> | 是 | 回调函数，当接口调用成功，err为null，否则为错误对象。 |

**错误码**：

以下错误码的详细介绍请参见[企业设备管理错误码](errorcode-enterpriseDeviceManager.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                               |
| ------- | ----------------------------------------------------- |
| 9200001 | The application is not an administrator application of the device. |
| 9200008 | The specified system event is invalid.          |
| 201 | Permission verification failed. The application does not have the permission required to call the API. |
| 202 | Permission verification failed. A non-system application calls a system API. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**示例：**

```ts
import { Want } from '@kit.AbilityKit';
let wantTemp: Want = {
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility',
};
let events: Array<adminManager.ManagedEvent> = [adminManager.ManagedEvent.MANAGED_EVENT_BUNDLE_ADDED, adminManager.ManagedEvent.MANAGED_EVENT_BUNDLE_REMOVED];

adminManager.unsubscribeManagedEvent(wantTemp, events, (err) => {
  if (err) {
    console.error(`Failed to unsubscribe managed event. Code: ${err.code}, message: ${err.message}`);
    return;
  }
  console.info('Succeeded in unsubscribe managed event');
});
```

## adminManager.unsubscribeManagedEvent

unsubscribeManagedEvent(admin: Want, managedEvents: Array\<ManagedEvent>): Promise\<void>

取消订阅系统管理事件。使用promise异步回调。

**需要权限：** ohos.permission.ENTERPRISE_SUBSCRIBE_MANAGED_EVENT

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager



**模型约束**: 此接口仅可在Stage模型下使用。

**参数：**

| 参数名   | 类型                                  | 必填   | 说明      |
| ----- | ----------------------------------- | ---- | ------- |
| admin | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | 是    | 企业设备管理扩展组件。 |
| managedEvents  | Array\<[ManagedEvent](js-apis-enterprise-adminManager.md#managedevent)> | 是 | 取消订阅事件数组。 |

**返回值：**

| 类型   | 说明                                  |
| ----- | ----------------------------------- |
| Promise\<void> | 无返回结果的Promise对象。当取消订阅系统管理事件失败时，会抛出错误对象。 |

**错误码**：

以下错误码的详细介绍请参见[企业设备管理错误码](errorcode-enterpriseDeviceManager.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                               |
| ------- | ----------------------------------------------------- |
| 9200001 | The application is not an administrator application of the device. |
| 9200008 | The specified system event is invalid.          |
| 201 | Permission verification failed. The application does not have the permission required to call the API. |
| 202 | Permission verification failed. A non-system application calls a system API. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**示例：**

```ts
import { Want } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
let wantTemp: Want = {
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility',
};
let events: Array<adminManager.ManagedEvent> = [adminManager.ManagedEvent.MANAGED_EVENT_BUNDLE_ADDED, adminManager.ManagedEvent.MANAGED_EVENT_BUNDLE_REMOVED];

adminManager.unsubscribeManagedEvent(wantTemp, events).then(() => {
}).catch((err: BusinessError) => {
  console.error(`Failed to unsubscribe managed event. Code: ${err.code}, message: ${err.message}`);
})
```

## adminManager.authorizeAdmin<sup>10+</sup>

authorizeAdmin(admin: Want, bundleName: string, callback: AsyncCallback&lt;void&gt;): void

授予指定应用管理员权限。使用callback异步回调。

**需要权限：** ohos.permission.MANAGE_ENTERPRISE_DEVICE_ADMIN

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager



**模型约束**: 此接口仅可在Stage模型下使用。

**参数：**

| 参数名   | 类型                                  | 必填   | 说明      |
| ----- | ----------------------------------- | ---- | ------- |
| admin | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | 是    | 企业设备管理扩展组件。 |
| bundleName  | string | 是 | 被授予管理员权限应用的包名。 |
| callback | AsyncCallback&lt;void&gt; | 是 | 回调函数，当接口调用成功，err为null，否则为错误对象。 |

**错误码**：

以下的错误码的详细介绍请参见[企业设备管理错误码](errorcode-enterpriseDeviceManager.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                               |
| ------- | ----------------------------------------------------- |
| 9200001 | The application is not an administrator application of the device. |
| 9200002 | The administrator application does not have permission to manage the device.          |
| 9200009 | Failed to grant the permission to the application. |
| 201 | Permission verification failed. The application does not have the permission required to call the API. |
| 202 | Permission verification failed. A non-system application calls a system API. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**示例：**

```ts
import { Want } from '@kit.AbilityKit';
let wantTemp: Want = {
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility',
};
let bundleName: string = "com.example.application";

adminManager.authorizeAdmin(wantTemp, bundleName, (err) => {
  if (err) {
    console.error(`Failed to authorize permission to the application. Code: ${err.code}, message: ${err.message}`);
    return;
  }
  console.info('Successfully authorized permission to the application');
});
```

## adminManager.authorizeAdmin<sup>10+</sup>

authorizeAdmin(admin: Want, bundleName: string): Promise&lt;void&gt;

授予指定应用管理员权限。使用Promise异步回调。

**需要权限：** ohos.permission.MANAGE_ENTERPRISE_DEVICE_ADMIN

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager



**模型约束**: 此接口仅可在Stage模型下使用。

**参数：**

| 参数名   | 类型                                  | 必填   | 说明      |
| ----- | ----------------------------------- | ---- | ------- |
| admin | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | 是    | 企业设备管理扩展组件。 |
| bundleName  | string | 是 | 被授予管理员权限应用的包名。 |

**返回值：**

| 类型   | 说明                                  |
| ----- | ----------------------------------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。当授予指定应用管理员权限失败时，抛出错误对象。 |

**错误码**：

以下的错误码的详细介绍请参见[企业设备管理错误码](errorcode-enterpriseDeviceManager.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                               |
| ------- | ----------------------------------------------------- |
| 9200001 | The application is not an administrator application of the device. |
| 9200002 | The administrator application does not have permission to manage the device.          |
| 9200009 | Failed to grant the permission to the application. |
| 201 | Permission verification failed. The application does not have the permission required to call the API. |
| 202 | Permission verification failed. A non-system application calls a system API. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**示例：**

```ts
import { Want } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
let wantTemp: Want = {
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility',
};
let bundleName: string = "com.example.application";

adminManager.authorizeAdmin(wantTemp, bundleName).then(() => {
}).catch((err: BusinessError) => {
  console.error(`Failed to authorize permission to the application. Code: ${err.code}, message: ${err.message}`);
})
```

## adminManager.getAdmins<sup>15+</sup>

getAdmins(): Promise&lt;Array&lt;Want&gt;&gt;

查询当前用户下的所有设备管理应用。使用promise异步回调。

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager



**模型约束**: 此接口仅可在Stage模型下使用。


**返回值：**

| 类型   | 说明                                  |
| ----- | ----------------------------------- |
| Promise&lt;Array&lt;Want&gt;&gt; | 包含所有已激活的设备管理应用的Promise对象。 |

**错误码**：

以下的错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                               |
| ------- | ----------------------------------------------------- |
| 202 | Permission verification failed. A non-system application calls a system API. |

**示例：**

```ts
import { Want } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

adminManager.getAdmins().then((result) => {
  console.info(`Succeeded in getting admins :${JSON.stringify(result)}`);
}).catch((err: BusinessError) => {
  console.error(`Failed to get admins. Code: ${err.code}, message: ${err.message}`);
})
```

## adminManager.replaceSuperAdmin<sup>18+</sup>

replaceSuperAdmin(oldAdmin: Want, newAdmin: Want, isKeepPolicy: boolean): void

将指定应用替换成超级设备管理应用。

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager



**模型约束**: 此接口仅可在Stage模型下使用。

**参数**：

| 参数名            | 类型                                  | 必填   | 说明                           |
| -------------- | ----------------------------------- | ---- | ---------------------------- |
| oldAdmin       | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | 是    | 原有企业设备管理扩展组件。                  |
| newAdmin       | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | 是    | 新企业设备管理扩展组件。                 |
| isKeepPolicy   | boolean                             | 是    | 是否保留原有企业设备管理扩展组件的策略，取值为true表示保留，取值为false表示不保留。      |

**错误码**：

以下错误码的详细介绍请参见[企业设备管理错误码](errorcode-enterpriseDeviceManager.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                               |
| ------- | ----------------------------------------------------- |
| 9200001 | The application is not an administrator application of the device. |
| 9200003 | The administrator ability component is invalid. |
| 9200011 | Failed to replace the administrator application of the device. |
| 201  | Permission verification failed. The application does not have the permission required to call the API. |
| 202  | Permission verification failed. A non-system application calls a system API. |

**示例：**

```ts
import { Want } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let oldAdmin: Want = {
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility',
};
let newAdmin: Want = {
  bundleName: 'com.example.myapplication_new',
  abilityName: 'NewEntryAbility',
};
try {
  adminManager.replaceSuperAdmin(oldAdmin, newAdmin, false);
  console.info(`Succeeded in replace super admin.`);
} catch(err) {
  console.error(`Failed to replace super admin. Code: ${err.code}, message: ${err.message}`);
}
```

## adminManager.setAdminRunningMode<sup>19+</sup>

setAdminRunningMode(admin: Want, mode: RunningMode): void

设置设备管理应用的运行模式。

该接口仅在PC设备上生效。

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager



**模型约束**: 此接口仅可在Stage模型下使用。

**参数**：

| 参数名            | 类型                                  | 必填   | 说明                           |
| -------------- | ----------------------------------- | ---- | ---------------------------- |
| admin | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | 是    | 企业设备管理扩展组件。       |
| mode | [RunningMode](#runningmode19) | 是    | 运行模式。取值为DEFAULT表示默认用户运行模式，即应用在首次开机后的用户下运行。取值为MULTI_USER表示多用户运行模式，即应用能够在多个用户下同时运行。 |



**错误码**：

以下错误码的详细介绍请参见[企业设备管理错误码](errorcode-enterpriseDeviceManager.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                               |
| ------- | ----------------------------------------------------- |
| 9200001 | The application is not an administrator application of the device. |
| 201  | Permission verification failed. The application does not have the permission required to call the API. |
| 202  | Permission verification failed. A non-system application calls a system API. |

**示例：**

```ts
import { Want } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { adminManager } from '@kit.MDMKit'

let admin: Want = {
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility',
};
try {
  adminManager.setAdminRunningMode(admin, adminManager.RunningMode.MULTI_USER);
  console.info(`Succeeded in set admin running mode.`);
} catch(err) {
  console.error(`Failed to set admin running mode. Code: ${err.code}, message: ${err.message}`);
}
```

## EnterpriseInfo

设备管理应用的企业信息。

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager



| 名称         | 类型     | 必填 | 说明                            |
| ----------- | --------| ---- | ------------------------------- |
| name        | string   | 是   | 表示设备管理应用所属企业的名称。 |
| description | string   | 是   | 表示设备管理应用所属企业的描述。 |

## AdminType

设备管理应用的类型。 

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager



| 名称                | 值  | 说明    |
| ----------------- | ---- | ----- |
| ADMIN_TYPE_NORMAL | 0x00 | 普通设备管理应用。 |
| ADMIN_TYPE_SUPER  | 0x01 | 超级设备管理应用。 |

## RunningMode<sup>19+</sup>

设备管理的运行模式。 

**系统能力：** SystemCapability.Customization.EnterpriseDeviceManager



| 名称                | 值  | 说明    |
| ----------------- | ---- | ----- |
| DEFAULT  | 0 | 默认用户运行模式，表示应用在首次开机后的用户下运行。 |
| MULTI_USER   | 1 | 多用户运行模式，表示应用能够在多个用户下同时运行。 |

