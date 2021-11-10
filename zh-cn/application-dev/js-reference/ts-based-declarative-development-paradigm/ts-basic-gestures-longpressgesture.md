# LongPressGesture<a name="ZH-CN_TOPIC_0000001113138854"></a>

## 接口<a name="section710011405537"></a>

LongPressGesture\(options?: \{ fingers?: number, repeat?: boolean, duration?: number \}\)

-   参数

    <a name="table1392916196212"></a>
    <table><thead align="left"><tr id="row19306191218"><th class="cellrowborder" valign="top" width="16.11%" id="mcps1.1.6.1.1"><p id="p199307193217"><a name="p199307193217"></a><a name="p199307193217"></a>参数名称</p>
    </th>
    <th class="cellrowborder" valign="top" width="14.180000000000001%" id="mcps1.1.6.1.2"><p id="p119302191128"><a name="p119302191128"></a><a name="p119302191128"></a>参数类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="12.82%" id="mcps1.1.6.1.3"><p id="p7930141911211"><a name="p7930141911211"></a><a name="p7930141911211"></a>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="16.88%" id="mcps1.1.6.1.4"><p id="p1393020194219"><a name="p1393020194219"></a><a name="p1393020194219"></a>默认值</p>
    </th>
    <th class="cellrowborder" valign="top" width="40.01%" id="mcps1.1.6.1.5"><p id="p693061912210"><a name="p693061912210"></a><a name="p693061912210"></a>参数描述</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row1093021911217"><td class="cellrowborder" valign="top" width="16.11%" headers="mcps1.1.6.1.1 "><p id="p119307198218"><a name="p119307198218"></a><a name="p119307198218"></a>fingers</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.180000000000001%" headers="mcps1.1.6.1.2 "><p id="p129301719828"><a name="p129301719828"></a><a name="p129301719828"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="12.82%" headers="mcps1.1.6.1.3 "><p id="p893091913213"><a name="p893091913213"></a><a name="p893091913213"></a>否</p>
    </td>
    <td class="cellrowborder" valign="top" width="16.88%" headers="mcps1.1.6.1.4 "><p id="p421641117507"><a name="p421641117507"></a><a name="p421641117507"></a>1</p>
    </td>
    <td class="cellrowborder" valign="top" width="40.01%" headers="mcps1.1.6.1.5 "><p id="p176763225917"><a name="p176763225917"></a><a name="p176763225917"></a>触发长按的最少手指数，最小为1指， 最大取值为10指。</p>
    </td>
    </tr>
    <tr id="row126591442115811"><td class="cellrowborder" valign="top" width="16.11%" headers="mcps1.1.6.1.1 "><p id="p10659342135818"><a name="p10659342135818"></a><a name="p10659342135818"></a>repeat</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.180000000000001%" headers="mcps1.1.6.1.2 "><p id="p465944219588"><a name="p465944219588"></a><a name="p465944219588"></a>boolean</p>
    </td>
    <td class="cellrowborder" valign="top" width="12.82%" headers="mcps1.1.6.1.3 "><p id="p965920427583"><a name="p965920427583"></a><a name="p965920427583"></a>否</p>
    </td>
    <td class="cellrowborder" valign="top" width="16.88%" headers="mcps1.1.6.1.4 "><p id="p3659104211582"><a name="p3659104211582"></a><a name="p3659104211582"></a>false</p>
    </td>
    <td class="cellrowborder" valign="top" width="40.01%" headers="mcps1.1.6.1.5 "><p id="p156682039155912"><a name="p156682039155912"></a><a name="p156682039155912"></a>是否连续触发事件回调。</p>
    </td>
    </tr>
    <tr id="row6281649195819"><td class="cellrowborder" valign="top" width="16.11%" headers="mcps1.1.6.1.1 "><p id="p1281124917585"><a name="p1281124917585"></a><a name="p1281124917585"></a>duration</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.180000000000001%" headers="mcps1.1.6.1.2 "><p id="p528134912583"><a name="p528134912583"></a><a name="p528134912583"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="12.82%" headers="mcps1.1.6.1.3 "><p id="p028164919585"><a name="p028164919585"></a><a name="p028164919585"></a>否</p>
    </td>
    <td class="cellrowborder" valign="top" width="16.88%" headers="mcps1.1.6.1.4 "><p id="p42811149185811"><a name="p42811149185811"></a><a name="p42811149185811"></a>500</p>
    </td>
    <td class="cellrowborder" valign="top" width="40.01%" headers="mcps1.1.6.1.5 "><p id="p6809144419592"><a name="p6809144419592"></a><a name="p6809144419592"></a>最小触发长按的时间，单位为毫秒（ms）。</p>
    </td>
    </tr>
    </tbody>
    </table>


## 事件<a name="section526892112537"></a>

<a name="table135406579437"></a>
<table><thead align="left"><tr id="row1154015719436"><th class="cellrowborder" colspan="2" valign="top" id="mcps1.1.4.1.1"><p id="p85411457184316"><a name="p85411457184316"></a><a name="p85411457184316"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.1.4.1.2"><p id="p5541457194319"><a name="p5541457194319"></a><a name="p5541457194319"></a>功能描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row4541257114319"><td class="cellrowborder" colspan="2" valign="top" headers="mcps1.1.4.1.1 "><p id="p5541357194313"><a name="p5541357194313"></a><a name="p5541357194313"></a>onAction((event?: <a href="ts-gesture-settings.md#table290mcpsimp">GestureEvent</a>) =&gt; void)</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.1.4.1.2 "><p id="p11541155710434"><a name="p11541155710434"></a><a name="p11541155710434"></a>LongPress手势识别成功回调。</p>
</td>
</tr>
<tr id="row2899841162916"><td class="cellrowborder" colspan="2" valign="top" headers="mcps1.1.4.1.1 "><p id="p15900174162916"><a name="p15900174162916"></a><a name="p15900174162916"></a>onActionEnd((event?: <a href="ts-gesture-settings.md#table290mcpsimp">GestureEvent</a>) =&gt; void)</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.1.4.1.2 "><p id="p69001041172920"><a name="p69001041172920"></a><a name="p69001041172920"></a>LongPress手势识别成功，手指抬起后触发回调。</p>
</td>
</tr>
<tr id="row13598134672914"><td class="cellrowborder" colspan="2" valign="top" headers="mcps1.1.4.1.1 "><p id="p85999460299"><a name="p85999460299"></a><a name="p85999460299"></a>onActionCancel(event: () =&gt; void)</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.1.4.1.2 "><p id="p1459954652916"><a name="p1459954652916"></a><a name="p1459954652916"></a>LongPress手势识别成功，接收到触摸取消事件触发回调。</p>
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
        .onAction((event: GestureEvent) => {
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

