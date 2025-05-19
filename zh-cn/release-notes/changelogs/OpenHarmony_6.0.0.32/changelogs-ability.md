# 元能力子系统Changelog

## cl.ability.1 AbilityDelegator.startAbility()接口错误码变更

**访问级别**

公开接口

**变更原因**

AbilityDelegator.startAbility()返回的所有错误码与API描述不一致。

**变更影响**

此变更不涉及应用适配。

变更影响AbilityDelegator.startAbility()返回的所有错误码，错误码对照表如下：

| 变更前    | 变更后    |
| -------- | --------  |
| 29360128 | 401       |
| 2097199  | 16000001  |
| 2097187  | 16000002  |
| 2097179  | 16000004  |
| 2097208  | 16000005  |
| 2097207  |16000006   |
| 2097203  | 16000008  |
| 11       |  16000009 |
| 2097206  | 16000010  |
| 2097323  | 16000011  |
| 2097204  | 16000012  |
| 2097215  | 16000013  |
| 2097167  | 16000050  |
| 5242881  | 16000053  |
| 29360300 | 16000055  |
| 2097205  | 16200001  |

**起始API Level**

API 9

**变更发生版本**

从OpenHarmony SDK 6.0.0.32开始。

**变更的接口/组件**

AbilityDelegator提供的startAbility()接口。

**适配指导**

无需适配。

AbilityDelegator提供的startAbility()接口参见[startAbility API参考](../../../application-dev/reference/apis-test-kit/js-apis-inner-application-abilityDelegator.md#startability9)。