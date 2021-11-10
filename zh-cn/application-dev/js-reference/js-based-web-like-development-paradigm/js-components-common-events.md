# 通用事件<a name="ZH-CN_TOPIC_0000001173324611"></a>

## 事件说明<a name="section05041657172410"></a>

-   事件绑定在组件上，当组件达到事件触发条件时，会执行JS中对应的事件回调函数，实现页面UI视图和页面JS逻辑层的交互；
-   事件回调函数中通过参数可以携带额外的信息，如组件上的数据对象dataset，事件特有的回调参数。

相对于私有事件，大部分组件都可以绑定如下事件。

<a name="tf7a840896dc848b5ab17a18b50036601"></a>
<table><thead align="left"><tr id="rf3d0da15d2f64cd492dfa1e7d98890a5"><th class="cellrowborder" valign="top" width="14.96149614961496%" id="mcps1.1.5.1.1"><p id="a487aa1c493e84ca68567b4b65051674d"><a name="a487aa1c493e84ca68567b4b65051674d"></a><a name="a487aa1c493e84ca68567b4b65051674d"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="20.242024202420243%" id="mcps1.1.5.1.2"><p id="adc4b506cda3043508da6ee7649c12ca4"><a name="adc4b506cda3043508da6ee7649c12ca4"></a><a name="adc4b506cda3043508da6ee7649c12ca4"></a>参数</p>
</th>
<th class="cellrowborder" valign="top" width="45.34453445344535%" id="mcps1.1.5.1.3"><p id="a59e4cbe58a5c42a7a4585bc8365783bc"><a name="a59e4cbe58a5c42a7a4585bc8365783bc"></a><a name="a59e4cbe58a5c42a7a4585bc8365783bc"></a>描述</p>
</th>
<th class="cellrowborder" valign="top" width="19.451945194519453%" id="mcps1.1.5.1.4"><p id="p5947175616300"><a name="p5947175616300"></a><a name="p5947175616300"></a>是否支持冒泡</p>
</th>
</tr>
</thead>
<tbody><tr id="r7683acd1d0964f31840d03c9aeb32fca"><td class="cellrowborder" valign="top" width="14.96149614961496%" headers="mcps1.1.5.1.1 "><p id="a58fb4b1d870f466e955cf5ea879c4d4a"><a name="a58fb4b1d870f466e955cf5ea879c4d4a"></a><a name="a58fb4b1d870f466e955cf5ea879c4d4a"></a>touchstart</p>
</td>
<td class="cellrowborder" valign="top" width="20.242024202420243%" headers="mcps1.1.5.1.2 "><p id="abefebd99301b4bdebb798d1b9df24d8d"><a name="abefebd99301b4bdebb798d1b9df24d8d"></a><a name="abefebd99301b4bdebb798d1b9df24d8d"></a><a href="#tdb541af4e4db41d7a92e9b6e3c93f606">TouchEvent</a></p>
</td>
<td class="cellrowborder" valign="top" width="45.34453445344535%" headers="mcps1.1.5.1.3 "><p id="afa4290e2620f4f5fbdcb74dcae84e536"><a name="afa4290e2620f4f5fbdcb74dcae84e536"></a><a name="afa4290e2620f4f5fbdcb74dcae84e536"></a>手指刚触摸屏幕时触发该事件。</p>
</td>
<td class="cellrowborder" valign="top" width="19.451945194519453%" headers="mcps1.1.5.1.4 "><p id="p494775663017"><a name="p494775663017"></a><a name="p494775663017"></a>是<sup id="sup1424819863620"><a name="sup1424819863620"></a><a name="sup1424819863620"></a>5+</sup></p>
</td>
</tr>
<tr id="r7f70ef6c895e4d2d95325887fee7d62e"><td class="cellrowborder" valign="top" width="14.96149614961496%" headers="mcps1.1.5.1.1 "><p id="a23e0317cfee94650be4dcd2280c3e94e"><a name="a23e0317cfee94650be4dcd2280c3e94e"></a><a name="a23e0317cfee94650be4dcd2280c3e94e"></a>touchmove</p>
</td>
<td class="cellrowborder" valign="top" width="20.242024202420243%" headers="mcps1.1.5.1.2 "><p id="aea26e4f9575044dc8fb65080f3a6684a"><a name="aea26e4f9575044dc8fb65080f3a6684a"></a><a name="aea26e4f9575044dc8fb65080f3a6684a"></a><a href="#tdb541af4e4db41d7a92e9b6e3c93f606">TouchEvent</a></p>
</td>
<td class="cellrowborder" valign="top" width="45.34453445344535%" headers="mcps1.1.5.1.3 "><p id="a37f7cc43d82c4ee18512bd079349079d"><a name="a37f7cc43d82c4ee18512bd079349079d"></a><a name="a37f7cc43d82c4ee18512bd079349079d"></a>手指触摸屏幕后移动时触发该事件。</p>
</td>
<td class="cellrowborder" valign="top" width="19.451945194519453%" headers="mcps1.1.5.1.4 "><p id="p1694775683010"><a name="p1694775683010"></a><a name="p1694775683010"></a>是<sup id="sup9681141216369"><a name="sup9681141216369"></a><a name="sup9681141216369"></a>5+</sup></p>
</td>
</tr>
<tr id="ra5c278d41f9045ed9d95e13165974bf4"><td class="cellrowborder" valign="top" width="14.96149614961496%" headers="mcps1.1.5.1.1 "><p id="ad0728eeac06143bbb4a6fdf1ed5c6d91"><a name="ad0728eeac06143bbb4a6fdf1ed5c6d91"></a><a name="ad0728eeac06143bbb4a6fdf1ed5c6d91"></a>touchcancel</p>
</td>
<td class="cellrowborder" valign="top" width="20.242024202420243%" headers="mcps1.1.5.1.2 "><p id="a59e2819eae2b4d3e935991b43156347b"><a name="a59e2819eae2b4d3e935991b43156347b"></a><a name="a59e2819eae2b4d3e935991b43156347b"></a><a href="#tdb541af4e4db41d7a92e9b6e3c93f606">TouchEvent</a></p>
</td>
<td class="cellrowborder" valign="top" width="45.34453445344535%" headers="mcps1.1.5.1.3 "><p id="a739d9ef0db624f6284554aeaeddffa0a"><a name="a739d9ef0db624f6284554aeaeddffa0a"></a><a name="a739d9ef0db624f6284554aeaeddffa0a"></a>手指触摸屏幕中动作被打断时触发该事件。</p>
</td>
<td class="cellrowborder" valign="top" width="19.451945194519453%" headers="mcps1.1.5.1.4 "><p id="p19474565303"><a name="p19474565303"></a><a name="p19474565303"></a>是<sup id="sup1354051315361"><a name="sup1354051315361"></a><a name="sup1354051315361"></a>5+</sup></p>
</td>
</tr>
<tr id="rddfe06969173404d96b60c402a7e783c"><td class="cellrowborder" valign="top" width="14.96149614961496%" headers="mcps1.1.5.1.1 "><p id="a233e2f6ff39f49fd97b8f233875d01d4"><a name="a233e2f6ff39f49fd97b8f233875d01d4"></a><a name="a233e2f6ff39f49fd97b8f233875d01d4"></a>touchend</p>
</td>
<td class="cellrowborder" valign="top" width="20.242024202420243%" headers="mcps1.1.5.1.2 "><p id="a439e69aaf158448e99b3c81cbc9fd624"><a name="a439e69aaf158448e99b3c81cbc9fd624"></a><a name="a439e69aaf158448e99b3c81cbc9fd624"></a><a href="#tdb541af4e4db41d7a92e9b6e3c93f606">TouchEvent</a></p>
</td>
<td class="cellrowborder" valign="top" width="45.34453445344535%" headers="mcps1.1.5.1.3 "><p id="a05c0fe4e05ef4154acee8a06ad56a2de"><a name="a05c0fe4e05ef4154acee8a06ad56a2de"></a><a name="a05c0fe4e05ef4154acee8a06ad56a2de"></a>手指触摸结束离开屏幕时触发该事件。</p>
</td>
<td class="cellrowborder" valign="top" width="19.451945194519453%" headers="mcps1.1.5.1.4 "><p id="p11947456133011"><a name="p11947456133011"></a><a name="p11947456133011"></a>是<sup id="sup762061414361"><a name="sup762061414361"></a><a name="sup762061414361"></a>5+</sup></p>
</td>
</tr>
<tr id="rec1121b8bebc4a3f9ed9a906d061746e"><td class="cellrowborder" valign="top" width="14.96149614961496%" headers="mcps1.1.5.1.1 "><p id="a2fb4de45b1594f6fa1a7da45ce0db57f"><a name="a2fb4de45b1594f6fa1a7da45ce0db57f"></a><a name="a2fb4de45b1594f6fa1a7da45ce0db57f"></a>click</p>
</td>
<td class="cellrowborder" valign="top" width="20.242024202420243%" headers="mcps1.1.5.1.2 "><p id="af86bf1da40504ed2a8d14213a42536ab"><a name="af86bf1da40504ed2a8d14213a42536ab"></a><a name="af86bf1da40504ed2a8d14213a42536ab"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="45.34453445344535%" headers="mcps1.1.5.1.3 "><p id="a1d32f00c38c440ddaa63c3f3e01d4e09"><a name="a1d32f00c38c440ddaa63c3f3e01d4e09"></a><a name="a1d32f00c38c440ddaa63c3f3e01d4e09"></a>点击动作触发该事件。</p>
</td>
<td class="cellrowborder" valign="top" width="19.451945194519453%" headers="mcps1.1.5.1.4 "><p id="p825613220390"><a name="p825613220390"></a><a name="p825613220390"></a>是<sup id="sup84271359397"><a name="sup84271359397"></a><a name="sup84271359397"></a>6+</sup></p>
</td>
</tr>
<tr id="row2705152317020"><td class="cellrowborder" valign="top" width="14.96149614961496%" headers="mcps1.1.5.1.1 "><p id="p1670622317013"><a name="p1670622317013"></a><a name="p1670622317013"></a>doubleclick<sup id="sup898272511424"><a name="sup898272511424"></a><a name="sup898272511424"></a><span>7+</span></sup></p>
</td>
<td class="cellrowborder" valign="top" width="20.242024202420243%" headers="mcps1.1.5.1.2 ">&nbsp;&nbsp;</td>
<td class="cellrowborder" valign="top" width="45.34453445344535%" headers="mcps1.1.5.1.3 "><p id="p10706723605"><a name="p10706723605"></a><a name="p10706723605"></a>双击动作触发该事件</p>
</td>
<td class="cellrowborder" valign="top" width="19.451945194519453%" headers="mcps1.1.5.1.4 "><p id="p1170617231703"><a name="p1170617231703"></a><a name="p1170617231703"></a>否</p>
</td>
</tr>
<tr id="r95f500ef9402487ea42e829d69606f90"><td class="cellrowborder" valign="top" width="14.96149614961496%" headers="mcps1.1.5.1.1 "><p id="aa7dc63d1b4924872bbff6a6a100e928f"><a name="aa7dc63d1b4924872bbff6a6a100e928f"></a><a name="aa7dc63d1b4924872bbff6a6a100e928f"></a>longpress</p>
</td>
<td class="cellrowborder" valign="top" width="20.242024202420243%" headers="mcps1.1.5.1.2 "><p id="a39186f4ff74544d89ace56ea87d9937b"><a name="a39186f4ff74544d89ace56ea87d9937b"></a><a name="a39186f4ff74544d89ace56ea87d9937b"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="45.34453445344535%" headers="mcps1.1.5.1.3 "><p id="a44b8585170304b5596c41714772e605e"><a name="a44b8585170304b5596c41714772e605e"></a><a name="a44b8585170304b5596c41714772e605e"></a>长按动作触发该事件。</p>
</td>
<td class="cellrowborder" valign="top" width="19.451945194519453%" headers="mcps1.1.5.1.4 "><p id="p19655530173713"><a name="p19655530173713"></a><a name="p19655530173713"></a>否</p>
</td>
</tr>
<tr id="row117014569616"><td class="cellrowborder" valign="top" width="14.96149614961496%" headers="mcps1.1.5.1.1 "><p id="p12706561061"><a name="p12706561061"></a><a name="p12706561061"></a>swipe<sup id="sup35424382912"><a name="sup35424382912"></a><a name="sup35424382912"></a>5+</sup></p>
</td>
<td class="cellrowborder" valign="top" width="20.242024202420243%" headers="mcps1.1.5.1.2 "><p id="p11711056161"><a name="p11711056161"></a><a name="p11711056161"></a><a href="#table111811577714">SwipeEvent</a></p>
</td>
<td class="cellrowborder" valign="top" width="45.34453445344535%" headers="mcps1.1.5.1.3 "><p id="p2711556162"><a name="p2711556162"></a><a name="p2711556162"></a>组件上快速滑动后触发该事件。</p>
</td>
<td class="cellrowborder" valign="top" width="19.451945194519453%" headers="mcps1.1.5.1.4 "><p id="p172818312393"><a name="p172818312393"></a><a name="p172818312393"></a>否</p>
</td>
</tr>
<tr id="row4761236154510"><td class="cellrowborder" valign="top" width="14.96149614961496%" headers="mcps1.1.5.1.1 "><p id="p1976143617459"><a name="p1976143617459"></a><a name="p1976143617459"></a>attached<sup id="sup1479243510549"><a name="sup1479243510549"></a><a name="sup1479243510549"></a><span>6+</span></sup></p>
</td>
<td class="cellrowborder" valign="top" width="20.242024202420243%" headers="mcps1.1.5.1.2 "><p id="p876293613452"><a name="p876293613452"></a><a name="p876293613452"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="45.34453445344535%" headers="mcps1.1.5.1.3 "><p id="p676263610459"><a name="p676263610459"></a><a name="p676263610459"></a>当前组件节点挂载在渲染树后触发。</p>
</td>
<td class="cellrowborder" valign="top" width="19.451945194519453%" headers="mcps1.1.5.1.4 "><p id="p79471756173019"><a name="p79471756173019"></a><a name="p79471756173019"></a>否</p>
</td>
</tr>
<tr id="row37951541194613"><td class="cellrowborder" valign="top" width="14.96149614961496%" headers="mcps1.1.5.1.1 "><p id="p12796641204612"><a name="p12796641204612"></a><a name="p12796641204612"></a>detached<sup id="sup18566163910540"><a name="sup18566163910540"></a><a name="sup18566163910540"></a><span>6+</span></sup></p>
</td>
<td class="cellrowborder" valign="top" width="20.242024202420243%" headers="mcps1.1.5.1.2 "><p id="p177961241154618"><a name="p177961241154618"></a><a name="p177961241154618"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="45.34453445344535%" headers="mcps1.1.5.1.3 "><p id="p9796124114612"><a name="p9796124114612"></a><a name="p9796124114612"></a>当前组件节点从渲染树中移除后触发。</p>
</td>
<td class="cellrowborder" valign="top" width="19.451945194519453%" headers="mcps1.1.5.1.4 "><p id="p2947105614304"><a name="p2947105614304"></a><a name="p2947105614304"></a>否</p>
</td>
</tr>
<tr id="row127781725724"><td class="cellrowborder" valign="top" width="14.96149614961496%" headers="mcps1.1.5.1.1 "><p id="p15778202514212"><a name="p15778202514212"></a><a name="p15778202514212"></a>pinchstart<sup id="sup81411323204310"><a name="sup81411323204310"></a><a name="sup81411323204310"></a><span>7+</span></sup></p>
</td>
<td class="cellrowborder" valign="top" width="20.242024202420243%" headers="mcps1.1.5.1.2 "><p id="p577810251824"><a name="p577810251824"></a><a name="p577810251824"></a><a href="#table1828625919617">PinchEvent</a></p>
</td>
<td class="cellrowborder" valign="top" width="45.34453445344535%" headers="mcps1.1.5.1.3 "><p id="p877817251226"><a name="p877817251226"></a><a name="p877817251226"></a>手指开始执行捏合操作时触发该事件。</p>
</td>
<td class="cellrowborder" valign="top" width="19.451945194519453%" headers="mcps1.1.5.1.4 "><p id="p57789251323"><a name="p57789251323"></a><a name="p57789251323"></a>否</p>
</td>
</tr>
<tr id="row192314391432"><td class="cellrowborder" valign="top" width="14.96149614961496%" headers="mcps1.1.5.1.1 "><p id="p69238391334"><a name="p69238391334"></a><a name="p69238391334"></a>pinchupdate<sup id="sup8215182424319"><a name="sup8215182424319"></a><a name="sup8215182424319"></a><span>7+</span></sup></p>
</td>
<td class="cellrowborder" valign="top" width="20.242024202420243%" headers="mcps1.1.5.1.2 "><p id="p1977416315333"><a name="p1977416315333"></a><a name="p1977416315333"></a><a href="#table1828625919617">PinchEvent</a></p>
</td>
<td class="cellrowborder" valign="top" width="45.34453445344535%" headers="mcps1.1.5.1.3 "><p id="p49236391135"><a name="p49236391135"></a><a name="p49236391135"></a>手指执行捏合操作过程中触发该事件。</p>
</td>
<td class="cellrowborder" valign="top" width="19.451945194519453%" headers="mcps1.1.5.1.4 "><p id="p149239398315"><a name="p149239398315"></a><a name="p149239398315"></a>否</p>
</td>
</tr>
<tr id="row487617446316"><td class="cellrowborder" valign="top" width="14.96149614961496%" headers="mcps1.1.5.1.1 "><p id="p987718441331"><a name="p987718441331"></a><a name="p987718441331"></a>pinchend<sup id="sup678725104315"><a name="sup678725104315"></a><a name="sup678725104315"></a><span>7+</span></sup></p>
</td>
<td class="cellrowborder" valign="top" width="20.242024202420243%" headers="mcps1.1.5.1.2 "><p id="p3166118193310"><a name="p3166118193310"></a><a name="p3166118193310"></a><a href="#table1828625919617">PinchEvent</a></p>
</td>
<td class="cellrowborder" valign="top" width="45.34453445344535%" headers="mcps1.1.5.1.3 "><p id="p1987715441638"><a name="p1987715441638"></a><a name="p1987715441638"></a>手指捏合操作结束离开屏幕时触发该事件。</p>
</td>
<td class="cellrowborder" valign="top" width="19.451945194519453%" headers="mcps1.1.5.1.4 "><p id="p14877174410314"><a name="p14877174410314"></a><a name="p14877174410314"></a>否</p>
</td>
</tr>
<tr id="row1930164915319"><td class="cellrowborder" valign="top" width="14.96149614961496%" headers="mcps1.1.5.1.1 "><p id="p1893015491132"><a name="p1893015491132"></a><a name="p1893015491132"></a>pinchcancel<sup id="sup1120714269437"><a name="sup1120714269437"></a><a name="sup1120714269437"></a><span>7+</span></sup></p>
</td>
<td class="cellrowborder" valign="top" width="20.242024202420243%" headers="mcps1.1.5.1.2 "><p id="p1056161218334"><a name="p1056161218334"></a><a name="p1056161218334"></a><a href="#table1828625919617">PinchEvent</a></p>
</td>
<td class="cellrowborder" valign="top" width="45.34453445344535%" headers="mcps1.1.5.1.3 "><p id="p1993034918316"><a name="p1993034918316"></a><a name="p1993034918316"></a>手指捏合操作被打断时触发该事件。</p>
</td>
<td class="cellrowborder" valign="top" width="19.451945194519453%" headers="mcps1.1.5.1.4 "><p id="p15930114916314"><a name="p15930114916314"></a><a name="p15930114916314"></a>否</p>
</td>
</tr>
<tr id="row134184458269"><td class="cellrowborder" valign="top" width="14.96149614961496%" headers="mcps1.1.5.1.1 "><p id="p16418184552612"><a name="p16418184552612"></a><a name="p16418184552612"></a>dragstart<sup id="sup1640611844620"><a name="sup1640611844620"></a><a name="sup1640611844620"></a><span>7+</span></sup></p>
</td>
<td class="cellrowborder" valign="top" width="20.242024202420243%" headers="mcps1.1.5.1.2 "><p id="p14418124562610"><a name="p14418124562610"></a><a name="p14418124562610"></a><a href="#table95551461358">DragEvent</a></p>
</td>
<td class="cellrowborder" valign="top" width="45.34453445344535%" headers="mcps1.1.5.1.3 "><p id="p1341894592614"><a name="p1341894592614"></a><a name="p1341894592614"></a>用户开始拖拽时触发该事件。</p>
</td>
<td class="cellrowborder" valign="top" width="19.451945194519453%" headers="mcps1.1.5.1.4 "><p id="p1341811451268"><a name="p1341811451268"></a><a name="p1341811451268"></a>否</p>
</td>
</tr>
<tr id="row195941786134"><td class="cellrowborder" valign="top" width="14.96149614961496%" headers="mcps1.1.5.1.1 "><p id="p6151151019134"><a name="p6151151019134"></a><a name="p6151151019134"></a>drag<sup id="sup317711477125"><a name="sup317711477125"></a><a name="sup317711477125"></a><span>7+</span></sup></p>
</td>
<td class="cellrowborder" valign="top" width="20.242024202420243%" headers="mcps1.1.5.1.2 "><p id="p1151110191313"><a name="p1151110191313"></a><a name="p1151110191313"></a><a href="#table95551461358">DragEvent</a></p>
</td>
<td class="cellrowborder" valign="top" width="45.34453445344535%" headers="mcps1.1.5.1.3 "><p id="p915141041313"><a name="p915141041313"></a><a name="p915141041313"></a>拖拽过程中触发该事件。</p>
</td>
<td class="cellrowborder" valign="top" width="19.451945194519453%" headers="mcps1.1.5.1.4 "><p id="p1815112102131"><a name="p1815112102131"></a><a name="p1815112102131"></a>否</p>
</td>
</tr>
<tr id="row343314310509"><td class="cellrowborder" valign="top" width="14.96149614961496%" headers="mcps1.1.5.1.1 "><p id="p243393145013"><a name="p243393145013"></a><a name="p243393145013"></a>dragend<sup id="sup1016615910463"><a name="sup1016615910463"></a><a name="sup1016615910463"></a><span>7+</span></sup></p>
</td>
<td class="cellrowborder" valign="top" width="20.242024202420243%" headers="mcps1.1.5.1.2 "><p id="p94331834504"><a name="p94331834504"></a><a name="p94331834504"></a><a href="#table95551461358">DragEvent</a></p>
</td>
<td class="cellrowborder" valign="top" width="45.34453445344535%" headers="mcps1.1.5.1.3 "><p id="p143310312509"><a name="p143310312509"></a><a name="p143310312509"></a>用户拖拽完成后触发。</p>
</td>
<td class="cellrowborder" valign="top" width="19.451945194519453%" headers="mcps1.1.5.1.4 "><p id="p194331833500"><a name="p194331833500"></a><a name="p194331833500"></a>否</p>
</td>
</tr>
<tr id="row129701428135013"><td class="cellrowborder" valign="top" width="14.96149614961496%" headers="mcps1.1.5.1.1 "><p id="p3970152810505"><a name="p3970152810505"></a><a name="p3970152810505"></a>dragenter<sup id="sup685614917463"><a name="sup685614917463"></a><a name="sup685614917463"></a><span>7+</span></sup></p>
</td>
<td class="cellrowborder" valign="top" width="20.242024202420243%" headers="mcps1.1.5.1.2 "><p id="p697082875015"><a name="p697082875015"></a><a name="p697082875015"></a><a href="#table95551461358">DragEvent</a></p>
</td>
<td class="cellrowborder" valign="top" width="45.34453445344535%" headers="mcps1.1.5.1.3 "><p id="p79702028125013"><a name="p79702028125013"></a><a name="p79702028125013"></a>进入释放目标时触发该事件。</p>
</td>
<td class="cellrowborder" valign="top" width="19.451945194519453%" headers="mcps1.1.5.1.4 "><p id="p1297011285502"><a name="p1297011285502"></a><a name="p1297011285502"></a>否</p>
</td>
</tr>
<tr id="row139802344501"><td class="cellrowborder" valign="top" width="14.96149614961496%" headers="mcps1.1.5.1.1 "><p id="p1798473495020"><a name="p1798473495020"></a><a name="p1798473495020"></a>dragover<sup id="sup166541210204610"><a name="sup166541210204610"></a><a name="sup166541210204610"></a><span>7+</span></sup></p>
</td>
<td class="cellrowborder" valign="top" width="20.242024202420243%" headers="mcps1.1.5.1.2 "><p id="p1598793419509"><a name="p1598793419509"></a><a name="p1598793419509"></a><a href="#table95551461358">DragEvent</a></p>
</td>
<td class="cellrowborder" valign="top" width="45.34453445344535%" headers="mcps1.1.5.1.3 "><p id="p8987163414509"><a name="p8987163414509"></a><a name="p8987163414509"></a>在释放目标内拖动时触发。</p>
</td>
<td class="cellrowborder" valign="top" width="19.451945194519453%" headers="mcps1.1.5.1.4 "><p id="p19987103405015"><a name="p19987103405015"></a><a name="p19987103405015"></a>否</p>
</td>
</tr>
<tr id="row833215394509"><td class="cellrowborder" valign="top" width="14.96149614961496%" headers="mcps1.1.5.1.1 "><p id="p633512393503"><a name="p633512393503"></a><a name="p633512393503"></a>dragleave<sup id="sup18549201194615"><a name="sup18549201194615"></a><a name="sup18549201194615"></a><span>7+</span></sup></p>
</td>
<td class="cellrowborder" valign="top" width="20.242024202420243%" headers="mcps1.1.5.1.2 "><p id="p18335153913504"><a name="p18335153913504"></a><a name="p18335153913504"></a><a href="#table95551461358">DragEvent</a></p>
</td>
<td class="cellrowborder" valign="top" width="45.34453445344535%" headers="mcps1.1.5.1.3 "><p id="p8335173910503"><a name="p8335173910503"></a><a name="p8335173910503"></a>离开释放目标区域时触发。</p>
</td>
<td class="cellrowborder" valign="top" width="19.451945194519453%" headers="mcps1.1.5.1.4 "><p id="p10338193915012"><a name="p10338193915012"></a><a name="p10338193915012"></a>否</p>
</td>
</tr>
<tr id="row82701055155015"><td class="cellrowborder" valign="top" width="14.96149614961496%" headers="mcps1.1.5.1.1 "><p id="p8270205585018"><a name="p8270205585018"></a><a name="p8270205585018"></a>drop<sup id="sup3324161319467"><a name="sup3324161319467"></a><a name="sup3324161319467"></a><span>7+</span></sup></p>
</td>
<td class="cellrowborder" valign="top" width="20.242024202420243%" headers="mcps1.1.5.1.2 "><p id="p1627055514502"><a name="p1627055514502"></a><a name="p1627055514502"></a><a href="#table95551461358">DragEvent</a></p>
</td>
<td class="cellrowborder" valign="top" width="45.34453445344535%" headers="mcps1.1.5.1.3 "><p id="p162704558509"><a name="p162704558509"></a><a name="p162704558509"></a>在可释放目标区域内释放时触发。</p>
</td>
<td class="cellrowborder" valign="top" width="19.451945194519453%" headers="mcps1.1.5.1.4 "><p id="p127065585014"><a name="p127065585014"></a><a name="p127065585014"></a>否</p>
</td>
</tr>
</tbody>
</table>

