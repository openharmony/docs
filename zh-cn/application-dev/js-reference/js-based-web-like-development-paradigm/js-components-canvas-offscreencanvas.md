# OffscreenCanvas对象<a name="ZH-CN_TOPIC_0000001180744579"></a>

>![](../../public_sys-resources/icon-note.gif) **说明：** 
>从API Version 7 开始支持。

可以离屏渲染的canvas对象。

## 属性<a name="section661391987"></a>

<a name="table67211828124016"></a>
<table><thead align="left"><tr id="row108577289405"><th class="cellrowborder" valign="top" width="22.872287228722872%" id="mcps1.1.4.1.1"><p id="p385742814403"><a name="p385742814403"></a><a name="p385742814403"></a>属性</p>
</th>
<th class="cellrowborder" valign="top" width="29.352935293529352%" id="mcps1.1.4.1.2"><p id="p19857192816408"><a name="p19857192816408"></a><a name="p19857192816408"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="47.774777477747776%" id="mcps1.1.4.1.3"><p id="p18573288402"><a name="p18573288402"></a><a name="p18573288402"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row1085792824019"><td class="cellrowborder" valign="top" width="22.872287228722872%" headers="mcps1.1.4.1.1 "><p id="p1485792815404"><a name="p1485792815404"></a><a name="p1485792815404"></a>width</p>
</td>
<td class="cellrowborder" valign="top" width="29.352935293529352%" headers="mcps1.1.4.1.2 "><p id="p11857182804010"><a name="p11857182804010"></a><a name="p11857182804010"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="47.774777477747776%" headers="mcps1.1.4.1.3 "><p id="p1785711281405"><a name="p1785711281405"></a><a name="p1785711281405"></a>offscreen canvas对象的宽度。</p>
</td>
</tr>
<tr id="row3857132812406"><td class="cellrowborder" valign="top" width="22.872287228722872%" headers="mcps1.1.4.1.1 "><p id="p88572283404"><a name="p88572283404"></a><a name="p88572283404"></a>height</p>
</td>
<td class="cellrowborder" valign="top" width="29.352935293529352%" headers="mcps1.1.4.1.2 "><p id="p198571828114017"><a name="p198571828114017"></a><a name="p198571828114017"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="47.774777477747776%" headers="mcps1.1.4.1.3 "><p id="p3857192844012"><a name="p3857192844012"></a><a name="p3857192844012"></a>offscreen canvas对象的高度。</p>
</td>
</tr>
</tbody>
</table>

## 方法<a name="section47669296127"></a>

