# 元能力子系统JS API变更Changelog

## cl.ability.1 接口迁移
ability子系统UIAbilityContext的接口requestPermissionsFromUser迁移到security子系统：

之前权限弹窗应用是基于UIAbility实现的，需要借助于UIAbilityContext的startAbilityForResult接口把授权结果带回给调用方，故把requestPermissionsFromUser接口暂时放在UIAbilityContext中。现在权限弹窗应用切换为基于ServiceExtensionAbility实现，不再需要借助UIAbilityContext的startAbilityForResult接口，因此把requestPermissionsFromUser接口迁移到security子系统。

开发者需要根据以下说明对应用进行适配。

 **变更影响**

影响API9版本的JS接口，应用需要进行适配才可以在新版本SDK环境正常实现功能。

**关键的接口/组件变更**

| 模块名                    | 类名                | 方法/属性/枚举/常量                                          | 变更类型 |
| ------------------------- | ------------------- | ------------------------------------------------------------ | -------- |
| application/UIAbilityContext        | UIAbilityContext        | requestPermissionsFromUser(permissions: Array<string>, requestCallback: AsyncCallback<PermissionRequestResult>): void; | 删除     |
| application/UIAbilityContext        | UIAbilityContext        | requestPermissionsFromUser(permissions: Array<string>): Promise<PermissionRequestResult>; | 删除     |
| @ohos.abilityAccessCtrl        | AtManager         | requestPermissionsFromUser(context: Context, permissions: Array<Permissions>, requestCallback: AsyncCallback<PermissionRequestResult>) : void; | 新增     |
| @ohos.abilityAccessCtrl        | AtManager         | requestPermissionsFromUser(context: Context, permissions: Array<Permissions>) : Promise<PermissionRequestResult>; | 新增     |


**适配指导**

应用中调用requestPermissionsFromUser拉起权限弹窗应用可参考下列代码

Stage模型下的示例：

