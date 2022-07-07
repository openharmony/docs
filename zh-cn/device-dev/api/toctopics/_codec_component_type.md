# CodecComponentType<a name="ZH-CN_TOPIC_0000001343000849"></a>

## **概述**<a name="section1278200753083931"></a>

**所属模块:**

[Codec](_codec.md)

## **汇总**<a name="section1341491084083931"></a>

## Public 属性<a name="pub-attribs"></a>

<a name="table351373067083931"></a>
<table><thead align="left"><tr id="row1034308228083931"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p749256873083931"><a name="p749256873083931"></a><a name="p749256873083931"></a>Public 属性</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1013293729083931"><a name="p1013293729083931"></a><a name="p1013293729083931"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row892151676083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1722564023083931"><a name="p1722564023083931"></a><a name="p1722564023083931"></a>( <a href="_codec.md#ga4cedc89a7d30bcf20a8cf7a8e2c726ae">GetComponentVersion</a> )(struct <a href="_codec_component_type.md">CodecComponentType</a> *self, struct <a href="_comp_ver_info.md">CompVerInfo</a> *verInfo)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p384527805083931"><a name="p384527805083931"></a><a name="p384527805083931"></a>获取Codec组件版本号。 <a href="_codec.md#ga4cedc89a7d30bcf20a8cf7a8e2c726ae">更多...</a></p>
</td>
</tr>
<tr id="row438235049083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p141393414083931"><a name="p141393414083931"></a><a name="p141393414083931"></a>( <a href="_codec.md#ga7ed960417c546f912f315bed1c7bfb8c">SendCommand</a> )(struct <a href="_codec_component_type.md">CodecComponentType</a> *self, enum OMX_COMMANDTYPE cmd, uint32_t param, int8_t *cmdData, uint32_t cmdDataLen)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1994238333083931"><a name="p1994238333083931"></a><a name="p1994238333083931"></a>发送命令给组件。 <a href="_codec.md#ga7ed960417c546f912f315bed1c7bfb8c">更多...</a></p>
</td>
</tr>
<tr id="row272257862083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1958055302083931"><a name="p1958055302083931"></a><a name="p1958055302083931"></a>( <a href="_codec.md#gaddff94963448ccfbb35eff8b4af2870f">GetParameter</a> )(struct <a href="_codec_component_type.md">CodecComponentType</a> *self, uint32_t paramIndex, int8_t *paramStruct, uint32_t paramStructLen)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2085566128083931"><a name="p2085566128083931"></a><a name="p2085566128083931"></a>获取组件参数设置。 <a href="_codec.md#gaddff94963448ccfbb35eff8b4af2870f">更多...</a></p>
</td>
</tr>
<tr id="row339566048083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2137356793083931"><a name="p2137356793083931"></a><a name="p2137356793083931"></a>( <a href="_codec.md#ga49d3a2d930bd2a985fbf7b936370477f">SetParameter</a> )(struct <a href="_codec_component_type.md">CodecComponentType</a> *self, uint32_t index, int8_t *paramStruct, uint32_t paramStructLen)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1372550139083931"><a name="p1372550139083931"></a><a name="p1372550139083931"></a>设置组件需要的参数。 <a href="_codec.md#ga49d3a2d930bd2a985fbf7b936370477f">更多...</a></p>
</td>
</tr>
<tr id="row2127468865083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p238532543083931"><a name="p238532543083931"></a><a name="p238532543083931"></a>( <a href="_codec.md#gaa01f66a3b96f7247992e661294190033">GetConfig</a> )(struct <a href="_codec_component_type.md">CodecComponentType</a> *self, uint32_t index, int8_t *cfgStruct, uint32_t cfgStructLen)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p893013842083931"><a name="p893013842083931"></a><a name="p893013842083931"></a>获取组件的配置结构。 <a href="_codec.md#gaa01f66a3b96f7247992e661294190033">更多...</a></p>
</td>
</tr>
<tr id="row1340229783083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p639798782083931"><a name="p639798782083931"></a><a name="p639798782083931"></a>( <a href="_codec.md#gad8583f286f333fb79e6c565cc78104f5">SetConfig</a> )(struct <a href="_codec_component_type.md">CodecComponentType</a> *self, uint32_t index, int8_t *cfgStruct, uint32_t cfgStructLen)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1940908086083931"><a name="p1940908086083931"></a><a name="p1940908086083931"></a>设置组件的配置。 <a href="_codec.md#gad8583f286f333fb79e6c565cc78104f5">更多...</a></p>
</td>
</tr>
<tr id="row658310723083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1230958585083931"><a name="p1230958585083931"></a><a name="p1230958585083931"></a>( <a href="_codec.md#ga056ce7fb304f194e348f1cec0268528b">GetExtensionIndex</a> )(struct <a href="_codec_component_type.md">CodecComponentType</a> *self, const char *paramName, uint32_t *indexType)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p230750230083931"><a name="p230750230083931"></a><a name="p230750230083931"></a>根据字符串获取组件的扩展索引。 <a href="_codec.md#ga056ce7fb304f194e348f1cec0268528b">更多...</a></p>
</td>
</tr>
<tr id="row1871138525083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1637847129083931"><a name="p1637847129083931"></a><a name="p1637847129083931"></a>( <a href="_codec.md#ga700e66879ba52e184c6e7fe2c5f18fe5">GetState</a> )(struct <a href="_codec_component_type.md">CodecComponentType</a> *self, enum OMX_STATETYPE *state)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p561596095083931"><a name="p561596095083931"></a><a name="p561596095083931"></a>获取组件的当前状态。 <a href="_codec.md#ga700e66879ba52e184c6e7fe2c5f18fe5">更多...</a></p>
</td>
</tr>
<tr id="row244711407083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p538263255083931"><a name="p538263255083931"></a><a name="p538263255083931"></a>( <a href="_codec.md#ga0dc7db1b92bd299959cc99a347397b5f">ComponentTunnelRequest</a> )(struct <a href="_codec_component_type.md">CodecComponentType</a> *self, uint32_t port, int32_t tunneledComp, uint32_t tunneledPort, struct OMX_TUNNELSETUPTYPE *tunnelSetup)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1137773469083931"><a name="p1137773469083931"></a><a name="p1137773469083931"></a>设置组件采用Tunnel方式通信。 <a href="_codec.md#ga0dc7db1b92bd299959cc99a347397b5f">更多...</a></p>
</td>
</tr>
<tr id="row362359647083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1718143083931"><a name="p1718143083931"></a><a name="p1718143083931"></a>( <a href="_codec.md#gab08568f4724ddaec0581f2211195084d">UseBuffer</a> )(struct <a href="_codec_component_type.md">CodecComponentType</a> *self, uint32_t portIndex, struct <a href="_omx_codec_buffer.md">OmxCodecBuffer</a> *buffer)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1053845779083931"><a name="p1053845779083931"></a><a name="p1053845779083931"></a>指定组件端口的buffer。 <a href="_codec.md#gab08568f4724ddaec0581f2211195084d">更多...</a></p>
</td>
</tr>
<tr id="row615382615083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p469694197083931"><a name="p469694197083931"></a><a name="p469694197083931"></a>( <a href="_codec.md#gaf3186cc84cf9b9429492c44530d4e6ed">AllocateBuffer</a> )(struct <a href="_codec_component_type.md">CodecComponentType</a> *self, uint32_t portIndex, struct <a href="_omx_codec_buffer.md">OmxCodecBuffer</a> *buffer)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p546445801083931"><a name="p546445801083931"></a><a name="p546445801083931"></a>向组件申请端口buffer。 <a href="_codec.md#gaf3186cc84cf9b9429492c44530d4e6ed">更多...</a></p>
</td>
</tr>
<tr id="row1101597619083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1993124356083931"><a name="p1993124356083931"></a><a name="p1993124356083931"></a>( <a href="_codec.md#gaaaa6224e212bc23aa246c1e2fc57ffba">FreeBuffer</a> )(struct <a href="_codec_component_type.md">CodecComponentType</a> *self, uint32_t portIndex, const struct <a href="_omx_codec_buffer.md">OmxCodecBuffer</a> *buffer)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p585721792083931"><a name="p585721792083931"></a><a name="p585721792083931"></a>释放buffer。 <a href="_codec.md#gaaaa6224e212bc23aa246c1e2fc57ffba">更多...</a></p>
</td>
</tr>
<tr id="row289590160083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p141357596083931"><a name="p141357596083931"></a><a name="p141357596083931"></a>( <a href="_codec.md#gadde4bcc34f33cf427c4e3d065fe9ced6">EmptyThisBuffer</a> )(struct <a href="_codec_component_type.md">CodecComponentType</a> *self, const struct <a href="_omx_codec_buffer.md">OmxCodecBuffer</a> *buffer)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1034051291083931"><a name="p1034051291083931"></a><a name="p1034051291083931"></a>编解码输入待处理buffer。 <a href="_codec.md#gadde4bcc34f33cf427c4e3d065fe9ced6">更多...</a></p>
</td>
</tr>
<tr id="row1611454792083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p254269892083931"><a name="p254269892083931"></a><a name="p254269892083931"></a>( <a href="_codec.md#ga71e19a0e945a2c5b5d8e4da4327e4a01">FillThisBuffer</a> )(struct <a href="_codec_component_type.md">CodecComponentType</a> *self, const struct <a href="_omx_codec_buffer.md">OmxCodecBuffer</a> *buffer)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p261857173083931"><a name="p261857173083931"></a><a name="p261857173083931"></a>编解码输出填充buffer。 <a href="_codec.md#ga71e19a0e945a2c5b5d8e4da4327e4a01">更多...</a></p>
</td>
</tr>
<tr id="row279084471083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1319358325083931"><a name="p1319358325083931"></a><a name="p1319358325083931"></a>( <a href="_codec.md#ga091c2102bef68b5e74ec8dd9843d827e">SetCallbacks</a> )(struct <a href="_codec_component_type.md">CodecComponentType</a> *self, struct <a href="_codec_callback_type.md">CodecCallbackType</a> *callback, int8_t *appData, uint32_t appDataLen)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1287433881083931"><a name="p1287433881083931"></a><a name="p1287433881083931"></a>设置Codec组件的回调函数。 <a href="_codec.md#ga091c2102bef68b5e74ec8dd9843d827e">更多...</a></p>
</td>
</tr>
<tr id="row747455706083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1891719611083931"><a name="p1891719611083931"></a><a name="p1891719611083931"></a>( <a href="_codec.md#ga0229a1a8803fc74a0cfdc3ffbe6c6d37">ComponentDeInit</a> )(struct <a href="_codec_component_type.md">CodecComponentType</a> *self)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p125782597083931"><a name="p125782597083931"></a><a name="p125782597083931"></a>组件去初始化。 <a href="_codec.md#ga0229a1a8803fc74a0cfdc3ffbe6c6d37">更多...</a></p>
</td>
</tr>
<tr id="row2017213679083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1554566851083931"><a name="p1554566851083931"></a><a name="p1554566851083931"></a>( <a href="_codec.md#gac04950979ddbdfe02c7774e0d8e59459">UseEglImage</a> )(struct <a href="_codec_component_type.md">CodecComponentType</a> *self, struct <a href="_omx_codec_buffer.md">OmxCodecBuffer</a> *buffer, uint32_t portIndex, int8_t *eglImage, uint32_t eglImageLen)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p885615643083931"><a name="p885615643083931"></a><a name="p885615643083931"></a>使用已在EGL中申请的空间。 <a href="_codec.md#gac04950979ddbdfe02c7774e0d8e59459">更多...</a></p>
</td>
</tr>
<tr id="row1292080736083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1969625986083931"><a name="p1969625986083931"></a><a name="p1969625986083931"></a>( <a href="_codec.md#gac756974c7b26a75bf59cd3901fb8c9cb">ComponentRoleEnum</a> )(struct <a href="_codec_component_type.md">CodecComponentType</a> *self, uint8_t *role, uint32_t roleLen, uint32_t index)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p59093703083931"><a name="p59093703083931"></a><a name="p59093703083931"></a>获取组件角色。 <a href="_codec.md#gac756974c7b26a75bf59cd3901fb8c9cb">更多...</a></p>
</td>
</tr>
</tbody>
</table>

## **详细描述**<a name="section1239847567083931"></a>

Codec组件接口定义。

主要提供以下功能：

-   获取组件的版本。
-   组件参数配置的获取和设置。
-   发送命令至组件及获取组件状态。
-   设置回调函数。
-   设置/释放组件使用的buffer。
-   编解码输入输出buffer处理 具体方法使用详见函数说明。

