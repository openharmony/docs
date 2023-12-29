# @ohos.enterprise.applicationManager (Application Management)

The **applicationManager** module provides application management capabilities, including adding, removing, and obtaining the applications that are forbidden to run.

> **NOTE**
>
> - The initial APIs of this module are supported since API version 10. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
> - The APIs of this module can be used only in the stage model.
>
> - The APIs provided by this module can be called only by a [device administrator application](enterpriseDeviceManagement-overview.md#basic-concepts) that is [enabled](js-apis-enterprise-adminManager.md#adminmanagerenableadmin).

## Modules to Import

```ts
import applicationManager from '@ohos.enterprise.applicationManager';
```

## applicationManager.addDisallowedRunningBundles

addDisallowedRunningBundles(admin: Want, appIds: Array\<string>, callback: AsyncCallback&lt;void&gt;): void

Adds the applications that are not allowed to run by the current user through the specified device administrator application. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.ENTERPRISE_MANAGE_SET_APP_RUNNING_POLICY

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**System API**: This is a system API.

**Parameters**

| Name     | Type                                      | Mandatory  | Description                      |
| -------- | ---------------------------------------- | ---- | ------------------------------- |
| admin    | [Want](js-apis-app-ability-want.md)     | Yes   | Device administrator application.                 |
| appIds    | Array&lt;string&gt;                | Yes   | IDs of the applications to add.                 |
| callback | AsyncCallback&lt;void&gt;            | Yes   | Callback invoked to return the result. If the operation is successful, **err** is **null**. Otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](../errorcodes/errorcode-enterpriseDeviceManager.md).

| ID| Error Message                                                                      |
| ------- | ---------------------------------------------------------------------------- |
| 9200001 | the application is not an administrator of the device.                        |
| 9200002 | the administrator application does not have permission to manage the device. |


**Example**

```ts
import Want from '@ohos.app.ability.Want';
let wantTemp: Want = {
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility',
};
let appIds: Array<string> = ['com.example.myapplication'];

applicationManager.addDisallowedRunningBundles(wantTemp, appIds, (err) => {
  if (err) {
    console.error(`Failed to add disallowed running bundles. Code is ${err.code}, message is ${err.message}`);
    return;
  }
  console.info('Succeeded in adding disallowed running bundles');
});
```

## applicationManager.addDisallowedRunningBundles

addDisallowedRunningBundles(admin: Want, appIds: Array\<string>, userId: number, callback: AsyncCallback&lt;void&gt;): void

Adds the applications that are not allowed to run by the specified user through the specified device administrator application. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.ENTERPRISE_MANAGE_SET_APP_RUNNING_POLICY

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**System API**: This is a system API.

**Parameters**

| Name  | Type                                 | Mandatory  | Description     |
| ----- | ----------------------------------- | ---- | ------- |
| admin    | [Want](js-apis-app-ability-want.md)     | Yes   | Device administrator application.                 |
| appIds    | Array&lt;string&gt;                | Yes   | IDs of the applications to add.                 |
| userId     | number                             | Yes   | User ID, which must be greater than or equal to 0.|
| callback | AsyncCallback&lt;void&gt;            | Yes   | Callback invoked to return the result. If the operation is successful, **err** is **null**. Otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](../errorcodes/errorcode-enterpriseDeviceManager.md).

| ID| Error Message                                                                    |
| ------- | ---------------------------------------------------------------------------- |
| 9200001 | the application is not an administrator of the device.                        |
| 9200002 | the administrator application does not have permission to manage the device. |

**Example**

```ts
import Want from '@ohos.app.ability.Want';
let wantTemp: Want = {
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility',
};
let appIds: Array<string> = ['com.example.myapplication'];

applicationManager.addDisallowedRunningBundles(wantTemp, appIds, 100, (err) => {
  if (err) {
    console.error(`Failed to add disallowed running bundles. Code is ${err.code}, message is ${err.message}`);
    return;
  }
  console.info('Succeeded in adding disallowed running bundles');
});
```

## applicationManager.addDisallowedRunningBundles

addDisallowedRunningBundles(admin: Want, appIds: Array\<string>, userId?: number): Promise&lt;void&gt;

