# 包管理子系统变更说明

## cl.bundlemanager.1 获取BundleResourceInfo和LauncherAbilityResourceInfo接口行为变更，支持获取被禁用应用和设备上已安装的应用(不区分用户)图标和名称资源

**访问级别**

系统接口

**变更原因**

1. 应用被禁用后，无法通过其他方法展示应用的图标和名称，需要使用资源缓存接口返回图标和名称资源。
2. 跨用户查询应用图标时，无法通过现有接口返回应用的图标和名称，需要使用资源缓存接口返回图标和名称资源。

**变更影响**

该变更为不兼容变更。

|接口名称                | 变更前    | 变更后|
|------------------------|---------|---------|
| getBundleResourceInfo  |传入被禁用应用或者其他用户下安装的bundleName，接口会抛出错误码1770001 | 传入被禁用应用或者其他用户下安装的bundleName，接口可以正常返回数据|
| getAllBundleResourceInfo  |返回当前用户下已安装的应用图标和名称资源，不包含被禁用应用和其他用户安装的应用 | 返回当前设备上已安装的应用图标和名称资源，包含被禁用应用和其他用户安装的应用|
| getLauncherAbilityResourceInfo  |传入被禁用应用或者其他用户下安装的bundleName，接口会抛出错误码1770001 | 传入被禁用应用或者其他用户下安装的bundleName，接口可以正常返回数据|
| getAllLauncherAbilityResourceInfo  |返回当前用户下已安装的应用图标和名称资源，不包含被禁用应用和其他用户安装的应用 | 返回当前设备上已安装的应用图标和名称资源，包含被禁用应用和其他用户安装的应用|


**起始API Level**

11

**变更发生版本**

从OpenHarmony SDK 5.0.0.35 版本开始。

**变更的接口/组件**

| 接口文件   |
|---------|
| [ohos.bundle.bundleResourceManager.d.ts](https://gitee.com/openharmony/interface_sdk-js/blob/master/api/@ohos.bundle.bundleResourceManager.d.ts) |

| 接口名称   |
|---------|
| getBundleResourceInfo |
| getAllBundleResourceInfo |
| getLauncherAbilityResourceInfo |
| getAllLauncherAbilityResourceInfo |


**适配指导**

使用资源缓存接口拿到应用的图标和名称后，需要区分下是否需要展示。可以通过bundleManager模块中的getAllBundleInfo或者launcherBundleManager模块中的getLaunchAbilityInfo接口获取当前用户下应用的信息，然后拿到图标和名称资源进行展示。

