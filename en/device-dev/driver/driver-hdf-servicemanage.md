# Driver Service Management


Driver services are objects of capabilities provided by HDF driver devices to external systems and are managed by the HDF in a unified manner. Driver service management involves publishing and obtaining driver services.


The HDF uses the **policy** field in the configuration file to define policies for a driver to provide services externally. The values this field are as follows:


  
```c
typedef enum {
    /* The driver does not provide services. */
    SERVICE_POLICY_NONE = 0,
    /* The driver publishes services only for kernel-mode processes. */
    SERVICE_POLICY_PUBLIC = 1,
    /* The driver publishes services for both kernel- and user-mode processes. */
    SERVICE_POLICY_CAPACITY = 2,
    /** The driver services are not published externally but can be subscribed to. */
    SERVICE_POLICY_FRIENDLY = 3,
    /* The driver private services cannot be published externally or subscribed to. */
    SERVICE_POLICY_PRIVATE = 4,
    /** Invalid service policy. */
    SERVICE_POLICY_INVALID
} ServicePolicy;
```


## When to Use

You can use the driver service management capability of the HDF when the driver needs to provide capabilities via APIs.


## Available APIs

The table below describes the APIs for driver service management.

  **Table 1** APIs for driver service management

| API| Description| 
| -------- | -------- |
| int32_t (\*Bind)(struct HdfDeviceObject \*deviceObject) | Binds a service API to the HDF. You need to implement the **Bind()** function.|
| const struct HdfObject \*DevSvcManagerClntGetService(const char \*svcName)| Obtains a driver service.|
|int HdfDeviceSubscribeService(struct HdfDeviceObject \*deviceObject, const char \*serviceName, struct SubscriberCallback callback) | Subscribes to a driver service.|


## How to Develop

The development procedure is as follows:

1. Define the service to be published by the driver.
     
   ```c
   // Define the driver service structure.
   struct ISampleDriverService {
       struct IDeviceIoService ioService;       // The first member must be of the IDeviceIoService type.
       int32_t (*ServiceA)(void);               // API of the first driver service.
       int32_t (*ServiceB)(uint32_t inputCode); // API of the second driver service. You can add more as required.
   };
   
   // Implement the driver service APIs.
   int32_t SampleDriverServiceA(void)
   {
       // You need to implement the service logic.
       return HDF_SUCCESS;
   }
   
   int32_t SampleDriverServiceB(uint32_t inputCode)
   {
       // You need to implement the service logic.
       return HDF_SUCCESS;
   }
   ```

2. Bind the driver service.
   
   Implement the **Bind** pointer function, for example, **SampleDriverBind**, in **HdfDriverEntry** to bind the driver service to the HDF.
     
   ```c
   int32_t SampleDriverBind(struct HdfDeviceObject *deviceObject)
   {
       // deviceObject is a pointer to the device object created by the HDF for each driver. The device object holds private device data and service APIs.
       if (deviceObject == NULL) {
           HDF_LOGE("Sample device object is null!");
           return HDF_FAILURE;
       }
       static struct ISampleDriverService sampleDriverA = {
           .ServiceA = SampleDriverServiceA,
           .ServiceB = SampleDriverServiceB,
       };
       deviceObject->service = &sampleDriverA.ioService;
       return HDF_SUCCESS;
   }
   ```

3. Obtain the driver service.

   The driver service can be obtained by using either of the following methods:

   - Using the API provided by the HDF

     If the service requester clearly knows the time when the driver is loaded, use the API provided by the HDF to obtain the driver service. The following is an example:

        
      ```c
      const struct ISampleDriverService *sampleService =
              (const struct ISampleDriverService *)DevSvcManagerClntGetService("sample_driver");
      if (sampleService == NULL) {
          return HDF_FAILURE;
      }
      sampleService->ServiceA();
      sampleService->ServiceB(5);
      ```
   - Using the subscription mechanism

     If the service requester is unaware of the time when the driver (in the same host) is loaded, use the subscription mechanism provided by the HDF to subscribe to the service. After the driver is loaded, the HDF publishes the driver service to the subscriber. The implementation is as follows:

        
      ```c
      // Callback invoked to return the driver service after the subscribed driver is loaded.
      // object is the pointer to the private data of the subscriber, and service is the pointer to the subscribed service object.
      int32_t TestDriverSubCallBack(struct HdfDeviceObject *deviceObject, const struct HdfObject *service)
      {
          const struct ISampleDriverService *sampleService =
              (const struct ISampleDriverService *)service;
          if (sampleService == NULL) {
              return HDF_FAILURE;
          }
          sampleService->ServiceA();
          sampleService->ServiceB(5);
      }
      // Implement the subscription process.
      int32_t TestDriverInit(struct HdfDeviceObject *deviceObject)
      {
          if (deviceObject == NULL) {
              HDF_LOGE("Test driver init failed, deviceObject is null!");
              return HDF_FAILURE;
          }
          struct SubscriberCallback callBack;
          callBack.deviceObject = deviceObject;
          callBack.OnServiceConnected = TestDriverSubCallBack;
          int32_t ret = HdfDeviceSubscribeService(deviceObject, "sample_driver", callBack);
          if (ret != HDF_SUCCESS) {
              HDF_LOGE("Test driver subscribe sample driver failed!");
          }
          return ret;
      }
      ```
