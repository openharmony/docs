# @ohos.enterprise.dateTimeManager (System Time Management) (System API)

The **dateTimeManager** module provides APIs for system time management.

> **NOTE**
> 
> The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
> The APIs of this module can be used only in the stage model.
>
> The APIs of this module can be called only by a [device administrator application](../../mdm/mdm-kit-guide.md#introduction) that is [enabled](js-apis-enterprise-adminManager-sys.md#adminmanagerenableadmin).
> 
> The APIs provided by this module are system APIs.

## Modules to Import

```ts
import { dateTimeManager } from '@kit.MDMKit';
```

## dateTimeManager.setDateTime

setDateTime(admin: Want, time: number, callback: AsyncCallback\<void>): void

Sets the system time through the specified device administrator application. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.ENTERPRISE_SET_DATETIME

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager


**Parameters**

| Name  | Type                                 | Mandatory  | Description     |
| ----- | ----------------------------------- | ---- | ------- |
| admin | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | Yes   | Device administrator application.|
| time  | number | Yes| Timestamp to set, in ms.|
| callback | AsyncCallback\<void> | Yes| Callback invoked to return the result. If the operation is successful, **err** is **null**. Otherwise, **err** is an error object.|

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

Sets the system time through the specified device administrator application. This API uses a promise to return the result.

**Required permissions**: ohos.permission.ENTERPRISE_SET_DATETIME

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager


**Parameters**

| Name  | Type                                 | Mandatory  | Description     |
| ----- | ----------------------------------- | ---- | ------- |
| admin | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | Yes   | Device administrator application.|
| time  | number | Yes| Timestamp to set, in ms.|

**Return value**

| Type  | Description                                 |
| ----- | ----------------------------------- |
| Promise\<void> | Promise that returns no value.|

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
  bundleName: 'bundleName',
  abilityName: 'abilityName',
};

dateTimeManager.setDateTime(wantTemp, 1526003846000).then(() => {
  console.info('Succeeded in setting date time');
}).catch((err: BusinessError) => {
  console.error(`Failed to set date time. Code is ${err.code}, message is ${err.message}`);
})
```

## dateTimeManager.disallowModifyDateTime<sup>10+</sup>

disallowModifyDateTime(admin: Want, disallow: boolean, callback: AsyncCallback\<void>): void

Forbids the specified device administrator application to modify the system time. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.ENTERPRISE_SET_DATETIME

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager


**Parameters**

| Name  | Type                                 | Mandatory  | Description     |
| ----- | ----------------------------------- | ---- | ------- |
| admin | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | Yes   | Device administrator application.|
| disallow  | boolean | Yes| Whether to disallow modification of the system time. The value **true** means to disallow modification of the system time, and **false** means the opposite.|
| callback | AsyncCallback\<void> | Yes| Callback invoked to return the result. If the operation is successful, **err** is **null**. Otherwise, **err** is an error object.|

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

Forbids the specified device administrator application to modify the system time. This API uses a promise to return the result.

**Required permissions**: ohos.permission.ENTERPRISE_SET_DATETIME

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager


**Parameters**

| Name  | Type                                 | Mandatory  | Description     |
| ----- | ----------------------------------- | ---- | ------- |
| admin | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | Yes   | Device administrator application.|
| disallow  | boolean | Yes| Whether to disallow modification of the system time. The value **true** means to disallow modification of the system time, and **false** means the opposite.|

**Return value**

| Type  | Description                                 |
| ----- | ----------------------------------- |
| Promise\<void> | Promise that returns no value. If the operation fails, an error object will be thrown.|

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
  bundleName: 'bundleName',
  abilityName: 'abilityName',
};

dateTimeManager.disallowModifyDateTime(wantTemp, true).then(() => {
  console.info('Succeeded in disallowing modify date time');
}).catch((err: BusinessError) => {
  console.error(`Failed to disallow modify date time. Code is ${err.code}, message is ${err.message}`);
})
```

## dateTimeManager.isModifyDateTimeDisallowed<sup>10+</sup>

isModifyDateTimeDisallowed(admin: Want, callback: AsyncCallback\<boolean>): void

Checks whether the system time modification is disallowed through the specified device administrator application. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.ENTERPRISE_SET_DATETIME

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager


**Parameters**

| Name  | Type                                 | Mandatory  | Description     |
| ----- | ----------------------------------- | ---- | ------- |
| admin | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | Yes   | Device administrator application.|
| callback | AsyncCallback\<boolean> | Yes| Callback invoked to return the result. The value **true** means the system time modification is disallowed, and **false** means the opposite.|

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

Checks whether the system time modification is disallowed through the specified device administrator application. This API uses a promise to return the result.

**Required permissions**: ohos.permission.ENTERPRISE_SET_DATETIME

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager


**Parameters**

| Name  | Type                                 | Mandatory  | Description     |
| ----- | ----------------------------------- | ---- | ------- |
| admin | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | Yes   | Device administrator application.|

**Return value**

| Type  | Description                                 |
| ----- | ----------------------------------- |
| Promise\<boolean> | Promise used to return the result. The value **true** means the system time modification is disallowed, and **false** means the opposite.|

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
  bundleName: 'bundleName',
  abilityName: 'abilityName',
};

dateTimeManager.isModifyDateTimeDisallowed(wantTemp).then((result) => {
  console.info(`Succeeded in querying modify date time is disallowed : ${result}`);
}).catch((err: BusinessError) => {
  console.error(`Failed to query modify date time is disallowed or not. Code is ${err.code}, message is ${err.message}`);
})
```
