# USB


## 概述

USB Host部分，主要包括协议封装、设备管理、驱动安装与卸载等。

USB Device部分，支持USB功能设备的开发，提供USB设备相关功能，主要包括设备管理、配置管理、IO管理，实现USB功能设备创建、配置、数据通信等。

  USB Host和Device驱动模型如下图所示：

  **图1** USB Host驱动模型图

  ![image](figures/USB-Host驱动模型图.png "USB-Host驱动模型图")

  
  **图2** USB Device驱动模型图

  ![image](figures/USB-Device驱动模型图.png "USB-Device驱动模型图")

USB驱动模型对外开放的API接口能力如下：

- Usb Host DDK提供给用户态可直接调用的驱动能力接口，按照功能分类三大类：DDK初始化类、对interface对象操作类、对request对象操作类，可以提供DDK初始化、interface绑定和释放，打开和关闭操作，request的申请和释放，同步和异步传输等。

- Usb Device DDK提供设备管理、IO管理、配置管理，主要功能有：创建和删除设备、获取和打开接口、同步和异步传输等。


### 接口说明

USB驱动模型Host侧开放的API接口功能，参考USB Host驱动模型图。

  **表1** usb_ddk_interface.h

| 接口名称 | 功能描述 | 
| -------- | -------- |
| int32_t&nbsp;UsbInitHostSdk(struct&nbsp;UsbSession&nbsp;\*\*session); | USB主机端驱动开发工具包初始化 | 
| int32_t&nbsp;UsbExitHostSdk(const&nbsp;struct&nbsp;UsbSession<br/>\*session); | USB主机端驱动开发工具包退出 | 
| const&nbsp;struct&nbsp;UsbInterface&nbsp;\*UsbClaimInterface(const<br/>struct&nbsp;UsbSession&nbsp;\*session,&nbsp;uint8_t&nbsp;busNum,&nbsp;uint8_t<br/>usbAddr,&nbsp;uint8_t&nbsp;interfaceIndex); | 获取USB接口对象 | 
| int&nbsp;UsbReleaseInterface(const&nbsp;struct&nbsp;UsbInterface<br/>\*interfaceObj); | 释放USB接口对象 | 
| int&nbsp;UsbAddOrRemoveInterface(const&nbsp;struct&nbsp;UsbSession<br/>\*session,&nbsp;uint8_t&nbsp;busNum,&nbsp;uint8_t&nbsp;usbAddr,&nbsp;uint8_t<br/>interfaceIndex,&nbsp;UsbInterfaceStatus&nbsp;status); | 增加移除接口 | 
| UsbInterfaceHandle&nbsp;\*UsbOpenInterface(const&nbsp;struct<br/>UsbInterface&nbsp;\*interfaceObj); | 打开USB对象接口 | 
| int32_t&nbsp;UsbCloseInterface(const&nbsp;UsbInterfaceHandle<br/>\*interfaceHandle); | 关闭USB接口对象 | 
| int32_t&nbsp;UsbSelectInterfaceSetting(const<br/>UsbInterfaceHandle&nbsp;\*interfaceHandle,&nbsp;uint8_t<br/>settingIndex,&nbsp;struct&nbsp;UsbInterface&nbsp;\*\*interfaceObj); | 设置可选配置 | 
| int32_t&nbsp;UsbGetPipeInfo(const&nbsp;UsbInterfaceHandle<br/>\*interfaceHandle,&nbsp;uint8_t&nbsp;settingIndex,&nbsp;uint8_t&nbsp;pipeId,<br/>struct&nbsp;UsbPipeInfo&nbsp;\*pipeInfo); | 获取指定可选设置的管道信息 | 
| int32_t&nbsp;UsbClearInterfaceHalt(const<br/>UsbInterfaceHandle&nbsp;\*interfaceHandle,&nbsp;uint8_t<br/>pipeAddress); | 清除指定索引的管道状态 | 
| struct&nbsp;UsbRequest&nbsp;\*UsbAllocRequest(const<br/>UsbInterfaceHandle&nbsp;\*interfaceHandle,&nbsp;int&nbsp;isoPackets<br/>,&nbsp;int&nbsp;length); | 分配请求对象 | 
| int&nbsp;UsbFreeRequest(const&nbsp;struct&nbsp;UsbRequest<br/>\*request); | 释放请求对象 | 
| int&nbsp;UsbSubmitRequestAsync(const&nbsp;struct&nbsp;UsbRequest<br/>\*request); | 发送异步请求 | 
| int32_t&nbsp;UsbFillRequest(const&nbsp;struct&nbsp;UsbRequest<br/>\*request,&nbsp;const&nbsp;UsbInterfaceHandle&nbsp;\*interfaceHandle,<br/>const&nbsp;struct&nbsp;UsbRequestParams&nbsp;\*params); | 填充请求 | 
| sint&nbsp;UsbCancelRequest(const&nbsp;struct&nbsp;UsbRequest<br/>\*request); | 取消异步请求 | 
| int&nbsp;UsbSubmitRequestSync(const&nbsp;struct&nbsp;UsbRequest<br/>\*request); | 发送同步请求 | 

  **表2** usb_raw_api.h

