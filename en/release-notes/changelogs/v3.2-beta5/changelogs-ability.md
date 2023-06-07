# Ability Framework Changelog

## cl.ability.1 API Migration
The **requestPermissionsFromUser** API of **UIAbilityContext** is migrated from the ability subsystem to the security subsystem.

Previously, the permission popup was implemented based on **UIAbility**, which used the **startAbilityForResult** API of **UIAbilityContext** to return the permission authorization result to the caller. Therefore, **requestPermissionsFromUser** was temporarily placed in **UIAbilityContext**. The permission popup is now implemented based on **ServiceExtensionAbility**, which no longer requires **startAbilityForResult** of **UIAbilityContext**. Therefore, **requestPermissionsFromUser** is migrated to the security subsystem.

You need to adapt your application based on the following information.

 **Change Impact**

JS APIs in API version 9 are affected. Your application needs to adapt these APIs so that it can properly implement features in the SDK environment of the new version.

**Key API/Component Changes**

| Module                   | Class               | Method/Attribute/Enum/Constant                                         | Change Type|
| ------------------------- | ------------------- | ------------------------------------------------------------ | -------- |
| application/UIAbilityContext        | UIAbilityContext        | requestPermissionsFromUser(permissions: Array<string>, requestCallback: AsyncCallback<PermissionRequestResult>): void; | Deleted    |
| application/UIAbilityContext        | UIAbilityContext        | requestPermissionsFromUser(permissions: Array<string>): Promise<PermissionRequestResult>; | Deleted    |
| @ohos.abilityAccessCtrl        | AtManager         | requestPermissionsFromUser(context: Context, permissions: Array<Permissions>, requestCallback: AsyncCallback<PermissionRequestResult>) : void; | Added    |
| @ohos.abilityAccessCtrl        | AtManager         | requestPermissionsFromUser(context: Context, permissions: Array<Permissions>) : Promise<PermissionRequestResult>; | Added    |


**Adaptation Guide**

The following illustrates how **requestPermissionsFromUser** is called to show a permission popup.

Stage model:

```ts
import abilityAccessCtrl from '@ohos.abilityAccessCtrl.d.ts';
// onWindowStageCreate lifecycle of UIAbility.
onWindowStageCreate() {
    let AtManager = abilityAccessCtrl.createAtManager();
    // requestPermissionsFromUser determines whether to display a popup based on the permission authorization status.
    AtManager.requestPermissionsFromUser(this.context, ["ohos.permission.MANAGE_DISPOSED_APP_STATUS"]).then((data) => {
        console.log("data type:" + typeof(data));
        console.log("data:" + data);
        console.log("data permissions:" + data.permissions);
        console.log("data result:" + data.authResults);
    }).catch((err) => {
        console.error('Failed to start ability', err.code);
    })
}
```



## cl.ability.2 Deletion of Deprecated APIs in API Version 9

In the **Ability Exception Rectification** document, some APIs in API version 9 have been marked as deprecated. According to API specifications of OpenHarmony, these APIs should be deleted.

**Change Impact**

The application developed based on earlier versions needs to use new APIs to replace the deleted ones. Otherwise, the application compilation will be affected.

**Key API/Component Changes**

API files are deleted.

| Deleted API                                     | New API                                         |
| ----------------------------------------------- | ----------------------------------------------- |
| @ohos.application.Ability.d.ts                  | @ohos.app.ability.UIAbility.d.ts                |
| @ohos.application.AbilityConstant.d.ts          | @ohos.app.ability.AbilityConstant.d.ts          |
| @ohos.application.AbilityLifecycleCallback.d.ts | @ohos.app.ability.AbilityLifecycleCallback.d.ts |
| @ohos.application.AbilityStage.d.ts             | @ohos.app.ability.AbilityStage.d.ts             |
| @ohos.application.EnvironmentCallback.d.ts      | @ohos.app.ability.EnvironmentCallback.d.ts      |
| @ohos.application.ExtensionAbility.d.ts         | @ohos.app.ability.ExtensionAbility.d.ts         |
| @ohos.application.FormExtension.d.ts            | @ohos.app.form.FormExtensionAbility.d.ts        |
| @ohos.application.ServiceExtensionAbility.d.ts  | @ohos.app.ability.ServiceExtensionAbility.d.ts  |
| @ohos.application.StartOptions.d.ts             | @ohos.app.ability.StartOptions.d.ts             |
| @ohos.application.context.d.ts                  | @ohos.app.ability.common.d.ts                   |
| @ohos.application.errorManager.d.ts             | @ohos.app.ability.errorManager.d.ts             |

