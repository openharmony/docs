# Stack
<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @fenglinbailu-->
<!--Designer: @fenglinbailu-->
<!--Tester: @liuli0427-->
<!--Adviser: @Brilliantry_Rui-->

堆叠容器，子组件按照顺序依次入栈，后一个子组件覆盖前一个子组件。堆叠顺序基于子组件在父容器中的声明顺序，后声明的子组件具有更高的渲染层级，在视觉上覆盖前面的子组件。适用于需要层叠布局的场景，如页面上的悬浮按钮或提示信息、图片或视频上覆盖文字标签、多层叠加的弹窗或对话框等。相比使用多个容器嵌套实现层叠效果，Stack提供了更简洁高效的解决方案。

> **说明：**
>
> - 该组件从API version 7开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
> 
> - 通用属性[align](./ts-universal-attributes-location.md#align)在该组件上支持镜像能力。


## 子组件

可以包含子组件。

## 接口

Stack(options?: StackOptions)

堆叠容器，子组件按照顺序依次入栈，后一个子组件覆盖前一个子组件。堆叠顺序基于子组件在父容器中的声明顺序，后声明的子组件具有更高的渲染层级，在视觉上覆盖前面的子组件。

> **说明：**
>
> 组件嵌套层数过多会导致性能下降。在可通过组件属性或系统API实现相同布局效果的场景中，使用这些替代方法可以减少嵌套层数，从而优化性能。最佳实践请参考[组件嵌套优化-优先使用组件属性代替嵌套组件](https://developer.huawei.com/consumer/cn/doc/best-practices/bpta-component-nesting-optimization#section78181114123811)。
>
> 该接口的alignContent参数与[align](./ts-universal-attributes-location.md#align)同时设置时，后设置的属性值会覆盖先设置的属性值。该接口的alignContent参数与alignContent属性同时设置时，以属性设置的值为准。

**卡片能力：** 从API version 9开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名       | 类型                                    | 必填 | 说明                                                    |
| ------------ | ------------------------------------------- | ---- | ----------------------------------------------------------- |
| options | [StackOptions](#stackoptions18对象说明) | 否   | 设置子组件在容器内的对齐方式。当需要将子组件对齐到特定位置（如顶部、底部、左上角等）而非默认居中时传入此参数；如果不传入此参数，则使用StackOptions的默认配置，其中alignContent默认为Alignment.Center。 |

## StackOptions<sup>18+</sup>对象说明

设置堆叠容器的子组件对齐方式。

> **说明：**
>
> 为规范匿名对象的定义，API 18版本修改了此处的元素定义。其中，保留了历史匿名对象的起始版本信息，会出现外层元素@since版本号高于内层元素版本号的情况，但这不影响接口的使用。

**卡片能力：** 从API version 18开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API version 18开始，该接口支持在原子化服务中使用。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称 | 类型 | 只读 | 可选 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| alignContent<sup>7+</sup> | [Alignment](ts-appendix-enums.md#alignment) | 否 | 是   | 设置子组件在容器内的对齐方式。该属性与接口的构造入参同时设置时，以属性设置的值为准。<br>默认值：Alignment.Center <br>非法值：按默认值处理。<br>**说明：** 该参数与[align](./ts-universal-attributes-location.md#align)同时设置时，后设置的属性值会覆盖先设置的属性值。<br>**卡片能力：** 从API version 9开始，该接口支持在ArkTS卡片中使用。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 |

## 属性

除支持[通用属性](ts-component-general-attributes.md)外，还支持以下属性：

### alignContent

alignContent(value: Alignment)

设置子组件在容器内的对齐方式。该属性与[align](ts-universal-attributes-location.md#align)同时设置时，后设置的属性值会覆盖先设置的属性值。该属性与接口构造入参同时设置时，以属性设置的值为准，与设置顺序无关。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**卡片能力：** 从API version 9开始，该接口支持在ArkTS卡片中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名 | 类型                                        | 必填 | 说明                                                        |
| ------ | ------------------------------------------- | ---- | ----------------------------------------------------------- |
| value  | [Alignment](ts-appendix-enums.md#alignment) | 是   | 所有子组件在容器内的对齐方式。<br>默认值：Alignment.Center <br>非法值：按默认值处理。 |

### syncLoad

syncLoad(enable: boolean)

设置是否同步加载Stack区域内所有子组件。同步加载时，所有子组件会在当前帧内完成布局计算和渲染；异步加载时，系统会根据当前帧的布局耗时动态调整子组件的布局时机，避免阻塞主线程。

**起始版本：** 26.0.0

**原子化服务API：** 从API版本26.0.0开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**模型约束：** 此接口仅可在Stage模型下使用。

**参数：**

| 参数名 | 类型                                        | 必填 | 说明                                 |
| ------ | ------------------------------------------- | ---- | ----------------------------------- |
| enable   | boolean | 是   | 是否同步加载Stack区域内所有子组件。<br>true表示同步加载；false表示异步加载。<br>默认值：true<br>**说明：** <br>设置为false时，在首次显示场景，若当前帧布局耗时超过50ms，会将Stack区域内尚未布局的子组件延后到下一帧进行布局。 |

## 事件

支持[通用事件](ts-component-general-events.md)。

## 示例

当Stack的[alignContent](#aligncontent)属性设为Alignment.Bottom，且[syncLoad](#syncload)为true时，其子组件的显示效果表现为在Stack组件底部横向居中并且所有子组件在同一帧内加载完成。

从API版本26.0.0开始，新增syncLoad属性。

```ts
// xxx.ets
@Entry
@Component
struct StackExample {
  build() {
    // 设置子组件在Stack容器底部对齐
    Stack({ alignContent: Alignment.Bottom }) {
      // 第一个子组件，显示在底部
      Text('First child, show in bottom').width('90%').height('100%').backgroundColor(0xd2cab3).align(Alignment.Top)
      // 第二个子组件，显示在上层
      Text('Second child, show in top').width('70%').height('60%').backgroundColor(0xc1cbac).align(Alignment.Top)
    }.width('100%').height(150).margin({ top: 5 })
    // 从API版本26.0.0开始，新增syncLoad属性，设置为true表示同步加载Stack区域内所有子组件
    .syncLoad(true)
  }
}
```

![stack](figures/stack.PNG)
