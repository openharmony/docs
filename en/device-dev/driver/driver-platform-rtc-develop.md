# RTC<a name="EN-US_TOPIC_0000001153785954"></a>

## Overview<a name="section509989381142407"></a>

In the Hardware Driver Foundation \(HDF\) framework, the real-time clock \(RTC\) uses the independent service mode for API adaptation. In this mode, each device independently publishes a device service to handle external access requests. After receiving an access request from an API, the device manager extracts the parameters in the request to call the internal method of the target device. In the independent service mode, the service management capabilities of the HDFDeviceManager can be directly used. However, you need to configure a device node for each device, which increases the memory usage.

**Figure  1**  Independent service mode<a name="fig6742142611299"></a>  
![](figures/independent-service-mode.png "independent-service-mode-11")

## Available APIs<a name="section752964871810"></a>

RtcMethod

```
struct RtcMethod {
    int32_t (*ReadTime)(struct RtcHost *host, struct RtcTime *time);
    int32_t (*WriteTime)(struct RtcHost *host, const struct RtcTime *time);
    int32_t (*ReadAlarm)(struct RtcHost *host, enum RtcAlarmIndex alarmIndex, struct RtcTime *time);
    int32_t (*WriteAlarm)(struct RtcHost *host, enum RtcAlarmIndex alarmIndex, const struct RtcTime *time);
    int32_t (*RegisterAlarmCallback)(struct RtcHost *host, enum RtcAlarmIndex alarmIndex, RtcAlarmCallback cb);
    int32_t (*AlarmInterruptEnable)(struct RtcHost *host, enum RtcAlarmIndex alarmIndex, uint8_t enable);
    int32_t (*GetFreq)(struct RtcHost *host, uint32_t *freq);
    int32_t (*SetFreq)(struct RtcHost *host, uint32_t freq);
    int32_t (*Reset)(struct RtcHost *host);
    int32_t (*ReadReg)(struct RtcHost *host, uint8_t usrDefIndex, uint8_t *value);
    int32_t (*WriteReg)(struct RtcHost *host, uint8_t usrDefIndex, uint8_t value);
};
```

**Table  1**  Callbacks for the members in the RtcMethod structure

