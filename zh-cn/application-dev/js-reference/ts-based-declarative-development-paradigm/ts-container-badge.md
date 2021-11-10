# Badge<a name="ZH-CN_TOPIC_0000001196785703"></a>

新事件标记组件，在组件上提供事件信息展示能力。

## 子组件<a name="section1089034711356"></a>

支持单个子组件。

## 接口<a name="section17399164519412"></a>

Badge\(value: \{count: number, position?: BadgePosition, maxCount?: number, style?: BadgeStyle\}\)

-   参数

    <a name="table10719114169"></a>
    <table><thead align="left"><tr id="row1571913410610"><th class="cellrowborder" valign="top" width="16.11%" id="mcps1.1.6.1.1"><p id="p87202043618"><a name="p87202043618"></a><a name="p87202043618"></a>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="18.95%" id="mcps1.1.6.1.2"><p id="p5720441466"><a name="p5720441466"></a><a name="p5720441466"></a>参数类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="9.55%" id="mcps1.1.6.1.3"><p id="p147201241662"><a name="p147201241662"></a><a name="p147201241662"></a>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="13.18%" id="mcps1.1.6.1.4"><p id="p187201141967"><a name="p187201141967"></a><a name="p187201141967"></a>默认值</p>
    </th>
    <th class="cellrowborder" valign="top" width="42.21%" id="mcps1.1.6.1.5"><p id="p127201740612"><a name="p127201740612"></a><a name="p127201740612"></a>参数描述</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row12720249611"><td class="cellrowborder" valign="top" width="16.11%" headers="mcps1.1.6.1.1 "><p id="p07201441569"><a name="p07201441569"></a><a name="p07201441569"></a>count</p>
    </td>
    <td class="cellrowborder" valign="top" width="18.95%" headers="mcps1.1.6.1.2 "><p id="p872084169"><a name="p872084169"></a><a name="p872084169"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.55%" headers="mcps1.1.6.1.3 "><p id="p16720134166"><a name="p16720134166"></a><a name="p16720134166"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="13.18%" headers="mcps1.1.6.1.4 "><p id="p144311926155911"><a name="p144311926155911"></a><a name="p144311926155911"></a>-</p>
    </td>
    <td class="cellrowborder" valign="top" width="42.21%" headers="mcps1.1.6.1.5 "><p id="p137201841366"><a name="p137201841366"></a><a name="p137201841366"></a>设置提醒消息数。</p>
    </td>
    </tr>
    <tr id="row97201341367"><td class="cellrowborder" valign="top" width="16.11%" headers="mcps1.1.6.1.1 "><p id="p2072011415617"><a name="p2072011415617"></a><a name="p2072011415617"></a>position</p>
    </td>
    <td class="cellrowborder" valign="top" width="18.95%" headers="mcps1.1.6.1.2 "><p id="p19720541461"><a name="p19720541461"></a><a name="p19720541461"></a><a href="#li7315759142415">BadgePosition</a></p>
    </td>
    <td class="cellrowborder" valign="top" width="9.55%" headers="mcps1.1.6.1.3 "><p id="p1272074565"><a name="p1272074565"></a><a name="p1272074565"></a>否</p>
    </td>
    <td class="cellrowborder" valign="top" width="13.18%" headers="mcps1.1.6.1.4 "><p id="p6923632174018"><a name="p6923632174018"></a><a name="p6923632174018"></a>RightTop</p>
    </td>
    <td class="cellrowborder" valign="top" width="42.21%" headers="mcps1.1.6.1.5 "><p id="p26168425613"><a name="p26168425613"></a><a name="p26168425613"></a>设置提示点显示位置。</p>
    </td>
    </tr>
    <tr id="row1991692015619"><td class="cellrowborder" valign="top" width="16.11%" headers="mcps1.1.6.1.1 "><p id="p129169209564"><a name="p129169209564"></a><a name="p129169209564"></a>maxCount</p>
    </td>
    <td class="cellrowborder" valign="top" width="18.95%" headers="mcps1.1.6.1.2 "><p id="p99161220135617"><a name="p99161220135617"></a><a name="p99161220135617"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.55%" headers="mcps1.1.6.1.3 "><p id="p519323619415"><a name="p519323619415"></a><a name="p519323619415"></a>否</p>
    </td>
    <td class="cellrowborder" valign="top" width="13.18%" headers="mcps1.1.6.1.4 "><p id="p7916120155613"><a name="p7916120155613"></a><a name="p7916120155613"></a>99</p>
    </td>
    <td class="cellrowborder" valign="top" width="42.21%" headers="mcps1.1.6.1.5 "><p id="p29161220105614"><a name="p29161220105614"></a><a name="p29161220105614"></a>最大消息数，超过最大消息时仅显示maxCount+。</p>
    </td>
    </tr>
    <tr id="row010583375614"><td class="cellrowborder" valign="top" width="16.11%" headers="mcps1.1.6.1.1 "><p id="p1910523311561"><a name="p1910523311561"></a><a name="p1910523311561"></a>style</p>
    </td>
    <td class="cellrowborder" valign="top" width="18.95%" headers="mcps1.1.6.1.2 "><p id="p15105113317566"><a name="p15105113317566"></a><a name="p15105113317566"></a><a href="#li910545532420">BadgeStyle</a></p>
    </td>
    <td class="cellrowborder" valign="top" width="9.55%" headers="mcps1.1.6.1.3 "><p id="p16876536044"><a name="p16876536044"></a><a name="p16876536044"></a>否</p>
    </td>
    <td class="cellrowborder" valign="top" width="13.18%" headers="mcps1.1.6.1.4 "><p id="p14105193325614"><a name="p14105193325614"></a><a name="p14105193325614"></a>-</p>
    </td>
    <td class="cellrowborder" valign="top" width="42.21%" headers="mcps1.1.6.1.5 "><p id="p1610520333565"><a name="p1610520333565"></a><a name="p1610520333565"></a>Badge组件可设置样式，支持设置文本颜色、尺寸、圆点颜色和尺寸。</p>
    </td>
    </tr>
    </tbody>
    </table>


