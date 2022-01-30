# Scroll<a name="EN-US_TOPIC_0000001192595158"></a>

>![](../../public_sys-resources/icon-note.gif) **NOTE:** 
>This component is supported since API version 7. Updates will be marked with a superscript to indicate their earliest API version.

The  **<Scroll\>**  component scrolls the content when the layout size of a component exceeds the viewport of its parent component.

## Required Permissions<a name="section1073795814133"></a>

None

## Child Components<a name="section152511941148"></a>

This component supports only one child component.

## APIs<a name="section13412231148"></a>

Scroll\(scroller?: Scroller\)

## Attributes<a name="section186841370012"></a>

<a name="table0461840719"></a>
<table><thead align="left"><tr id="row10461406119"><th class="cellrowborder" valign="top" width="18.81188118811881%" id="mcps1.1.5.1.1"><p id="p114614406120"><a name="p114614406120"></a><a name="p114614406120"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="18.801880188018803%" id="mcps1.1.5.1.2"><p id="p1461740412"><a name="p1461740412"></a><a name="p1461740412"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="14.861486148614864%" id="mcps1.1.5.1.3"><p id="p1146194011113"><a name="p1146194011113"></a><a name="p1146194011113"></a>Default Value</p>
</th>
<th class="cellrowborder" valign="top" width="47.52475247524753%" id="mcps1.1.5.1.4"><p id="p1463401818"><a name="p1463401818"></a><a name="p1463401818"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row74616401011"><td class="cellrowborder" valign="top" width="18.81188118811881%" headers="mcps1.1.5.1.1 "><p id="p44619407119"><a name="p44619407119"></a><a name="p44619407119"></a>scrollable</p>
</td>
<td class="cellrowborder" valign="top" width="18.801880188018803%" headers="mcps1.1.5.1.2 "><p id="p114684017118"><a name="p114684017118"></a><a name="p114684017118"></a><a href="#li1464044171913">ScrollDirection</a></p>
</td>
<td class="cellrowborder" valign="top" width="14.861486148614864%" headers="mcps1.1.5.1.3 "><p id="p134610401415"><a name="p134610401415"></a><a name="p134610401415"></a>Vertical</p>
</td>
<td class="cellrowborder" valign="top" width="47.52475247524753%" headers="mcps1.1.5.1.4 "><p id="p74616407117"><a name="p74616407117"></a><a name="p74616407117"></a>Scroll method.</p>
</td>
</tr>
<tr id="row10854143717118"><td class="cellrowborder" valign="top" width="18.81188118811881%" headers="mcps1.1.5.1.1 "><p id="p1685403713116"><a name="p1685403713116"></a><a name="p1685403713116"></a>scrollBar</p>
</td>
<td class="cellrowborder" valign="top" width="18.801880188018803%" headers="mcps1.1.5.1.2 "><p id="p087765315"><a name="p087765315"></a><a name="p087765315"></a><a href="ts-appendix-enums.md#section122549529179">BarState</a></p>
</td>
<td class="cellrowborder" valign="top" width="14.861486148614864%" headers="mcps1.1.5.1.3 "><p id="p173471491823"><a name="p173471491823"></a><a name="p173471491823"></a>Auto</p>
</td>
<td class="cellrowborder" valign="top" width="47.52475247524753%" headers="mcps1.1.5.1.4 "><p id="p114261215315"><a name="p114261215315"></a><a name="p114261215315"></a>Scroll bar status.</p>
</td>
</tr>
<tr id="row11414540317"><td class="cellrowborder" valign="top" width="18.81188118811881%" headers="mcps1.1.5.1.1 "><p id="p19414194019118"><a name="p19414194019118"></a><a name="p19414194019118"></a>scrollBarColor</p>
</td>
<td class="cellrowborder" valign="top" width="18.801880188018803%" headers="mcps1.1.5.1.2 "><p id="p841454012118"><a name="p841454012118"></a><a name="p841454012118"></a>Color</p>
</td>
<td class="cellrowborder" valign="top" width="14.861486148614864%" headers="mcps1.1.5.1.3 "><p id="p194142401415"><a name="p194142401415"></a><a name="p194142401415"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="47.52475247524753%" headers="mcps1.1.5.1.4 "><p id="p7414340714"><a name="p7414340714"></a><a name="p7414340714"></a>Color of the scroll bar.</p>
</td>
</tr>
<tr id="row044484216112"><td class="cellrowborder" valign="top" width="18.81188118811881%" headers="mcps1.1.5.1.1 "><p id="p1944417421711"><a name="p1944417421711"></a><a name="p1944417421711"></a>scrollBarWidth</p>
</td>
<td class="cellrowborder" valign="top" width="18.801880188018803%" headers="mcps1.1.5.1.2 "><p id="p1386661639"><a name="p1386661639"></a><a name="p1386661639"></a>Length</p>
</td>
<td class="cellrowborder" valign="top" width="14.861486148614864%" headers="mcps1.1.5.1.3 "><p id="p4444542713"><a name="p4444542713"></a><a name="p4444542713"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="47.52475247524753%" headers="mcps1.1.5.1.4 "><p id="p11444642012"><a name="p11444642012"></a><a name="p11444642012"></a>Width of the scrollbar.</p>
</td>
</tr>
</tbody>
</table>

