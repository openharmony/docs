# PowerTypes.idl<a name="ZH-CN_TOPIC_0000001291040612"></a>

## **概述**<a name="section681618265083932"></a>

**所属模块:**

[Power](power.md)

## **汇总**<a name="section1716155818083932"></a>

## 枚举<a name="enum-members"></a>

<a name="table491589914083932"></a>
<table><thead align="left"><tr id="row840450493083932"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1936449539083932"><a name="p1936449539083932"></a><a name="p1936449539083932"></a>枚举</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p428061112083932"><a name="p428061112083932"></a><a name="p428061112083932"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row1746346028083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2017896878083932"><a name="p2017896878083932"></a><a name="p2017896878083932"></a><a href="power.md#ga0c9f68a1cf4b1b76a8253281688a499f">PowerHdfCmd</a> {   <a href="power.md#gga0c9f68a1cf4b1b76a8253281688a499fadb8d2fd75158645b1cd01cab62a11e48">CMD_REGISTER_CALLBCK</a> = 0, <a href="power.md#gga0c9f68a1cf4b1b76a8253281688a499fab1d1e95415b8a9ab070fed3200b5f1d3">CMD_START_SUSPEND</a>, <a href="power.md#gga0c9f68a1cf4b1b76a8253281688a499fa65c754fdc432aa2a6f13c27cb97c27de">CMD_STOP_SUSPEND</a>, <a href="power.md#gga0c9f68a1cf4b1b76a8253281688a499faa96402e649008dcafce89c7a47c6f266">CMD_FORCE_SUSPEND</a>,   <a href="power.md#gga0c9f68a1cf4b1b76a8253281688a499fa0766f8c155a9de9fc7168a498c8317da">CMD_SUSPEND_BLOCK</a>, <a href="power.md#gga0c9f68a1cf4b1b76a8253281688a499fa840d1fd2227dfea25fcee7217deb82ed">CMD_SUSPEND_UNBLOCK</a>, <a href="power.md#gga0c9f68a1cf4b1b76a8253281688a499fab92b7d7125239e258bd22cd1a35aba0d">CMD_DUMP</a> }</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p40871966083932"><a name="p40871966083932"></a><a name="p40871966083932"></a>枚举电源命令的参数。 <a href="power.md#ga0c9f68a1cf4b1b76a8253281688a499f">更多...</a></p>
</td>
</tr>
<tr id="row1027979943083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1812298973083932"><a name="p1812298973083932"></a><a name="p1812298973083932"></a><a href="power.md#ga4bbb7ca0dc24efe3980c39cd409b4109">PowerHdfCallbackCmd</a> { <a href="power.md#gga4bbb7ca0dc24efe3980c39cd409b4109a6d4a3ebd4580d7303df66d5ea9ad98d1">CMD_ON_SUSPEND</a> = 0, <a href="power.md#gga4bbb7ca0dc24efe3980c39cd409b4109a4d0194285647be62fe2c191cad95e72f">CMD_ON_WAKEUP</a> }</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p442067241083932"><a name="p442067241083932"></a><a name="p442067241083932"></a>枚举电源状态回调的参数。 <a href="power.md#ga4bbb7ca0dc24efe3980c39cd409b4109">更多...</a></p>
</td>
</tr>
<tr id="row527651950083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p104650558083932"><a name="p104650558083932"></a><a name="p104650558083932"></a><a href="power.md#gadf82dc0e2ae04729ac8fabb3e3d28ecd">PowerHdfState</a> { <a href="power.md#ggadf82dc0e2ae04729ac8fabb3e3d28ecda65e803ac3fb48fa726e326f3c63c2d83">AWAKE</a> = 0, <a href="power.md#ggadf82dc0e2ae04729ac8fabb3e3d28ecda3ff8ba88da6f8947ab7c22b7825c6bb6">INACTIVE</a>, <a href="power.md#ggadf82dc0e2ae04729ac8fabb3e3d28ecdad6137abebe4fdc59e2f0f2c84bdbe3fa">SLEEP</a> }</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p884844900083932"><a name="p884844900083932"></a><a name="p884844900083932"></a>枚举电源的状态。 <a href="power.md#gadf82dc0e2ae04729ac8fabb3e3d28ecd">更多...</a></p>
</td>
</tr>
</tbody>
</table>

## 变量<a name="var-members"></a>

<a name="table1154430472083932"></a>
<table><thead align="left"><tr id="row2049105101083932"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1128992350083932"><a name="p1128992350083932"></a><a name="p1128992350083932"></a>变量 名称</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1113138121083932"><a name="p1113138121083932"></a><a name="p1113138121083932"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row1995953653083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1315201920194"><a name="p1315201920194"></a><a name="p1315201920194"></a>package ohos.hdi.power.v1_0</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p33555584336"><a name="p33555584336"></a><a name="p33555584336"></a>电源管理接口的包路径</p>
</td>
</tr>
</tbody>
</table>

## **详细描述**<a name="section131361357083932"></a>

电源相关的数据类型。

电源管理中使用的数据类型，包括命令参数、回调参数和系统状态。

**Since：**

3.1

**Version：**

1.0

