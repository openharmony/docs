# @ohos.enterprise.bundleManager (Bundle Management)

The **bundleManager** module provides APIs for bundle management, including adding, obtaining, and removing a list of bundles that are allowed to install. Only the enterprise device administrator applications can call the APIs provided by this module.

> **NOTE**
>
> The initial APIs of this module are supported since API version 10. Newly added APIs will be marked with a superscript to indicate their earliest API version.
> The APIs of this module can be called only after a [device administrator application](js-apis-enterprise-adminManager.md#adminmanagerenableadmin) is enabled.

## Modules to Import

```js
import bundleManager from '@ohos.enterprise.bundleManager';
```

## bundleManager.addAllowedInstallBundles

addAllowedInstallBundles(admin: Want, appIds: Array\<string>, callback: AsyncCallback&lt;void&gt;): void;

Adds a list of bundles that are allowed to be installed by the current administrator for an enterprise device administrator application. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.ENTERPRISE_SET_BUNDLE_INSTALL_POLICY

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**System API**: This is a system API.

**Parameters**

| Name     | Type                                      | Mandatory  | Description                      |
| -------- | ---------------------------------------- | ---- | ------------------------------- |
| admin    | [Want](js-apis-app-ability-want.md)     | Yes   | Target enterprise device administrator application.                 |
| appIds    | Array&lt;string&gt;                | Yes   | Bundles to be added to the allowed bundle list.                 |
| callback | AsyncCallback&lt;void&gt;            | Yes   | Callback used to return the result. If the operation is successful, **err** is **null**. Otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](../errorcodes/errorcode-enterpriseDeviceManager.md).

| ID| Error Message                                                                      |          
| ------- | ---------------------------------------------------------------------------- |
| 9200001 | the application is not an administrator of the device.                              |
| 9200002 | the administrator application does not have permission to manage the device.                                          |

**Example:**

```js
let wantTemp = {
    bundleName: "com.example.myapplication",
    abilityName: "EntryAbility",
};
let appIds = ["com.example.myapplication"];

bundleManager.addAllowedInstallBundles(wantTemp, appIds, (error) => {
    if (error != null) {
        console.log("error code:" + error.code + " error message:" + error.message);
    }
});
```

## bundleManager.addAllowedInstallBundles

addAllowedInstallBundles(admin: Want, appIds: Array\<string>, userId: number, callback: AsyncCallback&lt;void&gt;): void;

Adds a list of bundles that are allowed to be installed by the given user (specified by **userId**) for an enterprise device administrator application. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.ENTERPRISE_SET_BUNDLE_INSTALL_POLICY

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**System API**: This is a system API.

**Parameters**

| Name  | Type                                 | Mandatory  | Description     |
| ----- | ----------------------------------- | ---- | ------- |
| admin    | [Want](js-apis-app-ability-want.md)     | Yes   | Target enterprise device administrator application.                 |
| appIds    | Array&lt;string&gt;                | Yes   | Bundles to be added to the allowed bundle list.                 |
| userId     | number                             | Yes   | User ID. The default value is the user ID of the caller. The value must be greater than or equal to 0.|
| callback | AsyncCallback&lt;void&gt;            | Yes   | Callback used to return the result. If the operation is successful, **err** is **null**. Otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](../errorcodes/errorcode-enterpriseDeviceManager.md).

| ID| Error Message                                                                    |          
| ------- | ---------------------------------------------------------------------------- |
| 9200001 | the application is not an administrator of the device.                              |
| 9200002 | the administrator application does not have permission to manage the device.                                          |

**Example:**

```js
let wantTemp = {
    bundleName: "com.example.myapplication",
    abilityName: "EntryAbility",
};
let appIds = ["com.example.myapplication"];

bundleManager.addAllowedInstallBundles(wantTemp, appIds, 100, (error) => {
    if (error != null) {
        console.log("error code:" + error.code + " error message:" + error.message);
    }
});
```

## bundleManager.addAllowedInstallBundles

addAllowedInstallBundles(admin: Want, appIds: Array\<string>, userId?: number): Promise&lt;void&gt;;

Adds a list of bundles that are allowed to be installed by the current administrator (if **userId** is not passed in) or the given user (if **userId** is passed in) for an enterprise device administrator application. This API uses a promise to return the result.

**Required permissions**: ohos.permission.ENTERPRISE_SET_BUNDLE_INSTALL_POLICY

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**System API**: This is a system API.

