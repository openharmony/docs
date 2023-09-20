# PermissionRequestResult

The **PermissionRequestResult** module defines the result of a permission request. The result is returned when [requestPermissionsFromUser](js-apis-abilityAccessCtrl.md#requestpermissionsfromuser9) is called to request permissions.

> **NOTE**
> 
> - The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version. 
> - The APIs of this module can be used only in the stage model.

## Attributes

**System capability**: SystemCapability.Security.AccessToken

| Name| Type| Readable| Writable| Description|
| -------- | -------- | -------- | -------- | -------- |
| permissions | Array&lt;string&gt; | Yes| No| Permissions requested.|
| authResults | Array&lt;number&gt; | Yes| No| Result of the permission request.<br>- **-1**: The permission is not authorized and must be set in **Settings** without displaying a dialog box.<br>- **0**: The permission is authorized.<br>- **2**: The permission is not authorized due to an invalid request. The possible causes are as follows:<br>  - The permission is not declared in the configuration file.<br>  - The permission name is invalid.<br>  - Special conditions for applying for the permission are not satisfied. See [ohos.permission.LOCATION](../../security/permission-list.md#ohospermissionlocation) and [ohos.permission.APPROXIMATELY_LOCATION](../../security/permission-list.md#ohospermissionapproximately_location).|

## Usage

The permission request result is obtained through an **atManager** instance.

**Example**

The ArkTS syntax does not support direct use of **globalThis**. A singleton map is required to enable the use of **globalThis**. You need to perform the following operations:

a. Import the created singleton object **GlobalThis** to **EntryAbility.ets**.
  ```typescript
    import {GlobalThis} from '../utils/globalThis'; // Set it based on the path of globalThis.ets.
  ```
b. Add the following to **onCreate**:
  ```typescript
    GlobalThis.getInstance().setContext('context', this.context);
  ```

> **NOTE**
>
> An alert will be generated when a **.ets** file is imported to a TS file. To prevent the alert, you need to change the file name extension of **EntryAbility.ts** to **EntryAbility.ets** and modify the file name extension in **module.json5**.

The sample code of **globalThis.ets** is as follows:
```typescript
import common from '@ohos.app.ability.common';

// Construct a singleton object.
export class GlobalThis {
  private constructor() {}
  private static instance: GlobalThis;
  private _uiContexts = new Map<string, common.UIAbilityContext>();

  public static getInstance(): GlobalThis {
    if (!GlobalThis.instance) {
      GlobalThis.instance = new GlobalThis();
    }
    return GlobalThis.instance;
  }

  getContext(key: string): common.UIAbilityContext | undefined {
    return this._uiContexts.get(key);
  }

  setContext(key: string, value: common.UIAbilityContext): void {
    this._uiContexts.set(key, value);
  }

  // Set other content in the same way.
}
```

```ts
import { BusinessError } from '@ohos.base';
import abilityAccessCtrl from '@ohos.abilityAccessCtrl';
import common from '@ohos.app.ability.common';
import { GlobalThis } from '../utils/globalThis';

let atManager = abilityAccessCtrl.createAtManager();
try {
  let context: common.UIAbilityContext = GlobalThis.getInstance().getContext('context');
  atManager.requestPermissionsFromUser(context, ["ohos.permission.CAMERA"]).then((data) => {
      console.info("data:" + JSON.stringify(data));
      console.info("data permissions:" + data.permissions);
      console.info("data authResults:" + data.authResults);
  }).catch((err: BusinessError) => {
      console.info("data:" + JSON.stringify(err));
  })
} catch(err) {
  console.log(`catch err->${JSON.stringify(err)}`);
}
```
