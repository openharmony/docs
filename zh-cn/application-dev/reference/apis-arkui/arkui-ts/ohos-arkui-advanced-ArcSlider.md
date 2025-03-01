# ArcSlider

弧形滑动条组件，通常用于在圆形屏幕中快速调节设置值，如音量调节、亮度调节等应用场景。

>  **说明：**
>
>  该组件从API Version 16开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。

## 导入模块

```ts
import {
  ArcSlider,
  ArcSliderPosition,
  ArcSliderOptions,
  ArcSliderValueOptions,
  ArcSliderLayoutOptions,
  ArcSliderStyleOptions,
  ArcSliderValueOptionsConstructorOptions,
  ArcSliderLayoutOptionsConstructorOptions,
  ArcSliderStyleOptionsConstructorOptions,
  ArcSliderOptionsConstructorOptions
} from '@kit.ArkUI'
```

## 子组件

无

## 属性

不支持[通用属性](ts-component-general-attributes.md)。

## 事件

不支持[通用事件](ts-component-general-events.md)。

## ArcSlider

ArcSlider({options?: ArcSliderOptions})

创建ArcSlider实例，入参是弧形进度条配置选项。

**装饰器类型：**@ComponentV2

**原子化服务API：** 从API version 16开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Circle

**参数：** 

