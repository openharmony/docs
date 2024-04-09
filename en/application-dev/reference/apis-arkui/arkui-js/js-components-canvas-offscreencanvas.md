# OffscreenCanvas

>  **NOTE**
>
>  The APIs of this component are supported since API version 7. Updates will be marked with a superscript to indicate their earliest API version.


**OffscreenCanvas** defines a canvas object that can be rendered off the screen.


## Attributes

| Name    | Type    | Description                         |
| ------ | ------ | --------------------------- |
| width  | number | Width of the **OffscreenCanvas** object.|
| height | number | Height of the **OffscreenCanvas** object.|


## Methods


### getContext

getContext(type: string, options?: CanvasRenderingContext2DSettings): OffscreenCanvasRenderingContext2D

Obtains the **OffscreenCanvas** context. This API returns a 2D drawing object.

**Parameters**

| Name      | Type                                    | Mandatory  | Description                    |
| --------- | ---------------------------------------- | ---- | ---------------------- |
| contextId | string                                   | Yes   | Context ID. The value can only be **"2d"**.        |
| options   | [CanvasRenderingContext2DSettings](#canvasrenderingcontext2dsettings) | No   | Whether to enable anti-aliasing. By default, anti-aliasing is disabled.|

**Return value** 

| Type                                      | Description                         |
| ---------------------------------------- | --------------------------- |
| [OffscreenCanvasRenderingContext2D](js-offscreencanvasrenderingcontext2d.md) | 2D drawing object, which can be used to draw rectangles, images, and texts, on the **OffscreenCanvas**.|

### CanvasRenderingContext2DSettings

CanvasRenderingContext2DSettings(antialias?: boolean)

Configures the settings of an **OffscreenCanvasRenderingContext2D** object, including whether to enable antialiasing.

| Name      | Type     | Description                 |
| --------- | ------- | ------------------- |
| antialias | boolean | Whether to enable anti-aliasing. The default value is **false**.|

### toDataURL

toDataURL(type?: string, quality?:number): string

Generates a URL containing image display information.

**Parameters**

| Name    | Type  | Mandatory  | Description                                      |
| ------- | ------ | ---- | ---------------------------------------- |
| type    | string | No   | Image format. The default value is **image/png**.           |
| quality | number | No   | Image quality, which ranges from 0 to 1, when the image format is **image/jpeg** or **image/webp**. If the set value is beyond the value range, the default value **0.92** is used.|

**Return value** 

| Type    | Description       |
| ------ | --------- |
| string | Image URL.|


### transferToImageBitmap

transferToImageBitmap(): ImageBitmap

Creates an **ImageBitmap** object on the most recently rendered image of the **OffscreenCanvas**.

**Return value** 

| Type                                      | Description             |
| ---------------------------------------- | --------------- |
| [ImageBitmap](js-components-canvas-imagebitmap.md) | Pixel data rendered on the **OffscreenCanvas**.|


## Example

```html
<!-- xxx.hml -->
<div>
  <canvas ref="canvasId" style="width: 200px; height: 150px; background-color: #ffff00;"></canvas>
</div>
```

```js
//xxx.js
export default {
  onShow() {
    var canvas = this.$refs.canvasId.getContext('2d');
    var offscreen = new OffscreenCanvas(500,500);
    var offscreenCanvasCtx = offscreen.getContext("2d");

    // ... some drawing for the canvas using the offscreenCanvasCtx ...

    var dataURL = offscreen.toDataURL();
    console.log(dataURL); //data:image/png;base64,xxxxxx

    var bitmap = offscreen.transferToImageBitmap();
    canvas.transferFromImageBitmap(bitmap);
  }
}
```
