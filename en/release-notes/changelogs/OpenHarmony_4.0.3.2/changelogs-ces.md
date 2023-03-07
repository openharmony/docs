# Common Event Subsystem Changelog

## cl.ces.1 Event Enum Change of ohos.commonEvent

**Change Impact**

For applications developed based on earlier versions, the following common events of the **.ohos.commonEvent** module must be adapted.

| Common Event                         |
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

**Key API/Component Changes**

Replace the common events in **ohos.commonEvent** with those in **ohos.commonEventManager**.

| Common Event in ohos.commonEvent | Common Event in ohos.commonEventManager |
| ----------------------------------- | ----------------------------------- |
| COMMON_EVENT_PACKAGE_CACHE_CLEARED  | COMMON_EVENT_PACKAGE_CACHE_CLEARED  |
| COMMON_EVENT_USB_STATE              | COMMON_EVENT_USB_STATE              |
| COMMON_EVENT_USB_PORT_CHANGED       | COMMON_EVENT_USB_PORT_CHANGED       |
| COMMON_EVENT_VOLUME_REMOVED         | COMMON_EVENT_VOLUME_REMOVED         |
| COMMON_EVENT_VOLUME_UNMOUNTED       | COMMON_EVENT_VOLUME_UNMOUNTED       |
| COMMON_EVENT_VOLUME_MOUNTED         | COMMON_EVENT_VOLUME_MOUNTED         |
| COMMON_EVENT_VOLUME_BAD_REMOVAL     | COMMON_EVENT_VOLUME_BAD_REMOVAL     |
| COMMON_EVENT_VOLUME_EJECT           | COMMON_EVENT_VOLUME_EJECT           |
| COMMON_EVENT_SLOT_CHANGE            | COMMON_EVENT_SLOT_CHANGE            |
| COMMON_EVENT_SPN_INFO_CHANGED       | COMMON_EVENT_SPN_INFO_CHANGED       |
| COMMON_EVENT_QUICK_FIX_APPLY_RESULT | COMMON_EVENT_QUICK_FIX_APPLY_RESULT |

**Adaptation Guide**

Replace the events in **ohos.commonEvent** with those in **ohos.commonEventManager**.

Before change:

```typescript
import commonEvent from '@ohos.commonEvent';
let event: string = commonEvent.Support.COMMON_EVENT_PACKAGE_CACHE_CLEARED;
```

After change:

```typescript
import commonEventManager from '@ohos.commonEventManager';
let event: string = commonEventManager.Support.COMMON_EVENT_PACKAGE_CACHE_CLEARED;
```
