# grid-row<a name="EN-US_TOPIC_0000001173324663"></a>

The  **<grid-row\>**  component is a container used as a child component of  **<grid-container\>**. Each  **<grid-col\>**  component is arranged horizontally with  **flex**-related styles. By default, items in the  **<grid-row\>**  component are packed towards the start row and aligned to the start of the cross axis. You can set the items to be displayed in multiple axes.

## Required Permissions<a name="section11257113618419"></a>

None

## Child Components<a name="section9288143101012"></a>

Only the  **<grid-col\>**  component is supported.

## Attributes<a name="section631751545214"></a>

Attributes in  [Universal Attributes](js-components-common-attributes.md)  are supported.

## Styles<a name="section9475356165220"></a>

In addition to the styles in  [Universal Styles](js-components-common-styles.md), the following styles are supported.

<a name="table1583612162713"></a>
<table><thead align="left"><tr id="row148360114276"><th class="cellrowborder" valign="top" width="23.11768823117688%" id="mcps1.1.6.1.1"><p id="p08361619274"><a name="p08361619274"></a><a name="p08361619274"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="20.477952204779523%" id="mcps1.1.6.1.2"><p id="p48361812276"><a name="p48361812276"></a><a name="p48361812276"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="8.869113088691131%" id="mcps1.1.6.1.3"><p id="p198367112715"><a name="p198367112715"></a><a name="p198367112715"></a>Default Value</p>
</th>
<th class="cellrowborder" valign="top" width="7.519248075192481%" id="mcps1.1.6.1.4"><p id="p1183610152710"><a name="p1183610152710"></a><a name="p1183610152710"></a>Mandatory</p>
</th>
<th class="cellrowborder" valign="top" width="40.01599840015999%" id="mcps1.1.6.1.5"><p id="p48362162718"><a name="p48362162718"></a><a name="p48362162718"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row17836181102717"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="p1283681182714"><a name="p1283681182714"></a><a name="p1283681182714"></a>flex-wrap</p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p id="p11837111182712"><a name="p11837111182712"></a><a name="p11837111182712"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p id="p1083741172718"><a name="p1083741172718"></a><a name="p1083741172718"></a>nowrap</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p id="p108371218276"><a name="p108371218276"></a><a name="p108371218276"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="p883731162713"><a name="p883731162713"></a><a name="p883731162713"></a>Whether items in the container are displayed in a single axis or multiple axes. Currently, dynamic modification is not supported. Available values are as follows:</p>
<a name="ul1583771142719"></a><a name="ul1583771142719"></a><ul id="ul1583771142719"><li><strong id="b1899950182014"><a name="b1899950182014"></a><a name="b1899950182014"></a>nowrap</strong>: Items are displayed on a single axis.</li><li><strong id="b18315182162018"><a name="b18315182162018"></a><a name="b18315182162018"></a>wrap</strong>: Items are displayed on multiple axes.</li></ul>
</td>
</tr>
<tr id="row14837111202712"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="p1883781162717"><a name="p1883781162717"></a><a name="p1883781162717"></a>justify-content</p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p id="p183731102715"><a name="p183731102715"></a><a name="p183731102715"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p id="p13837111279"><a name="p13837111279"></a><a name="p13837111279"></a>flex-start</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p id="p13837111162713"><a name="p13837111162713"></a><a name="p13837111162713"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="p198371919278"><a name="p198371919278"></a><a name="p198371919278"></a>How items are aligned along the main axis of the current row in the container. Available values are as follows:</p>
<a name="ul20837121152717"></a><a name="ul20837121152717"></a><ul id="ul20837121152717"><li><strong id="b1442428202016"><a name="b1442428202016"></a><a name="b1442428202016"></a>flex-start</strong>: Items are packed towards the start row.</li><li><strong id="b233318913202"><a name="b233318913202"></a><a name="b233318913202"></a>flex-end</strong>: Items are packed towards the end row.</li><li><strong id="b162541410172015"><a name="b162541410172015"></a><a name="b162541410172015"></a>center</strong>: Items are centered along the row.</li><li><strong id="b131513117202"><a name="b131513117202"></a><a name="b131513117202"></a>space-between</strong>: Items are positioned with space between the rows.</li><li><strong id="b1021031292014"><a name="b1021031292014"></a><a name="b1021031292014"></a>space-around</strong>: Items are positioned with space before, between, and after the rows.</li></ul>
</td>
</tr>
<tr id="row188387162714"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="p0838913278"><a name="p0838913278"></a><a name="p0838913278"></a>align-items</p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p id="p138385114274"><a name="p138385114274"></a><a name="p138385114274"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p id="p983811122713"><a name="p983811122713"></a><a name="p983811122713"></a>flex-start</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p id="p1883812110278"><a name="p1883812110278"></a><a name="p1883812110278"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="p983813116271"><a name="p983813116271"></a><a name="p983813116271"></a>How items are aligned along the cross axis of the current row in the container. Available values are as follows:</p>
<a name="ul2838201122714"></a><a name="ul2838201122714"></a><ul id="ul2838201122714"><li><strong id="b52351418182019"><a name="b52351418182019"></a><a name="b52351418182019"></a>stretch</strong>: Items are stretched to the same height or width as the container in the cross axis direction. </li><li><strong id="b19675172015207"><a name="b19675172015207"></a><a name="b19675172015207"></a>flex-start</strong>: Items are aligned to the start of the cross axis.</li><li><strong id="b2654721132018"><a name="b2654721132018"></a><a name="b2654721132018"></a>flex-end</strong>: Items are aligned to the end of the cross axis.</li><li><strong id="b4585102215204"><a name="b4585102215204"></a><a name="b4585102215204"></a>center</strong>: Items are aligned in the middle of the cross axis.</li></ul>
</td>
</tr>
<tr id="row13839918275"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="p88391714276"><a name="p88391714276"></a><a name="p88391714276"></a>align-content</p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p id="p283919116277"><a name="p283919116277"></a><a name="p283919116277"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p id="p18839181182720"><a name="p18839181182720"></a><a name="p18839181182720"></a>flex-start</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p id="p1683911142717"><a name="p1683911142717"></a><a name="p1683911142717"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="p148392011271"><a name="p148392011271"></a><a name="p148392011271"></a>Multi-row alignment mode when there is extra space in the cross axis. Available values are as follows:</p>
<a name="ul15839101102715"></a><a name="ul15839101102715"></a><ul id="ul15839101102715"><li><strong id="b232014272206"><a name="b232014272206"></a><a name="b232014272206"></a>flex-start</strong>: All rows are packed towards the start of the cross axis. The start edge of the cross axis of the first row is aligned with the start edge of the cross axis of the container. All subsequent rows are aligned with the previous row.</li><li><strong id="b034111308204"><a name="b034111308204"></a><a name="b034111308204"></a>flex-end</strong>: All rows are packed towards the end of the cross axis. The end of the cross axis of the last row is aligned with the end of the cross axis of the container. All subsequent rows are aligned with the previous row.</li><li><strong id="b58521334203"><a name="b58521334203"></a><a name="b58521334203"></a>center</strong>: All rows are packed towards the center of the container. Rows are close to each other and aligned with the center of the container. The spacing between the start of the container's cross axis and the first row is equal to the spacing between the end of the container's cross axis and the last row.</li><li><strong id="b126908361201"><a name="b126908361201"></a><a name="b126908361201"></a>space-between</strong>: All rows are evenly distributed in the container. The spacing between two adjacent rows is the same. The start and end edges of the container's cross axis are aligned with the edges of the first and last rows, respectively.</li><li><strong id="b19242184011208"><a name="b19242184011208"></a><a name="b19242184011208"></a>space-around</strong>: All rows are evenly distributed in the container, and the spacing between two adjacent rows is the same. The spacing between the start edge of the container's cross axis and the first row and that between the end edge and the last row are half of the spacing between two adjacent rows.</li></ul>
</td>
</tr>
</tbody>
</table>

>![](../../public_sys-resources/icon-note.gif) **NOTE:** 
>Width-related styles are not supported.

## Events<a name="section1417950207"></a>

Events in  [Universal Events](js-components-common-events.md)  are supported.

## Methods<a name="section2279124532420"></a>

Methods in  [Universal Methods](js-components-common-methods.md)  are supported.

## Example Code<a name="section634316188515"></a>

For details, see  [grid-col](js-components-grid-col.md).

