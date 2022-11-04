# 驱动消息机制管理


## 使用场景

当用户态应用和内核态驱动需要交互时，可以使用HDF框架的消息机制来实现。


## 接口说明

消息机制的功能主要有以下两种：

1. 用户态应用发送消息到驱动。

2. 用户态应用接收驱动主动上报事件。

  **表1** 消息机制接口

| 方法 | 描述 |
| -------- | -------- |
| struct&nbsp;HdfIoService&nbsp;\*HdfIoServiceBind(const&nbsp;char&nbsp;\*serviceName); | 用户态获取驱动的服务，获取该服务之后通过服务中的Dispatch方法向驱动发送消息。 |
| void&nbsp;HdfIoServiceRecycle(struct&nbsp;HdfIoService&nbsp;\*service); | 释放驱动服务。 |
| int&nbsp;HdfDeviceRegisterEventListener(struct&nbsp;HdfIoService&nbsp;\*target,&nbsp;struct&nbsp;HdfDevEventlistener&nbsp;\*listener); | 用户态程序注册接收驱动上报事件的操作方法。 |
| int&nbsp;HdfDeviceSendEvent(struct&nbsp;HdfDeviceObject&nbsp;\*deviceObject,&nbsp;uint32_t&nbsp;id,&nbsp;struct&nbsp;HdfSBuf&nbsp;\*data); | 驱动主动上报事件接口。 |


## 开发步骤

1. 将驱动配置信息中服务策略policy字段设置为2（SERVICE_POLICY_CAPACITY，参考[policy定义](../driver/driver-hdf-servicemanage.md)）。
   
   ```
   device_sample :: Device {
       policy = 2;
       ...
   }
   ```

2. 配置驱动信息中的服务设备节点权限（permission字段）是框架给驱动创建设备节点的权限，默认是0666，驱动开发者根据驱动的实际使用场景配置驱动设备节点的权限。

3. 在服务实现过程中，实现服务基类成员IDeviceIoService中的Dispatch方法。
   
   ```c
   // Dispatch是用来处理用户态发下来的消息
   int32_t SampleDriverDispatch(struct HdfDeviceIoClient *device, int cmdCode, struct HdfSBuf *data, struct HdfSBuf *reply)
   {
       HDF_LOGI("sample driver lite A dispatch");
       return HDF_SUCCESS;
   }
   int32_t SampleDriverBind(struct HdfDeviceObject *device)
   {
       HDF_LOGI("test for lite os sample driver A Open!");
       if (device == NULL) {
           HDF_LOGE("test for lite os sample driver A Open failed!");
           return HDF_FAILURE;
       }
       static struct ISampleDriverService sampleDriverA = {
           .ioService.Dispatch = SampleDriverDispatch,
           .ServiceA = SampleDriverServiceA,
           .ServiceB = SampleDriverServiceB,
       };
       device->service = (struct IDeviceIoService *)(&sampleDriverA);
       return HDF_SUCCESS;
   }
   ```

4. 驱动定义消息处理函数中的cmd类型。
   
   ```c
   #define SAMPLE_WRITE_READ 1    // 读写操作码1
   ```

5. 用户态获取服务接口并发送消息到驱动。
   
   ```c
   int SendMsg(const char *testMsg)
   {
       if (testMsg == NULL) {
           HDF_LOGE("test msg is null");
           return HDF_FAILURE;
       }
       struct HdfIoService *serv = HdfIoServiceBind("sample_driver");
       if (serv == NULL) {
           HDF_LOGE("fail to get service");
           return HDF_FAILURE;
       }
       struct HdfSBuf *data = HdfSbufObtainDefaultSize();
       if (data == NULL) {
           HDF_LOGE("fail to obtain sbuf data");
           return HDF_FAILURE;
       }
       struct HdfSBuf *reply = HdfSbufObtainDefaultSize();
       if (reply == NULL) {
           HDF_LOGE("fail to obtain sbuf reply");
           ret = HDF_DEV_ERR_NO_MEMORY;
           goto out;
       }
       if (!HdfSbufWriteString(data, testMsg)) {
           HDF_LOGE("fail to write sbuf");
           ret = HDF_FAILURE;
           goto out;
       }
       int ret = serv->dispatcher->Dispatch(&serv->object, SAMPLE_WRITE_READ, data, reply);
       if (ret != HDF_SUCCESS) {
           HDF_LOGE("fail to send service call");
           goto out;
       }
   out:
       HdfSbufRecycle(data);
       HdfSbbufRecycle(reply);
       HdfIoServiceRecycle(serv);
       return ret;
   }
   ```

6. 用户态接收该驱动上报的消息。
   1. 用户态编写驱动上报消息的处理函数。
      
       ```c
       static int OnDevEventReceived(void *priv,  uint32_t id, struct HdfSBuf *data)
       {
           OsalTimespec time;
           OsalGetTime(&time);
           HDF_LOGI("%{public}s received event at %{public}llu.%{public}llu", (char *)priv, time.sec, time.usec);
       
           const char *string = HdfSbufReadString(data);
           if (string == NULL) {
               HDF_LOGE("fail to read string in event data");
               return HDF_FAILURE;
           }
           HDF_LOGI("%{public}s: dev event received: %{public}d %{public}s",  (char *)priv, id, string);
           return HDF_SUCCESS;
       }
       ```
   2. 用户态注册接收驱动上报消息的操作方法。
      
       ```c
       int RegisterListen()
       {
           struct HdfIoService *serv = HdfIoServiceBind("sample_driver");
           if (serv == NULL) {
               HDF_LOGE("fail to get service");
               return HDF_FAILURE;
           }
           static struct HdfDevEventlistener listener = {
               .callBack = OnDevEventReceived,
               .priv ="Service0"
           };
           if (HdfDeviceRegisterEventListener(serv, &listener) != 0) {
               HDF_LOGE("fail to register event listener");
               return HDF_FAILURE;
           }
           ......
           HdfDeviceUnregisterEventListener(serv, &listener);
           HdfIoServiceRecycle(serv);
           return HDF_SUCCESS;
       }
       ```
   3. 驱动上报事件。
      
       ```c
       int32_t SampleDriverDispatch(HdfDeviceIoClient *client, int cmdCode, struct HdfSBuf *data, struct HdfSBuf *reply)
       {
           ... // process api call here
           return HdfDeviceSendEvent(client->device, cmdCode, data);
       }
       ```
