# AudioAdapter<a name="ZH-CN_TOPIC_0000001290721048"></a>

## **概述**<a name="section971393610083931"></a>

**所属模块:**

[Audio](_audio.md)

## **汇总**<a name="section2076285415083931"></a>

## Public 属性<a name="pub-attribs"></a>

<a name="table779792465083931"></a>
<table><thead align="left"><tr id="row1676525599083931"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p300853603083931"><a name="p300853603083931"></a><a name="p300853603083931"></a>Public 属性</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p2135479943083931"><a name="p2135479943083931"></a><a name="p2135479943083931"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row284565688083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2080570488083931"><a name="p2080570488083931"></a><a name="p2080570488083931"></a>( <a href="_audio_adapter.md#a289840d2bfe6071b8919ea0190def3a1">InitAllPorts</a> )(struct <a href="_audio_adapter.md">AudioAdapter</a> *adapter)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p39408603083931"><a name="p39408603083931"></a><a name="p39408603083931"></a>初始化一个音频适配器所有的端口驱动 <a href="_audio_adapter.md#a289840d2bfe6071b8919ea0190def3a1">更多...</a></p>
</td>
</tr>
<tr id="row1488758004083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p974161197083931"><a name="p974161197083931"></a><a name="p974161197083931"></a>( <a href="_audio_adapter.md#a284ea2ad18ebac562ca7283652e61b50">CreateRender</a> )(struct <a href="_audio_adapter.md">AudioAdapter</a> *adapter, const struct <a href="_audio_device_descriptor.md">AudioDeviceDescriptor</a> *desc, const struct <a href="_audio_sample_attributes.md">AudioSampleAttributes</a> *attrs, struct <a href="_audio_render.md">AudioRender</a> **render)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1131934327083931"><a name="p1131934327083931"></a><a name="p1131934327083931"></a>创建一个音频播放（render）接口的对象 <a href="_audio_adapter.md#a284ea2ad18ebac562ca7283652e61b50">更多...</a></p>
</td>
</tr>
<tr id="row191961762083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p579292587083931"><a name="p579292587083931"></a><a name="p579292587083931"></a>( <a href="_audio_adapter.md#a070a8d60f88134c58c4439d4419af913">DestroyRender</a> )(struct <a href="_audio_adapter.md">AudioAdapter</a> *adapter, struct <a href="_audio_render.md">AudioRender</a> *render)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1891774606083931"><a name="p1891774606083931"></a><a name="p1891774606083931"></a>销毁一个音频播放（render）接口的对象 <a href="_audio_adapter.md#a070a8d60f88134c58c4439d4419af913">更多...</a></p>
</td>
</tr>
<tr id="row2052905564083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p613843681083931"><a name="p613843681083931"></a><a name="p613843681083931"></a>( <a href="_audio_adapter.md#a8a46358cdad8e0a9d15ac079713535f2">CreateCapture</a> )(struct <a href="_audio_adapter.md">AudioAdapter</a> *adapter, const struct <a href="_audio_device_descriptor.md">AudioDeviceDescriptor</a> *desc, const struct <a href="_audio_sample_attributes.md">AudioSampleAttributes</a> *attrs, struct <a href="_audio_capture.md">AudioCapture</a> **capture)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1430776103083931"><a name="p1430776103083931"></a><a name="p1430776103083931"></a>创建一个音频录音（capture）接口的对象 <a href="_audio_adapter.md#a8a46358cdad8e0a9d15ac079713535f2">更多...</a></p>
</td>
</tr>
<tr id="row437367525083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p283503149083931"><a name="p283503149083931"></a><a name="p283503149083931"></a>( <a href="_audio_adapter.md#a1175a27c5273dab1acf8f8f3c4967637">DestroyCapture</a> )(struct <a href="_audio_adapter.md">AudioAdapter</a> *adapter, struct <a href="_audio_capture.md">AudioCapture</a> *capture)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1178404636083931"><a name="p1178404636083931"></a><a name="p1178404636083931"></a>销毁一个音频录音（capture）接口的对象 <a href="_audio_adapter.md#a1175a27c5273dab1acf8f8f3c4967637">更多...</a></p>
</td>
</tr>
<tr id="row2072665965083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p373199903083931"><a name="p373199903083931"></a><a name="p373199903083931"></a>( <a href="_audio_adapter.md#a8f86fe208c18df58654f183f5b440f1f">GetPortCapability</a> )(struct <a href="_audio_adapter.md">AudioAdapter</a> *adapter, struct <a href="_audio_port.md">AudioPort</a> *port, struct <a href="_audio_port_capability.md">AudioPortCapability</a> *capability)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1099445150083931"><a name="p1099445150083931"></a><a name="p1099445150083931"></a>获取一个音频适配器的端口驱动的能力集 <a href="_audio_adapter.md#a8f86fe208c18df58654f183f5b440f1f">更多...</a></p>
</td>
</tr>
<tr id="row995255765083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p85585188083931"><a name="p85585188083931"></a><a name="p85585188083931"></a>( <a href="_audio_adapter.md#a115fb7b21a1fe1b8412d24c380717bde">SetPassthroughMode</a> )(struct <a href="_audio_adapter.md">AudioAdapter</a> *adapter, struct <a href="_audio_port.md">AudioPort</a> *port, enum <a href="_audio.md#ga186d2d4f9a2ecacb80cd2cce2bd26f0e">AudioPortPassthroughMode</a> mode)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1543488199083931"><a name="p1543488199083931"></a><a name="p1543488199083931"></a>设置音频端口驱动的数据透传模式 <a href="_audio_adapter.md#a115fb7b21a1fe1b8412d24c380717bde">更多...</a></p>
</td>
</tr>
<tr id="row390874338083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p130825628083931"><a name="p130825628083931"></a><a name="p130825628083931"></a>( <a href="_audio_adapter.md#abd8f7f086993cb4ce34d01190db6cc11">GetPassthroughMode</a> )(struct <a href="_audio_adapter.md">AudioAdapter</a> *adapter, struct <a href="_audio_port.md">AudioPort</a> *port, enum <a href="_audio.md#ga186d2d4f9a2ecacb80cd2cce2bd26f0e">AudioPortPassthroughMode</a> *mode)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p105355868083931"><a name="p105355868083931"></a><a name="p105355868083931"></a>获取音频端口驱动的数据透传模式 <a href="_audio_adapter.md#abd8f7f086993cb4ce34d01190db6cc11">更多...</a></p>
</td>
</tr>
<tr id="row1038719721083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1836358723083931"><a name="p1836358723083931"></a><a name="p1836358723083931"></a>( <a href="_audio_adapter.md#abc83f0c9ca6f460b92f2ea10a5addb33">UpdateAudioRoute</a> )(struct <a href="_audio_adapter.md">AudioAdapter</a> *adapter, const struct <a href="_audio_route.md">AudioRoute</a> *route, int32_t *routeHandle)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p706156506083931"><a name="p706156506083931"></a><a name="p706156506083931"></a>更新一个或多个发送端和接受端之间的路由 <a href="_audio_adapter.md#abc83f0c9ca6f460b92f2ea10a5addb33">更多...</a></p>
</td>
</tr>
<tr id="row1110720584083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1578415687083931"><a name="p1578415687083931"></a><a name="p1578415687083931"></a>( <a href="_audio_adapter.md#a8ed77453f8082cac0783fc90a2fc64c5">ReleaseAudioRoute</a> )(struct <a href="_audio_adapter.md">AudioAdapter</a> *adapter, int32_t routeHandle)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1532380020083931"><a name="p1532380020083931"></a><a name="p1532380020083931"></a>释放一个音频路由. <a href="_audio_adapter.md#a8ed77453f8082cac0783fc90a2fc64c5">更多...</a></p>
</td>
</tr>
</tbody>
</table>

