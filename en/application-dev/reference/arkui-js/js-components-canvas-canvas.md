# canvas<a name="EN-US_TOPIC_0000001127284886"></a>

The  **<canvas\>**  component is used for customizing drawings.

## Permission List<a name="section11257113618419"></a>

None

## Child Component<a name="section9288143101012"></a>

Not supported

## Attribute<a name="section2907183951110"></a>

Attributes in  [Universal Attributes](js-components-common-attributes.md)  are supported.

## Style<a name="section5775351116"></a>

Styles in  [Universal Styles](js-components-common-styles.md)  are supported.

## Event<a name="section1729055142211"></a>

Events in  [Universal Events](js-components-common-events.md)  are supported.

## Method<a name="section47669296127"></a>

In addition to the methods in  [Universal Methods](js-components-common-methods.md), the following events are supported.

<a name="td0f869ce272e4d90b1c7df558ad7635e"></a>
<table><thead align="left"><tr id="rf11e90428c78465b9e3a0c3ec2222a3c"><th class="cellrowborder" valign="top" width="10.81%" id="mcps1.1.4.1.1"><p id="a11b4cb4edcf14b5584841b089cbea895"><a name="a11b4cb4edcf14b5584841b089cbea895"></a><a name="a11b4cb4edcf14b5584841b089cbea895"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="26.19%" id="mcps1.1.4.1.2"><p id="ac56fe081db8a4ddca537c39d9abfcd33"><a name="ac56fe081db8a4ddca537c39d9abfcd33"></a><a name="ac56fe081db8a4ddca537c39d9abfcd33"></a>Parameter</p>
</th>
<th class="cellrowborder" valign="top" width="63%" id="mcps1.1.4.1.3"><p id="a05cdd2c741a54fe3a44575a5b2384be3"><a name="a05cdd2c741a54fe3a44575a5b2384be3"></a><a name="a05cdd2c741a54fe3a44575a5b2384be3"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="r960677f8f5e64d7f9b33b8a0ae0c824f"><td class="cellrowborder" valign="top" width="10.81%" headers="mcps1.1.4.1.1 "><p id="p931916913120"><a name="p931916913120"></a><a name="p931916913120"></a>getContext</p>
</td>
<td class="cellrowborder" valign="top" width="26.19%" headers="mcps1.1.4.1.2 "><p id="p685785963319"><a name="p685785963319"></a><a name="p685785963319"></a>getContext  ( type: '2d', attributes<sup id="sup1114274719338"><a name="sup1114274719338"></a><a name="sup1114274719338"></a>6+</sup>:  { antialias: boolean } ) =&gt; CanvasRendering2dContext</p>
</td>
<td class="cellrowborder" valign="top" width="63%" headers="mcps1.1.4.1.3 "><p id="p176180219405"><a name="p176180219405"></a><a name="p176180219405"></a>Obtains the canvas drawing context. The invoking methods are as follows<sup id="sup520217171365"><a name="sup520217171365"></a><a name="sup520217171365"></a>6+</sup>:</p>
<p id="p1161802114405"><a name="p1161802114405"></a><a name="p1161802114405"></a>var ctx = canvas.getContext(contextType);</p>
<p id="p1161882115404"><a name="p1161882115404"></a><a name="p1161882115404"></a>var ctx = canvas.getContext(contextType, contextAttributes);</p>
<p id="p1361802194016"><a name="p1361802194016"></a><a name="p1361802194016"></a><strong id="b10777175914513"><a name="b10777175914513"></a><a name="b10777175914513"></a>contextType</strong> is mandatory and can be set to <strong id="b53315313620"><a name="b53315313620"></a><a name="b53315313620"></a>2d</strong>. <strong id="b1997310522618"><a name="b1997310522618"></a><a name="b1997310522618"></a>contextAttributes</strong> is optional and can be set only to enable or disable the anti-aliasing function. By default, the anti-aliasing function is disabled.</p>
<p id="p15975612161011"><a name="p15975612161011"></a><a name="p15975612161011"></a>The <strong id="b787712185710"><a name="b787712185710"></a><a name="b787712185710"></a>contextType</strong> objects are as follows:</p>
<p id="p1260014407342"><a name="p1260014407342"></a><a name="p1260014407342"></a><strong id="b176712541776"><a name="b176712541776"></a><a name="b176712541776"></a>2d</strong>: The return value is a 2D drawing object that provides specific 2D drawing operations. For details, see section <a href="js-components-canvas-canvasrenderingcontext2d.md">CanvasRenderingContext2D</a>.</p>
<p id="p14183154363412"><a name="p14183154363412"></a><a name="p14183154363412"></a>This API cannot be called in <strong id="b27896541168"><a name="b27896541168"></a><a name="b27896541168"></a>onInit</strong> or <strong id="b28715571664"><a name="b28715571664"></a><a name="b28715571664"></a>onReady</strong>.</p>
</td>
</tr>
<tr id="row13364759185512"><td class="cellrowborder" valign="top" width="10.81%" headers="mcps1.1.4.1.1 "><p id="p5364145915552"><a name="p5364145915552"></a><a name="p5364145915552"></a>toDataURL<sup id="sup822112587185"><a name="sup822112587185"></a><a name="sup822112587185"></a>6+</sup></p>
</td>
<td class="cellrowborder" valign="top" width="26.19%" headers="mcps1.1.4.1.2 "><p id="p12364115935515"><a name="p12364115935515"></a><a name="p12364115935515"></a>string type, number encoderOptions</p>
</td>
<td class="cellrowborder" valign="top" width="63%" headers="mcps1.1.4.1.3 "><p id="p1336455955512"><a name="p1336455955512"></a><a name="p1336455955512"></a>Generate a URL containing the image display.</p>
<a name="ul155726311612"></a><a name="ul155726311612"></a><ul id="ul155726311612"><li>type: specifies the image format. This parameter is optional. The default format is image/png.</li><li>encoderOptions: When the image format is set to image/jpeg or image/webp, the image quality can be selected from 0 to 1. If the value of this parameter is beyond the value range, the default value 0.92 is used.</li></ul>
</td>
</tr>
</tbody>
</table>

## Example<a name="section42931433142318"></a>

```
<!-- xxx.hml -->
<div>
  <canvas ref="canvas1" style="width: 200px; height: 150px; background-color: #ffff00;"></canvas>
  <input type="button" style="width: 180px; height: 60px;" value="fillStyle" onclick="handleClick" />
</div>
```

```
// xxx.js
export default {
  handleClick() {
    const el = this.$refs.canvas1;
    var dataURL = el.toDataURL();
    console.log(dataURL);
    // "data:image/png;base64,xxxxxxxx..."
  }
}
```

