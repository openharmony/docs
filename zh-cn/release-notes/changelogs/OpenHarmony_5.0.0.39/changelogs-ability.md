# 元能力子系统变更说明

## cl.ability.1 拉起UIExtensionAbility增加调用方为前台应用的校验

**访问级别**

公开接口

**变更原因**

UIExtensionAbility仅支持拥有前台窗口的应用拉起，虽有该约束，但未校验调用方是否为前台应用，存在后台应用拉起UIExtensionAbility的风险。

**变更影响**

该变更为不兼容变更。

变更前：未对后台应用拉起UIExtensionAbility做约束限制。

变更后：后台应用不允许拉起UIExtensionAbility。

**起始 API Level**

11

**变更发生版本**

从OpenHarmony 5.0.0.39 版本开始。

**变更的接口/组件**

1、UIAbilityContext.startAbilityByType、UIExtensionContentSession.startAbilityByType

2、具备拉起UIExtensionAbility能力的接口。

**适配指导**

行为变更：无需适配，变更后不允许后台应用拉起UIExtensionAbility。
