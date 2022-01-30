# Gauge<a name="EN-US_TOPIC_0000001237715089"></a>

>![](../../public_sys-resources/icon-note.gif) **NOTE:** 
>This component is supported since API version 8. Updates will be marked with a superscript to indicate their earliest API version.

Data gauge chart widget, which is used to display data in a ring chart.

## Required Permissions<a name="section781125411508"></a>

None

## Child Component<a name="section19640115511114"></a>

N/A

## APIs<a name="section5420929101113"></a>

Gauge\(value:\{value: number, min?: number, max?: number\}\)

-   Parameter

    <a name="table1392916196212"></a>
    <table><thead align="left"><tr id="row19306191218"><th class="cellrowborder" valign="top" width="16.21%" id="mcps1.1.6.1.1"><p id="p199307193217"><a name="p199307193217"></a><a name="p199307193217"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="13.91%" id="mcps1.1.6.1.2"><p id="p119302191128"><a name="p119302191128"></a><a name="p119302191128"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="14.499999999999998%" id="mcps1.1.6.1.3"><p id="p7930141911211"><a name="p7930141911211"></a><a name="p7930141911211"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="13.170000000000002%" id="mcps1.1.6.1.4"><p id="p1393020194219"><a name="p1393020194219"></a><a name="p1393020194219"></a>Default Value</p>
    </th>
    <th class="cellrowborder" valign="top" width="42.21%" id="mcps1.1.6.1.5"><p id="p693061912210"><a name="p693061912210"></a><a name="p693061912210"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row1093021911217"><td class="cellrowborder" valign="top" width="16.21%" headers="mcps1.1.6.1.1 "><p id="p119307198218"><a name="p119307198218"></a><a name="p119307198218"></a>value</p>
    </td>
    <td class="cellrowborder" valign="top" width="13.91%" headers="mcps1.1.6.1.2 "><p id="p129301719828"><a name="p129301719828"></a><a name="p129301719828"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.499999999999998%" headers="mcps1.1.6.1.3 "><p id="p893091913213"><a name="p893091913213"></a><a name="p893091913213"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="13.170000000000002%" headers="mcps1.1.6.1.4 "><p id="p793071910214"><a name="p793071910214"></a><a name="p793071910214"></a>-</p>
    </td>
    <td class="cellrowborder" valign="top" width="42.21%" headers="mcps1.1.6.1.5 "><p id="p693016198212"><a name="p693016198212"></a><a name="p693016198212"></a>Current data value.</p>
    </td>
    </tr>
    <tr id="row199301191726"><td class="cellrowborder" valign="top" width="16.21%" headers="mcps1.1.6.1.1 "><p id="p0930419923"><a name="p0930419923"></a><a name="p0930419923"></a>min</p>
    </td>
    <td class="cellrowborder" valign="top" width="13.91%" headers="mcps1.1.6.1.2 "><p id="p1993071918217"><a name="p1993071918217"></a><a name="p1993071918217"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.499999999999998%" headers="mcps1.1.6.1.3 "><p id="p29309191029"><a name="p29309191029"></a><a name="p29309191029"></a>No</p>
    </td>
    <td class="cellrowborder" valign="top" width="13.170000000000002%" headers="mcps1.1.6.1.4 "><p id="p393019193220"><a name="p393019193220"></a><a name="p393019193220"></a>0</p>
    </td>
    <td class="cellrowborder" valign="top" width="42.21%" headers="mcps1.1.6.1.5 "><p id="p793001918220"><a name="p793001918220"></a><a name="p793001918220"></a>Minimum value of the current data segment.</p>
    </td>
    </tr>
    <tr id="row210122354115"><td class="cellrowborder" valign="top" width="16.21%" headers="mcps1.1.6.1.1 "><p id="p171011023174118"><a name="p171011023174118"></a><a name="p171011023174118"></a>max</p>
    </td>
    <td class="cellrowborder" valign="top" width="13.91%" headers="mcps1.1.6.1.2 "><p id="p510102313410"><a name="p510102313410"></a><a name="p510102313410"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.499999999999998%" headers="mcps1.1.6.1.3 "><p id="p5101192374119"><a name="p5101192374119"></a><a name="p5101192374119"></a>No</p>
    </td>
    <td class="cellrowborder" valign="top" width="13.170000000000002%" headers="mcps1.1.6.1.4 "><p id="p10101132354111"><a name="p10101132354111"></a><a name="p10101132354111"></a>100</p>
    </td>
    <td class="cellrowborder" valign="top" width="42.21%" headers="mcps1.1.6.1.5 "><p id="p1310182384115"><a name="p1310182384115"></a><a name="p1310182384115"></a>Maximum value of the current data segment.</p>
    </td>
    </tr>
    </tbody>
    </table>


## Attributes<a name="section49201029171417"></a>

