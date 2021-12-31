# Badge<a name="ZH-CN_TOPIC_0000001237715075"></a>

>![](../../public_sys-resources/icon-note.gif) **说明：** 
>该组件从API Version 7开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。

新事件标记组件，在组件上提供事件信息展示能力。

## 权限列表<a name="section53281531154915"></a>

无

## 子组件<a name="section1089034711356"></a>

支持单个子组件。

## 接口<a name="section17399164519412"></a>

Badge\(value: \{count: number, position?: BadgePosition, maxCount?: number, style?: BadgeStyle\}\)

-   参数

    <table><thead align="left"><tr><th class="cellrowborder" valign="top" width="16.11%" id="mcps1.1.6.1.1"><p>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="18.95%" id="mcps1.1.6.1.2"><p>参数类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="9.55%" id="mcps1.1.6.1.3"><p>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="13.18%" id="mcps1.1.6.1.4"><p>默认值</p>
    </th>
    <th class="cellrowborder" valign="top" width="42.21%" id="mcps1.1.6.1.5"><p>参数描述</p>
    </th>
    </tr>
    </thead>
    <tbody><tr><td class="cellrowborder" valign="top" width="16.11%" headers="mcps1.1.6.1.1 "><p>count</p>
    </td>
    <td class="cellrowborder" valign="top" width="18.95%" headers="mcps1.1.6.1.2 "><p>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.55%" headers="mcps1.1.6.1.3 "><p>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="13.18%" headers="mcps1.1.6.1.4 "><p>-</p>
    </td>
    <td class="cellrowborder" valign="top" width="42.21%" headers="mcps1.1.6.1.5 "><p>设置提醒消息数。</p>
    </td>
    </tr>
    <tr><td class="cellrowborder" valign="top" width="16.11%" headers="mcps1.1.6.1.1 "><p>position</p>
    </td>
    <td class="cellrowborder" valign="top" width="18.95%" headers="mcps1.1.6.1.2 "><p><a href="#li7315759142415">BadgePosition</a></p>
    </td>
    <td class="cellrowborder" valign="top" width="9.55%" headers="mcps1.1.6.1.3 "><p>否</p>
    </td>
    <td class="cellrowborder" valign="top" width="13.18%" headers="mcps1.1.6.1.4 "><p>RightTop</p>
    </td>
    <td class="cellrowborder" valign="top" width="42.21%" headers="mcps1.1.6.1.5 "><p>设置提示点显示位置。</p>
    </td>
    </tr>
    <tr><td class="cellrowborder" valign="top" width="16.11%" headers="mcps1.1.6.1.1 "><p>maxCount</p>
    </td>
    <td class="cellrowborder" valign="top" width="18.95%" headers="mcps1.1.6.1.2 "><p>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.55%" headers="mcps1.1.6.1.3 "><p>否</p>
    </td>
    <td class="cellrowborder" valign="top" width="13.18%" headers="mcps1.1.6.1.4 "><p>99</p>
    </td>
    <td class="cellrowborder" valign="top" width="42.21%" headers="mcps1.1.6.1.5 "><p>最大消息数，超过最大消息时仅显示maxCount+。</p>
    </td>
    </tr>
    <tr><td class="cellrowborder" valign="top" width="16.11%" headers="mcps1.1.6.1.1 "><p>style</p>
    </td>
    <td class="cellrowborder" valign="top" width="18.95%" headers="mcps1.1.6.1.2 "><p><a href="#li910545532420">BadgeStyle</a></p>
    </td>
    <td class="cellrowborder" valign="top" width="9.55%" headers="mcps1.1.6.1.3 "><p>否</p>
    </td>
    <td class="cellrowborder" valign="top" width="13.18%" headers="mcps1.1.6.1.4 "><p>-</p>
    </td>
    <td class="cellrowborder" valign="top" width="42.21%" headers="mcps1.1.6.1.5 "><p>Badge组件可设置样式，支持设置文本颜色、尺寸、圆点颜色和尺寸。</p>
    </td>
    </tr>
    </tbody>
    </table>


