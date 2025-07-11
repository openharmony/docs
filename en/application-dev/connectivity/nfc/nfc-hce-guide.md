# HCE Development

## Introduction
Near Field Communication (NFC) is a short-range, high-frequency radio technology that operates at a frequency of 13.56 MHz, with a typical communication range of within 10 centimeters. Host Card Emulation (HCE) provides card emulation that does not depend on a secure element. It allows an application to emulate a card and communicate with an NFC card reader through the NFC service.

## When to Use
An application emulates a card and communicates with an NFC card reader through the NFC service. The device can communicate with an NFC card reader by using a started application (foreground mode) or without starting an application (background mode).
- HCE foreground card swiping<br>
In the foreground mode, the user has to start a specific application that communicates with the NFC card reader. Specifically, the user starts the application, opens the application page, and taps the device on the NFC card reader. In this case, the transaction data is distributed only to the foreground application. When the application switches to the background or exits, the foreground priority is also suspended.
- HCE background card swiping<br>
The user taps the device on an NFC card reader without starting any HCE application. Then, the device selects an HCE application based on the Applet ID (AID) provided by the NFC card reader, and completes the card swiping transaction. If multiple HCE applications are matched, an application selector will be displayed, listing all the available applications. In this case, the user needs to open the desired HCE application and tap the device on the NFC card reader again to trigger the card swiping transaction.

## Constraints
1. For security reasons, regardless of whether the HCE application performs card swiping in the foreground or background, the device does not support HCE card swiping operations when it is in the screen-off state.<br>
2. A device must be equipped with an NFC controller chip to support HCE card swiping capabilities. There are no constraints on whether it has an NFC secure element.<br>
3. An HCE application must declare the NFC card emulation permission. For specific details, see the sample code.<br>

## Available APIs

For details about the APIs and sample code, [NFC Card Emulation](../../reference/apis-connectivity-kit/js-apis-cardEmulation.md).

The following table describes the APIs for implementing HCE.

| API                            | Description                                                                      |
| ---------------------------------- | ------------------------------------------------------------------------------ |
| start(elementName: ElementName, aidList: string[]): void                   | Starts HCE, including enabling this application to run in the foreground preferentially and dynamically registering the AID list.                                                              |
| stop(elementName: ElementName): void  | Stops HCE, including canceling the subscription of APDU data, exiting this application from the foreground, and releasing the dynamically registered AID list.                                                    |
| on(type: 'hceCmd', callback: AsyncCallback\<number[]>): void                | Registers a callback to receive APDUs from the peer card reader.                                                    |
| transmit(response: number[]): Promise\<void>                  | Transmits APDU data to the peer card reader.|
| off(type: 'hceCmd', callback?: AsyncCallback\<number[]>): void| Unsubscribes from events indicating receiving of APDUs from the peer card reader.|

## Preparations

