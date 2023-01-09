# ChangeLog of JS API Changes of the Ability Subsystem

Compared with OpenHarmony 3.2 Beta4, OpenHarmony 3.2.10.1(Mr) has the following API changes in the ability subsystem:

## cl.ability.1 API Migration
The **requestPermissionsFromUser** API of **UIAbilityContext** is migrated from the ability subsystem to the security subsystem.

Previously, the permission popup was implemented based on **UIAbility**, which used the **startAbilityForResult** API of **UIAbilityContext** to return the permission authorization result to the caller. Therefore, **requestPermissionsFromUser** was temporarily placed in **UIAbilityContext**. The permission popup is now implemented based on **ServiceExtensionAbility**, which no longer requires **startAbilityForResult** of **UIAbilityContext**. Therefore, **requestPermissionsFromUser** is migrated to the security subsystem.

You need to adapt your applications based on the following information:

**Change Impacts**

JS APIs in API version 9 are affected. The application needs to adapt these APIs so that it can properly implement functions in the SDK environment of the new version.

**Key API/Component Changes**

| Module                      | Class            | Method/Attribute/Enumeration/Constant                                         | Change Type|
| ---------------------------- | ---------------- | ------------------------------------------------------------ | -------- |
| application/UIAbilityContext | UIAbilityContext | requestPermissionsFromUser(permissions: Array<string>, requestCallback: AsyncCallback<PermissionRequestResult>): void; | Deleted    |
| application/UIAbilityContext | UIAbilityContext | requestPermissionsFromUser(permissions: Array<string>): Promise<PermissionRequestResult>; | Deleted    |
| @ohos.abilityAccessCtrl      | AtManager        | requestPermissionsFromUser(context: Context, permissions: Array<Permissions>, requestCallback: AsyncCallback<PermissionRequestResult>) : void; | Added    |
| @ohos.abilityAccessCtrl      | AtManager        | requestPermissionsFromUser(context: Context, permissions: Array<Permissions>) : Promise<PermissionRequestResult>; | Added    |

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

In the [Ability Exception Rectification](../OpenHarmony_3.2.8.3/changelogs-ability.md) document, some APIs in API version 9 have been marked as deprecated. According to API specifications of OpenHarmony, these APIs should be deleted.

**Change Impacts**

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
  - **direction**, **screenDensity**, **displayId**, and **hasPointerDevice** of **Configuration** are deleted. Replace it with **Configuration** of **@ohos.app.ability.Configuration.d.ts**.
- @ohos.application.ConfigurationConstant.d.ts
  - **Direction** and **ScreenDensity** are deleted. Replace them with **Direction** and **ScreenDensity** of **@ohos.app.ability.ConfigurationConstant.d.ts**.
- @ohos.application.abilityManager.d.ts
  - **getExtensionRunningInfos** and **getTopAbility** are deleted. Replace them with synonymous methods of **@ohos.app.ability.abilityManager.d.ts**.
- @ohos.application.appManager.d.ts
  - **ApplicationState** and **ProcessState** are deleted. Replace them with **ApplicationState** and **ProcessState** of **@ohos.app.ability.appManager.d.ts**.
  - **registerApplicationStateObserver** and **getProcessRunningInformation** are deleted. Replace them with synonymous methods of **@ohos.app.ability.appManager.d.ts**.
- @ohos.application.formHost.d.ts
  - **shareForm** and **notifyFormsPrivacyProtected** are deleted. Replace them with synonymous methods of **@ohos.app.form.formHost.d.ts**.
