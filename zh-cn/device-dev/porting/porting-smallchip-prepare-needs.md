# 移植须知<a name="ZH-CN_TOPIC_0000001152006279"></a>

本文详细介绍如何将OpenHarmony[小型系统](../quick-start/quickstart-lite-overview.md)的linux和LiteOS-A内核移植到新的开发板上，要求读者具有一定的嵌入式系统开发经验。建议先查看[入门指导](../../OpenHarmony-Overview_zh.md)，以了解OpenHarmony软件架构、目录结构、内核子系统和驱动子系统相关知识。当前小型系统已适配的开发板如下表所示：

**表 1**  OpenHarmony小型系统已适配的开发板

<a name="table1839174685713"></a>
<table><thead align="left"><tr id="row1540164617570"><th class="cellrowborder" valign="top" width="14.18858114188581%" id="mcps1.2.8.1.1"><p id="p2400466575"><a name="p2400466575"></a><a name="p2400466575"></a>开发板</p>
</th>
<th class="cellrowborder" valign="top" width="16.498350164983503%" id="mcps1.2.8.1.2"><p id="p1401946115713"><a name="p1401946115713"></a><a name="p1401946115713"></a>内核</p>
</th>
<th class="cellrowborder" valign="top" width="13.948605139486054%" id="mcps1.2.8.1.3"><p id="p840194625718"><a name="p840194625718"></a><a name="p840194625718"></a>arch</p>
</th>
<th class="cellrowborder" valign="top" width="10.818918108189182%" id="mcps1.2.8.1.4"><p id="p289613324413"><a name="p289613324413"></a><a name="p289613324413"></a>ROM</p>
</th>
<th class="cellrowborder" valign="top" width="7.119288071192881%" id="mcps1.2.8.1.5"><p id="p73310186181"><a name="p73310186181"></a><a name="p73310186181"></a>RAM</p>
</th>
<th class="cellrowborder" valign="top" width="12.48875112488751%" id="mcps1.2.8.1.6"><p id="p9883194110564"><a name="p9883194110564"></a><a name="p9883194110564"></a>文件系统</p>
</th>
<th class="cellrowborder" valign="top" width="24.937506249375062%" id="mcps1.2.8.1.7"><p id="p1740164625715"><a name="p1740164625715"></a><a name="p1740164625715"></a>Flash 类型</p>
</th>
</tr>
</thead>
<tbody><tr id="row164094619576"><td class="cellrowborder" valign="top" width="14.18858114188581%" headers="mcps1.2.8.1.1 "><p id="p940546135713"><a name="p940546135713"></a><a name="p940546135713"></a>hispark_taurus</p>
</td>
<td class="cellrowborder" valign="top" width="16.498350164983503%" headers="mcps1.2.8.1.2 "><p id="p74084625719"><a name="p74084625719"></a><a name="p74084625719"></a>LiteOS-A和linux-4.19</p>
</td>
<td class="cellrowborder" valign="top" width="13.948605139486054%" headers="mcps1.2.8.1.3 "><p id="p18424818407"><a name="p18424818407"></a><a name="p18424818407"></a>ARM cortex-a7</p>
</td>
<td class="cellrowborder" valign="top" width="10.818918108189182%" headers="mcps1.2.8.1.4 "><p id="p1389623220417"><a name="p1389623220417"></a><a name="p1389623220417"></a>8G</p>
</td>
<td class="cellrowborder" valign="top" width="7.119288071192881%" headers="mcps1.2.8.1.5 "><p id="p533221819182"><a name="p533221819182"></a><a name="p533221819182"></a>1GB</p>
</td>
<td class="cellrowborder" valign="top" width="12.48875112488751%" headers="mcps1.2.8.1.6 "><p id="p1088394155619"><a name="p1088394155619"></a><a name="p1088394155619"></a>VFAT、EXT4</p>
</td>
<td class="cellrowborder" valign="top" width="24.937506249375062%" headers="mcps1.2.8.1.7 "><p id="p14024611578"><a name="p14024611578"></a><a name="p14024611578"></a>eMMC4.5</p>
</td>
</tr>
<tr id="row740646115717"><td class="cellrowborder" valign="top" width="14.18858114188581%" headers="mcps1.2.8.1.1 "><p id="p14405465576"><a name="p14405465576"></a><a name="p14405465576"></a>hispark_aries</p>
</td>
<td class="cellrowborder" valign="top" width="16.498350164983503%" headers="mcps1.2.8.1.2 "><p id="p64084655720"><a name="p64084655720"></a><a name="p64084655720"></a>LiteOS-A</p>
</td>
<td class="cellrowborder" valign="top" width="13.948605139486054%" headers="mcps1.2.8.1.3 "><p id="p44054610573"><a name="p44054610573"></a><a name="p44054610573"></a>ARM cortex-a7</p>
</td>
<td class="cellrowborder" valign="top" width="10.818918108189182%" headers="mcps1.2.8.1.4 "><p id="p289612321545"><a name="p289612321545"></a><a name="p289612321545"></a>16M</p>
</td>
<td class="cellrowborder" valign="top" width="7.119288071192881%" headers="mcps1.2.8.1.5 "><p id="p63323184186"><a name="p63323184186"></a><a name="p63323184186"></a>512M</p>
</td>
<td class="cellrowborder" valign="top" width="12.48875112488751%" headers="mcps1.2.8.1.6 "><p id="p2883124112564"><a name="p2883124112564"></a><a name="p2883124112564"></a>JFFS2</p>
</td>
<td class="cellrowborder" valign="top" width="24.937506249375062%" headers="mcps1.2.8.1.7 "><p id="p34019466577"><a name="p34019466577"></a><a name="p34019466577"></a>SPI NOR</p>
</td>
</tr>
</tbody>
</table>

