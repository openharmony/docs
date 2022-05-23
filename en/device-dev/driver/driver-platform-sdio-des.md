# SDIO

## Overview<a name="section1155271783811"></a>

Secure Digital Input/Output \(SDIO\) is a peripheral interface evolved from the Secure Digital \(SD\) memory card interface. The SDIO interface is compatible with SD memory cards and can be connected to devices that support the SDIO interface.

SDIO is widely used. Currently, many smartphones support SDIO, and many SDIO peripherals are developed for connections to smartphones. Common SDIO peripherals include WLAN, GPS, cameras, and Bluetooth.

The SDIO bus has two ends, named host and device. All communication starts when the host sends a command. The device can communicate with the host as long as it can parse the command of the host. An SDIO host can connect to multiple devices, as shown in the figure below.
- CLK signal: clock signal sent from the host to the device
- VDD signal: power signal
- VSS signal: ground signal
- D0-3 signal: four data lines. The DAT1 signal cable is multiplexed as the interrupt line. In 1-bit mode, DAT0 is used to transmit data. In 4-bit mode, DAT0 to DAT3 are used to transmit data.
- CMD signal: used by the host to send commands and the device to respond to commands.

**Figure 1**  Connections between the host and devices in SDIO  

![](figures/en-us_image_0000001160971556.png)

The SDIO interface defines a set of common methods for operating an SDIO device, including opening and closing an SDIO controller, exclusively claiming and releasing the host, enabling and disabling devices, claiming and releasing an SDIO IRQ, reading and writing data based on SDIO, and obtaining and setting common information.

## Available APIs<a name="section12601496259"></a>

**Table 1**  APIs available for the SDIO driver

<a name="table1731550155318"></a>
<table><thead align="left"><tr id="row1625342317507"><th class="cellrowborder" valign="top" width="21.07%" id="mcps1.2.4.1.1"><p id="p1779183435016"><a name="p1779183435016"></a><a name="p1779183435016"></a>Capability</p>
</th>
<th class="cellrowborder" valign="top" width="34.04%" id="mcps1.2.4.1.2"><p id="p1879163417502"><a name="p1879163417502"></a><a name="p1879163417502"></a>Function</p>
</th>
<th class="cellrowborder" valign="top" width="44.89%" id="mcps1.2.4.1.3"><p id="p1379113410506"><a name="p1379113410506"></a><a name="p1379113410506"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1351945135614"><td class="cellrowborder" rowspan="2" valign="top" width="21.07%" headers="mcps1.2.4.1.1 "><p id="p146755118566"><a name="p146755118566"></a><a name="p146755118566"></a>SDIO device opening/closing</p>
</td>
<td class="cellrowborder" valign="top" width="34.04%" headers="mcps1.2.4.1.2 "><p id="p1151945185614"><a name="p1151945185614"></a><a name="p1151945185614"></a>SdioOpen</p>
</td>
<td class="cellrowborder" valign="top" width="44.89%" headers="mcps1.2.4.1.3 "><p id="p85110451565"><a name="p85110451565"></a><a name="p85110451565"></a>Opens an SDIO controller with a specified bus number.</p>
</td>
</tr>
<tr id="row1062610995616"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p136261793568"><a name="p136261793568"></a><a name="p136261793568"></a>SdioClose</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p062614919566"><a name="p062614919566"></a><a name="p062614919566"></a>Closes an SDIO controller.</p>
</td>
</tr>
<tr id="row337105133315"><td class="cellrowborder" rowspan="6" valign="top" width="21.07%" headers="mcps1.2.4.1.1 "><p id="p07631557153319"><a name="p07631557153319"></a><a name="p07631557153319"></a>SDIO reading/writing</p>
</td>
<td class="cellrowborder" valign="top" width="34.04%" headers="mcps1.2.4.1.2 "><p id="p34551320121416"><a name="p34551320121416"></a><a name="p34551320121416"></a>SdioReadBytes</p>
</td>
<td class="cellrowborder" valign="top" width="44.89%" headers="mcps1.2.4.1.3 "><p id="p748062291415"><a name="p748062291415"></a><a name="p748062291415"></a>Incrementally reads a given length of data from a specified SDIO address.</p>
</td>
</tr>
<tr id="row9317134301618"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p10345104001412"><a name="p10345104001412"></a><a name="p10345104001412"></a>SdioWriteBytes</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p113452040141418"><a name="p113452040141418"></a><a name="p113452040141418"></a>Incrementally writes a given length of data into a specified SDIO address.</p>
</td>
</tr>
<tr id="row131301734171616"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p713025410166"><a name="p713025410166"></a><a name="p713025410166"></a>SdioReadBytesFromFixedAddr</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p14130165418168"><a name="p14130165418168"></a><a name="p14130165418168"></a>Reads a given length of data from a fixed SDIO address.</p>
</td>
</tr>
<tr id="row1434434011147"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p1913013546161"><a name="p1913013546161"></a><a name="p1913013546161"></a>SdioWriteBytesToFixedAddr</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p111301954131614"><a name="p111301954131614"></a><a name="p111301954131614"></a>Writes a given length of data into a fixed SDIO address.</p>
</td>
</tr>
<tr id="row364393591410"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p1851815711620"><a name="p1851815711620"></a><a name="p1851815711620"></a>SdioReadBytesFromFunc0</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p751875761611"><a name="p751875761611"></a><a name="p751875761611"></a>Reads a given length of data from the address space of SDIO function 0.</p>
</td>
</tr>
<tr id="row17455333175"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p1645519318173"><a name="p1645519318173"></a><a name="p1645519318173"></a>SdioWriteBytesToFunc0</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p114552320176"><a name="p114552320176"></a><a name="p114552320176"></a>Writes a given length of data into the address space of SDIO function 0.</p>
</td>
</tr>
<tr id="row34145016535"><td class="cellrowborder" valign="top" width="21.07%" headers="mcps1.2.4.1.1 "><p id="p229610227124"><a name="p229610227124"></a><a name="p229610227124"></a>SDIO block size setting</p>
</td>
<td class="cellrowborder" valign="top" width="34.04%" headers="mcps1.2.4.1.2 "><p id="p74531720181413"><a name="p74531720181413"></a><a name="p74531720181413"></a>SdioSetBlockSize</p>
</td>
<td class="cellrowborder" valign="top" width="44.89%" headers="mcps1.2.4.1.3 "><p id="p247972241411"><a name="p247972241411"></a><a name="p247972241411"></a>Sets the block size.</p>
</td>
</tr>
<tr id="row778816813238"><td class="cellrowborder" rowspan="2" valign="top" width="21.07%" headers="mcps1.2.4.1.1 "><p id="p1578958142317"><a name="p1578958142317"></a><a name="p1578958142317"></a>SDIO common information retrieval/setting</p>
</td>
<td class="cellrowborder" valign="top" width="34.04%" headers="mcps1.2.4.1.2 "><p id="p378918842311"><a name="p378918842311"></a><a name="p378918842311"></a>SdioGetCommonInfo</p>
</td>
<td class="cellrowborder" valign="top" width="44.89%" headers="mcps1.2.4.1.3 "><p id="p1078919892313"><a name="p1078919892313"></a><a name="p1078919892313"></a>Obtains common information.</p>
</td>
</tr>
<tr id="row5667102342417"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p2668623182411"><a name="p2668623182411"></a><a name="p2668623182411"></a>SdioSetCommonInfo</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p14668192362419"><a name="p14668192362419"></a><a name="p14668192362419"></a>Sets common information.</p>
</td>
</tr>
<tr id="row1165101111256"><td class="cellrowborder" valign="top" width="21.07%" headers="mcps1.2.4.1.1 "><p id="p8166161192511"><a name="p8166161192511"></a><a name="p8166161192511"></a>SDIO data flushing</p>
</td>
<td class="cellrowborder" valign="top" width="34.04%" headers="mcps1.2.4.1.2 "><p id="p121662112256"><a name="p121662112256"></a><a name="p121662112256"></a>SdioFlushData</p>
</td>
<td class="cellrowborder" valign="top" width="44.89%" headers="mcps1.2.4.1.3 "><p id="p171661711112519"><a name="p171661711112519"></a><a name="p171661711112519"></a>Flushes data.</p>
</td>
</tr>
<tr id="row17388101522515"><td class="cellrowborder" rowspan="2" valign="top" width="21.07%" headers="mcps1.2.4.1.1 "><p id="p53101413268"><a name="p53101413268"></a><a name="p53101413268"></a>SDIO host exclusively claiming or releasing</p>
</td>
<td class="cellrowborder" valign="top" width="34.04%" headers="mcps1.2.4.1.2 "><p id="p1638881562520"><a name="p1638881562520"></a><a name="p1638881562520"></a>SdioClaimHost</p>
</td>
<td class="cellrowborder" valign="top" width="44.89%" headers="mcps1.2.4.1.3 "><p id="p143881715152517"><a name="p143881715152517"></a><a name="p143881715152517"></a>Claims a host exclusively.</p>
</td>
</tr>
<tr id="row5352175517251"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p93537557259"><a name="p93537557259"></a><a name="p93537557259"></a>SdioReleaseHost</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p1235355511254"><a name="p1235355511254"></a><a name="p1235355511254"></a>Releases the exclusively claimed host.</p>
</td>
</tr>
<tr id="row8759125415269"><td class="cellrowborder" rowspan="2" valign="top" width="21.07%" headers="mcps1.2.4.1.1 "><p id="p272143815359"><a name="p272143815359"></a><a name="p272143815359"></a>SDIO device enablement</p>
</td>
<td class="cellrowborder" valign="top" width="34.04%" headers="mcps1.2.4.1.2 "><p id="p6760195452615"><a name="p6760195452615"></a><a name="p6760195452615"></a>SdioEnableFunc</p>
</td>
<td class="cellrowborder" valign="top" width="44.89%" headers="mcps1.2.4.1.3 "><p id="p9760135417263"><a name="p9760135417263"></a><a name="p9760135417263"></a>Enables an SDIO device.</p>
</td>
</tr>
<tr id="row1166105762620"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p5662175782616"><a name="p5662175782616"></a><a name="p5662175782616"></a>SdioDisableFunc</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p3662135722618"><a name="p3662135722618"></a><a name="p3662135722618"></a>Disables an SDIO device.</p>
</td>
</tr>
<tr id="row12332331113517"><td class="cellrowborder" rowspan="2" valign="top" width="21.07%" headers="mcps1.2.4.1.1 "><p id="p188181849203614"><a name="p188181849203614"></a><a name="p188181849203614"></a>SDIO IRQ claiming/releasing</p>
</td>
<td class="cellrowborder" valign="top" width="34.04%" headers="mcps1.2.4.1.2 "><p id="p933383133517"><a name="p933383133517"></a><a name="p933383133517"></a>SdioClaimIrq</p>
</td>
<td class="cellrowborder" valign="top" width="44.89%" headers="mcps1.2.4.1.3 "><p id="p20333431203510"><a name="p20333431203510"></a><a name="p20333431203510"></a>Claims an SDIO IRQ.</p>
</td>
</tr>
<tr id="row173103413357"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p2073123413515"><a name="p2073123413515"></a><a name="p2073123413515"></a>SdioReleaseIrq</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p1773634153518"><a name="p1773634153518"></a><a name="p1773634153518"></a>Releases an SDIO IRQ.</p>
</td>
</tr>
</tbody>
</table>

