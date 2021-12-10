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

### getContext\(type: '2d', options?:  ContextAttrOptions\)<a name="section18710131144813"></a>

getContext  \(type: '2d', options?:  ContextAttrOptions\): CanvasRendering2dContext

获取canvas绘图上下文。不支持在onInit和onReady中进行调用。

-   参数

    <a name="table3592161817496"></a>
    <table><thead align="left"><tr id="row19592141864916"><th class="cellrowborder" valign="top" width="21.04%" id="mcps1.1.5.1.1"><p id="p229575610288"><a name="p229575610288"></a><a name="p229575610288"></a>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="15.260000000000002%" id="mcps1.1.5.1.2"><p id="p929585682819"><a name="p929585682819"></a><a name="p929585682819"></a>参数类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="7.5200000000000005%" id="mcps1.1.5.1.3"><p id="p1184145643311"><a name="p1184145643311"></a><a name="p1184145643311"></a>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="56.18%" id="mcps1.1.5.1.4"><p id="p1929645618282"><a name="p1929645618282"></a><a name="p1929645618282"></a>描述</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row1559261834915"><td class="cellrowborder" valign="top" width="21.04%" headers="mcps1.1.5.1.1 "><p id="p115927183493"><a name="p115927183493"></a><a name="p115927183493"></a>type</p>
    </td>
    <td class="cellrowborder" valign="top" width="15.260000000000002%" headers="mcps1.1.5.1.2 "><p id="p95921918114914"><a name="p95921918114914"></a><a name="p95921918114914"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.5.1.3 "><p id="p1084205619334"><a name="p1084205619334"></a><a name="p1084205619334"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="56.18%" headers="mcps1.1.5.1.4 "><p id="p94820268342"><a name="p94820268342"></a><a name="p94820268342"></a>可选值为'2d'，返回值为2D绘制对象，该对象提供具体的2D绘制操作。</p>
    </td>
    </tr>
    <tr id="row195921118184916"><td class="cellrowborder" valign="top" width="21.04%" headers="mcps1.1.5.1.1 "><p id="p45928181498"><a name="p45928181498"></a><a name="p45928181498"></a>options<sup id="sup710512322033"><a name="sup710512322033"></a><a name="sup710512322033"></a>6+</sup></p>
    </td>
    <td class="cellrowborder" valign="top" width="15.260000000000002%" headers="mcps1.1.5.1.2 "><p id="p10111319172612"><a name="p10111319172612"></a><a name="p10111319172612"></a><a href="#table87141136171717">ContextAttrOptions</a></p>
    </td>
    <td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.5.1.3 "><p id="p184115663319"><a name="p184115663319"></a><a name="p184115663319"></a>否</p>
    </td>
    <td class="cellrowborder" valign="top" width="56.18%" headers="mcps1.1.5.1.4 "><p id="p6592518124911"><a name="p6592518124911"></a><a name="p6592518124911"></a>具体表现为当前仅支持配置是否开启抗锯齿功能，默认为关闭。</p>
    </td>
    </tr>
    </tbody>
    </table>

    **表 1**  ContextAttrOptions

    <a name="table87141136171717"></a>
    <table><thead align="left"><tr id="row13714163615179"><th class="cellrowborder" valign="top" width="33.33333333333333%" id="mcps1.2.4.1.1"><p id="p1315935981716"><a name="p1315935981716"></a><a name="p1315935981716"></a>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="33.33333333333333%" id="mcps1.2.4.1.2"><p id="p21591759121715"><a name="p21591759121715"></a><a name="p21591759121715"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="33.33333333333333%" id="mcps1.2.4.1.3"><p id="p115945931710"><a name="p115945931710"></a><a name="p115945931710"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row17151636111717"><td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.1 "><p id="p102771695180"><a name="p102771695180"></a><a name="p102771695180"></a>antialias</p>
    </td>
    <td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.2 "><p id="p1227710916188"><a name="p1227710916188"></a><a name="p1227710916188"></a>boolean</p>
    </td>
    <td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.3 "><p id="p5277099182"><a name="p5277099182"></a><a name="p5277099182"></a>是否开启抗锯齿功能，默认为false。</p>
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
    <tbody><tr id="row278317321285"><td class="cellrowborder" valign="top" width="19.77%" headers="mcps1.1.3.1.1 "><p id="p368814141577"><a name="p368814141577"></a><a name="p368814141577"></a><a href="js-components-canvas-canvasrenderingcontext2d.md">CanvasRenderingContext2D</a></p>
    </td>
    <td class="cellrowborder" valign="top" width="80.23%" headers="mcps1.1.3.1.2 "><p id="p1537310444489"><a name="p1537310444489"></a><a name="p1537310444489"></a>用于在画布组件上绘制矩形、文本<span id="ph12120164516264"><a name="ph12120164516264"></a><a name="ph12120164516264"></a>、图片等</span>。</p>
    </td>
    </tr>
    </tbody>
    </table>


### toDataURL<sup>6+</sup><a name="section16338154813483"></a>

toDataURL\(type?: string, quality?: number\): string

生成一个包含图片展示的URL。

-   参数

    <a name="table1972913125017"></a>
    <table><thead align="left"><tr id="row972933145015"><th class="cellrowborder" valign="top" width="21.04%" id="mcps1.1.5.1.1"><p id="p87291315508"><a name="p87291315508"></a><a name="p87291315508"></a>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="15.260000000000002%" id="mcps1.1.5.1.2"><p id="p1072919316505"><a name="p1072919316505"></a><a name="p1072919316505"></a>参数类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="7.5200000000000005%" id="mcps1.1.5.1.3"><p id="p11119820134420"><a name="p11119820134420"></a><a name="p11119820134420"></a>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="56.18%" id="mcps1.1.5.1.4"><p id="p872916310508"><a name="p872916310508"></a><a name="p872916310508"></a>描述</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row167295395016"><td class="cellrowborder" valign="top" width="21.04%" headers="mcps1.1.5.1.1 "><p id="p0729103105015"><a name="p0729103105015"></a><a name="p0729103105015"></a>type</p>
    </td>
    <td class="cellrowborder" valign="top" width="15.260000000000002%" headers="mcps1.1.5.1.2 "><p id="p1872993205018"><a name="p1872993205018"></a><a name="p1872993205018"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.5.1.3 "><p id="p1511910203441"><a name="p1511910203441"></a><a name="p1511910203441"></a>否</p>
    </td>
    <td class="cellrowborder" valign="top" width="56.18%" headers="mcps1.1.5.1.4 "><p id="p209224525110"><a name="p209224525110"></a><a name="p209224525110"></a>可选参数，用于指定图像格式，默认格式为image/png。</p>
    </td>
    </tr>
    <tr id="row77303345020"><td class="cellrowborder" valign="top" width="21.04%" headers="mcps1.1.5.1.1 "><p id="p3304419154314"><a name="p3304419154314"></a><a name="p3304419154314"></a>quality</p>
    </td>
    <td class="cellrowborder" valign="top" width="15.260000000000002%" headers="mcps1.1.5.1.2 "><p id="p591623145012"><a name="p591623145012"></a><a name="p591623145012"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.5.1.3 "><p id="p71196204446"><a name="p71196204446"></a><a name="p71196204446"></a>否</p>
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

