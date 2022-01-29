# Navigation<a name="EN-US_TOPIC_0000001193075106"></a>

>![](../../public_sys-resources/icon-note.gif) **NOTE:** 
>This component is supported since API version 8. Updates will be marked with a superscript to indicate their earliest API version.

The  **<Navigation\>**  component typically functions as the root container of a page and displays the page title, toolbar, and menu through attribute settings.

## Required Permissions<a name="section988262631714"></a>

None

## Child Components<a name="section5989144051714"></a>

This component can contain child components.

## APIs<a name="section97451749121712"></a>

Navigation\(\)

Creates a component that can automatically display the navigation bar, title, and toolbar based on the attribute settings.

## Attributes<a name="section1966485019544"></a>

<a name="table167541053105516"></a>
<table><thead align="left"><tr id="row1875513532552"><th class="cellrowborder" valign="top" width="17.27%" id="mcps1.1.5.1.1"><p id="p107551553135517"><a name="p107551553135517"></a><a name="p107551553135517"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="31.8%" id="mcps1.1.5.1.2"><p id="p13755205312554"><a name="p13755205312554"></a><a name="p13755205312554"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="19.23%" id="mcps1.1.5.1.3"><p id="p11755145375513"><a name="p11755145375513"></a><a name="p11755145375513"></a>Default Value</p>
</th>
<th class="cellrowborder" valign="top" width="31.7%" id="mcps1.1.5.1.4"><p id="p15755053145517"><a name="p15755053145517"></a><a name="p15755053145517"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row187551753195515"><td class="cellrowborder" valign="top" width="17.27%" headers="mcps1.1.5.1.1 "><p id="p275595385515"><a name="p275595385515"></a><a name="p275595385515"></a>title</p>
</td>
<td class="cellrowborder" valign="top" width="31.8%" headers="mcps1.1.5.1.2 "><p id="p10755125312559"><a name="p10755125312559"></a><a name="p10755125312559"></a>string | <a href="../../toctopics/en-us_topic_0000001237475069.md#section2538145016250">CustomBuilder</a></p>
</td>
<td class="cellrowborder" valign="top" width="19.23%" headers="mcps1.1.5.1.3 "><p id="p1675555325512"><a name="p1675555325512"></a><a name="p1675555325512"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="31.7%" headers="mcps1.1.5.1.4 "><p id="p1675513539556"><a name="p1675513539556"></a><a name="p1675513539556"></a>No title</p>
</td>
</tr>
<tr id="row7755153175517"><td class="cellrowborder" valign="top" width="17.27%" headers="mcps1.1.5.1.1 "><p id="p1275545312556"><a name="p1275545312556"></a><a name="p1275545312556"></a>subtitle</p>
</td>
<td class="cellrowborder" valign="top" width="31.8%" headers="mcps1.1.5.1.2 "><p id="p11755453135512"><a name="p11755453135512"></a><a name="p11755453135512"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="19.23%" headers="mcps1.1.5.1.3 "><p id="p167558531551"><a name="p167558531551"></a><a name="p167558531551"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="31.7%" headers="mcps1.1.5.1.4 "><p id="p979915394296"><a name="p979915394296"></a><a name="p979915394296"></a>Subtitle of the page.</p>
</td>
</tr>
<tr id="row2755205305512"><td class="cellrowborder" valign="top" width="17.27%" headers="mcps1.1.5.1.1 "><p id="p19755553115520"><a name="p19755553115520"></a><a name="p19755553115520"></a>menus</p>
</td>
<td class="cellrowborder" valign="top" width="31.8%" headers="mcps1.1.5.1.2 "><p id="p55216364615"><a name="p55216364615"></a><a name="p55216364615"></a>Array&lt;<a href="#table192660141468">NavigationMenuItem</a>&gt; | <a href="../../toctopics/en-us_topic_0000001237475069.md#section2538145016250">CustomBuilder</a></p>
</td>
<td class="cellrowborder" valign="top" width="19.23%" headers="mcps1.1.5.1.3 "><p id="p19755053165514"><a name="p19755053165514"></a><a name="p19755053165514"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="31.7%" headers="mcps1.1.5.1.4 "><p id="p78692471290"><a name="p78692471290"></a><a name="p78692471290"></a>Menu in the upper right corner of the page.</p>
<p id="p10771517652"><a name="p10771517652"></a><a name="p10771517652"></a></p>
</td>
</tr>
<tr id="row127554532551"><td class="cellrowborder" valign="top" width="17.27%" headers="mcps1.1.5.1.1 "><p id="p1875519534552"><a name="p1875519534552"></a><a name="p1875519534552"></a>titleMode</p>
</td>
<td class="cellrowborder" valign="top" width="31.8%" headers="mcps1.1.5.1.2 "><p id="p141172011910"><a name="p141172011910"></a><a name="p141172011910"></a><a href="#li3339655172412">NavigationTitleMode</a></p>
</td>
<td class="cellrowborder" valign="top" width="19.23%" headers="mcps1.1.5.1.3 "><p id="p1578819117304"><a name="p1578819117304"></a><a name="p1578819117304"></a>NavigationTitleMode.Free</p>
</td>
<td class="cellrowborder" valign="top" width="31.7%" headers="mcps1.1.5.1.4 "><p id="p12615195782913"><a name="p12615195782913"></a><a name="p12615195782913"></a>Display mode of the page title bar.</p>
</td>
</tr>
<tr id="row853226151019"><td class="cellrowborder" valign="top" width="17.27%" headers="mcps1.1.5.1.1 "><p id="p454162611102"><a name="p454162611102"></a><a name="p454162611102"></a>toolBar</p>
</td>
<td class="cellrowborder" valign="top" width="31.8%" headers="mcps1.1.5.1.2 "><p id="p514515128225"><a name="p514515128225"></a><a name="p514515128225"></a>{</p>
<p id="p3517755171011"><a name="p3517755171011"></a><a name="p3517755171011"></a>items:[</p>
<p id="p176924331545"><a name="p176924331545"></a><a name="p176924331545"></a><a href="#table192660141468">Object</a></p>
<p id="p1722618388516"><a name="p1722618388516"></a><a name="p1722618388516"></a>] }</p>
<p id="p1251712556108"><a name="p1251712556108"></a><a name="p1251712556108"></a>| <a href="../../toctopics/en-us_topic_0000001237475069.md#section2538145016250">CustomBuilder</a></p>
<p id="p751775510106"><a name="p751775510106"></a><a name="p751775510106"></a></p>
</td>
<td class="cellrowborder" valign="top" width="19.23%" headers="mcps1.1.5.1.3 "><p id="p195472615100"><a name="p195472615100"></a><a name="p195472615100"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="31.7%" headers="mcps1.1.5.1.4 "><p id="p177791949116"><a name="p177791949116"></a><a name="p177791949116"></a>Content of the toolbar.</p>
<p id="p1977944111113"><a name="p1977944111113"></a><a name="p1977944111113"></a><strong id="b14491343193810"><a name="b14491343193810"></a><a name="b14491343193810"></a>items</strong>: all items on the toolbar.</p>
</td>
</tr>
<tr id="row1497643520101"><td class="cellrowborder" valign="top" width="17.27%" headers="mcps1.1.5.1.1 "><p id="p597712351109"><a name="p597712351109"></a><a name="p597712351109"></a>hideToolBar</p>
</td>
<td class="cellrowborder" valign="top" width="31.8%" headers="mcps1.1.5.1.2 "><p id="p1819931915116"><a name="p1819931915116"></a><a name="p1819931915116"></a>boolean</p>
</td>
<td class="cellrowborder" valign="top" width="19.23%" headers="mcps1.1.5.1.3 "><p id="p187092451117"><a name="p187092451117"></a><a name="p187092451117"></a>false</p>
</td>
<td class="cellrowborder" valign="top" width="31.7%" headers="mcps1.1.5.1.4 "><p id="p204442303113"><a name="p204442303113"></a><a name="p204442303113"></a>Whether the toolbar is shown or hidden.</p>
<p id="p15520203201119"><a name="p15520203201119"></a><a name="p15520203201119"></a><strong id="b33411150193820"><a name="b33411150193820"></a><a name="b33411150193820"></a>true</strong>: The toolbar is hidden.</p>
<p id="p76711233181115"><a name="p76711233181115"></a><a name="p76711233181115"></a><strong id="b1760125743814"><a name="b1760125743814"></a><a name="b1760125743814"></a>false</strong>: The toolbar is shown.</p>
</td>
</tr>
<tr id="row736419418298"><td class="cellrowborder" valign="top" width="17.27%" headers="mcps1.1.5.1.1 "><p id="p183531311193014"><a name="p183531311193014"></a><a name="p183531311193014"></a>hideTitleBar</p>
</td>
<td class="cellrowborder" valign="top" width="31.8%" headers="mcps1.1.5.1.2 "><p id="p236524142913"><a name="p236524142913"></a><a name="p236524142913"></a>boolean</p>
</td>
<td class="cellrowborder" valign="top" width="19.23%" headers="mcps1.1.5.1.3 "><p id="p19365545293"><a name="p19365545293"></a><a name="p19365545293"></a>false</p>
</td>
<td class="cellrowborder" valign="top" width="31.7%" headers="mcps1.1.5.1.4 "><p id="p636554132919"><a name="p636554132919"></a><a name="p636554132919"></a>Whether the title bar is hidden.</p>
</td>
</tr>
<tr id="row798716815299"><td class="cellrowborder" valign="top" width="17.27%" headers="mcps1.1.5.1.1 "><p id="p2987484294"><a name="p2987484294"></a><a name="p2987484294"></a>hideBackButton</p>
</td>
<td class="cellrowborder" valign="top" width="31.8%" headers="mcps1.1.5.1.2 "><p id="p4987188162915"><a name="p4987188162915"></a><a name="p4987188162915"></a>boolean</p>
</td>
<td class="cellrowborder" valign="top" width="19.23%" headers="mcps1.1.5.1.3 "><p id="p3987108152910"><a name="p3987108152910"></a><a name="p3987108152910"></a>false</p>
</td>
<td class="cellrowborder" valign="top" width="31.7%" headers="mcps1.1.5.1.4 "><p id="p109871786297"><a name="p109871786297"></a><a name="p109871786297"></a>Whether the back key is hidden.</p>
</td>
</tr>
</tbody>
</table>

