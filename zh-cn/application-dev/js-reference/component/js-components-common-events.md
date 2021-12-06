# 通用事件<a name="ZH-CN_TOPIC_0000001209412119"></a>

## 事件说明<a name="zh-cn_topic_0000001173324611_section05041657172410"></a>

-   事件绑定在组件上，当组件达到事件触发条件时，会执行JS中对应的事件回调函数，实现页面UI视图和页面JS逻辑层的交互；
-   事件回调函数中通过参数可以携带额外的信息，如组件上的数据对象dataset，事件特有的回调参数。

相对于私有事件，大部分组件都可以绑定如下事件。

<a name="zh-cn_topic_0000001173324611_tf7a840896dc848b5ab17a18b50036601"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001173324611_rf3d0da15d2f64cd492dfa1e7d98890a5"><th class="cellrowborder" valign="top" width="14.96149614961496%" id="mcps1.1.5.1.1"><p id="zh-cn_topic_0000001173324611_a487aa1c493e84ca68567b4b65051674d"><a name="zh-cn_topic_0000001173324611_a487aa1c493e84ca68567b4b65051674d"></a><a name="zh-cn_topic_0000001173324611_a487aa1c493e84ca68567b4b65051674d"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="20.242024202420243%" id="mcps1.1.5.1.2"><p id="zh-cn_topic_0000001173324611_adc4b506cda3043508da6ee7649c12ca4"><a name="zh-cn_topic_0000001173324611_adc4b506cda3043508da6ee7649c12ca4"></a><a name="zh-cn_topic_0000001173324611_adc4b506cda3043508da6ee7649c12ca4"></a>参数</p>
</th>
<th class="cellrowborder" valign="top" width="45.34453445344535%" id="mcps1.1.5.1.3"><p id="zh-cn_topic_0000001173324611_a59e4cbe58a5c42a7a4585bc8365783bc"><a name="zh-cn_topic_0000001173324611_a59e4cbe58a5c42a7a4585bc8365783bc"></a><a name="zh-cn_topic_0000001173324611_a59e4cbe58a5c42a7a4585bc8365783bc"></a>描述</p>
</th>
<th class="cellrowborder" valign="top" width="19.451945194519453%" id="mcps1.1.5.1.4"><p id="zh-cn_topic_0000001173324611_p5947175616300"><a name="zh-cn_topic_0000001173324611_p5947175616300"></a><a name="zh-cn_topic_0000001173324611_p5947175616300"></a>是否支持冒泡</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001173324611_r7683acd1d0964f31840d03c9aeb32fca"><td class="cellrowborder" valign="top" width="14.96149614961496%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001173324611_a58fb4b1d870f466e955cf5ea879c4d4a"><a name="zh-cn_topic_0000001173324611_a58fb4b1d870f466e955cf5ea879c4d4a"></a><a name="zh-cn_topic_0000001173324611_a58fb4b1d870f466e955cf5ea879c4d4a"></a>touchstart</p>
</td>
<td class="cellrowborder" valign="top" width="20.242024202420243%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001173324611_abefebd99301b4bdebb798d1b9df24d8d"><a name="zh-cn_topic_0000001173324611_abefebd99301b4bdebb798d1b9df24d8d"></a><a name="zh-cn_topic_0000001173324611_abefebd99301b4bdebb798d1b9df24d8d"></a><a href="#zh-cn_topic_0000001173324611_tdb541af4e4db41d7a92e9b6e3c93f606">TouchEvent</a></p>
</td>
<td class="cellrowborder" valign="top" width="45.34453445344535%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001173324611_afa4290e2620f4f5fbdcb74dcae84e536"><a name="zh-cn_topic_0000001173324611_afa4290e2620f4f5fbdcb74dcae84e536"></a><a name="zh-cn_topic_0000001173324611_afa4290e2620f4f5fbdcb74dcae84e536"></a>手指刚触摸屏幕时触发该事件。</p>
</td>
<td class="cellrowborder" valign="top" width="19.451945194519453%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000001173324611_p494775663017"><a name="zh-cn_topic_0000001173324611_p494775663017"></a><a name="zh-cn_topic_0000001173324611_p494775663017"></a>是<sup id="zh-cn_topic_0000001173324611_sup1424819863620"><a name="zh-cn_topic_0000001173324611_sup1424819863620"></a><a name="zh-cn_topic_0000001173324611_sup1424819863620"></a>5+</sup></p>
</td>
</tr>
<tr id="zh-cn_topic_0000001173324611_r7f70ef6c895e4d2d95325887fee7d62e"><td class="cellrowborder" valign="top" width="14.96149614961496%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001173324611_a23e0317cfee94650be4dcd2280c3e94e"><a name="zh-cn_topic_0000001173324611_a23e0317cfee94650be4dcd2280c3e94e"></a><a name="zh-cn_topic_0000001173324611_a23e0317cfee94650be4dcd2280c3e94e"></a>touchmove</p>
</td>
<td class="cellrowborder" valign="top" width="20.242024202420243%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001173324611_aea26e4f9575044dc8fb65080f3a6684a"><a name="zh-cn_topic_0000001173324611_aea26e4f9575044dc8fb65080f3a6684a"></a><a name="zh-cn_topic_0000001173324611_aea26e4f9575044dc8fb65080f3a6684a"></a><a href="#zh-cn_topic_0000001173324611_tdb541af4e4db41d7a92e9b6e3c93f606">TouchEvent</a></p>
</td>
<td class="cellrowborder" valign="top" width="45.34453445344535%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001173324611_a37f7cc43d82c4ee18512bd079349079d"><a name="zh-cn_topic_0000001173324611_a37f7cc43d82c4ee18512bd079349079d"></a><a name="zh-cn_topic_0000001173324611_a37f7cc43d82c4ee18512bd079349079d"></a>手指触摸屏幕后移动时触发该事件。</p>
</td>
<td class="cellrowborder" valign="top" width="19.451945194519453%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000001173324611_p1694775683010"><a name="zh-cn_topic_0000001173324611_p1694775683010"></a><a name="zh-cn_topic_0000001173324611_p1694775683010"></a>是<sup id="zh-cn_topic_0000001173324611_sup9681141216369"><a name="zh-cn_topic_0000001173324611_sup9681141216369"></a><a name="zh-cn_topic_0000001173324611_sup9681141216369"></a>5+</sup></p>
</td>
</tr>
<tr id="zh-cn_topic_0000001173324611_ra5c278d41f9045ed9d95e13165974bf4"><td class="cellrowborder" valign="top" width="14.96149614961496%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001173324611_ad0728eeac06143bbb4a6fdf1ed5c6d91"><a name="zh-cn_topic_0000001173324611_ad0728eeac06143bbb4a6fdf1ed5c6d91"></a><a name="zh-cn_topic_0000001173324611_ad0728eeac06143bbb4a6fdf1ed5c6d91"></a>touchcancel</p>
</td>
<td class="cellrowborder" valign="top" width="20.242024202420243%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001173324611_a59e2819eae2b4d3e935991b43156347b"><a name="zh-cn_topic_0000001173324611_a59e2819eae2b4d3e935991b43156347b"></a><a name="zh-cn_topic_0000001173324611_a59e2819eae2b4d3e935991b43156347b"></a><a href="#zh-cn_topic_0000001173324611_tdb541af4e4db41d7a92e9b6e3c93f606">TouchEvent</a></p>
</td>
<td class="cellrowborder" valign="top" width="45.34453445344535%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001173324611_a739d9ef0db624f6284554aeaeddffa0a"><a name="zh-cn_topic_0000001173324611_a739d9ef0db624f6284554aeaeddffa0a"></a><a name="zh-cn_topic_0000001173324611_a739d9ef0db624f6284554aeaeddffa0a"></a>手指触摸屏幕中动作被打断时触发该事件。</p>
</td>
<td class="cellrowborder" valign="top" width="19.451945194519453%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000001173324611_p19474565303"><a name="zh-cn_topic_0000001173324611_p19474565303"></a><a name="zh-cn_topic_0000001173324611_p19474565303"></a>是<sup id="zh-cn_topic_0000001173324611_sup1354051315361"><a name="zh-cn_topic_0000001173324611_sup1354051315361"></a><a name="zh-cn_topic_0000001173324611_sup1354051315361"></a>5+</sup></p>
</td>
</tr>
<tr id="zh-cn_topic_0000001173324611_rddfe06969173404d96b60c402a7e783c"><td class="cellrowborder" valign="top" width="14.96149614961496%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001173324611_a233e2f6ff39f49fd97b8f233875d01d4"><a name="zh-cn_topic_0000001173324611_a233e2f6ff39f49fd97b8f233875d01d4"></a><a name="zh-cn_topic_0000001173324611_a233e2f6ff39f49fd97b8f233875d01d4"></a>touchend</p>
</td>
<td class="cellrowborder" valign="top" width="20.242024202420243%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001173324611_a439e69aaf158448e99b3c81cbc9fd624"><a name="zh-cn_topic_0000001173324611_a439e69aaf158448e99b3c81cbc9fd624"></a><a name="zh-cn_topic_0000001173324611_a439e69aaf158448e99b3c81cbc9fd624"></a><a href="#zh-cn_topic_0000001173324611_tdb541af4e4db41d7a92e9b6e3c93f606">TouchEvent</a></p>
</td>
<td class="cellrowborder" valign="top" width="45.34453445344535%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001173324611_a05c0fe4e05ef4154acee8a06ad56a2de"><a name="zh-cn_topic_0000001173324611_a05c0fe4e05ef4154acee8a06ad56a2de"></a><a name="zh-cn_topic_0000001173324611_a05c0fe4e05ef4154acee8a06ad56a2de"></a>手指触摸结束离开屏幕时触发该事件。</p>
</td>
<td class="cellrowborder" valign="top" width="19.451945194519453%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000001173324611_p11947456133011"><a name="zh-cn_topic_0000001173324611_p11947456133011"></a><a name="zh-cn_topic_0000001173324611_p11947456133011"></a>是<sup id="zh-cn_topic_0000001173324611_sup762061414361"><a name="zh-cn_topic_0000001173324611_sup762061414361"></a><a name="zh-cn_topic_0000001173324611_sup762061414361"></a>5+</sup></p>
</td>
</tr>
<tr id="zh-cn_topic_0000001173324611_rec1121b8bebc4a3f9ed9a906d061746e"><td class="cellrowborder" valign="top" width="14.96149614961496%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001173324611_a2fb4de45b1594f6fa1a7da45ce0db57f"><a name="zh-cn_topic_0000001173324611_a2fb4de45b1594f6fa1a7da45ce0db57f"></a><a name="zh-cn_topic_0000001173324611_a2fb4de45b1594f6fa1a7da45ce0db57f"></a>click</p>
</td>
<td class="cellrowborder" valign="top" width="20.242024202420243%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001173324611_af86bf1da40504ed2a8d14213a42536ab"><a name="zh-cn_topic_0000001173324611_af86bf1da40504ed2a8d14213a42536ab"></a><a name="zh-cn_topic_0000001173324611_af86bf1da40504ed2a8d14213a42536ab"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="45.34453445344535%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001173324611_a1d32f00c38c440ddaa63c3f3e01d4e09"><a name="zh-cn_topic_0000001173324611_a1d32f00c38c440ddaa63c3f3e01d4e09"></a><a name="zh-cn_topic_0000001173324611_a1d32f00c38c440ddaa63c3f3e01d4e09"></a>点击动作触发该事件。</p>
</td>
<td class="cellrowborder" valign="top" width="19.451945194519453%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000001173324611_p825613220390"><a name="zh-cn_topic_0000001173324611_p825613220390"></a><a name="zh-cn_topic_0000001173324611_p825613220390"></a>是<sup id="zh-cn_topic_0000001173324611_sup84271359397"><a name="zh-cn_topic_0000001173324611_sup84271359397"></a><a name="zh-cn_topic_0000001173324611_sup84271359397"></a>6+</sup></p>
</td>
</tr>
<tr id="zh-cn_topic_0000001173324611_row2705152317020"><td class="cellrowborder" valign="top" width="14.96149614961496%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001173324611_p1670622317013"><a name="zh-cn_topic_0000001173324611_p1670622317013"></a><a name="zh-cn_topic_0000001173324611_p1670622317013"></a>doubleclick<sup id="zh-cn_topic_0000001173324611_sup898272511424"><a name="zh-cn_topic_0000001173324611_sup898272511424"></a><a name="zh-cn_topic_0000001173324611_sup898272511424"></a><span>7+</span></sup></p>
</td>
<td class="cellrowborder" valign="top" width="20.242024202420243%" headers="mcps1.1.5.1.2 ">&nbsp;&nbsp;</td>
<td class="cellrowborder" valign="top" width="45.34453445344535%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001173324611_p10706723605"><a name="zh-cn_topic_0000001173324611_p10706723605"></a><a name="zh-cn_topic_0000001173324611_p10706723605"></a>双击动作触发该事件</p>
</td>
<td class="cellrowborder" valign="top" width="19.451945194519453%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000001173324611_p1170617231703"><a name="zh-cn_topic_0000001173324611_p1170617231703"></a><a name="zh-cn_topic_0000001173324611_p1170617231703"></a>否</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001173324611_r95f500ef9402487ea42e829d69606f90"><td class="cellrowborder" valign="top" width="14.96149614961496%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001173324611_aa7dc63d1b4924872bbff6a6a100e928f"><a name="zh-cn_topic_0000001173324611_aa7dc63d1b4924872bbff6a6a100e928f"></a><a name="zh-cn_topic_0000001173324611_aa7dc63d1b4924872bbff6a6a100e928f"></a>longpress</p>
</td>
<td class="cellrowborder" valign="top" width="20.242024202420243%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001173324611_a39186f4ff74544d89ace56ea87d9937b"><a name="zh-cn_topic_0000001173324611_a39186f4ff74544d89ace56ea87d9937b"></a><a name="zh-cn_topic_0000001173324611_a39186f4ff74544d89ace56ea87d9937b"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="45.34453445344535%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001173324611_a44b8585170304b5596c41714772e605e"><a name="zh-cn_topic_0000001173324611_a44b8585170304b5596c41714772e605e"></a><a name="zh-cn_topic_0000001173324611_a44b8585170304b5596c41714772e605e"></a>长按动作触发该事件。</p>
</td>
<td class="cellrowborder" valign="top" width="19.451945194519453%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000001173324611_p19655530173713"><a name="zh-cn_topic_0000001173324611_p19655530173713"></a><a name="zh-cn_topic_0000001173324611_p19655530173713"></a>否</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001173324611_row117014569616"><td class="cellrowborder" valign="top" width="14.96149614961496%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001173324611_p12706561061"><a name="zh-cn_topic_0000001173324611_p12706561061"></a><a name="zh-cn_topic_0000001173324611_p12706561061"></a>swipe<sup id="zh-cn_topic_0000001173324611_sup35424382912"><a name="zh-cn_topic_0000001173324611_sup35424382912"></a><a name="zh-cn_topic_0000001173324611_sup35424382912"></a>5+</sup></p>
</td>
<td class="cellrowborder" valign="top" width="20.242024202420243%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001173324611_p11711056161"><a name="zh-cn_topic_0000001173324611_p11711056161"></a><a name="zh-cn_topic_0000001173324611_p11711056161"></a><a href="#zh-cn_topic_0000001173324611_table111811577714">SwipeEvent</a></p>
</td>
<td class="cellrowborder" valign="top" width="45.34453445344535%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001173324611_p2711556162"><a name="zh-cn_topic_0000001173324611_p2711556162"></a><a name="zh-cn_topic_0000001173324611_p2711556162"></a>组件上快速滑动后触发该事件。</p>
</td>
<td class="cellrowborder" valign="top" width="19.451945194519453%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000001173324611_p172818312393"><a name="zh-cn_topic_0000001173324611_p172818312393"></a><a name="zh-cn_topic_0000001173324611_p172818312393"></a>否</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001173324611_row4761236154510"><td class="cellrowborder" valign="top" width="14.96149614961496%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001173324611_p1976143617459"><a name="zh-cn_topic_0000001173324611_p1976143617459"></a><a name="zh-cn_topic_0000001173324611_p1976143617459"></a>attached<sup id="zh-cn_topic_0000001173324611_sup1479243510549"><a name="zh-cn_topic_0000001173324611_sup1479243510549"></a><a name="zh-cn_topic_0000001173324611_sup1479243510549"></a><span>6+</span></sup></p>
</td>
<td class="cellrowborder" valign="top" width="20.242024202420243%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001173324611_p876293613452"><a name="zh-cn_topic_0000001173324611_p876293613452"></a><a name="zh-cn_topic_0000001173324611_p876293613452"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="45.34453445344535%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001173324611_p676263610459"><a name="zh-cn_topic_0000001173324611_p676263610459"></a><a name="zh-cn_topic_0000001173324611_p676263610459"></a>当前组件节点挂载在渲染树后触发。</p>
</td>
<td class="cellrowborder" valign="top" width="19.451945194519453%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000001173324611_p79471756173019"><a name="zh-cn_topic_0000001173324611_p79471756173019"></a><a name="zh-cn_topic_0000001173324611_p79471756173019"></a>否</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001173324611_row37951541194613"><td class="cellrowborder" valign="top" width="14.96149614961496%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001173324611_p12796641204612"><a name="zh-cn_topic_0000001173324611_p12796641204612"></a><a name="zh-cn_topic_0000001173324611_p12796641204612"></a>detached<sup id="zh-cn_topic_0000001173324611_sup18566163910540"><a name="zh-cn_topic_0000001173324611_sup18566163910540"></a><a name="zh-cn_topic_0000001173324611_sup18566163910540"></a><span>6+</span></sup></p>
</td>
<td class="cellrowborder" valign="top" width="20.242024202420243%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001173324611_p177961241154618"><a name="zh-cn_topic_0000001173324611_p177961241154618"></a><a name="zh-cn_topic_0000001173324611_p177961241154618"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="45.34453445344535%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001173324611_p9796124114612"><a name="zh-cn_topic_0000001173324611_p9796124114612"></a><a name="zh-cn_topic_0000001173324611_p9796124114612"></a>当前组件节点从渲染树中移除后触发。</p>
</td>
<td class="cellrowborder" valign="top" width="19.451945194519453%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000001173324611_p2947105614304"><a name="zh-cn_topic_0000001173324611_p2947105614304"></a><a name="zh-cn_topic_0000001173324611_p2947105614304"></a>否</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001173324611_row127781725724"><td class="cellrowborder" valign="top" width="14.96149614961496%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001173324611_p15778202514212"><a name="zh-cn_topic_0000001173324611_p15778202514212"></a><a name="zh-cn_topic_0000001173324611_p15778202514212"></a>pinchstart<sup id="zh-cn_topic_0000001173324611_sup81411323204310"><a name="zh-cn_topic_0000001173324611_sup81411323204310"></a><a name="zh-cn_topic_0000001173324611_sup81411323204310"></a><span>7+</span></sup></p>
</td>
<td class="cellrowborder" valign="top" width="20.242024202420243%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001173324611_p577810251824"><a name="zh-cn_topic_0000001173324611_p577810251824"></a><a name="zh-cn_topic_0000001173324611_p577810251824"></a><a href="#zh-cn_topic_0000001173324611_table1828625919617">PinchEvent</a></p>
</td>
<td class="cellrowborder" valign="top" width="45.34453445344535%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001173324611_p877817251226"><a name="zh-cn_topic_0000001173324611_p877817251226"></a><a name="zh-cn_topic_0000001173324611_p877817251226"></a>手指开始执行捏合操作时触发该事件。</p>
</td>
<td class="cellrowborder" valign="top" width="19.451945194519453%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000001173324611_p57789251323"><a name="zh-cn_topic_0000001173324611_p57789251323"></a><a name="zh-cn_topic_0000001173324611_p57789251323"></a>否</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001173324611_row192314391432"><td class="cellrowborder" valign="top" width="14.96149614961496%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001173324611_p69238391334"><a name="zh-cn_topic_0000001173324611_p69238391334"></a><a name="zh-cn_topic_0000001173324611_p69238391334"></a>pinchupdate<sup id="zh-cn_topic_0000001173324611_sup8215182424319"><a name="zh-cn_topic_0000001173324611_sup8215182424319"></a><a name="zh-cn_topic_0000001173324611_sup8215182424319"></a><span>7+</span></sup></p>
</td>
<td class="cellrowborder" valign="top" width="20.242024202420243%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001173324611_p1977416315333"><a name="zh-cn_topic_0000001173324611_p1977416315333"></a><a name="zh-cn_topic_0000001173324611_p1977416315333"></a><a href="#zh-cn_topic_0000001173324611_table1828625919617">PinchEvent</a></p>
</td>
<td class="cellrowborder" valign="top" width="45.34453445344535%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001173324611_p49236391135"><a name="zh-cn_topic_0000001173324611_p49236391135"></a><a name="zh-cn_topic_0000001173324611_p49236391135"></a>手指执行捏合操作过程中触发该事件。</p>
</td>
<td class="cellrowborder" valign="top" width="19.451945194519453%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000001173324611_p149239398315"><a name="zh-cn_topic_0000001173324611_p149239398315"></a><a name="zh-cn_topic_0000001173324611_p149239398315"></a>否</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001173324611_row487617446316"><td class="cellrowborder" valign="top" width="14.96149614961496%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001173324611_p987718441331"><a name="zh-cn_topic_0000001173324611_p987718441331"></a><a name="zh-cn_topic_0000001173324611_p987718441331"></a>pinchend<sup id="zh-cn_topic_0000001173324611_sup678725104315"><a name="zh-cn_topic_0000001173324611_sup678725104315"></a><a name="zh-cn_topic_0000001173324611_sup678725104315"></a><span>7+</span></sup></p>
</td>
<td class="cellrowborder" valign="top" width="20.242024202420243%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001173324611_p3166118193310"><a name="zh-cn_topic_0000001173324611_p3166118193310"></a><a name="zh-cn_topic_0000001173324611_p3166118193310"></a><a href="#zh-cn_topic_0000001173324611_table1828625919617">PinchEvent</a></p>
</td>
<td class="cellrowborder" valign="top" width="45.34453445344535%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001173324611_p1987715441638"><a name="zh-cn_topic_0000001173324611_p1987715441638"></a><a name="zh-cn_topic_0000001173324611_p1987715441638"></a>手指捏合操作结束离开屏幕时触发该事件。</p>
</td>
<td class="cellrowborder" valign="top" width="19.451945194519453%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000001173324611_p14877174410314"><a name="zh-cn_topic_0000001173324611_p14877174410314"></a><a name="zh-cn_topic_0000001173324611_p14877174410314"></a>否</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001173324611_row1930164915319"><td class="cellrowborder" valign="top" width="14.96149614961496%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001173324611_p1893015491132"><a name="zh-cn_topic_0000001173324611_p1893015491132"></a><a name="zh-cn_topic_0000001173324611_p1893015491132"></a>pinchcancel<sup id="zh-cn_topic_0000001173324611_sup1120714269437"><a name="zh-cn_topic_0000001173324611_sup1120714269437"></a><a name="zh-cn_topic_0000001173324611_sup1120714269437"></a><span>7+</span></sup></p>
</td>
<td class="cellrowborder" valign="top" width="20.242024202420243%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001173324611_p1056161218334"><a name="zh-cn_topic_0000001173324611_p1056161218334"></a><a name="zh-cn_topic_0000001173324611_p1056161218334"></a><a href="#zh-cn_topic_0000001173324611_table1828625919617">PinchEvent</a></p>
</td>
<td class="cellrowborder" valign="top" width="45.34453445344535%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001173324611_p1993034918316"><a name="zh-cn_topic_0000001173324611_p1993034918316"></a><a name="zh-cn_topic_0000001173324611_p1993034918316"></a>手指捏合操作被打断时触发该事件。</p>
</td>
<td class="cellrowborder" valign="top" width="19.451945194519453%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000001173324611_p15930114916314"><a name="zh-cn_topic_0000001173324611_p15930114916314"></a><a name="zh-cn_topic_0000001173324611_p15930114916314"></a>否</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001173324611_row134184458269"><td class="cellrowborder" valign="top" width="14.96149614961496%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001173324611_p16418184552612"><a name="zh-cn_topic_0000001173324611_p16418184552612"></a><a name="zh-cn_topic_0000001173324611_p16418184552612"></a>dragstart<sup id="zh-cn_topic_0000001173324611_sup1640611844620"><a name="zh-cn_topic_0000001173324611_sup1640611844620"></a><a name="zh-cn_topic_0000001173324611_sup1640611844620"></a><span>7+</span></sup></p>
</td>
<td class="cellrowborder" valign="top" width="20.242024202420243%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001173324611_p14418124562610"><a name="zh-cn_topic_0000001173324611_p14418124562610"></a><a name="zh-cn_topic_0000001173324611_p14418124562610"></a><a href="#zh-cn_topic_0000001173324611_table95551461358">DragEvent</a></p>
</td>
<td class="cellrowborder" valign="top" width="45.34453445344535%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001173324611_p1341894592614"><a name="zh-cn_topic_0000001173324611_p1341894592614"></a><a name="zh-cn_topic_0000001173324611_p1341894592614"></a>用户开始拖拽时触发该事件。</p>
</td>
<td class="cellrowborder" valign="top" width="19.451945194519453%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000001173324611_p1341811451268"><a name="zh-cn_topic_0000001173324611_p1341811451268"></a><a name="zh-cn_topic_0000001173324611_p1341811451268"></a>否</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001173324611_row195941786134"><td class="cellrowborder" valign="top" width="14.96149614961496%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001173324611_p6151151019134"><a name="zh-cn_topic_0000001173324611_p6151151019134"></a><a name="zh-cn_topic_0000001173324611_p6151151019134"></a>drag<sup id="zh-cn_topic_0000001173324611_sup317711477125"><a name="zh-cn_topic_0000001173324611_sup317711477125"></a><a name="zh-cn_topic_0000001173324611_sup317711477125"></a><span>7+</span></sup></p>
</td>
<td class="cellrowborder" valign="top" width="20.242024202420243%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001173324611_p1151110191313"><a name="zh-cn_topic_0000001173324611_p1151110191313"></a><a name="zh-cn_topic_0000001173324611_p1151110191313"></a><a href="#zh-cn_topic_0000001173324611_table95551461358">DragEvent</a></p>
</td>
<td class="cellrowborder" valign="top" width="45.34453445344535%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001173324611_p915141041313"><a name="zh-cn_topic_0000001173324611_p915141041313"></a><a name="zh-cn_topic_0000001173324611_p915141041313"></a>拖拽过程中触发该事件。</p>
</td>
<td class="cellrowborder" valign="top" width="19.451945194519453%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000001173324611_p1815112102131"><a name="zh-cn_topic_0000001173324611_p1815112102131"></a><a name="zh-cn_topic_0000001173324611_p1815112102131"></a>否</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001173324611_row343314310509"><td class="cellrowborder" valign="top" width="14.96149614961496%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001173324611_p243393145013"><a name="zh-cn_topic_0000001173324611_p243393145013"></a><a name="zh-cn_topic_0000001173324611_p243393145013"></a>dragend<sup id="zh-cn_topic_0000001173324611_sup1016615910463"><a name="zh-cn_topic_0000001173324611_sup1016615910463"></a><a name="zh-cn_topic_0000001173324611_sup1016615910463"></a><span>7+</span></sup></p>
</td>
<td class="cellrowborder" valign="top" width="20.242024202420243%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001173324611_p94331834504"><a name="zh-cn_topic_0000001173324611_p94331834504"></a><a name="zh-cn_topic_0000001173324611_p94331834504"></a><a href="#zh-cn_topic_0000001173324611_table95551461358">DragEvent</a></p>
</td>
<td class="cellrowborder" valign="top" width="45.34453445344535%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001173324611_p143310312509"><a name="zh-cn_topic_0000001173324611_p143310312509"></a><a name="zh-cn_topic_0000001173324611_p143310312509"></a>用户拖拽完成后触发。</p>
</td>
<td class="cellrowborder" valign="top" width="19.451945194519453%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000001173324611_p194331833500"><a name="zh-cn_topic_0000001173324611_p194331833500"></a><a name="zh-cn_topic_0000001173324611_p194331833500"></a>否</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001173324611_row129701428135013"><td class="cellrowborder" valign="top" width="14.96149614961496%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001173324611_p3970152810505"><a name="zh-cn_topic_0000001173324611_p3970152810505"></a><a name="zh-cn_topic_0000001173324611_p3970152810505"></a>dragenter<sup id="zh-cn_topic_0000001173324611_sup685614917463"><a name="zh-cn_topic_0000001173324611_sup685614917463"></a><a name="zh-cn_topic_0000001173324611_sup685614917463"></a><span>7+</span></sup></p>
</td>
<td class="cellrowborder" valign="top" width="20.242024202420243%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001173324611_p697082875015"><a name="zh-cn_topic_0000001173324611_p697082875015"></a><a name="zh-cn_topic_0000001173324611_p697082875015"></a><a href="#zh-cn_topic_0000001173324611_table95551461358">DragEvent</a></p>
</td>
<td class="cellrowborder" valign="top" width="45.34453445344535%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001173324611_p79702028125013"><a name="zh-cn_topic_0000001173324611_p79702028125013"></a><a name="zh-cn_topic_0000001173324611_p79702028125013"></a>进入释放目标时触发该事件。</p>
</td>
<td class="cellrowborder" valign="top" width="19.451945194519453%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000001173324611_p1297011285502"><a name="zh-cn_topic_0000001173324611_p1297011285502"></a><a name="zh-cn_topic_0000001173324611_p1297011285502"></a>否</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001173324611_row139802344501"><td class="cellrowborder" valign="top" width="14.96149614961496%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001173324611_p1798473495020"><a name="zh-cn_topic_0000001173324611_p1798473495020"></a><a name="zh-cn_topic_0000001173324611_p1798473495020"></a>dragover<sup id="zh-cn_topic_0000001173324611_sup166541210204610"><a name="zh-cn_topic_0000001173324611_sup166541210204610"></a><a name="zh-cn_topic_0000001173324611_sup166541210204610"></a><span>7+</span></sup></p>
</td>
<td class="cellrowborder" valign="top" width="20.242024202420243%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001173324611_p1598793419509"><a name="zh-cn_topic_0000001173324611_p1598793419509"></a><a name="zh-cn_topic_0000001173324611_p1598793419509"></a><a href="#zh-cn_topic_0000001173324611_table95551461358">DragEvent</a></p>
</td>
<td class="cellrowborder" valign="top" width="45.34453445344535%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001173324611_p8987163414509"><a name="zh-cn_topic_0000001173324611_p8987163414509"></a><a name="zh-cn_topic_0000001173324611_p8987163414509"></a>在释放目标内拖动时触发。</p>
</td>
<td class="cellrowborder" valign="top" width="19.451945194519453%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000001173324611_p19987103405015"><a name="zh-cn_topic_0000001173324611_p19987103405015"></a><a name="zh-cn_topic_0000001173324611_p19987103405015"></a>否</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001173324611_row833215394509"><td class="cellrowborder" valign="top" width="14.96149614961496%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001173324611_p633512393503"><a name="zh-cn_topic_0000001173324611_p633512393503"></a><a name="zh-cn_topic_0000001173324611_p633512393503"></a>dragleave<sup id="zh-cn_topic_0000001173324611_sup18549201194615"><a name="zh-cn_topic_0000001173324611_sup18549201194615"></a><a name="zh-cn_topic_0000001173324611_sup18549201194615"></a><span>7+</span></sup></p>
</td>
<td class="cellrowborder" valign="top" width="20.242024202420243%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001173324611_p18335153913504"><a name="zh-cn_topic_0000001173324611_p18335153913504"></a><a name="zh-cn_topic_0000001173324611_p18335153913504"></a><a href="#zh-cn_topic_0000001173324611_table95551461358">DragEvent</a></p>
</td>
<td class="cellrowborder" valign="top" width="45.34453445344535%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001173324611_p8335173910503"><a name="zh-cn_topic_0000001173324611_p8335173910503"></a><a name="zh-cn_topic_0000001173324611_p8335173910503"></a>离开释放目标区域时触发。</p>
</td>
<td class="cellrowborder" valign="top" width="19.451945194519453%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000001173324611_p10338193915012"><a name="zh-cn_topic_0000001173324611_p10338193915012"></a><a name="zh-cn_topic_0000001173324611_p10338193915012"></a>否</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001173324611_row82701055155015"><td class="cellrowborder" valign="top" width="14.96149614961496%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001173324611_p8270205585018"><a name="zh-cn_topic_0000001173324611_p8270205585018"></a><a name="zh-cn_topic_0000001173324611_p8270205585018"></a>drop<sup id="zh-cn_topic_0000001173324611_sup3324161319467"><a name="zh-cn_topic_0000001173324611_sup3324161319467"></a><a name="zh-cn_topic_0000001173324611_sup3324161319467"></a><span>7+</span></sup></p>
</td>
<td class="cellrowborder" valign="top" width="20.242024202420243%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001173324611_p1627055514502"><a name="zh-cn_topic_0000001173324611_p1627055514502"></a><a name="zh-cn_topic_0000001173324611_p1627055514502"></a><a href="#zh-cn_topic_0000001173324611_table95551461358">DragEvent</a></p>
</td>
<td class="cellrowborder" valign="top" width="45.34453445344535%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001173324611_p162704558509"><a name="zh-cn_topic_0000001173324611_p162704558509"></a><a name="zh-cn_topic_0000001173324611_p162704558509"></a>在可释放目标区域内释放时触发。</p>
</td>
<td class="cellrowborder" valign="top" width="19.451945194519453%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000001173324611_p127065585014"><a name="zh-cn_topic_0000001173324611_p127065585014"></a><a name="zh-cn_topic_0000001173324611_p127065585014"></a>否</p>
</td>
</tr>
</tbody>
</table>

