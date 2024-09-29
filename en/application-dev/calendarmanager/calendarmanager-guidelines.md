# Calendar Kit Development

## Requesting Permissions

### Scenario

To use the Calendar Kit capabilities, your application must have the permissions to read and write calendar events. If your application has not been granted such permissions, apply for them from the user.

Specifically, Calendar Kit requires the following permissions:

- **ohos.permission.READ_CALENDAR**: used to read calendar events.

- **ohos.permission.WRITE_CALENDAR**: used to write calendar events.

You must manually apply for these required permissions.

### Procedure for Requesting Permissions

Declare the required permissions in **module.json5** file. For details, see [Declaring Permissions](https://gitee.com/openharmony/docs/blob/master/en/application-dev/security/AccessToken/declare-permissions.md).
```
{
  "module" : {
    // ...
    "requestPermissions":[
      {
        "name" : "ohos.permission.READ_CALENDAR",
        // reason is used to describe the reason for applying for the permission. The value is a resource reference of the string type, in the $string: \*\*\* format.
        "reason": "$string:reason",
        "usedScene": {
          "abilities": [
            "XxxAbility"
          ],
          "when":"inuse"
        }
      },
      {
        "name" : "ohos.permission.WRITE_CALENDAR",
        "reason": "$string:reason",
        "usedScene": {
          "abilities": [
            "XxxAbility"
          ],
          "when":"always"
        }
      }
    ]
  }
}
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
