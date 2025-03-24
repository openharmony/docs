# Using startAbilityByType to Start a Flight Application

This topic describes how to open the vertical domain panel of flight applications.

For example, in a travel scheduling application, if a user inputs the flight number for an upcoming journey, the application can identify this flight number and provide a link to track the flight status. After the user touches the link, the application calls [UIAbilityContext.startAbilityByType](../reference/apis-ability-kit/js-apis-inner-application-uiAbilityContext.md#uiabilitycontextstartabilitybytype11) or [UIExtensionContentSession.startAbilityByType](../reference/apis-ability-kit/js-apis-app-ability-uiExtensionContentSession.md#uiextensioncontentsessionstartabilitybytype11) to open a panel. This panel displays all available applications on the device that support flight query, enabling the user to select and switch to the application that meets their needs.

## Parameters on the Flight Application Panel

If the **type** field in **startAbilityByType** is set to **flight**, two intent scenarios are supported: flight query by flight number and by origin and destination. The corresponding **wantParam** parameter contains the following properties.

- Flight query by flight number

    | Name       | Type  | Mandatory| Description                                                        |
    | ------------- | ------ | ---- | ------------------------------------------------------------ |
    | sceneType     | number | No  | Intent scene, which indicates the purpose of the current request. The default value is **1**. In scenarios of flight query by flight number, set it to **1** or leave it empty.                    |
    | flightNo      | string | Yes  | Flight number, which is a two-digit code of the airline company plus a dight.|
    | departureDate | string | No  | Flight departure date, in the format of YYYY-MM-DD.                                    |

- Flight query by origin and destination

    | Name              | Type                  | Mandatory| Description                                                    |
    | -------------------- | ---------------------- | ---- | -------------------------------------------------------- |
    | sceneType            | number                 | Yes  | Intent scene, which indicates the purpose of the current request. In scenarios of flight query by origin and destination, set it to **2**.                                       |
    | originLocation      | string                 | Yes  | Departure place.                                                |
    | destinationLocation  | string                  | Yes  | Destination.                                                |
    | departureDate | string                  | No  | Flight departure date, in the format of YYYY-MM-DD.                                                |


## Developing a Caller Application

1. Import the module.
    ```ts
    import { common } from '@kit.AbilityKit';
    ```
    
2. Construct parameters and call the **startAbilityByType** API.

    ```ts
    let context = getContext(this) as common.UIAbilityContext;
    let wantParam: Record<string, Object> = {
      'sceneType': 1,
      'flightNo': 'ZH1509',
      'departureDate': '2024-10-01'
    };
    let abilityStartCallback: common.AbilityStartCallback = {
      onError: (code: number, name: string, message: string) => {
        console.log(`onError code ${code} name: ${name} message: ${message}`);
      },
      onResult: (result)=>{
        console.log(`onResult result: ${JSON.stringify(result)}`);
      }
    }
    
    context.startAbilityByType("flight", wantParam, abilityStartCallback, 
        (err) => {
            if (err) {
                console.error(`startAbilityByType fail, err: ${JSON.stringify(err)}`);
            } else {
                console.log(`success`);
            }
    });
    ```
    Effect
    
    ![Effect example](./figures/start-flight-panel.png)

## Developing a Target Application

1. Configure [uris](../quick-start/module-configuration-file.md#skills) in the **module.json5** file.
    1. Set the **linkFeature** field to declare the features supported by the application so that the system can match the application against all the installed applications on the device. The options are as follows:
        | Value       | Description                    |
        | ----------- | ------------------------ |
        | QueryByFlightNo  | Declares that the application supports flight query by flight number.    |
        | QueryByLocation   | Declares that the application supports flight query by origin and destination.|
    2. Set **scheme**, **host**, **port**, and **path** or **pathStartWith** to match the URIs in Want to distinguish different features.
        ```json
        {
            "abilities": [
                {
                    "skills": [
                        {
                            "uris": [
                                {
                                    "scheme": "flight",
                                    "host": "queryByFlightNo",
                                    "path": "",
                                    "linkFeature": "QueryByFlightNo"
                                },
                                {
                                    "scheme": "flight",
                                    "host": "queryByLocation",
                                    "path": "",
                                    "linkFeature": "QueryByLocation"
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
    UIAbility.onCreate(want: Want, launchParam: AbilityConstant.LaunchParam): void
    ```

    The **want.uri** parameter carries the URI corresponding to **linkFeature** configured by the target application.

    **want.parameters** carries the parameters passed by the caller, which vary in different scenarios.

    - Flight query by flight number
    
        | Name              | Type  | Mandatory| Description                                                |
        | -------------------- | ------ | ---- | ---------------------------------------------------- |
        | flightNo           | string | Yes  | Flight number, which is a two-digit code of the airline company plus a dight.                                            |
        | departureDate       | string | No  | Flight departure date, in the format of YYYY-MM-DD. If this field is left blank, it indicates the current day.                                            |
    
    - Flight query by origin and destination
    
        | Name              | Type  | Mandatory| Description                                              |
        | -------------------- | ------ | ---- | -------------------------------------------------- |
        | originLocation      | string | Yes  | Departure place.                                          |
        | destinationLocation  | string  | Yes  | Destination.                                          |
        | departureDate | string  | No  | Flight departure date, in the format of YYYY-MM-DD. If this field is left blank, it indicates the current day.   |

    The application can develop different style pages based on the features defined in [linkFeature](../quick-start/module-configuration-file.md#skills), such as flight query by flight number or by origin and destination, as well as the received URI and parameters.

**Sample Code**

```ts
import { AbilityConstant, UIAbility, Want } from '@kit.AbilityKit';
import { hilog } from '@kit.PerformanceAnalysisKit';
import { window } from '@kit.ArkUI';

const TAG = 'EntryAbility'

export default class EntryAbility extends UIAbility {
    windowStage: window.WindowStage | null = null;

    uri?: string;
    flightNo?: string;
    departureDate?: string;
    originLocation?: string;
    destinationLocation?: string;

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
        this.flightNo = want.parameters?.flightNo as string | undefined;
        this.departureDate = want.parameters?.departureDate as string | undefined;
        this.originLocation = want.parameters?.originLocation as string | undefined;
        this.destinationLocation = want.parameters?.destinationLocation as string | undefined;
    }

    private loadPage(windowStage: window.WindowStage): void {
        hilog.info(0x0000, TAG, `loadPage, uri=${this.uri}`);
        if (this.uri === 'flight://queryByFlightNo') {
            // Construct parameters for scenarios of flight query by flight number.
            const storage: LocalStorage = new LocalStorage({
                "flightNo": this.flightNo,
                "departureDate": this.departureDate
            } as Record<string, Object>);
            // Display the page for querying flights by flight number.
            windowStage.loadContent('pages/QueryByFlightNoPage', storage)
        } else if (this.uri === 'flight://queryByLocation') {
            // Construct parameters for scenarios of flight query by origin and destination.
            const storage: LocalStorage = new LocalStorage({
                "originLocation": this.originLocation,
                "destinationLocation": this.destinationLocation,
                "departureDate": this.departureDate
            } as Record<string, Object>);
            // Display the page for querying flights by origin and destination.
            windowStage.loadContent('pages/QueryByLocationPage', storage)
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
