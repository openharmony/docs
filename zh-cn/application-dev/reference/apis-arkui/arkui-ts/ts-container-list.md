# List

列表包含一系列相同宽度的列表项。适合连续、多行呈现同类数据，例如图片和文本。

> **说明：**
>
> - 该组件从API Version 7开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。
>
> - 该组件内容区小于一屏时，默认没有回弹效果。需要回弹效果，可以通过edgeEffect属性的options参数进行设置。
>
> - List组件[通用属性clip](ts-universal-attributes-sharp-clipping.md)的默认值为true。
>
> - 要使List处于可编辑模式需配合onItemDelete事件和ListItem的editable属性，即可编辑模式实现删除列表项功能，需满足以下条件（该功能从API9开始废弃）：
>
>   - editMode属性设置为true。
>
>   - 绑定onItemDelete事件，且事件回调返回true。
>
>   - ListItem的editable属性设置为true。
>
> - 实现ListItem拖拽，需满足以下条件：
>
>   - editMode属性设置为true（从API9开始无需设置editMode属性）。
>
>   - 绑定onDragStart事件，且事件回调中返回浮动UI布局。


## 子组件

仅支持[ListItem](ts-container-listitem.md)、[ListItemGroup](ts-container-listitemgroup.md)子组件，支持渲染控制类型（[if/else](../../../quick-start/arkts-rendering-control-ifelse.md)、[ForEach](../../../quick-start/arkts-rendering-control-foreach.md)、[LazyForEach](../../../quick-start/arkts-rendering-control-lazyforeach.md)和[Repeat](../../../quick-start/arkts-new-rendering-control-repeat.md)）。

> **说明：**
>
> List的子组件的索引值计算规则：
>
> 按子组件的顺序依次递增。
>
> if/else语句中，只有条件成立的分支内的子组件会参与索引值计算，条件不成立的分支内子组件不计算索引值。
>
> ForEach/LazyForEach/Repeat语句中，会计算展开所有子节点索引值。
>
> [if/else](../../../quick-start/arkts-rendering-control-ifelse.md)、[ForEach](../../../quick-start/arkts-rendering-control-foreach.md)、[LazyForEach](../../../quick-start/arkts-rendering-control-lazyforeach.md)和[Repeat](../../../quick-start/arkts-new-rendering-control-repeat.md)发生变化以后，会更新子节点索引值。
>
> ListItemGroup作为一个整体计算一个索引值，ListItemGroup内部的ListItem不计算索引值。
>
> List子组件visibility属性设置为Hidden或None依然会计算索引值。
>
> List子组件的visibility属性设置为None时不显示，但该子组件上下的space还会生效。


## 接口

List(value?:{ initialIndex?: number, space?: number&nbsp;|&nbsp;string, scroller?: Scroller})

