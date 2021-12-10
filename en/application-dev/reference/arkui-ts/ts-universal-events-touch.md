# Touch Event<a name="EN-US_TOPIC_0000001158261221"></a>

<a name="table2154mcpsimp"></a>
<table><thead align="left"><tr id="row2160mcpsimp"><th class="cellrowborder" colspan="2" valign="top" id="mcps1.1.5.1.1"><p id="p2164mcpsimp"><a name="p2164mcpsimp"></a><a name="p2164mcpsimp"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.1.5.1.2"><p id="p8337105413110"><a name="p8337105413110"></a><a name="p8337105413110"></a>Bubble Supported</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.1.5.1.3"><p id="p2166mcpsimp"><a name="p2166mcpsimp"></a><a name="p2166mcpsimp"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row2167mcpsimp"><td class="cellrowborder" colspan="2" valign="top" headers="mcps1.1.5.1.1 "><p id="p2169mcpsimp"><a name="p2169mcpsimp"></a><a name="p2169mcpsimp"></a>onTouch(callback: (event?: TouchEvent) =&gt; void)</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.1.5.1.2 "><p id="p93371254153112"><a name="p93371254153112"></a><a name="p93371254153112"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.1.5.1.3 "><p id="p2173mcpsimp"><a name="p2173mcpsimp"></a><a name="p2173mcpsimp"></a>Called when a touch event occurs. For details about the event parameters, see <a href="#section454663343911">TouchEvent</a>.</p>
</td>
</tr>
</tbody>
</table>

## TouchEvent Object<a name="section454663343911"></a>

-   Attributes

    <a name="table898410720260"></a>
    <table><thead align="left"><tr id="row18984147112612"><th class="cellrowborder" valign="top" width="22.509999999999998%" id="mcps1.1.4.1.1"><p id="p9984973264"><a name="p9984973264"></a><a name="p9984973264"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="22.7%" id="mcps1.1.4.1.2"><p id="p1984773265"><a name="p1984773265"></a><a name="p1984773265"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="54.790000000000006%" id="mcps1.1.4.1.3"><p id="p16984207122611"><a name="p16984207122611"></a><a name="p16984207122611"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row298417792614"><td class="cellrowborder" valign="top" width="22.509999999999998%" headers="mcps1.1.4.1.1 "><p id="p139841278263"><a name="p139841278263"></a><a name="p139841278263"></a>type</p>
    </td>
    <td class="cellrowborder" valign="top" width="22.7%" headers="mcps1.1.4.1.2 "><p id="p1498417711267"><a name="p1498417711267"></a><a name="p1498417711267"></a><a href="#li16235181314454">TouchType</a></p>
    </td>
    <td class="cellrowborder" valign="top" width="54.790000000000006%" headers="mcps1.1.4.1.3 "><p id="p298418717261"><a name="p298418717261"></a><a name="p298418717261"></a>Type of a touch event.</p>
    </td>
    </tr>
    <tr id="row998410782614"><td class="cellrowborder" valign="top" width="22.509999999999998%" headers="mcps1.1.4.1.1 "><p id="p1498467172613"><a name="p1498467172613"></a><a name="p1498467172613"></a>touches</p>
    </td>
    <td class="cellrowborder" valign="top" width="22.7%" headers="mcps1.1.4.1.2 "><p id="p298416711269"><a name="p298416711269"></a><a name="p298416711269"></a>Array&lt;<a href="#li1783344810442">TouchObject</a>&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="54.790000000000006%" headers="mcps1.1.4.1.3 "><p id="p59841077265"><a name="p59841077265"></a><a name="p59841077265"></a>All finger information.</p>
    </td>
    </tr>
    <tr id="row20984107182618"><td class="cellrowborder" valign="top" width="22.509999999999998%" headers="mcps1.1.4.1.1 "><p id="p1698413710263"><a name="p1698413710263"></a><a name="p1698413710263"></a>changedTouches</p>
    </td>
    <td class="cellrowborder" valign="top" width="22.7%" headers="mcps1.1.4.1.2 "><p id="p1798467132615"><a name="p1798467132615"></a><a name="p1798467132615"></a>Array&lt;<a href="#li1783344810442">TouchObject</a>&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="54.790000000000006%" headers="mcps1.1.4.1.3 "><p id="p189847762616"><a name="p189847762616"></a><a name="p189847762616"></a>Finger information changed.</p>
    </td>
    </tr>
    <tr id="row89849792613"><td class="cellrowborder" valign="top" width="22.509999999999998%" headers="mcps1.1.4.1.1 "><p id="p1098416792611"><a name="p1098416792611"></a><a name="p1098416792611"></a>timestamp</p>
    </td>
    <td class="cellrowborder" valign="top" width="22.7%" headers="mcps1.1.4.1.2 "><p id="p49841971263"><a name="p49841971263"></a><a name="p49841971263"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="54.790000000000006%" headers="mcps1.1.4.1.3 "><p id="p1698467192611"><a name="p1698467192611"></a><a name="p1698467192611"></a>Timestamp of the event.</p>
    </td>
    </tr>
    </tbody>
    </table>


