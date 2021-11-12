# grid-col<a name="EN-US_TOPIC_0000001173164763"></a>

The  **<grid-col\>**  is the child component of the  **<grid-row\>**  container.

## Permission List<a name="section11257113618419"></a>

None

## Child Component<a name="section9288143101012"></a>

Supported

## Attribute<a name="section1976213199113"></a>

In addition to the attributes in  [Universal Attributes](js-components-common-attributes.md), the following attributes are supported.

<a name="table20633101642315"></a>
<table><thead align="left"><tr id="row663331618238"><th class="cellrowborder" valign="top" width="23.119999999999997%" id="mcps1.1.6.1.1"><p id="a45273e2103004ff3bdd3375013e96a2a"><a name="a45273e2103004ff3bdd3375013e96a2a"></a><a name="a45273e2103004ff3bdd3375013e96a2a"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="23.119999999999997%" id="mcps1.1.6.1.2"><p id="ad5b10d4a60e44bb4a8bbb3b4416d7b27"><a name="ad5b10d4a60e44bb4a8bbb3b4416d7b27"></a><a name="ad5b10d4a60e44bb4a8bbb3b4416d7b27"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="10.48%" id="mcps1.1.6.1.3"><p id="ab2ae3d9f60d6475ab95ba095851a9d07"><a name="ab2ae3d9f60d6475ab95ba095851a9d07"></a><a name="ab2ae3d9f60d6475ab95ba095851a9d07"></a>Default Value</p>
</th>
<th class="cellrowborder" valign="top" width="7.449999999999999%" id="mcps1.1.6.1.4"><p id="p824610360217"><a name="p824610360217"></a><a name="p824610360217"></a>Mandatory</p>
</th>
<th class="cellrowborder" valign="top" width="35.83%" id="mcps1.1.6.1.5"><p id="af5c3b773ed0a42e589819a6c8d257ca1"><a name="af5c3b773ed0a42e589819a6c8d257ca1"></a><a name="af5c3b773ed0a42e589819a6c8d257ca1"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row61510615123"><td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.1 "><p id="p13694117171213"><a name="p13694117171213"></a><a name="p13694117171213"></a>xs</p>
</td>
<td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.2 "><p id="p17694191719123"><a name="p17694191719123"></a><a name="p17694191719123"></a>number|object</p>
</td>
<td class="cellrowborder" valign="top" width="10.48%" headers="mcps1.1.6.1.3 "><p id="p9694171712125"><a name="p9694171712125"></a><a name="p9694171712125"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.449999999999999%" headers="mcps1.1.6.1.4 "><p id="p769441711125"><a name="p769441711125"></a><a name="p769441711125"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="35.83%" headers="mcps1.1.6.1.5 "><p id="p3694217141213"><a name="p3694217141213"></a><a name="p3694217141213"></a>Number of columns occupied by this item and offset columns when <strong id="b2730139165"><a name="b2730139165"></a><a name="b2730139165"></a>sizetype</strong> is <strong id="b181713015162"><a name="b181713015162"></a><a name="b181713015162"></a>xs</strong>. If you set the value of the number type, you only set the number of occupied columns. You can set a value of the object type for both the number of occupied columns and offset columns, for example, <strong id="b19696173081219"><a name="b19696173081219"></a><a name="b19696173081219"></a>{"span": 1, "offset": 0}</strong>.</p>
</td>
</tr>
<tr id="row683183131212"><td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.1 "><p id="p15694417181219"><a name="p15694417181219"></a><a name="p15694417181219"></a>sm</p>
</td>
<td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.2 "><p id="p15694141741210"><a name="p15694141741210"></a><a name="p15694141741210"></a>number|object</p>
</td>
<td class="cellrowborder" valign="top" width="10.48%" headers="mcps1.1.6.1.3 "><p id="p66941517171212"><a name="p66941517171212"></a><a name="p66941517171212"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.449999999999999%" headers="mcps1.1.6.1.4 "><p id="p4694111714123"><a name="p4694111714123"></a><a name="p4694111714123"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="35.83%" headers="mcps1.1.6.1.5 "><p id="p17694117171211"><a name="p17694117171211"></a><a name="p17694117171211"></a>Number of columns occupied by this item and offset columns when <strong id="b964791471919"><a name="b964791471919"></a><a name="b964791471919"></a>sizetype</strong> is <strong id="b0648714191910"><a name="b0648714191910"></a><a name="b0648714191910"></a>sm</strong>. If you set the value of the number type, you only set the number of occupied columns. You can set a value of the object type for both the number of occupied columns and offset columns, for example, <strong id="b464831451918"><a name="b464831451918"></a><a name="b464831451918"></a>{"span": 1, "offset": 0}</strong>.</p>
</td>
</tr>
<tr id="row1211310592118"><td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.1 "><p id="p4694161710123"><a name="p4694161710123"></a><a name="p4694161710123"></a>md</p>
</td>
<td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.2 "><p id="p569551751220"><a name="p569551751220"></a><a name="p569551751220"></a>number|object</p>
</td>
<td class="cellrowborder" valign="top" width="10.48%" headers="mcps1.1.6.1.3 "><p id="p86952172121"><a name="p86952172121"></a><a name="p86952172121"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.449999999999999%" headers="mcps1.1.6.1.4 "><p id="p3695171711214"><a name="p3695171711214"></a><a name="p3695171711214"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="35.83%" headers="mcps1.1.6.1.5 "><p id="p66953176126"><a name="p66953176126"></a><a name="p66953176126"></a>Number of columns occupied by this item and offset columns when <strong id="b1331803320193"><a name="b1331803320193"></a><a name="b1331803320193"></a>sizetype</strong> is <strong id="b9324153381911"><a name="b9324153381911"></a><a name="b9324153381911"></a>md</strong>. If you set the value of the number type, you only set the number of occupied columns. You can set a value of the object type for both the number of occupied columns and offset columns, for example, <strong id="b173250330195"><a name="b173250330195"></a><a name="b173250330195"></a>{"span": 1, "offset": 0}</strong>.</p>
</td>
</tr>
<tr id="row9263155681117"><td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.1 "><p id="p10695101717122"><a name="p10695101717122"></a><a name="p10695101717122"></a>lg</p>
</td>
<td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.2 "><p id="p5695131701217"><a name="p5695131701217"></a><a name="p5695131701217"></a>number|object</p>
</td>
<td class="cellrowborder" valign="top" width="10.48%" headers="mcps1.1.6.1.3 "><p id="p1469501714124"><a name="p1469501714124"></a><a name="p1469501714124"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.449999999999999%" headers="mcps1.1.6.1.4 "><p id="p1769511715127"><a name="p1769511715127"></a><a name="p1769511715127"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="35.83%" headers="mcps1.1.6.1.5 "><p id="p8695111741217"><a name="p8695111741217"></a><a name="p8695111741217"></a>Number of columns occupied by this item and offset columns when <strong id="b148141243141918"><a name="b148141243141918"></a><a name="b148141243141918"></a>sizetype</strong> is <strong id="b1981914316199"><a name="b1981914316199"></a><a name="b1981914316199"></a>lg</strong>. If you set the value of the number type, you only set the number of occupied columns. You can set a value of the object type for both the number of occupied columns and offset columns, for example, <strong id="b8820204320198"><a name="b8820204320198"></a><a name="b8820204320198"></a>{"span": 1, "offset": 0}</strong>.</p>
</td>
</tr>
<tr id="row1236753141115"><td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.1 "><p id="p166957175127"><a name="p166957175127"></a><a name="p166957175127"></a>span</p>
</td>
<td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.2 "><p id="p1569561741210"><a name="p1569561741210"></a><a name="p1569561741210"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="10.48%" headers="mcps1.1.6.1.3 "><p id="p17695201719121"><a name="p17695201719121"></a><a name="p17695201719121"></a>1</p>
</td>
<td class="cellrowborder" valign="top" width="7.449999999999999%" headers="mcps1.1.6.1.4 "><p id="p156951617101214"><a name="p156951617101214"></a><a name="p156951617101214"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="35.83%" headers="mcps1.1.6.1.5 "><p id="p1169581712121"><a name="p1169581712121"></a><a name="p1169581712121"></a>Default number of columns occupied by this item when no breakpoint is set.</p>
</td>
</tr>
<tr id="row1348115011117"><td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.1 "><p id="p12695141741216"><a name="p12695141741216"></a><a name="p12695141741216"></a>offset</p>
</td>
<td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.2 "><p id="p0695131711124"><a name="p0695131711124"></a><a name="p0695131711124"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="10.48%" headers="mcps1.1.6.1.3 "><p id="p8695111710129"><a name="p8695111710129"></a><a name="p8695111710129"></a>0</p>
</td>
<td class="cellrowborder" valign="top" width="7.449999999999999%" headers="mcps1.1.6.1.4 "><p id="p15695111781220"><a name="p15695111781220"></a><a name="p15695111781220"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="35.83%" headers="mcps1.1.6.1.5 "><p id="p2069531710128"><a name="p2069531710128"></a><a name="p2069531710128"></a>Default number of offset columns in the container layout direction when <strong id="b4434112162515"><a name="b4434112162515"></a><a name="b4434112162515"></a>"offset"</strong> is not set for a specific <strong id="b1253195119225"><a name="b1253195119225"></a><a name="b1253195119225"></a>sizetype</strong>.</p>
</td>
</tr>
</tbody>
</table>

