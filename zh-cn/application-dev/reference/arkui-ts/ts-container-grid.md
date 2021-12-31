# Grid<a name="ZH-CN_TOPIC_0000001237355067"></a>

>![](../../public_sys-resources/icon-note.gif) **说明：** 
>该组件从API Version 7开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。

网格容器，二维布局，将容器划分成"行"和"列"，产生单元格，然后指定"项目所在"的单元格，可以任意组合不同的网格，做出各种各样的布局。

## 权限列表<a name="section62209458329"></a>

无

## 子组件<a name="section18342185015322"></a>

包含[GridItem](ts-container-griditem.md)子组件。

## 接口说明<a name="section3362154133312"></a>

Grid\(\)

## 属性<a name="section4907201336"></a>

<table><thead align="left"><tr><th class="cellrowborder" valign="top" width="19.09%" id="mcps1.1.5.1.1"><p>名称</p>
</th>
<th class="cellrowborder" valign="top" width="11.600000000000001%" id="mcps1.1.5.1.2"><p>参数类型</p>
</th>
<th class="cellrowborder" valign="top" width="11.92%" id="mcps1.1.5.1.3"><p>默认值</p>
</th>
<th class="cellrowborder" valign="top" width="57.38999999999999%" id="mcps1.1.5.1.4"><p>描述</p>
</th>
</tr>
</thead>
<tbody><tr><td class="cellrowborder" valign="top" width="19.09%" headers="mcps1.1.5.1.1 "><p>columnsTemplate</p>
</td>
<td class="cellrowborder" valign="top" width="11.600000000000001%" headers="mcps1.1.5.1.2 "><p>string</p>
</td>
<td class="cellrowborder" valign="top" width="11.92%" headers="mcps1.1.5.1.3 "><p>'1fr'</p>
</td>
<td class="cellrowborder" valign="top" width="57.38999999999999%" headers="mcps1.1.5.1.4 "><p>用于设置当前网格布局列的数量，不设置时默认1列 示例, '1fr 1fr 2fr' 分三列，将父组件允许的宽分为4等份，第一列占1份，第二列占一份，第三列占2份。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="19.09%" headers="mcps1.1.5.1.1 "><p>rowsTemplate</p>
</td>
<td class="cellrowborder" valign="top" width="11.600000000000001%" headers="mcps1.1.5.1.2 "><p>string</p>
</td>
<td class="cellrowborder" valign="top" width="11.92%" headers="mcps1.1.5.1.3 "><p>'1fr'</p>
</td>
<td class="cellrowborder" valign="top" width="57.38999999999999%" headers="mcps1.1.5.1.4 "><p>用于设置当前网格布局行的数量，不设置时默认1行 示例, '1fr 1fr 2fr'分三行，将父组件允许的高分为4等份，第一行占1份，第二行占一份，第三行占2份。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="19.09%" headers="mcps1.1.5.1.1 "><p>columnsGap</p>
</td>
<td class="cellrowborder" valign="top" width="11.600000000000001%" headers="mcps1.1.5.1.2 "><p>Length</p>
</td>
<td class="cellrowborder" valign="top" width="11.92%" headers="mcps1.1.5.1.3 "><p>0</p>
</td>
<td class="cellrowborder" valign="top" width="57.38999999999999%" headers="mcps1.1.5.1.4 "><p>用于设置列与列的间距。</p>
</td>
</tr>
<tr><td class="cellrowborder" valign="top" width="19.09%" headers="mcps1.1.5.1.1 "><p>rowsGap</p>
</td>
<td class="cellrowborder" valign="top" width="11.600000000000001%" headers="mcps1.1.5.1.2 "><p>Length</p>
</td>
<td class="cellrowborder" valign="top" width="11.92%" headers="mcps1.1.5.1.3 "><p>0</p>
</td>
<td class="cellrowborder" valign="top" width="57.38999999999999%" headers="mcps1.1.5.1.4 "><p>用于设置行与行的间距。</p>
</td>
</tr>
</tbody>
</table>

## 事件<a name="section1822319492372"></a>

<table><thead align="left"><tr><th class="cellrowborder" valign="top" width="39.77%" id="mcps1.1.3.1.1"><p>名称</p>
</th>
<th class="cellrowborder" valign="top" width="60.23%" id="mcps1.1.3.1.2"><p>功能描述</p>
</th>
</tr>
</thead>
<tbody><tr><td class="cellrowborder" valign="top" width="39.77%" headers="mcps1.1.3.1.1 "><p>onScrollIndex(first: number) =&gt; void</p>
</td>
<td class="cellrowborder" valign="top" width="60.23%" headers="mcps1.1.3.1.2 "><p>当前列表显示的起始位置item发生变化时触发。</p>
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

![](figures/grid-3.gif)

