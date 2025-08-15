# ImageData对象
<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @sd-wu-->
<!--Designer: @sunbees-->
<!--Tester: @liuli0427-->
<!--Adviser: @HelloCrease-->

>  **说明：**
>  从API version 4开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。

ImageData对象可以存储[canvas组件](js-components-canvas-canvas.md)渲染的像素数据。


## 属性

| 属性     | 类型                        | 描述                           |
| ------ | ------------------------- | ---------------------------- |
| width  | number                    | 矩形区域实际像素宽度。                  |
| height | number                    | 矩形区域实际像素高度。                  |
| data   | &lt;Uint8ClampedArray&gt; | 一维数组，保存了相应的颜色数据，数据值范围为0到255。 |


## 示例

```html
<!-- xxx.hml -->
<div>
  <canvas ref="canvas" style="width: 500px; height: 500px; background-color: #ffff00;"></canvas>
</div>
```

```js
// xxx.js
import promptAction from '@ohos.promptAction';
export default {
  onShow() {
    const el =this.$refs.canvas;
    const ctx = el.getContext('2d');
    ctx.fillRect(0,0,200,200);
    var imageData = ctx.createImageData(1,1);
    promptAction.showToast({
      message:imageData,
      duration:5000
    })
  }
}
```
