# Enterprise Device Management

The **enterpriseDeviceManager** module provides enterprise device management capabilities so that devices have the customization capabilities required in enterprise scenarios.

> **NOTE**
>
> The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```js
import enterpriseDeviceManager from '@ohos.enterpriseDeviceManager';
```

## enterpriseDeviceManager.enableAdmin

enableAdmin(admin: Want, enterpriseInfo: EnterpriseInfo, type: AdminType, callback: AsyncCallback\<boolean>): void

Enables a device administrator application based on the specified bundle name and class name. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.MANAGE_ENTERPRISE_DEVICE_ADMIN

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Parameters**

| Name           | Type                                 | Mandatory  | Description                |
| -------------- | ----------------------------------- | ---- | ------------------ |
| admin          | [Want](js-apis-application-Want.md) | Yes   | Device administrator application.           |
| enterpriseInfo | [EnterpriseInfo](#enterpriseinfo)   | Yes   | Enterprise information of the device administrator application.      |
| type           | [AdminType](#admintype)             | Yes   | Type of the device administrator to enable.        |
| callback       | AsyncCallback\<boolean>             | Yes   | Callback used to return the result.|

**Example**

```js
let wantTemp = {
    bundleName: "com.example.myapplication",
    abilityName: "com.example.myapplication.MainAbility",
};
let enterpriseInfo = {
    name: "enterprise name",
    description: "enterprise description"
}
enterpriseDeviceManager.enableAdmin(wantTemp, enterpriseInfo, enterpriseDeviceManager.AdminType.ADMIN_TYPE_NORMAL, (error, result) => {
    if (error != null) {
        console.log("error occurs" + error);
        return;
    }
    console.log("result is " + result);
});
```

## enterpriseDeviceManager.enableAdmin

enableAdmin(admin: Want, enterpriseInfo: EnterpriseInfo, type: AdminType, userId: number, callback: AsyncCallback\<boolean>): void

Enables a device administrator application based on the specified bundle name and class name. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.MANAGE_ENTERPRISE_DEVICE_ADMIN

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Parameters**

| Name           | Type                                 | Mandatory  | Description                          |
| -------------- | ----------------------------------- | ---- | ---------------------------- |
| admin          | [Want](js-apis-application-Want.md) | Yes   | Device administrator application.                     |
| enterpriseInfo | [EnterpriseInfo](#enterpriseinfo)   | Yes   | Enterprise information of the device administrator application.                |
| type           | [AdminType](#admintype)             | Yes   | Type of the device administrator to enable.                  |
| userId         | number                              | Yes   | User ID The default value is the user ID of the caller. The value must be greater than or equal to 0.|
| callback       | AsyncCallback\<boolean>             | Yes   | Callback used to return the result.          |

**Example**

```js
let wantTemp = {
    bundleName: "com.example.myapplication",
    abilityName: "com.example.myapplication.MainAbility",
};
let enterpriseInfo = {
    name: "enterprise name",
    description: "enterprise description"
}
enterpriseDeviceManager.enableAdmin(wantTemp, enterpriseInfo, enterpriseDeviceManager.AdminType.ADMIN_TYPE_NORMAL, 100, (error, result) => {
    if (error != null) {
        console.log("error occurs" + error);
        return;
    }
    console.log("result is " + result);
});
```

## enterpriseDeviceManager.enableAdmin

enableAdmin(admin: Want, enterpriseInfo: EnterpriseInfo, type: AdminType, userId?: number): Promise\<boolean>

Enables a device administrator application based on the specified bundle name and class name. This API uses a promise to return the result.

**Required permissions**: ohos.permission.MANAGE_ENTERPRISE_DEVICE_ADMIN

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Parameters**

| Name           | Type                                 | Mandatory  | Description                          |
| -------------- | ----------------------------------- | ---- | ---------------------------- |
| admin          | [Want](js-apis-application-Want.md) | Yes   | Device administrator application.                     |
| enterpriseInfo | [EnterpriseInfo](#enterpriseinfo)   | Yes   | Enterprise information of the device administrator application.                |
| type           | [AdminType](#admintype)             | Yes   | Type of the device administrator to enable.                  |
| userId         | number                              | No   | User ID The default value is the user ID of the caller. The value must be greater than or equal to 0.|

**Return value**

| Type               | Description               |
| ----------------- | ----------------- |
| Promise\<boolean> | Promise used to return the result.|

**Example**

```js
let wantTemp = {
    bundleName: "com.example.myapplication",
    abilityName: "com.example.myapplication.MainAbility",
};
let enterpriseInfo = {
    name: "enterprise name",
    description: "enterprise description"
}
enterpriseDeviceManager.enableAdmin(wantTemp, enterpriseInfo, enterpriseDeviceManager.AdminType.ADMIN_TYPE_NORMAL, 100)
.then((result) => {
    console.log("result is " + result);
}).catch(error => {
    console.log("error occurs" + error);
});
```

## enterpriseDeviceManager.disableAdmin

disableAdmin(admin: Want, callback: AsyncCallback\<boolean>): void

Disables a device common administrator application based on the specified bundle name and class name. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.MANAGE_ENTERPRISE_DEVICE_ADMIN

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Parameters**

| Name     | Type                                 | Mandatory  | Description                 |
| -------- | ----------------------------------- | ---- | ------------------- |
| admin    | [Want](js-apis-application-Want.md) | Yes   | Device common administrator application.          |
| callback | AsyncCallback\<boolean>             | Yes   | Callback used to return the result.|

**Example**

```js
let wantTemp = {
    bundleName: "bundleName",
    abilityName: "abilityName",
};
enterpriseDeviceManager.disableAdmin(wantTemp, (error, result) => {
    if (error != null) {
        console.log("error occurs" + error);
        return;
    }
    console.log("result is " + result);
});
```

## enterpriseDeviceManager.disableAdmin

disableAdmin(admin: Want, userId: number, callback: AsyncCallback\<boolean>): void

Disables a device common administrator application based on the specified bundle name and class name. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.MANAGE_ENTERPRISE_DEVICE_ADMIN

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Parameters**

| Name     | Type                                 | Mandatory  | Description                          |
| -------- | ----------------------------------- | ---- | ---------------------------- |
| admin    | [Want](js-apis-application-Want.md) | Yes   | Device common administrator application.                   |
| userId   | number                              | Yes   | User ID The default value is the user ID of the caller. The value must be greater than or equal to 0.|
| callback | AsyncCallback\<boolean>             | Yes   | Callback used to return the result.         |

**Example**

```js
let wantTemp = {
    bundleName: "bundleName",
    abilityName: "abilityName",
};
enterpriseDeviceManager.disableAdmin(wantTemp, 100, (error, result) => {
    if (error != null) {
        console.log("error occurs" + error);
        return;
    }
    console.log("result is " + result);
});
```

## enterpriseDeviceManager.disableAdmin

disableAdmin(admin: Want, userId?: number): Promise\<boolean>

Disables a device common administrator application based on the specified bundle name and class name. This API uses a promise to return the result.

**Required permissions**: ohos.permission.MANAGE_ENTERPRISE_DEVICE_ADMIN

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Parameters**

| Name   | Type                                 | Mandatory  | Description                          |
| ------ | ----------------------------------- | ---- | ---------------------------- |
| admin  | [Want](js-apis-application-Want.md) | Yes   | Device common administrator application.                   |
| userId | number                              | No   | User ID The default value is the user ID of the caller. The value must be greater than or equal to 0.|

**Return value**

| Type               | Description               |
| ----------------- | ----------------- |
| Promise\<boolean> | Promise used to return the result.|

**Example**

```js
let wantTemp = {
    bundleName: "bundleName",
    abilityName: "abilityName",
};
enterpriseDeviceManager.disableAdmin(wantTemp, 100).then((result) => {
    console.log("result is " + result);
}).catch(error => {
    console.log("error occurs" + error);
});
```

## enterpriseDeviceManager.disableSuperAdmin

disableSuperAdmin(bundleName: String, callback: AsyncCallback\<boolean>): void

Disables a device super administrator application based on the specified bundle name. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Parameters**

| Name       | Type                     | Mandatory  | Description                 |
| ---------- | ----------------------- | ---- | ------------------- |
| bundleName | String                  | Yes   | Bundle name of the device super administrator application.       |
| callback   | AsyncCallback\<boolean> | Yes   | Callback used to return the result.|

**Example**

```js
let bundleName = "com.example.myapplication";
enterpriseDeviceManager.disableSuperAdmin(bundleName, (error, result) => {
    if (error != null) {
        console.log("error occurs" + error);
        return;
    }
    console.log("result is " + result);
});
```

## enterpriseDeviceManager.disableSuperAdmin

disableSuperAdmin(bundleName: String): Promise\<boolean>

Disables a device super administrator application based on the specified bundle name. This API uses a promise to return the result.

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Parameters**

| Name       | Type    | Mandatory  | Description          |
| ---------- | ------ | ---- | ------------ |
| bundleName | String | Yes   | Bundle name of the device super administrator application.|

**Return value**

| Type               | Description               |
| ----------------- | ----------------- |
| Promise\<boolean> | Promise used to return the result.|

**Example**

```js
let bundleName = "com.example.myapplication";
enterpriseDeviceManager.disableSuperAdmin(bundleName).then((result) => {
    console.log("result is " + result);
}).catch(error => {
    console.log("error occurs" + error);
});
```

## enterpriseDeviceManager.isAdminEnabled

isAdminEnabled(admin: Want, callback: AsyncCallback\<boolean>): void

Checks whether a device administrator application is enabled based on the specified bundle name and class name. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Parameters**

| Name     | Type                                 | Mandatory  | Description                  |
| -------- | ----------------------------------- | ---- | -------------------- |
| admin    | [Want](js-apis-application-Want.md) | Yes   | Device administrator application.             |
| callback | AsyncCallback\<boolean>             | Yes   | Callback used to return the result.|

**Example**

```js
let wantTemp = {
    bundleName: "bundleName",
    abilityName: "abilityName",
};
enterpriseDeviceManager.isAdminEnabled(wantTemp, (error, result) => {
    if (error != null) {
        console.log("error occurs" + error);
        return;
    }
    console.log("result is " + result);
});
```

## enterpriseDeviceManager.isAdminEnabled

isAdminEnabled(admin: Want, userId: number, callback: AsyncCallback\<boolean>): void

Checks whether a device administrator application is enabled based on the specified bundle name and class name. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Parameters**

| Name     | Type                                 | Mandatory  | Description                          |
| -------- | ----------------------------------- | ---- | ---------------------------- |
| admin    | [Want](js-apis-application-Want.md) | Yes   | Device administrator application.                     |
| userId   | number                              | Yes   | User ID The default value is the user ID of the caller. The value must be greater than or equal to 0.|
| callback | AsyncCallback\<boolean>             | Yes   | Callback used to return the result.        |

**Example**

```js
let wantTemp = {
    bundleName: "bundleName",
    abilityName: "abilityName",
};
enterpriseDeviceManager.isAdminEnabled(wantTemp, 100, (error, result) => {
    if (error != null) {
        console.log("error occurs" + error);
        return;
    }
    console.log("result is " + result);
});
```

## enterpriseDeviceManager.isAdminEnabled

isAdminEnabled(admin: Want, userId?: number): Promise\<boolean>

Checks whether a device administrator application is enabled based on the specified bundle name and class name. This API uses a promise to return the result.

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Parameters**

| Name   | Type                                 | Mandatory  | Description                          |
| ------ | ----------------------------------- | ---- | ---------------------------- |
| admin  | [Want](js-apis-application-Want.md) | Yes   | Device administrator application.                     |
| userId | number                              | No   | User ID The default value is the user ID of the caller. The value must be greater than or equal to 0.|

**Return value**

| Type               | Description                 |
| ----------------- | ------------------- |
| Promise\<boolean> | Promise used to return the result.|

**Example**

```js
let wantTemp = {
    bundleName: "bundleName",
    abilityName: "abilityName",
};
enterpriseDeviceManager.isAdminEnabled(wantTemp, 100).then((result) => {
    console.log("result is " + result);
}).catch(error => {
    console.log("error occurs" + error);
});
```

## enterpriseDeviceManager.isSuperAdmin

isSuperAdmin(bundleName: String, callback: AsyncCallback\<boolean>): void

Checks whether a device super administrator application is enabled based on the specified bundle name. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Parameters**

| Name       | Type                     | Mandatory  | Description                  |
| ---------- | ----------------------- | ---- | -------------------- |
| bundleName | String                  | Yes   | Device administrator application.             |
| callback   | AsyncCallback\<boolean> | Yes   | Callback used to return the result.|

**Example**

```js
let bundleName = "com.example.myapplication";
enterpriseDeviceManager.isSuperAdmin(bundleName, (error, result) => {
    if (error != null) {
        console.log("error occurs" + error);
        return;
    }
    console.log("result is " + result);
});
```

## enterpriseDeviceManager.isSuperAdmin

isSuperAdmin(bundleName: String): Promise\<boolean>

Checks whether a device super administrator application is enabled based on the specified bundle name. This API uses a promise to return the result.

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Parameters**

| Name       | Type    | Mandatory  | Description       |
| ---------- | ------ | ---- | --------- |
| bundleName | String | Yes   | Device super administrator application.|

**Return value**

| Type               | Description                 |
| ----------------- | ------------------- |
| Promise\<boolean> | Promise used to return the result.|

**Example**

```js
let bundleName = "com.example.myapplication";
enterpriseDeviceManager.isSuperAdmin(bundleName).then((result) => {
    console.log("result is " + result);
}).catch(error => {
    console.log("error occurs" + error);
});
```

## enterpriseDeviceManager.getDeviceSettingsManager

getDeviceSettingsManager(callback: AsyncCallback&lt;DeviceSettingsManager&gt;): void

Obtains a **DeviceSettingsManager** object. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Parameters**

| Name     | Type                                     | Mandatory  | Description                                 |
| -------- | --------------------------------------- | ---- | ----------------------------------- |
| callback | AsyncCallback<[DeviceSettingsManager](js-apis-enterpriseDeviceManager-DeviceSettingsManager.md)&gt; | Yes   | Callback used to return the **DeviceSettingsManager** object obtained.|

**Example**

```js
let wantTemp = {
    bundleName: "bundleName",
    abilityName: "abilityName",
};
enterpriseDeviceManager.getDeviceSettingsManager((error, mgr) => {
    if (error != null) {
        console.log("error occurs" + error);
        return;
    }
    mgr.setDateTime(wantTemp, 1526003846000, (error, value) => { 
        if (error != null) {
            console.log(error);
        } else {
            console.log(value);
        }
    });
});
```

## enterpriseDeviceManager.getDeviceSettingsManager

getDeviceSettingsManager(): Promise&lt;DeviceSettingsManager&gt;

Obtains a **DeviceSettingsManager** object. This API uses a promise to return the result.

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Return value**

| Type                                  | Description                                |
| ------------------------------------ | ---------------------------------- |
| Promise&lt;[DeviceSettingsManager](js-apis-enterpriseDeviceManager-DeviceSettingsManager.md)&gt; | Promise used to return the **DeviceSettingsManager** object obtained.|

**Example**

```js
let wantTemp = {
    bundleName: "bundleName",
    abilityName: "abilityName",
};
enterpriseDeviceManager.getDeviceSettingsManager().then((mgr) => {
    mgr.setDateTime(wantTemp, 1526003846000).then((value) => {
        console.log(value);
    }).catch((error) => {
        console.log(error);
    })
}).catch((error) => {
    console.log(error);
})
```

## enterpriseDeviceManager.setEnterpriseInfo

setEnterpriseInfo(admin: Want, enterpriseInfo: EnterpriseInfo, callback: AsyncCallback&lt;boolean&gt;): void

Sets the enterprise information of a device administrator application. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Parameters**

| Name           | Type                                 | Mandatory  | Description                    |
| -------------- | ----------------------------------- | ---- | ---------------------- |
| admin          | [Want](js-apis-application-Want.md) | Yes   | Device administrator application.               |
| enterpriseInfo | [EnterpriseInfo](#enterpriseinfo)   | Yes   | Enterprise information of the device administrator application.          |
| callback       | AsyncCallback\<boolean&gt;          | Yes   | Callback used to return the result.|

**Example**

```js
let wantTemp = {
    bundleName: "com.example.myapplication",
    abilityName: "com.example.myapplication.MainAbility",
};
let enterpriseInfo = {
    name: "enterprise name",
    description: "enterprise description"
}
enterpriseDeviceManager.setEnterpriseInfo(wantTemp, enterpriseInfo)
.then((result) => {
    console.log("result is " + result);
}).catch(error => {
    console.log("error occurs" + error);
});
```

## enterpriseDeviceManager.setEnterpriseInfo

setEnterpriseInfo(admin: Want, enterpriseInfo: EnterpriseInfo): Promise&lt;boolean&gt;

Sets the enterprise information of a device administrator application. This API uses a promise to return the result.

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Parameters**

| Name           | Type                                 | Mandatory  | Description          |
| -------------- | ----------------------------------- | ---- | ------------ |
| admin          | [Want](js-apis-application-Want.md) | Yes   | Device administrator application.     |
| enterpriseInfo | [EnterpriseInfo](#enterpriseinfo)   | Yes   | Enterprise information of the device administrator application.|

**Return value**

| Type               | Description                   |
| ----------------- | --------------------- |
| Promise\<boolean> | Promise used to return the result.|

**Example**

```js
let wantTemp = {
    bundleName: "com.example.myapplication",
    abilityName: "com.example.myapplication.MainAbility",
};
let enterpriseInfo = {
    name: "enterprise name",
    description: "enterprise description"
}
enterpriseDeviceManager.setEnterpriseInfo(wantTemp, enterpriseInfo)
.then((result) => {
    console.log("result is " + result);
}).catch(error => {
    console.log("error occurs" + error);
});
```

## enterpriseDeviceManager.getEnterpriseInfo

getEnterpriseInfo(admin: Want, callback: AsyncCallback&lt;EnterpriseInfo&gt;): void

Obtains the enterprise information of a device administrator application. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Parameters**

| Name     | Type                                      | Mandatory  | Description                      |
| -------- | ---------------------------------------- | ---- | ------------------------ |
| admin    | [Want](js-apis-application-Want.md)      | Yes   | Device administrator application.                 |
| callback | AsyncCallback&lt;[EnterpriseInfo](#enterpriseinfo)&gt; | Yes   | Callback used to return the enterprise information of the device administrator application.|

**Example**

```js
let wantTemp = {
    bundleName: "com.example.myapplication",
    abilityName: "com.example.myapplication.MainAbility",
};
enterpriseDeviceManager.getEnterpriseInfo(wantTemp, (error, result) => {
    if (error != null) {
        console.log("error occurs" + error);
        return;
    }
    console.log(result.name);
    console.log(result.description);
});
```

## enterpriseDeviceManager.getEnterpriseInfo

getEnterpriseInfo(admin: Want): Promise&lt;EnterpriseInfo&gt;

Obtains the enterprise information of a device administrator application. This API uses a promise to return the result.

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Parameters**

| Name  | Type                                 | Mandatory  | Description     |
| ----- | ----------------------------------- | ---- | ------- |
| admin | [Want](js-apis-application-Want.md) | Yes   | Device administrator application.|

**Return value**

| Type                                      | Description                       |
| ---------------------------------------- | ------------------------- |
| Promise&lt;[EnterpriseInfo](#enterpriseinfo)&gt; | Promise used to return the enterprise information of the device administrator application.|

**Example**

```js
let wantTemp = {
    bundleName: "com.example.myapplication",
    abilityName: "com.example.myapplication.MainAbility",
};
enterpriseDeviceManager.getEnterpriseInfo(wantTemp).then((result) => {
    console.log(result.name);
    console.log(result.description);
}).catch(error => {
    console.log("error occurs" + error);
});
```

## EnterpriseInfo

Describes the enterprise information of a device administrator application.

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

| Name         | Readable/Writable| Type    | Mandatory  | Description               |
| ----------- | ---- | ------ | ---- | ----------------- |
| name        | Read only  | string | Yes   | Name of the enterprise to which the device administrator application belongs.|
| description | Read only  | string | Yes   | Description of the enterprise to which the device administrator application belongs.|

## AdminType

Enumerates the administrator types of the device administrator application.

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

| Name               | Default Value | Description   |
| ----------------- | ---- | ----- |
| ADMIN_TYPE_NORMAL | 0x00 | Common administrator.|
| ADMIN_TYPE_SUPER  | 0x01 | Super administrator.|
