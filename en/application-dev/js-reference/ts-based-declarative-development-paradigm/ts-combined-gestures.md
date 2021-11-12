# Combined Gestures<a name="EN-US_TOPIC_0000001160419381"></a>

## APIs<a name="section46581530142116"></a>

GestureGroup\(mode: GestureMode, ...gesture: GestureType\[\]\)

-   Parameters

    <a name="table173341539181419"></a>
    <table><thead align="left"><tr id="row1333463916149"><th class="cellrowborder" valign="top" width="16.11%" id="mcps1.1.6.1.1"><p id="p133353392142"><a name="p133353392142"></a><a name="p133353392142"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="20.330000000000002%" id="mcps1.1.6.1.2"><p id="p1335143919146"><a name="p1335143919146"></a><a name="p1335143919146"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="11.450000000000001%" id="mcps1.1.6.1.3"><p id="p0335193981413"><a name="p0335193981413"></a><a name="p0335193981413"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="9.35%" id="mcps1.1.6.1.4"><p id="p1333543911418"><a name="p1333543911418"></a><a name="p1333543911418"></a>Default Value</p>
    </th>
    <th class="cellrowborder" valign="top" width="42.76%" id="mcps1.1.6.1.5"><p id="p6335173915149"><a name="p6335173915149"></a><a name="p6335173915149"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row1433516398146"><td class="cellrowborder" valign="top" width="16.11%" headers="mcps1.1.6.1.1 "><p id="p9335439111419"><a name="p9335439111419"></a><a name="p9335439111419"></a>mode</p>
    </td>
    <td class="cellrowborder" valign="top" width="20.330000000000002%" headers="mcps1.1.6.1.2 "><p id="p43352391148"><a name="p43352391148"></a><a name="p43352391148"></a><a href="#li1176517215161">GestureMode</a></p>
    </td>
    <td class="cellrowborder" valign="top" width="11.450000000000001%" headers="mcps1.1.6.1.3 "><p id="p9335239141417"><a name="p9335239141417"></a><a name="p9335239141417"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.35%" headers="mcps1.1.6.1.4 "><p id="p15335839161412"><a name="p15335839161412"></a><a name="p15335839161412"></a>-</p>
    </td>
    <td class="cellrowborder" valign="top" width="42.76%" headers="mcps1.1.6.1.5 "><p id="p71884403389"><a name="p71884403389"></a><a name="p71884403389"></a>Recognition mode of combined gestures.</p>
    </td>
    </tr>
    <tr id="row8335239171414"><td class="cellrowborder" valign="top" width="16.11%" headers="mcps1.1.6.1.1 "><p id="p17335153941411"><a name="p17335153941411"></a><a name="p17335153941411"></a>gesture</p>
    </td>
    <td class="cellrowborder" valign="top" width="20.330000000000002%" headers="mcps1.1.6.1.2 "><p id="p207391156164411"><a name="p207391156164411"></a><a name="p207391156164411"></a><a href="ts-basic-gestures-tapgesture.md">TapGesture</a></p>
    <p id="p1873975624410"><a name="p1873975624410"></a><a name="p1873975624410"></a>| <a href="ts-basic-gestures-longpressgesture.md">LongPressGesture</a></p>
    <p id="p17391556114410"><a name="p17391556114410"></a><a name="p17391556114410"></a>| <a href="ts-basic-gestures-pangesture.md">PanGesture</a></p>
    <p id="p12739556194416"><a name="p12739556194416"></a><a name="p12739556194416"></a>| <a href="ts-basic-gestures-pinchgesture.md">PinchGesture</a></p>
    <p id="p9739185616449"><a name="p9739185616449"></a><a name="p9739185616449"></a>| <a href="ts-basic-gestures-rotationgesture.md">RotationGesture</a></p>
    </td>
    <td class="cellrowborder" valign="top" width="11.450000000000001%" headers="mcps1.1.6.1.3 "><p id="p14335639151414"><a name="p14335639151414"></a><a name="p14335639151414"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.35%" headers="mcps1.1.6.1.4 "><p id="p103359397141"><a name="p103359397141"></a><a name="p103359397141"></a>-</p>
    </td>
    <td class="cellrowborder" valign="top" width="42.76%" headers="mcps1.1.6.1.5 "><p id="p203351539171416"><a name="p203351539171416"></a><a name="p203351539171416"></a>Variable-length parameter, indicating one or more basic gesture types. These gestures are recognized in combination.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   <a name="li1176517215161"></a>GestureMode enums

    <a name="table3452114216394"></a>
    <table><thead align="left"><tr id="row245219426397"><th class="cellrowborder" valign="top" width="25.2%" id="mcps1.1.3.1.1"><p id="p545244283914"><a name="p545244283914"></a><a name="p545244283914"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="74.8%" id="mcps1.1.3.1.2"><p id="p2452114203917"><a name="p2452114203917"></a><a name="p2452114203917"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row6452144218390"><td class="cellrowborder" valign="top" width="25.2%" headers="mcps1.1.3.1.1 "><p id="p34529427398"><a name="p34529427398"></a><a name="p34529427398"></a>Sequence</p>
    </td>
    <td class="cellrowborder" valign="top" width="74.8%" headers="mcps1.1.3.1.2 "><p id="p1245211421393"><a name="p1245211421393"></a><a name="p1245211421393"></a>Sequential recognition: Gestures are recognized in the registration sequence until all gestures are recognized successfully. When one gesture fails to be recognized, all gestures fail to be recognized.</p>
    </td>
    </tr>
    <tr id="row12452184217398"><td class="cellrowborder" valign="top" width="25.2%" headers="mcps1.1.3.1.1 "><p id="p54523425398"><a name="p54523425398"></a><a name="p54523425398"></a>Parallel</p>
    </td>
    <td class="cellrowborder" valign="top" width="74.8%" headers="mcps1.1.3.1.2 "><p id="p745215426391"><a name="p745215426391"></a><a name="p745215426391"></a>Parallel recognition. Registered gestures are recognized concurrently until all gestures are recognized. The recognition result of each gesture does not affect each other.</p>
    </td>
    </tr>
    <tr id="row9452134213392"><td class="cellrowborder" valign="top" width="25.2%" headers="mcps1.1.3.1.1 "><p id="p510719111403"><a name="p510719111403"></a><a name="p510719111403"></a>Exclusive</p>
    </td>
    <td class="cellrowborder" valign="top" width="74.8%" headers="mcps1.1.3.1.2 "><p id="p154533425394"><a name="p154533425394"></a><a name="p154533425394"></a>Exclusive recognition. Registered gestures are identified concurrently. If one gesture is successfully recognized, gesture recognition ends.</p>
    </td>
    </tr>
    </tbody>
    </table>


