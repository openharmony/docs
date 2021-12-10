# Gesture Binding Methods<a name="EN-US_TOPIC_0000001113113018"></a>

You can use the following attributes to bind gesture recognition to a component. When a gesture is recognized, the event callback is invoked to notify the component.

<a name="table944614112104"></a>
<table><thead align="left"><tr id="row204461811161015"><th class="cellrowborder" valign="top" width="18.108189181081894%" id="mcps1.1.5.1.1"><p id="p1644631116106"><a name="p1644631116106"></a><a name="p1644631116106"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="20.73792620737926%" id="mcps1.1.5.1.2"><p id="p1544681113104"><a name="p1544681113104"></a><a name="p1544681113104"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="22.617738226177384%" id="mcps1.1.5.1.3"><p id="p54461011181010"><a name="p54461011181010"></a><a name="p54461011181010"></a>Default Value</p>
</th>
<th class="cellrowborder" valign="top" width="38.53614638536146%" id="mcps1.1.5.1.4"><p id="p164461211111011"><a name="p164461211111011"></a><a name="p164461211111011"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row17446171141018"><td class="cellrowborder" valign="top" width="18.108189181081894%" headers="mcps1.1.5.1.1 "><p id="p1344631141011"><a name="p1344631141011"></a><a name="p1344631141011"></a>gesture</p>
</td>
<td class="cellrowborder" valign="top" width="20.73792620737926%" headers="mcps1.1.5.1.2 "><p id="p1957911339347"><a name="p1957911339347"></a><a name="p1957911339347"></a>gesture: <a href="#li13550165717410">GestureType</a>,</p>
<p id="p54461311191019"><a name="p54461311191019"></a><a name="p54461311191019"></a>mask?: <a href="#li05419551143">GestureMask</a></p>
</td>
<td class="cellrowborder" valign="top" width="22.617738226177384%" headers="mcps1.1.5.1.3 "><p id="p1845118520402"><a name="p1845118520402"></a><a name="p1845118520402"></a>gesture: -,</p>
<p id="p8347175974014"><a name="p8347175974014"></a><a name="p8347175974014"></a>mask: GestureMask.Normal</p>
</td>
<td class="cellrowborder" valign="top" width="38.53614638536146%" headers="mcps1.1.5.1.4 "><p id="p5568132704814"><a name="p5568132704814"></a><a name="p5568132704814"></a>Gesture to recognize.</p>
<p id="p104469114109"><a name="p104469114109"></a><a name="p104469114109"></a><strong id="b29691964247"><a name="b29691964247"></a><a name="b29691964247"></a>gesture</strong> specifies the type of the gesture to bind, and <strong id="b12623173132414"><a name="b12623173132414"></a><a name="b12623173132414"></a>mask</strong> specifies the event response setting.</p>
</td>
</tr>
<tr id="row2061211295910"><td class="cellrowborder" valign="top" width="18.108189181081894%" headers="mcps1.1.5.1.1 "><p id="p66131425594"><a name="p66131425594"></a><a name="p66131425594"></a>priorityGesture</p>
</td>
<td class="cellrowborder" valign="top" width="20.73792620737926%" headers="mcps1.1.5.1.2 "><p id="p26211539358"><a name="p26211539358"></a><a name="p26211539358"></a>gesture: <a href="#li13550165717410">GestureType</a>,</p>
<p id="p206215394516"><a name="p206215394516"></a><a name="p206215394516"></a>mask?: <a href="#li05419551143">GestureMask</a></p>
</td>
<td class="cellrowborder" valign="top" width="22.617738226177384%" headers="mcps1.1.5.1.3 "><p id="p18613202165915"><a name="p18613202165915"></a><a name="p18613202165915"></a>gesture: -,</p>
<p id="p17988104110418"><a name="p17988104110418"></a><a name="p17988104110418"></a>mask: GestureMask.Normal</p>
</td>
<td class="cellrowborder" valign="top" width="38.53614638536146%" headers="mcps1.1.5.1.4 "><p id="p96137210592"><a name="p96137210592"></a><a name="p96137210592"></a>Gesture to preferentially recognize.</p>
<p id="p1019519536483"><a name="p1019519536483"></a><a name="p1019519536483"></a><strong id="b12945130172510"><a name="b12945130172510"></a><a name="b12945130172510"></a>gesture</strong> specifies the type of the gesture to bind, and <strong id="b19464062514"><a name="b19464062514"></a><a name="b19464062514"></a>mask</strong> specifies the event response setting.</p>
<div class="note" id="note18517313410"><a name="note18517313410"></a><a name="note18517313410"></a><span class="notetitle"> NOTE: </span><div class="notebody"><a name="ul109190774114"></a><a name="ul109190774114"></a><ul id="ul109190774114"><li>By default, the child component takes precedence over the parent component in gesture recognition. When <strong id="b398919252137"><a name="b398919252137"></a><a name="b398919252137"></a>priorityGesture</strong> is configured for the parent component, the parent component takes precedence over the child component in gesture recognition.</li></ul>
</div></div>
</td>
</tr>
<tr id="row158353605910"><td class="cellrowborder" valign="top" width="18.108189181081894%" headers="mcps1.1.5.1.1 "><p id="p68362655916"><a name="p68362655916"></a><a name="p68362655916"></a>parallelGesture</p>
</td>
<td class="cellrowborder" valign="top" width="20.73792620737926%" headers="mcps1.1.5.1.2 "><p id="p11190743358"><a name="p11190743358"></a><a name="p11190743358"></a>gesture: <a href="#li13550165717410">GestureType</a>,</p>
<p id="p11904431950"><a name="p11904431950"></a><a name="p11904431950"></a>mask?: <a href="#li05419551143">GestureMask</a></p>
</td>
<td class="cellrowborder" valign="top" width="22.617738226177384%" headers="mcps1.1.5.1.3 "><p id="p117241409423"><a name="p117241409423"></a><a name="p117241409423"></a>gesture: -,</p>
<p id="p197248054214"><a name="p197248054214"></a><a name="p197248054214"></a>mask: GestureMask.Normal</p>
</td>
<td class="cellrowborder" valign="top" width="38.53614638536146%" headers="mcps1.1.5.1.4 "><p id="p11836196155911"><a name="p11836196155911"></a><a name="p11836196155911"></a>Gesture that can be triggered together with the child component gesture.</p>
<p id="p201145816486"><a name="p201145816486"></a><a name="p201145816486"></a><strong id="b59522001251"><a name="b59522001251"></a><a name="b59522001251"></a>gesture</strong> specifies the type of the gesture to bind, and <strong id="b149527013255"><a name="b149527013255"></a><a name="b149527013255"></a>mask</strong> specifies the event response setting.</p>
<div class="note" id="note1488211815428"><a name="note1488211815428"></a><a name="note1488211815428"></a><span class="notetitle"> NOTE: </span><div class="notebody"><a name="ul13442131918420"></a><a name="ul13442131918420"></a><ul id="ul13442131918420"><li>The gesture event is not a bubbling event. When <strong id="b1828153091416"><a name="b1828153091416"></a><a name="b1828153091416"></a>parallelGesture</strong> is set for the parent component, gesture events that are the same for the parent component and child components can be triggered, thereby implementing a bubbling effect.</li></ul>
</div></div>
</td>
</tr>
</tbody>
</table>

