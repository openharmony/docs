# ArkCompiler子系统Changelog

## 修复了极罕见情况下超大函数可能引发应用crash的问题

**访问级别**

其他

**变更原因**

开发者源码中存在超大函数或者超大类，在一些罕见场景下会编译出错误的字节码文件导致运行时crash或者运行出错，crash的错误信息为 Reason:Signal:SIGSEGV 或是 Segmentation Fault。

**变更影响**

此变更为兼容变更。

变更前，特定场景会造成crash或者运行结果异常。

变更后，问题修复。

**起始 API Level**

从API 12起修复。

**变更发生版本**

从OpenHarmony SDK 5.0.0.39 开始。

**变更的接口/组件**

不涉及。

**适配指导**

升级OpenHarmony SDK 5.0.0.39及以上版本，并重新编译应用。
