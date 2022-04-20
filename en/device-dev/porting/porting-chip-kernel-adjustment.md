# Basic Kernel Adaptation<a name="EN-US_TOPIC_0000001199842517"></a>

The LiteOS Cortex-M kernel provides the system initialization process and customized configuration options required for system running. During kernel porting, you must pay attention to the functions related to hardware configuration in the initialization process and understand the kernel configuration options so that the minimum kernel that matches the board can be tailored.

## Adaptation Process<a name="section14523241594"></a>

Basic adaptation consists of the following steps:

1.  Modify the code in the  **startup.S**  and corresponding link configuration files.
2.  Initialize the serial port and register the handler function for the tick interrupt response in the  **main.c**  file

**Figure  1**  Startup process<a name="fig10838105524917"></a>  


![](figures/startup-process.png)

In the  **startup.S**  file, you must ensure that the entry function \(for example,  **reset\_vector**\) of the interrupt vector table is stored in the RAM start address specified by the link configuration files. The link configuration files of IAR, Keil, and GCC projects are  **xxx.icf**,  **xxx.sct**, and  **xxx.ld**, respectively. The startup file provided by the vendor does not need to be modified if the  **startup.S**  file has initialized the system clock and returned to the  **main**  function. Otherwise, the preceding functions need to be implemented.

In the  **main.c**  file, you need to register the UartInit function used for initializing the serial port and the handler function used for the system tick.

-   The UartInit function initializes the board serial port, and the function name can be defined based on the board. This function is optional. You can determine whether to call it based on whether the board supports the serial port. If the board supports the serial port, this function must enable TX and RX channels of the serial port and set the baud rate.
-   You can call  **HalTickStart**  to set the  **OsTickHandler**  function for the tick interrupt response.

For the chip whose interrupt vector table cannot be redirected, you need to disable the  **LOSCFG\_PLATFORM\_HWI**  macro, and add the  **OsTickHandler**  function for the tick interrupt response in the  **startup.S**  file.

## Feature Configuration<a name="section112994366592"></a>

The  **los\_config.h**  file defines both complete configuration and default configuration of  **liteos\_m**. All configuration items in this file can be customized for different boards as required.

You can define configuration items in the  **device/xxxx/target\_config.h**  file of the corresponding board. For other undefined configuration items, default values in the  **los\_config.h**  file will be used.

The following table shows some typical configuration items:

**Table  1**  Typical configuration items

<a name="table1343954214199"></a>

