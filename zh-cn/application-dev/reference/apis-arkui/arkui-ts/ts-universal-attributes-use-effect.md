# 特效绘制合并
<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @hehongyang3-->
<!--Designer: @hehongyang3-->
<!--Tester: @lxl007-->
<!--Adviser: @Brilliantry_Rui-->

用于设置组件是否应用效果模板，对背景模糊等特效进行绘制合并。

> **说明：**
>
> - 从API version 12开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。
>
> - 本模块接口仅可在Stage模型下使用。

## useEffect

useEffect(value: boolean): T

用于控制组件是否继承<!--Del-->父级[EffectComponent](ts-container-effectcomponent-sys.md)的<!--DelEnd-->特效属性参数，对背景模糊等特效进行绘制合并。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| value | boolean | 是 | 控制组件是否继承<!--Del-->父级[EffectComponent](ts-container-effectcomponent-sys.md)的<!--DelEnd-->特效属性参数，从而合并绘制特效。<br>useEffect为true时子组件继承<!--Del-->父级[EffectComponent](ts-container-effectcomponent-sys.md)的<!--DelEnd-->特效属性参数，为false时子组件不继承<!--Del-->父级[EffectComponent](ts-container-effectcomponent-sys.md)的<!--DelEnd-->特效属性参数。<br>默认值：false|

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| T | 返回当前组件，用于链式调用。 |

## useEffect<sup>14+</sup>

useEffect(useEffect: boolean, effectType: EffectType): T

用于设置组件是否应用<!--Del-->父级[EffectComponent](ts-container-effectcomponent-sys.md)或<!--DelEnd-->窗口定义的效果模板。effectType为DEFAULT时，必须在EffectComponent的子组件上使用且EffectComponent需配置特效属性才能生效；effectType为WINDOW_EFFECT时，需配合窗口效果模板使用。不在对应容器内使用时，useEffect将不产生任何效果。效果模板是一组预定义的视觉特效参数（包括模糊半径、饱和度、亮度、颜色），应用于组件以实现统一的视觉特效风格。

**原子化服务API：** 从API version 14开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名     | 类型                                                         | 必填 | 说明                                                         |
| ---------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| useEffect  | boolean                                                      | 是   | 控制组件是否应用<!--Del-->父级EffectComponent或<!--DelEnd-->窗口定义的效果模板，从而合并绘制特效。<br>useEffect为true时表示应用<!--Del-->父级EffectComponent或<!--DelEnd-->窗口定义的效果模板，为false时不应用<!--Del-->父级EffectComponent或<!--DelEnd-->窗口定义的效果模板。<br>默认值：false |
| effectType | [EffectType](#effecttype14) | 是   | 设置组件应用<!--Del-->父级EffectComponent或<!--DelEnd-->窗口定义的效果模板，仅在useEffect为true时生效。<br>默认值：EffectType.DEFAULT |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| T | 返回当前组件，用于链式调用。 |

## useEffect<sup>18+</sup>

useEffect(useEffect: Optional\<boolean>, effectType?: EffectType): T

用于设置组件是否应用<!--Del-->父级[EffectComponent](ts-container-effectcomponent-sys.md)或<!--DelEnd-->窗口定义的效果模板。与[useEffect<sup>14+</sup>](#useeffect14)相比，useEffect参数新增了对undefined类型的支持。effectType为DEFAULT时，必须在EffectComponent的子组件上使用且EffectComponent需配置特效属性才能生效；effectType为WINDOW_EFFECT时，需配合窗口效果模板使用。不在对应容器内使用时，useEffect将不产生任何效果。

**原子化服务API：** 从API version 18开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| useEffect | [Optional](ts-universal-attributes-custom-property.md#optionalt)\<boolean> | 是 | 控制组件是否应用<!--Del-->父级EffectComponent或<!--DelEnd-->窗口定义的效果模板。<br>useEffect为true时表示应用<!--Del-->父级EffectComponent或<!--DelEnd-->窗口定义的效果模板，具体应用哪种效果模板由effectType参数决定。<br>useEffect为false时表示不应用效果模板。<br>默认值：false<br>当useEffect的值为undefined时，维持该属性上一次生效的取值不变。 |
| effectType | [EffectType](#effecttype14) | 否 | 指定效果模板的类型，应用<!--Del-->父级EffectComponent定义的或<!--DelEnd-->窗口定义的效果模板。<br>默认值：EffectType.DEFAULT|

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| T | 返回当前组件，用于链式调用。 |

## EffectType<sup>14+</sup>

效果模板类型的枚举值。效果模板为预设的视觉效果参数配置，包含模糊半径、饱和度、亮度和颜色等参数。

**原子化服务API：** 从API version 14开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称     | 值   | 说明                   |
| -------- | ---- | ---------------------- |
| DEFAULT  | 0   | 使用<!--Del-->父级EffectComponent定义的<!--DelEnd-->效果模板来渲染组件特效。 |
| WINDOW_EFFECT  | 1   | 使用窗口定义的效果模板来渲染组件特效。 |

效果模板

|  设备类型    | 模糊半径（单位：px）   | 饱和度                 |  亮度  |  颜色  |
| -------- | ---- | ---------------------- | -------- | -------- |
| 移动设备  | 0   | 0 | 0 | '#ffffffff'，显示为白色。 |
| 2in1设备：深色模式  | 80   | 1.5 | 1.0 | '#e52e3033'，显示为半透明的深灰色。 |
| 2in1设备：浅色模式  | 80   | 1.9 | 1.0 | '#e5ffffff'，显示为半透明的白色。 |
| Tablet设备  | 0   | 0 | 0 | '#ffffffff'，显示为白色。 |

<!--Del-->
## 示例

该示例演示背景模糊等特效的绘制合并。

<!--code_no_check-->

```ts
// Index.ets
@Entry
@Component
struct Index {
  @State isUse: boolean = true;

  build() {
    Stack() {
      Image($r('app.media.mountain'))
        .autoResize(true)
      EffectComponent() {
        Column({ space: 20 }) {
           Column() {
           }
           .position({ x: 0, y: 0 })
           .width(150)
           .height(800)
           .useEffect(this.isUse, EffectType.WINDOW_EFFECT)
         
           Column() {
           }
           .position({ x: 200, y: 20 })
           .width(150)
           .height(300)
           .useEffect(this.isUse, EffectType.DEFAULT)

           Column() {
           }
           .position({ x: 400, y: 20 })
           .width(150)
           .height(300)
           .useEffect(this.isUse)
        }
        .width('100%')
        .height('100%')
      }
      .backgroundBlurStyle(BlurStyle.Thin)

       Column() {
       }
        .position({ x: 600, y: 0 })
        .width(150)
        .height(800)
        .useEffect(this.isUse, EffectType.WINDOW_EFFECT)

      Row() {
        Button('useEffect')
        .margin(30)
        .onClick(() => {
          this.isUse = !this.isUse;
        })
      }
      .position({ x: 300, y: 450 })
    }
    .backgroundColor(Color.Black)
    .width('100%')
  }
}
```

![zh_image_useeffect_effecttype](figures/image-useeffect-effecttype.png)
<!--DelEnd-->
