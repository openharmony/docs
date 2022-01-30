# SwipeGesture<a name="EN-US_TOPIC_0000001237475077"></a>

>![](../../public_sys-resources/icon-note.gif) **NOTE:** 
>This attribute is supported since API version 8. Updates will be marked with a superscript to indicate their earliest API version.

## Required Permissions<a name="section781125411508"></a>

None

## APIs<a name="section46581530142116"></a>

SwipeGesture\(value?: \{ fingers?: number; direction?: SwipeDirection; speed?: number \}\)

-   Parameters

    <a name="table932781715123"></a>
    <table><thead align="left"><tr id="row1333463916149"><th class="cellrowborder" valign="top" width="13.62%" id="mcps1.1.6.1.1"><p id="p43281617131211"><a name="p43281617131211"></a><a name="p43281617131211"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="17.16%" id="mcps1.1.6.1.2"><p id="p10329101721217"><a name="p10329101721217"></a><a name="p10329101721217"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="6.239999999999999%" id="mcps1.1.6.1.3"><p id="p16330171731218"><a name="p16330171731218"></a><a name="p16330171731218"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="20.4%" id="mcps1.1.6.1.4"><p id="p143311717141217"><a name="p143311717141217"></a><a name="p143311717141217"></a>Default Value</p>
    </th>
    <th class="cellrowborder" valign="top" width="42.58%" id="mcps1.1.6.1.5"><p id="p93324175121"><a name="p93324175121"></a><a name="p93324175121"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row1433516398146"><td class="cellrowborder" valign="top" width="13.62%" headers="mcps1.1.6.1.1 "><p id="p4332191717121"><a name="p4332191717121"></a><a name="p4332191717121"></a>fingers</p>
    </td>
    <td class="cellrowborder" valign="top" width="17.16%" headers="mcps1.1.6.1.2 "><p id="p1433318173127"><a name="p1433318173127"></a><a name="p1433318173127"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="6.239999999999999%" headers="mcps1.1.6.1.3 "><p id="p193349174125"><a name="p193349174125"></a><a name="p193349174125"></a>No</p>
    </td>
    <td class="cellrowborder" valign="top" width="20.4%" headers="mcps1.1.6.1.4 "><p id="p113355171122"><a name="p113355171122"></a><a name="p113355171122"></a>1</p>
    </td>
    <td class="cellrowborder" valign="top" width="42.58%" headers="mcps1.1.6.1.5 "><p id="p833614175126"><a name="p833614175126"></a><a name="p833614175126"></a>Minimum number of fingers to trigger a swipe gesture. The value ranges from 1 to 10.</p>
    </td>
    </tr>
    <tr id="row8335239171414"><td class="cellrowborder" valign="top" width="13.62%" headers="mcps1.1.6.1.1 "><p id="p183371017151212"><a name="p183371017151212"></a><a name="p183371017151212"></a>direction</p>
    </td>
    <td class="cellrowborder" valign="top" width="17.16%" headers="mcps1.1.6.1.2 "><p id="p1533851710127"><a name="p1533851710127"></a><a name="p1533851710127"></a><a href="#li1176517215161">SwipeDirection</a></p>
    </td>
    <td class="cellrowborder" valign="top" width="6.239999999999999%" headers="mcps1.1.6.1.3 "><p id="p17339517201212"><a name="p17339517201212"></a><a name="p17339517201212"></a>No</p>
    </td>
    <td class="cellrowborder" valign="top" width="20.4%" headers="mcps1.1.6.1.4 "><p id="p8340171711125"><a name="p8340171711125"></a><a name="p8340171711125"></a>SwipeDirection.All</p>
    </td>
    <td class="cellrowborder" valign="top" width="42.58%" headers="mcps1.1.6.1.5 "><p id="p133468582313"><a name="p133468582313"></a><a name="p133468582313"></a>Swipe direction</p>
    </td>
    </tr>
    <tr id="row1054013952317"><td class="cellrowborder" valign="top" width="13.62%" headers="mcps1.1.6.1.1 "><p id="p16541123902317"><a name="p16541123902317"></a><a name="p16541123902317"></a>speed</p>
    </td>
    <td class="cellrowborder" valign="top" width="17.16%" headers="mcps1.1.6.1.2 "><p id="p35412396232"><a name="p35412396232"></a><a name="p35412396232"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="6.239999999999999%" headers="mcps1.1.6.1.3 "><p id="p17541133962311"><a name="p17541133962311"></a><a name="p17541133962311"></a>No</p>
    </td>
    <td class="cellrowborder" valign="top" width="20.4%" headers="mcps1.1.6.1.4 "><p id="p13541739112313"><a name="p13541739112313"></a><a name="p13541739112313"></a>100</p>
    </td>
    <td class="cellrowborder" valign="top" width="42.58%" headers="mcps1.1.6.1.5 "><p id="p7542039182314"><a name="p7542039182314"></a><a name="p7542039182314"></a>Minimum speed of the swipe operation (100 vp/s).</p>
    </td>
    </tr>
    </tbody>
    </table>

