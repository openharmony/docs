# Gradient Color<a name="EN-US_TOPIC_0000001150694530"></a>

<a name="table1265031910316"></a>
<table><thead align="left"><tr id="row9650111916319"><th class="cellrowborder" valign="top" width="17.86%" id="mcps1.1.5.1.1"><p id="p18651919153114"><a name="p18651919153114"></a><a name="p18651919153114"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="35.92%" id="mcps1.1.5.1.2"><p id="p965116197315"><a name="p965116197315"></a><a name="p965116197315"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="9.4%" id="mcps1.1.5.1.3"><p id="p4651181953113"><a name="p4651181953113"></a><a name="p4651181953113"></a>Default Value</p>
</th>
<th class="cellrowborder" valign="top" width="36.82%" id="mcps1.1.5.1.4"><p id="p6651191918319"><a name="p6651191918319"></a><a name="p6651191918319"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1165131943114"><td class="cellrowborder" valign="top" width="17.86%" headers="mcps1.1.5.1.1 "><p id="p122152715327"><a name="p122152715327"></a><a name="p122152715327"></a>linearGradient</p>
</td>
<td class="cellrowborder" valign="top" width="35.92%" headers="mcps1.1.5.1.2 "><p id="p94621515915"><a name="p94621515915"></a><a name="p94621515915"></a>{</p>
<p id="p696011914596"><a name="p696011914596"></a><a name="p696011914596"></a>angle?: <a href="ts-types.md#section1530915545289">Angle</a>,</p>
<p id="p116922025185912"><a name="p116922025185912"></a><a name="p116922025185912"></a>direction?:<a href="#li1798245810543">GradientDirection</a>,</p>
<p id="p38974273590"><a name="p38974273590"></a><a name="p38974273590"></a>colors: Array&lt;<a href="ts-types.md#section5633640161413">ColorStop</a>&gt;</p>
<p id="p82133214396"><a name="p82133214396"></a><a name="p82133214396"></a>repeating?: boolean</p>
<p id="p822914920401"><a name="p822914920401"></a><a name="p822914920401"></a>}</p>
</td>
<td class="cellrowborder" valign="top" width="9.4%" headers="mcps1.1.5.1.3 "><p id="p1885914345342"><a name="p1885914345342"></a><a name="p1885914345342"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="36.82%" headers="mcps1.1.5.1.4 "><p id="p1821562018213"><a name="p1821562018213"></a><a name="p1821562018213"></a>Linear gradient.</p>
<p id="p1622132703211"><a name="p1622132703211"></a><a name="p1622132703211"></a><strong id="b22111113277"><a name="b22111113277"></a><a name="b22111113277"></a>angle</strong>: angle of the linear gradient.</p>
<p id="p156811542172917"><a name="p156811542172917"></a><a name="p156811542172917"></a><strong id="b142838318273"><a name="b142838318273"></a><a name="b142838318273"></a>direction</strong>: direction of the linear gradient.</p>
<p id="p35832582286"><a name="p35832582286"></a><a name="p35832582286"></a><strong id="b109818162718"><a name="b109818162718"></a><a name="b109818162718"></a>colors</strong>: description of the gradient colors.</p>
<p id="p19829150123911"><a name="p19829150123911"></a><a name="p19829150123911"></a><strong id="b9721134984113"><a name="b9721134984113"></a><a name="b9721134984113"></a>repeating</strong>: whether the colors are repeated.</p>
</td>
</tr>
<tr id="row472mcpsimp"><td class="cellrowborder" valign="top" width="17.86%" headers="mcps1.1.5.1.1 "><p id="p19221162773210"><a name="p19221162773210"></a><a name="p19221162773210"></a>sweepGradient</p>
</td>
<td class="cellrowborder" valign="top" width="35.92%" headers="mcps1.1.5.1.2 "><p id="p1339211315593"><a name="p1339211315593"></a><a name="p1339211315593"></a>{</p>
<p id="p1973712343599"><a name="p1973712343599"></a><a name="p1973712343599"></a>center: Point,</p>
<p id="p6761136175910"><a name="p6761136175910"></a><a name="p6761136175910"></a>start?: angle,</p>
<p id="p16717740175912"><a name="p16717740175912"></a><a name="p16717740175912"></a>end?: angle,</p>
<p id="p11563114615596"><a name="p11563114615596"></a><a name="p11563114615596"></a>colors: Array&lt;<a href="ts-types.md#section5633640161413">ColorStop</a>&gt;</p>
<p id="p1246417165412"><a name="p1246417165412"></a><a name="p1246417165412"></a>repeating?: boolean</p>
<p id="p2843117104311"><a name="p2843117104311"></a><a name="p2843117104311"></a>}</p>
</td>
<td class="cellrowborder" valign="top" width="9.4%" headers="mcps1.1.5.1.3 "><p id="p885717342341"><a name="p885717342341"></a><a name="p885717342341"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="36.82%" headers="mcps1.1.5.1.4 "><p id="p2022574119118"><a name="p2022574119118"></a><a name="p2022574119118"></a>Angle gradient.</p>
<p id="p11186446217"><a name="p11186446217"></a><a name="p11186446217"></a><strong id="b9341174142811"><a name="b9341174142811"></a><a name="b9341174142811"></a>center</strong>: center point of the angle gradient.</p>
<p id="p158901054911"><a name="p158901054911"></a><a name="p158901054911"></a><strong id="b1548712140282"><a name="b1548712140282"></a><a name="b1548712140282"></a>start</strong>: start point of the angle gradient.</p>
<p id="p1057017411396"><a name="p1057017411396"></a><a name="p1057017411396"></a><strong id="b1118721818283"><a name="b1118721818283"></a><a name="b1118721818283"></a>end</strong>: end point of the angle gradient.</p>
<p id="p117514168309"><a name="p117514168309"></a><a name="p117514168309"></a><strong id="b84270335284"><a name="b84270335284"></a><a name="b84270335284"></a>colors</strong>: description of the gradient colors.</p>
<p id="p626262014112"><a name="p626262014112"></a><a name="p626262014112"></a><strong id="b15651184464212"><a name="b15651184464212"></a><a name="b15651184464212"></a>repeating</strong>: whether the colors are repeated.</p>
</td>
</tr>
<tr id="row481mcpsimp"><td class="cellrowborder" valign="top" width="17.86%" headers="mcps1.1.5.1.1 "><p id="p2221027193216"><a name="p2221027193216"></a><a name="p2221027193216"></a>radialGradient</p>
</td>
<td class="cellrowborder" valign="top" width="35.92%" headers="mcps1.1.5.1.2 "><p id="p106469530594"><a name="p106469530594"></a><a name="p106469530594"></a>{</p>
<p id="p167511156125910"><a name="p167511156125910"></a><a name="p167511156125910"></a>center: Point,</p>
<p id="p39331958195916"><a name="p39331958195916"></a><a name="p39331958195916"></a>radius: Length,</p>
<p id="p65713519017"><a name="p65713519017"></a><a name="p65713519017"></a>colors: Array&lt;<a href="ts-types.md#section5633640161413">ColorStop</a>&gt;</p>
<p id="p48831534184115"><a name="p48831534184115"></a><a name="p48831534184115"></a>repeating: boolean</p>
<p id="p99163173317"><a name="p99163173317"></a><a name="p99163173317"></a>}</p>
</td>
<td class="cellrowborder" valign="top" width="9.4%" headers="mcps1.1.5.1.3 "><p id="p13855193418347"><a name="p13855193418347"></a><a name="p13855193418347"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="36.82%" headers="mcps1.1.5.1.4 "><p id="p188052111806"><a name="p188052111806"></a><a name="p188052111806"></a>Radial gradient.</p>
<p id="p2516261008"><a name="p2516261008"></a><a name="p2516261008"></a><strong id="b1746018451282"><a name="b1746018451282"></a><a name="b1746018451282"></a>center</strong>: center point of the radial gradient.</p>
<p id="p59780470391"><a name="p59780470391"></a><a name="p59780470391"></a><strong id="b3545195017285"><a name="b3545195017285"></a><a name="b3545195017285"></a>radius</strong>: radius of the radial gradient.</p>
<p id="p3283173111308"><a name="p3283173111308"></a><a name="p3283173111308"></a><strong id="b2447183042815"><a name="b2447183042815"></a><a name="b2447183042815"></a>colors</strong>: description of the gradient colors.</p>
<p id="p1131915428412"><a name="p1131915428412"></a><a name="p1131915428412"></a><strong id="b15789161094315"><a name="b15789161094315"></a><a name="b15789161094315"></a>repeating</strong>: whether the colors are repeated.</p>
</td>
</tr>
</tbody>
</table>

