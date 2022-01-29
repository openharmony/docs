# canvas<a name="EN-US_TOPIC_0000001127284886"></a>

The  **<canvas\>**  component is used for customizing drawings.

## Required Permissions<a name="section11257113618419"></a>

None

## Child Components<a name="section9288143101012"></a>

Not supported

## Attributes<a name="section2907183951110"></a>

Attributes in  [Universal Attributes](js-components-common-attributes.md)  are supported.

## Styles<a name="section5775351116"></a>

Styles in  [Universal Styles](js-components-common-styles.md)  are supported.

## Events<a name="section1729055142211"></a>

Events in  [Universal Events](js-components-common-events.md)  are supported.

## Methods<a name="section47669296127"></a>

In addition to the methods in  [Universal Methods](js-components-common-methods.md), the following events are supported.

### getContext<a name="section18710131144813"></a>

getContext\(type: '2d', options?:  ContextAttrOptions\): CanvasRendering2dContext

Obtains the canvas drawing context. This API cannot be called in  **onInit**  or  **onReady**.

-   Parameters

    <a name="table3592161817496"></a>
    <table><thead align="left"><tr id="row19592141864916"><th class="cellrowborder" valign="top" width="21.04%" id="mcps1.1.5.1.1"><p id="p229575610288"><a name="p229575610288"></a><a name="p229575610288"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="15.260000000000002%" id="mcps1.1.5.1.2"><p id="p929585682819"><a name="p929585682819"></a><a name="p929585682819"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="7.5200000000000005%" id="mcps1.1.5.1.3"><p id="p1184145643311"><a name="p1184145643311"></a><a name="p1184145643311"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="56.18%" id="mcps1.1.5.1.4"><p id="p1929645618282"><a name="p1929645618282"></a><a name="p1929645618282"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row1559261834915"><td class="cellrowborder" valign="top" width="21.04%" headers="mcps1.1.5.1.1 "><p id="p115927183493"><a name="p115927183493"></a><a name="p115927183493"></a>type</p>
    </td>
    <td class="cellrowborder" valign="top" width="15.260000000000002%" headers="mcps1.1.5.1.2 "><p id="p95921918114914"><a name="p95921918114914"></a><a name="p95921918114914"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.5.1.3 "><p id="p1084205619334"><a name="p1084205619334"></a><a name="p1084205619334"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="56.18%" headers="mcps1.1.5.1.4 "><p id="p94820268342"><a name="p94820268342"></a><a name="p94820268342"></a>The value is set to <strong id="b11562042143418"><a name="b11562042143418"></a><a name="b11562042143418"></a>'2d'</strong>, indicating that a 2D drawing object is returned. This object can be used to draw rectangles, texts, and images on the canvas component.</p>
    </td>
    </tr>
    <tr id="row195921118184916"><td class="cellrowborder" valign="top" width="21.04%" headers="mcps1.1.5.1.1 "><p id="p45928181498"><a name="p45928181498"></a><a name="p45928181498"></a>options<sup id="sup710512322033"><a name="sup710512322033"></a><a name="sup710512322033"></a>6+</sup></p>
    </td>
    <td class="cellrowborder" valign="top" width="15.260000000000002%" headers="mcps1.1.5.1.2 "><p id="p10111319172612"><a name="p10111319172612"></a><a name="p10111319172612"></a><a href="#table87141136171717">ContextAttrOptions</a></p>
    </td>
    <td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.5.1.3 "><p id="p184115663319"><a name="p184115663319"></a><a name="p184115663319"></a>No</p>
    </td>
    <td class="cellrowborder" valign="top" width="56.18%" headers="mcps1.1.5.1.4 "><p id="p6592518124911"><a name="p6592518124911"></a><a name="p6592518124911"></a>Whether to enable anti-aliasing. By default, anti-aliasing is disabled.</p>
    </td>
    </tr>
    </tbody>
    </table>

    **Table  1**  ContextAttrOptions

    <a name="table87141136171717"></a>
    <table><thead align="left"><tr id="row13714163615179"><th class="cellrowborder" valign="top" width="33.33333333333333%" id="mcps1.2.4.1.1"><p id="p1315935981716"><a name="p1315935981716"></a><a name="p1315935981716"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="33.33333333333333%" id="mcps1.2.4.1.2"><p id="p21591759121715"><a name="p21591759121715"></a><a name="p21591759121715"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="33.33333333333333%" id="mcps1.2.4.1.3"><p id="p115945931710"><a name="p115945931710"></a><a name="p115945931710"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row17151636111717"><td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.1 "><p id="p102771695180"><a name="p102771695180"></a><a name="p102771695180"></a>antialias</p>
    </td>
    <td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.2 "><p id="p1227710916188"><a name="p1227710916188"></a><a name="p1227710916188"></a>boolean</p>
    </td>
    <td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.3 "><p id="p5277099182"><a name="p5277099182"></a><a name="p5277099182"></a>Whether to enable anti-aliasing. The default value is <strong id="b0624355174210"><a name="b0624355174210"></a><a name="b0624355174210"></a>false</strong>.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Return values

    <a name="table0782932202818"></a>
    <table><thead align="left"><tr id="row3782832172814"><th class="cellrowborder" valign="top" width="19.77%" id="mcps1.1.3.1.1"><p id="p1278314323284"><a name="p1278314323284"></a><a name="p1278314323284"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="80.23%" id="mcps1.1.3.1.2"><p id="p17783153216281"><a name="p17783153216281"></a><a name="p17783153216281"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row278317321285"><td class="cellrowborder" valign="top" width="19.77%" headers="mcps1.1.3.1.1 "><p id="p368814141577"><a name="p368814141577"></a><a name="p368814141577"></a><a href="js-components-canvas-canvasrenderingcontext2d.md">CanvasRenderingContext2D</a></p>
    </td>
    <td class="cellrowborder" valign="top" width="80.23%" headers="mcps1.1.3.1.2 "><p id="p1537310444489"><a name="p1537310444489"></a><a name="p1537310444489"></a>2D drawing object, which can be used to draw rectangles<span id="ph12120164516264"><a name="ph12120164516264"></a><a name="ph12120164516264"></a>, images,</span> and texts on the canvas component.</p>
    </td>
    </tr>
    </tbody>
    </table>