**卡片能力：** 从API version 9开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名       | 类型                                    | 必填 | 说明                                                     |
| ------------ | ------------------------------------------- | ---- | ------------------------------------------------------------ |
|    initialIndex    | number                 | 否   | 设置当前List初次加载时显示区域起始位置的item索引值。<br/>默认值：0<br/>**说明：** <br/>设置为负数或超过了当前List最后一个item的索引值时视为无效取值，无效取值按默认值显示。 |
| space  | number&nbsp;\|&nbsp;string                                       | 否   | 子组件主轴方向的间隔。<br/>默认值：0<br/>参数类型为number时单位为vp<br/>**说明：** <br/>设置为负数或者大于等于List内容区长度时，按默认值显示。<br/>space参数值小于List分割线宽度时，子组件主轴方向的间隔取分割线宽度。 |
| scroller     | [Scroller](ts-container-scroll.md#scroller) | 否   | 可滚动组件的控制器。用于与可滚动组件进行绑定。<br/>**说明：** <br/>不允许和其他滚动类组件绑定同一个滚动控制对象。 |

## 属性

除支持[通用属性](ts-universal-attributes-size.md)和[滚动组件通用属性](ts-container-scrollable-common.md#属性)外，还支持以下属性：

### listDirection

listDirection(value: Axis)

设置List组件排列方向。

**卡片能力：** 从API version 9开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名 | 类型                              | 必填 | 说明                                       |
| ------ | --------------------------------- | ---- | ------------------------------------------ |
| value  | [Axis](ts-appendix-enums.md#axis) | 是   | 组件的排列方向。<br/>默认值：Axis.Vertical |

### divider

divider(value: {strokeWidth: Length; color?: ResourceColor; startMargin?: Length; endMargin?: Length;} | null,)

设置ListItem分割线样式，默认无分割线。

endMargin + startMargin 超过列宽度后startMargin和endMargin会置0。

strokeWidth, startMargin和endMargin不支持设置百分比。

List的分割线画在主轴方向两个子组件之间，第一个子组件上方和最后一个子组件下方不会绘制分割线。

多列模式下，ListItem与ListItem之间的分割线起始边距从每一列的交叉轴方向起始边开始计算，其他情况从List交叉轴方向起始边开始计算。

ListItem设置[多态样式](ts-universal-attributes-polymorphic-style.md)时，被按压的子组件上下的分割线不绘制。

**卡片能力：** 从API version 9开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名 | 类型                                                         | 必填 | 说明                                                         |
| ------ | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| value  | {<br/>strokeWidth:&nbsp;[Length](ts-types.md#length),<br/>color?:[ResourceColor](ts-types.md#resourcecolor),<br/>startMargin?:&nbsp;[Length](ts-types.md#length),<br/>endMargin?:&nbsp;[Length](ts-types.md#length)<br/>}&nbsp;\|&nbsp;null | 是   | ListItem分割线样式。<br/>- strokeWidth:&nbsp;分割线的线宽。<br/>- color:&nbsp;分割线的颜色。<br/>默认值：0x08000000<br/>- startMargin:&nbsp;分割线与列表侧边起始端的距离。<br/>默认值：0，单位：vp<br/>- endMargin:&nbsp;分割线与列表侧边结束端的距离。<br/>默认值：0，单位：vp |

### scrollBar

scrollBar(value: BarState)

设置滚动条状态。

**卡片能力：** 从API version 9开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名 | 类型                                      | 必填 | 说明                                                         |
| ------ | ----------------------------------------- | ---- | ------------------------------------------------------------ |
| value  | [BarState](ts-appendix-enums.md#barstate) | 是   | 滚动条状态。<br/>默认值：BarState.Auto<br/>**说明：** <br/>API version 9及以下版本默认值为BarState.Off，API version 10及以上版本的默认值为BarState.Auto。 |

### cachedCount

cachedCount(value: number)

设置列表中ListItem/ListItemGroup的预加载数量，懒加载场景只会预加载List显示区域外cachedCount的内容，非懒加载场景会全部加载。懒加载、非懒加载都只布局List显示区域+List显示区域外cachedCount的内容。<!--Del-->具体使用可参考[减少应用白块说明](../../../performance/arkts-performance-improvement-recommendation.md#减少应用滑动白块)。<!--DelEnd-->

List设置cachedCount后，显示区域外上下各会预加载并布局cachedCount行ListItem。计算ListItem行数时，会计算ListItemGroup内部的ListItem行数。如果ListItemGroup内没有ListItem，则整个ListItemGroup算一行。

List下嵌套使用LazyForEach，并且LazyForEach下嵌套使用ListItemGroup时，LazyForEach会在List显示区域外上下各会创建cachedCount个ListItemGroup。

**卡片能力：** 从API version 9开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名 | 类型   | 必填 | 说明                                               |
| ------ | ------ | ---- | -------------------------------------------------- |
| value  | number | 是   | ListItem/ListItemGroup的预加载数量。<br/>默认值：1 |

### editMode<sup>(deprecated)</sup>

editMode(value: boolean)

设置当前List组件是否处于可编辑模式。可参考[示例3](#示例3)实现删除选中的list项。

从API version9开始废弃不再使用，无替代接口。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名 | 类型   | 必填 | 说明                                               |
| ------ | ------ | ---- | -------------------------------------------------- |
| value  | boolean | 是   | 当前List组件是否处于可编辑模式。<br/>默认值：false |

### edgeEffect

edgeEffect(value: EdgeEffect, options?: EdgeEffectOptions)

设置边缘滑动效果。

**卡片能力：** 从API version 9开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名                | 类型                                                         | 必填 | 说明                                                         |
| --------------------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| value                 | [EdgeEffect](ts-appendix-enums.md#edgeeffect)                | 是   | List组件的边缘滑动效果，支持弹簧效果和阴影效果。<br/>默认值：EdgeEffect.Spring |
| options<sup>11+</sup> | [EdgeEffectOptions](ts-container-scrollable-common.md#edgeeffectoptions11对象说明) | 否   | 组件内容大小小于组件自身时，是否开启滑动效果。设置为{ alwaysEnabled: true }会开启滑动效果，{ alwaysEnabled: false }不开启。<br/>默认值：{ alwaysEnabled: false } |

### chainAnimation

chainAnimation(value: boolean)

设置当前List是否启用链式联动动效，开启后列表滑动以及顶部和底部拖拽时会有链式联动的效果。

链式联动效果：List内的ListItem间隔一定距离，该距离可以通过List组件space参数设置，默认为20vp。在手指划动过程中，手指拖动的ListItem是主动对象，相邻的ListItem为从动对象，主动对象驱动从动对象联动，驱动效果遵循弹簧物理动效。

链式动效生效后，List的分割线不显示。

链式动效生效需要满足以下前提条件：

 1、List边缘效果为Spring类型。

 2、List没有启用多列模式。

**卡片能力：** 从API version 9开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名 | 类型    | 必填 | 说明                                                         |
| ------ | ------- | ---- | ------------------------------------------------------------ |
| value  | boolean | 是   | 是否启用链式联动动效。<br/>默认值：false，不启用链式联动。true，启用链式联动。 |

### multiSelectable<sup>8+</sup>

multiSelectable(value: boolean)

设置是否开启鼠标框选。

**卡片能力：** 从API version 9开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名 | 类型    | 必填 | 说明                                                         |
| ------ | ------- | ---- | ------------------------------------------------------------ |
| value  | boolean | 是   | 是否开启鼠标框选。<br/>默认值：false，关闭框选。true，开启框选。 |

### lanes<sup>9+</sup>

lanes(value: number | LengthConstrain, gutter?: Dimension)

设置List组件的布局列数或行数。gutter为列间距，当列数大于1时生效。

规则如下：

- lanes为指定的数量时，根据指定的数量与List组件的交叉轴尺寸除以列数作为列的宽度。
- lanes设置了{minLength，maxLength}时，根据List组件的宽度自适应决定lanes数量（即列数），保证缩放过程中lane的宽度符合{minLength，maxLength}的限制。其中，minLength条件会被优先满足，即优先保证符合ListItem的交叉轴尺寸符合最小限制。
- lanes设置了{minLength，maxLength}，如果父组件交叉轴方向尺寸约束为无穷大时，固定按一列排列，列宽度按显示区域内最大的ListItem计算。
- &nbsp;ListItemGroup在多列模式下也是独占一行，ListItemGroup中的ListItem按照List组件的lanes属性设置值来布局。
- lanes设置了{minLength，maxLength}时，计算列数会按照ListItemGroup的交叉轴尺寸计算。当ListItemGroup交叉轴尺寸与List交叉轴尺寸不一致时ListItemGroup中的列数与List中的列数可能不一样。

**卡片能力：** 从API version 9开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名               | 类型                                                         | 必填 | 说明                                     |
| -------------------- | ------------------------------------------------------------ | ---- | ---------------------------------------- |
| value                | number&nbsp;\|&nbsp;[LengthConstrain](ts-types.md#lengthconstrain) | 是   | List组件的布局列数或行数。<br/>默认值：1 |
| gutter<sup>10+</sup> | [Dimension](ts-types.md#dimension10)                         | 否   | 列间距。<br />默认值：0                  |

### alignListItem<sup>9+</sup>

alignListItem(value: ListItemAlign)

设置List交叉轴方向宽度大于ListItem交叉轴宽度 * lanes时，ListItem在List交叉轴方向的布局方式。

**卡片能力：** 从API version 9开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名 | 类型                                     | 必填 | 说明                                                   |
| ------ | ---------------------------------------- | ---- | ------------------------------------------------------ |
| value  | [ListItemAlign](#listitemalign9枚举说明) | 是   | 交叉轴方向的布局方式。<br/>默认值：ListItemAlign.Start |

### sticky<sup>9+</sup>

sticky(value: StickyStyle)

配合[ListItemGroup](ts-container-listitemgroup.md)组件使用，设置ListItemGroup中header和footer是否要吸顶或吸底。sticky属性可以设置为 StickyStyle.Header \| StickyStyle.Footer 以同时支持header吸顶和footer吸底。

**卡片能力：** 从API version 9开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名 | 类型                                 | 必填 | 说明                                                       |
| ------ | ------------------------------------ | ---- | ---------------------------------------------------------- |
| value  | [StickyStyle](#stickystyle9枚举说明) | 是   | ListItemGroup吸顶或吸底效果。<br/>默认值：StickyStyle.None |

### scrollSnapAlign<sup>10+</sup>

scrollSnapAlign(value: ScrollSnapAlign)

设置列表项滚动结束对齐效果。

只支持ListItem等高情况下，设置列表项滚动结束对齐效果。

触控板和鼠标滑动List结束后不支持对齐效果。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名 | 类型                                          | 必填 | 说明                                                      |
| ------ | --------------------------------------------- | ---- | --------------------------------------------------------- |
| value  | [ScrollSnapAlign](#scrollsnapalign10枚举说明) | 是   | 列表项滚动结束对齐效果。<br/>默认值：ScrollSnapAlign.NONE |

### enableScrollInteraction<sup>10+</sup>

enableScrollInteraction(value: boolean)

设置是否支持滚动手势，当设置为false时，无法通过手指或者鼠标滚动，但不影响控制器的滚动接口。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名 | 类型    | 必填 | 说明                                |
| ------ | ------- | ---- | ----------------------------------- |
| value  | boolean | 是   | 是否支持滚动手势。<br/>默认值：true |

### nestedScroll<sup>10+</sup>

nestedScroll(value: NestedScrollOptions)

设置向前向后两个方向上的嵌套滚动模式，实现与父组件的滚动联动。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名 | 类型                                                         | 必填 | 说明           |
| ------ | ------------------------------------------------------------ | ---- | -------------- |
| value  | [NestedScrollOptions](ts-container-scrollable-common.md#nestedscrolloptions10对象说明) | 是   | 嵌套滚动选项。 |

### friction<sup>10+</sup>

friction(value: number | Resource)

设置摩擦系数，手动划动滚动区域时生效，只对惯性滚动过程有影响，对惯性滚动过程中的链式效果有间接影响。设置为小于等于0的值时，按默认值处理。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名 | 类型                                                 | 必填 | 说明                                                         |
| ------ | ---------------------------------------------------- | ---- | ------------------------------------------------------------ |
| value  | number&nbsp;\|&nbsp;[Resource](ts-types.md#resource) | 是   | 摩擦系数。<br/>默认值：非可穿戴设备为0.6，可穿戴设备为0.9。<br/>从API version 11开始，非可穿戴设备默认值为0.7。<br/>从API version 12开始，非可穿戴设备默认值为0.75。 |

### contentStartOffset<sup>11+</sup>

contentStartOffset(value: number)

设置内容区域起始偏移量。列表滚动到起始位置时，列表内容与列表显示区域边界保留指定距离。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名 | 类型   | 必填 | 说明                                            |
| ------ | ------ | ---- | ----------------------------------------------- |
| value  | number | 是   | 内容区域起始偏移量。<br/>默认值：0<br/>单位：vp |

### contentEndOffset<sup>11+</sup>

contentEndOffset(value: number)

设置内容区末尾偏移量。列表滚动到末尾位置时，列表内容与列表显示区域边界保留指定距离。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名 | 类型   | 必填 | 说明                                          |
| ------ | ------ | ---- | --------------------------------------------- |
| value  | number | 是   | 内容区末尾偏移量。<br/>默认值：0<br/>单位：vp |

### childrenMainSize<sup>12+</sup>

childrenMainSize(value: ChildrenMainSize)

设置List组件的子组件在主轴方向的大小信息。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名     | 类型   | 必填 | 说明                            |
| ---------- | ------ | ---- | ------------------------------- |
| value | [ChildrenMainSize](ts-container-scrollable-common.md#childrenmainsize12对象说明) | 是   | 1. 作用：<br/>通过ChildrenMainSize对象向List组件准确提供所有子组件在主轴方向的大小信息，能够使List组件在子组件的主轴大小不一致、增删子组件、使用[scrollToIndex](ts-container-scroll.md#scrolltoindex)等场景也能维护自己准确的滑动位置，进而使[scrollTo](ts-container-scroll.md#scrollto)能跳转到准确的指定位置，[currentOffset](ts-container-scroll.md#currentoffset)能够获取到当前准确的滑动位置，内置滚动条能够平滑移动无跳变。<br/>2.使用约束：<br/>（1）提供的主轴方向大小必须与子组件实际在主轴方向的大小一致，子组件在主轴方向大小变化或者增删子组件时都必须通过ChildrenMainSize对象方法通知List组件。<br/>（2）当子组件是ListItemGroup时，需要根据ListItemGroup的列数，ListItemGroup中ListItem在主轴方向的间距，ListItemGroup中header,footer,ListItem的大小准确计算出ListItemGroup整体在主轴方向的大小，并提供给List组件。<br/>（3）如果子组件有ListItemGroup，必须给每一个ListItemGroup也设置childrenMainSize属性，List组件和每一个ListItemGroup组件都要通过childrenMainSize属性接口一对一绑定着一个ChildrenMainSize对象。<br/>（4）多列场景使用LazyForEach生成子组件时，需确保LazyForEach全部生成ListItemGroup组件或者全部生成ListItem组件。

### maintainVisibleContentPosition<sup>12+</sup>

maintainVisibleContentPosition(enabled: boolean)

设置显示区域上方插入或删除数据时是否要保持可见内容位置不变。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名 | 类型    | 必填 | 说明                                                         |
| ------ | ------- | ---- | ------------------------------------------------------------ |
| enabled  | boolean | 是   | 设置显示区域上方插入或删除数据时是否要保持可见内容位置不变。<br/>默认值：false，显示区域上方插入或删除数据时可见内容位置会跟随变化。 true：显示区域上方插入或删除数据时可见内容位置不变。|

> **说明：** 
> - 只有使用LazyForEach在显示区域外插入或删除数据时，才能保持可见内容位置不变。使用ForEach插入或删除数据或使用LazyForEach重新加载数据时，即使maintainVisibleContentPosition属性设置为true，可见区内容位置也会跟随变化。
> - maintainVisibleContentPosition属性设置为true后，在显示区域上方插入或删除数据，会触发onDidScroll、onScrollIndex事件。
> - maintainVisibleContentPosition属性设置为true后，在多列场景下，一次插入或删除整行数据，可以保持可见内容位置不变，如果不是插入或删除整行数据，可见内容位置还是会发生变化。

## ListItemAlign<sup>9+</sup>枚举说明

**卡片能力：** 从API version 9开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称     |  值  | 说明                      |
| ------ | ------ | ------------------------- |
| Start  | 0 | ListItem在List中，交叉轴方向首部对齐。 |
| Center | 1 | ListItem在List中，交叉轴方向居中对齐。 |
| End    | 2 | ListItem在List中，交叉轴方向尾部对齐。 |

## StickyStyle<sup>9+</sup>枚举说明

**卡片能力：** 从API version 9开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称     |  值  | 说明                               |
| ------ | ------ | ---------------------------------- |
| None   | 0 | ListItemGroup的header不吸顶，footer不吸底。 |
| Header | 1 | ListItemGroup的header吸顶，footer不吸底。  |
| Footer | 2 | ListItemGroup的footer吸底，header不吸顶。  |

## ScrollSnapAlign<sup>10+</sup>枚举说明

设置列表项滚动结束对齐效果。

左右和上下这种两端对齐的样式：当列表位移至末端，则需要将末端的item完整显示，同时不能露出边界空白区域，此时另一端可以出现不限位对齐的现象。

只支持item等高场景限位，不等高场景可能存在不准确的情况。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称     |  值  | 说明                                     |
| ------ | ------ | ---------------------------------------- |
| NONE   | 0 | 默认无项目滚动对齐效果。            |
| START  | 1 | 视图中的第一项将在列表的开头对齐。<br/>**说明：**<br/>当列表位移至末端，需要将末端的item完整显示，可能出现开头不对齐的情况。 |
| CENTER | 2 | 视图中的中间项将在列表中心对齐。<br/>**说明：**<br/>顶端和末尾的item都可以在列表中心对齐，列表显示可能露出空白，<br/>第一个或最后一个item会对齐到中间位置。 |
| END    | 3 | 视图中的最后一项将在列表末尾对齐。<br/>**说明：**<br/>当列表位移至顶端，需要将顶端的item完整显示，可能出现末尾不对齐的情况。 |
## CloseSwipeActionOptions<sup>11+</sup>对象说明

收起[EXPANDED](ts-container-listitem.md#swipeactionstate11枚举说明)状态[ListItem](ts-container-listitem.md)回调事件集合，用于设置收起动画完成后回调事件。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称     | 类型     | 必填 | 说明                   |
| ------- | -------- | ---- | ---------------------- |
| onFinish | ()=>void | 否   | 在收起动画完成后触发。 |

## 事件

除支持[通用事件](ts-universal-events-click.md)和[滚动组件通用事件](ts-container-scrollable-common.md#事件)外，还支持以下事件：

### onItemDelete<sup>(deprecated)</sup>

onItemDelete(event: (index: number) => boolean)

当List组件在编辑模式时，点击ListItem右边出现的删除按钮时触发。

从API version9开始废弃不再使用，无替代接口。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名 | 类型   | 必填 | 说明                     |
| ------ | ------ | ---- | ------------------------ |
| index  | number | 是   | 被删除的列表项的索引值。 |

**返回值：** 

| 类型    | 说明           |
| ------- | -------------- |
| boolean | 是否已经删除。 |

### onScrollIndex

onScrollIndex(event: (start: number, end: number, center: number) => void)

有子组件划入或划出List显示区域时触发。计算索引值时，ListItemGroup作为一个整体占一个索引值，不计算ListItemGroup内部ListItem的索引值。

List的边缘效果为弹簧效果时，在List划动到边缘继续划动和松手回弹过程不会触发onScrollIndex事件。

触发该事件的条件：列表初始化时会触发一次，List显示区域内第一个子组件的索引值或最后一个子组件的索引值有变化时会触发。

从API version 10开始，List显示区域中间位置子组件变化时也会触发该事件。

**卡片能力：** 从API version 9开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名               | 类型   | 必填 | 说明                                   |
| -------------------- | ------ | ---- | -------------------------------------- |
| start                | number | 是   | List显示区域内第一个子组件的索引值     |
| end                  | number | 是   | List显示区域内最后一个子组件的索引值。 |
| center<sup>10+</sup> | number | 是   | List显示区域内中间位置子组件的索引值。 |

### onReachStart

onReachStart(event: () => void)

列表到达起始位置时触发。

List初始化时如果initialIndex为0会触发一次，List滚动到起始位置时触发一次。List边缘效果为弹簧效果时，划动经过起始位置时触发一次，回弹回起始位置时再触发一次。

**卡片能力：** 从API version 9开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

### onReachEnd

onReachEnd(event: () => void)

列表到底末尾位置时触发。

List边缘效果为弹簧效果时，划动经过末尾位置时触发一次，回弹回末尾位置时再触发一次。

**卡片能力：** 从API version 9开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

### onScrollFrameBegin<sup>9+</sup>

onScrollFrameBegin(event: (offset: number, state: ScrollState) => { offsetRemain: number })

列表开始滑动时触发，事件参数传入即将发生的滑动量，事件处理函数中可根据应用场景计算实际需要的滑动量并作为事件处理函数的返回值返回，列表将按照返回值的实际滑动量进行滑动。

当listDirection的值为Axis.Vertical时，返回垂直方向滑动量，当listDirection的值为Axis.Horizontal时，返回水平方向滑动量。

触发该事件的条件：手指拖动List、List惯性划动时每帧开始时触发；List超出边缘回弹、使用滚动控制器和拖动滚动条的滚动不会触发。

**卡片能力：** 从API version 9开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名 | 类型                                | 必填 | 说明                       |
| ------ | ----------------------------------- | ---- | -------------------------- |
| offset | number                              | 是   | 即将发生的滑动量，单位vp。 |
| state  | [ScrollState](#scrollstate枚举说明) | 是   | 当前滑动状态。             |

**返回值：** 

| 类型                     | 说明                 |
| ------------------------ | -------------------- |
| { offsetRemain: number } | 实际滑动量，单位vp。 |

### onScrollStart<sup>9+</sup>

onScrollStart(event: () => void)

列表滑动开始时触发。手指拖动列表或列表的滚动条触发的滑动开始时，会触发该事件。使用[Scroller](ts-container-scroll.md#scroller)滑动控制器触发的带动画的滑动，动画开始时会触发该事件

**卡片能力：** 从API version 9开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

### onScrollStop

onScrollStop(event: () => void)

列表滑动停止时触发。手拖动列表或列表的滚动条触发的滑动，手离开屏幕并且滑动停止时会触发该事件。使用[Scroller](ts-container-scroll.md#scroller)滑动控制器触发的带动画的滑动，动画停止会触发该事件。

**卡片能力：** 从API version 9开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

### onItemMove

onItemMove(event: (from: number, to: number) => boolean)

列表元素发生移动时触发。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名 | 类型   | 必填 | 说明           |
| ------ | ------ | ---- | -------------- |
| from   | number | 是   | 移动前索引值。 |
| to     | number | 是   | 移动后索引值。 |

**返回值：** 

| 类型    | 说明           |
| ------- | -------------- |
| boolean | 是否已经移动。 |

### onItemDragStart<sup>8+</sup>

onItemDragStart(event: (event: ItemDragInfo, itemIndex: number) => ((() => any) \| void))

开始拖拽列表元素时触发。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名    | 类型                                                      | 必填 | 说明                   |
| --------- | --------------------------------------------------------- | ---- | ---------------------- |
| event     | [ItemDragInfo](ts-container-scrollable-common.md#itemdraginfo对象说明) | 是   | 拖拽点的信息。         |
| itemIndex | number                                                    | 是   | 被拖拽列表元素索引值。 |

### onItemDragEnter<sup>8+</sup>

onItemDragEnter(event: (event: ItemDragInfo) => void)

拖拽进入列表元素范围内时触发。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名 | 类型                                                      | 必填 | 说明           |
| ------ | --------------------------------------------------------- | ---- | -------------- |
| event  | [ItemDragInfo](ts-container-scrollable-common.md#itemdraginfo对象说明) | 是   | 拖拽点的信息。 |

### onItemDragMove<sup>8+</sup>

onItemDragMove(event: (event: ItemDragInfo, itemIndex: number, insertIndex: number) => void)

拖拽在列表元素范围内移动时触发。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名      | 类型                                                      | 必填 | 说明           |
| ----------- | --------------------------------------------------------- | ---- | -------------- |
| event       | [ItemDragInfo](ts-container-scrollable-common.md#itemdraginfo对象说明) | 是   | 拖拽点的信息。 |
| itemIndex   | number                                                    | 是   | 拖拽起始位置。 |
| insertIndex | number                                                    | 是   | 拖拽插入位置。 |

### onItemDragLeave<sup>8+</sup>

onItemDragLeave(event: (event: ItemDragInfo, itemIndex: number) => void)

拖拽离开列表元素时触发。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名    | 类型                                                      | 必填 | 说明                       |
| --------- | --------------------------------------------------------- | ---- | -------------------------- |
| event     | [ItemDragInfo](ts-container-scrollable-common.md#itemdraginfo对象说明) | 是   | 拖拽点的信息。             |
| itemIndex | number                                                    | 是   | 拖拽离开的列表元素索引值。 |

### onItemDrop<sup>8+</sup>

onItemDrop(event: (event: ItemDragInfo, itemIndex: number, insertIndex: number, isSuccess: boolean) => void)

绑定该事件的列表元素可作为拖拽释放目标，当在列表元素内停止拖拽时触发。

跨List拖拽时，当拖拽释放的位置绑定了onItemDrop时会返回true，否则为false。List内部拖拽时，isSuccess为onItemMove事件的返回值。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名      | 类型                                                      | 必填 | 说明           |
| ----------- | --------------------------------------------------------- | ---- | -------------- |
| event       | [ItemDragInfo](ts-container-scrollable-common.md#itemdraginfo对象说明) | 是   | 拖拽点的信息。 |
| itemIndex   | number                                                    | 是   | 拖拽起始位置。 |
| insertIndex | number                                                    | 是   | 拖拽插入位置。 |
| isSuccess   | boolean                                                   | 是   | 是否成功释放   |


### onScroll<sup>(deprecated)</sup>
onScroll(event: (scrollOffset: number, scrollState: [ScrollState](#scrollstate枚举说明)) => void)

列表滑动时触发。

从API version 12开始废弃不再使用，推荐使用[onDidScroll](ts-container-scrollable-common.md#ondidscroll12)事件替代。

**卡片能力：** 从API version 9开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**
| 参数名 | 类型 | 必填 | 说明 |
| ------ | ------ | ------ | ------|
| scrollOffset | number | 是 | 每帧滚动的偏移量，List的内容向上滚动时偏移量为正，向下滚动时偏移量为负。<br/>单位vp。 |
| scrollState | [ScrollState](ts-container-list.md#scrollstate枚举说明) | 是 | 当前滑动状态。 |

### onScrollVisibleContentChange<sup>12+</sup>
onScrollVisibleContentChange(handler: OnScrollVisibleContentChangeCallback)

有子组件划入或划出List显示区域时触发。计算触发条件时，每一个ListItem、ListItemGroup中的header或footer都算一个子组件。

List的边缘效果为弹簧效果时，在List划动到边缘继续划动和松手回弹过程不会触发onScrollVisibleContentChange事件。

触发该事件的条件：列表初始化时会触发一次，List显示区域内第一个子组件的索引值或最后一个子组件的索引值有变化时会触发。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| ------ | ------ | ------ | ------|
| handler | [OnScrollVisibleContentChangeCallback](#onscrollvisiblecontentchangecallback12) | 是 | 当前显示内容发生改变的时候触发回调。 |

## ScrollState枚举说明

**卡片能力：** 从API version 9开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称     |  值  | 说明                                     |
| ------ | ------ | ---------------------------------------- |
| Idle   |  0  | 空闲状态。滚动状态回归空闲时触发，控制器提供的无动画方法控制滚动时触发。 |
| Scroll |  1  | 滚动状态。手指拖动List，拖动滚动条和滚动鼠标滚轮时触发。|
| Fling  |  2  | 惯性滚动状态。动画控制的滚动都会触发。包括快速划动松手后的惯性滚动， <br/>划动到边缘回弹的滚动，快速拖动内置滚动条松手后的惯性滚动， <br/>使用滚动控制器提供的带动画的方法控制的滚动。 |


## ListScroller<sup>11+</sup>对象说明

List组件的滚动控制器，通过它控制List组件的滚动，仅支持一对一绑定到List组件。


>  **说明：**
>
>  ListScroller继承自[Scroller](ts-container-scroll.md#scroller)，具有[Scroller](ts-container-scroll.md#scroller)的全部方法。


### 导入对象

```
listScroller: ListScroller = new ListScroller()
```


### getItemRectInGroup<sup>11+</sup>

getItemRectInGroup(index: number, indexInGroup: number): RectResult

获取[ListItemGroup](ts-container-listitemgroup.md)中的[ListItem](ts-container-listitem.md)的大小和相对于List的位置。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名   | 类型   | 必填   | 说明              |
| ----- | ------ | ---- | ----------------- |
| index | number | 是    | ListItemGroup在List中的索引值。 |
| indexInGroup | number | 是    | ListItem在ListItemGroup中的索引值。 |

> **说明：**
>
> - index必须是当前显示区域显示的子组件的索引值，否则视index为非法值。
> - 索引值为index的子组件必须是ListItemGroup，否则视index为非法值。
> - indexInGroup必须是当前显示区域内ListItemGroup中显示的ListItem的索引值，否则视indexInGroup为非法值。
> - index或者indexInGroup为非法值时返回的大小和位置均为0。

**返回值：**

| 类型       | 说明       |
| -------------------  | -------- |
| [RectResult](ts-types.md#rectresult10) | ListItemGroup中的ListItem的大小和相对于List的位置。<br/>单位：vp。 |


**错误码**：

以下错误码详细介绍请参考[通用错误码](../../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| ------- | -------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2.Incorrect parameters types; 3. Parameter verification failed.   |
| 100004   | Controller not bound to component.                               |

### scrollToItemInGroup<sup>11+</sup>

scrollToItemInGroup(index: number, indexInGroup: number, smooth?: boolean, align?: ScrollAlign): void

滑动到指定的ListItemGroup中指定的ListItem。

开启smooth动效时，会对经过的所有item进行加载和布局计算，当大量加载item时会导致性能问题。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名                | 类型 | 必填 | 说明                                                     |
| --------------------- | -------- | ---- | ------------------------------------------------------------ |
| index                 | number   | 是   | 要滑动到的目标元素所在的ListItemGroup在当前容器中的索引值。      <br/>**说明：** <br/>index值设置成负值或者大于当前容器子组件的最大索引值，视为异常值，本次跳转不生效。                     |
| indexInGroup          | number   | 是   | 要滑动到的目标元素在index指定的ListItemGroup中的索引值。      <br/>**说明：** <br/>indexInGroup值设置成负值或者大于index指定的ListItemGroup容器子组件的最大索引值，视为异常值，本次跳转不生效。|
| smooth                | boolean  | 否   | 设置滑动到列表项在列表中的索引值时是否有动效，true表示有动效，false表示没有动效。<br/>默认值：false。 |
| align                 | [ScrollAlign](ts-container-scroll.md#scrollalign10枚举说明)  | 否   | 指定滑动到的元素与当前容器的对齐方式。<br/>默认值：ScrollAlign.START。 |

**错误码**：

以下错误码详细介绍请参考[通用错误码](../../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| ------- | -------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2.Incorrect parameters types; 3. Parameter verification failed.   |
| 100004   | Controller not bound to component.                               |

### closeAllSwipeActions<sup>11+</sup>

closeAllSwipeActions(options?: [CloseSwipeActionOptions](#closeswipeactionoptions11对象说明)): void

将[EXPANDED](ts-container-listitem.md#swipeactionstate11枚举说明)状态的[ListItem](ts-container-listitem.md)收起，并设置回调事件。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名  | 类型                                  | 必填 | 说明                                            |
| ------- | ------------------------------------ | ---- | ----------------------------------------------- |
| options | [CloseSwipeActionOptions](#closeswipeactionoptions11对象说明) | 否   | 收起[EXPANDED](ts-container-listitem.md#swipeactionstate11枚举说明)状态的[ListItem](ts-container-listitem.md)的回调事件集合。 |


**错误码**：

以下错误码详细介绍请参考[通用错误码](../../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| ------- | -------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2.Incorrect parameters types; 3. Parameter verification failed.   |
| 100004   | Controller not bound to component.                               |

> **说明：**
>
> - ListScroller必须绑定到List组件上。

## OnScrollVisibleContentChangeCallback<sup>12+</sup>

type OnScrollVisibleContentChangeCallback = (start: VisibleListContentInfo, end: VisibleListContentInfo) => void

有子组件划入或划出List显示区域时触发。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 参数名 | 类型 | 必填 | 说明 |
| ------ | ------ | ------ | ------|
| start | [VisibleListContentInfo](#visiblelistcontentinfo12对象说明) | 是 | 当前显示界面第一个ListItem或ListItemGroup的详细信息。 |
| end | [VisibleListContentInfo](#visiblelistcontentinfo12对象说明) | 是 | 当前显示界面最后一个ListItem或ListItemGroup的详细信息。 |

## VisibleListContentInfo<sup>12+</sup>对象说明

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称 | 类型 | 必填 | 说明 |
| ------ | ------ | ------ | ------|
| index | number | 是 | List显示区域内ListItem或ListItemGroup的索引值。 |
| itemGroupArea | [ListItemGroupArea](#listitemgrouparea12枚举说明) | 否 | 如果当前可视页面的上边或下边在某个ListItemGroup之中，将会显示它所处的位置。 |
| itemIndexInGroup | number | 否 | 如果当前可视页面的上边或下边在某个Group之中，将会显示Start或End的ListItem在Group中的索引。 |

## ListItemGroupArea<sup>12+</sup>枚举说明

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称     |  值  | 说明                                     |
| ------ | ------ | ---------------------------------------- |
| NONE |  0  | 当前页面可视边处于none位置。例如，ListItemGroup中既没有header、footer，也没有ListItem。 |
| IN_LIST_ITEM_AREA |  1  | 当前页面可视边处于ListItem位置。 |
| IN_HEADER_AREA |  2  | 当前页面可视边处于header位置。 |
| IN_FOOTER_AREA |  3  | 当前页面可视边处于footer位置。 |

## 示例

### 示例1
该示例实现了设置纵向列表，并在当前显示界面发生改变时回调索引。
```ts
// xxx.ets
@Entry
@Component
struct ListExample {
  private arr: number[] = [0, 1, 2, 3, 4, 5, 6, 7, 8, 9]

  build() {
    Column() {
      List({ space: 20, initialIndex: 0 }) {
        ForEach(this.arr, (item: number) => {
          ListItem() {
            Text('' + item)
              .width('100%').height(100).fontSize(16)
              .textAlign(TextAlign.Center).borderRadius(10).backgroundColor(0xFFFFFF)
          }
        }, (item: string) => item)
      }
      .listDirection(Axis.Vertical) // 排列方向
      .scrollBar(BarState.Off)
      .friction(0.6)
      .divider({ strokeWidth: 2, color: 0xFFFFFF, startMargin: 20, endMargin: 20 }) // 每行之间的分界线
      .edgeEffect(EdgeEffect.Spring) // 边缘效果设置为Spring
      .onScrollIndex((firstIndex: number, lastIndex: number, centerIndex: number) => {
        console.info('first' + firstIndex)
        console.info('last' + lastIndex)
        console.info('center' + centerIndex)
      })
      .onScrollVisibleContentChange((start: VisibleListContentInfo, end: VisibleListContentInfo) => {
        console.log(' start index: ' + start.index +
                    ' start item group area: ' + start.itemGroupArea +
                    ' start index in group: ' + start.itemIndexInGroup)
        console.log(' end index: ' + end.index +
                    ' end item group area: ' + end.itemGroupArea +
                    ' end index in group: ' + end.itemIndexInGroup)
      })
      .onDidScroll((scrollOffset: number, scrollState: ScrollState) => {
        console.info(`onScroll scrollState = ScrollState` + scrollState + `, scrollOffset = ` + scrollOffset)
      })
      .width('90%')
    }
    .width('100%')
    .height('100%')
    .backgroundColor(0xDCDCDC)
    .padding({ top: 5 })
  }
}
```

![zh-cn_image_0000001174264378](figures/zh-cn_image_0000001174264378.gif)


### 示例2

```ts
// xxx.ets
@Entry
@Component
struct ListLanesExample {
  @State arr: string[] = ["0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "11", "12", "13", "14", "15", "16", "17", "18", "19"]
  @State alignListItem: ListItemAlign = ListItemAlign.Start

  build() {
    Column() {
      List({ space: 20, initialIndex: 0 }) {
        ForEach(this.arr, (item: string) => {
          ListItem() {
            Text('' + item)
              .width('100%')
              .height(100)
              .fontSize(16)
              .textAlign(TextAlign.Center)
              .borderRadius(10)
              .backgroundColor(0xFFFFFF)
          }
          .border({ width: 2, color: Color.Green })
        }, (item: string) => item)
      }
      .height(300)
      .width("90%")
      .friction(0.6)
      .border({ width: 3, color: Color.Red })
      .lanes({ minLength: 40, maxLength: 40 })
      .alignListItem(this.alignListItem)
      .scrollBar(BarState.Off)

      Button("点击更改alignListItem:" + this.alignListItem).onClick(() => {
        if (this.alignListItem == ListItemAlign.Start) {
          this.alignListItem = ListItemAlign.Center
        } else if (this.alignListItem == ListItemAlign.Center) {
          this.alignListItem = ListItemAlign.End
        } else {
          this.alignListItem = ListItemAlign.Start
        }
      })
    }.width('100%').height('100%').backgroundColor(0xDCDCDC).padding({ top: 5 })
  }
}
```

![list](figures/list-alignListItem.gif)


### 示例3

```ts
// xxx.ets
@Entry
@Component
struct ListExample {
  @State arr: number[] = [0, 1, 2, 3, 4, 5, 6, 7, 8, 9]
  @State editFlag: boolean = false

  build() {
    Stack({ alignContent: Alignment.TopStart }) {
      Column() {
        List({ space: 20, initialIndex: 0 }) {
          ForEach(this.arr, (item: number, index?: number) => {
            ListItem() {
              Flex({ direction: FlexDirection.Row, alignItems: ItemAlign.Center }) {
                Text('' + item)
                  .width('100%')
                  .height(80)
                  .fontSize(20)
                  .textAlign(TextAlign.Center)
                  .borderRadius(10)
                  .backgroundColor(0xFFFFFF)
                  .flexShrink(1)
                if (this.editFlag) {
                  Button() {
                    Text("delete").fontSize(16)
                  }.width('30%').height(40)
                  .onClick(() => {
                    if (index != undefined) {
                      console.info(this.arr[index] + 'Delete')
                      this.arr.splice(index, 1)
                      console.info(JSON.stringify(this.arr))
                      this.editFlag = false
                    }
                  }).stateEffect(true)
                }
              }
            }
          }, (item: string) => item)
        }.width('90%')
        .scrollBar(BarState.Off)
        .friction(0.6)
      }.width('100%')

      Button('edit list')
        .onClick(() => {
          this.editFlag = !this.editFlag
        }).margin({ top: 5, left: 20 })
    }.width('100%').height('100%').backgroundColor(0xDCDCDC).padding({ top: 5 })
  }
}
```

![list](figures/list3.gif)

### 示例4

```ts
// xxx.ets
@Entry
@Component
struct ListExample {
  private arr: number[] = []
  private scrollerForList: Scroller = new Scroller()

  aboutToAppear() {
    for (let i = 0; i < 20; i++) {
      this.arr.push(i)
    }
  }
  build() {
    Column() {
      Row() {
        List({ space: 20, initialIndex: 3, scroller: this.scrollerForList }) {
          ForEach(this.arr, (item: number) => {
            ListItem() {
              Text('' + item)
                .width('100%').height(100).fontSize(16)
                .textAlign(TextAlign.Center)
            }
            .borderRadius(10).backgroundColor(0xFFFFFF)
            .width('60%')
            .height('80%')
          }, (item: number) => JSON.stringify(item))
        }
        .chainAnimation(true)
        .edgeEffect(EdgeEffect.Spring)
        .listDirection(Axis.Horizontal)
        .height('100%')
        .width('100%')
        .scrollSnapAlign(ScrollSnapAlign.CENTER)
        .borderRadius(10)
        .backgroundColor(0xDCDCDC)
      }
      .width('100%')
      .height('100%')
      .backgroundColor(0xDCDCDC)
      .padding({ top: 10 })
    }
  }
}

```

![list](figures/list4.gif)

### 示例5
该示例通过设置childrenMainSize属性，实现了List在子组件高度不一致时调用scrollTo接口也可以跳转准确。
```ts
// xxx.ets
@Entry
@Component
struct ListExample {
  private arr: number[] = []
  private scroller: ListScroller = new ListScroller()
  @State listSpace: number = 10
  @State listChildrenSize: ChildrenMainSize = new ChildrenMainSize(100)
  aboutToAppear(){
    // 初始化数据源。
    for (let i = 0; i < 10; i++) {
      this.arr.push(i)
    }
    // 前5个item的主轴大小不是默认大小100，因此需要通过ChildrenMainSize通知List。
    this.listChildrenSize.splice(0, 5, [300, 300, 300, 300, 300])
  }
  build() {
    Column() {
      List({ space: this.listSpace, initialIndex: 4, scroller: this.scroller }) {
        ForEach(this.arr, (item: number) => {
          ListItem() {
            Text('item-' + item)
              .height( item < 5 ? 300 : this.listChildrenSize.childDefaultSize)
              .width('90%')
              .fontSize(16)
              .textAlign(TextAlign.Center)
              .borderRadius(10)
              .backgroundColor(0xFFFFFF)
          }
        }, (item: string) => item)
      }
      .backgroundColor(Color.Gray)
      .layoutWeight(1)
      .scrollBar(BarState.On)
      .childrenMainSize(this.listChildrenSize)
      .alignListItem(ListItemAlign.Center)
      Row(){
        Button() { Text('item size + 50') }.onClick(()=>{
          this.listChildrenSize.childDefaultSize += 50
        }).height('50%').width('30%')
        Button() { Text('item size - 50') }.onClick(()=>{
          if (this.listChildrenSize.childDefaultSize === 0) {
            return
          }
          this.listChildrenSize.childDefaultSize -= 50
        }).height('50%').width('30%')
        Button() { Text('scrollTo (0, 310)') }.onClick(()=>{
          // 310: 跳转到item 1顶部与List顶部平齐的位置。
          // 如果不设置childrenMainSize，item高度不一致时scrollTo会不准确。
          this.scroller.scrollTo({xOffset: 0, yOffset: 310})
        }).height('50%').width('30%')
      }.height('20%')
    }
  }
}

```

![list](figures/list5.gif)