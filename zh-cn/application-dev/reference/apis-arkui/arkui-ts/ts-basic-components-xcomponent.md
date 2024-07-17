# XComponent

提供用于图形绘制和媒体数据写入的Surface，XComponent负责将其嵌入到视图中，支持应用自定义Surface位置和大小。

> **说明：**
>
> 该组件从API Version 8 开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。


## 子组件
无

## 接口

### XComponent<sup>12+</sup>

XComponent(options: XComponentOptions)

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数:**

| 参数名  | 参数类型                                | 必填 | 描述                           |
| ------- | --------------------------------------- | ---- | ------------------------------ |
| options | [XComponentOptions](#xcomponentoptions12) | 是   | 定义XComponent的具体配置参数。 |

### XComponent<sup>10+</sup>

XComponent(value: {id: string, type: XComponentType, libraryname?: string, controller?: XComponentController})

该接口不再演进，推荐使用[XComponent(options: XComponentOptions)](#xcomponent12)。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**参数:** 

| 参数名      | 参数类型                                      | 必填 | 描述                                                         |
| ----------- | --------------------------------------------- | ---- | ------------------------------------------------------------ |
| id          | string                                        | 是   | 组件的唯一标识，支持最大的字符串长度128。                    |
| type        | [XComponentType](#xcomponenttype10枚举说明)   | 是   | 用于指定XComponent组件类型。                                 |
| libraryname | string                                        | 否   | 用Native层编译输出动态库名称，仅类型为SURFACE或TEXTURE时有效。 |
| controller  | [XComponentcontroller](#xcomponentcontroller) | 否   | 给组件绑定一个控制器，通过控制器调用组件方法，仅类型为SURFACE或TEXTURE时有效。 |

### XComponent<sup>(deprecated)</sup>

XComponent(value: {id: string, type: string, libraryname?: string, controller?: XComponentController})

**说明：**

从API version 12开始废弃，建议使用[XComponent(options: XComponentOptions)](#xcomponent12)替代。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**参数:** 

| 参数名      | 参数类型                                      | 必填 | 描述                                                         |
| ----------- | --------------------------------------------- | ---- | ------------------------------------------------------------ |
| id          | string                                        | 是   | 组件的唯一标识，支持最大的字符串长度128。                    |
| type        | string                                        | 是   | 用于指定XComponent组件类型，可选值仅有两个为：<br/>-"surface"：用于EGL/OpenGLES和媒体数据写入，开发者定制的绘制内容单独展示到屏幕上。<br/>-"component"<sup>9+</sup> ：XComponent将变成一个容器组件，并可在其中执行非UI逻辑以动态加载显示内容。<br/>其他值均会被视为"surface"类型 |
| libraryname | string                                        | 否   | 应用Native层编译输出动态库名称，仅XComponent类型为"surface"时有效。 |
| controller  | [XComponentcontroller](#xcomponentcontroller) | 否   | 给组件绑定一个控制器，通过控制器调用组件方法，仅XComponent类型为"surface"时有效。 |

## XComponentOptions<sup>12+</sup>

定义XComponent的具体配置参数。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

| 名称 | 参数类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| type | [XComponentType](#xcomponenttype10枚举说明)         | 是   | 用于指定XComponent组件类型。 |
| controller | [XComponentcontroller](#xcomponentcontroller) | 是 | 给组件绑定一个控制器，通过控制器调用组件方法，仅类型为SURFACE或TEXTURE时有效。 |
| imageAIOptions | [ImageAIOptions](ts-image-common.md#imageaioptions) | 否 | 给组件设置一个AI分析选项，通过此项可配置分析类型或绑定一个分析控制器。 |

## XComponentType<sup>10+</sup>枚举说明

| 名称                             | 描述                                                         |
| -------------------------------- | ------------------------------------------------------------ |
| SURFACE                          | 用于EGL/OpenGLES和媒体数据写入，开发者定制的绘制内容单独展示到屏幕上。<br/>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 |
| COMPONENT<sup>(deprecated)</sup> | XComponent将变成一个容器组件，并可在其中执行非UI逻辑以动态加载显示内容。<br/>**说明：**<br/>从API version 12 开始，该接口废弃，建议使用其他容器组件替代。<br/>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 |
| TEXTURE                          | 用于EGL/OpenGLES和媒体数据写入，开发者定制的绘制内容会和XComponent组件的内容合成后展示到屏幕上。<br/>**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。 |
| NODE                             | 用于Native UI节点的占位容器，开发者通过Native API 开发的页面组件可展示在此容器区域内。<br/>**说明：**<br/>该类型不再演进，推荐使用[ContentSlot](../../../quick-start/arkts-rendering-control-contentslot.md)占位组件管理Native API创建的组件。<br/>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。 |

## 属性
- XComponent显示的内容，可由开发者自定义绘制，通用属性中的[背景设置](ts-universal-attributes-background.md)、[透明度设置](ts-universal-attributes-opacity.md)和[图像效果](ts-universal-attributes-image-effect.md)按照type类型有限支持。

- type为SURFACE时仅支持[图像效果](ts-universal-attributes-image-effect.md)中的shadow和BlendMode属性，建议使用EGL/OpenGLES提供的接口设置相关内容。

  > **说明：**
  >
  > 从API version 11开始，type为SURFACE时支持[背景颜色设置](ts-universal-attributes-background.md#backgroundcolor)。

- type为TEXTURE时通用属性可以支持[背景颜色设置](ts-universal-attributes-background.md#backgroundcolor)、[透明度设置](ts-universal-attributes-opacity.md)和[图像效果](ts-universal-attributes-image-effect.md)中的shadow和BlendMode属性，[除颜色外的背景设置](ts-universal-attributes-background.md)和其他[图像效果](ts-universal-attributes-image-effect.md)暂不支持，建议使用EGL/OpenGLES提供的接口设置相关内容。

### enableAnalyzer<sup>12+</sup>

enableAnalyzer(enable: boolean)

设置组件支持AI分析，需要搭配XComponentController的[StartImageAnalyzer](#startimageanalyzer12)和[StopImageAnalyzer](#stopimageanalyzer12)一起使用。
不能和[overlay](ts-universal-attributes-overlay.md)属性同时使用，两者同时设置时overlay中CustomBuilder属性将失效。该特性依赖设备能力。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| enable | boolean | 是 | 是否启用图像分析功能 |

  > **说明：**
  >
  > 仅type为SURFACE和TEXTURE时该功能有效。

## 事件

从API version 12开始，type为SURFACE或TEXTURE时，支持[通用事件](ts-universal-events-click.md)。

> **说明：** 
>
> 当配置libraryname参数时，[点击事件](ts-universal-events-click.md)、[触摸事件](ts-universal-events-touch.md)、[挂载卸载事件](ts-universal-events-show-hide.md)、[按键事件](ts-universal-events-key.md)、[焦点事件](ts-universal-focus-event.md)、[鼠标事件](ts-universal-mouse-key.md)仅响应C-API侧事件接口。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

仅type为SURFACE或TEXTURE时以下事件有效：

### onLoad

onLoad(callback: (event?: object) => void )

插件加载完成时回调事件。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**参数:**

| 参数名   | 参数类型   | 必填   | 描述                                       |
| ----- | ------ | ---- | ---------------------------------------- |
| event | object | 否    | 获取XComponent实例对象的context，context上挂载的方法由开发者在c++层定义。 |

### onDestroy

onDestroy(event: () => void )

插件卸载完成时回调事件。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

## XComponentController

XComponent组件的控制器，可以将此对象绑定至XComponent组件，然后通过控制器来调用组件方法。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

### 创建对象

```
xcomponentController: XComponentController = new XComponentController()
```

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

### getXComponentSurfaceId

getXComponentSurfaceId(): string

获取XComponent对应Surface的ID，供@ohos接口使用，使用方式可参考[相机管理](../../apis-camera-kit/js-apis-camera.md)，仅XComponent类型为SURFACE("surface")或TEXTURE时有效。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**返回值:**

| 类型     | 描述                      |
| ------ | ----------------------- |
| string | XComponent持有Surface的ID。 |


### setXComponentSurfaceSize<sup>(deprecated)</sup>

setXComponentSurfaceSize(value: {surfaceWidth: number, surfaceHeight: number}): void

设置XComponent持有Surface的宽度和高度，仅XComponent类型为SURFACE("surface")或TEXTURE时有效。

该接口从API Version 12开始废弃，建议使用[setXComponentSurfaceRect](#setxcomponentsurfacerect12)替代。

**参数:**

| 参数名           | 参数类型   | 必填   | 描述                      |
| ------------- | ------ | ---- | ----------------------- |
| surfaceWidth  | number | 是    | XComponent持有Surface的宽度。 |
| surfaceHeight | number | 是    | XComponent持有Surface的高度。 |


### getXComponentContext

getXComponentContext(): Object

获取XComponent实例对象的context，仅XComponent类型为SURFACE("surface")或TEXTURE时有效。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**返回值:**

| 类型   | 描述                                                         |
| ------ | ------------------------------------------------------------ |
| Object | 获取XComponent实例对象的context，context包含的具体接口方法由开发者自定义，context内容与onLoad回调中的第一个参数一致。 |

### setXComponentSurfaceRect<sup>12+</sup>

setXComponentSurfaceRect(rect: SurfaceRect): void

设置XComponent持有Surface的显示区域，仅XComponent类型为SURFACE("surface")或TEXTURE时有效。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**参数:**

| 参数名 | 参数类型                             | 必填 | 描述                              |
| ------ | ------------------------------------ | ---- | --------------------------------- |
| rect   | [SurfaceRect](#surfacerect12类型说明) | 是   | XComponent持有Surface的显示区域。 |

> **说明：**
>
> rect参数中的offsetX/offsetY不设置时，Surface显示区域相对于XComponent左上角x/y轴的偏移效果默认按照居中显示。
>
> rect参数中的surfaceWidth和surfaceHeight存在0或负数时，调用该接口设置显示区域不生效。
>
> 该方法优先级高于[border](ts-universal-attributes-border.md#border)、[padding](ts-universal-attributes-size.md#padding)等可以改变内容偏移和大小的属性。

### getXComponentSurfaceRect<sup>12+</sup>

getXComponentSurfaceRect(): SurfaceRect

获取XComponent持有Surface的显示区域，仅XComponent类型为SURFACE("surface")或TEXTURE时有效。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**返回值:**

| 类型                                 | 描述                                  |
| ------------------------------------ | ------------------------------------- |
| [SurfaceRect](#surfacerect12类型说明) | 获取XComponent持有Surface的显示区域。 |

### onSurfaceCreated<sup>12+</sup>

onSurfaceCreated(surfaceId: string): void

当XComponent持有的Surface创建后进行该回调，仅XComponent类型为SURFACE("surface")或TEXTURE时有效。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**参数:**

| 参数名    | 参数类型 | 必填 | 描述                                              |
| --------- | -------- | ---- | ------------------------------------------------- |
| surfaceId | string   | 是   | 回调该方法的时候，绑定XComponent持有Surface的ID。 |

> **说明：**
>
> 仅当XComponent组件未设置libraryname参数时，会进行该回调。

### onSurfaceChanged<sup>12+</sup>

onSurfaceChanged(surfaceId: string, rect: SurfaceRect): void

当XComponent持有的Surface大小改变后（包括首次创建时的大小改变）进行该回调，仅XComponent类型为SURFACE("surface")或TEXTURE时有效。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**参数:**

| 参数名    | 参数类型                              | 必填 | 描述                                                    |
| --------- | ------------------------------------- | ---- | ------------------------------------------------------- |
| surfaceId | string                                | 是   | 回调该方法的时候，绑定XComponent持有Surface的ID。       |
| rect      | [SurfaceRect](#surfacerect12类型说明) | 是   | 回调该方法的时候，绑定XComponent持有Surface的显示区域。 |

> **说明：**
>
> 仅当XComponent组件未设置libraryname参数时，会进行该回调。

### onSurfaceDestroyed<sup>12+</sup>

onSurfaceDestroyed(surfaceId: string): void

当XComponent持有的Surface销毁后进行该回调，仅XComponent类型为SURFACE("surface")或TEXTURE时有效。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**参数:**

| 参数名    | 参数类型 | 必填 | 描述                                              |
| --------- | -------- | ---- | ------------------------------------------------- |
| surfaceId | string   | 是   | 回调该方法的时候，绑定XComponent持有Surface的ID。 |

> **说明：**
>
> 仅当XComponent组件未设置libraryname参数时，会进行该回调。

### SurfaceRect<sup>12+</sup>类型说明

用于描述XComponent持有Surface的显示区域。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

| 名称          | 类型   | 必填 | 说明                                                         |
| ------------- | ------ | ---- | ------------------------------------------------------------ |
| offsetX       | number | 否   | Surface显示区域相对于XComponent组件左上角的x轴坐标，单位：px。 |
| offsetY       | number | 否   | Surface显示区域相对于XComponent组件左上角的y轴坐标，单位：px。 |
| surfaceWidth  | number | 是   | Surface显示区域的宽度，单位：px。                            |
| surfaceHeight | number | 是   | Surface显示区域的高度，单位：px。                            |

### startImageAnalyzer<sup>12+</sup>

startImageAnalyzer(config: ImageAnalyzerConfig): Promise\<void>

配置AI分析并启动AI分析功能，使用前需先[使能](#enableanalyzer12)图像AI分析能力。<br>该方法调用时，将截取调用时刻的画面帧进行分析，使用时需注意启动分析的时机，避免出现画面和分析内容不一致的情况。<br>若该方法尚未执行完毕，此时重复调用，则会触发错误回调。

> **说明：**
> 
> 分析类型不支持动态修改。
> 该特性依赖设备能力，不支持该能力的情况下，将返回错误码。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名 | 类型      | 必填 | 说明                                                                   |
| ------ | --------- | ---- | ---------------------------------------------------------------------- |
| config   | [ImageAnalyzerConfig](ts-image-common.md#imageanalyzerconfig) | 是   | 执行AI分析所需要的入参，用于配置AI分析功能。 |

**返回值：**

| 类型              | 说明                                 |
| ----------------- | ------------------------------------ |
| Promise\<void>  | Promise对象，用于获取AI分析是否成功执行。 |

**错误码：**

以下错误码的详细介绍请参见[AI分析类库错误码](../errorcode-image-analyzer.md)。

| 错误码ID | 错误信息                                      |
| -------- | -------------------------------------------- |
| 110001 | AI analysis is unsupported.               |
| 110002 | AI analysis is ongoing.  |

### stopImageAnalyzer<sup>12+</sup>

stopImageAnalyzer(): void

停止AI分析功能，AI分析展示的内容将被销毁。

> **说明：**
> 
> 在startImageAnalyzer方法未返回结果时调用本方法，会触发其错误回调。
> 该特性依赖设备能力。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

### setXComponentSurfaceRotation<sup>12+</sup>

setXComponentSurfaceRotation(rotationOptions: SurfaceRotationOptions): void

设置XComponent持有Surface在屏幕旋转时是否锁定方向，仅XComponent类型为SURFACE("surface")时有效。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**参数:**

| 参数名 | 参数类型                             | 必填 | 描述                              |
| ------ | ------------------------------------ | ---- | --------------------------------- |
| rotationOptions   | [SurfaceRotationOptions](#surfacerotationoptions12类型说明) | 是 | 设置XComponent持有Surface在屏幕旋转时是否锁定方向。 |

> **说明：**
>
> rotationOptions未配置时，默认XComponent持有Surface在屏幕旋转时不锁定方向，跟随屏幕进行旋转。
>
> 仅在屏幕旋转过程中生效，旋转完成后不再锁定Surface。
>
> 仅在屏幕旋转90°，即发生横竖屏切换时生效。

### getXComponentSurfaceRotation<sup>12+</sup>

getXComponentSurfaceRotation(): Required\<SurfaceRotationOptions>

获取XComponent持有Surface在屏幕旋转时是否锁定方向的设置，仅XComponent类型为SURFACE("surface")时有效。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**返回值:**

| 类型                                 | 描述                                  |
| ------------------------------------ | ------------------------------------- |
| [SurfaceRotationOptions](#surfacerotationoptions12类型说明) | 获取XComponent持有Surface在屏幕旋转时是否锁定方向的设置。 |

### SurfaceRotationOptions<sup>12+</sup>类型说明

用于描述XComponent持有Surface在屏幕旋转时是否锁定方向的设置。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

| 名称          | 类型   | 必填 | 说明                                                         |
| ------------- | ------ | ---- | ------------------------------------------------------------ |
| lock       | boolean | 否   | Surface在屏幕旋转时是否锁定方向，未设置时默认取值为false，即不锁定方向。 |

## 示例

示例效果请以真机运行为准，当前IDE预览器不支持。

```ts
// xxx.ets
import { BusinessError } from '@kit.BasicServicesKit';

class CustomXComponentController extends XComponentController {
  onSurfaceCreated(surfaceId: string): void {
    console.log(`onSurfaceCreated surfaceId: ${surfaceId}`)
  }

  onSurfaceChanged(surfaceId: string, rect: SurfaceRect): void {
    console.log(`onSurfaceChanged surfaceId: ${surfaceId}, rect: ${JSON.stringify(rect)}}`)
  }

  onSurfaceDestroyed(surfaceId: string): void {
    console.log(`onSurfaceDestroyed surfaceId: ${surfaceId}`)
  }
}

@Entry
@Component
struct XComponentExample {
  xComponentController: XComponentController = new CustomXComponentController()
  private config: ImageAnalyzerConfig = {
    types: [ImageAnalyzerType.SUBJECT, ImageAnalyzerType.TEXT]
  }
  private aiController: ImageAnalyzerController = new ImageAnalyzerController()
  private options: ImageAIOptions = {
    types: [ImageAnalyzerType.SUBJECT, ImageAnalyzerType.TEXT],
    aiController: this.aiController
  }
  @State xcWidth: string = "320px"
  @State xcHeight: string = "480px"

  build() {
    Column({ space: 5 }) {
      Button("change size")
        .onClick(() => {
          this.xcWidth = "640px"
          this.xcHeight = "720px"
        })
      Button('start AI analyze')
        .onClick(() => {
          this.xComponentController.startImageAnalyzer(this.config)
            .then(() => {
              console.log("analysis complete")
            })
            .catch((error: BusinessError) => {
              console.log("error code: " + error.code)
            })
        })
      Button('stop AI analyze')
        .onClick(() => {
          this.xComponentController.stopImageAnalyzer()
        })
      Button('get analyzer types')
        .onClick(() => {
          this.aiController.getImageAnalyzerSupportTypes()
        })
      XComponent({
        type: XComponentType.SURFACE,
        controller: this.xComponentController,
        imageAIOptions: this.options
      })
        .width(this.xcWidth)
        .height(this.xcHeight)
    }
    .width("100%")
  }
}
```