Badge\(value: \{value: string, position?: BadgePosition, style?: BadgeStyle\}\)

根据字符串创建提醒组件。

-   参数

    <a name="table16272859113719"></a>
    <table><thead align="left"><tr id="row1827215916372"><th class="cellrowborder" valign="top" width="16.11%" id="mcps1.1.6.1.1"><p id="p1627214597371"><a name="p1627214597371"></a><a name="p1627214597371"></a>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="17.71%" id="mcps1.1.6.1.2"><p id="p32721159143711"><a name="p32721159143711"></a><a name="p32721159143711"></a>参数类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="10.79%" id="mcps1.1.6.1.3"><p id="p327245916378"><a name="p327245916378"></a><a name="p327245916378"></a>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="13.18%" id="mcps1.1.6.1.4"><p id="p192721559103713"><a name="p192721559103713"></a><a name="p192721559103713"></a>默认值</p>
    </th>
    <th class="cellrowborder" valign="top" width="42.21%" id="mcps1.1.6.1.5"><p id="p132721059103714"><a name="p132721059103714"></a><a name="p132721059103714"></a>参数描述</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row627285973720"><td class="cellrowborder" valign="top" width="16.11%" headers="mcps1.1.6.1.1 "><p id="p8272145933716"><a name="p8272145933716"></a><a name="p8272145933716"></a>value</p>
    </td>
    <td class="cellrowborder" valign="top" width="17.71%" headers="mcps1.1.6.1.2 "><p id="p227225903712"><a name="p227225903712"></a><a name="p227225903712"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="10.79%" headers="mcps1.1.6.1.3 "><p id="p14272959153714"><a name="p14272959153714"></a><a name="p14272959153714"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="13.18%" headers="mcps1.1.6.1.4 "><p id="p227212593379"><a name="p227212593379"></a><a name="p227212593379"></a>-</p>
    </td>
    <td class="cellrowborder" valign="top" width="42.21%" headers="mcps1.1.6.1.5 "><p id="p1627216590372"><a name="p1627216590372"></a><a name="p1627216590372"></a>提示内容的文本字符串。</p>
    </td>
    </tr>
    <tr id="row2272459183716"><td class="cellrowborder" valign="top" width="16.11%" headers="mcps1.1.6.1.1 "><p id="p7272115917378"><a name="p7272115917378"></a><a name="p7272115917378"></a>position</p>
    </td>
    <td class="cellrowborder" valign="top" width="17.71%" headers="mcps1.1.6.1.2 "><p id="p1327212597375"><a name="p1327212597375"></a><a name="p1327212597375"></a><a href="#li7315759142415">BadgePosition</a></p>
    </td>
    <td class="cellrowborder" valign="top" width="10.79%" headers="mcps1.1.6.1.3 "><p id="p227218594378"><a name="p227218594378"></a><a name="p227218594378"></a>否</p>
    </td>
    <td class="cellrowborder" valign="top" width="13.18%" headers="mcps1.1.6.1.4 "><p id="p1622693010409"><a name="p1622693010409"></a><a name="p1622693010409"></a>RightTop</p>
    </td>
    <td class="cellrowborder" valign="top" width="42.21%" headers="mcps1.1.6.1.5 "><p id="p132729596377"><a name="p132729596377"></a><a name="p132729596377"></a>设置提示点显示位置。</p>
    </td>
    </tr>
    <tr id="row227385919378"><td class="cellrowborder" valign="top" width="16.11%" headers="mcps1.1.6.1.1 "><p id="p427355918375"><a name="p427355918375"></a><a name="p427355918375"></a>style</p>
    </td>
    <td class="cellrowborder" valign="top" width="17.71%" headers="mcps1.1.6.1.2 "><p id="p14721195722617"><a name="p14721195722617"></a><a name="p14721195722617"></a><a href="#li910545532420">BadgeStyle</a></p>
    </td>
    <td class="cellrowborder" valign="top" width="10.79%" headers="mcps1.1.6.1.3 "><p id="p11273559103712"><a name="p11273559103712"></a><a name="p11273559103712"></a>否</p>
    </td>
    <td class="cellrowborder" valign="top" width="13.18%" headers="mcps1.1.6.1.4 "><p id="p1527355933714"><a name="p1527355933714"></a><a name="p1527355933714"></a>-</p>
    </td>
    <td class="cellrowborder" valign="top" width="42.21%" headers="mcps1.1.6.1.5 "><p id="p3273105983711"><a name="p3273105983711"></a><a name="p3273105983711"></a>Badge组件可设置样式，支持设置文本颜色、尺寸、圆点颜色和尺寸。</p>
    </td>
    </tr>
    </tbody>
    </table>


