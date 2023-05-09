# @ohos.enterprise.accountManager (Account Management)

The **accountManager** module provides APIs for account management of enterprise devices. Only the device administrator applications can call the APIs provided by this module.

> **NOTE**
>
> The initial APIs of this module are supported since API version 10. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```js
import accountManager from '@ohos.enterprise.accountManager';
```

## accountManager.disallowAddLocalAccount

disallowAddLocalAccount(admin: Want, disallow: boolean, callback: AsyncCallback&lt;void&gt;): void

Forbids a device administrator application to create local user accounts. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.ENTERPRISE_SET_ACCOUNT_POLICY

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**System API**: This is a system API.

**Parameters**

| Name     | Type                                      | Mandatory  | Description                      |
| -------- | ---------------------------------------- | ---- | ------------------------------- |
| admin    | [Want](js-apis-app-ability-want.md)     | Yes   | Enterprise device administrator application.                 |
| disallow    | boolean     | Yes   | Whether to forbid the creation of local user accounts. The value **true** means that local user accounts cannot be created; the value **false** means the opposite.                 |
| callback | AsyncCallback&lt;void&gt;            | Yes   | Callback invoked to return the result. If the operation is successful, **err** is **null**. Otherwise, **err** is an error object.      |

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
accountManager.disallowAddLocalAccount(admin, true, (error) => {
    if (error != null) {
        console.log("error code:" + error.code + " error message:" + error.message);
    }
});
```

## accountManager.disallowAddLocalAccount

disallowAddLocalAccount(admin: Want, disallow: boolean): Promise&lt;void&gt;

Forbids a device administrator application to create local user accounts. This API uses a promise to return the result.

**Required permissions**: ohos.permission.ENTERPRISE_SET_ACCOUNT_POLICY

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**System API**: This is a system API.

**Parameters**

| Name  | Type                                 | Mandatory  | Description     |
| ----- | ----------------------------------- | ---- | ------- |
| admin | [Want](js-apis-app-ability-want.md) | Yes   | Enterprise device administrator application.|
| disallow    | boolean     | Yes   | Whether to forbid the creation of local user accounts. The value **true** means that local user accounts cannot be created; the value **false** means the opposite.                 |

**Return value**

| Type                  | Description                     |
| --------------------- | ------------------------- |
| Promise&lt;void&gt; | Promise that returns no value. An error object will be thrown if the operation fails.|

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
accountManager.disallowAddLocalAccount(wantTemp, true).then(() => {
    console.log("success");
}).catch(error => {
    console.log("error code:" + error.code + " error message:" + error.message);
});
```
