# Opacity<a name="EN-US_TOPIC_0000001237475067"></a>

>![](../../public_sys-resources/icon-note.gif) **NOTE:** 
>This attribute is supported since API version 7. Updates will be marked with a superscript to indicate their earliest API version.

The attributes described in this topic are used to set the opacity of a component.

## Required Permissions<a name="section781125411508"></a>

None

## Attributes<a name="section6820191711316"></a>

<a name="table581mcpsimp"></a>
<table><thead align="left"><tr id="row587mcpsimp"><th class="cellrowborder" valign="top" width="13.969999999999999%" id="mcps1.1.5.1.1"><p id="p589mcpsimp"><a name="p589mcpsimp"></a><a name="p589mcpsimp"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="17.419999999999998%" id="mcps1.1.5.1.2"><p id="p591mcpsimp"><a name="p591mcpsimp"></a><a name="p591mcpsimp"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="10.35%" id="mcps1.1.5.1.3"><p id="p283717104462"><a name="p283717104462"></a><a name="p283717104462"></a>Default Value</p>
</th>
<th class="cellrowborder" valign="top" width="58.26%" id="mcps1.1.5.1.4"><p id="p593mcpsimp"><a name="p593mcpsimp"></a><a name="p593mcpsimp"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row594mcpsimp"><td class="cellrowborder" valign="top" width="13.969999999999999%" headers="mcps1.1.5.1.1 "><p id="p596mcpsimp"><a name="p596mcpsimp"></a><a name="p596mcpsimp"></a>opacity</p>
</td>
<td class="cellrowborder" valign="top" width="17.419999999999998%" headers="mcps1.1.5.1.2 "><p id="p598mcpsimp"><a name="p598mcpsimp"></a><a name="p598mcpsimp"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="10.35%" headers="mcps1.1.5.1.3 "><p id="p8837131054617"><a name="p8837131054617"></a><a name="p8837131054617"></a>1</p>
</td>
<td class="cellrowborder" valign="top" width="58.26%" headers="mcps1.1.5.1.4 "><p id="p600mcpsimp"><a name="p600mcpsimp"></a><a name="p600mcpsimp"></a>Opacity of a component. The value ranges from <strong id="b122851614162713"><a name="b122851614162713"></a><a name="b122851614162713"></a>0</strong> to <strong id="b6291121492717"><a name="b6291121492717"></a><a name="b6291121492717"></a>1</strong>. The value <strong id="b10291111432714"><a name="b10291111432714"></a><a name="b10291111432714"></a>1</strong> means opaque, and <strong id="b12291191492719"><a name="b12291191492719"></a><a name="b12291191492719"></a>0</strong> means completely transparent.</p>
</td>
</tr>
</tbody>
</table>

## Example<a name="section4278134412416"></a>

```
@Entry
@Component
struct OpacityExample {
  build() {
    Column({ space: 5 }) {
      Text('opacity(1)').fontSize(9).width('90%').fontColor(0xCCCCCC)
      Text().width('90%').height(50).opacity(1).backgroundColor(0xAFEEEE)
      Text('opacity(0.7)').fontSize(9).width('90%').fontColor(0xCCCCCC)
      Text().width('90%').height(50).opacity(0.7).backgroundColor(0xAFEEEE)
      Text('opacity(0.4)').fontSize(9).width('90%').fontColor(0xCCCCCC)
      Text().width('90%').height(50).opacity(0.4).backgroundColor(0xAFEEEE)
    }
    .width('100%')
    .padding({ top: 5 })
  }
}
```

![](figures/opacity.gif)