>![](../public_sys-resources/icon-note.gif) **NOTE:**<br>
>All functions provided in this document can be called only in kernel mode.

## Usage Guidelines<a name="section1878939192515"></a>

### How to Use<a name="section1490685512255"></a>

The figure below illustrates how to use the APIs.

**Figure 2**  Using SDIO driver APIs

  


![](figures/using-SDIO-process.png)

### Opening an SDIO Controller<a name="section10782428132616"></a>

Before performing SDIO communication, obtain the device handle of an SDIO controller by calling **SdioOpen**. This function returns the device handle of the SDIO controller with a specified bus number.

DevHandle SdioOpen\(int16\_t mmcBusNum, struct SdioFunctionConfig \*config\);

**Table 2**  Parameters and return values of SdioOpen

<a name="table1036944152712"></a>
<table><thead align="left"><tr id="row4370114192717"><th class="cellrowborder" valign="top" width="50%" id="mcps1.2.3.1.1"><p id="p737074112720"><a name="p737074112720"></a><a name="p737074112720"></a>Parameter</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.2.3.1.2"><p id="p15370154102716"><a name="p15370154102716"></a><a name="p15370154102716"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row3370184112716"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p337094142715"><a name="p337094142715"></a><a name="p337094142715"></a>mmcBusNum</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p8370154162718"><a name="p8370154162718"></a><a name="p8370154162718"></a>Bus number.</p>
</td>
</tr>
<tr id="row10370746272"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p23706402717"><a name="p23706402717"></a><a name="p23706402717"></a>config</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p153701492715"><a name="p153701492715"></a><a name="p153701492715"></a>SDIO functionality configurations.</p>
</td>
</tr>
<tr id="row173703417274"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p183701349276"><a name="p183701349276"></a><a name="p183701349276"></a><strong id="b11478182120013"><a name="b11478182120013"></a><a name="b11478182120013"></a>Return Value</strong></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p203701647275"><a name="p203701647275"></a><a name="p203701647275"></a><strong id="b277217221307"><a name="b277217221307"></a><a name="b277217221307"></a>Description</strong></p>
</td>
</tr>
<tr id="row837016462716"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p937184172716"><a name="p937184172716"></a><a name="p937184172716"></a>NULL</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p1837184182720"><a name="p1837184182720"></a><a name="p1837184182720"></a>Failed to obtain the device handle of an SDIO controller.</p>
</td>
</tr>
<tr id="row737116492712"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p537174122715"><a name="p537174122715"></a><a name="p537174122715"></a>Device handle</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p113715411274"><a name="p113715411274"></a><a name="p113715411274"></a>Device handle of an SDIO controller.</p>
</td>
</tr>
</tbody>
</table>

The following example shows how to open an SDIO controller.

```
DevHandle handle = NULL;
struct SdioFunctionConfig config;
config.funcNr = 1;
config.vendorId = 0x123;
config.deviceId = 0x456;
/* Open an SDIO controller whose bus number is 1. */
handle = SdioOpen(1, &config);
if (handle == NULL) {
    HDF_LOGE("SdioOpen: failed!\n");
}
```

### Claiming a Host Exclusively<a name="section11263172312715"></a>

After obtaining the device handle of an SDIO controller, exclusively claim the host before performing subsequent operations on the SDIO device.

void SdioClaimHost\(DevHandle handle\);

**Table 3**  Parameter description of SdioClaimHost