-   APIs

    <a name="table268mcpsimp"></a>
    <table><thead align="left"><tr id="row274mcpsimp"><th class="cellrowborder" valign="top" width="39.26%" id="mcps1.1.3.1.1"><p id="p276mcpsimp"><a name="p276mcpsimp"></a><a name="p276mcpsimp"></a>API</p>
    </th>
    <th class="cellrowborder" valign="top" width="60.74%" id="mcps1.1.3.1.2"><p id="p280mcpsimp"><a name="p280mcpsimp"></a><a name="p280mcpsimp"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row281mcpsimp"><td class="cellrowborder" valign="top" width="39.26%" headers="mcps1.1.3.1.1 "><p id="p283mcpsimp"><a name="p283mcpsimp"></a><a name="p283mcpsimp"></a>stopPropagation(): void</p>
    </td>
    <td class="cellrowborder" valign="top" width="60.74%" headers="mcps1.1.3.1.2 "><p id="p163641244113119"><a name="p163641244113119"></a><a name="p163641244113119"></a>Stops the event from bubbling upwards or downwards.</p>
    </td>
    </tr>
    </tbody>
    </table>


-   <a name="li1783344810442"></a>TouchObject

    <a name="table154425195577"></a>
    <table><thead align="left"><tr id="row5442519165712"><th class="cellrowborder" valign="top" width="21%" id="mcps1.1.4.1.1"><p id="p544211995710"><a name="p544211995710"></a><a name="p544211995710"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="23%" id="mcps1.1.4.1.2"><p id="p34421419185718"><a name="p34421419185718"></a><a name="p34421419185718"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="56.00000000000001%" id="mcps1.1.4.1.3"><p id="p104421619205712"><a name="p104421619205712"></a><a name="p104421619205712"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row12442161916572"><td class="cellrowborder" valign="top" width="21%" headers="mcps1.1.4.1.1 "><p id="p2442819125714"><a name="p2442819125714"></a><a name="p2442819125714"></a>type</p>
    </td>
    <td class="cellrowborder" valign="top" width="23%" headers="mcps1.1.4.1.2 "><p id="p9442171935714"><a name="p9442171935714"></a><a name="p9442171935714"></a><a href="#li16235181314454">TouchType</a></p>
    </td>
    <td class="cellrowborder" valign="top" width="56.00000000000001%" headers="mcps1.1.4.1.3 "><p id="p6442519185717"><a name="p6442519185717"></a><a name="p6442519185717"></a>Type of a touch event.</p>
    </td>
    </tr>
    <tr id="row114421819145710"><td class="cellrowborder" valign="top" width="21%" headers="mcps1.1.4.1.1 "><p id="p9442319195714"><a name="p9442319195714"></a><a name="p9442319195714"></a>id</p>
    </td>
    <td class="cellrowborder" valign="top" width="23%" headers="mcps1.1.4.1.2 "><p id="p1442919115710"><a name="p1442919115710"></a><a name="p1442919115710"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="56.00000000000001%" headers="mcps1.1.4.1.3 "><p id="p2997174914575"><a name="p2997174914575"></a><a name="p2997174914575"></a>Unique identifier of a finger.</p>
    </td>
    </tr>
    <tr id="row124431019165720"><td class="cellrowborder" valign="top" width="21%" headers="mcps1.1.4.1.1 "><p id="p12443519105713"><a name="p12443519105713"></a><a name="p12443519105713"></a>screenX</p>
    </td>
    <td class="cellrowborder" valign="top" width="23%" headers="mcps1.1.4.1.2 "><p id="p44431219165710"><a name="p44431219165710"></a><a name="p44431219165710"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="56.00000000000001%" headers="mcps1.1.4.1.3 "><p id="p1044311192574"><a name="p1044311192574"></a><a name="p1044311192574"></a>X coordinate of the touch point relative to the left edge of the screen.</p>
    </td>
    </tr>
    <tr id="row94431119135719"><td class="cellrowborder" valign="top" width="21%" headers="mcps1.1.4.1.1 "><p id="p164437198572"><a name="p164437198572"></a><a name="p164437198572"></a>screenY</p>
    </td>
    <td class="cellrowborder" valign="top" width="23%" headers="mcps1.1.4.1.2 "><p id="p344317198579"><a name="p344317198579"></a><a name="p344317198579"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="56.00000000000001%" headers="mcps1.1.4.1.3 "><p id="p174432193577"><a name="p174432193577"></a><a name="p174432193577"></a>Y coordinate of the touch point relative to the upper edge of the device screen.</p>
    </td>
    </tr>
    <tr id="row1544341911577"><td class="cellrowborder" valign="top" width="21%" headers="mcps1.1.4.1.1 "><p id="p94431719205712"><a name="p94431719205712"></a><a name="p94431719205712"></a>x</p>
    </td>
    <td class="cellrowborder" valign="top" width="23%" headers="mcps1.1.4.1.2 "><p id="p7443171975716"><a name="p7443171975716"></a><a name="p7443171975716"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="56.00000000000001%" headers="mcps1.1.4.1.3 "><p id="p744361916578"><a name="p744361916578"></a><a name="p744361916578"></a>X coordinate of the touch point relative to the left edge of the element being touched.</p>
    </td>
    </tr>
    <tr id="row1144331985713"><td class="cellrowborder" valign="top" width="21%" headers="mcps1.1.4.1.1 "><p id="p144381919573"><a name="p144381919573"></a><a name="p144381919573"></a>y</p>
    </td>
    <td class="cellrowborder" valign="top" width="23%" headers="mcps1.1.4.1.2 "><p id="p15443191915572"><a name="p15443191915572"></a><a name="p15443191915572"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="56.00000000000001%" headers="mcps1.1.4.1.3 "><p id="p444371917576"><a name="p444371917576"></a><a name="p444371917576"></a>Y coordinate of the touch point relative to the upper edge of the element being touched.</p>
    </td>
    </tr>
    </tbody>
    </table>


