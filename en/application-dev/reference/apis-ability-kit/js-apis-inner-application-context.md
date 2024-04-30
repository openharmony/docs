# Context

The Context module, inherited frome [BaseContext](js-apis-inner-application-baseContext.md), provides context for abilities or applications, including access to application-specific resources.

> **NOTE**
>
>  - The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>  - The APIs of this module can be used only in the stage model.

## Modules to Import

```ts
import common from '@ohos.app.ability.common';
```

## Attributes

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

| Name                 | Type    | Read-only  | Mandatory  | Description                                                              |
|---------------------| ------ | ---- | ---- |------------------------------------------------------------------|
| resourceManager     | resmgr.[ResourceManager](../apis-localization-kit/js-apis-resource-manager.md#resourcemanager) | No   | Yes   | Object for resource management.                                                         |
| applicationInfo     | [ApplicationInfo](js-apis-bundleManager-applicationInfo.md) | No   | Yes   | Application information.                                                      |
| cacheDir            | string | No   | Yes   | Cache directory.                                                           |
| tempDir             | string | No   | Yes   | Temporary directory.                                                           |
| resourceDir<sup>11+<sup>         | string | No   | Yes   | Resource directory.                                                           |
| filesDir            | string | No   | Yes   | File directory.                                                           |
| databaseDir         | string | No   | Yes   | Database directory.                                                          |
| preferencesDir      | string | No   | Yes   | Preferences directory.                                                  |
| bundleCodeDir       | string | No   | Yes   | Bundle code directory. Do not access resource files using concatenated paths. Use [@ohos.resourceManager](../apis-localization-kit/js-apis-resource-manager.md) instead.|
| distributedFilesDir | string | Yes   | Yes   | Distributed file directory.                                                        |
| cloudFileDir<sup>12+</sup>        | string | Yes   | Yes   | Cloud file directory.                                                       |
| eventHub            | [EventHub](js-apis-inner-application-eventHub.md) | No   | Yes   | Event hub that implements event subscription, unsubscription, and triggering.                                          |
| area                | contextConstant.[AreaMode](js-apis-app-ability-contextConstant.md) | No   | Yes   | Encryption level of the directory.                                                         |

## Context.createModuleContext

createModuleContext(moduleName: string): Context

Creates the context based on the module name.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name      | Type                    | Mandatory  | Description           |
| -------- | ---------------------- | ---- | ------------- |
| moduleName | string | Yes   | Module name.|

**Return value**

| Type| Description|
| -------- | -------- |
| Context | Context created.|

**Example**

```ts
import UIAbility from '@ohos.app.ability.UIAbility';
import common from '@ohos.app.ability.common';

export default class EntryAbility extends UIAbility {
  onCreate() {
    console.log('MyAbility onCreate');
    let moduleContext: common.Context;
    try {
      moduleContext = this.context.createModuleContext('entry');
    } catch (error) {
      console.error(`createModuleContext failed, error.code: ${error.code}, error.message: ${error.message}`);
    }
  }
}
```

> **NOTE**
>
> Only the context of other modules in the current application and the context of the [intra-application HSP](../../../application-dev/quick-start/in-app-hsp.md) can be obtained. The context of other applications cannot be obtained.

## Context.getApplicationContext

getApplicationContext(): ApplicationContext

Obtains the context of this application.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Return value**

| Type| Description|
| -------- | -------- |
| [ApplicationContext](js-apis-inner-application-applicationContext.md) | Application context obtained.|

**Example**

```ts
import UIAbility from '@ohos.app.ability.UIAbility';
import common from '@ohos.app.ability.common';

export default class EntryAbility extends UIAbility {
  onCreate() {
    console.log('MyAbility onCreate');
    let applicationContext: common.Context;
    try {
      applicationContext = this.context.getApplicationContext();
    } catch (error) {
      console.error(`getApplicationContext failed, error.code: ${error.code}, error.message: ${error.message}`);
    }
  }
}
```

## Context.getGroupDir<sup>10+</sup>

getGroupDir(dataGroupID: string): Promise\<string>

Obtains the shared directory based on a group ID. This API uses a promise to return the result.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name      | Type                    | Mandatory  | Description           |
| -------- | ---------------------- | ---- | ------------- |
| dataGroupID | string | Yes   | Group ID, which is assigned by the system when an atomic service application project is created.|

**Return value**

| Type| Description|
| -------- | -------- |
| Promise\<string> | Promise used to return the result. If no shared directory exists, null is returned. Only the encryption level EL2 is supported.|

**Error codes**

| ID| Error Message|
| ------- | -------- |
| 16000011 | The context does not exist. |

For details about the error codes, see [Ability Error Codes](errorcode-ability.md).

**Example**

```ts
import UIAbility from '@ohos.app.ability.UIAbility';
import common from '@ohos.app.ability.common';

export default class EntryAbility extends UIAbility {
  onCreate() {
    console.log('MyAbility onCreate');
    let groupId = "1";
    let getGroupDirContext: common.Context = this.context;
    try {
      getGroupDirContext.getGroupDir(groupId).then(data => {
        console.log("getGroupDir result:" + data);
      })
    } catch (error) {
      console.error(`getGroupDirContext failed, error.code: ${error.code}, error.message: ${error.message}`);
    }
  }
}
```

## Context.getGroupDir<sup>10+</sup>

getGroupDir(dataGroupID: string, callback: AsyncCallback\<string>): void

Obtains the shared directory based on a group ID. This API uses an asynchronous callback to return the result.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name      | Type                    | Mandatory  | Description           |
| -------- | ---------------------- | ---- | ------------- |
| dataGroupID | string | Yes   | Group ID, which is assigned by the system when an atomic service application project is created.|
| callback | AsyncCallback\<string> | Yes   | Callback used to return the result. If no shared directory exists, null is returned. Only the encryption level EL2 is supported.|

**Error codes**

| ID| Error Message|
| ------- | -------- |
| 16000011 | The context does not exist. |

For details about the error codes, see [Ability Error Codes](errorcode-ability.md).

**Example**

```ts
import UIAbility from '@ohos.app.ability.UIAbility';
import common from '@ohos.app.ability.common';

export default class EntryAbility extends UIAbility {
  onCreate() {
    console.log('MyAbility onCreate');
    let getGroupDirContext: common.Context = this.context;

    getGroupDirContext.getGroupDir("1", (err, data) => {
      if (err) {
        console.error(`getGroupDir faile, err: ${JSON.stringify(err)}`);
      } else {
        console.log(`getGroupDir result is: ${JSON.stringify(data)}`);
      }
    });
  }
}
```

## Context.createSystemHspModuleResourceManager<sup>12+</sup>

createSystemHspModuleResourceManager(bundleName: string, moduleName: string): resmgr.ResourceManager

Creates a resource manager object for a module of the system-level HSP.

**System API**: This is a system API.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name      | Type    | Mandatory  | Description  |
| -------- |--------| ---- |------|
| bundleName | string | Yes   | Bundle name. |
| moduleName | string | Yes   | Module name.|

**Error codes**

| ID| Error Message|
|  | -------- |
| 401 | Incorrect parameters.|
| 16400001 | The combination of the bundle name and module name does not correspond to a system-level HSP.|

For details about the error codes, see [Ability Error Codes](errorcode-ability.md).

**Example**

```ts
import UIAbility from '@ohos.app.ability.UIAbility';
import common from '@ohos.app.ability.common';

export default class EntryAbility extends UIAbility {
  onCreate() {
    console.log('MyAbility onCreate');
    let hspContext: common.Context = this.context;
    let resourceManager = hspContext.createSystemHspModuleResourceManager("com.example.myapplication", "library");
  }
}
```
