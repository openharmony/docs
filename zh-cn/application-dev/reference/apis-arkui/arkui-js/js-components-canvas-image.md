# Image对象

>  **说明：**
>  从API version 4开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。

图片对象。


## 属性

| 属性      | 类型             | 默认值  | 必填   | 描述                |
| ------- | -------------- | ---- | ---- | ----------------- |
| src     | string         | -    | 是    | 图片资源的路径。          |
| width   | &lt;length&gt; | 0px  | 否    | 图片的宽度。            |
| height  | &lt;length&gt; | 0px  | 否    | 图片的高度。            |
| onload  | Function       | -    | 否    | 图片加载成功后触发该事件，无参数。 |
| onerror | Function       | -    | 否    | 图片加载失败后触发该事件，无参数。 |


## 示例

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
        // 图片路径建议放在common目录下
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


![zh-cn_image_0000001198530395](figures/zh-cn_image_0000001198530395.png)
