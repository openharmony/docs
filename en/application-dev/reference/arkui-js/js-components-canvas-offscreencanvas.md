# OffscreenCanvas<a name="EN-US_TOPIC_0000001180744579"></a>

>![](../../public_sys-resources/icon-note.gif) **NOTE:** 
>**OffscreenCanvas**  is supported since API version 7. Updates will be marked with a superscript to indicate their earliest API version.

**OffscreenCanvas**  defines a canvas object that can be rendered off the screen.

## Attributes<a name="section661391987"></a>

<a name="table67211828124016"></a>
<table><thead align="left"><tr id="row108577289405"><th class="cellrowborder" valign="top" width="22.872287228722872%" id="mcps1.1.4.1.1"><p id="p385742814403"><a name="p385742814403"></a><a name="p385742814403"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="29.352935293529352%" id="mcps1.1.4.1.2"><p id="p19857192816408"><a name="p19857192816408"></a><a name="p19857192816408"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="47.774777477747776%" id="mcps1.1.4.1.3"><p id="p18573288402"><a name="p18573288402"></a><a name="p18573288402"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1085792824019"><td class="cellrowborder" valign="top" width="22.872287228722872%" headers="mcps1.1.4.1.1 "><p id="p1485792815404"><a name="p1485792815404"></a><a name="p1485792815404"></a>width</p>
</td>
<td class="cellrowborder" valign="top" width="29.352935293529352%" headers="mcps1.1.4.1.2 "><p id="p11857182804010"><a name="p11857182804010"></a><a name="p11857182804010"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="47.774777477747776%" headers="mcps1.1.4.1.3 "><p id="p1785711281405"><a name="p1785711281405"></a><a name="p1785711281405"></a>Width of the <strong id="b1293921991"><a name="b1293921991"></a><a name="b1293921991"></a>OffscreenCanvas</strong> object.</p>
</td>
</tr>
<tr id="row3857132812406"><td class="cellrowborder" valign="top" width="22.872287228722872%" headers="mcps1.1.4.1.1 "><p id="p88572283404"><a name="p88572283404"></a><a name="p88572283404"></a>height</p>
</td>
<td class="cellrowborder" valign="top" width="29.352935293529352%" headers="mcps1.1.4.1.2 "><p id="p198571828114017"><a name="p198571828114017"></a><a name="p198571828114017"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="47.774777477747776%" headers="mcps1.1.4.1.3 "><p id="p3857192844012"><a name="p3857192844012"></a><a name="p3857192844012"></a>Height of the <strong id="b38911358914"><a name="b38911358914"></a><a name="b38911358914"></a>OffscreenCanvas</strong> object.</p>
</td>
</tr>
</tbody>
</table>

## Methods<a name="section47669296127"></a>

### getContext<a name="section18710131144813"></a>

getContext\(type: string, options?: CanvasRenderingContext2DSettings\): OffscreenCanvasRenderingContext2D

Obtains the  **OffscreenCanvas**  context. This method returns a 2D drawing object.

