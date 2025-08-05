# @ohos.bundle.bundleMonitor (bundleMonitor) (System API)

The module provides APIs for listens for bundle installation, uninstall, and updates.

> **NOTE**
>
> The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
> The APIs provided by this module are system APIs.

## Modules to Import

```ts
import bundleMonitor from '@ohos.bundle.bundleMonitor';
```

## BundleChangedInfo

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

**System API**: This is a system API.

| Name      | Type  | Read-Only| Optional| Description                      |
| ---------- | ------ | ---- | ---- | -------------------------- |
| bundleName | string | Yes  | No  | Name of the bundle whose status changes.|
| userId     | number | Yes  | No  | ID of the user for whom the bundle status changes. You can obtain the ID by calling [getOsAccountLocalId](../apis-basic-services-kit/js-apis-osAccount.md#getosaccountlocalid9).  |
| appIndex<sup>12+</sup>   | number | Yes  | No  |  Index of the application clone whose status changes. |

## BundleChangedEvent

Enumerates the types of events to listen for.

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

**System API**: This is a system API.

| Name      | Description            |
| ---------- | --------------- |
| add        | Bundle addition events.  |
| update     | Bundle update events.  |
| remove     | Bundle removal events.  |

## bundleMonitor.on

on(type: BundleChangedEvent, callback: Callback\<BundleChangedInfo>): void

Subscribes to bundle installation, uninstall, and update events.
>**NOTE**
>
>This API must be used together with [bundleMonitor.off](#bundlemonitoroff). When the lifecycle of a component, page, or application ends, use [bundleMonitor.off](#bundlemonitoroff) to unsubscribe from the bundle installation, uninstall, and update events.

**Required permissions**: ohos.permission.LISTEN_BUNDLE_CHANGE

**System API**: This is a system API.

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

**Parameters**

| Name                      | Type    | Mandatory| Description              |
| ---------------------------- | -------- | ---- | ------------------ |
| type| [BundleChangedEvent](js-apis-bundleMonitor-sys.md#bundlechangedevent)| Yes  | Type of the event to subscribe to.|
| callback | callback\<BundleChangedInfo>| Yes  | [Callback function](../apis-basic-services-kit/js-apis-base.md#asynccallback) used for the subscription.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                           |
| -------- | --------------------------------------|
| 201 | Verify permission denied. |
| 202 | Permission denied, non-system app called system api. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|

**Example**

```ts
import bundleMonitor from '@ohos.bundle.bundleMonitor';
import { BusinessError } from '@ohos.base';

try {
    bundleMonitor.on('add', (bundleChangeInfo) => {
        console.info(`bundleName : ${bundleChangeInfo.bundleName} userId : ${bundleChangeInfo.userId}`);
	})
} catch (errData) {
    let message = (errData as BusinessError).message;
    let errCode = (errData as BusinessError).code;
    console.error(`errData is errCode:${errCode}  message:${message}`);
}
```

## bundleMonitor.off

off(type: BundleChangedEvent, callback?: Callback\<BundleChangedInfo>): void

Unsubscribes from bundle installation, uninstall, and update events.

**Required permissions**: ohos.permission.LISTEN_BUNDLE_CHANGE

**System API**: This is a system API.

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

**Parameters**

| Name                      | Type    | Mandatory| Description                                                      |
| ---------------------------- | -------- | ---- | ---------------------------------------------------------- |
| type| [BundleChangedEvent](js-apis-bundleMonitor-sys.md#bundlechangedevent)| Yes  | Type of the event to unsubscribe from.                                        |
| callback | callback\<BundleChangedInfo>| No  | [Callback function](../apis-basic-services-kit/js-apis-base.md#asynccallback) used for the unsubscription. The default value is all callbacks of the current event.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                           |
| -------- | --------------------------------------|
| 201 | Verify permission denied. |
| 202 | Permission denied, non-system app called system api. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types.|

**Example**

```ts
import bundleMonitor from '@ohos.bundle.bundleMonitor';
import { BusinessError } from '@ohos.base';

try {
    bundleMonitor.off('add');
} catch (errData) {
    let message = (errData as BusinessError).message;
    let errCode = (errData as BusinessError).code;
    console.error(`errData is errCode:${errCode}  message:${message}`);
}
```
