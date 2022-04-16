# list-item<a name="EN-US_TOPIC_0000001127125046"></a>

**<list-item\>**  is a child component of the  **<[list](js-components-container-list.md)\>**  component and is used to display items in a list. You can customize the width of each  **<list-item\>**. However, if you retain the default value  **stretch**  of  **align-items**  for the parent component  **<list\>**, the width of  **<list-item\>**  is equal to that of  **<list\>**. You can set  **align-items**  to other values rather than  **stretch**  to make the customized  **<list-item-group\>**  width take effect.

## Required Permissions<a name="section11257113618419"></a>

None

## Child Components<a name="section9288143101012"></a>

This component supports only one child component.

## Attributes<a name="section2907183951110"></a>

In addition to the attributes in  [Universal Attributes](js-components-common-attributes.md), the following attributes are supported.

<a name="table1868413436126"></a>
<table><thead align="left"><tr id="row7684164319127"><th class="cellrowborder" valign="top" width="23.119999999999997%" id="mcps1.1.6.1.1"><p id="en-us_topic_0000001058340523_a9ba8c579217b4b8b841b035f1d28b20e"><a name="en-us_topic_0000001058340523_a9ba8c579217b4b8b841b035f1d28b20e"></a><a name="en-us_topic_0000001058340523_a9ba8c579217b4b8b841b035f1d28b20e"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="23.119999999999997%" id="mcps1.1.6.1.2"><p id="en-us_topic_0000001058340523_a633002333b024497914a4b172446f14e"><a name="en-us_topic_0000001058340523_a633002333b024497914a4b172446f14e"></a><a name="en-us_topic_0000001058340523_a633002333b024497914a4b172446f14e"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="10.48%" id="mcps1.1.6.1.3"><p id="en-us_topic_0000001058340523_a4950f7884c6540b9ad523ac34657d952"><a name="en-us_topic_0000001058340523_a4950f7884c6540b9ad523ac34657d952"></a><a name="en-us_topic_0000001058340523_a4950f7884c6540b9ad523ac34657d952"></a>Default Value</p>
</th>
<th class="cellrowborder" valign="top" width="7.5200000000000005%" id="mcps1.1.6.1.4"><p id="p3684134381211"><a name="p3684134381211"></a><a name="p3684134381211"></a>Mandatory</p>
</th>
<th class="cellrowborder" valign="top" width="35.76%" id="mcps1.1.6.1.5"><p id="en-us_topic_0000001058340523_a1313564aa9404a338447087d5918c17d"><a name="en-us_topic_0000001058340523_a1313564aa9404a338447087d5918c17d"></a><a name="en-us_topic_0000001058340523_a1313564aa9404a338447087d5918c17d"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row14827156171315"><td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.1 "><p id="p2095581381314"><a name="p2095581381314"></a><a name="p2095581381314"></a>type</p>
</td>
<td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.2 "><p id="p1956151315137"><a name="p1956151315137"></a><a name="p1956151315137"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="10.48%" headers="mcps1.1.6.1.3 "><p id="p8956111351319"><a name="p8956111351319"></a><a name="p8956111351319"></a>default</p>
</td>
<td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.6.1.4 "><p id="p14956141314133"><a name="p14956141314133"></a><a name="p14956141314133"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="35.76%" headers="mcps1.1.6.1.5 "><p id="p1595671312135"><a name="p1595671312135"></a><a name="p1595671312135"></a>Type of the list-item. A list can contain multiple list-item types. The same type of list items should have the same view layout after being rendered. When the type is fixed, replace the <strong id="b1152364710610"><a name="b1152364710610"></a><a name="b1152364710610"></a>if</strong> attribute with the <strong id="b8963450964"><a name="b8963450964"></a><a name="b8963450964"></a>show</strong> attribute to ensure that the view layout remains unchanged.</p>
</td>
</tr>
<tr id="row182818671318"><td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.1 "><p id="p209561313171315"><a name="p209561313171315"></a><a name="p209561313171315"></a>primary</p>
</td>
<td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.2 "><p id="p195631313131"><a name="p195631313131"></a><a name="p195631313131"></a>boolean</p>
</td>
<td class="cellrowborder" valign="top" width="10.48%" headers="mcps1.1.6.1.3 "><p id="p7956181316134"><a name="p7956181316134"></a><a name="p7956181316134"></a>false</p>
</td>
<td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.6.1.4 "><p id="p1895681321315"><a name="p1895681321315"></a><a name="p1895681321315"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="35.76%" headers="mcps1.1.6.1.5 "><p id="p995671314134"><a name="p995671314134"></a><a name="p995671314134"></a>The value <strong id="b133217164716"><a name="b133217164716"></a><a name="b133217164716"></a>true</strong> indicates that the item is the primary item in the group, which is the item that appears in a collapsed group. If there is more than one item marked as primary, the first one is the primary item. If there is no item marked as primary, the first item is the primary item.</p>
</td>
</tr>
<tr id="row16295321132"><td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.1 "><p id="p16956101311310"><a name="p16956101311310"></a><a name="p16956101311310"></a>section</p>
</td>
<td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.2 "><p id="p195611135133"><a name="p195611135133"></a><a name="p195611135133"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="10.48%" headers="mcps1.1.6.1.3 "><p id="p209561413191315"><a name="p209561413191315"></a><a name="p209561413191315"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.6.1.4 "><p id="p20956111318130"><a name="p20956111318130"></a><a name="p20956111318130"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="35.76%" headers="mcps1.1.6.1.5 "><p id="p2956161391313"><a name="p2956161391313"></a><a name="p2956161391313"></a>String used to match this item. This attribute can be left empty. The value cannot be dynamically updated. In a list item group, only the string set for the primary item is valid.</p>
</td>
</tr>
<tr id="row1629515214134"><td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.1 "><p id="p2095641311138"><a name="p2095641311138"></a><a name="p2095641311138"></a>sticky</p>
</td>
<td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.2 "><p id="p6957141317138"><a name="p6957141317138"></a><a name="p6957141317138"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="10.48%" headers="mcps1.1.6.1.3 "><p id="p295771313131"><a name="p295771313131"></a><a name="p295771313131"></a>none</p>
</td>
<td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.6.1.4 "><p id="p199571613151311"><a name="p199571613151311"></a><a name="p199571613151311"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="35.76%" headers="mcps1.1.6.1.5 "><p id="p29571313131310"><a name="p29571313131310"></a><a name="p29571313131310"></a>Whether the current item sticks in place at the top, and the effect when it disappears. This attribute supports vertical lists only and is invalid for items in a group.</p>
<a name="ul69572137130"></a><a name="ul69572137130"></a><ul id="ul69572137130"><li><strong id="b13151921114"><a name="b13151921114"></a><a name="b13151921114"></a>none</strong>: The current item does not stick at the top.</li><li><strong id="b646332811"><a name="b646332811"></a><a name="b646332811"></a>normal</strong>: The current item sticks at the top and disappears with a sliding effect.</li><li><strong id="b20166151733418"><a name="b20166151733418"></a><a name="b20166151733418"></a>opacity</strong>: The current item sticks at the top and disappears gradually. This option is only supported on wearables.</li></ul>
</td>
</tr>
<tr id="row6359185421211"><td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.1 "><p id="p109577139132"><a name="p109577139132"></a><a name="p109577139132"></a>clickeffect<sup id="sup1375415364114"><a name="sup1375415364114"></a><a name="sup1375415364114"></a>5+</sup></p>
</td>
<td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.2 "><p id="p9957161341310"><a name="p9957161341310"></a><a name="p9957161341310"></a>boolean</p>
</td>
<td class="cellrowborder" valign="top" width="10.48%" headers="mcps1.1.6.1.3 "><p id="p99571013181316"><a name="p99571013181316"></a><a name="p99571013181316"></a>true</p>
</td>
<td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.6.1.4 "><p id="p139571513121313"><a name="p139571513121313"></a><a name="p139571513121313"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="35.76%" headers="mcps1.1.6.1.5 "><p id="p99581613141313"><a name="p99581613141313"></a><a name="p99581613141313"></a>Whether an effect is displayed when the current item is clicked.</p>
<a name="ul1958513101318"></a><a name="ul1958513101318"></a><ul id="ul1958513101318"><li><strong id="b206206251067"><a name="b206206251067"></a><a name="b206206251067"></a>false</strong>: No effect is displayed when the item is clicked.</li><li><strong id="b1974082612456"><a name="b1974082612456"></a><a name="b1974082612456"></a>true</strong>: An effect is displayed when the item is clicked.</li></ul>
</td>
</tr>
</tbody>
</table>

