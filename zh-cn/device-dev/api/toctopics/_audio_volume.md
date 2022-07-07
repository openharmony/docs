# AudioVolume<a name="ZH-CN_TOPIC_0000001343000845"></a>

## **概述**<a name="section992094052083931"></a>

**所属模块:**

[Audio](_audio.md)

## **汇总**<a name="section1989389132083931"></a>

## Public 属性<a name="pub-attribs"></a>

<a name="table1130029350083931"></a>
<table><thead align="left"><tr id="row1624193198083931"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p2138925417083931"><a name="p2138925417083931"></a><a name="p2138925417083931"></a>Public 属性</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1236028813083931"><a name="p1236028813083931"></a><a name="p1236028813083931"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row1586817913083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1522649487083931"><a name="p1522649487083931"></a><a name="p1522649487083931"></a>( <a href="_audio_volume.md#a79c127fa37eb2dbf8dc5fe9f0ed4421e">SetMute</a> )(<a href="_audio.md#ga18675ddb073465fdeac33a897f675d79">AudioHandle</a> handle, bool mute)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p990264659083931"><a name="p990264659083931"></a><a name="p990264659083931"></a>设置音频的静音状态 <a href="_audio_volume.md#a79c127fa37eb2dbf8dc5fe9f0ed4421e">更多...</a></p>
</td>
</tr>
<tr id="row361746036083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p812661319083931"><a name="p812661319083931"></a><a name="p812661319083931"></a>( <a href="_audio_volume.md#a75fcb5bda7e0ca9b823187f6056ad1d4">GetMute</a> )(<a href="_audio.md#ga18675ddb073465fdeac33a897f675d79">AudioHandle</a> handle, bool *mute)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p750014429083931"><a name="p750014429083931"></a><a name="p750014429083931"></a>获取音频的静音状态 <a href="_audio_volume.md#a75fcb5bda7e0ca9b823187f6056ad1d4">更多...</a></p>
</td>
</tr>
<tr id="row316694765083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p436458472083931"><a name="p436458472083931"></a><a name="p436458472083931"></a>( <a href="_audio_volume.md#aebf67caf924cba5f3be9d0f395390908">SetVolume</a> )(<a href="_audio.md#ga18675ddb073465fdeac33a897f675d79">AudioHandle</a> handle, float volume)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p734198058083931"><a name="p734198058083931"></a><a name="p734198058083931"></a>设置一个音频流的音量 <a href="_audio_volume.md#aebf67caf924cba5f3be9d0f395390908">更多...</a></p>
</td>
</tr>
<tr id="row1191393771083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p521101487083931"><a name="p521101487083931"></a><a name="p521101487083931"></a>( <a href="_audio_volume.md#a649524ce280ecdb62ddacb78e1a63439">GetVolume</a> )(<a href="_audio.md#ga18675ddb073465fdeac33a897f675d79">AudioHandle</a> handle, float *volume)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p774028548083931"><a name="p774028548083931"></a><a name="p774028548083931"></a>获取一个音频流的音量 <a href="_audio_volume.md#a649524ce280ecdb62ddacb78e1a63439">更多...</a></p>
</td>
</tr>
<tr id="row77812740083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2069804324083931"><a name="p2069804324083931"></a><a name="p2069804324083931"></a>( <a href="_audio_volume.md#aa42ff18fa2b7e6780acf120ea49054ed">GetGainThreshold</a> )(<a href="_audio.md#ga18675ddb073465fdeac33a897f675d79">AudioHandle</a> handle, float *min, float *max)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p4461820083931"><a name="p4461820083931"></a><a name="p4461820083931"></a>获取音频流增益的阈值 <a href="_audio_volume.md#aa42ff18fa2b7e6780acf120ea49054ed">更多...</a></p>
</td>
</tr>
<tr id="row1378743349083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p627751075083931"><a name="p627751075083931"></a><a name="p627751075083931"></a>( <a href="_audio_volume.md#a5ff7f9e5b763d20822a1fadecc5a8db7">GetGain</a> )(<a href="_audio.md#ga18675ddb073465fdeac33a897f675d79">AudioHandle</a> handle, float *gain)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1374258392083931"><a name="p1374258392083931"></a><a name="p1374258392083931"></a>获取音频流的增益 <a href="_audio_volume.md#a5ff7f9e5b763d20822a1fadecc5a8db7">更多...</a></p>
</td>
</tr>
<tr id="row721630665083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1045709312083931"><a name="p1045709312083931"></a><a name="p1045709312083931"></a>( <a href="_audio_volume.md#ab667c5f8754d0b10121451a57abbe429">SetGain</a> )(<a href="_audio.md#ga18675ddb073465fdeac33a897f675d79">AudioHandle</a> handle, float gain)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p423296085083931"><a name="p423296085083931"></a><a name="p423296085083931"></a>设置音频流的增益 <a href="_audio_volume.md#ab667c5f8754d0b10121451a57abbe429">更多...</a></p>
</td>
</tr>
</tbody>
</table>

