# @ohos.enterprise.adminManager

The **adminManager** module provides enterprise device management capabilities so that devices have the custom capabilities required in enterprise settings.

> **NOTE**
>
> The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```js
import adminManager from '@ohos.enterprise.adminManager';
```

## adminManager.enableAdmin

enableAdmin(admin: Want, enterpriseInfo: EnterpriseInfo, type: AdminType, callback: AsyncCallback\<void>): void

Enables a device administrator application based on the specified bundle name and class name. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.MANAGE_ENTERPRISE_DEVICE_ADMIN

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**System API**: This is a system API.

**Parameters**

| Name           | Type                                 | Mandatory  | Description                |
| -------------- | ----------------------------------- | ---- | ------------------ |
| admin          | [Want](js-apis-app-ability-want.md) | Yes   | Device administrator application.           |
| enterpriseInfo | [EnterpriseInfo](#enterpriseinfo)   | Yes   | Enterprise information of the device administrator application.      |
| type           | [AdminType](#admintype)             | Yes   | Type of the device administrator to enable.        |
| callback       | AsyncCallback\<void>                | Yes   | Callback used to return the result.|

**Error codes**

For details about the following error codes, see [Enterprise Device Management Error Codes](../errorcodes/errorcode-enterpriseDeviceManager.md).

| ID| Error Message                                                        |
| ------- | --------------------------------------------------------------- |
| 9200003 | the administrator ability component is invalid.                 |
| 9200004 | failed to enable the administrator application of the device.   |
| 9200007 | the system ability work abnormally.                             |

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
adminManager.enableAdmin(wantTemp, enterpriseInfo, adminManager.AdminType.ADMIN_TYPE_NORMAL, error => {
    if (error != null) {
        console.log("error occurs" + error);
        return;
    }
    console.log("enableAdmin success");
});
```

## adminManager.enableAdmin

enableAdmin(admin: Want, enterpriseInfo: EnterpriseInfo, type: AdminType, userId: number, callback: AsyncCallback\<void>): void

Enables a device administrator application for the specified user based on the specified bundle name and class name. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.MANAGE_ENTERPRISE_DEVICE_ADMIN

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**System API**: This is a system API.

**Parameters**

| Name           | Type                                 | Mandatory  | Description                          |
| -------------- | ----------------------------------- | ---- | ---------------------------- |
| admin          | [Want](js-apis-app-ability-want.md) | Yes   | Device administrator application.                     |
| enterpriseInfo | [EnterpriseInfo](#enterpriseinfo)   | Yes   | Enterprise information of the device administrator application.                |
| type           | [AdminType](#admintype)             | Yes   | Type of the device administrator to enable.                  |
| userId         | number                              | Yes   | User ID. The default value is the user ID of the caller. The value must be greater than or equal to 0.|
| callback       | AsyncCallback\<void>                | Yes   | Callback used to return the result.          |

**Error codes**

For details about the following error codes, see [Enterprise Device Management Error Codes](../errorcodes/errorcode-enterpriseDeviceManager.md).

| ID| Error Message                                                        |
| ------- | --------------------------------------------------------------- |
| 9200003 | the administrator ability component is invalid.                 |
| 9200004 | failed to enable the administrator application of the device.   |
| 9200007 | the system ability work abnormally.                             |

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
adminManager.enableAdmin(wantTemp, enterpriseInfo, adminManager.AdminType.ADMIN_TYPE_NORMAL, 100, error => {
    if (error != null) {
        console.log("error occurs" + error);
        return;
    }
    console.log("enableAdmin success");
});
```

## adminManager.enableAdmin

enableAdmin(admin: Want, enterpriseInfo: EnterpriseInfo, type: AdminType, userId?: number): Promise\<void>

Enables a device administrator application based on the specified bundle name and class name. This API uses a promise to return the result.

**Required permissions**: ohos.permission.MANAGE_ENTERPRISE_DEVICE_ADMIN

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**System API**: This is a system API.

**Parameters**

| Name           | Type                                 | Mandatory  | Description                          |
| -------------- | ----------------------------------- | ---- | ---------------------------- |
| admin          | [Want](js-apis-app-ability-want.md) | Yes   | Device administrator application.                     |
| enterpriseInfo | [EnterpriseInfo](#enterpriseinfo)   | Yes   | Enterprise information of the device administrator application.                |
| type           | [AdminType](#admintype)             | Yes   | Type of the device administrator to enable.                  |
| userId         | number                              | No   | User ID. The default value is the user ID of the caller. The value must be greater than or equal to 0.|

**Return value**

| Type               | Description               |
| ----------------- | ----------------- |
| Promise\<void>    | Promise used to return the result.|

**Error codes**

For details about the following error codes, see [Enterprise Device Management Error Codes](../errorcodes/errorcode-enterpriseDeviceManager.md).

| ID| Error Message                                                        |
| ------- | --------------------------------------------------------------- |
| 9200003 | the administrator ability component is invalid.                 |
| 9200004 | failed to enable the administrator application of the device.   |
| 9200007 | the system ability work abnormally.                             |

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
adminManager.enableAdmin(wantTemp, enterpriseInfo, adminManager.AdminType.ADMIN_TYPE_NORMAL, 100)
.catch(error => {
    console.log("error occurs" + error);
});
```

## adminManager.disableAdmin

disableAdmin(admin: Want, callback: AsyncCallback\<void>): void

Disables a device common administrator application based on the specified bundle name and class name. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.MANAGE_ENTERPRISE_DEVICE_ADMIN

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**System API**: This is a system API.

**Parameters**

| Name     | Type                                 | Mandatory  | Description                 |
| -------- | ----------------------------------- | ---- | ------------------- |
| admin    | [Want](js-apis-app-ability-want.md) | Yes   | Device common administrator application.          |
| callback | AsyncCallback\<void>                | Yes   | Callback used to return the result.|

**Error codes**

For details about the following error codes, see [Enterprise Device Management Error Codes](../errorcodes/errorcode-enterpriseDeviceManager.md).

| ID| Error Message                                                          |
| ------- | ----------------------------------------------------------------- |
| 9200005 | failed to disable the administrator application of the device.    |

**Example**

```js
let wantTemp = {
    bundleName: "bundleName",
    abilityName: "abilityName",
};
adminManager.disableAdmin(wantTemp, error => {
    if (error != null) {
        console.log("error occurs" + error);
        return;
    }
    console.log("disableAdmin success ");
});
```

## adminManager.disableAdmin

disableAdmin(admin: Want, userId: number, callback: AsyncCallback\<void>): void

Disables a device common administrator application for the specified user based on the specified bundle name and class name. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.MANAGE_ENTERPRISE_DEVICE_ADMIN

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**System API**: This is a system API.

**Parameters**

| Name     | Type                                 | Mandatory  | Description                          |
| -------- | ----------------------------------- | ---- | ---------------------------- |
| admin    | [Want](js-apis-app-ability-want.md) | Yes   | Device common administrator application.                   |
| userId   | number                              | Yes   | User ID. The default value is the user ID of the caller. The value must be greater than or equal to 0.|
| callback | AsyncCallback\<void>                | Yes   | Callback used to return the result.         |

**Error codes**

For details about the following error codes, see [Enterprise Device Management Error Codes](../errorcodes/errorcode-enterpriseDeviceManager.md).

| ID| Error Message                                                          |
| ------- | ----------------------------------------------------------------- |
| 9200005 | failed to disable the administrator application of the device.    |

**Example**

```js
let wantTemp = {
    bundleName: "bundleName",
    abilityName: "abilityName",
};
adminManager.disableAdmin(wantTemp, 100, error => {
    if (error != null) {
        console.log("error occurs" + error);
        return;
    }
    console.log("disableAdmin success ");
});
```

## adminManager.disableAdmin

disableAdmin(admin: Want, userId?: number): Promise\<void>

Disables a device common administrator application based on the specified bundle name and class name. This API uses a promise to return the result.

**Required permissions**: ohos.permission.MANAGE_ENTERPRISE_DEVICE_ADMIN

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**System API**: This is a system API.

**Parameters**

| Name   | Type                                 | Mandatory  | Description                          |
| ------ | ----------------------------------- | ---- | ---------------------------- |
| admin  | [Want](js-apis-app-ability-want.md) | Yes   | Device common administrator application.                   |
| userId | number                              | No   | User ID. The default value is the user ID of the caller. The value must be greater than or equal to 0.|

**Return value**

| Type               | Description               |
| ----------------- | ----------------- |
| Promise\<void>    | Promise used to return the result.|

**Error codes**

For details about the following error codes, see [Enterprise Device Management Error Codes](../errorcodes/errorcode-enterpriseDeviceManager.md).

| ID| Error Message                                                          |
| ------- | ----------------------------------------------------------------- |
| 9200005 | failed to disable the administrator application of the device.    |

**Example**

```js
let wantTemp = {
    bundleName: "bundleName",
    abilityName: "abilityName",
};
adminManager.disableAdmin(wantTemp, 100).catch(error => {
    console.log("error occurs" + error);
});
```

## adminManager.disableSuperAdmin

disableSuperAdmin(bundleName: String, callback: AsyncCallback\<void>): void

Disables a device super administrator application based on the specified bundle name. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.MANAGE_ENTERPRISE_DEVICE_ADMIN

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**System API**: This is a system API.

**Parameters**

| Name       | Type                     | Mandatory  | Description                 |
| ---------- | ----------------------- | ---- | ------------------- |
| bundleName | String                  | Yes   | Bundle name of the device super administrator application.       |
| callback   | AsyncCallback\<void>    | Yes   | Callback used to return the result.|

**Error codes**

For details about the following error codes, see [Enterprise Device Management Error Codes](../errorcodes/errorcode-enterpriseDeviceManager.md).

| ID| Error Message                                                          |
| ------- | ----------------------------------------------------------------- |
| 9200005 | failed to disable the administrator application of the device.    |

**Example**

```js
let bundleName = "com.example.myapplication";
adminManager.disableSuperAdmin(bundleName, error => {
    if (error != null) {
        console.log("error occurs" + error);
        return;
    }
    console.log("disableSuperAdmin success");
});
```

## adminManager.disableSuperAdmin

disableSuperAdmin(bundleName: String): Promise\<void>

Disables a device super administrator application based on the specified bundle name. This API uses a promise to return the result.

**Required permissions**: ohos.permission.MANAGE_ENTERPRISE_DEVICE_ADMIN

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**System API**: This is a system API.

**Parameters**

| Name       | Type    | Mandatory  | Description          |
| ---------- | ------ | ---- | ------------ |
| bundleName | String | Yes   | Bundle name of the device super administrator application.|

**Return value**

| Type               | Description               |
| ----------------- | ----------------- |
| Promise\<void>    | Promise used to return the result.|

**Error codes**

For details about the following error codes, see [Enterprise Device Management Error Codes](../errorcodes/errorcode-enterpriseDeviceManager.md).

| ID| Error Message                                                          |
| ------- | ----------------------------------------------------------------- |
| 9200005 | failed to disable the administrator application of the device.    |

**Example**

```js
let bundleName = "com.example.myapplication";
adminManager.disableSuperAdmin(bundleName).catch(error => {
    console.log("error occurs" + error);
});
```

## adminManager.isAdminEnabled

isAdminEnabled(admin: Want, callback: AsyncCallback\<boolean>): void

Checks whether a device administrator application is enabled based on the specified bundle name and class name. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**System API**: This is a system API.

**Parameters**

| Name     | Type                                 | Mandatory  | Description                  |
| -------- | ----------------------------------- | ---- | -------------------- |
| admin    | [Want](js-apis-app-ability-want.md) | Yes   | Device administrator application.             |
| callback | AsyncCallback\<boolean>             | Yes   | Callback used to return the result.|

**Example**

```js
let wantTemp = {
    bundleName: "bundleName",
    abilityName: "abilityName",
};
adminManager.isAdminEnabled(wantTemp, (error, result) => {
    if (error != null) {
        console.log("error occurs" + error);
        return;
    }
    console.log("result is " + result);
});
```

## adminManager.isAdminEnabled

isAdminEnabled(admin: Want, userId: number, callback: AsyncCallback\<boolean>): void

Checks whether a device administrator application is enabled for the specified user based on the specified bundle name and class name. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**System API**: This is a system API.

**Parameters**

| Name     | Type                                 | Mandatory  | Description                          |
| -------- | ----------------------------------- | ---- | ---------------------------- |
| admin    | [Want](js-apis-app-ability-want.md) | Yes   | Device administrator application.                     |
| userId   | number                              | Yes   | User ID. The default value is the user ID of the caller. The value must be greater than or equal to 0.|
| callback | AsyncCallback\<boolean>             | Yes   | Callback used to return the result.        |

**Example**

```js
let wantTemp = {
    bundleName: "bundleName",
    abilityName: "abilityName",
};
adminManager.isAdminEnabled(wantTemp, 100, (error, result) => {
    if (error != null) {
        console.log("error occurs" + error);
        return;
    }
    console.log("result is " + result);
});
```

## adminManager.isAdminEnabled

isAdminEnabled(admin: Want, userId?: number): Promise\<boolean>

Checks whether a device administrator application is enabled based on the specified bundle name and class name. This API uses a promise to return the result.

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**System API**: This is a system API.

**Parameters**

| Name   | Type                                 | Mandatory  | Description                          |
| ------ | ----------------------------------- | ---- | ---------------------------- |
| admin  | [Want](js-apis-app-ability-want.md) | Yes   | Device administrator application.                     |
| userId | number                              | No   | User ID. The default value is the user ID of the caller. The value must be greater than or equal to 0.|

**Return value**

| Type              | Description               |
| ----------------- | ------------------- |
| Promise\<boolean> | Promise used to return the result.|

**Example**

```js
let wantTemp = {
    bundleName: "bundleName",
    abilityName: "abilityName",
};
adminManager.isAdminEnabled(wantTemp, 100).then((result) => {
    console.log("result is " + result);
}).catch(error => {
    console.log("error occurs" + error);
});
```

## adminManager.isSuperAdmin

isSuperAdmin(bundleName: String, callback: AsyncCallback\<boolean>): void

Checks whether a device super administrator application is enabled based on the specified bundle name. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**System API**: This is a system API.

**Parameters**

| Name       | Type                     | Mandatory  | Description                  |
| ---------- | ----------------------- | ---- | -------------------- |
| bundleName | String                  | Yes   | Device administrator application.             |
| callback   | AsyncCallback\<boolean> | Yes   | Callback used to return the result.|

**Example**

```js
let bundleName = "com.example.myapplication";
adminManager.isSuperAdmin(bundleName, (error, result) => {
    if (error != null) {
        console.log("error occurs" + error);
        return;
    }
    console.log("result is " + result);
});
```

## adminManager.isSuperAdmin

isSuperAdmin(bundleName: String): Promise\<boolean>

Checks whether a device super administrator application is enabled based on the specified bundle name. This API uses a promise to return the result.

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**System API**: This is a system API.

**Parameters**

| Name       | Type    | Mandatory  | Description       |
| ---------- | ------ | ---- | --------- |
| bundleName | String | Yes   | Device super administrator application.|

**Return value**

| ID          | Error Message              |
| ----------------- | ------------------- |
| Promise\<boolean> | Promise used to return the result.|

**Example**

```js
let bundleName = "com.example.myapplication";
adminManager.isSuperAdmin(bundleName).then((result) => {
    console.log("result is " + result);
}).catch(error => {
    console.log("error occurs" + error);
});
```

## adminManager.setEnterpriseInfo

setEnterpriseInfo(admin: Want, enterpriseInfo: EnterpriseInfo, callback: AsyncCallback\<void>;): void

Sets the enterprise information of a device administrator application. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.SET_ENTERPRISE_INFO

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**System API**: This is a system API.

**Parameters**

| Name           | Type                                 | Mandatory  | Description                    |
| -------------- | ----------------------------------- | ---- | ---------------------- |
| admin          | [Want](js-apis-app-ability-want.md) | Yes   | Device administrator application.               |
| enterpriseInfo | [EnterpriseInfo](#enterpriseinfo)   | Yes   | Enterprise information of the device administrator application.          |
| callback       | AsyncCallback\<void>;               | Yes   | Callback used to return the result.|

**Error codes**

For details about the following error codes, see [Enterprise Device Management Error Codes](../errorcodes/errorcode-enterpriseDeviceManager.md).

| ID| Error Message                                              |
| ------- | ----------------------------------------------------- |
| 9200001 | the application is not an administrator of the device. |

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
adminManager.setEnterpriseInfo(wantTemp, enterpriseInfo, error => {
    if (error != null) {
        console.log("error occurs" + error);
        return;
    }
    console.log("setEnterpriseInfo success");
});
```

## adminManager.setEnterpriseInfo

setEnterpriseInfo(admin: Want, enterpriseInfo: EnterpriseInfo): Promise\<void>;

Sets the enterprise information of a device administrator application. This API uses a promise to return the result.

**Required permissions**: ohos.permission.SET_ENTERPRISE_INFO

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**System API**: This is a system API.

**Parameters**

| Name           | Type                                 | Mandatory  | Description          |
| -------------- | ----------------------------------- | ---- | ------------ |
| admin          | [Want](js-apis-app-ability-want.md) | Yes   | Device administrator application.     |
| enterpriseInfo | [EnterpriseInfo](#enterpriseinfo)   | Yes   | Enterprise information of the device administrator application.|

**Return value**

| Type               | Description                   |
| ----------------- | --------------------- |
| Promise\<void>    | Promise used to return the result.|

**Error codes**

For details about the following error codes, see [Enterprise Device Management Error Codes](../errorcodes/errorcode-enterpriseDeviceManager.md).

| ID| Error Message                                              |
| ------- | ----------------------------------------------------- |
| 9200001 | the application is not an administrator of the device. |

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
adminManager.setEnterpriseInfo(wantTemp, enterpriseInfo).catch(error => {
    console.log("error occurs" + error);
});
```

## adminManager.getEnterpriseInfo

getEnterpriseInfo(admin: Want, callback: AsyncCallback&lt;EnterpriseInfo&gt;): void

Obtains the enterprise information of a device administrator application. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**System API**: This is a system API.

**Parameters**

| Name     | Type                                      | Mandatory  | Description                      |
| -------- | ---------------------------------------- | ---- | ------------------------ |
| admin    | [Want](js-apis-app-ability-want.md)      | Yes   | Device administrator application.                 |
| callback | AsyncCallback&lt;[EnterpriseInfo](#enterpriseinfo)&gt; | Yes   | Callback used to return the enterprise information of the device administrator application.|

**Error codes**

For details about the following error codes, see [Enterprise Device Management Error Codes](../errorcodes/errorcode-enterpriseDeviceManager.md).

| ID| Error Message                                              |
| ------- | ----------------------------------------------------- |
| 9200001 | the application is not an administrator of the device. |

**Example**

```js
let wantTemp = {
    bundleName: "com.example.myapplication",
    abilityName: "com.example.myapplication.MainAbility",
};
adminManager.getEnterpriseInfo(wantTemp, (error, result) => {
    if (error != null) {
        console.log("error occurs" + error);
        return;
    }
    console.log(result.name);
    console.log(result.description);
});
```

## adminManager.getEnterpriseInfo

getEnterpriseInfo(admin: Want): Promise&lt;EnterpriseInfo&gt;

Obtains the enterprise information of a device administrator application. This API uses a promise to return the result.

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**System API**: This is a system API.

**Parameters**

| Name  | Type                                 | Mandatory  | Description     |
| ----- | ----------------------------------- | ---- | ------- |
| admin | [Want](js-apis-app-ability-want.md) | Yes   | Device administrator application.|

**Return value**

| Type                                      | Description                       |
| ---------------------------------------- | ------------------------- |
| Promise&lt;[EnterpriseInfo](#enterpriseinfo)&gt; | Promise used to return the enterprise information of the device administrator application.|

**Error codes**

For details about the following error codes, see [Enterprise Device Management Error Codes](../errorcodes/errorcode-enterpriseDeviceManager.md).

| ID| Error Message                                              |
| ------- | ----------------------------------------------------- |
| 9200001 | the application is not an administrator of the device. |

**Example**

```js
let wantTemp = {
    bundleName: "com.example.myapplication",
    abilityName: "com.example.myapplication.MainAbility",
};
adminManager.getEnterpriseInfo(wantTemp).then((result) => {
    console.log(result.name);
    console.log(result.description);
}).catch(error => {
    console.log("error occurs" + error);
});
```

## adminManager.subscribeManagedEvent

subscribeManagedEvent(admin: Want, managedEvents: Array\<ManagedEvent>, callback: AsyncCallback\<void>): void

Subscribes to system management events. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.ENTERPRISE_SUBSCRIBE_MANAGED_EVENT

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**System API**: This is a system API.

**Parameters**

| Name  | Type                                 | Mandatory  | Description     |
| ----- | ----------------------------------- | ---- | ------- |
| admin | [Want](js-apis-app-ability-want.md) | Yes   | Device administrator application.|
| managedEvents  | Array\<[ManagedEvent](#managedevent)> | Yes| Array of events to subscribe to.|
| callback | AsyncCallback\<void> | Yes| Callback used to return the result. If the subscription is successful, **err** is **null**. Otherwise, **err** is an error object.|

**Error codes**

For details about the following error codes, see [Enterprise Device Management Error Codes](../errorcodes/errorcode-enterpriseDeviceManager.md).

|ID| Error Message                                               |
| ------- | ----------------------------------------------------- |
| 9200001 | the application is not an administrator of the device. |
| 9200008 | the specified system events enum is invalid.          |

**Example**

```js
let wantTemp = {
    bundleName: "bundleName",
    abilityName: "abilityName",
};
let events = [0, 1];
adminManager.subscribeManagedEvent(wantTemp, events, (error) => {
    if (error) {
        console.log("error code:" + error.code + " error message:" + error.message);
    }
});
```

## adminManager.subscribeManagedEvent

subscribeManagedEvent(admin: Want, managedEvents: Array\<ManagedEvent>): Promise\<void>

Subscribes to system management events. This API uses a promise to return the result.

**Required permissions**: ohos.permission.ENTERPRISE_SUBSCRIBE_MANAGED_EVENT

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**System API**: This is a system API.

**Parameters**

| Name  | Type                                 | Mandatory  | Description     |
| ----- | ----------------------------------- | ---- | ------- |
| admin | [Want](js-apis-app-ability-want.md) | Yes   | Device administrator application.|
| managedEvents  | Array\<[ManagedEvent](#managedevent)> | Yes| Array of events to subscribe to.|

**Return value**

| Type  | Description                                 |
| ----- | ----------------------------------- |
| Promise\<void> | Promise that returns no value.|

**Error codes**

For details about the following error codes, see [Enterprise Device Management Error Codes](../errorcodes/errorcode-enterpriseDeviceManager.md).

| ID| Error Message                                              |
| ------- | ----------------------------------------------------- |
| 9200001 | the application is not an administrator of the device. |
| 9200008 | the specified system events enum is invalid.          |

**Example**

```js
let wantTemp = {
    bundleName: "bundleName",
    abilityName: "abilityName",
};
let events = [0, 1];
adminManager.subscribeManagedEvent(wantTemp, events).then(() => {
}).catch((error) => {
    console.log("error code:" + error.code + " error message:" + error.message);
})
```

## adminManager.unsubscribeManagedEvent

unsubscribeManagedEvent(admin: Want, managedEvents: Array\<ManagedEvent>, callback: AsyncCallback\<void>): void

Unsubscribes from system management events. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.ENTERPRISE_SUBSCRIBE_MANAGED_EVENT

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**System API**: This is a system API.

**Parameters**

| Name  | Type                                 | Mandatory  | Description     |
| ----- | ----------------------------------- | ---- | ------- |
| admin | [Want](js-apis-app-ability-want.md) | Yes   | Device administrator application.|
| managedEvents  | Array\<[ManagedEvent](#managedevent)> | Yes| Array of events to unsubscribe from.|
| callback | AsyncCallback\<void> | Yes| Callback used to return the result. If the unsubscription is successful, **err** is **null**. Otherwise, **err** is an error object.|

**Error codes**

For details about the following error codes, see [Enterprise Device Management Error Codes](../errorcodes/errorcode-enterpriseDeviceManager.md).

| ID| Error Message                                              |
| ------- | ----------------------------------------------------- |
| 9200001 | the application is not an administrator of the device. |
| 9200008 | the specified system events enum is invalid.          |

**Example**

```js
let wantTemp = {
    bundleName: "bundleName",
    abilityName: "abilityName",
};
let events = [0, 1];
adminManager.unsubscribeManagedEvent(wantTemp, events, (error) => {
    if (error) {
        console.log("error code:" + error.code + " error message:" + error.message);
    }
});
```

## adminManager.unsubscribeManagedEvent

unsubscribeManagedEvent(admin: Want, managedEvents: Array\<ManagedEvent>): Promise\<void>

Unsubscribes from system management events. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.ENTERPRISE_SUBSCRIBE_MANAGED_EVENT

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**System API**: This is a system API.

**Parameters**

| Name  | Type                                 | Mandatory  | Description     |
| ----- | ----------------------------------- | ---- | ------- |
| admin | [Want](js-apis-app-ability-want.md) | Yes   | Device administrator application.|
| managedEvents  | Array\<[ManagedEvent](#managedevent)> | Yes| Array of events to unsubscribe from.|

**Return value**

| Type  | Description                                 |
| ----- | ----------------------------------- |
| Promise\<void> | Promise that returns no value.|

**Error codes**

For details about the following error codes, see [Enterprise Device Management Error Codes](../errorcodes/errorcode-enterpriseDeviceManager.md).

| ID| Error Message                                              |
| ------- | ----------------------------------------------------- |
| 9200001 | the application is not an administrator of the device. |
| 9200008 | the specified system events enum is invalid.          |

**Example**

```js
let wantTemp = {
    bundleName: "bundleName",
    abilityName: "abilityName",
};
let events = [0, 1];
adminManager.unsubscribeManagedEvent(wantTemp, events).then(() => {
}).catch((error) => {
    console.log("error code:" + error.code + " error message:" + error.message);
})
```

## EnterpriseInfo

Describes the enterprise information of a device administrator application.

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**System API**: This is a system API.

| Name        | Type    | Readable| Writable  | Description                           |
| ----------- | --------| ---- | ----- | ------------------------------- |
| name        | string   | Yes  | No   | Name of the enterprise to which the device administrator application belongs.|
| description | string   | Yes  | No   | Description of the enterprise to which the device administrator application belongs.|

## AdminType

Enumerates the administrator types of the device administrator application.

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**System API**: This is a system API.

| Name               | Value | Description   |
| ----------------- | ---- | ----- |
| ADMIN_TYPE_NORMAL | 0x00 | Common administrator.|
| ADMIN_TYPE_SUPER  | 0x01 | Super administrator.|

## ManagedEvent

Enumerates the system management events that can be subscribed to.

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**System API**: This is a system API.

| Name                       | Value | Description          |
| -------------------------- | ---- | ------------- |
| MANAGED_EVENT_BUNDLE_ADDED | 0    | Application installation event.|
| MANAGED_EVENT_BUNDLE_REMOVED | 1  | Application uninstallation event.|
