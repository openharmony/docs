# 显隐控制<a name="ZH-CN_TOPIC_0000001166728051"></a>

<a name="table3856mcpsimp"></a>
<table><thead align="left"><tr id="row3864mcpsimp"><th class="cellrowborder" valign="top" width="12.088791120887912%" id="mcps1.1.5.1.1"><p id="p3866mcpsimp"><a name="p3866mcpsimp"></a><a name="p3866mcpsimp"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="13.18868113188681%" id="mcps1.1.5.1.2"><p id="p3868mcpsimp"><a name="p3868mcpsimp"></a><a name="p3868mcpsimp"></a>参数类型</p>
</th>
<th class="cellrowborder" valign="top" width="10.988901109889012%" id="mcps1.1.5.1.3"><p id="p3870mcpsimp"><a name="p3870mcpsimp"></a><a name="p3870mcpsimp"></a>默认值</p>
</th>
<th class="cellrowborder" valign="top" width="63.73362663733626%" id="mcps1.1.5.1.4"><p id="p3874mcpsimp"><a name="p3874mcpsimp"></a><a name="p3874mcpsimp"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row3875mcpsimp"><td class="cellrowborder" valign="top" width="12.088791120887912%" headers="mcps1.1.5.1.1 "><p id="p3877mcpsimp"><a name="p3877mcpsimp"></a><a name="p3877mcpsimp"></a>visibility</p>
</td>
<td class="cellrowborder" valign="top" width="13.18868113188681%" headers="mcps1.1.5.1.2 "><p id="p3879mcpsimp"><a name="p3879mcpsimp"></a><a name="p3879mcpsimp"></a><a href="#li1521155325910">Visibility</a></p>
</td>
<td class="cellrowborder" valign="top" width="10.988901109889012%" headers="mcps1.1.5.1.3 "><p id="p3881mcpsimp"><a name="p3881mcpsimp"></a><a name="p3881mcpsimp"></a>Visible</p>
</td>
<td class="cellrowborder" valign="top" width="63.73362663733626%" headers="mcps1.1.5.1.4 "><p id="p3885mcpsimp"><a name="p3885mcpsimp"></a><a name="p3885mcpsimp"></a>控制当前组件显示或隐藏。</p>
</td>
</tr>
</tbody>
</table>

-   <a name="li1521155325910"></a>Visibility枚举说明

    <a name="table3452114216394"></a>
    <table><thead align="left"><tr id="row245219426397"><th class="cellrowborder" valign="top" width="25.2%" id="mcps1.1.3.1.1"><p id="p545244283914"><a name="p545244283914"></a><a name="p545244283914"></a>名称</p>
    </th>
    <th class="cellrowborder" valign="top" width="74.8%" id="mcps1.1.3.1.2"><p id="p2452114203917"><a name="p2452114203917"></a><a name="p2452114203917"></a>描述</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row6452144218390"><td class="cellrowborder" valign="top" width="25.2%" headers="mcps1.1.3.1.1 "><p id="p34529427398"><a name="p34529427398"></a><a name="p34529427398"></a>Hidden</p>
    </td>
    <td class="cellrowborder" valign="top" width="74.8%" headers="mcps1.1.3.1.2 "><p id="p1245211421393"><a name="p1245211421393"></a><a name="p1245211421393"></a>隐藏，但参与布局进行占位。</p>
    </td>
    </tr>
    <tr id="row12452184217398"><td class="cellrowborder" valign="top" width="25.2%" headers="mcps1.1.3.1.1 "><p id="p54523425398"><a name="p54523425398"></a><a name="p54523425398"></a>Visible</p>
    </td>
    <td class="cellrowborder" valign="top" width="74.8%" headers="mcps1.1.3.1.2 "><p id="p745215426391"><a name="p745215426391"></a><a name="p745215426391"></a>显示。</p>
    </td>
    </tr>
    <tr id="row9452134213392"><td class="cellrowborder" valign="top" width="25.2%" headers="mcps1.1.3.1.1 "><p id="p510719111403"><a name="p510719111403"></a><a name="p510719111403"></a>None</p>
    </td>
    <td class="cellrowborder" valign="top" width="74.8%" headers="mcps1.1.3.1.2 "><p id="p154533425394"><a name="p154533425394"></a><a name="p154533425394"></a>隐藏，但不参与布局，不进行占位。</p>
    </td>
    </tr>
    </tbody>
    </table>


## 示例<a name="section4278134412416"></a>

```
@Entry
@Component
struct VisibilityExample {
  build() {
    Column() {
      Column() {
        Text('Visible').fontSize(9).width('90%').fontColor(0xCCCCCC)
        Row().visibility(Visibility.Visible).width('90%').height(80).backgroundColor(0xAFEEEE)

        Text('None').fontSize(9).width('90%').fontColor(0xCCCCCC)
        // 隐藏不参与占位
        Row().visibility(Visibility.None).width('90%').height(80).backgroundColor(0xAFEEEE)

        Text('Hidden').fontSize(9).width('90%').fontColor(0xCCCCCC)
        // 隐藏参与占位
        Row().visibility(Visibility.Hidden).width('90%').height(80).backgroundColor(0xAFEEEE)
      }.width('90%').border({ width: 1 })
    }.width('100%').margin({ top: 5 })
  }
}
```

![](figures/visibility.gif)