-   Parameters

    <a name="table3592161817496"></a>
    <table><thead align="left"><tr id="row19592141864916"><th class="cellrowborder" valign="top" width="14.63%" id="mcps1.1.5.1.1"><p id="p229575610288"><a name="p229575610288"></a><a name="p229575610288"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="21.67%" id="mcps1.1.5.1.2"><p id="p929585682819"><a name="p929585682819"></a><a name="p929585682819"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="7.5200000000000005%" id="mcps1.1.5.1.3"><p id="p11119820134420"><a name="p11119820134420"></a><a name="p11119820134420"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="56.18%" id="mcps1.1.5.1.4"><p id="p1929645618282"><a name="p1929645618282"></a><a name="p1929645618282"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row1559261834915"><td class="cellrowborder" valign="top" width="14.63%" headers="mcps1.1.5.1.1 "><p id="p4300201718586"><a name="p4300201718586"></a><a name="p4300201718586"></a>contextId</p>
    </td>
    <td class="cellrowborder" valign="top" width="21.67%" headers="mcps1.1.5.1.2 "><p id="p95921918114914"><a name="p95921918114914"></a><a name="p95921918114914"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.5.1.3 "><p id="p1511910203441"><a name="p1511910203441"></a><a name="p1511910203441"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="56.18%" headers="mcps1.1.5.1.4 "><p id="p5592518104911"><a name="p5592518104911"></a><a name="p5592518104911"></a>The value can only be <strong id="b195311126134218"><a name="b195311126134218"></a><a name="b195311126134218"></a>"2d"</strong>.</p>
    </td>
    </tr>
    <tr id="row195921118184916"><td class="cellrowborder" valign="top" width="14.63%" headers="mcps1.1.5.1.1 "><p id="p45928181498"><a name="p45928181498"></a><a name="p45928181498"></a>options</p>
    </td>
    <td class="cellrowborder" valign="top" width="21.67%" headers="mcps1.1.5.1.2 "><p id="p311133955712"><a name="p311133955712"></a><a name="p311133955712"></a><a href="js-offscreencanvasrenderingcontext2d.md">CanvasRenderingContext2DSettings</a></p>
    </td>
    <td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.5.1.3 "><p id="p71196204446"><a name="p71196204446"></a><a name="p71196204446"></a>No</p>
    </td>
    <td class="cellrowborder" valign="top" width="56.18%" headers="mcps1.1.5.1.4 "><p id="p4507539135910"><a name="p4507539135910"></a><a name="p4507539135910"></a>2D drawing object, which can be used to draw rectangles<span id="ph9658615131215"><a name="ph9658615131215"></a><a name="ph9658615131215"></a>, images,</span> and texts, on the <strong id="b233535603219"><a name="b233535603219"></a><a name="b233535603219"></a>OffscreenCanvas</strong>.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Return values

    <a name="table0782932202818"></a>
    <table><thead align="left"><tr id="row3782832172814"><th class="cellrowborder" valign="top" width="30.130000000000003%" id="mcps1.1.3.1.1"><p id="p1278314323284"><a name="p1278314323284"></a><a name="p1278314323284"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="69.87%" id="mcps1.1.3.1.2"><p id="p17783153216281"><a name="p17783153216281"></a><a name="p17783153216281"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row278317321285"><td class="cellrowborder" valign="top" width="30.130000000000003%" headers="mcps1.1.3.1.1 "><p id="p183226014014"><a name="p183226014014"></a><a name="p183226014014"></a><a href="js-offscreencanvasrenderingcontext2d.md">OffscreenCanvasRenderingContext2D</a></p>
    </td>
    <td class="cellrowborder" valign="top" width="69.87%" headers="mcps1.1.3.1.2 "><p id="p122361757181118"><a name="p122361757181118"></a><a name="p122361757181118"></a>2D drawing object, which can be used to draw rectangles<span id="ph12120164516264"><a name="ph12120164516264"></a><a name="ph12120164516264"></a>, images,</span> and texts, on the <strong id="b14803183913269"><a name="b14803183913269"></a><a name="b14803183913269"></a>OffscreenCanvas</strong>.</p>
    </td>
    </tr>
    </tbody>
    </table>


### toDataURL<a name="section16338154813483"></a>

toDataURL\(type?: string, quality?:number\):

Generates a URL containing image display information.

