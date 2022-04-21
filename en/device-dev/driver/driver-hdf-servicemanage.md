# Driver Service Management


Driver services are objects of capabilities provided by HDF driver devices to external systems and are managed by the HDF in a unified manner. Driver service management involves providing and obtaining driver services.


The HDF uses the **policy** field in the configuration file to define policies for drivers to provide services externally. The values this field are as follows:


  
```
typedef enum {
    /* The driver does not provide services. */
    SERVICE_POLICY_NONE = 0,
    /* The driver provides services only for kernel-mode applications. */
    SERVICE_POLICY_PUBLIC = 1,
    /* The driver provides services for both kernel- and user-mode applications. */
    SERVICE_POLICY_CAPACITY = 2,
    /** The driver services are not provided externally but can be subscribed to. */
    SERVICE_POLICY_FRIENDLY = 3,
    /* The driver private services cannot be provided externally or subscribed to. */
    SERVICE_POLICY_PRIVATE = 4,
    /** Invalid service policy. */
    SERVICE_POLICY_INVALID
} ServicePolicy;
```


## When to Use

The driver service management capability can be used if the driver provides capabilities using APIs.


## Available APIs

The table below describes the APIs for driver service management.

  **Table 1** APIs for driver service management

| API| Description| 
| -------- | -------- |
| int32_t&nbsp;(\*Bind)(struct&nbsp;HdfDeviceObject&nbsp;\*deviceObject); | Binds a service API to the HDF. You need to implement the **Bind()** function.| 
| const&nbsp;struct&nbsp;HdfObject&nbsp;\*DevSvcManagerClntGetService(const&nbsp;char&nbsp;\*svcName); | Obtains a driver service.| 
| int&nbsp;HdfDeviceSubscribeService(<br>struct&nbsp;HdfDeviceObject&nbsp;\*deviceObject,&nbsp;const&nbsp;char&nbsp;\*serviceName,&nbsp;struct&nbsp;SubscriberCallback&nbsp;callback); | Subscribes to a driver service.| 


## How to Develop

The development procedure is as follows:

1. Define the services to be provided by the driver.
     
   ```
   Define the driver service structure.
   struct ISampleDriverService {
       struct IDeviceIoService ioService;   // The first member must be of the IDeviceIoService type.
       int32_t (*ServiceA)(void);               // API of the first driver service.
       int32_t (*ServiceB)(uint32_t inputCode); // API of the second driver service. You can add more as required.
   };
   
   Implement the driver service APIs.
   int32_t SampleDriverServiceA(void)
   {
       // You need to implement the service logic.
       return 0;
   }
   
   int32_t SampleDriverServiceB(uint32_t inputCode)
   {
       // You need to implement the service logic.
       return 0;
   }
   ```

2. Bind the driver service to the HDF and implement the **Bind()** function in the **HdfDriverEntry** structure.
     
   ```
   int32_t SampleDriverBind(struct HdfDeviceObject *deviceObject)
   {
       // deviceObject is a pointer to the device object created by the HDF for each driver. The device object holds private device data and service APIs.
       if (deviceObject == NULL) {
           HDF_LOGE("Sample device object is null!");
           return -1;
       }
       static struct ISampleDriverService sampleDriverA = {
           .ServiceA = SampleDriverServiceA,
           .ServiceB = SampleDriverServiceB,
       };
       deviceObject->service = &sampleDriverA.ioService;
       return 0;
   }
   ```

3. Obtain the driver service.
   The driver service can be obtained by using the API or subscription mechanism provided by the HDF.

   - Using the API
      Use the API provided by the HDF to obtain the driver service if the driver has been loaded.

        
      ```
      const struct ISampleDriverService *sampleService =
              (const struct ISampleDriverService *)DevSvcManagerClntGetService("sample_driver");
      if (sampleService == NULL) {
          return -1;
      }
      sampleService->ServiceA();
      sampleService->ServiceB(5);
      ```
   - Using the subscription mechanism
      If the kernel mode is unaware of the time for loading drivers on the same host, use the subscription mechanism provided by the HDF to subscribe to the drivers. After the drivers are loaded, the HDF sends the driver services to the subscriber. The implementation is as follows:

        
      ```
      // Callback invoked to return the driver services after the subscribed driver is loaded.
      // object is the pointer to the private data of the subscriber, and service is the pointer to the subscribed service object.
      int32_t TestDriverSubCallBack(struct HdfDeviceObject *deviceObject, const struct HdfObject *service)
      {
          const struct ISampleDriverService *sampleService =
              (const struct ISampleDriverService *)service;
          if (sampleService == NULL) {
              return -1;
          }
          sampleService->ServiceA();
          sampleService->ServiceB(5);
      }
      // Implement the subscription process.
      int32_t TestDriverInit(struct HdfDeviceObject *deviceObject)
      {
          if (deviceObject == NULL) {
              HDF_LOGE("Test driver init failed, deviceObject is null!");
              return -1;
          }
          struct SubscriberCallback callBack;
          callBack.deviceObject = deviceObject;
          callBack.OnServiceConnected = TestDriverSubCallBack;
          int32_t ret = HdfDeviceSubscribeService(deviceObject, "sample_driver", callBack);
          if (ret != 0) {
              HDF_LOGE("Test driver subscribe sample driver failed!");
          }
          return ret;
      }
      ```
