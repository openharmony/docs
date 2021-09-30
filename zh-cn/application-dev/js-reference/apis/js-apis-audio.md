# 音频管理<a name="ZH-CN_TOPIC_0000001149807881"></a>

-   [导入模块](#s56d19203690d4782bfc74069abb6bd71)
-   [权限](#section11257113618419)
-   [getAudioManager\(\): AudioManager](#section84581011418)
-   [AudioVolumeType](#section92261857172218)
-   [DeviceFlag](#section11285183164210)
-   [DeviceRole](#section380038142619)
-   [DeviceType](#devicetype)
  - [ActiveDeviceType7+](#activedevicetype)
-   [AudioRingMode7+](#section14948916131018)
-   [AudioManager](#section8265143814015)
    -   [setVolume\(volumeType: AudioVolumeType, volume: number, callback: AsyncCallback<void\>\): void](#section189141826104616)
    -   [setVolume\(volumeType: AudioVolumeType, volume: number\): Promise<void\>](#section102021249114612)
    -   [getVolume\(volumeType: AudioVolumeType, callback: AsyncCallback<number\>\): void](#section4387320194714)
    -   [getVolume\(volumeType: AudioVolumeType\): Promise<number\>](#section04121965119)
    -   [getMinVolume\(volumeType: AudioVolumeType, callback: AsyncCallback<number\>\): void](#section188714283511)
    -   [getMinVolume\(volumeType: AudioVolumeType\): Promise<number\>](#section41556389511)
    -   [getMaxVolume\(volumeType: AudioVolumeType, callback: AsyncCallback<number\>\): void](#section690395418516)
    -   [getMaxVolume\(volumeType: AudioVolumeType\): Promise<number\>](#section155151345217)
    -   [mute\(volumeType: AudioVolumeType, mute: boolean, callback: AsyncCallback<void\>\): void7+](#section13516136134613)
    -   [mute\(volumeType: AudioVolumeType, mute: boolean\): Promise<void\>7+](#section7519036144616)
    -   [isMute\(volumeType: AudioVolumeType, callback: AsyncCallback<boolean\>\): void7+](#section10684183819585)
    -   [isMute\(volumeType: AudioVolumeType\): Promise<boolean\>7+](#section6920211145610)
    -   [isActive\(volumeType: AudioVolumeType, callback: AsyncCallback<boolean\>\): void7+](#section380012544121)
    -   [isActive\(volumeType: AudioVolumeType\): Promise<boolean\>7+](#section1880315481216)
    -   [setRingerMode\(mode: AudioRingMode, callback: AsyncCallback<void\>\): void7+](#section18572131483613)
    -   [setRingerMode\(mode: AudioRingMode\): Promise<void\>7+](#section55741914143615)
    -   [getRingerMode\(callback: AsyncCallback<AudioRingMode\>\): void7+](#section149044108162)
    -   [getRingerMode\(\): Promise<AudioRingMode\>7+](#section13908210101620)
    -   [setAudioParameter\(key: string, value: string, callback: AsyncCallback<void\>\): void7+](#section1691957174818)
    -   [setAudioParameter\(key: string, value: string\): Promise<void\>7+](#section18121057174820)
    -   [getAudioParameter\(key: string, callback: AsyncCallback<string\>\): void7+](#section1415145714812)
    -   [getAudioParameter\(key: string\): Promise<string\>7+](#section3185577485)
    -   [getDevices\(deviceFlag: DeviceFlag, callback: AsyncCallback<AudioDeviceDescriptors\>\): void](#section11536182020523)
    -   [getDevices\(deviceFlag: DeviceFlag\): Promise<AudioDeviceDescriptors\>](#section181733125210)
    -   [setDeviceActive\(deviceType: ActiveDeviceType, active: boolean, callback: AsyncCallback<void\>\): void7+](#section103558400222)
    -   [setDeviceActive\(deviceType: ActiveDeviceType, active: boolean\): Promise<void\>7+](#section1235914401228)
    -   [isDeviceActive\(deviceType: ActiveDeviceType, callback: AsyncCallback<boolean\>\): void7+](#section12363240122219)
    -   [isDeviceActive\(deviceType: ActiveDeviceType\): Promise<boolean\>7+](#section18366184012213)
    -   [setMicrophoneMute\(mute: boolean, callback: AsyncCallback<void\>\): void7+](#section14703163618122)
    -   [setMicrophoneMute\(mute: boolean\): Promise<void\>7+](#section56287111791)
    -   [isMicrophoneMute\(callback: AsyncCallback<boolean\>\): void7+](#section6632141119912)
    -   [isMicrophoneMute\(\): Promise<boolean\>7+](#section196363111918)

-   [AudioDeviceDescriptor](#section164657411927)
    -   [属性](#section4947115405)

-   [AudioDeviceDescriptors](#section5181155710523)

## 导入模块<a name="s56d19203690d4782bfc74069abb6bd71"></a>

```
import audio from '@ohos.multimedia.audio';
```

## 权限<a name="section11257113618419"></a>

无

## getAudioManager\(\): AudioManager<a name="section84581011418"></a>

获取音频管理器。

**返回值：**

<a name="table16391145317913"></a>
<table><thead align="left"><tr id="row2391145319910"><th class="cellrowborder" valign="top" width="17.01%" id="mcps1.1.3.1.1"><p id="p13911353991"><a name="p13911353991"></a><a name="p13911353991"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="82.99%" id="mcps1.1.3.1.2"><p id="p193911531395"><a name="p193911531395"></a><a name="p193911531395"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="row1339114531391"><td class="cellrowborder" valign="top" width="17.01%" headers="mcps1.1.3.1.1 "><p id="p1338931454713"><a name="p1338931454713"></a><a name="p1338931454713"></a><a href="#section8265143814015">AudioManager</a></p>
</td>
<td class="cellrowborder" valign="top" width="82.99%" headers="mcps1.1.3.1.2 "><p id="p1039217531898"><a name="p1039217531898"></a><a name="p1039217531898"></a>音频管理类。</p>
</td>
</tr>
</tbody>
</table>

**示例：**

```
var audioManager = audio.getAudioManager();
```

## AudioVolumeType<a name="section92261857172218"></a>

枚举，音频流类型。

<a name="table689215633911"></a>
<table><thead align="left"><tr id="row19892165613399"><th class="cellrowborder" valign="top" width="30.380000000000003%" id="mcps1.1.4.1.1"><p id="p148924564394"><a name="p148924564394"></a><a name="p148924564394"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="9.950000000000001%" id="mcps1.1.4.1.2"><p id="aace9cae4ba0d4939bfa048460f61c3c7"><a name="aace9cae4ba0d4939bfa048460f61c3c7"></a><a name="aace9cae4ba0d4939bfa048460f61c3c7"></a>默认值</p>
</th>
<th class="cellrowborder" valign="top" width="59.67%" id="mcps1.1.4.1.3"><p id="p19892145616392"><a name="p19892145616392"></a><a name="p19892145616392"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row1389215612395"><td class="cellrowborder" valign="top" width="30.380000000000003%" headers="mcps1.1.4.1.1 "><p id="p52851329122117"><a name="p52851329122117"></a><a name="p52851329122117"></a>RINGTONE</p>
</td>
<td class="cellrowborder" valign="top" width="9.950000000000001%" headers="mcps1.1.4.1.2 "><p id="p2282152962115"><a name="p2282152962115"></a><a name="p2282152962115"></a>2</p>
</td>
<td class="cellrowborder" valign="top" width="59.67%" headers="mcps1.1.4.1.3 "><p id="p328012293211"><a name="p328012293211"></a><a name="p328012293211"></a>表示铃声。</p>
</td>
</tr>
<tr id="row6892145616397"><td class="cellrowborder" valign="top" width="30.380000000000003%" headers="mcps1.1.4.1.1 "><p id="p027662952110"><a name="p027662952110"></a><a name="p027662952110"></a>MEDIA</p>
</td>
<td class="cellrowborder" valign="top" width="9.950000000000001%" headers="mcps1.1.4.1.2 "><p id="p17273229192113"><a name="p17273229192113"></a><a name="p17273229192113"></a>3</p>
</td>
<td class="cellrowborder" valign="top" width="59.67%" headers="mcps1.1.4.1.3 "><p id="p182452299212"><a name="p182452299212"></a><a name="p182452299212"></a>表示媒体。</p>
</td>
</tr>
</tbody>
</table>

## DeviceFlag<a name="section11285183164210"></a>

枚举，可获取的设备种类。

<a name="table162856320422"></a>
<table><thead align="left"><tr id="row928593124213"><th class="cellrowborder" valign="top" width="30.380000000000003%" id="mcps1.1.4.1.1"><p id="p628553124216"><a name="p628553124216"></a><a name="p628553124216"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="9.950000000000001%" id="mcps1.1.4.1.2"><p id="p1828512314213"><a name="p1828512314213"></a><a name="p1828512314213"></a>默认值</p>
</th>
<th class="cellrowborder" valign="top" width="59.67%" id="mcps1.1.4.1.3"><p id="p1228612334216"><a name="p1228612334216"></a><a name="p1228612334216"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row2286435427"><td class="cellrowborder" valign="top" width="30.380000000000003%" headers="mcps1.1.4.1.1 "><p id="p19184101242511"><a name="p19184101242511"></a><a name="p19184101242511"></a>OUTPUT_DEVICES_FLAG</p>
</td>
<td class="cellrowborder" valign="top" width="9.950000000000001%" headers="mcps1.1.4.1.2 "><p id="p172861314213"><a name="p172861314213"></a><a name="p172861314213"></a>1</p>
</td>
<td class="cellrowborder" valign="top" width="59.67%" headers="mcps1.1.4.1.3 "><p id="p5286133134212"><a name="p5286133134212"></a><a name="p5286133134212"></a>表示输出设备种类。</p>
</td>
</tr>
<tr id="row2286163194220"><td class="cellrowborder" valign="top" width="30.380000000000003%" headers="mcps1.1.4.1.1 "><p id="p5514162412251"><a name="p5514162412251"></a><a name="p5514162412251"></a>INPUT_DEVICES_FLAG</p>
</td>
<td class="cellrowborder" valign="top" width="9.950000000000001%" headers="mcps1.1.4.1.2 "><p id="p112863354219"><a name="p112863354219"></a><a name="p112863354219"></a>2</p>
</td>
<td class="cellrowborder" valign="top" width="59.67%" headers="mcps1.1.4.1.3 "><p id="p1328617334214"><a name="p1328617334214"></a><a name="p1328617334214"></a>表示输入设备种类。</p>
</td>
</tr>
<tr id="row10631228192520"><td class="cellrowborder" valign="top" width="30.380000000000003%" headers="mcps1.1.4.1.1 "><p id="p1731716317259"><a name="p1731716317259"></a><a name="p1731716317259"></a>ALL_DEVICES_FLAG</p>
</td>
<td class="cellrowborder" valign="top" width="9.950000000000001%" headers="mcps1.1.4.1.2 "><p id="p1364628102517"><a name="p1364628102517"></a><a name="p1364628102517"></a>3</p>
</td>
<td class="cellrowborder" valign="top" width="59.67%" headers="mcps1.1.4.1.3 "><p id="p1864182814256"><a name="p1864182814256"></a><a name="p1864182814256"></a>表示所有设备种类。</p>
</td>
</tr>
</tbody>
</table>

## DeviceRole<a name="section380038142619"></a>

枚举，设备角色。

<a name="table48001786268"></a>
<table><thead align="left"><tr id="row138007814267"><th class="cellrowborder" valign="top" width="30.380000000000003%" id="mcps1.1.4.1.1"><p id="p1980068112616"><a name="p1980068112616"></a><a name="p1980068112616"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="9.950000000000001%" id="mcps1.1.4.1.2"><p id="p28003819263"><a name="p28003819263"></a><a name="p28003819263"></a>默认值</p>
</th>
<th class="cellrowborder" valign="top" width="59.67%" id="mcps1.1.4.1.3"><p id="p3800118112615"><a name="p3800118112615"></a><a name="p3800118112615"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row98008816264"><td class="cellrowborder" valign="top" width="30.380000000000003%" headers="mcps1.1.4.1.1 "><p id="p1542334211265"><a name="p1542334211265"></a><a name="p1542334211265"></a>INPUT_DEVICE</p>
</td>
<td class="cellrowborder" valign="top" width="9.950000000000001%" headers="mcps1.1.4.1.2 "><p id="p98008852610"><a name="p98008852610"></a><a name="p98008852610"></a>1</p>
</td>
<td class="cellrowborder" valign="top" width="59.67%" headers="mcps1.1.4.1.3 "><p id="p118009817260"><a name="p118009817260"></a><a name="p118009817260"></a>输入设备角色。</p>
</td>
</tr>
<tr id="row680018802618"><td class="cellrowborder" valign="top" width="30.380000000000003%" headers="mcps1.1.4.1.1 "><p id="p2011710479267"><a name="p2011710479267"></a><a name="p2011710479267"></a>OUTPUT_DEVICE</p>
</td>
<td class="cellrowborder" valign="top" width="9.950000000000001%" headers="mcps1.1.4.1.2 "><p id="p08009812613"><a name="p08009812613"></a><a name="p08009812613"></a>2</p>
</td>
<td class="cellrowborder" valign="top" width="59.67%" headers="mcps1.1.4.1.3 "><p id="p380020842611"><a name="p380020842611"></a><a name="p380020842611"></a>输出设备角色。</p>
</td>
</tr>
</tbody>
</table>

## DeviceType<a name="devicetype"></a>

枚举，设备类型。

| 名称           | 默认值        | 描述                                                    |
| -------------- | ------------- | ------------------------------------------------------- |
| INVALID        | 0             | 无效设备。                                              |
| EARPIECE       | 1             | 听筒。                                                  |
| SPEAKER        | 2             | 扬声器。                                                |
| WIRED_HEADSET  | 3             | 有线耳机。                                              |
| BLUETOOTH_SCO  | 7             | 蓝牙设备SCO连接(Synchronous Connection Oriented)。      |
| BLUETOOTH_A2DP | 8             | 蓝牙设备A2DP连接(Advanced Audio Distribution Profile)。 |
| MIC            | 15            | 麦克风。                                                |


## ActiveDeviceType<sup>7+</sup><a name="activedevicetype"></a>

Enumerates active device types.

| 名称          | 默认值        | 描述                                                     |
| ------------- | ------------- | -------------------------------------------------------- |
| SPEAKER       | 2             | 扬声器。                                                 |
| BLUETOOTH_SCO | 7             | 蓝牙设备SCO连接(Synchronous Connection Oriented)。       |

## AudioRingMode<sup>7+</sup><a name="section14948916131018"></a>

枚举，铃声模式。

<a name="table794961616108"></a>
<table><thead align="left"><tr id="row189491616171016"><th class="cellrowborder" valign="top" width="30.380000000000003%" id="mcps1.1.4.1.1"><p id="p15949151616106"><a name="p15949151616106"></a><a name="p15949151616106"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="9.950000000000001%" id="mcps1.1.4.1.2"><p id="p15949416141012"><a name="p15949416141012"></a><a name="p15949416141012"></a>默认值</p>
</th>
<th class="cellrowborder" valign="top" width="59.67%" id="mcps1.1.4.1.3"><p id="p15949216151020"><a name="p15949216151020"></a><a name="p15949216151020"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row1094911651010"><td class="cellrowborder" valign="top" width="30.380000000000003%" headers="mcps1.1.4.1.1 "><p id="p12788943145414"><a name="p12788943145414"></a><a name="p12788943145414"></a>RINGER_MODE_SILENT</p>
</td>
<td class="cellrowborder" valign="top" width="9.950000000000001%" headers="mcps1.1.4.1.2 "><p id="p18788114345414"><a name="p18788114345414"></a><a name="p18788114345414"></a>0</p>
</td>
<td class="cellrowborder" valign="top" width="59.67%" headers="mcps1.1.4.1.3 "><p id="p1378874385416"><a name="p1378874385416"></a><a name="p1378874385416"></a>静音模式</p>
</td>
</tr>
<tr id="row69495166107"><td class="cellrowborder" valign="top" width="30.380000000000003%" headers="mcps1.1.4.1.1 "><p id="p1447557125520"><a name="p1447557125520"></a><a name="p1447557125520"></a>RINGER_MODE_VIBRATE</p>
</td>
<td class="cellrowborder" valign="top" width="9.950000000000001%" headers="mcps1.1.4.1.2 "><p id="p04766720552"><a name="p04766720552"></a><a name="p04766720552"></a>1</p>
</td>
<td class="cellrowborder" valign="top" width="59.67%" headers="mcps1.1.4.1.3 "><p id="p3610191945517"><a name="p3610191945517"></a><a name="p3610191945517"></a>震动模式</p>
</td>
</tr>
<tr id="row49498168105"><td class="cellrowborder" valign="top" width="30.380000000000003%" headers="mcps1.1.4.1.1 "><p id="p1034891712171"><a name="p1034891712171"></a><a name="p1034891712171"></a>RINGER_MODE_NORMAL</p>
</td>
<td class="cellrowborder" valign="top" width="9.950000000000001%" headers="mcps1.1.4.1.2 "><p id="p421692310811"><a name="p421692310811"></a><a name="p421692310811"></a>2</p>
</td>
<td class="cellrowborder" valign="top" width="59.67%" headers="mcps1.1.4.1.3 "><p id="p187929346177"><a name="p187929346177"></a><a name="p187929346177"></a>响铃模式</p>
</td>
</tr>
</tbody>
</table>

## AudioManager<a name="section8265143814015"></a>

管理音频音量和音频设备。

### setVolume\(volumeType: AudioVolumeType, volume: number, callback: AsyncCallback<void\>\): void<a name="section189141826104616"></a>

设置指定流的音量，使用callback方式返回异步结果。

**参数：**

<a name="table11004831415"></a>
<table><thead align="left"><tr id="row1510164861414"><th class="cellrowborder" valign="top" width="17.57%" id="mcps1.1.5.1.1"><p id="p171154819142"><a name="p171154819142"></a><a name="p171154819142"></a>参数名</p>
</th>
<th class="cellrowborder" valign="top" width="19.52%" id="mcps1.1.5.1.2"><p id="p121164815148"><a name="p121164815148"></a><a name="p121164815148"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="7.5200000000000005%" id="mcps1.1.5.1.3"><p id="p1351547105313"><a name="p1351547105313"></a><a name="p1351547105313"></a>必填</p>
</th>
<th class="cellrowborder" valign="top" width="55.38999999999999%" id="mcps1.1.5.1.4"><p id="p131114812144"><a name="p131114812144"></a><a name="p131114812144"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="row911124881410"><td class="cellrowborder" valign="top" width="17.57%" headers="mcps1.1.5.1.1 "><p id="p11184811420"><a name="p11184811420"></a><a name="p11184811420"></a>volumeType</p>
</td>
<td class="cellrowborder" valign="top" width="19.52%" headers="mcps1.1.5.1.2 "><p id="p91134810142"><a name="p91134810142"></a><a name="p91134810142"></a><a href="#section92261857172218">AudioVolumeType</a></p>
</td>
<td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.5.1.3 "><p id="p1751247115312"><a name="p1751247115312"></a><a name="p1751247115312"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="55.38999999999999%" headers="mcps1.1.5.1.4 "><p id="p151134811149"><a name="p151134811149"></a><a name="p151134811149"></a>音量流类型。</p>
</td>
</tr>
<tr id="row1811164871417"><td class="cellrowborder" valign="top" width="17.57%" headers="mcps1.1.5.1.1 "><p id="p141114817144"><a name="p141114817144"></a><a name="p141114817144"></a>volume</p>
</td>
<td class="cellrowborder" valign="top" width="19.52%" headers="mcps1.1.5.1.2 "><p id="p1511648151417"><a name="p1511648151417"></a><a name="p1511648151417"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.5.1.3 "><p id="p151947175314"><a name="p151947175314"></a><a name="p151947175314"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="55.38999999999999%" headers="mcps1.1.5.1.4 "><p id="p16111548121411"><a name="p16111548121411"></a><a name="p16111548121411"></a>音量等级，可设置范围通过getMinVolume和getMaxVolume获取。</p>
</td>
</tr>
<tr id="row85121563158"><td class="cellrowborder" valign="top" width="17.57%" headers="mcps1.1.5.1.1 "><p id="p175121965154"><a name="p175121965154"></a><a name="p175121965154"></a>callback</p>
</td>
<td class="cellrowborder" valign="top" width="19.52%" headers="mcps1.1.5.1.2 "><p id="p1851220691518"><a name="p1851220691518"></a><a name="p1851220691518"></a>AsyncCallback&lt;void&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.5.1.3 "><p id="p15134711532"><a name="p15134711532"></a><a name="p15134711532"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="55.38999999999999%" headers="mcps1.1.5.1.4 "><p id="p751211651512"><a name="p751211651512"></a><a name="p751211651512"></a>回调表示成功还是失败。</p>
</td>
</tr>
</tbody>
</table>

**返回值：**

无

**示例：**

```
audioManager.setVolume(audio.AudioVolumeType.MEDIA, 10, (err)=>{
   if (err) {
	   console.error('Failed to set the volume. ${err.message}');
	   return;
   }
   console.log('Callback invoked to indicate a successful volume setting.');
})
```

### setVolume\(volumeType: AudioVolumeType, volume: number\): Promise<void\><a name="section102021249114612"></a>

设置指定流的音量，使用promise方式返回异步结果。

**参数：**

<a name="table20688181818176"></a>
<table><thead align="left"><tr id="row1368810188176"><th class="cellrowborder" valign="top" width="17.599999999999998%" id="mcps1.1.5.1.1"><p id="p5688818171712"><a name="p5688818171712"></a><a name="p5688818171712"></a>参数名</p>
</th>
<th class="cellrowborder" valign="top" width="19.49%" id="mcps1.1.5.1.2"><p id="p8688118111719"><a name="p8688118111719"></a><a name="p8688118111719"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="7.5200000000000005%" id="mcps1.1.5.1.3"><p id="p1994792215711"><a name="p1994792215711"></a><a name="p1994792215711"></a>必填</p>
</th>
<th class="cellrowborder" valign="top" width="55.38999999999999%" id="mcps1.1.5.1.4"><p id="p12688151816173"><a name="p12688151816173"></a><a name="p12688151816173"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="row0688518171714"><td class="cellrowborder" valign="top" width="17.599999999999998%" headers="mcps1.1.5.1.1 "><p id="p1368820182174"><a name="p1368820182174"></a><a name="p1368820182174"></a>volumeType</p>
</td>
<td class="cellrowborder" valign="top" width="19.49%" headers="mcps1.1.5.1.2 "><p id="p116881518111712"><a name="p116881518111712"></a><a name="p116881518111712"></a><a href="#section92261857172218">AudioVolumeType</a></p>
</td>
<td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.5.1.3 "><p id="p2094702218579"><a name="p2094702218579"></a><a name="p2094702218579"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="55.38999999999999%" headers="mcps1.1.5.1.4 "><p id="p1688131812176"><a name="p1688131812176"></a><a name="p1688131812176"></a>音量流类型。</p>
</td>
</tr>
<tr id="row5688218131711"><td class="cellrowborder" valign="top" width="17.599999999999998%" headers="mcps1.1.5.1.1 "><p id="p176881618181715"><a name="p176881618181715"></a><a name="p176881618181715"></a>volume</p>
</td>
<td class="cellrowborder" valign="top" width="19.49%" headers="mcps1.1.5.1.2 "><p id="p5688201811720"><a name="p5688201811720"></a><a name="p5688201811720"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.5.1.3 "><p id="p79472226579"><a name="p79472226579"></a><a name="p79472226579"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="55.38999999999999%" headers="mcps1.1.5.1.4 "><p id="p2688718171716"><a name="p2688718171716"></a><a name="p2688718171716"></a>音量等级，可设置范围通过getMinVolume和getMaxVolume获取。</p>
</td>
</tr>
</tbody>
</table>

**返回值：**

<a name="table106721328171713"></a>
<table><thead align="left"><tr id="row9672122817176"><th class="cellrowborder" valign="top" width="26.06%" id="mcps1.1.3.1.1"><p id="p106728288171"><a name="p106728288171"></a><a name="p106728288171"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="73.94%" id="mcps1.1.3.1.2"><p id="p5672112817178"><a name="p5672112817178"></a><a name="p5672112817178"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="row06721528191711"><td class="cellrowborder" valign="top" width="26.06%" headers="mcps1.1.3.1.1 "><p id="p107821612171919"><a name="p107821612171919"></a><a name="p107821612171919"></a>Promise&lt;void&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="73.94%" headers="mcps1.1.3.1.2 "><p id="p4672828141718"><a name="p4672828141718"></a><a name="p4672828141718"></a>Promise回调表示成功还是失败。</p>
</td>
</tr>
</tbody>
</table>

**示例：**

```
audioManager.setVolume(audio.AudioVolumeType.MEDIA, 10).then(()=>
    console.log('Promise returned to indicate a successful volume setting.');
)
```

### getVolume\(volumeType: AudioVolumeType, callback: AsyncCallback<number\>\): void<a name="section4387320194714"></a>

获取指定流的音量，使用callback方式返回异步结果。

**参数：**

<a name="table44323134204"></a>
<table><thead align="left"><tr id="row16433171322017"><th class="cellrowborder" valign="top" width="17.57%" id="mcps1.1.5.1.1"><p id="p1943319132201"><a name="p1943319132201"></a><a name="p1943319132201"></a>参数名</p>
</th>
<th class="cellrowborder" valign="top" width="19.52%" id="mcps1.1.5.1.2"><p id="p143314139203"><a name="p143314139203"></a><a name="p143314139203"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="7.5200000000000005%" id="mcps1.1.5.1.3"><p id="p1540765014581"><a name="p1540765014581"></a><a name="p1540765014581"></a>必填</p>
</th>
<th class="cellrowborder" valign="top" width="55.38999999999999%" id="mcps1.1.5.1.4"><p id="p10433181362011"><a name="p10433181362011"></a><a name="p10433181362011"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="row4433913122010"><td class="cellrowborder" valign="top" width="17.57%" headers="mcps1.1.5.1.1 "><p id="p54331513192018"><a name="p54331513192018"></a><a name="p54331513192018"></a>volumeType</p>
</td>
<td class="cellrowborder" valign="top" width="19.52%" headers="mcps1.1.5.1.2 "><p id="p182075544714"><a name="p182075544714"></a><a name="p182075544714"></a><a href="#section92261857172218">AudioVolumeType</a></p>
</td>
<td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.5.1.3 "><p id="p3407185013588"><a name="p3407185013588"></a><a name="p3407185013588"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="55.38999999999999%" headers="mcps1.1.5.1.4 "><p id="p44331613142018"><a name="p44331613142018"></a><a name="p44331613142018"></a>音量流类型。</p>
</td>
</tr>
<tr id="row743331372014"><td class="cellrowborder" valign="top" width="17.57%" headers="mcps1.1.5.1.1 "><p id="p143341319205"><a name="p143341319205"></a><a name="p143341319205"></a>callback</p>
</td>
<td class="cellrowborder" valign="top" width="19.52%" headers="mcps1.1.5.1.2 "><p id="p1043316137200"><a name="p1043316137200"></a><a name="p1043316137200"></a>AsyncCallback&lt;number&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.5.1.3 "><p id="p12659352195818"><a name="p12659352195818"></a><a name="p12659352195818"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="55.38999999999999%" headers="mcps1.1.5.1.4 "><p id="p3433161313204"><a name="p3433161313204"></a><a name="p3433161313204"></a>回调返回音量大小。</p>
</td>
</tr>
</tbody>
</table>

**返回值：**

无

**示例：**

```
audioManager.getVolume(audio.AudioVolumeType.MEDIA, (err, value) => {
   if (err) {
	   console.error('Failed to obtain the volume. ${err.message}');
	   return;
   }
   console.log('Callback invoked to indicate that the volume is obtained.');
})
```

### getVolume\(volumeType: AudioVolumeType\): Promise<number\><a name="section04121965119"></a>

获取指定流的音量，使用promise方式返回异步结果。

**参数：**

<a name="table174341113202016"></a>
<table><thead align="left"><tr id="row843416136203"><th class="cellrowborder" valign="top" width="17.57%" id="mcps1.1.5.1.1"><p id="p143410134207"><a name="p143410134207"></a><a name="p143410134207"></a>参数名</p>
</th>
<th class="cellrowborder" valign="top" width="19.52%" id="mcps1.1.5.1.2"><p id="p6434813182016"><a name="p6434813182016"></a><a name="p6434813182016"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="7.5200000000000005%" id="mcps1.1.5.1.3"><p id="p418721165918"><a name="p418721165918"></a><a name="p418721165918"></a>必填</p>
</th>
<th class="cellrowborder" valign="top" width="55.38999999999999%" id="mcps1.1.5.1.4"><p id="p943491320207"><a name="p943491320207"></a><a name="p943491320207"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="row5434181312207"><td class="cellrowborder" valign="top" width="17.57%" headers="mcps1.1.5.1.1 "><p id="p144343134206"><a name="p144343134206"></a><a name="p144343134206"></a>volumeType</p>
</td>
<td class="cellrowborder" valign="top" width="19.52%" headers="mcps1.1.5.1.2 "><p id="p121741711487"><a name="p121741711487"></a><a name="p121741711487"></a><a href="#section92261857172218">AudioVolumeType</a></p>
</td>
<td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.5.1.3 "><p id="p118791205914"><a name="p118791205914"></a><a name="p118791205914"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="55.38999999999999%" headers="mcps1.1.5.1.4 "><p id="p6434613122010"><a name="p6434613122010"></a><a name="p6434613122010"></a>音量流类型。</p>
</td>
</tr>
</tbody>
</table>

**返回值：**

<a name="table11435101313201"></a>
<table><thead align="left"><tr id="row9435191332013"><th class="cellrowborder" valign="top" width="25.97%" id="mcps1.1.3.1.1"><p id="p7435131352019"><a name="p7435131352019"></a><a name="p7435131352019"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="74.03%" id="mcps1.1.3.1.2"><p id="p343521362017"><a name="p343521362017"></a><a name="p343521362017"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="row1143515137209"><td class="cellrowborder" valign="top" width="25.97%" headers="mcps1.1.3.1.1 "><p id="p3435171318201"><a name="p3435171318201"></a><a name="p3435171318201"></a>Promise&lt;number&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="74.03%" headers="mcps1.1.3.1.2 "><p id="p17435513102016"><a name="p17435513102016"></a><a name="p17435513102016"></a>Promise回调返回音量大小。</p>
</td>
</tr>
</tbody>
</table>

**示例：**

```
audioManager.getVolume(audio.AudioVolumeType.MEDIA).then((value) =>
    console.log('Promise returned to indicate that the volume is obtained.' + value);
)
```

### getMinVolume\(volumeType: AudioVolumeType, callback: AsyncCallback<number\>\): void<a name="section188714283511"></a>

获取指定流的最小音量，使用callback方式返回异步结果。

**参数：**

<a name="table9585157122219"></a>
<table><thead align="left"><tr id="row95857713228"><th class="cellrowborder" valign="top" width="17.57%" id="mcps1.1.5.1.1"><p id="p1358510710223"><a name="p1358510710223"></a><a name="p1358510710223"></a>参数名</p>
</th>
<th class="cellrowborder" valign="top" width="19.52%" id="mcps1.1.5.1.2"><p id="p958577152214"><a name="p958577152214"></a><a name="p958577152214"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="7.5200000000000005%" id="mcps1.1.5.1.3"><p id="p12979171810590"><a name="p12979171810590"></a><a name="p12979171810590"></a>必填</p>
</th>
<th class="cellrowborder" valign="top" width="55.38999999999999%" id="mcps1.1.5.1.4"><p id="p85851579221"><a name="p85851579221"></a><a name="p85851579221"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="row7585373227"><td class="cellrowborder" valign="top" width="17.57%" headers="mcps1.1.5.1.1 "><p id="p105852712216"><a name="p105852712216"></a><a name="p105852712216"></a>volumeType</p>
</td>
<td class="cellrowborder" valign="top" width="19.52%" headers="mcps1.1.5.1.2 "><p id="p1862714319487"><a name="p1862714319487"></a><a name="p1862714319487"></a><a href="#section92261857172218">AudioVolumeType</a></p>
</td>
<td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.5.1.3 "><p id="p59791018125916"><a name="p59791018125916"></a><a name="p59791018125916"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="55.38999999999999%" headers="mcps1.1.5.1.4 "><p id="p758517710222"><a name="p758517710222"></a><a name="p758517710222"></a>音量流类型。</p>
</td>
</tr>
<tr id="row165851718222"><td class="cellrowborder" valign="top" width="17.57%" headers="mcps1.1.5.1.1 "><p id="p115866772214"><a name="p115866772214"></a><a name="p115866772214"></a>callback</p>
</td>
<td class="cellrowborder" valign="top" width="19.52%" headers="mcps1.1.5.1.2 "><p id="p558614719222"><a name="p558614719222"></a><a name="p558614719222"></a>AsyncCallback&lt;number&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.5.1.3 "><p id="p89791518185916"><a name="p89791518185916"></a><a name="p89791518185916"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="55.38999999999999%" headers="mcps1.1.5.1.4 "><p id="p1958614711221"><a name="p1958614711221"></a><a name="p1958614711221"></a>回调返回最小音量。</p>
</td>
</tr>
</tbody>
</table>

**返回值：**

无

**示例：**

```
audioManager.getVolume(audio.AudioVolumeType.MEDIA, (err, value) => {
    if (err) {
        console.error('Failed to obtain the minimum volume. ${err.message}');
	return;
    }
    console.log('Callback invoked to indicate that the minimum volume is obtained.' + value);
})
```

### getMinVolume\(volumeType: AudioVolumeType\): Promise<number\><a name="section41556389511"></a>

获取指定流的最小音量，使用promise方式返回异步结果。

**参数：**

<a name="table558627102215"></a>
<table><thead align="left"><tr id="row175868714227"><th class="cellrowborder" valign="top" width="17.57%" id="mcps1.1.5.1.1"><p id="p1758619712217"><a name="p1758619712217"></a><a name="p1758619712217"></a>参数名</p>
</th>
<th class="cellrowborder" valign="top" width="19.52%" id="mcps1.1.5.1.2"><p id="p12586776227"><a name="p12586776227"></a><a name="p12586776227"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="7.5200000000000005%" id="mcps1.1.5.1.3"><p id="p94861627165914"><a name="p94861627165914"></a><a name="p94861627165914"></a>必填</p>
</th>
<th class="cellrowborder" valign="top" width="55.38999999999999%" id="mcps1.1.5.1.4"><p id="p85862711223"><a name="p85862711223"></a><a name="p85862711223"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="row65861477221"><td class="cellrowborder" valign="top" width="17.57%" headers="mcps1.1.5.1.1 "><p id="p5586167172217"><a name="p5586167172217"></a><a name="p5586167172217"></a>volumeType</p>
</td>
<td class="cellrowborder" valign="top" width="19.52%" headers="mcps1.1.5.1.2 "><p id="p592519511485"><a name="p592519511485"></a><a name="p592519511485"></a><a href="#section92261857172218">AudioVolumeType</a></p>
</td>
<td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.5.1.3 "><p id="p2048622713593"><a name="p2048622713593"></a><a name="p2048622713593"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="55.38999999999999%" headers="mcps1.1.5.1.4 "><p id="p135871079226"><a name="p135871079226"></a><a name="p135871079226"></a>音量流类型。</p>
</td>
</tr>
</tbody>
</table>

**返回值：**

<a name="table35874718223"></a>
<table><thead align="left"><tr id="row1558718715227"><th class="cellrowborder" valign="top" width="26.02%" id="mcps1.1.3.1.1"><p id="p75871715226"><a name="p75871715226"></a><a name="p75871715226"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="73.98%" id="mcps1.1.3.1.2"><p id="p85871720225"><a name="p85871720225"></a><a name="p85871720225"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="row1458710714221"><td class="cellrowborder" valign="top" width="26.02%" headers="mcps1.1.3.1.1 "><p id="p558737142218"><a name="p558737142218"></a><a name="p558737142218"></a>Promise&lt;number&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="73.98%" headers="mcps1.1.3.1.2 "><p id="p05878717229"><a name="p05878717229"></a><a name="p05878717229"></a>Promise回调返回最小音量。</p>
</td>
</tr>
</tbody>
</table>

**示例：**

```
audioManager.getMinVolume(audio.AudioVolumeType.MEDIA).then((value) =>
    console.log('Promised returned to indicate that the minimum  volume is obtained.' + value);
)
```

### getMaxVolume\(volumeType: AudioVolumeType, callback: AsyncCallback<number\>\): void<a name="section690395418516"></a>

获取指定流的最大音量，使用callback方式返回异步结果。

**参数：**

<a name="table7210144262214"></a>
<table><thead align="left"><tr id="row7210104242215"><th class="cellrowborder" valign="top" width="17.57%" id="mcps1.1.5.1.1"><p id="p521018428221"><a name="p521018428221"></a><a name="p521018428221"></a>参数名</p>
</th>
<th class="cellrowborder" valign="top" width="19.52%" id="mcps1.1.5.1.2"><p id="p102107424223"><a name="p102107424223"></a><a name="p102107424223"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="7.5200000000000005%" id="mcps1.1.5.1.3"><p id="p167531439593"><a name="p167531439593"></a><a name="p167531439593"></a>必填</p>
</th>
<th class="cellrowborder" valign="top" width="55.38999999999999%" id="mcps1.1.5.1.4"><p id="p1521054292218"><a name="p1521054292218"></a><a name="p1521054292218"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="row321010428228"><td class="cellrowborder" valign="top" width="17.57%" headers="mcps1.1.5.1.1 "><p id="p5210642132212"><a name="p5210642132212"></a><a name="p5210642132212"></a>volumeType</p>
</td>
<td class="cellrowborder" valign="top" width="19.52%" headers="mcps1.1.5.1.2 "><p id="p35691288487"><a name="p35691288487"></a><a name="p35691288487"></a><a href="#section92261857172218">AudioVolumeType</a></p>
</td>
<td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.5.1.3 "><p id="p14753114317590"><a name="p14753114317590"></a><a name="p14753114317590"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="55.38999999999999%" headers="mcps1.1.5.1.4 "><p id="p8210242112217"><a name="p8210242112217"></a><a name="p8210242112217"></a>音量流类型。</p>
</td>
</tr>
<tr id="row82115429227"><td class="cellrowborder" valign="top" width="17.57%" headers="mcps1.1.5.1.1 "><p id="p4211842132218"><a name="p4211842132218"></a><a name="p4211842132218"></a>callback</p>
</td>
<td class="cellrowborder" valign="top" width="19.52%" headers="mcps1.1.5.1.2 "><p id="p8211114232217"><a name="p8211114232217"></a><a name="p8211114232217"></a>AsyncCallback&lt;number&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.5.1.3 "><p id="p1275384315910"><a name="p1275384315910"></a><a name="p1275384315910"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="55.38999999999999%" headers="mcps1.1.5.1.4 "><p id="p1621114282212"><a name="p1621114282212"></a><a name="p1621114282212"></a>回调返回最大音量大小。</p>
</td>
</tr>
</tbody>
</table>

**返回值：**

无

**示例：**

```
audioManager.getMaxVolume(audio.AudioVolumeType.MEDIA, (err, value) => {
    if (err) {
        console.error('Failed to obtain the maximum volume. ${err.message}');
        return;
    }
    console.log('Callback invoked to indicate that the maximum volume is obtained.' + value);
})
```

### getMaxVolume\(volumeType: AudioVolumeType\): Promise<number\><a name="section155151345217"></a>

获取指定流的最大音量，使用promise方式返回异步结果。

**参数：**

<a name="table11211104210226"></a>
<table><thead align="left"><tr id="row42111424228"><th class="cellrowborder" valign="top" width="17.57%" id="mcps1.1.5.1.1"><p id="p14211842162217"><a name="p14211842162217"></a><a name="p14211842162217"></a>参数名</p>
</th>
<th class="cellrowborder" valign="top" width="20.54%" id="mcps1.1.5.1.2"><p id="p7211184211223"><a name="p7211184211223"></a><a name="p7211184211223"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="8.72%" id="mcps1.1.5.1.3"><p id="p165812523592"><a name="p165812523592"></a><a name="p165812523592"></a>必填</p>
</th>
<th class="cellrowborder" valign="top" width="53.169999999999995%" id="mcps1.1.5.1.4"><p id="p821164232217"><a name="p821164232217"></a><a name="p821164232217"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="row22111742112216"><td class="cellrowborder" valign="top" width="17.57%" headers="mcps1.1.5.1.1 "><p id="p152121542152218"><a name="p152121542152218"></a><a name="p152121542152218"></a>volumeType</p>
</td>
<td class="cellrowborder" valign="top" width="20.54%" headers="mcps1.1.5.1.2 "><p id="p9479411164814"><a name="p9479411164814"></a><a name="p9479411164814"></a><a href="#section92261857172218">AudioVolumeType</a></p>
</td>
<td class="cellrowborder" valign="top" width="8.72%" headers="mcps1.1.5.1.3 "><p id="p45811752165910"><a name="p45811752165910"></a><a name="p45811752165910"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="53.169999999999995%" headers="mcps1.1.5.1.4 "><p id="p1021294292216"><a name="p1021294292216"></a><a name="p1021294292216"></a>音量流类型。</p>
</td>
</tr>
</tbody>
</table>

**返回值：**

<a name="table621215425220"></a>
<table><thead align="left"><tr id="row3212842112215"><th class="cellrowborder" valign="top" width="26.02%" id="mcps1.1.3.1.1"><p id="p521274272216"><a name="p521274272216"></a><a name="p521274272216"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="73.98%" id="mcps1.1.3.1.2"><p id="p1121214215221"><a name="p1121214215221"></a><a name="p1121214215221"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="row12121442192216"><td class="cellrowborder" valign="top" width="26.02%" headers="mcps1.1.3.1.1 "><p id="p72128426221"><a name="p72128426221"></a><a name="p72128426221"></a>Promise&lt;number&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="73.98%" headers="mcps1.1.3.1.2 "><p id="p4212114210226"><a name="p4212114210226"></a><a name="p4212114210226"></a>Promise回调返回最大音量大小。</p>
</td>
</tr>
</tbody>
</table>

**示例：**

```
audioManager.getMaxVolume(audio.AudioVolumeType.MEDIA).then((data)=>
    console.log('Promised returned to indicate that the maximum volume is obtained.');
)
```

### mute\(volumeType: AudioVolumeType, mute: boolean, callback: AsyncCallback<void\>\): void<sup>7+</sup><a name="section13516136134613"></a>

设置指定音量流静音，使用callback方式返回异步结果。

**参数：**

<a name="table16516183634618"></a>
<table><thead align="left"><tr id="row35162369464"><th class="cellrowborder" valign="top" width="17.57%" id="mcps1.1.5.1.1"><p id="p1751663624620"><a name="p1751663624620"></a><a name="p1751663624620"></a>参数名</p>
</th>
<th class="cellrowborder" valign="top" width="19.52%" id="mcps1.1.5.1.2"><p id="p10517193604610"><a name="p10517193604610"></a><a name="p10517193604610"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="8.97%" id="mcps1.1.5.1.3"><p id="p75178369466"><a name="p75178369466"></a><a name="p75178369466"></a>必填</p>
</th>
<th class="cellrowborder" valign="top" width="53.94%" id="mcps1.1.5.1.4"><p id="p135173369461"><a name="p135173369461"></a><a name="p135173369461"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="row14517123611463"><td class="cellrowborder" valign="top" width="17.57%" headers="mcps1.1.5.1.1 "><p id="p1051753654616"><a name="p1051753654616"></a><a name="p1051753654616"></a>volumeType</p>
</td>
<td class="cellrowborder" valign="top" width="19.52%" headers="mcps1.1.5.1.2 "><p id="p19517183664611"><a name="p19517183664611"></a><a name="p19517183664611"></a><a href="#section92261857172218">AudioVolumeType</a></p>
</td>
<td class="cellrowborder" valign="top" width="8.97%" headers="mcps1.1.5.1.3 "><p id="p14517113634613"><a name="p14517113634613"></a><a name="p14517113634613"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="53.94%" headers="mcps1.1.5.1.4 "><p id="p412912394120"><a name="p412912394120"></a><a name="p412912394120"></a>音量流类型。</p>
</td>
</tr>
<tr id="row051703612469"><td class="cellrowborder" valign="top" width="17.57%" headers="mcps1.1.5.1.1 "><p id="p8518436144612"><a name="p8518436144612"></a><a name="p8518436144612"></a>mute</p>
</td>
<td class="cellrowborder" valign="top" width="19.52%" headers="mcps1.1.5.1.2 "><p id="p592111217487"><a name="p592111217487"></a><a name="p592111217487"></a>boolean</p>
</td>
<td class="cellrowborder" valign="top" width="8.97%" headers="mcps1.1.5.1.3 "><p id="p145187366468"><a name="p145187366468"></a><a name="p145187366468"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="53.94%" headers="mcps1.1.5.1.4 "><p id="p11518133684618"><a name="p11518133684618"></a><a name="p11518133684618"></a>静音状态，true为静音，false为非静音。</p>
</td>
</tr>
<tr id="row351833624617"><td class="cellrowborder" valign="top" width="17.57%" headers="mcps1.1.5.1.1 "><p id="p1651817365464"><a name="p1651817365464"></a><a name="p1651817365464"></a>callback</p>
</td>
<td class="cellrowborder" valign="top" width="19.52%" headers="mcps1.1.5.1.2 "><p id="p451813613462"><a name="p451813613462"></a><a name="p451813613462"></a>AsyncCallback&lt;void&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="8.97%" headers="mcps1.1.5.1.3 "><p id="p65181636194618"><a name="p65181636194618"></a><a name="p65181636194618"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="53.94%" headers="mcps1.1.5.1.4 "><p id="p18115237124119"><a name="p18115237124119"></a><a name="p18115237124119"></a>回调表示成功还是失败。</p>
</td>
</tr>
</tbody>
</table>

**返回值：**

无

**示例：**

```
audioManager.mute(audio.AudioVolumeType.MEDIA, true, (err) => {
    if (err) {
        console.error('Failed to mute the stream. ${err.message}');
	return;
    }
    console.log('Callback invoked to indicate that the stream is muted.');
})
```

### mute\(volumeType: AudioVolumeType, mute: boolean\): Promise<void\><sup>7+</sup><a name="section7519036144616"></a>

设置指定音量流静音，使用promise方式返回异步结果。

**参数：**

<a name="table9519103616467"></a>
<table><thead align="left"><tr id="row12519123684618"><th class="cellrowborder" valign="top" width="17.599999999999998%" id="mcps1.1.5.1.1"><p id="p7885132645511"><a name="p7885132645511"></a><a name="p7885132645511"></a>参数名</p>
</th>
<th class="cellrowborder" valign="top" width="19.49%" id="mcps1.1.5.1.2"><p id="p98856261553"><a name="p98856261553"></a><a name="p98856261553"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="9.950000000000001%" id="mcps1.1.5.1.3"><p id="p1388582618559"><a name="p1388582618559"></a><a name="p1388582618559"></a>必填</p>
</th>
<th class="cellrowborder" valign="top" width="52.959999999999994%" id="mcps1.1.5.1.4"><p id="p688512261558"><a name="p688512261558"></a><a name="p688512261558"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="row552093624612"><td class="cellrowborder" valign="top" width="17.599999999999998%" headers="mcps1.1.5.1.1 "><p id="p1052023616462"><a name="p1052023616462"></a><a name="p1052023616462"></a>volumeType</p>
</td>
<td class="cellrowborder" valign="top" width="19.49%" headers="mcps1.1.5.1.2 "><p id="p552013620468"><a name="p552013620468"></a><a name="p552013620468"></a><a href="#section92261857172218">AudioVolumeType</a></p>
</td>
<td class="cellrowborder" valign="top" width="9.950000000000001%" headers="mcps1.1.5.1.3 "><p id="p85203364468"><a name="p85203364468"></a><a name="p85203364468"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="52.959999999999994%" headers="mcps1.1.5.1.4 "><p id="p05201036124617"><a name="p05201036124617"></a><a name="p05201036124617"></a>音量流类型。</p>
</td>
</tr>
<tr id="row7520143614463"><td class="cellrowborder" valign="top" width="17.599999999999998%" headers="mcps1.1.5.1.1 "><p id="p9522436134617"><a name="p9522436134617"></a><a name="p9522436134617"></a>mute</p>
</td>
<td class="cellrowborder" valign="top" width="19.49%" headers="mcps1.1.5.1.2 "><p id="p12440205013243"><a name="p12440205013243"></a><a name="p12440205013243"></a>boolean</p>
</td>
<td class="cellrowborder" valign="top" width="9.950000000000001%" headers="mcps1.1.5.1.3 "><p id="p15221236134617"><a name="p15221236134617"></a><a name="p15221236134617"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="52.959999999999994%" headers="mcps1.1.5.1.4 "><p id="p1079311161421"><a name="p1079311161421"></a><a name="p1079311161421"></a>静音状态，true为静音，false为非静音。</p>
</td>
</tr>
</tbody>
</table>

**返回值：**

<a name="table1152273694614"></a>
<table><thead align="left"><tr id="row352213367467"><th class="cellrowborder" valign="top" width="26.06%" id="mcps1.1.3.1.1"><p id="p16791154010553"><a name="p16791154010553"></a><a name="p16791154010553"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="73.94%" id="mcps1.1.3.1.2"><p id="p117911040155511"><a name="p117911040155511"></a><a name="p117911040155511"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="row185231369468"><td class="cellrowborder" valign="top" width="26.06%" headers="mcps1.1.3.1.1 "><p id="p25231836174612"><a name="p25231836174612"></a><a name="p25231836174612"></a>Promise&lt;void&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="73.94%" headers="mcps1.1.3.1.2 "><p id="p18347134724215"><a name="p18347134724215"></a><a name="p18347134724215"></a>Promise回调表示成功还是失败。</p>
</td>
</tr>
</tbody>
</table>

**示例：**

```
audioManager.mute(audio.AudioVolumeType.MEDIA, true).then(() =>
    console.log('Promise returned to indicate that the stream is muted.');
)
```

### isMute\(volumeType: AudioVolumeType, callback: AsyncCallback<boolean\>\): void<sup>7+</sup><a name="section10684183819585"></a>

获取指定音量流是否被静音，使用callback方式返回异步结果。

**参数：**

<a name="table26841038115812"></a>
<table><thead align="left"><tr id="row166859386584"><th class="cellrowborder" valign="top" width="17.57%" id="mcps1.1.5.1.1"><p id="p1077814316558"><a name="p1077814316558"></a><a name="p1077814316558"></a>参数名</p>
</th>
<th class="cellrowborder" valign="top" width="19.52%" id="mcps1.1.5.1.2"><p id="p67781331135518"><a name="p67781331135518"></a><a name="p67781331135518"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="10.56%" id="mcps1.1.5.1.3"><p id="p1177819312556"><a name="p1177819312556"></a><a name="p1177819312556"></a>必填</p>
</th>
<th class="cellrowborder" valign="top" width="52.349999999999994%" id="mcps1.1.5.1.4"><p id="p177816317552"><a name="p177816317552"></a><a name="p177816317552"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="row14685163820583"><td class="cellrowborder" valign="top" width="17.57%" headers="mcps1.1.5.1.1 "><p id="p668543875817"><a name="p668543875817"></a><a name="p668543875817"></a>volumeType</p>
</td>
<td class="cellrowborder" valign="top" width="19.52%" headers="mcps1.1.5.1.2 "><p id="p1268653815581"><a name="p1268653815581"></a><a name="p1268653815581"></a><a href="#section92261857172218">AudioVolumeType</a></p>
</td>
<td class="cellrowborder" valign="top" width="10.56%" headers="mcps1.1.5.1.3 "><p id="p12686123814583"><a name="p12686123814583"></a><a name="p12686123814583"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="52.349999999999994%" headers="mcps1.1.5.1.4 "><p id="p6947181918459"><a name="p6947181918459"></a><a name="p6947181918459"></a>音量流类型。</p>
</td>
</tr>
<tr id="row15686153825819"><td class="cellrowborder" valign="top" width="17.57%" headers="mcps1.1.5.1.1 "><p id="p5686153895817"><a name="p5686153895817"></a><a name="p5686153895817"></a>callback</p>
</td>
<td class="cellrowborder" valign="top" width="19.52%" headers="mcps1.1.5.1.2 "><p id="p16869387581"><a name="p16869387581"></a><a name="p16869387581"></a>AsyncCallback&lt;boolean&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="10.56%" headers="mcps1.1.5.1.3 "><p id="p4686163865811"><a name="p4686163865811"></a><a name="p4686163865811"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="52.349999999999994%" headers="mcps1.1.5.1.4 "><p id="p183723274511"><a name="p183723274511"></a><a name="p183723274511"></a>回调返回流静音状态，true为静音，false为非静音。</p>
</td>
</tr>
</tbody>
</table>

**返回值：**

无

**示例：**

```
audioManager.isMute(audio.AudioVolumeType.MEDIA, (err, value) => {
   if (err) {
	   console.error('Failed to obtain the mute status. ${err.message}');
	   return;
   }
   console.log('Callback invoked to indicate that the mute status of the stream is obtained.' + value);
})
```

### isMute\(volumeType: AudioVolumeType\): Promise<boolean\><sup>7+</sup><a name="section6920211145610"></a>

获取指定音量流是否被静音，使用promise方式返回异步结果。

**参数：**

<a name="table179201611155614"></a>
<table><thead align="left"><tr id="row9920911195617"><th class="cellrowborder" valign="top" width="17.57%" id="mcps1.1.5.1.1"><p id="p873322815570"><a name="p873322815570"></a><a name="p873322815570"></a>参数名</p>
</th>
<th class="cellrowborder" valign="top" width="19.52%" id="mcps1.1.5.1.2"><p id="p87331028115717"><a name="p87331028115717"></a><a name="p87331028115717"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="9.94%" id="mcps1.1.5.1.3"><p id="p47331128105710"><a name="p47331128105710"></a><a name="p47331128105710"></a>必填</p>
</th>
<th class="cellrowborder" valign="top" width="52.96999999999999%" id="mcps1.1.5.1.4"><p id="p373318281575"><a name="p373318281575"></a><a name="p373318281575"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="row1292111110560"><td class="cellrowborder" valign="top" width="17.57%" headers="mcps1.1.5.1.1 "><p id="p149211311135618"><a name="p149211311135618"></a><a name="p149211311135618"></a>volumeType</p>
</td>
<td class="cellrowborder" valign="top" width="19.52%" headers="mcps1.1.5.1.2 "><p id="p1692191110568"><a name="p1692191110568"></a><a name="p1692191110568"></a><a href="#section92261857172218">AudioVolumeType</a></p>
</td>
<td class="cellrowborder" valign="top" width="9.94%" headers="mcps1.1.5.1.3 "><p id="p1921131145612"><a name="p1921131145612"></a><a name="p1921131145612"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="52.96999999999999%" headers="mcps1.1.5.1.4 "><p id="p12726822462"><a name="p12726822462"></a><a name="p12726822462"></a>音量流类型。</p>
</td>
</tr>
</tbody>
</table>

**返回值：**

<a name="table1392211113567"></a>
<table><thead align="left"><tr id="row39224110565"><th class="cellrowborder" valign="top" width="25.97%" id="mcps1.1.3.1.1"><p id="p1532894520558"><a name="p1532894520558"></a><a name="p1532894520558"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="74.03%" id="mcps1.1.3.1.2"><p id="p16328114517555"><a name="p16328114517555"></a><a name="p16328114517555"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="row8922161155612"><td class="cellrowborder" valign="top" width="25.97%" headers="mcps1.1.3.1.1 "><p id="p992211117566"><a name="p992211117566"></a><a name="p992211117566"></a>Promise&lt;boolean&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="74.03%" headers="mcps1.1.3.1.2 "><p id="p17922131112568"><a name="p17922131112568"></a><a name="p17922131112568"></a>Promise回调返回流静音状态，true为静音，false为非静音。</p>
</td>
</tr>
</tbody>
</table>

**示例：**

```
audioManager.isMute(audio.AudioVolumeType.MEDIA).then((value) =>
    console.log('Promise returned to indicate that the mute status of the stream is obtained.' + value);
)
```

### isActive\(volumeType: AudioVolumeType, callback: AsyncCallback<boolean\>\): void<sup>7+</sup><a name="section380012544121"></a>

获取指定音量流是否为活跃状态，使用callback方式返回异步结果。

**参数：**

<a name="table11801954151215"></a>
<table><thead align="left"><tr id="row480175481211"><th class="cellrowborder" valign="top" width="17.57%" id="mcps1.1.5.1.1"><p id="p16771626115716"><a name="p16771626115716"></a><a name="p16771626115716"></a>参数名</p>
</th>
<th class="cellrowborder" valign="top" width="19.52%" id="mcps1.1.5.1.2"><p id="p146771226195712"><a name="p146771226195712"></a><a name="p146771226195712"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="9.78%" id="mcps1.1.5.1.3"><p id="p16678202665719"><a name="p16678202665719"></a><a name="p16678202665719"></a>必填</p>
</th>
<th class="cellrowborder" valign="top" width="53.13%" id="mcps1.1.5.1.4"><p id="p867882665719"><a name="p867882665719"></a><a name="p867882665719"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="row6802165481211"><td class="cellrowborder" valign="top" width="17.57%" headers="mcps1.1.5.1.1 "><p id="p138023547121"><a name="p138023547121"></a><a name="p138023547121"></a>volumeType</p>
</td>
<td class="cellrowborder" valign="top" width="19.52%" headers="mcps1.1.5.1.2 "><p id="p168021543125"><a name="p168021543125"></a><a name="p168021543125"></a><a href="#section92261857172218">AudioVolumeType</a></p>
</td>
<td class="cellrowborder" valign="top" width="9.78%" headers="mcps1.1.5.1.3 "><p id="p1180275418128"><a name="p1180275418128"></a><a name="p1180275418128"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="53.13%" headers="mcps1.1.5.1.4 "><p id="p106221941204617"><a name="p106221941204617"></a><a name="p106221941204617"></a>音量流类型。</p>
</td>
</tr>
<tr id="row148021654111218"><td class="cellrowborder" valign="top" width="17.57%" headers="mcps1.1.5.1.1 "><p id="p1280275410128"><a name="p1280275410128"></a><a name="p1280275410128"></a>callback</p>
</td>
<td class="cellrowborder" valign="top" width="19.52%" headers="mcps1.1.5.1.2 "><p id="p1680245411214"><a name="p1680245411214"></a><a name="p1680245411214"></a>AsyncCallback&lt;boolean&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="9.78%" headers="mcps1.1.5.1.3 "><p id="p198031054151212"><a name="p198031054151212"></a><a name="p198031054151212"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="53.13%" headers="mcps1.1.5.1.4 "><p id="p2803354131214"><a name="p2803354131214"></a><a name="p2803354131214"></a>回调返回流的活跃状态，true为活跃，false为不活跃。</p>
</td>
</tr>
</tbody>
</table>

**返回值：**

无

**示例：**

```
audioManager.isActive(audio.AudioVolumeType.MEDIA, (err, value) => {
    if (err) {
        console.error('Failed to obtain the active status of the stream. ${err.message}');
	return;
    }
    console.log('Callback invoked to indicate that the active status of the stream is obtained.' + value);
})
```

### isActive\(volumeType: AudioVolumeType\): Promise<boolean\><sup>7+</sup><a name="section1880315481216"></a>

获取指定音量流是否为活跃状态，使用promise方式返回异步结果。

**参数：**

<a name="table18041954171217"></a>
<table><thead align="left"><tr id="row18804154151212"><th class="cellrowborder" valign="top" width="17.57%" id="mcps1.1.5.1.1"><p id="p1162310248571"><a name="p1162310248571"></a><a name="p1162310248571"></a>参数名</p>
</th>
<th class="cellrowborder" valign="top" width="19.52%" id="mcps1.1.5.1.2"><p id="p262322411572"><a name="p262322411572"></a><a name="p262322411572"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="9.43%" id="mcps1.1.5.1.3"><p id="p13623152455711"><a name="p13623152455711"></a><a name="p13623152455711"></a>必填</p>
</th>
<th class="cellrowborder" valign="top" width="53.480000000000004%" id="mcps1.1.5.1.4"><p id="p186231724165714"><a name="p186231724165714"></a><a name="p186231724165714"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="row8805115411211"><td class="cellrowborder" valign="top" width="17.57%" headers="mcps1.1.5.1.1 "><p id="p118051544122"><a name="p118051544122"></a><a name="p118051544122"></a>volumeType</p>
</td>
<td class="cellrowborder" valign="top" width="19.52%" headers="mcps1.1.5.1.2 "><p id="p19805145415124"><a name="p19805145415124"></a><a name="p19805145415124"></a><a href="#section92261857172218">AudioVolumeType</a></p>
</td>
<td class="cellrowborder" valign="top" width="9.43%" headers="mcps1.1.5.1.3 "><p id="p380585411216"><a name="p380585411216"></a><a name="p380585411216"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="53.480000000000004%" headers="mcps1.1.5.1.4 "><p id="p1238516185410"><a name="p1238516185410"></a><a name="p1238516185410"></a>音量流类型。</p>
</td>
</tr>
</tbody>
</table>

**返回值：**

<a name="table1380613543122"></a>
<table><thead align="left"><tr id="row2806125411129"><th class="cellrowborder" valign="top" width="25.97%" id="mcps1.1.3.1.1"><p id="p07811652175517"><a name="p07811652175517"></a><a name="p07811652175517"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="74.03%" id="mcps1.1.3.1.2"><p id="p478112526558"><a name="p478112526558"></a><a name="p478112526558"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="row680605491218"><td class="cellrowborder" valign="top" width="25.97%" headers="mcps1.1.3.1.1 "><p id="p138061054101212"><a name="p138061054101212"></a><a name="p138061054101212"></a>Promise&lt;boolean&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="74.03%" headers="mcps1.1.3.1.2 "><p id="p280615541125"><a name="p280615541125"></a><a name="p280615541125"></a>Promise回调返回流的活跃状态，true为活跃，false为不活跃。</p>
</td>
</tr>
</tbody>
</table>

**示例：**

```
audioManager.isActive(audio.AudioVolumeType.MEDIA).then((value) =>
    console.log('Promise returned to indicate that the active status of the stream is obtained.' + value);
)
```

### setRingerMode\(mode: AudioRingMode, callback: AsyncCallback<void\>\): void<sup>7+</sup><a name="section18572131483613"></a>

设置铃声模式，使用callback方式返回异步结果。

**参数：**

<a name="table157219143361"></a>
<table><thead align="left"><tr id="row1357221412365"><th class="cellrowborder" valign="top" width="17.57%" id="mcps1.1.5.1.1"><p id="p1175132113575"><a name="p1175132113575"></a><a name="p1175132113575"></a>参数名</p>
</th>
<th class="cellrowborder" valign="top" width="19.52%" id="mcps1.1.5.1.2"><p id="p1375122116572"><a name="p1375122116572"></a><a name="p1375122116572"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="10.56%" id="mcps1.1.5.1.3"><p id="p1375122115710"><a name="p1375122115710"></a><a name="p1375122115710"></a>必填</p>
</th>
<th class="cellrowborder" valign="top" width="52.349999999999994%" id="mcps1.1.5.1.4"><p id="p18751521135717"><a name="p18751521135717"></a><a name="p18751521135717"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="row14573171411369"><td class="cellrowborder" valign="top" width="17.57%" headers="mcps1.1.5.1.1 "><p id="p55731714143611"><a name="p55731714143611"></a><a name="p55731714143611"></a>mode</p>
</td>
<td class="cellrowborder" valign="top" width="19.52%" headers="mcps1.1.5.1.2 "><p id="p185881627122214"><a name="p185881627122214"></a><a name="p185881627122214"></a>AudioRingMode</p>
</td>
<td class="cellrowborder" valign="top" width="10.56%" headers="mcps1.1.5.1.3 "><p id="p35731514193617"><a name="p35731514193617"></a><a name="p35731514193617"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="52.349999999999994%" headers="mcps1.1.5.1.4 "><p id="p8573191453617"><a name="p8573191453617"></a><a name="p8573191453617"></a>音频铃声模式。</p>
</td>
</tr>
<tr id="row165731014143611"><td class="cellrowborder" valign="top" width="17.57%" headers="mcps1.1.5.1.1 "><p id="p357416149361"><a name="p357416149361"></a><a name="p357416149361"></a>callback</p>
</td>
<td class="cellrowborder" valign="top" width="19.52%" headers="mcps1.1.5.1.2 "><p id="p1457491463618"><a name="p1457491463618"></a><a name="p1457491463618"></a>AsyncCallback&lt;void&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="10.56%" headers="mcps1.1.5.1.3 "><p id="p95741514103617"><a name="p95741514103617"></a><a name="p95741514103617"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="52.349999999999994%" headers="mcps1.1.5.1.4 "><p id="p19574514123617"><a name="p19574514123617"></a><a name="p19574514123617"></a>回调返回设置成功或失败。</p>
</td>
</tr>
</tbody>
</table>

**返回值：**

无

**示例：**

```
audioManager.setRingerMode(audio.AudioRingMode.RINGER_MODE_NORMAL, (err) => {
   if (err) {
       console.error('Failed to set the ringer mode.​ ${err.message}');
       return;
    }
    console.log('Callback invoked to indicate a successful setting of the ringer mode.');
})
```

### setRingerMode\(mode: AudioRingMode\): Promise<void\><sup>7+</sup><a name="section55741914143615"></a>

设置铃声模式，使用promise方式返回异步结果。

**参数：**

<a name="table55743147369"></a>
<table><thead align="left"><tr id="row557512147369"><th class="cellrowborder" valign="top" width="17.599999999999998%" id="mcps1.1.5.1.1"><p id="p86951317155710"><a name="p86951317155710"></a><a name="p86951317155710"></a>参数名</p>
</th>
<th class="cellrowborder" valign="top" width="19.49%" id="mcps1.1.5.1.2"><p id="p13695101705716"><a name="p13695101705716"></a><a name="p13695101705716"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="9.08%" id="mcps1.1.5.1.3"><p id="p7695717175715"><a name="p7695717175715"></a><a name="p7695717175715"></a>必填</p>
</th>
<th class="cellrowborder" valign="top" width="53.83%" id="mcps1.1.5.1.4"><p id="p2695181775710"><a name="p2695181775710"></a><a name="p2695181775710"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="row10575131412368"><td class="cellrowborder" valign="top" width="17.599999999999998%" headers="mcps1.1.5.1.1 "><p id="p1957571420365"><a name="p1957571420365"></a><a name="p1957571420365"></a>mode</p>
</td>
<td class="cellrowborder" valign="top" width="19.49%" headers="mcps1.1.5.1.2 "><p id="p14224197645"><a name="p14224197645"></a><a name="p14224197645"></a>AudioRingMode</p>
</td>
<td class="cellrowborder" valign="top" width="9.08%" headers="mcps1.1.5.1.3 "><p id="p9575191416367"><a name="p9575191416367"></a><a name="p9575191416367"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="53.83%" headers="mcps1.1.5.1.4 "><p id="p10576214143620"><a name="p10576214143620"></a><a name="p10576214143620"></a>音频铃声模式。</p>
</td>
</tr>
</tbody>
</table>

**返回值：**

<a name="table145763146361"></a>
<table><thead align="left"><tr id="row1576101403610"><th class="cellrowborder" valign="top" width="26.06%" id="mcps1.1.3.1.1"><p id="p465818212561"><a name="p465818212561"></a><a name="p465818212561"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="73.94%" id="mcps1.1.3.1.2"><p id="p2065832195616"><a name="p2065832195616"></a><a name="p2065832195616"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="row1257711144362"><td class="cellrowborder" valign="top" width="26.06%" headers="mcps1.1.3.1.1 "><p id="p1577714143613"><a name="p1577714143613"></a><a name="p1577714143613"></a>Promise&lt;void&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="73.94%" headers="mcps1.1.3.1.2 "><p id="p20577181420364"><a name="p20577181420364"></a><a name="p20577181420364"></a>Promise回调返回设置成功或失败。</p>
</td>
</tr>
</tbody>
</table>

**示例：**

```
audioManager.setRingerMode(audio.AudioRingMode.RINGER_MODE_NORMAL).then(() =>
    console.log('Promise returned to indicate a successful setting of the ringer mode.');
)
```

### getRingerMode\(callback: AsyncCallback<AudioRingMode\>\): void<sup>7+</sup><a name="section149044108162"></a>

获取铃声模式，使用callback方式返回异步结果。

**参数：**

<a name="table139051710191611"></a>
<table><thead align="left"><tr id="row6905910101619"><th class="cellrowborder" valign="top" width="17.57%" id="mcps1.1.5.1.1"><p id="p67261514145710"><a name="p67261514145710"></a><a name="p67261514145710"></a>参数名</p>
</th>
<th class="cellrowborder" valign="top" width="22.71%" id="mcps1.1.5.1.2"><p id="p177261314145713"><a name="p177261314145713"></a><a name="p177261314145713"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="9.8%" id="mcps1.1.5.1.3"><p id="p1672610143573"><a name="p1672610143573"></a><a name="p1672610143573"></a>必填</p>
</th>
<th class="cellrowborder" valign="top" width="49.919999999999995%" id="mcps1.1.5.1.4"><p id="p27268142573"><a name="p27268142573"></a><a name="p27268142573"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="row690717102164"><td class="cellrowborder" valign="top" width="17.57%" headers="mcps1.1.5.1.1 "><p id="p2907191071616"><a name="p2907191071616"></a><a name="p2907191071616"></a>callback</p>
</td>
<td class="cellrowborder" valign="top" width="22.71%" headers="mcps1.1.5.1.2 "><p id="p1490712109166"><a name="p1490712109166"></a><a name="p1490712109166"></a>AsyncCallback&lt;AudioRingMode&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="9.8%" headers="mcps1.1.5.1.3 "><p id="p12907181051618"><a name="p12907181051618"></a><a name="p12907181051618"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="49.919999999999995%" headers="mcps1.1.5.1.4 "><p id="p1890771019169"><a name="p1890771019169"></a><a name="p1890771019169"></a>回调返回系统的铃声模式。</p>
</td>
</tr>
</tbody>
</table>

**返回值：**

无

**示例：**

```
audioManager.getRingerMode((err, value) => {
   if (err) {
	   console.error('Failed to obtain the ringer mode.​ ${err.message}');
	   return;
   }
   console.log('Callback invoked to indicate that the ringer mode is obtained.' + value);
})
```

### getRingerMode\(\): Promise<AudioRingMode\><sup>7+</sup><a name="section13908210101620"></a>

获取铃声模式，使用promise方式返回异步结果。

**参数：**

无

**返回值：**

<a name="table59092010111611"></a>
<table><thead align="left"><tr id="row1290901017161"><th class="cellrowborder" valign="top" width="25.97%" id="mcps1.1.3.1.1"><p id="p138856135611"><a name="p138856135611"></a><a name="p138856135611"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="74.03%" id="mcps1.1.3.1.2"><p id="p03899675614"><a name="p03899675614"></a><a name="p03899675614"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="row14910121071610"><td class="cellrowborder" valign="top" width="25.97%" headers="mcps1.1.3.1.1 "><p id="p191031031611"><a name="p191031031611"></a><a name="p191031031611"></a>Promise&lt;AudioRingerMode&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="74.03%" headers="mcps1.1.3.1.2 "><p id="p17910141021611"><a name="p17910141021611"></a><a name="p17910141021611"></a>Promise回调返回系统的铃声模式。</p>
</td>
</tr>
</tbody>
</table>

**示例：**

```
audioManager.getRingerMode().then((value) =>
    console.log('Promise returned to indicate that the ringer mode is obtained.' + value);
)
```

### setAudioParameter\(key: string, value: string, callback: AsyncCallback<void\>\): void<sup>7+</sup><a name="section1691957174818"></a>

音频参数设置，使用callback方式返回异步结果。

**参数：**

<a name="table59175774814"></a>
<table><thead align="left"><tr id="row31075754816"><th class="cellrowborder" valign="top" width="17.57%" id="mcps1.1.5.1.1"><p id="p134771411145711"><a name="p134771411145711"></a><a name="p134771411145711"></a>参数名</p>
</th>
<th class="cellrowborder" valign="top" width="19.52%" id="mcps1.1.5.1.2"><p id="p64779113577"><a name="p64779113577"></a><a name="p64779113577"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="9.08%" id="mcps1.1.5.1.3"><p id="p14477311155717"><a name="p14477311155717"></a><a name="p14477311155717"></a>必填</p>
</th>
<th class="cellrowborder" valign="top" width="53.83%" id="mcps1.1.5.1.4"><p id="p1347701112574"><a name="p1347701112574"></a><a name="p1347701112574"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="row1210257154813"><td class="cellrowborder" valign="top" width="17.57%" headers="mcps1.1.5.1.1 "><p id="p310105784818"><a name="p310105784818"></a><a name="p310105784818"></a>key</p>
</td>
<td class="cellrowborder" valign="top" width="19.52%" headers="mcps1.1.5.1.2 "><p id="p1438102417524"><a name="p1438102417524"></a><a name="p1438102417524"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="9.08%" headers="mcps1.1.5.1.3 "><p id="p811195717481"><a name="p811195717481"></a><a name="p811195717481"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="53.83%" headers="mcps1.1.5.1.4 "><p id="p10117574484"><a name="p10117574484"></a><a name="p10117574484"></a>被设置的音频参数的键。</p>
</td>
</tr>
<tr id="row16111057124817"><td class="cellrowborder" valign="top" width="17.57%" headers="mcps1.1.5.1.1 "><p id="p1159793235211"><a name="p1159793235211"></a><a name="p1159793235211"></a>value</p>
</td>
<td class="cellrowborder" valign="top" width="19.52%" headers="mcps1.1.5.1.2 "><p id="p19461139165212"><a name="p19461139165212"></a><a name="p19461139165212"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="9.08%" headers="mcps1.1.5.1.3 "><p id="p91155718487"><a name="p91155718487"></a><a name="p91155718487"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="53.83%" headers="mcps1.1.5.1.4 "><p id="p13111157164816"><a name="p13111157164816"></a><a name="p13111157164816"></a>被设置的音频参数的值。</p>
</td>
</tr>
<tr id="row611205754810"><td class="cellrowborder" valign="top" width="17.57%" headers="mcps1.1.5.1.1 "><p id="p31235754812"><a name="p31235754812"></a><a name="p31235754812"></a>callback</p>
</td>
<td class="cellrowborder" valign="top" width="19.52%" headers="mcps1.1.5.1.2 "><p id="p11255718483"><a name="p11255718483"></a><a name="p11255718483"></a>AsyncCallback&lt;void&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="9.08%" headers="mcps1.1.5.1.3 "><p id="p101255744812"><a name="p101255744812"></a><a name="p101255744812"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="53.83%" headers="mcps1.1.5.1.4 "><p id="p91220576488"><a name="p91220576488"></a><a name="p91220576488"></a>回调返回设置成功或失败。</p>
</td>
</tr>
</tbody>
</table>

**返回值：**

无

**示例：**

```
audioManager.setAudioParameter('PBits per sample', '8 bit', (err) => {
    if (err) {
        console.error('Failed to set the audio parameter. ${err.message}');
	return;
    }
    console.log('Callback invoked to indicate a successful setting of the audio parameter.');
})
```

### setAudioParameter\(key: string, value: string\): Promise<void\><sup>7+</sup><a name="section18121057174820"></a>

音频参数设置，使用promise方式返回异步结果。

**参数：**

<a name="table18121957164810"></a>
<table><thead align="left"><tr id="row1139578486"><th class="cellrowborder" valign="top" width="17.599999999999998%" id="mcps1.1.5.1.1"><p id="p658416785710"><a name="p658416785710"></a><a name="p658416785710"></a>参数名</p>
</th>
<th class="cellrowborder" valign="top" width="19.49%" id="mcps1.1.5.1.2"><p id="p175849775719"><a name="p175849775719"></a><a name="p175849775719"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="9.78%" id="mcps1.1.5.1.3"><p id="p4584578579"><a name="p4584578579"></a><a name="p4584578579"></a>必填</p>
</th>
<th class="cellrowborder" valign="top" width="53.13%" id="mcps1.1.5.1.4"><p id="p10585577570"><a name="p10585577570"></a><a name="p10585577570"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="row1113125710483"><td class="cellrowborder" valign="top" width="17.599999999999998%" headers="mcps1.1.5.1.1 "><p id="p1421211251605"><a name="p1421211251605"></a><a name="p1421211251605"></a>key</p>
</td>
<td class="cellrowborder" valign="top" width="19.49%" headers="mcps1.1.5.1.2 "><p id="p15212725503"><a name="p15212725503"></a><a name="p15212725503"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="9.78%" headers="mcps1.1.5.1.3 "><p id="p52122259012"><a name="p52122259012"></a><a name="p52122259012"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="53.13%" headers="mcps1.1.5.1.4 "><p id="p1747016545595"><a name="p1747016545595"></a><a name="p1747016545595"></a>被设置的音频参数的键。</p>
</td>
</tr>
<tr id="row914185716488"><td class="cellrowborder" valign="top" width="17.599999999999998%" headers="mcps1.1.5.1.1 "><p id="p1931324215016"><a name="p1931324215016"></a><a name="p1931324215016"></a>value</p>
</td>
<td class="cellrowborder" valign="top" width="19.49%" headers="mcps1.1.5.1.2 "><p id="p9313164219015"><a name="p9313164219015"></a><a name="p9313164219015"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="9.78%" headers="mcps1.1.5.1.3 "><p id="p931316429017"><a name="p931316429017"></a><a name="p931316429017"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="53.13%" headers="mcps1.1.5.1.4 "><p id="p1231310421203"><a name="p1231310421203"></a><a name="p1231310421203"></a>被设置的音频参数的值。</p>
</td>
</tr>
</tbody>
</table>

**返回值：**

<a name="table1514135774811"></a>
<table><thead align="left"><tr id="row16141857164818"><th class="cellrowborder" valign="top" width="26.06%" id="mcps1.1.3.1.1"><p id="p1847161019561"><a name="p1847161019561"></a><a name="p1847161019561"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="73.94%" id="mcps1.1.3.1.2"><p id="p7847161018562"><a name="p7847161018562"></a><a name="p7847161018562"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="row1815185711489"><td class="cellrowborder" valign="top" width="26.06%" headers="mcps1.1.3.1.1 "><p id="p8151957184816"><a name="p8151957184816"></a><a name="p8151957184816"></a>Promise&lt;void&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="73.94%" headers="mcps1.1.3.1.2 "><p id="p41511577486"><a name="p41511577486"></a><a name="p41511577486"></a>Promise回调返回设置成功或失败。</p>
</td>
</tr>
</tbody>
</table>

**示例：**

```
audioManager.setAudioParameter('PBits per sample', '8 bit').then(() =>
    console.log('Promise returned to indicate a successful setting of the audio parameter.');
)
```

### getAudioParameter\(key: string, callback: AsyncCallback<string\>\): void<sup>7+</sup><a name="section1415145714812"></a>

获取指定音频参数值，使用callback方式返回异步结果。

**参数：**

<a name="table1315657114817"></a>
<table><thead align="left"><tr id="row181517574489"><th class="cellrowborder" valign="top" width="17.57%" id="mcps1.1.5.1.1"><p id="p1023712411572"><a name="p1023712411572"></a><a name="p1023712411572"></a>参数名</p>
</th>
<th class="cellrowborder" valign="top" width="19.52%" id="mcps1.1.5.1.2"><p id="p16238124125713"><a name="p16238124125713"></a><a name="p16238124125713"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="9.17%" id="mcps1.1.5.1.3"><p id="p1623811419574"><a name="p1623811419574"></a><a name="p1623811419574"></a>必填</p>
</th>
<th class="cellrowborder" valign="top" width="53.74%" id="mcps1.1.5.1.4"><p id="p82387411579"><a name="p82387411579"></a><a name="p82387411579"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="row616115754814"><td class="cellrowborder" valign="top" width="17.57%" headers="mcps1.1.5.1.1 "><p id="p5220105915810"><a name="p5220105915810"></a><a name="p5220105915810"></a>key</p>
</td>
<td class="cellrowborder" valign="top" width="19.52%" headers="mcps1.1.5.1.2 "><p id="p1722019593812"><a name="p1722019593812"></a><a name="p1722019593812"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="9.17%" headers="mcps1.1.5.1.3 "><p id="p82209596816"><a name="p82209596816"></a><a name="p82209596816"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="53.74%" headers="mcps1.1.5.1.4 "><p id="p11261642604"><a name="p11261642604"></a><a name="p11261642604"></a>待获取的音频参数的键。</p>
</td>
</tr>
<tr id="row61715714487"><td class="cellrowborder" valign="top" width="17.57%" headers="mcps1.1.5.1.1 "><p id="p1517145710486"><a name="p1517145710486"></a><a name="p1517145710486"></a>callback</p>
</td>
<td class="cellrowborder" valign="top" width="19.52%" headers="mcps1.1.5.1.2 "><p id="p141715713486"><a name="p141715713486"></a><a name="p141715713486"></a>AsyncCallback&lt;string&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="9.17%" headers="mcps1.1.5.1.3 "><p id="p21785718487"><a name="p21785718487"></a><a name="p21785718487"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="53.74%" headers="mcps1.1.5.1.4 "><p id="p91715719485"><a name="p91715719485"></a><a name="p91715719485"></a>回调返回获取的音频参数的值。</p>
</td>
</tr>
</tbody>
</table>

**返回值：**

无

**示例：**

```
audioManager.getAudioParameter('PBits per sample', (err, value) => {
    if (err) {
        console.error('Failed to obtain the value of the audio parameter. ${err.message}');
	return;
    }
    console.log('Callback invoked to indicate that the value of the audio parameter is obtained.' + value);
})
```

### getAudioParameter\(key: string\): Promise<string\><sup>7+</sup><a name="section3185577485"></a>

获取指定音频参数值，使用promise方式返回异步结果。

**参数：**

<a name="table5180572488"></a>
<table><thead align="left"><tr id="row111885714815"><th class="cellrowborder" valign="top" width="17.57%" id="mcps1.1.5.1.1"><p id="p51148120574"><a name="p51148120574"></a><a name="p51148120574"></a>参数名</p>
</th>
<th class="cellrowborder" valign="top" width="19.52%" id="mcps1.1.5.1.2"><p id="p111142175720"><a name="p111142175720"></a><a name="p111142175720"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="9.42%" id="mcps1.1.5.1.3"><p id="p151141145717"><a name="p151141145717"></a><a name="p151141145717"></a>必填</p>
</th>
<th class="cellrowborder" valign="top" width="53.49%" id="mcps1.1.5.1.4"><p id="p1111410195711"><a name="p1111410195711"></a><a name="p1111410195711"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="row1519105784811"><td class="cellrowborder" valign="top" width="17.57%" headers="mcps1.1.5.1.1 "><p id="p7988114714123"><a name="p7988114714123"></a><a name="p7988114714123"></a>key</p>
</td>
<td class="cellrowborder" valign="top" width="19.52%" headers="mcps1.1.5.1.2 "><p id="p149881947161218"><a name="p149881947161218"></a><a name="p149881947161218"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="9.42%" headers="mcps1.1.5.1.3 "><p id="p1798812477124"><a name="p1798812477124"></a><a name="p1798812477124"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="53.49%" headers="mcps1.1.5.1.4 "><p id="p1860910215116"><a name="p1860910215116"></a><a name="p1860910215116"></a>待获取的音频参数的键。</p>
</td>
</tr>
</tbody>
</table>

**返回值：**

<a name="table152065754818"></a>
<table><thead align="left"><tr id="row10201357184813"><th class="cellrowborder" valign="top" width="25.97%" id="mcps1.1.3.1.1"><p id="p11727422165616"><a name="p11727422165616"></a><a name="p11727422165616"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="74.03%" id="mcps1.1.3.1.2"><p id="p5727922155611"><a name="p5727922155611"></a><a name="p5727922155611"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="row8207572485"><td class="cellrowborder" valign="top" width="25.97%" headers="mcps1.1.3.1.1 "><p id="p22155774819"><a name="p22155774819"></a><a name="p22155774819"></a>Promise&lt;string&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="74.03%" headers="mcps1.1.3.1.2 "><p id="p1121155704810"><a name="p1121155704810"></a><a name="p1121155704810"></a>Promise回调返回获取的音频参数的值。</p>
</td>
</tr>
</tbody>
</table>

**示例：**

```
audioManager.getAudioParameter('PBits per sample').then((value) =>
    console.log('Promise returned to indicate that the value of the audio parameter is obtained.' + value);
)
```

### getDevices\(deviceFlag: DeviceFlag, callback: AsyncCallback<AudioDeviceDescriptors\>\): void<a name="section11536182020523"></a>

获取音频设备列表，使用callback方式返回异步结果。

**参数：**

<a name="table8653191616249"></a>
<table><thead align="left"><tr id="row165412169245"><th class="cellrowborder" valign="top" width="17.57%" id="mcps1.1.5.1.1"><p id="p1665412161243"><a name="p1665412161243"></a><a name="p1665412161243"></a>参数名</p>
</th>
<th class="cellrowborder" valign="top" width="21%" id="mcps1.1.5.1.2"><p id="p1765491672417"><a name="p1765491672417"></a><a name="p1765491672417"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="12.78%" id="mcps1.1.5.1.3"><p id="p113067111209"><a name="p113067111209"></a><a name="p113067111209"></a>必填</p>
</th>
<th class="cellrowborder" valign="top" width="48.65%" id="mcps1.1.5.1.4"><p id="p765431682419"><a name="p765431682419"></a><a name="p765431682419"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="row1654191652419"><td class="cellrowborder" valign="top" width="17.57%" headers="mcps1.1.5.1.1 "><p id="p126549165241"><a name="p126549165241"></a><a name="p126549165241"></a>deviceFlag</p>
</td>
<td class="cellrowborder" valign="top" width="21%" headers="mcps1.1.5.1.2 "><p id="p8654141622416"><a name="p8654141622416"></a><a name="p8654141622416"></a><a href="#section11285183164210">DeviceFlag</a></p>
</td>
<td class="cellrowborder" valign="top" width="12.78%" headers="mcps1.1.5.1.3 "><p id="p830651111019"><a name="p830651111019"></a><a name="p830651111019"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="48.65%" headers="mcps1.1.5.1.4 "><p id="p10654131616248"><a name="p10654131616248"></a><a name="p10654131616248"></a>设备类型的flag。</p>
</td>
</tr>
<tr id="row16544162243"><td class="cellrowborder" valign="top" width="17.57%" headers="mcps1.1.5.1.1 "><p id="p176541316122412"><a name="p176541316122412"></a><a name="p176541316122412"></a>callback</p>
</td>
<td class="cellrowborder" valign="top" width="21%" headers="mcps1.1.5.1.2 "><p id="p1565461620244"><a name="p1565461620244"></a><a name="p1565461620244"></a>AsyncCallback&lt;<a href="#section5181155710523">AudioDeviceDescriptors</a>&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="12.78%" headers="mcps1.1.5.1.3 "><p id="p2307711908"><a name="p2307711908"></a><a name="p2307711908"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="48.65%" headers="mcps1.1.5.1.4 "><p id="p19654141672416"><a name="p19654141672416"></a><a name="p19654141672416"></a>回调，返回设备列表。</p>
</td>
</tr>
</tbody>
</table>

**示例：**

```
audioManager.getDevices(audio.DeviceFlag.OUTPUT_DEVICES_FLAG, (err, value)=>{
   if (err) {
	   console.error('Failed to obtain the device list. ${err.message}');
	   return;
   }
   console.log('Callback invoked to indicate that the device list is obtained.');
})
```

### getDevices\(deviceFlag: DeviceFlag\): Promise<AudioDeviceDescriptors\><a name="section181733125210"></a>

获取音频设备列表，使用promise方式返回异步结果。

**参数：**

<a name="table17655516132411"></a>
<table><thead align="left"><tr id="row4655616192414"><th class="cellrowborder" valign="top" width="17.57%" id="mcps1.1.5.1.1"><p id="p1465518164247"><a name="p1465518164247"></a><a name="p1465518164247"></a>参数名</p>
</th>
<th class="cellrowborder" valign="top" width="19.52%" id="mcps1.1.5.1.2"><p id="p196551316172415"><a name="p196551316172415"></a><a name="p196551316172415"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="7.5200000000000005%" id="mcps1.1.5.1.3"><p id="p13161629902"><a name="p13161629902"></a><a name="p13161629902"></a>必填</p>
</th>
<th class="cellrowborder" valign="top" width="55.38999999999999%" id="mcps1.1.5.1.4"><p id="p17655616102417"><a name="p17655616102417"></a><a name="p17655616102417"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="row13656111662415"><td class="cellrowborder" valign="top" width="17.57%" headers="mcps1.1.5.1.1 "><p id="p2092935211270"><a name="p2092935211270"></a><a name="p2092935211270"></a>deviceFlag</p>
</td>
<td class="cellrowborder" valign="top" width="19.52%" headers="mcps1.1.5.1.2 "><p id="p88719299489"><a name="p88719299489"></a><a name="p88719299489"></a><a href="#section11285183164210">DeviceFlag</a></p>
</td>
<td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.5.1.3 "><p id="p12161129209"><a name="p12161129209"></a><a name="p12161129209"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="55.38999999999999%" headers="mcps1.1.5.1.4 "><p id="p1692985222710"><a name="p1692985222710"></a><a name="p1692985222710"></a>设备类型的flag。</p>
</td>
</tr>
</tbody>
</table>

**返回值：**

<a name="table565618166249"></a>
<table><thead align="left"><tr id="row19656151662410"><th class="cellrowborder" valign="top" width="26.02%" id="mcps1.1.3.1.1"><p id="p15656916152415"><a name="p15656916152415"></a><a name="p15656916152415"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="73.98%" id="mcps1.1.3.1.2"><p id="p365641616247"><a name="p365641616247"></a><a name="p365641616247"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="row665681617243"><td class="cellrowborder" valign="top" width="26.02%" headers="mcps1.1.3.1.1 "><p id="p5673192162816"><a name="p5673192162816"></a><a name="p5673192162816"></a>Promise&lt;<a href="#section5181155710523">AudioDeviceDescriptors</a>&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="73.98%" headers="mcps1.1.3.1.2 "><p id="p765751610249"><a name="p765751610249"></a><a name="p765751610249"></a>Promise回调返回设备列表。</p>
</td>
</tr>
</tbody>
</table>

**示例：**

```
audioManager.getDevices(audio.DeviceFlag.OUTPUT_DEVICES_FLAG).then((data)=>
    console.log('Promise returned to indicate that the device list is obtained.');
)
```

### setDeviceActive\(deviceType: ActiveDeviceType, active: boolean, callback: AsyncCallback<void\>\): void<sup>7+</sup><a name="section103558400222"></a>

设置设备激活状态，使用callback方式返回异步结果。

**参数：**

<a name="table5355740142213"></a>
<table><thead align="left"><tr id="row133561640192217"><th class="cellrowborder" valign="top" width="17.57%" id="mcps1.1.5.1.1"><p id="p41511817185812"><a name="p41511817185812"></a><a name="p41511817185812"></a>参数名</p>
</th>
<th class="cellrowborder" valign="top" width="19.52%" id="mcps1.1.5.1.2"><p id="p1415119175583"><a name="p1415119175583"></a><a name="p1415119175583"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="9.78%" id="mcps1.1.5.1.3"><p id="p16151171720587"><a name="p16151171720587"></a><a name="p16151171720587"></a>必填</p>
</th>
<th class="cellrowborder" valign="top" width="53.13%" id="mcps1.1.5.1.4"><p id="p141511117195811"><a name="p141511117195811"></a><a name="p141511117195811"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="row15356174052213"><td class="cellrowborder" valign="top" width="17.57%" headers="mcps1.1.5.1.1 "><p id="p6356240182212"><a name="p6356240182212"></a><a name="p6356240182212"></a>deviceType</p>
</td>
<td class="cellrowborder" valign="top" width="19.52%" headers="mcps1.1.5.1.2 "><p id="p1982716244344"><a name="p1982716244344"></a><a name="p1982716244344"></a><a href="#section11727420122710">ActiveDeviceType</a></p>
</td>
<td class="cellrowborder" valign="top" width="9.78%" headers="mcps1.1.5.1.3 "><p id="p035794062216"><a name="p035794062216"></a><a name="p035794062216"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="53.13%" headers="mcps1.1.5.1.4 "><p id="p166271345204414"><a name="p166271345204414"></a><a name="p166271345204414"></a>音频设备类型。</p>
</td>
</tr>
<tr id="row1635713409226"><td class="cellrowborder" valign="top" width="17.57%" headers="mcps1.1.5.1.1 "><p id="p268924403311"><a name="p268924403311"></a><a name="p268924403311"></a>active</p>
</td>
<td class="cellrowborder" valign="top" width="19.52%" headers="mcps1.1.5.1.2 "><p id="p5357104032210"><a name="p5357104032210"></a><a name="p5357104032210"></a>boolean</p>
</td>
<td class="cellrowborder" valign="top" width="9.78%" headers="mcps1.1.5.1.3 "><p id="p635764012218"><a name="p635764012218"></a><a name="p635764012218"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="53.13%" headers="mcps1.1.5.1.4 "><p id="p1357124052217"><a name="p1357124052217"></a><a name="p1357124052217"></a>设备激活状态。</p>
</td>
</tr>
<tr id="row133581840102212"><td class="cellrowborder" valign="top" width="17.57%" headers="mcps1.1.5.1.1 "><p id="p03581340182212"><a name="p03581340182212"></a><a name="p03581340182212"></a>callback</p>
</td>
<td class="cellrowborder" valign="top" width="19.52%" headers="mcps1.1.5.1.2 "><p id="p3358204011223"><a name="p3358204011223"></a><a name="p3358204011223"></a>AsyncCallback&lt;void&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="9.78%" headers="mcps1.1.5.1.3 "><p id="p10358124014222"><a name="p10358124014222"></a><a name="p10358124014222"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="53.13%" headers="mcps1.1.5.1.4 "><p id="p13358540132217"><a name="p13358540132217"></a><a name="p13358540132217"></a>回调返回设置成功或失败。</p>
</td>
</tr>
</tbody>
</table>

**返回值：**

无

**示例：**

```
audioManager.setDeviceActive(audio.ActiveDeviceType.SPEAKER, true, (err)=> {
    if (err) {
        console.error('Failed to set the active status of the device. ${err.message}');
	return;
    }
    console.log('Callback invoked to indicate that the device is set to the active status.');
})
```

### setDeviceActive\(deviceType: ActiveDeviceType, active: boolean\): Promise<void\><sup>7+</sup><a name="section1235914401228"></a>

设置设备激活状态，使用promise方式返回异步结果。

**参数：**

<a name="table1335914018225"></a>
<table><thead align="left"><tr id="row103598403228"><th class="cellrowborder" valign="top" width="17.599999999999998%" id="mcps1.1.5.1.1"><p id="p5120161465816"><a name="p5120161465816"></a><a name="p5120161465816"></a>参数名</p>
</th>
<th class="cellrowborder" valign="top" width="19.49%" id="mcps1.1.5.1.2"><p id="p6120121420586"><a name="p6120121420586"></a><a name="p6120121420586"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="7.5200000000000005%" id="mcps1.1.5.1.3"><p id="p412015148583"><a name="p412015148583"></a><a name="p412015148583"></a>必填</p>
</th>
<th class="cellrowborder" valign="top" width="55.38999999999999%" id="mcps1.1.5.1.4"><p id="p14120111417585"><a name="p14120111417585"></a><a name="p14120111417585"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="row6360124010225"><td class="cellrowborder" valign="top" width="17.599999999999998%" headers="mcps1.1.5.1.1 "><p id="p21049584484"><a name="p21049584484"></a><a name="p21049584484"></a>deviceType</p>
</td>
<td class="cellrowborder" valign="top" width="19.49%" headers="mcps1.1.5.1.2 "><p id="p98241474910"><a name="p98241474910"></a><a name="p98241474910"></a><a href="#section11727420122710">ActiveDeviceType</a></p>
</td>
<td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.5.1.3 "><p id="p103601240202216"><a name="p103601240202216"></a><a name="p103601240202216"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="55.38999999999999%" headers="mcps1.1.5.1.4 "><p id="p173618402226"><a name="p173618402226"></a><a name="p173618402226"></a>音频设备类型。</p>
</td>
</tr>
<tr id="row10361104018222"><td class="cellrowborder" valign="top" width="17.599999999999998%" headers="mcps1.1.5.1.1 "><p id="p280718578504"><a name="p280718578504"></a><a name="p280718578504"></a>active</p>
</td>
<td class="cellrowborder" valign="top" width="19.49%" headers="mcps1.1.5.1.2 "><p id="p103615400229"><a name="p103615400229"></a><a name="p103615400229"></a>boolean</p>
</td>
<td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.5.1.3 "><p id="p936154082210"><a name="p936154082210"></a><a name="p936154082210"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="55.38999999999999%" headers="mcps1.1.5.1.4 "><p id="p280510397459"><a name="p280510397459"></a><a name="p280510397459"></a>设备激活状态。</p>
</td>
</tr>
</tbody>
</table>

**返回值：**

<a name="table636154016223"></a>
<table><thead align="left"><tr id="row17362540112218"><th class="cellrowborder" valign="top" width="26.06%" id="mcps1.1.3.1.1"><p id="p78801632195618"><a name="p78801632195618"></a><a name="p78801632195618"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="73.94%" id="mcps1.1.3.1.2"><p id="p1688043265614"><a name="p1688043265614"></a><a name="p1688043265614"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="row143621940142213"><td class="cellrowborder" valign="top" width="26.06%" headers="mcps1.1.3.1.1 "><p id="p236215405225"><a name="p236215405225"></a><a name="p236215405225"></a>Promise&lt;void&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="73.94%" headers="mcps1.1.3.1.2 "><p id="p536214032220"><a name="p536214032220"></a><a name="p536214032220"></a>Promise回调返回设置成功或失败。</p>
</td>
</tr>
</tbody>
</table>

**示例：**

```
audioManager.setDeviceActive(audio.ActiveDeviceType.SPEAKER, true).then(()=>
    console.log('Promise returned to indicate that the device is set to the active status.');
)
```

### isDeviceActive\(deviceType: DeviceType, callback: AsyncCallback<boolean\>\): void<sup>7+</sup><a name="section12363240122219"></a>

获取指定设备激活状态，使用callback方式返回异步结果。

**参数：**

<a name="table13638406221"></a>
<table><thead align="left"><tr id="row15363840122216"><th class="cellrowborder" valign="top" width="17.57%" id="mcps1.1.5.1.1"><p id="p18980131114586"><a name="p18980131114586"></a><a name="p18980131114586"></a>参数名</p>
</th>
<th class="cellrowborder" valign="top" width="19.52%" id="mcps1.1.5.1.2"><p id="p16980161145817"><a name="p16980161145817"></a><a name="p16980161145817"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="9.25%" id="mcps1.1.5.1.3"><p id="p5980121165813"><a name="p5980121165813"></a><a name="p5980121165813"></a>必填</p>
</th>
<th class="cellrowborder" valign="top" width="53.66%" id="mcps1.1.5.1.4"><p id="p149802111588"><a name="p149802111588"></a><a name="p149802111588"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="row1536417409223"><td class="cellrowborder" valign="top" width="17.57%" headers="mcps1.1.5.1.1 "><p id="p12364174016224"><a name="p12364174016224"></a><a name="p12364174016224"></a>deviceType</p>
</td>
<td class="cellrowborder" valign="top" width="19.52%" headers="mcps1.1.5.1.2 "><p id="p1779218497578"><a name="p1779218497578"></a><a name="p1779218497578"></a><a href="#section11727420122710">ActiveDeviceType</a></p>
</td>
<td class="cellrowborder" valign="top" width="9.25%" headers="mcps1.1.5.1.3 "><p id="p122111521127"><a name="p122111521127"></a><a name="p122111521127"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="53.66%" headers="mcps1.1.5.1.4 "><p id="p4364640122219"><a name="p4364640122219"></a><a name="p4364640122219"></a>音频设备类型。</p>
</td>
</tr>
<tr id="row11365174011226"><td class="cellrowborder" valign="top" width="17.57%" headers="mcps1.1.5.1.1 "><p id="p14365144016225"><a name="p14365144016225"></a><a name="p14365144016225"></a>callback</p>
</td>
<td class="cellrowborder" valign="top" width="19.52%" headers="mcps1.1.5.1.2 "><p id="p15365104062213"><a name="p15365104062213"></a><a name="p15365104062213"></a>AsyncCallback&lt;boolean&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="9.25%" headers="mcps1.1.5.1.3 "><p id="p20365154014220"><a name="p20365154014220"></a><a name="p20365154014220"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="53.66%" headers="mcps1.1.5.1.4 "><p id="p19365154072213"><a name="p19365154072213"></a><a name="p19365154072213"></a>回调返回设备的激活状态。</p>
</td>
</tr>
</tbody>
</table>

**返回值：**

无

**示例：**

```
audioManager.isDeviceActive(audio.ActiveDeviceType.SPEAKER, (err, value) => {
    if (err) {
        console.error('Failed to obtain the active status of the device. ${err.message}');
	return;
    }
    console.log('Callback invoked to indicate that the active status of the device is obtained.');
})
```

### isDeviceActive\(deviceType: ActiveDeviceType\): Promise<boolean\><sup>7+</sup><a name="section18366184012213"></a>

获取指定设备激活状态，使用promise方式返回异步结果。

**参数：**

<a name="table10366184019222"></a>
<table><thead align="left"><tr id="row3366174012217"><th class="cellrowborder" valign="top" width="17.57%" id="mcps1.1.5.1.1"><p id="p158645818582"><a name="p158645818582"></a><a name="p158645818582"></a>参数名</p>
</th>
<th class="cellrowborder" valign="top" width="19.52%" id="mcps1.1.5.1.2"><p id="p15864158125814"><a name="p15864158125814"></a><a name="p15864158125814"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="8.99%" id="mcps1.1.5.1.3"><p id="p168649845815"><a name="p168649845815"></a><a name="p168649845815"></a>必填</p>
</th>
<th class="cellrowborder" valign="top" width="53.92%" id="mcps1.1.5.1.4"><p id="p2086413855815"><a name="p2086413855815"></a><a name="p2086413855815"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="row12367340122213"><td class="cellrowborder" valign="top" width="17.57%" headers="mcps1.1.5.1.1 "><p id="p11637137420"><a name="p11637137420"></a><a name="p11637137420"></a>deviceType</p>
</td>
<td class="cellrowborder" valign="top" width="19.52%" headers="mcps1.1.5.1.2 "><p id="p1616311136412"><a name="p1616311136412"></a><a name="p1616311136412"></a><a href="#section11727420122710">ActiveDeviceType</a></p>
</td>
<td class="cellrowborder" valign="top" width="8.99%" headers="mcps1.1.5.1.3 "><p id="p201646138419"><a name="p201646138419"></a><a name="p201646138419"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="53.92%" headers="mcps1.1.5.1.4 "><p id="p7164113246"><a name="p7164113246"></a><a name="p7164113246"></a>音频设备类型。</p>
</td>
</tr>
</tbody>
</table>

**返回值：**

<a name="table1368174012225"></a>
<table><thead align="left"><tr id="row17368164018220"><th class="cellrowborder" valign="top" width="25.97%" id="mcps1.1.3.1.1"><p id="p16368154062213"><a name="p16368154062213"></a><a name="p16368154062213"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="74.03%" id="mcps1.1.3.1.2"><p id="p1368740102218"><a name="p1368740102218"></a><a name="p1368740102218"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row8368840162213"><td class="cellrowborder" valign="top" width="25.97%" headers="mcps1.1.3.1.1 "><p id="p1436944092212"><a name="p1436944092212"></a><a name="p1436944092212"></a>Promise&lt;boolean&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="74.03%" headers="mcps1.1.3.1.2 "><p id="p113691340122217"><a name="p113691340122217"></a><a name="p113691340122217"></a>Promise回调返回设备的激活状态。</p>
</td>
</tr>
</tbody>
</table>

**示例：**

```
audioManager.isDeviceActive(audio.ActiveDeviceType.SPEAKER).then((value) =>
    console.log('Promise returned to indicate that the active status of the device is obtained.' + value);
)
```

### setMicrophoneMute\(mute: boolean, callback: AsyncCallback<void\>\): void<sup>7+</sup><a name="section14703163618122"></a>

设置麦克风静音状态，使用callback方式返回异步结果。

**参数：**

<a name="table6703123691210"></a>
<table><thead align="left"><tr id="row67041836111213"><th class="cellrowborder" valign="top" width="17.57%" id="mcps1.1.5.1.1"><p id="p25751666588"><a name="p25751666588"></a><a name="p25751666588"></a>参数名</p>
</th>
<th class="cellrowborder" valign="top" width="19.52%" id="mcps1.1.5.1.2"><p id="p12575065588"><a name="p12575065588"></a><a name="p12575065588"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="9.6%" id="mcps1.1.5.1.3"><p id="p3575136125814"><a name="p3575136125814"></a><a name="p3575136125814"></a>必填</p>
</th>
<th class="cellrowborder" valign="top" width="53.31%" id="mcps1.1.5.1.4"><p id="p55751061582"><a name="p55751061582"></a><a name="p55751061582"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="row670420363129"><td class="cellrowborder" valign="top" width="17.57%" headers="mcps1.1.5.1.1 "><p id="p17493113218156"><a name="p17493113218156"></a><a name="p17493113218156"></a>mute</p>
</td>
<td class="cellrowborder" valign="top" width="19.52%" headers="mcps1.1.5.1.2 "><p id="p519017106151"><a name="p519017106151"></a><a name="p519017106151"></a>boolean</p>
</td>
<td class="cellrowborder" valign="top" width="9.6%" headers="mcps1.1.5.1.3 "><p id="p6705103681214"><a name="p6705103681214"></a><a name="p6705103681214"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="53.31%" headers="mcps1.1.5.1.4 "><p id="p1953244311156"><a name="p1953244311156"></a><a name="p1953244311156"></a>待设置的静音状态，true为静音，false为非静音。</p>
</td>
</tr>
<tr id="row9705103671212"><td class="cellrowborder" valign="top" width="17.57%" headers="mcps1.1.5.1.1 "><p id="p14705436191218"><a name="p14705436191218"></a><a name="p14705436191218"></a>callback</p>
</td>
<td class="cellrowborder" valign="top" width="19.52%" headers="mcps1.1.5.1.2 "><p id="p270593617126"><a name="p270593617126"></a><a name="p270593617126"></a>AsyncCallback&lt;void&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="9.6%" headers="mcps1.1.5.1.3 "><p id="p1570573621213"><a name="p1570573621213"></a><a name="p1570573621213"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="53.31%" headers="mcps1.1.5.1.4 "><p id="p19706103612122"><a name="p19706103612122"></a><a name="p19706103612122"></a>回调返回设置成功或失败。</p>
</td>
</tr>
</tbody>
</table>

**返回值：**

无

**示例：**

```
audioManager.setMicrophoneMute(true, (err) => {
    if (err) {
        console.error('Failed to mute the microphone. ${err.message}');
        return;
    }
    console.log('Callback invoked to indicate that the microphone is muted.');
})
```

### setMicrophoneMute\(mute: boolean\): Promise<void\><sup>7+</sup><a name="section56287111791"></a>

设置麦克风静音状态，使用promise方式返回异步结果。

**参数：**

<a name="table36281411997"></a>
<table><thead align="left"><tr id="row16629011891"><th class="cellrowborder" valign="top" width="17.599999999999998%" id="mcps1.1.5.1.1"><p id="p1853715297587"><a name="p1853715297587"></a><a name="p1853715297587"></a>参数名</p>
</th>
<th class="cellrowborder" valign="top" width="19.49%" id="mcps1.1.5.1.2"><p id="p253711297583"><a name="p253711297583"></a><a name="p253711297583"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="10.39%" id="mcps1.1.5.1.3"><p id="p95374292585"><a name="p95374292585"></a><a name="p95374292585"></a>必填</p>
</th>
<th class="cellrowborder" valign="top" width="52.52%" id="mcps1.1.5.1.4"><p id="p953722918583"><a name="p953722918583"></a><a name="p953722918583"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="row186306112918"><td class="cellrowborder" valign="top" width="17.599999999999998%" headers="mcps1.1.5.1.1 "><p id="p16482185512813"><a name="p16482185512813"></a><a name="p16482185512813"></a>mute</p>
</td>
<td class="cellrowborder" valign="top" width="19.49%" headers="mcps1.1.5.1.2 "><p id="p17482195572814"><a name="p17482195572814"></a><a name="p17482195572814"></a>boolean</p>
</td>
<td class="cellrowborder" valign="top" width="10.39%" headers="mcps1.1.5.1.3 "><p id="p54828557284"><a name="p54828557284"></a><a name="p54828557284"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="52.52%" headers="mcps1.1.5.1.4 "><p id="p5819746191515"><a name="p5819746191515"></a><a name="p5819746191515"></a>待设置的静音状态，true为静音，false为非静音。</p>
</td>
</tr>
</tbody>
</table>

**返回值：**

<a name="table1263113111593"></a>
<table><thead align="left"><tr id="row1863116111998"><th class="cellrowborder" valign="top" width="26.06%" id="mcps1.1.3.1.1"><p id="p17429547125617"><a name="p17429547125617"></a><a name="p17429547125617"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="73.94%" id="mcps1.1.3.1.2"><p id="p15429347165616"><a name="p15429347165616"></a><a name="p15429347165616"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="row19631511495"><td class="cellrowborder" valign="top" width="26.06%" headers="mcps1.1.3.1.1 "><p id="p963131110911"><a name="p963131110911"></a><a name="p963131110911"></a>Promise&lt;void&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="73.94%" headers="mcps1.1.3.1.2 "><p id="p2632911495"><a name="p2632911495"></a><a name="p2632911495"></a>Promise回调返回设置成功或失败。</p>
</td>
</tr>
</tbody>
</table>

**示例：**

```
audioManager.setMicrophoneMute(true).then(() =>
    console.log('Promise returned to indicate that the microphone is muted.');
)
```

### isMicrophoneMute\(callback: AsyncCallback<boolean\>\): void<sup>7+</sup><a name="section6632141119912"></a>

获取麦克风静音状态，使用callback方式返回异步结果。

**参数：**

<a name="table263341115910"></a>
<table><thead align="left"><tr id="row963351114915"><th class="cellrowborder" valign="top" width="17.57%" id="mcps1.1.5.1.1"><p id="p17609143285813"><a name="p17609143285813"></a><a name="p17609143285813"></a>参数名</p>
</th>
<th class="cellrowborder" valign="top" width="19.52%" id="mcps1.1.5.1.2"><p id="p1460953214582"><a name="p1460953214582"></a><a name="p1460953214582"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="8.38%" id="mcps1.1.5.1.3"><p id="p4609103219585"><a name="p4609103219585"></a><a name="p4609103219585"></a>必填</p>
</th>
<th class="cellrowborder" valign="top" width="54.53%" id="mcps1.1.5.1.4"><p id="p13609332195816"><a name="p13609332195816"></a><a name="p13609332195816"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="row863416111912"><td class="cellrowborder" valign="top" width="17.57%" headers="mcps1.1.5.1.1 "><p id="p136341311990"><a name="p136341311990"></a><a name="p136341311990"></a>callback</p>
</td>
<td class="cellrowborder" valign="top" width="19.52%" headers="mcps1.1.5.1.2 "><p id="p263413111799"><a name="p263413111799"></a><a name="p263413111799"></a>AsyncCallback&lt;boolean&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="8.38%" headers="mcps1.1.5.1.3 "><p id="p1563571116915"><a name="p1563571116915"></a><a name="p1563571116915"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="54.53%" headers="mcps1.1.5.1.4 "><p id="p7929533121617"><a name="p7929533121617"></a><a name="p7929533121617"></a>回调返回系统麦克风静音状态，true为静音，false为非静音。</p>
</td>
</tr>
</tbody>
</table>

**返回值：**

无

**示例：**

```
audioManager.isMicrophoneMute((err, value) => {
    if (err) {
        console.error('Failed to obtain the mute status of the microphone. ${err.message}');
        return;
    }
    console.log('Callback invoked to indicate that the mute status of the microphone is obtained.' + value);
})
```

### isMicrophoneMute\(\): Promise<boolean\><sup>7+</sup><a name="section196363111918"></a>

获取麦克风静音状态，使用promise方式返回异步结果。

**参数：**

无

**返回值：**

<a name="table1563618111590"></a>
<table><thead align="left"><tr id="row1563614111198"><th class="cellrowborder" valign="top" width="25.97%" id="mcps1.1.3.1.1"><p id="p4631195085616"><a name="p4631195085616"></a><a name="p4631195085616"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="74.03%" id="mcps1.1.3.1.2"><p id="p2063115065618"><a name="p2063115065618"></a><a name="p2063115065618"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="row2063711111794"><td class="cellrowborder" valign="top" width="25.97%" headers="mcps1.1.3.1.1 "><p id="p7637511798"><a name="p7637511798"></a><a name="p7637511798"></a>Promise&lt;boolean&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="74.03%" headers="mcps1.1.3.1.2 "><p id="p9637191112911"><a name="p9637191112911"></a><a name="p9637191112911"></a>Promise回调返回系统麦克风静音状态，true为静音，false为非静音。</p>
</td>
</tr>
</tbody>
</table>

**示例：**

```
audioManager.isMicrophoneMute().then((value) =>
    console.log('Promise returned to indicate that the mute status of the microphone is obtained.', + value);
)
```

## AudioDeviceDescriptor<a name="section164657411927"></a>

描述音频设备。

### 属性<a name="section4947115405"></a>

<a name="table92548495595"></a>
<table><thead align="left"><tr id="row132541749175917"><th class="cellrowborder" valign="top" width="22.65226522652265%" id="mcps1.1.6.1.1"><p id="p925404965919"><a name="p925404965919"></a><a name="p925404965919"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="17.021702170217022%" id="mcps1.1.6.1.2"><p id="p325464914599"><a name="p325464914599"></a><a name="p325464914599"></a>参数型</p>
</th>
<th class="cellrowborder" valign="top" width="8.720872087208722%" id="mcps1.1.6.1.3"><p id="p025484918596"><a name="p025484918596"></a><a name="p025484918596"></a>可读</p>
</th>
<th class="cellrowborder" valign="top" width="13.881388138813882%" id="mcps1.1.6.1.4"><p id="p025414499590"><a name="p025414499590"></a><a name="p025414499590"></a>可写</p>
</th>
<th class="cellrowborder" valign="top" width="37.72377237723772%" id="mcps1.1.6.1.5"><p id="p20254134925912"><a name="p20254134925912"></a><a name="p20254134925912"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="row18254849155915"><td class="cellrowborder" valign="top" width="22.65226522652265%" headers="mcps1.1.6.1.1 "><p id="p4909151512710"><a name="p4909151512710"></a><a name="p4909151512710"></a>deviceRole</p>
</td>
<td class="cellrowborder" valign="top" width="17.021702170217022%" headers="mcps1.1.6.1.2 "><p id="p262713618564"><a name="p262713618564"></a><a name="p262713618564"></a><a href="#section380038142619">DeviceRole</a></p>
</td>
<td class="cellrowborder" valign="top" width="8.720872087208722%" headers="mcps1.1.6.1.3 "><p id="p8254749195914"><a name="p8254749195914"></a><a name="p8254749195914"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="13.881388138813882%" headers="mcps1.1.6.1.4 "><p id="p5255549115910"><a name="p5255549115910"></a><a name="p5255549115910"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="37.72377237723772%" headers="mcps1.1.6.1.5 "><p id="p11973171511560"><a name="p11973171511560"></a><a name="p11973171511560"></a>设备角色。</p>
</td>
</tr>
<tr id="row3558145812553"><td class="cellrowborder" valign="top" width="22.65226522652265%" headers="mcps1.1.6.1.1 "><p id="p1155815580552"><a name="p1155815580552"></a><a name="p1155815580552"></a>deviceType</p>
</td>
<td class="cellrowborder" valign="top" width="17.021702170217022%" headers="mcps1.1.6.1.2 "><p id="p5558165811550"><a name="p5558165811550"></a><a name="p5558165811550"></a><a href="#section11727420122710">DeviceType</a></p>
</td>
<td class="cellrowborder" valign="top" width="8.720872087208722%" headers="mcps1.1.6.1.3 "><p id="p17539151215617"><a name="p17539151215617"></a><a name="p17539151215617"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="13.881388138813882%" headers="mcps1.1.6.1.4 "><p id="p85391712105612"><a name="p85391712105612"></a><a name="p85391712105612"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="37.72377237723772%" headers="mcps1.1.6.1.5 "><p id="p525718188565"><a name="p525718188565"></a><a name="p525718188565"></a>设备类型。</p>
</td>
</tr>
</tbody>
</table>

## AudioDeviceDescriptors<a name="section5181155710523"></a>

<a name="table169751229266"></a>
<table><thead align="left"><tr id="row169757224268"><th class="cellrowborder" valign="top" width="19.7%" id="mcps1.1.3.1.1"><p id="p19975182202612"><a name="p19975182202612"></a><a name="p19975182202612"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="80.30000000000001%" id="mcps1.1.3.1.2"><p id="p109751622132611"><a name="p109751622132611"></a><a name="p109751622132611"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row169751322182613"><td class="cellrowborder" valign="top" width="19.7%" headers="mcps1.1.3.1.1 "><p id="p139751522182616"><a name="p139751522182616"></a><a name="p139751522182616"></a>设备属性数组</p>
</td>
<td class="cellrowborder" valign="top" width="80.30000000000001%" headers="mcps1.1.3.1.2 "><p id="p597532272616"><a name="p597532272616"></a><a name="p597532272616"></a>AudioDeviceDescriptor的数组，只读。</p>
</td>
</tr>
</tbody>
</table>

