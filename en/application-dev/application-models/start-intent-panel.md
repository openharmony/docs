# Using startAbilityByType to Start Vertical Applications
## When to Use
You can call the **startAbilityByType** API to start a vertical domain panel based on a specific business category, such as navigation and finance. The panel displays all the vertical applications available on the device, and the user can choose to open one of them. The vertical domain panel provides secure and trusted applications available on the device, while reducing the access cost of the caller.

![](./figures/process-start-intent-panel.png)

## Constraints
Devices running HarmonyOS NEXT Developer Preview0 or later
## Available APIs
The **startAbilityByType<sup>11+</sup>** API is available in the [UIAbilityContext](../reference/apis-ability-kit/js-apis-inner-application-uiAbilityContext.md#uiabilitycontextstartabilitybytype11) and [UIExtensionContentSession](../reference/apis-ability-kit/js-apis-app-ability-uiExtensionContentSession.md#uiextensioncontentsessionstartabilitybytype11) classes. It provides the capability of starting a vertical domain panel based on the business category specified by the caller. The vertical applications available on the device are displayed on the panel.

If **type** is set to **navigation**, **wantParam** contains the following properties:

| Property Name            | Description                                                        | Data Type| Can Left Unspecified|
| -------------------- | ------------------------------------------------------------ | -------- | -------- |
| destinationLatitude  | Latitude<sup>GCJ-02</sup> of the destination.                                                    | number   | This parameter cannot be left unspecified when **sceneType** is set to **1** or **2**.|
| destinationLongitude | Longitude<sup>GCJ-02</sup> of the destination.                                                    | number   | This parameter cannot be left unspecified when **sceneType** is set to **1** or **2**.|
| sceneType            | Scene type. The options are as follows: 1: route planning; 2: navigation; 3: place search.                               | number   | This parameter can be left unspecified. When it is left unspecified, the default value **1** is used.  |
| destinationName      | Name of the destination.                                                    | string   | This parameter cannot be left unspecified when **sceneType** is set to **3**.  |
| originName           | Name of the source. It is valid in route planning scenarios.                                  | string   | This parameter can be left unspecified.  |
| originLatitude       | Latitude<sup>GCJ-02</sup> of the source. It is valid in route planning scenarios.                                  | number   | This parameter can be left unspecified.  |
| originLongitude      | Longitude<sup>GCJ-02</sup> of the source. It is valid in route planning scenarios.                                  | number   | This parameter can be left unspecified.  |
| vehicleType          | Transportation mode. The options are as follows: 0: driving; 1: walking; 2: cycling; 3: public transportation. It is valid in route planning scenarios.| number   | This parameter can be left unspecified. When it is left unspecified, the processing is determined by the application.  |

## How to Develop
### For the Caller

1. Import the **ohos.app.ability.common** module.
    ```
    import common from '@ohos.app.ability.common';
    ```
2. Construct parameters and call the **startAbilityByType** API.

**Example**
  ~~~typescript
  import common from '@ohos.app.ability.common';
  let context = getContext(this) as common.UIAbilityContext;
  let wantParam: Record<string, Object> = {
      'sceneType':1,
      'destinationLatitude':32.060844,
      'destinationLongitude':118.78315,
      'destinationName':'No. xx, xx Road, xx City',
      'originName':'xx Park in xx City',
      'originLatitude':31.060844,
      'originLongitude':120.78315,
      'vehicleType':0
  };
  let abilityStartCallback: common.AbilityStartCallback = {
    onError: (code: number, name: string, message: string) => {
      console.log(`code:` + code + `name:` + name + `message:` + message);
    }
  }
  context.startAbilityByType("navigation", wantParam, abilityStartCallback, (err) => {
    if (err) {
      console.error(`startAbilityByType fail, err: ${JSON.stringify(err)}`);
    } else {
      console.log(`success`);
    }
  });
  
  ~~~
**Effect**

![Effect example](./figures/start-navigation-panel.png)

### For a Target Application

1. Import the **ohos.app.ability.UIAbility** module.
    ~~~typescript
    import UIAbility from '@ohos.app.ability.UIAbility';
    ~~~
2. Add the [linkFeature](../quick-start/module-configuration-file.md#skills) attribute to **module.json5** and declare the features supported. In this way, the system can find the applications that support a specific feature from all the applications installed on the device.

    Configuration example:

    ~~~json
    {
    "abilities": [
        {
        "skills": [
            {
            "uris": [
                {
                "scheme": "maps", // It is for reference only. Ensure that the declared URI can be started by external systems.
                "host": "navigation",
                "path": "",
                "linkFeature": "navigation" // Declare that the application supports navigation.
                },
                {
                "scheme": "maps", // It is for reference only. Ensure that the declared URI can be started by external systems.
                "host": "routePlan",
                "path": "",
                "linkFeature": "routePlan" // Declare that the application supports route planning.
                },
                {
                "scheme": "maps", // It is for reference only. Ensure that the declared URI can be started by external systems.
                "host": "search",
                "path": "",
                "linkFeature": "textSearch" // Declare that the application supports place search.
                }
            ]
            }
        ]
        }
    ]
    }
    ~~~

3. Parse parameters and perform corresponding processing.

    ~~~typescript
    UIAbility::onCreate(want: Want, launchParam: AbilityConstant.LaunchParam): void
    ~~~

    The **want.parameters** parameter contains the following parameters, which may be slightly different from the ones passed in by the caller.

    | Property Name            | Description                                                        | Data Type| Can Left Unspecified|
    | -------------------- | ------------------------------------------------------------ | -------- | -------- |
    | destinationLatitude  | Latitude<sup>GCJ-02</sup> of the destination.                                                    | number   | This parameter cannot be left unspecified when **sceneType** is set to **1** or **2**.|
    | destinationLongitude | Longitude<sup>GCJ-02</sup> of the destination.                                                    | number   | This parameter cannot be left unspecified when **sceneType** is set to **1** or **2**.|
    | destinationName      | Name of the destination.                                                    | string   | This parameter cannot be left unspecified when **sceneType** is set to **3**.  |
    | originName           | Name of the source.                                  | string   | This parameter can be left unspecified. If it is specified, it can be used to display a route planning page.  |
    | originLatitude       | Latitude<sup>GCJ-02</sup> of the source.                                | number   | This parameter can be left unspecified. If it is specified, it can be used to display a route planning page.  |
    | originLongitude      | Longitude<sup>GCJ-02</sup> of the source.                                 | number   | This parameter can be left unspecified. If it is specified, it can be used to display a route planning page.  |
    | vehicleType          | Transportation mode. The options are as follows: 0: driving; 1: walking; 2: cycling; 3: public transportation. It is valid in route planning scenarios.| number   | This parameter can be left unspecified. When it is left unspecified, the processing is determined by the application.  |

    The application can develop different style pages based on the features defined in [linkFeature](../quick-start/module-configuration-file.md#skills), such as route planning and navigation, and received parameters.

**Example**

```
import AbilityConstant from '@ohos.app.ability.AbilityConstant';
import hilog from '@ohos.hilog';
import UIAbility from '@ohos.app.ability.UIAbility';
import Want from '@ohos.app.ability.Want';
import window from '@ohos.window';

let destinationLatitude:number;
let destinationLongitude:number;
let originLatitude:number | undefined;
let originLongitude:number | undefined;

export default class EntryAbility extends UIAbility {
    onCreate(want: Want, launchParam: AbilityConstant.LaunchParam) {
        hilog.info(0x0000, 'testTag', '%{public}s', 'Ability onCreate');
        
        destinationLatitude = want.parameters?.destinationLatitude as number;
        destinationLongitude = want.parameters?.destinationLongitude as number;
        originLatitude = want.parameters?.originLatitude as number | undefined;
        originLongitude = want.parameters?.originLongitude as number | undefined;
    }

    onWindowStageCreate(windowStage: window.WindowStage) {
        hilog.info(0x0000, 'testTag', '%{public}s', `Ability onWindowStageCreate: ${JSON.stringify(this.context)}`);

        const storage: LocalStorage = new LocalStorage({
            "destinationLatitude": destinationLatitude,
            "destinationLongitude": destinationLongitude,
            "originLatitude": originLatitude,
            "originLongitude": originLongitude
        } as Record<string, object>);
        
        if(originLatitude !== undefined && originLongitude !== undefined) {
            windowStage.loadContent('pages/IndexForNavigation', storage);
        } else {
            windowStage.loadContent('pages/IndexForRoutePlan', storage);
        }
    }
}

```
