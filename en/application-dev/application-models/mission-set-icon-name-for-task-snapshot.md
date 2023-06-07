# Setting the Icon and Name of a Mission Snapshot

Setting a unique icon and name for each mission snapshot of an application helps you better manage the missions and functions of the application.

By default, the **icon** and **label** fields in the [abilities tag](../quick-start/module-configuration-file.md#abilities) of the [module.json5 file](../quick-start/module-configuration-file.md) are used to set the icon and label.

Figure 1 Mission snapshot of a UIAbility
![](figures/mission-list-recent.png)

You can also use [UIAbilityContext.setMissionIcon()](../reference/apis/js-apis-inner-application-uiAbilityContext.md#uiabilitycontextsetmissionicon) and [UIAbilityContext.setMissionLabel()](../reference/apis/js-apis-inner-application-uiAbilityContext.md#uiabilitycontextsetmissionlabel) to customize the icon and name for a mission snapshot. For example, for a UIAbility instance in multiton mode, you can configure the icon and name for each mission snapshot based on different functions.

This document describes the following operations:

- [Setting a Mission Snapshot Icon (for System Applications Only)](#setting-a-mission-snapshot-icon-for-system-applications-only)
- [Setting a Mission Snapshot Name](#setting-a-mission-snapshot-name)

## Setting a Mission Snapshot Icon (for System Applications Only)

Call [UIAbilityContext.setMissionIcon()](../reference/apis/js-apis-inner-application-uiAbilityContext.md#uiabilitycontextsetmissionicon) to set the icon of a mission snapshot. The icon is an object of the [PixelMap](../reference/apis/js-apis-image.md#pixelmap7) type. For details about how to obtain the context, see [Obtaining the Context of UIAbility](uiability-usage.md#obtaining-the-context-of-uiability).
```ts
let imagePixelMap: PixelMap = undefined; // Obtain the PixelMap information.

context.setMissionIcon(imagePixelMap, (err) => {
  if (err.code) {
    console.error(`Failed to set mission icon. Code is ${err.code}, message is ${err.message}`);
  }
})
```

The display effect is shown below.

Figure 2 Mission snapshot icon
![](figures/mission-set-task-snapshot-icon.png)

## Setting a Mission Snapshot Name

Call [UIAbilityContext.setMissionLabel()](../reference/apis/js-apis-inner-application-uiAbilityContext.md#uiabilitycontextsetmissionlabel) to set the name of a mission snapshot.

```ts
this.context.setMissionLabel('test').then(() => {
  console.info('Succeeded in seting mission label.');
}).catch((err) => {
  console.error(`Failed to set mission label. Code is ${err.code}, message is ${err.message}`);
});
```

The display effect is shown below.

Figure 3 Mission snapshot name
![](figures/mission-set-task-snapshot-label.png)
