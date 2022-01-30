# grid-container<a name="EN-US_TOPIC_0000001173324617"></a>

The  **<grid-container\>**  component is the root container of the grid layout. Within the root container, you can use  **<grid-row\>**  and  **<grid-col\>**  for the grid layout.

## Required Permissions<a name="section11257113618419"></a>

None

## Child Component<a name="section9288143101012"></a>

Only the  **<grid-row\>**  component is supported.

## Attributes<a name="section5248929161316"></a>

In addition to the attributes in  [Universal Attributes](js-components-common-attributes.md), the following attributes are supported.

<a name="table20633101642315"></a>
<table><thead align="left"><tr id="row663331618238"><th class="cellrowborder" valign="top" width="23.119999999999997%" id="mcps1.1.6.1.1"><p id="a45273e2103004ff3bdd3375013e96a2a"><a name="a45273e2103004ff3bdd3375013e96a2a"></a><a name="a45273e2103004ff3bdd3375013e96a2a"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="23.119999999999997%" id="mcps1.1.6.1.2"><p id="ad5b10d4a60e44bb4a8bbb3b4416d7b27"><a name="ad5b10d4a60e44bb4a8bbb3b4416d7b27"></a><a name="ad5b10d4a60e44bb4a8bbb3b4416d7b27"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="10.48%" id="mcps1.1.6.1.3"><p id="ab2ae3d9f60d6475ab95ba095851a9d07"><a name="ab2ae3d9f60d6475ab95ba095851a9d07"></a><a name="ab2ae3d9f60d6475ab95ba095851a9d07"></a>Default Value</p>
</th>
<th class="cellrowborder" valign="top" width="7.5200000000000005%" id="mcps1.1.6.1.4"><p id="p824610360217"><a name="p824610360217"></a><a name="p824610360217"></a>Mandatory</p>
</th>
<th class="cellrowborder" valign="top" width="35.76%" id="mcps1.1.6.1.5"><p id="af5c3b773ed0a42e589819a6c8d257ca1"><a name="af5c3b773ed0a42e589819a6c8d257ca1"></a><a name="af5c3b773ed0a42e589819a6c8d257ca1"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row18693825133018"><td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.1 "><p id="p6247162723015"><a name="p6247162723015"></a><a name="p6247162723015"></a>columns</p>
</td>
<td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.2 "><p id="p824742753016"><a name="p824742753016"></a><a name="p824742753016"></a>string | number</p>
</td>
<td class="cellrowborder" valign="top" width="10.48%" headers="mcps1.1.6.1.3 "><p id="p102474272303"><a name="p102474272303"></a><a name="p102474272303"></a>auto</p>
</td>
<td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.6.1.4 "><p id="p0247112733012"><a name="p0247112733012"></a><a name="p0247112733012"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="35.76%" headers="mcps1.1.6.1.5 "><p id="p224762773015"><a name="p224762773015"></a><a name="p224762773015"></a>Total number of columns in the grid. If a value of the string type is set, it can only be <strong id="b7289163434214"><a name="b7289163434214"></a><a name="b7289163434214"></a>auto</strong>. In this case, the total number of columns is determined based on the current <strong id="b9588131715436"><a name="b9588131715436"></a><a name="b9588131715436"></a>sizetype</strong>, which can be one of the following values:</p>
<a name="ul9387744161011"></a><a name="ul9387744161011"></a><ul id="ul9387744161011"><li><strong id="b2081320274437"><a name="b2081320274437"></a><a name="b2081320274437"></a>xs</strong>: 2 columns</li><li><strong id="b712963416437"><a name="b712963416437"></a><a name="b712963416437"></a>sm</strong>: 4 columns</li><li><strong id="b420975024310"><a name="b420975024310"></a><a name="b420975024310"></a>md</strong>: 8 columns</li><li><strong id="b183281655114316"><a name="b183281655114316"></a><a name="b183281655114316"></a>lg</strong>: 12 columns</li></ul>
</td>
</tr>
<tr id="row2866142283019"><td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.1 "><p id="p52471927173014"><a name="p52471927173014"></a><a name="p52471927173014"></a>sizetype</p>
</td>
<td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.2 "><p id="p92470270304"><a name="p92470270304"></a><a name="p92470270304"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="10.48%" headers="mcps1.1.6.1.3 "><p id="p5247172773018"><a name="p5247172773018"></a><a name="p5247172773018"></a>auto</p>
</td>
<td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.6.1.4 "><p id="p124772703014"><a name="p124772703014"></a><a name="p124772703014"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="35.76%" headers="mcps1.1.6.1.5 "><p id="p7247627163020"><a name="p7247627163020"></a><a name="p7247627163020"></a>Size-responsive type of the grid. Available values are <strong id="b91463252455"><a name="b91463252455"></a><a name="b91463252455"></a>xs</strong>, <strong id="b1714732794517"><a name="b1714732794517"></a><a name="b1714732794517"></a>sm</strong>, <strong id="b15924192884519"><a name="b15924192884519"></a><a name="b15924192884519"></a>md</strong>, and <strong id="b15978430104510"><a name="b15978430104510"></a><a name="b15978430104510"></a>lg</strong>. If the default value <strong id="b101844241462"><a name="b101844241462"></a><a name="b101844241462"></a>auto</strong> is used, the framework automatically selects one of the four types based on the current container size.</p>
</td>
</tr>
<tr id="row275616196304"><td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.1 "><p id="p9247122719308"><a name="p9247122719308"></a><a name="p9247122719308"></a>gutter</p>
</td>
<td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.2 "><p id="p1424718278304"><a name="p1424718278304"></a><a name="p1424718278304"></a>&lt;length&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="10.48%" headers="mcps1.1.6.1.3 "><p id="p92471627133011"><a name="p92471627133011"></a><a name="p92471627133011"></a>24px</p>
</td>
<td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.6.1.4 "><p id="p15247202713010"><a name="p15247202713010"></a><a name="p15247202713010"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="35.76%" headers="mcps1.1.6.1.5 "><p id="p16247192714308"><a name="p16247192714308"></a><a name="p16247192714308"></a>Gutter width</p>
</td>
</tr>
<tr id="row164131050102817"><td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.1 "><p id="p1941415503284"><a name="p1941415503284"></a><a name="p1941415503284"></a>gridtemplate<sup id="sup105523732920"><a name="sup105523732920"></a><a name="sup105523732920"></a>6+</sup></p>
</td>
<td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.2 "><p id="p94141850142816"><a name="p94141850142816"></a><a name="p94141850142816"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="10.48%" headers="mcps1.1.6.1.3 "><p id="p34141950172810"><a name="p34141950172810"></a><a name="p34141950172810"></a>default</p>
</td>
<td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.6.1.4 "><p id="p104141550172811"><a name="p104141550172811"></a><a name="p104141550172811"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="35.76%" headers="mcps1.1.6.1.5 "><p id="p5414150172819"><a name="p5414150172819"></a><a name="p5414150172819"></a>Layout template of the grid, which defines the columns, gutters, and margins for different size-responsive types. This attribute is available when <strong id="b1258512715617"><a name="b1258512715617"></a><a name="b1258512715617"></a>columns</strong> and <strong id="b476518131765"><a name="b476518131765"></a><a name="b476518131765"></a>sizetype</strong> are set to <strong id="b148138151263"><a name="b148138151263"></a><a name="b148138151263"></a>auto</strong>. For details about the values, see <a href="#table135645386317">gridtemplate options</a>.</p>
</td>
</tr>
</tbody>
</table>