-   <a name="li1464044171913"></a>ScrollDirection

    <a name="table13104911929"></a>
    <table><thead align="left"><tr id="row11104011320"><th class="cellrowborder" valign="top" width="25.2%" id="mcps1.1.3.1.1"><p id="p11104171129"><a name="p11104171129"></a><a name="p11104171129"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="74.8%" id="mcps1.1.3.1.2"><p id="p610415110213"><a name="p610415110213"></a><a name="p610415110213"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row151040115210"><td class="cellrowborder" valign="top" width="25.2%" headers="mcps1.1.3.1.1 "><p id="p19104815217"><a name="p19104815217"></a><a name="p19104815217"></a>Horizontal</p>
    </td>
    <td class="cellrowborder" valign="top" width="74.8%" headers="mcps1.1.3.1.2 "><p id="p7104121622"><a name="p7104121622"></a><a name="p7104121622"></a>Only horizontal scrolling is supported.</p>
    </td>
    </tr>
    <tr id="row810411118218"><td class="cellrowborder" valign="top" width="25.2%" headers="mcps1.1.3.1.1 "><p id="p151041411125"><a name="p151041411125"></a><a name="p151041411125"></a>Vertical</p>
    </td>
    <td class="cellrowborder" valign="top" width="74.8%" headers="mcps1.1.3.1.2 "><p id="p1104711524"><a name="p1104711524"></a><a name="p1104711524"></a>Only vertical scrolling is supported.</p>
    </td>
    </tr>
    <tr id="row91041314217"><td class="cellrowborder" valign="top" width="25.2%" headers="mcps1.1.3.1.1 "><p id="p510441020"><a name="p510441020"></a><a name="p510441020"></a>None</p>
    </td>
    <td class="cellrowborder" valign="top" width="74.8%" headers="mcps1.1.3.1.2 "><p id="p5104813220"><a name="p5104813220"></a><a name="p5104813220"></a>Scrolling is disabled.</p>
    </td>
    </tr>
    </tbody>
    </table>


## Scroller<a name="section123902548458"></a>

Controller of the scrollable container component. You can bind this component to the container component and use it to control the scrolling of the container component. Currently, this component can be bound to the  **<List\>**  and  **<Scroll\>**  components.

### Creating an Object<a name="section1241383014362"></a>

```
scroller: Scroller = new Scroller()
```

### scroller.scrollTo<a name="section15413203010365"></a>

scrollTo\(value: \{ xOffset: number | string, yOffset: number | string, animation?: \{ duration: number, curve: Curve \} \}\): void

Scrolls to the specified position.

