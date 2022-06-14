# Ability Development
## When to Use
The stage model is an application development model introduced in API version 9. For details about this model, see [Stage Model Overview](stage-brief.md). To develop an ability based on the stage model, you must implement the following logic:
- Create Page abilities for an application that needs to be browsed on the screen and supports man-machine interaction, such as video playback and news browsing.
- Obtain ability configuration information, such as **ApplicationInfo**, **AbilityInfo**, and **HapModuleInfo**.
- Start an ability, start an ability with start options, start an ability with the returned result, or start an ability with an account ID.
- Request certain permissions from end users.
- Notify the ability stage and ability of environment configuration changes.
- Call common components. For details, see [Call Development](stage-call.md).
- Connect to and disconnect from the Service Extension ability. For details, see [Service Extension Ability Development](stage-serviceextension.md).
- Continue the application on another device. For details, see [Ability Continuation Development](stage-ability-continuation.md).

### Launch Type
The ability supports three launch types: singleton, multi-instance, and instance-specific.
The **launchType** item in the **module.json** file is used to specify the launch type.

| Launch Type    | Description    |Description            |
| ----------- | -------  |---------------- |
| standard    | Multi-instance  | A new instance is started each time an ability starts.|
| singleton   | Singleton  | Only one instance exists in the system. If an instance already exists when an ability is started, that instance is reused.|
| specified   | Instance-specific| The internal service of an ability determines whether to create multiple instances during running.|

By default, **singleton** is used.

## Available APIs
The table below describes the APIs provided by the **AbilityStage** class, which has the **context** attribute. For details about the APIs, see [AbilityStage](../reference/apis/js-apis-application-abilitystage.md).

**Table 1** AbilityStage APIs
|API|Description|
|:------|:------|
|void onCreate()|Called when an ability stage is created.|
|string onAcceptWant(want: Want)|Called when a specified ability is started.|
|void onConfigurationUpdated(config: Configuration)|Called when the global configuration is updated.|

The table below describes the APIs provided by the **Ability** class. For details about the APIs, see [Ability](../reference/apis/js-apis-application-ability.md).

**Table 2** Ability APIs
|API|Description|
|:------|:------|
|void onCreate(want: Want, param: AbilityConstant.LaunchParam)|Called when an ability is created.|
|void onDestroy()|Called when the ability is destroyed.|
|void onWindowStageCreate(windowStage: window.WindowStage)|Called when a **WindowStage** is created for the ability. You can use the **window.WindowStage** APIs to implement operations such as page loading.|
|void onWindowStageDestroy()|Called when the **WindowStage** is destroyed for the ability.|
|void onForeground()|Called when the ability is running in the foreground.|
|void onBackground()|Called when the ability is switched to the background.|
|void onNewWant(want: Want)|Called when the ability startup mode is set to singleton.|
|void onConfigurationUpdated(config: Configuration)|Called when the configuration of the environment where the ability is running is updated.|

The **Ability** class has the **context** attribute, which belongs to the **AbilityContext** class. The **AbilityContext** class has attributes such as **abilityInfo** and **currentHapModuleInfo**. For details about the APIs, see [AbilityContext](../reference/apis/js-apis-ability-context.md).

**Table 3** AbilityContext APIs
|API|Description|
|:------|:------|
|void startAbility(want: Want, callback: AsyncCallback\<void>)|Starts an ability.|
|void startAbility(want: Want, options: StartOptions, callback: AsyncCallback\<void>)|Starts an ability with start options.|
|void startAbilityWithAccount(want: Want, accountId: number, callback: AsyncCallback\<void>)|Starts an ability with the account ID.|
|void startAbilityWithAccount(want: Want, accountId: number, options: StartOptions, callback: AsyncCallback\<void>)|Starts an ability with the account ID and start options.|
|void startAbilityForResult(want: Want, callback: AsyncCallback\<AbilityResult>)|Starts an ability with the returned result.|
|void startAbilityForResult(want: Want, options: StartOptions, callback: AsyncCallback\<AbilityResult>)|Starts an ability with the returned result and start options.|
|void startAbilityForResultWithAccount(want: Want, accountId: number, callback: AsyncCallback\<AbilityResult>)|Starts an ability with the returned result and account ID.|
|void startAbilityForResultWithAccount(want: Want, accountId: number, options: StartOptions, callback: AsyncCallback\<void>)|Starts an ability with the returned result, account ID, and start options.|
|void terminateSelf(callback: AsyncCallback\<void>)|Destroys the Page ability.|
|void terminateSelfWithResult(parameter: AbilityResult, callback: AsyncCallback\<void>)|Destroys the Page ability with the returned result.|