<a name="td0f869ce272e4d90b1c7df558ad7635e"></a>
<table><thead align="left"><tr id="rf11e90428c78465b9e3a0c3ec2222a3c"><th class="cellrowborder" valign="top" width="11.68%" id="mcps1.1.4.1.1"><p id="a11b4cb4edcf14b5584841b089cbea895"><a name="a11b4cb4edcf14b5584841b089cbea895"></a><a name="a11b4cb4edcf14b5584841b089cbea895"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="25.319999999999997%" id="mcps1.1.4.1.2"><p id="ac56fe081db8a4ddca537c39d9abfcd33"><a name="ac56fe081db8a4ddca537c39d9abfcd33"></a><a name="ac56fe081db8a4ddca537c39d9abfcd33"></a>参数</p>
</th>
<th class="cellrowborder" valign="top" width="63%" id="mcps1.1.4.1.3"><p id="a05cdd2c741a54fe3a44575a5b2384be3"><a name="a05cdd2c741a54fe3a44575a5b2384be3"></a><a name="a05cdd2c741a54fe3a44575a5b2384be3"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="r960677f8f5e64d7f9b33b8a0ae0c824f"><td class="cellrowborder" valign="top" width="11.68%" headers="mcps1.1.4.1.1 "><p id="p931916913120"><a name="p931916913120"></a><a name="p931916913120"></a>getContext</p>
</td>
<td class="cellrowborder" valign="top" width="25.319999999999997%" headers="mcps1.1.4.1.2 "><p id="p123073254554"><a name="p123073254554"></a><a name="p123073254554"></a>contextId: "2d", options?: CanvasRenderingContext2DSettings</p>
</td>
<td class="cellrowborder" valign="top" width="63%" headers="mcps1.1.4.1.3 "><p id="p176180219405"><a name="p176180219405"></a><a name="p176180219405"></a>调用方法如下两种：</p>
<p id="p1161802114405"><a name="p1161802114405"></a><a name="p1161802114405"></a>var ctx = canvas.getContext(contextId);</p>
<p id="p1161882115404"><a name="p1161882115404"></a><a name="p1161882115404"></a>var ctx = canvas.getContext(contextId, options);</p>
<p id="p1361802194016"><a name="p1361802194016"></a><a name="p1361802194016"></a>其中contextId为必填项，当前仅支持"2d"，options为可选项，暂时不支持。</p>
<p id="p1260014407342"><a name="p1260014407342"></a><a name="p1260014407342"></a>获取offscreen canvas绘图上下文，参数仅支持“2d”，返回值为2D绘制对象，该对象提供具体的2D绘制操作。详见<a href="js-offscreencanvasrenderingcontext2d.md">OffscreenCanvasRenderingContext2D</a>对象章节。</p>
</td>
</tr>
<tr id="row13364759185512"><td class="cellrowborder" valign="top" width="11.68%" headers="mcps1.1.4.1.1 "><p id="p93374133418"><a name="p93374133418"></a><a name="p93374133418"></a>toDataURL</p>
</td>
<td class="cellrowborder" valign="top" width="25.319999999999997%" headers="mcps1.1.4.1.2 "><p id="p74131655155410"><a name="p74131655155410"></a><a name="p74131655155410"></a>type?: string, quality?: number</p>
</td>
<td class="cellrowborder" valign="top" width="63%" headers="mcps1.1.4.1.3 "><p id="p1336455955512"><a name="p1336455955512"></a><a name="p1336455955512"></a>生成一个包含图片展示的URL。</p>
<a name="ul155726311612"></a><a name="ul155726311612"></a><ul id="ul155726311612"><li>type：可选参数，用于指定图像格式，默认格式为image/png。</li><li>quality：在指定图片格式为image/jpeg或image/webp的情况下，可以从0到1的区间内选择图片的质量。如果超出取值范围，将会使用默认值0.92。</li></ul>
</td>
</tr>
<tr id="row1350184614429"><td class="cellrowborder" valign="top" width="11.68%" headers="mcps1.1.4.1.1 "><p id="p11501134614422"><a name="p11501134614422"></a><a name="p11501134614422"></a>transferToImageBitmap</p>
</td>
<td class="cellrowborder" valign="top" width="25.319999999999997%" headers="mcps1.1.4.1.2 "><p id="p135011946194215"><a name="p135011946194215"></a><a name="p135011946194215"></a>无</p>
</td>
<td class="cellrowborder" valign="top" width="63%" headers="mcps1.1.4.1.3 "><p id="p20502164624212"><a name="p20502164624212"></a><a name="p20502164624212"></a>从OffscreenCanvas最近渲染的图像创建一个 ImageBitmap 对象</p>
</td>
</tr>
</tbody>
</table>

## 示例<a name="section13457717134912"></a>

```
var canvas = this.$refs.canvasId.getContext('2d');
var offscreen = new OffscreenCanvas(500,500);
var offscreenCanvasCtx = offscreen.getContext("2d");

// ... some drawing for the canvas using the offscreenCanvasCtx ...

var dataURL = offscreen.toDataURL();
console.log(dataURL); //data:image/png;base64,xxxxxx

var bitmap = offscreen.transferToImageBitmap();
canvas.transferFromImageBitmap(bitmap);
```

