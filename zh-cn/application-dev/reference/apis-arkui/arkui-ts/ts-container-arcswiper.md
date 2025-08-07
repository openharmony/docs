# ArcSwiper
<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @Hu_ZeQi-->
<!--SE: @jiangdayuan-->
<!--TSE: @lxl007-->

弧形滑块视图容器，提供子组件滑动轮播显示的能力。 

> **说明：**
>
> 该组件从API version 18开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。

## 导入模块

```ts
import {
  ArcSwiper,
  ArcSwiperAttribute,
  ArcDotIndicator,
  ArcDirection,
  ArcSwiperController
} from '@kit.ArkUI';
```

## 子组件

可以包含子组件。

>  **说明：** 
>
>  - 子组件类型：系统组件和自定义组件，支持渲染控制类型（[if/else](../../../ui/state-management/arkts-rendering-control-ifelse.md)、[ForEach](../../../ui/state-management/arkts-rendering-control-foreach.md)和[LazyForEach](../../../ui/state-management/arkts-rendering-control-lazyforeach.md)）。
>- 不建议在执行翻页动画过程中增加或减少子组件，会导致未进行动画的子组件提前进入视窗，引起显示异常。

## 接口

ArcSwiper(controller?: ArcSwiperController)

创建弧形滑块视图容器。

**原子化服务API：** 从API version 18开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Circle

**参数：** 

