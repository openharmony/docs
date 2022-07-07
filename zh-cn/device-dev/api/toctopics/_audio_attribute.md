# AudioAttribute<a name="ZH-CN_TOPIC_0000001343320989"></a>

## **概述**<a name="section1025648734083931"></a>

**所属模块:**

[Audio](_audio.md)

## **汇总**<a name="section1937071519083931"></a>

## Public 属性<a name="pub-attribs"></a>

<a name="table172600186083931"></a>
<table><thead align="left"><tr id="row1543372393083931"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1354007632083931"><a name="p1354007632083931"></a><a name="p1354007632083931"></a>Public 属性</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p781006795083931"><a name="p781006795083931"></a><a name="p781006795083931"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row996886070083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1532309474083931"><a name="p1532309474083931"></a><a name="p1532309474083931"></a>( <a href="_audio_attribute.md#a74a23f0544ac688223e61fa71a307851">GetFrameSize</a> )(<a href="_audio.md#ga18675ddb073465fdeac33a897f675d79">AudioHandle</a> handle, uint64_t *size)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1205754224083931"><a name="p1205754224083931"></a><a name="p1205754224083931"></a>获取音频帧（frame）的大小 <a href="_audio_attribute.md#a74a23f0544ac688223e61fa71a307851">更多...</a></p>
</td>
</tr>
<tr id="row371444828083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1142704519083931"><a name="p1142704519083931"></a><a name="p1142704519083931"></a>( <a href="_audio_attribute.md#ab31fee582dc33b9320e0a0e5d16ae0e6">GetFrameCount</a> )(<a href="_audio.md#ga18675ddb073465fdeac33a897f675d79">AudioHandle</a> handle, uint64_t *count)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p393391393083931"><a name="p393391393083931"></a><a name="p393391393083931"></a>获取音频buffer中的音频帧数 <a href="_audio_attribute.md#ab31fee582dc33b9320e0a0e5d16ae0e6">更多...</a></p>
</td>
</tr>
<tr id="row1757779507083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1497742008083931"><a name="p1497742008083931"></a><a name="p1497742008083931"></a>( <a href="_audio_attribute.md#a502fe4e4b97cd253244debcc67d45c4d">SetSampleAttributes</a> )(<a href="_audio.md#ga18675ddb073465fdeac33a897f675d79">AudioHandle</a> handle, const struct <a href="_audio_sample_attributes.md">AudioSampleAttributes</a> *attrs)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1889623699083931"><a name="p1889623699083931"></a><a name="p1889623699083931"></a>设置音频采样的属性参数 <a href="_audio_attribute.md#a502fe4e4b97cd253244debcc67d45c4d">更多...</a></p>
</td>
</tr>
<tr id="row1528339566083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p257928916083931"><a name="p257928916083931"></a><a name="p257928916083931"></a>( <a href="_audio_attribute.md#a2f92d8704ef677a07d664c33342e4318">GetSampleAttributes</a> )(<a href="_audio.md#ga18675ddb073465fdeac33a897f675d79">AudioHandle</a> handle, struct <a href="_audio_sample_attributes.md">AudioSampleAttributes</a> *attrs)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1202352042083931"><a name="p1202352042083931"></a><a name="p1202352042083931"></a>获取音频采样的属性参数 <a href="_audio_attribute.md#a2f92d8704ef677a07d664c33342e4318">更多...</a></p>
</td>
</tr>
<tr id="row1654680664083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1768851030083931"><a name="p1768851030083931"></a><a name="p1768851030083931"></a>( <a href="_audio_attribute.md#ad070369ffa9d88df541aaf0ffbbcfbfd">GetCurrentChannelId</a> )(<a href="_audio.md#ga18675ddb073465fdeac33a897f675d79">AudioHandle</a> handle, uint32_t *channelId)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1933157914083931"><a name="p1933157914083931"></a><a name="p1933157914083931"></a>获取音频的数据通道ID <a href="_audio_attribute.md#ad070369ffa9d88df541aaf0ffbbcfbfd">更多...</a></p>
</td>
</tr>
<tr id="row785532308083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1133807990083931"><a name="p1133807990083931"></a><a name="p1133807990083931"></a>( <a href="_audio_attribute.md#a48841de93d8c4e340cc75b288eb14245">SetExtraParams</a> )(<a href="_audio.md#ga18675ddb073465fdeac33a897f675d79">AudioHandle</a> handle, const char *keyValueList)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1440449734083931"><a name="p1440449734083931"></a><a name="p1440449734083931"></a>设置音频拓展参数 <a href="_audio_attribute.md#a48841de93d8c4e340cc75b288eb14245">更多...</a></p>
</td>
</tr>
<tr id="row1334318808083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1560277225083931"><a name="p1560277225083931"></a><a name="p1560277225083931"></a>( <a href="_audio_attribute.md#a3f83d4450331a740cdbc45e94ed7e54f">GetExtraParams</a> )(<a href="_audio.md#ga18675ddb073465fdeac33a897f675d79">AudioHandle</a> handle, char *keyValueList)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p963772615083931"><a name="p963772615083931"></a><a name="p963772615083931"></a>获取音频拓展参数 <a href="_audio_attribute.md#a3f83d4450331a740cdbc45e94ed7e54f">更多...</a></p>
</td>
</tr>
<tr id="row1261547693083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p860764152083931"><a name="p860764152083931"></a><a name="p860764152083931"></a>( <a href="_audio_attribute.md#ab8d33f6e19666ab00d66df2982bbd3c7">ReqMmapBuffer</a> )(<a href="_audio.md#ga18675ddb073465fdeac33a897f675d79">AudioHandle</a> handle, int32_t reqSize, struct <a href="_audio_mmap_buffer_descripter.md">AudioMmapBufferDescripter</a> *desc)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1356637666083931"><a name="p1356637666083931"></a><a name="p1356637666083931"></a>请求mmap缓冲区 <a href="_audio_attribute.md#ab8d33f6e19666ab00d66df2982bbd3c7">更多...</a></p>
</td>
</tr>
<tr id="row1761951666083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p232120718083931"><a name="p232120718083931"></a><a name="p232120718083931"></a>( <a href="_audio_attribute.md#a0131b50991af411d441151574f11d26f">GetMmapPosition</a> )(<a href="_audio.md#ga18675ddb073465fdeac33a897f675d79">AudioHandle</a> handle, uint64_t *frames, struct <a href="_audio_time_stamp.md">AudioTimeStamp</a> *time)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p192363220083931"><a name="p192363220083931"></a><a name="p192363220083931"></a>获取当前mmap的读/写位置 <a href="_audio_attribute.md#a0131b50991af411d441151574f11d26f">更多...</a></p>
</td>
</tr>
</tbody>
</table>

