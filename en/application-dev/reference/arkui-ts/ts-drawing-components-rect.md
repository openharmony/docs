# Rect<a name="EN-US_TOPIC_0000001192755114"></a>

>![](../../public_sys-resources/icon-note.gif) **NOTE:** 
>This component is supported since API version 7. Updates will be marked with a superscript to indicate their earliest API version.

The  **<Rect\>**  component is used to draw a rectangle.

## Required Permissions<a name="section53281531154915"></a>

None

## Child Components<a name="section172855459342"></a>

None

## APIs<a name="section6391804354"></a>

Rect\(value:\{options?: \{width: Length,height: Length,radius?: Length | Array<Length\>\} | \{width: Length,height: Length,radiusWidth?: Length,radiusHeight?: Length\}\}\)

-   Parameters

    <a name="table193606194544"></a>
    <table><thead align="left"><tr id="row536071910541"><th class="cellrowborder" valign="top" width="15.47%" id="mcps1.1.6.1.1"><p id="p436112199544"><a name="p436112199544"></a><a name="p436112199544"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="17.22%" id="mcps1.1.6.1.2"><p id="p19361319115410"><a name="p19361319115410"></a><a name="p19361319115410"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="12.49%" id="mcps1.1.6.1.3"><p id="p9361201975417"><a name="p9361201975417"></a><a name="p9361201975417"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="18.6%" id="mcps1.1.6.1.4"><p id="p43611199542"><a name="p43611199542"></a><a name="p43611199542"></a>Default Value</p>
    </th>
    <th class="cellrowborder" valign="top" width="36.22%" id="mcps1.1.6.1.5"><p id="p1136141975419"><a name="p1136141975419"></a><a name="p1136141975419"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row10361101915545"><td class="cellrowborder" valign="top" width="15.47%" headers="mcps1.1.6.1.1 "><p id="p1361119155417"><a name="p1361119155417"></a><a name="p1361119155417"></a>options</p>
    </td>
    <td class="cellrowborder" valign="top" width="17.22%" headers="mcps1.1.6.1.2 "><p id="p8361181913548"><a name="p8361181913548"></a><a name="p8361181913548"></a>Object</p>
    </td>
    <td class="cellrowborder" valign="top" width="12.49%" headers="mcps1.1.6.1.3 "><p id="p153611119195411"><a name="p153611119195411"></a><a name="p153611119195411"></a>No</p>
    </td>
    <td class="cellrowborder" valign="top" width="18.6%" headers="mcps1.1.6.1.4 "><p id="p1436114193546"><a name="p1436114193546"></a><a name="p1436114193546"></a>-</p>
    </td>
    <td class="cellrowborder" valign="top" width="36.22%" headers="mcps1.1.6.1.5 "><p id="p328155017218"><a name="p328155017218"></a><a name="p328155017218"></a>For details, see the <a href="#li1258118431037">options parameters</a>.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   <a name="li1258118431037"></a>options parameters

    <a name="table15611143934"></a>
    <table><thead align="left"><tr id="row260916434313"><th class="cellrowborder" valign="top" width="16.11%" id="mcps1.1.6.1.1"><p id="p16609194315313"><a name="p16609194315313"></a><a name="p16609194315313"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="19.36%" id="mcps1.1.6.1.2"><p id="p860916431334"><a name="p860916431334"></a><a name="p860916431334"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="9.15%" id="mcps1.1.6.1.3"><p id="p1860954313315"><a name="p1860954313315"></a><a name="p1860954313315"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="13.170000000000002%" id="mcps1.1.6.1.4"><p id="p560974313312"><a name="p560974313312"></a><a name="p560974313312"></a>Default Value</p>
    </th>
    <th class="cellrowborder" valign="top" width="42.21%" id="mcps1.1.6.1.5"><p id="p13609643633"><a name="p13609643633"></a><a name="p13609643633"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row560915431434"><td class="cellrowborder" valign="top" width="16.11%" headers="mcps1.1.6.1.1 "><p id="p116094431838"><a name="p116094431838"></a><a name="p116094431838"></a>width</p>
    </td>
    <td class="cellrowborder" valign="top" width="19.36%" headers="mcps1.1.6.1.2 "><p id="p460911431137"><a name="p460911431137"></a><a name="p460911431137"></a>Length</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.15%" headers="mcps1.1.6.1.3 "><p id="p96091143731"><a name="p96091143731"></a><a name="p96091143731"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="13.170000000000002%" headers="mcps1.1.6.1.4 "><p id="p196092043732"><a name="p196092043732"></a><a name="p196092043732"></a>-</p>
    </td>
    <td class="cellrowborder" valign="top" width="42.21%" headers="mcps1.1.6.1.5 "><p id="p106091431532"><a name="p106091431532"></a><a name="p106091431532"></a>Width.</p>
    </td>
    </tr>
    <tr id="row5610443631"><td class="cellrowborder" valign="top" width="16.11%" headers="mcps1.1.6.1.1 "><p id="p11610443534"><a name="p11610443534"></a><a name="p11610443534"></a>height</p>
    </td>
    <td class="cellrowborder" valign="top" width="19.36%" headers="mcps1.1.6.1.2 "><p id="p1661014431231"><a name="p1661014431231"></a><a name="p1661014431231"></a>Length</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.15%" headers="mcps1.1.6.1.3 "><p id="p661094310316"><a name="p661094310316"></a><a name="p661094310316"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="13.170000000000002%" headers="mcps1.1.6.1.4 "><p id="p19610124320316"><a name="p19610124320316"></a><a name="p19610124320316"></a>-</p>
    </td>
    <td class="cellrowborder" valign="top" width="42.21%" headers="mcps1.1.6.1.5 "><p id="p1761013430316"><a name="p1761013430316"></a><a name="p1761013430316"></a>Height.</p>
    </td>
    </tr>
    <tr id="row176101943938"><td class="cellrowborder" valign="top" width="16.11%" headers="mcps1.1.6.1.1 "><p id="p176101843939"><a name="p176101843939"></a><a name="p176101843939"></a>radius</p>
    </td>
    <td class="cellrowborder" valign="top" width="19.36%" headers="mcps1.1.6.1.2 "><p id="p1561084310318"><a name="p1561084310318"></a><a name="p1561084310318"></a>Length | Array&lt;Length&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.15%" headers="mcps1.1.6.1.3 "><p id="p86105431833"><a name="p86105431833"></a><a name="p86105431833"></a>No</p>
    </td>
    <td class="cellrowborder" valign="top" width="13.170000000000002%" headers="mcps1.1.6.1.4 "><p id="p1061012431935"><a name="p1061012431935"></a><a name="p1061012431935"></a>0</p>
    </td>
    <td class="cellrowborder" valign="top" width="42.21%" headers="mcps1.1.6.1.5 "><p id="p261044311313"><a name="p261044311313"></a><a name="p261044311313"></a>Radius of a rounded corner. You can set the radius of four rounded corners.</p>
    </td>
    </tr>
    <tr id="row1161017431139"><td class="cellrowborder" valign="top" width="16.11%" headers="mcps1.1.6.1.1 "><p id="p26108435317"><a name="p26108435317"></a><a name="p26108435317"></a>radiusWidth</p>
    </td>
    <td class="cellrowborder" valign="top" width="19.36%" headers="mcps1.1.6.1.2 "><p id="p06102430310"><a name="p06102430310"></a><a name="p06102430310"></a>Length</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.15%" headers="mcps1.1.6.1.3 "><p id="p196106437315"><a name="p196106437315"></a><a name="p196106437315"></a>No</p>
    </td>
    <td class="cellrowborder" valign="top" width="13.170000000000002%" headers="mcps1.1.6.1.4 "><p id="p1561020431336"><a name="p1561020431336"></a><a name="p1561020431336"></a>0</p>
    </td>
    <td class="cellrowborder" valign="top" width="42.21%" headers="mcps1.1.6.1.5 "><p id="p15610134313316"><a name="p15610134313316"></a><a name="p15610134313316"></a>Width of the rounded corner.</p>
    </td>
    </tr>
    <tr id="row126113436319"><td class="cellrowborder" valign="top" width="16.11%" headers="mcps1.1.6.1.1 "><p id="p186101143439"><a name="p186101143439"></a><a name="p186101143439"></a>radiusHeight</p>
    </td>
    <td class="cellrowborder" valign="top" width="19.36%" headers="mcps1.1.6.1.2 "><p id="p106101431736"><a name="p106101431736"></a><a name="p106101431736"></a>Length</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.15%" headers="mcps1.1.6.1.3 "><p id="p1761114317313"><a name="p1761114317313"></a><a name="p1761114317313"></a>No</p>
    </td>
    <td class="cellrowborder" valign="top" width="13.170000000000002%" headers="mcps1.1.6.1.4 "><p id="p1861115431133"><a name="p1861115431133"></a><a name="p1861115431133"></a>0</p>
    </td>
    <td class="cellrowborder" valign="top" width="42.21%" headers="mcps1.1.6.1.5 "><p id="p18611194310311"><a name="p18611194310311"></a><a name="p18611194310311"></a>Height of the rounded corner.</p>
    </td>
    </tr>
    </tbody>
    </table>