<a name="table192822447271"></a>
<table><thead align="left"><tr id="row192829443279"><th class="cellrowborder" valign="top" width="50%" id="mcps1.2.3.1.1"><p id="p1128284452713"><a name="p1128284452713"></a><a name="p1128284452713"></a>Parameter</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.2.3.1.2"><p id="p1528264418272"><a name="p1528264418272"></a><a name="p1528264418272"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row328264472711"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p15282124420274"><a name="p15282124420274"></a><a name="p15282124420274"></a>handle</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p0282164432719"><a name="p0282164432719"></a><a name="p0282164432719"></a>Device handle of an SDIO controller.</p>
</td>
</tr>
</tbody>
</table>

The following example shows how to exclusively claim a host.

```
SdioClaimHost(handle); /* Claim a host exclusively. */
```

### Enabling the SDIO Device<a name="section17861486271"></a>

Before accessing a register, enable the SDIO device.

int32\_t SdioEnableFunc\(DevHandle handle\);

**Table 4**  Parameters and return values of SdioEnableFunc

<a name="table144881047485"></a>
<table><thead align="left"><tr id="row8487204184815"><th class="cellrowborder" valign="top" width="50%" id="mcps1.2.3.1.1"><p id="p1648611415486"><a name="p1648611415486"></a><a name="p1648611415486"></a>Parameter</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.2.3.1.2"><p id="p19487134124820"><a name="p19487134124820"></a><a name="p19487134124820"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row16487044480"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p74878414810"><a name="p74878414810"></a><a name="p74878414810"></a>handle</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p17487184194819"><a name="p17487184194819"></a><a name="p17487184194819"></a>Device handle of an SDIO controller.</p>
</td>
</tr>
<tr id="row13487748487"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p24873424811"><a name="p24873424811"></a><a name="p24873424811"></a><strong id="b048017216013"><a name="b048017216013"></a><a name="b048017216013"></a>Return Value</strong></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p4487174134813"><a name="p4487174134813"></a><a name="p4487174134813"></a><strong id="b87731622105"><a name="b87731622105"></a><a name="b87731622105"></a>Description</strong></p>
</td>
</tr>
<tr id="row1748814494812"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p84878410488"><a name="p84878410488"></a><a name="p84878410488"></a>0</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p948715410483"><a name="p948715410483"></a><a name="p948715410483"></a>The SDIO device is enabled.</p>
</td>
</tr>
<tr id="row54881416482"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p24881645489"><a name="p24881645489"></a><a name="p24881645489"></a>Negative value</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p10488247487"><a name="p10488247487"></a><a name="p10488247487"></a>Failed to enable the SDIO device.</p>
</td>
</tr>
</tbody>
</table>

The following example shows how to enable the SDIO device.

```
int32_t ret;
/* Enable the SDIO device. */
ret = SdioEnableFunc(handle);
if (ret != 0) {
    HDF_LOGE("SdioEnableFunc: failed, ret %d\n", ret);
}
```

### Claiming an SDIO IRQ<a name="section521213262286"></a>

Before SDIO communication, claim an SDIO IRQ.

int32\_t SdioClaimIrq\(DevHandle handle, SdioIrqHandler \*handler\);

**Table 5**  Parameters and return values of SdioClaimIrq

<a name="table1149014114815"></a>
<table><thead align="left"><tr id="row114891042488"><th class="cellrowborder" valign="top" width="49.980000000000004%" id="mcps1.2.3.1.1"><p id="p1348864164811"><a name="p1348864164811"></a><a name="p1348864164811"></a>Parameter</p>
</th>
<th class="cellrowborder" valign="top" width="50.019999999999996%" id="mcps1.2.3.1.2"><p id="p14885410486"><a name="p14885410486"></a><a name="p14885410486"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row048911404820"><td class="cellrowborder" valign="top" width="49.980000000000004%" headers="mcps1.2.3.1.1 "><p id="p248974174814"><a name="p248974174814"></a><a name="p248974174814"></a>handle</p>
</td>
<td class="cellrowborder" valign="top" width="50.019999999999996%" headers="mcps1.2.3.1.2 "><p id="p1848915494813"><a name="p1848915494813"></a><a name="p1848915494813"></a>Device handle of an SDIO controller.</p>
</td>
</tr>
<tr id="row204894454813"><td class="cellrowborder" valign="top" width="49.980000000000004%" headers="mcps1.2.3.1.1 "><p id="p17489944488"><a name="p17489944488"></a><a name="p17489944488"></a>handler</p>
</td>
<td class="cellrowborder" valign="top" width="50.019999999999996%" headers="mcps1.2.3.1.2 "><p id="p1548984174813"><a name="p1548984174813"></a><a name="p1548984174813"></a>Pointer to the SDIO IRQ function.</p>
</td>
</tr>
<tr id="row44898413488"><td class="cellrowborder" valign="top" width="49.980000000000004%" headers="mcps1.2.3.1.1 "><p id="p1548934124815"><a name="p1548934124815"></a><a name="p1548934124815"></a><strong id="b548120216017"><a name="b548120216017"></a><a name="b548120216017"></a>Return Value</strong></p>
</td>
<td class="cellrowborder" valign="top" width="50.019999999999996%" headers="mcps1.2.3.1.2 "><p id="p54891444485"><a name="p54891444485"></a><a name="p54891444485"></a><strong id="b877422211013"><a name="b877422211013"></a><a name="b877422211013"></a>Description</strong></p>
</td>
</tr>
<tr id="row748994144811"><td class="cellrowborder" valign="top" width="49.980000000000004%" headers="mcps1.2.3.1.1 "><p id="p448918415484"><a name="p448918415484"></a><a name="p448918415484"></a>0</p>
</td>
<td class="cellrowborder" valign="top" width="50.019999999999996%" headers="mcps1.2.3.1.2 "><p id="p174892412489"><a name="p174892412489"></a><a name="p174892412489"></a>The SDIO IRQ is claimed.</p>
</td>
</tr>
<tr id="row448914420489"><td class="cellrowborder" valign="top" width="49.980000000000004%" headers="mcps1.2.3.1.1 "><p id="p248912464817"><a name="p248912464817"></a><a name="p248912464817"></a>Negative value</p>
</td>
<td class="cellrowborder" valign="top" width="50.019999999999996%" headers="mcps1.2.3.1.2 "><p id="p34891645485"><a name="p34891645485"></a><a name="p34891645485"></a>Failed to claim an SDIO IRQ.</p>
</td>
</tr>
</tbody>
</table>

The following example shows how to claim an SDIO IRQ.

```
/* Implement the SDIO IRQ function based on the application. */
static void SdioIrqFunc(void *data)
{
    if (data == NULL) {
        HDF_LOGE("SdioIrqFunc: data is NULL.\n");
        return;
    }
    /* You need to add specific implementations. */
}

int32_t ret;
/* Claim an SDIO IRQ. */
ret = SdioClaimIrq(handle, SdioIrqFunc);
if (ret != 0) {
    HDF_LOGE("SdioClaimIrq: failed, ret %d\n", ret);
}
```

### Performing SDIO Communication<a name="section85661522153420"></a>

- Incrementally write a given length of data into the SDIO device.

The corresponding function is as follows:

int32\_t SdioWriteBytes\(DevHandle handle, uint8\_t \*data, uint32\_t addr, uint32\_t size\);

**Table 6**  Parameters and return values of SdioWriteBytes

