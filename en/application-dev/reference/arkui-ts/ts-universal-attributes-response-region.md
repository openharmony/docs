# Touch Target<a name="EN-US_TOPIC_0000001192595182"></a>

>![](../../public_sys-resources/icon-note.gif) **NOTE:** 
>This attribute is supported since API version 8. Updates will be marked with a superscript to indicate their earliest API version.

You can set the touch target for components that support universal click events, touch events, and gestures.

## Required Permissions<a name="section781125411508"></a>

None

## Attributes<a name="section6820191711316"></a>

<a name="table3548mcpsimp"></a>
<table><thead align="left"><tr id="row3556mcpsimp"><th class="cellrowborder" valign="top" width="15.120000000000001%" id="mcps1.1.5.1.1"><p id="p3558mcpsimp"><a name="p3558mcpsimp"></a><a name="p3558mcpsimp"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="18.05%" id="mcps1.1.5.1.2"><p id="p3560mcpsimp"><a name="p3560mcpsimp"></a><a name="p3560mcpsimp"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="18.22%" id="mcps1.1.5.1.3"><p id="p3562mcpsimp"><a name="p3562mcpsimp"></a><a name="p3562mcpsimp"></a>Default Value</p>
</th>
<th class="cellrowborder" valign="top" width="48.61%" id="mcps1.1.5.1.4"><p id="p3566mcpsimp"><a name="p3566mcpsimp"></a><a name="p3566mcpsimp"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row3567mcpsimp"><td class="cellrowborder" valign="top" width="15.120000000000001%" headers="mcps1.1.5.1.1 "><p id="p7937194712382"><a name="p7937194712382"></a><a name="p7937194712382"></a>responseRegion</p>
</td>
<td class="cellrowborder" valign="top" width="18.05%" headers="mcps1.1.5.1.2 "><p id="p1993734718386"><a name="p1993734718386"></a><a name="p1993734718386"></a>Array&lt;Rectangle&gt; | <a href="#li11163114695111">Rectangle</a></p>
</td>
<td class="cellrowborder" valign="top" width="18.22%" headers="mcps1.1.5.1.3 "><p id="p123675110476"><a name="p123675110476"></a><a name="p123675110476"></a>{</p>
<p id="p1896253114716"><a name="p1896253114716"></a><a name="p1896253114716"></a>x: 0,</p>
<p id="p46656558470"><a name="p46656558470"></a><a name="p46656558470"></a>y：0,</p>
<p id="p1142411112430"><a name="p1142411112430"></a><a name="p1142411112430"></a>width：'100%',</p>
<p id="p31570811444"><a name="p31570811444"></a><a name="p31570811444"></a>height：'100%'</p>
<p id="p106108613276"><a name="p106108613276"></a><a name="p106108613276"></a>}</p>
</td>
<td class="cellrowborder" valign="top" width="48.61%" headers="mcps1.1.5.1.4 "><p id="p3577mcpsimp"><a name="p3577mcpsimp"></a><a name="p3577mcpsimp"></a>Indicates one or more touch targets, including their location and size.</p>
<div class="note" id="note362494014496"><a name="note362494014496"></a><a name="note362494014496"></a><span class="notetitle"> NOTE: </span><div class="notebody"><p id="p945217554319"><a name="p945217554319"></a><a name="p945217554319"></a>The percentage is measured relative to the component itself.</p>
<p id="p26671365154"><a name="p26671365154"></a><a name="p26671365154"></a><strong id="b1789155982819"><a name="b1789155982819"></a><a name="b1789155982819"></a>x</strong> and <strong id="b13886151112910"><a name="b13886151112910"></a><a name="b13886151112910"></a>y</strong> can be set to a positive or negative percentage value. For example, when <strong id="b1862536112916"><a name="b1862536112916"></a><a name="b1862536112916"></a>x</strong> is set to <strong id="b72301745193017"><a name="b72301745193017"></a><a name="b72301745193017"></a>'100%'</strong>, the touch target is offset from the right edge of the component by the component's width. When <strong id="b16863154414"><a name="b16863154414"></a><a name="b16863154414"></a>x</strong> is set to <strong id="b17555554417"><a name="b17555554417"></a><a name="b17555554417"></a>'-100%'</strong>, the touch target is offset from the left edge of the component by the component's width. When <strong id="b31941833174511"><a name="b31941833174511"></a><a name="b31941833174511"></a>y</strong> is set to <strong id="b61941433104514"><a name="b61941433104514"></a><a name="b61941433104514"></a>'100%'</strong>, the touch target is offset from the bottom edge of the component by the component's height. When <strong id="b219418330458"><a name="b219418330458"></a><a name="b219418330458"></a>y</strong> is set to <strong id="b191941933204510"><a name="b191941933204510"></a><a name="b191941933204510"></a>'-100%'</strong>, the touch target is offset from the top edge of the component by the component's height.</p>
<p id="p14618143735213"><a name="p14618143735213"></a><a name="p14618143735213"></a><strong id="b147841237155720"><a name="b147841237155720"></a><a name="b147841237155720"></a>width</strong> and <strong id="b6600740125710"><a name="b6600740125710"></a><a name="b6600740125710"></a>height</strong> can only be set to positive percentage values. For example, when <strong id="b1868265745715"><a name="b1868265745715"></a><a name="b1868265745715"></a>width</strong> is set to <strong id="b9790182584216"><a name="b9790182584216"></a><a name="b9790182584216"></a>'100%'</strong>, the width of the touch target is equal to that of the component; when <strong id="b183581058102511"><a name="b183581058102511"></a><a name="b183581058102511"></a>height</strong> is set to <strong id="b73582588255"><a name="b73582588255"></a><a name="b73582588255"></a>'100%'</strong>, the height of the touch target is equal to that of the component.</p>
</div></div>
</td>
</tr>
</tbody>
</table>

