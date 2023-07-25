# @ohos.componentUtils (componentUtils)

The **componentUtils** module provides API for obtaining the coordinates and size of the drawing area of a component.

> **NOTE**
>
> The APIs of this module are supported since API version 10. Updates will be marked with a superscript to indicate their earliest API version.
>
> The functionality of this module depends on UI context. This means that the APIs of this module cannot be used where the UI context is unclear. For details, see [UIContext](./js-apis-arkui-UIContext.md#uicontext).
>
> Since API version 10, you can use the [getComponentUtils](./js-apis-arkui-UIContext.md#getcomponentutils) API in **UIContext** to obtain the **ComponentUtils** object associated with the current UI context. For this API to work correctly, call it after the notification indicating completion of component layout is received through [@ohos.arkui.inspector (layout callback)](js-apis-arkui-inspector.md).

## Modules to Import

```js
import componentUtils from '@ohos.componentUtils'
```
## componentUtils.getRectangleById

getRectangleById(id: string): ComponentInfo

Obtains a **ComponentInfo** object based on the component ID.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name| Type  | Mandatory| Description      |
| ------ | ------ | ---- | ---------- |
| id     | string | Yes  | Component ID.|

**Return value**

| Type  | Description      |
| ------ | ---------- |
| [ComponentInfo](#componentinfo) | **ComponentInfo** object, which provides the size, position, translation, scaling, rotation, and affine matrix information of the component.|

**Example**

```js
let modePosition = componentUtils.getRectangleById("onClick");
```

## ComponentInfo

| Name          | Type            | Description                        |
| ---------------|------------     | -----------------------------|
| size           | [Size](#size) | Component size.                   |
| localOffset    | [Offset](#offset) | Offset of the component relative to the parent component.        |
| windowOffset   | [Offset](#offset) | Offset of the component relative to the window.          |
| screenOffset   | [Offset](#offset) | Offset of the component relative to the screen.          |
| translate      | [TranslateResult](#translateresult) | Translation of the component.               |
| scale          | [ScaleResult](#scaleresult) | Scaling of the component.               |
| rotate         | [RotateResult](#rotateresult) | Rotation of the component.               |
| transform      | [Matrix4Result](#matrix4result) | Affine matrix of the component, which is a 4x4 matrix object created based on the input parameter. |

### Size 

| Name    | Type| Description                              |
| -------- | ---- | ----------------------------------|
| width    | number | Component width.                        |
| height   | number | Component height.                        |

### Offset

| Name    | Type| Description                              |
| --------| ---- | -----------------------------------|
| x       | number | X coordinate.                          |
| y       | number | Y coordinate.                          |

### TranslateResult

| Name    | Type| Description                              |
| --------| ---- | -----------------------------------|
| x       | number | Translation distance along the x-axis.                      |
| y       | number | Translation distance along the y-axis.                      |
| z       | number | Translation distance along the z-axis.                      |

### ScaleResult

| Name    | Type| Description                              |
| --------| ---- | -----------------------------------|
| x       | number | Scale factor along the x-axis.                      |
| y       | number | Scale factor along the y-axis.                      |
| z       | number | Scale factor along the z-axis.                      |
| centerX | number | X coordinate of the center point.                 |
| centerY | number | Y coordinate of the center point.               |

### RotateResult

| Name    | Type| Description                              |
| --------| ---- | -----------------------------------|
| x       | number | X coordinate of the rotation vector.                  |
| y       | number | Y coordinate of the rotation vector.                  |
| z       | number | Z coordinate of the rotation vector.                  |
| angle   | number | Rotation angle.                         |
| centerX | number | X coordinate of the center point.                |
| centerY | number | Y coordinate of the center point.                |

### Matrix4Result

| Name    | Type| Description                              |
| --------| ---- | -----------------------------------|
| number  | number | Scale factor along the x-axis. Defaults to **1** for the identity matrix.        |
| number  | number | The second value, which is affected by the rotation of the x, y, and z axes.|
| number  | number | The third value, which is affected by the rotation of the x, y, and z axes.|
| number  | number | Meaningless value.                       |
| number  | number | The fifth value, which is affected by the rotation of the x, y, and z axes.|
| number  | number | Scale factor along the y-axis. Defaults to **1** for the identity matrix.         |
| number  | number | The seventh value, which is affected by the rotation of the x, y, and z axes.|
| number  | number | Meaningless value.                       |
| number  | number | The ninth value, which is affected by the rotation of the x, y, and z axes.|
| number  | number | The tenth value, which is affected by the rotation of the x, y, and z axes.|
| number  | number | Scale factor along the z-axis. Defaults to **1** for the identity matrix.        |
| number  | number | Meaningless value.                      |
| number  | number | Translation distance along the x-axis. Defaults to **0** for the identity matrix. |
| number  | number | Translation distance along the y-axis. Defaults to **0** for the identity matrix.|
| number  | number | Translation distance along the z-axis. Defaults to **0** for the identity matrix.|
| number  | number | Valid in homogeneous coordinates, presenting the perspective projection effect.  |

**Example**

  ```js
import matrix4 from '@ohos.matrix4';
import componentUtils from '@ohos.componentUtils';

@Entry
@Component
struct Utils{
  private getComponentRect(key) {
    console.info("Mode Key: " + key);
    let modePosition = componentUtils.getRectangleById(key);

    let localOffsetWidth = modePosition.size.width;
    let localOffsetHeight = modePosition.size.height;
    let localOffsetX = modePosition.localOffset.x;
    let localOffsetY = modePosition.localOffset.y;

    let windowOffsetX = modePosition.windowOffset.x;
    let windowOffsetY = modePosition.windowOffset.y;

    let screenOffsetX = modePosition.screenOffset.x;
    let screenOffsetY = modePosition.screenOffset.y;

    let translateX = modePosition.translate.x;
    let translateY = modePosition.translate.y;
    let translateZ = modePosition.translate.z;

    let scaleX = modePosition.scale.x;
    let scaleY = modePosition.scale.y;
    let scaleZ = modePosition.scale.z;
    let scaleCenterX = modePosition.scale.centerX;
    let scaleCenterY = modePosition.scale.centerY;

    let rotateX = modePosition.rotate.x;
    let rotateY = modePosition.rotate.y;
    let rotateZ = modePosition.rotate.z;
    let rotateCenterX = modePosition.rotate.centerX;
    let rotateCenterY = modePosition.rotate.centerY;
    let rotateAngle = modePosition.rotate.angle;

    let Matrix4_1 = modePosition.transform[0];
    let Matrix4_2 = modePosition.transform[1];
    let Matrix4_3 = modePosition.transform[2];
    let Matrix4_4 = modePosition.transform[3];
    let Matrix4_5 = modePosition.transform[4];
    let Matrix4_6 = modePosition.transform[5];
    let Matrix4_7 = modePosition.transform[6];
    let Matrix4_8 = modePosition.transform[7];
    let Matrix4_9 = modePosition.transform[8];
    let Matrix4_10 = modePosition.transform[9];
    let Matrix4_11 = modePosition.transform[10];
    let Matrix4_12 = modePosition.transform[11];
    let Matrix4_13 = modePosition.transform[12];
    let Matrix4_14 = modePosition.transform[13];
    let Matrix4_15 = modePosition.transform[14];
    let Matrix4_16 = modePosition.transform[15];
    console.info("[getRectangleById] current component obj is: " + modePosition );
  }
  @State x: number = 120;
  @State y: number = 10;
  @State z: number = 100;
  private matrix1 = matrix4.identity().translate({ x: this.x, y: this.y, z: this.z });
  build() {
    Column() {
        Image($r("app.media.icon"))
          .transform(this.matrix1)
          .translate({ x: 100, y: 10, z: 50})
          .scale({ x: 2, y: 0.5, z: 1 })
          .rotate({
            x: 1,
            y: 1,
            z: 1,
            centerX: '50%',
            centerY: '50%',
            angle: 300
          })
          .width("40%")
          .height(100)
          .key("image_01")
      Button() {
        Text('getRectangleById').fontSize(40).fontWeight(FontWeight.Bold);
      }.margin({ top: 20 })
      .onClick(() => {
        this.getComponentRect("image_01");
      }).id('onClick');
    }
  }
}
  ```
