# Window Subsystem Changelog

## cl.window.1 Input_KeyEvent Injection Changed in the Callback Event Registered by OH_NativeWindowManager_RegisterKeyEventFilter

**Access Level**

Public API

**Reason for Change**

The injected value does not match the enumerated value when the [Input_KeyEventAction](../../../application-dev/reference/apis-input-kit/input.md#input_keyeventaction) field of the [Input_KeyEvent](../../../application-dev/reference/apis-input-kit/input.md) struct is injected into the callback function. Before the change, the values 1, 2, and 3 of **Input_KeyEventAction** correspond to KEY_ACTION_CANCEL, KEY_ACTION_DOWN, and KEY_ACTION_UP, respectively, whereas the enumerated values are 0 (KEY_ACTION_CANCEL), 1 (KEY_ACTION_DOWN), and 2 (KEY_ACTION_UP).

**Change Impact**

This change is a non-compatible change.<br>
Before the change, the value of **Input_KeyEventAction** in **Input_KeyEvent** is 1, 2, or 3, which does not match the enumerated values.<br>
After the change, the value of **Input_KeyEventAction** in **Input_KeyEvent** is 0, 1, or 2, which matches the enumerated values.<br>

**Start API Level**

API version 12

**Change Since**

OpenHarmony SDK 5.0.0.38

**Key API/Component Changes**

Injection implementation of the callback function **OH_NativeWindowManager_KeyEventFilter** registered by calling **OH_NativeWindowManager_RegisterKeyEventFilter**

**Adaptation Guide**

Change the code to the corresponding enumerated values of **Input_KeyEventAction**.

## cl.window.2 Startup Behavior of startAbility and openLink Is Restricted on a Lock Screen

**Access Level**

Public API

**Reason for Change**

Added restrictions on the behavior of randomly starting applications when the screen is locked.

**Change Impact**

This change is a non-compatible change. 

Before the change: When the screen is locked, the **startAbility** and **openLink** APIs can be called to start an application and keep the application window in the foreground. 

After the change: When **startAbility** or **openLink** is called to start an application on a lock screen, the application window is blocked by the window manager when it attempts to enter the foreground state, and the window and application are closed.

**Start API Level**

6

**Change Since**

OpenHarmony SDK 5.0.0.71

**Key API/Component Changes**

startAbility/openLink

The following interfaces are involved:
|UIAbilityContext|ServiceExtensionContext|UIExtensionContext|
|---|---|---|
|startAbility(want: Want, callback: AsyncCallback&lt;void&gt;)|startAbility(want: Want, callback: AsyncCallback&lt;void&gt;)|startAbility(want: Want, callback: AsyncCallback&lt;void&gt;)|
|startAbility(want: Want, options: StartOptions, callback: AsyncCallback&lt;void&gt;)|startAbility(want: Want, options: StartOptions, callback: AsyncCallback&lt;void&gt;)|startAbility(want: Want, options: StartOptions, callback: AsyncCallback&lt;void&gt;)|
|startAbility(want: Want, options?: StartOptions)|startAbility(want: Want, options?: StartOptions)|startAbility(want: Want, options?: StartOptions)|
|startAbilityForResult(want: Want, callback: AsyncCallback&lt;AbilityResult&gt;)|startAbilityWithAccount(want: Want, accountId: number, callback: AsyncCallback&lt;void&gt;)|startAbilityForResult(want: Want, callback: AsyncCallback&lt;AbilityResult&gt;)|
|startAbilityForResult(want: Want, options: StartOptions, callback: AsyncCallback&lt;AbilityResult&gt;)|startAbilityWithAccount(want: Want, accountId: number, options: StartOptions, callback: AsyncCallback&lt;void&gt;)|startAbilityForResult(want: Want, options: StartOptions, callback: AsyncCallback&lt;AbilityResult&gt;)|
|startAbilityForResult(want: Want, options?: StartOptions)|startAbilityWithAccount(want: Want, accountId: number, options?: StartOptions)|startAbilityForResult(want: Want, options?: StartOptions)|
|startAbilityByCall(want: Want)|startAbilityAsCaller(want: Want, callback: AsyncCallback&lt;void&gt;)|openLink(link:string, options?: OpenLinkOptions, callback?: AsyncCallback&lt;AbilityResult&gt;)|
|startAbilityAsCaller(want: Want, options?: StartOptions)|startAbilityAsCaller(want: Want, options: StartOptions, callback: AsyncCallback&lt;void&gt;)|openAtomicService(appId: string, options?: AtomicServiceOptions)|
|startAbilityAsCaller(want: Want, options: StartOptions, callback: AsyncCallback&lt;void&gt;)|startAbilityAsCaller(want: Want, options?: StartOptions)|startAbilityForResultAsCaller(want: Want, options?: StartOptions)|
|openLink(link: string, options?: OpenLinkOptions, callback?: AsyncCallback&lt;AbilityResult&gt;)|startAbilityByCall(want: Want)|
|startAbilityForResultWithAccount(want: Want, accountId: number, callback: AsyncCallback&lt;AbilityResult&gt;)|startRecentAbility(want: Want, callback: AsyncCallback&lt;void&gt;)|
|startAbilityForResultWithAccount(want: Want, accountId: number, options: StartOptions, callback: AsyncCallback&lt;void&gt;)|startRecentAbility(want: Want, options: StartOptions, callback: AsyncCallback&lt;void&gt;)|
|startAbilityForResultWithAccount(want: Want, accountId: number, options?: StartOptions)|startRecentAbility(want: Want, options?: StartOptions)|
|startAbilityWithAccount(want: Want, accountId: number, callback: AsyncCallback&lt;void&gt;)|startAbilityByCallWithAccount(want: Want, accountId: number)|
|startAbilityWithAccount(want: Want, accountId: number, options: StartOptions, callback: AsyncCallback&lt;void&gt;)|openLink(link:string, options?: OpenLinkOptions)|
|startAbilityWithAccount(want: Want, accountId: number, options?: StartOptions)|
|startRecentAbility(want: Want, callback: AsyncCallback&lt;void&gt;)|
|startRecentAbility(want: Want, options: StartOptions, callback: AsyncCallback&lt;void&gt;)|
|startRecentAbility(want: Want, options?: StartOptions)|
|startAbilityByCallWithAccount(want: Want, accountId: number)|
|startAbilityAsCaller(want: Want, callback: AsyncCallback&lt;void&gt;)|

**Adaptation Guide**

Cancel the calls of the involved APIs on a lock screen. Otherwise, the started application will be closed.
