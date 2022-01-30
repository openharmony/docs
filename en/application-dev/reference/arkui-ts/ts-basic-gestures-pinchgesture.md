# PinchGesture<a name="EN-US_TOPIC_0000001237715101"></a>

>![](../../public_sys-resources/icon-note.gif) **NOTE:** 
>This gesture is supported since API version 7. Updates will be marked with a superscript to indicate their earliest API version.

## Required Permissions<a name="section781125411508"></a>

None

## APIs<a name="section46581530142116"></a>

PinchGesture\(options?: \{ fingers?: number, distance?: number \}\)

-   Parameters

    <a name="table6433854121111"></a>
    <table><thead align="left"><tr id="row1333463916149"><th class="cellrowborder" valign="top" width="16.11%" id="mcps1.1.6.1.1"><p id="p543535461112"><a name="p543535461112"></a><a name="p543535461112"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="15.959999999999999%" id="mcps1.1.6.1.2"><p id="p24351054201110"><a name="p24351054201110"></a><a name="p24351054201110"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="11.04%" id="mcps1.1.6.1.3"><p id="p1043518544112"><a name="p1043518544112"></a><a name="p1043518544112"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="11.709999999999999%" id="mcps1.1.6.1.4"><p id="p17436954101117"><a name="p17436954101117"></a><a name="p17436954101117"></a>Default Value</p>
    </th>
    <th class="cellrowborder" valign="top" width="45.18%" id="mcps1.1.6.1.5"><p id="p174361554111115"><a name="p174361554111115"></a><a name="p174361554111115"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row1433516398146"><td class="cellrowborder" valign="top" width="16.11%" headers="mcps1.1.6.1.1 "><p id="p3436454151117"><a name="p3436454151117"></a><a name="p3436454151117"></a>fingers</p>
    </td>
    <td class="cellrowborder" valign="top" width="15.959999999999999%" headers="mcps1.1.6.1.2 "><p id="p17437185411115"><a name="p17437185411115"></a><a name="p17437185411115"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="11.04%" headers="mcps1.1.6.1.3 "><p id="p2437054181119"><a name="p2437054181119"></a><a name="p2437054181119"></a>No</p>
    </td>
    <td class="cellrowborder" valign="top" width="11.709999999999999%" headers="mcps1.1.6.1.4 "><p id="p44377543115"><a name="p44377543115"></a><a name="p44377543115"></a>2</p>
    </td>
    <td class="cellrowborder" valign="top" width="45.18%" headers="mcps1.1.6.1.5 "><p id="p1843825411110"><a name="p1843825411110"></a><a name="p1843825411110"></a>Minimum number of fingers to trigger a pinch. The value ranges from 2 to 5.</p>
    </td>
    </tr>
    <tr id="row8335239171414"><td class="cellrowborder" valign="top" width="16.11%" headers="mcps1.1.6.1.1 "><p id="p843855441111"><a name="p843855441111"></a><a name="p843855441111"></a>distance</p>
    </td>
    <td class="cellrowborder" valign="top" width="15.959999999999999%" headers="mcps1.1.6.1.2 "><p id="p243965411110"><a name="p243965411110"></a><a name="p243965411110"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="11.04%" headers="mcps1.1.6.1.3 "><p id="p6439754141115"><a name="p6439754141115"></a><a name="p6439754141115"></a>No</p>
    </td>
    <td class="cellrowborder" valign="top" width="11.709999999999999%" headers="mcps1.1.6.1.4 "><p id="p174391754151110"><a name="p174391754151110"></a><a name="p174391754151110"></a>3.0</p>
    </td>
    <td class="cellrowborder" valign="top" width="45.18%" headers="mcps1.1.6.1.5 "><p id="p44401854141112"><a name="p44401854141112"></a><a name="p44401854141112"></a>Minimum recognition distance, in vp.</p>
    </td>
    </tr>
    </tbody>
    </table>


## Events<a name="section1121514205616"></a>

