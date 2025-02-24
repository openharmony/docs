# 包管理子系统Changelog

## cl.bundlemanager.1 supportWindowModes选项配置fullscreen和split时，窗口由自由窗口状态启动变更为全屏启动

**访问级别**

公开接口

**变更原因**

2in1设备上 通过 [supportWindowModes](../../../application-dev/quick-start/module-configuration-file.md#abilities标签)配置fullscreen和split时，2in1设备的窗口将以自由窗口状态启动，与预期效果不符。

**变更影响**

此变更涉及应用适配。

变更前：supportWindowModes配置fullscreen和split时，2in1设备上以自由窗口启动。

变更后：supportWindowModes配置fullscreen和split时，2in1设备上窗口全屏启动。

**起始API Level**

API 9

**变更发生版本**

从OpenHarmony 5.1.0.52 版本开始。

**变更的接口/组件**

module.json5中supportWindowModes标签

**适配指导**

API version 15及之后的版本, 开发者需要关注supportWindowModes配置fullscreen和split时，2in1设备上窗口全屏启动。
若预期是以自由窗口启动，则需要在supportWindowModes原来的配置项中增加floating配置项。

## cl.bundlemanager.2 [@ohos.bundle.installer.d.ts](https://gitee.com/openharmony/interface_sdk-js/blob/master/api/@ohos.bundle.installer.d.ts)中install接口行为变更

**访问级别**

系统接口

**变更原因**

1. 防止安装一个低版本的预置系统应用。

2. 安装一个已卸载的系统预置应用，能够继承预置应用的独立selinux标签。

**变更影响**

此变更涉及应用适配。

变更前：安装一个已卸载的预置系统应用，能够直接安装成功。

变更后：安装一个已卸载的预置系统应用，会先进行预置版本应用的安装，然后再继续安装目标版本应用。如果目标版本号比预置的低，会返回安装失败错误码，但预置版本的应用安装成功。

**起始API Level**

API 9

**变更发生版本**

从OpenHarmony 5.1.0.52 版本开始。

**变更的接口/组件**

[@ohos.bundle.installer.d.ts](https://gitee.com/openharmony/interface_sdk-js/blob/master/api/@ohos.bundle.installer.d.ts)中如下接口：

1. function install(hapFilePaths: Array<string>, installParam: InstallParam, callback: AsyncCallback<void>): void;

2. function install(hapFilePaths: Array<string>, callback: AsyncCallback<void>): void;

3. function install(hapFilePaths: Array<string>, installParam?: InstallParam): Promise<void>;

**适配指导**

系统应用开发者需要处理该场景下新增的错误码--安装预置版本成功，但目标版本应用安装失败。