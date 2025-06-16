# 取消订阅公共事件（C/C++）


## 场景介绍

订阅者在完成业务需求之后，需要取消订阅公共事件。

## 接口说明

详细的API说明请参考[CommonEvent API参考](../../reference/apis-basic-services-kit/capi-common-event.md)。

| 接口名                               | 描述                                                             |
| ------------------------------------ | ---------------------------------------------------------------- |
|[CommonEvent_ErrCode OH_CommonEvent_UnSubscribe(const CommonEvent_Subscriber* subscriber)](../../reference/apis-basic-services-kit/capi-common-event.md#oh_commonevent_unsubscribe)|取消订阅公共事件。|

## 开发步骤

1. 引用头文件。

   ```c++
   #include <cstdint>
   #include "hilog/log.h"
   #include "BasicServicesKit/oh_commonevent.h"
   ```

2. 在CMake脚本中添加动态链接库。

   ```txt
   target_link_libraries(entry PUBLIC
       libace_napi.z.so
       libhilog_ndk.z.so
       libohcommonevent.so
   )
   ```


3. 取消订阅公共事件。

   订阅者订阅公共事件并完成业务需求后，可以通过[OH_CommonEvent_UnSubscribe](../../reference/apis-basic-services-kit/capi-common-event.md#oh_commonevent_unsubscribe)主动取消订阅事件。

   ```c++
   void Unsubscribe(CommonEvent_Subscriber* subscriber) {
       // 通过传入订阅者来退订事件
       int32_t ret = OH_CommonEvent_UnSubscribe(subscriber);
       OH_LOG_Print(LOG_APP, LOG_INFO, 1, "CES_TEST", "OH_CommonEvent_UnSubscribe ret <%{public}d>.", ret);
   }
   ```