-   <a name="li910545532420"></a>BadgeStyle对象说明

    <a name="table13726195418229"></a>
    <table><thead align="left"><tr id="row87261254182220"><th class="cellrowborder" valign="top" width="14.85%" id="mcps1.1.6.1.1"><p id="p4726165413222"><a name="p4726165413222"></a><a name="p4726165413222"></a>名称</p>
    </th>
    <th class="cellrowborder" valign="top" width="19.73%" id="mcps1.1.6.1.2"><p id="p972617545229"><a name="p972617545229"></a><a name="p972617545229"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="6.569999999999999%" id="mcps1.1.6.1.3"><p id="p87262054142210"><a name="p87262054142210"></a><a name="p87262054142210"></a>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="9.17%" id="mcps1.1.6.1.4"><p id="p187268547223"><a name="p187268547223"></a><a name="p187268547223"></a>默认值</p>
    </th>
    <th class="cellrowborder" valign="top" width="49.68%" id="mcps1.1.6.1.5"><p id="p157261454152211"><a name="p157261454152211"></a><a name="p157261454152211"></a>描述</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row11726125442212"><td class="cellrowborder" valign="top" width="14.85%" headers="mcps1.1.6.1.1 "><p id="p07260542222"><a name="p07260542222"></a><a name="p07260542222"></a>color</p>
    </td>
    <td class="cellrowborder" valign="top" width="19.73%" headers="mcps1.1.6.1.2 "><p id="p1072665415220"><a name="p1072665415220"></a><a name="p1072665415220"></a>Color</p>
    </td>
    <td class="cellrowborder" valign="top" width="6.569999999999999%" headers="mcps1.1.6.1.3 "><p id="p572695420229"><a name="p572695420229"></a><a name="p572695420229"></a>否</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.17%" headers="mcps1.1.6.1.4 "><p id="p572610545224"><a name="p572610545224"></a><a name="p572610545224"></a>White</p>
    </td>
    <td class="cellrowborder" valign="top" width="49.68%" headers="mcps1.1.6.1.5 "><p id="p1972620548227"><a name="p1972620548227"></a><a name="p1972620548227"></a>文本颜色。</p>
    </td>
    </tr>
    <tr id="row172675411221"><td class="cellrowborder" valign="top" width="14.85%" headers="mcps1.1.6.1.1 "><p id="p272665462210"><a name="p272665462210"></a><a name="p272665462210"></a>fontSize</p>
    </td>
    <td class="cellrowborder" valign="top" width="19.73%" headers="mcps1.1.6.1.2 "><p id="p472612541229"><a name="p472612541229"></a><a name="p472612541229"></a>number | string</p>
    </td>
    <td class="cellrowborder" valign="top" width="6.569999999999999%" headers="mcps1.1.6.1.3 "><p id="p1972614542223"><a name="p1972614542223"></a><a name="p1972614542223"></a>否</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.17%" headers="mcps1.1.6.1.4 "><p id="p172655415226"><a name="p172655415226"></a><a name="p172655415226"></a>10</p>
    </td>
    <td class="cellrowborder" valign="top" width="49.68%" headers="mcps1.1.6.1.5 "><p id="p27269548228"><a name="p27269548228"></a><a name="p27269548228"></a>文本大小。</p>
    </td>
    </tr>
    <tr id="row37261254192219"><td class="cellrowborder" valign="top" width="14.85%" headers="mcps1.1.6.1.1 "><p id="p272655416220"><a name="p272655416220"></a><a name="p272655416220"></a>badgeSize</p>
    </td>
    <td class="cellrowborder" valign="top" width="19.73%" headers="mcps1.1.6.1.2 "><p id="p187270547228"><a name="p187270547228"></a><a name="p187270547228"></a>number | string</p>
    </td>
    <td class="cellrowborder" valign="top" width="6.569999999999999%" headers="mcps1.1.6.1.3 "><p id="p13727145413221"><a name="p13727145413221"></a><a name="p13727145413221"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.17%" headers="mcps1.1.6.1.4 "><p id="p872717545226"><a name="p872717545226"></a><a name="p872717545226"></a>-</p>
    </td>
    <td class="cellrowborder" valign="top" width="49.68%" headers="mcps1.1.6.1.5 "><p id="p1672745411224"><a name="p1672745411224"></a><a name="p1672745411224"></a>badge的大小。</p>
    </td>
    </tr>
    <tr id="row17274546224"><td class="cellrowborder" valign="top" width="14.85%" headers="mcps1.1.6.1.1 "><p id="p18727165452210"><a name="p18727165452210"></a><a name="p18727165452210"></a>badgeColor</p>
    </td>
    <td class="cellrowborder" valign="top" width="19.73%" headers="mcps1.1.6.1.2 "><p id="p672775452217"><a name="p672775452217"></a><a name="p672775452217"></a>Color</p>
    </td>
    <td class="cellrowborder" valign="top" width="6.569999999999999%" headers="mcps1.1.6.1.3 "><p id="p127275543221"><a name="p127275543221"></a><a name="p127275543221"></a>否</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.17%" headers="mcps1.1.6.1.4 "><p id="p1272785417221"><a name="p1272785417221"></a><a name="p1272785417221"></a>Red</p>
    </td>
    <td class="cellrowborder" valign="top" width="49.68%" headers="mcps1.1.6.1.5 "><p id="p13727185419222"><a name="p13727185419222"></a><a name="p13727185419222"></a>badge的颜色。</p>
    </td>
    </tr>
    </tbody>
    </table>


