# Before You Start<a name="EN-US_TOPIC_0000001154212510"></a>

This document provides guidance on how to port the Linux and LiteOS Cortex-A kernels on the OpenHarmony small system to a development board. It is intended for developers with experience in developing embedded systems. Before following instructions in this document, it is recommended that you familiarize yourself with  [OpenHarmony](../../OpenHarmony-Overview.md), including its technical architecture, directory structure, kernel subsystem, and driver subsystem. The following table lists the development boards that have been adapted to the small system.

**Table  1**  Development boards compatible with the OpenHarmony small system

<a name="table1839174685713"></a>
<table><thead align="left"><tr id="row1540164617570"><th class="cellrowborder" valign="top" width="14.18858114188581%" id="mcps1.2.8.1.1"><p id="p2400466575"><a name="p2400466575"></a><a name="p2400466575"></a>Development Board</p>
</th>
<th class="cellrowborder" valign="top" width="16.498350164983503%" id="mcps1.2.8.1.2"><p id="p1401946115713"><a name="p1401946115713"></a><a name="p1401946115713"></a>Kernel</p>
</th>
<th class="cellrowborder" valign="top" width="13.948605139486054%" id="mcps1.2.8.1.3"><p id="p840194625718"><a name="p840194625718"></a><a name="p840194625718"></a>Architecture</p>
</th>
<th class="cellrowborder" valign="top" width="10.818918108189182%" id="mcps1.2.8.1.4"><p id="p289613324413"><a name="p289613324413"></a><a name="p289613324413"></a>ROM</p>
</th>
<th class="cellrowborder" valign="top" width="7.119288071192881%" id="mcps1.2.8.1.5"><p id="p73310186181"><a name="p73310186181"></a><a name="p73310186181"></a>RAM</p>
</th>
<th class="cellrowborder" valign="top" width="12.48875112488751%" id="mcps1.2.8.1.6"><p id="p9883194110564"><a name="p9883194110564"></a><a name="p9883194110564"></a>File System</p>
</th>
<th class="cellrowborder" valign="top" width="24.937506249375062%" id="mcps1.2.8.1.7"><p id="p1740164625715"><a name="p1740164625715"></a><a name="p1740164625715"></a>Flash Type</p>
</th>
</tr>
</thead>
<tbody><tr id="row164094619576"><td class="cellrowborder" valign="top" width="14.18858114188581%" headers="mcps1.2.8.1.1 "><p id="p940546135713"><a name="p940546135713"></a><a name="p940546135713"></a>hispark_taurus</p>
</td>
<td class="cellrowborder" valign="top" width="16.498350164983503%" headers="mcps1.2.8.1.2 "><p id="p74084625719"><a name="p74084625719"></a><a name="p74084625719"></a>LiteOS Cortex-A and Linux 4.19</p>
</td>
<td class="cellrowborder" valign="top" width="13.948605139486054%" headers="mcps1.2.8.1.3 "><p id="p18424818407"><a name="p18424818407"></a><a name="p18424818407"></a>Arm Cortex-A7</p>
</td>
<td class="cellrowborder" valign="top" width="10.818918108189182%" headers="mcps1.2.8.1.4 "><p id="p1389623220417"><a name="p1389623220417"></a><a name="p1389623220417"></a>8 GB</p>
</td>
<td class="cellrowborder" valign="top" width="7.119288071192881%" headers="mcps1.2.8.1.5 "><p id="p533221819182"><a name="p533221819182"></a><a name="p533221819182"></a>1 GB</p>
</td>
<td class="cellrowborder" valign="top" width="12.48875112488751%" headers="mcps1.2.8.1.6 "><p id="p1088394155619"><a name="p1088394155619"></a><a name="p1088394155619"></a>VFAT, EXT4</p>
</td>
<td class="cellrowborder" valign="top" width="24.937506249375062%" headers="mcps1.2.8.1.7 "><p id="p14024611578"><a name="p14024611578"></a><a name="p14024611578"></a>eMMC4.5</p>
</td>
</tr>
<tr id="row740646115717"><td class="cellrowborder" valign="top" width="14.18858114188581%" headers="mcps1.2.8.1.1 "><p id="p14405465576"><a name="p14405465576"></a><a name="p14405465576"></a>hispark_aries</p>
</td>
<td class="cellrowborder" valign="top" width="16.498350164983503%" headers="mcps1.2.8.1.2 "><p id="p64084655720"><a name="p64084655720"></a><a name="p64084655720"></a>LiteOS-A</p>
</td>
<td class="cellrowborder" valign="top" width="13.948605139486054%" headers="mcps1.2.8.1.3 "><p id="p44054610573"><a name="p44054610573"></a><a name="p44054610573"></a>Arm Cortex-A7</p>
</td>
<td class="cellrowborder" valign="top" width="10.818918108189182%" headers="mcps1.2.8.1.4 "><p id="p289612321545"><a name="p289612321545"></a><a name="p289612321545"></a>16 MB</p>
</td>
<td class="cellrowborder" valign="top" width="7.119288071192881%" headers="mcps1.2.8.1.5 "><p id="p63323184186"><a name="p63323184186"></a><a name="p63323184186"></a>512 MB</p>
</td>
<td class="cellrowborder" valign="top" width="12.48875112488751%" headers="mcps1.2.8.1.6 "><p id="p2883124112564"><a name="p2883124112564"></a><a name="p2883124112564"></a>JFFS2</p>
</td>
<td class="cellrowborder" valign="top" width="24.937506249375062%" headers="mcps1.2.8.1.7 "><p id="p34019466577"><a name="p34019466577"></a><a name="p34019466577"></a>SPI NOR</p>
</td>
</tr>
</tbody>
</table>

