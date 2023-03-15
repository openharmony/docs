# Ability Subsystem ChangeLog

## cl.ability.1 Application Component Startup Rule Change

The rules for starting application components of the ability subsystem are changed in the following scenarios:

 - Start application components when the application is in the background.
 - Start invisible application components across applications.
 - Start **serviceAbility** and **dataAbility** of the FA model across applications.
 - Use the **startAbilityByCall** API.

You need to adapt your application based on the following information.

**Change Impacts**

If new rules are not adapted, application components cannot be started in the previous scenarios.
> **NOTE** 
>
> Starting application components refers to any behavior starting or connecting to an ability.
>
> 1. Start an ability using APIs such as **startAbility**, **startServiceExtensionAbility**, and **startAbilityByCall**.
> 2. Connect to an ability using APIs such as **connectAbility**, **connectServiceExtensionAbility**, **acquireDataAbilityHelper**, and **createDataShareHelper**.

**Key API/Component Changes**

 - Involved application components
   - Stage model
     - Ability
     - ServiceExtension
     - DataShareExtension
   - FA model
     - PageAbility
     - ServiceAbility
     - DataAbility 
 - Involved APIs
   - Stage model
     - startAbility(want: Want, callback: AsyncCallback<void>): void;
     - startAbility(want: Want, options: StartOptions, callback: AsyncCallback<void>): void;
     - startAbility(want: Want, options?: StartOptions): Promise<void>;
     - startAbilityByCall(want: Want): Promise<Caller>;
     - startAbilityWithAccount(want: Want, accountId: number, callback: AsyncCallback<void>): void;
     - startAbilityWithAccount(want: Want, accountId: number, options: StartOptions, callback: AsyncCallback<void>): void;
     - startAbilityWithAccount(want: Want, accountId: number, options?: StartOptions): Promise<void>;
     - startAbilityForResult(want: Want, callback: AsyncCallback<AbilityResult>): void;
     - startAbilityForResult(want: Want, options: StartOptions, callback: AsyncCallback<AbilityResult>): void;
     - startAbilityForResult(want: Want, options?: StartOptions): Promise<AbilityResult>;
     - startAbilityForResultWithAccount(want: Want, accountId: number, callback: AsyncCallback<AbilityResult>): void;
     - startAbilityForResultWithAccount(want: Want, accountId: number, options: StartOptions, callback: AsyncCallback<void>): void;
     - startAbilityForResultWithAccount(want: Want, accountId: number, options?: StartOptions): Promise<AbilityResult>;
     - startServiceExtensionAbility(want: Want, callback: AsyncCallback<void>): void;
     - startServiceExtensionAbility(want: Want): Promise<void>;
     - startServiceExtensionAbilityWithAccount(want: Want, accountId: number, callback: AsyncCallback<void>): void;
     - startServiceExtensionAbilityWithAccount(want: Want, accountId: number): Promise<void>;
     - stopServiceExtensionAbility(want: Want, callback: AsyncCallback<void>): void;
     - stopServiceExtensionAbility(want: Want): Promise<void>;
     - stopServiceExtensionAbilityWithAccount(want: Want, accountId: number, callback: AsyncCallback<void>): void;
     - stopServiceExtensionAbilityWithAccount(want: Want, accountId: number): Promise<void>;
     - connectAbility(want: Want, options: ConnectOptions): number;
     - connectAbilityWithAccount(want: Want, accountId: number, options: ConnectOptions): number;
     - createDataShareHelper(context: Context, uri: string, callback: AsyncCallback<DataShareHelper>): void
   - FA model
     - startAbility(parameter: StartAbilityParameter, callback: AsyncCallback<number>): void;
     - startAbility(parameter: StartAbilityParameter): Promise<number>;
     - startAbilityForResult(parameter: StartAbilityParameter, callback: AsyncCallback<AbilityResult>): void;
     - startAbilityForResult(parameter: StartAbilityParameter): Promise<AbilityResult>;
     - acquireDataAbilityHelper(uri: string): DataAbilityHelper;
     - connectAbility(request: Want, options:ConnectOptions ): number;

**Adaptation Guide**