<table><thead align="left"><tr id="row1244014425196"><th class="cellrowborder" valign="top" width="34.81%" id="mcps1.2.3.1.1"><p id="p1544044212197"><a name="p1544044212197"></a><a name="p1544044212197"></a>Item</p>
</th>
<th class="cellrowborder" valign="top" width="65.19%" id="mcps1.2.3.1.2"><p id="p7440194281913"><a name="p7440194281913"></a><a name="p7440194281913"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1944094221913"><td class="cellrowborder" valign="top" width="34.81%" headers="mcps1.2.3.1.1 "><p id="p84407426198"><a name="p84407426198"></a><a name="p84407426198"></a>LOSCFG_BASE_CORE_SWTMR</p>
</td>
<td class="cellrowborder" valign="top" width="65.19%" headers="mcps1.2.3.1.2 "><p id="p84408426194"><a name="p84408426194"></a><a name="p84408426194"></a>Switch of the software timer. The values <strong id="b10860112593720"><a name="b10860112593720"></a><a name="b10860112593720"></a>1</strong> and <strong id="b297273113393"><a name="b297273113393"></a><a name="b297273113393"></a>0</strong> indicate that the switch is turned on and turned off, respectively.</p>
</td>
</tr>
<tr id="row1225026133717"><td class="cellrowborder" valign="top" width="34.81%" headers="mcps1.2.3.1.1 "><p id="p725015663718"><a name="p725015663718"></a><a name="p725015663718"></a>LOSCFG_BASE_CORE_SWTMR_ALIGN</p>
</td>
<td class="cellrowborder" valign="top" width="65.19%" headers="mcps1.2.3.1.2 "><p id="p62502611378"><a name="p62502611378"></a><a name="p62502611378"></a>Switch of the time alignment feature, which depends on the switch status of the software timer. The values <strong id="b10462312174018"><a name="b10462312174018"></a><a name="b10462312174018"></a>1</strong> and <strong id="b3462151215403"><a name="b3462151215403"></a><a name="b3462151215403"></a>0</strong> indicate that the switch is turned on and turned off, respectively.</p>
</td>
</tr>
<tr id="row7440742191919"><td class="cellrowborder" valign="top" width="34.81%" headers="mcps1.2.3.1.1 "><p id="p19440134241919"><a name="p19440134241919"></a><a name="p19440134241919"></a>LOSCFG_BASE_IPC_MUX</p>
</td>
<td class="cellrowborder" valign="top" width="65.19%" headers="mcps1.2.3.1.2 "><p id="p1144017426191"><a name="p1144017426191"></a><a name="p1144017426191"></a>Switch of the mux feature. The values <strong id="b12108629184012"><a name="b12108629184012"></a><a name="b12108629184012"></a>1</strong> and <strong id="b510882954014"><a name="b510882954014"></a><a name="b510882954014"></a>0</strong> indicate that the switch is turned on and turned off, respectively.</p>
</td>
</tr>
<tr id="row3440642161918"><td class="cellrowborder" valign="top" width="34.81%" headers="mcps1.2.3.1.1 "><p id="p1144004261916"><a name="p1144004261916"></a><a name="p1144004261916"></a>LOSCFG_BASE_IPC_QUEUE</p>
</td>
<td class="cellrowborder" valign="top" width="65.19%" headers="mcps1.2.3.1.2 "><p id="p1644094201917"><a name="p1644094201917"></a><a name="p1644094201917"></a>Switch of the queue feature. The values <strong id="b1514814454405"><a name="b1514814454405"></a><a name="b1514814454405"></a>1</strong> and <strong id="b114824504011"><a name="b114824504011"></a><a name="b114824504011"></a>0</strong> indicate that the switch is turned on and turned off, respectively.</p>
</td>
</tr>
<tr id="row14294143784110"><td class="cellrowborder" valign="top" width="34.81%" headers="mcps1.2.3.1.1 "><p id="p529573794111"><a name="p529573794111"></a><a name="p529573794111"></a>LOSCFG_BASE_CORE_TSK_LIMIT</p>
</td>
<td class="cellrowborder" valign="top" width="65.19%" headers="mcps1.2.3.1.2 "><p id="p529503704116"><a name="p529503704116"></a><a name="p529503704116"></a>Maximum number of available tasks, excluding idle tasks. You can set this item based on your actual service requirements, or you can initially set it to a large value and adjust the value at a later time.</p>
</td>
</tr>
<tr id="row16440124216198"><td class="cellrowborder" valign="top" width="34.81%" headers="mcps1.2.3.1.1 "><p id="p9440184271915"><a name="p9440184271915"></a><a name="p9440184271915"></a>LOSCFG_BASE_IPC_SEM</p>
</td>
<td class="cellrowborder" valign="top" width="65.19%" headers="mcps1.2.3.1.2 "><p id="p1044024261912"><a name="p1044024261912"></a><a name="p1044024261912"></a>Switch of the semaphore feature. The values <strong id="b0766102114312"><a name="b0766102114312"></a><a name="b0766102114312"></a>1</strong> and <strong id="b1876612254312"><a name="b1876612254312"></a><a name="b1876612254312"></a>0</strong> indicate that the switch is turned on and turned off, respectively.</p>
</td>
</tr>
<tr id="row444064216197"><td class="cellrowborder" valign="top" width="34.81%" headers="mcps1.2.3.1.1 "><p id="p14441642121912"><a name="p14441642121912"></a><a name="p14441642121912"></a>LOSCFG_PLATFORM_EXC</p>
</td>
<td class="cellrowborder" valign="top" width="65.19%" headers="mcps1.2.3.1.2 "><p id="p13441154216198"><a name="p13441154216198"></a><a name="p13441154216198"></a>Switch of the exception feature. The values <strong id="b15509164154316"><a name="b15509164154316"></a><a name="b15509164154316"></a>1</strong> and <strong id="b1651024115436"><a name="b1651024115436"></a><a name="b1651024115436"></a>0</strong> indicate that the switch is turned on and turned off, respectively.</p>
</td>
</tr>
<tr id="row744111422199"><td class="cellrowborder" valign="top" width="34.81%" headers="mcps1.2.3.1.1 "><p id="p19441942111910"><a name="p19441942111910"></a><a name="p19441942111910"></a>LOSCFG_KERNEL_PRINTF</p>
</td>
<td class="cellrowborder" valign="top" width="65.19%" headers="mcps1.2.3.1.2 "><p id="p1744115424197"><a name="p1744115424197"></a><a name="p1744115424197"></a>Switch of the print feature. The values <strong id="b71401245104416"><a name="b71401245104416"></a><a name="b71401245104416"></a>1</strong> and <strong id="b141401545194417"><a name="b141401545194417"></a><a name="b141401545194417"></a>0</strong> indicate that the switch is turned on and turned off, respectively.</p>
</td>
</tr>
</tbody>
</table>