## **详细描述**<a name="section469150451083931"></a>

AudioAttribute音频属性接口

提供音频播放（render）或录音（capture）需要的公共属性驱动能力，包括获取帧（frame）信息、设置采样属性等。

**Since：**

1.0

**Version：**

1.0

## **类成员变量说明**<a name="section449656386083931"></a>

## GetCurrentChannelId<a name="ad070369ffa9d88df541aaf0ffbbcfbfd"></a>

```
int32_t(* AudioAttribute::GetCurrentChannelId) (AudioHandle handle, uint32_t *channelId)
```

**描述：**

获取音频的数据通道ID

**参数：**

<a name="table316236040083931"></a>
<table><thead align="left"><tr id="row161471940083931"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1636319156083931"><a name="p1636319156083931"></a><a name="p1636319156083931"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1295302570083931"><a name="p1295302570083931"></a><a name="p1295302570083931"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row773024180083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1177700915083931p0"><a name="entry1177700915083931p0"></a><a name="entry1177700915083931p0"></a>handle</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry42382353083931p0"><a name="entry42382353083931p0"></a><a name="entry42382353083931p0"></a>待操作的音频句柄</p>
</td>
</tr>
<tr id="row1666876464083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1806859883083931p0"><a name="entry1806859883083931p0"></a><a name="entry1806859883083931p0"></a>channelId</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry34198875083931p0"><a name="entry34198875083931p0"></a><a name="entry34198875083931p0"></a>获取的通道ID保存到channelId中</p>
</td>
</tr>
</tbody>
</table>

