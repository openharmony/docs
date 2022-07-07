# wifi\_hal\_ap\_feature.h<a name="ZH-CN_TOPIC_0000001290721044"></a>

## **概述**<a name="section2001746673083931"></a>

**所属模块:**

[WLAN](_w_l_a_n.md)

## **汇总**<a name="section942732506083931"></a>

## 类<a name="nested-classes"></a>

<a name="table916933557083931"></a>
<table><thead align="left"><tr id="row389135583083931"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p612753111083931"><a name="p612753111083931"></a><a name="p612753111083931"></a>类</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1048080075083931"><a name="p1048080075083931"></a><a name="p1048080075083931"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row1118085906083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p89771846083931"><a name="p89771846083931"></a><a name="p89771846083931"></a><a href="_sta_info.md">StaInfo</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p884722767083931"><a name="p884722767083931"></a><a name="p884722767083931"></a>描述与AP连接的STA的基本信息 <a href="_sta_info.md">更多...</a></p>
</td>
</tr>
<tr id="row1624001836083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1755611141083931"><a name="p1755611141083931"></a><a name="p1755611141083931"></a><a href="_i_wi_fi_ap.md">IWiFiAp</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1911069892083931"><a name="p1911069892083931"></a><a name="p1911069892083931"></a>继承了<a href="_i_wi_fi_base_feature.md">IWiFiBaseFeature</a>基本特性，并包含AP模式下获取连接STA的信息和设置国家码的功能。 <a href="_i_wi_fi_ap.md">更多...</a></p>
</td>
</tr>
</tbody>
</table>

## 函数<a name="func-members"></a>

<a name="table2110382105083931"></a>
<table><thead align="left"><tr id="row2084510723083931"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p534279404083931"><a name="p534279404083931"></a><a name="p534279404083931"></a>函数</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1684776992083931"><a name="p1684776992083931"></a><a name="p1684776992083931"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row1649897323083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p621297651083931"><a name="p621297651083931"></a><a name="p621297651083931"></a><a href="_w_l_a_n.md#ga8c820a2d357baffe0916b27f10f4be22">InitApFeature</a> (struct <a href="_i_wi_fi_ap.md">IWiFiAp</a> **fe)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1582747315083931"><a name="p1582747315083931"></a><a name="p1582747315083931"></a>初始化AP特性。WLAN服务在创建AP类型的特性<a href="_w_l_a_n.md#gad2b28a6ade408676d1371ea941824012">FeatureType</a>时调用。 <a href="_w_l_a_n.md#ga8c820a2d357baffe0916b27f10f4be22">更多...</a></p>
</td>
</tr>
</tbody>
</table>

## **详细描述**<a name="section2142007408083931"></a>

提供WLAN的AP特性能力（获取与AP连接的STA的基本信息、设置国家码）。

**Since：**

1.0

**Version：**

1.0

