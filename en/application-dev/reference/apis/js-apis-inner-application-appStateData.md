# AppStateData

The **AppStateData** module defines the application state data, which can be obtained through [getForegroundApplications](js-apis-app-ability-appManager.md#appmanagergetforegroundapplications).

> **NOTE**
> 
> The initial APIs of this module are supported since API version 8. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```ts
import appManager from '@ohos.app.ability.appManager';
```

## Attributes

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**System API**: This module is marked as @systemapi and not visible to third-party applications.

| Name                     | Type  | Mandatory | Description      |
| ------------------------- | ------ | ---- | --------- |
| bundleName<sup>8+</sup>   | string | No  | Bundle name.|
| uid<sup>8+</sup>          | number | No  | UID of the application.  |
| state<sup>8+</sup>        | number | No  | Application state.<br>**0**: The application is being initialized.<br>**1**: The application has been initialized and is ready.<br>**2**: The application is running in the foreground.<br>**3**: The application is having the focus. (This state is reserved.)<br>**4**: The application is running in the background.<br>**5**: The application has exited.|

**Example**

```ts
import appManager from '@ohos.app.ability.appManager';

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
        }
    });
}
```
