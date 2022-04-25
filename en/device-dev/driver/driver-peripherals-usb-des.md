# USB


## Overview

USB host development aims to provide host-related functions, including protocol encapsulation, device management, and driver installation and uninstall.

USB device development aims to provide device-related functions, including device management, configuration management, and I/O management. These functions implement creation, configuration, and data communication of USB devices.

  The following figures show the USB host and device driver models.

  **Figure 1** USB host driver model

  ![](figures/USB_host_driver_model.png "USB host driver model")

  
  **Figure 2** USB device driver model

  ![](figures/USB_device_driver_model.png "USB device driver model")

The USB driver model offers the following APIs:

- The USB host Driver Development Kit (DDK) provides driver capability APIs that can be directly called in user mode. The APIs can be classified into the DDK initialization class, interface operation class, and request operation class by function. These APIs can be used to perform DDK initialization, bind/release and open/close an interface, allocate/release a request, and implement synchronous or asynchronous transfer.

- The USB device DDK provides device management, I/O management, and configuration management APIs, which can be used to create or delete a device, obtain or open an interface, and perform synchronous or asynchronous transfer.


### Available APIs

The tables below describe the APIs provided by the USB host driver model.

  **Table 1** usb_ddk_interface.h

| API| Description| 
| -------- | -------- |
| int32_t&nbsp;UsbInitHostSdk(struct&nbsp;UsbSession&nbsp;\*\*session); | Initializes the USB host driver DDK.| 
| int32_t&nbsp;UsbExitHostSdk(const&nbsp;struct&nbsp;UsbSession<br>\*session); | Exits the USB host driver DDK.| 
| const&nbsp;struct&nbsp;UsbInterface&nbsp;\*UsbClaimInterface(const<br>struct&nbsp;UsbSession&nbsp;\*session,&nbsp;uint8_t&nbsp;busNum,&nbsp;uint8_t<br>usbAddr,&nbsp;uint8_t&nbsp;interfaceIndex); | Obtains a USB interface.| 
| int&nbsp;UsbReleaseInterface(const&nbsp;struct&nbsp;UsbInterface<br>\*interfaceObj); | Releases a USB interface.| 
| int&nbsp;UsbAddOrRemoveInterface(const&nbsp;struct&nbsp;UsbSession<br>\*session,&nbsp;uint8_t&nbsp;busNum,&nbsp;uint8_t&nbsp;usbAddr,&nbsp;uint8_t<br>interfaceIndex,&nbsp;UsbInterfaceStatus&nbsp;status); | Adds or removes a USB interface.| 
| UsbInterfaceHandle&nbsp;\*UsbOpenInterface(const&nbsp;struct<br>UsbInterface&nbsp;\*interfaceObj); | Opens a USB interface.| 
| int32_t&nbsp;UsbCloseInterface(const&nbsp;UsbInterfaceHandle<br>\*interfaceHandle); | Closes a USB interface.| 
| int32_t&nbsp;UsbSelectInterfaceSetting(const<br>UsbInterfaceHandle&nbsp;\*interfaceHandle,&nbsp;uint8_t<br>settingIndex,&nbsp;struct&nbsp;UsbInterface&nbsp;\*\*interfaceObj); | Sets a USB interface.| 
| int32_t&nbsp;UsbGetPipeInfo(const&nbsp;UsbInterfaceHandle<br>\*interfaceHandle,&nbsp;uint8_t&nbsp;settingIndex,&nbsp;uint8_t&nbsp;pipeId,<br>struct&nbsp;UsbPipeInfo&nbsp;\*pipeInfo); | Obtains USB pipe information.| 
| int32_t&nbsp;UsbClearInterfaceHalt(const<br>UsbInterfaceHandle&nbsp;\*interfaceHandle,&nbsp;uint8_t<br>pipeAddress); | Clears the state of the pipe with the specified index.| 
| struct&nbsp;UsbRequest&nbsp;\*UsbAllocRequest(const<br>UsbInterfaceHandle&nbsp;\*interfaceHandle,&nbsp;int&nbsp;isoPackets<br>,&nbsp;int&nbsp;length); | Allocates a request object.| 
| int&nbsp;UsbFreeRequest(const&nbsp;struct&nbsp;UsbRequest<br>\*request); | Releases a request object.| 
| int&nbsp;UsbSubmitRequestAsync(const&nbsp;struct&nbsp;UsbRequest<br>\*request); | Sends an asynchronous request.| 
| int32_t&nbsp;UsbFillRequest(const&nbsp;struct&nbsp;UsbRequest<br>\*request,&nbsp;const&nbsp;UsbInterfaceHandle&nbsp;\*interfaceHandle,<br>const&nbsp;struct&nbsp;UsbRequestParams&nbsp;\*params); | Fills in a request.| 
| sint&nbsp;UsbCancelRequest(const&nbsp;struct&nbsp;UsbRequest<br>\*request); | Cancels an asynchronous request.| 
| int&nbsp;UsbSubmitRequestSync(const&nbsp;struct&nbsp;UsbRequest<br>\*request); | Sends a synchronous request.| 

  **Table 2** usb_raw_api.h