## **详细描述**<a name="section417003153083931"></a>

AudioVolume音频音量接口。

提供音频播放（render）或录音（capture）需要的公共音量驱动能力，包括静音操作、设置音量、设置增益等。

**Since：**

1.0

**Version：**

1.0

## **类成员变量说明**<a name="section223013531083931"></a>

## GetGain<a name="a5ff7f9e5b763d20822a1fadecc5a8db7"></a>

```
int32_t(* AudioVolume::GetGain) (AudioHandle handle, float *gain)
```

**描述：**

获取音频流的增益

**参数：**

<a name="table905446562083931"></a>
<table><thead align="left"><tr id="row1625254992083931"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p304753472083931"><a name="p304753472083931"></a><a name="p304753472083931"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p935653501083931"><a name="p935653501083931"></a><a name="p935653501083931"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row1575175717083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1303642876083931p0"><a name="entry1303642876083931p0"></a><a name="entry1303642876083931p0"></a>handle</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1183858780083931p0"><a name="entry1183858780083931p0"></a><a name="entry1183858780083931p0"></a>待操作的音频句柄</p>
</td>
</tr>
<tr id="row1816897003083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1190639629083931p0"><a name="entry1190639629083931p0"></a><a name="entry1190639629083931p0"></a>gain</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry741109090083931p0"><a name="entry741109090083931p0"></a><a name="entry741109090083931p0"></a>保存当前获取到的增益到gain中</p>
</td>
</tr>
</tbody>
</table>

**返回：**

成功返回值0，失败返回负值

**参见：**

