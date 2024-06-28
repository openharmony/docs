# Calendar Kit Development

## Requesting Permissions

### Scenario

To use the Calendar Kit capabilities, your application must have the permissions to read and write calendar events. If your application has not been granted such permissions, apply for them from the user.

Specifically, Calendar Kit requires the following permissions:

- **ohos.permission.READ_CALENDAR**: used to read calendar events.

- **ohos.permission.WRITE_CALENDAR**: used to write calendar events.

You must manually apply for these required permissions.

### Procedure for Requesting Permissions

Declare the permissions to request in the **module.json5** file.
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

Manually request the required permissions.
```typescript
import { abilityAccessCtrl, PermissionRequestResult, Permissions } from '@kit.AbilityKit';
import {mContext} from '../entryability/EntryAbility'; // Obtained context, which needs to be defined.

const permissions: Permissions[] = ["ohos.permission.READ_CALENDAR", "ohos.permission.WRITE_CALENDAR"];
const atManager = abilityAccessCtrl.createAtManager();
atManager.requestPermissionsFromUser(mContext, permissions).then((data: PermissionRequestResult) => {
  console.log(`get Permission result: ${JSON.stringify(data)}`);
})
```

Obtain **calendarManager** after the required permissions are obtained.
```typescript
import { calendarManager } from '@kit.CalendarKit';
import {mContext} from '../entryability/EntryAbility'; // Obtained context, which needs to be defined.

let calendarMgr: calendarManager.CalendarManager = calendarManager.getCalendarManager(mContext);
```

### Calendar Kit API References

- [@ohos.calendarManager (Calendar Manager)](../reference/apis-calendar-kit/js-apis-calendarManager.md)