-   <a name="li7315759142415"></a>BadgePosition枚举说明

    <a name="table1648081319234"></a>
    <table><thead align="left"><tr id="row248131319233"><th class="cellrowborder" valign="top" width="25.2%" id="mcps1.1.3.1.1"><p id="p10481131319231"><a name="p10481131319231"></a><a name="p10481131319231"></a>名称</p>
    </th>
    <th class="cellrowborder" valign="top" width="74.8%" id="mcps1.1.3.1.2"><p id="p11481191342319"><a name="p11481191342319"></a><a name="p11481191342319"></a>描述</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row44811513102315"><td class="cellrowborder" valign="top" width="25.2%" headers="mcps1.1.3.1.1 "><p id="p1348191316232"><a name="p1348191316232"></a><a name="p1348191316232"></a>Right</p>
    </td>
    <td class="cellrowborder" valign="top" width="74.8%" headers="mcps1.1.3.1.2 "><p id="p10481111332318"><a name="p10481111332318"></a><a name="p10481111332318"></a>圆点显示在右侧纵向居中。</p>
    </td>
    </tr>
    <tr id="row4481191382316"><td class="cellrowborder" valign="top" width="25.2%" headers="mcps1.1.3.1.1 "><p id="p74811513172312"><a name="p74811513172312"></a><a name="p74811513172312"></a>RightTop</p>
    </td>
    <td class="cellrowborder" valign="top" width="74.8%" headers="mcps1.1.3.1.2 "><p id="p10481111362318"><a name="p10481111362318"></a><a name="p10481111362318"></a>圆点显示在右上角。</p>
    </td>
    </tr>
    <tr id="row2481171372318"><td class="cellrowborder" valign="top" width="25.2%" headers="mcps1.1.3.1.1 "><p id="p948141302319"><a name="p948141302319"></a><a name="p948141302319"></a>Left</p>
    </td>
    <td class="cellrowborder" valign="top" width="74.8%" headers="mcps1.1.3.1.2 "><p id="p44812137238"><a name="p44812137238"></a><a name="p44812137238"></a>圆点显示在左侧纵向居中。</p>
    </td>
    </tr>
    </tbody>
    </table>


