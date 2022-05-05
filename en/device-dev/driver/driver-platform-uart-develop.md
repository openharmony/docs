# UART<a name="EN-US_TOPIC_0000001153656474"></a>

## Overview<a name="section1761881586154520"></a>

In the Hardware Driver Foundation \(HDF\), the Universal Asynchronous Receiver/Transmitter \(UART\) uses the independent service mode for API adaptation. In this mode, each device independently publishes a device service to handle external access requests. After receiving an access request from an API, the device manager extracts the parameters in the request to call the internal method of the target device. In the independent service mode, the service management capabilities of the HDF Device Manager can be directly used. However, you need to configure a device node for each device, which increases the memory usage.

**Figure  1**  Independent service mode<a name="fig1474518243468"></a>  
![](figures/independent-service-mode.png "independent-service-mode-14")

## Available APIs<a name="section752964871810"></a>

UartHostMethod

```
struct UartHostMethod {
  int32_t (*Init)(struct UartHost *host);
  int32_t (*Deinit)(struct UartHost *host);
  int32_t (*Read)(struct UartHost *host, uint8_t *data, uint32_t size);
  int32_t (*Write)(struct UartHost *host, uint8_t *data, uint32_t size);
  int32_t (*GetBaud)(struct UartHost *host, uint32_t *baudRate);
  int32_t (*SetBaud)(struct UartHost *host, uint32_t baudRate);
  int32_t (*GetAttribute)(struct UartHost *host, struct UartAttribute *attribute);
  int32_t (*SetAttribute)(struct UartHost *host, struct UartAttribute *attribute);
  int32_t (*SetTransMode)(struct UartHost *host, enum UartTransMode mode);
  int32_t (*pollEvent)(struct UartHost *host, void *filep, void *table);
};
```

**Table  1**  Callbacks for the members in the UartHostMethod structure