Startup rules for different scenarios are as follows:
 - **Start application components when the application is in the background.**
   - OpenHarmony 3.2 Beta3 rules:
     
      - Starting application components when the application is in the background is not restricted.
   - OpenHarmony 3.2 Beta4 rules:
     - When the application is in the background, starting application components requires authentication. The following permission needs to be applied for:
        ```json
        {
            "name": "ohos.permission.START_ABILITIES_FROM_BACKGROUND",
            "grantMode": "system_grant",
            "availableLevel": "system_basic",  
            "provisionEnable": true,
            "distributedSceneEnable": false
        }
        ```
          > **NOTE**  
          >
          > 1. Starting components of the same application is also restricted by this rule. 
          > 2. For SDKs of API version 8 or earlier, starting **serviceAbility** and **dataAbility** is not restricted by this rule.
   
 - **Start invisible application components across applications.**
   - OpenHarmony 3.2 Beta3 rules:
     
     - For applications whose APL is normal, invisible application components cannot be started across applications.
   - OpenHarmony 3.2 Beta4 rules:
     - For all applications, starting invisible application components across applications requires authentication. The following permission needs to be applied for:
       ```json
        {
            "name": "ohos.permission.START_INVISIBLE_ABILITY",
            "grantMode": "system_grant",
            "availableLevel": "system_core",
            "provisionEnable": true,
            "distributedSceneEnable": false
        }
       ```
   
 - **Start serviceAbility and dataAbility of the FA model across applications.**

   - OpenHarmony 3.2 Beta3 rules:
     - Starting **serviceAbility** and **dataAbility** across applications is not restricted.
   - OpenHarmony 3.2 Beta4 rules:
     - Associated startup needs to be configured for the provider of **serviceAbility** and **dataAbility**. Otherwise, **serviceAbility** and **dataAbility** cannot be started across applications. (Associated startup cannot be configured for common applications.)


 - **Use the startAbilityByCall API.**
   - OpenHarmony 3.2 Beta3 rules:
     
     - The API call is not restricted.
   - OpenHarmony 3.2 Beta4 rules:
     
     - The **startAbilityByCall** API cannot be called by the same application.
   - Calling the **startAbilityByCall** API across applications requires authentication. The following permission needs to be applied for:
   
        ```json
        {
            "name": "ohos.permission.ABILITY_BACKGROUND_COMMUNICATION",
            "grantMode": "system_grant",
            "availableLevel": "system_basic",
            "provisionEnable": true,
            "distributedSceneEnable": false
        }
        ```
        > **NOTE**
        >
        > Using the **startAbilityByCall** API is also restricted by the background startup and across-application invisible component startup rules.

## cl.ability.2 Cross-Device Application Component Startup Rule Change (for System Applications Only)

The rules for starting cross-device application components of the ability subsystem are changed in the following scenarios:

 - Start application components when the application is in the background.
 - Start invisible application components across applications.
 - Start **serviceAbility** of the FA model across applications.

You need to adapt your application based on the following information.


**Change Impacts**

If new rules are not adapted, application components cannot be started in the previous scenarios.
>**NOTE**
>
>Starting application components refers to any behavior starting or connecting to an ability.
>
>1. Start an ability using APIs such as **startAbility**, **startAbilityForResult**, and **startAbilityByCall**.
>2. Connect to an ability using APIs such as **connectAbility**.

**Key API/Component Changes**

 - Involved application components
   - Stage model
     - Ability
     - ServiceExtension
   - FA model
     - PageAbility
     - ServiceAbility
 - Involved APIs
   - Stage model
     - startAbility(want: Want, callback: AsyncCallback<void>): void;
     - startAbilityByCall(want: Want): Promise<Caller>;
     - startAbilityForResult(want: Want, callback: AsyncCallback<AbilityResult>): void;
     - connectAbility(want: Want, options: ConnectOptions): number;
   - FA model
     - startAbility(parameter: StartAbilityParameter, callback: AsyncCallback<number>): void;
     - startAbility(parameter: StartAbilityParameter): Promise<number>;
     - startAbilityForResult(parameter: StartAbilityParameter, callback: AsyncCallback<AbilityResult>): void;
     - startAbilityForResult(parameter: StartAbilityParameter): Promise<AbilityResult>;
     - connectAbility(request: Want, options:ConnectOptions ): number;

**Adaptation Guide**

