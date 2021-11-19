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

![](figures/c3.png)

## 方法<a name="section47669296127"></a>

除支持与CanvasRenderingContext2D对象相同的方法外，还支持如下方法：

### isPointInPath<a name="section12576152143713"></a>

isPointInPath\(path?: Path2D, x: number, y: number\): boolean

判断指定点是否在路径的区域内。

-   参数

    <a name="table3592161817496"></a>
    <table><thead align="left"><tr id="row19592141864916"><th class="cellrowborder" valign="top" width="21.04%" id="mcps1.1.5.1.1"><p id="p229575610288"><a name="p229575610288"></a><a name="p229575610288"></a>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="15.260000000000002%" id="mcps1.1.5.1.2"><p id="p929585682819"><a name="p929585682819"></a><a name="p929585682819"></a>参数类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="7.5200000000000005%" id="mcps1.1.5.1.3"><p id="p988715163459"><a name="p988715163459"></a><a name="p988715163459"></a>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="56.18%" id="mcps1.1.5.1.4"><p id="p1929645618282"><a name="p1929645618282"></a><a name="p1929645618282"></a>描述</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row1559261834915"><td class="cellrowborder" valign="top" width="21.04%" headers="mcps1.1.5.1.1 "><p id="p115927183493"><a name="p115927183493"></a><a name="p115927183493"></a>path</p>
    </td>
    <td class="cellrowborder" valign="top" width="15.260000000000002%" headers="mcps1.1.5.1.2 "><p id="p95921918114914"><a name="p95921918114914"></a><a name="p95921918114914"></a>Path2D</p>
    </td>
    <td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.5.1.3 "><p id="p1188716161453"><a name="p1188716161453"></a><a name="p1188716161453"></a>否</p>
    </td>
    <td class="cellrowborder" valign="top" width="56.18%" headers="mcps1.1.5.1.4 "><p id="p168291512124013"><a name="p168291512124013"></a><a name="p168291512124013"></a>可选对象，指定用来判断的路径。若没有设置，则使用当前路径。</p>
    </td>
    </tr>
    <tr id="row195921118184916"><td class="cellrowborder" valign="top" width="21.04%" headers="mcps1.1.5.1.1 "><p id="p1622015388394"><a name="p1622015388394"></a><a name="p1622015388394"></a>x</p>
    </td>
    <td class="cellrowborder" valign="top" width="15.260000000000002%" headers="mcps1.1.5.1.2 "><p id="p1635295333919"><a name="p1635295333919"></a><a name="p1635295333919"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.5.1.3 "><p id="p17887616174515"><a name="p17887616174515"></a><a name="p17887616174515"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="56.18%" headers="mcps1.1.5.1.4 "><p id="p6592518124911"><a name="p6592518124911"></a><a name="p6592518124911"></a>待判断点的x轴坐标。</p>
    </td>
    </tr>
    <tr id="row449114413392"><td class="cellrowborder" valign="top" width="21.04%" headers="mcps1.1.5.1.1 "><p id="p1349212448390"><a name="p1349212448390"></a><a name="p1349212448390"></a>y</p>
    </td>
    <td class="cellrowborder" valign="top" width="15.260000000000002%" headers="mcps1.1.5.1.2 "><p id="p44927443396"><a name="p44927443396"></a><a name="p44927443396"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.5.1.3 "><p id="p18888101694519"><a name="p18888101694519"></a><a name="p18888101694519"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="56.18%" headers="mcps1.1.5.1.4 "><p id="p79061374406"><a name="p79061374406"></a><a name="p79061374406"></a>待判断点的y轴坐标。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   返回值

    <a name="table0782932202818"></a>
    <table><thead align="left"><tr id="row3782832172814"><th class="cellrowborder" valign="top" width="19.77%" id="mcps1.1.3.1.1"><p id="p1278314323284"><a name="p1278314323284"></a><a name="p1278314323284"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="80.23%" id="mcps1.1.3.1.2"><p id="p17783153216281"><a name="p17783153216281"></a><a name="p17783153216281"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row278317321285"><td class="cellrowborder" valign="top" width="19.77%" headers="mcps1.1.3.1.1 "><p id="p98384418408"><a name="p98384418408"></a><a name="p98384418408"></a>boolean</p>
    </td>
    <td class="cellrowborder" valign="top" width="80.23%" headers="mcps1.1.3.1.2 "><p id="p1537310444489"><a name="p1537310444489"></a><a name="p1537310444489"></a>指定点是否在路径的区域内。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   示例

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

    ![](figures/zh-cn_image_0000001224354967.png)