## Style<a name="section1948816404128"></a>

In addition to the styles in  [Universal Styles](js-components-common-styles.md), the following styles are supported.

<a name="table282005513017"></a>
<table><thead align="left"><tr id="row168201855113012"><th class="cellrowborder" valign="top" width="23.11768823117688%" id="mcps1.1.6.1.1"><p id="p38201055113016"><a name="p38201055113016"></a><a name="p38201055113016"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="12.218778122187782%" id="mcps1.1.6.1.2"><p id="p3820105573010"><a name="p3820105573010"></a><a name="p3820105573010"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="13.03869613038696%" id="mcps1.1.6.1.3"><p id="p1282065593020"><a name="p1282065593020"></a><a name="p1282065593020"></a>Default Value</p>
</th>
<th class="cellrowborder" valign="top" width="8.4991500849915%" id="mcps1.1.6.1.4"><p id="p2820455103013"><a name="p2820455103013"></a><a name="p2820455103013"></a>Mandatory</p>
</th>
<th class="cellrowborder" valign="top" width="43.12568743125688%" id="mcps1.1.6.1.5"><p id="p8820115573010"><a name="p8820115573010"></a><a name="p8820115573010"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row482195519300"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="p108211555183011"><a name="p108211555183011"></a><a name="p108211555183011"></a>flex-direction</p>
</td>
<td class="cellrowborder" valign="top" width="12.218778122187782%" headers="mcps1.1.6.1.2 "><p id="p6821185583020"><a name="p6821185583020"></a><a name="p6821185583020"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="13.03869613038696%" headers="mcps1.1.6.1.3 "><p id="p108217558305"><a name="p108217558305"></a><a name="p108217558305"></a>row</p>
</td>
<td class="cellrowborder" valign="top" width="8.4991500849915%" headers="mcps1.1.6.1.4 "><p id="p168211655173015"><a name="p168211655173015"></a><a name="p168211655173015"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="43.12568743125688%" headers="mcps1.1.6.1.5 "><p id="p18821165563017"><a name="p18821165563017"></a><a name="p18821165563017"></a>Main axis direction of the container. Available values are as follows:</p>
<a name="ul15821145583019"></a><a name="ul15821145583019"></a><ul id="ul15821145583019"><li><strong id="b1376512564223"><a name="b1376512564223"></a><a name="b1376512564223"></a>column</strong>: Items are placed vertically from top to bottom.</li><li><strong id="b461175812215"><a name="b461175812215"></a><a name="b461175812215"></a>row</strong>: Items are placed horizontally from left to right.</li></ul>
</td>
</tr>
<tr id="row1582115513018"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="p148211055133015"><a name="p148211055133015"></a><a name="p148211055133015"></a>flex-wrap</p>
</td>
<td class="cellrowborder" valign="top" width="12.218778122187782%" headers="mcps1.1.6.1.2 "><p id="p0821055103010"><a name="p0821055103010"></a><a name="p0821055103010"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="13.03869613038696%" headers="mcps1.1.6.1.3 "><p id="p118212557306"><a name="p118212557306"></a><a name="p118212557306"></a>nowrap</p>
</td>
<td class="cellrowborder" valign="top" width="8.4991500849915%" headers="mcps1.1.6.1.4 "><p id="p168211155143015"><a name="p168211155143015"></a><a name="p168211155143015"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="43.12568743125688%" headers="mcps1.1.6.1.5 "><p id="p1382145510309"><a name="p1382145510309"></a><a name="p1382145510309"></a>Whether items in the container are displayed in a single axis or multiple axes. Currently, dynamic modification is not supported. Available values are as follows:</p>
<a name="ul282175510308"></a><a name="ul282175510308"></a><ul id="ul282175510308"><li><strong id="b1899950182014"><a name="b1899950182014"></a><a name="b1899950182014"></a>nowrap</strong>: Items are displayed on a single axis.</li><li><strong id="b18315182162018"><a name="b18315182162018"></a><a name="b18315182162018"></a>wrap</strong>: Items are displayed on multiple axes.</li></ul>
</td>
</tr>
<tr id="row782155583013"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="p1782175512303"><a name="p1782175512303"></a><a name="p1782175512303"></a>justify-content</p>
</td>
<td class="cellrowborder" valign="top" width="12.218778122187782%" headers="mcps1.1.6.1.2 "><p id="p88219557300"><a name="p88219557300"></a><a name="p88219557300"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="13.03869613038696%" headers="mcps1.1.6.1.3 "><p id="p18821855173011"><a name="p18821855173011"></a><a name="p18821855173011"></a>flex-start</p>
</td>
<td class="cellrowborder" valign="top" width="8.4991500849915%" headers="mcps1.1.6.1.4 "><p id="p3821205517302"><a name="p3821205517302"></a><a name="p3821205517302"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="43.12568743125688%" headers="mcps1.1.6.1.5 "><p id="p68219555307"><a name="p68219555307"></a><a name="p68219555307"></a>How items are aligned along the main axis of the current row in the container. Available values are as follows:</p>
<a name="ul782165511302"></a><a name="ul782165511302"></a><ul id="ul782165511302"><li><strong id="b1442428202016"><a name="b1442428202016"></a><a name="b1442428202016"></a>flex-start</strong>: Items are packed towards the start row.</li><li><strong id="b233318913202"><a name="b233318913202"></a><a name="b233318913202"></a>flex-end</strong>: Items are packed towards the end row.</li><li><strong id="b162541410172015"><a name="b162541410172015"></a><a name="b162541410172015"></a>center</strong>: Items are centered along the row.</li><li><strong id="b131513117202"><a name="b131513117202"></a><a name="b131513117202"></a>space-between</strong>: Items are positioned with space between the rows.</li><li><strong id="b1021031292014"><a name="b1021031292014"></a><a name="b1021031292014"></a>space-around</strong>: Items are positioned with space before, between, and after the rows.</li></ul>
</td>
</tr>
<tr id="row182215556305"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="p13822205523020"><a name="p13822205523020"></a><a name="p13822205523020"></a>align-items</p>
</td>
<td class="cellrowborder" valign="top" width="12.218778122187782%" headers="mcps1.1.6.1.2 "><p id="p6822155519300"><a name="p6822155519300"></a><a name="p6822155519300"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="13.03869613038696%" headers="mcps1.1.6.1.3 "><p id="p1982215523014"><a name="p1982215523014"></a><a name="p1982215523014"></a>stretch</p>
</td>
<td class="cellrowborder" valign="top" width="8.4991500849915%" headers="mcps1.1.6.1.4 "><p id="p14822655113020"><a name="p14822655113020"></a><a name="p14822655113020"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="43.12568743125688%" headers="mcps1.1.6.1.5 "><p id="p17822555103011"><a name="p17822555103011"></a><a name="p17822555103011"></a>How items are aligned along the cross axis of the current row in the container. Available values are as follows:</p>
<a name="ul1822185512309"></a><a name="ul1822185512309"></a><ul id="ul1822185512309"><li><strong id="b52351418182019"><a name="b52351418182019"></a><a name="b52351418182019"></a>stretch</strong>: Items are stretched to the same height or width as the container in the cross axis direction. </li><li><strong id="b19675172015207"><a name="b19675172015207"></a><a name="b19675172015207"></a>flex-start</strong>: Items are aligned to the start of the cross axis.</li><li><strong id="b2654721132018"><a name="b2654721132018"></a><a name="b2654721132018"></a>flex-end</strong>: Items are aligned to the end of the cross axis.</li><li><strong id="b4585102215204"><a name="b4585102215204"></a><a name="b4585102215204"></a>center</strong>: Items are aligned in the middle of the cross axis.</li></ul>
</td>
</tr>
<tr id="row158231551309"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="p108231055173010"><a name="p108231055173010"></a><a name="p108231055173010"></a>align-content</p>
</td>
<td class="cellrowborder" valign="top" width="12.218778122187782%" headers="mcps1.1.6.1.2 "><p id="p98231455193012"><a name="p98231455193012"></a><a name="p98231455193012"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="13.03869613038696%" headers="mcps1.1.6.1.3 "><p id="p108232055103011"><a name="p108232055103011"></a><a name="p108232055103011"></a>flex-start</p>
</td>
<td class="cellrowborder" valign="top" width="8.4991500849915%" headers="mcps1.1.6.1.4 "><p id="p198231155153019"><a name="p198231155153019"></a><a name="p198231155153019"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="43.12568743125688%" headers="mcps1.1.6.1.5 "><p id="p1882312558307"><a name="p1882312558307"></a><a name="p1882312558307"></a>Multi-row alignment mode when there is extra space in the cross axis. Available values are as follows:</p>
<a name="ul282335519305"></a><a name="ul282335519305"></a><ul id="ul282335519305"><li><strong id="b232014272206"><a name="b232014272206"></a><a name="b232014272206"></a>flex-start</strong>: All rows are packed towards the start of the cross axis. The start edge of the cross axis of the first row is aligned with the start edge of the cross axis of the container. All subsequent rows are aligned with the previous row.</li><li><strong id="b034111308204"><a name="b034111308204"></a><a name="b034111308204"></a>flex-end</strong>: All rows are packed towards the end of the cross axis. The end of the cross axis of the last row is aligned with the end of the cross axis of the container. All subsequent rows are aligned with the previous row.</li><li><strong id="b58521334203"><a name="b58521334203"></a><a name="b58521334203"></a>center</strong>: All rows are packed towards the center of the container. Rows are close to each other and aligned with the center of the container. The spacing between the start of the container's cross axis and the first row is equal to the spacing between the end of the container's cross axis and the last row.</li><li><strong id="b126908361201"><a name="b126908361201"></a><a name="b126908361201"></a>space-between</strong>: All rows are evenly distributed in the container. The spacing between two adjacent rows is the same. The start and end edges of the container's cross axis are aligned with the edges of the first and last rows, respectively.</li><li><strong id="b19242184011208"><a name="b19242184011208"></a><a name="b19242184011208"></a>space-around</strong>: All rows are evenly distributed in the container, and the spacing between two adjacent rows is the same. The spacing between the start edge of the container's cross axis and the first row and that between the end edge and the last row are half of the spacing between two adjacent rows.</li></ul>
</td>
</tr>
<tr id="row782325510307"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="p5823355143013"><a name="p5823355143013"></a><a name="p5823355143013"></a>display</p>
</td>
<td class="cellrowborder" valign="top" width="12.218778122187782%" headers="mcps1.1.6.1.2 "><p id="p582325563018"><a name="p582325563018"></a><a name="p582325563018"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="13.03869613038696%" headers="mcps1.1.6.1.3 "><p id="p68238557307"><a name="p68238557307"></a><a name="p68238557307"></a>flex</p>
</td>
<td class="cellrowborder" valign="top" width="8.4991500849915%" headers="mcps1.1.6.1.4 "><p id="p182315511303"><a name="p182315511303"></a><a name="p182315511303"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="43.12568743125688%" headers="mcps1.1.6.1.5 "><p id="p1482375503018"><a name="p1482375503018"></a><a name="p1482375503018"></a>Type of the view box of the element. Currently, dynamic modification is not supported. Text alignment mode. Available values include:</p>
<a name="ul6823155153010"></a><a name="ul6823155153010"></a><ul id="ul6823155153010"><li><strong id="b616734818208"><a name="b616734818208"></a><a name="b616734818208"></a>flex</strong>: flexible layout</li><li><strong id="b62721549192011"><a name="b62721549192011"></a><a name="b62721549192011"></a>grid</strong>: grid layout</li><li><strong id="b835965032015"><a name="b835965032015"></a><a name="b835965032015"></a>none</strong>: This item is not rendered.</li></ul>
</td>
</tr>
<tr id="row382411557307"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="p48249553303"><a name="p48249553303"></a><a name="p48249553303"></a>grid-template-[columns|rows]</p>
</td>
<td class="cellrowborder" valign="top" width="12.218778122187782%" headers="mcps1.1.6.1.2 "><p id="p0824115563014"><a name="p0824115563014"></a><a name="p0824115563014"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="13.03869613038696%" headers="mcps1.1.6.1.3 "><p id="p7824185512308"><a name="p7824185512308"></a><a name="p7824185512308"></a>1 row, 1 column</p>
</td>
<td class="cellrowborder" valign="top" width="8.4991500849915%" headers="mcps1.1.6.1.4 "><p id="p782445523018"><a name="p782445523018"></a><a name="p782445523018"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="43.12568743125688%" headers="mcps1.1.6.1.5 "><p id="p1082465513013"><a name="p1082465513013"></a><a name="p1082465513013"></a>Number of rows and columns in the current grid layout. If this attribute is not set, one row and one column are displayed by default. This attribute is valid only when <strong id="b10585155511205"><a name="b10585155511205"></a><a name="b10585155511205"></a>display</strong> is set to <strong id="b105911555201"><a name="b105911555201"></a><a name="b105911555201"></a>grid</strong>.</p>
<p id="p18824145520305"><a name="p18824145520305"></a><a name="p18824145520305"></a>For example, set <strong id="b199088562205"><a name="b199088562205"></a><a name="b199088562205"></a>grid-template-columns</strong> to:</p>
<p id="p68241557304"><a name="p68241557304"></a><a name="p68241557304"></a>(1) <strong id="b9433155813209"><a name="b9433155813209"></a><a name="b9433155813209"></a>50px 100px 60px</strong>: There are three columns. The first column is 50 px, the second column is 100 px, and the third column is 60 px.</p>
<p id="p4824105513305"><a name="p4824105513305"></a><a name="p4824105513305"></a>(2) <strong id="b161711008212"><a name="b161711008212"></a><a name="b161711008212"></a>1fr 1fr 2fr</strong>: There are three columns, and the width allowed by the parent component is divided into four equal shares. The first column occupies one share, the second column occupies one share, and the third column occupies two shares.</p>
<p id="p128242055163011"><a name="p128242055163011"></a><a name="p128242055163011"></a>(3) <strong id="b291228214"><a name="b291228214"></a><a name="b291228214"></a>30% 20% 50%</strong>: There are three columns. The first column occupies 30% of the total width allowed by the parent component, the second column occupies 20%, and the third column occupies 50%.</p>
<p id="p282475514306"><a name="p282475514306"></a><a name="p282475514306"></a>(4) <strong id="b118014510216"><a name="b118014510216"></a><a name="b118014510216"></a>repeat (2,100px)</strong>: There are two columns. The first column is 100 px, and the second column is 100 px.</p>
<p id="p17824185516300"><a name="p17824185516300"></a><a name="p17824185516300"></a>(5) <strong id="b4921587212"><a name="b4921587212"></a><a name="b4921587212"></a>auto 1fr 1fr</strong>: There are three columns. The first column is adaptive to the width required by its child components. The remaining space is divided into two equal shares, one share occupied by each of the two columns.</p>
</td>
</tr>
<tr id="row1882465518305"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="p28241855183010"><a name="p28241855183010"></a><a name="p28241855183010"></a>grid-[columns|rows]-gap</p>
</td>
<td class="cellrowborder" valign="top" width="12.218778122187782%" headers="mcps1.1.6.1.2 "><p id="p6824755103014"><a name="p6824755103014"></a><a name="p6824755103014"></a>&lt;length&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="13.03869613038696%" headers="mcps1.1.6.1.3 "><p id="p1282455553014"><a name="p1282455553014"></a><a name="p1282455553014"></a>0</p>
</td>
<td class="cellrowborder" valign="top" width="8.4991500849915%" headers="mcps1.1.6.1.4 "><p id="p1824125515309"><a name="p1824125515309"></a><a name="p1824125515309"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="43.12568743125688%" headers="mcps1.1.6.1.5 "><p id="p88241255183013"><a name="p88241255183013"></a><a name="p88241255183013"></a>Size of the gap between two consecutive rows or columns in a grid layout. You can also use <strong id="b12431413218"><a name="b12431413218"></a><a name="b12431413218"></a>grid-gap</strong> to set the same size of the gap between rows and columns. This attribute is valid only when <strong id="b173311412210"><a name="b173311412210"></a><a name="b173311412210"></a>display</strong> is set to <strong id="b333214202117"><a name="b333214202117"></a><a name="b333214202117"></a>grid</strong>.</p>
</td>
</tr>
<tr id="row10824135523013"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="p882475513307"><a name="p882475513307"></a><a name="p882475513307"></a>grid-row-[start|end]</p>
</td>
<td class="cellrowborder" valign="top" width="12.218778122187782%" headers="mcps1.1.6.1.2 "><p id="p19824205513018"><a name="p19824205513018"></a><a name="p19824205513018"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="13.03869613038696%" headers="mcps1.1.6.1.3 "><p id="p7824105523012"><a name="p7824105523012"></a><a name="p7824105523012"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="8.4991500849915%" headers="mcps1.1.6.1.4 "><p id="p782445503011"><a name="p782445503011"></a><a name="p782445503011"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="43.12568743125688%" headers="mcps1.1.6.1.5 "><p id="p13824115519302"><a name="p13824115519302"></a><a name="p13824115519302"></a>Start and end row numbers of the current item in the grid layout. This attribute is valid only when <strong id="b10351201882119"><a name="b10351201882119"></a><a name="b10351201882119"></a>display</strong> of the parent component is <strong id="b1435618186213"><a name="b1435618186213"></a><a name="b1435618186213"></a>grid</strong>. (The <strong id="b435641819210"><a name="b435641819210"></a><a name="b435641819210"></a>display</strong> attribute of the parent component can be set to <strong id="b735718181213"><a name="b735718181213"></a><a name="b735718181213"></a>grid</strong> only for the <strong id="b83583181217"><a name="b83583181217"></a><a name="b83583181217"></a>&lt;div&gt;</strong> container.)</p>
</td>
</tr>
<tr id="row1582495513010"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="p48247556301"><a name="p48247556301"></a><a name="p48247556301"></a>grid-column-[start|end]</p>
</td>
<td class="cellrowborder" valign="top" width="12.218778122187782%" headers="mcps1.1.6.1.2 "><p id="p2825455183011"><a name="p2825455183011"></a><a name="p2825455183011"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="13.03869613038696%" headers="mcps1.1.6.1.3 "><p id="p1382545583012"><a name="p1382545583012"></a><a name="p1382545583012"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="8.4991500849915%" headers="mcps1.1.6.1.4 "><p id="p382515553016"><a name="p382515553016"></a><a name="p382515553016"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="43.12568743125688%" headers="mcps1.1.6.1.5 "><p id="p128256553309"><a name="p128256553309"></a><a name="p128256553309"></a>Start and end column numbers of the current item in the grid layout. This attribute is valid only when <strong id="b265219521145"><a name="b265219521145"></a><a name="b265219521145"></a>display</strong> of the parent component is <strong id="b1165835212148"><a name="b1165835212148"></a><a name="b1165835212148"></a>grid</strong>. (The <strong id="b11659195211417"><a name="b11659195211417"></a><a name="b11659195211417"></a>display</strong> attribute of the parent component can be set to <strong id="b76590525147"><a name="b76590525147"></a><a name="b76590525147"></a>grid</strong> only for the <strong id="b1466095261417"><a name="b1466095261417"></a><a name="b1466095261417"></a>&lt;div&gt;</strong> container.)</p>
</td>
</tr>
</tbody>
</table>

