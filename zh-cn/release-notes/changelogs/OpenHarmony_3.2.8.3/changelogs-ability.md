# 元能力子系统ChangeLog

## cl.ability.1 应用组件启动规则变更

元能力子系统应用组件启动规则在如下场景中存在变更：

 - 应用位于后台启动应用组件
 - 跨应用启动invisible应用组件
 - 跨应用启动FA模型的serviceAbility与dataAbility
 - 使用startAbilityByCall接口

开发者需要根据以下说明对应用进行适配。


**变更影响**

若未适配新规则，在上述场景下将无法启动应用组件
> **注意，启动应用组件是指一切启动或连接Ability的行为：**
<br> 1. 启动Ability，如使用startAbility、startServiceExtensionAbility、startAbilityByCall等接口。
<br> 2. 连接Ability，如使用connectAbility、connectServiceExtensionAbility、acquireDataAbilityHelper、createDataShareHelper等接口。

**关键的接口/组件变更**

 - 涉及的应用组件
   - Stage模型
     - Ability
     - ServiceExtension
     - DataShareExtension
   - FA模型
     - PageAbility
     - ServiceAbility
     - DataAbility 
 - 涉及接口
   - Stage模型
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
   - FA模型
     - startAbility(parameter: StartAbilityParameter, callback: AsyncCallback<number>): void;
     - startAbility(parameter: StartAbilityParameter): Promise<number>;
     - startAbilityForResult(parameter: StartAbilityParameter, callback: AsyncCallback<AbilityResult>): void;
     - startAbilityForResult(parameter: StartAbilityParameter): Promise<AbilityResult>;
     - acquireDataAbilityHelper(uri: string): DataAbilityHelper;
     - connectAbility(request: Want, options:ConnectOptions ): number;

**适配指导**

不同场景下的启动规则说明如下：
 - **应用后台启动应用组件**
   - OpenHarmony 3.2-beta3 版本规则：
      - 应用位于后台时，启动应用组件不受任何限制。
   - OpenHarmony 3.2-beta4 版本新规则：
     - 当应用位于后台时，启动应用组件需鉴权，需申请的权限如下：
      - ```json
        {
            "name": "ohos.permission.START_ABILITIES_FROM_BACKGROUND",
            "grantMode": "system_grant",
            "availableLevel": "system_basic",  
            "provisionEnable": true,
            "distributedSceneEnable": false
        }
        ```
          > **注：**
          <br> 1. 即使启动同应用的组件，也受该规则限制。
          <br> 2. 对于API8以及之前的SDK，启动serviceAbility和dataAbility不受此规则限制。

 - **跨应用启动invisible应用组件**
   - OpenHarmony 3.2-beta3 版本规则：
     - 对于APL为normal的应用，无法跨应用启动invisible的应用组件
   - OpenHarmony 3.2-beta4 版本新规则：
     - 所有应用，若需要跨应用启动invisible的应用组件，需鉴权，需申请的权限如下：
     - ```json
        {
            "name": "ohos.permission.START_INVISIBLE_ABILITY",
            "grantMode": "system_grant",
            "availableLevel": "system_core",
            "provisionEnable": true,
            "distributedSceneEnable": false
        }
        ```

 - **跨应用启动FA模型的serviceAbility与dataAbility**

   - OpenHarmony 3.2-beta3 版本规则：
     - 可任意跨应用启动serviceAbility与dataAbility
   - OpenHarmony 3.2-beta4 版本新规则：
     - serviceAbility与dataAbility的提供方应用需配置关联启动，否则无法被跨应用拉起。（普通应用无法配置关联启动）


 - **startAbilityByCall接口**
   - OpenHarmony 3.2-beta3 版本规则：
     - 可任意进行Call调用
   - OpenHarmony 3.2-beta4 版本新规则：
     - 不支持同应用startAbilityByCall调用
      - 跨应用startAbilityByCall调用需鉴权，需申请的权限如下：

      - ```json
        {
            "name": "ohos.permission.ABILITY_BACKGROUND_COMMUNICATION",
            "grantMode": "system_grant",
            "availableLevel": "system_basic",
            "provisionEnable": true,
            "distributedSceneEnable": false
        }
        ```
        > **注：**
        <br> 使用startAbilityByCall接口同时也受上述后台启动、跨应用启动invisible规则的限制。