## Events<a name="section660220206578"></a>

<a name="table2683193511513"></a>
<table><thead align="left"><tr id="row76836351515"><th class="cellrowborder" colspan="2" valign="top" id="mcps1.1.4.1.1"><p id="p196831635195112"><a name="p196831635195112"></a><a name="p196831635195112"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.1.4.1.2"><p id="p186841835145111"><a name="p186841835145111"></a><a name="p186841835145111"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1468416359511"><td class="cellrowborder" colspan="2" valign="top" headers="mcps1.1.4.1.1 "><p id="p156841935195116"><a name="p156841935195116"></a><a name="p156841935195116"></a>onCancel(event: () =&gt; void)</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.1.4.1.2 "><p id="p17684103595118"><a name="p17684103595118"></a><a name="p17684103595118"></a>Callback for the GestureMode.Sequence cancellation event.</p>
</td>
</tr>
</tbody>
</table>

## Example<a name="section16900453182718"></a>

```
@Entry
@Component
struct GestureGroupExample {
  @State count: number = 0
  @State offsetX: number = 0
  @State offsetY: number = 0
  @State borderStyle: BorderStyle = BorderStyle.Solid

  build() {
    Flex({ direction: FlexDirection.Column, alignItems: ItemAlign.Center, justifyContent: FlexAlign.SpaceBetween }) {
      Text('sequence gesture\n' + 'LongPress onAction:' + this.count + '\nPanGesture offset:\nX: ' + this.offsetX + '\n' + 'Y: ' + this.offsetY)
    }.translate({ x: this.offsetX, y: this.offsetY, z: 5 })
    .height(100).width(200).padding(10).margin(80).border({ width: 1, style: this.borderStyle })
    .gesture(
      GestureGroup(GestureMode.Sequence,
        LongPressGesture({ repeat: true })
          .onAction((event: GestureEvent) => {
            if (event.repeat) {this.count++}
            console.log('LongPress onAction')
          })
          .onActionEnd(() => {
            console.log('LongPress end')
          }),
        PanGesture({})
          .onActionStart(() => {
            this.borderStyle = BorderStyle.Dashed
            console.log('pan start')
          })
          .onActionUpdate((event: GestureEvent) => {
            this.offsetX = event.offsetX
            this.offsetY = event.offsetY
            console.log('pan update')
          })
      )
      .onCancel(() => {
        console.log('sequence gesture canceled')
      })
    )
  }
}
```

![](figures/gesturegroup.gif)

