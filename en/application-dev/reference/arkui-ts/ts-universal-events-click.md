# Click Event<a name="EN-US_TOPIC_0000001192915110"></a>

>![](../../public_sys-resources/icon-note.gif) **NOTE:** 
>This event is supported since API version 7. Updates will be marked with a superscript to indicate their earliest API version.

## Required Permissions<a name="section781125411508"></a>

None

## Events<a name="section1823713918564"></a>

<a name="table268mcpsimp"></a>
<table><thead align="left"><tr id="row274mcpsimp"><th class="cellrowborder" colspan="2" valign="top" id="mcps1.1.5.1.1"><p id="p278mcpsimp"><a name="p278mcpsimp"></a><a name="p278mcpsimp"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.1.5.1.2"><p id="p240018113020"><a name="p240018113020"></a><a name="p240018113020"></a>Bubble Supported</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.1.5.1.3"><p id="p280mcpsimp"><a name="p280mcpsimp"></a><a name="p280mcpsimp"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row281mcpsimp"><td class="cellrowborder" colspan="2" valign="top" headers="mcps1.1.5.1.1 "><p id="p283mcpsimp"><a name="p283mcpsimp"></a><a name="p283mcpsimp"></a>onClick(callback: (event?: ClickEvent) =&gt; void)</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.1.5.1.2 "><p id="p240119143012"><a name="p240119143012"></a><a name="p240119143012"></a>No</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.1.5.1.3 "><p id="p287mcpsimp"><a name="p287mcpsimp"></a><a name="p287mcpsimp"></a>Called when a click event occurs. For details about the event parameters, see <a href="#li155675712535">ClickEvent object</a>.</p>
</td>
</tr>
</tbody>
</table>

