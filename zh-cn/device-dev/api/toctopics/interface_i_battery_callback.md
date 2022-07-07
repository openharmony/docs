# IBatteryCallback<a name="ZH-CN_TOPIC_0000001290561176"></a>

## **概述**<a name="section124697118083932"></a>

**所属模块:**

[Battery](battery.md)

## **汇总**<a name="section1482628090083932"></a>

## Public 成员函数<a name="pub-methods"></a>

<a name="table1529482294083932"></a>
<table><thead align="left"><tr id="row2059894638083932"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1843442775083932"><a name="p1843442775083932"></a><a name="p1843442775083932"></a>Public 成员函数</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p234580731083932"><a name="p234580731083932"></a><a name="p234580731083932"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row1300228949083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2005977873083932"><a name="p2005977873083932"></a><a name="p2005977873083932"></a><a href="interface_i_battery_callback.md#a8fa894451339e0227a508cf8e0be1c03">Update</a> ([in] struct <a href="_battery_info.md">BatteryInfo</a> event)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p559856486083932"><a name="p559856486083932"></a><a name="p559856486083932"></a>电池信息的回调方法。 <a href="interface_i_battery_callback.md#a8fa894451339e0227a508cf8e0be1c03">更多...</a></p>
</td>
</tr>
</tbody>
</table>

## **详细描述**<a name="section358109784083932"></a>

电池信息的回调。

服务创建此回调对象后，可以调用IBatteryInterface的接口注册回调，从而订阅电池信息的变化。

**Since：**

3.1

## **成员函数说明**<a name="section925964582083932"></a>

## Update\(\)<a name="a8fa894451339e0227a508cf8e0be1c03"></a>

```
IBatteryCallback::Update ([in] struct BatteryInfo event)
```

**描述：**

电池信息的回调方法。

当电池信息发生变化时，将通过此方法的参数返回给服务。

**参数：**

<a name="table1813126431083932"></a>
<table><thead align="left"><tr id="row467926975083932"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p83246914083932"><a name="p83246914083932"></a><a name="p83246914083932"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1915282210083932"><a name="p1915282210083932"></a><a name="p1915282210083932"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row320736768083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry639291058083932p0"><a name="entry639291058083932p0"></a><a name="entry639291058083932p0"></a>event</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry519566028083932p0"><a name="entry519566028083932p0"></a><a name="entry519566028083932p0"></a>电池信息，如电量，电压，健康状态等。</p>
</td>
</tr>
</tbody>
</table>

**参见：**

[BatteryInfo](_battery_info.md)

