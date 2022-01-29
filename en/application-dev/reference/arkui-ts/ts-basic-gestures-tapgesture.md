# TapGesture<a name="EN-US_TOPIC_0000001237475081"></a>

>![](../../public_sys-resources/icon-note.gif) **NOTE:** 
>This gesture is supported since API version 7. Updates will be marked with a superscript to indicate their earliest API version.

## Required Permissions<a name="section781125411508"></a>

None

## APIs<a name="section11129153920518"></a>

TapGesture\(options?: \{ count?: number, fingers?: number \}\)

-   Parameters

    <a name="table1392916196212"></a>
    <table><thead align="left"><tr id="row19306191218"><th class="cellrowborder" valign="top" width="14.330000000000002%" id="mcps1.1.6.1.1"><p id="p199307193217"><a name="p199307193217"></a><a name="p199307193217"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="14.799999999999999%" id="mcps1.1.6.1.2"><p id="p119302191128"><a name="p119302191128"></a><a name="p119302191128"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="11.58%" id="mcps1.1.6.1.3"><p id="p7930141911211"><a name="p7930141911211"></a><a name="p7930141911211"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="8.219999999999999%" id="mcps1.1.6.1.4"><p id="p1393020194219"><a name="p1393020194219"></a><a name="p1393020194219"></a>Default Value</p>
    </th>
    <th class="cellrowborder" valign="top" width="51.07000000000001%" id="mcps1.1.6.1.5"><p id="p693061912210"><a name="p693061912210"></a><a name="p693061912210"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row1238121310306"><td class="cellrowborder" valign="top" width="14.330000000000002%" headers="mcps1.1.6.1.1 "><p id="p938113193017"><a name="p938113193017"></a><a name="p938113193017"></a>count</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.799999999999999%" headers="mcps1.1.6.1.2 "><p id="p23861373017"><a name="p23861373017"></a><a name="p23861373017"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="11.58%" headers="mcps1.1.6.1.3 "><p id="p183814131307"><a name="p183814131307"></a><a name="p183814131307"></a>No</p>
    </td>
    <td class="cellrowborder" valign="top" width="8.219999999999999%" headers="mcps1.1.6.1.4 "><p id="p163831312306"><a name="p163831312306"></a><a name="p163831312306"></a>1</p>
    </td>
    <td class="cellrowborder" valign="top" width="51.07000000000001%" headers="mcps1.1.6.1.5 "><p id="p103814137301"><a name="p103814137301"></a><a name="p103814137301"></a>Number of consecutive taps. If this parameter is set to a value less than <strong id="b137681238173218"><a name="b137681238173218"></a><a name="b137681238173218"></a>1</strong>, the default value will be used.</p>
    <div class="note" id="note1962422343316"><a name="note1962422343316"></a><a name="note1962422343316"></a><span class="notetitle"> NOTE: </span><div class="notebody"><p id="p1262452373311"><a name="p1262452373311"></a><a name="p1262452373311"></a>If multi-tap is configured, the timeout interval between a lift and the next tap is 300 ms.</p>
    </div></div>
    </td>
    </tr>
    <tr id="row1093021911217"><td class="cellrowborder" valign="top" width="14.330000000000002%" headers="mcps1.1.6.1.1 "><p id="p119307198218"><a name="p119307198218"></a><a name="p119307198218"></a>fingers</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.799999999999999%" headers="mcps1.1.6.1.2 "><p id="p129301719828"><a name="p129301719828"></a><a name="p129301719828"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="11.58%" headers="mcps1.1.6.1.3 "><p id="p893091913213"><a name="p893091913213"></a><a name="p893091913213"></a>No</p>
    </td>
    <td class="cellrowborder" valign="top" width="8.219999999999999%" headers="mcps1.1.6.1.4 "><p id="p421641117507"><a name="p421641117507"></a><a name="p421641117507"></a>1</p>
    </td>
    <td class="cellrowborder" valign="top" width="51.07000000000001%" headers="mcps1.1.6.1.5 "><p id="p1791619538303"><a name="p1791619538303"></a><a name="p1791619538303"></a>Minimum number of fingers to trigger a tap. The value ranges from 1 to 10.</p>
    <div class="note" id="note439342719312"><a name="note439342719312"></a><a name="note439342719312"></a><span class="notetitle"> NOTE: </span><div class="notebody"><p id="p116781255143118"><a name="p116781255143118"></a><a name="p116781255143118"></a>1. When multi-finger is configured, if the number of fingers used for tap does not reach the specified number within 300 ms after the first finger is tapped, the gesture fails to be recognized.</p>
    <p id="p939311275319"><a name="p939311275319"></a><a name="p939311275319"></a>2. Gesture recognition fails if the number of fingers used for tap exceeds the configured number.</p>
    </div></div>
    </td>
    </tr>
    </tbody>
    </table>


## Events<a name="section23760590517"></a>

<a name="table135406579437"></a>
<table><thead align="left"><tr id="row1154015719436"><th class="cellrowborder" colspan="2" valign="top" id="mcps1.1.4.1.1"><p id="p85411457184316"><a name="p85411457184316"></a><a name="p85411457184316"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.1.4.1.2"><p id="p5541457194319"><a name="p5541457194319"></a><a name="p5541457194319"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row4541257114319"><td class="cellrowborder" colspan="2" valign="top" headers="mcps1.1.4.1.1 "><p id="p5541357194313"><a name="p5541357194313"></a><a name="p5541357194313"></a>onAction((event?: <a href="#li21621335144710">TapGestureEvent</a>) =&gt; void)</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.1.4.1.2 "><p id="p11541155710434"><a name="p11541155710434"></a><a name="p11541155710434"></a>Callback invoked when a tap gesture is recognized.</p>
</td>
</tr>
</tbody>
</table>

-   <a name="li21621335144710"></a>TapGestureEvent attributes<sup>8+</sup>

    Inherited from  [GestureEvent](ts-gesture-settings.md#table290mcpsimp).


## Example<a name="section16900453182718"></a>

```
@Entry
@Component
struct TapGestureExample {
  @State value: string = ''

  build() {
    Flex({ direction: FlexDirection.Column, alignItems: ItemAlign.Center, justifyContent: FlexAlign.SpaceBetween }) {
      Text('Click twice')
      Text(this.value)
    }
    .height(200).width(300).padding(60).border({ width: 1 }).margin(30)
    .gesture(
      TapGesture({ count: 2 })
        .onAction(() => {
          this.value = 'TapGesture onAction'
        })
    )
  }
}
```

![](figures/tapgesture.gif)