-   NavigationMenuItem parameters

    <a name="table192660141468"></a>
    <table><thead align="left"><tr id="row1226617144463"><th class="cellrowborder" valign="top" width="14.542963397925234%" id="mcps1.1.6.1.1"><p id="p4266121418464"><a name="p4266121418464"></a><a name="p4266121418464"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="19.69074182814641%" id="mcps1.1.6.1.2"><p id="p748632215472"><a name="p748632215472"></a><a name="p748632215472"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="6.605989430416913%" id="mcps1.1.6.1.3"><p id="p15266914124618"><a name="p15266914124618"></a><a name="p15266914124618"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="10.080250538265807%" id="mcps1.1.6.1.4"><p id="p11266181415465"><a name="p11266181415465"></a><a name="p11266181415465"></a>Default Value</p>
    </th>
    <th class="cellrowborder" valign="top" width="49.08005480524565%" id="mcps1.1.6.1.5"><p id="p3266414154614"><a name="p3266414154614"></a><a name="p3266414154614"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row1526651444613"><td class="cellrowborder" valign="top" width="14.542963397925234%" headers="mcps1.1.6.1.1 "><p id="p6267131413461"><a name="p6267131413461"></a><a name="p6267131413461"></a>value</p>
    </td>
    <td class="cellrowborder" valign="top" width="19.69074182814641%" headers="mcps1.1.6.1.2 "><p id="p2026710142461"><a name="p2026710142461"></a><a name="p2026710142461"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="6.605989430416913%" headers="mcps1.1.6.1.3 "><p id="p226781424617"><a name="p226781424617"></a><a name="p226781424617"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="10.080250538265807%" headers="mcps1.1.6.1.4 "><p id="p1526751474616"><a name="p1526751474616"></a><a name="p1526751474616"></a>-</p>
    </td>
    <td class="cellrowborder" valign="top" width="49.08005480524565%" headers="mcps1.1.6.1.5 "><p id="p0193124010182"><a name="p0193124010182"></a><a name="p0193124010182"></a>Text of a single option on the menu bar.</p>
    </td>
    </tr>
    <tr id="row20655108171816"><td class="cellrowborder" valign="top" width="14.542963397925234%" headers="mcps1.1.6.1.1 "><p id="p1655198201811"><a name="p1655198201811"></a><a name="p1655198201811"></a>icon</p>
    </td>
    <td class="cellrowborder" valign="top" width="19.69074182814641%" headers="mcps1.1.6.1.2 "><p id="p1265520861818"><a name="p1265520861818"></a><a name="p1265520861818"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="6.605989430416913%" headers="mcps1.1.6.1.3 "><p id="p17655198181818"><a name="p17655198181818"></a><a name="p17655198181818"></a>No</p>
    </td>
    <td class="cellrowborder" valign="top" width="10.080250538265807%" headers="mcps1.1.6.1.4 "><p id="p1765512841819"><a name="p1765512841819"></a><a name="p1765512841819"></a>-</p>
    </td>
    <td class="cellrowborder" valign="top" width="49.08005480524565%" headers="mcps1.1.6.1.5 "><p id="p565588141812"><a name="p565588141812"></a><a name="p565588141812"></a>Icon path of a single option on the menu bar.</p>
    </td>
    </tr>
    <tr id="row2478191217187"><td class="cellrowborder" valign="top" width="14.542963397925234%" headers="mcps1.1.6.1.1 "><p id="p144781212161813"><a name="p144781212161813"></a><a name="p144781212161813"></a>action</p>
    </td>
    <td class="cellrowborder" valign="top" width="19.69074182814641%" headers="mcps1.1.6.1.2 "><p id="p11457934175214"><a name="p11457934175214"></a><a name="p11457934175214"></a>() =&gt; void</p>
    </td>
    <td class="cellrowborder" valign="top" width="6.605989430416913%" headers="mcps1.1.6.1.3 "><p id="p13478151218189"><a name="p13478151218189"></a><a name="p13478151218189"></a>No</p>
    </td>
    <td class="cellrowborder" valign="top" width="10.080250538265807%" headers="mcps1.1.6.1.4 "><p id="p24781312161812"><a name="p24781312161812"></a><a name="p24781312161812"></a>-</p>
    </td>
    <td class="cellrowborder" valign="top" width="49.08005480524565%" headers="mcps1.1.6.1.5 "><p id="p547861271816"><a name="p547861271816"></a><a name="p547861271816"></a>Callback invoked when the option is selected.</p>
    </td>
    </tr>
    </tbody>
    </table>