## cl.ability.2 跨设备应用组件启动规则变更（仅支持系统应用）

元能力子系统跨设备应用组件启动规则在如下场景中存在变更：

 - 应用位于后台启动应用组件
 - 跨应用启动invisible应用组件
 - 跨应用启动FA模型的serviceAbility

开发者需要根据以下说明对应用进行适配。


**变更影响**

若未适配新规则，在上述场景下将无法启动应用组件
> **注意，启动应用组件是指一切启动或连接Ability的行为：**
<br> 1. 启动Ability，如使用startAbility、startAbilityForResult、startAbilityByCall等接口。
<br> 2. 连接Ability，如使用connectAbility等接口。

**关键的接口/组件变更**

 - 涉及的应用组件
   - Stage模型
     - Ability
     - ServiceExtension
   - FA模型
     - PageAbility
     - ServiceAbility
 - 涉及接口
   - Stage模型
     - startAbility(want: Want, callback: AsyncCallback<void>): void;
     - startAbilityByCall(want: Want): Promise<Caller>;
     - startAbilityForResult(want: Want, callback: AsyncCallback<AbilityResult>): void;
     - connectAbility(want: Want, options: ConnectOptions): number;
   - FA模型
     - startAbility(parameter: StartAbilityParameter, callback: AsyncCallback<number>): void;
     - startAbility(parameter: StartAbilityParameter): Promise<number>;
     - startAbilityForResult(parameter: StartAbilityParameter, callback: AsyncCallback<AbilityResult>): void;
     - startAbilityForResult(parameter: StartAbilityParameter): Promise<AbilityResult>;
     - connectAbility(request: Want, options:ConnectOptions ): number;

**适配指导**

不同场景下的启动规则说明如下：
 - **应用后台启动应用组件**
   - OpenHarmony 3.2-beta3 版本规则：
      - 应用位于后台时，启动应用组件不受任何限制。
   - OpenHarmony 3.2-beta4 版本新规则：
     - 当应用位于后台时，启动应用组件需鉴权，需申请的权限如下：
      - ```json
        {
            "name": "ohos.permission.START_ABILITIES_FROM_BACKGROUND",
            "grantMode": "system_grant",
            "availableLevel": "system_basic",  
            "provisionEnable": true,
            "distributedSceneEnable": false
        }
        ```
          > **注：**
          <br> 1. 即使启动同应用的组件，也受该规则限制。
          <br> 2. 对于API8以及之前的SDK，启动serviceAbility不受此规则限制。

 - **跨应用启动invisible应用组件**
   - OpenHarmony 3.2-beta3 版本规则：
     - 无法跨应用启动invisible的应用组件
   - OpenHarmony 3.2-beta4 版本新规则：
     - 若需要跨应用启动invisible的应用组件，需鉴权，需申请的权限如下：
     - ```json
        {
            "name": "ohos.permission.START_INVISIBLE_ABILITY",
            "grantMode": "system_grant",
            "availableLevel": "system_core",
            "provisionEnable": true,
            "distributedSceneEnable": false
        }
        ```

 - **跨应用启动FA模型的serviceAbility**

   - OpenHarmony 3.2-beta3 版本规则：
     - 可任意跨应用启动serviceAbility
   - OpenHarmony 3.2-beta4 版本新规则：
     - serviceAbility的提供方应用需配置关联启动，否则无法被跨应用拉起。（普通应用无法配置关联启动）
     - 关联启动配置
     - ```json
        {
            "bundleName": "",
            "app_signature": ["xxxxxxxxxxxxxxxxxxx"],
            "associatedWakeUp": true
        }
        ```

## cl.ability.3 API异常处理方式变更

元能力部分接口使用业务逻辑返回值表示错误信息，不符合OpenHarmony接口错误码规范。

**变更影响**

基于此前版本开发的应用，需适配变更接口的错误信息返回方式，否则会影响原有业务逻辑。

**关键接口/组件变更**

