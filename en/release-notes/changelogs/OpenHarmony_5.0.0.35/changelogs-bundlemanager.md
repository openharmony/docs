# Bundle Manager Subsystem Changelog

## cl.bundlemanager.1 Behavior of the APIs for Obtaining BundleResourceInfo and LauncherAbilityResourceInfo Is Changed to Support Obtaining of the Icons and Names of Disabled Applications and Installed Applications of All Users

**Access Level**

System API

**Reason for Change**

1. After an application is disabled, there is no way to display its icon and name. APIs should be available to support obtaining of such icons and names.
2. APIs should be available to support obtaining of the icons and names of applications installed by other users.

**Change Impact**

This change is a non-compatible change.

|API               | Before Change   | After Change|
|------------------------|---------|---------|
| getBundleResourceInfo  |The API throws error code 1770001 if the bundle name of a disabled application or an application of another user is passed in. | The API returns data normally if the bundle name of a disabled application or an application of another user is passed in.|
| getAllBundleResourceInfo  |The API returns the icons and names of applications installed by the current user, excluding disabled applications and applications installed by other users. | The API returns the icons and names of applications installed on the current device, including disabled applications and applications installed by other users.|
| getLauncherAbilityResourceInfo  |The API throws error code 1770001 if the bundle name of a disabled application or an application of another user is passed in. | The API returns data normally if the bundle name of a disabled application or an application of another user is passed in.|
| getAllLauncherAbilityResourceInfo  |The API returns the icons and names of applications installed by the current user, excluding disabled applications and applications installed by other users. | The API returns the icons and names of applications installed on the current device, including disabled applications and applications installed by other users.|


**Start API Level**

11

**Change Since**

OpenHarmony SDK 5.0.0.35

**Key API/Component Changes**

| Interface file  |
|---------|
| [ohos.bundle.bundleResourceManager.d.ts](https://gitee.com/openharmony/interface_sdk-js/blob/master/api/@ohos.bundle.bundleResourceManager.d.ts) |

| API  |
|---------|
| getBundleResourceInfo |
| getAllBundleResourceInfo |
| getLauncherAbilityResourceInfo |
| getAllLauncherAbilityResourceInfo |


**Adaptation Guide**

After obtaining the application icons and names, you need to determine whether to display all of them. You can use **getAllBundleInfo** in the bundleManager module or **getLaunchAbilityInfo** in the launcherBundleManager module to obtain the application information of the current user, and then selectively display the icons and names obtained.
