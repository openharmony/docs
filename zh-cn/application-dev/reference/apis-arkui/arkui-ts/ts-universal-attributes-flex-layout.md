# Flex布局
<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @camlostshi-->
<!--Designer: @lanshouren-->
<!--Tester: @liuli0427-->
<!--Adviser: @HelloCrease-->

>  **说明：**
>  - 从API version 7开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。
>
>  - 仅当父组件是 [Flex](ts-container-flex.md)、[Column](ts-container-column.md)、[Row](ts-container-row.md)或[GridRow](ts-container-gridrow.md)（仅针对[alignSelf](#alignself)）时生效。

## flexBasis

flexBasis(value: number | string): T

设置组件的基准尺寸。

**卡片能力：** 从API version 9开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名 | 类型                       | 必填 | 说明                                                         |
| ------ | -------------------------- | ---- | ------------------------------------------------------------ |
| value  | number&nbsp;\|&nbsp;string | 是   | 设置组件在父容器主轴方向上的基准尺寸。<br/>默认值：'auto'（表示组件在主轴方向上的基准尺寸为组件原本的大小）。<br/>string类型可选值：可以转化为数字的字符串（如'10'）或带长度单位的字符串（如'10px'）或'auto'，不允许设置百分比字符串。<br/>number：取值范围(0,+∞)，单位为vp。<br/>异常值：默认为'auto'。 |

**返回值：**

| 类型 | 说明 |
| --- | --- |
|  T | 返回当前组件。 |

## flexGrow

flexGrow(value: number): T

设置组件在父容器的剩余空间所占比例。

**卡片能力：** 从API version 9开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名 | 类型   | 必填 | 说明                                                         |
| ------ | ------ | ---- | ------------------------------------------------------------ |
| value  | number | 是   | 设置父容器在主轴方向上的剩余空间分配给此属性所在组件的比例。<br/>取值范围[0,+∞)，默认值：0 |

**返回值：**

| 类型 | 说明 |
| --- | --- |
|  T | 返回当前组件。 |

## flexShrink

flexShrink(value: number): T

设置父容器压缩尺寸分配给此属性所在组件的比例。当父容器为Column、Row时，需设置主轴方向的尺寸。

**卡片能力：** 从API version 9开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名 | 类型   | 必填 | 说明                                                         |
| ------ | ------ | ---- | ------------------------------------------------------------ |
| value  | number | 是   | 设置父容器压缩尺寸分配给此属性所在组件的比例。<br/>父容器为[Column](ts-container-column.md)、[Row](ts-container-row.md)时，默认值：0，取值范围[0,+∞)。<br/> 父容器为[Flex](ts-container-flex.md)时，默认值：1 <br/>[constraintSize](ts-universal-attributes-size.md#constraintsize)限制组件的尺寸范围。[Column](ts-container-column.md)和[Row](ts-container-row.md)即使设置了[constraintSize](ts-universal-attributes-size.md#constraintsize)，在未设置主轴尺寸（[width](ts-universal-attributes-size.md#width)/[height](ts-universal-attributes-size.md#height)/[size](ts-universal-attributes-size.md#size)）时仍遵守默认布局行为，在主轴上自适应子组件尺寸，此时flexShrink不生效。|

**返回值：**

| 类型 | 说明 |
| --- | --- |
|  T | 返回当前组件。 |

## alignSelf

alignSelf(value: ItemAlign): T

子组件在父容器交叉轴的对齐格式。

**卡片能力：** 从API version 9开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名 | 类型                                        | 必填 | 说明                                                         |
| ------ | ------------------------------------------- | ---- | ------------------------------------------------------------ |
| value  | [ItemAlign](ts-appendix-enums.md#itemalign) | 是   | 子组件在父容器交叉轴的对齐格式，会覆盖[Flex](ts-container-flex.md)、[Column](ts-container-column.md)、[Row](ts-container-row.md)、[GridRow](ts-container-gridrow.md)布局容器中的alignItems设置。<br/>[GridCol](./ts-container-gridcol.md)可以绑定alignSelf属性来改变它自身在交叉轴方向上的布局。<br/>默认值：ItemAlign.Auto |

**返回值：**

| 类型 | 说明 |
| --- | --- |
|  T | 返回当前组件。 |

## 示例

通过配置flexBasis/flexGrow/flexShrink/alignSelf属性设置Flex布局。

```ts
// xxx.ets
@Entry
@Component
struct FlexExample {
  build() {
    Column({ space: 5 }) {
      Text('flexBasis').fontSize(9).fontColor(0xCCCCCC).width('90%')
      // 基于主轴的基准尺寸
      // flexBasis()值可以是字符串'auto'，表示基准尺寸是元素本来的大小，也可以是长度设置，相当于.width()/.height()
      Flex() {
        Text('flexBasis(100)')
          .flexBasis(100) // 这里表示宽度为100vp
          .height(100)
          .backgroundColor(0xF5DEB3)
          .textAlign(TextAlign.Center)
        Text(`flexBasis('auto')`)
          .flexBasis('auto') // 这里表示宽度保持原本设置的60%的宽度
          .width('60%')
          .height(100)
          .backgroundColor(0xD2B48C)
          .textAlign(TextAlign.Center)
      }.width('90%').height(120).padding(10).backgroundColor(0xAFEEEE)

      Text('flexGrow').fontSize(9).fontColor(0xCCCCCC).width('90%')
      // flexGrow()表示剩余空间分配给该元素的比例
      Flex() {
        Text('flexGrow(2)')
          .flexGrow(2) // 父容器分配给该Text的宽度为剩余宽度的2/3
          .height(100)
          .backgroundColor(0xF5DEB3)
          .textAlign(TextAlign.Center)
        Text('flexGrow(1)')
          .flexGrow(1) // 父容器分配给该Text的宽度为剩余宽度的1/3
          .height(100)
          .backgroundColor(0xD2B48C)
          .textAlign(TextAlign.Center)
      }.width('90%').height(120).padding(10).backgroundColor(0xAFEEEE)

      Text('flexShrink').fontSize(9).fontColor(0xCCCCCC).width('90%')
      // flexShrink()表示该元素的压缩比例，基于超出的总尺寸进行计算
      // 第一个text压缩比例是0，另外两个都是1，因此放不下时等比例压缩后两个，第一个不压缩
      Flex({ direction: FlexDirection.Row }) {
        Text('flexShrink(0)')
          .flexShrink(0)
          .width('50%')
          .height(100)
          .backgroundColor(0xF5DEB3)
          .textAlign(TextAlign.Center)
        Text('default flexShrink') // 默认值为1
          .width('40%')
          .height(100)
          .backgroundColor(0xD2B48C)
          .textAlign(TextAlign.Center)
        Text('flexShrink(1)')
          .flexShrink(1)
          .width('40%')
          .height(100)
          .backgroundColor(0xF5DEB3)
          .textAlign(TextAlign.Center)
      }.width('90%').height(120).padding(10).backgroundColor(0xAFEEEE)

      Text('alignSelf').fontSize(9).fontColor(0xCCCCCC).width('90%')
      // alignSelf会覆盖Flex布局容器中的alignItems设置
      Flex({ direction: FlexDirection.Row, alignItems: ItemAlign.Center }) {
        Text('no alignSelf,height:70')
          .width('33%')
          .height(70)
          .backgroundColor(0xF5DEB3)
          .textAlign(TextAlign.Center)
        Text('alignSelf End')
          .alignSelf(ItemAlign.End)
          .width('33%')
          .height(70)
          .backgroundColor(0xD2B48C)
          .textAlign(TextAlign.Center)
        Text('no alignSelf,height:100%')
          .width('34%')
          .height('100%')
          .backgroundColor(0xF5DEB3)
          .textAlign(TextAlign.Center)
      }.width('90%').height(120).padding(10).backgroundColor(0xAFEEEE)
    }.width('100%').margin({ top: 5 })
  }
}
```

![flex](figures/flex.PNG)
