# 包管理子系统Changelog

## cl.bundlemanager.1 包管理[@ohos.bundle.bundleManager.d.ts](https://gitee.com/openharmony/interface_sdk-js/blob/master/api/@ohos.bundle.bundleManager.d.ts)中的bundleManager.verifyAbc接口以及bundleManager.deleteAbc接口变更为系统api

**访问级别**

公开接口

**变更原因**

因安全合规要求，包管理[@ohos.bundle.bundleManager.d.ts](https://gitee.com/openharmony/interface_sdk-js/blob/master/api/@ohos.bundle.bundleManager.d.ts)中的bundleManager.verifyAbc接口以及bundleManager.deleteAbc接口变更为系统api

**变更影响**

该变更为不兼容变更。

变更前：
包管理[@ohos.bundle.bundleManager.d.ts](https://gitee.com/openharmony/interface_sdk-js/blob/master/api/@ohos.bundle.bundleManager.d.ts)中的bundleManager.verifyAbc接口以及bundleManager.deleteAbc接口访问级别为public API，外部开发者可以调用。

变更后：
包管理[@ohos.bundle.bundleManager.d.ts](https://gitee.com/openharmony/interface_sdk-js/blob/master/api/@ohos.bundle.bundleManager.d.ts)中的bundleManager.verifyAbc接口以及bundleManager.deleteAbc接口访问级别变更为system API，仅供系统应用调用，外部开发者将无法调用相关接口，非系统应用调用相关接口会返回202错误。


**起始API Level**

API 11

**变更发生版本**

从OpenHarmony 5.0.0.44 版本开始。

**变更的接口/组件**

[@ohos.bundle.bundleManager.d.ts](https://gitee.com/openharmony/interface_sdk-js/blob/master/api/@ohos.bundle.bundleManager.d.ts)中如下接口：

1. function verifyAbc(abcPaths: Array\<string\>, deleteOriginalFiles: boolean, callback: AsyncCallback\<void\>): void;

2. function verifyAbc(abcPaths: Array\<string\>, deleteOriginalFiles: boolean): Promise\<void\>;

3. function deleteAbc(abcPath: string): Promise\<void\>;

**适配指导**

取消对相关接口的调用，非系统应用调用相关接口会返回202错误。