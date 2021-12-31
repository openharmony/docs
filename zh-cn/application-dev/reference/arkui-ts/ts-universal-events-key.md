# 按键事件<a name="ZH-CN_TOPIC_0000001192915122"></a>

>![](../../public_sys-resources/icon-note.gif) **说明：** 
>从API Version 7开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。

## 权限列表<a name="section781125411508"></a>

无

## 事件<a name="section2158223135910"></a>

<table><thead align="left"><tr><th class="cellrowborder" colspan="2" valign="top" id="mcps1.1.5.1.1"><p>名称</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.1.5.1.2"><p>支持冒泡</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.1.5.1.3"><p>功能描述</p>
</th>
</tr>
</thead>
<tbody><tr><td class="cellrowborder" colspan="2" valign="top" headers="mcps1.1.5.1.1 "><p>onKeyEvent(event: (event?: KeyEvent) =&gt; void)</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.1.5.1.2 "><p>是</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.1.5.1.3 "><p>按键动作触发该方法调用，event参数见<a href="#section3668926124018">KeyEvent</a>介绍。</p>
</td>
</tr>
</tbody>
</table>

## KeyEvent对象说明<a name="section3668926124018"></a>

-   属性

    <table><thead align="left"><tr><th class="cellrowborder" valign="top" width="33.29332933293329%" id="mcps1.1.4.1.1"><p>属性名称</p>
    </th>
    <th class="cellrowborder" valign="top" width="21.26212621262126%" id="mcps1.1.4.1.2"><p>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="45.44454445444545%" id="mcps1.1.4.1.3"><p>描述</p>
    </th>
    </tr>
    </thead>
    <tbody><tr><td class="cellrowborder" valign="top" width="33.29332933293329%" headers="mcps1.1.4.1.1 "><p>type</p>
    </td>
    <td class="cellrowborder" valign="top" width="21.26212621262126%" headers="mcps1.1.4.1.2 "><p><a href="#li15552046124817">KeyType</a></p>
    </td>
    <td class="cellrowborder" valign="top" width="45.44454445444545%" headers="mcps1.1.4.1.3 "><p>按键的类型。</p>
    </td>
    </tr>
    <tr><td class="cellrowborder" valign="top" width="33.29332933293329%" headers="mcps1.1.4.1.1 "><p>keyCode</p>
    </td>
    <td class="cellrowborder" valign="top" width="21.26212621262126%" headers="mcps1.1.4.1.2 "><p>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="45.44454445444545%" headers="mcps1.1.4.1.3 "><p>按键的键码。</p>
    </td>
    </tr>
    <tr><td class="cellrowborder" valign="top" width="33.29332933293329%" headers="mcps1.1.4.1.1 "><p>keyText</p>
    </td>
    <td class="cellrowborder" valign="top" width="21.26212621262126%" headers="mcps1.1.4.1.2 "><p>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="45.44454445444545%" headers="mcps1.1.4.1.3 "><p>按键的键值。</p>
    </td>
    </tr>
    <tr><td class="cellrowborder" valign="top" width="33.29332933293329%" headers="mcps1.1.4.1.1 "><p>keySource</p>
    </td>
    <td class="cellrowborder" valign="top" width="21.26212621262126%" headers="mcps1.1.4.1.2 "><p><a href="#li19778175915485">KeySource</a></p>
    </td>
    <td class="cellrowborder" valign="top" width="45.44454445444545%" headers="mcps1.1.4.1.3 "><p>触发当前按键的输入设备类型。</p>
    </td>
    </tr>
    <tr><td class="cellrowborder" valign="top" width="33.29332933293329%" headers="mcps1.1.4.1.1 "><p>deviceId</p>
    </td>
    <td class="cellrowborder" valign="top" width="21.26212621262126%" headers="mcps1.1.4.1.2 "><p>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="45.44454445444545%" headers="mcps1.1.4.1.3 "><p>触发当前按键的输入设备ID。</p>
    </td>
    </tr>
    <tr><td class="cellrowborder" valign="top" width="33.29332933293329%" headers="mcps1.1.4.1.1 "><p>metaKey</p>
    </td>
    <td class="cellrowborder" valign="top" width="21.26212621262126%" headers="mcps1.1.4.1.2 "><p>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="45.44454445444545%" headers="mcps1.1.4.1.3 "><p>按键发生时元键的状态，1表示按压态，0表示未按压态。</p>
    </td>
    </tr>
    <tr><td class="cellrowborder" valign="top" width="33.29332933293329%" headers="mcps1.1.4.1.1 "><p>timestamp</p>
    </td>
    <td class="cellrowborder" valign="top" width="21.26212621262126%" headers="mcps1.1.4.1.2 "><p>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="45.44454445444545%" headers="mcps1.1.4.1.3 "><p>按键发生时的时间戳。</p>
    </td>
    </tr>
    </tbody>
    </table>


-   接口

    <table><thead align="left"><tr><th class="cellrowborder" valign="top" width="42.68%" id="mcps1.1.3.1.1"><p>接口名称</p>
    </th>
    <th class="cellrowborder" valign="top" width="57.32000000000001%" id="mcps1.1.3.1.2"><p>功能描述</p>
    </th>
    </tr>
    </thead>
    <tbody><tr><td class="cellrowborder" valign="top" width="42.68%" headers="mcps1.1.3.1.1 "><p>stopPropagation(): void</p>
    </td>
    <td class="cellrowborder" valign="top" width="57.32000000000001%" headers="mcps1.1.3.1.2 "><p>阻塞事件冒泡传递。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   <a name="li15552046124817"></a>KeyType枚举说明

    <table><thead align="left"><tr><th class="cellrowborder" valign="top" width="25.2%" id="mcps1.1.3.1.1"><p>名称</p>
    </th>
    <th class="cellrowborder" valign="top" width="74.8%" id="mcps1.1.3.1.2"><p>描述</p>
    </th>
    </tr>
    </thead>
    <tbody><tr><td class="cellrowborder" valign="top" width="25.2%" headers="mcps1.1.3.1.1 "><p>Down</p>
    </td>
    <td class="cellrowborder" valign="top" width="74.8%" headers="mcps1.1.3.1.2 "><p>按键按下。</p>
    </td>
    </tr>
    <tr><td class="cellrowborder" valign="top" width="25.2%" headers="mcps1.1.3.1.1 "><p>Up</p>
    </td>
    <td class="cellrowborder" valign="top" width="74.8%" headers="mcps1.1.3.1.2 "><p>按键松开。</p>
    </td>
    </tr>
    </tbody>
    </table>