<a name="table1782119567143"></a>
<table><thead align="left"><tr id="row9821165611146"><th class="cellrowborder" valign="top" width="19.02%" id="mcps1.1.5.1.1"><p id="p1182117568143"><a name="p1182117568143"></a><a name="p1182117568143"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="27.169999999999998%" id="mcps1.1.5.1.2"><p id="p6821356151412"><a name="p6821356151412"></a><a name="p6821356151412"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="12.24%" id="mcps1.1.5.1.3"><p id="p1821105681420"><a name="p1821105681420"></a><a name="p1821105681420"></a>Default Value</p>
</th>
<th class="cellrowborder" valign="top" width="41.57%" id="mcps1.1.5.1.4"><p id="p13821115617148"><a name="p13821115617148"></a><a name="p13821115617148"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1682165614143"><td class="cellrowborder" valign="top" width="19.02%" headers="mcps1.1.5.1.1 "><p id="p7821145601413"><a name="p7821145601413"></a><a name="p7821145601413"></a>value</p>
</td>
<td class="cellrowborder" valign="top" width="27.169999999999998%" headers="mcps1.1.5.1.2 "><p id="p582135612146"><a name="p582135612146"></a><a name="p582135612146"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="12.24%" headers="mcps1.1.5.1.3 "><p id="p1282195691412"><a name="p1282195691412"></a><a name="p1282195691412"></a>0</p>
</td>
<td class="cellrowborder" valign="top" width="41.57%" headers="mcps1.1.5.1.4 "><p id="p1782175610142"><a name="p1782175610142"></a><a name="p1782175610142"></a>Sets the value of the current data chart.</p>
</td>
</tr>
<tr id="row1782112568147"><td class="cellrowborder" valign="top" width="19.02%" headers="mcps1.1.5.1.1 "><p id="p1482145641410"><a name="p1482145641410"></a><a name="p1482145641410"></a>startAngle</p>
</td>
<td class="cellrowborder" valign="top" width="27.169999999999998%" headers="mcps1.1.5.1.2 "><p id="p1382145671418"><a name="p1382145671418"></a><a name="p1382145671418"></a>Angle</p>
</td>
<td class="cellrowborder" valign="top" width="12.24%" headers="mcps1.1.5.1.3 "><p id="p1682275613143"><a name="p1682275613143"></a><a name="p1682275613143"></a>-150</p>
</td>
<td class="cellrowborder" valign="top" width="41.57%" headers="mcps1.1.5.1.4 "><p id="p2822105651412"><a name="p2822105651412"></a><a name="p2822105651412"></a>Set the start angle. Clock 0 indicates 0 degree, and the clockwise direction indicates the positive angle.</p>
</td>
</tr>
<tr id="row19822456161411"><td class="cellrowborder" valign="top" width="19.02%" headers="mcps1.1.5.1.1 "><p id="p198224567149"><a name="p198224567149"></a><a name="p198224567149"></a>endAngle</p>
</td>
<td class="cellrowborder" valign="top" width="27.169999999999998%" headers="mcps1.1.5.1.2 "><p id="p582216569142"><a name="p582216569142"></a><a name="p582216569142"></a>Angle</p>
</td>
<td class="cellrowborder" valign="top" width="12.24%" headers="mcps1.1.5.1.3 "><p id="p58221256171410"><a name="p58221256171410"></a><a name="p58221256171410"></a>150</p>
</td>
<td class="cellrowborder" valign="top" width="41.57%" headers="mcps1.1.5.1.4 "><p id="p58229562149"><a name="p58229562149"></a><a name="p58229562149"></a>Sets the end angle position. The clock 0 point is 0 degree, and the clockwise direction is the positive angle.</p>
</td>
</tr>
<tr id="row58221756151414"><td class="cellrowborder" valign="top" width="19.02%" headers="mcps1.1.5.1.1 "><p id="p88220563141"><a name="p88220563141"></a><a name="p88220563141"></a>colors</p>
</td>
<td class="cellrowborder" valign="top" width="27.169999999999998%" headers="mcps1.1.5.1.2 "><p id="p7822155613145"><a name="p7822155613145"></a><a name="p7822155613145"></a>Color | Array&lt;ColorStop&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="12.24%" headers="mcps1.1.5.1.3 "><p id="p19823135691414"><a name="p19823135691414"></a><a name="p19823135691414"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="41.57%" headers="mcps1.1.5.1.4 "><p id="p8823155611145"><a name="p8823155611145"></a><a name="p8823155611145"></a>Set the color of the chart. You can set the pure color or segmental gradient color.</p>
</td>
</tr>
<tr id="row38231856161419"><td class="cellrowborder" valign="top" width="19.02%" headers="mcps1.1.5.1.1 "><p id="p882313569148"><a name="p882313569148"></a><a name="p882313569148"></a>strokeWidth</p>
</td>
<td class="cellrowborder" valign="top" width="27.169999999999998%" headers="mcps1.1.5.1.2 "><p id="p58236564147"><a name="p58236564147"></a><a name="p58236564147"></a>Length</p>
</td>
<td class="cellrowborder" valign="top" width="12.24%" headers="mcps1.1.5.1.3 "><p id="p1782315601412"><a name="p1782315601412"></a><a name="p1782315601412"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="41.57%" headers="mcps1.1.5.1.4 "><p id="p4823125671411"><a name="p4823125671411"></a><a name="p4823125671411"></a>Sets the ring thickness of a ring chart.</p>
</td>
</tr>
</tbody>
</table>

## Example<a name="section1951681592110"></a>

```
@Entry
@Component
struct GaugeExample {
  build() {
    Column() {
      Gauge({ value: 50, min: 0, max: 100 })
        .startAngle(210).endAngle(150)
        .colors([[0x317AF7, 1], [0x5BA854, 1], [0xE08C3A, 1], [0x9C554B, 1], [0xD94838, 1]])
        .strokeWidth(20)
        .width(200).height(200)
    }.width('100%').margin({ top: 5 })
  }
}
```

![](figures/gauge.png)

