# ArkTS子系统Changelog

## cl.arkts.1 受限虚拟机中RestrictedWorker的接口访问级别变更

**访问级别**

公开接口

**变更原因**

因安全合规要求，RestrictedWorker的接口由public API变更为system API。

**变更影响**

该变更为不兼容变更。

变更前：
受限虚拟机中RestrictedWorker类中的接口访问级别为public API，外部开发者可以调用。

变更后：
受限虚拟机中RestrictedWorker类中的接口访问级别变更为system API，仅供系统应用调用，外部开发者将无法调用相关接口。


**起始API Level**

API 11

**变更发生版本**

从OpenHarmony 5.0.0.44 版本开始。

**变更的接口/组件**

worker模块下的两个接口：

1. class RestrictedWorker extends ThreadWorker;

2. constructor(scriptURL: string, options?: WorkerOptions);

**适配指导**

受限虚拟机相关的接口访问级别变更为system API，相关接口将不再对外暴露。

外部开发者将无法正常调用受限虚拟机相关的接口，强行使用会出现编译告警。

如果业务场景只涉及线程间通信，对受限环境没有需求，可以选择使用worker.ThreadWorker类创建worker线程。
