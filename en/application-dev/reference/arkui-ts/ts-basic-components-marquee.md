# Marquee<a name="EN-US_TOPIC_0000001193075120"></a>

>![](../../public_sys-resources/icon-note.gif) **NOTE:** 
>This component is supported since API version 8. Updates will be marked with a superscript to indicate their earliest API version.

The  **<Marquee\>**  component displays single-line scrolling text.

## Required Permissions<a name="section781125411508"></a>

None

## Child Components<a name="section1747133474417"></a>

None

## APIs<a name="section9359185354414"></a>

Marquee\(value: \{ start: boolean, step?: number, loop?: number, fromStart?: boolean, src: string \}\)

-   Parameters

    <a name="table1392916196212"></a>
    <table><thead align="left"><tr id="row19306191218"><th class="cellrowborder" valign="top" width="16.11%" id="mcps1.1.6.1.1"><p id="p199307193217"><a name="p199307193217"></a><a name="p199307193217"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="14.01%" id="mcps1.1.6.1.2"><p id="p119302191128"><a name="p119302191128"></a><a name="p119302191128"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="14.499999999999998%" id="mcps1.1.6.1.3"><p id="p7930141911211"><a name="p7930141911211"></a><a name="p7930141911211"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="13.170000000000002%" id="mcps1.1.6.1.4"><p id="p1393020194219"><a name="p1393020194219"></a><a name="p1393020194219"></a>Default Value</p>
    </th>
    <th class="cellrowborder" valign="top" width="42.21%" id="mcps1.1.6.1.5"><p id="p693061912210"><a name="p693061912210"></a><a name="p693061912210"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row1093021911217"><td class="cellrowborder" valign="top" width="16.11%" headers="mcps1.1.6.1.1 "><p id="p119307198218"><a name="p119307198218"></a><a name="p119307198218"></a>start</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.01%" headers="mcps1.1.6.1.2 "><p id="p129301719828"><a name="p129301719828"></a><a name="p129301719828"></a>boolean</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.499999999999998%" headers="mcps1.1.6.1.3 "><p id="p893091913213"><a name="p893091913213"></a><a name="p893091913213"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="13.170000000000002%" headers="mcps1.1.6.1.4 "><p id="p793071910214"><a name="p793071910214"></a><a name="p793071910214"></a>-</p>
    </td>
    <td class="cellrowborder" valign="top" width="42.21%" headers="mcps1.1.6.1.5 "><p id="p693016198212"><a name="p693016198212"></a><a name="p693016198212"></a>Whether to set the marquee scroll.</p>
    </td>
    </tr>
    <tr id="row199301191726"><td class="cellrowborder" valign="top" width="16.11%" headers="mcps1.1.6.1.1 "><p id="p0930419923"><a name="p0930419923"></a><a name="p0930419923"></a>step</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.01%" headers="mcps1.1.6.1.2 "><p id="p1993071918217"><a name="p1993071918217"></a><a name="p1993071918217"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.499999999999998%" headers="mcps1.1.6.1.3 "><p id="p29309191029"><a name="p29309191029"></a><a name="p29309191029"></a>No</p>
    </td>
    <td class="cellrowborder" valign="top" width="13.170000000000002%" headers="mcps1.1.6.1.4 "><p id="p118311842123617"><a name="p118311842123617"></a><a name="p118311842123617"></a>6</p>
    </td>
    <td class="cellrowborder" valign="top" width="42.21%" headers="mcps1.1.6.1.5 "><p id="p793001918220"><a name="p793001918220"></a><a name="p793001918220"></a>Scroll step of the marquee text.</p>
    </td>
    </tr>
    <tr id="row10370145873614"><td class="cellrowborder" valign="top" width="16.11%" headers="mcps1.1.6.1.1 "><p id="p4370135818365"><a name="p4370135818365"></a><a name="p4370135818365"></a>loop</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.01%" headers="mcps1.1.6.1.2 "><p id="p53708580369"><a name="p53708580369"></a><a name="p53708580369"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.499999999999998%" headers="mcps1.1.6.1.3 "><p id="p15370165813367"><a name="p15370165813367"></a><a name="p15370165813367"></a>No</p>
    </td>
    <td class="cellrowborder" valign="top" width="13.170000000000002%" headers="mcps1.1.6.1.4 "><p id="p13701558103616"><a name="p13701558103616"></a><a name="p13701558103616"></a>-1</p>
    </td>
    <td class="cellrowborder" valign="top" width="42.21%" headers="mcps1.1.6.1.5 "><p id="p6370105815365"><a name="p6370105815365"></a><a name="p6370105815365"></a>Number of times the marquee scrolls. If the value is less than or equal to 0, the marquee scrolls continuously.</p>
    </td>
    </tr>
    <tr id="row247175183714"><td class="cellrowborder" valign="top" width="16.11%" headers="mcps1.1.6.1.1 "><p id="p3471958371"><a name="p3471958371"></a><a name="p3471958371"></a>fromStart</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.01%" headers="mcps1.1.6.1.2 "><p id="p13471257376"><a name="p13471257376"></a><a name="p13471257376"></a>boolean</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.499999999999998%" headers="mcps1.1.6.1.3 "><p id="p6471454375"><a name="p6471454375"></a><a name="p6471454375"></a>No</p>
    </td>
    <td class="cellrowborder" valign="top" width="13.170000000000002%" headers="mcps1.1.6.1.4 "><p id="p1747135123718"><a name="p1747135123718"></a><a name="p1747135123718"></a>true</p>
    </td>
    <td class="cellrowborder" valign="top" width="42.21%" headers="mcps1.1.6.1.5 "><p id="p18471153375"><a name="p18471153375"></a><a name="p18471153375"></a>Whether the marquee scrolls from the start of the text. If the value is <strong id="b052932855811"><a name="b052932855811"></a><a name="b052932855811"></a>false</strong>, the marquee scrolls from the end of the text.</p>
    </td>
    </tr>
    <tr id="row157653817379"><td class="cellrowborder" valign="top" width="16.11%" headers="mcps1.1.6.1.1 "><p id="p197654883718"><a name="p197654883718"></a><a name="p197654883718"></a>src</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.01%" headers="mcps1.1.6.1.2 "><p id="p11765108153716"><a name="p11765108153716"></a><a name="p11765108153716"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.499999999999998%" headers="mcps1.1.6.1.3 "><p id="p137659813720"><a name="p137659813720"></a><a name="p137659813720"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="13.170000000000002%" headers="mcps1.1.6.1.4 "><p id="p1765208133711"><a name="p1765208133711"></a><a name="p1765208133711"></a>-</p>
    </td>
    <td class="cellrowborder" valign="top" width="42.21%" headers="mcps1.1.6.1.5 "><p id="p16765158143711"><a name="p16765158143711"></a><a name="p16765158143711"></a>Text to be scrolled.</p>
    </td>
    </tr>
    </tbody>
    </table>


