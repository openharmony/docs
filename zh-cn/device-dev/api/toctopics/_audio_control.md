# AudioControl<a name="ZH-CN_TOPIC_0000001343200713"></a>

## **概述**<a name="section995789463083931"></a>

**所属模块:**

[Audio](_audio.md)

## **汇总**<a name="section2104884921083931"></a>

## Public 属性<a name="pub-attribs"></a>

<a name="table8770909083931"></a>
<table><thead align="left"><tr id="row781812983083931"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p559125621083931"><a name="p559125621083931"></a><a name="p559125621083931"></a>Public 属性</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p449731989083931"><a name="p449731989083931"></a><a name="p449731989083931"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row557782768083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1926881702083931"><a name="p1926881702083931"></a><a name="p1926881702083931"></a>( <a href="_audio_control.md#a80ddae13819bb1eb348ad4b57597e930">Start</a> )(<a href="_audio.md#ga18675ddb073465fdeac33a897f675d79">AudioHandle</a> handle)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1047825661083931"><a name="p1047825661083931"></a><a name="p1047825661083931"></a>启动一个音频播放（render）或录音（capture）处理 <a href="_audio_control.md#a80ddae13819bb1eb348ad4b57597e930">更多...</a></p>
</td>
</tr>
<tr id="row256190228083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1251659762083931"><a name="p1251659762083931"></a><a name="p1251659762083931"></a>( <a href="_audio_control.md#a62e385e391ba1efed35021ee67ab9449">Stop</a> )(<a href="_audio.md#ga18675ddb073465fdeac33a897f675d79">AudioHandle</a> handle)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1973295939083931"><a name="p1973295939083931"></a><a name="p1973295939083931"></a>停止一个音频播放（render）或录音（capture）处理 <a href="_audio_control.md#a62e385e391ba1efed35021ee67ab9449">更多...</a></p>
</td>
</tr>
<tr id="row1002264171083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p566366843083931"><a name="p566366843083931"></a><a name="p566366843083931"></a>( <a href="_audio_control.md#a16a26deffa17b9f143f602763a260908">Pause</a> )(<a href="_audio.md#ga18675ddb073465fdeac33a897f675d79">AudioHandle</a> handle)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p91599342083931"><a name="p91599342083931"></a><a name="p91599342083931"></a>暂停一个音频播放（render）或录音（capture）处理 <a href="_audio_control.md#a16a26deffa17b9f143f602763a260908">更多...</a></p>
</td>
</tr>
<tr id="row1399399893083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p197613223083931"><a name="p197613223083931"></a><a name="p197613223083931"></a>( <a href="_audio_control.md#ac59c3e9a5ff9041989871f67253a1e8d">Resume</a> )(<a href="_audio.md#ga18675ddb073465fdeac33a897f675d79">AudioHandle</a> handle)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p183926835083931"><a name="p183926835083931"></a><a name="p183926835083931"></a>恢复一个音频播放（render）或录音（capture）处理 <a href="_audio_control.md#ac59c3e9a5ff9041989871f67253a1e8d">更多...</a></p>
</td>
</tr>
<tr id="row1720907119083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p146174227083931"><a name="p146174227083931"></a><a name="p146174227083931"></a>( <a href="_audio_control.md#acebc54c385b91ddc52b6b7849ddf12d0">Flush</a> )(<a href="_audio.md#ga18675ddb073465fdeac33a897f675d79">AudioHandle</a> handle)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p986997117083931"><a name="p986997117083931"></a><a name="p986997117083931"></a>刷新音频缓冲区buffer中的数据 <a href="_audio_control.md#acebc54c385b91ddc52b6b7849ddf12d0">更多...</a></p>
</td>
</tr>
<tr id="row170137041083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1129124975083931"><a name="p1129124975083931"></a><a name="p1129124975083931"></a>( <a href="_audio_control.md#a193e0691f13810a9098eb3217f8cd809">TurnStandbyMode</a> )(<a href="_audio.md#ga18675ddb073465fdeac33a897f675d79">AudioHandle</a> handle)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p858185405083931"><a name="p858185405083931"></a><a name="p858185405083931"></a>设置或去设置设备的待机模式 <a href="_audio_control.md#a193e0691f13810a9098eb3217f8cd809">更多...</a></p>
</td>
</tr>
<tr id="row1919337726083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p329211294083931"><a name="p329211294083931"></a><a name="p329211294083931"></a>( <a href="_audio_control.md#a3a6641ee7ddb4f2116478633dceb2578">AudioDevDump</a> )(<a href="_audio.md#ga18675ddb073465fdeac33a897f675d79">AudioHandle</a> handle, int32_t range, int32_t fd)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p428947590083931"><a name="p428947590083931"></a><a name="p428947590083931"></a>Dump音频设备信息 <a href="_audio_control.md#a3a6641ee7ddb4f2116478633dceb2578">更多...</a></p>
</td>
</tr>
</tbody>
</table>

