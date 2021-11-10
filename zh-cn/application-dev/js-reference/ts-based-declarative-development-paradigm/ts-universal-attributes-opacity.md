# 透明度设置<a name="ZH-CN_TOPIC_0000001158141255"></a>

设置组件的透明度。

<a name="table581mcpsimp"></a>
<table><thead align="left"><tr id="row587mcpsimp"><th class="cellrowborder" valign="top" width="13.969999999999999%" id="mcps1.1.5.1.1"><p id="p589mcpsimp"><a name="p589mcpsimp"></a><a name="p589mcpsimp"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="17.419999999999998%" id="mcps1.1.5.1.2"><p id="p591mcpsimp"><a name="p591mcpsimp"></a><a name="p591mcpsimp"></a>参数类型</p>
</th>
<th class="cellrowborder" valign="top" width="10.35%" id="mcps1.1.5.1.3"><p id="p283717104462"><a name="p283717104462"></a><a name="p283717104462"></a>默认值</p>
</th>
<th class="cellrowborder" valign="top" width="58.26%" id="mcps1.1.5.1.4"><p id="p593mcpsimp"><a name="p593mcpsimp"></a><a name="p593mcpsimp"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row594mcpsimp"><td class="cellrowborder" valign="top" width="13.969999999999999%" headers="mcps1.1.5.1.1 "><p id="p596mcpsimp"><a name="p596mcpsimp"></a><a name="p596mcpsimp"></a>opacity</p>
</td>
<td class="cellrowborder" valign="top" width="17.419999999999998%" headers="mcps1.1.5.1.2 "><p id="p598mcpsimp"><a name="p598mcpsimp"></a><a name="p598mcpsimp"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="10.35%" headers="mcps1.1.5.1.3 "><p id="p8837131054617"><a name="p8837131054617"></a><a name="p8837131054617"></a>1</p>
</td>
<td class="cellrowborder" valign="top" width="58.26%" headers="mcps1.1.5.1.4 "><p id="p600mcpsimp"><a name="p600mcpsimp"></a><a name="p600mcpsimp"></a>元素的不透明度，取值范围为0到1，1表示为不透明，0表示为完全透明。</p>
</td>
</tr>
</tbody>
</table>

## 示例<a name="section4278134412416"></a>

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

