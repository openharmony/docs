# 配网接口调用<a name="ZH-CN_TOPIC_0000001158605995"></a>

-   [是否持WifiAware](#section1488020125510)
-   [获取Wifi列表](#section743413288512)
-   [通过NAN发现设备](#section1504174410511)
-   [通过SoftAP发现设备](#section55681185218)
-   [连接设备](#section4392324115210)
-   [对指定设备进行配网](#section772433526)
-   [释放配网通道](#section194641109530)
-   [秒控接口](#section144171232175313)
-   [注册消息回调](#section7232650195315)
-   [设备断链通知回调消息](#section176579445411)

配网相关接口都在login/fa-netconfig.js下。

参考app.js中的import netConfig from 'fa-netconfig'进行引用。

## 是否持WifiAware<a name="section1488020125510"></a>

<a name="table363724418353"></a>
<table><tbody><tr id="row12769644123510"><th class="firstcol" valign="top" width="31.580000000000002%" id="mcps1.1.3.1.1"><p id="p1769844113511"><a name="p1769844113511"></a><a name="p1769844113511"></a>函数原型</p>
</th>
<td class="cellrowborder" valign="top" width="68.42%" headers="mcps1.1.3.1.1 "><p id="p159318523353"><a name="p159318523353"></a><a name="p159318523353"></a>NetConfig.isSupportWifiAware()</p>
</td>
</tr>
<tr id="row976954433512"><th class="firstcol" valign="top" width="31.580000000000002%" id="mcps1.1.3.2.1"><p id="p0770134411354"><a name="p0770134411354"></a><a name="p0770134411354"></a>说明</p>
</th>
<td class="cellrowborder" valign="top" width="68.42%" headers="mcps1.1.3.2.1 "><p id="p777024413512"><a name="p777024413512"></a><a name="p777024413512"></a>WifiAware是否支持。</p>
</td>
</tr>
<tr id="row177701444173514"><th class="firstcol" valign="top" width="31.580000000000002%" id="mcps1.1.3.3.1"><p id="p3770144493519"><a name="p3770144493519"></a><a name="p3770144493519"></a>接口类型</p>
</th>
<td class="cellrowborder" valign="top" width="68.42%" headers="mcps1.1.3.3.1 "><p id="p07701244183515"><a name="p07701244183515"></a><a name="p07701244183515"></a>同步接口</p>
</td>
</tr>
<tr id="row12770204412352"><th class="firstcol" valign="top" width="31.580000000000002%" id="mcps1.1.3.4.1"><p id="p167707440352"><a name="p167707440352"></a><a name="p167707440352"></a>返回值</p>
</th>
<td class="cellrowborder" valign="top" width="68.42%" headers="mcps1.1.3.4.1 "><p id="p1977004419359"><a name="p1977004419359"></a><a name="p1977004419359"></a>0（支持）/ -1（不支持）</p>
</td>
</tr>
</tbody>
</table>

-   参数

    无

-   示例：

    ```
    getApp(this).NetConfig.isSupportWifiAware().then(function (result) {
    	let ret = JSON.parse(result);
    	console.info("isSupportWifiAware消息结果: code=" + ret.code + ", data=" + ret.data);
    	if (ret.code == 0) {
    		//支持WifiAware
    	} else {
    		//不支持WifiAware
    	}
    });
    ```


## 获取Wifi列表<a name="section743413288512"></a>

<a name="table1717191916404"></a>
<table><tbody><tr id="row3202419184016"><th class="firstcol" valign="top" width="34.260000000000005%" id="mcps1.1.3.1.1"><p id="p0202419124019"><a name="p0202419124019"></a><a name="p0202419124019"></a>函数原型</p>
</th>
<td class="cellrowborder" valign="top" width="65.74%" headers="mcps1.1.3.1.1 "><p id="p92028195407"><a name="p92028195407"></a><a name="p92028195407"></a>NetConfig.getWifiList(callbackFunc)</p>
</td>
</tr>
<tr id="row720261917406"><th class="firstcol" valign="top" width="34.260000000000005%" id="mcps1.1.3.2.1"><p id="p1020331934015"><a name="p1020331934015"></a><a name="p1020331934015"></a>说明</p>
</th>
<td class="cellrowborder" valign="top" width="65.74%" headers="mcps1.1.3.2.1 "><p id="p0203141954013"><a name="p0203141954013"></a><a name="p0203141954013"></a>获取周边wifi列表。</p>
</td>
</tr>
<tr id="row92032192404"><th class="firstcol" valign="top" width="34.260000000000005%" id="mcps1.1.3.3.1"><p id="p6203131924015"><a name="p6203131924015"></a><a name="p6203131924015"></a>接口类型</p>
</th>
<td class="cellrowborder" valign="top" width="65.74%" headers="mcps1.1.3.3.1 "><p id="p6203219164019"><a name="p6203219164019"></a><a name="p6203219164019"></a>异步接口</p>
</td>
</tr>
<tr id="row13203519184015"><th class="firstcol" valign="top" width="34.260000000000005%" id="mcps1.1.3.4.1"><p id="p1920321994015"><a name="p1920321994015"></a><a name="p1920321994015"></a>返回值</p>
</th>
<td class="cellrowborder" valign="top" width="65.74%" headers="mcps1.1.3.4.1 "><p id="p192032198404"><a name="p192032198404"></a><a name="p192032198404"></a>0（成功）/ -1（失败）</p>
</td>
</tr>
</tbody>
</table>

-   参数

    <a name="table156944377389"></a>
    <table><thead align="left"><tr id="row9694637163812"><th class="cellrowborder" valign="top" width="15.73%" id="mcps1.1.5.1.1"><p id="p626854064118"><a name="p626854064118"></a><a name="p626854064118"></a>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="11.06%" id="mcps1.1.5.1.2"><p id="p926819401412"><a name="p926819401412"></a><a name="p926819401412"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="8.709999999999999%" id="mcps1.1.5.1.3"><p id="p1726884018418"><a name="p1726884018418"></a><a name="p1726884018418"></a>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="64.5%" id="mcps1.1.5.1.4"><p id="p1326815406411"><a name="p1326815406411"></a><a name="p1326815406411"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row166951637133810"><td class="cellrowborder" valign="top" width="15.73%" headers="mcps1.1.5.1.1 "><p id="p14268204010415"><a name="p14268204010415"></a><a name="p14268204010415"></a>callbackFunc</p>
    </td>
    <td class="cellrowborder" valign="top" width="11.06%" headers="mcps1.1.5.1.2 "><p id="p1826811403411"><a name="p1826811403411"></a><a name="p1826811403411"></a>function</p>
    </td>
    <td class="cellrowborder" valign="top" width="8.709999999999999%" headers="mcps1.1.5.1.3 "><p id="p192688400414"><a name="p192688400414"></a><a name="p192688400414"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="64.5%" headers="mcps1.1.5.1.4 "><p id="p726854034116"><a name="p726854034116"></a><a name="p726854034116"></a>回调函数，回调成功的情况下，data为返回数据结果，在该回调函数中解析使用数据结果。</p>
    <p id="p102686402419"><a name="p102686402419"></a><a name="p102686402419"></a>返回：List&lt;WifiApInfo&gt;</p>
    <p id="p5268144014113"><a name="p5268144014113"></a><a name="p5268144014113"></a>WifiApInfo {</p>
    <p id="p1226810401419"><a name="p1226810401419"></a><a name="p1226810401419"></a>int channel;</p>
    <p id="p22681940164113"><a name="p22681940164113"></a><a name="p22681940164113"></a>boolean hasDefaultPassword;</p>
    <p id="p526816404417"><a name="p526816404417"></a><a name="p526816404417"></a>boolean is5G; // 是否是5G wifi</p>
    <p id="p1926814064115"><a name="p1926814064115"></a><a name="p1926814064115"></a>String securityType;</p>
    <p id="p18268640164113"><a name="p18268640164113"></a><a name="p18268640164113"></a>int signalLevel;</p>
    <p id="p112681040194120"><a name="p112681040194120"></a><a name="p112681040194120"></a>String ssid;</p>
    <p id="p1226844094110"><a name="p1226844094110"></a><a name="p1226844094110"></a>String wifiApId; // wifiAp ID</p>
    <p id="p1826854018411"><a name="p1826854018411"></a><a name="p1826854018411"></a>}</p>
    <p id="p02683405411"><a name="p02683405411"></a><a name="p02683405411"></a>2.4G和5G都返回，原子化服务只需通过is5G是否支持5G进行筛选过滤；</p>
    <p id="p13268184064110"><a name="p13268184064110"></a><a name="p13268184064110"></a>周边范围内的已配置过，并且能够成功获取密码的ssid，hasDefaultPassword才为true；</p>
    </td>
    </tr>
    </tbody>
    </table>

-   示例

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


## 通过NAN发现设备<a name="section1504174410511"></a>

<a name="table1576075594214"></a>
<table><tbody><tr id="row17849855174211"><th class="firstcol" valign="top" width="31.39%" id="mcps1.1.3.1.1"><p id="p584955510426"><a name="p584955510426"></a><a name="p584955510426"></a>函数原型</p>
</th>
<td class="cellrowborder" valign="top" width="68.61%" headers="mcps1.1.3.1.1 "><p id="p17849165510422"><a name="p17849165510422"></a><a name="p17849165510422"></a>NetConfig.discoveryByNAN(scanNanInfo, callbackFunc)</p>
</td>
</tr>
<tr id="row19849105594212"><th class="firstcol" valign="top" width="31.39%" id="mcps1.1.3.2.1"><p id="p188491551425"><a name="p188491551425"></a><a name="p188491551425"></a>说明</p>
</th>
<td class="cellrowborder" valign="top" width="68.61%" headers="mcps1.1.3.2.1 "><p id="p084965517423"><a name="p084965517423"></a><a name="p084965517423"></a>广播NAN服务，等待客户端连接，建立起一条连接，停止广播。</p>
</td>
</tr>
<tr id="row584912559421"><th class="firstcol" valign="top" width="31.39%" id="mcps1.1.3.3.1"><p id="p9849555114216"><a name="p9849555114216"></a><a name="p9849555114216"></a>接口类型</p>
</th>
<td class="cellrowborder" valign="top" width="68.61%" headers="mcps1.1.3.3.1 "><p id="p1849255194219"><a name="p1849255194219"></a><a name="p1849255194219"></a>异步接口</p>
</td>
</tr>
<tr id="row7849145584212"><th class="firstcol" valign="top" width="31.39%" id="mcps1.1.3.4.1"><p id="p18849455174211"><a name="p18849455174211"></a><a name="p18849455174211"></a>返回值</p>
</th>
<td class="cellrowborder" valign="top" width="68.61%" headers="mcps1.1.3.4.1 "><p id="p1484910557421"><a name="p1484910557421"></a><a name="p1484910557421"></a>0（成功）/ -1（失败）</p>
</td>
</tr>
</tbody>
</table>

-   参数

    <a name="table14693111134316"></a>
    <table><thead align="left"><tr id="row37448110431"><th class="cellrowborder" valign="top" width="17.798220177982202%" id="mcps1.1.5.1.1"><p id="p127441111154317"><a name="p127441111154317"></a><a name="p127441111154317"></a>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="11.968803119688031%" id="mcps1.1.5.1.2"><p id="p574541114431"><a name="p574541114431"></a><a name="p574541114431"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="11.968803119688031%" id="mcps1.1.5.1.3"><p id="p1274521154310"><a name="p1274521154310"></a><a name="p1274521154310"></a>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="58.26417358264173%" id="mcps1.1.5.1.4"><p id="p1374531144319"><a name="p1374531144319"></a><a name="p1374531144319"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row9745151164311"><td class="cellrowborder" valign="top" width="17.798220177982202%" headers="mcps1.1.5.1.1 "><p id="p674511114317"><a name="p674511114317"></a><a name="p674511114317"></a>scanNanInfo</p>
    </td>
    <td class="cellrowborder" valign="top" width="11.968803119688031%" headers="mcps1.1.5.1.2 "><p id="p15745201120435"><a name="p15745201120435"></a><a name="p15745201120435"></a>Object</p>
    </td>
    <td class="cellrowborder" valign="top" width="11.968803119688031%" headers="mcps1.1.5.1.3 "><p id="p17451811174316"><a name="p17451811174316"></a><a name="p17451811174316"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="58.26417358264173%" headers="mcps1.1.5.1.4 "><p id="p20745711104316"><a name="p20745711104316"></a><a name="p20745711104316"></a>scanNanInfo {</p>
    <p id="p17745141116439"><a name="p17745141116439"></a><a name="p17745141116439"></a>int duration; 在指定的duration时间内未建立起连接，停止广播，单位为秒，范围[0,100],0表示不限制时长。</p>
    <p id="p6745151184310"><a name="p6745151184310"></a><a name="p6745151184310"></a>int lockTime; 设备收到NAN互信消息后在NAN模式的锁定时长，单位为秒，范围[0,100],0表示不限制时长。</p>
    <p id="p2745101184317"><a name="p2745101184317"></a><a name="p2745101184317"></a>String sessionId; 值为service拉起原子化服务时的Intent携带的sessionId值。</p>
    <p id="p137451511144313"><a name="p137451511144313"></a><a name="p137451511144313"></a>}</p>
    </td>
    </tr>
    <tr id="row1174531110436"><td class="cellrowborder" valign="top" width="17.798220177982202%" headers="mcps1.1.5.1.1 "><p id="p6745181115436"><a name="p6745181115436"></a><a name="p6745181115436"></a>callbackFunc</p>
    </td>
    <td class="cellrowborder" valign="top" width="11.968803119688031%" headers="mcps1.1.5.1.2 "><p id="p4745611124319"><a name="p4745611124319"></a><a name="p4745611124319"></a>function</p>
    </td>
    <td class="cellrowborder" valign="top" width="11.968803119688031%" headers="mcps1.1.5.1.3 "><p id="p1274531110430"><a name="p1274531110430"></a><a name="p1274531110430"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="58.26417358264173%" headers="mcps1.1.5.1.4 "><p id="p7745911124314"><a name="p7745911124314"></a><a name="p7745911124314"></a>回调函数，回调成功的情况下，data为返回数据结果，在该回调函数中解析使用数据结果。返回：</p>
    <p id="p197451111104319"><a name="p197451111104319"></a><a name="p197451111104319"></a>DeviceInfo{</p>
    <p id="p1874561113432"><a name="p1874561113432"></a><a name="p1874561113432"></a>String productId,</p>
    <p id="p11745411114311"><a name="p11745411114311"></a><a name="p11745411114311"></a>String sessionId</p>
    <p id="p274551118435"><a name="p274551118435"></a><a name="p274551118435"></a>String sn,</p>
    <p id="p1474581116435"><a name="p1474581116435"></a><a name="p1474581116435"></a>}</p>
    </td>
    </tr>
    </tbody>
    </table>

-   示例：

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


## 通过SoftAP发现设备<a name="section55681185218"></a>

<a name="table20458153644412"></a>
<table><tbody><tr id="row1055614367448"><th class="firstcol" valign="top" width="29.29%" id="mcps1.1.3.1.1"><p id="p1355623614444"><a name="p1355623614444"></a><a name="p1355623614444"></a>函数原型</p>
</th>
<td class="cellrowborder" valign="top" width="70.71%" headers="mcps1.1.3.1.1 "><p id="p1688316106306"><a name="p1688316106306"></a><a name="p1688316106306"></a>NetConfig.discoveryBySoftAP(callbackFunc)</p>
</td>
</tr>
<tr id="row655623618445"><th class="firstcol" valign="top" width="29.29%" id="mcps1.1.3.2.1"><p id="p255643615444"><a name="p255643615444"></a><a name="p255643615444"></a>说明</p>
</th>
<td class="cellrowborder" valign="top" width="70.71%" headers="mcps1.1.3.2.1 "><p id="p195561836184411"><a name="p195561836184411"></a><a name="p195561836184411"></a>扫描AP。</p>
</td>
</tr>
<tr id="row13557123664414"><th class="firstcol" valign="top" width="29.29%" id="mcps1.1.3.3.1"><p id="p14557123654410"><a name="p14557123654410"></a><a name="p14557123654410"></a>接口类型</p>
</th>
<td class="cellrowborder" valign="top" width="70.71%" headers="mcps1.1.3.3.1 "><p id="p15557163620448"><a name="p15557163620448"></a><a name="p15557163620448"></a>异步接口</p>
</td>
</tr>
<tr id="row14557236124412"><th class="firstcol" valign="top" width="29.29%" id="mcps1.1.3.4.1"><p id="p55571236134417"><a name="p55571236134417"></a><a name="p55571236134417"></a>输入参数</p>
</th>
<td class="cellrowborder" valign="top" width="70.71%" headers="mcps1.1.3.4.1 "><p id="p2557136164416"><a name="p2557136164416"></a><a name="p2557136164416"></a>由原子化服务自行确定调用次数</p>
</td>
</tr>
<tr id="row35571336194410"><th class="firstcol" valign="top" width="29.29%" id="mcps1.1.3.5.1"><p id="p1655763674419"><a name="p1655763674419"></a><a name="p1655763674419"></a>返回值</p>
</th>
<td class="cellrowborder" valign="top" width="70.71%" headers="mcps1.1.3.5.1 "><p id="p75571636124418"><a name="p75571636124418"></a><a name="p75571636124418"></a>0（成功）/ -1（失败）</p>
</td>
</tr>
</tbody>
</table>

-   参数

    <a name="table69251651204410"></a>
    <table><thead align="left"><tr id="row1495415519449"><th class="cellrowborder" valign="top" width="17.82%" id="mcps1.1.5.1.1"><p id="p12954851144412"><a name="p12954851144412"></a><a name="p12954851144412"></a>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="11.99%" id="mcps1.1.5.1.2"><p id="p29541518441"><a name="p29541518441"></a><a name="p29541518441"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="10.41%" id="mcps1.1.5.1.3"><p id="p69541051144414"><a name="p69541051144414"></a><a name="p69541051144414"></a>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="59.78%" id="mcps1.1.5.1.4"><p id="p9954951144419"><a name="p9954951144419"></a><a name="p9954951144419"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row1795411515442"><td class="cellrowborder" valign="top" width="17.82%" headers="mcps1.1.5.1.1 "><p id="p1495465118444"><a name="p1495465118444"></a><a name="p1495465118444"></a>callbackFunc</p>
    </td>
    <td class="cellrowborder" valign="top" width="11.99%" headers="mcps1.1.5.1.2 "><p id="p795485111444"><a name="p795485111444"></a><a name="p795485111444"></a>function</p>
    </td>
    <td class="cellrowborder" valign="top" width="10.41%" headers="mcps1.1.5.1.3 "><p id="p11954251194420"><a name="p11954251194420"></a><a name="p11954251194420"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="59.78%" headers="mcps1.1.5.1.4 "><p id="p1495411516446"><a name="p1495411516446"></a><a name="p1495411516446"></a>回调函数，回调成功的情况下，data为返回数据结果，在该回调函数中解析使用数据结果。</p>
    <p id="p189557513442"><a name="p189557513442"></a><a name="p189557513442"></a>返回：List&lt;SoftAPInfo&gt; SoftAPInfo{</p>
    <p id="p15955125119448"><a name="p15955125119448"></a><a name="p15955125119448"></a>String ssid,</p>
    <p id="p179558518449"><a name="p179558518449"></a><a name="p179558518449"></a>boolean usePassword // 是否需要使用密码</p>
    <p id="p5955175111443"><a name="p5955175111443"></a><a name="p5955175111443"></a>}</p>
    </td>
    </tr>
    </tbody>
    </table>

-   示例：

    ```
    getApp(this).NetConfig.discoveryBySoftAP((result) => {
    	if (result.code == 0) {
    		for (let index = 0; index < result.data.length; index++) {
    			let element = result.data[index];
    			console.info("discoveryBySoftAP回调：device element=" + JSON.stringify(element));
    			// softAP扫描到的列表中，与既定的设备的ssid格式+品类+mac地址进行比对
    			if (element.ssid.indexOf(self.softAPSsidDefault) != -1) {
    				this.discoverDeviceBySoftAPResult = JSON.stringify(element);
    				this.softAPSsidDefault = element.ssid;
    				break;
    			}
    		}
    	}
    });
    ```


## 连接设备<a name="section4392324115210"></a>

<a name="table132751845184515"></a>
<table><tbody><tr id="row142354710453"><th class="firstcol" valign="top" width="31.730000000000004%" id="mcps1.1.3.1.1"><p id="p342313479450"><a name="p342313479450"></a><a name="p342313479450"></a>函数原型</p>
</th>
<td class="cellrowborder" valign="top" width="68.27%" headers="mcps1.1.3.1.1 "><p id="p13423447124517"><a name="p13423447124517"></a><a name="p13423447124517"></a>NetConfig.connectDevice(connectInfo,callbackFunc)</p>
</td>
</tr>
<tr id="row542317476453"><th class="firstcol" valign="top" width="31.730000000000004%" id="mcps1.1.3.2.1"><p id="p442314720451"><a name="p442314720451"></a><a name="p442314720451"></a>说明</p>
</th>
<td class="cellrowborder" valign="top" width="68.27%" headers="mcps1.1.3.2.1 "><p id="p17423747164510"><a name="p17423747164510"></a><a name="p17423747164510"></a>连接设备。</p>
</td>
</tr>
<tr id="row242319478452"><th class="firstcol" valign="top" width="31.730000000000004%" id="mcps1.1.3.3.1"><p id="p1642394704512"><a name="p1642394704512"></a><a name="p1642394704512"></a>接口类型</p>
</th>
<td class="cellrowborder" valign="top" width="68.27%" headers="mcps1.1.3.3.1 "><p id="p54239476451"><a name="p54239476451"></a><a name="p54239476451"></a>异步接口</p>
</td>
</tr>
<tr id="row1742394713458"><th class="firstcol" valign="top" width="31.730000000000004%" id="mcps1.1.3.4.1"><p id="p11423154711451"><a name="p11423154711451"></a><a name="p11423154711451"></a>返回值</p>
</th>
<td class="cellrowborder" valign="top" width="68.27%" headers="mcps1.1.3.4.1 "><p id="p11423184734516"><a name="p11423184734516"></a><a name="p11423184734516"></a>0（成功）/ -1（失败）</p>
</td>
</tr>
</tbody>
</table>

-   参数

    <a name="table146121713204612"></a>
    <table><thead align="left"><tr id="row365515136467"><th class="cellrowborder" valign="top" width="15.958404159584042%" id="mcps1.1.5.1.1"><p id="p6655201314618"><a name="p6655201314618"></a><a name="p6655201314618"></a>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="11.688831116888311%" id="mcps1.1.5.1.2"><p id="p3655713104617"><a name="p3655713104617"></a><a name="p3655713104617"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="11.218878112188781%" id="mcps1.1.5.1.3"><p id="p565511134464"><a name="p565511134464"></a><a name="p565511134464"></a>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="61.13388661133887%" id="mcps1.1.5.1.4"><p id="p1065561384615"><a name="p1065561384615"></a><a name="p1065561384615"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row3655213104610"><td class="cellrowborder" valign="top" width="15.958404159584042%" headers="mcps1.1.5.1.1 "><p id="p2655121312460"><a name="p2655121312460"></a><a name="p2655121312460"></a>connectInfo</p>
    </td>
    <td class="cellrowborder" valign="top" width="11.688831116888311%" headers="mcps1.1.5.1.2 "><p id="p116551313184613"><a name="p116551313184613"></a><a name="p116551313184613"></a>Object</p>
    </td>
    <td class="cellrowborder" valign="top" width="11.218878112188781%" headers="mcps1.1.5.1.3 "><p id="p176551213114613"><a name="p176551213114613"></a><a name="p176551213114613"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.13388661133887%" headers="mcps1.1.5.1.4 "><p id="p17655181374619"><a name="p17655181374619"></a><a name="p17655181374619"></a>connectInfo {</p>
    <p id="p1165541317461"><a name="p1165541317461"></a><a name="p1165541317461"></a>string targetDeviceId; //必填，待连接设备的标识。</p>
    <a name="ul46551213184611"></a><a name="ul46551213184611"></a><ul id="ul46551213184611"><li>number type; //必填，0（NAN）/ 1（SoftAp）。</li><li>string pin; //必填，设备pin。</li><li>string password; //必填，若设备需要密码，则设置为所需密码；否则设置为""。</li><li>string sessionId; //必填，若type为NAN，则设置为discoverDevByNAN 返回的sessionId；否则设置为""。<p id="p3655181324610"><a name="p3655181324610"></a><a name="p3655181324610"></a>}</p>
    </li></ul>
    </td>
    </tr>
    <tr id="row965561334615"><td class="cellrowborder" valign="top" width="15.958404159584042%" headers="mcps1.1.5.1.1 "><p id="p19655121314617"><a name="p19655121314617"></a><a name="p19655121314617"></a>callbackFunc</p>
    </td>
    <td class="cellrowborder" valign="top" width="11.688831116888311%" headers="mcps1.1.5.1.2 "><p id="p9655191313466"><a name="p9655191313466"></a><a name="p9655191313466"></a>function</p>
    </td>
    <td class="cellrowborder" valign="top" width="11.218878112188781%" headers="mcps1.1.5.1.3 "><p id="p18655141364615"><a name="p18655141364615"></a><a name="p18655141364615"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.13388661133887%" headers="mcps1.1.5.1.4 "><p id="p3655113184615"><a name="p3655113184615"></a><a name="p3655113184615"></a>回调函数，回调成功的情况下，data为返回数据结果，在该回调函数中解析使用数据结果。</p>
    <p id="p16655151319465"><a name="p16655151319465"></a><a name="p16655151319465"></a>返回：String vendorData // 后续扩展使用。</p>
    <p id="p196550137466"><a name="p196550137466"></a><a name="p196550137466"></a>Softap模式下返回{</p>
    <p id="p1965591344615"><a name="p1965591344615"></a><a name="p1965591344615"></a>String productId，</p>
    <p id="p11656111310462"><a name="p11656111310462"></a><a name="p11656111310462"></a>String sn，</p>
    <p id="p13656171384616"><a name="p13656171384616"></a><a name="p13656171384616"></a>String vendorData</p>
    <p id="p1165618134463"><a name="p1165618134463"></a><a name="p1165618134463"></a>} 的JSON格式字符串</p>
    </td>
    </tr>
    </tbody>
    </table>

-   NAN类型示例

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

-   SoftAP类型示例

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


## 对指定设备进行配网<a name="section772433526"></a>

<a name="table766315593514"></a>
<table><tbody><tr id="row18751195915512"><th class="firstcol" valign="top" width="30.509999999999998%" id="mcps1.1.3.1.1"><p id="p275105985117"><a name="p275105985117"></a><a name="p275105985117"></a>函数原型</p>
</th>
<td class="cellrowborder" valign="top" width="69.49%" headers="mcps1.1.3.1.1 "><p id="p147511459125120"><a name="p147511459125120"></a><a name="p147511459125120"></a>NetConfig.configDeviceNet(deviceInfo,accountInfo,netConfigInfo,callbackFunc)</p>
</td>
</tr>
<tr id="row97511594514"><th class="firstcol" valign="top" width="30.509999999999998%" id="mcps1.1.3.2.1"><p id="p97518597517"><a name="p97518597517"></a><a name="p97518597517"></a>说明</p>
</th>
<td class="cellrowborder" valign="top" width="69.49%" headers="mcps1.1.3.2.1 "><p id="p875135945115"><a name="p875135945115"></a><a name="p875135945115"></a>开始对指定的设备进行配网，发送SSID和密码，以及设备和账号信息。</p>
</td>
</tr>
<tr id="row1875112593518"><th class="firstcol" valign="top" width="30.509999999999998%" id="mcps1.1.3.3.1"><p id="p3752155918516"><a name="p3752155918516"></a><a name="p3752155918516"></a>接口类型</p>
</th>
<td class="cellrowborder" valign="top" width="69.49%" headers="mcps1.1.3.3.1 "><p id="p157521159165112"><a name="p157521159165112"></a><a name="p157521159165112"></a>异步接口</p>
</td>
</tr>
<tr id="row675285919511"><th class="firstcol" valign="top" width="30.509999999999998%" id="mcps1.1.3.4.1"><p id="p13752135985113"><a name="p13752135985113"></a><a name="p13752135985113"></a>返回值</p>
</th>
<td class="cellrowborder" valign="top" width="69.49%" headers="mcps1.1.3.4.1 "><p id="p1775213598514"><a name="p1775213598514"></a><a name="p1775213598514"></a>0（成功）/ -1（失败）</p>
</td>
</tr>
</tbody>
</table>

-   参数

    <a name="table011339165214"></a>
    <table><thead align="left"><tr id="row14729396525"><th class="cellrowborder" valign="top" width="16.82%" id="mcps1.1.5.1.1"><p id="p4721639105217"><a name="p4721639105217"></a><a name="p4721639105217"></a>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="12.620000000000001%" id="mcps1.1.5.1.2"><p id="p1721639145218"><a name="p1721639145218"></a><a name="p1721639145218"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="11.68%" id="mcps1.1.5.1.3"><p id="p14721239155216"><a name="p14721239155216"></a><a name="p14721239155216"></a>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="58.879999999999995%" id="mcps1.1.5.1.4"><p id="p37203911525"><a name="p37203911525"></a><a name="p37203911525"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row127273985212"><td class="cellrowborder" valign="top" width="16.82%" headers="mcps1.1.5.1.1 "><p id="p77243917526"><a name="p77243917526"></a><a name="p77243917526"></a>deviceInfo</p>
    </td>
    <td class="cellrowborder" valign="top" width="12.620000000000001%" headers="mcps1.1.5.1.2 "><p id="p872153913526"><a name="p872153913526"></a><a name="p872153913526"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="11.68%" headers="mcps1.1.5.1.3 "><p id="p3721539125215"><a name="p3721539125215"></a><a name="p3721539125215"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="58.879999999999995%" headers="mcps1.1.5.1.4 "><p id="p1872133916526"><a name="p1872133916526"></a><a name="p1872133916526"></a>设备云为设备分配的信息，如deviceID等</p>
    </td>
    </tr>
    <tr id="row27293965211"><td class="cellrowborder" valign="top" width="16.82%" headers="mcps1.1.5.1.1 "><p id="p5723395522"><a name="p5723395522"></a><a name="p5723395522"></a>accountInfo</p>
    </td>
    <td class="cellrowborder" valign="top" width="12.620000000000001%" headers="mcps1.1.5.1.2 "><p id="p072143905216"><a name="p072143905216"></a><a name="p072143905216"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="11.68%" headers="mcps1.1.5.1.3 "><p id="p172193965210"><a name="p172193965210"></a><a name="p172193965210"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="58.879999999999995%" headers="mcps1.1.5.1.4 "><p id="p472163918521"><a name="p472163918521"></a><a name="p472163918521"></a>账号信息</p>
    </td>
    </tr>
    <tr id="row77218399529"><td class="cellrowborder" valign="top" width="16.82%" headers="mcps1.1.5.1.1 "><p id="p17731839105218"><a name="p17731839105218"></a><a name="p17731839105218"></a>netConfigInfo</p>
    </td>
    <td class="cellrowborder" valign="top" width="12.620000000000001%" headers="mcps1.1.5.1.2 "><p id="p167393919522"><a name="p167393919522"></a><a name="p167393919522"></a>Object</p>
    </td>
    <td class="cellrowborder" valign="top" width="11.68%" headers="mcps1.1.5.1.3 "><p id="p1373439175215"><a name="p1373439175215"></a><a name="p1373439175215"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="58.879999999999995%" headers="mcps1.1.5.1.4 "><p id="p1973839105216"><a name="p1973839105216"></a><a name="p1973839105216"></a>netConfigInfo {</p>
    <p id="p18731639135213"><a name="p18731639135213"></a><a name="p18731639135213"></a>string ssid;</p>
    <p id="p27323955214"><a name="p27323955214"></a><a name="p27323955214"></a>//必填，如果是手机已经配置过的ssid，可免输密码。</p>
    <p id="p187318398523"><a name="p187318398523"></a><a name="p187318398523"></a>string ssidPassword;//非必填，不需要下发密码时，填写“”。</p>
    <p id="p1073123912525"><a name="p1073123912525"></a><a name="p1073123912525"></a>boolean isDefaultPassword; //必填。</p>
    <p id="p1173739165213"><a name="p1173739165213"></a><a name="p1173739165213"></a>int channel; //必填。</p>
    <p id="p3732399523"><a name="p3732399523"></a><a name="p3732399523"></a>string sessionId; //必填,type为NAN时填实际值；type为softAp时填“”。</p>
    <p id="p107343985217"><a name="p107343985217"></a><a name="p107343985217"></a>int type; //必填,0（NAN）/ 1(softAp)。</p>
    <p id="p197353917529"><a name="p197353917529"></a><a name="p197353917529"></a>String wifiApId; //填写wifi列表返回信息中的对应字段。</p>
    <p id="p15731139185218"><a name="p15731139185218"></a><a name="p15731139185218"></a>String vendorData; //产品数据，当前为random Base64编码;</p>
    <p id="p157319392526"><a name="p157319392526"></a><a name="p157319392526"></a>int timeout; // 配网超时时间，在NAN模式下设置，范围[1,90]s。</p>
    <p id="p5731339125215"><a name="p5731339125215"></a><a name="p5731339125215"></a>}</p>
    <p id="p177314391525"><a name="p177314391525"></a><a name="p177314391525"></a>说明:如果用户输入密码，则isDefaultPassword=false, ssidPassword=“输入的密码”；否则按使用默认密码处理，isDefaultPassword=true, ssidPassword=””</p>
    </td>
    </tr>
    <tr id="row1173539155215"><td class="cellrowborder" valign="top" width="16.82%" headers="mcps1.1.5.1.1 "><p id="p117353905211"><a name="p117353905211"></a><a name="p117353905211"></a>callbackFunc</p>
    </td>
    <td class="cellrowborder" valign="top" width="12.620000000000001%" headers="mcps1.1.5.1.2 "><p id="p177313912528"><a name="p177313912528"></a><a name="p177313912528"></a>function</p>
    </td>
    <td class="cellrowborder" valign="top" width="11.68%" headers="mcps1.1.5.1.3 "><p id="p13739392522"><a name="p13739392522"></a><a name="p13739392522"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="58.879999999999995%" headers="mcps1.1.5.1.4 "><p id="p1373183955219"><a name="p1373183955219"></a><a name="p1373183955219"></a>回调函数，NAN配网模式中，回调成功表示模组上报配网状态结果，其结果会转换成整型数值放到data.code，字符串类型会放到data.msg; SoftAp配网模式中，返回0/ -1表示配网成功/失败；</p>
    </td>
    </tr>
    </tbody>
    </table>

-   NAN类型示例

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

-   SoftAP类型示例

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


## 释放配网通道<a name="section194641109530"></a>

<a name="table128870433546"></a>
<table><tbody><tr id="row1297394375419"><th class="firstcol" valign="top" width="28.95%" id="mcps1.1.3.1.1"><p id="p129731143135410"><a name="p129731143135410"></a><a name="p129731143135410"></a>函数原型</p>
</th>
<td class="cellrowborder" valign="top" width="71.05%" headers="mcps1.1.3.1.1 "><p id="p17973124395410"><a name="p17973124395410"></a><a name="p17973124395410"></a>NetConfig.disconnectDevice(commonInfo,callbackFunc)</p>
</td>
</tr>
<tr id="row17973204315415"><th class="firstcol" valign="top" width="28.95%" id="mcps1.1.3.2.1"><p id="p2973743165416"><a name="p2973743165416"></a><a name="p2973743165416"></a>说明</p>
</th>
<td class="cellrowborder" valign="top" width="71.05%" headers="mcps1.1.3.2.1 "><p id="p1097344385414"><a name="p1097344385414"></a><a name="p1097344385414"></a>释放配网通道，在原子化服务不再使用NAN通道、原子化服务退出等情况需要原子化服务主动调用该接口。</p>
</td>
</tr>
<tr id="row19973194335418"><th class="firstcol" valign="top" width="28.95%" id="mcps1.1.3.3.1"><p id="p1397314345410"><a name="p1397314345410"></a><a name="p1397314345410"></a>接口类型</p>
</th>
<td class="cellrowborder" valign="top" width="71.05%" headers="mcps1.1.3.3.1 "><p id="p1197314315411"><a name="p1197314315411"></a><a name="p1197314315411"></a>异步接口</p>
</td>
</tr>
<tr id="row397319439545"><th class="firstcol" valign="top" width="28.95%" id="mcps1.1.3.4.1"><p id="p2097317431544"><a name="p2097317431544"></a><a name="p2097317431544"></a>输入参数</p>
</th>
<td class="cellrowborder" valign="top" width="71.05%" headers="mcps1.1.3.4.1 "><p id="p9973184315541"><a name="p9973184315541"></a><a name="p9973184315541"></a>commonInfo</p>
</td>
</tr>
<tr id="row69741743125419"><th class="firstcol" valign="top" width="28.95%" id="mcps1.1.3.5.1"><p id="p5974154310544"><a name="p5974154310544"></a><a name="p5974154310544"></a>返回值</p>
</th>
<td class="cellrowborder" valign="top" width="71.05%" headers="mcps1.1.3.5.1 "><p id="p7974134311548"><a name="p7974134311548"></a><a name="p7974134311548"></a>0（成功）/ -1（失败）</p>
</td>
</tr>
</tbody>
</table>

-   参数

    <a name="table16964125885416"></a>
    <table><thead align="left"><tr id="row9991125815410"><th class="cellrowborder" valign="top" width="17.57175717571757%" id="mcps1.1.5.1.1"><p id="p1299155816541"><a name="p1299155816541"></a><a name="p1299155816541"></a>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="11.821182118211821%" id="mcps1.1.5.1.2"><p id="p129911658145417"><a name="p129911658145417"></a><a name="p129911658145417"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="10.26102610261026%" id="mcps1.1.5.1.3"><p id="p12991105815417"><a name="p12991105815417"></a><a name="p12991105815417"></a>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="60.34603460346035%" id="mcps1.1.5.1.4"><p id="p59914581544"><a name="p59914581544"></a><a name="p59914581544"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row4991185815417"><td class="cellrowborder" valign="top" width="17.57175717571757%" headers="mcps1.1.5.1.1 "><p id="p99911858205413"><a name="p99911858205413"></a><a name="p99911858205413"></a>commonInfo</p>
    </td>
    <td class="cellrowborder" valign="top" width="11.821182118211821%" headers="mcps1.1.5.1.2 "><p id="p1699135845419"><a name="p1699135845419"></a><a name="p1699135845419"></a>Object</p>
    </td>
    <td class="cellrowborder" valign="top" width="10.26102610261026%" headers="mcps1.1.5.1.3 "><p id="p299115875419"><a name="p299115875419"></a><a name="p299115875419"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="60.34603460346035%" headers="mcps1.1.5.1.4 "><p id="p10991758125410"><a name="p10991758125410"></a><a name="p10991758125410"></a>commonInfo{</p>
    <p id="p19991958145416"><a name="p19991958145416"></a><a name="p19991958145416"></a>String sessionId; //若type为NAN，则设置为discoverDevByNAN 返回的sessionId；SoftAp设置为””。</p>
    <p id="p699195810547"><a name="p699195810547"></a><a name="p699195810547"></a>}</p>
    </td>
    </tr>
    <tr id="row1099120586543"><td class="cellrowborder" valign="top" width="17.57175717571757%" headers="mcps1.1.5.1.1 "><p id="p13991105817544"><a name="p13991105817544"></a><a name="p13991105817544"></a>callbackFunc</p>
    </td>
    <td class="cellrowborder" valign="top" width="11.821182118211821%" headers="mcps1.1.5.1.2 "><p id="p399220582548"><a name="p399220582548"></a><a name="p399220582548"></a>function</p>
    </td>
    <td class="cellrowborder" valign="top" width="10.26102610261026%" headers="mcps1.1.5.1.3 "><p id="p109921558195417"><a name="p109921558195417"></a><a name="p109921558195417"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="60.34603460346035%" headers="mcps1.1.5.1.4 "><p id="p1099255814547"><a name="p1099255814547"></a><a name="p1099255814547"></a>回调函数，回调成功的情况下，data为返回数据结果，在该回调函数中解析使用数据结果。</p>
    <p id="p14992458205413"><a name="p14992458205413"></a><a name="p14992458205413"></a>返回：0（成功）/ -1（失败）</p>
    </td>
    </tr>
    </tbody>
    </table>

-   示例：

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


## 秒控接口<a name="section144171232175313"></a>

<a name="table7293155175619"></a>
<table><tbody><tr id="row1835917518565"><th class="firstcol" valign="top" width="29.470000000000002%" id="mcps1.1.3.1.1"><p id="p93591518565"><a name="p93591518565"></a><a name="p93591518565"></a>函数原型</p>
</th>
<td class="cellrowborder" valign="top" width="70.53%" headers="mcps1.1.3.1.1 "><p id="p1835917518569"><a name="p1835917518569"></a><a name="p1835917518569"></a>NetConfig.sendMessage(commonInfo,message,callbackFunc)</p>
</td>
</tr>
<tr id="row335918595614"><th class="firstcol" valign="top" width="29.470000000000002%" id="mcps1.1.3.2.1"><p id="p0359659565"><a name="p0359659565"></a><a name="p0359659565"></a>说明</p>
</th>
<td class="cellrowborder" valign="top" width="70.53%" headers="mcps1.1.3.2.1 "><p id="p17359205155619"><a name="p17359205155619"></a><a name="p17359205155619"></a>秒控接口。</p>
</td>
</tr>
<tr id="row1035975175619"><th class="firstcol" valign="top" width="29.470000000000002%" id="mcps1.1.3.3.1"><p id="p1735914517561"><a name="p1735914517561"></a><a name="p1735914517561"></a>接口类型</p>
</th>
<td class="cellrowborder" valign="top" width="70.53%" headers="mcps1.1.3.3.1 "><p id="p1136014517562"><a name="p1136014517562"></a><a name="p1136014517562"></a>异步接口</p>
</td>
</tr>
<tr id="row63602519566"><th class="firstcol" valign="top" width="29.470000000000002%" id="mcps1.1.3.4.1"><p id="p236019517563"><a name="p236019517563"></a><a name="p236019517563"></a>返回值</p>
</th>
<td class="cellrowborder" valign="top" width="70.53%" headers="mcps1.1.3.4.1 "><p id="p183601656561"><a name="p183601656561"></a><a name="p183601656561"></a>0（成功）/ -1（失败）</p>
</td>
</tr>
</tbody>
</table>

-   参数

    <a name="table1810171665618"></a>
    <table><thead align="left"><tr id="row12858141695611"><th class="cellrowborder" valign="top" width="16.400000000000002%" id="mcps1.1.5.1.1"><p id="p148588169568"><a name="p148588169568"></a><a name="p148588169568"></a>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="13.41%" id="mcps1.1.5.1.2"><p id="p13858616185615"><a name="p13858616185615"></a><a name="p13858616185615"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="8.99%" id="mcps1.1.5.1.3"><p id="p19858111675611"><a name="p19858111675611"></a><a name="p19858111675611"></a>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="61.199999999999996%" id="mcps1.1.5.1.4"><p id="p58581116175612"><a name="p58581116175612"></a><a name="p58581116175612"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row485831610563"><td class="cellrowborder" valign="top" width="16.400000000000002%" headers="mcps1.1.5.1.1 "><p id="p58581016155610"><a name="p58581016155610"></a><a name="p58581016155610"></a>commonInfo</p>
    </td>
    <td class="cellrowborder" valign="top" width="13.41%" headers="mcps1.1.5.1.2 "><p id="p13858201645612"><a name="p13858201645612"></a><a name="p13858201645612"></a>Object</p>
    </td>
    <td class="cellrowborder" valign="top" width="8.99%" headers="mcps1.1.5.1.3 "><p id="p20858101625614"><a name="p20858101625614"></a><a name="p20858101625614"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.199999999999996%" headers="mcps1.1.5.1.4 "><p id="p38583161561"><a name="p38583161561"></a><a name="p38583161561"></a>commonInfo{</p>
    <p id="p78581216145614"><a name="p78581216145614"></a><a name="p78581216145614"></a>String sessionId; //若type为NAN，则设置为discoverDevByNAN 返回的sessionId；否则设置为””。</p>
    <p id="p185851616560"><a name="p185851616560"></a><a name="p185851616560"></a>}</p>
    </td>
    </tr>
    <tr id="row485811169560"><td class="cellrowborder" valign="top" width="16.400000000000002%" headers="mcps1.1.5.1.1 "><p id="p16858121612564"><a name="p16858121612564"></a><a name="p16858121612564"></a>message</p>
    </td>
    <td class="cellrowborder" valign="top" width="13.41%" headers="mcps1.1.5.1.2 "><p id="p1385861675612"><a name="p1385861675612"></a><a name="p1385861675612"></a>String</p>
    </td>
    <td class="cellrowborder" valign="top" width="8.99%" headers="mcps1.1.5.1.3 "><p id="p178582162567"><a name="p178582162567"></a><a name="p178582162567"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.199999999999996%" headers="mcps1.1.5.1.4 "><p id="p12858216205613"><a name="p12858216205613"></a><a name="p12858216205613"></a>消息内容</p>
    </td>
    </tr>
    <tr id="row17858141610567"><td class="cellrowborder" valign="top" width="16.400000000000002%" headers="mcps1.1.5.1.1 "><p id="p148581816155611"><a name="p148581816155611"></a><a name="p148581816155611"></a>callbackFunc</p>
    </td>
    <td class="cellrowborder" valign="top" width="13.41%" headers="mcps1.1.5.1.2 "><p id="p585819166568"><a name="p585819166568"></a><a name="p585819166568"></a>function</p>
    </td>
    <td class="cellrowborder" valign="top" width="8.99%" headers="mcps1.1.5.1.3 "><p id="p5858201645617"><a name="p5858201645617"></a><a name="p5858201645617"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.199999999999996%" headers="mcps1.1.5.1.4 "><p id="p885811610561"><a name="p885811610561"></a><a name="p885811610561"></a>回调函数，返回命令发送结果。</p>
    <p id="p6858316165614"><a name="p6858316165614"></a><a name="p6858316165614"></a>返回：0（成功）/ -1（失败）</p>
    </td>
    </tr>
    </tbody>
    </table>

-   示例：

    ```
    let commonInfo = {
    	sessionId: getApp(this).ConfigParams.deviceInfo.sessionId
    }
    getApp(this).NetConfig.sendMessage(commonInfo, "111111", (result) => {
    	// sendMessage 回调
    })
    ```


## 注册消息回调<a name="section7232650195315"></a>

<a name="table38194613569"></a>
<table><tbody><tr id="row0371246105618"><th class="firstcol" valign="top" width="32.25%" id="mcps1.1.3.1.1"><p id="p113784655612"><a name="p113784655612"></a><a name="p113784655612"></a>函数原型</p>
</th>
<td class="cellrowborder" valign="top" width="67.75%" headers="mcps1.1.3.1.1 "><p id="p33748588181"><a name="p33748588181"></a><a name="p33748588181"></a>NetConfig.registerMsgReceive(commonInfo, callbackFunc)</p>
</td>
</tr>
<tr id="row1937646205610"><th class="firstcol" valign="top" width="32.25%" id="mcps1.1.3.2.1"><p id="p1937144617568"><a name="p1937144617568"></a><a name="p1937144617568"></a>说明</p>
</th>
<td class="cellrowborder" valign="top" width="67.75%" headers="mcps1.1.3.2.1 "><p id="p1737184612564"><a name="p1737184612564"></a><a name="p1737184612564"></a>获取设备侧消息，建议在NAN配网模式下连接设备接口前调用。</p>
</td>
</tr>
<tr id="row237446185610"><th class="firstcol" valign="top" width="32.25%" id="mcps1.1.3.3.1"><p id="p5371046105617"><a name="p5371046105617"></a><a name="p5371046105617"></a>接口类型</p>
</th>
<td class="cellrowborder" valign="top" width="67.75%" headers="mcps1.1.3.3.1 "><p id="p237164615616"><a name="p237164615616"></a><a name="p237164615616"></a>异步接口</p>
</td>
</tr>
<tr id="row163784695613"><th class="firstcol" valign="top" width="32.25%" id="mcps1.1.3.4.1"><p id="p163717468566"><a name="p163717468566"></a><a name="p163717468566"></a>输入参数</p>
</th>
<td class="cellrowborder" valign="top" width="67.75%" headers="mcps1.1.3.4.1 "><p id="p19371546175612"><a name="p19371546175612"></a><a name="p19371546175612"></a>详见下方参数表格</p>
</td>
</tr>
<tr id="row73784665619"><th class="firstcol" valign="top" width="32.25%" id="mcps1.1.3.5.1"><p id="p17381346185612"><a name="p17381346185612"></a><a name="p17381346185612"></a>返回值</p>
</th>
<td class="cellrowborder" valign="top" width="67.75%" headers="mcps1.1.3.5.1 "><p id="p12383462562"><a name="p12383462562"></a><a name="p12383462562"></a>0（成功）/ -1（失败）</p>
</td>
</tr>
</tbody>
</table>

-   参数

    <a name="table103185565712"></a>
    <table><thead align="left"><tr id="row133429513571"><th class="cellrowborder" valign="top" id="mcps1.1.6.1.1"><p id="p15342145145716"><a name="p15342145145716"></a><a name="p15342145145716"></a>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" id="mcps1.1.6.1.2"><p id="p183423545714"><a name="p183423545714"></a><a name="p183423545714"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" id="mcps1.1.6.1.3"><p id="p1834219517579"><a name="p1834219517579"></a><a name="p1834219517579"></a>必填</p>
    </th>
    <th class="cellrowborder" colspan="2" valign="top" id="mcps1.1.6.1.4"><p id="p173421459575"><a name="p173421459575"></a><a name="p173421459575"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row83422520571"><td class="cellrowborder" valign="top" headers="mcps1.1.6.1.1 "><p id="p134219517573"><a name="p134219517573"></a><a name="p134219517573"></a>commonInfo</p>
    </td>
    <td class="cellrowborder" valign="top" headers="mcps1.1.6.1.2 "><p id="p634213518572"><a name="p634213518572"></a><a name="p634213518572"></a>Object</p>
    </td>
    <td class="cellrowborder" valign="top" headers="mcps1.1.6.1.3 "><p id="p2034211545715"><a name="p2034211545715"></a><a name="p2034211545715"></a>是</p>
    </td>
    <td class="cellrowborder" colspan="2" valign="top" headers="mcps1.1.6.1.4 "><p id="p1342356574"><a name="p1342356574"></a><a name="p1342356574"></a>commonInfo{</p>
    <p id="p1634216515711"><a name="p1634216515711"></a><a name="p1634216515711"></a>String sessionId; //若type为NAN，则设置为discoverDevByNAN 返回的sessionId；否则设置为””。</p>
    <p id="p63423585719"><a name="p63423585719"></a><a name="p63423585719"></a>}</p>
    </td>
    </tr>
    <tr id="row113431152578"><td class="cellrowborder" valign="top" headers="mcps1.1.6.1.1 "><p id="p1343115145711"><a name="p1343115145711"></a><a name="p1343115145711"></a>callbackFunc</p>
    </td>
    <td class="cellrowborder" valign="top" headers="mcps1.1.6.1.2 "><p id="p1934314520573"><a name="p1934314520573"></a><a name="p1934314520573"></a>function</p>
    </td>
    <td class="cellrowborder" valign="top" headers="mcps1.1.6.1.3 "><p id="p1134365145710"><a name="p1134365145710"></a><a name="p1134365145710"></a>是</p>
    </td>
    <td class="cellrowborder" colspan="2" valign="top" headers="mcps1.1.6.1.4 "><p id="p93434585716"><a name="p93434585716"></a><a name="p93434585716"></a>回调函数，回调成功的情况下，data为返回数据结果，在该回调函数中解析使用数据结果。</p>
    <p id="p20343351576"><a name="p20343351576"></a><a name="p20343351576"></a>返回：String message</p>
    </td>
    </tr>
    </tbody>
    </table>

-   示例：

    ```
    let commonInfo = {
    	sessionId: getApp(this).ConfigParams.deviceInfo.sessionId
    }
    getApp(this).NetConfig.registerMsgReceive(commonInfo, () => {
    	// registerMsgReceive 回调
    });
    ```


## 设备断链通知回调消息<a name="section176579445411"></a>

<a name="table19930677582"></a>
<table><tbody><tr id="row109561471585"><th class="firstcol" valign="top" width="18.54%" id="mcps1.1.3.1.1"><p id="p1595647145811"><a name="p1595647145811"></a><a name="p1595647145811"></a>函数原型</p>
</th>
<td class="cellrowborder" valign="top" width="81.46%" headers="mcps1.1.3.1.1 "><p id="p9218543151217"><a name="p9218543151217"></a><a name="p9218543151217"></a>NetConfig.registerDisconnectCallback(commonInfo, callbackFunc)</p>
</td>
</tr>
<tr id="row2095618718587"><th class="firstcol" valign="top" width="18.54%" id="mcps1.1.3.2.1"><p id="p5956272581"><a name="p5956272581"></a><a name="p5956272581"></a>说明</p>
</th>
<td class="cellrowborder" valign="top" width="81.46%" headers="mcps1.1.3.2.1 "><p id="p19569719585"><a name="p19569719585"></a><a name="p19569719585"></a>注册连接断开事件回调，建议在NAN配网模式下连接设备接口前调用。</p>
<p id="p1495618716583"><a name="p1495618716583"></a><a name="p1495618716583"></a>当因某些原因造成设备主动与手机断开连接时，会通过该回调通知。</p>
</td>
</tr>
<tr id="row149563775817"><th class="firstcol" valign="top" width="18.54%" id="mcps1.1.3.3.1"><p id="p209561872581"><a name="p209561872581"></a><a name="p209561872581"></a>接口类型</p>
</th>
<td class="cellrowborder" valign="top" width="81.46%" headers="mcps1.1.3.3.1 "><p id="p895614718582"><a name="p895614718582"></a><a name="p895614718582"></a>异步接口</p>
</td>
</tr>
<tr id="row10956876588"><th class="firstcol" valign="top" width="18.54%" id="mcps1.1.3.4.1"><p id="p119564775815"><a name="p119564775815"></a><a name="p119564775815"></a>输入参数</p>
</th>
<td class="cellrowborder" valign="top" width="81.46%" headers="mcps1.1.3.4.1 "><p id="p09561077586"><a name="p09561077586"></a><a name="p09561077586"></a>详见下方参数表格</p>
</td>
</tr>
<tr id="row295610725819"><th class="firstcol" valign="top" width="18.54%" id="mcps1.1.3.5.1"><p id="p1095687185817"><a name="p1095687185817"></a><a name="p1095687185817"></a>返回值</p>
</th>
<td class="cellrowborder" valign="top" width="81.46%" headers="mcps1.1.3.5.1 "><p id="p9956575589"><a name="p9956575589"></a><a name="p9956575589"></a>0（成功）/ -1（失败）</p>
</td>
</tr>
</tbody>
</table>

-   参数

    <a name="table12296223105818"></a>
    <table><thead align="left"><tr id="row13327122315586"><th class="cellrowborder" valign="top" width="18.34%" id="mcps1.1.5.1.1"><p id="p3327102315582"><a name="p3327102315582"></a><a name="p3327102315582"></a>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="17.28%" id="mcps1.1.5.1.2"><p id="p17327172319583"><a name="p17327172319583"></a><a name="p17327172319583"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="9.879999999999999%" id="mcps1.1.5.1.3"><p id="p732792365817"><a name="p732792365817"></a><a name="p732792365817"></a>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="54.50000000000001%" id="mcps1.1.5.1.4"><p id="p103270238580"><a name="p103270238580"></a><a name="p103270238580"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row143278239582"><td class="cellrowborder" valign="top" width="18.34%" headers="mcps1.1.5.1.1 "><p id="p53276239586"><a name="p53276239586"></a><a name="p53276239586"></a>commonInfo</p>
    </td>
    <td class="cellrowborder" valign="top" width="17.28%" headers="mcps1.1.5.1.2 "><p id="p2327192305812"><a name="p2327192305812"></a><a name="p2327192305812"></a>Object</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.879999999999999%" headers="mcps1.1.5.1.3 "><p id="p8327172315586"><a name="p8327172315586"></a><a name="p8327172315586"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="54.50000000000001%" headers="mcps1.1.5.1.4 "><p id="p183275239582"><a name="p183275239582"></a><a name="p183275239582"></a>commonInfo{</p>
    <p id="p1632712311585"><a name="p1632712311585"></a><a name="p1632712311585"></a>String sessionId; //若type为NAN，则设置为discoverDevByNAN 返回的sessionId ；否则设置为””。</p>
    <p id="p63271623145811"><a name="p63271623145811"></a><a name="p63271623145811"></a>}</p>
    </td>
    </tr>
    <tr id="row5327112315586"><td class="cellrowborder" valign="top" width="18.34%" headers="mcps1.1.5.1.1 "><p id="p8327112316582"><a name="p8327112316582"></a><a name="p8327112316582"></a>callbackFunc</p>
    </td>
    <td class="cellrowborder" valign="top" width="17.28%" headers="mcps1.1.5.1.2 "><p id="p4327132315816"><a name="p4327132315816"></a><a name="p4327132315816"></a>function</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.879999999999999%" headers="mcps1.1.5.1.3 "><p id="p16327192313589"><a name="p16327192313589"></a><a name="p16327192313589"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="54.50000000000001%" headers="mcps1.1.5.1.4 "><p id="p11327102385817"><a name="p11327102385817"></a><a name="p11327102385817"></a>回调函数，当收到该回调时表示设备与手机连接断开。</p>
    <p id="p13271123155817"><a name="p13271123155817"></a><a name="p13271123155817"></a>返回状态码：0。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   示例

    ```
    let commonInfo = {
    	sessionId: getApp(this).ConfigParams.deviceInfo.sessionId
    }
    getApp(this).NetConfig.registerDisconnectCallback(commonInfo, () => {
    	// registerDisconnectCallback 回调
    });
    ```


