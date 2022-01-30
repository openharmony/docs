# Popup Control<a name="EN-US_TOPIC_0000001192755120"></a>

>![](../../public_sys-resources/icon-note.gif) **NOTE:** 
>This attribute is supported since API version 7. Updates will be marked with a superscript to indicate their earliest API version.

## Required Permissions<a name="section781125411508"></a>

None

## Attributes<a name="section6820191711316"></a>

<a name="table3856mcpsimp"></a>
<table><thead align="left"><tr id="row3864mcpsimp"><th class="cellrowborder" valign="top" width="12.088791120887912%" id="mcps1.1.5.1.1"><p id="p3866mcpsimp"><a name="p3866mcpsimp"></a><a name="p3866mcpsimp"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="42.165783421657835%" id="mcps1.1.5.1.2"><p id="p3868mcpsimp"><a name="p3868mcpsimp"></a><a name="p3868mcpsimp"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="9.849015098490153%" id="mcps1.1.5.1.3"><p id="p3870mcpsimp"><a name="p3870mcpsimp"></a><a name="p3870mcpsimp"></a>Default Value</p>
</th>
<th class="cellrowborder" valign="top" width="35.896410358964104%" id="mcps1.1.5.1.4"><p id="p3874mcpsimp"><a name="p3874mcpsimp"></a><a name="p3874mcpsimp"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row3875mcpsimp"><td class="cellrowborder" valign="top" width="12.088791120887912%" headers="mcps1.1.5.1.1 "><p id="p18207172943415"><a name="p18207172943415"></a><a name="p18207172943415"></a>bindPopup</p>
</td>
<td class="cellrowborder" valign="top" width="42.165783421657835%" headers="mcps1.1.5.1.2 "><p id="p1895115541642"><a name="p1895115541642"></a><a name="p1895115541642"></a>show: boolean,</p>
<p id="p831713614349"><a name="p831713614349"></a><a name="p831713614349"></a>popup: <a href="#table1488313583914">PopupOption</a> | <a href="#table192660141468">CustomPopupOption</a></p>
</td>
<td class="cellrowborder" valign="top" width="9.849015098490153%" headers="mcps1.1.5.1.3 "><p id="p3881mcpsimp"><a name="p3881mcpsimp"></a><a name="p3881mcpsimp"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="35.896410358964104%" headers="mcps1.1.5.1.4 "><p id="p1032412610614"><a name="p1032412610614"></a><a name="p1032412610614"></a>Settings of the popup bound to a component.</p>
<p id="p14394133110614"><a name="p14394133110614"></a><a name="p14394133110614"></a><strong id="b31631743193718"><a name="b31631743193718"></a><a name="b31631743193718"></a>show</strong>: whether to display the popup message on the creation page by default. The default value is <strong id="b4850184514390"><a name="b4850184514390"></a><a name="b4850184514390"></a>false</strong>.</p>
<p id="p3885mcpsimp"><a name="p3885mcpsimp"></a><a name="p3885mcpsimp"></a>popup: parameters of the current popup window.</p>
</td>
</tr>
</tbody>
</table>

