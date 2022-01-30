# USB<a name="EN-US_TOPIC_0000001052857350"></a>

## Overview <a name="section175431838101617"></a>

USB host development aims to provide host-related functions, including protocol encapsulation, device management, and driver installation and uninstall.

USB device development aims to provide device-related functions, including device management, configuration management, and I/O management. These functions implement creation, configuration, and data communication of USB devices.

The following figures show the UBS host and device driver models.

**Figure 1** USB host driver model<a name="fig10451455446"></a>
![](figures/USB_host_driver_model.png "USB host driver model")

**Figure 2** USB device driver model<a name="fig10451455446"></a>
![](figures/USB_device_driver_model.png "USB device driver model")

The USB driver model offers the following APIs:

-   The USB host Driver Development Kit (DDK) provides driver capability APIs that can be directly called in user mode. The APIs can be classified into the DDK initialization class, interface operation class, and request operation class by function. These APIs can be used to perform DDK initialization, bind/release and open/close an interface, allocate/release a request, and implement isochronous or non-isochronous transfer.
-   The USB device DDK provides device management, I/O management, and configuration management APIs, which can be used to create and delete a device, obtain/open an interface, and perform isochronous or non-isochronous transfer.

### Available APIs<a name="section17667171301711"></a>

Table 1 describes the APIs provided by the USB host driver model.

**Table 1** APIs provided by the USB host driver model

