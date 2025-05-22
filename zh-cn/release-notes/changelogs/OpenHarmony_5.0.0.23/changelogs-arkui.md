# ArkUI子系统Changelog

## cl.arkui.1 bindMenu新增指向性菜单样式

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

## cl.arkui.2 应用可获焦的默认行为变更

**访问级别**

公开接口

**变更原因**

优化默认走焦行为。

**变更影响**

该变更为非兼容性变更。

变更前：有获焦能力但默认不可获焦的组件，需要通过配置属性`.focusable(true)`使得自身可获焦，且走焦时没有默认焦点框，需要配置焦点态样式。

变更后：注册了onClick或者单指单击手势的组件默认可获焦，走焦时无需配置焦点态样式也能显示默认焦点框。

**API Level**

该特性变更起始支持版本为 API 12。

**变更发生版本**

从OpenHarmony SDK 5.0.0.23开始。

**适配指导**

可点击组件不希望参与走焦，需要显示配置`.focusable(false)`；

## cl.arkui.3 Dialog组件弹窗圆角、背景色、背景模糊、宽高限制、响应式/自适应、阴影样式等默认样式变更

**访问级别**

公开接口

**变更原因**

对弹窗视觉风格进行优化，包括圆角、背景色、材质、阴影；对弹窗响应式布局进行优化，在多设备上获得更好的用户体验。

**变更影响**

该变更为非兼容性变更，只影响弹窗的默认样式，自定义样式后以设置为准，自定义设置非法值时，效果等同默认场景。

- 变更前
  1. 弹窗圆角默认四个角均为24vp
  2. 弹窗浅色模式默认背景色为0xd9fffff
  3. 大部分弹窗默认均为背景色为透明（Color.Transparent）和 背景模糊（COMPONENT_ULTRA_THICK）叠加，customDialog和PromptAction中showDialog和openCustomDialog还是使用的默认背景色。
  4. 弹窗默认宽度为栅格系统控制，最大宽度400vp，当设备为2in1时，弹窗固定大小为400vp不可改变，无法自定义设置宽度。
  5. 弹窗默认最大高度为（屏幕高度 - 安全区域）* 0.8， 当设备为2in1时，高度最大为全屏 * 0.67 * 0.9。
  6. 弹窗响应式/自适应场景下，居中样式为避让导航条后的居中；默认场景下弹窗对齐方式是DialogAlignment.Bottom样式，其余设备均为居中样式。
  7. 所有设备都没有默认的阴影样式。

  <br/>
- 变更后
  1. 弹窗圆角默认四个角均为32vp
  2. 弹窗浅色模式默认背景色为0xfffff
  3. 所有弹窗默认均为背景色为透明（Color.Transparent）和 背景模糊（COMPONENT_ULTRA_THICK）叠加
  4. 弹窗默认宽度为所在窗口宽度 - 左右margin，设备上margin为16；当设备为2in1时，左右margin为40。默认最大宽度为400vp，可以随所在窗口大小变化。当自定义设置width接口值时，以自定义设置为准， 弹窗参考宽度为所在窗口的宽度，在此基础上调小或调大；自定义设置非法值时，效果等同默认场景。
  5. 弹窗默认最小高度为70vp，默认最大高度均为（窗口高度 - 安全区域）* 0.9，无设备差异。当自定义设置Height接口值时，以自定义设置为准，弹窗参考高度为（窗口高度 - 安全区域），在此基础上调小或调大；自定义设置非法值时，效果等同默认场景。
  6. 弹窗响应式/自适应场景下，居中样式为全屏居中，所有设备都默认弹窗居中。
  7. 当设备为2in1时，默认场景下获焦阴影值为ShadowStyle.OUTER_FLOATING_MD，失焦为ShadowStyle.OUTER_FLOATING_SM；其余设备没有默认阴影样式。

  如下图所示为变更前后效果对比：

| 变更前 | 变更后 |
|---------|---------|
| ![](figures/Dialog_Default_Radius_And_Margin_Before.png)  |  ![](figures/Dialog_Default_Radius_And_Margin_After.png)  |
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

默认效果变更：默认效果变更，无需适配，但应注意变更后的默认效果是否符合开发者预期，如不符合则应自定义修改效果控制变量以达到预期。

## cl.arkui.4 拖拽预览图支持透明度效果及应用自定义

