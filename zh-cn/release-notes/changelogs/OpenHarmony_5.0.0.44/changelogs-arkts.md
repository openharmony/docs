# ArkTS子系统Changelog

## cl.arkts.1 Worker模块中RestrictedWorker的接口访问级别变更

**访问级别**

公开接口

**变更原因**

因安全合规要求，RestrictedWorker的接口由public API变更为system API。

**变更影响**

该变更为不兼容变更。

变更前：
Worker模块中RestrictedWorker类中的接口访问级别为public API，外部开发者可以调用。

变更后：
Worker模块中RestrictedWorker类中的接口访问级别变更为system API，相关接口将不再对外暴露，仅供系统应用调用，外部开发者使用时会出现无法找到RestrictedWorker相关接口的编译失败问题。

**起始API Level**

API 11

**变更发生版本**

从OpenHarmony 5.0.0.44 版本开始。

**变更的接口/组件**

worker模块下的两个接口：

1. class RestrictedWorker extends ThreadWorker;

2. constructor(scriptURL: string, options?: WorkerOptions);

**适配指导**

如果业务场景只涉及线程间通信，可以选择使用worker.ThreadWorker类创建worker线程。