表1中的开发板可作为待移植开发板的参考，当前LiteOS-A和linux-4.19支持的arch、ROM占用、支持的文件系统和支持的Flash类型如下表所示：

**表 2**  OpenHarmony小型系统内核移植信息表

<a name="table1447964818426"></a>
<table><thead align="left"><tr id="row114791148154215"><th class="cellrowborder" valign="top" width="10.54%" id="mcps1.2.6.1.1"><p id="p10479134834218"><a name="p10479134834218"></a><a name="p10479134834218"></a>内核</p>
</th>
<th class="cellrowborder" valign="top" width="24.529999999999998%" id="mcps1.2.6.1.2"><p id="p64791548164211"><a name="p64791548164211"></a><a name="p64791548164211"></a>支持的arch</p>
</th>
<th class="cellrowborder" valign="top" width="8.459999999999999%" id="mcps1.2.6.1.3"><p id="p1347984854212"><a name="p1347984854212"></a><a name="p1347984854212"></a>ROM</p>
</th>
<th class="cellrowborder" valign="top" width="33.35%" id="mcps1.2.6.1.4"><p id="p650414725815"><a name="p650414725815"></a><a name="p650414725815"></a>文件系统</p>
</th>
<th class="cellrowborder" valign="top" width="23.119999999999997%" id="mcps1.2.6.1.5"><p id="p204791048124211"><a name="p204791048124211"></a><a name="p204791048124211"></a>Flash类型</p>
</th>
</tr>
</thead>
<tbody><tr id="row147904814423"><td class="cellrowborder" valign="top" width="10.54%" headers="mcps1.2.6.1.1 "><p id="p1348044810423"><a name="p1348044810423"></a><a name="p1348044810423"></a>LiteOS-A</p>
</td>
<td class="cellrowborder" valign="top" width="24.529999999999998%" headers="mcps1.2.6.1.2 "><p id="p124801448124214"><a name="p124801448124214"></a><a name="p124801448124214"></a>ARMv7</p>
</td>
<td class="cellrowborder" valign="top" width="8.459999999999999%" headers="mcps1.2.6.1.3 "><p id="p5480124814429"><a name="p5480124814429"></a><a name="p5480124814429"></a>&gt; 2M</p>
</td>
<td class="cellrowborder" valign="top" width="33.35%" headers="mcps1.2.6.1.4 "><p id="p20361621185812"><a name="p20361621185812"></a><a name="p20361621185812"></a>VFAT、JFFS2、YAFFS2</p>
</td>
<td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.2.6.1.5 "><p id="p348018481421"><a name="p348018481421"></a><a name="p348018481421"></a>SPI NOR、NAND、EMMC</p>
</td>
</tr>
<tr id="row148871689436"><td class="cellrowborder" valign="top" width="10.54%" headers="mcps1.2.6.1.1 "><p id="p688718854317"><a name="p688718854317"></a><a name="p688718854317"></a>linux-4.19</p>
</td>
<td class="cellrowborder" valign="top" width="24.529999999999998%" headers="mcps1.2.6.1.2 "><p id="p1588818812437"><a name="p1588818812437"></a><a name="p1588818812437"></a>ARM， ARM64、 MIPS、 X86等</p>
</td>
<td class="cellrowborder" valign="top" width="8.459999999999999%" headers="mcps1.2.6.1.3 "><p id="p1688828194310"><a name="p1688828194310"></a><a name="p1688828194310"></a>&gt; 5M</p>
</td>
<td class="cellrowborder" valign="top" width="33.35%" headers="mcps1.2.6.1.4 "><p id="p2504117185816"><a name="p2504117185816"></a><a name="p2504117185816"></a>VFAT、JFFS2、YAFFS、EXT/2/3/4、NFS等等</p>
</td>
<td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.2.6.1.5 "><p id="p8452944910"><a name="p8452944910"></a><a name="p8452944910"></a>NOR、NAND、EMMC等</p>
</td>
</tr>
</tbody>
</table>