## **详细描述**<a name="section737749775083931"></a>

AudioControl音频控制接口。

提供音频播放（render）或录音（capture）需要的公共控制驱动能力，包括Start、Stop、Pause、Resume、Flush等。

**Since：**

1.0

**Version：**

1.0

## **类成员变量说明**<a name="section914996535083931"></a>

## AudioDevDump<a name="a3a6641ee7ddb4f2116478633dceb2578"></a>

```
int32_t(* AudioControl::AudioDevDump) (AudioHandle handle, int32_t range, int32_t fd)
```

**描述：**

Dump音频设备信息

**参数：**

<a name="table1360450529083931"></a>
<table><thead align="left"><tr id="row1844159697083931"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1619064104083931"><a name="p1619064104083931"></a><a name="p1619064104083931"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p812644782083931"><a name="p812644782083931"></a><a name="p812644782083931"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row145004166083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1196010677083931p0"><a name="entry1196010677083931p0"></a><a name="entry1196010677083931p0"></a>handle</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry702490136083931p0"><a name="entry702490136083931p0"></a><a name="entry702490136083931p0"></a>待操作的音频句柄</p>
</td>
</tr>
<tr id="row264613150083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry2095376768083931p0"><a name="entry2095376768083931p0"></a><a name="entry2095376768083931p0"></a>range</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry898219255083931p0"><a name="entry898219255083931p0"></a><a name="entry898219255083931p0"></a>Dump信息范围，分为简要信息、全量信息</p>
</td>
</tr>
<tr id="row1282738572083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1067633423083931p0"><a name="entry1067633423083931p0"></a><a name="entry1067633423083931p0"></a>fd</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1648827033083931p0"><a name="entry1648827033083931p0"></a><a name="entry1648827033083931p0"></a>指定Dump目标文件</p>
</td>
</tr>
</tbody>
</table>

**返回：**

成功返回值0，失败返回负值

## Flush<a name="acebc54c385b91ddc52b6b7849ddf12d0"></a>

```
int32_t(* AudioControl::Flush) (AudioHandle handle)
```

**描述：**

刷新音频缓冲区buffer中的数据

**参数：**

<a name="table2037085318083931"></a>
<table><thead align="left"><tr id="row1659212040083931"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1524927880083931"><a name="p1524927880083931"></a><a name="p1524927880083931"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1772834249083931"><a name="p1772834249083931"></a><a name="p1772834249083931"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row1142345124083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry2011170282083931p0"><a name="entry2011170282083931p0"></a><a name="entry2011170282083931p0"></a>handle</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1730396084083931p0"><a name="entry1730396084083931p0"></a><a name="entry1730396084083931p0"></a>待操作的音频句柄</p>
</td>
</tr>
</tbody>
</table>

**返回：**

成功返回值0，失败返回负值

## Pause<a name="a16a26deffa17b9f143f602763a260908"></a>

```
int32_t(* AudioControl::Pause) (AudioHandle handle)
```

**描述：**

暂停一个音频播放（render）或录音（capture）处理

**参数：**

<a name="table1700365799083931"></a>
<table><thead align="left"><tr id="row1468188290083931"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1362925638083931"><a name="p1362925638083931"></a><a name="p1362925638083931"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p311689515083931"><a name="p311689515083931"></a><a name="p311689515083931"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row1568623355083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1867552038083931p0"><a name="entry1867552038083931p0"></a><a name="entry1867552038083931p0"></a>handle</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry585975435083931p0"><a name="entry585975435083931p0"></a><a name="entry585975435083931p0"></a>待操作的音频句柄</p>
</td>
</tr>
</tbody>
</table>

