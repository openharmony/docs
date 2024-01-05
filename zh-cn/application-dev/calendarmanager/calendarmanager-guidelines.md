# Calendar Kit开发指南

## 申请权限开发指导

### 场景概述

应用在使用Calendar Kit系统能力前，需要检查是否已经获取用户授权读取、写入日历日程的权限。如未获得授权，可以向用户申请所需要的权限。

Calendar kit所需权限有：

- ohos.permission.READ_CALENDAR：用于读取日历日程信息。

- ohos.permission.WRITE_CALENDAR：用于写入日历日程信息。

必须手动申请且获得用户授权才能使用上述权限。

### 申请权限步骤

module.json5中配置所需申请的权限
```
"requestPermissions": [
  {
    "name": "ohos.permission.READ_CALENDAR",
  },
  {
    "name": "ohos.permission.WRITE_CALENDAR"
  }
]
```

代码中手动申请权限
```typescript
import abilityAccessCtrl, {PermissionRequestResult, Permission} from '@ohos.abilityAccessCtrl';
import {mContext} from '../entryability/EntryAbility'; // 获取的上下文，需自己定义
        
const permissions: Permission[] = ["ohos.permission.READ_CALENDAR", "ohos.permission.WRITE_CALENDAR"];
const atManager = abilityAccessCtrl.createAtManager();
atManager.requestPermissionsFromUser(mContext, permissions).then((data: PermissionRequestResult) => {
  console.log(`get Permission result: ${JSON.stringify(data)}`);
})
```

申请权限后获取calendarManager
```typescript
import calendarManager from '@ohos.calendarManager';
import {mContext} from '../entryability/EntryAbility'; // 获取的上下文，需自己定义
        
let calendarMgr: calendarManager.CalendarManager = calendarManager.getCalendarManager(mContext);
```

### 调用calendar Kit函数

- [getCalendar()](../reference/apis/js-apis-calendarManager.md#getcalendar)

- [addEvent()](../reference/apis/js-apis-calendarManager.md#addevent)