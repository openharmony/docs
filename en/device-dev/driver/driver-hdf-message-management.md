# Driver Messaging Mechanism


## When to Use

The HDF messaging mechanism implements the interaction between the user-mode applications and kernel-mode drivers.


## Available APIs

The messaging mechanism allows:

1. User-mode applications to send messages to drivers.

2. User-mode applications to receive events from drivers.

  **Table 1** APIs for the driver messaging mechanism

| API| Description|
| -------- | -------- |
| struct&nbsp;HdfIoService&nbsp;\*HdfIoServiceBind(const&nbsp;char&nbsp;\*serviceName); | Obtains a driver service. The **Dispatch()** method in the driver service obtained sends messages to the driver.|
| void&nbsp;HdfIoServiceRecycle(struct&nbsp;HdfIoService&nbsp;\*service); | Releases a driver service.|
| int&nbsp;HdfDeviceRegisterEventListener(struct&nbsp;HdfIoService&nbsp;\*target,&nbsp;struct&nbsp;HdfDevEventlistener&nbsp;\*listener); | Registers the method for receiving events reported by the driver.|
| int&nbsp;HdfDeviceSendEvent(struct&nbsp;HdfDeviceObject&nbsp;\*deviceObject,&nbsp;uint32_t&nbsp;id,&nbsp;struct&nbsp;HdfSBuf&nbsp;\*data); | Sends events. |


## How to Develop

1. In the driver configuration, set **policy** to **2**. For more details, see [policy](../driver/driver-hdf-servicemanage.md).
   
   ```
   device_sample :: Device {
       policy = 2;
       ...
   }
   ```

2. Set the driver permission. By default, the **permission** field is set to **0666**, which allows the driver to create device nodes. You can set this field based on service requirements.

3. Implement the **Dispatch()** method of **IDeviceIoService**.
   
   ```
   // Dispatch messages sent from the user-mode application.
   int32_t SampleDriverDispatch(struct HdfDeviceObject *device, int cmdCode, struct HdfSBuf *data, struct HdfSBuf *reply)
   {
       HDF_LOGE("sample driver lite A dispatch");
       return 0;
   }
   int32_t SampleDriverBind(struct HdfDeviceObject *device)
   {
       HDF_LOGE("test for lite os sample driver A Open!");
       if (device == NULL) {
           HDF_LOGE("test for lite os sample driver A Open failed!");
           return -1;
       }
       static struct ISampleDriverService sampleDriverA = {
           .ioService.Dispatch = SampleDriverDispatch,
           .ServiceA = SampleDriverServiceA,
           .ServiceB = SampleDriverServiceB,
       };
       device->service = (struct IDeviceIoService *)(&sampleDriverA);
       return 0;
   }
   ```

4. Define the cmd type in the message processing function.
   
   ```
   #define SAMPLE_WRITE_READ 1 // Read and write operation 1
   ```

5. Bind the driver service and the user-mode application to enable messages to be sent to the driver.
   
   ```
   int SendMsg(const char *testMsg)
   {
       if (testMsg == NULL) {
           HDF_LOGE("test msg is null");
           return -1;
       }
       struct HdfIoService *serv = HdfIoServiceBind("sample_driver");
       if (serv == NULL) {
           HDF_LOGE("fail to get service");
           return -1;
       }
       struct HdfSBuf *data = HdfSBufObtainDefaultSize();
       if (data == NULL) {
           HDF_LOGE("fail to obtain sbuf data");
           return -1;
       }
       struct HdfSBuf *reply = HdfSBufObtainDefaultSize();
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
       HdfSBufRecycle(data);
       HdfSBufRecycle(reply);
       HdfIoServiceRecycle(serv);
       return ret;
   }
   ```

6. Enable the user-mode application to receive messages from the driver.
   1. Enable the driver to report events to the user-mode application.
      
       ```
       static int OnDevEventReceived(void *priv,  uint32_t id, struct HdfSBuf *data)
       {
           OsalTimespec time;
           OsalGetTime(&time);
           HDF_LOGE("%s received event at %llu.%llu", (char *)priv, time.sec, time.usec);
       
           const char *string = HdfSbufReadString(data);
           if (string == NULL) {
               HDF_LOGE("fail to read string in event data");
               return -1;
           }
           HDF_LOGE("%s: dev event received: %d %s",  (char *)priv, id, string);
           return 0;
       }
       ```
   2. Register the method for receiving the messages from the driver.
      
       ```
       int RegisterListen()
       {
           struct HdfIoService *serv = HdfIoServiceBind("sample_driver");
           if (serv == NULL) {
               HDF_LOGE("fail to get service");
               return -1;
           }
           static struct HdfDevEventlistener listener = {
               .callBack = OnDevEventReceived,
               .priv ="Service0"
           };
           if (HdfDeviceRegisterEventListener(serv, &listener) != 0) {
               HDF_LOGE("fail to register event listener");
               return -1;
           }
           ......
           HdfDeviceUnregisterEventListener(serv, &listener);
           HdfIoServiceRecycle(serv);
           return 0;
       }
       ```
   3. Enable the driver to report events.
      
       ```
       int32_t SampleDriverDispatch(struct HdfDeviceObject *device, int cmdCode, struct HdfSBuf *data, struct HdfSBuf *reply)
       {
           ... // Process the API call.
           return HdfDeviceSendEvent(deviceObject, cmdCode, data);
       }
       ```