## 示例<a name="section187541341164211"></a>

```
@Entry
@Component
struct BadgeExample {
  @State counts: number = 1
  @State message: string = 'new'

  build() {
    Flex({ justifyContent: FlexAlign.SpaceAround }) {
      Badge({
        count: this.counts,
        maxCount: 99,
        style: { color: 0xFFFFFF, fontSize: 16, badgeSize: 20, badgeColor: Color.Red }
      }) {
        Button('message')
          .onClick(() => {
            this.counts++
          })
          .width(100).height(50).backgroundColor(0x317aff)
      }.width(100).height(50)

      Badge({
        value: this.message,
        style: { color: 0xFFFFFF, fontSize: 9, badgeSize: 20, badgeColor: Color.Blue }
      }) {
        Text('message')
          .width(80).height(50).fontSize(16).lineHeight(37)
          .borderRadius(10).textAlign(TextAlign.Center).backgroundColor(0xF3F4ED)
      }.width(80).height(50)

      Badge({
        value: '',
        position: 1,
        style: { badgeSize: 6, badgeColor: Color.Red }
      }) {
        Text('message')
          .width(90).height(50).fontSize(16).lineHeight(37)
          .borderRadius(10).textAlign(TextAlign.Center).backgroundColor(0xF3F4ED)
      }.width(90).height(50)
    }.width('100%').margin({ top: 5 })
  }
}
```

![](figures/badge.gif)

