# 位置设置<a name="ZH-CN_TOPIC_0000001166648181"></a>

<a name="table2377mcpsimp"></a>
<table><thead align="left"><tr id="row2385mcpsimp"><th class="cellrowborder" valign="top" width="17.341734173417343%" id="mcps1.1.5.1.1"><p id="p2387mcpsimp"><a name="p2387mcpsimp"></a><a name="p2387mcpsimp"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="28.672867286728675%" id="mcps1.1.5.1.2"><p id="p2389mcpsimp"><a name="p2389mcpsimp"></a><a name="p2389mcpsimp"></a>参数类型</p>
</th>
<th class="cellrowborder" valign="top" width="14.35143514351435%" id="mcps1.1.5.1.3"><p id="p2391mcpsimp"><a name="p2391mcpsimp"></a><a name="p2391mcpsimp"></a>默认值</p>
</th>
<th class="cellrowborder" valign="top" width="39.63396339633963%" id="mcps1.1.5.1.4"><p id="p2395mcpsimp"><a name="p2395mcpsimp"></a><a name="p2395mcpsimp"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row2396mcpsimp"><td class="cellrowborder" valign="top" width="17.341734173417343%" headers="mcps1.1.5.1.1 "><p id="p2398mcpsimp"><a name="p2398mcpsimp"></a><a name="p2398mcpsimp"></a>align</p>
</td>
<td class="cellrowborder" valign="top" width="28.672867286728675%" headers="mcps1.1.5.1.2 "><p id="p2400mcpsimp"><a name="p2400mcpsimp"></a><a name="p2400mcpsimp"></a><a href="ts-appendix-enums.md#section1145418513159">Alignment</a></p>
</td>
<td class="cellrowborder" valign="top" width="14.35143514351435%" headers="mcps1.1.5.1.3 "><p id="p2402mcpsimp"><a name="p2402mcpsimp"></a><a name="p2402mcpsimp"></a>Center</p>
</td>
<td class="cellrowborder" valign="top" width="39.63396339633963%" headers="mcps1.1.5.1.4 "><p id="p3491422033"><a name="p3491422033"></a><a name="p3491422033"></a>设置元素内容的对齐方式，只有当设置的width和height大小超过元素本身内容大小时生效。</p>
</td>
</tr>
<tr id="row2407mcpsimp"><td class="cellrowborder" valign="top" width="17.341734173417343%" headers="mcps1.1.5.1.1 "><p id="p2409mcpsimp"><a name="p2409mcpsimp"></a><a name="p2409mcpsimp"></a>direction</p>
</td>
<td class="cellrowborder" valign="top" width="28.672867286728675%" headers="mcps1.1.5.1.2 "><p id="p2411mcpsimp"><a name="p2411mcpsimp"></a><a name="p2411mcpsimp"></a><a href="#li12312485585">Direction</a></p>
</td>
<td class="cellrowborder" valign="top" width="14.35143514351435%" headers="mcps1.1.5.1.3 "><p id="p2413mcpsimp"><a name="p2413mcpsimp"></a><a name="p2413mcpsimp"></a>Auto</p>
</td>
<td class="cellrowborder" valign="top" width="39.63396339633963%" headers="mcps1.1.5.1.4 "><p id="p1980615130316"><a name="p1980615130316"></a><a name="p1980615130316"></a>设置元素水平方向的布局，可选值参照<a href="#li12312485585">Direction</a>枚举说明。</p>
</td>
</tr>
<tr id="row2418mcpsimp"><td class="cellrowborder" valign="top" width="17.341734173417343%" headers="mcps1.1.5.1.1 "><p id="p2420mcpsimp"><a name="p2420mcpsimp"></a><a name="p2420mcpsimp"></a>position</p>
</td>
<td class="cellrowborder" valign="top" width="28.672867286728675%" headers="mcps1.1.5.1.2 "><p id="p16757125154718"><a name="p16757125154718"></a><a name="p16757125154718"></a>{</p>
<p id="p183016439471"><a name="p183016439471"></a><a name="p183016439471"></a>x: Length,</p>
<p id="p764913452474"><a name="p764913452474"></a><a name="p764913452474"></a>y: Length</p>
<p id="p2422mcpsimp"><a name="p2422mcpsimp"></a><a name="p2422mcpsimp"></a>}</p>
</td>
<td class="cellrowborder" valign="top" width="14.35143514351435%" headers="mcps1.1.5.1.3 "><p id="p2424mcpsimp"><a name="p2424mcpsimp"></a><a name="p2424mcpsimp"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="39.63396339633963%" headers="mcps1.1.5.1.4 "><p id="p2428mcpsimp"><a name="p2428mcpsimp"></a><a name="p2428mcpsimp"></a>使用绝对定位，设置元素锚点相对于父容器顶部起点偏移位置。在布局容器中，设置该属性不影响父容器布局，仅在绘制时进行位置调整。</p>
</td>
</tr>
<tr id="row1147212479269"><td class="cellrowborder" valign="top" width="17.341734173417343%" headers="mcps1.1.5.1.1 "><p id="p16472184713266"><a name="p16472184713266"></a><a name="p16472184713266"></a>markAnchor</p>
</td>
<td class="cellrowborder" valign="top" width="28.672867286728675%" headers="mcps1.1.5.1.2 "><p id="p123675110476"><a name="p123675110476"></a><a name="p123675110476"></a>{</p>
<p id="p1896253114716"><a name="p1896253114716"></a><a name="p1896253114716"></a>x: Length,</p>
<p id="p46656558470"><a name="p46656558470"></a><a name="p46656558470"></a>y: Length</p>
<p id="p106108613276"><a name="p106108613276"></a><a name="p106108613276"></a>}</p>
</td>
<td class="cellrowborder" valign="top" width="14.35143514351435%" headers="mcps1.1.5.1.3 "><p id="p12862191814214"><a name="p12862191814214"></a><a name="p12862191814214"></a>{</p>
<p id="p98521729"><a name="p98521729"></a><a name="p98521729"></a>x: 0,</p>
<p id="p88483417217"><a name="p88483417217"></a><a name="p88483417217"></a>y: 0</p>
<p id="p1646264492820"><a name="p1646264492820"></a><a name="p1646264492820"></a>}</p>
</td>
<td class="cellrowborder" valign="top" width="39.63396339633963%" headers="mcps1.1.5.1.4 "><p id="p44721347162616"><a name="p44721347162616"></a><a name="p44721347162616"></a>设置元素在位置定位时的锚点，以元素顶部起点作为基准点进行偏移。</p>
</td>
</tr>
<tr id="row2429mcpsimp"><td class="cellrowborder" valign="top" width="17.341734173417343%" headers="mcps1.1.5.1.1 "><p id="p2431mcpsimp"><a name="p2431mcpsimp"></a><a name="p2431mcpsimp"></a>offset</p>
</td>
<td class="cellrowborder" valign="top" width="28.672867286728675%" headers="mcps1.1.5.1.2 "><p id="p1925713118484"><a name="p1925713118484"></a><a name="p1925713118484"></a>{</p>
<p id="p14734111364812"><a name="p14734111364812"></a><a name="p14734111364812"></a>x: Length,</p>
<p id="p834931664818"><a name="p834931664818"></a><a name="p834931664818"></a>y: Length</p>
<p id="p2433mcpsimp"><a name="p2433mcpsimp"></a><a name="p2433mcpsimp"></a>}</p>
</td>
<td class="cellrowborder" valign="top" width="14.35143514351435%" headers="mcps1.1.5.1.3 "><p id="p12906114817217"><a name="p12906114817217"></a><a name="p12906114817217"></a>{</p>
<p id="p116940501223"><a name="p116940501223"></a><a name="p116940501223"></a>x: 0,</p>
<p id="p196153523"><a name="p196153523"></a><a name="p196153523"></a>y: 0</p>
<p id="p2435mcpsimp"><a name="p2435mcpsimp"></a><a name="p2435mcpsimp"></a>}</p>
</td>
<td class="cellrowborder" valign="top" width="39.63396339633963%" headers="mcps1.1.5.1.4 "><p id="p2439mcpsimp"><a name="p2439mcpsimp"></a><a name="p2439mcpsimp"></a>相对布局完成位置坐标偏移量，设置该属性，不影响父容器布局，仅在绘制时进行位置调整。</p>
</td>
</tr>
</tbody>
</table>