| 接口名称 | 功能描述 | 
| -------- | -------- |
| int&nbsp;UsbRawInit(struct&nbsp;UsbSession&nbsp;\*\*session); | USB驱动开发工具包专家模式初始化 | 
| int&nbsp;UsbRawExit(const&nbsp;struct&nbsp;UsbSession&nbsp;\*session); | USB驱动开发工具包专家模式退出 | 
| UsbRawHandle&nbsp;\*UsbRawOpenDevice(const&nbsp;struct<br/>UsbSession&nbsp;\*session,&nbsp;uint8_t&nbsp;busNum,&nbsp;uint8_t<br/>usbAddr); | 打开USB设备对象 | 
| int&nbsp;UsbRawCloseDevice(const&nbsp;UsbRawHandle<br/>\*devHandle); | 关闭USB设备对象 | 
| int&nbsp;UsbRawSendControlRequest(const&nbsp;struct<br/>UsbRawRequest&nbsp;\*request,&nbsp;const&nbsp;UsbRawHandle<br/>\*devHandle,&nbsp;const&nbsp;struct&nbsp;UsbControlRequestData<br/>\*requestData); | 执行同步控制传输 | 
| int&nbsp;UsbRawSendBulkRequest(const&nbsp;struct<br/>UsbRawRequest&nbsp;\*request,&nbsp;const&nbsp;UsbRawHandle<br/>\*devHandle,&nbsp;const&nbsp;struct&nbsp;UsbRequestData<br/>\*requestData); | 执行同步批量传输 | 
| int&nbsp;UsbRawSendInterruptRequest(const&nbsp;struct<br/>UsbRawRequest&nbsp;\*request,&nbsp;const&nbsp;UsbRawHandle<br/>\*devHandle,&nbsp;const&nbsp;struct&nbsp;UsbRequestData<br/>\*requestData); | 执行同步中断传输 | 
| int&nbsp;UsbRawGetConfigDescriptor(const&nbsp;UsbRawDevice<br/>\*rawDev,&nbsp;uint8_t&nbsp;configIndex,&nbsp;struct<br/>UsbRawConfigDescriptor&nbsp;\*\*config); | 获取给定设备指定ID的设备配置描述符 | 
| void&nbsp;UsbRawFreeConfigDescriptor(const&nbsp;struct<br/>UsbRawConfigDescriptor&nbsp;\*config); | 释放配置描述符内存空间 | 
| int&nbsp;UsbRawGetConfiguration(const&nbsp;UsbRawHandle<br/>\*devHandle,&nbsp;int&nbsp;\*config); | 获取当前激活配置 | 
| int&nbsp;UsbRawSetConfiguration(const&nbsp;UsbRawHandle<br/>\*devHandle,&nbsp;int&nbsp;config); | 设置当前激活配置 | 
| int&nbsp;UsbRawGetDescriptor(const&nbsp;struct&nbsp;UsbRawRequest<br/>\*request,&nbsp;const&nbsp;UsbRawHandle&nbsp;\*devHandle,&nbsp;const&nbsp;struct<br/>UsbRawDescriptorParam&nbsp;\*param,&nbsp;const&nbsp;unsigned&nbsp;char<br/>\*data); | 获取描述符信息 | 
| UsbRawDevice&nbsp;\*UsbRawGetDevice(const&nbsp;UsbRawHandle<br/>\*devHandle); | 由设备句柄获取设备指针 | 
| int&nbsp;UsbRawGetDeviceDescriptor(const&nbsp;UsbRawDevice<br/>\*rawDev,&nbsp;struct<br/>UsbDeviceDescriptor&nbsp;\*desc); | 获取给定设备的USB设备描述符 | 
| int&nbsp;UsbRawClaimInterface(const&nbsp;UsbRawHandle<br/>\*devHandle,&nbsp;int<br/>interfaceNumber); | 声明给定设备句柄上的接口 | 
| int&nbsp;UsbRawReleaseInterface(const&nbsp;UsbRawHandle<br/>\*devHandle,&nbsp;in<br/>t&nbsp;interfaceNumber); | 释放之前声明的接口 | 
| int&nbsp;UsbRawResetDevice(const&nbsp;UsbRawHandle<br/>\*devHandle); | 复位设备 | 
| struct&nbsp;UsbRawRequest&nbsp;\*UsbRawAllocRequest(const<br/>UsbRawHandle<br/>\*devHandle,&nbsp;int&nbsp;isoPackets,&nbsp;int&nbsp;length); | 分配一个带有指定数量的同步包描述符的传输请求 | 
| int&nbsp;UsbRawFreeRequest(const&nbsp;struct&nbsp;UsbRawRequest<br/>\*request); | 释放之前分配的传输请求 | 
| int&nbsp;UsbRawFillBulkRequest(const&nbsp;struct&nbsp;UsbRawRequest<br/>\*request,&nbsp;const&nbsp;UsbRawHandle&nbsp;\*devHandle,&nbsp;const&nbsp;struct<br/>UsbRawFillRequestData&nbsp;\*fillData); | 填充批量传输请求所需信息 | 
| int&nbsp;UsbRawFillControlSetup(const&nbsp;unsigned&nbsp;char&nbsp;\*setup,<br/>const&nbsp;struct&nbsp;UsbControlRequestData&nbsp;\*requestData); | 填充控制传输设置包所需信息 | 
| int&nbsp;UsbRawFillControlRequest(const&nbsp;struct&nbsp;UsbRawRequest<br/>\*request,&nbsp;const&nbsp;UsbRawHandle&nbsp;\*devHandle,&nbsp;const&nbsp;struct<br/>UsbRawFillRequestData&nbsp;\*fillData); | 填充控制传输请求所需信息 | 
| int&nbsp;UsbRawFillInterruptRequest(const&nbsp;struct&nbsp;UsbRawRequest<br/>\*request,&nbsp;const&nbsp;UsbRawHandle&nbsp;\*devHandle,&nbsp;const&nbsp;struct<br/>UsbRawFillRequestData&nbsp;\*fillData); | 填充中断传输请求所需信息 | 
| int&nbsp;UsbRawFillIsoRequest(const&nbsp;struct&nbsp;UsbRawRequest<br/>\*request,&nbsp;const&nbsp;UsbRawHandle&nbsp;\*devHandle,&nbsp;const&nbsp;struct<br/>UsbRawFillRequestData&nbsp;\*fillData); | 填充同步传输（Isochronous&nbsp;Transfers）请求所需信息 | 
| int&nbsp;UsbRawSubmitRequest(const&nbsp;struct&nbsp;UsbRawRequest<br/>\*request); | 提交一个传输请求 | 
| int&nbsp;UsbRawCancelRequest(const&nbsp;struct&nbsp;UsbRawRequest<br/>\*request); | 取消一个传输请求 | 
| int&nbsp;UsbRawHandleRequests(const&nbsp;UsbRawHandle<br/>\*devHandle); | 传输请求事件完成处理 | 

