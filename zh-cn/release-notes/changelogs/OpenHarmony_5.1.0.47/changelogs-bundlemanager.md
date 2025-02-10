# 包管理子系统Changelog

## cl.bundlemanager.1 installSource字段规格变更

**访问级别**

公开接口

**变更原因**

规格变更，支持开发者判断应用是否是预置应用。

**变更影响**

此变更无需应用适配。

变更前：
installSource会因为应用更新而改变。

变更前installSource取值范围：
- pre-installed表示应用为第一次开机时安装的预置应用。
- 安装来源的格式为包名表示应用由此包名对应的应用安装。
- unknown表示应用安装来源未知。

变更后：
installSource不会因为应用更新而改变。

变更后installSource取值范围：
- pre-installed表示应用为第一次开机时安装的预置应用。
- ota表示应用为系统升级时新增的预置应用。
- recovery表示卸载后再恢复的预置应用。
- 安装来源的格式为包名表示应用由此包名对应的应用安装。
- unknown表示应用安装来源未知。

例如：预置应用的installSource为pre-installed，应用市场更新此预置应用。变更前installSource变为应用市场包名，变更后此应用的installSource还是pre-installed。

**起始API Level**

API 12

**变更发生版本**

从OpenHarmony 5.1.0.47 版本开始。

**变更的接口/组件**

[ApplicationInfo](https://gitee.com/openharmony/docs/blob/master/zh-cn/application-dev/reference/apis-ability-kit/js-apis-bundleManager-applicationInfo.md)中的installSource字段。

**适配指导**

预置应用开发者需根据变更后的规格适配，可根据[ApplicationInfo](https://gitee.com/openharmony/docs/blob/master/zh-cn/application-dev/reference/apis-ability-kit/js-apis-bundleManager-applicationInfo.md)中的installSource字段判断应用是否是预置应用。