-   <a name="li12312485585"></a>Direction枚举说明

    <a name="table197411342193817"></a>
    <table><thead align="left"><tr id="row374111426387"><th class="cellrowborder" valign="top" width="25.2%" id="mcps1.1.3.1.1"><p id="p15741134223813"><a name="p15741134223813"></a><a name="p15741134223813"></a>名称</p>
    </th>
    <th class="cellrowborder" valign="top" width="74.8%" id="mcps1.1.3.1.2"><p id="p474164215383"><a name="p474164215383"></a><a name="p474164215383"></a>描述</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row1774194233815"><td class="cellrowborder" valign="top" width="25.2%" headers="mcps1.1.3.1.1 "><p id="p1674111428389"><a name="p1674111428389"></a><a name="p1674111428389"></a>Ltr</p>
    </td>
    <td class="cellrowborder" valign="top" width="74.8%" headers="mcps1.1.3.1.2 "><p id="p18741134243810"><a name="p18741134243810"></a><a name="p18741134243810"></a>元素从左到右布局。</p>
    </td>
    </tr>
    <tr id="row1741442113814"><td class="cellrowborder" valign="top" width="25.2%" headers="mcps1.1.3.1.1 "><p id="p87418424388"><a name="p87418424388"></a><a name="p87418424388"></a>Rtl</p>
    </td>
    <td class="cellrowborder" valign="top" width="74.8%" headers="mcps1.1.3.1.2 "><p id="p6741104213389"><a name="p6741104213389"></a><a name="p6741104213389"></a>元素从右到左布局。</p>
    </td>
    </tr>
    <tr id="row12741542203810"><td class="cellrowborder" valign="top" width="25.2%" headers="mcps1.1.3.1.1 "><p id="p12742342103816"><a name="p12742342103816"></a><a name="p12742342103816"></a>Auto</p>
    </td>
    <td class="cellrowborder" valign="top" width="74.8%" headers="mcps1.1.3.1.2 "><p id="p157426425387"><a name="p157426425387"></a><a name="p157426425387"></a>使用系统默认布局方向。</p>
    </td>
    </tr>
    </tbody>
    </table>