<a name="table1513255710559"></a>
<table><thead align="left"><tr id="row171321857155517"><th class="cellrowborder" valign="top" width="10.721072107210723%" id="mcps1.2.4.1.1"><p id="p6132957115511"><a name="p6132957115511"></a><a name="p6132957115511"></a>Header File</p>
</th>
<th class="cellrowborder" valign="top" width="66.36663666366637%" id="mcps1.2.4.1.2"><p id="p14132125715552"><a name="p14132125715552"></a><a name="p14132125715552"></a>API</p>
</th>
<th class="cellrowborder" valign="top" width="22.912291229122914%" id="mcps1.2.4.1.3"><p id="p18132205755516"><a name="p18132205755516"></a><a name="p18132205755516"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row13132357165514"><td class="cellrowborder" rowspan="16" valign="top" width="10.721072107210723%" headers="mcps1.2.4.1.1 "><p id="p15132185775510"><a name="p15132185775510"></a><a name="p15132185775510"></a>usb_ddk_interface.h</p>
<p id="p18132157175510"><a name="p18132157175510"></a><a name="p18132157175510"></a></p>
<p id="p2133757135510"><a name="p2133757135510"></a><a name="p2133757135510"></a></p>
</td>
<td class="cellrowborder" valign="top" width="66.36663666366637%" headers="mcps1.2.4.1.2 "><p id="p1213365714550"><a name="p1213365714550"></a><a name="p1213365714550"></a>int32_t UsbInitHostSdk(struct UsbSession **session);</p>
</td>
<td class="cellrowborder" valign="top" width="22.912291229122914%" headers="mcps1.2.4.1.3 "><p id="p201331557185512"><a name="p201331557185512"></a><a name="p201331557185512"></a>Initializes the USB host driver DDK.</p>
</td>
</tr>
<tr id="row171331657185514"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p913305715553"><a name="p913305715553"></a><a name="p913305715553"></a>int32_t UsbExitHostSdk(const struct UsbSession *session);</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p161332570553"><a name="p161332570553"></a><a name="p161332570553"></a>Exits the USB host driver DDK.</p>
</td>
</tr>
<tr id="row41331557165518"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p6133145713559"><a name="p6133145713559"></a><a name="p6133145713559"></a>const struct UsbInterface *UsbClaimInterface(const struct UsbSession *session, uint8_t busNum, uint8_t usbAddr, uint8_t interfaceIndex);</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p131331557175510"><a name="p131331557175510"></a><a name="p131331557175510"></a>Obtains a USB interface.</p>
</td>
</tr>
<tr id="row77021769584"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p77031566584"><a name="p77031566584"></a><a name="p77031566584"></a>int UsbReleaseInterface(const struct UsbInterface *interfaceObj);</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p1470315695811"><a name="p1470315695811"></a><a name="p1470315695811"></a>Releases a USB interface.</p>
</td>
</tr>
<tr id="row71857914585"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p1318619155811"><a name="p1318619155811"></a><a name="p1318619155811"></a>int UsbAddOrRemoveInterface(const struct UsbSession *session, uint8_t busNum, uint8_t usbAddr, uint8_t interfaceIndex, UsbInterfaceStatus status);</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p1186597589"><a name="p1186597589"></a><a name="p1186597589"></a>Adds or removes a USB interface.</p>
</td>
</tr>
<tr id="row18831119115815"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p48323975814"><a name="p48323975814"></a><a name="p48323975814"></a>UsbInterfaceHandle *UsbOpenInterface(const struct UsbInterface *interfaceObj);</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p15832129135813"><a name="p15832129135813"></a><a name="p15832129135813"></a>Opens a USB interface.</p>
</td>
</tr>
<tr id="row71857914585"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p1318619155811"><a name="p1318619155811"></a><a name="p1318619155811"></a>int32_t UsbCloseInterface(const UsbInterfaceHandle *interfaceHandle);</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p1186597589"><a name="p1186597589"></a><a name="p1186597589"></a>Closes a USB interface.</p>
</td>
</tr>
<tr id="row18831119115815"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p48323975814"><a name="p48323975814"></a><a name="p48323975814"></a>int32_t UsbSelectInterfaceSetting(const UsbInterfaceHandle *interfaceHandle, uint8_t settingIndex, struct UsbInterface **interfaceObj);</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p15832129135813"><a name="p15832129135813"></a><a name="p15832129135813"></a>Sets a USB interface.</p>
</td>
</tr>
<tr id="row71857914585"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p1318619155811"><a name="p1318619155811"></a><a name="p1318619155811"></a>int32_t UsbGetPipeInfo(const UsbInterfaceHandle *interfaceHandle, uint8_t settingIndex, uint8_t pipeId, struct UsbPipeInfo *pipeInfo);</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p1186597589"><a name="p1186597589"></a><a name="p1186597589"></a>Obtains USB pipe information.</p>
</td>
</tr>
<tr id="row18831119115815"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p48323975814"><a name="p48323975814"></a><a name="p48323975814"></a>int32_t UsbClearInterfaceHalt(const UsbInterfaceHandle *interfaceHandle, uint8_t pipeAddress);</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p15832129135813"><a name="p15832129135813"></a><a name="p15832129135813"></a>Clears the state of the pipe with the specified index.</p>
</td>
</tr>
<tr id="row71857914585"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p1318619155811"><a name="p1318619155811"></a><a name="p1318619155811"></a>struct UsbRequest *UsbAllocRequest(const UsbInterfaceHandle *interfaceHandle, int isoPackets, int length);</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p1186597589"><a name="p1186597589"></a><a name="p1186597589"></a>Allocates a request object.</p>
</td>
</tr>
<tr id="row18831119115815"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p48323975814"><a name="p48323975814"></a><a name="p48323975814"></a>int UsbFreeRequest(const struct UsbRequest *request);</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p15832129135813"><a name="p15832129135813"></a><a name="p15832129135813"></a>Releases a request object.</p>
</td>
</tr>
<tr id="row71857914585"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p1318619155811"><a name="p1318619155811"></a><a name="p1318619155811"></a>int UsbSubmitRequestAsync(const struct UsbRequest *request);</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p1186597589"><a name="p1186597589"></a><a name="p1186597589"></a>Sends a request asynchronously.</p>
</td>
</tr>
<tr id="row18831119115815"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p48323975814"><a name="p48323975814"></a><a name="p48323975814"></a>int32_t UsbFillRequest(const struct UsbRequest *request, const UsbInterfaceHandle *interfaceHandle, const struct UsbRequestParams *params);</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p15832129135813"><a name="p15832129135813"></a><a name="p15832129135813"></a>Fills in a request.</p>
</td>
</tr>
<tr id="row71857914585"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p1318619155811"><a name="p1318619155811"></a><a name="p1318619155811"></a>sint UsbCancelRequest(const struct UsbRequest *request);</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p1186597589"><a name="p1186597589"></a><a name="p1186597589"></a>Cancels an asynchronous request.</p>
</td>
</tr>
<tr id="row18831119115815"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p48323975814"><a name="p48323975814"></a><a name="p48323975814"></a>int UsbSubmitRequestSync(const struct UsbRequest *request);</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p15832129135813"><a name="p15832129135813"></a><a name="p15832129135813"></a>Sends a synchronous request.</p>
</td>
</tr>
<tr id="row1513316577554"><td class="cellrowborder" rowspan="27" valign="top" width="10.721072107210723%" headers="mcps1.2.4.1.1 "><p id="p15133657185517"><a name="p15133657185517"></a><a name="p15133657185517"></a>usb_raw_api.h</p>
<p id="p1513315717555"><a name="p1513315717555"></a><a name="p1513315717555"></a></p>
<p id="p81331057125513"><a name="p81331057125513"></a><a name="p81331057125513"></a></p>
<p id="p18703206155812"><a name="p18703206155812"></a><a name="p18703206155812"></a></p>
<p id="p17186692581"><a name="p17186692581"></a><a name="p17186692581"></a></p>
<p id="p28322099581"><a name="p28322099581"></a><a name="p28322099581"></a></p>
</td>
<td class="cellrowborder" valign="top" width="66.36663666366637%" headers="mcps1.2.4.1.2 "><p id="p105259109581"><a name="p105259109581"></a><a name="p105259109581"></a>int UsbRawInit(struct UsbSession **session);</p>
</td>
<td class="cellrowborder" valign="top" width="22.912291229122914%" headers="mcps1.2.4.1.3 "><p id="p752531095814"><a name="p752531095814"></a><a name="p752531095814"></a>Initializes the USB raw APIs.</p>
</td>
</tr>
<tr id="row172902161193"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p16290141681918"><a name="p16290141681918"></a><a name="p16290141681918"></a>int UsbRawExit(const struct UsbSession *session);</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p1929141611198"><a name="p1929141611198"></a><a name="p1929141611198"></a>Exits the USB raw APIs.</p>
</td>
</tr>
<tr id="row1948179195"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p1395181710193"><a name="p1395181710193"></a><a name="p1395181710193"></a>UsbRawHandle *UsbRawOpenDevice(const struct UsbSession *session, uint8_t busNum, uint8_t usbAddr);</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p169531741912"><a name="p169531741912"></a><a name="p169531741912"></a>Opens a USB device.</p>
</td>
</tr>
<tr id="row1331121813197"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p533121871912"><a name="p533121871912"></a><a name="p533121871912"></a>int UsbRawCloseDevice(const UsbRawHandle *devHandle);</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p4331131817195"><a name="p4331131817195"></a><a name="p4331131817195"></a>Closes a USB device.</p>
</td>
</tr>
<tr id="row1393181951920"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p79410191191"><a name="p79410191191"></a><a name="p79410191191"></a>int UsbRawSendControlRequest(const struct UsbRawRequest *request, const UsbRawHandle *devHandle, const struct UsbControlRequestData *requestData);</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p17948193197"><a name="p17948193197"></a><a name="p17948193197"></a>Performs a control transfer synchronously.</p>
</td>
</tr>
<tr id="row12422102092613"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p194231720102610"><a name="p194231720102610"></a><a name="p194231720102610"></a>int UsbRawSendBulkRequest(const struct UsbRawRequest *request, const UsbRawHandle *devHandle, const struct UsbRequestData *requestData);</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p342315202267"><a name="p342315202267"></a><a name="p342315202267"></a>Performs a bulk transfer synchronously.</p>
</td>
</tr>
<tr id="row1393181951920"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p79410191191"><a name="p79410191191"></a><a name="p79410191191"></a>int UsbRawSendInterruptRequest(const struct UsbRawRequest *request, const UsbRawHandle *devHandle, const struct UsbRequestData *requestData);</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p17948193197"><a name="p17948193197"></a><a name="p17948193197"></a>Performs an interrupt transfer synchronously.</p>
</td>
</tr>
<tr id="row12422102092613"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p194231720102610"><a name="p194231720102610"></a><a name="p194231720102610"></a>int UsbRawGetConfigDescriptor(const UsbRawDevice *rawDev, uint8_t configIndex, struct UsbRawConfigDescriptor **config);</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p342315202267"><a name="p342315202267"></a><a name="p342315202267"></a>Obtains the configuration descriptor of a device.</p>
</td>
</tr>
<tr id="row1393181951920"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p79410191191"><a name="p79410191191"></a><a name="p79410191191"></a>void UsbRawFreeConfigDescriptor(const struct UsbRawConfigDescriptor *config);</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p17948193197"><a name="p17948193197"></a><a name="p17948193197"></a>Releases the memory space of a configuration descriptor.</p>
</td>
</tr>
<tr id="row12422102092613"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p194231720102610"><a name="p194231720102610"></a><a name="p194231720102610"></a>int UsbRawGetConfiguration(const UsbRawHandle *devHandle, int *config);</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p342315202267"><a name="p342315202267"></a><a name="p342315202267"></a>Obtains the configuration in use.</p>
</td>
</tr>
<tr id="row1393181951920"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p79410191191"><a name="p79410191191"></a><a name="p79410191191"></a>int UsbRawSetConfiguration(const UsbRawHandle *devHandle, int config);</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p17948193197"><a name="p17948193197"></a><a name="p17948193197"></a>Sets the configuration in use.</p>
</td>
</tr>
<tr id="row12422102092613"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p194231720102610"><a name="p194231720102610"></a><a name="p194231720102610"></a>int UsbRawGetDescriptor(const struct UsbRawRequest *request, const UsbRawHandle *devHandle, const struct UsbRawDescriptorParam *param, const unsigned char *data);</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p342315202267"><a name="p342315202267"></a><a name="p342315202267"></a>Obtains descriptor information.</p>
</td>
</tr>
<tr id="row1393181951920"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p79410191191"><a name="p79410191191"></a><a name="p79410191191"></a>UsbRawDevice *UsbRawGetDevice(const UsbRawHandle *devHandle);</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p17948193197"><a name="p17948193197"></a><a name="p17948193197"></a>Obtains the device pointer based on the device handle.</p>
</td>
</tr>
<tr id="row12422102092613"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p194231720102610"><a name="p194231720102610"></a><a name="p194231720102610"></a>int UsbRawGetDeviceDescriptor(const UsbRawDevice *rawDev, struct UsbDeviceDescriptor *desc);</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p342315202267"><a name="p342315202267"></a><a name="p342315202267"></a>Obtains the device descriptor of the specified USB device.</p>
</td>
</tr>
<tr id="row1393181951920"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p79410191191"><a name="p79410191191"></a><a name="p79410191191"></a>int UsbRawClaimInterface(const UsbRawHandle *devHandle, int interfaceNumber);</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p17948193197"><a name="p17948193197"></a><a name="p17948193197"></a>Declares the interface on the specified device handle.</p>
</td>
</tr>
<tr id="row12422102092613"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p194231720102610"><a name="p194231720102610"></a><a name="p194231720102610"></a>int UsbRawReleaseInterface(const UsbRawHandle *devHandle, int interfaceNumber);</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p342315202267"><a name="p342315202267"></a><a name="p342315202267"></a>Releases the previously declared interface.</p>
</td>
</tr>
<tr id="row1393181951920"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p79410191191"><a name="p79410191191"></a><a name="p79410191191"></a>int UsbRawResetDevice(const UsbRawHandle *devHandle);</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p17948193197"><a name="p17948193197"></a><a name="p17948193197"></a>Resets a device.</p>
</td>
</tr>
<tr id="row12422102092613"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p194231720102610"><a name="p194231720102610"></a><a name="p194231720102610"></a>struct UsbRawRequest *UsbRawAllocRequest(const UsbRawHandle *devHandle, int isoPackets, int length);</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p342315202267"><a name="p342315202267"></a><a name="p342315202267"></a>Allocates a transfer request with the specified number of sync packet descriptors.</p>
</td>
</tr>
<tr id="row1393181951920"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p79410191191"><a name="p79410191191"></a><a name="p79410191191"></a>int UsbRawFreeRequest(const struct UsbRawRequest *request);</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p17948193197"><a name="p17948193197"></a><a name="p17948193197"></a>Releases the previously allocated transfer request.</p>
</td>
</tr>
<tr id="row12422102092613"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p194231720102610"><a name="p194231720102610"></a><a name="p194231720102610"></a>int UsbRawFillBulkRequest(const struct UsbRawRequest *request, const UsbRawHandle *devHandle, const struct UsbRawFillRequestData *fillData);</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p342315202267"><a name="p342315202267"></a><a name="p342315202267"></a>Fills in the bulk transfer request.</p>
</td>
</tr>
<tr id="row1393181951920"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p79410191191"><a name="p79410191191"></a><a name="p79410191191"></a>int UsbRawFillControlSetup(const unsigned char *setup, const struct UsbControlRequestData *requestData);</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p17948193197"><a name="p17948193197"></a><a name="p17948193197"></a>Fills in the control setup packet.</p>
</td>
</tr>
<tr id="row12422102092613"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p194231720102610"><a name="p194231720102610"></a><a name="p194231720102610"></a>int UsbRawFillControlRequest(const struct UsbRawRequest *request, const UsbRawHandle *devHandle, const struct UsbRawFillRequestData *fillData);</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p342315202267"><a name="p342315202267"></a><a name="p342315202267"></a>Fills in the control transfer request.</p>
</td>
</tr>
<tr id="row1393181951920"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p79410191191"><a name="p79410191191"></a><a name="p79410191191"></a>int UsbRawFillInterruptRequest(const struct UsbRawRequest *request, const UsbRawHandle *devHandle, const struct UsbRawFillRequestData *fillData);</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p17948193197"><a name="p17948193197"></a><a name="p17948193197"></a>Fills in the interrupt transfer request.</p>
</td>
</tr>
<tr id="row12422102092613"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p194231720102610"><a name="p194231720102610"></a><a name="p194231720102610"></a>int UsbRawFillIsoRequest(const struct UsbRawRequest *request, const UsbRawHandle *devHandle, const struct UsbRawFillRequestData *fillData);</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p342315202267"><a name="p342315202267"></a><a name="p342315202267"></a>Fills in the isochronous transfer request.</p>
</td>
</tr>
<tr id="row1393181951920"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p79410191191"><a name="p79410191191"></a><a name="p79410191191"></a>int UsbRawSubmitRequest(const struct UsbRawRequest *request);</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p17948193197"><a name="p17948193197"></a><a name="p17948193197"></a>Submits a transfer request.</p>
</td>
</tr>
<tr id="row12422102092613"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p194231720102610"><a name="p194231720102610"></a><a name="p194231720102610"></a>int UsbRawCancelRequest(const struct UsbRawRequest *request);</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p342315202267"><a name="p342315202267"></a><a name="p342315202267"></a>Cancels a transfer request.</p>
</td>
</tr>
<tr id="row1393181951920"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p79410191191"><a name="p79410191191"></a><a name="p79410191191"></a>int UsbRawHandleRequests(const UsbRawHandle *devHandle);</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p17948193197"><a name="p17948193197"></a><a name="p17948193197"></a>Handles a transfer request event.</p>
</td>
</tr>
</tbody>
</table>

