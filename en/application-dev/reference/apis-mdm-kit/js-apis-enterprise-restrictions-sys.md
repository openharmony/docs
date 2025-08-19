# @ohos.enterprise.restrictions (Restrictions) (System API)

This **restrictions** module provides APIs for setting general restriction policies, including disabling or enabling the printer and OpenHarmony Device Connector (hdc) for devices.

> **NOTE**
> 
> - The initial APIs of this module are supported since API version 10. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
> - The APIs of this module can be used only in the stage model.
>
> - The APIs of this module can be called only by a [device administrator application](../../mdm/mdm-kit-guide.md#introduction) that is [enabled](js-apis-enterprise-adminManager-sys.md#adminmanagerenableadmin-2).
> 
> - This topic describes only the system APIs provided by the module. For details about its public APIs, see [@ohos.enterprise.restrictions](js-apis-enterprise-restrictions.md).

## Modules to Import

```ts
import { restrictions } from '@kit.MDMKit';
```

## restrictions.setPrinterDisabled

setPrinterDisabled(admin: Want, disabled: boolean, callback: AsyncCallback\<void>): void

Enables or disables the printing capability of the device. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.ENTERPRISE_RESTRICT_POLICY

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Parameters**

| Name  | Type                                 | Mandatory  | Description     |
| ----- | ----------------------------------- | ---- | ------- |
| admin | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | Yes   | EnterpriseAdminExtensionAbility.|
| disabled  | boolean | Yes| Operation to perform. The value **true** means to disable the printer; the value **false** means the opposite.|
| callback | AsyncCallback\<void> | Yes| Callback invoked to return the result. <br>If the operation is successful, **err** is **null**. Otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](errorcode-enterpriseDeviceManager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                                     |
| ------- | ---------------------------------------------------------------------------- |
| 9200001 | The application is not an administrator application of the device.           |
| 9200002 | The administrator application does not have permission to manage the device. |
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

Enables or disables the printing capability of the device. This API uses a promise to return the result.

**Required permissions**: ohos.permission.ENTERPRISE_RESTRICT_POLICY

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Parameters**

| Name  | Type                                 | Mandatory  | Description     |
| ----- | ----------------------------------- | ---- | ------- |
| admin | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | Yes   | EnterpriseAdminExtensionAbility.|
| disabled  | boolean | Yes| Operation to perform. The value **true** means to disable the printer; the value **false** means the opposite.|

**Return value**

| Type  | Description                                 |
| ----- | ----------------------------------- |
| Promise\<void> | Promise that returns no value. An error object is thrown when the print capability fails to be disabled or enabled.|

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](errorcode-enterpriseDeviceManager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                                     |
| ------- | ---------------------------------------------------------------------------- |
| 9200001 | The application is not an administrator application of the device.            |
| 9200002 | The administrator application does not have permission to manage the device. |
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

restrictions.setPrinterDisabled(wantTemp, true).then(() => {
  console.info('Succeeded in setting printer disabled');
}).catch((err: BusinessError) => {
  console.error(`Failed to set printer disabled. Code is ${err.code}, message is ${err.message}`);
})
```

## restrictions.isPrinterDisabled

isPrinterDisabled(admin: Want, callback: AsyncCallback\<boolean>): void

Queries whether the printing capability of a device is disabled. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.ENTERPRISE_RESTRICT_POLICY

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Parameters**

| Name  | Type                                 | Mandatory  | Description     |
| ----- | ----------------------------------- | ---- | ------- |
| admin | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | Yes   | EnterpriseAdminExtensionAbility.|
| callback | AsyncCallback\<boolean> | Yes| Callback invoked to return the result.<br>The value **true** means that the printer is disabled; the value **false** means the opposite.|

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](errorcode-enterpriseDeviceManager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                                     |
| ------- | ---------------------------------------------------------------------------- |
| 9200001 | The application is not an administrator application of the device.           |
| 9200002 | The administrator application does not have permission to manage the device. |
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

Queries whether the printing capability of a device is disabled. This API uses a promise to return the result.

**Required permissions**: ohos.permission.ENTERPRISE_RESTRICT_POLICY

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Parameters**

| Name| Type                                                   | Mandatory| Description                                  |
| ------ | ------------------------------------------------------- | ---- | -------------------------------------- |
| admin  | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | Yes  | EnterpriseAdminExtensionAbility.|

**Return value**

| Type  | Description                                 |
| ----- | ----------------------------------- |
| Promise\<boolean> | Promise used to return the result. The value **true** means that the printer is disabled; the value **false** means the opposite.|

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](errorcode-enterpriseDeviceManager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                                     |
| ------- | ---------------------------------------------------------------------------- |
| 9200001 | The application is not an administrator application of the device.            |
| 9200002 | The administrator application does not have permission to manage the device. |
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

restrictions.isPrinterDisabled(wantTemp).then((result) => {
  console.info(`Succeeded in querying is the printing function disabled : ${result}`);
}).catch((err: BusinessError) => {
  console.error(`Failed to query is the printing function disabled or not. Code is ${err.code}, message is ${err.message}`);
})
```

## restrictions.setHdcDisabled

setHdcDisabled(admin: Want, disabled: boolean, callback: AsyncCallback\<void>): void

Enables or disables [HDC](../../../device-dev/subsystems/subsys-toolchain-hdc-guide.md#hdc). This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.ENTERPRISE_RESTRICT_POLICY

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Parameters**

| Name  | Type                                 | Mandatory  | Description     |
| ----- | ----------------------------------- | ---- | ------- |
| admin | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | Yes   | EnterpriseAdminExtensionAbility.|
| disabled  | boolean | Yes| Operation to perform. The value **true** means to disable HDC; the value **false** means the opposite.|
| callback | AsyncCallback\<void> | Yes| Callback invoked to return the result. <br>If the operation is successful, **err** is **null**. Otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](errorcode-enterpriseDeviceManager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                                     |
| ------- | ---------------------------------------------------------------------------- |
| 9200001 | The application is not an administrator application of the device.           |
| 9200002 | The administrator application does not have permission to manage the device. |
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

Enables or disables HDC on a device. This API uses a promise to return the result.

**Required permissions**: ohos.permission.ENTERPRISE_RESTRICT_POLICY

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Parameters**

| Name  | Type                                 | Mandatory  | Description     |
| ----- | ----------------------------------- | ---- | ------- |
| admin | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | Yes   | EnterpriseAdminExtensionAbility.|
| disabled  | boolean | Yes| Operation to perform. The value **true** means to disable HDC; the value **false** means the opposite.|

**Return value**

| Type  | Description                                 |
| ----- | ----------------------------------- |
| Promise\<void> | Promise that returns no value. An error object is thrown when the HDC fails to be disabled or enabled.|

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](errorcode-enterpriseDeviceManager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                                     |
| ------- | ---------------------------------------------------------------------------- |
| 9200001 | The application is not an administrator application of the device.            |
| 9200002 | The administrator application does not have permission to manage the device. |
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

restrictions.setHdcDisabled(wantTemp, true).then(() => {
  console.info('Succeeded in setting hdc disabled');
}).catch((err: BusinessError) => {
  console.error(`Failed to set hdc disabled. Code is ${err.code}, message is ${err.message}`);
})
```

## restrictions.isHdcDisabled

isHdcDisabled(admin: Want, callback: AsyncCallback\<boolean>): void

Queries whether HDC is disabled. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.ENTERPRISE_RESTRICT_POLICY

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Parameters**

| Name  | Type                                 | Mandatory  | Description     |
| ----- | ----------------------------------- | ---- | ------- |
| admin | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | Yes   | EnterpriseAdminExtensionAbility.|
| callback | AsyncCallback\<boolean> | Yes| Callback invoked to return the result.<br>The value **true** means HDC is disabled; the value **false** means the opposite.|

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](errorcode-enterpriseDeviceManager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                                     |
| ------- | ---------------------------------------------------------------------------- |
| 9200001 | The application is not an administrator application of the device.           |
| 9200002 | The administrator application does not have permission to manage the device. |
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

Queries whether HDC is disabled. This API uses a promise to return the result.

**Required permissions**: ohos.permission.ENTERPRISE_RESTRICT_POLICY

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Parameters**

| Name| Type                                                   | Mandatory| Description                                  |
| ------ | ------------------------------------------------------- | ---- | -------------------------------------- |
| admin  | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | Yes  | EnterpriseAdminExtensionAbility.|

**Return value**

| Type  | Description                                 |
| ----- | ----------------------------------- |
| Promise\<boolean> | Promise used to return the result. The value **true** means HDC is disabled; the value **false** means the opposite.|

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](errorcode-enterpriseDeviceManager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                                     |
| ------- | ---------------------------------------------------------------------------- |
| 9200001 | The application is not an administrator application of the device.            |
| 9200002 | The administrator application does not have permission to manage the device. |
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

restrictions.isHdcDisabled(wantTemp).then((result) => {
  console.info(`Succeeded in querying is hdc disabled : ${result}`);
}).catch((err: BusinessError) => {
  console.error(`Failed to query is hdc disabled or not. Code is ${err.code}, message is ${err.message}`);
})
```

## restrictions.isMicrophoneDisabled<sup>11+</sup>

isMicrophoneDisabled(admin: Want): boolean

Queries whether the microphone is disabled.

**Required permissions**: ohos.permission.ENTERPRISE_MANAGE_RESTRICTIONS

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Parameters**

| Name| Type                                                   | Mandatory| Description                                  |
| ------ | ------------------------------------------------------- | ---- | -------------------------------------- |
| admin  | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | Yes  | EnterpriseAdminExtensionAbility.|

**Return value**

| Type  | Description                                 |
| ----- | ----------------------------------- |
| boolean | Returns **true** if the microphone is disabled; returns **false** otherwise.|

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](errorcode-enterpriseDeviceManager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                                     |
| ------- | ---------------------------------------------------------------------------- |
| 9200001 | The application is not an administrator application of the device.           |
| 9200002 | The administrator application does not have permission to manage the device. |
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

try {
  let result = restrictions.isMicrophoneDisabled(wantTemp);
  console.info(`Succeeded in querying is microphone disabled : ${result}`);
} catch (err) {
  console.error(`Failed to query is microphone disabled or not. Code is ${err.code}, message is ${err.message}`);
}
```

## restrictions.disableMicrophone<sup>11+</sup>

disableMicrophone(admin: Want, disable: boolean): void

Enables or disables the microphone.

**Required permissions**: ohos.permission.ENTERPRISE_MANAGE_RESTRICTIONS

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Parameters**

| Name  | Type                                 | Mandatory  | Description     |
| ----- | ----------------------------------- | ---- | ------- |
| admin | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | Yes   | EnterpriseAdminExtensionAbility.|
| disable  | boolean | Yes| Operation to perform. The value **true** means to disable the microphone; the value **false** means the opposite.|

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](errorcode-enterpriseDeviceManager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                                     |
| ------- | ---------------------------------------------------------------------------- |
| 9200001 | The application is not an administrator application of the device.            |
| 9200002 | The administrator application does not have permission to manage the device. |
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

try {
  restrictions.disableMicrophone(wantTemp, true);
  console.info('Succeeded in setting microphone disabled');
} catch (err) {
  console.error(`Failed to disable microphone. Code is ${err.code}, message is ${err.message}`);
}
```

## restrictions.setFingerprintAuthDisabled<sup>11+</sup>

setFingerprintAuthDisabled(admin: Want, disabled: boolean): void

Enables or disables fingerprint authentication.

**Required permissions**: ohos.permission.ENTERPRISE_MANAGE_RESTRICTIONS

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Parameters**

| Name  | Type                                 | Mandatory  | Description     |
| ----- | ----------------------------------- | ---- | ------- |
| admin | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | Yes   | EnterpriseAdminExtensionAbility.|
| disabled  | boolean | Yes| Operation to perform. The value **true** means to disable fingerprint authentication; the value **false** the opposite.|

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](errorcode-enterpriseDeviceManager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                                     |
| ------- | ---------------------------------------------------------------------------- |
| 9200001 | The application is not an administrator application of the device.            |
| 9200002 | The administrator application does not have permission to manage the device. |
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

try {
  restrictions.setFingerprintAuthDisabled(wantTemp, true);
  console.info('Succeeded in disabling the fingerprint auth');
} catch (err) {
  console.error(`Failed to disable fingerprint auth. Code: ${err.code}, message: ${err.message}`);
};

```

## restrictions.isFingerprintAuthDisabled<sup>11+</sup>

isFingerprintAuthDisabled(admin: Want): boolean

Queries whether fingerprint authentication is disabled.

**Required permissions**: ohos.permission.ENTERPRISE_MANAGE_RESTRICTIONS

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Parameters**

| Name| Type                                                   | Mandatory| Description                                  |
| ------ | ------------------------------------------------------- | ---- | -------------------------------------- |
| admin  | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | Yes  | EnterpriseAdminExtensionAbility.|

**Return value**

| Type  | Description                                 |
| ----- | ----------------------------------- |
| boolean | Returns **true** if fingerprint authentication is disabled; returns **false** otherwise.|

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](errorcode-enterpriseDeviceManager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                                     |
| ------- | ---------------------------------------------------------------------------- |
| 9200001 | The application is not an administrator application of the device.            |
| 9200002 | The administrator application does not have permission to manage the device. |
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

try {
  let result: boolean = restrictions.isFingerprintAuthDisabled(wantTemp);
  console.info(`Succeeded in getting the state of fingerprint auth. result : ${result}`);
} catch (err) {
  console.error(`Failed to get the state of fingerprint auth. Code: ${err.code}, message: ${err.message}`);
};
```