## **详细描述**<a name="section638894139083931"></a>

AudioAdapter音频适配器接口

提供音频适配器（声卡）对外支持的驱动能力，包括初始化端口、创建render、创建capture、获取端口能力集等

**参见：**

[AudioRender](_audio_render.md)

[AudioCapture](_audio_capture.md)

**Since：**

1.0

**Version：**

1.0

## **类成员变量说明**<a name="section782016973083931"></a>

## CreateCapture<a name="a8a46358cdad8e0a9d15ac079713535f2"></a>

```
int32_t(* AudioAdapter::CreateCapture) (struct AudioAdapter *adapter, const struct AudioDeviceDescriptor *desc, const struct AudioSampleAttributes *attrs, struct AudioCapture **capture)
```

**描述：**

创建一个音频录音（capture）接口的对象

**参数：**

<a name="table1462860627083931"></a>
<table><thead align="left"><tr id="row771408277083931"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p2011080129083931"><a name="p2011080129083931"></a><a name="p2011080129083931"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p2124692235083931"><a name="p2124692235083931"></a><a name="p2124692235083931"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row1807740461083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry882703410083931p0"><a name="entry882703410083931p0"></a><a name="entry882703410083931p0"></a>adapter</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry701014258083931p0"><a name="entry701014258083931p0"></a><a name="entry701014258083931p0"></a>待操作的音频适配器的指针</p>
</td>
</tr>
<tr id="row1849486220083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1430794656083931p0"><a name="entry1430794656083931p0"></a><a name="entry1430794656083931p0"></a>desc</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry330848123083931p0"><a name="entry330848123083931p0"></a><a name="entry330848123083931p0"></a>指向要启动的音频适配器的描述符的指针</p>
</td>
</tr>
<tr id="row234899904083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1772788055083931p0"><a name="entry1772788055083931p0"></a><a name="entry1772788055083931p0"></a>attrs</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry802080884083931p0"><a name="entry802080884083931p0"></a><a name="entry802080884083931p0"></a>指向要打开的音频采样属性的指针</p>
</td>
</tr>
<tr id="row508661507083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1721043175083931p0"><a name="entry1721043175083931p0"></a><a name="entry1721043175083931p0"></a>capture</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry2052608047083931p0"><a name="entry2052608047083931p0"></a><a name="entry2052608047083931p0"></a>指向AudioCapture对象的二级指针</p>
</td>
</tr>
</tbody>
</table>

