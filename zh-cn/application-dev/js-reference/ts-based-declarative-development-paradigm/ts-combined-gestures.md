# 组合手势<a name="ZH-CN_TOPIC_0000001160419381"></a>

## 接口<a name="section46581530142116"></a>

GestureGroup\(mode: GestureMode, ...gesture: GestureType\[\]\)

-   参数

    <a name="table173341539181419"></a>
    <table><thead align="left"><tr id="row1333463916149"><th class="cellrowborder" valign="top" width="16.11%" id="mcps1.1.6.1.1"><p id="p133353392142"><a name="p133353392142"></a><a name="p133353392142"></a>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="20.330000000000002%" id="mcps1.1.6.1.2"><p id="p1335143919146"><a name="p1335143919146"></a><a name="p1335143919146"></a>参数类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="11.450000000000001%" id="mcps1.1.6.1.3"><p id="p0335193981413"><a name="p0335193981413"></a><a name="p0335193981413"></a>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="9.35%" id="mcps1.1.6.1.4"><p id="p1333543911418"><a name="p1333543911418"></a><a name="p1333543911418"></a>默认值</p>
    </th>
    <th class="cellrowborder" valign="top" width="42.76%" id="mcps1.1.6.1.5"><p id="p6335173915149"><a name="p6335173915149"></a><a name="p6335173915149"></a>参数描述</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row1433516398146"><td class="cellrowborder" valign="top" width="16.11%" headers="mcps1.1.6.1.1 "><p id="p9335439111419"><a name="p9335439111419"></a><a name="p9335439111419"></a>mode</p>
    </td>
    <td class="cellrowborder" valign="top" width="20.330000000000002%" headers="mcps1.1.6.1.2 "><p id="p43352391148"><a name="p43352391148"></a><a name="p43352391148"></a><a href="#li1176517215161">GestureMode</a></p>
    </td>
    <td class="cellrowborder" valign="top" width="11.450000000000001%" headers="mcps1.1.6.1.3 "><p id="p9335239141417"><a name="p9335239141417"></a><a name="p9335239141417"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.35%" headers="mcps1.1.6.1.4 "><p id="p15335839161412"><a name="p15335839161412"></a><a name="p15335839161412"></a>-</p>
    </td>
    <td class="cellrowborder" valign="top" width="42.76%" headers="mcps1.1.6.1.5 "><p id="p71884403389"><a name="p71884403389"></a><a name="p71884403389"></a>设置组合手势识别模式。</p>
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
    <td class="cellrowborder" valign="top" width="11.450000000000001%" headers="mcps1.1.6.1.3 "><p id="p14335639151414"><a name="p14335639151414"></a><a name="p14335639151414"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.35%" headers="mcps1.1.6.1.4 "><p id="p103359397141"><a name="p103359397141"></a><a name="p103359397141"></a>-</p>
    </td>
    <td class="cellrowborder" valign="top" width="42.76%" headers="mcps1.1.6.1.5 "><p id="p203351539171416"><a name="p203351539171416"></a><a name="p203351539171416"></a>可变长参数，1个或者多个基础手势类型，这些手势会被组合识别。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   <a name="li1176517215161"></a>GestureMode枚举说明

    <a name="table3452114216394"></a>
    <table><thead align="left"><tr id="row245219426397"><th class="cellrowborder" valign="top" width="25.2%" id="mcps1.1.3.1.1"><p id="p545244283914"><a name="p545244283914"></a><a name="p545244283914"></a>名称</p>
    </th>
    <th class="cellrowborder" valign="top" width="74.8%" id="mcps1.1.3.1.2"><p id="p2452114203917"><a name="p2452114203917"></a><a name="p2452114203917"></a>描述</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row6452144218390"><td class="cellrowborder" valign="top" width="25.2%" headers="mcps1.1.3.1.1 "><p id="p34529427398"><a name="p34529427398"></a><a name="p34529427398"></a>Sequence</p>
    </td>
    <td class="cellrowborder" valign="top" width="74.8%" headers="mcps1.1.3.1.2 "><p id="p1245211421393"><a name="p1245211421393"></a><a name="p1245211421393"></a>顺序识别，按照手势的注册顺序识别手势，直到所有手势识别成功。当有一个手势识别失败时，所有手势识别失败。</p>
    </td>
    </tr>
    <tr id="row12452184217398"><td class="cellrowborder" valign="top" width="25.2%" headers="mcps1.1.3.1.1 "><p id="p54523425398"><a name="p54523425398"></a><a name="p54523425398"></a>Parallel</p>
    </td>
    <td class="cellrowborder" valign="top" width="74.8%" headers="mcps1.1.3.1.2 "><p id="p745215426391"><a name="p745215426391"></a><a name="p745215426391"></a>并发识别，注册的手势同时识别，直到所有手势识别结束，手势识别互相不影响。</p>
    </td>
    </tr>
    <tr id="row9452134213392"><td class="cellrowborder" valign="top" width="25.2%" headers="mcps1.1.3.1.1 "><p id="p510719111403"><a name="p510719111403"></a><a name="p510719111403"></a>Exclusive</p>
    </td>
    <td class="cellrowborder" valign="top" width="74.8%" headers="mcps1.1.3.1.2 "><p id="p154533425394"><a name="p154533425394"></a><a name="p154533425394"></a>互斥识别，注册的手势同时识别，若有一个手势识别成功，则结束手势识别。</p>
    </td>
    </tr>
    </tbody>
    </table>


## 事件<a name="section660220206578"></a>

<a name="table2683193511513"></a>
<table><thead align="left"><tr id="row76836351515"><th class="cellrowborder" colspan="2" valign="top" id="mcps1.1.4.1.1"><p id="p196831635195112"><a name="p196831635195112"></a><a name="p196831635195112"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.1.4.1.2"><p id="p186841835145111"><a name="p186841835145111"></a><a name="p186841835145111"></a>功能描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row1468416359511"><td class="cellrowborder" colspan="2" valign="top" headers="mcps1.1.4.1.1 "><p id="p156841935195116"><a name="p156841935195116"></a><a name="p156841935195116"></a>onCancel(event: () =&gt; void)</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.1.4.1.2 "><p id="p17684103595118"><a name="p17684103595118"></a><a name="p17684103595118"></a>顺序组合手势（GestureMode.Sequence）取消后触发回调。</p>
</td>
</tr>
</tbody>
</table>

## 示例<a name="section16900453182718"></a>

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

![](figures/GestureGroup.gif)

