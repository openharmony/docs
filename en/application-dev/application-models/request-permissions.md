# Requesting Permissions


If an application needs to obtain user privacy information or use system capabilities, for example, obtaining location information or using the camera to take photos or record videos, it must request the respective permission from users.


During application development, you must declare the required permission in the **config.json** file and call **requestPermissionsFromUser** to request the permission from users in the form of a dialog box.


To declare a permission in **config.json**, add **reqPermissions** under **module** and list the permission.


For example, to declare the permission to access the calendar, request the **ohos.permission.READ_CALENDAR** permission. For details, see [Permission Application Guide](../security/accesstoken-guidelines.md#stage-model).


The sample code in the **config.json** file is as follows:

```json
{
  "module": {
    // ...
    "reqPermissions": [
      {
        "name": "ohos.permission.READ_CALENDAR"
        // ...
      }
    ]
  }
}
```


Request the permission from uses in the form of a dialog box:

```ts
import featureAbility from '@ohos.ability.featureAbility';

let context = featureAbility.getContext();  
let permissions: Array<string> = ['ohos.permission.READ_CALENDAR']
context.requestPermissionsFromUser(permissions, 1).then((data) => {    
    console.info("Succeed to request permission from user with data: " + JSON.stringify(data))
}).catch((error) => {    
    console.info("Failed to request permission from user with error: " + JSON.stringify(error))
})
```
