# @ohos.enterprise.deviceInfo

The **deviceInfo** module provides APIs for enterprise device information management, including the API for obtaining device serial numbers. These APIs can only be called by device administrator applications.

> **NOTE**
>
> The initial APIs of this module are supported since API version 10. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```js
import deviceInfo from '@ohos.enterprise.deviceInfo';
```

## deviceInfo.getDeviceSerial

getDeviceSerial(admin: Want, callback: AsyncCallback&lt;string&gt;): void

Obtains the device serial number. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.ENTERPRISE_GET_DEVICE_INFO

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**System API**: This is a system API.

**Parameters**

| Name     | Type                                      | Mandatory  | Description                      |
| -------- | ---------------------------------------- | ---- | ------------------------------- |
| admin    | [Want](js-apis-app-ability-want.md)     | Yes   | Device administrator application.                 |
| callback | AsyncCallback&lt;string&gt;            | Yes   | Callback used to return the device serial number.      |

**Error codes**

For details about the following error codes, see [Enterprise Device Management Error Codes](../errorcodes/errorcode-enterpriseDeviceManager.md).

| ID| Error Message                                                                      |
| ------- | ---------------------------------------------------------------------------- |
| 9200001 | the application is not an administrator of the device.                        |
| 9200002 | the administrator application does not have permission to manage the device. |

**Example**

```js
let wantTemp = {
    bundleName: "com.example.myapplication",
    abilityName: "com.example.myapplication.MainAbility",
};
deviceInfo.getDeviceSerial(wantTemp, (error, result) => {
    if (error != null) {
        console.log("error code:" + error.code + " error message:" + error.message);
        return;
    }
    console.log(result);
});
```

## deviceInfo.getDeviceSerial

getDeviceSerial(admin: Want): Promise&lt;string&gt;

Obtains the device serial number. This API uses a promise to return the result.

**Required permissions**: ohos.permission.ENTERPRISE_GET_DEVICE_INFO

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**System API**: This is a system API.

**Parameters**

| Name  | Type                                 | Mandatory  | Description     |
| ----- | ----------------------------------- | ---- | ------- |
| admin | [Want](js-apis-app-ability-want.md) | Yes   | Device administrator application.|

**Return value**

| Type                  | Description                     |
| --------------------- | ------------------------- |
| Promise&lt;string&gt; | Promise used to return the device serial number. |

**Error codes**

For details about the following error codes, see [Enterprise Device Management Error Codes](../errorcodes/errorcode-enterpriseDeviceManager.md).

| ID| Error Message                                                                    |
| ------- | ---------------------------------------------------------------------------- |
| 9200001 | the application is not an administrator of the device.                        |
| 9200002 | the administrator application does not have permission to manage the device. |

**Example**

```js
let wantTemp = {
    bundleName: "com.example.myapplication",
    abilityName: "com.example.myapplication.MainAbility",
};
deviceInfo.getDeviceSerial(wantTemp).then((result) => {
    console.log(result);
}).catch(error => {
    console.log("error code:" + error.code + " error message:" + error.message);
});
```

## deviceInfo.getDisplayVersion

getDisplayVersion(admin: Want, callback: AsyncCallback&lt;string&gt;): void;

Obtains the device version number. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.ENTERPRISE_GET_DEVICE_INFO

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**System API**: This is a system API.

**Parameters**

| Name     | Type                                      | Mandatory  | Description                      |
| -------- | ---------------------------------------- | ---- | ------------------------------- |
| admin    | [Want](js-apis-app-ability-want.md)      | Yes   | Device administrator application.                 |
| callback | AsyncCallback&lt;string&gt;            | Yes   | Callback used to return the device version number.      |

**Error codes**

For details about the following error codes, see [Enterprise Device Management Error Codes](../errorcodes/errorcode-enterpriseDeviceManager.md).

| ID| Error Message                                                                      |
| ------- | ---------------------------------------------------------------------------- |
| 9200001 | the application is not an administrator of the device.                        |
| 9200002 | the administrator application does not have permission to manage the device. |

**Example**

