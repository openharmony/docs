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

### getContext<a name="section18710131144813"></a>

getContext\(type: string, options?: CanvasRenderingContext2DSettings\): OffscreenCanvasRenderingContext2D

获取offscreen canvas绘图上下文，返回值为2D绘制对象。

-   参数

    <a name="table3592161817496"></a>
    <table><thead align="left"><tr id="row19592141864916"><th class="cellrowborder" valign="top" width="14.63%" id="mcps1.1.5.1.1"><p id="p229575610288"><a name="p229575610288"></a><a name="p229575610288"></a>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="21.67%" id="mcps1.1.5.1.2"><p id="p929585682819"><a name="p929585682819"></a><a name="p929585682819"></a>参数类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="7.5200000000000005%" id="mcps1.1.5.1.3"><p id="p11119820134420"><a name="p11119820134420"></a><a name="p11119820134420"></a>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="56.18%" id="mcps1.1.5.1.4"><p id="p1929645618282"><a name="p1929645618282"></a><a name="p1929645618282"></a>描述</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row1559261834915"><td class="cellrowborder" valign="top" width="14.63%" headers="mcps1.1.5.1.1 "><p id="p4300201718586"><a name="p4300201718586"></a><a name="p4300201718586"></a>contextId</p>
    </td>
    <td class="cellrowborder" valign="top" width="21.67%" headers="mcps1.1.5.1.2 "><p id="p95921918114914"><a name="p95921918114914"></a><a name="p95921918114914"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.5.1.3 "><p id="p1511910203441"><a name="p1511910203441"></a><a name="p1511910203441"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="56.18%" headers="mcps1.1.5.1.4 "><p id="p5592518104911"><a name="p5592518104911"></a><a name="p5592518104911"></a>仅支持"2d"。</p>
    </td>
    </tr>
    <tr id="row195921118184916"><td class="cellrowborder" valign="top" width="14.63%" headers="mcps1.1.5.1.1 "><p id="p45928181498"><a name="p45928181498"></a><a name="p45928181498"></a>options</p>
    </td>
    <td class="cellrowborder" valign="top" width="21.67%" headers="mcps1.1.5.1.2 "><p id="p311133955712"><a name="p311133955712"></a><a name="p311133955712"></a><a href="js-offscreencanvasrenderingcontext2d.md">CanvasRenderingContext2DSettings</a></p>
    </td>
    <td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.5.1.3 "><p id="p71196204446"><a name="p71196204446"></a><a name="p71196204446"></a>否</p>
    </td>
    <td class="cellrowborder" valign="top" width="56.18%" headers="mcps1.1.5.1.4 "><p id="p4507539135910"><a name="p4507539135910"></a><a name="p4507539135910"></a>用于在离屏画布上进行绘制矩形、文本<span id="ph9658615131215"><a name="ph9658615131215"></a><a name="ph9658615131215"></a>、图片等</span>。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   返回值

    <a name="table0782932202818"></a>
    <table><thead align="left"><tr id="row3782832172814"><th class="cellrowborder" valign="top" width="30.130000000000003%" id="mcps1.1.3.1.1"><p id="p1278314323284"><a name="p1278314323284"></a><a name="p1278314323284"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="69.87%" id="mcps1.1.3.1.2"><p id="p17783153216281"><a name="p17783153216281"></a><a name="p17783153216281"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row278317321285"><td class="cellrowborder" valign="top" width="30.130000000000003%" headers="mcps1.1.3.1.1 "><p id="p183226014014"><a name="p183226014014"></a><a name="p183226014014"></a><a href="js-offscreencanvasrenderingcontext2d.md">OffscreenCanvasRenderingContext2D</a></p>
    </td>
    <td class="cellrowborder" valign="top" width="69.87%" headers="mcps1.1.3.1.2 "><p id="p122361757181118"><a name="p122361757181118"></a><a name="p122361757181118"></a>用于在画布组件上绘制矩形、文本<span id="ph12120164516264"><a name="ph12120164516264"></a><a name="ph12120164516264"></a>、图片等</span>。</p>
    </td>
    </tr>
    </tbody>
    </table>


### toDataURL<a name="section16338154813483"></a>

toDataURL\(type?: string, quality?:number\):

生成一个包含图片展示的URL。