<a name="table12929217311"></a>
<table><thead align="left"><tr id="row293621203111"><th class="cellrowborder" valign="top" width="20%" id="mcps1.2.6.1.1"><p id="p15932212314"><a name="p15932212314"></a><a name="p15932212314"></a>Callback</p>
</th>
<th class="cellrowborder" valign="top" width="20%" id="mcps1.2.6.1.2"><p id="p1193421113111"><a name="p1193421113111"></a><a name="p1193421113111"></a>Input Parameter</p>
</th>
<th class="cellrowborder" valign="top" width="20%" id="mcps1.2.6.1.3"><p id="p179312214317"><a name="p179312214317"></a><a name="p179312214317"></a>Output Parameter</p>
</th>
<th class="cellrowborder" valign="top" width="20%" id="mcps1.2.6.1.4"><p id="p993521163113"><a name="p993521163113"></a><a name="p993521163113"></a>Return Value</p>
</th>
<th class="cellrowborder" valign="top" width="20%" id="mcps1.2.6.1.5"><p id="p5931821123115"><a name="p5931821123115"></a><a name="p5931821123115"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1093521113114"><td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.1 "><p id="p14941421163112"><a name="p14941421163112"></a><a name="p14941421163112"></a>ReadTime</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.2 "><p id="p094112118314"><a name="p094112118314"></a><a name="p094112118314"></a><strong id="b1264214345404"><a name="b1264214345404"></a><a name="b1264214345404"></a>host</strong>: structure pointer to the RTC controller at the core layer.</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.3 "><p id="p19945219318"><a name="p19945219318"></a><a name="p19945219318"></a><strong id="b6902125819406"><a name="b6902125819406"></a><a name="b6902125819406"></a>time</strong>: structure pointer to the output time value.</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.4 "><p id="p20941021143120"><a name="p20941021143120"></a><a name="p20941021143120"></a>HDF_STATUS</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.5 "><p id="p094132115317"><a name="p094132115317"></a><a name="p094132115317"></a>Reads the RTC time information.</p>
</td>
</tr>
<tr id="row199472183111"><td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.1 "><p id="p69418214318"><a name="p69418214318"></a><a name="p69418214318"></a>WriteTime</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.2 "><p id="p10306227052"><a name="p10306227052"></a><a name="p10306227052"></a><strong id="b1330617271556"><a name="b1330617271556"></a><a name="b1330617271556"></a>host</strong>: structure pointer to the RTC controller at the core layer.</p>
<p id="p89418214311"><a name="p89418214311"></a><a name="p89418214311"></a><strong id="b1411813377426"><a name="b1411813377426"></a><a name="b1411813377426"></a>time</strong>: structure pointer to the input time.</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.3 "><p id="p3944214314"><a name="p3944214314"></a><a name="p3944214314"></a>–</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.4 "><p id="p1194321113112"><a name="p1194321113112"></a><a name="p1194321113112"></a>HDF_STATUS</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.5 "><p id="p5941521123118"><a name="p5941521123118"></a><a name="p5941521123118"></a>Writes the RTC time information (from milliseconds to years).</p>
</td>
</tr>
<tr id="row4941521113111"><td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.1 "><p id="p19462119319"><a name="p19462119319"></a><a name="p19462119319"></a>ReadAlarm</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.2 "><p id="p1362015341251"><a name="p1362015341251"></a><a name="p1362015341251"></a><strong id="b14620934553"><a name="b14620934553"></a><a name="b14620934553"></a>host</strong>: structure pointer to the RTC controller at the core layer.</p>
<p id="p9951721113113"><a name="p9951721113113"></a><a name="p9951721113113"></a><strong id="b477221417458"><a name="b477221417458"></a><a name="b477221417458"></a>alarmIndex</strong>: clock alarm index, which is an enumerated value.</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.3 "><p id="p1995921113112"><a name="p1995921113112"></a><a name="p1995921113112"></a><strong id="b0371144014414"><a name="b0371144014414"></a><a name="b0371144014414"></a>time</strong>: structure pointer to the output time.</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.4 "><p id="p10951721133115"><a name="p10951721133115"></a><a name="p10951721133115"></a>HDF_STATUS</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.5 "><p id="p14951121193113"><a name="p14951121193113"></a><a name="p14951121193113"></a>Reads the RTC alarm time.</p>
</td>
</tr>
<tr id="row6957211313"><td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.1 "><p id="p129517219311"><a name="p129517219311"></a><a name="p129517219311"></a>WriteAlarm</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.2 "><p id="p136914402055"><a name="p136914402055"></a><a name="p136914402055"></a><strong id="b176918401258"><a name="b176918401258"></a><a name="b176918401258"></a>host</strong>: structure pointer to the RTC controller at the core layer.</p>
<p id="p11512468517"><a name="p11512468517"></a><a name="p11512468517"></a><strong id="b195114613519"><a name="b195114613519"></a><a name="b195114613519"></a>alarmIndex</strong>: clock alarm index, which is an enumerated value.</p>
<p id="p595152114315"><a name="p595152114315"></a><a name="p595152114315"></a><strong id="b1892302045019"><a name="b1892302045019"></a><a name="b1892302045019"></a>time</strong>: structure pointer to the input time.</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.3 "><p id="p16951321203115"><a name="p16951321203115"></a><a name="p16951321203115"></a>–</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.4 "><p id="p195321113116"><a name="p195321113116"></a><a name="p195321113116"></a>HDF_STATUS</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.5 "><p id="p1095122163116"><a name="p1095122163116"></a><a name="p1095122163116"></a>Writes the RTC alarm time.</p>
</td>
</tr>
<tr id="row1495021173112"><td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.1 "><p id="p795421193118"><a name="p795421193118"></a><a name="p795421193118"></a>RegisterAlarmCallback</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.2 "><p id="p7793145219520"><a name="p7793145219520"></a><a name="p7793145219520"></a><strong id="b37931529513"><a name="b37931529513"></a><a name="b37931529513"></a>host</strong>: structure pointer to the RTC controller at the core layer.</p>
<p id="p109352055359"><a name="p109352055359"></a><a name="p109352055359"></a><strong id="b393518551159"><a name="b393518551159"></a><a name="b393518551159"></a>alarmIndex</strong>: clock alarm index, which is an enumerated value.</p>
<p id="p1295182163112"><a name="p1295182163112"></a><a name="p1295182163112"></a><strong id="b11371112513"><a name="b11371112513"></a><a name="b11371112513"></a>cb</strong>: pointer to the callback.</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.3 "><p id="p79582123118"><a name="p79582123118"></a><a name="p79582123118"></a>–</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.4 "><p id="p1996122173116"><a name="p1996122173116"></a><a name="p1996122173116"></a>HDF_STATUS</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.5 "><p id="p39602133113"><a name="p39602133113"></a><a name="p39602133113"></a>Registers <strong id="b176627580513"><a name="b176627580513"></a><a name="b176627580513"></a>RtcAlarmCallback</strong> that will be invoked when an alarm is generated at the specified time.</p>
</td>
</tr>
<tr id="row6961321113110"><td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.1 "><p id="p129682193119"><a name="p129682193119"></a><a name="p129682193119"></a>AlarmInterruptEnable</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.2 "><p id="p796015120619"><a name="p796015120619"></a><a name="p796015120619"></a><strong id="b149601210611"><a name="b149601210611"></a><a name="b149601210611"></a>host</strong>: structure pointer to the RTC controller at the core layer.</p>
<p id="p174501061561"><a name="p174501061561"></a><a name="p174501061561"></a><strong id="b7450562062"><a name="b7450562062"></a><a name="b7450562062"></a>alarmIndex</strong>: clock alarm index, which is an enumerated value.</p>
<p id="p59682173112"><a name="p59682173112"></a><a name="p59682173112"></a><strong id="b6999711105518"><a name="b6999711105518"></a><a name="b6999711105518"></a>enable</strong>: specifies whether to enable the RTC alarm interrupt.</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.3 "><p id="p5962021123110"><a name="p5962021123110"></a><a name="p5962021123110"></a>–</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.4 "><p id="p16961621143119"><a name="p16961621143119"></a><a name="p16961621143119"></a>HDF_STATUS</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.5 "><p id="p996182112316"><a name="p996182112316"></a><a name="p996182112316"></a>Enables or disables the RTC alarm interrupt.</p>
</td>
</tr>
<tr id="row199622114317"><td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.1 "><p id="p09615216315"><a name="p09615216315"></a><a name="p09615216315"></a>GetFreq</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.2 "><p id="p16961021103119"><a name="p16961021103119"></a><a name="p16961021103119"></a><strong id="b17147182285715"><a name="b17147182285715"></a><a name="b17147182285715"></a>host</strong>: structure pointer to the RTC controller at the core layer.</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.3 "><p id="p09620218318"><a name="p09620218318"></a><a name="p09620218318"></a><strong id="b11413184435713"><a name="b11413184435713"></a><a name="b11413184435713"></a>freq</strong>: pointer to the output frequency, which is of the uint32_t type.</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.4 "><p id="p15961121163111"><a name="p15961121163111"></a><a name="p15961121163111"></a>HDF_STATUS</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.5 "><p id="p3968214311"><a name="p3968214311"></a><a name="p3968214311"></a>Reads the frequency of the external crystal oscillator connected to the RTC driver.</p>
</td>
</tr>
<tr id="row29692120319"><td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.1 "><p id="p1296421103115"><a name="p1296421103115"></a><a name="p1296421103115"></a>SetFreq</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.2 "><p id="p38121311169"><a name="p38121311169"></a><a name="p38121311169"></a><strong id="b481218117612"><a name="b481218117612"></a><a name="b481218117612"></a>host</strong>: structure pointer to the RTC controller at the core layer.</p>
<p id="p79792114315"><a name="p79792114315"></a><a name="p79792114315"></a><strong id="b1220510308"><a name="b1220510308"></a><a name="b1220510308"></a>freq</strong>: input frequency, which is of the uint32_t type.</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.3 "><p id="p4971021103118"><a name="p4971021103118"></a><a name="p4971021103118"></a>–</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.4 "><p id="p109772117315"><a name="p109772117315"></a><a name="p109772117315"></a>HDF_STATUS</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.5 "><p id="p11971621193115"><a name="p11971621193115"></a><a name="p11971621193115"></a>Sets the frequency of the external crystal oscillator connected to the RTC driver.</p>
</td>
</tr>
<tr id="row1697112123114"><td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.1 "><p id="p99712117318"><a name="p99712117318"></a><a name="p99712117318"></a>Reset</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.2 "><p id="p169712123111"><a name="p169712123111"></a><a name="p169712123111"></a><strong id="b13129173210577"><a name="b13129173210577"></a><a name="b13129173210577"></a>host</strong>: structure pointer to the RTC controller at the core layer.</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.3 "><p id="p3974213312"><a name="p3974213312"></a><a name="p3974213312"></a>–</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.4 "><p id="p109718210315"><a name="p109718210315"></a><a name="p109718210315"></a>HDF_STATUS</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.5 "><p id="p197112116316"><a name="p197112116316"></a><a name="p197112116316"></a>Resets the RTC.</p>
</td>
</tr>
<tr id="row3971821103115"><td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.1 "><p id="p2971221173111"><a name="p2971221173111"></a><a name="p2971221173111"></a>ReadReg</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.2 "><p id="p12704168619"><a name="p12704168619"></a><a name="p12704168619"></a><strong id="b1570171616616"><a name="b1570171616616"></a><a name="b1570171616616"></a>host</strong>: structure pointer to the RTC controller at the core layer.</p>
<p id="p18975210312"><a name="p18975210312"></a><a name="p18975210312"></a><strong id="b1020311128520"><a name="b1020311128520"></a><a name="b1020311128520"></a>usrDefIndex</strong>: structure defining the index of a custom register.</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.3 "><p id="p14975211314"><a name="p14975211314"></a><a name="p14975211314"></a><strong id="b10580501973"><a name="b10580501973"></a><a name="b10580501973"></a>value</strong>: pointer to the output register value, which is of the uint8_t type.</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.4 "><p id="p15981221193114"><a name="p15981221193114"></a><a name="p15981221193114"></a>HDF_STATUS</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.5 "><p id="p1098821143115"><a name="p1098821143115"></a><a name="p1098821143115"></a>Reads the configuration of a custom RTC register based on the register index. One index corresponds to one byte of the configuration value.</p>
</td>
</tr>
<tr id="row1298102119313"><td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.1 "><p id="p598121153114"><a name="p598121153114"></a><a name="p598121153114"></a>WriteReg</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.2 "><p id="p1747714196613"><a name="p1747714196613"></a><a name="p1747714196613"></a><strong id="b6477519469"><a name="b6477519469"></a><a name="b6477519469"></a>host</strong>: structure pointer to the RTC controller at the core layer.</p>
<p id="p1527912317612"><a name="p1527912317612"></a><a name="p1527912317612"></a><strong id="b72791123968"><a name="b72791123968"></a><a name="b72791123968"></a>usrDefIndex</strong>: structure defining the index of a custom register.</p>
<p id="p1498172173115"><a name="p1498172173115"></a><a name="p1498172173115"></a><strong id="b68893701014"><a name="b68893701014"></a><a name="b68893701014"></a>value</strong>: input register value, which is of the uint8_t type.</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.3 "><p id="p1998162193110"><a name="p1998162193110"></a><a name="p1998162193110"></a>–</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.4 "><p id="p198162173118"><a name="p198162173118"></a><a name="p198162173118"></a>HDF_STATUS</p>
</td>
<td class="cellrowborder" valign="top" width="20%" headers="mcps1.2.6.1.5 "><p id="p13981421203110"><a name="p13981421203110"></a><a name="p13981421203110"></a>Configures the RTC register based on the register index. One index corresponds to one byte of the configuration value.</p>
</td>
</tr>
</tbody>
</table>