**访问级别**

公开接口

**变更原因**

依照UX规范

**变更影响**

该变更为非兼容性变更。

API version 11及以前：可拖拽组件长按浮起预览图后没有透明度。

API version 12及以后：可拖拽组件长按浮起预览图默认为95%透明度，应用可自定义透明度数值。

**API Level**

12

**变更发生版本**

从OpenHarmony SDK 5.0.0.23开始。

**适配指导**

默认样式变更调整，无需适配。

## cl.arkui.5 @Observed/@Track/@ObservedV2新增校验变更
**访问级别**

公开接口

**变更原因**

深度观察的装饰器存在新旧两个接口，增加编译校验，防止开发者混用，导致运行时功能异常。

**变更影响**

变更前：不校验报错。

变更后：
如果开发者存在以下场景，不按规范使用，编译会报错。

- 在@ObservedV2修饰的class内使用@Track。

> **说明：**
>
> 因为新的@ObservedV2采用了和@Observed不同的实现逻辑，因此不能在@ObservedV2修饰的class内使用@Track。@Track可以和@Observed一起使用，@Trace可以和@ObservedV2一起使用。

- 一个class同时被@Observed和@ObservedV2装饰。

> **说明：**
>
> 将Observed和@ObservedV2混合使用，会出现未定义行为，表现为冗余刷新、失去深度观测能力、失去自身属性观测能力、失去属性级更新能力等。因此不能将Observed和@ObservedV2混合使用。

- 装饰子类和父类的@Observed和@ObservedV2不一致。

错误示例如下：

```ts
// @Track不能使用在@ObservedV2修饰的class内
@ObservedV2
class TestObserved {
  @Track value: string = "hello"
}
// 一个class不能同时被@Observed和@ObservedV2装饰
@Observed
@ObservedV2
class TestObserved1 {
  value: string = "hello"
}
// 装饰子类和父类的@Observed和@ObservedV2需要保持一致
@Observed
class TestObserved3 {
  @Track value: string = "hello"
}
@ObservedV2
class TestObserved4 extends TestObserved3 {
  @Trace value: string = "hello"
}

@ObservedV2
class TestObserved5 {
  @Trace value: string = "hello"
}
@Observed
class TestObserved6 extends TestObserved5 {
  @Track value: string = "hello"
}
```

**起始API Level**

起始支持版本为 API 12。

**变更发生版本**

从OpenHarmony SDK 5.0.0.23开始。

**适配指导**

开发者需要根据错误提示信息，进行适配整改。

## cl.arkui.6 TextInput、TextArea、Search、RichEditor空间文本菜单样式变更

**访问级别**

公开接口

**变更原因**

规格变更

**变更影响**

该变更为兼容性变更。
API Version 11 以及之前的版本：文本选择菜单，包含分享、搜索、翻译按钮，三个按钮都是灰色，并且有拓展菜单。

API Version 12 变更后：文本选择菜单，不包含分享、搜索、翻译按钮，不出现拓展菜单。

**起始 API Level**

文本菜单是系统能力，无对外接口。

**变更发生版本**

从OpenHarmony SDK 5.0.0.23 版本开始。

**变更的接口/组件**

TextInput、TextArea、Search、RichEditor。

**适配指导**

默认行为变更，无需适配，但应注意变更后的行为是否对整体应用逻辑产生影响。

## cl.arkui.7 ImageSpan、ContainerSpan单独使用在DevEco Studio中报错变更

**访问级别**

公开接口

**变更原因**

规格变更

**变更影响**

该变更为非兼容性变更。
变更前：Text子组件ImageSpan、ContainerSpan放在其他组件下使用，编译无报错。
变更后：DevEco Studio中单独使用ImageSpan、ContainerSpan组件，而不是作为Text的子组件被使用，编译报错。

**起始 API Level**

12

**变更发生版本**

从OpenHarmony SDK 5.0.0.23 版本开始。

**变更的接口/组件**

ImageSpan、ContainerSpan。

**适配指导**

默认行为变更，开发者按照报错提示修改。

## cl.arkui.8 Popup组件宽度设置100%场景下避让位置变更

**访问级别**

公开接口

**变更原因**

UX样式变更

**变更影响**

该变更为非兼容性变更。

