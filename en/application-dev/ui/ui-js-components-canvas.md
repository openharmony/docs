# &lt;canvas&gt; Development
<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @sd-wu-->
<!--Designer: @sunbees-->
<!--Tester: @liuli0427-->
<!--Adviser: @HelloCrease-->


The **&lt;canvas&gt;** component provides a canvas for drawing customized graphics. For details, see [canvas](../reference/apis-arkui/arkui-js/js-components-canvas-canvas.md).


## Creating a &lt;canvas&gt; Component

Create a **&lt;canvas&gt;** component in the .hml file under **pages/index**.


```html
<!-- xxx.hml -->
<div class="container">
  <canvas></canvas>
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
  background-color: #00ff73;
}
```

![en-us_image_0000001232162316](figures/en-us_image_0000001232162316.png)

> **NOTE**
>
> - The default background color of the **&lt;canvas&gt;** component is the same as that of the parent component.
>
> - The default width and height of **&lt;canvas&gt;** are 300 px and 150 px, respectively.


## Adding Styles

Set **width**, **height**, **background-color**, and **border** of the **&lt;canvas&gt;** component.


```html
<!-- xxx.hml -->
<div class="container">
  <canvas></canvas>
</div>
```


```css
/* xxx.css */
.container{
  flex-direction: column;
  justify-content: center;
  align-items: center;
  background-color: #F1F3F5;
  width: 100%;
  height: 100%;
}
canvas{
  width: 500px;
  height: 500px;  
  background-color: #fdfdfd;  
  border: 5px solid red;
}
```

![en-us_image_0000001231843104](figures/en-us_image_0000001231843104.png)


## Adding Events

Add the long press event to the **&lt;canvas&gt;** component. When the event is triggered, the value of **dataUrl** (image information returned by the **toDataURL** method) of the **&lt;canvas&gt;** component can be obtained and printed in the text area below.


```html
<!-- xxx.hml -->
<div class="container">
  <canvas ref="canvas1" onlongpress="getUrl"></canvas>
  <text>dataURL</text>
  <text class="content">{{dataURL}}</text>
</div>
```


```css
/* xxx.css */
.container{
  width:100%;
  height:100%;
  flex-direction: column;
  justify-content: center;
  align-items: center;
  background-color: #F1F3F5;
  }
  canvas{  
    width: 500px;  
    height: 500px;
    background-color: #fdfdfd;
    border: 5px solid red;
    margin-bottom: 50px;
}
.content{
  border: 5px solid blue;
  padding: 10px;
  width: 90%;
  height: 400px; 
  overflow: scroll;
}
```


```js
// xxx.js
import promptAction from '@ohos.promptAction';
export default {
  data:{
    dataURL:null,
  },
  onShow(){
    let el = this.$refs.canvas1;
    let ctx = el.getContext("2d"); 
    ctx.strokeRect(100,100,300,300);
  },
  getUrl(){
    let el = this.$refs.canvas1
    let dataUrl = el.toDataURL()
    this.dataURL = dataUrl;
    promptAction.showToast({duration:2000,message:"long press,get dataURL"})
  }
}
```

![en-us_image_0000001276003513](figures/en-us_image_0000001276003513.gif)

> **NOTE**
>
> The **&lt;canvas&gt;** component cannot be created in **onInit** or **onReady**.