**Parameters**

| Name  | Type                                 | Mandatory  | Description     |
| ----- | ----------------------------------- | ---- | ------- |
| admin    | [Want](js-apis-app-ability-want.md)     | Yes   | Target enterprise device administrator application.                 |
| appIds    | Array&lt;string&gt;                | Yes   | Bundles to be added to the allowed bundle list.                 |
| userId     | number                             | No   | User ID. The default value is the user ID of the caller. The value must be greater than or equal to 0.|

**Return value**

| Type                  | Description                     |
| --------------------- | ------------------------- |
| Promise&lt;void&gt; | Promise that returns no value. If the operation fails, an error object is thrown. |

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](../errorcodes/errorcode-enterpriseDeviceManager.md).

| ID| Error Message                                                                    |          
| ------- | ---------------------------------------------------------------------------- |
| 9200001 | the application is not an administrator of the device.                              |
| 9200002 | the administrator application does not have permission to manage the device.                                          |

**Example:**

```js
let wantTemp = {
    bundleName: "com.example.myapplication",
    abilityName: "EntryAbility",
};
let appIds = ["com.example.myapplication"];

bundleManager.addAllowedInstallBundles(wantTemp, appIds, 100).then(() => {
    console.log("success");
}).catch(error => {
    console.log("error code:" + error.code + " error message:" + error.message);
});
```

## bundleManager.removeAllowedInstallBundles

removeAllowedInstallBundles(admin: Want, appIds: Array\<string>, callback: AsyncCallback&lt;void&gt;): void;

Removes a list of bundles that are allowed to be installed by the current administrator for an enterprise device administrator application. The bundles removed from the list can no longer be installed. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.ENTERPRISE_SET_BUNDLE_INSTALL_POLICY

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**System API**: This is a system API.

**Parameters**

| Name     | Type                                      | Mandatory  | Description                      |
| -------- | ---------------------------------------- | ---- | ------------------------------- |
| admin    | [Want](js-apis-app-ability-want.md)     | Yes   | Target enterprise device administrator application.                 |
| appIds    | Array&lt;string&gt;                | Yes   | Bundles to be removed from the allowed bundle list.                 |
| callback | AsyncCallback&lt;void&gt;            | Yes   | Callback used to return the result. If the operation is successful, **err** is **null**. Otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](../errorcodes/errorcode-enterpriseDeviceManager.md).

| ID| Error Message                                                                      |          
| ------- | ---------------------------------------------------------------------------- |
| 9200001 | the application is not an administrator of the device.                              |
| 9200002 | the administrator application does not have permission to manage the device.                                          |

**Example:**

```js
let wantTemp = {
    bundleName: "com.example.myapplication",
    abilityName: "EntryAbility",
};
let appIds = ["com.example.myapplication"];

bundleManager.removeAllowedInstallBundles(wantTemp, appIds, (error) => {
    if (error != null) {
        console.log("error code:" + error.code + " error message:" + error.message);
    }
});
```

## bundleManager.removeAllowedInstallBundles

removeAllowedInstallBundles(admin: Want, appIds: Array\<string>, userId: number, callback: AsyncCallback&lt;void&gt;): void;

Removes a list of bundles that are allowed to be installed by the given user (specified by **userId**) for an enterprise device administrator application. The bundles removed from the list can no longer be installed. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.ENTERPRISE_SET_BUNDLE_INSTALL_POLICY

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**System API**: This is a system API.

**Parameters**

| Name  | Type                                 | Mandatory  | Description     |
| ----- | ----------------------------------- | ---- | ------- |
| admin    | [Want](js-apis-app-ability-want.md)     | Yes   | Target enterprise device administrator application.                 |
| appIds    | Array&lt;string&gt;                | Yes   | Bundles to be removed from the allowed bundle list.                 |
| userId     | number                             | Yes   | User ID. The default value is the user ID of the caller. The value must be greater than or equal to 0.|
| callback | AsyncCallback&lt;void&gt;            | Yes   | Callback used to return the result. If the operation is successful, **err** is **null**. Otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](../errorcodes/errorcode-enterpriseDeviceManager.md).

| ID| Error Message                                                                    |          
| ------- | ---------------------------------------------------------------------------- |
| 9200001 | the application is not an administrator of the device.                              |
| 9200002 | the administrator application does not have permission to manage the device.                                          |

**Example:**