-   <a name="li05419551143"></a>GestureMask enums

    <a name="table3452114216394"></a>
    <table><thead align="left"><tr id="row245219426397"><th class="cellrowborder" valign="top" width="25.2%" id="mcps1.1.3.1.1"><p id="p545244283914"><a name="p545244283914"></a><a name="p545244283914"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="74.8%" id="mcps1.1.3.1.2"><p id="p2452114203917"><a name="p2452114203917"></a><a name="p2452114203917"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row6452144218390"><td class="cellrowborder" valign="top" width="25.2%" headers="mcps1.1.3.1.1 "><p id="p34529427398"><a name="p34529427398"></a><a name="p34529427398"></a>Normal</p>
    </td>
    <td class="cellrowborder" valign="top" width="74.8%" headers="mcps1.1.3.1.2 "><p id="p175862510368"><a name="p175862510368"></a><a name="p175862510368"></a>The gestures of child components are not masked and are recognized based on the default gesture recognition sequence.</p>
    </td>
    </tr>
    <tr id="row12452184217398"><td class="cellrowborder" valign="top" width="25.2%" headers="mcps1.1.3.1.1 "><p id="p54523425398"><a name="p54523425398"></a><a name="p54523425398"></a>IgnoreInternal</p>
    </td>
    <td class="cellrowborder" valign="top" width="74.8%" headers="mcps1.1.3.1.2 "><p id="p745215426391"><a name="p745215426391"></a><a name="p745215426391"></a>The gestures of child components are masked. Only the gestures of the current component are recognized.</p>
    <div class="note" id="note498994724413"><a name="note498994724413"></a><a name="note498994724413"></a><span class="notetitle"> NOTE: </span><div class="notebody"><a name="ul0160856174418"></a><a name="ul0160856174418"></a><ul id="ul0160856174418"><li>However, the built-in gestures of the child components are not masked. For example, when the child component is a <strong id="b15749201120175"><a name="b15749201120175"></a><a name="b15749201120175"></a>&lt;List&gt;</strong> component, the built-in sliding gestures can still be triggered.</li></ul>
    </div></div>
    </td>
    </tr>
    </tbody>
    </table>


