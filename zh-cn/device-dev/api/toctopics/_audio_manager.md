# AudioManager<a name="ZH-CN_TOPIC_0000001343000837"></a>

## **概述**<a name="section1023179890083931"></a>

**所属模块:**

[Audio](_audio.md)

## **汇总**<a name="section1191788726083931"></a>

## Public 属性<a name="pub-attribs"></a>

<a name="table715342202083931"></a>
<table><thead align="left"><tr id="row1403344088083931"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p940288463083931"><a name="p940288463083931"></a><a name="p940288463083931"></a>Public 属性</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1670819264083931"><a name="p1670819264083931"></a><a name="p1670819264083931"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row731921433083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1243790664083931"><a name="p1243790664083931"></a><a name="p1243790664083931"></a>( <a href="_audio_manager.md#a385ae18dad8e513fcfc49c3384cdf030">GetAllAdapters</a> )(struct AudioAdapterManager *manager, struct <a href="_audio_adapter_descriptor.md">AudioAdapterDescriptor</a> **descs, int *size)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p667040946083931"><a name="p667040946083931"></a><a name="p667040946083931"></a>获取音频驱动中支持的所有适配器的列表 <a href="_audio_manager.md#a385ae18dad8e513fcfc49c3384cdf030">更多...</a></p>
</td>
</tr>
<tr id="row826099235083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1727951871083931"><a name="p1727951871083931"></a><a name="p1727951871083931"></a>( <a href="_audio_manager.md#a94e701aaf2952efac2369688b0704e4d">LoadAdapter</a> )(struct AudioAdapterManager *manager, const struct <a href="_audio_adapter_descriptor.md">AudioAdapterDescriptor</a> *desc, struct <a href="_audio_adapter.md">AudioAdapter</a> **adapter)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p925716283083931"><a name="p925716283083931"></a><a name="p925716283083931"></a>加载一个音频适配器（声卡）的驱动 <a href="_audio_manager.md#a94e701aaf2952efac2369688b0704e4d">更多...</a></p>
</td>
</tr>
<tr id="row952877918083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p122692822083931"><a name="p122692822083931"></a><a name="p122692822083931"></a>( <a href="_audio_manager.md#a2e6760aa74554355b0379c9594937b3a">UnloadAdapter</a> )(struct AudioAdapterManager *manager, struct <a href="_audio_adapter.md">AudioAdapter</a> *adapter)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2031871913083931"><a name="p2031871913083931"></a><a name="p2031871913083931"></a>卸载音频适配器（声卡）的驱动 <a href="_audio_manager.md#a2e6760aa74554355b0379c9594937b3a">更多...</a></p>
</td>
</tr>
<tr id="row305528369083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1838378131083931"><a name="p1838378131083931"></a><a name="p1838378131083931"></a>( <a href="_audio_manager.md#ae3747f703a05690da84b7f2ec794a23d">ReleaseAudioManagerObject</a> )(struct <a href="_audio_manager.md">AudioManager</a> *object)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1677599217083931"><a name="p1677599217083931"></a><a name="p1677599217083931"></a>释放音频管理接口对象 <a href="_audio_manager.md#ae3747f703a05690da84b7f2ec794a23d">更多...</a></p>
</td>
</tr>
</tbody>
</table>

## **详细描述**<a name="section1274143706083931"></a>

AudioManager音频适配器管理接口

按照音频服务下发的音频适配器（声卡）描述符加载一个具体的音频适配器驱动程序

参见：

[AudioAdapter](_audio_adapter.md)

**Since：**

1.0

**Version：**

1.0

## **类成员变量说明**<a name="section1621946444083931"></a>

## GetAllAdapters<a name="a385ae18dad8e513fcfc49c3384cdf030"></a>

```
int(* AudioManager::GetAllAdapters) (struct AudioAdapterManager *manager, struct AudioAdapterDescriptor **descs, int *size)
```

**描述：**

获取音频驱动中支持的所有适配器的列表

**参数：**

<a name="table1242803433083931"></a>
<table><thead align="left"><tr id="row1821797894083931"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1358753324083931"><a name="p1358753324083931"></a><a name="p1358753324083931"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1288160422083931"><a name="p1288160422083931"></a><a name="p1288160422083931"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row1778139503083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry460085762083931p0"><a name="entry460085762083931p0"></a><a name="entry460085762083931p0"></a>manager</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1112393497083931p0"><a name="entry1112393497083931p0"></a><a name="entry1112393497083931p0"></a>待操作的音频管理接口对象</p>
</td>
</tr>
<tr id="row821358184083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry964421821083931p0"><a name="entry964421821083931p0"></a><a name="entry964421821083931p0"></a>descs</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1415225111083931p0"><a name="entry1415225111083931p0"></a><a name="entry1415225111083931p0"></a>获取到的音频适配器列表保存到descs中</p>
</td>
</tr>
<tr id="row621972126083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry614311181083931p0"><a name="entry614311181083931p0"></a><a name="entry614311181083931p0"></a>size</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry847344655083931p0"><a name="entry847344655083931p0"></a><a name="entry847344655083931p0"></a>获取到的音频适配器列表的长度保存到size中</p>
</td>
</tr>
</tbody>
</table>