```js
let wantTemp = {
    bundleName: "com.example.myapplication",
    abilityName: "EntryAbility",
};
let appIds = ["com.example.myapplication"];

bundleManager.removeAllowedInstallBundles(wantTemp, appIds, 100, (error) => {
    if (error != null) {
        console.log("error code:" + error.code + " error message:" + error.message);
    }
});
```

## bundleManager.removeAllowedInstallBundles

removeAllowedInstallBundles(admin: Want, appIds: Array\<string>, userId?: number): Promise&lt;void&gt;;

Removes a list of bundles that are allowed to be installed by the current administrator (if **userId** is not passed in) or the given user (if **userId** is passed in) for an enterprise device administrator application. The bundles removed from the list can no longer be installed. This API uses a promise to return the result.

**Required permissions**: ohos.permission.ENTERPRISE_SET_BUNDLE_INSTALL_POLICY

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**System API**: This is a system API.

**Parameters**

| Name  | Type                                 | Mandatory  | Description     |
| ----- | ----------------------------------- | ---- | ------- |
| admin    | [Want](js-apis-app-ability-want.md)     | Yes   | Target enterprise device administrator application.                 |
| appIds    | Array\&lt;string&gt;                | Yes   | Bundles to be removed from the allowed bundle list.                 |
| userId     | number                             | No   | User ID. The default value is the user ID of the caller. The value must be greater than or equal to 0.|

**Return value**

| Type                  | Description                     |
| --------------------- | ------------------------- |
| Promise&lt;void&gt; | Promise that returns no value. If the operation fails, an error object is thrown. |

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](../errorcodes/errorcode-enterpriseDeviceManager.md).

| ID| Error Message                                                                    |          
| ------- | ---------------------------------------------------------------------------- |
| 9200001 | the application is not an administrator of the device.                              |
| 9200002 | the administrator application does not have permission to manage the device.                                          |

**Example:**

```js
let wantTemp = {
    bundleName: "com.example.myapplication",
    abilityName: "EntryAbility",
};
let appIds = ["com.example.myapplication"];

bundleManager.removeAllowedInstallBundles(wantTemp, appIds, 100).then(() => {
    console.log("success");
}).catch(error => {
    console.log("error code:" + error.code + " error message:" + error.message);
});
```

## bundleManager.getAllowedInstallBundles

getAllowedInstallBundles(admin: Want, callback: AsyncCallback&lt;Array&lt;string&gt;&gt;): void;

Obtains the list of bundles that are allowed to be installed by the current administrator for an enterprise device administrator application. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.ENTERPRISE_SET_BUNDLE_INSTALL_POLICY

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**System API**: This is a system API.

**Parameters**

| Name     | Type                                      | Mandatory  | Description                      |
| -------- | ---------------------------------------- | ---- | ------------------------------- |
| admin    | [Want](js-apis-app-ability-want.md)     | Yes   | Target enterprise device administrator application.                 |
| callback | AsyncCallback&lt;Array&lt;string&gt;&gt;       | Yes   | Callback used to return the result. If the operation is successful, **err** is **null**. Otherwise, **err** is an error object.      |

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](../errorcodes/errorcode-enterpriseDeviceManager.md).

| ID| Error Message                                                                      |          
| ------- | ---------------------------------------------------------------------------- |
| 9200001 | the application is not an administrator of the device.                              |
| 9200002 | the administrator application does not have permission to manage the device.                                          |

**Example:**

```js
let wantTemp = {
    bundleName: "com.example.myapplication",
    abilityName: "EntryAbility",
};

bundleManager.getAllowedInstallBundles(wantTemp, (error) => {
    if (error != null) {
        console.log("error code:" + error.code + " error message:" + error.message);
    }
});
```

## bundleManager.getAllowedInstallBundles

getAllowedInstallBundles(admin: Want, userId: number, callback: AsyncCallback&lt;Array&lt;string&gt;&gt;): void;

Obtains the list of bundles that are allowed to be installed by the given user (specified by **userId**) for an enterprise device administrator application. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.ENTERPRISE_SET_BUNDLE_INSTALL_POLICY

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**System API**: This is a system API.

**Parameters**