Startup rules for different scenarios are as follows:
 - **Start application components when the application is in the background.**
   - OpenHarmony 3.2 Beta3 rules:
     
      - Starting application components when the application is in the background is not restricted.
   - OpenHarmony 3.2 Beta4 rules:
     - When the application is in the background, starting application components requires authentication. The following permission needs to be applied for:
        ```json
        {
            "name": "ohos.permission.START_ABILITIES_FROM_BACKGROUND",
            "grantMode": "system_grant",
            "availableLevel": "system_basic",  
            "provisionEnable": true,
            "distributedSceneEnable": false
        }
        ```
          > **NOTE** 
          >
          > 1. Starting components of the same application is also restricted by this rule. 
          > 2. For SDKs of API version 8 or earlier, starting **serviceAbility** is not restricted by this rule.
   
 - **Start invisible application components across applications.**
   - OpenHarmony 3.2 Beta3 rules:
     
     - Invisible application components cannot be started across applications.
   - OpenHarmony 3.2 Beta4 rules:
     - Starting invisible application components across applications requires authentication. The following permission needs to be applied for:
       ```json
        {
            "name": "ohos.permission.START_INVISIBLE_ABILITY",
            "grantMode": "system_grant",
            "availableLevel": "system_core",
            "provisionEnable": true,
            "distributedSceneEnable": false
        }
       ```
   
 - **Start serviceAbility of the FA model across applications.**

   - OpenHarmony 3.2 Beta3 rules:
     
     - Starting **serviceAbility** across applications is not restricted.
   - OpenHarmony 3.2 Beta4 rules:
     - Associated startup needs to be configured for the **serviceAbility** provider application. Otherwise, **serviceAbility** cannot be started across applications. (Associated startup cannot be configured for common applications.)
     - Configure associated startup as follows:
       ```json
        {
            "bundleName": "",
            "app_signature": ["xxxxxxxxxxxxxxxxxxx"],
            "associatedWakeUp": true
        }
       ```

## cl.ability.3 API Exception Handling Method Change

Certain APIs of the ability subsystem use service logic return values to indicate error information, which does not comply with the API error code specifications of OpenHarmony.

**Change Impacts**

The application developed based on earlier versions needs to adapt the new APIs and their method for returning API error information. Otherwise, the original service logic will be affected.

**Key API/Component Changes**

For adaptation to the unified API exception handling mode, certain ability subsystem APIs are deprecated (original APIs in the following table) and corresponding new APIs in the following table are added. (In the following table, original APIs in API version 9 will be deleted, and APIs in API version 8 and earlier will be deprecated.) The newly added APIs support unified error code handling specifications and function the same as the original APIs.

| Original API                                         | New API                                         |
| ----------------------------------------------- | ----------------------------------------------- |
| @ohos.ability.wantConstant.d.ts                 | @ohos.app.ability.wantConstant.d.ts             |
| @ohos.application.Ability.d.ts                  | @ohos.app.ability.UIAbility.d.ts                |
| @ohos.application.AbilityConstant.d.ts          | @ohos.app.ability.AbilityConstant.d.ts          |
| @ohos.application.abilityDelegatorRegistry.d.ts | @ohos.app.ability.abilityDelegatorRegistry.d.ts |
| @ohos.application.AbilityLifecycleCallback.d.ts | @ohos.app.ability.AbilityLifecycleCallback.d.ts |
| @ohos.application.abilityManager.d.ts           | @ohos.app.ability.abilityManager.d.ts           |
| @ohos.application.AbilityStage.d.ts             | @ohos.app.ability.AbilityStage.d.ts             |
| @ohos.application.appManager.d.ts               | @ohos.app.ability.appManager.d.ts               |
| @ohos.application.Configuration.d.ts            | @ohos.app.ability.Configuration.d.ts            |
| @ohos.application.ConfigurationConstant.d.ts    | @ohos.app.ability.ConfigurationConstant.d.ts    |
| @ohos.application.context.d.ts                  | @ohos.app.ability.common.d.ts                   |
| @ohos.application.EnvironmentCallback.d.ts      | @ohos.app.ability.EnvironmentCallback.d.ts      |
| @ohos.application.errorManager.d.ts             | @ohos.app.ability.errorManager.d.ts             |
| @ohos.application.ExtensionAbility.d.ts         | @ohos.app.ability.ExtensionAbility.d.ts         |
| @ohos.application.formBindingData.d.ts          | @ohos.app.form.formBindingData.d.ts             |
| @ohos.application.FormExtension.d.ts            | @ohos.app.form.FormExtensionAbility.d.ts        |
| @ohos.application.formHost.d.ts                 | @ohos.app.form.formHost.d.ts                    |
| @ohos.application.formInfo.d.ts                 | @ohos.app.form.formInfo.d.ts                    |
| @ohos.application.formProvider.d.ts             | @ohos.app.form.formProvider.d.ts                |
| @ohos.application.missionManager.d.ts           | @ohos.app.ability.missionManager.d.ts           |
| @ohos.application.quickFixManager.d.ts          | @ohos.app.ability.quickFixManager.d.ts          |
| @ohos.application.ServiceExtensionAbility.d.ts  | @ohos.app.ability.ServiceExtensionAbility.d.ts  |
| @ohos.application.StartOptions.d.ts             | @ohos.app.ability.StartOptions.d.ts             |
| @ohos.application.Want.d.ts                     | @ohos.app.ability.Want.d.ts                     |
| @ohos.wantAgent.d.ts                            | @ohos.app.ability.wantAgent.d.ts                |