Table 2 describes the APIs provided by the USB device driver model.

**Table 2** APIs provided by the USB device driver model

<a name="table1513255710559"></a>
<table><thead align="left"><tr id="row171321857155517"><th class="cellrowborder" valign="top" width="10.721072107210723%" id="mcps1.2.4.1.1"><p id="p6132957115511"><a name="p6132957115511"></a><a name="p6132957115511"></a>Header File</p>
</th>
<th class="cellrowborder" valign="top" width="66.36663666366637%" id="mcps1.2.4.1.2"><p id="p14132125715552"><a name="p14132125715552"></a><a name="p14132125715552"></a>API</p>
</th>
<th class="cellrowborder" valign="top" width="22.912291229122914%" id="mcps1.2.4.1.3"><p id="p18132205755516"><a name="p18132205755516"></a><a name="p18132205755516"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row13132357165514"><td class="cellrowborder" rowspan="3" valign="top" width="10.721072107210723%" headers="mcps1.2.4.1.1 "><p id="p15132185775510"><a name="p15132185775510"></a><a name="p15132185775510"></a>usbfn_device.h</p>
<p id="p18132157175510"><a name="p18132157175510"></a><a name="p18132157175510"></a></p>
<p id="p2133757135510"><a name="p2133757135510"></a><a name="p2133757135510"></a></p>
</td>
<td class="cellrowborder" valign="top" width="66.36663666366637%" headers="mcps1.2.4.1.2 "><p id="p11132857135517"><a name="p11132857135517"></a><a name="p11132857135517"></a>const struct UsbFnDevice *UsbFnCreateDevice(const char *udcName, const struct UsbFnDescriptorData *descriptor);</p>
</td>
<td class="cellrowborder" valign="top" width="22.912291229122914%" headers="mcps1.2.4.1.3 "><p id="p213285715558"><a name="p213285715558"></a><a name="p213285715558"></a>Creates a USB device.</p>
</td>
</tr>
<tr id="row9132135715515"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p16133957155517"><a name="p16133957155517"></a><a name="p16133957155517"></a>int UsbFnRemoveDevice(struct UsbFnDevice *fnDevice);</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p113315745519"><a name="p113315745519"></a><a name="p113315745519"></a> Deletes a USB device.</p>
</td>
</tr>
<tr id="row171330575555"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p913315573557"><a name="p913315573557"></a><a name="p913315573557"></a>const struct UsbFnDevice *UsbFnGetDevice(const char *udcName);</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p1413365765514"><a name="p1413365765514"></a><a name="p1413365765514"></a>Obtains a USB device.</p>
</td>
</tr>
<tr id="row1513316577554"><td class="cellrowborder" rowspan="6" valign="top" width="10.721072107210723%" headers="mcps1.2.4.1.1 "><p id="p15133657185517"><a name="p15133657185517"></a><a name="p15133657185517"></a>usbfn_interface.h</p>
<p id="p1513315717555"><a name="p1513315717555"></a><a name="p1513315717555"></a></p>
<p id="p81331057125513"><a name="p81331057125513"></a><a name="p81331057125513"></a></p>
<p id="p18703206155812"><a name="p18703206155812"></a><a name="p18703206155812"></a></p>
<p id="p17186692581"><a name="p17186692581"></a><a name="p17186692581"></a></p>
<p id="p28322099581"><a name="p28322099581"></a><a name="p28322099581"></a></p>
</td>
<td class="cellrowborder" valign="top" width="66.36663666366637%" headers="mcps1.2.4.1.2 "><p id="p1213365714550"><a name="p1213365714550"></a><a name="p1213365714550"></a>int UsbFnStartRecvInterfaceEvent(struct UsbFnInterface *interface, uint32_t eventMask, UsbFnEventCallback callback, void *context);</p>
</td>
<td class="cellrowborder" valign="top" width="22.912291229122914%" headers="mcps1.2.4.1.3 "><p id="p201331557185512"><a name="p201331557185512"></a><a name="p201331557185512"></a>Starts to receive events.</p>
</td>
</tr>
<tr id="row171331657185514"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p913305715553"><a name="p913305715553"></a><a name="p913305715553"></a>int UsbFnStopRecvInterfaceEvent(struct UsbFnInterface *interface);</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p161332570553"><a name="p161332570553"></a><a name="p161332570553"></a>Stops receiving events.</p>
</td>
</tr>
<tr id="row41331557165518"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p6133145713559"><a name="p6133145713559"></a><a name="p6133145713559"></a>UsbFnInterfaceHandle UsbFnOpenInterface(struct UsbFnInterface *interface);</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p131331557175510"><a name="p131331557175510"></a><a name="p131331557175510"></a>Opens an interface.</p>
</td>
</tr>
<tr id="row77021769584"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p77031566584"><a name="p77031566584"></a><a name="p77031566584"></a>int UsbFnCloseInterface(UsbFnInterfaceHandle handle);</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p1470315695811"><a name="p1470315695811"></a><a name="p1470315695811"></a>Closes an interface.</p>
</td>
</tr>
<tr id="row71857914585"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p1318619155811"><a name="p1318619155811"></a><a name="p1318619155811"></a>int UsbFnGetInterfacePipeInfo(struct UsbFnInterface *interface, uint8_t pipeId, struct UsbFnPipeInfo *info);</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p1186597589"><a name="p1186597589"></a><a name="p1186597589"></a>Obtains pipe information.</p>
</td>
</tr>
<tr id="row18831119115815"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p48323975814"><a name="p48323975814"></a><a name="p48323975814"></a>int UsbFnSetInterfaceProp(const struct UsbFnInterface *interface, const char *name, const char *value);</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p15832129135813"><a name="p15832129135813"></a><a name="p15832129135813"></a>Sets custom properties.</p>
</td>
</tr>
<tr id="row1452521025813"><td class="cellrowborder" rowspan="8" valign="top" width="10.721072107210723%" headers="mcps1.2.4.1.1 "><p id="p12525910165811"><a name="p12525910165811"></a><a name="p12525910165811"></a>usbfn_request.h</p>
<p id="p1929018168192"><a name="p1929018168192"></a><a name="p1929018168192"></a></p>
<p id="p99515179192"><a name="p99515179192"></a><a name="p99515179192"></a></p>
<p id="p11331918201913"><a name="p11331918201913"></a><a name="p11331918201913"></a></p>
<p id="p209341981918"><a name="p209341981918"></a><a name="p209341981918"></a></p>
<p id="p1996019191197"><a name="p1996019191197"></a><a name="p1996019191197"></a></p>
<p id="p2812720131919"><a name="p2812720131919"></a><a name="p2812720131919"></a></p>
<p id="p942322013262"><a name="p942322013262"></a><a name="p942322013262"></a></p>
</td>
<td class="cellrowborder" valign="top" width="66.36663666366637%" headers="mcps1.2.4.1.2 "><p id="p105259109581"><a name="p105259109581"></a><a name="p105259109581"></a>struct UsbFnRequest *UsbFnAllocCtrlRequest(UsbFnInterfaceHandle handle, uint32_t len);</p>
</td>
<td class="cellrowborder" valign="top" width="22.912291229122914%" headers="mcps1.2.4.1.3 "><p id="p752531095814"><a name="p752531095814"></a><a name="p752531095814"></a>Applies for a control transfer request.</p>
</td>
</tr>
<tr id="row172902161193"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p16290141681918"><a name="p16290141681918"></a><a name="p16290141681918"></a>struct UsbFnRequest *UsbFnAllocRequest(UsbFnInterfaceHandle handle, uint8_t pipe, uint32_t len);</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p1929141611198"><a name="p1929141611198"></a><a name="p1929141611198"></a>Applies for a data request.</p>
</td>
</tr>
<tr id="row1948179195"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p1395181710193"><a name="p1395181710193"></a><a name="p1395181710193"></a>int UsbFnFreeRequest(struct UsbFnRequest *req);</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p169531741912"><a name="p169531741912"></a><a name="p169531741912"></a>Releases a request.</p>
</td>
</tr>
<tr id="row1331121813197"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p533121871912"><a name="p533121871912"></a><a name="p533121871912"></a>int UsbFnSubmitRequestAsync(struct UsbFnRequest *req);</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p4331131817195"><a name="p4331131817195"></a><a name="p4331131817195"></a> Sends a request asynchronously.</p>
</td>
</tr>
<tr id="row1393181951920"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p79410191191"><a name="p79410191191"></a><a name="p79410191191"></a>int UsbFnSubmitRequestSync(struct UsbFnRequest *req, uint32_t timeout);</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p17948193197"><a name="p17948193197"></a><a name="p17948193197"></a>Sends a request synchronously.</p>
</td>
</tr>
<tr id="row12422102092613"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p194231720102610"><a name="p194231720102610"></a><a name="p194231720102610"></a>int UsbFnCancelRequest(struct UsbFnRequest *req);</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p342315202267"><a name="p342315202267"></a><a name="p342315202267"></a>Cancels a request.</p>
</td>
</tr>
</tbody>
</table>

