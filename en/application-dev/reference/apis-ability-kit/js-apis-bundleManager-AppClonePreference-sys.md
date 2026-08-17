# AppClonePreference (System API)

<!--Kit: Ability Kit-->
<!--Subsystem: BundleManager-->
<!--Owner: @wanghang904-->
<!--Designer: @hanfeng6-->
<!--Tester: @kongjing2-->
<!--Adviser: @HelloCrease-->
<!-- md-trans-meta sourceCommit=96c970b9ef0e5c53bb2ae27e6f2142cdd49b75d7 translatedAt=2026-08-13T13:19:37.620Z pushedAt=2026-08-17T03:15:31.801Z -->

App clone preference, used to configure the selection policy between the main app and the clone app at app startup. It is obtained through [bundleManager.getAppClonePreference](js-apis-bundleManager-sys.md#bundlemanagergetappclonepreference) and set through [bundleManager.setAppClonePreference](js-apis-bundleManager-sys.md#bundlemanagersetappclonepreference).

**Since**: 26.0.0

## Modules to Import

```ts
import { bundleManager } from '@kit.AbilityKit';
```

## AppClonePreferenceMode

Enumerates the modes of the app clone preference.

**Since**: 26.0.0

**System API**: This is a system API.

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

**Model restriction**: This API can be used only in the stage model.

| Name | Value | Description |
| --------------- | --- | --- |
| ALWAYS_ASK        | 0   | Asks the user to select the main app or clone app each time the app is started. |
| MAIN_APP          | 1   | Uses the main app by default. |
| CLONE_APP         | 2   | Uses the clone app by default. |

## AppClonePreference

App clone preference, used to configure the selection policy between the main app and the clone app at app startup.

**Since**: 26.0.0

**System API**: This is a system API.

**System capability**: SystemCapability.BundleManager.BundleFramework.Core

**Model restriction**: This API can be used only in the stage model.

| Name      | Type           | Read-only | Optional | Description                        |
| --------- | -------------- | ---- | ---- | --------------------------- |
| mode | [AppClonePreferenceMode](#appclonepreferencemode)         | No   | No   | Mode of the app clone preference. |
| appIndex | number         | No   | Yes   | App clone index.<br>This parameter is mandatory when the value of **mode** is **AppClonePreferenceMode.CLONE_APP**, and is used to specify a specific clone app. The value is an integer ranging from 1 to 5 (the system supports a maximum of 5 clones).   |