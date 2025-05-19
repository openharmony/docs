# 元能力子系统Changelog

## cl.ability.1 AbilityDelegator.startAbility()接口错误码变更

**访问级别**

公开接口

**变更原因**

AbilityDelegator.startAbility()返回的所有错误码与API描述不一致。

**变更影响**

该变更为行为不兼容变更。此变更不涉及应用适配。

例如16000001错误码。

变更前：返回错误码为2097199，与API描述不一致。

变更后：返回和API一致的错误码16000001。

**起始API Level**

API 9

**变更发生版本**

从OpenHarmony SDK 6.0.0.32开始。

**变更的接口/组件**

AbilityDelegator提供的startAbility()接口。

**适配指导**

无需适配。

AbilityDelegator提供的startAbility()接口参见[startAbility API参考](../../../application-dev/reference/apis-test-kit/js-apis-inner-application-abilityDelegator.md#startability9)。