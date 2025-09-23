# OffscreenCanvasRenderingContext2D
<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @sd-wu-->
<!--Designer: @sunbees-->
<!--Tester: @liuli0427-->
<!--Adviser: @HelloCrease-->

**OffscreenCanvasRenderingContext2D** allows you to draw rectangles, text, images, and other objects on an offscreen canvas, which is a new buffer created by the GPU outside of the current buffer. For details, see [OffscreenCanvasRenderingContext2D](../reference/apis-arkui/arkui-js/js-offscreencanvasrenderingcontext2d.md).

In the following example, you first create an offscreen canvas, and then create a **getContext2d** object on the canvas, which is an image, and finally set the **filter** attribute for the image.

```html
<!-- xxx.hml -->
<div class="container">
  <canvas ref="canvas1"></canvas>
  <select @change="change()">
    <option value="blur(5px)">blur</option>
    <option value="grayscale(50%)">grayscale</option>
    <option value="hue-rotate(45deg)">hue-rotate</option>
    <option value="invert(100%)">invert</option>
    <option value="drop-shadow(8px 8px 10px green)">drop-shadow</option>
    <option value="brightness(0.4)">brightness</option>
    <option value="opacity(0.25)">opacity</option>
    <option value="saturate(30%)">saturate</option>
    <option value="sepia(60%)">sepia</option>
    <option value="contrast(200%)">contrast</option>
  </select>
</div>
```

```css
/* xxx.css */
.container{
  width: 100%;
  height: 100%;
  flex-direction: column;
  justify-content: center;
  align-items: center;
  background-color: #F1F3F5;
}
canvas{
  width: 600px;
  height: 500px;
  background-color: #fdfdfd;
  border: 5px solid red;
}
select{
  margin-top: 50px;
  width: 250px;
  height: 100px;
  background-color: white;
}
```

```js
// xxx.js
import promptAction from '@ohos.promptAction';
export default {
  data:{
    el: null,
    ctx: null,
    offscreen: null,
    offCanvas: null,
    img: null,
  },
  onShow(){
    this.ctx = this.$refs.canvas1.getContext("2d");
    this.offscreen = new OffscreenCanvas(600, 500);
    this.offCanvas = this.offscreen.getContext("2d");
    this.img = new Image();
    // Replace "common/images/2.png" with the image resource file you use.
    this.img.src = 'common/images/2.png';
    // Invoked when the image is successfully obtained.
    let _this = this;
    this.img.onload = function() {
      _this.offCanvas.drawImage(_this.img, 100, 100, 400, 300);
    };
    this.img.onerror = function() {
      promptAction.showToast({message:"error",duration:2000})
    };
    var bitmap = this.offscreen.transferToImageBitmap();
    this.ctx.transferFromImageBitmap(bitmap);
  },
  change(e){
    this.offCanvas.filter = e.newValue;this.offCanvas.drawImage(this.img, 100, 100, 400, 300);
    var bitmap = this.offscreen.transferToImageBitmap();
    this.ctx.transferFromImageBitmap(bitmap);
  },
}
```


![en-us_image_0000001232162292](figures/en-us_image_0000001232162292.gif)


## Determining the Position

Use **isPointInPath** to determine whether a coordinate is within the path area and use **isPointInStroke** to determine whether a coordinate is on the edge of the path.


```html
<!-- xxx.hml -->
<div class="container">
  <div class="content">
    <text>Coordinate: {{X}}, {{Y}}</text>
    <text>In path:{{textValue}}</text>
    <text>In stroke:{{textValue1}}</text>
  </div>
  <canvas ref="canvas"></canvas>
  <button onclick="change">Add(50)</button>
</div>
```


```css
/* xxx.css */
.container{
  width: 100%;
  height: 100%;
  flex-direction: column;
  justify-content: center;
  align-items: center;
  background-color: #F1F3F5;
  display: flex;
}
canvas{
  width: 600px;
  height: 500px;
  background-color: #fdfdfd;
  border: 5px solid red;
}
.content{
  flex-direction: column;
  justify-content: center;
  align-items: center; 
}
text{
  font-size: 30px;
  width: 300px;
  height: 80px;
  text-align: center;
}
button{
  width: 180px;
  height: 75px;
  margin-top: 50px;
}
```


```js
// xxx.js
export default {
  data: {
    textValue: 0,
    textValue1: 0,
    X:0,
    Y:250,
  },
  onShow(){
    let canvas = this.$refs.canvas.getContext('2d');
    let offscreen = new OffscreenCanvas(500,500);
    let offscreenCanvasCtx = offscreen.getContext("2d");
    let offscreenCanvasCtx1 = offscreen.getContext("2d");
    offscreenCanvasCtx1.arc(this.X, this.Y, 2, 0, 6.28);
    offscreenCanvasCtx.lineWidth=20;
    offscreenCanvasCtx.rect(200,150, 200, 200);
    offscreenCanvasCtx.stroke();
    this.textValue1 = offscreenCanvasCtx.isPointInStroke(this.X, this.Y)?'true':'false';
    this.textValue = offscreenCanvasCtx.isPointInPath(this.X, this.Y)?'true':'false';
    let bitmap = offscreen.transferToImageBitmap();
    canvas.transferFromImageBitmap(bitmap);
  },
  change(){
    if(this.X < 500){
      this.X = this.X+50;
    }else{
      this.X = 0;
    }
    let canvas = this.$refs.canvas.getContext('2d');
    let offscreen = new OffscreenCanvas(500,500);
    let offscreenCanvasCtx = offscreen.getContext("2d");
    let offscreenCanvasCtx1 = offscreen.getContext("2d");
    offscreenCanvasCtx1.arc(this.X, this.Y, 1, 0, 6.28)
    offscreenCanvasCtx.lineWidth=20
    offscreenCanvasCtx.rect(200,150, 200, 200);
    offscreenCanvasCtx.stroke();
    this.textValue1 = offscreenCanvasCtx.isPointInStroke(this.X, this.Y)?'true':'false';
    this.textValue = offscreenCanvasCtx.isPointInPath(this.X, this.Y)?'true':'false';
    let bitmap = offscreen.transferToImageBitmap();
    canvas.transferFromImageBitmap(bitmap);
  }
}
```

![en-us_image_0000001178084014](figures/en-us_image_0000001178084014.gif)
