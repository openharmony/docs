# LayerFuncs<a name="ZH-CN_TOPIC_0000001290721096"></a>

## **概述**<a name="section215564862083932"></a>

**所属模块:**

[Display](_display.md)

## **汇总**<a name="section970230256083932"></a>

## Public 属性<a name="pub-attribs"></a>

<a name="table1474658150083932"></a>
<table><thead align="left"><tr id="row478871078083932"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p116462620083932"><a name="p116462620083932"></a><a name="p116462620083932"></a>Public 属性</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p2146171849083932"><a name="p2146171849083932"></a><a name="p2146171849083932"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row1059200205083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1289623000083932"><a name="p1289623000083932"></a><a name="p1289623000083932"></a>( <a href="_layer_funcs.md#a0641c3b48542646daa80386122bed46a">InitDisplay</a> )(uint32_t devId)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1205758933083932"><a name="p1205758933083932"></a><a name="p1205758933083932"></a>初始化显示设备。 <a href="_layer_funcs.md#a0641c3b48542646daa80386122bed46a">更多...</a></p>
</td>
</tr>
<tr id="row1162792010083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1705651931083932"><a name="p1705651931083932"></a><a name="p1705651931083932"></a>( <a href="_layer_funcs.md#a8d7a715d7d2b4bd5ab0db92c2a1eec93">DeinitDisplay</a> )(uint32_t devId)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p939265598083932"><a name="p939265598083932"></a><a name="p939265598083932"></a>取消初始化显示设备。 <a href="_layer_funcs.md#a8d7a715d7d2b4bd5ab0db92c2a1eec93">更多...</a></p>
</td>
</tr>
<tr id="row1767136014083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1879546871083932"><a name="p1879546871083932"></a><a name="p1879546871083932"></a>( <a href="_layer_funcs.md#aba57e2b79df0e774727d0c07ef90e715">GetDisplayInfo</a> )(uint32_t devId, <a href="_display_info.md">DisplayInfo</a> *dispInfo)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1740108547083932"><a name="p1740108547083932"></a><a name="p1740108547083932"></a>获取显示设备相关信息。 <a href="_layer_funcs.md#aba57e2b79df0e774727d0c07ef90e715">更多...</a></p>
</td>
</tr>
<tr id="row1444177416083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1573177451083932"><a name="p1573177451083932"></a><a name="p1573177451083932"></a>( <a href="_layer_funcs.md#ab75207f00ec3352a042aec6c7981fb68">CreateLayer</a> )(uint32_t devId, const <a href="_layer_info.md">LayerInfo</a> *layerInfo, uint32_t *layerId)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p349628841083932"><a name="p349628841083932"></a><a name="p349628841083932"></a>打开图层。 <a href="_layer_funcs.md#ab75207f00ec3352a042aec6c7981fb68">更多...</a></p>
</td>
</tr>
<tr id="row504859713083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1035618500083932"><a name="p1035618500083932"></a><a name="p1035618500083932"></a>( <a href="_layer_funcs.md#a2e375f75209da329f131b914377e9616">CloseLayer</a> )(uint32_t devId, uint32_t layerId)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p550357464083932"><a name="p550357464083932"></a><a name="p550357464083932"></a>关闭图层。 <a href="_layer_funcs.md#a2e375f75209da329f131b914377e9616">更多...</a></p>
</td>
</tr>
<tr id="row748647574083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2026268043083932"><a name="p2026268043083932"></a><a name="p2026268043083932"></a>( <a href="_layer_funcs.md#aaa5bf7f98e8dc47510a4f26fb38094b6">SetLayerVisible</a> )(uint32_t devId, uint32_t layerId, bool visible)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p832788923083932"><a name="p832788923083932"></a><a name="p832788923083932"></a>设置图层是否可见。 <a href="_layer_funcs.md#aaa5bf7f98e8dc47510a4f26fb38094b6">更多...</a></p>
</td>
</tr>
<tr id="row1795931290083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p27675249083932"><a name="p27675249083932"></a><a name="p27675249083932"></a>( <a href="_layer_funcs.md#a6bbff71bb4f17eb84a4db4857a0b0985">GetLayerVisibleState</a> )(uint32_t devId, uint32_t layerId, bool *visible)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p851349727083932"><a name="p851349727083932"></a><a name="p851349727083932"></a>获取图层是否可见状态。 <a href="_layer_funcs.md#a6bbff71bb4f17eb84a4db4857a0b0985">更多...</a></p>
</td>
</tr>
<tr id="row90378588083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1274224490083932"><a name="p1274224490083932"></a><a name="p1274224490083932"></a>( <a href="_layer_funcs.md#ab58e66b0676b1baa1662c175d43bf219">SetLayerSize</a> )(uint32_t devId, uint32_t layerId, <a href="_i_rect.md">IRect</a> *rect)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2114122267083932"><a name="p2114122267083932"></a><a name="p2114122267083932"></a>设置图层大小。 <a href="_layer_funcs.md#ab58e66b0676b1baa1662c175d43bf219">更多...</a></p>
</td>
</tr>
<tr id="row2089333378083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1221277213083932"><a name="p1221277213083932"></a><a name="p1221277213083932"></a>( <a href="_layer_funcs.md#a56be84be25eba64497b2a842c1f68b26">GetLayerSize</a> )(uint32_t devId, uint32_t layerId, <a href="_i_rect.md">IRect</a> *rect)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1878323422083932"><a name="p1878323422083932"></a><a name="p1878323422083932"></a>获取图层大小。 <a href="_layer_funcs.md#a56be84be25eba64497b2a842c1f68b26">更多...</a></p>
</td>
</tr>
<tr id="row1394404202083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1039775788083932"><a name="p1039775788083932"></a><a name="p1039775788083932"></a>( <a href="_layer_funcs.md#a4f925226529e27678df19423fa6f83ad">SetLayerCrop</a> )(uint32_t devId, uint32_t layerId, <a href="_i_rect.md">IRect</a> *rect)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1855217242083932"><a name="p1855217242083932"></a><a name="p1855217242083932"></a>设置图层裁剪区域。 <a href="_layer_funcs.md#a4f925226529e27678df19423fa6f83ad">更多...</a></p>
</td>
</tr>
<tr id="row364043243083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1967873827083932"><a name="p1967873827083932"></a><a name="p1967873827083932"></a>( <a href="_layer_funcs.md#aa3803c2a6395651d1538ffb62d29733d">SetLayerZorder</a> )(uint32_t devId, uint32_t layerId, uint32_t zorder)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2055582022083932"><a name="p2055582022083932"></a><a name="p2055582022083932"></a>设置图层Z轴次序。 <a href="_layer_funcs.md#aa3803c2a6395651d1538ffb62d29733d">更多...</a></p>
</td>
</tr>
<tr id="row721154954083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p711266333083932"><a name="p711266333083932"></a><a name="p711266333083932"></a>( <a href="_layer_funcs.md#a5644645442e1d6943b55ce0a6a801b8c">GetLayerZorder</a> )(uint32_t devId, uint32_t layerId, uint32_t *zorder)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1502254482083932"><a name="p1502254482083932"></a><a name="p1502254482083932"></a>获取图层Z轴次序。 <a href="_layer_funcs.md#a5644645442e1d6943b55ce0a6a801b8c">更多...</a></p>
</td>
</tr>
<tr id="row2101082603083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1055357067083932"><a name="p1055357067083932"></a><a name="p1055357067083932"></a>( <a href="_layer_funcs.md#a456aa01ca3ffa81d2e49c0a9487f816f">SetLayerPreMulti</a> )(uint32_t devId, uint32_t layerId, bool preMul)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1817284713083932"><a name="p1817284713083932"></a><a name="p1817284713083932"></a>设置图层预乘。 <a href="_layer_funcs.md#a456aa01ca3ffa81d2e49c0a9487f816f">更多...</a></p>
</td>
</tr>
<tr id="row1916959652083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p348501693083932"><a name="p348501693083932"></a><a name="p348501693083932"></a>( <a href="_layer_funcs.md#a4a0e26f8401da1232f03bb37502ff4bd">GetLayerPreMulti</a> )(uint32_t devId, uint32_t layerId, bool *preMul)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p221025818083932"><a name="p221025818083932"></a><a name="p221025818083932"></a>获取图层预乘标识。 <a href="_layer_funcs.md#a4a0e26f8401da1232f03bb37502ff4bd">更多...</a></p>
</td>
</tr>
<tr id="row1903989382083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1224399768083932"><a name="p1224399768083932"></a><a name="p1224399768083932"></a>( <a href="_layer_funcs.md#abb9bea9f251316f7c2bea697de55a139">SetLayerAlpha</a> )(uint32_t devId, uint32_t layerId, <a href="_layer_alpha.md">LayerAlpha</a> *alpha)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2002593261083932"><a name="p2002593261083932"></a><a name="p2002593261083932"></a>设置图层alpha值。 <a href="_layer_funcs.md#abb9bea9f251316f7c2bea697de55a139">更多...</a></p>
</td>
</tr>
<tr id="row516888466083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2122825335083932"><a name="p2122825335083932"></a><a name="p2122825335083932"></a>( <a href="_layer_funcs.md#acf1e01338eeb0fd957f53ed0d2551394">GetLayerAlpha</a> )(uint32_t devId, uint32_t layerId, <a href="_layer_alpha.md">LayerAlpha</a> *alpha)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p484796447083932"><a name="p484796447083932"></a><a name="p484796447083932"></a>获取图层alpha值。 <a href="_layer_funcs.md#acf1e01338eeb0fd957f53ed0d2551394">更多...</a></p>
</td>
</tr>
<tr id="row983977723083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1073936785083932"><a name="p1073936785083932"></a><a name="p1073936785083932"></a>( <a href="_layer_funcs.md#a5701fe1e0e2414de577aa5329bd873c9">SetLayerColorKey</a> )(uint32_t devId, uint32_t layerId, bool enable, uint32_t key)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p697332421083932"><a name="p697332421083932"></a><a name="p697332421083932"></a>设置图层colorkey属性,在图层叠加时使用。 <a href="_layer_funcs.md#a5701fe1e0e2414de577aa5329bd873c9">更多...</a></p>
</td>
</tr>
<tr id="row1190383384083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p391318100083932"><a name="p391318100083932"></a><a name="p391318100083932"></a>( <a href="_layer_funcs.md#aea882232b6279b8be82c45e889187b24">GetLayerColorKey</a> )(uint32_t devId, uint32_t layerId, bool *enable, uint32_t *key)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1308442930083932"><a name="p1308442930083932"></a><a name="p1308442930083932"></a>获取图层colorkey。 <a href="_layer_funcs.md#aea882232b6279b8be82c45e889187b24">更多...</a></p>
</td>
</tr>
<tr id="row836095380083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p631828699083932"><a name="p631828699083932"></a><a name="p631828699083932"></a>( <a href="_layer_funcs.md#a3982c76e093852ef386fc372581be4af">SetLayerPalette</a> )(uint32_t devId, uint32_t layerId, uint32_t *palette, uint32_t len)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1959804005083932"><a name="p1959804005083932"></a><a name="p1959804005083932"></a>设置图层调色板。 <a href="_layer_funcs.md#a3982c76e093852ef386fc372581be4af">更多...</a></p>
</td>
</tr>
<tr id="row2032639779083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p900138241083932"><a name="p900138241083932"></a><a name="p900138241083932"></a>( <a href="_layer_funcs.md#af713bc39e51dc8168c278e2f126bf4e3">GetLayerPalette</a> )(uint32_t devId, uint32_t layerId, uint32_t *palette, uint32_t len)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1848239980083932"><a name="p1848239980083932"></a><a name="p1848239980083932"></a>获取图层调色板。 <a href="_layer_funcs.md#af713bc39e51dc8168c278e2f126bf4e3">更多...</a></p>
</td>
</tr>
<tr id="row841983243083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p16662713083932"><a name="p16662713083932"></a><a name="p16662713083932"></a>( <a href="_layer_funcs.md#a707a6ae5144ee329110822dd8301cb22">SetTransformMode</a> )(uint32_t devId, uint32_t layerId, <a href="_display.md#gaa65f3b21a9a92ff022e435a7304126d2">TransformType</a> type)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p714055972083932"><a name="p714055972083932"></a><a name="p714055972083932"></a>设置图层变换模式，根据不同的场景设置图层的旋转、缩放、移位等。 <a href="_layer_funcs.md#a707a6ae5144ee329110822dd8301cb22">更多...</a></p>
</td>
</tr>
<tr id="row1855812012083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p665934097083932"><a name="p665934097083932"></a><a name="p665934097083932"></a>( <a href="_layer_funcs.md#a46c9750d8615dc874b66ac4b10796b24">SetLayerCompression</a> )(uint32_t devId, uint32_t layerId, int32_t compType)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p518746125083932"><a name="p518746125083932"></a><a name="p518746125083932"></a>设置图层压缩功能 <a href="_layer_funcs.md#a46c9750d8615dc874b66ac4b10796b24">更多...</a></p>
</td>
</tr>
<tr id="row1958953496083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1574605222083932"><a name="p1574605222083932"></a><a name="p1574605222083932"></a>( <a href="_layer_funcs.md#ab0b5855ea4ee5228516303cba84907ce">GetLayerCompression</a> )(uint32_t devId, uint32_t layerId, int32_t *compType)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1242418344083932"><a name="p1242418344083932"></a><a name="p1242418344083932"></a>获取图层压缩功能是否打开。 <a href="_layer_funcs.md#ab0b5855ea4ee5228516303cba84907ce">更多...</a></p>
</td>
</tr>
<tr id="row1986040388083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p810380998083932"><a name="p810380998083932"></a><a name="p810380998083932"></a>( <a href="_layer_funcs.md#a7aa2a7bf4c0aed948c8617adec2d91b6">SetLayerDirtyRegion</a> )(uint32_t devId, uint32_t layerId, <a href="_i_rect.md">IRect</a> *region)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1368896554083932"><a name="p1368896554083932"></a><a name="p1368896554083932"></a>设置图层刷新区域。 <a href="_layer_funcs.md#a7aa2a7bf4c0aed948c8617adec2d91b6">更多...</a></p>
</td>
</tr>
<tr id="row1236266595083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p159245058083932"><a name="p159245058083932"></a><a name="p159245058083932"></a>( <a href="_layer_funcs.md#a40b406f6b4e6a812a36605041e0e81d6">GetLayerBuffer</a> )(uint32_t devId, uint32_t layerId, <a href="_layer_buffer.md">LayerBuffer</a> *buffer)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2093390583083932"><a name="p2093390583083932"></a><a name="p2093390583083932"></a>获取图层的buffer。 <a href="_layer_funcs.md#a40b406f6b4e6a812a36605041e0e81d6">更多...</a></p>
</td>
</tr>
<tr id="row410754380083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p40496695083932"><a name="p40496695083932"></a><a name="p40496695083932"></a>( <a href="_layer_funcs.md#abb480bf2b85e93841c49fdc9800bd1e7">Flush</a> )(uint32_t devId, uint32_t layerId, <a href="_layer_buffer.md">LayerBuffer</a> *buffer)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1144153558083932"><a name="p1144153558083932"></a><a name="p1144153558083932"></a>刷新图层。 <a href="_layer_funcs.md#abb480bf2b85e93841c49fdc9800bd1e7">更多...</a></p>
</td>
</tr>
<tr id="row715780933083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1548578839083932"><a name="p1548578839083932"></a><a name="p1548578839083932"></a>( <a href="_layer_funcs.md#a771d3d43be731540b881ac788c71266b">WaitForVBlank</a> )(uint32_t devId, uint32_t layerId, int32_t timeOut)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1555755655083932"><a name="p1555755655083932"></a><a name="p1555755655083932"></a>实现等待帧消隐期到来功能。 <a href="_layer_funcs.md#a771d3d43be731540b881ac788c71266b">更多...</a></p>
</td>
</tr>
<tr id="row809699076083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1313174598083932"><a name="p1313174598083932"></a><a name="p1313174598083932"></a>( <a href="_layer_funcs.md#a751377d6d1877cd9e878208b94339407">SnapShot</a> )(uint32_t devId, <a href="_layer_buffer.md">LayerBuffer</a> *buffer)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1428807687083932"><a name="p1428807687083932"></a><a name="p1428807687083932"></a>实现抓图功能。 <a href="_layer_funcs.md#a751377d6d1877cd9e878208b94339407">更多...</a></p>
</td>
</tr>
<tr id="row1998801373083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p767744990083932"><a name="p767744990083932"></a><a name="p767744990083932"></a>( <a href="_layer_funcs.md#a36625a6daf8faca55551e1d53e0131e1">SetLayerVisibleRegion</a> )(uint32_t devId, uint32_t layerId, uint32_t num, <a href="_i_rect.md">IRect</a> *rect)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1172532000083932"><a name="p1172532000083932"></a><a name="p1172532000083932"></a>设置一个图层的可见区域 <a href="_layer_funcs.md#a36625a6daf8faca55551e1d53e0131e1">更多...</a></p>
</td>
</tr>
<tr id="row1361785254083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1350039755083932"><a name="p1350039755083932"></a><a name="p1350039755083932"></a>( <a href="_layer_funcs.md#a454c07d73a03b655493329f4b33db987">SetLayerBuffer</a> )(uint32_t devId, uint32_t layerId, const BufferHandle *buffer, int32_t fence)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p906940778083932"><a name="p906940778083932"></a><a name="p906940778083932"></a>设置一个层的缓冲区。 <a href="_layer_funcs.md#a454c07d73a03b655493329f4b33db987">更多...</a></p>
</td>
</tr>
<tr id="row863126602083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p688582431083932"><a name="p688582431083932"></a><a name="p688582431083932"></a>( <a href="_layer_funcs.md#a44befcf5ab6e6631faa9339c96c9ab38">InvokeLayerCmd</a> )(uint32_t devId, uint32_t layerId, uint32_t cmd,...)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1640866171083932"><a name="p1640866171083932"></a><a name="p1640866171083932"></a>扩展接口 <a href="_layer_funcs.md#a44befcf5ab6e6631faa9339c96c9ab38">更多...</a></p>
</td>
</tr>
<tr id="row702017351083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1217939962083932"><a name="p1217939962083932"></a><a name="p1217939962083932"></a>( <a href="_layer_funcs.md#a5b085b5fe8473b2df7e80bea55cbc962">SetLayerCompositionType</a> )(uint32_t devId, uint32_t layerId, <a href="_display.md#gae5d7b642670cf3dc6654131dfa115fe5">CompositionType</a> type)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1111739107083932"><a name="p1111739107083932"></a><a name="p1111739107083932"></a>设置客户端期望的组合类型 <a href="_layer_funcs.md#a5b085b5fe8473b2df7e80bea55cbc962">更多...</a></p>
</td>
</tr>
<tr id="row897166528083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1555444482083932"><a name="p1555444482083932"></a><a name="p1555444482083932"></a>( <a href="_layer_funcs.md#aeb3d30d563393299e16984ebf3cc951e">SetLayerBlendType</a> )(uint32_t devId, uint32_t layerId, <a href="_display.md#gaab1839ed4aab1030dfda801a51e68817">BlendType</a> type)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p227570904083932"><a name="p227570904083932"></a><a name="p227570904083932"></a>设置混合类型 <a href="_layer_funcs.md#aeb3d30d563393299e16984ebf3cc951e">更多...</a></p>
</td>
</tr>
<tr id="row959452168083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2145135155083932"><a name="p2145135155083932"></a><a name="p2145135155083932"></a>( <a href="_layer_funcs.md#a04e994982994090802399d9d60fe18d8">SetLayerColorTransform</a> )(uint32_t devId, uint32_t layerId, const float *matrix)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p570748150083932"><a name="p570748150083932"></a><a name="p570748150083932"></a>设置图层当前的颜色转换矩阵。 <a href="_layer_funcs.md#a04e994982994090802399d9d60fe18d8">更多...</a></p>
</td>
</tr>
<tr id="row1206820764083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p544575082083932"><a name="p544575082083932"></a><a name="p544575082083932"></a>( <a href="_layer_funcs.md#a3f8ae902bbfe26dc2449ac20adbb3c16">SetLayerColorDataSpace</a> )(uint32_t devId, uint32_t layerId, <a href="_display.md#ga00fa6ca1bcfe5949dceaa3a77f8d33cc">ColorDataSpace</a> colorSpace)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p258278228083932"><a name="p258278228083932"></a><a name="p258278228083932"></a>设置图层的颜色数据空间。 <a href="_layer_funcs.md#a3f8ae902bbfe26dc2449ac20adbb3c16">更多...</a></p>
</td>
</tr>
<tr id="row915068718083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p584117777083932"><a name="p584117777083932"></a><a name="p584117777083932"></a>( <a href="_layer_funcs.md#ae960c85c48a9e21631870f42acbcbd62">GetLayerColorDataSpace</a> )(uint32_t devId, uint32_t layerId, <a href="_display.md#ga00fa6ca1bcfe5949dceaa3a77f8d33cc">ColorDataSpace</a> *colorSpace)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2063253085083932"><a name="p2063253085083932"></a><a name="p2063253085083932"></a>获取图层当前的颜色数据空间。 <a href="_layer_funcs.md#ae960c85c48a9e21631870f42acbcbd62">更多...</a></p>
</td>
</tr>
<tr id="row1169754865083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2042439399083932"><a name="p2042439399083932"></a><a name="p2042439399083932"></a>( <a href="_layer_funcs.md#aac35ce1bed6960d799006d5e3d6b4cee">SetLayerMetaData</a> )(uint32_t devId, uint32_t layerId, uint32_t num, const <a href="_h_d_r_meta_data.md">HDRMetaData</a> *metaData)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1484987829083932"><a name="p1484987829083932"></a><a name="p1484987829083932"></a>设置图层的HDRmetaData。 <a href="_layer_funcs.md#aac35ce1bed6960d799006d5e3d6b4cee">更多...</a></p>
</td>
</tr>
<tr id="row1197862581083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1144713773083932"><a name="p1144713773083932"></a><a name="p1144713773083932"></a>( <a href="_layer_funcs.md#a460ae3e58e74470bab506ab7c7cc8606">SetLayerMetaDataSet</a> )(uint32_t devId, uint32_t layerId, <a href="_display.md#ga5d7d90acb5c568e62a02b18446f37789">HDRMetadataKey</a> key, uint32_t num, const uint8_t *metaData)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p609095614083932"><a name="p609095614083932"></a><a name="p609095614083932"></a>设置图层的metaData set。 <a href="_layer_funcs.md#a460ae3e58e74470bab506ab7c7cc8606">更多...</a></p>
</td>
</tr>
<tr id="row1144072406083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1148498644083932"><a name="p1148498644083932"></a><a name="p1148498644083932"></a>( <a href="_layer_funcs.md#a6b46adf8f2ac044681f5ecf7eac93ff3">GetSupportedPresentTimestamp</a> )(uint32_t devId, uint32_t layerId, <a href="_display.md#gabdba71665ea5ba4004ac1a9fbeb505f3">PresentTimestampType</a> *type)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1818637978083932"><a name="p1818637978083932"></a><a name="p1818637978083932"></a>获取图层支持的上屏时间戳类型。 <a href="_layer_funcs.md#a6b46adf8f2ac044681f5ecf7eac93ff3">更多...</a></p>
</td>
</tr>
<tr id="row1302615596083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1111749506083932"><a name="p1111749506083932"></a><a name="p1111749506083932"></a>( <a href="_layer_funcs.md#aa3b942f49fdef9034326dafa5f6de4f0">GetHwPresentTimestamp</a> )(uint32_t devId, uint32_t layerId, <a href="_present_timestamp.md">PresentTimestamp</a> *pts)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p782230778083932"><a name="p782230778083932"></a><a name="p782230778083932"></a>获取图层的上屏时间戳信息。 <a href="_layer_funcs.md#aa3b942f49fdef9034326dafa5f6de4f0">更多...</a></p>
</td>
</tr>
<tr id="row620525628083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1630787103083932"><a name="p1630787103083932"></a><a name="p1630787103083932"></a>( <a href="_layer_funcs.md#a0737f01ec437fc7e7180ad69b7f4dcd1">SetLayerTunnelHandle</a> )(uint32_t devId, uint32_t layerId, ExtDataHandle *handle)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1191315090083932"><a name="p1191315090083932"></a><a name="p1191315090083932"></a>设置图层的tunnel句柄。 <a href="_layer_funcs.md#a0737f01ec437fc7e7180ad69b7f4dcd1">更多...</a></p>
</td>
</tr>
<tr id="row1421373927083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2075533045083932"><a name="p2075533045083932"></a><a name="p2075533045083932"></a>( <a href="_layer_funcs.md#a9f1e8e07ad962046650833298098162a">GetLayerReleaseFence</a> )(uint32_t devId, uint32_t layerId, int32_t *fence)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p422623946083932"><a name="p422623946083932"></a><a name="p422623946083932"></a>获取图层的同步栅栏。 <a href="_layer_funcs.md#a9f1e8e07ad962046650833298098162a">更多...</a></p>
</td>
</tr>
</tbody>
</table>