APIs or attributes are deleted:

- @ohos.application.Configuration.d.ts
  - **direction**, **screenDensity**, **displayId**, and **hasPointerDevice** of **Configuration** are deleted. Use **Configuration** of **@ohos.app.ability.Configuration.d.ts**.
- @ohos.application.ConfigurationConstant.d.ts
  - **Direction** and **ScreenDensity** are deleted. Use **Direction** and **ScreenDensity** of **@ohos.app.ability.ConfigurationConstant.d.ts**.
- @ohos.application.abilityManager.d.ts
  - **getExtensionRunningInfos** and **getTopAbility** are deleted. Use the APIs with the same name in **@ohos.app.ability.abilityManager.d.ts**.
- @ohos.application.appManager.d.ts
  - **ApplicationState** and **ProcessState** are deleted. Use **ApplicationState** and **ProcessState** of **@ohos.app.ability.appManager.d.ts**.
  - **registerApplicationStateObserver** and **getProcessRunningInformation** are deleted. Use the APIs with the same name in **@ohos.app.ability.appManager.d.ts**.
- @ohos.application.formHost.d.ts
  - **shareForm** and **notifyFormsPrivacyProtected** are deleted. Use the APIs with the same name in **@ohos.app.form.formHost.d.ts**.
- @ohos.application.formInfo.d.ts
  - **eTS** of **FormType** is deleted. Use **eTS** of **FormType** in **@ohos.app.form.formInfo.d.ts**.
  - **IDENTITY_KEY**, **BUNDLE_NAME_KEY**, **ABILITY_NAME_KEY**, and **DEVICE_ID_KEY** of **FormParam** are deleted. Use the enums with the same name in **@ohos.app.form.formInfo.d.ts**.
  - **FormInfoFilter** is deleted. Use **FormInfoFilter** of **@ohos.app.form.formInfo.d.ts**.
  - **FormDimension** is deleted. Use **FormDimension** of **@ohos.app.form.formInfo.d.ts**.
  - **VisibilityType** is deleted. Use **VisibilityType** of **@ohos.app.form.formInfo.d.ts**.
- @ohos.wantAgent.d.ts
  - **trigger** and **getOperationType** are deleted. Use the APIs with the same name in **@ohos.app.ability.wantAgent.d.ts**.
- application/ApplicationContext.d.ts
  - **registerAbilityLifecycleCallback**, **unregisterAbilityLifecycleCallback**, **registerEnvironmentCallback**, and **unregisterEnvironmentCallback** are deleted. Use **on** and **off**.
- application/ServiceExtensionContext.d.ts
  - **connectAbility**, **connectAbilityWithAccount**, and **disconnectAbility** are deleted. Use **connectServiceExtensionAbility**, **connectServiceExtensionAbilityWithAccount**, and **disconnectServiceExtensionAbility**.
- @ohos.application.FormExtension.d.ts
  - **onCreate**, **onCastToNormal**, **onUpdate**, **onVisibilityChange**, **onEvent**, **onDestroy**, **onAcquireFormState**, and **onShare** are deleted. Use the following lifecycle methods of **@ohos.app.form.FormExtensionAbility.d.ts**: **onAddForm**, **onCastToNormalForm**, **onUpdateForm**, **onChangeFormVisibility**, **onFormEvent**, **onRemoveForm**, **onAcquireFormState**, and **onShareForm**.