<a name="table6887174174111"></a>
<table><thead align="left"><tr id="row10887144111419"><th class="cellrowborder" valign="top" width="50%" id="mcps1.2.3.1.1"><p id="p181381751164113"><a name="p181381751164113"></a><a name="p181381751164113"></a>Parameter</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.2.3.1.2"><p id="p19138115184116"><a name="p19138115184116"></a><a name="p19138115184116"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row4887341174114"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p1534612017427"><a name="p1534612017427"></a><a name="p1534612017427"></a>handle</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p8179347434"><a name="p8179347434"></a><a name="p8179347434"></a>Device handle of an SDIO controller.</p>
</td>
</tr>
<tr id="row18881041144120"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p10888154118412"><a name="p10888154118412"></a><a name="p10888154118412"></a>data</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p1288854115413"><a name="p1288854115413"></a><a name="p1288854115413"></a>Pointer to the data to write.</p>
</td>
</tr>
<tr id="row191054911432"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p91054994311"><a name="p91054994311"></a><a name="p91054994311"></a>addr</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p111024915432"><a name="p111024915432"></a><a name="p111024915432"></a>Start address where the data is written into.</p>
</td>
</tr>
<tr id="row14888144124119"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p1588814413412"><a name="p1588814413412"></a><a name="p1588814413412"></a>size</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p1288813411413"><a name="p1288813411413"></a><a name="p1288813411413"></a>Length of the data to write.</p>
</td>
</tr>
<tr id="row18247654163519"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p486155173610"><a name="p486155173610"></a><a name="p486155173610"></a><strong id="b84827210012"><a name="b84827210012"></a><a name="b84827210012"></a>Return Value</strong></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p1686155113620"><a name="p1686155113620"></a><a name="p1686155113620"></a><strong id="b16775152213010"><a name="b16775152213010"></a><a name="b16775152213010"></a>Description</strong></p>
</td>
</tr>
<tr id="row10574165663512"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p912141012364"><a name="p912141012364"></a><a name="p912141012364"></a>0</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p51219107363"><a name="p51219107363"></a><a name="p51219107363"></a>Data is written into the SDIO device.</p>
</td>
</tr>
<tr id="row1490635883519"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p10121510133617"><a name="p10121510133617"></a><a name="p10121510133617"></a>Negative value</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p131212106365"><a name="p131212106365"></a><a name="p131212106365"></a>Failed to write data into the SDIO device.</p>
</td>
</tr>
</tbody>
</table>

The following example shows how to incrementally write a given length of data into the SDIO device.

```
int32_t ret;
uint8_t wbuff[] = {1,2,3,4,5};
uint32_t addr = 0x100 + 0x09;
/* Incrementally write 5-byte data into the start address 0x109 of the SDIO device. */
ret = SdioWriteBytes(handle, wbuff, addr, sizeof(wbuff) / sizeof(wbuff[0]));
if (ret != 0) {
    HDF_LOGE("SdioWriteBytes: failed, ret %d\n", ret);
}
```

- Incrementally read a given length of data from the SDIO device.

The corresponding function is as follows:

int32\_t SdioReadBytes\(DevHandle handle, uint8\_t \*data, uint32\_t addr, uint32\_t size\);

**Table 7**  Parameters and return values of SdioReadBytes

<a name="table5783755152110"></a>
<table><thead align="left"><tr id="row19783355162116"><th class="cellrowborder" valign="top" width="50%" id="mcps1.2.3.1.1"><p id="p635754142212"><a name="p635754142212"></a><a name="p635754142212"></a>Parameter</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.2.3.1.2"><p id="p1035774182215"><a name="p1035774182215"></a><a name="p1035774182215"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row137831055192118"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p14783155192114"><a name="p14783155192114"></a><a name="p14783155192114"></a>handle</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p9676437202218"><a name="p9676437202218"></a><a name="p9676437202218"></a>Device handle of an SDIO controller.</p>
</td>
</tr>
<tr id="row4784155102111"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p1978455510217"><a name="p1978455510217"></a><a name="p1978455510217"></a>data</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p767683714223"><a name="p767683714223"></a><a name="p767683714223"></a>Pointer to the data to read.</p>
</td>
</tr>
<tr id="row63651118499"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p73669113496"><a name="p73669113496"></a><a name="p73669113496"></a>addr</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p53661144916"><a name="p53661144916"></a><a name="p53661144916"></a>Start address where the data is read from.</p>
</td>
</tr>
<tr id="row7784145510218"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p1078413554219"><a name="p1078413554219"></a><a name="p1078413554219"></a>size</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p14676163782210"><a name="p14676163782210"></a><a name="p14676163782210"></a>Length of the data to read.</p>
</td>
</tr>
<tr id="row964182643610"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p7833639163612"><a name="p7833639163612"></a><a name="p7833639163612"></a><strong id="b84831021108"><a name="b84831021108"></a><a name="b84831021108"></a>Return Value</strong></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p3833939113619"><a name="p3833939113619"></a><a name="p3833939113619"></a><strong id="b17775192216016"><a name="b17775192216016"></a><a name="b17775192216016"></a>Description</strong></p>
</td>
</tr>
<tr id="row199479312363"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p567424413611"><a name="p567424413611"></a><a name="p567424413611"></a>0</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p166741544113615"><a name="p166741544113615"></a><a name="p166741544113615"></a>Data is read from the SDIO device.</p>
</td>
</tr>
<tr id="row5166203418361"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p1167416448361"><a name="p1167416448361"></a><a name="p1167416448361"></a>Negative value</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p9674114410364"><a name="p9674114410364"></a><a name="p9674114410364"></a>Failed to read data from the SDIO device.</p>
</td>
</tr>
</tbody>
</table>

The following example shows how to incrementally read a given length of data from the SDIO device.

```
int32_t ret;
uint8_t rbuff[5] = {0};
uint32_t addr = 0x100 + 0x09;
/* Incrementally read 5-byte data from the start address 0x109 of the SDIO device. */
ret = SdioReadBytes(handle, rbuff, addr, 5);
if (ret != 0) {
    HDF_LOGE("SdioReadBytes: failed, ret %d\n", ret);
}
```