Badge\(value: \{value: string, position?: BadgePosition, style?: BadgeStyle\}\)

根据字符串创建提醒组件。

-   参数

    <table><thead align="left"><tr><th class="cellrowborder" valign="top" width="16.11%" id="mcps1.1.6.1.1"><p>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="17.71%" id="mcps1.1.6.1.2"><p>参数类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="10.79%" id="mcps1.1.6.1.3"><p>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="13.18%" id="mcps1.1.6.1.4"><p>默认值</p>
    </th>
    <th class="cellrowborder" valign="top" width="42.21%" id="mcps1.1.6.1.5"><p>参数描述</p>
    </th>
    </tr>
    </thead>
    <tbody><tr><td class="cellrowborder" valign="top" width="16.11%" headers="mcps1.1.6.1.1 "><p>value</p>
    </td>
    <td class="cellrowborder" valign="top" width="17.71%" headers="mcps1.1.6.1.2 "><p>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="10.79%" headers="mcps1.1.6.1.3 "><p>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="13.18%" headers="mcps1.1.6.1.4 "><p>-</p>
    </td>
    <td class="cellrowborder" valign="top" width="42.21%" headers="mcps1.1.6.1.5 "><p>提示内容的文本字符串。</p>
    </td>
    </tr>
    <tr><td class="cellrowborder" valign="top" width="16.11%" headers="mcps1.1.6.1.1 "><p>position</p>
    </td>
    <td class="cellrowborder" valign="top" width="17.71%" headers="mcps1.1.6.1.2 "><p><a href="#li7315759142415">BadgePosition</a></p>
    </td>
    <td class="cellrowborder" valign="top" width="10.79%" headers="mcps1.1.6.1.3 "><p>否</p>
    </td>
    <td class="cellrowborder" valign="top" width="13.18%" headers="mcps1.1.6.1.4 "><p>RightTop</p>
    </td>
    <td class="cellrowborder" valign="top" width="42.21%" headers="mcps1.1.6.1.5 "><p>设置提示点显示位置。</p>
    </td>
    </tr>
    <tr><td class="cellrowborder" valign="top" width="16.11%" headers="mcps1.1.6.1.1 "><p>style</p>
    </td>
    <td class="cellrowborder" valign="top" width="17.71%" headers="mcps1.1.6.1.2 "><p><a href="#li910545532420">BadgeStyle</a></p>
    </td>
    <td class="cellrowborder" valign="top" width="10.79%" headers="mcps1.1.6.1.3 "><p>否</p>
    </td>
    <td class="cellrowborder" valign="top" width="13.18%" headers="mcps1.1.6.1.4 "><p>-</p>
    </td>
    <td class="cellrowborder" valign="top" width="42.21%" headers="mcps1.1.6.1.5 "><p>Badge组件可设置样式，支持设置文本颜色、尺寸、圆点颜色和尺寸。</p>
    </td>
    </tr>
    </tbody>
    </table>