-   Parameters

    <a name="table1972913125017"></a>
    <table><thead align="left"><tr id="row972933145015"><th class="cellrowborder" valign="top" width="21.04%" id="mcps1.1.5.1.1"><p id="p87291315508"><a name="p87291315508"></a><a name="p87291315508"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="15.260000000000002%" id="mcps1.1.5.1.2"><p id="p1072919316505"><a name="p1072919316505"></a><a name="p1072919316505"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="7.5200000000000005%" id="mcps1.1.5.1.3"><p id="p13152856144418"><a name="p13152856144418"></a><a name="p13152856144418"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="56.18%" id="mcps1.1.5.1.4"><p id="p872916310508"><a name="p872916310508"></a><a name="p872916310508"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row167295395016"><td class="cellrowborder" valign="top" width="21.04%" headers="mcps1.1.5.1.1 "><p id="p0729103105015"><a name="p0729103105015"></a><a name="p0729103105015"></a>type</p>
    </td>
    <td class="cellrowborder" valign="top" width="15.260000000000002%" headers="mcps1.1.5.1.2 "><p id="p1872993205018"><a name="p1872993205018"></a><a name="p1872993205018"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.5.1.3 "><p id="p61520569444"><a name="p61520569444"></a><a name="p61520569444"></a>No</p>
    </td>
    <td class="cellrowborder" valign="top" width="56.18%" headers="mcps1.1.5.1.4 "><p id="p209224525110"><a name="p209224525110"></a><a name="p209224525110"></a>Image format. The default value is <strong id="b17433181813618"><a name="b17433181813618"></a><a name="b17433181813618"></a>image/png</strong>.</p>
    </td>
    </tr>
    <tr id="row77303345020"><td class="cellrowborder" valign="top" width="21.04%" headers="mcps1.1.5.1.1 "><p id="p15925558438"><a name="p15925558438"></a><a name="p15925558438"></a>quality</p>
    </td>
    <td class="cellrowborder" valign="top" width="15.260000000000002%" headers="mcps1.1.5.1.2 "><p id="p591623145012"><a name="p591623145012"></a><a name="p591623145012"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.5.1.3 "><p id="p201520564442"><a name="p201520564442"></a><a name="p201520564442"></a>No</p>
    </td>
    <td class="cellrowborder" valign="top" width="56.18%" headers="mcps1.1.5.1.4 "><p id="p154271418165118"><a name="p154271418165118"></a><a name="p154271418165118"></a>Image quality, which ranges from 0 to 1, when the image format is <strong id="b18400112703618"><a name="b18400112703618"></a><a name="b18400112703618"></a>image/jpeg</strong> or <strong id="b15400112719363"><a name="b15400112719363"></a><a name="b15400112719363"></a>image/webp</strong>. If the set value is beyond the value range, the default value <strong id="b1498145413366"><a name="b1498145413366"></a><a name="b1498145413366"></a>0.92</strong> is used.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Return values

    <a name="table840318881017"></a>
    <table><thead align="left"><tr id="row4403128141019"><th class="cellrowborder" valign="top" width="19.77%" id="mcps1.1.3.1.1"><p id="p1440311815106"><a name="p1440311815106"></a><a name="p1440311815106"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="80.23%" id="mcps1.1.3.1.2"><p id="p18403185106"><a name="p18403185106"></a><a name="p18403185106"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row640378101013"><td class="cellrowborder" valign="top" width="19.77%" headers="mcps1.1.3.1.1 "><p id="p13403983101"><a name="p13403983101"></a><a name="p13403983101"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="80.23%" headers="mcps1.1.3.1.2 "><p id="p1248949111020"><a name="p1248949111020"></a><a name="p1248949111020"></a>Image URL.</p>
    </td>
    </tr>
    </tbody>
    </table>


### transferToImageBitmap<a name="section1255985012014"></a>

transferToImageBitmap\(\): ImageBitmap

Creates an  **ImageBitmap**  object on the most recently rendered image of the  **OffscreenCanvas**.

-   Return values

    <a name="table1355965013016"></a>
    <table><thead align="left"><tr id="row1955916501207"><th class="cellrowborder" valign="top" width="21.36%" id="mcps1.1.3.1.1"><p id="p455913505014"><a name="p455913505014"></a><a name="p455913505014"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="78.64%" id="mcps1.1.3.1.2"><p id="p155591504010"><a name="p155591504010"></a><a name="p155591504010"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row205593500015"><td class="cellrowborder" valign="top" width="21.36%" headers="mcps1.1.3.1.1 "><p id="p2559155012012"><a name="p2559155012012"></a><a name="p2559155012012"></a><a href="js-components-canvas-imagebitmap.md">ImageBitmap</a></p>
    </td>
    <td class="cellrowborder" valign="top" width="78.64%" headers="mcps1.1.3.1.2 "><p id="p455913505011"><a name="p455913505011"></a><a name="p455913505011"></a>Pixel data rendered on the <strong id="b1256513214611"><a name="b1256513214611"></a><a name="b1256513214611"></a>OffscreenCanvas</strong>.</p>
    </td>
    </tr>
    </tbody>
    </table>


## Example<a name="section13457717134912"></a>

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

