# Flex
<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @camlostshi-->
<!--Designer: @fenglinbailu-->
<!--Tester: @liuli0427-->
<!--Adviser: @Brilliantry_Rui-->

Flex是以弹性方式布局子组件的容器组件，能够高效地排列、对齐子元素并分配剩余空间。

具体指南请参考[弹性布局](../../../ui/arkts-layout-development-flex-layout.md)。

> **说明：**
>
> - 该组件从API version 7开始支持。后续版本如有新增内容将采用上角标单独标记该内容的起始版本。
> - Flex组件在渲染时存在二次布局过程，因此在对性能有严格要求的场景下建议使用[Column](ts-container-column.md)、[Row](ts-container-row.md)代替。最佳实践请参考布局优化指导-[合理使用布局组件](https://developer.huawei.com/consumer/cn/doc/harmonyos-guides/arkts-layout-optimization-guidance#合理使用布局组件)。
> - Flex组件主轴不设置长度时默认撑满父容器，如果包含设置[position](ts-universal-attributes-location.md#position)的子组件，此时Flex组件不会撑满父容器。[Column](ts-container-column.md)、[Row](ts-container-row.md)组件主轴不设置长度时默认跟随子节点大小。
> - Flex、Column、Row组件在没有子节点且不设置宽高时，默认宽高为-1。
> - 主轴长度可设置为auto使Flex自适应子组件布局，自适应时，Flex长度受[constraintSize](ts-universal-attributes-size.md#constraintsize)属性以及父容器传递的最大最小长度限制，且constraintSize属性优先级更高。


## 子组件

可以包含子组件。

## 接口

Flex(value?: FlexOptions)

创建Flex布局容器，用于以弹性方式排列、对齐子组件并分配剩余空间。

**卡片能力：** 从API version 9开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名            | 类型        | 必填   | 说明                                     |
| -------------- | ---------------------------------------- | ---- |  ---------------------------------------- |
| value      | [FlexOptions](#flexoptions对象说明) | 否    |  Flex容器的配置选项，用于设置子组件的排列方向、换行方式、对齐方式和间距。不传入时使用默认配置，各属性默认值详见[FlexOptions](#flexoptions对象说明)对象说明。               |

## FlexOptions对象说明

设置Flex子组件的排列对齐方式。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称 | 类型 | 只读 | 可选 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| direction      | [FlexDirection](ts-appendix-enums.md#flexdirection) | 否 | 是     | 子组件在Flex容器上排列的方向，即主轴的方向。设置后，子组件将按照指定的方向在主轴上依次排列。<br>默认值：FlexDirection.Row <br>异常值按默认值处理。<br>取值包括：<br>- Row：主轴为水平方向，起点在左端。<br>- RowReverse：主轴为水平方向，起点在右端。<br>- Column：主轴为垂直方向，起点在上端。<br>- ColumnReverse：主轴为垂直方向，起点在下端。<br>Row和RowReverse的起点位置受容器的direction属性影响。<br>**卡片能力：** 从API version 9开始，该接口支持在ArkTS卡片中使用。   <br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。            |
| wrap           | [FlexWrap](ts-appendix-enums.md#flexwrap) | 否 | 是     | Flex容器是单行/列还是多行/列排列。设置后，子组件将在容器中按指定的换行方式进行布局。<br>默认值：FlexWrap.NoWrap <br>异常值按默认值处理。<br>取值包括：<br>- NoWrap：不换行，子组件总宽度超过容器宽度时被截断。<br>- Wrap：换行，第一行在上方。<br>- WrapReverse：换行，第一行在下方。<br>**说明：** <br>在多行布局时，通过交叉轴方向，确认新行堆叠方向。<br>**卡片能力：** 从API version 9开始，该接口支持在ArkTS卡片中使用。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 |
| justifyContent | [FlexAlign](ts-appendix-enums.md#flexalign) | 否 | 是     | 所有子组件在Flex容器主轴上的对齐格式。设置后，子组件将按照指定的对齐方式在主轴方向上分布和排列。<br>默认值：FlexAlign.Start <br>异常值按默认值处理。<br>取值包括：<br>- Start：首端对齐。<br>- Center：居中对齐。<br>- End：尾端对齐。<br>- SpaceBetween：两端对齐，子组件之间间距相等。<br>- SpaceAround：子组件两侧间距相等。<br>- SpaceEvenly：子组件之间及两端间距完全相等。<br>**说明：** 当justifyContent设置为SpaceBetween、SpaceAround、SpaceEvenly时，space参数不生效。<br>**卡片能力：** 从API version 9开始，该接口支持在ArkTS卡片中使用。  <br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。                  |
| alignItems     | [ItemAlign](ts-appendix-enums.md#itemalign) | 否 | 是     | 所有子组件在Flex容器交叉轴上的对齐格式。设置后，子组件将按照指定的对齐方式在交叉轴方向上定位。<br>默认值：ItemAlign.Start <br>异常值按默认值处理。<br>取值包括：<br>- Auto：使用父容器的对齐方式。<br>- Start：首部对齐。<br>- Center：居中对齐。<br>- End：尾部对齐。<br>- Stretch：拉伸填充。<br>- Baseline：基线对齐。<br>**卡片能力：** 从API version 9开始，该接口支持在ArkTS卡片中使用。  <br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。               |
| alignContent   | [FlexAlign](ts-appendix-enums.md#flexalign) | 否 | 是     | 当交叉轴存在额外空间时，多行内容之间的对齐方式。仅在wrap为Wrap或WrapReverse下生效。<br>默认值：FlexAlign.Start <br>异常值按默认值处理。<br>取值包括：<br>- Start：首端对齐。<br>- Center：居中对齐。<br>- End：尾端对齐。<br>- SpaceBetween：两端对齐，行与行之间间距相等。<br>- SpaceAround：每行两侧间距相等。<br>- SpaceEvenly：行与行之间及两端间距完全相等。<br>**卡片能力：** 从API version 9开始，该接口支持在ArkTS卡片中使用。<br>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。  |
| space<sup>12+</sup>          | [FlexSpaceOptions<sup>12+</sup>](#flexspaceoptions12) | 否 | 是   | 设置Flex容器子组件在主轴和交叉轴上的间距，包含main和cross两个属性。当需要调整子组件之间的间距时传入此参数，不传入时子组件之间无间距。<br>默认值：{main: LengthMetrics.px(0), cross: LengthMetrics.px(0)} <br>非法值：按默认值处理。 <br>当space.main或space.cross的值为负数，或者justifyContent设置为FlexAlign.SpaceBetween、FlexAlign.SpaceAround、FlexAlign.SpaceEvenly时，space参数不生效。其中main属性在单行或多行布局时均生效，cross属性仅在wrap为Wrap或WrapReverse（多行布局）时生效。<br>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。<br>**模型约束：** 此接口仅可在Stage模型下使用。|

## FlexSpaceOptions<sup>12+</sup>

设置Flex容器的子组件在主轴或交叉轴的间距。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称          | 类型        |  只读     | 可选      | 说明      |
| ----------- | --------- | ----------- | --------- |----------- |
| main   | [LengthMetrics](../js-apis-arkui-graphics.md#lengthmetrics12)  | 否 | 是 | Flex容器主轴上相邻子组件之间的间距。设置后，主轴方向相邻子组件之间将按指定间距进行分隔，在单行或多行布局时均生效。当space.main为负数，或者justifyContent设置为FlexAlign.SpaceBetween、FlexAlign.SpaceAround、FlexAlign.SpaceEvenly时，该参数不生效。<br> 默认值：LengthMetrics.px(0) |
| cross  | [LengthMetrics](../js-apis-arkui-graphics.md#lengthmetrics12) | 否 | 是 | Flex容器交叉轴上相邻行之间的间距。设置后，交叉轴方向相邻行之间将按指定间距进行分隔，仅在多行布局（wrap为Wrap或WrapReverse）时生效。当space.cross为负数，或者justifyContent设置为FlexAlign.SpaceBetween、FlexAlign.SpaceAround、FlexAlign.SpaceEvenly时，该参数不生效。<br> 默认值：LengthMetrics.px(0) |

## 属性

支持[通用属性](ts-component-general-attributes.md)。

## 事件

支持[通用事件](ts-component-general-events.md)。

## 示例

### 示例1（子组件排列方向）
该示例通过设置direction实现不同的子组件排列方向效果。
```ts
// xxx.ets
@Entry
@Component
struct FlexExample1 {
  build() {
    Column() {
      Column({ space: 5 }) {
        Text('direction:Row').fontSize(9).fontColor(0xCCCCCC).width('90%')
        Flex({ direction: FlexDirection.Row }) { // 子组件在容器主轴上行布局
          Text('1').width('20%').height(50).backgroundColor(0xF5DEB3)
          Text('2').width('20%').height(50).backgroundColor(0xD2B48C)
          Text('3').width('20%').height(50).backgroundColor(0xF5DEB3)
          Text('4').width('20%').height(50).backgroundColor(0xD2B48C)
        }
        .height(70)
        .width('90%')
        .padding(10)
        .backgroundColor(0xAFEEEE)

        Text('direction:RowReverse').fontSize(9).fontColor(0xCCCCCC).width('90%')
        Flex({ direction: FlexDirection.RowReverse }) { // 子组件在容器主轴上反向行布局
          Text('1').width('20%').height(50).backgroundColor(0xF5DEB3)
          Text('2').width('20%').height(50).backgroundColor(0xD2B48C)
          Text('3').width('20%').height(50).backgroundColor(0xF5DEB3)
          Text('4').width('20%').height(50).backgroundColor(0xD2B48C)
        }
        .height(70)
        .width('90%')
        .padding(10)
        .backgroundColor(0xAFEEEE)

        Text('direction:Column').fontSize(9).fontColor(0xCCCCCC).width('90%')
        Flex({ direction: FlexDirection.Column }) { // 子组件在容器主轴上列布局
          Text('1').width('100%').height(40).backgroundColor(0xF5DEB3)
          Text('2').width('100%').height(40).backgroundColor(0xD2B48C)
          Text('3').width('100%').height(40).backgroundColor(0xF5DEB3)
          Text('4').width('100%').height(40).backgroundColor(0xD2B48C)
        }
        .height(160)
        .width('90%')
        .padding(10)
        .backgroundColor(0xAFEEEE)

        Text('direction:ColumnReverse').fontSize(9).fontColor(0xCCCCCC).width('90%')
        Flex({ direction: FlexDirection.ColumnReverse }) { // 子组件在容器主轴上反向列布局
          Text('1').width('100%').height(40).backgroundColor(0xF5DEB3)
          Text('2').width('100%').height(40).backgroundColor(0xD2B48C)
          Text('3').width('100%').height(40).backgroundColor(0xF5DEB3)
          Text('4').width('100%').height(40).backgroundColor(0xD2B48C)
        }
        .height(160)
        .width('90%')
        .padding(10)
        .backgroundColor(0xAFEEEE)
      }.width('100%').margin({ top: 5 })
    }.width('100%')
  }
}
```

![flex1](figures/flex1.PNG)

### 示例2（子组件单/多行排列）
该示例通过设置wrap实现子组件单行或多行的排列效果。
```ts
// xxx.ets
@Entry
@Component
struct FlexExample2 {
  build() {
    Column() {
      Column({ space: 5 }) {
        Text('Wrap').fontSize(9).fontColor(0xCCCCCC).width('90%')
        Flex({ wrap: FlexWrap.Wrap }) { // 子组件多行布局
          Text('1').width('50%').height(50).backgroundColor(0xF5DEB3)
          Text('2').width('50%').height(50).backgroundColor(0xD2B48C)
          Text('3').width('50%').height(50).backgroundColor(0xD2B48C)
        }
        .width('90%')
        .padding(10)
        .backgroundColor(0xAFEEEE)

        Text('NoWrap').fontSize(9).fontColor(0xCCCCCC).width('90%')
        Flex({ wrap: FlexWrap.NoWrap }) { // 子组件单行布局
          Text('1').width('50%').height(50).backgroundColor(0xF5DEB3)
          Text('2').width('50%').height(50).backgroundColor(0xD2B48C)
          Text('3').width('50%').height(50).backgroundColor(0xF5DEB3)
        }
        .width('90%')
        .padding(10)
        .backgroundColor(0xAFEEEE)

        Text('WrapReverse').fontSize(9).fontColor(0xCCCCCC).width('90%')
        Flex({ wrap: FlexWrap.WrapReverse , direction:FlexDirection.Row }) { // 子组件反向多行布局
          Text('1').width('50%').height(50).backgroundColor(0xF5DEB3)
          Text('2').width('50%').height(50).backgroundColor(0xD2B48C)
          Text('3').width('50%').height(50).backgroundColor(0xD2B48C)
        }
        .width('90%')
        .height(120)
        .padding(10)
        .backgroundColor(0xAFEEEE)
      }.width('100%').margin({ top: 5 })
    }.width('100%')
  }
}
```

![flex2](figures/flex2.png)

### 示例3（子组件在主轴上的对齐格式）
该示例通过设置justifyContent实现子组件在主轴上不同的对齐效果。
```ts
// xxx.ets
@Component
struct JustifyContentFlex {
  justifyContent: number = 0;

  build() {
    Flex({ justifyContent: this.justifyContent }) {
      Text('1').width('20%').height(50).backgroundColor(0xF5DEB3)
      Text('2').width('20%').height(50).backgroundColor(0xD2B48C)
      Text('3').width('20%').height(50).backgroundColor(0xF5DEB3)
    }
    .width('90%')
    .padding(10)
    .backgroundColor(0xAFEEEE)
  }
}

@Entry
@Component
struct FlexExample3 {
  build() {
    Column() {
      Column({ space: 5 }) {
        Text('justifyContent:Start').fontSize(9).fontColor(0xCCCCCC).width('90%')
        JustifyContentFlex({ justifyContent: FlexAlign.Start }) // 子组件在容器主轴上首端对齐

        Text('justifyContent:Center').fontSize(9).fontColor(0xCCCCCC).width('90%')
        JustifyContentFlex({ justifyContent: FlexAlign.Center }) // 子组件在容器主轴上居中对齐

        Text('justifyContent:End').fontSize(9).fontColor(0xCCCCCC).width('90%')
        JustifyContentFlex({ justifyContent: FlexAlign.End }) // 子组件在容器主轴上尾端对齐

        Text('justifyContent:SpaceBetween').fontSize(9).fontColor(0xCCCCCC).width('90%')
        JustifyContentFlex({ justifyContent: FlexAlign.SpaceBetween }) // 子组件在容器主轴上均分容器布局，第一个子组件与行首对齐，最后一个子组件与行尾对齐。

        Text('justifyContent:SpaceAround').fontSize(9).fontColor(0xCCCCCC).width('90%')
        JustifyContentFlex({ justifyContent: FlexAlign.SpaceAround }) // 子组件在容器主轴上均分容器布局，每个子组件两侧都有相等的空间，因此第一个子组件到行首的距离和最后一个子组件到行尾的距离是相邻子组件之间距离的一半。

        Text('justifyContent:SpaceEvenly').fontSize(9).fontColor(0xCCCCCC).width('90%')
        JustifyContentFlex({ justifyContent: FlexAlign.SpaceEvenly }) // 子组件在容器主轴上均分容器布局，子组件之间的距离与第一子组件到行首、最后一个子组件到行尾的距离相等
      }.width('100%').margin({ top: 5 })
    }.width('100%')
  }
}
```

![flex3](figures/flex3.PNG)

### 示例4（子组件在交叉轴上的对齐方式）
该示例通过设置alignItems实现子组件在交叉轴上的不同的对齐效果。
```ts
// xxx.ets
@Component
struct AlignItemsFlex {
  alignItems: number = 0;

  build() {
    Flex({ alignItems: this.alignItems }) {
      Text('1').width('33%').height(30).backgroundColor(0xF5DEB3)
      Text('2').width('33%').height(40).backgroundColor(0xD2B48C)
      Text('3').width('33%').height(50).backgroundColor(0xF5DEB3)
    }
    .size({width: '90%', height: 80})
    .padding(10)
    .backgroundColor(0xAFEEEE)
  }
}

@Entry
@Component
struct FlexExample4 {
  build() {
    Column() {
      Column({ space: 5 }) {
        Text('alignItems:Auto').fontSize(9).fontColor(0xCCCCCC).width('90%')
        AlignItemsFlex({ alignItems: ItemAlign.Auto }) // 子组件在容器交叉轴上自动对齐

        Text('alignItems:Start').fontSize(9).fontColor(0xCCCCCC).width('90%')
        AlignItemsFlex({ alignItems: ItemAlign.Start }) // 子组件在容器交叉轴上首部对齐

        Text('alignItems:Center').fontSize(9).fontColor(0xCCCCCC).width('90%')
        AlignItemsFlex({ alignItems: ItemAlign.Center }) // 子组件在容器交叉轴上居中对齐

        Text('alignItems:End').fontSize(9).fontColor(0xCCCCCC).width('90%')
        AlignItemsFlex({ alignItems: ItemAlign.End }) // 子组件在容器交叉轴上尾部对齐

        Text('alignItems:Stretch').fontSize(9).fontColor(0xCCCCCC).width('90%')
        AlignItemsFlex({ alignItems: ItemAlign.Stretch }) // 子组件在容器交叉轴上拉伸填充

        Text('alignItems:Baseline').fontSize(9).fontColor(0xCCCCCC).width('90%')
        AlignItemsFlex({ alignItems: ItemAlign.Baseline }) // 子组件在容器交叉轴上与文本基线对齐
      }.width('100%').margin({ top: 5 })
    }.width('100%')
  }
}
```

![flex4](figures/flex4.png)

### 示例5（多行内容的对齐方式）
该示例通过设置alignContent实现多行内容的不同对齐效果。
```ts
// xxx.ets
@Component
struct AlignContentFlex {
  alignContent: number = 0;

  build() {
    Flex({ wrap: FlexWrap.Wrap, alignContent: this.alignContent }) {
      Text('1').width('50%').height(20).backgroundColor(0xF5DEB3)
      Text('2').width('50%').height(20).backgroundColor(0xD2B48C)
      Text('3').width('50%').height(20).backgroundColor(0xD2B48C)
    }
    .size({ width: '90%', height: 90 })
    .padding(10)
    .backgroundColor(0xAFEEEE)
  }
}

@Entry
@Component
struct FlexExample5 {
  build() {
    Column() {
      Column({ space: 5 }) {
        Text('alignContent:Start').fontSize(9).fontColor(0xCCCCCC).width('90%')
        AlignContentFlex({ alignContent: FlexAlign.Start }) // 多行布局下子组件首部对齐

        Text('alignContent:Center').fontSize(9).fontColor(0xCCCCCC).width('90%')
        AlignContentFlex({ alignContent: FlexAlign.Center }) // 多行布局下子组件居中对齐

        Text('alignContent:End').fontSize(9).fontColor(0xCCCCCC).width('90%')
        AlignContentFlex({ alignContent: FlexAlign.End }) // 多行布局下子组件尾部对齐

        Text('alignContent:SpaceBetween').fontSize(9).fontColor(0xCCCCCC).width('90%')
        AlignContentFlex({ alignContent: FlexAlign.SpaceBetween }) // 多行布局下第一行子组件与列首对齐，最后一行子组件与列尾对齐

        Text('alignContent:SpaceAround').fontSize(9).fontColor(0xCCCCCC).width('90%')
        AlignContentFlex({ alignContent: FlexAlign.SpaceAround }) // 多行布局下第一行子组件到列首的距离和最后一行子组件到列尾的距离是相邻行之间距离的一半

        Text('alignContent:SpaceEvenly').fontSize(9).fontColor(0xCCCCCC).width('90%')
        Flex({
          wrap: FlexWrap.Wrap,
          alignContent: FlexAlign.SpaceEvenly
        }) { // 多行布局下相邻行之间的距离与第一行子组件到列首的距离、最后一行子组件到列尾的距离完全一样
          Text('1').width('50%').height(20).backgroundColor(0xF5DEB3)
          Text('2').width('50%').height(20).backgroundColor(0xD2B48C)
          Text('3').width('50%').height(20).backgroundColor(0xF5DEB3)
          Text('4').width('50%').height(20).backgroundColor(0xD2B48C)
          Text('5').width('50%').height(20).backgroundColor(0xF5DEB3)
        }
        .size({ width: '90%', height: 100 })
        .padding({ left: 10, right: 10 })
        .backgroundColor(0xAFEEEE)
      }.width('100%').margin({ top: 5 })
    }.width('100%')
  }
}
```

![flex5](figures/flex5.PNG)

### 示例6（子组件单/多行排列时的主/交叉轴间距）
该示例通过设置space属性，为单/多行排列的子组件设置主轴和交叉轴上的间距。
```ts
import {LengthMetrics} from '@kit.ArkUI';

@Entry
@Component
struct FlexExample6 {
  build() {
    Column() {
      Column({ space: 5 }) {
        Text('Wrap').fontSize(9).fontColor(0xCCCCCC).width('90%')
        Flex({ wrap: FlexWrap.Wrap, space: {main: LengthMetrics.px(50), cross: LengthMetrics.px(50)} }) { // 子组件多行布局
          Text('1').width('40%').height(50).backgroundColor(0xF5DEB3)
          Text('2').width('40%').height(50).backgroundColor(0xD2B48C)
          Text('3').width('40%').height(50).backgroundColor(0xD2B48C)
        }
        .width('90%')
        .padding(10)
        .backgroundColor(0xAFEEEE)

        Text('NoWrap').fontSize(9).fontColor(0xCCCCCC).width('90%')
        Flex({ wrap: FlexWrap.NoWrap, space: {main: LengthMetrics.px(50), cross: LengthMetrics.px(50)} }) { // 子组件单行布局
          Text('1').width('50%').height(50).backgroundColor(0xF5DEB3)
          Text('2').width('50%').height(50).backgroundColor(0xD2B48C)
          Text('3').width('50%').height(50).backgroundColor(0xF5DEB3)
        }
        .width('90%')
        .padding(10)
        .backgroundColor(0xAFEEEE)

        Text('WrapReverse').fontSize(9).fontColor(0xCCCCCC).width('90%')
        Flex({ wrap: FlexWrap.WrapReverse, direction:FlexDirection.Row, space: {main: LengthMetrics.px(50), cross: LengthMetrics.px(50)} }) { // 子组件反向多行布局
          Text('1').width('40%').height(50).backgroundColor(0xF5DEB3)
          Text('2').width('40%').height(50).backgroundColor(0xD2B48C)
          Text('3').width('40%').height(50).backgroundColor(0xD2B48C)
        }
        .width('90%')
        .height(120)
        .padding(10)
        .backgroundColor(0xAFEEEE)
      }.width('100%').margin({ top: 5 })
    }.width('100%')
  }
}
```

![flex6](figures/flex6.PNG)

### 示例7（宽度自适应的Flex容器）
该示例实现了Flex在宽度设置auto后可以自适应子组件布局的能力。
```ts
@Component
struct Demo {
  @Require @Prop text: string

  build() {
    Button() {
      Flex() {
        Image($r('sys.media.ohos_ic_public_voice'))
          .width(16)
          .height(16)

        Row() {
          Text(this.text)
            .margin({
              left: 6,
              right: 6
            })
            .fontSize(14)
            .maxLines(1)
            .textOverflow({ overflow: TextOverflow.Ellipsis })
        }

        Image($r('sys.media.ohos_ic_public_sound'))
          .width(16)
          .height(16)
      }.width('auto')
    }
    .backgroundColor(0xAFEEEE)
    .height(36)
    .padding({ left: 16, right: 16 })
    .constraintSize({ maxWidth: 156 })
    .width('auto')
  }
}

@Entry
@Component
struct FlexExample7 {
  build() {
    Column({ space: 12 }) {
      Text('Width does not reach max length').fontSize(11).fontColor(0XCCCCCC).width('50%')
      Demo({ text: '123' })
      Text('Width reaches max length').fontSize(11).fontColor(0XCCCCCC).width('50%')
      Demo({ text: '1234567890-1234567890-1234567890-1234567890' })
    }
  }
}
```

![flexDemo7](figures/flexDemo7.png)
