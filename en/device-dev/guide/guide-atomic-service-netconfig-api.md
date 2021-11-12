# Calling of Network Configuration APIs<a name="EN-US_TOPIC_0000001158605995"></a>

-   [Whether WifiAware Is Supported](#section1488020125510)
-   [Obtaining the Wi-Fi List](#section743413288512)
-   [Discovering Devices Through NAN](#section1504174410511)
-   [Discovering a Device Through SoftAP](#section55681185218)
-   [Connecting a Device](#section4392324115210)
-   [Configuring the Network for a Device](#section772433526)
-   [Releasing the Network Configuration Channel](#section194641109530)
-   [Controlling the Device in Seconds](#section144171232175313)
-   [Registering Message Callbacks](#section7232650195315)
-   [Callback for Device Disconnection](#section176579445411)

All APIs related to the network configuration are in  **login/fa-netconfig.js**.

For details about how to reference these APIs, see  **import netConfig from'fa-netconfig'**  in  **app.js**.

## Whether WifiAware Is Supported<a name="section1488020125510"></a>

<a name="table363724418353"></a>
<table><tbody><tr id="row12769644123510"><th class="firstcol" valign="top" width="31.580000000000002%" id="mcps1.1.3.1.1"><p id="p1769844113511"><a name="p1769844113511"></a><a name="p1769844113511"></a>Function Prototype</p>
</th>
<td class="cellrowborder" valign="top" width="68.42%" headers="mcps1.1.3.1.1 "><p id="p159318523353"><a name="p159318523353"></a><a name="p159318523353"></a>NetConfig.isSupportWifiAware()</p>
</td>
</tr>
<tr id="row976954433512"><th class="firstcol" valign="top" width="31.580000000000002%" id="mcps1.1.3.2.1"><p id="p0770134411354"><a name="p0770134411354"></a><a name="p0770134411354"></a>Description</p>
</th>
<td class="cellrowborder" valign="top" width="68.42%" headers="mcps1.1.3.2.1 "><p id="p777024413512"><a name="p777024413512"></a><a name="p777024413512"></a>Whether <strong id="b1906019195617"><a name="b1906019195617"></a><a name="b1906019195617"></a>WifiAware</strong> is supported.</p>
</td>
</tr>
<tr id="row177701444173514"><th class="firstcol" valign="top" width="31.580000000000002%" id="mcps1.1.3.3.1"><p id="p3770144493519"><a name="p3770144493519"></a><a name="p3770144493519"></a>API Type</p>
</th>
<td class="cellrowborder" valign="top" width="68.42%" headers="mcps1.1.3.3.1 "><p id="p07701244183515"><a name="p07701244183515"></a><a name="p07701244183515"></a>Synchronous API</p>
</td>
</tr>
<tr id="row12770204412352"><th class="firstcol" valign="top" width="31.580000000000002%" id="mcps1.1.3.4.1"><p id="p167707440352"><a name="p167707440352"></a><a name="p167707440352"></a>Return Value</p>
</th>
<td class="cellrowborder" valign="top" width="68.42%" headers="mcps1.1.3.4.1 "><p id="p1977004419359"><a name="p1977004419359"></a><a name="p1977004419359"></a><strong id="b279116285616"><a name="b279116285616"></a><a name="b279116285616"></a>0</strong> (supported) and <strong id="b145521446562"><a name="b145521446562"></a><a name="b145521446562"></a>-1</strong> (not supported)</p>
</td>
</tr>
</tbody>
</table>

-   Parameters

    None

-   Example

    ```
    getApp(this).NetConfig.isSupportWifiAware().then(function (result) {
    	let ret = JSON.parse(result);
    	console.info"isSupportWifiAware message result: code=" + ret.code +", data=" + ret.data)
    	if (ret.code == 0) {
    		// WifiAware supported.
    	} else {
    		// WifiAware not supported.
    	}
    });
    ```


## Obtaining the Wi-Fi List<a name="section743413288512"></a>

<a name="table1717191916404"></a>
<table><tbody><tr id="row3202419184016"><th class="firstcol" valign="top" width="34.260000000000005%" id="mcps1.1.3.1.1"><p id="p0202419124019"><a name="p0202419124019"></a><a name="p0202419124019"></a>Function Prototype</p>
</th>
<td class="cellrowborder" valign="top" width="65.74%" headers="mcps1.1.3.1.1 "><p id="p92028195407"><a name="p92028195407"></a><a name="p92028195407"></a>NetConfig.getWifiList(callbackFunc)</p>
</td>
</tr>
<tr id="row720261917406"><th class="firstcol" valign="top" width="34.260000000000005%" id="mcps1.1.3.2.1"><p id="p1020331934015"><a name="p1020331934015"></a><a name="p1020331934015"></a>Description</p>
</th>
<td class="cellrowborder" valign="top" width="65.74%" headers="mcps1.1.3.2.1 "><p id="p0203141954013"><a name="p0203141954013"></a><a name="p0203141954013"></a>Obtains the list of nearby Wi-Fi networks.</p>
</td>
</tr>
<tr id="row92032192404"><th class="firstcol" valign="top" width="34.260000000000005%" id="mcps1.1.3.3.1"><p id="p6203131924015"><a name="p6203131924015"></a><a name="p6203131924015"></a>API Type</p>
</th>
<td class="cellrowborder" valign="top" width="65.74%" headers="mcps1.1.3.3.1 "><p id="p6203219164019"><a name="p6203219164019"></a><a name="p6203219164019"></a>Asynchronous API</p>
</td>
</tr>
<tr id="row13203519184015"><th class="firstcol" valign="top" width="34.260000000000005%" id="mcps1.1.3.4.1"><p id="p1920321994015"><a name="p1920321994015"></a><a name="p1920321994015"></a>Return Value</p>
</th>
<td class="cellrowborder" valign="top" width="65.74%" headers="mcps1.1.3.4.1 "><p id="p192032198404"><a name="p192032198404"></a><a name="p192032198404"></a><strong id="b099912203579"><a name="b099912203579"></a><a name="b099912203579"></a>0</strong> (success) and <strong id="b1381219362579"><a name="b1381219362579"></a><a name="b1381219362579"></a>-1</strong> (failure)</p>
</td>
</tr>
</tbody>
</table>

-   Parameters

    <a name="table156944377389"></a>
    <table><thead align="left"><tr id="row9694637163812"><th class="cellrowborder" valign="top" width="15.73%" id="mcps1.1.5.1.1"><p id="p626854064118"><a name="p626854064118"></a><a name="p626854064118"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="11.06%" id="mcps1.1.5.1.2"><p id="p926819401412"><a name="p926819401412"></a><a name="p926819401412"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="8.709999999999999%" id="mcps1.1.5.1.3"><p id="p1726884018418"><a name="p1726884018418"></a><a name="p1726884018418"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="64.5%" id="mcps1.1.5.1.4"><p id="p1326815406411"><a name="p1326815406411"></a><a name="p1326815406411"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row166951637133810"><td class="cellrowborder" valign="top" width="15.73%" headers="mcps1.1.5.1.1 "><p id="p14268204010415"><a name="p14268204010415"></a><a name="p14268204010415"></a>callbackFunc</p>
    </td>
    <td class="cellrowborder" valign="top" width="11.06%" headers="mcps1.1.5.1.2 "><p id="p1826811403411"><a name="p1826811403411"></a><a name="p1826811403411"></a>function</p>
    </td>
    <td class="cellrowborder" valign="top" width="8.709999999999999%" headers="mcps1.1.5.1.3 "><p id="p192688400414"><a name="p192688400414"></a><a name="p192688400414"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="64.5%" headers="mcps1.1.5.1.4 "><p id="p726854034116"><a name="p726854034116"></a><a name="p726854034116"></a>Callback function. If the callback is successful, <strong id="b128901051123418"><a name="b128901051123418"></a><a name="b128901051123418"></a>data</strong> contains the returned data result. The data result is parsed and used in the callback.</p>
    <p id="p102686402419"><a name="p102686402419"></a><a name="p102686402419"></a>Data returned: List&lt;WifiApInfo&gt;</p>
    <p id="p5268144014113"><a name="p5268144014113"></a><a name="p5268144014113"></a>WifiApInfo {</p>
    <p id="p1226810401419"><a name="p1226810401419"></a><a name="p1226810401419"></a>int channel;</p>
    <p id="p22681940164113"><a name="p22681940164113"></a><a name="p22681940164113"></a>boolean hasDefaultPassword;</p>
    <p id="p526816404417"><a name="p526816404417"></a><a name="p526816404417"></a>boolean is5G; // Specifies whether 5 GHz Wi-Fi is used.</p>
    <p id="p1926814064115"><a name="p1926814064115"></a><a name="p1926814064115"></a>String securityType;</p>
    <p id="p18268640164113"><a name="p18268640164113"></a><a name="p18268640164113"></a>int signalLevel;</p>
    <p id="p112681040194120"><a name="p112681040194120"></a><a name="p112681040194120"></a>String ssid;</p>
    <p id="p1226844094110"><a name="p1226844094110"></a><a name="p1226844094110"></a>String wifiApId; // wifiAp ID</p>
    <p id="p1826854018411"><a name="p1826854018411"></a><a name="p1826854018411"></a>}</p>
    <p id="p02683405411"><a name="p02683405411"></a><a name="p02683405411"></a>Both 2.4 GHz Wi-Fi and 5 GHz Wi-Fi are returned. The atomic service can filter data based on the value of <strong id="b1841210211901"><a name="b1841210211901"></a><a name="b1841210211901"></a>is5G</strong>.</p>
    <p id="p13268184064110"><a name="p13268184064110"></a><a name="p13268184064110"></a>The value of <strong id="b77861626135211"><a name="b77861626135211"></a><a name="b77861626135211"></a>hasDefaultPassword</strong> is <strong id="b1963443025215"><a name="b1963443025215"></a><a name="b1963443025215"></a>true</strong> only when the SSID has been connected before and the password can be successfully obtained.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Example

    ```
    getApp(this).NetConfig.getWifiList((result) => {
    	if (result.code == 0 && result.data && result.data.length > 0) {
    		this.progress = this.progressStatus[3];
    		this.desc = this.descStatus[3];
    		this.configDevice(result.data[0]);
    	} else {
    		this.progress = this.progressStatus[4];
    		this.desc = this.descStatus[3];
    		this.disconnectDevice();
    	}
    });
    ```


## Discovering Devices Through NAN<a name="section1504174410511"></a>

<a name="table1576075594214"></a>
<table><tbody><tr id="row17849855174211"><th class="firstcol" valign="top" width="31.39%" id="mcps1.1.3.1.1"><p id="p584955510426"><a name="p584955510426"></a><a name="p584955510426"></a>Function Prototype</p>
</th>
<td class="cellrowborder" valign="top" width="68.61%" headers="mcps1.1.3.1.1 "><p id="p17849165510422"><a name="p17849165510422"></a><a name="p17849165510422"></a>NetConfig.discoveryByNAN(scanNanInfo, callbackFunc)</p>
</td>
</tr>
<tr id="row19849105594212"><th class="firstcol" valign="top" width="31.39%" id="mcps1.1.3.2.1"><p id="p188491551425"><a name="p188491551425"></a><a name="p188491551425"></a>Description</p>
</th>
<td class="cellrowborder" valign="top" width="68.61%" headers="mcps1.1.3.2.1 "><p id="p084965517423"><a name="p084965517423"></a><a name="p084965517423"></a>Initiates a NAN broadcast, waits for a client connection, establishes the connection, and stops the broadcast.</p>
</td>
</tr>
<tr id="row584912559421"><th class="firstcol" valign="top" width="31.39%" id="mcps1.1.3.3.1"><p id="p9849555114216"><a name="p9849555114216"></a><a name="p9849555114216"></a>API Type</p>
</th>
<td class="cellrowborder" valign="top" width="68.61%" headers="mcps1.1.3.3.1 "><p id="p1849255194219"><a name="p1849255194219"></a><a name="p1849255194219"></a>Asynchronous API</p>
</td>
</tr>
<tr id="row7849145584212"><th class="firstcol" valign="top" width="31.39%" id="mcps1.1.3.4.1"><p id="p18849455174211"><a name="p18849455174211"></a><a name="p18849455174211"></a>Return Value</p>
</th>
<td class="cellrowborder" valign="top" width="68.61%" headers="mcps1.1.3.4.1 "><p id="p1484910557421"><a name="p1484910557421"></a><a name="p1484910557421"></a><strong id="b3281145175712"><a name="b3281145175712"></a><a name="b3281145175712"></a>0</strong> (success) and <strong id="b528114535718"><a name="b528114535718"></a><a name="b528114535718"></a>-1</strong> (failure)</p>
</td>
</tr>
</tbody>
</table>

-   Parameters

    <a name="table14693111134316"></a>
    <table><thead align="left"><tr id="row37448110431"><th class="cellrowborder" valign="top" width="17.798220177982202%" id="mcps1.1.5.1.1"><p id="p127441111154317"><a name="p127441111154317"></a><a name="p127441111154317"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="11.968803119688031%" id="mcps1.1.5.1.2"><p id="p574541114431"><a name="p574541114431"></a><a name="p574541114431"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="11.968803119688031%" id="mcps1.1.5.1.3"><p id="p1274521154310"><a name="p1274521154310"></a><a name="p1274521154310"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="58.26417358264173%" id="mcps1.1.5.1.4"><p id="p1374531144319"><a name="p1374531144319"></a><a name="p1374531144319"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row9745151164311"><td class="cellrowborder" valign="top" width="17.798220177982202%" headers="mcps1.1.5.1.1 "><p id="p674511114317"><a name="p674511114317"></a><a name="p674511114317"></a>scanNanInfo</p>
    </td>
    <td class="cellrowborder" valign="top" width="11.968803119688031%" headers="mcps1.1.5.1.2 "><p id="p15745201120435"><a name="p15745201120435"></a><a name="p15745201120435"></a>Object</p>
    </td>
    <td class="cellrowborder" valign="top" width="11.968803119688031%" headers="mcps1.1.5.1.3 "><p id="p17451811174316"><a name="p17451811174316"></a><a name="p17451811174316"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="58.26417358264173%" headers="mcps1.1.5.1.4 "><p id="p20745711104316"><a name="p20745711104316"></a><a name="p20745711104316"></a>scanNanInfo {</p>
    <p id="p17745141116439"><a name="p17745141116439"></a><a name="p17745141116439"></a>int duration // If a connection is not set up within the specified duration, the broadcast stops. The value range is [0,100], and the unit is seconds. The value <strong id="b427514211874"><a name="b427514211874"></a><a name="b427514211874"></a>0</strong> indicates an unlimited duration.</p>
    <p id="p6745151184310"><a name="p6745151184310"></a><a name="p6745151184310"></a>int lockTime // Locking duration of a device in NAN mode after the device receives an NAN mutual trust message. The value range is [0,100], and the unit is seconds. The value <strong id="b1973061611610"><a name="b1973061611610"></a><a name="b1973061611610"></a>0</strong> indicates an unlimited duration.</p>
    <p id="p2745101184317"><a name="p2745101184317"></a><a name="p2745101184317"></a>String sessionId // The value is the <strong id="b1750119341471"><a name="b1750119341471"></a><a name="b1750119341471"></a>sessionId</strong> value carried by the intent when the service starts the atomic service.</p>
    <p id="p137451511144313"><a name="p137451511144313"></a><a name="p137451511144313"></a>}</p>
    </td>
    </tr>
    <tr id="row1174531110436"><td class="cellrowborder" valign="top" width="17.798220177982202%" headers="mcps1.1.5.1.1 "><p id="p6745181115436"><a name="p6745181115436"></a><a name="p6745181115436"></a>callbackFunc</p>
    </td>
    <td class="cellrowborder" valign="top" width="11.968803119688031%" headers="mcps1.1.5.1.2 "><p id="p4745611124319"><a name="p4745611124319"></a><a name="p4745611124319"></a>function</p>
    </td>
    <td class="cellrowborder" valign="top" width="11.968803119688031%" headers="mcps1.1.5.1.3 "><p id="p1274531110430"><a name="p1274531110430"></a><a name="p1274531110430"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="58.26417358264173%" headers="mcps1.1.5.1.4 "><p id="p7745911124314"><a name="p7745911124314"></a><a name="p7745911124314"></a>Callback function. If the callback is successful, <strong id="b3578104913416"><a name="b3578104913416"></a><a name="b3578104913416"></a>data</strong> contains the returned data result. The data result is parsed and used in the callback. Data returned:</p>
    <p id="p197451111104319"><a name="p197451111104319"></a><a name="p197451111104319"></a>DeviceInfo{</p>
    <p id="p1874561113432"><a name="p1874561113432"></a><a name="p1874561113432"></a>String productId,</p>
    <p id="p11745411114311"><a name="p11745411114311"></a><a name="p11745411114311"></a>String sessionId</p>
    <p id="p274551118435"><a name="p274551118435"></a><a name="p274551118435"></a>String sn,</p>
    <p id="p1474581116435"><a name="p1474581116435"></a><a name="p1474581116435"></a>}</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Example

    ```
    let scanInfo = {
    	duration: 30,
    	lockTime: 60,
    	sessionId: ''
    };
    getApp(this).NetConfig.discoveryByNAN(scanInfo, (result) => {
    	if (result.code == 0) {
    		this.progress = this.progressStatus[1];
    		this.desc = this.descStatus[1];
    		getApp(this).ConfigParams.deviceInfo = result.data;
    		this.registerDisconnectCallback(result.data.sessionId);
    		this.connectDevice();
    	} else {
    		this.progress = this.progressStatus[4];
    		this.desc = this.failDescStatus[1];
    		this.disconnectDevice();
    	}
    });
    ```


## Discovering a Device Through SoftAP<a name="section55681185218"></a>

<a name="table20458153644412"></a>
<table><tbody><tr id="row1055614367448"><th class="firstcol" valign="top" width="29.29%" id="mcps1.1.3.1.1"><p id="p1355623614444"><a name="p1355623614444"></a><a name="p1355623614444"></a>Function Prototype</p>
</th>
<td class="cellrowborder" valign="top" width="70.71%" headers="mcps1.1.3.1.1 "><p id="p1688316106306"><a name="p1688316106306"></a><a name="p1688316106306"></a>NetConfig.discoveryBySoftAP(callbackFunc)</p>
</td>
</tr>
<tr id="row655623618445"><th class="firstcol" valign="top" width="29.29%" id="mcps1.1.3.2.1"><p id="p255643615444"><a name="p255643615444"></a><a name="p255643615444"></a>Description</p>
</th>
<td class="cellrowborder" valign="top" width="70.71%" headers="mcps1.1.3.2.1 "><p id="p195561836184411"><a name="p195561836184411"></a><a name="p195561836184411"></a>Scans for access points (APs).</p>
</td>
</tr>
<tr id="row13557123664414"><th class="firstcol" valign="top" width="29.29%" id="mcps1.1.3.3.1"><p id="p14557123654410"><a name="p14557123654410"></a><a name="p14557123654410"></a>API Type</p>
</th>
<td class="cellrowborder" valign="top" width="70.71%" headers="mcps1.1.3.3.1 "><p id="p15557163620448"><a name="p15557163620448"></a><a name="p15557163620448"></a>Asynchronous API</p>
</td>
</tr>
<tr id="row14557236124412"><th class="firstcol" valign="top" width="29.29%" id="mcps1.1.3.4.1"><p id="p55571236134417"><a name="p55571236134417"></a><a name="p55571236134417"></a>Input Parameter</p>
</th>
<td class="cellrowborder" valign="top" width="70.71%" headers="mcps1.1.3.4.1 "><p id="p2557136164416"><a name="p2557136164416"></a><a name="p2557136164416"></a>The number of calling times is determined by the atomic service.</p>
</td>
</tr>
<tr id="row35571336194410"><th class="firstcol" valign="top" width="29.29%" id="mcps1.1.3.5.1"><p id="p1655763674419"><a name="p1655763674419"></a><a name="p1655763674419"></a>Return Value</p>
</th>
<td class="cellrowborder" valign="top" width="70.71%" headers="mcps1.1.3.5.1 "><p id="p75571636124418"><a name="p75571636124418"></a><a name="p75571636124418"></a><strong id="b628214459577"><a name="b628214459577"></a><a name="b628214459577"></a>0</strong> (success) and <strong id="b1428284510572"><a name="b1428284510572"></a><a name="b1428284510572"></a>-1</strong> (failure)</p>
</td>
</tr>
</tbody>
</table>

-   Parameters

    <a name="table69251651204410"></a>
    <table><thead align="left"><tr id="row1495415519449"><th class="cellrowborder" valign="top" width="17.82%" id="mcps1.1.5.1.1"><p id="p12954851144412"><a name="p12954851144412"></a><a name="p12954851144412"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="11.99%" id="mcps1.1.5.1.2"><p id="p29541518441"><a name="p29541518441"></a><a name="p29541518441"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="10.41%" id="mcps1.1.5.1.3"><p id="p69541051144414"><a name="p69541051144414"></a><a name="p69541051144414"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="59.78%" id="mcps1.1.5.1.4"><p id="p9954951144419"><a name="p9954951144419"></a><a name="p9954951144419"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row1795411515442"><td class="cellrowborder" valign="top" width="17.82%" headers="mcps1.1.5.1.1 "><p id="p1495465118444"><a name="p1495465118444"></a><a name="p1495465118444"></a>callbackFunc</p>
    </td>
    <td class="cellrowborder" valign="top" width="11.99%" headers="mcps1.1.5.1.2 "><p id="p795485111444"><a name="p795485111444"></a><a name="p795485111444"></a>function</p>
    </td>
    <td class="cellrowborder" valign="top" width="10.41%" headers="mcps1.1.5.1.3 "><p id="p11954251194420"><a name="p11954251194420"></a><a name="p11954251194420"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="59.78%" headers="mcps1.1.5.1.4 "><p id="p1495411516446"><a name="p1495411516446"></a><a name="p1495411516446"></a>Callback function. If the callback is successful, <strong id="b16544351619"><a name="b16544351619"></a><a name="b16544351619"></a>data</strong> contains the returned data result. The data result is parsed and used in the callback.</p>
    <p id="p189557513442"><a name="p189557513442"></a><a name="p189557513442"></a>Data returned: List&lt;SoftAPInfo&gt; SoftAPInfo{</p>
    <p id="p15955125119448"><a name="p15955125119448"></a><a name="p15955125119448"></a>String ssid,</p>
    <p id="p179558518449"><a name="p179558518449"></a><a name="p179558518449"></a>boolean usePassword // Specifies whether a password is required.</p>
    <p id="p5955175111443"><a name="p5955175111443"></a><a name="p5955175111443"></a>}</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Example

    ```
    getApp(this).NetConfig.discoveryBySoftAP((result) => {
    	if (result.code == 0) {
    		for (let index = 0; index < result.data.length; index++) {
    			let element = result.data[index];
    			console.info("discoveryBySoftAP callback: device element=" + JSON.stringify(element));
    			// Compare the Wi-Fi list scanned through SoftAP with the target device's SSID format, category, and MAC address.
    			if (element.ssid.indexOf(self.softAPSsidDefault) != -1) {
    				this.discoverDeviceBySoftAPResult = JSON.stringify(element);
    				this.softAPSsidDefault = element.ssid;
    				break;
    			}
    		}
    	}
    });
    ```


## Connecting a Device<a name="section4392324115210"></a>

<a name="table132751845184515"></a>
<table><tbody><tr id="row142354710453"><th class="firstcol" valign="top" width="31.730000000000004%" id="mcps1.1.3.1.1"><p id="p342313479450"><a name="p342313479450"></a><a name="p342313479450"></a>Function Prototype</p>
</th>
<td class="cellrowborder" valign="top" width="68.27%" headers="mcps1.1.3.1.1 "><p id="p13423447124517"><a name="p13423447124517"></a><a name="p13423447124517"></a>NetConfig.connectDevice(connectInfo,callbackFunc)</p>
</td>
</tr>
<tr id="row542317476453"><th class="firstcol" valign="top" width="31.730000000000004%" id="mcps1.1.3.2.1"><p id="p442314720451"><a name="p442314720451"></a><a name="p442314720451"></a>Description</p>
</th>
<td class="cellrowborder" valign="top" width="68.27%" headers="mcps1.1.3.2.1 "><p id="p17423747164510"><a name="p17423747164510"></a><a name="p17423747164510"></a>Connects a device.</p>
</td>
</tr>
<tr id="row242319478452"><th class="firstcol" valign="top" width="31.730000000000004%" id="mcps1.1.3.3.1"><p id="p1642394704512"><a name="p1642394704512"></a><a name="p1642394704512"></a>API Type</p>
</th>
<td class="cellrowborder" valign="top" width="68.27%" headers="mcps1.1.3.3.1 "><p id="p54239476451"><a name="p54239476451"></a><a name="p54239476451"></a>Asynchronous API</p>
</td>
</tr>
<tr id="row1742394713458"><th class="firstcol" valign="top" width="31.730000000000004%" id="mcps1.1.3.4.1"><p id="p11423154711451"><a name="p11423154711451"></a><a name="p11423154711451"></a>Return Value</p>
</th>
<td class="cellrowborder" valign="top" width="68.27%" headers="mcps1.1.3.4.1 "><p id="p11423184734516"><a name="p11423184734516"></a><a name="p11423184734516"></a><strong id="b16283145145714"><a name="b16283145145714"></a><a name="b16283145145714"></a>0</strong> (success) and <strong id="b1728315451574"><a name="b1728315451574"></a><a name="b1728315451574"></a>-1</strong> (failure)</p>
</td>
</tr>
</tbody>
</table>

-   Parameters

    <a name="table146121713204612"></a>
    <table><thead align="left"><tr id="row365515136467"><th class="cellrowborder" valign="top" width="15.958404159584042%" id="mcps1.1.5.1.1"><p id="p6655201314618"><a name="p6655201314618"></a><a name="p6655201314618"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="11.688831116888311%" id="mcps1.1.5.1.2"><p id="p3655713104617"><a name="p3655713104617"></a><a name="p3655713104617"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="11.218878112188781%" id="mcps1.1.5.1.3"><p id="p565511134464"><a name="p565511134464"></a><a name="p565511134464"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="61.13388661133887%" id="mcps1.1.5.1.4"><p id="p1065561384615"><a name="p1065561384615"></a><a name="p1065561384615"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row3655213104610"><td class="cellrowborder" valign="top" width="15.958404159584042%" headers="mcps1.1.5.1.1 "><p id="p2655121312460"><a name="p2655121312460"></a><a name="p2655121312460"></a>connectInfo</p>
    </td>
    <td class="cellrowborder" valign="top" width="11.688831116888311%" headers="mcps1.1.5.1.2 "><p id="p116551313184613"><a name="p116551313184613"></a><a name="p116551313184613"></a>Object</p>
    </td>
    <td class="cellrowborder" valign="top" width="11.218878112188781%" headers="mcps1.1.5.1.3 "><p id="p176551213114613"><a name="p176551213114613"></a><a name="p176551213114613"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.13388661133887%" headers="mcps1.1.5.1.4 "><p id="p17655181374619"><a name="p17655181374619"></a><a name="p17655181374619"></a>connectInfo {</p>
    <p id="p1165541317461"><a name="p1165541317461"></a><a name="p1165541317461"></a>string targetDeviceId; // Mandatory. ID of the device to connect.</p>
    <a name="ul46551213184611"></a><a name="ul46551213184611"></a><ul id="ul46551213184611"><li>number type; // Mandatory. The value can be <strong id="b13161115114510"><a name="b13161115114510"></a><a name="b13161115114510"></a>0</strong> (NAN) and <strong id="b14402125315517"><a name="b14402125315517"></a><a name="b14402125315517"></a>1</strong> (SoftAp).</li><li>string pin; // Mandatory. Device PIN.</li><li>string password; //Mandatory. If the device requires a password, set this parameter to the required password. Otherwise, set this parameter to "".</li><li>string sessionId; // Mandatory. If <strong id="b1851645018810"><a name="b1851645018810"></a><a name="b1851645018810"></a>type</strong> is set to <strong id="b143321948785"><a name="b143321948785"></a><a name="b143321948785"></a>NAN</strong>, set this parameter to the value of <strong id="b171011391061"><a name="b171011391061"></a><a name="b171011391061"></a>sessionId</strong> returned by <strong id="b5771342563"><a name="b5771342563"></a><a name="b5771342563"></a>discoverDevByNAN</strong>. Otherwise, set this parameter to "".<p id="p3655181324610"><a name="p3655181324610"></a><a name="p3655181324610"></a>}</p>
    </li></ul>
    </td>
    </tr>
    <tr id="row965561334615"><td class="cellrowborder" valign="top" width="15.958404159584042%" headers="mcps1.1.5.1.1 "><p id="p19655121314617"><a name="p19655121314617"></a><a name="p19655121314617"></a>callbackFunc</p>
    </td>
    <td class="cellrowborder" valign="top" width="11.688831116888311%" headers="mcps1.1.5.1.2 "><p id="p9655191313466"><a name="p9655191313466"></a><a name="p9655191313466"></a>function</p>
    </td>
    <td class="cellrowborder" valign="top" width="11.218878112188781%" headers="mcps1.1.5.1.3 "><p id="p18655141364615"><a name="p18655141364615"></a><a name="p18655141364615"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.13388661133887%" headers="mcps1.1.5.1.4 "><p id="p3655113184615"><a name="p3655113184615"></a><a name="p3655113184615"></a>Callback function. If the callback is successful, <strong id="b676141013425"><a name="b676141013425"></a><a name="b676141013425"></a>data</strong> contains the returned data result. The data result is parsed and used in the callback.</p>
    <p id="p16655151319465"><a name="p16655151319465"></a><a name="p16655151319465"></a>Data returned: String vendorData // Reserved.</p>
    <p id="p196550137466"><a name="p196550137466"></a><a name="p196550137466"></a>In SoftAP mode, {</p>
    <p id="p1965591344615"><a name="p1965591344615"></a><a name="p1965591344615"></a>String productId,</p>
    <p id="p11656111310462"><a name="p11656111310462"></a><a name="p11656111310462"></a>String sn,</p>
    <p id="p13656171384616"><a name="p13656171384616"></a><a name="p13656171384616"></a>String vendorData</p>
    <p id="p1165618134463"><a name="p1165618134463"></a><a name="p1165618134463"></a>} JSON string</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Example of the NAN type

    ```
    let connectInfo = {
    	targetDeviceId: getApp(this).ConfigParams.deviceInfo.productId,
    	type: 0,
    	pin: '0123456789012345',
    	password: getApp(this).ConfigParams.deviceInfo.sn,
    	sessionId: getApp(this).ConfigParams.deviceInfo.sessionId
    };
    getApp(this).NetConfig.connectDevice(connectInfo, (result) => {
    	if (result.code === 0) {
    		this.progress = this.progressStatus[2];
    		this.desc = this.descStatus[2];
    		this.getWifiInfo();
    	} else {
    		this.progress = this.progressStatus[4];
    		this.desc = this.failDescStatus[2];
    		this.disconnectDevice();
    	}
    });
    ```

-   Example of the SoftAP type

    ```
    let connectInfo = {
    	targetDeviceId: getApp(this).ConfigParams.deviceInfo.productId,
    	type: 1,
    	pin: '0123456789012345',
    	password: getApp(this).ConfigParams.deviceInfo.sn,
    	sessionId: getApp(this).ConfigParams.deviceInfo.sessionId
    };
    getApp(this).NetConfig.connectDevice(connectInfo, (result) => {
    	if (result.code === 0) {
    		this.progress = this.progressStatus[2];
    		this.desc = this.descStatus[2];
    		this.getWifiInfo();
    	} else {
    		this.progress = this.progressStatus[4];
    		this.desc = this.failDescStatus[2];
    		this.disconnectDevice();
    	}
    });
    ```


## Configuring the Network for a Device<a name="section772433526"></a>

<a name="table766315593514"></a>
<table><tbody><tr id="row18751195915512"><th class="firstcol" valign="top" width="30.509999999999998%" id="mcps1.1.3.1.1"><p id="p275105985117"><a name="p275105985117"></a><a name="p275105985117"></a>Function Prototype</p>
</th>
<td class="cellrowborder" valign="top" width="69.49%" headers="mcps1.1.3.1.1 "><p id="p147511459125120"><a name="p147511459125120"></a><a name="p147511459125120"></a>NetConfig.configDeviceNet(deviceInfo,accountInfo,netConfigInfo,callbackFunc)</p>
</td>
</tr>
<tr id="row97511594514"><th class="firstcol" valign="top" width="30.509999999999998%" id="mcps1.1.3.2.1"><p id="p97518597517"><a name="p97518597517"></a><a name="p97518597517"></a>Description</p>
</th>
<td class="cellrowborder" valign="top" width="69.49%" headers="mcps1.1.3.2.1 "><p id="p875135945115"><a name="p875135945115"></a><a name="p875135945115"></a>Starts to configure the network for the specified device by sending the SSID, password, device information, and account information.</p>
</td>
</tr>
<tr id="row1875112593518"><th class="firstcol" valign="top" width="30.509999999999998%" id="mcps1.1.3.3.1"><p id="p3752155918516"><a name="p3752155918516"></a><a name="p3752155918516"></a>API Type</p>
</th>
<td class="cellrowborder" valign="top" width="69.49%" headers="mcps1.1.3.3.1 "><p id="p157521159165112"><a name="p157521159165112"></a><a name="p157521159165112"></a>Asynchronous API</p>
</td>
</tr>
<tr id="row675285919511"><th class="firstcol" valign="top" width="30.509999999999998%" id="mcps1.1.3.4.1"><p id="p13752135985113"><a name="p13752135985113"></a><a name="p13752135985113"></a>Return Value</p>
</th>
<td class="cellrowborder" valign="top" width="69.49%" headers="mcps1.1.3.4.1 "><p id="p1775213598514"><a name="p1775213598514"></a><a name="p1775213598514"></a><strong id="b112846456574"><a name="b112846456574"></a><a name="b112846456574"></a>0</strong> (success) and <strong id="b182841945105716"><a name="b182841945105716"></a><a name="b182841945105716"></a>-1</strong> (failure)</p>
</td>
</tr>
</tbody>
</table>

-   Parameters

    <a name="table011339165214"></a>
    <table><thead align="left"><tr id="row14729396525"><th class="cellrowborder" valign="top" width="16.82%" id="mcps1.1.5.1.1"><p id="p4721639105217"><a name="p4721639105217"></a><a name="p4721639105217"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="12.620000000000001%" id="mcps1.1.5.1.2"><p id="p1721639145218"><a name="p1721639145218"></a><a name="p1721639145218"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="11.68%" id="mcps1.1.5.1.3"><p id="p14721239155216"><a name="p14721239155216"></a><a name="p14721239155216"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="58.879999999999995%" id="mcps1.1.5.1.4"><p id="p37203911525"><a name="p37203911525"></a><a name="p37203911525"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row127273985212"><td class="cellrowborder" valign="top" width="16.82%" headers="mcps1.1.5.1.1 "><p id="p77243917526"><a name="p77243917526"></a><a name="p77243917526"></a>deviceInfo</p>
    </td>
    <td class="cellrowborder" valign="top" width="12.620000000000001%" headers="mcps1.1.5.1.2 "><p id="p872153913526"><a name="p872153913526"></a><a name="p872153913526"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="11.68%" headers="mcps1.1.5.1.3 "><p id="p3721539125215"><a name="p3721539125215"></a><a name="p3721539125215"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="58.879999999999995%" headers="mcps1.1.5.1.4 "><p id="p1872133916526"><a name="p1872133916526"></a><a name="p1872133916526"></a>Information allocated by the device cloud to the device, such as the device ID.</p>
    </td>
    </tr>
    <tr id="row27293965211"><td class="cellrowborder" valign="top" width="16.82%" headers="mcps1.1.5.1.1 "><p id="p5723395522"><a name="p5723395522"></a><a name="p5723395522"></a>accountInfo</p>
    </td>
    <td class="cellrowborder" valign="top" width="12.620000000000001%" headers="mcps1.1.5.1.2 "><p id="p072143905216"><a name="p072143905216"></a><a name="p072143905216"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="11.68%" headers="mcps1.1.5.1.3 "><p id="p172193965210"><a name="p172193965210"></a><a name="p172193965210"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="58.879999999999995%" headers="mcps1.1.5.1.4 "><p id="p472163918521"><a name="p472163918521"></a><a name="p472163918521"></a>Account information.</p>
    </td>
    </tr>
    <tr id="row77218399529"><td class="cellrowborder" valign="top" width="16.82%" headers="mcps1.1.5.1.1 "><p id="p17731839105218"><a name="p17731839105218"></a><a name="p17731839105218"></a>netConfigInfo</p>
    </td>
    <td class="cellrowborder" valign="top" width="12.620000000000001%" headers="mcps1.1.5.1.2 "><p id="p167393919522"><a name="p167393919522"></a><a name="p167393919522"></a>Object</p>
    </td>
    <td class="cellrowborder" valign="top" width="11.68%" headers="mcps1.1.5.1.3 "><p id="p1373439175215"><a name="p1373439175215"></a><a name="p1373439175215"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="58.879999999999995%" headers="mcps1.1.5.1.4 "><p id="p1973839105216"><a name="p1973839105216"></a><a name="p1973839105216"></a>netConfigInfo {</p>
    <p id="p18731639135213"><a name="p18731639135213"></a><a name="p18731639135213"></a>string ssid;</p>
    <p id="p27323955214"><a name="p27323955214"></a><a name="p27323955214"></a>// Mandatory. If the SSID has been configured for the phone, you do not need to enter a password.</p>
    <p id="p187318398523"><a name="p187318398523"></a><a name="p187318398523"></a>string ssidPassword; // Optional. If the password does not need to be delivered, set this parameter to "".</p>
    <p id="p1073123912525"><a name="p1073123912525"></a><a name="p1073123912525"></a>boolean isDefaultPassword; // Mandatory.</p>
    <p id="p1173739165213"><a name="p1173739165213"></a><a name="p1173739165213"></a>int channel; // Mandatory.</p>
    <p id="p3732399523"><a name="p3732399523"></a><a name="p3732399523"></a>string sessionId; // Mandatory. When <strong id="b2066161813108"><a name="b2066161813108"></a><a name="b2066161813108"></a>type</strong> is set to <strong id="b953212014101"><a name="b953212014101"></a><a name="b953212014101"></a>NAN</strong>, enter the actual value. Otherwise, set this parameter to "".</p>
    <p id="p107343985217"><a name="p107343985217"></a><a name="p107343985217"></a>int type; // Mandatory. The value can be <strong id="b14851032141019"><a name="b14851032141019"></a><a name="b14851032141019"></a>0 (NAN)</strong> and 1 <strong id="b9620353102"><a name="b9620353102"></a><a name="b9620353102"></a>(SoftAp)</strong>.</p>
    <p id="p197353917529"><a name="p197353917529"></a><a name="p197353917529"></a>String wifiApId; // Enter the corresponding fields in the returned Wi-Fi network list information.</p>
    <p id="p15731139185218"><a name="p15731139185218"></a><a name="p15731139185218"></a>String vendorData; // Product data, which is encoded using random Base64.</p>
    <p id="p157319392526"><a name="p157319392526"></a><a name="p157319392526"></a>int timeout; // Network configuration timeout interval, which is set in NAN mode. The value range is [1,90], and the unit is seconds.</p>
    <p id="p5731339125215"><a name="p5731339125215"></a><a name="p5731339125215"></a>}</p>
    <p id="p177314391525"><a name="p177314391525"></a><a name="p177314391525"></a>Note: To require the user to enter the password, set <strong id="b630141320164"><a name="b630141320164"></a><a name="b630141320164"></a>isDefaultPassword</strong> to <strong id="b18977216141610"><a name="b18977216141610"></a><a name="b18977216141610"></a>false</strong> and <strong id="b1429142111619"><a name="b1429142111619"></a><a name="b1429142111619"></a>ssidPassword</strong> to the entered password; otherwise, set <strong id="b16911540201616"><a name="b16911540201616"></a><a name="b16911540201616"></a>isDefaultPassword</strong> to <strong id="b1569218407163"><a name="b1569218407163"></a><a name="b1569218407163"></a>true</strong> and <strong id="b14692194061618"><a name="b14692194061618"></a><a name="b14692194061618"></a>ssidPassword</strong> to "".</p>
    </td>
    </tr>
    <tr id="row1173539155215"><td class="cellrowborder" valign="top" width="16.82%" headers="mcps1.1.5.1.1 "><p id="p117353905211"><a name="p117353905211"></a><a name="p117353905211"></a>callbackFunc</p>
    </td>
    <td class="cellrowborder" valign="top" width="12.620000000000001%" headers="mcps1.1.5.1.2 "><p id="p177313912528"><a name="p177313912528"></a><a name="p177313912528"></a>function</p>
    </td>
    <td class="cellrowborder" valign="top" width="11.68%" headers="mcps1.1.5.1.3 "><p id="p13739392522"><a name="p13739392522"></a><a name="p13739392522"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="58.879999999999995%" headers="mcps1.1.5.1.4 "><p id="p1373183955219"><a name="p1373183955219"></a><a name="p1373183955219"></a>Callback function. In NAN mode, if the callback is successful, the module reports the network configuration status. The result is converted into two parts: the integer part (stored in <strong id="b1944317584176"><a name="b1944317584176"></a><a name="b1944317584176"></a>data.code</strong>) and the string type (stored in <strong id="b6325810121818"><a name="b6325810121818"></a><a name="b6325810121818"></a>data.msg</strong>). In SoftAP mode, either <strong id="b1841172361815"><a name="b1841172361815"></a><a name="b1841172361815"></a>0</strong> or <strong id="b10421127161820"><a name="b10421127161820"></a><a name="b10421127161820"></a>-1</strong> is returned, indicating that the network configuration is successful or fails.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Example of the NAN type

    ```
    let netConfigInfo = {
    	ssid: wifiApInfo.ssid,
    	ssidPassword: '',
    	isDefaultPassword: true,
    	channel: wifiApInfo.channel,
    	sessionId: getApp(this).ConfigParams.deviceInfo.sessionId,
    	type: 0,
    	wifiApId: wifiApInfo.wifiApId,
    	vendorData: '',
    	timeout: 30,
    	paramValid: true
    };
    getApp(this).NetConfig.configDeviceNet('deviceInfo', 'accountInfo', netConfigInfo, (result) => {
    	if (result.code == 0) {
    		this.progress = this.progressStatus[4];
    		this.desc = this.descStatus[4];
    		this.registerMsgReceive()
    		this.goToControl();
    	} else {
    		this.progress = this.progressStatus[4];
    		this.desc = this.failDescStatus[4];
    		this.disconnectDevice();
    	}
    });
    ```

-   Example of the SoftAP type

    ```
    let netConfigInfo = {
    	ssid: wifiApInfo.ssid,
    	ssidPassword: '',
    	isDefaultPassword: true,
    	channel: wifiApInfo.channel,
    	sessionId: getApp(this).ConfigParams.deviceInfo.sessionId,
    	type: 1,
    	wifiApId: wifiApInfo.wifiApId,
    	vendorData: '',
    	timeout: 30,
    	paramValid: true
    };
    getApp(this).NetConfig.configDeviceNet('deviceInfo', 'accountInfo', netConfigInfo, (result) => {
    	if (result.code == 0) {
    		this.progress = this.progressStatus[4];
    		this.desc = this.descStatus[4];
    		this.registerMsgReceive()
    		this.goToControl();
    	} else {
    		this.progress = this.progressStatus[4];
    		this.desc = this.failDescStatus[4];
    		this.disconnectDevice();
    	}
    });
    ```


## Releasing the Network Configuration Channel<a name="section194641109530"></a>

<a name="table128870433546"></a>
<table><tbody><tr id="row1297394375419"><th class="firstcol" valign="top" width="28.95%" id="mcps1.1.3.1.1"><p id="p129731143135410"><a name="p129731143135410"></a><a name="p129731143135410"></a>Function Prototype</p>
</th>
<td class="cellrowborder" valign="top" width="71.05%" headers="mcps1.1.3.1.1 "><p id="p17973124395410"><a name="p17973124395410"></a><a name="p17973124395410"></a>NetConfig.disconnectDevice(commonInfo,callbackFunc)</p>
</td>
</tr>
<tr id="row17973204315415"><th class="firstcol" valign="top" width="28.95%" id="mcps1.1.3.2.1"><p id="p2973743165416"><a name="p2973743165416"></a><a name="p2973743165416"></a>Description</p>
</th>
<td class="cellrowborder" valign="top" width="71.05%" headers="mcps1.1.3.2.1 "><p id="p1097344385414"><a name="p1097344385414"></a><a name="p1097344385414"></a>Releases the network configuration channel. When the atomic service does not use the NAN channel or the atomic service exits, the atomic service needs to proactively call this function.</p>
</td>
</tr>
<tr id="row19973194335418"><th class="firstcol" valign="top" width="28.95%" id="mcps1.1.3.3.1"><p id="p1397314345410"><a name="p1397314345410"></a><a name="p1397314345410"></a>API Type</p>
</th>
<td class="cellrowborder" valign="top" width="71.05%" headers="mcps1.1.3.3.1 "><p id="p1197314315411"><a name="p1197314315411"></a><a name="p1197314315411"></a>Asynchronous API</p>
</td>
</tr>
<tr id="row397319439545"><th class="firstcol" valign="top" width="28.95%" id="mcps1.1.3.4.1"><p id="p2097317431544"><a name="p2097317431544"></a><a name="p2097317431544"></a>Input Parameter</p>
</th>
<td class="cellrowborder" valign="top" width="71.05%" headers="mcps1.1.3.4.1 "><p id="p9973184315541"><a name="p9973184315541"></a><a name="p9973184315541"></a>commonInfo</p>
</td>
</tr>
<tr id="row69741743125419"><th class="firstcol" valign="top" width="28.95%" id="mcps1.1.3.5.1"><p id="p5974154310544"><a name="p5974154310544"></a><a name="p5974154310544"></a>Return Value</p>
</th>
<td class="cellrowborder" valign="top" width="71.05%" headers="mcps1.1.3.5.1 "><p id="p7974134311548"><a name="p7974134311548"></a><a name="p7974134311548"></a><strong id="b2285194575711"><a name="b2285194575711"></a><a name="b2285194575711"></a>0</strong> (success) and <strong id="b6285545135712"><a name="b6285545135712"></a><a name="b6285545135712"></a>-1</strong> (failure)</p>
</td>
</tr>
</tbody>
</table>

-   Parameters

    <a name="table16964125885416"></a>
    <table><thead align="left"><tr id="row9991125815410"><th class="cellrowborder" valign="top" width="17.57175717571757%" id="mcps1.1.5.1.1"><p id="p1299155816541"><a name="p1299155816541"></a><a name="p1299155816541"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="11.821182118211821%" id="mcps1.1.5.1.2"><p id="p129911658145417"><a name="p129911658145417"></a><a name="p129911658145417"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="10.26102610261026%" id="mcps1.1.5.1.3"><p id="p12991105815417"><a name="p12991105815417"></a><a name="p12991105815417"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="60.34603460346035%" id="mcps1.1.5.1.4"><p id="p59914581544"><a name="p59914581544"></a><a name="p59914581544"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row4991185815417"><td class="cellrowborder" valign="top" width="17.57175717571757%" headers="mcps1.1.5.1.1 "><p id="p99911858205413"><a name="p99911858205413"></a><a name="p99911858205413"></a>commonInfo</p>
    </td>
    <td class="cellrowborder" valign="top" width="11.821182118211821%" headers="mcps1.1.5.1.2 "><p id="p1699135845419"><a name="p1699135845419"></a><a name="p1699135845419"></a>Object</p>
    </td>
    <td class="cellrowborder" valign="top" width="10.26102610261026%" headers="mcps1.1.5.1.3 "><p id="p299115875419"><a name="p299115875419"></a><a name="p299115875419"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="60.34603460346035%" headers="mcps1.1.5.1.4 "><p id="p10991758125410"><a name="p10991758125410"></a><a name="p10991758125410"></a>commonInfo{</p>
    <p id="p19991958145416"><a name="p19991958145416"></a><a name="p19991958145416"></a>String sessionId; // If <strong id="b3440141171511"><a name="b3440141171511"></a><a name="b3440141171511"></a>type</strong> is <strong id="b102924159157"><a name="b102924159157"></a><a name="b102924159157"></a>NAN</strong>, set this parameter to the value of <strong id="b19898142613159"><a name="b19898142613159"></a><a name="b19898142613159"></a>sessionId</strong> returned by <strong id="b13883103331511"><a name="b13883103331511"></a><a name="b13883103331511"></a>discoverDevByNAN</strong>. Otherwise, set this parameter to "".</p>
    <p id="p699195810547"><a name="p699195810547"></a><a name="p699195810547"></a>}</p>
    </td>
    </tr>
    <tr id="row1099120586543"><td class="cellrowborder" valign="top" width="17.57175717571757%" headers="mcps1.1.5.1.1 "><p id="p13991105817544"><a name="p13991105817544"></a><a name="p13991105817544"></a>callbackFunc</p>
    </td>
    <td class="cellrowborder" valign="top" width="11.821182118211821%" headers="mcps1.1.5.1.2 "><p id="p399220582548"><a name="p399220582548"></a><a name="p399220582548"></a>function</p>
    </td>
    <td class="cellrowborder" valign="top" width="10.26102610261026%" headers="mcps1.1.5.1.3 "><p id="p109921558195417"><a name="p109921558195417"></a><a name="p109921558195417"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="60.34603460346035%" headers="mcps1.1.5.1.4 "><p id="p1099255814547"><a name="p1099255814547"></a><a name="p1099255814547"></a>Callback function. If the callback is successful, <strong id="b19521505614"><a name="b19521505614"></a><a name="b19521505614"></a>data</strong> contains the returned data result. The data result is parsed and used in the callback.</p>
    <p id="p14992458205413"><a name="p14992458205413"></a><a name="p14992458205413"></a>Data returned: <strong id="b20729161914215"><a name="b20729161914215"></a><a name="b20729161914215"></a>0</strong> (success) or <strong id="b15756172782120"><a name="b15756172782120"></a><a name="b15756172782120"></a>-1</strong> (failure)</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Example

    ```
    let commonInfo = {
    	sessionId: getApp(this).ConfigParams.deviceInfo.sessionId
    }
    getApp(this).NetConfig.disconnectDevice(commonInfo, (result) => {
    	if (result.code == 0) {
    		return;
    	}
    });
    ```


## Controlling the Device in Seconds<a name="section144171232175313"></a>

<a name="table7293155175619"></a>
<table><tbody><tr id="row1835917518565"><th class="firstcol" valign="top" width="29.470000000000002%" id="mcps1.1.3.1.1"><p id="p93591518565"><a name="p93591518565"></a><a name="p93591518565"></a>Function Prototype</p>
</th>
<td class="cellrowborder" valign="top" width="70.53%" headers="mcps1.1.3.1.1 "><p id="p1835917518569"><a name="p1835917518569"></a><a name="p1835917518569"></a>NetConfig.sendMessage(commonInfo,message,callbackFunc)</p>
</td>
</tr>
<tr id="row335918595614"><th class="firstcol" valign="top" width="29.470000000000002%" id="mcps1.1.3.2.1"><p id="p0359659565"><a name="p0359659565"></a><a name="p0359659565"></a>Description</p>
</th>
<td class="cellrowborder" valign="top" width="70.53%" headers="mcps1.1.3.2.1 "><p id="p17359205155619"><a name="p17359205155619"></a><a name="p17359205155619"></a>Sends a message to the device for control purposes.</p>
</td>
</tr>
<tr id="row1035975175619"><th class="firstcol" valign="top" width="29.470000000000002%" id="mcps1.1.3.3.1"><p id="p1735914517561"><a name="p1735914517561"></a><a name="p1735914517561"></a>API Type</p>
</th>
<td class="cellrowborder" valign="top" width="70.53%" headers="mcps1.1.3.3.1 "><p id="p1136014517562"><a name="p1136014517562"></a><a name="p1136014517562"></a>Asynchronous API</p>
</td>
</tr>
<tr id="row63602519566"><th class="firstcol" valign="top" width="29.470000000000002%" id="mcps1.1.3.4.1"><p id="p236019517563"><a name="p236019517563"></a><a name="p236019517563"></a>Return Value</p>
</th>
<td class="cellrowborder" valign="top" width="70.53%" headers="mcps1.1.3.4.1 "><p id="p183601656561"><a name="p183601656561"></a><a name="p183601656561"></a><strong id="b18286144525710"><a name="b18286144525710"></a><a name="b18286144525710"></a>0</strong> (success) and <strong id="b1228618458578"><a name="b1228618458578"></a><a name="b1228618458578"></a>-1</strong> (failure)</p>
</td>
</tr>
</tbody>
</table>

-   Parameters

    <a name="table1810171665618"></a>
    <table><thead align="left"><tr id="row12858141695611"><th class="cellrowborder" valign="top" width="16.400000000000002%" id="mcps1.1.5.1.1"><p id="p148588169568"><a name="p148588169568"></a><a name="p148588169568"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="13.41%" id="mcps1.1.5.1.2"><p id="p13858616185615"><a name="p13858616185615"></a><a name="p13858616185615"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="8.99%" id="mcps1.1.5.1.3"><p id="p19858111675611"><a name="p19858111675611"></a><a name="p19858111675611"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="61.199999999999996%" id="mcps1.1.5.1.4"><p id="p58581116175612"><a name="p58581116175612"></a><a name="p58581116175612"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row485831610563"><td class="cellrowborder" valign="top" width="16.400000000000002%" headers="mcps1.1.5.1.1 "><p id="p58581016155610"><a name="p58581016155610"></a><a name="p58581016155610"></a>commonInfo</p>
    </td>
    <td class="cellrowborder" valign="top" width="13.41%" headers="mcps1.1.5.1.2 "><p id="p13858201645612"><a name="p13858201645612"></a><a name="p13858201645612"></a>Object</p>
    </td>
    <td class="cellrowborder" valign="top" width="8.99%" headers="mcps1.1.5.1.3 "><p id="p20858101625614"><a name="p20858101625614"></a><a name="p20858101625614"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.199999999999996%" headers="mcps1.1.5.1.4 "><p id="p38583161561"><a name="p38583161561"></a><a name="p38583161561"></a>commonInfo{</p>
    <p id="p78581216145614"><a name="p78581216145614"></a><a name="p78581216145614"></a>String sessionId; // If <strong id="b74690302168"><a name="b74690302168"></a><a name="b74690302168"></a>type</strong> is <strong id="b17420143331613"><a name="b17420143331613"></a><a name="b17420143331613"></a>NAN</strong>, set this parameter to the value of <strong id="b20445244121612"><a name="b20445244121612"></a><a name="b20445244121612"></a>sessionId</strong> returned by <strong id="b1432516478167"><a name="b1432516478167"></a><a name="b1432516478167"></a>discoverDevByNAN</strong>. Otherwise, set this parameter to "".</p>
    <p id="p185851616560"><a name="p185851616560"></a><a name="p185851616560"></a>}</p>
    </td>
    </tr>
    <tr id="row485811169560"><td class="cellrowborder" valign="top" width="16.400000000000002%" headers="mcps1.1.5.1.1 "><p id="p16858121612564"><a name="p16858121612564"></a><a name="p16858121612564"></a>message</p>
    </td>
    <td class="cellrowborder" valign="top" width="13.41%" headers="mcps1.1.5.1.2 "><p id="p1385861675612"><a name="p1385861675612"></a><a name="p1385861675612"></a>String</p>
    </td>
    <td class="cellrowborder" valign="top" width="8.99%" headers="mcps1.1.5.1.3 "><p id="p178582162567"><a name="p178582162567"></a><a name="p178582162567"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.199999999999996%" headers="mcps1.1.5.1.4 "><p id="p12858216205613"><a name="p12858216205613"></a><a name="p12858216205613"></a>Message content.</p>
    </td>
    </tr>
    <tr id="row17858141610567"><td class="cellrowborder" valign="top" width="16.400000000000002%" headers="mcps1.1.5.1.1 "><p id="p148581816155611"><a name="p148581816155611"></a><a name="p148581816155611"></a>callbackFunc</p>
    </td>
    <td class="cellrowborder" valign="top" width="13.41%" headers="mcps1.1.5.1.2 "><p id="p585819166568"><a name="p585819166568"></a><a name="p585819166568"></a>function</p>
    </td>
    <td class="cellrowborder" valign="top" width="8.99%" headers="mcps1.1.5.1.3 "><p id="p5858201645617"><a name="p5858201645617"></a><a name="p5858201645617"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.199999999999996%" headers="mcps1.1.5.1.4 "><p id="p885811610561"><a name="p885811610561"></a><a name="p885811610561"></a>Callback function, which returns the command sending result.</p>
    <p id="p6858316165614"><a name="p6858316165614"></a><a name="p6858316165614"></a>Data returned: <strong id="b115438327219"><a name="b115438327219"></a><a name="b115438327219"></a>0</strong> (success) or <strong id="b1754333262117"><a name="b1754333262117"></a><a name="b1754333262117"></a>-1</strong> (failure)</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Example

    ```
    let commonInfo = {
    	sessionId: getApp(this).ConfigParams.deviceInfo.sessionId
    }
    getApp(this).NetConfig.sendMessage(commonInfo, "111111", (result) => {
    	// sendMessage callback
    })
    ```


## Registering Message Callbacks<a name="section7232650195315"></a>

<a name="table38194613569"></a>
<table><tbody><tr id="row0371246105618"><th class="firstcol" valign="top" width="32.25%" id="mcps1.1.3.1.1"><p id="p113784655612"><a name="p113784655612"></a><a name="p113784655612"></a>Function Prototype</p>
</th>
<td class="cellrowborder" valign="top" width="67.75%" headers="mcps1.1.3.1.1 "><p id="p33748588181"><a name="p33748588181"></a><a name="p33748588181"></a>NetConfig.registerMsgReceive(commonInfo, callbackFunc)</p>
</td>
</tr>
<tr id="row1937646205610"><th class="firstcol" valign="top" width="32.25%" id="mcps1.1.3.2.1"><p id="p1937144617568"><a name="p1937144617568"></a><a name="p1937144617568"></a>Description</p>
</th>
<td class="cellrowborder" valign="top" width="67.75%" headers="mcps1.1.3.2.1 "><p id="p1737184612564"><a name="p1737184612564"></a><a name="p1737184612564"></a>Obtains messages on the device side. You are advised to call this function before calling the device connection API in NAN mode.</p>
</td>
</tr>
<tr id="row237446185610"><th class="firstcol" valign="top" width="32.25%" id="mcps1.1.3.3.1"><p id="p5371046105617"><a name="p5371046105617"></a><a name="p5371046105617"></a>API Type</p>
</th>
<td class="cellrowborder" valign="top" width="67.75%" headers="mcps1.1.3.3.1 "><p id="p237164615616"><a name="p237164615616"></a><a name="p237164615616"></a>Asynchronous API</p>
</td>
</tr>
<tr id="row163784695613"><th class="firstcol" valign="top" width="32.25%" id="mcps1.1.3.4.1"><p id="p163717468566"><a name="p163717468566"></a><a name="p163717468566"></a>Input Parameter</p>
</th>
<td class="cellrowborder" valign="top" width="67.75%" headers="mcps1.1.3.4.1 "><p id="p19371546175612"><a name="p19371546175612"></a><a name="p19371546175612"></a>See the table below.</p>
</td>
</tr>
<tr id="row73784665619"><th class="firstcol" valign="top" width="32.25%" id="mcps1.1.3.5.1"><p id="p17381346185612"><a name="p17381346185612"></a><a name="p17381346185612"></a>Return Value</p>
</th>
<td class="cellrowborder" valign="top" width="67.75%" headers="mcps1.1.3.5.1 "><p id="p12383462562"><a name="p12383462562"></a><a name="p12383462562"></a><strong id="b32871445125717"><a name="b32871445125717"></a><a name="b32871445125717"></a>0</strong> (success) and <strong id="b1928711452575"><a name="b1928711452575"></a><a name="b1928711452575"></a>-1</strong> (failure)</p>
</td>
</tr>
</tbody>
</table>

-   Parameters

    <a name="table103185565712"></a>
    <table><thead align="left"><tr id="row133429513571"><th class="cellrowborder" valign="top" id="mcps1.1.6.1.1"><p id="p15342145145716"><a name="p15342145145716"></a><a name="p15342145145716"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" id="mcps1.1.6.1.2"><p id="p183423545714"><a name="p183423545714"></a><a name="p183423545714"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" id="mcps1.1.6.1.3"><p id="p1834219517579"><a name="p1834219517579"></a><a name="p1834219517579"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" colspan="2" valign="top" id="mcps1.1.6.1.4"><p id="p173421459575"><a name="p173421459575"></a><a name="p173421459575"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row83422520571"><td class="cellrowborder" valign="top" headers="mcps1.1.6.1.1 "><p id="p134219517573"><a name="p134219517573"></a><a name="p134219517573"></a>commonInfo</p>
    </td>
    <td class="cellrowborder" valign="top" headers="mcps1.1.6.1.2 "><p id="p634213518572"><a name="p634213518572"></a><a name="p634213518572"></a>Object</p>
    </td>
    <td class="cellrowborder" valign="top" headers="mcps1.1.6.1.3 "><p id="p2034211545715"><a name="p2034211545715"></a><a name="p2034211545715"></a>Yes</p>
    </td>
    <td class="cellrowborder" colspan="2" valign="top" headers="mcps1.1.6.1.4 "><p id="p1342356574"><a name="p1342356574"></a><a name="p1342356574"></a>commonInfo{</p>
    <p id="p1634216515711"><a name="p1634216515711"></a><a name="p1634216515711"></a>String sessionId; // If <strong id="b1071211571912"><a name="b1071211571912"></a><a name="b1071211571912"></a>type</strong> is <strong id="b187120519196"><a name="b187120519196"></a><a name="b187120519196"></a>NAN</strong>, set this parameter to the value of <strong id="b20712357198"><a name="b20712357198"></a><a name="b20712357198"></a>sessionId</strong> returned by <strong id="b1771319511199"><a name="b1771319511199"></a><a name="b1771319511199"></a>discoverDevByNAN</strong>. Otherwise, set this parameter to "".</p>
    <p id="p63423585719"><a name="p63423585719"></a><a name="p63423585719"></a>}</p>
    </td>
    </tr>
    <tr id="row113431152578"><td class="cellrowborder" valign="top" headers="mcps1.1.6.1.1 "><p id="p1343115145711"><a name="p1343115145711"></a><a name="p1343115145711"></a>callbackFunc</p>
    </td>
    <td class="cellrowborder" valign="top" headers="mcps1.1.6.1.2 "><p id="p1934314520573"><a name="p1934314520573"></a><a name="p1934314520573"></a>function</p>
    </td>
    <td class="cellrowborder" valign="top" headers="mcps1.1.6.1.3 "><p id="p1134365145710"><a name="p1134365145710"></a><a name="p1134365145710"></a>Yes</p>
    </td>
    <td class="cellrowborder" colspan="2" valign="top" headers="mcps1.1.6.1.4 "><p id="p93434585716"><a name="p93434585716"></a><a name="p93434585716"></a>Callback function. If the callback is successful, <strong id="b827170173817"><a name="b827170173817"></a><a name="b827170173817"></a>data</strong> contains the returned data result. The data result is parsed and used in the callback.</p>
    <p id="p20343351576"><a name="p20343351576"></a><a name="p20343351576"></a>Data returned: String message</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Example

    ```
    let commonInfo = {
    	sessionId: getApp(this).ConfigParams.deviceInfo.sessionId
    }
    getApp(this).NetConfig.registerMsgReceive(commonInfo, () => {
    	// registerMsgReceive callback
    });
    ```


## Callback for Device Disconnection<a name="section176579445411"></a>

<a name="table19930677582"></a>
<table><tbody><tr id="row109561471585"><th class="firstcol" valign="top" width="18.54%" id="mcps1.1.3.1.1"><p id="p1595647145811"><a name="p1595647145811"></a><a name="p1595647145811"></a>Function Prototype</p>
</th>
<td class="cellrowborder" valign="top" width="81.46%" headers="mcps1.1.3.1.1 "><p id="p9218543151217"><a name="p9218543151217"></a><a name="p9218543151217"></a>NetConfig.registerDisconnectCallback(commonInfo, callbackFunc)</p>
</td>
</tr>
<tr id="row2095618718587"><th class="firstcol" valign="top" width="18.54%" id="mcps1.1.3.2.1"><p id="p5956272581"><a name="p5956272581"></a><a name="p5956272581"></a>Description</p>
</th>
<td class="cellrowborder" valign="top" width="81.46%" headers="mcps1.1.3.2.1 "><p id="p19569719585"><a name="p19569719585"></a><a name="p19569719585"></a>Registers the callback for device disconnection events. You are advised to call this function before calling the device connection API in NAN mode.</p>
<p id="p1495618716583"><a name="p1495618716583"></a><a name="p1495618716583"></a>When the device is disconnected from the phone unexpectedly, the callback is triggered.</p>
</td>
</tr>
<tr id="row149563775817"><th class="firstcol" valign="top" width="18.54%" id="mcps1.1.3.3.1"><p id="p209561872581"><a name="p209561872581"></a><a name="p209561872581"></a>API Type</p>
</th>
<td class="cellrowborder" valign="top" width="81.46%" headers="mcps1.1.3.3.1 "><p id="p895614718582"><a name="p895614718582"></a><a name="p895614718582"></a>Asynchronous API</p>
</td>
</tr>
<tr id="row10956876588"><th class="firstcol" valign="top" width="18.54%" id="mcps1.1.3.4.1"><p id="p119564775815"><a name="p119564775815"></a><a name="p119564775815"></a>Input Parameter</p>
</th>
<td class="cellrowborder" valign="top" width="81.46%" headers="mcps1.1.3.4.1 "><p id="p09561077586"><a name="p09561077586"></a><a name="p09561077586"></a>See the table below.</p>
</td>
</tr>
<tr id="row295610725819"><th class="firstcol" valign="top" width="18.54%" id="mcps1.1.3.5.1"><p id="p1095687185817"><a name="p1095687185817"></a><a name="p1095687185817"></a>Return Value</p>
</th>
<td class="cellrowborder" valign="top" width="81.46%" headers="mcps1.1.3.5.1 "><p id="p9956575589"><a name="p9956575589"></a><a name="p9956575589"></a><strong id="b7288645185716"><a name="b7288645185716"></a><a name="b7288645185716"></a>0</strong> (success) and <strong id="b82881745115711"><a name="b82881745115711"></a><a name="b82881745115711"></a>-1</strong> (failure)</p>
</td>
</tr>
</tbody>
</table>

-   Parameters

    <a name="table12296223105818"></a>
    <table><thead align="left"><tr id="row13327122315586"><th class="cellrowborder" valign="top" width="18.34%" id="mcps1.1.5.1.1"><p id="p3327102315582"><a name="p3327102315582"></a><a name="p3327102315582"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="17.28%" id="mcps1.1.5.1.2"><p id="p17327172319583"><a name="p17327172319583"></a><a name="p17327172319583"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="9.879999999999999%" id="mcps1.1.5.1.3"><p id="p732792365817"><a name="p732792365817"></a><a name="p732792365817"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="54.50000000000001%" id="mcps1.1.5.1.4"><p id="p103270238580"><a name="p103270238580"></a><a name="p103270238580"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row143278239582"><td class="cellrowborder" valign="top" width="18.34%" headers="mcps1.1.5.1.1 "><p id="p53276239586"><a name="p53276239586"></a><a name="p53276239586"></a>commonInfo</p>
    </td>
    <td class="cellrowborder" valign="top" width="17.28%" headers="mcps1.1.5.1.2 "><p id="p2327192305812"><a name="p2327192305812"></a><a name="p2327192305812"></a>Object</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.879999999999999%" headers="mcps1.1.5.1.3 "><p id="p8327172315586"><a name="p8327172315586"></a><a name="p8327172315586"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="54.50000000000001%" headers="mcps1.1.5.1.4 "><p id="p183275239582"><a name="p183275239582"></a><a name="p183275239582"></a>commonInfo{</p>
    <p id="p1632712311585"><a name="p1632712311585"></a><a name="p1632712311585"></a>String sessionId; // If <strong id="b18666925142214"><a name="b18666925142214"></a><a name="b18666925142214"></a>type</strong> is <strong id="b1666162514226"><a name="b1666162514226"></a><a name="b1666162514226"></a>NAN</strong>, set this parameter to the value of <strong id="b18666172512226"><a name="b18666172512226"></a><a name="b18666172512226"></a>sessionId</strong> returned by <strong id="b066618259224"><a name="b066618259224"></a><a name="b066618259224"></a>discoverDevByNAN</strong>. Otherwise, set this parameter to "".</p>
    <p id="p63271623145811"><a name="p63271623145811"></a><a name="p63271623145811"></a>}</p>
    </td>
    </tr>
    <tr id="row5327112315586"><td class="cellrowborder" valign="top" width="18.34%" headers="mcps1.1.5.1.1 "><p id="p8327112316582"><a name="p8327112316582"></a><a name="p8327112316582"></a>callbackFunc</p>
    </td>
    <td class="cellrowborder" valign="top" width="17.28%" headers="mcps1.1.5.1.2 "><p id="p4327132315816"><a name="p4327132315816"></a><a name="p4327132315816"></a>function</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.879999999999999%" headers="mcps1.1.5.1.3 "><p id="p16327192313589"><a name="p16327192313589"></a><a name="p16327192313589"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="54.50000000000001%" headers="mcps1.1.5.1.4 "><p id="p11327102385817"><a name="p11327102385817"></a><a name="p11327102385817"></a>Callback function. This callback is triggered when the device is disconnected from the phone.</p>
    <p id="p13271123155817"><a name="p13271123155817"></a><a name="p13271123155817"></a>Status code returned: 0</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Example

    ```
    let commonInfo = {
    	sessionId: getApp(this).ConfigParams.deviceInfo.sessionId
    }
    getApp(this).NetConfig.registerDisconnectCallback(commonInfo, () => {
    	// registerDisconnectCallback
    });
    ```


