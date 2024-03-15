# Image

>  **NOTE**
>
>  This component is supported since API version 4. Updates will be marked with a superscript to indicate their earliest API version.

The **Image** object is an image on the canvas.


## Attributes

| Name     | Type            | Default Value | Mandatory  | Description               |
| ------- | -------------- | ---- | ---- | ----------------- |
| src     | string         | -    | Yes   | Image resource path.         |
| width   | &lt;length&gt; | 0px  | No   | Image width.           |
| height  | &lt;length&gt; | 0px  | No   | Image height.           |
| onload  | Function       | -    | No   | Function called when an image is successfully loaded. This function has no parameter.|
| onerror | Function       | -    | No   | Function called when an image fails to be loaded. This function has no parameter.|


## Example

```html
<!-- xxx.hml -->
<div>
  <canvas ref="canvas" style="width: 500px; height: 500px; "></canvas>
</div>
```

```js
// xxx.js
export default {
    onShow() {
        const el = this.$refs.canvas;
        var ctx = el.getContext('2d');
        var img = new Image();
        // It is recommended that the image be stored in the common directory.
        img.src = 'common/images/example.jpg';
        img.onload = function () {
            console.log('Image load success');
            ctx.drawImage(img, 0, 0, 360, 250);
        };
        img.onerror = function () {
            console.log('Image load fail');
        };
    }
}
```


![1-9](figures/1-9.png)