USB驱动模型Device侧开放的API接口功能，参考USB Device驱动模型图。

  **表3** usbfn_device.h

| 接口名称 | 功能描述 | 
| -------- | -------- |
| const&nbsp;struct&nbsp;UsbFnDevice&nbsp;\*UsbFnCreateDevice(const<br/>char&nbsp;\*udcName,&nbsp;const&nbsp;struct&nbsp;UsbFnDescriptorData<br/>\*descriptor); | 创建Usb设备 | 
| int&nbsp;UsbFnRemoveDevice(struct&nbsp;UsbFnDevice<br/>\*fnDevice); | 删除Usb设备 | 
| const&nbsp;struct&nbsp;UsbFnDevice&nbsp;\*UsbFnGetDevice(const&nbsp;char<br/>\*udcName); | 获取Usb设备 | 

  **表4** usbfn_interface.h

| 接口名称 | 功能描述 | 
| -------- | -------- |
| int&nbsp;UsbFnStartRecvInterfaceEvent(struct<br/>UsbFnInterface&nbsp;\*interface,&nbsp;uint32_t&nbsp;eventMask,<br/>UsbFnEventCallback&nbsp;callback,&nbsp;void&nbsp;\*context); | 开始接受Event事件 | 
| int&nbsp;UsbFnStopRecvInterfaceEvent(struct<br/>UsbFnInterface&nbsp;\*interface); | 停止接受Event事件 | 
| UsbFnInterfaceHandle&nbsp;UsbFnOpenInterface(struct&nbsp;UsbFnInterface&nbsp;\*interface); | 打开一个接口 | 
| int&nbsp;UsbFnCloseInterface(UsbFnInterfaceHandle&nbsp;handle); | 关闭一个接口 | 
| int&nbsp;UsbFnGetInterfacePipeInfo(struct&nbsp;UsbFnInterface<br/>\*interface,&nbsp;uint8_t&nbsp;pipeId,&nbsp;struct&nbsp;UsbFnPipeInfo&nbsp;\*info); | 获取管道信息 | 
| int&nbsp;UsbFnSetInterfaceProp(const&nbsp;struct&nbsp;UsbFnInterface<br/>\*interface,&nbsp;const&nbsp;char&nbsp;\*name,&nbsp;const&nbsp;char&nbsp;\*value); | 设置自定义属性 | 

  **表5** usbfn_request.h