-   PopupOption APIs

    <a name="table1488313583914"></a>
    <table><thead align="left"><tr id="row3883659398"><th class="cellrowborder" valign="top" width="17.723624975533372%" id="mcps1.1.6.1.1"><p id="p188835515399"><a name="p188835515399"></a><a name="p188835515399"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="20.82599334507731%" id="mcps1.1.6.1.2"><p id="p8883155173915"><a name="p8883155173915"></a><a name="p8883155173915"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="8.426306517909572%" id="mcps1.1.6.1.3"><p id="p58841456398"><a name="p58841456398"></a><a name="p58841456398"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="11.94950088079859%" id="mcps1.1.6.1.4"><p id="p118845512394"><a name="p118845512394"></a><a name="p118845512394"></a>Default Value</p>
    </th>
    <th class="cellrowborder" valign="top" width="41.074574280681155%" id="mcps1.1.6.1.5"><p id="p688495143916"><a name="p688495143916"></a><a name="p688495143916"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row1788414593919"><td class="cellrowborder" valign="top" width="17.723624975533372%" headers="mcps1.1.6.1.1 "><p id="p19916122516126"><a name="p19916122516126"></a><a name="p19916122516126"></a>message</p>
    </td>
    <td class="cellrowborder" valign="top" width="20.82599334507731%" headers="mcps1.1.6.1.2 "><p id="p1191602581213"><a name="p1191602581213"></a><a name="p1191602581213"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="8.426306517909572%" headers="mcps1.1.6.1.3 "><p id="p189171725131212"><a name="p189171725131212"></a><a name="p189171725131212"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="11.94950088079859%" headers="mcps1.1.6.1.4 "><p id="p169171125151210"><a name="p169171125151210"></a><a name="p169171125151210"></a>-</p>
    </td>
    <td class="cellrowborder" valign="top" width="41.074574280681155%" headers="mcps1.1.6.1.5 "><p id="p159172251128"><a name="p159172251128"></a><a name="p159172251128"></a>Content of the popup message.</p>
    </td>
    </tr>
    <tr id="row12940102711110"><td class="cellrowborder" valign="top" width="17.723624975533372%" headers="mcps1.1.6.1.1 "><p id="p1141114621219"><a name="p1141114621219"></a><a name="p1141114621219"></a>placementOnTop</p>
    </td>
    <td class="cellrowborder" valign="top" width="20.82599334507731%" headers="mcps1.1.6.1.2 "><p id="p1714164681216"><a name="p1714164681216"></a><a name="p1714164681216"></a>boolean</p>
    </td>
    <td class="cellrowborder" valign="top" width="8.426306517909572%" headers="mcps1.1.6.1.3 "><p id="p214194641218"><a name="p214194641218"></a><a name="p214194641218"></a>No</p>
    </td>
    <td class="cellrowborder" valign="top" width="11.94950088079859%" headers="mcps1.1.6.1.4 "><p id="p13141184617129"><a name="p13141184617129"></a><a name="p13141184617129"></a>false</p>
    </td>
    <td class="cellrowborder" valign="top" width="41.074574280681155%" headers="mcps1.1.6.1.5 "><p id="p1514117463122"><a name="p1514117463122"></a><a name="p1514117463122"></a>Whether to display the popup message above the component. The default value is <strong id="b8989131124619"><a name="b8989131124619"></a><a name="b8989131124619"></a>false</strong>.</p>
    </td>
    </tr>
    <tr id="row39661446161412"><td class="cellrowborder" valign="top" width="17.723624975533372%" headers="mcps1.1.6.1.1 "><p id="p99661946111418"><a name="p99661946111418"></a><a name="p99661946111418"></a>primaryButton</p>
    </td>
    <td class="cellrowborder" valign="top" width="20.82599334507731%" headers="mcps1.1.6.1.2 "><p id="p1723754771318"><a name="p1723754771318"></a><a name="p1723754771318"></a>{</p>
    <p id="p1553014716310"><a name="p1553014716310"></a><a name="p1553014716310"></a>value: string,</p>
    <p id="p2282164681314"><a name="p2282164681314"></a><a name="p2282164681314"></a>action: () =&gt; void</p>
    <p id="p133191116156"><a name="p133191116156"></a><a name="p133191116156"></a>}</p>
    </td>
    <td class="cellrowborder" valign="top" width="8.426306517909572%" headers="mcps1.1.6.1.3 "><p id="p19884115133910"><a name="p19884115133910"></a><a name="p19884115133910"></a>No</p>
    </td>
    <td class="cellrowborder" valign="top" width="11.94950088079859%" headers="mcps1.1.6.1.4 "><p id="p14884657397"><a name="p14884657397"></a><a name="p14884657397"></a>-</p>
    </td>
    <td class="cellrowborder" valign="top" width="41.074574280681155%" headers="mcps1.1.6.1.5 "><p id="p9884956396"><a name="p9884956396"></a><a name="p9884956396"></a>The first button.</p>
    <p id="p665934132012"><a name="p665934132012"></a><a name="p665934132012"></a><strong id="b19248184444912"><a name="b19248184444912"></a><a name="b19248184444912"></a>value</strong>: text of the primary button in the popup.</p>
    <p id="p16918824112213"><a name="p16918824112213"></a><a name="p16918824112213"></a><strong id="b12411740145417"><a name="b12411740145417"></a><a name="b12411740145417"></a>action</strong>: callback function for tapping the primary button.</p>
    </td>
    </tr>
    <tr id="row129365741412"><td class="cellrowborder" valign="top" width="17.723624975533372%" headers="mcps1.1.6.1.1 "><p id="p1693115718143"><a name="p1693115718143"></a><a name="p1693115718143"></a>secondaryButton</p>
    </td>
    <td class="cellrowborder" valign="top" width="20.82599334507731%" headers="mcps1.1.6.1.2 "><p id="p136435010156"><a name="p136435010156"></a><a name="p136435010156"></a>{</p>
    <p id="p1676605014159"><a name="p1676605014159"></a><a name="p1676605014159"></a>value: string,</p>
    <p id="p19529021620"><a name="p19529021620"></a><a name="p19529021620"></a>action: () =&gt; void</p>
    <p id="p593145716140"><a name="p593145716140"></a><a name="p593145716140"></a>}</p>
    </td>
    <td class="cellrowborder" valign="top" width="8.426306517909572%" headers="mcps1.1.6.1.3 "><p id="p993115771417"><a name="p993115771417"></a><a name="p993115771417"></a>No</p>
    </td>
    <td class="cellrowborder" valign="top" width="11.94950088079859%" headers="mcps1.1.6.1.4 "><p id="p7931572141"><a name="p7931572141"></a><a name="p7931572141"></a>-</p>
    </td>
    <td class="cellrowborder" valign="top" width="41.074574280681155%" headers="mcps1.1.6.1.5 "><p id="p694115711144"><a name="p694115711144"></a><a name="p694115711144"></a>Second button.</p>
    <p id="p1974117152312"><a name="p1974117152312"></a><a name="p1974117152312"></a><strong id="b137532369568"><a name="b137532369568"></a><a name="b137532369568"></a>value</strong>: text of the secondary button in the popup.</p>
    <p id="p1074127102315"><a name="p1074127102315"></a><a name="p1074127102315"></a><strong id="b08791247165611"><a name="b08791247165611"></a><a name="b08791247165611"></a>action</strong>: callback function for tapping the secondary button.</p>
    </td>
    </tr>
    <tr id="row688418573919"><td class="cellrowborder" valign="top" width="17.723624975533372%" headers="mcps1.1.6.1.1 "><p id="p5884351394"><a name="p5884351394"></a><a name="p5884351394"></a>onStateChange</p>
    </td>
    <td class="cellrowborder" valign="top" width="20.82599334507731%" headers="mcps1.1.6.1.2 "><p id="p591851741120"><a name="p591851741120"></a><a name="p591851741120"></a>(isVisible: boolean) =&gt; void</p>
    </td>
    <td class="cellrowborder" valign="top" width="8.426306517909572%" headers="mcps1.1.6.1.3 "><p id="p186161912101511"><a name="p186161912101511"></a><a name="p186161912101511"></a>No</p>
    </td>
    <td class="cellrowborder" valign="top" width="11.94950088079859%" headers="mcps1.1.6.1.4 "><p id="p07051116181519"><a name="p07051116181519"></a><a name="p07051116181519"></a>-</p>
    </td>
    <td class="cellrowborder" valign="top" width="41.074574280681155%" headers="mcps1.1.6.1.5 "><p id="p6415111811517"><a name="p6415111811517"></a><a name="p6415111811517"></a>Callback for the popup status change event. The parameter <strong id="b2061192210116"><a name="b2061192210116"></a><a name="b2061192210116"></a>isVisible</strong> indicates the visibility of the popup.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   CustomPopupOption APIs<sup>8+</sup>

    <a name="table8167205313"></a>
    <table><thead align="left"><tr id="row101672001439"><th class="cellrowborder" valign="top" width="14.542963397925234%" id="mcps1.1.6.1.1"><p id="p14167501332"><a name="p14167501332"></a><a name="p14167501332"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="19.69074182814641%" id="mcps1.1.6.1.2"><p id="p21671208319"><a name="p21671208319"></a><a name="p21671208319"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="6.605989430416913%" id="mcps1.1.6.1.3"><p id="p1116810533"><a name="p1116810533"></a><a name="p1116810533"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="10.080250538265807%" id="mcps1.1.6.1.4"><p id="p7168304311"><a name="p7168304311"></a><a name="p7168304311"></a>Default Value</p>
    </th>
    <th class="cellrowborder" valign="top" width="49.08005480524565%" id="mcps1.1.6.1.5"><p id="p41681101310"><a name="p41681101310"></a><a name="p41681101310"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row616810020312"><td class="cellrowborder" valign="top" width="14.542963397925234%" headers="mcps1.1.6.1.1 "><p id="p10168170437"><a name="p10168170437"></a><a name="p10168170437"></a>builder</p>
    </td>
    <td class="cellrowborder" valign="top" width="19.69074182814641%" headers="mcps1.1.6.1.2 "><p id="p916817019315"><a name="p916817019315"></a><a name="p916817019315"></a>() =&gt; any</p>
    </td>
    <td class="cellrowborder" valign="top" width="6.605989430416913%" headers="mcps1.1.6.1.3 "><p id="p816815015312"><a name="p816815015312"></a><a name="p816815015312"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="10.080250538265807%" headers="mcps1.1.6.1.4 "><p id="p171689012316"><a name="p171689012316"></a><a name="p171689012316"></a>-</p>
    </td>
    <td class="cellrowborder" valign="top" width="49.08005480524565%" headers="mcps1.1.6.1.5 "><p id="p121681005319"><a name="p121681005319"></a><a name="p121681005319"></a>Builder of the tooltip content.</p>
    </td>
    </tr>
    <tr id="row1416810938"><td class="cellrowborder" valign="top" width="14.542963397925234%" headers="mcps1.1.6.1.1 "><p id="p1616880734"><a name="p1616880734"></a><a name="p1616880734"></a>placement</p>
    </td>
    <td class="cellrowborder" valign="top" width="19.69074182814641%" headers="mcps1.1.6.1.2 "><p id="p18168704316"><a name="p18168704316"></a><a name="p18168704316"></a><a href="#li1521155325910">Placement</a></p>
    </td>
    <td class="cellrowborder" valign="top" width="6.605989430416913%" headers="mcps1.1.6.1.3 "><p id="p8168505319"><a name="p8168505319"></a><a name="p8168505319"></a>No</p>
    </td>
    <td class="cellrowborder" valign="top" width="10.080250538265807%" headers="mcps1.1.6.1.4 "><p id="p16168140035"><a name="p16168140035"></a><a name="p16168140035"></a>Placement.Bottom</p>
    </td>
    <td class="cellrowborder" valign="top" width="49.08005480524565%" headers="mcps1.1.6.1.5 "><p id="p1116890238"><a name="p1116890238"></a><a name="p1116890238"></a>Preferred position of the tooltip component. If the set position is insufficient for holding the component, it will be automatically adjusted.</p>
    </td>
    </tr>
    <tr id="row1016870938"><td class="cellrowborder" valign="top" width="14.542963397925234%" headers="mcps1.1.6.1.1 "><p id="p181681101431"><a name="p181681101431"></a><a name="p181681101431"></a>maskColor</p>
    </td>
    <td class="cellrowborder" valign="top" width="19.69074182814641%" headers="mcps1.1.6.1.2 "><p id="p816812013313"><a name="p816812013313"></a><a name="p816812013313"></a><a href="../../toctopics/en-us_topic_0000001237475069.md#section1326744510818">Color</a></p>
    </td>
    <td class="cellrowborder" valign="top" width="6.605989430416913%" headers="mcps1.1.6.1.3 "><p id="p016813016317"><a name="p016813016317"></a><a name="p016813016317"></a>No</p>
    </td>
    <td class="cellrowborder" valign="top" width="10.080250538265807%" headers="mcps1.1.6.1.4 "><p id="p1016813019310"><a name="p1016813019310"></a><a name="p1016813019310"></a>-</p>
    </td>
    <td class="cellrowborder" valign="top" width="49.08005480524565%" headers="mcps1.1.6.1.5 "><p id="p116819013310"><a name="p116819013310"></a><a name="p116819013310"></a>Color of the tooltip mask.</p>
    </td>
    </tr>
    <tr id="row01681402313"><td class="cellrowborder" valign="top" width="14.542963397925234%" headers="mcps1.1.6.1.1 "><p id="p161686019320"><a name="p161686019320"></a><a name="p161686019320"></a>popupColor</p>
    </td>
    <td class="cellrowborder" valign="top" width="19.69074182814641%" headers="mcps1.1.6.1.2 "><p id="p4168901034"><a name="p4168901034"></a><a name="p4168901034"></a><a href="../../toctopics/en-us_topic_0000001237475069.md#section1326744510818">Color</a></p>
    </td>
    <td class="cellrowborder" valign="top" width="6.605989430416913%" headers="mcps1.1.6.1.3 "><p id="p15168407317"><a name="p15168407317"></a><a name="p15168407317"></a>No</p>
    </td>
    <td class="cellrowborder" valign="top" width="10.080250538265807%" headers="mcps1.1.6.1.4 "><p id="p51681903311"><a name="p51681903311"></a><a name="p51681903311"></a>-</p>
    </td>
    <td class="cellrowborder" valign="top" width="49.08005480524565%" headers="mcps1.1.6.1.5 "><p id="p121681101637"><a name="p121681101637"></a><a name="p121681101637"></a>Color of the tooltip.</p>
    </td>
    </tr>
    <tr id="row6169401638"><td class="cellrowborder" valign="top" width="14.542963397925234%" headers="mcps1.1.6.1.1 "><p id="p11169807314"><a name="p11169807314"></a><a name="p11169807314"></a>enableArrow</p>
    </td>
    <td class="cellrowborder" valign="top" width="19.69074182814641%" headers="mcps1.1.6.1.2 "><p id="p171691801538"><a name="p171691801538"></a><a name="p171691801538"></a>boolean</p>
    </td>
    <td class="cellrowborder" valign="top" width="6.605989430416913%" headers="mcps1.1.6.1.3 "><p id="p111691201139"><a name="p111691201139"></a><a name="p111691201139"></a>No</p>
    </td>
    <td class="cellrowborder" valign="top" width="10.080250538265807%" headers="mcps1.1.6.1.4 "><p id="p716910630"><a name="p716910630"></a><a name="p716910630"></a>true</p>
    </td>
    <td class="cellrowborder" valign="top" width="49.08005480524565%" headers="mcps1.1.6.1.5 "><p id="p31691901231"><a name="p31691901231"></a><a name="p31691901231"></a>Whether to display arrows. Arrows are displayed only for tooltips in the up and down directions.</p>
    </td>
    </tr>
    <tr id="row81691806316"><td class="cellrowborder" valign="top" width="14.542963397925234%" headers="mcps1.1.6.1.1 "><p id="p3169705315"><a name="p3169705315"></a><a name="p3169705315"></a>autoCancel</p>
    </td>
    <td class="cellrowborder" valign="top" width="19.69074182814641%" headers="mcps1.1.6.1.2 "><p id="p916910012312"><a name="p916910012312"></a><a name="p916910012312"></a>boolean</p>
    </td>
    <td class="cellrowborder" valign="top" width="6.605989430416913%" headers="mcps1.1.6.1.3 "><p id="p101691601431"><a name="p101691601431"></a><a name="p101691601431"></a>No</p>
    </td>
    <td class="cellrowborder" valign="top" width="10.080250538265807%" headers="mcps1.1.6.1.4 "><p id="p101691105319"><a name="p101691105319"></a><a name="p101691105319"></a>true</p>
    </td>
    <td class="cellrowborder" valign="top" width="49.08005480524565%" headers="mcps1.1.6.1.5 "><p id="p18169602318"><a name="p18169602318"></a><a name="p18169602318"></a>Whether to automatically close the tooltip when an operation is performed on the page.</p>
    </td>
    </tr>
    <tr id="row15169110939"><td class="cellrowborder" valign="top" width="14.542963397925234%" headers="mcps1.1.6.1.1 "><p id="p51693019313"><a name="p51693019313"></a><a name="p51693019313"></a>onStateChange</p>
    </td>
    <td class="cellrowborder" valign="top" width="19.69074182814641%" headers="mcps1.1.6.1.2 "><p id="p13169001734"><a name="p13169001734"></a><a name="p13169001734"></a>(isVisible: boolean) =&gt; void</p>
    </td>
    <td class="cellrowborder" valign="top" width="6.605989430416913%" headers="mcps1.1.6.1.3 "><p id="p111698017316"><a name="p111698017316"></a><a name="p111698017316"></a>No</p>
    </td>
    <td class="cellrowborder" valign="top" width="10.080250538265807%" headers="mcps1.1.6.1.4 "><p id="p1716919015310"><a name="p1716919015310"></a><a name="p1716919015310"></a>-</p>
    </td>
    <td class="cellrowborder" valign="top" width="49.08005480524565%" headers="mcps1.1.6.1.5 "><p id="p31691007316"><a name="p31691007316"></a><a name="p31691007316"></a>Callback for the popup status change event. The parameter <strong id="b2148454966"><a name="b2148454966"></a><a name="b2148454966"></a>isVisible</strong> indicates the visibility of the popup.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Placement enums<sup>8+</sup>

    <a name="table3452114216394"></a>
    <table><thead align="left"><tr id="row245219426397"><th class="cellrowborder" valign="top" width="25.180000000000003%" id="mcps1.1.3.1.1"><p id="p545244283914"><a name="p545244283914"></a><a name="p545244283914"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="74.82%" id="mcps1.1.3.1.2"><p id="p2452114203917"><a name="p2452114203917"></a><a name="p2452114203917"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row6452144218390"><td class="cellrowborder" valign="top" width="25.180000000000003%" headers="mcps1.1.3.1.1 "><p id="p34529427398"><a name="p34529427398"></a><a name="p34529427398"></a>Left</p>
    </td>
    <td class="cellrowborder" valign="top" width="74.82%" headers="mcps1.1.3.1.2 "><p id="p1245211421393"><a name="p1245211421393"></a><a name="p1245211421393"></a>The tooltip is on the left of the component.</p>
    </td>
    </tr>
    <tr id="row12452184217398"><td class="cellrowborder" valign="top" width="25.180000000000003%" headers="mcps1.1.3.1.1 "><p id="p54523425398"><a name="p54523425398"></a><a name="p54523425398"></a>Right</p>
    </td>
    <td class="cellrowborder" valign="top" width="74.82%" headers="mcps1.1.3.1.2 "><p id="p745215426391"><a name="p745215426391"></a><a name="p745215426391"></a>The tooltip is on the right of the component.</p>
    </td>
    </tr>
    <tr id="row9452134213392"><td class="cellrowborder" valign="top" width="25.180000000000003%" headers="mcps1.1.3.1.1 "><p id="p510719111403"><a name="p510719111403"></a><a name="p510719111403"></a>Top</p>
    </td>
    <td class="cellrowborder" valign="top" width="74.82%" headers="mcps1.1.3.1.2 "><p id="p154533425394"><a name="p154533425394"></a><a name="p154533425394"></a>The tooltip is on the top of the component.</p>
    </td>
    </tr>
    <tr id="row0211134613505"><td class="cellrowborder" valign="top" width="25.180000000000003%" headers="mcps1.1.3.1.1 "><p id="p1653174535020"><a name="p1653174535020"></a><a name="p1653174535020"></a>Bottom</p>
    </td>
    <td class="cellrowborder" valign="top" width="74.82%" headers="mcps1.1.3.1.2 "><p id="p2533455508"><a name="p2533455508"></a><a name="p2533455508"></a>The tooltip is at the bottom of the component.</p>
    </td>
    </tr>
    <tr id="row152111246105011"><td class="cellrowborder" valign="top" width="25.180000000000003%" headers="mcps1.1.3.1.1 "><p id="p153245165017"><a name="p153245165017"></a><a name="p153245165017"></a>TopLeft</p>
    </td>
    <td class="cellrowborder" valign="top" width="74.82%" headers="mcps1.1.3.1.2 "><p id="p254194555014"><a name="p254194555014"></a><a name="p254194555014"></a>The tooltip is in the upper left corner of the component.</p>
    </td>
    </tr>
    <tr id="row7829204845016"><td class="cellrowborder" valign="top" width="25.180000000000003%" headers="mcps1.1.3.1.1 "><p id="p10717194765010"><a name="p10717194765010"></a><a name="p10717194765010"></a>TopRight</p>
    </td>
    <td class="cellrowborder" valign="top" width="74.82%" headers="mcps1.1.3.1.2 "><p id="p1718164712507"><a name="p1718164712507"></a><a name="p1718164712507"></a>The tooltip is in the upper right corner of the component.</p>
    </td>
    </tr>
    <tr id="row15829144815507"><td class="cellrowborder" valign="top" width="25.180000000000003%" headers="mcps1.1.3.1.1 "><p id="p37183472503"><a name="p37183472503"></a><a name="p37183472503"></a>BottomLeft</p>
    </td>
    <td class="cellrowborder" valign="top" width="74.82%" headers="mcps1.1.3.1.2 "><p id="p107183476502"><a name="p107183476502"></a><a name="p107183476502"></a>The tooltip is in the lower left corner of the component.</p>
    </td>
    </tr>
    <tr id="row13378931517"><td class="cellrowborder" valign="top" width="25.180000000000003%" headers="mcps1.1.3.1.1 "><p id="p12424215115"><a name="p12424215115"></a><a name="p12424215115"></a>BottomRight</p>
    </td>
    <td class="cellrowborder" valign="top" width="74.82%" headers="mcps1.1.3.1.2 "><p id="p824211275120"><a name="p824211275120"></a><a name="p824211275120"></a>The tooltip is in the lower right corner of the component.</p>
    </td>
    </tr>
    </tbody>
    </table>


