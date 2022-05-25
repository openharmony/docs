# UART<a name="EN-US_TOPIC_0000001160652800"></a>

## Overview<a name="section833012453535"></a>

The Universal Asynchronous Receiver/Transmitter \(UART\) is a universal serial data bus used for asynchronous communication. It enables bi-directional communication between devices in full-duplex mode.
UART is widely used to print information for debugging or to connect to various external modules such as GPS and Bluetooth.
A UART is connected to other modules through two wires \(as shown in  [Figure 1](#fig68294715408)\) or four wires \(as shown in  [Figure 2](#fig179241542163112)\).
-   TX: TX pin of the transmitting UART. It is connected to the RX pin of the peer UART.
-   RX: RX pin of the receiving UART. It is connected to the TX pin of the peer UART.
-   RTS: Request to Send signal pin. It is connected to the CTS pin of the peer UART and is used to indicate whether the local UART is ready to receive data.
-   CTS: Clear to Send signal pin. It is connected to the RTS pin of the peer UART and is used to indicate whether the local UART is allowed to send data to the peer end.

       **Figure  1** 2-wire UART communication<a name="fig68294715408"></a>  
        ![](figures/2-wire-uart-communication.png "2-wire-uart-communication")

       **Figure  2** 4-wire UART communication<a name="fig179241542163112"></a>  
        ![](figures/4-wire-uart-communication.png "4-wire-uart-communication")


The transmitting and receiving UARTs must ensure that they have the same settings on particular attributes such as the baud rate and data format \(start bit, data bit, parity bit, and stop bit\) before they start to communicate. During data transmission, a UART sends data to the peer end over the TX pin and receives data from the peer end over the RX pin. When the size of the buffer used by a UART for storing received data reaches the preset threshold, the RTS signal of the UART changes to **1** \(data cannot be received\), and the peer UART stops sending data to it because its CTS signal does not allow it to send data.


## Available APIs<a name="section1928742202715"></a>

The UART interface defines a set of common functions for operating a UART port, including obtaining and releasing device handles, reading and writing data of a specified length, and obtaining and setting the baud rate, as well as the device attributes.

**Table  1** APIs for the UART driver

<a name="table1731550155318"></a>
<table><thead align="left"><tr id="row1223152681611"><th class="cellrowborder" valign="top" width="26.619999999999997%" id="mcps1.2.4.1.1"><p id="p210413571619"><a name="p210413571619"></a><a name="p210413571619"></a><strong id="b4100105545211"><a name="b4100105545211"></a><a name="b4100105545211"></a>Capability</strong></p>
</th>
<th class="cellrowborder" valign="top" width="31.369999999999997%" id="mcps1.2.4.1.2"><p id="p810403511614"><a name="p810403511614"></a><a name="p810403511614"></a><strong id="b1653121711186"><a name="b1653121711186"></a><a name="b1653121711186"></a>Function</strong></p>
</th>
<th class="cellrowborder" valign="top" width="42.01%" id="mcps1.2.4.1.3"><p id="p110418354161"><a name="p110418354161"></a><a name="p110418354161"></a><strong id="b69108168153412"><a name="b69108168153412"></a><a name="b69108168153412"></a>Description</strong></p>
</th>
</tr>
</thead>
<tbody><tr id="row1638573613415"><td class="cellrowborder" rowspan="2" valign="top" width="26.619999999999997%" headers="mcps1.2.4.1.1 "><p id="p917154316414"><a name="p917154316414"></a><a name="p917154316414"></a>Obtaining and releasing device handles</p>
<p id="p9596111154212"><a name="p9596111154212"></a><a name="p9596111154212"></a></p>
</td>
<td class="cellrowborder" valign="top" width="31.369999999999997%" headers="mcps1.2.4.1.2 "><p id="p20385163614412"><a name="p20385163614412"></a><a name="p20385163614412"></a>UartOpen</p>
</td>
<td class="cellrowborder" valign="top" width="42.01%" headers="mcps1.2.4.1.3 "><p id="p12101135184213"><a name="p12101135184213"></a><a name="p12101135184213"></a>Obtains the UART device handle.</p>
</td>
</tr>
<tr id="row5950143316415"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p149501733134113"><a name="p149501733134113"></a><a name="p149501733134113"></a>UartClose</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p371073520422"><a name="p371073520422"></a><a name="p371073520422"></a>Releases a specified UART device handle.</p>
</td>
</tr>
<tr id="row34145016535"><td class="cellrowborder" rowspan="2" valign="top" width="26.619999999999997%" headers="mcps1.2.4.1.1 "><p id="p229610227124"><a name="p229610227124"></a><a name="p229610227124"></a>Reading and writing data</p>
<p id="p131072201215"><a name="p131072201215"></a><a name="p131072201215"></a></p>
</td>
<td class="cellrowborder" valign="top" width="31.369999999999997%" headers="mcps1.2.4.1.2 "><p id="p8296182221219"><a name="p8296182221219"></a><a name="p8296182221219"></a>UartRead</p>
</td>
<td class="cellrowborder" valign="top" width="42.01%" headers="mcps1.2.4.1.3 "><p id="p16297172213125"><a name="p16297172213125"></a><a name="p16297172213125"></a>Reads data of a specified length from a UART device.</p>
</td>
</tr>
<tr id="row11585016539"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p1095722493616"><a name="p1095722493616"></a><a name="p1095722493616"></a>UartWrite</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p15297162215122"><a name="p15297162215122"></a><a name="p15297162215122"></a>Writes data of a specified length into a UART device.</p>
</td>
</tr>
<tr id="row8687115843715"><td class="cellrowborder" rowspan="2" valign="top" width="26.619999999999997%" headers="mcps1.2.4.1.1 "><p id="p196317143813"><a name="p196317143813"></a><a name="p196317143813"></a>Obtaining and setting the baud rate</p>
</td>
<td class="cellrowborder" valign="top" width="31.369999999999997%" headers="mcps1.2.4.1.2 "><p id="p166885582375"><a name="p166885582375"></a><a name="p166885582375"></a>UartGetBaud</p>
</td>
<td class="cellrowborder" valign="top" width="42.01%" headers="mcps1.2.4.1.3 "><p id="p13688358183716"><a name="p13688358183716"></a><a name="p13688358183716"></a>Obtains the UART baud rate.</p>
</td>
</tr>
<tr id="row18987529382"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p698719214383"><a name="p698719214383"></a><a name="p698719214383"></a>UartSetBaud</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p1398712123810"><a name="p1398712123810"></a><a name="p1398712123810"></a>Sets the UART baud rate.</p>
</td>
</tr>
<tr id="row1551850115317"><td class="cellrowborder" rowspan="2" valign="top" width="26.619999999999997%" headers="mcps1.2.4.1.1 "><p id="p1629782201218"><a name="p1629782201218"></a><a name="p1629782201218"></a>Obtaining and setting device attributes</p>
<p id="p10308192211216"><a name="p10308192211216"></a><a name="p10308192211216"></a></p>
</td>
<td class="cellrowborder" valign="top" width="31.369999999999997%" headers="mcps1.2.4.1.2 "><p id="p32972022151218"><a name="p32972022151218"></a><a name="p32972022151218"></a>UartGetAttribute</p>
</td>
<td class="cellrowborder" valign="top" width="42.01%" headers="mcps1.2.4.1.3 "><p id="p13297122216123"><a name="p13297122216123"></a><a name="p13297122216123"></a>Obtains the UART device attributes.</p>
</td>
</tr>
<tr id="row7545065311"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p102974224120"><a name="p102974224120"></a><a name="p102974224120"></a>UartSetAttribute</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p152971322111219"><a name="p152971322111219"></a><a name="p152971322111219"></a>Sets the UART device attributes.</p>
</td>
</tr>
<tr id="row14614115403"><td class="cellrowborder" valign="top" width="26.619999999999997%" headers="mcps1.2.4.1.1 "><p id="p1746281144010"><a name="p1746281144010"></a><a name="p1746281144010"></a>Setting the transmission mode</p>
</td>
<td class="cellrowborder" valign="top" width="31.369999999999997%" headers="mcps1.2.4.1.2 "><p id="p1146215112405"><a name="p1146215112405"></a><a name="p1146215112405"></a>UartSetTransMode</p>
</td>
<td class="cellrowborder" valign="top" width="42.01%" headers="mcps1.2.4.1.3 "><p id="p11303181216414"><a name="p11303181216414"></a><a name="p11303181216414"></a>Sets the UART transmission mode.</p>
</td>
</tr>
</tbody>
</table>

>![](../public_sys-resources/icon-note.gif) **NOTE**<br> 
>All functions provided in this document can be called only in kernel space.

## Usage Guidelines<a name="section12779050105412"></a>

### How to Use<a name="section1858116395510"></a>

The figure below illustrates how to use the APIs.

**Figure  3** Using UART driver APIs<a name="fig99673244388"></a>  
![](figures/using-uart-process.png "process-of-using-a-uart-device")

### Obtaining a UART Device Handle<a name="section124512065617"></a>

Before performing UART communication, call **UartOpen** to obtain a UART device handle. This function returns the pointer to the UART device handle with a specified port number.

DevHandle UartOpen\(uint32\_t port\);

**Table  2** Description of UartOpen

<a name="table14222165114310"></a>
<table><thead align="left"><tr id="row1022175133111"><th class="cellrowborder" valign="top" width="50%" id="mcps1.2.3.1.1"><p id="p13221551153117"><a name="p13221551153117"></a><a name="p13221551153117"></a><strong id="b538194163718"><a name="b538194163718"></a><a name="b538194163718"></a>Parameter</strong></p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.2.3.1.2"><p id="p122211251103111"><a name="p122211251103111"></a><a name="p122211251103111"></a><strong id="b20924204203714"><a name="b20924204203714"></a><a name="b20924204203714"></a>Description</strong></p>
</th>
</tr>
</thead>
<tbody><tr id="row6222451133114"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p92221518315"><a name="p92221518315"></a><a name="p92221518315"></a>port</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p1322217518318"><a name="p1322217518318"></a><a name="p1322217518318"></a>UART port number.</p>
</td>
</tr>
<tr id="row1122245153112"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p102221451123118"><a name="p102221451123118"></a><a name="p102221451123118"></a><strong id="b101754483378"><a name="b101754483378"></a><a name="b101754483378"></a>Return Value</strong></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p1122215143113"><a name="p1122215143113"></a><a name="p1122215143113"></a><strong id="b647184919374"><a name="b647184919374"></a><a name="b647184919374"></a>Description</strong></p>
</td>
</tr>
<tr id="row522275114317"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p422235114313"><a name="p422235114313"></a><a name="p422235114313"></a>NULL</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p5222351203112"><a name="p5222351203112"></a><a name="p5222351203112"></a>Failed to obtain the UART device handle.</p>
</td>
</tr>
<tr id="row1222212513311"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p5222125115316"><a name="p5222125115316"></a><a name="p5222125115316"></a>Device handle</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p192228515311"><a name="p192228515311"></a><a name="p192228515311"></a>UART device handle.</p>
</td>
</tr>
</tbody>
</table>

The following example shows how to obtain a UART device handle based on the assumption that the UART port number is **3**:

```
DevHandle handle = NULL;    /* The UART device handle */
uint32_t port = 3;                  /* UART port number */
handle = UartOpen(port);
if (handle == NULL) {
    HDF_LOGE("UartOpen: failed!\n");
    return;
}
```

### Setting the UART Baud Rate<a name="section86881004579"></a>

After obtaining the UART device handle, set the UART baud rate by calling the following function:

int32\_t UartSetBaud\(DevHandle handle, uint32\_t baudRate\);

**Table  3** Description of UartSetBaud

<a name="table539135313325"></a>
<table><thead align="left"><tr id="row15391205311323"><th class="cellrowborder" valign="top" width="50%" id="mcps1.2.3.1.1"><p id="p11390453103216"><a name="p11390453103216"></a><a name="p11390453103216"></a><strong id="b0704124143717"><a name="b0704124143717"></a><a name="b0704124143717"></a>Parameter</strong></p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.2.3.1.2"><p id="p839065316328"><a name="p839065316328"></a><a name="p839065316328"></a><strong id="b10127164520376"><a name="b10127164520376"></a><a name="b10127164520376"></a>Description</strong></p>
</th>
</tr>
</thead>
<tbody><tr id="row2039115373216"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p1639165310324"><a name="p1639165310324"></a><a name="p1639165310324"></a>handle</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p539115320328"><a name="p539115320328"></a><a name="p539115320328"></a>UART device handle.</p>
</td>
</tr>
<tr id="row163911753143214"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p13911653203215"><a name="p13911653203215"></a><a name="p13911653203215"></a>baudRate</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p163919537322"><a name="p163919537322"></a><a name="p163919537322"></a>Baud rate of the UART to set.</p>
</td>
</tr>
<tr id="row539155343218"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p1039185313321"><a name="p1039185313321"></a><a name="p1039185313321"></a><strong id="b1551834812373"><a name="b1551834812373"></a><a name="b1551834812373"></a>Return Value</strong></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p123911753143213"><a name="p123911753143213"></a><a name="p123911753143213"></a><strong id="b43667492373"><a name="b43667492373"></a><a name="b43667492373"></a>Description</strong></p>
</td>
</tr>
<tr id="row2391853153218"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p17391185310322"><a name="p17391185310322"></a><a name="p17391185310322"></a>0</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p14391653193210"><a name="p14391653193210"></a><a name="p14391653193210"></a>Succeeded in setting the UART baud rate.</p>
</td>
</tr>
<tr id="row23912053143211"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p7391165320321"><a name="p7391165320321"></a><a name="p7391165320321"></a>Negative value</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p639185318322"><a name="p639185318322"></a><a name="p639185318322"></a>Failed to set the UART baud rate.</p>
</td>
</tr>
</tbody>
</table>

The following example shows how to set the UART baud rate to **9600**:

```
int32_t ret;
/* Set the UART baud rate to 9600. */
ret = UartSetBaud(handle, 9600);
if (ret != 0) {
    HDF_LOGE("UartSetBaud: failed, ret %d\n", ret);
}
```

### Obtaining the UART Baud Rate<a name="section897032965712"></a>

After setting the UART baud rate, obtain the current baud rate by calling the following function:

int32\_t UartGetBaud\(DevHandle handle, uint32\_t \*baudRate\);

**Table  4** Description of UartGetBaud

<a name="table20393185311326"></a>
<table><thead align="left"><tr id="row19392653123215"><th class="cellrowborder" valign="top" width="50%" id="mcps1.2.3.1.1"><p id="p6392105315326"><a name="p6392105315326"></a><a name="p6392105315326"></a><strong id="b13706541173716"><a name="b13706541173716"></a><a name="b13706541173716"></a>Parameter</strong></p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.2.3.1.2"><p id="p53920531329"><a name="p53920531329"></a><a name="p53920531329"></a><strong id="b15128194510378"><a name="b15128194510378"></a><a name="b15128194510378"></a>Description</strong></p>
</th>
</tr>
</thead>
<tbody><tr id="row103921553103211"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p1539220536326"><a name="p1539220536326"></a><a name="p1539220536326"></a>handle</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p6392553203217"><a name="p6392553203217"></a><a name="p6392553203217"></a>UART device handle.</p>
</td>
</tr>
<tr id="row1539211532322"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p93921053123210"><a name="p93921053123210"></a><a name="p93921053123210"></a>baudRate</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p93926536328"><a name="p93926536328"></a><a name="p93926536328"></a>Pointer to the UART baud rate.</p>
</td>
</tr>
<tr id="row1239318531326"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p17392653123213"><a name="p17392653123213"></a><a name="p17392653123213"></a><strong id="b55191048113716"><a name="b55191048113716"></a><a name="b55191048113716"></a>Return Value</strong></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p1339365316327"><a name="p1339365316327"></a><a name="p1339365316327"></a><strong id="b193671249193713"><a name="b193671249193713"></a><a name="b193671249193713"></a>Description</strong></p>
</td>
</tr>
<tr id="row143939531328"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p2393953153213"><a name="p2393953153213"></a><a name="p2393953153213"></a>0</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p8393165383218"><a name="p8393165383218"></a><a name="p8393165383218"></a>Succeeded in obtaining the UART baud rate.</p>
</td>
</tr>
<tr id="row5393105363210"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p17393125363215"><a name="p17393125363215"></a><a name="p17393125363215"></a>Negative value</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p1539325393211"><a name="p1539325393211"></a><a name="p1539325393211"></a>Failed to obtain the UART baud rate.</p>
</td>
</tr>
</tbody>
</table>

The following example shows how to obtain the UART baud rate:

```
int32_t ret;
uint32_t baudRate;
/* Obtain the UART baud rate. */
ret = UartGetBaud(handle, &baudRate);
if (ret != 0) {
    HDF_LOGE("UartGetBaud: failed, ret %d\n", ret);
}
```

### Setting the UART Device Attributes<a name="section129141884588"></a>

Before performing UART communication, set the UART device attributes by calling the following function:

int32\_t UartSetAttribute\(DevHandle handle, struct UartAttribute \*attribute\);

**Table  5** Description of UartSetAttribute

<a name="table1453119335341"></a>
<table><thead align="left"><tr id="row3530433103416"><th class="cellrowborder" valign="top" width="49.980000000000004%" id="mcps1.2.3.1.1"><p id="p1853073310341"><a name="p1853073310341"></a><a name="p1853073310341"></a><strong id="b8706441133719"><a name="b8706441133719"></a><a name="b8706441133719"></a>Parameter</strong></p>
</th>
<th class="cellrowborder" valign="top" width="50.019999999999996%" id="mcps1.2.3.1.2"><p id="p553083393417"><a name="p553083393417"></a><a name="p553083393417"></a><strong id="b16129154519371"><a name="b16129154519371"></a><a name="b16129154519371"></a>Description</strong></p>
</th>
</tr>
</thead>
<tbody><tr id="row55303331347"><td class="cellrowborder" valign="top" width="49.980000000000004%" headers="mcps1.2.3.1.1 "><p id="p1530113313341"><a name="p1530113313341"></a><a name="p1530113313341"></a>handle</p>
</td>
<td class="cellrowborder" valign="top" width="50.019999999999996%" headers="mcps1.2.3.1.2 "><p id="p3530173313346"><a name="p3530173313346"></a><a name="p3530173313346"></a>UART device handle.</p>
</td>
</tr>
<tr id="row45309337342"><td class="cellrowborder" valign="top" width="49.980000000000004%" headers="mcps1.2.3.1.1 "><p id="p553083319348"><a name="p553083319348"></a><a name="p553083319348"></a>attribute</p>
</td>
<td class="cellrowborder" valign="top" width="50.019999999999996%" headers="mcps1.2.3.1.2 "><p id="p5530133314343"><a name="p5530133314343"></a><a name="p5530133314343"></a>Pointer to the UART device attributes to set.</p>
</td>
</tr>
<tr id="row12530833103415"><td class="cellrowborder" valign="top" width="49.980000000000004%" headers="mcps1.2.3.1.1 "><p id="p185309331345"><a name="p185309331345"></a><a name="p185309331345"></a><strong id="b18520248203717"><a name="b18520248203717"></a><a name="b18520248203717"></a>Return Value</strong></p>
</td>
<td class="cellrowborder" valign="top" width="50.019999999999996%" headers="mcps1.2.3.1.2 "><p id="p145309332344"><a name="p145309332344"></a><a name="p145309332344"></a><strong id="b5367174913370"><a name="b5367174913370"></a><a name="b5367174913370"></a>Description</strong></p>
</td>
</tr>
<tr id="row14530203310348"><td class="cellrowborder" valign="top" width="49.980000000000004%" headers="mcps1.2.3.1.1 "><p id="p1653014339343"><a name="p1653014339343"></a><a name="p1653014339343"></a>0</p>
</td>
<td class="cellrowborder" valign="top" width="50.019999999999996%" headers="mcps1.2.3.1.2 "><p id="p1453023323419"><a name="p1453023323419"></a><a name="p1453023323419"></a>Succeeded in setting the UART device attributes.</p>
</td>
</tr>
<tr id="row6531163373412"><td class="cellrowborder" valign="top" width="49.980000000000004%" headers="mcps1.2.3.1.1 "><p id="p16530123310345"><a name="p16530123310345"></a><a name="p16530123310345"></a>Negative value</p>
</td>
<td class="cellrowborder" valign="top" width="50.019999999999996%" headers="mcps1.2.3.1.2 "><p id="p1953118334347"><a name="p1953118334347"></a><a name="p1953118334347"></a>Failed to set the UART device attributes.</p>
</td>
</tr>
</tbody>
</table>

The following example shows how to set the UART device attributes:

```
int32_t ret;
struct UartAttribute attribute;
attribute.dataBits = UART_ATTR_DATABIT_7;   /* Set the number of data bits to 7. */
attribute.parity = UART_ATTR_PARITY_NONE;   /* Set the parity bit to no parity. */
attribute.stopBits = UART_ATTR_STOPBIT_1;   /* Set the stop bit to 1. */
attribute.rts = UART_ATTR_RTS_DIS;          /* Disable the RTS signal. */
attribute.cts = UART_ATTR_CTS_DIS;          /* Disable the CTS signal. */
attribute.fifoRxEn = UART_ATTR_RX_FIFO_EN;  /* Enable RX FIFO. */
attribute.fifoTxEn = UART_ATTR_TX_FIFO_EN;  /* Enable TX FIFO. */
/* Set the UART device attributes. */
ret = UartSetAttribute(handle, &attribute);
if (ret != 0) {
    HDF_LOGE("UartSetAttribute: failed, ret %d\n", ret);
}
```

### Obtaining UART Device Attributes<a name="section18689637165812"></a>

After setting the UART device attributes, obtain the current device attributes by calling the following function:

int32\_t UartGetAttribute\(DevHandle handle, struct UartAttribute \*attribute\);

**Table  6** Description of UartGetAttribute

<a name="table17532123316342"></a>
<table><thead align="left"><tr id="row18531193383420"><th class="cellrowborder" valign="top" width="50%" id="mcps1.2.3.1.1"><p id="p85311833143420"><a name="p85311833143420"></a><a name="p85311833143420"></a><strong id="b1770784123715"><a name="b1770784123715"></a><a name="b1770784123715"></a>Parameter</strong></p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.2.3.1.2"><p id="p17531103319348"><a name="p17531103319348"></a><a name="p17531103319348"></a><strong id="b0130114519373"><a name="b0130114519373"></a><a name="b0130114519373"></a>Description</strong></p>
</th>
</tr>
</thead>
<tbody><tr id="row35311533153413"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p453133333418"><a name="p453133333418"></a><a name="p453133333418"></a>handle</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p753193323420"><a name="p753193323420"></a><a name="p753193323420"></a>UART device handle.</p>
</td>
</tr>
<tr id="row1953103315344"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p35315333346"><a name="p35315333346"></a><a name="p35315333346"></a>attribute</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p14531633133416"><a name="p14531633133416"></a><a name="p14531633133416"></a>Pointer to the UART device attributes.</p>
</td>
</tr>
<tr id="row45321433143415"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p653273363417"><a name="p653273363417"></a><a name="p653273363417"></a><strong id="b15211548193719"><a name="b15211548193719"></a><a name="b15211548193719"></a>Return Value</strong></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p1653203312347"><a name="p1653203312347"></a><a name="p1653203312347"></a><strong id="b836815498379"><a name="b836815498379"></a><a name="b836815498379"></a>Description</strong></p>
</td>
</tr>
<tr id="row175320339342"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p10532163383412"><a name="p10532163383412"></a><a name="p10532163383412"></a>0</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p5532143319341"><a name="p5532143319341"></a><a name="p5532143319341"></a>Succeeded in obtaining the UART device attributes.</p>
</td>
</tr>
<tr id="row125327337340"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p19532153317345"><a name="p19532153317345"></a><a name="p19532153317345"></a>Negative value</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p175321933163410"><a name="p175321933163410"></a><a name="p175321933163410"></a>Failed to obtain the UART device attributes.</p>
</td>
</tr>
</tbody>
</table>

The following example shows how to obtain the UART device attributes:

```
int32_t ret;
struct UartAttribute attribute;
/* Obtain the UART attributes. */
ret = UartGetAttribute(handle, &attribute);
if (ret != 0) {
    HDF_LOGE("UartGetAttribute: failed, ret %d\n", ret);
}
```

### Setting the UART Transmission Mode<a name="section72713435918"></a>

Before performing UART communication, set the UART transmission mode by calling the following function:

int32\_t UartSetTransMode\(DevHandle handle, enum UartTransMode mode\);

**Table  7** Description of UartSetTransMode

<a name="table131892266313"></a>
<table><thead align="left"><tr id="row018922615318"><th class="cellrowborder" valign="top" width="49.980000000000004%" id="mcps1.2.3.1.1"><p id="p131891826835"><a name="p131891826835"></a><a name="p131891826835"></a><strong id="b197086411379"><a name="b197086411379"></a><a name="b197086411379"></a>Parameter</strong></p>
</th>
<th class="cellrowborder" valign="top" width="50.019999999999996%" id="mcps1.2.3.1.2"><p id="p101894269314"><a name="p101894269314"></a><a name="p101894269314"></a><strong id="b813014510375"><a name="b813014510375"></a><a name="b813014510375"></a>Description</strong></p>
</th>
</tr>
</thead>
<tbody><tr id="row11893261734"><td class="cellrowborder" valign="top" width="49.980000000000004%" headers="mcps1.2.3.1.1 "><p id="p81897261333"><a name="p81897261333"></a><a name="p81897261333"></a>handle</p>
</td>
<td class="cellrowborder" valign="top" width="50.019999999999996%" headers="mcps1.2.3.1.2 "><p id="p5190142618310"><a name="p5190142618310"></a><a name="p5190142618310"></a>UART device handle.</p>
</td>
</tr>
<tr id="row1119082615317"><td class="cellrowborder" valign="top" width="49.980000000000004%" headers="mcps1.2.3.1.1 "><p id="p1519012261314"><a name="p1519012261314"></a><a name="p1519012261314"></a>mode</p>
</td>
<td class="cellrowborder" valign="top" width="50.019999999999996%" headers="mcps1.2.3.1.2 "><p id="p121901026632"><a name="p121901026632"></a><a name="p121901026632"></a>UART transmission mode to set.</p>
</td>
</tr>
<tr id="row19190152612317"><td class="cellrowborder" valign="top" width="49.980000000000004%" headers="mcps1.2.3.1.1 "><p id="p131900266316"><a name="p131900266316"></a><a name="p131900266316"></a><strong id="b1352194823717"><a name="b1352194823717"></a><a name="b1352194823717"></a>Return Value</strong></p>
</td>
<td class="cellrowborder" valign="top" width="50.019999999999996%" headers="mcps1.2.3.1.2 "><p id="p1519022616315"><a name="p1519022616315"></a><a name="p1519022616315"></a><strong id="b1836924917371"><a name="b1836924917371"></a><a name="b1836924917371"></a>Description</strong></p>
</td>
</tr>
<tr id="row919016261932"><td class="cellrowborder" valign="top" width="49.980000000000004%" headers="mcps1.2.3.1.1 "><p id="p10190526334"><a name="p10190526334"></a><a name="p10190526334"></a>0</p>
</td>
<td class="cellrowborder" valign="top" width="50.019999999999996%" headers="mcps1.2.3.1.2 "><p id="p1219012264318"><a name="p1219012264318"></a><a name="p1219012264318"></a>Succeeded in setting the UART transmission mode.</p>
</td>
</tr>
<tr id="row1219017262313"><td class="cellrowborder" valign="top" width="49.980000000000004%" headers="mcps1.2.3.1.1 "><p id="p15190162616316"><a name="p15190162616316"></a><a name="p15190162616316"></a>Negative value</p>
</td>
<td class="cellrowborder" valign="top" width="50.019999999999996%" headers="mcps1.2.3.1.2 "><p id="p131906262311"><a name="p131906262311"></a><a name="p131906262311"></a>Failed to set the UART transmission mode.</p>
</td>
</tr>
</tbody>
</table>

The following example shows how to set the transmission mode to **UART\_MODE\_RD\_BLOCK**:

```
int32_t ret;
/* Set the UART transmission mode. */
ret = UartSetTransMode(handle, UART_MODE_RD_BLOCK);
if (ret != 0) {
    HDF_LOGE("UartSetTransMode: failed, ret %d\n", ret);
}
```

### Writing Data of a Specified Length into a UART Device<a name="section128001736155919"></a>

To write data into a UART device, call the following function:

int32\_t UartWrite\(DevHandle handle, uint8\_t \*data, uint32\_t size\);

**Table  8** Description of UartWrite

<a name="table27825111368"></a>
<table><thead align="left"><tr id="row1578171123619"><th class="cellrowborder" valign="top" width="50%" id="mcps1.2.3.1.1"><p id="p078112115360"><a name="p078112115360"></a><a name="p078112115360"></a><strong id="b14708841203711"><a name="b14708841203711"></a><a name="b14708841203711"></a>Parameter</strong></p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.2.3.1.2"><p id="p37811711163612"><a name="p37811711163612"></a><a name="p37811711163612"></a><strong id="b2131174553712"><a name="b2131174553712"></a><a name="b2131174553712"></a>Description</strong></p>
</th>
</tr>
</thead>
<tbody><tr id="row1878291143611"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p07818112360"><a name="p07818112360"></a><a name="p07818112360"></a>handle</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p178281113369"><a name="p178281113369"></a><a name="p178281113369"></a>UART device handle.</p>
</td>
</tr>
<tr id="row7782811123614"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p8782911173610"><a name="p8782911173610"></a><a name="p8782911173610"></a>data</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p17782171120366"><a name="p17782171120366"></a><a name="p17782171120366"></a>Pointer to the data to write.</p>
</td>
</tr>
<tr id="row1578251112367"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p3782911183612"><a name="p3782911183612"></a><a name="p3782911183612"></a>size</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p17782161110366"><a name="p17782161110366"></a><a name="p17782161110366"></a>Length of the data to write.</p>
</td>
</tr>
<tr id="row1378281113363"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p87821411183616"><a name="p87821411183616"></a><a name="p87821411183616"></a><strong id="b2052274863718"><a name="b2052274863718"></a><a name="b2052274863718"></a>Return Value</strong></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p13782111116361"><a name="p13782111116361"></a><a name="p13782111116361"></a><strong id="b73704492377"><a name="b73704492377"></a><a name="b73704492377"></a>Description</strong></p>
</td>
</tr>
<tr id="row47822112365"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p107821011103613"><a name="p107821011103613"></a><a name="p107821011103613"></a>0</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p11782191103610"><a name="p11782191103610"></a><a name="p11782191103610"></a>Succeeded in writing data into the UART device.</p>
</td>
</tr>
<tr id="row11782911113611"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p1578221111367"><a name="p1578221111367"></a><a name="p1578221111367"></a>Negative value</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p9782151110366"><a name="p9782151110366"></a><a name="p9782151110366"></a>Failed to write data into the UART device.</p>
</td>
</tr>
</tbody>
</table>

The following example shows how to write data of a specified length into the UART device:

```
int32_t ret;
uint8_t wbuff[5] = {1, 2, 3, 4, 5};
/* Write 5-byte data into the UART device. */
ret = UartWrite(handle, wbuff, 5);
if (ret != 0) {
    HDF_LOGE("UartWrite: failed, ret %d\n", ret);
}
```

### Reading Data of a Specified Length from a UART Device<a name="section92851601604"></a>

To write data into a UART device, call the following function:

int32\_t UartRead\(DevHandle handle, uint8\_t \*data, uint32\_t size\);

**Table  9** Description of UartRead

<a name="table162341717123713"></a>
<table><thead align="left"><tr id="row023313171377"><th class="cellrowborder" valign="top" width="50%" id="mcps1.2.3.1.1"><p id="p1123331710376"><a name="p1123331710376"></a><a name="p1123331710376"></a><strong id="b970911411374"><a name="b970911411374"></a><a name="b970911411374"></a>Parameter</strong></p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.2.3.1.2"><p id="p523321783715"><a name="p523321783715"></a><a name="p523321783715"></a><strong id="b16132114553713"><a name="b16132114553713"></a><a name="b16132114553713"></a>Description</strong></p>
</th>
</tr>
</thead>
<tbody><tr id="row6234417133712"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p7233121716379"><a name="p7233121716379"></a><a name="p7233121716379"></a>handle</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p17234101753712"><a name="p17234101753712"></a><a name="p17234101753712"></a>UART device handle.</p>
</td>
</tr>
<tr id="row18234151718372"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p16234191783711"><a name="p16234191783711"></a><a name="p16234191783711"></a>data</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p923417175378"><a name="p923417175378"></a><a name="p923417175378"></a>Pointer to the buffer for receiving the data.</p>
</td>
</tr>
<tr id="row82341017193711"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p13234917103717"><a name="p13234917103717"></a><a name="p13234917103717"></a>size</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p182341817153717"><a name="p182341817153717"></a><a name="p182341817153717"></a>Length of the data to read.</p>
</td>
</tr>
<tr id="row102341617123717"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p172341617163712"><a name="p172341617163712"></a><a name="p172341617163712"></a><strong id="b1352319486376"><a name="b1352319486376"></a><a name="b1352319486376"></a>Return Value</strong></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p1623431763718"><a name="p1623431763718"></a><a name="p1623431763718"></a><strong id="b73711949113718"><a name="b73711949113718"></a><a name="b73711949113718"></a>Description</strong></p>
</td>
</tr>
<tr id="row4234151719372"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p3234131716375"><a name="p3234131716375"></a><a name="p3234131716375"></a>Non-negative value</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p7234171783718"><a name="p7234171783718"></a><a name="p7234171783718"></a>Length of the data read from the UART device.</p>
</td>
</tr>
<tr id="row112340173378"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p1423431743714"><a name="p1423431743714"></a><a name="p1423431743714"></a>Negative value</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p32349178378"><a name="p32349178378"></a><a name="p32349178378"></a>Failed to read data from the UART device.</p>
</td>
</tr>
</tbody>
</table>

The following example shows how to read data of a specified length from the UART device:

```
int32_t ret;
uint8_t rbuff[5] = {0};
/* Read 5-byte data from the UART device. */
ret = UartRead(handle, rbuff, 5);
if (ret < 0) {
    HDF_LOGE("UartRead: failed, ret %d\n", ret);
}
```

>![](../public_sys-resources/icon-caution.gif) **CAUTION:** 
>Data is successfully read from the UART device if a non-negative value is returned. If the return value is **0**, no valid data can be read from the UART device. If the return value is greater than **0**, the return value is the length of the data actually read from the UART device. The length is less than or equal to the value of **size** and does not exceed the maximum length of data to read at a time specified by the UART controller in use.

### Destroying the UART Device Handle<a name="section1477410521406"></a>

After the UART communication, destroy the UART device handle by calling the following function:

void UartClose\(DevHandle handle\);

This function will release the resources previously obtained.

**Table  10** Description of UartClose

<a name="table03348317351"></a>
<table><thead align="left"><tr id="row15334837351"><th class="cellrowborder" valign="top" width="50%" id="mcps1.2.3.1.1"><p id="p933411316354"><a name="p933411316354"></a><a name="p933411316354"></a><strong id="b1710184115375"><a name="b1710184115375"></a><a name="b1710184115375"></a>Parameter</strong></p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.2.3.1.2"><p id="p16334103143517"><a name="p16334103143517"></a><a name="p16334103143517"></a><strong id="b2013254513370"><a name="b2013254513370"></a><a name="b2013254513370"></a>Description</strong></p>
</th>
</tr>
</thead>
<tbody><tr id="row733483103513"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p7334530358"><a name="p7334530358"></a><a name="p7334530358"></a>handle</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p133341331356"><a name="p133341331356"></a><a name="p133341331356"></a>UART device handle.</p>
</td>
</tr>
</tbody>
</table>

The following example shows how to destroy the UART device handle:

```
UartClose(handle); /* Destroy the UART device handle. */
```

## Usage Example<a name="section35404241311"></a>

The following is a usage example of a UART device, including how to obtain the UART device handle, set the baud rate, device attributes, and transmission mode, read data from or write data into the UART device, and then destroy the UART device handle.

```
#include "hdf_log.h"
#include "uart_if.h"

void UartTestSample(void)
{
    int32_t ret;
    uint32_t port;  
    DevHandle handle = NULL;
    uint8_t wbuff[5] = { 1, 2, 3, 4, 5 };
    uint8_t rbuff[5] = { 0 };
    struct UartAttribute attribute;
    attribute.dataBits = UART_ATTR_DATABIT_7;   /* Set the number of data bits to 7. */
    attribute.parity = UART_ATTR_PARITY_NONE;   /* Set the parity bit to no parity. */
    attribute.stopBits = UART_ATTR_STOPBIT_1;   /* Set the stop bit to 1. */
    attribute.rts = UART_ATTR_RTS_DIS;          /* Disable the RTS signal. */
    attribute.cts = UART_ATTR_CTS_DIS;          /* Disable the CTS signal. */
    attribute.fifoRxEn = UART_ATTR_RX_FIFO_EN;  /* Enable RX FIFO. */
    attribute.fifoTxEn = UART_ATTR_TX_FIFO_EN;  /* Enable TX FIFO. */
    /* Set the UART port number actually used. */
    port = 1; 
    /* Obtain the UART device handle. */
    handle = UartOpen(port);
    if (handle == NULL) {
        HDF_LOGE("UartOpen: failed!\n");
        return;
    }
    /* Set the UART baud rate to 9600. */
    ret = UartSetBaud(handle, 9600);
    if (ret != 0) {
        HDF_LOGE("UartSetBaud: failed, ret %d\n", ret);
        goto _ERR;
    }
    /* Set the UART device attributes. */
    ret = UartSetAttribute(handle, &attribute);
    if (ret != 0) {
        HDF_LOGE("UartSetAttribute: failed, ret %d\n", ret);
        goto _ERR;
    }
    /* Set the UART transmission mode to non-blocking mode. */
    ret = UartSetTransMode(handle, UART_MODE_RD_NONBLOCK);
    if (ret != 0) {
        HDF_LOGE("UartSetTransMode: failed, ret %d\n", ret);
        goto _ERR;
    }
    /* Write 5-byte data into the UART device. */
    ret = UartWrite(handle, wbuff, 5);
    if (ret != 0) {
        HDF_LOGE("UartWrite: failed, ret %d\n", ret);
        goto _ERR;
    }
    /* Read 5-byte data from the UART device. */
    ret = UartRead(handle, rbuff, 5);
    if (ret < 0) {
        HDF_LOGE("UartRead: failed, ret %d\n", ret);
        goto _ERR;
    }
_ERR:
    /* Destroy the UART device handle. */
    UartClose(handle); 
}
```