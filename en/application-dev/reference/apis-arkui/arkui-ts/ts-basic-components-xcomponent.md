# XComponent

The **\<XComponent>** can accept and display the EGL/OpenGL ES and media data input.

> **NOTE**
>
> This component is supported since API version 8. Updates will be marked with a superscript to indicate their earliest API version.


## Child Components
Child components are not supported when **type** is set to **"surface"**.

Since API version 9, child components are supported when **type** is set to **"component"**.

## APIs

### XComponent

XComponent(value: {id: string, type: string, libraryname?: string, controller?: XComponentController})

**Parameters**

| Name     | Type                                     | Mandatory| Description                                                        |
| ----------- | --------------------------------------------- | ---- | ------------------------------------------------------------ |
| id          | string                                        | Yes  | Unique ID of the component. The value can contain a maximum of 128 characters.                   |
| type        | string                                        | Yes  | Type of the component. The options are as follows:<br>- **"surface"**: The custom content is displayed individually on the screen. This option is used for displaying EGL/OpenGL ES and media data.<br>- **"component"**<sup>9+</sup>: The component becomes a container where non-UI logic can be executed to dynamically load the display content.<br>Any other value evaluates to **"surface"**.|
| libraryname | string                                        | No  | Name of the dynamic library generated after compilation at the application native layer. This parameter is valid only when **type** is **"surface"**.|
| controller  | [XComponentcontroller](#xcomponentcontroller) | No  | Controller bound to the component, which can be used to invoke methods of the component. This parameter is valid only when the component type is **"surface"**.|

### XComponent<sup>10+</sup>

XComponent(value: {id: string, type: XComponentType, libraryname?: string, controller?: XComponentController})

**Parameters**

| Name     | Type                                     | Mandatory| Description                                                        |
| ----------- | --------------------------------------------- | ---- | ------------------------------------------------------------ |
| id          | string                                        | Yes  | Unique ID of the component. The value can contain a maximum of 128 characters.                   |
| type        | [XComponentType](#xcomponenttype10)   | Yes  | Type of the component.                                |
| libraryname | string                                        | No  | Name of the dynamic library generated after compilation at the application native layer. This parameter is valid only when **type** is **SURFACE** or **TEXTURE**.|
| controller  | [XComponentcontroller](#xcomponentcontroller) | No  | Controller bound to the component, which can be used to invoke methods of the component. This parameter is valid only when **type** is **SURFACE** or **TEXTURE**.|

## XComponentType<sup>10+</sup>

| Name     | Description                                                        |
| --------- | ------------------------------------------------------------ |
| SURFACE   | The custom content is displayed individually on the screen. This option is used for displaying EGL/OpenGL ES and media data.|
| COMPONENT | The component becomes a container where non-UI logic can be executed to dynamically load the display content.|
| TEXTURE   | The custom content of the component is grouped and displayed together with content of the component.|

> **NOTE**
>
> When **type** is set to **COMPONENT("component")**, the **\<XComponent>** functions as a container, where child components are laid out vertically.
>
> - Vertical alignment: [FlexAlign](ts-appendix-enums.md#flexalign).Start
> - Horizontal alignment: [FlexAlign](ts-appendix-enums.md#flexalign).Center
>
> The component does not respond to any events.
>
> Layout changes and event responses can be set by mounting child components.
>
> The non-UI logic written internally needs to be encapsulated in one or more functions.

## Attributes
- You can customize the content displayed in the **\<XComponent>**. Depending on the **type** settings, the support for the universal attributes [background](ts-universal-attributes-background.md), [opacity](ts-universal-attributes-opacity.md), and [image effects](ts-universal-attributes-image-effect.md) varies.

- When **type** is set to **SURFACE("surface")**, only the **shadow** attribute of [image effects](ts-universal-attributes-image-effect.md). For configuration of other attributes, you are advised to use the APIs provided by EGL/OpenGL ES instead.

  > **NOTE**<br>
  >
  > Since API version 11, when **type** is set to **SURFACE("surface")**, the [backgroundColor](ts-universal-attributes-background.md#backgroundcolor) attribute is supported.

- When **type** is set to **COMPONENT("component")**, only the **shadow** attribute of [image effects](ts-universal-attributes-image-effect.md). For configuration of other attributes, you are advised to mount child components.

- When **type** is set to **TEXTURE**, the **shadow** attribute of [image effects](ts-universal-attributes-image-effect.md), [backgroundColor](ts-universal-attributes-background.md#backgroundcolor), and [opacity](ts-universal-attributes-opacity.md) are supported. For configuration of other attributes, you are advised to use the APIs provided by EGL/OpenGL ES instead.

### enableAnalyzer<sup>12+</sup>

enableAnalyzer(enable: boolean)

Specifies whether to enable the AI image analyzer. This attribute must be used together with[StartImageAnalyzer](#startimageanalyzer12) and [StopImageAnalyzer](#stopimageanalyzer12) in **XComponentController**.
This attribute cannot be used together with the [overlay](ts-universal-attributes-overlay.md) attribute. If they are set at the same time, the **CustomBuilder** attribute in **overlay** has no effect. This feature depends on device capabilities.

**Widget capability**: This API can be used in ArkTS widgets since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| enable | boolean | Yes| Whether to enable the AI image analyzer.|

  > **NOTE**<br>
  >
  > This API has effect only when **type** is set to **SURFACE** or **TEXTURE**.

## Events

When **type** is set to **SURFACE("surface")** or **TEXTURE**, the [universal events](ts-universal-events-click.md) are supported since API version 12, subject to the following constraints:

- The following events, which are mutually exclusive with the corresponding NDK APIs, are available only when **libraryname** is not set: [click event](ts-universal-events-click.md), [touch event](ts-universal-events-touch.md), [show/hide event](ts-universal-events-show-hide.md), [key event](ts-universal-events-key.md), [focus event](ts-universal-focus-event.md), and [mouse event](ts-universal-mouse-key.md).

- Other universal events do not have corresponding NDK APIs; therefore, they are available regardless of whether **libraryname** is set.

When **type** is set to **SURFACE("surface")** or **TEXTURE**, the following events are supported.

### onLoad

onLoad(callback: (event?: object) => void )

Triggered when the plug-in is loaded.

**Parameters**

| Name  | Type  | Mandatory  | Description                                      |
| ----- | ------ | ---- | ---------------------------------------- |
| event | object | No   | Context of the **\<XComponent>** object. The APIs contained in the context are defined at the C++ layer by developers.|

### onDestroy

onDestroy(event: () => void )

Triggered when the plug-in is destroyed.

## XComponentController

Defines the controller of the **\<XComponent>**. You can bind the controller to the **\<XComponent>** to invoke the methods of the component through the controller.

### Creating an Object

```
xcomponentController: XComponentController = new XComponentController()
```

### getXComponentSurfaceId

getXComponentSurfaceId(): string

Obtains the ID of the surface held by the **\<XComponent>**, which can then be used for @ohos APIs. For details, see [Camera Management](../../apis-camera-kit/js-apis-camera.md). This API works only when **type** of the **\<XComponent>** is set to **SURFACE("surface")** or **TEXTURE**.

**Return value**

| Type    | Description                     |
| ------ | ----------------------- |
| string | ID of the surface held by the **\<XComponent>**.|


### setXComponentSurfaceSize<sup>(deprecated)</sup>

setXComponentSurfaceSize(value: {surfaceWidth: number, surfaceHeight: number}): void

Sets the width and height of the surface held by the **\<XComponent>**. This API works only when **type** of the **\<XComponent>** is set to **SURFACE("surface")** or **TEXTURE**.

This API is deprecated since API version 12. You are advised to use [setXComponentSurfaceRect](#setxcomponentsurfacerect12) instead.

**Parameters**

| Name          | Type  | Mandatory  | Description                     |
| ------------- | ------ | ---- | ----------------------- |
| surfaceWidth  | number | Yes   | Width of the surface held by the **\<XComponent>**.|
| surfaceHeight | number | Yes   | Height of the surface held by the **\<XComponent>**.|


### getXComponentContext

getXComponentContext(): Object

Obtains the context of an **\<XComponent>** object. This API works only when **type** of the **\<XComponent>** is set to **SURFACE("surface")** or **TEXTURE**.

**Return value**

| Type  | Description                                                        |
| ------ | ------------------------------------------------------------ |
| Object | Context of the **\<XComponent>** object. The APIs contained in the context are defined by developers. The context is passed in as the first parameter of the **onLoad** callback.|

### setXComponentSurfaceRect<sup>12+</sup>

setXComponentSurfaceRect(rect: SurfaceRect): void

Sets the rectangle for the surface held by the **\<XComponent>**. This API works only when type of the **\<XComponent>** is set to **SURFACE("surface")** or **TEXTURE**.

**Parameters**

| Name| Type                            | Mandatory| Description                             |
| ------ | ------------------------------------ | ---- | --------------------------------- |
| rect   | [SurfaceRect](#surfacerect12) | Yes  | Rectangle of the surface held by the **\<XComponent>**.|

> **NOTE**<br>
>
> If **offsetX** or **offsetY** in the **rect** parameter is not set, the surface rectangle is centered along the x-axis or y-axis relative to the upper left corner of the **\<XComponent>**.
>
> If **surfaceWidth** and **surfaceHeight** in the **rect** parameter are set to **0** or a negative value, this API has no effect.
>
> This API has a higher priority than attributes that can change the content offset and size, such as [border](ts-universal-attributes-border.md#border) and [padding](ts-universal-attributes-size.md#padding).

### getXComponentSurfaceRect<sup>12+</sup>

getXComponentSurfaceRect(): SurfaceRect

Obtains the rectangle of the surface held by the **\<XComponent>**. This API works only when type of the **\<XComponent>** is set to **SURFACE("surface")** or **TEXTURE**.

**Return value**

| Type                                | Description                                 |
| ------------------------------------ | ------------------------------------- |
| [SurfaceRect](#surfacerect12) | Rectangle of the surface held by the **\<XComponent>**.|

### onSurfaceCreated<sup>12+</sup>

onSurfaceCreated(surfaceId: string): void

Triggered when the surface held by the **\<XComponent>** is created. This API works only when **type** of the **\<XComponent>** is set to **SURFACE("surface")** or **TEXTURE**.

**Parameters**

| Name   | Type| Mandatory| Description                                             |
| --------- | -------- | ---- | ------------------------------------------------- |
| surfaceId | string   | Yes  | ID of the surface held by the **\<XComponent>**.|

> **NOTE**<br>
>
> The callback is triggered only when the **libraryname** parameter is not set for the **\<XComponent>**.

### onSurfaceChanged<sup>12+</sup>

onSurfaceChanged(surfaceId: string, rect: SurfaceRect): void

Triggered when the surface held by the **\<XComponent>** has its size changed (including the time when the **\<XComponent>** is created with the specified size). This API works only when **type** of the **\<XComponent>** is set to **SURFACE("surface")** or **TEXTURE**.

**Parameters**

| Name   | Type                             | Mandatory| Description                                                   |
| --------- | ------------------------------------- | ---- | ------------------------------------------------------- |
| surfaceId | string                                | Yes  | ID of the surface held by the **\<XComponent>**.      |
| rect      | [SurfaceRect](#surfacerect12) | Yes  | Rectangle for displaying the surface held by the **\<XComponent>**.|

> **NOTE**<br>
>
> The callback is triggered only when the **libraryname** parameter is not set for the **\<XComponent>**.

### onSurfaceDestroyed<sup>12+</sup>

onSurfaceDestroyed(surfaceId: string): void

Triggered when the surface held by the **\<XComponent>** is destroyed. This API works only when **type** of the **\<XComponent>** is set to **SURFACE("surface")** or **TEXTURE**.

**Parameters**

| Name   | Type| Mandatory| Description                                             |
| --------- | -------- | ---- | ------------------------------------------------- |
| surfaceId | string   | Yes  | ID of the surface held by the **\<XComponent>**.|

> **NOTE**<br>
>
> The callback is triggered only when the **libraryname** parameter is not set for the **\<XComponent>**.

### SurfaceRect<sup>12+</sup>

Describes the rectangle of the surface held by the **\<XComponent>**.

| Name         | Type  | Mandatory| Description                                                        |
| ------------- | ------ | ---- | ------------------------------------------------------------ |
| offsetX       | number | No  | X coordinate of the surface rectangle relative to the upper left corner of the **\<XComponent>**.<br>Unit: px|
| offsetY       | number | No  | Y coordinate of the surface rectangle relative to the upper left corner of the **\<XComponent>**.<br>Unit: px|
| surfaceWidth  | number | Yes  | Width of the surface rectangle.<br>Unit: px                           |
| surfaceHeight | number | Yes  | Height of the surface rectangle.<br>Unit: px                           |

### startImageAnalyzer<sup>12+</sup>

startImageAnalyzer(config: ImageAnalyzerConfig): Promise\<void>

Starts AI image analysis in the given settings. Before calling this API, make sure the AI image analyzer is [enabled](#enableanalyzer12).<br>Because the image frame used for analysis is the one captured when this API is called, pay attention to the invoking time of this API.<br>If this API is repeatedly called before the execution is complete, an error callback is triggered.

> **NOTE**<br>
> 
> The image analysis type cannot be dynamically modified.
> This API depends on device capabilities. If it is called on an incompatible device, an error code is returned.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type     | Mandatory| Description                                                                  |
| ------ | --------- | ---- | ---------------------------------------------------------------------- |
| config   | [ImageAnalyzerConfig](ts-image-common.md#imageanalyzerconfig12) | Yes  | Settings of the AI image analyzer.|

**Return value**

| Type             | Description                                |
| ----------------- | ------------------------------------ |
| Promise\<void>  | Promise used to return the result.|

**Error codes**

For details about the error codes, see [AI Image Analyzer Error Codes](../errorcode-image-analyzer.md).

| ID| Error Message                                     |
| -------- | -------------------------------------------- |
| 110001 | AI analysis is unsupported.               |
| 110002 | AI analysis is ongoing.  |
| 110003 | AI analysis is stopped.  |

### stopImageAnalyzer<sup>12+</sup>

stopImageAnalyzer(): void

Stops AI image analysis. The content displayed by the AI image analyzer will be destroyed.

> **NOTE**<br>
> 
> If this API is called when the **startImageAnalyzer** API has not yet returned any result, an error callback is triggered.
> This feature depends on device capabilities.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

## Example

You can preview how this component looks on a real device, but not in the DevEco Studio Previewer.

### Example 1

```ts
// xxx.ets
@Entry
@Component
struct PreviewArea {
  private surfaceId: string = ''
  private xComponentContext: Record<string, () => void> = {}
  xComponentController: XComponentController = new XComponentController()
  @State rect: SurfaceRect | null = null

  build() {
    Column() {
      Text(JSON.stringify(this.rect))
        .fontSize(12)
      XComponent({
        id: 'xcomponent',
        type: XComponentType.SURFACE,
        controller: this.xComponentController
      })
        .onLoad(() => {
          this.surfaceId = this.xComponentController.getXComponentSurfaceId()
          this.xComponentContext = this.xComponentController.getXComponentContext() as Record<string, () => void>
          let surfaceRect: SurfaceRect = { offsetX: 20, offsetY: 20, surfaceWidth: 500, surfaceHeight: 500 }
          this.xComponentController.setXComponentSurfaceRect(surfaceRect)
          this.rect = this.xComponentController.getXComponentSurfaceRect()
        })
        .width('640px')
        .height('480px')
    }
    .position({ x: 0, y: 48 })
  }
}
```

### Example 2

```ts
// xxx.ets
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
struct SurfaceCallbackDemo {
  xComponentController: XComponentController = new CustomXComponentController()
  @State xcWidth: string = "320px"
  @State xcHeight: string = "480px"

  build() {
    Column() {
      Button("change size")
        .onClick(() => {
          this.xcWidth = "640px"
          this.xcHeight = "960px"
        })
      XComponent({
        id: 'xcomponent',
        type: XComponentType.SURFACE,
        controller: this.xComponentController
      })
        .width(this.xcWidth)
        .height(this.xcHeight)
    }
    .width("100%")
  }
}
```

### Example 3

This example shows how to use the AI image analyzer.

```ts
// xxx.ets
@Entry
@Component
struct ImageAnalyzerExample {
  xComponentController: XComponentController = new XComponentController()
  private config: ImageAnalyzerConfig = {
    types: [ImageAnalyzerType.SUBJECT, ImageAnalyzerType.TEXT]
  }

  build() {
    Column() {
      Button('start')
        .width(80)
        .height(80)
        .onClick(() => {
          this.xComponentController.startImageAnalyzer(this.config)
            .then(() => {
              console.log("analysis complete")
            })
            .catch((error: BusinessError) => {
              console.log("error code: " + error.code)
            })
        })
      Button('stop')
        .width(80)
        .height(80)
        .onClick(() => {
          this.xComponentController.stopImageAnalyzer()
        })
      XComponent({
        id: 'xcomponent',
        type: XComponentType.SURFACE,
        controller: this.xComponentController
      })
        .enableAnalyzer(true)
        .width('640px')
        .height('480px')
    }
    .width("100%")
  }
}
```
