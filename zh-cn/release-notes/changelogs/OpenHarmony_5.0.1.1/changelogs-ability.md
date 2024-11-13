# 元能力子系统变更说明

## cl.ability.1 childProcessManager增加子进程最大数量限制

**访问级别**

公开接口

**变更原因**

应用可以无限制启动子进程，这个场景存在恶意调用风险，因此需要增加子进程最大数量限制。

**变更影响**

该变更为不兼容变更。

变更前：每个应用通过childProcessManager启动的子进程总数没有限制。

变更后：每个应用通过childProcessManager(非SELF_FORK模式)启动的子进程总数上限为512个。

**起始 API Level**

11

**变更发生版本**

从OpenHarmony 5.0.1.1 版本开始。

**变更的接口/组件**

childProcessManager中的startChildProcess(非SELF_FORK模式)、startArkChildProcess接口。

**适配指导**

行为变更：无需适配，通过childProcessManager最大可以启动的子进程数量为512个，超过后无法启动。