## How to Develop
### Creating Page Abilities for an Application
To create Page abilities for an application on the stage model, you must implement the **AbilityStage** class and ability lifecycle callbacks, and use the **Window** APIs to set the pages. The sample code is as follows:
1. Import the **AbilityStage** module.
   ```
   import AbilityStage from "@ohos.application.AbilityStage"
   ```
2. Implement the **AbilityStage** class.
   ```ts
   export default class MyAbilityStage extends AbilityStage {
    onCreate() {
        console.log("MyAbilityStage onCreate")
    }
   }
   ```
3. Import the **Ability** module.
   ```js
   import Ability from '@ohos.application.Ability'
   ```
4. Implement the lifecycle callbacks of the **Ability** class.

   In the **onWindowStageCreate(windowStage)** API, use **loadContent** to set the pages to be loaded by the application. For details about how to use the **Window** APIs, see [Window Development](../windowmanager/window-guidelines.md).
   ```ts
   export default class MainAbility extends Ability {
    onCreate(want, launchParam) {
        console.log("MainAbility onCreate")
    }
   
    onDestroy() {
        console.log("MainAbility onDestroy")
    }
   
    onWindowStageCreate(windowStage) {
        console.log("MainAbility onWindowStageCreate")
   
        windowStage.loadContent("pages/index").then((data) => {
            console.log("MainAbility load content succeed with data: " + JSON.stringify(data))
        }).catch((error) => {
            console.error("MainAbility load content failed with error: "+ JSON.stringify(error))
        })
    }
   
    onWindowStageDestroy() {
        console.log("MainAbility onWindowStageDestroy")
    }
   
    onForeground() {
        console.log("MainAbility onForeground")
    }
   
    onBackground() {
        console.log("MainAbility onBackground")
    }
   }
   ```
### Obtaining AbilityStage and Ability Configuration Information
Both the **AbilityStage** and **Ability** classes have the **context** attribute. An application can obtain the context of the **Ability** instance through **this.context** to obtain detailed configuration information. The following example shows how the ability stage obtains the bundle code directory, HAP file name, ability name, and system language through the **context** attribute. The sample code is as follows:
```ts
import AbilityStage from "@ohos.application.AbilityStage"
export default class MyAbilityStage extends AbilityStage {
    onCreate() {
        console.log("MyAbilityStage onCreate")
        let context = this.context
        console.log("MyAbilityStage bundleCodeDir" + context.bundleCodeDir)

        let currentHapModuleInfo = context.currentHapModuleInfo
        console.log("MyAbilityStage hap module name" + currentHapModuleInfo.name)
        console.log("MyAbilityStage hap module mainAbilityName" + currentHapModuleInfo.mainAbilityName)

        let config = this.context.config
        console.log("MyAbilityStage config language" + config.language)
    }
}
```

The following example shows how the ability obtains the bundle code directory, HAP file name, ability name, and system language through the **context** attribute. The sample code is as follows:
```ts
import Ability from '@ohos.application.Ability'
export default class MainAbility extends Ability {
    onCreate(want, launchParam) {
        console.log("MainAbility onCreate")
        let context = this.context
        console.log("MainAbility bundleCodeDir" + context.bundleCodeDir)

        let abilityInfo = this.context.abilityInfo;
        console.log("MainAbility ability bundleName" + abilityInfo.bundleName)
        console.log("MainAbility ability name" + abilityInfo.name)

        let config = this.context.config
        console.log("MyAbilityStage config language" + config.language)
    }
}
```

### Starting an Ability
An application can obtain the context of an **Ability** instance through **this.context** and then use the **StartAbility** API in the **AbilityContext** class to start the ability. The ability can be started by specifying **Want**, **StartOptions**, and **accountId**, and the operation result can be returned using a callback or **Promise** instance. The sample code is as follows:
```ts
let context = this.context
var want = {
    "deviceId": "",
    "bundleName": "com.example.MyApplication",
    "abilityName": "MainAbility"
};
var options = {
    windowMode: 0,
    displayId: 2
};
context.startAbility(want, options).then((data) => {
    console.log("Succeed to start ability with data: " + JSON.stringify(data))
}).catch((error) => {
    console.error("Failed to start ability with error: "+ JSON.stringify(error))
})
```