- Write a given length of data into the fixed address of an SDIO device.

    The corresponding function is as follows:

    int32\_t SdioWriteBytesToFixedAddr\(DevHandle handle, uint8\_t \*data, uint32\_t addr, uint32\_t size, uint32\_t scatterLen\);

   **Table 8**  Parameters and return values of SdioWriteBytesToFixedAddr

    <a name="table1982918113010"></a>
    <table><thead align="left"><tr id="row1582911114010"><th class="cellrowborder" valign="top" width="48.43%" id="mcps1.2.3.1.1"><p id="p28301411903"><a name="p28301411903"></a><a name="p28301411903"></a>Parameter</p>
    </th>
    <th class="cellrowborder" valign="top" width="51.57000000000001%" id="mcps1.2.3.1.2"><p id="p1883019111018"><a name="p1883019111018"></a><a name="p1883019111018"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row10830141111014"><td class="cellrowborder" valign="top" width="48.43%" headers="mcps1.2.3.1.1 "><p id="p470818551018"><a name="p470818551018"></a><a name="p470818551018"></a>handle</p>
    </td>
    <td class="cellrowborder" valign="top" width="51.57000000000001%" headers="mcps1.2.3.1.2 "><p id="p18578510518"><a name="p18578510518"></a><a name="p18578510518"></a>Device handle of an SDIO controller.</p>
    </td>
    </tr>
    <tr id="row48303111304"><td class="cellrowborder" valign="top" width="48.43%" headers="mcps1.2.3.1.1 "><p id="p127081955502"><a name="p127081955502"></a><a name="p127081955502"></a>data</p>
    </td>
    <td class="cellrowborder" valign="top" width="51.57000000000001%" headers="mcps1.2.3.1.2 "><p id="p1857841013110"><a name="p1857841013110"></a><a name="p1857841013110"></a>Pointer to the data to write.</p>
    </td>
    </tr>
    <tr id="row9830111119019"><td class="cellrowborder" valign="top" width="48.43%" headers="mcps1.2.3.1.1 "><p id="p187085555011"><a name="p187085555011"></a><a name="p187085555011"></a>addr</p>
    </td>
    <td class="cellrowborder" valign="top" width="51.57000000000001%" headers="mcps1.2.3.1.2 "><p id="p257831016115"><a name="p257831016115"></a><a name="p257831016115"></a>Fixed address where the data is written into.</p>
    </td>
    </tr>
    <tr id="row683091120012"><td class="cellrowborder" valign="top" width="48.43%" headers="mcps1.2.3.1.1 "><p id="p370819555013"><a name="p370819555013"></a><a name="p370819555013"></a>size</p>
    </td>
    <td class="cellrowborder" valign="top" width="51.57000000000001%" headers="mcps1.2.3.1.2 "><p id="p7578181015113"><a name="p7578181015113"></a><a name="p7578181015113"></a>Length of the data to write.</p>
    </td>
    </tr>
    <tr id="row58301911309"><td class="cellrowborder" valign="top" width="48.43%" headers="mcps1.2.3.1.1 "><p id="p570810551107"><a name="p570810551107"></a><a name="p570810551107"></a>scatterLen</p>
    </td>
    <td class="cellrowborder" valign="top" width="51.57000000000001%" headers="mcps1.2.3.1.2 "><p id="p17579910915"><a name="p17579910915"></a><a name="p17579910915"></a>Length of the scatter list. If the value is not <strong id="b107381713254"><a name="b107381713254"></a><a name="b107381713254"></a>0</strong>, the data is of the scatter list type.</p>
    </td>
    </tr>
    <tr id="row18215162810212"><td class="cellrowborder" valign="top" width="48.43%" headers="mcps1.2.3.1.1 "><p id="p1521319452211"><a name="p1521319452211"></a><a name="p1521319452211"></a><strong id="b648472113017"><a name="b648472113017"></a><a name="b648472113017"></a>Return Value</strong></p>
    </td>
    <td class="cellrowborder" valign="top" width="51.57000000000001%" headers="mcps1.2.3.1.2 "><p id="p162138457217"><a name="p162138457217"></a><a name="p162138457217"></a><strong id="b1277682210016"><a name="b1277682210016"></a><a name="b1277682210016"></a>Description</strong></p>
    </td>
    </tr>
    <tr id="row2197123118210"><td class="cellrowborder" valign="top" width="48.43%" headers="mcps1.2.3.1.1 "><p id="p1921413451212"><a name="p1921413451212"></a><a name="p1921413451212"></a>0</p>
    </td>
    <td class="cellrowborder" valign="top" width="51.57000000000001%" headers="mcps1.2.3.1.2 "><p id="p32146451624"><a name="p32146451624"></a><a name="p32146451624"></a>Data is written into the SDIO device.</p>
    </td>
    </tr>
    <tr id="row18629103314218"><td class="cellrowborder" valign="top" width="48.43%" headers="mcps1.2.3.1.1 "><p id="p132141245622"><a name="p132141245622"></a><a name="p132141245622"></a>Negative value</p>
    </td>
    <td class="cellrowborder" valign="top" width="51.57000000000001%" headers="mcps1.2.3.1.2 "><p id="p17214345328"><a name="p17214345328"></a><a name="p17214345328"></a>Failed to write data into the SDIO device.</p>
    </td>
    </tr>
    </tbody>
    </table>

    The following example shows how to write a given length of data into the fixed address of an SDIO device.

    ```
    int32_t ret;
    uint8_t wbuff[] = {1, 2, 3, 4, 5};
    uint32_t addr = 0x100 + 0x09;
    /* Write 5-byte data into the fixed address 0x109 of the SDIO device. */
    ret = SdioWriteBytesToFixedAddr(handle, wbuff, addr, sizeof(wbuff) / sizeof(wbuff[0]), 0);
    if (ret != 0) {
        HDF_LOGE("SdioWriteBytesToFixedAddr: failed, ret %d\n", ret);
    }
    ```

- Read a given length of data from the fixed address of an SDIO device.

    The corresponding function is as follows:

    int32\_t SdioReadBytesFromFixedAddr\(DevHandle handle, uint8\_t \*data, uint32\_t addr, uint32\_t size, uint32\_t scatterLen\);

   **Table 9**  Parameters and return values of SdioReadBytesFromFixedAddr

    <a name="table2724132220115"></a>
    <table><thead align="left"><tr id="row8724142214115"><th class="cellrowborder" valign="top" width="48.699999999999996%" id="mcps1.2.3.1.1"><p id="p16752055131112"><a name="p16752055131112"></a><a name="p16752055131112"></a>Parameter</p>
    </th>
    <th class="cellrowborder" valign="top" width="51.300000000000004%" id="mcps1.2.3.1.2"><p id="p914434191218"><a name="p914434191218"></a><a name="p914434191218"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row1372462214119"><td class="cellrowborder" valign="top" width="48.699999999999996%" headers="mcps1.2.3.1.1 "><p id="p2752175516113"><a name="p2752175516113"></a><a name="p2752175516113"></a>handle</p>
    </td>
    <td class="cellrowborder" valign="top" width="51.300000000000004%" headers="mcps1.2.3.1.2 "><p id="p1353155020125"><a name="p1353155020125"></a><a name="p1353155020125"></a>Device handle of an SDIO controller.</p>
    </td>
    </tr>
    <tr id="row197244220117"><td class="cellrowborder" valign="top" width="48.699999999999996%" headers="mcps1.2.3.1.1 "><p id="p12752165581117"><a name="p12752165581117"></a><a name="p12752165581117"></a>data</p>
    </td>
    <td class="cellrowborder" valign="top" width="51.300000000000004%" headers="mcps1.2.3.1.2 "><p id="p9540508121"><a name="p9540508121"></a><a name="p9540508121"></a>Pointer to the data to read.</p>
    </td>
    </tr>
    <tr id="row172519228116"><td class="cellrowborder" valign="top" width="48.699999999999996%" headers="mcps1.2.3.1.1 "><p id="p1675315521120"><a name="p1675315521120"></a><a name="p1675315521120"></a>addr</p>
    </td>
    <td class="cellrowborder" valign="top" width="51.300000000000004%" headers="mcps1.2.3.1.2 "><p id="p05415501125"><a name="p05415501125"></a><a name="p05415501125"></a>Start address where the data is read from.</p>
    </td>
    </tr>
    <tr id="row137251922131117"><td class="cellrowborder" valign="top" width="48.699999999999996%" headers="mcps1.2.3.1.1 "><p id="p47531355111111"><a name="p47531355111111"></a><a name="p47531355111111"></a>size</p>
    </td>
    <td class="cellrowborder" valign="top" width="51.300000000000004%" headers="mcps1.2.3.1.2 "><p id="p1954165031214"><a name="p1954165031214"></a><a name="p1954165031214"></a>Length of the data to read.</p>
    </td>
    </tr>
    <tr id="row972552281111"><td class="cellrowborder" valign="top" width="48.699999999999996%" headers="mcps1.2.3.1.1 "><p id="p2753755161114"><a name="p2753755161114"></a><a name="p2753755161114"></a>scatterLen</p>
    </td>
    <td class="cellrowborder" valign="top" width="51.300000000000004%" headers="mcps1.2.3.1.2 "><p id="p3541350111218"><a name="p3541350111218"></a><a name="p3541350111218"></a>Length of the scatter list. If the value is not <strong id="b498517146511"><a name="b498517146511"></a><a name="b498517146511"></a>0</strong>, the data is of the scatter list type.</p>
    </td>
    </tr>
    <tr id="row15725162210117"><td class="cellrowborder" valign="top" width="48.699999999999996%" headers="mcps1.2.3.1.1 "><p id="p681073451314"><a name="p681073451314"></a><a name="p681073451314"></a><strong id="b144852215014"><a name="b144852215014"></a><a name="b144852215014"></a>Return Value</strong></p>
    </td>
    <td class="cellrowborder" valign="top" width="51.300000000000004%" headers="mcps1.2.3.1.2 "><p id="p17810134121316"><a name="p17810134121316"></a><a name="p17810134121316"></a><strong id="b127776221003"><a name="b127776221003"></a><a name="b127776221003"></a>Description</strong></p>
    </td>
    </tr>
    <tr id="row1772511227119"><td class="cellrowborder" valign="top" width="48.699999999999996%" headers="mcps1.2.3.1.1 "><p id="p78105346133"><a name="p78105346133"></a><a name="p78105346133"></a>0</p>
    </td>
    <td class="cellrowborder" valign="top" width="51.300000000000004%" headers="mcps1.2.3.1.2 "><p id="p18810173411312"><a name="p18810173411312"></a><a name="p18810173411312"></a>Data is read from the SDIO device.</p>
    </td>
    </tr>
    <tr id="row191829161138"><td class="cellrowborder" valign="top" width="48.699999999999996%" headers="mcps1.2.3.1.1 "><p id="p1581012340131"><a name="p1581012340131"></a><a name="p1581012340131"></a>Negative value</p>
    </td>
    <td class="cellrowborder" valign="top" width="51.300000000000004%" headers="mcps1.2.3.1.2 "><p id="p28101834161317"><a name="p28101834161317"></a><a name="p28101834161317"></a>Failed to read data from the SDIO device.</p>
    </td>
    </tr>
    </tbody>
    </table>

    The following example shows how to read a given length of data from the fixed address of an SDIO device.

    ```
    int32_t ret;
    uint8_t rbuff[5] = {0};
    uint32_t addr = 0x100 + 0x09;
    /* Read 5-byte data from the fixed address 0x109 of the SDIO device. */
    ret = SdioReadBytesFromFixedAddr(handle, rbuff, addr, 5, 0);
    if (ret != 0) {
        HDF_LOGE("SdioReadBytesFromFixedAddr: failed, ret %d\n", ret);
    }
    ```


