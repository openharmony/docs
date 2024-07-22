 # AppStateData (System API)

The **AppStateData** module defines the application state data, which can be obtained through [getForegroundApplications](js-apis-app-ability-appManager-sys.md#appmanagergetforegroundapplications).

> **NOTE**
> 
> The initial APIs of this module are supported since API version 8. Newly added APIs will be marked with a superscript to indicate their earliest API version.
> The APIs provided by this module are system APIs.

## Modules to Import

```ts
import { appManager } from '@kit.AbilityKit';
```

## Attributes

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**System API**: This module is marked as @systemapi and not visible to third-party applications.

| Name                     | Type  | Mandatory | Description      |
| ------------------------- | ------ | ---- | --------- |
| bundleName<sup>8+</sup>   | string | No  | Bundle name. |
| uid<sup>8+</sup>          | number | No  | UID of the application.  |
| state<sup>8+</sup>        | number | No  | Application state.<br>**0**: The application is being initialized.<br>**1**: The application has been initialized and is ready.<br>**2**: The application is running in the foreground.<br>**3**: The application is having the focus. (This state is reserved.)<br>**4**: The application is running in the background.<br>**5**: The application has exited. |
| isSplitScreenMode<sup>11+</sup> | boolean | No | Whether the application is in split-screen mode.<br>**true**: The application is in split-screen mode.<br>**false**: The application is not in split-screen mode. |
| isFloatingWindowMode<sup>11+</sup> | boolean | No | Whether the application is in floating window mode.<br>**true**: The application is in floating window mode.<br>**false**: The application is not in floating window mode. |

**Example**

```ts
import { appManager } from '@kit.AbilityKit';

function getForegroundAppInfos() {
  appManager.getForegroundApplications((error, data) => {
    if (error) {
      console.log(`getForegroundApplications failed, error.code: ${JSON.stringify(error.code)}, error.message: ${JSON.stringify(error.message)}`);
      return;
    }
    for (let i = 0; i < data.length; i++) {
      let appStateData = data[i];
      console.log(`appStateData.bundleName: ${appStateData.bundleName}`);
      console.log(`appStateData.uid: ${appStateData.uid}`);
      console.log(`appStateData.state: ${appStateData.state}`);
      console.log(`appStateData.isSplitScreenMode: ${appStateData.isSplitScreenMode}`);
      console.log(`appStateData.isFloatingWindowMode: ${appStateData.isFloatingWindowMode}`);
    }
  });
}
```