**Table  1**  gridtemplate options<sup>6+</sup>

<a name="table135645386317"></a>
<table><thead align="left"><tr id="row256563853117"><th class="cellrowborder" valign="top" width="11.52769446110778%" id="mcps1.2.7.1.1">&nbsp;&nbsp;</th>
<th class="cellrowborder" valign="top" width="14.487102579484104%" id="mcps1.2.7.1.2"><p id="p65657386312"><a name="p65657386312"></a><a name="p65657386312"></a>Template Value</p>
</th>
<th class="cellrowborder" valign="top" width="18.49630073985203%" id="mcps1.2.7.1.3"><p id="p1956553833119"><a name="p1956553833119"></a><a name="p1956553833119"></a>Size-responsive Type</p>
</th>
<th class="cellrowborder" valign="top" width="18.49630073985203%" id="mcps1.2.7.1.4"><p id="p3565103873115"><a name="p3565103873115"></a><a name="p3565103873115"></a>Columns</p>
</th>
<th class="cellrowborder" valign="top" width="18.49630073985203%" id="mcps1.2.7.1.5"><p id="p3565438123118"><a name="p3565438123118"></a><a name="p3565438123118"></a>Margins(px)</p>
</th>
<th class="cellrowborder" valign="top" width="18.49630073985203%" id="mcps1.2.7.1.6"><p id="p8565193843119"><a name="p8565193843119"></a><a name="p8565193843119"></a>Gutters(px)</p>
</th>
</tr>
</thead>
<tbody><tr id="row35651438163116"><td class="cellrowborder" rowspan="4" valign="top" width="11.52769446110778%" headers="mcps1.2.7.1.1 "><p id="p1070922164816"><a name="p1070922164816"></a><a name="p1070922164816"></a>Default grid</p>
</td>
<td class="cellrowborder" rowspan="4" valign="top" width="14.487102579484104%" headers="mcps1.2.7.1.2 "><p id="p165657381311"><a name="p165657381311"></a><a name="p165657381311"></a>default</p>
</td>
<td class="cellrowborder" valign="top" width="18.49630073985203%" headers="mcps1.2.7.1.3 "><p id="p1956518386313"><a name="p1956518386313"></a><a name="p1956518386313"></a>xs</p>
</td>
<td class="cellrowborder" valign="top" width="18.49630073985203%" headers="mcps1.2.7.1.4 "><p id="p1156683863116"><a name="p1156683863116"></a><a name="p1156683863116"></a>2</p>
</td>
<td class="cellrowborder" valign="top" width="18.49630073985203%" headers="mcps1.2.7.1.5 "><p id="p1156603833110"><a name="p1156603833110"></a><a name="p1156603833110"></a>12</p>
</td>
<td class="cellrowborder" valign="top" width="18.49630073985203%" headers="mcps1.2.7.1.6 "><p id="p0566203818310"><a name="p0566203818310"></a><a name="p0566203818310"></a>12</p>
</td>
</tr>
<tr id="row7566133843118"><td class="cellrowborder" valign="top" headers="mcps1.2.7.1.1 "><p id="p456615380314"><a name="p456615380314"></a><a name="p456615380314"></a>sm</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.7.1.2 "><p id="p2566103818314"><a name="p2566103818314"></a><a name="p2566103818314"></a>4</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.7.1.3 "><p id="p18566123833111"><a name="p18566123833111"></a><a name="p18566123833111"></a>24</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.7.1.4 "><p id="p115661438173119"><a name="p115661438173119"></a><a name="p115661438173119"></a>24</p>
</td>
</tr>
<tr id="row1456616389317"><td class="cellrowborder" valign="top" headers="mcps1.2.7.1.1 "><p id="p35661138173117"><a name="p35661138173117"></a><a name="p35661138173117"></a>md</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.7.1.2 "><p id="p13566203812311"><a name="p13566203812311"></a><a name="p13566203812311"></a>8</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.7.1.3 "><p id="p17566103819319"><a name="p17566103819319"></a><a name="p17566103819319"></a>32</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.7.1.4 "><p id="p11566173814316"><a name="p11566173814316"></a><a name="p11566173814316"></a>24</p>
</td>
</tr>
<tr id="row135873533313"><td class="cellrowborder" valign="top" headers="mcps1.2.7.1.1 "><p id="p1558711543319"><a name="p1558711543319"></a><a name="p1558711543319"></a>lg</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.7.1.2 "><p id="p185889523318"><a name="p185889523318"></a><a name="p185889523318"></a>12</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.7.1.3 "><p id="p1658815513315"><a name="p1658815513315"></a><a name="p1658815513315"></a>48</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.7.1.4 "><p id="p145882517336"><a name="p145882517336"></a><a name="p145882517336"></a>24</p>
</td>
</tr>
<tr id="row375535115395"><td class="cellrowborder" rowspan="3" valign="top" width="11.52769446110778%" headers="mcps1.2.7.1.1 "><p id="p84201325134819"><a name="p84201325134819"></a><a name="p84201325134819"></a>Grid layout</p>
</td>
<td class="cellrowborder" rowspan="3" valign="top" width="14.487102579484104%" headers="mcps1.2.7.1.2 "><p id="p147956315402"><a name="p147956315402"></a><a name="p147956315402"></a>grid</p>
</td>
<td class="cellrowborder" valign="top" width="18.49630073985203%" headers="mcps1.2.7.1.3 "><p id="p675625173915"><a name="p675625173915"></a><a name="p675625173915"></a>sm (0 &lt; device horizontal resolution &lt; 600px)</p>
</td>
<td class="cellrowborder" valign="top" width="18.49630073985203%" headers="mcps1.2.7.1.4 "><p id="p10756851163916"><a name="p10756851163916"></a><a name="p10756851163916"></a>4</p>
</td>
<td class="cellrowborder" valign="top" width="18.49630073985203%" headers="mcps1.2.7.1.5 "><p id="p67561651123914"><a name="p67561651123914"></a><a name="p67561651123914"></a>24</p>
</td>
<td class="cellrowborder" valign="top" width="18.49630073985203%" headers="mcps1.2.7.1.6 "><p id="p4756125119398"><a name="p4756125119398"></a><a name="p4756125119398"></a>12</p>
</td>
</tr>
<tr id="row1796215541391"><td class="cellrowborder" valign="top" headers="mcps1.2.7.1.1 "><p id="p1996235416399"><a name="p1996235416399"></a><a name="p1996235416399"></a>md</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.7.1.2 "><p id="p1896285411394"><a name="p1896285411394"></a><a name="p1896285411394"></a>8</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.7.1.3 "><p id="p9962185416391"><a name="p9962185416391"></a><a name="p9962185416391"></a>32</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.7.1.4 "><p id="p696235412394"><a name="p696235412394"></a><a name="p696235412394"></a>12</p>
</td>
</tr>
<tr id="row12335758203911"><td class="cellrowborder" valign="top" headers="mcps1.2.7.1.1 "><p id="p03359587398"><a name="p03359587398"></a><a name="p03359587398"></a>lg</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.7.1.2 "><p id="p2033514589392"><a name="p2033514589392"></a><a name="p2033514589392"></a>12</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.7.1.3 "><p id="p23354588392"><a name="p23354588392"></a><a name="p23354588392"></a>48</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.7.1.4 "><p id="p15335358123917"><a name="p15335358123917"></a><a name="p15335358123917"></a>12</p>
</td>
</tr>
</tbody>
</table>

