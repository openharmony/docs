# OffscreenCanvas<a name="EN-US_TOPIC_0000001180744579"></a>

>![](../../public_sys-resources/icon-note.gif) **NOTE:** 
>The APIs of this module are supported since API version 7.

Defines a canvas object that can be rendered off the screen.

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
<td class="cellrowborder" valign="top" width="47.774777477747776%" headers="mcps1.1.4.1.3 "><p id="p1785711281405"><a name="p1785711281405"></a><a name="p1785711281405"></a>Width of the <strong id="b1293921991"><a name="b1293921991"></a><a name="b1293921991"></a>offscreen canvas</strong> object.</p>
</td>
</tr>
<tr id="row3857132812406"><td class="cellrowborder" valign="top" width="22.872287228722872%" headers="mcps1.1.4.1.1 "><p id="p88572283404"><a name="p88572283404"></a><a name="p88572283404"></a>height</p>
</td>
<td class="cellrowborder" valign="top" width="29.352935293529352%" headers="mcps1.1.4.1.2 "><p id="p198571828114017"><a name="p198571828114017"></a><a name="p198571828114017"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="47.774777477747776%" headers="mcps1.1.4.1.3 "><p id="p3857192844012"><a name="p3857192844012"></a><a name="p3857192844012"></a>Height of the <strong id="b38911358914"><a name="b38911358914"></a><a name="b38911358914"></a>offscreen canvas</strong> object.</p>
</td>
</tr>
</tbody>
</table>

## Methods<a name="section47669296127"></a>

<a name="td0f869ce272e4d90b1c7df558ad7635e"></a>
<table><thead align="left"><tr id="rf11e90428c78465b9e3a0c3ec2222a3c"><th class="cellrowborder" valign="top" width="11.68%" id="mcps1.1.4.1.1"><p id="a11b4cb4edcf14b5584841b089cbea895"><a name="a11b4cb4edcf14b5584841b089cbea895"></a><a name="a11b4cb4edcf14b5584841b089cbea895"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="25.319999999999997%" id="mcps1.1.4.1.2"><p id="ac56fe081db8a4ddca537c39d9abfcd33"><a name="ac56fe081db8a4ddca537c39d9abfcd33"></a><a name="ac56fe081db8a4ddca537c39d9abfcd33"></a>Parameter</p>
</th>
<th class="cellrowborder" valign="top" width="63%" id="mcps1.1.4.1.3"><p id="a05cdd2c741a54fe3a44575a5b2384be3"><a name="a05cdd2c741a54fe3a44575a5b2384be3"></a><a name="a05cdd2c741a54fe3a44575a5b2384be3"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="r960677f8f5e64d7f9b33b8a0ae0c824f"><td class="cellrowborder" valign="top" width="11.68%" headers="mcps1.1.4.1.1 "><p id="p931916913120"><a name="p931916913120"></a><a name="p931916913120"></a>getContext</p>
</td>
<td class="cellrowborder" valign="top" width="25.319999999999997%" headers="mcps1.1.4.1.2 "><p id="p123073254554"><a name="p123073254554"></a><a name="p123073254554"></a>contextId: "2d", options?: CanvasRenderingContext2DSettings</p>
</td>
<td class="cellrowborder" valign="top" width="63%" headers="mcps1.1.4.1.3 "><p id="p176180219405"><a name="p176180219405"></a><a name="p176180219405"></a>The invoking methods are as follows:</p>
<p id="p1161802114405"><a name="p1161802114405"></a><a name="p1161802114405"></a>var ctx = canvas.getContext(contextId);</p>
<p id="p1161882115404"><a name="p1161882115404"></a><a name="p1161882115404"></a>var ctx = canvas.getContext(contextId, options);</p>
<p id="p1361802194016"><a name="p1361802194016"></a><a name="p1361802194016"></a>The <strong id="b105631832792"><a name="b105631832792"></a><a name="b105631832792"></a>contextId</strong> parameter is mandatory. Currently, only the value <strong id="b193699361793"><a name="b193699361793"></a><a name="b193699361793"></a>2d</strong> is supported. The <strong id="b684519411497"><a name="b684519411497"></a><a name="b684519411497"></a>options</strong> parameter is optional and is not supported currently.</p>
<p id="p1260014407342"><a name="p1260014407342"></a><a name="p1260014407342"></a>Obtains the context for drawing on an offscreen canvas. The parameter can be set only to <strong id="b23451345291"><a name="b23451345291"></a><a name="b23451345291"></a>2d</strong>. The return value is a 2D drawing object that provides specific 2D drawing operations. For details, see <a href="js-offscreencanvasrenderingcontext2d.md">OffscreenCanvasRenderingContext2D</a>.</p>
</td>
</tr>
<tr id="row13364759185512"><td class="cellrowborder" valign="top" width="11.68%" headers="mcps1.1.4.1.1 "><p id="p93374133418"><a name="p93374133418"></a><a name="p93374133418"></a>toDataURL</p>
</td>
<td class="cellrowborder" valign="top" width="25.319999999999997%" headers="mcps1.1.4.1.2 "><p id="p74131655155410"><a name="p74131655155410"></a><a name="p74131655155410"></a>type?: string, quality?: number</p>
</td>
<td class="cellrowborder" valign="top" width="63%" headers="mcps1.1.4.1.3 "><p id="p1336455955512"><a name="p1336455955512"></a><a name="p1336455955512"></a>Generates a URL containing image display information.</p>
<a name="ul155726311612"></a><a name="ul155726311612"></a><ul id="ul155726311612"><li><strong id="b2361350191014"><a name="b2361350191014"></a><a name="b2361350191014"></a>type</strong>: specifies the image format. This parameter is optional. The default value is <strong id="b163775018106"><a name="b163775018106"></a><a name="b163775018106"></a>image/png</strong>.</li><li><strong id="b1635110532108"><a name="b1635110532108"></a><a name="b1635110532108"></a>quality</strong>: specifies the image quality, which ranges from 0 to 1 when the image format is <strong id="b23523533103"><a name="b23523533103"></a><a name="b23523533103"></a>image/jpeg</strong> or <strong id="b13352125311104"><a name="b13352125311104"></a><a name="b13352125311104"></a>image/webp</strong>. If the value of this parameter exceeds the value range, the default value <strong id="b61228121110"><a name="b61228121110"></a><a name="b61228121110"></a>0.92</strong> will be used.</li></ul>
</td>
</tr>
<tr id="row1350184614429"><td class="cellrowborder" valign="top" width="11.68%" headers="mcps1.1.4.1.1 "><p id="p11501134614422"><a name="p11501134614422"></a><a name="p11501134614422"></a>transferToImageBitmap</p>
</td>
<td class="cellrowborder" valign="top" width="25.319999999999997%" headers="mcps1.1.4.1.2 "><p id="p135011946194215"><a name="p135011946194215"></a><a name="p135011946194215"></a>None</p>
</td>
<td class="cellrowborder" valign="top" width="63%" headers="mcps1.1.4.1.3 "><p id="p20502164624212"><a name="p20502164624212"></a><a name="p20502164624212"></a>Creates an <strong id="b7554192515115"><a name="b7554192515115"></a><a name="b7554192515115"></a>ImageBitmap</strong> object from the most recent image rendered by <strong id="b633493591111"><a name="b633493591111"></a><a name="b633493591111"></a>Offscreen Canvas</strong>.</p>
</td>
</tr>
</tbody>
</table>

## Example<a name="section13457717134912"></a>

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