变更前，Popup宽度大于等于100% - 6vp时，Popup会进行默认避让，且距离窗口左侧有6vp边距。

变更后，Popup宽度大于等于100% - 6vp时，Popup不会进行默认避让，且距离窗口左侧没有6vp边距。

| 变更前 | 变更后 |
|---------|---------|
| ![变更前](figures/popup_avoid_old.jpg)  |  ![变更后](figures/popup_avoid_new.jpg)  |

**起始API Level**

7

**变更发生版本**

从OpenHarmony SDK 5.0.0.23 版本开始。

**变更的接口/组件**

Popup组件。

**适配指导**

默认效果变更，应注意变更后的默认效果是否符合开发者预期，如不符合可以使用offset属性自行调整Popup位置，请查阅[Popup控制](../../../application-dev/reference/apis-arkui/arkui-ts/ts-universal-attributes-popup.md)文档。

## cl.arkui.9 DatePickerDialog标题按钮大小及布局变更

**访问级别**

公开接口

**变更原因**

UX规格增强

**变更影响**

该变更为非兼容性变更。

变更前：DatePickerDialog标题按钮大小与文本大小一致，底部操作区距离弹窗边缘24vp。

变更后：DatePickerDialog标题按钮高度为32vp，距离弹窗左右边界为16vp，底部操作区与离弹窗边缘无间距。

如下图所示为变更前后效果对比：

| 变更前 | 变更后 |
|---------|---------|
| ![](figures/DatePickerDialogTitle_Before.jpg) | ![](figures/DatePickerDialogTitle_After.jpg) |

**起始API Level**

12

**变更发生版本**

从OpenHarmony SDK 5.0.0.23开始。

**适配指导**

默认行为变更，无需适配，但应注意变更后的行为是否对整体应用逻辑产生影响。

## cl.arkui.10  bindSheet组件修改标题与关闭按钮之间的间距

**访问级别**

公开接口

**变更原因**

为满足应用述求和新的UX规格，标题与关闭按钮的间距调整为8vp。

**变更影响**

该变更为非兼容性变更。

API version 12之前，标题与关闭按钮之间的距离为32vp。

API version 12及以后，标题与关闭按钮之间的距离为8vp。

变更示例图：

![](figures/SheetTitleSpace_compared.png)

**起始API Level**

11

**变更发生版本**

从OpenHarmony SDK 5.0.0.23开始。

**变更的接口/组件**

bindSheet组件

**适配指导**

默认行为变更，无需适配，但应注意变更后的默认效果是否符合开发者预期，如不符合则自定义修改效果控制变量以达到预期。

## c1.arkui.13 bindSheet半模态面板的backgroundColor属性异常值处理逻辑变更

**访问级别**

公开接口

**变更原因**

bindSheet半模态面板的backgroundColor属性设置从正常值更新为异常值时，使用默认值。

**变更影响**

该变更为非兼容性变更。

变更前，当开发者对bindSheet半模态面板的backgroundColor属性设置从正常值更新为异常值时，采用不操作处理。

变更后，当开发者对bindSheet半模态面板的backgroundColor属性设置从正常值更新为异常值时，采用默认颜色处理。

**起始API Level**

11

**变更发生版本**

从OpenHarmony SDK 5.0.0.23 版本开始。

**变更的接口/组件**

bindSheet半模态面板。

**适配指导**

异常值处理逻辑变更，不涉及适配。

默认行为变更，无需适配，但应注意变更后的默认效果是否符合开发者预期，如不符合则自定义修改效果控制变量以达到预期。

## cl.arkui.11 Menu 组件边距 margin 变更

**访问级别**

公开接口

**变更原因**

菜单弹出 UX 默认行为改变

**变更影响**

API12变更之前：菜单带有边距 margin，左右方向为 12vp，上下方向为 24vp。

API12变更之后：如果配置菜单在应用窗口内弹出，左右方向的 margin 为 16vp，上下侧默认规避状态栏与导航条，不额外增加避让距离；如果配置菜单在应用窗口外弹出，左右方向的 margin 为 8vp，上下侧默认规避状态栏与 Dock 区域，不额外增加避让距离。

**起始API Level**

9

**变更发生版本**

从OpenHarmony SDK 5.0.0.23版本开始。

**变更的接口/组件**

Menu 组件

**适配指导**