**返回：**

成功返回值0，失败返回负值

**参见：**

[GetPortCapability](_audio_adapter.md#a8f86fe208c18df58654f183f5b440f1f)

[DestroyCapture](_audio_adapter.md#a1175a27c5273dab1acf8f8f3c4967637)

## CreateRender<a name="a284ea2ad18ebac562ca7283652e61b50"></a>

```
int32_t(* AudioAdapter::CreateRender) (struct AudioAdapter *adapter, const struct AudioDeviceDescriptor *desc, const struct AudioSampleAttributes *attrs, struct AudioRender **render)
```

**描述：**

创建一个音频播放（render）接口的对象

**参数：**

<a name="table196009287083931"></a>
<table><thead align="left"><tr id="row56127178083931"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p302091231083931"><a name="p302091231083931"></a><a name="p302091231083931"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p295293433083931"><a name="p295293433083931"></a><a name="p295293433083931"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row1066974639083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1615967676083931p0"><a name="entry1615967676083931p0"></a><a name="entry1615967676083931p0"></a>adapter</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1678457985083931p0"><a name="entry1678457985083931p0"></a><a name="entry1678457985083931p0"></a>待操作的音频适配器对象</p>
</td>
</tr>
<tr id="row1930771027083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry159194003083931p0"><a name="entry159194003083931p0"></a><a name="entry159194003083931p0"></a>desc</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry236064806083931p0"><a name="entry236064806083931p0"></a><a name="entry236064806083931p0"></a>待打开的音频设备描述符</p>
</td>
</tr>
<tr id="row902777988083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry2132960429083931p0"><a name="entry2132960429083931p0"></a><a name="entry2132960429083931p0"></a>attrs</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1311750051083931p0"><a name="entry1311750051083931p0"></a><a name="entry1311750051083931p0"></a>待打开的音频采样属性</p>
</td>
</tr>
<tr id="row1839227398083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1926406733083931p0"><a name="entry1926406733083931p0"></a><a name="entry1926406733083931p0"></a>render</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry464426930083931p0"><a name="entry464426930083931p0"></a><a name="entry464426930083931p0"></a>获取的音频播放接口的对象实例保存到render中</p>
</td>
</tr>
</tbody>
</table>

**返回：**

成功返回值0，失败返回负值

**参见：**

[GetPortCapability](_audio_adapter.md#a8f86fe208c18df58654f183f5b440f1f)

[DestroyRender](_audio_adapter.md#a070a8d60f88134c58c4439d4419af913)

## DestroyCapture<a name="a1175a27c5273dab1acf8f8f3c4967637"></a>

```
int32_t(* AudioAdapter::DestroyCapture) (struct AudioAdapter *adapter, struct AudioCapture *capture)
```

**描述：**

销毁一个音频录音（capture）接口的对象

**参数：**

<a name="table1659369579083931"></a>
<table><thead align="left"><tr id="row705443265083931"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1964931370083931"><a name="p1964931370083931"></a><a name="p1964931370083931"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1243399305083931"><a name="p1243399305083931"></a><a name="p1243399305083931"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row1265910134083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1734409245083931p0"><a name="entry1734409245083931p0"></a><a name="entry1734409245083931p0"></a>adapter</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry680601568083931p0"><a name="entry680601568083931p0"></a><a name="entry680601568083931p0"></a>待操作的音频适配器对象</p>
</td>
</tr>
<tr id="row568795228083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1430728803083931p0"><a name="entry1430728803083931p0"></a><a name="entry1430728803083931p0"></a>capture</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry147901940083931p0"><a name="entry147901940083931p0"></a><a name="entry147901940083931p0"></a>待操作的音频录音接口对象</p>
</td>
</tr>
</tbody>
</table>

**注意:**

在音频录音过程中，不能销毁该接口对象

**返回：**

成功返回值0，失败返回负值

**参见：**

[CreateCapture](_audio_adapter.md#a8a46358cdad8e0a9d15ac079713535f2)

## DestroyRender<a name="a070a8d60f88134c58c4439d4419af913"></a>

```
int32_t(* AudioAdapter::DestroyRender) (struct AudioAdapter *adapter, struct AudioRender *render)
```

**描述：**

销毁一个音频播放（render）接口的对象

**参数：**

<a name="table579109357083931"></a>
<table><thead align="left"><tr id="row2069768855083931"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p525011667083931"><a name="p525011667083931"></a><a name="p525011667083931"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1654585502083931"><a name="p1654585502083931"></a><a name="p1654585502083931"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row726684552083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1050608756083931p0"><a name="entry1050608756083931p0"></a><a name="entry1050608756083931p0"></a>adapter</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1628205771083931p0"><a name="entry1628205771083931p0"></a><a name="entry1628205771083931p0"></a>待操作的音频适配器对象</p>
</td>
</tr>
<tr id="row244555948083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry984068446083931p0"><a name="entry984068446083931p0"></a><a name="entry984068446083931p0"></a>render</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1029229236083931p0"><a name="entry1029229236083931p0"></a><a name="entry1029229236083931p0"></a>待操作的音频播放接口对象</p>
</td>
</tr>
</tbody>
</table>

**注意:**

在音频播放过程中，不能销毁该接口对象

**返回：**

成功返回值0，失败返回负值

**参见：**

[CreateRender](_audio_adapter.md#a284ea2ad18ebac562ca7283652e61b50)

## GetPassthroughMode<a name="abd8f7f086993cb4ce34d01190db6cc11"></a>

```
int(* AudioAdapter::GetPassthroughMode) (struct AudioAdapter *adapter, struct AudioPort *port, enum AudioPortPassthroughMode *mode)
```

**描述：**

获取音频端口驱动的数据透传模式

**参数：**

<a name="table913546222083931"></a>
<table><thead align="left"><tr id="row900713439083931"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1979812603083931"><a name="p1979812603083931"></a><a name="p1979812603083931"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1845390869083931"><a name="p1845390869083931"></a><a name="p1845390869083931"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row175192576083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry341926813083931p0"><a name="entry341926813083931p0"></a><a name="entry341926813083931p0"></a>adapter</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1133647851083931p0"><a name="entry1133647851083931p0"></a><a name="entry1133647851083931p0"></a>待操作的音频适配器对象</p>
</td>
</tr>
<tr id="row1599240883083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry882233640083931p0"><a name="entry882233640083931p0"></a><a name="entry882233640083931p0"></a>port</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry591044812083931p0"><a name="entry591044812083931p0"></a><a name="entry591044812083931p0"></a>待获取的端口</p>
</td>
</tr>
<tr id="row1979138493083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1334757704083931p0"><a name="entry1334757704083931p0"></a><a name="entry1334757704083931p0"></a>mode</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1490764918083931p0"><a name="entry1490764918083931p0"></a><a name="entry1490764918083931p0"></a>获取的传输模式保存到mode中</p>
</td>
</tr>
</tbody>
</table>

**返回：**

成功返回值0，失败返回负值

**参见：**

[SetPassthroughMode](_audio_adapter.md#a115fb7b21a1fe1b8412d24c380717bde)

## GetPortCapability<a name="a8f86fe208c18df58654f183f5b440f1f"></a>

```
int(* AudioAdapter::GetPortCapability) (struct AudioAdapter *adapter, struct AudioPort *port, struct AudioPortCapability *capability)
```

**描述：**

获取一个音频适配器的端口驱动的能力集

**参数：**

<a name="table1782047908083931"></a>
<table><thead align="left"><tr id="row1077859622083931"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1213713944083931"><a name="p1213713944083931"></a><a name="p1213713944083931"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1362146296083931"><a name="p1362146296083931"></a><a name="p1362146296083931"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row448621604083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1313256440083931p0"><a name="entry1313256440083931p0"></a><a name="entry1313256440083931p0"></a>adapter</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1632183200083931p0"><a name="entry1632183200083931p0"></a><a name="entry1632183200083931p0"></a>待操作的音频适配器对象</p>
</td>
</tr>
<tr id="row1808140134083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1519662203083931p0"><a name="entry1519662203083931p0"></a><a name="entry1519662203083931p0"></a>port</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1195829921083931p0"><a name="entry1195829921083931p0"></a><a name="entry1195829921083931p0"></a>待获取的端口</p>
</td>
</tr>
<tr id="row1730998291083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1471269188083931p0"><a name="entry1471269188083931p0"></a><a name="entry1471269188083931p0"></a>capability</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry988806907083931p0"><a name="entry988806907083931p0"></a><a name="entry988806907083931p0"></a>获取的端口能力保存到capability中</p>
</td>
</tr>
</tbody>
</table>

**返回：**

成功返回值0，失败返回负值

## InitAllPorts<a name="a289840d2bfe6071b8919ea0190def3a1"></a>

```
int(* AudioAdapter::InitAllPorts) (struct AudioAdapter *adapter)
```

**描述：**

初始化一个音频适配器所有的端口驱动

在音频服务中，调用其他驱动接口前需要首先调用该接口检查端口是否已经初始化完成，如果端口驱动初始化完成，则函数返回值0， 否则返回负值，如果端口没有初始化完成，则需要等待一段时间（例如100ms）后重新进行检查，直到端口初始化完成后再继续操作

**参数：**

<a name="table90070450083931"></a>
<table><thead align="left"><tr id="row1768665177083931"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p834624781083931"><a name="p834624781083931"></a><a name="p834624781083931"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p2011595170083931"><a name="p2011595170083931"></a><a name="p2011595170083931"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row1685324761083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry668755300083931p0"><a name="entry668755300083931p0"></a><a name="entry668755300083931p0"></a>adapter</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1234808078083931p0"><a name="entry1234808078083931p0"></a><a name="entry1234808078083931p0"></a>待操作的音频适配器对象</p>
</td>
</tr>
</tbody>
</table>

**返回：**

成功返回值0，失败返回负值

## ReleaseAudioRoute<a name="a8ed77453f8082cac0783fc90a2fc64c5"></a>

```
int32_t(* AudioAdapter::ReleaseAudioRoute) (struct AudioAdapter *adapter, int32_t routeHandle)
```

**描述：**

释放一个音频路由.

**参数：**

<a name="table1335112550083931"></a>
<table><thead align="left"><tr id="row731053550083931"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1629423646083931"><a name="p1629423646083931"></a><a name="p1629423646083931"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1179119106083931"><a name="p1179119106083931"></a><a name="p1179119106083931"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row1818927413083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry363095364083931p0"><a name="entry363095364083931p0"></a><a name="entry363095364083931p0"></a>adapter</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1697766960083931p0"><a name="entry1697766960083931p0"></a><a name="entry1697766960083931p0"></a>待操作的音频适配器对象</p>
</td>
</tr>
<tr id="row1783855142083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1683180839083931p0"><a name="entry1683180839083931p0"></a><a name="entry1683180839083931p0"></a>routeHandle</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry249006190083931p0"><a name="entry249006190083931p0"></a><a name="entry249006190083931p0"></a>待释放的路由句柄.</p>
</td>
</tr>
</tbody>
</table>

**返回：**

成功返回值0，失败返回负值

## SetPassthroughMode<a name="a115fb7b21a1fe1b8412d24c380717bde"></a>

```
int(* AudioAdapter::SetPassthroughMode) (struct AudioAdapter *adapter, struct AudioPort *port, enum AudioPortPassthroughMode mode)
```

**描述：**

设置音频端口驱动的数据透传模式

**参数：**

<a name="table198880180083931"></a>
<table><thead align="left"><tr id="row467209455083931"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1720508207083931"><a name="p1720508207083931"></a><a name="p1720508207083931"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p713917706083931"><a name="p713917706083931"></a><a name="p713917706083931"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row393953041083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1368939809083931p0"><a name="entry1368939809083931p0"></a><a name="entry1368939809083931p0"></a>adapter</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry638292851083931p0"><a name="entry638292851083931p0"></a><a name="entry638292851083931p0"></a>待操作的音频适配器对象</p>
</td>
</tr>
<tr id="row2074380920083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry837331004083931p0"><a name="entry837331004083931p0"></a><a name="entry837331004083931p0"></a>port</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry369189134083931p0"><a name="entry369189134083931p0"></a><a name="entry369189134083931p0"></a>待设置的端口</p>
</td>
</tr>
<tr id="row1031022253083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1736930711083931p0"><a name="entry1736930711083931p0"></a><a name="entry1736930711083931p0"></a>mode</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry2102005480083931p0"><a name="entry2102005480083931p0"></a><a name="entry2102005480083931p0"></a>待设置的传输模式</p>
</td>
</tr>
</tbody>
</table>

**返回：**

成功返回值0，失败返回负值

**参见：**

[GetPassthroughMode](_audio_adapter.md#abd8f7f086993cb4ce34d01190db6cc11)

## UpdateAudioRoute<a name="abc83f0c9ca6f460b92f2ea10a5addb33"></a>

```
int32_t(* AudioAdapter::UpdateAudioRoute) (struct AudioAdapter *adapter, const struct AudioRoute *route, int32_t *routeHandle)
```

**描述：**

更新一个或多个发送端和接受端之间的路由

**参数：**

<a name="table1866175074083931"></a>
<table><thead align="left"><tr id="row1044565677083931"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1820520109083931"><a name="p1820520109083931"></a><a name="p1820520109083931"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1102011900083931"><a name="p1102011900083931"></a><a name="p1102011900083931"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row1427227083083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1983310767083931p0"><a name="entry1983310767083931p0"></a><a name="entry1983310767083931p0"></a>adapter</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1806864662083931p0"><a name="entry1806864662083931p0"></a><a name="entry1806864662083931p0"></a>待操作的音频适配器对象</p>
</td>
</tr>
<tr id="row1910305792083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1243111332083931p0"><a name="entry1243111332083931p0"></a><a name="entry1243111332083931p0"></a>route</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry897218259083931p0"><a name="entry897218259083931p0"></a><a name="entry897218259083931p0"></a>路由信息</p>
</td>
</tr>
<tr id="row729642529083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1955695939083931p0"><a name="entry1955695939083931p0"></a><a name="entry1955695939083931p0"></a>routeHandle</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry919297931083931p0"><a name="entry919297931083931p0"></a><a name="entry919297931083931p0"></a>生成的路由句柄</p>
</td>
</tr>
</tbody>
</table>

**返回：**

成功返回值0，失败返回负值