```ts
import abilityAccessCtrl from '@ohos.abilityAccessCtrl.d.ts';
//UIAbility的onWindowStageCreate生命周期
onWindowStageCreate() {
    let AtManager = abilityAccessCtrl.createAtManager();
    //requestPermissionsFromUser会判断权限的授权状态来决定是否唤起弹窗
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



## cl.ability.2 删除标记为废弃的API9接口

元能力异常处理整改将部分API9接口标记为了废弃，根据OpenHarmony接口规范，需要删除标记为废弃的API9接口。

**变更影响**

基于此前版本开发的应用，需要将被删除的接口替换为新接口，否则会影响应用编译。

**关键接口/组件变更**

接口文件被删除：

| 被删除接口                                      | 新接口                                          |
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

接口、属性被删除：

- @ohos.application.Configuration.d.ts
  - Configuration 的 direction、screenDensity、displayId、hasPointerDevice 被删除。可以使用 @ohos.app.ability.Configuration.d.ts 的 Configuration替换。
- @ohos.application.ConfigurationConstant.d.ts
  - 枚举 Direction 和 ScreenDensity 被删除。可以使用 @ohos.app.ability.ConfigurationConstant.d.ts 的枚举 Direction 和 ScreenDensity 替换。
- @ohos.application.abilityManager.d.ts
  - 方法 getExtensionRunningInfos 和 getTopAbility 被删除。可以使用 @ohos.app.ability.abilityManager.d.ts 的同名方法替换。
- @ohos.application.appManager.d.ts
  - 枚举 ApplicationState 和 ProcessState 被删除。可以使用 @ohos.app.ability.appManager.d.ts 的枚举 ApplicationState 和 ProcessState 替换。
  - 方法 registerApplicationStateObserver 和 getProcessRunningInformation被删除。可以使用 @ohos.app.ability.appManager.d.ts 的同名方法替换。
- @ohos.application.formHost.d.ts
  - 方法 shareForm 和 notifyFormsPrivacyProtected 被删除。可以使用 @ohos.app.form.formHost.d.ts 的同名方法替换。
- @ohos.application.formInfo.d.ts
  - 枚举 FormType 的 eTS 被删除，可以使用 @ohos.app.form.formInfo.d.ts 的 FormType 中的 eTS 替换。
  - 枚举 FormParam 的 IDENTITY_KEY、BUNDLE_NAME_KEY、ABILITY_NAME_KEY、DEVICE_ID_KEY 被删除，可以使用  @ohos.app.form.formInfo.d.ts 的 FormParam 中的同名枚举替换。
  - 接口 FormInfoFilter 被删除。可以使用 @ohos.app.form.formInfo.d.ts 的 FormInfoFilter 替换。
  - 枚举 FormDimension 被删除。可以使用 @ohos.app.form.formInfo.d.ts 的 FormDimension 替换。
  - 枚举 VisibilityType 被删除。可以使用 @ohos.app.form.formInfo.d.ts 的 VisibilityType 替换。
- @ohos.wantAgent.d.ts
  - 方法 trigger 和 getOperationType 被删除。可以使用 @ohos.app.ability.wantAgent.d.ts 的同名方法替换。
- application/ApplicationContext.d.ts
  - 方法 registerAbilityLifecycleCallback、unregisterAbilityLifecycleCallback、registerEnvironmentCallback、unregisterEnvironmentCallback 被删除。可以使用 on、off 替换。
- application/ServiceExtensionContext.d.ts
  - 方法 connectAbility、connectAbilityWithAccount、disconnectAbility 被删除。可以使用 connectServiceExtensionAbility、connectServiceExtensionAbilityWithAccount、disconnectServiceExtensionAbility 替换。
- @ohos.application.FormExtension.d.ts
  - 生命周期onCreate、onCastToNormal、onUpdate、onVisibilityChange、onEvent、onDestroy、onAcquireFormState、onShare 被删除。可以使用@ohos.app.form.FormExtensionAbility.d.ts的onAddForm、onCastToNormalForm、onUpdateForm、onChangeFormVisibility、onFormEvent、onRemoveForm、onAcquireFormState、onShareForm
- @ohos.application.abilityDelegatorRegistry.d.ts
  - 导出类 AbilityDelegator、AbilityDelegatorArgs、AbilityMonitor、ShellCmdResult 被删除。可以使用@ohos.app.ability.abilityDelegatorRegistry.d.ts中的同名导出类替换。
- @ohos.application.abilityManager.d.ts
  - 导出类 AbilityRunningInfo、ExtensionRunningInfo 被删除。可以使用@ohos.app.ability.abilityManager.d.ts中的同名导出类替换。
- @ohos.application.appManager.d.ts
  - 导出类 AbilityStateData、AppStateData、ApplicationStateObserver、ProcessRunningInfo、ProcessRunningInformation 被删除。可以使用@ohos.app.ability.appManager.d.ts中的同名导出类替换。
- @ohos.application.missionManager.d.ts
  - 导出类 MissionInfo、MissionListener、MissionSnapshot 被删除。可以使用@ohos.app.ability.missionManager.d.ts中的同名导出类替换。
- @ohos.wantAgent.d.ts
  - 导出类 TriggerInfo、WantAgentInfo 被删除。可以使用@ohos.app.ability.wantAgent.d.ts中的同名导出类替换。





**适配指导**

如上所述，仅少数接口修改了接口名的如注册回调函数（registerAbilityLifecycleCallback、unregisterAbilityLifecycleCallback、registerEnvironmentCallback、unregisterEnvironmentCallback）和连接断开 ServiceExtensionAbility（connectAbility、connectAbilityWithAccount、disconnectAbility），卡片生命周期等需要替换成新的接口名。

绝大多数接口平移到了新的namespace中，所以可以通过修改import来解决适配问题：

如原先接口使用了@ohos.application.Ability

```js
import Ability from '@ohos.application.Ability';
```

可以通过直接修改import，来切换到新的namespace上：

```js
import Ability from '@ohos.app.ability.UIAbility';
```

此外还需要适配异常处理，具体参考新接口的接口文档。

## cl.ability.3 appRecovery接口中RestartFlag属性名称变更，删除了未支持的属性

appRecovery接口中RestartFlag枚举命名从特定故障发生后**不重启**改成了特定故障发生后**重启**。  
删除了CPP_CRASH_NO_RESTART。

**变更影响**

3.2.10.6版本之前使用CPP_CRASH_NO_RESTART/JS_CRASH_NO_RESTART/APP_FREEZE_NO_RESTART类型开发的应用，在3.2.10.6版本之后行为会发生变化。

**关键接口/组件变更**

**RestartFlag** <sup>9+</sup>

变更前：

| 名称                  | 值     | 说明                             |
| --------------------- | ------ | -------------------------------- |
| ALWAYS_RESTART        | 0      | 总是重启应用。                   |
| CPP_CRASH_NO_RESTART  | 0x0001 | 发生CPP_CRASH时**不重启**应用。  |
| JS_CRASH_NO_RESTART   | 0x0002 | 发生JS_CRASH时**不重启**应用。   |
| APP_FREEZE_NO_RESTART | 0x0004 | 发生APP_FREEZE时**不重启**应用。 |
| NO_RESTART            | 0xFFFF | 总是不重启应用。                 |

变更后：

| 名称                    | 值     | 说明                           |
| ----------------------- | ------ | ------------------------------ |
| ALWAYS_RESTART          | 0      | 总是重启应用。                 |
| CPP_CRASH_NO_RESTART    | NA     | **删除**，不支持该场景的重启。 |
| RESTART_WHEN_JS_CRASH   | 0x0001 | 发生JS_CRASH时**重启**应用。   |
| RESTART_WHEN_APP_FREEZE | 0x0002 | 发生APP_FREEZE时**重启**应用。 |
| NO_RESTART              | 0xFFFF | 总是不重启应用。               |

**适配指导**

按新的语义进行适配。