>![](../../public_sys-resources/icon-note.gif) **说明：** 
>-   除上述事件外，其他事件均为非冒泡事件，如[input的change事件](js-components-basic-input.md#zh-cn_topic_0000001173324647_section1721512551218)，详见各个组件。

**表 1**  BaseEvent对象属性列表

<a name="zh-cn_topic_0000001173324611_t4afe3a7d9546429ca1113ff78333d1c5"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001173324611_r17b57a5916254b538712224afce3ec93"><th class="cellrowborder" valign="top" width="17.169999999999998%" id="mcps1.2.4.1.1"><p id="zh-cn_topic_0000001173324611_a85fa8e3227fc48a2b8bc9c953327ae36"><a name="zh-cn_topic_0000001173324611_a85fa8e3227fc48a2b8bc9c953327ae36"></a><a name="zh-cn_topic_0000001173324611_a85fa8e3227fc48a2b8bc9c953327ae36"></a>属性</p>
</th>
<th class="cellrowborder" valign="top" width="14.14%" id="mcps1.2.4.1.2"><p id="zh-cn_topic_0000001173324611_aae0028a39da64592bc9e3de357419d3b"><a name="zh-cn_topic_0000001173324611_aae0028a39da64592bc9e3de357419d3b"></a><a name="zh-cn_topic_0000001173324611_aae0028a39da64592bc9e3de357419d3b"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="68.69%" id="mcps1.2.4.1.3"><p id="zh-cn_topic_0000001173324611_a84e596443d8d4e80ab2d990e87e19d0a"><a name="zh-cn_topic_0000001173324611_a84e596443d8d4e80ab2d990e87e19d0a"></a><a name="zh-cn_topic_0000001173324611_a84e596443d8d4e80ab2d990e87e19d0a"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001173324611_ref9724a78ebd4f959cc159def567a6e5"><td class="cellrowborder" valign="top" width="17.169999999999998%" headers="mcps1.2.4.1.1 "><p id="zh-cn_topic_0000001173324611_a8e318c4332dd44cda62259cd5018bc7c"><a name="zh-cn_topic_0000001173324611_a8e318c4332dd44cda62259cd5018bc7c"></a><a name="zh-cn_topic_0000001173324611_a8e318c4332dd44cda62259cd5018bc7c"></a>type</p>
</td>
<td class="cellrowborder" valign="top" width="14.14%" headers="mcps1.2.4.1.2 "><p id="zh-cn_topic_0000001173324611_a567269320f1c43b3984e231f61130431"><a name="zh-cn_topic_0000001173324611_a567269320f1c43b3984e231f61130431"></a><a name="zh-cn_topic_0000001173324611_a567269320f1c43b3984e231f61130431"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="68.69%" headers="mcps1.2.4.1.3 "><p id="zh-cn_topic_0000001173324611_a732751a8a4114815953f940529086cc4"><a name="zh-cn_topic_0000001173324611_a732751a8a4114815953f940529086cc4"></a><a name="zh-cn_topic_0000001173324611_a732751a8a4114815953f940529086cc4"></a>当前事件的类型，比如click、longpress等。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001173324611_rc5890121a2e14421be07b897d2c04995"><td class="cellrowborder" valign="top" width="17.169999999999998%" headers="mcps1.2.4.1.1 "><p id="zh-cn_topic_0000001173324611_a8f15a7cee90e48ac80b09f0f3ba1bc3a"><a name="zh-cn_topic_0000001173324611_a8f15a7cee90e48ac80b09f0f3ba1bc3a"></a><a name="zh-cn_topic_0000001173324611_a8f15a7cee90e48ac80b09f0f3ba1bc3a"></a>timestamp</p>
</td>
<td class="cellrowborder" valign="top" width="14.14%" headers="mcps1.2.4.1.2 "><p id="zh-cn_topic_0000001173324611_a257a70e6a33d481e8c32f4551d33f6e4"><a name="zh-cn_topic_0000001173324611_a257a70e6a33d481e8c32f4551d33f6e4"></a><a name="zh-cn_topic_0000001173324611_a257a70e6a33d481e8c32f4551d33f6e4"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="68.69%" headers="mcps1.2.4.1.3 "><p id="zh-cn_topic_0000001173324611_a816c5efe2ab2447bbd14dfd91095052c"><a name="zh-cn_topic_0000001173324611_a816c5efe2ab2447bbd14dfd91095052c"></a><a name="zh-cn_topic_0000001173324611_a816c5efe2ab2447bbd14dfd91095052c"></a>该事件触发时的时间戳。</p>
</td>
</tr>
</tbody>
</table>

**表 2**  TouchEvent对象属性列表\(继承BaseEvent\)

<a name="zh-cn_topic_0000001173324611_tdb541af4e4db41d7a92e9b6e3c93f606"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001173324611_rea83e482278e4251975cce4fd873c6bb"><th class="cellrowborder" valign="top" width="19.439999999999998%" id="mcps1.2.4.1.1"><p id="zh-cn_topic_0000001173324611_a82b31036c9c94b3d8a7702523f9b40ec"><a name="zh-cn_topic_0000001173324611_a82b31036c9c94b3d8a7702523f9b40ec"></a><a name="zh-cn_topic_0000001173324611_a82b31036c9c94b3d8a7702523f9b40ec"></a>属性</p>
</th>
<th class="cellrowborder" valign="top" width="20.14%" id="mcps1.2.4.1.2"><p id="zh-cn_topic_0000001173324611_a916c9aa3c32e4903953063bb7424027c"><a name="zh-cn_topic_0000001173324611_a916c9aa3c32e4903953063bb7424027c"></a><a name="zh-cn_topic_0000001173324611_a916c9aa3c32e4903953063bb7424027c"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="60.419999999999995%" id="mcps1.2.4.1.3"><p id="zh-cn_topic_0000001173324611_af9aad173dc2f44f5be69c86fe5537af7"><a name="zh-cn_topic_0000001173324611_af9aad173dc2f44f5be69c86fe5537af7"></a><a name="zh-cn_topic_0000001173324611_af9aad173dc2f44f5be69c86fe5537af7"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001173324611_r2f3c99711cf243c19b359026f2863056"><td class="cellrowborder" valign="top" width="19.439999999999998%" headers="mcps1.2.4.1.1 "><p id="zh-cn_topic_0000001173324611_a660dbbfaf8d349b7921fbe9a0b96574a"><a name="zh-cn_topic_0000001173324611_a660dbbfaf8d349b7921fbe9a0b96574a"></a><a name="zh-cn_topic_0000001173324611_a660dbbfaf8d349b7921fbe9a0b96574a"></a>touches</p>
</td>
<td class="cellrowborder" valign="top" width="20.14%" headers="mcps1.2.4.1.2 "><p id="zh-cn_topic_0000001173324611_aab0506a4edc147beb25866891e5fddcd"><a name="zh-cn_topic_0000001173324611_aab0506a4edc147beb25866891e5fddcd"></a><a name="zh-cn_topic_0000001173324611_aab0506a4edc147beb25866891e5fddcd"></a>Array&lt;TouchInfo&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="60.419999999999995%" headers="mcps1.2.4.1.3 "><p id="zh-cn_topic_0000001173324611_aa3d09d0a55704a6097fb39739436c5db"><a name="zh-cn_topic_0000001173324611_aa3d09d0a55704a6097fb39739436c5db"></a><a name="zh-cn_topic_0000001173324611_aa3d09d0a55704a6097fb39739436c5db"></a>触摸事件时的属性集合，包含屏幕触摸点的信息数组。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001173324611_raad83bde64d9482f8a56c44ae45b3f77"><td class="cellrowborder" valign="top" width="19.439999999999998%" headers="mcps1.2.4.1.1 "><p id="zh-cn_topic_0000001173324611_a7e263f0434c94a16a584943ddde92012"><a name="zh-cn_topic_0000001173324611_a7e263f0434c94a16a584943ddde92012"></a><a name="zh-cn_topic_0000001173324611_a7e263f0434c94a16a584943ddde92012"></a>changedTouches</p>
</td>
<td class="cellrowborder" valign="top" width="20.14%" headers="mcps1.2.4.1.2 "><p id="zh-cn_topic_0000001173324611_a76ffd0f779234ab6a77e808500fca675"><a name="zh-cn_topic_0000001173324611_a76ffd0f779234ab6a77e808500fca675"></a><a name="zh-cn_topic_0000001173324611_a76ffd0f779234ab6a77e808500fca675"></a>Array&lt;TouchInfo&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="60.419999999999995%" headers="mcps1.2.4.1.3 "><p id="zh-cn_topic_0000001173324611_a85eddf1d320641a8b344aaadffe6d49e"><a name="zh-cn_topic_0000001173324611_a85eddf1d320641a8b344aaadffe6d49e"></a><a name="zh-cn_topic_0000001173324611_a85eddf1d320641a8b344aaadffe6d49e"></a>触摸事件时的属性集合，包括产生变化的屏幕触摸点的信息数组。数据格式和touches一样。该属性表示有变化的触摸点，如从无变有，位置变化，从有变无。例如用户手指刚接触屏幕时，touches数组中有数据，但changedTouches无数据。</p>
</td>
</tr>
</tbody>
</table>

**表 3**  TouchInfo

<a name="zh-cn_topic_0000001173324611_tf03fc1fac826405d95028a3b880047b6"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001173324611_rff1c937243f04922b941ec313c0cc858"><th class="cellrowborder" valign="top" width="21.060000000000002%" id="mcps1.2.4.1.1"><p id="zh-cn_topic_0000001173324611_a7f9f203c859c4f2ab2f44035c97cffa7"><a name="zh-cn_topic_0000001173324611_a7f9f203c859c4f2ab2f44035c97cffa7"></a><a name="zh-cn_topic_0000001173324611_a7f9f203c859c4f2ab2f44035c97cffa7"></a>属性</p>
</th>
<th class="cellrowborder" valign="top" width="15.939999999999998%" id="mcps1.2.4.1.2"><p id="zh-cn_topic_0000001173324611_a00de9107caaf46968b7d3a52f0c9718f"><a name="zh-cn_topic_0000001173324611_a00de9107caaf46968b7d3a52f0c9718f"></a><a name="zh-cn_topic_0000001173324611_a00de9107caaf46968b7d3a52f0c9718f"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="63%" id="mcps1.2.4.1.3"><p id="zh-cn_topic_0000001173324611_a3406658ff5084d1aaad3fca32c5d31d6"><a name="zh-cn_topic_0000001173324611_a3406658ff5084d1aaad3fca32c5d31d6"></a><a name="zh-cn_topic_0000001173324611_a3406658ff5084d1aaad3fca32c5d31d6"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001173324611_r19de9fd9501e4d99a3a9232b7fb94c98"><td class="cellrowborder" valign="top" width="21.060000000000002%" headers="mcps1.2.4.1.1 "><p id="zh-cn_topic_0000001173324611_a8653f3e51af34bb78136455652a61cec"><a name="zh-cn_topic_0000001173324611_a8653f3e51af34bb78136455652a61cec"></a><a name="zh-cn_topic_0000001173324611_a8653f3e51af34bb78136455652a61cec"></a>globalX</p>
</td>
<td class="cellrowborder" valign="top" width="15.939999999999998%" headers="mcps1.2.4.1.2 "><p id="zh-cn_topic_0000001173324611_add8c97142b8742f78503909547ebd380"><a name="zh-cn_topic_0000001173324611_add8c97142b8742f78503909547ebd380"></a><a name="zh-cn_topic_0000001173324611_add8c97142b8742f78503909547ebd380"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="63%" headers="mcps1.2.4.1.3 "><p id="zh-cn_topic_0000001173324611_a834cd2553aa7439781eeeddd342329df"><a name="zh-cn_topic_0000001173324611_a834cd2553aa7439781eeeddd342329df"></a><a name="zh-cn_topic_0000001173324611_a834cd2553aa7439781eeeddd342329df"></a>距离屏幕左上角（不包括状态栏）横向距离。屏幕的左上角为原点。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001173324611_rde7a56164c134cd2a1afce437e437211"><td class="cellrowborder" valign="top" width="21.060000000000002%" headers="mcps1.2.4.1.1 "><p id="zh-cn_topic_0000001173324611_aebdebb651e74449fb00e1b9930564eac"><a name="zh-cn_topic_0000001173324611_aebdebb651e74449fb00e1b9930564eac"></a><a name="zh-cn_topic_0000001173324611_aebdebb651e74449fb00e1b9930564eac"></a>globalY</p>
</td>
<td class="cellrowborder" valign="top" width="15.939999999999998%" headers="mcps1.2.4.1.2 "><p id="zh-cn_topic_0000001173324611_a3bcbd4de1a634f3195b525d00f1c9667"><a name="zh-cn_topic_0000001173324611_a3bcbd4de1a634f3195b525d00f1c9667"></a><a name="zh-cn_topic_0000001173324611_a3bcbd4de1a634f3195b525d00f1c9667"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="63%" headers="mcps1.2.4.1.3 "><p id="zh-cn_topic_0000001173324611_a5a1306479f784edf8a5a42f76e2540be"><a name="zh-cn_topic_0000001173324611_a5a1306479f784edf8a5a42f76e2540be"></a><a name="zh-cn_topic_0000001173324611_a5a1306479f784edf8a5a42f76e2540be"></a>距离屏幕左上角（不包括状态栏）纵向距离。屏幕的左上角为原点。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001173324611_r94760564980c470490555043898942f3"><td class="cellrowborder" valign="top" width="21.060000000000002%" headers="mcps1.2.4.1.1 "><p id="zh-cn_topic_0000001173324611_a1a1011d86d0c4149a43d0175e75028c5"><a name="zh-cn_topic_0000001173324611_a1a1011d86d0c4149a43d0175e75028c5"></a><a name="zh-cn_topic_0000001173324611_a1a1011d86d0c4149a43d0175e75028c5"></a>localX</p>
</td>
<td class="cellrowborder" valign="top" width="15.939999999999998%" headers="mcps1.2.4.1.2 "><p id="zh-cn_topic_0000001173324611_a0618e3c91a61456a9a9ad2c23095cca5"><a name="zh-cn_topic_0000001173324611_a0618e3c91a61456a9a9ad2c23095cca5"></a><a name="zh-cn_topic_0000001173324611_a0618e3c91a61456a9a9ad2c23095cca5"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="63%" headers="mcps1.2.4.1.3 "><p id="zh-cn_topic_0000001173324611_ad7268ba243c546af8f93208c427c5340"><a name="zh-cn_topic_0000001173324611_ad7268ba243c546af8f93208c427c5340"></a><a name="zh-cn_topic_0000001173324611_ad7268ba243c546af8f93208c427c5340"></a>距离被触摸组件左上角横向距离。组件的左上角为原点。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001173324611_ra0ea6d13e3224d3fac80631ac8458af7"><td class="cellrowborder" valign="top" width="21.060000000000002%" headers="mcps1.2.4.1.1 "><p id="zh-cn_topic_0000001173324611_ab9af76cc10bf4da49cef6ff3a201ff46"><a name="zh-cn_topic_0000001173324611_ab9af76cc10bf4da49cef6ff3a201ff46"></a><a name="zh-cn_topic_0000001173324611_ab9af76cc10bf4da49cef6ff3a201ff46"></a>localY</p>
</td>
<td class="cellrowborder" valign="top" width="15.939999999999998%" headers="mcps1.2.4.1.2 "><p id="zh-cn_topic_0000001173324611_a7d7052c11197432aa14f39bb4039d7aa"><a name="zh-cn_topic_0000001173324611_a7d7052c11197432aa14f39bb4039d7aa"></a><a name="zh-cn_topic_0000001173324611_a7d7052c11197432aa14f39bb4039d7aa"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="63%" headers="mcps1.2.4.1.3 "><p id="zh-cn_topic_0000001173324611_ae3aa585280c449e5a8fe954711ab56fd"><a name="zh-cn_topic_0000001173324611_ae3aa585280c449e5a8fe954711ab56fd"></a><a name="zh-cn_topic_0000001173324611_ae3aa585280c449e5a8fe954711ab56fd"></a>距离被触摸组件左上角纵向距离。组件的左上角为原点。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001173324611_row199451713154119"><td class="cellrowborder" valign="top" width="21.060000000000002%" headers="mcps1.2.4.1.1 "><p id="zh-cn_topic_0000001173324611_p3369201515412"><a name="zh-cn_topic_0000001173324611_p3369201515412"></a><a name="zh-cn_topic_0000001173324611_p3369201515412"></a>size</p>
</td>
<td class="cellrowborder" valign="top" width="15.939999999999998%" headers="mcps1.2.4.1.2 "><p id="zh-cn_topic_0000001173324611_p14369121514116"><a name="zh-cn_topic_0000001173324611_p14369121514116"></a><a name="zh-cn_topic_0000001173324611_p14369121514116"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="63%" headers="mcps1.2.4.1.3 "><p id="zh-cn_topic_0000001173324611_p336941534115"><a name="zh-cn_topic_0000001173324611_p336941534115"></a><a name="zh-cn_topic_0000001173324611_p336941534115"></a>触摸接触面积。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001173324611_row94487132103"><td class="cellrowborder" valign="top" width="21.060000000000002%" headers="mcps1.2.4.1.1 "><p id="zh-cn_topic_0000001173324611_p5448113101014"><a name="zh-cn_topic_0000001173324611_p5448113101014"></a><a name="zh-cn_topic_0000001173324611_p5448113101014"></a>force<sup id="zh-cn_topic_0000001173324611_sup15558152223315"><a name="zh-cn_topic_0000001173324611_sup15558152223315"></a><a name="zh-cn_topic_0000001173324611_sup15558152223315"></a>6+</sup></p>
</td>
<td class="cellrowborder" valign="top" width="15.939999999999998%" headers="mcps1.2.4.1.2 "><p id="zh-cn_topic_0000001173324611_p1944911319107"><a name="zh-cn_topic_0000001173324611_p1944911319107"></a><a name="zh-cn_topic_0000001173324611_p1944911319107"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="63%" headers="mcps1.2.4.1.3 "><p id="zh-cn_topic_0000001173324611_p204493130105"><a name="zh-cn_topic_0000001173324611_p204493130105"></a><a name="zh-cn_topic_0000001173324611_p204493130105"></a>接触力信息。</p>
</td>
</tr>
</tbody>
</table>

**表 4**  SwipeEvent 基础事件对象属性列表（继承BaseEvent）

<a name="zh-cn_topic_0000001173324611_table111811577714"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001173324611_row1011820575718"><th class="cellrowborder" valign="top" width="27.47274727472747%" id="mcps1.2.4.1.1"><p id="zh-cn_topic_0000001173324611_p81183572071"><a name="zh-cn_topic_0000001173324611_p81183572071"></a><a name="zh-cn_topic_0000001173324611_p81183572071"></a>属性</p>
</th>
<th class="cellrowborder" valign="top" width="27.94279427942794%" id="mcps1.2.4.1.2"><p id="zh-cn_topic_0000001173324611_p0118105719719"><a name="zh-cn_topic_0000001173324611_p0118105719719"></a><a name="zh-cn_topic_0000001173324611_p0118105719719"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="44.58445844584458%" id="mcps1.2.4.1.3"><p id="zh-cn_topic_0000001173324611_p111875717717"><a name="zh-cn_topic_0000001173324611_p111875717717"></a><a name="zh-cn_topic_0000001173324611_p111875717717"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001173324611_row9118257276"><td class="cellrowborder" valign="top" width="27.47274727472747%" headers="mcps1.2.4.1.1 "><p id="zh-cn_topic_0000001173324611_p21198576710"><a name="zh-cn_topic_0000001173324611_p21198576710"></a><a name="zh-cn_topic_0000001173324611_p21198576710"></a>direction</p>
</td>
<td class="cellrowborder" valign="top" width="27.94279427942794%" headers="mcps1.2.4.1.2 "><p id="zh-cn_topic_0000001173324611_p511918578713"><a name="zh-cn_topic_0000001173324611_p511918578713"></a><a name="zh-cn_topic_0000001173324611_p511918578713"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="44.58445844584458%" headers="mcps1.2.4.1.3 "><p id="zh-cn_topic_0000001173324611_p41191257174"><a name="zh-cn_topic_0000001173324611_p41191257174"></a><a name="zh-cn_topic_0000001173324611_p41191257174"></a>滑动方向，可能值有：</p>
<a name="zh-cn_topic_0000001173324611_ol241216371597"></a><a name="zh-cn_topic_0000001173324611_ol241216371597"></a><ol id="zh-cn_topic_0000001173324611_ol241216371597"><li>left：向左滑动；</li><li>right：向右滑动；</li><li>up：向上滑动；</li><li>down：向下滑动。</li></ol>
</td>
</tr>
<tr id="zh-cn_topic_0000001173324611_row204127481117"><td class="cellrowborder" valign="top" width="27.47274727472747%" headers="mcps1.2.4.1.1 "><p id="zh-cn_topic_0000001173324611_p16412194131110"><a name="zh-cn_topic_0000001173324611_p16412194131110"></a><a name="zh-cn_topic_0000001173324611_p16412194131110"></a>distance<sup id="zh-cn_topic_0000001173324611_sup167661149153415"><a name="zh-cn_topic_0000001173324611_sup167661149153415"></a><a name="zh-cn_topic_0000001173324611_sup167661149153415"></a>6+</sup></p>
</td>
<td class="cellrowborder" valign="top" width="27.94279427942794%" headers="mcps1.2.4.1.2 "><p id="zh-cn_topic_0000001173324611_p15412945114"><a name="zh-cn_topic_0000001173324611_p15412945114"></a><a name="zh-cn_topic_0000001173324611_p15412945114"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="44.58445844584458%" headers="mcps1.2.4.1.3 "><p id="zh-cn_topic_0000001173324611_p041344171112"><a name="zh-cn_topic_0000001173324611_p041344171112"></a><a name="zh-cn_topic_0000001173324611_p041344171112"></a>在滑动方向上的滑动距离。</p>
</td>
</tr>
</tbody>
</table>

**表 5**  PinchEvent 对象属性列表<sup>7+</sup>

<a name="zh-cn_topic_0000001173324611_table1828625919617"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001173324611_row1328711598619"><th class="cellrowborder" valign="top" width="27.47274727472747%" id="mcps1.2.4.1.1"><p id="zh-cn_topic_0000001173324611_p1228716594618"><a name="zh-cn_topic_0000001173324611_p1228716594618"></a><a name="zh-cn_topic_0000001173324611_p1228716594618"></a>属性</p>
</th>
<th class="cellrowborder" valign="top" width="27.94279427942794%" id="mcps1.2.4.1.2"><p id="zh-cn_topic_0000001173324611_p72877591666"><a name="zh-cn_topic_0000001173324611_p72877591666"></a><a name="zh-cn_topic_0000001173324611_p72877591666"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="44.58445844584458%" id="mcps1.2.4.1.3"><p id="zh-cn_topic_0000001173324611_p1028713591761"><a name="zh-cn_topic_0000001173324611_p1028713591761"></a><a name="zh-cn_topic_0000001173324611_p1028713591761"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001173324611_row15287185918613"><td class="cellrowborder" valign="top" width="27.47274727472747%" headers="mcps1.2.4.1.1 "><p id="zh-cn_topic_0000001173324611_p6287559764"><a name="zh-cn_topic_0000001173324611_p6287559764"></a><a name="zh-cn_topic_0000001173324611_p6287559764"></a>scale</p>
</td>
<td class="cellrowborder" valign="top" width="27.94279427942794%" headers="mcps1.2.4.1.2 "><p id="zh-cn_topic_0000001173324611_p202871959563"><a name="zh-cn_topic_0000001173324611_p202871959563"></a><a name="zh-cn_topic_0000001173324611_p202871959563"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="44.58445844584458%" headers="mcps1.2.4.1.3 "><p id="zh-cn_topic_0000001173324611_p10884101585"><a name="zh-cn_topic_0000001173324611_p10884101585"></a><a name="zh-cn_topic_0000001173324611_p10884101585"></a>缩放比例</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001173324611_row192234415459"><td class="cellrowborder" valign="top" width="27.47274727472747%" headers="mcps1.2.4.1.1 "><p id="zh-cn_topic_0000001173324611_p17224144111459"><a name="zh-cn_topic_0000001173324611_p17224144111459"></a><a name="zh-cn_topic_0000001173324611_p17224144111459"></a>pinchCenterX</p>
</td>
<td class="cellrowborder" valign="top" width="27.94279427942794%" headers="mcps1.2.4.1.2 "><p id="zh-cn_topic_0000001173324611_p022412411453"><a name="zh-cn_topic_0000001173324611_p022412411453"></a><a name="zh-cn_topic_0000001173324611_p022412411453"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="44.58445844584458%" headers="mcps1.2.4.1.3 "><p id="zh-cn_topic_0000001173324611_p172245414455"><a name="zh-cn_topic_0000001173324611_p172245414455"></a><a name="zh-cn_topic_0000001173324611_p172245414455"></a>捏合中心点X轴坐标，单位px</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001173324611_row435915214512"><td class="cellrowborder" valign="top" width="27.47274727472747%" headers="mcps1.2.4.1.1 "><p id="zh-cn_topic_0000001173324611_p13359165234511"><a name="zh-cn_topic_0000001173324611_p13359165234511"></a><a name="zh-cn_topic_0000001173324611_p13359165234511"></a>pinchCenterY</p>
</td>
<td class="cellrowborder" valign="top" width="27.94279427942794%" headers="mcps1.2.4.1.2 "><p id="zh-cn_topic_0000001173324611_p1135913524456"><a name="zh-cn_topic_0000001173324611_p1135913524456"></a><a name="zh-cn_topic_0000001173324611_p1135913524456"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="44.58445844584458%" headers="mcps1.2.4.1.3 "><p id="zh-cn_topic_0000001173324611_p235975213453"><a name="zh-cn_topic_0000001173324611_p235975213453"></a><a name="zh-cn_topic_0000001173324611_p235975213453"></a>捏合中心点Y轴坐标，单位px</p>
</td>
</tr>
</tbody>
</table>

**表 6**  DragEvent对象属性列表\(继承BaseEvent\)<sup>7+</sup>\(Rich\)

<a name="zh-cn_topic_0000001173324611_table95551461358"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001173324611_row0556746250"><th class="cellrowborder" valign="top" width="17%" id="mcps1.2.4.1.1"><p id="zh-cn_topic_0000001173324611_p1555617466516"><a name="zh-cn_topic_0000001173324611_p1555617466516"></a><a name="zh-cn_topic_0000001173324611_p1555617466516"></a>属性</p>
</th>
<th class="cellrowborder" valign="top" width="20.06%" id="mcps1.2.4.1.2"><p id="zh-cn_topic_0000001173324611_p165561146851"><a name="zh-cn_topic_0000001173324611_p165561146851"></a><a name="zh-cn_topic_0000001173324611_p165561146851"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="62.94%" id="mcps1.2.4.1.3"><p id="zh-cn_topic_0000001173324611_p1155674617514"><a name="zh-cn_topic_0000001173324611_p1155674617514"></a><a name="zh-cn_topic_0000001173324611_p1155674617514"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001173324611_row85567466517"><td class="cellrowborder" valign="top" width="17%" headers="mcps1.2.4.1.1 "><p id="zh-cn_topic_0000001173324611_p125566461257"><a name="zh-cn_topic_0000001173324611_p125566461257"></a><a name="zh-cn_topic_0000001173324611_p125566461257"></a>type</p>
</td>
<td class="cellrowborder" valign="top" width="20.06%" headers="mcps1.2.4.1.2 "><p id="zh-cn_topic_0000001173324611_p055611461551"><a name="zh-cn_topic_0000001173324611_p055611461551"></a><a name="zh-cn_topic_0000001173324611_p055611461551"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="62.94%" headers="mcps1.2.4.1.3 "><p id="zh-cn_topic_0000001173324611_p18556846051"><a name="zh-cn_topic_0000001173324611_p18556846051"></a><a name="zh-cn_topic_0000001173324611_p18556846051"></a>事件名称。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001173324611_row195568463513"><td class="cellrowborder" valign="top" width="17%" headers="mcps1.2.4.1.1 "><p id="zh-cn_topic_0000001173324611_p1255654616515"><a name="zh-cn_topic_0000001173324611_p1255654616515"></a><a name="zh-cn_topic_0000001173324611_p1255654616515"></a>globalX</p>
</td>
<td class="cellrowborder" valign="top" width="20.06%" headers="mcps1.2.4.1.2 "><p id="zh-cn_topic_0000001173324611_p455644618517"><a name="zh-cn_topic_0000001173324611_p455644618517"></a><a name="zh-cn_topic_0000001173324611_p455644618517"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="62.94%" headers="mcps1.2.4.1.3 "><p id="zh-cn_topic_0000001173324611_p135561846957"><a name="zh-cn_topic_0000001173324611_p135561846957"></a><a name="zh-cn_topic_0000001173324611_p135561846957"></a>距离屏幕左上角坐标原点横向距离。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001173324611_row19556144619516"><td class="cellrowborder" valign="top" width="17%" headers="mcps1.2.4.1.1 "><p id="zh-cn_topic_0000001173324611_p755613461156"><a name="zh-cn_topic_0000001173324611_p755613461156"></a><a name="zh-cn_topic_0000001173324611_p755613461156"></a>globalY</p>
</td>
<td class="cellrowborder" valign="top" width="20.06%" headers="mcps1.2.4.1.2 "><p id="zh-cn_topic_0000001173324611_p145563469516"><a name="zh-cn_topic_0000001173324611_p145563469516"></a><a name="zh-cn_topic_0000001173324611_p145563469516"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="62.94%" headers="mcps1.2.4.1.3 "><p id="zh-cn_topic_0000001173324611_p355612467514"><a name="zh-cn_topic_0000001173324611_p355612467514"></a><a name="zh-cn_topic_0000001173324611_p355612467514"></a>距离屏幕左上角坐标原点纵向距离。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001173324611_row1355615461359"><td class="cellrowborder" valign="top" width="17%" headers="mcps1.2.4.1.1 "><p id="zh-cn_topic_0000001173324611_p115561846650"><a name="zh-cn_topic_0000001173324611_p115561846650"></a><a name="zh-cn_topic_0000001173324611_p115561846650"></a>timestamp</p>
</td>
<td class="cellrowborder" valign="top" width="20.06%" headers="mcps1.2.4.1.2 "><p id="zh-cn_topic_0000001173324611_p14557144617513"><a name="zh-cn_topic_0000001173324611_p14557144617513"></a><a name="zh-cn_topic_0000001173324611_p14557144617513"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="62.94%" headers="mcps1.2.4.1.3 "><p id="zh-cn_topic_0000001173324611_p17557194614511"><a name="zh-cn_topic_0000001173324611_p17557194614511"></a><a name="zh-cn_topic_0000001173324611_p17557194614511"></a>时间戳。</p>
</td>
</tr>
</tbody>
</table>

## 事件对象<a name="zh-cn_topic_0000001173324611_section18787165861818"></a>

当组件触发事件后，事件回调函数默认会收到一个事件对象，通过该事件对象可以获取相应的信息。

**target对象：**

<a name="zh-cn_topic_0000001173324611_table1753454616219"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001173324611_row4534124672116"><th class="cellrowborder" valign="top" width="33.33333333333333%" id="mcps1.1.4.1.1"><p id="zh-cn_topic_0000001173324611_p105342462217"><a name="zh-cn_topic_0000001173324611_p105342462217"></a><a name="zh-cn_topic_0000001173324611_p105342462217"></a>属性</p>
</th>
<th class="cellrowborder" valign="top" width="33.33333333333333%" id="mcps1.1.4.1.2"><p id="zh-cn_topic_0000001173324611_p25342466210"><a name="zh-cn_topic_0000001173324611_p25342466210"></a><a name="zh-cn_topic_0000001173324611_p25342466210"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="33.33333333333333%" id="mcps1.1.4.1.3"><p id="zh-cn_topic_0000001173324611_p1353419469216"><a name="zh-cn_topic_0000001173324611_p1353419469216"></a><a name="zh-cn_topic_0000001173324611_p1353419469216"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001173324611_row1753415461213"><td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001173324611_p175344463216"><a name="zh-cn_topic_0000001173324611_p175344463216"></a><a name="zh-cn_topic_0000001173324611_p175344463216"></a>dataSet<sup id="zh-cn_topic_0000001173324611_sup94252412316"><a name="zh-cn_topic_0000001173324611_sup94252412316"></a><a name="zh-cn_topic_0000001173324611_sup94252412316"></a><span>6+</span></sup></p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001173324611_p35341546102111"><a name="zh-cn_topic_0000001173324611_p35341546102111"></a><a name="zh-cn_topic_0000001173324611_p35341546102111"></a>Object</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001173324611_p8534204622111"><a name="zh-cn_topic_0000001173324611_p8534204622111"></a><a name="zh-cn_topic_0000001173324611_p8534204622111"></a><span>组件上通过通用属性设置的</span><a href="js-components-common-attributes.md">data-*</a><span>的自定义属性组成的集合。</span></p>
</td>
</tr>
</tbody>
</table>

**示例：**

```
<!-- xxx.hml -->
<div>
    <div data-a="dataA" data-b="dataB" 
         style="width: 100%; height: 50%; background-color: saddlebrown;"
         @touchstart='touchstartfunc'></div>
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

