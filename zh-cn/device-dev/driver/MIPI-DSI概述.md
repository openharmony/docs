# MIPI DSI概述<a name="ZH-CN_TOPIC_0000001062724343"></a>

-   [简介](#section1369320102013)
-   [接口说明](#section6577545192317)

## 简介<a name="section1369320102013"></a>

-   DSI（Display Serial Interface）是由移动行业处理器接口联盟（Mobile Industry Processor Interface \(MIPI\) Alliance）制定的规范，旨在降低移动设备中显示控制器的成本。它以串行的方式发送像素数据或指令给外设\(通常是LCD或者类似的显示设备\)，或从外设中读取状态信息或像素信息；它定义了主机、图像数据源和目标设备之间的串行总线和通信协议。

-   MIPI-DSI具备高速模式和低速模式两种工作模式，全部数据通道都可以用于单向的高速传输，但只有第一个数据通道才可用于低速双向传输，从属端的状态信息、像素等是通过该数据通道返回。时钟通道专用于在高速传输数据的过程中传输同步时钟信号。
    -   图1显示了简化的DSI接口。从概念上看，符合DSI的接口与基于DBI-2和DPI-2标准的接口具有相同的功能。它向外围设备传输像素或命令数据，并且可以从外围设备读取状态或像素信息。主要区别在于，DSI对所有像素数据、命令和事件进行序列化，而在传统接口中，这些像素数据、命令和事件通常需要附加控制信号才能在并行数据总线上传输。

        **图 1**  DSI发送、接收接口<a name="fig1122611461203"></a>  
        ![](figures/DSI发送-接收接口.png "DSI发送-接收接口")



## 接口说明<a name="section6577545192317"></a>

**表 1**  MIPI-DSI API接口功能介绍

<a name="table4199102313245"></a>
<table><thead align="left"><tr id="row1619910238244"><th class="cellrowborder" valign="top" width="26.619999999999997%" id="mcps1.2.4.1.1"><p id="p141991023182411"><a name="p141991023182411"></a><a name="p141991023182411"></a>功能分类</p>
</th>
<th class="cellrowborder" valign="top" width="28.910000000000004%" id="mcps1.2.4.1.2"><p id="p1199102315247"><a name="p1199102315247"></a><a name="p1199102315247"></a>接口名</p>
</th>
<th class="cellrowborder" valign="top" width="44.47%" id="mcps1.2.4.1.3"><p id="p719918232240"><a name="p719918232240"></a><a name="p719918232240"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row15199023172414"><td class="cellrowborder" rowspan="2" valign="top" width="26.619999999999997%" headers="mcps1.2.4.1.1 "><p id="p919902312413"><a name="p919902312413"></a><a name="p919902312413"></a>设置/获取当前MIPI-DSI相关配置</p>
</td>
<td class="cellrowborder" valign="top" width="28.910000000000004%" headers="mcps1.2.4.1.2 "><p id="p21995232243"><a name="p21995232243"></a><a name="p21995232243"></a>MipiDsiSetCfg</p>
</td>
<td class="cellrowborder" valign="top" width="44.47%" headers="mcps1.2.4.1.3 "><p id="p919911233240"><a name="p919911233240"></a><a name="p919911233240"></a>设置MIPI-DSI相关配置</p>
</td>
</tr>
<tr id="row171996232248"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p7199623152412"><a name="p7199623152412"></a><a name="p7199623152412"></a>MipiDsiGetCfg</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p1119919235248"><a name="p1119919235248"></a><a name="p1119919235248"></a>获取当前MIPI-DSI相关配置</p>
</td>
</tr>
<tr id="row91994239242"><td class="cellrowborder" rowspan="2" valign="top" width="26.619999999999997%" headers="mcps1.2.4.1.1 "><p id="p101998233245"><a name="p101998233245"></a><a name="p101998233245"></a>获取/释放MIPI-DSI操作句柄</p>
</td>
<td class="cellrowborder" valign="top" width="28.910000000000004%" headers="mcps1.2.4.1.2 "><p id="p51991323112415"><a name="p51991323112415"></a><a name="p51991323112415"></a>MipiDsiOpen</p>
</td>
<td class="cellrowborder" valign="top" width="44.47%" headers="mcps1.2.4.1.3 "><p id="p11991623182415"><a name="p11991623182415"></a><a name="p11991623182415"></a>获取MIPI-DSI操作句柄</p>
</td>
</tr>
<tr id="row12199192352411"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p131991123172412"><a name="p131991123172412"></a><a name="p131991123172412"></a>MipiDsiClose</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p520062313249"><a name="p520062313249"></a><a name="p520062313249"></a>释放MIPI-DSI操作句柄</p>
</td>
</tr>
<tr id="row7200152382417"><td class="cellrowborder" rowspan="2" valign="top" width="26.619999999999997%" headers="mcps1.2.4.1.1 "><p id="p8200202312241"><a name="p8200202312241"></a><a name="p8200202312241"></a>设置MIPI-DSI进入Low power模式/High speed模式</p>
</td>
<td class="cellrowborder" valign="top" width="28.910000000000004%" headers="mcps1.2.4.1.2 "><p id="p6200192318247"><a name="p6200192318247"></a><a name="p6200192318247"></a>MipiDsiSetLpMode</p>
</td>
<td class="cellrowborder" valign="top" width="44.47%" headers="mcps1.2.4.1.3 "><p id="p16200192319240"><a name="p16200192319240"></a><a name="p16200192319240"></a>设置MIPI-DSI进入Low power模式</p>
</td>
</tr>
<tr id="row122001523182417"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p22009236249"><a name="p22009236249"></a><a name="p22009236249"></a>MipiDsiSetHsMode</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p22001423192418"><a name="p22001423192418"></a><a name="p22001423192418"></a>设置MIPI-DSI进入High speed模式</p>
</td>
</tr>
<tr id="row52002237248"><td class="cellrowborder" rowspan="2" valign="top" width="26.619999999999997%" headers="mcps1.2.4.1.1 "><p id="p10200162332412"><a name="p10200162332412"></a><a name="p10200162332412"></a>MIPI-DSI发送/回读指令</p>
</td>
<td class="cellrowborder" valign="top" width="28.910000000000004%" headers="mcps1.2.4.1.2 "><p id="p19200142315249"><a name="p19200142315249"></a><a name="p19200142315249"></a>MipiDsiTx</p>
</td>
<td class="cellrowborder" valign="top" width="44.47%" headers="mcps1.2.4.1.3 "><p id="p1020082319243"><a name="p1020082319243"></a><a name="p1020082319243"></a>MIPI-DSI发送相应指令的接口</p>
</td>
</tr>
<tr id="row6200162372416"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p18200112392417"><a name="p18200112392417"></a><a name="p18200112392417"></a>MipiDsiRx</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p9200102312249"><a name="p9200102312249"></a><a name="p9200102312249"></a>MIPI-DSI按期望长度回读的接口</p>
</td>
</tr>
</tbody>
</table>

>![](public_sys-resources/icon-note.gif) **说明：** 
>本文涉及的所有接口，仅限内核态使用，不支持在用户态使用