-   Object attributes

    <a name="table1287613175314"></a>
    <table><thead align="left"><tr id="row48766319535"><th class="cellrowborder" valign="top" width="14.542963397925234%" id="mcps1.1.6.1.1"><p id="p6876103155315"><a name="p6876103155315"></a><a name="p6876103155315"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="19.69074182814641%" id="mcps1.1.6.1.2"><p id="p12876103165315"><a name="p12876103165315"></a><a name="p12876103165315"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="6.605989430416913%" id="mcps1.1.6.1.3"><p id="p1387683145315"><a name="p1387683145315"></a><a name="p1387683145315"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="10.080250538265807%" id="mcps1.1.6.1.4"><p id="p118761331115312"><a name="p118761331115312"></a><a name="p118761331115312"></a>Default Value</p>
    </th>
    <th class="cellrowborder" valign="top" width="49.08005480524565%" id="mcps1.1.6.1.5"><p id="p587623114533"><a name="p587623114533"></a><a name="p587623114533"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row28763317534"><td class="cellrowborder" valign="top" width="14.542963397925234%" headers="mcps1.1.6.1.1 "><p id="p387603115537"><a name="p387603115537"></a><a name="p387603115537"></a>value</p>
    </td>
    <td class="cellrowborder" valign="top" width="19.69074182814641%" headers="mcps1.1.6.1.2 "><p id="p587673114538"><a name="p587673114538"></a><a name="p587673114538"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="6.605989430416913%" headers="mcps1.1.6.1.3 "><p id="p11876173113534"><a name="p11876173113534"></a><a name="p11876173113534"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="10.080250538265807%" headers="mcps1.1.6.1.4 "><p id="p6876531115316"><a name="p6876531115316"></a><a name="p6876531115316"></a>-</p>
    </td>
    <td class="cellrowborder" valign="top" width="49.08005480524565%" headers="mcps1.1.6.1.5 "><p id="p18876131125313"><a name="p18876131125313"></a><a name="p18876131125313"></a>Text of a single option on the toolbar.</p>
    </td>
    </tr>
    <tr id="row10876163165320"><td class="cellrowborder" valign="top" width="14.542963397925234%" headers="mcps1.1.6.1.1 "><p id="p387616313534"><a name="p387616313534"></a><a name="p387616313534"></a>icon</p>
    </td>
    <td class="cellrowborder" valign="top" width="19.69074182814641%" headers="mcps1.1.6.1.2 "><p id="p1787643115537"><a name="p1787643115537"></a><a name="p1787643115537"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="6.605989430416913%" headers="mcps1.1.6.1.3 "><p id="p1887615317531"><a name="p1887615317531"></a><a name="p1887615317531"></a>No</p>
    </td>
    <td class="cellrowborder" valign="top" width="10.080250538265807%" headers="mcps1.1.6.1.4 "><p id="p7876183111533"><a name="p7876183111533"></a><a name="p7876183111533"></a>-</p>
    </td>
    <td class="cellrowborder" valign="top" width="49.08005480524565%" headers="mcps1.1.6.1.5 "><p id="p18876203155315"><a name="p18876203155315"></a><a name="p18876203155315"></a>Icon path of a single option on the toolbar.</p>
    </td>
    </tr>
    <tr id="row1187619317533"><td class="cellrowborder" valign="top" width="14.542963397925234%" headers="mcps1.1.6.1.1 "><p id="p8877103120539"><a name="p8877103120539"></a><a name="p8877103120539"></a>action</p>
    </td>
    <td class="cellrowborder" valign="top" width="19.69074182814641%" headers="mcps1.1.6.1.2 "><p id="p1877153135316"><a name="p1877153135316"></a><a name="p1877153135316"></a>() =&gt; void</p>
    </td>
    <td class="cellrowborder" valign="top" width="6.605989430416913%" headers="mcps1.1.6.1.3 "><p id="p1287793116537"><a name="p1287793116537"></a><a name="p1287793116537"></a>No</p>
    </td>
    <td class="cellrowborder" valign="top" width="10.080250538265807%" headers="mcps1.1.6.1.4 "><p id="p19877193185311"><a name="p19877193185311"></a><a name="p19877193185311"></a>-</p>
    </td>
    <td class="cellrowborder" valign="top" width="49.08005480524565%" headers="mcps1.1.6.1.5 "><p id="p19877143113537"><a name="p19877143113537"></a><a name="p19877143113537"></a>Callback invoked when the option is selected.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   <a name="li3339655172412"></a>NavigationTitleMode enums

    <a name="table12742135111110"></a>
    <table><thead align="left"><tr id="row7742135111114"><th class="cellrowborder" valign="top" width="11.52%" id="mcps1.1.3.1.1"><p id="p1174215118116"><a name="p1174215118116"></a><a name="p1174215118116"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="88.48%" id="mcps1.1.3.1.2"><p id="p16742651818"><a name="p16742651818"></a><a name="p16742651818"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row9742175115114"><td class="cellrowborder" valign="top" width="11.52%" headers="mcps1.1.3.1.1 "><p id="p16742651016"><a name="p16742651016"></a><a name="p16742651016"></a>Free</p>
    </td>
    <td class="cellrowborder" valign="top" width="88.48%" headers="mcps1.1.3.1.2 "><p id="p174318510119"><a name="p174318510119"></a><a name="p174318510119"></a>When the content is a scrollable component, the title shrinks as the content scrolls up (the subtitle fades out with its size remaining unchanged) and restores to the original one as the content scrolls down.</p>
    </td>
    </tr>
    <tr id="row874313511511"><td class="cellrowborder" valign="top" width="11.52%" headers="mcps1.1.3.1.1 "><p id="p19734185914"><a name="p19734185914"></a><a name="p19734185914"></a>Mini</p>
    </td>
    <td class="cellrowborder" valign="top" width="88.48%" headers="mcps1.1.3.1.2 "><p id="p1074313515120"><a name="p1074313515120"></a><a name="p1074313515120"></a>The mode is fixed at subtitle mode (icon + main title and subtitle).</p>
    </td>
    </tr>
    <tr id="row37438519110"><td class="cellrowborder" valign="top" width="11.52%" headers="mcps1.1.3.1.1 "><p id="p67431513112"><a name="p67431513112"></a><a name="p67431513112"></a>Full</p>
    </td>
    <td class="cellrowborder" valign="top" width="88.48%" headers="mcps1.1.3.1.2 "><p id="p1774312514120"><a name="p1774312514120"></a><a name="p1774312514120"></a>The mode is fixed at main title mode (main title and subtitle).</p>
    </td>
    </tr>
    </tbody>
    </table>

    >![](../../public_sys-resources/icon-note.gif) **NOTE:** 
    >Currently, only the scrollable component  **<List\>**  is supported.


