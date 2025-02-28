# Unsubscribing from Common Events in C


## When to Use

After completing service requirements, subscribers need to unsubscribe from common events.

## Available APIs

For details about the APIs, see [CommonEvent](../../reference/apis-basic-services-kit/capi-common-event.md).

| API                              | Description                                                            |
| ------------------------------------ | ---------------------------------------------------------------- |
|[CommonEvent_ErrCode OH_CommonEvent_UnSubscribe(const CommonEvent_Subscriber* subscriber)](../../reference/apis-basic-services-kit/capi-common-event.md#oh_commonevent_unsubscribe)|Creates the subscriber information.|

## How to Develop

1. Reference header files.

   ```c++
   #include <cstdint>
   #include <cstdio>
   #include <cwchar>
   #include <vector>
   #include <string.h>
   #include "hilog/log.h"
   #include "BasicServicesKit/oh_commonevent.h"
   #include "BasicServicesKit/oh_commonevent_support.h"
   ```

2. Add dynamic link libraries to the CMake script.

   ```txt
   target_link_libraries(entry PUBLIC
       libace_napi.z.so
       libhilog_ndk.z.so
       libohcommonevent.so
   )
   ```


3. Unsubscribe from a common event.

   After a subscriber subscribes to a common event and meets service requirements, the subscriber can use [OH_CommonEvent_UnSubscribe](../../reference/apis-basic-services-kit/capi-common-event.md#oh_commonevent_unsubscribe) to unsubscribe from the event.

   ```c++
   void Unsubscribe(CommonEvent_Subscriber* subscriber) {
       // Unsubscribe from a common event by passing a subscriber.
       int32_t ret = OH_CommonEvent_UnSubscribe(subscriber);
       OH_LOG_INFO(LOG_APP, "OH_CommonEvent_UnSubscribe ret <%{public}d>.", ret);
   }
   ```
