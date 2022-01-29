# Attribute Animation<a name="EN-US_TOPIC_0000001192915094"></a>

>![](../../public_sys-resources/icon-note.gif) **NOTE:** 
>This gesture is supported since API version 7. Updates will be marked with a superscript to indicate their earliest API version.

When the universal attributes of a component change, you can create an  **AnimatorProperty**  for gradient to improve user experience.

<a name="table618mcpsimp"></a>
<table><thead align="left"><tr id="row625mcpsimp"><th class="cellrowborder" valign="top" width="16.21%" id="mcps1.1.5.1.1"><p id="p627mcpsimp"><a name="p627mcpsimp"></a><a name="p627mcpsimp"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="15.980000000000002%" id="mcps1.1.5.1.2"><p id="p629mcpsimp"><a name="p629mcpsimp"></a><a name="p629mcpsimp"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="13.630000000000003%" id="mcps1.1.5.1.3"><p id="p631mcpsimp"><a name="p631mcpsimp"></a><a name="p631mcpsimp"></a>Default Value</p>
</th>
<th class="cellrowborder" valign="top" width="54.18000000000001%" id="mcps1.1.5.1.4"><p id="p633mcpsimp"><a name="p633mcpsimp"></a><a name="p633mcpsimp"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row634mcpsimp"><td class="cellrowborder" valign="top" width="16.21%" headers="mcps1.1.5.1.1 "><p id="p636mcpsimp"><a name="p636mcpsimp"></a><a name="p636mcpsimp"></a>duration</p>
</td>
<td class="cellrowborder" valign="top" width="15.980000000000002%" headers="mcps1.1.5.1.2 "><p id="p638mcpsimp"><a name="p638mcpsimp"></a><a name="p638mcpsimp"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="13.630000000000003%" headers="mcps1.1.5.1.3 "><p id="p640mcpsimp"><a name="p640mcpsimp"></a><a name="p640mcpsimp"></a>1000</p>
</td>
<td class="cellrowborder" valign="top" width="54.18000000000001%" headers="mcps1.1.5.1.4 "><p id="p642mcpsimp"><a name="p642mcpsimp"></a><a name="p642mcpsimp"></a>Animation duration, in ms. The default duration is 1000 ms.</p>
</td>
</tr>
<tr id="row643mcpsimp"><td class="cellrowborder" valign="top" width="16.21%" headers="mcps1.1.5.1.1 "><p id="p645mcpsimp"><a name="p645mcpsimp"></a><a name="p645mcpsimp"></a>curve</p>
</td>
<td class="cellrowborder" valign="top" width="15.980000000000002%" headers="mcps1.1.5.1.2 "><p id="p647mcpsimp"><a name="p647mcpsimp"></a><a name="p647mcpsimp"></a><a href="#li16621545614">Curve</a></p>
</td>
<td class="cellrowborder" valign="top" width="13.630000000000003%" headers="mcps1.1.5.1.3 "><p id="p649mcpsimp"><a name="p649mcpsimp"></a><a name="p649mcpsimp"></a>Linear</p>
</td>
<td class="cellrowborder" valign="top" width="54.18000000000001%" headers="mcps1.1.5.1.4 "><p id="p651mcpsimp"><a name="p651mcpsimp"></a><a name="p651mcpsimp"></a>The default curve is linear. For details about the valid values, see <a href="#table12144170154116">Curve enums</a>.</p>
</td>
</tr>
<tr id="row652mcpsimp"><td class="cellrowborder" valign="top" width="16.21%" headers="mcps1.1.5.1.1 "><p id="p654mcpsimp"><a name="p654mcpsimp"></a><a name="p654mcpsimp"></a>delay</p>
</td>
<td class="cellrowborder" valign="top" width="15.980000000000002%" headers="mcps1.1.5.1.2 "><p id="p656mcpsimp"><a name="p656mcpsimp"></a><a name="p656mcpsimp"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="13.630000000000003%" headers="mcps1.1.5.1.3 "><p id="p658mcpsimp"><a name="p658mcpsimp"></a><a name="p658mcpsimp"></a>0</p>
</td>
<td class="cellrowborder" valign="top" width="54.18000000000001%" headers="mcps1.1.5.1.4 "><p id="p660mcpsimp"><a name="p660mcpsimp"></a><a name="p660mcpsimp"></a>Delay of animation playback, in ms. By default, the playback is not delayed.</p>
</td>
</tr>
<tr id="row670mcpsimp"><td class="cellrowborder" valign="top" width="16.21%" headers="mcps1.1.5.1.1 "><p id="p672mcpsimp"><a name="p672mcpsimp"></a><a name="p672mcpsimp"></a>iterations</p>
</td>
<td class="cellrowborder" valign="top" width="15.980000000000002%" headers="mcps1.1.5.1.2 "><p id="p674mcpsimp"><a name="p674mcpsimp"></a><a name="p674mcpsimp"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="13.630000000000003%" headers="mcps1.1.5.1.3 "><p id="p676mcpsimp"><a name="p676mcpsimp"></a><a name="p676mcpsimp"></a>1</p>
</td>
<td class="cellrowborder" valign="top" width="54.18000000000001%" headers="mcps1.1.5.1.4 "><p id="p678mcpsimp"><a name="p678mcpsimp"></a><a name="p678mcpsimp"></a>Number of times that the animation is played. By default, the animation is played once. The value <strong id="b149936423520"><a name="b149936423520"></a><a name="b149936423520"></a>-1</strong> indicates that the animation is played for an unlimited number of times.</p>
</td>
</tr>
<tr id="row679mcpsimp"><td class="cellrowborder" valign="top" width="16.21%" headers="mcps1.1.5.1.1 "><p id="p681mcpsimp"><a name="p681mcpsimp"></a><a name="p681mcpsimp"></a>playMode</p>
</td>
<td class="cellrowborder" valign="top" width="15.980000000000002%" headers="mcps1.1.5.1.2 "><p id="p683mcpsimp"><a name="p683mcpsimp"></a><a name="p683mcpsimp"></a><a href="ts-appendix-enums.md#section2780178121714">PlayMode</a></p>
</td>
<td class="cellrowborder" valign="top" width="13.630000000000003%" headers="mcps1.1.5.1.3 "><p id="p685mcpsimp"><a name="p685mcpsimp"></a><a name="p685mcpsimp"></a>Normal</p>
</td>
<td class="cellrowborder" valign="top" width="54.18000000000001%" headers="mcps1.1.5.1.4 "><p id="p687mcpsimp"><a name="p687mcpsimp"></a><a name="p687mcpsimp"></a>Playback mode. By default, the animation is played from the beginning after the playback is complete.</p>
</td>
</tr>
</tbody>
</table>

