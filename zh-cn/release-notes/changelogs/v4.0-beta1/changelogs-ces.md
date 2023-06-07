# 公共事件子系统ChangeLog

## cl.ces.1 ohos.commonEvent中Support事件枚举值修改。

**变更影响**

4.0.3.2之前使用ohos.commonEvent的下面的公共事件需要修改适配。

| 公共事件名                          |
| ----------------------------------- |
| COMMON_EVENT_PACKAGE_CACHE_CLEARED  |
| COMMON_EVENT_USB_STATE              |
| COMMON_EVENT_USB_PORT_CHANGED       |
| COMMON_EVENT_VOLUME_REMOVED         |
| COMMON_EVENT_VOLUME_UNMOUNTED       |
| COMMON_EVENT_VOLUME_MOUNTED         |
| COMMON_EVENT_VOLUME_BAD_REMOVAL     |
| COMMON_EVENT_VOLUME_EJECT           |
| COMMON_EVENT_SLOT_CHANGE            |
| COMMON_EVENT_SPN_INFO_CHANGED       |
| COMMON_EVENT_QUICK_FIX_APPLY_RESULT |

**关键的接口/组件变更**

下面修改的ohos.commonEvent中的公共事件替换到ohos.commonEventManager中。

| 模块       | ohos.commonEvent                    | ohos.commonEventManager             |
| ---------- | ----------------------------------- | ----------------------------------- |
|            | COMMON_EVENT_PACKAGE_CACHE_CLEARED  | COMMON_EVENT_PACKAGE_CACHE_CLEARED  |
|            | COMMON_EVENT_USB_STATE              | COMMON_EVENT_USB_STATE              |
|            | COMMON_EVENT_USB_PORT_CHANGED       | COMMON_EVENT_USB_PORT_CHANGED       |
|            | COMMON_EVENT_VOLUME_REMOVED         | COMMON_EVENT_VOLUME_REMOVED         |
|            | COMMON_EVENT_VOLUME_UNMOUNTED       | COMMON_EVENT_VOLUME_UNMOUNTED       |
| **事件名** | COMMON_EVENT_VOLUME_MOUNTED         | COMMON_EVENT_VOLUME_MOUNTED         |
|            | COMMON_EVENT_VOLUME_BAD_REMOVAL     | COMMON_EVENT_VOLUME_BAD_REMOVAL     |
|            | COMMON_EVENT_VOLUME_EJECT           | COMMON_EVENT_VOLUME_EJECT           |
|            | COMMON_EVENT_SLOT_CHANGE            | COMMON_EVENT_SLOT_CHANGE            |
|            | COMMON_EVENT_SPN_INFO_CHANGED       | COMMON_EVENT_SPN_INFO_CHANGED       |
|            | COMMON_EVENT_QUICK_FIX_APPLY_RESULT | COMMON_EVENT_QUICK_FIX_APPLY_RESULT |

**适配指导**

将调用ohos.commonEvent中的事件替换成调用@ohos.commonEventManager，比如以下示例代码：

```typescript
import commonEvent from '@ohos.commonEvent';
let event: string = commonEvent.Support.COMMON_EVENT_PACKAGE_CACHE_CLEARED;
```

需要修改成

```typescript
import commonEventManager from '@ohos.commonEventManager';
let event: string = commonEventManager.Support.COMMON_EVENT_PACKAGE_CACHE_CLEARED;
```
