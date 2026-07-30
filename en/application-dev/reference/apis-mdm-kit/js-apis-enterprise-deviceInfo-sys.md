# @ohos.enterprise.deviceInfo (Device Information Management) (System API)
<!--Kit: MDM Kit-->
<!--Subsystem: Customization-->
<!--Owner: @huanleima; @weizai16-->
<!--Designer: @hp_guo-->
<!--Tester: @lpw_work-->
<!--Adviser: @zhang_yixin13-->

The **deviceInfo** module provides APIs for enterprise device information management, including obtaining device serial numbers and device names.

> **NOTE**
>
> The initial APIs of this module are supported since API version 10. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
> The APIs of this module can be used only in the stage model.
>
> The APIs of this module are available only to the [MDM application](../../mdm/mdm-kit-term.md#mdm-application-device-administrator-application), and can be called only after the device administrator application is activated via [enableAdmin](js-apis-enterprise-adminManager-sys.md#adminmanagerenableadmin-2).
> 
> This topic describes only system APIs provided by the module. For details about its public APIs, see [@ohos.enterprise.deviceInfo](js-apis-enterprise-deviceInfo.md).

## Modules to Import

```ts
import { deviceInfo } from '@kit.MDMKit';
```

## deviceInfo.getDeviceSerial<sup>(deprecated)</sup>

getDeviceSerial(admin: Want, callback: AsyncCallback&lt;string&gt;): void

Obtains the device serial number. This API uses an asynchronous callback to return the result.

**Deprecated since:** 26.0.0

**Substitutes:** [getDeviceInfo](./js-apis-enterprise-deviceInfo.md#deviceinfogetdeviceinfo)

**Required permissions**: ohos.permission.ENTERPRISE_GET_DEVICE_INFO

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Model restriction**: This API can be used only in the stage model.

**System API**: This is a system API.

**Parameters**

| Name     | Type                                      | Mandatory  | Description                      |
| -------- | ---------------------------------------- | ---- | ------------------------------- |
| admin    | [Want](../apis-ability-kit/js-apis-app-ability-want.md)     | Yes   | EnterpriseAdminExtensionAbility. **Want** must contain the ability name of the EnterpriseAdminExtensionAbility and the bundle name of the application.                 |
| callback | AsyncCallback&lt;string&gt;            | Yes   | Callback invoked to return the result. If the operation is successful, **err** is **null** and **data** is the device serial number obtained. If the operation fails, **err** is an error object.      |

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](errorcode-enterpriseDeviceManager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                                      |
| ------- | ---------------------------------------------------------------------------- |
| 9200001 | The application is not an administrator application of the device.            |
| 9200002 | The administrator application does not have permission to manage the device. |
| 201 | Permission verification failed. The application does not have the permission required to call the API. |
| 202 | Permission verification failed. A non-system application calls a system API. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**

```ts
import { deviceInfo } from '@kit.MDMKit';
import { Want } from '@kit.AbilityKit';

let wantTemp: Want = {
  // Replace with actual values.
  bundleName: 'com.example.myapplication',
  abilityName: 'EnterpriseAdminAbility'
};

deviceInfo.getDeviceSerial(wantTemp, (err, result) => {
  if (err) {
    console.error(`Failed to get device serial. Code: ${err.code}, message: ${err.message}`);
    return;
  }
  console.info(`Succeeded in getting device serial, result : ${result}`);
});
```

## deviceInfo.getDeviceSerial<sup>(deprecated)</sup>

getDeviceSerial(admin: Want): Promise&lt;string&gt;

Obtains the device serial number. This API uses a promise to return the result.

**Deprecated since:** 26.0.0

**Substitutes:** [getDeviceInfo](./js-apis-enterprise-deviceInfo.md#deviceinfogetdeviceinfo)

**Required permissions**: ohos.permission.ENTERPRISE_GET_DEVICE_INFO

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Model restriction**: This API can be used only in the stage model.

**System API**: This is a system API.

**Parameters**

| Name  | Type                                 | Mandatory  | Description     |
| ----- | ----------------------------------- | ---- | ------- |
| admin | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | Yes   | EnterpriseAdminExtensionAbility. **Want** must contain the ability name of the EnterpriseAdminExtensionAbility and the bundle name of the application.|

**Return value**

| Type                  | Description                     |
| --------------------- | ------------------------- |
| Promise&lt;string&gt; | Promise used to return the device serial number. |

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](errorcode-enterpriseDeviceManager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                                    |
| ------- | ---------------------------------------------------------------------------- |
| 9200001 | The application is not an administrator application of the device.            |
| 9200002 | The administrator application does not have permission to manage the device. |
| 201 | Permission verification failed. The application does not have the permission required to call the API. |
| 202 | Permission verification failed. A non-system application calls a system API. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**

```ts
import { deviceInfo } from '@kit.MDMKit';
import { Want } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let wantTemp: Want = {
  // Replace with actual values.
  bundleName: 'com.example.myapplication',
  abilityName: 'EnterpriseAdminAbility'
};

deviceInfo.getDeviceSerial(wantTemp).then((result) => {
  console.info(`Succeeded in getting device serial, result : ${result}`);
}).catch((err: BusinessError) => {
  console.error(`Failed to get device serial. Code: ${err.code}, message: ${err.message}`);
});
```

## deviceInfo.getDisplayVersion<sup>(deprecated)</sup>

getDisplayVersion(admin: Want, callback: AsyncCallback&lt;string&gt;): void

Obtains the device version number. This API uses an asynchronous callback to return the result.

**Deprecated since:** 26.0.0

**Substitutes:** [getDeviceInfo](./js-apis-enterprise-deviceInfo.md#deviceinfogetdeviceinfo)

**Required permissions**: ohos.permission.ENTERPRISE_GET_DEVICE_INFO

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Model restriction**: This API can be used only in the stage model.

**System API**: This is a system API.

**Parameters**

| Name     | Type                                      | Mandatory  | Description                      |
| -------- | ---------------------------------------- | ---- | ------------------------------- |
| admin    | [Want](../apis-ability-kit/js-apis-app-ability-want.md)      | Yes   | EnterpriseAdminExtensionAbility. **Want** must contain the ability name of the EnterpriseAdminExtensionAbility and the bundle name of the application.                 |
| callback | AsyncCallback&lt;string&gt;            | Yes   | Callback invoked to return the result. If the operation is successful, **err** is **null** and **data** is the device version number obtained. If the operation fails, **err** is an error object.      |

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](errorcode-enterpriseDeviceManager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                                      |
| ------- | ---------------------------------------------------------------------------- |
| 9200001 | The application is not an administrator application of the device.            |
| 9200002 | The administrator application does not have permission to manage the device. |
| 201 | Permission verification failed. The application does not have the permission required to call the API. |
| 202 | Permission verification failed. A non-system application calls a system API. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**

```ts
import { deviceInfo } from '@kit.MDMKit';
import { Want } from '@kit.AbilityKit';

let wantTemp: Want = {
  // Replace with actual values.
  bundleName: 'com.example.myapplication',
  abilityName: 'EnterpriseAdminAbility'
};

deviceInfo.getDisplayVersion(wantTemp, (err, result) => {
  if (err) {
    console.error(`Failed to get display version. Code: ${err.code}, message: ${err.message}`);
    return;
  }
  console.info(`Succeeded in getting display version, result : ${result}`);
});
```

## deviceInfo.getDisplayVersion<sup>(deprecated)</sup>

getDisplayVersion(admin: Want): Promise&lt;string&gt;

Obtains the device version number. This API uses a promise to return the result.

**Deprecated since:** 26.0.0

**Substitutes:** [getDeviceInfo](./js-apis-enterprise-deviceInfo.md#deviceinfogetdeviceinfo)

**Required permissions**: ohos.permission.ENTERPRISE_GET_DEVICE_INFO

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Model restriction**: This API can be used only in the stage model.

**System API**: This is a system API.

**Parameters**

| Name  | Type                                 | Mandatory  | Description     |
| ----- | ----------------------------------- | ---- | ------- |
| admin | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | Yes   | EnterpriseAdminExtensionAbility. **Want** must contain the ability name of the EnterpriseAdminExtensionAbility and the bundle name of the application.|

**Return value**

| Type                  | Description                     |
| --------------------- | ------------------------- |
| Promise&lt;string&gt; | Promise used to return the device version number.|

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](errorcode-enterpriseDeviceManager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                                    |
| ------- | ---------------------------------------------------------------------------- |
| 9200001 | The application is not an administrator application of the device.            |
| 9200002 | The administrator application does not have permission to manage the device. |
| 201 | Permission verification failed. The application does not have the permission required to call the API. |
| 202 | Permission verification failed. A non-system application calls a system API. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**

```ts
import { deviceInfo } from '@kit.MDMKit';
import { Want } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let wantTemp: Want = {
  // Replace with actual values.
  bundleName: 'com.example.myapplication',
  abilityName: 'EnterpriseAdminAbility'
};

deviceInfo.getDisplayVersion(wantTemp).then((result) => {
  console.info(`Succeeded in getting display version, result : ${result}`);
}).catch((err: BusinessError) => {
  console.error(`Failed to get display version. Code: ${err.code}, message: ${err.message}`);
});
```

## deviceInfo.getDeviceName<sup>(deprecated)</sup>

getDeviceName(admin: Want, callback: AsyncCallback&lt;string&gt;): void

Obtains the device name. This API uses an asynchronous callback to return the result.

**Deprecated since:** 26.0.0

**Substitutes:** [getDeviceInfo](./js-apis-enterprise-deviceInfo.md#deviceinfogetdeviceinfo)

**Required permissions**: ohos.permission.ENTERPRISE_GET_DEVICE_INFO

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Model restriction**: This API can be used only in the stage model.

**System API**: This is a system API.

**Parameters**

| Name     | Type                                      | Mandatory  | Description                      |
| -------- | ---------------------------------------- | ---- | ------------------------------- |
| admin    | [Want](../apis-ability-kit/js-apis-app-ability-want.md)      | Yes   | EnterpriseAdminExtensionAbility. **Want** must contain the ability name of the EnterpriseAdminExtensionAbility and the bundle name of the application.                 |
| callback | AsyncCallback&lt;string&gt;              | Yes   | Callback invoked to return the result. If the operation is successful, **err** is **null** and **data** is the device name obtained. If the operation fails, **err** is an error object.      |

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](errorcode-enterpriseDeviceManager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                                      |
| ------- | ---------------------------------------------------------------------------- |
| 9200001 | The application is not an administrator application of the device.            |
| 9200002 | The administrator application does not have permission to manage the device. |
| 201 | Permission verification failed. The application does not have the permission required to call the API. |
| 202 | Permission verification failed. A non-system application calls a system API. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**

```ts
import { deviceInfo } from '@kit.MDMKit';
import { Want } from '@kit.AbilityKit';

let wantTemp: Want = {
  // Replace with actual values.
  bundleName: 'com.example.myapplication',
  abilityName: 'EnterpriseAdminAbility'
};

deviceInfo.getDeviceName(wantTemp, (err, result) => {
  if (err) {
    console.error(`Failed to get device name. Code: ${err.code}, message: ${err.message}`);
    return;
  }
  console.info(`Succeeded in getting device name, result : ${result}`);
});
```

## deviceInfo.getDeviceName<sup>(deprecated)</sup>

getDeviceName(admin: Want): Promise&lt;string&gt;

Obtains the device name. This API uses a promise to return the result.

**Deprecated since:** 26.0.0

**Substitutes:** [getDeviceInfo](./js-apis-enterprise-deviceInfo.md#deviceinfogetdeviceinfo)

**Required permissions**: ohos.permission.ENTERPRISE_GET_DEVICE_INFO

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Model restriction**: This API can be used only in the stage model.

**System API**: This is a system API.

**Parameters**

| Name  | Type                                 | Mandatory  | Description     |
| ----- | ----------------------------------- | ---- | ------- |
| admin | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | Yes   | EnterpriseAdminExtensionAbility. **Want** must contain the ability name of the EnterpriseAdminExtensionAbility and the bundle name of the application.|

**Return value**

| Type                  | Description                     |
| --------------------- | ------------------------- |
| Promise&lt;string&gt; | Promise used to return the device name.|

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](errorcode-enterpriseDeviceManager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                                    |
| ------- | ---------------------------------------------------------------------------- |
| 9200001 | The application is not an administrator application of the device.            |
| 9200002 | The administrator application does not have permission to manage the device. |
| 201 | Permission verification failed. The application does not have the permission required to call the API. |
| 202 | Permission verification failed. A non-system application calls a system API. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**

```ts
import { deviceInfo } from '@kit.MDMKit';
import { Want } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let wantTemp: Want = {
  // Replace with actual values.
  bundleName: 'com.example.myapplication',
  abilityName: 'EnterpriseAdminAbility'
};

deviceInfo.getDeviceName(wantTemp).then((result) => {
  console.info(`Succeeded in getting device name, result : ${result}`);
}).catch((err: BusinessError) => {
  console.error(`Failed to get device name. Code: ${err.code}, message: ${err.message}`);
});
```
