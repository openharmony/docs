# input\_type.h<a name="ZH-CN_TOPIC_0000001343320977"></a>

## **概述**<a name="section1034418051083931"></a>

**所属模块:**

[Input](_input.md)

## **汇总**<a name="section1977027147083931"></a>

## 类<a name="nested-classes"></a>

<a name="table902953191083931"></a>
<table><thead align="left"><tr id="row2407193083931"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p369950383083931"><a name="p369950383083931"></a><a name="p369950383083931"></a>类</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1338334012083931"><a name="p1338334012083931"></a><a name="p1338334012083931"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row1473780659083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1437917552083931"><a name="p1437917552083931"></a><a name="p1437917552083931"></a><a href="_event_package.md">EventPackage</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p238641427083931"><a name="p238641427083931"></a><a name="p238641427083931"></a>input事件数据包结构 <a href="_event_package.md">更多...</a></p>
</td>
</tr>
<tr id="row955444940083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1720693259083931"><a name="p1720693259083931"></a><a name="p1720693259083931"></a><a href="_input_report_event_cb.md">InputReportEventCb</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1576609452083931"><a name="p1576609452083931"></a><a name="p1576609452083931"></a>此结构体定义了输入事件回调函数并提供给input服务使用 <a href="_input_report_event_cb.md">更多...</a></p>
</td>
</tr>
<tr id="row1145573080083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1661590259083931"><a name="p1661590259083931"></a><a name="p1661590259083931"></a><a href="_device_info.md">DeviceInfo</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1456636978083931"><a name="p1456636978083931"></a><a name="p1456636978083931"></a>input设备基础设备信息 <a href="_device_info.md">更多...</a></p>
</td>
</tr>
<tr id="row926331442083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1845709345083931"><a name="p1845709345083931"></a><a name="p1845709345083931"></a><a href="_input_extra_cmd.md">InputExtraCmd</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1759685173083931"><a name="p1759685173083931"></a><a name="p1759685173083931"></a>扩展指令的数据结构 <a href="_input_extra_cmd.md">更多...</a></p>
</td>
</tr>
</tbody>
</table>

## 宏定义<a name="define-members"></a>

<a name="table677976861083931"></a>
<table><thead align="left"><tr id="row1940174443083931"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p309785351083931"><a name="p309785351083931"></a><a name="p309785351083931"></a>宏定义</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p871470921083931"><a name="p871470921083931"></a><a name="p871470921083931"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row1327547294083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p864727393083931"><a name="p864727393083931"></a><a name="p864727393083931"></a><strong id="b296572948083931"><a name="b296572948083931"></a><a name="b296572948083931"></a>MAX_INPUT_DEV_NUM</strong>   32</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1192136023083931p0"><a name="entry1192136023083931p0"></a><a name="entry1192136023083931p0"></a><span>Input设备最大数量。</span></p>
</td>
</tr>
<tr id="row400057021083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1304815735083931"><a name="p1304815735083931"></a><a name="p1304815735083931"></a><strong id="b1455838141083931"><a name="b1455838141083931"></a><a name="b1455838141083931"></a>MAX_NODE_PATH_LEN</strong>   64</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry95392210083931p0"><a name="entry95392210083931p0"></a><a name="entry95392210083931p0"></a>节点路径最大长度。</p>
</td>
</tr>
<tr id="row939639874083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p722785661083931"><a name="p722785661083931"></a><a name="p722785661083931"></a><strong id="b108607339083931"><a name="b108607339083931"></a><a name="b108607339083931"></a>CHIP_INFO_LEN</strong>   10</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry892050802083931p0"><a name="entry892050802083931p0"></a><a name="entry892050802083931p0"></a>芯片信息长度。</p>
</td>
</tr>
<tr id="row133475027083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1220340571083931"><a name="p1220340571083931"></a><a name="p1220340571083931"></a><strong id="b1219736538083931"><a name="b1219736538083931"></a><a name="b1219736538083931"></a>CHIP_NAME_LEN</strong>   10</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1031238103083931p0"><a name="entry1031238103083931p0"></a><a name="entry1031238103083931p0"></a>芯片名称长度。</p>
</td>
</tr>
<tr id="row1029317603083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1423211856083931"><a name="p1423211856083931"></a><a name="p1423211856083931"></a><strong id="b789563284083931"><a name="b789563284083931"></a><a name="b789563284083931"></a>VENDOR_NAME_LEN</strong>   10</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1670495082083931p0"><a name="entry1670495082083931p0"></a><a name="entry1670495082083931p0"></a>厂商名称长度。</p>
</td>
</tr>
<tr id="row2004220901083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p598658154083931"><a name="p598658154083931"></a><a name="p598658154083931"></a><strong id="b947686080083931"><a name="b947686080083931"></a><a name="b947686080083931"></a>SELF_TEST_RESULT_LEN</strong>   20</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1473732594083931p0"><a name="entry1473732594083931p0"></a><a name="entry1473732594083931p0"></a>自测结果长度。</p>
</td>
</tr>
</tbody>
</table>

