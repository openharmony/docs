# Grid<a name="ZH-CN_TOPIC_0000001158261259"></a>

网格容器，二维布局，将容器划分成"行"和"列"，产生单元格，然后指定"项目所在"的单元格，可以任意组合不同的网格，做出各种各样的布局。

## 权限类别<a name="section62209458329"></a>

无

## 子组件<a name="section18342185015322"></a>

包含[GridItem](ts-container-griditem.md)子组件。

## 接口说明<a name="section3362154133312"></a>

Grid\(\)

## 属性<a name="section4907201336"></a>

<a name="table1689mcpsimp"></a>
<table><thead align="left"><tr id="row1696mcpsimp"><th class="cellrowborder" valign="top" width="19.09%" id="mcps1.1.5.1.1"><p id="p1698mcpsimp"><a name="p1698mcpsimp"></a><a name="p1698mcpsimp"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="11.600000000000001%" id="mcps1.1.5.1.2"><p id="p1700mcpsimp"><a name="p1700mcpsimp"></a><a name="p1700mcpsimp"></a>参数类型</p>
</th>
<th class="cellrowborder" valign="top" width="11.92%" id="mcps1.1.5.1.3"><p id="p1702mcpsimp"><a name="p1702mcpsimp"></a><a name="p1702mcpsimp"></a>默认值</p>
</th>
<th class="cellrowborder" valign="top" width="57.38999999999999%" id="mcps1.1.5.1.4"><p id="p1704mcpsimp"><a name="p1704mcpsimp"></a><a name="p1704mcpsimp"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row1705mcpsimp"><td class="cellrowborder" valign="top" width="19.09%" headers="mcps1.1.5.1.1 "><p id="p1707mcpsimp"><a name="p1707mcpsimp"></a><a name="p1707mcpsimp"></a>columnsTemplate</p>
</td>
<td class="cellrowborder" valign="top" width="11.600000000000001%" headers="mcps1.1.5.1.2 "><p id="p1709mcpsimp"><a name="p1709mcpsimp"></a><a name="p1709mcpsimp"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="11.92%" headers="mcps1.1.5.1.3 "><p id="p1711mcpsimp"><a name="p1711mcpsimp"></a><a name="p1711mcpsimp"></a>'1fr'</p>
</td>
<td class="cellrowborder" valign="top" width="57.38999999999999%" headers="mcps1.1.5.1.4 "><p id="p1713mcpsimp"><a name="p1713mcpsimp"></a><a name="p1713mcpsimp"></a>用于设置当前网格布局列的数量，不设置时默认1列 示例, '1fr 1fr 2fr' 分三列，将父组件允许的宽分为4等份，第一列占1份，第二列占一份，第三列占2份。</p>
</td>
</tr>
<tr id="row1714mcpsimp"><td class="cellrowborder" valign="top" width="19.09%" headers="mcps1.1.5.1.1 "><p id="p1716mcpsimp"><a name="p1716mcpsimp"></a><a name="p1716mcpsimp"></a>rowsTemplate</p>
</td>
<td class="cellrowborder" valign="top" width="11.600000000000001%" headers="mcps1.1.5.1.2 "><p id="p1718mcpsimp"><a name="p1718mcpsimp"></a><a name="p1718mcpsimp"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="11.92%" headers="mcps1.1.5.1.3 "><p id="p1720mcpsimp"><a name="p1720mcpsimp"></a><a name="p1720mcpsimp"></a>'1fr'</p>
</td>
<td class="cellrowborder" valign="top" width="57.38999999999999%" headers="mcps1.1.5.1.4 "><p id="p1722mcpsimp"><a name="p1722mcpsimp"></a><a name="p1722mcpsimp"></a>用于设置当前网格布局行的数量，不设置时默认1行 示例, '1fr 1fr 2fr'分三行，将父组件允许的高分为4等份，第一行占1份，第二行占一份，第三行占2份。</p>
</td>
</tr>
<tr id="row1723mcpsimp"><td class="cellrowborder" valign="top" width="19.09%" headers="mcps1.1.5.1.1 "><p id="p1725mcpsimp"><a name="p1725mcpsimp"></a><a name="p1725mcpsimp"></a>columnsGap</p>
</td>
<td class="cellrowborder" valign="top" width="11.600000000000001%" headers="mcps1.1.5.1.2 "><p id="p1727mcpsimp"><a name="p1727mcpsimp"></a><a name="p1727mcpsimp"></a>Length</p>
</td>
<td class="cellrowborder" valign="top" width="11.92%" headers="mcps1.1.5.1.3 "><p id="p1729mcpsimp"><a name="p1729mcpsimp"></a><a name="p1729mcpsimp"></a>0</p>
</td>
<td class="cellrowborder" valign="top" width="57.38999999999999%" headers="mcps1.1.5.1.4 "><p id="p1731mcpsimp"><a name="p1731mcpsimp"></a><a name="p1731mcpsimp"></a>用于设置列与列的间距。</p>
</td>
</tr>
<tr id="row1732mcpsimp"><td class="cellrowborder" valign="top" width="19.09%" headers="mcps1.1.5.1.1 "><p id="p1734mcpsimp"><a name="p1734mcpsimp"></a><a name="p1734mcpsimp"></a>rowsGap</p>
</td>
<td class="cellrowborder" valign="top" width="11.600000000000001%" headers="mcps1.1.5.1.2 "><p id="p1736mcpsimp"><a name="p1736mcpsimp"></a><a name="p1736mcpsimp"></a>Length</p>
</td>
<td class="cellrowborder" valign="top" width="11.92%" headers="mcps1.1.5.1.3 "><p id="p1738mcpsimp"><a name="p1738mcpsimp"></a><a name="p1738mcpsimp"></a>0</p>
</td>
<td class="cellrowborder" valign="top" width="57.38999999999999%" headers="mcps1.1.5.1.4 "><p id="p1740mcpsimp"><a name="p1740mcpsimp"></a><a name="p1740mcpsimp"></a>用于设置行与行的间距。</p>
</td>
</tr>
</tbody>
</table>

