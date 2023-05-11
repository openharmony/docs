# @ohos.enterprise.networkManager (Network Management)

The **networkManager** module provides APIs for network management of enterprise devices, including obtaining the device IP address and MAC address. Only the device administrator applications can call the APIs provided by this module.

> **NOTE**
>
> The initial APIs of this module are supported since API version 10. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```js
import networkManager from '@ohos.enterprise.networkManager';
```

## networkManager.getAllNetworkInterfaces

getAllNetworkInterfaces(admin: Want, callback: AsyncCallback&lt;Array&lt;string&gt;&gt;): void

Obtains all active network interfaces through a device administrator application. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.GET_NETWORK_INFO

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**System API**: This is a system API.

**Parameters**

| Name     | Type                                      | Mandatory  | Description                      |
| -------- | ---------------------------------------- | ---- | ------------------------------- |
| admin    | [Want](js-apis-app-ability-want.md)     | Yes   | Device administrator application that obtains the information.                 |
| callback | AsyncCallback&lt;Array&lt;string&gt;&gt;            | Yes   | Callback invoked to return the result. If the operation is successful, **err** is **null** and **data** is an array of network interfaces obtained. If the operation fails, **err** is an error object.    |

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](../errorcodes/errorcode-enterpriseDeviceManager.md).

| ID| Error Message                                                                      |
| ------- | ---------------------------------------------------------------------------- |
| 9200001 | The application is not an administrator application of the device.                       |
| 9200002 | The administrator application does not have permission to manage the device.|

**Example**

```js
let wantTemp = {
    bundleName: "com.example.myapplication",
    abilityName: "EntryAbility",
};
networkManager.getAllNetworkInterfaces(admin, (error, result) => {
    if (error != null) {
        console.log("error code:" + error.code + " error message:" + error.message);
        return;
    }
    console.log(JSON.stringify(result));
});
```

## networkManager.getAllNetworkInterfaces

getAllNetworkInterfaces(admin: Want): Promise&lt;Array&lt;string&gt;&gt;

Obtains all active network interfaces through a device administrator application. This API uses a promise to return the result.

**Required permissions**: ohos.permission.ENTERPRISE_GET_NETWORK_INFO

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**System API**: This is a system API.

**Parameters**

| Name  | Type                                 | Mandatory  | Description     |
| ----- | ----------------------------------- | ---- | ------- |
| admin | [Want](js-apis-app-ability-want.md) | Yes   | Device administrator application that obtains the information.|

**Return value**

| Type                  | Description                     |
| --------------------- | ------------------------- |
| Promise&lt;Array&lt;string&gt;&gt; | Promise used to return an array of network interfaces obtained. |

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](../errorcodes/errorcode-enterpriseDeviceManager.md).

| ID| Error Message                                                                    |
| ------- | ---------------------------------------------------------------------------- |
| 9200001 | The application is not an administrator application of the device.                       |
| 9200002 | The administrator application does not have permission to manage the device.|

**Example**

```js
let wantTemp = {
    bundleName: "com.example.myapplication",
    abilityName: "EntryAbility",
};
networkManager.getAllNetworkInterfaces(wantTemp).then((result) => {
    console.log(JSON.stringify(result));
}).catch(error => {
    console.log("error code:" + error.code + " error message:" + error.message);
});
```

## networkManager.getIpAddress

getIpAddress(admin: Want, networkInterface: string, callback: AsyncCallback&lt;string&gt;): void

Obtains the device IP address based on the given network interface through a device administrator application. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.GET_NETWORK_INFO

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**System API**: This is a system API.

**Parameters**

| Name     | Type                                      | Mandatory  | Description                      |
| -------- | ---------------------------------------- | ---- | ------------------------------- |
| admin    | [Want](js-apis-app-ability-want.md)     | Yes   | Device administrator application that obtains the information.                 |
| networkInterface    | string     | Yes   | Network interface.                 |
| callback | AsyncCallback&lt;string&gt;            | Yes   | Callback invoked to return the result. If the operation is successful, **err** is **null** and **data** is the IP address obtained. If the operation fails, **err** is an error object.      |

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](../errorcodes/errorcode-enterpriseDeviceManager.md).

| ID| Error Message                                                                      |
| ------- | ---------------------------------------------------------------------------- |
| 9200001 | The application is not an administrator application of the device.                       |
| 9200002 | The administrator application does not have permission to manage the device.|

**Example**

