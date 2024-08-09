# @ohos.enterprise.adminManager (Enterprise Device Management)

The **adminManager** module provides enterprise device management capabilities so that devices have the custom capabilities required in enterprise settings.

> **NOTE**
>
> - The initial APIs of this module are supported since API version 12. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
> - The APIs of this module are available only to [device administrator applications](../../mdm/mdm-kit-guide.md#introduction).

## Modules to Import

```ts
import { adminManager } from '@kit.MDMKit';
```

## adminManager.disableAdmin

disableAdmin(admin: Want, userId?: number): Promise\<void>

Disables a common administrator application for the current or specified user. This API uses a promise to return the result.

**Required permissions**: ohos.permission.MANAGE_ENTERPRISE_DEVICE_ADMIN

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager



**Model restriction**: This API can be used only in the stage model.

**Parameters**

| Name| Type                                                   | Mandatory| Description                                                        |
| ------ | ------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| admin  | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | Yes  | Common administrator application to disable.                                          |
| userId | number                                                  | No  | User ID, which must be greater than or equal to 0.<br>- If **userId** is passed in, this API applies to the specified user.<br>- If **userId** is not passed in, this API applies to the current user.|

**Return value**

| Type          | Description                                                        |
| -------------- | ------------------------------------------------------------ |
| Promise\<void> | Promise that returns no value. If the operation fails, an error object will be thrown.|

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](errorcode-enterpriseDeviceManager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 9200005  | Failed to deactivate the administrator application of the device. |
| 201      | Permission verification failed. The application does not have the permission required to call the API. |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**

```ts
import { Want } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
let wantTemp: Want = {
  bundleName: 'bundleName',
  abilityName: 'abilityName',
};

adminManager.disableAdmin(wantTemp, 100).catch((err: BusinessError) => {
  console.error(`Failed to disable admin. Code: ${err.code}, message: ${err.message}`);
});
```

## adminManager.subscribeManagedEventSync

subscribeManagedEventSync(admin: Want, managedEvents: Array\<ManagedEvent>): void

Subscribes to system management events of a device administrator application.

**Required permissions**: ohos.permission.ENTERPRISE_SUBSCRIBE_MANAGED_EVENT

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager



**Model restriction**: This API can be used only in the stage model.

**Parameters**

| Name       | Type                                                   | Mandatory| Description          |
| ------------- | ------------------------------------------------------- | ---- | -------------- |
| admin         | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | Yes  | Device administrator application.|
| managedEvents | Array\<[ManagedEvent](#managedevent)>                   | Yes  | Array of events to subscribe to.|

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](errorcode-enterpriseDeviceManager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 9200001  | The application is not an administrator application of the device. |
| 9200008  | The specified system event is invalid.                       |
| 201      | Permission verification failed. The application does not have the permission required to call the API. |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**

```ts
import { Want } from '@kit.AbilityKit';
let wantTemp: Want = {
  bundleName: 'bundleName',
  abilityName: 'abilityName',
};
let events: Array<adminManager.ManagedEvent> = [adminManager.ManagedEvent.MANAGED_EVENT_BUNDLE_ADDED, adminManager.ManagedEvent.MANAGED_EVENT_BUNDLE_REMOVED];

try {
  adminManager.subscribeManagedEventSync(wantTemp, events);
  console.info('Succeeded in subscribe managed event.');
} catch (err) {
  console.error(`Failed to subscribe managed event. Code: ${err.code}, message: ${err.message}`);
}
```

## adminManager.unsubscribeManagedEventSync

unsubscribeManagedEventSync(admin: Want, managedEvents: Array\<ManagedEvent>): void

Unsubscribes from system management events of a device administrator application.

**Required permissions**: ohos.permission.ENTERPRISE_SUBSCRIBE_MANAGED_EVENT

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager



**Model restriction**: This API can be used only in the stage model.

**Parameters**

| Name       | Type                                                   | Mandatory| Description              |
| ------------- | ------------------------------------------------------- | ---- | ------------------ |
| admin         | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | Yes  | Device administrator application.    |
| managedEvents | Array\<[ManagedEvent](#managedevent)>                   | Yes  | Array of events to unsubscribe from.|

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](errorcode-enterpriseDeviceManager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 9200001  | The application is not an administrator application of the device. |
| 9200008  | The specified system event is invalid.                       |
| 201      | Permission verification failed. The application does not have the permission required to call the API. |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**

```ts
import { Want } from '@kit.AbilityKit';
let wantTemp: Want = {
  bundleName: 'bundleName',
  abilityName: 'abilityName',
};
let events: Array<adminManager.ManagedEvent> = [adminManager.ManagedEvent.MANAGED_EVENT_BUNDLE_ADDED, adminManager.ManagedEvent.MANAGED_EVENT_BUNDLE_REMOVED];

try {
  adminManager.unsubscribeManagedEventSync(wantTemp, events);
  console.info('Succeeded in subscribe managed event.');
} catch (err) {
  console.error(`Failed to subscribe managed event. Code: ${err.code}, message: ${err.message}`);
}
```

## ManagedEvent

Enumerates the system management events that can be subscribed to.

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager



| Name                        | Value  | Description          |
| ---------------------------- | ---- | -------------- |
| MANAGED_EVENT_BUNDLE_ADDED   | 0    | An application is installed.|
| MANAGED_EVENT_BUNDLE_REMOVED | 1    | An application is uninstalled.|
| MANAGED_EVENT_APP_START      | 2    | An application is started.|
| MANAGED_EVENT_APP_STOP       | 3    | An application is stopped.|
| MANAGED_EVENT_SYSTEM_UPDATE  | 4    | The system is updated. |