-   <a name="li910545532420"></a>BadgeStyle对象说明

    <table><thead align="left"><tr><th class="cellrowborder" valign="top" width="14.85%" id="mcps1.1.6.1.1"><p>名称</p>
    </th>
    <th class="cellrowborder" valign="top" width="19.73%" id="mcps1.1.6.1.2"><p>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="6.569999999999999%" id="mcps1.1.6.1.3"><p>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="9.17%" id="mcps1.1.6.1.4"><p>默认值</p>
    </th>
    <th class="cellrowborder" valign="top" width="49.68%" id="mcps1.1.6.1.5"><p>描述</p>
    </th>
    </tr>
    </thead>
    <tbody><tr><td class="cellrowborder" valign="top" width="14.85%" headers="mcps1.1.6.1.1 "><p>color</p>
    </td>
    <td class="cellrowborder" valign="top" width="19.73%" headers="mcps1.1.6.1.2 "><p>Color</p>
    </td>
    <td class="cellrowborder" valign="top" width="6.569999999999999%" headers="mcps1.1.6.1.3 "><p>否</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.17%" headers="mcps1.1.6.1.4 "><p>White</p>
    </td>
    <td class="cellrowborder" valign="top" width="49.68%" headers="mcps1.1.6.1.5 "><p>文本颜色。</p>
    </td>
    </tr>
    <tr><td class="cellrowborder" valign="top" width="14.85%" headers="mcps1.1.6.1.1 "><p>fontSize</p>
    </td>
    <td class="cellrowborder" valign="top" width="19.73%" headers="mcps1.1.6.1.2 "><p>number | string</p>
    </td>
    <td class="cellrowborder" valign="top" width="6.569999999999999%" headers="mcps1.1.6.1.3 "><p>否</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.17%" headers="mcps1.1.6.1.4 "><p>10</p>
    </td>
    <td class="cellrowborder" valign="top" width="49.68%" headers="mcps1.1.6.1.5 "><p>文本大小。</p>
    </td>
    </tr>
    <tr><td class="cellrowborder" valign="top" width="14.85%" headers="mcps1.1.6.1.1 "><p>badgeSize</p>
    </td>
    <td class="cellrowborder" valign="top" width="19.73%" headers="mcps1.1.6.1.2 "><p>number | string</p>
    </td>
    <td class="cellrowborder" valign="top" width="6.569999999999999%" headers="mcps1.1.6.1.3 "><p>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.17%" headers="mcps1.1.6.1.4 "><p>-</p>
    </td>
    <td class="cellrowborder" valign="top" width="49.68%" headers="mcps1.1.6.1.5 "><p>badge的大小。</p>
    </td>
    </tr>
    <tr><td class="cellrowborder" valign="top" width="14.85%" headers="mcps1.1.6.1.1 "><p>badgeColor</p>
    </td>
    <td class="cellrowborder" valign="top" width="19.73%" headers="mcps1.1.6.1.2 "><p>Color</p>
    </td>
    <td class="cellrowborder" valign="top" width="6.569999999999999%" headers="mcps1.1.6.1.3 "><p>否</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.17%" headers="mcps1.1.6.1.4 "><p>Red</p>
    </td>
    <td class="cellrowborder" valign="top" width="49.68%" headers="mcps1.1.6.1.5 "><p>badge的颜色。</p>
    </td>
    </tr>
    </tbody>
    </table>


-   <a name="li7315759142415"></a>BadgePosition枚举说明

    <table><thead align="left"><tr><th class="cellrowborder" valign="top" width="25.2%" id="mcps1.1.3.1.1"><p>名称</p>
    </th>
    <th class="cellrowborder" valign="top" width="74.8%" id="mcps1.1.3.1.2"><p>描述</p>
    </th>
    </tr>
    </thead>
    <tbody><tr><td class="cellrowborder" valign="top" width="25.2%" headers="mcps1.1.3.1.1 "><p>Right</p>
    </td>
    <td class="cellrowborder" valign="top" width="74.8%" headers="mcps1.1.3.1.2 "><p>圆点显示在右侧纵向居中。</p>
    </td>
    </tr>
    <tr><td class="cellrowborder" valign="top" width="25.2%" headers="mcps1.1.3.1.1 "><p>RightTop</p>
    </td>
    <td class="cellrowborder" valign="top" width="74.8%" headers="mcps1.1.3.1.2 "><p>圆点显示在右上角。</p>
    </td>
    </tr>
    <tr><td class="cellrowborder" valign="top" width="25.2%" headers="mcps1.1.3.1.1 "><p>Left</p>
    </td>
    <td class="cellrowborder" valign="top" width="74.8%" headers="mcps1.1.3.1.2 "><p>圆点显示在左侧纵向居中。</p>
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

