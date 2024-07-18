# Using startAbilityByType to Start Vertical Applications
## When to Use
You can call the **startAbilityByType** API to start a vertical domain panel based on a specific business category, such as navigation, finance, and email. The panel displays all the vertical applications available on the device, and users can choose to open one of them. The vertical domain panel provides secure and trusted applications available on the device, while reducing the access cost of the caller.

![](./figures/process-start-intent-panel.png)

## Available APIs

The **startAbilityByType<sup>11+</sup>** API is available in the [UIAbilityContext](../reference/apis-ability-kit/js-apis-inner-application-uiAbilityContext.md#uiabilitycontextstartabilitybytype11) and [UIExtensionContentSession](../reference/apis-ability-kit/js-apis-app-ability-uiExtensionContentSession.md#uiextensioncontentsessionstartabilitybytype11) classes. It provides the capability of starting a vertical domain panel based on the business category specified by the caller. The vertical applications available on the device are displayed on the panel.

### Parameters on the Navigation Application Panel

If the **type** field in **startAbilityByType** is set to **navigation**, **wantParam** contains the following properties.

| Property Name            | Description                                                        | Data Type| Mandatory|
| -------------------- | ------------------------------------------------------------ | -------- | -------- |
| destinationLatitude  | Latitude of the destination.                                                   | number   | Mandatory when **sceneType** is set to **1** or **2**.|
| destinationLongitude | Longitude of the destination.                                                    | number   | Mandatory when **sceneType** is set to **1** or **2**.|
| sceneType            | Scene type. The options are as follows: 1: route planning; 2: navigation; 3: place search.                               | number   | No. When this parameter is left unspecified, the default value **1** is used.  |
| destinationName      | Name of the destination.                                                    | string   | Mandatory when **sceneType** is set to **3**.  |
| originName           | Name of the source. It is valid in route planning scenarios.                                  | string   | No  |
| originLatitude       | Latitude of the source. It is valid in route planning scenarios.                                  | number   | No  |
| originLongitude      | Longitude of the source. It is valid in route planning scenarios.                                  | number   | No  |
| vehicleType          | Transportation mode. The options are as follows: 0: driving; 1: walking; 2: cycling; 3: public transportation. It is valid in route planning scenarios.| number   | No. When this parameter is left unspecified, the processing is determined by the application.  |

> **NOTE**
> 
> The GCJ-02 coordinate system is used for the longitude and latitude in this document.

### Parameters on the Email Application Panel

If the **type** field in **startAbilityByType** is set to **mail**, **wantParam** contains the following properties.

| Property Name                             | Description                                  | Data Type| Mandatory                  |
| ------------------------------------- | -------------------------------------- | -------- | -------------------------- |
| email                                 | Email address of the recipient. Multiple email addresses, separated by commas (,), are supported.| string[ ] | No                        |
| cc                                    | Email address of the CC recipient. Multiple email addresses, separated by commas (,), are supported.| string[ ] | No                        |
| bcc                                   | Email address of the BCC recipient. Multiple email addresses, separated by commas (,), are supported.| string[ ] | No                        |
| subject                               | Email subject.                              | string   | No                        |
| body                                  | Email body.                              | string   | No                        |
| ability.params.stream                 | Email attachments (URI list of the attachments).         | string[ ] | No                        |
| ability.want.params.uriPermissionFlag | At least the read permission must be granted on the email attachments.              | number   | Mandatory when an email attachment exists.|
| sceneType                             | 1: Send an email.                  | number   | Yes                        |

> **NOTE**
>
> The content of the string or string[] type in the extended panel of the email application needs to be URL encoded. After receiving these parameters, the receiver needs to decode the URL.

## Displaying the Navigation Application Panel

### For the Caller Application

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
      'originName': 'xx Park in xx City',
      'originLatitude': 31.060844,
      'originLongitude': 120.78315,
      'vehicleType': 0
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
    ```
    **Effect**
    
    ![Example effect](./figures/start-navigation-panel.png)

### For the Target Application

1. Add the [linkFeature](../quick-start/module-configuration-file.md#skills) attribute to **module.json5** and declare the features supported. In this way, the system can find the applications that support a specific feature from all the applications installed on the device.

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
    ~~~

2. Parse parameters and perform corresponding processing.

    ```ts
    UIAbility::onCreate(want: Want, launchParam: AbilityConstant.LaunchParam): void
    ```

    The **want.parameters** parameter contains the following parameters, which may be slightly different from the ones passed in by the caller.

    | Property Name            | Description                                                        | Data Type| Mandatory|
    | -------------------- | ------------------------------------------------------------ | -------- | -------- |
    | destinationLatitude  | Latitude of the destination.                                                    | number   | Mandatory when **sceneType** is set to **1** or **2**.|
    | destinationLongitude | Longitude of the destination.                                                    | number   | Mandatory when **sceneType** is set to **1** or **2**.|
    | destinationName      | Name of the destination.                                                    | string   | Mandatory when **sceneType** is set to **3**.  |
    | originName           | Name of the source.                                  | string   | No. When this parameter is specified, it can be used to display a route planning page.  |
    | originLatitude       | Latitude of the source.                                | number   | No. When this parameter is specified, it can be used to display a route planning page.  |
    | originLongitude      | Longitude of the source.                                 | number   | No. When this parameter is specified, it can be used to display a route planning page.  |
    | vehicleType          | Transportation mode. The options are as follows: 0: driving; 1: walking; 2: cycling; 3: public transportation. It is valid in route planning scenarios.| number   | No. When this parameter is left unspecified, the processing is determined by the application.  |

    The application can develop different style pages based on the features defined in [linkFeature](../quick-start/module-configuration-file.md#skills), such as route planning and navigation, as well as the received parameters.

**Sample Code**

```ts
import { AbilityConstant, UIAbility, Want } from '@kit.AbilityKit';
import { hilog } from '@kit.PerformanceAnalysisKit';
import { window } from '@kit.ArkUI';

let destinationLatitude: number;
let destinationLongitude: number;
let originLatitude: number | undefined;
let originLongitude: number | undefined;

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
    } as Record<string, number>);

    if (originLatitude !== undefined && originLongitude !== undefined) {
      windowStage.loadContent('pages/IndexForNavigation', storage);
    } else {
      windowStage.loadContent('pages/IndexForRoutePlan', storage);
    }
  }
}
```
## Displaying the Email Application Panel

### For the Caller Application
1. Import the **ohos.app.ability.common** module.
    ```ts
    import { common } from '@kit.AbilityKit';
    ```
2. Construct parameters and call the **startAbilityByType** API.

    ```ts
    let context = getContext(this) as common.UIAbilityContext;
    let wantParam: Record<string, Object> = {
      'sceneType': 1,
      'email': [encodeURI('xxx@example.com'),encodeURI('xxx@example.com')], // Email address of the recipient. Multiple values are separated by commas (,). The array content is URL encoded using encodeURI().
      'cc': [encodeURI('xxx@example.com'),encodeURI('xxx@example.com')], // Email address of the CC recipient. Multiple values are separated by commas (,). The array content is URL encoded using encodeURI().
      'bcc': [encodeURI('xxx@example.com'),encodeURI('xxx@example.com')], // Email address of the BCC recipient. Multiple values are separated by commas (,). The array content is URL encoded using encodeURI().
      'subject': encodeURI('Email subject'), // Email subject. The content is URL encoded using encodeURI().
      'body': encodeURI('Email body'), // Email body. The content is URL encoded using encodeURI().
      'ability.params.stream':[encodeURI('attachment uri1'),encodeURI('attachment uri2')], // Attachment URIs. Multiple values are separated by commas (,). The array content is URL encoded using encodeURI().
      'ability.want.params.uriPermissionFlag': 1
    };
    let abilityStartCallback: common.AbilityStartCallback = {
      onError: (code: number, name: string, message: string) => {
        console.log(`code:` + code + `name:` + name + `message:` + message);
      }
    }
    
    context.startAbilityByType("mail", wantParam, abilityStartCallback, (err) => {
    if (err) {
        console.error(`startAbilityByType fail, err: ${JSON.stringify(err)}`);
      } else {
        console.log(`success`);
      }
    });
    ```
    **Effect**
    
    ![Example effect](./figures/start-mail-panel.png)

### For the Target Application
1. Add the [linkFeature](../quick-start/module-configuration-file.md#skills) attribute to **module.json5** and declare the features supported. In this way, the system can find the applications that support a specific feature from all the applications installed on the device.

    ~~~json
    {
    "abilities": [
        {
        "skills": [
            {
            "uris": [
                {
                "scheme": "mail", // It is for reference only. Ensure that the declared URI can be started by external systems.
                "host": "mail",
                "path": "",
                "linkFeature": "ComposeMail" // Declare that the application supports email writing.
                }
            ]
            }
        ]
        }
    ]
    }
    ~~~
    
2. Parse and process the parameters transferred from the panel.

    ```ts
    UIAbility::onCreate(want: Want, launchParam: AbilityConstant.LaunchParam): void
    ```

    The **want.parameters** parameter contains the following parameters, which may be slightly different from the ones passed in by the caller.

    | Property Name            | Description                                                        | Data Type| Mandatory|
    | -------------------- | ------------------------------------------------------------ | -------- | -------- |
    | email  | Email address of the recipient. Multiple email addresses, separated by commas (,), are supported.                                 | string[ ] | No|
    | cc | Email address of the CC recipient. Multiple email addresses, separated by commas (,), are supported.                                 | string[ ] | No|
    | bcc    | Email address of the BCC recipient. Multiple email addresses, separated by commas (,), are supported.                                 | string[ ] | No |
    | subject    | Email subject.                              | string   | No |
    | body   | Email body.                            | string | No |
    | stream | Email attachments (URI list of the attachments).                 | string[ ] | No |
    
    The application can develop different style pages based on the features defined in [linkFeature](../quick-start/module-configuration-file.md#skills), such as writing an email, as well as the received parameters.

**Sample Code**

```ts
import { AbilityConstant, UIAbility, Want } from '@kit.AbilityKit';
import { window } from '@kit.ArkUI';

let email: string[] | undefined;
let cc: string[] | undefined;
let bcc: string[] | undefined;
let subject: string | undefined;
let body: string | undefined;
let stream: string[] | undefined;

export default class EntryAbility extends UIAbility {
  onCreate(want: Want, launchParam: AbilityConstant.LaunchParam) {
    subject = decodeURI(want.parameters? .subject as string); // Use decodeURI() to decode the URL of the email subject. Other fields are processed in the same way.
	body = decodeURI(want.parameters?.body as string); // Use decodeURI() to decode the URL of the email body. Other fields are processed in the same way.
  }

  onWindowStageCreate(windowStage: window.WindowStage) {
    const storage: LocalStorage = new LocalStorage({
      "subject": subject,
      "body": body
    } as Record<string, Object>);

    windowStage.loadContent('pages/IndexForMail', storage);
  }
}
```
