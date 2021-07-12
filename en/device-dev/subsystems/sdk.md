# SDK<a name="EN-US_TOPIC_0000001077607682"></a>

The function of the SDK header file is implemented by mapping SDK API calls to client API calls.  [Table 1](#table203963834718)  lists the APIs provided by the client.

**Table  1**  APIs provided by the client

<a name="table203963834718"></a>
<table><thead align="left"><tr id="row173964834716"><th class="cellrowborder" valign="top" width="33.33333333333333%" id="mcps1.2.4.1.1"><p id="p20921103144918"><a name="p20921103144918"></a><a name="p20921103144918"></a>API</p>
</th>
<th class="cellrowborder" valign="top" width="23.03230323032303%" id="mcps1.2.4.1.2"><p id="p109216317495"><a name="p109216317495"></a><a name="p109216317495"></a>Description</p>
</th>
<th class="cellrowborder" valign="top" width="43.634363436343634%" id="mcps1.2.4.1.3"><p id="p1192112316497"><a name="p1192112316497"></a><a name="p1192112316497"></a>Parameters</p>
</th>
</tr>
</thead>
<tbody><tr id="row4397198154712"><td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.1 "><p id="p179221331104919"><a name="p179221331104919"></a><a name="p179221331104919"></a>int <strong id="b15922731104916"><a name="b15922731104916"></a><a name="b15922731104916"></a>AieClientInit</strong>(const ConfigInfo &amp;configInfo, ClientInfo &amp;clientInfo, const AlgorithmInfo &amp;algorithmInfo, IServiceDeadCb *cb)</p>
</td>
<td class="cellrowborder" valign="top" width="23.03230323032303%" headers="mcps1.2.4.1.2 "><p id="p199227318499"><a name="p199227318499"></a><a name="p199227318499"></a><strong id="b13441162819186"><a name="b13441162819186"></a><a name="b13441162819186"></a>Function</strong>: Links and initializes the engine service and activates IPC call.</p>
<p id="p9922153110492"><a name="p9922153110492"></a><a name="p9922153110492"></a><strong id="b170141173719"><a name="b170141173719"></a><a name="b170141173719"></a>Return value</strong>: Returns <strong id="b147515111372"><a name="b147515111372"></a><a name="b147515111372"></a>0</strong> if the operation is successful; returns a non-zero value otherwise.</p>
</td>
<td class="cellrowborder" valign="top" width="43.634363436343634%" headers="mcps1.2.4.1.3 "><p id="p4350171113110"><a name="p4350171113110"></a><a name="p4350171113110"></a><strong id="b172457843913"><a name="b172457843913"></a><a name="b172457843913"></a>configInfo</strong>: Indicates engine-related initial configuration data. This parameter must not be null.</p>
<p id="p4922173116498"><a name="p4922173116498"></a><a name="p4922173116498"></a><strong id="b795413313395"><a name="b795413313395"></a><a name="b795413313395"></a>clientInfo</strong>: Indicates engine client information. This parameter must not be null.</p>
<p id="p18922931134919"><a name="p18922931134919"></a><a name="p18922931134919"></a><strong id="b1120348134615"><a name="b1120348134615"></a><a name="b1120348134615"></a>algorithmInfo</strong>: Indicates information about the called algorithm. This parameter must not be null.</p>
<p id="p592283164916"><a name="p592283164916"></a><a name="p592283164916"></a><strong id="b12672821164720"><a name="b12672821164720"></a><a name="b12672821164720"></a>cb</strong>: Indicates the death callback object. This parameter can be null.</p>
</td>
</tr>
<tr id="row1839716854716"><td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.1 "><p id="p15922153154919"><a name="p15922153154919"></a><a name="p15922153154919"></a>int <strong id="b1922831144914"><a name="b1922831144914"></a><a name="b1922831144914"></a>AieClientPrepare</strong>(const ClientInfo &amp;clientInfo, const AlgorithmInfo &amp;algorithmInfo, const DataInfo &amp;inputInfo, DataInfo &amp;outputInfo, IClientCb *cb)</p>
</td>
<td class="cellrowborder" valign="top" width="23.03230323032303%" headers="mcps1.2.4.1.2 "><p id="p14922113114914"><a name="p14922113114914"></a><a name="p14922113114914"></a><strong id="b912863320185"><a name="b912863320185"></a><a name="b912863320185"></a>Function</strong>: Loads an algorithm plug-in.</p>
<p id="p5922331114916"><a name="p5922331114916"></a><a name="p5922331114916"></a><strong id="b1924517315515"><a name="b1924517315515"></a><a name="b1924517315515"></a>Return value</strong>: Returns <strong id="b3246532516"><a name="b3246532516"></a><a name="b3246532516"></a>0</strong> if the operation is successful; returns a non-zero value otherwise.</p>
</td>
<td class="cellrowborder" valign="top" width="43.634363436343634%" headers="mcps1.2.4.1.3 "><p id="p17922183120490"><a name="p17922183120490"></a><a name="p17922183120490"></a><strong id="b725819995114"><a name="b725819995114"></a><a name="b725819995114"></a>clientInfo</strong>: Indicates engine client information. This parameter must not be null.</p>
<p id="p8922193154917"><a name="p8922193154917"></a><a name="p8922193154917"></a><strong id="b15875246121420"><a name="b15875246121420"></a><a name="b15875246121420"></a>algorithmInfo</strong>: Indicates information about the called algorithm. This parameter must not be null.</p>
<p id="p192293134912"><a name="p192293134912"></a><a name="p192293134912"></a><strong id="b15627162015517"><a name="b15627162015517"></a><a name="b15627162015517"></a>inputInfo</strong>: Indicates input information specified for algorithm plug-in loading. This parameter can be null.</p>
<p id="p1492219316494"><a name="p1492219316494"></a><a name="p1492219316494"></a><strong id="b1583175435114"><a name="b1583175435114"></a><a name="b1583175435114"></a>outputInfo</strong>: Indicates information returned after algorithm plug-in loading, if any. This parameter can be null.</p>
<p id="p12922931134913"><a name="p12922931134913"></a><a name="p12922931134913"></a><strong id="b3784829145316"><a name="b3784829145316"></a><a name="b3784829145316"></a>cb</strong>: Indicates the return result of the asynchronous algorithm. This parameter must not be null for the asynchronous algorithm. For the synchronous algorithm, this parameter must be null.</p>
</td>
</tr>
<tr id="row6397138134713"><td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.1 "><p id="p6923143184914"><a name="p6923143184914"></a><a name="p6923143184914"></a>int <strong id="b7923231144918"><a name="b7923231144918"></a><a name="b7923231144918"></a>AieClientAsyncProcess</strong>(const ClientInfo &amp;clientInfo, const AlgorithmInfo &amp;algorithmInfo, const DataInfo &amp;inputInfo)</p>
</td>
<td class="cellrowborder" valign="top" width="23.03230323032303%" headers="mcps1.2.4.1.2 "><p id="p792383116495"><a name="p792383116495"></a><a name="p792383116495"></a><strong id="b172326389919"><a name="b172326389919"></a><a name="b172326389919"></a>Function</strong>: Executes an asynchronous algorithm.</p>
<p id="p139231531184912"><a name="p139231531184912"></a><a name="p139231531184912"></a><strong id="b37381339391"><a name="b37381339391"></a><a name="b37381339391"></a>Return value</strong>: Returns <strong id="b18743103912917"><a name="b18743103912917"></a><a name="b18743103912917"></a>0</strong> if the operation is successful; returns a non-zero value otherwise.</p>
</td>
<td class="cellrowborder" valign="top" width="43.634363436343634%" headers="mcps1.2.4.1.3 "><p id="p1592323144910"><a name="p1592323144910"></a><a name="p1592323144910"></a><strong id="b1178439918"><a name="b1178439918"></a><a name="b1178439918"></a>clientInfo</strong>: Indicates engine client information. This parameter must not be null.</p>
<p id="p199231831194912"><a name="p199231831194912"></a><a name="p199231831194912"></a><strong id="b1944312201011"><a name="b1944312201011"></a><a name="b1944312201011"></a>algorithmInfo</strong>: Indicates information about the called algorithm. This parameter must not be null.</p>
<p id="p6924173115491"><a name="p6924173115491"></a><a name="p6924173115491"></a><strong id="b14257151715100"><a name="b14257151715100"></a><a name="b14257151715100"></a>inputInfo</strong>: Indicates input information specified for algorithm operations. This parameter can be null.</p>
</td>
</tr>
<tr id="row43981283476"><td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.1 "><p id="p992473112496"><a name="p992473112496"></a><a name="p992473112496"></a>int <strong id="b292493134918"><a name="b292493134918"></a><a name="b292493134918"></a>AieClientSyncProcess</strong>(const ClientInfo &amp;clientInfo, const AlgorithmInfo &amp;algorithmInfo, const DataInfo &amp;inputInfo, DataInfo &amp;outputInfo)</p>
</td>
<td class="cellrowborder" valign="top" width="23.03230323032303%" headers="mcps1.2.4.1.2 "><p id="p14924831124913"><a name="p14924831124913"></a><a name="p14924831124913"></a><strong id="b885383113273"><a name="b885383113273"></a><a name="b885383113273"></a>Function</strong>: Executes a synchronous algorithm.</p>
<p id="p14924203134910"><a name="p14924203134910"></a><a name="p14924203134910"></a><strong id="b17382123702712"><a name="b17382123702712"></a><a name="b17382123702712"></a>Return value</strong>: Returns <strong id="b4382173717276"><a name="b4382173717276"></a><a name="b4382173717276"></a>0</strong> if the operation is successful; returns a non-zero value otherwise.</p>
</td>
<td class="cellrowborder" valign="top" width="43.634363436343634%" headers="mcps1.2.4.1.3 "><p id="p189243318494"><a name="p189243318494"></a><a name="p189243318494"></a><strong id="b20515558161616"><a name="b20515558161616"></a><a name="b20515558161616"></a>clientInfo</strong>: Indicates engine client information. This parameter must not be null.</p>
<p id="p2924133124918"><a name="p2924133124918"></a><a name="p2924133124918"></a><strong id="b37605331717"><a name="b37605331717"></a><a name="b37605331717"></a>algorithmInfo</strong>: Indicates information about the called algorithm. This parameter must not be null.</p>
<p id="p1692403115493"><a name="p1692403115493"></a><a name="p1692403115493"></a><strong id="b182067751711"><a name="b182067751711"></a><a name="b182067751711"></a>inputInfo</strong>: Indicates input information specified for algorithm operations. This parameter can be null.</p>
<p id="p392443174917"><a name="p392443174917"></a><a name="p392443174917"></a><strong id="b79131511171714"><a name="b79131511171714"></a><a name="b79131511171714"></a>outputInfo</strong>: Indicates output information in the return result of the synchronous algorithm. This parameter can be null.</p>
</td>
</tr>
<tr id="row439813812472"><td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.1 "><p id="p17925631194911"><a name="p17925631194911"></a><a name="p17925631194911"></a>int <strong id="b8925123113494"><a name="b8925123113494"></a><a name="b8925123113494"></a>AieClientRelease</strong>(const ClientInfo &amp;clientInfo, const AlgorithmInfo &amp;algorithmInfo, const DataInfo &amp;inputInfo)</p>
</td>
<td class="cellrowborder" valign="top" width="23.03230323032303%" headers="mcps1.2.4.1.2 "><p id="p1892583174920"><a name="p1892583174920"></a><a name="p1892583174920"></a><strong id="b14896112094719"><a name="b14896112094719"></a><a name="b14896112094719"></a>Function</strong>: Uninstalls an algorithm plug-in.</p>
<p id="p16925113119497"><a name="p16925113119497"></a><a name="p16925113119497"></a><strong id="b184731730104716"><a name="b184731730104716"></a><a name="b184731730104716"></a>Return value</strong>: Returns <strong id="b17478230114714"><a name="b17478230114714"></a><a name="b17478230114714"></a>0</strong> if the operation is successful; returns a non-zero value otherwise.</p>
</td>
<td class="cellrowborder" valign="top" width="43.634363436343634%" headers="mcps1.2.4.1.3 "><p id="p59255313493"><a name="p59255313493"></a><a name="p59255313493"></a><strong id="b108167619488"><a name="b108167619488"></a><a name="b108167619488"></a>clientInfo</strong>: Indicates engine client information. This parameter must not be null.</p>
<p id="p1692517314499"><a name="p1692517314499"></a><a name="p1692517314499"></a><strong id="b189871213481"><a name="b189871213481"></a><a name="b189871213481"></a>algorithmInfo</strong>: Indicates information about the algorithm plug-in to be uninstalled. This parameter must not be null.</p>
<p id="p14925631194912"><a name="p14925631194912"></a><a name="p14925631194912"></a><strong id="b16790163214488"><a name="b16790163214488"></a><a name="b16790163214488"></a>inputInfo</strong>: Indicates input information specified for algorithm plug-in uninstallation. This parameter can be null.</p>
</td>
</tr>
<tr id="row123998813470"><td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.1 "><p id="p492513120494"><a name="p492513120494"></a><a name="p492513120494"></a>int <strong id="b139251331144916"><a name="b139251331144916"></a><a name="b139251331144916"></a>AieClientDestroy</strong>(ClientInfo &amp;clientInfo)</p>
</td>
<td class="cellrowborder" valign="top" width="23.03230323032303%" headers="mcps1.2.4.1.2 "><p id="p12925143118492"><a name="p12925143118492"></a><a name="p12925143118492"></a><strong id="b14954713125014"><a name="b14954713125014"></a><a name="b14954713125014"></a>Function</strong>: Disconnects from the server and releases the cache.</p>
<p id="p5926031124914"><a name="p5926031124914"></a><a name="p5926031124914"></a><strong id="b102283247503"><a name="b102283247503"></a><a name="b102283247503"></a>Return value</strong>: Returns <strong id="b8233142411503"><a name="b8233142411503"></a><a name="b8233142411503"></a>0</strong> if the operation is successful; returns a non-zero value otherwise.</p>
</td>
<td class="cellrowborder" valign="top" width="43.634363436343634%" headers="mcps1.2.4.1.3 "><p id="p1692683112499"><a name="p1692683112499"></a><a name="p1692683112499"></a><strong id="b151201529105015"><a name="b151201529105015"></a><a name="b151201529105015"></a>clientInfo</strong>: Indicates information about the engine client to be destroyed. This parameter must not be null.</p>
</td>
</tr>
<tr id="row166991140328"><td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.1 "><p id="p26995401922"><a name="p26995401922"></a><a name="p26995401922"></a>int <strong id="b992616317493"><a name="b992616317493"></a><a name="b992616317493"></a>AieClientSetOption</strong>(const ClientInfo &amp;clientInfo, int optionType, const DataInfo &amp;inputInfo)</p>
</td>
<td class="cellrowborder" valign="top" width="23.03230323032303%" headers="mcps1.2.4.1.2 "><p id="p892633118493"><a name="p892633118493"></a><a name="p892633118493"></a><strong id="b419171265110"><a name="b419171265110"></a><a name="b419171265110"></a>Function</strong>: Sets configuration items. You can use this API to pass algorithm's extended information to plug-ins.</p>
<p id="p166531559429"><a name="p166531559429"></a><a name="p166531559429"></a><strong id="b365717397512"><a name="b365717397512"></a><a name="b365717397512"></a>Return value</strong>: Returns <strong id="b76651539175118"><a name="b76651539175118"></a><a name="b76651539175118"></a>0</strong> if the operation is successful; returns a non-zero value otherwise.</p>
</td>
<td class="cellrowborder" valign="top" width="43.634363436343634%" headers="mcps1.2.4.1.3 "><p id="p119277312492"><a name="p119277312492"></a><a name="p119277312492"></a><strong id="b7651131105216"><a name="b7651131105216"></a><a name="b7651131105216"></a>clientInfo</strong>: Indicates engine client information. This parameter must not be null.</p>
<p id="p159271031184915"><a name="p159271031184915"></a><a name="p159271031184915"></a><strong id="b4875332173319"><a name="b4875332173319"></a><a name="b4875332173319"></a>optionType</strong>: Indicates the algorithm for obtaining the configuration item information. An algorithm plug-in can use this parameter as needed. This parameter must not be null.</p>
<p id="p163731116313"><a name="p163731116313"></a><a name="p163731116313"></a><strong id="b16454175203613"><a name="b16454175203613"></a><a name="b16454175203613"></a>inputInfo</strong>: Indicates algorithm parameter information. An algorithm plug-in can use this parameter as needed. This parameter can be null.</p>
</td>
</tr>
<tr id="row939914814478"><td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.1 "><p id="p992713144920"><a name="p992713144920"></a><a name="p992713144920"></a>int <strong id="b6927163174918"><a name="b6927163174918"></a><a name="b6927163174918"></a>AieClientGetOption</strong>(const ClientInfo &amp;clientInfo, int optionType, const DataInfo &amp;inputInfo, DataInfo &amp;outputInfo)</p>
</td>
<td class="cellrowborder" valign="top" width="23.03230323032303%" headers="mcps1.2.4.1.2 "><p id="p1927031114910"><a name="p1927031114910"></a><a name="p1927031114910"></a><strong id="b1484102953810"><a name="b1484102953810"></a><a name="b1484102953810"></a>Function</strong>: Obtains configuration item information based on the specified <strong id="b124632567381"><a name="b124632567381"></a><a name="b124632567381"></a>optionType</strong> and <strong id="b558110589386"><a name="b558110589386"></a><a name="b558110589386"></a>inputInfo</strong>.</p>
<p id="p1792723174913"><a name="p1792723174913"></a><a name="p1792723174913"></a><strong id="b184331910185218"><a name="b184331910185218"></a><a name="b184331910185218"></a>Return value</strong>: Returns <strong id="b4439131065216"><a name="b4439131065216"></a><a name="b4439131065216"></a>0</strong> if the operation is successful; returns a non-zero value otherwise.</p>
</td>
<td class="cellrowborder" valign="top" width="43.634363436343634%" headers="mcps1.2.4.1.3 "><p id="p0927173154916"><a name="p0927173154916"></a><a name="p0927173154916"></a><strong id="b050871313524"><a name="b050871313524"></a><a name="b050871313524"></a>clientInfo</strong>: Indicates engine client information. This parameter must not be null.</p>
<p id="p5927131114914"><a name="p5927131114914"></a><a name="p5927131114914"></a><strong id="b1697610514445"><a name="b1697610514445"></a><a name="b1697610514445"></a>optionType</strong>: Indicates the algorithm for obtaining the configuration item information. This parameter must not be null.</p>
<p id="p69283313491"><a name="p69283313491"></a><a name="p69283313491"></a><strong id="b1783310194518"><a name="b1783310194518"></a><a name="b1783310194518"></a>inputInfo</strong>: Indicates input information specified for obtaining configuration item information of the algorithm. This parameter can be null.</p>
<p id="p8928431104914"><a name="p8928431104914"></a><a name="p8928431104914"></a><strong id="b139522410538"><a name="b139522410538"></a><a name="b139522410538"></a>outputInfo</strong>: Indicates the configuration item information in the return result. This parameter can be null.</p>
</td>
</tr>
</tbody>
</table>

[Table 2](#table22154317482)  describes the data structure of  **ConfigInfo**,  **ClientInfo**,  **AlgorithmInfo**, and  **DataInfo**.

**Table  2**  Data structure of ConfigInfo, ClientInfo, AlgorithmInfo, and DataInfo

<a name="table22154317482"></a>
<table><thead align="left"><tr id="row6215103164810"><th class="cellrowborder" valign="top" width="16.65166516651665%" id="mcps1.2.4.1.1"><p id="p4265171044816"><a name="p4265171044816"></a><a name="p4265171044816"></a>Structure</p>
</th>
<th class="cellrowborder" valign="top" width="25.962596259625965%" id="mcps1.2.4.1.2"><p id="p2266110174819"><a name="p2266110174819"></a><a name="p2266110174819"></a>Description</p>
</th>
<th class="cellrowborder" valign="top" width="57.38573857385738%" id="mcps1.2.4.1.3"><p id="p1626618102488"><a name="p1626618102488"></a><a name="p1626618102488"></a>Attributes</p>
</th>
</tr>
</thead>
<tbody><tr id="row17216183174817"><td class="cellrowborder" valign="top" width="16.65166516651665%" headers="mcps1.2.4.1.1 "><p id="p283074964915"><a name="p283074964915"></a><a name="p283074964915"></a>ConfigInfo</p>
</td>
<td class="cellrowborder" valign="top" width="25.962596259625965%" headers="mcps1.2.4.1.2 "><p id="p48301649114915"><a name="p48301649114915"></a><a name="p48301649114915"></a>Algorithm configuration item information</p>
</td>
<td class="cellrowborder" valign="top" width="57.38573857385738%" headers="mcps1.2.4.1.3 "><p id="p783054924913"><a name="p783054924913"></a><a name="p783054924913"></a><strong id="b383094934918"><a name="b383094934918"></a><a name="b383094934918"></a>const char *description</strong>: Indicates the body of configuration item information.</p>
</td>
</tr>
<tr id="row721619312480"><td class="cellrowborder" valign="top" width="16.65166516651665%" headers="mcps1.2.4.1.1 "><p id="p98305491499"><a name="p98305491499"></a><a name="p98305491499"></a>ClientInfo</p>
</td>
<td class="cellrowborder" valign="top" width="25.962596259625965%" headers="mcps1.2.4.1.2 "><p id="p17830154920494"><a name="p17830154920494"></a><a name="p17830154920494"></a>Client information</p>
</td>
<td class="cellrowborder" valign="top" width="57.38573857385738%" headers="mcps1.2.4.1.3 "><p id="p198309499494"><a name="p198309499494"></a><a name="p198309499494"></a><strong id="b98303498492"><a name="b98303498492"></a><a name="b98303498492"></a>long long clientVersion</strong>: Indicates client version number. This parameter is not used currently.</p>
<p id="p15830749154912"><a name="p15830749154912"></a><a name="p15830749154912"></a><strong id="b1383084912498"><a name="b1383084912498"></a><a name="b1383084912498"></a>int clientId</strong>: Indicates the client ID.</p>
<p id="p38302049174916"><a name="p38302049174916"></a><a name="p38302049174916"></a><strong id="b6723194918202"><a name="b6723194918202"></a><a name="b6723194918202"></a>int sessionId</strong>: Indicates the session ID.</p>
<p id="p38302049174916"><a name="p38302049174916"></a><a name="p38302049174916"></a><strong id="b6723194918202"><a name="b6723194918202"></a><a name="b6723194918202"></a>uid_t serverUid</strong>: Indicates the server UID.</p>
<p id="p38302049174916"><a name="p38302049174916"></a><a name="p38302049174916"></a><strong id="b6723194918202"><a name="b6723194918202"></a><a name="b6723194918202"></a>uid_t clientUid</strong>: Indicates the client UID.</p>
<p id="p1183104954914"><a name="p1183104954914"></a><a name="p1183104954914"></a><strong id="b204492316219"><a name="b204492316219"></a><a name="b204492316219"></a>int extendLen</strong>: Indicates the length of the extended information (<strong id="b1559511017336"><a name="b1559511017336"></a><a name="b1559511017336"></a>extendMsg</strong>).</p>
<p id="p11831124994912"><a name="p11831124994912"></a><a name="p11831124994912"></a><strong id="b1383134914916"><a name="b1383134914916"></a><a name="b1383134914916"></a>unsigned char *extendMsg</strong>: Indicates the body of the extended information.</p>
</td>
</tr>
<tr id="row16278112314319"><td class="cellrowborder" valign="top" width="16.65166516651665%" headers="mcps1.2.4.1.1 "><p id="p162788231732"><a name="p162788231732"></a><a name="p162788231732"></a>AlgorithmInfo</p>
</td>
<td class="cellrowborder" valign="top" width="25.962596259625965%" headers="mcps1.2.4.1.2 "><p id="p1027882317314"><a name="p1027882317314"></a><a name="p1027882317314"></a>Algorithm information</p>
</td>
<td class="cellrowborder" valign="top" width="57.38573857385738%" headers="mcps1.2.4.1.3 "><p id="p5831849124917"><a name="p5831849124917"></a><a name="p5831849124917"></a><strong id="b45465127235"><a name="b45465127235"></a><a name="b45465127235"></a>long long clientVersion</strong>: Indicates client version number. This parameter is not used currently.</p>
<p id="p5831749164916"><a name="p5831749164916"></a><a name="p5831749164916"></a><strong id="b78316491497"><a name="b78316491497"></a><a name="b78316491497"></a>bool isAsync</strong>: Indicates whether asynchronous execution is used.</p>
<p id="p1983164910493"><a name="p1983164910493"></a><a name="p1983164910493"></a><strong id="b4831154944912"><a name="b4831154944912"></a><a name="b4831154944912"></a>int algorithmType</strong>: Indicates the algorithm type ID allocated by the AI engine framework based on the plug-in loading sequence.</p>
<p id="p1883184914916"><a name="p1883184914916"></a><a name="p1883184914916"></a><strong id="b783164913498"><a name="b783164913498"></a><a name="b783164913498"></a>long long algorithmVersion</strong>: Indicates the algorithm version number.</p>
<p id="p78311449174914"><a name="p78311449174914"></a><a name="p78311449174914"></a><strong id="b1883124910493"><a name="b1883124910493"></a><a name="b1883124910493"></a>bool isCloud</strong>: Indicates whether to migrate data to the cloud. This parameter is not used currently.</p>
<p id="p168321349114912"><a name="p168321349114912"></a><a name="p168321349114912"></a><strong id="b4832194944913"><a name="b4832194944913"></a><a name="b4832194944913"></a>int operateId</strong>: Indicates the execution ID. This parameter is not used currently.</p>
<p id="p683234934911"><a name="p683234934911"></a><a name="p683234934911"></a><strong id="b11832144910491"><a name="b11832144910491"></a><a name="b11832144910491"></a>int requestId</strong>: Indicates the request ID, which identifies each request and corresponds to the execution result.</p>
<p id="p108320499498"><a name="p108320499498"></a><a name="p108320499498"></a><strong id="b1756835923012"><a name="b1756835923012"></a><a name="b1756835923012"></a>int extendLen</strong>: Indicates the length of the extended information (<strong id="b196260465325"><a name="b196260465325"></a><a name="b196260465325"></a>extendMsg</strong>).</p>
<p id="p91953541631"><a name="p91953541631"></a><a name="p91953541631"></a><strong id="b9501173193113"><a name="b9501173193113"></a><a name="b9501173193113"></a>unsigned char *extendMsg</strong>: Indicates the body of the extended information.</p>
</td>
</tr>
<tr id="row11216163194819"><td class="cellrowborder" valign="top" width="16.65166516651665%" headers="mcps1.2.4.1.1 "><p id="p11832104917494"><a name="p11832104917494"></a><a name="p11832104917494"></a>DataInfo</p>
</td>
<td class="cellrowborder" valign="top" width="25.962596259625965%" headers="mcps1.2.4.1.2 "><p id="p168317490499"><a name="p168317490499"></a><a name="p168317490499"></a>Algorithm input parameter configuration information (<strong id="b548444311323"><a name="b548444311323"></a><a name="b548444311323"></a>inputInfo</strong>) and output parameter configuration information (<strong id="b198223448325"><a name="b198223448325"></a><a name="b198223448325"></a>outputInfo</strong>)</p>
</td>
<td class="cellrowborder" valign="top" width="57.38573857385738%" headers="mcps1.2.4.1.3 "><p id="p1483274934919"><a name="p1483274934919"></a><a name="p1483274934919"></a><strong id="b28321849174917"><a name="b28321849174917"></a><a name="b28321849174917"></a>unsigned char *data</strong>: Indicates the data body.</p>
<p id="p383284915493"><a name="p383284915493"></a><a name="p383284915493"></a><strong id="b38321249154916"><a name="b38321249154916"></a><a name="b38321249154916"></a>int length</strong>: Indicates the data length.</p>
</td>
</tr>
</tbody>
</table>

For details about the development process, see the development example for the KWS SDK.

