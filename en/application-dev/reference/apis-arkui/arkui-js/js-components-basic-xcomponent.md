# xcomponent

> **NOTE**
> 
> This component is supported since API version 8. Updates will be marked with a superscript to indicate their earliest API version.

The **\<xcomponent>** displays the components to which the EGL/OpenGLES or media data is written.

## Required Permissions

None

## Child Components

Not supported

## Attributes

In addition to the [universal attributes](js-components-common-attributes.md), the following attributes are supported.

| Name         | Type  | Mandatory  | Description                                      |
| ----------- | ------ | ---- | ---------------------------------------- |
| id          | string | Yes   | Unique ID of the component. The value can contain a maximum of 128 characters.                  |
| type        | string | Yes   | Type of the component. The options are as follows:<br>- **surface**: The content of this type of component is displayed individually, without being combined with that of other components.<br>- **component**: The content of this type of component is displayed after having been combined with that of other components.<br>|
| libraryname | string | No   | Name of the dynamic library generated after compilation at the application native layer.                     |

## Styles

The [universal styles](js-components-common-styles.md) are supported.

## Events

In addition to the [universal events](js-components-common-events.md), the following events are supported.

| Name                              | Description                                    |
| -------------------------------- | ---------------------------------------- |
| onLoad(context?: object) => void | Triggered when the plug-in is loaded.<br>**context**: context of an **\<xcomponent>** object. The APIs contained in the context are defined by developers.|
| onDestroy() => void              | Triggered when the plug-in is destroyed.                            |

## Methods

In addition to the [universal methods](js-components-common-methods.md), the following methods are supported.

| Name                      | Parameter                                      | Return Value Type | Description                                      |
| ------------------------ | ---------------------------------------- | ------ | ---------------------------------------- |
| getXComponentSurfaceId   | -                                        | string | Obtains the ID of the surface held by the **\<xcomponent>**. The ID can be used for @ohos interfaces, such as camera-related interfaces.|
| setXComponentSurfaceSize | {<br>surfaceWidth: number,<br>surfaceHeight: number  <br>} | -      | Sets the width and height of the surface held by the **\<xcomponent>**.            |
| getXComponentContext     | -                                        | object | Obtains the instance object of the xcomponent method extended by the developer.              |

## Example

Provide a surface-type **\<xcomponent>** to support camera preview and other capabilities.

   ```html
<!-- xxx.hml -->
<div style="height: 500px; width: 500px; flex-direction: column; justify-content: center; align-items: center;">
	<text id = 'camera' class = 'title'>camera_display</text>
	<xcomponent id = 'xcomponent' type = 'surface' onload = 'onload' ondestroy = 'ondestroy'></xcomponent>
</div>
   ```

   ```js
// xxx.js
import camera from '@ohos.multimedia.camera';
export default {
    onload() {
        var surfaceId = this.$element('xcomponent').getXComponentSurfaceId();
        camera.createPreviewOutput(surfaceId).then((previewOutput) => {
            console.log('Promise returned with the PreviewOutput instance');
        })
    }
}
   ```