>![](../../public_sys-resources/icon-note.gif) **说明：** 
>-   除上述事件外，其他事件均为非冒泡事件，如[input的change事件](js-components-basic-input.md#section1721512551218)，详见各个组件。

**表 1**  BaseEvent对象属性列表

<a name="t4afe3a7d9546429ca1113ff78333d1c5"></a>
<table><thead align="left"><tr id="r17b57a5916254b538712224afce3ec93"><th class="cellrowborder" valign="top" width="17.169999999999998%" id="mcps1.2.4.1.1"><p id="a85fa8e3227fc48a2b8bc9c953327ae36"><a name="a85fa8e3227fc48a2b8bc9c953327ae36"></a><a name="a85fa8e3227fc48a2b8bc9c953327ae36"></a>属性</p>
</th>
<th class="cellrowborder" valign="top" width="14.14%" id="mcps1.2.4.1.2"><p id="aae0028a39da64592bc9e3de357419d3b"><a name="aae0028a39da64592bc9e3de357419d3b"></a><a name="aae0028a39da64592bc9e3de357419d3b"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="68.69%" id="mcps1.2.4.1.3"><p id="a84e596443d8d4e80ab2d990e87e19d0a"><a name="a84e596443d8d4e80ab2d990e87e19d0a"></a><a name="a84e596443d8d4e80ab2d990e87e19d0a"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="ref9724a78ebd4f959cc159def567a6e5"><td class="cellrowborder" valign="top" width="17.169999999999998%" headers="mcps1.2.4.1.1 "><p id="a8e318c4332dd44cda62259cd5018bc7c"><a name="a8e318c4332dd44cda62259cd5018bc7c"></a><a name="a8e318c4332dd44cda62259cd5018bc7c"></a>type</p>
</td>
<td class="cellrowborder" valign="top" width="14.14%" headers="mcps1.2.4.1.2 "><p id="a567269320f1c43b3984e231f61130431"><a name="a567269320f1c43b3984e231f61130431"></a><a name="a567269320f1c43b3984e231f61130431"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="68.69%" headers="mcps1.2.4.1.3 "><p id="a732751a8a4114815953f940529086cc4"><a name="a732751a8a4114815953f940529086cc4"></a><a name="a732751a8a4114815953f940529086cc4"></a>当前事件的类型，比如click、longpress等。</p>
</td>
</tr>
<tr id="rc5890121a2e14421be07b897d2c04995"><td class="cellrowborder" valign="top" width="17.169999999999998%" headers="mcps1.2.4.1.1 "><p id="a8f15a7cee90e48ac80b09f0f3ba1bc3a"><a name="a8f15a7cee90e48ac80b09f0f3ba1bc3a"></a><a name="a8f15a7cee90e48ac80b09f0f3ba1bc3a"></a>timestamp</p>
</td>
<td class="cellrowborder" valign="top" width="14.14%" headers="mcps1.2.4.1.2 "><p id="a257a70e6a33d481e8c32f4551d33f6e4"><a name="a257a70e6a33d481e8c32f4551d33f6e4"></a><a name="a257a70e6a33d481e8c32f4551d33f6e4"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="68.69%" headers="mcps1.2.4.1.3 "><p id="a816c5efe2ab2447bbd14dfd91095052c"><a name="a816c5efe2ab2447bbd14dfd91095052c"></a><a name="a816c5efe2ab2447bbd14dfd91095052c"></a>该事件触发时的时间戳。</p>
</td>
</tr>
</tbody>
</table>

**表 2**  TouchEvent对象属性列表\(继承BaseEvent\)

<a name="tdb541af4e4db41d7a92e9b6e3c93f606"></a>
<table><thead align="left"><tr id="rea83e482278e4251975cce4fd873c6bb"><th class="cellrowborder" valign="top" width="19.439999999999998%" id="mcps1.2.4.1.1"><p id="a82b31036c9c94b3d8a7702523f9b40ec"><a name="a82b31036c9c94b3d8a7702523f9b40ec"></a><a name="a82b31036c9c94b3d8a7702523f9b40ec"></a>属性</p>
</th>
<th class="cellrowborder" valign="top" width="20.14%" id="mcps1.2.4.1.2"><p id="a916c9aa3c32e4903953063bb7424027c"><a name="a916c9aa3c32e4903953063bb7424027c"></a><a name="a916c9aa3c32e4903953063bb7424027c"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="60.419999999999995%" id="mcps1.2.4.1.3"><p id="af9aad173dc2f44f5be69c86fe5537af7"><a name="af9aad173dc2f44f5be69c86fe5537af7"></a><a name="af9aad173dc2f44f5be69c86fe5537af7"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="r2f3c99711cf243c19b359026f2863056"><td class="cellrowborder" valign="top" width="19.439999999999998%" headers="mcps1.2.4.1.1 "><p id="a660dbbfaf8d349b7921fbe9a0b96574a"><a name="a660dbbfaf8d349b7921fbe9a0b96574a"></a><a name="a660dbbfaf8d349b7921fbe9a0b96574a"></a>touches</p>
</td>
<td class="cellrowborder" valign="top" width="20.14%" headers="mcps1.2.4.1.2 "><p id="aab0506a4edc147beb25866891e5fddcd"><a name="aab0506a4edc147beb25866891e5fddcd"></a><a name="aab0506a4edc147beb25866891e5fddcd"></a>Array&lt;TouchInfo&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="60.419999999999995%" headers="mcps1.2.4.1.3 "><p id="aa3d09d0a55704a6097fb39739436c5db"><a name="aa3d09d0a55704a6097fb39739436c5db"></a><a name="aa3d09d0a55704a6097fb39739436c5db"></a>触摸事件时的属性集合，包含屏幕触摸点的信息数组。</p>
</td>
</tr>
<tr id="raad83bde64d9482f8a56c44ae45b3f77"><td class="cellrowborder" valign="top" width="19.439999999999998%" headers="mcps1.2.4.1.1 "><p id="a7e263f0434c94a16a584943ddde92012"><a name="a7e263f0434c94a16a584943ddde92012"></a><a name="a7e263f0434c94a16a584943ddde92012"></a>changedTouches</p>
</td>
<td class="cellrowborder" valign="top" width="20.14%" headers="mcps1.2.4.1.2 "><p id="a76ffd0f779234ab6a77e808500fca675"><a name="a76ffd0f779234ab6a77e808500fca675"></a><a name="a76ffd0f779234ab6a77e808500fca675"></a>Array&lt;TouchInfo&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="60.419999999999995%" headers="mcps1.2.4.1.3 "><p id="a85eddf1d320641a8b344aaadffe6d49e"><a name="a85eddf1d320641a8b344aaadffe6d49e"></a><a name="a85eddf1d320641a8b344aaadffe6d49e"></a>触摸事件时的属性集合，包括产生变化的屏幕触摸点的信息数组。数据格式和touches一样。该属性表示有变化的触摸点，如从无变有，位置变化，从有变无。例如用户手指刚接触屏幕时，touches数组中有数据，但changedTouches无数据。</p>
</td>
</tr>
</tbody>
</table>

**表 3**  TouchInfo

<a name="tf03fc1fac826405d95028a3b880047b6"></a>
<table><thead align="left"><tr id="rff1c937243f04922b941ec313c0cc858"><th class="cellrowborder" valign="top" width="21.060000000000002%" id="mcps1.2.4.1.1"><p id="a7f9f203c859c4f2ab2f44035c97cffa7"><a name="a7f9f203c859c4f2ab2f44035c97cffa7"></a><a name="a7f9f203c859c4f2ab2f44035c97cffa7"></a>属性</p>
</th>
<th class="cellrowborder" valign="top" width="15.939999999999998%" id="mcps1.2.4.1.2"><p id="a00de9107caaf46968b7d3a52f0c9718f"><a name="a00de9107caaf46968b7d3a52f0c9718f"></a><a name="a00de9107caaf46968b7d3a52f0c9718f"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="63%" id="mcps1.2.4.1.3"><p id="a3406658ff5084d1aaad3fca32c5d31d6"><a name="a3406658ff5084d1aaad3fca32c5d31d6"></a><a name="a3406658ff5084d1aaad3fca32c5d31d6"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="r19de9fd9501e4d99a3a9232b7fb94c98"><td class="cellrowborder" valign="top" width="21.060000000000002%" headers="mcps1.2.4.1.1 "><p id="a8653f3e51af34bb78136455652a61cec"><a name="a8653f3e51af34bb78136455652a61cec"></a><a name="a8653f3e51af34bb78136455652a61cec"></a>globalX</p>
</td>
<td class="cellrowborder" valign="top" width="15.939999999999998%" headers="mcps1.2.4.1.2 "><p id="add8c97142b8742f78503909547ebd380"><a name="add8c97142b8742f78503909547ebd380"></a><a name="add8c97142b8742f78503909547ebd380"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="63%" headers="mcps1.2.4.1.3 "><p id="a834cd2553aa7439781eeeddd342329df"><a name="a834cd2553aa7439781eeeddd342329df"></a><a name="a834cd2553aa7439781eeeddd342329df"></a>距离屏幕左上角（不包括状态栏）横向距离。屏幕的左上角为原点。</p>
</td>
</tr>
<tr id="rde7a56164c134cd2a1afce437e437211"><td class="cellrowborder" valign="top" width="21.060000000000002%" headers="mcps1.2.4.1.1 "><p id="aebdebb651e74449fb00e1b9930564eac"><a name="aebdebb651e74449fb00e1b9930564eac"></a><a name="aebdebb651e74449fb00e1b9930564eac"></a>globalY</p>
</td>
<td class="cellrowborder" valign="top" width="15.939999999999998%" headers="mcps1.2.4.1.2 "><p id="a3bcbd4de1a634f3195b525d00f1c9667"><a name="a3bcbd4de1a634f3195b525d00f1c9667"></a><a name="a3bcbd4de1a634f3195b525d00f1c9667"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="63%" headers="mcps1.2.4.1.3 "><p id="a5a1306479f784edf8a5a42f76e2540be"><a name="a5a1306479f784edf8a5a42f76e2540be"></a><a name="a5a1306479f784edf8a5a42f76e2540be"></a>距离屏幕左上角（不包括状态栏）纵向距离。屏幕的左上角为原点。</p>
</td>
</tr>
<tr id="r94760564980c470490555043898942f3"><td class="cellrowborder" valign="top" width="21.060000000000002%" headers="mcps1.2.4.1.1 "><p id="a1a1011d86d0c4149a43d0175e75028c5"><a name="a1a1011d86d0c4149a43d0175e75028c5"></a><a name="a1a1011d86d0c4149a43d0175e75028c5"></a>localX</p>
</td>
<td class="cellrowborder" valign="top" width="15.939999999999998%" headers="mcps1.2.4.1.2 "><p id="a0618e3c91a61456a9a9ad2c23095cca5"><a name="a0618e3c91a61456a9a9ad2c23095cca5"></a><a name="a0618e3c91a61456a9a9ad2c23095cca5"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="63%" headers="mcps1.2.4.1.3 "><p id="ad7268ba243c546af8f93208c427c5340"><a name="ad7268ba243c546af8f93208c427c5340"></a><a name="ad7268ba243c546af8f93208c427c5340"></a>距离被触摸组件左上角横向距离。组件的左上角为原点。</p>
</td>
</tr>
<tr id="ra0ea6d13e3224d3fac80631ac8458af7"><td class="cellrowborder" valign="top" width="21.060000000000002%" headers="mcps1.2.4.1.1 "><p id="ab9af76cc10bf4da49cef6ff3a201ff46"><a name="ab9af76cc10bf4da49cef6ff3a201ff46"></a><a name="ab9af76cc10bf4da49cef6ff3a201ff46"></a>localY</p>
</td>
<td class="cellrowborder" valign="top" width="15.939999999999998%" headers="mcps1.2.4.1.2 "><p id="a7d7052c11197432aa14f39bb4039d7aa"><a name="a7d7052c11197432aa14f39bb4039d7aa"></a><a name="a7d7052c11197432aa14f39bb4039d7aa"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="63%" headers="mcps1.2.4.1.3 "><p id="ae3aa585280c449e5a8fe954711ab56fd"><a name="ae3aa585280c449e5a8fe954711ab56fd"></a><a name="ae3aa585280c449e5a8fe954711ab56fd"></a>距离被触摸组件左上角纵向距离。组件的左上角为原点。</p>
</td>
</tr>
<tr id="row199451713154119"><td class="cellrowborder" valign="top" width="21.060000000000002%" headers="mcps1.2.4.1.1 "><p id="p3369201515412"><a name="p3369201515412"></a><a name="p3369201515412"></a>size</p>
</td>
<td class="cellrowborder" valign="top" width="15.939999999999998%" headers="mcps1.2.4.1.2 "><p id="p14369121514116"><a name="p14369121514116"></a><a name="p14369121514116"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="63%" headers="mcps1.2.4.1.3 "><p id="p336941534115"><a name="p336941534115"></a><a name="p336941534115"></a>触摸接触面积。</p>
</td>
</tr>
<tr id="row94487132103"><td class="cellrowborder" valign="top" width="21.060000000000002%" headers="mcps1.2.4.1.1 "><p id="p5448113101014"><a name="p5448113101014"></a><a name="p5448113101014"></a>force<sup id="sup15558152223315"><a name="sup15558152223315"></a><a name="sup15558152223315"></a>6+</sup></p>
</td>
<td class="cellrowborder" valign="top" width="15.939999999999998%" headers="mcps1.2.4.1.2 "><p id="p1944911319107"><a name="p1944911319107"></a><a name="p1944911319107"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="63%" headers="mcps1.2.4.1.3 "><p id="p204493130105"><a name="p204493130105"></a><a name="p204493130105"></a>接触力信息。</p>
</td>
</tr>
</tbody>
</table>

**表 4**  SwipeEvent 基础事件对象属性列表（继承BaseEvent）

<a name="table111811577714"></a>
<table><thead align="left"><tr id="row1011820575718"><th class="cellrowborder" valign="top" width="27.47274727472747%" id="mcps1.2.4.1.1"><p id="p81183572071"><a name="p81183572071"></a><a name="p81183572071"></a>属性</p>
</th>
<th class="cellrowborder" valign="top" width="27.94279427942794%" id="mcps1.2.4.1.2"><p id="p0118105719719"><a name="p0118105719719"></a><a name="p0118105719719"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="44.58445844584458%" id="mcps1.2.4.1.3"><p id="p111875717717"><a name="p111875717717"></a><a name="p111875717717"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="row9118257276"><td class="cellrowborder" valign="top" width="27.47274727472747%" headers="mcps1.2.4.1.1 "><p id="p21198576710"><a name="p21198576710"></a><a name="p21198576710"></a>direction</p>
</td>
<td class="cellrowborder" valign="top" width="27.94279427942794%" headers="mcps1.2.4.1.2 "><p id="p511918578713"><a name="p511918578713"></a><a name="p511918578713"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="44.58445844584458%" headers="mcps1.2.4.1.3 "><p id="p41191257174"><a name="p41191257174"></a><a name="p41191257174"></a>滑动方向，可能值有：</p>
<a name="ol241216371597"></a><a name="ol241216371597"></a><ol id="ol241216371597"><li>left：向左滑动；</li><li>right：向右滑动；</li><li>up：向上滑动；</li><li>down：向下滑动。</li></ol>
</td>
</tr>
<tr id="row204127481117"><td class="cellrowborder" valign="top" width="27.47274727472747%" headers="mcps1.2.4.1.1 "><p id="p16412194131110"><a name="p16412194131110"></a><a name="p16412194131110"></a>distance<sup id="sup167661149153415"><a name="sup167661149153415"></a><a name="sup167661149153415"></a>6+</sup></p>
</td>
<td class="cellrowborder" valign="top" width="27.94279427942794%" headers="mcps1.2.4.1.2 "><p id="p15412945114"><a name="p15412945114"></a><a name="p15412945114"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="44.58445844584458%" headers="mcps1.2.4.1.3 "><p id="p041344171112"><a name="p041344171112"></a><a name="p041344171112"></a>在滑动方向上的滑动距离。</p>
</td>
</tr>
</tbody>
</table>

**表 5**  PinchEvent 对象属性列表<sup>7+</sup>

<a name="table1828625919617"></a>
<table><thead align="left"><tr id="row1328711598619"><th class="cellrowborder" valign="top" width="27.47274727472747%" id="mcps1.2.4.1.1"><p id="p1228716594618"><a name="p1228716594618"></a><a name="p1228716594618"></a>属性</p>
</th>
<th class="cellrowborder" valign="top" width="27.94279427942794%" id="mcps1.2.4.1.2"><p id="p72877591666"><a name="p72877591666"></a><a name="p72877591666"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="44.58445844584458%" id="mcps1.2.4.1.3"><p id="p1028713591761"><a name="p1028713591761"></a><a name="p1028713591761"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="row15287185918613"><td class="cellrowborder" valign="top" width="27.47274727472747%" headers="mcps1.2.4.1.1 "><p id="p6287559764"><a name="p6287559764"></a><a name="p6287559764"></a>scale</p>
</td>
<td class="cellrowborder" valign="top" width="27.94279427942794%" headers="mcps1.2.4.1.2 "><p id="p202871959563"><a name="p202871959563"></a><a name="p202871959563"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="44.58445844584458%" headers="mcps1.2.4.1.3 "><p id="p10884101585"><a name="p10884101585"></a><a name="p10884101585"></a>缩放比例</p>
</td>
</tr>
<tr id="row192234415459"><td class="cellrowborder" valign="top" width="27.47274727472747%" headers="mcps1.2.4.1.1 "><p id="p17224144111459"><a name="p17224144111459"></a><a name="p17224144111459"></a>pinchCenterX</p>
</td>
<td class="cellrowborder" valign="top" width="27.94279427942794%" headers="mcps1.2.4.1.2 "><p id="p022412411453"><a name="p022412411453"></a><a name="p022412411453"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="44.58445844584458%" headers="mcps1.2.4.1.3 "><p id="p172245414455"><a name="p172245414455"></a><a name="p172245414455"></a>捏合中心点X轴坐标，单位px</p>
</td>
</tr>
<tr id="row435915214512"><td class="cellrowborder" valign="top" width="27.47274727472747%" headers="mcps1.2.4.1.1 "><p id="p13359165234511"><a name="p13359165234511"></a><a name="p13359165234511"></a>pinchCenterY</p>
</td>
<td class="cellrowborder" valign="top" width="27.94279427942794%" headers="mcps1.2.4.1.2 "><p id="p1135913524456"><a name="p1135913524456"></a><a name="p1135913524456"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="44.58445844584458%" headers="mcps1.2.4.1.3 "><p id="p235975213453"><a name="p235975213453"></a><a name="p235975213453"></a>捏合中心点Y轴坐标，单位px</p>
</td>
</tr>
</tbody>
</table>

**表 6**  DragEvent对象属性列表\(继承BaseEvent\)<sup>7+</sup>\(Rich\)

<a name="table95551461358"></a>
<table><thead align="left"><tr id="row0556746250"><th class="cellrowborder" valign="top" width="17%" id="mcps1.2.4.1.1"><p id="p1555617466516"><a name="p1555617466516"></a><a name="p1555617466516"></a>属性</p>
</th>
<th class="cellrowborder" valign="top" width="20.06%" id="mcps1.2.4.1.2"><p id="p165561146851"><a name="p165561146851"></a><a name="p165561146851"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="62.94%" id="mcps1.2.4.1.3"><p id="p1155674617514"><a name="p1155674617514"></a><a name="p1155674617514"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="row85567466517"><td class="cellrowborder" valign="top" width="17%" headers="mcps1.2.4.1.1 "><p id="p125566461257"><a name="p125566461257"></a><a name="p125566461257"></a>type</p>
</td>
<td class="cellrowborder" valign="top" width="20.06%" headers="mcps1.2.4.1.2 "><p id="p055611461551"><a name="p055611461551"></a><a name="p055611461551"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="62.94%" headers="mcps1.2.4.1.3 "><p id="p18556846051"><a name="p18556846051"></a><a name="p18556846051"></a>事件名称。</p>
</td>
</tr>
<tr id="row195568463513"><td class="cellrowborder" valign="top" width="17%" headers="mcps1.2.4.1.1 "><p id="p1255654616515"><a name="p1255654616515"></a><a name="p1255654616515"></a>globalX</p>
</td>
<td class="cellrowborder" valign="top" width="20.06%" headers="mcps1.2.4.1.2 "><p id="p455644618517"><a name="p455644618517"></a><a name="p455644618517"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="62.94%" headers="mcps1.2.4.1.3 "><p id="p135561846957"><a name="p135561846957"></a><a name="p135561846957"></a>距离屏幕左上角坐标原点横向距离。</p>
</td>
</tr>
<tr id="row19556144619516"><td class="cellrowborder" valign="top" width="17%" headers="mcps1.2.4.1.1 "><p id="p755613461156"><a name="p755613461156"></a><a name="p755613461156"></a>globalY</p>
</td>
<td class="cellrowborder" valign="top" width="20.06%" headers="mcps1.2.4.1.2 "><p id="p145563469516"><a name="p145563469516"></a><a name="p145563469516"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="62.94%" headers="mcps1.2.4.1.3 "><p id="p355612467514"><a name="p355612467514"></a><a name="p355612467514"></a>距离屏幕左上角坐标原点纵向距离。</p>
</td>
</tr>
<tr id="row1355615461359"><td class="cellrowborder" valign="top" width="17%" headers="mcps1.2.4.1.1 "><p id="p115561846650"><a name="p115561846650"></a><a name="p115561846650"></a>timestamp</p>
</td>
<td class="cellrowborder" valign="top" width="20.06%" headers="mcps1.2.4.1.2 "><p id="p14557144617513"><a name="p14557144617513"></a><a name="p14557144617513"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="62.94%" headers="mcps1.2.4.1.3 "><p id="p17557194614511"><a name="p17557194614511"></a><a name="p17557194614511"></a>时间戳。</p>
</td>
</tr>
</tbody>
</table>

## 事件对象<a name="section18787165861818"></a>

当组件触发事件后，事件回调函数默认会收到一个事件对象，通过该事件对象可以获取相应的信息。

**target对象：**

<a name="table1753454616219"></a>
<table><thead align="left"><tr id="row4534124672116"><th class="cellrowborder" valign="top" width="33.33333333333333%" id="mcps1.1.4.1.1"><p id="p105342462217"><a name="p105342462217"></a><a name="p105342462217"></a>属性</p>
</th>
<th class="cellrowborder" valign="top" width="33.33333333333333%" id="mcps1.1.4.1.2"><p id="p25342466210"><a name="p25342466210"></a><a name="p25342466210"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="33.33333333333333%" id="mcps1.1.4.1.3"><p id="p1353419469216"><a name="p1353419469216"></a><a name="p1353419469216"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="row1753415461213"><td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.1.4.1.1 "><p id="p175344463216"><a name="p175344463216"></a><a name="p175344463216"></a>dataSet<sup id="sup94252412316"><a name="sup94252412316"></a><a name="sup94252412316"></a><span>6+</span></sup></p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.1.4.1.2 "><p id="p35341546102111"><a name="p35341546102111"></a><a name="p35341546102111"></a>Object</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.1.4.1.3 "><p id="p8534204622111"><a name="p8534204622111"></a><a name="p8534204622111"></a><span>组件上通过通用属性设置的</span><a href="js-components-common-attributes.md">data-*</a><span>的自定义属性组成的集合。</span></p>
</td>
</tr>
</tbody>
</table>

**示例：**

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