为适配统一的API异常处理方式，对元能力相关接口进行废弃（下表中 原接口 列内容，其中的API9接口将被删除，API8及以前的接口将被标注为废弃），并新增对应接口（下表中 新接口 列内容）。新增接口支持统一的错误码异常处理规范，功能上与原接口保持一致。

| 原接口                                          | 新接口                                          |
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

**适配指导**

如上所述，仅将老接口平移到了新的namespace中，所以可以通过修改import来解决适配问题：

如原先接口使用了@ohos.application.missionManager

```js
import missionManager from '@ohos.application.missionManager';
```

可以通过直接修改import，来切换到新的namespace上：

```js
import missionManager from '@ohos.app.ability.missionManager';
```

此外还需要适配异常处理，具体参考新接口的接口文档。

## cl.ability.4 接口变更

对元能力部分接口名进行了变更。

**关键的接口/组件变更**

| 模块名                                    | 类名                    | 方法/属性/枚举/常量                                          | 变更类型 |
| ----------------------------------------- | ----------------------- | ------------------------------------------------------------ | -------- |
| @ohos.application.Ability                 | Caller                  | onRelease(callback: OnReleaseCallBack): **void**;            | 废弃     |
| @ohos.app.ability.UIAbility               | Caller                  | on(**type**: "release", callback: OnReleaseCallBack): **void**; | 新增     |
| @ohos.application.Ability                 | Ability                 | dump(params: Array<**string**>): Array<**string**>;          | 废弃     |
| @ohos.app.ability.UIAbility               | UIAbility               | onDump(params: Array<**string**>): Array<**string**>;        | 新增     |
| @ohos.application.appManager              | appManager              | **function** registerApplicationStateObserver(observer: ApplicationStateObserver): **number**; | 废弃     |
| @ohos.application.appManager              | appManager              | **function** registerApplicationStateObserver(observer: ApplicationStateObserver, bundleNameList: Array<**string**>): **number**; | 废弃     |
| @ohos.application.appManager              | appManager              | **function** unregisterApplicationStateObserver(observerId: **number**, callback: AsyncCallback<**void**>): **void**; | 废弃     |
| @ohos.application.appManager              | appManager              | **function** unregisterApplicationStateObserver(observerId: **number**): Promise<**void**>; | 废弃     |
| @ohos.app.ability.appManager              | appManager              | **function** on(**type**: "applicationState", observer: ApplicationStateObserver): **number**; | 新增     |
| @ohos.app.ability.appManager              | appManager              | **function** on(**type**: "applicationState", observer: ApplicationStateObserver, bundleNameList: Array<**string**>): **number**; | 新增     |
| @ohos.app.ability.appManager              | appManager              | **function** off(**type**: "applicationState", observerId: **number**, callback: AsyncCallback<**void**>): **void**; | 新增     |
| @ohos.app.ability.appManager              | appManager              | **function** off(**type**: "applicationState", observerId: **number**): Promise<**void**>; | 新增     |
| @ohos.application.errorManager            | errorManager            | **function** registerErrorObserver(observer: ErrorObserver): **number**; | 废弃     |
| @ohos.application.errorManager            | errorManager            | **function** unregisterErrorObserver(observerId: **number**, callback: AsyncCallback<**void**>): **void**; | 废弃     |
| @ohos.application.errorManager            | errorManager            | **function** unregisterErrorObserver(observerId: **number**): Promise<**void**>; | 废弃     |
| @ohos.app.ability.errorManager            | errorManager            | **function** on(**type**: "error", observer: ErrorObserver): **number**; | 新增     |
| @ohos.app.ability.errorManager            | errorManager            | **function** off(**type**: "error", observerId: **number**, callback: AsyncCallback<**void**>): **void**; | 新增     |
| @ohos.app.ability.errorManager            | errorManager            | **function** off(**type**: "error", observerId: **number**): Promise<**void**>; | 新增     |
| @ohos.application.missionManager          | missionManager          | **function** registerMissionListener(listener: MissionListener): **number**; | 废弃     |
| @ohos.application.missionManager          | missionManager          | **function** unregisterMissionListener(listenerId: **number**, callback: AsyncCallback<**void**>): **void**; | 废弃     |
| @ohos.application.missionManager          | missionManager          | **function** unregisterMissionListener(listenerId: **number**): Promise<**void**>; | 废弃     |
| @ohos.app.ability.missionManager          | missionManager          | **function** on(**type**: "mission", listener: MissionListener): **number**; | 新增     |
| @ohos.app.ability.missionManager          | missionManager          | **function** off(**type**: "mission", listenerId: **number**, callback: AsyncCallback<**void**>): **void**; | 新增     |
| @ohos.app.ability.missionManager          | missionManager          | **function** off(**type**: "mission", listenerId: **number**): Promise<**void**>; | 新增     |
| @ohos.application.FormExtension           | FormExtension           | onCreate(want: Want): formBindingData.FormBindingData;       | 废弃     |
| @ohos.application.FormExtension           | FormExtension           | onCastToNormal(formId: **string**): **void**;                | 废弃     |
| @ohos.application.FormExtension           | FormExtension           | onUpdate(formId: **string**): **void**;                      | 废弃     |
| @ohos.application.FormExtension           | FormExtension           | onVisibilityChange(newStatus: { [key: **string**]: **number** }): **void**; | 废弃     |
| @ohos.application.FormExtension           | FormExtension           | onEvent(formId: **string**, message: **string**): **void**;  | 废弃     |
| @ohos.application.FormExtension           | FormExtension           | onDestroy(formId: **string**): **void**;                     | 废弃     |
| @ohos.application.FormExtension           | FormExtension           | onShare?(formId: **string**): {[key: **string**]: **any**};  | 废弃     |
| @ohos.app.form.FormExtensionAbility       | FormExtensionAbility    | onAddForm(want: Want): formBindingData.FormBindingData;      | 新增     |
| @ohos.app.form.FormExtensionAbility       | FormExtensionAbility    | onCastToNormalForm(formId: **string**): **void**;            | 新增     |
| @ohos.app.form.FormExtensionAbility       | FormExtensionAbility    | onUpdateForm(formId: **string**): **void**;                  | 新增     |
| @ohos.app.form.FormExtensionAbility       | FormExtensionAbility    | onChangeFormVisibility(newStatus: { [key: **string**]: **number** }): **void**; | 新增     |
| @ohos.app.form.FormExtensionAbility       | FormExtensionAbility    | onFormEvent(formId: **string**, message: **string**): **void**; | 新增     |
| @ohos.app.form.FormExtensionAbility       | FormExtensionAbility    | onRemoveForm(formId: **string**): **void**;                  | 新增     |
| @ohos.app.form.FormExtensionAbility       | FormExtensionAbility    | onShareForm?(formId: **string**): {[key: **string**]: **any**}; | 新增     |
| @ohos.application.formHost.d.ts           | formHost                | **function** castTempForm(formId: **string**, callback: AsyncCallback<**void**>): **void**; | 废弃     |
| @ohos.application.formHost.d.ts           | formHost                | **function** castTempForm(formId: **string**): Promise<**void**>; | 废弃     |
| @ohos.app.form.formHost.d.ts              | formHost                | **function** castToNormalForm(formId: **string**, callback: AsyncCallback<**void**>): **void**; | 新增     |
| @ohos.app.form.formHost.d.ts              | formHost                | **function** castToNormalForm(formId: **string**): Promise<**void**>; | 新增     |
| @ohos.application.ServiceExtensionAbility | ServiceExtensionAbility | dump(params: Array<**string**>): Array<**string**>;          | 废弃     |
| @ohos.app.ability.ServiceExtensionAbility | ServiceExtensionAbility | onDump(params: Array<**string**>): Array<**string**>;        | 新增     |
| application/AbilityContext                | AbilityContext          | connectAbility(want: Want, options: ConnectOptions): **number**; | 废弃     |
| application/AbilityContext                | AbilityContext          | connectAbilityWithAccount(want: Want, accountId: **number**, options: ConnectOptions): **number**; | 废弃     |
| application/AbilityContext                | AbilityContext          | disconnectAbility(connection: **number**, callback: AsyncCallback<**void**>): **void**; | 废弃     |
| application/AbilityContext                | AbilityContext          | disconnectAbility(connection: **number**): Promise<**void**>; | 废弃     |
| application/UIAbilityContext              | UIAbilityContext        | connectServiceExtensionAbilityWithAccount(want: Want, accountId: **number**, options: ConnectOptions): **number**; | 新增     |
| application/UIAbilityContext              | UIAbilityContext        | connectServiceExtensionAbilityWithAccount(want: Want, accountId: **number**, options: ConnectOptions): **number**; | 新增     |
| application/UIAbilityContext              | UIAbilityContext        | disconnectServiceExtensionAbility(connection: **number**, callback: AsyncCallback<**void**>): **void**; | 新增     |
| application/UIAbilityContext              | UIAbilityContext        | disconnectServiceExtensionAbility(connection: **number**): Promise<**void**>; | 新增     |
| application/ApplicationContext            | ApplicationContext      | registerAbilityLifecycleCallback(callback: AbilityLifecycleCallback): **number**; | 废弃     |
| application/ApplicationContext            | ApplicationContext      | unregisterAbilityLifecycleCallback(callbackId: **number**, callback: AsyncCallback<**void**>): **void**; | 废弃     |
| application/ApplicationContext            | ApplicationContext      | unregisterAbilityLifecycleCallback(callbackId: **number**): Promise<**void**>; | 废弃     |
| application/ApplicationContext            | ApplicationContext      | registerEnvironmentCallback(callback: EnvironmentCallback): **number**; | 废弃     |
| application/ApplicationContext            | ApplicationContext      | unregisterEnvironmentCallback(callbackId: **number**, callback: AsyncCallback<**void**>): **void**; | 废弃     |
| application/ApplicationContext            | ApplicationContext      | unregisterEnvironmentCallback(callbackId: **number**): Promise<**void**>; | 废弃     |
| application/ApplicationContext            | ApplicationContext      | on(**type**: "abilityLifecycle", callback: AbilityLifecycleCallback): **number**; | 新增     |
| application/ApplicationContext            | ApplicationContext      | off(**type**: "abilityLifecycle", callbackId: **number**, callback: AsyncCallback<**void**>): **void**; | 新增     |
| application/ApplicationContext            | ApplicationContext      | off(**type**: "abilityLifecycle", callbackId: **number**): Promise<**void**>; | 新增     |
| application/ApplicationContext            | ApplicationContext      | on(**type**: "environment", callback: EnvironmentCallback): **number**; | 新增     |
| application/ApplicationContext            | ApplicationContext      | off(**type**: "environment", callbackId: **number**, callback: AsyncCallback<**void**>): **void**; | 新增     |
| application/ApplicationContext            | ApplicationContext      | off(**type**: "environment", callbackId: **number**): Promise<**void**>; | 新增     |
| application/ServiceExtensionContext       | ServiceExtensionContext | connectAbility(want: Want, options: ConnectOptions): **number**; | 废弃     |
| application/ServiceExtensionContext       | ServiceExtensionContext | connectAbilityWithAccount(want: Want, accountId: **number**, options: ConnectOptions): **number**; | 废弃     |
| application/ServiceExtensionContext       | ServiceExtensionContext | disconnectAbility(connection: **number**, callback: AsyncCallback<**void**>): **void**; | 废弃     |
| application/ServiceExtensionContext       | ServiceExtensionContext | disconnectAbility(connection: **number**): Promise<**void**>; | 废弃     |
| application/ServiceExtensionContext       | ServiceExtensionContext | connectServiceExtensionAbility(want: Want, options: ConnectOptions): **number**; | 新增     |
| application/ServiceExtensionContext       | ServiceExtensionContext | connectServiceExtensionAbilityWithAccount(want: Want, accountId: **number**, options: ConnectOptions): **number**; | 新增     |
| application/ServiceExtensionContext       | ServiceExtensionContext | disconnectServiceExtensionAbility(connection: **number**, callback: AsyncCallback<**void**>): **void**; | 新增     |
| application/ServiceExtensionContext       | ServiceExtensionContext | disconnectServiceExtensionAbility(connection: **number**): Promise<**void**>; | 新增     |