-   <a name="li19778175915485"></a>KeySource枚举说明

    <table><thead align="left"><tr><th class="cellrowborder" valign="top" width="25.2%" id="mcps1.1.3.1.1"><p>名称</p>
    </th>
    <th class="cellrowborder" valign="top" width="74.8%" id="mcps1.1.3.1.2"><p>描述</p>
    </th>
    </tr>
    </thead>
    <tbody><tr><td class="cellrowborder" valign="top" width="25.2%" headers="mcps1.1.3.1.1 "><p>Unknown</p>
    </td>
    <td class="cellrowborder" valign="top" width="74.8%" headers="mcps1.1.3.1.2 "><p>输入设备类型未知。</p>
    </td>
    </tr>
    <tr><td class="cellrowborder" valign="top" width="25.2%" headers="mcps1.1.3.1.1 "><p>Keyboard</p>
    </td>
    <td class="cellrowborder" valign="top" width="74.8%" headers="mcps1.1.3.1.2 "><p>输入设备类型为键盘。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   常用KeyCode说明

    <table><thead align="left"><tr><th class="cellrowborder" valign="top" width="17%" id="mcps1.1.4.1.1"><p>数值</p>
    </th>
    <th class="cellrowborder" valign="top" width="20%" id="mcps1.1.4.1.2"><p>行为</p>
    </th>
    <th class="cellrowborder" valign="top" width="63%" id="mcps1.1.4.1.3"><p>物理按键</p>
    </th>
    </tr>
    </thead>
    <tbody><tr><td class="cellrowborder" valign="top" width="17%" headers="mcps1.1.4.1.1 "><p>19</p>
    </td>
    <td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.4.1.2 "><p>上</p>
    </td>
    <td class="cellrowborder" valign="top" width="63%" headers="mcps1.1.4.1.3 "><p>向上方向键。</p>
    </td>
    </tr>
    <tr><td class="cellrowborder" valign="top" width="17%" headers="mcps1.1.4.1.1 "><p>20</p>
    </td>
    <td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.4.1.2 "><p>下</p>
    </td>
    <td class="cellrowborder" valign="top" width="63%" headers="mcps1.1.4.1.3 "><p>向下方向键。</p>
    </td>
    </tr>
    <tr><td class="cellrowborder" valign="top" width="17%" headers="mcps1.1.4.1.1 "><p>21</p>
    </td>
    <td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.4.1.2 "><p>左</p>
    </td>
    <td class="cellrowborder" valign="top" width="63%" headers="mcps1.1.4.1.3 "><p>向左方向键。</p>
    </td>
    </tr>
    <tr><td class="cellrowborder" valign="top" width="17%" headers="mcps1.1.4.1.1 "><p>22</p>
    </td>
    <td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.4.1.2 "><p>右</p>
    </td>
    <td class="cellrowborder" valign="top" width="63%" headers="mcps1.1.4.1.3 "><p>向右方向键。</p>
    </td>
    </tr>
    <tr><td class="cellrowborder" valign="top" width="17%" headers="mcps1.1.4.1.1 "><p>23</p>
    </td>
    <td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.4.1.2 "><p>确定</p>
    </td>
    <td class="cellrowborder" valign="top" width="63%" headers="mcps1.1.4.1.3 "><p>遥控器的确认键。</p>
    </td>
    </tr>
    <tr><td class="cellrowborder" valign="top" width="17%" headers="mcps1.1.4.1.1 "><p>66</p>
    </td>
    <td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.4.1.2 "><p>确定</p>
    </td>
    <td class="cellrowborder" valign="top" width="63%" headers="mcps1.1.4.1.3 "><p>键盘的回车键。</p>
    </td>
    </tr>
    <tr><td class="cellrowborder" valign="top" width="17%" headers="mcps1.1.4.1.1 "><p>160</p>
    </td>
    <td class="cellrowborder" valign="top" width="20%" headers="mcps1.1.4.1.2 "><p>确定</p>
    </td>
    <td class="cellrowborder" valign="top" width="63%" headers="mcps1.1.4.1.3 "><p>键盘的小键盘回车键。</p>
    </td>
    </tr>
    </tbody>
    </table>


## 示例<a name="section520994913452"></a>

```
@Entry
@Component
struct KeyEventExample {
  @State text: string = ''
  @State eventType: string = ''

  build() {
    Column() {
      Button('KeyEvent').backgroundColor(0x2788D9)
        .onKeyEvent((event: KeyEvent) => {
          if (event.type === KeyType.Down) {
            this.eventType = 'Down'
          }
          if (event.type === KeyType.Up) {
            this.eventType = 'Up'
          }
          console.info(this.text = 'KeyType:' + this.eventType + '\nkeyCode:' + event.keyCode + '\nkeyText:' + event.keyText)
        })
      Text(this.text).padding(15)
    }.height(300).width('100%').padding(35)
  }
}
```

![](figures/KeyEvent.gif)