- Writes a given length of data into the address space of SDIO function 0.

Currently, only 1-byte data can be written. The corresponding function is as follows:

int32\_t SdioWriteBytesToFunc0\(DevHandle handle, uint8\_t \*data, uint32\_t addr, uint32\_t size\);

**Table 10**  Parameters and return values of SdioWriteBytesToFunc0

<a name="table5339151811112"></a>
<table><thead align="left"><tr id="row2033991881120"><th class="cellrowborder" valign="top" width="49.94%" id="mcps1.2.3.1.1"><p id="p1116916499117"><a name="p1116916499117"></a><a name="p1116916499117"></a>Parameter</p>
</th>
<th class="cellrowborder" valign="top" width="50.06%" id="mcps1.2.3.1.2"><p id="p13169174971115"><a name="p13169174971115"></a><a name="p13169174971115"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row9339171871118"><td class="cellrowborder" valign="top" width="49.94%" headers="mcps1.2.3.1.1 "><p id="p16169194914117"><a name="p16169194914117"></a><a name="p16169194914117"></a>handle</p>
</td>
<td class="cellrowborder" valign="top" width="50.06%" headers="mcps1.2.3.1.2 "><p id="p10169114921110"><a name="p10169114921110"></a><a name="p10169114921110"></a>Device handle of an SDIO controller.</p>
</td>
</tr>
<tr id="row93401118171116"><td class="cellrowborder" valign="top" width="49.94%" headers="mcps1.2.3.1.1 "><p id="p216919491118"><a name="p216919491118"></a><a name="p216919491118"></a>data</p>
</td>
<td class="cellrowborder" valign="top" width="50.06%" headers="mcps1.2.3.1.2 "><p id="p5169449121117"><a name="p5169449121117"></a><a name="p5169449121117"></a>Pointer to the data to write.</p>
</td>
</tr>
<tr id="row534019182114"><td class="cellrowborder" valign="top" width="49.94%" headers="mcps1.2.3.1.1 "><p id="p2016934941114"><a name="p2016934941114"></a><a name="p2016934941114"></a>addr</p>
</td>
<td class="cellrowborder" valign="top" width="50.06%" headers="mcps1.2.3.1.2 "><p id="p8169649101112"><a name="p8169649101112"></a><a name="p8169649101112"></a>Start address where the data is written into.</p>
</td>
</tr>
<tr id="row334011871113"><td class="cellrowborder" valign="top" width="49.94%" headers="mcps1.2.3.1.1 "><p id="p6169194913117"><a name="p6169194913117"></a><a name="p6169194913117"></a>size</p>
</td>
<td class="cellrowborder" valign="top" width="50.06%" headers="mcps1.2.3.1.2 "><p id="p71691449141119"><a name="p71691449141119"></a><a name="p71691449141119"></a>Length of the data to write.</p>
</td>
</tr>
<tr id="row123407185111"><td class="cellrowborder" valign="top" width="49.94%" headers="mcps1.2.3.1.1 "><p id="p294173071617"><a name="p294173071617"></a><a name="p294173071617"></a><strong id="b848612215010"><a name="b848612215010"></a><a name="b848612215010"></a>Return Value</strong></p>
</td>
<td class="cellrowborder" valign="top" width="50.06%" headers="mcps1.2.3.1.2 "><p id="p39421830111616"><a name="p39421830111616"></a><a name="p39421830111616"></a><strong id="b27786221308"><a name="b27786221308"></a><a name="b27786221308"></a>Description</strong></p>
</td>
</tr>
<tr id="row8950101811164"><td class="cellrowborder" valign="top" width="49.94%" headers="mcps1.2.3.1.1 "><p id="p9942730181613"><a name="p9942730181613"></a><a name="p9942730181613"></a>0</p>
</td>
<td class="cellrowborder" valign="top" width="50.06%" headers="mcps1.2.3.1.2 "><p id="p89421130141617"><a name="p89421130141617"></a><a name="p89421130141617"></a>Data is written into the SDIO device.</p>
</td>
</tr>
<tr id="row42485216168"><td class="cellrowborder" valign="top" width="49.94%" headers="mcps1.2.3.1.1 "><p id="p1194223012167"><a name="p1194223012167"></a><a name="p1194223012167"></a>Negative value</p>
</td>
<td class="cellrowborder" valign="top" width="50.06%" headers="mcps1.2.3.1.2 "><p id="p19942630121617"><a name="p19942630121617"></a><a name="p19942630121617"></a>Failed to write data into the SDIO device.</p>
</td>
</tr>
</tbody>
</table>

The following example shows how to write a given length of data into the address space of SDIO function 0.

```
int32_t ret;
uint8_t wbuff = 1;
/* Write 1-byte data into the address 0x2 of SDIO function 0. */
ret = SdioWriteBytesToFunc0(handle, &wbuff, 0x2, 1);
if (ret != 0) {
    HDF_LOGE("SdioWriteBytesToFunc0: failed, ret %d\n", ret);
}
```

- Reads a given length of data from the address space of SDIO function 0.

Currently, only 1-byte data can be read. The corresponding function is as follows:

int32\_t SdioReadBytesFromFunc0\(DevHandle handle, uint8\_t \*data, uint32\_t addr, uint32\_t size\);

**Table 11**  Parameters and return values of SdioReadBytesFromFunc0

<a name="table1071931161814"></a>
<table><thead align="left"><tr id="row771918171819"><th class="cellrowborder" valign="top" width="50%" id="mcps1.2.3.1.1"><p id="p71291418171813"><a name="p71291418171813"></a><a name="p71291418171813"></a>Parameter</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.2.3.1.2"><p id="p51291818101818"><a name="p51291818101818"></a><a name="p51291818101818"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row9720113186"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p121294185189"><a name="p121294185189"></a><a name="p121294185189"></a>handle</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p20129141815184"><a name="p20129141815184"></a><a name="p20129141815184"></a>Device handle of an SDIO controller.</p>
</td>
</tr>
<tr id="row672017114185"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p171291186185"><a name="p171291186185"></a><a name="p171291186185"></a>data</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p8129118171820"><a name="p8129118171820"></a><a name="p8129118171820"></a>Pointer to the data to read.</p>
</td>
</tr>
<tr id="row5720910188"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p8129121816184"><a name="p8129121816184"></a><a name="p8129121816184"></a>addr</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p21296189182"><a name="p21296189182"></a><a name="p21296189182"></a>Start address where the data is read from.</p>
</td>
</tr>
<tr id="row172020115189"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p18129418191816"><a name="p18129418191816"></a><a name="p18129418191816"></a>size</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p612921851820"><a name="p612921851820"></a><a name="p612921851820"></a>Length of the data to read.</p>
</td>
</tr>
<tr id="row167202113189"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p1813001881810"><a name="p1813001881810"></a><a name="p1813001881810"></a><strong id="b164871218012"><a name="b164871218012"></a><a name="b164871218012"></a>Return Value</strong></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p1313081817184"><a name="p1313081817184"></a><a name="p1313081817184"></a><strong id="b17795221202"><a name="b17795221202"></a><a name="b17795221202"></a>Description</strong></p>
</td>
</tr>
<tr id="row17720151101818"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p131307185182"><a name="p131307185182"></a><a name="p131307185182"></a>0</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p113019187182"><a name="p113019187182"></a><a name="p113019187182"></a>Data is read from the SDIO device.</p>
</td>
</tr>
<tr id="row1972019118189"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p18130151815185"><a name="p18130151815185"></a><a name="p18130151815185"></a>Negative value</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p1013001861815"><a name="p1013001861815"></a><a name="p1013001861815"></a>Failed to read data from the SDIO device.</p>
</td>
</tr>
</tbody>
</table>

The following example shows how to read a given length of data from the address space of SDIO function 0.

```
int32_t ret;
uint8_t rbuff;
/* Read 1-byte data from the address 0x2 of SDIO function 0. */
ret = SdioReadBytesFromFunc0(handle, &rbuff, 0x2, 1);
if (ret != 0) {
    HDF_LOGE("SdioReadBytesFromFunc0: failed, ret %d\n", ret);
}
```

### Releasing the SDIO IRQ<a name="section1683449352"></a>

After the SDIO communication, release the SDIO IRQ.

int32\_t SdioReleaseIrq\(DevHandle handle\);

**Table 12**  Parameters and return values of SdioReleaseIrq

<a name="table165006412481"></a>
<table><thead align="left"><tr id="row15499849482"><th class="cellrowborder" valign="top" width="50%" id="mcps1.2.3.1.1"><p id="p1549964114814"><a name="p1549964114814"></a><a name="p1549964114814"></a>Parameter</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.2.3.1.2"><p id="p749915484816"><a name="p749915484816"></a><a name="p749915484816"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1499194104813"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p9499743481"><a name="p9499743481"></a><a name="p9499743481"></a>handle</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p184999434815"><a name="p184999434815"></a><a name="p184999434815"></a>Device handle of an SDIO controller.</p>
</td>
</tr>
<tr id="row3499442485"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p649918414812"><a name="p649918414812"></a><a name="p649918414812"></a><strong id="b54881821905"><a name="b54881821905"></a><a name="b54881821905"></a>Return Value</strong></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p164991242486"><a name="p164991242486"></a><a name="p164991242486"></a><strong id="b1078062218018"><a name="b1078062218018"></a><a name="b1078062218018"></a>Description</strong></p>
</td>
</tr>
<tr id="row1349919494810"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p24994484820"><a name="p24994484820"></a><a name="p24994484820"></a>0</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p1649920414482"><a name="p1649920414482"></a><a name="p1649920414482"></a>The SDIO IRQ is released.</p>
</td>
</tr>
<tr id="row17500204154810"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p194990415489"><a name="p194990415489"></a><a name="p194990415489"></a>Negative value</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p74997419484"><a name="p74997419484"></a><a name="p74997419484"></a>Failed to release the SDIO IRQ.</p>
</td>
</tr>
</tbody>
</table>

The following example shows how to release the SDIO IRQ.

```
int32_t ret;
/* Release the SDIO IRQ. */
ret = SdioReleaseIrq(handle);
if (ret != 0) {
    HDF_LOGE("SdioReleaseIrq: failed, ret %d\n", ret);
}
```

### Disabling the SDIO Device<a name="section15379324143611"></a>

After the SDIO communication, disable the SDIO device.

int32\_t SdioDisableFunc\(DevHandle handle\);

**Table 13**  Parameters and return values of SdioDisableFunc

<a name="table25012415481"></a>
<table><thead align="left"><tr id="row1050010474810"><th class="cellrowborder" valign="top" width="50%" id="mcps1.2.3.1.1"><p id="p05002419488"><a name="p05002419488"></a><a name="p05002419488"></a>Parameter</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.2.3.1.2"><p id="p17500114174811"><a name="p17500114174811"></a><a name="p17500114174811"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row65001946482"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p1150054104814"><a name="p1150054104814"></a><a name="p1150054104814"></a>handle</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p1850014184812"><a name="p1850014184812"></a><a name="p1850014184812"></a>Device handle of an SDIO controller.</p>
</td>
</tr>
<tr id="row175013494817"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p350013434816"><a name="p350013434816"></a><a name="p350013434816"></a><strong id="b1448917215019"><a name="b1448917215019"></a><a name="b1448917215019"></a>Return Value</strong></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p1750184104813"><a name="p1750184104813"></a><a name="p1750184104813"></a><strong id="b37811222007"><a name="b37811222007"></a><a name="b37811222007"></a>Description</strong></p>
</td>
</tr>
<tr id="row1850113413481"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p11501164114818"><a name="p11501164114818"></a><a name="p11501164114818"></a>0</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p1550116416489"><a name="p1550116416489"></a><a name="p1550116416489"></a>The SDIO device is disabled.</p>
</td>
</tr>
<tr id="row45015444817"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p7501184154816"><a name="p7501184154816"></a><a name="p7501184154816"></a>Negative value</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p35011040484"><a name="p35011040484"></a><a name="p35011040484"></a>Failed to disable the SDIO device.</p>
</td>
</tr>
</tbody>
</table>

The following example shows how to disable the SDIO device.

```
int32_t ret;
/* Disable the SDIO device. */
ret = SdioDisableFunc(handle);
if (ret != 0) {
    HDF_LOGE("SdioDisableFunc: failed, ret %d\n", ret);
}
```

### Releasing the Exclusively Claimed Host<a name="section536018263713"></a>

After the SDIO communication, release the exclusively claimed host.

void SdioReleaseHost\(DevHandle handle\);