## How to Develop<a name="section1784450860142407"></a>

The RTC module adaptation involves the following steps:

1.  Instantiate the driver entry.
    -   Instantiate the  **HdfDriverEntry**  structure.
    -   Call  **HDF\_INIT**  to register the  **HdfDriverEntry**  instance with the HDF.

2.  Configure attribute files.
    -   Add the  **deviceNode**  information to the  **device\_info.hcs**  file.
    -   \(Optional\) Add the  **rtc\_config.hcs**  file.

3.  Instantiate the RTC controller object.
    -   Initialize  **RtcHost**.
    -   Instantiate  **RtcMethod**  in the  **RtcHost**  object.

        >![](../public_sys-resources/icon-note.gif) **NOTE** 

        >For details, see [Available APIs](#available-apis).


4.  Debug the driver.
    -   \(Optional\) For new drivers, verify the basic functions, such as the RTC control status and response to interrupts.


## Development Example<a name="section1594883301142407"></a>

The following uses  **rtc\_hi35xx.c**  as an example to present the contents that need to be provided by the vendor to implement device functions.

1.  Instantiate the driver entry. The driver entry must be a global variable of the  **HdfDriverEntry**  type \(defined in  **hdf\_device\_desc.h**\), and the value of  **moduleName**  must be the same as that in  **device\_info.hcs**. In the HDF, the start address of each  **HdfDriverEntry**  object of all loaded drivers is collected to form a segment address space similar to an array for the upper layer to invoke.

    Generally, HDF calls the  **Bind**  function and then the  **Init**  function to load a driver. If  **Init**  fails to be called, HDF calls  **Release**  to release driver resources and exit.

    -   RTC driver entry reference

        ```
        struct HdfDriverEntry g_rtcDriverEntry = {
          .moduleVersion = 1,
          .Bind = HiRtcBind,                // See the Bind function.
             .Init = HiRtcInit,              // See the Init function.
          .Release = HiRtcRelease,         //See the Release function.
          .moduleName = "HDF_PLATFORM_RTC", // (Mandatory) This parameter must be the same as that in the .hcs file.
        };
        // Call HDF_INIT to register the driver entry with the HDF.
        HDF_INIT(g_rtcDriverEntry);
        ```

2.  Add the  **deviceNode**  information to the  **device\_info.hcs**  file and configure the device attributes in the  **rtc\_config.hcs**  file. The  **deviceNode**  information is related to registration of the driver entry. The device attribute values are closely related to the default values or value ranges of the  **RtcHost**  members at the core layer.

    In this example, there is only one RTC controller. If there are multiple RTC controllers, you need to add the  **deviceNode**  information to the  **device\_info**  file and add the corresponding device attributes to the  **rtc\_config**  file.

    -   **device\_info.hcs**  configuration reference

        ```
        root {
          device_info {
            platform :: host {
              device_rtc :: device {
                device0 :: deviceNode {
                  policy = 1; // 2: The driver publishes user-mode services. 1: The driver publishes kernel-mode services. 0: No service needs to be published.
                  priority = 30; // A smaller value indicates a higher priority.
                permission = 0644;                  // Permission for the driver to create a device node
                 moduleName = "HDF_PLATFORM_RTC";  // (Mandatory) Driver name, which must be the same as the moduleName in the driver entry.
                serviceName = "HDF_PLATFORM_RTC"; // (Mandatory) Unique name of the service published by the driver
                deviceMatchAttr = "hisilicon_hi35xx_rtc";// The value must be the same as that of match_attr in the .hcs file.
                }
              }
            }
          }
        }
        ```

    -   **rtc\_config.hcs**  configuration reference

        ```
        root {
          platform {
            rtc_config {
              controller_0x12080000 {
                  match_attr = "hisilicon_hi35xx_rtc";// (Mandatory) The value must be the same as that of deviceMatchAttr in device_info.hcs.
                rtcSpiBaseAddr = 0x12080000; // Used for address mapping
                regAddrLength = 0x100;  // Used for address mapping
                irq = 37; // Interruption number
                supportAnaCtrl = false;
                supportLock = false;
                anaCtrlAddr = 0xff;
                lock0Addr = 0xff;
                lock1Addr = 0xff;
                lock2Addr = 0xff;
                lock3Addr = 0xff;
              }
            }
          }
        }
        ```

3.  Initialize the  **RtcHost**  object at the core layer, including initializing the vendor custom structure \(transferring parameters and data\), instantiating  **RtcMethod**  \(used to call underlying functions of the driver\) in  **RtcHost**, and implementing the  **HdfDriverEntry**  member functions \(**Bind**,  **Init**, and  **Release**\).
    -   Custom structure reference

        To the driver, the custom structure carries parameters and data. The values in the  **rtc\_config.hcs**  file are read by HDF, and the structure members are initialized through  **DeviceResourceIface**.

        ```
        struct RtcConfigInfo {
                 uint32_t           spiBaseAddr; // Used for address mapping
          volatile void      *remapBaseAddr;  // Used for address mapping
         uint16_t           regAddrLength; // Used for address mapping
            uint8_t            supportAnaCtrl; // Indicates whether ANACTRL is supported.
           uint8_t            supportLock;    // Indicates whether lock is supported.
          uint8_t            irq;            // Interrupt number
          uint8_t            alarmIndex;    // Clock alarm index
           uint8_t            anaCtrlAddr; // ANACTRL address
          struct RtcLockAddr lockAddr;      // Lock address
            RtcAlarmCallback   cb;             // Callback
          struct OsalMutex   mutex;          // Mutex
        };
        
        // RtcHost is the controller structure at the core layer. Its members are assigned with values by using the Init function.
        struct RtcHost {
            struct IDeviceIoService service;
            struct HdfDeviceObject *device;
            struct RtcMethod *method;
            void *data;
        };
        ```

    -   Instantiate the callback function structure  **RtcMethod**  in  **RtcHost**. Other members are initialized by using the  **Init**  function.

        ```
        // Example in rtc_hi35xx.c: instantiate the hook.
        static struct RtcMethod g_method = {
            .ReadTime   = HiRtcReadTime,
            .WriteTime  = HiRtcWriteTime,
            .ReadAlarm  = HiReadAlarm,
            .WriteAlarm = HiWriteAlarm,
            .RegisterAlarmCallback  = HiRegisterAlarmCallback,
            .AlarmInterruptEnable   = HiAlarmInterruptEnable,
            .GetFreq  = HiGetFreq,
            .SetFreq  = HiSetFreq,
            .Reset       = HiReset,
            .ReadReg  = HiReadReg,
            .WriteReg = HiWriteReg,
        };
        ```

    -   Bind function

        Input parameters:

        **HdfDeviceObject**, an interface parameter exposed by the driver, contains the .hcs configuration file information.

        Return values:

        HDF\_STATUS \(The following table lists some status. For details about other status, see  **HDF\_STATUS**  in the  **//drivers/framework/include/utils/hdf\_base.h**  file.\)

        **Table  2**  Input parameters and return values of the Bind function

        <a name="table14285177465"></a>
        <table><thead align="left"><tr id="row6280177461"><th class="cellrowborder" valign="top" width="50%" id="mcps1.2.3.1.1"><p id="p528181764613"><a name="p528181764613"></a><a name="p528181764613"></a>Status (Value)</p>
        </th>
        <th class="cellrowborder" valign="top" width="50%" id="mcps1.2.3.1.2"><p id="p192891754615"><a name="p192891754615"></a><a name="p192891754615"></a>Description</p>
        </th>
        </tr>
        </thead>
        <tbody><tr id="row1328191713465"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p02812173467"><a name="p02812173467"></a><a name="p02812173467"></a>HDF_ERR_INVALID_OBJECT</p>
        </td>
        <td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p142861714610"><a name="p142861714610"></a><a name="p142861714610"></a>Invalid controller object</p>
        </td>
        </tr>
        <tr id="row19288170464"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p16282017184619"><a name="p16282017184619"></a><a name="p16282017184619"></a>HDF_ERR_MALLOC_FAIL</p>
        </td>
        <td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p02841754611"><a name="p02841754611"></a><a name="p02841754611"></a>Failed to allocate memory</p>
        </td>
        </tr>
        <tr id="row229131734619"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p429171784617"><a name="p429171784617"></a><a name="p429171784617"></a>HDF_ERR_INVALID_PARAM</p>
        </td>
        <td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p1229151764617"><a name="p1229151764617"></a><a name="p1229151764617"></a>Invalid parameter</p>
        </td>
        </tr>
        <tr id="row6291017154612"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p15294179461"><a name="p15294179461"></a><a name="p15294179461"></a>HDF_ERR_IO</p>
        </td>
        <td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p329517154617"><a name="p329517154617"></a><a name="p329517154617"></a>I/O error</p>
        </td>
        </tr>
        <tr id="row9298171469"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p13297172461"><a name="p13297172461"></a><a name="p13297172461"></a>HDF_SUCCESS</p>
        </td>
        <td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p11299171460"><a name="p11299171460"></a><a name="p11299171460"></a>Initialization successful</p>
        </td>
        </tr>
        <tr id="row122911175467"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p32931744612"><a name="p32931744612"></a><a name="p32931744612"></a>HDF_FAILURE</p>
        </td>
        <td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p102911724610"><a name="p102911724610"></a><a name="p102911724610"></a>Initialization failed</p>
        </td>
        </tr>
        </tbody>
        </table>

        Function description:

        Associates the  **HdfDeviceObject**  object and  **RtcHost**.

        ```
        static int32_t HiRtcBind(struct HdfDeviceObject *device)
        {
          struct RtcHost *host = NULL;  
          host = RtcHostCreate(device); // Apply for memory and connect to the device: host->device = device;
                                           // Enable conversion between HdfDeviceObject and RtcHost.
          ...
           device->service = &host->service; // Enable conversion between HdfDeviceObject and RtcHost.
                                           // This setting enables the host to be globally used by calling RtcHostFromDevice.
          return HDF_SUCCESS;
        }
        ```

    -   Init function

        Input parameters:

        **HdfDeviceObject**, an interface parameter exposed by the driver, contains the .hcs configuration file information.

        Return values:

        HDF\_STATUS

        Function description:

        Initializes the custom structure object and  **RtcHost**.

        ```
        static int32_t HiRtcInit(struct HdfDeviceObject *device)
        {
          struct RtcHost *host = NULL;
          struct RtcConfigInfo *rtcInfo = NULL;
          ...
          host = RtcHostFromDevice(device);// A forced conversion from HdfDeviceObject to RtcHost is involved.
          rtcInfo = OsalMemCalloc(sizeof(*rtcInfo));
          ...
          // HiRtcConfigData reads attributes from the device configuration tree and fills in supportAnaCtrl, supportLock, spiBaseAddr, regAddrLength, and irq in rtcInfo.
          // Provide parameters for HiRtcSwInit and HiRtcSwInit, and perform operations such as releasing memory when the function internal processing fails.
          if (HiRtcConfigData(rtcInfo, device->property) != 0) {
            ...
          }
          if (HiRtcSwInit(rtcInfo)! = 0) {// Related to address mapping and interrupt registration
            ...
          }
          if (HiRtcHwInit(rtcInfo)! = 0) {// Initialize ANACTRL and lockAddr.
            ...
          }
        
              host->method = &g_method; // Connect to the UARTHostMethod instance.
          host->data = rtcInfo; // Enable conversion between RtcConfigInfo and RtcHost.
          HDF_LOGI("Hdf dev service:%s init success!", HdfDeviceGetServiceName(device));
          return HDF_SUCCESS;
        }
        ```

    -   Release function

        Input parameters:

        **HdfDeviceObject**, an interface parameter exposed by the driver, contains the .hcs configuration file information.

        Return values:

        –

        **Function description**:

        Releases the memory and deletes the controller. This function assigns a value to the  **Release**  API in the driver entry structure. When the HDF fails to call the  **Init**  function to initialize the driver, the  **Release**  function can be called to release driver resources. All forced conversion operations for obtaining the corresponding object can be successful only when the  **Init**  or  **Bind**  function has the corresponding value assignment operations.

        ```
        static void HiRtcRelease(struct HdfDeviceObject *device)
        {
            struct RtcHost *host = NULL;
            struct RtcConfigInfo *rtcInfo = NULL;
            ...
         host = RtcHostFromDevice(device);            // A forced conversion from HdfDeviceObject to RtcHost is involved.
            rtcInfo = (struct RtcConfigInfo *)host->data;// A forced conversion from RtcHost to RtcConfigInfo is involved.
            if (rtcInfo != NULL) {
                HiRtcSwExit(rtcInfo);
                OsalMemFree(rtcInfo); // Release RtcConfigInfo.
                host->data = NULL;
            }
            RtcHostDestroy(host); // Release RtcHost.
        }
        ```



