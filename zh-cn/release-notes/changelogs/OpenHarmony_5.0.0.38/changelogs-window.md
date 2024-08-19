# 窗口子系统变更说明

## cl.window.1 OH_NativeWindowManager_RegisterKeyEventFilter接口注册的回调事件中，回调函数参数Input_KeyEvent注入变更

**访问级别**

公开接口

**变更原因**

修复回调函数注入[Input_KeyEvent](../../../application-dev/reference/apis-input-kit/input.md)结构体的[Input_KeyEventAction](../../../application-dev/reference/apis-input-kit/input.md#input_keyeventaction)字段时，注入值无法匹配枚举的bug。变更前注入Input_KeyEventAction的值为1、2、3分别对应取消（KEY_ACTION_CANCEL）、按下（KEY_ACTION_DOWN）和抬起（KEY_ACTION_UP）三种行为，与枚举中定义的0（KEY_ACTION_CANCEL）、1（KEY_ACTION_DOWN）、2（KEY_ACTION_UP）不匹配。

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

## cl.window.2 SatrtAbility行为变更

**访问级别**

公开接口

**变更原因**

锁屏时任意拉起应用存在安全风险。

**变更影响**

该变更为不兼容变更。
显示的应用拉起其他应用时，根据安全要求，WMS会对被拉起方进行校验。校验不通过的，被拉起时不能直接在锁屏上跳转显示。拉起到前台过程会在锁屏下进行。
锁屏时，根据安全要求，WMS会在窗口到前台时进行校验。处于锁屏状态时，未设置锁屏之上显示的应用主窗口会被阻止到前台并关闭。
变更前：
startAbility可以在锁屏时任意拉起应用；startAbility可以在锁屏时任意拉起应用。
变更后：
被拉起方如果无特殊权限，拉起到前台时会被关闭。

**起始API Level**

13

**变更发生版本**

OpenHarmony-5.0-Release

**变更的接口/组件**

startAbility
变更前后，在被拉起应用没有配置对应权限的情况下，锁屏时调用startAbility的效果如下

|调用方|变更前|变更后|
|---|---|---|
|被拉起应用窗口未在创建时设置setShowOnLockScreen(true)|在锁屏下拉起到前台|应用窗口被关闭|

涉及相关接口：
|UIAbilityContext|ServiceExtensionContext|UIExtensionContext|
|---|---|---|
|startAbility(want: Want, callback: AsyncCallback<void>)|startAbility(want: Want, callback: AsyncCallback<void>)|startAbility(want: Want, callback: AsyncCallback<void>)|
|startAbility(want: Want, options: StartOptions, callback: AsyncCallback<void>)|startAbility(want: Want, options: StartOptions, callback: AsyncCallback<void>)|startAbility(want: Want, options: StartOptions, callback: AsyncCallback<void>)|
|startAbility(want: Want, options?: StartOptions)|startAbility(want: Want, options?: StartOptions)|startAbility(want: Want, options?: StartOptions)|
|startAbilityForResult(want: Want, callback: AsyncCallback<AbilityResult>)|startAbilityWithAccount(want: Want, accountId: number, callback: AsyncCallback<void>)|startAbilityForResult(want: Want, callback: AsyncCallback<AbilityResult>)|
|startAbilityForResult(want: Want, options: StartOptions, callback: AsyncCallback<AbilityResult>)|startAbilityWithAccount(want: Want, accountId: number, options: StartOptions, callback: AsyncCallback<void>)|startAbilityForResult(want: Want, options: StartOptions, callback: AsyncCallback<AbilityResult>)|
|startAbilityForResult(want: Want, options?: StartOptions)|startAbilityWithAccount(want: Want, accountId: number, options?: StartOptions)|startAbilityForResult(want: Want, options?: StartOptions)|
|startAbilityByCall(want: Want)|startAbilityAsCaller(want: Want, callback: AsyncCallback<void>)|openLink(link:string, options?: OpenLinkOptions, callback?: AsyncCallback<AbilityResult>)|
|startAbilityByType(type: string, wantParam: Record<string, Object>, abilityStartCallback: AbilityStartCallback, callback: AsyncCallback<void>)|startAbilityAsCaller(want: Want, options: StartOptions, callback: AsyncCallback<void>)|openAtomicService(appId: string, options?: AtomicServiceOptions)|
|startAbilityByType(type: string, wantParam: Record<string, Object>, abilityStartCallback: AbilityStartCallback)|startAbilityAsCaller(want: Want, options?: StartOptions)|startAbilityForResultAsCaller(want: Want, options?: StartOptions)|
|openLink(link: string, options?: OpenLinkOptions, callback?: AsyncCallback<AbilityResult>)|startAbilityByCall(want: Want)||
|startAbilityForResultWithAccount(want: Want, accountId: number, callback: AsyncCallback<AbilityResult>)|startRecentAbility(want: Want, callback: AsyncCallback<void>)||
|startAbilityForResultWithAccount(want: Want, accountId: number, options: StartOptions, callback: AsyncCallback<void>)|startRecentAbility(want: Want, options: StartOptions, callback: AsyncCallback<void>)||
|startAbilityForResultWithAccount(want: Want, accountId: number, options?: StartOptions)|startRecentAbility(want: Want, options?: StartOptions)||
|startAbilityWithAccount(want: Want, accountId: number, callback: AsyncCallback<void>)|startAbilityByCallWithAccount(want: Want, accountId: number)||
|startAbilityWithAccount(want: Want, accountId: number, options: StartOptions, callback: AsyncCallback<void>)|openLink(link:string, options?: OpenLinkOptions)||
|startAbilityWithAccount(want: Want, accountId: number, options?: StartOptions)|||
|startRecentAbility(want: Want, callback: AsyncCallback<void>)|||
|startRecentAbility(want: Want, options: StartOptions, callback: AsyncCallback<void>)|||
|startRecentAbility(want: Want, options?: StartOptions)|||
|startAbilityByCallWithAccount(want: Want, accountId: number)|||
|startAbilityAsCaller(want: Want, callback: AsyncCallback<void>)|||
|startAbilityAsCaller(want: Want, options: StartOptions, callback: AsyncCallback<void>)|||
|startAbilityAsCaller(want: Want, options?: StartOptions)|||



**适配指导**

锁屏时调用startAbility。
锁屏时拉起应用：需要在锁屏上显示的，在窗口到前台之前调用SetShowWhenLockScreen接口设置锁屏之上显示；否则，需要申请对应权限。