## Development Guidelines<a name="section65745222184"></a>

The USB driver is developed based on the Hardware Driver Foundation (HDF), platform, and Operating System Abstraction Layer (OSAL) APIs. A unified driver model is provided for USB devices, irrespective of the operating system and chip architecture. This document uses a serial port as an example to describe how to develop drivers for the USB host and USB device.

### How to Develop<a name="section865734181916"></a>

### Developing Driver Using Host DDK APIs<a name="section18249155619195"></a>

1.  Configure the driver mapping table.
2.  Initialize the USB host DDK.
3.  Obtain a **UsbInterface** object.
4.  Open the **UsbInterface** object to obtain the **UsbInterfaceHandle** object.
5.  Obtain pipe information of the specified **pipeIndex** based on the **UsbInterfaceHandle** object.
6.  Allocate an I/O request for the **UsbInterfaceHandle** object.
7.  Fill in the I/O request based on the input parameters.
8.  Submit the I/O request in synchronous or asynchronous mode.


### Developing Driver Using Host Raw APIs<a name="section18249155619195"></a>

1.  Configure the driver mapping table.
2.  Initialize the host raw data, open the USB device, obtain the descriptor, and then obtain interface and endpoint information based on the descriptor.
3.  Allocate a request and fill in the request based on the transfer type.
4.  Submit the I/O request object in synchronous or asynchronous mode.

### Developing Driver Using Device DDK APIs<a name="section18249155619195"></a>

1.  Construct a descriptor.
2.  Instantiate a USB device using the descriptor constructed.
3.  Call **UsbFnDeviceGetInterface** to obtain an interface, call **UsbFnInterfaceGetPipeInfo** to obtain pipe information based on the interface, call **UsbFnInterfaceOpen** to open the interface to obtain the handle, and call **UsbFnRequestAlloc** to obtain the request based on the handle and pipe ID.
4.  Call **UsbFnInterfaceStartRecvEvent** to receive events such as Enable and Setup, and respond to the events in **UsbFnEventCallback**.
5.  Send and receive data in synchronous or asynchronous mode.

## Development Examples<a name="section263714411191"></a>

The following example helps you better understand the development of the USB serial port driver.

### Developing Driver Using Host DDK APIs<a name="section18249155619195"></a>