>![](../../public_sys-resources/icon-note.gif) **NOTE:** 
>
>-   The px unit is applicable when  **autoDesignWidth**  is set to  **true**  in the "js" tag.  <sup>6+</sup>

## Styles<a name="section16690243163414"></a>

In addition to the styles in  [Universal Styles](js-components-common-styles.md), the following styles are supported.

<a name="table1386942213254"></a>
<table><thead align="left"><tr id="row1886913223255"><th class="cellrowborder" valign="top" width="23.11768823117688%" id="mcps1.1.6.1.1"><p id="p68690228255"><a name="p68690228255"></a><a name="p68690228255"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="12.80871912808719%" id="mcps1.1.6.1.2"><p id="p14869822112518"><a name="p14869822112518"></a><a name="p14869822112518"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="13.498650134986503%" id="mcps1.1.6.1.3"><p id="p15869192217258"><a name="p15869192217258"></a><a name="p15869192217258"></a>Default Value</p>
</th>
<th class="cellrowborder" valign="top" width="7.56924307569243%" id="mcps1.1.6.1.4"><p id="p1486982212516"><a name="p1486982212516"></a><a name="p1486982212516"></a>Mandatory</p>
</th>
<th class="cellrowborder" valign="top" width="43.00569943005699%" id="mcps1.1.6.1.5"><p id="p10869722192510"><a name="p10869722192510"></a><a name="p10869722192510"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row7869322142518"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="p16869162213256"><a name="p16869162213256"></a><a name="p16869162213256"></a>justify-content</p>
</td>
<td class="cellrowborder" valign="top" width="12.80871912808719%" headers="mcps1.1.6.1.2 "><p id="p1386912214258"><a name="p1386912214258"></a><a name="p1386912214258"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="13.498650134986503%" headers="mcps1.1.6.1.3 "><p id="p19869172292512"><a name="p19869172292512"></a><a name="p19869172292512"></a>flex-start</p>
</td>
<td class="cellrowborder" valign="top" width="7.56924307569243%" headers="mcps1.1.6.1.4 "><p id="p68702022122511"><a name="p68702022122511"></a><a name="p68702022122511"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="43.00569943005699%" headers="mcps1.1.6.1.5 "><p id="p387092216251"><a name="p387092216251"></a><a name="p387092216251"></a>How items are aligned along the main axis of the current row in the container. Available values are as follows:</p>
<a name="ul10870182213257"></a><a name="ul10870182213257"></a><ul id="ul10870182213257"><li><strong id="b51288404238"><a name="b51288404238"></a><a name="b51288404238"></a>flex-start</strong>: Items are packed towards the start row.</li><li><strong id="b5644141515401"><a name="b5644141515401"></a><a name="b5644141515401"></a>flex-end</strong>: Items are packed towards the end row.</li><li><strong id="b7864161612403"><a name="b7864161612403"></a><a name="b7864161612403"></a>center</strong>: Items are centered along the row.</li><li><strong id="b88480177406"><a name="b88480177406"></a><a name="b88480177406"></a>space-between</strong>: Items are positioned with space between the rows.</li><li><strong id="b18281819184011"><a name="b18281819184011"></a><a name="b18281819184011"></a>space-around</strong>: Items are positioned with space before, between, and after the rows.</li></ul>
</td>
</tr>
<tr id="row15870152282510"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="p1687032217257"><a name="p1687032217257"></a><a name="p1687032217257"></a>align-items</p>
</td>
<td class="cellrowborder" valign="top" width="12.80871912808719%" headers="mcps1.1.6.1.2 "><p id="p1587032212513"><a name="p1587032212513"></a><a name="p1587032212513"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="13.498650134986503%" headers="mcps1.1.6.1.3 "><p id="p98701322122512"><a name="p98701322122512"></a><a name="p98701322122512"></a>stretch</p>
</td>
<td class="cellrowborder" valign="top" width="7.56924307569243%" headers="mcps1.1.6.1.4 "><p id="p48701322192515"><a name="p48701322192515"></a><a name="p48701322192515"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="43.00569943005699%" headers="mcps1.1.6.1.5 "><p id="p68701122112519"><a name="p68701122112519"></a><a name="p68701122112519"></a>How items are aligned along the cross axis of the current row in the container. Available values are as follows:</p>
<a name="ul3870122212514"></a><a name="ul3870122212514"></a><ul id="ul3870122212514"><li><strong id="b15990175016232"><a name="b15990175016232"></a><a name="b15990175016232"></a>stretch</strong>: Items are stretched to the same height or width as the container in the cross axis direction. </li><li><strong id="b524165320338"><a name="b524165320338"></a><a name="b524165320338"></a>flex-start</strong>: Items are aligned to the start of the cross axis.</li><li><strong id="b676224516400"><a name="b676224516400"></a><a name="b676224516400"></a>flex-end</strong>: Items are aligned to the end of the cross axis.</li><li><strong id="b364214812409"><a name="b364214812409"></a><a name="b364214812409"></a>center</strong>: Items are aligned in the middle of the cross axis.</li></ul>
</td>
</tr>
<tr id="row087015224259"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="p1870722182510"><a name="p1870722182510"></a><a name="p1870722182510"></a>align-content</p>
</td>
<td class="cellrowborder" valign="top" width="12.80871912808719%" headers="mcps1.1.6.1.2 "><p id="p18870122242511"><a name="p18870122242511"></a><a name="p18870122242511"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="13.498650134986503%" headers="mcps1.1.6.1.3 "><p id="p587016227256"><a name="p587016227256"></a><a name="p587016227256"></a>flex-start</p>
</td>
<td class="cellrowborder" valign="top" width="7.56924307569243%" headers="mcps1.1.6.1.4 "><p id="p587117228254"><a name="p587117228254"></a><a name="p587117228254"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="43.00569943005699%" headers="mcps1.1.6.1.5 "><p id="p168715228251"><a name="p168715228251"></a><a name="p168715228251"></a>Multi-row alignment mode when there is extra space in the cross axis. Available values are as follows:</p>
<a name="ul38718227256"></a><a name="ul38718227256"></a><ul id="ul38718227256"><li><strong id="b6835336414"><a name="b6835336414"></a><a name="b6835336414"></a>flex-start</strong>: All rows are packed towards the start of the cross axis. The start edge of the cross axis of the first row is aligned with the start edge of the cross axis of the container. All subsequent rows are aligned with the previous row.</li><li><strong id="b16351217154115"><a name="b16351217154115"></a><a name="b16351217154115"></a>flex-end</strong>: All rows are packed towards the end of the cross axis. The end of the cross axis of the last row is aligned with the end of the cross axis of the container. All subsequent rows are aligned with the previous row.</li><li><strong id="b122251326204112"><a name="b122251326204112"></a><a name="b122251326204112"></a>center</strong>: All rows are packed towards the center of the container. Rows are close to each other and aligned with the center of the container. The spacing between the start of the container's cross axis and the first row is equal to the spacing between the end of the container's cross axis and the last row.</li><li><strong id="b193979315414"><a name="b193979315414"></a><a name="b193979315414"></a>space-between</strong>: All rows are evenly distributed in the container. The spacing between two adjacent rows is the same. The start and end edges of the container's cross axis are aligned with the edges of the first and last rows, respectively.</li><li><strong id="b1724683484119"><a name="b1724683484119"></a><a name="b1724683484119"></a>space-around</strong>: All rows are evenly distributed in the container, and the spacing between two adjacent rows is the same. The spacing between the start edge of the container's cross axis and the first row and that between the end edge and the last row are half of the spacing between two adjacent rows.</li></ul>
</td>
</tr>
</tbody>
</table>