## Attributes<a name="section208511436173518"></a>

<a name="table1467195373113"></a>
<table><thead align="left"><tr id="row474513536315"><th class="cellrowborder" valign="top" width="20%" id="mcps1.1.6.1.1"><p id="p2745185313112"><a name="p2745185313112"></a><a name="p2745185313112"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="22.009999999999998%" id="mcps1.1.6.1.2"><p id="p4745135303114"><a name="p4745135303114"></a><a name="p4745135303114"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="17.990000000000002%" id="mcps1.1.6.1.3"><p id="p13745553103118"><a name="p13745553103118"></a><a name="p13745553103118"></a>Default Value</p>
</th>
<th class="cellrowborder" valign="top" width="20%" id="mcps1.1.6.1.4"><p id="p147451053173119"><a name="p147451053173119"></a><a name="p147451053173119"></a>Mandatory</p>
</th>
<th class="cellrowborder" valign="top" width="20%" id="mcps1.1.6.1.5"><p id="p19745165314312"><a name="p19745165314312"></a><a name="p19745165314312"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row074515531314"><td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.1 "><p id="p57451853193115"><a name="p57451853193115"></a><a name="p57451853193115"></a>width</p>
</td>
<td class="cellrowborder" valign="top" width="22.009999999999998%" headers="mcps1.1.6.1.2 "><p id="p197451553133113"><a name="p197451553133113"></a><a name="p197451553133113"></a>Length</p>
</td>
<td class="cellrowborder" valign="top" width="17.990000000000002%" headers="mcps1.1.6.1.3 "><p id="p574575393113"><a name="p574575393113"></a><a name="p574575393113"></a>0</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.4 "><p id="p874545343110"><a name="p874545343110"></a><a name="p874545343110"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.5 "><p id="p07451953183116"><a name="p07451953183116"></a><a name="p07451953183116"></a>Width.</p>
</td>
</tr>
<tr id="row874518538313"><td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.1 "><p id="p474535311316"><a name="p474535311316"></a><a name="p474535311316"></a>height</p>
</td>
<td class="cellrowborder" valign="top" width="22.009999999999998%" headers="mcps1.1.6.1.2 "><p id="p2745185310316"><a name="p2745185310316"></a><a name="p2745185310316"></a>Length</p>
</td>
<td class="cellrowborder" valign="top" width="17.990000000000002%" headers="mcps1.1.6.1.3 "><p id="p1974512538318"><a name="p1974512538318"></a><a name="p1974512538318"></a>0</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.4 "><p id="p1674595373113"><a name="p1674595373113"></a><a name="p1674595373113"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.5 "><p id="p10745753183117"><a name="p10745753183117"></a><a name="p10745753183117"></a>Height.</p>
</td>
</tr>
<tr id="row57451453143117"><td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.1 "><p id="p17745115312313"><a name="p17745115312313"></a><a name="p17745115312313"></a>radiusWidth</p>
</td>
<td class="cellrowborder" valign="top" width="22.009999999999998%" headers="mcps1.1.6.1.2 "><p id="p4745165319317"><a name="p4745165319317"></a><a name="p4745165319317"></a>Length</p>
</td>
<td class="cellrowborder" valign="top" width="17.990000000000002%" headers="mcps1.1.6.1.3 "><p id="p14745165312316"><a name="p14745165312316"></a><a name="p14745165312316"></a>0</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.4 "><p id="p874585313119"><a name="p874585313119"></a><a name="p874585313119"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.5 "><p id="p137451353153117"><a name="p137451353153117"></a><a name="p137451353153117"></a>Width of a rounded corner. The width and height are the same when only the width is set.</p>
</td>
</tr>
<tr id="row1274555312314"><td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.1 "><p id="p9745135316315"><a name="p9745135316315"></a><a name="p9745135316315"></a>radiusHeight</p>
</td>
<td class="cellrowborder" valign="top" width="22.009999999999998%" headers="mcps1.1.6.1.2 "><p id="p1874515373114"><a name="p1874515373114"></a><a name="p1874515373114"></a>Length</p>
</td>
<td class="cellrowborder" valign="top" width="17.990000000000002%" headers="mcps1.1.6.1.3 "><p id="p12745125320319"><a name="p12745125320319"></a><a name="p12745125320319"></a>0</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.4 "><p id="p1174675303113"><a name="p1174675303113"></a><a name="p1174675303113"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.5 "><p id="p107461553183116"><a name="p107461553183116"></a><a name="p107461553183116"></a>Height of the rounded corner. The width and height are the same only when the height is set.</p>
</td>
</tr>
<tr id="row127461253193113"><td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.1 "><p id="p174635313119"><a name="p174635313119"></a><a name="p174635313119"></a>radius</p>
</td>
<td class="cellrowborder" valign="top" width="22.009999999999998%" headers="mcps1.1.6.1.2 "><p id="p374675363112"><a name="p374675363112"></a><a name="p374675363112"></a>Length | Array&lt;Length&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="17.990000000000002%" headers="mcps1.1.6.1.3 "><p id="p574645353116"><a name="p574645353116"></a><a name="p574645353116"></a>0</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.4 "><p id="p177461538317"><a name="p177461538317"></a><a name="p177461538317"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.6.1.5 "><p id="p1574685310314"><a name="p1574685310314"></a><a name="p1574685310314"></a>Size of the rounded corner.</p>
</td>
</tr>
</tbody>
</table>

## Example<a name="section4459736105512"></a>

```
@Entry
@Component
struct RectExample {
  build() {
    Column({ space: 5 }) {
      Text('normal').fontSize(9).fontColor(0xCCCCCC).width('90%')
      // Draw a 90% x 50 rectangle.
      Rect({ width: '90%', height: 50 })
      // Draw a 90% x 50 rectangle.
      Rect().width('90%').height(50)

      Text('with rounded corners').fontSize(9).fontColor(0xCCCCCC).width('90%')
      // Draw a 90% x 50 rectangle with the width and height of the rounded corner being 20.
      Rect({ width: '90%', height: 50 }).radiusHeight(20).radiusWidth(20)
      // Draw a 90% x 50 rectangle with the width and height of the rounded corner being 20.
      Rect({ width: '90%', height: 50 }).radius(20)
    }.width('100%').margin({ top: 5 })
  }
}
```

![](figures/rect.png)