-   <a name="li16621545614"></a>Curve enums

    <a name="table12144170154116"></a>
    <table><thead align="left"><tr id="row1314430184118"><th class="cellrowborder" valign="top" width="22.48%" id="mcps1.1.3.1.1"><p id="p1614414014416"><a name="p1614414014416"></a><a name="p1614414014416"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="77.52%" id="mcps1.1.3.1.2"><p id="p1314415074113"><a name="p1314415074113"></a><a name="p1314415074113"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row61441505417"><td class="cellrowborder" valign="top" width="22.48%" headers="mcps1.1.3.1.1 "><p id="p191443034117"><a name="p191443034117"></a><a name="p191443034117"></a>Linear</p>
    </td>
    <td class="cellrowborder" valign="top" width="77.52%" headers="mcps1.1.3.1.2 "><p id="p121447017412"><a name="p121447017412"></a><a name="p121447017412"></a>The animation speed keeps unchanged.</p>
    </td>
    </tr>
    <tr id="row20144801418"><td class="cellrowborder" valign="top" width="22.48%" headers="mcps1.1.3.1.1 "><p id="p17145110194110"><a name="p17145110194110"></a><a name="p17145110194110"></a>Ease</p>
    </td>
    <td class="cellrowborder" valign="top" width="77.52%" headers="mcps1.1.3.1.2 "><p id="p171454015415"><a name="p171454015415"></a><a name="p171454015415"></a>The animation starts at a low speed and then accelerates. It slows down before the animation ends. The cubic-bezier curve (0.25, 0.1, 0.25, 1.0) is used.</p>
    </td>
    </tr>
    <tr id="row914570194112"><td class="cellrowborder" valign="top" width="22.48%" headers="mcps1.1.3.1.1 "><p id="p714511012418"><a name="p714511012418"></a><a name="p714511012418"></a>EaseIn</p>
    </td>
    <td class="cellrowborder" valign="top" width="77.52%" headers="mcps1.1.3.1.2 "><p id="p101451704415"><a name="p101451704415"></a><a name="p101451704415"></a>The animation starts at a low speed. The cubic-bezier curve (0.42, 0.0, 1.0, 1.0) is used.</p>
    </td>
    </tr>
    <tr id="row414560184112"><td class="cellrowborder" valign="top" width="22.48%" headers="mcps1.1.3.1.1 "><p id="p1114590124110"><a name="p1114590124110"></a><a name="p1114590124110"></a>EaseOut</p>
    </td>
    <td class="cellrowborder" valign="top" width="77.52%" headers="mcps1.1.3.1.2 "><p id="p13145007410"><a name="p13145007410"></a><a name="p13145007410"></a>The animation ends at a low speed. The cubic-bezier curve (0.0, 0.0, 0.58, 1.0) is used.</p>
    </td>
    </tr>
    <tr id="row09402054112813"><td class="cellrowborder" valign="top" width="22.48%" headers="mcps1.1.3.1.1 "><p id="p7940185413286"><a name="p7940185413286"></a><a name="p7940185413286"></a>EaseInOut</p>
    </td>
    <td class="cellrowborder" valign="top" width="77.52%" headers="mcps1.1.3.1.2 "><p id="p159403543285"><a name="p159403543285"></a><a name="p159403543285"></a>The animation starts and ends at a low speed. The cubic-bezier curve (0.42, 0.0, 0.58, 1.0) is used.</p>
    </td>
    </tr>
    <tr id="row968074706"><td class="cellrowborder" valign="top" width="22.48%" headers="mcps1.1.3.1.1 "><p id="p668004506"><a name="p668004506"></a><a name="p668004506"></a>FastOutSlowIn</p>
    </td>
    <td class="cellrowborder" valign="top" width="77.52%" headers="mcps1.1.3.1.2 "><p id="p186801141202"><a name="p186801141202"></a><a name="p186801141202"></a>The animation uses the standard cubic-bezier curve (0.4, 0.0, 0.2, 1.0).</p>
    </td>
    </tr>
    <tr id="row7689991303"><td class="cellrowborder" valign="top" width="22.48%" headers="mcps1.1.3.1.1 "><p id="p46901197014"><a name="p46901197014"></a><a name="p46901197014"></a>LinearOutSlowIn</p>
    </td>
    <td class="cellrowborder" valign="top" width="77.52%" headers="mcps1.1.3.1.2 "><p id="p19690593012"><a name="p19690593012"></a><a name="p19690593012"></a>The animation uses the deceleration cubic-bezier curve (0.0, 0.0, 0.2, 1.0).</p>
    </td>
    </tr>
    <tr id="row929620312"><td class="cellrowborder" valign="top" width="22.48%" headers="mcps1.1.3.1.1 "><p id="p122961101218"><a name="p122961101218"></a><a name="p122961101218"></a>FastOutLinearIn</p>
    </td>
    <td class="cellrowborder" valign="top" width="77.52%" headers="mcps1.1.3.1.2 "><p id="p11296501511"><a name="p11296501511"></a><a name="p11296501511"></a>The animation uses the acceleration cubic-bezier curve (0.4, 0.0, 1.0, 1.0).</p>
    </td>
    </tr>
    <tr id="row3225344120"><td class="cellrowborder" valign="top" width="22.48%" headers="mcps1.1.3.1.1 "><p id="p17225342116"><a name="p17225342116"></a><a name="p17225342116"></a>ExtremeDeceleration</p>
    </td>
    <td class="cellrowborder" valign="top" width="77.52%" headers="mcps1.1.3.1.2 "><p id="p142251341112"><a name="p142251341112"></a><a name="p142251341112"></a>The animation uses the extreme deceleration cubic-bezier curve (0.0, 0.0, 0.0, 1.0).</p>
    </td>
    </tr>
    <tr id="row172861558115"><td class="cellrowborder" valign="top" width="22.48%" headers="mcps1.1.3.1.1 "><p id="p1828718551314"><a name="p1828718551314"></a><a name="p1828718551314"></a>Sharp</p>
    </td>
    <td class="cellrowborder" valign="top" width="77.52%" headers="mcps1.1.3.1.2 "><p id="p62876551111"><a name="p62876551111"></a><a name="p62876551111"></a>The animation uses the sharp cubic-bezier curve (0.33, 0.0, 0.67, 1.0).</p>
    </td>
    </tr>
    <tr id="row430245920118"><td class="cellrowborder" valign="top" width="22.48%" headers="mcps1.1.3.1.1 "><p id="p43029591216"><a name="p43029591216"></a><a name="p43029591216"></a>Rhythm</p>
    </td>
    <td class="cellrowborder" valign="top" width="77.52%" headers="mcps1.1.3.1.2 "><p id="p16302159914"><a name="p16302159914"></a><a name="p16302159914"></a>The animation uses the rhythm cubic-bezier curve (0.7, 0.0, 0.2, 1.0).</p>
    </td>
    </tr>
    <tr id="row1584139216"><td class="cellrowborder" valign="top" width="22.48%" headers="mcps1.1.3.1.1 "><p id="p10840318214"><a name="p10840318214"></a><a name="p10840318214"></a>Smooth</p>
    </td>
    <td class="cellrowborder" valign="top" width="77.52%" headers="mcps1.1.3.1.2 "><p id="p48410318212"><a name="p48410318212"></a><a name="p48410318212"></a>The animation uses the smooth cubic-bezier curve (0.4, 0.0, 0.4, 1.0).</p>
    </td>
    </tr>
    <tr id="row1878101152919"><td class="cellrowborder" valign="top" width="22.48%" headers="mcps1.1.3.1.1 "><p id="p15781171162917"><a name="p15781171162917"></a><a name="p15781171162917"></a>Friction</p>
    </td>
    <td class="cellrowborder" valign="top" width="77.52%" headers="mcps1.1.3.1.2 "><p id="p1378191102917"><a name="p1378191102917"></a><a name="p1378191102917"></a>Damping curve. The cubic-bezier curve (0.2, 0.0, 0.2, 1.0) is used.</p>
    </td>
    </tr>
    </tbody>
    </table>


## Example<a name="section137791934201313"></a>

```
@Entry
@Component
struct AttrAnimationExample {
  @State widthSize: number = 200
  @State heightSize: number = 100
  @State flag: boolean = true

  build() {
    Column() {
      Button('click me')
        .onClick((event: ClickEvent) => {
          if (this.flag) {
            this.widthSize = 100
            this.heightSize = 50
          } else {
            this.widthSize = 200
            this.heightSize = 100
          }
          this.flag = !this.flag
        })
        .width(this.widthSize).height(this.heightSize).backgroundColor(0x317aff)
        .animation({
          duration: 2000, // Animation duration
          curve: Curve.EaseOut, // Animation curve
          delay: 500, // Animation delay
          iterations: 1, // Number of playback times
          playMode: PlayMode.Normal // Animation mode
        }) // Animation configuration for the width and height attributes of the Button component
    }.width('100%').margin({ top: 5 })
  }
}
```

![](figures/attranimation.gif)

