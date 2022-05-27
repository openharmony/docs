# MMC<a name="EN-US_TOPIC_0000001153669000"></a>

## Overview<a name="section1846388309162704"></a>

In the Hardware Driver Foundation \(HDF\) framework, the MultiMedia Card \(MMC\) uses the independent service mode for API adaptation. In this mode, each device independently publishes a device service to handle external access requests. After receiving an access request from an API, the device manager extracts the parameters in the request to call the internal method of the target device. In the independent service mode, the service management capabilities of the HDFDeviceManager can be directly used. However, you need to configure a device node for each device, which increases the memory usage.

**Figure  1** Independent service mode<a name="fig19517114132810"></a>  
![](figures/independent-service-mode.png "independent-service-mode")

## Available APIs<a name="section752964871810"></a>

MmcCntlrOps

```
struct MmcCntlrOps {
  int32_t (*request)(struct MmcCntlr *cntlr, struct MmcCmd *cmd);
  int32_t (*setClock)(struct MmcCntlr *cntlr, uint32_t clock);
  int32_t (*setPowerMode)(struct MmcCntlr *cntlr, enum MmcPowerMode mode);
  int32_t (*setBusWidth)(struct MmcCntlr *cntlr, enum MmcBusWidth width);
  int32_t (*setBusTiming)(struct MmcCntlr *cntlr, enum MmcBusTiming timing);
  int32_t (*setSdioIrq)(struct MmcCntlr *cntlr, bool enable);
  int32_t (*hardwareReset)(struct MmcCntlr *cntlr);
  int32_t (*systemInit)(struct MmcCntlr *cntlr);
  int32_t (*setEnhanceSrobe)(struct MmcCntlr *cntlr, bool enable);
  int32_t (*switchVoltage)(struct MmcCntlr *cntlr, enum MmcVolt volt);
  bool (*devReadOnly)(struct MmcCntlr *cntlr);
  bool (*devPluged)(struct MmcCntlr *cntlr);
  bool (*devBusy)(struct MmcCntlr *cntlr);
  int32_t  (*tune)(struct MmcCntlr *cntlr, uint32_t cmdCode);
  int32_t (*rescanSdioDev)(struct MmcCntlr *cntlr);
};
```

**Table  1** Callbacks for the members in the MmcCntlrOps structure