### isPointInStroke<a name="section18889155054014"></a>

isPointInStroke\(path?: Path2D, x: number, y: number\): boolean

判断指定点是否在路径的边缘线上。

-   参数

    <a name="table101720539407"></a>
    <table><thead align="left"><tr id="row1317185315401"><th class="cellrowborder" valign="top" width="21.04%" id="mcps1.1.5.1.1"><p id="p71725384017"><a name="p71725384017"></a><a name="p71725384017"></a>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="15.260000000000002%" id="mcps1.1.5.1.2"><p id="p171715334016"><a name="p171715334016"></a><a name="p171715334016"></a>参数类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="7.5200000000000005%" id="mcps1.1.5.1.3"><p id="p1182841194515"><a name="p1182841194515"></a><a name="p1182841194515"></a>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="56.18%" id="mcps1.1.5.1.4"><p id="p171718539408"><a name="p171718539408"></a><a name="p171718539408"></a>描述</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row121716534405"><td class="cellrowborder" valign="top" width="21.04%" headers="mcps1.1.5.1.1 "><p id="p1717953184014"><a name="p1717953184014"></a><a name="p1717953184014"></a>path</p>
    </td>
    <td class="cellrowborder" valign="top" width="15.260000000000002%" headers="mcps1.1.5.1.2 "><p id="p171817535409"><a name="p171817535409"></a><a name="p171817535409"></a>Path2D</p>
    </td>
    <td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.5.1.3 "><p id="p8822419452"><a name="p8822419452"></a><a name="p8822419452"></a>否</p>
    </td>
    <td class="cellrowborder" valign="top" width="56.18%" headers="mcps1.1.5.1.4 "><p id="p91855319403"><a name="p91855319403"></a><a name="p91855319403"></a>可选对象，指定用来判断的路径。若没有设置，则使用当前路径。</p>
    </td>
    </tr>
    <tr id="row1181653114010"><td class="cellrowborder" valign="top" width="21.04%" headers="mcps1.1.5.1.1 "><p id="p518253104016"><a name="p518253104016"></a><a name="p518253104016"></a>x</p>
    </td>
    <td class="cellrowborder" valign="top" width="15.260000000000002%" headers="mcps1.1.5.1.2 "><p id="p17181653194010"><a name="p17181653194010"></a><a name="p17181653194010"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.5.1.3 "><p id="p48214116452"><a name="p48214116452"></a><a name="p48214116452"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="56.18%" headers="mcps1.1.5.1.4 "><p id="p518185344013"><a name="p518185344013"></a><a name="p518185344013"></a>待判断点的x轴坐标。</p>
    </td>
    </tr>
    <tr id="row118185354016"><td class="cellrowborder" valign="top" width="21.04%" headers="mcps1.1.5.1.1 "><p id="p91895354013"><a name="p91895354013"></a><a name="p91895354013"></a>y</p>
    </td>
    <td class="cellrowborder" valign="top" width="15.260000000000002%" headers="mcps1.1.5.1.2 "><p id="p1318953104011"><a name="p1318953104011"></a><a name="p1318953104011"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.5.1.3 "><p id="p782114119457"><a name="p782114119457"></a><a name="p782114119457"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="56.18%" headers="mcps1.1.5.1.4 "><p id="p2018195312409"><a name="p2018195312409"></a><a name="p2018195312409"></a>待判断点的y轴坐标。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   返回值

    <a name="table3572363195"></a>
    <table><thead align="left"><tr id="row1572669197"><th class="cellrowborder" valign="top" width="19.77%" id="mcps1.1.3.1.1"><p id="p1857211681912"><a name="p1857211681912"></a><a name="p1857211681912"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="80.23%" id="mcps1.1.3.1.2"><p id="p1257216171910"><a name="p1257216171910"></a><a name="p1257216171910"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row195722063190"><td class="cellrowborder" valign="top" width="19.77%" headers="mcps1.1.3.1.1 "><p id="p8572369196"><a name="p8572369196"></a><a name="p8572369196"></a>boolean</p>
    </td>
    <td class="cellrowborder" valign="top" width="80.23%" headers="mcps1.1.3.1.2 "><p id="p12572186101919"><a name="p12572186101919"></a><a name="p12572186101919"></a>指定点是否在路径的区域内。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   示例

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

    ![](figures/zh-cn_image_0000001178875308.png)


### resetTransform<a name="section1098812560426"></a>

resetTransform\(\): void

-   示例

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

    ![](figures/zh-cn_image_0000001179035242.png)


