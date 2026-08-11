# LayoutAlgorithm
<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @zju_ljz-->
<!--Designer: @fenglinbailu-->
<!--Tester: @liuli0427-->
<!--Adviser: @Brilliantry_Rui-->

[DynamicLayout](./arkui-ts/ts-container-dynamiclayout.md)组件支持的布局算法详细信息。

LayoutAlgorithm是动态布局容器的布局算法基础类型，提供了多种布局算法实现，包括线性布局、堆叠布局和网格布局。开发者可以根据实际场景选择合适的布局算法，也可以继承CustomLayoutAlgorithm实现自定义布局。

> **说明：**
>
> - 本模块首批接口从API version 24开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>
> - 本模块接口仅可在Stage模型下使用。

## 导入模块

```ts
import { LayoutAlgorithm, CustomLayoutAlgorithm, RowLayoutAlgorithm, ColumnLayoutAlgorithm, StackLayoutAlgorithm, GridLayoutAlgorithm } from '@kit.ArkUI';
```

## LayoutAlgorithm

动态布局容器[DynamicLayout](./arkui-ts/ts-container-dynamiclayout.md)的布局算法基础类型。

> **说明：**
>
> 该类型变量可以赋值具体的布局算法类对象，如[CustomLayoutAlgorithm](#customlayoutalgorithm)类对象、[RowLayoutAlgorithm](#rowlayoutalgorithm)类对象等。

**模型约束：** 此接口仅可在Stage模型下使用。

**卡片能力：** 从API version 24开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API version 24开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

## CustomLayoutAlgorithm

自定义布局算法类，允许开发者实现自定义的测量和布局逻辑。适用于需要精细控制子组件尺寸和位置的复杂布局场景，如瀑布流布局、不规则网格布局、动态流式布局等。通过重写onMeasure和onLayout方法，开发者可以实现内置布局算法无法覆盖的布局策略。

**装饰器类型：** [\@ObservedV2](../../ui/state-management/arkts-new-observedV2-and-trace.md)

> **说明：**
>
> CustomLayoutAlgorithm类对象可以作为[DynamicLayout](./arkui-ts/ts-container-dynamiclayout.md)组件的入参指定布局算法。

### onMeasure
onMeasure(self: FrameNode, constraint: LayoutConstraint): void

通过重写此函数，开发者可以自定义测量子组件的大小。ArkUI框架会在动态布局组件确定尺寸时，将该组件对应的FrameNode和布局约束通过onMeasure传递给开发者。不允许在onMeasure函数中改变状态变量。

> **说明：**
>
> - onMeasure和[onLayout](#onlayout)通常需要配合使用，共同完成完整的自定义布局流程。框架先调用onMeasure测量子组件大小，再调用onLayout设置子组件位置。
> - 在此函数中，开发者可以调用[FrameNode](js-apis-arkui-frameNode.md#framenode-1)的[getChild()](js-apis-arkui-frameNode.md#getchild12)方法获取子组件FrameNode，调用[FrameNode](js-apis-arkui-frameNode.md#framenode-1)的[measure()](js-apis-arkui-frameNode.md#measure12)方法测量子组件大小，参考DynamicLayout组件[示例1（自定义布局算法实现瀑布流布局）](./arkui-ts/ts-container-dynamiclayout.md#示例1自定义布局算法实现瀑布流布局)。

**模型约束：** 此接口仅可在Stage模型下使用。

**卡片能力：** 从API version 24开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API version 24开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| ---- | ---- | ---- | ---- |
| self | [FrameNode](js-apis-arkui-frameNode.md#framenode-1) | 是 | 动态布局组件在组件树上的实体节点，用于获取子组件FrameNode并测量子组件大小。|
| constraint | [LayoutConstraint](js-apis-arkui-frameNode.md#layoutconstraint12) | 是 | 动态布局组件进行测量时使用的布局约束。|

### onLayout
onLayout(self: FrameNode, position: Position): void

通过重写此函数，开发者可以自定义排列子组件的位置。ArkUI框架会在动态布局组件确定位置时，将该组件对应的FrameNode和布局位置通过onLayout传递给开发者。不允许在onLayout函数中改变状态变量。

> **说明：**
>
> - onLayout和[onMeasure](#onmeasure)通常需要配合使用，共同完成完整的自定义布局流程。框架先调用onMeasure测量子组件大小，再调用onLayout设置子组件位置。
> - 在此函数中，开发者可以调用[FrameNode](js-apis-arkui-frameNode.md#framenode-1)的[getChild()](js-apis-arkui-frameNode.md#getchild12)方法获取子组件FrameNode，调用[FrameNode](js-apis-arkui-frameNode.md#framenode-1)的[layout()](js-apis-arkui-frameNode.md#layout12)方法设置子组件位置，参考DynamicLayout组件[示例1（自定义布局算法实现瀑布流布局）](./arkui-ts/ts-container-dynamiclayout.md#示例1自定义布局算法实现瀑布流布局)。

**模型约束：** 此接口仅可在Stage模型下使用。
  
**卡片能力：** 从API version 24开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API version 24开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| ---- | ---- | ---- | ---- |
| self | [FrameNode](js-apis-arkui-frameNode.md#framenode-1) | 是 | 动态布局组件在组件树上的实体节点，用于获取子组件FrameNode并设置子组件位置。|
| position | [Position](js-apis-arkui-graphics.md#position) | 是 | 动态布局组件进行布局时使用的位置信息。|

**示例：**

请参考DynamicLayout组件[示例1（自定义布局算法实现瀑布流布局）](./arkui-ts/ts-container-dynamiclayout.md#示例1自定义布局算法实现瀑布流布局)。

## RowLayoutAlgorithm

水平方向线性布局算法类，用于实现子组件的水平线性排列。适用于需要水平排列子组件的场景，如横向列表、工具栏、标签栏、操作按钮组等。支持设置子组件间距、垂直对齐方式、水平对齐方式和排列方向，提供类似Row组件的布局能力。

**装饰器类型：** [\@ObservedV2](../../ui/state-management/arkts-new-observedV2-and-trace.md)

> **说明：**
>
> RowLayoutAlgorithm类对象可以作为[DynamicLayout](./arkui-ts/ts-container-dynamiclayout.md)组件的入参指定布局算法。

### 属性

**模型约束：** 此接口仅可在Stage模型下使用。

**卡片能力：** 从API version 24开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API version 24开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称 | 类型 | 只读 | 可选 | 说明 |
| ---- | ---- | ---- | ---- | ---- |
| space | [LengthMetrics](js-apis-arkui-graphics.md#lengthmetrics12) | 否 | 是 | 子组件水平方向间距。取值范围：非负数。<br> 默认值：LengthMetrics.vp(0) <br> 非法值：按默认值处理。<br>装饰器类型：[@Trace](../../ui/state-management/arkts-new-observedV2-and-trace.md) |
| alignItems | [VerticalAlign](./arkui-ts/ts-appendix-enums.md#verticalalign) | 否 | 是 | 所有子组件在垂直方向上的对齐格式。<br> 默认值：VerticalAlign.Center <br> 非法值：按默认值处理。<br>装饰器类型：[@Trace](../../ui/state-management/arkts-new-observedV2-and-trace.md) |
| justifyContent | [FlexAlign](./arkui-ts/ts-appendix-enums.md#flexalign) | 否 | 是 | 所有子组件在水平方向上的对齐格式。<br> 默认值：FlexAlign.Start <br> 非法值：按默认值处理。<br>装饰器类型：[@Trace](../../ui/state-management/arkts-new-observedV2-and-trace.md) |
| isReverse | boolean | 否 | 是 | 子组件在水平方向上的排列是否反转。取值为true表示子组件在水平方向上反转排列。水平方向受通用属性[direction](./arkui-ts/ts-universal-attributes-location.md#direction)影响，当[direction](./arkui-ts/ts-universal-attributes-location.md#direction)属性设置后，子组件会先根据direction排列，再根据isReverse进行反转。取值为false表示子组件在水平方向上正序排列。<br>默认值：false <br> 非法值：按默认值处理。<br>装饰器类型：[@Trace](../../ui/state-management/arkts-new-observedV2-and-trace.md) |

### constructor

constructor(option?: RowLayoutAlgorithmOptions)

水平方向线性布局算法类的构造函数。

**模型约束：** 此接口仅可在Stage模型下使用。

**卡片能力：** 从API version 24开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API version 24开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| ---- | ---- | ---- | ---- |
| option | [RowLayoutAlgorithmOptions](#rowlayoutalgorithmoptions) | 否 | 水平方向线性布局算法的构造入参，设置布局算法的间距、主轴对齐方式、交叉轴对齐方式及主轴排列方向。不传入时使用各属性的默认值。|

**示例：**

请参考DynamicLayout组件[示例2（切换布局算法）](./arkui-ts/ts-container-dynamiclayout.md#示例2切换布局算法)。

## RowLayoutAlgorithmOptions

设置水平方向线性布局算法的间距、主轴对齐方式、交叉轴对齐方式及主轴排列方向。

**模型约束：** 此接口仅可在Stage模型下使用。

**卡片能力：** 从API version 24开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API version 24开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称 | 类型 | 只读 | 可选 | 说明 |
| ---- | ---- | ---- | ---- | ---- |
| space | [LengthMetrics](js-apis-arkui-graphics.md#lengthmetrics12) | 否 | 是 | 子组件水平方向间距。取值范围：非负数。<br> 默认值：LengthMetrics.vp(0) <br> 非法值：按默认值处理。|
| alignItems | [VerticalAlign](./arkui-ts/ts-appendix-enums.md#verticalalign) | 否 | 是 | 所有子组件在垂直方向上的对齐格式。<br> 默认值：VerticalAlign.Center <br> 非法值：按默认值处理。|
| justifyContent | [FlexAlign](./arkui-ts/ts-appendix-enums.md#flexalign) | 否 | 是 | 所有子组件在水平方向上的对齐格式。<br> 默认值：FlexAlign.Start <br> 非法值：按默认值处理。|
| isReverse | boolean | 否 | 是 | 子组件在水平方向上的排列是否反转。取值为true表示子组件在水平方向上反转排列。水平方向受通用属性[direction](./arkui-ts/ts-universal-attributes-location.md#direction)影响，当[direction](./arkui-ts/ts-universal-attributes-location.md#direction)属性设置后，子组件会先根据direction排列，再根据isReverse进行反转。取值为false表示子组件在水平方向上正序排列。<br>默认值：false <br> 非法值：按默认值处理。|

## ColumnLayoutAlgorithm

垂直方向线性布局算法类，用于实现子组件的垂直线性排列。适用于需要垂直排列子组件的场景，如纵向列表、垂直堆叠的表单项、垂直菜单等。支持设置子组件间距、水平对齐方式、垂直对齐方式和排列方向，提供类似Column组件的布局能力。

**装饰器类型：** [\@ObservedV2](../../ui/state-management/arkts-new-observedV2-and-trace.md)

> **说明：**
>
> ColumnLayoutAlgorithm类对象可以作为[DynamicLayout](./arkui-ts/ts-container-dynamiclayout.md)组件的入参指定布局算法。

### 属性

**模型约束：** 此接口仅可在Stage模型下使用。

**卡片能力：** 从API version 24开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API version 24开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称 | 类型 | 只读 | 可选 | 说明 |
| ---- | ---- | ---- | ---- | ---- |
| space | [LengthMetrics](js-apis-arkui-graphics.md#lengthmetrics12) | 否 | 是 | 子组件垂直方向间距。取值范围：非负数。<br> 默认值：LengthMetrics.vp(0) <br> 非法值：按默认值处理。<br>装饰器类型：[@Trace](../../ui/state-management/arkts-new-observedV2-and-trace.md) |
| alignItems | [HorizontalAlign](./arkui-ts/ts-appendix-enums.md#horizontalalign) | 否 | 是 | 所有子组件在水平方向上的对齐格式。<br> 默认值：HorizontalAlign.Center <br> 非法值：按默认值处理。<br>装饰器类型：[@Trace](../../ui/state-management/arkts-new-observedV2-and-trace.md) |
| justifyContent | [FlexAlign](./arkui-ts/ts-appendix-enums.md#flexalign) | 否 | 是 | 所有子组件在垂直方向上的对齐格式。<br> 默认值：FlexAlign.Start <br> 非法值：按默认值处理。<br>装饰器类型：[@Trace](../../ui/state-management/arkts-new-observedV2-and-trace.md) |
| isReverse | boolean | 否 | 是 | 子组件在垂直方向上的排列是否反转。取值为true表示子组件在垂直方向上反转排列。垂直方向不受通用属性direction影响。取值为false表示子组件在垂直方向上正序排列。<br>默认值：false <br> 非法值：按默认值处理。<br>装饰器类型：[@Trace](../../ui/state-management/arkts-new-observedV2-and-trace.md) |

### constructor 

constructor(option?: ColumnLayoutAlgorithmOptions)

垂直方向线性布局算法类的构造函数。

**模型约束：** 此接口仅可在Stage模型下使用。

**卡片能力：** 从API version 24开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API version 24开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| ---- | ---- | ---- | ---- |
| option | [ColumnLayoutAlgorithmOptions](#columnlayoutalgorithmoptions) | 否 | 垂直方向线性布局算法的构造入参，设置布局算法的间距、主轴对齐方式、交叉轴对齐方式及主轴排列方向。不传入时使用各属性的默认值。|

**示例：**

请参考DynamicLayout组件[示例2（切换布局算法）](./arkui-ts/ts-container-dynamiclayout.md#示例2切换布局算法)。

## ColumnLayoutAlgorithmOptions

设置垂直方向线性布局算法的间距、主轴对齐方式、交叉轴对齐方式及主轴排列方向。

**模型约束：** 此接口仅可在Stage模型下使用。

**卡片能力：** 从API version 24开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API version 24开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称 | 类型 | 只读 | 可选 | 说明 |
| ---- | ---- | ---- | ---- | ---- |
| space | [LengthMetrics](js-apis-arkui-graphics.md#lengthmetrics12) | 否 | 是 | 子组件垂直方向间距。取值范围：非负数。<br> 默认值：LengthMetrics.vp(0) <br> 非法值：按默认值处理。|
| alignItems | [HorizontalAlign](./arkui-ts/ts-appendix-enums.md#horizontalalign) | 否 | 是 | 所有子组件在水平方向上的对齐格式。<br> 默认值：HorizontalAlign.Center <br> 非法值：按默认值处理。|
| justifyContent | [FlexAlign](./arkui-ts/ts-appendix-enums.md#flexalign) | 否 | 是 | 所有子组件在垂直方向上的对齐格式。<br> 默认值：FlexAlign.Start <br> 非法值：按默认值处理。|
| isReverse | boolean | 否 | 是 | 子组件在垂直方向上的排列是否反转。取值为true表示子组件在垂直方向上反转排列。垂直方向不受通用属性direction影响。取值为false表示子组件在垂直方向上正序排列。<br>默认值：false <br> 非法值：按默认值处理。|

## StackLayoutAlgorithm

堆叠布局算法类，用于实现子组件的堆叠排列。适用于需要子组件重叠显示的场景，如图层叠加、悬浮按钮、带背景的内容区域、卡片叠加效果等。支持设置子组件在堆叠容器中的对齐方式，提供类似Stack组件的布局能力。

**装饰器类型：** [\@ObservedV2](../../ui/state-management/arkts-new-observedV2-and-trace.md)

> **说明：**
>
> StackLayoutAlgorithm类对象可以作为[DynamicLayout](./arkui-ts/ts-container-dynamiclayout.md)组件的入参指定布局算法。

### 属性

**模型约束：** 此接口仅可在Stage模型下使用。

**卡片能力：** 从API version 24开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API version 24开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称 | 类型 | 只读 | 可选 | 说明 |
| ---- | ---- | ---- | ---- | ---- |
| alignContent | [LocalizedAlignment](./arkui-ts/ts-appendix-enums.md#localizedalignment20) | 否 | 是 | 设置子组件在堆叠布局算法中对齐格式。<br> 默认值：LocalizedAlignment.CENTER <br> 非法值：按默认值处理。<br>装饰器类型：[@Trace](../../ui/state-management/arkts-new-observedV2-and-trace.md) |

### constructor

constructor(option?: StackLayoutAlgorithmOptions)

堆叠布局算法类的构造函数。

**模型约束：** 此接口仅可在Stage模型下使用。

**卡片能力：** 从API version 24开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API version 24开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| ---- | ---- | ---- | ---- |
| option | [StackLayoutAlgorithmOptions](#stacklayoutalgorithmoptions) | 否 | 堆叠布局算法的构造入参，设置九宫格对齐格式。不传入时使用各属性的默认值。|

**示例：**

请参考DynamicLayout组件[示例2（切换布局算法）](./arkui-ts/ts-container-dynamiclayout.md#示例2切换布局算法)。

## StackLayoutAlgorithmOptions

设置堆叠布局算法的对齐方式。

**模型约束：** 此接口仅可在Stage模型下使用。

**卡片能力：** 从API version 24开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API version 24开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称 | 类型 | 只读 | 可选 | 说明 |
| ---- | ---- | ---- | ---- | ---- |
| alignContent | [LocalizedAlignment](./arkui-ts/ts-appendix-enums.md#localizedalignment20) | 否 | 是 | 设置子组件在堆叠布局算法中对齐格式。<br> 默认值：LocalizedAlignment.CENTER <br> 非法值：按默认值处理。|

## GridLayoutAlgorithm

网格布局算法类，用于实现子组件的网格排列。适用于需要将子组件按网格形式排列的场景，如宫格菜单、相册网格、应用列表、商品展示等。支持设置列数模板、列间距和行间距，提供类似Grid组件的布局能力。

**装饰器类型：** [\@ObservedV2](../../ui/state-management/arkts-new-observedV2-and-trace.md)

> **说明：**
>
> GridLayoutAlgorithm类对象可以作为[DynamicLayout](./arkui-ts/ts-container-dynamiclayout.md)组件的入参指定布局算法。

### 属性

**模型约束：** 此接口仅可在Stage模型下使用。

**原子化服务API：** 从API version 24开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称 | 类型 | 只读 | 可选 | 说明 |
| ---- | ---- | ---- | ---- | ---- |
| columnsTemplate | string \| [ItemFillPolicy](./arkui-ts/ts-types.md#itemfillpolicy22) | 否 | 是 | 设置当前网格布局的列模板，定义列的宽度和数量。string类型需符合模板格式，例如'1fr'表示单列布局，'1fr 1fr 1fr'表示三列等宽布局，'1fr 2fr'表示两列且第二列宽度是第一列的两倍。使用ItemFillPolicy时可实现自适应列数。<br> 默认值：'1fr' <br> 非法值：按默认值处理。<br>装饰器类型：[@Trace](../../ui/state-management/arkts-new-observedV2-and-trace.md) |
| columnsGap | [LengthMetrics](js-apis-arkui-graphics.md#lengthmetrics12) | 否 | 是 | 列与列之间的间距。取值范围：非负数。<br> 默认值：LengthMetrics.vp(0) <br> 非法值：按默认值处理。<br>装饰器类型：[@Trace](../../ui/state-management/arkts-new-observedV2-and-trace.md) |
| rowsGap | [LengthMetrics](js-apis-arkui-graphics.md#lengthmetrics12) | 否 | 是 | 行与行之间的间距。取值范围：非负数。<br> 默认值：LengthMetrics.vp(0) <br> 非法值：按默认值处理。<br>装饰器类型：[@Trace](../../ui/state-management/arkts-new-observedV2-and-trace.md) |

### constructor

constructor(option?: GridLayoutAlgorithmOptions)

网格布局算法类的构造函数。

**模型约束：** 此接口仅可在Stage模型下使用。

**原子化服务API：** 从API version 24开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| ---- | ---- | ---- | ---- |
| option | [GridLayoutAlgorithmOptions](#gridlayoutalgorithmoptions) | 否 | 网格布局算法的构造入参，设置网格布局的列数、列间距、行间距。不传入时使用各属性的默认值。|

**示例：**

请参考DynamicLayout组件[示例2（切换布局算法）](./arkui-ts/ts-container-dynamiclayout.md#示例2切换布局算法)。

## GridLayoutAlgorithmOptions

设置网格布局算法的列数模板、列间距、行间距。

**模型约束：** 此接口仅可在Stage模型下使用。

**原子化服务API：** 从API version 24开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称 | 类型 | 只读 | 可选 | 说明 |
| ---- | ---- | ---- | ---- | ---- |
| columnsTemplate | string \| [ItemFillPolicy](./arkui-ts/ts-types.md#itemfillpolicy22) | 否 | 是 | 设置当前网格布局的列模板，定义列的宽度和数量。string类型需符合模板格式，例如'1fr'表示单列布局，'1fr 1fr 1fr'表示三列等宽布局，'1fr 2fr'表示两列且第二列宽度是第一列的两倍。使用ItemFillPolicy时可实现自适应列数。<br> 默认值：'1fr' <br> 非法值：按默认值处理。|
| columnsGap | [LengthMetrics](js-apis-arkui-graphics.md#lengthmetrics12) | 否 | 是 | 列与列之间的间距。取值范围：非负数。<br> 默认值：LengthMetrics.vp(0) <br> 非法值：按默认值处理。|
| rowsGap | [LengthMetrics](js-apis-arkui-graphics.md#lengthmetrics12) | 否 | 是 | 行与行之间的间距。取值范围：非负数。<br> 默认值：LengthMetrics.vp(0) <br> 非法值：按默认值处理。|