## 示例<a name="section12073184715"></a>

```
@Entry
@Component
struct PositionExample {
  build() {
    Column() {
      Column({space: 10}) {
        Text('align').fontSize(9).fontColor(0xCCCCCC).width('90%')
        Text('top start')
          .align(Alignment.TopStart)
          .height(50)
          .width('90%')
          .fontSize(16)
          .backgroundColor(0xFFE4C4)

        Text('direction').fontSize(9).fontColor(0xCCCCCC).width('90%')
        Row() {
          Text('1').height(50).width('25%').fontSize(16).backgroundColor(0xF5DEB3)
          Text('2').height(50).width('25%').fontSize(16).backgroundColor(0xD2B48C)
          Text('3').height(50).width('25%').fontSize(16).backgroundColor(0xF5DEB3)
          Text('4').height(50).width('25%').fontSize(16).backgroundColor(0xD2B48C)
        }
        .width('90%')
        .direction(Direction.Rtl)
      }
    }
    .width('100%').margin({ top: 5 }).direction(Direction.Rtl)
  }
}
```

![](figures/position.gif)

```
@Entry
@Component
struct PositionExample2 {
  build() {
    Column({ space: 20 }) {
      Text('position').fontSize(12).fontColor(0xCCCCCC).width('90%')
      Row({ space: 20 }) {
        Text('1').size({ width: '45%', height: '50' }).backgroundColor(0xdeb887).border({ width: 1 }) .fontSize(16)
        Text('2 position(25, 15)')
          .size({ width: '60%', height: '30' }).backgroundColor(0xbbb2cb).border({ width: 1 })
          .fontSize(16).align(Alignment.Start)
          .position({ x: 25, y: 15 })
        Text('3').size({ width: '45%', height: '50' }).backgroundColor(0xdeb887).border({ width: 1 }).fontSize(16)
        Text('4 position(50%, 70%)')
          .size({ width: '50%', height: '50' }).backgroundColor(0xbbb2cb).border({ width: 1 }).fontSize(16)
          .position({ x: '50%', y: '70%' })
      }.width('90%').height(100).border({ width: 1, style: BorderStyle.Dashed })

      Text('markAnchor').fontSize(12).fontColor(0xCCCCCC).width('90%')
      Stack({ alignContent: Alignment.TopStart }) {
        Row()
          .size({ width: '100', height: '100' })
          .backgroundColor(0xdeb887)
        Image($r('app.media.ic_health_heart'))
          .size({ width: 25, height: 25 })
          .markAnchor({ x: 25, y: 25 })
        Image($r('app.media.ic_health_heart'))
          .size({ width: 25, height: 25 })
          .markAnchor({ x: 25, y: 25 })
          .position({ x: '100%', y: '100%' })
      }.margin({ top: 25 }).border({ width: 1, style: BorderStyle.Dashed })

      Text('offset').fontSize(12).fontColor(0xCCCCCC).width('90%')
      Row() {
        Text('1').size({ width: '15%', height: '50' }).backgroundColor(0xdeb887).border({ width: 1 }).fontSize(16)
        Text('2\noffset(15, 15)')
          .size({ width: 120, height: '50' }).backgroundColor(0xbbb2cb).border({ width: 1 })
          .fontSize(16).align(Alignment.Start)
          .offset({ x: 15, y: 15 })
        Text('3').size({ width: '15%', height: '50' }).backgroundColor(0xdeb887).border({ width: 1 }).fontSize(16)
        Text('4\noffset(-10%, 20%)')
          .size({ width: 150, height: '50' }) .backgroundColor(0xbbb2cb).border({ width: 1 }).fontSize(16)
          .offset({ x: '-10%', y: '20%' })
      }.width('90%').height(100).border({ width: 1, style: BorderStyle.Dashed })
    }
    .width('100%').margin({ top: 25 })
  }
}
```

![](figures/position2.gif)

