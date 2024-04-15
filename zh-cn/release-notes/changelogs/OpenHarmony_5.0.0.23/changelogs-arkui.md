# ArkUI子系统Changelog

## cl.arkui.1  Image组件按照syncLoad来同步/异步加载PixelMap格式图片

**访问级别**

公开接口

**变更原因**

应用侧的某些实现场景需要Image组件支持异步加载pixelMap。

**变更影响**

该变更为非兼容性变更。

API version 11及以前，Image组件加载PixelMap始终为同步加载。

API version 12及以后，Image组件按照syncLoad来同步/异步加载PixelMap格式图片，若没有设置则按照syncLoad为false进行异步加载。

**API Level**

12

**变更发生版本**

从OpenHarmony SDK 5.0.0.23 版本开始。

**示例：**

无

**变更的接口/组件**

Image组件

**适配指导**

若应用侧需要Image组件同步加载pixelmap，则需要设置syncLoad为true。

## cl.arkui.2 bindMenu新增指向性菜单样式

**访问级别**

公开接口

**变更原因**

UX规格增强

**变更影响**

该变更为非兼容性变更。

变更前：在bindMenu的MenuOptions中将enableArrow属性设为true时，不展示指向性菜单样式。

变更后：在bindMenu的MenuOptions中将enableArrow属性设为true且菜单的大小和位置足以放置箭头时，会展示指向性菜单样式。

**API Level**

enableArrow、arrowOffset属性的起始支持版本为API version 10。

**变更发生版本**

从OpenHarmony SDK 5.0.0.23开始。

**适配指导**

如果不需要bindMenu展示指向性菜单样式，在bindMenu的MenuOptions中不设置enableArrow属性或将enableArrow属性设置为false；
如果需要bindMenu展示指向性菜单样式，在bindMenu的MenuOptions中将enableArrow属性设置为true，并根据需要决定是否设置arrowOffset属性值。

## cl.arkui.3 Dialog组件弹窗圆角、背景色、背景模糊、宽高限制、响应式/自适应、阴影样式等默认样式变更

**访问级别**

公开接口

**变更原因**
UX样式变更

**变更影响**

该变更为非兼容性变更，只影响弹窗的默认样式，自定义样式后以设置为准，自定义设置非法值时，效果等同默认场景。

- 变更前
  1. 弹窗圆角默认四个角均为24vp
  2. 弹窗浅色模式默认背景色为0xd9fffff
  3. 大部分弹窗默认均为背景色为透明（Color.Transparent）和 背景模糊（COMPONENT_ULTRA_THICK）叠加，customDialog和PromptAction中showDialog和openCustomDialog还是使用的默认背景色。
  4. 弹窗默认宽度为栅格系统控制，最大宽度400vp，当设备为2in1时，弹窗固定大小为400vp不可改变，无法自定义设置宽度。
  5. 弹窗默认最大高度为（安全区域高度 - 信号栏&导航栏）* 0.9， 当设备为2in1时，高度最大为全屏 * 0.67 * 0.9。
  6. 弹窗响应式/自适应场景下，居中样式为避让导航条后的居中；默认场景下弹窗对齐方式是DialogAlignment.Bottom样式，其余设备均为居中样式。
  7. 所有设备都没有默认的阴影样式。

  <br/>
- 变更后
  1. 弹窗圆角默认四个角均为32vp
  2. 弹窗浅色模式默认背景色为0xfffff
  3. 所有弹窗默认均为背景色为透明（Color.Transparent）和 背景模糊（COMPONENT_ULTRA_THICK）叠加
  4. 弹窗默认宽度为所在窗口宽度 - 左右margin，设备上margin为16；当设备为2in1时，左右margin为40。默认最大宽度为400vp，可以随所在窗口大小变化。当自定义设置width接口值时，以自定义设置为准；自定义设置非法值时，效果等同默认场景。
  5. 弹窗默认最小高度为70vp，最大高度均为（安全区域高度 - 信号栏&导航栏）* 0.9，无设备差异。当自定义设置Height接口值时，以自定义设置为准，自定义设置非法值时，效果等同默认场景。
  6. 弹窗响应式/自适应场景下，居中样式为全屏居中，所有设备都默认弹窗居中。
  7. 当设备为2in1时，默认场景下获焦阴影值为ShadowStyle.OUTER_FLOATING_MD，失焦为ShadowStyle.OUTER_FLOATING_SM；其余设备没有默认阴影样式。

  如下图所示为变更前后效果对比：
 ![](figures/Dialog_Default_Radius_And_Margin.png) 
 ![](figures/Dialog_Width.png) 
 ![](figures/Dialog_Default_Alignment.png) 
 ![](figures/Dialog_Default_Shadow.png) 

 | 变更前 | 变更后 |
|---------|---------|
|  ![](figures/Dialog_Default_Radius_And_Margin_Before.png)  |  ![](figures/Dialog_Default_Radius_And_Margin_After.png)  |
| ![](figures/Dialog_Width_Before.png) |  ![](figures/Dialog_Width_After.png) |
| ![](figures/Dialog_Default_Alignment_Before.png)  | ![](figures/Dialog_Default_Alignment_After.png) |
| ![](figures/Dialog_Default_Shadow_Before.png)  | ![](figures/Dialog_Default_Shadow_After.png)  |

**API Level**

在API 12进行版本隔离

**变更发生版本**

从OpenHarmony SDK 5.0.0.23 版本开始。

**变更的接口/组件**

Dialog组件。

**适配指导**

UX默认行为变更，无需适配。
