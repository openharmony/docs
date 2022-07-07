# wifi\_hal.h<a name="ZH-CN_TOPIC_0000001291040548"></a>

## **概述**<a name="section1021461831083931"></a>

**所属模块:**

[WLAN](_w_l_a_n.md)

## **汇总**<a name="section1790692579083931"></a>

## 类<a name="nested-classes"></a>

<a name="table920000968083931"></a>
<table><thead align="left"><tr id="row1886338816083931"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p2061000069083931"><a name="p2061000069083931"></a><a name="p2061000069083931"></a>类</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p190672384083931"><a name="p190672384083931"></a><a name="p190672384083931"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row1331762498083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2128098405083931"><a name="p2128098405083931"></a><a name="p2128098405083931"></a><a href="_i_wi_fi.md">IWiFi</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p5172312083931"><a name="p5172312083931"></a><a name="p5172312083931"></a>HAL对WLAN服务提供的基本能力。 <a href="_i_wi_fi.md">更多...</a></p>
</td>
</tr>
</tbody>
</table>

## 类型定义<a name="typedef-members"></a>

<a name="table1154856931083931"></a>
<table><thead align="left"><tr id="row191845830083931"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1747191552083931"><a name="p1747191552083931"></a><a name="p1747191552083931"></a>类型定义</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1850272801083931"><a name="p1850272801083931"></a><a name="p1850272801083931"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row1381549923083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p986892011083931"><a name="p986892011083931"></a><a name="p986892011083931"></a>(<a href="_w_l_a_n.md#gaa7dd2fac193e1b8de1e2c063b2ed175a">CallbackFunc</a>) (uint32_t event, void *data, const char *ifName)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1935611885083931"><a name="p1935611885083931"></a><a name="p1935611885083931"></a>定义IWiFi回调函数的原型，监听异步事件。 <a href="_w_l_a_n.md#gaa7dd2fac193e1b8de1e2c063b2ed175a">更多...</a></p>
</td>
</tr>
</tbody>
</table>

## 函数<a name="func-members"></a>

<a name="table76452389083931"></a>
<table><thead align="left"><tr id="row1465399398083931"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p846529664083931"><a name="p846529664083931"></a><a name="p846529664083931"></a>函数</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1992406661083931"><a name="p1992406661083931"></a><a name="p1992406661083931"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row369121474083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1456569668083931"><a name="p1456569668083931"></a><a name="p1456569668083931"></a><a href="_w_l_a_n.md#ga02c5deac16c60604e57214e64fdb1daa">WifiConstruct</a> (struct <a href="_i_wi_fi.md">IWiFi</a> **wifiInstance)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p900287254083931"><a name="p900287254083931"></a><a name="p900287254083931"></a>创建IWiFi结构体，挂接<a href="_i_wi_fi.md">IWiFi</a>中能力接口。 <a href="_w_l_a_n.md#ga02c5deac16c60604e57214e64fdb1daa">更多...</a></p>
</td>
</tr>
<tr id="row331029119083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1373160927083931"><a name="p1373160927083931"></a><a name="p1373160927083931"></a><a href="_w_l_a_n.md#gab80897fa4893947e591ca35efb55353a">WifiDestruct</a> (struct <a href="_i_wi_fi.md">IWiFi</a> **wifiInstance)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p655441354083931"><a name="p655441354083931"></a><a name="p655441354083931"></a>销毁IWiFi结构体并释放相关资源。 <a href="_w_l_a_n.md#gab80897fa4893947e591ca35efb55353a">更多...</a></p>
</td>
</tr>
</tbody>
</table>

## **详细描述**<a name="section1737175181083931"></a>

提供给WLAN服务的WLAN基本能力接口。

**Since：**

1.0

**Version：**

1.0

