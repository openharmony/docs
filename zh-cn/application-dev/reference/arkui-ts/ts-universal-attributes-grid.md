# 栅格设置<a name="ZH-CN_TOPIC_0000001174112533"></a>

>![](../../public_sys-resources/icon-note.gif) **说明：** 
>栅格布局的列宽、列间距由距离最近的GridContainer父组件决定。使用栅格属性的组件树上至少需要有1个GridContainer容器组件。

<a name="table1265031910316"></a>
<table><thead align="left"><tr id="row9650111916319"><th class="cellrowborder" valign="top" width="15.42%" id="mcps1.1.5.1.1"><p id="p18651919153114"><a name="p18651919153114"></a><a name="p18651919153114"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="23.880000000000003%" id="mcps1.1.5.1.2"><p id="p965116197315"><a name="p965116197315"></a><a name="p965116197315"></a>参数类型</p>
</th>
<th class="cellrowborder" valign="top" width="9.55%" id="mcps1.1.5.1.3"><p id="p4651181953113"><a name="p4651181953113"></a><a name="p4651181953113"></a>默认值</p>
</th>
<th class="cellrowborder" valign="top" width="51.15%" id="mcps1.1.5.1.4"><p id="p6651191918319"><a name="p6651191918319"></a><a name="p6651191918319"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row1165131943114"><td class="cellrowborder" valign="top" width="15.42%" headers="mcps1.1.5.1.1 "><p id="p10511918121510"><a name="p10511918121510"></a><a name="p10511918121510"></a>useSizeType</p>
</td>
<td class="cellrowborder" valign="top" width="23.880000000000003%" headers="mcps1.1.5.1.2 "><p id="p2511181812157"><a name="p2511181812157"></a><a name="p2511181812157"></a>{</p>
<p id="p1151191816156"><a name="p1151191816156"></a><a name="p1151191816156"></a>xs?: number | { span: number, offset: number },</p>
<p id="p451101841519"><a name="p451101841519"></a><a name="p451101841519"></a>sm?: number | { span: number, offset: number },</p>
<p id="p12511171851518"><a name="p12511171851518"></a><a name="p12511171851518"></a>md?: number | { span: number, offset: number },</p>
<p id="p951171851514"><a name="p951171851514"></a><a name="p951171851514"></a>lg?: number | { span: number, offset: number }</p>
<p id="p45111418191517"><a name="p45111418191517"></a><a name="p45111418191517"></a>}</p>
</td>
<td class="cellrowborder" valign="top" width="9.55%" headers="mcps1.1.5.1.3 "><p id="p10511518201518"><a name="p10511518201518"></a><a name="p10511518201518"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="51.15%" headers="mcps1.1.5.1.4 "><p id="p684393617229"><a name="p684393617229"></a><a name="p684393617229"></a>设置在特定设备宽度类型下的占用列数和偏移列数，span: 占用列数; offset: 偏移列数。</p>
<p id="p251151841510"><a name="p251151841510"></a><a name="p251151841510"></a>当值为number类型时，仅设置列数， 当格式如{"span": 1, "offset": 0}时，指同时设置占用列数与偏移列数。</p>
<a name="ul2612171925511"></a><a name="ul2612171925511"></a><ul id="ul2612171925511"><li>xs: 指设备宽度类型为SizeType.XS时的占用列数和偏移列数。</li><li>sm: 指设备宽度类型为SizeType.SM时的占用列数和偏移列数。</li></ul>
<a name="ul2246226185512"></a><a name="ul2246226185512"></a><ul id="ul2246226185512"><li>md: 指设备宽度类型为SizeType.MD时的占用列数和偏移列数。</li><li>lg: 指设备宽度类型为SizeType.LG时的占用列数和偏移列数。</li></ul>
</td>
</tr>
<tr id="row472mcpsimp"><td class="cellrowborder" valign="top" width="15.42%" headers="mcps1.1.5.1.1 "><p id="p160914118157"><a name="p160914118157"></a><a name="p160914118157"></a>gridSpan</p>
</td>
<td class="cellrowborder" valign="top" width="23.880000000000003%" headers="mcps1.1.5.1.2 "><p id="p136091811101519"><a name="p136091811101519"></a><a name="p136091811101519"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="9.55%" headers="mcps1.1.5.1.3 "><p id="p360921112150"><a name="p360921112150"></a><a name="p360921112150"></a>1</p>
</td>
<td class="cellrowborder" valign="top" width="51.15%" headers="mcps1.1.5.1.4 "><p id="p176091311181517"><a name="p176091311181517"></a><a name="p176091311181517"></a>默认占用列数，指useSizeType属性没有设置对应尺寸的列数（span)时，占用的栅格列数。</p>
<div class="note" id="note155021950101610"><a name="note155021950101610"></a><a name="note155021950101610"></a><span class="notetitle"> 说明： </span><div class="notebody"><p id="p20503115041613"><a name="p20503115041613"></a><a name="p20503115041613"></a>设置了栅格span属性，组件的宽度由栅格布局决定。</p>
</div></div>
</td>
</tr>
<tr id="row481mcpsimp"><td class="cellrowborder" valign="top" width="15.42%" headers="mcps1.1.5.1.1 "><p id="p3156334151515"><a name="p3156334151515"></a><a name="p3156334151515"></a>gridOffset</p>
</td>
<td class="cellrowborder" valign="top" width="23.880000000000003%" headers="mcps1.1.5.1.2 "><p id="p16156143420150"><a name="p16156143420150"></a><a name="p16156143420150"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="9.55%" headers="mcps1.1.5.1.3 "><p id="p1615611347155"><a name="p1615611347155"></a><a name="p1615611347155"></a>0</p>
</td>
<td class="cellrowborder" valign="top" width="51.15%" headers="mcps1.1.5.1.4 "><p id="p515683491513"><a name="p515683491513"></a><a name="p515683491513"></a>默认偏移列数，指useSizeType属性没有设置对应尺寸的偏移(offset)时， 当前组件沿着父组件Start方向，偏移的列数，也就是当前组件位于第n列。</p>
<div class="note" id="note31561434121517"><a name="note31561434121517"></a><a name="note31561434121517"></a><span class="notetitle"> 说明： </span><div class="notebody"><p id="p1315613431519"><a name="p1315613431519"></a><a name="p1315613431519"></a>1.  配置该属性后，当前组件在父组件水平方向的布局不再跟随父组件原有的布局方式，而是沿着父组件的Start方向偏移一定位移。</p>
<p id="p3156203412152"><a name="p3156203412152"></a><a name="p3156203412152"></a>2.  偏移位移 = （列宽 + 间距）* 列数。</p>
<p id="p16156113416159"><a name="p16156113416159"></a><a name="p16156113416159"></a>3.  设置了偏移(gridOffset)的组件之后的兄弟组件会根据该组件进行相对布局，类似相对布局。</p>
</div></div>
</td>
</tr>
</tbody>
</table>

