# Driver Messaging Mechanism


## When to Use

The HDF messaging mechanism implements the interaction between the user-mode applications and kernel-mode drivers.


## Available APIs

The messaging mechanism allows:

1. A user-mode application to send a message to a driver.

2. A user-mode application to receive events reported by a driver.

  **Table 1** APIs for the driver messaging mechanism

| API| Description|
| -------- | -------- |
| struct HdfIoService \*HdfIoServiceBind(const char \*serviceName); | Obtains a driver service. After obtaining the driver service, the user-mode application uses **Dispatch()** in the driver service obtained to send messages to the driver.|
| void HdfIoServiceRecycle(struct HdfIoService \*service); | Releases a driver service.|
| int HdfDeviceRegisterEventListener(struct HdfIoService \*target, struct HdfDevEventlistener \*listener); | Registers the method for receiving events reported by the driver.|
| int HdfDeviceSendEvent(struct HdfDeviceObject \*deviceObject, uint32_t id, struct HdfSBuf \*data); | Sends events. |


## How to Develop

1. In the driver configuration file, set **policy** to **2**. For more details, see [Driver Service Management](../driver/driver-hdf-servicemanage.md).
   
   ```
   device_sample :: Device {
       policy = 2;
       ...
   }
   ```

2. Set permissions for the device node of the driver. By default, the **permission** field is set to **0666**. You can set it based on service requirements.

3. Implement the **Dispatch()** method of **IDeviceIoService**.
   
   ```c
   // Dispatch() is used to process messages sent from the user-mode application.
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

4. Define the cmd type in the message processing function.
   
   ```c
   #define SAMPLE_WRITE_READ 1 // Read and write operation 1
   ```

5. Enable the user-mode application to obtain a service and send a message to the driver.
   
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

6. Enable the user-mode application to receive messages from the driver.
   1. Implement the method for the user-mode application to process the events reported by the driver.
      
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
   2. Register the method for the user-mode application to receive messages from the driver.
      
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
   3. Enable the driver to report events.
      
       ```c
       int32_t SampleDriverDispatch(HdfDeviceIoClient *client, int cmdCode, struct HdfSBuf *data, struct HdfSBuf *reply)
       {
           // Process the API call.
           return HdfDeviceSendEvent(client->device, cmdCode, data);
       }
       ```