## 枚举<a name="enum-members"></a>

<a name="table141893302083931"></a>
<table><thead align="left"><tr id="row874853884083931"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p880993450083931"><a name="p880993450083931"></a><a name="p880993450083931"></a>枚举</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1595335173083931"><a name="p1595335173083931"></a><a name="p1595335173083931"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row1542474680083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1487990177083931"><a name="p1487990177083931"></a><a name="p1487990177083931"></a><a href="_input.md#ga85d58a5185669daa4995e332b63eba7a">RetStatus</a> {   <a href="_input.md#gga85d58a5185669daa4995e332b63eba7aa4b6c3821e689826c4323c4eb759b4d3a">INPUT_SUCCESS</a> = 0, <a href="_input.md#gga85d58a5185669daa4995e332b63eba7aa07d986b0ee365020834af82a31dfce11">INPUT_FAILURE</a> = -1, <a href="_input.md#gga85d58a5185669daa4995e332b63eba7aa5f54ab958e21a298da35c3c5c1c36d85">INPUT_INVALID_PARAM</a> = -2, <a href="_input.md#gga85d58a5185669daa4995e332b63eba7aaddf6c11b0fac107e0123b83cfc4a1185">INPUT_NOMEM</a> = -3,   <a href="_input.md#gga85d58a5185669daa4995e332b63eba7aa157cd4f4736dd1f05eb2e13dbc7123ed">INPUT_NULL_PTR</a> = -4, <a href="_input.md#gga85d58a5185669daa4995e332b63eba7aabdaeb2a27983bd66ff6e24d4df255f59">INPUT_TIMEOUT</a> = -5, <a href="_input.md#gga85d58a5185669daa4995e332b63eba7aa8978f7ee3d0ddd70f5077c21efc4a97a">INPUT_UNSUPPORTED</a> = -6 }</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1508039291083931"><a name="p1508039291083931"></a><a name="p1508039291083931"></a>定义返回值类型 <a href="_input.md#ga85d58a5185669daa4995e332b63eba7a">更多...</a></p>
</td>
</tr>
<tr id="row324996382083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2055207415083931"><a name="p2055207415083931"></a><a name="p2055207415083931"></a><a href="_input.md#gaa8225ba155dfa1ef2c4119c832bc4dd3">InputDevType</a> {   <a href="_input.md#ggaa8225ba155dfa1ef2c4119c832bc4dd3a621678554aac2b37ac244b80fc33da0d">INDEV_TYPE_TOUCH</a>, <a href="_input.md#ggaa8225ba155dfa1ef2c4119c832bc4dd3a4c4c8407342021cc06a95aa13ebeaca1">INDEV_TYPE_KEY</a>, <a href="_input.md#ggaa8225ba155dfa1ef2c4119c832bc4dd3a3a4137efe666a3aaccf267d597879fdc">INDEV_TYPE_KEYBOARD</a>, <a href="_input.md#ggaa8225ba155dfa1ef2c4119c832bc4dd3abe68740c1d125d3d474fdadc7d31d11c">INDEV_TYPE_MOUSE</a>,   <a href="_input.md#ggaa8225ba155dfa1ef2c4119c832bc4dd3a2815a25dde3e56e1f8eb57f20049e8c0">INDEV_TYPE_BUTTON</a>, <a href="_input.md#ggaa8225ba155dfa1ef2c4119c832bc4dd3a4ef2ab6bc355e2321664709716d1d04f">INDEV_TYPE_CROWN</a>, <a href="_input.md#ggaa8225ba155dfa1ef2c4119c832bc4dd3a8cd6b27ac631b9d3fa89a17ddca37291">INDEV_TYPE_ENCODER</a>, <a href="_input.md#ggaa8225ba155dfa1ef2c4119c832bc4dd3a4097247eba52062f47a1aa99414033de">INDEV_TYPE_UNKNOWN</a> }</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p980630484083931"><a name="p980630484083931"></a><a name="p980630484083931"></a>定义input设备类型 <a href="_input.md#gaa8225ba155dfa1ef2c4119c832bc4dd3">更多...</a></p>
</td>
</tr>
<tr id="row180527858083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2146860219083931"><a name="p2146860219083931"></a><a name="p2146860219083931"></a><a href="_input.md#ga65e6bb4d942c22dba9975253b0a1d73f">PowerStatus</a> { <a href="_input.md#gga65e6bb4d942c22dba9975253b0a1d73fa5edb1acdc509659046de9cb61bd9508a">INPUT_RESUME</a>, <a href="_input.md#gga65e6bb4d942c22dba9975253b0a1d73fa2a6aab1b3d50dae2b6ba43779e185ea5">INPUT_SUSPEND</a>, <a href="_input.md#gga65e6bb4d942c22dba9975253b0a1d73fa8895c64802d558830d46bcd921830e9d">INPUT_LOW_POWER</a>, <a href="_input.md#gga65e6bb4d942c22dba9975253b0a1d73fa728020b31c626f749d426cbe8f0f92fe">INPUT_POWER_STATUS_UNKNOWN</a> }</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p688388368083931"><a name="p688388368083931"></a><a name="p688388368083931"></a>定义电源状态 <a href="_input.md#ga65e6bb4d942c22dba9975253b0a1d73f">更多...</a></p>
</td>
</tr>
<tr id="row504710555083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p322240533083931"><a name="p322240533083931"></a><a name="p322240533083931"></a><a href="_input.md#gae96e484cfd64ea37b5b7782f57f38a21">CapacitanceTest</a> {   <a href="_input.md#ggae96e484cfd64ea37b5b7782f57f38a21aedd31f50c79a36cc8e084d69a3fc695b">BASE_TEST</a>, <a href="_input.md#ggae96e484cfd64ea37b5b7782f57f38a21abfe92c879dc84b5b071899a7ec5cc41d">FULL_TEST</a>, <a href="_input.md#ggae96e484cfd64ea37b5b7782f57f38a21a93335d88212604ade3b0bfe7e619916f">MMI_TEST</a>, <a href="_input.md#ggae96e484cfd64ea37b5b7782f57f38a21a31afc25da895db4eaa2af6cec1d6b37c">RUNNING_TEST</a>,   <a href="_input.md#ggae96e484cfd64ea37b5b7782f57f38a21a9d739cecefd291b39152e3815445aa20">TEST_TYPE_UNKNOWN</a> }</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1742713595083931"><a name="p1742713595083931"></a><a name="p1742713595083931"></a>定义容值测试类型 <a href="_input.md#gae96e484cfd64ea37b5b7782f57f38a21">更多...</a></p>
</td>
</tr>
</tbody>
</table>

## **详细描述**<a name="section1161754544083931"></a>

input设备相关的类型定义，定义了input设备驱动接口所使用的结构体及枚举类型。

**Since：**

1.0

**Version：**

1.0

