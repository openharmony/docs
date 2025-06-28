# 窗口子系统变更说明

## cl.window.1 OH_NativeWindowManager_RegisterKeyEventFilter接口注册的回调事件中，回调函数参数Input_KeyEvent注入变更

**访问级别**

公开接口

**变更原因**

修复回调函数注入[Input_KeyEvent](../../../application-dev/reference/apis-input-kit/capi-input-input-keyevent.md)结构体的[Input_KeyEventAction](../../../application-dev/reference/apis-input-kit/capi-oh-input-manager-h.md#input_keyeventaction)字段时，注入值无法匹配枚举的bug。变更前注入Input_KeyEventAction的值为1、2、3分别对应取消（KEY_ACTION_CANCEL）、按下（KEY_ACTION_DOWN）和抬起（KEY_ACTION_UP）三种行为，与枚举中定义的0（KEY_ACTION_CANCEL）、1（KEY_ACTION_DOWN）、2（KEY_ACTION_UP）不匹配。

**变更影响**

该变更为不兼容变更。<br/>
变更前，注入Input_KeyEvent中的Input_KeyEventAction为1、2、3，无法匹配枚举。<br/>
变更后，注入Input_KeyEvent中的Input_KeyEventAction为0、1、2，匹配枚举。<br/>

**起始API Level**

API 12

**变更发生版本**

从OpenHarmony 5.0.0.38 版本开始。

**变更的接口/组件**

OH_NativeWindowManager_RegisterKeyEventFilter接口中，回调函数OH_NativeWindowManager_KeyEventFilter的注入实现。

**适配指导**

注入行为bug修复，开发者之前用code作硬编码需要改为对应的Input_KeyEventAction枚举。

## cl.window.2 startAbility/openLink锁屏时限制拉起行为

**访问级别**

公开接口

**变更原因**

锁屏时对任意拉起应用的行为增加限制。

**变更影响**

该变更为不兼容变更。  
变更前：锁屏时可调用startAbility/openLink接口正常拉起应用并正常保持应用窗口为前台状态。  
变更后：锁屏时调用startAbility/openLink接口拉起应用时，当应用窗口到前台状态时会被窗口管理阻止进而关闭窗口和应用。

**起始API Level**

6

**变更发生版本**

从OpenHarmony SDK 5.0.0.71版本开始。

**变更的接口/组件**

startAbility/openLink

涉及相关接口:  
UIAbilityContext:
- startAbility(want: Want, options?: StartOptions)
- startAbility(want: Want, callback: AsyncCallback&lt;void&gt;)
- startAbility(want: Want, options: StartOptions, callback: AsyncCallback&lt;void&gt;)
- startAbilityByCall(want: Want)
- startAbilityForResult(want: Want, callback: AsyncCallback&lt;AbilityResult&gt;)
- startAbilityForResult(want: Want, options: StartOptions, callback: AsyncCallback&lt;AbilityResult&gt;)
- startAbilityForResult(want: Want, options?: StartOptions)
- startAbilityAsCaller(want: Want, options?: StartOptions)
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
- startAbilityByCallWithAccount(want: Want, accountId: number)
- startAbilityAsCaller(want: Want, callback: AsyncCallback&lt;void&gt;)
- openLink(link: string, options?: OpenLinkOptions, callback?: AsyncCallback&lt;AbilityResult&gt;)

ServiceExtensionContext:
- startAbility(want: Want, options?: StartOptions)
- startAbility(want: Want, callback: AsyncCallback&lt;void&gt;)
- startAbility(want: Want, options: StartOptions, callback: AsyncCallback&lt;void&gt;)
- startAbilityWithAccount(want: Want, accountId: number, options?: StartOptions)
- startAbilityWithAccount(want: Want, accountId: number, callback: AsyncCallback&lt;void&gt;)
- startAbilityWithAccount(want: Want, accountId: number, options: StartOptions, callback: AsyncCallback&lt;void&gt;)
- startAbilityByCall(want: Want)
- startAbilityAsCaller(want: Want, options?: StartOptions)
- startAbilityAsCaller(want: Want, callback: AsyncCallback&lt;void&gt;)
- startAbilityAsCaller(want: Want, options: StartOptions, callback: AsyncCallback&lt;void&gt;)
- startRecentAbility(want: Want, options?: StartOptions)
- startRecentAbility(want: Want, callback: AsyncCallback&lt;void&gt;)
- startRecentAbility(want: Want, options: StartOptions, callback: AsyncCallback&lt;void&gt;)
- startAbilityByCallWithAccount(want: Want, accountId: number)
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
- openAtomicService(appId: string, options?: AtomicServiceOptions)

AbilityDelegator:
- startAbility(want: Want, callback: AsyncCallback&lt;void&gt;)

InsightIntentContext:
- startAbility(want: Want, callback: AsyncCallback&lt;void&gt;)

FeatureAbility:
- startAbility(parameter: StartAbilityParameter, callback: AsyncCallback&lt;number&gt;)
- startAbilityForResult(parameter: StartAbilityParameter, callback: AsyncCallback&lt;AbilityResult&gt;)

StaticSubscriberExtensionContext:
- startAbility(want: Want, callback: AsyncCallback&lt;void&gt;)

InputMethodExtensionContext:
- startAbility(want: Want)

AccessibilityExtensionContext:
- startAbility(want: Want)

FormExtensionContext:
- startAbility(want: Want, callback: AsyncCallback&lt;void&gt;)

WindowExtensionContext:
- startAbility(want: Want, options: StartOptions, callback: AsyncCallback&lt;void&gt;)

**适配指导**

锁屏时取消对相关接口的调用，否则会关闭被拉起的应用。
