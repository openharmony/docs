# GPIO<a name="EN-US_TOPIC_0000001153555758"></a>

## Overview<a name="section1826197354103451"></a>

In the Hardware Driver Foundation \(HDF\) framework, the general-purpose input/output \(GPIO\) module uses the service-free mode for API adaptation. The service-free mode applies to the devices that do not provide user-mode APIs or the OS system that does not distinguish the user mode and the kernel mode. In the service-free mode, **DevHandle** \(a void pointer\) directly points to the kernel-mode address of the device object.

**Figure  1** Service-free mode<a name="fig5511033193814"></a>  
![](figures/service-free-mode.png "service-free-mode")

## Available APIs<a name="section752964871810"></a>

GpioMethod

```
struct GpioMethod {
  int32_t (*request)(struct GpioCntlr *cntlr, uint16_t local);// Reserved
  int32_t (*release)(struct GpioCntlr *cntlr, uint16_t local);// Reserved
  int32_t (*write)(struct GpioCntlr *cntlr, uint16_t local, uint16_t val);
  int32_t (*read)(struct GpioCntlr *cntlr, uint16_t local, uint16_t *val);
  int32_t (*setDir)(struct GpioCntlr *cntlr, uint16_t local, uint16_t dir);
  int32_t (*getDir)(struct GpioCntlr *cntlr, uint16_t local, uint16_t *dir);
  int32_t (*toIrq)(struct GpioCntlr *cntlr, uint16_t local, uint16_t *irq);// Reserved
  int32_t (*setIrq)(struct GpioCntlr *cntlr, uint16_t local, uint16_t mode, GpioIrqFunc func, void *arg);
  int32_t (*unsetIrq)(struct GpioCntlr *cntlr, uint16_t local);
  int32_t (*enableIrq)(struct GpioCntlr *cntlr, uint16_t local);
  int32_t (*disableIrq)(struct GpioCntlr *cntlr, uint16_t local);
}
```
**Table  1** Callbacks for the members in the GpioMethod structure

