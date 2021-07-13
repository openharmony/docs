# SDK开发过程<a name="ZH-CN_TOPIC_0000001077607682"></a>

SDK头文件的功能实现是基于对SDK的调用映射到对client的调用。Client端提供的接口如下[表1](#table203963834718)所示。

**表 1**  Client端提供的接口

<a name="table203963834718"></a>
<table><thead align="left"><tr id="row173964834716"><th class="cellrowborder" valign="top" width="33.33333333333333%" id="mcps1.2.4.1.1"><p id="p20921103144918"><a name="p20921103144918"></a><a name="p20921103144918"></a>接口名</p>
</th>
<th class="cellrowborder" valign="top" width="23.03230323032303%" id="mcps1.2.4.1.2"><p id="p109216317495"><a name="p109216317495"></a><a name="p109216317495"></a>接口说明</p>
</th>
<th class="cellrowborder" valign="top" width="43.634363436343634%" id="mcps1.2.4.1.3"><p id="p1192112316497"><a name="p1192112316497"></a><a name="p1192112316497"></a>参数要求</p>
</th>
</tr>
</thead>
<tbody><tr id="row4397198154712"><td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.1 "><p id="p179221331104919"><a name="p179221331104919"></a><a name="p179221331104919"></a>int <strong id="b15922731104916"><a name="b15922731104916"></a><a name="b15922731104916"></a>AieClientInit</strong>(const ConfigInfo &amp;configInfo, ClientInfo &amp;clientInfo, const AlgorithmInfo &amp;algorithmInfo, IServiceDeadCb *cb)</p>
</td>
<td class="cellrowborder" valign="top" width="23.03230323032303%" headers="mcps1.2.4.1.2 "><p id="p199227318499"><a name="p199227318499"></a><a name="p199227318499"></a><strong id="b59221831174918"><a name="b59221831174918"></a><a name="b59221831174918"></a>作用</strong>：链接并初始化引擎服务，激活跨进程调用。</p>
<p id="p9922153110492"><a name="p9922153110492"></a><a name="p9922153110492"></a><strong id="b2922183114917"><a name="b2922183114917"></a><a name="b2922183114917"></a>返回值</strong>：0为成功，其他返回值失败。</p>
</td>
<td class="cellrowborder" valign="top" width="43.634363436343634%" headers="mcps1.2.4.1.3 "><p id="p4350171113110"><a name="p4350171113110"></a><a name="p4350171113110"></a><strong id="b9922631154913"><a name="b9922631154913"></a><a name="b9922631154913"></a>configInfo</strong>(NOT NULL)：引擎相关初始化配置数据；</p>
<p id="p4922173116498"><a name="p4922173116498"></a><a name="p4922173116498"></a><strong id="b692213117497"><a name="b692213117497"></a><a name="b692213117497"></a>clientInfo</strong>(NOT NULL)：引擎客户端信息；</p>
<p id="p18922931134919"><a name="p18922931134919"></a><a name="p18922931134919"></a><strong id="b129226314491"><a name="b129226314491"></a><a name="b129226314491"></a>algorithmInfo</strong>(NOT NULL)：调用算法信息；</p>
<p id="p592283164916"><a name="p592283164916"></a><a name="p592283164916"></a><strong id="b892273194914"><a name="b892273194914"></a><a name="b892273194914"></a>cb</strong>(可为NULL)：死亡回调 对象；</p>
</td>
</tr>
<tr id="row1839716854716"><td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.1 "><p id="p15922153154919"><a name="p15922153154919"></a><a name="p15922153154919"></a>int <strong id="b1922831144914"><a name="b1922831144914"></a><a name="b1922831144914"></a>AieClientPrepare</strong>(const ClientInfo &amp;clientInfo, const AlgorithmInfo &amp;algorithmInfo, const DataInfo &amp;inputInfo, DataInfo &amp;outputInfo, IClientCb *cb)</p>
</td>
<td class="cellrowborder" valign="top" width="23.03230323032303%" headers="mcps1.2.4.1.2 "><p id="p14922113114914"><a name="p14922113114914"></a><a name="p14922113114914"></a><strong id="b2922133194911"><a name="b2922133194911"></a><a name="b2922133194911"></a>作用</strong>：加载算法插件。</p>
<p id="p5922331114916"><a name="p5922331114916"></a><a name="p5922331114916"></a><strong id="b49221631154911"><a name="b49221631154911"></a><a name="b49221631154911"></a>返回值</strong>： 0为成功，其他返回值失败。</p>
</td>
<td class="cellrowborder" valign="top" width="43.634363436343634%" headers="mcps1.2.4.1.3 "><p id="p17922183120490"><a name="p17922183120490"></a><a name="p17922183120490"></a><strong id="b179221731174919"><a name="b179221731174919"></a><a name="b179221731174919"></a>clientInfo</strong>(NOT NULL)：引擎客户端信息；</p>
<p id="p8922193154917"><a name="p8922193154917"></a><a name="p8922193154917"></a><strong id="b7922163118490"><a name="b7922163118490"></a><a name="b7922163118490"></a>algorithmInfo</strong>(NOT NULL)：调用算法信息；</p>
<p id="p192293134912"><a name="p192293134912"></a><a name="p192293134912"></a><strong id="b9922631164919"><a name="b9922631164919"></a><a name="b9922631164919"></a>inputInfo</strong>(可为NULL)：加载算法插件时输入所需信息；</p>
<p id="p1492219316494"><a name="p1492219316494"></a><a name="p1492219316494"></a><strong id="b1592213314497"><a name="b1592213314497"></a><a name="b1592213314497"></a>outputInfo</strong>(可为NULL)：加载算法插件之后如需返回信息则通过此出参返回；</p>
<p id="p12922931134913"><a name="p12922931134913"></a><a name="p12922931134913"></a><strong id="b2922163118492"><a name="b2922163118492"></a><a name="b2922163118492"></a>cb</strong>：异步算法通过此回调返回运算结果，因此<strong id="b1922831114914"><a name="b1922831114914"></a><a name="b1922831114914"></a>异步算法此结构体不能为空</strong>；若为同步算法，传入空值即可；</p>
</td>
</tr>
<tr id="row6397138134713"><td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.1 "><p id="p6923143184914"><a name="p6923143184914"></a><a name="p6923143184914"></a>int <strong id="b7923231144918"><a name="b7923231144918"></a><a name="b7923231144918"></a>AieClientAsyncProcess</strong>(const ClientInfo &amp;clientInfo, const AlgorithmInfo &amp;algorithmInfo, const DataInfo &amp;inputInfo)</p>
</td>
<td class="cellrowborder" valign="top" width="23.03230323032303%" headers="mcps1.2.4.1.2 "><p id="p792383116495"><a name="p792383116495"></a><a name="p792383116495"></a><strong id="b592313144920"><a name="b592313144920"></a><a name="b592313144920"></a>作用</strong>：执行异步算法。</p>
<p id="p139231531184912"><a name="p139231531184912"></a><a name="p139231531184912"></a><strong id="b3923113134918"><a name="b3923113134918"></a><a name="b3923113134918"></a>返回值</strong>：0为成功，其他返回值失败。</p>
</td>
<td class="cellrowborder" valign="top" width="43.634363436343634%" headers="mcps1.2.4.1.3 "><p id="p1592323144910"><a name="p1592323144910"></a><a name="p1592323144910"></a><strong id="b11923153184916"><a name="b11923153184916"></a><a name="b11923153184916"></a>clientInfo</strong>(NOT NULL)：引擎客户端信息；</p>
<p id="p199231831194912"><a name="p199231831194912"></a><a name="p199231831194912"></a><strong id="b69231031124912"><a name="b69231031124912"></a><a name="b69231031124912"></a>algorithmInfo</strong>(NOT NULL)：调用算法信息；</p>
<p id="p6924173115491"><a name="p6924173115491"></a><a name="p6924173115491"></a><strong id="b149248313494"><a name="b149248313494"></a><a name="b149248313494"></a>inputInfo</strong>(可为NULL)：算法运算入参；</p>
</td>
</tr>
<tr id="row43981283476"><td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.1 "><p id="p992473112496"><a name="p992473112496"></a><a name="p992473112496"></a>int <strong id="b292493134918"><a name="b292493134918"></a><a name="b292493134918"></a>AieClientSyncProcess</strong>(const ClientInfo &amp;clientInfo, const AlgorithmInfo &amp;algorithmInfo, const DataInfo &amp;inputInfo, DataInfo &amp;outputInfo)</p>
</td>
<td class="cellrowborder" valign="top" width="23.03230323032303%" headers="mcps1.2.4.1.2 "><p id="p14924831124913"><a name="p14924831124913"></a><a name="p14924831124913"></a><strong id="b1292416313494"><a name="b1292416313494"></a><a name="b1292416313494"></a>作用</strong>：执行同步算法。</p>
<p id="p14924203134910"><a name="p14924203134910"></a><a name="p14924203134910"></a><strong id="b16924123134910"><a name="b16924123134910"></a><a name="b16924123134910"></a>返回值</strong>：0为成功，其他返回值失败。</p>
</td>
<td class="cellrowborder" valign="top" width="43.634363436343634%" headers="mcps1.2.4.1.3 "><p id="p189243318494"><a name="p189243318494"></a><a name="p189243318494"></a><strong id="b29241131194913"><a name="b29241131194913"></a><a name="b29241131194913"></a>clientInfo</strong>(NOT NULL)：引擎客户端信息；</p>
<p id="p2924133124918"><a name="p2924133124918"></a><a name="p2924133124918"></a><strong id="b1924193144918"><a name="b1924193144918"></a><a name="b1924193144918"></a>algorithmInfo</strong>(NOT NULL)：调用算法信息；</p>
<p id="p1692403115493"><a name="p1692403115493"></a><a name="p1692403115493"></a><strong id="b69241431134911"><a name="b69241431134911"></a><a name="b69241431134911"></a>inputInfo</strong>(可为NULL)：算法运算入参；</p>
<p id="p392443174917"><a name="p392443174917"></a><a name="p392443174917"></a><strong id="b15924193114495"><a name="b15924193114495"></a><a name="b15924193114495"></a>outputInfo</strong>(可为NULL)：同步算法运算结果出参；</p>
</td>
</tr>
<tr id="row439813812472"><td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.1 "><p id="p17925631194911"><a name="p17925631194911"></a><a name="p17925631194911"></a>int <strong id="b8925123113494"><a name="b8925123113494"></a><a name="b8925123113494"></a>AieClientRelease</strong>(const ClientInfo &amp;clientInfo, const AlgorithmInfo &amp;algorithmInfo, const DataInfo &amp;inputInfo)</p>
</td>
<td class="cellrowborder" valign="top" width="23.03230323032303%" headers="mcps1.2.4.1.2 "><p id="p1892583174920"><a name="p1892583174920"></a><a name="p1892583174920"></a><strong id="b129251231104917"><a name="b129251231104917"></a><a name="b129251231104917"></a>作用</strong>：卸载算法插件。</p>
<p id="p16925113119497"><a name="p16925113119497"></a><a name="p16925113119497"></a><strong id="b592515316496"><a name="b592515316496"></a><a name="b592515316496"></a>返回值</strong>：0为成功，其他返回值失败。</p>
</td>
<td class="cellrowborder" valign="top" width="43.634363436343634%" headers="mcps1.2.4.1.3 "><p id="p59255313493"><a name="p59255313493"></a><a name="p59255313493"></a><strong id="b13925103144913"><a name="b13925103144913"></a><a name="b13925103144913"></a>clientInfo</strong>(NOT NULL)：引擎客户端信息；</p>
<p id="p1692517314499"><a name="p1692517314499"></a><a name="p1692517314499"></a><strong id="b892515316491"><a name="b892515316491"></a><a name="b892515316491"></a>algorithmInfo</strong>(NOT NULL)：卸载算法插件的相关信息；</p>
<p id="p14925631194912"><a name="p14925631194912"></a><a name="p14925631194912"></a><strong id="b18925431114910"><a name="b18925431114910"></a><a name="b18925431114910"></a>inputInfo</strong>(可为NULL)：调用卸载接口时的输入信息；</p>
</td>
</tr>
<tr id="row123998813470"><td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.1 "><p id="p492513120494"><a name="p492513120494"></a><a name="p492513120494"></a>int <strong id="b139251331144916"><a name="b139251331144916"></a><a name="b139251331144916"></a>AieClientDestroy</strong>(ClientInfo &amp;clientInfo)</p>
</td>
<td class="cellrowborder" valign="top" width="23.03230323032303%" headers="mcps1.2.4.1.2 "><p id="p12925143118492"><a name="p12925143118492"></a><a name="p12925143118492"></a><strong id="b10925163114496"><a name="b10925163114496"></a><a name="b10925163114496"></a>作用</strong>：断开与服务端的链接，释放相关缓存。</p>
<p id="p5926031124914"><a name="p5926031124914"></a><a name="p5926031124914"></a><strong id="b17926331124911"><a name="b17926331124911"></a><a name="b17926331124911"></a>返回值</strong>：0为成功，其他返回值失败。</p>
</td>
<td class="cellrowborder" valign="top" width="43.634363436343634%" headers="mcps1.2.4.1.3 "><p id="p1692683112499"><a name="p1692683112499"></a><a name="p1692683112499"></a><strong id="b199261131124913"><a name="b199261131124913"></a><a name="b199261131124913"></a>clientInfo</strong>(NOT NULL)：所要销毁的引擎客户端信息；</p>
</td>
</tr>
<tr id="row166991140328"><td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.1 "><p id="p26995401922"><a name="p26995401922"></a><a name="p26995401922"></a>int <strong id="b992616317493"><a name="b992616317493"></a><a name="b992616317493"></a>AieClientSetOption</strong>(const ClientInfo &amp;clientInfo, int optionType, const DataInfo &amp;inputInfo)</p>
</td>
<td class="cellrowborder" valign="top" width="23.03230323032303%" headers="mcps1.2.4.1.2 "><p id="p892633118493"><a name="p892633118493"></a><a name="p892633118493"></a><strong id="b1926113164920"><a name="b1926113164920"></a><a name="b1926113164920"></a>作用</strong>：设置配置项，可将一些算法的拓展信息通过此接口传入插件。</p>
<p id="p166531559429"><a name="p166531559429"></a><a name="p166531559429"></a><strong id="b1492733110494"><a name="b1492733110494"></a><a name="b1492733110494"></a>返回值</strong>：0为成功，其他返回值失败。</p>
</td>
<td class="cellrowborder" valign="top" width="43.634363436343634%" headers="mcps1.2.4.1.3 "><p id="p119277312492"><a name="p119277312492"></a><a name="p119277312492"></a><strong id="b12927193184910"><a name="b12927193184910"></a><a name="b12927193184910"></a>clientInfo</strong>(NOT NULL)：引擎客户端信息；</p>
<p id="p159271031184915"><a name="p159271031184915"></a><a name="p159271031184915"></a><strong id="b792753113495"><a name="b792753113495"></a><a name="b792753113495"></a>optionType</strong> (NOT NULL)：算法配置项，算法插件可根据需要利用此状态位；</p>
<p id="p163731116313"><a name="p163731116313"></a><a name="p163731116313"></a><strong id="b292743174920"><a name="b292743174920"></a><a name="b292743174920"></a>inputInfo</strong>(可为NULL)：插件可根据需要通过此入参设置算法参数信息；</p>
</td>
</tr>
<tr id="row939914814478"><td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.1 "><p id="p992713144920"><a name="p992713144920"></a><a name="p992713144920"></a>int <strong id="b6927163174918"><a name="b6927163174918"></a><a name="b6927163174918"></a>AieClientGetOption</strong>(const ClientInfo &amp;clientInfo, int optionType, const DataInfo &amp;inputInfo, DataInfo &amp;outputInfo)</p>
</td>
<td class="cellrowborder" valign="top" width="23.03230323032303%" headers="mcps1.2.4.1.2 "><p id="p1927031114910"><a name="p1927031114910"></a><a name="p1927031114910"></a><strong id="b592716319496"><a name="b592716319496"></a><a name="b592716319496"></a>作用</strong>：给定特定的optionType和inputInfo，获取其对应的配置项信息。</p>
<p id="p1792723174913"><a name="p1792723174913"></a><a name="p1792723174913"></a><strong id="b9927133113493"><a name="b9927133113493"></a><a name="b9927133113493"></a>返回值</strong>：0为成功，其他返回值失败。</p>
</td>
<td class="cellrowborder" valign="top" width="43.634363436343634%" headers="mcps1.2.4.1.3 "><p id="p0927173154916"><a name="p0927173154916"></a><a name="p0927173154916"></a><strong id="b139271731154918"><a name="b139271731154918"></a><a name="b139271731154918"></a>clientInfo</strong>(NOT NULL)：引擎客户端信息；</p>
<p id="p5927131114914"><a name="p5927131114914"></a><a name="p5927131114914"></a><strong id="b20928331164915"><a name="b20928331164915"></a><a name="b20928331164915"></a>optionType</strong>(NOT NULL)：所获取配置项信息的对应算法状态位；</p>
<p id="p69283313491"><a name="p69283313491"></a><a name="p69283313491"></a><strong id="b792810316490"><a name="b792810316490"></a><a name="b792810316490"></a>inputInfo</strong>(可为NULL)：所获取配置项信息的对应算法参数信息；</p>
<p id="p8928431104914"><a name="p8928431104914"></a><a name="p8928431104914"></a><strong id="b1692873104911"><a name="b1692873104911"></a><a name="b1692873104911"></a>outputInfo</strong>(可为NULL)：所要获取的配置项信息返回结果；</p>
</td>
</tr>
</tbody>
</table>

其中，ConfigInfo，ClientInfo，AlgorithmInfo，DataInfo的数据结构如下[表2](#table22154317482)所示。

**表 2**  ConfigInfo，ClientInfo，AlgorithmInfo，DataInfo的数据结构

<a name="table22154317482"></a>
<table><thead align="left"><tr id="row6215103164810"><th class="cellrowborder" valign="top" width="16.65166516651665%" id="mcps1.2.4.1.1"><p id="p4265171044816"><a name="p4265171044816"></a><a name="p4265171044816"></a>结构体名称</p>
</th>
<th class="cellrowborder" valign="top" width="25.962596259625965%" id="mcps1.2.4.1.2"><p id="p2266110174819"><a name="p2266110174819"></a><a name="p2266110174819"></a>说明</p>
</th>
<th class="cellrowborder" valign="top" width="57.38573857385738%" id="mcps1.2.4.1.3"><p id="p1626618102488"><a name="p1626618102488"></a><a name="p1626618102488"></a>属性</p>
</th>
</tr>
</thead>
<tbody><tr id="row17216183174817"><td class="cellrowborder" valign="top" width="16.65166516651665%" headers="mcps1.2.4.1.1 "><p id="p283074964915"><a name="p283074964915"></a><a name="p283074964915"></a>ConfigInfo</p>
</td>
<td class="cellrowborder" valign="top" width="25.962596259625965%" headers="mcps1.2.4.1.2 "><p id="p48301649114915"><a name="p48301649114915"></a><a name="p48301649114915"></a>算法配置项信息。</p>
</td>
<td class="cellrowborder" valign="top" width="57.38573857385738%" headers="mcps1.2.4.1.3 "><p id="p783054924913"><a name="p783054924913"></a><a name="p783054924913"></a><strong id="b383094934918"><a name="b383094934918"></a><a name="b383094934918"></a>const char *description</strong>：配置项信息主体；</p>
</td>
</tr>
<tr id="row721619312480"><td class="cellrowborder" valign="top" width="16.65166516651665%" headers="mcps1.2.4.1.1 "><p id="p98305491499"><a name="p98305491499"></a><a name="p98305491499"></a>ClientInfo</p>
</td>
<td class="cellrowborder" valign="top" width="25.962596259625965%" headers="mcps1.2.4.1.2 "><p id="p17830154920494"><a name="p17830154920494"></a><a name="p17830154920494"></a>客户端信息。</p>
</td>
<td class="cellrowborder" valign="top" width="57.38573857385738%" headers="mcps1.2.4.1.3 "><p id="p198309499494"><a name="p198309499494"></a><a name="p198309499494"></a><strong id="b98303498492"><a name="b98303498492"></a><a name="b98303498492"></a>long long clientVersion</strong>：客户端设备版本号（当前还未启用）；</p>
<p id="p15830749154912"><a name="p15830749154912"></a><a name="p15830749154912"></a><strong id="b1383084912498"><a name="b1383084912498"></a><a name="b1383084912498"></a>int clientId</strong>：客户端ID；</p>
<p id="p38302049174916"><a name="p38302049174916"></a><a name="p38302049174916"></a><strong id="b983015499493"><a name="b983015499493"></a><a name="b983015499493"></a>int sessionId：</strong>会话ID；</p>
<p id="p38302049174916"><a name="p38302049174916"></a><a name="p38302049174916"></a><strong id="b983015499493"><a name="b983015499493"></a><a name="b983015499493"></a>uid_t serverUid：</strong>server端UID；</p>
<p id="p38302049174916"><a name="p38302049174916"></a><a name="p38302049174916"></a><strong id="b983015499493"><a name="b983015499493"></a><a name="b983015499493"></a>uid_t clientUid：</strong>client端UID；</p>
<p id="p1183104954914"><a name="p1183104954914"></a><a name="p1183104954914"></a><strong id="b20831194964918"><a name="b20831194964918"></a><a name="b20831194964918"></a>int extendLen</strong>：拓展信息（extendMsg）长度；</p>
<p id="p11831124994912"><a name="p11831124994912"></a><a name="p11831124994912"></a><strong id="b1383134914916"><a name="b1383134914916"></a><a name="b1383134914916"></a>unsigned char *extendMsg</strong>：拓展信息主体；</p>
</td>
</tr>
<tr id="row16278112314319"><td class="cellrowborder" valign="top" width="16.65166516651665%" headers="mcps1.2.4.1.1 "><p id="p162788231732"><a name="p162788231732"></a><a name="p162788231732"></a>AlgorithmInfo</p>
</td>
<td class="cellrowborder" valign="top" width="25.962596259625965%" headers="mcps1.2.4.1.2 "><p id="p1027882317314"><a name="p1027882317314"></a><a name="p1027882317314"></a>算法信息。</p>
</td>
<td class="cellrowborder" valign="top" width="57.38573857385738%" headers="mcps1.2.4.1.3 "><p id="p5831849124917"><a name="p5831849124917"></a><a name="p5831849124917"></a><strong id="b148311749204913"><a name="b148311749204913"></a><a name="b148311749204913"></a>long long clientVersion</strong>：客户端设备版本号（当前还未启用）；</p>
<p id="p5831749164916"><a name="p5831749164916"></a><a name="p5831749164916"></a><strong id="b78316491497"><a name="b78316491497"></a><a name="b78316491497"></a>bool isAsync</strong>：是否为异步执行；</p>
<p id="p1983164910493"><a name="p1983164910493"></a><a name="p1983164910493"></a><strong id="b4831154944912"><a name="b4831154944912"></a><a name="b4831154944912"></a>int algorithmType：</strong>引擎框架根据插件加载顺序分配的算法类型ID；</p>
<p id="p1883184914916"><a name="p1883184914916"></a><a name="p1883184914916"></a><strong id="b783164913498"><a name="b783164913498"></a><a name="b783164913498"></a>long long algorithmVersion</strong>：算法版本号；</p>
<p id="p78311449174914"><a name="p78311449174914"></a><a name="p78311449174914"></a><strong id="b1883124910493"><a name="b1883124910493"></a><a name="b1883124910493"></a>bool isCloud</strong>：是否上云（当前还未启用）；</p>
<p id="p168321349114912"><a name="p168321349114912"></a><a name="p168321349114912"></a><strong id="b4832194944913"><a name="b4832194944913"></a><a name="b4832194944913"></a>int operateId</strong>：执行ID（当前还未启用）；</p>
<p id="p683234934911"><a name="p683234934911"></a><a name="p683234934911"></a><strong id="b11832144910491"><a name="b11832144910491"></a><a name="b11832144910491"></a>int requestId</strong>：请求ID，标识每次request，以对应执行结果；</p>
<p id="p108320499498"><a name="p108320499498"></a><a name="p108320499498"></a><strong id="b18832194984920"><a name="b18832194984920"></a><a name="b18832194984920"></a>int extendLen</strong>：拓展信息（extendMsg）长度；</p>
<p id="p91953541631"><a name="p91953541631"></a><a name="p91953541631"></a><strong id="b583210499491"><a name="b583210499491"></a><a name="b583210499491"></a>unsigned char *extendMsg</strong>：拓展信息主体；</p>
</td>
</tr>
<tr id="row11216163194819"><td class="cellrowborder" valign="top" width="16.65166516651665%" headers="mcps1.2.4.1.1 "><p id="p11832104917494"><a name="p11832104917494"></a><a name="p11832104917494"></a>DataInfo</p>
</td>
<td class="cellrowborder" valign="top" width="25.962596259625965%" headers="mcps1.2.4.1.2 "><p id="p168317490499"><a name="p168317490499"></a><a name="p168317490499"></a>算法数据入参(inputInfo)、接口调用结果出参(outputInfo)。</p>
</td>
<td class="cellrowborder" valign="top" width="57.38573857385738%" headers="mcps1.2.4.1.3 "><p id="p1483274934919"><a name="p1483274934919"></a><a name="p1483274934919"></a><strong id="b28321849174917"><a name="b28321849174917"></a><a name="b28321849174917"></a>unsigned char *data：</strong>数据主体；</p>
<p id="p383284915493"><a name="p383284915493"></a><a name="p383284915493"></a><strong id="b38321249154916"><a name="b38321249154916"></a><a name="b38321249154916"></a>int length</strong>：数据(data)长度；</p>
</td>
</tr>
</tbody>
</table>

具体开发过程可参考唤醒词识别SDK开发示例。