-   Parameters

    <a name="table1413230103617"></a>
    <table><thead align="left"><tr id="row20414203010366"><th class="cellrowborder" valign="top" width="16.11%" id="mcps1.1.6.1.1"><p id="p04141430183615"><a name="p04141430183615"></a><a name="p04141430183615"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="21.43%" id="mcps1.1.6.1.2"><p id="p241473011360"><a name="p241473011360"></a><a name="p241473011360"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="7.08%" id="mcps1.1.6.1.3"><p id="p941493017363"><a name="p941493017363"></a><a name="p941493017363"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="13.170000000000002%" id="mcps1.1.6.1.4"><p id="p4414173019365"><a name="p4414173019365"></a><a name="p4414173019365"></a>Default Value</p>
    </th>
    <th class="cellrowborder" valign="top" width="42.21%" id="mcps1.1.6.1.5"><p id="p1941493016367"><a name="p1941493016367"></a><a name="p1941493016367"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row841473010365"><td class="cellrowborder" valign="top" width="16.11%" headers="mcps1.1.6.1.1 "><p id="p18414143015360"><a name="p18414143015360"></a><a name="p18414143015360"></a>xOffset</p>
    </td>
    <td class="cellrowborder" valign="top" width="21.43%" headers="mcps1.1.6.1.2 "><p id="p18414830193611"><a name="p18414830193611"></a><a name="p18414830193611"></a>Length</p>
    </td>
    <td class="cellrowborder" valign="top" width="7.08%" headers="mcps1.1.6.1.3 "><p id="p14414130153613"><a name="p14414130153613"></a><a name="p14414130153613"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="13.170000000000002%" headers="mcps1.1.6.1.4 "><p id="p154141030173610"><a name="p154141030173610"></a><a name="p154141030173610"></a>-</p>
    </td>
    <td class="cellrowborder" valign="top" width="42.21%" headers="mcps1.1.6.1.5 "><p id="p114143301368"><a name="p114143301368"></a><a name="p114143301368"></a>Horizontal scrolling offset.</p>
    </td>
    </tr>
    <tr id="row44142306366"><td class="cellrowborder" valign="top" width="16.11%" headers="mcps1.1.6.1.1 "><p id="p16414133023611"><a name="p16414133023611"></a><a name="p16414133023611"></a>yOffset</p>
    </td>
    <td class="cellrowborder" valign="top" width="21.43%" headers="mcps1.1.6.1.2 "><p id="p12414330123614"><a name="p12414330123614"></a><a name="p12414330123614"></a>Length</p>
    </td>
    <td class="cellrowborder" valign="top" width="7.08%" headers="mcps1.1.6.1.3 "><p id="p1041423043614"><a name="p1041423043614"></a><a name="p1041423043614"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="13.170000000000002%" headers="mcps1.1.6.1.4 "><p id="p10414103083617"><a name="p10414103083617"></a><a name="p10414103083617"></a>-</p>
    </td>
    <td class="cellrowborder" valign="top" width="42.21%" headers="mcps1.1.6.1.5 "><p id="p154141930133619"><a name="p154141930133619"></a><a name="p154141930133619"></a>Vertical scrolling offset.</p>
    </td>
    </tr>
    <tr id="row0414163019369"><td class="cellrowborder" valign="top" width="16.11%" headers="mcps1.1.6.1.1 "><p id="p141433010365"><a name="p141433010365"></a><a name="p141433010365"></a>animation</p>
    </td>
    <td class="cellrowborder" valign="top" width="21.43%" headers="mcps1.1.6.1.2 "><p id="p17415430163612"><a name="p17415430163612"></a><a name="p17415430163612"></a>{</p>
    <p id="p441593053612"><a name="p441593053612"></a><a name="p441593053612"></a>duration: number,</p>
    <p id="p17415113093611"><a name="p17415113093611"></a><a name="p17415113093611"></a>curve: <a href="ts-animatorproperty.md#li16621545614">Curve</a> | CubicBezier | SpringCurve</p>
    <p id="p15415123010367"><a name="p15415123010367"></a><a name="p15415123010367"></a>}</p>
    </td>
    <td class="cellrowborder" valign="top" width="7.08%" headers="mcps1.1.6.1.3 "><p id="p1441573073612"><a name="p1441573073612"></a><a name="p1441573073612"></a>No</p>
    </td>
    <td class="cellrowborder" valign="top" width="13.170000000000002%" headers="mcps1.1.6.1.4 "><p id="p144151730173619"><a name="p144151730173619"></a><a name="p144151730173619"></a>-</p>
    </td>
    <td class="cellrowborder" valign="top" width="42.21%" headers="mcps1.1.6.1.5 "><p id="p341519302361"><a name="p341519302361"></a><a name="p341519302361"></a>Animation configuration, which includes the following:</p>
    <a name="ul154152304364"></a><a name="ul154152304364"></a><ul id="ul154152304364"><li><strong id="b10320330393"><a name="b10320330393"></a><a name="b10320330393"></a>duration</strong>: scrolling duration.</li><li><strong id="b641674418913"><a name="b641674418913"></a><a name="b641674418913"></a>curve</strong>: scrolling curve.</li></ul>
    </td>
    </tr>
    </tbody>
    </table>