<a name="table99129433019"></a>
<table><thead align="left"><tr id="row1891214163012"><th class="cellrowborder" valign="top" width="25%" id="mcps1.2.5.1.1"><p id="p79129483017"><a name="p79129483017"></a><a name="p79129483017"></a>Callback</p>
</th>
<th class="cellrowborder" valign="top" width="25%" id="mcps1.2.5.1.2"><p id="p1591213403019"><a name="p1591213403019"></a><a name="p1591213403019"></a>Input Parameter</p>
</th>
<th class="cellrowborder" valign="top" width="25%" id="mcps1.2.5.1.3"><p id="p491312483012"><a name="p491312483012"></a><a name="p491312483012"></a>Return Value</p>
</th>
<th class="cellrowborder" valign="top" width="25%" id="mcps1.2.5.1.4"><p id="p8913144203017"><a name="p8913144203017"></a><a name="p8913144203017"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row4913844307"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 "><p id="p17913149309"><a name="p17913149309"></a><a name="p17913149309"></a>doRequest</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 "><p id="p359655512340"><a name="p359655512340"></a><a name="p359655512340"></a><strong id="b1596155533411"><a name="b1596155533411"></a><a name="b1596155533411"></a>cntlr</strong>: structure pointer to the MMC controller at the core layer.</p>
<p id="p159131449308"><a name="p159131449308"></a><a name="p159131449308"></a><strong id="b71781053113715"><a name="b71781053113715"></a><a name="b71781053113715"></a>cmd</strong>: structure pointer to the input command.</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="p1291519413308"><a name="p1291519413308"></a><a name="p1291519413308"></a>HDF_STATUS</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.4 "><p id="p3915048309"><a name="p3915048309"></a><a name="p3915048309"></a>Processes the request.</p>
</td>
</tr>
<tr id="row17915124113014"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 "><p id="p69152416307"><a name="p69152416307"></a><a name="p69152416307"></a>setClock</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 "><p id="p12397758163416"><a name="p12397758163416"></a><a name="p12397758163416"></a><strong id="b2397155816345"><a name="b2397155816345"></a><a name="b2397155816345"></a>cntlr</strong>: structure pointer to the MMC controller at the core layer.</p>
<p id="p119153413013"><a name="p119153413013"></a><a name="p119153413013"></a><strong id="b13651101617393"><a name="b13651101617393"></a><a name="b13651101617393"></a>clock</strong>: input clock value.</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="p79153417302"><a name="p79153417302"></a><a name="p79153417302"></a>HDF_STATUS</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.4 "><p id="p1291614183010"><a name="p1291614183010"></a><a name="p1291614183010"></a>Sets the clock frequency.</p>
</td>
</tr>
<tr id="row19168433011"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 "><p id="p1391614416305"><a name="p1391614416305"></a><a name="p1391614416305"></a>setPowerMode</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 "><p id="p349710303139"><a name="p349710303139"></a><a name="p349710303139"></a><strong id="b749713013132"><a name="b749713013132"></a><a name="b749713013132"></a>cntlr</strong>: structure pointer to the MMC controller at the core layer.</p>
<p id="p99161341305"><a name="p99161341305"></a><a name="p99161341305"></a><strong id="b1355614134405"><a name="b1355614134405"></a><a name="b1355614134405"></a>mode</strong>: power consumption mode. It is an enumerated value (see MmcPowerMode).</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="p1091674183020"><a name="p1091674183020"></a><a name="p1091674183020"></a>HDF_STATUS</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.4 "><p id="p1191617420307"><a name="p1191617420307"></a><a name="p1191617420307"></a>Sets the power consumption mode.</p>
</td>
</tr>
<tr id="row291620463018"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 "><p id="p291612453018"><a name="p291612453018"></a><a name="p291612453018"></a>setBusWidth</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 "><p id="p52591598350"><a name="p52591598350"></a><a name="p52591598350"></a><strong id="b225999203512"><a name="b225999203512"></a><a name="b225999203512"></a>cntlr</strong>: structure pointer to the MMC controller at the core layer.</p>
<p id="p11916245309"><a name="p11916245309"></a><a name="p11916245309"></a><strong id="b24742024134111"><a name="b24742024134111"></a><a name="b24742024134111"></a>width</strong>: bus width. It is an enumerated value (see MmcBusWidth).</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="p1491610415305"><a name="p1491610415305"></a><a name="p1491610415305"></a>HDF_STATUS</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.4 "><p id="p19916147304"><a name="p19916147304"></a><a name="p19916147304"></a>Sets the bus width.</p>
</td>
</tr>
<tr id="row1916742301"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 "><p id="p3916104143014"><a name="p3916104143014"></a><a name="p3916104143014"></a>setBusTiming</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 "><p id="p109861912123517"><a name="p109861912123517"></a><a name="p109861912123517"></a><strong id="b39864125357"><a name="b39864125357"></a><a name="b39864125357"></a>cntlr</strong>: structure pointer to the MMC controller at the core layer.</p>
<p id="p591710419302"><a name="p591710419302"></a><a name="p591710419302"></a><strong id="b1067164920426"><a name="b1067164920426"></a><a name="b1067164920426"></a>timing</strong>: bus timing. It is an enumerated value (see MmcBusTiming).</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="p14917154123017"><a name="p14917154123017"></a><a name="p14917154123017"></a>HDF_STATUS</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.4 "><p id="p1991814443016"><a name="p1991814443016"></a><a name="p1991814443016"></a>Sets the bus timing.</p>
</td>
</tr>
<tr id="row199186423012"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 "><p id="p991810414305"><a name="p991810414305"></a><a name="p991810414305"></a>setSdioIrq</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 "><p id="p207324169351"><a name="p207324169351"></a><a name="p207324169351"></a><strong id="b11731716183510"><a name="b11731716183510"></a><a name="b11731716183510"></a>cntlr</strong>: structure pointer to the MMC controller at the core layer.</p>
<p id="p16918844305"><a name="p16918844305"></a><a name="p16918844305"></a><strong id="b49304428454"><a name="b49304428454"></a><a name="b49304428454"></a>enable</strong>: specifies whether to enable interrupt.</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="p17918204193011"><a name="p17918204193011"></a><a name="p17918204193011"></a>HDF_STATUS</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.4 "><p id="p1191813416305"><a name="p1191813416305"></a><a name="p1191813416305"></a>Enables or disables Secure Digital Input Output (SDIO) interrupt.</p>
</td>
</tr>
<tr id="row139181453012"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 "><p id="p491874193011"><a name="p491874193011"></a><a name="p491874193011"></a>hardwareReset</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 "><p id="p12918114163011"><a name="p12918114163011"></a><a name="p12918114163011"></a><strong id="b127774583476"><a name="b127774583476"></a><a name="b127774583476"></a>cntlr</strong>: structure pointer to the MMC controller at the core layer.</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="p4918244309"><a name="p4918244309"></a><a name="p4918244309"></a>HDF_STATUS</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.4 "><p id="p11919243306"><a name="p11919243306"></a><a name="p11919243306"></a>Resets hardware.</p>
</td>
</tr>
<tr id="row169195410309"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 "><p id="p89191746303"><a name="p89191746303"></a><a name="p89191746303"></a>systemInit</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 "><p id="p8919441302"><a name="p8919441302"></a><a name="p8919441302"></a><strong id="b296543474814"><a name="b296543474814"></a><a name="b296543474814"></a>cntlr</strong>: structure pointer to the MMC controller at the core layer.</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="p199191941307"><a name="p199191941307"></a><a name="p199191941307"></a>HDF_STATUS</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.4 "><p id="p391919473014"><a name="p391919473014"></a><a name="p391919473014"></a>Performs system initialization.</p>
</td>
</tr>
<tr id="row159191423012"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 "><p id="p189194417307"><a name="p189194417307"></a><a name="p189194417307"></a>setEnhanceSrobe</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 "><p id="p684922173510"><a name="p684922173510"></a><a name="p684922173510"></a><strong id="b1184122212354"><a name="b1184122212354"></a><a name="b1184122212354"></a>cntlr</strong>: structure pointer to the MMC controller at the core layer.</p>
<p id="p1191910419304"><a name="p1191910419304"></a><a name="p1191910419304"></a><strong id="b17674159184914"><a name="b17674159184914"></a><a name="b17674159184914"></a>enable</strong>: specifies whether to enable the enhanced strobe feature.</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="p69194473011"><a name="p69194473011"></a><a name="p69194473011"></a>HDF_STATUS</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.4 "><p id="p091904143019"><a name="p091904143019"></a><a name="p091904143019"></a>Sets the enhanced strobe feature.</p>
</td>
</tr>
<tr id="row109197416305"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 "><p id="p791917443010"><a name="p791917443010"></a><a name="p791917443010"></a>switchVoltage</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 "><p id="p180311317351"><a name="p180311317351"></a><a name="p180311317351"></a><strong id="b2803231173514"><a name="b2803231173514"></a><a name="b2803231173514"></a>cntlr</strong>: structure pointer to the MMC controller at the core layer.</p>
<p id="p1591912415304"><a name="p1591912415304"></a><a name="p1591912415304"></a><strong id="b5411538185218"><a name="b5411538185218"></a><a name="b5411538185218"></a>volt</strong>: voltage, which can be 3.3 V, 1.8 V, or 1.2 V. It is an enumerated value.</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="p59196416307"><a name="p59196416307"></a><a name="p59196416307"></a>HDF_STATUS</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.4 "><p id="p169207416301"><a name="p169207416301"></a><a name="p169207416301"></a>Sets the voltage.</p>
</td>
</tr>
<tr id="row1992015417301"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 "><p id="p1892014463010"><a name="p1892014463010"></a><a name="p1892014463010"></a>devReadOnly</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 "><p id="p1392011411309"><a name="p1392011411309"></a><a name="p1392011411309"></a><strong id="b20848102414403"><a name="b20848102414403"></a><a name="b20848102414403"></a>cntlr</strong>: structure pointer to the MMC controller at the core layer.</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="p89207418304"><a name="p89207418304"></a><a name="p89207418304"></a>Boolean</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.4 "><p id="p7920847301"><a name="p7920847301"></a><a name="p7920847301"></a>Checks whether the device is read-only.</p>
</td>
</tr>
<tr id="row1092019483018"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 "><p id="p1092034103011"><a name="p1092034103011"></a><a name="p1092034103011"></a>cardPluged</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 "><p id="p2920144123010"><a name="p2920144123010"></a><a name="p2920144123010"></a><strong id="b1685142434016"><a name="b1685142434016"></a><a name="b1685142434016"></a>cntlr</strong>: structure pointer to the MMC controller at the core layer.</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="p2092014411305"><a name="p2092014411305"></a><a name="p2092014411305"></a>Boolean</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.4 "><p id="p1892094153017"><a name="p1892094153017"></a><a name="p1892094153017"></a>Checks whether the device is removed.</p>
</td>
</tr>
<tr id="row892018413013"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 "><p id="p39201146309"><a name="p39201146309"></a><a name="p39201146309"></a>devBusy</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 "><p id="p9920124193013"><a name="p9920124193013"></a><a name="p9920124193013"></a><strong id="b1885213240408"><a name="b1885213240408"></a><a name="b1885213240408"></a>cntlr</strong>: structure pointer to the MMC controller at the core layer.</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="p1992112419305"><a name="p1992112419305"></a><a name="p1992112419305"></a>Boolean</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.4 "><p id="p69211417302"><a name="p69211417302"></a><a name="p69211417302"></a>Checks whether the device is engaged.</p>
</td>
</tr>
<tr id="row71064053613"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 "><p id="p1511114015361"><a name="p1511114015361"></a><a name="p1511114015361"></a>tune</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 "><p id="p4972240153511"><a name="p4972240153511"></a><a name="p4972240153511"></a><strong id="b1997244017354"><a name="b1997244017354"></a><a name="b1997244017354"></a>cntlr</strong>: structure pointer to the MMC controller at the core layer.</p>
<p id="p5116409364"><a name="p5116409364"></a><a name="p5116409364"></a><strong id="b2286168195617"><a name="b2286168195617"></a><a name="b2286168195617"></a>cmdCode</strong>: command code of the uint32_t type.</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="p711440123610"><a name="p711440123610"></a><a name="p711440123610"></a>HDF_STATUS</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.4 "><p id="p1411184011368"><a name="p1411184011368"></a><a name="p1411184011368"></a>Tunes</p>
</td>
</tr>
<tr id="row1559214410366"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 "><p id="p1559364493618"><a name="p1559364493618"></a><a name="p1559364493618"></a>rescanSdioDev</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 "><p id="p165931944133618"><a name="p165931944133618"></a><a name="p165931944133618"></a><strong id="b0854424164010"><a name="b0854424164010"></a><a name="b0854424164010"></a>cntlr</strong>: structure pointer to the MMC controller at the core layer.</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="p15593184493610"><a name="p15593184493610"></a><a name="p15593184493610"></a>HDF_STATUS</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.4 "><p id="p359384473615"><a name="p359384473615"></a><a name="p359384473615"></a>Scans and adds an SDIO device.</p>
</td>
</tr>
</tbody>
</table>