-   <a name="li13550165717410"></a>Gesture types

    <a name="table5827185910217"></a>
    <table><thead align="left"><tr id="row128271591226"><th class="cellrowborder" valign="top" width="25.2%" id="mcps1.1.3.1.1"><p id="p8828115918216"><a name="p8828115918216"></a><a name="p8828115918216"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="74.8%" id="mcps1.1.3.1.2"><p id="p17828959023"><a name="p17828959023"></a><a name="p17828959023"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row88284591024"><td class="cellrowborder" valign="top" width="25.2%" headers="mcps1.1.3.1.1 "><p id="p118281599217"><a name="p118281599217"></a><a name="p118281599217"></a>TapGesture</p>
    </td>
    <td class="cellrowborder" valign="top" width="74.8%" headers="mcps1.1.3.1.2 "><p id="p1182818591217"><a name="p1182818591217"></a><a name="p1182818591217"></a>Tap gesture, which can be a single-tap or multi-tap gesture.</p>
    </td>
    </tr>
    <tr id="row682819591217"><td class="cellrowborder" valign="top" width="25.2%" headers="mcps1.1.3.1.1 "><p id="p8828959826"><a name="p8828959826"></a><a name="p8828959826"></a>LongPressGesture</p>
    </td>
    <td class="cellrowborder" valign="top" width="74.8%" headers="mcps1.1.3.1.2 "><p id="p1182895915212"><a name="p1182895915212"></a><a name="p1182895915212"></a>Long press gesture.</p>
    </td>
    </tr>
    <tr id="row9452134213392"><td class="cellrowborder" valign="top" width="25.2%" headers="mcps1.1.3.1.1 "><p id="p510719111403"><a name="p510719111403"></a><a name="p510719111403"></a>PanGesture</p>
    </td>
    <td class="cellrowborder" valign="top" width="74.8%" headers="mcps1.1.3.1.2 "><p id="p154533425394"><a name="p154533425394"></a><a name="p154533425394"></a>Pan gesture.</p>
    </td>
    </tr>
    <tr id="row1345313424399"><td class="cellrowborder" valign="top" width="25.2%" headers="mcps1.1.3.1.1 "><p id="p1766215124010"><a name="p1766215124010"></a><a name="p1766215124010"></a>PinchGesture</p>
    </td>
    <td class="cellrowborder" valign="top" width="74.8%" headers="mcps1.1.3.1.2 "><p id="p1245319426394"><a name="p1245319426394"></a><a name="p1245319426394"></a>Pinch gesture.</p>
    </td>
    </tr>
    <tr id="row98471941249"><td class="cellrowborder" valign="top" width="25.2%" headers="mcps1.1.3.1.1 "><p id="p984715411248"><a name="p984715411248"></a><a name="p984715411248"></a>RotationGesture</p>
    </td>
    <td class="cellrowborder" valign="top" width="74.8%" headers="mcps1.1.3.1.2 "><p id="p20847741744"><a name="p20847741744"></a><a name="p20847741744"></a>Rotation gesture.</p>
    </td>
    </tr>
    <tr id="row7930351148"><td class="cellrowborder" valign="top" width="25.2%" headers="mcps1.1.3.1.1 "><p id="p89306517410"><a name="p89306517410"></a><a name="p89306517410"></a>GestureGroup</p>
    </td>
    <td class="cellrowborder" valign="top" width="74.8%" headers="mcps1.1.3.1.2 "><p id="p17930251442"><a name="p17930251442"></a><a name="p17930251442"></a>A group of gestures. Continuous recognition, parallel recognition, and exclusive recognition are supported.</p>
    </td>
    </tr>
    </tbody>
    </table>


