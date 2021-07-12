# Plug-in<a name="EN-US_TOPIC_0000001077767652"></a>

The AI engine framework has defined a set of algorithm plug-in access specifications. Each plug-in needs to implement specified APIs to implement functions such as obtaining the plug-in version information and algorithm inference type, executing synchronous and asynchronous algorithms, loading algorithm plug-ins, uninstalling algorithm plug-ins, setting algorithm configuration information, and obtaining specified algorithm configuration information. Specifically, implement the  **SyncProcess**  API for the synchronous algorithm and the  **AsyncProcess**  API for the asynchronous algorithm.

[Table 1](#table1329717488505)  describes the  **IPlugin**  APIs.

**Table  1**  IPlugin APIs

<a name="table1329717488505"></a>
<table><thead align="left"><tr id="row52971848135020"><th class="cellrowborder" valign="top" width="33.33333333333333%" id="mcps1.2.4.1.1"><p id="p1728114205110"><a name="p1728114205110"></a><a name="p1728114205110"></a>API</p>
</th>
<th class="cellrowborder" valign="top" width="29.34293429342934%" id="mcps1.2.4.1.2"><p id="p172818410516"><a name="p172818410516"></a><a name="p172818410516"></a>Description</p>
</th>
<th class="cellrowborder" valign="top" width="37.32373237323732%" id="mcps1.2.4.1.3"><p id="p197291748518"><a name="p197291748518"></a><a name="p197291748518"></a>Parameters</p>
</th>
</tr>
</thead>
<tbody><tr id="row15297194895013"><td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.1 "><p id="p872954205114"><a name="p872954205114"></a><a name="p872954205114"></a>const long long GetVersion() const;</p>
</td>
<td class="cellrowborder" valign="top" width="29.34293429342934%" headers="mcps1.2.4.1.2 "><p id="p572944205112"><a name="p572944205112"></a><a name="p572944205112"></a><strong id="b20629921155910"><a name="b20629921155910"></a><a name="b20629921155910"></a>Function</strong>: Obtains the plug-in version information.</p>
<p id="p107294413512"><a name="p107294413512"></a><a name="p107294413512"></a><strong id="b8276163752217"><a name="b8276163752217"></a><a name="b8276163752217"></a>Return value</strong>: version number (long long)</p>
</td>
<td class="cellrowborder" valign="top" width="37.32373237323732%" headers="mcps1.2.4.1.3 "><p id="p18729174145115"><a name="p18729174145115"></a><a name="p18729174145115"></a>-</p>
</td>
</tr>
<tr id="row2297124812500"><td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.1 "><p id="p117290419511"><a name="p117290419511"></a><a name="p117290419511"></a>const char *GetInferMode() const;</p>
</td>
<td class="cellrowborder" valign="top" width="29.34293429342934%" headers="mcps1.2.4.1.2 "><p id="p27294415118"><a name="p27294415118"></a><a name="p27294415118"></a><strong id="b1533152821817"><a name="b1533152821817"></a><a name="b1533152821817"></a>Function</strong>: Obtains the algorithm inference type.</p>
<p id="p7729124165117"><a name="p7729124165117"></a><a name="p7729124165117"></a><strong id="b2038319406228"><a name="b2038319406228"></a><a name="b2038319406228"></a>Return value</strong>: <strong id="b0137831142112"><a name="b0137831142112"></a><a name="b0137831142112"></a>SYNC</strong> or <strong id="b4295192932114"><a name="b4295192932114"></a><a name="b4295192932114"></a>ASYNC</strong></p>
</td>
<td class="cellrowborder" valign="top" width="37.32373237323732%" headers="mcps1.2.4.1.3 "><p id="p107293425116"><a name="p107293425116"></a><a name="p107293425116"></a>-</p>
</td>
</tr>
<tr id="row129814805012"><td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.1 "><p id="p4729749518"><a name="p4729749518"></a><a name="p4729749518"></a>int SyncProcess(IRequest *request, IResponse *&amp;response);</p>
</td>
<td class="cellrowborder" valign="top" width="29.34293429342934%" headers="mcps1.2.4.1.2 "><p id="p273084115114"><a name="p273084115114"></a><a name="p273084115114"></a><strong id="b16617151915342"><a name="b16617151915342"></a><a name="b16617151915342"></a>Function</strong>: Executes a synchronous algorithm.</p>
<p id="p4730142514"><a name="p4730142514"></a><a name="p4730142514"></a><strong id="b102731816123611"><a name="b102731816123611"></a><a name="b102731816123611"></a>Return value</strong>: Returns <strong id="b132798168368"><a name="b132798168368"></a><a name="b132798168368"></a>0</strong> if the operation is successful; returns a non-zero value otherwise.</p>
</td>
<td class="cellrowborder" valign="top" width="37.32373237323732%" headers="mcps1.2.4.1.3 "><p id="p167306485114"><a name="p167306485114"></a><a name="p167306485114"></a><strong id="b1069405117544"><a name="b1069405117544"></a><a name="b1069405117544"></a>request</strong>: Passes the request content to the algorithm plug-in over the data channel between the engine server and the plug-in. This parameter must not be null.</p>
<p id="p373014485110"><a name="p373014485110"></a><a name="p373014485110"></a><strong id="b14964162419400"><a name="b14964162419400"></a><a name="b14964162419400"></a>response</strong>: Receives the synchronous algorithm execution result returned by the algorithm plug-in over the data channel between the engine server and the plug-in. This parameter must not be null.</p>
</td>
</tr>
<tr id="row16298748135017"><td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.1 "><p id="p187308420519"><a name="p187308420519"></a><a name="p187308420519"></a>int AsyncProcess(IRequest *request, IPluginAlgorithmCallback *callback);</p>
</td>
<td class="cellrowborder" valign="top" width="29.34293429342934%" headers="mcps1.2.4.1.2 "><p id="p17301414513"><a name="p17301414513"></a><a name="p17301414513"></a><strong id="b3141553184215"><a name="b3141553184215"></a><a name="b3141553184215"></a>Function</strong>: Executes an asynchronous algorithm.</p>
<p id="p147307419512"><a name="p147307419512"></a><a name="p147307419512"></a><strong id="b687904545214"><a name="b687904545214"></a><a name="b687904545214"></a>Return value</strong>: Returns <strong id="b15879845115212"><a name="b15879845115212"></a><a name="b15879845115212"></a>0</strong> if the operation is successful; returns a non-zero value otherwise.</p>
</td>
<td class="cellrowborder" valign="top" width="37.32373237323732%" headers="mcps1.2.4.1.3 "><p id="p187303415118"><a name="p187303415118"></a><a name="p187303415118"></a><strong id="b121481271938"><a name="b121481271938"></a><a name="b121481271938"></a>request</strong>: Passes the request content to the algorithm plug-in over the data channel between the engine server and the plug-in. This parameter must not be null.</p>
<p id="p273014415111"><a name="p273014415111"></a><a name="p273014415111"></a><strong id="b118911239511"><a name="b118911239511"></a><a name="b118911239511"></a>callback</strong>: Returns the asynchronous algorithm execution result to the engine server. This parameter must not be null.</p>
</td>
</tr>
<tr id="row0298648135020"><td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.1 "><p id="p57316445115"><a name="p57316445115"></a><a name="p57316445115"></a>int Prepare(long long transactionId, const DataInfo &amp;inputInfo, DataInfo &amp;outputInfo);</p>
</td>
<td class="cellrowborder" valign="top" width="29.34293429342934%" headers="mcps1.2.4.1.2 "><p id="p17731343517"><a name="p17731343517"></a><a name="p17731343517"></a><strong id="b0828326172412"><a name="b0828326172412"></a><a name="b0828326172412"></a>Function</strong>: Loads an algorithm plug-in.</p>
<p id="p873110465115"><a name="p873110465115"></a><a name="p873110465115"></a><strong id="b557063317174"><a name="b557063317174"></a><a name="b557063317174"></a>Return value</strong>: Returns <strong id="b1557416338177"><a name="b1557416338177"></a><a name="b1557416338177"></a>0</strong> if the operation is successful; returns a non-zero value otherwise.</p>
</td>
<td class="cellrowborder" valign="top" width="37.32373237323732%" headers="mcps1.2.4.1.3 "><p id="p17731114165112"><a name="p17731114165112"></a><a name="p17731114165112"></a><strong id="b7749839131710"><a name="b7749839131710"></a><a name="b7749839131710"></a>transactionId</strong>: Indicates the transaction ID, which is used to identify the client and session. This parameter must not be null.</p>
<p id="p13731104205111"><a name="p13731104205111"></a><a name="p13731104205111"></a><strong id="b1432792318205"><a name="b1432792318205"></a><a name="b1432792318205"></a>inputInfo</strong>: Indicates input information specified for algorithm plug-in loading. This parameter can be null.</p>
<p id="p117313420517"><a name="p117313420517"></a><a name="p117313420517"></a><strong id="b042175652110"><a name="b042175652110"></a><a name="b042175652110"></a>outputInfo</strong>: Indicates output information in the return result of algorithm plug-in loading. This parameter can be null.</p>
</td>
</tr>
<tr id="row132988482502"><td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.1 "><p id="p137312415517"><a name="p137312415517"></a><a name="p137312415517"></a>int Release(bool isFullUnload, long long transactionId, const DataInfo &amp;inputInfo);</p>
</td>
<td class="cellrowborder" valign="top" width="29.34293429342934%" headers="mcps1.2.4.1.2 "><p id="p1473114420516"><a name="p1473114420516"></a><a name="p1473114420516"></a><strong id="b114914567339"><a name="b114914567339"></a><a name="b114914567339"></a>Function</strong>: Uninstalls an algorithm plug-in.</p>
<p id="p973184165118"><a name="p973184165118"></a><a name="p973184165118"></a><strong id="b78344137343"><a name="b78344137343"></a><a name="b78344137343"></a>Return value</strong>: Returns <strong id="b1783421310349"><a name="b1783421310349"></a><a name="b1783421310349"></a>0</strong> if the operation is successful; returns a non-zero value otherwise.</p>
</td>
<td class="cellrowborder" valign="top" width="37.32373237323732%" headers="mcps1.2.4.1.3 "><p id="p7732546518"><a name="p7732546518"></a><a name="p7732546518"></a><strong id="b1874862293815"><a name="b1874862293815"></a><a name="b1874862293815"></a>isFullUnload</strong>: Indicates whether a plug-in is called by only one client. A plug-in can be uninstalled only when it is called by only one client. This parameter must not be null.</p>
<p id="p1173213410515"><a name="p1173213410515"></a><a name="p1173213410515"></a><strong id="b11951635163814"><a name="b11951635163814"></a><a name="b11951635163814"></a>transactionId</strong>: Indicates the transaction ID, which is used to identify the client and session. This parameter must not be null.</p>
<p id="p6732642517"><a name="p6732642517"></a><a name="p6732642517"></a><strong id="b330968114416"><a name="b330968114416"></a><a name="b330968114416"></a>inputInfo</strong>: Indicates input information specified for algorithm plug-in uninstallation. This parameter can be null.</p>
</td>
</tr>
<tr id="row12991848165011"><td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.1 "><p id="p197328419511"><a name="p197328419511"></a><a name="p197328419511"></a>int SetOption(int optionType, const DataInfo &amp;inputInfo);</p>
</td>
<td class="cellrowborder" valign="top" width="29.34293429342934%" headers="mcps1.2.4.1.2 "><p id="p473213411517"><a name="p473213411517"></a><a name="p473213411517"></a><strong id="b11504650164417"><a name="b11504650164417"></a><a name="b11504650164417"></a>Function</strong>: Sets configuration items. You can use this API to pass algorithm's extended information to plug-ins.</p>
<p id="p12732440511"><a name="p12732440511"></a><a name="p12732440511"></a><strong id="b13517165514413"><a name="b13517165514413"></a><a name="b13517165514413"></a>Return value</strong>: Returns <strong id="b1522125574410"><a name="b1522125574410"></a><a name="b1522125574410"></a>0</strong> if the operation is successful; returns a non-zero value otherwise.</p>
</td>
<td class="cellrowborder" valign="top" width="37.32373237323732%" headers="mcps1.2.4.1.3 "><p id="p117321446518"><a name="p117321446518"></a><a name="p117321446518"></a><strong id="b1085717564449"><a name="b1085717564449"></a><a name="b1085717564449"></a>optionType</strong>: Indicates the algorithm for obtaining the configuration item information. An algorithm plug-in can use this parameter as needed. This parameter must not be null.</p>
<p id="p18732447514"><a name="p18732447514"></a><a name="p18732447514"></a><strong id="b1659115820440"><a name="b1659115820440"></a><a name="b1659115820440"></a>inputInfo</strong>: Indicates algorithm parameter information. An algorithm plug-in can use this parameter as needed. This parameter can be null.</p>
</td>
</tr>
<tr id="row629954865010"><td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.1 "><p id="p4733947512"><a name="p4733947512"></a><a name="p4733947512"></a>int GetOption(int optionType, const DataInfo &amp;inputInfo, DataInfo &amp;outputInfo);</p>
</td>
<td class="cellrowborder" valign="top" width="29.34293429342934%" headers="mcps1.2.4.1.2 "><p id="p177331049517"><a name="p177331049517"></a><a name="p177331049517"></a><strong id="b17538727204613"><a name="b17538727204613"></a><a name="b17538727204613"></a>Function</strong>: Obtains configuration item information based on the specified <strong id="b0543527134610"><a name="b0543527134610"></a><a name="b0543527134610"></a>optionType</strong> and <strong id="b1854413275465"><a name="b1854413275465"></a><a name="b1854413275465"></a>inputInfo</strong>.</p>
<p id="p19733114175119"><a name="p19733114175119"></a><a name="p19733114175119"></a><strong id="b347423014611"><a name="b347423014611"></a><a name="b347423014611"></a>Return value</strong>: Returns <strong id="b8479153044618"><a name="b8479153044618"></a><a name="b8479153044618"></a>0</strong> if the operation is successful; returns a non-zero value otherwise.</p>
</td>
<td class="cellrowborder" valign="top" width="37.32373237323732%" headers="mcps1.2.4.1.3 "><p id="p1273354145117"><a name="p1273354145117"></a><a name="p1273354145117"></a><strong id="b16246133304610"><a name="b16246133304610"></a><a name="b16246133304610"></a>optionType</strong>: Indicates the algorithm for obtaining the configuration item information. This parameter must not be null.</p>
<p id="p773394115116"><a name="p773394115116"></a><a name="p773394115116"></a><strong id="b9497734104614"><a name="b9497734104614"></a><a name="b9497734104614"></a>inputInfo</strong>: Indicates input information specified for obtaining configuration item information of the algorithm. This parameter can be null.</p>
<p id="p3733349519"><a name="p3733349519"></a><a name="p3733349519"></a><strong id="b1537435164617"><a name="b1537435164617"></a><a name="b1537435164617"></a>outputInfo</strong>: Indicates the configuration item information in the return result. This parameter can be null.</p>
</td>
</tr>
</tbody>
</table>

Algorithm plug-in APIs including  **Prepare**,  **SyncProcess**,  **AsyncProcess**,  **Release**,  **SetOption**, and  **GetOption**  are in 1:1 mapping with the client APIs including  **AieClientPrepare**,  **AieClientSyncProcess**,  **AieClientAsyncProcess**,  **AieClientRelease**,  **AieClientSetOption**, and  **AieClientGetOption**. The  **GetInferMode**  API is used to return the algorithm execution type, which can be synchronous or asynchronous.

[Table 2](#table461192635114)  describes the  **IPluginCallback**  APIs.

**Table  2**  IPluginCallback APIs

<a name="table461192635114"></a>
<table><thead align="left"><tr id="row1061222605116"><th class="cellrowborder" valign="top" width="28.642864286428644%" id="mcps1.2.4.1.1"><p id="p12501314513"><a name="p12501314513"></a><a name="p12501314513"></a>API</p>
</th>
<th class="cellrowborder" valign="top" width="28.062806280628067%" id="mcps1.2.4.1.2"><p id="p9501131175119"><a name="p9501131175119"></a><a name="p9501131175119"></a>Description</p>
</th>
<th class="cellrowborder" valign="top" width="43.29432943294329%" id="mcps1.2.4.1.3"><p id="p0501431145119"><a name="p0501431145119"></a><a name="p0501431145119"></a>Parameters</p>
</th>
</tr>
</thead>
<tbody><tr id="row6612726205112"><td class="cellrowborder" valign="top" width="28.642864286428644%" headers="mcps1.2.4.1.1 "><p id="p85013185116"><a name="p85013185116"></a><a name="p85013185116"></a>void OnEvent(PluginEvent event, IResponse *response);</p>
</td>
<td class="cellrowborder" valign="top" width="28.062806280628067%" headers="mcps1.2.4.1.2 "><p id="p105053145110"><a name="p105053145110"></a><a name="p105053145110"></a><strong id="b2961171272212"><a name="b2961171272212"></a><a name="b2961171272212"></a>Function</strong>: Returns the asynchronous algorithm execution result.</p>
</td>
<td class="cellrowborder" valign="top" width="43.29432943294329%" headers="mcps1.2.4.1.3 "><p id="p650193115116"><a name="p650193115116"></a><a name="p650193115116"></a><strong id="b14537929102415"><a name="b14537929102415"></a><a name="b14537929102415"></a>event</strong>: Enumerates the algorithm execution result. The value can be <strong id="b55381140182615"><a name="b55381140182615"></a><a name="b55381140182615"></a>ON_PLUGIN_SUCCEED</strong> or <strong id="b13980433268"><a name="b13980433268"></a><a name="b13980433268"></a>ON_PLUGIN_FAIL</strong>.</p>
<p id="p35053185113"><a name="p35053185113"></a><a name="p35053185113"></a><strong id="b1212654152616"><a name="b1212654152616"></a><a name="b1212654152616"></a>response</strong>: Encapsulates the algorithm execution result.</p>
</td>
</tr>
</tbody>
</table>

The  **Request**  and  **Response**  classes define the requests and responses used for communication between the AI engine server and algorithm plug-ins. A request encapsulates the request content and input data of the caller. The plug-in returns the calculation result to the AI engine server through a response.

[Table 3](#table16273647125120)  describes the attributes of the  **Request**  class.

**Table  3**  Attributes of the Request class

<a name="table16273647125120"></a>
<table><thead align="left"><tr id="row1727454745110"><th class="cellrowborder" valign="top" width="23.17231723172317%" id="mcps1.2.4.1.1"><p id="p203081522515"><a name="p203081522515"></a><a name="p203081522515"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="43.494349434943494%" id="mcps1.2.4.1.2"><p id="p1330917523513"><a name="p1330917523513"></a><a name="p1330917523513"></a>Description</p>
</th>
<th class="cellrowborder" valign="top" width="33.33333333333333%" id="mcps1.2.4.1.3"><p id="p153091152175116"><a name="p153091152175116"></a><a name="p153091152175116"></a>Default Value</p>
</th>
</tr>
</thead>
<tbody><tr id="row527454745113"><td class="cellrowborder" valign="top" width="23.17231723172317%" headers="mcps1.2.4.1.1 "><p id="p03095528514"><a name="p03095528514"></a><a name="p03095528514"></a>innerSequenceId_</p>
</td>
<td class="cellrowborder" valign="top" width="43.494349434943494%" headers="mcps1.2.4.1.2 "><p id="p730911521513"><a name="p730911521513"></a><a name="p730911521513"></a><strong id="b981061216467"><a name="b981061216467"></a><a name="b981061216467"></a>Type</strong>: long long</p>
<p id="p12309105210517"><a name="p12309105210517"></a><a name="p12309105210517"></a><strong id="b1196921312469"><a name="b1196921312469"></a><a name="b1196921312469"></a>Function</strong>: reserved</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.3 "><p id="p930919521513"><a name="p930919521513"></a><a name="p930919521513"></a>0</p>
</td>
</tr>
<tr id="row32741247175116"><td class="cellrowborder" valign="top" width="23.17231723172317%" headers="mcps1.2.4.1.1 "><p id="p3309175220514"><a name="p3309175220514"></a><a name="p3309175220514"></a>requestId_</p>
</td>
<td class="cellrowborder" valign="top" width="43.494349434943494%" headers="mcps1.2.4.1.2 "><p id="p1230915216512"><a name="p1230915216512"></a><a name="p1230915216512"></a><strong id="b138808447463"><a name="b138808447463"></a><a name="b138808447463"></a>Type</strong>: int</p>
<p id="p11309195212517"><a name="p11309195212517"></a><a name="p11309195212517"></a><strong id="b8504120114718"><a name="b8504120114718"></a><a name="b8504120114718"></a>Function</strong>: Indicates the request sequence, which is used to bind the return result.</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.3 "><p id="p1130965265119"><a name="p1130965265119"></a><a name="p1130965265119"></a>0</p>
</td>
</tr>
<tr id="row112741847115118"><td class="cellrowborder" valign="top" width="23.17231723172317%" headers="mcps1.2.4.1.1 "><p id="p11309175275117"><a name="p11309175275117"></a><a name="p11309175275117"></a>operationId_</p>
</td>
<td class="cellrowborder" valign="top" width="43.494349434943494%" headers="mcps1.2.4.1.2 "><p id="p1530925235120"><a name="p1530925235120"></a><a name="p1530925235120"></a><strong id="b7143927134813"><a name="b7143927134813"></a><a name="b7143927134813"></a>Type</strong>: int</p>
<p id="p5309165265113"><a name="p5309165265113"></a><a name="p5309165265113"></a><strong id="b142411438164814"><a name="b142411438164814"></a><a name="b142411438164814"></a>Function</strong>: reserved</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.3 "><p id="p030912527512"><a name="p030912527512"></a><a name="p030912527512"></a>0</p>
</td>
</tr>
<tr id="row182749478511"><td class="cellrowborder" valign="top" width="23.17231723172317%" headers="mcps1.2.4.1.1 "><p id="p1931035225114"><a name="p1931035225114"></a><a name="p1931035225114"></a>transactionId_</p>
</td>
<td class="cellrowborder" valign="top" width="43.494349434943494%" headers="mcps1.2.4.1.2 "><p id="p13101152175113"><a name="p13101152175113"></a><a name="p13101152175113"></a><strong id="b1547420592496"><a name="b1547420592496"></a><a name="b1547420592496"></a>Type</strong>: long long</p>
<p id="p12310125215120"><a name="p12310125215120"></a><a name="p12310125215120"></a><strong id="b12604311507"><a name="b12604311507"></a><a name="b12604311507"></a>Function</strong>: Indicates the transaction ID, which is the combination of <strong id="b2155123195211"><a name="b2155123195211"></a><a name="b2155123195211"></a>clientId</strong> and <strong id="b17763524185218"><a name="b17763524185218"></a><a name="b17763524185218"></a>sessionId</strong>.</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.3 "><p id="p1831005265113"><a name="p1831005265113"></a><a name="p1831005265113"></a>0</p>
</td>
</tr>
<tr id="row14274134755111"><td class="cellrowborder" valign="top" width="23.17231723172317%" headers="mcps1.2.4.1.1 "><p id="p1931045285110"><a name="p1931045285110"></a><a name="p1931045285110"></a>algoPluginType_</p>
</td>
<td class="cellrowborder" valign="top" width="43.494349434943494%" headers="mcps1.2.4.1.2 "><p id="p143101452165112"><a name="p143101452165112"></a><a name="p143101452165112"></a><strong id="b893851675519"><a name="b893851675519"></a><a name="b893851675519"></a>Type</strong>: int</p>
<p id="p2310352145115"><a name="p2310352145115"></a><a name="p2310352145115"></a><strong id="b78543521559"><a name="b78543521559"></a><a name="b78543521559"></a>Function</strong>: Indicates the algorithm type ID allocated by the AI engine framework based on the plug-in loading sequence.</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.3 "><p id="p8310152115111"><a name="p8310152115111"></a><a name="p8310152115111"></a>0</p>
</td>
</tr>
<tr id="row11275547135119"><td class="cellrowborder" valign="top" width="23.17231723172317%" headers="mcps1.2.4.1.1 "><p id="p1331035212512"><a name="p1331035212512"></a><a name="p1331035212512"></a>msg_</p>
</td>
<td class="cellrowborder" valign="top" width="43.494349434943494%" headers="mcps1.2.4.1.2 "><p id="p63104525518"><a name="p63104525518"></a><a name="p63104525518"></a><strong id="b1670914289565"><a name="b1670914289565"></a><a name="b1670914289565"></a>Type</strong>: DataInfo</p>
<p id="p10310352125110"><a name="p10310352125110"></a><a name="p10310352125110"></a><strong id="b151491632185612"><a name="b151491632185612"></a><a name="b151491632185612"></a>Function</strong>: Stores the input parameters for calling the algorithm API.</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.3 "><p id="p7310125218519"><a name="p7310125218519"></a><a name="p7310125218519"></a>.data = nullptr</p>
<p id="p0310185235113"><a name="p0310185235113"></a><a name="p0310185235113"></a>.length = 0</p>
</td>
</tr>
</tbody>
</table>

[Table 4](#table1798597135212)  describes the attributes of the  **Response**  class.

**Table  4**  Attributes of the Response class

<a name="table1798597135212"></a>
<table><thead align="left"><tr id="row209850785217"><th class="cellrowborder" valign="top" width="22.122212221222124%" id="mcps1.2.4.1.1"><p id="p6669101317529"><a name="p6669101317529"></a><a name="p6669101317529"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="49.834983498349835%" id="mcps1.2.4.1.2"><p id="p1666931318527"><a name="p1666931318527"></a><a name="p1666931318527"></a>Description</p>
</th>
<th class="cellrowborder" valign="top" width="28.04280428042804%" id="mcps1.2.4.1.3"><p id="p1966901311520"><a name="p1966901311520"></a><a name="p1966901311520"></a>Default Value</p>
</th>
</tr>
</thead>
<tbody><tr id="row149854735212"><td class="cellrowborder" valign="top" width="22.122212221222124%" headers="mcps1.2.4.1.1 "><p id="p166901314528"><a name="p166901314528"></a><a name="p166901314528"></a>innerSequenceId_</p>
</td>
<td class="cellrowborder" valign="top" width="49.834983498349835%" headers="mcps1.2.4.1.2 "><p id="p166691813145216"><a name="p166691813145216"></a><a name="p166691813145216"></a><strong id="b129294378214"><a name="b129294378214"></a><a name="b129294378214"></a>Type</strong>: long long</p>
<p id="p17669151316526"><a name="p17669151316526"></a><a name="p17669151316526"></a><strong id="b14115237626"><a name="b14115237626"></a><a name="b14115237626"></a>Function</strong>: reserved</p>
</td>
<td class="cellrowborder" valign="top" width="28.04280428042804%" headers="mcps1.2.4.1.3 "><p id="p136691135528"><a name="p136691135528"></a><a name="p136691135528"></a>0</p>
</td>
</tr>
<tr id="row199868705211"><td class="cellrowborder" valign="top" width="22.122212221222124%" headers="mcps1.2.4.1.1 "><p id="p11669813145211"><a name="p11669813145211"></a><a name="p11669813145211"></a>requestId_</p>
</td>
<td class="cellrowborder" valign="top" width="49.834983498349835%" headers="mcps1.2.4.1.2 "><p id="p10669201316529"><a name="p10669201316529"></a><a name="p10669201316529"></a><strong id="b615115411522"><a name="b615115411522"></a><a name="b615115411522"></a>Type</strong>: int</p>
<p id="p166693133522"><a name="p166693133522"></a><a name="p166693133522"></a><strong id="b184331942824"><a name="b184331942824"></a><a name="b184331942824"></a>Function</strong>: Indicates the request sequence, which is used to bind the return result.</p>
</td>
<td class="cellrowborder" valign="top" width="28.04280428042804%" headers="mcps1.2.4.1.3 "><p id="p266961385216"><a name="p266961385216"></a><a name="p266961385216"></a>0</p>
</td>
</tr>
<tr id="row1898612735212"><td class="cellrowborder" valign="top" width="22.122212221222124%" headers="mcps1.2.4.1.1 "><p id="p066951315526"><a name="p066951315526"></a><a name="p066951315526"></a>retCode__</p>
</td>
<td class="cellrowborder" valign="top" width="49.834983498349835%" headers="mcps1.2.4.1.2 "><p id="p166991310529"><a name="p166991310529"></a><a name="p166991310529"></a><strong id="b162021245723"><a name="b162021245723"></a><a name="b162021245723"></a>Type</strong>: int</p>
<p id="p146692134527"><a name="p146692134527"></a><a name="p146692134527"></a><strong id="b291255018210"><a name="b291255018210"></a><a name="b291255018210"></a>Function</strong>: Indicates the inference result code of the asynchronous algorithm.</p>
</td>
<td class="cellrowborder" valign="top" width="28.04280428042804%" headers="mcps1.2.4.1.3 "><p id="p5669101395220"><a name="p5669101395220"></a><a name="p5669101395220"></a>0</p>
</td>
</tr>
<tr id="row298617775218"><td class="cellrowborder" valign="top" width="22.122212221222124%" headers="mcps1.2.4.1.1 "><p id="p1966921318528"><a name="p1966921318528"></a><a name="p1966921318528"></a>retDesc_</p>
</td>
<td class="cellrowborder" valign="top" width="49.834983498349835%" headers="mcps1.2.4.1.2 "><p id="p36691613155217"><a name="p36691613155217"></a><a name="p36691613155217"></a><strong id="b162461753448"><a name="b162461753448"></a><a name="b162461753448"></a>Type</strong>: string</p>
<p id="p1067091319529"><a name="p1067091319529"></a><a name="p1067091319529"></a><strong id="b58297541946"><a name="b58297541946"></a><a name="b58297541946"></a>Function</strong>: reserved</p>
</td>
<td class="cellrowborder" valign="top" width="28.04280428042804%" headers="mcps1.2.4.1.3 "><p id="p15670191355218"><a name="p15670191355218"></a><a name="p15670191355218"></a>-</p>
</td>
</tr>
<tr id="row798614711527"><td class="cellrowborder" valign="top" width="22.122212221222124%" headers="mcps1.2.4.1.1 "><p id="p1467011314524"><a name="p1467011314524"></a><a name="p1467011314524"></a>transactionId_</p>
</td>
<td class="cellrowborder" valign="top" width="49.834983498349835%" headers="mcps1.2.4.1.2 "><p id="p1567010132524"><a name="p1567010132524"></a><a name="p1567010132524"></a><strong id="b621230052"><a name="b621230052"></a><a name="b621230052"></a>Type</strong>: long long</p>
<p id="p0670161311522"><a name="p0670161311522"></a><a name="p0670161311522"></a><strong id="b182156282052"><a name="b182156282052"></a><a name="b182156282052"></a>Function</strong>: Indicates the transaction ID, which is the combination of <strong id="b122209281516"><a name="b122209281516"></a><a name="b122209281516"></a>clientId</strong> and <strong id="b1922032818514"><a name="b1922032818514"></a><a name="b1922032818514"></a>sessionId</strong>.</p>
</td>
<td class="cellrowborder" valign="top" width="28.04280428042804%" headers="mcps1.2.4.1.3 "><p id="p86701313135217"><a name="p86701313135217"></a><a name="p86701313135217"></a>0</p>
</td>
</tr>
<tr id="row189861676522"><td class="cellrowborder" valign="top" width="22.122212221222124%" headers="mcps1.2.4.1.1 "><p id="p567011138522"><a name="p567011138522"></a><a name="p567011138522"></a>algoPluginType_</p>
</td>
<td class="cellrowborder" valign="top" width="49.834983498349835%" headers="mcps1.2.4.1.2 "><p id="p17670121385214"><a name="p17670121385214"></a><a name="p17670121385214"></a><strong id="b169111225155"><a name="b169111225155"></a><a name="b169111225155"></a>Type</strong>: int</p>
<p id="p1667010131526"><a name="p1667010131526"></a><a name="p1667010131526"></a><strong id="b14607332259"><a name="b14607332259"></a><a name="b14607332259"></a>Function</strong>: Indicates the algorithm type ID allocated by the AI engine framework based on the plug-in loading sequence.</p>
</td>
<td class="cellrowborder" valign="top" width="28.04280428042804%" headers="mcps1.2.4.1.3 "><p id="p1267015136527"><a name="p1267015136527"></a><a name="p1267015136527"></a>INVALID_ALGO_PLUGIN_TYPE(-1)</p>
</td>
</tr>
<tr id="row199862715524"><td class="cellrowborder" valign="top" width="22.122212221222124%" headers="mcps1.2.4.1.1 "><p id="p1670913155216"><a name="p1670913155216"></a><a name="p1670913155216"></a>result_</p>
</td>
<td class="cellrowborder" valign="top" width="49.834983498349835%" headers="mcps1.2.4.1.2 "><p id="p1670191315529"><a name="p1670191315529"></a><a name="p1670191315529"></a><strong id="b163471135954"><a name="b163471135954"></a><a name="b163471135954"></a>Type</strong>: DataInfo</p>
<p id="p4670313155214"><a name="p4670313155214"></a><a name="p4670313155214"></a><strong id="b498363911518"><a name="b498363911518"></a><a name="b498363911518"></a>Function</strong>: Stores the inference result of the asynchronous algorithm.</p>
</td>
<td class="cellrowborder" valign="top" width="28.04280428042804%" headers="mcps1.2.4.1.3 "><p id="p20670101375219"><a name="p20670101375219"></a><a name="p20670101375219"></a>.data = nullptr</p>
<p id="p867010135520"><a name="p867010135520"></a><a name="p867010135520"></a>.length = 0</p>
</td>
</tr>
</tbody>
</table>

For details about the development process, see the development example for the KWS plug-in.

