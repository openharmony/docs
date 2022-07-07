# dac\_if.h<a name="ZH-CN_TOPIC_0000001290840880"></a>

## **概述**<a name="section1135431994083931"></a>

**所属模块:**

[DAC](_d_a_c.md)

## **汇总**<a name="section1027492380083931"></a>

## 类<a name="nested-classes"></a>

<a name="table2079430363083931"></a>
<table><thead align="left"><tr id="row840133903083931"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p2102319331083931"><a name="p2102319331083931"></a><a name="p2102319331083931"></a>类</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p38459796083931"><a name="p38459796083931"></a><a name="p38459796083931"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row872366921083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1196223683083931"><a name="p1196223683083931"></a><a name="p1196223683083931"></a><a href="_dac_io_msg.md">DacIoMsg</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1499454272083931"><a name="p1499454272083931"></a><a name="p1499454272083931"></a>DAC设备信息传输结构体 <a href="_dac_io_msg.md">更多...</a></p>
</td>
</tr>
</tbody>
</table>

## 函数<a name="func-members"></a>

<a name="table803059932083931"></a>
<table><thead align="left"><tr id="row650207118083931"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p722981904083931"><a name="p722981904083931"></a><a name="p722981904083931"></a>函数</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p957198412083931"><a name="p957198412083931"></a><a name="p957198412083931"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row149703990083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p175081988083931"><a name="p175081988083931"></a><a name="p175081988083931"></a><a href="_d_a_c.md#gacf3c353a85e1fe5f1244b5a2899d358d">DacOpen</a> (uint32_t number)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1568536608083931"><a name="p1568536608083931"></a><a name="p1568536608083931"></a>获取DAC控制器的句柄。 <a href="_d_a_c.md#gacf3c353a85e1fe5f1244b5a2899d358d">更多...</a></p>
</td>
</tr>
<tr id="row2060106832083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1296491306083931"><a name="p1296491306083931"></a><a name="p1296491306083931"></a><a href="_d_a_c.md#ga18777f73a55de3684bc3c711bbe676aa">DacClose</a> (DevHandle handle)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1240979235083931"><a name="p1240979235083931"></a><a name="p1240979235083931"></a>释放DAC控制器的句柄。 <a href="_d_a_c.md#ga18777f73a55de3684bc3c711bbe676aa">更多...</a></p>
</td>
</tr>
<tr id="row1342345778083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1661832475083931"><a name="p1661832475083931"></a><a name="p1661832475083931"></a><a href="_d_a_c.md#ga57a778e69c19f30563ab18d4eb388267">DacWrite</a> (DevHandle handle, uint32_t channel, uint32_t val)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p899410262083931"><a name="p899410262083931"></a><a name="p899410262083931"></a>启动DAC设备进行传输，将目标值写入指定的DAC通道。 <a href="_d_a_c.md#ga57a778e69c19f30563ab18d4eb388267">更多...</a></p>
</td>
</tr>
</tbody>
</table>

## **详细描述**<a name="section1064408574083931"></a>

声明标准DAC接口函数。

**Since：**

3.1

