# Atomic Layout<a name="EN-US_TOPIC_0000001115974728"></a>

-   [Hiding Components](#en-us_topic_0000001062070665_section0441154013284)
-   [Proportion](#en-us_topic_0000001062070665_section13725752194418)
-   [Fixed Ratio](#en-us_topic_0000001062070665_section922215811557)

The atomic layout features adaptive change and layout capabilities for screens of different sizes and types. Designers can use the atomic layout to define adaptive rules for elements on UIs of different forms. Developers can use the atomic layout to implement the adaptive UI features matching the design effect for a variety of screens.

>![](public_sys-resources/icon-note.gif) **NOTE:** 
>The atomic layout is supported since API version 5.

## Hiding Components<a name="en-us_topic_0000001062070665_section0441154013284"></a>

You can set priority flags for a flex layout that does not support cross-row display to define the display priorities for elements in the horizontal or vertical direction. The elements are hidden based on available space of the container.

<a name="en-us_topic_0000001062070665_table14323142291413"></a>
<table><thead align="left"><tr id="en-us_topic_0000001062070665_row232317223144"><th class="cellrowborder" valign="top" width="15.65%" id="mcps1.1.5.1.1"><p id="en-us_topic_0000001062070665_p85051811127"><a name="en-us_topic_0000001062070665_p85051811127"></a><a name="en-us_topic_0000001062070665_p85051811127"></a>Style</p>
</th>
<th class="cellrowborder" valign="top" width="13.270000000000001%" id="mcps1.1.5.1.2"><p id="en-us_topic_0000001062070665_p2505915217"><a name="en-us_topic_0000001062070665_p2505915217"></a><a name="en-us_topic_0000001062070665_p2505915217"></a>Value Type</p>
</th>
<th class="cellrowborder" valign="top" width="11.58%" id="mcps1.1.5.1.3"><p id="en-us_topic_0000001062070665_p8654516123719"><a name="en-us_topic_0000001062070665_p8654516123719"></a><a name="en-us_topic_0000001062070665_p8654516123719"></a>Default Value</p>
</th>
<th class="cellrowborder" valign="top" width="59.5%" id="mcps1.1.5.1.4"><p id="en-us_topic_0000001062070665_p75054112213"><a name="en-us_topic_0000001062070665_p75054112213"></a><a name="en-us_topic_0000001062070665_p75054112213"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="en-us_topic_0000001062070665_row23236222143"><td class="cellrowborder" valign="top" width="15.65%" headers="mcps1.1.5.1.1 "><p id="en-us_topic_0000001062070665_p1950519112213"><a name="en-us_topic_0000001062070665_p1950519112213"></a><a name="en-us_topic_0000001062070665_p1950519112213"></a>display-index</p>
</td>
<td class="cellrowborder" valign="top" width="13.270000000000001%" headers="mcps1.1.5.1.2 "><p id="en-us_topic_0000001062070665_p65059111213"><a name="en-us_topic_0000001062070665_p65059111213"></a><a name="en-us_topic_0000001062070665_p65059111213"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="11.58%" headers="mcps1.1.5.1.3 "><p id="en-us_topic_0000001062070665_p166547162374"><a name="en-us_topic_0000001062070665_p166547162374"></a><a name="en-us_topic_0000001062070665_p166547162374"></a>Infinity</p>
</td>
<td class="cellrowborder" valign="top" width="59.5%" headers="mcps1.1.5.1.4 "><p id="en-us_topic_0000001062070665_p75481189562"><a name="en-us_topic_0000001062070665_p75481189562"></a><a name="en-us_topic_0000001062070665_p75481189562"></a>Hide child components according to the ascending order of their <strong id="en-us_topic_0000001062070665_b9988192710556"><a name="en-us_topic_0000001062070665_b9988192710556"></a><a name="en-us_topic_0000001062070665_b9988192710556"></a>display-index</strong> values when the space on the flex main axis of the container is insufficient to display all content.</p>
<p id="en-us_topic_0000001062070665_p11989182765511"><a name="en-us_topic_0000001062070665_p11989182765511"></a><a name="en-us_topic_0000001062070665_p11989182765511"></a>Child components with the same <strong id="en-us_topic_0000001062070665_b189887271559"><a name="en-us_topic_0000001062070665_b189887271559"></a><a name="en-us_topic_0000001062070665_b189887271559"></a>display-index</strong> value are hidden at the same time.</p>
<p id="en-us_topic_0000001062070665_p1363375318"><a name="en-us_topic_0000001062070665_p1363375318"></a><a name="en-us_topic_0000001062070665_p1363375318"></a>You can use the default value (<strong id="en-us_topic_0000001062070665_b1163178316"><a name="en-us_topic_0000001062070665_b1163178316"></a><a name="en-us_topic_0000001062070665_b1163178316"></a>Infinity</strong>) for a child component, which means that it will not be hidden.</p>
<p id="en-us_topic_0000001062070665_p3505181129"><a name="en-us_topic_0000001062070665_p3505181129"></a><a name="en-us_topic_0000001062070665_p3505181129"></a>This style is applicable only to child components in a container that supports flex layout, such as <strong id="en-us_topic_0000001062070665_b16943743133013"><a name="en-us_topic_0000001062070665_b16943743133013"></a><a name="en-us_topic_0000001062070665_b16943743133013"></a>&lt;div&gt;</strong>.</p>
</td>
</tr>
</tbody>
</table>

## Proportion<a name="en-us_topic_0000001062070665_section13725752194418"></a>

In a flex layout that does not support cross-row display, elements with the proportion style configured are always arranged with the set proportions in the container.

<a name="en-us_topic_0000001062070665_table337121117522"></a>
<table><thead align="left"><tr id="en-us_topic_0000001062070665_row9371811155218"><th class="cellrowborder" valign="top" width="15.65%" id="mcps1.1.5.1.1"><p id="en-us_topic_0000001062070665_p173711311175216"><a name="en-us_topic_0000001062070665_p173711311175216"></a><a name="en-us_topic_0000001062070665_p173711311175216"></a>Style</p>
</th>
<th class="cellrowborder" valign="top" width="13.270000000000001%" id="mcps1.1.5.1.2"><p id="en-us_topic_0000001062070665_p6371111119529"><a name="en-us_topic_0000001062070665_p6371111119529"></a><a name="en-us_topic_0000001062070665_p6371111119529"></a>Value Type</p>
</th>
<th class="cellrowborder" valign="top" width="11.58%" id="mcps1.1.5.1.3"><p id="en-us_topic_0000001062070665_p337181145211"><a name="en-us_topic_0000001062070665_p337181145211"></a><a name="en-us_topic_0000001062070665_p337181145211"></a>Default Value</p>
</th>
<th class="cellrowborder" valign="top" width="59.5%" id="mcps1.1.5.1.4"><p id="en-us_topic_0000001062070665_p33711211145213"><a name="en-us_topic_0000001062070665_p33711211145213"></a><a name="en-us_topic_0000001062070665_p33711211145213"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="en-us_topic_0000001062070665_row1237118111527"><td class="cellrowborder" valign="top" width="15.65%" headers="mcps1.1.5.1.1 "><p id="en-us_topic_0000001062070665_p17371711195218"><a name="en-us_topic_0000001062070665_p17371711195218"></a><a name="en-us_topic_0000001062070665_p17371711195218"></a>flex-weight</p>
</td>
<td class="cellrowborder" valign="top" width="13.270000000000001%" headers="mcps1.1.5.1.2 "><p id="en-us_topic_0000001062070665_p737191112523"><a name="en-us_topic_0000001062070665_p737191112523"></a><a name="en-us_topic_0000001062070665_p737191112523"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="11.58%" headers="mcps1.1.5.1.3 "><p id="en-us_topic_0000001062070665_p83711511205218"><a name="en-us_topic_0000001062070665_p83711511205218"></a><a name="en-us_topic_0000001062070665_p83711511205218"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="59.5%" headers="mcps1.1.5.1.4 "><p id="en-us_topic_0000001062070665_p234101512916"><a name="en-us_topic_0000001062070665_p234101512916"></a><a name="en-us_topic_0000001062070665_p234101512916"></a>Size weight of an element on the flex main axis. </p>
<p id="en-us_topic_0000001062070665_p5749319913"><a name="en-us_topic_0000001062070665_p5749319913"></a><a name="en-us_topic_0000001062070665_p5749319913"></a>Element size = Container main axis size x <strong id="en-us_topic_0000001062070665_b37418311916"><a name="en-us_topic_0000001062070665_b37418311916"></a><a name="en-us_topic_0000001062070665_b37418311916"></a>flex-weight</strong> / Sum of all element size weights. </p>
<p id="en-us_topic_0000001062070665_p337111112521"><a name="en-us_topic_0000001062070665_p337111112521"></a><a name="en-us_topic_0000001062070665_p337111112521"></a>This style takes effect only when it is set for all elements in the container.</p>
</td>
</tr>
</tbody>
</table>

## Fixed Ratio<a name="en-us_topic_0000001062070665_section922215811557"></a>

A component with fixed ratio can be scaled up and down while retaining its aspect ratio.

<a name="en-us_topic_0000001062070665_table1077611191734"></a>
<table><thead align="left"><tr id="en-us_topic_0000001062070665_row377618191536"><th class="cellrowborder" valign="top" width="15.65%" id="mcps1.1.5.1.1"><p id="en-us_topic_0000001062070665_p1776101916316"><a name="en-us_topic_0000001062070665_p1776101916316"></a><a name="en-us_topic_0000001062070665_p1776101916316"></a>Style</p>
</th>
<th class="cellrowborder" valign="top" width="13.270000000000001%" id="mcps1.1.5.1.2"><p id="en-us_topic_0000001062070665_p277618191233"><a name="en-us_topic_0000001062070665_p277618191233"></a><a name="en-us_topic_0000001062070665_p277618191233"></a>Value Type</p>
</th>
<th class="cellrowborder" valign="top" width="11.58%" id="mcps1.1.5.1.3"><p id="en-us_topic_0000001062070665_p57762194318"><a name="en-us_topic_0000001062070665_p57762194318"></a><a name="en-us_topic_0000001062070665_p57762194318"></a>Default Value</p>
</th>
<th class="cellrowborder" valign="top" width="59.5%" id="mcps1.1.5.1.4"><p id="en-us_topic_0000001062070665_p2776151915313"><a name="en-us_topic_0000001062070665_p2776151915313"></a><a name="en-us_topic_0000001062070665_p2776151915313"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="en-us_topic_0000001062070665_row67761119233"><td class="cellrowborder" valign="top" width="15.65%" headers="mcps1.1.5.1.1 "><p id="en-us_topic_0000001062070665_p10776181914317"><a name="en-us_topic_0000001062070665_p10776181914317"></a><a name="en-us_topic_0000001062070665_p10776181914317"></a>aspect-ratio</p>
</td>
<td class="cellrowborder" valign="top" width="13.270000000000001%" headers="mcps1.1.5.1.2 "><p id="en-us_topic_0000001062070665_p57762019636"><a name="en-us_topic_0000001062070665_p57762019636"></a><a name="en-us_topic_0000001062070665_p57762019636"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="11.58%" headers="mcps1.1.5.1.3 "><p id="en-us_topic_0000001062070665_p1777613191935"><a name="en-us_topic_0000001062070665_p1777613191935"></a><a name="en-us_topic_0000001062070665_p1777613191935"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="59.5%" headers="mcps1.1.5.1.4 "><p id="en-us_topic_0000001062070665_p12776121918313"><a name="en-us_topic_0000001062070665_p12776121918313"></a><a name="en-us_topic_0000001062070665_p12776121918313"></a>Aspect ratio of the component. The value is a floating-point value greater than 0.</p>
<p id="en-us_topic_0000001062070665_p3793145491117"><a name="en-us_topic_0000001062070665_p3793145491117"></a><a name="en-us_topic_0000001062070665_p3793145491117"></a>The value is subjective to the upper and lower limits of the component size.</p>
<p id="en-us_topic_0000001062070665_p15216164731415"><a name="en-us_topic_0000001062070665_p15216164731415"></a><a name="en-us_topic_0000001062070665_p15216164731415"></a>In a flex layout, the main axis size is adjusted first, based on which the cross axis size is adjusted.</p>
</td>
</tr>
</tbody>
</table>