| 接口名称 | 功能描述 | 
| -------- | -------- |
| struct&nbsp;UsbFnRequest<br/>\*UsbFnAllocCtrlRequest(UsbFnInterfaceHandle&nbsp;handle,<br/>uint32_t&nbsp;len); | 申请一个控制请求 | 
| struct&nbsp;UsbFnRequest&nbsp;\*UsbFnAllocRequest(UsbFnInterfaceHandle&nbsp;handle,<br/>uint8_t&nbsp;pipe,&nbsp;uint32_t&nbsp;len); | 申请一个数据请求 | 
| int&nbsp;UsbFnFreeRequest(struct&nbsp;UsbFnRequest&nbsp;\*req); | 释放一个请求 | 
| int&nbsp;UsbFnSubmitRequestAsync(struct&nbsp;UsbFnRequest<br/>\*req); | 发送异步请求 | 
| int&nbsp;UsbFnSubmitRequestSync(struct&nbsp;UsbFnRequest<br/>\*req,&nbsp;uint32_t&nbsp;timeout); | 发送同步请求 | 
| int&nbsp;UsbFnCancelRequest(struct&nbsp;UsbFnRequest&nbsp;\*req); | 取消请求 | 


## 开发步骤

USB驱动是基于HDF框架、PLATFORM和OSAL基础接口进行开发，不区分操作系统和芯片平台，为不同USB器件提供统一的驱动模型。本篇开发指导以串口为例，分别介绍USB Host和USB Device驱动开发。


### Host DDK API驱动开发步骤