-   <a name="li16235181314454"></a>TouchType enums

    <a name="table3452114216394"></a>
    <table><thead align="left"><tr id="row245219426397"><th class="cellrowborder" valign="top" width="25.2%" id="mcps1.1.3.1.1"><p id="p545244283914"><a name="p545244283914"></a><a name="p545244283914"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="74.8%" id="mcps1.1.3.1.2"><p id="p2452114203917"><a name="p2452114203917"></a><a name="p2452114203917"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row6452144218390"><td class="cellrowborder" valign="top" width="25.2%" headers="mcps1.1.3.1.1 "><p id="p34529427398"><a name="p34529427398"></a><a name="p34529427398"></a>Down</p>
    </td>
    <td class="cellrowborder" valign="top" width="74.8%" headers="mcps1.1.3.1.2 "><p id="p1245211421393"><a name="p1245211421393"></a><a name="p1245211421393"></a>A finger is pressed.</p>
    </td>
    </tr>
    <tr id="row12452184217398"><td class="cellrowborder" valign="top" width="25.2%" headers="mcps1.1.3.1.1 "><p id="p54523425398"><a name="p54523425398"></a><a name="p54523425398"></a>Up</p>
    </td>
    <td class="cellrowborder" valign="top" width="74.8%" headers="mcps1.1.3.1.2 "><p id="p745215426391"><a name="p745215426391"></a><a name="p745215426391"></a>A finger is lifted.</p>
    </td>
    </tr>
    <tr id="row9452134213392"><td class="cellrowborder" valign="top" width="25.2%" headers="mcps1.1.3.1.1 "><p id="p510719111403"><a name="p510719111403"></a><a name="p510719111403"></a>Move</p>
    </td>
    <td class="cellrowborder" valign="top" width="74.8%" headers="mcps1.1.3.1.2 "><p id="p154533425394"><a name="p154533425394"></a><a name="p154533425394"></a>A finger moves on the screen in pressed state.</p>
    </td>
    </tr>
    <tr id="row1345313424399"><td class="cellrowborder" valign="top" width="25.2%" headers="mcps1.1.3.1.1 "><p id="p1766215124010"><a name="p1766215124010"></a><a name="p1766215124010"></a>Cancel</p>
    </td>
    <td class="cellrowborder" valign="top" width="74.8%" headers="mcps1.1.3.1.2 "><p id="p1245319426394"><a name="p1245319426394"></a><a name="p1245319426394"></a>A touch event is canceled.</p>
    </td>
    </tr>
    </tbody>
    </table>


## Example<a name="section13817013123017"></a>

```
@Entry
@Component
struct TouchExample {
  @State text: string = ''
  @State eventType: string = ''

  build() {
    Flex({ direction: FlexDirection.Column, alignItems: ItemAlign.Center, justifyContent: FlexAlign.SpaceBetween }) {
      Button('Touch').backgroundColor(0x2788D9)
        .onTouch((event: TouchEvent) => {
          if (event.type === TouchType.Down) {
            this.eventType = 'Down'
          }
          if (event.type === TouchType.Up) {
            this.eventType = 'Up'
          }
          if (event.type === TouchType.Move) {
            this.eventType = 'Move'
          }
          console.info(this.text = 'TouchType:' + this.eventType + '\nDistance between touch point and touch element:\nx: ' + event.touches[0].x + '\n' + 'y: ' + event.touches[0].y)
        })
      Text(this.text)
    }.height(200).width(350).padding({ left: 35, right: 35, top: 35 })
  }
}
```

![](figures/touch.gif)