## Gesture Response Event<a name="section13681164710593"></a>

The component uses the  **gesture**  method to bind the gesture object and uses the events provided in this object to respond to the gesture operation. For example, the  **onAction**  event of the  **TapGesture**  object can be used to respond to a click event. For details about the event definition, see the section of each gesture object.

-   TapGesture events

    <a name="table135406579437"></a>
    <table><thead align="left"><tr id="row1154015719436"><th class="cellrowborder" colspan="2" valign="top" id="mcps1.1.4.1.1"><p id="p85411457184316"><a name="p85411457184316"></a><a name="p85411457184316"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" id="mcps1.1.4.1.2"><p id="p5541457194319"><a name="p5541457194319"></a><a name="p5541457194319"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row4541257114319"><td class="cellrowborder" colspan="2" valign="top" headers="mcps1.1.4.1.1 "><p id="p5541357194313"><a name="p5541357194313"></a><a name="p5541357194313"></a>onAction((event?: <a href="#li209321550192419">GestureEvent</a>) =&gt; void)</p>
    </td>
    <td class="cellrowborder" valign="top" headers="mcps1.1.4.1.2 "><p id="p11541155710434"><a name="p11541155710434"></a><a name="p11541155710434"></a>Callback invoked when a tap gesture is recognized.</p>
    </td>
    </tr>
    </tbody>
    </table>


