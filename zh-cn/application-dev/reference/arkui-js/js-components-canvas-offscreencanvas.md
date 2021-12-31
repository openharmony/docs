# OffscreenCanvas对象<a name="ZH-CN_TOPIC_0000001180744579"></a>

>![](../../public_sys-resources/icon-note.gif) **说明：** 
>从API version 7开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。

可以离屏渲染的canvas对象。

## 属性<a name="section661391987"></a>

<table><thead align="left"><tr><th class="cellrowborder" valign="top" width="22.872287228722872%" id="mcps1.1.4.1.1"><p>属性</p>
</th>
<th class="cellrowborder" valign="top" width="29.352935293529352%" id="mcps1.1.4.1.2"><p>类型</p>
</th>
<th class="cellrowborder" valign="top" width="47.774777477747776%" id="mcps1.1.4.1.3"><p>描述</p>
</th>
</tr>
</thead>
<tbody><tr><td class="cellrowborder" valign="top" width="22.872287228722872%" headers="mcps1.1.4.1.1 "><p>width</p>
</td>
<td class="cellrowborder" valign="top" width="29.352935293529352%" headers="mcps1.1.4.1.2 "><p>number</p>
</td>
<td class="cellrowborder" valign="top" width="47.774777477747776%" headers="mcps1.1.4.1.3 "><p>offscreen canvas对象的宽度。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="22.872287228722872%" headers="mcps1.1.4.1.1 "><p>height</p>
</td>
<td class="cellrowborder" valign="top" width="29.352935293529352%" headers="mcps1.1.4.1.2 "><p>number</p>
</td>
<td class="cellrowborder" valign="top" width="47.774777477747776%" headers="mcps1.1.4.1.3 "><p>offscreen canvas对象的高度。</p>
</td>
</tr>
</tbody>
</table>

## 方法<a name="section47669296127"></a>

### getContext<a name="section18710131144813"></a>

getContext\(type: string, options?: CanvasRenderingContext2DSettings\): OffscreenCanvasRenderingContext2D

获取offscreen canvas绘图上下文，返回值为2D绘制对象。

-   参数

    <table><thead align="left"><tr><th class="cellrowborder" valign="top" width="14.63%" id="mcps1.1.5.1.1"><p>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="21.67%" id="mcps1.1.5.1.2"><p>参数类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="7.5200000000000005%" id="mcps1.1.5.1.3"><p>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="56.18%" id="mcps1.1.5.1.4"><p>描述</p>
    </th>
    </tr>
    </thead>
    <tbody><tr><td class="cellrowborder" valign="top" width="14.63%" headers="mcps1.1.5.1.1 "><p>contextId</p>
    </td>
    <td class="cellrowborder" valign="top" width="21.67%" headers="mcps1.1.5.1.2 "><p>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.5.1.3 "><p>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="56.18%" headers="mcps1.1.5.1.4 "><p>仅支持 '2d'。</p>
    </td>
    </tr>
    <tr><td class="cellrowborder" valign="top" width="14.63%" headers="mcps1.1.5.1.1 "><p>options</p>
    </td>
    <td class="cellrowborder" valign="top" width="21.67%" headers="mcps1.1.5.1.2 "><p><a href="js-offscreencanvasrenderingcontext2d.md">CanvasRenderingContext2DSettings</a></p>
    </td>
    <td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.5.1.3 "><p>否</p>
    </td>
    <td class="cellrowborder" valign="top" width="56.18%" headers="mcps1.1.5.1.4 "><p>用于在离屏画布上进行绘制矩形、文本<span>、图片等</span>。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   返回值

    <table><thead align="left"><tr><th class="cellrowborder" valign="top" width="30.130000000000003%" id="mcps1.1.3.1.1"><p>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="69.87%" id="mcps1.1.3.1.2"><p>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr><td class="cellrowborder" valign="top" width="30.130000000000003%" headers="mcps1.1.3.1.1 "><p><a href="js-offscreencanvasrenderingcontext2d.md">OffscreenCanvasRenderingContext2D</a></p>
    </td>
    <td class="cellrowborder" valign="top" width="69.87%" headers="mcps1.1.3.1.2 "><p>2D绘制对象，用于在画布组件上绘制矩形、文本<span>、图片等</span>。</p>
    </td>
    </tr>
    </tbody>
    </table>


### toDataURL<a name="section16338154813483"></a>

toDataURL\(type?: string, quality?:number\):

生成一个包含图片展示的URL。

-   参数

    <table><thead align="left"><tr><th class="cellrowborder" valign="top" width="21.04%" id="mcps1.1.5.1.1"><p>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="15.260000000000002%" id="mcps1.1.5.1.2"><p>参数类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="7.5200000000000005%" id="mcps1.1.5.1.3"><p>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="56.18%" id="mcps1.1.5.1.4"><p>描述</p>
    </th>
    </tr>
    </thead>
    <tbody><tr><td class="cellrowborder" valign="top" width="21.04%" headers="mcps1.1.5.1.1 "><p>type</p>
    </td>
    <td class="cellrowborder" valign="top" width="15.260000000000002%" headers="mcps1.1.5.1.2 "><p>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.5.1.3 "><p>否</p>
    </td>
    <td class="cellrowborder" valign="top" width="56.18%" headers="mcps1.1.5.1.4 "><p>可选参数，用于指定图像格式，默认格式为image/png。</p>
    </td>
    </tr>
    <tr><td class="cellrowborder" valign="top" width="21.04%" headers="mcps1.1.5.1.1 "><p>quality</p>
    </td>
    <td class="cellrowborder" valign="top" width="15.260000000000002%" headers="mcps1.1.5.1.2 "><p>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.5.1.3 "><p>否</p>
    </td>
    <td class="cellrowborder" valign="top" width="56.18%" headers="mcps1.1.5.1.4 "><p>在指定图片格式为image/jpeg或image/webp的情况下，可以从0到1的区间内选择图片的质量。如果超出取值范围，将会使用默认值0.92。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   返回值

    <table><thead align="left"><tr><th class="cellrowborder" valign="top" width="19.77%" id="mcps1.1.3.1.1"><p>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="80.23%" id="mcps1.1.3.1.2"><p>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr><td class="cellrowborder" valign="top" width="19.77%" headers="mcps1.1.3.1.1 "><p>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="80.23%" headers="mcps1.1.3.1.2 "><p>图像的URL地址。</p>
    </td>
    </tr>
    </tbody>
    </table>


### transferToImageBitmap<a name="section1255985012014"></a>

transferToImageBitmap\(\): ImageBitmap

在离屏画布最近渲染的图像上创建一个ImageBitmap对象。

-   返回值

    <table><thead align="left"><tr><th class="cellrowborder" valign="top" width="21.36%" id="mcps1.1.3.1.1"><p>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="78.64%" id="mcps1.1.3.1.2"><p>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr><td class="cellrowborder" valign="top" width="21.36%" headers="mcps1.1.3.1.1 "><p><a href="js-components-canvas-imagebitmap.md">ImageBitmap</a></p>
    </td>
    <td class="cellrowborder" valign="top" width="78.64%" headers="mcps1.1.3.1.2 "><p>存储离屏画布上渲染的像素数据。</p>
    </td>
    </tr>
    </tbody>
    </table>


## 示例<a name="section13457717134912"></a>

```
<!-- xxx.hml -->
<div>
  <canvas ref="canvasId" style="width: 200px; height: 150px; background-color: #ffff00;"></canvas>
</div>
```

```
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