## Styles<a name="section5775351116"></a>

In addition to the styles in  [Universal Styles](js-components-common-styles.md), the following styles are supported.

<a name="table164819331216"></a>
<table><thead align="left"><tr id="row1548217331922"><th class="cellrowborder" valign="top" width="23.11768823117688%" id="mcps1.1.6.1.1"><p id="p19482733426"><a name="p19482733426"></a><a name="p19482733426"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="20.477952204779523%" id="mcps1.1.6.1.2"><p id="p174821332212"><a name="p174821332212"></a><a name="p174821332212"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="8.869113088691131%" id="mcps1.1.6.1.3"><p id="p1948203319214"><a name="p1948203319214"></a><a name="p1948203319214"></a>Default Value</p>
</th>
<th class="cellrowborder" valign="top" width="7.519248075192481%" id="mcps1.1.6.1.4"><p id="p1482733627"><a name="p1482733627"></a><a name="p1482733627"></a>Mandatory</p>
</th>
<th class="cellrowborder" valign="top" width="40.01599840015999%" id="mcps1.1.6.1.5"><p id="p1348213331227"><a name="p1348213331227"></a><a name="p1348213331227"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row124821733120"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="p34821331428"><a name="p34821331428"></a><a name="p34821331428"></a>column-span</p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p id="p24823331213"><a name="p24823331213"></a><a name="p24823331213"></a>&lt;number&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p id="p1848211334211"><a name="p1848211334211"></a><a name="p1848211334211"></a>1</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p id="p14482133318219"><a name="p14482133318219"></a><a name="p14482133318219"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="p24821933921"><a name="p24821933921"></a><a name="p24821933921"></a>Number of columns occupied by the current list-item in the list. By default, the list-item occupies one column. This attribute is valid only when the list contains multiple columns.</p>
</td>
</tr>
</tbody>
</table>