1. 驱动匹配表配置。

2. 初始化Host DDK。

3. 待步骤2初始化完后获取UsbInterface接口对象。

4. 打开步骤3获取到的UsbInterface接口对象，获取相应接口的UsbInterfaceHandle对象。

5. 根据步骤4获取到的UsbInterfaceHandle对象，获取指定索引为pipeIndex的pipeInfo信息。

6. 为步骤4获取到的UsbInterfaceHandle预先分配待发送的IO Request对象。

7. 根据输入参数params填充步骤6预先分配的IO Request。

8. 提交IO Request对象，可以选择同步或异步两种模式。


### Host RAW API驱动开发步骤

1. 驱动匹配表配置。

2. 初始化Host RAW，并打开USB设备，然后获取描述符，通过描述符获取接口、端点信息。

3. 分配Request，并根据传输类型使用相应接口对Request进行填充。

4. 提交IO Request对象，可以选择同步或异步两种模式。


### Device DDK API驱动开发步骤

1. 构造描述符。

2. 创建设备，使用步骤1构造的描述符实例化一个USB设备。

3. 根据创建的设备获取接口（UsbFnDeviceGetInterface），获取Pipe信息（UsbFnInterfaceGetPipeInfo），打开接口获取Handle（UsbFnInterfaceOpen），根据Handle和Pipe号获取Request（UsbFnRequestAlloc）。

4. 接收Event事件（UsbFnInterfaceStartRecvEvent）如Enable、Setup等事件，回调函数（UsbFnEventCallback）中对Event事件做出响应。

5. 收发数据，可以选择同步异步发送模式。


## 开发实例

本实例提供USB串口驱动开发示例，并简要对具体关键点进行开发说明。


