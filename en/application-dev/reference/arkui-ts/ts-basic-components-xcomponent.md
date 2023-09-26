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
- When **type** is set to **COMPONENT("component")**, only the **shadow** attribute of [image effects](ts-universal-attributes-image-effect.md). For configuration of other attributes, you are advised to mount child components.
- When **type** is set to **TEXTURE**, only the **backgroundColor** attribute of [background](ts-universal-attributes-background.md), the **shadow** attribute of [image effects](ts-universal-attributes-image-effect.md), and [opacity](ts-universal-attributes-opacity.md) are supported. For configuration of other attributes, you are advised to use the APIs provided by EGL/OpenGL ES instead.

## Events

When **type** is set to **SURFACE("surface")** or **TEXTURE**, the following events are supported. The [universal events](ts-universal-events-click.md) are not supported.

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

Obtains the ID of the surface held by the **\<XComponent>**, which can then be used for @ohos APIs. For details, see [Camera Management](../apis/js-apis-camera.md). This API works only when **type** of the **\<XComponent>** is set to **SURFACE("surface")** or **TEXTURE**.


**Return value**

| Type    | Description                     |
| ------ | ----------------------- |
| string | ID of the surface held by the **\<XComponent>**.|


### setXComponentSurfaceSize

setXComponentSurfaceSize(value: {surfaceWidth: number, surfaceHeight: number}): void

Sets the width and height of the surface held by the **\<XComponent>**. This API works only when **type** of the **\<XComponent>** is set to **SURFACE("surface")** or **TEXTURE**.


**Parameters**

| Name          | Type  | Mandatory  | Description                     |
| ------------- | ------ | ---- | ----------------------- |
| surfaceWidth  | number | Yes   | Width of the surface held by the **\<XComponent>**.|
| surfaceHeight | number | Yes   | Height of the surface held by the **\<XComponent>**.|


### getXComponentContext

getXComponentContext(): Object

Obtains the context of an **\<XComponent>** object. This API works only when **type** of the **\<XComponent>** is set to **SURFACE("surface")** or **TEXTURE**.

**Return value**

| Type    | Description                                      |
| ------ | ---------------------------------------- |
| Object | Context of the **\<XComponent>** object. The APIs contained in the context are defined by developers.|


## Example

You can preview how this component looks on a real device. The preview is not yet available in the DevEco Studio Previewer.

```ts
// xxx.ets
@Entry
@Component
struct PreviewArea {
  private surfaceId : string =''
  xcomponentController: XComponentController = new XComponentController()
  build() {
    Row() {
      XComponent({
        id: 'xcomponent',
        type: 'surface',
        controller: this.xcomponentController
      })
        .onLoad(() => {
          this.xcomponentController.setXComponentSurfaceSize({surfaceWidth:1920,surfaceHeight:1080});
          this.surfaceId = this.xcomponentController.getXComponentSurfaceId()
        })
        .width('640px')
        .height('480px')
    }
    .backgroundColor(Color.Black)
    .position({x: 0, y: 48})
  }
}
```
