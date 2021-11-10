# OffscreenCanvasRenderingContext2D对象<a name="ZH-CN_TOPIC_0000001180864495"></a>

>![](../../public_sys-resources/icon-note.gif) **说明：** 
>从API Version 7 开始支持。

使用OffscreenCanvasRenderingContext2D在offscreen canvas上进行绘制，绘制对象可以是矩形、文本、图片等

## 属性<a name="section661391987"></a>

除支持与CanvasRenderingContext2D对象相同的属性外，还支持如下属性：

<a name="table67211828124016"></a>
<table><thead align="left"><tr id="row108577289405"><th class="cellrowborder" valign="top" width="22.872287228722872%" id="mcps1.1.4.1.1"><p id="p385742814403"><a name="p385742814403"></a><a name="p385742814403"></a>属性</p>
</th>
<th class="cellrowborder" valign="top" width="29.352935293529352%" id="mcps1.1.4.1.2"><p id="p19857192816408"><a name="p19857192816408"></a><a name="p19857192816408"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="47.774777477747776%" id="mcps1.1.4.1.3"><p id="p18573288402"><a name="p18573288402"></a><a name="p18573288402"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row85971918336"><td class="cellrowborder" valign="top" width="22.872287228722872%" headers="mcps1.1.4.1.1 "><p id="p155980933313"><a name="p155980933313"></a><a name="p155980933313"></a>filter</p>
</td>
<td class="cellrowborder" valign="top" width="29.352935293529352%" headers="mcps1.1.4.1.2 "><p id="p735764418306"><a name="p735764418306"></a><a name="p735764418306"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="47.774777477747776%" headers="mcps1.1.4.1.3 "><p id="p1059819912335"><a name="p1059819912335"></a><a name="p1059819912335"></a>设置图像的滤镜。</p>
<p id="p4505204453214"><a name="p4505204453214"></a><a name="p4505204453214"></a>支持的滤镜效果如下：</p>
<a name="ul03421175334"></a><a name="ul03421175334"></a><ul id="ul03421175334"><li>blur：给图像设置高斯模糊</li><li>brightness：给图片应用一种线性乘法，使其看起来更亮或更暗</li><li>contrast：调整图像的对比度</li><li>drop-shadow：给图像设置一个阴影效果</li><li>grayscale：将图像转换为灰度图像</li><li>hue-rotate：给图像应用色相旋转</li><li>invert：反转输入图像</li><li>opacity：转化图像的透明程度</li><li>saturate：转换图像饱和度</li><li>sepia：将图像转换为深褐色</li></ul>
</td>
</tr>
</tbody>
</table>

-   示例

```
var ctx = this.$refs.canvasid.getContext('2d');
var offscreen = new OffscreenCanvas(360, 500);
var offCanvas2 = offscreen.getContext("2d");
var img = new Image();
img.src = 'common/images/flower.jpg';
offCanvas2.drawImage(img, 0, 0, 100, 100);
offCanvas2.filter = 'blur(5px)';
offCanvas2.drawImage(img, 100, 0, 100, 100);

offCanvas2.filter = 'grayscale(50%)';
offCanvas2.drawImage(img, 200, 0, 100, 100);

offCanvas2.filter = 'hue-rotate(90deg)';
offCanvas2.drawImage(img, 0, 100, 100, 100);

offCanvas2.filter = 'invert(100%)';
offCanvas2.drawImage(img, 100, 100, 100, 100);

offCanvas2.filter = 'drop-shadow(8px 8px 10px green)';
offCanvas2.drawImage(img, 200, 100, 100, 100);

offCanvas2.filter = 'brightness(0.4)';
offCanvas2.drawImage(img, 0, 200, 100, 100);

offCanvas2.filter = 'opacity(25%)';
offCanvas2.drawImage(img, 100, 200, 100, 100);

offCanvas2.filter = 'saturate(30%)';
offCanvas2.drawImage(img, 200, 200, 100, 100);

offCanvas2.filter = 'sepia(60%)';
offCanvas2.drawImage(img, 0, 300, 100, 100);

offCanvas2.filter = 'contrast(200%)';
offCanvas2.drawImage(img, 100, 300, 100, 100);
var bitmap = offscreen.transferToImageBitmap();
ctx.transferFromImageBitmap(bitmap);
```