**返回：**

成功返回值0，失败返回负值

## GetExtraParams<a name="a3f83d4450331a740cdbc45e94ed7e54f"></a>

```
int32_t(* AudioAttribute::GetExtraParams) (AudioHandle handle, char *keyValueList)
```

**描述：**

获取音频拓展参数。

**参数：**

<a name="table1234072143083931"></a>
<table><thead align="left"><tr id="row1317939519083931"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p716308082083931"><a name="p716308082083931"></a><a name="p716308082083931"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p744008728083931"><a name="p744008728083931"></a><a name="p744008728083931"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row1991864249083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry535307546083931p0"><a name="entry535307546083931p0"></a><a name="entry535307546083931p0"></a>handle</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry910278516083931p0"><a name="entry910278516083931p0"></a><a name="entry910278516083931p0"></a>待操作的音频句柄</p>
</td>
</tr>
<tr id="row1437003322083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1299500651083931p0"><a name="entry1299500651083931p0"></a><a name="entry1299500651083931p0"></a>keyValueList</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1003834136083931p0"><a name="entry1003834136083931p0"></a><a name="entry1003834136083931p0"></a>拓展参数键值对字符串列表，格式为key=value，多个键值对通过分号分割</p>
</td>
</tr>
</tbody>
</table>

**返回：**

成功返回值0，失败返回负值。

## GetFrameCount<a name="ab31fee582dc33b9320e0a0e5d16ae0e6"></a>

```
int32_t(* AudioAttribute::GetFrameCount) (AudioHandle handle, uint64_t *count)
```

**描述：**

获取音频buffer中的音频帧数。

**参数：**

<a name="table609312203083931"></a>
<table><thead align="left"><tr id="row947766947083931"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1225187679083931"><a name="p1225187679083931"></a><a name="p1225187679083931"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1136087997083931"><a name="p1136087997083931"></a><a name="p1136087997083931"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row531364599083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1719166980083931p0"><a name="entry1719166980083931p0"></a><a name="entry1719166980083931p0"></a>handle</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1731223420083931p0"><a name="entry1731223420083931p0"></a><a name="entry1731223420083931p0"></a>待操作的音频句柄</p>
</td>
</tr>
<tr id="row34675074083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry5685187083931p0"><a name="entry5685187083931p0"></a><a name="entry5685187083931p0"></a>count</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry559523743083931p0"><a name="entry559523743083931p0"></a><a name="entry559523743083931p0"></a>一个音频buffer中包含的音频帧数，获取后保存到count中</p>
</td>
</tr>
</tbody>
</table>

**返回：**

成功返回值0，失败返回负值

## GetFrameSize<a name="a74a23f0544ac688223e61fa71a307851"></a>

```
int32_t(* AudioAttribute::GetFrameSize) (AudioHandle handle, uint64_t *size)
```

**描述：**

获取音频帧（frame）的大小

获取一帧音频数据的长度（字节数）

**参数：**

<a name="table2136169531083931"></a>
<table><thead align="left"><tr id="row1554404375083931"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p616424526083931"><a name="p616424526083931"></a><a name="p616424526083931"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1537155972083931"><a name="p1537155972083931"></a><a name="p1537155972083931"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row967956411083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry454049802083931p0"><a name="entry454049802083931p0"></a><a name="entry454049802083931p0"></a>handle</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1919619076083931p0"><a name="entry1919619076083931p0"></a><a name="entry1919619076083931p0"></a>待操作的音频句柄</p>
</td>
</tr>
<tr id="row1549342029083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1409970034083931p0"><a name="entry1409970034083931p0"></a><a name="entry1409970034083931p0"></a>size</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1001519894083931p0"><a name="entry1001519894083931p0"></a><a name="entry1001519894083931p0"></a>获取的音频帧大小（字节数）保存到size中</p>
</td>
</tr>
</tbody>
</table>

