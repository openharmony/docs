# Bundle.bundleMonitor

The **Bundle.bundleMonitor** module provides APIs for listens for bundle installation, uninstall, and updates.

> **NOTE**
>
> The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```ts
import bundleMonitor from '@ohos.bundle.bundleMonitor';
```

## Required Permissions

| Permission                                | Permission Level   | Description                          |
| ------------------------------------ | ----------- | ------------------------------ |
| ohos.permission.LISTEN_BUNDLE_CHANGE | system_core | Permission to listen for bundle installation, uninstall, and updates.|

For details, see [Permission Levels](../../security/accesstoken-overview.md#permission-levels).

## BundleChangeInfo

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

**System API**: This is a system API and cannot be called by third-party applications.

| Name      | Template  | Readable| Writable| Description                      |
| ---------- | ------ | ---- | ---- | -------------------------- |
| bundleName | string | Yes  | No  | Name of the bundle whose status changes.|
| userId     | number | Yes  | No  | ID of the user whose bundle status changes.  |

## bundleMonitor.on

on(type: BundleChangedEvent, callback: Callback\<BundleChangedInfo>): void;

Subscribes to bundle installation, uninstall, and update events.

**Required permissions**: ohos.permission.LISTEN_BUNDLE_CHANGE

**System API**: This is a system API and cannot be called by third-party applications.

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

**Parameters**

| Name                      | Type    | Mandatory| Description              |
| ---------------------------- | -------- | ---- | ------------------ |
| BundleChangedEvent           | string   | Yes  | Type of the event to subscribe to.|
| Callback\<BundleChangedInfo> | callback | Yes  | Callback used for the subscription.|

**Error codes**

For details about the error codes, see [Bundle Error Codes](../errorcodes/errorcode-bundle.md).

**Example**

```ts
import bundleMonitor from '@ohos.bundle.bundleMonitor';

try {
    bundleMonitor.on('add', (bundleChangeInfo) => {
        console.info(`bundleName : ${bundleChangeInfo.bundleName} userId : ${bundleChangeInfo.userId}`);
	})
} catch (errData) {
    console.log(`errData is errCode:${errData.errCode}  message:${errData.message}`);
}
```

## bundleMonitor.off

off(type: BundleChangedEvent, callback?: Callback\<BundleChangedInfo>): void;

Unsubscribes from bundle installation, uninstall, and update events.

**Required permissions**: ohos.permission.LISTEN_BUNDLE_CHANGE

**System API**: This is a system API and cannot be called by third-party applications.

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

**Parameters**

| Name                      | Type    | Mandatory| Description                                                      |
| ---------------------------- | -------- | ---- | ---------------------------------------------------------- |
| BundleChangedEvent           | string   | Yes  | Type of the event to unsubscribe from.                                        |
| Callback\<BundleChangedInfo> | callback | Yes  | Callback used for the unsubscription. If this parameter is left empty, all callbacks of the current event are unsubscribed from.|

**Error codes**

For details about the error codes, see [Bundle Error Codes](../errorcodes/errorcode-bundle.md).

**Example**

```ts
import bundleMonitor from '@ohos.bundle.bundleMonitor';

try {
    bundleMonitor.off('add');
} catch (errData) {
    console.log(`errData is errCode:${errData.errCode}  message:${errData.message}`);
}
```
