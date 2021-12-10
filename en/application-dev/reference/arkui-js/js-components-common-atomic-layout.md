# Atomic Layout<a name="EN-US_TOPIC_0000001127125020"></a>

The atomic layout implements adaptive layout for screens of different sizes and types. Designers can use the atomic layout to define adaptive rules for elements on UIs of different forms. Developers can use the atomic layout to implement the adaptive UI features matching the design effect for a variety of screens.

>![](../../public_sys-resources/icon-note.gif) **NOTE:** 
>The atomic layout is supported since API version 5.

## Hiding Components<a name="section0441154013284"></a>

You can set priority flags for a flex layout that does not support cross-row display to define the display priorities for elements in the horizontal or vertical direction. The elements are hidden based on available space of the container.

<a name="table14323142291413"></a>
<table><thead align="left"><tr id="row232317223144"><th class="cellrowborder" valign="top" width="15.65%" id="mcps1.1.5.1.1"><p id="p85051811127"><a name="p85051811127"></a><a name="p85051811127"></a>Style</p>
</th>
<th class="cellrowborder" valign="top" width="13.270000000000001%" id="mcps1.1.5.1.2"><p id="p2505915217"><a name="p2505915217"></a><a name="p2505915217"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="11.58%" id="mcps1.1.5.1.3"><p id="p8654516123719"><a name="p8654516123719"></a><a name="p8654516123719"></a>Default Value</p>
</th>
<th class="cellrowborder" valign="top" width="59.5%" id="mcps1.1.5.1.4"><p id="p75054112213"><a name="p75054112213"></a><a name="p75054112213"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row23236222143"><td class="cellrowborder" valign="top" width="15.65%" headers="mcps1.1.5.1.1 "><p id="p1950519112213"><a name="p1950519112213"></a><a name="p1950519112213"></a>display-index</p>
</td>
<td class="cellrowborder" valign="top" width="13.270000000000001%" headers="mcps1.1.5.1.2 "><p id="p65059111213"><a name="p65059111213"></a><a name="p65059111213"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="11.58%" headers="mcps1.1.5.1.3 "><p id="p166547162374"><a name="p166547162374"></a><a name="p166547162374"></a>0</p>
</td>
<td class="cellrowborder" valign="top" width="59.5%" headers="mcps1.1.5.1.4 "><p id="p75481189562"><a name="p75481189562"></a><a name="p75481189562"></a>Hide child components according to the ascending order of their <strong id="b9988192710556"><a name="b9988192710556"></a><a name="b9988192710556"></a>display-index</strong> values when the space on the flex main axis of the container is insufficient to display all content.</p>
<p id="p11989182765511"><a name="p11989182765511"></a><a name="p11989182765511"></a>Child components with the same <strong id="b189887271559"><a name="b189887271559"></a><a name="b189887271559"></a>display-index</strong> value are hidden at the same time.</p>
<p id="p1363375318"><a name="p1363375318"></a><a name="p1363375318"></a>You can use the default value (<strong id="b1163178316"><a name="b1163178316"></a><a name="b1163178316"></a>0</strong>) for a child component, which means that it will be hidden.</p>
<p id="p3505181129"><a name="p3505181129"></a><a name="p3505181129"></a>This style is applicable only to child components in a container that supports the flex layout, such as <strong id="b16943743133013"><a name="b16943743133013"></a><a name="b16943743133013"></a>&lt;div&gt;</strong>.</p>
</td>
</tr>
</tbody>
</table>

## Proportion<a name="section13725752194418"></a>

In a flex layout that does not support cross-row display, elements with the proportion style configured are always arranged with the set proportions in the container.

