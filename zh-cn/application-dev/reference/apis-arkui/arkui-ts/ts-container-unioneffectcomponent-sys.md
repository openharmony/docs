# UnionEffectContainer (系统接口)
<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @hehongyang3-->
<!--Designer: @hehongyang3-->
<!--Tester: @lxl007-->
<!--Adviser: @Brilliantry_Rui-->

形状融合容器，配合后代组件的[useUnionEffect](ts-universal-attributes-use-union-effect-sys.md#useunioneffect)属性使用。该容器会收集所有设置了[useUnionEffect](ts-universal-attributes-use-union-effect-sys.md#useunioneffect)的后代组件形状，将收集的形状融合后作为该容器的绘制形状。若后代组件未设置[useUnionEffect](ts-universal-attributes-use-union-effect-sys.md#useunioneffect)属性，则容器不会产生融合效果。

>  **说明：**
>
> - 该组件从API version 23开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。
>
> - 本模块接口仅可在Stage模型下使用。
>
> - 本模块为系统接口。
> 
> - 形状融合过程中，开发者可通过动画接口为融合形变添加过渡动画效果。

## 子组件

可以包含子组件。

## 接口

### UnionEffectContainer

UnionEffectContainer(options?: UnionEffectContainerOptions)

创建形状融合容器组件。

**系统接口：** 此接口为系统接口。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名            | 类型        | 必填   | 说明                                     |
| -------------- | ---------------------------------------- | ---- |  ---------------------------------------- |
| options      | [UnionEffectContainerOptions](#unioneffectcontaineroptions对象说明) | 否    |  UnionEffectContainer构造参数，用于决定收集到的后代组件形状的融合形变程度。<br>默认值：{spacing:0}               |

## UnionEffectContainerOptions对象说明

设置UnionEffectContainer构造参数。

**系统接口：** 此接口为系统接口。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称        | 类型                                    | 只读 | 可选 | 说明                                                     |
| ----------- | --------------------------------------- | ---- | ---------- | ---------------------------------------------- |
| spacing | number | 否 | 是  | spacing表示后代组件发生融合形变的程度。它不代表实际的间距，只有设置了使用祖先组件UnionEffectContainer融合效果的后代组件且后代组件靠近到一定程度时才会发生融合。<br>**说明：**<br>设置的spacing大于0，且设置了祖先组件UnionEffectContainer融合效果的后代组件彼此靠近到一定程度，这些后代组件会开始相互融合形变，且随着距离的变近融合形变的效果越强。该值越大，后代组件彼此靠近时，它们的融合会越早开始，越容易发生融合形变。<br>默认值：0，此时后代组件形状会融合在一起，但不会有形变效果。<br>取值范围：[0, +∞)。小于0时按0处理。 |

## 事件

支持通用事件。

## 属性

支持通用属性，支持宽高设置。

> **说明：**
>
> - 融合过程中容器会变成粘连的非线性形变效果，边框会变成融合后的粘连效果，故与边框相关的能力在融合形变过程中会发生变化，未支持融合形变效果的边框属性可能无法正常生效。目前与边框相关且支持融合形变效果的属性：阴影[shadow](ts-universal-attributes-image-effect.md#shadow)、背景色[backgroundColor](ts-universal-attributes-background.md#backgroundcolor)、点光源[pointLight](#pointlight)。上述效果会绘制在融合后的形状上，属于UnionEffectContainer的绘制部分。
>
> - 在该组件上设置上述与边框相关支持融合形变效果的属性，绘制体现在该组件上，如果后代组件设置了同一个属性，实际上两个属性的设置相互独立，会绘制两次，一次发生在UnionEffectContainer组件的绘制中，一次发生在后代组件自身的属性绘制中。在无特殊设计需求时，不需要在使用祖先组件UnionEffectContainer融合效果的后代组件中设置同一个支持融合形变效果的属性，避免融合效果因双重绘制而出现视觉异常。

### pointLight

pointLight(light: PointLightStyle)

设置点光源样式。点光源是从指定位置发出的光源，在融合后的形状上产生光照高亮效果。该属性效果绘制在融合后的形状上，需要后代组件使用[useUnionEffect](ts-universal-attributes-use-union-effect-sys.md#useunioneffect)才能生效。通常情况下不需要在使用融合效果的后代组件中同时设置pointLight属性，避免融合效果劣化。

**系统接口：** 此接口为系统接口。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：** 

| 参数名 | 类型                                                         | 必填 | 说明         |
| ------ | ------------------------------------------------------------ | ---- | ------------ |
| light  | [PointLightStyle](ts-universal-attributes-point-light-style-sys.md#pointlightstyle) | 是   | 点光源样式，用于设置UnionEffectContainer融合形状上的点光源效果。pointLight为与边框相关且支持融合形变效果的属性，效果绘制在融合后的形状上；不建议在使用融合效果的后代组件中同时设置pointLight，避免融合效果劣化。 |

### unionMode

unionMode(mode: UnionMode)

设置融合效果模式。需后代组件设置[useUnionEffect](ts-universal-attributes-use-union-effect-sys.md#useunioneffect)属性，融合效果才能生效。当融合效果模式为[UnionMode.GRAVITY_UNION](#unionmode枚举说明)时，需配合[useUnionEffect](ts-universal-attributes-use-union-effect-sys.md#useunioneffect-1)并设置[GravityCenterOptions](ts-universal-attributes-use-union-effect-sys.md#gravitycenteroptions)的gravityCenter为true才能生效。

**起始版本：** 26.0.0

**系统接口：** 此接口为系统接口。

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型                                                         | 必填 | 说明         |
| ------ | ------------------------------------------------------------ | ---- | ------------ |
| mode  | [UnionMode](#unionmode枚举说明) | 是   | 融合效果模式。需配合后代组件使用[useUnionEffect](ts-universal-attributes-use-union-effect-sys.md#useunioneffect)属性才能生效。设置[UnionMode.GRAVITY_UNION](#unionmode枚举说明)时，需结合[useUnionEffect](ts-universal-attributes-use-union-effect-sys.md#useunioneffect-1)属性并设置[GravityCenterOptions](ts-universal-attributes-use-union-effect-sys.md#gravitycenteroptions)的gravityCenter为true才能生效。 |

## UnionMode枚举说明

融合效果模式枚举。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**系统接口：** 此接口为系统接口。

| 名称           | 值  | 说明                         |
| -------------- | --- |---------------------------- |
| SMOOTH_UNION       | 0   | 平滑的融合形变效果，适用于需要平滑过渡和自然连接的融合场景。<br>**说明：**<br>设置该类型时，需后代组件设置[useUnionEffect](ts-universal-attributes-use-union-effect-sys.md#useunioneffect)属性才能产生融合效果。            |
| GRAVITY_UNION      | 1   | 引力作用下的融合形变效果，适用于需要模拟引力吸引效果的融合场景，如元素间存在吸引和靠近趋势的视觉表现。<br>**说明：**<br>设置该类型时，需配合[useUnionEffect](ts-universal-attributes-use-union-effect-sys.md#useunioneffect-1)并设置[GravityCenterOptions](ts-universal-attributes-use-union-effect-sys.md#gravitycenteroptions)的gravityCenter为true才能生效；不满足上述条件时，GRAVITY_UNION效果不生效。            |

## 示例

### 示例1（设置融合形变效果）

该示例主要演示如何使用[UnionEffectContainer](#unioneffectcontainer)组件，通过改变spacing值或后代组件的距离，产生融合形变效果。

```ts
// UnionEffectContainerPage.ets
@Entry
@Component
struct UnionEffectContainerPage {
  @State spacing: number = 0;
  @State translateY: number = 0;

  build() {
    Column() {
      Column() {
        UnionEffectContainer({ spacing: 10 }) {
          Column({ space: 50 }) {
            Column()
              .width(100)
              .height(100)
              .margin({ top: 10 })
              .borderRadius(50)
              .useUnionEffect(true) // 设置useUnionEffect属性，使用融合效果
              .translate({ y: this.translateY })

            Column()
              .width(200)
              .height(100)
              .useUnionEffect(true)
          }
          .width('100%')
        }
        .width('100%')
        .height('80%')
        .backgroundColor('#2787d9') // 设置融合效果支持的属性，如背景色

        Row({ space: 30 }) {
          Text('translate:')
          Button('+10')
            .onClick(() => {
              this.getUIContext().animateTo({ duration: 200 }, () => {
                this.translateY += 10; // 改变后代组件的距离
              });
            })
          Button('-10')
            .onClick(() => {
              this.getUIContext().animateTo({ duration: 200 }, () => {
                this.translateY -= 10; // 改变后代组件的距离
              });
            })
        }
        .width('100%')
        .height('20%')
      }.width('90%')
      .height('40%')
      .borderWidth(1)
      .margin({ top: 10 })

      Column() {
        UnionEffectContainer({ spacing: this.spacing }) {
          Column({ space: 50 }) {
            Column()
              .width(100)
              .height(100)
              .margin({ top: 10 })
              .borderRadius(50)
              .useUnionEffect(true) // 设置useUnionEffect属性，使用融合效果

            Column()
              .width(200)
              .height(100)
              .useUnionEffect(true)
          }
          .width('100%')
        }
        .width('100%')
        .height('80%')
        .backgroundColor('#2787d9') // 设置融合效果支持的属性，如背景色

        Row({ space: 30 }) {
          Text('spacing:')
          Button('+20')
            .onClick(() => {
              this.getUIContext().animateTo({ duration: 200 }, () => {
                this.spacing += 20; // 改变融合形变的程度
              });
            })
          Button('-20')
            .onClick(() => {
              if (this.spacing <= 0) {
                return;
              }
              this.getUIContext().animateTo({ duration: 200 }, () => {
                this.spacing -= 20; // 改变融合形变的程度
                if (this.spacing < 0) {
                  this.spacing = 0;
                }
              });
            })
        }
        .width('100%')
        .height('20%')
      }.width('90%')
      .height('40%')
      .borderWidth(1)
      .margin({ top: 10 })
    }.width('100%')
    .height('100%')
  }
}
```

![unionEffectContainerDemo](figures/unionEffectContainerDemo.gif)

### 示例2（设置不同类型的融合形变效果）

该示例主要演示如何使用[unionMode](#unionmode)接口，通过设置不同的融合类型，产生不同的融合形变效果。

从API版本26.0.0开始，新增unionMode接口。

```ts
// UnionEffectContainerPage.ets
@Entry
@Component
struct UnionEffectContainerPage {
  @State translateY1: number = 0;
  @State translateY2: number = 0;

  build() {
    Column() {
      Column() {
        Text('UnionMode.SMOOTH_UNION')
        UnionEffectContainer({ spacing: 10 }) {
          Column({ space: 50 }) {
            Column()
              .width(100)
              .height(100)
              .margin({ top: 10 })
              .borderRadius(50)
              .useUnionEffect(true) // 设置useUnionEffect属性，使用融合效果
              .translate({ y: this.translateY1 })

            Column()
              .width(200)
              .height(100)
              .useUnionEffect(true)
          }
          .width('100%')
        }
        .width('100%')
        .height('75%')
        .backgroundColor('#2787d9') // 设置融合效果支持的属性，如背景色
        .unionMode(UnionMode.SMOOTH_UNION)

        Row({ space: 30 }) {
          Text('translate:')
          Button('+10')
            .onClick(() => {
              this.getUIContext().animateTo({ duration: 200 }, () => {
                this.translateY1 += 10; // 改变相邻组件的距离
              });
            })
          Button('-10')
            .onClick(() => {
              this.getUIContext().animateTo({ duration: 200 }, () => {
                this.translateY1 -= 10; // 改变相邻组件的距离
              });
            })
        }
        .width('100%')
        .height('20%')
      }.width('90%')
      .height('45%')
      .borderWidth(1)
      .margin({ top: 10 })

      Column() {
        Text('UnionMode.GRAVITY_UNION')
        UnionEffectContainer({ spacing: 1000 }) {
          Column({ space: 50 }) {
            Column()
              .width(40)
              .height(40)
              .margin({ top: 10 })
              .borderRadius(20)
              .useUnionEffect(true, {gravityCenter: true, gravityIntensity: 60}) // 设置useUnionEffect属性，使用融合效果
              .translate({ y: this.translateY2 })

            Column()
              .width(200)
              .height(100)
              .useUnionEffect(true)
          }
          .width('100%')
        }
        .width('100%')
        .height('75%')
        .backgroundColor('#2787d9') // 设置融合效果支持的属性，如背景色
        .unionMode(UnionMode.GRAVITY_UNION)

        Row({ space: 30 }) {
          Text('translate:')
          Button('+10')
            .onClick(() => {
              this.getUIContext().animateTo({ duration: 200 }, () => {
                this.translateY2 += 10; // 改变相邻组件的距离
              });
            })
          Button('-10')
            .onClick(() => {
              this.getUIContext().animateTo({ duration: 200 }, () => {
                this.translateY2 -= 10; // 改变相邻组件的距离
              });
            })
        }
        .width('100%')
        .height('20%')
      }.width('90%')
      .height('45%')
      .borderWidth(1)
      .margin({ top: 10 })
    }.width('100%')
    .height('100%')
  }
}
```

![unionModeDemo](figures/unionModeDemo.gif)