| Name     | Type                                      | Mandatory  | Description                      |
| -------- | ---------------------------------------- | ---- | ------------------------------- |
| admin    | [Want](js-apis-app-ability-want.md)     | Yes   | Target enterprise device administrator application.                 |
| userId     | number                             | Yes   | User ID. The default value is the user ID of the caller. The value must be greater than or equal to 0.|
| callback | AsyncCallback&lt;Array&lt;string&gt;&gt;       | Yes   | Callback used to return the result. If the operation is successful, **err** is **null**. Otherwise, **err** is an error object.      |

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](../errorcodes/errorcode-enterpriseDeviceManager.md).

| ID| Error Message                                                                      |          
| ------- | ---------------------------------------------------------------------------- |
| 9200001 | the application is not an administrator of the device.                              |
| 9200002 | the administrator application does not have permission to manage the device.                                          |

**Example:**

```js
let wantTemp = {
    bundleName: "com.example.myapplication",
    abilityName: "EntryAbility",
};

bundleManager.getAllowedInstallBundles(wantTemp, 100, (error) => {
    if (error != null) {
        console.log("error code:" + error.code + " error message:" + error.message);
    }
});
```

## bundleManager.getAllowedInstallBundles

getAllowedInstallBundles(admin: Want, userId?: number): Promise&lt;Array&lt;string&gt;&gt;;

Obtains the list of bundles that are allowed to be installed by the current administrator (if **userId** is not passed in) or the given user (if **userId** is passed in) for an enterprise device administrator application. This API uses a promise to return the result.

**Required permissions**: ohos.permission.ENTERPRISE_SET_BUNDLE_INSTALL_POLICY

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**System API**: This is a system API.

**Parameters**

| Name  | Type                                 | Mandatory  | Description     |
| ----- | ----------------------------------- | ---- | ------- |
| admin | [Want](js-apis-app-ability-want.md) | Yes   | Target enterprise device administrator application.|
| userId     | number                             | No   | User ID. The default value is the user ID of the caller. The value must be greater than or equal to 0.|

**Return value**

| Type                  | Description                     |
| --------------------- | ------------------------- |
| Promise&lt;Array&lt;string&gt;&gt; | Promise used to return the allowed bundle list.|

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](../errorcodes/errorcode-enterpriseDeviceManager.md).

| ID| Error Message                                                                    |          
| ------- | ---------------------------------------------------------------------------- |
| 9200001 | the application is not an administrator of the device.                              |
| 9200002 | the administrator application does not have permission to manage the device.                                          |

**Example:**

```js
let wantTemp = {
    bundleName: "com.example.myapplication",
    abilityName: "EntryAbility",
};
bundleManager.getAllowedInstallBundles(wantTemp, 100).then(() => {
    console.log("success");
}).catch(error => {
    console.log("error code:" + error.code + " error message:" + error.message);
});
```

## bundleManager.addDisallowedInstallBundles

addDisallowedInstallBundles(admin: Want, appIds: Array\<string>, callback: AsyncCallback&lt;void&gt;): void;

Adds a list of bundles that are not allowed to be installed by the current administrator for an enterprise device administrator application. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.ENTERPRISE_SET_BUNDLE_INSTALL_POLICY

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**System API**: This is a system API.

**Parameters**

| Name     | Type                                      | Mandatory  | Description                      |
| -------- | ---------------------------------------- | ---- | ------------------------------- |
| admin    | [Want](js-apis-app-ability-want.md)     | Yes   | Target enterprise device administrator application.                 |
| appIds    | Array&lt;string&gt;                | Yes   | Bundles to be added to the disallowed bundle list.                 |
| callback | AsyncCallback&lt;void&gt;            | Yes   | Callback used to return the result. If the operation is successful, **err** is **null**. Otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](../errorcodes/errorcode-enterpriseDeviceManager.md).

| ID| Error Message                                                                      |          
| ------- | ---------------------------------------------------------------------------- |
| 9200001 | the application is not an administrator of the device.                              |
| 9200002 | the administrator application does not have permission to manage the device.                                          |

**Example:**

```js
let wantTemp = {
    bundleName: "com.example.myapplication",
    abilityName: "EntryAbility",
};
let appIds = ["com.example.myapplication"];

bundleManager.addDisallowedInstallBundles(wantTemp, appIds, (error) => {
    if (error != null) {
        console.log("error code:" + error.code + " error message:" + error.message);
    }
});
```

## bundleManager.addDisallowedInstallBundles

addDisallowedInstallBundles(admin: Want, appIds: Array\<string>, userId: number, callback: AsyncCallback&lt;void&gt;): void;