Adds the applications that are not allowed to run by the current or specified user through the specified device administrator application. This API uses a promise to return the result.

**Required permissions**: ohos.permission.ENTERPRISE_MANAGE_SET_APP_RUNNING_POLICY

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**System API**: This is a system API.

**Parameters**

| Name  | Type                                 | Mandatory  | Description     |
| ----- | ----------------------------------- | ---- | ------- |
| admin    | [Want](js-apis-app-ability-want.md)     | Yes   | Device administrator application.                 |
| appIds    | Array&lt;string&gt;                | Yes   | IDs of the applications to add.                 |
| userId     | number                             | No   | User ID, which must be greater than or equal to 0.<br>- If **userId** is passed in, the applications cannot be run by the specified user.<br>- If **userId** is not passed in, the applications cannot be run by the current user.|

**Return value**

| Type                  | Description                     |
| --------------------- | ------------------------- |
| Promise&lt;void&gt; | Promise that returns no value. If the operation fails, an error object will be thrown. |

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](../errorcodes/errorcode-enterpriseDeviceManager.md).

| ID| Error Message                                                                    |
| ------- | ---------------------------------------------------------------------------- |
| 9200001 | the application is not an administrator of the device.                        |
| 9200002 | the administrator application does not have permission to manage the device. |

**Example**

```ts
import Want from '@ohos.app.ability.Want';
import { BusinessError } from '@ohos.base';
let wantTemp: Want = {
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility',
};
let appIds: Array<string> = ['com.example.myapplication'];

applicationManager.addDisallowedRunningBundles(wantTemp, appIds, 100).then(() => {
  console.info('Succeeded in adding disallowed running bundles');
}).catch((err: BusinessError) => {
  console.error(`Failed to add disallowed running bundles. Code is ${err.code}, message is ${err.message}`);
});
```

## applicationManager.removeDisallowedRunningBundles

removeDisallowedRunningBundles(admin: Want, appIds: Array\<string>, callback: AsyncCallback&lt;void&gt;): void

Removes the applications that are not allowed to run by the current user through the specified device administrator application. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.ENTERPRISE_MANAGE_SET_APP_RUNNING_POLICY

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**System API**: This is a system API.

**Parameters**

| Name     | Type                                      | Mandatory  | Description                      |
| -------- | ---------------------------------------- | ---- | ------------------------------- |
| admin    | [Want](js-apis-app-ability-want.md)     | Yes   | Device administrator application.                 |
| appIds    | Array&lt;string&gt;                | Yes   | IDs of the applications to remove.                 |
| callback | AsyncCallback&lt;void&gt;            | Yes   | Callback invoked to return the result. If the operation is successful, **err** is **null**. Otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](../errorcodes/errorcode-enterpriseDeviceManager.md).

| ID| Error Message                                                                      |
| ------- | ---------------------------------------------------------------------------- |
| 9200001 | the application is not an administrator of the device.                        |
| 9200002 | the administrator application does not have permission to manage the device. |

**Example**

```ts
import Want from '@ohos.app.ability.Want';
let wantTemp: Want = {
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility',
};
let appIds: Array<string> = ['com.example.myapplication'];

applicationManager.removeDisallowedRunningBundles(wantTemp, appIds, (err) => {
  if (err) {
    console.error(`Failed to remove disallowed running bundles. Code is ${err.code}, message is ${err.message}`);
    return;
  }
  console.info('Succeeded in removing disallowed running bundles');
});
```

## applicationManager.removeDisallowedRunningBundles

removeDisallowedRunningBundles(admin: Want, appIds: Array\<string>, userId: number, callback: AsyncCallback&lt;void&gt;): void

Removes the applications that are not allowed to run by the specified user through the specified device administrator application. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.ENTERPRISE_MANAGE_SET_APP_RUNNING_POLICY

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**System API**: This is a system API.

**Parameters**

