# Universal Events<a name="EN-US_TOPIC_0000001173324611"></a>

## Event Description<a name="section05041657172410"></a>

-   Events are bound to components. When a component meets the event triggering condition, the corresponding event callback in the JS is executed to implement the interaction between the UI and the JS logic layer of the page.
-   The event callback can carry additional information through parameters, such as the dataset on the component and event-specific callback parameters.

Different from private events, universal events can be bound to most components.

<a name="tf7a840896dc848b5ab17a18b50036601"></a>
<table><thead align="left"><tr id="rf3d0da15d2f64cd492dfa1e7d98890a5"><th class="cellrowborder" valign="top" width="14.96149614961496%" id="mcps1.1.5.1.1"><p id="a487aa1c493e84ca68567b4b65051674d"><a name="a487aa1c493e84ca68567b4b65051674d"></a><a name="a487aa1c493e84ca68567b4b65051674d"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="20.242024202420243%" id="mcps1.1.5.1.2"><p id="adc4b506cda3043508da6ee7649c12ca4"><a name="adc4b506cda3043508da6ee7649c12ca4"></a><a name="adc4b506cda3043508da6ee7649c12ca4"></a>Parameter</p>
</th>
<th class="cellrowborder" valign="top" width="45.34453445344535%" id="mcps1.1.5.1.3"><p id="a59e4cbe58a5c42a7a4585bc8365783bc"><a name="a59e4cbe58a5c42a7a4585bc8365783bc"></a><a name="a59e4cbe58a5c42a7a4585bc8365783bc"></a>Description</p>
</th>
<th class="cellrowborder" valign="top" width="19.451945194519453%" id="mcps1.1.5.1.4"><p id="p5947175616300"><a name="p5947175616300"></a><a name="p5947175616300"></a>Support Bubbling</p>
</th>
</tr>
</thead>
<tbody><tr id="r7683acd1d0964f31840d03c9aeb32fca"><td class="cellrowborder" valign="top" width="14.96149614961496%" headers="mcps1.1.5.1.1 "><p id="a58fb4b1d870f466e955cf5ea879c4d4a"><a name="a58fb4b1d870f466e955cf5ea879c4d4a"></a><a name="a58fb4b1d870f466e955cf5ea879c4d4a"></a>touchstart</p>
</td>
<td class="cellrowborder" valign="top" width="20.242024202420243%" headers="mcps1.1.5.1.2 "><p id="abefebd99301b4bdebb798d1b9df24d8d"><a name="abefebd99301b4bdebb798d1b9df24d8d"></a><a name="abefebd99301b4bdebb798d1b9df24d8d"></a><a href="#tdb541af4e4db41d7a92e9b6e3c93f606">TouchEvent</a></p>
</td>
<td class="cellrowborder" valign="top" width="45.34453445344535%" headers="mcps1.1.5.1.3 "><p id="afa4290e2620f4f5fbdcb74dcae84e536"><a name="afa4290e2620f4f5fbdcb74dcae84e536"></a><a name="afa4290e2620f4f5fbdcb74dcae84e536"></a>Triggered when the tapping starts.</p>
</td>
<td class="cellrowborder" valign="top" width="19.451945194519453%" headers="mcps1.1.5.1.4 "><p id="p494775663017"><a name="p494775663017"></a><a name="p494775663017"></a>Yes<sup id="sup1424819863620"><a name="sup1424819863620"></a><a name="sup1424819863620"></a>5+</sup></p>
</td>
</tr>
<tr id="r7f70ef6c895e4d2d95325887fee7d62e"><td class="cellrowborder" valign="top" width="14.96149614961496%" headers="mcps1.1.5.1.1 "><p id="a23e0317cfee94650be4dcd2280c3e94e"><a name="a23e0317cfee94650be4dcd2280c3e94e"></a><a name="a23e0317cfee94650be4dcd2280c3e94e"></a>touchmove</p>
</td>
<td class="cellrowborder" valign="top" width="20.242024202420243%" headers="mcps1.1.5.1.2 "><p id="aea26e4f9575044dc8fb65080f3a6684a"><a name="aea26e4f9575044dc8fb65080f3a6684a"></a><a name="aea26e4f9575044dc8fb65080f3a6684a"></a><a href="#tdb541af4e4db41d7a92e9b6e3c93f606">TouchEvent</a></p>
</td>
<td class="cellrowborder" valign="top" width="45.34453445344535%" headers="mcps1.1.5.1.3 "><p id="a37f7cc43d82c4ee18512bd079349079d"><a name="a37f7cc43d82c4ee18512bd079349079d"></a><a name="a37f7cc43d82c4ee18512bd079349079d"></a>Triggered when the tapping moves.</p>
</td>
<td class="cellrowborder" valign="top" width="19.451945194519453%" headers="mcps1.1.5.1.4 "><p id="p1694775683010"><a name="p1694775683010"></a><a name="p1694775683010"></a>Yes<sup id="sup886511437386"><a name="sup886511437386"></a><a name="sup886511437386"></a>5+</sup></p>
</td>
</tr>
<tr id="ra5c278d41f9045ed9d95e13165974bf4"><td class="cellrowborder" valign="top" width="14.96149614961496%" headers="mcps1.1.5.1.1 "><p id="ad0728eeac06143bbb4a6fdf1ed5c6d91"><a name="ad0728eeac06143bbb4a6fdf1ed5c6d91"></a><a name="ad0728eeac06143bbb4a6fdf1ed5c6d91"></a>touchcancel</p>
</td>
<td class="cellrowborder" valign="top" width="20.242024202420243%" headers="mcps1.1.5.1.2 "><p id="a59e2819eae2b4d3e935991b43156347b"><a name="a59e2819eae2b4d3e935991b43156347b"></a><a name="a59e2819eae2b4d3e935991b43156347b"></a><a href="#tdb541af4e4db41d7a92e9b6e3c93f606">TouchEvent</a></p>
</td>
<td class="cellrowborder" valign="top" width="45.34453445344535%" headers="mcps1.1.5.1.3 "><p id="a739d9ef0db624f6284554aeaeddffa0a"><a name="a739d9ef0db624f6284554aeaeddffa0a"></a><a name="a739d9ef0db624f6284554aeaeddffa0a"></a>Triggered when the tapping is interrupted.</p>
</td>
<td class="cellrowborder" valign="top" width="19.451945194519453%" headers="mcps1.1.5.1.4 "><p id="p19474565303"><a name="p19474565303"></a><a name="p19474565303"></a>Yes<sup id="sup11909124833817"><a name="sup11909124833817"></a><a name="sup11909124833817"></a>5+</sup></p>
</td>
</tr>
<tr id="rddfe06969173404d96b60c402a7e783c"><td class="cellrowborder" valign="top" width="14.96149614961496%" headers="mcps1.1.5.1.1 "><p id="a233e2f6ff39f49fd97b8f233875d01d4"><a name="a233e2f6ff39f49fd97b8f233875d01d4"></a><a name="a233e2f6ff39f49fd97b8f233875d01d4"></a>touchend</p>
</td>
<td class="cellrowborder" valign="top" width="20.242024202420243%" headers="mcps1.1.5.1.2 "><p id="a439e69aaf158448e99b3c81cbc9fd624"><a name="a439e69aaf158448e99b3c81cbc9fd624"></a><a name="a439e69aaf158448e99b3c81cbc9fd624"></a><a href="#tdb541af4e4db41d7a92e9b6e3c93f606">TouchEvent</a></p>
</td>
<td class="cellrowborder" valign="top" width="45.34453445344535%" headers="mcps1.1.5.1.3 "><p id="a05c0fe4e05ef4154acee8a06ad56a2de"><a name="a05c0fe4e05ef4154acee8a06ad56a2de"></a><a name="a05c0fe4e05ef4154acee8a06ad56a2de"></a>Triggered when the tapping ends.</p>
</td>
<td class="cellrowborder" valign="top" width="19.451945194519453%" headers="mcps1.1.5.1.4 "><p id="p11947456133011"><a name="p11947456133011"></a><a name="p11947456133011"></a>Yes<sup id="sup784019463385"><a name="sup784019463385"></a><a name="sup784019463385"></a>5+</sup></p>
</td>
</tr>
<tr id="rec1121b8bebc4a3f9ed9a906d061746e"><td class="cellrowborder" valign="top" width="14.96149614961496%" headers="mcps1.1.5.1.1 "><p id="a2fb4de45b1594f6fa1a7da45ce0db57f"><a name="a2fb4de45b1594f6fa1a7da45ce0db57f"></a><a name="a2fb4de45b1594f6fa1a7da45ce0db57f"></a>click</p>
</td>
<td class="cellrowborder" valign="top" width="20.242024202420243%" headers="mcps1.1.5.1.2 "><p id="af86bf1da40504ed2a8d14213a42536ab"><a name="af86bf1da40504ed2a8d14213a42536ab"></a><a name="af86bf1da40504ed2a8d14213a42536ab"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="45.34453445344535%" headers="mcps1.1.5.1.3 "><p id="a1d32f00c38c440ddaa63c3f3e01d4e09"><a name="a1d32f00c38c440ddaa63c3f3e01d4e09"></a><a name="a1d32f00c38c440ddaa63c3f3e01d4e09"></a>Triggered when a component is clicked.</p>
</td>
<td class="cellrowborder" valign="top" width="19.451945194519453%" headers="mcps1.1.5.1.4 "><p id="p825613220390"><a name="p825613220390"></a><a name="p825613220390"></a>Yes<sup id="sup84271359397"><a name="sup84271359397"></a><a name="sup84271359397"></a>6+</sup></p>
</td>
</tr>
<tr id="row2705152317020"><td class="cellrowborder" valign="top" width="14.96149614961496%" headers="mcps1.1.5.1.1 "><p id="p1670622317013"><a name="p1670622317013"></a><a name="p1670622317013"></a>doubleclick<sup id="sup898272511424"><a name="sup898272511424"></a><a name="sup898272511424"></a>7+</sup></p>
</td>
<td class="cellrowborder" valign="top" width="20.242024202420243%" headers="mcps1.1.5.1.2 ">&nbsp;&nbsp;</td>
<td class="cellrowborder" valign="top" width="45.34453445344535%" headers="mcps1.1.5.1.3 "><p id="p10706723605"><a name="p10706723605"></a><a name="p10706723605"></a>Triggered when a component is double-clicked.</p>
</td>
<td class="cellrowborder" valign="top" width="19.451945194519453%" headers="mcps1.1.5.1.4 "><p id="p1170617231703"><a name="p1170617231703"></a><a name="p1170617231703"></a>No</p>
</td>
</tr>
<tr id="r95f500ef9402487ea42e829d69606f90"><td class="cellrowborder" valign="top" width="14.96149614961496%" headers="mcps1.1.5.1.1 "><p id="aa7dc63d1b4924872bbff6a6a100e928f"><a name="aa7dc63d1b4924872bbff6a6a100e928f"></a><a name="aa7dc63d1b4924872bbff6a6a100e928f"></a>longpress</p>
</td>
<td class="cellrowborder" valign="top" width="20.242024202420243%" headers="mcps1.1.5.1.2 "><p id="a39186f4ff74544d89ace56ea87d9937b"><a name="a39186f4ff74544d89ace56ea87d9937b"></a><a name="a39186f4ff74544d89ace56ea87d9937b"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="45.34453445344535%" headers="mcps1.1.5.1.3 "><p id="a44b8585170304b5596c41714772e605e"><a name="a44b8585170304b5596c41714772e605e"></a><a name="a44b8585170304b5596c41714772e605e"></a>Triggered when a component is long pressed.</p>
</td>
<td class="cellrowborder" valign="top" width="19.451945194519453%" headers="mcps1.1.5.1.4 "><p id="p19655530173713"><a name="p19655530173713"></a><a name="p19655530173713"></a>No</p>
</td>
</tr>
<tr id="row117014569616"><td class="cellrowborder" valign="top" width="14.96149614961496%" headers="mcps1.1.5.1.1 "><p id="p12706561061"><a name="p12706561061"></a><a name="p12706561061"></a>swipe<sup id="sup35424382912"><a name="sup35424382912"></a><a name="sup35424382912"></a>5+</sup></p>
</td>
<td class="cellrowborder" valign="top" width="20.242024202420243%" headers="mcps1.1.5.1.2 "><p id="p11711056161"><a name="p11711056161"></a><a name="p11711056161"></a><a href="#table111811577714">SwipeEvent</a></p>
</td>
<td class="cellrowborder" valign="top" width="45.34453445344535%" headers="mcps1.1.5.1.3 "><p id="p2711556162"><a name="p2711556162"></a><a name="p2711556162"></a>Triggered when a user quickly swipes on a component.</p>
</td>
<td class="cellrowborder" valign="top" width="19.451945194519453%" headers="mcps1.1.5.1.4 "><p id="p172818312393"><a name="p172818312393"></a><a name="p172818312393"></a>No</p>
</td>
</tr>
<tr id="row4761236154510"><td class="cellrowborder" valign="top" width="14.96149614961496%" headers="mcps1.1.5.1.1 "><p id="p1976143617459"><a name="p1976143617459"></a><a name="p1976143617459"></a>attached<sup id="sup1479243510549"><a name="sup1479243510549"></a><a name="sup1479243510549"></a>6+</sup></p>
</td>
<td class="cellrowborder" valign="top" width="20.242024202420243%" headers="mcps1.1.5.1.2 "><p id="p876293613452"><a name="p876293613452"></a><a name="p876293613452"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="45.34453445344535%" headers="mcps1.1.5.1.3 "><p id="p676263610459"><a name="p676263610459"></a><a name="p676263610459"></a>Triggered after the current component node is mounted to the render tree.</p>
</td>
<td class="cellrowborder" valign="top" width="19.451945194519453%" headers="mcps1.1.5.1.4 "><p id="p79471756173019"><a name="p79471756173019"></a><a name="p79471756173019"></a>No</p>
</td>
</tr>
<tr id="row37951541194613"><td class="cellrowborder" valign="top" width="14.96149614961496%" headers="mcps1.1.5.1.1 "><p id="p12796641204612"><a name="p12796641204612"></a><a name="p12796641204612"></a>detached<sup id="sup18566163910540"><a name="sup18566163910540"></a><a name="sup18566163910540"></a>6+</sup></p>
</td>
<td class="cellrowborder" valign="top" width="20.242024202420243%" headers="mcps1.1.5.1.2 "><p id="p177961241154618"><a name="p177961241154618"></a><a name="p177961241154618"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="45.34453445344535%" headers="mcps1.1.5.1.3 "><p id="p9796124114612"><a name="p9796124114612"></a><a name="p9796124114612"></a>Triggered when the current component node is removed from the render tree.</p>
</td>
<td class="cellrowborder" valign="top" width="19.451945194519453%" headers="mcps1.1.5.1.4 "><p id="p2947105614304"><a name="p2947105614304"></a><a name="p2947105614304"></a>No</p>
</td>
</tr>
<tr id="row127781725724"><td class="cellrowborder" valign="top" width="14.96149614961496%" headers="mcps1.1.5.1.1 "><p id="p15778202514212"><a name="p15778202514212"></a><a name="p15778202514212"></a>pinchstart<sup id="sup81411323204310"><a name="sup81411323204310"></a><a name="sup81411323204310"></a>7+</sup></p>
</td>
<td class="cellrowborder" valign="top" width="20.242024202420243%" headers="mcps1.1.5.1.2 "><p id="p577810251824"><a name="p577810251824"></a><a name="p577810251824"></a><a href="#table1828625919617">PinchEvent</a></p>
</td>
<td class="cellrowborder" valign="top" width="45.34453445344535%" headers="mcps1.1.5.1.3 "><p id="p877817251226"><a name="p877817251226"></a><a name="p877817251226"></a>Triggered when a pinch operation is started.</p>
</td>
<td class="cellrowborder" valign="top" width="19.451945194519453%" headers="mcps1.1.5.1.4 "><p id="p57789251323"><a name="p57789251323"></a><a name="p57789251323"></a>No</p>
</td>
</tr>
<tr id="row192314391432"><td class="cellrowborder" valign="top" width="14.96149614961496%" headers="mcps1.1.5.1.1 "><p id="p69238391334"><a name="p69238391334"></a><a name="p69238391334"></a>pinchupdate<sup id="sup8215182424319"><a name="sup8215182424319"></a><a name="sup8215182424319"></a>7+</sup></p>
</td>
<td class="cellrowborder" valign="top" width="20.242024202420243%" headers="mcps1.1.5.1.2 "><p id="p1977416315333"><a name="p1977416315333"></a><a name="p1977416315333"></a><a href="#table1828625919617">PinchEvent</a></p>
</td>
<td class="cellrowborder" valign="top" width="45.34453445344535%" headers="mcps1.1.5.1.3 "><p id="p49236391135"><a name="p49236391135"></a><a name="p49236391135"></a>Triggered when a pinch operation is in progress.</p>
</td>
<td class="cellrowborder" valign="top" width="19.451945194519453%" headers="mcps1.1.5.1.4 "><p id="p149239398315"><a name="p149239398315"></a><a name="p149239398315"></a>No</p>
</td>
</tr>
<tr id="row487617446316"><td class="cellrowborder" valign="top" width="14.96149614961496%" headers="mcps1.1.5.1.1 "><p id="p987718441331"><a name="p987718441331"></a><a name="p987718441331"></a>pinchend<sup id="sup678725104315"><a name="sup678725104315"></a><a name="sup678725104315"></a>7+</sup></p>
</td>
<td class="cellrowborder" valign="top" width="20.242024202420243%" headers="mcps1.1.5.1.2 "><p id="p3166118193310"><a name="p3166118193310"></a><a name="p3166118193310"></a><a href="#table1828625919617">PinchEvent</a></p>
</td>
<td class="cellrowborder" valign="top" width="45.34453445344535%" headers="mcps1.1.5.1.3 "><p id="p1987715441638"><a name="p1987715441638"></a><a name="p1987715441638"></a>Triggered when a pinch operation is ended.</p>
</td>
<td class="cellrowborder" valign="top" width="19.451945194519453%" headers="mcps1.1.5.1.4 "><p id="p14877174410314"><a name="p14877174410314"></a><a name="p14877174410314"></a>No</p>
</td>
</tr>
<tr id="row1930164915319"><td class="cellrowborder" valign="top" width="14.96149614961496%" headers="mcps1.1.5.1.1 "><p id="p1893015491132"><a name="p1893015491132"></a><a name="p1893015491132"></a>pinchcancel<sup id="sup1120714269437"><a name="sup1120714269437"></a><a name="sup1120714269437"></a>7+</sup></p>
</td>
<td class="cellrowborder" valign="top" width="20.242024202420243%" headers="mcps1.1.5.1.2 "><p id="p1056161218334"><a name="p1056161218334"></a><a name="p1056161218334"></a><a href="#table1828625919617">PinchEvent</a></p>
</td>
<td class="cellrowborder" valign="top" width="45.34453445344535%" headers="mcps1.1.5.1.3 "><p id="p1993034918316"><a name="p1993034918316"></a><a name="p1993034918316"></a>Triggered when the pinch operation is interrupted.</p>
</td>
<td class="cellrowborder" valign="top" width="19.451945194519453%" headers="mcps1.1.5.1.4 "><p id="p15930114916314"><a name="p15930114916314"></a><a name="p15930114916314"></a>No</p>
</td>
</tr>
<tr id="row134184458269"><td class="cellrowborder" valign="top" width="14.96149614961496%" headers="mcps1.1.5.1.1 "><p id="p16418184552612"><a name="p16418184552612"></a><a name="p16418184552612"></a>dragstart<sup id="sup1640611844620"><a name="sup1640611844620"></a><a name="sup1640611844620"></a>7+</sup></p>
</td>
<td class="cellrowborder" valign="top" width="20.242024202420243%" headers="mcps1.1.5.1.2 "><p id="p14418124562610"><a name="p14418124562610"></a><a name="p14418124562610"></a><a href="#table95551461358">DragEvent</a></p>
</td>
<td class="cellrowborder" valign="top" width="45.34453445344535%" headers="mcps1.1.5.1.3 "><p id="p1341894592614"><a name="p1341894592614"></a><a name="p1341894592614"></a>Triggered when dragging starts.</p>
</td>
<td class="cellrowborder" valign="top" width="19.451945194519453%" headers="mcps1.1.5.1.4 "><p id="p1341811451268"><a name="p1341811451268"></a><a name="p1341811451268"></a>No</p>
</td>
</tr>
<tr id="row195941786134"><td class="cellrowborder" valign="top" width="14.96149614961496%" headers="mcps1.1.5.1.1 "><p id="p6151151019134"><a name="p6151151019134"></a><a name="p6151151019134"></a>drag<sup id="sup317711477125"><a name="sup317711477125"></a><a name="sup317711477125"></a>7+</sup></p>
</td>
<td class="cellrowborder" valign="top" width="20.242024202420243%" headers="mcps1.1.5.1.2 "><p id="p1151110191313"><a name="p1151110191313"></a><a name="p1151110191313"></a><a href="#table95551461358">DragEvent</a></p>
</td>
<td class="cellrowborder" valign="top" width="45.34453445344535%" headers="mcps1.1.5.1.3 "><p id="p915141041313"><a name="p915141041313"></a><a name="p915141041313"></a>Triggered when dragging is in progress.</p>
</td>
<td class="cellrowborder" valign="top" width="19.451945194519453%" headers="mcps1.1.5.1.4 "><p id="p1815112102131"><a name="p1815112102131"></a><a name="p1815112102131"></a>No</p>
</td>
</tr>
<tr id="row343314310509"><td class="cellrowborder" valign="top" width="14.96149614961496%" headers="mcps1.1.5.1.1 "><p id="p243393145013"><a name="p243393145013"></a><a name="p243393145013"></a>dragend<sup id="sup1016615910463"><a name="sup1016615910463"></a><a name="sup1016615910463"></a>7+</sup></p>
</td>
<td class="cellrowborder" valign="top" width="20.242024202420243%" headers="mcps1.1.5.1.2 "><p id="p94331834504"><a name="p94331834504"></a><a name="p94331834504"></a><a href="#table95551461358">DragEvent</a></p>
</td>
<td class="cellrowborder" valign="top" width="45.34453445344535%" headers="mcps1.1.5.1.3 "><p id="p143310312509"><a name="p143310312509"></a><a name="p143310312509"></a>Triggered when dragging is ended.</p>
</td>
<td class="cellrowborder" valign="top" width="19.451945194519453%" headers="mcps1.1.5.1.4 "><p id="p194331833500"><a name="p194331833500"></a><a name="p194331833500"></a>No</p>
</td>
</tr>
<tr id="row129701428135013"><td class="cellrowborder" valign="top" width="14.96149614961496%" headers="mcps1.1.5.1.1 "><p id="p3970152810505"><a name="p3970152810505"></a><a name="p3970152810505"></a>dragenter<sup id="sup685614917463"><a name="sup685614917463"></a><a name="sup685614917463"></a>7+</sup></p>
</td>
<td class="cellrowborder" valign="top" width="20.242024202420243%" headers="mcps1.1.5.1.2 "><p id="p697082875015"><a name="p697082875015"></a><a name="p697082875015"></a><a href="#table95551461358">DragEvent</a></p>
</td>
<td class="cellrowborder" valign="top" width="45.34453445344535%" headers="mcps1.1.5.1.3 "><p id="p79702028125013"><a name="p79702028125013"></a><a name="p79702028125013"></a>Triggered when the dragged component enters a drop target.</p>
</td>
<td class="cellrowborder" valign="top" width="19.451945194519453%" headers="mcps1.1.5.1.4 "><p id="p1297011285502"><a name="p1297011285502"></a><a name="p1297011285502"></a>No</p>
</td>
</tr>
<tr id="row139802344501"><td class="cellrowborder" valign="top" width="14.96149614961496%" headers="mcps1.1.5.1.1 "><p id="p1798473495020"><a name="p1798473495020"></a><a name="p1798473495020"></a>dragover<sup id="sup166541210204610"><a name="sup166541210204610"></a><a name="sup166541210204610"></a>7+</sup></p>
</td>
<td class="cellrowborder" valign="top" width="20.242024202420243%" headers="mcps1.1.5.1.2 "><p id="p1598793419509"><a name="p1598793419509"></a><a name="p1598793419509"></a><a href="#table95551461358">DragEvent</a></p>
</td>
<td class="cellrowborder" valign="top" width="45.34453445344535%" headers="mcps1.1.5.1.3 "><p id="p8987163414509"><a name="p8987163414509"></a><a name="p8987163414509"></a>Triggered when the dragged component is being dragged over a drop target.</p>
</td>
<td class="cellrowborder" valign="top" width="19.451945194519453%" headers="mcps1.1.5.1.4 "><p id="p19987103405015"><a name="p19987103405015"></a><a name="p19987103405015"></a>No</p>
</td>
</tr>
<tr id="row833215394509"><td class="cellrowborder" valign="top" width="14.96149614961496%" headers="mcps1.1.5.1.1 "><p id="p633512393503"><a name="p633512393503"></a><a name="p633512393503"></a>dragleave<sup id="sup18549201194615"><a name="sup18549201194615"></a><a name="sup18549201194615"></a>7+</sup></p>
</td>
<td class="cellrowborder" valign="top" width="20.242024202420243%" headers="mcps1.1.5.1.2 "><p id="p18335153913504"><a name="p18335153913504"></a><a name="p18335153913504"></a><a href="#table95551461358">DragEvent</a></p>
</td>
<td class="cellrowborder" valign="top" width="45.34453445344535%" headers="mcps1.1.5.1.3 "><p id="p8335173910503"><a name="p8335173910503"></a><a name="p8335173910503"></a>Triggered when the dragged component leaves a drop target.</p>
</td>
<td class="cellrowborder" valign="top" width="19.451945194519453%" headers="mcps1.1.5.1.4 "><p id="p10338193915012"><a name="p10338193915012"></a><a name="p10338193915012"></a>No</p>
</td>
</tr>
<tr id="row82701055155015"><td class="cellrowborder" valign="top" width="14.96149614961496%" headers="mcps1.1.5.1.1 "><p id="p8270205585018"><a name="p8270205585018"></a><a name="p8270205585018"></a>drop<sup id="sup3324161319467"><a name="sup3324161319467"></a><a name="sup3324161319467"></a>7+</sup></p>
</td>
<td class="cellrowborder" valign="top" width="20.242024202420243%" headers="mcps1.1.5.1.2 "><p id="p1627055514502"><a name="p1627055514502"></a><a name="p1627055514502"></a><a href="#table95551461358">DragEvent</a></p>
</td>
<td class="cellrowborder" valign="top" width="45.34453445344535%" headers="mcps1.1.5.1.3 "><p id="p162704558509"><a name="p162704558509"></a><a name="p162704558509"></a>Triggered when a component is dropped on a drop target.</p>
</td>
<td class="cellrowborder" valign="top" width="19.451945194519453%" headers="mcps1.1.5.1.4 "><p id="p127065585014"><a name="p127065585014"></a><a name="p127065585014"></a>No</p>
</td>
</tr>
</tbody>
</table>

