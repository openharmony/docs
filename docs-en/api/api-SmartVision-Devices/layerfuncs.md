# LayerFuncs<a name="EN-US_TOPIC_0000001055678100"></a>

-   [Overview](#section818032663165632)
-   [Summary](#section2061830316165632)
-   [Data Fields](#pub-attribs)
-   [Details](#section1254774471165632)
-   [Field](#section842552881165632)
-   [CloseLayer](#a2e375f75209da329f131b914377e9616)
-   [DeinitDisplay](#a8d7a715d7d2b4bd5ab0db92c2a1eec93)
-   [Flush](#abb480bf2b85e93841c49fdc9800bd1e7)
-   [GetDisplayInfo](#aba57e2b79df0e774727d0c07ef90e715)
-   [GetLayerAlpha](#acf1e01338eeb0fd957f53ed0d2551394)
-   [GetLayerBuffer](#a40b406f6b4e6a812a36605041e0e81d6)
-   [GetLayerColorKey](#aea882232b6279b8be82c45e889187b24)
-   [GetLayerCompression](#ab0b5855ea4ee5228516303cba84907ce)
-   [GetLayerPalette](#af713bc39e51dc8168c278e2f126bf4e3)
-   [GetLayerPreMulti](#a4a0e26f8401da1232f03bb37502ff4bd)
-   [GetLayerSize](#a56be84be25eba64497b2a842c1f68b26)
-   [GetLayerVisibleState](#a6bbff71bb4f17eb84a4db4857a0b0985)
-   [GetLayerZorder](#a5644645442e1d6943b55ce0a6a801b8c)
-   [InitDisplay](#a0641c3b48542646daa80386122bed46a)
-   [OpenLayer](#a795f4e168d5b284a9c33f636c278207f)
-   [SetLayerAlpha](#a20e554afa2f7b1015fd23ce240344b13)
-   [SetLayerColorKey](#a5701fe1e0e2414de577aa5329bd873c9)
-   [SetLayerCompression](#a46c9750d8615dc874b66ac4b10796b24)
-   [SetLayerCrop](#a4f925226529e27678df19423fa6f83ad)
-   [SetLayerDirtyRegion](#a7aa2a7bf4c0aed948c8617adec2d91b6)
-   [SetLayerPalette](#a3982c76e093852ef386fc372581be4af)
-   [SetLayerPreMulti](#a456aa01ca3ffa81d2e49c0a9487f816f)
-   [SetLayerSize](#ab58e66b0676b1baa1662c175d43bf219)
-   [SetLayerVisible](#aaa5bf7f98e8dc47510a4f26fb38094b6)
-   [SetLayerZorder](#aa3803c2a6395651d1538ffb62d29733d)
-   [SetTransformMode](#a707a6ae5144ee329110822dd8301cb22)
-   [SnapShot](#a751377d6d1877cd9e878208b94339407)
-   [WaitForVBlank](#a62471eb83a24d0a84dabd53018666336)

## **Overview**<a name="section818032663165632"></a>

**Related Modules:**

[Display](display.md)

**Description:**

Defines pointers to the layer driver functions. 

## **Summary**<a name="section2061830316165632"></a>

## Data Fields<a name="pub-attribs"></a>

<a name="table541106358165632"></a>
<table><thead align="left"><tr id="row628492967165632"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1498559263165632"><a name="p1498559263165632"></a><a name="p1498559263165632"></a>Variable Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1912803131165632"><a name="p1912803131165632"></a><a name="p1912803131165632"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row524101257165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1201371888165632"><a name="p1201371888165632"></a><a name="p1201371888165632"></a><a href="layerfuncs.md#a0641c3b48542646daa80386122bed46a">InitDisplay</a> )(uint32_t devId)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p663011786165632"><a name="p663011786165632"></a><a name="p663011786165632"></a>int32_t(* </p>
<p id="p962429474165632"><a name="p962429474165632"></a><a name="p962429474165632"></a>Initializes a display device. </p>
</td>
</tr>
<tr id="row793107941165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1086416270165632"><a name="p1086416270165632"></a><a name="p1086416270165632"></a><a href="layerfuncs.md#a8d7a715d7d2b4bd5ab0db92c2a1eec93">DeinitDisplay</a> )(uint32_t devId)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2016096221165632"><a name="p2016096221165632"></a><a name="p2016096221165632"></a>int32_t(* </p>
<p id="p145623060165632"><a name="p145623060165632"></a><a name="p145623060165632"></a>Deinitializes a display device. </p>
</td>
</tr>
<tr id="row79038079165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p142819779165632"><a name="p142819779165632"></a><a name="p142819779165632"></a><a href="layerfuncs.md#aba57e2b79df0e774727d0c07ef90e715">GetDisplayInfo</a> )(uint32_t devId, <a href="displayinfo.md">DisplayInfo</a> *dispInfo)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p339155670165632"><a name="p339155670165632"></a><a name="p339155670165632"></a>int32_t(* </p>
<p id="p99814326165632"><a name="p99814326165632"></a><a name="p99814326165632"></a>Obtains information about a display device. </p>
</td>
</tr>
<tr id="row1466953348165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1330060617165632"><a name="p1330060617165632"></a><a name="p1330060617165632"></a><a href="layerfuncs.md#a795f4e168d5b284a9c33f636c278207f">OpenLayer</a> )(uint32_t devId, const <a href="layerinfo.md">LayerInfo</a> *layerInfo, uint32_t *layerId)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p443500552165632"><a name="p443500552165632"></a><a name="p443500552165632"></a>int32_t(* </p>
<p id="p663120130165632"><a name="p663120130165632"></a><a name="p663120130165632"></a>Opens a layer on a specified display device. </p>
</td>
</tr>
<tr id="row542816703165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p931042133165632"><a name="p931042133165632"></a><a name="p931042133165632"></a><a href="layerfuncs.md#a2e375f75209da329f131b914377e9616">CloseLayer</a> )(uint32_t devId, uint32_t layerId)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p653753441165632"><a name="p653753441165632"></a><a name="p653753441165632"></a>int32_t(* </p>
<p id="p48763163165632"><a name="p48763163165632"></a><a name="p48763163165632"></a>Closes a layer that is no longer required on a specified display device. </p>
</td>
</tr>
<tr id="row1824182403165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1450501913165632"><a name="p1450501913165632"></a><a name="p1450501913165632"></a><a href="layerfuncs.md#aaa5bf7f98e8dc47510a4f26fb38094b6">SetLayerVisible</a> )(uint32_t devId, uint32_t layerId, bool visible)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p491770946165632"><a name="p491770946165632"></a><a name="p491770946165632"></a>int32_t(* </p>
<p id="p677960873165632"><a name="p677960873165632"></a><a name="p677960873165632"></a>Sets whether a layer is visible. </p>
</td>
</tr>
<tr id="row871511334165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p925338164165632"><a name="p925338164165632"></a><a name="p925338164165632"></a><a href="layerfuncs.md#a6bbff71bb4f17eb84a4db4857a0b0985">GetLayerVisibleState</a> )(uint32_t devId, uint32_t layerId, bool *visible)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p559324303165632"><a name="p559324303165632"></a><a name="p559324303165632"></a>int32_t(* </p>
<p id="p471814769165632"><a name="p471814769165632"></a><a name="p471814769165632"></a>Checks whether a layer is visible. </p>
</td>
</tr>
<tr id="row1338400743165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p991763711165632"><a name="p991763711165632"></a><a name="p991763711165632"></a><a href="layerfuncs.md#ab58e66b0676b1baa1662c175d43bf219">SetLayerSize</a> )(uint32_t devId, uint32_t layerId, <a href="irect.md">IRect</a> *rect)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1685945986165632"><a name="p1685945986165632"></a><a name="p1685945986165632"></a>int32_t(* </p>
<p id="p585565756165632"><a name="p585565756165632"></a><a name="p585565756165632"></a>Sets the size of a layer. </p>
</td>
</tr>
<tr id="row195566010165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1285091356165632"><a name="p1285091356165632"></a><a name="p1285091356165632"></a><a href="layerfuncs.md#a56be84be25eba64497b2a842c1f68b26">GetLayerSize</a> )(uint32_t devId, uint32_t layerId, <a href="irect.md">IRect</a> *rect)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p586346465165632"><a name="p586346465165632"></a><a name="p586346465165632"></a>int32_t(* </p>
<p id="p645796451165632"><a name="p645796451165632"></a><a name="p645796451165632"></a>Obtains the size of a layer. </p>
</td>
</tr>
<tr id="row1104500057165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1002731791165632"><a name="p1002731791165632"></a><a name="p1002731791165632"></a><a href="layerfuncs.md#a4f925226529e27678df19423fa6f83ad">SetLayerCrop</a> )(uint32_t devId, uint32_t layerId, <a href="irect.md">IRect</a> *rect)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p809148529165632"><a name="p809148529165632"></a><a name="p809148529165632"></a>int32_t(* </p>
<p id="p121422450165632"><a name="p121422450165632"></a><a name="p121422450165632"></a>Sets the rectangular area to crop for a layer. </p>
</td>
</tr>
<tr id="row395056182165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p993726907165632"><a name="p993726907165632"></a><a name="p993726907165632"></a><a href="layerfuncs.md#aa3803c2a6395651d1538ffb62d29733d">SetLayerZorder</a> )(uint32_t devId, uint32_t layerId, uint32_t zorder)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1621071495165632"><a name="p1621071495165632"></a><a name="p1621071495165632"></a>int32_t(* </p>
<p id="p1159652455165632"><a name="p1159652455165632"></a><a name="p1159652455165632"></a>Sets the z-order for a layer. </p>
</td>
</tr>
<tr id="row1528265751165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p749403485165632"><a name="p749403485165632"></a><a name="p749403485165632"></a><a href="layerfuncs.md#a5644645442e1d6943b55ce0a6a801b8c">GetLayerZorder</a> )(uint32_t devId, uint32_t layerId, uint32_t *zorder)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p170940348165632"><a name="p170940348165632"></a><a name="p170940348165632"></a>int32_t(* </p>
<p id="p1848360992165632"><a name="p1848360992165632"></a><a name="p1848360992165632"></a>Obtains the z-order of a layer. </p>
</td>
</tr>
<tr id="row833741249165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1868807032165632"><a name="p1868807032165632"></a><a name="p1868807032165632"></a><a href="layerfuncs.md#a456aa01ca3ffa81d2e49c0a9487f816f">SetLayerPreMulti</a> )(uint32_t devId, uint32_t layerId, bool preMul)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p665878990165632"><a name="p665878990165632"></a><a name="p665878990165632"></a>int32_t(* </p>
<p id="p1290429980165632"><a name="p1290429980165632"></a><a name="p1290429980165632"></a>Sets layer premultiplication. </p>
</td>
</tr>
<tr id="row446689934165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1734043765165632"><a name="p1734043765165632"></a><a name="p1734043765165632"></a><a href="layerfuncs.md#a4a0e26f8401da1232f03bb37502ff4bd">GetLayerPreMulti</a> )(uint32_t devId, uint32_t layerId, bool *preMul)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1480858831165632"><a name="p1480858831165632"></a><a name="p1480858831165632"></a>int32_t(* </p>
<p id="p289331741165632"><a name="p289331741165632"></a><a name="p289331741165632"></a>Obtains the premultiplication flag of a layer. </p>
</td>
</tr>
<tr id="row1759089500165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2051742172165632"><a name="p2051742172165632"></a><a name="p2051742172165632"></a><a href="layerfuncs.md#a20e554afa2f7b1015fd23ce240344b13">SetLayerAlpha</a> )(uint32_t devId, uint32_t layerid, <a href="layeralpha.md">LayerAlpha</a> *alpha)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2035154922165632"><a name="p2035154922165632"></a><a name="p2035154922165632"></a>int32_t(* </p>
<p id="p1559125114165632"><a name="p1559125114165632"></a><a name="p1559125114165632"></a>Sets the alpha value for a layer. </p>
</td>
</tr>
<tr id="row1565512477165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p845606407165632"><a name="p845606407165632"></a><a name="p845606407165632"></a><a href="layerfuncs.md#acf1e01338eeb0fd957f53ed0d2551394">GetLayerAlpha</a> )(uint32_t devId, uint32_t layerId, <a href="layeralpha.md">LayerAlpha</a> *alpha)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p702291153165632"><a name="p702291153165632"></a><a name="p702291153165632"></a>int32_t(* </p>
<p id="p347803473165632"><a name="p347803473165632"></a><a name="p347803473165632"></a>Obtains the alpha value of a layer. </p>
</td>
</tr>
<tr id="row566520262165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1636871165165632"><a name="p1636871165165632"></a><a name="p1636871165165632"></a><a href="layerfuncs.md#a5701fe1e0e2414de577aa5329bd873c9">SetLayerColorKey</a> )(uint32_t devId, uint32_t layerId, bool enable, uint32_t key)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p228058675165632"><a name="p228058675165632"></a><a name="p228058675165632"></a>int32_t(* </p>
<p id="p271422756165632"><a name="p271422756165632"></a><a name="p271422756165632"></a>Sets the color key for a layer. </p>
</td>
</tr>
<tr id="row1575984507165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p590506212165632"><a name="p590506212165632"></a><a name="p590506212165632"></a><a href="layerfuncs.md#aea882232b6279b8be82c45e889187b24">GetLayerColorKey</a> )(uint32_t devId, uint32_t layerId, bool *enable, uint32_t *key)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1249507993165632"><a name="p1249507993165632"></a><a name="p1249507993165632"></a>int32_t(* </p>
<p id="p1483403454165632"><a name="p1483403454165632"></a><a name="p1483403454165632"></a>Obtains the color key of a layer. </p>
</td>
</tr>
<tr id="row496761990165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1356510145165632"><a name="p1356510145165632"></a><a name="p1356510145165632"></a><a href="layerfuncs.md#a3982c76e093852ef386fc372581be4af">SetLayerPalette</a> )(uint32_t devId, uint32_t layerId, uint32_t *palette, uint32_t len)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p325281963165632"><a name="p325281963165632"></a><a name="p325281963165632"></a>int32_t(* </p>
<p id="p1118060801165632"><a name="p1118060801165632"></a><a name="p1118060801165632"></a>Sets the palette for a layer. </p>
</td>
</tr>
<tr id="row876960988165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1590590614165632"><a name="p1590590614165632"></a><a name="p1590590614165632"></a><a href="layerfuncs.md#af713bc39e51dc8168c278e2f126bf4e3">GetLayerPalette</a> )(uint32_t devId, uint32_t layerId, uint32_t *palette, uint32_t len)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1984816786165632"><a name="p1984816786165632"></a><a name="p1984816786165632"></a>int32_t(* </p>
<p id="p406479769165632"><a name="p406479769165632"></a><a name="p406479769165632"></a>Obtains the palette of a layer. </p>
</td>
</tr>
<tr id="row1544328355165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2116990613165632"><a name="p2116990613165632"></a><a name="p2116990613165632"></a><a href="layerfuncs.md#a707a6ae5144ee329110822dd8301cb22">SetTransformMode</a> )(uint32_t devId, uint32_t layerId, <a href="display.md#gaa65f3b21a9a92ff022e435a7304126d2">TransformType</a> type)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1993660039165632"><a name="p1993660039165632"></a><a name="p1993660039165632"></a>int32_t(* </p>
<p id="p695222559165632"><a name="p695222559165632"></a><a name="p695222559165632"></a>Sets the transform mode for a layer. </p>
</td>
</tr>
<tr id="row104004166165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p570651751165632"><a name="p570651751165632"></a><a name="p570651751165632"></a><a href="layerfuncs.md#a46c9750d8615dc874b66ac4b10796b24">SetLayerCompression</a> )(uint32_t devId, uint32_t layerId, int32_t compType)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p946995662165632"><a name="p946995662165632"></a><a name="p946995662165632"></a>int32_t(* </p>
<p id="p1752638861165632"><a name="p1752638861165632"></a><a name="p1752638861165632"></a>Sets the compression feature for a layer. </p>
</td>
</tr>
<tr id="row89810929165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1482763558165632"><a name="p1482763558165632"></a><a name="p1482763558165632"></a><a href="layerfuncs.md#ab0b5855ea4ee5228516303cba84907ce">GetLayerCompression</a> )(uint32_t devId, uint32_t layerId, int32_t *compType)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p561351729165632"><a name="p561351729165632"></a><a name="p561351729165632"></a>int32_t(* </p>
<p id="p520830496165632"><a name="p520830496165632"></a><a name="p520830496165632"></a>Checks whether the compression feature is enabled for a layer. </p>
</td>
</tr>
<tr id="row261549797165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1627275690165632"><a name="p1627275690165632"></a><a name="p1627275690165632"></a><a href="layerfuncs.md#a7aa2a7bf4c0aed948c8617adec2d91b6">SetLayerDirtyRegion</a> )(uint32_t devId, uint32_t layerId, <a href="irect.md">IRect</a> *region)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1774784784165632"><a name="p1774784784165632"></a><a name="p1774784784165632"></a>int32_t(* </p>
<p id="p801282441165632"><a name="p801282441165632"></a><a name="p801282441165632"></a>Sets the flushing area for a layer. </p>
</td>
</tr>
<tr id="row1089202806165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1371025427165632"><a name="p1371025427165632"></a><a name="p1371025427165632"></a><a href="layerfuncs.md#a40b406f6b4e6a812a36605041e0e81d6">GetLayerBuffer</a> )(uint32_t devId, uint32_t layerId, <a href="layerbuffer.md">LayerBuffer</a> *buffer)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p400539131165632"><a name="p400539131165632"></a><a name="p400539131165632"></a>int32_t(* </p>
<p id="p1439488622165632"><a name="p1439488622165632"></a><a name="p1439488622165632"></a>Obtains the buffer of a layer. </p>
</td>
</tr>
<tr id="row1286168019165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p779321055165632"><a name="p779321055165632"></a><a name="p779321055165632"></a><a href="layerfuncs.md#abb480bf2b85e93841c49fdc9800bd1e7">Flush</a> )(uint32_t devId, uint32_t layerId, <a href="layerbuffer.md">LayerBuffer</a> *buffer)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2138301075165632"><a name="p2138301075165632"></a><a name="p2138301075165632"></a>int32_t(* </p>
<p id="p560012919165632"><a name="p560012919165632"></a><a name="p560012919165632"></a>Flushes a layer. </p>
</td>
</tr>
<tr id="row467068126165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1983506751165632"><a name="p1983506751165632"></a><a name="p1983506751165632"></a><a href="layerfuncs.md#a62471eb83a24d0a84dabd53018666336">WaitForVBlank</a> )(uint32_t devId, uint32_t layerId)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p743253164165632"><a name="p743253164165632"></a><a name="p743253164165632"></a>int32_t(* </p>
<p id="p967340636165632"><a name="p967340636165632"></a><a name="p967340636165632"></a>Waits for the arrival of vertical blanking. </p>
</td>
</tr>
<tr id="row571211666165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1391784900165632"><a name="p1391784900165632"></a><a name="p1391784900165632"></a><a href="layerfuncs.md#a751377d6d1877cd9e878208b94339407">SnapShot</a> )(uint32_t devId, <a href="layerbuffer.md">LayerBuffer</a> *buffer)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p552083191165632"><a name="p552083191165632"></a><a name="p552083191165632"></a>int32_t(* </p>
<p id="p1645559931165632"><a name="p1645559931165632"></a><a name="p1645559931165632"></a>Implements the snapshot feature. </p>
</td>
</tr>
</tbody>
</table>

## **Details**<a name="section1254774471165632"></a>

## **Field **<a name="section842552881165632"></a>

## CloseLayer<a name="a2e375f75209da329f131b914377e9616"></a>

```
int32_t(* LayerFuncs::CloseLayer) (uint32_t devId, uint32_t layerId)
```

 **Description:**

Closes a layer that is no longer required on a specified display device. 

**Parameters:**

<a name="table1543595533165632"></a>
<table><thead align="left"><tr id="row2001520136165632"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1694287780165632"><a name="p1694287780165632"></a><a name="p1694287780165632"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1387666572165632"><a name="p1387666572165632"></a><a name="p1387666572165632"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row778608164165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">devId</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the ID of a display device. The value ranges from 0 to 4, where 0 indicates the first display device and 4 indicates the last display device. </td>
</tr>
<tr id="row2145427547165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">layerId</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the layer ID, which identifies a unique layer. You can perform operations on the layer with the specified layer ID.</td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the operation is successful; returns an error code defined in  [DispErrCode](display.md#ga12a925dadef7573cd74d63d06824f9b0)  otherwise. 

**See also:**

[OpenLayer](layerfuncs.md#a795f4e168d5b284a9c33f636c278207f) 

## DeinitDisplay<a name="a8d7a715d7d2b4bd5ab0db92c2a1eec93"></a>

```
int32_t(* LayerFuncs::DeinitDisplay) (uint32_t devId)
```

 **Description:**

Deinitializes a display device. 

**Parameters:**

<a name="table1026652908165632"></a>
<table><thead align="left"><tr id="row2074731672165632"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1991670606165632"><a name="p1991670606165632"></a><a name="p1991670606165632"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1820889927165632"><a name="p1820889927165632"></a><a name="p1820889927165632"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1345934411165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">devId</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the ID of a display device. The value ranges from 0 to 4, where 0 indicates the first display device and 4 indicates the last display device.</td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the operation is successful; returns an error code defined in  [DispErrCode](display.md#ga12a925dadef7573cd74d63d06824f9b0)  otherwise. 

**See also:**

[InitDisplay](layerfuncs.md#a0641c3b48542646daa80386122bed46a) 

## Flush<a name="abb480bf2b85e93841c49fdc9800bd1e7"></a>

```
int32_t(* LayerFuncs::Flush) (uint32_t devId, uint32_t layerId, [LayerBuffer](layerbuffer.md) *buffer)
```

 **Description:**

Flushes a layer. 

Display data in the buffer is flushed to a specified layer so that the image data is displayed on the screen.

**Parameters:**

<a name="table994405926165632"></a>
<table><thead align="left"><tr id="row35876642165632"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p2093702722165632"><a name="p2093702722165632"></a><a name="p2093702722165632"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p739143352165632"><a name="p739143352165632"></a><a name="p739143352165632"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row179084474165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">devId</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the ID of a display device. The value ranges from 0 to 4, where 0 indicates the first display device and 4 indicates the last display device. </td>
</tr>
<tr id="row205903523165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">layerId</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the layer ID, which identifies a unique layer. You can perform operations on the layer with the specified layer ID. </td>
</tr>
<tr id="row44630898165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">buffer</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the buffer in which the display data is to flush.</td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the operation is successful; returns an error code defined in  [DispErrCode](display.md#ga12a925dadef7573cd74d63d06824f9b0)  otherwise. 

## GetDisplayInfo<a name="aba57e2b79df0e774727d0c07ef90e715"></a>

```
int32_t(* LayerFuncs::GetDisplayInfo) (uint32_t devId, [DisplayInfo](displayinfo.md) *dispInfo)
```

 **Description:**

Obtains information about a display device. 

**Parameters:**

<a name="table263128525165632"></a>
<table><thead align="left"><tr id="row1135218235165632"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p391449563165632"><a name="p391449563165632"></a><a name="p391449563165632"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1797543351165632"><a name="p1797543351165632"></a><a name="p1797543351165632"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row117838762165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">devId</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the ID of a display device. The value ranges from 0 to 4, where 0 indicates the first display device and 4 indicates the last display device. </td>
</tr>
<tr id="row138769489165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">dispInfo</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the display device information obtained.</td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the operation is successful; returns an error code defined in  [DispErrCode](display.md#ga12a925dadef7573cd74d63d06824f9b0)  otherwise. 

## GetLayerAlpha<a name="acf1e01338eeb0fd957f53ed0d2551394"></a>

```
int32_t(* LayerFuncs::GetLayerAlpha) (uint32_t devId, uint32_t layerId, [LayerAlpha](layeralpha.md) *alpha)
```

 **Description:**

Obtains the alpha value of a layer. 

**Parameters:**

<a name="table1439325851165632"></a>
<table><thead align="left"><tr id="row397862873165632"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1373664093165632"><a name="p1373664093165632"></a><a name="p1373664093165632"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1754053907165632"><a name="p1754053907165632"></a><a name="p1754053907165632"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1605829911165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">devId</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the ID of a display device. The value ranges from 0 to 4, where 0 indicates the first display device and 4 indicates the last display device. </td>
</tr>
<tr id="row1866545992165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">layerId</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the layer ID, which identifies a unique layer. You can perform operations on the layer with the specified layer ID. </td>
</tr>
<tr id="row1462115906165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">alpha</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the obtained alpha value.</td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the operation is successful; returns an error code defined in  [DispErrCode](display.md#ga12a925dadef7573cd74d63d06824f9b0)  otherwise. 

**See also:**

[SetLayerAlpha](layerfuncs.md#a20e554afa2f7b1015fd23ce240344b13) 

## GetLayerBuffer<a name="a40b406f6b4e6a812a36605041e0e81d6"></a>

```
int32_t(* LayerFuncs::GetLayerBuffer) (uint32_t devId, uint32_t layerId, [LayerBuffer](layerbuffer.md) *buffer)
```

 **Description:**

Obtains the buffer of a layer. 

After drawing a picture in the buffer, the application calls the  [Flush](layerfuncs.md#abb480bf2b85e93841c49fdc9800bd1e7)  function to display the picture on the screen.

**Parameters:**

<a name="table1348421142165632"></a>
<table><thead align="left"><tr id="row1171246490165632"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p2053695463165632"><a name="p2053695463165632"></a><a name="p2053695463165632"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1471384937165632"><a name="p1471384937165632"></a><a name="p1471384937165632"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row341204274165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">devId</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the ID of a display device. The value ranges from 0 to 4, where 0 indicates the first display device and 4 indicates the last display device. </td>
</tr>
<tr id="row1552051472165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">layerId</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the layer ID, which identifies a unique layer. You can perform operations on the layer with the specified layer ID. </td>
</tr>
<tr id="row138282383165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">buffer</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the obtained buffer.</td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the operation is successful; returns an error code defined in  [DispErrCode](display.md#ga12a925dadef7573cd74d63d06824f9b0)  otherwise. 

**See also:**

[Flush](layerfuncs.md#abb480bf2b85e93841c49fdc9800bd1e7) 

## GetLayerColorKey<a name="aea882232b6279b8be82c45e889187b24"></a>

```
int32_t(* LayerFuncs::GetLayerColorKey) (uint32_t devId, uint32_t layerId, bool *enable, uint32_t *key)
```

 **Description:**

Obtains the color key of a layer. 

**Parameters:**

<a name="table1350827177165632"></a>
<table><thead align="left"><tr id="row427901484165632"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p762682896165632"><a name="p762682896165632"></a><a name="p762682896165632"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p803693059165632"><a name="p803693059165632"></a><a name="p803693059165632"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row543067608165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">devId</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the ID of a display device. The value ranges from 0 to 4, where 0 indicates the first display device and 4 indicates the last display device. </td>
</tr>
<tr id="row1443545850165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">layerId</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the layer ID, which identifies a unique layer. You can perform operations on the layer with the specified layer ID. </td>
</tr>
<tr id="row1556012687165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">enable</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the color key enable bit. </td>
</tr>
<tr id="row626983832165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">key</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the color key.</td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the operation is successful; returns an error code defined in  [DispErrCode](display.md#ga12a925dadef7573cd74d63d06824f9b0)  otherwise. 

**See also:**

[SetLayerColorKey](layerfuncs.md#a5701fe1e0e2414de577aa5329bd873c9) 

## GetLayerCompression<a name="ab0b5855ea4ee5228516303cba84907ce"></a>

```
int32_t(* LayerFuncs::GetLayerCompression) (uint32_t devId, uint32_t layerId, int32_t *compType)
```

 **Description:**

Checks whether the compression feature is enabled for a layer. 

**Parameters:**

<a name="table542056827165632"></a>
<table><thead align="left"><tr id="row487002658165632"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1220304861165632"><a name="p1220304861165632"></a><a name="p1220304861165632"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1508444401165632"><a name="p1508444401165632"></a><a name="p1508444401165632"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1243289081165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">devId</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the ID of a display device. The value ranges from 0 to 4, where 0 indicates the first display device and 4 indicates the last display device. </td>
</tr>
<tr id="row1450196693165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">layerId</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the layer ID, which identifies a unique layer. You can perform operations on the layer with the specified layer ID. </td>
</tr>
<tr id="row1862275282165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">compType</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the variable specifying whether the compression feature is enabled.</td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the operation is successful; returns an error code defined in  [DispErrCode](display.md#ga12a925dadef7573cd74d63d06824f9b0)  otherwise. 

**See also:**

[SetLayerCompression](layerfuncs.md#a46c9750d8615dc874b66ac4b10796b24) 

## GetLayerPalette<a name="af713bc39e51dc8168c278e2f126bf4e3"></a>

```
int32_t(* LayerFuncs::GetLayerPalette) (uint32_t devId, uint32_t layerId, uint32_t *palette, uint32_t len)
```

 **Description:**

Obtains the palette of a layer. 

**Parameters:**

<a name="table1635925912165632"></a>
<table><thead align="left"><tr id="row958887735165632"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p754930819165632"><a name="p754930819165632"></a><a name="p754930819165632"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p136655908165632"><a name="p136655908165632"></a><a name="p136655908165632"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1045735785165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">devId</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the ID of a display device. The value ranges from 0 to 4, where 0 indicates the first display device and 4 indicates the last display device. </td>
</tr>
<tr id="row146029879165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">layerId</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the layer ID, which identifies a unique layer. You can perform operations on the layer with the specified layer ID. </td>
</tr>
<tr id="row1483284433165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">palette</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the obtained palette. </td>
</tr>
<tr id="row1048054295165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">len</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the length of the palette.</td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the operation is successful; returns an error code defined in  [DispErrCode](display.md#ga12a925dadef7573cd74d63d06824f9b0)  otherwise. 

**See also:**

[SetLayerPalette](layerfuncs.md#a3982c76e093852ef386fc372581be4af) 

## GetLayerPreMulti<a name="a4a0e26f8401da1232f03bb37502ff4bd"></a>

```
int32_t(* LayerFuncs::GetLayerPreMulti) (uint32_t devId, uint32_t layerId, bool *preMul)
```

 **Description:**

Obtains the premultiplication flag of a layer. 

**Parameters:**

<a name="table616179908165632"></a>
<table><thead align="left"><tr id="row1415840647165632"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1549025456165632"><a name="p1549025456165632"></a><a name="p1549025456165632"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1097809392165632"><a name="p1097809392165632"></a><a name="p1097809392165632"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row696578945165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">devId</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the ID of a display device. The value ranges from 0 to 4, where 0 indicates the first display device and 4 indicates the last display device. </td>
</tr>
<tr id="row1612655977165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">layerId</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the layer ID, which identifies a unique layer. You can perform operations on the layer with the specified layer ID. </td>
</tr>
<tr id="row1262535181165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">preMul</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the obtained layer premultiplication flag.</td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the operation is successful; returns an error code defined in  [DispErrCode](display.md#ga12a925dadef7573cd74d63d06824f9b0)  otherwise. 

**See also:**

[SetLayerPreMulti](layerfuncs.md#a456aa01ca3ffa81d2e49c0a9487f816f) 

## GetLayerSize<a name="a56be84be25eba64497b2a842c1f68b26"></a>

```
int32_t(* LayerFuncs::GetLayerSize) (uint32_t devId, uint32_t layerId, [IRect](irect.md) *rect)
```

 **Description:**

Obtains the size of a layer. 

**Parameters:**

<a name="table1353183840165632"></a>
<table><thead align="left"><tr id="row2124507491165632"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p426355063165632"><a name="p426355063165632"></a><a name="p426355063165632"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1168547281165632"><a name="p1168547281165632"></a><a name="p1168547281165632"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row419257842165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">devId</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the ID of a display device. The value ranges from 0 to 4, where 0 indicates the first display device and 4 indicates the last display device. </td>
</tr>
<tr id="row233338385165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">layerId</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the layer ID, which identifies a unique layer. You can perform operations on the layer with the specified layer ID. </td>
</tr>
<tr id="row758714466165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">rect</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the obtained layer size.</td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the operation is successful; returns an error code defined in  [DispErrCode](display.md#ga12a925dadef7573cd74d63d06824f9b0)  otherwise. 

**See also:**

[SetLayerSize](layerfuncs.md#ab58e66b0676b1baa1662c175d43bf219) 

## GetLayerVisibleState<a name="a6bbff71bb4f17eb84a4db4857a0b0985"></a>

```
int32_t(* LayerFuncs::GetLayerVisibleState) (uint32_t devId, uint32_t layerId, bool *visible)
```

 **Description:**

Checks whether a layer is visible. 

**Parameters:**

<a name="table370119135165632"></a>
<table><thead align="left"><tr id="row1489135666165632"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p58371982165632"><a name="p58371982165632"></a><a name="p58371982165632"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1369391298165632"><a name="p1369391298165632"></a><a name="p1369391298165632"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row256981253165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">devId</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the ID of a display device. The value ranges from 0 to 4, where 0 indicates the first display device and 4 indicates the last display device. </td>
</tr>
<tr id="row91178558165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">layerId</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the layer ID, which identifies a unique layer. You can perform operations on the layer with the specified layer ID. </td>
</tr>
<tr id="row1772674410165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">visible</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the obtained layer visibility. The value <strong id="b1681905426165632"><a name="b1681905426165632"></a><a name="b1681905426165632"></a>true</strong> indicates that the layer is visible, and <strong id="b423449687165632"><a name="b423449687165632"></a><a name="b423449687165632"></a>false</strong> indicates that the layer is invisible.</td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the operation is successful; returns an error code defined in  [DispErrCode](display.md#ga12a925dadef7573cd74d63d06824f9b0)  otherwise. 

**See also:**

[SetLayerVisible](layerfuncs.md#aaa5bf7f98e8dc47510a4f26fb38094b6) 

## GetLayerZorder<a name="a5644645442e1d6943b55ce0a6a801b8c"></a>

```
int32_t(* LayerFuncs::GetLayerZorder) (uint32_t devId, uint32_t layerId, uint32_t *zorder)
```

 **Description:**

Obtains the z-order of a layer. 

**Parameters:**

<a name="table968445522165632"></a>
<table><thead align="left"><tr id="row929647316165632"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p2009650758165632"><a name="p2009650758165632"></a><a name="p2009650758165632"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p428027686165632"><a name="p428027686165632"></a><a name="p428027686165632"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1137775505165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">devId</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the ID of a display device. The value ranges from 0 to 4, where 0 indicates the first display device and 4 indicates the last display device. </td>
</tr>
<tr id="row2008385577165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">layerId</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the layer ID, which identifies a unique layer. You can perform operations on the layer with the specified layer ID. </td>
</tr>
<tr id="row696025880165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">zorder</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the obtained z-order. The value is an integer ranging from 0 to 255. A larger z-order value indicates a higher layer.</td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the operation is successful; returns an error code defined in  [DispErrCode](display.md#ga12a925dadef7573cd74d63d06824f9b0)  otherwise. 

**See also:**

[SetLayerZorder](layerfuncs.md#aa3803c2a6395651d1538ffb62d29733d) 

## InitDisplay<a name="a0641c3b48542646daa80386122bed46a"></a>

```
int32_t(* LayerFuncs::InitDisplay) (uint32_t devId)
```

 **Description:**

Initializes a display device. 

**Parameters:**

<a name="table522033989165632"></a>
<table><thead align="left"><tr id="row164199436165632"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1487169002165632"><a name="p1487169002165632"></a><a name="p1487169002165632"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p452841967165632"><a name="p452841967165632"></a><a name="p452841967165632"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row2050888031165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">devId</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the ID of a display device. The value ranges from 0 to 4, where 0 indicates the first display device and 4 indicates the last display device.</td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the operation is successful; returns an error code defined in  [DispErrCode](display.md#ga12a925dadef7573cd74d63d06824f9b0)  otherwise. 

**See also:**

[DeinitDisplay](layerfuncs.md#a8d7a715d7d2b4bd5ab0db92c2a1eec93) 

## OpenLayer<a name="a795f4e168d5b284a9c33f636c278207f"></a>

```
int32_t(* LayerFuncs::OpenLayer) (uint32_t devId, const [LayerInfo](layerinfo.md) *layerInfo, uint32_t *layerId)
```

 **Description:**

Opens a layer on a specified display device. 

Before using a layer on the GUI, you must open the layer based on the layer information. After the layer is opened, you can obtain the layer ID and then use other functions based on the layer ID.

**Parameters:**

<a name="table130037253165632"></a>
<table><thead align="left"><tr id="row1669611452165632"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p284218685165632"><a name="p284218685165632"></a><a name="p284218685165632"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p575864446165632"><a name="p575864446165632"></a><a name="p575864446165632"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row731067643165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">devId</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the ID of a display device. The value ranges from 0 to 4, where 0 indicates the first display device and 4 indicates the last display device. </td>
</tr>
<tr id="row1090728391165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">layerInfo</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the layer information passed to open a layer, including the layer type, layer size, and pixel format. </td>
</tr>
<tr id="row1976993297165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">layerId</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the layer ID, which identifies a unique layer. The layer ID is returned to the GUI after the layer is successfully opened.</td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the operation is successful; returns an error code defined in  [DispErrCode](display.md#ga12a925dadef7573cd74d63d06824f9b0)  otherwise. 

**See also:**

[CloseLayer](layerfuncs.md#a2e375f75209da329f131b914377e9616) 

## SetLayerAlpha<a name="a20e554afa2f7b1015fd23ce240344b13"></a>

```
int32_t(* LayerFuncs::SetLayerAlpha) (uint32_t devId, uint32_t layerid, [LayerAlpha](layeralpha.md) *alpha)
```

 **Description:**

Sets the alpha value for a layer. 

**Parameters:**

<a name="table2012063560165632"></a>
<table><thead align="left"><tr id="row1755239717165632"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p314670388165632"><a name="p314670388165632"></a><a name="p314670388165632"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1343730291165632"><a name="p1343730291165632"></a><a name="p1343730291165632"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row425638363165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">devId</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the ID of a display device. The value ranges from 0 to 4, where 0 indicates the first display device and 4 indicates the last display device. </td>
</tr>
<tr id="row1967990612165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">layerId</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the layer ID, which identifies a unique layer. You can perform operations on the layer with the specified layer ID. </td>
</tr>
<tr id="row1831638060165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">alpha</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the alpha value to set.</td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the operation is successful; returns an error code defined in  [DispErrCode](display.md#ga12a925dadef7573cd74d63d06824f9b0)  otherwise. 

**See also:**

[GetLayerAlpha](layerfuncs.md#acf1e01338eeb0fd957f53ed0d2551394) 

## SetLayerColorKey<a name="a5701fe1e0e2414de577aa5329bd873c9"></a>

```
int32_t(* LayerFuncs::SetLayerColorKey) (uint32_t devId, uint32_t layerId, bool enable, uint32_t key)
```

 **Description:**

Sets the color key for a layer. 

The color key is used during layer overlay.

**Parameters:**

<a name="table645358519165632"></a>
<table><thead align="left"><tr id="row189145125165632"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p257833452165632"><a name="p257833452165632"></a><a name="p257833452165632"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p923730273165632"><a name="p923730273165632"></a><a name="p923730273165632"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row421024386165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">devId</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the ID of a display device. The value ranges from 0 to 4, where 0 indicates the first display device and 4 indicates the last display device. </td>
</tr>
<tr id="row1226927131165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">layerId</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the layer ID, which identifies a unique layer. You can perform operations on the layer with the specified layer ID. </td>
</tr>
<tr id="row331508620165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">enable</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Specify whether to enable the color key. </td>
</tr>
<tr id="row68944013165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">key</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the color key.</td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the operation is successful; returns an error code defined in  [DispErrCode](display.md#ga12a925dadef7573cd74d63d06824f9b0)  otherwise. 

**See also:**

[GetLayerColorKey](layerfuncs.md#aea882232b6279b8be82c45e889187b24) 

## SetLayerCompression<a name="a46c9750d8615dc874b66ac4b10796b24"></a>

```
int32_t(* LayerFuncs::SetLayerCompression) (uint32_t devId, uint32_t layerId, int32_t compType)
```

 **Description:**

Sets the compression feature for a layer. 

In specific scenarios, images need to be compressed. You can set whether to enable layer compression.

**Parameters:**

<a name="table1308655503165632"></a>
<table><thead align="left"><tr id="row1199143037165632"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p2144331036165632"><a name="p2144331036165632"></a><a name="p2144331036165632"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p287892948165632"><a name="p287892948165632"></a><a name="p287892948165632"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row753621167165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">devId</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the ID of a display device. The value ranges from 0 to 4, where 0 indicates the first display device and 4 indicates the last display device. </td>
</tr>
<tr id="row652942403165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">layerId</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the layer ID, which identifies a unique layer. You can perform operations on the layer with the specified layer ID. </td>
</tr>
<tr id="row55705039165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">compType</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Specifies whether to enable the compression feature. The value <strong id="b470304678165632"><a name="b470304678165632"></a><a name="b470304678165632"></a>true&gt;/b&gt; means to enable compression, and <strong id="b1667671797165632"><a name="b1667671797165632"></a><a name="b1667671797165632"></a>false&gt; means the opposite.</strong></strong></td>
</tr>
</tbody>
</table>

**Returns:**

**** Returns  **0**  if the operation is successful; returns an error code defined in  [DispErrCode](display.md#ga12a925dadef7573cd74d63d06824f9b0)  otherwise. ****

**See also:**

**** [GetLayerCompression](layerfuncs.md#ab0b5855ea4ee5228516303cba84907ce) ****

## SetLayerCrop<a name="a4f925226529e27678df19423fa6f83ad"></a>

```
int32_t(* LayerFuncs::SetLayerCrop) (uint32_t devId, uint32_t layerId, [IRect](irect.md) *rect)
```

 **Description:**

Sets the rectangular area to crop for a layer. 

**Parameters:**

<a name="table162377769165632"></a>
<table><thead align="left"><tr id="row1122391440165632"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p679024085165632"><a name="p679024085165632"></a><a name="p679024085165632"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p640193311165632"><a name="p640193311165632"></a><a name="p640193311165632"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1655630920165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">devId</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the ID of a display device. The value ranges from 0 to 4, where 0 indicates the first display device and 4 indicates the last display device. </td>
</tr>
<tr id="row331436421165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">layerId</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the layer ID, which identifies a unique layer. You can perform operations on the layer with the specified layer ID. </td>
</tr>
<tr id="row1523611326165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">rect</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the rectangular area to crop.</td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the operation is successful; returns an error code defined in  [DispErrCode](display.md#ga12a925dadef7573cd74d63d06824f9b0)  otherwise. 

## SetLayerDirtyRegion<a name="a7aa2a7bf4c0aed948c8617adec2d91b6"></a>

```
int32_t(* LayerFuncs::SetLayerDirtyRegion) (uint32_t devId, uint32_t layerId, [IRect](irect.md) *region)
```

 **Description:**

Sets the flushing area for a layer. 

After the GUI draws an image, you must set the layer flushing area before calling the  [Flush](layerfuncs.md#abb480bf2b85e93841c49fdc9800bd1e7)  function to flush the screen.

**Parameters:**

<a name="table1801969045165632"></a>
<table><thead align="left"><tr id="row1663077745165632"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1836881250165632"><a name="p1836881250165632"></a><a name="p1836881250165632"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1529161025165632"><a name="p1529161025165632"></a><a name="p1529161025165632"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1475840241165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">devId</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the ID of a display device. The value ranges from 0 to 4, where 0 indicates the first display device and 4 indicates the last display device. </td>
</tr>
<tr id="row277870572165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">layerId</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the layer ID, which identifies a unique layer. You can perform operations on the layer with the specified layer ID. </td>
</tr>
<tr id="row1591614914165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">region</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the flushing area to set.</td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the operation is successful; returns an error code defined in  [DispErrCode](display.md#ga12a925dadef7573cd74d63d06824f9b0)  otherwise. 

## SetLayerPalette<a name="a3982c76e093852ef386fc372581be4af"></a>

```
int32_t(* LayerFuncs::SetLayerPalette) (uint32_t devId, uint32_t layerId, uint32_t *palette, uint32_t len)
```

 **Description:**

Sets the palette for a layer. 

**Parameters:**

<a name="table671065619165632"></a>
<table><thead align="left"><tr id="row1217800922165632"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1985161606165632"><a name="p1985161606165632"></a><a name="p1985161606165632"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p784321697165632"><a name="p784321697165632"></a><a name="p784321697165632"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1906107364165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">devId</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the ID of a display device. The value ranges from 0 to 4, where 0 indicates the first display device and 4 indicates the last display device. </td>
</tr>
<tr id="row351607033165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">layerId</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the layer ID, which identifies a unique layer. You can perform operations on the layer with the specified layer ID. </td>
</tr>
<tr id="row1560984140165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">palette</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the palette to set. </td>
</tr>
<tr id="row506285705165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">len</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the length of the palette.</td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the operation is successful; returns an error code defined in  [DispErrCode](display.md#ga12a925dadef7573cd74d63d06824f9b0)  otherwise. 

**See also:**

[GetLayerPalette](layerfuncs.md#af713bc39e51dc8168c278e2f126bf4e3) 

## SetLayerPreMulti<a name="a456aa01ca3ffa81d2e49c0a9487f816f"></a>

```
int32_t(* LayerFuncs::SetLayerPreMulti) (uint32_t devId, uint32_t layerId, bool preMul)
```

 **Description:**

Sets layer premultiplication. 

**Parameters:**

<a name="table601571774165632"></a>
<table><thead align="left"><tr id="row6243236165632"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1525658278165632"><a name="p1525658278165632"></a><a name="p1525658278165632"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1982844636165632"><a name="p1982844636165632"></a><a name="p1982844636165632"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1783019805165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">devId</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the ID of a display device. The value ranges from 0 to 4, where 0 indicates the first display device and 4 indicates the last display device. </td>
</tr>
<tr id="row354478546165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">layerId</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the layer ID, which identifies a unique layer. You can perform operations on the layer with the specified layer ID. </td>
</tr>
<tr id="row2066096111165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">preMul</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Specifies whether to enable layer premultiplication. The value <strong id="b461516838165632"><a name="b461516838165632"></a><a name="b461516838165632"></a>1</strong> means to enable layer premultiplication, and <strong id="b2060729092165632"><a name="b2060729092165632"></a><a name="b2060729092165632"></a>0</strong> means the opposite.</td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the operation is successful; returns an error code defined in  [DispErrCode](display.md#ga12a925dadef7573cd74d63d06824f9b0)  otherwise. 

**See also:**

[GetLayerPreMulti](layerfuncs.md#a4a0e26f8401da1232f03bb37502ff4bd) 

## SetLayerSize<a name="ab58e66b0676b1baa1662c175d43bf219"></a>

```
int32_t(* LayerFuncs::SetLayerSize) (uint32_t devId, uint32_t layerId, [IRect](irect.md) *rect)
```

 **Description:**

Sets the size of a layer. 

**Parameters:**

<a name="table1979944501165632"></a>
<table><thead align="left"><tr id="row2095509444165632"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p2069899076165632"><a name="p2069899076165632"></a><a name="p2069899076165632"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p477476387165632"><a name="p477476387165632"></a><a name="p477476387165632"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row924999879165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">devId</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the ID of a display device. The value ranges from 0 to 4, where 0 indicates the first display device and 4 indicates the last display device. </td>
</tr>
<tr id="row1128167314165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">layerId</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the layer ID, which identifies a unique layer. You can perform operations on the layer with the specified layer ID. </td>
</tr>
<tr id="row1562768966165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">rect</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the layer size to set, in pixels.</td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the operation is successful; returns an error code defined in  [DispErrCode](display.md#ga12a925dadef7573cd74d63d06824f9b0)  otherwise. 

**See also:**

[GetLayerSize](layerfuncs.md#a56be84be25eba64497b2a842c1f68b26) 

## SetLayerVisible<a name="aaa5bf7f98e8dc47510a4f26fb38094b6"></a>

```
int32_t(* LayerFuncs::SetLayerVisible) (uint32_t devId, uint32_t layerId, bool visible)
```

 **Description:**

Sets whether a layer is visible. 

A visible layer is displayed on the screen, whereas an invisible layer is not displayed on the screen.

**Parameters:**

<a name="table1957727469165632"></a>
<table><thead align="left"><tr id="row874087480165632"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p481865325165632"><a name="p481865325165632"></a><a name="p481865325165632"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p736373667165632"><a name="p736373667165632"></a><a name="p736373667165632"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row167749751165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">devId</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the ID of a display device. The value ranges from 0 to 4, where 0 indicates the first display device and 4 indicates the last display device. </td>
</tr>
<tr id="row469878754165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">layerId</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the layer ID, which identifies a unique layer. You can perform operations on the layer with the specified layer ID. </td>
</tr>
<tr id="row1577395807165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">visible</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the visibility to set for the layer. The value <strong id="b814844275165632"><a name="b814844275165632"></a><a name="b814844275165632"></a>true</strong> means to set the layer to be visible, and <strong id="b622636045165632"><a name="b622636045165632"></a><a name="b622636045165632"></a>false</strong> means the opposite.</td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the operation is successful; returns an error code defined in  [DispErrCode](display.md#ga12a925dadef7573cd74d63d06824f9b0)  otherwise. 

**See also:**

[GetLayerVisibleState](layerfuncs.md#a6bbff71bb4f17eb84a4db4857a0b0985) 

## SetLayerZorder<a name="aa3803c2a6395651d1538ffb62d29733d"></a>

```
int32_t(* LayerFuncs::SetLayerZorder) (uint32_t devId, uint32_t layerId, uint32_t zorder)
```

 **Description:**

Sets the z-order for a layer. 

A larger z-order value indicates a higher layer.

**Parameters:**

<a name="table1579188095165632"></a>
<table><thead align="left"><tr id="row650560101165632"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1907023334165632"><a name="p1907023334165632"></a><a name="p1907023334165632"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1991118280165632"><a name="p1991118280165632"></a><a name="p1991118280165632"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1757665471165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">devId</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the ID of a display device. The value ranges from 0 to 4, where 0 indicates the first display device and 4 indicates the last display device. </td>
</tr>
<tr id="row2037022355165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">layerId</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the layer ID, which identifies a unique layer. You can perform operations on the layer with the specified layer ID. </td>
</tr>
<tr id="row470799747165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">zorder</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the z-order to set. The value is an integer ranging from 0 to 255.</td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the operation is successful; returns an error code defined in  [DispErrCode](display.md#ga12a925dadef7573cd74d63d06824f9b0)  otherwise. 

**See also:**

[GetLayerZorder](layerfuncs.md#a5644645442e1d6943b55ce0a6a801b8c) 

## SetTransformMode<a name="a707a6ae5144ee329110822dd8301cb22"></a>

```
int32_t(* LayerFuncs::SetTransformMode) (uint32_t devId, uint32_t layerId, [TransformType](display.md#gaa65f3b21a9a92ff022e435a7304126d2) type)
```

 **Description:**

Sets the transform mode for a layer. 

Using this function, you can rotate, scale, and move the layer.

**Parameters:**

<a name="table1479840475165632"></a>
<table><thead align="left"><tr id="row1694749250165632"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p2132146789165632"><a name="p2132146789165632"></a><a name="p2132146789165632"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p277087714165632"><a name="p277087714165632"></a><a name="p277087714165632"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1767242757165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">devId</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the ID of a display device. The value ranges from 0 to 4, where 0 indicates the first display device and 4 indicates the last display device. </td>
</tr>
<tr id="row351173926165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">layerId</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the layer ID, which identifies a unique layer. You can perform operations on the layer with the specified layer ID. </td>
</tr>
<tr id="row1813270144165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">type</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the transformation mode to set.</td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the operation is successful; returns an error code defined in  [DispErrCode](display.md#ga12a925dadef7573cd74d63d06824f9b0)  otherwise. 

## SnapShot<a name="a751377d6d1877cd9e878208b94339407"></a>

```
int32_t(* LayerFuncs::SnapShot) (uint32_t devId, [LayerBuffer](layerbuffer.md) *buffer)
```

 **Description:**

Implements the snapshot feature. 

This function saves the screenshot of image data on the display device to the buffer for debugging or as requested by applications.

**Parameters:**

<a name="table1598492285165632"></a>
<table><thead align="left"><tr id="row727492661165632"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1818590863165632"><a name="p1818590863165632"></a><a name="p1818590863165632"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1185180406165632"><a name="p1185180406165632"></a><a name="p1185180406165632"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1463998420165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">devId</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the ID of a display device. The value ranges from 0 to 4, where 0 indicates the first display device and 4 indicates the last display device. </td>
</tr>
<tr id="row377506788165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">buffer</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the pointer to the buffer for saving screenshots.</td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the operation is successful; returns an error code defined in  [DispErrCode](display.md#ga12a925dadef7573cd74d63d06824f9b0)  otherwise. 

## WaitForVBlank<a name="a62471eb83a24d0a84dabd53018666336"></a>

```
int32_t(* LayerFuncs::WaitForVBlank) (uint32_t devId, uint32_t layerId)
```

 **Description:**

Waits for the arrival of vertical blanking. 

This function blocks the process until vertical blanking arrives, implementing the synchronization between software and hardware.

**Parameters:**

<a name="table1187792229165632"></a>
<table><thead align="left"><tr id="row1214475599165632"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1194080327165632"><a name="p1194080327165632"></a><a name="p1194080327165632"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p871726355165632"><a name="p871726355165632"></a><a name="p871726355165632"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row382751366165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">devId</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the ID of a display device. The value ranges from 0 to 4, where 0 indicates the first display device and 4 indicates the last display device. </td>
</tr>
<tr id="row1340217752165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">layerId</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the layer ID, which identifies a unique layer. You can perform operations on the layer with the specified layer ID. </td>
</tr>
<tr id="row422895917165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">timeOut</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">Indicates the maximum duration that the process waits for the arrival of vertical blanking.</td>
</tr>
</tbody>
</table>

**Returns:**

Returns  **0**  if the operation is successful; returns an error code defined in  [DispErrCode](display.md#ga12a925dadef7573cd74d63d06824f9b0)  otherwise. 