| 参数名     | 类型                                        | 必填 | 说明                                     |
| ---------- | ------------------------------------------- | ---- | ---------------------------------------- |
| controller | [ArcSwiperController](#arcswipercontroller) | 否   | 给组件绑定一个控制器，用来控制组件翻页。 |


## 属性

除支持[通用属性](ts-component-general-attributes.md)外，还支持以下属性，不支持[Menu控制](ts-universal-attributes-menu.md)。 

### index

index(index: Optional\<number>)

设置当前在容器中显示的子组件的索引值。设置小于0或大于等于子组件数量时，按照默认值0处理。

**原子化服务API：** 从API version 18开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Circle

**参数：** 

| 参数名 | 类型   | 必填 | 说明                                             |
| ------ | ------ | ---- | ------------------------------------------------ |
| index  | Optional\<number> | 是   | 当前在容器中显示的子组件的索引值。<br/>默认值：0 |

### indicator

indicator(style: Optional\<ArcDotIndicator | boolean>)

设置弧形圆点指示器样式。

**原子化服务API：** 从API version 18开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Circle

**参数：** 

| 参数名 | 类型                                                         | 必填 | 说明                                                         |
| ------ | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| style  | Optional\<[ArcDotIndicator](#arcdotindicator)&nbsp;&nbsp;\|&nbsp;boolean> | 是   | 弧形圆点指示器样式。<br/> \- ArcDotIndicator：弧形圆点指示器属性及功能。<br/> \- boolean：是否启用弧形圆点指示器。设置为true启用，false不启用。<br/> 默认值：true<br/> 默认类型：ArcDotIndicator |

### duration

duration(duration: Optional\<number>)

设置子组件切换的动画时长。

**原子化服务API：** 从API version 18开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Circle

**参数：** 

| 参数名 | 类型   | 必填 | 说明                                                  |
| ------ | ------ | ---- | ----------------------------------------------------- |
| duration  | Optional\<number> | 是   | 子组件切换的动画时长。<br/>默认值：400<br/>单位：毫秒 |

### vertical

vertical(isVertical: Optional\<boolean>)

设置是否为纵向滑动。

**原子化服务API：** 从API version 18开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Circle

**参数：** 

| 参数名 | 类型    | 必填 | 说明                               |
| ------ | ------- | ---- | ---------------------------------- |
| isVertical  | Optional\<boolean> | 是   | 是否为纵向滑动。true为纵向滑动，false为横向滑动。<br/>默认值：false |

### disableSwipe

disableSwipe(disabled: Optional\<boolean>)

设置禁用组件滑动切换功能。

**原子化服务API：** 从API version 18开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Circle

**参数：** 

| 参数名 | 类型    | 必填 | 说明                                     |
| ------ | ------- | ---- | ---------------------------------------- |
| disabled  | Optional\<boolean> | 是   | 禁用组件滑动切换功能。设置为true禁用，false不禁用。<br/>默认值：false |

### digitalCrownSensitivity

digitalCrownSensitivity(sensitivity: Optional\<CrownSensitivity>)

设置旋转表冠的灵敏度。

**原子化服务API：** 从API version 18开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Circle

**参数：** 

| 参数名 | 类型                                                        | 必填 | 说明                                                |
| ------ | ----------------------------------------------------------- | ---- | --------------------------------------------------- |
| sensitivity  | Optional\<[CrownSensitivity](ts-appendix-enums.md#crownsensitivity18)> | 是   | 旋转表冠的灵敏度。<br/>默认值：CrownSensitivity.MEDIUM |

### effectMode

effectMode(edgeEffect: Optional\<EdgeEffect>)

设置边缘滑动效果。 目前支持的滑动效果参见[EdgeEffect](ts-appendix-enums.md#edgeeffect)的枚举说明。调用控制器接口时回弹不生效。

**原子化服务API：** 从API version 18开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Circle

**参数：** 

| 参数名 | 类型                                          | 必填 | 说明                                         |
| ------ | --------------------------------------------- | ---- | -------------------------------------------- |
| edgeEffect  | Optional\<[EdgeEffect](ts-appendix-enums.md#edgeeffect)> | 是   | 边缘滑动效果。<br/>默认值：EdgeEffect.Spring |

### disableTransitionAnimation

disableTransitionAnimation(disabled: Optional\<boolean>)

是否关闭特殊动效效果。

**原子化服务API：** 从API version 18开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Circle

**参数：**

| 参数名   | 类型               | 必填 | 说明                                    |
| -------- | ------------------ | ---- | --------------------------------------- |
| disabled | Optional\<boolean> | 是   | 是否关闭特殊动效效果。<br>默认值：false，不关闭特殊动效效果。 |

## ArcSwiperController

ArcSwiper容器组件的控制器，可以将此对象绑定至ArcSwiper组件，可以通过它控制翻页。

**原子化服务API：** 从API version 18开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Circle

### constructor

constructor()

ArcSwiperController的构造函数。

**原子化服务API：** 从API version 18开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Circle

### showNext

showNext()

翻至下一页。翻页带动效切换过程，时长通过[duration](#duration)指定。

**原子化服务API：** 从API version 18开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Circle

### showPrevious

showPrevious()

翻至上一页。翻页带动效切换过程，时长通过[duration](#duration)指定。

**原子化服务API：** 从API version 18开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Circle

### finishAnimation

finishAnimation(handler?: FinishAnimationHandler)

停止播放动画。

**原子化服务API：** 从API version 18开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Circle

**参数：**

| 参数名  | 类型                                              | 必填 | 说明                                             |
| ------- | ------------------------------------------------- | ---- | ------------------------------------------------ |
| handler | [FinishAnimationHandler](#finishanimationhandler) | 否   | 动画结束的回调。<br>默认值：不传入的情况，无回调 |

## ArcDotIndicator

提供弧形圆点指示器属性及功能。

**原子化服务API：** 从API version 18开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Circle

### constructor

constructor()

ArcDotIndicator的构造函数。

**原子化服务API：** 从API version 18开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Circle

### arcDirection

arcDirection(direction: Optional\<ArcDirection>): ArcDotIndicator

设置弧形指示器的方向。

**原子化服务API：** 从API version 18开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Circle

**参数：** 

| 参数名    | 类型                                     | 必填 | 说明                                                         |
| --------- | ---------------------------------------- | ---- | ------------------------------------------------------------ |
| direction | [Optional\<ArcDirection>](#arcdirection) | 是   | 设置弧形指示器的方向。<br/>默认值：ArcDirection.SIX_CLOCK_DIRECTION，6点钟方向。 |

**返回值：** 

| 类型                                | 说明                           |
| ----------------------------------- | ------------------------------ |
| [ArcDotIndicator](#arcdotindicator) | 提供弧形圆点指示器属性及功能。 |

### itemColor

itemColor(color: Optional\<ResourceColor>): ArcDotIndicator

设置弧形指示器中，未选中导航点的颜色。

**原子化服务API：** 从API version 18开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Circle

**参数：** 

| 参数名 | 类型                                                  | 必填 | 说明                                                         |
| ------ | ----------------------------------------------------- | ---- | ------------------------------------------------------------ |
| color  | [Optional\<ResourceColor>](ts-types.md#resourcecolor) | 是   | 设置弧形指示器中，未选中导航点的颜色。<br/>默认值：'#A9FFFFFF' |

**返回值：** 

| 类型                                | 说明                           |
| ----------------------------------- | ------------------------------ |
| [ArcDotIndicator](#arcdotindicator) | 提供弧形圆点指示器属性及功能。 |

### selectedItemColor

selectedItemColor(color: Optional\<ResourceColor>): ArcDotIndicator

设置弧形指示器中，选中导航点的颜色。

**原子化服务API：** 从API version 18开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Circle

**参数：** 

| 参数名 | 类型                                                  | 必填 | 说明                                                         |
| ------ | ----------------------------------------------------- | ---- | ------------------------------------------------------------ |
| color  | [Optional\<ResourceColor>](ts-types.md#resourcecolor) | 是   | 设置弧形指示器中，选中导航点的颜色。<br/>默认值：'#FF5EA1FF' |

**返回值：** 

| 类型                                | 说明                           |
| ----------------------------------- | ------------------------------ |
| [ArcDotIndicator](#arcdotindicator) | 提供弧形圆点指示器属性及功能。 |

### backgroundColor

backgroundColor(color: Optional\<ResourceColor>): ArcDotIndicator

设置弧形指示器被长按时，弧形指示器的颜色。

**原子化服务API：** 从API version 18开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Circle

**参数：** 

| 参数名 | 类型                                                  | 必填 | 说明                                                         |
| ------ | ----------------------------------------------------- | ---- | ------------------------------------------------------------ |
| color  | [Optional\<ResourceColor>](ts-types.md#resourcecolor) | 是   | 设置弧形指示器被长按时，弧形指示器的颜色。<br/>默认值：'#FF404040' |

**返回值：** 

| 类型                                | 说明                           |
| ----------------------------------- | ------------------------------ |
| [ArcDotIndicator](#arcdotindicator) | 提供弧形圆点指示器属性及功能。 |

### maskColor

maskColor(color: Optional\<LinearGradient>): ArcDotIndicator

设置弧形指示器的遮罩渐变色。

**原子化服务API：** 从API version 18开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Circle

**参数：** 

| 参数名 | 类型                                                         | 必填 | 说明                                                         |
| ------ | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| color  | [Optional\<LinearGradient>](ts-basic-components-datapanel.md#lineargradient10) | 是   | 设置弧形指示器的遮罩渐变色。<br/>起始颜色默认值：'#00000000'<br/>结束颜色默认值：'#FF000000' |

**返回值：** 

| 类型                                | 说明                           |
| ----------------------------------- | ------------------------------ |
| [ArcDotIndicator](#arcdotindicator) | 提供弧形圆点指示器属性及功能。 |

### ArcDirection

弧形方向。

**原子化服务API：** 从API version 18开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Circle

| 名称                  | 值   | 说明        |
| --------------------- | ---- | ----------- |
| THREE_CLOCK_DIRECTION | 0    | 3点钟方向。 |
| SIX_CLOCK_DIRECTION   | 1    | 6点钟方向。 |
| NINE_CLOCK_DIRECTION  | 2    | 9点钟方向。 |

## FinishAnimationHandler

type FinishAnimationHandler = () => void

停止播放动画时，告知应用。

**原子化服务API：** 从API version 18开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Circle

## IndexChangedHandler

type IndexChangedHandler = (index: number) => void

当前显示元素的索引变化时，告知应用。

**原子化服务API：** 从API version 18开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Circle

**参数：** 

| 参数名 | 类型   | 必填 | 说明                                   |
| ------ | ------ | ---- | -------------------------------------- |
| index  | number | 是   | 当前显示元素的索引。index序列从0开始。 |

## AnimationStartHandler

type AnimationStartHandler = (index: number, targetIndex: number, event: SwiperAnimationEvent) => void

切换动画开始时的回调。

**原子化服务API：** 从API version 18开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Circle

**参数：** 

| 参数名      | 类型                                                         | 必填 | 说明                                                         |
| ----------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| index       | number                                                       | 是   | 当前显示元素的索引，动画开始前的index值（不是最终结束动画的index值）。 |
| targetIndex | number                                                       | 是   | 切换动画目标元素的索引。                                     |
| event       | [SwiperAnimationEvent](ts-container-swiper.md#swiperanimationevent10对象说明) | 是   | 动画相关信息，包括主轴方向上当前显示元素和目标元素相对ArcSwiper起始位置的位移，以及离手速度。 |

## AnimationEndHandler

type AnimationEndHandler = (index: number, event: SwiperAnimationEvent) => void

切换动画结束时的回调。

**原子化服务API：** 从API version 18开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Circle

**参数：** 

| 参数名 | 类型                                                         | 必填 | 说明                                                         |
| ------ | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| index  | number                                                       | 是   | 当前显示元素的索引。                                         |
| event  | [SwiperAnimationEvent](ts-container-swiper.md#swiperanimationevent10对象说明) | 是   | 动画相关信息，只返回主轴方向上当前显示元素相对于ArcSwiper起始位置的位移。 |

## GestureSwipeHandler

type GestureSwipeHandler = (index: number, event: SwiperAnimationEvent) => void

在页面跟手滑动过程中，逐帧触发的回调。

**原子化服务API：** 从API version 18开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Circle

**参数：** 

| 参数名 | 类型                                                         | 必填 | 说明                                                         |
| ------ | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| index  | number                                                       | 是   | 当前显示元素的索引。                                         |
| event  | [SwiperAnimationEvent](ts-container-swiper.md#swiperanimationevent10对象说明) | 是   | 动画相关信息，只返回主轴方向上当前显示元素相对于ArcSwiper起始位置的位移。 |

## 事件

除支持[通用事件](ts-component-general-events.md)外，还支持以下事件：

### onChange

onChange(handler: Optional\<IndexChangedHandler>)

当前显示子组件的索引变化时触发该事件，返回值为当前显示子组件的索引值。

ArcSwiper组件结合LazyForEach使用时，不能在onChange事件里触发子页面UI的刷新。

**原子化服务API：** 从API version 18开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Circle

**参数：** 

| 参数名  | 类型                                                   | 必填 | 说明                     |
| ------- | ------------------------------------------------------ | ---- | ------------------------ |
| handler | [Optional\<IndexChangedHandler>](#indexchangedhandler) | 是   | 当前显示元素的索引回调。 |

### onAnimationStart

onAnimationStart(handler: Optional\<AnimationStartHandler>)

切换动画开始时触发该回调。

**原子化服务API：** 从API version 18开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Circle

**参数：** 

| 参数名  | 类型                                                       | 必填 | 说明                   |
| ------- | ---------------------------------------------------------- | ---- | ---------------------- |
| handler | [Optional\<AnimationStartHandler>](#animationstarthandler) | 是   | 切换动画开始时的回调。 |

### onAnimationEnd

onAnimationEnd(handler: Optional\<AnimationEndHandler>)

切换动画结束时触发该回调。

当ArcSwiper切换动效结束时触发，包括动画过程中手势中断，通过SwiperController调用finishAnimation。参数为动画结束后的index值，多列ArcSwiper时，index为最左侧组件的索引。

**原子化服务API：** 从API version 18开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Circle

**参数：** 

| 参数名  | 类型                                                   | 必填 | 说明                       |
| ------- | ------------------------------------------------------ | ---- | -------------------------- |
| handler | [Optional\<AnimationEndHandler>](#animationendhandler) | 是   | 切换动画结束时触发该回调。 |

### onGestureSwipe

onGestureSwipe(handler: Optional\<GestureSwipeHandler>)

在页面跟手滑动过程中，逐帧触发该回调。

**原子化服务API：** 从API version 18开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Circle

**参数：** 

| 参数名  | 类型                                                   | 必填 | 说明                                   |
| ------- | ------------------------------------------------------ | ---- | -------------------------------------- |
| handler | [Optional\<GestureSwipeHandler>](#gestureswipehandler) | 是   | 在页面跟手滑动过程中，逐帧触发该回调。 |

### customContentTransition

customContentTransition(transition: Optional\<SwiperContentAnimatedTransition>)

自定义ArcSwiper页面切换动画。在页面跟手滑动和离手后执行切换动画的过程中，会对视窗内所有页面逐帧触发回调。开发者可以在回调中设置透明度、缩放比例、位移等属性来自定义切换动画。

在页面跟手滑动和离手后执行切换动画的过程中，会对视窗内所有页面逐帧触发[SwiperContentTransitionProxy](#swipercontenttransitionproxy)回调。例如，当视窗内有下标为0、1的两个页面时，会每帧触发两次index值分别为0和1的回调。

**原子化服务API：** 从API version 18开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Circle

**参数：**

| 参数名     | 类型                                                         | 必填 | 说明                              |
| ---------- | ------------------------------------------------------------ | ---- | --------------------------------- |
| transition | Optional\<[SwiperContentAnimatedTransition](#swipercontentanimatedtransition)> | 是   | ArcSwiper自定义切换动画相关信息。 |

## SwiperContentAnimatedTransition

ArcSwiper自定义切换动画相关信息。

**原子化服务API：** 从API version 18开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Circle

| 名称 | 类型 | 只读 | 可选 | 说明 |
| ------ | ---- | ---- | ---- | ---- |
| timeout | number | 否 | 是 | ArcSwiper自定义切换动画超时时间。从页面执行默认动画（页面滑动）至移出视窗外的第一帧开始计时，如果到达该时间后，开发者仍未调用[SwiperContentTransitionProxy](#swipercontenttransitionproxy)的finishTransition接口通知ArcSwiper组件此页面的自定义动画已结束，那么组件就会认为此页面的自定义动画已结束，立即在该页面节点下渲染树。单位ms，默认值为0。 |
| transition | Callback\<[SwiperContentTransitionProxy](#swipercontenttransitionproxy)> | 否 | 否 | 自定义切换动画具体内容。 |

## SwiperContentTransitionProxy

ArcSwiper自定义切换动画执行过程中，返回给开发者的proxy对象。开发者可通过该对象获取自定义动画视窗内的页面信息，同时，也可以通过调用该对象的finishTransition接口通知ArcSwiper组件页面自定义动画已结束。

**原子化服务API：** 从API version 18开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Circle

### **属性**

| 名称 | 类型 | 只读 | 可选 | 说明 |
| ------ | ---- | ---- | ---- | ---- |
| selectedIndex | number | 否 | 否 | 当前选中页面的索引。 |
| index | number | 否 | 否 | 视窗内页面的索引。 |
| position | number | 否 | 否 | index页面相对于ArcSwiper主轴起始位置（selectedIndex对应页面的起始位置）的移动比例。 |
| mainAxisLength | number | 否 | 否 | index对应页面在主轴方向上的长度。 |

>**说明：** 
>
>假设当前选中的子组件的索引为0，从第0页切换到第1页的动画过程中，每帧都会对视窗内所有页面触发回调，当视窗内有第0
>页和第1页两页时，每帧会触发两次回调。其中第一次回调的selectedIndex为0，index为0，position为当前帧第0页相对于动画开
>始前第0页的移动比例，mainAxisLength为主轴方向上第0页的长度；第二次回调的selectedIndex仍为0，index为1，position为当
>前帧第1页相对于动画开始前第0页的移动比例，mainAxisLength为主轴方向上第1页的长度。
>
>若动画曲线为弹簧插值曲线，从第0页切换到第1页的动画过程中，可能会因为离手时的位置和速度，先过滑到第2页，再回弹到
>第1页，该过程中每帧会对视窗内第1页和第2页触发回调。


### finishTransition

finishTransition(): void

通知ArcSwiper组件，此页面的自定义动画已结束。

**原子化服务API：** 从API version 18开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Circle

## 示例

该示例通过设置arcSwiper的基本属性，展示了组件的基本功能。

```ts
// xxx.ets
import {
  CircleShape,
  ArcSwiper,
  ArcSwiperAttribute, // ArcSwiper的属性依赖ArcSwiperAttribute对象导入，不建议删除该对象的引入。
  ArcDotIndicator,
  ArcDirection,
  ArcSwiperController
} from '@kit.ArkUI';

class MyDataSource implements IDataSource {
  private list: Color[] = [];

  constructor(list: Color[]) {
    this.list = list;
  }

  totalCount(): number {
    return this.list.length;
  }

  getData(index: number): Color {
    return this.list[index];
  }

  registerDataChangeListener(listener: DataChangeListener): void {
  }

  unregisterDataChangeListener() {
  }
}

@Entry
@Component
struct TestNewInterface {
  @State itemSimpleColor: Color | number | string = '';
  @State selectedItemSimpleColor: Color | number | string = '';
  private wearableSwiperController: ArcSwiperController = new ArcSwiperController();
  private arcDotIndicator: ArcDotIndicator = new ArcDotIndicator();
  private data: MyDataSource = new MyDataSource([]);
  @State backgroundColors: Color[] =
    [Color.Green, Color.Blue, Color.Yellow, Color.Pink, Color.White, Color.Gray, Color.Orange, Color.Transparent];
  innerSelectedIndex: number = 0;

  aboutToAppear(): void {
    let list: Color[] = [];
    for (let i = 1; i <= 6; i++) {
      list.push(i);
    }
    this.data = new MyDataSource(this.backgroundColors);
  }

  build() {
    Column() {
      Row() {
        ArcSwiper(this.wearableSwiperController) {
          LazyForEach(this.data, (backgroundColor: Color, index: number) => {
            Text(index.toString())
              .width(233)
              .height(233)
              .backgroundColor(backgroundColor)
              .textAlign(TextAlign.Center)
              .fontSize(30)
          })
        }
        .clipShape(new CircleShape({ width: 233, height: 233 }))
        .effectMode(EdgeEffect.None)
        .backgroundColor(Color.Transparent)
        .index(0)
        .duration(400)
        .vertical(false)
        .indicator(this.arcDotIndicator
          .arcDirection(ArcDirection.SIX_CLOCK_DIRECTION)
          .itemColor(this.itemSimpleColor)
          .selectedItemColor(this.selectedItemSimpleColor)
        )
        .disableSwipe(false)
        .digitalCrownSensitivity(CrownSensitivity.MEDIUM)
        .onChange((index: number) => {
          console.info("onChange:" + index.toString());
        })
        .onAnimationStart((index: number, targetIndex: number, extraInfo: SwiperAnimationEvent) => {
          this.innerSelectedIndex = targetIndex;
          console.info("index: " + index);
          console.info("targetIndex: " + targetIndex);
          console.info("current offset: " + extraInfo.currentOffset);
          console.info("target offset: " + extraInfo.targetOffset);
          console.info("velocity: " + extraInfo.velocity);
        })
        .onGestureRecognizerJudgeBegin((event: BaseGestureEvent, current: GestureRecognizer,
          others: Array<GestureRecognizer>): GestureJudgeResult => { // 在识别器即将要成功时，根据当前组件状态，设置识别器使能状态
          if (current) {
            let target = current.getEventTargetInfo();
            if (target && current.isBuiltIn() && current.getType() == GestureControl.GestureType.PAN_GESTURE) {
              // 此处判断swiperTarget.isBegin()或innerSelectedIndex === 0，表明ArcSwiper滑动到开头
              let swiperTarget = target as ScrollableTargetInfo
              if (swiperTarget instanceof ScrollableTargetInfo &&
                (swiperTarget.isBegin() || this.innerSelectedIndex === 0)) {
                let panEvent = event as PanGestureEvent;
                if (panEvent && panEvent.offsetX > 0 && (swiperTarget.isBegin() || this.innerSelectedIndex === 0)) {
                  return GestureJudgeResult.REJECT;
                }
              }
            }
          }
          return GestureJudgeResult.CONTINUE;
        })
        .onAnimationEnd((index: number, extraInfo: SwiperAnimationEvent) => {
          console.info("index: " + index);
          console.info("current offset: " + extraInfo.currentOffset);
        })
        .disableTransitionAnimation(false)
      }.height('100%')
    }.width('100%')
  }
}
```

![arcSwiper](figures/arcSwiper.gif)
