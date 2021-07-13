# 插件的开发过程<a name="ZH-CN_TOPIC_0000001077767652"></a>

AI引擎框架规定了一套算法插件接入规范，各插件需实现规定接口以实现获取插件版本信息、算法推理类型、同步执行算法、异步执行算法、加载算法插件、卸载算法插件、设置算法配置信息、获取指定算法配置信息等功能。（同步算法实现SyncProcess接口，异步算法实现AsyncProcess接口）。

1）算法插件类IPlugin接口设计如下[表1](#table1329717488505)所示。

**表 1**  算法插件类IPlugin接口设计

<a name="table1329717488505"></a>
<table><thead align="left"><tr id="row52971848135020"><th class="cellrowborder" valign="top" width="33.33333333333333%" id="mcps1.2.4.1.1"><p id="p1728114205110"><a name="p1728114205110"></a><a name="p1728114205110"></a>接口名</p>
</th>
<th class="cellrowborder" valign="top" width="29.34293429342934%" id="mcps1.2.4.1.2"><p id="p172818410516"><a name="p172818410516"></a><a name="p172818410516"></a>接口说明</p>
</th>
<th class="cellrowborder" valign="top" width="37.32373237323732%" id="mcps1.2.4.1.3"><p id="p197291748518"><a name="p197291748518"></a><a name="p197291748518"></a>参数要求</p>
</th>
</tr>
</thead>
<tbody><tr id="row15297194895013"><td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.1 "><p id="p872954205114"><a name="p872954205114"></a><a name="p872954205114"></a>const long long GetVersion() const;</p>
</td>
<td class="cellrowborder" valign="top" width="29.34293429342934%" headers="mcps1.2.4.1.2 "><p id="p572944205112"><a name="p572944205112"></a><a name="p572944205112"></a><strong id="b1372916410511"><a name="b1372916410511"></a><a name="b1372916410511"></a>作用</strong>：获取插件版本信息。</p>
<p id="p107294413512"><a name="p107294413512"></a><a name="p107294413512"></a><strong id="b11729104125111"><a name="b11729104125111"></a><a name="b11729104125111"></a>返回值</strong>：版本号（long long）</p>
</td>
<td class="cellrowborder" valign="top" width="37.32373237323732%" headers="mcps1.2.4.1.3 "><p id="p18729174145115"><a name="p18729174145115"></a><a name="p18729174145115"></a>-</p>
</td>
</tr>
<tr id="row2297124812500"><td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.1 "><p id="p117290419511"><a name="p117290419511"></a><a name="p117290419511"></a>const char *GetInferMode() const;</p>
</td>
<td class="cellrowborder" valign="top" width="29.34293429342934%" headers="mcps1.2.4.1.2 "><p id="p27294415118"><a name="p27294415118"></a><a name="p27294415118"></a><strong id="b1272914425114"><a name="b1272914425114"></a><a name="b1272914425114"></a>作用</strong>：获取算法推理类型。</p>
<p id="p7729124165117"><a name="p7729124165117"></a><a name="p7729124165117"></a><strong id="b1172911415517"><a name="b1172911415517"></a><a name="b1172911415517"></a>返回值</strong>："SYNC" or "ASYNC";</p>
</td>
<td class="cellrowborder" valign="top" width="37.32373237323732%" headers="mcps1.2.4.1.3 "><p id="p107293425116"><a name="p107293425116"></a><a name="p107293425116"></a>-</p>
</td>
</tr>
<tr id="row129814805012"><td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.1 "><p id="p4729749518"><a name="p4729749518"></a><a name="p4729749518"></a>int SyncProcess(IRequest *request, IResponse *&amp;response);</p>
</td>
<td class="cellrowborder" valign="top" width="29.34293429342934%" headers="mcps1.2.4.1.2 "><p id="p273084115114"><a name="p273084115114"></a><a name="p273084115114"></a><strong id="b16730194185116"><a name="b16730194185116"></a><a name="b16730194185116"></a>作用</strong>：执行插件同步算法。</p>
<p id="p4730142514"><a name="p4730142514"></a><a name="p4730142514"></a><strong id="b37307415510"><a name="b37307415510"></a><a name="b37307415510"></a>返回值</strong>：0为成功，其他返回值失败。</p>
</td>
<td class="cellrowborder" valign="top" width="37.32373237323732%" headers="mcps1.2.4.1.3 "><p id="p167306485114"><a name="p167306485114"></a><a name="p167306485114"></a><strong id="b167300414514"><a name="b167300414514"></a><a name="b167300414514"></a>request</strong>(NOT NULL)：用于向算法插件传递请求内容；引擎服务端与插件的数据通道；</p>
<p id="p373014485110"><a name="p373014485110"></a><a name="p373014485110"></a><strong id="b2730347518"><a name="b2730347518"></a><a name="b2730347518"></a>response</strong>(NOT NULL)：作为出参用于接收算法插件发回的同步算法执行结果，引擎服务端与插件的数据通道；</p>
</td>
</tr>
<tr id="row16298748135017"><td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.1 "><p id="p187308420519"><a name="p187308420519"></a><a name="p187308420519"></a>int AsyncProcess(IRequest *request, IPluginAlgorithmCallback *callback);</p>
</td>
<td class="cellrowborder" valign="top" width="29.34293429342934%" headers="mcps1.2.4.1.2 "><p id="p17301414513"><a name="p17301414513"></a><a name="p17301414513"></a><strong id="b1373017425110"><a name="b1373017425110"></a><a name="b1373017425110"></a>作用</strong>：执行异步算法。</p>
<p id="p147307419512"><a name="p147307419512"></a><a name="p147307419512"></a><strong id="b9730134185111"><a name="b9730134185111"></a><a name="b9730134185111"></a>返回值</strong>：0为成功，其他返回值失败。</p>
</td>
<td class="cellrowborder" valign="top" width="37.32373237323732%" headers="mcps1.2.4.1.3 "><p id="p187303415118"><a name="p187303415118"></a><a name="p187303415118"></a><strong id="b107303411514"><a name="b107303411514"></a><a name="b107303411514"></a>request</strong>(NOT NULL)：用于向算法插件传递请求内容；引擎服务端与插件的数据通道。</p>
<p id="p273014415111"><a name="p273014415111"></a><a name="p273014415111"></a><strong id="b127311740510"><a name="b127311740510"></a><a name="b127311740510"></a>callback</strong>(NOT NULL)：算法插件异步执行结果通过此回调返回引擎服务端；</p>
</td>
</tr>
<tr id="row0298648135020"><td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.1 "><p id="p57316445115"><a name="p57316445115"></a><a name="p57316445115"></a>int Prepare(long long transactionId, const DataInfo &amp;inputInfo, DataInfo &amp;outputInfo);</p>
</td>
<td class="cellrowborder" valign="top" width="29.34293429342934%" headers="mcps1.2.4.1.2 "><p id="p17731343517"><a name="p17731343517"></a><a name="p17731343517"></a><strong id="b167311843514"><a name="b167311843514"></a><a name="b167311843514"></a>作用</strong>：加载算法插件。</p>
<p id="p873110465115"><a name="p873110465115"></a><a name="p873110465115"></a><strong id="b207317425117"><a name="b207317425117"></a><a name="b207317425117"></a>返回值</strong>：0为成功，其他返回值失败。</p>
</td>
<td class="cellrowborder" valign="top" width="37.32373237323732%" headers="mcps1.2.4.1.3 "><p id="p17731114165112"><a name="p17731114165112"></a><a name="p17731114165112"></a><strong id="b18731845511"><a name="b18731845511"></a><a name="b18731845511"></a>transactionId</strong>(NOT NULL)：事务ID，用于标记客户端+会话信息；</p>
<p id="p13731104205111"><a name="p13731104205111"></a><a name="p13731104205111"></a><strong id="b1873194125113"><a name="b1873194125113"></a><a name="b1873194125113"></a>inputInfo</strong>(可为NULL)：加载算法插件传入的一些信息；</p>
<p id="p117313420517"><a name="p117313420517"></a><a name="p117313420517"></a><strong id="b673116435116"><a name="b673116435116"></a><a name="b673116435116"></a>outputInfo</strong>(可为NULL)：调用加载接口时的出参，返回相关执行结果；</p>
</td>
</tr>
<tr id="row132988482502"><td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.1 "><p id="p137312415517"><a name="p137312415517"></a><a name="p137312415517"></a>int Release(bool isFullUnload, long long transactionId, const DataInfo &amp;inputInfo);</p>
</td>
<td class="cellrowborder" valign="top" width="29.34293429342934%" headers="mcps1.2.4.1.2 "><p id="p1473114420516"><a name="p1473114420516"></a><a name="p1473114420516"></a><strong id="b673118410511"><a name="b673118410511"></a><a name="b673118410511"></a>作用</strong>：卸载相关算法插件。</p>
<p id="p973184165118"><a name="p973184165118"></a><a name="p973184165118"></a><strong id="b1773214205119"><a name="b1773214205119"></a><a name="b1773214205119"></a>返回值</strong>：0为成功，其他返回值失败。</p>
</td>
<td class="cellrowborder" valign="top" width="37.32373237323732%" headers="mcps1.2.4.1.3 "><p id="p7732546518"><a name="p7732546518"></a><a name="p7732546518"></a><strong id="b147326465110"><a name="b147326465110"></a><a name="b147326465110"></a>isFullUnload</strong>(NOT NULL)：表示此插件是否只剩一个client调用，否则不能直接卸载插件，需等最后一个client来进行卸载；</p>
<p id="p1173213410515"><a name="p1173213410515"></a><a name="p1173213410515"></a><strong id="b1673215445117"><a name="b1673215445117"></a><a name="b1673215445117"></a>transactionId</strong>(NOT NULL)：事务ID，用于标记客户端+会话信息；</p>
<p id="p6732642517"><a name="p6732642517"></a><a name="p6732642517"></a><strong id="b87321941514"><a name="b87321941514"></a><a name="b87321941514"></a>inputInfo</strong>(可为NULL)：卸载算法插件传入的一些信息；</p>
</td>
</tr>
<tr id="row12991848165011"><td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.1 "><p id="p197328419511"><a name="p197328419511"></a><a name="p197328419511"></a>int SetOption(int optionType, const DataInfo &amp;inputInfo);</p>
</td>
<td class="cellrowborder" valign="top" width="29.34293429342934%" headers="mcps1.2.4.1.2 "><p id="p473213411517"><a name="p473213411517"></a><a name="p473213411517"></a><strong id="b207322420519"><a name="b207322420519"></a><a name="b207322420519"></a>作用</strong>：设置配置项，可将一些算法的拓展信息通过此接口传入插件。</p>
<p id="p12732440511"><a name="p12732440511"></a><a name="p12732440511"></a><strong id="b373217445110"><a name="b373217445110"></a><a name="b373217445110"></a>返回值</strong>：0为成功，其他返回值失败。</p>
</td>
<td class="cellrowborder" valign="top" width="37.32373237323732%" headers="mcps1.2.4.1.3 "><p id="p117321446518"><a name="p117321446518"></a><a name="p117321446518"></a><strong id="b14732348517"><a name="b14732348517"></a><a name="b14732348517"></a>optionType</strong> (NOT NULL)：算法配置项，算法插件可根据需要利用此状态位；</p>
<p id="p18732447514"><a name="p18732447514"></a><a name="p18732447514"></a><strong id="b18732847511"><a name="b18732847511"></a><a name="b18732847511"></a>inputInfo</strong>(可为NULL)：插件可根据需要通过此入参设置算法参数信息；</p>
</td>
</tr>
<tr id="row629954865010"><td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.1 "><p id="p4733947512"><a name="p4733947512"></a><a name="p4733947512"></a>int GetOption(int optionType, const DataInfo &amp;inputInfo, DataInfo &amp;outputInfo);</p>
</td>
<td class="cellrowborder" valign="top" width="29.34293429342934%" headers="mcps1.2.4.1.2 "><p id="p177331049517"><a name="p177331049517"></a><a name="p177331049517"></a><strong id="b7733184195119"><a name="b7733184195119"></a><a name="b7733184195119"></a>作用</strong>：给定特定的optionType和inputInfo，获取其对应的配置项信息。</p>
<p id="p19733114175119"><a name="p19733114175119"></a><a name="p19733114175119"></a><strong id="b873354105117"><a name="b873354105117"></a><a name="b873354105117"></a>返回值</strong>：0为成功，其他返回值失败。</p>
</td>
<td class="cellrowborder" valign="top" width="37.32373237323732%" headers="mcps1.2.4.1.3 "><p id="p1273354145117"><a name="p1273354145117"></a><a name="p1273354145117"></a><strong id="b673317412518"><a name="b673317412518"></a><a name="b673317412518"></a>optionType</strong>(NOT NULL)：所获取配置项信息的对应算法状态位；</p>
<p id="p773394115116"><a name="p773394115116"></a><a name="p773394115116"></a><strong id="b197331648519"><a name="b197331648519"></a><a name="b197331648519"></a>inputInfo</strong>(可为NULL)：所获取配置项信息的对应算法参数信息；</p>
<p id="p3733349519"><a name="p3733349519"></a><a name="p3733349519"></a><strong id="b2733174185110"><a name="b2733174185110"></a><a name="b2733174185110"></a>outputInfo</strong>(可为NULL)：所要获取的配置项信息返回结果；</p>
</td>
</tr>
</tbody>
</table>

算法插件类接口：Prepare、SyncProcess、AsyncProcess、Release、SetOption、GetOption分别于客户端接口AieClientPrepare、AieClientSyncProcess、AieClientAsyncProcess、AieClientRelease、AieClientSetOption、AieClientGetOption一一对应；GetInferMode接口用于返回算法执行类型——同步或异步。

2）算法插件回调类IPluginCallback 接口设计如[表2](#table461192635114)所示。

**表 2**  算法插件回调类IPluginCallback 接口设计

<a name="table461192635114"></a>
<table><thead align="left"><tr id="row1061222605116"><th class="cellrowborder" valign="top" width="28.642864286428644%" id="mcps1.2.4.1.1"><p id="p12501314513"><a name="p12501314513"></a><a name="p12501314513"></a>接口名</p>
</th>
<th class="cellrowborder" valign="top" width="28.062806280628067%" id="mcps1.2.4.1.2"><p id="p9501131175119"><a name="p9501131175119"></a><a name="p9501131175119"></a>接口说明</p>
</th>
<th class="cellrowborder" valign="top" width="43.29432943294329%" id="mcps1.2.4.1.3"><p id="p0501431145119"><a name="p0501431145119"></a><a name="p0501431145119"></a>参数要求</p>
</th>
</tr>
</thead>
<tbody><tr id="row6612726205112"><td class="cellrowborder" valign="top" width="28.642864286428644%" headers="mcps1.2.4.1.1 "><p id="p85013185116"><a name="p85013185116"></a><a name="p85013185116"></a>void OnEvent(PluginEvent event, IResponse *response);</p>
</td>
<td class="cellrowborder" valign="top" width="28.062806280628067%" headers="mcps1.2.4.1.2 "><p id="p105053145110"><a name="p105053145110"></a><a name="p105053145110"></a>作用：插件通过此回调返回异步算法执行结果。</p>
</td>
<td class="cellrowborder" valign="top" width="43.29432943294329%" headers="mcps1.2.4.1.3 "><p id="p650193115116"><a name="p650193115116"></a><a name="p650193115116"></a><strong id="b1150153115118"><a name="b1150153115118"></a><a name="b1150153115118"></a>event</strong>：算法执行结果枚举,‘ON_PLUGIN_SUCCEED’或 ‘ON_PLUGIN_FAIL’（成功或者失败）；</p>
<p id="p35053185113"><a name="p35053185113"></a><a name="p35053185113"></a><strong id="b350163114517"><a name="b350163114517"></a><a name="b350163114517"></a>response</strong>：算法执行结果封装；</p>
</td>
</tr>
</tbody>
</table>

Request、Response是ai引擎服务端与算法插件进行通信的对象。Request封装了调用方的请求、输入数据等，而插件主要通过Response将运算之后的结果返回给AI引擎服务端。

Request类的属性如下[表3](#table16273647125120)所示。

**表 3**  Request类的属性

<a name="table16273647125120"></a>
<table><thead align="left"><tr id="row1727454745110"><th class="cellrowborder" valign="top" width="23.17231723172317%" id="mcps1.2.4.1.1"><p id="p203081522515"><a name="p203081522515"></a><a name="p203081522515"></a>属性名称</p>
</th>
<th class="cellrowborder" valign="top" width="43.494349434943494%" id="mcps1.2.4.1.2"><p id="p1330917523513"><a name="p1330917523513"></a><a name="p1330917523513"></a>属性说明</p>
</th>
<th class="cellrowborder" valign="top" width="33.33333333333333%" id="mcps1.2.4.1.3"><p id="p153091152175116"><a name="p153091152175116"></a><a name="p153091152175116"></a>默认值</p>
</th>
</tr>
</thead>
<tbody><tr id="row527454745113"><td class="cellrowborder" valign="top" width="23.17231723172317%" headers="mcps1.2.4.1.1 "><p id="p03095528514"><a name="p03095528514"></a><a name="p03095528514"></a>innerSequenceId_</p>
</td>
<td class="cellrowborder" valign="top" width="43.494349434943494%" headers="mcps1.2.4.1.2 "><p id="p730911521513"><a name="p730911521513"></a><a name="p730911521513"></a>类型：long long</p>
<p id="p12309105210517"><a name="p12309105210517"></a><a name="p12309105210517"></a>作用：暂未启用。</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.3 "><p id="p930919521513"><a name="p930919521513"></a><a name="p930919521513"></a>0</p>
</td>
</tr>
<tr id="row32741247175116"><td class="cellrowborder" valign="top" width="23.17231723172317%" headers="mcps1.2.4.1.1 "><p id="p3309175220514"><a name="p3309175220514"></a><a name="p3309175220514"></a>requestId_</p>
</td>
<td class="cellrowborder" valign="top" width="43.494349434943494%" headers="mcps1.2.4.1.2 "><p id="p1230915216512"><a name="p1230915216512"></a><a name="p1230915216512"></a>类型：int</p>
<p id="p11309195212517"><a name="p11309195212517"></a><a name="p11309195212517"></a>作用：标识请求序列，用于绑定返回运算结果。</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.3 "><p id="p1130965265119"><a name="p1130965265119"></a><a name="p1130965265119"></a>0</p>
</td>
</tr>
<tr id="row112741847115118"><td class="cellrowborder" valign="top" width="23.17231723172317%" headers="mcps1.2.4.1.1 "><p id="p11309175275117"><a name="p11309175275117"></a><a name="p11309175275117"></a>operationId_</p>
</td>
<td class="cellrowborder" valign="top" width="43.494349434943494%" headers="mcps1.2.4.1.2 "><p id="p1530925235120"><a name="p1530925235120"></a><a name="p1530925235120"></a>类型：int</p>
<p id="p5309165265113"><a name="p5309165265113"></a><a name="p5309165265113"></a>作用：目前暂未启用。</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.3 "><p id="p030912527512"><a name="p030912527512"></a><a name="p030912527512"></a>0</p>
</td>
</tr>
<tr id="row182749478511"><td class="cellrowborder" valign="top" width="23.17231723172317%" headers="mcps1.2.4.1.1 "><p id="p1931035225114"><a name="p1931035225114"></a><a name="p1931035225114"></a>transactionId_</p>
</td>
<td class="cellrowborder" valign="top" width="43.494349434943494%" headers="mcps1.2.4.1.2 "><p id="p13101152175113"><a name="p13101152175113"></a><a name="p13101152175113"></a>类型：long long</p>
<p id="p12310125215120"><a name="p12310125215120"></a><a name="p12310125215120"></a>作用：事务ID，唯一标识clientId+sessionId。</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.3 "><p id="p1831005265113"><a name="p1831005265113"></a><a name="p1831005265113"></a>0</p>
</td>
</tr>
<tr id="row14274134755111"><td class="cellrowborder" valign="top" width="23.17231723172317%" headers="mcps1.2.4.1.1 "><p id="p1931045285110"><a name="p1931045285110"></a><a name="p1931045285110"></a>algoPluginType_</p>
</td>
<td class="cellrowborder" valign="top" width="43.494349434943494%" headers="mcps1.2.4.1.2 "><p id="p143101452165112"><a name="p143101452165112"></a><a name="p143101452165112"></a>类型：int</p>
<p id="p2310352145115"><a name="p2310352145115"></a><a name="p2310352145115"></a>作用：引擎框架根据插件加载顺序分配的算法类型的ID。</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.3 "><p id="p8310152115111"><a name="p8310152115111"></a><a name="p8310152115111"></a>0</p>
</td>
</tr>
<tr id="row11275547135119"><td class="cellrowborder" valign="top" width="23.17231723172317%" headers="mcps1.2.4.1.1 "><p id="p1331035212512"><a name="p1331035212512"></a><a name="p1331035212512"></a>msg_</p>
</td>
<td class="cellrowborder" valign="top" width="43.494349434943494%" headers="mcps1.2.4.1.2 "><p id="p63104525518"><a name="p63104525518"></a><a name="p63104525518"></a>类型：DataInfo</p>
<p id="p10310352125110"><a name="p10310352125110"></a><a name="p10310352125110"></a>作用：存放调用算法接口的输入数据。</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.3 "><p id="p7310125218519"><a name="p7310125218519"></a><a name="p7310125218519"></a>.data = nullptr</p>
<p id="p0310185235113"><a name="p0310185235113"></a><a name="p0310185235113"></a>.length = 0</p>
</td>
</tr>
</tbody>
</table>

Response类的属性如下[表4](#table1798597135212)所示。

**表 4**  Response类的属性

<a name="table1798597135212"></a>
<table><thead align="left"><tr id="row209850785217"><th class="cellrowborder" valign="top" width="22.122212221222124%" id="mcps1.2.4.1.1"><p id="p6669101317529"><a name="p6669101317529"></a><a name="p6669101317529"></a>属性名称</p>
</th>
<th class="cellrowborder" valign="top" width="49.834983498349835%" id="mcps1.2.4.1.2"><p id="p1666931318527"><a name="p1666931318527"></a><a name="p1666931318527"></a>属性说明</p>
</th>
<th class="cellrowborder" valign="top" width="28.04280428042804%" id="mcps1.2.4.1.3"><p id="p1966901311520"><a name="p1966901311520"></a><a name="p1966901311520"></a>默认值</p>
</th>
</tr>
</thead>
<tbody><tr id="row149854735212"><td class="cellrowborder" valign="top" width="22.122212221222124%" headers="mcps1.2.4.1.1 "><p id="p166901314528"><a name="p166901314528"></a><a name="p166901314528"></a>innerSequenceId_</p>
</td>
<td class="cellrowborder" valign="top" width="49.834983498349835%" headers="mcps1.2.4.1.2 "><p id="p166691813145216"><a name="p166691813145216"></a><a name="p166691813145216"></a>类型：long long</p>
<p id="p17669151316526"><a name="p17669151316526"></a><a name="p17669151316526"></a>作用：暂未启用。</p>
</td>
<td class="cellrowborder" valign="top" width="28.04280428042804%" headers="mcps1.2.4.1.3 "><p id="p136691135528"><a name="p136691135528"></a><a name="p136691135528"></a>0</p>
</td>
</tr>
<tr id="row199868705211"><td class="cellrowborder" valign="top" width="22.122212221222124%" headers="mcps1.2.4.1.1 "><p id="p11669813145211"><a name="p11669813145211"></a><a name="p11669813145211"></a>requestId_</p>
</td>
<td class="cellrowborder" valign="top" width="49.834983498349835%" headers="mcps1.2.4.1.2 "><p id="p10669201316529"><a name="p10669201316529"></a><a name="p10669201316529"></a>类型：int</p>
<p id="p166693133522"><a name="p166693133522"></a><a name="p166693133522"></a>作用：标识请求序列，用于绑定返回运算结果。</p>
</td>
<td class="cellrowborder" valign="top" width="28.04280428042804%" headers="mcps1.2.4.1.3 "><p id="p266961385216"><a name="p266961385216"></a><a name="p266961385216"></a>0</p>
</td>
</tr>
<tr id="row1898612735212"><td class="cellrowborder" valign="top" width="22.122212221222124%" headers="mcps1.2.4.1.1 "><p id="p066951315526"><a name="p066951315526"></a><a name="p066951315526"></a>retCode__</p>
</td>
<td class="cellrowborder" valign="top" width="49.834983498349835%" headers="mcps1.2.4.1.2 "><p id="p166991310529"><a name="p166991310529"></a><a name="p166991310529"></a>类型：int</p>
<p id="p146692134527"><a name="p146692134527"></a><a name="p146692134527"></a>作用：异步执行算法推理结果码。</p>
</td>
<td class="cellrowborder" valign="top" width="28.04280428042804%" headers="mcps1.2.4.1.3 "><p id="p5669101395220"><a name="p5669101395220"></a><a name="p5669101395220"></a>0</p>
</td>
</tr>
<tr id="row298617775218"><td class="cellrowborder" valign="top" width="22.122212221222124%" headers="mcps1.2.4.1.1 "><p id="p1966921318528"><a name="p1966921318528"></a><a name="p1966921318528"></a>retDesc_</p>
</td>
<td class="cellrowborder" valign="top" width="49.834983498349835%" headers="mcps1.2.4.1.2 "><p id="p36691613155217"><a name="p36691613155217"></a><a name="p36691613155217"></a>类型：string</p>
<p id="p1067091319529"><a name="p1067091319529"></a><a name="p1067091319529"></a>作用：暂未启用。</p>
</td>
<td class="cellrowborder" valign="top" width="28.04280428042804%" headers="mcps1.2.4.1.3 "><p id="p15670191355218"><a name="p15670191355218"></a><a name="p15670191355218"></a>-</p>
</td>
</tr>
<tr id="row798614711527"><td class="cellrowborder" valign="top" width="22.122212221222124%" headers="mcps1.2.4.1.1 "><p id="p1467011314524"><a name="p1467011314524"></a><a name="p1467011314524"></a>transactionId_</p>
</td>
<td class="cellrowborder" valign="top" width="49.834983498349835%" headers="mcps1.2.4.1.2 "><p id="p1567010132524"><a name="p1567010132524"></a><a name="p1567010132524"></a>类型：long long</p>
<p id="p0670161311522"><a name="p0670161311522"></a><a name="p0670161311522"></a>作用：事务ID，唯一标识clientId+sessionId。</p>
</td>
<td class="cellrowborder" valign="top" width="28.04280428042804%" headers="mcps1.2.4.1.3 "><p id="p86701313135217"><a name="p86701313135217"></a><a name="p86701313135217"></a>0</p>
</td>
</tr>
<tr id="row189861676522"><td class="cellrowborder" valign="top" width="22.122212221222124%" headers="mcps1.2.4.1.1 "><p id="p567011138522"><a name="p567011138522"></a><a name="p567011138522"></a>algoPluginType_</p>
</td>
<td class="cellrowborder" valign="top" width="49.834983498349835%" headers="mcps1.2.4.1.2 "><p id="p17670121385214"><a name="p17670121385214"></a><a name="p17670121385214"></a>类型：int</p>
<p id="p1667010131526"><a name="p1667010131526"></a><a name="p1667010131526"></a>作用：引擎框架根据插件加载顺序分配的算法类型的ID。</p>
</td>
<td class="cellrowborder" valign="top" width="28.04280428042804%" headers="mcps1.2.4.1.3 "><p id="p1267015136527"><a name="p1267015136527"></a><a name="p1267015136527"></a>INVALID_ALGO_PLUGIN_TYPE(-1)</p>
</td>
</tr>
<tr id="row199862715524"><td class="cellrowborder" valign="top" width="22.122212221222124%" headers="mcps1.2.4.1.1 "><p id="p1670913155216"><a name="p1670913155216"></a><a name="p1670913155216"></a>result_</p>
</td>
<td class="cellrowborder" valign="top" width="49.834983498349835%" headers="mcps1.2.4.1.2 "><p id="p1670191315529"><a name="p1670191315529"></a><a name="p1670191315529"></a>类型：DataInfo</p>
<p id="p4670313155214"><a name="p4670313155214"></a><a name="p4670313155214"></a>作用：存放异步算法推理结果。</p>
</td>
<td class="cellrowborder" valign="top" width="28.04280428042804%" headers="mcps1.2.4.1.3 "><p id="p20670101375219"><a name="p20670101375219"></a><a name="p20670101375219"></a>.data = nullptr</p>
<p id="p867010135520"><a name="p867010135520"></a><a name="p867010135520"></a>.length = 0</p>
</td>
</tr>
</tbody>
</table>

具体开发过程可参考唤醒词识别插件开发示例。

