# Divider<a name="ZH-CN_TOPIC_0000001111421406"></a>

提供分隔器组件，分隔不同内容块/内容元素。

## 权限列表<a name="section781125411508"></a>

无

## 子组件<a name="section171053164519"></a>

无

## 接口<a name="section314622835214"></a>

Divider\(\)

## 属性<a name="section065712415316"></a>

<a name="table1166mcpsimp"></a>
<table><thead align="left"><tr id="row1173mcpsimp"><th class="cellrowborder" valign="top" width="14.540000000000001%" id="mcps1.1.5.1.1"><p id="p1175mcpsimp"><a name="p1175mcpsimp"></a><a name="p1175mcpsimp"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="14.82%" id="mcps1.1.5.1.2"><p id="p1177mcpsimp"><a name="p1177mcpsimp"></a><a name="p1177mcpsimp"></a>参数类型</p>
</th>
<th class="cellrowborder" valign="top" width="9.64%" id="mcps1.1.5.1.3"><p id="p1179mcpsimp"><a name="p1179mcpsimp"></a><a name="p1179mcpsimp"></a>默认值</p>
</th>
<th class="cellrowborder" valign="top" width="61%" id="mcps1.1.5.1.4"><p id="p1181mcpsimp"><a name="p1181mcpsimp"></a><a name="p1181mcpsimp"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row1182mcpsimp"><td class="cellrowborder" valign="top" width="14.540000000000001%" headers="mcps1.1.5.1.1 "><p id="p1184mcpsimp"><a name="p1184mcpsimp"></a><a name="p1184mcpsimp"></a>vertical</p>
</td>
<td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.2 "><p id="p1186mcpsimp"><a name="p1186mcpsimp"></a><a name="p1186mcpsimp"></a>boolean</p>
</td>
<td class="cellrowborder" valign="top" width="9.64%" headers="mcps1.1.5.1.3 "><p id="p1188mcpsimp"><a name="p1188mcpsimp"></a><a name="p1188mcpsimp"></a>false</p>
</td>
<td class="cellrowborder" valign="top" width="61%" headers="mcps1.1.5.1.4 "><p id="p1190mcpsimp"><a name="p1190mcpsimp"></a><a name="p1190mcpsimp"></a>使用水平分割线还是垂直分割线，false: 水平分割线， true:垂直分割线。</p>
</td>
</tr>
<tr id="row1191mcpsimp"><td class="cellrowborder" valign="top" width="14.540000000000001%" headers="mcps1.1.5.1.1 "><p id="p1193mcpsimp"><a name="p1193mcpsimp"></a><a name="p1193mcpsimp"></a>color</p>
</td>
<td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.2 "><p id="p1195mcpsimp"><a name="p1195mcpsimp"></a><a name="p1195mcpsimp"></a>Color</p>
</td>
<td class="cellrowborder" valign="top" width="9.64%" headers="mcps1.1.5.1.3 "><p id="p1197mcpsimp"><a name="p1197mcpsimp"></a><a name="p1197mcpsimp"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="61%" headers="mcps1.1.5.1.4 "><p id="p1199mcpsimp"><a name="p1199mcpsimp"></a><a name="p1199mcpsimp"></a>设置分割线颜色。</p>
</td>
</tr>
<tr id="row1200mcpsimp"><td class="cellrowborder" valign="top" width="14.540000000000001%" headers="mcps1.1.5.1.1 "><p id="p1202mcpsimp"><a name="p1202mcpsimp"></a><a name="p1202mcpsimp"></a>strokeWidth</p>
</td>
<td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.2 "><p id="p1204mcpsimp"><a name="p1204mcpsimp"></a><a name="p1204mcpsimp"></a>Length</p>
</td>
<td class="cellrowborder" valign="top" width="9.64%" headers="mcps1.1.5.1.3 "><p id="p1206mcpsimp"><a name="p1206mcpsimp"></a><a name="p1206mcpsimp"></a>1</p>
</td>
<td class="cellrowborder" valign="top" width="61%" headers="mcps1.1.5.1.4 "><p id="p1208mcpsimp"><a name="p1208mcpsimp"></a><a name="p1208mcpsimp"></a>设置分割线宽度。</p>
</td>
</tr>
<tr id="row1209mcpsimp"><td class="cellrowborder" valign="top" width="14.540000000000001%" headers="mcps1.1.5.1.1 "><p id="p1211mcpsimp"><a name="p1211mcpsimp"></a><a name="p1211mcpsimp"></a>lineCap</p>
</td>
<td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.2 "><p id="p1213mcpsimp"><a name="p1213mcpsimp"></a><a name="p1213mcpsimp"></a><a href="ts-appendix-enums.md#section549694781614">LineCapStyle</a></p>
</td>
<td class="cellrowborder" valign="top" width="9.64%" headers="mcps1.1.5.1.3 "><p id="p1215mcpsimp"><a name="p1215mcpsimp"></a><a name="p1215mcpsimp"></a>Butt</p>
</td>
<td class="cellrowborder" valign="top" width="61%" headers="mcps1.1.5.1.4 "><p id="p1217mcpsimp"><a name="p1217mcpsimp"></a><a name="p1217mcpsimp"></a>设置分割线条的端点样式，默认为Butt。</p>
</td>
</tr>
</tbody>
</table>

## 事件<a name="section8567175225417"></a>

不支持通用事件。

## 示例<a name="section18551123820541"></a>

```
@Entry
@Component
struct DividerExample {
  build() {
    Flex({ direction: FlexDirection.Column, alignItems: ItemAlign.Start, justifyContent: FlexAlign.SpaceBetween }) {
      Text('Horizontal divider').fontSize(9).fontColor(0xCCCCCC)
      Row().width('100%').height(40).backgroundColor(0xF1F3F5)
      Divider()
      Row().width('100%').height(40).backgroundColor(0xF1F3F5)

      Text('Vertical divider').fontSize(9).fontColor(0xCCCCCC)
      Flex({ alignItems: ItemAlign.Center, wrap: FlexWrap.Wrap }) {
        Text('bravery')
        Divider().vertical(true).margin(20).height(15)
        Text('effort')
        Divider().vertical(true).margin(20).height(15)
        Text('upward')
      }.width(250)

      Text('Custom Styles').fontSize(9).fontColor(0xCCCCCC)
      Row().width('100%').height(40).backgroundColor(0xF1F3F5)
      Divider().vertical(false).strokeWidth(5).color(0x2788D9).lineCap(LineCapStyle.Round)
      Row().width('100%').height(40).backgroundColor(0xF1F3F5)
    }.width('100%').height(350).padding({ left: 35, right: 35, top: 35 })
  }
}
```

![](figures/divider.png)

