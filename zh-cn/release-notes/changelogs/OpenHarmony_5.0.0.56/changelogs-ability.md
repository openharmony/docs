# 元能力子系统Changelog

## cl.ability.1 startAbility接口启动UIAbility，且UIAbility模式为singleton的时，如果该UIAbility正在启动中，返回错误码16000082

**访问级别**

公开接口

**变更原因**

通过startAbility相关接口以singleton模式启动UIAbility时，如果该UIAbility正在启动中，原有逻辑将不执行本次请求并返回OK。
为了让调用方能够感知到请求异常，变更后将返回错误码。

**变更影响**

该变更为不兼容变更。

变更前：通过startAbility相关接口以singleton模式启动UIAbility时，如果该UIAbility正在启动中，系统将不响应本次请求并返回OK。调用方不感知异常。

变更后：通过startAbility相关接口以singleton模式启动UIAbility时，如果该UIAbility正在启动中，系统将不响应本次请求并返回错误码。接口调用失败。


**起始API Level**

API 9

**变更发生版本**

从OpenHarmony SDK 5.0.0.56开始。

**变更的接口/组件**

startAbility/openLink

涉及相关接口:
UIAbilityContext:
- startAbility(want: Want, options?: StartOptions)
- startAbility(want: Want, callback: AsyncCallback&lt;void&gt;)
- startAbility(want: Want, options: StartOptions, callback: AsyncCallback&lt;void&gt;)
- startAbilityForResult(want: Want, callback: AsyncCallback&lt;AbilityResult&gt;)
- startAbilityForResult(want: Want, options: StartOptions, callback: AsyncCallback&lt;AbilityResult&gt;)
- startAbilityForResult(want: Want, options?: StartOptions)
- startAbilityAsCaller(want: Want, options?: StartOptions)
- startAbilityAsCaller(want: Want, callback: AsyncCallback&lt;void&gt;)
- startAbilityAsCaller(want: Want, options: StartOptions, callback: AsyncCallback&lt;void&gt;)
- startAbilityForResultWithAccount(want: Want, accountId: number, options?: StartOptions)
- startAbilityForResultWithAccount(want: Want, accountId: number, callback: AsyncCallback&lt;AbilityResult&gt;)
- startAbilityForResultWithAccount(want: Want, accountId: number, options: StartOptions, callback: AsyncCallback&lt;void&gt;)
- startAbilityWithAccount(want: Want, accountId: number, options?: StartOptions)
- startAbilityWithAccount(want: Want, accountId: number, callback: AsyncCallback&lt;void&gt;)
- startAbilityWithAccount(want: Want, accountId: number, options: StartOptions, callback: AsyncCallback&lt;void&gt;)
- startRecentAbility(want: Want, options?: StartOptions)
- startRecentAbility(want: Want, callback: AsyncCallback&lt;void&gt;)
- startRecentAbility(want: Want, options: StartOptions, callback: AsyncCallback&lt;void&gt;)
- openLink(link: string, options?: OpenLinkOptions, callback?: AsyncCallback&lt;AbilityResult&gt;)

ServiceExtensionContext:
- startAbility(want: Want, options?: StartOptions)
- startAbility(want: Want, callback: AsyncCallback&lt;void&gt;)
- startAbility(want: Want, options: StartOptions, callback: AsyncCallback&lt;void&gt;)
- startAbilityWithAccount(want: Want, accountId: number, options?: StartOptions)
- startAbilityWithAccount(want: Want, accountId: number, callback: AsyncCallback&lt;void&gt;)
- startAbilityWithAccount(want: Want, accountId: number, options: StartOptions, callback: AsyncCallback&lt;void&gt;)
- startAbilityAsCaller(want: Want, options?: StartOptions)
- startAbilityAsCaller(want: Want, callback: AsyncCallback&lt;void&gt;)
- startAbilityAsCaller(want: Want, options: StartOptions, callback: AsyncCallback&lt;void&gt;)
- startRecentAbility(want: Want, options?: StartOptions)
- startRecentAbility(want: Want, callback: AsyncCallback&lt;void&gt;)
- startRecentAbility(want: Want, options: StartOptions, callback: AsyncCallback&lt;void&gt;)
- openLink(link:string, options?: OpenLinkOptions)

UIExtensionContext:
- startAbility(want: Want, options?: StartOptions)
- startAbility(want: Want, callback: AsyncCallback&lt;void&gt;)
- startAbility(want: Want, options: StartOptions, callback: AsyncCallback&lt;void&gt;)
- startAbilityForResult(want: Want, callback: AsyncCallback&lt;AbilityResult&gt;)
- startAbilityForResult(want: Want, options: StartOptions, callback: AsyncCallback&lt;AbilityResult&gt;)
- startAbilityForResult(want: Want, options?: StartOptions)
- startAbilityForResultAsCaller(want: Want, options?: StartOptions)
- openLink(link:string, options?: OpenLinkOptions, callback?: AsyncCallback&lt;AbilityResult&gt;)

UIExtensionContentSession
- startAbility(want: Want, options?: StartOptions)
- startAbility(want: Want, callback: AsyncCallback&lt;void&gt;)
- startAbility(want: Want, options: StartOptions, callback: AsyncCallback&lt;void&gt;)
- startAbilityForResult(want: Want, callback: AsyncCallback&lt;AbilityResult&gt;)
- startAbilityForResult(want: Want, options: StartOptions, callback: AsyncCallback&lt;AbilityResult&gt;)
- startAbilityForResult(want: Want, options?: StartOptions)
- startAbilityAsCaller(want: Want, options?: StartOptions)
- startAbilityAsCaller(want: Want, callback: AsyncCallback&lt;void&gt;)
- startAbilityAsCaller(want: Want, options: StartOptions, callback: AsyncCallback&lt;void&gt;)

AbilityDelegator:
- startAbility(want: Want)
- startAbility(want: Want, callback: AsyncCallback&lt;void&gt;)

InsightIntentContext:
- startAbility(want: Want)
- startAbility(want: Want, callback: AsyncCallback&lt;void&gt;)

**适配指导**

应用侧调用接口启动UIAbility，且该UIAbility模式为singleton时，如果收到错误码16000082，表示该UIAbility正在启动中，需要等该UIAbility启动完成，再进行重试。