### Starting an Ability on a Remote Device (Available only to System Applications)
>Note: The **getTrustedDeviceListSync** API of the **DeviceManager** class is open only to system applications. Therefore, cross-device ability startup applies only to system applications.
In the cross-device scenario, you must specify the ID of the remote device. The sample code is as follows:
```ts
let context = this.context
var want = {
    "deviceId": getRemoteDeviceId(),
    "bundleName": "com.example.MyApplication",
    "abilityName": "MainAbility"
};
context.startAbility(want).then((data) => {
    console.log("Succeed to start remote ability with data: " + JSON.stringify(data))
}).catch((error) => {
    console.error("Failed to start remote ability with error: "+ JSON.stringify(error))
})
```
Obtain the ID of a specified device from **DeviceManager**. The sample code is as follows:
```ts
import deviceManager from '@ohos.distributedHardware.deviceManager';
function getRemoteDeviceId() {
    if (typeof dmClass === 'object' && dmClass != null) {
        var list = dmClass.getTrustedDeviceListSync();
        if (typeof (list) == 'undefined' || typeof (list.length) == 'undefined') {
            console.log("MainAbility onButtonClick getRemoteDeviceId err: list is null");
            return;
        }
        console.log("MainAbility onButtonClick getRemoteDeviceId success:" + list[0].deviceId);
        return list[0].deviceId;
    } else {
        console.log("MainAbility onButtonClick getRemoteDeviceId err: dmClass is null");
    }
}
```

### Requesting Permissions
If an application requires certain permissions, such as storage, location information, and log access, the application must request the permissions from end users. After determining the required permissions, add the permissions in the **module.json** file and use **requestPermissionsFromUser** to request the permissions from end users in the form of a dialog box. The following uses the permissions for calendar access as an example.
Modify the **module.json** file as follows:
```json
"requestPermissions": [
    {
    "name": "ohos.permission.READ_CALENDAR"
    }
]
```
Request the permissions from end users in the form of a dialog box:
```ts
let context = this.context
let permissions: Array<string> = ['ohos.permission.READ_CALENDAR']
context.requestPermissionsFromUser(permissions).then((data) => {
    console.log("Succeed to request permission from user with data: "+ JSON.stringify(data))
}).catch((error) => {
    console.log("Failed to request permission from user with error: "+ JSON.stringify(error))
})
```
In the cross-device scenario, the application must also apply for the data synchronization permission from end users. The sample code is as follows:
```ts
let context = this.context
let permissions: Array<string> = ['ohos.permission.DISTRIBUTED_DATASYNC']
context.requestPermissionsFromUser(permissions).then((data) => {
    console.log("Succeed to request permission from user with data: "+ JSON.stringify(data))
}).catch((error) => {
    console.log("Failed to request permission from user with error: "+ JSON.stringify(error))
})
```

### Notifying of Environment Configuration Changes
When the global configuration, for example, system language and color mode, changes, the **onConfigurationUpdated** API is called to notify the ability stage and ability. System applications can update the system language and color mode through the **updateConfiguration** API. The following example shows the implement of the **onConfigurationUpdated** callback in the **AbilityStage** class. The callback is triggered when the system language and color mode change. The sample code is as follows:
```ts
import Ability from '@ohos.application.Ability'
import ConfigurationConstant from '@ohos.application.ConfigurationConstant'
export default class MyAbilityStage extends AbilityStage {
    onConfigurationUpdated(config) {
        console.log("MyAbilityStage onConfigurationUpdated")
        console.log("MyAbilityStage config language" + config.language)
        console.log("MyAbilityStage config colorMode" + config.colorMode)
    }
}
```

The following example shows the implement of the **onConfigurationUpdated** callback in the **Ability** class. The callback is triggered when the system language, color mode, and display parameters (such as the direction and density) change. The sample code is as follows:
```ts
import Ability from '@ohos.application.Ability'
import ConfigurationConstant from '@ohos.application.ConfigurationConstant'
export default class MainAbility extends Ability { {
    onConfigurationUpdated(config) {
        console.log("MainAbility onConfigurationUpdated")
        console.log("MainAbility config language" + config.language)
        console.log("MainAbility config colorMode" + config.colorMode)
        console.log("MainAbility config direction" + config.direction)
        console.log("MainAbility config screenDensity" + config.screenDensity)
        console.log("MainAbility config displayId" + config.displayId)
    }
}
```

## Samples
The following sample is provided to help you better understand how to develop an ability on the stage model:
- [`StageCallAbility`: Stage Ability Creation and Usage (eTS) (API9)](https://gitee.com/openharmony/app_samples/tree/master/ability/StageCallAbility)