## Events<a name="section291933813509"></a>

Events in  [Universal Events](js-components-common-events.md)  are supported.

## Method<a name="section13156101584913"></a>

In addition to the methods in  [Universal Methods](js-components-common-methods.md), the following events are supported.

<a name="t26fe2ddff8674cc38a3a1ec490b76e2f"></a>
<table><thead align="left"><tr id="r237544a789f74f4599b0688cdb75239a"><th class="cellrowborder" valign="top" width="23%" id="mcps1.1.4.1.1"><p id="a897dc10a0e4e45bc94f02c558c679435"><a name="a897dc10a0e4e45bc94f02c558c679435"></a><a name="a897dc10a0e4e45bc94f02c558c679435"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="32%" id="mcps1.1.4.1.2"><p id="ac86c6eca347b48e9a749143ecf54f38f"><a name="ac86c6eca347b48e9a749143ecf54f38f"></a><a name="ac86c6eca347b48e9a749143ecf54f38f"></a>Parameter</p>
</th>
<th class="cellrowborder" valign="top" width="45%" id="mcps1.1.4.1.3"><p id="a0050d08b0c5744de88990d92ef35d3b1"><a name="a0050d08b0c5744de88990d92ef35d3b1"></a><a name="a0050d08b0c5744de88990d92ef35d3b1"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="r08b3c58c981c42a390dc730286c9ce95"><td class="cellrowborder" valign="top" width="23%" headers="mcps1.1.4.1.1 "><p id="p191499655120"><a name="p191499655120"></a><a name="p191499655120"></a>getColumns</p>
</td>
<td class="cellrowborder" valign="top" width="32%" headers="mcps1.1.4.1.2 "><p id="p16149146105111"><a name="p16149146105111"></a><a name="p16149146105111"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="45%" headers="mcps1.1.4.1.3 "><p id="p51491967515"><a name="p51491967515"></a><a name="p51491967515"></a>Returns the number of columns in the grid.</p>
</td>
</tr>
<tr id="row89901747115010"><td class="cellrowborder" valign="top" width="23%" headers="mcps1.1.4.1.1 "><p id="p121491167519"><a name="p121491167519"></a><a name="p121491167519"></a>getColumnWidth</p>
</td>
<td class="cellrowborder" valign="top" width="32%" headers="mcps1.1.4.1.2 "><p id="p514914615113"><a name="p514914615113"></a><a name="p514914615113"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="45%" headers="mcps1.1.4.1.3 "><p id="p81491761519"><a name="p81491761519"></a><a name="p81491761519"></a>Returns the column width of the grid.</p>
</td>
</tr>
<tr id="row440095118508"><td class="cellrowborder" valign="top" width="23%" headers="mcps1.1.4.1.1 "><p id="p614919617515"><a name="p614919617515"></a><a name="p614919617515"></a>getGutterWidth</p>
</td>
<td class="cellrowborder" valign="top" width="32%" headers="mcps1.1.4.1.2 "><p id="p91498685115"><a name="p91498685115"></a><a name="p91498685115"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="45%" headers="mcps1.1.4.1.3 "><p id="p51495615511"><a name="p51495615511"></a><a name="p51495615511"></a>Returns the gutter width between columns of the grid.</p>
</td>
</tr>
<tr id="row1340723513"><td class="cellrowborder" valign="top" width="23%" headers="mcps1.1.4.1.1 "><p id="p31495615517"><a name="p31495615517"></a><a name="p31495615517"></a>getSizeType</p>
</td>
<td class="cellrowborder" valign="top" width="32%" headers="mcps1.1.4.1.2 "><p id="p1014956185118"><a name="p1014956185118"></a><a name="p1014956185118"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="45%" headers="mcps1.1.4.1.3 "><p id="p1414911617515"><a name="p1414911617515"></a><a name="p1414911617515"></a>Returns the size-responsive type of the grid container, which can be <strong id="b1935468442"><a name="b1935468442"></a><a name="b1935468442"></a>xs</strong>, <strong id="b79446104417"><a name="b79446104417"></a><a name="b79446104417"></a>sm</strong>, <strong id="b179546164415"><a name="b179546164415"></a><a name="b179546164415"></a>md</strong>, or <strong id="b910346144414"><a name="b910346144414"></a><a name="b910346144414"></a>lg</strong>.</p>
</td>
</tr>
</tbody>
</table>

## Example Code<a name="section132671420142616"></a>

For details, see  [grid-col](js-components-grid-col.md).