**返回：**

成功返回值0，失败返回负值

**参见：**

[Resume](_audio_control.md#ac59c3e9a5ff9041989871f67253a1e8d)

## Resume<a name="ac59c3e9a5ff9041989871f67253a1e8d"></a>

```
int32_t(* AudioControl::Resume) (AudioHandle handle)
```

**描述：**

恢复一个音频播放（render）或录音（capture）处理

**参数：**

<a name="table1562082828083931"></a>
<table><thead align="left"><tr id="row440275421083931"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p172074961083931"><a name="p172074961083931"></a><a name="p172074961083931"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p267218298083931"><a name="p267218298083931"></a><a name="p267218298083931"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row806727138083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1425510439083931p0"><a name="entry1425510439083931p0"></a><a name="entry1425510439083931p0"></a>handle</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry105424540083931p0"><a name="entry105424540083931p0"></a><a name="entry105424540083931p0"></a>待操作的音频句柄</p>
</td>
</tr>
</tbody>
</table>

**返回：**

成功返回值0，失败返回负值

**参见：**

[Pause](_audio_control.md#a16a26deffa17b9f143f602763a260908)

## Start<a name="a80ddae13819bb1eb348ad4b57597e930"></a>

```
int32_t(* AudioControl::Start) (AudioHandle handle)
```

**描述：**

启动一个音频播放（render）或录音（capture）处理

**参数：**

<a name="table651316873083931"></a>
<table><thead align="left"><tr id="row726050511083931"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p2013584391083931"><a name="p2013584391083931"></a><a name="p2013584391083931"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1123656988083931"><a name="p1123656988083931"></a><a name="p1123656988083931"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row1999942997083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry2020229098083931p0"><a name="entry2020229098083931p0"></a><a name="entry2020229098083931p0"></a>handle</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1611732825083931p0"><a name="entry1611732825083931p0"></a><a name="entry1611732825083931p0"></a>待操作的音频句柄</p>
</td>
</tr>
</tbody>
</table>

**返回：**

成功返回值0，失败返回负值

**参见：**

[Stop](_audio_control.md#a62e385e391ba1efed35021ee67ab9449)

## Stop<a name="a62e385e391ba1efed35021ee67ab9449"></a>

```
int32_t(* AudioControl::Stop) (AudioHandle handle)
```

**描述：**

停止一个音频播放（render）或录音（capture）处理

**参数：**

<a name="table1230880181083931"></a>
<table><thead align="left"><tr id="row631019766083931"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p186771028083931"><a name="p186771028083931"></a><a name="p186771028083931"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1789007084083931"><a name="p1789007084083931"></a><a name="p1789007084083931"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row2091823786083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry106028199083931p0"><a name="entry106028199083931p0"></a><a name="entry106028199083931p0"></a>handle</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1014395889083931p0"><a name="entry1014395889083931p0"></a><a name="entry1014395889083931p0"></a>待操作的音频句柄</p>
</td>
</tr>
</tbody>
</table>

**返回：**

成功返回值0，失败返回负值

**参见：**

[Start](_audio_control.md#a80ddae13819bb1eb348ad4b57597e930)

## TurnStandbyMode<a name="a193e0691f13810a9098eb3217f8cd809"></a>

```
int32_t(* AudioControl::TurnStandbyMode) (AudioHandle handle)
```

**描述：**

设置或去设置设备的待机模式

**参数：**

<a name="table1096990473083931"></a>
<table><thead align="left"><tr id="row793959920083931"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p318563627083931"><a name="p318563627083931"></a><a name="p318563627083931"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1042981018083931"><a name="p1042981018083931"></a><a name="p1042981018083931"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row1431581945083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1049714873083931p0"><a name="entry1049714873083931p0"></a><a name="entry1049714873083931p0"></a>handle</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry259386434083931p0"><a name="entry259386434083931p0"></a><a name="entry259386434083931p0"></a>待操作的音频句柄</p>
</td>
</tr>
</tbody>
</table>

**返回：**

设置设备待机模式成功返回值0，再次执行后去设置待机模式成功返回正值，失败返回负值