**返回：**

成功返回值0，失败返回负值

## GetMmapPosition<a name="a0131b50991af411d441151574f11d26f"></a>

```
int32_t(* AudioAttribute::GetMmapPosition) (AudioHandle handle, uint64_t *frames, struct AudioTimeStamp *time)
```

**描述：**

获取当前mmap的读/写位置

**参数：**

<a name="table96879976083931"></a>
<table><thead align="left"><tr id="row2099594525083931"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p2111072467083931"><a name="p2111072467083931"></a><a name="p2111072467083931"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p124021653083931"><a name="p124021653083931"></a><a name="p124021653083931"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row1530476861083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry2133182732083931p0"><a name="entry2133182732083931p0"></a><a name="entry2133182732083931p0"></a>handle</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry618046411083931p0"><a name="entry618046411083931p0"></a><a name="entry618046411083931p0"></a>待操作的音频句柄</p>
</td>
</tr>
<tr id="row1736987854083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1923635313083931p0"><a name="entry1923635313083931p0"></a><a name="entry1923635313083931p0"></a>frames</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1902286521083931p0"><a name="entry1902286521083931p0"></a><a name="entry1902286521083931p0"></a>获取的音频帧计数保存到frames中</p>
</td>
</tr>
<tr id="row1681011523083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry209957636083931p0"><a name="entry209957636083931p0"></a><a name="entry209957636083931p0"></a>time</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1909663296083931p0"><a name="entry1909663296083931p0"></a><a name="entry1909663296083931p0"></a>获取的关联时间戳保存到time中</p>
</td>
</tr>
</tbody>
</table>

**返回：**

成功返回值0，失败返回负值

## GetSampleAttributes<a name="a2f92d8704ef677a07d664c33342e4318"></a>

```
int32_t(* AudioAttribute::GetSampleAttributes) (AudioHandle handle, struct AudioSampleAttributes *attrs)
```

**描述：**

获取音频采样的属性参数。

**参数：**

<a name="table1869176733083931"></a>
<table><thead align="left"><tr id="row1542185135083931"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p72975378083931"><a name="p72975378083931"></a><a name="p72975378083931"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p95787914083931"><a name="p95787914083931"></a><a name="p95787914083931"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row443340054083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry858551322083931p0"><a name="entry858551322083931p0"></a><a name="entry858551322083931p0"></a>handle</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry991461631083931p0"><a name="entry991461631083931p0"></a><a name="entry991461631083931p0"></a>待操作的音频句柄</p>
</td>
</tr>
<tr id="row394004133083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1430656464083931p0"><a name="entry1430656464083931p0"></a><a name="entry1430656464083931p0"></a>attrs</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1819780122083931p0"><a name="entry1819780122083931p0"></a><a name="entry1819780122083931p0"></a>获取的音频采样属性（例如采样频率、采样精度、通道）保存到attrs中</p>
</td>
</tr>
</tbody>
</table>

**返回：**

成功返回值0，失败返回负值

**参见：**