```
root {
    module = "usb_pnp_device";
    usb_pnp_config {
        match_attr = "usb_pnp_match";
        usb_pnp_device_id = "UsbPnpDeviceId";
        UsbPnpDeviceId {
            idTableList = [
				"host_acm_table"
			];
			host_acm_table {
				// Driver module name, which must be the same as the value of moduleName in the driver entry structure.
				moduleName = "usbhost_acm";
				// Service name of the driver, which must be unique.
				serviceName = "usbhost_acm_pnp_service";
				// Keyword for matching private driver data.
				deviceMatchAttr = "usbhost_acm_pnp_matchAttr";
				// Data length starting from this field, in bytes.
				length = 21;
				// USB driver matching rule: vendorId+productId+interfaceSubClass+interfaceProtocol+interfaceNumber.
				matchFlag = 0x0303;
				// Vendor ID.
				vendorId = 0x12D1;
				// Product ID.
				productId = 0x5000;
				// The least significant 16 bits of the device sequence number.
				bcdDeviceLow = 0x0000;
				// The most significant 16 bits of the device sequence number.
			 	bcdDeviceHigh = 0x0000;
				// Device class code allocated by the USB.
				deviceClass = 0;
				// Child class code allocated by the USB.
				deviceSubClass = 0;
				// Device protocol code allocated by the USB.
				deviceProtocol = 0;
				// Interface type. You can enter multiple types as needed.
				interfaceClass = [0];
				// Interface subtype. You can enter multiple subtypes as needed.
				interfaceSubClass = [2, 0];
				// Protocol that the interface complies with. You can enter multiple protocols as needed.
				interfaceProtocol = [1, 2];
				// Interface numer. You can enter multiple interface numbers as needed.
				interfaceNumber = [2, 3];
			}
        }
    }
}

#include "usb_serial.h"
#include "hdf_base.h"
#include "hdf_log.h"
#include "osal_mem.h"
#include "osal_time.h"
#include "securec.h"
#include "usb_ddk_interface.h"
#include "hdf_usb_pnp_manage.h"

#define HDF_LOG_TAG USB_HOST_ACM
#define STR_LEN     512

static struct UsbRequest *g_syncRequest = NULL;
static struct UsbRequest *g_ctrlCmdRequest = NULL;
static bool g_acmReleaseFlag = false;
static uint8_t *g_acmReadBuffer = NULL;
...
static int SerialCtrlMsg(struct AcmDevice *acm, uint8_t request,
    uint16_t value, void *buf, uint16_t len)
{
    int ret;
    uint16_t index = acm->intPipe->interfaceId;
    struct UsbControlParams controlParams = {};
    struct UsbRequestParams parmas = {};
    if (acm == NULL || buf == NULL) {
        HDF_LOGE("%{public}s:invalid param", __func__);
        return HDF_ERR_IO;
    }
    if (acm->ctrlReq == NULL) {
        acm->ctrlReq = UsbAllocRequest(acm->ctrDevHandle, 0, len);
        if (acm->ctrlReq == NULL) {
            HDF_LOGE("%{public}s: UsbAllocRequest failed", __func__);
            return HDF_ERR_IO;
        }
    }

    controlParams.request = request;
    controlParams.target = USB_REQUEST_TARGET_INTERFACE;
    controlParams.reqType = USB_REQUEST_TYPE_CLASS;
    controlParams.directon = USB_REQUEST_DIR_TO_DEVICE;
    controlParams.value = value;
    controlParams.index = index;
    controlParams.data = buf;
    controlParams.size = len;

    parmas.interfaceId = USB_CTRL_INTERFACE_ID;
    parmas.pipeAddress = acm->ctrPipe->pipeAddress;
    parmas.pipeId = acm->ctrPipe->pipeId;
    parmas.requestType = USB_REQUEST_PARAMS_CTRL_TYPE;
    parmas.timeout = USB_CTRL_SET_TIMEOUT;
    parmas.ctrlReq = UsbControlSetUp(&controlParams);
    ret = UsbFillRequest(acm->ctrlReq, acm->ctrDevHandle, &parmas);
    if (HDF_SUCCESS != ret) {
        HDF_LOGE("%{public}s: failed, ret=%{public}d ", __func__, ret);
        return ret;
    }
    ret = UsbSubmitRequestSync(acm->ctrlReq);	// Send an I/O request synchronously.
    if (HDF_SUCCESS != ret) {
        HDF_LOGE("UsbSubmitRequestSync  faile, ret=%{public}d ", ret);
        return ret;
    }
    if (!acm->ctrlReq->compInfo.status) {
        HDF_LOGE("%{public}s  status=%{public}d ", __func__, acm->ctrlReq->compInfo.status);
    }
    return HDF_SUCCESS;
}
...
static struct UsbInterface *GetUsbInterfaceById(const struct AcmDevice *acm,
    uint8_t interfaceIndex)
{
    struct UsbInterface *tmpIf = NULL;
    tmpIf = (struct UsbInterface *)UsbClaimInterface(acm->session, acm->busNum, \
            acm->devAddr, interfaceIndex);	// Obtain the UsbInterface object.
    return tmpIf;
}
...
static struct UsbPipeInfo *EnumePipe(const struct AcmDevice *acm,
    uint8_t interfaceIndex, UsbPipeType pipeType, UsbPipeDirection pipeDirection)
{
    uint8_t i;
    int ret;
    struct UsbInterfaceInfo *info = NULL;
    UsbInterfaceHandle *interfaceHandle = NULL;
    if (pipeType == USB_PIPE_TYPE_CONTROL)
    {
        info = &acm->ctrIface->info;
        interfaceHandle = acm->ctrDevHandle;
    }
    else
    {
        info = &acm->iface[interfaceIndex]->info;
        interfaceHandle = InterfaceIdToHandle(acm, info->interfaceIndex);
    }

    for (i = 0;  i <= info->pipeNum; i++) {
        struct UsbPipeInfo p;
        ret = UsbGetPipeInfo(interfaceHandle, info->curAltSetting, i, &p);// Obtain information about the pipe with index i.
        if (ret < 0) {
            continue;
        }
        if ((p.pipeDirection == pipeDirection) && (p.pipeType == pipeType)) {
            struct UsbPipeInfo *pi = OsalMemCalloc(sizeof(*pi));
            if (pi == NULL) {
                HDF_LOGE("%{public}s: Alloc pipe failed", __func__);
                return NULL;
            }
            p.interfaceId = info->interfaceIndex;
            *pi = p;
            return pi;
        }
    }
    return NULL;
}

static struct UsbPipeInfo *GetPipe(const struct AcmDevice *acm,
    UsbPipeType pipeType, UsbPipeDirection pipeDirection)
{
    uint8_t i;
    if (acm == NULL) {
        HDF_LOGE("%{public}s: invalid parmas", __func__);
        return NULL;
    }
    for (i = 0; i < acm->interfaceCnt; i++) {
        struct UsbPipeInfo *p = NULL;
        if (!acm->iface[i]) {
            continue;
        }
        p = EnumePipe(acm, i, pipeType, pipeDirection);
        if (p == NULL) {
            continue;
        }
        return p;
    }
    return NULL;
}

/* HdfDriverEntry implementations */
static int32_t UsbSerialDriverBind(struct HdfDeviceObject *device)
{
    struct UsbPnpNotifyServiceInfo *info = NULL;
    errno_t err;
    struct AcmDevice *acm = NULL;
    if (device == NULL) {
        HDF_LOGE("%s: device is null", __func__);
        return HDF_ERR_INVALID_OBJECT;
    }
    acm = (struct AcmDevice *)OsalMemCalloc(sizeof(*acm));
    if (acm == NULL) {
        HDF_LOGE("%s: Alloc usb serial device failed", __func__);
        return HDF_FAILURE;
    }
    if (OsalMutexInit(&acm->lock) != HDF_SUCCESS) {
        HDF_LOGE("%s:%d OsalMutexInit fail", __func__, __LINE__);
        goto error;
    }
    info = (struct UsbPnpNotifyServiceInfo *)device->priv;
    if (info != NULL) {
        HDF_LOGD("%s:%d busNum=%d,devAddr=%d,interfaceLength=%d", \
            __func__, __LINE__, info->busNum, info->devNum, info->interfaceLength);
        acm->busNum = info->busNum;
        acm->devAddr = info->devNum;
        acm->interfaceCnt = info->interfaceLength;
        err = memcpy_s((void *)(acm->interfaceIndex), USB_MAX_INTERFACES,
              (const void*)info->interfaceNumber, info->interfaceLength);
        if (err != EOK) {
            HDF_LOGE("%s:%d memcpy_s failed err=%d", \
                __func__, __LINE__, err);
            goto lock_error;
        }
    } else {
        HDF_LOGE("%s:%d info is NULL!", __func__, __LINE__);
        goto lock_error;
    }
    acm->device  = device;
    device->service = &(acm->service);
    acm->device->service->Dispatch = UsbSerialDeviceDispatch;
    HDF_LOGD("UsbSerialDriverBind=========================OK");
    return HDF_SUCCESS;

lock_error:
    if (OsalMutexDestroy(&acm->lock)) {
        HDF_LOGE("%s:%d OsalMutexDestroy fail", __func__, __LINE__);
    }
error:
    OsalMemFree(acm);
    acm = NULL;
    return HDF_FAILURE;
}
...
static int AcmAllocReadRequests(struct AcmDevice *acm)
{
    int ret;
    struct UsbRequestParams readParmas = {};
    for (int i = 0; i < ACM_NR; i++) {
        acm->readReq[i] = UsbAllocRequest(InterfaceIdToHandle(acm, acm->dataInPipe->interfaceId), 0, acm->readSize);	// Allocate the readReq I/O request object to be sent.
        if (!acm->readReq[i]) {
            HDF_LOGE("readReq request failed\n");
            goto error;
        }
        readParmas.userData = (void *)acm;
        readParmas.pipeAddress = acm->dataInPipe->pipeAddress;
        readParmas.pipeId = acm->dataInPipe->pipeId;
        readParmas.interfaceId = acm->dataInPipe->interfaceId;
        readParmas.callback = AcmReadBulk;
        readParmas.requestType = USB_REQUEST_PARAMS_DATA_TYPE;
        readParmas.timeout = USB_CTRL_SET_TIMEOUT;
        readParmas.dataReq.numIsoPackets = 0;
        readParmas.dataReq.directon = (acm->dataInPipe->pipeDirection >> USB_PIPE_DIR_OFFSET) & 0x1;
        readParmas.dataReq.length = acm->readSize;
        ret = UsbFillRequest(acm->readReq[i], InterfaceIdToHandle(acm, acm->dataInPipe->interfaceId), &readParmas);	// Fill in the readReq object to be sent.
        if (HDF_SUCCESS != ret) {
            HDF_LOGE("%{public}s: UsbFillRequest faile, ret=%{public}d \n", __func__, ret);
            goto error;
        }
    }
    return HDF_SUCCESS;

error:
    AcmFreeReadRequests(acm);
    return HDF_ERR_MALLOC_FAIL;
}

static int AcmAllocNotifyRequest(struct AcmDevice *acm)
{
    int ret;
    struct UsbRequestParams intParmas = {};
    acm->notifyReq = UsbAllocRequest(InterfaceIdToHandle(acm, acm->intPipe->interfaceId), 0, acm->intSize);	// Allocate the interrupt I/O request object to be sent.
    if (!acm->notifyReq) {
        HDF_LOGE("notifyReq request fail\n");
        return HDF_ERR_MALLOC_FAIL;
    }
    intParmas.userData = (void *)acm;
    intParmas.pipeAddress = acm->intPipe->pipeAddress;
    intParmas.pipeId = acm->intPipe->pipeId;
    intParmas.interfaceId = acm->intPipe->interfaceId;
    intParmas.callback = AcmCtrlIrq;
    intParmas.requestType = USB_REQUEST_PARAMS_DATA_TYPE;
    intParmas.timeout = USB_CTRL_SET_TIMEOUT;
    intParmas.dataReq.numIsoPackets = 0;
    intParmas.dataReq.directon = (acm->intPipe->pipeDirection >> USB_PIPE_DIR_OFFSET) & DIRECTION_MASK;
    intParmas.dataReq.length = acm->intSize;
    ret = UsbFillRequest(acm->notifyReq, InterfaceIdToHandle(acm, acm->intPipe->interfaceId), &intParmas);	// Fill in the interrupt I/O request.
    if (HDF_SUCCESS != ret) {
        HDF_LOGE("%{public}s: UsbFillRequest faile, ret=%{public}d \n", __func__, ret);
        goto error;
    }
    return HDF_SUCCESS;

error:
    AcmFreeNotifyReqeust(acm);
    return ret;
}

static void AcmReleaseInterfaces(struct AcmDevice *acm)
{
    for (int i = 0; i < acm->interfaceCnt; i++) {
        if (acm->iface[i]) {
            UsbReleaseInterface(acm->iface[i]);
            acm->iface[i] = NULL;
        }
    }
    if (acm->ctrIface) {
        UsbReleaseInterface(acm->ctrIface);
        acm->ctrIface = NULL;
    }
}

static int32_t AcmClaimInterfaces(struct AcmDevice *acm)
{
    for (int i = 0; i < acm->interfaceCnt; i++) {
        acm->iface[i] = GetUsbInterfaceById((const struct AcmDevice *)acm, acm->interfaceIndex[i]);	// Obtain the UsbInterface object.
        if (acm->iface[i] == NULL) {
            HDF_LOGE("%{public}s: interface%{public}d is null", __func__, acm->interfaceIndex[i]);
            goto error;
        }
    }

    acm->ctrIface = GetUsbInterfaceById((const struct AcmDevice *)acm, USB_CTRL_INTERFACE_ID);	// Obtain the UsbInterface object corresponding to the control interface.
    if (acm->ctrIface == NULL) {
        HDF_LOGE("%{public}s: GetUsbInterfaceById null", __func__);
        goto error;
    }

    return HDF_SUCCESS;

 error:
    AcmReleaseInterfaces(acm);
    return HDF_FAILURE;
}

static void AcmCloseInterfaces(struct AcmDevice *acm)
{
    for (int i = 0; i < acm->interfaceCnt; i++) {
        if (acm->devHandle[i]) {
            UsbCloseInterface(acm->devHandle[i]);
            acm->devHandle[i] = NULL;
        }
    }
    if (acm->ctrDevHandle) {
        UsbCloseInterface(acm->ctrDevHandle);
        acm->ctrDevHandle = NULL;
    }
}

static int32_t AcmOpenInterfaces(struct AcmDevice *acm)
{
    for (int i = 0; i < acm->interfaceCnt; i++) {
        if (acm->iface[i]) {
            acm->devHandle[i] = UsbOpenInterface(acm->iface[i]);	// Open the UsbInterface object obtained.
            if (acm->devHandle[i] == NULL) {
                HDF_LOGE("%{public}s: UsbOpenInterface null", __func__);
                goto error;
            }
        }
    }
    acm->ctrDevHandle = UsbOpenInterface(acm->ctrIface);
    if (acm->ctrDevHandle == NULL) {
        HDF_LOGE("%{public}s: ctrDevHandle UsbOpenInterface null", __func__);
        goto error;
    }

    return HDF_SUCCESS;

error:
    AcmCloseInterfaces(acm);
    return HDF_FAILURE;
}

static int32_t AcmGetPipes(struct AcmDevice *acm)
{
    acm->dataInPipe = GetPipe(acm, USB_PIPE_TYPE_BULK, USB_PIPE_DIRECTION_IN); // Obtain pipe information of dataInPipe.
    if (acm->dataInPipe == NULL) {
        HDF_LOGE("dataInPipe is NULL");
        goto error;
    }

    acm->dataOutPipe = GetPipe(acm, USB_PIPE_TYPE_BULK, USB_PIPE_DIRECTION_OUT); // Obtain pipe information of dataOutPipe.
    if (acm->dataOutPipe == NULL) {
        HDF_LOGE("dataOutPipe is NULL");
        goto error;
    }

    acm->ctrPipe = EnumePipe(acm, acm->ctrIface->info.interfaceIndex, USB_PIPE_TYPE_CONTROL, USB_PIPE_DIRECTION_OUT);	// Obtain pipe information of the control pipe.
    if (acm->ctrPipe == NULL) {
        HDF_LOGE("ctrPipe is NULL");
        goto error;
    }

    acm->intPipe = GetPipe(acm, USB_PIPE_TYPE_INTERRUPT, USB_PIPE_DIRECTION_IN); // Obtain pipe information of the interrupt pipe.
    if (acm->intPipe == NULL) {
        HDF_LOGE("intPipe is NULL");
        goto error;
    }

    acm->readSize  = acm->dataInPipe->maxPacketSize;
    acm->writeSize = acm->dataOutPipe->maxPacketSize;
    acm->ctrlSize  = acm->ctrPipe->maxPacketSize;
    acm->intSize   = acm->intPipe->maxPacketSize;

    return HDF_SUCCESS;

error:
    AcmFreePipes(acm);
    return HDF_FAILURE;
}

static void AcmFreeRequests(struct AcmDevice *acm)
{
    if (g_syncRequest != NULL) {
        UsbFreeRequest(g_syncRequest);
        g_syncRequest = NULL;
    }
    AcmFreeReadRequests(acm);
    AcmFreeNotifyReqeust(acm);
    AcmFreeWriteRequests(acm);
    AcmWriteBufFree(acm);
}

static int32_t AcmAllocRequests(struct AcmDevice *acm)
{
    int32_t ret;

    if (AcmWriteBufAlloc(acm) < 0) {
        HDF_LOGE("%{public}s: AcmWriteBufAlloc failed", __func__);
        return HDF_ERR_MALLOC_FAIL;
    }

    for (int i = 0; i < ACM_NW; i++) {
        struct AcmWb *snd = &(acm->wb[i]);
        snd->request = UsbAllocRequest(InterfaceIdToHandle(acm, acm->dataOutPipe->interfaceId), 0, acm->writeSize);	// Allocate the I/O request object to be sent.
        snd->instance = acm;
        if (snd->request == NULL) {
            HDF_LOGE("%{public}s:%{public}d snd request fail", __func__, __LINE__);
            goto error_alloc_write_req;
        }
    }

    ret = AcmAllocNotifyRequest(acm);	// Allocate and fill in the interrupt I/O request object.
    if (ret != HDF_SUCCESS) {
        HDF_LOGE("%{public}s:%{public}d AcmAllocNotifyRequest fail", __func__, __LINE__);
        goto error_alloc_int_req;
    }

    ret = AcmAllocReadRequests(acm);	// Allocate and fill in the readReq I/O request object.
    if (ret) {
        HDF_LOGE("%{public}s:%{public}d AcmAllocReadRequests fail", __func__, __LINE__);
        goto error_alloc_read_req;
    }

    return HDF_SUCCESS;

error_alloc_read_req:
    AcmFreeNotifyReqeust(acm);
error_alloc_int_req:
    AcmFreeWriteRequests(acm);
error_alloc_write_req:
    AcmWriteBufFree(acm);
    return HDF_FAILURE;
}

static int32_t AcmInit(struct AcmDevice *acm)
{
    int32_t ret;
    struct UsbSession *session = NULL;

    if (acm->initFlag == true) {
        HDF_LOGE("%{public}s:%{public}d: initFlag is true", __func__, __LINE__);
        return HDF_SUCCESS;
    }

    ret = UsbInitHostSdk(NULL);	// Initialize the host DDK.
    if (ret != HDF_SUCCESS) {
        HDF_LOGE("%{public}s: UsbInitHostSdk failed", __func__);
        return HDF_ERR_IO;
    }
    acm->session = session;

    ret = AcmClaimInterfaces(acm);
    if (ret != HDF_SUCCESS) {
        HDF_LOGE("%{public}s: AcmClaimInterfaces failed", __func__);
        goto error_claim_interfaces;
    }

    ret = AcmOpenInterfaces(acm);
    if (ret != HDF_SUCCESS) {
        HDF_LOGE("%{public}s: AcmOpenInterfaces failed", __func__);
        goto error_open_interfaces;
    }

    ret = AcmGetPipes(acm);
    if (ret != HDF_SUCCESS) {
        HDF_LOGE("%{public}s: AcmGetPipes failed", __func__);
        goto error_get_pipes;
    }

    ret = AcmAllocRequests(acm);
    if (ret != HDF_SUCCESS) {
        HDF_LOGE("%{public}s: AcmAllocRequests failed", __func__);
        goto error_alloc_reqs;
    }

    acm->lineCoding.dwDTERate = CpuToLe32(DATARATE);
    acm->lineCoding.bCharFormat = CHARFORMAT;
    acm->lineCoding.bParityType = USB_CDC_NO_PARITY;
    acm->lineCoding.bDataBits = USB_CDC_1_STOP_BITS;
    acm->initFlag = true;

    HDF_LOGD("%{public}s:%{public}d========OK", __func__, __LINE__);
    return HDF_SUCCESS;

error_alloc_reqs:
    AcmFreePipes(acm);
error_get_pipes:
    AcmCloseInterfaces(acm);
error_open_interfaces:
    AcmReleaseInterfaces(acm);
error_claim_interfaces:
    UsbExitHostSdk(acm->session);
    acm->session = NULL;
    return ret;
}

static void AcmRelease(struct AcmDevice *acm)
{
    if (acm->initFlag == false) {
        HDF_LOGE("%{public}s:%{public}d: initFlag is false", __func__, __LINE__);
        return;
    }

    AcmFreeRequests(acm);
    AcmFreePipes(acm);
    AcmCloseInterfaces(acm);
    AcmReleaseInterfaces(acm);
    UsbExitHostSdk(acm->session);
    acm->session = NULL;

    acm->initFlag = false;
}

static int32_t UsbSerialDriverInit(struct HdfDeviceObject *device)
{
    int32_t ret;
    struct AcmDevice *acm = NULL;

    if (device == NULL) {
        HDF_LOGE("%{public}s: device is null", __func__);
        return HDF_ERR_INVALID_OBJECT;
    }
    acm = (struct AcmDevice *)device->service;
    OsalMutexInit(&acm->readLock);
    OsalMutexInit(&acm->writeLock);
    HDF_LOGD("%{public}s:%{public}d busNum=%{public}d,devAddr=%{public}d", \
        __func__, __LINE__, acm->busNum, acm->devAddr);

    ret = UsbSerialDeviceAlloc(acm);
    if (ret != HDF_SUCCESS) {
        HDF_LOGE("%{public}s: Serial Device alloc failed", __func__);
    }

    acm->initFlag = false;
    g_acmReleaseFlag = false;

    HDF_LOGD("%{public}s:%{public}d init ok!", __func__, __LINE__);

    return ret;
}

static void UsbSerialDriverRelease(struct HdfDeviceObject *device)
{
    struct AcmDevice *acm = NULL;

    if (device == NULL) {
        HDF_LOGE("%{public}s: device is NULL", __func__);
        return;
    }
    acm = (struct AcmDevice *)device->service;
    if (acm == NULL) {
        HDF_LOGE("%{public}s: acm is null", __func__);
        return;
    }

    g_acmReleaseFlag = true;

    if (acm->initFlag == true) {
        HDF_LOGE("%{public}s:%{public}d AcmRelease", __func__, __LINE__);
        AcmRelease(acm);
    }
    UsbSeriaDevicelFree(acm);
    OsalMutexDestroy(&acm->writeLock);
    OsalMutexDestroy(&acm->readLock);
    OsalMutexDestroy(&acm->lock);
    OsalMemFree(acm);
    acm = NULL;
    HDF_LOGD("%{public}s:%{public}d exit", __func__, __LINE__);
}

struct HdfDriverEntry g_usbSerialDriverEntry = {
    .moduleVersion = 1,
    .moduleName    = "usbhost_acm",	// Driver module name, which must be the same as that configured in the .hcs file.
    .Bind          = UsbSerialDriverBind,
    .Init          = UsbSerialDriverInit,
    .Release       = UsbSerialDriverRelease,
};
HDF_INIT(g_usbSerialDriverEntry);
```