### toDataURL<sup>6+</sup><a name="section16338154813483"></a>

toDataURL\(type?: string, quality?: number\): string

Generates a URL containing image display information.

-   Parameters

    <a name="table1972913125017"></a>
    <table><thead align="left"><tr id="row972933145015"><th class="cellrowborder" valign="top" width="21.04%" id="mcps1.1.5.1.1"><p id="p87291315508"><a name="p87291315508"></a><a name="p87291315508"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="15.260000000000002%" id="mcps1.1.5.1.2"><p id="p1072919316505"><a name="p1072919316505"></a><a name="p1072919316505"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="7.5200000000000005%" id="mcps1.1.5.1.3"><p id="p11119820134420"><a name="p11119820134420"></a><a name="p11119820134420"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="56.18%" id="mcps1.1.5.1.4"><p id="p872916310508"><a name="p872916310508"></a><a name="p872916310508"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row167295395016"><td class="cellrowborder" valign="top" width="21.04%" headers="mcps1.1.5.1.1 "><p id="p0729103105015"><a name="p0729103105015"></a><a name="p0729103105015"></a>type</p>
    </td>
    <td class="cellrowborder" valign="top" width="15.260000000000002%" headers="mcps1.1.5.1.2 "><p id="p1872993205018"><a name="p1872993205018"></a><a name="p1872993205018"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.5.1.3 "><p id="p1511910203441"><a name="p1511910203441"></a><a name="p1511910203441"></a>No</p>
    </td>
    <td class="cellrowborder" valign="top" width="56.18%" headers="mcps1.1.5.1.4 "><p id="p209224525110"><a name="p209224525110"></a><a name="p209224525110"></a>Image format. The default value is <strong id="b4381617131817"><a name="b4381617131817"></a><a name="b4381617131817"></a>image/png</strong>.</p>
    </td>
    </tr>
    <tr id="row77303345020"><td class="cellrowborder" valign="top" width="21.04%" headers="mcps1.1.5.1.1 "><p id="p3304419154314"><a name="p3304419154314"></a><a name="p3304419154314"></a>quality</p>
    </td>
    <td class="cellrowborder" valign="top" width="15.260000000000002%" headers="mcps1.1.5.1.2 "><p id="p591623145012"><a name="p591623145012"></a><a name="p591623145012"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.5.1.3 "><p id="p71196204446"><a name="p71196204446"></a><a name="p71196204446"></a>No</p>
    </td>
    <td class="cellrowborder" valign="top" width="56.18%" headers="mcps1.1.5.1.4 "><p id="p154271418165118"><a name="p154271418165118"></a><a name="p154271418165118"></a>Image quality, which ranges from 0 to 1, when the image format is <strong id="b15931192220406"><a name="b15931192220406"></a><a name="b15931192220406"></a>image/jpeg</strong> or <strong id="b693117224406"><a name="b693117224406"></a><a name="b693117224406"></a>image/webp</strong>. If the set value is beyond the value range, the default value <strong id="b167851581370"><a name="b167851581370"></a><a name="b167851581370"></a>0.92</strong> is used.</p>
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