| Name  | Type                                 | Mandatory  | Description     |
| ----- | ----------------------------------- | ---- | ------- |
| admin    | [Want](js-apis-app-ability-want.md)     | Yes   | Device administrator application.                 |
| appIds    | Array&lt;string&gt;                | Yes   | IDs of the applications to remove.                 |
| userId     | number                             | Yes   | User ID, which must be greater than or equal to 0.|
| callback | AsyncCallback&lt;void&gt;            | Yes   | Callback invoked to return the result. If the operation is successful, **err** is **null**. Otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](../errorcodes/errorcode-enterpriseDeviceManager.md).

| ID| Error Message                                                                    |
| ------- | ---------------------------------------------------------------------------- |
| 9200001 | the application is not an administrator of the device.                        |
| 9200002 | the administrator application does not have permission to manage the device. |

**Example**

```ts
import Want from '@ohos.app.ability.Want';
let wantTemp: Want = {
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility',
};
let appIds: Array<string> = ['com.example.myapplication'];

applicationManager.removeDisallowedRunningBundles(wantTemp, appIds, 100, (err) => {
  if (err) {
    console.error(`Failed to remove disallowed running bundles. Code is ${err.code}, message is ${err.message}`);
    return;
  }
  console.info('Succeeded in removing disallowed running bundles');
});
```

## applicationManager.removeDisallowedRunningBundles

removeDisallowedRunningBundles(admin: Want, appIds: Array\<string>, userId?: number): Promise&lt;void&gt;

Removes the applications that are not allowed to run by the current or specified user through the specified device administrator application. This API uses a promise to return the result.

**Required permissions**: ohos.permission.ENTERPRISE_MANAGE_SET_APP_RUNNING_POLICY

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**System API**: This is a system API.

**Parameters**

| Name  | Type                                 | Mandatory  | Description     |
| ----- | ----------------------------------- | ---- | ------- |
| admin    | [Want](js-apis-app-ability-want.md)     | Yes   | Device administrator application.                 |
| appIds    | Array&lt;string&gt;                | Yes   | IDs of the applications to remove.                 |
| userId     | number                             | No   | User ID, which must be greater than or equal to 0.<br>- If **userId** is passed in, the applications cannot be run by the specified user.<br>- If **userId** is not passed in, the applications cannot be run by the current user.|

**Return value**

| Type                  | Description                     |
| --------------------- | ------------------------- |
| Promise&lt;void&gt; | Promise that returns no value. If the operation fails, an error object will be thrown. |

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](../errorcodes/errorcode-enterpriseDeviceManager.md).

| ID| Error Message                                                                    |
| ------- | ---------------------------------------------------------------------------- |
| 9200001 | the application is not an administrator of the device.                        |
| 9200002 | the administrator application does not have permission to manage the device. |

**Example**

```ts
import Want from '@ohos.app.ability.Want';
import { BusinessError } from '@ohos.base';
let wantTemp: Want = {
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility',
};
let appIds: Array<string> = ['com.example.myapplication'];

applicationManager.removeDisallowedRunningBundles(wantTemp, appIds, 100).then(() => {
  console.info('Succeeded in removing disallowed running bundles');
}).catch((err: BusinessError) => {
  console.error(`Failed to remove disallowed running bundles. Code is ${err.code}, message is ${err.message}`);
});
```

## applicationManager.getDisallowedRunningBundles

getDisallowedRunningBundles(admin: Want, callback: AsyncCallback&lt;Array&lt;string&gt;&gt;): void

Obtains the applications that are not allowed to run by the current user through the specified device administrator application. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.ENTERPRISE_MANAGE_SET_APP_RUNNING_POLICY

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**System API**: This is a system API.

**Parameters**

| Name     | Type                                      | Mandatory  | Description                      |
| -------- | ---------------------------------------- | ---- | ------------------------------- |
| admin    | [Want](js-apis-app-ability-want.md)     | Yes   | Device administrator application.                 |
| callback | AsyncCallback&lt;Array&lt;string&gt;&gt;       | Yes   | Callback invoked to return the result. If the operation is successful, **err** is **null**. Otherwise, **err** is an error object.      |

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](../errorcodes/errorcode-enterpriseDeviceManager.md).

