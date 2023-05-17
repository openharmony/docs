# 设置任务快照的图标和名称

设置任务快照的图标和名称是为了提高用户界面的可视化性和用户体验，以便更好地管理和跟踪应用程序中的任务和功能。通过为每个任务快照设置不同的图标和名称，可以更轻松地区分和识别每个任务和功能。

默认情况下任务快照的图标和名称采用的是[module.json5配置文件](../quick-start/module-configuration-file.md)的[abilities标签](../quick-start/module-configuration-file.md#abilities标签)中的icon和label字段，如下图所示。

图1 UIAbility对应的任务快照   
![](figures/mission-list-recent.png)

也可以使用[UIAbilityContext.setMissionIcon()](../reference/apis/js-apis-inner-application-uiAbilityContext.md#uiabilitycontextsetmissionicon)和[UIAbilityContext.setMissionLabel()](../reference/apis/js-apis-inner-application-uiAbilityContext.md#uiabilitycontextsetmissionlabel)方法，根据需要自定义任务快照的图标和名称。例如，对于UIAbility的多实例启动模式，可以根据不同的功能配置相应的任务快照的图标和名称。

本文将从以下两个方面介绍。

- [设置任务快照的图标（仅对系统应用开放）](#设置任务快照的图标（仅对系统应用开放）)
- [设置任务快照的名称](#设置任务快照的名称)

## 设置任务快照的图标（仅对系统应用开放）

通过调用[UIAbilityContext.setMissionIcon()](../reference/apis/js-apis-inner-application-uiAbilityContext.md#uiabilitycontextsetmissionicon)方法修改任务快照的图标。图片内容为[PixelMap](../reference/apis/js-apis-image.md#pixelmap7)类型对象。示例中的context的获取方式请参见[获取UIAbility的上下文信息](uiability-usage.md#获取uiability的上下文信息)。
```ts
let imagePixelMap: PixelMap = undefined; // 需要获取图片PixelMap信息

context.setMissionIcon(imagePixelMap, (err) => {
  if (err.code) {
    console.error(`Failed to set mission icon. Code is ${err.code}, message is ${err.message}`);
  }
})
```

效果示意如下图所示。

图2 设置任务快照的图标   
![](figures/mission-set-task-snapshot-icon.png)

## 设置任务快照的名称

通过调用[UIAbilityContext.setMissionLabel()](../reference/apis/js-apis-inner-application-uiAbilityContext.md#uiabilitycontextsetmissionlabel)方法修改任务快照的名称。

```ts
this.context.setMissionLabel('test').then(() => {
  console.info('Succeeded in seting mission label.');
}).catch((err) => {
  console.error(`Failed to set mission label. Code is ${err.code}, message is ${err.message}`);
});
```

效果示意如下图所示。

图3 设置任务快照的名称   
![](figures/mission-set-task-snapshot-label.png)