## Example<a name="section0760145054817"></a>

```
@Entry
@Component
struct PopupExample {
  @State noHandlePopup: boolean = false
  @State handlePopup: boolean = false
  @State customPopup: boolean = false

  @Builder popupBuilder() {
    Row({ space: 2 }) {
      Image('/resource/ic_public_thumbsup.svg').width(24).height(24).margin({ left: -5 })
      Text('Custom Popup').fontSize(12)
    }.width(100).height(50).backgroundColor(Color.White)
  }

  build() {
    Flex({ direction: FlexDirection.Column }) {
      Button('no handle popup')
        .onClick(() => {
          this.noHandlePopup = !this.noHandlePopup
        })
        .bindPopup(this.noHandlePopup, {
          message: 'content1 content1',
          placementOnTop: false,
          onStateChange: (e) => {
            console.info(e.isVisible.toString())
            if (!e.isVisible) {
              this.noHandlePopup = false
            }
          }
        })
        .position({ x: 100, y: 50 })

      Button('with handle popup')
        .onClick(() => {
          this.handlePopup = !this.handlePopup
        })
        .bindPopup(this.handlePopup, {
          message: 'content2 content2',
          placementOnTop: true,
          primaryButton: {
            value: 'ok',
            action: () => {
              this.handlePopup = !this.handlePopup
              console.info('secondaryButton click')
            }
          },
          onStateChange: (e) => {
            console.info(e.isVisible.toString())
          }
        })
        .position({ x: 100, y: 200 })

      Button('custom popup')
        .onClick(() => {
          this.customPopup = !this.customPopup
        })
        .bindPopup(this.customPopup, {
          builder: this.popupBuilder,
          placement: Placement.Bottom,
          maskColor: 0x33000000,
          popupColor: Color.White,
          enableArrow: true,
          onStateChange: (e) => {
            if (!e.isVisible) {
              this.customPopup = false
            }
          }
        })
        .position({ x: 100, y: 350 })
    }.width('100%').padding({ top: 5 })
  }
}
```

![](figures/popup.gif)