## Events<a name="section1635844417475"></a>

<a name="table111753094820"></a>
<table><thead align="left"><tr id="row11176100164815"><th class="cellrowborder" colspan="2" valign="top" id="mcps1.1.4.1.1"><p id="p276mcpsimp"><a name="p276mcpsimp"></a><a name="p276mcpsimp"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.1.4.1.2"><p id="p3176150114819"><a name="p3176150114819"></a><a name="p3176150114819"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row171761700484"><td class="cellrowborder" colspan="2" valign="top" headers="mcps1.1.4.1.1 "><p id="p6940113511352"><a name="p6940113511352"></a><a name="p6940113511352"></a>onStart(callback: () =&gt; void)</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.1.4.1.2 "><p id="p71769012486"><a name="p71769012486"></a><a name="p71769012486"></a>Invoked when scrolling starts.</p>
</td>
</tr>
<tr id="row5176601485"><td class="cellrowborder" colspan="2" valign="top" headers="mcps1.1.4.1.1 "><p id="p1287810465356"><a name="p1287810465356"></a><a name="p1287810465356"></a>onBounce(callback: () =&gt; void)</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.1.4.1.2 "><p id="p317711014811"><a name="p317711014811"></a><a name="p317711014811"></a>Invoked when scrolling reaches the end.</p>
</td>
</tr>
<tr id="row8177706483"><td class="cellrowborder" colspan="2" valign="top" headers="mcps1.1.4.1.1 "><p id="p10795054203519"><a name="p10795054203519"></a><a name="p10795054203519"></a>onFinish(callback: () =&gt; void)</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.1.4.1.2 "><p id="p61771084820"><a name="p61771084820"></a><a name="p61771084820"></a>Invoked when scrolling is complete.</p>
</td>
</tr>
</tbody>
</table>

## Example<a name="section3609114210499"></a>

```
@Entry
@Component
struct MarqueeExample {
  @State start: boolean = false
  @State fromStart: boolean = true
  @State step: number = 50
  @State loop: number = 3
  @State src: string = "Running Marquee starts rolling"

  build() {
    Flex({ direction: FlexDirection.Column, alignItems: ItemAlign.Center, justifyContent: FlexAlign.Center }) {
      Marquee({
        start: this.start,
        step: this.step,
        loop: this.loop,
        fromStart: this.fromStart,
        src: this.src
      })
        .fontColor(Color.White)
        .fontSize(50)
        .allowScale(false)
        .fontWeight(FontWeight.Bold)
        .backgroundColor(Color.Black)
        .margin({bottom:40})
        .onStart(() => {
          console.log('Marquee animation complete onStart')
        })
        .onBounce(() => {
          console.log('Marquee animation complete onBounce')
        })
        .onFinish(() => {
          console.log('Marquee animation complete onFinish')
        })
        Button('start')
          .onClick(() => {
            this.start = true
             })
          .width(200)
          .height(60)
          .margin({bottom:20})
    }
    .width('100%')
    .height('100%')
  }
}
```

![](figures/gif-1.gif)

