# 元能力子系统JS API变更Changelog

OpenHarmony 3.2.10.1(Mr)版本相较于OpenHarmony 3.2.beta4版本，元能力子系统的API变更如下

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