### scroller.scrollEdge<a name="section1441583018367"></a>

scrollEdge\(value: Edge\): void

Scrolls to the edge of the container.

-   Parameters

    <a name="table5415133010363"></a>
    <table><thead align="left"><tr id="row164151300364"><th class="cellrowborder" valign="top" width="16.11%" id="mcps1.1.6.1.1"><p id="p64159300368"><a name="p64159300368"></a><a name="p64159300368"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="14.01%" id="mcps1.1.6.1.2"><p id="p18415183053613"><a name="p18415183053613"></a><a name="p18415183053613"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="14.499999999999998%" id="mcps1.1.6.1.3"><p id="p18415183019366"><a name="p18415183019366"></a><a name="p18415183019366"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="13.170000000000002%" id="mcps1.1.6.1.4"><p id="p1841533073620"><a name="p1841533073620"></a><a name="p1841533073620"></a>Default Value</p>
    </th>
    <th class="cellrowborder" valign="top" width="42.21%" id="mcps1.1.6.1.5"><p id="p541513019368"><a name="p541513019368"></a><a name="p541513019368"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row641543093614"><td class="cellrowborder" valign="top" width="16.11%" headers="mcps1.1.6.1.1 "><p id="p641512305364"><a name="p641512305364"></a><a name="p641512305364"></a>value</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.01%" headers="mcps1.1.6.1.2 "><p id="p1041573053612"><a name="p1041573053612"></a><a name="p1041573053612"></a>Edge</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.499999999999998%" headers="mcps1.1.6.1.3 "><p id="p124152307361"><a name="p124152307361"></a><a name="p124152307361"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="13.170000000000002%" headers="mcps1.1.6.1.4 "><p id="p5416130133613"><a name="p5416130133613"></a><a name="p5416130133613"></a>-</p>
    </td>
    <td class="cellrowborder" valign="top" width="42.21%" headers="mcps1.1.6.1.5 "><p id="p1241673011362"><a name="p1241673011362"></a><a name="p1241673011362"></a>Edge position to scroll to.</p>
    </td>
    </tr>
    </tbody>
    </table>


### scroller.scrollPage<a name="section2416163018368"></a>

scrollPage\(value: \{ next: boolean \}\): void

Scrolls to the next or previous page.

-   Parameters

    <a name="table7416530183618"></a>
    <table><thead align="left"><tr id="row1741603013364"><th class="cellrowborder" valign="top" width="16.11%" id="mcps1.1.6.1.1"><p id="p4416163013369"><a name="p4416163013369"></a><a name="p4416163013369"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="14.01%" id="mcps1.1.6.1.2"><p id="p16416193083619"><a name="p16416193083619"></a><a name="p16416193083619"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="14.499999999999998%" id="mcps1.1.6.1.3"><p id="p641633043614"><a name="p641633043614"></a><a name="p641633043614"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="13.170000000000002%" id="mcps1.1.6.1.4"><p id="p841683033618"><a name="p841683033618"></a><a name="p841683033618"></a>Default Value</p>
    </th>
    <th class="cellrowborder" valign="top" width="42.21%" id="mcps1.1.6.1.5"><p id="p341616304366"><a name="p341616304366"></a><a name="p341616304366"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row441614306360"><td class="cellrowborder" valign="top" width="16.11%" headers="mcps1.1.6.1.1 "><p id="p11416103023620"><a name="p11416103023620"></a><a name="p11416103023620"></a>next</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.01%" headers="mcps1.1.6.1.2 "><p id="p16416830173615"><a name="p16416830173615"></a><a name="p16416830173615"></a>boolean</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.499999999999998%" headers="mcps1.1.6.1.3 "><p id="p7416123010364"><a name="p7416123010364"></a><a name="p7416123010364"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="13.170000000000002%" headers="mcps1.1.6.1.4 "><p id="p17416193043615"><a name="p17416193043615"></a><a name="p17416193043615"></a>-</p>
    </td>
    <td class="cellrowborder" valign="top" width="42.21%" headers="mcps1.1.6.1.5 "><p id="p1941613011362"><a name="p1941613011362"></a><a name="p1941613011362"></a>Whether to turn to the next page. The value <strong id="b13842341565"><a name="b13842341565"></a><a name="b13842341565"></a>true</strong> means to turn to the next page, and the value <strong id="b17843945613"><a name="b17843945613"></a><a name="b17843945613"></a>false</strong> means to turn to the previous page.</p>
    </td>
    </tr>
    </tbody>
    </table>