| API| Description| 
| -------- | -------- |
| int&nbsp;UsbRawInit(struct&nbsp;UsbSession&nbsp;\*\*session); | Initializes the USB raw APIs.| 
| int&nbsp;UsbRawExit(const&nbsp;struct&nbsp;UsbSession&nbsp;\*session); | Exits the USB raw APIs.| 
| UsbRawHandle&nbsp;\*UsbRawOpenDevice(const&nbsp;struct<br>UsbSession&nbsp;\*session,&nbsp;uint8_t&nbsp;busNum,&nbsp;uint8_t<br>usbAddr); | Opens a USB device.| 
| int&nbsp;UsbRawCloseDevice(const&nbsp;UsbRawHandle<br>\*devHandle); | Closes a USB device.| 
| int&nbsp;UsbRawSendControlRequest(const&nbsp;struct<br>UsbRawRequest&nbsp;\*request,&nbsp;const&nbsp;UsbRawHandle<br>\*devHandle,&nbsp;const&nbsp;struct&nbsp;UsbControlRequestData<br>\*requestData); | Performs a control transfer synchronously.| 
| int&nbsp;UsbRawSendBulkRequest(const&nbsp;struct<br>UsbRawRequest&nbsp;\*request,&nbsp;const&nbsp;UsbRawHandle<br>\*devHandle,&nbsp;const&nbsp;struct&nbsp;UsbRequestData<br>\*requestData); | Performs a bulk transfer synchronously.| 
| int&nbsp;UsbRawSendInterruptRequest(const&nbsp;struct<br>UsbRawRequest&nbsp;\*request,&nbsp;const&nbsp;UsbRawHandle<br>\*devHandle,&nbsp;const&nbsp;struct&nbsp;UsbRequestData<br>\*requestData); | Performs an interrupt transfer synchronously.| 
| int&nbsp;UsbRawGetConfigDescriptor(const&nbsp;UsbRawDevice<br>\*rawDev,&nbsp;uint8_t&nbsp;configIndex,&nbsp;struct<br>UsbRawConfigDescriptor&nbsp;\*\*config); | Obtains the configuration descriptor of a device.| 
| void&nbsp;UsbRawFreeConfigDescriptor(const&nbsp;struct<br>UsbRawConfigDescriptor&nbsp;\*config); | Releases the memory space of a configuration descriptor.| 
| int&nbsp;UsbRawGetConfiguration(const&nbsp;UsbRawHandle<br>\*devHandle,&nbsp;int&nbsp;\*config); | Obtains the configuration in use.| 
| int&nbsp;UsbRawSetConfiguration(const&nbsp;UsbRawHandle<br>\*devHandle,&nbsp;int&nbsp;config); | Sets the configuration in use.| 
| int&nbsp;UsbRawGetDescriptor(const&nbsp;struct&nbsp;UsbRawRequest<br>\*request,&nbsp;const&nbsp;UsbRawHandle&nbsp;\*devHandle,&nbsp;const&nbsp;struct<br>UsbRawDescriptorParam&nbsp;\*param,&nbsp;const&nbsp;unsigned&nbsp;char<br>\*data); | Obtains descriptor information.| 
| UsbRawDevice&nbsp;\*UsbRawGetDevice(const&nbsp;UsbRawHandle<br>\*devHandle); | Obtains the device pointer based on the device handle.| 
| int&nbsp;UsbRawGetDeviceDescriptor(const&nbsp;UsbRawDevice<br>\*rawDev,&nbsp;struct<br>UsbDeviceDescriptor&nbsp;\*desc); | Obtains the device descriptor of the specified USB device.| 
| int&nbsp;UsbRawClaimInterface(const&nbsp;UsbRawHandle<br>\*devHandle,&nbsp;int<br>interfaceNumber); | Declares the interface on the specified device handle.| 
| int&nbsp;UsbRawReleaseInterface(const&nbsp;UsbRawHandle<br>\*devHandle,&nbsp;in<br>t&nbsp;interfaceNumber); | Releases the previously declared interface.| 
| int&nbsp;UsbRawResetDevice(const&nbsp;UsbRawHandle<br>\*devHandle); | Resets a device.| 
| struct&nbsp;UsbRawRequest&nbsp;\*UsbRawAllocRequest(const<br>UsbRawHandle<br>\*devHandle,&nbsp;int&nbsp;isoPackets,&nbsp;int&nbsp;length); | Allocates a transfer request with the specified number of sync packet descriptors.| 
| int&nbsp;UsbRawFreeRequest(const&nbsp;struct&nbsp;UsbRawRequest<br>\*request); | Releases the previously allocated transfer request.| 
| int&nbsp;UsbRawFillBulkRequest(const&nbsp;struct&nbsp;UsbRawRequest<br>\*request,&nbsp;const&nbsp;UsbRawHandle&nbsp;\*devHandle,&nbsp;const&nbsp;struct<br>UsbRawFillRequestData&nbsp;\*fillData); | Fills in a bulk transfer request.| 
| int&nbsp;UsbRawFillControlSetup(const&nbsp;unsigned&nbsp;char&nbsp;\*setup,<br>const&nbsp;struct&nbsp;UsbControlRequestData&nbsp;\*requestData); | Fills in a control setup packet.| 
| int&nbsp;UsbRawFillControlRequest(const&nbsp;struct&nbsp;UsbRawRequest<br>\*request,&nbsp;const&nbsp;UsbRawHandle&nbsp;\*devHandle,&nbsp;const&nbsp;struct<br>UsbRawFillRequestData&nbsp;\*fillData); | Fills in a control transfer request.| 
| int&nbsp;UsbRawFillInterruptRequest(const&nbsp;struct&nbsp;UsbRawRequest<br>\*request,&nbsp;const&nbsp;UsbRawHandle&nbsp;\*devHandle,&nbsp;const&nbsp;struct<br>UsbRawFillRequestData&nbsp;\*fillData); | Fills in an interrupt transfer request.| 
| int&nbsp;UsbRawFillIsoRequest(const&nbsp;struct&nbsp;UsbRawRequest<br>\*request,&nbsp;const&nbsp;UsbRawHandle&nbsp;\*devHandle,&nbsp;const&nbsp;struct<br>UsbRawFillRequestData&nbsp;\*fillData); | Fills in an isochronous transfer request.| 
| int&nbsp;UsbRawSubmitRequest(const&nbsp;struct&nbsp;UsbRawRequest<br>\*request); | Submits a transfer request.| 
| int&nbsp;UsbRawCancelRequest(const&nbsp;struct&nbsp;UsbRawRequest<br>\*request); | Cancels a transfer request.| 
| int&nbsp;UsbRawHandleRequests(const&nbsp;UsbRawHandle<br>\*devHandle); | Handles a transfer request event.| 