## Events<a name="section1948820711216"></a>

In addition to the events in  [Universal Events](js-components-common-events.md), the following events are supported.

<a name="table7489127521"></a>
<table><thead align="left"><tr id="row848957922"><th class="cellrowborder" valign="top" width="24.852485248524854%" id="mcps1.1.4.1.1"><p id="p748914712220"><a name="p748914712220"></a><a name="p748914712220"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="22.82228222822282%" id="mcps1.1.4.1.2"><p id="p194899713219"><a name="p194899713219"></a><a name="p194899713219"></a>Parameter</p>
</th>
<th class="cellrowborder" valign="top" width="52.32523252325233%" id="mcps1.1.4.1.3"><p id="p14489471229"><a name="p14489471229"></a><a name="p14489471229"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row14891075219"><td class="cellrowborder" valign="top" width="24.852485248524854%" headers="mcps1.1.4.1.1 "><p id="p124898715214"><a name="p124898715214"></a><a name="p124898715214"></a>sticky </p>
</td>
<td class="cellrowborder" valign="top" width="22.82228222822282%" headers="mcps1.1.4.1.2 "><p id="p048977429"><a name="p048977429"></a><a name="p048977429"></a>{ state: boolean }</p>
</td>
<td class="cellrowborder" valign="top" width="52.32523252325233%" headers="mcps1.1.4.1.3 "><p id="p3489773215"><a name="p3489773215"></a><a name="p3489773215"></a>Callback events for a sticky component.</p>
<p id="p44891171220"><a name="p44891171220"></a><a name="p44891171220"></a><strong id="b3628542811"><a name="b3628542811"></a><a name="b3628542811"></a>value: false</strong>: The current item is not in the sticky state.</p>
<p id="p74892071427"><a name="p74892071427"></a><a name="p74892071427"></a><strong id="b6657181394"><a name="b6657181394"></a><a name="b6657181394"></a>value: true</strong>: The current item is in the sticky state.</p>
<p id="p74895716210"><a name="p74895716210"></a><a name="p74895716210"></a>This event is supported only when the item is configured with the <strong id="b15560112218363"><a name="b15560112218363"></a><a name="b15560112218363"></a>sticky</strong> attribute.</p>
</td>
</tr>
</tbody>
</table>

## Methods<a name="section2279124532420"></a>

Methods in  [Universal Methods](js-components-common-methods.md)  are supported.

## Example<a name="section634316188515"></a>

For details, see the  [list example code](js-components-container-list.md#example).