[GetGainThreshold](_audio_volume.md#aa42ff18fa2b7e6780acf120ea49054ed)

[SetGain](_audio_volume.md#ab667c5f8754d0b10121451a57abbe429)

## GetGainThreshold<a name="aa42ff18fa2b7e6780acf120ea49054ed"></a>

```
int32_t(* AudioVolume::GetGainThreshold) (AudioHandle handle, float *min, float *max)
```

**描述：**

获取音频流增益的阈值

在具体的功能实现中，可以根据芯片平台的实际情况来进行处理：

-   1. 可以使用实际的增益值，例如增益的范围为-50db \~ 6db
-   2. 也可以将增益范围设定为0.0\~1.0，如果增益的范围为-50db \~ 6db， 则增益的映射关系为0.0表示静音，1.0表示最大增益（6db）

**参数：**

<a name="table2108047822083931"></a>
<table><thead align="left"><tr id="row632144602083931"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p761055833083931"><a name="p761055833083931"></a><a name="p761055833083931"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p511890515083931"><a name="p511890515083931"></a><a name="p511890515083931"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row466915043083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry335339910083931p0"><a name="entry335339910083931p0"></a><a name="entry335339910083931p0"></a>handle</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1769542853083931p0"><a name="entry1769542853083931p0"></a><a name="entry1769542853083931p0"></a>待操作的音频句柄</p>
</td>
</tr>
<tr id="row576788228083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry770291011083931p0"><a name="entry770291011083931p0"></a><a name="entry770291011083931p0"></a>min</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1944655838083931p0"><a name="entry1944655838083931p0"></a><a name="entry1944655838083931p0"></a>获取的音频增益的阈值下限保存到min中</p>
</td>
</tr>
<tr id="row960037453083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry251683094083931p0"><a name="entry251683094083931p0"></a><a name="entry251683094083931p0"></a>max</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry985925541083931p0"><a name="entry985925541083931p0"></a><a name="entry985925541083931p0"></a>获取的音频增益的阈值上限保存到max中</p>
</td>
</tr>
</tbody>
</table>

**返回：**

成功返回值0，失败返回负值

**参见：**

[GetGain](_audio_volume.md#a5ff7f9e5b763d20822a1fadecc5a8db7)

[SetGain](_audio_volume.md#ab667c5f8754d0b10121451a57abbe429)

## GetMute<a name="a75fcb5bda7e0ca9b823187f6056ad1d4"></a>

```
int32_t(* AudioVolume::GetMute) (AudioHandle handle, bool *mute)
```

**描述：**

获取音频的静音状态

**参数：**

<a name="table766627423083931"></a>
<table><thead align="left"><tr id="row1596814326083931"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1958005341083931"><a name="p1958005341083931"></a><a name="p1958005341083931"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p880363950083931"><a name="p880363950083931"></a><a name="p880363950083931"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row1630417551083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry535044925083931p0"><a name="entry535044925083931p0"></a><a name="entry535044925083931p0"></a>handle</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1195914189083931p0"><a name="entry1195914189083931p0"></a><a name="entry1195914189083931p0"></a>待操作的音频句柄</p>
</td>
</tr>
<tr id="row1772218363083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry845420743083931p0"><a name="entry845420743083931p0"></a><a name="entry845420743083931p0"></a>mute</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1976101801083931p0"><a name="entry1976101801083931p0"></a><a name="entry1976101801083931p0"></a>获取的静音状态保存到mute中，true表示静音操作、false表示取消静音操作</p>
</td>
</tr>
</tbody>
</table>

**返回：**

成功返回值0，失败返回负值

**参见：**

[SetMute](_audio_volume.md#a79c127fa37eb2dbf8dc5fe9f0ed4421e)

## GetVolume<a name="a649524ce280ecdb62ddacb78e1a63439"></a>

```
int32_t(* AudioVolume::GetVolume) (AudioHandle handle, float *volume)
```

**描述：**

获取一个音频流的音量

**参数：**

<a name="table1787879424083931"></a>
<table><thead align="left"><tr id="row224990892083931"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p666858784083931"><a name="p666858784083931"></a><a name="p666858784083931"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1509104652083931"><a name="p1509104652083931"></a><a name="p1509104652083931"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row230663079083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1282264416083931p0"><a name="entry1282264416083931p0"></a><a name="entry1282264416083931p0"></a>handle</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry208572450083931p0"><a name="entry208572450083931p0"></a><a name="entry208572450083931p0"></a>待操作的音频句柄</p>
</td>
</tr>
<tr id="row1587051705083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry343796382083931p0"><a name="entry343796382083931p0"></a><a name="entry343796382083931p0"></a>volume</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1972093581083931p0"><a name="entry1972093581083931p0"></a><a name="entry1972093581083931p0"></a>获取的音量保存到volume中，范围0.0~1.0</p>
</td>
</tr>
</tbody>
</table>

**返回：**

成功返回值0，失败返回负值

**参见：**

[SetVolume](_audio_volume.md#aebf67caf924cba5f3be9d0f395390908)

## SetGain<a name="ab667c5f8754d0b10121451a57abbe429"></a>

```
int32_t(* AudioVolume::SetGain) (AudioHandle handle, float gain)
```

**描述：**

设置音频流的增益

**参数：**

<a name="table81661993083931"></a>
<table><thead align="left"><tr id="row2102729013083931"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p308202910083931"><a name="p308202910083931"></a><a name="p308202910083931"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p657280662083931"><a name="p657280662083931"></a><a name="p657280662083931"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row1594565051083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry304057650083931p0"><a name="entry304057650083931p0"></a><a name="entry304057650083931p0"></a>handle</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry964186671083931p0"><a name="entry964186671083931p0"></a><a name="entry964186671083931p0"></a>待操作的音频句柄</p>
</td>
</tr>
<tr id="row1373685378083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1121700837083931p0"><a name="entry1121700837083931p0"></a><a name="entry1121700837083931p0"></a>gain</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1125746554083931p0"><a name="entry1125746554083931p0"></a><a name="entry1125746554083931p0"></a>gain 待设置的增益</p>
</td>
</tr>
</tbody>
</table>

**返回：**

成功返回值0，失败返回负值

**参见：**

[GetGainThreshold](_audio_volume.md#aa42ff18fa2b7e6780acf120ea49054ed)

[GetGain](_audio_volume.md#a5ff7f9e5b763d20822a1fadecc5a8db7)

## SetMute<a name="a79c127fa37eb2dbf8dc5fe9f0ed4421e"></a>

```
int32_t(* AudioVolume::SetMute) (AudioHandle handle, bool mute)
```

**描述：**

设置音频的静音状态

**参数：**

<a name="table44567435083931"></a>
<table><thead align="left"><tr id="row75414421083931"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p682978442083931"><a name="p682978442083931"></a><a name="p682978442083931"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1019748712083931"><a name="p1019748712083931"></a><a name="p1019748712083931"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row1404296593083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry781018606083931p0"><a name="entry781018606083931p0"></a><a name="entry781018606083931p0"></a>handle</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry961949109083931p0"><a name="entry961949109083931p0"></a><a name="entry961949109083931p0"></a>待操作的音频句柄</p>
</td>
</tr>
<tr id="row832805160083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1350220956083931p0"><a name="entry1350220956083931p0"></a><a name="entry1350220956083931p0"></a>mute</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry232434969083931p0"><a name="entry232434969083931p0"></a><a name="entry232434969083931p0"></a>待设置的静音状态，true表示静音操作、false表示取消静音操作</p>
</td>
</tr>
</tbody>
</table>

**返回：**

成功返回值0，失败返回负值

**参见：**

[GetMute](_audio_volume.md#a75fcb5bda7e0ca9b823187f6056ad1d4)

## SetVolume<a name="aebf67caf924cba5f3be9d0f395390908"></a>

```
int32_t(* AudioVolume::SetVolume) (AudioHandle handle, float volume)
```

**描述：**

设置一个音频流的音量。

音量的取值范围是0.0\~1.0，如果音频服务中的音量等级为15级（0 \~ 15）， 则音量的映射关系为0.0表示静音，1.0表示最大音量等级（15）

**参数：**

<a name="table640270345083931"></a>
<table><thead align="left"><tr id="row1813793366083931"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1042872007083931"><a name="p1042872007083931"></a><a name="p1042872007083931"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p822854990083931"><a name="p822854990083931"></a><a name="p822854990083931"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row1138751721083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry747730025083931p0"><a name="entry747730025083931p0"></a><a name="entry747730025083931p0"></a>handle</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1268440637083931p0"><a name="entry1268440637083931p0"></a><a name="entry1268440637083931p0"></a>待操作的音频句柄</p>
</td>
</tr>
<tr id="row85808091083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry418061939083931p0"><a name="entry418061939083931p0"></a><a name="entry418061939083931p0"></a>volume</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry393481817083931p0"><a name="entry393481817083931p0"></a><a name="entry393481817083931p0"></a>待设置的音量，范围0.0~1.0</p>
</td>
</tr>
</tbody>
</table>

**返回：**

成功返回值0，失败返回负值

