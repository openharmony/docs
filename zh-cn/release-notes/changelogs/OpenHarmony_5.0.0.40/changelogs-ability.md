# 元能力子系统变更说明

## cl.ability.1 startAbility从后台发起时，即使应用正在运行长时任务，也不能调用成功。

**访问级别**

公开接口

**变更原因**

应用从后台使用startAbility拉起自己或者其他应用，这种行为是禁止的。但是利用长时任务，当前可以达到应用在后台依然startAbility成功的效果。这个场景存在恶意弹窗等风险，因此现在禁止应用在运行长时任务时，从后台调用startAbility的行为。

**变更影响**

该变更为不兼容变更。

变更前：应用运行长时任务时，可以在后台调用startAbility成功。

变更后：应用运行长时任务时，在后台调用startAbility会失败。

**起始 API Level**

9

**变更发生版本**

从OpenHarmony 5.0.0.40 版本开始。

**变更的接口/组件**

各个context中的startAbility接口。

**适配指导**

避免在后台通过长时任务调用startAbility，否则会调用失败。

## cl.ability.2 禁止BackupExtensionAbility进程拉起启动框架

**访问级别**

公开接口

**变更原因**

BackupExtensionAbility进程用于数据迁移服务，进行数据迁移时，应用还未启动，此时拉起启动框架会影响数据迁移的正常执行。

**变更影响**

该变更为不兼容变更。

变更前：BackupExtensionAbility进程可以拉起启动框架并执行启动任务。

变更后：BackupExtensionAbility进程无法拉起启动框架。

**起始 API Level**

12

**变更发生版本**

从OpenHarmony 5.0.0.40 版本开始。

**变更的接口/组件**

AppStartup启动框架模块默认行为

**适配指导**

默认行为变更，无需适配，但应注意变更后的行为是否对整体应用逻辑产生影响。