### Host DDK API驱动开发

  
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
                //驱动模块名，该字段的值必须和驱动入口结构的moduleName一致
                moduleName = "usbhost_acm";
                //驱动对外发布服务的名称，必须唯一
                serviceName = "usbhost_acm_pnp_service";
                //驱动私有数据匹配关键字
                deviceMatchAttr = "usbhost_acm_pnp_matchAttr";
                //从该字段开始（包含该字段）之后数据长度，以byte为单位
                length = 21;
                //USB驱动匹配规则vendorId+productId+interfaceSubClass+interfaceProtocol+interfaceNumber
                matchFlag = 0x0303;
                //厂商编号
                vendorId = 0x12D1;
                //产品编号
                productId = 0x5000;
                //设备出厂编号，低16位
                bcdDeviceLow = 0x0000;
                //设备出厂编号，高16位
                 bcdDeviceHigh = 0x0000;
                //USB分配的设备类代码
                deviceClass = 0;
                //USB分配的子类代码
                deviceSubClass = 0;
                //USB分配的设备协议代码
                deviceProtocol = 0;
                //接口类型，根据实际需要可填写多个
                interfaceClass = [0];
                //接口子类型，根据实际需要可填写多个
                interfaceSubClass = [2, 0];
                //接口所遵循的协议，根据实际需要可填写多个    
                interfaceProtocol = [1, 2];
                //接口的编号，根据实际需要可填写多个
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
    ret = UsbSubmitRequestSync(acm->ctrlReq);    //发送同步IO Request
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
            acm->devAddr, interfaceIndex);    //获取UsbInterface接口对象
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
        ret = UsbGetPipeInfo(interfaceHandle, info->curAltSetting, i, &p);//获取指定索引为i的pipeInfo信息
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
        acm->readReq[i] = UsbAllocRequest(InterfaceIdToHandle(acm, acm->dataInPipe->interfaceId), 0, acm->readSize);    //分配待发送的readReq IO Request对象
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
        ret = UsbFillRequest(acm->readReq[i], InterfaceIdToHandle(acm, acm->dataInPipe->interfaceId), &readParams);    //填充待发送的readReq对象
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
    acm->notifyReq = UsbAllocRequest(InterfaceIdToHandle(acm, acm->intPipe->interfaceId), 0, acm->intSize);    //分配待发送的中断IO Request对象
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
    ret = UsbFillRequest(acm->notifyReq, InterfaceIdToHandle(acm, acm->intPipe->interfaceId), &intParams);    //填充预先分配的中断IO Request
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
        acm->iface[i] = GetUsbInterfaceById((const struct AcmDevice *)acm, acm->interfaceIndex[i]);    //获取UsbInterface接口对象
        if (acm->iface[i] == NULL) {
            HDF_LOGE("%s: interface%d is null", __func__, acm->interfaceIndex[i]);
            goto error;
        }
    }

    acm->ctrIface = GetUsbInterfaceById((const struct AcmDevice *)acm, USB_CTRL_INTERFACE_ID);    //获取控制接口对应的UsbInterface接口对象
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
            acm->devHandle[i] = UsbOpenInterface(acm->iface[i]);    //打开获取到的UsbInterface接口对象
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
    acm->dataInPipe = GetPipe(acm, USB_PIPE_TYPE_BULK, USB_PIPE_DIRECTION_IN);//获取dataInPipe的pipeInfo信息
    if (acm->dataInPipe == NULL) {
        HDF_LOGE("dataInPipe is NULL");
        goto error;
    }

    acm->dataOutPipe = GetPipe(acm, USB_PIPE_TYPE_BULK, USB_PIPE_DIRECTION_OUT);//获取dataOutPipe的pipeInfo信息
    if (acm->dataOutPipe == NULL) {
        HDF_LOGE("dataOutPipe is NULL");
        goto error;
    }

    acm->ctrPipe = EnumePipe(acm, acm->ctrIface->info.interfaceIndex, USB_PIPE_TYPE_CONTROL, USB_PIPE_DIRECTION_OUT);    //获取控制pipe的pipeInfo信息
    if (acm->ctrPipe == NULL) {
        HDF_LOGE("ctrPipe is NULL");
        goto error;
    }

    acm->intPipe = GetPipe(acm, USB_PIPE_TYPE_INTERRUPT, USB_PIPE_DIRECTION_IN);//获取中断pipe的pipeInfo信息
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
        snd->request = UsbAllocRequest(InterfaceIdToHandle(acm, acm->dataOutPipe->interfaceId), 0, acm->writeSize);    //分配待发送的IO Request对象
        snd->instance = acm;
        if (snd->request == NULL) {
            HDF_LOGE("%s:%d snd request failed", __func__, __LINE__);
            goto error_alloc_write_req;
        }
    }

    ret = AcmAllocNotifyRequest(acm);    //分配并填充中断IO Request对象
    if (ret != HDF_SUCCESS) {
        HDF_LOGE("%s:%d AcmAllocNotifyRequest failed", __func__, __LINE__);
        goto error_alloc_int_req;
    }

    ret = AcmAllocReadRequests(acm);    //分配并填充readReq IO Request对象
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

    ret = UsbInitHostSdk(NULL);    //初始化Host DDK
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
    .moduleName    = "usbhost_acm",    //驱动模块名称，必须与hcs文件中配置的名称一致
    .Bind          = UsbSerialDriverBind,
    .Init          = UsbSerialDriverInit,
    .Release       = UsbSerialDriverRelease,
};
HDF_INIT(g_usbSerialDriverEntry);
```


### Host RAW API驱动开发

  
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
            host_acm_rawapi_table {    //驱动配置匹配表信息
                //驱动模块名，该字段的值必须和驱动入口结构的moduleName一致
                moduleName = "usbhost_acm_rawapi";
                //驱动对外发布服务的名称，必须唯一
                serviceName = "usbhost_acm_rawapi_service";
                //驱动私有数据匹配关键字
                deviceMatchAttr = "usbhost_acm_rawapi_matchAttr";
                //从该字段开始（包含该字段）之后数据长度，以byte为单位
                length = 21;
                //USB驱动匹配规则vendorId+productId+interfaceSubClass+interfaceProtocol+interfaceNumber
                matchFlag = 0x0303;
                //厂商编号
                vendorId = 0x12D1;
                //产品编号
                productId = 0x5000;
                //设备出厂编号，低16位
                bcdDeviceLow = 0x0000;
                //设备出厂编号，高16位
                bcdDeviceHigh = 0x0000;
                //USB分配的设备类代码
                deviceClass = 0;
                //USB分配的子类代码
                deviceSubClass = 0;
                //USB分配的设备协议代码
                deviceProtocol = 0;
                //接口类型，根据实际需要可填写多个
                interfaceClass = [0];
                //接口子类型，根据实际需要可填写多个
                interfaceSubClass = [2, 0];
                //接口所遵循的协议，根据实际需要可填写多个
                interfaceProtocol = [1, 2];
                //接口的编号，根据实际需要可填写多个
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
    .moduleName    = "usbhost_acm_rawapi",    //驱动模块名称，必须与hcs文件中配置的名称一致
    .Bind          = UsbSerialDriverBind,
    .Init          = UsbSerialDriverInit,
    .Release       = UsbSerialDriverRelease,
};
HDF_INIT(g_usbSerialRawDriverEntry);
```


