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

## cl.ability.2 借助Want进行文件分享时擦除不合法的URI

**访问级别**

公开接口

**变更原因**

在文件分享场景下（Want的flags字段中配置了[wantConstant.Flags.FLAG_AUTH_READ_URI_PERMISSION](../../../application-dev/reference/apis-ability-kit/js-apis-app-ability-wantConstant.md#flags)或[wantConstant.Flags.FLAG_AUTH_WRITE_URI_PERMISSION](../../../application-dev/reference/apis-ability-kit/js-apis-app-ability-wantConstant.md#flags)），应用可以通过Want的uri字段传递单个URI、或者通过[wantConstant.Params.PARAMS_STREAM](../../../application-dev/reference/apis-ability-kit/js-apis-app-ability-wantConstant.md#params)的Key值传递多个URI。为了确保传递给目标应用的参数合法，系统将主动擦除不满足条件的URI。

**变更影响**

此变更不涉及应用适配。

变更前：文件分享场景下，如果Want的uri字段中scheme为空，或wantConstant.Params.PARAMS_STREAM字段中的URI的scheme不为file，系统不做任何处理。

变更后：文件分享场景下，如果Want的uri字段中scheme为空，或wantConstant.Params.PARAMS_STREAM字段中的URI的scheme不为file，系统将擦除对应的URI取值。

**起始API Level**

API 9

**变更发生版本**

从OpenHarmony SDK 6.0.0.32开始。

**变更的接口/组件**

启动和退出应用的相关接口在文件分享场景下可触发该变更，涉及的接口如下：

[UIAbilityContext](../../../application-dev/reference/apis-ability-kit/js-apis-inner-application-uiAbilityContext.md#uiabilitycontext):
- startAbility(want: Want, callback: AsyncCallback&lt;void&gt;): void
- startAbility(want: Want, options: StartOptions, callback: AsyncCallback&lt;void&gt;): void
- startAbility(want: Want, options?: StartOptions): Promise&lt;void&gt;
- startAbilityForResult(want: Want, callback: AsyncCallback&lt;AbilityResult&gt;): void
- startAbilityForResult(want: Want, options: StartOptions, callback: AsyncCallback&lt;AbilityResult&gt;): void
- startAbilityForResult(want: Want, options?: StartOptions): Promise&lt;AbilityResult&gt;
- terminateSelfWithResult(parameter: AbilityResult, callback: AsyncCallback&lt;void&gt;): void
- terminateSelfWithResult(parameter: AbilityResult): Promise&lt;void&gt;
- connectServiceExtensionAbility(want: Want, options: ConnectOptions): number
- startAbilityByCall(want: Want): Promise&lt;Caller&gt;
- startUIServiceExtensionAbility(want: Want): Promise&lt;void&gt;
- connectUIServiceExtensionAbility(want: Want, callback: UIServiceExtensionConnectCallback) : Promise&lt;UIServiceProxy&gt;

[UIExtensionContext](../../../application-dev/reference/apis-ability-kit/js-apis-inner-application-uiExtensionContext.md#uiextensioncontext):

- startAbility(want: Want, callback: AsyncCallback&lt;void&gt;): void
- startAbility(want: Want, options: StartOptions, callback: AsyncCallback&lt;void&gt;): void
- startAbility(want: Want, options?: StartOptions): Promise&lt;void&gt;
- startAbilityForResult(want: Want, callback: AsyncCallback&lt;AbilityResult&gt;): void
- startAbilityForResult(want: Want, options: StartOptions, callback: AsyncCallback&lt;AbilityResult&gt;): void
- startAbilityForResult(want: Want, options?: StartOptions): Promise&lt;AbilityResult&gt;
- connectServiceExtensionAbility(want: Want, options: ConnectOptions): number
- terminateSelfWithResult(parameter: AbilityResult, callback: AsyncCallback&lt;void&gt;): void
- terminateSelfWithResult(parameter: AbilityResult): Promise&lt;void&gt;
- startUIServiceExtensionAbility(want: Want): Promise&lt;void&gt;
- connectUIServiceExtensionAbility(want: Want, callback: UIServiceExtensionConnectCallback) : Promise&lt;UIServiceProxy&gt;

**适配指导**

默认行为变更，无需适配。