# Overlay<a name="EN-US_TOPIC_0000001154905728"></a>

<a name="table3548mcpsimp"></a>
<table><thead align="left"><tr id="row3556mcpsimp"><th class="cellrowborder" valign="top" width="15.120000000000001%" id="mcps1.1.5.1.1"><p id="p3558mcpsimp"><a name="p3558mcpsimp"></a><a name="p3558mcpsimp"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="35.94%" id="mcps1.1.5.1.2"><p id="p3560mcpsimp"><a name="p3560mcpsimp"></a><a name="p3560mcpsimp"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="25.4%" id="mcps1.1.5.1.3"><p id="p3562mcpsimp"><a name="p3562mcpsimp"></a><a name="p3562mcpsimp"></a>Default Value</p>
</th>
<th class="cellrowborder" valign="top" width="23.54%" id="mcps1.1.5.1.4"><p id="p3566mcpsimp"><a name="p3566mcpsimp"></a><a name="p3566mcpsimp"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row3567mcpsimp"><td class="cellrowborder" valign="top" width="15.120000000000001%" headers="mcps1.1.5.1.1 "><p id="p3569mcpsimp"><a name="p3569mcpsimp"></a><a name="p3569mcpsimp"></a>overlay</p>
</td>
<td class="cellrowborder" valign="top" width="35.94%" headers="mcps1.1.5.1.2 "><p id="p15143143013238"><a name="p15143143013238"></a><a name="p15143143013238"></a>title: string,</p>
<p id="p346205712231"><a name="p346205712231"></a><a name="p346205712231"></a>options: {</p>
<p id="p1022253413236"><a name="p1022253413236"></a><a name="p1022253413236"></a>align?: <a href="ts-appendix-enums.md#section1145418513159">Alignment</a>,</p>
<p id="p750225072319"><a name="p750225072319"></a><a name="p750225072319"></a>offset?: {x: number, y: number}</p>
<p id="p3571mcpsimp"><a name="p3571mcpsimp"></a><a name="p3571mcpsimp"></a>}</p>
</td>
<td class="cellrowborder" valign="top" width="25.4%" headers="mcps1.1.5.1.3 "><p id="p17678157182417"><a name="p17678157182417"></a><a name="p17678157182417"></a>{</p>
<p id="p122176521265"><a name="p122176521265"></a><a name="p122176521265"></a>align: Alignment.Center,</p>
<p id="p1987841519242"><a name="p1987841519242"></a><a name="p1987841519242"></a>offset: {0, 0}</p>
<p id="p3573mcpsimp"><a name="p3573mcpsimp"></a><a name="p3573mcpsimp"></a>}</p>
</td>
<td class="cellrowborder" valign="top" width="23.54%" headers="mcps1.1.5.1.4 "><p id="p3577mcpsimp"><a name="p3577mcpsimp"></a><a name="p3577mcpsimp"></a>Mask added to the component. The mask has the same layout as the component.</p>
</td>
</tr>
</tbody>
</table>

## Example<a name="section4278134412416"></a>

```
@Entry
@Component
struct OverlayExample {
  build() {
    Column() {
      Column() {
        Text('floating layer')
          .fontSize(12).fontColor(0xCCCCCC).maxLines(1)
        Column() {
          Image($r('app.media.img'))
            .width(240).height(240)
            .overlay("Don't walk and play with your phone.", { align: Alignment.Bottom, offset: { x: 0, y: -15 } })
        }.border({ color: Color.Black, width: 2 })
      }.width('100%')
    }.padding({ top: 20 })
  }
}
```

![](figures/overlay.gif)

