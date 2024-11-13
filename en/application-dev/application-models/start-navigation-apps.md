# Starting a Navigation Application


This topic describes how to open the vertical domain panel of navigation applications.


## Parameters on the Navigation Application Panel

If the **type** field in **startAbilityByType** is set to **navigation**, **wantParam** contains the following properties.

| Name            | Description                                                        | Data Type| Mandatory|
| -------------------- | ------------------------------------------------------------ | -------- | -------- |
| destinationLatitude  | Latitude of the destination.                                                   | number   | Mandatory when **sceneType** is set to **1** or **2**.|
| destinationLongitude | Longitude of the destination.                                                    | number   | Mandatory when **sceneType** is set to **1** or **2**.|
| sceneType            | Scene type. The options are as follows: 1: route planning; 2: navigation; 3: place search.                               | number   | No. When this parameter is left unspecified, the default value **1** is used.  |
| destinationName      | Name of the destination.                                                    | string   | Mandatory when **sceneType** is set to **3**.  |
| destinationPoiIds      | List of POI IDs of the destination. It is valid in route planning or navigation scenarios.                                                      | Record<number, string>   | No  |
| originName           | Name of the source. It is valid in route planning scenarios.                                  | string   | No  |
| originLatitude       | Latitude of the source. It is valid in route planning scenarios.                                  | number   | No  |
| originLongitude      | Longitude of the source. It is valid in route planning scenarios.                                  | number   | No  |
| originPoiIds      | List of POI IDs of the source. It is valid in route planning or navigation scenarios.                                                     | Record<number, string>   | No  |
| vehicleType          | Transportation mode. The options are as follows: 0: driving; 1: walking; 2: cycling; 3: public transportation. It is valid in route planning scenarios.| number   | No. When this parameter is left unspecified, the processing is determined by the application.  |

> **NOTE**
> 
> * The GCJ-02 coordinate system is used for the longitude and latitude in this document.
> 
> * You need to obtain the destination POI IDs and source POI IDs from each map system and transfer parameters based on the following mappings.

```ts
let wantParam: Record<string, Object> = {
      // Other parameters
      ...,
      'destinationPoiIds': {
          1:'1111', // Key 1 indicates Petal Maps, and the value must be a POI in Petal Maps.
          2:'2222' // Key 2 indicates AutoNavi Map, and the value must be a POI in AutoNavi Map.
      } as Record<number, string>,
      'originPoiIds': {
          1: '3333',  // Key 1 indicates Petal Maps, and the value must be a POI in Petal Maps.
          2: '4444'   // Key 2 indicates AutoNavi Map, and the value must be a POI in AutoNavi Map.
      } as Record<number, string>
    };
```

## Developing a Caller Application

1. Import the **ohos.app.ability.common** module.
    ```ts
    import { common } from '@kit.AbilityKit';
    ```
2. Construct parameters and call the **startAbilityByType** API.

    ```ts
    let context = getContext(this) as common.UIAbilityContext;
    let wantParam: Record<string, Object> = {
      'sceneType': 1,
      'destinationLatitude': 32.060844,
      'destinationLongitude': 118.78315,
      'destinationName': 'No.xx, xx Road, xx City',
      'destinationPoiIds': {
          1: "111111111111",
          2: "222222222222"
      } as Record<number, string>,
      'originName': 'xx Park in xx City',
      'originLatitude': 31.060844,
      'originLongitude': 120.78315,
      'originPoiIds': {
          1: "333333333333",  
          2: "444444444444"
      } as Record<number, string>,
      'vehicleType': 0
    };
    let abilityStartCallback: common.AbilityStartCallback = {
      onError: (code: number, name: string, message: string) => {
        console.log(`onError code ${code} name: ${name} message: ${message}`);
      },
      onResult: (result)=>{
        console.log(`onResult result: ${JSON.stringify(result)}`);
      }
    }
    
    context.startAbilityByType("navigation", wantParam, abilityStartCallback, 
        (err) => {
            if (err) {
                console.error(`startAbilityByType fail, err: ${JSON.stringify(err)}`);
            } else {
                console.log(`success`);
            }
    });
    ```
    Effect

    ![Effect example](./figures/start-navigation-panel.png)