Adds a list of bundles that are not allowed to be installed by the given user (specified by **userId**) for an enterprise device administrator application. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.ENTERPRISE_SET_BUNDLE_INSTALL_POLICY

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**System API**: This is a system API.

**Parameters**

| Name  | Type                                 | Mandatory  | Description     |
| ----- | ----------------------------------- | ---- | ------- |
| admin    | [Want](js-apis-app-ability-want.md)     | Yes   | Target enterprise device administrator application.                 |
| appIds    | Array&lt;string&gt;                | Yes   | Bundles to be added to the disallowed bundle list.                 |
| userId     | number                             | Yes   | User ID. The default value is the user ID of the caller. The value must be greater than or equal to 0.|
| callback | AsyncCallback&lt;void&gt;            | Yes   | Callback used to return the result. If the operation is successful, **err** is **null**. Otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](../errorcodes/errorcode-enterpriseDeviceManager.md).

| ID| Error Message                                                                    |          
| ------- | ---------------------------------------------------------------------------- |
| 9200001 | the application is not an administrator of the device.                              |
| 9200002 | the administrator application does not have permission to manage the device.                                          |

**Example:**

```js
let wantTemp = {
    bundleName: "com.example.myapplication",
    abilityName: "EntryAbility",
};
let appIds = ["com.example.myapplication"];

bundleManager.addDisallowedInstallBundles(wantTemp, appIds, 100, (error) => {
    if (error != null) {
        console.log("error code:" + error.code + " error message:" + error.message);
    }
});
```

## bundleManager.addDisallowedInstallBundles

addDisallowedInstallBundles(admin: Want, appIds: Array\<string>, userId?: number): Promise&lt;void&gt;;

Adds a list of bundles that are not allowed to be installed by the current administrator (if **userId** is not passed in) or the given user (if **userId** is passed in) for an enterprise device administrator application. This API uses a promise to return the result.

**Required permissions**: ohos.permission.ENTERPRISE_SET_BUNDLE_INSTALL_POLICY

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**System API**: This is a system API.

**Parameters**

| Name  | Type                                 | Mandatory  | Description     |
| ----- | ----------------------------------- | ---- | ------- |
| admin    | [Want](js-apis-app-ability-want.md)     | Yes   | Target enterprise device administrator application.                 |
| appIds    | Array&lt;string&gt;                | Yes   | Bundles to be added to the disallowed bundle list.                 |
| userId     | number                             | No   | User ID. The default value is the user ID of the caller. The value must be greater than or equal to 0.|

**Return value**

| Type                  | Description                     |
| --------------------- | ------------------------- |
| Promise&lt;void&gt; | Promise that returns no value. If the operation fails, an error object is thrown. |

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](../errorcodes/errorcode-enterpriseDeviceManager.md).

| ID| Error Message                                                                    |          
| ------- | ---------------------------------------------------------------------------- |
| 9200001 | the application is not an administrator of the device.                              |
| 9200002 | the administrator application does not have permission to manage the device.                                          |

**Example:**

```js
let wantTemp = {
    bundleName: "com.example.myapplication",
    abilityName: "EntryAbility",
};
let appIds = ["com.example.myapplication"];

bundleManager.addDisallowedInstallBundles(wantTemp, appIds, 100).then(() => {
    console.log("success");
}).catch(error => {
    console.log("error code:" + error.code + " error message:" + error.message);
});
```

## bundleManager.removeDisallowedInstallBundles

removeDisallowedInstallBundles(admin: Want, appIds: Array\<string>, callback: AsyncCallback&lt;void&gt;): void;

Removes a list of bundles that are not allowed to be installed by the current administrator for an enterprise device administrator application. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.ENTERPRISE_SET_BUNDLE_INSTALL_POLICY

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**System API**: This is a system API.

**Parameters**

| Name     | Type                                      | Mandatory  | Description                      |
| -------- | ---------------------------------------- | ---- | ------------------------------- |
| admin    | [Want](js-apis-app-ability-want.md)     | Yes   | Target enterprise device administrator application.                 |
| appIds    | Array&lt;string&gt;                | Yes   | Bundles to be removed from the disallowed bundle list.                 |
| callback | AsyncCallback&lt;void&gt;            | Yes   | Callback used to return the result. If the operation is successful, **err** is **null**. Otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](../errorcodes/errorcode-enterpriseDeviceManager.md).

| ID| Error Message                                                                      |          
| ------- | ---------------------------------------------------------------------------- |
| 9200001 | the application is not an administrator of the device.                              |
| 9200002 | the administrator application does not have permission to manage the device.                                          |

