# 元能力子系统Changelog

## cl.ability.1 aa工具不支持对Release模式的应用进行调试

**访问级别**

公开接口。

**变更原因**

aa工具是DevEco Studio调试能力的底层依赖，正常的调试场景都通过DevEco Studio进行，正常情况下DevEco Studio会限制对Release模式的应用进行调试，但存在绕过DevEco Studio直接使用aa工具的调试命令进行调试的风险，应当从根本上限制此行为。

**变更影响**

该变更为不兼容变更。

变更前：
存在绕过DevEco Studio直接通过aa工具的命令调试Release模式的应用的风险。

变更后：
aa工具不支持对Release模式的应用进行调试。

**起始API Level**

不涉及。

**变更发生版本**

从OpenHarmony SDK 5.0.0.43开始。

**变更的接口/组件**

aa工具。

**适配指导**

默认行为变更，无需适配。


## cl.ability.2.禁止通过wantAgent拉起ExtensionAbility

**访问级别**

公开接口

**变更原因**

三方应用创建拉起ExtensionAbility的wantAgent，并发送携带此wantAgent的通知。通过桌面点击通知拉起该ExtensionAbility，应用退出后，该ExtensionAbility进程无法退出从而影响功耗。

**变更影响**

该变更为不兼容变更。

变更前：
三方应用创建拉起ExtensionAbility的wantAgent，并发送携带此wantAgent的通知。通过桌面点击通知可以拉起该ExtensionAbility。

变更后：
三方应用创建拉起ExtensionAbility的wantAgent，并发送携带此wantAgent的通知。通过桌面点击通知无法拉起该ExtensionAbility。

**起始API Level**

API 9

**变更发生版本**

从OpenHarmony SDK 5.0.0.43开始。

**变更的接口/组件**

wantAgent.trigger接口

**适配指导**

建议不要创建拉起ExtensionAbility的wantAgent，否则通过wantAgent的trigger接口拉起该ExtensionAbility会拉起失败。
