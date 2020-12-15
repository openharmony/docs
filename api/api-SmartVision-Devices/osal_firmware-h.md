# osal\_firmware.h<a name="ZH-CN_TOPIC_0000001054718101"></a>

-   [Overview](#section1066745201165628)
-   [Summary](#section588592143165628)
-   [Data Structures](#nested-classes)
-   [Functions](#func-members)

## **Overview**<a name="section1066745201165628"></a>

**Related Modules:**

[OSAL](OSAL.md)

**Description:**

Declares firmware structures and interfaces. 

This file provides operations such as requesting and reading a firmware file, setting the offset for reading a firmware file, and releasing a firmware file. The firmware file can be read in split mode. The size of the firmware block to read each time is defined by the macro  **HDF\_FW\_BLOCK\_SIZE**. The firmware file is requested by calling  [OsalRequestFirmware](OSAL.md#ga428b9de7fb95a20ab9e25b47a7d4272c), the firmware block is read from the firmware file by calling  [OsalReadFirmware](OSAL.md#ga2b721d36c177786841cd05cecdb01034), and the firmware block can also be randomly read at a specified position by calling  [OsalSeekFirmware](OSAL.md#ga41ae4dade9246f3b30efd276cbd43474).

**Since:**

1.0

**Version:**

1.0

## **Summary**<a name="section588592143165628"></a>

## Data Structures<a name="nested-classes"></a>

<a name="table171085170165628"></a>
<table><thead align="left"><tr id="row416798148165628"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p453292282165628"><a name="p453292282165628"></a><a name="p453292282165628"></a>Data Structure Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1953555449165628"><a name="p1953555449165628"></a><a name="p1953555449165628"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row271026366165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1101237908165628"><a name="p1101237908165628"></a><a name="p1101237908165628"></a><a href="OsalFirmware.md">OsalFirmware</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1706962078165628"><a name="p1706962078165628"></a><a name="p1706962078165628"></a>Defines the data structure for operating a firmware file. </p>
</td>
</tr>
<tr id="row970141822165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p866534043165628"><a name="p866534043165628"></a><a name="p866534043165628"></a><a href="OsalFwBlock.md">OsalFwBlock</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p638018213165628"><a name="p638018213165628"></a><a name="p638018213165628"></a>Defines the data structure for reading a firmware file. </p>
</td>
</tr>
</tbody>
</table>

## Functions<a name="func-members"></a>

<a name="table922966045165628"></a>
<table><thead align="left"><tr id="row837777159165628"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1694708152165628"><a name="p1694708152165628"></a><a name="p1694708152165628"></a>Function</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1184067706165628"><a name="p1184067706165628"></a><a name="p1184067706165628"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row411216124165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2007224945165628"><a name="p2007224945165628"></a><a name="p2007224945165628"></a><a href="OSAL.md#ga428b9de7fb95a20ab9e25b47a7d4272c">OsalRequestFirmware</a> (struct <a href="OsalFirmware.md">OsalFirmware</a> *fw, const char *fwName, void *device)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1400939603165628"><a name="p1400939603165628"></a><a name="p1400939603165628"></a>int32_t </p>
<p id="p1056450308165628"><a name="p1056450308165628"></a><a name="p1056450308165628"></a>Requests a firmware file based on its name and device information. </p>
</td>
</tr>
<tr id="row281085907165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p578812261165628"><a name="p578812261165628"></a><a name="p578812261165628"></a><a href="OSAL.md#ga41ae4dade9246f3b30efd276cbd43474">OsalSeekFirmware</a> (struct <a href="OsalFirmware.md">OsalFirmware</a> *fw, uint32_t offset)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1682398033165628"><a name="p1682398033165628"></a><a name="p1682398033165628"></a>int32_t </p>
<p id="p2054350134165628"><a name="p2054350134165628"></a><a name="p2054350134165628"></a>Reads a firmware file. </p>
</td>
</tr>
<tr id="row1951332928165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2035162693165628"><a name="p2035162693165628"></a><a name="p2035162693165628"></a><a href="OSAL.md#ga2b721d36c177786841cd05cecdb01034">OsalReadFirmware</a> (struct <a href="OsalFirmware.md">OsalFirmware</a> *fw, struct <a href="OsalFwBlock.md">OsalFwBlock</a> *block)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p855076606165628"><a name="p855076606165628"></a><a name="p855076606165628"></a>int32_t </p>
<p id="p1721408302165628"><a name="p1721408302165628"></a><a name="p1721408302165628"></a>Releases a firmware file. </p>
</td>
</tr>
<tr id="row114621975165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1005902748165628"><a name="p1005902748165628"></a><a name="p1005902748165628"></a><a href="OSAL.md#gadfccddc78411a76ae8f4af4282da12f0">OsalReleaseFirmware</a> (struct <a href="OsalFirmware.md">OsalFirmware</a> *fw)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2051150504165628"><a name="p2051150504165628"></a><a name="p2051150504165628"></a>int32_t </p>
</td>
</tr>
</tbody>
</table>

