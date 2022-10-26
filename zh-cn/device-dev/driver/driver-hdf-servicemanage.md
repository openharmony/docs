# 驱动服务管理


驱动服务是HDF驱动设备对外提供能力的对象，由HDF框架统一管理。驱动服务管理主要包含驱动服务的发布和获取。


HDF框架定义了驱动对外发布服务的策略，由配置文件中的policy字段来控制，policy字段的取值范围以及含义如下：


  
```c
typedef enum {
    /* 驱动不提供服务 */
    SERVICE_POLICY_NONE = 0,
    /* 驱动对内核态发布服务 */
    SERVICE_POLICY_PUBLIC = 1,
    /* 驱动对内核态和用户态都发布服务 */
    SERVICE_POLICY_CAPACITY = 2,
    /* 驱动服务不对外发布服务，但可以被订阅 */
    SERVICE_POLICY_FRIENDLY = 3,
    /* 驱动私有服务不对外发布服务，也不能被订阅 */
    SERVICE_POLICY_PRIVATE = 4,
    /* 错误的服务策略 */
    SERVICE_POLICY_INVALID
} ServicePolicy;
```


## 使用场景

当驱动需要以接口的形式对外提供能力时，可以使用HDF框架的驱动服务管理能力。


## 接口说明

针对驱动服务管理功能，HDF框架开放了以下接口供开发者调用，如下表所示：

  **表1** 服务管理接口

| 方法 | 描述 | 
| -------- | -------- |
| int32_t&nbsp;(\*Bind)(struct&nbsp;HdfDeviceObject&nbsp;\*deviceObject) | 需要驱动开发者实现Bind函数，将自己的服务接口绑定到HDF框架中。 | 
| const&nbsp;struct&nbsp;HdfObject&nbsp;\*DevSvcManagerClntGetService(const&nbsp;char&nbsp;\*svcName)| 获取驱动的服务。 | 
|int&nbsp;HdfDeviceSubscribeService(<br/>struct&nbsp;HdfDeviceObject&nbsp;\*deviceObject,&nbsp;const&nbsp;char&nbsp;\*serviceName,&nbsp;struct&nbsp;SubscriberCallback&nbsp;callback) | 订阅驱动的服务。 | 


## 开发步骤

驱动服务管理的开发包括驱动服务的编写、绑定、获取或者订阅，详细步骤如下。

1. 驱动服务编写。
     
   ```c
   // 驱动服务结构的定义
   struct ISampleDriverService {
       struct IDeviceIoService ioService;       // 服务结构的首个成员必须是IDeviceIoService类型的成员。
       int32_t (*ServiceA)(void);               // 驱动的第一个服务接口。
       int32_t (*ServiceB)(uint32_t inputCode); // 驱动的第二个服务接口，有多个可以依次往下累加。
   };
   
   // 驱动服务接口的实现
   int32_t SampleDriverServiceA(void)
   {
       // 驱动开发者实现业务逻辑
       return HDF_SUCCESS;
   }
   
   int32_t SampleDriverServiceB(uint32_t inputCode)
   {
       // 驱动开发者实现业务逻辑
       return HDF_SUCCESS;
   }
   ```

2. 驱动服务绑定。
   
   开发者实现HdfDriverEntry中的Bind指针函数，如下的SampleDriverBind，把驱动服务绑定到HDF框架中。
     
   ```c
   int32_t SampleDriverBind(struct HdfDeviceObject *deviceObject)
   {
       // deviceObject为HDF框架给每一个驱动创建的设备对象，用来保存设备相关的私有数据和服务接口。
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

3. 驱动服务获取。

   应用程序开发者获取驱动服务有两种方式：通过HDF接口直接获取和通过HDF提供的订阅机制获取。

   - 通过HDF接口直接获取

     当驱动服务获取者明确驱动已经加载完成时，获取该驱动的服务可以通过HDF框架提供的能力接口直接获取，如下所示：

        
      ```c
      const struct ISampleDriverService *sampleService =
              (const struct ISampleDriverService *)DevSvcManagerClntGetService("sample_driver");
      if (sampleService == NULL) {
          return HDF_FAILURE;
      }
      sampleService->ServiceA();
      sampleService->ServiceB(5);
      ```
   - 通过HDF提供的订阅机制获取

     当内核态驱动服务获取者对驱动（同一个host）加载的时机不感知时，可以通过HDF框架提供的订阅机制来订阅该驱动服务。当该驱动加载完成时，HDF框架会将被订阅的驱动服务发布给订阅者（驱动服务获取者），实现方式如下所示：

        
      ```c
      // 订阅回调函数的编写，当被订阅的驱动加载完成后，HDF框架会将被订阅驱动的服务发布给订阅者，通过这个回调函数给订阅者使用。
      // object为订阅者的私有数据，service为被订阅的服务对象。
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
      // 订阅过程的实现
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