In addition to the aforementioned development boards, LiteOS Cortex-A and Linux 4.19 can be ported to development boards that meet the requirements described in the table below.

**Table  2**  Requirements for porting OpenHarmony small system kernels

<a name="table1447964818426"></a>
<table><thead align="left"><tr id="row114791148154215"><th class="cellrowborder" valign="top" width="10.54%" id="mcps1.2.6.1.1"><p id="p10479134834218"><a name="p10479134834218"></a><a name="p10479134834218"></a>Kernel</p>
</th>
<th class="cellrowborder" valign="top" width="24.529999999999998%" id="mcps1.2.6.1.2"><p id="p64791548164211"><a name="p64791548164211"></a><a name="p64791548164211"></a>Supported Architecture</p>
</th>
<th class="cellrowborder" valign="top" width="8.459999999999999%" id="mcps1.2.6.1.3"><p id="p1347984854212"><a name="p1347984854212"></a><a name="p1347984854212"></a>ROM</p>
</th>
<th class="cellrowborder" valign="top" width="33.35%" id="mcps1.2.6.1.4"><p id="p650414725815"><a name="p650414725815"></a><a name="p650414725815"></a>File System</p>
</th>
<th class="cellrowborder" valign="top" width="23.119999999999997%" id="mcps1.2.6.1.5"><p id="p204791048124211"><a name="p204791048124211"></a><a name="p204791048124211"></a>Flash Type</p>
</th>
</tr>
</thead>
<tbody><tr id="row147904814423"><td class="cellrowborder" valign="top" width="10.54%" headers="mcps1.2.6.1.1 "><p id="p1348044810423"><a name="p1348044810423"></a><a name="p1348044810423"></a>LiteOS-A</p>
</td>
<td class="cellrowborder" valign="top" width="24.529999999999998%" headers="mcps1.2.6.1.2 "><p id="p124801448124214"><a name="p124801448124214"></a><a name="p124801448124214"></a>ARMv7</p>
</td>
<td class="cellrowborder" valign="top" width="8.459999999999999%" headers="mcps1.2.6.1.3 "><p id="p5480124814429"><a name="p5480124814429"></a><a name="p5480124814429"></a>&gt; 2 MB</p>
</td>
<td class="cellrowborder" valign="top" width="33.35%" headers="mcps1.2.6.1.4 "><p id="p20361621185812"><a name="p20361621185812"></a><a name="p20361621185812"></a>VFAT, JFFS2, YAFFS2</p>
</td>
<td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.2.6.1.5 "><p id="p348018481421"><a name="p348018481421"></a><a name="p348018481421"></a>SPI NOR, NAND, eMMC</p>
</td>
</tr>
<tr id="row148871689436"><td class="cellrowborder" valign="top" width="10.54%" headers="mcps1.2.6.1.1 "><p id="p688718854317"><a name="p688718854317"></a><a name="p688718854317"></a>Linux 4.19</p>
</td>
<td class="cellrowborder" valign="top" width="24.529999999999998%" headers="mcps1.2.6.1.2 "><p id="p1588818812437"><a name="p1588818812437"></a><a name="p1588818812437"></a>ARM, Arm64, MIPS, x86</p>
</td>
<td class="cellrowborder" valign="top" width="8.459999999999999%" headers="mcps1.2.6.1.3 "><p id="p1688828194310"><a name="p1688828194310"></a><a name="p1688828194310"></a>&gt; 5 MB</p>
</td>
<td class="cellrowborder" valign="top" width="33.35%" headers="mcps1.2.6.1.4 "><p id="p2504117185816"><a name="p2504117185816"></a><a name="p2504117185816"></a>VFAT, JFFS2, YAFFS, EXT/2/3/4, NFS</p>
</td>
<td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.2.6.1.5 "><p id="p8452944910"><a name="p8452944910"></a><a name="p8452944910"></a>NOR, NAND, eMMC</p>
</td>
</tr>
</tbody>
</table>