- @ohos.application.formInfo.d.ts
  - **eTS** of **FormType** is deleted. Replace it with **eTS** of **FormType** in **@ohos.app.form.formInfo.d.ts**.
  - **IDENTITY_KEY**, **BUNDLE_NAME_KEY**, **ABILITY_NAME_KEY**, and **DEVICE_ID_KEY** of **FormParam** are deleted. Replace them with synonymous enumerations of **@ohos.app.form.formInfo.d.ts**.
  - **FormInfoFilter** is deleted. Replace it with **FormInfoFilter** of **@ohos.app.form.formInfo.d.ts**.
  - **FormDimension** is deleted. Replace it with **FormDimension** of **@ohos.app.form.formInfo.d.ts**.
  - **VisibilityType** is deleted. Replace it with **VisibilityType** of **@ohos.app.form.formInfo.d.ts**.
- @ohos.wantAgent.d.ts
  - **trigger** and **getOperationType** are deleted. Replace them with synonymous methods of **@ohos.app.ability.wantAgent.d.ts**.
- application/ApplicationContext.d.ts
  - **registerAbilityLifecycleCallback**, **unregisterAbilityLifecycleCallback**, **registerEnvironmentCallback**, and **unregisterEnvironmentCallback** are deleted. Replace them with **on** and **off**.
- application/ServiceExtensionContext.d.ts
  - **connectAbility**, **connectAbilityWithAccount**, and **disconnectAbility** are deleted. Replace them with **connectServiceExtensionAbility**, **connectServiceExtensionAbilityWithAccount**, and **disconnectServiceExtensionAbility**.
- @ohos.application.ExtensionAbility.d.ts
  - **onCreate**, **onCastToNormal**, **onUpdate**, **onVisibilityChange**, **onEvent**, **onDestroy**, **onAcquireFormState**, and **onShare** are deleted. Replace them with the following lifecycle methods of **@ohos.app.form.FormExtensionAbility.d.ts**: **onAddForm**, **onCastToNormalForm**, **onUpdateForm**, **onChangeFormVisibility**, **onFormEvent**, **onRemoveForm**, **onAcquireFormState**, and **onShareForm**.
- @ohos.application.abilityDelegatorRegistry.d.ts
  - **AbilityDelegator**, **AbilityDelegatorArgs**, **AbilityMonitor**, and **ShellCmdResult** are deleted. Replace them with synonymous classes of **@ohos.app.ability.abilityDelegatorRegistry.d.ts**.
- @ohos.application.abilityManager.d.ts
  - **AbilityRunningInfo** and **ExtensionRunningInfo** are deleted. Replace them with synonymous classes of **@ohos.app.ability.abilityManager.d.ts**.
- @ohos.application.appManager.d.ts
  - **AbilityStateData**, **AppStateData**, **ApplicationStateObserver**, **ProcessRunningInfo**, and **ProcessRunningInformation** are deleted. Replace them with synonymous classes of **@ohos.app.ability.appManager.d.ts**.
- @ohos.application.missionManager.d.ts
  - **MissionInfo**, **MissionListener**, and **MissionSnapshot** are deleted. Replace them with synonymous classes of **@ohos.app.ability.missionManager.d.ts**.
- @ohos.wantAgent.d.ts
  - **TriggerInfo** and **WantAgentInfo** are deleted. Replace them with synonymous classes of **@ohos.app.ability.wantAgent.d.ts**.

**Adaptation Guide**

As mentioned above, only several APIs have their names changed in terms of, for example, the registration callbacks (**registerAbilityLifecycleCallback**, **unregisterAbilityLifecycleCallback**, **registerEnvironmentCallback**, and **unregisterEnvironmentCallback**) and connection and disconnection **ServiceExtensionAbility** (**connectAbility**, **connectAbilityWithAccount**, and **disconnectAbility**). For such APIs, replace their names with those of their corresponding new APIs in the lifecycle callbacks.

Most APIs are moved to the new namespace. Therefore, you can modify **import** for adaption.

For example, the original API uses **@ohos.application.Ability**:

```js
import Ability from '@ohos.application.Ability';
```

You can directly modify **import** to switch to the new namespace:

```js
import Ability from '@ohos.app.ability.UIAbility';
```

In addition, exception processing is needed. For details, see the API reference for the new APIs.
