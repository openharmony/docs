# VibratorInterface<a name="ZH-CN_TOPIC_0000001343120377"></a>

## **概述**<a name="section381545287083932"></a>

**所属模块:**

[Vibrator](_vibrator.md)

## **汇总**<a name="section580641793083932"></a>

## Public 属性<a name="pub-attribs"></a>

<a name="table99888158083932"></a>
<table><thead align="left"><tr id="row121089406083932"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1437598861083932"><a name="p1437598861083932"></a><a name="p1437598861083932"></a>Public 属性</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1727160057083932"><a name="p1727160057083932"></a><a name="p1727160057083932"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row970711560083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1667305637083932"><a name="p1667305637083932"></a><a name="p1667305637083932"></a>( <a href="_vibrator_interface.md#a877bdc8efbb78ee69ed845f7abe4ae94">StartOnce</a> )([in] uint32_t duration)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p728628818083932"><a name="p728628818083932"></a><a name="p728628818083932"></a>控制马达以执行给定持续时间的一次性振动。 <a href="_vibrator_interface.md#a877bdc8efbb78ee69ed845f7abe4ae94">更多...</a></p>
</td>
</tr>
<tr id="row563117959083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p415745690083932"><a name="p415745690083932"></a><a name="p415745690083932"></a>( <a href="_vibrator_interface.md#a6a76422b3b3ef1d44fb39a2309aec311">Start</a> )([in] const char *effectType)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p477539458083932"><a name="p477539458083932"></a><a name="p477539458083932"></a>控制马达以预置效果执行周期性振动。 <a href="_vibrator_interface.md#a6a76422b3b3ef1d44fb39a2309aec311">更多...</a></p>
</td>
</tr>
<tr id="row623036666083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2086987059083932"><a name="p2086987059083932"></a><a name="p2086987059083932"></a>( <a href="_vibrator_interface.md#a33ac464ed7c29a7e2bad855683e7af2e">Stop</a> )([in] enum <a href="_vibrator.md#gadbbc422555ccc89c4d9cf80f5175af2f">VibratorMode</a> mode)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2090585445083932"><a name="p2090585445083932"></a><a name="p2090585445083932"></a>停止马达振动。 <a href="_vibrator_interface.md#a33ac464ed7c29a7e2bad855683e7af2e">更多...</a></p>
</td>
</tr>
</tbody>
</table>

## **详细描述**<a name="section187222013144617"></a>

提供Vibrator设备基本控制操作接口。

## **类成员变量说明**<a name="section1260559321083932"></a>

## Start<a name="a6a76422b3b3ef1d44fb39a2309aec311"></a>

```
int32_t(* VibratorInterface::Start) ([in] const char *effectType)
```

**描述：**

控制马达以预置效果执行周期性振动。

单次振动与周期振动相互排斥。在执行一次性振动之前，需退出周期性振动。

**参数：**

<a name="table1174185332083932"></a>
<table><thead align="left"><tr id="row2039373401083932"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1219762527083932"><a name="p1219762527083932"></a><a name="p1219762527083932"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1141567620083932"><a name="p1141567620083932"></a><a name="p1141567620083932"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row416570715083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry197722133083932p0"><a name="entry197722133083932p0"></a><a name="entry197722133083932p0"></a>effectType</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1409906799083932p0"><a name="entry1409906799083932p0"></a><a name="entry1409906799083932p0"></a>指向指示预置效果类型的指针。</p>
</td>
</tr>
</tbody>
</table>

**返回：**

如果操作成功，则返回0。

如果操作失败，则返回负值。

## StartOnce<a name="a877bdc8efbb78ee69ed845f7abe4ae94"></a>

```
int32_t(* VibratorInterface::StartOnce) ([in] uint32_t duration)
```

**描述：**

控制马达以执行给定持续时间的一次性振动。

单次振动与周期振动相互排斥。在执行一次性振动之前，需退出周期性振动。

**参数：**

<a name="table1010470015083932"></a>
<table><thead align="left"><tr id="row1442992669083932"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p177493849083932"><a name="p177493849083932"></a><a name="p177493849083932"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p258375750083932"><a name="p258375750083932"></a><a name="p258375750083932"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row1383478791083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1772742847083932p0"><a name="entry1772742847083932p0"></a><a name="entry1772742847083932p0"></a>duration</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry778215294083932p0"><a name="entry778215294083932p0"></a><a name="entry778215294083932p0"></a>指示一次性振动的持续时间，以毫秒为单位。</p>
</td>
</tr>
</tbody>
</table>

**返回：**

如果操作成功，则返回0。

如果操作失败，则返回负值。

## Stop<a name="a33ac464ed7c29a7e2bad855683e7af2e"></a>

```
int32_t(* VibratorInterface::Stop) ([in] enum VibratorMode mode)
```

**描述：**

停止马达振动。

马达启动前，必须在任何模式下停止振动。此功能用在振动过程之后。

**参数：**

<a name="table1913005889083932"></a>
<table><thead align="left"><tr id="row1376814794083932"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p554090892083932"><a name="p554090892083932"></a><a name="p554090892083932"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1749304227083932"><a name="p1749304227083932"></a><a name="p1749304227083932"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row777063611083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1682054025083932p0"><a name="entry1682054025083932p0"></a><a name="entry1682054025083932p0"></a>mode</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1213781046083932p0"><a name="entry1213781046083932p0"></a><a name="entry1213781046083932p0"></a>指示振动模式，可以是一次性或周期性的，详见<a href="_vibrator.md#gadbbc422555ccc89c4d9cf80f5175af2f">VibratorMode</a>。</p>
</td>
</tr>
</tbody>
</table>

**返回：**

如果操作成功，则返回0。

如果操作失败，则返回负值。