## 示例<a name="section1976245813394"></a>

```
@Entry
@Component
struct GridContainerExample1 {
  build(){
    GridContainer() {
      Row({}) {
        Row() {
          Text('Left').fontSize(25)
        }
        .useSizeType({
          xs: { span: 1, offset: 0 }, sm: { span: 1, offset: 0 },
          md: { span: 1, offset: 0 }, lg: { span: 2, offset: 0 }
        })
        .height("100%")
        .backgroundColor(0x66bbb2cb)
        Row() {
          Text('Center').fontSize(25)
        }
        .useSizeType({
          xs: { span: 1, offset: 0 }, sm: { span: 2, offset: 1 },
          md: { span: 5, offset: 1 }, lg: { span: 7, offset: 2 }
        })
        .height("100%")
        .backgroundColor(0x66b6c5d1)
        Row() {
          Text('Right').fontSize(25)
        }
        .useSizeType({
          xs: { span: 1, offset: 0 }, sm: { span: 1, offset: 3 },
          md: { span: 2, offset: 6 }, lg: { span: 3, offset: 9 }
        })
        .height("100%")
        .backgroundColor(0x66bbb2cb)
      }
      .height(200)
    }
    .backgroundColor(0xf1f3f5)
    .margin({ top: 10 })
  }
}
```

**图 1**  设备宽度为SM<a name="fig20276133417719"></a>  
![](figures/设备宽度为SM.png "设备宽度为SM")

**图 2**  设备宽度为MD<a name="fig677595214820"></a>  
![](figures/设备宽度为MD.png "设备宽度为MD")

**图 3**  设备宽度为LG<a name="fig15900112016917"></a>  
![](figures/设备宽度为LG.png "设备宽度为LG")