### Developing Driver Using Host Raw APIs<a name="section3571192072014"></a>

```
root {
    module = "usb_pnp_device";
    usb_pnp_config {
        match_attr = "usb_pnp_match";
        usb_pnp_device_id = "UsbPnpDeviceId";
        UsbPnpDeviceId {
            idTableList = [
                "host_acm_rawapi_table"
            ];
            host_acm_rawapi_table {	// Driver mapping table information.
				// Driver module name, which must be the same as the value of moduleName in the driver entry structure.
                moduleName = "usbhost_acm_rawapi";
				// Service name of the driver, which must be unique.
                serviceName = "usbhost_acm_rawapi_service";
				// Keyword for matching private driver data.
                deviceMatchAttr = "usbhost_acm_rawapi_matchAttr";
				// Data length starting from this field, in bytes.
				length = 21;
				// USB driver matching rule: vendorId+productId+interfaceSubClass+interfaceProtocol+interfaceNumber.
                matchFlag = 0x0303;
				// Vendor ID.
                vendorId = 0x12D1;
				// Product ID.
                productId = 0x5000;
				// The least significant 16 bits of the device sequence number.
                bcdDeviceLow = 0x0000;
				// The most significant 16 bits of the device sequence number.
                bcdDeviceHigh = 0x0000;
				// Device class code allocated by the USB.
                deviceClass = 0;
				// Child class code allocated by the USB.
                deviceSubClass = 0;
				// Device protocol code allocated by the USB.
                deviceProtocol = 0;
				// Interface type. You can enter multiple types as needed.
                interfaceClass = [0];
				// Interface subtype. You can enter multiple subtypes as needed.
                interfaceSubClass = [2, 0];
				// Protocol that the interface complies with. You can enter multiple protocols as needed.
                interfaceProtocol = [1, 2];
				// Interface numer. You can enter multiple interface numbers as needed.
                interfaceNumber = [2, 3];
            }
        }
    }
}

#include "usb_serial_rawapi.h"
#include <unistd.h>
#include "osal_mem.h"
#include "osal_time.h"
#include "securec.h"
#include "hdf_base.h"
#include "hdf_log.h"
#include "hdf_usb_pnp_manage.h"

#define HDF_LOG_TAG                     USB_HOST_ACM_RAW_API
#define USB_CTRL_REQ_SIZE               64
#define USB_IO_THREAD_STACK_SIZE        8192
#define USB_RAW_IO_SLEEP_MS_TIME        100
#define USB_RAW_IO_STOP_WAIT_MAX_TIME   3

static struct UsbRawRequest *g_syncRequest = NULL;
static UsbRawIoProcessStatusType g_stopIoStatus = USB_RAW_IO_PROCESS_RUNNING;
struct OsalMutex g_stopIoLock;
static bool g_rawAcmReleaseFlag = false;
......

static int UsbGetConfigDescriptor(UsbRawHandle *devHandle, struct UsbRawConfigDescriptor **config)
{
    UsbRawDevice *dev = NULL;
    int activeConfig;
    int ret;

    if (devHandle == NULL) {
        HDF_LOGE("%{public}s:%{public}d devHandle is NULL",
                 __func__, __LINE__);
        return HDF_ERR_INVALID_PARAM;
    }

    ret = UsbRawGetConfiguration(devHandle, &activeConfig);
    if (ret) {
        HDF_LOGE("%{public}s:%{public}d UsbRawGetConfiguration failed, ret=%{public}d",
                 __func__, __LINE__, ret);
        return HDF_FAILURE;
    }
    HDF_LOGE("%{public}s:%{public}d activeConfig=%{public}d", __func__, __LINE__, activeConfig);
    dev = UsbRawGetDevice(devHandle);
    if (dev == NULL) {
        HDF_LOGE("%{public}s:%{public}d UsbRawGetDevice failed",
                 __func__, __LINE__);
        return HDF_FAILURE;
    }

    ret = UsbRawGetConfigDescriptor(dev, activeConfig, config);
    if (ret) {
        HDF_LOGE("UsbRawGetConfigDescriptor failed, ret=%{public}d\n", ret);
        return HDF_FAILURE;
    }

    return HDF_SUCCESS;
}
...
static int UsbAllocWriteRequests(struct AcmDevice *acm)
{
    int i;

    for (i = 0; i < ACM_NW; i++) {
        struct AcmWb *snd = &acm->wb[i];
        snd->request = UsbRawAllocRequest(acm->devHandle, 0, acm->dataOutEp->maxPacketSize);
        snd->instance = acm;
        if (snd->request == NULL) {
            HDF_LOGE("%{public}s: UsbRawAllocRequest failed", __func__);
            return HDF_ERR_MALLOC_FAIL;
        }
    }

    return HDF_SUCCESS;
}
...
/* HdfDriverEntry implementations */
static int32_t UsbSerialDriverBind(struct HdfDeviceObject *device)
{
    struct AcmDevice *acm = NULL;
    struct UsbPnpNotifyServiceInfo *info = NULL;
    errno_t err;

    if (device == NULL) {
        HDF_LOGE("%s: device is null", __func__);
        return HDF_ERR_INVALID_OBJECT;
    }

    acm = (struct AcmDevice *)OsalMemCalloc(sizeof(*acm));
    if (acm == NULL) {
        HDF_LOGE("%s: Alloc usb serial device failed", __func__);
        return HDF_FAILURE;
    }
    if (OsalMutexInit(&acm->lock) != HDF_SUCCESS) {
        HDF_LOGE("%s:%d OsalMutexInit fail", __func__, __LINE__);
        goto error;
    }

    info = (struct UsbPnpNotifyServiceInfo *)device->priv;
    if (info != NULL) {
        acm->busNum       = info->busNum;
        acm->devAddr      = info->devNum;
        acm->interfaceCnt = info->interfaceLength;
        err = memcpy_s((void *)(acm->interfaceIndex), USB_MAX_INTERFACES,
                       (const void*)info->interfaceNumber, info->interfaceLength);
        if (err != EOK) {
            HDF_LOGE("%s:%d memcpy_s failed err=%d", \
                __func__, __LINE__, err);
            goto lock_error;
        }
    } else {
        HDF_LOGE("%s:%d info is NULL!", __func__, __LINE__);
        goto lock_error;
    }

    device->service = &(acm->service);
    device->service->Dispatch = UsbSerialDeviceDispatch;
    acm->device = device;
    HDF_LOGD("UsbSerialDriverBind=========================OK");
    return HDF_SUCCESS;

lock_error:
    if (OsalMutexDestroy(&acm->lock)) {
        HDF_LOGE("%s:%d OsalMutexDestroy fail", __func__, __LINE__);
    }
error:
    OsalMemFree(acm);
    acm = NULL;
    return HDF_FAILURE;
}
...
static int UsbAllocReadRequests(struct AcmDevice *acm)
{
    struct UsbRawFillRequestData reqData;
    int size = acm->dataInEp->maxPacketSize;
    int ret;

    for (int i = 0; i < ACM_NR; i++) {
        acm->readReq[i] = UsbRawAllocRequest(acm->devHandle, 0, size);
        if (!acm->readReq[i]) {
            HDF_LOGE("readReq request failed\n");
            return HDF_ERR_MALLOC_FAIL;
        }

        reqData.endPoint      = acm->dataInEp->addr;
        reqData.numIsoPackets = 0;
        reqData.callback      = AcmReadBulkCallback;
        reqData.userData      = (void *)acm;
        reqData.timeout       = USB_CTRL_SET_TIMEOUT;
        reqData.length        = size;

        ret = UsbRawFillBulkRequest(acm->readReq[i], acm->devHandle, &reqData);
        if (ret) {
            HDF_LOGE("%{public}s: FillBulkRequest faile, ret=%{public}d \n",
                     __func__, ret);
            return HDF_FAILURE;
        }
    }

    return HDF_SUCCESS;
}
...
static int UsbAllocNotifyRequest(struct AcmDevice *acm)
{
    struct UsbRawFillRequestData fillRequestData;
    int size = acm->notifyEp->maxPacketSize;
    int ret;

    acm->notifyReq = UsbRawAllocRequest(acm->devHandle, 0, size);
    if (!acm->notifyReq) {
        HDF_LOGE("notifyReq request fail\n");
        return HDF_ERR_MALLOC_FAIL;
    }

    fillRequestData.endPoint = acm->notifyEp->addr;
    fillRequestData.length = size;
    fillRequestData.numIsoPackets = 0;
    fillRequestData.callback = AcmNotifyReqCallback;
    fillRequestData.userData = (void *)acm;
    fillRequestData.timeout = USB_CTRL_SET_TIMEOUT;

    ret = UsbRawFillInterruptRequest(acm->notifyReq, acm->devHandle, &fillRequestData);
    if (ret) {
        HDF_LOGE("%{public}s: FillInterruptRequest faile, ret=%{public}d", __func__, ret);
        return HDF_FAILURE;
    }

    return HDF_SUCCESS;
}
...
static int32_t UsbSerialInit(struct AcmDevice *acm)
{
    struct UsbSession *session = NULL;
    UsbRawHandle *devHandle = NULL;
    int32_t ret;

    if (acm->initFlag == true) {
        HDF_LOGE("%{public}s:%{public}d: initFlag is true", __func__, __LINE__);
        return HDF_SUCCESS;
    }

    ret = UsbRawInit(NULL);
    if (ret) {
        HDF_LOGE("%{public}s:%{public}d UsbRawInit failed", __func__, __LINE__);
        return HDF_ERR_IO;
    }
    acm->session = session;

    devHandle = UsbRawOpenDevice(session, acm->busNum, acm->devAddr);
    if (devHandle == NULL) {
        HDF_LOGE("%{public}s:%{public}d UsbRawOpenDevice failed", __func__, __LINE__);
        ret =  HDF_FAILURE;
        goto err_open_device;
    }
    acm->devHandle = devHandle;
    ret = UsbGetConfigDescriptor(devHandle, &acm->config);
    if (ret) {
        HDF_LOGE("%{public}s:%{public}d UsbGetConfigDescriptor failed", __func__, __LINE__);
        ret =  HDF_FAILURE;
        goto err_get_desc;
    }
    ret = UsbParseConfigDescriptor(acm, acm->config);
    if (ret != HDF_SUCCESS) {
        HDF_LOGE("%{public}s:%{public}d UsbParseConfigDescriptor failed", __func__, __LINE__);
        ret = HDF_FAILURE;
        goto err_parse_desc;
    }

    ret = AcmWriteBufAlloc(acm);
    if (ret < 0) {
        HDF_LOGE("%{public}s:%{public}d AcmWriteBufAlloc failed", __func__, __LINE__);
        ret = HDF_FAILURE;
        goto err_alloc_write_buf;
    }
    ret = UsbAllocWriteRequests(acm);
    if (ret < 0) {
        HDF_LOGE("%{public}s:%{public}d UsbAllocWriteRequests failed", __func__, __LINE__);
        ret = HDF_FAILURE;
        goto err_alloc_write_reqs;
    }
    ret = UsbAllocNotifyRequest(acm);
    if (ret) {
        HDF_LOGE("%{public}s:%{public}d UsbAllocNotifyRequests failed", __func__, __LINE__);
        goto err_alloc_notify_req;
    }
    ret = UsbAllocReadRequests(acm);
    if (ret) {
        HDF_LOGE("%{public}s:%{public}d UsbAllocReadRequests failed", __func__, __LINE__);
        goto err_alloc_read_reqs;
    }
    ret = UsbStartIo(acm);
    if (ret) {
        HDF_LOGE("%{public}s:%{public}d UsbAllocReadRequests failed", __func__, __LINE__);
        goto err_start_io;
    }

    acm->lineCoding.dwDTERate   = CpuToLe32(DATARATE);
    acm->lineCoding.bCharFormat = CHARFORMAT;
    acm->lineCoding.bParityType = USB_CDC_NO_PARITY;
    acm->lineCoding.bDataBits   = USB_CDC_1_STOP_BITS;

    ret = UsbRawSubmitRequest(acm->notifyReq);
    if (ret) {
        HDF_LOGE("%{public}s:%{public}d UsbRawSubmitRequest failed", __func__, __LINE__);
        goto err_submit_req;
    }

    acm->initFlag = true;

    HDF_LOGD("%{public}s:%{public}d=========================OK", __func__, __LINE__);

    return HDF_SUCCESS;

err_submit_req:
    UsbStopIo(acm);
err_start_io:
    UsbFreeReadRequests(acm);
err_alloc_read_reqs:
    UsbFreeNotifyReqeust(acm);
 err_alloc_notify_req:
    UsbFreeWriteRequests(acm);
err_alloc_write_reqs:
    AcmWriteBufFree(acm);
err_alloc_write_buf:
    UsbReleaseInterfaces(acm);
err_parse_desc:
    UsbRawFreeConfigDescriptor(acm->config);
    acm->config = NULL;
err_get_desc:
    (void)UsbRawCloseDevice(devHandle);
err_open_device:
    UsbRawExit(acm->session);

    return ret;
}

static void UsbSerialRelease(struct AcmDevice *acm)
{
    if (acm->initFlag == false) {
        HDF_LOGE("%{public}s:%{public}d: initFlag is false", __func__, __LINE__);
        return;
    }

    /* stop io thread and release all resources */
    UsbStopIo(acm);
    if (g_syncRequest != NULL) {
        UsbRawFreeRequest(g_syncRequest);
        g_syncRequest = NULL;
    }
    UsbFreeReadRequests(acm);
    UsbFreeNotifyReqeust(acm);
    UsbFreeWriteRequests(acm);
    AcmWriteBufFree(acm);
    (void)UsbRawCloseDevice(acm->devHandle);
    UsbReleaseInterfaces(acm);
    UsbRawFreeConfigDescriptor(acm->config);
    acm->config = NULL;
    UsbRawExit(acm->session);

    acm->initFlag = false;
}

static int32_t UsbSerialDriverInit(struct HdfDeviceObject *device)
{
    struct AcmDevice *acm = NULL;
    int32_t ret;

    if (device == NULL) {
        HDF_LOGE("%{public}s:%{public}d device is null", __func__, __LINE__);
        return HDF_ERR_INVALID_OBJECT;
    }
    acm = (struct AcmDevice *)device->service;
    OsalMutexInit(&acm->readLock);
    OsalMutexInit(&acm->writeLock);

    ret = UsbSerialDeviceAlloc(acm);
    if (ret != HDF_SUCCESS) {
        HDF_LOGE("%{public}s:%{public}d UsbSerialDeviceAlloc failed", __func__, __LINE__);
    }

    acm->initFlag = false;
    g_rawAcmReleaseFlag = false;

    HDF_LOGD("%{public}s:%{public}d init ok!", __func__, __LINE__);

    return ret;
}

static void UsbSerialDriverRelease(struct HdfDeviceObject *device)
{
    struct AcmDevice *acm = NULL;
    if (device == NULL) {
        HDF_LOGE("%{public}s: device is NULL", __func__);
        return;
    }

    acm = (struct AcmDevice *)device->service;
    if (acm == NULL) {
        HDF_LOGE("%{public}s: acm is null", __func__);
        return;
    }

    g_rawAcmReleaseFlag = true;

    if (acm->initFlag == true) {
        HDF_LOGE("%{public}s:%{public}d UsbSerialRelease", __func__, __LINE__);
        UsbSerialRelease(acm);
    }
    UsbSeriaDevicelFree(acm);
    OsalMutexDestroy(&acm->writeLock);
    OsalMutexDestroy(&acm->readLock);
    OsalMutexDestroy(&acm->lock);
    OsalMemFree(acm);
    acm = NULL;
    HDF_LOGD("%{public}s:%{public}d exit", __func__, __LINE__);
}

struct HdfDriverEntry g_usbSerialRawDriverEntry = {
    .moduleVersion = 1,
    .moduleName    = "usbhost_acm_rawapi",	// Driver module name, which must be the same as that configured in the .hcs file.
    .Bind          = UsbSerialDriverBind,
    .Init          = UsbSerialDriverInit,
    .Release       = UsbSerialDriverRelease,
};
HDF_INIT(g_usbSerialRawDriverEntry);
```

