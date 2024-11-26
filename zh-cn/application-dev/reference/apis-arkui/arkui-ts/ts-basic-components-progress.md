# Progress

进度条组件，用于显示内容加载或操作处理等进度。

>  **说明：**
>
>  该组件从API version 7开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。


## 子组件

无

## 接口

Progress(options: ProgressOptions)

创建进度条组件。

**卡片能力：** 从API version 9开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| options |  [ProgressOptions](#progressoptionstype对象说明)| 是 | 按进度条类型不同，设置不同属性的进度条组件参数。 |

## ProgressOptions\<Type\>对象说明

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称                        | 类型                                | 必填   | 说明                                     |
| -------------------------- | ----------------------------------- | ---- | ---------------------------------------- |
| value                      | number                              | 是    | 指定当前进度值。设置小于0的数值时置为0，设置大于total的数值时置为total。<br/>默认值：0<br/>**卡片能力：** 从API version 9开始，该接口支持在ArkTS卡片中使用。 |
| total                      | number                              | 否    | 指定进度总长。设置小于等于0的数值时置为100。<br/>默认值：100<br/>**卡片能力：** 从API version 9开始，该接口支持在ArkTS卡片中使用。 |
| type<sup>8+</sup>          | [ProgressType](#progresstype8枚举说明)   | 否    | 指定进度条类型。<br/>默认值：ProgressType.Linear<br/>**卡片能力：** 从API version 9开始，该接口支持在ArkTS卡片中使用。 |
| style<sup>(deprecated)</sup> | [ProgressStyle](#progressstyle枚举说明) | 否    | 指定进度条样式。<br/>该参数从API version8开始废弃，建议使用type替代。<br/>默认值：ProgressStyle.Linear |

## ProgressType<sup>8+</sup>枚举说明

**卡片能力：** 从API version 9开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称                     | 说明                                     |
| ---------------------- | ---------------------------------------- |
| Linear                 | 线性样式。从API version9开始，高度大于宽度的时候自适应垂直显示。   |
| Ring      | 环形无刻度样式，环形圆环逐渐显示至完全填充效果。                 |
| Eclipse  | 圆形样式，显示类似月圆月缺的进度展示效果，从月牙逐渐变化至满月。         |
| ScaleRing | 环形有刻度样式，显示类似时钟刻度形式的进度展示效果。从API version9开始，刻度外圈出现重叠的时候自动转换为环形无刻度进度条。 |
| Capsule   | 胶囊样式，头尾两端圆弧处的进度展示效果与Eclipse相同；中段处的进度展示效果与Linear相同。高度大于宽度的时候自适应垂直显示。 |

##  ProgressStyle枚举说明 

**卡片能力：** 从API version 9开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称        | 说明                                     |
| --------- | ---------------------------------------- |
| Linear    | 线性样式。                                    |
| Ring<sup>8+</sup>      | 环形无刻度样式，环形圆环逐渐显示至完全填充效果。                 |
| Eclipse   | 圆形样式，显示类似月圆月缺的进度展示效果，从月牙逐渐变化至满月。         |
| ScaleRing<sup>8+</sup> | 环形有刻度样式，显示类似时钟刻度形式的进度展示效果。               |
| Capsule<sup>8+</sup>   | 胶囊样式，头尾两端圆弧处的进度展示效果与Eclipse相同；中段处的进度展示效果与Linear相同。高度大于宽度的时候自适应垂直显示。 |

##  ProgressStyleMap对象说明 

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称        | 类型                                      |
| --------- | ---------------------------------------- |
| ProgressType.Linear | [LinearStyleOptions<sup>10+</sup>](#linearstyleoptions10)&nbsp; \| &nbsp;[ProgressStyleOptions<sup>8+</sup>](#progressstyleoptions8)&nbsp; |
ProgressType.Ring | [RingStyleOptions<sup>10+</sup>](#ringstyleoptions10)&nbsp; \| &nbsp;[ProgressStyleOptions<sup>8+</sup>](#progressstyleoptions8)&nbsp; |
ProgressType.Eclipse | [EclipseStyleOptions<sup>10+</sup>](#eclipsestyleoptions10)&nbsp;  \| &nbsp;[ProgressStyleOptions<sup>8+</sup>](#progressstyleoptions8)&nbsp; |
ProgressType.ScaleRing| [ScaleRingStyleOptions<sup>10+</sup>](#scaleringstyleoptions10)&nbsp; \| &nbsp;[ProgressStyleOptions<sup>8+</sup>](#progressstyleoptions8)&nbsp; |
ProgressType.Capsule | [CapsuleStyleOptions<sup>10+</sup>](#capsulestyleoptions10)&nbsp; \| &nbsp;[ProgressStyleOptions<sup>8+</sup>](#progressstyleoptions8)&nbsp;

## 属性

除支持[通用属性](ts-universal-attributes-size.md)外，还支持以下属性：

> **说明：**
>
> 该组件重写了通用属性[backgroundColor](ts-universal-attributes-background.md)，直接添加在Progress组件上，生效进度条的底色。如需设置整个Progress组件的背景色，需要在外层容器上添加backgroundColor，容器再包裹Progress组件。

### value

value(value: number)

设置当前进度值。设置小于0的数值时置为0，设置大于total的数值时置为total。非法数值不生效。

**卡片能力：** 从API version 9开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名 | 类型   | 必填 | 说明         |
| ------ | ------ | ---- | ------------ |
| value  | number | 是   | 当前进度值。<br/> 默认值：0|

### color

color(value: ResourceColor | LinearGradient)

设置进度条前景色。

从API version 10开始支持利用LinearGradient设置Ring样式的渐变色。

**卡片能力：** 从API version 9开始，该接口支持在ArkTS卡片中使用，暂不支持LinearGradient。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名 | 类型                                                         | 必填 | 说明                                                         |
| ------ | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| value  | [ResourceColor](ts-types.md#resourcecolor)&nbsp;\|&nbsp;[LinearGradient<sup>10+</sup>](ts-basic-components-datapanel.md#lineargradient10) | 是   | 进度条前景色。<br/>默认值：<br/>- Capsule：<br/>&nbsp;&nbsp;&nbsp;API version 9及以下：'\#ff007dff'<br/>&nbsp;&nbsp;&nbsp;API version 10：'\#33006cde'<br/>&nbsp;&nbsp;&nbsp;API version 11及以上：'\#33007dff'<br/>- Ring：<br/>&nbsp;&nbsp;&nbsp;API version 9及以下：'\#ff007dff'<br/>&nbsp;&nbsp;&nbsp;API version 10及以上：起始端：'\#ff86c1ff'，结束端：'\#ff254ff7'<br/>- 其他样式：'\#ff007dff' |

### style<sup>8+</sup>

style(value: ProgressStyleOptions \| CapsuleStyleOptions \| RingStyleOptions \| LinearStyleOptions \| ScaleRingStyleOptions \| EclipseStyleOptions)

设置组件的样式。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名 | 类型                                                         | 必填 | 说明                                                         |
| ------ | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| value  | [ProgressStyleOptions<sup>8+</sup>](#progressstyleoptions8)&nbsp;\|&nbsp;[CapsuleStyleOptions<sup>10+</sup>](#capsulestyleoptions10)&nbsp;\|&nbsp;<br/>[RingStyleOptions<sup>10+</sup>](#ringstyleoptions10)&nbsp;\|&nbsp;[LinearStyleOptions<sup>10+</sup>](#linearstyleoptions10)&nbsp;\|&nbsp;<br/>[ScaleRingStyleOptions<sup>10+</sup>](#scaleringstyleoptions10)&nbsp;\|&nbsp;[EclipseStyleOptions<sup>10+</sup>](#eclipsestyleoptions10) | 是   | 组件的样式。<br/>- CapsuleStyleOptions：设置Capsule的样式。<br/>- RingStyleOptions：设置Ring的样式。<br/>- LinearStyleOptions：设置Linear的样式。<br/>- ScaleRingStyleOptions：设置ScaleRing的样式。<br/>- EclipseStyleOptions：设置Eclipse的样式。<br/>- ProgressStyleOptions：仅可设置各类型进度条的基本样式。<br/>ProgressStyleOptions，暂不支持其它的参数类型。 |

### contentModifier<sup>12+</sup>
contentModifier(modifier:ContentModifier\<ProgressConfiguration\>)

定制progress内容区的方法。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**
| 参数名 | 类型   | 必填 | 说明         |
| ------ | ------ | ---- | ------------ |
| modifier | [ContentModifier\<ProgressConfiguration\>](#progressconfiguration12) | 是   | 在progress组件上，定制内容区的方法。<br/>modifier: 内容修改器，开发者需要自定义class实现ContentModifier接口。 |

### privacySensitive<sup>12+</sup>

privacySensitive(isPrivacySensitiveMode: Optional\<boolean\>)

设置隐私敏感。

**卡片能力：** 从API version 12开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名 | 类型                                                      | 必填 | 说明                                                  |
| ------ | --------------------------------------------------------- | ---- | ----------------------------------------------------- |
| isPrivacySensitiveMode  | [Optional\<boolean\>] | 是   | 设置隐私敏感，隐私模式下进度清零，文字将被遮罩。<br/>**说明：** <br/>设置null则不敏感。<br/>[需要卡片框架支持。](./ts-universal-attributes-obscured.md) |

## ProgressConfiguration<sup>12+</sup>

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称 | 类型  | 必填 |说明         |
| ------ | ------ | ------- |------------|
| value  | number | 是 | 当前进度值。 |
| total  | number | 是 | 进度总长。   |

## CommonProgressStyleOptions<sup>10+</sup>

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称          | 类型                      | 必填 | 说明                                                                                        |
| ------------ | ---------------------------- | ---- | ------------------------------------------------------------------------------------------ |
| enableSmoothEffect | boolean | 否 | 进度平滑动效的开关。开启平滑动效后设置进度，进度会从当前值渐变至设定值，否则进度从当前值突变至设定值。<br/>默认值：true |

## ScanEffectOptions<sup>10+</sup>

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称          | 类型 | 必填 | 说明 |
| ------------- | ------- | ---- | -------- |
| enableScanEffect | boolean | 否 | 扫光效果的开关。<br/>默认值：false |

## ProgressStyleOptions<sup>8+</sup>

继承自[CommonProgressStyleOptions](#commonprogressstyleoptions10)。

**卡片能力：** 从API version 9开始，该接口支持在ArkTS卡片中使用。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称          | 类型                      | 必填 | 说明                                                                                        |
| ------------ | ---------------------------- | ---- | ------------------------------------------------------------------------------------------ |
| strokeWidth  | [Length](ts-types.md#length) | 否   | 设置进度条宽度（不支持百分比设置）。<br/>默认值：4.0vp                                            |
| scaleCount   | number                       | 否   | 设置环形进度条总刻度数。<br/>默认值：120                                                        |
| scaleWidth   | [Length](ts-types.md#length) | 否   | 设置环形进度条刻度粗细（不支持百分比设置），刻度粗细大于进度条宽度时，为系统默认粗细。<br/>默认值：2.0vp |

## CapsuleStyleOptions<sup>10+</sup>

继承自[ScanEffectOptions](#scaneffectoptions10)，[CommonProgressStyleOptions](#commonprogressstyleoptions10)。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称          | 类型 | 必填 | 说明 |
| ------------- | ------- | ---- | -------- |
| borderColor | [ResourceColor](ts-types.md#resourcecolor) | 否 | 内描边颜色。<br/>默认值：<br/>API version 10：'\#33006cde'<br/>API version 11及以上：'\#33007dff' |
| borderWidth | [Length](ts-types.md#length) | 否 | 内描边宽度（不支持百分比设置）。<br/>默认值：1vp |
| content | string | 否 | 文本内容，应用可自定义。 |
| font | [Font](ts-types.md#font) | 否 | 文本样式。<br/>默认值：<br/>- 文本大小（不支持百分比设置）：12fp <br/>其他文本参数跟随text组件的主题值。|
| fontColor | [ResourceColor](ts-types.md#resourcecolor) | 否 | 文本颜色。<br/>默认值：'\#ff182431' |
| showDefaultPercentage | boolean | 否 | 显示百分比文本的开关，开启后会在进度条上显示当前进度的百分比。设置了content属性时该属性不生效。<br/>默认值：false |

## RingStyleOptions<sup>10+</sup>

继承自[ScanEffectOptions](#scaneffectoptions10)，[CommonProgressStyleOptions](#commonprogressstyleoptions10)。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称           | 类型                      | 必填 | 说明                                                                                        |
| ------------- | ---------------------------- | ---- | ------------------------------------------------------------------------------------------ |
| strokeWidth   | [Length](ts-types.md#length) | 否   | 设置进度条宽度（不支持百分比设置），宽度大于等于半径时，默认修改宽度至半径值的二分之一。<br/>默认值：4.0vp |
| shadow        | boolean                      | 否   | 进度条阴影开关。<br/>默认值：false                                                             |
| status        | [ProgressStatus<sup>10+</sup>](#progressstatus10枚举说明) | 否 | 进度条状态，当设置为LOADING时会开启检查更新动效，此时设置进度值不生效。当从LOADING设置为PROGRESSING，检查更新动效会执行到终点再停止。<br/>默认值： ProgressStatus.PROGRESSING |

## LinearStyleOptions<sup>10+</sup>

继承自[ScanEffectOptions](#scaneffectoptions10)，[CommonProgressStyleOptions](#commonprogressstyleoptions10)。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称           | 类型                      | 必填 | 说明                                                                                        |
| ------------- | ---------------------------- | ---- | ------------------------------------------------------------------------------------------ |
| strokeWidth   | [Length](ts-types.md#length) | 否   | 设置进度条宽度（不支持百分比设置）。<br/>默认值：4.0vp |
| strokeRadius   | [PX](ts-types.md#px10)    \| [VP](ts-types.md#vp10)    \| [LPX](ts-types.md#lpx10)    \| [Resource](ts-types.md#resource)| 否   | 设置线性进度条圆角半径。<br/>取值范围[0, strokeWidth / 2]。默认值：strokeWidth / 2。 |

## ScaleRingStyleOptions<sup>10+</sup>

继承自[CommonProgressStyleOptions](#commonprogressstyleoptions10)。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称          | 类型                      | 必填 | 说明                                                                                        |
| ------------ | ---------------------------- | ---- | ------------------------------------------------------------------------------------------ |
| strokeWidth  | [Length](ts-types.md#length) | 否   | 设置进度条宽度（不支持百分比设置）。<br/>默认值：4.0vp                                            |
| scaleCount   | number                       | 否   | 设置环形进度条总刻度数。<br/>默认值：120                                                        |
| scaleWidth   | [Length](ts-types.md#length) | 否   | 设置环形进度条刻度粗细（不支持百分比设置），刻度粗细大于进度条宽度时，为系统默认粗细。<br/>默认值：2.0vp |

## EclipseStyleOptions<sup>10+</sup>

继承自[CommonProgressStyleOptions](#commonprogressstyleoptions10)。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

## ProgressStatus<sup>10+</sup>枚举说明

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称                    | 说明      |
| ----------------------- | ---------------- |
| LOADING  | 加载中。 |
| PROGRESSING | 进度更新中。 |

## 事件

支持[通用事件](ts-universal-events-click.md)。

## 示例

### 示例1

各进度条基础属性效果。

```ts
// xxx.ets
@Entry
@Component
struct ProgressExample {
  build() {
    Column({ space: 15 }) {
      Text('Linear Progress').fontSize(9).fontColor(0xCCCCCC).width('90%')
      Progress({ value: 10, type: ProgressType.Linear }).width(200)
      Progress({ value: 20, total: 150, type: ProgressType.Linear }).color(Color.Grey).value(50).width(200)


      Text('Eclipse Progress').fontSize(9).fontColor(0xCCCCCC).width('90%')
      Row({ space: 40 }) {
        Progress({ value: 10, type: ProgressType.Eclipse }).width(100)
        Progress({ value: 20, total: 150, type: ProgressType.Eclipse }).color(Color.Grey).value(50).width(100)
      }

      Text('ScaleRing Progress').fontSize(9).fontColor(0xCCCCCC).width('90%')
      Row({ space: 40 }) {
        Progress({ value: 10, type: ProgressType.ScaleRing }).width(100)
        Progress({ value: 20, total: 150, type: ProgressType.ScaleRing })
          .color(Color.Grey).value(50).width(100)
          .style({ strokeWidth: 15, scaleCount: 15, scaleWidth: 5 })
      }

      // scaleCount和scaleWidth效果对比
      Row({ space: 40 }) {
        Progress({ value: 20, total: 150, type: ProgressType.ScaleRing })
          .color(Color.Grey).value(50).width(100)
          .style({ strokeWidth: 20, scaleCount: 20, scaleWidth: 5 })
        Progress({ value: 20, total: 150, type: ProgressType.ScaleRing })
          .color(Color.Grey).value(50).width(100)
          .style({ strokeWidth: 20, scaleCount: 30, scaleWidth: 3 })
      }

      Text('Ring Progress').fontSize(9).fontColor(0xCCCCCC).width('90%')
      Row({ space: 40 }) {
        Progress({ value: 10, type: ProgressType.Ring }).width(100)
        Progress({ value: 20, total: 150, type: ProgressType.Ring })
          .color(Color.Grey).value(50).width(100)
          .style({ strokeWidth: 20 })
      }

      Text('Capsule Progress').fontSize(9).fontColor(0xCCCCCC).width('90%')
      Row({ space: 40 }) {
        Progress({ value: 10, type: ProgressType.Capsule }).width(100).height(50)
        Progress({ value: 20, total: 150, type: ProgressType.Capsule })
          .color(Color.Grey)
          .value(50)
          .width(100)
          .height(50)
      }
    }.width('100%').margin({ top: 30 })
  }
}
```

![progress](figures/arkts-progress.png)

### 示例2

环形进度条视觉属性。

```ts
// xxx.ets
@Entry
@Component
struct ProgressExample {
  private gradientColor: LinearGradient = new LinearGradient([{ color: Color.Yellow, offset: 0.5 },
                                                              { color: Color.Orange, offset: 1.0 }])
  build() {
    Column({ space: 15 }) {
      Text('Gradient Color').fontSize(9).fontColor(0xCCCCCC).width('90%')
      Progress({ value: 70, total: 100, type: ProgressType.Ring })
        .width(100).style({ strokeWidth: 20 })
        .color(this.gradientColor)

      Text('Shadow').fontSize(9).fontColor(0xCCCCCC).width('90%')
      Progress({ value: 70, total: 100, type: ProgressType.Ring })
        .width(120).color(Color.Orange)
        .style({ strokeWidth: 20, shadow: true })
    }.width('100%').padding({ top: 5 })
  }
}
```
![ringProgressStyleEffect](figures/arkts-ringProgressStyleEffect.png)

### 示例3

环形进度条动效。

```ts
// xxx.ets
@Entry
@Component
struct ProgressExample {
  build() {
    Column({ space: 15 }) {
      Text('Loading Effect').fontSize(9).fontColor(0xCCCCCC).width('90%')
      Progress({ value: 0, total: 100, type: ProgressType.Ring })
        .width(100).color(Color.Blue)
        .style({ strokeWidth: 20, status: ProgressStatus.LOADING })

      Text('Scan Effect').fontSize(9).fontColor(0xCCCCCC).width('90%')
      Progress({ value: 30, total: 100, type: ProgressType.Ring })
        .width(100).color(Color.Orange)
        .style({ strokeWidth: 20, enableScanEffect: true })
    }.width('100%').padding({ top: 5 })
  }
}
```
![ringProgressAnimation](figures/arkts-ringProgressAnimation.gif)

### 示例4

胶囊形进度条视觉属性。

```ts
// xxx.ets
@Entry
@Component
struct ProgressExample {

  build() {
    Column({ space: 15 }) {
      Row({ space: 40 }) {
        Progress({ value: 100, total: 100,type: ProgressType.Capsule }).width(100).height(50)
          .style({borderColor: Color.Blue, borderWidth: 1, content: 'Installing...',
                  font: {size: 13, style: FontStyle.Normal}, fontColor: Color.Gray,
                  enableScanEffect: false, showDefaultPercentage: false})
      }
    }.width('100%').padding({ top: 5 })
  }
}
```
![capsuleProgressStyleEffect](figures/arkts-capsuleProgressStyleEffect.png)

### 示例5

进度平滑动效。

```ts
// xxx.ets
@Entry
@Component
struct Index {
  @State value: number = 0

  build() {
    Column({space: 10}) {
      Text('enableSmoothEffect: true').fontSize(9).fontColor(0xCCCCCC).width('90%').margin(5)
        .margin({top: 20})
      Progress({value: this.value, total: 100, type:ProgressType.Linear})
        .style({strokeWidth: 10, enableSmoothEffect: true})

      Text('enableSmoothEffect: false').fontSize(9).fontColor(0xCCCCCC).width('90%').margin(5)
      Progress({value: this.value, total: 100, type:ProgressType.Linear})
        .style({strokeWidth: 10, enableSmoothEffect: false})

      Button('value +10').onClick(() => {
        this.value += 10
      })
        .width(75)
        .height(15)
        .fontSize(9)
    }
    .width('50%')
    .height('100%')
    .margin({left:20})
  }
}

```
![progressSmoothEffect](figures/arkts-progressSmoothEffect.gif)

### 示例6

该示例实现了自定义进度条的功能，自定义实现星形，其中总进度为3，且当前值可通过按钮进行增减，达到的进度被填充自定义颜色。

```ts
// xxx.ets
class MyProgressModifier implements ContentModifier<ProgressConfiguration> {
  color: Color = Color.White


  constructor(color:Color) {
    this.color = color
  }
  applyContent() : WrappedBuilder<[ProgressConfiguration]>
  {
    return wrapBuilder(myProgress)
  }
}

@Builder function myProgress(config: ProgressConfiguration ) {

  Column({space:30}) {
    Text("当前进度：" + config.value + "/" + config.total).fontSize(20)
    Row() {
      Flex({ justifyContent: FlexAlign.SpaceBetween }) {
        Path()
          .width('30%')
          .height('30%')
          .commands('M108 0 L141 70 L218 78.3 L162 131 L175 205 L108 170 L41.2 205 L55 131 L1 78 L75 68 L108 0 Z')
          .fill(config.enabled && config.value >=1 ? (config.contentModifier as MyProgressModifier).color : Color.White)
          .stroke(Color.Black)
          .strokeWidth(3)
        Path()
          .width('30%')
          .height('30%')
          .commands('M108 0 L141 70 L218 78.3 L162 131 L175 205 L108 170 L41.2 205 L55 131 L1 78 L75 68 L108 0 Z')
          .fill(config.enabled && config.value >=2 ? (config.contentModifier as MyProgressModifier).color : Color.White)
          .stroke(Color.Black)
          .strokeWidth(3)
        Path()
          .width('30%')
          .height('30%')
          .commands('M108 0 L141 70 L218 78.3 L162 131 L175 205 L108 170 L41.2 205 L55 131 L1 78 L75 68 L108 0 Z')
          .fill(config.enabled && config.value >=3 ? (config.contentModifier as MyProgressModifier).color : Color.White)
          .stroke(Color.Black)
          .strokeWidth(3)
      }.width('100%')
    }
  }.margin({bottom:100})
}

@Entry
@Component
struct Index {
  @State currentValue: number = 0
  modifier = new MyProgressModifier(Color.Red)
  @State myModifier:(MyProgressModifier | undefined)  = this.modifier
  build() {
    Column() {
        Progress({ value: this.currentValue, total: 3, type: ProgressType.Ring}).contentModifier(this.modifier)
        Button('Progress++').onClick(()=>{
          if (this.currentValue < 3) {
            this.currentValue += 1
          }
        }).width('30%')
        Button('addProgress--').onClick(()=>{
          if (this.currentValue > 0) {
            this.currentValue -= 1
          }
        }).width('30%')
    }.width('100%').height('100%')
  }
}

```
![progressCustom](figures/arkts-progressCustom.gif)

### 示例7

该示例展示了如何配置隐私隐藏，效果展示需要卡片框架支持

```ts
@Entry
@Component
struct ProgressExample {
  build() {
    Scroll() {
      Column({ space: 15 }) {
        Row() {
          Progress({ value: 50, total: 100, type: ProgressType.Capsule }).width(100).height(50)
            .style({
              borderColor: Color.Blue,
              borderWidth: 1,
              content: 'Installing...',
              font: { size: 13, style: FontStyle.Normal },
              fontColor: Color.Gray,
              enableScanEffect: false,
              showDefaultPercentage: true
            })
            .privacySensitive(true)
        }
      }
    }
  }
}
```
![progressSensitive](figures/progress-privacysensitive.gif)