### Device DDK API驱动开发

USB ACM设备核心代码路径为drivers\peripheral\usb\gadget\function\acm\cdcacm.c，其使用示例如下所示，首先根据描述符创建设备，然后获取接口，打开接口，获取Pipe信息，接收Event事件，接着进行USB通信（读写等），设备卸载时候，关闭接口，停止Event接收，删除设备。

  
```
1、创建设备
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
/* 创建设备 */ 
    fnDev = (struct UsbFnDevice *)UsbFnDeviceCreate(acm->udcName, &descData);
    if (fnDev == NULL) {
        HDF_LOGE("%s: create usb function device failed", __func__);
        return HDF_FAILURE;
    }
    ...
}
2、获取接口，打开接口，获取Pipe信息
static int32_t AcmParseEachPipe(struct UsbAcmDevice *acm, struct UsbAcmInterface *iface)
{
    ...
    for (i = 0; i < fnIface->info.numPipes; i++) {
        struct UsbFnPipeInfo pipeInfo;
/* 获取pipe信息 */
        ret = UsbFnInterfaceGetPipeInfo(fnIface, i, &pipeInfo);
        ...
    }
    return HDF_SUCCESS;
}
/* 获取接口，打开接口获取handle */ 
static int32_t AcmParseEachIface(struct UsbAcmDevice *acm, struct UsbFnDevice *fnDev)
{
    ...
    for (i = 0; i < fnDev->numInterfaces; i++) {
        /* 获取接口 */
        fnIface = (struct UsbFnInterface *)UsbFnDeviceGetInterface(fnDev, i);
        ...
        /* 打开接口 */
        handle = UsbFnInterfaceOpen(fnIface);
        ...
    }
    return HDF_SUCCESS;
}
3、接收Event事件
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
/* 开始接收Event */ 
    ret = UsbFnInterfaceStartRecvEvent(acm->ctrlIface.fn, 0xff, UsbAcmEventCallback, acm);
    ...
}
4、进行USB通信（读写等）
static int32_t AcmSendNotifyRequest(struct UsbAcmDevice *acm, uint8_t type,
    uint16_t value, void *data, uint32_t length)
{
...
/* 异步发送 */ 
    ret = UsbFnRequestSubmitAsync(req); 
    ...
}
5、关闭接口，停止Event接收，删除设备
static int32_t AcmReleaseFuncDevice(struct UsbAcmDevice *acm)
{
int32_t ret;
/* 关闭接口 */
    (void)UsbFnInterfaceClose(acm->ctrlIface.handle);
(void)UsbFnInterfaceClose(acm->dataIface.handle);
/* 停止接收Event */
(void)UsbFnInterfaceStopRecvEvent(acm->ctrlIface.fn);
/* 删除设备 */
    ret = UsbFnDeviceRemove(acm->fnDev);
    if (ret != HDF_SUCCESS) {
        HDF_LOGE("%s: remove usb function device failed", __func__);
    }
    return ret;
}
```