-   <a name="li155675712535"></a>ClickEvent object

    <a name="table150414419378"></a>
    <table><thead align="left"><tr id="row250434411379"><th class="cellrowborder" valign="top" width="33.33333333333333%" id="mcps1.1.4.1.1"><p id="p17251053163714"><a name="p17251053163714"></a><a name="p17251053163714"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="33.33333333333333%" id="mcps1.1.4.1.2"><p id="p125175313377"><a name="p125175313377"></a><a name="p125175313377"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="33.33333333333333%" id="mcps1.1.4.1.3"><p id="p152518539379"><a name="p152518539379"></a><a name="p152518539379"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row25047446377"><td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.1.4.1.1 "><p id="p625120539377"><a name="p625120539377"></a><a name="p625120539377"></a>screenX</p>
    </td>
    <td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.1.4.1.2 "><p id="p7251105311371"><a name="p7251105311371"></a><a name="p7251105311371"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.1.4.1.3 "><p id="p62511553103710"><a name="p62511553103710"></a><a name="p62511553103710"></a>X coordinate of the click relative to the left edge of the screen.</p>
    </td>
    </tr>
    <tr id="row16504744143718"><td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.1.4.1.1 "><p id="p3251353193710"><a name="p3251353193710"></a><a name="p3251353193710"></a>screenY</p>
    </td>
    <td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.1.4.1.2 "><p id="p14252175323715"><a name="p14252175323715"></a><a name="p14252175323715"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.1.4.1.3 "><p id="p225275353713"><a name="p225275353713"></a><a name="p225275353713"></a>Y coordinate of the click relative to the upper edge of the screen.</p>
    </td>
    </tr>
    <tr id="row750454419376"><td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.1.4.1.1 "><p id="p11252195317371"><a name="p11252195317371"></a><a name="p11252195317371"></a>x</p>
    </td>
    <td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.1.4.1.2 "><p id="p025215313716"><a name="p025215313716"></a><a name="p025215313716"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.1.4.1.3 "><p id="p10252195316373"><a name="p10252195316373"></a><a name="p10252195316373"></a>X coordinate of the click relative to the left edge of the component being clicked.</p>
    </td>
    </tr>
    <tr id="row19505244163715"><td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.1.4.1.1 "><p id="p6252195312377"><a name="p6252195312377"></a><a name="p6252195312377"></a>y</p>
    </td>
    <td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.1.4.1.2 "><p id="p92521553113719"><a name="p92521553113719"></a><a name="p92521553113719"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.1.4.1.3 "><p id="p1925216537376"><a name="p1925216537376"></a><a name="p1925216537376"></a>Y coordinate of the click relative to the upper edge of the component being clicked.</p>
    </td>
    </tr>
    <tr id="row206951418174710"><td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.1.4.1.1 "><p id="p069611884717"><a name="p069611884717"></a><a name="p069611884717"></a>target<sup id="sup2028414336385"><a name="sup2028414336385"></a><a name="sup2028414336385"></a>8+</sup></p>
    </td>
    <td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.1.4.1.2 "><p id="p869611874717"><a name="p869611874717"></a><a name="p869611874717"></a><a href="#li552912253714">EventTarget</a></p>
    </td>
    <td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.1.4.1.3 "><p id="p136963189476"><a name="p136963189476"></a><a name="p136963189476"></a>Object of the element that is clicked.</p>
    </td>
    </tr>
    <tr id="row7505194418373"><td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.1.4.1.1 "><p id="p3252155316378"><a name="p3252155316378"></a><a name="p3252155316378"></a>timestamp</p>
    </td>
    <td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.1.4.1.2 "><p id="p16252453163717"><a name="p16252453163717"></a><a name="p16252453163717"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.1.4.1.3 "><p id="p13252115333711"><a name="p13252115333711"></a><a name="p13252115333711"></a>Timestamp of the event.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   <a name="li552912253714"></a>EventTarget object<sup>8+</sup>

    <a name="table16263713812"></a>
    <table><thead align="left"><tr id="row821037683"><th class="cellrowborder" valign="top" width="33.33333333333333%" id="mcps1.1.4.1.1"><p id="p14212371983"><a name="p14212371983"></a><a name="p14212371983"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="33.33333333333333%" id="mcps1.1.4.1.2"><p id="p62737480"><a name="p62737480"></a><a name="p62737480"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="33.33333333333333%" id="mcps1.1.4.1.3"><p id="p186742557817"><a name="p186742557817"></a><a name="p186742557817"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row2027375819"><td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.1.4.1.1 "><p id="p8214371488"><a name="p8214371488"></a><a name="p8214371488"></a>area</p>
    </td>
    <td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.1.4.1.2 "><p id="p1721375814"><a name="p1721375814"></a><a name="p1721375814"></a><a href="#li3196948121214">Area</a></p>
    </td>
    <td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.1.4.1.3 "><p id="p112133720810"><a name="p112133720810"></a><a name="p112133720810"></a>Area information of the target element.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   <a name="li3196948121214"></a>Area attributes<sup>8+</sup>

    <a name="table7114191821312"></a>
    <table><thead align="left"><tr id="row811471812132"><th class="cellrowborder" valign="top" width="33.33333333333333%" id="mcps1.1.4.1.1"><p id="p161151118191312"><a name="p161151118191312"></a><a name="p161151118191312"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="33.33333333333333%" id="mcps1.1.4.1.2"><p id="p6115141815136"><a name="p6115141815136"></a><a name="p6115141815136"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="33.33333333333333%" id="mcps1.1.4.1.3"><p id="p1197593717135"><a name="p1197593717135"></a><a name="p1197593717135"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row21151918111311"><td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.1.4.1.1 "><p id="p21151818111310"><a name="p21151818111310"></a><a name="p21151818111310"></a>width</p>
    </td>
    <td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.1.4.1.2 "><p id="p18115131819137"><a name="p18115131819137"></a><a name="p18115131819137"></a>Length</p>
    </td>
    <td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.1.4.1.3 "><p id="p31157183130"><a name="p31157183130"></a><a name="p31157183130"></a>Width of the target element.</p>
    </td>
    </tr>
    <tr id="row1211511814134"><td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.1.4.1.1 "><p id="p111511815137"><a name="p111511815137"></a><a name="p111511815137"></a>height</p>
    </td>
    <td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.1.4.1.2 "><p id="p811518188132"><a name="p811518188132"></a><a name="p811518188132"></a>Length</p>
    </td>
    <td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.1.4.1.3 "><p id="p14115191841319"><a name="p14115191841319"></a><a name="p14115191841319"></a>Height of the target element.</p>
    </td>
    </tr>
    <tr id="row611515184130"><td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.1.4.1.1 "><p id="p11151318201311"><a name="p11151318201311"></a><a name="p11151318201311"></a>pos</p>
    </td>
    <td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.1.4.1.2 "><p id="p19115181811313"><a name="p19115181811313"></a><a name="p19115181811313"></a><a href="#li7111244165">Position</a></p>
    </td>
    <td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.1.4.1.3 "><p id="p161151318191314"><a name="p161151318191314"></a><a name="p161151318191314"></a>Position of the upper left corner of the target element relative to that of the parent element.</p>
    </td>
    </tr>
    <tr id="row141151018171317"><td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.1.4.1.1 "><p id="p19115618131320"><a name="p19115618131320"></a><a name="p19115618131320"></a>globalPos</p>
    </td>
    <td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.1.4.1.2 "><p id="p1146417160254"><a name="p1146417160254"></a><a name="p1146417160254"></a><a href="#li7111244165">Position</a></p>
    </td>
    <td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.1.4.1.3 "><p id="p12115618141318"><a name="p12115618141318"></a><a name="p12115618141318"></a>Position of the upper left corner of the target element relative to that of the page.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   <a name="li7111244165"></a>Position attributes<sup>8+</sup>

    <a name="table1211352151616"></a>
    <table><thead align="left"><tr id="row142115526161"><th class="cellrowborder" valign="top" width="33.33333333333333%" id="mcps1.1.4.1.1"><p id="p14211252101612"><a name="p14211252101612"></a><a name="p14211252101612"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="33.33333333333333%" id="mcps1.1.4.1.2"><p id="p921155281618"><a name="p921155281618"></a><a name="p921155281618"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="33.33333333333333%" id="mcps1.1.4.1.3"><p id="p22115212162"><a name="p22115212162"></a><a name="p22115212162"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row192175211612"><td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.1.4.1.1 "><p id="p152118524166"><a name="p152118524166"></a><a name="p152118524166"></a>x</p>
    </td>
    <td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.1.4.1.2 "><p id="p82125215163"><a name="p82125215163"></a><a name="p82125215163"></a>Length</p>
    </td>
    <td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.1.4.1.3 "><p id="p921115219166"><a name="p921115219166"></a><a name="p921115219166"></a>X-coordinate.</p>
    </td>
    </tr>
    <tr id="row1721752161614"><td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.1.4.1.1 "><p id="p721155212168"><a name="p721155212168"></a><a name="p721155212168"></a>y</p>
    </td>
    <td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.1.4.1.2 "><p id="p1521125218168"><a name="p1521125218168"></a><a name="p1521125218168"></a>Length</p>
    </td>
    <td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.1.4.1.3 "><p id="p1921652181617"><a name="p1921652181617"></a><a name="p1921652181617"></a>Y-coordinate.</p>
    </td>
    </tr>
    </tbody>
    </table>


## Example<a name="section16900453182718"></a>

```
@Entry
@Component
struct ClickExample {
  @State text: string = ''

  build() {
    Column() {
      Button('Click').backgroundColor(0x2788D9).width(100).height(40)
        .onClick((event: ClickEvent) => {
          console.info(this.text = 'Click Point:' + '\n  screenX:' + event.screenX + '\n  screenY:' + event.screenY
          + '\n  x :' + event.x + '\n  y:' + event.y + '\ntarget:' + '\n  component globalPos:('
+ event.target.area.globalPos.x + ',' + event.target.area.globalPos.y + ')\n  width:'
          + event.target.area.width + '\n  height：' + event.target.area.height)
        })
      Text(this.text).padding(15)
    }.height(350).width('100%').padding(10)
  }
}
```

![](figures/en-us_image_0000001237355087.gif)