-   参数

    <a name="table1972913125017"></a>
    <table><thead align="left"><tr id="row972933145015"><th class="cellrowborder" valign="top" width="21.04%" id="mcps1.1.5.1.1"><p id="p87291315508"><a name="p87291315508"></a><a name="p87291315508"></a>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="15.260000000000002%" id="mcps1.1.5.1.2"><p id="p1072919316505"><a name="p1072919316505"></a><a name="p1072919316505"></a>参数类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="7.5200000000000005%" id="mcps1.1.5.1.3"><p id="p13152856144418"><a name="p13152856144418"></a><a name="p13152856144418"></a>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="56.18%" id="mcps1.1.5.1.4"><p id="p872916310508"><a name="p872916310508"></a><a name="p872916310508"></a>描述</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row167295395016"><td class="cellrowborder" valign="top" width="21.04%" headers="mcps1.1.5.1.1 "><p id="p0729103105015"><a name="p0729103105015"></a><a name="p0729103105015"></a>type</p>
    </td>
    <td class="cellrowborder" valign="top" width="15.260000000000002%" headers="mcps1.1.5.1.2 "><p id="p1872993205018"><a name="p1872993205018"></a><a name="p1872993205018"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.5.1.3 "><p id="p61520569444"><a name="p61520569444"></a><a name="p61520569444"></a>否</p>
    </td>
    <td class="cellrowborder" valign="top" width="56.18%" headers="mcps1.1.5.1.4 "><p id="p209224525110"><a name="p209224525110"></a><a name="p209224525110"></a>可选参数，用于指定图像格式，默认格式为image/png。</p>
    </td>
    </tr>
    <tr id="row77303345020"><td class="cellrowborder" valign="top" width="21.04%" headers="mcps1.1.5.1.1 "><p id="p15925558438"><a name="p15925558438"></a><a name="p15925558438"></a>quality</p>
    </td>
    <td class="cellrowborder" valign="top" width="15.260000000000002%" headers="mcps1.1.5.1.2 "><p id="p591623145012"><a name="p591623145012"></a><a name="p591623145012"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.5.1.3 "><p id="p201520564442"><a name="p201520564442"></a><a name="p201520564442"></a>否</p>
    </td>
    <td class="cellrowborder" valign="top" width="56.18%" headers="mcps1.1.5.1.4 "><p id="p154271418165118"><a name="p154271418165118"></a><a name="p154271418165118"></a>在指定图片格式为image/jpeg或image/webp的情况下，可以从0到1的区间内选择图片的质量。如果超出取值范围，将会使用默认值0.92。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   返回值

    <a name="table840318881017"></a>
    <table><thead align="left"><tr id="row4403128141019"><th class="cellrowborder" valign="top" width="19.77%" id="mcps1.1.3.1.1"><p id="p1440311815106"><a name="p1440311815106"></a><a name="p1440311815106"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="80.23%" id="mcps1.1.3.1.2"><p id="p18403185106"><a name="p18403185106"></a><a name="p18403185106"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row640378101013"><td class="cellrowborder" valign="top" width="19.77%" headers="mcps1.1.3.1.1 "><p id="p13403983101"><a name="p13403983101"></a><a name="p13403983101"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="80.23%" headers="mcps1.1.3.1.2 "><p id="p1248949111020"><a name="p1248949111020"></a><a name="p1248949111020"></a>图像的URL地址。</p>
    </td>
    </tr>
    </tbody>
    </table>


### transferToImageBitmap<a name="section1255985012014"></a>

transferToImageBitmap\(\): ImageBitmap

在离屏画布最近渲染的图像上创建一个ImageBitmap对象。

-   返回值

    <a name="table1355965013016"></a>
    <table><thead align="left"><tr id="row1955916501207"><th class="cellrowborder" valign="top" width="21.36%" id="mcps1.1.3.1.1"><p id="p455913505014"><a name="p455913505014"></a><a name="p455913505014"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="78.64%" id="mcps1.1.3.1.2"><p id="p155591504010"><a name="p155591504010"></a><a name="p155591504010"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row205593500015"><td class="cellrowborder" valign="top" width="21.36%" headers="mcps1.1.3.1.1 "><p id="p2559155012012"><a name="p2559155012012"></a><a name="p2559155012012"></a><a href="js-components-canvas-imagebitmap.md">ImageBitmap</a></p>
    </td>
    <td class="cellrowborder" valign="top" width="78.64%" headers="mcps1.1.3.1.2 "><p id="p455913505011"><a name="p455913505011"></a><a name="p455913505011"></a>存储离屏画布上渲染的像素数据。</p>
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

