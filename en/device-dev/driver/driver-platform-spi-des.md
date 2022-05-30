# SPI<a name="EN-US_TOPIC_0000001206171293"></a>

## Overview<a name="section193356154511"></a>

Serial Peripheral Interface \(SPI\) is a serial bus specification used for high-speed, full-duplex, and synchronous communication.
SPI is developed by Motorola. It is commonly used for communication with flash memory, real-time clocks, sensors, and analog-to-digital \(A/D\) converters.
SPI works in controller/device mode. Generally, there is one SPI controller that controls one or more SPI devices. They are connected via four wires:
-   SCLK: clock signals output from the SPI controller
-   MOSI: data output from the SPI controller and input into an SPI device
-   MISO: data output from an SPI device and input into the SPI controller
-   CS: signals enabled by an SPI device and controlled by the SPI controller


[Figure 1](#fig89085710359)  shows the connection between one SPI controller and two SPI devices \(device A and device B\). In this figure, device A and device B share three pins \(SCLK, MISO, and MOSI\) of the controller. CS0 of device A and CS1 of device B are connected to CS0 and CS1 of the controller, respectively.

**Figure  1** SPI controller/device connection<a name="fig89085710359"></a>  
![](figures/spi-controller-device-connection.png "spi-controller-device-connection")

SPI communication is usually initiated by the SPI controller and is operated as follows:

1.  A single SPI device is selected at a time via the CS to communicate with the SPI controller.
2.  Clock signals are provided for the selected SPI device via the SCLK.
3.  The SPI controller sends data to SPI devices via the MOSI, and receives data from SPI devices via the MISO.

-   SPI can work in one of the following four modes, equivalent to one of the four possible states for Clock Polarity \(CPOL\) and Clock Phase \(CPHA\):
    -   If both CPOL and CPHA are **0**, the clock signal level is low in the idle state and data is sampled on the first clock edge.
    -   If CPOL is **0** and CPHA is **1**, the clock signal level is low in the idle state and data is sampled on the second clock edge.
    -   If CPOL is **1** and CPHA is **0**, the clock signal level is high in the idle state and data is sampled on the first clock edge.
    -   If both CPOL and CPHA are **1**, the clock signal level is high in the idle state and data is sampled on the second clock edge.


-   SPI defines a set of common functions for operating an SPI device, including those for:
    -   Obtaining and releasing the handle of an SPI device.
    -   Reading or writing data of a specified length from or into an SPI device.
    -   Customizing data reading or writing via **SpiMsg**.
    -   Obtaining and setting SPI device configuration parameters.


>![](../public_sys-resources/icon-note.gif) **NOTE**<br>
>Currently, these functions are only applicable in the communication initiated by the SPI controller.

## Available APIs<a name="section1325964832615"></a>

**Table  1** APIs for the SPI driver

<a name="table1731550155318"></a>
<table><thead align="left"><tr id="row4419501537"><th class="cellrowborder" align="left" valign="top" width="20.857914208579142%" id="mcps1.2.4.1.1"><p id="p641050105320"><a name="p641050105320"></a><a name="p641050105320"></a><strong id="b17365506414"><a name="b17365506414"></a><a name="b17365506414"></a>Capability</strong></p>
</th>
<th class="cellrowborder" align="left" valign="top" width="23.36766323367663%" id="mcps1.2.4.1.2"><p id="p54150165315"><a name="p54150165315"></a><a name="p54150165315"></a><strong id="b191701618154210"><a name="b191701618154210"></a><a name="b191701618154210"></a>Function</strong></p>
</th>
<th class="cellrowborder" align="left" valign="top" width="55.77442255774422%" id="mcps1.2.4.1.3"><p id="p941150145313"><a name="p941150145313"></a><a name="p941150145313"></a><strong id="b64281840104214"><a name="b64281840104214"></a><a name="b64281840104214"></a>Description</strong></p>
</th>
</tr>
</thead>
<tbody><tr id="row1651292212306"><td class="cellrowborder" rowspan="2" valign="top" width="20.857914208579142%" headers="mcps1.2.4.1.1 "><p id="p1387414255305"><a name="p1387414255305"></a><a name="p1387414255305"></a>SPI device handle obtaining/releasing</p>
</td>
<td class="cellrowborder" valign="top" width="23.36766323367663%" headers="mcps1.2.4.1.2 "><p id="p8874825143014"><a name="p8874825143014"></a><a name="p8874825143014"></a>SpiOpen</p>
</td>
<td class="cellrowborder" valign="top" width="55.77442255774422%" headers="mcps1.2.4.1.3 "><p id="p1087432513307"><a name="p1087432513307"></a><a name="p1087432513307"></a>Obtains an SPI device handle.</p>
</td>
</tr>
<tr id="row1429083612305"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p1956614106311"><a name="p1956614106311"></a><a name="p1956614106311"></a>SpiClose</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p829111362306"><a name="p829111362306"></a><a name="p829111362306"></a>Releases an SPI device handle.</p>
</td>
</tr>
<tr id="row34145016535"><td class="cellrowborder" rowspan="3" valign="top" width="20.857914208579142%" headers="mcps1.2.4.1.1 "><p id="p229610227124"><a name="p229610227124"></a><a name="p229610227124"></a>SPI reading/writing</p>
</td>
<td class="cellrowborder" valign="top" width="23.36766323367663%" headers="mcps1.2.4.1.2 "><p id="p19389143041518"><a name="p19389143041518"></a><a name="p19389143041518"></a>SpiRead</p>
</td>
<td class="cellrowborder" valign="top" width="55.77442255774422%" headers="mcps1.2.4.1.3 "><p id="p8738101941716"><a name="p8738101941716"></a><a name="p8738101941716"></a>Reads data of a specified length from an SPI device.</p>
</td>
</tr>
<tr id="row5632152611414"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p143890309153"><a name="p143890309153"></a><a name="p143890309153"></a>SpiWrite</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p573815197171"><a name="p573815197171"></a><a name="p573815197171"></a>Writes data of a specified length into an SPI device.</p>
</td>
</tr>
<tr id="row1766145611414"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p183904373018"><a name="p183904373018"></a><a name="p183904373018"></a>SpiTransfer</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p1639011313303"><a name="p1639011313303"></a><a name="p1639011313303"></a>Transfers SPI data.</p>
</td>
</tr>
<tr id="row1020919129159"><td class="cellrowborder" rowspan="2" valign="top" width="20.857914208579142%" headers="mcps1.2.4.1.1 "><p id="p82092126154"><a name="p82092126154"></a><a name="p82092126154"></a>SPI device configuration</p>
<p id="p6794153701111"><a name="p6794153701111"></a><a name="p6794153701111"></a></p>
</td>
<td class="cellrowborder" valign="top" width="23.36766323367663%" headers="mcps1.2.4.1.2 "><p id="p1739013012154"><a name="p1739013012154"></a><a name="p1739013012154"></a>SpiSetCfg</p>
</td>
<td class="cellrowborder" valign="top" width="55.77442255774422%" headers="mcps1.2.4.1.3 "><p id="p073910197173"><a name="p073910197173"></a><a name="p073910197173"></a>Sets configuration parameters for an SPI device.</p>
</td>
</tr>
<tr id="row379443710118"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p4333154919111"><a name="p4333154919111"></a><a name="p4333154919111"></a>SpiGetCfg</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p11333649171117"><a name="p11333649171117"></a><a name="p11333649171117"></a>Obtains configuration parameters of an SPI device.</p>
</td>
</tr>
</tbody>
</table>

>![](../public_sys-resources/icon-note.gif) **NOTE:** 
>All functions provided in this document can be called only in kernel space.

## Usage Guidelines<a name="section71363452477"></a>

### How to Use<a name="section32846814820"></a>

The figure below illustrates how to use the APIs.

**Figure  2** Using SPI driver APIs<a name="fig1586912310348"></a>  
![](figures/using-spi-process.png "process-of-using-an-spi-device")

### Obtaining an SPI Device Handle<a name="section1927265711481"></a>

Before performing SPI communication, obtain an SPI device handle by calling **SpiOpen**. This function returns an SPI device handle with a specified bus number and CS number.

DevHandle SpiOpen\(const struct SpiDevInfo \*info\);

**Table  2** Description of SpiOpen

<a name="table7603619123820"></a>
<table><tbody><tr id="row1060351914386"><td class="cellrowborder" valign="top" width="50%"><p id="p14603181917382"><a name="p14603181917382"></a><a name="p14603181917382"></a><strong id="b139290298482"><a name="b139290298482"></a><a name="b139290298482"></a>Parameter</strong></p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p id="p36031519183819"><a name="p36031519183819"></a><a name="p36031519183819"></a><strong id="b17557183010484"><a name="b17557183010484"></a><a name="b17557183010484"></a>Description</strong></p>
</td>
</tr>
<tr id="row1960431983813"><td class="cellrowborder" valign="top" width="50%"><p id="p3604719123817"><a name="p3604719123817"></a><a name="p3604719123817"></a>info</p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p id="p1560441923818"><a name="p1560441923818"></a><a name="p1560441923818"></a>Pointer to the SPI device descriptor.</p>
</td>
</tr>
<tr id="row380484160"><td class="cellrowborder" valign="top" width="50%"><p id="p460381915385"><a name="p460381915385"></a><a name="p460381915385"></a><strong id="b1431414320486"><a name="b1431414320486"></a><a name="b1431414320486"></a>Return Value</strong></p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p id="p96031619153812"><a name="p96031619153812"></a><a name="p96031619153812"></a><strong id="b164533311485"><a name="b164533311485"></a><a name="b164533311485"></a>Description</strong></p>
</td>
</tr>
<tr id="row5793818161"><td class="cellrowborder" valign="top" width="50%"><p id="p1060418195389"><a name="p1060418195389"></a><a name="p1060418195389"></a>NULL</p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p id="p760471912388"><a name="p760471912388"></a><a name="p760471912388"></a>Failed to obtain an SPI device handle.</p>
</td>
</tr>
<tr id="row187914871618"><td class="cellrowborder" valign="top" width="50%"><p id="p5604719133811"><a name="p5604719133811"></a><a name="p5604719133811"></a>Device handle</p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p id="p3604181933818"><a name="p3604181933818"></a><a name="p3604181933818"></a>Returns the pointer to the SPI device handle.</p>
</td>
</tr>
</tbody>
</table>

The following example shows how to obtain an SPI device handle based on the assumption that both the bus number and CS number of the SPI device are **0**.

```
struct SpiDevInfo spiDevinfo;       /* SPI device descriptor */
DevHandle spiHandle = NULL; /* SPI device handle */
spiDevinfo.busNum = 0;              /* SPI device bus number */
spiDevinfo.csNum = 0;               /* SPI device CS number */

/* Obtain an SPI device handle. */
spiHandle = SpiOpen(&spiDevinfo);
if (spiHandle == NULL) {
    HDF_LOGE("SpiOpen: failed\n");
    return;
}
```

### Obtaining SPI Device Configuration Parameters<a name="section541133418493"></a>

After obtaining the SPI device handle, obtain the SPI device configuration parameters by calling the following function:

int32\_t SpiGetCfg\(DevHandle handle, struct SpiCfg \*cfg\);

**Table  3** Description of SpiGetCfg

<a name="table14209152141313"></a>
<table><tbody><tr id="row1420918529133"><td class="cellrowborder" valign="top" width="50%"><p id="p42091852141314"><a name="p42091852141314"></a><a name="p42091852141314"></a><strong id="b6279123012486"><a name="b6279123012486"></a><a name="b6279123012486"></a>Parameter</strong></p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p id="p202099523137"><a name="p202099523137"></a><a name="p202099523137"></a><strong id="b18243194818"><a name="b18243194818"></a><a name="b18243194818"></a>Description</strong></p>
</td>
</tr>
<tr id="row142091352171310"><td class="cellrowborder" valign="top" width="50%"><p id="p1520915529131"><a name="p1520915529131"></a><a name="p1520915529131"></a>handle</p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p id="p720995291310"><a name="p720995291310"></a><a name="p720995291310"></a>SPI device handle.</p>
</td>
</tr>
<tr id="row6209152161314"><td class="cellrowborder" valign="top" width="50%"><p id="p720916522139"><a name="p720916522139"></a><a name="p720916522139"></a>cfg</p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p id="p172091452131319"><a name="p172091452131319"></a><a name="p172091452131319"></a>Pointer to SPI device configuration parameters.</p>
</td>
</tr>
<tr id="row12092522139"><td class="cellrowborder" valign="top" width="50%"><p id="p18209125211134"><a name="p18209125211134"></a><a name="p18209125211134"></a><strong id="b16646173219483"><a name="b16646173219483"></a><a name="b16646173219483"></a>Return Value</strong></p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p id="p420975231318"><a name="p420975231318"></a><a name="p420975231318"></a><strong id="b184316334486"><a name="b184316334486"></a><a name="b184316334486"></a>Description</strong></p>
</td>
</tr>
<tr id="row8209155251310"><td class="cellrowborder" valign="top" width="50%"><p id="p13210145291312"><a name="p13210145291312"></a><a name="p13210145291312"></a>0</p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p id="p152101952141315"><a name="p152101952141315"></a><a name="p152101952141315"></a>Succeeded in obtaining SPI device configuration parameters.</p>
</td>
</tr>
<tr id="row102101452121320"><td class="cellrowborder" valign="top" width="50%"><p id="p10210175219134"><a name="p10210175219134"></a><a name="p10210175219134"></a>Negative value</p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p id="p72101252101312"><a name="p72101252101312"></a><a name="p72101252101312"></a>Failed to obtain SPI device configuration parameters.</p>
</td>
</tr>
</tbody>
</table>

```
int32_t ret;
struct SpiCfg cfg = {0};                /* SPI configuration information */
ret = SpiGetCfg(spiHandle, &cfg);       /* Obtain SPI device configuration parameters. */
if (ret != 0) {
    HDF_LOGE("SpiGetCfg: failed, ret %d\n", ret);
}
```

### Setting SPI Device Configuration Parameters<a name="section7870106145010"></a>

After obtaining the SPI device handle, set SPI device configuration parameters by calling the following function:

int32\_t SpiSetCfg\(DevHandle handle, struct SpiCfg \*cfg\);

**Table  4** Description of SpiSetCfg

<a name="table219052945210"></a>
<table><tbody><tr id="row14191192918522"><td class="cellrowborder" valign="top" width="50%"><p id="p17424155016529"><a name="p17424155016529"></a><a name="p17424155016529"></a><strong id="b11281163011480"><a name="b11281163011480"></a><a name="b11281163011480"></a>Parameter</strong></p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p id="p942512508520"><a name="p942512508520"></a><a name="p942512508520"></a><strong id="b1330312487"><a name="b1330312487"></a><a name="b1330312487"></a>Description</strong></p>
</td>
</tr>
<tr id="row219152915524"><td class="cellrowborder" valign="top" width="50%"><p id="p2191122985218"><a name="p2191122985218"></a><a name="p2191122985218"></a>handle</p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p id="p1519162913524"><a name="p1519162913524"></a><a name="p1519162913524"></a>SPI device handle.</p>
</td>
</tr>
<tr id="row1719110297526"><td class="cellrowborder" valign="top" width="50%"><p id="p181911292523"><a name="p181911292523"></a><a name="p181911292523"></a>cfg</p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p id="p91911729155216"><a name="p91911729155216"></a><a name="p91911729155216"></a>Pointer to SPI device configuration parameters.</p>
</td>
</tr>
<tr id="row036524131716"><td class="cellrowborder" valign="top" width="50%"><p id="p6425165035214"><a name="p6425165035214"></a><a name="p6425165035214"></a><strong id="b96476326489"><a name="b96476326489"></a><a name="b96476326489"></a>Return Value</strong></p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p id="p18425650165215"><a name="p18425650165215"></a><a name="p18425650165215"></a><strong id="b17432193311481"><a name="b17432193311481"></a><a name="b17432193311481"></a>Description</strong></p>
</td>
</tr>
<tr id="row43653411178"><td class="cellrowborder" valign="top" width="50%"><p id="p1319132918520"><a name="p1319132918520"></a><a name="p1319132918520"></a>0</p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p id="p1719117292522"><a name="p1719117292522"></a><a name="p1719117292522"></a>Succeeded in setting SPI device configuration parameters.</p>
</td>
</tr>
<tr id="row536594171715"><td class="cellrowborder" valign="top" width="50%"><p id="p719119296522"><a name="p719119296522"></a><a name="p719119296522"></a>Negative value</p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p id="p20191192925212"><a name="p20191192925212"></a><a name="p20191192925212"></a>Failed to set SPI device configuration parameters.</p>
</td>
</tr>
</tbody>
</table>

```
int32_t ret;
struct SpiCfg cfg = {0};                     /* SPI configuration information */
cfg.mode = SPI_MODE_LOOP;                    /* Communication in loopback mode */
cfg.transferMode = PAL_SPI_POLLING_TRANSFER; /* Communication in polling mode */
cfg.maxSpeedHz = 115200;                     /* Maximum transmission frequency */
cfg.bitsPerWord = 8;                         /* The width of per word to be read or written is 8 bits. */
ret = SpiSetCfg(spiHandle, &cfg);            /* Set SPI device configuration parameters. */
if (ret != 0) {
    HDF_LOGE("SpiSetCfg: failed, ret %d\n", ret);
}
```

### Performing SPI Communication<a name="section13324155195013"></a>

-   Writing data of a specific length into an SPI device

To write data into an SPI device only once, call the following function:

int32\_t SpiWrite\(DevHandle handle, uint8\_t \*buf, uint32\_t len\);

**Table  5** Description of SpiWrite

<a name="table1018490043"></a>
<table><tbody><tr id="row31848013417"><td class="cellrowborder" valign="top" width="50%"><p id="p1415816132411"><a name="p1415816132411"></a><a name="p1415816132411"></a><strong id="b42810303484"><a name="b42810303484"></a><a name="b42810303484"></a>Parameter</strong></p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p id="p11158111316410"><a name="p11158111316410"></a><a name="p11158111316410"></a><strong id="b03103112484"><a name="b03103112484"></a><a name="b03103112484"></a>Description</strong></p>
</td>
</tr>
<tr id="row10184701945"><td class="cellrowborder" valign="top" width="50%"><p id="p104891871157"><a name="p104891871157"></a><a name="p104891871157"></a>handle</p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p id="p204891671156"><a name="p204891671156"></a><a name="p204891671156"></a>SPI device handle.</p>
</td>
</tr>
<tr id="row928111518418"><td class="cellrowborder" valign="top" width="50%"><p id="p4282955412"><a name="p4282955412"></a><a name="p4282955412"></a>buf</p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p id="p7282752412"><a name="p7282752412"></a><a name="p7282752412"></a>Pointer to the data to write.</p>
</td>
</tr>
<tr id="row149041113651"><td class="cellrowborder" valign="top" width="50%"><p id="p139051213357"><a name="p139051213357"></a><a name="p139051213357"></a>len</p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p id="p16905313854"><a name="p16905313854"></a><a name="p16905313854"></a>Length of the data to write.</p>
</td>
</tr>
<tr id="row1148818622017"><td class="cellrowborder" valign="top" width="50%"><p id="p8158313248"><a name="p8158313248"></a><a name="p8158313248"></a><strong id="b9649732154818"><a name="b9649732154818"></a><a name="b9649732154818"></a>Return Value</strong></p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p id="p161591413741"><a name="p161591413741"></a><a name="p161591413741"></a><strong id="b12433113344813"><a name="b12433113344813"></a><a name="b12433113344813"></a>Description</strong></p>
</td>
</tr>
<tr id="row14488762202"><td class="cellrowborder" valign="top" width="50%"><p id="p103191916578"><a name="p103191916578"></a><a name="p103191916578"></a>0</p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p id="p1231981611712"><a name="p1231981611712"></a><a name="p1231981611712"></a>Succeeded in writing data into an SPI device.</p>
</td>
</tr>
<tr id="row164881464201"><td class="cellrowborder" valign="top" width="50%"><p id="p531916166716"><a name="p531916166716"></a><a name="p531916166716"></a>Negative value</p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p id="p93191161174"><a name="p93191161174"></a><a name="p93191161174"></a>Failed to write data into an SPI device.</p>
</td>
</tr>
</tbody>
</table>

```
int32_t ret;
uint8_t wbuff[4] = {0x12, 0x34, 0x56, 0x78};
/* Write data of a specific length into an SPI device. */
ret = SpiWrite(spiHandle, wbuff, 4);
if (ret != 0) {
    HDF_LOGE("SpiWrite: failed, ret %d\n", ret);
}
```

-   Reading data of a specific length from an SPI device

To read data from an SPI device only once, call the following function:

int32\_t SpiRead\(DevHandle handle, uint8\_t \*buf, uint32\_t len\);

**Table  6** Description of SpiRead

<a name="table0265191412124"></a>
<table><tbody><tr id="row42651914141213"><td class="cellrowborder" valign="top" width="50%"><p id="p1483184123"><a name="p1483184123"></a><a name="p1483184123"></a><strong id="b528223019480"><a name="b528223019480"></a><a name="b528223019480"></a>Parameter</strong></p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p id="p9831871216"><a name="p9831871216"></a><a name="p9831871216"></a><strong id="b3416318489"><a name="b3416318489"></a><a name="b3416318489"></a>Description</strong></p>
</td>
</tr>
<tr id="row1926651415123"><td class="cellrowborder" valign="top" width="50%"><p id="p389183129"><a name="p389183129"></a><a name="p389183129"></a>handle</p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p id="p168151817124"><a name="p168151817124"></a><a name="p168151817124"></a>SPI device handle.</p>
</td>
</tr>
<tr id="row202661414201220"><td class="cellrowborder" valign="top" width="50%"><p id="p158161821210"><a name="p158161821210"></a><a name="p158161821210"></a>buf</p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p id="p98131811126"><a name="p98131811126"></a><a name="p98131811126"></a>Pointer to the data to read.</p>
</td>
</tr>
<tr id="row1926621451212"><td class="cellrowborder" valign="top" width="50%"><p id="p2918182124"><a name="p2918182124"></a><a name="p2918182124"></a>len</p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p id="p169718191220"><a name="p169718191220"></a><a name="p169718191220"></a>Length of the data to read.</p>
</td>
</tr>
<tr id="row05841310206"><td class="cellrowborder" valign="top" width="50%"><p id="p38171818128"><a name="p38171818128"></a><a name="p38171818128"></a><strong id="b1364973254814"><a name="b1364973254814"></a><a name="b1364973254814"></a>Return Value</strong></p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p id="p881918161220"><a name="p881918161220"></a><a name="p881918161220"></a><strong id="b04341333484"><a name="b04341333484"></a><a name="b04341333484"></a>Description</strong></p>
</td>
</tr>
<tr id="row15584173192016"><td class="cellrowborder" valign="top" width="50%"><p id="p14871820128"><a name="p14871820128"></a><a name="p14871820128"></a>0</p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p id="p88118101211"><a name="p88118101211"></a><a name="p88118101211"></a>Succeeded in reading data from an SPI device.</p>
</td>
</tr>
<tr id="row1058418317204"><td class="cellrowborder" valign="top" width="50%"><p id="p10841817125"><a name="p10841817125"></a><a name="p10841817125"></a>Negative value</p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p id="p986183127"><a name="p986183127"></a><a name="p986183127"></a>Failed to read data from an SPI device.</p>
</td>
</tr>
</tbody>
</table>

```
int32_t ret;
uint8_t rbuff[4] = {0};
/* Read data of a specific length from an SPI device. */
ret = SpiRead(spiHandle, rbuff, 4);
if (ret != 0) {
    HDF_LOGE("SpiRead: failed, ret %d\n", ret);
}
```

-   Launching a custom transfer

To launch a custom transfer, call the following function:

int32\_t SpiTransfer\(DevHandle handle, struct SpiMsg \*msgs, uint32\_t count\);

**Table  7** Description of SpiTransfer

<a name="table1934414174212"></a>
<table><tbody><tr id="row1134415176216"><td class="cellrowborder" valign="top" width="50%"><p id="p13295152320217"><a name="p13295152320217"></a><a name="p13295152320217"></a><strong id="b1628393012482"><a name="b1628393012482"></a><a name="b1628393012482"></a>Parameter</strong></p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p id="p1295112352115"><a name="p1295112352115"></a><a name="p1295112352115"></a><strong id="b175931204814"><a name="b175931204814"></a><a name="b175931204814"></a>Description</strong></p>
</td>
</tr>
<tr id="row5344101702113"><td class="cellrowborder" valign="top" width="50%"><p id="p19295132382111"><a name="p19295132382111"></a><a name="p19295132382111"></a>handle</p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p id="p829510232213"><a name="p829510232213"></a><a name="p829510232213"></a>SPI device handle.</p>
</td>
</tr>
<tr id="row17344171722117"><td class="cellrowborder" valign="top" width="50%"><p id="p9295122332113"><a name="p9295122332113"></a><a name="p9295122332113"></a>msgs</p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p id="p202951238218"><a name="p202951238218"></a><a name="p202951238218"></a>Pointer to the message array to be transferred.</p>
</td>
</tr>
<tr id="row45812466213"><td class="cellrowborder" valign="top" width="50%"><p id="p1659246112117"><a name="p1659246112117"></a><a name="p1659246112117"></a>count</p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p id="p259124622119"><a name="p259124622119"></a><a name="p259124622119"></a>Number of messages in the message array.</p>
</td>
</tr>
<tr id="row45187318214"><td class="cellrowborder" valign="top" width="50%"><p id="p17295142322113"><a name="p17295142322113"></a><a name="p17295142322113"></a><strong id="b5650532164818"><a name="b5650532164818"></a><a name="b5650532164818"></a>Return Value</strong></p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p id="p142959232211"><a name="p142959232211"></a><a name="p142959232211"></a><strong id="b84349335480"><a name="b84349335480"></a><a name="b84349335480"></a>Description</strong></p>
</td>
</tr>
<tr id="row175186313217"><td class="cellrowborder" valign="top" width="50%"><p id="p929532313211"><a name="p929532313211"></a><a name="p929532313211"></a>0</p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p id="p829512237217"><a name="p829512237217"></a><a name="p829512237217"></a>Succeeded in launching the custom transfer.</p>
</td>
</tr>
<tr id="row1451803152114"><td class="cellrowborder" valign="top" width="50%"><p id="p12958234217"><a name="p12958234217"></a><a name="p12958234217"></a>Negative value</p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p id="p1295192312112"><a name="p1295192312112"></a><a name="p1295192312112"></a>Failed to launch the custom transfer.</p>
</td>
</tr>
</tbody>
</table>

```
int32_t ret;
uint8_t wbuff[1] = {0x12};
uint8_t rbuff[1] = {0};
struct SpiMsg msg;        /* Custom message to be transferred */
msg.wbuf = wbuff;         /* Pointer to the data to write */
msg.rbuf = rbuff;         /* Pointer to the data to read */
msg.len = 1;              /* The length of the data to read or write is 1 bit. */
msg.csChange = 1;         /* Disable the CS before the next transfer. */
msg.delayUs = 0;          /* No delay before the next transfer */
msg.speed = 115200;       /* Speed of this transfer */
/* Launch a custom transfer. The number of messages to be transferred is 1. */
ret = SpiTransfer(spiHandle, &msg, 1);
if (ret != 0) {
    HDF_LOGE("SpiTransfer: failed, ret %d\n", ret);
}
```

### Destroying the SPI Device Handle<a name="section19661632135117"></a>

After the SPI communication, destroy the SPI device handle by calling the following function:

void SpiClose\(DevHandle handle\);

This function will release the resources previously obtained.

**Table  8** Description of SpiClose

<a name="table72517953115"></a>
<table><tbody><tr id="row1525793312"><td class="cellrowborder" valign="top" width="50%"><p id="p115402031153111"><a name="p115402031153111"></a><a name="p115402031153111"></a><strong id="b1728493044820"><a name="b1728493044820"></a><a name="b1728493044820"></a>Parameter</strong></p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p id="p65406313319"><a name="p65406313319"></a><a name="p65406313319"></a><strong id="b176133134814"><a name="b176133134814"></a><a name="b176133134814"></a>Description</strong></p>
</td>
</tr>
<tr id="row1926109193116"><td class="cellrowborder" valign="top" width="50%"><p id="p105419317318"><a name="p105419317318"></a><a name="p105419317318"></a>handle</p>
</td>
<td class="cellrowborder" valign="top" width="50%"><p id="p16541153110317"><a name="p16541153110317"></a><a name="p16541153110317"></a>SPI device handle.</p>
</td>
</tr>
</tbody>
</table>

```
SpiClose(spiHandle); /* Destroy the SPI device handle. */
```

## Usage Example<a name="section06541058155120"></a>

The following example shows how to obtain an SPI device handle, set the configuration parameters, and then read or write data from or into the SPI device, and finally destroy the SPI device handle.

```
#include "hdf_log.h"
#include "spi_if.h"

void SpiTestSample(void)
{
    int32_t ret;
    struct SpiCfg cfg;                  /* SPI device configuration information */
    struct SpiDevInfo spiDevinfo;       /* SPI device descriptor */
    DevHandle spiHandle = NULL; /* SPI device handle */
    struct SpiMsg msg;                  /* Custom message to be transferred */
    uint8_t rbuff[4] = { 0 };
    uint8_t wbuff[4] = { 0x12, 0x34, 0x56, 0x78 };
    uint8_t wbuff2[4] = { 0xa1, 0xb2, 0xc3, 0xd4 };

    spiDevinfo.busNum = 0;              /* SPI device bus number */
    spiDevinfo.csNum = 0;               /* SPI device CS number */
    spiHandle = SpiOpen(&spiDevinfo);   /* Obtain an SPI device handle based on spiDevinfo. */
    if (spiHandle == NULL) {
        HDF_LOGE("SpiOpen: failed\n");
        return;
    }
    /* Obtain configuration parameters of an SPI device. */
    ret = SpiGetCfg(spiHandle, &cfg);
    if (ret != 0) {
        HDF_LOGE("SpiGetCfg: failed, ret %d\n", ret);
        goto err;
    }
    cfg.maxSpeedHz = 115200;                /* Change the maximum clock frequency to 115200. */
    cfg.bitsPerWord = 8;                    /* Change the word width to 8 bits. */
    /* Set configuration parameters for an SPI device. */
    ret = SpiSetCfg(spiHandle, &cfg);
    if (ret != 0) {
        HDF_LOGE("SpiSetCfg: failed, ret %d\n", ret);
        goto err;
    }
    /* Write specified length of data into an SPI device. */
    ret = SpiWrite(spiHandle, wbuff, 4);
    if (ret != 0) {
        HDF_LOGE("SpiWrite: failed, ret %d\n", ret);
        goto err;
    }
    /* Read data of a specific length from an SPI device. */
    ret = SpiRead(spiHandle, rbuff, 4);
    if (ret != 0) {
        HDF_LOGE("SpiRead: failed, ret %d\n", ret);
        goto err;
    }
    msg.wbuf = wbuff2;  /* Pointer to the data to write */
    msg.rbuf = rbuff;   /* Pointer to the data to read */
    msg.len = 4;        /* The length of the data to read or write is 4 bits. */
    msg.csChange = 1;   /* Disable the CS before the next transfer. */
    msg.delayUs = 0;    /* No delay before the next transfer */
    msg.speed = 115200; /* Speed of this transfer */
    /* Launch a custom transfer. The number of messages to be transferred is 1. */
    ret = SpiTransfer(spiHandle, &msg, 1);
    if (ret != 0) {
        HDF_LOGE("SpiTransfer: failed, ret %d\n", ret);
        goto err;
    }
err:
    /* Destroy the SPI device handle. */
    SpiClose(spiHandle);
}
```