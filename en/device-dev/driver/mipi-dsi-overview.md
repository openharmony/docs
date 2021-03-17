# MIPI DSI Overview<a name="EN-US_TOPIC_0000001062724343"></a>

-   [Introduction](#section1369320102013)
-   [Available APIs](#section6577545192317)

## Introduction<a name="section1369320102013"></a>

-   The Display Serial Interface \(DSI\) is a specification stipulated by the Mobile Industry Processor Interface \(MIPI\) Alliance, aiming to reduce the cost of display controllers in a mobile device. It defines a serial bus and communication protocol among the host, the source of image data, and the target device. In this way, the DSI can send pixel data or commands to peripherals \(usually LCDs or similar display devices\) in serial mode, or reads information such as status and pixel from the peripherals.

-   MIPI DSI is capable of working in both high speed \(HS\) mode and low power \(LP\) mode. All data lanes can only travel from the DSI host to a peripheral in HS mode, except the first data lane, which can also receive data such as status information and pixels from the peripheral in LP mode. The clock lane is dedicated to transmitting synchronization clock signals in HS mode.
    -   [Figure 1](#fig1122611461203)  shows a simplified DSI interface. Conceptually, a DSI-compliant interface has the same features as interfaces complying with DBI-2 and DPI-2 standards. It sends pixels or commands to a peripheral and can read status or pixel information from the peripheral. The main difference is that the DSI serializes all pixel data, commands, and events that, in traditional interfaces, are conveyed to and from the peripheral on a parallel data bus with additional control signals.

        **Figure  1**  DSI transmitting and receiving Interface<a name="fig1122611461203"></a>  
        ![](figures/dsi-transmitting-and-receiving-interface.png "dsi-transmitting-and-receiving-interface")



## Available APIs<a name="section6577545192317"></a>

**Table  1**  APIs for MIPI DSI

<a name="table4199102313245"></a>
<table><thead align="left"><tr id="row1619910238244"><th class="cellrowborder" valign="top" width="26.619999999999997%" id="mcps1.2.4.1.1"><p id="p141991023182411"><a name="p141991023182411"></a><a name="p141991023182411"></a>Capability</p>
</th>
<th class="cellrowborder" valign="top" width="28.910000000000004%" id="mcps1.2.4.1.2"><p id="p1199102315247"><a name="p1199102315247"></a><a name="p1199102315247"></a>Function</p>
</th>
<th class="cellrowborder" valign="top" width="44.47%" id="mcps1.2.4.1.3"><p id="p719918232240"><a name="p719918232240"></a><a name="p719918232240"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row15199023172414"><td class="cellrowborder" rowspan="2" valign="top" width="26.619999999999997%" headers="mcps1.2.4.1.1 "><p id="p919902312413"><a name="p919902312413"></a><a name="p919902312413"></a>Setting/Obtaining MIPI DSI configuration parameters</p>
</td>
<td class="cellrowborder" valign="top" width="28.910000000000004%" headers="mcps1.2.4.1.2 "><p id="p21995232243"><a name="p21995232243"></a><a name="p21995232243"></a>MipiDsiSetCfg</p>
</td>
<td class="cellrowborder" valign="top" width="44.47%" headers="mcps1.2.4.1.3 "><p id="p919911233240"><a name="p919911233240"></a><a name="p919911233240"></a>Sets configuration parameters for a MIPI DSI device.</p>
</td>
</tr>
<tr id="row171996232248"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p7199623152412"><a name="p7199623152412"></a><a name="p7199623152412"></a>MipiDsiGetCfg</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p1119919235248"><a name="p1119919235248"></a><a name="p1119919235248"></a>Obtains the configuration parameters of a MIPI DSI device.</p>
</td>
</tr>
<tr id="row91994239242"><td class="cellrowborder" rowspan="2" valign="top" width="26.619999999999997%" headers="mcps1.2.4.1.1 "><p id="p101998233245"><a name="p101998233245"></a><a name="p101998233245"></a>Obtaining /Releasing device handles</p>
</td>
<td class="cellrowborder" valign="top" width="28.910000000000004%" headers="mcps1.2.4.1.2 "><p id="p51991323112415"><a name="p51991323112415"></a><a name="p51991323112415"></a>MipiDsiOpen</p>
</td>
<td class="cellrowborder" valign="top" width="44.47%" headers="mcps1.2.4.1.3 "><p id="p11991623182415"><a name="p11991623182415"></a><a name="p11991623182415"></a>Obtains a MIPI DSI device handle.</p>
</td>
</tr>
<tr id="row12199192352411"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p131991123172412"><a name="p131991123172412"></a><a name="p131991123172412"></a>MipiDsiClose</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p520062313249"><a name="p520062313249"></a><a name="p520062313249"></a>Releases a specified MIPI DSI device handle.</p>
</td>
</tr>
<tr id="row7200152382417"><td class="cellrowborder" rowspan="2" valign="top" width="26.619999999999997%" headers="mcps1.2.4.1.1 "><p id="p8200202312241"><a name="p8200202312241"></a><a name="p8200202312241"></a>Setting the LP or HS mode</p>
</td>
<td class="cellrowborder" valign="top" width="28.910000000000004%" headers="mcps1.2.4.1.2 "><p id="p6200192318247"><a name="p6200192318247"></a><a name="p6200192318247"></a>MipiDsiSetLpMode</p>
</td>
<td class="cellrowborder" valign="top" width="44.47%" headers="mcps1.2.4.1.3 "><p id="p16200192319240"><a name="p16200192319240"></a><a name="p16200192319240"></a>Sets LP mode for a MIPI DSI device.</p>
</td>
</tr>
<tr id="row122001523182417"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p22009236249"><a name="p22009236249"></a><a name="p22009236249"></a>MipiDsiSetHsMode</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p22001423192418"><a name="p22001423192418"></a><a name="p22001423192418"></a>Sets HS mode for a MIPI DSI device.</p>
</td>
</tr>
<tr id="row52002237248"><td class="cellrowborder" rowspan="2" valign="top" width="26.619999999999997%" headers="mcps1.2.4.1.1 "><p id="p10200162332412"><a name="p10200162332412"></a><a name="p10200162332412"></a>Reading/Sending commands</p>
</td>
<td class="cellrowborder" valign="top" width="28.910000000000004%" headers="mcps1.2.4.1.2 "><p id="p19200142315249"><a name="p19200142315249"></a><a name="p19200142315249"></a>MipiDsiTx</p>
</td>
<td class="cellrowborder" valign="top" width="44.47%" headers="mcps1.2.4.1.3 "><p id="p1020082319243"><a name="p1020082319243"></a><a name="p1020082319243"></a>Sends a display command set (DCS) command for sending data.</p>
</td>
</tr>
<tr id="row6200162372416"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p18200112392417"><a name="p18200112392417"></a><a name="p18200112392417"></a>MipiDsiRx</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p9200102312249"><a name="p9200102312249"></a><a name="p9200102312249"></a>Receives a DCS command for reading data with the specified length.</p>
</td>
</tr>
</tbody>
</table>

>![](public_sys-resources/icon-note.gif) **NOTE:** 
>All functions described in this document can be called only in kernel space.

