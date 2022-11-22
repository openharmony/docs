# HDF开发实例


下面基于HDF框架，提供一个完整的样例，包含配置文件的添加，驱动代码的实现以及用户态程序和驱动交互的流程。


## 添加配置

在HDF框架的配置文件（例如vendor/hisilicon/xxx/hdf_config/device_info）中添加该驱动的配置信息，如下所示：

  
```
root {
    device_info {
        match_attr = "hdf_manager";
        template host {
            hostName = "";
            priority = 100;
            template device {
                template deviceNode {
                    policy = 0;
                    priority = 100;
                    preload = 0;
                    permission = 0664;
                    moduleName = "";
                    serviceName = "";
                    deviceMatchAttr = "";
                }
            }
        }
        sample_host :: host {
            hostName = "sample_host";
            sample_device :: device {
                device0 :: deviceNode {
                    policy = 2;
                    priority = 100;
                    preload = 1;
                    permission = 0664;
                    moduleName = "sample_driver";
                    serviceName = "sample_service";
                }
            }
        }
    }
}
```


## 编写驱动代码

基于HDF框架编写的sample驱动代码如下（编译参考[驱动开发](../driver/driver-hdf-development.md)）：

  
```c
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/ioctl.h>
#include "hdf_log.h"
#include "hdf_base.h"
#include "hdf_device_desc.h"

#define HDF_LOG_TAG sample_driver

#define SAMPLE_WRITE_READ 123

static int32_t HdfSampleDriverDispatch(
    struct HdfDeviceIoClient *client, int id, struct HdfSBuf *data, struct HdfSBuf *reply)
{
    HDF_LOGI("%{public}s: received cmd %{public}d", __func__, id);
    if (id == SAMPLE_WRITE_READ) {
        const char *readData = HdfSbufReadString(data);
        if (readData != NULL) {
            HDF_LOGE("%{public}s: read data is: %{public}s", __func__, readData);
        }
        if (!HdfSbufWriteInt32(reply, INT32_MAX)) {
            HDF_LOGE("%{public}s: reply int32 fail", __func__);
        }
        return HdfDeviceSendEvent(client->device, id, data);
    }
    return HDF_FAILURE;
}

static void HdfSampleDriverRelease(struct HdfDeviceObject *deviceObject)
{
    // release resources here
    return;
}

static int HdfSampleDriverBind(struct HdfDeviceObject *deviceObject)
{
    if (deviceObject == NULL) {
        return HDF_FAILURE;
    }
    static struct IDeviceIoService testService = {
        .Dispatch = HdfSampleDriverDispatch,
    };
    deviceObject->service = &testService;
    return HDF_SUCCESS;
}

static int HdfSampleDriverInit(struct HdfDeviceObject *deviceObject)
{
    if (deviceObject == NULL) {
        HDF_LOGE("%{public}s::ptr is null!", __func__);
        return HDF_FAILURE;
    }
    HDF_LOGI("Sample driver Init success");
    return HDF_SUCCESS;
}

static struct HdfDriverEntry g_sampleDriverEntry = {
    .moduleVersion = 1,
    .moduleName = "sample_driver",
    .Bind = HdfSampleDriverBind,
    .Init = HdfSampleDriverInit,
    .Release = HdfSampleDriverRelease,
};

HDF_INIT(g_sampleDriverEntry);
```


## 编写用户程序和驱动交互代码

基于HDF框架编写的用户态程序和驱动交互的代码如下（代码可以放在目录drivers/hdf_core/adapter/uhdf下面编译，BUILD.gn可以参考drivers/hdf_core/framework/sample/platform/uart/dev/BUILD.gn）：

  
```c
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include "hdf_log.h"
#include "hdf_sbuf.h"
#include "hdf_io_service_if.h"

#define HDF_LOG_TAG sample_test
#define SAMPLE_SERVICE_NAME "sample_service"

#define SAMPLE_WRITE_READ 123

int g_replyFlag = 0;

static int OnDevEventReceived(void *priv,  uint32_t id, struct HdfSBuf *data)
{
    const char *string = HdfSbufReadString(data);
    if (string == NULL) {
        HDF_LOGE("fail to read string in event data");
        g_replyFlag = 1;
        return HDF_FAILURE;
    }
    HDF_LOGI("%{public}s: dev event received: %{public}u %{public}s",  (char *)priv, id, string);
    g_replyFlag = 1;
    return HDF_SUCCESS;
}

static int SendEvent(struct HdfIoService *serv, char *eventData)
{
    int ret = 0;
    struct HdfSBuf *data = HdfSbufObtainDefaultSize();
    if (data == NULL) {
        HDF_LOGE("fail to obtain sbuf data");
        return 1;
    }

    struct HdfSBuf *reply = HdfSbufObtainDefaultSize();
    if (reply == NULL) {
        HDF_LOGE("fail to obtain sbuf reply");
        ret = HDF_DEV_ERR_NO_MEMORY;
        goto out;
    }

    if (!HdfSbufWriteString(data, eventData)) {
        HDF_LOGE("fail to write sbuf");
        ret = HDF_FAILURE;
        goto out;
    }

    ret = serv->dispatcher->Dispatch(&serv->object, SAMPLE_WRITE_READ, data, reply);
    if (ret != HDF_SUCCESS) {
        HDF_LOGE("fail to send service call");
        goto out;
    }

    int replyData = 0;
    if (!HdfSbufReadInt32(reply, &replyData)) {
        HDF_LOGE("fail to get service call reply");
        ret = HDF_ERR_INVALID_OBJECT;
        goto out;
    }
    HDF_LOGI("Get reply is: %{public}d", replyData);
out:
    HdfSbufRecycle(data);
    HdfSbufRecycle(reply);
    return ret;
}

int main()
{
    char *sendData = "default event info";
    struct HdfIoService *serv = HdfIoServiceBind(SAMPLE_SERVICE_NAME);
    if (serv == NULL) {
        HDF_LOGE("fail to get service %s", SAMPLE_SERVICE_NAME);
        return HDF_FAILURE;
    }

    static struct HdfDevEventlistener listener = {
        .callBack = OnDevEventReceived,
        .priv ="Service0"
    };

    if (HdfDeviceRegisterEventListener(serv, &listener) != HDF_SUCCESS) {
        HDF_LOGE("fail to register event listener");
        return HDF_FAILURE;
    }
    if (SendEvent(serv, sendData)) {
        HDF_LOGE("fail to send event");
        return HDF_FAILURE;
    }

    while (g_replyFlag == 0) {
        sleep(1);
    }

    if (HdfDeviceUnregisterEventListener(serv, &listener)) {
        HDF_LOGE("fail to  unregister listener");
        return HDF_FAILURE;
    }

    HdfIoServiceRecycle(serv);
    return HDF_SUCCESS;
}
```

> ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**<br>
> 用户态应用程序使用了HDF框架中的消息发送接口，因此在编译用户态程序的过程中需要依赖HDF框架对外提供的hdf_core和osal的动态库，在gn编译文件中添加如下依赖项：
> 
> deps = [
> 
> "//drivers/hdf_core/adapter/uhdf/manager:hdf_core",
> 
> "//drivers/hdf_core/adapter/uhdf/posix:hdf_posix_osal",
> 
> ]
