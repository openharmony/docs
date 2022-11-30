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

enableAdmin(admin: Want, enterpriseInfo: EnterpriseInfo, type: AdminType, callback: AsyncCallback\<void>): void

Enables a device administrator application based on the specified bundle name and class name. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.MANAGE_ENTERPRISE_DEVICE_ADMIN

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**System API**: This is a system API.

**Parameters**

| Name           | Type                                 | Mandatory  | Description                |
| -------------- | ----------------------------------- | ---- | ------------------ |
| admin          | [Want](js-apis-application-Want.md) | Yes   | Device administrator application.           |
| enterpriseInfo | [EnterpriseInfo](#enterpriseinfo)   | Yes   | Enterprise information of the device administrator application.      |
| type           | [AdminType](#admintype)             | Yes   | Type of the device administrator to enable.        |
| callback       | AsyncCallback\<void>                | Yes   | Callback used to return the result.|

**Error codes**

| Type     | Description                                                          |
| ------- | --------------------------------------------------------------- |
| 9200003 | The administrator ability component is invalid.                 |
| 9200004 | Failed to activate the administrator application of the device. |
| 9200007 | The system ability work abnormally.                             |

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
enterpriseDeviceManager.enableAdmin(wantTemp, enterpriseInfo, enterpriseDeviceManager.AdminType.ADMIN_TYPE_NORMAL, error => {
    if (error != null) {
        console.log("error occurs" + error);
        return;
    }
    console.log("enableAdmin success");
});
```

## enterpriseDeviceManager.enableAdmin

enableAdmin(admin: Want, enterpriseInfo: EnterpriseInfo, type: AdminType, userId: number, callback: AsyncCallback\<void>): void

Enables a device administrator application based on the specified bundle name and class name. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.MANAGE_ENTERPRISE_DEVICE_ADMIN

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**System API**: This is a system API.

**Parameters**

| Name           | Type                                 | Mandatory  | Description                          |
| -------------- | ----------------------------------- | ---- | ---------------------------- |
| admin          | [Want](js-apis-application-Want.md) | Yes   | Device administrator application.                     |
| enterpriseInfo | [EnterpriseInfo](#enterpriseinfo)   | Yes   | Enterprise information of the device administrator application.                |
| type           | [AdminType](#admintype)             | Yes   | Type of the device administrator to enable.                  |
| userId         | number                              | Yes   | User ID The default value is the user ID of the caller. The value must be greater than or equal to 0.|
| callback       | AsyncCallback\<void>                | Yes   | Callback used to return the result.          |

**Error codes**

| Type     | Description                                                          |
| ------- | --------------------------------------------------------------- |
| 9200003 | The administrator ability component is invalid.                 |
| 9200004 | Failed to activate the administrator application of the device. |
| 9200007 | The system ability work abnormally.                             |

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
enterpriseDeviceManager.enableAdmin(wantTemp, enterpriseInfo, enterpriseDeviceManager.AdminType.ADMIN_TYPE_NORMAL, 100, error => {
    if (error != null) {
        console.log("error occurs" + error);
        return;
    }
    console.log("enableAdmin success");
});
```

## enterpriseDeviceManager.enableAdmin

enableAdmin(admin: Want, enterpriseInfo: EnterpriseInfo, type: AdminType, userId?: number): Promise\<void>

Enables a device administrator application based on the specified bundle name and class name. This API uses a promise to return the result.

**Required permissions**: ohos.permission.MANAGE_ENTERPRISE_DEVICE_ADMIN

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**System API**: This is a system API.

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
| Promise\<void>    | Promise used to return the result.|

**Error codes**

| Type     | Description                                                          |
| ------- | --------------------------------------------------------------- |
| 9200003 | The administrator ability component is invalid.                 |
| 9200004 | Failed to activate the administrator application of the device. |
| 9200007 | The system ability work abnormally.                             |

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
.catch(error => {
    console.log("error occurs" + error);
});
```

## enterpriseDeviceManager.disableAdmin

disableAdmin(admin: Want, callback: AsyncCallback\<void>): void

Disables a device common administrator application based on the specified bundle name and class name. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.MANAGE_ENTERPRISE_DEVICE_ADMIN

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**System API**: This is a system API.

**Parameters**

| Name     | Type                                 | Mandatory  | Description                 |
| -------- | ----------------------------------- | ---- | ------------------- |
| admin    | [Want](js-apis-application-Want.md) | Yes   | Device common administrator application.          |
| callback | AsyncCallback\<void>                | Yes   | Callback used to return the result.|

**Error codes**

| Type     | Description                                                             |
| ------- | ----------------------------------------------------------------- |
| 9200005 | Failed to deactivate the administrator application of the device. |

**Example**

```js
let wantTemp = {
    bundleName: "bundleName",
    abilityName: "abilityName",
};
enterpriseDeviceManager.disableAdmin(wantTemp, error => {
    if (error != null) {
        console.log("error occurs" + error);
        return;
    }
    console.log("disableAdmin success ");
});
```

## enterpriseDeviceManager.disableAdmin

disableAdmin(admin: Want, userId: number, callback: AsyncCallback\<void>): void

Disables a device common administrator application based on the specified bundle name and class name. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.MANAGE_ENTERPRISE_DEVICE_ADMIN

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**System API**: This is a system API.

**Parameters**

| Name     | Type                                 | Mandatory  | Description                          |
| -------- | ----------------------------------- | ---- | ---------------------------- |
| admin    | [Want](js-apis-application-Want.md) | Yes   | Device common administrator application.                   |
| userId   | number                              | Yes   | User ID The default value is the user ID of the caller. The value must be greater than or equal to 0.|
| callback | AsyncCallback\<void>                | Yes   | Callback used to return the result.         |

**Error codes**

| Type     | Description                                                             |
| ------- | ----------------------------------------------------------------- |
| 9200005 | Failed to deactivate the administrator application of the device. |

**Example**

```js
let wantTemp = {
    bundleName: "bundleName",
    abilityName: "abilityName",
};
enterpriseDeviceManager.disableAdmin(wantTemp, 100, error => {
    if (error != null) {
        console.log("error occurs" + error);
        return;
    }
    console.log("disableAdmin success ");
});
```

## enterpriseDeviceManager.disableAdmin

disableAdmin(admin: Want, userId?: number): Promise\<void>

Disables a device common administrator application based on the specified bundle name and class name. This API uses a promise to return the result.

**Required permissions**: ohos.permission.MANAGE_ENTERPRISE_DEVICE_ADMIN

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**System API**: This is a system API.

**Parameters**

| Name   | Type                                 | Mandatory  | Description                          |
| ------ | ----------------------------------- | ---- | ---------------------------- |
| admin  | [Want](js-apis-application-Want.md) | Yes   | Device common administrator application.                   |
| userId | number                              | No   | User ID The default value is the user ID of the caller. The value must be greater than or equal to 0.|

**Return value**

| Type               | Description               |
| ----------------- | ----------------- |
| Promise\<void>    | Promise used to return the result.|

**Error codes**

| Type     | Description                                                             |
| ------- | ----------------------------------------------------------------- |
| 9200005 | Failed to deactivate the administrator application of the device. |

**Example**

```js
let wantTemp = {
    bundleName: "bundleName",
    abilityName: "abilityName",
};
enterpriseDeviceManager.disableAdmin(wantTemp, 100).catch(error => {
    console.log("error occurs" + error);
});
```

## enterpriseDeviceManager.disableSuperAdmin

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

| Type     | Description                                                             |
| ------- | ----------------------------------------------------------------- |
| 9200005 | Failed to deactivate the administrator application of the device. |

**Example**

```js
let bundleName = "com.example.myapplication";
enterpriseDeviceManager.disableSuperAdmin(bundleName, error => {
    if (error != null) {
        console.log("error occurs" + error);
        return;
    }
    console.log("disableSuperAdmin success");
});
```

## enterpriseDeviceManager.disableSuperAdmin

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

| Type     | Description                                                             |
| ------- | ----------------------------------------------------------------- |
| 9200005 | Failed to deactivate the administrator application of the device. |

**Example**

```js
let bundleName = "com.example.myapplication";
enterpriseDeviceManager.disableSuperAdmin(bundleName).catch(error => {
    console.log("error occurs" + error);
});
```

## enterpriseDeviceManager.isAdminEnabled

isAdminEnabled(admin: Want, callback: AsyncCallback\<boolean>): void

Checks whether a device administrator application is enabled based on the specified bundle name and class name. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**System API**: This is a system API.

**Parameters**

| Name     | Type                                 | Mandatory  | Description                  |
| -------- | ----------------------------------- | ---- | -------------------- |
| admin    | [Want](js-apis-application-Want.md) | Yes   | Device administrator application.             |
| callback | AsyncCallback\<boolean>             | Yes   | Callback used to return the result.|

**Error codes**

| Type     | Description                                                             |
| ------- | ----------------------------------------------------------------- |
| 9200005 | Failed to deactivate the administrator application of the device. |

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

**System API**: This is a system API.

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

**System API**: This is a system API.

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

**System API**: This is a system API.

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

**System API**: This is a system API.

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

**Error codes**

| Type     | Description                                                                        |
| ------- | ---------------------------------------------------------------------------- |
| 9200001 | The application is not a administrator of the device.                        |
| 9200002 | The administrator application does not have permission to manage the device. |

**Example**

```js
let wantTemp = {
    bundleName: "bundleName",
    abilityName: "abilityName",
};
enterpriseDeviceManager.getDeviceSettingsManager((error, mgr) => {
    if (error != null) {
        console.log("error code:" + error.code);
        return;
    }
    mgr.setDateTime(wantTemp, 1526003846000, (error) => { 
        if (error != null) {
            console.log("error code:" + error.code);
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

**Error codes**

| Type     | Description                                                                        |
| ------- | ---------------------------------------------------------------------------- |
| 9200001 | The application is not a administrator of the device.                        |
| 9200002 | The administrator application does not have permission to manage the device. |

**Example**

```js
let wantTemp = {
    bundleName: "bundleName",
    abilityName: "abilityName",
};
enterpriseDeviceManager.getDeviceSettingsManager().then((mgr) => {
    mgr.setDateTime(wantTemp, 1526003846000).catch((error) => {
        console.log("error code:" + error.code);
    })
}).catch((error) => {
    console.log("error code:" + error.code);
})
```

## enterpriseDeviceManager.setEnterpriseInfo

setEnterpriseInfo(admin: Want, enterpriseInfo: EnterpriseInfo, callback: AsyncCallback\<void>;): void

Sets the enterprise information of a device administrator application. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.SET_ENTERPRISE_INFO

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**System API**: This is a system API.

**Parameters**

| Name           | Type                                 | Mandatory  | Description                    |
| -------------- | ----------------------------------- | ---- | ---------------------- |
| admin          | [Want](js-apis-application-Want.md) | Yes   | Device administrator application.               |
| enterpriseInfo | [EnterpriseInfo](#enterpriseinfo)   | Yes   | Enterprise information of the device administrator application.          |
| callback       | AsyncCallback\<void>;               | Yes   | Callback used to return the result.|

**Error codes**

| Type     | Description                                                 |
| ------- | ----------------------------------------------------- |
| 9200001 | The application is not a administrator of the device. |

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
enterpriseDeviceManager.setEnterpriseInfo(wantTemp, enterpriseInfo, error => {
    if (error != null) {
        console.log("error occurs" + error);
        return;
    }
    console.log("setEnterpriseInfo success");
});
```

## enterpriseDeviceManager.setEnterpriseInfo

setEnterpriseInfo(admin: Want, enterpriseInfo: EnterpriseInfo): Promise\<void>;

Sets the enterprise information of a device administrator application. This API uses a promise to return the result.

**Required permissions**: ohos.permission.SET_ENTERPRISE_INFO

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**System API**: This is a system API.

**Parameters**

| Name           | Type                                 | Mandatory  | Description          |
| -------------- | ----------------------------------- | ---- | ------------ |
| admin          | [Want](js-apis-application-Want.md) | Yes   | Device administrator application.     |
| enterpriseInfo | [EnterpriseInfo](#enterpriseinfo)   | Yes   | Enterprise information of the device administrator application.|

**Return value**

| Type               | Description                   |
| ----------------- | --------------------- |
| Promise\<void>    | Promise used to return the result.|

**Error codes**

| Type     | Description                                                 |
| ------- | ----------------------------------------------------- |
| 9200001 | The application is not a administrator of the device. |

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
enterpriseDeviceManager.setEnterpriseInfo(wantTemp, enterpriseInfo).catch(error => {
    console.log("error occurs" + error);
});
```

## enterpriseDeviceManager.getEnterpriseInfo

getEnterpriseInfo(admin: Want, callback: AsyncCallback&lt;EnterpriseInfo&gt;): void

Obtains the enterprise information of a device administrator application. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**System API**: This is a system API.

**Parameters**

| Name     | Type                                      | Mandatory  | Description                      |
| -------- | ---------------------------------------- | ---- | ------------------------ |
| admin    | [Want](js-apis-application-Want.md)      | Yes   | Device administrator application.                 |
| callback | AsyncCallback&lt;[EnterpriseInfo](#enterpriseinfo)&gt; | Yes   | Callback used to return the enterprise information of the device administrator application.|

**Error codes**

| Type     | Description                                                 |
| ------- | ----------------------------------------------------- |
| 9200001 | The application is not a administrator of the device. |

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

**System API**: This is a system API.

**Parameters**

| Name  | Type                                 | Mandatory  | Description     |
| ----- | ----------------------------------- | ---- | ------- |
| admin | [Want](js-apis-application-Want.md) | Yes   | Device administrator application.|

**Return value**

| Type                                      | Description                       |
| ---------------------------------------- | ------------------------- |
| Promise&lt;[EnterpriseInfo](#enterpriseinfo)&gt; | Promise used to return the enterprise information of the device administrator application.|

**Error codes**

| Type     | Description                                                 |
| ------- | ----------------------------------------------------- |
| 9200001 | The application is not a administrator of the device. |

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

## enterpriseDeviceManager.subscribeManagedEvent

subscribeManagedEvent(admin: Want, managedEvents: Array\<ManagedEvent>, callback: AsyncCallback\<void>): void

Subscribes to system management events. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.ENTERPRISE_SUBSCRIBE_MANAGED_EVENT

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**System API**: This is a system API.

**Parameters**

| Name  | Type                                 | Mandatory  | Description     |
| ----- | ----------------------------------- | ---- | ------- |
| admin | [Want](js-apis-application-Want.md) | Yes   | Device administrator application.|
| managedEvents  | Array\<[ManagedEvent](#managedevent)> | Yes| Array of events to subscribe to.|
| callback | AsyncCallback\<void> | Yes| Callback used to return the result. If the subscription is successful, **err** is **null**. Otherwise, **err** is an error object.|

**Example**

```js
let wantTemp = {
    bundleName: "bundleName",
    abilityName: "abilityName",
};
let events = [0, 1];
enterpriseDeviceManager.subscribeManagedEvent(wantTemp, events, (error) => {
    if (error) {
        console.log("error code:" + error.code + " error message:" + error.message);
    }
});
```

## enterpriseDeviceManager.subscribeManagedEvent

subscribeManagedEvent(admin: Want, managedEvents: Array\<ManagedEvent>): Promise\<void>

Subscribes to system management events. This API uses a promise to return the result.

**Required permissions**: ohos.permission.ENTERPRISE_SUBSCRIBE_MANAGED_EVENT

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**System API**: This is a system API.

**Parameters**

| Name  | Type                                 | Mandatory  | Description     |
| ----- | ----------------------------------- | ---- | ------- |
| admin | [Want](js-apis-application-Want.md) | Yes   | Device administrator application.|
| managedEvents  | Array\<[ManagedEvent](#managedevent)> | Yes| Array of events to subscribe to.|

**Return value**

| Type  | Description                                 |
| ----- | ----------------------------------- |
| Promise\<void> | Promise used to return the result. Promise that returns no value.|

**Example**

```js
let wantTemp = {
    bundleName: "bundleName",
    abilityName: "abilityName",
};
let events = [0, 1];
enterpriseDeviceManager.subscribeManagedEvent(wantTemp, events).then(() => {
}).catch((error) => {
    console.log("error code:" + error.code + " error message:" + error.message);
})
```

## enterpriseDeviceManager.unsubscribeManagedEvent

unsubscribeManagedEvent(admin: Want, managedEvents: Array\<ManagedEvent>, callback: AsyncCallback\<void>): void

Unsubscribes from system management events. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.ENTERPRISE_SUBSCRIBE_MANAGED_EVENT

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**System API**: This is a system API.

**Parameters**

| Name  | Type                                 | Mandatory  | Description     |
| ----- | ----------------------------------- | ---- | ------- |
| admin | [Want](js-apis-application-Want.md) | Yes   | Device administrator application.|
| managedEvents  | Array\<[ManagedEvent](#managedevent)> | Yes| Array of events to unsubscribe from.|
| callback | AsyncCallback\<void> | Yes| Callback used to return the result. If the unsubscription is successful, **err** is **null**. Otherwise, **err** is an error object.|

**Example**

```js
let wantTemp = {
    bundleName: "bundleName",
    abilityName: "abilityName",
};
let events = [0, 1];
enterpriseDeviceManager.unsubscribeManagedEvent(wantTemp, events, (error) => {
    if (error) {
        console.log("error code:" + error.code + " error message:" + error.message);
    }
});
```

## enterpriseDeviceManager.unsubscribeManagedEvent

unsubscribeManagedEvent(admin: Want, managedEvents: Array\<ManagedEvent>): Promise\<void>

Unsubscribes from system management events. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.ENTERPRISE_SUBSCRIBE_MANAGED_EVENT

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**System API**: This is a system API.

**Parameters**

| Name  | Type                                 | Mandatory  | Description     |
| ----- | ----------------------------------- | ---- | ------- |
| admin | [Want](js-apis-application-Want.md) | Yes   | Device administrator application.|
| managedEvents  | Array\<[ManagedEvent](#managedevent)> | Yes| Array of events to unsubscribe from.|

**Return value**

| Type  | Description                                 |
| ----- | ----------------------------------- |
| Promise\<void> | Promise used to return the result. Promise that returns no value.|

**Example**

```js
let wantTemp = {
    bundleName: "bundleName",
    abilityName: "abilityName",
};
let events = [0, 1];
enterpriseDeviceManager.unsubscribeManagedEvent(wantTemp, events).then(() => {
}).catch((error) => {
    console.log("error code:" + error.code + " error message:" + error.message);
})
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

## ManagedEvent

Enumerates the system management events that can be subscribed to.

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

| Name               | Default Value | Description   |
| ----------------- | ---- | ----- |
| MANAGED_EVENT_BUNDLE_ADDED | 0 | Application installation event.|
| MANAGED_EVENT_BUNDLE_REMOVED  | 1 | Application uninstallation event.|
