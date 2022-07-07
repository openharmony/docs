# DeviceFuncs<a name="ZH-CN_TOPIC_0000001291040568"></a>

## **概述**<a name="section330329847083931"></a>

**所属模块:**

[Display](_display.md)

## **汇总**<a name="section543581263083931"></a>

## Public 属性<a name="pub-attribs"></a>

<a name="table1783335433083931"></a>
<table><thead align="left"><tr id="row2029388410083931"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1265428868083931"><a name="p1265428868083931"></a><a name="p1265428868083931"></a>Public 属性</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p2010420977083931"><a name="p2010420977083931"></a><a name="p2010420977083931"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row2051696041083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p833655095083931"><a name="p833655095083931"></a><a name="p833655095083931"></a>( <strong id="b1256792015231"><a name="b1256792015231"></a><a name="b1256792015231"></a>RegHotPlugCallback</strong> )(HotPlugCallback callback, void *data)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1369183518550"><a name="p1369183518550"></a><a name="p1369183518550"></a>注册热插拔事件回调</p>
</td>
</tr>
<tr id="row1519463501083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2120544641083931"><a name="p2120544641083931"></a><a name="p2120544641083931"></a>( <strong id="b1129720748083931"><a name="b1129720748083931"></a><a name="b1129720748083931"></a>RegDisplayVBlankCallback</strong> )(uint32_t devId, VBlankCallback callback, void *data)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p36917351551"><a name="p36917351551"></a><a name="p36917351551"></a>注册VBlank事件回调。</p>
</td>
</tr>
<tr id="row336105712083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p156743702083931"><a name="p156743702083931"></a><a name="p156743702083931"></a>( <strong id="b1638447729083931"><a name="b1638447729083931"></a><a name="b1638447729083931"></a>RegDisplayRefreshCallback</strong> )(uint32_t devId, RefreshCallback callback, void *data)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1369135175511"><a name="p1369135175511"></a><a name="p1369135175511"></a>刷新请求回调。</p>
</td>
</tr>
<tr id="row1951420207083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2083623373083931"><a name="p2083623373083931"></a><a name="p2083623373083931"></a>( <strong id="b1425376978083931"><a name="b1425376978083931"></a><a name="b1425376978083931"></a>GetDisplayCapability</strong> )(uint32_t devId, <a href="_display_capability.md">DisplayCapability</a> *info)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2069153575511"><a name="p2069153575511"></a><a name="p2069153575511"></a>获取显示设备能力集。</p>
</td>
</tr>
<tr id="row1035250619083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1072306923083931"><a name="p1072306923083931"></a><a name="p1072306923083931"></a>( <strong id="b959339725083931"><a name="b959339725083931"></a><a name="b959339725083931"></a>GetDisplaySupportedModes</strong> )(uint32_t devId, uint32_t *num, <a href="_display_mode_info.md">DisplayModeInfo</a> *modes)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1669535145514"><a name="p1669535145514"></a><a name="p1669535145514"></a>获取显示设备支持的显示模式信息。</p>
</td>
</tr>
<tr id="row1465348770083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1141308078083931"><a name="p1141308078083931"></a><a name="p1141308078083931"></a>( <strong id="b1155634597083931"><a name="b1155634597083931"></a><a name="b1155634597083931"></a>GetDisplayMode</strong> )(uint32_t devId, uint32_t *modeId)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1369735185519"><a name="p1369735185519"></a><a name="p1369735185519"></a>获取显示设备当前的显示模式。</p>
</td>
</tr>
<tr id="row988031461083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1848458269083931"><a name="p1848458269083931"></a><a name="p1848458269083931"></a>( <strong id="b437009079083931"><a name="b437009079083931"></a><a name="b437009079083931"></a>SetDisplayMode</strong> )(uint32_t devId, uint32_t modeId)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1370735185516"><a name="p1370735185516"></a><a name="p1370735185516"></a>设置显示设备的显示模式。</p>
</td>
</tr>
<tr id="row1037851222083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p956995500083931"><a name="p956995500083931"></a><a name="p956995500083931"></a>( <strong id="b261081672083931"><a name="b261081672083931"></a><a name="b261081672083931"></a>GetDisplayPowerStatus</strong> )(uint32_t devId, <a href="_display.md#ga0f3c8af6e9d40730b0d2e0fbbf8e627d">DispPowerStatus</a> *status)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p167083510552"><a name="p167083510552"></a><a name="p167083510552"></a>获取显示设备当前的电源状态。</p>
</td>
</tr>
<tr id="row1699923367083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2033898926083931"><a name="p2033898926083931"></a><a name="p2033898926083931"></a>( <strong id="b1821649511083931"><a name="b1821649511083931"></a><a name="b1821649511083931"></a>SetDisplayPowerStatus</strong> )(uint32_t devId, <a href="_display.md#ga0f3c8af6e9d40730b0d2e0fbbf8e627d">DispPowerStatus</a> status)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p19703354558"><a name="p19703354558"></a><a name="p19703354558"></a>设置显示设备当前的电源状态。</p>
</td>
</tr>
<tr id="row307916829083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p871445935083931"><a name="p871445935083931"></a><a name="p871445935083931"></a>( <strong id="b2043476479083931"><a name="b2043476479083931"></a><a name="b2043476479083931"></a>GetDisplayBacklight</strong> )(uint32_t devId, uint32_t *level)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p770835105513"><a name="p770835105513"></a><a name="p770835105513"></a>获取显示设备当前的背光值。</p>
</td>
</tr>
<tr id="row1077192792083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1245087457083931"><a name="p1245087457083931"></a><a name="p1245087457083931"></a>( <strong id="b685245113083931"><a name="b685245113083931"></a><a name="b685245113083931"></a>SetDisplayBacklight</strong> )(uint32_t devId, uint32_t level)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1170153512556"><a name="p1170153512556"></a><a name="p1170153512556"></a>设置显示设备当前的背光值。</p>
</td>
</tr>
<tr id="row2052012076083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p779520429083931"><a name="p779520429083931"></a><a name="p779520429083931"></a>( <strong id="b1840718796083931"><a name="b1840718796083931"></a><a name="b1840718796083931"></a>GetDisplayProperty</strong> )(uint32_t devId, uint32_t id, uint64_t *value)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p37023517555"><a name="p37023517555"></a><a name="p37023517555"></a>获取显示设备属性值。</p>
</td>
</tr>
<tr id="row577902969083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p114679795083931"><a name="p114679795083931"></a><a name="p114679795083931"></a>( <strong id="b255519819083931"><a name="b255519819083931"></a><a name="b255519819083931"></a>SetDisplayProperty</strong> )(uint32_t devId, uint32_t id, uint64_t value)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p17063511553"><a name="p17063511553"></a><a name="p17063511553"></a>设置显示设备属性值。</p>
</td>
</tr>
<tr id="row1575988655083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p673295446083931"><a name="p673295446083931"></a><a name="p673295446083931"></a>( <strong id="b1472131206083931"><a name="b1472131206083931"></a><a name="b1472131206083931"></a>PrepareDisplayLayers</strong> )(uint32_t devId, bool *needFlushFb)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p37017355554"><a name="p37017355554"></a><a name="p37017355554"></a>显示设备合成前准备</p>
</td>
</tr>
<tr id="row581075577083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1716660985083931"><a name="p1716660985083931"></a><a name="p1716660985083931"></a>( <strong id="b669541731083931"><a name="b669541731083931"></a><a name="b669541731083931"></a>GetDisplayCompChange</strong> )(uint32_t devId, uint32_t *num, uint32_t *Layers, int32_t *type)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p370103510552"><a name="p370103510552"></a><a name="p370103510552"></a>获取显示设备合成类型有变化的layer</p>
</td>
</tr>
<tr id="row315632311083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1430424835083931"><a name="p1430424835083931"></a><a name="p1430424835083931"></a>( <strong id="b531366382083931"><a name="b531366382083931"></a><a name="b531366382083931"></a>SetDisplayClientCrop</strong> )(uint32_t devId, <a href="_i_rect.md">IRect</a> *rect)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p7701935185517"><a name="p7701935185517"></a><a name="p7701935185517"></a>设置显示设备的裁剪区域。</p>
</td>
</tr>
<tr id="row843538242083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p359378403083931"><a name="p359378403083931"></a><a name="p359378403083931"></a>( <strong id="b812927705083931"><a name="b812927705083931"></a><a name="b812927705083931"></a>SetDisplayClientDestRect</strong> )(uint32_t devId, <a href="_i_rect.md">IRect</a> *rect)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p37103515520"><a name="p37103515520"></a><a name="p37103515520"></a>设置显示设备的显示区域。</p>
</td>
</tr>
<tr id="row560585244083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p45889157083931"><a name="p45889157083931"></a><a name="p45889157083931"></a>( <strong id="b1320521958083931"><a name="b1320521958083931"></a><a name="b1320521958083931"></a>SetDisplayClientBuffer</strong> )(uint32_t devId, const BufferHandle *buffer, int32_t fence)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1871113525515"><a name="p1871113525515"></a><a name="p1871113525515"></a>设置显示设备的显示缓存。</p>
</td>
</tr>
<tr id="row246321150083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p279759194083931"><a name="p279759194083931"></a><a name="p279759194083931"></a>( <strong id="b206507088083931"><a name="b206507088083931"></a><a name="b206507088083931"></a>SetDisplayClientDamage</strong> )(uint32_t devId, uint32_t num, <a href="_i_rect.md">IRect</a> *rect)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p6711358555"><a name="p6711358555"></a><a name="p6711358555"></a>设置显示设备的显示脏区</p>
</td>
</tr>
<tr id="row1106629731083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2062128357083931"><a name="p2062128357083931"></a><a name="p2062128357083931"></a>( <strong id="b333659412083931"><a name="b333659412083931"></a><a name="b333659412083931"></a>SetDisplayVsyncEnabled</strong> )(uint32_t devId, bool enabled)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p471123510558"><a name="p471123510558"></a><a name="p471123510558"></a>使能垂直同步信号。</p>
</td>
</tr>
<tr id="row1597398434083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1816347817083931"><a name="p1816347817083931"></a><a name="p1816347817083931"></a>( <strong id="b118737813083931"><a name="b118737813083931"></a><a name="b118737813083931"></a>GetDisplayReleaseFence</strong> )(uint32_t devId, uint32_t *num, uint32_t *layers, int32_t *fences)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p17173555517"><a name="p17173555517"></a><a name="p17173555517"></a>获取显示图层fence。</p>
</td>
</tr>
<tr id="row786125964083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1191580129083931"><a name="p1191580129083931"></a><a name="p1191580129083931"></a>( <strong id="b463689276083931"><a name="b463689276083931"></a><a name="b463689276083931"></a>GetDisplaySupportedColorGamuts</strong> )(uint32_t devId, uint32_t *num, <a href="_display.md#ga7e865f6dbae09a004be2949b473fd7c3">ColorGamut</a> *gamuts)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p37143516550"><a name="p37143516550"></a><a name="p37143516550"></a>获取显示设备支持的色域信息。</p>
</td>
</tr>
<tr id="row1331206077083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1651337569083931"><a name="p1651337569083931"></a><a name="p1651337569083931"></a>( <strong id="b565232993083931"><a name="b565232993083931"></a><a name="b565232993083931"></a>GetDisplayColorGamut</strong> )(uint32_t devId, <a href="_display.md#ga7e865f6dbae09a004be2949b473fd7c3">ColorGamut</a> *gamut)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p371935145520"><a name="p371935145520"></a><a name="p371935145520"></a>获取显示设备当前的色域模式。</p>
</td>
</tr>
<tr id="row1067741767083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p879380104083931"><a name="p879380104083931"></a><a name="p879380104083931"></a>( <strong id="b816774612083931"><a name="b816774612083931"></a><a name="b816774612083931"></a>SetDisplayColorGamut</strong> )(uint32_t devId, <a href="_display.md#ga7e865f6dbae09a004be2949b473fd7c3">ColorGamut</a> gamut)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p8711535185514"><a name="p8711535185514"></a><a name="p8711535185514"></a>设置显示设备当前的色域模式。</p>
</td>
</tr>
<tr id="row411183387083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p41363105083931"><a name="p41363105083931"></a><a name="p41363105083931"></a>( <strong id="b1511096020083931"><a name="b1511096020083931"></a><a name="b1511096020083931"></a>GetDisplayGamutMap</strong> )(uint32_t devId, <a href="_display.md#ga5700b58f1bc340e309a0962101ad7fa4">GamutMap</a> *gamutMap)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1071203545512"><a name="p1071203545512"></a><a name="p1071203545512"></a>获取显示设备当前的色域映射模式。</p>
</td>
</tr>
<tr id="row308323540083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1469588129083931"><a name="p1469588129083931"></a><a name="p1469588129083931"></a>( <strong id="b1796536071083931"><a name="b1796536071083931"></a><a name="b1796536071083931"></a>SetDisplayGamutMap</strong> )(uint32_t devId, <a href="_display.md#ga5700b58f1bc340e309a0962101ad7fa4">GamutMap</a> gamutMap)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p107163517553"><a name="p107163517553"></a><a name="p107163517553"></a>设置显示设备当前的色域映射模式。</p>
</td>
</tr>
<tr id="row119395169083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1510594000083931"><a name="p1510594000083931"></a><a name="p1510594000083931"></a>( <strong id="b4506181511253"><a name="b4506181511253"></a><a name="b4506181511253"></a>SetDisplayColorTransform</strong> )(uint32_t devId, const float *matrix)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p77213565515"><a name="p77213565515"></a><a name="p77213565515"></a>设置显示设备当前的4x4的颜色转换矩阵。</p>
</td>
</tr>
<tr id="row580378745083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p964997338083931"><a name="p964997338083931"></a><a name="p964997338083931"></a>( <strong id="b1962705116083931"><a name="b1962705116083931"></a><a name="b1962705116083931"></a>GetHDRCapabilityInfos</strong> )(uint32_t devId, <a href="_h_d_r_capability.md">HDRCapability</a> *info)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p172193525510"><a name="p172193525510"></a><a name="p172193525510"></a>获取显示设备支持的HDR属性信息。</p>
</td>
</tr>
<tr id="row1964238703083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p465565352083931"><a name="p465565352083931"></a><a name="p465565352083931"></a>( <strong id="b860046396083931"><a name="b860046396083931"></a><a name="b860046396083931"></a>GetSupportedMetadataKey</strong> )(uint32_t devId, uint32_t *num, <a href="_display.md#ga5d7d90acb5c568e62a02b18446f37789">HDRMetadataKey</a> *keys)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p187293555510"><a name="p187293555510"></a><a name="p187293555510"></a>获取显示设备支持的 HDRMetadataKey。</p>
</td>
</tr>
<tr id="row817187140083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p905317431083931"><a name="p905317431083931"></a><a name="p905317431083931"></a>( <strong id="b1786017916083931"><a name="b1786017916083931"></a><a name="b1786017916083931"></a>Commit</strong> )(uint32_t devId, int32_t *fence)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p17213565512"><a name="p17213565512"></a><a name="p17213565512"></a>提交合成送显请求。</p>
</td>
</tr>
<tr id="row618265680083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p484018279083931"><a name="p484018279083931"></a><a name="p484018279083931"></a>( <strong id="b1339920946083931"><a name="b1339920946083931"></a><a name="b1339920946083931"></a>InvokeDisplayCmd</strong> )(uint32_t devId,...)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p372183575517"><a name="p372183575517"></a><a name="p372183575517"></a>调用显示设备命令。</p>
</td>
</tr>
<tr id="row2003918167083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p406681664083931"><a name="p406681664083931"></a><a name="p406681664083931"></a>( <strong id="b1011389338083931"><a name="b1011389338083931"></a><a name="b1011389338083931"></a>CreateVirtualDisplay</strong> )(uint32_t width, uint32_t height, int32_t *format, uint32_t *devId)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p17283545513"><a name="p17283545513"></a><a name="p17283545513"></a>创建虚拟显示设备。</p>
</td>
</tr>
<tr id="row2030132641083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p931967313083931"><a name="p931967313083931"></a><a name="p931967313083931"></a>( <strong id="b1486678751083931"><a name="b1486678751083931"></a><a name="b1486678751083931"></a>DestroyVirtualDisplay</strong> )(uint32_t devId)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p18721035165512"><a name="p18721035165512"></a><a name="p18721035165512"></a>销毁虚拟显示设备。</p>
</td>
</tr>
<tr id="row1805511086083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1008121725083931"><a name="p1008121725083931"></a><a name="p1008121725083931"></a>( <strong id="b691297482083931"><a name="b691297482083931"></a><a name="b691297482083931"></a>SetVirtualDisplayBuffer</strong> )(uint32_t devId, BufferHandle *buffer, int32_t fence)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p775035155513"><a name="p775035155513"></a><a name="p775035155513"></a>设置虚拟屏的输出缓存。</p>
</td>
</tr>
<tr id="row78373644083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p426788436083931"><a name="p426788436083931"></a><a name="p426788436083931"></a>( <strong id="b125655634083931"><a name="b125655634083931"></a><a name="b125655634083931"></a>GetWriteBackFrame</strong> )(uint32_t devId, BufferHandle *buffer, int32_t *fence)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1075173516556"><a name="p1075173516556"></a><a name="p1075173516556"></a>获取显示设备的回写帧。</p>
</td>
</tr>
<tr id="row86848102083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p921529639083931"><a name="p921529639083931"></a><a name="p921529639083931"></a>( <strong id="b608633291083931"><a name="b608633291083931"></a><a name="b608633291083931"></a>CreateWriteBack</strong> )(uint32_t *devId, uint32_t width, uint32_t height, int32_t *format)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p197533585519"><a name="p197533585519"></a><a name="p197533585519"></a>对指定显示设备创建回写点。</p>
</td>
</tr>
<tr id="row258031777083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1220567424083931"><a name="p1220567424083931"></a><a name="p1220567424083931"></a>( <strong id="b2035791031083931"><a name="b2035791031083931"></a><a name="b2035791031083931"></a>DestroyWriteBack</strong> )(uint32_t devId)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p575143555517"><a name="p575143555517"></a><a name="p575143555517"></a>销毁指定显示设备的回写点。</p>
</td>
</tr>
</tbody>
</table>

## **详细描述**<a name="section254697475083931"></a>

显示设备控制接口结构体，定义显示设备控制接口函数指针。

