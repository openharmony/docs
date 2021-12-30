# LongPressGesture<a name="ZH-CN_TOPIC_0000001237555117"></a>

>![](../../public_sys-resources/icon-note.gif) **说明：** 
>从API Version 7开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。

## 权限列表<a name="section781125411508"></a>

无

## 接口<a name="section710011405537"></a>

LongPressGesture\(options?: \{ fingers?: number, repeat?: boolean, duration?: number \}\)

-   参数

    <table><thead align="left"><tr><th class="cellrowborder" valign="top" width="16.11%" id="mcps1.1.6.1.1"><p>参数名称</p>
    </th>
    <th class="cellrowborder" valign="top" width="14.180000000000001%" id="mcps1.1.6.1.2"><p>参数类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="12.82%" id="mcps1.1.6.1.3"><p>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="16.88%" id="mcps1.1.6.1.4"><p>默认值</p>
    </th>
    <th class="cellrowborder" valign="top" width="40.01%" id="mcps1.1.6.1.5"><p>参数描述</p>
    </th>
    </tr>
    </thead>
    <tbody><tr><td class="cellrowborder" valign="top" width="16.11%" headers="mcps1.1.6.1.1 "><p>fingers</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.180000000000001%" headers="mcps1.1.6.1.2 "><p>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="12.82%" headers="mcps1.1.6.1.3 "><p>否</p>
    </td>
    <td class="cellrowborder" valign="top" width="16.88%" headers="mcps1.1.6.1.4 "><p>1</p>
    </td>
    <td class="cellrowborder" valign="top" width="40.01%" headers="mcps1.1.6.1.5 "><p>触发长按的最少手指数，最小为1指， 最大取值为10指。</p>
    </td>
    </tr>
    <tr><td class="cellrowborder" valign="top" width="16.11%" headers="mcps1.1.6.1.1 "><p>repeat</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.180000000000001%" headers="mcps1.1.6.1.2 "><p>boolean</p>
    </td>
    <td class="cellrowborder" valign="top" width="12.82%" headers="mcps1.1.6.1.3 "><p>否</p>
    </td>
    <td class="cellrowborder" valign="top" width="16.88%" headers="mcps1.1.6.1.4 "><p>false</p>
    </td>
    <td class="cellrowborder" valign="top" width="40.01%" headers="mcps1.1.6.1.5 "><p>是否连续触发事件回调。</p>
    </td>
    </tr>
    <tr><td class="cellrowborder" valign="top" width="16.11%" headers="mcps1.1.6.1.1 "><p>duration</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.180000000000001%" headers="mcps1.1.6.1.2 "><p>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="12.82%" headers="mcps1.1.6.1.3 "><p>否</p>
    </td>
    <td class="cellrowborder" valign="top" width="16.88%" headers="mcps1.1.6.1.4 "><p>500</p>
    </td>
    <td class="cellrowborder" valign="top" width="40.01%" headers="mcps1.1.6.1.5 "><p>最小触发长按的时间，单位为毫秒（ms）。</p>
    </td>
    </tr>
    </tbody>
    </table>


## 事件<a name="section526892112537"></a>

<table><thead align="left"><tr><th class="cellrowborder" colspan="2" valign="top" id="mcps1.1.4.1.1"><p>名称</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.1.4.1.2"><p>功能描述</p>
</th>
</tr>
</thead>
<tbody><tr><td class="cellrowborder" colspan="2" valign="top" headers="mcps1.1.4.1.1 "><p>onAction((event?: <a href="#li21621335144710">LongPressGestureEvent</a>) =&gt; void)</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.1.4.1.2 "><p>LongPress手势识别成功回调。</p>
</td>
</tr>
<tr><td class="cellrowborder" colspan="2" valign="top" headers="mcps1.1.4.1.1 "><p>onActionEnd((event?: <a href="#li21621335144710">LongPressGestureEvent</a>) =&gt; void)</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.1.4.1.2 "><p>LongPress手势识别成功，手指抬起后触发回调。</p>
</td>
</tr>
<tr><td class="cellrowborder" colspan="2" valign="top" headers="mcps1.1.4.1.1 "><p>onActionCancel(event: () =&gt; void)</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.1.4.1.2 "><p>LongPress手势识别成功，接收到触摸取消事件触发回调。</p>
</td>
</tr>
</tbody>
</table>

-   <a name="li21621335144710"></a>LongPressGestureEvent类型说明<sup>8+</sup>

    继承自[GestureEvent](ts-gesture-settings.md#table290mcpsimp)类型。

    <table><thead align="left"><tr><th class="cellrowborder" valign="top" width="20.09%" id="mcps1.1.4.1.1"><p>属性名称</p>
    </th>
    <th class="cellrowborder" valign="top" width="18.41%" id="mcps1.1.4.1.2"><p>属性类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="61.5%" id="mcps1.1.4.1.3"><p>描述</p>
    </th>
    </tr>
    </thead>
    <tbody><tr><td class="cellrowborder" valign="top" width="20.09%" headers="mcps1.1.4.1.1 "><p>repeat</p>
    </td>
    <td class="cellrowborder" valign="top" width="18.41%" headers="mcps1.1.4.1.2 "><p>boolean</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.5%" headers="mcps1.1.4.1.3 "><p>事件是否为重复触发事件。</p>
    </td>
    </tr>
    </tbody>
    </table>


## 示例<a name="section16900453182718"></a>

```
@Entry
@Component
struct LongPressGestureExample {
  @State count: number = 0

  build() {
    Flex({ direction: FlexDirection.Column, alignItems: ItemAlign.Center, justifyContent: FlexAlign.SpaceBetween }) {
      Text('LongPress onAction:' + this.count)
    }
    .height(200).width(300).padding(60).border({ width:1 }).margin(30)
    .gesture(
      LongPressGesture({ repeat: true })
        //长按动作存在会连续触发
        .onAction((event: LongPressGestureEvent) => {
          if (event.repeat) { this.count++ }
        })
        //长按动作一结束触发
        .onActionEnd(() => {
          this.count = 0
        })
    )
  }
}
```

![](figures/LongPressGesture.gif)