The tables below describe the APIs provided by the USB device driver model.

  **Table 3** usbfn_device.h

| API| Description| 
| -------- | -------- |
| const&nbsp;struct&nbsp;UsbFnDevice&nbsp;\*UsbFnCreateDevice(const<br>char&nbsp;\*udcName,&nbsp;const&nbsp;struct&nbsp;UsbFnDescriptorData<br>\*descriptor); | Creates a USB device.| 
| int&nbsp;UsbFnRemoveDevice(struct&nbsp;UsbFnDevice<br>\*fnDevice); | Deletes a USB device.| 
| const&nbsp;struct&nbsp;UsbFnDevice&nbsp;\*UsbFnGetDevice(const&nbsp;char<br>\*udcName); | Obtains a USB device.| 

  **Table 4** usbfn_interface.h

| API| Description| 
| -------- | -------- |
| int&nbsp;UsbFnStartRecvInterfaceEvent(struct<br>UsbFnInterface&nbsp;\*interface,&nbsp;uint32_t&nbsp;eventMask,<br>UsbFnEventCallback&nbsp;callback,&nbsp;void&nbsp;\*context); | Starts receiving events.| 
| int&nbsp;UsbFnStopRecvInterfaceEvent(struct<br>UsbFnInterface&nbsp;\*interface); | Stops receiving events.| 
| UsbFnInterfaceHandle&nbsp;UsbFnOpenInterface(struct&nbsp;UsbFnInterface&nbsp;\*interface); | Opens an interface.| 
| int&nbsp;UsbFnCloseInterface(UsbFnInterfaceHandle&nbsp;handle); | Closes an interface.| 
| int&nbsp;UsbFnGetInterfacePipeInfo(struct&nbsp;UsbFnInterface<br>\*interface,&nbsp;uint8_t&nbsp;pipeId,&nbsp;struct&nbsp;UsbFnPipeInfo&nbsp;\*info); | Obtains pipe information.| 
| int&nbsp;UsbFnSetInterfaceProp(const&nbsp;struct&nbsp;UsbFnInterface<br>\*interface,&nbsp;const&nbsp;char&nbsp;\*name,&nbsp;const&nbsp;char&nbsp;\*value); | Sets custom properties.| 

  **Table 5** usbfn_request.h