**返回：**

成功返回值0，失败返回负值

**参见：**

[LoadAdapter](_audio_manager.md#a94e701aaf2952efac2369688b0704e4d)

## LoadAdapter<a name="a94e701aaf2952efac2369688b0704e4d"></a>

```
int(* AudioManager::LoadAdapter) (struct AudioAdapterManager *manager, const struct AudioAdapterDescriptor *desc, struct AudioAdapter **adapter)
```

**描述：**

加载一个音频适配器（声卡）的驱动

加载一个具体的音频驱动，例如usb驱动，在具体实现中可能加载的是一个动态链接库（\*.so）

**参数：**

<a name="table102040320083931"></a>
<table><thead align="left"><tr id="row1520529502083931"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p564857632083931"><a name="p564857632083931"></a><a name="p564857632083931"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p2040509698083931"><a name="p2040509698083931"></a><a name="p2040509698083931"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row1141142322083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1077405973083931p0"><a name="entry1077405973083931p0"></a><a name="entry1077405973083931p0"></a>manager</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry2048774147083931p0"><a name="entry2048774147083931p0"></a><a name="entry2048774147083931p0"></a>待操作的音频管理接口对象</p>
</td>
</tr>
<tr id="row1650957433083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1268990849083931p0"><a name="entry1268990849083931p0"></a><a name="entry1268990849083931p0"></a>desc</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry2145470067083931p0"><a name="entry2145470067083931p0"></a><a name="entry2145470067083931p0"></a>待加载的音频适配器描述符</p>
</td>
</tr>
<tr id="row1893034319083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry2131315588083931p0"><a name="entry2131315588083931p0"></a><a name="entry2131315588083931p0"></a>adapter</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1998960310083931p0"><a name="entry1998960310083931p0"></a><a name="entry1998960310083931p0"></a>获取的音频适配器接口的对象实例保存到adapter中</p>
</td>
</tr>
</tbody>
</table>

**返回：**

成功返回值0，失败返回负值

**参见：**

[GetAllAdapters](_audio_manager.md#a385ae18dad8e513fcfc49c3384cdf030)

[UnloadAdapter](_audio_manager.md#a2e6760aa74554355b0379c9594937b3a)

## ReleaseAudioManagerObject<a name="ae3747f703a05690da84b7f2ec794a23d"></a>

```
bool(* AudioManager::ReleaseAudioManagerObject) (struct AudioManager *object)
```

**描述：**

释放音频管理接口对象

**参数：**

<a name="table76889502083931"></a>
<table><thead align="left"><tr id="row1638437325083931"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1902698813083931"><a name="p1902698813083931"></a><a name="p1902698813083931"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1076850445083931"><a name="p1076850445083931"></a><a name="p1076850445083931"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row1292643495083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1994421516083931p0"><a name="entry1994421516083931p0"></a><a name="entry1994421516083931p0"></a>object</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1320023755083931p0"><a name="entry1320023755083931p0"></a><a name="entry1320023755083931p0"></a>待操作的音频管理接口对象</p>
</td>
</tr>
</tbody>
</table>

**返回：**

成功返回ture，失败返回false

## UnloadAdapter<a name="a2e6760aa74554355b0379c9594937b3a"></a>

```
void(* AudioManager::UnloadAdapter) (struct AudioAdapterManager *manager, struct AudioAdapter *adapter)
```

**描述：**

卸载音频适配器（声卡）的驱动

**参数：**

<a name="table567678803083931"></a>
<table><thead align="left"><tr id="row435257995083931"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1050017873083931"><a name="p1050017873083931"></a><a name="p1050017873083931"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1122844951083931"><a name="p1122844951083931"></a><a name="p1122844951083931"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row1480983287083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1888163089083931p0"><a name="entry1888163089083931p0"></a><a name="entry1888163089083931p0"></a>manager</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry661979913083931p0"><a name="entry661979913083931p0"></a><a name="entry661979913083931p0"></a>待操作的音频管理接口对象</p>
</td>
</tr>
<tr id="row1732729807083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1362978436083931p0"><a name="entry1362978436083931p0"></a><a name="entry1362978436083931p0"></a>adapter</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1994310700083931p0"><a name="entry1994310700083931p0"></a><a name="entry1994310700083931p0"></a>待卸载的音频适配器接口的对象</p>
</td>
</tr>
</tbody>
</table>

**参见：**

[LoadAdapter](_audio_manager.md#a94e701aaf2952efac2369688b0704e4d)

