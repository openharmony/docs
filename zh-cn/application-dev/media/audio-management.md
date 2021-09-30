# 音频管理开发指导<a name="ZH-CN_TOPIC_0000001147178551"></a>

-   [场景介绍](#section1269212236329)
-   [接口说明](#section5122103123215)
-   [开发步骤](#section1772415410138)

## 场景介绍<a name="section1269212236329"></a>

音频管理的主要工作是音量调节与音量查询，以及输入/输出设备查询。

## 接口说明<a name="section5122103123215"></a>

**表 1**  audio的相关接口

<a name="table14861021152915"></a>
<table><thead align="left"><tr id="row1586142112297"><th class="cellrowborder" valign="top" width="50%" id="mcps1.2.3.1.1"><p id="p12879217294"><a name="p12879217294"></a><a name="p12879217294"></a>接口名</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.2.3.1.2"><p id="p58716212291"><a name="p58716212291"></a><a name="p58716212291"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row188719211298"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p122859462311"><a name="p122859462311"></a><a name="p122859462311"></a>getAudioManager(): AudioManager</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p587321182911"><a name="p587321182911"></a><a name="p587321182911"></a>获得音频管理器。</p>
</td>
</tr>
<tr id="row118752119293"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p1387142192917"><a name="p1387142192917"></a><a name="p1387142192917"></a>AudioManager</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p78762192915"><a name="p78762192915"></a><a name="p78762192915"></a>音频管理器。具体参考表 音频管理相关的interface AudioManager。</p>
</td>
</tr>
<tr id="row3871321172918"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p118712212292"><a name="p118712212292"></a><a name="p118712212292"></a><a href="#table5223445184315">AudioDeviceDescriptor</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p987182116295"><a name="p987182116295"></a><a name="p987182116295"></a>描述音频设备。</p>
</td>
</tr>
<tr id="row1987172162912"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p1287132152919"><a name="p1287132152919"></a><a name="p1287132152919"></a><a href="#table48202011451">AudioVolumeType</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p1387221162913"><a name="p1387221162913"></a><a name="p1387221162913"></a>表示音频流类型的枚举。</p>
</td>
</tr>
<tr id="row487192117299"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p1287121122918"><a name="p1287121122918"></a><a name="p1287121122918"></a><a href="#table2959127489">DeviceFlag</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p787102117299"><a name="p787102117299"></a><a name="p787102117299"></a>表示可获取的设备种类的枚举。</p>
</td>
</tr>
<tr id="row171261911173510"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p1412691112350"><a name="p1412691112350"></a><a name="p1412691112350"></a><a href="#table41106159499">DeviceRole</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p012791116358"><a name="p012791116358"></a><a name="p012791116358"></a>表示设备角色的枚举。</p>
</td>
</tr>
<tr id="row6530511173512"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p9530181193513"><a name="p9530181193513"></a><a name="p9530181193513"></a><a href="#table1238810503496">DeviceType</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p7530191117353"><a name="p7530191117353"></a><a name="p7530191117353"></a>表示设备类型的枚举。</p>
</td>
</tr>
</tbody>
</table>

**表 2**  音频管理相关的interface  **AudioManager**

<a name="table5183104292517"></a>
<table><thead align="left"><tr id="row3183104212517"><th class="cellrowborder" valign="top" width="64.83%" id="mcps1.2.3.1.1"><p id="p950118362414"><a name="p950118362414"></a><a name="p950118362414"></a>接口名</p>
</th>
<th class="cellrowborder" valign="top" width="35.17%" id="mcps1.2.3.1.2"><p id="p125017361644"><a name="p125017361644"></a><a name="p125017361644"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row0634135815263"><td class="cellrowborder" valign="top" width="64.83%" headers="mcps1.2.3.1.1 "><p id="p102919146399"><a name="p102919146399"></a><a name="p102919146399"></a>setVolume(audioType: AudioVolumeType,volume: number,callback: AsyncCallback&lt;void&gt;): void</p>
</td>
<td class="cellrowborder" valign="top" width="35.17%" headers="mcps1.2.3.1.2 "><p id="p163555832612"><a name="p163555832612"></a><a name="p163555832612"></a>改变某个流的音量。</p>
</td>
</tr>
<tr id="row574419319279"><td class="cellrowborder" valign="top" width="64.83%" headers="mcps1.2.3.1.1 "><p id="p64791923153912"><a name="p64791923153912"></a><a name="p64791923153912"></a>setVolume(audioType: AudioVolumeType,volume: number): Promise&lt;void&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="35.17%" headers="mcps1.2.3.1.2 "><p id="p674443182715"><a name="p674443182715"></a><a name="p674443182715"></a>改变某个流的音量。</p>
</td>
</tr>
<tr id="row1348213114277"><td class="cellrowborder" valign="top" width="64.83%" headers="mcps1.2.3.1.1 "><p id="p1293542863917"><a name="p1293542863917"></a><a name="p1293542863917"></a>getVolume(audioType: AudioVolumeType, callback: AsyncCallback&lt;number&gt;): void</p>
</td>
<td class="cellrowborder" valign="top" width="35.17%" headers="mcps1.2.3.1.2 "><p id="p8482201142715"><a name="p8482201142715"></a><a name="p8482201142715"></a>获得某个流的音量。</p>
</td>
</tr>
<tr id="row872195279"><td class="cellrowborder" valign="top" width="64.83%" headers="mcps1.2.3.1.1 "><p id="p1124013343392"><a name="p1124013343392"></a><a name="p1124013343392"></a>getVolume(audioType: AudioVolumeType): Promise&lt;number&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="35.17%" headers="mcps1.2.3.1.2 "><p id="p1273493271"><a name="p1273493271"></a><a name="p1273493271"></a>获得某个流的音量。</p>
</td>
</tr>
<tr id="row3300184416273"><td class="cellrowborder" valign="top" width="64.83%" headers="mcps1.2.3.1.1 "><p id="p14484174015396"><a name="p14484174015396"></a><a name="p14484174015396"></a>getMinVolume(audioType: AudioVolumeType, callback: AsyncCallback&lt;number&gt;): void</p>
</td>
<td class="cellrowborder" valign="top" width="35.17%" headers="mcps1.2.3.1.2 "><p id="p130194472719"><a name="p130194472719"></a><a name="p130194472719"></a>获得某个流的最小音量。</p>
</td>
</tr>
<tr id="row747314483273"><td class="cellrowborder" valign="top" width="64.83%" headers="mcps1.2.3.1.1 "><p id="p88551509397"><a name="p88551509397"></a><a name="p88551509397"></a>getMinVolume(audioType: AudioVolumeType): Promise&lt;number&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="35.17%" headers="mcps1.2.3.1.2 "><p id="p1747464810273"><a name="p1747464810273"></a><a name="p1747464810273"></a>获得某个流的最小音量。</p>
</td>
</tr>
<tr id="row9417164614274"><td class="cellrowborder" valign="top" width="64.83%" headers="mcps1.2.3.1.1 "><p id="p147247575391"><a name="p147247575391"></a><a name="p147247575391"></a>getMaxVolume(audioType: AudioVolumeType, callback: AsyncCallback&lt;number&gt;): void</p>
</td>
<td class="cellrowborder" valign="top" width="35.17%" headers="mcps1.2.3.1.2 "><p id="p1441884632714"><a name="p1441884632714"></a><a name="p1441884632714"></a>获得某个流的最大音量。</p>
</td>
</tr>
<tr id="row199921350162711"><td class="cellrowborder" valign="top" width="64.83%" headers="mcps1.2.3.1.1 "><p id="p191994474013"><a name="p191994474013"></a><a name="p191994474013"></a>getMaxVolume(audioType: AudioVolumeType): Promise&lt;number&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="35.17%" headers="mcps1.2.3.1.2 "><p id="p1999235072718"><a name="p1999235072718"></a><a name="p1999235072718"></a>获得某个流的最大音量。</p>
</td>
</tr>
<tr id="row182815717273"><td class="cellrowborder" valign="top" width="64.83%" headers="mcps1.2.3.1.1 "><p id="p10833698408"><a name="p10833698408"></a><a name="p10833698408"></a>getDevices(deviceFlag: DeviceFlag, callback: AsyncCallback&lt;AudioDeviceDescriptors&gt;): void</p>
</td>
<td class="cellrowborder" valign="top" width="35.17%" headers="mcps1.2.3.1.2 "><p id="p112818572270"><a name="p112818572270"></a><a name="p112818572270"></a>获得设备列表。</p>
</td>
</tr>
<tr id="row1982485992714"><td class="cellrowborder" valign="top" width="64.83%" headers="mcps1.2.3.1.1 "><p id="p1242861714408"><a name="p1242861714408"></a><a name="p1242861714408"></a>getDevices(deviceFlag: DeviceFlag): Promise&lt;AudioDeviceDescriptors&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="35.17%" headers="mcps1.2.3.1.2 "><p id="p16825195911278"><a name="p16825195911278"></a><a name="p16825195911278"></a>获得设备列表。</p>
</td>
</tr>
</tbody>
</table>

**表 3**  表示音频设备的interface AudioDeviceDescriptor

<a name="table5223445184315"></a>
<table><thead align="left"><tr id="row72237455433"><th class="cellrowborder" valign="top" width="50%" id="mcps1.2.3.1.1"><p id="p82931051124313"><a name="p82931051124313"></a><a name="p82931051124313"></a>属性</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.2.3.1.2"><p id="p1229365113434"><a name="p1229365113434"></a><a name="p1229365113434"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row3223745114317"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p7416236174410"><a name="p7416236174410"></a><a name="p7416236174410"></a>deviceRole: DeviceRole</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p16223104511433"><a name="p16223104511433"></a><a name="p16223104511433"></a>设备角色。</p>
</td>
</tr>
<tr id="row6223194516430"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p622374516437"><a name="p622374516437"></a><a name="p622374516437"></a>deviceType: DeviceType</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p172237458430"><a name="p172237458430"></a><a name="p172237458430"></a>设备类型。</p>
</td>
</tr>
</tbody>
</table>

**表 4**  表示音频流类型的枚举AudioVolumeType

<a name="table48202011451"></a>
<table><thead align="left"><tr id="row7872094512"><th class="cellrowborder" valign="top" width="31.45%" id="mcps1.2.3.1.1"><p id="p3372527184510"><a name="p3372527184510"></a><a name="p3372527184510"></a>枚举值</p>
</th>
<th class="cellrowborder" valign="top" width="68.55%" id="mcps1.2.3.1.2"><p id="p1737222710450"><a name="p1737222710450"></a><a name="p1737222710450"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row188162012454"><td class="cellrowborder" valign="top" width="31.45%" headers="mcps1.2.3.1.1 "><p id="p764215288462"><a name="p764215288462"></a><a name="p764215288462"></a>MEDIA = 1</p>
</td>
<td class="cellrowborder" valign="top" width="68.55%" headers="mcps1.2.3.1.2 "><p id="p1596200459"><a name="p1596200459"></a><a name="p1596200459"></a>媒体声音。</p>
</td>
</tr>
<tr id="row1288915367468"><td class="cellrowborder" valign="top" width="31.45%" headers="mcps1.2.3.1.1 "><p id="p51611346194614"><a name="p51611346194614"></a><a name="p51611346194614"></a>RINGTONE = 2</p>
</td>
<td class="cellrowborder" valign="top" width="68.55%" headers="mcps1.2.3.1.2 "><p id="p9333131144712"><a name="p9333131144712"></a><a name="p9333131144712"></a>铃声。</p>
</td>
</tr>
</tbody>
</table>

**表 5**  表示可获取的设备种类的枚举DeviceFlag

<a name="table2959127489"></a>
<table><thead align="left"><tr id="row0959122483"><th class="cellrowborder" valign="top" width="31.56%" id="mcps1.2.3.1.1"><p id="p10301718485"><a name="p10301718485"></a><a name="p10301718485"></a>枚举值</p>
</th>
<th class="cellrowborder" valign="top" width="68.44%" id="mcps1.2.3.1.2"><p id="p8314178482"><a name="p8314178482"></a><a name="p8314178482"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row7967128484"><td class="cellrowborder" valign="top" width="31.56%" headers="mcps1.2.3.1.1 "><p id="p149631217480"><a name="p149631217480"></a><a name="p149631217480"></a>OUTPUT_DEVICES_FLAG = 1</p>
</td>
<td class="cellrowborder" valign="top" width="68.44%" headers="mcps1.2.3.1.2 "><p id="p119613126489"><a name="p119613126489"></a><a name="p119613126489"></a>输出设备。</p>
</td>
</tr>
<tr id="row169691220485"><td class="cellrowborder" valign="top" width="31.56%" headers="mcps1.2.3.1.1 "><p id="p1796201204814"><a name="p1796201204814"></a><a name="p1796201204814"></a>INPUT_DEVICES_FLAG = 2</p>
</td>
<td class="cellrowborder" valign="top" width="68.44%" headers="mcps1.2.3.1.2 "><p id="p796181254810"><a name="p796181254810"></a><a name="p796181254810"></a>输入设备。</p>
</td>
</tr>
<tr id="row1696812154817"><td class="cellrowborder" valign="top" width="31.56%" headers="mcps1.2.3.1.1 "><p id="p396191218482"><a name="p396191218482"></a><a name="p396191218482"></a>ALL_DEVICES_FLAG = 3</p>
</td>
<td class="cellrowborder" valign="top" width="68.44%" headers="mcps1.2.3.1.2 "><p id="p29612124485"><a name="p29612124485"></a><a name="p29612124485"></a>所有设备。</p>
</td>
</tr>
</tbody>
</table>

**表 6**  表示设备角色的枚举DeviceRole

<a name="table41106159499"></a>
<table><thead align="left"><tr id="row1811011515495"><th class="cellrowborder" valign="top" width="32.08%" id="mcps1.2.3.1.1"><p id="p2090221774914"><a name="p2090221774914"></a><a name="p2090221774914"></a>枚举值</p>
</th>
<th class="cellrowborder" valign="top" width="67.92%" id="mcps1.2.3.1.2"><p id="p99029172498"><a name="p99029172498"></a><a name="p99029172498"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row1611031534915"><td class="cellrowborder" valign="top" width="32.08%" headers="mcps1.2.3.1.1 "><p id="p711111150497"><a name="p711111150497"></a><a name="p711111150497"></a>INPUT_DEVICE = 1</p>
</td>
<td class="cellrowborder" valign="top" width="67.92%" headers="mcps1.2.3.1.2 "><p id="p81111715114914"><a name="p81111715114914"></a><a name="p81111715114914"></a>输入设备。</p>
</td>
</tr>
<tr id="row19111171574916"><td class="cellrowborder" valign="top" width="32.08%" headers="mcps1.2.3.1.1 "><p id="p111112153492"><a name="p111112153492"></a><a name="p111112153492"></a>OUTPUT_DEVICE = 2</p>
</td>
<td class="cellrowborder" valign="top" width="67.92%" headers="mcps1.2.3.1.2 "><p id="p9111141504916"><a name="p9111141504916"></a><a name="p9111141504916"></a>输出设备。</p>
</td>
</tr>
</tbody>
</table>

**表 7**  表示设备类型的枚举DeviceType

<a name="table1238810503496"></a>
<table><thead align="left"><tr id="row1738810504498"><th class="cellrowborder" valign="top" width="32.17%" id="mcps1.2.3.1.1"><p id="p973775318495"><a name="p973775318495"></a><a name="p973775318495"></a>枚举值</p>
</th>
<th class="cellrowborder" valign="top" width="67.83%" id="mcps1.2.3.1.2"><p id="p17737253174912"><a name="p17737253174912"></a><a name="p17737253174912"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row2388155012491"><td class="cellrowborder" valign="top" width="32.17%" headers="mcps1.2.3.1.1 "><p id="p2038925064917"><a name="p2038925064917"></a><a name="p2038925064917"></a>INVALID = 0</p>
</td>
<td class="cellrowborder" valign="top" width="67.83%" headers="mcps1.2.3.1.2 "><p id="p17389145016497"><a name="p17389145016497"></a><a name="p17389145016497"></a>无效。</p>
</td>
</tr>
<tr id="row938915016493"><td class="cellrowborder" valign="top" width="32.17%" headers="mcps1.2.3.1.1 "><p id="p538925044916"><a name="p538925044916"></a><a name="p538925044916"></a>SPEAKER = 1</p>
</td>
<td class="cellrowborder" valign="top" width="67.83%" headers="mcps1.2.3.1.2 "><p id="p16724165865017"><a name="p16724165865017"></a><a name="p16724165865017"></a>扬声器。</p>
</td>
</tr>
<tr id="row12389105084916"><td class="cellrowborder" valign="top" width="32.17%" headers="mcps1.2.3.1.1 "><p id="p538914502497"><a name="p538914502497"></a><a name="p538914502497"></a>WIRED_HEADSET = 2</p>
</td>
<td class="cellrowborder" valign="top" width="67.83%" headers="mcps1.2.3.1.2 "><p id="p63891850144911"><a name="p63891850144911"></a><a name="p63891850144911"></a>有线耳机。</p>
</td>
</tr>
<tr id="row2389205074915"><td class="cellrowborder" valign="top" width="32.17%" headers="mcps1.2.3.1.1 "><p id="p10389175054919"><a name="p10389175054919"></a><a name="p10389175054919"></a>BLUETOOTH_SCO = 3</p>
</td>
<td class="cellrowborder" valign="top" width="67.83%" headers="mcps1.2.3.1.2 "><p id="p538905016496"><a name="p538905016496"></a><a name="p538905016496"></a>蓝牙设备。</p>
</td>
</tr>
<tr id="row83891502499"><td class="cellrowborder" valign="top" width="32.17%" headers="mcps1.2.3.1.1 "><p id="p1938975015494"><a name="p1938975015494"></a><a name="p1938975015494"></a>BLUETOOTH_A2DP = 4</p>
</td>
<td class="cellrowborder" valign="top" width="67.83%" headers="mcps1.2.3.1.2 "><p id="p193891550134912"><a name="p193891550134912"></a><a name="p193891550134912"></a>支持A2DP的蓝牙设备。</p>
</td>
</tr>
<tr id="row11389175014916"><td class="cellrowborder" valign="top" width="32.17%" headers="mcps1.2.3.1.1 "><p id="p1738955018497"><a name="p1738955018497"></a><a name="p1738955018497"></a>MIC = 5</p>
</td>
<td class="cellrowborder" valign="top" width="67.83%" headers="mcps1.2.3.1.2 "><p id="p73891250174914"><a name="p73891250174914"></a><a name="p73891250174914"></a>麦克风。</p>
</td>
</tr>
</tbody>
</table>

## 开发步骤<a name="section1772415410138"></a>

1.  获取音频控制器。

    ```
    const audioManager = audio.getAudioManager();
    ```

2.  改变媒体流的声音。

    ```
    audioManager.getVolume(audio.AudioVolumeType.MEDIA, (err, value) => {
       if (err) {
    	   console.error(`failed to get volume ${err.message}`);
    	   return;
       }
       console.log(`Media getVolume  ${value}`);
    });
    ```