>![](../../public_sys-resources/icon-note.gif) **NOTE:** 
>-   Width-related styles are not supported.

## Event<a name="section94351031102113"></a>

Events in  [Universal Events](js-components-common-events.md)  are supported.

## Method<a name="section2279124532420"></a>

Methods in  [Universal Methods](js-components-common-methods.md)  are supported.

## Example Code<a name="section2021865273710"></a>

```
<!-- index.hml -->
<div class="container">
  <grid-container id="mygrid" columns="5" gutter="20px" style="background-color: pink;">
    <grid-row style="height:400px;justify-content:space-around;">
      <grid-col span="1">
        <div style="align-items: center;justify-content: center;height: 100%;width: 100%;">
          <text style="color: dodgerblue;" onclick="getCol">Element text</text>
        </div>
      </grid-col>
      <grid-col span="4" style="background-color:orange;">
        <div style="width: 100%;height: 100%;padding: 20px;align-items: center;">
          <text onclick="getColWidth">Element text</text>
        </div>
      </grid-col>
    </grid-row>
  </grid-container>
</div>
```

```
/* index.css */
.container {
  flex-direction: column;
  padding-top: 80px;
}
```

```
// index.js
import prompt from '@system.prompt';
export default {
  getCol(e) {
    this.$element('mygrid').getColumns(function (result) {
      prompt.showToast({
        message: e.target.id + ' result = ' + result,
        duration: 3000,
      });
    })
  },
  getColWidth(e) {
    this.$element('mygrid').getColumnWidth(function (result) {
      prompt.showToast({
        message: e.target.id + ' result = ' + result,
        duration: 3000,
      });
    })
  }
}
```

