# @ohos.enterprise.deviceSettings (Device Settings Management)

The **deviceSettings** module provides APIs for setting enterprise devices, including obtaining the screen-off time of a device.

> **NOTE**
>
> The initial APIs of this module are supported since API version 10. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
> The APIs of this module can be used only in the stage model.
>
> The APIs provided by this module can be called only by a [device administrator application](enterpriseDeviceManagement-overview.md#basic-concepts) that is [enabled](js-apis-enterprise-adminManager.md#adminmanagerenableadmin).

## Modules to Import

```js
import deviceSettings from '@ohos.enterprise.deviceSettings';
```

## deviceSettings.getScreenOffTime

getScreenOffTime(admin: Want, callback: AsyncCallback&lt;number&gt;): void

Obtains the device screen-off time through the specified device administrator application. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.ENTERPRISE_GET_SETTINGS

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**System API**: This is a system API.

**Parameters**

| Name     | Type                                      | Mandatory  | Description                      |
| -------- | ---------------------------------------- | ---- | ------------------------------- |
| admin    | [Want](js-apis-app-ability-want.md)     | Yes   | Device administrator application.                 |
| callback | AsyncCallback&lt;number&gt;            | Yes   | Callback invoked to return the result. If the operation is successful, **err** is **null** and **data** is the device screen-off time obtained. Otherwise, **err** is an error object.      |

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](../errorcodes/errorcode-enterpriseDeviceManager.md).

| ID| Error Message                                                                      |          
| ------- | ---------------------------------------------------------------------------- |
| 9200001 | the application is not an administrator of the device.                        |
| 9200002 | the administrator application does not have permission to manage the device. |

**Example**

```js
let wantTemp = {
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility',
};

deviceSettings.getScreenOffTime(wantTemp, (err, result) => {
  if (err) {
    console.error(`Failed to get screen off time. Code: ${err.code}, message: ${err.message}`);
    return;
  }
  console.info(`Succeeded in getting screen off time, result : ${result}`);
});
```

## deviceSettings.getScreenOffTime

getScreenOffTime(admin: Want): Promise&lt;number&gt;

Obtains the device screen-off time through the specified device administrator application. This API uses a promise to return the result.

**Required permissions**: ohos.permission.ENTERPRISE_GET_SETTINGS

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**System API**: This is a system API.

**Parameters**

| Name  | Type                                 | Mandatory  | Description     |
| ----- | ----------------------------------- | ---- | ------- |
| admin | [Want](js-apis-app-ability-want.md) | Yes   | Device administrator application.|

**Return value**

| Type                  | Description                     |
| --------------------- | ------------------------- |
| Promise&lt;number&gt; | Promise used to return the device screen-off time. |

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](../errorcodes/errorcode-enterpriseDeviceManager.md).

| ID| Error Message                                                                    |          
| ------- | ---------------------------------------------------------------------------- |
| 9200001 | the application is not an administrator of the device.                        |
| 9200002 | the administrator application does not have permission to manage the device. |

**Example**

```js
let wantTemp = {
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility',
};

deviceSettings.getScreenOffTime(wantTemp).then((result) => {
  console.info(`Succeeded in getting screen off time, result : ${result}`);
}).catch((err) => {
  console.error(`Failed to get screen off time. Code: ${err.code}, message: ${err.message}`);
});
```