>![](../../public_sys-resources/icon-note.gif) **NOTE:** 
>Events not listed in the preceding table are non-bubbling events, such as the  [change event](js-components-basic-input.md#section1721512551218). For details, see the specific component.

**Table  1**  Attributes of the BaseEvent object

<a name="t4afe3a7d9546429ca1113ff78333d1c5"></a>
<table><thead align="left"><tr id="r17b57a5916254b538712224afce3ec93"><th class="cellrowborder" valign="top" width="17.169999999999998%" id="mcps1.2.4.1.1"><p id="a85fa8e3227fc48a2b8bc9c953327ae36"><a name="a85fa8e3227fc48a2b8bc9c953327ae36"></a><a name="a85fa8e3227fc48a2b8bc9c953327ae36"></a>Attribute</p>
</th>
<th class="cellrowborder" valign="top" width="14.14%" id="mcps1.2.4.1.2"><p id="aae0028a39da64592bc9e3de357419d3b"><a name="aae0028a39da64592bc9e3de357419d3b"></a><a name="aae0028a39da64592bc9e3de357419d3b"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="68.69%" id="mcps1.2.4.1.3"><p id="a84e596443d8d4e80ab2d990e87e19d0a"><a name="a84e596443d8d4e80ab2d990e87e19d0a"></a><a name="a84e596443d8d4e80ab2d990e87e19d0a"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="ref9724a78ebd4f959cc159def567a6e5"><td class="cellrowborder" valign="top" width="17.169999999999998%" headers="mcps1.2.4.1.1 "><p id="a8e318c4332dd44cda62259cd5018bc7c"><a name="a8e318c4332dd44cda62259cd5018bc7c"></a><a name="a8e318c4332dd44cda62259cd5018bc7c"></a>type</p>
</td>
<td class="cellrowborder" valign="top" width="14.14%" headers="mcps1.2.4.1.2 "><p id="a567269320f1c43b3984e231f61130431"><a name="a567269320f1c43b3984e231f61130431"></a><a name="a567269320f1c43b3984e231f61130431"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="68.69%" headers="mcps1.2.4.1.3 "><p id="a732751a8a4114815953f940529086cc4"><a name="a732751a8a4114815953f940529086cc4"></a><a name="a732751a8a4114815953f940529086cc4"></a>Event type, such as <strong id="b17928122183715"><a name="b17928122183715"></a><a name="b17928122183715"></a>click</strong> and <strong id="b78784073719"><a name="b78784073719"></a><a name="b78784073719"></a>longpress</strong></p>
</td>
</tr>
<tr id="rc5890121a2e14421be07b897d2c04995"><td class="cellrowborder" valign="top" width="17.169999999999998%" headers="mcps1.2.4.1.1 "><p id="a8f15a7cee90e48ac80b09f0f3ba1bc3a"><a name="a8f15a7cee90e48ac80b09f0f3ba1bc3a"></a><a name="a8f15a7cee90e48ac80b09f0f3ba1bc3a"></a>timestamp</p>
</td>
<td class="cellrowborder" valign="top" width="14.14%" headers="mcps1.2.4.1.2 "><p id="a257a70e6a33d481e8c32f4551d33f6e4"><a name="a257a70e6a33d481e8c32f4551d33f6e4"></a><a name="a257a70e6a33d481e8c32f4551d33f6e4"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="68.69%" headers="mcps1.2.4.1.3 "><p id="a816c5efe2ab2447bbd14dfd91095052c"><a name="a816c5efe2ab2447bbd14dfd91095052c"></a><a name="a816c5efe2ab2447bbd14dfd91095052c"></a>Timestamp when the event is triggered</p>
</td>
</tr>
</tbody>
</table>

**Table  2**  Attributes of the TouchEvent object \(inherited from BaseEvent\)

<a name="tdb541af4e4db41d7a92e9b6e3c93f606"></a>
<table><thead align="left"><tr id="rea83e482278e4251975cce4fd873c6bb"><th class="cellrowborder" valign="top" width="21.07%" id="mcps1.2.4.1.1"><p id="a82b31036c9c94b3d8a7702523f9b40ec"><a name="a82b31036c9c94b3d8a7702523f9b40ec"></a><a name="a82b31036c9c94b3d8a7702523f9b40ec"></a>Attribute</p>
</th>
<th class="cellrowborder" valign="top" width="15.93%" id="mcps1.2.4.1.2"><p id="a916c9aa3c32e4903953063bb7424027c"><a name="a916c9aa3c32e4903953063bb7424027c"></a><a name="a916c9aa3c32e4903953063bb7424027c"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="63%" id="mcps1.2.4.1.3"><p id="af9aad173dc2f44f5be69c86fe5537af7"><a name="af9aad173dc2f44f5be69c86fe5537af7"></a><a name="af9aad173dc2f44f5be69c86fe5537af7"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="r2f3c99711cf243c19b359026f2863056"><td class="cellrowborder" valign="top" width="21.07%" headers="mcps1.2.4.1.1 "><p id="a660dbbfaf8d349b7921fbe9a0b96574a"><a name="a660dbbfaf8d349b7921fbe9a0b96574a"></a><a name="a660dbbfaf8d349b7921fbe9a0b96574a"></a>touches</p>
</td>
<td class="cellrowborder" valign="top" width="15.93%" headers="mcps1.2.4.1.2 "><p id="aab0506a4edc147beb25866891e5fddcd"><a name="aab0506a4edc147beb25866891e5fddcd"></a><a name="aab0506a4edc147beb25866891e5fddcd"></a>Array&lt;TouchInfo&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="63%" headers="mcps1.2.4.1.3 "><p id="aa3d09d0a55704a6097fb39739436c5db"><a name="aa3d09d0a55704a6097fb39739436c5db"></a><a name="aa3d09d0a55704a6097fb39739436c5db"></a>Attribute set of the touch event, including the information array of the touch points on the screen.</p>
</td>
</tr>
<tr id="raad83bde64d9482f8a56c44ae45b3f77"><td class="cellrowborder" valign="top" width="21.07%" headers="mcps1.2.4.1.1 "><p id="a7e263f0434c94a16a584943ddde92012"><a name="a7e263f0434c94a16a584943ddde92012"></a><a name="a7e263f0434c94a16a584943ddde92012"></a>changedTouches</p>
</td>
<td class="cellrowborder" valign="top" width="15.93%" headers="mcps1.2.4.1.2 "><p id="a76ffd0f779234ab6a77e808500fca675"><a name="a76ffd0f779234ab6a77e808500fca675"></a><a name="a76ffd0f779234ab6a77e808500fca675"></a>Array&lt;TouchInfo&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="63%" headers="mcps1.2.4.1.3 "><p id="a85eddf1d320641a8b344aaadffe6d49e"><a name="a85eddf1d320641a8b344aaadffe6d49e"></a><a name="a85eddf1d320641a8b344aaadffe6d49e"></a>Attribute set when a touch event occurs, including the information array of changed touch points on the screen. <strong id="b185721925164418"><a name="b185721925164418"></a><a name="b185721925164418"></a>changedTouches</strong> has the same data format as <strong id="b18207185144513"><a name="b18207185144513"></a><a name="b18207185144513"></a>touches</strong> and indicates touch point changes, such as from no touch point to newly generated touch points, from some touch points to no touch point, and location changes. For example, when the user's finger leaves the touchscreen, no data exists in the <strong id="b127219713482"><a name="b127219713482"></a><a name="b127219713482"></a>touches</strong> array, but <strong id="b1813110115482"><a name="b1813110115482"></a><a name="b1813110115482"></a>changedTouches</strong> will save the generated data.</p>
</td>
</tr>
</tbody>
</table>

**Table  3**  TouchInfo

<a name="tf03fc1fac826405d95028a3b880047b6"></a>
<table><thead align="left"><tr id="rff1c937243f04922b941ec313c0cc858"><th class="cellrowborder" valign="top" width="21%" id="mcps1.2.4.1.1"><p id="a7f9f203c859c4f2ab2f44035c97cffa7"><a name="a7f9f203c859c4f2ab2f44035c97cffa7"></a><a name="a7f9f203c859c4f2ab2f44035c97cffa7"></a>Attribute</p>
</th>
<th class="cellrowborder" valign="top" width="16%" id="mcps1.2.4.1.2"><p id="a00de9107caaf46968b7d3a52f0c9718f"><a name="a00de9107caaf46968b7d3a52f0c9718f"></a><a name="a00de9107caaf46968b7d3a52f0c9718f"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="63%" id="mcps1.2.4.1.3"><p id="a3406658ff5084d1aaad3fca32c5d31d6"><a name="a3406658ff5084d1aaad3fca32c5d31d6"></a><a name="a3406658ff5084d1aaad3fca32c5d31d6"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="r19de9fd9501e4d99a3a9232b7fb94c98"><td class="cellrowborder" valign="top" width="21%" headers="mcps1.2.4.1.1 "><p id="a8653f3e51af34bb78136455652a61cec"><a name="a8653f3e51af34bb78136455652a61cec"></a><a name="a8653f3e51af34bb78136455652a61cec"></a>globalX</p>
</td>
<td class="cellrowborder" valign="top" width="16%" headers="mcps1.2.4.1.2 "><p id="add8c97142b8742f78503909547ebd380"><a name="add8c97142b8742f78503909547ebd380"></a><a name="add8c97142b8742f78503909547ebd380"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="63%" headers="mcps1.2.4.1.3 "><p id="a834cd2553aa7439781eeeddd342329df"><a name="a834cd2553aa7439781eeeddd342329df"></a><a name="a834cd2553aa7439781eeeddd342329df"></a>Horizontal distance from the upper left corner of the screen (excluding the status bar). The upper left corner of the screen acts as the coordinate origin.</p>
</td>
</tr>
<tr id="rde7a56164c134cd2a1afce437e437211"><td class="cellrowborder" valign="top" width="21%" headers="mcps1.2.4.1.1 "><p id="aebdebb651e74449fb00e1b9930564eac"><a name="aebdebb651e74449fb00e1b9930564eac"></a><a name="aebdebb651e74449fb00e1b9930564eac"></a>globalY</p>
</td>
<td class="cellrowborder" valign="top" width="16%" headers="mcps1.2.4.1.2 "><p id="a3bcbd4de1a634f3195b525d00f1c9667"><a name="a3bcbd4de1a634f3195b525d00f1c9667"></a><a name="a3bcbd4de1a634f3195b525d00f1c9667"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="63%" headers="mcps1.2.4.1.3 "><p id="a5a1306479f784edf8a5a42f76e2540be"><a name="a5a1306479f784edf8a5a42f76e2540be"></a><a name="a5a1306479f784edf8a5a42f76e2540be"></a>Vertical distance from the upper left corner of the screen (excluding the status bar). The upper left corner of the screen acts as the coordinate origin.</p>
</td>
</tr>
<tr id="r94760564980c470490555043898942f3"><td class="cellrowborder" valign="top" width="21%" headers="mcps1.2.4.1.1 "><p id="a1a1011d86d0c4149a43d0175e75028c5"><a name="a1a1011d86d0c4149a43d0175e75028c5"></a><a name="a1a1011d86d0c4149a43d0175e75028c5"></a>localX</p>
</td>
<td class="cellrowborder" valign="top" width="16%" headers="mcps1.2.4.1.2 "><p id="a0618e3c91a61456a9a9ad2c23095cca5"><a name="a0618e3c91a61456a9a9ad2c23095cca5"></a><a name="a0618e3c91a61456a9a9ad2c23095cca5"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="63%" headers="mcps1.2.4.1.3 "><p id="ad7268ba243c546af8f93208c427c5340"><a name="ad7268ba243c546af8f93208c427c5340"></a><a name="ad7268ba243c546af8f93208c427c5340"></a>Horizontal distance from the upper left corner of the touched component. The upper left corner of the component acts as the coordinate origin.</p>
</td>
</tr>
<tr id="ra0ea6d13e3224d3fac80631ac8458af7"><td class="cellrowborder" valign="top" width="21%" headers="mcps1.2.4.1.1 "><p id="ab9af76cc10bf4da49cef6ff3a201ff46"><a name="ab9af76cc10bf4da49cef6ff3a201ff46"></a><a name="ab9af76cc10bf4da49cef6ff3a201ff46"></a>localY</p>
</td>
<td class="cellrowborder" valign="top" width="16%" headers="mcps1.2.4.1.2 "><p id="a7d7052c11197432aa14f39bb4039d7aa"><a name="a7d7052c11197432aa14f39bb4039d7aa"></a><a name="a7d7052c11197432aa14f39bb4039d7aa"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="63%" headers="mcps1.2.4.1.3 "><p id="ae3aa585280c449e5a8fe954711ab56fd"><a name="ae3aa585280c449e5a8fe954711ab56fd"></a><a name="ae3aa585280c449e5a8fe954711ab56fd"></a>Vertical distance from the upper left corner of the touched component. The upper left corner of the component acts as the coordinate origin.</p>
</td>
</tr>
<tr id="row199451713154119"><td class="cellrowborder" valign="top" width="21%" headers="mcps1.2.4.1.1 "><p id="p3369201515412"><a name="p3369201515412"></a><a name="p3369201515412"></a>size</p>
</td>
<td class="cellrowborder" valign="top" width="16%" headers="mcps1.2.4.1.2 "><p id="p14369121514116"><a name="p14369121514116"></a><a name="p14369121514116"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="63%" headers="mcps1.2.4.1.3 "><p id="p336941534115"><a name="p336941534115"></a><a name="p336941534115"></a>Touch area.</p>
</td>
</tr>
<tr id="row94487132103"><td class="cellrowborder" valign="top" width="21%" headers="mcps1.2.4.1.1 "><p id="p5448113101014"><a name="p5448113101014"></a><a name="p5448113101014"></a>force<sup id="sup15558152223315"><a name="sup15558152223315"></a><a name="sup15558152223315"></a>6+</sup></p>
</td>
<td class="cellrowborder" valign="top" width="16%" headers="mcps1.2.4.1.2 "><p id="p1944911319107"><a name="p1944911319107"></a><a name="p1944911319107"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="63%" headers="mcps1.2.4.1.3 "><p id="p204493130105"><a name="p204493130105"></a><a name="p204493130105"></a>Touch force.</p>
</td>
</tr>
</tbody>
</table>

**Table  4**  Attributes of the SwipeEvent object \(inherited from BaseEvent\)

<a name="table111811577714"></a>
<table><thead align="left"><tr id="row1011820575718"><th class="cellrowborder" valign="top" width="33.33333333333333%" id="mcps1.2.4.1.1"><p id="p81183572071"><a name="p81183572071"></a><a name="p81183572071"></a>Attribute</p>
</th>
<th class="cellrowborder" valign="top" width="33.33333333333333%" id="mcps1.2.4.1.2"><p id="p0118105719719"><a name="p0118105719719"></a><a name="p0118105719719"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="33.33333333333333%" id="mcps1.2.4.1.3"><p id="p111875717717"><a name="p111875717717"></a><a name="p111875717717"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row9118257276"><td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.1 "><p id="p21198576710"><a name="p21198576710"></a><a name="p21198576710"></a>direction</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.2 "><p id="p511918578713"><a name="p511918578713"></a><a name="p511918578713"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.3 "><p id="p41191257174"><a name="p41191257174"></a><a name="p41191257174"></a>Swiping direction. The value can be one of the following:</p>
<a name="ol241216371597"></a><a name="ol241216371597"></a><ol id="ol241216371597"><li><strong id="b151161324356"><a name="b151161324356"></a><a name="b151161324356"></a>left</strong>: Swipe from right to left</li><li><strong id="b19343123183517"><a name="b19343123183517"></a><a name="b19343123183517"></a>right</strong>: Swipe from left to right</li><li><strong id="b168477363520"><a name="b168477363520"></a><a name="b168477363520"></a>up</strong>: Swipe upwards</li><li><strong id="b832616413351"><a name="b832616413351"></a><a name="b832616413351"></a>down</strong>: Swipe downwards</li></ol>
</td>
</tr>
<tr id="row204127481117"><td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.1 "><p id="p16412194131110"><a name="p16412194131110"></a><a name="p16412194131110"></a>distance<sup id="sup167661149153415"><a name="sup167661149153415"></a><a name="sup167661149153415"></a>6+</sup></p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.2 "><p id="p15412945114"><a name="p15412945114"></a><a name="p15412945114"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.3 "><p id="p041344171112"><a name="p041344171112"></a><a name="p041344171112"></a>Swiping distance in the swiping direction.</p>
</td>
</tr>
</tbody>
</table>

**Table  5**  Attributes of the PinchEvent object<sup>7+</sup>

<a name="table1828625919617"></a>
<table><thead align="left"><tr id="row1328711598619"><th class="cellrowborder" valign="top" width="27.47274727472747%" id="mcps1.2.4.1.1"><p id="p1228716594618"><a name="p1228716594618"></a><a name="p1228716594618"></a>Attribute</p>
</th>
<th class="cellrowborder" valign="top" width="27.94279427942794%" id="mcps1.2.4.1.2"><p id="p72877591666"><a name="p72877591666"></a><a name="p72877591666"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="44.58445844584458%" id="mcps1.2.4.1.3"><p id="p1028713591761"><a name="p1028713591761"></a><a name="p1028713591761"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row15287185918613"><td class="cellrowborder" valign="top" width="27.47274727472747%" headers="mcps1.2.4.1.1 "><p id="p6287559764"><a name="p6287559764"></a><a name="p6287559764"></a>scale</p>
</td>
<td class="cellrowborder" valign="top" width="27.94279427942794%" headers="mcps1.2.4.1.2 "><p id="p202871959563"><a name="p202871959563"></a><a name="p202871959563"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="44.58445844584458%" headers="mcps1.2.4.1.3 "><p id="p10884101585"><a name="p10884101585"></a><a name="p10884101585"></a>Scale factor.</p>
</td>
</tr>
<tr id="row192234415459"><td class="cellrowborder" valign="top" width="27.47274727472747%" headers="mcps1.2.4.1.1 "><p id="p17224144111459"><a name="p17224144111459"></a><a name="p17224144111459"></a>pinchCenterX</p>
</td>
<td class="cellrowborder" valign="top" width="27.94279427942794%" headers="mcps1.2.4.1.2 "><p id="p022412411453"><a name="p022412411453"></a><a name="p022412411453"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="44.58445844584458%" headers="mcps1.2.4.1.3 "><p id="p172245414455"><a name="p172245414455"></a><a name="p172245414455"></a>X-coordinate of the pinch center, in px.</p>
</td>
</tr>
<tr id="row435915214512"><td class="cellrowborder" valign="top" width="27.47274727472747%" headers="mcps1.2.4.1.1 "><p id="p13359165234511"><a name="p13359165234511"></a><a name="p13359165234511"></a>pinchCenterY</p>
</td>
<td class="cellrowborder" valign="top" width="27.94279427942794%" headers="mcps1.2.4.1.2 "><p id="p1135913524456"><a name="p1135913524456"></a><a name="p1135913524456"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="44.58445844584458%" headers="mcps1.2.4.1.3 "><p id="p235975213453"><a name="p235975213453"></a><a name="p235975213453"></a>Y-coordinate of the pinch center, in px.</p>
</td>
</tr>
</tbody>
</table>

**Table  6**  Attributes of the DragEvent object \(inherited from BaseEvent\)<sup>7+</sup>

<a name="table95551461358"></a>
<table><thead align="left"><tr id="row0556746250"><th class="cellrowborder" valign="top" width="17%" id="mcps1.2.4.1.1"><p id="p1555617466516"><a name="p1555617466516"></a><a name="p1555617466516"></a>Attribute</p>
</th>
<th class="cellrowborder" valign="top" width="20.06%" id="mcps1.2.4.1.2"><p id="p165561146851"><a name="p165561146851"></a><a name="p165561146851"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="62.94%" id="mcps1.2.4.1.3"><p id="p1155674617514"><a name="p1155674617514"></a><a name="p1155674617514"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row85567466517"><td class="cellrowborder" valign="top" width="17%" headers="mcps1.2.4.1.1 "><p id="p125566461257"><a name="p125566461257"></a><a name="p125566461257"></a>type</p>
</td>
<td class="cellrowborder" valign="top" width="20.06%" headers="mcps1.2.4.1.2 "><p id="p055611461551"><a name="p055611461551"></a><a name="p055611461551"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="62.94%" headers="mcps1.2.4.1.3 "><p id="p18556846051"><a name="p18556846051"></a><a name="p18556846051"></a>Event name.</p>
</td>
</tr>
<tr id="row195568463513"><td class="cellrowborder" valign="top" width="17%" headers="mcps1.2.4.1.1 "><p id="p1255654616515"><a name="p1255654616515"></a><a name="p1255654616515"></a>globalX</p>
</td>
<td class="cellrowborder" valign="top" width="20.06%" headers="mcps1.2.4.1.2 "><p id="p455644618517"><a name="p455644618517"></a><a name="p455644618517"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="62.94%" headers="mcps1.2.4.1.3 "><p id="p135561846957"><a name="p135561846957"></a><a name="p135561846957"></a>Horizontal distance from the origin of the coordinates in the upper left corner of the screen.</p>
</td>
</tr>
<tr id="row19556144619516"><td class="cellrowborder" valign="top" width="17%" headers="mcps1.2.4.1.1 "><p id="p755613461156"><a name="p755613461156"></a><a name="p755613461156"></a>globalY</p>
</td>
<td class="cellrowborder" valign="top" width="20.06%" headers="mcps1.2.4.1.2 "><p id="p145563469516"><a name="p145563469516"></a><a name="p145563469516"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="62.94%" headers="mcps1.2.4.1.3 "><p id="p355612467514"><a name="p355612467514"></a><a name="p355612467514"></a>Vertical distance from the origin of the coordinates in the upper left corner of the screen.</p>
</td>
</tr>
<tr id="row1355615461359"><td class="cellrowborder" valign="top" width="17%" headers="mcps1.2.4.1.1 "><p id="p115561846650"><a name="p115561846650"></a><a name="p115561846650"></a>timestamp</p>
</td>
<td class="cellrowborder" valign="top" width="20.06%" headers="mcps1.2.4.1.2 "><p id="p14557144617513"><a name="p14557144617513"></a><a name="p14557144617513"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="62.94%" headers="mcps1.2.4.1.3 "><p id="p17557194614511"><a name="p17557194614511"></a><a name="p17557194614511"></a>Timestamp.</p>
</td>
</tr>
</tbody>
</table>

## Event Object<a name="section18787165861818"></a>

When a component triggers an event, the event callback receives an event object by default. You can obtain the corresponding information through the event object.

**target object:**

<a name="table1753454616219"></a>
<table><thead align="left"><tr id="row4534124672116"><th class="cellrowborder" valign="top" width="33.33333333333333%" id="mcps1.1.4.1.1"><p id="p105342462217"><a name="p105342462217"></a><a name="p105342462217"></a>Attribute</p>
</th>
<th class="cellrowborder" valign="top" width="33.33333333333333%" id="mcps1.1.4.1.2"><p id="p25342466210"><a name="p25342466210"></a><a name="p25342466210"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="33.33333333333333%" id="mcps1.1.4.1.3"><p id="p1353419469216"><a name="p1353419469216"></a><a name="p1353419469216"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1753415461213"><td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.1.4.1.1 "><p id="p175344463216"><a name="p175344463216"></a><a name="p175344463216"></a>dataSet<sup id="sup94252412316"><a name="sup94252412316"></a><a name="sup94252412316"></a>6+</sup></p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.1.4.1.2 "><p id="p35341546102111"><a name="p35341546102111"></a><a name="p35341546102111"></a>Object</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.1.4.1.3 "><p id="p8534204622111"><a name="p8534204622111"></a><a name="p8534204622111"></a>Custom attribute set defined through <a href="js-components-common-attributes.md">data-*</a>.</p>
</td>
</tr>
</tbody>
</table>

**Example:**

```
<!-- xxx.hml -->
<div>
  <div data-a="dataA" data-b="dataB" 
    style="width: 100%; height: 50%; background-color: saddlebrown;"@touchstart='touchstartfunc'></div>
</div>
```

```
// xxx.js
export default {
  touchstartfunc(msg) {
    console.info(`on touch start, point is: ${msg.touches[0].globalX}`);
    console.info(`on touch start, data is: ${msg.target.dataSet.a}`);
  }
}
```