### scroller.currentOffset<a name="section041711305362"></a>

scroller.currentOffset\(\): Object

Obtains the scrolling offset.

-   Return values

    <a name="table14417163018362"></a>
    <table><thead align="left"><tr id="row6417330153614"><th class="cellrowborder" valign="top" width="25.2%" id="mcps1.1.3.1.1"><p id="p1841743053617"><a name="p1841743053617"></a><a name="p1841743053617"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="74.8%" id="mcps1.1.3.1.2"><p id="p1041753016364"><a name="p1041753016364"></a><a name="p1041753016364"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row34171130163610"><td class="cellrowborder" valign="top" width="25.2%" headers="mcps1.1.3.1.1 "><p id="p1841712301363"><a name="p1841712301363"></a><a name="p1841712301363"></a>{</p>
    <p id="p194171230153610"><a name="p194171230153610"></a><a name="p194171230153610"></a>xOffset: number,</p>
    <p id="p10417133018363"><a name="p10417133018363"></a><a name="p10417133018363"></a>yOffset: number</p>
    <p id="p9417173016361"><a name="p9417173016361"></a><a name="p9417173016361"></a>}</p>
    </td>
    <td class="cellrowborder" valign="top" width="74.8%" headers="mcps1.1.3.1.2 "><p id="p341717302367"><a name="p341717302367"></a><a name="p341717302367"></a><strong id="b635116556121"><a name="b635116556121"></a><a name="b635116556121"></a>xOffset</strong>: horizontal scrolling offset.</p>
    <p id="p19417163043618"><a name="p19417163043618"></a><a name="p19417163043618"></a><strong id="b97929165134"><a name="b97929165134"></a><a name="b97929165134"></a>yOffset</strong>: vertical scrolling offset.</p>
    </td>
    </tr>
    </tbody>
    </table>


### scroller.scrollToIndex<a name="section10417103010368"></a>

scroller.scrollToIndex\(value: number\): void

Scrolls to the specified index.

>![](../../public_sys-resources/icon-note.gif) **NOTE:** 
>Only the  **<List\>**  component is supported.

-   Parameters

    <a name="table4417430173610"></a>
    <table><thead align="left"><tr id="row114187306362"><th class="cellrowborder" valign="top" width="16.11%" id="mcps1.1.6.1.1"><p id="p1241863013366"><a name="p1241863013366"></a><a name="p1241863013366"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="14.01%" id="mcps1.1.6.1.2"><p id="p141843023613"><a name="p141843023613"></a><a name="p141843023613"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="14.499999999999998%" id="mcps1.1.6.1.3"><p id="p84181230183615"><a name="p84181230183615"></a><a name="p84181230183615"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="13.170000000000002%" id="mcps1.1.6.1.4"><p id="p24181030103616"><a name="p24181030103616"></a><a name="p24181030103616"></a>Default Value</p>
    </th>
    <th class="cellrowborder" valign="top" width="42.21%" id="mcps1.1.6.1.5"><p id="p204181830113611"><a name="p204181830113611"></a><a name="p204181830113611"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row16418183093611"><td class="cellrowborder" valign="top" width="16.11%" headers="mcps1.1.6.1.1 "><p id="p341833013365"><a name="p341833013365"></a><a name="p341833013365"></a>value</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.01%" headers="mcps1.1.6.1.2 "><p id="p104181530143612"><a name="p104181530143612"></a><a name="p104181530143612"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.499999999999998%" headers="mcps1.1.6.1.3 "><p id="p1441863014365"><a name="p1441863014365"></a><a name="p1441863014365"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="13.170000000000002%" headers="mcps1.1.6.1.4 "><p id="p2041873010365"><a name="p2041873010365"></a><a name="p2041873010365"></a>-</p>
    </td>
    <td class="cellrowborder" valign="top" width="42.21%" headers="mcps1.1.6.1.5 "><p id="p6418193017364"><a name="p6418193017364"></a><a name="p6418193017364"></a>Index of the item to be scrolled to in the list.</p>
    </td>
    </tr>
    </tbody>
    </table>