## **详细描述**<a name="section1293272183083932"></a>

显示图层驱动接口结构体，定义显示图层驱动接口函数指针。

## **类成员变量说明**<a name="section2091640329083932"></a>

## CloseLayer<a name="a2e375f75209da329f131b914377e9616"></a>

```
int32_t(* LayerFuncs::CloseLayer) (uint32_t devId, uint32_t layerId)
```

**描述：**

关闭图层。

在完成显示后，如果不在需要使用图层，调用关闭图层接口关闭图层。

**参数：**

<a name="table1526785483083932"></a>
<table><thead align="left"><tr id="row701071483083932"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p130889368083932"><a name="p130889368083932"></a><a name="p130889368083932"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1653958078083932"><a name="p1653958078083932"></a><a name="p1653958078083932"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row361634619083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1560224929083932p0"><a name="entry1560224929083932p0"></a><a name="entry1560224929083932p0"></a>devId</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry166915568083932p0"><a name="entry166915568083932p0"></a><a name="entry166915568083932p0"></a>输入参数，显示设备ID，用于支持多个显示设备，取值从0开始，0表示第一个设备，最大支持5个设备。</p>
</td>
</tr>
<tr id="row1228903219083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry499354977083932p0"><a name="entry499354977083932p0"></a><a name="entry499354977083932p0"></a>layerId</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1823352770083932p0"><a name="entry1823352770083932p0"></a><a name="entry1823352770083932p0"></a>输入参数，图层ID，图层的唯一标识，根据图层ID操作图层。</p>
</td>
</tr>
</tbody>
</table>

**返回：**