<a name="table151341544111"></a>
<table><thead align="left"><tr id="row19514101504111"><th class="cellrowborder" align="center" valign="top" width="20%" id="mcps1.2.6.1.1"><p id="p451461513418"><a name="p451461513418"></a><a name="p451461513418"></a>Callback</p>
</th>
<th class="cellrowborder" valign="top" width="20%" id="mcps1.2.6.1.2"><p id="p32641283426"><a name="p32641283426"></a><a name="p32641283426"></a>Input Parameter</p>
</th>
<th class="cellrowborder" valign="top" width="20%" id="mcps1.2.6.1.3"><p id="p55141515134111"><a name="p55141515134111"></a><a name="p55141515134111"></a>Output Parameter</p>
</th>
<th class="cellrowborder" valign="top" width="20%" id="mcps1.2.6.1.4"><p id="p5514171514114"><a name="p5514171514114"></a><a name="p5514171514114"></a>Return Value</p>
</th>
<th class="cellrowborder" valign="top" width="20%" id="mcps1.2.6.1.5"><p id="p155141215124113"><a name="p155141215124113"></a><a name="p155141215124113"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row195141715164110"><td class="cellrowborder" align="center" valign="top" width="20%" headers="mcps1.2.6.1.1 "><p id="p145141015144110"><a name="p145141015144110"></a><a name="p145141015144110"></a>write</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.2 "><p id="p453215451206"><a name="p453215451206"></a><a name="p453215451206"></a><strong id="b1053114522014"><a name="b1053114522014"></a><a name="b1053114522014"></a>cntlr</strong>: structure pointer to the GPIO controller at the core layer.</p>
<p id="p116571249112015"><a name="p116571249112015"></a><a name="p116571249112015"></a><strong id="b8657144913202"><a name="b8657144913202"></a><a name="b8657144913202"></a>local</strong>: GPIO port number, which is of the uint16_t type.</p>
<p id="p1351421512414"><a name="p1351421512414"></a><a name="p1351421512414"></a><strong id="b1861811201459"><a name="b1861811201459"></a><a name="b1861811201459"></a>val</strong>: input level value, which is of the uint16_t type.</p>
</td>
<td class="cellrowborder" align="left" valign="top" width="20%" headers="mcps1.2.6.1.3 "><p id="p8514715124111"><a name="p8514715124111"></a><a name="p8514715124111"></a>–</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.4 "><p id="p14514161554118"><a name="p14514161554118"></a><a name="p14514161554118"></a>HDF_STATUS</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.5 "><p id="p155148151416"><a name="p155148151416"></a><a name="p155148151416"></a>Writes the level of a GPIO pin.</p>
</td>
</tr>
<tr id="row185141415174112"><td class="cellrowborder" align="center" valign="top" width="20%" headers="mcps1.2.6.1.1 "><p id="p1151520153413"><a name="p1151520153413"></a><a name="p1151520153413"></a>read</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.2 "><p id="p139611135152114"><a name="p139611135152114"></a><a name="p139611135152114"></a><strong id="b4961435162120"><a name="b4961435162120"></a><a name="b4961435162120"></a>cntlr</strong>: structure pointer to the GPIO controller at the core layer.</p>
<p id="p1451581512410"><a name="p1451581512410"></a><a name="p1451581512410"></a><strong id="b12610253913"><a name="b12610253913"></a><a name="b12610253913"></a>local</strong>: GPIO port number, which is of the uint16_t type.</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.3 "><p id="p19515415134113"><a name="p19515415134113"></a><a name="p19515415134113"></a><strong id="b5968229295"><a name="b5968229295"></a><a name="b5968229295"></a>val</strong>: pointer to the output level value, which is of the uint16_t type.</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.4 "><p id="p1051591564115"><a name="p1051591564115"></a><a name="p1051591564115"></a>HDF_STATUS</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.5 "><p id="p185151715184112"><a name="p185151715184112"></a><a name="p185151715184112"></a>Reads the level of a GPIO pin.</p>
</td>
</tr>
<tr id="row4515111512414"><td class="cellrowborder" align="center" valign="top" width="20%" headers="mcps1.2.6.1.1 "><p id="p125152152412"><a name="p125152152412"></a><a name="p125152152412"></a>setDir</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.2 "><p id="p5579168142212"><a name="p5579168142212"></a><a name="p5579168142212"></a><strong id="b357928112218"><a name="b357928112218"></a><a name="b357928112218"></a>cntlr</strong>: structure pointer to the GPIO controller at the core layer.</p>
<p id="p1465781110227"><a name="p1465781110227"></a><a name="p1465781110227"></a><strong id="b4657711182217"><a name="b4657711182217"></a><a name="b4657711182217"></a>local</strong>: GPIO port number, which is of the uint16_t type.</p>
<p id="p1551521584114"><a name="p1551521584114"></a><a name="p1551521584114"></a><strong id="b1172125431011"><a name="b1172125431011"></a><a name="b1172125431011"></a>dir</strong>: input pin direction, which is of the uint16_t type.</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.3 "><p id="p1351541517413"><a name="p1351541517413"></a><a name="p1351541517413"></a>–</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.4 "><p id="p251551515419"><a name="p251551515419"></a><a name="p251551515419"></a>HDF_STATUS</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.5 "><p id="p1351501516419"><a name="p1351501516419"></a><a name="p1351501516419"></a>Sets the input or output direction for a GPIO pin.</p>
</td>
</tr>
<tr id="row10515161517417"><td class="cellrowborder" align="center" valign="top" width="20%" headers="mcps1.2.6.1.1 "><p id="p135151015154114"><a name="p135151015154114"></a><a name="p135151015154114"></a>getDir</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.2 "><p id="p14901244112218"><a name="p14901244112218"></a><a name="p14901244112218"></a><strong id="b1689844182212"><a name="b1689844182212"></a><a name="b1689844182212"></a>cntlr</strong>: structure pointer to the GPIO controller at the core layer.</p>
<p id="p1351531519411"><a name="p1351531519411"></a><a name="p1351531519411"></a><strong id="b171715420138"><a name="b171715420138"></a><a name="b171715420138"></a>local</strong>: GPIO port number, which is of the uint16_t type.</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.3 "><p id="p15515141554120"><a name="p15515141554120"></a><a name="p15515141554120"></a><strong id="b12246123210138"><a name="b12246123210138"></a><a name="b12246123210138"></a>dir</strong>: pointer to the output pin direction, which is of the uint16_t type.</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.4 "><p id="p651531574110"><a name="p651531574110"></a><a name="p651531574110"></a>HDF_STATUS</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.5 "><p id="p1551620153418"><a name="p1551620153418"></a><a name="p1551620153418"></a>Obtains the input or output direction of a GPIO pin.</p>
</td>
</tr>
<tr id="row2051616153411"><td class="cellrowborder" align="center" valign="top" width="20%" headers="mcps1.2.6.1.1 "><p id="p13516171517412"><a name="p13516171517412"></a><a name="p13516171517412"></a>setIrq</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.2 "><p id="p139141552310"><a name="p139141552310"></a><a name="p139141552310"></a><strong id="b1791313562318"><a name="b1791313562318"></a><a name="b1791313562318"></a>cntlr</strong>: structure pointer to the GPIO controller at the core layer.</p>
<p id="p1939331118235"><a name="p1939331118235"></a><a name="p1939331118235"></a><strong id="b839319111238"><a name="b839319111238"></a><a name="b839319111238"></a>local</strong>: GPIO port number, which is of the uint16_t type.</p>
<p id="p81051177235"><a name="p81051177235"></a><a name="p81051177235"></a><strong id="b6105141718231"><a name="b6105141718231"></a><a name="b6105141718231"></a>mode</strong>: triggering mode, which can be <strong id="b11105517102314"><a name="b11105517102314"></a><a name="b11105517102314"></a>edge</strong> or <strong id="b1210501711237"><a name="b1210501711237"></a><a name="b1210501711237"></a>level</strong>. The value is of the uint16_t type.</p>
<p id="p24421624172315"><a name="p24421624172315"></a><a name="p24421624172315"></a><strong id="b9442524112316"><a name="b9442524112316"></a><a name="b9442524112316"></a>func</strong>: function pointer to the interrupt service handler.</p>
<p id="p251619154417"><a name="p251619154417"></a><a name="p251619154417"></a><strong id="b33689285172"><a name="b33689285172"></a><a name="b33689285172"></a>arg</strong>: void pointer to the input parameters of the interrupt service handler.</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.3 "><p id="p1851631524118"><a name="p1851631524118"></a><a name="p1851631524118"></a>–</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.4 "><p id="p1551691512413"><a name="p1551691512413"></a><a name="p1551691512413"></a>HDF_STATUS</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.5 "><p id="p351615157411"><a name="p351615157411"></a><a name="p351615157411"></a>Sets an interrupt request (IRQ) for a GPIO pin.</p>
</td>
</tr>
<tr id="row135161157417"><td class="cellrowborder" align="center" valign="top" width="20%" headers="mcps1.2.6.1.1 "><p id="p551631515418"><a name="p551631515418"></a><a name="p551631515418"></a>unsetIrq</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.2 "><p id="p5931131516250"><a name="p5931131516250"></a><a name="p5931131516250"></a><strong id="b119311215162517"><a name="b119311215162517"></a><a name="b119311215162517"></a>cntlr</strong>: structure pointer to the GPIO controller at the core layer.</p>
<p id="p155164152415"><a name="p155164152415"></a><a name="p155164152415"></a><strong id="b1330123517188"><a name="b1330123517188"></a><a name="b1330123517188"></a>local</strong>: GPIO port number, which is of the uint16_t type.</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.3 "><p id="p8516161519416"><a name="p8516161519416"></a><a name="p8516161519416"></a>–</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.4 "><p id="p4516415124119"><a name="p4516415124119"></a><a name="p4516415124119"></a>HDF_STATUS</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.5 "><p id="p451671594110"><a name="p451671594110"></a><a name="p451671594110"></a>Cancels the GPIO interrupt settings.</p>
</td>
</tr>
<tr id="row55161015134117"><td class="cellrowborder" align="center" valign="top" width="20%" headers="mcps1.2.6.1.1 "><p id="p165161153415"><a name="p165161153415"></a><a name="p165161153415"></a>enableIrq</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.2 "><p id="p87941124269"><a name="p87941124269"></a><a name="p87941124269"></a><strong id="b979421272616"><a name="b979421272616"></a><a name="b979421272616"></a>cntlr</strong>: structure pointer to the GPIO controller at the core layer.</p>
<p id="p85164158418"><a name="p85164158418"></a><a name="p85164158418"></a><strong id="b1046612112256"><a name="b1046612112256"></a><a name="b1046612112256"></a>local</strong>: GPIO port number, which is of the uint16_t type.</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.3 "><p id="p13517181584114"><a name="p13517181584114"></a><a name="p13517181584114"></a>–</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.4 "><p id="p1251711518412"><a name="p1251711518412"></a><a name="p1251711518412"></a>HDF_STATUS</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.5 "><p id="p65172015124114"><a name="p65172015124114"></a><a name="p65172015124114"></a>Enables an interrupt for a GPIO pin.</p>
</td>
</tr>
<tr id="row125171915154119"><td class="cellrowborder" align="center" valign="top" width="20%" headers="mcps1.2.6.1.1 "><p id="p155173157418"><a name="p155173157418"></a><a name="p155173157418"></a>disableIrq</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.2 "><p id="p352101419274"><a name="p352101419274"></a><a name="p352101419274"></a><strong id="b052141472711"><a name="b052141472711"></a><a name="b052141472711"></a>cntlr</strong>: structure pointer to the GPIO controller at the core layer.</p>
<p id="p16517191544119"><a name="p16517191544119"></a><a name="p16517191544119"></a><strong id="b1173395802511"><a name="b1173395802511"></a><a name="b1173395802511"></a>local</strong>: GPIO port number, which is of the uint16_t type.</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.3 "><p id="p1751751544113"><a name="p1751751544113"></a><a name="p1751751544113"></a>–</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.4 "><p id="p11517515164117"><a name="p11517515164117"></a><a name="p11517515164117"></a>HDF_STATUS</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.5 "><p id="p15517191534112"><a name="p15517191534112"></a><a name="p15517191534112"></a>Disables an interrupt for a GPIO pin.</p>
</td>
</tr>
</tbody>
</table>

