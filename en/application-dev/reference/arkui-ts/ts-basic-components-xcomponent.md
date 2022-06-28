# XComponent

  > **NOTE**<br>
  > This component is supported since API version 8. Updates will be marked with a superscript to indicate their earliest API version.

  The **\<XComponent>** can accept and display the EGL/OpenGLES and media data input.

## Required Permissions

  None

## Child Components

  Not supported

## APIs

  XComponent\(value: {id: string, type: string, libraryname?: string, controller?: XComponentController}\)

  - Name

    | Name        | Type                                    | Mandatory | Description                                                        |
    | ----------- | --------------------------------------- | --------- | ------------------------------------------------------------ |
    | id          | string                                        | Yes | Unique ID of the component. The value can contain a maximum of 128 characters.                   |
    | type        | string                                        | Yes | Type of the component. The options are as follows:<br>- **surface**: The content of this component is displayed individually, without being combined with that of other components.<br>- **component**: The content of this component is displayed after having been combined with that of other components. |
    | libraryname | string                                        | No  | Name of the dynamic library generated after compilation at the application native layer. |
    | controller  | [XComponentController](#XComponentController) | No  | Controller bound to the component, which can be used to invoke methods of the component.              |


## Events

| Name                            | Description              |
| ------------------------------- | ------------------------ |
| onLoad(context?: object) => void | Triggered when the plug-in is loaded. |
| onDestroy() => void              | Triggered when the plug-in is destroyed. |

## XComponentController

Defines the controller of the **\<XComponent>**. You can bind the controller to the **\<XComponent>** to invoke the component methods through the controller.

### Creating an Object

```
xcomponentController: XComponentController = new XComponentController()
```

### getXComponentSurfaceId

getXComponentSurfaceId(): string

Obtains the ID of the surface held by the **\<XComponent>**. The ID can be used for @ohos interfaces, such as camera-related interfaces.

  - Return value

    | Type   | Description                 |
    | ------ | --------------------------- |
    | string | ID of the surface held by the **\<XComponent>**. |

### setXComponentSurfaceSize

setXComponentSurfaceSize(value: {surfaceWidth: number, surfaceHeight: number}): void

Sets the width and height of the surface held by the **\<XComponent>**.

- Parameters

  | Name       | Type | Mandatory | Default Value | Description              |
  | ------------- | -------- | ---- | ------ | ----------------------------- |
  | surfaceWidth  | number   | Yes  | -      | Width of the surface held by the **\<XComponent>**. |
  | surfaceHeight | number   | Yes  | -      | Height of the surface held by the **\<XComponent>**. |

### getXComponentContext

getXComponentContext(): Object

Obtains the context of an **\<XComponent>** object.

- Return value

  | Type  | Description                                                        |
  | ------ | ------------------------------------------------------------ |
  | Object | Context of an **\<XComponent>** object. The APIs contained in the context are defined by developers. |

## Example

Provide a surface-type **\<XComponent>** to support capabilities such as camera preview.

```ts
// xxx.ets
import camera from '@ohos.multimedia.camera';
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
          this.surfaceId = this.xcomponentController.getXComponentSurfaceId();
          camera.createPreviewOutput(this.surfaceId).then((previewOutput) => {
            console.log('Promise returned with the PreviewOutput instance');
          })
        })
        .width('640px')
        .height('480px')
    }
    .backgroundColor(Color.Black)
    .position({x: 0, y: 48})
  }
}
```