![](figures/zh-cn_image_0000001152773860.png)

## 方法<a name="section47669296127"></a>

除支持与CanvasRenderingContext2D对象相同的方法外，还支持如下方法：

<a name="td0f869ce272e4d90b1c7df558ad7635e"></a>
<table><thead align="left"><tr id="rf11e90428c78465b9e3a0c3ec2222a3c"><th class="cellrowborder" valign="top" width="10.81%" id="mcps1.1.4.1.1"><p id="a11b4cb4edcf14b5584841b089cbea895"><a name="a11b4cb4edcf14b5584841b089cbea895"></a><a name="a11b4cb4edcf14b5584841b089cbea895"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="26.19%" id="mcps1.1.4.1.2"><p id="ac56fe081db8a4ddca537c39d9abfcd33"><a name="ac56fe081db8a4ddca537c39d9abfcd33"></a><a name="ac56fe081db8a4ddca537c39d9abfcd33"></a>参数</p>
</th>
<th class="cellrowborder" valign="top" width="63%" id="mcps1.1.4.1.3"><p id="a05cdd2c741a54fe3a44575a5b2384be3"><a name="a05cdd2c741a54fe3a44575a5b2384be3"></a><a name="a05cdd2c741a54fe3a44575a5b2384be3"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="r960677f8f5e64d7f9b33b8a0ae0c824f"><td class="cellrowborder" valign="top" width="10.81%" headers="mcps1.1.4.1.1 "><p id="p931916913120"><a name="p931916913120"></a><a name="p931916913120"></a>isPointInPath</p>
<p id="p11907165844810"><a name="p11907165844810"></a><a name="p11907165844810"></a></p>
</td>
<td class="cellrowborder" valign="top" width="26.19%" headers="mcps1.1.4.1.2 "><p id="p13193144905014"><a name="p13193144905014"></a><a name="p13193144905014"></a>path?: Path2D, x: number, y: number</p>
</td>
<td class="cellrowborder" valign="top" width="63%" headers="mcps1.1.4.1.3 "><p id="p16545402518"><a name="p16545402518"></a><a name="p16545402518"></a>判断指定点是否在路径的区域内。</p>
<p id="p18921037165115"><a name="p18921037165115"></a><a name="p18921037165115"></a>path：可选对象，指定用来判断的路径。若没有设置，则使用当前路径</p>
<p id="p10885826185416"><a name="p10885826185416"></a><a name="p10885826185416"></a>x：待判断点的x轴坐标</p>
<p id="p17751133085419"><a name="p17751133085419"></a><a name="p17751133085419"></a>y：待判断点的y轴坐标</p>
</td>
</tr>
<tr id="row13364759185512"><td class="cellrowborder" valign="top" width="10.81%" headers="mcps1.1.4.1.1 "><p id="p5364145915552"><a name="p5364145915552"></a><a name="p5364145915552"></a>isPointInStroke</p>
</td>
<td class="cellrowborder" valign="top" width="26.19%" headers="mcps1.1.4.1.2 "><p id="p162714244571"><a name="p162714244571"></a><a name="p162714244571"></a>path?: Path2D, x: number, y: number</p>
</td>
<td class="cellrowborder" valign="top" width="63%" headers="mcps1.1.4.1.3 "><p id="p1336455955512"><a name="p1336455955512"></a><a name="p1336455955512"></a>判断指定点是否在路径的边缘线上。</p>
<p id="p1362284019185"><a name="p1362284019185"></a><a name="p1362284019185"></a>path：可选对象，指定用来判断的路径。若没有设置，则使用当前路径</p>
<p id="p1262224011185"><a name="p1262224011185"></a><a name="p1262224011185"></a>x：待判断点的x轴坐标</p>
<p id="p66220409182"><a name="p66220409182"></a><a name="p66220409182"></a>y：待判断点的y轴坐标</p>
</td>
</tr>
<tr id="row477613917194"><td class="cellrowborder" valign="top" width="10.81%" headers="mcps1.1.4.1.1 "><p id="p107779911916"><a name="p107779911916"></a><a name="p107779911916"></a>resetTransform</p>
</td>
<td class="cellrowborder" valign="top" width="26.19%" headers="mcps1.1.4.1.2 "><p id="p107771192192"><a name="p107771192192"></a><a name="p107771192192"></a>无</p>
</td>
<td class="cellrowborder" valign="top" width="63%" headers="mcps1.1.4.1.3 "><p id="p277714913197"><a name="p277714913197"></a><a name="p277714913197"></a>将当前变换重置为单位矩阵。</p>
</td>
</tr>
</tbody>
</table>