## Events<a name="section992435316359"></a>

<a name="table119951413133615"></a>
<table><thead align="left"><tr id="row139951813163619"><th class="cellrowborder" valign="top" width="49.94%" id="mcps1.1.3.1.1"><p id="p399515132360"><a name="p399515132360"></a><a name="p399515132360"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50.06%" id="mcps1.1.3.1.2"><p id="p1199531313369"><a name="p1199531313369"></a><a name="p1199531313369"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row799671373618"><td class="cellrowborder" valign="top" width="49.94%" headers="mcps1.1.3.1.1 "><p id="p1199619138367"><a name="p1199619138367"></a><a name="p1199619138367"></a>onTitleModeChanged(callback: (titleMode: NavigationTitleMode) =&gt; void)</p>
</td>
<td class="cellrowborder" valign="top" width="50.06%" headers="mcps1.1.3.1.2 "><p id="p12996171318367"><a name="p12996171318367"></a><a name="p12996171318367"></a>Triggered when <strong id="b16876934928"><a name="b16876934928"></a><a name="b16876934928"></a>titleMode</strong> is set to <strong id="b1146213217215"><a name="b1146213217215"></a><a name="b1146213217215"></a>NavigationTitleMode.Free</strong> and the title bar mode changes as content scrolls.</p>
</td>
</tr>
</tbody>
</table>