| 名称    | 类型                                  | 必填 | 装饰器类型   | 说明                                                         |
| ------- | ------------------------------------- | ---- | ------------ | ------------------------------------------------------------ |
| options | [ArcSliderOptions](#arcslideroptions) | 否   | @ComponentV2 | 配置弧形滑动条的参数。<br/>默认值：[ArcSliderOptions](#arcslideroptions)的各项子属性均取其默认值 |

## ArcSliderOptions

配置弧形Slider的信息。

**装饰器类型：**@ComponentV2

**原子化服务API：** 从API version 16开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Circle

| 名称 | 类型 | 必填 | 装饰器类型 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| valueOptions | [ArcSliderValueOptions](#arcslidervalueoptions) | 否 | @Trace | 配置弧形Slider的数值信息。<br/>默认值：[ArcSliderValueOptions](#arcslidervalueoptions)的各项子属性均取其默认值 |
| layoutOptions | [ArcSliderLayoutOptions](#arcsliderlayoutoptions) | 否 | @Trace | 配置弧形Slider的布局信息。<br/>默认值：[ArcSliderLayoutOptions](#arcsliderlayoutoptions)的各项子属性均取其默认值 |
| styleOptions | [ArcSliderStyleOptions](#arcsliderstyleoptions) | 否 | @Trace | 配置弧形Slider的样式信息。<br/>默认值：[ArcSliderStyleOptions](#arcsliderstyleoptions)的各项子属性均取其默认值 |
| digitalCrownSensitivity | [CrownSensitivity](ts-appendix-enums.md#crownsensitivity16) | 否 | @Trace | 设置旋转表冠的灵敏度。<br/>默认值：CrownSensitivity.MEDIUM |
| onTouch | [ArcSliderTouchHandler](#arcslidertouchhandler) | 否 | @Trace | 弧形Slider被触摸时，告知应用。<br/>默认值：不传入的情况，无回调 |
| onChange | [ArcSliderChangeHandler](#arcsliderchangehandler) | 否 | @Trace | 弧形Slider的进度值发生变化时，告知应用。<br/>默认值：不传入的情况，无回调 |

### constructor

constructor(options?: ArcSliderOptionsConstructorOptions)

ArcSliderOptions的构造函数。

**原子化服务API：** 从API version 16开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Circle

**参数：**

| 名称    | 类型                                                         | 必填 | 说明                         |
| ------- | ------------------------------------------------------------ | ---- | ---------------------------- |
| options | [ArcSliderOptionsConstructorOptions](#arcslideroptionsconstructoroptions) | 否   | ArcSliderOptions的构造信息。 |

## ArcSliderValueOptions

配置弧形Slider的数值信息。

**装饰器类型：**@ComponentV2

**原子化服务API：** 从API version 16开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Circle

| 名称  | 类型   | 必填 | 装饰器类型 | 说明                                                         |
| ----- | ------ | ---- | ---------- | ------------------------------------------------------------ |
| progress | number | 否   | @Trace     | 设置当前进度值。<br />默认值：与参数min的取值一致            |
| min   | number | 否   | @Trace     | 设置最小值。<br />默认值：0                                  |
| max   | number | 否   | @Trace     | 设置最大值。<br />默认值：100<br />**说明：**<br/>当出现异常情况min >= max时，min取默认值0，max取默认值100。<br/>progress不在[min, max]范围之内，取min或者max，靠近min取min，靠近max取max。 |

### constructor

constructor(options?: ArcSliderValueOptionsConstructorOptions)

ArcSliderValueOptions的构造函数。

**原子化服务API：** 从API version 16开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Circle

**参数：**

| 名称    | 类型                                                         | 必填 | 说明                              |
| ------- | ------------------------------------------------------------ | ---- | --------------------------------- |
| options | [ArcSliderValueOptionsConstructorOptions](#arcslidervalueoptionsconstructoroptions) | 否   | ArcSliderValueOptions的构造信息。 |

## ArcSliderLayoutOptions

配置弧形Slider的布局信息。

**装饰器类型：**@ComponentV2

**原子化服务API：** 从API version 16开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Circle

| 名称     | 类型                                    | 必填 | 装饰器类型 | 说明                                                         |
| -------- | --------------------------------------- | ---- | ---------- | ------------------------------------------------------------ |
| reverse  | boolean                                 | 否   | @Trace     | 设置弧形Slider取值范围是否反向。<br />默认值：true。表示从下往上滑动。 |
| position | [ArcSliderPosition](#arcsliderposition) | 否   | @Trace     | 弧形Slider的屏幕显示位置。<br />默认值：ArcSliderPosition.RIGHT |

### constructor

constructor(options?: ArcSliderLayoutOptionsConstructorOptions)

ArcSliderLayoutOptions的构造函数。

**原子化服务API：** 从API version 16开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Circle

**参数：**

| 名称    | 类型                                                         | 必填 | 说明                               |
| ------- | ------------------------------------------------------------ | ---- | ---------------------------------- |
| options | [ArcSliderLayoutOptionsConstructorOptions](#arcsliderlayoutoptionsconstructoroptions) | 否   | ArcSliderLayoutOptions的构造信息。 |

## ArcSliderStyleOptions

配置弧形Slider的样式信息。

**装饰器类型：**@ComponentV2

**原子化服务API：** 从API version 16开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Circle

| 名称                 | 类型   | 必填 | 装饰器类型 | 说明                                                         |
| -------------------- | ------ | ---- | ---------- | ------------------------------------------------------------ |
| trackThickness       | number | 否   | @Trace     | 正常状态下弧形Slider的描边粗细，单位：vp。<br />默认值：5<br />取值范围：最小可取5，最大可取16，异常值按默认值处理。 |
| activeTrackThickness | number | 否   | @Trace     | 放大状态下弧形Slider的描边粗细，单位：vp。<br />默认值：24<br />取值范围：最小可取24，最大可取36，异常值按默认值处理。 |
| trackColor           | string | 否   | @Trace     | 设置描边背景色。<br />默认值：#33FFFFFF                      |
| selectedColor        | string | 否   | @Trace     | 设置描边高亮色。<br />默认值：#FF5EA1FF                      |
| trackBlur            | number | 否   | @Trace     | 设置描边背景模糊值，单位：vp。<br />默认值：20               |

### constructor

constructor(options?: ArcSliderStyleOptionsConstructorOptions)

ArcSliderStyleOptions的构造函数。

**原子化服务API：** 从API version 16开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Circle

**参数：**

| 名称    | 类型                                                         | 必填 | 说明                              |
| ------- | ------------------------------------------------------------ | ---- | --------------------------------- |
| options | [ArcSliderStyleOptionsConstructorOptions](#arcsliderstyleoptionsconstructoroptions) | 否   | ArcSliderStyleOptions的构造信息。 |

## ArcSliderPosition

配置弧形Slider的屏幕显示位置。

**原子化服务API：** 从API version 16开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Circle

| 名称  | 值   | 说明                             |
| ----- | ---- | -------------------------------- |
| LEFT  | 0    | 弧形Slider的屏幕显示位置在左侧。 |
| RIGHT | 1    | 弧形Slider的屏幕显示位置在右侧。 |

## ArcSliderTouchHandler

type ArcSliderTouchHandler = (event: TouchEvent) => void

弧形Slider被触摸时，告知应用。

**原子化服务API：** 从API version 16开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Circle

**参数：**

| 参数名 | 类型                                                         | 必填 | 说明                 |
| ------ | ------------------------------------------------------------ | ---- | -------------------- |
| event  | [TouchEvent](ts-universal-events-touch.md#touchevent对象说明) | 否   | 获得TouchEvent对象。 |

## ArcSliderChangeHandler

type ArcSliderChangeHandler = (progress: number) => void

弧形Slider的进度值发生变化时，告知应用。

**原子化服务API：** 从API version 16开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Circle

**参数：**

| 名称     | 类型   | 必填 | 说明                 |
| -------- | ------ | ---- | -------------------- |
| progress | number | 否   | Slider当前的进度值。 |

## ArcSliderOptionsConstructorOptions

ArcSliderOptions的构造信息。

**原子化服务API：** 从API version 16开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Circle

**参数：**

| 名称                    | 类型                                                        | 必填 | 说明                                                         |
| ----------------------- | ----------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| valueOptions            | [ArcSliderValueOptions](#arcslidervalueoptions)             | 否   | 配置弧形Slider的数值信息。<br/>默认值：[ArcSliderValueOptions](#arcslidervalueoptions)的各项子属性均取其默认值 |
| layoutOptions           | [ArcSliderLayoutOptions](#arcsliderlayoutoptions)           | 否   | 配置弧形Slider的布局信息。<br/>默认值：[ArcSliderLayoutOptions](#arcsliderlayoutoptions)的各项子属性均取其默认值 |
| styleOptions            | [ArcSliderStyleOptions](#arcsliderstyleoptions)             | 否   | 配置弧形Slider的样式信息。<br/>默认值：[ArcSliderStyleOptions](#arcsliderstyleoptions)的各项子属性均取其默认值 |
| digitalCrownSensitivity | [CrownSensitivity](ts-appendix-enums.md#crownsensitivity16) | 否   | 设置旋转表冠的灵敏度。<br/>默认值：CrownSensitivity.MEDIUM   |
| onTouch                 | [ArcSliderTouchHandler](#arcslidertouchhandler)             | 否   | 弧形Slider被触摸时，告知应用。<br/>默认值：不传入的情况，无回调 |
| onChange                | [ArcSliderChangeHandler](#arcsliderchangehandler)           | 否   | 弧形Slider的进度值发生变化时，告知应用。<br/>默认值：不传入的情况，无回调 |

## ArcSliderValueOptionsConstructorOptions

ArcSliderValueOptions的构造信息。

**原子化服务API：** 从API version 16开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Circle

**参数：**

| 名称  | 类型   | 必填 | 装饰器类型 | 说明                                                         |
| ----- | ------ | ---- | ---------- | ------------------------------------------------------------ |
| progress | number | 否   | @Trace     | 设置当前进度值。<br />默认值：与参数min的取值一致            |
| min   | number | 否   | @Trace     | 设置最小值。<br />默认值：0                                  |
| max   | number | 否   | @Trace     | 设置最大值。<br />默认值：100<br />**说明：**<br/>当出现异常情况min >= max时，min取默认值0，max取默认值100。<br/>progress不在[min, max]范围之内，取min或者max，靠近min取min，靠近max取max。 |

## ArcSliderLayoutOptionsConstructorOptions

ArcSliderLayoutValueOptions的构造信息。

**原子化服务API：** 从API version 16开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Circle

**参数：**

| 名称     | 类型                                    | 必填 | 说明                                                         |
| -------- | --------------------------------------- | ---- | ------------------------------------------------------------ |
| reverse  | boolean                                 | 否   | 设置弧形Slider取值范围是否反向。<br />默认值：true。表示从下往上滑动。 |
| position | [ArcSliderPosition](#arcsliderposition) | 否   | 弧形Slider的屏幕显示位置。<br />默认值：ArcSliderPosition.RIGHT |

## ArcSliderStyleOptionsConstructorOptions

ArcSliderStyleOptions的构造信息。

**原子化服务API：** 从API version 16开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Circle

**参数：**

| 名称                 | 类型   | 必填 | 说明                                                         |
| -------------------- | ------ | ---- | ------------------------------------------------------------ |
| trackThickness       | number | 否   | 正常状态下弧形Slider的描边粗细，单位：vp。<br />默认值：5<br />取值范围：最小可取5，最大可取16，异常值按默认值处理。 |
| activeTrackThickness | number | 否   | 放大状态下弧形Slider的描边粗细，单位：vp。<br />默认值：24<br />取值范围：最小可取24，最大可取36，异常值按默认值处理。 |
| trackColor           | string | 否   | 设置描边背景色。<br />默认值：#33FFFFFF                      |
| selectedColor        | string | 否   | 设置描边高亮色。<br />默认值：#FF5EA1FF                      |
| trackBlur            | number | 否   | 设置描边背景模糊值，单位：vp。<br />默认值：20               |

## 示例

```ts
// xxx.ets
import {
  ArcSlider,
  ArcSliderPosition,
  ArcSliderOptions,
  ArcSliderValueOptions,
  ArcSliderLayoutOptions,
  ArcSliderStyleOptions,
  ArcSliderValueOptionsConstructorOptions,
  ArcSliderLayoutOptionsConstructorOptions,
  ArcSliderStyleOptionsConstructorOptions,
  ArcSliderOptionsConstructorOptions
} from '@kit.ArkUI'

@Entry
@ComponentV2
struct ArcSliderExample {
  valueOptionsConstructorOptions: ArcSliderValueOptionsConstructorOptions = {
    progress: 60,
    min: 10,
    max: 110
  }

  layoutOptionsConstructorOptions: ArcSliderLayoutOptionsConstructorOptions = {
    reverse: true,
    position: ArcSliderPosition.RIGHT
  }
  styleOptionsConstructorOptions: ArcSliderStyleOptionsConstructorOptions = {
    trackThickness: 8,
    activeTrackThickness: 30,
    trackColor: '#ffd5d5d5',
    selectedColor: '#ff2787d9',
    trackBlur: 20
  }
  valueOptions: ArcSliderValueOptions = new ArcSliderValueOptions(this.valueOptionsConstructorOptions)
  layoutOptions: ArcSliderLayoutOptions = new ArcSliderLayoutOptions(this.layoutOptionsConstructorOptions)
  styleOptions: ArcSliderStyleOptions = new ArcSliderStyleOptions(this.styleOptionsConstructorOptions)
  arcSliderOptionsConstructorOptions: ArcSliderOptionsConstructorOptions = {
    valueOptions: this.valueOptions,
    layoutOptions: this.layoutOptions,
    styleOptions: this.styleOptions,
    digitalCrownSensitivity:CrownSensitivity.LOW,
    onTouch: (event: TouchEvent) => {
    },
    onChange: (progress: number) => {
    }
  }
  arcSliderOptions: ArcSliderOptions = new ArcSliderOptions(this.arcSliderOptionsConstructorOptions)

  build() {
    Column() {
      ArcSlider({ options: this.arcSliderOptions })}
      .width('100%')
  }
}
```

![arcslider](figures/arcslider.gif)