## Events<a name="section142174333711"></a>

<a name="table2605mcpsimp"></a>
<table><thead align="left"><tr id="row2611mcpsimp"><th class="cellrowborder" colspan="2" valign="top" id="mcps1.1.4.1.1"><p id="p2615mcpsimp"><a name="p2615mcpsimp"></a><a name="p2615mcpsimp"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.1.4.1.2"><p id="p2617mcpsimp"><a name="p2617mcpsimp"></a><a name="p2617mcpsimp"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row2618mcpsimp"><td class="cellrowborder" colspan="2" valign="top" headers="mcps1.1.4.1.1 "><p id="p2620mcpsimp"><a name="p2620mcpsimp"></a><a name="p2620mcpsimp"></a>onScroll(xOffset: number, yOffset: number) =&gt; void</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.1.4.1.2 "><p id="p2624mcpsimp"><a name="p2624mcpsimp"></a><a name="p2624mcpsimp"></a>Invoked to return the horizontal and vertical offsets during scrolling when the specified scroll event occurs.</p>
</td>
</tr>
<tr id="row114319381836"><td class="cellrowborder" colspan="2" valign="top" headers="mcps1.1.4.1.1 "><p id="p9434386312"><a name="p9434386312"></a><a name="p9434386312"></a>onScrollEdge(side: Edge) =&gt; void</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.1.4.1.2 "><p id="p174311388317"><a name="p174311388317"></a><a name="p174311388317"></a>Invoked when an event of scrolling to the edge occurs.</p>
</td>
</tr>
<tr id="row9211043639"><td class="cellrowborder" colspan="2" valign="top" headers="mcps1.1.4.1.1 "><p id="p20211243636"><a name="p20211243636"></a><a name="p20211243636"></a>onScrollEnd() =&gt; void</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.1.4.1.2 "><p id="p1221112432312"><a name="p1221112432312"></a><a name="p1221112432312"></a>Invoked when scrolling stops.</p>
</td>
</tr>
</tbody>
</table>

## Example<a name="section11271205310156"></a>

```
@Entry
@Component
struct ScrollExample {
  scroller: Scroller = new Scroller()
  private arr: number[] = [0, 1, 2, 3, 4, 5, 6, 7, 8, 9]

  build() {
    Stack({ alignContent: Alignment.TopStart }) {
      Scroll(this.scroller) {
        Column() {
          ForEach(this.arr, (item) => {
            Text(item.toString())
              .width('90%').height(150).backgroundColor(0xFFFFFF)
              .borderRadius(15).fontSize(16).textAlign(TextAlign.Center)
              .margin({ top: 10 })
          }, item => item)
        }.width('100%')
      }
      .scrollable(ScrollDirection.Vertical).scrollBar(BarState.On)
      .scrollBarColor(Color.Gray).scrollBarWidth(30)
      .onScroll((xOffset: number, yOffset: number) => {
        console.info(xOffset + ' ' + yOffset)
      })
      .onScrollEdge((side: Edge) => {
        console.info('To the edge')
      })
      .onScrollEnd(() => {
        console.info('Scroll Stop')
      })

      Button('scroll 100')
        .onClick(() => {// Click to scroll down 100.0.
          this.scroller.scrollTo({ xOffset: 0, yOffset: this.scroller.currentOffset().yOffset + 100 })
        })
        .margin({ top: 10, left: 20 })
      Button('back top')
        .onClick(() => {// Click to go back to the top.
          this.scroller.scrollEdge(Edge.Top)
        })
        .margin({ top: 60, left: 20 })
      Button('next page')
        .onClick(() => {// Click to scroll down to the bottom.
          this.scroller.scrollPage({ next: true })
        })
        .margin({ top: 110, left: 20 })
    }.width('100%').height('100%').backgroundColor(0xDCDCDC)
  }
}
```

![](figures/scroll.gif)