## Example<a name="section4459736105512"></a>

```
/ Example 01
@Entry
@Component
struct NavigationExample {
  private arr: number[] = [0, 1, 2, 3, 4, 5, 6, 7, 8, 9]
  @State hideBar: boolean = true

  @Builder NavigationTitle() {
    Column() {
      Text('title')
        .width(80)
        .height(60)
        .fontColor(Color.Blue)
        .fontSize(30)
    }
    .onClick(() => {
      console.log("title")
    })
  }

  @Builder NavigationMenus() {
    Row() {
      Image('images/add.png')
        .width(25)
        .height(25)
      Image('comment/more.png')
        .width(25)
        .height(25)
        .margin({ left: 30 })
    }.width(100)
  }

  build() {
    Column() {
      Navigation() {
        Search({ value: '', placeholder: "" }).width('85%').margin(26)
        List({ space: 5, initialIndex: 0 }) {
          ForEach(this.arr, (item) => {
            ListItem() {
              Text('' + item)
                .width('90%')
                .height(80)
                .backgroundColor('#3366CC')
                .borderRadius(15)
                .fontSize(16)
                .textAlign(TextAlign.Center)
            }.editable(true)
          }, item => item)
        }
        .listDirection(Axis.Vertical)
        .height(300)
        .margin({ top: 10, left: 18 })
        .width('100%')

        Button(this.hideBar ? "tool bar" : "hide bar")
          .onClick(() => {
            this.hideBar = !this.hideBar
          })
          .margin({ left: 135, top: 60 })
      }
      .title(this.NavigationTitle)
      .subTitle('subtitle')
      .menus(this.NavigationMenus)
      .titleMode(NavigationTitleMode.Free)
      .hideTitleBar(false)
      .hideBackButton(false)
      .onTitleModeChanged((titleModel: NavigationTitleMode) => {
        console.log('titleMode')
      })
      .toolBar({ items: [
        { value: 'app', icon: 'images/grid.svg', action: () => {
          console.log("app")
        } },
        { value: 'add', icon: 'images/add.svg', action: () => {
          console.log("add")
        } },
        { value: 'collect', icon: 'images/collect.svg', action: () => {
          console.log("collect")
        } }] })
      .hideToolBar(this.hideBar)
    }
  }
}
```

