# @ohos.bundle.bundleMonitor (bundleMonitor)

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

For details, see [Permission Levels](../../security/accesstoken-overview.md).

## BundleChangeInfo

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

**System API**: This is a system API.

| Name      | Template  | Readable| Writable| Description                      |
| ---------- | ------ | ---- | ---- | -------------------------- |
| bundleName | string | Yes  | No  | Name of the bundle whose status changes.|
| userId     | number | Yes  | No  | ID of the user whose bundle status changes.  |

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

on(type: BundleChangedEvent, callback: Callback\<BundleChangedInfo>): void;

Subscribes to bundle installation, uninstall, and update events.

**Required permissions**: ohos.permission.LISTEN_BUNDLE_CHANGE

**System API**: This is a system API.

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

**Parameters**

| Name                      | Type    | Mandatory| Description              |
| ---------------------------- | -------- | ---- | ------------------ |
| type| [BundleChangedEvent](js-apis-bundleMonitor.md#bundlechangedevent)| Yes  | Type of the event to subscribe to.|
| callback | callback\<BundleChangedInfo>| Yes  | Callback used for the subscription.|

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

**System API**: This is a system API.

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

**Parameters**

| Name                      | Type    | Mandatory| Description                                                      |
| ---------------------------- | -------- | ---- | ---------------------------------------------------------- |
| type| [BundleChangedEvent](js-apis-bundleMonitor.md#bundlechangedevent)| Yes  | Type of the event to unsubscribe from.                                        |
| callback | callback\<BundleChangedInfo>| No  | Callback used for the unsubscription. By default, no value is passed, and all callbacks of the current event are unsubscribed from.|

**Example**

```ts
import bundleMonitor from '@ohos.bundle.bundleMonitor';

try {
    bundleMonitor.off('add');
} catch (errData) {
    console.log(`errData is errCode:${errData.errCode}  message:${errData.message}`);
}
```