-   isPointInPath示例

![](figures/zh-cn_image_0000001181449919.png)

```
<!-- xxx.hml -->
<div style="width: 180px; height: 60px;">
  <text>In path:{{textValue}}</text>
</div>
<canvas ref="canvasId" style="width: 500px; height: 500px; background-color: #ffff00;"></canvas>
```

```
// xxx.js
export default {
  data: {
    textValue: 0
  },
  onShow(){
    var canvas = this.$refs.canvas.getContext('2d');
    var offscreen = new OffscreenCanvas(500,500);
    var offscreenCanvasCtx = offscreen.getContext("2d");

    offscreenCanvasCtx.rect(10, 10, 100, 100);
    offscreenCanvasCtx.fill();
    this.textValue = offscreenCanvasCtx.isPointInPath(30, 70);

    var bitmap = offscreen.transferToImageBitmap();
    canvas.transferFromImageBitmap(bitmap);
  }
}
```

-   isPointInStroke示例

![](figures/zh-cn_image_0000001181458721.png)

```
<!-- xxx.hml -->
<div style="width: 180px; height: 60px;">
  <text>In path:{{textValue}}</text>
</div>
<canvas ref="canvasId" style="width: 500px; height: 500px; background-color: #ffff00;"></canvas>
```

```
// xxx.js
export default {
  data: {
    textValue: 0
  },
  onShow(){
    var canvas = this.$refs.canvas.getContext('2d');
    var offscreen = new OffscreenCanvas(500,500);
    var offscreenCanvasCtx = offscreen.getContext("2d");

    offscreenCanvasCtx.rect(10, 10, 100, 100);
    offscreenCanvasCtx.stroke();
    this.textValue = offscreenCanvasCtx.isPointInStroke(50, 10);

    var bitmap = offscreen.transferToImageBitmap();
    canvas.transferFromImageBitmap(bitmap);
  }
}
```

-   resetTransform示例

![](figures/zh-cn_image_0000001135171488.png)

```
var canvas = this.$refs.canvas.getContext('2d');
var offscreen = new OffscreenCanvas(500,500);
var offscreenCanvasCtx = offscreen.getContext("2d");

offscreenCanvasCtx.transform(1, 0, 1.7, 1, 0, 0);
offscreenCanvasCtx.fillStyle = 'gray';
offscreenCanvasCtx.fillRect(40, 40, 50, 20);
offscreenCanvasCtx.fillRect(40, 90, 50, 20);

// Non-skewed rectangles
offscreenCanvasCtx.resetTransform();
offscreenCanvasCtx.fillStyle = 'red';
offscreenCanvasCtx.fillRect(40, 40, 50, 20);
offscreenCanvasCtx.fillRect(40, 90, 50, 20);

var bitmap = offscreen.transferToImageBitmap();
canvas.transferFromImageBitmap(bitmap);
```