### Selecting Foreground or Background Card Swiping
HCE application developers can choose to implement either foreground or background card swiping based on service requirements. These two methods differ in their code implementation.
- HCE Foreground Card Swiping<br>
1. In the **module.json5** configuration file, there is no need to statically declare the AID selected by the NFC card reader. Instead, dynamically register an AID by using [start](../../reference/apis-connectivity-kit/js-apis-cardEmulation.md#start9).
2. When the card swiping page of the HCE application exits,  explicitly called [stop](../../reference/apis-connectivity-kit/js-apis-cardEmulation.md#stop9) to release the dynamically registered AID.
- HCE Background Card Swiping<br>
1. In the **module.json5** configuration file, statically declare the AID selected by the NFC card reader. Based on service requirements, specify whether the declared AID belongs to the **Payment** type or the **Other** type.
2. If the **Payment** type is selected, the HCE application will appear in the default payment app list on the NFC settings page. Users can only use background card swiping after selecting this HCE application as the default payment app. Since a default payment app is designated, there will be no conflicts between multiple HCE applications of the **Payment** type.
3. If the **Other** type is selected, the HCE application will not appear in the default payment app list on the NFC settings page. However, conflicts may arise if multiple HCE applications declare the same AID of the **Other** type.
4. When implementing HCE background card swiping, you do not need to call the **start** and **stop** APIs.

> **NOTE**
>
> - Starting from API version 9, application development supports the Stage model, which is recommended for long-term evolution.
> - All the HCE sample code in this document is based on the Stage model.

## How to Develop

### HCE Foreground Card Swiping
1. Declare the permission required for NFC card emulation and HCE action in the **module.json5** file.
2. Import modules.
3. Check whether the device supports the NFC and HCE capabilities.
4. Enable the foreground HCE application to preferentially process NFC card swiping.
5. Subscribe to the HCE APDU receiving events.
6. Receive and send APDU data for HCE card swiping.
7. Exit the HCE foreground mode when the application exits the NFC card swiping page.

```ts
    "abilities": [
      {
        "name": "EntryAbility",
        "srcEntry": "./ets/entryability/EntryAbility.ts",
        "description": "$string:EntryAbility_desc",
        "icon": "$media:icon",
        "label": "$string:EntryAbility_label",
        "startWindowIcon": "$media:icon",
        "startWindowBackground": "$color:start_window_background",
        "exported": true,
        "skills": [
          {
            "entities": [
              "entity.system.home"
            ],
            "actions": [
              "ohos.want.action.home",

              // The **actions** field must contain ohos.nfc.cardemulation.action.HOST_APDU_SERVICE.
              "ohos.nfc.cardemulation.action.HOST_APDU_SERVICE"
            ]
          }
        ]
      }
    ],
    "requestPermissions": [
      {
        // Add the permission required for NFC card emulation.
        "name": "ohos.permission.NFC_CARD_EMULATION",
        "reason": "$string:app_name",
      }
    ]
```

```ts
import { cardEmulation } from '@kit.ConnectivityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { hilog } from '@kit.PerformanceAnalysisKit';
import { AsyncCallback } from '@kit.BasicServicesKit';
import { AbilityConstant, UIAbility, Want, bundleManager } from '@kit.AbilityKit';

let hceElementName: bundleManager.ElementName;
let hceService: cardEmulation.HceService;

const hceCommandCb : AsyncCallback<number[]> = (error : BusinessError, hceCommand : number[]) => {
  if (!error) {
    if (hceCommand == null || hceCommand == undefined) {
      hilog.error(0x0000, 'testTag', 'hceCommandCb has invalid hceCommand.');
      return;
    }
    // The application checks the content of the received command and sends the matching response data based on its own service implementation.
    hilog.info(0x0000, 'testTag', 'hceCommand = %{public}s', JSON.stringify(hceCommand));
    let responseData = [0x90, 0x00]; // Change the response data based on the received command.
    hceService.transmit(responseData).then(() => {
      hilog.info(0x0000, 'testTag', 'hceService transmit Promise success.');
    }).catch((err: BusinessError) => {
      hilog.error(0x0000, 'testTag', 'hceService transmit Promise error = %{public}s', JSON.stringify(err));
    });
  } else {
    hilog.error(0x0000, 'testTag', 'hceCommandCb error %{public}s', JSON.stringify(error));
  }
}

export default class EntryAbility extends UIAbility {
  onCreate(want: Want, launchParam: AbilityConstant.LaunchParam) {
    hilog.info(0x0000, 'testTag', '%{public}s', 'Ability onCreate');

    // Check whether the device supports the NFC and HCE capabilities.
    if (!canIUse("SystemCapability.Communication.NFC.Core")) {
      hilog.error(0x0000, 'testTag', 'nfc unavailable.');
      return;
    }
    if (!cardEmulation.hasHceCapability()) {
      hilog.error(0x0000, 'testTag', 'hce unavailable.');
      return;
    }

    // Initialize the correct value based on the application information.
    hceElementName = {
      bundleName: want.bundleName ?? '',
      abilityName: want.abilityName ?? '',
      moduleName: want.moduleName,
    }
    hceService = new cardEmulation.HceService();
  }

  onForeground() {
    // Switch the application to the foreground.
    hilog.info(0x0000, 'testTag', '%{public}s', 'Ability onForeground');
    if (hceElementName != undefined) {
      try {
        // Enable the foreground HCE application to preferentially process NFC card swiping.
        let aidList = ["A0000000031010," "A0000000031011"]; // Set the AID list correctly.
        hceService.start(hceElementName, aidList);

        // Subscribe to the HCE APDU receiving events.
        hceService.on('hceCmd', hceCommandCb);
      } catch (error) {
        hilog.error(0x0000, 'testTag', 'hceService.start error = %{public}s', JSON.stringify(error));
      }
    }
  }

  onBackground() {
    // Switch the application to the background.
    hilog.info(0x0000, 'testTag', '%{public}s', 'Ability onBackground');
    // When exiting the NFC tag page of the application, call the tag module API to exit the foreground mode.
    if (hceElementName != undefined) {
      try {
        hceService.stop(hceElementName);
      } catch (error) {
        hilog.error(0x0000, 'testTag', 'hceService.stop error = %{public}s', JSON.stringify(error));
      }
    }
  }
}
```

### HCE Background Card Swiping
1. Declare the permission required for NFC card emulation, HCE action, and AIDs for application matching in the **module.json5** file.
2. Import modules.
3. Check whether the device supports the NFC and HCE capabilities.
4. Subscribe to the HCE APDU receiving events.
5. Receive and send APDU data for HCE card swiping.
6. Cancel the subscription when the application exits.

```ts
    "abilities": [
      {
        "name": "EntryAbility",
        "srcEntry": "./ets/entryability/EntryAbility.ts",
        "description": "$string:EntryAbility_desc",
        "icon": "$media:icon",
        "label": "$string:EntryAbility_label",
        "startWindowIcon": "$media:icon",
        "startWindowBackground": "$color:start_window_background",
        "exported": true,
        "skills": [
          {
            "entities": [
              "entity.system.home"
            ],
            "actions": [
              "ohos.want.action.home",

              // The **actions** field must contain ohos.nfc.cardemulation.action.HOST_APDU_SERVICE.
              "ohos.nfc.cardemulation.action.HOST_APDU_SERVICE"
            ]
          }
        ],

        // Define at least one AID of the Payment or Other type based on service requirements.
        "metadata": [
          {
            "name": "payment-aid",
            "value": "A0000000031010" // Define the AID of the Payment type.
          },
          {
            "name": "other-aid",
            "value": "A0000000031011" // Define the AID of the Other type.
          }
        ]
      }
    ],
    "requestPermissions": [
      {
        // Add the permission required for NFC card emulation.
        "name": "ohos.permission.NFC_CARD_EMULATION",
        "reason": "$string:app_name",
      }
    ]
```

```ts
import { cardEmulation } from '@kit.ConnectivityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { hilog } from '@kit.PerformanceAnalysisKit';
import { AsyncCallback } from '@kit.BasicServicesKit';
import { AbilityConstant, UIAbility, Want, bundleManager } from '@kit.AbilityKit';

let hceElementName : bundleManager.ElementName;
let hceService: cardEmulation.HceService;

const hceCommandCb : AsyncCallback<number[]> = (error : BusinessError, hceCommand : number[]) => {
  if (!error) {
    if (hceCommand == null || hceCommand == undefined) {
      hilog.error(0x0000, 'testTag', 'hceCommandCb has invalid hceCommand.');
      return;
    }

    // The application checks the content of the received command and sends the matching response based on its own service implementation.
    hilog.info(0x0000, 'testTag', 'hceCommand = %{public}s', JSON.stringify(hceCommand));
    let responseData = [0x90, 0x00]; // Change the response data based on the received command.
    hceService.transmit(responseData).then(() => {
      hilog.info(0x0000, 'testTag', 'hceService transmit Promise success.');
    }).catch((err: BusinessError) => {
      hilog.error(0x0000, 'testTag', 'hceService transmit Promise error = %{public}s', JSON.stringify(err));
    });
  } else {
    hilog.error(0x0000, 'testTag', 'hceCommandCb error %{public}s', JSON.stringify(error));
  }
}

export default class EntryAbility extends UIAbility {
  onCreate(want: Want, launchParam: AbilityConstant.LaunchParam) {
    hilog.info(0x0000, 'testTag', '%{public}s', 'Ability onCreate');

    // Check whether the device supports the NFC and HCE capabilities.
    if (!canIUse("SystemCapability.Communication.NFC.Core")) {
      hilog.error(0x0000, 'testTag', 'nfc unavailable.');
      return;
    }
    if (!cardEmulation.hasHceCapability()) {
      hilog.error(0x0000, 'testTag', 'hce unavailable.');
      return;
    }

    // Subscribe to HCE card swiping data when the application is running in the foreground.
    hceService = new cardEmulation.HceService();
    hceService.on('hceCmd', hceCommandCb);
  }

  onForeground() {
    // Switch the application to the foreground.
    hilog.info(0x0000, 'testTag', '%{public}s', 'Ability onForeground');
  }

  onDestroy() {
    hilog.info(0x0000, 'testTag', '%{public}s', 'Ability onDestroy');
    // Unsubscribe from HCE card swiping data when the application exits.
    hceService.off('hceCmd', hceCommandCb);
  }
}
```