```js
let wantTemp = {
    bundleName: "com.example.myapplication",
    abilityName: "EntryAbility",
};
networkManager.getIpAddress(wantTemp, "eth0", (error, result) => {
    if (error != null) {
        console.log("error code:" + error.code + " error message:" + error.message);
        return;
    }
    console.log(result);
});
```

## networkManager.getIpAddress

getIpAddress(admin: Want, networkInterface: string): Promise&lt;string&gt;

Obtains the device IP address based on the given network interface through a device administrator application. This API uses a promise to return the result.

**Required permissions**: ohos.permission.ENTERPRISE_GET_NETWORK_INFO

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**System API**: This is a system API.

**Parameters**

| Name  | Type                                 | Mandatory  | Description     |
| ----- | ----------------------------------- | ---- | ------- |
| admin | [Want](js-apis-app-ability-want.md) | Yes   | Device administrator application that obtains the information.|
| networkInterface    | string     | Yes   | Network interface.                 |

**Return value**

| Type                  | Description                     |
| --------------------- | ------------------------- |
| Promise&lt;string&gt; | Promise used to return the device IP address obtained. |

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](../errorcodes/errorcode-enterpriseDeviceManager.md).

| ID| Error Message                                                                    |
| ------- | ---------------------------------------------------------------------------- |
| 9200001 | The application is not an administrator application of the device.                       |
| 9200002 | The administrator application does not have permission to manage the device.|

**Example**

```js
let wantTemp = {
    bundleName: "com.example.myapplication",
    abilityName: "EntryAbility",
};
networkManager.getIpAddress(wantTemp, "eth0").then((result) => {
    console.log(result);
}).catch(error => {
    console.log("error code:" + error.code + " error message:" + error.message);
});
```

## networkManager.getMac

getMac(admin: Want, networkInterface: string, callback: AsyncCallback&lt;string&gt;): void

Obtains the device MAC address based on the given network interface through a device administrator application. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.ENTERPRISE_GET_NETWORK_INFO

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**System API**: This is a system API.

**Parameters**

| Name     | Type                                      | Mandatory  | Description                      |
| -------- | ---------------------------------------- | ---- | ------------------------------- |
| admin    | [Want](js-apis-app-ability-want.md)      | Yes   | Device administrator application that obtains the information.                 |
| networkInterface    | string     | Yes   | Network interface.                 |
| callback | AsyncCallback&lt;string&gt;            | Yes   | Callback invoked to return the result. If the operation is successful, **err** is **null** and **data** is the MAC address obtained. If the operation fails, **err** is an error object.      |

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](../errorcodes/errorcode-enterpriseDeviceManager.md).

| ID| Error Message                                                                      |
| ------- | ---------------------------------------------------------------------------- |
| 9200001 | The application is not an administrator application of the device.                       |
| 9200002 | The administrator application does not have permission to manage the device.|

**Example**

```js
let wantTemp = {
    bundleName: "com.example.myapplication",
    abilityName: "EntryAbility",
};
networkManager.getMac(wantTemp, "eth0", (error, result) => {
    if (error != null) {
        console.log("error code:" + error.code + " error message:" + error.message);
        return;
    }
    console.log(result);
});
```

## networkManager.getMac

getIpAddress(admin: Want, networkInterface: string): Promise&lt;string&gt;

Obtain the device MAC address based on the given network interface through a device administrator application. This API uses a promise to return the result.

**Required permissions**: ohos.permission.ENTERPRISE_GET_NETWORK_INFO

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**System API**: This is a system API.

**Parameters**

| Name  | Type                                 | Mandatory  | Description     |
| ----- | ----------------------------------- | ---- | ------- |
| admin | [Want](js-apis-app-ability-want.md) | Yes   | Device administrator application that obtains the information.|
| networkInterface    | string     | Yes   | Network interface.                 |

**Return value**

| Type                  | Description                     |
| --------------------- | ------------------------- |
| Promise&lt;string&gt; | Promise used to return the device MAC address obtained. |

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](../errorcodes/errorcode-enterpriseDeviceManager.md).

| ID| Error Message                                                                    |
| ------- | ---------------------------------------------------------------------------- |
| 9200001 | The application is not an administrator application of the device.                       |
| 9200002 | The administrator application does not have permission to manage the device.|

**Example**

```js
let wantTemp = {
    bundleName: "com.example.myapplication",
    abilityName: "EntryAbility",
};
networkManager.getMac(wantTemp, "eth0").then((result) => {
    console.log(result);
}).catch(error => {
    console.log("error code:" + error.code + " error message:" + error.message);
});
```