-   <a name="li1176517215161"></a>SwipeDirection enums

    <a name="table3452114216394"></a>
    <table><thead align="left"><tr id="row245219426397"><th class="cellrowborder" valign="top" width="25.2%" id="mcps1.1.3.1.1"><p id="p545244283914"><a name="p545244283914"></a><a name="p545244283914"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="74.8%" id="mcps1.1.3.1.2"><p id="p2452114203917"><a name="p2452114203917"></a><a name="p2452114203917"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row6452144218390"><td class="cellrowborder" valign="top" width="25.2%" headers="mcps1.1.3.1.1 "><p id="p34529427398"><a name="p34529427398"></a><a name="p34529427398"></a>All</p>
    </td>
    <td class="cellrowborder" valign="top" width="74.8%" headers="mcps1.1.3.1.2 "><p id="p9757214162714"><a name="p9757214162714"></a><a name="p9757214162714"></a>All directions.</p>
    </td>
    </tr>
    <tr id="row12452184217398"><td class="cellrowborder" valign="top" width="25.2%" headers="mcps1.1.3.1.1 "><p id="p144813311274"><a name="p144813311274"></a><a name="p144813311274"></a>Horizontal</p>
    </td>
    <td class="cellrowborder" valign="top" width="74.8%" headers="mcps1.1.3.1.2 "><p id="p745215426391"><a name="p745215426391"></a><a name="p745215426391"></a>Horizontal direction.</p>
    </td>
    </tr>
    <tr id="row9452134213392"><td class="cellrowborder" valign="top" width="25.2%" headers="mcps1.1.3.1.1 "><p id="p195968892719"><a name="p195968892719"></a><a name="p195968892719"></a>Vertical</p>
    </td>
    <td class="cellrowborder" valign="top" width="74.8%" headers="mcps1.1.3.1.2 "><p id="p154533425394"><a name="p154533425394"></a><a name="p154533425394"></a>Vertical direction.</p>
    </td>
    </tr>
    </tbody>
    </table>


## Events<a name="section171844635610"></a>

<a name="table135406579437"></a>
<table><thead align="left"><tr id="row1154015719436"><th class="cellrowborder" colspan="2" valign="top" id="mcps1.1.4.1.1"><p id="p85411457184316"><a name="p85411457184316"></a><a name="p85411457184316"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.1.4.1.2"><p id="p5541457194319"><a name="p5541457194319"></a><a name="p5541457194319"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row4541257114319"><td class="cellrowborder" colspan="2" valign="top" headers="mcps1.1.4.1.1 "><p id="p5541357194313"><a name="p5541357194313"></a><a name="p5541357194313"></a>onAction(callback:(event?: <a href="#li497431115208">SwipeGestureEvent</a>) =&gt; void)</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.1.4.1.2 "><p id="p11541155710434"><a name="p11541155710434"></a><a name="p11541155710434"></a>Callback for the swipe gesture recognition event.</p>
</td>
</tr>
</tbody>
</table>

-   <a name="li497431115208"></a>SwipeGestureEvent attributes

    Inherited from  [GestureEvent](ts-gesture-settings.md#table290mcpsimp).

    <a name="table15580161813418"></a>
    <table><thead align="left"><tr id="row45806181744"><th class="cellrowborder" valign="top" width="33.33333333333333%" id="mcps1.1.4.1.1"><p id="p165801018649"><a name="p165801018649"></a><a name="p165801018649"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="33.33333333333333%" id="mcps1.1.4.1.2"><p id="p9580131818410"><a name="p9580131818410"></a><a name="p9580131818410"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="33.33333333333333%" id="mcps1.1.4.1.3"><p id="p858010183417"><a name="p858010183417"></a><a name="p858010183417"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row25801186415"><td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.1.4.1.1 "><p id="p358018181444"><a name="p358018181444"></a><a name="p358018181444"></a>angle</p>
    </td>
    <td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.1.4.1.2 "><p id="p6580161813416"><a name="p6580161813416"></a><a name="p6580161813416"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.1.4.1.3 "><p id="p10581201811415"><a name="p10581201811415"></a><a name="p10581201811415"></a>Angle of the swipe gesture.</p>
    </td>
    </tr>
    <tr id="row2581518249"><td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.1.4.1.1 "><p id="p135816181040"><a name="p135816181040"></a><a name="p135816181040"></a>speed</p>
    </td>
    <td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.1.4.1.2 "><p id="p1258116186414"><a name="p1258116186414"></a><a name="p1258116186414"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.1.4.1.3 "><p id="p758191810414"><a name="p758191810414"></a><a name="p758191810414"></a>Speed of the swipe gesture.</p>
    </td>
    </tr>
    </tbody>
    </table>


## Example<a name="section16900453182718"></a>

```
@Entry
@Component
struct SwipeGestureExample {
  @State rotateAngle : number = 0
  @State speed : number = 1

  build() {
    Column() {
      Text("SwipGesture speed ： " + this.speed)
      Text("SwipGesture angle ： " + this.rotateAngle)
    }
    .position({x: 80, y: 200})
    .border({width:2})
    .width(260).height(260)
    .rotate({x: 0, y: 0, z: 1, angle: this.rotateAngle})
    .gesture(
      SwipeGesture({fingers: 1, direction:SwipeDirection.Vertical})
        .onAction((event: SwipeGestureEvent) => {
          this.speed = event.speed
          this.rotateAngle = event.angle
      })
    )
  }
}
```

![](figures/gif-0.gif)