## 事件<a name="section1822319492372"></a>

<a name="table1422484983716"></a>
<table><thead align="left"><tr id="row122247497373"><th class="cellrowborder" colspan="2" valign="top" id="mcps1.1.4.1.1"><p id="p1224949123712"><a name="p1224949123712"></a><a name="p1224949123712"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.1.4.1.2"><p id="p1022424983717"><a name="p1022424983717"></a><a name="p1022424983717"></a>功能描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row19224134910371"><td class="cellrowborder" colspan="2" valign="top" headers="mcps1.1.4.1.1 "><p id="p622474918373"><a name="p622474918373"></a><a name="p622474918373"></a>onScrollIndex(first: number) =&gt; void</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.1.4.1.2 "><p id="p18224144918373"><a name="p18224144918373"></a><a name="p18224144918373"></a>当前列表显示的起始位置item发生变化时触发。</p>
</td>
</tr>
</tbody>
</table>

## 示例<a name="section183419570330"></a>

```
@Entry
@Component
struct GridExample {
  @State Number: String[] = ['0', '1', '2', '3', '4']

  build() {
    Column({ space: 5 }) {
      Grid() {
        ForEach(this.Number, (day: string) => {
          ForEach(this.Number, (day: string) => {
            GridItem() {
              Text(day)
                .fontSize(16)
                .backgroundColor(0xF9CF93)
                .width('100%')
                .height('100%')
                .textAlign(TextAlign.Center)
            }
          }, day => day)
        }, day => day)
      }
      .columnsTemplate('1fr 1fr 1fr 1fr 1fr')
      .rowsTemplate('1fr 1fr 1fr 1fr 1fr')
      .columnsGap(10)
      .rowsGap(10)
      .width('90%')
      .backgroundColor(0xFAEEE0)
      .height(300)

      Text('scroll').fontColor(0xCCCCCC).fontSize(9).width('90%')
      Grid() {
        ForEach(this.Number, (day: string) => {
          ForEach(this.Number, (day: string) => {
            GridItem() {
              Text(day)
                .fontSize(16)
                .backgroundColor(0xF9CF93)
                .width('100%')
                .height(80)
                .textAlign(TextAlign.Center)
            }
          }, day => day)
        }, day => day)
      }
      .columnsTemplate('1fr 1fr 1fr 1fr 1fr')
      .columnsGap(10)
      .rowsGap(10)
      .onScrollIndex((first: number) => {
        console.info(first.toString())
      })
      .width('90%')
      .backgroundColor(0xFAEEE0)
      .height(300)
    }.width('100%').margin({ top: 5 })
  }
}
```

![](figures/grid-17.gif)