![](figures/66666.gif)

```
// Example 02
@Entry
@Component
struct ToolbarBuilderExample {
  @State currentIndex: number = 0
  @State Build: Array<Object> = [
    {
      icon: $r('app.media.ic_public_add'),
      icon_after: $r('app.media.ic_public_addcolor'),
      text: 'add',
      num: 0
    },
    {
      icon: $r('app.media.ic_public_app'),
      icon_after: $r('app.media.ic_public_appcolor'),
      text: 'app',
      num: 1
    },
    {
      icon: $r('app.media.ic_public_collect'),
      icon_after: $r('app.media.ic_public_collectcolor'),
      text: 'collect',
      num: 2
    }
  ]

  @Builder NavigationToolbar() {
    Row() {
      ForEach(this.Build, item => {
        Column() {
          Image(this.currentIndex == item.num ? item.icon_after : item.icon)
            .width(25)
            .height(25)
          Text(item.text)
            .fontColor(this.currentIndex == item.num ? "#ff7500" : "#000000")
        }
        .onClick(() => {
          this.currentIndex = item.num
        })
        .margin({ left: 70 })
      })
    }
  }

  build() {
    Column() {
      Navigation() {
        Flex() {
        }
      }
      .toolBar(this.NavigationToolbar)
    }
  }
}
```

![](figures/duande.gif)

