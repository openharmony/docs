# LongPressGesture<a name="EN-US_TOPIC_0000001237555117"></a>

>![](../../public_sys-resources/icon-note.gif) **NOTE:** 
>This gesture is supported since API version 7. Updates will be marked with a superscript to indicate their earliest API version.

## Required Permissions<a name="section781125411508"></a>

None

## APIs<a name="section710011405537"></a>

LongPressGesture\(options?: \{ fingers?: number, repeat?: boolean, duration?: number \}\)

-   Parameters

    <a name="table1392916196212"></a>
    <table><thead align="left"><tr id="row19306191218"><th class="cellrowborder" valign="top" width="16.11%" id="mcps1.1.6.1.1"><p id="p199307193217"><a name="p199307193217"></a><a name="p199307193217"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="14.180000000000001%" id="mcps1.1.6.1.2"><p id="p119302191128"><a name="p119302191128"></a><a name="p119302191128"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="12.82%" id="mcps1.1.6.1.3"><p id="p7930141911211"><a name="p7930141911211"></a><a name="p7930141911211"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="16.88%" id="mcps1.1.6.1.4"><p id="p1393020194219"><a name="p1393020194219"></a><a name="p1393020194219"></a>Default Value</p>
    </th>
    <th class="cellrowborder" valign="top" width="40.01%" id="mcps1.1.6.1.5"><p id="p693061912210"><a name="p693061912210"></a><a name="p693061912210"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row1093021911217"><td class="cellrowborder" valign="top" width="16.11%" headers="mcps1.1.6.1.1 "><p id="p119307198218"><a name="p119307198218"></a><a name="p119307198218"></a>fingers</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.180000000000001%" headers="mcps1.1.6.1.2 "><p id="p129301719828"><a name="p129301719828"></a><a name="p129301719828"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="12.82%" headers="mcps1.1.6.1.3 "><p id="p893091913213"><a name="p893091913213"></a><a name="p893091913213"></a>No</p>
    </td>
    <td class="cellrowborder" valign="top" width="16.88%" headers="mcps1.1.6.1.4 "><p id="p421641117507"><a name="p421641117507"></a><a name="p421641117507"></a>1</p>
    </td>
    <td class="cellrowborder" valign="top" width="40.01%" headers="mcps1.1.6.1.5 "><p id="p176763225917"><a name="p176763225917"></a><a name="p176763225917"></a>Minimum number of fingers to trigger a long press gesture. The value ranges from 1 to 10.</p>
    </td>
    </tr>
    <tr id="row126591442115811"><td class="cellrowborder" valign="top" width="16.11%" headers="mcps1.1.6.1.1 "><p id="p10659342135818"><a name="p10659342135818"></a><a name="p10659342135818"></a>repeat</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.180000000000001%" headers="mcps1.1.6.1.2 "><p id="p465944219588"><a name="p465944219588"></a><a name="p465944219588"></a>boolean</p>
    </td>
    <td class="cellrowborder" valign="top" width="12.82%" headers="mcps1.1.6.1.3 "><p id="p965920427583"><a name="p965920427583"></a><a name="p965920427583"></a>No</p>
    </td>
    <td class="cellrowborder" valign="top" width="16.88%" headers="mcps1.1.6.1.4 "><p id="p3659104211582"><a name="p3659104211582"></a><a name="p3659104211582"></a>false</p>
    </td>
    <td class="cellrowborder" valign="top" width="40.01%" headers="mcps1.1.6.1.5 "><p id="p156682039155912"><a name="p156682039155912"></a><a name="p156682039155912"></a>Whether to continuously trigger the event callback.</p>
    </td>
    </tr>
    <tr id="row6281649195819"><td class="cellrowborder" valign="top" width="16.11%" headers="mcps1.1.6.1.1 "><p id="p1281124917585"><a name="p1281124917585"></a><a name="p1281124917585"></a>duration</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.180000000000001%" headers="mcps1.1.6.1.2 "><p id="p528134912583"><a name="p528134912583"></a><a name="p528134912583"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="12.82%" headers="mcps1.1.6.1.3 "><p id="p028164919585"><a name="p028164919585"></a><a name="p028164919585"></a>No</p>
    </td>
    <td class="cellrowborder" valign="top" width="16.88%" headers="mcps1.1.6.1.4 "><p id="p42811149185811"><a name="p42811149185811"></a><a name="p42811149185811"></a>500</p>
    </td>
    <td class="cellrowborder" valign="top" width="40.01%" headers="mcps1.1.6.1.5 "><p id="p6809144419592"><a name="p6809144419592"></a><a name="p6809144419592"></a>Minimum hold-down time, in ms.</p>
    </td>
    </tr>
    </tbody>
    </table>