### Developing Driver Using Device DDK APIs<a name="section6356758162015"></a>
The core code of the USB Abstract Control Model (ACM) device is available in **drivers\peripheral\usb\gadget\function\acm\cdcacm.c**. The following is an example.

```
1. Create a device.
static int32_t AcmCreateFuncDevice(struct UsbAcmDevice *acm,
    struct DeviceResourceIface *iface)
{
    struct UsbFnDevice *fnDev = NULL;
struct UsbFnDescriptorData descData;
uint8_t useHcs;
 	...
if (useHcs == 0) {
    descData.type = USBFN_DESC_DATA_TYPE_DESC;
    descData.descriptor = &g_masterFuncDevice;
} else {
    descData.type = USBFN_DESC_DATA_TYPE_PROP;
    descData.property = device->property;
}
/* Create a device. */
    fnDev = (struct UsbFnDevice *)UsbFnDeviceCreate(acm->udcName, &descData);
    if (fnDev == NULL) {
        HDF_LOGE("%{public}s: create usb function device failed", __func__);
        return HDF_FAILURE;
    }
    ...
}
2. Obtain an interface and open the interface for pipe information.
static int32_t AcmParseEachPipe(struct UsbAcmDevice *acm, struct UsbAcmInterface *iface)
{
    ...
    for (i = 0; i < fnIface->info.numPipes; i++) {
        struct UsbFnPipeInfo pipeInfo;
/* Obtain pipe information. */
        ret = UsbFnInterfaceGetPipeInfo(fnIface, i, &pipeInfo);
        ...
    }
    return HDF_SUCCESS;
}
/* Obtain the interface and open the interface to obtain the handle. */
static int32_t AcmParseEachIface(struct UsbAcmDevice *acm, struct UsbFnDevice *fnDev)
{
    ...
    for (i = 0; i < fnDev->numInterfaces; i++) {
        /* Obtain an interface.*/
        fnIface = (struct UsbFnInterface *)UsbFnDeviceGetInterface(fnDev, i);
        ...
        /* Open the interface. */
        handle = UsbFnInterfaceOpen(fnIface);
        ...
    }
    return HDF_SUCCESS;
}
3. Receive events.
static int32_t AcmAllocCtrlRequests(struct UsbAcmDevice *acm, int num)
{
    ...
        req = UsbFnCtrlRequestAlloc(acm->ctrlIface.handle,
            sizeof(struct UsbCdcLineCoding) + sizeof(struct UsbCdcLineCoding));
    ...
}
static int32_t AcmDriverInit(struct HdfDeviceObject *device)
{
...    
/* Start to receive events.*/
    ret = UsbFnInterfaceStartRecvEvent(acm->ctrlIface.fn, 0xff, UsbAcmEventCallback, acm);
    ...
}
4. Perform USB communication (read and write).
static int32_t AcmSendNotifyRequest(struct UsbAcmDevice *acm, uint8_t type,
    uint16_t value, void *data, uint32_t length)
{
...
/* Send a request asynchronously. */
    ret = UsbFnRequestSubmitAsync(req); 
    ...
}
5. Close the interface, stop receiving events, and remove the device.
static int32_t AcmReleaseFuncDevice(struct UsbAcmDevice *acm)
{
int32_t ret;
/* Close the interface. */
    (void)UsbFnInterfaceClose(acm->ctrlIface.handle);
(void)UsbFnInterfaceClose(acm->dataIface.handle);
/* Stop receiving events. */
(void)UsbFnInterfaceStopRecvEvent(acm->ctrlIface.fn);
/* Remove the device. */
    ret = UsbFnDeviceRemove(acm->fnDev);
    if (ret != HDF_SUCCESS) {
        HDF_LOGE("%{public}s: remove usb function device failed", __func__);
    }
    return ret;
}
```
