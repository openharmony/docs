# @ohos.enterprise.adminManager (Enterprise Device Management) (System API)

The **adminManager** module provides enterprise device management capabilities so that devices have the custom capabilities required in enterprise settings.

> **NOTE**
>
> - The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
> - The APIs of this module are available only to [device administrator applications](../../mdm/mdm-kit-guide.md#introduction).
> 
> - This topic describes only the system APIs provided by the module. For details about its public APIs, see [@ohos.enterprise.adminManager](js-apis-enterprise-adminManager.md).

## Modules to Import

```ts
import { adminManager } from '@kit.MDMKit';
```

## adminManager.enableAdmin

enableAdmin(admin: Want, enterpriseInfo: EnterpriseInfo, type: AdminType, callback: AsyncCallback\<void>): void

Enables a device administrator application for the current user. The super device administrator application can be activated only by the administrator. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.MANAGE_ENTERPRISE_DEVICE_ADMIN

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager



**Model restriction**: This API can be used only in the stage model.

**Parameters**

| Name           | Type                                 | Mandatory  | Description                |
| -------------- | ----------------------------------- | ---- | ------------------ |
| admin          | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | Yes   | Device administrator application to enable.           |
| enterpriseInfo | [EnterpriseInfo](#enterpriseinfo)   | Yes   | Enterprise information of the device administrator application.     |
| type           | [AdminType](#admintype)             | Yes   | Type of the device administrator application to enable.        |
| callback       | AsyncCallback\<void>                | Yes   | Callback invoked to return the result. If the operation is successful, **err** is **null**. Otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](errorcode-enterpriseDeviceManager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                        |
| ------- | --------------------------------------------------------------- |
| 9200003 | The administrator ability component is invalid.                 |
| 9200004 | Failed to activate the administrator application of the device.   |
| 9200007 | The system ability works abnormally. |
| 201 | Permission verification failed. The application does not have the permission required to call the API. |
| 202 | Permission verification failed. A non-system application calls a system API. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**

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

Enables a device administrator application for the specified user. The super device administrator application can be activated only by the administrator. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.MANAGE_ENTERPRISE_DEVICE_ADMIN

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager



**Model restriction**: This API can be used only in the stage model.

**Parameters**

| Name           | Type                                 | Mandatory  | Description                          |
| -------------- | ----------------------------------- | ---- | ---------------------------- |
| admin          | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | Yes   | Device administrator application to enable.                     |
| enterpriseInfo | [EnterpriseInfo](#enterpriseinfo)   | Yes   | Enterprise information of the device administrator application.                |
| type           | [AdminType](#admintype)             | Yes   | Type of the device administrator application to enable.                 |
| userId         | number                              | Yes   | User ID, which must be greater than or equal to 0.<br>The default value is the user ID of the caller. |
| callback       | AsyncCallback\<void>                | Yes   | Callback invoked to return the result. If the operation is successful, **err** is **null**. Otherwise, **err** is an error object.      |

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](errorcode-enterpriseDeviceManager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                        |
| ------- | --------------------------------------------------------------- |
| 9200003 | The administrator ability component is invalid.                 |
| 9200004 | Failed to activate the administrator application of the device.   |
| 9200007 | The system ability works abnormally. |
| 201 | Permission verification failed. The application does not have the permission required to call the API. |
| 202 | Permission verification failed. A non-system application calls a system API. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**

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

Enables a device administrator application for the current or specified user. The super device administrator application can be activated only by the administrator. This API uses a promise to return the result.

**Required permissions**: ohos.permission.MANAGE_ENTERPRISE_DEVICE_ADMIN

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager



**Model restriction**: This API can be used only in the stage model.

**Parameters**

| Name           | Type                                 | Mandatory  | Description                          |
| -------------- | ----------------------------------- | ---- | ---------------------------- |
| admin          | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | Yes   | Device administrator application to enable.                     |
| enterpriseInfo | [EnterpriseInfo](#enterpriseinfo)   | Yes   | Enterprise information of the device administrator application.                |
| type           | [AdminType](#admintype)             | Yes   | Type of the device administrator application to enable.                  |
| userId         | number                              | No   | User ID, which must be greater than or equal to 0.<br> - If **userId** is passed in, this API applies to the specified user.<br> - If **userId** is not passed in, this API applies to the current user.|

**Return value**

| Type               | Description               |
| ----------------- | ----------------- |
| Promise\<void>    | Promise that returns no value. If the operation fails, an error object will be thrown.|

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](errorcode-enterpriseDeviceManager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                        |
| ------- | --------------------------------------------------------------- |
| 9200003 | The administrator ability component is invalid.                 |
| 9200004 | Failed to activate the administrator application of the device.   |
| 9200007 | The system ability works abnormally. |
| 201 | Permission verification failed. The application does not have the permission required to call the API. |
| 202 | Permission verification failed. A non-system application calls a system API. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**

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

Disables a common administrator application for the current user. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.MANAGE_ENTERPRISE_DEVICE_ADMIN

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager



**Model restriction**: This API can be used only in the stage model.

**Parameters**

| Name     | Type                                 | Mandatory  | Description                 |
| -------- | ----------------------------------- | ---- | ------------------- |
| admin    | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | Yes   | Common administrator application to disable.          |
| callback | AsyncCallback\<void>                | Yes   | Callback invoked to return the result. If the operation is successful, **err** is **null**. Otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](errorcode-enterpriseDeviceManager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                          |
| ------- | ----------------------------------------------------------------- |
| 9200005 | Failed to deactivate the administrator application of the device.    |
| 201 | Permission verification failed. The application does not have the permission required to call the API. |
| 202 | Permission verification failed. A non-system application calls a system API. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**

```ts
import { Want } from '@kit.AbilityKit';
let wantTemp: Want = {
  bundleName: 'bundleName',
  abilityName: 'abilityName',
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

Disables a common administrator application for the specified user. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.MANAGE_ENTERPRISE_DEVICE_ADMIN

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager



**Model restriction**: This API can be used only in the stage model.

**Parameters**

| Name     | Type                                 | Mandatory  | Description                          |
| -------- | ----------------------------------- | ---- | ---------------------------- |
| admin    | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | Yes   | Common administrator application to disable.                   |
| userId   | number                              | Yes   | User ID, which must be greater than or equal to 0.<br>The default value is the user ID of the caller. |
| callback | AsyncCallback\<void>                | Yes   | Callback invoked to return the result. If the operation is successful, **err** is **null**. Otherwise, **err** is an error object.       |

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](errorcode-enterpriseDeviceManager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                          |
| ------- | ----------------------------------------------------------------- |
| 9200005 | Failed to deactivate the administrator application of the device.    |
| 201 | Permission verification failed. The application does not have the permission required to call the API. |
| 202 | Permission verification failed. A non-system application calls a system API. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**

```ts
import { Want } from '@kit.AbilityKit';
let wantTemp: Want = {
  bundleName: 'bundleName',
  abilityName: 'abilityName',
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

Disables a super administrator application for the administrator based on **bundleName**. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.MANAGE_ENTERPRISE_DEVICE_ADMIN

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager



**Model restriction**: This API can be used only in the stage model.

**Parameters**

| Name       | Type                     | Mandatory  | Description                 |
| ---------- | ----------------------- | ---- | ------------------- |
| bundleName | String                  | Yes   | Bundle name of the super administrator application to disable.       |
| callback   | AsyncCallback\<void>    | Yes   | Callback invoked to return the result. If the operation is successful, **err** is **null**. Otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](errorcode-enterpriseDeviceManager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                          |
| ------- | ----------------------------------------------------------------- |
| 9200005 | Failed to deactivate the administrator application of the device.    |
| 201 | Permission verification failed. The application does not have the permission required to call the API. |
| 202 | Permission verification failed. A non-system application calls a system API. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**

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

Disables a super administrator application for the administrator based on **bundleName**. This API uses a promise to return the result.

**Required permissions**: ohos.permission.MANAGE_ENTERPRISE_DEVICE_ADMIN

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager



**Model restriction**: This API can be used only in the stage model.

**Parameters**

| Name       | Type    | Mandatory  | Description          |
| ---------- | ------ | ---- | ------------ |
| bundleName | String | Yes   | Bundle name of the super administrator application to disable.|

**Return value**

| Type               | Description               |
| ----------------- | ----------------- |
| Promise\<void>    | Promise that returns no value. If the operation fails, an error object will be thrown.|

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](errorcode-enterpriseDeviceManager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                          |
| ------- | ----------------------------------------------------------------- |
| 9200005 | Failed to deactivate the administrator application of the device.    |
| 201 | Permission verification failed. The application does not have the permission required to call the API. |
| 202 | Permission verification failed. A non-system application calls a system API. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**

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

Checks whether a device administrator application of the current user is enabled. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager



**Model restriction**: This API can be used only in the stage model.

**Parameters**

| Name     | Type                                 | Mandatory  | Description                  |
| -------- | ----------------------------------- | ---- | -------------------- |
| admin    | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | Yes   | Device administrator application to check.            |
| callback | AsyncCallback\<boolean>             | Yes   | Callback invoked to return the result. If the operation is successful, **err** is **null** and **data** is a Boolean value (**true** means that the device administrator application is enabled; and **false** means the opposite). If the operation fails, **err** is an error object.|

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](errorcode-enterpriseDeviceManager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 202      | Permission verification failed. A non-system application calls a system API. |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |

**Example**

```ts
import { Want } from '@kit.AbilityKit';
let wantTemp: Want = {
  bundleName: 'bundleName',
  abilityName: 'abilityName',
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

Checks whether a device administrator application of the specified user is enabled. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager



**Model restriction**: This API can be used only in the stage model.

**Parameters**

| Name     | Type                                 | Mandatory  | Description                          |
| -------- | ----------------------------------- | ---- | ---------------------------- |
| admin    | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | Yes   | Device administrator application to check.                     |
| userId   | number                              | Yes   | User ID, which must be greater than or equal to 0.<br> The default value is the user ID of the caller. |
| callback | AsyncCallback\<boolean>             | Yes   | Callback invoked to return the result. If the operation is successful, **err** is **null** and **data** is a Boolean value (**true** means that the device administrator application is enabled; and **false** means the opposite). If the operation fails, **err** is an error object.     |

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](errorcode-enterpriseDeviceManager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 202      | Permission verification failed. A non-system application calls a system API. |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |

**Example**

```ts
import { Want } from '@kit.AbilityKit';
let wantTemp: Want = {
  bundleName: 'bundleName',
  abilityName: 'abilityName',
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

Checks whether a device administrator application of the current or specified user is enabled. This API uses a promise to return the result.

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager



**Model restriction**: This API can be used only in the stage model.

**Parameters**

| Name   | Type                                 | Mandatory  | Description                          |
| ------ | ----------------------------------- | ---- | ---------------------------- |
| admin  | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | Yes   | Device administrator application to check.                     |
| userId | number                              | No   | User ID, which must be greater than or equal to 0.<br> - If **userId** is passed in, this API applies to the specified user.<br> - If **userId** is not passed in, this API applies to the current user.|

**Return value**

| Type              | Description               |
| ----------------- | ------------------- |
| Promise\<boolean> | Promise used to return the result. The value **true** means the device administrator application is enabled; the value **false** means the opposite.|

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](errorcode-enterpriseDeviceManager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 202      | Permission verification failed. A non-system application calls a system API. |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |

**Example**

```ts
import { Want } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
let wantTemp: Want = {
  bundleName: 'bundleName',
  abilityName: 'abilityName',
};

adminManager.isAdminEnabled(wantTemp, 100).then((result) => {
  console.info(`Succeeded in querying admin is enabled or not, result : ${result}`);
}).catch((err: BusinessError) => {
  console.error(`Failed to query admin is enabled or not. Code: ${err.code}, message: ${err.message}`);
});
```

## adminManager.isSuperAdmin

isSuperAdmin(bundleName: String, callback: AsyncCallback\<boolean>): void

Checks whether a super administrator application of the administrator is enabled based on **bundleName**. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager



**Model restriction**: This API can be used only in the stage model.

**Parameters**

| Name       | Type                     | Mandatory  | Description                  |
| ---------- | ----------------------- | ---- | -------------------- |
| bundleName | String                  | Yes   | Super administrator application to check.             |
| callback   | AsyncCallback\<boolean> | Yes   | Callback invoked to return the result. If the operation is successful, **err** is **null** and **data** is a Boolean value (**true** means that the device administrator application is enabled; and **false** means the opposite). If the operation fails, **err** is an error object.|

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](errorcode-enterpriseDeviceManager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 202      | Permission verification failed. A non-system application calls a system API. |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |

**Example**

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

Checks whether a super administrator application of the administrator is enabled based on **bundleName**. This API uses a promise to return the result.

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager



**Model restriction**: This API can be used only in the stage model.

**Parameters**

| Name       | Type    | Mandatory  | Description       |
| ---------- | ------ | ---- | --------- |
| bundleName | String | Yes   | Super administrator application to check.|

**Return value**

| ID          | Error Message              |
| ----------------- | ------------------- |
| Promise\<boolean> | Promise used to return the result. The value **true** means the super administrator application is enabled; the value **false** means the opposite. |

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](errorcode-enterpriseDeviceManager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 202      | Permission verification failed. A non-system application calls a system API. |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |

**Example**

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

Obtains the super device administrator application of this administrator. This API uses a promise to return the result.

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager



**Model restriction**: This API can be used only in the stage model.

**Return value**

| Type                                                        | Description                                                        |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| Promise\<[Want](../apis-ability-kit/js-apis-app-ability-want.md)> | Promise used to return the super device administrator application obtained. If no super device administrator application is activated on the device, **bundleName** and **abilityName** in **Want** returned are empty strings.|

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](errorcode-enterpriseDeviceManager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 202      | Permission verification failed. A non-system application calls a system API. |

**Example**

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

Sets enterprise information for a device administrator application. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.SET_ENTERPRISE_INFO

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager



**Model restriction**: This API can be used only in the stage model.

**Parameters**

| Name           | Type                                 | Mandatory  | Description                    |
| -------------- | ----------------------------------- | ---- | ---------------------- |
| admin          | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | Yes   | Device administrator application to enable.               |
| enterpriseInfo | [EnterpriseInfo](#enterpriseinfo)   | Yes   | Enterprise information to set.          |
| callback       | AsyncCallback\<void>              | Yes   | Callback invoked to return the result. If the operation is successful, **err** is **null**. Otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](errorcode-enterpriseDeviceManager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                              |
| ------- | ----------------------------------------------------- |
| 9200001 | The application is not an administrator application of the device. |
| 201 | Permission verification failed. The application does not have the permission required to call the API. |
| 202 | Permission verification failed. A non-system application calls a system API. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**

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

Sets enterprise information for a device administrator application. This API uses a promise to return the result.

**Required permissions**: ohos.permission.SET_ENTERPRISE_INFO

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager



**Model restriction**: This API can be used only in the stage model.

**Parameters**

| Name           | Type                                 | Mandatory  | Description          |
| -------------- | ----------------------------------- | ---- | ------------ |
| admin          | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | Yes   | Device administrator application.     |
| enterpriseInfo | [EnterpriseInfo](#enterpriseinfo)   | Yes   | Enterprise information to set.|

**Return value**

| Type               | Description                   |
| ----------------- | --------------------- |
| Promise\<void>    | Promise that returns no value. If the operation fails, an error object will be thrown.|

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](errorcode-enterpriseDeviceManager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                              |
| ------- | ----------------------------------------------------- |
| 9200001 | The application is not an administrator application of the device. |
| 201 | Permission verification failed. The application does not have the permission required to call the API. |
| 202 | Permission verification failed. A non-system application calls a system API. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**

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

Obtains the enterprise information of a device administrator application. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager



**Model restriction**: This API can be used only in the stage model.

**Parameters**

| Name     | Type                                      | Mandatory  | Description                      |
| -------- | ---------------------------------------- | ---- | ------------------------ |
| admin    | [Want](../apis-ability-kit/js-apis-app-ability-want.md)      | Yes   | Device administrator application.                 |
| callback | AsyncCallback&lt;[EnterpriseInfo](#enterpriseinfo)&gt; | Yes   | Callback invoked to return the result. If the operation is successful, **err** is **null** and **data** is the enterprise information of the device administrator application obtained. If the operation fails, **err** is an error object.|

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](errorcode-enterpriseDeviceManager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                              |
| ------- | ----------------------------------------------------- |
| 9200001 | The application is not an administrator application of the device. |
| 202 | Permission verification failed. A non-system application calls a system API. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**

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

Obtains the enterprise information of a device administrator application. This API uses a promise to return the result.

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager



**Model restriction**: This API can be used only in the stage model.

**Parameters**

| Name  | Type                                 | Mandatory  | Description     |
| ----- | ----------------------------------- | ---- | ------- |
| admin | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | Yes   | Device administrator application.|

**Return value**

| Type                                      | Description                       |
| ---------------------------------------- | ------------------------- |
| Promise&lt;[EnterpriseInfo](#enterpriseinfo)&gt; | Promise used to return the enterprise information obtained.|

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](errorcode-enterpriseDeviceManager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                              |
| ------- | ----------------------------------------------------- |
| 9200001 | The application is not an administrator application of the device. |
| 202 | Permission verification failed. A non-system application calls a system API. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**

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

Subscribes to system management events of a device administrator application. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.ENTERPRISE_SUBSCRIBE_MANAGED_EVENT

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager



**Model restriction**: This API can be used only in the stage model.

**Parameters**

| Name  | Type                                 | Mandatory  | Description     |
| ----- | ----------------------------------- | ---- | ------- |
| admin | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | Yes   | Device administrator application.|
| managedEvents  | Array\<[ManagedEvent](js-apis-enterprise-adminManager.md#managedevent)> | Yes| Array of events to subscribe to.|
| callback | AsyncCallback\<void> | Yes| Callback invoked to return the result. If the operation is successful, **err** is **null**. Otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](errorcode-enterpriseDeviceManager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 9200001  | The application is not an administrator application of the device. |
| 9200008  | The specified system event is invalid.                       |
| 201      | Permission verification failed. The application does not have the permission required to call the API. |
| 202      | Permission verification failed. A non-system application calls a system API. |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**

```ts
import { Want } from '@kit.AbilityKit';
let wantTemp: Want = {
  bundleName: 'bundleName',
  abilityName: 'abilityName',
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

Subscribes to system management events of a device administrator application. This API uses a promise to return the result.

**Required permissions**: ohos.permission.ENTERPRISE_SUBSCRIBE_MANAGED_EVENT

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager



**Model restriction**: This API can be used only in the stage model.

**Parameters**

| Name  | Type                                 | Mandatory  | Description     |
| ----- | ----------------------------------- | ---- | ------- |
| admin | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | Yes   | Device administrator application.|
| managedEvents  | Array\<[ManagedEvent](js-apis-enterprise-adminManager.md#managedevent)> | Yes| Array of events to subscribe to.|

**Return value**

| Type  | Description                                 |
| ----- | ----------------------------------- |
| Promise\<void> | Promise that returns no value. If the operation fails, an error object will be thrown.|

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](errorcode-enterpriseDeviceManager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                              |
| ------- | ----------------------------------------------------- |
| 9200001 | The application is not an administrator application of the device. |
| 9200008 | The specified system event is invalid.          |
| 201 | Permission verification failed. The application does not have the permission required to call the API. |
| 202 | Permission verification failed. A non-system application calls a system API. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**

```ts
import { Want } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
let wantTemp: Want = {
  bundleName: 'bundleName',
  abilityName: 'abilityName',
};
let events: Array<adminManager.ManagedEvent> = [adminManager.ManagedEvent.MANAGED_EVENT_BUNDLE_ADDED, adminManager.ManagedEvent.MANAGED_EVENT_BUNDLE_REMOVED];

adminManager.subscribeManagedEvent(wantTemp, events).then(() => {
}).catch((err: BusinessError) => {
  console.error(`Failed to subscribe managed event. Code: ${err.code}, message: ${err.message}`);
})
```

## adminManager.unsubscribeManagedEvent

unsubscribeManagedEvent(admin: Want, managedEvents: Array\<ManagedEvent>, callback: AsyncCallback\<void>): void

Unsubscribes from system management events of a device administrator application. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.ENTERPRISE_SUBSCRIBE_MANAGED_EVENT

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager



**Model restriction**: This API can be used only in the stage model.

**Parameters**

| Name  | Type                                 | Mandatory  | Description     |
| ----- | ----------------------------------- | ---- | ------- |
| admin | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | Yes   | Device administrator application.|
| managedEvents  | Array\<[ManagedEvent](js-apis-enterprise-adminManager.md#managedevent)> | Yes| Array of events to unsubscribe from.|
| callback | AsyncCallback\<void> | Yes| Callback invoked to return the result. If the operation is successful, **err** is **null**. Otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](errorcode-enterpriseDeviceManager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                              |
| ------- | ----------------------------------------------------- |
| 9200001 | The application is not an administrator application of the device. |
| 9200008 | The specified system event is invalid.          |
| 201 | Permission verification failed. The application does not have the permission required to call the API. |
| 202 | Permission verification failed. A non-system application calls a system API. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**

```ts
import { Want } from '@kit.AbilityKit';
let wantTemp: Want = {
  bundleName: 'bundleName',
  abilityName: 'abilityName',
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

Unsubscribes from system management events of a device administrator application. This API uses a promise to return the result.

**Required permissions**: ohos.permission.ENTERPRISE_SUBSCRIBE_MANAGED_EVENT

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager



**Model restriction**: This API can be used only in the stage model.

**Parameters**

| Name  | Type                                 | Mandatory  | Description     |
| ----- | ----------------------------------- | ---- | ------- |
| admin | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | Yes   | Device administrator application.|
| managedEvents  | Array\<[ManagedEvent](js-apis-enterprise-adminManager.md#managedevent)> | Yes| Array of events to unsubscribe from.|

**Return value**

| Type  | Description                                 |
| ----- | ----------------------------------- |
| Promise\<void> | Promise that returns no value. If the operation fails, an error object will be thrown.|

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](errorcode-enterpriseDeviceManager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                              |
| ------- | ----------------------------------------------------- |
| 9200001 | The application is not an administrator application of the device. |
| 9200008 | The specified system event is invalid.          |
| 201 | Permission verification failed. The application does not have the permission required to call the API. |
| 202 | Permission verification failed. A non-system application calls a system API. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**

```ts
import { Want } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
let wantTemp: Want = {
  bundleName: 'bundleName',
  abilityName: 'abilityName',
};
let events: Array<adminManager.ManagedEvent> = [adminManager.ManagedEvent.MANAGED_EVENT_BUNDLE_ADDED, adminManager.ManagedEvent.MANAGED_EVENT_BUNDLE_REMOVED];

adminManager.unsubscribeManagedEvent(wantTemp, events).then(() => {
}).catch((err: BusinessError) => {
  console.error(`Failed to unsubscribe managed event. Code: ${err.code}, message: ${err.message}`);
})
```

## adminManager.authorizeAdmin<sup>10+</sup>

authorizeAdmin(admin: Want, bundleName: string, callback: AsyncCallback&lt;void&gt;): void

Authorizes the administrator rights to an application through the specified device administrator application. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.MANAGE_ENTERPRISE_DEVICE_ADMIN

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager



**Model restriction**: This API can be used only in the stage model.

**Parameters**

| Name  | Type                                 | Mandatory  | Description     |
| ----- | ----------------------------------- | ---- | ------- |
| admin | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | Yes   | Device administrator application.|
| bundleName  | string | Yes| Bundle name of the application to be authorized with the administrator rights.|
| callback | AsyncCallback&lt;void&gt; | Yes| Callback invoked to return the result. If the operation is successful, **err** is **null**. Otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](errorcode-enterpriseDeviceManager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                              |
| ------- | ----------------------------------------------------- |
| 9200001 | The application is not an administrator application of the device. |
| 9200002 | The administrator application does not have permission to manage the device.          |
| 9200009 | Failed to grant the permission to the application. |
| 201 | Permission verification failed. The application does not have the permission required to call the API. |
| 202 | Permission verification failed. A non-system application calls a system API. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**

```ts
import { Want } from '@kit.AbilityKit';
let wantTemp: Want = {
  bundleName: 'bundleName',
  abilityName: 'abilityName',
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

Authorizes the administrator rights to an application through the specified device administrator application. This API uses a promise to return the result.

**Required permissions**: ohos.permission.MANAGE_ENTERPRISE_DEVICE_ADMIN

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager



**Model restriction**: This API can be used only in the stage model.

**Parameters**

| Name  | Type                                 | Mandatory  | Description     |
| ----- | ----------------------------------- | ---- | ------- |
| admin | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | Yes   | Device administrator application.|
| bundleName  | string | Yes| Bundle name of the application to be authorized with the administrator rights.|

**Return value**

| Type  | Description                                 |
| ----- | ----------------------------------- |
| Promise&lt;void&gt; | Promise that returns no value. When the device management application fails to grant the administrator rights to a specified application, an error object is thrown.|

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](errorcode-enterpriseDeviceManager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                              |
| ------- | ----------------------------------------------------- |
| 9200001 | The application is not an administrator application of the device. |
| 9200002 | The administrator application does not have permission to manage the device.          |
| 9200009 | Failed to grant the permission to the application. |
| 201 | Permission verification failed. The application does not have the permission required to call the API. |
| 202 | Permission verification failed. A non-system application calls a system API. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**

```ts
import { Want } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
let wantTemp: Want = {
  bundleName: 'bundleName',
  abilityName: 'abilityName',
};
let bundleName: string = "com.example.application";

adminManager.authorizeAdmin(wantTemp, bundleName).then(() => {
}).catch((err: BusinessError) => {
  console.error(`Failed to authorize permission to the application. Code: ${err.code}, message: ${err.message}`);
})
```

## adminManager.getAdmins<sup>15+</sup>

getAdmins(): Promise&lt;Array&lt;Want&gt;&gt;

Queries all device administrator applications of the current user. This API uses a promise to return the result.

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager



**Model restriction**: This API can be used only in the stage model.


**Return value**

| Type  | Description                                 |
| ----- | ----------------------------------- |
| Promise&lt;Array&lt;Want&gt;&gt; | Promise that contains all activated device administrator applications.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                              |
| ------- | ----------------------------------------------------- |
| 202 | Permission verification failed. A non-system application calls a system API. |

**Example**

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

Replaces a specified application with a super device administrator application.

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager



**Model restriction**: This API can be used only in the stage model.

**Parameters**

| Name           | Type                                 | Mandatory  | Description                          |
| -------------- | ----------------------------------- | ---- | ---------------------------- |
| oldAdmin       | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | Yes   | Old EnterpriseAdminExtensionAbility.                 |
| newAdmin       | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | Yes   | New EnterpriseAdminExtensionAbility.                |
| isKeepPolicy   | boolean                             | Yes   | A Boolean value indicates whether to retain the policy of the old **EnterpriseAdminExtensionAbility**. The value **true** means that the policy is retained, and the value **false** means the opposite.     |

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](errorcode-enterpriseDeviceManager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                              |
| ------- | ----------------------------------------------------- |
| 9200001 | The application is not an administrator application of the device. |
| 9200003 | The administrator ability component is invalid. |
| 9200011 | Failed to replace the administrator application of the device. |
| 201  | Permission verification failed. The application does not have the permission required to call the API. |
| 202  | Permission verification failed. A non-system application calls a system API. |
| 401  | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**

```ts
import { Want } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let oldAdmin: Want = {
  bundleName: 'bundleName',
  abilityName: 'abilityName',
};
let newAdmin: Want = {
  bundleName: 'newBundleName',
  abilityName: 'newAbilityName',
};
try {
  adminManager.replaceSuperAdmin(oldAdmin, newAdmin, false);
  console.info(`Succeeded in replace super admin.`);
} catch(err) {
  console.error(`Failed to replace super admin. Code: ${err.code}, message: ${err.message}`);
}
```

## EnterpriseInfo

Represents the enterprise information of a device administrator application.

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager



| Name        | Type    | Mandatory| Description                           |
| ----------- | --------| ---- | ------------------------------- |
| name        | string   | Yes  | Name of the enterprise.|
| description | string   | Yes  | Description of the enterprise.|

## AdminType

Enumerates the types of device administrator applications.

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager



| Name               | Value | Description   |
| ----------------- | ---- | ----- |
| ADMIN_TYPE_NORMAL | 0x00 | Common administrator application.|
| ADMIN_TYPE_SUPER  | 0x01 | Super administrator application.|
