# USB<a name="EN-US_TOPIC_0000001228574475"></a>

-   [Overview](#section127mcpsimp)
    -   [Available APIs](#section141mcpsimp)

-   [Development Guidelines](#section581mcpsimp)
    -   [Developing Driver Using Host DDK APIs](#section584mcpsimp)
    -   [Developing Driver Using Host Raw APIs](#section594mcpsimp)
    -   [Developing Driver Using Device DDK APIs](#section600mcpsimp)

-   [Development Examples](#section607mcpsimp)
    -   [Developing Driver Using Host DDK APIs](#section609mcpsimp)
    -   [Developing Driver Using Host Raw APIs](#section612mcpsimp)
    -   [Developing Driver Using Device DDK APIs](#section615mcpsimp)


## Overview<a name="section127mcpsimp"></a>

USB host development aims to provide host-related functions, including protocol encapsulation, device management, and driver installation and uninstall.

USB device development aims to provide device-related functions, including device management, configuration management, and I/O management. These functions implement creation, configuration, and data communication of USB devices.

The following figures show the UBS host and device driver models.

**Figure 1** USB host driver model<a name="fig1649563542917"></a>
![](figures/USB_host_driver_model.png "USB host driver model")

**Figure 2** USB device driver model<a name="fig8847615103013"></a>
![](figures/USB_device_driver_model.png "USB device driver model")

The USB driver model offers the following APIs:

-   The USB host Driver Development Kit (DDK) provides driver capability APIs that can be directly called in user mode. The APIs can be classified into the DDK initialization class, interface operation class, and request operation class by function. These APIs can be used to perform DDK initialization, bind/release and open/close an interface, allocate/release a request, and implement synchronous or asynchronous transfer.
-   The USB device DDK provides device management, I/O management, and configuration management APIs, which can be used to create and delete a device, obtain/open an interface, and perform synchronous or asynchronous transfer.

### Available APIs(<a name="section141mcpsimp"></a>)

[Figure 1](#fig1649563542917) describes the APIs provided by the USB host driver model.

**Table 1** APIs provided by the USB host driver model

<a name="table11474102882612"></a>
<table><thead align="left"><tr id="row1147413289268"><th class="cellrowborder" valign="top" width="33.33333333333333%" id="mcps1.2.4.1.1"><p id="p1966391682713"><a name="p1966391682713"></a><a name="p1966391682713"></a>Header File</p>
</th>
<th class="cellrowborder" valign="top" width="33.33333333333333%" id="mcps1.2.4.1.2"><p id="p166313167274"><a name="p166313167274"></a><a name="p166313167274"></a>API</p>
</th>
<th class="cellrowborder" valign="top" width="33.33333333333333%" id="mcps1.2.4.1.3"><p id="p1066341602710"><a name="p1066341602710"></a><a name="p1066341602710"></a> Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1275799122710"><td class="cellrowborder" rowspan="16" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.1 "><p id="p4725109162716"><a name="p4725109162716"></a><a name="p4725109162716"></a>usb_ddk_interface.h</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.2 "><p id="p17725698274"><a name="p17725698274"></a><a name="p17725698274"></a>int32_t UsbInitHostSdk(struct UsbSession **session);</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.3 "><p id="p27252992712"><a name="p27252992712"></a><a name="p27252992712"></a>Initializes the USB host driver DDK.</p>
</td>
</tr>
<tr id="row775779172719"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p14725149172712"><a name="p14725149172712"></a><a name="p14725149172712"></a>int32_t UsbExitHostSdk(const struct UsbSession *session);</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p172549192711"><a name="p172549192711"></a><a name="p172549192711"></a>Exits the USB host driver DDK.</p>
</td>
</tr>
<tr id="row975769172712"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p167251791278"><a name="p167251791278"></a><a name="p167251791278"></a>const struct UsbInterface *UsbClaimInterface(const struct UsbSession *session, uint8_t busNum, uint8_t usbAddr, uint8_t interfaceIndex);</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p187255962716"><a name="p187255962716"></a><a name="p187255962716"></a>Obtains a USB interface.</p>
</td>
</tr>
<tr id="row97577920273"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p16725497276"><a name="p16725497276"></a><a name="p16725497276"></a>int UsbReleaseInterface(const struct UsbInterface *interfaceObj);</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p117251894270"><a name="p117251894270"></a><a name="p117251894270"></a>Releases a USB interface.</p>
</td>
</tr>
<tr id="row67574982718"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p872514915277"><a name="p872514915277"></a><a name="p872514915277"></a>int UsbAddOrRemoveInterface(const struct UsbSession *session, uint8_t busNum, uint8_t usbAddr, uint8_t interfaceIndex, UsbInterfaceStatus status);</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p157251914278"><a name="p157251914278"></a><a name="p157251914278"></a>Adds or removes a USB interface.</p>
</td>
</tr>
<tr id="row47576942720"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p572517916275"><a name="p572517916275"></a><a name="p572517916275"></a>UsbInterfaceHandle *UsbOpenInterface(const struct UsbInterface *interfaceObj);</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p67254915272"><a name="p67254915272"></a><a name="p67254915272"></a>Opens a USB interface.</p>
</td>
</tr>
<tr id="row197579952713"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p472514912712"><a name="p472514912712"></a><a name="p472514912712"></a>int32_t UsbCloseInterface(const UsbInterfaceHandle *interfaceHandle);</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p67251095276"><a name="p67251095276"></a><a name="p67251095276"></a>Closes a USB interface.</p>
</td>
</tr>
<tr id="row15757894278"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p5725169192717"><a name="p5725169192717"></a><a name="p5725169192717"></a>int32_t UsbSelectInterfaceSetting(const UsbInterfaceHandle *interfaceHandle, uint8_t settingIndex, struct UsbInterface **interfaceObj);</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p6725109112720"><a name="p6725109112720"></a><a name="p6725109112720"></a>Sets a USB interface.</p>
</td>
</tr>
<tr id="row107579932715"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p11725199182715"><a name="p11725199182715"></a><a name="p11725199182715"></a>int32_t UsbGetPipeInfo(const UsbInterfaceHandle *interfaceHandle, uint8_t settingIndex, uint8_t pipeId, struct UsbPipeInfo *pipeInfo);</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p107261298272"><a name="p107261298272"></a><a name="p107261298272"></a>Obtains USB pipe information.</p>
</td>
</tr>
<tr id="row27577992716"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p8726890275"><a name="p8726890275"></a><a name="p8726890275"></a>int32_t UsbClearInterfaceHalt(const UsbInterfaceHandle *interfaceHandle, uint8_t pipeAddress);</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p177261797274"><a name="p177261797274"></a><a name="p177261797274"></a>Clears the state of the pipe with the specified index.</p>
</td>
</tr>
<tr id="row1757189172714"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p1726998273"><a name="p1726998273"></a><a name="p1726998273"></a>struct UsbRequest *UsbAllocRequest(const UsbInterfaceHandle *interfaceHandle, int isoPackets, int length);</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p1272617982713"><a name="p1272617982713"></a><a name="p1272617982713"></a>Allocates a request object.</p>
</td>
</tr>
<tr id="row07579911279"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p187261911279"><a name="p187261911279"></a><a name="p187261911279"></a>int UsbFreeRequest(const struct UsbRequest *request);</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p177271592271"><a name="p177271592271"></a><a name="p177271592271"></a>Releases a request object.</p>
</td>
</tr>
<tr id="row075759142715"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p3727896271"><a name="p3727896271"></a><a name="p3727896271"></a>int UsbSubmitRequestAsync(const struct UsbRequest *request);</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p372714942718"><a name="p372714942718"></a><a name="p372714942718"></a>Sends an asynchronous request.</p>
</td>
</tr>
<tr id="row1475718919272"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p1727698272"><a name="p1727698272"></a><a name="p1727698272"></a>int32_t UsbFillRequest(const struct UsbRequest *request, const UsbInterfaceHandle *interfaceHandle, const struct UsbRequestParams *params);</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p872713910270"><a name="p872713910270"></a><a name="p872713910270"></a>Fills in a request.</p>
</td>
</tr>
<tr id="row117576932710"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p9727291278"><a name="p9727291278"></a><a name="p9727291278"></a>sint UsbCancelRequest(const struct UsbRequest *request);</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p37271897276"><a name="p37271897276"></a><a name="p37271897276"></a>Cancels an asynchronous request.</p>
</td>
</tr>
<tr id="row1475714912715"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p2727698275"><a name="p2727698275"></a><a name="p2727698275"></a>int UsbSubmitRequestSync(const struct UsbRequest *request);</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p87279914277"><a name="p87279914277"></a><a name="p87279914277"></a>Sends a synchronous request.</p>
</td>
</tr>
<tr id="row11756097274"><td class="cellrowborder" rowspan="27" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.1 "><p id="p12727179132710"><a name="p12727179132710"></a><a name="p12727179132710"></a>usb_raw_api.h</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.2 "><p id="p11727391272"><a name="p11727391272"></a><a name="p11727391272"></a>int UsbRawInit(struct UsbSession **session);</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.3 "><p id="p1572711919272"><a name="p1572711919272"></a><a name="p1572711919272"></a>Initializes the USB raw APIs.</p>
</td>
</tr>
<tr id="row1575629182713"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p372711918279"><a name="p372711918279"></a><a name="p372711918279"></a>int UsbRawExit(const struct UsbSession *session);</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p372710942717"><a name="p372710942717"></a><a name="p372710942717"></a>Exits the USB raw APIs.</p>
</td>
</tr>
<tr id="row5756999270"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p8727291277"><a name="p8727291277"></a><a name="p8727291277"></a>UsbRawHandle *UsbRawOpenDevice(const struct UsbSession *session, uint8_t busNum, uint8_t usbAddr);</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p1772719972717"><a name="p1772719972717"></a><a name="p1772719972717"></a>Opens a USB device.</p>
</td>
</tr>
<tr id="row117561292270"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p772709122715"><a name="p772709122715"></a><a name="p772709122715"></a>int UsbRawCloseDevice(const UsbRawHandle *devHandle);</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p1372715902711"><a name="p1372715902711"></a><a name="p1372715902711"></a>Closes a USB device.</p>
</td>
</tr>
<tr id="row775689182714"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p197272918272"><a name="p197272918272"></a><a name="p197272918272"></a>int UsbRawSendControlRequest(const struct UsbRawRequest *request, const UsbRawHandle *devHandle, const struct UsbControlRequestData *requestData);</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p272715932717"><a name="p272715932717"></a><a name="p272715932717"></a>Performs a control transfer synchronously.</p>
</td>
</tr>
<tr id="row3756179132714"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p1727296276"><a name="p1727296276"></a><a name="p1727296276"></a>int UsbRawSendBulkRequest(const struct UsbRawRequest *request, const UsbRawHandle *devHandle, const struct UsbRequestData *requestData);</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p872789162713"><a name="p872789162713"></a><a name="p872789162713"></a>Performs a bulk transfer synchronously.</p>
</td>
</tr>
<tr id="row27568916276"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p1072719992711"><a name="p1072719992711"></a><a name="p1072719992711"></a>int UsbRawSendInterruptRequest(const struct UsbRawRequest *request, const UsbRawHandle *devHandle, const struct UsbRequestData *requestData);</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p117271895271"><a name="p117271895271"></a><a name="p117271895271"></a>Performs an interrupt transfer synchronously.</p>
</td>
</tr>
<tr id="row14756149112710"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p772711917274"><a name="p772711917274"></a><a name="p772711917274"></a>int UsbRawGetConfigDescriptor(const UsbRawDevice *rawDev, uint8_t configIndex, struct UsbRawConfigDescriptor **config);</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p472714912710"><a name="p472714912710"></a><a name="p472714912710"></a>Obtains the configuration descriptor of a device.</p>
</td>
</tr>
<tr id="row1775614902711"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p37277942718"><a name="p37277942718"></a><a name="p37277942718"></a>void UsbRawFreeConfigDescriptor(const struct UsbRawConfigDescriptor *config);</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p772759162711"><a name="p772759162711"></a><a name="p772759162711"></a>Releases the memory space of a configuration descriptor.</p>
</td>
</tr>
<tr id="row9756119182711"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p3727699274"><a name="p3727699274"></a><a name="p3727699274"></a>int UsbRawGetConfiguration(const UsbRawHandle *devHandle, int *config);</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p13728109192717"><a name="p13728109192717"></a><a name="p13728109192717"></a>Obtains the configuration in use.</p>
</td>
</tr>
<tr id="row37567922714"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p1872849162718"><a name="p1872849162718"></a><a name="p1872849162718"></a>int UsbRawSetConfiguration(const UsbRawHandle *devHandle, int config);</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p87280914277"><a name="p87280914277"></a><a name="p87280914277"></a>Sets the configuration in use.</p>
</td>
</tr>
<tr id="row1775612982711"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p127283902712"><a name="p127283902712"></a><a name="p127283902712"></a>int UsbRawGetDescriptor(const struct UsbRawRequest *request, const UsbRawHandle *devHandle, const struct UsbRawDescriptorParam *param, const unsigned char *data);</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p17728209122710"><a name="p17728209122710"></a><a name="p17728209122710"></a>Obtains descriptor information.</p>
</td>
</tr>
<tr id="row97564992719"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p1672849122712"><a name="p1672849122712"></a><a name="p1672849122712"></a>UsbRawDevice *UsbRawGetDevice(const UsbRawHandle *devHandle);</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p472879202719"><a name="p472879202719"></a><a name="p472879202719"></a>Obtains the device pointer based on the device handle.</p>
</td>
</tr>
<tr id="row1075612922718"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p172814982715"><a name="p172814982715"></a><a name="p172814982715"></a>int UsbRawGetDeviceDescriptor(const UsbRawDevice *rawDev, struct UsbDeviceDescriptor *desc);</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p8728139172715"><a name="p8728139172715"></a><a name="p8728139172715"></a>Obtains the device descriptor of the specified USB device.</p>
</td>
</tr>
<tr id="row117561919273"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p072820912714"><a name="p072820912714"></a><a name="p072820912714"></a>int UsbRawClaimInterface(const UsbRawHandle *devHandle, int interfaceNumber);</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p972817914279"><a name="p972817914279"></a><a name="p972817914279"></a>Declares the interface on the specified device handle.</p>
</td>
</tr>
<tr id="row87561920275"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p2728191276"><a name="p2728191276"></a><a name="p2728191276"></a>int UsbRawReleaseInterface(const UsbRawHandle *devHandle, int interfaceNumber);</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p8728159102710"><a name="p8728159102710"></a><a name="p8728159102710"></a>Releases the previously declared interface.</p>
</td>
</tr>
<tr id="row375679152710"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p137281192274"><a name="p137281192274"></a><a name="p137281192274"></a>int UsbRawResetDevice(const UsbRawHandle *devHandle);</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p107281992272"><a name="p107281992272"></a><a name="p107281992272"></a>Resets a device.</p>
</td>
</tr>
<tr id="row14756109152719"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p137288914273"><a name="p137288914273"></a><a name="p137288914273"></a>struct UsbRawRequest *UsbRawAllocRequest(const UsbRawHandle *devHandle, int isoPackets, int length);</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p27281797274"><a name="p27281797274"></a><a name="p27281797274"></a>Allocates a transfer request with the specified number of sync packet descriptors.</p>
</td>
</tr>
<tr id="row07560932714"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p2072810912713"><a name="p2072810912713"></a><a name="p2072810912713"></a>int UsbRawFreeRequest(const struct UsbRawRequest *request);</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p17281917278"><a name="p17281917278"></a><a name="p17281917278"></a>Releases the previously allocated transfer request.</p>
</td>
</tr>
<tr id="row1775615952717"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p1872810915274"><a name="p1872810915274"></a><a name="p1872810915274"></a>int UsbRawFillBulkRequest(const struct UsbRawRequest *request, const UsbRawHandle *devHandle, const struct UsbRawFillRequestData *fillData);</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p117281090271"><a name="p117281090271"></a><a name="p117281090271"></a>Fills in a bulk transfer request.</p>
</td>
</tr>
<tr id="row675659172716"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p1272820962719"><a name="p1272820962719"></a><a name="p1272820962719"></a>int UsbRawFillControlSetup(const unsigned char *setup, const struct UsbControlRequestData *requestData);</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p177281299278"><a name="p177281299278"></a><a name="p177281299278"></a>Fills in a control setup packet.</p>
</td>
</tr>
<tr id="row97563912271"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p1372817914277"><a name="p1372817914277"></a><a name="p1372817914277"></a>int UsbRawFillControlRequest(const struct UsbRawRequest *request, const UsbRawHandle *devHandle, const struct UsbRawFillRequestData *fillData);</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p1372815952715"><a name="p1372815952715"></a><a name="p1372815952715"></a>Fills in a control transfer request.</p>
</td>
</tr>
<tr id="row117561932712"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p172899112714"><a name="p172899112714"></a><a name="p172899112714"></a>int UsbRawFillInterruptRequest(const struct UsbRawRequest *request, const UsbRawHandle *devHandle, const struct UsbRawFillRequestData *fillData);</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p19728092271"><a name="p19728092271"></a><a name="p19728092271"></a>Fills in an interrupt transfer request.</p>
</td>
</tr>
<tr id="row075617917271"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p072829132714"><a name="p072829132714"></a><a name="p072829132714"></a>int UsbRawFillIsoRequest(const struct UsbRawRequest *request, const UsbRawHandle *devHandle, const struct UsbRawFillRequestData *fillData);</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p107281913275"><a name="p107281913275"></a><a name="p107281913275"></a>Fills in an isochronous transfer request.</p>
</td>
</tr>
<tr id="row87564917271"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p16728129152712"><a name="p16728129152712"></a><a name="p16728129152712"></a>int UsbRawSubmitRequest(const struct UsbRawRequest *request);</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p187299922718"><a name="p187299922718"></a><a name="p187299922718"></a>Submits a transfer request.</p>
</td>
</tr>
<tr id="row975659192711"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p15729099278"><a name="p15729099278"></a><a name="p15729099278"></a>int UsbRawCancelRequest(const struct UsbRawRequest *request);</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p872912911274"><a name="p872912911274"></a><a name="p872912911274"></a>Cancels a transfer request.</p>
</td>
</tr>
<tr id="row1675519932712"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p1472929182710"><a name="p1472929182710"></a><a name="p1472929182710"></a>int UsbRawHandleRequests(const UsbRawHandle *devHandle);</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p572929102710"><a name="p572929102710"></a><a name="p572929102710"></a>Handles a transfer request event.</p>
</td>
</tr>
</tbody>
</table>

[Figure 2](#fig8847615103013) describes the APIs provided by the USB device driver model.

**Table 2** APIs provided by the USB device driver model

<a name="table1172315391272"></a>
<table><thead align="left"><tr id="row207231239162719"><th class="cellrowborder" valign="top" width="33.33333333333333%" id="mcps1.2.4.1.1"><p id="p1472363915270"><a name="p1472363915270"></a><a name="p1472363915270"></a>Header File</p>
</th>
<th class="cellrowborder" valign="top" width="33.33333333333333%" id="mcps1.2.4.1.2"><p id="p672313910271"><a name="p672313910271"></a><a name="p672313910271"></a>API</p>
</th>
<th class="cellrowborder" valign="top" width="33.33333333333333%" id="mcps1.2.4.1.3"><p id="p524922814284"><a name="p524922814284"></a><a name="p524922814284"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1526165392716"><td class="cellrowborder" rowspan="3" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.1 "><p id="p143125320275"><a name="p143125320275"></a><a name="p143125320275"></a>usbfn_device.h</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.2 "><p id="p1644533274"><a name="p1644533274"></a><a name="p1644533274"></a>const struct UsbFnDevice *UsbFnCreateDevice(const char *udcName, const struct UsbFnDescriptorData *descriptor);</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.3 "><p id="p241853152716"><a name="p241853152716"></a><a name="p241853152716"></a>Creates a USB device.</p>
</td>
</tr>
<tr id="row11261453112717"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p741553102715"><a name="p741553102715"></a><a name="p741553102715"></a>int UsbFnRemoveDevice(struct UsbFnDevice *fnDevice);</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p5435318271"><a name="p5435318271"></a><a name="p5435318271"></a>Deletes a USB device.</p>
</td>
</tr>
<tr id="row126205320278"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p9425362716"><a name="p9425362716"></a><a name="p9425362716"></a>const struct UsbFnDevice *UsbFnGetDevice(const char *udcName);</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p54135392719"><a name="p54135392719"></a><a name="p54135392719"></a>Obtains a USB device.</p>
</td>
</tr>
<tr id="row326125314279"><td class="cellrowborder" rowspan="6" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.1 "><p id="p144653142719"><a name="p144653142719"></a><a name="p144653142719"></a>usbfn_interface.h</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.2 "><p id="p941453112713"><a name="p941453112713"></a><a name="p941453112713"></a>int UsbFnStartRecvInterfaceEvent(struct UsbFnInterface *interface, uint32_t eventMask, UsbFnEventCallback callback, void *context);</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.3 "><p id="p1341530277"><a name="p1341530277"></a><a name="p1341530277"></a>Starts receiving events.</p>
</td>
</tr>
<tr id="row172613534273"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p124153152713"><a name="p124153152713"></a><a name="p124153152713"></a>int UsbFnStopRecvInterfaceEvent(struct UsbFnInterface *interface);</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p1441532271"><a name="p1441532271"></a><a name="p1441532271"></a>Stops receiving events.</p>
</td>
</tr>
<tr id="row1026653142717"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p24185317276"><a name="p24185317276"></a><a name="p24185317276"></a>UsbFnInterfaceHandle UsbFnOpenInterface(struct UsbFnInterface *interface);</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p142537274"><a name="p142537274"></a><a name="p142537274"></a>Opens an interface.</p>
</td>
</tr>
<tr id="row226195362720"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p114175382715"><a name="p114175382715"></a><a name="p114175382715"></a>int UsbFnCloseInterface(UsbFnInterfaceHandle handle);</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p124453132715"><a name="p124453132715"></a><a name="p124453132715"></a>Closes an interface.</p>
</td>
</tr>
<tr id="row12605311277"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p3565313278"><a name="p3565313278"></a><a name="p3565313278"></a>int UsbFnGetInterfacePipeInfo(struct UsbFnInterface *interface, uint8_t pipeId, struct UsbFnPipeInfo *info);</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p054536274"><a name="p054536274"></a><a name="p054536274"></a>Obtains pipe information.</p>
</td>
</tr>
<tr id="row19261153132716"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p1958532275"><a name="p1958532275"></a><a name="p1958532275"></a>int UsbFnSetInterfaceProp(const struct UsbFnInterface *interface, const char *name, const char *value);</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p9516538277"><a name="p9516538277"></a><a name="p9516538277"></a>Sets custom properties.</p>
</td>
</tr>
<tr id="row3261853202716"><td class="cellrowborder" rowspan="8" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.1 "><p id="p65453192711"><a name="p65453192711"></a><a name="p65453192711"></a>usbfn_request.h</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.2 "><p id="p3520539276"><a name="p3520539276"></a><a name="p3520539276"></a>struct UsbFnRequest *UsbFnAllocCtrlRequest(UsbFnInterfaceHandle handle, uint32_t len);</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.3 "><p id="p5514538278"><a name="p5514538278"></a><a name="p5514538278"></a>Applies for a control transfer request.</p>
</td>
</tr>
<tr id="row18261253112716"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p85115312277"><a name="p85115312277"></a><a name="p85115312277"></a>struct UsbFnRequest *UsbFnAllocRequest(UsbFnInterfaceHandle handle, uint8_t pipe, uint32_t len);</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p105105342716"><a name="p105105342716"></a><a name="p105105342716"></a>Applies for a data request.</p>
</td>
</tr>
<tr id="row82665320272"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p1461538279"><a name="p1461538279"></a><a name="p1461538279"></a>int UsbFnFreeRequest(struct UsbFnRequest *req);</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p26165372718"><a name="p26165372718"></a><a name="p26165372718"></a>Releases a request.</p>
</td>
</tr>
<tr id="row162610537275"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p261653192714"><a name="p261653192714"></a><a name="p261653192714"></a>int UsbFnSubmitRequestAsync(struct UsbFnRequest *req);</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p361253112718"><a name="p361253112718"></a><a name="p361253112718"></a>Sends an asynchronous request.</p>
</td>
</tr>
<tr id="row1326253122711"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p4611536275"><a name="p4611536275"></a><a name="p4611536275"></a>int UsbFnSubmitRequestSync(struct UsbFnRequest *req, uint32_t timeout);</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p06853112710"><a name="p06853112710"></a><a name="p06853112710"></a>Sends a synchronous request.</p>
</td>
</tr>
<tr id="row15265539272"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p177453102712"><a name="p177453102712"></a><a name="p177453102712"></a>int UsbFnCancelRequest(struct UsbFnRequest *req);</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p13725312275"><a name="p13725312275"></a><a name="p13725312275"></a>Cancels a request.</p>
</td>
</tr>
</tbody>
</table>

## Development Guidelines<a name="section581mcpsimp"></a>

The USB driver is developed based on the Hardware Driver Foundation (HDF), platform, and Operating System Abstraction Layer (OSAL) APIs. A unified driver model is provided for USB devices, irrespective of the operating system and chip architecture. This document uses a serial port as an example to describe how to develop drivers for the USB host and USB device.

### How to Develop<a name="section583mcpsimp"></a>

### Developing Driver Using Host DDK APIs<a name="section584mcpsimp"></a>

1.  Configure the driver mapping table.
2.  Initialize the USB host DDK.
3.  Obtain a **UsbInterface** object.
4.  Open the **UsbInterface** object to obtain the **UsbInterfaceHandle** object.
5.  Obtain pipe information of the specified **pipeIndex** based on the **UsbInterfaceHandle** object.
6.  Allocate an I/O request for the **UsbInterfaceHandle** object.
7.  Fill in the I/O request based on the input parameters.
8.  Submit the I/O request in synchronous or asynchronous mode.

### Developing Driver Using Host Raw APIs<a name="section594mcpsimp"></a>

1.  Configure the driver mapping table.
2.  Initialize the host raw data, open the USB device, obtain the descriptor, and then obtain interface and endpoint information based on the descriptor.
3.  Allocate a request and fill in the request based on the transfer type.
4.  Submit the I/O request in synchronous or asynchronous mode.

### Developing Driver Using Device DDK APIs<a name="section600mcpsimp"></a>

1.  Construct a descriptor.
2.  Instantiate a USB device using the descriptor constructed.
3.  Call **UsbFnDeviceGetInterface** to obtain an interface, call **UsbFnInterfaceGetPipeInfo** to obtain pipe information based on the interface, call **UsbFnInterfaceOpen** to open the interface to obtain the handle, and call **UsbFnRequestAlloc** to obtain the request based on the handle and pipe ID.
4.  Call **UsbFnInterfaceStartRecvEvent** to receive events such as Enable and Setup, and respond to the events in **UsbFnEventCallback**.
5.  Send and receive data in synchronous or asynchronous mode.

## Development Examples<a name="section607mcpsimp"></a>

The following examples help you better understand the development of the USB serial port driver.

### Developing Driver Using Host DDK APIs<a name="section609mcpsimp"></a>

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
                // Interface number. You can enter multiple interface numbers as needed.
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
    struct UsbControlParams controlParams;
    struct UsbRequestParams params;
    if (acm == NULL || buf == NULL) {
        HDF_LOGE("%s:invalid param", __func__);
        return HDF_ERR_IO;
    }
    if (acm->ctrlReq == NULL) {
        acm->ctrlReq = UsbAllocRequest(acm->ctrDevHandle, 0, len);
        if (acm->ctrlReq == NULL) {
            HDF_LOGE("%s: UsbAllocRequest failed", __func__);
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

    params.interfaceId = USB_CTRL_INTERFACE_ID;
    params.pipeAddress = acm->ctrPipe->pipeAddress;
    params.pipeId = acm->ctrPipe->pipeId;
    params.requestType = USB_REQUEST_PARAMS_CTRL_TYPE;
    params.timeout = USB_CTRL_SET_TIMEOUT;
    params.ctrlReq = UsbControlSetUp(&controlParams);
    ret = UsbFillRequest(acm->ctrlReq, acm->ctrDevHandle, &params);
    if (HDF_SUCCESS != ret) {
        HDF_LOGE("%s: failed, ret=%d ", __func__, ret);
        return ret;
    }
    ret = UsbSubmitRequestSync(acm->ctrlReq);    // Send an I/O request synchronously.
    if (HDF_SUCCESS != ret) {
        HDF_LOGE("UsbSubmitRequestSync failed, ret=%d ", ret);
        return ret;
    }
    if (!acm->ctrlReq->compInfo.status) {
        HDF_LOGE("%s status=%d ", __func__, acm->ctrlReq->compInfo.status);
    }
    return HDF_SUCCESS;
}
...
static struct UsbInterface *GetUsbInterfaceById(const struct AcmDevice *acm,
    uint8_t interfaceIndex)
{
    struct UsbInterface *tmpIf = NULL;
    tmpIf = (struct UsbInterface *)UsbClaimInterface(acm->session, acm->busNum, 
            acm->devAddr, interfaceIndex); // Obtain the UsbInterface object.
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
                HDF_LOGE("%s: Alloc pipe failed", __func__);
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
        HDF_LOGE("%s: invalid params", __func__);
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
        HDF_LOGE("%s:%d OsalMutexInit failed", __func__, __LINE__);
        goto error;
    }
    info = (struct UsbPnpNotifyServiceInfo *)device->priv;
    if (info != NULL) {
        HDF_LOGD("%s:%d busNum=%d,devAddr=%d,interfaceLength=%d", 
            __func__, __LINE__, info->busNum, info->devNum, info->interfaceLength);
        acm->busNum = info->busNum;
        acm->devAddr = info->devNum;
        acm->interfaceCnt = info->interfaceLength;
        err = memcpy_s((void *)(acm->interfaceIndex), USB_MAX_INTERFACES,
              (const void*)info->interfaceNumber, info->interfaceLength);
        if (err != EOK) {
            HDF_LOGE("%s:%d memcpy_s failed err=%d",
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
        HDF_LOGE("%s:%d OsalMutexDestroy failed", __func__, __LINE__);
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
    struct UsbRequestParams readParams;
    for (int i = 0; i < ACM_NR; i++) {
        acm->readReq[i] = UsbAllocRequest(InterfaceIdToHandle(acm, acm->dataInPipe->interfaceId), 0, acm->readSize);    // Allocate the readReq I/O request to be sent.
        if (!acm->readReq[i]) {
            HDF_LOGE("readReq request failed");
            goto error;
        }
        readParams.userData = (void *)acm;
        readParams.pipeAddress = acm->dataInPipe->pipeAddress;
        readParams.pipeId = acm->dataInPipe->pipeId;
        readParams.interfaceId = acm->dataInPipe->interfaceId;
        readParams.callback = AcmReadBulk;
        readParams.requestType = USB_REQUEST_PARAMS_DATA_TYPE;
        readParams.timeout = USB_CTRL_SET_TIMEOUT;
        readParams.dataReq.numIsoPackets = 0;
        readParams.dataReq.directon = (acm->dataInPipe->pipeDirection >> USB_PIPE_DIR_OFFSET) & 0x1;
        readParams.dataReq.length = acm->readSize;
        ret = UsbFillRequest(acm->readReq[i], InterfaceIdToHandle(acm, acm->dataInPipe->interfaceId), &readParams);    // Fills in the readReq object to be sent.
        if (HDF_SUCCESS != ret) {
            HDF_LOGE("%s: UsbFillRequest failed, ret=%d n", __func__, ret);
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
    struct UsbRequestParams intParams = {};
    acm->notifyReq = UsbAllocRequest(InterfaceIdToHandle(acm, acm->intPipe->interfaceId), 0, acm->intSize);    // Allocate the interrupt I/O request object to be sent.
    if (!acm->notifyReq) {
        HDF_LOGE("notifyReq request failed");
        return HDF_ERR_MALLOC_FAIL;
    }
    intParams.userData = (void *)acm;
    intParams.pipeAddress = acm->intPipe->pipeAddress;
    intParams.pipeId = acm->intPipe->pipeId;
    intParams.interfaceId = acm->intPipe->interfaceId;
    intParams.callback = AcmCtrlIrq;
    intParams.requestType = USB_REQUEST_PARAMS_DATA_TYPE;
    intParams.timeout = USB_CTRL_SET_TIMEOUT;
    intParams.dataReq.numIsoPackets = 0;
    intParams.dataReq.directon = (acm->intPipe->pipeDirection >> USB_PIPE_DIR_OFFSET) & DIRECTION_MASK;
    intParams.dataReq.length = acm->intSize;
    ret = UsbFillRequest(acm->notifyReq, InterfaceIdToHandle(acm, acm->intPipe->interfaceId), &intParams);    // Fill in the interrupt I/O request.
    if (HDF_SUCCESS != ret) {
        HDF_LOGE("%s: UsbFillRequest failed, ret=%d n", __func__, ret);
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
        acm->iface[i] = GetUsbInterfaceById((const struct AcmDevice *)acm, acm->interfaceIndex[i]);    // Obtain the UsbInterface object.
        if (acm->iface[i] == NULL) {
            HDF_LOGE("%s: interface%d is null", __func__, acm->interfaceIndex[i]);
            goto error;
        }
    }

    acm->ctrIface = GetUsbInterfaceById((const struct AcmDevice *)acm, USB_CTRL_INTERFACE_ID);     // Obtain the UsbInterface object corresponding to the control interface.
    if (acm->ctrIface == NULL) {
        HDF_LOGE("%s: GetUsbInterfaceById null", __func__);
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
            acm->devHandle[i] = UsbOpenInterface(acm->iface[i]);    // Open the UsbInterface object obtained.
            if (acm->devHandle[i] == NULL) {
                HDF_LOGE("%s: UsbOpenInterface null", __func__);
                goto error;
            }
        }
    }
    acm->ctrDevHandle = UsbOpenInterface(acm->ctrIface);
    if (acm->ctrDevHandle == NULL) {
        HDF_LOGE("%s: ctrDevHandle UsbOpenInterface null", __func__);
        goto error;
    }

    return HDF_SUCCESS;

error:
    AcmCloseInterfaces(acm);
    return HDF_FAILURE;
}

static int32_t AcmGetPipes(struct AcmDevice *acm)
{
    acm->dataInPipe = GetPipe(acm, USB_PIPE_TYPE_BULK, USB_PIPE_DIRECTION_IN);// Obtain pipe information of dataInPipe.
    if (acm->dataInPipe == NULL) {
        HDF_LOGE("dataInPipe is NULL");
        goto error;
    }

    acm->dataOutPipe = GetPipe(acm, USB_PIPE_TYPE_BULK, USB_PIPE_DIRECTION_OUT); // Obtain pipe information of dataOutPipe.
    if (acm->dataOutPipe == NULL) {
        HDF_LOGE("dataOutPipe is NULL");
        goto error;
    }

    acm->ctrPipe = EnumePipe(acm, acm->ctrIface->info.interfaceIndex, USB_PIPE_TYPE_CONTROL, USB_PIPE_DIRECTION_OUT);    // Obtain pipe information of the control pipe.
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
        HDF_LOGE("%s: AcmWriteBufAlloc failed", __func__);
        return HDF_ERR_MALLOC_FAIL;
    }

    for (int i = 0; i < ACM_NW; i++) {
        struct AcmWb *snd = &(acm->wb[i]);
        snd->request = UsbAllocRequest(InterfaceIdToHandle(acm, acm->dataOutPipe->interfaceId), 0, acm->writeSize);    // Allocate the I/O request object to be sent.
        snd->instance = acm;
        if (snd->request == NULL) {
            HDF_LOGE("%s:%d snd request failed", __func__, __LINE__);
            goto error_alloc_write_req;
        }
    }

    ret = AcmAllocNotifyRequest(acm); // Allocate and fill in the interrupt I/O request object.
    if (ret != HDF_SUCCESS) {
        HDF_LOGE("%s:%d AcmAllocNotifyRequest failed", __func__, __LINE__);
        goto error_alloc_int_req;
    }

    ret = AcmAllocReadRequests(acm);    // Allocate and fill in the readReq I/O request object.
    if (ret) {
        HDF_LOGE("%s:%d AcmAllocReadRequests failed", __func__, __LINE__);
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
        HDF_LOGE("%s:%d: initFlag is true", __func__, __LINE__);
        return HDF_SUCCESS;
    }

    ret = UsbInitHostSdk(NULL); // Initialize the Host DDK.
    if (ret != HDF_SUCCESS) {
        HDF_LOGE("%s: UsbInitHostSdk failed", __func__);
        return HDF_ERR_IO;
    }
    acm->session = session;

    ret = AcmClaimInterfaces(acm);
    if (ret != HDF_SUCCESS) {
        HDF_LOGE("%s: AcmClaimInterfaces failed", __func__);
        goto error_claim_interfaces;
    }

    ret = AcmOpenInterfaces(acm);
    if (ret != HDF_SUCCESS) {
        HDF_LOGE("%s: AcmOpenInterfaces failed", __func__);
        goto error_open_interfaces;
    }

    ret = AcmGetPipes(acm);
    if (ret != HDF_SUCCESS) {
        HDF_LOGE("%s: AcmGetPipes failed", __func__);
        goto error_get_pipes;
    }

    ret = AcmAllocRequests(acm);
    if (ret != HDF_SUCCESS) {
        HDF_LOGE("%s: AcmAllocRequests failed", __func__);
        goto error_alloc_reqs;
    }

    acm->lineCoding.dwDTERate = CpuToLe32(DATARATE);
    acm->lineCoding.bCharFormat = CHARFORMAT;
    acm->lineCoding.bParityType = USB_CDC_NO_PARITY;
    acm->lineCoding.bDataBits = USB_CDC_1_STOP_BITS;
    acm->initFlag = true;

    HDF_LOGD("%s:%d========OK", __func__, __LINE__);
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
        HDF_LOGE("%s:%d: initFlag is false", __func__, __LINE__);
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
        HDF_LOGE("%s: device is null", __func__);
        return HDF_ERR_INVALID_OBJECT;
    }
    acm = (struct AcmDevice *)device->service;
    OsalMutexInit(&acm->readLock);
    OsalMutexInit(&acm->writeLock);
    HDF_LOGD("%s:%d busNum=%d,devAddr=%d",
        __func__, __LINE__, acm->busNum, acm->devAddr);

    ret = UsbSerialDeviceAlloc(acm);
    if (ret != HDF_SUCCESS) {
        HDF_LOGE("%s: Serial Device alloc failed", __func__);
    }

    acm->initFlag = false;
    g_acmReleaseFlag = false;

    HDF_LOGD("%s:%d init ok!", __func__, __LINE__);

    return ret;
}

static void UsbSerialDriverRelease(struct HdfDeviceObject *device)
{
    struct AcmDevice *acm = NULL;

    if (device == NULL) {
        HDF_LOGE("%s: device is NULL", __func__);
        return;
    }
    acm = (struct AcmDevice *)device->service;
    if (acm == NULL) {
        HDF_LOGE("%s: acm is null", __func__);
        return;
    }

    g_acmReleaseFlag = true;

    if (acm->initFlag == true) {
        HDF_LOGE("%s:%d AcmRelease", __func__, __LINE__);
        AcmRelease(acm);
    }
    UsbSeriaDevicelFree(acm);
    OsalMutexDestroy(&acm->writeLock);
    OsalMutexDestroy(&acm->readLock);
    OsalMutexDestroy(&acm->lock);
    OsalMemFree(acm);
    acm = NULL;
    HDF_LOGD("%s:%d exit", __func__, __LINE__);
}

struct HdfDriverEntry g_usbSerialDriverEntry = {
    .moduleVersion = 1,
    .moduleName    = "usbhost_acm",    // Driver module name, which must be the same as that configured in the .hcs file.
    .Bind          = UsbSerialDriverBind,
    .Init          = UsbSerialDriverInit,
    .Release       = UsbSerialDriverRelease,
};
HDF_INIT(g_usbSerialDriverEntry);
```

### Developing Driver Using Host Raw APIs<a name="section612mcpsimp"></a>

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
            host_acm_rawapi_table {    // Driver mapping table information.
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
                // Interface number. You can enter multiple interface numbers as needed.
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
        HDF_LOGE("%s:%d devHandle is NULL",
                 __func__, __LINE__);
        return HDF_ERR_INVALID_PARAM;
    }

    ret = UsbRawGetConfiguration(devHandle, &activeConfig);
    if (ret) {
        HDF_LOGE("%s:%d UsbRawGetConfiguration failed, ret=%d",
                 __func__, __LINE__, ret);
        return HDF_FAILURE;
    }
    HDF_LOGE("%s:%d activeConfig=%d", __func__, __LINE__, activeConfig);
    dev = UsbRawGetDevice(devHandle);
    if (dev == NULL) {
        HDF_LOGE("%s:%d UsbRawGetDevice failed",
                 __func__, __LINE__);
        return HDF_FAILURE;
    }

    ret = UsbRawGetConfigDescriptor(dev, activeConfig, config);
    if (ret) {
        HDF_LOGE("UsbRawGetConfigDescriptor failed, ret=%dn", ret);
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
            HDF_LOGE("%s: UsbRawAllocRequest failed", __func__);
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
        HDF_LOGE("%s:%d OsalMutexInit failed", __func__, __LINE__);
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
            HDF_LOGE("%s:%d memcpy_s failed err=%d",
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
        HDF_LOGE("%s:%d OsalMutexDestroy failed", __func__, __LINE__);
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
            HDF_LOGE("readReq request failed");
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
            HDF_LOGE("%s: FillBulkRequest failed, ret=%d n",
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
        HDF_LOGE("notifyReq request failed");
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
        HDF_LOGE("%s: FillInterruptRequest failed, ret=%d", __func__, ret);
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
        HDF_LOGE("%s:%d: initFlag is true", __func__, __LINE__);
        return HDF_SUCCESS;
    }

    ret = UsbRawInit(NULL);
    if (ret) {
        HDF_LOGE("%s:%d UsbRawInit failed", __func__, __LINE__);
        return HDF_ERR_IO;
    }
    acm->session = session;

    devHandle = UsbRawOpenDevice(session, acm->busNum, acm->devAddr);
    if (devHandle == NULL) {
        HDF_LOGE("%s:%d UsbRawOpenDevice failed", __func__, __LINE__);
        ret =  HDF_FAILURE;
        goto err_open_device;
    }
    acm->devHandle = devHandle;
    ret = UsbGetConfigDescriptor(devHandle, &acm->config);
    if (ret) {
        HDF_LOGE("%s:%d UsbGetConfigDescriptor failed", __func__, __LINE__);
        ret =  HDF_FAILURE;
        goto err_get_desc;
    }
    ret = UsbParseConfigDescriptor(acm, acm->config);
    if (ret != HDF_SUCCESS) {
        HDF_LOGE("%s:%d UsbParseConfigDescriptor failed", __func__, __LINE__);
        ret = HDF_FAILURE;
        goto err_parse_desc;
    }

    ret = AcmWriteBufAlloc(acm);
    if (ret < 0) {
        HDF_LOGE("%s:%d AcmWriteBufAlloc failed", __func__, __LINE__);
        ret = HDF_FAILURE;
        goto err_alloc_write_buf;
    }
    ret = UsbAllocWriteRequests(acm);
    if (ret < 0) {
        HDF_LOGE("%s:%d UsbAllocWriteRequests failed", __func__, __LINE__);
        ret = HDF_FAILURE;
        goto err_alloc_write_reqs;
    }
    ret = UsbAllocNotifyRequest(acm);
    if (ret) {
        HDF_LOGE("%s:%d UsbAllocNotifyRequests failed", __func__, __LINE__);
        goto err_alloc_notify_req;
    }
    ret = UsbAllocReadRequests(acm);
    if (ret) {
        HDF_LOGE("%s:%d UsbAllocReadRequests failed", __func__, __LINE__);
        goto err_alloc_read_reqs;
    }
    ret = UsbStartIo(acm);
    if (ret) {
        HDF_LOGE("%s:%d UsbAllocReadRequests failed", __func__, __LINE__);
        goto err_start_io;
    }

    acm->lineCoding.dwDTERate   = CpuToLe32(DATARATE);
    acm->lineCoding.bCharFormat = CHARFORMAT;
    acm->lineCoding.bParityType = USB_CDC_NO_PARITY;
    acm->lineCoding.bDataBits   = USB_CDC_1_STOP_BITS;

    ret = UsbRawSubmitRequest(acm->notifyReq);
    if (ret) {
        HDF_LOGE("%s:%d UsbRawSubmitRequest failed", __func__, __LINE__);
        goto err_submit_req;
    }

    acm->initFlag = true;

    HDF_LOGD("%s:%d=========================OK", __func__, __LINE__);

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
        HDF_LOGE("%s:%d: initFlag is false", __func__, __LINE__);
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
        HDF_LOGE("%s:%d device is null", __func__, __LINE__);
        return HDF_ERR_INVALID_OBJECT;
    }
    acm = (struct AcmDevice *)device->service;
    OsalMutexInit(&acm->readLock);
    OsalMutexInit(&acm->writeLock);

    ret = UsbSerialDeviceAlloc(acm);
    if (ret != HDF_SUCCESS) {
        HDF_LOGE("%s:%d UsbSerialDeviceAlloc failed", __func__, __LINE__);
    }

    acm->initFlag = false;
    g_rawAcmReleaseFlag = false;

    HDF_LOGD("%s:%d init ok!", __func__, __LINE__);

    return ret;
}

static void UsbSerialDriverRelease(struct HdfDeviceObject *device)
{
    struct AcmDevice *acm = NULL;
    if (device == NULL) {
        HDF_LOGE("%s: device is NULL", __func__);
        return;
    }

    acm = (struct AcmDevice *)device->service;
    if (acm == NULL) {
        HDF_LOGE("%s: acm is null", __func__);
        return;
    }

    g_rawAcmReleaseFlag = true;

    if (acm->initFlag == true) {
        HDF_LOGE("%s:%d UsbSerialRelease", __func__, __LINE__);
        UsbSerialRelease(acm);
    }
    UsbSeriaDevicelFree(acm);
    OsalMutexDestroy(&acm->writeLock);
    OsalMutexDestroy(&acm->readLock);
    OsalMutexDestroy(&acm->lock);
    OsalMemFree(acm);
    acm = NULL;
    HDF_LOGD("%s:%d exit", __func__, __LINE__);
}

struct HdfDriverEntry g_usbSerialRawDriverEntry = {
    .moduleVersion = 1,
    ..moduleName    = "usbhost_acm_rawapi",    // Driver module name, which must be the same as that configured in the .hcs file.
    .Bind          = UsbSerialDriverBind,
    .Init          = UsbSerialDriverInit,
    .Release       = UsbSerialDriverRelease,
};
HDF_INIT(g_usbSerialRawDriverEntry);
```

### Developing Driver Using Device DDK APIs<a name="section615mcpsimp"></a>

The core code of the USB Abstract Control Model (ACM) device is available in **drivers\peripheral\usb\gadget\function\acm\cdcacm.c**. The following is an example:

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
        HDF_LOGE("%s: create usb function device failed", __func__);
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
/* Send an asynchronous request.*/
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
        HDF_LOGE("%s: remove usb function device failed", __func__);
    }
    return ret;
}
```