-   <a name="li209321550192419"></a>GestureEvent attributes

    <a name="table290mcpsimp"></a>
    <table><thead align="left"><tr id="row296mcpsimp"><th class="cellrowborder" valign="top" width="20.11%" id="mcps1.1.4.1.1"><p id="p298mcpsimp"><a name="p298mcpsimp"></a><a name="p298mcpsimp"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="18.39%" id="mcps1.1.4.1.2"><p id="p300mcpsimp"><a name="p300mcpsimp"></a><a name="p300mcpsimp"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="61.5%" id="mcps1.1.4.1.3"><p id="p302mcpsimp"><a name="p302mcpsimp"></a><a name="p302mcpsimp"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row303mcpsimp"><td class="cellrowborder" valign="top" width="20.11%" headers="mcps1.1.4.1.1 "><p id="p305mcpsimp"><a name="p305mcpsimp"></a><a name="p305mcpsimp"></a>repeat</p>
    </td>
    <td class="cellrowborder" valign="top" width="18.39%" headers="mcps1.1.4.1.2 "><p id="p307mcpsimp"><a name="p307mcpsimp"></a><a name="p307mcpsimp"></a>boolean</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.5%" headers="mcps1.1.4.1.3 "><p id="p309mcpsimp"><a name="p309mcpsimp"></a><a name="p309mcpsimp"></a>Whether an event is repeatedly triggered. This attribute is used for the long press gesture.</p>
    </td>
    </tr>
    <tr id="row310mcpsimp"><td class="cellrowborder" valign="top" width="20.11%" headers="mcps1.1.4.1.1 "><p id="p312mcpsimp"><a name="p312mcpsimp"></a><a name="p312mcpsimp"></a>offsetX</p>
    </td>
    <td class="cellrowborder" valign="top" width="18.39%" headers="mcps1.1.4.1.2 "><p id="p314mcpsimp"><a name="p314mcpsimp"></a><a name="p314mcpsimp"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.5%" headers="mcps1.1.4.1.3 "><p id="p316mcpsimp"><a name="p316mcpsimp"></a><a name="p316mcpsimp"></a>Gesture event offset along the x-axis, in vp. This attribute is used for the pan gesture.</p>
    </td>
    </tr>
    <tr id="row317mcpsimp"><td class="cellrowborder" valign="top" width="20.11%" headers="mcps1.1.4.1.1 "><p id="p319mcpsimp"><a name="p319mcpsimp"></a><a name="p319mcpsimp"></a>offsetY</p>
    </td>
    <td class="cellrowborder" valign="top" width="18.39%" headers="mcps1.1.4.1.2 "><p id="p321mcpsimp"><a name="p321mcpsimp"></a><a name="p321mcpsimp"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.5%" headers="mcps1.1.4.1.3 "><p id="p323mcpsimp"><a name="p323mcpsimp"></a><a name="p323mcpsimp"></a>Gesture event offset along the y-axis, in vp. This attribute is used for the pan gesture.</p>
    </td>
    </tr>
    <tr id="row324mcpsimp"><td class="cellrowborder" valign="top" width="20.11%" headers="mcps1.1.4.1.1 "><p id="p326mcpsimp"><a name="p326mcpsimp"></a><a name="p326mcpsimp"></a>scale</p>
    </td>
    <td class="cellrowborder" valign="top" width="18.39%" headers="mcps1.1.4.1.2 "><p id="p328mcpsimp"><a name="p328mcpsimp"></a><a name="p328mcpsimp"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.5%" headers="mcps1.1.4.1.3 "><p id="p330mcpsimp"><a name="p330mcpsimp"></a><a name="p330mcpsimp"></a>Scale ratio. This attribute is used for the pinch gesture.</p>
    </td>
    </tr>
    <tr id="row4266173283818"><td class="cellrowborder" valign="top" width="20.11%" headers="mcps1.1.4.1.1 "><p id="p1626610325382"><a name="p1626610325382"></a><a name="p1626610325382"></a>pinchCenterX</p>
    </td>
    <td class="cellrowborder" valign="top" width="18.39%" headers="mcps1.1.4.1.2 "><p id="p1526643203814"><a name="p1526643203814"></a><a name="p1526643203814"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.5%" headers="mcps1.1.4.1.3 "><p id="p4266163216388"><a name="p4266163216388"></a><a name="p4266163216388"></a>X-coordinate of the center point of the pinch gesture, in px. This attribute is used for the pinch gesture.</p>
    </td>
    </tr>
    <tr id="row838693614382"><td class="cellrowborder" valign="top" width="20.11%" headers="mcps1.1.4.1.1 "><p id="p19386163653814"><a name="p19386163653814"></a><a name="p19386163653814"></a>pinchCenterY</p>
    </td>
    <td class="cellrowborder" valign="top" width="18.39%" headers="mcps1.1.4.1.2 "><p id="p638693615380"><a name="p638693615380"></a><a name="p638693615380"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.5%" headers="mcps1.1.4.1.3 "><p id="p1238643673818"><a name="p1238643673818"></a><a name="p1238643673818"></a>Y-coordinate of the center point of the pinch gesture, in px. This attribute is used for the pinch gesture.</p>
    </td>
    </tr>
    <tr id="row331mcpsimp"><td class="cellrowborder" valign="top" width="20.11%" headers="mcps1.1.4.1.1 "><p id="p333mcpsimp"><a name="p333mcpsimp"></a><a name="p333mcpsimp"></a>angle</p>
    </td>
    <td class="cellrowborder" valign="top" width="18.39%" headers="mcps1.1.4.1.2 "><p id="p335mcpsimp"><a name="p335mcpsimp"></a><a name="p335mcpsimp"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.5%" headers="mcps1.1.4.1.3 "><p id="p337mcpsimp"><a name="p337mcpsimp"></a><a name="p337mcpsimp"></a>Rotation angle. This attribute is used for the rotation gesture.</p>
    </td>
    </tr>
    <tr id="row1194611133620"><td class="cellrowborder" valign="top" width="20.11%" headers="mcps1.1.4.1.1 "><p id="p1619501111361"><a name="p1619501111361"></a><a name="p1619501111361"></a>timestamp</p>
    </td>
    <td class="cellrowborder" valign="top" width="18.39%" headers="mcps1.1.4.1.2 "><p id="p5195161119368"><a name="p5195161119368"></a><a name="p5195161119368"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.5%" headers="mcps1.1.4.1.3 "><p id="p171951211103611"><a name="p171951211103611"></a><a name="p171951211103611"></a>Timestamp of the event.</p>
    </td>
    </tr>
    </tbody>
    </table>


## Example<a name="section5447171181015"></a>

```
@Entry
@Component
struct GestureSettingsExample {
  @State value: string = ''

  build() {
    Column() {
      Text('Click\n' + this.value).gesture(TapGesture()
        .onAction(() => {
          this.value = 'gesture onAction'
        }))
    }.height(200).width(300).padding(60).border({ width: 1 }).margin(30)
    // When priorityGesture is specified, the bound gesture is preferentially recognized and the child component gesture is ignored.
    .priorityGesture(
      TapGesture()
        .onAction(() => {
          this.value = 'priorityGesture onAction'
        }), GestureMask.IgnoreInternal
    )
  }
}
```

![](figures/gesturesetting.gif)