[SetSampleAttributes](_audio_attribute.md#a502fe4e4b97cd253244debcc67d45c4d)

## ReqMmapBuffer<a name="ab8d33f6e19666ab00d66df2982bbd3c7"></a>

```
int32_t(* AudioAttribute::ReqMmapBuffer) (AudioHandle handle, int32_t reqSize, struct AudioMmapBufferDescripter *desc)
```

**描述：**

请求mmap缓冲区

**参数：**

<a name="table1202900722083931"></a>
<table><thead align="left"><tr id="row536521735083931"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1374264292083931"><a name="p1374264292083931"></a><a name="p1374264292083931"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1832068544083931"><a name="p1832068544083931"></a><a name="p1832068544083931"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row973210155083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1324039566083931p0"><a name="entry1324039566083931p0"></a><a name="entry1324039566083931p0"></a>handle</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1494503839083931p0"><a name="entry1494503839083931p0"></a><a name="entry1494503839083931p0"></a>待操作的音频句柄</p>
</td>
</tr>
<tr id="row1690130282083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1620452410083931p0"><a name="entry1620452410083931p0"></a><a name="entry1620452410083931p0"></a>reqSize</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry6146783083931p0"><a name="entry6146783083931p0"></a><a name="entry6146783083931p0"></a>请求缓冲区的大小</p>
</td>
</tr>
<tr id="row1597213117083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1815959212083931p0"><a name="entry1815959212083931p0"></a><a name="entry1815959212083931p0"></a>desc</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry586217767083931p0"><a name="entry586217767083931p0"></a><a name="entry586217767083931p0"></a>缓冲区描述符</p>
</td>
</tr>
</tbody>
</table>

**返回：**

成功返回值0，失败返回负值

## SetExtraParams<a name="a48841de93d8c4e340cc75b288eb14245"></a>

```
int32_t(* AudioAttribute::SetExtraParams) (AudioHandle handle, const char *keyValueList)
```

**描述：**

设置音频拓展参数。

**参数：**

<a name="table347422338083931"></a>
<table><thead align="left"><tr id="row1231291166083931"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p900241238083931"><a name="p900241238083931"></a><a name="p900241238083931"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p484031027083931"><a name="p484031027083931"></a><a name="p484031027083931"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row680910926083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry2035081037083931p0"><a name="entry2035081037083931p0"></a><a name="entry2035081037083931p0"></a>handle</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry279247724083931p0"><a name="entry279247724083931p0"></a><a name="entry279247724083931p0"></a>待操作的音频句柄</p>
</td>
</tr>
<tr id="row144571834083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry117281360083931p0"><a name="entry117281360083931p0"></a><a name="entry117281360083931p0"></a>keyValueList</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry29654822083931p0"><a name="entry29654822083931p0"></a><a name="entry29654822083931p0"></a>拓展参数键值对字符串列表，格式为key=value，多个键值对通过分号分割</p>
</td>
</tr>
</tbody>
</table>

**返回：**

成功返回值0，失败返回负值

## SetSampleAttributes<a name="a502fe4e4b97cd253244debcc67d45c4d"></a>

```
int32_t(* AudioAttribute::SetSampleAttributes) (AudioHandle handle, const struct AudioSampleAttributes *attrs)
```

**描述：**

设置音频采样的属性参数。

**参数：**

<a name="table1494305452083931"></a>
<table><thead align="left"><tr id="row1749630020083931"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1033880648083931"><a name="p1033880648083931"></a><a name="p1033880648083931"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1068307241083931"><a name="p1068307241083931"></a><a name="p1068307241083931"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row150371531083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1595216551083931p0"><a name="entry1595216551083931p0"></a><a name="entry1595216551083931p0"></a>handle</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry207683945083931p0"><a name="entry207683945083931p0"></a><a name="entry207683945083931p0"></a>待操作的音频句柄</p>
</td>
</tr>
<tr id="row1077774462083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry577465310083931p0"><a name="entry577465310083931p0"></a><a name="entry577465310083931p0"></a>attrs</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1082738205083931p0"><a name="entry1082738205083931p0"></a><a name="entry1082738205083931p0"></a>待设置的音频采样属性，例如采样频率、采样精度、通道</p>
</td>
</tr>
</tbody>
</table>

**返回：**

成功返回值0，失败返回负值

**参见：**

[GetSampleAttributes](_audio_attribute.md#a2f92d8704ef677a07d664c33342e4318)

