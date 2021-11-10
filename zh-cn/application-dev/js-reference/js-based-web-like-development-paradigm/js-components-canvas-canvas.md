# canvas组件<a name="ZH-CN_TOPIC_0000001127284886"></a>

提供画布组件。用于自定义绘制图形。

## 权限列表<a name="section11257113618419"></a>

无

## 子组件<a name="section9288143101012"></a>

不支持。

## 属性<a name="section2907183951110"></a>

支持[通用属性](js-components-common-attributes.md)。

## 样式<a name="section5775351116"></a>

支持[通用样式](js-components-common-styles.md)。

## 事件<a name="section1729055142211"></a>

支持[通用事件](js-components-common-events.md)。

## 方法<a name="section47669296127"></a>

除支持[通用方法](js-components-common-methods.md)外，还支持如下方法：

<a name="td0f869ce272e4d90b1c7df558ad7635e"></a>
<table><thead align="left"><tr id="rf11e90428c78465b9e3a0c3ec2222a3c"><th class="cellrowborder" valign="top" width="10.81%" id="mcps1.1.4.1.1"><p id="a11b4cb4edcf14b5584841b089cbea895"><a name="a11b4cb4edcf14b5584841b089cbea895"></a><a name="a11b4cb4edcf14b5584841b089cbea895"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="26.19%" id="mcps1.1.4.1.2"><p id="ac56fe081db8a4ddca537c39d9abfcd33"><a name="ac56fe081db8a4ddca537c39d9abfcd33"></a><a name="ac56fe081db8a4ddca537c39d9abfcd33"></a>参数</p>
</th>
<th class="cellrowborder" valign="top" width="63%" id="mcps1.1.4.1.3"><p id="a05cdd2c741a54fe3a44575a5b2384be3"><a name="a05cdd2c741a54fe3a44575a5b2384be3"></a><a name="a05cdd2c741a54fe3a44575a5b2384be3"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="r960677f8f5e64d7f9b33b8a0ae0c824f"><td class="cellrowborder" valign="top" width="10.81%" headers="mcps1.1.4.1.1 "><p id="p931916913120"><a name="p931916913120"></a><a name="p931916913120"></a>getContext</p>
</td>
<td class="cellrowborder" valign="top" width="26.19%" headers="mcps1.1.4.1.2 "><p id="p685785963319"><a name="p685785963319"></a><a name="p685785963319"></a>getContext  ( type: '2d', attributes<sup id="sup1114274719338"><a name="sup1114274719338"></a><a name="sup1114274719338"></a>6+</sup>:  { antialias: boolean } ) =&gt; CanvasRendering2dContext</p>
</td>
<td class="cellrowborder" valign="top" width="63%" headers="mcps1.1.4.1.3 "><p id="p176180219405"><a name="p176180219405"></a><a name="p176180219405"></a>获取canvas绘图上下文。调用方法如下两种<sup id="sup520217171365"><a name="sup520217171365"></a><a name="sup520217171365"></a><span>6+</span></sup>：</p>
<p id="p1161802114405"><a name="p1161802114405"></a><a name="p1161802114405"></a>var ctx = canvas.getContext(contextType);</p>
<p id="p1161882115404"><a name="p1161882115404"></a><a name="p1161882115404"></a>var ctx = canvas.getContext(contextType, contextAttributes);</p>
<p id="p1361802194016"><a name="p1361802194016"></a><a name="p1361802194016"></a>其中contextType为必填项，当前支持"2d"，contextAttributes为可选参数，当前仅支持配置是否开启抗锯齿功能，默认为关闭。</p>
<p id="p15975612161011"><a name="p15975612161011"></a><a name="p15975612161011"></a>contextType对应的上下文对象如下：</p>
<p id="p1260014407342"><a name="p1260014407342"></a><a name="p1260014407342"></a>"2d"：返回值为2D绘制对象，该对象提供具体的2D绘制操作。详见<a href="js-components-canvas-canvasrenderingcontext2d.md">CanvasRenderingContext2D对象</a>章节。</p>
<p id="p14183154363412"><a name="p14183154363412"></a><a name="p14183154363412"></a>不支持在onInit和onReady中进行调用。</p>
</td>
</tr>
<tr id="row13364759185512"><td class="cellrowborder" valign="top" width="10.81%" headers="mcps1.1.4.1.1 "><p id="p5364145915552"><a name="p5364145915552"></a><a name="p5364145915552"></a>toDataURL<sup id="sup822112587185"><a name="sup822112587185"></a><a name="sup822112587185"></a>6+</sup></p>
</td>
<td class="cellrowborder" valign="top" width="26.19%" headers="mcps1.1.4.1.2 "><p id="p12364115935515"><a name="p12364115935515"></a><a name="p12364115935515"></a>string type, number encoderOptions</p>
</td>
<td class="cellrowborder" valign="top" width="63%" headers="mcps1.1.4.1.3 "><p id="p1336455955512"><a name="p1336455955512"></a><a name="p1336455955512"></a>生成一个包含图片展示的URL。</p>
<a name="ul155726311612"></a><a name="ul155726311612"></a><ul id="ul155726311612"><li>type：可选参数，用于指定图像格式，默认格式为image/png。</li><li>encoderOptions：在指定图片格式为image/jpeg或image/webp的情况下，可以从0到1的区间内选择图片的质量。如果超出取值范围，将会使用默认值0.92。</li></ul>
</td>
</tr>
</tbody>
</table>

## 示例<a name="section42931433142318"></a>

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