## Events<a name="section526892112537"></a>

<a name="table135406579437"></a>
<table><thead align="left"><tr id="row1154015719436"><th class="cellrowborder" colspan="2" valign="top" id="mcps1.1.4.1.1"><p id="p85411457184316"><a name="p85411457184316"></a><a name="p85411457184316"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.1.4.1.2"><p id="p5541457194319"><a name="p5541457194319"></a><a name="p5541457194319"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row4541257114319"><td class="cellrowborder" colspan="2" valign="top" headers="mcps1.1.4.1.1 "><p id="p5541357194313"><a name="p5541357194313"></a><a name="p5541357194313"></a>onAction((event?: <a href="#li21621335144710">LongPressGestureEvent</a>) =&gt; void)</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.1.4.1.2 "><p id="p11541155710434"><a name="p11541155710434"></a><a name="p11541155710434"></a>Callback invoked when a long press gesture is recognized.</p>
</td>
</tr>
<tr id="row2899841162916"><td class="cellrowborder" colspan="2" valign="top" headers="mcps1.1.4.1.1 "><p id="p15900174162916"><a name="p15900174162916"></a><a name="p15900174162916"></a>onActionEnd((event?: <a href="#li21621335144710">LongPressGestureEvent</a>) =&gt; void)</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.1.4.1.2 "><p id="p69001041172920"><a name="p69001041172920"></a><a name="p69001041172920"></a>Callback invoked when the finger used for a long press gesture is lift.</p>
</td>
</tr>
<tr id="row13598134672914"><td class="cellrowborder" colspan="2" valign="top" headers="mcps1.1.4.1.1 "><p id="p85999460299"><a name="p85999460299"></a><a name="p85999460299"></a>onActionCancel(event: () =&gt; void)</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.1.4.1.2 "><p id="p1459954652916"><a name="p1459954652916"></a><a name="p1459954652916"></a>Callback invoked when a tap cancellation event is received after a long press gesture is recognized.</p>
</td>
</tr>
</tbody>
</table>

-   <a name="li21621335144710"></a>LongPressGestureEvent attributes<sup>8+</sup>

    Inherited from  [GestureEvent](ts-gesture-settings.md#table290mcpsimp).

    <a name="table290mcpsimp"></a>
    <table><thead align="left"><tr id="row296mcpsimp"><th class="cellrowborder" valign="top" width="20.09%" id="mcps1.1.4.1.1"><p id="p298mcpsimp"><a name="p298mcpsimp"></a><a name="p298mcpsimp"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="18.41%" id="mcps1.1.4.1.2"><p id="p300mcpsimp"><a name="p300mcpsimp"></a><a name="p300mcpsimp"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="61.5%" id="mcps1.1.4.1.3"><p id="p302mcpsimp"><a name="p302mcpsimp"></a><a name="p302mcpsimp"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row303mcpsimp"><td class="cellrowborder" valign="top" width="20.09%" headers="mcps1.1.4.1.1 "><p id="p305mcpsimp"><a name="p305mcpsimp"></a><a name="p305mcpsimp"></a>repeat</p>
    </td>
    <td class="cellrowborder" valign="top" width="18.41%" headers="mcps1.1.4.1.2 "><p id="p307mcpsimp"><a name="p307mcpsimp"></a><a name="p307mcpsimp"></a>boolean</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.5%" headers="mcps1.1.4.1.3 "><p id="p309mcpsimp"><a name="p309mcpsimp"></a><a name="p309mcpsimp"></a>Whether the event is repeated.</p>
    </td>
    </tr>
    </tbody>
    </table>


## Example<a name="section16900453182718"></a>

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
        // Repeatedly triggered when the long press gesture exists.
        .onAction((event: LongPressGestureEvent) => {
          if (event.repeat) { this.count++ }
        })
        // Triggered when the long press gesture ends.
        .onActionEnd(() => {
          this.count = 0
        })
    )
  }
}
```

![](figures/longpressgesture.gif)