DISPLAY\_SUCCESS 表示执行成功。

其他值表示执行失败，具体错误码查看[DispErrCode](_display.md#ga12a925dadef7573cd74d63d06824f9b0)。

**参见：**

**OpenLayer**

## CreateLayer<a name="ab75207f00ec3352a042aec6c7981fb68"></a>

```
int32_t(* LayerFuncs::CreateLayer) (uint32_t devId, const LayerInfo *layerInfo, uint32_t *layerId)
```

**描述：**

打开图层。

GUI在使用图层时，需要先根据图层信息打开图层，打开图层成功可获得图层ID，根据图层ID使用图层各接口。

**参数：**

<a name="table264384928083932"></a>
<table><thead align="left"><tr id="row550500521083932"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1353948647083932"><a name="p1353948647083932"></a><a name="p1353948647083932"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p964341028083932"><a name="p964341028083932"></a><a name="p964341028083932"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row127958808083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1801445701083932p0"><a name="entry1801445701083932p0"></a><a name="entry1801445701083932p0"></a>devId</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry207361307083932p0"><a name="entry207361307083932p0"></a><a name="entry207361307083932p0"></a>输入参数，显示设备ID，用于支持多个显示设备，取值从0开始，0表示第一个设备，最大支持5个设备。</p>
</td>
</tr>
<tr id="row474050235083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry343554360083932p0"><a name="entry343554360083932p0"></a><a name="entry343554360083932p0"></a>layerInfo</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry2004111121083932p0"><a name="entry2004111121083932p0"></a><a name="entry2004111121083932p0"></a>输入参数，图层信息，上层GUI打开图层时需传递图层信息，包括图层类型，图层大小，像素格式等信息。</p>
</td>
</tr>
<tr id="row622957865083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1303964406083932p0"><a name="entry1303964406083932p0"></a><a name="entry1303964406083932p0"></a>layerId</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1190633530083932p0"><a name="entry1190633530083932p0"></a><a name="entry1190633530083932p0"></a>输入参数，图层ID，打开图层成功后返回给GUI的图层ID，用于标识唯一的图层。</p>
</td>
</tr>
</tbody>
</table>

**返回：**

DISPLAY\_SUCCESS 表示执行成功。

其他值表示执行失败，具体错误码查看[DispErrCode](_display.md#ga12a925dadef7573cd74d63d06824f9b0)。

**参见：**

[CloseLayer](_layer_funcs.md#a2e375f75209da329f131b914377e9616)

## DeinitDisplay<a name="a8d7a715d7d2b4bd5ab0db92c2a1eec93"></a>

```
int32_t(* LayerFuncs::DeinitDisplay) (uint32_t devId)
```

**描述：**

取消初始化显示设备。

**参数：**

<a name="table77433526083932"></a>
<table><thead align="left"><tr id="row544180361083932"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1604522382083932"><a name="p1604522382083932"></a><a name="p1604522382083932"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p2111803430083932"><a name="p2111803430083932"></a><a name="p2111803430083932"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row439398038083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry460280662083932p0"><a name="entry460280662083932p0"></a><a name="entry460280662083932p0"></a>devId</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry723568698083932p0"><a name="entry723568698083932p0"></a><a name="entry723568698083932p0"></a>输入参数，显示设备ID，用于支持多个显示设备，取值从0开始，0表示第一个设备，最大支持5个设备。</p>
</td>
</tr>
</tbody>
</table>

**返回：**

DISPLAY\_SUCCESS 表示执行成功。

其他值表示执行失败，具体错误码查看[DispErrCode](_display.md#ga12a925dadef7573cd74d63d06824f9b0)。

**参见：**

[InitDisplay](_layer_funcs.md#a0641c3b48542646daa80386122bed46a)

## Flush<a name="abb480bf2b85e93841c49fdc9800bd1e7"></a>

```
int32_t(* LayerFuncs::Flush) (uint32_t devId, uint32_t layerId, LayerBuffer *buffer)
```

**描述：**

刷新图层。

将buffer显示数据刷新到指定的layerId图层上，实现图像数据显示到屏幕上。

**参数：**

<a name="table843382957083932"></a>
<table><thead align="left"><tr id="row148740203083932"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1469579882083932"><a name="p1469579882083932"></a><a name="p1469579882083932"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1980981557083932"><a name="p1980981557083932"></a><a name="p1980981557083932"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row1408483028083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1040480086083932p0"><a name="entry1040480086083932p0"></a><a name="entry1040480086083932p0"></a>devId</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1778034626083932p0"><a name="entry1778034626083932p0"></a><a name="entry1778034626083932p0"></a>输入参数，显示设备ID，用于支持多个显示设备，取值从0开始，0表示第一个设备，最大支持5个设备。</p>
</td>
</tr>
<tr id="row974310480083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry279275834083932p0"><a name="entry279275834083932p0"></a><a name="entry279275834083932p0"></a>layerId</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry105856254083932p0"><a name="entry105856254083932p0"></a><a name="entry105856254083932p0"></a>输入参数，图层ID，图层的唯一标识，根据图层ID操作图层。</p>
</td>
</tr>
<tr id="row298074362083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1436491081083932p0"><a name="entry1436491081083932p0"></a><a name="entry1436491081083932p0"></a>buffer</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry409484530083932p0"><a name="entry409484530083932p0"></a><a name="entry409484530083932p0"></a>输出参数，待刷新的buffer。</p>
</td>
</tr>
</tbody>
</table>

**返回：**

DISPLAY\_SUCCESS 表示执行成功。

其他值表示执行失败，具体错误码查看[DispErrCode](_display.md#ga12a925dadef7573cd74d63d06824f9b0)。

## GetDisplayInfo<a name="aba57e2b79df0e774727d0c07ef90e715"></a>

```
int32_t(* LayerFuncs::GetDisplayInfo) (uint32_t devId, DisplayInfo *dispInfo)
```

**描述：**

获取显示设备相关信息。

**参数：**

<a name="table2024808713083932"></a>
<table><thead align="left"><tr id="row225036758083932"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p523801834083932"><a name="p523801834083932"></a><a name="p523801834083932"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1630711476083932"><a name="p1630711476083932"></a><a name="p1630711476083932"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row1534332493083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry793205913083932p0"><a name="entry793205913083932p0"></a><a name="entry793205913083932p0"></a>devId</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1962967598083932p0"><a name="entry1962967598083932p0"></a><a name="entry1962967598083932p0"></a>输入参数，显示设备ID，用于支持多个显示设备，取值从0开始，0表示第一个设备，最大支持5个设备。</p>
</td>
</tr>
<tr id="row457955943083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry910769425083932p0"><a name="entry910769425083932p0"></a><a name="entry910769425083932p0"></a>dispInfo</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry651168896083932p0"><a name="entry651168896083932p0"></a><a name="entry651168896083932p0"></a>输出参数，显示相关信息。</p>
</td>
</tr>
</tbody>
</table>

**返回：**

DISPLAY\_SUCCESS 表示执行成功。

其他值表示执行失败，具体错误码查看[DispErrCode](_display.md#ga12a925dadef7573cd74d63d06824f9b0)。

## GetHwPresentTimestamp<a name="aa3b942f49fdef9034326dafa5f6de4f0"></a>

```
int32_t(* LayerFuncs::GetHwPresentTimestamp) (uint32_t devId, uint32_t layerId, PresentTimestamp *pts)
```

**描述：**

获取图层的上屏时间戳信息。

**参数：**

<a name="table366573849083932"></a>
<table><thead align="left"><tr id="row1712616763083932"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1940025107083932"><a name="p1940025107083932"></a><a name="p1940025107083932"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1012842457083932"><a name="p1012842457083932"></a><a name="p1012842457083932"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row1506401628083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry278925771083932p0"><a name="entry278925771083932p0"></a><a name="entry278925771083932p0"></a>devId</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1144611932083932p0"><a name="entry1144611932083932p0"></a><a name="entry1144611932083932p0"></a>输入参数，指示需要操作的设备ID。</p>
</td>
</tr>
<tr id="row1135808329083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry616559596083932p0"><a name="entry616559596083932p0"></a><a name="entry616559596083932p0"></a>layerId</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry319506398083932p0"><a name="entry319506398083932p0"></a><a name="entry319506398083932p0"></a>输入参数，指示需要操作的图层ID。</p>
</td>
</tr>
<tr id="row333603277083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1669135714083932p0"><a name="entry1669135714083932p0"></a><a name="entry1669135714083932p0"></a>pts</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry742552022083932p0"><a name="entry742552022083932p0"></a><a name="entry742552022083932p0"></a>输出参数，保存图层的上屏时间戳信息, 由接口实现层进行写入。</p>
</td>
</tr>
</tbody>
</table>

**返回：**

DISPLAY\_SUCCESS 表示执行成功。

其他值表示执行失败，具体错误码查看[DispErrCode](_display.md#ga12a925dadef7573cd74d63d06824f9b0)。

## GetLayerAlpha<a name="acf1e01338eeb0fd957f53ed0d2551394"></a>

```
int32_t(* LayerFuncs::GetLayerAlpha) (uint32_t devId, uint32_t layerId, LayerAlpha *alpha)
```

**描述：**

获取图层alpha值。

**参数：**

<a name="table2100623238083932"></a>
<table><thead align="left"><tr id="row1046104559083932"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p37572044083932"><a name="p37572044083932"></a><a name="p37572044083932"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p2086582696083932"><a name="p2086582696083932"></a><a name="p2086582696083932"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row829949943083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry945974153083932p0"><a name="entry945974153083932p0"></a><a name="entry945974153083932p0"></a>devId</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry665544653083932p0"><a name="entry665544653083932p0"></a><a name="entry665544653083932p0"></a>输入参数，显示设备ID，用于支持多个显示设备，取值从0开始，0表示第一个设备，最大支持5个设备。</p>
</td>
</tr>
<tr id="row2106104857083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry655698888083932p0"><a name="entry655698888083932p0"></a><a name="entry655698888083932p0"></a>layerId</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1627415548083932p0"><a name="entry1627415548083932p0"></a><a name="entry1627415548083932p0"></a>输入参数，图层ID，图层的唯一标识，根据图层ID操作图层。</p>
</td>
</tr>
<tr id="row1444182072083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1761170679083932p0"><a name="entry1761170679083932p0"></a><a name="entry1761170679083932p0"></a>alpha</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1478185613083932p0"><a name="entry1478185613083932p0"></a><a name="entry1478185613083932p0"></a>输出参数，保存获取的图层alpha值。</p>
</td>
</tr>
</tbody>
</table>

**返回：**

DISPLAY\_SUCCESS 表示执行成功。

其他值表示执行失败，具体错误码查看[DispErrCode](_display.md#ga12a925dadef7573cd74d63d06824f9b0)。

**参见：**

[SetLayerAlpha](_layer_funcs.md#abb9bea9f251316f7c2bea697de55a139)

## GetLayerBuffer<a name="a40b406f6b4e6a812a36605041e0e81d6"></a>

```
int32_t(* LayerFuncs::GetLayerBuffer) (uint32_t devId, uint32_t layerId, LayerBuffer *buffer)
```

**描述：**

获取图层的buffer。

向buffer中绘图后，调用Flush接口显示到屏幕上。

**参数：**

<a name="table1871842609083932"></a>
<table><thead align="left"><tr id="row2146479588083932"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1787462898083932"><a name="p1787462898083932"></a><a name="p1787462898083932"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1030979277083932"><a name="p1030979277083932"></a><a name="p1030979277083932"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row1372165686083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry2003439572083932p0"><a name="entry2003439572083932p0"></a><a name="entry2003439572083932p0"></a>devId</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry531158845083932p0"><a name="entry531158845083932p0"></a><a name="entry531158845083932p0"></a>输入参数，显示设备ID，用于支持多个显示设备，取值从0开始，0表示第一个设备，最大支持5个设备。</p>
</td>
</tr>
<tr id="row637415930083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry187820476083932p0"><a name="entry187820476083932p0"></a><a name="entry187820476083932p0"></a>layerId</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1015815429083932p0"><a name="entry1015815429083932p0"></a><a name="entry1015815429083932p0"></a>输入参数，图层ID，图层的唯一标识，根据图层ID操作图层。</p>
</td>
</tr>
<tr id="row1817305663083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1887581819083932p0"><a name="entry1887581819083932p0"></a><a name="entry1887581819083932p0"></a>buffer</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry149119921083932p0"><a name="entry149119921083932p0"></a><a name="entry149119921083932p0"></a>输出参数，保存获取的图层buffer。</p>
</td>
</tr>
</tbody>
</table>

**返回：**

DISPLAY\_SUCCESS 表示执行成功。

其他值表示执行失败，具体错误码查看[DispErrCode](_display.md#ga12a925dadef7573cd74d63d06824f9b0)。

**参见：**

[Flush](_layer_funcs.md#abb480bf2b85e93841c49fdc9800bd1e7)

## GetLayerColorDataSpace<a name="ae960c85c48a9e21631870f42acbcbd62"></a>

```
int32_t(* LayerFuncs::GetLayerColorDataSpace) (uint32_t devId, uint32_t layerId, ColorDataSpace *colorSpace)
```

**描述：**

获取图层当前的颜色数据空间。

**参数：**

<a name="table1549422926083932"></a>
<table><thead align="left"><tr id="row1194526906083932"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1690954888083932"><a name="p1690954888083932"></a><a name="p1690954888083932"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p2109303301083932"><a name="p2109303301083932"></a><a name="p2109303301083932"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row1153849289083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1922692118083932p0"><a name="entry1922692118083932p0"></a><a name="entry1922692118083932p0"></a>devId</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry870028082083932p0"><a name="entry870028082083932p0"></a><a name="entry870028082083932p0"></a>输入参数，指示需要操作的设备ID。</p>
</td>
</tr>
<tr id="row2026997623083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1592824439083932p0"><a name="entry1592824439083932p0"></a><a name="entry1592824439083932p0"></a>layerId</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1542882598083932p0"><a name="entry1542882598083932p0"></a><a name="entry1542882598083932p0"></a>输入参数，指示需要操作的图层ID。</p>
</td>
</tr>
<tr id="row1968244656083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry714573978083932p0"><a name="entry714573978083932p0"></a><a name="entry714573978083932p0"></a>colorSpace</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry679089188083932p0"><a name="entry679089188083932p0"></a><a name="entry679089188083932p0"></a>输出参数，保存对应图层的颜色数据空间。</p>
</td>
</tr>
</tbody>
</table>

**返回：**

DISPLAY\_SUCCESS 表示执行成功。

其他值表示执行失败，具体错误码查看[DispErrCode](_display.md#ga12a925dadef7573cd74d63d06824f9b0)。

## GetLayerColorKey<a name="aea882232b6279b8be82c45e889187b24"></a>

```
int32_t(* LayerFuncs::GetLayerColorKey) (uint32_t devId, uint32_t layerId, bool *enable, uint32_t *key)
```

**描述：**

获取图层colorkey。

**参数：**

<a name="table78966371083932"></a>
<table><thead align="left"><tr id="row337191099083932"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p853630907083932"><a name="p853630907083932"></a><a name="p853630907083932"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1748249246083932"><a name="p1748249246083932"></a><a name="p1748249246083932"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row36449845083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1267045428083932p0"><a name="entry1267045428083932p0"></a><a name="entry1267045428083932p0"></a>devId</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry159272558083932p0"><a name="entry159272558083932p0"></a><a name="entry159272558083932p0"></a>输入参数，显示设备ID，用于支持多个显示设备，取值从0开始，0表示第一个设备，最大支持5个设备。</p>
</td>
</tr>
<tr id="row1010047602083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1203912356083932p0"><a name="entry1203912356083932p0"></a><a name="entry1203912356083932p0"></a>layerId</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry940853088083932p0"><a name="entry940853088083932p0"></a><a name="entry940853088083932p0"></a>输入参数，图层ID，图层的唯一标识，根据图层ID操作图层。</p>
</td>
</tr>
<tr id="row1921908925083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry85949891083932p0"><a name="entry85949891083932p0"></a><a name="entry85949891083932p0"></a>enable</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1123350741083932p0"><a name="entry1123350741083932p0"></a><a name="entry1123350741083932p0"></a>输出参数，保存获取的enable色键使能标识。</p>
</td>
</tr>
<tr id="row1047666535083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1908225491083932p0"><a name="entry1908225491083932p0"></a><a name="entry1908225491083932p0"></a>key</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry941968209083932p0"><a name="entry941968209083932p0"></a><a name="entry941968209083932p0"></a>输出参数，保存获取的色键值，即颜色值。</p>
</td>
</tr>
</tbody>
</table>

**返回：**

DISPLAY\_SUCCESS 表示执行成功。

其他值表示执行失败，具体错误码查看[DispErrCode](_display.md#ga12a925dadef7573cd74d63d06824f9b0)。

**参见：**

[SetLayerColorKey](_layer_funcs.md#a5701fe1e0e2414de577aa5329bd873c9)

## GetLayerCompression<a name="ab0b5855ea4ee5228516303cba84907ce"></a>

```
int32_t(* LayerFuncs::GetLayerCompression) (uint32_t devId, uint32_t layerId, int32_t *compType)
```

**描述：**

获取图层压缩功能是否打开。

**参数：**

<a name="table39908355083932"></a>
<table><thead align="left"><tr id="row786874671083932"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1205793732083932"><a name="p1205793732083932"></a><a name="p1205793732083932"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p686927472083932"><a name="p686927472083932"></a><a name="p686927472083932"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row986476912083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry535546487083932p0"><a name="entry535546487083932p0"></a><a name="entry535546487083932p0"></a>devId</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry151458501083932p0"><a name="entry151458501083932p0"></a><a name="entry151458501083932p0"></a>输入参数，显示设备ID，用于支持多个显示设备，取值从0开始，0表示第一个设备，最大支持5个设备。</p>
</td>
</tr>
<tr id="row291534194083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1481237694083932p0"><a name="entry1481237694083932p0"></a><a name="entry1481237694083932p0"></a>layerId</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1950776980083932p0"><a name="entry1950776980083932p0"></a><a name="entry1950776980083932p0"></a>输入参数，图层ID，图层的唯一标识，根据图层ID操作图层。</p>
</td>
</tr>
<tr id="row1910782690083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1376549762083932p0"><a name="entry1376549762083932p0"></a><a name="entry1376549762083932p0"></a>compType</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry160330427083932p0"><a name="entry160330427083932p0"></a><a name="entry160330427083932p0"></a>输出参数，保存获取的图层压缩功能状态。</p>
</td>
</tr>
</tbody>
</table>

**返回：**

DISPLAY\_SUCCESS 表示执行成功。

其他值表示执行失败，具体错误码查看[DispErrCode](_display.md#ga12a925dadef7573cd74d63d06824f9b0)。

**参见：**

[SetLayerCompression](_layer_funcs.md#a46c9750d8615dc874b66ac4b10796b24)

## GetLayerPalette<a name="af713bc39e51dc8168c278e2f126bf4e3"></a>

```
int32_t(* LayerFuncs::GetLayerPalette) (uint32_t devId, uint32_t layerId, uint32_t *palette, uint32_t len)
```

**描述：**

获取图层调色板。

**参数：**

<a name="table1885507800083932"></a>
<table><thead align="left"><tr id="row313959697083932"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1747251088083932"><a name="p1747251088083932"></a><a name="p1747251088083932"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1876670285083932"><a name="p1876670285083932"></a><a name="p1876670285083932"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row1247478338083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry2022225307083932p0"><a name="entry2022225307083932p0"></a><a name="entry2022225307083932p0"></a>devId</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1734947853083932p0"><a name="entry1734947853083932p0"></a><a name="entry1734947853083932p0"></a>输入参数，显示设备ID，用于支持多个显示设备，取值从0开始，0表示第一个设备，最大支持5个设备。</p>
</td>
</tr>
<tr id="row1210791152083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry585360906083932p0"><a name="entry585360906083932p0"></a><a name="entry585360906083932p0"></a>layerId</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1791834836083932p0"><a name="entry1791834836083932p0"></a><a name="entry1791834836083932p0"></a>输入参数，图层ID，图层的唯一标识，根据图层ID操作图层。</p>
</td>
</tr>
<tr id="row1178494239083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1772949120083932p0"><a name="entry1772949120083932p0"></a><a name="entry1772949120083932p0"></a>palette</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry299918883083932p0"><a name="entry299918883083932p0"></a><a name="entry299918883083932p0"></a>输出参数，保存获取的图层调色板。</p>
</td>
</tr>
<tr id="row622537883083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1669316745083932p0"><a name="entry1669316745083932p0"></a><a name="entry1669316745083932p0"></a>len</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1245205782083932p0"><a name="entry1245205782083932p0"></a><a name="entry1245205782083932p0"></a>输入参数，调色板长度。</p>
</td>
</tr>
</tbody>
</table>

**返回：**

DISPLAY\_SUCCESS 表示执行成功。

其他值表示执行失败，具体错误码查看[DispErrCode](_display.md#ga12a925dadef7573cd74d63d06824f9b0)。

**参见：**

[SetLayerPalette](_layer_funcs.md#a3982c76e093852ef386fc372581be4af)

## GetLayerPreMulti<a name="a4a0e26f8401da1232f03bb37502ff4bd"></a>

```
int32_t(* LayerFuncs::GetLayerPreMulti) (uint32_t devId, uint32_t layerId, bool *preMul)
```

**描述：**

获取图层预乘标识。

**参数：**

<a name="table1845167606083932"></a>
<table><thead align="left"><tr id="row299596210083932"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1260325550083932"><a name="p1260325550083932"></a><a name="p1260325550083932"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p568255687083932"><a name="p568255687083932"></a><a name="p568255687083932"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row1071485312083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1769185888083932p0"><a name="entry1769185888083932p0"></a><a name="entry1769185888083932p0"></a>devId</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry301263292083932p0"><a name="entry301263292083932p0"></a><a name="entry301263292083932p0"></a>输入参数，显示设备ID，用于支持多个显示设备，取值从0开始，0表示第一个设备，最大支持5个设备。</p>
</td>
</tr>
<tr id="row920838415083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry995715100083932p0"><a name="entry995715100083932p0"></a><a name="entry995715100083932p0"></a>layerId</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry2123323208083932p0"><a name="entry2123323208083932p0"></a><a name="entry2123323208083932p0"></a>输入参数，图层ID，图层的唯一标识，根据图层ID操作图层。</p>
</td>
</tr>
<tr id="row799908195083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry339661707083932p0"><a name="entry339661707083932p0"></a><a name="entry339661707083932p0"></a>preMul</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1861074446083932p0"><a name="entry1861074446083932p0"></a><a name="entry1861074446083932p0"></a>输出参数，保存获取的图层预乘使能标识。</p>
</td>
</tr>
</tbody>
</table>

**返回：**

DISPLAY\_SUCCESS 表示执行成功。

其他值表示执行失败，具体错误码查看[DispErrCode](_display.md#ga12a925dadef7573cd74d63d06824f9b0)。

**参见：**

[SetLayerPreMulti](_layer_funcs.md#a456aa01ca3ffa81d2e49c0a9487f816f)

## GetLayerReleaseFence<a name="a9f1e8e07ad962046650833298098162a"></a>

```
int32_t(* LayerFuncs::GetLayerReleaseFence) (uint32_t devId, uint32_t layerId, int32_t *fence)
```

**描述：**

获取图层的同步栅栏。

**参数：**

<a name="table436822621083932"></a>
<table><thead align="left"><tr id="row497945220083932"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1511694171083932"><a name="p1511694171083932"></a><a name="p1511694171083932"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p168655727083932"><a name="p168655727083932"></a><a name="p168655727083932"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row1470470848083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry915559768083932p0"><a name="entry915559768083932p0"></a><a name="entry915559768083932p0"></a>devId</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry517750440083932p0"><a name="entry517750440083932p0"></a><a name="entry517750440083932p0"></a>输入参数，指示需要操作的设备ID。</p>
</td>
</tr>
<tr id="row1103652174083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry2044032062083932p0"><a name="entry2044032062083932p0"></a><a name="entry2044032062083932p0"></a>layerId</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1161156007083932p0"><a name="entry1161156007083932p0"></a><a name="entry1161156007083932p0"></a>输入参数，指示需要操作的图层ID。</p>
</td>
</tr>
<tr id="row368296458083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry168397274083932p0"><a name="entry168397274083932p0"></a><a name="entry168397274083932p0"></a>fence</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry261332062083932p0"><a name="entry261332062083932p0"></a><a name="entry261332062083932p0"></a>输出参数，保存图层的 release fence, 由接口实现层进行写入。</p>
</td>
</tr>
</tbody>
</table>

**返回：**

DISPLAY\_SUCCESS 表示执行成功。

其他值表示执行失败，具体错误码查看[DispErrCode](_display.md#ga12a925dadef7573cd74d63d06824f9b0)。

## GetLayerSize<a name="a56be84be25eba64497b2a842c1f68b26"></a>

```
int32_t(* LayerFuncs::GetLayerSize) (uint32_t devId, uint32_t layerId, IRect *rect)
```

**描述：**

获取图层大小。

**参数：**

<a name="table957580327083932"></a>
<table><thead align="left"><tr id="row2139930506083932"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1704324720083932"><a name="p1704324720083932"></a><a name="p1704324720083932"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1190944194083932"><a name="p1190944194083932"></a><a name="p1190944194083932"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row1114841223083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1724213062083932p0"><a name="entry1724213062083932p0"></a><a name="entry1724213062083932p0"></a>devId</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1496809246083932p0"><a name="entry1496809246083932p0"></a><a name="entry1496809246083932p0"></a>输入参数，显示设备ID，用于支持多个显示设备，取值从0开始，0表示第一个设备，最大支持5个设备。</p>
</td>
</tr>
<tr id="row465058190083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry2031446632083932p0"><a name="entry2031446632083932p0"></a><a name="entry2031446632083932p0"></a>layerId</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry566049105083932p0"><a name="entry566049105083932p0"></a><a name="entry566049105083932p0"></a>输入参数，图层ID，图层的唯一标识，根据图层ID操作图层。</p>
</td>
</tr>
<tr id="row696738705083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1113823631083932p0"><a name="entry1113823631083932p0"></a><a name="entry1113823631083932p0"></a>rect</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1772738769083932p0"><a name="entry1772738769083932p0"></a><a name="entry1772738769083932p0"></a>输出参数，保存获取的图层大小。</p>
</td>
</tr>
</tbody>
</table>

**返回：**

DISPLAY\_SUCCESS 表示执行成功。

其他值表示执行失败，具体错误码查看[DispErrCode](_display.md#ga12a925dadef7573cd74d63d06824f9b0)。

**参见：**

[SetLayerSize](_layer_funcs.md#ab58e66b0676b1baa1662c175d43bf219)

## GetLayerVisibleState<a name="a6bbff71bb4f17eb84a4db4857a0b0985"></a>

```
int32_t(* LayerFuncs::GetLayerVisibleState) (uint32_t devId, uint32_t layerId, bool *visible)
```

**描述：**

获取图层是否可见状态。

**参数：**

<a name="table732527683083932"></a>
<table><thead align="left"><tr id="row756922634083932"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1449311481083932"><a name="p1449311481083932"></a><a name="p1449311481083932"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p980801273083932"><a name="p980801273083932"></a><a name="p980801273083932"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row283760288083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry79632474083932p0"><a name="entry79632474083932p0"></a><a name="entry79632474083932p0"></a>devId</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry178501038083932p0"><a name="entry178501038083932p0"></a><a name="entry178501038083932p0"></a>输入参数，显示设备ID，用于支持多个显示设备，取值从0开始，0表示第一个设备，最大支持5个设备。</p>
</td>
</tr>
<tr id="row681611674083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry580340587083932p0"><a name="entry580340587083932p0"></a><a name="entry580340587083932p0"></a>layerId</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1753614641083932p0"><a name="entry1753614641083932p0"></a><a name="entry1753614641083932p0"></a>输入参数，图层ID，图层的唯一标识，根据图层ID操作图层。</p>
</td>
</tr>
<tr id="row1557315090083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry490671566083932p0"><a name="entry490671566083932p0"></a><a name="entry490671566083932p0"></a>visible</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry848738351083932p0"><a name="entry848738351083932p0"></a><a name="entry848738351083932p0"></a>输出参数，保存获取的图层可见状态，true表示图层可见，false表示图层不可见。</p>
</td>
</tr>
</tbody>
</table>

**返回：**

DISPLAY\_SUCCESS 表示执行成功。

其他值表示执行失败，具体错误码查看[DispErrCode](_display.md#ga12a925dadef7573cd74d63d06824f9b0)。

**参见：**

[SetLayerVisible](_layer_funcs.md#aaa5bf7f98e8dc47510a4f26fb38094b6)

## GetLayerZorder<a name="a5644645442e1d6943b55ce0a6a801b8c"></a>

```
int32_t(* LayerFuncs::GetLayerZorder) (uint32_t devId, uint32_t layerId, uint32_t *zorder)
```

**描述：**

获取图层Z轴次序。

**参数：**

<a name="table281205014083932"></a>
<table><thead align="left"><tr id="row1808308695083932"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p38530213083932"><a name="p38530213083932"></a><a name="p38530213083932"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1861425994083932"><a name="p1861425994083932"></a><a name="p1861425994083932"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row1432044319083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry587479989083932p0"><a name="entry587479989083932p0"></a><a name="entry587479989083932p0"></a>devId</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry167587884083932p0"><a name="entry167587884083932p0"></a><a name="entry167587884083932p0"></a>输入参数，显示设备ID，用于支持多个显示设备，取值从0开始，0表示第一个设备，最大支持5个设备。</p>
</td>
</tr>
<tr id="row82477895083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry796203794083932p0"><a name="entry796203794083932p0"></a><a name="entry796203794083932p0"></a>layerId</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1193092795083932p0"><a name="entry1193092795083932p0"></a><a name="entry1193092795083932p0"></a>输入参数，图层ID，图层的唯一标识，根据图层ID操作图层。</p>
</td>
</tr>
<tr id="row269959626083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry384568426083932p0"><a name="entry384568426083932p0"></a><a name="entry384568426083932p0"></a>zorder</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1149671966083932p0"><a name="entry1149671966083932p0"></a><a name="entry1149671966083932p0"></a>输出参数，保存获取的图层Z轴次序，为整数值，取值范围为[0, 255]，值越大图层越往上排列。</p>
</td>
</tr>
</tbody>
</table>

**返回：**

DISPLAY\_SUCCESS 表示执行成功。

其他值表示执行失败，具体错误码查看[DispErrCode](_display.md#ga12a925dadef7573cd74d63d06824f9b0)。

**参见：**

[SetLayerZorder](_layer_funcs.md#aa3803c2a6395651d1538ffb62d29733d)

## GetSupportedPresentTimestamp<a name="a6b46adf8f2ac044681f5ecf7eac93ff3"></a>

```
int32_t(* LayerFuncs::GetSupportedPresentTimestamp) (uint32_t devId, uint32_t layerId, PresentTimestampType *type)
```

**描述：**

获取图层支持的上屏时间戳类型。

**参数：**

<a name="table130012843083932"></a>
<table><thead align="left"><tr id="row1242119029083932"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1311308281083932"><a name="p1311308281083932"></a><a name="p1311308281083932"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1872987683083932"><a name="p1872987683083932"></a><a name="p1872987683083932"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row1868498840083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry473827022083932p0"><a name="entry473827022083932p0"></a><a name="entry473827022083932p0"></a>devId</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1135724712083932p0"><a name="entry1135724712083932p0"></a><a name="entry1135724712083932p0"></a>输入参数，指示需要操作的设备ID。</p>
</td>
</tr>
<tr id="row941686961083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry280080971083932p0"><a name="entry280080971083932p0"></a><a name="entry280080971083932p0"></a>layerId</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry571922977083932p0"><a name="entry571922977083932p0"></a><a name="entry571922977083932p0"></a>输入参数，指示需要操作的图层ID。</p>
</td>
</tr>
<tr id="row264022443083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry348976917083932p0"><a name="entry348976917083932p0"></a><a name="entry348976917083932p0"></a>type</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry26133140083932p0"><a name="entry26133140083932p0"></a><a name="entry26133140083932p0"></a>输出参数，保存图层支持的上屏时间戳类型, 由接口实现层进行写入。</p>
</td>
</tr>
</tbody>
</table>

**返回：**

DISPLAY\_SUCCESS 表示执行成功。

其他值表示执行失败，具体错误码查看[DispErrCode](_display.md#ga12a925dadef7573cd74d63d06824f9b0)。

## InitDisplay<a name="a0641c3b48542646daa80386122bed46a"></a>

```
int32_t(* LayerFuncs::InitDisplay) (uint32_t devId)
```

**描述：**

初始化显示设备。

**参数：**

<a name="table754211141083932"></a>
<table><thead align="left"><tr id="row1916249858083932"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1573114279083932"><a name="p1573114279083932"></a><a name="p1573114279083932"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1558842031083932"><a name="p1558842031083932"></a><a name="p1558842031083932"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row1438327220083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1493755614083932p0"><a name="entry1493755614083932p0"></a><a name="entry1493755614083932p0"></a>devId</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry686384160083932p0"><a name="entry686384160083932p0"></a><a name="entry686384160083932p0"></a>输入参数，显示设备ID，用于支持多个显示设备，取值从0开始，0表示第一个设备，最大支持5个设备。</p>
</td>
</tr>
</tbody>
</table>

**返回：**

DISPLAY\_SUCCESS 表示执行成功。

其他值表示执行失败，具体错误码查看[DispErrCode](_display.md#ga12a925dadef7573cd74d63d06824f9b0)。

**参见：**

[DeinitDisplay](_layer_funcs.md#a8d7a715d7d2b4bd5ab0db92c2a1eec93)

## InvokeLayerCmd<a name="a44befcf5ab6e6631faa9339c96c9ab38"></a>

```
int32_t(* LayerFuncs::InvokeLayerCmd) (uint32_t devId, uint32_t layerId, uint32_t cmd,...)
```

**描述：**

扩展接口

**参数：**

<a name="table1696949659083932"></a>
<table><thead align="left"><tr id="row779548202083932"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p637632352083932"><a name="p637632352083932"></a><a name="p637632352083932"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p491762660083932"><a name="p491762660083932"></a><a name="p491762660083932"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row1520269364083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry976039952083932p0"><a name="entry976039952083932p0"></a><a name="entry976039952083932p0"></a>devId</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry670419412083932p0"><a name="entry670419412083932p0"></a><a name="entry670419412083932p0"></a>输入参数，显示设备的ID。取值范围为0 ~ 4，其中0表示第一个显示设备，4表示最后一个显示设备。</p>
</td>
</tr>
<tr id="row1172719269083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry2134349195083932p0"><a name="entry2134349195083932p0"></a><a name="entry2134349195083932p0"></a>layerId</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry579336623083932p0"><a name="entry579336623083932p0"></a><a name="entry579336623083932p0"></a>输入参数，层ID，唯一标识一个层。可以对该层进行操作。</p>
</td>
</tr>
<tr id="row377167062083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1256461569083932p0"><a name="entry1256461569083932p0"></a><a name="entry1256461569083932p0"></a>cmd</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry408854353083932p0"><a name="entry408854353083932p0"></a><a name="entry408854353083932p0"></a>输入参数，表示扩展cmd，用于识别不同的意图。</p>
</td>
</tr>
</tbody>
</table>

**返回：**

DISPLAY\_SUCCESS 表示执行成功。

其他值表示执行失败，具体错误码查看[DispErrCode](_display.md#ga12a925dadef7573cd74d63d06824f9b0)。

## SetLayerAlpha<a name="abb9bea9f251316f7c2bea697de55a139"></a>

```
int32_t(* LayerFuncs::SetLayerAlpha) (uint32_t devId, uint32_t layerId, LayerAlpha *alpha)
```

**描述：**

设置图层alpha值。

**参数：**

<a name="table1763398829083932"></a>
<table><thead align="left"><tr id="row152435941083932"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1192819418083932"><a name="p1192819418083932"></a><a name="p1192819418083932"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1978940178083932"><a name="p1978940178083932"></a><a name="p1978940178083932"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row1924853442083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry650278700083932p0"><a name="entry650278700083932p0"></a><a name="entry650278700083932p0"></a>devId</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1073228391083932p0"><a name="entry1073228391083932p0"></a><a name="entry1073228391083932p0"></a>输入参数，显示设备ID，用于支持多个显示设备，取值从0开始，0表示第一个设备，最大支持5个设备。</p>
</td>
</tr>
<tr id="row803172573083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry621840917083932p0"><a name="entry621840917083932p0"></a><a name="entry621840917083932p0"></a>layerId</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1237024561083932p0"><a name="entry1237024561083932p0"></a><a name="entry1237024561083932p0"></a>输入参数，图层ID，图层的唯一标识，根据图层ID操作图层。</p>
</td>
</tr>
<tr id="row1012385490083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1314786733083932p0"><a name="entry1314786733083932p0"></a><a name="entry1314786733083932p0"></a>alpha</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1957300701083932p0"><a name="entry1957300701083932p0"></a><a name="entry1957300701083932p0"></a>输入参数，待设置的图层 alpha 值。</p>
</td>
</tr>
</tbody>
</table>

**返回：**

DISPLAY\_SUCCESS 表示执行成功。

其他值表示执行失败，具体错误码查看[DispErrCode](_display.md#ga12a925dadef7573cd74d63d06824f9b0)。

**参见：**

[GetLayerAlpha](_layer_funcs.md#acf1e01338eeb0fd957f53ed0d2551394)

## SetLayerBlendType<a name="aeb3d30d563393299e16984ebf3cc951e"></a>

```
int32_t(* LayerFuncs::SetLayerBlendType) (uint32_t devId, uint32_t layerId, BlendType type)
```

**描述：**

设置混合类型

**参数：**

<a name="table60415956083932"></a>
<table><thead align="left"><tr id="row894206688083932"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p2020018464083932"><a name="p2020018464083932"></a><a name="p2020018464083932"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p316131743083932"><a name="p316131743083932"></a><a name="p316131743083932"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row1435133256083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry2034095447083932p0"><a name="entry2034095447083932p0"></a><a name="entry2034095447083932p0"></a>devId</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1413141743083932p0"><a name="entry1413141743083932p0"></a><a name="entry1413141743083932p0"></a>输入参数，显示设备的ID。取值范围为0 ~ 4，其中0表示第一个显示设备，4表示最后一个显示设备。</p>
</td>
</tr>
<tr id="row1370920391083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1403633330083932p0"><a name="entry1403633330083932p0"></a><a name="entry1403633330083932p0"></a>layerId</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1127879677083932p0"><a name="entry1127879677083932p0"></a><a name="entry1127879677083932p0"></a>输入参数，层ID，唯一标识一个层。可以对该层进行操作。</p>
</td>
</tr>
<tr id="row939907236083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry869143710083932p0"><a name="entry869143710083932p0"></a><a name="entry869143710083932p0"></a>type</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1003701792083932p0"><a name="entry1003701792083932p0"></a><a name="entry1003701792083932p0"></a>输入参数，指示混合类型。</p>
</td>
</tr>
</tbody>
</table>

**返回：**

DISPLAY\_SUCCESS 表示执行成功。

其他值表示执行失败，具体错误码查看[DispErrCode](_display.md#ga12a925dadef7573cd74d63d06824f9b0)。

## SetLayerBuffer<a name="a454c07d73a03b655493329f4b33db987"></a>

```
int32_t(* LayerFuncs::SetLayerBuffer) (uint32_t devId, uint32_t layerId, const BufferHandle *buffer, int32_t fence)
```

**描述：**

设置一个层的缓冲区。

**参数：**

<a name="table842784705083932"></a>
<table><thead align="left"><tr id="row1668199045083932"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1215839272083932"><a name="p1215839272083932"></a><a name="p1215839272083932"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1978979396083932"><a name="p1978979396083932"></a><a name="p1978979396083932"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row152560054083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1519538724083932p0"><a name="entry1519538724083932p0"></a><a name="entry1519538724083932p0"></a>devId</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry372743300083932p0"><a name="entry372743300083932p0"></a><a name="entry372743300083932p0"></a>输入参数，显示设备的ID。取值范围为0 ~ 4，其中0表示第一个显示设备，4表示最后一个显示设备。</p>
</td>
</tr>
<tr id="row1758503152083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1607282890083932p0"><a name="entry1607282890083932p0"></a><a name="entry1607282890083932p0"></a>layerId</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry192709093083932p0"><a name="entry192709093083932p0"></a><a name="entry192709093083932p0"></a>输入参数，层ID，唯一标识一个层。可以对该层进行操作。</p>
</td>
</tr>
<tr id="row1346060344083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry125354552083932p0"><a name="entry125354552083932p0"></a><a name="entry125354552083932p0"></a>buffer</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1036869242083932p0"><a name="entry1036869242083932p0"></a><a name="entry1036869242083932p0"></a>输入参数，指示缓冲区句柄的指针，该指针包含所有用于合成的缓冲区的所有信息。</p>
</td>
</tr>
<tr id="row1985318590083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1052602415083932p0"><a name="entry1052602415083932p0"></a><a name="entry1052602415083932p0"></a>fence</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry837425014083932p0"><a name="entry837425014083932p0"></a><a name="entry837425014083932p0"></a>输入参数，同步文件的fd。</p>
</td>
</tr>
</tbody>
</table>

**返回：**

DISPLAY\_SUCCESS 表示执行成功。

其他值表示执行失败，具体错误码查看[DispErrCode](_display.md#ga12a925dadef7573cd74d63d06824f9b0)。

## SetLayerColorDataSpace<a name="a3f8ae902bbfe26dc2449ac20adbb3c16"></a>

```
int32_t(* LayerFuncs::SetLayerColorDataSpace) (uint32_t devId, uint32_t layerId, ColorDataSpace colorSpace)
```

**描述：**

设置图层的颜色数据空间。

**参数：**

<a name="table1306767978083932"></a>
<table><thead align="left"><tr id="row691881214083932"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p703062508083932"><a name="p703062508083932"></a><a name="p703062508083932"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p633895230083932"><a name="p633895230083932"></a><a name="p633895230083932"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row1023817563083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1533126732083932p0"><a name="entry1533126732083932p0"></a><a name="entry1533126732083932p0"></a>devId</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry239303297083932p0"><a name="entry239303297083932p0"></a><a name="entry239303297083932p0"></a>输入参数，指示需要操作的设备ID。</p>
</td>
</tr>
<tr id="row1418122039083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry327551167083932p0"><a name="entry327551167083932p0"></a><a name="entry327551167083932p0"></a>layerId</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry489364417083932p0"><a name="entry489364417083932p0"></a><a name="entry489364417083932p0"></a>输入参数，指示需要操作的图层ID。</p>
</td>
</tr>
<tr id="row1555452061083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry2112497976083932p0"><a name="entry2112497976083932p0"></a><a name="entry2112497976083932p0"></a>colorSpace</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1956732104083932p0"><a name="entry1956732104083932p0"></a><a name="entry1956732104083932p0"></a>输入参数，表示需要设置的颜色数据空间。</p>
</td>
</tr>
</tbody>
</table>

**返回：**

DISPLAY\_SUCCESS 表示执行成功。

其他值表示执行失败，具体错误码查看[DispErrCode](_display.md#ga12a925dadef7573cd74d63d06824f9b0)。

## SetLayerColorKey<a name="a5701fe1e0e2414de577aa5329bd873c9"></a>

```
int32_t(* LayerFuncs::SetLayerColorKey) (uint32_t devId, uint32_t layerId, bool enable, uint32_t key)
```

**描述：**

设置图层colorkey属性,在图层叠加时使用。

**参数：**

<a name="table1482581337083932"></a>
<table><thead align="left"><tr id="row718233690083932"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p265142793083932"><a name="p265142793083932"></a><a name="p265142793083932"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p214479998083932"><a name="p214479998083932"></a><a name="p214479998083932"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row1605059932083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry378102163083932p0"><a name="entry378102163083932p0"></a><a name="entry378102163083932p0"></a>devId</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry903791510083932p0"><a name="entry903791510083932p0"></a><a name="entry903791510083932p0"></a>输入参数，显示设备ID，用于支持多个显示设备，取值从0开始，0表示第一个设备，最大支持5个设备。</p>
</td>
</tr>
<tr id="row1837276085083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry392913671083932p0"><a name="entry392913671083932p0"></a><a name="entry392913671083932p0"></a>layerId</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry869916439083932p0"><a name="entry869916439083932p0"></a><a name="entry869916439083932p0"></a>输入参数，图层ID，图层的唯一标识，根据图层ID操作图层。</p>
</td>
</tr>
<tr id="row104895721083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry69748374083932p0"><a name="entry69748374083932p0"></a><a name="entry69748374083932p0"></a>enable</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1318267474083932p0"><a name="entry1318267474083932p0"></a><a name="entry1318267474083932p0"></a>输入参数，待设置的色键使能标识。</p>
</td>
</tr>
<tr id="row170720091083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1401066853083932p0"><a name="entry1401066853083932p0"></a><a name="entry1401066853083932p0"></a>key</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry2027681642083932p0"><a name="entry2027681642083932p0"></a><a name="entry2027681642083932p0"></a>输入参数，待设置的色键值，即颜色值。</p>
</td>
</tr>
</tbody>
</table>

**返回：**

DISPLAY\_SUCCESS 表示执行成功。

其他值表示执行失败，具体错误码查看[DispErrCode](_display.md#ga12a925dadef7573cd74d63d06824f9b0)。

**参见：**

[GetLayerColorKey](_layer_funcs.md#aea882232b6279b8be82c45e889187b24)

## SetLayerColorTransform<a name="a04e994982994090802399d9d60fe18d8"></a>

```
int32_t(* LayerFuncs::SetLayerColorTransform) (uint32_t devId, uint32_t layerId, const float *matrix)
```

**描述：**

设置图层当前的颜色转换矩阵。

**参数：**

<a name="table2117832682083932"></a>
<table><thead align="left"><tr id="row1250939191083932"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1831296298083932"><a name="p1831296298083932"></a><a name="p1831296298083932"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1491762241083932"><a name="p1491762241083932"></a><a name="p1491762241083932"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row681423516083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry589220794083932p0"><a name="entry589220794083932p0"></a><a name="entry589220794083932p0"></a>devId</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry41866505083932p0"><a name="entry41866505083932p0"></a><a name="entry41866505083932p0"></a>输入参数，指示需要操作的设备ID。</p>
</td>
</tr>
<tr id="row312790751083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1085574614083932p0"><a name="entry1085574614083932p0"></a><a name="entry1085574614083932p0"></a>layerId</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1736659072083932p0"><a name="entry1736659072083932p0"></a><a name="entry1736659072083932p0"></a>输入参数，指示需要操作的图层ID。</p>
</td>
</tr>
<tr id="row937121054083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry893241807083932p0"><a name="entry893241807083932p0"></a><a name="entry893241807083932p0"></a>matrix</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry915947609083932p0"><a name="entry915947609083932p0"></a><a name="entry915947609083932p0"></a>输入参数，表示需要设置的颜色转换模式。</p>
</td>
</tr>
</tbody>
</table>

**返回：**

DISPLAY\_SUCCESS 表示执行成功。

其他值表示执行失败，具体错误码查看[DispErrCode](_display.md#ga12a925dadef7573cd74d63d06824f9b0)。

## SetLayerCompositionType<a name="a5b085b5fe8473b2df7e80bea55cbc962"></a>

```
int32_t(* LayerFuncs::SetLayerCompositionType) (uint32_t devId, uint32_t layerId, CompositionType type)
```

**描述：**

设置客户端期望的组合类型

**参数：**

<a name="table1288354833083932"></a>
<table><thead align="left"><tr id="row737928403083932"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1659623649083932"><a name="p1659623649083932"></a><a name="p1659623649083932"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1758556440083932"><a name="p1758556440083932"></a><a name="p1758556440083932"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row1836612201083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry247635823083932p0"><a name="entry247635823083932p0"></a><a name="entry247635823083932p0"></a>devId</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry741597508083932p0"><a name="entry741597508083932p0"></a><a name="entry741597508083932p0"></a>输入参数，显示设备的ID。取值范围为0 ~ 4，其中0表示第一个显示设备，4表示最后一个显示设备。</p>
</td>
</tr>
<tr id="row412463959083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry419129583083932p0"><a name="entry419129583083932p0"></a><a name="entry419129583083932p0"></a>layerId</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry446359863083932p0"><a name="entry446359863083932p0"></a><a name="entry446359863083932p0"></a>输入参数，层ID，唯一标识一个层。可以对该层进行操作。</p>
</td>
</tr>
<tr id="row1259473894083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry101482722083932p0"><a name="entry101482722083932p0"></a><a name="entry101482722083932p0"></a>type</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry948290439083932p0"><a name="entry948290439083932p0"></a><a name="entry948290439083932p0"></a>输入参数，指示客户端期望的组合类型。它可能随实现而变化。</p>
</td>
</tr>
</tbody>
</table>

**返回：**

DISPLAY\_SUCCESS 表示执行成功。

其他值表示执行失败，具体错误码查看[DispErrCode](_display.md#ga12a925dadef7573cd74d63d06824f9b0)。

## SetLayerCompression<a name="a46c9750d8615dc874b66ac4b10796b24"></a>

```
int32_t(* LayerFuncs::SetLayerCompression) (uint32_t devId, uint32_t layerId, int32_t compType)
```

**描述：**

设置图层压缩功能

在特定场景下，需要对图像数据进行压缩，可设置启动或关闭图层压缩功能。

**参数：**

<a name="table339247249083932"></a>
<table><thead align="left"><tr id="row690529424083932"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1309570870083932"><a name="p1309570870083932"></a><a name="p1309570870083932"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p364113539083932"><a name="p364113539083932"></a><a name="p364113539083932"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row1172542745083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1328458960083932p0"><a name="entry1328458960083932p0"></a><a name="entry1328458960083932p0"></a>devId</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry267691160083932p0"><a name="entry267691160083932p0"></a><a name="entry267691160083932p0"></a>输入参数，显示设备ID，用于支持多个显示设备，取值从0开始，0表示第一个设备，最大支持5个设备。</p>
</td>
</tr>
<tr id="row1821695234083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1765169651083932p0"><a name="entry1765169651083932p0"></a><a name="entry1765169651083932p0"></a>layerId</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry550544577083932p0"><a name="entry550544577083932p0"></a><a name="entry550544577083932p0"></a>输入参数，图层ID，图层的唯一标识，根据图层ID操作图层。</p>
</td>
</tr>
<tr id="row826549370083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry363714499083932p0"><a name="entry363714499083932p0"></a><a name="entry363714499083932p0"></a>compType</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1791641249083932p0"><a name="entry1791641249083932p0"></a><a name="entry1791641249083932p0"></a>输入参数，图层压缩使能标识。</p>
</td>
</tr>
</tbody>
</table>

**返回：**

DISPLAY\_SUCCESS 表示执行成功。

其他值表示执行失败，具体错误码查看[DispErrCode](_display.md#ga12a925dadef7573cd74d63d06824f9b0)。

**参见：**

[GetLayerCompression](_layer_funcs.md#ab0b5855ea4ee5228516303cba84907ce)

## SetLayerCrop<a name="a4f925226529e27678df19423fa6f83ad"></a>

```
int32_t(* LayerFuncs::SetLayerCrop) (uint32_t devId, uint32_t layerId, IRect *rect)
```

**描述：**

设置图层裁剪区域。

**参数：**

<a name="table229531386083932"></a>
<table><thead align="left"><tr id="row1402042818083932"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1032074624083932"><a name="p1032074624083932"></a><a name="p1032074624083932"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1316939315083932"><a name="p1316939315083932"></a><a name="p1316939315083932"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row863220872083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry168133547083932p0"><a name="entry168133547083932p0"></a><a name="entry168133547083932p0"></a>devId</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry687947458083932p0"><a name="entry687947458083932p0"></a><a name="entry687947458083932p0"></a>输入参数，显示设备ID，用于支持多个显示设备，取值从0开始，0表示第一个设备，最大支持5个设备。</p>
</td>
</tr>
<tr id="row558287617083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1834133265083932p0"><a name="entry1834133265083932p0"></a><a name="entry1834133265083932p0"></a>layerId</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry184462993083932p0"><a name="entry184462993083932p0"></a><a name="entry184462993083932p0"></a>输入参数，图层ID，图层的唯一标识，根据图层ID操作图层。</p>
</td>
</tr>
<tr id="row1701131404083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry52198588083932p0"><a name="entry52198588083932p0"></a><a name="entry52198588083932p0"></a>rect</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1521007355083932p0"><a name="entry1521007355083932p0"></a><a name="entry1521007355083932p0"></a>输入参数，待设置的裁剪区域。</p>
</td>
</tr>
</tbody>
</table>

**返回：**

DISPLAY\_SUCCESS 表示执行成功。

其他值表示执行失败，具体错误码查看[DispErrCode](_display.md#ga12a925dadef7573cd74d63d06824f9b0)。

## SetLayerDirtyRegion<a name="a7aa2a7bf4c0aed948c8617adec2d91b6"></a>

```
int32_t(* LayerFuncs::SetLayerDirtyRegion) (uint32_t devId, uint32_t layerId, IRect *region)
```

**描述：**

设置图层刷新区域。

GUI图形系统绘制好图像数据后，在调用Flush接口刷新屏幕之前需要设置图层刷新区域。

**参数：**

<a name="table1476807169083932"></a>
<table><thead align="left"><tr id="row116957512083932"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p262521592083932"><a name="p262521592083932"></a><a name="p262521592083932"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p384312705083932"><a name="p384312705083932"></a><a name="p384312705083932"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row2091816226083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry725447451083932p0"><a name="entry725447451083932p0"></a><a name="entry725447451083932p0"></a>devId</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry427252046083932p0"><a name="entry427252046083932p0"></a><a name="entry427252046083932p0"></a>输入参数，显示设备ID，用于支持多个显示设备，取值从0开始，0表示第一个设备，最大支持5个设备。</p>
</td>
</tr>
<tr id="row1360909400083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry359795321083932p0"><a name="entry359795321083932p0"></a><a name="entry359795321083932p0"></a>layerId</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1636127834083932p0"><a name="entry1636127834083932p0"></a><a name="entry1636127834083932p0"></a>输入参数，图层ID，图层的唯一标识，根据图层ID操作图层。</p>
</td>
</tr>
<tr id="row1537280845083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry167413125083932p0"><a name="entry167413125083932p0"></a><a name="entry167413125083932p0"></a>region</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry872116435083932p0"><a name="entry872116435083932p0"></a><a name="entry872116435083932p0"></a>输入参数，待设置的刷新区域。</p>
</td>
</tr>
</tbody>
</table>

**返回：**

DISPLAY\_SUCCESS 表示执行成功。

其他值表示执行失败，具体错误码查看[DispErrCode](_display.md#ga12a925dadef7573cd74d63d06824f9b0)。

## SetLayerMetaData<a name="aac35ce1bed6960d799006d5e3d6b4cee"></a>

```
int32_t(* LayerFuncs::SetLayerMetaData) (uint32_t devId, uint32_t layerId, uint32_t num, const HDRMetaData *metaData)
```

**描述：**

设置图层的HDRmetaData。

**参数：**

<a name="table1851369124083932"></a>
<table><thead align="left"><tr id="row213987337083932"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p932904772083932"><a name="p932904772083932"></a><a name="p932904772083932"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1238370180083932"><a name="p1238370180083932"></a><a name="p1238370180083932"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row230390911083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1142859371083932p0"><a name="entry1142859371083932p0"></a><a name="entry1142859371083932p0"></a>devId</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry951314388083932p0"><a name="entry951314388083932p0"></a><a name="entry951314388083932p0"></a>输入参数，指示需要操作的设备ID。</p>
</td>
</tr>
<tr id="row1604444795083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1754246661083932p0"><a name="entry1754246661083932p0"></a><a name="entry1754246661083932p0"></a>layerId</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1224628414083932p0"><a name="entry1224628414083932p0"></a><a name="entry1224628414083932p0"></a>输入参数，指示需要操作的图层ID。</p>
</td>
</tr>
<tr id="row225882992083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1769708040083932p0"><a name="entry1769708040083932p0"></a><a name="entry1769708040083932p0"></a>num</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry769102967083932p0"><a name="entry769102967083932p0"></a><a name="entry769102967083932p0"></a>输入参数，metadata 数组个数。</p>
</td>
</tr>
<tr id="row547110140083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry591724354083932p0"><a name="entry591724354083932p0"></a><a name="entry591724354083932p0"></a>metaData</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry903410836083932p0"><a name="entry903410836083932p0"></a><a name="entry903410836083932p0"></a>输入参数，表示需要设置的 metadata 数组首地址。</p>
</td>
</tr>
</tbody>
</table>

**返回：**

DISPLAY\_SUCCESS 表示执行成功。

其他值表示执行失败，具体错误码查看[DispErrCode](_display.md#ga12a925dadef7573cd74d63d06824f9b0)。

## SetLayerMetaDataSet<a name="a460ae3e58e74470bab506ab7c7cc8606"></a>

```
int32_t(* LayerFuncs::SetLayerMetaDataSet) (uint32_t devId, uint32_t layerId, HDRMetadataKey key, uint32_t num, const uint8_t *metaData)
```

**描述：**

设置图层的metaData set。

**参数：**

<a name="table1145553512083932"></a>
<table><thead align="left"><tr id="row1605788667083932"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1549301408083932"><a name="p1549301408083932"></a><a name="p1549301408083932"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1231325984083932"><a name="p1231325984083932"></a><a name="p1231325984083932"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row311214791083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry2136761917083932p0"><a name="entry2136761917083932p0"></a><a name="entry2136761917083932p0"></a>devId</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry2117846961083932p0"><a name="entry2117846961083932p0"></a><a name="entry2117846961083932p0"></a>输入参数，指示需要操作的设备ID。</p>
</td>
</tr>
<tr id="row379869874083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry470428787083932p0"><a name="entry470428787083932p0"></a><a name="entry470428787083932p0"></a>layerId</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry454825506083932p0"><a name="entry454825506083932p0"></a><a name="entry454825506083932p0"></a>输入参数，指示需要操作的图层ID。</p>
</td>
</tr>
<tr id="row1652385285083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1027530832083932p0"><a name="entry1027530832083932p0"></a><a name="entry1027530832083932p0"></a>key</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry614636097083932p0"><a name="entry614636097083932p0"></a><a name="entry614636097083932p0"></a>输入参数，表示需要设置的 HDRMetadataKey。</p>
</td>
</tr>
<tr id="row1729156098083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1671070455083932p0"><a name="entry1671070455083932p0"></a><a name="entry1671070455083932p0"></a>num</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1254719967083932p0"><a name="entry1254719967083932p0"></a><a name="entry1254719967083932p0"></a>输入参数，metadata 数组个数。</p>
</td>
</tr>
<tr id="row480399086083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry479900137083932p0"><a name="entry479900137083932p0"></a><a name="entry479900137083932p0"></a>metaData</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1984760107083932p0"><a name="entry1984760107083932p0"></a><a name="entry1984760107083932p0"></a>输入参数，表示需要设置的 metadata 数组首地址, 数据类型为uint8_t。</p>
</td>
</tr>
</tbody>
</table>

**返回：**

DISPLAY\_SUCCESS 表示执行成功。

其他值表示执行失败，具体错误码查看[DispErrCode](_display.md#ga12a925dadef7573cd74d63d06824f9b0)。

## SetLayerPalette<a name="a3982c76e093852ef386fc372581be4af"></a>

```
int32_t(* LayerFuncs::SetLayerPalette) (uint32_t devId, uint32_t layerId, uint32_t *palette, uint32_t len)
```

**描述：**

设置图层调色板。

**参数：**

<a name="table1724929435083932"></a>
<table><thead align="left"><tr id="row1659551134083932"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p652157320083932"><a name="p652157320083932"></a><a name="p652157320083932"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p280858989083932"><a name="p280858989083932"></a><a name="p280858989083932"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row1921589746083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry247722039083932p0"><a name="entry247722039083932p0"></a><a name="entry247722039083932p0"></a>devId</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1842447138083932p0"><a name="entry1842447138083932p0"></a><a name="entry1842447138083932p0"></a>输入参数，显示设备ID，用于支持多个显示设备，取值从0开始，0表示第一个设备，最大支持5个设备。</p>
</td>
</tr>
<tr id="row1195354489083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1218869782083932p0"><a name="entry1218869782083932p0"></a><a name="entry1218869782083932p0"></a>layerId</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry446627384083932p0"><a name="entry446627384083932p0"></a><a name="entry446627384083932p0"></a>输入参数，图层ID，图层的唯一标识，根据图层ID操作图层。</p>
</td>
</tr>
<tr id="row1532842165083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry189215181083932p0"><a name="entry189215181083932p0"></a><a name="entry189215181083932p0"></a>palette</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1097932408083932p0"><a name="entry1097932408083932p0"></a><a name="entry1097932408083932p0"></a>输入参数，待设置的图层调色板。</p>
</td>
</tr>
<tr id="row1113831564083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry258343178083932p0"><a name="entry258343178083932p0"></a><a name="entry258343178083932p0"></a>len</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1999929968083932p0"><a name="entry1999929968083932p0"></a><a name="entry1999929968083932p0"></a>输入参数，调色板长度。</p>
</td>
</tr>
</tbody>
</table>

**返回：**

DISPLAY\_SUCCESS 表示执行成功。

其他值表示执行失败，具体错误码查看[DispErrCode](_display.md#ga12a925dadef7573cd74d63d06824f9b0)。

**参见：**

[GetLayerPalette](_layer_funcs.md#af713bc39e51dc8168c278e2f126bf4e3)

## SetLayerPreMulti<a name="a456aa01ca3ffa81d2e49c0a9487f816f"></a>

```
int32_t(* LayerFuncs::SetLayerPreMulti) (uint32_t devId, uint32_t layerId, bool preMul)
```

**描述：**

设置图层预乘。

**参数：**

<a name="table1341948102083932"></a>
<table><thead align="left"><tr id="row910778953083932"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p24217972083932"><a name="p24217972083932"></a><a name="p24217972083932"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p673689862083932"><a name="p673689862083932"></a><a name="p673689862083932"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row1803152674083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry2126765770083932p0"><a name="entry2126765770083932p0"></a><a name="entry2126765770083932p0"></a>devId</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1984621919083932p0"><a name="entry1984621919083932p0"></a><a name="entry1984621919083932p0"></a>输入参数，显示设备ID，用于支持多个显示设备，取值从0开始，0表示第一个设备，最大支持5个设备。</p>
</td>
</tr>
<tr id="row850116418083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry634774689083932p0"><a name="entry634774689083932p0"></a><a name="entry634774689083932p0"></a>layerId</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry645570500083932p0"><a name="entry645570500083932p0"></a><a name="entry645570500083932p0"></a>输入参数，图层ID，图层的唯一标识，根据图层ID操作图层。</p>
</td>
</tr>
<tr id="row1136550035083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1633836008083932p0"><a name="entry1633836008083932p0"></a><a name="entry1633836008083932p0"></a>preMul</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry2039824494083932p0"><a name="entry2039824494083932p0"></a><a name="entry2039824494083932p0"></a>输入参数，待设置的图层预乘使能标识，1表示使能图层预乘，0表示不使能图层预乘。</p>
</td>
</tr>
</tbody>
</table>

**返回：**

DISPLAY\_SUCCESS 表示执行成功。

其他值表示执行失败，具体错误码查看[DispErrCode](_display.md#ga12a925dadef7573cd74d63d06824f9b0)。

**参见：**

[GetLayerPreMulti](_layer_funcs.md#a4a0e26f8401da1232f03bb37502ff4bd)

## SetLayerSize<a name="ab58e66b0676b1baa1662c175d43bf219"></a>

```
int32_t(* LayerFuncs::SetLayerSize) (uint32_t devId, uint32_t layerId, IRect *rect)
```

**描述：**

设置图层大小。

**参数：**

<a name="table1658964510083932"></a>
<table><thead align="left"><tr id="row2116185226083932"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p70763821083932"><a name="p70763821083932"></a><a name="p70763821083932"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p88480269083932"><a name="p88480269083932"></a><a name="p88480269083932"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row152022591083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1009535841083932p0"><a name="entry1009535841083932p0"></a><a name="entry1009535841083932p0"></a>devId</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry421913960083932p0"><a name="entry421913960083932p0"></a><a name="entry421913960083932p0"></a>输入参数，显示设备ID，用于支持多个显示设备，取值从0开始，0表示第一个设备，最大支持5个设备。</p>
</td>
</tr>
<tr id="row864483234083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1247844580083932p0"><a name="entry1247844580083932p0"></a><a name="entry1247844580083932p0"></a>layerId</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1863683373083932p0"><a name="entry1863683373083932p0"></a><a name="entry1863683373083932p0"></a>输入参数，图层ID，图层的唯一标识，根据图层ID操作图层。</p>
</td>
</tr>
<tr id="row625172131083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry410375036083932p0"><a name="entry410375036083932p0"></a><a name="entry410375036083932p0"></a>rect</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1648169029083932p0"><a name="entry1648169029083932p0"></a><a name="entry1648169029083932p0"></a>输入参数，待设置的图层大小，单位为像素。</p>
</td>
</tr>
</tbody>
</table>

**返回：**

DISPLAY\_SUCCESS 表示执行成功。

其他值表示执行失败，具体错误码查看[DispErrCode](_display.md#ga12a925dadef7573cd74d63d06824f9b0)。

**参见：**

[GetLayerSize](_layer_funcs.md#a56be84be25eba64497b2a842c1f68b26)

## SetLayerTunnelHandle<a name="a0737f01ec437fc7e7180ad69b7f4dcd1"></a>

```
int32_t(* LayerFuncs::SetLayerTunnelHandle) (uint32_t devId, uint32_t layerId, ExtDataHandle *handle)
```

**描述：**

设置图层的tunnel句柄。

**参数：**

<a name="table1872466961083932"></a>
<table><thead align="left"><tr id="row1057173504083932"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p948664656083932"><a name="p948664656083932"></a><a name="p948664656083932"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1954034354083932"><a name="p1954034354083932"></a><a name="p1954034354083932"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row470052902083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry702295222083932p0"><a name="entry702295222083932p0"></a><a name="entry702295222083932p0"></a>devId</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1128882375083932p0"><a name="entry1128882375083932p0"></a><a name="entry1128882375083932p0"></a>输入参数，指示需要操作的设备ID。</p>
</td>
</tr>
<tr id="row880973676083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1369436746083932p0"><a name="entry1369436746083932p0"></a><a name="entry1369436746083932p0"></a>layerId</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry941921528083932p0"><a name="entry941921528083932p0"></a><a name="entry941921528083932p0"></a>输入参数，指示需要操作的图层ID。</p>
</td>
</tr>
<tr id="row907997576083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry673681250083932p0"><a name="entry673681250083932p0"></a><a name="entry673681250083932p0"></a>handle</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1176266847083932p0"><a name="entry1176266847083932p0"></a><a name="entry1176266847083932p0"></a>输入参数，表示需要设置的句柄。</p>
</td>
</tr>
</tbody>
</table>

**返回：**

DISPLAY\_SUCCESS 表示执行成功。

其他值表示执行失败，具体错误码查看[DispErrCode](_display.md#ga12a925dadef7573cd74d63d06824f9b0)。

## SetLayerVisible<a name="aaa5bf7f98e8dc47510a4f26fb38094b6"></a>

```
int32_t(* LayerFuncs::SetLayerVisible) (uint32_t devId, uint32_t layerId, bool visible)
```

**描述：**

设置图层是否可见。

不可见情况下图层不显示在屏幕上，可见情况下图层显示在屏幕上。

**参数：**

<a name="table1863720477083932"></a>
<table><thead align="left"><tr id="row1529694822083932"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1903595298083932"><a name="p1903595298083932"></a><a name="p1903595298083932"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p177708193083932"><a name="p177708193083932"></a><a name="p177708193083932"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row112969529083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry813642203083932p0"><a name="entry813642203083932p0"></a><a name="entry813642203083932p0"></a>devId</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry65423316083932p0"><a name="entry65423316083932p0"></a><a name="entry65423316083932p0"></a>输入参数，显示设备ID，用于支持多个显示设备，取值从0开始，0表示第一个设备，最大支持5个设备。</p>
</td>
</tr>
<tr id="row302307787083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry2053938857083932p0"><a name="entry2053938857083932p0"></a><a name="entry2053938857083932p0"></a>layerId</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1993372931083932p0"><a name="entry1993372931083932p0"></a><a name="entry1993372931083932p0"></a>输入参数，图层ID，图层的唯一标识，根据图层ID操作图层。</p>
</td>
</tr>
<tr id="row1546221481083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry985438717083932p0"><a name="entry985438717083932p0"></a><a name="entry985438717083932p0"></a>visible</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry2091421721083932p0"><a name="entry2091421721083932p0"></a><a name="entry2091421721083932p0"></a>输入参数，待设置的图层可见标识，设置true表示图层可见，设置false表示图层不可见。</p>
</td>
</tr>
</tbody>
</table>

**返回：**

DISPLAY\_SUCCESS 表示执行成功。

其他值表示执行失败，具体错误码查看[DispErrCode](_display.md#ga12a925dadef7573cd74d63d06824f9b0)。

**参见：**

[GetLayerVisibleState](_layer_funcs.md#a6bbff71bb4f17eb84a4db4857a0b0985)

## SetLayerVisibleRegion<a name="a36625a6daf8faca55551e1d53e0131e1"></a>

```
int32_t(* LayerFuncs::SetLayerVisibleRegion) (uint32_t devId, uint32_t layerId, uint32_t num, IRect *rect)
```

**描述：**

设置一个图层的可见区域

**参数：**

<a name="table1367860784083932"></a>
<table><thead align="left"><tr id="row1114367514083932"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p256969432083932"><a name="p256969432083932"></a><a name="p256969432083932"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1522881593083932"><a name="p1522881593083932"></a><a name="p1522881593083932"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row1931867517083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry53543868083932p0"><a name="entry53543868083932p0"></a><a name="entry53543868083932p0"></a>devId</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry175060521083932p0"><a name="entry175060521083932p0"></a><a name="entry175060521083932p0"></a>输入参数，显示设备的ID。取值范围为0 ~ 4，其中0表示第一个显示设备，4表示最后一个显示设备。</p>
</td>
</tr>
<tr id="row1562009996083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry489805515083932p0"><a name="entry489805515083932p0"></a><a name="entry489805515083932p0"></a>layerId</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1438277993083932p0"><a name="entry1438277993083932p0"></a><a name="entry1438277993083932p0"></a>输入参数，层ID，唯一标识一个层。可以对该层进行操作。</p>
</td>
</tr>
<tr id="row1219919458083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1158604779083932p0"><a name="entry1158604779083932p0"></a><a name="entry1158604779083932p0"></a>num</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry196168666083932p0"><a name="entry196168666083932p0"></a><a name="entry196168666083932p0"></a>输入参数，指定rect的计数，该区域包含多个 <a href="_i_rect.md">IRect</a>,num表示该区域中有多少个rect区域。</p>
</td>
</tr>
<tr id="row1088571444083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1707350660083932p0"><a name="entry1707350660083932p0"></a><a name="entry1707350660083932p0"></a>rect</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry397469171083932p0"><a name="entry397469171083932p0"></a><a name="entry397469171083932p0"></a>输出参数，rectes对象的指针。</p>
</td>
</tr>
</tbody>
</table>

**返回：**

DISPLAY\_SUCCESS 表示执行成功。

其他值表示执行失败，具体错误码查看[DispErrCode](_display.md#ga12a925dadef7573cd74d63d06824f9b0)。

## SetLayerZorder<a name="aa3803c2a6395651d1538ffb62d29733d"></a>

```
int32_t(* LayerFuncs::SetLayerZorder) (uint32_t devId, uint32_t layerId, uint32_t zorder)
```

**描述：**

设置图层Z轴次序。

图层的Z序值越大，图层越靠上显示。

**参数：**

<a name="table797953136083932"></a>
<table><thead align="left"><tr id="row1868050759083932"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1835639280083932"><a name="p1835639280083932"></a><a name="p1835639280083932"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1497091011083932"><a name="p1497091011083932"></a><a name="p1497091011083932"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row836472993083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry918102154083932p0"><a name="entry918102154083932p0"></a><a name="entry918102154083932p0"></a>devId</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry2084055636083932p0"><a name="entry2084055636083932p0"></a><a name="entry2084055636083932p0"></a>输入参数，显示设备ID，用于支持多个显示设备，取值从0开始，0表示第一个设备，最大支持5个设备。</p>
</td>
</tr>
<tr id="row1858681889083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry262817354083932p0"><a name="entry262817354083932p0"></a><a name="entry262817354083932p0"></a>layerId</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry2091325047083932p0"><a name="entry2091325047083932p0"></a><a name="entry2091325047083932p0"></a>输入参数，图层ID，图层的唯一标识，根据图层ID操作图层。</p>
</td>
</tr>
<tr id="row116232399083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1509222876083932p0"><a name="entry1509222876083932p0"></a><a name="entry1509222876083932p0"></a>zorder</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry104393164083932p0"><a name="entry104393164083932p0"></a><a name="entry104393164083932p0"></a>输入参数，待设置的图层Z序，为整数值，取值范围为[0, 255]，值越大图层越往上排列。</p>
</td>
</tr>
</tbody>
</table>

**返回：**

DISPLAY\_SUCCESS 表示执行成功。

其他值表示执行失败，具体错误码查看[DispErrCode](_display.md#ga12a925dadef7573cd74d63d06824f9b0)。

**参见：**

[GetLayerZorder](_layer_funcs.md#a5644645442e1d6943b55ce0a6a801b8c)

## SetTransformMode<a name="a707a6ae5144ee329110822dd8301cb22"></a>

```
int32_t(* LayerFuncs::SetTransformMode) (uint32_t devId, uint32_t layerId, TransformType type)
```

**描述：**

设置图层变换模式，根据不同的场景设置图层的旋转、缩放、移位等。

**参数：**

<a name="table2081410828083932"></a>
<table><thead align="left"><tr id="row489936534083932"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1648963578083932"><a name="p1648963578083932"></a><a name="p1648963578083932"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1866583028083932"><a name="p1866583028083932"></a><a name="p1866583028083932"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row1616506443083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry19306463083932p0"><a name="entry19306463083932p0"></a><a name="entry19306463083932p0"></a>devId</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry344386554083932p0"><a name="entry344386554083932p0"></a><a name="entry344386554083932p0"></a>输入参数，显示设备ID，用于支持多个显示设备，取值从0开始，0表示第一个设备，最大支持5个设备。</p>
</td>
</tr>
<tr id="row246387783083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry406773483083932p0"><a name="entry406773483083932p0"></a><a name="entry406773483083932p0"></a>layerId</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry332026382083932p0"><a name="entry332026382083932p0"></a><a name="entry332026382083932p0"></a>输入参数，图层ID，图层的唯一标识，根据图层ID操作图层。</p>
</td>
</tr>
<tr id="row252879575083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry355850575083932p0"><a name="entry355850575083932p0"></a><a name="entry355850575083932p0"></a>type</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry442073549083932p0"><a name="entry442073549083932p0"></a><a name="entry442073549083932p0"></a>输入参数，待设置的图层变换模式。</p>
</td>
</tr>
</tbody>
</table>

**返回：**

DISPLAY\_SUCCESS 表示执行成功。

其他值表示执行失败，具体错误码查看[DispErrCode](_display.md#ga12a925dadef7573cd74d63d06824f9b0)。

## SnapShot<a name="a751377d6d1877cd9e878208b94339407"></a>

```
int32_t(* LayerFuncs::SnapShot) (uint32_t devId, LayerBuffer *buffer)
```

**描述：**

实现抓图功能。

本函数将显示设备上的图像数据截图保存到buffer中，用于调试、应用截图等场景。

otherwise.

**参数：**

<a name="table489919074083932"></a>
<table><thead align="left"><tr id="row2047342183083932"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1321362513083932"><a name="p1321362513083932"></a><a name="p1321362513083932"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p308131199083932"><a name="p308131199083932"></a><a name="p308131199083932"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row31921531083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry2121182837083932p0"><a name="entry2121182837083932p0"></a><a name="entry2121182837083932p0"></a>devId</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry583881265083932p0"><a name="entry583881265083932p0"></a><a name="entry583881265083932p0"></a>输入参数，显示设备ID，用于支持多个显示设备，取值从0开始，0表示第一个设备，最大支持5个设备。</p>
</td>
</tr>
<tr id="row279891930083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1664310643083932p0"><a name="entry1664310643083932p0"></a><a name="entry1664310643083932p0"></a>buffer</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1987867491083932p0"><a name="entry1987867491083932p0"></a><a name="entry1987867491083932p0"></a>输出参数，保存截屏的buffer信息。</p>
</td>
</tr>
</tbody>
</table>

**返回：**

DISPLAY\_SUCCESS 表示执行成功。

其他值表示执行失败，具体错误码查看[DispErrCode](_display.md#ga12a925dadef7573cd74d63d06824f9b0)。

## WaitForVBlank<a name="a771d3d43be731540b881ac788c71266b"></a>

```
int32_t(* LayerFuncs::WaitForVBlank) (uint32_t devId, uint32_t layerId, int32_t timeOut)
```

**描述：**

实现等待帧消隐期到来功能。

该函数会让系统等待，直到帧消隐期到来，用于软件和硬件之间的同步。

**参数：**

<a name="table1630799899083932"></a>
<table><thead align="left"><tr id="row1003694002083932"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p884343492083932"><a name="p884343492083932"></a><a name="p884343492083932"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1591689378083932"><a name="p1591689378083932"></a><a name="p1591689378083932"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row443529496083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1049698471083932p0"><a name="entry1049698471083932p0"></a><a name="entry1049698471083932p0"></a>devId</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry749852432083932p0"><a name="entry749852432083932p0"></a><a name="entry749852432083932p0"></a>输入参数，显示设备ID，用于支持多个显示设备，取值从0开始，0表示第一个设备，最大支持5个设备。</p>
</td>
</tr>
<tr id="row2085787942083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1406223262083932p0"><a name="entry1406223262083932p0"></a><a name="entry1406223262083932p0"></a>layerId</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry841952095083932p0"><a name="entry841952095083932p0"></a><a name="entry841952095083932p0"></a>输入参数，图层ID，图层的唯一标识，根据图层ID操作图层。</p>
</td>
</tr>
<tr id="row63470323083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry573485622083932p0"><a name="entry573485622083932p0"></a><a name="entry573485622083932p0"></a>timeOut</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1401555711083932p0"><a name="entry1401555711083932p0"></a><a name="entry1401555711083932p0"></a>输入参数，超时时间，在设置的超时时间后，没有等到帧消隐期到来则超时返回。</p>
</td>
</tr>
</tbody>
</table>

**返回：**

DISPLAY\_SUCCESS 表示执行成功。

其他值表示执行失败，具体错误码查看[DispErrCode](_display.md#ga12a925dadef7573cd74d63d06824f9b0)。

