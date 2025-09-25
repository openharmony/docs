# AutoFillPopupConfig (系统接口)

<!--Kit: Ability Kit-->
<!--Subsystem: Ability-->
<!--Owner: @hanchen45-->
<!--Designer: @ccllee1-->
<!--Tester: @lixueqing513-->
<!--Adviser: @huipeizi-->

自动填充气泡弹窗的尺寸和位置信息。

> **说明：**
> 
> 本模块首批接口从API version 12开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
> 本模块接口均为系统接口。
> 本模块接口仅可在Stage模型下使用。

## 导入模块

```ts
import { autoFillManager } from '@kit.AbilityKit';
```

## AutoFillPopupConfig

**系统接口**：此接口为系统接口。

**系统能力**：SystemCapability.Ability.AbilityRuntime.AbilityCore

| 名称    | 类型           | 只读 | 可选 | 说明                                       |
| --------- | -------------- | ---- | ---- | ------------------------------------------ |
| popupSize | [PopupSize](#popupsize)      | 否   | 是  | 气泡弹窗的宽和高，不设置则不更新。 |
| placement | [PopupPlacement](#popupplacement) | 否   | 是  | 气泡弹窗位置，不设置则不更新。|

## PopupSize

表示气泡弹窗的宽和高。

**系统接口**：此接口为系统接口。

**系统能力**：SystemCapability.Ability.AbilityRuntime.AbilityCore

| 名称 | 类型   | 只读 | 可选 | 说明            |
| ------ | ------ | ---- | ---- | --------------- |
| width  | number | 否   | 否   | 气泡弹窗的宽。 |
| height | number | 否   | 否   | 气泡弹窗的高。 |

## PopupPlacement

表示气泡弹窗位置的枚举。

**系统接口**：此接口为系统接口。

**系统能力**：SystemCapability.Ability.AbilityRuntime.AbilityCore

| 名称         | 值  | 说明                               |
| ------------ | --- | --------------------------------- |
| LEFT         |  0  |气泡弹窗位于组件左侧，与组件左侧中心对齐。 |
| RIGHT        |  1  |气泡弹窗位于组件右侧，与组件右侧中心对齐。 |
| TOP          |  2  |气泡弹窗位于组件上侧，与组件上侧中心对齐。 |
| BOTTOM       |  3  |气泡弹窗位于组件下侧，与组件下侧中心对齐。 |
| TOP_LEFT     |  4  |气泡弹窗位于组件上侧，与组件左侧边缘对齐。 |
| TOP_RIGHT    |  5  |气泡弹窗位于组件上侧，与组件右侧边缘对齐。 |
| BOTTOM_LEFT  |  6  |气泡弹窗位于组件下侧，与组件左侧边缘对齐。 |
| BOTTOM_RIGHT |  7  |气泡弹窗位于组件下侧，与组件右侧边缘对齐。 |
| LEFT_TOP     |  8  |气泡弹窗位于组件左侧，与组件上侧边缘对齐。 |
| LEFT_BOTTOM  |  9  |气泡弹窗位于组件左侧，与组件下侧边缘对齐。 |
| RIGHT_TOP    |  10 |气泡弹窗位于组件右侧，与组件上侧边缘对齐。 |
| RIGHT_BOTTOM |  11 |气泡弹窗位于组件右侧，与组件下侧边缘对齐。 |
| NONE         |  12 |不设置。                                |