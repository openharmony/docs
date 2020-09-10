# Kernel Subsystem<a name="EN-US_TOPIC_0000001051340509"></a>

## Overview<a name="section12995104752113"></a>

The OpenHarmony kernel is a real-time OS kernel developed by Huawei for IoT devices. It is as lightweight as RTOS and as easy-to-use as Linux.

The kernel repository is used to store the source code of the OpenHarmony kernel components, including process and thread scheduling, memory management, IPC mechanism, and timer management, as well as the version package compilation information.

## Directory Structure<a name="section1121775732114"></a>

**Table  1**  Directory structure of the OpenHarmony lightweight kernel source code

<a name="table2977131081412"></a>
<table><thead align="left"><tr id="row7977610131417"><th class="cellrowborder" valign="top" width="30.34%" id="mcps1.2.3.1.1"><p id="p18792459121314"><a name="p18792459121314"></a><a name="p18792459121314"></a>Directory</p>
</th>
<th class="cellrowborder" valign="top" width="69.66%" id="mcps1.2.3.1.2"><p id="p77921459191317"><a name="p77921459191317"></a><a name="p77921459191317"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row17977171010144"><td class="cellrowborder" valign="top" width="30.34%" headers="mcps1.2.3.1.1 "><p id="p2793159171311"><a name="p2793159171311"></a><a name="p2793159171311"></a>apps</p>
</td>
<td class="cellrowborder" valign="top" width="69.66%" headers="mcps1.2.3.1.2 "><p id="p879375920132"><a name="p879375920132"></a><a name="p879375920132"></a>User-space init and shell application program</p>
</td>
</tr>
<tr id="row6978161091412"><td class="cellrowborder" valign="top" width="30.34%" headers="mcps1.2.3.1.1 "><p id="p37931659101311"><a name="p37931659101311"></a><a name="p37931659101311"></a>arch</p>
</td>
<td class="cellrowborder" valign="top" width="69.66%" headers="mcps1.2.3.1.2 "><p id="p6793059171318"><a name="p6793059171318"></a><a name="p6793059171318"></a>System architecture, such as ARM</p>
</td>
</tr>
<tr id="row6978201031415"><td class="cellrowborder" valign="top" width="30.34%" headers="mcps1.2.3.1.1 "><p id="p117935599130"><a name="p117935599130"></a><a name="p117935599130"></a>bsd</p>
</td>
<td class="cellrowborder" valign="top" width="69.66%" headers="mcps1.2.3.1.2 "><p id="p0793185971316"><a name="p0793185971316"></a><a name="p0793185971316"></a>Code of the driver and adaptation layer module related to the FreeBSD, such as the USB module</p>
</td>
</tr>
<tr id="row113263612392"><td class="cellrowborder" valign="top" width="30.34%" headers="mcps1.2.3.1.1 "><p id="p2133163611390"><a name="p2133163611390"></a><a name="p2133163611390"></a>compat</p>
</td>
<td class="cellrowborder" valign="top" width="69.66%" headers="mcps1.2.3.1.2 "><p id="p1913313364399"><a name="p1913313364399"></a><a name="p1913313364399"></a>Compatibility with the kernel POSIX interfaces</p>
</td>
</tr>
<tr id="row15700172218399"><td class="cellrowborder" valign="top" width="30.34%" headers="mcps1.2.3.1.1 "><p id="p10701622113920"><a name="p10701622113920"></a><a name="p10701622113920"></a>fs</p>
</td>
<td class="cellrowborder" valign="top" width="69.66%" headers="mcps1.2.3.1.2 "><p id="p270110222398"><a name="p270110222398"></a><a name="p270110222398"></a>File system module, which mainly derives from the NuttX open-source project</p>
</td>
</tr>
<tr id="row1897841071415"><td class="cellrowborder" valign="top" width="30.34%" headers="mcps1.2.3.1.1 "><p id="p16793185961315"><a name="p16793185961315"></a><a name="p16793185961315"></a>kernel</p>
</td>
<td class="cellrowborder" valign="top" width="69.66%" headers="mcps1.2.3.1.2 "><p id="p14793959161317"><a name="p14793959161317"></a><a name="p14793959161317"></a>Kernel modules including the process, memory, and IPC modules</p>
</td>
</tr>
<tr id="row172848480398"><td class="cellrowborder" valign="top" width="30.34%" headers="mcps1.2.3.1.1 "><p id="p728414485392"><a name="p728414485392"></a><a name="p728414485392"></a>lib</p>
</td>
<td class="cellrowborder" valign="top" width="69.66%" headers="mcps1.2.3.1.2 "><p id="p12284154818399"><a name="p12284154818399"></a><a name="p12284154818399"></a>Kernel library</p>
</td>
</tr>
<tr id="row5827141194012"><td class="cellrowborder" valign="top" width="30.34%" headers="mcps1.2.3.1.1 "><p id="p48272110403"><a name="p48272110403"></a><a name="p48272110403"></a>net</p>
</td>
<td class="cellrowborder" valign="top" width="69.66%" headers="mcps1.2.3.1.2 "><p id="p28272119406"><a name="p28272119406"></a><a name="p28272119406"></a>Network module, which mainly derives from the lwip open-source project</p>
</td>
</tr>
<tr id="row980916239407"><td class="cellrowborder" valign="top" width="30.34%" headers="mcps1.2.3.1.1 "><p id="p080910232403"><a name="p080910232403"></a><a name="p080910232403"></a>platform</p>
</td>
<td class="cellrowborder" valign="top" width="69.66%" headers="mcps1.2.3.1.2 "><p id="p11809202324018"><a name="p11809202324018"></a><a name="p11809202324018"></a>Code for supporting different systems on a chip (SOCs), such as Hi3516DV300</p>
</td>
</tr>
<tr id="row194244440402"><td class="cellrowborder" valign="top" width="30.34%" headers="mcps1.2.3.1.1 "><p id="p0424124412401"><a name="p0424124412401"></a><a name="p0424124412401"></a>security</p>
</td>
<td class="cellrowborder" valign="top" width="69.66%" headers="mcps1.2.3.1.2 "><p id="p442410448409"><a name="p442410448409"></a><a name="p442410448409"></a>Code related to security features, including process permission management and virtual ID mapping management</p>
</td>
</tr>
<tr id="row674312515406"><td class="cellrowborder" valign="top" width="30.34%" headers="mcps1.2.3.1.1 "><p id="p1274395114012"><a name="p1274395114012"></a><a name="p1274395114012"></a>syscall</p>
</td>
<td class="cellrowborder" valign="top" width="69.66%" headers="mcps1.2.3.1.2 "><p id="p1374365134011"><a name="p1374365134011"></a><a name="p1374365134011"></a>System calls</p>
</td>
</tr>
<tr id="row6470183019419"><td class="cellrowborder" valign="top" width="30.34%" headers="mcps1.2.3.1.1 "><p id="p17470143094117"><a name="p17470143094117"></a><a name="p17470143094117"></a>test</p>
</td>
<td class="cellrowborder" valign="top" width="69.66%" headers="mcps1.2.3.1.2 "><p id="p547013018415"><a name="p547013018415"></a><a name="p547013018415"></a>Kernel and user-space test cases</p>
</td>
</tr>
<tr id="row343553564120"><td class="cellrowborder" valign="top" width="30.34%" headers="mcps1.2.3.1.1 "><p id="p54351735114113"><a name="p54351735114113"></a><a name="p54351735114113"></a>tools</p>
</td>
<td class="cellrowborder" valign="top" width="69.66%" headers="mcps1.2.3.1.2 "><p id="p17435635114116"><a name="p17435635114116"></a><a name="p17435635114116"></a>Code related to compilation configuration and <strong id="b1181842313414"><a name="b1181842313414"></a><a name="b1181842313414"></a>menuconfig</strong></p>
</td>
</tr>
</tbody>
</table>

## Constraints<a name="section1967115154223"></a>

By default, the JFFS2 file system is used during system startup. This file system is read-write. If other file systems need to be used, the configurations of the file systems must be added accordingly.

## Usage<a name="section1821123352217"></a>

For details, see  [en-us\_bookmap\_0000001050030794.md\#en-us\_topic\_0000001050032743](en-us_bookmap_0000001050030794.md#en-us_topic_0000001050032743).

## Repositories Involved<a name="section2392425183215"></a>

drivers\_liteos

kernel\_liteos\_a

kernel\_liteos\_a\_huawei\_proprietary\_fs\_proc

kernel\_liteos\_m