<a name="table22862114719"></a>
<table><thead align="left"><tr id="row5297211471"><th class="cellrowborder" valign="top" width="20%" id="mcps1.2.6.1.1"><p id="p12291121134710"><a name="p12291121134710"></a><a name="p12291121134710"></a>Callback</p>
</th>
<th class="cellrowborder" valign="top" width="20%" id="mcps1.2.6.1.2"><p id="p3291921164712"><a name="p3291921164712"></a><a name="p3291921164712"></a>Input Parameter</p>
</th>
<th class="cellrowborder" valign="top" width="19.98%" id="mcps1.2.6.1.3"><p id="p15291321114718"><a name="p15291321114718"></a><a name="p15291321114718"></a>Output Parameter</p>
</th>
<th class="cellrowborder" valign="top" width="20.02%" id="mcps1.2.6.1.4"><p id="p03092115478"><a name="p03092115478"></a><a name="p03092115478"></a>Return Value</p>
</th>
<th class="cellrowborder" valign="top" width="20%" id="mcps1.2.6.1.5"><p id="p230172113475"><a name="p230172113475"></a><a name="p230172113475"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row13305217472"><td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.1 "><p id="p193012104714"><a name="p193012104714"></a><a name="p193012104714"></a>Init</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.2 "><p id="p53082134713"><a name="p53082134713"></a><a name="p53082134713"></a><strong id="b231216565514"><a name="b231216565514"></a><a name="b231216565514"></a>host</strong>: structure pointer to the UART controller at the core layer.</p>
</td>
<td class="cellrowborder" valign="top" width="19.98%" headers="mcps1.2.6.1.3 "><p id="p14301121174719"><a name="p14301121174719"></a><a name="p14301121174719"></a>–</p>
</td>
<td class="cellrowborder" valign="top" width="20.02%" headers="mcps1.2.6.1.4 "><p id="p83092116473"><a name="p83092116473"></a><a name="p83092116473"></a>HDF_STATUS</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.5 "><p id="p173032124713"><a name="p173032124713"></a><a name="p173032124713"></a>Initializes the UART device.</p>
</td>
</tr>
<tr id="row530121144713"><td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.1 "><p id="p12301215474"><a name="p12301215474"></a><a name="p12301215474"></a>Deinit</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.2 "><p id="p14301921174718"><a name="p14301921174718"></a><a name="p14301921174718"></a><strong id="b7500154935512"><a name="b7500154935512"></a><a name="b7500154935512"></a>host</strong>: structure pointer to the UART controller at the core layer.</p>
</td>
<td class="cellrowborder" valign="top" width="19.98%" headers="mcps1.2.6.1.3 "><p id="p143142110477"><a name="p143142110477"></a><a name="p143142110477"></a>–</p>
</td>
<td class="cellrowborder" valign="top" width="20.02%" headers="mcps1.2.6.1.4 "><p id="p1531162174719"><a name="p1531162174719"></a><a name="p1531162174719"></a>HDF_STATUS</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.5 "><p id="p203162110478"><a name="p203162110478"></a><a name="p203162110478"></a>Deinitializes the UART device.</p>
</td>
</tr>
<tr id="row93172118476"><td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.1 "><p id="p1231102194712"><a name="p1231102194712"></a><a name="p1231102194712"></a>Read</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.2 "><p id="p117841019115819"><a name="p117841019115819"></a><a name="p117841019115819"></a><strong id="b8784519205820"><a name="b8784519205820"></a><a name="b8784519205820"></a>host</strong>: structure pointer to the UART controller at the core layer.</p>
<p id="p13318214472"><a name="p13318214472"></a><a name="p13318214472"></a><strong id="b76471214185712"><a name="b76471214185712"></a><a name="b76471214185712"></a>size</strong>: data size, which is of the uint32_t type.</p>
</td>
<td class="cellrowborder" valign="top" width="19.98%" headers="mcps1.2.6.1.3 "><p id="p1313213473"><a name="p1313213473"></a><a name="p1313213473"></a><strong id="b1372195311577"><a name="b1372195311577"></a><a name="b1372195311577"></a>data</strong>: uint8_t pointer to the output data.</p>
</td>
<td class="cellrowborder" valign="top" width="20.02%" headers="mcps1.2.6.1.4 "><p id="p193110216473"><a name="p193110216473"></a><a name="p193110216473"></a>HDF_STATUS</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.5 "><p id="p1331102115475"><a name="p1331102115475"></a><a name="p1331102115475"></a>Receives data.</p>
</td>
</tr>
<tr id="row1731102120479"><td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.1 "><p id="p731321204711"><a name="p731321204711"></a><a name="p731321204711"></a>Write</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.2 "><p id="p11377332105815"><a name="p11377332105815"></a><a name="p11377332105815"></a><strong id="b193771532135811"><a name="b193771532135811"></a><a name="b193771532135811"></a>host</strong>: structure pointer to the UART controller at the core layer.</p>
<p id="p174031635125817"><a name="p174031635125817"></a><a name="p174031635125817"></a><strong id="b540373505819"><a name="b540373505819"></a><a name="b540373505819"></a>data</strong>: pointer to the input data, which is of the uint8_t type.</p>
<p id="p15311321204719"><a name="p15311321204719"></a><a name="p15311321204719"></a><strong id="b15686191305911"><a name="b15686191305911"></a><a name="b15686191305911"></a>size</strong>: data size, which is of the uint32_t type.</p>
</td>
<td class="cellrowborder" valign="top" width="19.98%" headers="mcps1.2.6.1.3 "><p id="p143142114478"><a name="p143142114478"></a><a name="p143142114478"></a>–</p>
</td>
<td class="cellrowborder" valign="top" width="20.02%" headers="mcps1.2.6.1.4 "><p id="p143212110477"><a name="p143212110477"></a><a name="p143212110477"></a>HDF_STATUS</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.5 "><p id="p123216211477"><a name="p123216211477"></a><a name="p123216211477"></a>Sends data.</p>
</td>
</tr>
<tr id="row73215214478"><td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.1 "><p id="p1032112119475"><a name="p1032112119475"></a><a name="p1032112119475"></a>SetBaud</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.2 "><p id="p863959125812"><a name="p863959125812"></a><a name="p863959125812"></a><strong id="b11631159145818"><a name="b11631159145818"></a><a name="b11631159145818"></a>host</strong>: structure pointer to the UART controller at the core layer. </p>
<p id="p3321521134717"><a name="p3321521134717"></a><a name="p3321521134717"></a><strong id="b16745461412"><a name="b16745461412"></a><a name="b16745461412"></a>baudRate</strong>: pointer to the input baud rate, which is of the uint32_t type.</p>
</td>
<td class="cellrowborder" valign="top" width="19.98%" headers="mcps1.2.6.1.3 "><p id="p18327218478"><a name="p18327218478"></a><a name="p18327218478"></a>–</p>
</td>
<td class="cellrowborder" valign="top" width="20.02%" headers="mcps1.2.6.1.4 "><p id="p23242111475"><a name="p23242111475"></a><a name="p23242111475"></a>HDF_STATUS</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.5 "><p id="p7321521114711"><a name="p7321521114711"></a><a name="p7321521114711"></a>Sets the baud rate.</p>
</td>
</tr>
<tr id="row113252104713"><td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.1 "><p id="p9323219476"><a name="p9323219476"></a><a name="p9323219476"></a>GetBaud</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.2 "><p id="p132821184711"><a name="p132821184711"></a><a name="p132821184711"></a><strong id="b4510164912550"><a name="b4510164912550"></a><a name="b4510164912550"></a>host</strong>: structure pointer to the UART controller at the core layer.</p>
</td>
<td class="cellrowborder" valign="top" width="19.98%" headers="mcps1.2.6.1.3 "><p id="p63262112477"><a name="p63262112477"></a><a name="p63262112477"></a><strong id="b1097116311227"><a name="b1097116311227"></a><a name="b1097116311227"></a>baudRate</strong>: uint32_t pointer to the output baud rate.</p>
</td>
<td class="cellrowborder" valign="top" width="20.02%" headers="mcps1.2.6.1.4 "><p id="p13262174719"><a name="p13262174719"></a><a name="p13262174719"></a>HDF_STATUS</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.5 "><p id="p163232154717"><a name="p163232154717"></a><a name="p163232154717"></a>Obtains the current baud rate.</p>
</td>
</tr>
<tr id="row2032102118472"><td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.1 "><p id="p9331321154714"><a name="p9331321154714"></a><a name="p9331321154714"></a>GetAttribute</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.2 "><p id="p15331721164715"><a name="p15331721164715"></a><a name="p15331721164715"></a><strong id="b1518144935510"><a name="b1518144935510"></a><a name="b1518144935510"></a>host</strong>: structure pointer to the UART controller at the core layer.</p>
</td>
<td class="cellrowborder" valign="top" width="19.98%" headers="mcps1.2.6.1.3 "><p id="p23313219472"><a name="p23313219472"></a><a name="p23313219472"></a><strong id="b16392039333"><a name="b16392039333"></a><a name="b16392039333"></a>attribute</strong>: structure pointer to the output attributes. For details, see <strong id="b524111513416"><a name="b524111513416"></a><a name="b524111513416"></a>UartAttribute</strong> in <strong id="b47291920444"><a name="b47291920444"></a><a name="b47291920444"></a>uart_if.h</strong>.</p>
</td>
<td class="cellrowborder" valign="top" width="20.02%" headers="mcps1.2.6.1.4 "><p id="p833142115476"><a name="p833142115476"></a><a name="p833142115476"></a>HDF_STATUS</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.5 "><p id="p63342119476"><a name="p63342119476"></a><a name="p63342119476"></a>Obtains UART attributes.</p>
</td>
</tr>
<tr id="row1133112144717"><td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.1 "><p id="p14331421114715"><a name="p14331421114715"></a><a name="p14331421114715"></a>SetAttribute</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.2 "><p id="p147011110590"><a name="p147011110590"></a><a name="p147011110590"></a><strong id="b070151125915"><a name="b070151125915"></a><a name="b070151125915"></a>host</strong>: structure pointer to the UART controller at the core layer.</p>
<p id="p16331210473"><a name="p16331210473"></a><a name="p16331210473"></a><strong id="b1497919522420"><a name="b1497919522420"></a><a name="b1497919522420"></a>attribute</strong>: structure pointer to the input attributes.</p>
</td>
<td class="cellrowborder" valign="top" width="19.98%" headers="mcps1.2.6.1.3 "><p id="p3331721204710"><a name="p3331721204710"></a><a name="p3331721204710"></a>–</p>
</td>
<td class="cellrowborder" valign="top" width="20.02%" headers="mcps1.2.6.1.4 "><p id="p03302111471"><a name="p03302111471"></a><a name="p03302111471"></a>HDF_STATUS</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.5 "><p id="p1933152113478"><a name="p1933152113478"></a><a name="p1933152113478"></a>Sets UART attributes.</p>
</td>
</tr>
<tr id="row834221114716"><td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.1 "><p id="p1934821104719"><a name="p1934821104719"></a><a name="p1934821104719"></a>SetTransMode</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.2 "><p id="p1821251985919"><a name="p1821251985919"></a><a name="p1821251985919"></a><strong id="b1121271918594"><a name="b1121271918594"></a><a name="b1121271918594"></a>host</strong>: structure pointer to the UART controller at the core layer.</p>
<p id="p1034621104717"><a name="p1034621104717"></a><a name="p1034621104717"></a><strong id="b104767219711"><a name="b104767219711"></a><a name="b104767219711"></a>mode</strong>: transmission mode, which is an enumerated value. For details, see <strong id="b2101455871"><a name="b2101455871"></a><a name="b2101455871"></a>UartTransMode</strong> in <strong id="b99657016815"><a name="b99657016815"></a><a name="b99657016815"></a>uart_if.h</strong>).</p>
</td>
<td class="cellrowborder" valign="top" width="19.98%" headers="mcps1.2.6.1.3 "><p id="p173442110475"><a name="p173442110475"></a><a name="p173442110475"></a>–</p>
</td>
<td class="cellrowborder" valign="top" width="20.02%" headers="mcps1.2.6.1.4 "><p id="p1734721194720"><a name="p1734721194720"></a><a name="p1734721194720"></a>HDF_STATUS</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.5 "><p id="p15341021194715"><a name="p15341021194715"></a><a name="p15341021194715"></a>Sets the UART transmission mode.</p>
</td>
</tr>
<tr id="row434192119479"><td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.1 "><p id="p133442184717"><a name="p133442184717"></a><a name="p133442184717"></a>PollEvent</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.2 "><p id="p31278367592"><a name="p31278367592"></a><a name="p31278367592"></a><strong id="b1127163625919"><a name="b1127163625919"></a><a name="b1127163625919"></a>host</strong>: structure pointer to the UART controller at the core layer.</p>
<p id="p16654144015591"><a name="p16654144015591"></a><a name="p16654144015591"></a><strong id="b86541440135917"><a name="b86541440135917"></a><a name="b86541440135917"></a>filep</strong>: void pointer to a file.</p>
<p id="p634121104712"><a name="p634121104712"></a><a name="p634121104712"></a><strong id="b163481035141514"><a name="b163481035141514"></a><a name="b163481035141514"></a>table</strong>: void pointer to a poll_table.</p>
</td>
<td class="cellrowborder" valign="top" width="19.98%" headers="mcps1.2.6.1.3 "><p id="p1334142111479"><a name="p1334142111479"></a><a name="p1334142111479"></a>–</p>
</td>
<td class="cellrowborder" valign="top" width="20.02%" headers="mcps1.2.6.1.4 "><p id="p133472110473"><a name="p133472110473"></a><a name="p133472110473"></a>HDF_STATUS</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.5 "><p id="p63522174720"><a name="p63522174720"></a><a name="p63522174720"></a>Polls for pending events.</p>
</td>
</tr>
</tbody>
</table>