| API| Description| 
| -------- | -------- |
| struct&nbsp;UsbFnRequest<br>\*UsbFnAllocCtrlRequest(UsbFnInterfaceHandle&nbsp;handle,<br>uint32_t&nbsp;len); | Allocates a control transfer request.| 
| struct&nbsp;UsbFnRequest&nbsp;\*UsbFnAllocRequest(UsbFnInterfaceHandle&nbsp;handle,<br>uint8_t&nbsp;pipe,&nbsp;uint32_t&nbsp;len); | Allocates a data request.| 
| int&nbsp;UsbFnFreeRequest(struct&nbsp;UsbFnRequest&nbsp;\*req); | Releases a request.| 
| int&nbsp;UsbFnSubmitRequestAsync(struct&nbsp;UsbFnRequest<br>\*req); | Sends an asynchronous request.| 
| int&nbsp;UsbFnSubmitRequestSync(struct&nbsp;UsbFnRequest<br>\*req,&nbsp;uint32_t&nbsp;timeout); | Sends a synchronous request.| 
| int&nbsp;UsbFnCancelRequest(struct&nbsp;UsbFnRequest&nbsp;\*req); | Cancels a request.| 


## How to Develop

The USB driver is developed based on the Hardware Driver Foundation (HDF), platform, and Operating System Abstraction Layer (OSAL) APIs. A unified driver model is provided for USB devices, irrespective of the operating system and chip architecture. This document uses a serial port as an example to describe how to develop drivers for the USB host and USB device.


### Developing Driver Using Host DDK APIs

1. Configure the driver mapping table.

2. Initialize the USB host DDK.

3. Obtain a **UsbInterface** object.

4. Open the **UsbInterface** object to obtain the **UsbInterfaceHandle** object.

5. Obtain pipe information of the specified **pipeIndex** based on the **UsbInterfaceHandle** object.

6. Allocate an I/O request for the **UsbInterfaceHandle** object.

7. Fill in the I/O request based on the input parameters.

8. Submit the I/O request in synchronous or asynchronous mode.


### Developing Driver Using Host Raw APIs

1. Configure the driver mapping table.

2. Initialize the host raw data, open the USB device, obtain the descriptor, and then obtain interface and endpoint information based on the descriptor.

3. Allocate a request and fill in the request based on the transfer type.

4. Submit the I/O request in synchronous or asynchronous mode.


### Developing Driver Using Device DDK APIs

1. Construct a descriptor.

2. Instantiate a USB device using the descriptor constructed.

3. Call **UsbFnDeviceGetInterface** to obtain an interface, call **UsbFnInterfaceGetPipeInfo** to obtain pipe information based on the interface, call **UsbFnInterfaceOpen** to open the interface to obtain the handle, and call **UsbFnRequestAlloc** to obtain the request based on the handle and pipe ID.

4. Call **UsbFnInterfaceStartRecvEvent** to receive events such as Enable and Setup, and respond to the events in **UsbFnEventCallback**.

5. Send and receive data in synchronous or asynchronous mode.


## Development Example

The following examples help you better understand the development of the USB serial port driver.


### Developing Driver Using Host DDK APIs

  
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
    controlParams.direction = USB_REQUEST_DIR_TO_DEVICE;
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
        readParams.dataReq.direction = (acm->dataInPipe->pipeDirection >> USB_PIPE_DIR_OFFSET) & 0x1;
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
    intParams.dataReq.direction = (acm->intPipe->pipeDirection >> USB_PIPE_DIR_OFFSET) & DIRECTION_MASK;
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


### Developing Driver Using Host Raw APIs

  
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


### Developing Driver Using Device DDK APIs

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
