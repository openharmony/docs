# UIAbility备份恢复

<!--Kit: Ability Kit-->
<!--Subsystem: Ability-->
<!--Owner: @altay; @Luobniz21-->
<!--Designer: @altay-->
<!--Tester: @lixueqing513-->
<!--Adviser: @huipeizi-->

## 场景介绍

当应用后台运行时，可能由于系统资源管控等原因导致应用关闭、进程退出，应用直接退出可能会导致用户数据丢失。如果应用在[UIAbilityContext](../reference/apis-ability-kit/js-apis-inner-application-uiAbilityContext.md)中启用了[UIAbility](../reference/apis-ability-kit/js-apis-app-ability-uiAbility.md)备份恢复功能，并对临时数据进行保存，则可以在应用退出后的下一次启动时恢复先前的状态和数据（包括应用的页面栈以及[onSaveState](../reference/apis-ability-kit/js-apis-app-ability-uiAbility.md#onsavestate)接口中保存的数据），从而保证用户体验的连贯性。

> **说明：**
>
> 应用正常关闭时，不会触发[UIAbility](../reference/apis-ability-kit/js-apis-app-ability-uiAbility.md)备份流程。应用正常启动（例如通过startAbility接口启动或点击图标启动）时，不触发[UIAbility](../reference/apis-ability-kit/js-apis-app-ability-uiAbility.md)恢复流程。

## 运行机制
- [UIAbility](../reference/apis-ability-kit/js-apis-app-ability-uiAbility.md)数据备份：在应用的[onBackground](../reference/apis-ability-kit/js-apis-app-ability-uiAbility.md#onbackground)生命周期后，系统自动调用[onSaveState](../reference/apis-ability-kit/js-apis-app-ability-uiAbility.md#onsavestate)进行备份。
- [UIAbility](../reference/apis-ability-kit/js-apis-app-ability-uiAbility.md)数据恢复：恢复的[Want](../reference/apis-ability-kit/js-apis-app-ability-want.md)数据可以在应用的[onCreate](../reference/apis-ability-kit/js-apis-app-ability-uiAbility.md#oncreate)生命周期中获取，页面栈数据在应用的[onWindowStageCreate](../reference/apis-ability-kit/js-apis-app-ability-uiAbility.md#onwindowstagecreate)生命周期中恢复。

## 约束限制

- [UIAbility](../reference/apis-ability-kit/js-apis-app-ability-uiAbility.md)备份恢复支持多实例，备份数据保存7天，以文件的形式存储在应用的沙箱路径中。

- 备份数据存储在[Want](../reference/apis-ability-kit/js-apis-app-ability-want.md#want)中的parameter字段中，由于序列化大小限制，支持的最大数据量为200KB。

- 重启设备不支持还原备份。

- [UIExtensionAbility](../reference/apis-ability-kit/js-apis-app-ability-uiExtensionAbility.md)不支持备份恢复。

## 接口说明

[UIAbility](../reference/apis-ability-kit/js-apis-app-ability-uiAbility.md)备份恢复接口由[UIAbilityContext](../reference/apis-ability-kit/js-apis-inner-application-uiAbilityContext.md)模块提供，开发者可以通过在[UIAbility](../reference/apis-ability-kit/js-apis-app-ability-uiAbility.md)中通过this.context直接调用，详见[开发步骤](#开发步骤)。

| 接口名称                                                       | 说明                                                 |
| ------------------------------------------------------------ | ---------------------------------------------------- |
| setRestoreEnabled(enabled: boolean): void | 设置当[UIAbility](../reference/apis-ability-kit/js-apis-app-ability-uiAbility.md)从后台切换回前台时是否启用恢复功能。|

[setRestoreEnabled](../reference/apis-ability-kit/js-apis-inner-application-uiAbilityContext.md#setrestoreenabled14)接口需要在应用初始化阶段调用（[onForeground](../reference/apis-ability-kit/js-apis-app-ability-uiAbility.md#onforeground)前），比如[UIAbility](../reference/apis-ability-kit/js-apis-app-ability-uiAbility.md)的[onCreate](../reference/apis-ability-kit/js-apis-app-ability-uiAbility.md#oncreate)调用。


## 开发步骤

开发者需要在应用模块初始化时启用[UIAbility](../reference/apis-ability-kit/js-apis-app-ability-uiAbility.md)的备份恢复功能。

```ts
import { UIAbility } from '@kit.AbilityKit';

export default class EntryAbility extends UIAbility {
    onCreate() {
        console.info('[Demo] EntryAbility onCreate');
        this.context.setRestoreEnabled(true);
    }
}
```

开发者主动保存数据，在UIAbility启动时恢复。

```ts
import { AbilityConstant, UIAbility, Want } from '@kit.AbilityKit';

export default class EntryAbility extends UIAbility {
    onCreate(want: Want, launchParam: AbilityConstant.LaunchParam) {
        console.info('[Demo] EntryAbility onCreate');
        this.context.setRestoreEnabled(true);
        if (want && want.parameters) {
          let recoveryMyData = want.parameters['myData'];
        }
    }

    onSaveState(state:AbilityConstant.StateType, wantParams: Record<string, Object>) {
        // Ability has called to save app data
        console.info('[Demo] EntryAbility onSaveState');
        wantParams['myData'] = 'my1234567';
        return AbilityConstant.OnSaveResult.ALL_AGREE;
    }
}
```