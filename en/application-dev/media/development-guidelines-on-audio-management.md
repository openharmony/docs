# Development Guidelines on Audio Management<a name="EN-US_TOPIC_0000001147178551"></a>

-   [When to Use](#section1269212236329)
-   [Available APIs](#section5122103123215)
-   [Development Procedure](#section1772415410138)

## When to Use<a name="section1269212236329"></a>

You use audio management APIs to set and obtain volume, and get information about input/output devices.

## Available APIs<a name="section5122103123215"></a>

**Table  1**  Audio

<a name="table14861021152915"></a>
<table><thead align="left"><tr id="row1586142112297"><th class="cellrowborder" valign="top" width="50%" id="mcps1.2.3.1.1"><p id="p12879217294"><a name="p12879217294"></a><a name="p12879217294"></a>API</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.2.3.1.2"><p id="p58716212291"><a name="p58716212291"></a><a name="p58716212291"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row188719211298"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p122859462311"><a name="p122859462311"></a><a name="p122859462311"></a>getAudioManager(): AudioManager</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p587321182911"><a name="p587321182911"></a><a name="p587321182911"></a>Obtains an <strong id="b6542415195"><a name="b6542415195"></a><a name="b6542415195"></a>AudioManager</strong> instance.</p>
</td>
</tr>
<tr id="row118752119293"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p1387142192917"><a name="p1387142192917"></a><a name="p1387142192917"></a><a href="#table5183104292517">AudioManager</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p78762192915"><a name="p78762192915"></a><a name="p78762192915"></a>Manages audio volume and audio device information.</p>
</td>
</tr>
<tr id="row3871321172918"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p118712212292"><a name="p118712212292"></a><a name="p118712212292"></a><a href="#table5223445184315">AudioDeviceDescriptor</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p987182116295"><a name="p987182116295"></a><a name="p987182116295"></a>Describes audio devices.</p>
</td>
</tr>
<tr id="row1987172162912"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p1287132152919"><a name="p1287132152919"></a><a name="p1287132152919"></a><a href="#table48202011451">AudioVolumeType</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p1387221162913"><a name="p1387221162913"></a><a name="p1387221162913"></a>Enumerates audio volume types.</p>
</td>
</tr>
<tr id="row487192117299"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p1287121122918"><a name="p1287121122918"></a><a name="p1287121122918"></a><a href="#table2959127489">DeviceFlag</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p787102117299"><a name="p787102117299"></a><a name="p787102117299"></a>Enumerates flags of supported devices.</p>
</td>
</tr>
<tr id="row171261911173510"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p1412691112350"><a name="p1412691112350"></a><a name="p1412691112350"></a><a href="#table41106159499">DeviceRole</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p012791116358"><a name="p012791116358"></a><a name="p012791116358"></a>Enumerates device roles.</p>
</td>
</tr>
<tr id="row6530511173512"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p9530181193513"><a name="p9530181193513"></a><a name="p9530181193513"></a><a href="#table1238810503496">DeviceType</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p7530191117353"><a name="p7530191117353"></a><a name="p7530191117353"></a>Enumerates device types.</p>
</td>
</tr>
</tbody>
</table>

**Table  2**  AudioManager methods

<a name="table5183104292517"></a>
<table><thead align="left"><tr id="row3183104212517"><th class="cellrowborder" valign="top" width="64.83%" id="mcps1.2.3.1.1"><p id="p950118362414"><a name="p950118362414"></a><a name="p950118362414"></a>Method</p>
</th>
<th class="cellrowborder" valign="top" width="35.17%" id="mcps1.2.3.1.2"><p id="p125017361644"><a name="p125017361644"></a><a name="p125017361644"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row0634135815263"><td class="cellrowborder" valign="top" width="64.83%" headers="mcps1.2.3.1.1 "><p id="p102919146399"><a name="p102919146399"></a><a name="p102919146399"></a>setVolume(audioType: AudioVolumeType,volume: number,callback: AsyncCallback&lt;void&gt;): void</p>
</td>
<td class="cellrowborder" valign="top" width="35.17%" headers="mcps1.2.3.1.2 "><p id="p163555832612"><a name="p163555832612"></a><a name="p163555832612"></a>Sets the volume of a stream asynchronously and uses a callback to return the execution result.</p>
</td>
</tr>
<tr id="row574419319279"><td class="cellrowborder" valign="top" width="64.83%" headers="mcps1.2.3.1.1 "><p id="p64791923153912"><a name="p64791923153912"></a><a name="p64791923153912"></a>setVolume(audioType: AudioVolumeType,volume: number): Promise&lt;void&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="35.17%" headers="mcps1.2.3.1.2 "><p id="p674443182715"><a name="p674443182715"></a><a name="p674443182715"></a>Sets the volume of a stream asynchronously and uses a Promise to return the execution result.</p>
</td>
</tr>
<tr id="row1348213114277"><td class="cellrowborder" valign="top" width="64.83%" headers="mcps1.2.3.1.1 "><p id="p1293542863917"><a name="p1293542863917"></a><a name="p1293542863917"></a>getVolume(audioType: AudioVolumeType, callback: AsyncCallback&lt;number&gt;): void</p>
</td>
<td class="cellrowborder" valign="top" width="35.17%" headers="mcps1.2.3.1.2 "><p id="p8482201142715"><a name="p8482201142715"></a><a name="p8482201142715"></a>Obtains the volume of a stream asynchronously and uses a callback to return the execution result.</p>
</td>
</tr>
<tr id="row872195279"><td class="cellrowborder" valign="top" width="64.83%" headers="mcps1.2.3.1.1 "><p id="p1124013343392"><a name="p1124013343392"></a><a name="p1124013343392"></a>getVolume(audioType: AudioVolumeType): Promise&lt;number&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="35.17%" headers="mcps1.2.3.1.2 "><p id="p1273493271"><a name="p1273493271"></a><a name="p1273493271"></a>Obtains the volume of a stream asynchronously and uses a Promise to return the execution result.</p>
</td>
</tr>
<tr id="row3300184416273"><td class="cellrowborder" valign="top" width="64.83%" headers="mcps1.2.3.1.1 "><p id="p14484174015396"><a name="p14484174015396"></a><a name="p14484174015396"></a>getMinVolume(audioType: AudioVolumeType, callback: AsyncCallback&lt;number&gt;): void</p>
</td>
<td class="cellrowborder" valign="top" width="35.17%" headers="mcps1.2.3.1.2 "><p id="p130194472719"><a name="p130194472719"></a><a name="p130194472719"></a>Obtains the minimum volume of a stream asynchronously and uses a callback to return the execution result.</p>
</td>
</tr>
<tr id="row747314483273"><td class="cellrowborder" valign="top" width="64.83%" headers="mcps1.2.3.1.1 "><p id="p88551509397"><a name="p88551509397"></a><a name="p88551509397"></a>getMinVolume(audioType: AudioVolumeType): Promise&lt;number&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="35.17%" headers="mcps1.2.3.1.2 "><p id="p1747464810273"><a name="p1747464810273"></a><a name="p1747464810273"></a>Obtains the minimum volume of a stream asynchronously and uses a Promise to return the execution result.</p>
</td>
</tr>
<tr id="row9417164614274"><td class="cellrowborder" valign="top" width="64.83%" headers="mcps1.2.3.1.1 "><p id="p147247575391"><a name="p147247575391"></a><a name="p147247575391"></a>getMaxVolume(audioType: AudioVolumeType, callback: AsyncCallback&lt;number&gt;): void</p>
</td>
<td class="cellrowborder" valign="top" width="35.17%" headers="mcps1.2.3.1.2 "><p id="p1441884632714"><a name="p1441884632714"></a><a name="p1441884632714"></a>Obtains the maximum volume of a stream asynchronously and uses a callback to return the execution result.</p>
</td>
</tr>
<tr id="row199921350162711"><td class="cellrowborder" valign="top" width="64.83%" headers="mcps1.2.3.1.1 "><p id="p191994474013"><a name="p191994474013"></a><a name="p191994474013"></a>getMaxVolume(audioType: AudioVolumeType): Promise&lt;number&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="35.17%" headers="mcps1.2.3.1.2 "><p id="p1999235072718"><a name="p1999235072718"></a><a name="p1999235072718"></a>Obtains the maximum volume of a stream asynchronously and uses a Promise to return the execution result.</p>
</td>
</tr>
<tr id="row182815717273"><td class="cellrowborder" valign="top" width="64.83%" headers="mcps1.2.3.1.1 "><p id="p10833698408"><a name="p10833698408"></a><a name="p10833698408"></a>getDevices(deviceFlag: DeviceFlag, callback: AsyncCallback&lt;AudioDeviceDescriptors&gt;): void</p>
</td>
<td class="cellrowborder" valign="top" width="35.17%" headers="mcps1.2.3.1.2 "><p id="p112818572270"><a name="p112818572270"></a><a name="p112818572270"></a>Obtains the device list asynchronously and uses a callback to return the execution result.</p>
</td>
</tr>
<tr id="row1982485992714"><td class="cellrowborder" valign="top" width="64.83%" headers="mcps1.2.3.1.1 "><p id="p1242861714408"><a name="p1242861714408"></a><a name="p1242861714408"></a>getDevices(deviceFlag: DeviceFlag): Promise&lt;AudioDeviceDescriptors&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="35.17%" headers="mcps1.2.3.1.2 "><p id="p16825195911278"><a name="p16825195911278"></a><a name="p16825195911278"></a>Obtains the device list asynchronously and uses a Promise to return the execution result.</p>
</td>
</tr>
</tbody>
</table>

**Table  3**  AudioDeviceDescriptor attributes

<a name="table5223445184315"></a>
<table><thead align="left"><tr id="row72237455433"><th class="cellrowborder" valign="top" width="50%" id="mcps1.2.3.1.1"><p id="p82931051124313"><a name="p82931051124313"></a><a name="p82931051124313"></a>Parameter</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.2.3.1.2"><p id="p1229365113434"><a name="p1229365113434"></a><a name="p1229365113434"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row3223745114317"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p7416236174410"><a name="p7416236174410"></a><a name="p7416236174410"></a>deviceRole: DeviceRole</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p16223104511433"><a name="p16223104511433"></a><a name="p16223104511433"></a>Audio device role</p>
</td>
</tr>
<tr id="row6223194516430"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p622374516437"><a name="p622374516437"></a><a name="p622374516437"></a>deviceType: DeviceType</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p172237458430"><a name="p172237458430"></a><a name="p172237458430"></a>Audio device type</p>
</td>
</tr>
</tbody>
</table>

**Table  4**  AudioVolumeType enums 

<a name="table48202011451"></a>
<table><thead align="left"><tr id="row7872094512"><th class="cellrowborder" valign="top" width="50%" id="mcps1.2.3.1.1"><p id="p3372527184510"><a name="p3372527184510"></a><a name="p3372527184510"></a>Enum</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.2.3.1.2"><p id="p1737222710450"><a name="p1737222710450"></a><a name="p1737222710450"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row188162012454"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p764215288462"><a name="p764215288462"></a><a name="p764215288462"></a>MEDIA = 1</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p1596200459"><a name="p1596200459"></a><a name="p1596200459"></a>Audio streams for media purpose</p>
</td>
</tr>
<tr id="row1288915367468"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p51611346194614"><a name="p51611346194614"></a><a name="p51611346194614"></a>RINGTONE = 2</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p9333131144712"><a name="p9333131144712"></a><a name="p9333131144712"></a>Audio streams for ring tones</p>
</td>
</tr>
</tbody>
</table>

**Table  5**  DeviceFlag enums

<a name="table2959127489"></a>
<table><thead align="left"><tr id="row0959122483"><th class="cellrowborder" valign="top" width="50%" id="mcps1.2.3.1.1"><p id="p10301718485"><a name="p10301718485"></a><a name="p10301718485"></a>Enum</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.2.3.1.2"><p id="p8314178482"><a name="p8314178482"></a><a name="p8314178482"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row7967128484"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p149631217480"><a name="p149631217480"></a><a name="p149631217480"></a>OUTPUT_DEVICES_FLAG = 1</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p119613126489"><a name="p119613126489"></a><a name="p119613126489"></a>Output devices</p>
</td>
</tr>
<tr id="row169691220485"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p1796201204814"><a name="p1796201204814"></a><a name="p1796201204814"></a>INPUT_DEVICES_FLAG = 2</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p796181254810"><a name="p796181254810"></a><a name="p796181254810"></a>Input devices</p>
</td>
</tr>
<tr id="row1696812154817"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p396191218482"><a name="p396191218482"></a><a name="p396191218482"></a>ALL_DEVICES_FLAG = 3</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p29612124485"><a name="p29612124485"></a><a name="p29612124485"></a>All devices</p>
</td>
</tr>
</tbody>
</table>

**Table  6**  DeviceRole enums

<a name="table41106159499"></a>
<table><thead align="left"><tr id="row1811011515495"><th class="cellrowborder" valign="top" width="50%" id="mcps1.2.3.1.1"><p id="p2090221774914"><a name="p2090221774914"></a><a name="p2090221774914"></a>Enum</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.2.3.1.2"><p id="p99029172498"><a name="p99029172498"></a><a name="p99029172498"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1611031534915"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p711111150497"><a name="p711111150497"></a><a name="p711111150497"></a>INPUT_DEVICE = 1</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p81111715114914"><a name="p81111715114914"></a><a name="p81111715114914"></a>Input role</p>
</td>
</tr>
<tr id="row19111171574916"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p111112153492"><a name="p111112153492"></a><a name="p111112153492"></a>OUTPUT_DEVICE = 2</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p9111141504916"><a name="p9111141504916"></a><a name="p9111141504916"></a>Output role</p>
</td>
</tr>
</tbody>
</table>

**Table  7**  DeviceType enums

<a name="table1238810503496"></a>
<table><thead align="left"><tr id="row1738810504498"><th class="cellrowborder" valign="top" width="50%" id="mcps1.2.3.1.1"><p id="p973775318495"><a name="p973775318495"></a><a name="p973775318495"></a>Enum</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.2.3.1.2"><p id="p17737253174912"><a name="p17737253174912"></a><a name="p17737253174912"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row2388155012491"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p2038925064917"><a name="p2038925064917"></a><a name="p2038925064917"></a>INVALID = 0</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p17389145016497"><a name="p17389145016497"></a><a name="p17389145016497"></a>Invalid device</p>
</td>
</tr>
<tr id="row938915016493"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p538925044916"><a name="p538925044916"></a><a name="p538925044916"></a>SPEAKER = 1</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p16724165865017"><a name="p16724165865017"></a><a name="p16724165865017"></a>Speaker</p>
</td>
</tr>
<tr id="row12389105084916"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p538914502497"><a name="p538914502497"></a><a name="p538914502497"></a>WIRED_HEADSET = 2</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p63891850144911"><a name="p63891850144911"></a><a name="p63891850144911"></a>Wired headset</p>
</td>
</tr>
<tr id="row2389205074915"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p10389175054919"><a name="p10389175054919"></a><a name="p10389175054919"></a>BLUETOOTH_SCO = 3</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p538905016496"><a name="p538905016496"></a><a name="p538905016496"></a>Bluetooth device using the synchronous connection oriented link (SCO)</p>
</td>
</tr>
<tr id="row83891502499"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p1938975015494"><a name="p1938975015494"></a><a name="p1938975015494"></a>BLUETOOTH_A2DP = 4</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p193891550134912"><a name="p193891550134912"></a><a name="p193891550134912"></a>Bluetooth device using advanced audio distribution profile (A2DP)</p>
</td>
</tr>
<tr id="row11389175014916"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p1738955018497"><a name="p1738955018497"></a><a name="p1738955018497"></a>MIC = 5</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p73891250174914"><a name="p73891250174914"></a><a name="p73891250174914"></a>Microphone</p>
</td>
</tr>
</tbody>
</table>

## Development Procedure<a name="section1772415410138"></a>

1.  Obtain an audio manager.

    ```
    const audioManager = audio.getAudioManager();
    ```

2.  Set the audio stream volume.

    ```
    audioManager.getVolume(audio.AudioVolumeType.MEDIA, (err, value) => {
       if (err) {
    	   console.error(`failed to get volume ${err.message}`);
    	   return;
       }
       console.log(`Media getVolume  ${value}`);
    });
    ```