## Developing a Target Application

1. Configure [uris](../quick-start/module-configuration-file.md#skills) in the **module.json5** file.
    1. Set the **linkFeature** field to declare the features supported by the application so that the system can match the application against all the installed applications on the device. The options are as follows:
        | Value          | Description                        |
        | -------------- | ---------------------------- |
        | Navigation     | The application supports navigation.		|
        | RoutePlan      | The application supports route planning.	|
        | PlaceSearch    | The application supports place search.    |
    2. Set **scheme**, **host**, **port**, and **path** or **pathStartWith** to match the URIs in Want to distinguish different features.
    ```json
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
                  "linkFeature": "Navigation" // Declare that the application supports navigation.
                  },
                  {
                  "scheme": "maps", // It is for reference only. Ensure that the declared URI can be started by external systems.
                  "host": "routePlan",
                  "path": "",
                  "linkFeature": "RoutePlan" // Declare that the application supports route planning.
                  },
                  {
                  "scheme": "maps", // It is for reference only. Ensure that the declared URI can be started by external systems.
                  "host": "search",
                  "path": "",
                  "linkFeature": "PlaceSearch" // Declare that the application supports place search.
                  }
              ]
              }
          ]
          }
      ]
    }
    ```

2. Parse parameters and perform corresponding processing.

    ```ts
    UIAbility::onCreate(want: Want, launchParam: AbilityConstant.LaunchParam): void
    ```

    The **want.uri** parameter carries the URI corresponding to **linkFeature** configured by the target application.

    The **want.parameters** parameter contains the following parameters, which may be slightly different from the ones passed in by the caller.

    | Name            | Description                                                        | Data Type| Mandatory|
    | -------------------- | ------------------------------------------------------------ | -------- | -------- |
    | destinationLatitude  | Latitude of the destination.                                                    | number   | Mandatory in the route planning or navigation scenario.|
    | destinationLongitude | Longitude of the destination.                                                    | number   | Mandatory in the route planning or navigation scenario.|
    | destinationName      | Name of the destination.                                                    | string   | Mandatory in the place search scenario.  |
    | destinationPoiId      | POI ID of the destination.                                                    | string   | No. When this parameter is specified, it can be used to display a route planning or navigation page.  |
    | originName           | Name of the source.                                  | string   | No. When this parameter is specified, it can be used to display a route planning page.  |
    | originLatitude       | Latitude of the source.                                | number   | No. When this parameter is specified, it can be used to display a route planning page.  |
    | originLongitude      | Longitude of the source.                                 | number   | No. When this parameter is specified, it can be used to display a route planning page.  |
    | originPoiId      | POI ID of the source.                                                    | string   | No. When this parameter is specified, it can be used to display a route planning page.  |
    | vehicleType          | Transportation mode. The options are as follows: 0: driving; 1: walking; 2: cycling; 3: public transportation. It is valid in route planning scenarios.| number   | No. When this parameter is left unspecified, the processing is determined by the application.  |

    The application can develop different style pages based on the features defined in [linkFeature](../quick-start/module-configuration-file.md#skills), such as route planning, navigation, and place search, as well as the received URI.

**Sample Code**

```ts
import { AbilityConstant, UIAbility, Want } from '@kit.AbilityKit';
import { hilog } from '@kit.PerformanceAnalysisKit';
import { window } from '@kit.ArkUI';

const TAG = 'EntryAbility'

export default class EntryAbility extends UIAbility {
    windowStage: window.WindowStage | null = null;

    uri?: string;
    destinationLatitude?: number;
    destinationLongitude?: number;
    destinationName?: string;
    originName?: string;
    originLatitude?: number;
    originLongitude?: number;
    vehicleType?: number;
    destinationPoiId?: string;
    originPoiId?: string;

    onCreate(want: Want, launchParam: AbilityConstant.LaunchParam): void {
        hilog.info(0x0000, TAG, `onCreate, want=${JSON.stringify(want)}`);
        super.onCreate(want, launchParam);
        this.parseWant(want);
    }

    onNewWant(want: Want, launchParam: AbilityConstant.LaunchParam): void {
        hilog.info(0x0000, TAG, `onNewWant, want=${JSON.stringify(want)}`);
        super.onNewWant(want, launchParam);
        this.parseWant(want);
        if (!this.windowStage) {
            hilog.error(0x0000, TAG, 'windowStage is null');
            this.context.terminateSelf();
            return;
        }
        this.loadPage(this.windowStage);
    }

    private parseWant(want: Want): void {
        this.uri = want.uri as string | undefined;
        this.destinationLatitude = want.parameters?.destinationLatitude as number | undefined;
        this.destinationLongitude = want.parameters?.destinationLongitude as number | undefined;
        this.destinationName = want.parameters?.destinationName as string | undefined;
        this.originName = want.parameters?.originName as string | undefined;
        this.originLatitude = want.parameters?.originLatitude as number | undefined;
        this.originLongitude = want.parameters?.originLongitude as number | undefined;
        this.vehicleType = want.parameters?.vehicleType as number | undefined;
        this.destinationPoiId = want.parameters?.destinationPoiId as string | undefined;
        this.originPoiId = want.parameters?.originPoiId as string | undefined;
    }

    private loadPage(windowStage: window.WindowStage): void {
        hilog.info(0x0000, TAG, `loadPage, uri=${this.uri}`);
        if (this.uri === 'maps://navigation') {
            // Construct parameters for the navigation scenario.
            const storage: LocalStorage = new LocalStorage({
                "destinationLatitude": this.destinationLatitude,
                "destinationLongitude": this.destinationLongitude,
                "destinationPoiId": this.destinationPoiId
            } as Record<string, Object>);
            // Open the navigation page.
            windowStage.loadContent('pages/NavigationPage', storage)
        } else if (this.uri === 'maps://routePlan') {
            // Construct parameters for the path planning scenario.
            const storage: LocalStorage = new LocalStorage({
                "destinationLatitude": this.destinationLatitude,
                "destinationLongitude": this.destinationLongitude,
                "destinationName": this.destinationName,
                "originName": this.originName,
                "originLatitude": this.originLatitude,
                "originLongitude": this.originLongitude,
                "vehicleType": this.vehicleType,
                "destinationPoiId": this.destinationPoiId,
                "originPoiId": this.originPoiId
            } as Record<string, Object>);
            // Open the route planning page.
            windowStage.loadContent('pages/RoutePlanPage', storage)
        }  else if (this.uri === 'maps://search') {
            // Construct parameters for the place search scenario.
            const storage: LocalStorage = new LocalStorage({
                "destinationName": this.destinationName
            } as Record<string, Object>);
            // Open the place search page.
            windowStage.loadContent('pages/PlaceSearchPage', storage)
        } else {
            // Display the home page by default.
            windowStage.loadContent('pages/Index', (err) => {
                if (err.code) {
                    hilog.error(0x0000, TAG, 'Failed to load the content. Cause: %{public}s',
                        JSON.stringify(err) ?? '');
                    return;
                }
                hilog.info(0x0000, TAG, 'Succeeded in loading the content.');
            });
        }
    }

    onDestroy(): void {
        hilog.info(0x0000, TAG, `onDestroy`);
    }

    onWindowStageCreate(windowStage: window.WindowStage): void {
        hilog.info(0x0000, TAG, `onWindowStageCreate`);
        this.windowStage = windowStage;
        this.loadPage(this.windowStage);
    }

    onWindowStageDestroy(): void {
        hilog.info(0x0000, TAG, '%{public}s', 'Ability onWindowStageDestroy');
    }

    onForeground(): void {
        hilog.info(0x0000, TAG, '%{public}s', 'Ability onForeground');
    }

    onBackground(): void {
        hilog.info(0x0000, TAG, '%{public}s', 'Ability onBackground');
    }
}
```