默认效果变更，无需适配，但应注意变更后的默认效果是否符合开发者预期，如不符合则应自定义修改效果控制变量以达到预期。

## cl.arkui.12  TabContent组件底部页签水平方向排列情景默认字体大小变更

**访问级别**

公开接口

**变更原因**

当前TabContent组件底部页签水平方向排列情景时默认字体大小为10vp，字体偏小，视觉效果较差，变更为12vp，以提升视觉效果。

**变更影响**

该变更为非兼容性变更。

API version 12之前，TabContent组件底部页签水平方向排布情景默认字体大小为10vp。

![TabContent_Before](figures/TabContent_Before.png)

API version 12及以后，TabContent组件底部页签水平方向排布情景默认字体大小为12vp。

![TabContent_After](figures/TabContent_After.png)

**起始API Level**

10

**变更发生版本**

从OpenHarmony SDK 5.0.0.23开始。

**变更的接口/组件**

TabContent组件

**适配指导**

默认行为变更，无需适配，但应注意变更后的默认效果是否符合开发者预期，如不符合可参照[TabContent组件](../../../application-dev/reference/apis-arkui/arkui-ts/ts-container-tabcontent.md)说明文档设置相关属性以达到预期。

## cl.arkui.13 backgroundImage异常参数处理规格变更

**访问级别**

公开接口

**变更原因**

接口异常值处理变更。

**变更影响**

变更前：异常值时不处理。

变更后：异常值时清除背景图，作默认值处理。

**起始API Level**

该特性版本为API 7,变更版本为API 12。

**变更发生版本**

从OpenHarmony SDK 5.0.0.23开始。

**适配指导**

异常值处理逻辑变更，不涉及适配，但应注意变更后的默认效果是否符合开发者预期，如不符合则自定义修改效果控制变量以达到预期。

## cl.arkui.14 backgroundImageSize异常参数处理规格变更

**访问级别**

公开接口

**变更原因**

接口异常值处理变更。

**变更影响**

变更前：异常值时当作宽高为0处理。

变更后：异常值时当作默认值ImageSize.Auto处理。

**起始API Level**

该特性版本为API 7,变更版本为API 12。

**变更发生版本**

从OpenHarmony SDK 5.0.0.23开始。

**适配指导**

异常值处理逻辑变更，不涉及适配，但应注意变更后的默认效果是否符合开发者预期，如不符合则自定义修改效果控制变量以达到预期。

## cl.arkui.15 border中对部分接口新增参数类型

**访问级别**

公开接口

**变更原因**

扩展border成员属性类型，提供镜像能力。

**变更影响**

该变更为不兼容变更。

变更前：borderWidth 参数类型为Length | EdgeWidths；

​                borderColor 参数类型为ResourceColor | EdgeColors；

​                borderRadius 参数类型为 Length | BorderRadiuses；

​                borderOptions同理

变更后：borderWidth 参数类型为Length | EdgeWidths | LocalizedEdgeWidths；

​                borderColor 参数类型为ResourceColor | EdgeColors | LocalizedEdgeColors；

​                borderRadius 参数类型为Length | BorderRadiuses | LocalizedBorderRadiuses；

​                borderOptions同理

**起始API Level**

12

**变更发生版本**

从OpenHarmony SDK 5.0.0.23开始。

**变更的接口/组件**

新增 borderWidth参数LocalizedEdgeWidths，borderColor参数LocalizedEdgeColors，borderRadius参数LocalizedBorderRadiuses以及borderOptions中width、color、radius参数的类型扩充。

**适配指导**

开发者需要根据错误提示信息，进行适配整改。

针对以下场景，会存在类型不兼容报错。

```ts
const item: BorderOptions = { width: "10px",color: 0x000000,radius: 10 }

const value1 : Length | EdgeWidths = item.width

const value2 : ResourceColor | EdgeColors = item.color

const value3 : Length | BorderRadiuses = item.radius
```

需要开发者手动修改代码。

```ts
const item: BorderOptions = { width: "10px",color: 0x000000,radius: 10 }

const value1 : Length | EdgeWidths | LocalizedEdgeWidths | undefined = item.width

const value2 : ResourceColor | EdgeColors | LocalizedEdgeColors | undefined = item.color

const value3 : Length | BorderRadiuses | LocalizedBorderRadiuses | undefined = item.radius
```

