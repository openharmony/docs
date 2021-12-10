# 禁用控制<a name="ZH-CN_TOPIC_0000001119928238"></a>

<a name="table3897mcpsimp"></a>
<table><thead align="left"><tr id="row3904mcpsimp"><th class="cellrowborder" valign="top" width="12.24%" id="mcps1.1.5.1.1"><p id="p3906mcpsimp"><a name="p3906mcpsimp"></a><a name="p3906mcpsimp"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="12.1%" id="mcps1.1.5.1.2"><p id="p3908mcpsimp"><a name="p3908mcpsimp"></a><a name="p3908mcpsimp"></a>参数类型</p>
</th>
<th class="cellrowborder" valign="top" width="10.85%" id="mcps1.1.5.1.3"><p id="p3910mcpsimp"><a name="p3910mcpsimp"></a><a name="p3910mcpsimp"></a>默认值</p>
</th>
<th class="cellrowborder" valign="top" width="64.81%" id="mcps1.1.5.1.4"><p id="p3912mcpsimp"><a name="p3912mcpsimp"></a><a name="p3912mcpsimp"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row3913mcpsimp"><td class="cellrowborder" valign="top" width="12.24%" headers="mcps1.1.5.1.1 "><p id="p3915mcpsimp"><a name="p3915mcpsimp"></a><a name="p3915mcpsimp"></a>enabled</p>
</td>
<td class="cellrowborder" valign="top" width="12.1%" headers="mcps1.1.5.1.2 "><p id="p3917mcpsimp"><a name="p3917mcpsimp"></a><a name="p3917mcpsimp"></a>boolean</p>
</td>
<td class="cellrowborder" valign="top" width="10.85%" headers="mcps1.1.5.1.3 "><p id="p3919mcpsimp"><a name="p3919mcpsimp"></a><a name="p3919mcpsimp"></a>true</p>
</td>
<td class="cellrowborder" valign="top" width="64.81%" headers="mcps1.1.5.1.4 "><p id="p3921mcpsimp"><a name="p3921mcpsimp"></a><a name="p3921mcpsimp"></a>值为true表示组件可用，可响应点击等操作；值为false时，不响应点击等操作。</p>
</td>
</tr>
</tbody>
</table>

## 示例<a name="section4278134412416"></a>

```
@Entry
@Component
struct EnabledExample {
  build() {
    Flex({ justifyContent: FlexAlign.SpaceAround }) {
      // 点击没有反应
      Button('disable').enabled(false).backgroundColor(0x317aff).opacity(0.4)
      Button('enable').backgroundColor(0x317aff)
    }
    .width('100%')
    .padding({ top: 5 })
  }
}
```

![](figures/enabled.gif)