**Example:**

```js
let wantTemp = {
    bundleName: "com.example.myapplication",
    abilityName: "EntryAbility",
};
let appIds = ["com.example.myapplication"];

bundleManager.removeDisallowedInstallBundles(wantTemp, appIds, (error) => {
    if (error != null) {
        console.log("error code:" + error.code + " error message:" + error.message);
    }
});
```

## bundleManager.removeDisallowedInstallBundles

removeAllowedInstallBundles(admin: Want, appIds: Array\<string>, userId: number, callback: AsyncCallback&lt;void&gt;): void;

Removes a list of bundles that are not allowed to be installed by the given user (specified by **userId**) for an enterprise device administrator application. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.ENTERPRISE_SET_BUNDLE_INSTALL_POLICY

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**System API**: This is a system API.

**Parameters**

| Name  | Type                                 | Mandatory  | Description     |
| ----- | ----------------------------------- | ---- | ------- |
| admin    | [Want](js-apis-app-ability-want.md)     | Yes   | Target enterprise device administrator application.                 |
| appIds    | Array&lt;string&gt;                | Yes   | Bundles to be removed from the disallowed bundle list.                 |
| userId     | number                             | Yes   | User ID. The default value is the user ID of the caller. The value must be greater than or equal to 0.|
| callback | AsyncCallback&lt;void&gt;            | Yes   | Callback used to return the result. If the operation is successful, **err** is **null**. Otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](../errorcodes/errorcode-enterpriseDeviceManager.md).

| ID| Error Message                                                                    |          
| ------- | ---------------------------------------------------------------------------- |
| 9200001 | the application is not an administrator of the device.                              |
| 9200002 | the administrator application does not have permission to manage the device.                                          |

**Example:**

```js
let wantTemp = {
    bundleName: "com.example.myapplication",
    abilityName: "EntryAbility",
};
let appIds = ["com.example.myapplication"];

bundleManager.removeDisallowedInstallBundles(wantTemp, appIds, 100, (error) => {
    if (error != null) {
        console.log("error code:" + error.code + " error message:" + error.message);
    }
});
```

## bundleManager.removeDisallowedInstallBundles

removeDisallowedInstallBundles(admin: Want, appIds: Array\<string>, userId?: number): Promise&lt;void&gt;;

Removes a list of bundles that are not allowed to be installed by the current administrator (if **userId** is not passed in) or the given user (if **userId** is passed in) for an enterprise device administrator application. This API uses a promise to return the result.

**Required permissions**: ohos.permission.ENTERPRISE_SET_BUNDLE_INSTALL_POLICY

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**System API**: This is a system API.

**Parameters**

| Name  | Type                                 | Mandatory  | Description     |
| ----- | ----------------------------------- | ---- | ------- |
| admin    | [Want](js-apis-app-ability-want.md)     | Yes   | Target enterprise device administrator application.                 |
| appIds    | Array\&lt;string&gt;                | Yes   | Bundles to be removed from the disallowed bundle list.                 |
| userId     | number                             | No   | User ID. The default value is the user ID of the caller. The value must be greater than or equal to 0.|

**Return value**

| Type                  | Description                     |
| --------------------- | ------------------------- |
| Promise&lt;void&gt; | Promise that returns no value. If the operation fails, an error object is thrown. |

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](../errorcodes/errorcode-enterpriseDeviceManager.md).

| ID| Error Message                                                                    |          
| ------- | ---------------------------------------------------------------------------- |
| 9200001 | the application is not an administrator of the device.                              |
| 9200002 | the administrator application does not have permission to manage the device.                                          |

**Example:**

```js
let wantTemp = {
    bundleName: "com.example.myapplication",
    abilityName: "EntryAbility",
};
let appIds = ["com.example.myapplication"];

bundleManager.removeDisallowedInstallBundles(wantTemp, appIds, 100).then(() => {
    console.log("success");
}).catch(error => {
    console.log("error code:" + error.code + " error message:" + error.message);
});
```

## bundleManager.getDisallowedInstallBundles

getDisallowedInstallBundles(admin: Want, callback: AsyncCallback&lt;Array&lt;string&gt;&gt;): void;

Obtains the list of bundles that are not allowed to be installed by the current administrator for an enterprise device administrator application. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.ENTERPRISE_SET_BUNDLE_INSTALL_POLICY

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**System API**: This is a system API.