## How to Develop<a name="section1617495117162704"></a>

The MMC module adaptation involves the following steps:

1.  Instantiate the driver entry.
    -   Instantiate the **HdfDriverEntry** structure.
    -   Call **HDF\_INIT** to register the **HdfDriverEntry** instance with the HDF framework.

2.  Configure attribute files.
    -   Add the **deviceNode** information to the **device\_info.hcs** file.
    -   \(Optional\) Add the **mmc\_config.hcs** file.

3.  Instantiate the MMC controller object.
    -   Initialize **MmcCntlr**.
    -   Instantiate **MmcCntlrOps** in the **MmcCntlr** object.

        For details, see [Available APIs](#available-apis). 

4.  \(Optional\) Debug the driver.
    For new drivers, verify basic functions, for example, verify the information returned after the mount operation and whether the device starts successfully.


## Development Example<a name="section1220893490162704"></a>

The following uses **himci.c** as an example to present the contents that need to be provided by the vendor to implement device functions.

1.  Instantiate the driver entry. The driver entry must be a global variable of the **HdfDriverEntry** type \(defined in **hdf\_device\_desc.h**\), and the value of **moduleName** must be the same as that in **device\_info.hcs**. In the HDF framework, the start address of each **HdfDriverEntry** object of all loaded drivers is collected to form a segment address space similar to an array for the upper layer to invoke.

    Generally, HDF calls the **Bind** function and then the **Init** function to load a driver. If **Init** fails to be called, HDF calls **Release** to release driver resources and exit.

    -   MMC driver entry reference

        ```
        struct HdfDriverEntry g_mmcDriverEntry = {
            .moduleVersion = 1,
            .Bind = HimciMmcBind, // See the Bind function.
            .Init = HimciMmcInit, // See the Init function.
            .Release = HimciMmcRelease, //See the Release function.
             .moduleName = "hi3516_mmc_driver",// (Mandatory) The value must be the same as that of moduleName in the .hcs file.
        };
        HDF_INIT(g_mmcDriverEntry);  // Call HDF_INIT to register the driver entry with the HDF framework.
        ```

2.  Add the **deviceNode** information to the **device\_info.hcs** file and configure the device attributes in the **mmc\_config.hcs** file. The **deviceNode** information is related to registration of the driver entry. The device attribute values are closely related to the default values or value ranges of the **MmcCntlr** members at the core layer.

    If there are multiple devices, you need to add the **deviceNode** information to the **device\_info** file and add the corresponding device attributes to the **mmc\_config** file.

    - **device\_info.hcs** configuration reference

        ```
        root {
          device_info {
            match_attr = "hdf_manager";
            platform :: host {
              hostName = "platform_host";
              priority = 50;
              device_mmc:: device {
                device0 :: deviceNode {
                  policy = 2;
                  priority = 10;
                  permission = 0644;
                 moduleName = "hi3516_mmc_driver"; // (Mandatory) Driver name, which must be the same as the moduleName in the driver entry.
                serviceName = "HDF_PLATFORM_MMC_0"; // (Mandatory) Unique name of the service published by the driver
                deviceMatchAttr = "hi3516_mmc_emmc";// (Mandatory) Used to configure the private data of the controller. The value must be the same as the controller in mmc_config.hcs.
                }
                device1 :: deviceNode {
                  policy = 1;
                  priority = 20;
                  permission = 0644;
                  moduleName = "hi3516_mmc_driver";
                  serviceName = "HDF_PLATFORM_MMC_1";
                  deviceMatchAttr = "hi3516_mmc_sd"; // Indicates an SD.
                }
                device2 :: deviceNode {
                  policy = 1;
                  priority = 30;
                  permission = 0644;
                  moduleName = "hi3516_mmc_driver";
                  serviceName = "HDF_PLATFORM_MMC_2";
                  deviceMatchAttr = "hi3516_mmc_sdio";// Indicates an SDIO.
                }
              }
            }
          }
        }
        ```

    - **mmc\_config.hcs** configuration reference

        ```
        root {
          platform {
            mmc_config {
              template mmc_controller {// Template configuration. In the template, you can configure the common parameters shared by service nodes.
                match_attr = "";
                voltDef = 0;            // 3.3V
                freqMin = 50000; // (Mandatory) Minimum frequency
                freqMax = 100000000; // (Mandatory) Maximum frequency
                freqDef = 400000; // (Mandatory) Default frequency
                maxBlkNum = 2048; // (Mandatory) Maximum block number
                maxBlkSize = 512; // (Mandatory) Maximum number of blocks
                ocrDef = 0x300000; // (Mandatory) Working voltage.
                caps2 = 0; // (Mandatory) Attribute register. For details, see MmcCaps2 in mmc_caps.h.
                regSize = 0x118; // (Mandatory) Register bit width
                hostId = 0; // (Mandatory) Host ID
            regBasePhy = 0x10020000;// (Mandatory) Physical base address of the register
                irqNum = 63; // (Mandatory) Interrupt number
                devType = 2; // (Mandatory) Device mode, which can be eMMC, SD, SDIO, or COMBO
                caps = 0x0001e045; // (Mandatory) Attribute register. For details, see MmcCaps in mmc_caps.h.
              }
              controller_0x10100000 :: mmc_controller {
                match_attr = "hi3516_mmc_emmc";// (Mandatory) The value must be the same as that of deviceMatchAttr in device_info.hcs.
                hostId = 0;
                regBasePhy = 0x10100000;
                irqNum = 96;
                devType = 0; // The value 0 indicates an eMMC.
                caps = 0xd001e045;
                caps2 = 0x60;
              }
              controller_0x100f0000 :: mmc_controller {
                match_attr = "hi3516_mmc_sd";
                hostId = 1;
                regBasePhy = 0x100f0000;
                irqNum = 62;
                devType = 1; // The value 1 indicates an SD card.
                caps = 0xd001e005;
              }
              controller_0x10020000 :: mmc_controller {
                match_attr = "hi3516_mmc_sdio";
                hostId = 2;
                regBasePhy = 0x10020000;
                irqNum = 63;
                devType = 2; // The value 2 indicates an SDIO device.
                caps = 0x0001e04d;
              }
            }
          }
        }
        ```

3.  Initialize the **MmcCntlr** object at the core layer, including initializing the vendor custom structure \(transferring parameters and data\), instantiating **MmcCntlrOps** \(used to call underlying functions of the driver\) in **MmcCntlr**, and implementing the **HdfDriverEntry** member functions \(**Bind**, **Init**, and **Release**\).
    -   Custom structure reference

        To the driver, the custom structure carries parameters and data. The values in the **mmc\_config.hcs** file are read by the HDF, and the structure members are initialized through **DeviceResourceIface**. Some important values are also transferred to the objects at the core layer.

        ```
        struct HimciHost {
            struct MmcCntlr *mmc;// (Mandatory) Core layer structure
            struct MmcCmd *cmd; // (Mandatory) Core layer structure used to transfer commands. For details about related commands, see MmcCmdCode.
            //(Optional) Set parameters based on the vendor's requirements.
            void *base;
            enum HimciPowerStatus powerStatus;
            uint8_t *alignedBuff;
            uint32_t buffLen;
            struct scatterlist dmaSg;
            struct scatterlist *sg;
            uint32_t dmaSgNum;
            DMA_ADDR_T dmaPaddr;
            uint32_t *dmaVaddr;
            uint32_t irqNum;
            bool isTuning;
            uint32_t id;
            struct OsalMutex mutex;
            bool waitForEvent;
            HIMCI_EVENT himciEvent;
        };
        // MmcCntlr is the core layer controller structure. Its members are assigned with values by using the bind function.
        struct MmcCntlr {
            struct IDeviceIoService service;
            struct HdfDeviceObject *hdfDevObj;
            struct PlatformDevice device;
            struct OsalMutex mutex;
            struct OsalSem released;
            uint32_t devType;
            struct MmcDevice *curDev;
            struct MmcCntlrOps *ops;
            struct PlatformQueue *msgQueue;
            uint16_t index;
            uint16_t voltDef;
            uint32_t vddBit;
            uint32_t freqMin;
            uint32_t freqMax;
            uint32_t freqDef;
            union MmcOcr ocrDef;
            union MmcCaps caps;
            union MmcCaps2 caps2;
            uint32_t maxBlkNum;
            uint32_t maxBlkSize;
            uint32_t maxReqSize;
            bool devPluged;
            bool detecting;
            void *priv;
        };
        ```

    -   Instantiate the callback function structure **MmcCntlrOps** in **MmcCntlr**. Other members are initialized by using the **Bind** function.

        ```
        static struct MmcCntlrOps g_himciHostOps = {
            .request        = HimciDoRequest,
            .setClock       = HimciSetClock,
            .setPowerMode   = HimciSetPowerMode,
            .setBusWidth    = HimciSetBusWidth,
            .setBusTiming   = HimciSetBusTiming,
            .setSdioIrq     = HimciSetSdioIrq,
            .hardwareReset  = HimciHardwareReset,
            .systemInit     = HimciSystemInit,
            .setEnhanceSrobe= HimciSetEnhanceSrobe,
            .switchVoltage  = HimciSwitchVoltage,
            .devReadOnly    = HimciDevReadOnly,
            .devPluged      = HimciCardPluged,
            .devBusy        = HimciDevBusy,
            .tune           = HimciTune,
            .rescanSdioDev  = HimciRescanSdioDev,
        };
        ```

    -   Bind function

        Input parameters:

      **HdfDeviceObject**, an interface parameter exposed by the driver, contains the .hcs configuration file information.

        Return values:

        HDF\_STATUS \(The following table lists some status. For details about other status, see **HDF\_STATUS** in the **//drivers/framework/include/utils/hdf\_base.h** file.\)

        <a name="table1428218958162704"></a>
        <table><thead align="left"><tr id="row1723943104162704"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="entry136979408162704p0"><a name="entry136979408162704p0"></a><a name="entry136979408162704p0"></a>Status (Value)</p>
        </th>
        <th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="entry1590766658162704p0"><a name="entry1590766658162704p0"></a><a name="entry1590766658162704p0"></a>Description</p>
        </th>
        </tr>
        </thead>
        <tbody><tr id="row408410040162704"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1337150412162704p0"><a name="entry1337150412162704p0"></a><a name="entry1337150412162704p0"></a>HDF_ERR_INVALID_OBJECT</p>
        </td>
        <td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry2061632106162704p0"><a name="entry2061632106162704p0"></a><a name="entry2061632106162704p0"></a>Invalid controller object</p>
        </td>
        </tr>
        <tr id="row160841211162704"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1173668571162704p0"><a name="entry1173668571162704p0"></a><a name="entry1173668571162704p0"></a>HDF_ERR_MALLOC_FAIL</p>
        </td>
        <td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry74350097162704p0"><a name="entry74350097162704p0"></a><a name="entry74350097162704p0"></a>Failed to allocate memory</p>
        </td>
        </tr>
        <tr id="row1596857798162704"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry190784255162704p0"><a name="entry190784255162704p0"></a><a name="entry190784255162704p0"></a>HDF_ERR_INVALID_PARAM</p>
        </td>
        <td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1070501269162704p0"><a name="entry1070501269162704p0"></a><a name="entry1070501269162704p0"></a>Invalid parameter</p>
        </td>
        </tr>
        <tr id="row1645995958162704"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry741922133162704p0"><a name="entry741922133162704p0"></a><a name="entry741922133162704p0"></a>HDF_ERR_IO</p>
        </td>
        <td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry2094504256162704p0"><a name="entry2094504256162704p0"></a><a name="entry2094504256162704p0"></a>I/O error</p>
        </td>
        </tr>
        <tr id="row733220922162704"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1177794681162704p0"><a name="entry1177794681162704p0"></a><a name="entry1177794681162704p0"></a>HDF_SUCCESS</p>
        </td>
        <td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry540896959162704p0"><a name="entry540896959162704p0"></a><a name="entry540896959162704p0"></a>Initialization successful</p>
        </td>
        </tr>
        <tr id="row1890064939162704"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry118676812162704p0"><a name="entry118676812162704p0"></a><a name="entry118676812162704p0"></a>HDF_FAILURE</p>
        </td>
        <td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry2078272728162704p0"><a name="entry2078272728162704p0"></a><a name="entry2078272728162704p0"></a>Initialization failed</p>
        </td>
        </tr>
        </tbody>
        </table>

        Function description:

        Initializes the custom structure **HimciHost** object and **MmcCntlr**, and calls the **MmcCntlrAdd** function at the core layer. **MmcCntlr**, **HimciHost**, and **HdfDeviceObject** assign values with each other so that other functions can be converted successfully.

        ```
        static int32_t HimciMmcBind(struct HdfDeviceObject *obj)
        {
            struct MmcCntlr *cntlr = NULL;
            struct HimciHost *host = NULL;
            int32_t ret;
            cntlr = (struct MmcCntlr *)OsalMemCalloc(sizeof(struct MmcCntlr));
            host = (struct HimciHost *)OsalMemCalloc(sizeof(struct HimciHost));
            
            host->mmc = cntlr; // (Mandatory) Enable conversion between HimciHost and MmcCntlr.
            cntlr->priv = (void *)host; // (Mandatory) Enable conversion between HimciHost and MmcCntlr.
            cntlr->ops = &g_himciHostOps; // (Mandatory) Connect to the MmcCntlrOps instance.
            cntlr->hdfDevObj = obj; // (Mandatory) Enable conversion between HdfDeviceObject and MmcCntlr.
            obj->service = &cntlr->service; // (Mandatory) Enable conversion between HdfDeviceObject and MmcCntlr.
            ret = MmcCntlrParse(cntlr, obj); // (Mandatory) Initialize cntlr. If the initialization fails, execute goto _ERR.
            ... 
            ret = HimciHostParse(host, obj); // (Mandatory) Initialize the attributes of the host. If the initialization fails, execute goto _ERR.
            ...
            ret = HimciHostInit(host, cntlr);// Initialization defined by the vendor. If the initialization fails, execute goto _ERR.
            ...
            ret = MmcCntlrAdd(cntlr); // Call the function at the core layer. If the function fails to be called, execute goto _ERR.
            ...
            (void)MmcCntlrAddDetectMsgToQueue(cntlr);// Add the card detection message to the queue.
            HDF_LOGD("HimciMmcBind: success.");
            return HDF_SUCCESS;
        _ERR:
            HimciDeleteHost(host);
            HDF_LOGD("HimciMmcBind: fail, err = %d.", ret);
            return ret;
        }
        ```

    -   Init function

        Input parameters:

      **HdfDeviceObject**, an interface parameter exposed by the driver, contains the .hcs configuration file information.

        Return values:

        HDF\_STATUS

        Function description:

        Implements ProcMciInit.

        ```
        static int32_t HimciMmcInit(struct HdfDeviceObject *obj)
        {
            static bool procInit = false;
            (void)obj;
            if (procInit == false) {
                if (ProcMciInit() == HDF_SUCCESS) {
                    procInit = true;
                    HDF_LOGD("HimciMmcInit: proc init success.");
                }
            }
            HDF_LOGD("HimciMmcInit: success.");
            return HDF_SUCCESS;
        }
        ```

    -   Release function

        Input parameters:

      **HdfDeviceObject**, an interface parameter exposed by the driver, contains the .hcs configuration file information.

        Return values:

        –

        Function description:

        Releases the memory and deletes the controller. This function assigns a value to the **Release** API in the driver entry structure. When the HDF framework fails to call the **Init** function to initialize the driver, the **Release** function can be called to release driver resources. All forced conversion operations for obtaining the corresponding object can be successful only when the **Init** function has the corresponding value assignment operations.

        ```
        static void HimciMmcRelease(struct HdfDeviceObject *obj)
        {
            struct MmcCntlr *cntlr = NULL;
            ...
            cntlr = (struct MmcCntlr *)obj->service;// Forcibly convert HdfDeviceObject to MmcCntlr by using service. For details about the value assignment, see the Bind function.
            ...
            HimciDeleteHost((struct HimciHost *)cntlr->priv);// Memory release function customized by the vendor. A forced conversion from MmcCntlr to HimciHost is involved in the process.
        }
        ```