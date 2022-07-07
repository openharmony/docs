# OHOS::USB::UsbdClient<a name="ZH-CN_TOPIC_0000001291040608"></a>

## **概述**<a name="section806551876083932"></a>

**所属模块:**

[USB](_u_s_b.md)

## **汇总**<a name="section434376776083932"></a>

## Public 成员函数<a name="pub-methods"></a>

<a name="table1165126080083932"></a>
<table><thead align="left"><tr id="row644600954083932"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p793241205083932"><a name="p793241205083932"></a><a name="p793241205083932"></a>Public 成员函数</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p2044489348083932"><a name="p2044489348083932"></a><a name="p2044489348083932"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row386543439083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p653772092083932"><a name="p653772092083932"></a><a name="p653772092083932"></a><a href="_u_s_b.md#ga2030ca1ae743d99d234a58f1ee35b496">OpenDevice</a> (const <a href="_o_h_o_s_1_1_u_s_b_1_1_usb_dev.md">UsbDev</a> &amp;dev)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1544239059083932"><a name="p1544239059083932"></a><a name="p1544239059083932"></a>打开设备，建立连接。 <a href="_u_s_b.md#ga2030ca1ae743d99d234a58f1ee35b496">更多...</a></p>
</td>
</tr>
<tr id="row192335736083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1958091724083932"><a name="p1958091724083932"></a><a name="p1958091724083932"></a><a href="_u_s_b.md#ga770abf33339a25186aee5949b30da2a8">CloseDevice</a> (const <a href="_o_h_o_s_1_1_u_s_b_1_1_usb_dev.md">UsbDev</a> &amp;dev)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1389622744083932"><a name="p1389622744083932"></a><a name="p1389622744083932"></a>关闭设备，释放与设备相关的所有系统资源。 <a href="_u_s_b.md#ga770abf33339a25186aee5949b30da2a8">更多...</a></p>
</td>
</tr>
<tr id="row1462825030083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p868707605083932"><a name="p868707605083932"></a><a name="p868707605083932"></a><a href="_u_s_b.md#ga21bbd11a882ef5c6f8977776b2e21c76">GetDeviceDescriptor</a> (const <a href="_o_h_o_s_1_1_u_s_b_1_1_usb_dev.md">UsbDev</a> &amp;dev, std::vector&lt; uint8_t &gt; &amp;descriptor)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p330701434083932"><a name="p330701434083932"></a><a name="p330701434083932"></a>获取设备描述符。 <a href="_u_s_b.md#ga21bbd11a882ef5c6f8977776b2e21c76">更多...</a></p>
</td>
</tr>
<tr id="row1440594780083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p294526020083932"><a name="p294526020083932"></a><a name="p294526020083932"></a><a href="_u_s_b.md#gab22f143738b0532acf297a9ef2403446">GetStringDescriptor</a> (const <a href="_o_h_o_s_1_1_u_s_b_1_1_usb_dev.md">UsbDev</a> &amp;dev, uint8_t descId, std::vector&lt; uint8_t &gt; &amp;descriptor)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1972003578083932"><a name="p1972003578083932"></a><a name="p1972003578083932"></a>根据String ID获取设备的字符串描述符。 <a href="_u_s_b.md#gab22f143738b0532acf297a9ef2403446">更多...</a></p>
</td>
</tr>
<tr id="row1008035712083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p800986326083932"><a name="p800986326083932"></a><a name="p800986326083932"></a><a href="_u_s_b.md#ga61492b3dfdff2ac4eca43c910a1b8df7">GetConfigDescriptor</a> (const <a href="_o_h_o_s_1_1_u_s_b_1_1_usb_dev.md">UsbDev</a> &amp;dev, uint8_t descId, std::vector&lt; uint8_t &gt; &amp;descriptor)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p462404949083932"><a name="p462404949083932"></a><a name="p462404949083932"></a>根据config ID获取设备的配置描述符config。 <a href="_u_s_b.md#ga61492b3dfdff2ac4eca43c910a1b8df7">更多...</a></p>
</td>
</tr>
<tr id="row1424059828083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p342861675083932"><a name="p342861675083932"></a><a name="p342861675083932"></a><a href="_u_s_b.md#ga655159f9bcafd63348d600e73becac4c">GetRawDescriptor</a> (const <a href="_o_h_o_s_1_1_u_s_b_1_1_usb_dev.md">UsbDev</a> &amp;dev, std::vector&lt; uint8_t &gt; &amp;descriptor)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1663687692083932"><a name="p1663687692083932"></a><a name="p1663687692083932"></a>获取原始描述符。 <a href="_u_s_b.md#ga655159f9bcafd63348d600e73becac4c">更多...</a></p>
</td>
</tr>
<tr id="row1402686743083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1355906279083932"><a name="p1355906279083932"></a><a name="p1355906279083932"></a><a href="_u_s_b.md#ga0fe54ca5db313a848fcbb70818c31456">GetFileDescriptor</a> (const <a href="_o_h_o_s_1_1_u_s_b_1_1_usb_dev.md">UsbDev</a> &amp;dev, int32_t &amp;fd)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1917719687083932"><a name="p1917719687083932"></a><a name="p1917719687083932"></a>获取文件描述符。 <a href="_u_s_b.md#ga0fe54ca5db313a848fcbb70818c31456">更多...</a></p>
</td>
</tr>
<tr id="row228565702083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1855881867083932"><a name="p1855881867083932"></a><a name="p1855881867083932"></a><a href="_u_s_b.md#ga14dc58d56b8a74b4ed5035353eeebd03">SetConfig</a> (const <a href="_o_h_o_s_1_1_u_s_b_1_1_usb_dev.md">UsbDev</a> &amp;dev, uint8_t configIndex)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1816655108083932"><a name="p1816655108083932"></a><a name="p1816655108083932"></a>设置当前的config信息。 <a href="_u_s_b.md#ga14dc58d56b8a74b4ed5035353eeebd03">更多...</a></p>
</td>
</tr>
<tr id="row390499315083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p463883868083932"><a name="p463883868083932"></a><a name="p463883868083932"></a><a href="_u_s_b.md#gaf6f6c0dec5756ad1d9af32baf3783e6f">GetConfig</a> (const <a href="_o_h_o_s_1_1_u_s_b_1_1_usb_dev.md">UsbDev</a> &amp;dev, uint8_t &amp;configIndex)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1771538337083932"><a name="p1771538337083932"></a><a name="p1771538337083932"></a>获取当前的config信息。 <a href="_u_s_b.md#gaf6f6c0dec5756ad1d9af32baf3783e6f">更多...</a></p>
</td>
</tr>
<tr id="row754019878083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1956995441083932"><a name="p1956995441083932"></a><a name="p1956995441083932"></a><a href="_u_s_b.md#ga5db7dbd652b4379497e22516c8ec1041">ClaimInterface</a> (const <a href="_o_h_o_s_1_1_u_s_b_1_1_usb_dev.md">UsbDev</a> &amp;dev, uint8_t interfaceid, uint8_t force)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1471030396083932"><a name="p1471030396083932"></a><a name="p1471030396083932"></a>打开接口，并声明独占接口，必须在数据传输前执行。 <a href="_u_s_b.md#ga5db7dbd652b4379497e22516c8ec1041">更多...</a></p>
</td>
</tr>
<tr id="row553157417083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p367334313083932"><a name="p367334313083932"></a><a name="p367334313083932"></a><a href="_u_s_b.md#ga8d2799f640ebdb178f04cfb9fccd1efe">ReleaseInterface</a> (const <a href="_o_h_o_s_1_1_u_s_b_1_1_usb_dev.md">UsbDev</a> &amp;dev, uint8_t interfaceid)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p721501214083932"><a name="p721501214083932"></a><a name="p721501214083932"></a>关闭接口，释放接口的占用，在停止数据传输后执行。 <a href="_u_s_b.md#ga8d2799f640ebdb178f04cfb9fccd1efe">更多...</a></p>
</td>
</tr>
<tr id="row1628351207083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p249249940083932"><a name="p249249940083932"></a><a name="p249249940083932"></a><a href="_u_s_b.md#ga0a45ff8a4fd4f88f8ae22f1631c39ce5">SetInterface</a> (const <a href="_o_h_o_s_1_1_u_s_b_1_1_usb_dev.md">UsbDev</a> &amp;dev, uint8_t interfaceid, uint8_t altIndex)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p460351491083932"><a name="p460351491083932"></a><a name="p460351491083932"></a>设置指定接口的备选设置，用于在具有相同ID但不同备用设置的两个接口之间进行选择。 <a href="_u_s_b.md#ga0a45ff8a4fd4f88f8ae22f1631c39ce5">更多...</a></p>
</td>
</tr>
<tr id="row624460137083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1518854198083932"><a name="p1518854198083932"></a><a name="p1518854198083932"></a><a href="_u_s_b.md#ga58ed776bd47b21c7674743d0fe3ea3c1">BulkTransferRead</a> (const <a href="_o_h_o_s_1_1_u_s_b_1_1_usb_dev.md">UsbDev</a> &amp;dev, const <a href="_o_h_o_s_1_1_u_s_b_1_1_usb_pipe.md">UsbPipe</a> &amp;pipe, int32_t timeout, std::vector&lt; uint8_t &gt; &amp;data)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1478278870083932"><a name="p1478278870083932"></a><a name="p1478278870083932"></a>在给定端点上执行批量数据读取，返回读取的数据和长度，端点方向必须为数据读取，可以设置超时时间。 <a href="_u_s_b.md#ga58ed776bd47b21c7674743d0fe3ea3c1">更多...</a></p>
</td>
</tr>
<tr id="row1012391087083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1277457254083932"><a name="p1277457254083932"></a><a name="p1277457254083932"></a><a href="_u_s_b.md#gab4432b79ac68bdbf1dbce1898258017d">BulkTransferWrite</a> (const <a href="_o_h_o_s_1_1_u_s_b_1_1_usb_dev.md">UsbDev</a> &amp;dev, const <a href="_o_h_o_s_1_1_u_s_b_1_1_usb_pipe.md">UsbPipe</a> &amp;pipe, int32_t timeout, const std::vector&lt; uint8_t &gt; &amp;data)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1707512389083932"><a name="p1707512389083932"></a><a name="p1707512389083932"></a>在给定端点上执行批量数据写入， 返回读取的数据和长度，端点方向必须为数据写入。 <a href="_u_s_b.md#gab4432b79ac68bdbf1dbce1898258017d">更多...</a></p>
</td>
</tr>
<tr id="row697631753083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p587430072083932"><a name="p587430072083932"></a><a name="p587430072083932"></a><a href="_u_s_b.md#gacf8e8a1f82dde5e6876ae3ef9353a78a">ControlTransfer</a> (const <a href="_o_h_o_s_1_1_u_s_b_1_1_usb_dev.md">UsbDev</a> &amp;dev, const <a href="_o_h_o_s_1_1_u_s_b_1_1_usb_ctrl_transfer.md">UsbCtrlTransfer</a> &amp;ctrl, std::vector&lt; uint8_t &gt; &amp;data)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p875718496083932"><a name="p875718496083932"></a><a name="p875718496083932"></a>对此设备执行端点零的控制事务，传输方向由请求类型决定。 如果requestType＆ USB_ENDPOINT_DIR_MASK是USB_DIR_OUT ，则传输是写入，如果是USB_DIR_IN ，则传输是读取。 <a href="_u_s_b.md#gacf8e8a1f82dde5e6876ae3ef9353a78a">更多...</a></p>
</td>
</tr>
<tr id="row1149884302083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1369949715083932"><a name="p1369949715083932"></a><a name="p1369949715083932"></a><a href="_u_s_b.md#ga947c1eb345f988bb10bd7a5fcc908042">InterruptTransferRead</a> (const <a href="_o_h_o_s_1_1_u_s_b_1_1_usb_dev.md">UsbDev</a> &amp;dev, const <a href="_o_h_o_s_1_1_u_s_b_1_1_usb_pipe.md">UsbPipe</a> &amp;pipe, int32_t timeout, std::vector&lt; uint8_t &gt; &amp;data)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1816271276083932"><a name="p1816271276083932"></a><a name="p1816271276083932"></a>在给定端点上执行中断数据读取， 返回读取的数据和长度，端点方向必须为数据读取。 <a href="_u_s_b.md#ga947c1eb345f988bb10bd7a5fcc908042">更多...</a></p>
</td>
</tr>
<tr id="row1187988604083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1051509091083932"><a name="p1051509091083932"></a><a name="p1051509091083932"></a><a href="_u_s_b.md#gabc6fd44733a87630e9092f0ff385772d">InterruptTransferWrite</a> (const <a href="_o_h_o_s_1_1_u_s_b_1_1_usb_dev.md">UsbDev</a> &amp;dev, const <a href="_o_h_o_s_1_1_u_s_b_1_1_usb_pipe.md">UsbPipe</a> &amp;pipe, int32_t timeout, std::vector&lt; uint8_t &gt; &amp;data)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1312539207083932"><a name="p1312539207083932"></a><a name="p1312539207083932"></a>在给定端点上执行中断数据写入， 返回读取的数据和长度，端点方向必须为数据写入。 <a href="_u_s_b.md#gabc6fd44733a87630e9092f0ff385772d">更多...</a></p>
</td>
</tr>
<tr id="row1309873004083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p971833574083932"><a name="p971833574083932"></a><a name="p971833574083932"></a><a href="_u_s_b.md#gafd635fc32a36e5ebad29965ab91f845e">IsoTransferRead</a> (const <a href="_o_h_o_s_1_1_u_s_b_1_1_usb_dev.md">UsbDev</a> &amp;dev, const <a href="_o_h_o_s_1_1_u_s_b_1_1_usb_pipe.md">UsbPipe</a> &amp;pipe, int32_t timeout, std::vector&lt; uint8_t &gt; &amp;data)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p549731964083932"><a name="p549731964083932"></a><a name="p549731964083932"></a>在给定端点上执行等时数据读取， 返回读取的数据和长度，端点方向必须为数据读取。 <a href="_u_s_b.md#gafd635fc32a36e5ebad29965ab91f845e">更多...</a></p>
</td>
</tr>
<tr id="row2009852752083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1386629659083932"><a name="p1386629659083932"></a><a name="p1386629659083932"></a><a href="_u_s_b.md#gaecdc768a7c20030fc165becd9dc68836">IsoTransferWrite</a> (const <a href="_o_h_o_s_1_1_u_s_b_1_1_usb_dev.md">UsbDev</a> &amp;dev, const <a href="_o_h_o_s_1_1_u_s_b_1_1_usb_pipe.md">UsbPipe</a> &amp;pipe, int32_t timeout, std::vector&lt; uint8_t &gt; &amp;data)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p374635550083932"><a name="p374635550083932"></a><a name="p374635550083932"></a>在给定端点上执行等时数据写入， 返回读取的数据和长度，端点方向必须为数据写入。 <a href="_u_s_b.md#gaecdc768a7c20030fc165becd9dc68836">更多...</a></p>
</td>
</tr>
<tr id="row538439044083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1209211472083932"><a name="p1209211472083932"></a><a name="p1209211472083932"></a><a href="_u_s_b.md#ga15206b8c37dddf23597b90783c3fd61e">RequestQueue</a> (const <a href="_o_h_o_s_1_1_u_s_b_1_1_usb_dev.md">UsbDev</a> &amp;dev, const <a href="_o_h_o_s_1_1_u_s_b_1_1_usb_pipe.md">UsbPipe</a> &amp;pipe, const std::vector&lt; uint8_t &gt; &amp;clientData, const std::vector&lt; uint8_t &gt; &amp;buffer)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p663819819083932"><a name="p663819819083932"></a><a name="p663819819083932"></a>将指定的端点进行异步数据发送或者接收请求，数据传输方向由端点方向决定。 <a href="_u_s_b.md#ga15206b8c37dddf23597b90783c3fd61e">更多...</a></p>
</td>
</tr>
<tr id="row1014722088083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p265205499083932"><a name="p265205499083932"></a><a name="p265205499083932"></a><a href="_u_s_b.md#gae8c59ac88cfab48b516a045d2ea60b09">RequestWait</a> (const <a href="_o_h_o_s_1_1_u_s_b_1_1_usb_dev.md">UsbDev</a> &amp;dev, std::vector&lt; uint8_t &gt; &amp;clientData, std::vector&lt; uint8_t &gt; &amp;buffer, int32_t timeout)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1262386951083932"><a name="p1262386951083932"></a><a name="p1262386951083932"></a>等待RequestQueue异步请求的操作结果。 <a href="_u_s_b.md#gae8c59ac88cfab48b516a045d2ea60b09">更多...</a></p>
</td>
</tr>
<tr id="row720550270083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p408586404083932"><a name="p408586404083932"></a><a name="p408586404083932"></a><a href="_u_s_b.md#ga0ea8572d2d2120f89ac6db3b22e317ed">RequestCancel</a> (const <a href="_o_h_o_s_1_1_u_s_b_1_1_usb_dev.md">UsbDev</a> &amp;dev, const <a href="_o_h_o_s_1_1_u_s_b_1_1_usb_pipe.md">UsbPipe</a> &amp;pipe)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p997003835083932"><a name="p997003835083932"></a><a name="p997003835083932"></a>取消待处理的数据请求。 <a href="_u_s_b.md#ga0ea8572d2d2120f89ac6db3b22e317ed">更多...</a></p>
</td>
</tr>
<tr id="row291142688083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p893126397083932"><a name="p893126397083932"></a><a name="p893126397083932"></a><a href="_u_s_b.md#ga3e67d97d8030f2663ba3a0e2a3604a3f">GetCurrentFunctions</a> (int32_t &amp;funcs)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p868246698083932"><a name="p868246698083932"></a><a name="p868246698083932"></a>获取从设备支持的功能列表（按位域表示）（从设备）。 <a href="_u_s_b.md#ga3e67d97d8030f2663ba3a0e2a3604a3f">更多...</a></p>
</td>
</tr>
<tr id="row121721109083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1242347623083932"><a name="p1242347623083932"></a><a name="p1242347623083932"></a><a href="_u_s_b.md#ga09ebfd1c4c7e336503f4667851269697">SetCurrentFunctions</a> (int32_t funcs)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1751441222083932"><a name="p1751441222083932"></a><a name="p1751441222083932"></a>设置从设备支持的功能列表（按位域表示）（从设备）。 <a href="_u_s_b.md#ga09ebfd1c4c7e336503f4667851269697">更多...</a></p>
</td>
</tr>
<tr id="row948944799083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p731600818083932"><a name="p731600818083932"></a><a name="p731600818083932"></a><a href="_u_s_b.md#ga50e12c010b0b342a461917063128e894">SetPortRole</a> (int32_t portId, int32_t powerRole, int32_t dataRole)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p114141754083932"><a name="p114141754083932"></a><a name="p114141754083932"></a>设置port端口的角色。 <a href="_u_s_b.md#ga50e12c010b0b342a461917063128e894">更多...</a></p>
</td>
</tr>
<tr id="row759414265083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p840575013083932"><a name="p840575013083932"></a><a name="p840575013083932"></a><a href="_u_s_b.md#ga4a128ec5d7c39f7d7798d76f8586f8c7">QueryPort</a> (int32_t &amp;portId, int32_t &amp;powerRole, int32_t &amp;dataRole, int32_t &amp;mode)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p629143201083932"><a name="p629143201083932"></a><a name="p629143201083932"></a>查询port端口的当前设置。 <a href="_u_s_b.md#ga4a128ec5d7c39f7d7798d76f8586f8c7">更多...</a></p>
</td>
</tr>
<tr id="row103871564083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1869971656083932"><a name="p1869971656083932"></a><a name="p1869971656083932"></a><a href="_u_s_b.md#ga8bbaa9efd7d85d84ff91af803a67333f">BindUsbdSubscriber</a> (const sptr&lt; <a href="_o_h_o_s_1_1_u_s_b_1_1_usbd_subscriber.md">UsbdSubscriber</a> &gt; &amp;subscriber)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1393438763083932"><a name="p1393438763083932"></a><a name="p1393438763083932"></a>绑定订阅者。 <a href="_u_s_b.md#ga8bbaa9efd7d85d84ff91af803a67333f">更多...</a></p>
</td>
</tr>
<tr id="row1815349883083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p806140934083932"><a name="p806140934083932"></a><a name="p806140934083932"></a><a href="_u_s_b.md#gae5b88c4c563623eb342186d525df1cd0">UnbindUsbdSubscriber</a> (const sptr&lt; <a href="_o_h_o_s_1_1_u_s_b_1_1_usbd_subscriber.md">UsbdSubscriber</a> &gt; &amp;subscriber)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p949354883083932"><a name="p949354883083932"></a><a name="p949354883083932"></a>解绑订阅者。 <a href="_u_s_b.md#gae5b88c4c563623eb342186d525df1cd0">更多...</a></p>
</td>
</tr>
<tr id="row798315609083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1905812450083932"><a name="p1905812450083932"></a><a name="p1905812450083932"></a><a href="_u_s_b.md#gafb1b746216cefccd765ab949c7ddb50b">RegBulkCallback</a> (const <a href="_o_h_o_s_1_1_u_s_b_1_1_usb_dev.md">UsbDev</a> &amp;dev, const <a href="_o_h_o_s_1_1_u_s_b_1_1_usb_pipe.md">UsbPipe</a> &amp;pipe, const sptr&lt; IRemoteObject &gt; &amp;cb)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1108067996083932"><a name="p1108067996083932"></a><a name="p1108067996083932"></a>注册批量传输异步回调函数。 <a href="_u_s_b.md#gafb1b746216cefccd765ab949c7ddb50b">更多...</a></p>
</td>
</tr>
<tr id="row1119018829083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1713107800083932"><a name="p1713107800083932"></a><a name="p1713107800083932"></a><a href="_u_s_b.md#gaac0161e47c42a91ecc77c21229969216">UnRegBulkCallback</a> (const <a href="_o_h_o_s_1_1_u_s_b_1_1_usb_dev.md">UsbDev</a> &amp;dev, const <a href="_o_h_o_s_1_1_u_s_b_1_1_usb_pipe.md">UsbPipe</a> &amp;pipe)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p396081098083932"><a name="p396081098083932"></a><a name="p396081098083932"></a>注销批量传输异步回调函数。 <a href="_u_s_b.md#gaac0161e47c42a91ecc77c21229969216">更多...</a></p>
</td>
</tr>
<tr id="row1998759782083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1095237561083932"><a name="p1095237561083932"></a><a name="p1095237561083932"></a><a href="_u_s_b.md#gab28056c346e27a858e9c274ef73bee82">BulkRead</a> (const <a href="_o_h_o_s_1_1_u_s_b_1_1_usb_dev.md">UsbDev</a> &amp;dev, const <a href="_o_h_o_s_1_1_u_s_b_1_1_usb_pipe.md">UsbPipe</a> &amp;pipe, sptr&lt; Ashmem &gt; &amp;ashmem)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1530320193083932"><a name="p1530320193083932"></a><a name="p1530320193083932"></a>批量传输异步读数据。 <a href="_u_s_b.md#gab28056c346e27a858e9c274ef73bee82">更多...</a></p>
</td>
</tr>
<tr id="row133412239083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1772796478083932"><a name="p1772796478083932"></a><a name="p1772796478083932"></a><a href="_u_s_b.md#gae3915859c54c1f287852baf413a74627">BulkWrite</a> (const <a href="_o_h_o_s_1_1_u_s_b_1_1_usb_dev.md">UsbDev</a> &amp;dev, const <a href="_o_h_o_s_1_1_u_s_b_1_1_usb_pipe.md">UsbPipe</a> &amp;pipe, sptr&lt; Ashmem &gt; &amp;ashmem)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p826259393083932"><a name="p826259393083932"></a><a name="p826259393083932"></a>批量传输异步写数据。 <a href="_u_s_b.md#gae3915859c54c1f287852baf413a74627">更多...</a></p>
</td>
</tr>
<tr id="row859226345083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p284250223083932"><a name="p284250223083932"></a><a name="p284250223083932"></a><a href="_u_s_b.md#gaf1f02c9695f5b5faa4a9eb2822f584b9">BulkCancel</a> (const <a href="_o_h_o_s_1_1_u_s_b_1_1_usb_dev.md">UsbDev</a> &amp;dev, const <a href="_o_h_o_s_1_1_u_s_b_1_1_usb_pipe.md">UsbPipe</a> &amp;pipe)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p282899403083932"><a name="p282899403083932"></a><a name="p282899403083932"></a>批量传输异步取消接口，用于取消当前接口的异步批量读写操作。 <a href="_u_s_b.md#gaf1f02c9695f5b5faa4a9eb2822f584b9">更多...</a></p>
</td>
</tr>
</tbody>
</table>

## 静态 Public 成员函数<a name="pub-static-methods"></a>

<a name="table97835937083932"></a>
<table><thead align="left"><tr id="row1946882837083932"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1826124308083932"><a name="p1826124308083932"></a><a name="p1826124308083932"></a>静态 Public 成员函数</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1590088840083932"><a name="p1590088840083932"></a><a name="p1590088840083932"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row617013028083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p934992986083932"><a name="p934992986083932"></a><a name="p934992986083932"></a><strong id="b1173596982083932"><a name="b1173596982083932"></a><a name="b1173596982083932"></a>GetInstance</strong> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry468430377083932p0"><a name="entry468430377083932p0"></a><a name="entry468430377083932p0"></a>获取实例。</p>
</td>
</tr>
</tbody>
</table>