## How to Develop<a name="section944397404154520"></a>

The UART module adaptation involves the following steps:

1.  Instantiate the driver entry.
    -   Instantiate the  **HdfDriverEntry**  structure.
    -   Call  **HDF\_INIT**  to register the  **HdfDriverEntry**  instance with the HDF.

2.  Configure attribute files.
    -   Add the  **deviceNode**  information to the  **device\_info.hcs**  file.
    -   \(Optional\) Add the  **uart\_config.hcs**  file.

3.  Instantiate the UART controller object.
    -   Initialize  **UartHost**.
    -   Instantiate  **UartHostMethod**  in the  **UartHost**  object.

        >![](../public_sys-resources/icon-note.gif) **NOTE** 

        >For details, see [Available APIs](#available-apis).


4.  Debug the driver.
    -   \(Optional\) For new drivers, verify the basic functions, such as the UART control status and response to interrupts.


## Development Example<a name="section774610224154520"></a>

The following uses  **uart\_hi35xx.c**  as an example to present the contents that need to be provided by the vendor to implement device functions.

1.  Instantiate the driver entry. The driver entry must be a global variable of the  **HdfDriverEntry**  type \(defined in  **hdf\_device\_desc.h**\), and the value of  **moduleName**  must be the same as that in  **device\_info.hcs**. In the HDF, the start address of each  **HdfDriverEntry**  object of all loaded drivers is collected to form a segment address space similar to an array for the upper layer to invoke.

    Generally, HDF calls the  **Bind**  function and then the  **Init**  function to load a driver. If  **Init**  fails to be called, HDF calls  **Release**  to release driver resources and exit.

    -   UART driver entry reference

        ```
        struct HdfDriverEntry g_hdfUartDevice = {
            .moduleVersion = 1,
          .moduleName = "HDF_PLATFORM_UART", // (Mandatory) This parameter must be the same as that in the .hcs file.
              .Bind = HdfUartDeviceBind, // See the Bind function.
            .Init = HdfUartDeviceInit,  // See the Init function.
           .Release = HdfUartDeviceRelease, //See the Release function.
        };
        // Call HDF_INIT to register the driver entry with the HDF.
        HDF_INIT(g_hdfUartDevice);
        ```

2.  Add the  **deviceNode**  information to the  **device\_info.hcs**  file and configure the device attributes in the  **uart\_config.hcs**  file. The  **deviceNode**  information is related to registration of the driver entry. The device attribute values are closely related to the default values or value ranges of the  **UartHost**  members at the core layer.

    In this example, there is only one UART controller. If there are multiple UART controllers, you need to add the  **deviceNode**  information to the  **device\_info**  file and add the corresponding device attributes to the  **uart\_config**  file.

    -   **device\_info.hcs**  configuration reference

        ```
        root {
          device_info {
            match_attr = "hdf_manager";
            platform :: host {
              hostName = "platform_host";
              priority = 50;
              device_uart :: device {
                device0 :: deviceNode {
                  policy = 1; // The value 1 indicates that the driver publishes kernel-mode services. The value 2 indicates that the driver publishes user-mode services.
                            priority = 40;                        // Driver startup priority
                permission = 0644;                  // Permission for the driver to create a device node
                           moduleName = "HDF_PLATFORM_UART";  // Driver name, which must be the same as that of moduleName in the driver entry structure.
                   serviceName = "HDF_PLATFORM_UART_0";// Unique name of the service published by the driver. The name is in the HDF_PLATFORM_UART_X format. X indicates the UART controller number.
                deviceMatchAttr = "hisilicon_hi35xx_uart_0"; // Keyword matching the private data of the driver. The value must be the same as that of match_attr in the private data configuration table of the driver.
                }
                device1 :: deviceNode {
                  policy = 2;
                  permission = 0644;
                  priority = 40;
                  moduleName = "HDF_PLATFORM_UART"; 
                  serviceName = "HDF_PLATFORM_UART_1";
                  deviceMatchAttr = "hisilicon_hi35xx_uart_1";
                }
                ...
              }
            }
          }
        }
        ```

    -   **uart\_config.hcs**  configuration reference

        ```
        root {
          platform {
              template uart_controller {// Template configuration. In the template, you can configure the common parameters shared by service nodes.
              match_attr = "";
                num = 0; // (Mandatory) Device number
              baudrate = 115200; // (Mandatory) Baud rate. Set the value based on service requirements.
              fifoRxEn = 1; // (Mandatory) Enable the receive of FIFOs.
              fifoTxEn = 1; // (Mandatory) Enable the transmit of FIFOs.
              flags = 4; // (Mandatory) Flag signal
              regPbase = 0x120a0000;  // (Mandatory) Used for address mapping.
              interrupt = 38; // (Mandatory) Interrupt number
              iomemCount = 0x48;  // (Mandatory) Used for address mapping.
            }
            controller_0x120a0000 :: uart_controller {
              match_attr = "hisilicon_hi35xx_uart_0";// (Mandatory) The value must be the same as that of deviceMatchAttr of the corresponding device in device_info.hcs.
            }
            controller_0x120a1000 :: uart_controller {
              num = 1;
              baudrate = 9600;
              regPbase = 0x120a1000;
              interrupt = 39;
              match_attr = "hisilicon_hi35xx_uart_1";
            }
            ...
            //(Optional) Add nodes to the device_info.hcs file as required.
          }
        }
        ```

3.  Initialize the  **UartHost**  object at the core layer, including initializing the vendor custom structure \(transferring parameters and data\), instantiating  **UartHostMethod**  \(used to call underlying functions of the driver\) in  **UartHost**, and implementing the  **HdfDriverEntry**  member functions \(**Bind**,  **Init**, and  **Release**\).
    -   Custom structure reference

        To the driver, the custom structure carries parameters and data. The values in the  **uart\_config.hcs**  file are read by HDF, and the structure members are initialized through  **DeviceResourceIface**. Some important values, such as the device number, are also passed to the objects at the core layer.

        ```
        struct UartPl011Port {// Structure related to the API
            int32_t             enable;
             unsigned long       physBase; // Physical address
                uint32_t            irqNum;          // Interrupt number
                uint32_t            defaultBaudrate;// Default baud rate
                uint32_t            flags;         // Flag signal, which is related to the following three macros.
        #define PL011_FLG_IRQ_REQUESTED    (1 << 0)
        #define PL011_FLG_DMA_RX_REQUESTED (1 << 1)
        #define PL011_FLG_DMA_TX_REQUESTED (1 << 2)
            struct UartDmaTransfer *rxUdt; // DMA transmission
            struct UartDriverData *udd; // See the following description.
        };
        struct UartDriverData {// Structure related to data transmission
            uint32_t num;
            uint32_t baudrate; // Baud rate (configurable)
            struct UartAttribute attr; // Transmission attributes, such as the data bit and stop bit
            struct UartTransfer *rxTransfer; // FIFO structure related to the buffer
            wait_queue_head_t wait; // Queuing signal related to conditional variables
            int32_t count; // Data count
            int32_t state; // UART controller status
        #define UART_STATE_NOT_OPENED 0
        #define UART_STATE_OPENING    1
        #define UART_STATE_USEABLE    2
        #define UART_STATE_SUSPENED   3
            uint32_t flags; // Status flag
        #define UART_FLG_DMA_RX       (1 << 0)
        #define UART_FLG_DMA_TX       (1 << 1)
        #define UART_FLG_RD_BLOCK     (1 << 2)
            RecvNotify recv; // Pointer to the function that receives serial port data
            struct UartOps *ops; // Custom function pointer structure. For details, see device/hisilicon/drivers/uart/uart_pl011.c.
            void *private; // It stores the pointer to the start address of UartPl011Port for easy invocation.
        };
        
        // UartHost is the controller structure at the core layer. Its members are assigned with values by using the Init function.
        struct UartHost {
            struct IDeviceIoService service;
            struct HdfDeviceObject *device;
            uint32_t num;
            OsalAtomic atom;
            void *priv; // It stores the pointer to the start address of the vendor's custom structure for invoking the structure.
            struct UartHostMethod *method; // Hook at the core layer. The vendor needs to implement and instantiate its member functions.
        };
        ```

    -   Instantiate the callback function structure  **UartHostMethod**  in  **UartHost**. Other members are initialized by using the  **Bind**  function.

        ```
        // Example in pwm_hi35xx.c: instantiate the hook.
        struct UartHostMethod g_uartHostMethod = {
          .Init = Hi35xxInit,
          .Deinit = Hi35xxDeinit,
          .Read = Hi35xxRead,
          .Write = Hi35xxWrite,
          .SetBaud = Hi35xxSetBaud,
          .GetBaud = Hi35xxGetBaud,
          .SetAttribute = Hi35xxSetAttribute,
          .GetAttribute = Hi35xxGetAttribute,
          .SetTransMode = Hi35xxSetTransMode,
          .pollEvent = Hi35xxPollEvent,
        };
        ```

    -   Bind function

        Input parameters:

        **HdfDeviceObject**, an interface parameter exposed by the driver, contains the .hcs configuration file information.

        Return values:

        HDF\_STATUS \(The following table lists some status. For details about other status, see  **HDF\_STATUS**  in the  **//drivers/framework/include/utils/hdf\_base.h**  file.\)

        **Table  2**  Input parameters and return values of the Bind function

        <a name="table69781823185619"></a>
        <table><thead align="left"><tr id="row997916234569"><th class="cellrowborder" valign="top" width="50%" id="mcps1.2.3.1.1"><p id="p99801123205616"><a name="p99801123205616"></a><a name="p99801123205616"></a>Status (Value)</p>
        </th>
        <th class="cellrowborder" valign="top" width="50%" id="mcps1.2.3.1.2"><p id="p698092355615"><a name="p698092355615"></a><a name="p698092355615"></a>Description</p>
        </th>
        </tr>
        </thead>
        <tbody><tr id="row39803236568"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p8980123175613"><a name="p8980123175613"></a><a name="p8980123175613"></a>HDF_ERR_INVALID_OBJECT</p>
        </td>
        <td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p79801423165611"><a name="p79801423165611"></a><a name="p79801423165611"></a>Invalid controller object</p>
        </td>
        </tr>
        <tr id="row3980023165617"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p698011239568"><a name="p698011239568"></a><a name="p698011239568"></a>HDF_ERR_MALLOC_FAIL</p>
        </td>
        <td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p798082395610"><a name="p798082395610"></a><a name="p798082395610"></a>Failed to allocate memory</p>
        </td>
        </tr>
        <tr id="row10980223165610"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p1980172365614"><a name="p1980172365614"></a><a name="p1980172365614"></a>HDF_ERR_INVALID_PARAM</p>
        </td>
        <td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p14980223145614"><a name="p14980223145614"></a><a name="p14980223145614"></a>Invalid parameter</p>
        </td>
        </tr>
        <tr id="row7980142315612"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p17980152385611"><a name="p17980152385611"></a><a name="p17980152385611"></a>HDF_ERR_IO</p>
        </td>
        <td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p17980182385611"><a name="p17980182385611"></a><a name="p17980182385611"></a>I/O error</p>
        </td>
        </tr>
        <tr id="row9980122312564"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p10981323155616"><a name="p10981323155616"></a><a name="p10981323155616"></a>HDF_SUCCESS</p>
        </td>
        <td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p11981423175614"><a name="p11981423175614"></a><a name="p11981423175614"></a>Initialization successful</p>
        </td>
        </tr>
        <tr id="row15981122365618"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p19981122311567"><a name="p19981122311567"></a><a name="p19981122311567"></a>HDF_FAILURE</p>
        </td>
        <td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p199811723105615"><a name="p199811723105615"></a><a name="p199811723105615"></a>Initialization failed</p>
        </td>
        </tr>
        </tbody>
        </table>

        Function description:

        Initializes the custom structure object and  **UartHost**.

        ```
        //uart_hi35xx.c
        static int32_t HdfUartDeviceBind(struct HdfDeviceObject *device)
        {
            ...
            return (UartHostCreate(device) == NULL)? HDF_FAILURE: HDF_SUCCESS;// (Mandatory) Call UartHostCreate.
        }
        // Description of the UartHostCreate function at the core layer in uart_core.c
        struct UartHost *UartHostCreate(struct HdfDeviceObject *device)
        {
            struct UartHost *host = NULL; // Create a UartHost.
            ...
            host = (struct UartHost *)OsalMemCalloc(sizeof(*host));// Apply for memory.
            ...
             host->device = device;               // (Mandatory) Enable conversion between HdfDeviceObject and UartHost.
            device->service = &(host->service); // (Mandatory) Enable conversion between HdfDeviceObject and UartHost.
            host->device->service->Dispatch = UartIoDispatch;// Assign a value to the Dispatch method of service.
            OsalAtomicSet(&host->atom, 0); // Initialize or set atomic data.
            host->priv = NULL;
            host->method = NULL;
            return host;
        }
        ```

    -   Init function

        Input parameters:

        **HdfDeviceObject**, an interface parameter exposed by the driver, contains the .hcs configuration file information.

        Return values:

        HDF\_STATUS

        Function description:

        Initializes the custom structure object and  **UartHost**, calls the  **artAddDev**  function at the core layer, and connects to VFS.

        ```
        int32_t HdfUartDeviceInit(struct HdfDeviceObject *device)
        {
            int32_t ret;
            struct UartHost *host = NULL;
            HDF_LOGI("%s: entry", __func__);
            ...
            host = UartHostFromDevice(device);// Forcibly convert to UartHost by using service. The value is assigned in the Bind function.
            ...
            ret = Hi35xxAttach(host, device); // Initialize the UartHost object.
            ...
            host->method = &g_uartHostMethod; // Connect to the UARTHostMethod instance.
            return ret;
        }
        // Complete initialization of the UartHost object.
        static int32_t Hi35xxAttach(struct UartHost *host, struct HdfDeviceObject *device)
        {
            int32_t ret;
            // udd and port are structure objects customized by the vendor. The vendor needs to implement related functions as required.
            struct UartDriverData *udd = NULL;
            struct UartPl011Port *port = NULL;
            ...
            // Steps [1] to [7] assign values to udd and then to the UartHost object at the core layer.
            udd = (struct UartDriverData *)OsalMemCalloc(sizeof(*udd));// [1] 
            ...
            port = (struct UartPl011Port *)OsalMemCalloc(sizeof(struct UartPl011Port));// [2] 
            ...
            udd->ops = Pl011GetOps();// [3] Perform operations, such as starting or stopping a device, setting attributes, and sending data.
            udd->recv = PL011UartRecvNotify;// [4] Connect to the data receiving notification function (conditional lock mechanism).
            udd->count = 0;          // [5] 
           port->udd = udd;          // [6]  Enable conversion between UartPl011Port and UartDriverData.
             ret = UartGetConfigFromHcs(port, device->property);// (Mandatory) Transfer the attributes of HdfDeviceObject to the vendor custom structure.
                                                               // The sample code is as follows:
            ...
            udd->private = port;     // [7] 
            
            host->priv = udd; // (Mandatory) Enable conversion between UartHost and UartDriverData.
            host->num = udd->num;// (Mandatory) UART device number
            UartAddDev(host); // (Mandatory) Function in uart_dev.c at the core layer used to register a character device node with the VFS so that the UART can be accessed in user mode through this virtual file node.
            return HDF_SUCCESS;
        }
        
        static int32_t UartGetConfigFromHcs(struct UartPl011Port *port, const struct DeviceResourceNode *node)
        {
            uint32_t tmp, regPbase, iomemCount;
            struct UartDriverData *udd = port->udd;
            struct DeviceResourceIface *iface = DeviceResourceGetIfaceInstance(HDF_CONFIG_SOURCE); 
            ...
            // Extract the value based on the request parameter and assign the value to the vendor custom structure.
            if (iface->GetUint32(node, "num", &udd->num, 0) != HDF_SUCCESS) {
                HDF_LOGE("%s: read busNum fail", __func__);
                return HDF_FAILURE;
            }
            ...
            return 0;
            }
        ```

    -   Release function

        Input parameters:

        **HdfDeviceObject**, an interface parameter exposed by the driver, contains the .hcs configuration file information.

        Return values:

        –

        Function description:

        Releases the memory and deletes the controller. This function assigns a value to the  **Release**  API in the driver entry structure. When the HDF fails to call the  **Init**  function to initialize the driver, the  **Release**  function can be called to release driver resources. All forced conversion operations for obtaining the corresponding object can be successful only when the  **Init**  function has the corresponding value assignment operations.

        ```
        void HdfUartDeviceRelease(struct HdfDeviceObject *device)
        {
            struct UartHost *host = NULL;
            ...
            host = UartHostFromDevice(device);// Forcibly convert HdfDeviceObject to UartHost by using service. For details about the value assignment, see the Bind function.
            ...
            if (host->priv != NULL) {
                Hi35xxDetach(host); // Memory release function customized by the vendor. For details, see the following description.
            }
            UartHostDestroy(host); // Call the function of the core layer to release the host.
        }
        
        static void Hi35xxDetach(struct UartHost *host)
        {
            struct UartDriverData *udd = NULL;
            struct UartPl011Port *port = NULL;
            ...
            udd = host->priv; // Convert UartHost to UartDriverData.
            ...
            UartRemoveDev(host);// Remove the VFS.
            port = udd->private;// Convert UartDriverData to UartPl011Port.
            if (port != NULL) {
                if (port->physBase != 0) {
                    OsalIoUnmap((void *)port->physBase);// Remove address mapping.
                }
                (void)OsalMemFree(port);
                udd->private = NULL;
            }
            (void)OsalMemFree(udd);// Release UartDriverData.
            host->priv = NULL;
        }
        ```