-   <a name="li11163114695111"></a>Rectangle object

    <a name="table197411342193817"></a>
    <table><thead align="left"><tr id="row374111426387"><th class="cellrowborder" valign="top" width="12.601260126012601%" id="mcps1.1.6.1.1"><p id="p15741134223813"><a name="p15741134223813"></a><a name="p15741134223813"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="15.791579157915791%" id="mcps1.1.6.1.2"><p id="p814413115312"><a name="p814413115312"></a><a name="p814413115312"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="6.950695069506951%" id="mcps1.1.6.1.3"><p id="p034985833218"><a name="p034985833218"></a><a name="p034985833218"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="7.520752075207521%" id="mcps1.1.6.1.4"><p id="p187421851338"><a name="p187421851338"></a><a name="p187421851338"></a>Default Value</p>
    </th>
    <th class="cellrowborder" valign="top" width="57.13571357135714%" id="mcps1.1.6.1.5"><p id="p474164215383"><a name="p474164215383"></a><a name="p474164215383"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row1774194233815"><td class="cellrowborder" valign="top" width="12.601260126012601%" headers="mcps1.1.6.1.1 "><p id="p1674111428389"><a name="p1674111428389"></a><a name="p1674111428389"></a>x</p>
    </td>
    <td class="cellrowborder" valign="top" width="15.791579157915791%" headers="mcps1.1.6.1.2 "><p id="p14141013145315"><a name="p14141013145315"></a><a name="p14141013145315"></a>Length</p>
    </td>
    <td class="cellrowborder" valign="top" width="6.950695069506951%" headers="mcps1.1.6.1.3 "><p id="p11349125893214"><a name="p11349125893214"></a><a name="p11349125893214"></a>No</p>
    </td>
    <td class="cellrowborder" valign="top" width="7.520752075207521%" headers="mcps1.1.6.1.4 "><p id="p187421955339"><a name="p187421955339"></a><a name="p187421955339"></a>0vp</p>
    </td>
    <td class="cellrowborder" valign="top" width="57.13571357135714%" headers="mcps1.1.6.1.5 "><p id="p18741134243810"><a name="p18741134243810"></a><a name="p18741134243810"></a>X coordinate of the touch point relative to the left edge of the component.</p>
    </td>
    </tr>
    <tr id="row1741442113814"><td class="cellrowborder" valign="top" width="12.601260126012601%" headers="mcps1.1.6.1.1 "><p id="p87418424388"><a name="p87418424388"></a><a name="p87418424388"></a>y</p>
    </td>
    <td class="cellrowborder" valign="top" width="15.791579157915791%" headers="mcps1.1.6.1.2 "><p id="p6141113175310"><a name="p6141113175310"></a><a name="p6141113175310"></a>Length</p>
    </td>
    <td class="cellrowborder" valign="top" width="6.950695069506951%" headers="mcps1.1.6.1.3 "><p id="p193490583320"><a name="p193490583320"></a><a name="p193490583320"></a>No</p>
    </td>
    <td class="cellrowborder" valign="top" width="7.520752075207521%" headers="mcps1.1.6.1.4 "><p id="p17742125143317"><a name="p17742125143317"></a><a name="p17742125143317"></a>0vp</p>
    </td>
    <td class="cellrowborder" valign="top" width="57.13571357135714%" headers="mcps1.1.6.1.5 "><p id="p6741104213389"><a name="p6741104213389"></a><a name="p6741104213389"></a>Y coordinate of the touch point relative to the left edge of the component.</p>
    </td>
    </tr>
    <tr id="row12741542203810"><td class="cellrowborder" valign="top" width="12.601260126012601%" headers="mcps1.1.6.1.1 "><p id="p12742342103816"><a name="p12742342103816"></a><a name="p12742342103816"></a>width</p>
    </td>
    <td class="cellrowborder" valign="top" width="15.791579157915791%" headers="mcps1.1.6.1.2 "><p id="p121471317537"><a name="p121471317537"></a><a name="p121471317537"></a>Length</p>
    </td>
    <td class="cellrowborder" valign="top" width="6.950695069506951%" headers="mcps1.1.6.1.3 "><p id="p18349105818327"><a name="p18349105818327"></a><a name="p18349105818327"></a>No</p>
    </td>
    <td class="cellrowborder" valign="top" width="7.520752075207521%" headers="mcps1.1.6.1.4 "><p id="p17742254334"><a name="p17742254334"></a><a name="p17742254334"></a>100%</p>
    </td>
    <td class="cellrowborder" valign="top" width="57.13571357135714%" headers="mcps1.1.6.1.5 "><p id="p157426425387"><a name="p157426425387"></a><a name="p157426425387"></a>Width of the touch target.</p>
    </td>
    </tr>
    <tr id="row11106175711531"><td class="cellrowborder" valign="top" width="12.601260126012601%" headers="mcps1.1.6.1.1 "><p id="p61068578532"><a name="p61068578532"></a><a name="p61068578532"></a>height</p>
    </td>
    <td class="cellrowborder" valign="top" width="15.791579157915791%" headers="mcps1.1.6.1.2 "><p id="p1710613574534"><a name="p1710613574534"></a><a name="p1710613574534"></a>Length</p>
    </td>
    <td class="cellrowborder" valign="top" width="6.950695069506951%" headers="mcps1.1.6.1.3 "><p id="p16349155873214"><a name="p16349155873214"></a><a name="p16349155873214"></a>No</p>
    </td>
    <td class="cellrowborder" valign="top" width="7.520752075207521%" headers="mcps1.1.6.1.4 "><p id="p374217511334"><a name="p374217511334"></a><a name="p374217511334"></a>100%</p>
    </td>
    <td class="cellrowborder" valign="top" width="57.13571357135714%" headers="mcps1.1.6.1.5 "><p id="p1710617573533"><a name="p1710617573533"></a><a name="p1710617573533"></a>Height of the touch target.</p>
    </td>
    </tr>
    </tbody>
    </table>

    >![](../../public_sys-resources/icon-note.gif) **NOTE:** 
    >When both  **x**  and  **y**  are set to positive values, the entire touch target offsets towards the lower right corner of the component. How much the touch target offsets is subject to the set values.


## Example<a name="section18306182803217"></a>

```
@Entry
@Component
struct ResponseRegionExample {
  build() {
    Column() {
        Toggle({ type: ToggleType.Checkbox, isOn: true })
          .selectedColor(0x39a2db)
          .backgroundColor(0xAFEEEE)
          .responseRegion({ x: 1.0, y: 1.0, width: 400, height: 400 })
          .onChange((isOn: boolean) => {
            console.info('Component status:' + isOn)
          })
    }.width('100%').margin({ top: 5 })
  }
}
```

![](figures/gif1.gif)