- @ohos.application.abilityDelegatorRegistry.d.ts
  - **AbilityDelegator**, **AbilityDelegatorArgs**, **AbilityMonitor**, and **ShellCmdResult** are deleted. Use the classes with the same name in **@ohos.app.ability.abilityDelegatorRegistry.d.ts**.
- @ohos.application.abilityManager.d.ts
  - **AbilityRunningInfo** and **ExtensionRunningInfo** are deleted. Use the classes with the same name in **@ohos.app.ability.abilityManager.d.ts**.
- @ohos.application.appManager.d.ts
  - **AbilityStateData**, **AppStateData**, **ApplicationStateObserver**, **ProcessRunningInfo**, and **ProcessRunningInformation** are deleted. Use the classes with the same name in **@ohos.app.ability.appManager.d.ts**.
- @ohos.application.missionManager.d.ts
  - **MissionInfo**, **MissionListener**, and **MissionSnapshot** are deleted. Use the classes with the same name in **@ohos.app.ability.missionManager.d.ts**.
- @ohos.wantAgent.d.ts
  - **TriggerInfo** and **WantAgentInfo** are deleted. Use the classes with the same name in **@ohos.app.ability.wantAgent.d.ts**.

**Adaptation Guide**

As mentioned above, only several APIs have their names changed in terms of, for example, the registration callbacks (**registerAbilityLifecycleCallback**, **unregisterAbilityLifecycleCallback**, **registerEnvironmentCallback**, and **unregisterEnvironmentCallback**) and connection and disconnection **ServiceExtensionAbility** (**connectAbility**, **connectAbilityWithAccount**, and **disconnectAbility**). For such APIs, replace their names with those of their corresponding new APIs in the lifecycle callbacks.

Most APIs are moved to the new namespace. Therefore, you can modify **import** for adaptation.

For example, the original API uses **@ohos.application.Ability**:

```js
import Ability from '@ohos.application.Ability';
```

You can directly modify **import** to switch to the new namespace:

```js
import Ability from '@ohos.app.ability.UIAbility';
```

In addition, exception handling is needed. For details, see the API reference for the new APIs.

## cl.ability.3 RestartFlag Attribute Names Changed and Unsupported Attribute Deleted in appRecovery

In the **appRecovery** API, the enum names of **RestartFlag** are changed from **NO_RESTART** upon a specific fault to **RESTART** upon a specific fault. 
The **CPP_CRASH_NO_RESTART** enum is deleted.

**Change Impact**

If your application uses the **CPP_CRASH_NO_RESTART**, **JS_CRASH_NO_RESTART**, or **APP_FREEZE_NO_RESTART** attribute in versions earlier than 3.2.10.6, its behavior will change after an upgrade to 3.2.10.6.

**Key API/Component Changes**

**RestartFlag** <sup>9+</sup>

Before change

| Name                 | Value    | Description                            |
| --------------------- | ------ | -------------------------------- |
| ALWAYS_RESTART        | 0      | The application is restarted in all cases.                  |
| CPP_CRASH_NO_RESTART  | 0x0001 | The application is **not restarted** in the case of CPP_CRASH. |
| JS_CRASH_NO_RESTART   | 0x0002 | The application is **not restarted** in the case of JS_CRASH.  |
| APP_FREEZE_NO_RESTART | 0x0004 | The application is **not restarted** in the case of APP_FREEZE.|
| NO_RESTART            | 0xFFFF | The application is not restarted in any case.                |

After change

| Name                   | Value    | Description                          |
| ----------------------- | ------ | ------------------------------ |
| ALWAYS_RESTART          | 0      | The application is restarted in all cases.                |
| CPP_CRASH_NO_RESTART    | NA     | **Deleted.** The restart in this scenario is not supported.|
| RESTART_WHEN_JS_CRASH   | 0x0001 | The application is **restarted** in the case of JS_CRASH.  |
| RESTART_WHEN_APP_FREEZE | 0x0002 | The application is **restarted** in the case of APP_FREEZE.|
| NO_RESTART              | 0xFFFF | The application is not restarted in any case.              |

**Adaptation Guide**

Perform adaptation based on the new semantics.