## How to Develop<a name="section731175315103451"></a>

The GPIO controller manages all pins by group. The related parameters are described in the attribute file. Instantiating the driver entry and API functions is the core for the vendor driver to access the HDF.

The GPIO module adaptation involves the following steps: 

1.  Instantiate the driver entry.
    -   Instantiate the **HdfDriverEntry** structure.
    -   Call **HDF\_INIT** to register the **HdfDriverEntry** instance with the HDF framework.

2.  Configure attribute files.
    -   Add the **deviceNode** information to the **device\_info.hcs** file.
    -   \(Optional\) Add the **gpio\_config.hcs** file.

3.  Instantiate the GPIO controller object.
    -   Initialize **GpioCntlr**.
    -   Instantiate **GpioMethod** in the **GpioCntlr** object.

        For details, see [Available APIs](#section752964871810).
	
4.  \(Optional\) Debug the driver.
    For new drivers, verify the basic functions, such as the GPIO control status and response to interrupts.


## Development Example<a name="section800425816103451"></a>

The following uses **gpio\_hi35xx.c** as an example to present the contents that need to be provided by the vendor to implement device functions.

1.  Instantiate the driver entry. The driver entry must be a global variable of the **HdfDriverEntry** type \(defined in **hdf\_device\_desc.h**\), and the value of **moduleName** must be the same as that in **device\_info.hcs**. In the HDF framework, the start address of each **HdfDriverEntry** object of all loaded drivers is collected to form a segment address space similar to an array for the upper layer to invoke.

    Generally, HDF calls the **Bind** function and then the **Init** function to load a driver. If **Init** fails to be called, HDF calls **Release** to release driver resources and exits.

    -   GPIO driver entry reference

        ```
        struct HdfDriverEntry g_gpioDriverEntry = {
          .moduleVersion = 1,
          .Bind = Pl061GpioBind, // Bind does not need to be implemented for GPIO. In this example, the implementation is empty. Vendors can add related operations as required.
          .Init = Pl061GpioInit,            // See the Init function.
           .Release = Pl061GpioRelease,      // See the Release function.
          .moduleName = "hisi_pl061_driver",// (Mandatory) The value must be the same as that of moduleName in the .hcs file.
        };
        // Call HDF_INIT to register the driver entry with the HDF framework.
        HDF_INIT(g_gpioDriverEntry);
        ```

2.  Add the **deviceNode** information to the **device\_info.hcs** file and configure the device attributes in the **gpio\_config.hcs** file. The **deviceNode** information is related to registration of the driver entry. The device attribute values are closely related to the default values or value ranges of the **GpioCntlr** members at the core layer.

    In this example, there is only one GPIO controller. If there are multiple GPIO controllers, you need to add the **deviceNode** information to the **device\_info** file and add the corresponding device attributes to the **gpio\_config** file.

    -  **device\_info.hcs** configuration reference

        ```
        root {
        device_info {
            platform :: host {
            hostName = "platform_host";
            priority = 50;
            device_gpio :: device {
                device0 :: deviceNode {
         policy = 0; // The value 0 indicates that no service needs to be published.
         priority = 10; // Driver startup priority
         permission = 0644; // Permission to create device nodes for the driver
                moduleName = "hisi_pl061_driver";         // (Mandatory) Driver name, which must be the same as the moduleName in the driver entry.
                  deviceMatchAttr = "hisilicon_hi35xx_pl061";// (Mandatory) Used to configure the private data of the controller. The value must be the same as the controller information in gpio_config.hcs.
                                                            // The controller information must be consistent. Other controller information is also contained in the file.
                }
            }
            }
        }
        }
        ```

    -  **gpio\_config.hcs** configuration reference

        ```
        root {
        platform {
            gpio_config {
            controller_0x120d0000 {
                match_attr = "hisilicon_hi35xx_pl061"; // (Mandatory) The value must be the same as that of deviceMatchAttr in device_info.hcs.
                groupNum = 12; // (Mandatory) GPIO group index
                bitNum = 8; // (Mandatory) Number of GPIO pins in each group
                regBase = 0x120d0000;// (Mandatory) Physical base address
                regStep = 0x1000; // (Mandatory) Register offset step
                irqStart = 48; // (Mandatory) Start an IRQ.
                irqShare = 0; // (Mandatory) Share the IRQ.
            }
            }
        }
        } 
        ```

3.  Initialize the **GpioCntlr** object at the core layer, including initializing the vendor custom structure \(transferring parameters and data\), instantiating **GpioMethod** \(used to call underlying functions of the driver\) in **GpioCntlr**, and implementing the **HdfDriverEntry** member functions \(**Bind**, **Init**, and **Release**\).
    -   Custom structure reference

        To the driver, the custom structure carries parameters and data. The values in the **gpio\_config.hcs** file are read by HDF, and the structure members are initialized through **DeviceResourceIface**. Some important values, such as the index and the number of pins, are also passed to the **GpioCntlr** object at the core layer.

        ```
        struct Pl061GpioCntlr {
          struct GpioCntlr cntlr;// (Mandatory) Control object of the core layer. For details about the member definitions, see the following description.
            volatile unsigned char  *regBase; // (Mandatory) Base address of the register
          uint32_t phyBase; // (Mandatory) Physical base address
          uint32_t regStep;  // (Mandatory) Register offset step
          uint32_t irqStart; // (Mandatory) Start an IRQ.
          uint16_t groupNum; // (Mandatory) GPIO port number
          uint16_t bitNum; // (Mandatory) GPIO port number
          uint8_t irqShare; // (Mandatory) Share the IRQ.
          struct Pl061GpioGroup *groups; // (Optional) Set based on the vendor's requirements.
        };
        struct Pl061GpioGroup {// Register address, interrupt number, interrupt function, and lock
          volatile unsigned char *regBase;
          unsigned int index;
          unsigned int irq;
          OsalIRQHandle irqFunc;
          OsalSpinlock lock;
        };
        
        // GpioCntlr is the controller structure at the core layer. Its members are assigned with values by using the Init function.
        struct GpioCntlr {
          struct IDeviceIoService service;
          struct HdfDeviceObject *device;
          struct GpioMethod *ops;
          struct DListHead list;
          OsalSpinlock spin;
          uint16_t start;
          uint16_t count;
          struct GpioInfo *ginfos;
          void *priv;
        };
        ```

    -   Instantiate the callback function structure **GpioMethod** in **GpioCntlr**. Other members are initialized by using the **Init** function.

        ```
        // The members of the GpioMethod structure are all callbacks. Vendors need to implement the corresponding functions according to [Table 1](#table151341544111).
        static struct GpioMethod g_method = {
            .request = NULL,
            .release = NULL,
            .write = Pl061GpioWrite, // Write pin settings.
            .read = Pl061GpioRead, // Read pin settings.
            .setDir = Pl061GpioSetDir, // Set the pin direction.
            .getDir = Pl061GpioGetDir, // Obtain the pin direction.
            .toIrq = NULL,
            .setIrq = Pl061GpioSetIrq, // Set an interrupt for the pin. If this capability is not available, skip it.
            .unsetIrq = Pl061GpioUnsetIrq, // Cancel the interrupt settings for the pin. If this capability is not available, skip it.
            .enableIrq = Pl061GpioEnableIrq,  // Enable an interrupt for the pin. If this capability is not available, skip it.
            .disableIrq = Pl061GpioDisableIrq,// Disable the interrupt for the pin. If this capability is not available, skip it. 
        };
        ```



-   Init function

    Input parameters:

   **HdfDeviceObject**, an interface parameter exposed by the driver, contains the .hcs configuration file information.

    Return values:

    HDF\_STATUS \(The following table lists some status. For details about other status, see **HDF\_STATUS** in the **//drivers/framework/include/utils/hdf\_base.h** file.\)

   **Table  2** Init function description

    <a name="table165981547354"></a>
    <table><thead align="left"><tr id="row8599145423516"><th class="cellrowborder" valign="top" width="50%" id="mcps1.2.3.1.1"><p id="p959995453515"><a name="p959995453515"></a><a name="p959995453515"></a>Status (Value)</p>
    </th>
    <th class="cellrowborder" valign="top" width="50%" id="mcps1.2.3.1.2"><p id="p185991854163519"><a name="p185991854163519"></a><a name="p185991854163519"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row13599195483515"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p125993545359"><a name="p125993545359"></a><a name="p125993545359"></a>HDF_ERR_INVALID_OBJECT</p>
    </td>
    <td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p125991454153519"><a name="p125991454153519"></a><a name="p125991454153519"></a>Invalid controller object</p>
    </td>
    </tr>
    <tr id="row35997541354"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p19600454153511"><a name="p19600454153511"></a><a name="p19600454153511"></a>HDF_ERR_MALLOC_FAIL</p>
    </td>
    <td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p1600145423514"><a name="p1600145423514"></a><a name="p1600145423514"></a>Failed to allocate memory</p>
    </td>
    </tr>
    <tr id="row9600155423514"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p146001546357"><a name="p146001546357"></a><a name="p146001546357"></a>HDF_ERR_INVALID_PARAM</p>
    </td>
    <td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p10600754133512"><a name="p10600754133512"></a><a name="p10600754133512"></a>Invalid parameter</p>
    </td>
    </tr>
    <tr id="row146001254143516"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p66007542357"><a name="p66007542357"></a><a name="p66007542357"></a>HDF_ERR_IO</p>
    </td>
    <td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p2600135416357"><a name="p2600135416357"></a><a name="p2600135416357"></a>I/O error</p>
    </td>
    </tr>
    <tr id="row36001544351"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p660095417357"><a name="p660095417357"></a><a name="p660095417357"></a>HDF_SUCCESS</p>
    </td>
    <td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p17600165411353"><a name="p17600165411353"></a><a name="p17600165411353"></a>Initialization successful</p>
    </td>
    </tr>
    <tr id="row14600154103518"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p46001544356"><a name="p46001544356"></a><a name="p46001544356"></a>HDF_FAILURE</p>
    </td>
    <td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p160035415356"><a name="p160035415356"></a><a name="p160035415356"></a>Initialization failed</p>
    </td>
    </tr>
    </tbody>
    </table>

    Function description:

    Initializes the custom structure object and **GpioCntlr**, calls the **GpioCntlrAdd** function at the core layer, and connects to the VFS \(optional\).

    ```
    static int32_t Pl061GpioInit(struct HdfDeviceObject *device)
    {
      ...
     struct Pl061GpioCntlr *pl061 = &g_pl061;// Use static global variables to complete initialization.
                                              //static struct Pl061GpioCntlr g_pl061 = {
                                              //    .groups = NULL,
                                              //    .groupNum = PL061_GROUP_MAX,
                                              //    .bitNum = PL061_BIT_MAX,
                                              //};
       ret = Pl061GpioReadDrs(pl061, device->property);// Use the attribute values read from the gpio_config.HCS file to initialize the members of the custom structure object.
      ...
      pl061->regBase = OsalIoRemap(pl061->phyBase, pl061->groupNum * pl061->regStep);// Address mapping
      ...
      ret = Pl061GpioInitCntlrMem(pl061); // Apply for memory.
      ...
      pl061->cntlr.count = pl061->groupNum x pl061->bitNum;// (Mandatory) Calculate the number of pins.
      pl061->cntlr.priv = (void *)device->property; // (Mandatory) Store device attributes.
      pl061->cntlr.ops = &g_method;      // (Mandatory) Connect to the GpioMethod instance.
       pl061->cntlr.device = device;  // (Mandatory) Enable conversion between HdfDeviceObject and GpioCntlr.
    ret = GpioCntlrAdd(&pl061->cntlr);    // (Mandatory) Call this function to set the structure of the core layer. The driver accesses the platform core layer only after a success signal is returned.
      ...
      Pl061GpioDebugCntlr(pl061);
      #ifdef PL061_GPIO_USER_SUPPORT // (Optional) Access the user-level virtual file system if supported.
      if (GpioAddVfs(pl061->bitNum) != HDF_SUCCESS) {
          HDF_LOGE("%s: add vfs fail!", __func__);
      }
      #endif
      ...
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
        static void Pl061GpioRelease(struct HdfDeviceObject *device)
        {
           struct GpioCntlr *cntlr = NULL;
           struct Pl061GpioCntlr *pl061 = NULL;
           ...
           cntlr = GpioCntlrFromDevice(device);// (Mandatory) Obtain the control object of the core layer through forced conversion.
                                               //return (device == NULL) ? NULL : (struct GpioCntlr *)device->service;
           ...
           #ifdef PL061_GPIO_USER_SUPPORT
           GpioRemoveVfs();// Perform operations reverse to GpioAddVfs in Init.
           #endif
           GpioCntlrRemove(cntlr);             // (Mandatory) Remove the device information and services from the core layer.
           pl061 = ToPl061GpioCntlr(cntlr);    //return (struct Pl061GpioCntlr *)cntlr;
           Pl061GpioRleaseCntlrMem(pl061);     // (Mandatory) Release the lock and memory.
           OsalIoUnmap((void *)pl061->regBase);// (Mandatory) Remove the address mapping.
           pl061->regBase = NULL;
        }
        ```