# Device Settings Management

The **EnterpriseDeviceManager** module provides capabilities to manage device settings, such as time settings. The APIs of this module can only be called by enterprise device administrator applications.

> **NOTE**
> 
> The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Usage

Before calling any API in **EnterpriseDeviceManager**, use **getDeviceSettingsManager** to create an **EnterpriseDeviceManager** instance.

```js
import enterpriseDeviceManager from '@ohos.enterpriseDeviceManager'

enterpriseDeviceManager.getDeviceSettingsManager((error, mgr) => {
    if (error) {
        console.log("error code:" + error.code + " error message:" + error.message);
        return;
    }
    let deviceMgr = mgr;
});
```

## DeviceSettingsManager.setDateTime

setDateTime(admin: Want, time: number, callback: AsyncCallback\<void>): void

Sets the system time. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.ENTERPRISE_SET_DATETIME

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**System API**: This is a system API.

**Parameters**

| Name  | Type                                 | Mandatory  | Description     |
| ----- | ----------------------------------- | ---- | ------- |
| admin | [Want](js-apis-application-Want.md) | Yes   | Device administrator application.|
| time  | number | Yes| Timestamp (ms).|
| callback | AsyncCallback\<void> | Yes| Callback used to the result. If the system time is set successfully, **err** is **null**; otherwise, **err** is an error object.|

**Error codes**

| Type     | Description                                                                        |
| ------- | ---------------------------------------------------------------------------- |
| 9200001 | The application is not a administrator of the device.                        |
| 9200002 | The administrator application does not have permission to manage the device. |

**Example**

```js
import enterpriseDeviceManager from '@ohos.enterpriseDeviceManager'

let wantTemp = {
    bundleName: "bundleName",
    abilityName: "abilityName",
};
enterpriseDeviceManager.getDeviceSettingsManager((error, mgr) => {
    if (error) {
        console.log("error code:" + error.code + " error message:" + error.message);
        return;
    }
    mgr.setDateTime(wantTemp, 1526003846000, (error) => {
        if (error) {
            console.log("error code:" + error.code + " error message:" + error.message);
        }
    });
});
```

## DeviceSettingsManager.setDateTime

setDateTime(admin: Want, time: number): Promise\<void>

Sets the system time. This API uses a promise to return the result.

**Required permissions**: ohos.permission.ENTERPRISE_SET_DATETIME

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**System API**: This is a system API.

**Parameters**

| Name  | Type                                 | Mandatory  | Description     |
| ----- | ----------------------------------- | ---- | ------- |
| admin | [Want](js-apis-application-Want.md) | Yes   | Device administrator application.|
| time  | number | Yes| Timestamp (ms).|

**Return value**

| Type  | Description                                 |
| ----- | ----------------------------------- |
| Promise\<void> | Promise that returns no value.|

**Error codes**

| Type     | Description                                                                        |
| ------- | ---------------------------------------------------------------------------- |
| 9200001 | The application is not a administrator of the device.                        |
| 9200002 | The administrator application does not have permission to manage the device. |

**Example**

```js
import enterpriseDeviceManager from '@ohos.enterpriseDeviceManager'

let wantTemp = {
    bundleName: "bundleName",
    abilityName: "abilityName",
};
enterpriseDeviceManager.getDeviceSettingsManager().then((mgr) => {
    mgr.setDateTime(wantTemp, 1526003846000).then(() => {
    }).catch((error) => {
        console.log("error code:" + error.code + " error message:" + error.message);
    })
}).catch((error) => {
    console.log("error code:" + error.code + " error message:" + error.message);
})
```