-   <a name="li1798245810543"></a>GradientDirection enums

    **GradientDirection**  is used to describe the gradient direction.

    <a name="table205151453908"></a>
    <table><thead align="left"><tr id="row1451635313012"><th class="cellrowborder" valign="top" width="41.68%" id="mcps1.1.3.1.1"><p id="p105161053106"><a name="p105161053106"></a><a name="p105161053106"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="58.32000000000001%" id="mcps1.1.3.1.2"><p id="p2516253904"><a name="p2516253904"></a><a name="p2516253904"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row751616531208"><td class="cellrowborder" valign="top" width="41.68%" headers="mcps1.1.3.1.1 "><p id="p451619537013"><a name="p451619537013"></a><a name="p451619537013"></a>Left</p>
    </td>
    <td class="cellrowborder" valign="top" width="58.32000000000001%" headers="mcps1.1.3.1.2 "><p id="p9516165316017"><a name="p9516165316017"></a><a name="p9516165316017"></a>The gradient direction is from right to left.</p>
    </td>
    </tr>
    <tr id="row205161453607"><td class="cellrowborder" valign="top" width="41.68%" headers="mcps1.1.3.1.1 "><p id="p25164531602"><a name="p25164531602"></a><a name="p25164531602"></a>Top</p>
    </td>
    <td class="cellrowborder" valign="top" width="58.32000000000001%" headers="mcps1.1.3.1.2 "><p id="p145171353407"><a name="p145171353407"></a><a name="p145171353407"></a>The gradient direction is from bottom to top.</p>
    </td>
    </tr>
    <tr id="row951712539020"><td class="cellrowborder" valign="top" width="41.68%" headers="mcps1.1.3.1.1 "><p id="p2517753403"><a name="p2517753403"></a><a name="p2517753403"></a>Right</p>
    </td>
    <td class="cellrowborder" valign="top" width="58.32000000000001%" headers="mcps1.1.3.1.2 "><p id="p1451795314015"><a name="p1451795314015"></a><a name="p1451795314015"></a>The gradient direction is from left to right.</p>
    </td>
    </tr>
    <tr id="row55178538020"><td class="cellrowborder" valign="top" width="41.68%" headers="mcps1.1.3.1.1 "><p id="p4517165319018"><a name="p4517165319018"></a><a name="p4517165319018"></a>Bottom</p>
    </td>
    <td class="cellrowborder" valign="top" width="58.32000000000001%" headers="mcps1.1.3.1.2 "><p id="p1351716531803"><a name="p1351716531803"></a><a name="p1351716531803"></a>The gradient direction is from top to bottom.</p>
    </td>
    </tr>
    <tr id="row105177531901"><td class="cellrowborder" valign="top" width="41.68%" headers="mcps1.1.3.1.1 "><p id="p1951714531201"><a name="p1951714531201"></a><a name="p1951714531201"></a>LeftTop</p>
    </td>
    <td class="cellrowborder" valign="top" width="58.32000000000001%" headers="mcps1.1.3.1.2 "><p id="p451711531005"><a name="p451711531005"></a><a name="p451711531005"></a>The gradient direction is upper left.</p>
    </td>
    </tr>
    <tr id="row0518153801"><td class="cellrowborder" valign="top" width="41.68%" headers="mcps1.1.3.1.1 "><p id="p175181953303"><a name="p175181953303"></a><a name="p175181953303"></a>LeftBottom</p>
    </td>
    <td class="cellrowborder" valign="top" width="58.32000000000001%" headers="mcps1.1.3.1.2 "><p id="p25181453605"><a name="p25181453605"></a><a name="p25181453605"></a>The gradient direction is lower left.</p>
    </td>
    </tr>
    <tr id="row133247299114"><td class="cellrowborder" valign="top" width="41.68%" headers="mcps1.1.3.1.1 "><p id="p932512291613"><a name="p932512291613"></a><a name="p932512291613"></a>RightTop</p>
    </td>
    <td class="cellrowborder" valign="top" width="58.32000000000001%" headers="mcps1.1.3.1.2 "><p id="p132513291318"><a name="p132513291318"></a><a name="p132513291318"></a>The gradient direction is upper right.</p>
    </td>
    </tr>
    <tr id="row85839321130"><td class="cellrowborder" valign="top" width="41.68%" headers="mcps1.1.3.1.1 "><p id="p1858333212316"><a name="p1858333212316"></a><a name="p1858333212316"></a>RightBottom</p>
    </td>
    <td class="cellrowborder" valign="top" width="58.32000000000001%" headers="mcps1.1.3.1.2 "><p id="p258313321431"><a name="p258313321431"></a><a name="p258313321431"></a>The gradient direction is lower right.</p>
    </td>
    </tr>
    <tr id="row19740746235"><td class="cellrowborder" valign="top" width="41.68%" headers="mcps1.1.3.1.1 "><p id="p1474014467315"><a name="p1474014467315"></a><a name="p1474014467315"></a>None</p>
    </td>
    <td class="cellrowborder" valign="top" width="58.32000000000001%" headers="mcps1.1.3.1.2 "><p id="p12741646333"><a name="p12741646333"></a><a name="p12741646333"></a>No gradient.</p>
    </td>
    </tr>
    </tbody>
    </table>


