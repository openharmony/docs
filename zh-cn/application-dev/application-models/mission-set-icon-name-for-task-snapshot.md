# 设置任务快照的图标和名称

设置任务快照的图标和名称是为了提高用户界面的可视化性和用户体验，以便更好地管理和跟踪应用程序中的任务和功能。通过为每个任务快照设置不同的图标和名称，可以更轻松地区分和识别每个任务的功能。

默认情况下任务快照的图标和名称采用的是[module.json5配置文件](../quick-start/module-configuration-file.md)的[abilities标签](../quick-start/module-configuration-file.md#abilities标签)中的icon和label字段，如下图所示。

图1 UIAbility对应的任务快照   
![](figures/mission-list-recent.png)

也可以使用[`UIAbilityContext.setMissionIcon()`](../reference/apis-ability-kit/js-apis-inner-application-uiAbilityContext-sys.md#uiabilitycontextsetmissionicon)和[`UIAbilityContext.setMissionLabel()`](../reference/apis-ability-kit/js-apis-inner-application-uiAbilityContext.md#uiabilitycontextsetmissionlabel)方法，根据需要自定义任务快照的图标和名称。例如，对于UIAbility的多实例启动模式，可以根据不同的功能配置相应的任务快照的图标和名称。

本文将从以下两个方面介绍。

- [设置任务快照的图标（仅对系统应用开放）](#设置任务快照的图标仅对系统应用开放)
- [设置任务快照的名称](#设置任务快照的名称)

## 设置任务快照的图标（仅对系统应用开放）

通过调用[`UIAbilityContext.setMissionIcon()`](../reference/apis-ability-kit/js-apis-inner-application-uiAbilityContext-sys.md#uiabilitycontextsetmissionicon)方法修改任务快照的图标。

示例中的context的获取方式请参见[获取UIAbility的上下文信息](uiability-usage.md#获取uiability的上下文信息)。示例中的`pixelMap`的获取方式请参见[图片解码](../media/image/image-decoding.md)。

```ts
import { common } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { hilog } from '@kit.PerformanceAnalysisKit';

const TAG: string = 'EntryAbility';
const DOMAIN_NUMBER: number = 0xFF00;

// ...
let context: common.UIAbilityContext = this.context; // UIAbilityContext

// ... // 获取pixelMap

// 设置任务快照的图标
context.setMissionIcon(pixelMap, (err: BusinessError) => {
  if (err.code) {
    hilog.error(DOMAIN_NUMBER, TAG, `Failed to set mission icon. Code is ${err.code}, message is ${err.message}`);
  } else {
    hilog.info(DOMAIN_NUMBER, TAG, `Success to set mission icon.`);
  }
})
```

效果示意如下图所示。

图2 设置任务快照的图标   
![](figures/mission-set-task-snapshot-icon.png)

## 设置任务快照的名称

通过调用[`UIAbilityContext.setMissionLabel()`](../reference/apis-ability-kit/js-apis-inner-application-uiAbilityContext.md#uiabilitycontextsetmissionlabel)方法修改任务快照的名称。

```ts
import { common } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { hilog } from '@kit.PerformanceAnalysisKit';

const TAG: string = 'EntryAbility';
const DOMAIN_NUMBER: number = 0xFF00;

// ...
let context: common.UIAbilityContext = this.context; // UIAbilityContext
// 设置任务快照的名称
context.setMissionLabel('test').then(() => {
  hilog.info(DOMAIN_NUMBER, TAG, 'Succeeded in seting mission label.');
}).catch((err: BusinessError) => {
  hilog.error(DOMAIN_NUMBER, TAG, `Failed to set mission label. Code is ${err.code}, message is ${err.message}`);
});
```

效果示意如下图所示。

图3 设置任务快照的名称   
![](figures/mission-set-task-snapshot-label.png)