<a name="table337121117522"></a>
<table><thead align="left"><tr id="row9371811155218"><th class="cellrowborder" valign="top" width="15.65%" id="mcps1.1.5.1.1"><p id="p173711311175216"><a name="p173711311175216"></a><a name="p173711311175216"></a>Style</p>
</th>
<th class="cellrowborder" valign="top" width="13.270000000000001%" id="mcps1.1.5.1.2"><p id="p6371111119529"><a name="p6371111119529"></a><a name="p6371111119529"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="11.58%" id="mcps1.1.5.1.3"><p id="p337181145211"><a name="p337181145211"></a><a name="p337181145211"></a>Default Value</p>
</th>
<th class="cellrowborder" valign="top" width="59.5%" id="mcps1.1.5.1.4"><p id="p33711211145213"><a name="p33711211145213"></a><a name="p33711211145213"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1237118111527"><td class="cellrowborder" valign="top" width="15.65%" headers="mcps1.1.5.1.1 "><p id="p17371711195218"><a name="p17371711195218"></a><a name="p17371711195218"></a>flex-weight</p>
</td>
<td class="cellrowborder" valign="top" width="13.270000000000001%" headers="mcps1.1.5.1.2 "><p id="p737191112523"><a name="p737191112523"></a><a name="p737191112523"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="11.58%" headers="mcps1.1.5.1.3 "><p id="p83711511205218"><a name="p83711511205218"></a><a name="p83711511205218"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="59.5%" headers="mcps1.1.5.1.4 "><p id="p234101512916"><a name="p234101512916"></a><a name="p234101512916"></a>Size weight of an element on the flex main axis. </p>
<p id="p5749319913"><a name="p5749319913"></a><a name="p5749319913"></a>Element size = Container main axis size x <strong id="b37418311916"><a name="b37418311916"></a><a name="b37418311916"></a>flex-weight</strong> / Sum of all element size weights. </p>
<p id="p337111112521"><a name="p337111112521"></a><a name="p337111112521"></a>This style takes effect only when it is set for all elements in the container.</p>
</td>
</tr>
</tbody>
</table>

## Fixed Ratio<a name="section922215811557"></a>

A component with fixed ratio can be scaled up and down while retaining its aspect ratio.

<a name="table1077611191734"></a>
<table><thead align="left"><tr id="row377618191536"><th class="cellrowborder" valign="top" width="15.65%" id="mcps1.1.5.1.1"><p id="p1776101916316"><a name="p1776101916316"></a><a name="p1776101916316"></a>Style</p>
</th>
<th class="cellrowborder" valign="top" width="13.270000000000001%" id="mcps1.1.5.1.2"><p id="p277618191233"><a name="p277618191233"></a><a name="p277618191233"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="11.58%" id="mcps1.1.5.1.3"><p id="p57762194318"><a name="p57762194318"></a><a name="p57762194318"></a>Default Value</p>
</th>
<th class="cellrowborder" valign="top" width="59.5%" id="mcps1.1.5.1.4"><p id="p2776151915313"><a name="p2776151915313"></a><a name="p2776151915313"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row67761119233"><td class="cellrowborder" valign="top" width="15.65%" headers="mcps1.1.5.1.1 "><p id="p10776181914317"><a name="p10776181914317"></a><a name="p10776181914317"></a>aspect-ratio</p>
</td>
<td class="cellrowborder" valign="top" width="13.270000000000001%" headers="mcps1.1.5.1.2 "><p id="p57762019636"><a name="p57762019636"></a><a name="p57762019636"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="11.58%" headers="mcps1.1.5.1.3 "><p id="p1777613191935"><a name="p1777613191935"></a><a name="p1777613191935"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="59.5%" headers="mcps1.1.5.1.4 "><p id="p12776121918313"><a name="p12776121918313"></a><a name="p12776121918313"></a>Aspect ratio of the component. The value is a floating-point value greater than 0.</p>
<p id="p3793145491117"><a name="p3793145491117"></a><a name="p3793145491117"></a>The value is subjective to the upper and lower limits of the component size.</p>
<p id="p15216164731415"><a name="p15216164731415"></a><a name="p15216164731415"></a>In a flex layout, the main axis size is adjusted first, based on which the cross axis size is adjusted.</p>
</td>
</tr>
</tbody>
</table>