## Example<a name="section5724154094916"></a>

```
@Entry
@Component
struct ColorGradientExample {
  build() {
    Column({ space: 5 }) {
      Text('linearGradient').fontSize(12).width('90%').fontColor(0xCCCCCC)
      Row()
        .width('90%')
        .height(50)
        .linearGradient({
          angle: 90,
          direction: GradientDirection.Left,
          colors: [[0xAEE1E1, 0.0], [0xD3E0DC, 0.3], [0xFCD1D1, 1.0]]
        })
      Text('sweepGradient').fontSize(12).width('90%').fontColor(0xCCCCCC)
      Row()
        .width(100)
        .height(100)
        .sweepGradient({
          center: [50, 50],
          start: 0,
          end: 359,
          colors: [[0xAEE1E1, 0.0], [0xD3E0DC, 0.3], [0xFCD1D1, 1.0]]
        })
      Text('radialGradient').fontSize(12).width('90%').fontColor(0xCCCCCC)
      Row()
        .width(100)
        .height(100)
        .radialGradient({
          center: [50, 50],
          radius: 60,
          colors:[[0xAEE1E1, 0.0], [0xD3E0DC, 0.3], [0xFCD1D1, 1.0]]
        })
    }
    .width('100%')
    .padding({ top: 5 })
  }
}
```

![](figures/colorgradient.png)