**Table 14**  Parameter description of SdioReleaseHost

<a name="table1350214164813"></a>
<table><thead align="left"><tr id="row6502134194814"><th class="cellrowborder" valign="top" width="50%" id="mcps1.2.3.1.1"><p id="p18501945486"><a name="p18501945486"></a><a name="p18501945486"></a>Parameter</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.2.3.1.2"><p id="p45028414817"><a name="p45028414817"></a><a name="p45028414817"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row135027411483"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p16502174204816"><a name="p16502174204816"></a><a name="p16502174204816"></a>handle</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p6502164184816"><a name="p6502164184816"></a><a name="p6502164184816"></a>Device handle of an SDIO controller.</p>
</td>
</tr>
</tbody>
</table>

The following example shows how to release the exclusively claimed host.

```
SdioReleaseHost(handle); /* Release the exclusively claimed host. */
```

### Closing an SDIO Controller<a name="section4752739183716"></a>

After the SDIO communication, close the SDIO controller.

void SdioClose\(DevHandle handle\);

This function releases the resources requested.

**Table 15**  Parameter description of SdioClose

<a name="table950324124815"></a>
<table><thead align="left"><tr id="row1050213424819"><th class="cellrowborder" valign="top" width="50%" id="mcps1.2.3.1.1"><p id="p18502134194818"><a name="p18502134194818"></a><a name="p18502134194818"></a>Parameter</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.2.3.1.2"><p id="p2502154104813"><a name="p2502154104813"></a><a name="p2502154104813"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row25035434810"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p175028434819"><a name="p175028434819"></a><a name="p175028434819"></a>handle</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p2050274194819"><a name="p2050274194819"></a><a name="p2050274194819"></a>Device handle of an SDIO controller.</p>
</td>
</tr>
</tbody>
</table>

The following example shows how to close an SDIO controller.

```
SdioClose(handle); /* Close an SDIO controller. */
```

## Usage Example<a name="section376910122382"></a>

The following example shows how to use an SDIO device. First, open an SDIO controller whose bus number is 1, exclusively claim a host, enable the SDIO device, claim an SDIO IRQ, and then perform SDIO communication \(such as reading and writing\). After the SDIO communication, release the SDIO IRQ, disable the SDIO device, release the host, and close the SDIO controller.

```
#include "hdf_log.h"
#include "sdio_if.h"

#define TEST_FUNC_NUM 1 /* The I/O function whose ID is 1 is used. */
#define TEST_FBR_BASE_ADDR 0x100 /* FBR base address of the I/O function whose ID is 1 */
#define TEST_ADDR_OFFSET 9 /* Address offset of the register to read or write */
#define TEST_DATA_LEN 3 /* Length of the data to read or write */
#define TEST_BLOCKSIZE 2 /* Size of a data block, in bytes */

/* Implement the SDIO IRQ function based on the application. */
static void SdioIrqFunc(void *data)
{
    if (data == NULL) {
        HDF_LOGE("SdioIrqFunc: data is NULL.\n");
        return;
    }
    /* You need to add specific implementations. */
}

void SdioTestSample(void)
{
    int32_t ret;  
    DevHandle handle = NULL;
    uint8_t data[TEST_DATA_LEN] = {0};
    struct SdioFunctionConfig config = {1, 0x123, 0x456};
    uint8_t val;
    uint32_t addr;
    
    /* Open an SDIO controller whose bus number is 1. */
    handle = SdioOpen(1, &config);
    if (handle == NULL) {
        HDF_LOGE("SdioOpen: failed!\n");
        return;
    }
   /* Claim a host exclusively. */
    SdioClaimHost(handle);
   /* Enable the SDIO device. */
    ret = SdioEnableFunc(handle);
    if (ret != 0) {
        HDF_LOGE("SdioEnableFunc: failed, ret %d\n", ret);
        goto ENABLE_ERR;
    }
   /* Claim an SDIO IRQ. */
    ret = SdioClaimIrq(handle, SdioIrqFunc);
    if (ret != 0) {
        HDF_LOGE("SdioClaimIrq: failed, ret %d\n", ret);
        goto CLAIM_IRQ_ERR;
    }
    /* Set the block size to 2 bytes. */
    ret = SdioSetBlockSize(handle, TEST_BLOCKSIZE);
    if (ret != 0) {
        HDF_LOGE("SdioSetBlockSize: failed, ret %d\n", ret);
        goto COMM_ERR;
    }
    /* Read 3-byte data from the incremental address of an SDIO device. */
    addr = TEST_FBR_BASE_ADDR * TEST_FUNC_NUM + TEST_ADDR_OFFSET;
    ret = SdioReadBytes(handle, data, addr, TEST_DATA_LEN);
    if (ret != 0) {
        HDF_LOGE("SdioReadBytes: failed, ret %d\n", ret);
        goto COMM_ERR;
    }
    /* Write 3-byte data into the incremental address of an SDIO device. */
    ret = SdioWriteBytes(handle, data, addr, TEST_DATA_LEN);
    if (ret != 0) {
        HDF_LOGE("SdioWriteBytes: failed, ret %d\n", ret);
        goto COMM_ERR;
    }
    /* Read 1-byte data from the SDIO device. */
    ret = SdioReadBytes(handle, &val, addr, 1);
    if (ret != 0) {
        HDF_LOGE("SdioReadBytes: failed, ret %d\n", ret);
        goto COMM_ERR;
    }
    /* Write 1-byte data into the SDIO device. */
    ret = SdioWriteBytes(handle, &val, addr, 1);
    if (ret != 0) {
        HDF_LOGE("SdioWriteBytes: failed, ret %d\n", ret);
        goto COMM_ERR;
    }
    /* Read 3-byte data from the fixed address of an SDIO device. */
    ret = SdioReadBytesFromFixedAddr(handle, data, addr, TEST_DATA_LEN, 0);
    if (ret != 0) {
        HDF_LOGE("SdioReadBytesFromFixedAddr: failed, ret %d\n", ret);
        goto COMM_ERR;
    }
    /* Write 1-byte data to the fixed address of an SDIO device. */
    ret = SdioWriteBytesToFixedAddr(handle, data, addr, 1, 0);
    if (ret != 0) {
        HDF_LOGE("SdioWriteBytesToFixedAddr: failed, ret %d\n", ret);
        goto COMM_ERR;
    }
    /* Read 1-byte data from SDIO function 0. */
    addr = 0x02;
    ret = SdioReadBytesFromFunc0(handle, &val, addr, 1);
    if (ret != 0) {
        HDF_LOGE("SdioReadBytesFromFunc0: failed, ret %d\n", ret);
        goto COMM_ERR;
    }
    /* Write 1-byte data into SDIO function 0. */
    ret = SdioWriteBytesToFunc0(handle, &val, addr, 1);
    if (ret != 0) {
        HDF_LOGE("SdioWriteBytesToFunc0: failed, ret %d\n", ret);
        goto COMM_ERR;
    }
COMM_ERR:
    /* Release the SDIO IRQ. */
    ret = SdioReleaseIrq(handle);
    if (ret != 0) {
        HDF_LOGE("SdioReleaseIrq: failed, ret %d\n", ret);
    }
CLAIM_IRQ_ERR:
    /* Disable the SDIO device. */
    ret = SdioDisableFunc(handle);
    if (ret != 0) {
        HDF_LOGE("SdioDisableFunc: failed, ret %d\n", ret);
    }
ENABLE_ERR:
    /* Release the exclusively claimed host. */
    SdioReleaseHost(handle);
    /* Close an SDIO controller. */
    SdioClose(handle); 
}
```