<a name="table135406579437"></a>
<table><thead align="left"><tr id="row1154015719436"><th class="cellrowborder" colspan="2" valign="top" id="mcps1.1.4.1.1"><p id="p85411457184316"><a name="p85411457184316"></a><a name="p85411457184316"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.1.4.1.2"><p id="p5541457194319"><a name="p5541457194319"></a><a name="p5541457194319"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row4541257114319"><td class="cellrowborder" colspan="2" valign="top" headers="mcps1.1.4.1.1 "><p id="p5541357194313"><a name="p5541357194313"></a><a name="p5541357194313"></a>onActionStart((event?: <a href="#li21621335144710">PinchGestureEvent</a>) =&gt; void)</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.1.4.1.2 "><p id="p11541155710434"><a name="p11541155710434"></a><a name="p11541155710434"></a>Callback invoked when a pinch gesture is recognized.</p>
</td>
</tr>
<tr id="row54544191113"><td class="cellrowborder" colspan="2" valign="top" headers="mcps1.1.4.1.1 "><p id="p145591931117"><a name="p145591931117"></a><a name="p145591931117"></a>onActionUpdate((event?: <a href="#li21621335144710">PinchGestureEvent</a>) =&gt; void)</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.1.4.1.2 "><p id="p1455111961111"><a name="p1455111961111"></a><a name="p1455111961111"></a>Callback invoked during the movement of a pinch gesture.</p>
</td>
</tr>
<tr id="row2899841162916"><td class="cellrowborder" colspan="2" valign="top" headers="mcps1.1.4.1.1 "><p id="p15900174162916"><a name="p15900174162916"></a><a name="p15900174162916"></a>onActionEnd((event?: <a href="#li21621335144710">PinchGestureEvent</a>) =&gt; void)</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.1.4.1.2 "><p id="p69001041172920"><a name="p69001041172920"></a><a name="p69001041172920"></a>Callback invoked when the finger used for a pinch gesture is lift.</p>
</td>
</tr>
<tr id="row13598134672914"><td class="cellrowborder" colspan="2" valign="top" headers="mcps1.1.4.1.1 "><p id="p85999460299"><a name="p85999460299"></a><a name="p85999460299"></a>onActionCancel(event: () =&gt; void)</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.1.4.1.2 "><p id="p1459954652916"><a name="p1459954652916"></a><a name="p1459954652916"></a>Callback invoked when a tap cancellation event is received after a pinch gesture is recognized.</p>
</td>
</tr>
</tbody>
</table>

-   <a name="li21621335144710"></a>PinchGestureEvent attributes<sup>8+</sup>

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
    <tbody><tr id="row303mcpsimp"><td class="cellrowborder" valign="top" width="20.09%" headers="mcps1.1.4.1.1 "><p id="p326mcpsimp"><a name="p326mcpsimp"></a><a name="p326mcpsimp"></a>scale</p>
    </td>
    <td class="cellrowborder" valign="top" width="18.41%" headers="mcps1.1.4.1.2 "><p id="p328mcpsimp"><a name="p328mcpsimp"></a><a name="p328mcpsimp"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.5%" headers="mcps1.1.4.1.3 "><p id="p330mcpsimp"><a name="p330mcpsimp"></a><a name="p330mcpsimp"></a>Scale ratio. This attribute is used for the pinch gesture.</p>
    </td>
    </tr>
    <tr id="row310mcpsimp"><td class="cellrowborder" valign="top" width="20.09%" headers="mcps1.1.4.1.1 "><p id="p1626610325382"><a name="p1626610325382"></a><a name="p1626610325382"></a>pinchCenterX</p>
    </td>
    <td class="cellrowborder" valign="top" width="18.41%" headers="mcps1.1.4.1.2 "><p id="p1526643203814"><a name="p1526643203814"></a><a name="p1526643203814"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.5%" headers="mcps1.1.4.1.3 "><p id="p4266163216388"><a name="p4266163216388"></a><a name="p4266163216388"></a>X coordinate of the center of the pinch, in px.</p>
    </td>
    </tr>
    <tr id="row317mcpsimp"><td class="cellrowborder" valign="top" width="20.09%" headers="mcps1.1.4.1.1 "><p id="p19386163653814"><a name="p19386163653814"></a><a name="p19386163653814"></a>pinchCenterY</p>
    </td>
    <td class="cellrowborder" valign="top" width="18.41%" headers="mcps1.1.4.1.2 "><p id="p638693615380"><a name="p638693615380"></a><a name="p638693615380"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.5%" headers="mcps1.1.4.1.3 "><p id="p1238643673818"><a name="p1238643673818"></a><a name="p1238643673818"></a>Y coordinate of the center of the pinch, in px.</p>
    </td>
    </tr>
    </tbody>
    </table>


## Example<a name="section16900453182718"></a>

```
@Entry
@Component
struct PinchGestureExample {
  @State scale: number = 1

  build() {
    Flex({ direction: FlexDirection.Column, alignItems: ItemAlign.Center, justifyContent: FlexAlign.SpaceBetween }) {
      Text('PinchGesture scale:' + this.scale)
    }
    .height(100).width(200).padding(20).border({ width: 1 }).margin(80)
    .scale({ x: this.scale, y: this.scale, z: this.scale })
    .gesture(
      PinchGesture()
        .onActionStart((event: PinchGestureEvent) => {
          console.info('Pinch start')
        })
        .onActionUpdate((event: PinchGestureEvent) => {
          this.scale = event.scale
        })
        .onActionEnd(() => {
          console.info('Pinch end')
        })
    )
  }
}
```

![](figures/pinchgesture.gif)