**Parameters**

| Name     | Type                                      | Mandatory  | Description                      |
| -------- | ---------------------------------------- | ---- | ------------------------------- |
| admin    | [Want](js-apis-app-ability-want.md)     | Yes   | Target enterprise device administrator application.                 |
| callback | AsyncCallback&lt;Array&lt;string&gt;&gt;       | Yes   | Callback used to return the result. If the operation is successful, **err** is **null**. Otherwise, **err** is an error object.      |

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](../errorcodes/errorcode-enterpriseDeviceManager.md).

| ID| Error Message                                                                      |          
| ------- | ---------------------------------------------------------------------------- |
| 9200001 | the application is not an administrator of the device.                              |
| 9200002 | the administrator application does not have permission to manage the device.                                          |

**Example:**

```js
let wantTemp = {
    bundleName: "com.example.myapplication",
    abilityName: "EntryAbility",
};

bundleManager.getDisallowedInstallBundles(wantTemp, (error) => {
    if (error != null) {
        console.log("error code:" + error.code + " error message:" + error.message);
    }
});
```

## bundleManager.getDisallowedInstallBundles

getDisallowedInstallBundles(admin: Want, userId: number, callback: AsyncCallback&lt;Array&lt;string&gt;&gt;): void;

Obtains the list of bundles that are not allowed to be installed by the given user (specified by **userId**) for an enterprise device administrator application. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.ENTERPRISE_SET_BUNDLE_INSTALL_POLICY

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**System API**: This is a system API.

**Parameters**

| Name     | Type                                      | Mandatory  | Description                      |
| -------- | ---------------------------------------- | ---- | ------------------------------- |
| admin    | [Want](js-apis-app-ability-want.md)     | Yes   | Target enterprise device administrator application.                 |
| userId     | number                             | Yes   | User ID. The default value is the user ID of the caller. The value must be greater than or equal to 0.|
| callback | AsyncCallback&lt;Array&lt;string&gt;&gt;       | Yes   | Callback used to return the result. If the operation is successful, **err** is **null**. Otherwise, **err** is an error object.      |

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](../errorcodes/errorcode-enterpriseDeviceManager.md).

| ID| Error Message                                                                      |          
| ------- | ---------------------------------------------------------------------------- |
| 9200001 | the application is not an administrator of the device.                              |
| 9200002 | the administrator application does not have permission to manage the device.                                          |

**Example:**

```js
let wantTemp = {
    bundleName: "com.example.myapplication",
    abilityName: "EntryAbility",
};

bundleManager.getDisallowedInstallBundles(wantTemp, 100, (error) => {
    if (error != null) {
        console.log("error code:" + error.code + " error message:" + error.message);
    }
});
```

## bundleManager.getDisallowedInstallBundles

getDisallowedInstallBundles(admin: Want, userId?: number): Promise&lt;Array&lt;string&gt;&gt;;

Obtains the list of bundles that are not allowed to be installed by the current administrator (if **userId** is not passed in) or the given user (if **userId** is passed in) for an enterprise device administrator application. This API uses a promise to return the result.

**Required permissions**: ohos.permission.ENTERPRISE_SET_BUNDLE_INSTALL_POLICY

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**System API**: This is a system API.

**Parameters**

| Name  | Type                                 | Mandatory  | Description     |
| ----- | ----------------------------------- | ---- | ------- |
| admin | [Want](js-apis-app-ability-want.md) | Yes   | Target enterprise device administrator application.|
| userId     | number                             | No   | User ID. The default value is the user ID of the caller. The value must be greater than or equal to 0.|

**Return value**

| Type                  | Description                     |
| --------------------- | ------------------------- |
| Promise&lt;Array&lt;string&gt;&gt; | Promise used to return the allowed bundle list.|

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](../errorcodes/errorcode-enterpriseDeviceManager.md).

| ID| Error Message                                                                    |          
| ------- | ---------------------------------------------------------------------------- |
| 9200001 | the application is not an administrator of the device.                              |
| 9200002 | the administrator application does not have permission to manage the device.                                          |

**Example:**

```js
let wantTemp = {
    bundleName: "com.example.myapplication",
    abilityName: "EntryAbility",
};
bundleManager.getDisallowedInstallBundles(wantTemp, 100).then(() => {
    console.log("success");
}).catch(error => {
    console.log("error code:" + error.code + " error message:" + error.message);
});