| ID| Error Message                                                                      |
| ------- | ---------------------------------------------------------------------------- |
| 9200001 | the application is not an administrator of the device.                        |
| 9200002 | the administrator application does not have permission to manage the device. |

**Example**

```ts
import Want from '@ohos.app.ability.Want';
let wantTemp: Want = {
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility',
};

applicationManager.getDisallowedRunningBundles(wantTemp, (err, result) => {
  if (err) {
    console.error(`Failed to get disallowed running bundles. Code is ${err.code}, message is ${err.message}`);
    return;
  }
  console.info(`Succeeded in getting disallowed running bundles, result : ${JSON.stringify(result)}`);
});
```

## applicationManager.getDisallowedRunningBundles

getDisallowedRunningBundles(admin: Want, userId: number, callback: AsyncCallback&lt;Array&lt;string&gt;&gt;): void

Obtains the applications that are not allowed to run by the specified user through the specified device administrator application. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.ENTERPRISE_MANAGE_SET_APP_RUNNING_POLICY

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**System API**: This is a system API.

**Parameters**

| Name     | Type                                      | Mandatory  | Description                      |
| -------- | ---------------------------------------- | ---- | ------------------------------- |
| admin    | [Want](js-apis-app-ability-want.md)     | Yes   | Device administrator application.                 |
| userId     | number                             | Yes   | User ID, which must be greater than or equal to 0.|
| callback | AsyncCallback&lt;Array&lt;string&gt;&gt;       | Yes   | Callback invoked to return the result. If the operation is successful, **err** is **null**. Otherwise, **err** is an error object.      |

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](../errorcodes/errorcode-enterpriseDeviceManager.md).

| ID| Error Message                                                                      |
| ------- | ---------------------------------------------------------------------------- |
| 9200001 | the application is not an administrator of the device.                        |
| 9200002 | the administrator application does not have permission to manage the device. |

**Example**

```ts
import Want from '@ohos.app.ability.Want';
let wantTemp: Want = {
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility',
};

applicationManager.getDisallowedRunningBundles(wantTemp, 100, (err, result) => {
  if (err) {
    console.error(`Failed to get disallowed running bundles. Code is ${err.code}, message is ${err.message}`);
    return;
  }
  console.info(`Succeeded in getting disallowed running bundles, result : ${JSON.stringify(result)}`);
});
```

## applicationManager.getDisallowedRunningBundles

getDisallowedRunningBundles(admin: Want, userId?: number): Promise&lt;Array&lt;string&gt;&gt;

Obtains the applications that are not allowed to run by the current or specified user through the specified device administrator application. This API uses a promise to return the result.

**Required permissions**: ohos.permission.ENTERPRISE_MANAGE_SET_APP_RUNNING_POLICY

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**System API**: This is a system API.

**Parameters**

| Name  | Type                                 | Mandatory  | Description     |
| ----- | ----------------------------------- | ---- | ------- |
| admin | [Want](js-apis-app-ability-want.md) | Yes   | Device administrator application.|
| userId     | number                             | No   | User ID, which must be greater than or equal to 0.<br>- If **userId** is passed in, the applications cannot be run by the specified user.<br>- If **userId** is not passed in, the applications cannot be run by the current user.|

**Return value**

| Type                  | Description                     |
| --------------------- | ------------------------- |
| Promise&lt;Array&lt;string&gt;&gt; | Promise used to return the application blocklist of the current user.|

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](../errorcodes/errorcode-enterpriseDeviceManager.md).

| ID| Error Message                                                                    |
| ------- | ---------------------------------------------------------------------------- |
| 9200001 | the application is not an administrator of the device.                        |
| 9200002 | the administrator application does not have permission to manage the device. |

**Example**

```ts
import Want from '@ohos.app.ability.Want';
import { BusinessError } from '@ohos.base';
let wantTemp: Want = {
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility',
};

applicationManager.getDisallowedRunningBundles(wantTemp, 100).then((result) => {
  console.info(`Succeeded in getting disallowed running bundles, result : ${JSON.stringify(result)}`);
}).catch((err: BusinessError) => {
  console.error(`Failed to get disallowed running bundles. Code is ${err.code}, message is ${err.message}`);
});
```