**Adaptation Guide**

The original APIs are only migrated to the new namespace. Therefore, you can modify **import** to solve the adaptation problem.

If the original API uses **@ohos.application.missionManager**:

```js
import missionManager from '@ohos.application.missionManager';
```

You can directly modify **import** to switch to the new namespace:

```js
import missionManager from '@ohos.app.ability.missionManager';
```

In addition, exception handling is needed. For details, see the API reference for the new APIs.

## cl.ability.4 API Change

The names of some ability subsystem APIs are changed.

**Key API/Component Changes**

| Module                                   | Class                   | Method/Attribute/Enumeration/Constant                                         | Change Type|
| ----------------------------------------- | ----------------------- | ------------------------------------------------------------ | -------- |
| @ohos.application.Ability                 | Caller                  | onRelease(callback: OnReleaseCallBack): **void**;            | Deprecated    |
| @ohos.app.ability.UIAbility               | Caller                  | on(**type**: "release", callback: OnReleaseCallBack): **void**; | Added    |
| @ohos.application.Ability                 | Ability                 | dump(params: Array<**string**>): Array<**string**>;          | Deprecated    |
| @ohos.app.ability.UIAbility               | UIAbility               | onDump(params: Array<**string**>): Array<**string**>;        | Added    |
| @ohos.application.appManager              | appManager              | **function** registerApplicationStateObserver(observer: ApplicationStateObserver): **number**; | Deprecated    |
| @ohos.application.appManager              | appManager              | **function** registerApplicationStateObserver(observer: ApplicationStateObserver, bundleNameList: Array<**string**>): **number**; | Deprecated    |
| @ohos.application.appManager              | appManager              | **function** unregisterApplicationStateObserver(observerId: **number**, callback: AsyncCallback<**void**>): **void**; | Deprecated    |
| @ohos.application.appManager              | appManager              | **function** unregisterApplicationStateObserver(observerId: **number**): Promise<**void**>; | Deprecated    |
| @ohos.app.ability.appManager              | appManager              | **function** on(**type**: "applicationState", observer: ApplicationStateObserver): **number**; | Added    |
| @ohos.app.ability.appManager              | appManager              | **function** on(**type**: "applicationState", observer: ApplicationStateObserver, bundleNameList: Array<**string**>): **number**; | Added    |
| @ohos.app.ability.appManager              | appManager              | **function** off(**type**: "applicationState", observerId: **number**, callback: AsyncCallback<**void**>): **void**; | Added    |
| @ohos.app.ability.appManager              | appManager              | **function** off(**type**: "applicationState", observerId: **number**): Promise<**void**>; | Added    |
| @ohos.application.errorManager            | errorManager            | **function** registerErrorObserver(observer: ErrorObserver): **number**; | Deprecated    |
| @ohos.application.errorManager            | errorManager            | **function** unregisterErrorObserver(observerId: **number**, callback: AsyncCallback<**void**>): **void**; | Deprecated    |
| @ohos.application.errorManager            | errorManager            | **function** unregisterErrorObserver(observerId: **number**): Promise<**void**>; | Deprecated    |
| @ohos.app.ability.errorManager            | errorManager            | **function** on(**type**: "error", observer: ErrorObserver): **number**; | Added    |
| @ohos.app.ability.errorManager            | errorManager            | **function** off(**type**: "error", observerId: **number**, callback: AsyncCallback<**void**>): **void**; | Added    |
| @ohos.app.ability.errorManager            | errorManager            | **function** off(**type**: "error", observerId: **number**): Promise<**void**>; | Added    |
| @ohos.application.missionManager          | missionManager          | **function** registerMissionListener(listener: MissionListener): **number**; | Deprecated    |
| @ohos.application.missionManager          | missionManager          | **function** unregisterMissionListener(listenerId: **number**, callback: AsyncCallback<**void**>): **void**; | Deprecated    |
| @ohos.application.missionManager          | missionManager          | **function** unregisterMissionListener(listenerId: **number**): Promise<**void**>; | Deprecated    |
| @ohos.app.ability.missionManager          | missionManager          | **function** on(**type**: "mission", listener: MissionListener): **number**; | Added    |
| @ohos.app.ability.missionManager          | missionManager          | **function** off(**type**: "mission", listenerId: **number**, callback: AsyncCallback<**void**>): **void**; | Added    |
| @ohos.app.ability.missionManager          | missionManager          | **function** off(**type**: "mission", listenerId: **number**): Promise<**void**>; | Added    |
| @ohos.application.FormExtension           | FormExtension           | onCreate(want: Want): formBindingData.FormBindingData;       | Deprecated    |
| @ohos.application.FormExtension           | FormExtension           | onCastToNormal(formId: **string**): **void**;                | Deprecated    |
| @ohos.application.FormExtension           | FormExtension           | onUpdate(formId: **string**): **void**;                      | Deprecated    |
| @ohos.application.FormExtension           | FormExtension           | onVisibilityChange(newStatus: { [key: **string**]: **number** }): **void**; | Deprecated    |
| @ohos.application.FormExtension           | FormExtension           | onEvent(formId: **string**, message: **string**): **void**;  | Deprecated    |
| @ohos.application.FormExtension           | FormExtension           | onDestroy(formId: **string**): **void**;                     | Deprecated    |
| @ohos.application.FormExtension           | FormExtension           | onShare?(formId: **string**): {[key: **string**]: **any**};  | Deprecated    |
| @ohos.app.form.FormExtensionAbility       | FormExtensionAbility    | onAddForm(want: Want): formBindingData.FormBindingData;      | Added    |
| @ohos.app.form.FormExtensionAbility       | FormExtensionAbility    | onCastToNormalForm(formId: **string**): **void**;            | Added    |
| @ohos.app.form.FormExtensionAbility       | FormExtensionAbility    | onUpdateForm(formId: **string**): **void**;                  | Added    |
| @ohos.app.form.FormExtensionAbility       | FormExtensionAbility    | onChangeFormVisibility(newStatus: { [key: **string**]: **number** }): **void**; | Added    |
| @ohos.app.form.FormExtensionAbility       | FormExtensionAbility    | onFormEvent(formId: **string**, message: **string**): **void**; | Added    |
| @ohos.app.form.FormExtensionAbility       | FormExtensionAbility    | onRemoveForm(formId: **string**): **void**;                  | Added    |
| @ohos.app.form.FormExtensionAbility       | FormExtensionAbility    | onShareForm?(formId: **string**): {[key: **string**]: **any**}; | Added    |
| @ohos.application.formHost.d.ts           | formHost                | **function** castTempForm(formId: **string**, callback: AsyncCallback<**void**>): **void**; | Deprecated    |
| @ohos.application.formHost.d.ts           | formHost                | **function** castTempForm(formId: **string**): Promise<**void**>; | Deprecated    |
| @ohos.app.form.formHost.d.ts              | formHost                | **function** castToNormalForm(formId: **string**, callback: AsyncCallback<**void**>): **void**; | Added    |
| @ohos.app.form.formHost.d.ts              | formHost                | **function** castToNormalForm(formId: **string**): Promise<**void**>; | Added    |
| @ohos.application.ServiceExtensionAbility | ServiceExtensionAbility | dump(params: Array<**string**>): Array<**string**>;          | Deprecated    |
| @ohos.app.ability.ServiceExtensionAbility | ServiceExtensionAbility | onDump(params: Array<**string**>): Array<**string**>;        | Added    |
| application/AbilityContext                | AbilityContext          | connectAbility(want: Want, options: ConnectOptions): **number**; | Deprecated    |
| application/AbilityContext                | AbilityContext          | connectAbilityWithAccount(want: Want, accountId: **number**, options: ConnectOptions): **number**; | Deprecated    |
| application/AbilityContext                | AbilityContext          | disconnectAbility(connection: **number**, callback: AsyncCallback<**void**>): **void**; | Deprecated    |
| application/AbilityContext                | AbilityContext          | disconnectAbility(connection: **number**): Promise<**void**>; | Deprecated    |
| application/UIAbilityContext              | UIAbilityContext        | connectServiceExtensionAbilityWithAccount(want: Want, accountId: **number**, options: ConnectOptions): **number**; | Added    |
| application/UIAbilityContext              | UIAbilityContext        | connectServiceExtensionAbilityWithAccount(want: Want, accountId: **number**, options: ConnectOptions): **number**; | Added    |
| application/UIAbilityContext              | UIAbilityContext        | disconnectServiceExtensionAbility(connection: **number**, callback: AsyncCallback<**void**>): **void**; | Added    |
| application/UIAbilityContext              | UIAbilityContext        | disconnectServiceExtensionAbility(connection: **number**): Promise<**void**>; | Added    |
| application/ApplicationContext            | ApplicationContext      | registerAbilityLifecycleCallback(callback: AbilityLifecycleCallback): **number**; | Deprecated    |
| application/ApplicationContext            | ApplicationContext      | unregisterAbilityLifecycleCallback(callbackId: **number**, callback: AsyncCallback<**void**>): **void**; | Deprecated    |
| application/ApplicationContext            | ApplicationContext      | unregisterAbilityLifecycleCallback(callbackId: **number**): Promise<**void**>; | Deprecated    |
| application/ApplicationContext            | ApplicationContext      | registerEnvironmentCallback(callback: EnvironmentCallback): **number**; | Deprecated    |
| application/ApplicationContext            | ApplicationContext      | unregisterEnvironmentCallback(callbackId: **number**, callback: AsyncCallback<**void**>): **void**; | Deprecated    |
| application/ApplicationContext            | ApplicationContext      | unregisterEnvironmentCallback(callbackId: **number**): Promise<**void**>; | Deprecated    |
| application/ApplicationContext            | ApplicationContext      | on(**type**: "abilityLifecycle", callback: AbilityLifecycleCallback): **number**; | Added    |
| application/ApplicationContext            | ApplicationContext      | off(**type**: "abilityLifecycle", callbackId: **number**, callback: AsyncCallback<**void**>): **void**; | Added    |
| application/ApplicationContext            | ApplicationContext      | off(**type**: "abilityLifecycle", callbackId: **number**): Promise<**void**>; | Added    |
| application/ApplicationContext            | ApplicationContext      | on(**type**: "environment", callback: EnvironmentCallback): **number**; | Added    |
| application/ApplicationContext            | ApplicationContext      | off(**type**: "environment", callbackId: **number**, callback: AsyncCallback<**void**>): **void**; | Added    |
| application/ApplicationContext            | ApplicationContext      | off(**type**: "environment", callbackId: **number**): Promise<**void**>; | Added    |
| application/ServiceExtensionContext       | ServiceExtensionContext | connectAbility(want: Want, options: ConnectOptions): **number**; | Deprecated    |
| application/ServiceExtensionContext       | ServiceExtensionContext | connectAbilityWithAccount(want: Want, accountId: **number**, options: ConnectOptions): **number**; | Deprecated    |
| application/ServiceExtensionContext       | ServiceExtensionContext | disconnectAbility(connection: **number**, callback: AsyncCallback<**void**>): **void**; | Deprecated    |
| application/ServiceExtensionContext       | ServiceExtensionContext | disconnectAbility(connection: **number**): Promise<**void**>; | Deprecated    |
| application/ServiceExtensionContext       | ServiceExtensionContext | connectServiceExtensionAbility(want: Want, options: ConnectOptions): **number**; | Added    |
| application/ServiceExtensionContext       | ServiceExtensionContext | connectServiceExtensionAbilityWithAccount(want: Want, accountId: **number**, options: ConnectOptions): **number**; | Added    |
| application/ServiceExtensionContext       | ServiceExtensionContext | disconnectServiceExtensionAbility(connection: **number**, callback: AsyncCallback<**void**>): **void**; | Added    |
| application/ServiceExtensionContext       | ServiceExtensionContext | disconnectServiceExtensionAbility(connection: **number**): Promise<**void**>; | Added    |