```js
let wantTemp = {
    bundleName: "com.example.myapplication",
    abilityName: "com.example.myapplication.MainAbility",
};
deviceInfo.getDisplayVersion(wantTemp, (error, result) => {
    if (error != null) {
        console.log("error code:" + error.code + " error message:" + error.message);
        return;
    }
    console.log(result);
});
```

## deviceInfo.getDisplayVersion

getDisplayVersion(admin: Want): Promise&lt;string&gt;

Obtains the device version number. This API uses a promise to return the result.

**Required permissions**: ohos.permission.ENTERPRISE_GET_DEVICE_INFO

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**System API**: This is a system API.

**Parameters**

| Name  | Type                                 | Mandatory  | Description     |
| ----- | ----------------------------------- | ---- | ------- |
| admin | [Want](js-apis-app-ability-want.md) | Yes   | Device administrator application.|

**Return value**

| Type                  | Description                     |
| --------------------- | ------------------------- |
| Promise&lt;string&gt; | Promise used to return the device version number. |

**Error codes**

For details about the following error codes, see [Enterprise Device Management Error Codes](../errorcodes/errorcode-enterpriseDeviceManager.md).

| ID| Error Message                                                                    |
| ------- | ---------------------------------------------------------------------------- |
| 9200001 | the application is not an administrator of the device.                        |
| 9200002 | the administrator application does not have permission to manage the device. |

**Example**

```js
let wantTemp = {
    bundleName: "com.example.myapplication",
    abilityName: "com.example.myapplication.MainAbility",
};
deviceInfo.getDisplayVersion(wantTemp).then((result) => {
    console.log(result);
}).catch(error => {
    console.log("error code:" + error.code + " error message:" + error.message);
});
```

## deviceInfo.getDeviceName

getDeviceName(admin: Want, callback: AsyncCallback&lt;string&gt;): void

Obtains the device name. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.ENTERPRISE_GET_DEVICE_INFO

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**System API**: This is a system API.

**Parameters**

| Name     | Type                                      | Mandatory  | Description                      |
| -------- | ---------------------------------------- | ---- | ------------------------------- |
| admin    | [Want](js-apis-app-ability-want.md)      | Yes   | Device administrator application.                 |
| callback | AsyncCallback&lt;string&gt;              | Yes   | Callback used to return the device name.      |

**Error codes**

For details about the following error codes, see [Enterprise Device Management Error Codes](../errorcodes/errorcode-enterpriseDeviceManager.md).

| ID| Error Message                                                                      |
| ------- | ---------------------------------------------------------------------------- |
| 9200001 | the application is not an administrator of the device.                        |
| 9200002 | the administrator application does not have permission to manage the device. |

**Example**

```js
let wantTemp = {
    bundleName: "com.example.myapplication",
    abilityName: "com.example.myapplication.MainAbility",
};
deviceInfo.getDeviceName(wantTemp, (error, result) => {
    if (error != null) {
        console.log("error code:" + error.code + " error message:" + error.message);
        return;
    }
    console.log(result);
});
```

## deviceInfo.getDeviceName

getDeviceName(admin: Want): Promise&lt;string&gt;

Obtains the device name. This API uses a promise to return the result.

**Required permissions**: ohos.permission.ENTERPRISE_GET_DEVICE_INFO

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**System API**: This is a system API.

**Parameters**

| Name  | Type                                 | Mandatory  | Description     |
| ----- | ----------------------------------- | ---- | ------- |
| admin | [Want](js-apis-app-ability-want.md) | Yes   | Device administrator application.|

**Return value**

| Type                  | Description                     |
| --------------------- | ------------------------- |
| Promise&lt;string&gt; | Promise used to return the device name. |

**Error codes**

For details about the following error codes, see [Enterprise Device Management Error Codes](../errorcodes/errorcode-enterpriseDeviceManager.md).

| ID| Error Message                                                                    |
| ------- | ---------------------------------------------------------------------------- |
| 9200001 | the application is not an administrator of the device.                        |
| 9200002 | the administrator application does not have permission to manage the device. |

**Example**

```js
let wantTemp = {
    bundleName: "com.example.myapplication",
    abilityName: "com.example.myapplication.MainAbility",
};
deviceInfo.getDeviceName(wantTemp).then((result) => {
    console.log(result);
}).catch(error => {
    console.log("error code:" + error.code + " error message:" + error.message);
});
```
