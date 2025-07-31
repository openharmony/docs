# NFC Tag Read/Write Development

## Introduction
Near Field Communication (NFC) is a high-frequency radio technology that enables communication between devices over a distance less than 10 cm. NFC operates at 13.56 MHz. With NFC technologies, electronic devices can read and write NFC tags.<br>
NFC tags support one or more communications technologies listed as follows:
- NFC-A (also known as ISO 14443-3A)
- NFC-B (also known as ISO 14443-3B)
- NFC-F (also known as JIS 6319-4)
- NFC-V (also known as ISO 15693)
- ISO-DEP (also known as ISO 14443-4)
- NDEF
- MIFARE Classic
- MIFARE Ultralight

## When to Use
An electronic device touches an NFC tag via the NFC antenna to read and write the NFC tag data. NFC tags can be read and written by a started application (foreground mode) on a device or without starting an application (background mode).
- Reading or writing an NFC tag by a started application<br>
An application started on a device reads or writes the NFC tag. That is, the user starts the application to read and write the NFC tag. The user starts the application, opens the application page, and taps the device on the NFC tag. In this case, the retrieved tag data can be distributed only to the foreground application.
- Reading or writing an NFC tag without starting an application<br>
The user taps the device on an NFC tag without starting any application. Then, the device selects an application based on the type of the NFC tag technology. If multiple applications are matched, an application selector will be displayed, listing all the available applications for the user to choose. After the user selects an application, the NFC tag read/write page of the application is automatically displayed.
- Constraints<br>
No matter whether the foreground mode or background mode is used, the NFC tag can be discovered by the device only when the device screen is unlocked and illuminated.

## Available APIs

For details about the JS APIs and sample code, see [Standard NFC Tags](../../reference/apis-connectivity-kit/js-apis-nfcTag.md).

The following table describes the APIs for obtaining objects of the tags that use different NFC tag technologies. The objects obtained are used to read and write NFC tags.

| API                            | Description                                                                      |
| ---------------------------------- | ------------------------------------------------------------------------------ |
| getNfcA(tagInfo: TagInfo): NfcATag                    | Obtains an **NfcATag** object, which allows access to the tags that use the NFC-A technology.                                                              |
| getNfcB(tagInfo: TagInfo): NfcBTag                      | Obtains an **NfcBTag** object, which allows access to the tags that use the NFC-B technology.                                                               |
| getNfcF(tagInfo: TagInfo): NfcFTag                 | Obtains an **NfcFTag** object, which allows access to the tags that use the NFC-F technology.                                                              |
| getNfcV(tagInfo: TagInfo): NfcVTag                  | Obtains an **NfcVTag** object, which allows access to the tags that use the NFC-V technology.                                                               |
| getIsoDep(tagInfo: TagInfo): IsoDepTag | Obtains an **IsoDepTag** object, which allows access to the tags that use the ISO-DEP technology.                                                               |
| getNdef(tagInfo: TagInfo): NdefTag | Obtains an **NdefTag** object, which allows access to the tags that use the NDEF technology.                                                           |
| getMifareClassic(tagInfo: TagInfo): MifareClassicTag         | Obtains a **MifareClassicTag** object, which allows access to the tags that use the MIFARE Classic technology.                                                       |
| getMifareUltralight(tagInfo: TagInfo): MifareUltralightTag         | Obtains a **MifareUltralightTag** object, which allows access to the tags that use the MIFARE Ultralight technology.                                                    |

## Preparations

### Reading/Writing NFC Tags in the Foreground or Background
NFC tag application developers can choose to read/write NFC tags in the foreground or background based on service requirements. These two methods differ in their code implementations.
- Reading or writing an NFC tag by a started application<br>
1. In the **module.json5** configuration file, you do not need to statically declare the technology type of the target NFC tag. Instead, dynamically register the technology type by using [tag.registerForegroundDispatch](../../reference/apis-connectivity-kit/js-apis-nfcTag.md#tagregisterforegrounddispatch10) or [tag.on](../../reference/apis-connectivity-kit/js-apis-nfcTag.md#tagon11).
2. During dynamic registration via **registerForegroundDispatch** or **tag.on**, specify the technology type of the target NFC tags in the input parameters.
3. If **registerForegroundDispatch** is used for registration: When the application runs in the foreground and enters the card swiping page, the NFC card emulation function is enabled, allowing card swiping to be performed simultaneously. If **tag.on** is used for registration: When the application runs in the foreground and enters the card swiping page, the NFC card emulation function is disabled, making simultaneous card swiping unavailable.
4. When the app page switches to the background, explicitly call [tag.unregisterForegroundDispatch](../../reference/apis-connectivity-kit/js-apis-nfcTag.md#tagunregisterforegrounddispatch10) or [tag.off](../../reference/apis-connectivity-kit/js-apis-nfcTag.md#tagoff11) to unregister technology type and exit the foreground dispatch mode.
- Reading or writing an NFC tag without starting an application<br>
1. In the **module.json5** configuration file, statically declare the technology type of the target NFC tag. You must define at least one technology type based on service requirements. **tag-tech/** is the prefix, followed by the technology type description.
2. The technology type description is case-sensitive and must exactly match the actual technology type.

> **NOTE**
> - Starting from API version 9, application development supports the Stage model, which is recommended for long-term evolution.
> - All the sample code in this document is based on the Stage model.

## How to Develop

### Accessing an NFC Tag by a Started Application
1. Declare the permission required for NFC tag operations and the action for filtering the application in the **module.json5** file.
2. Import related modules.
3. Check whether the device supports the NFC feature.
4. Register a listener for the NFC tag read event so that the tag can be preferentially dispatched to a foreground application.
5. Obtain an NFC tag object of the specific technology type.
6. Read and write the tag data.
7. Exit the foreground dispatch mode when the application exits the NFC tag page.

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

              // The actions field must contain ohos.nfc.tag.action.TAG_FOUND.
              "ohos.nfc.tag.action.TAG_FOUND"
            ]
          }
        ]
      }
    ],
    "requestPermissions": [
      {
        // Add the NFC tag operation permission.
        "name": "ohos.permission.NFC_TAG",
        "reason": "$string:app_name",
      }
    ]
```

```ts
import { tag } from '@kit.ConnectivityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { hilog } from '@kit.PerformanceAnalysisKit';
import { AbilityConstant, UIAbility, Want, bundleManager } from '@kit.AbilityKit';

let nfcTagElementName: bundleManager.ElementName;
let foregroundRegister: boolean;

async function readerModeCb(error : BusinessError, tagInfo : tag.TagInfo) {
  if (!error) {
    // Obtain an NFC tag object of the specific technology type.
    if (tagInfo == null || tagInfo == undefined) {
      hilog.error(0x0000, 'testTag', 'readerModeCb tagInfo is invalid');
      return;
    }
    if (tagInfo.uid == null || tagInfo.uid == undefined) {
      hilog.error(0x0000, 'testTag', 'readerModeCb uid is invalid');
      return;
    }
    if (tagInfo.technology == null || tagInfo.technology == undefined || tagInfo.technology.length == 0) {
      hilog.error(0x0000, 'testTag', 'readerModeCb technology is invalid');
      return;
    }

    // The NFC tag may support multiple technology types. Select a specific technology type to read or write tag data.
    // The following sample code is based on the IsoDep technology.
    let isoDep : tag.IsoDepTag | null = null;
    for (let i = 0; i < tagInfo.technology.length; i++) {
      if (tagInfo.technology[i] == tag.ISO_DEP) {
        try {
          isoDep = tag.getIsoDep(tagInfo);
        } catch (error) {
          hilog.error(0x0000, 'testTag', 'readerModeCb getIsoDep error = %{public}s', JSON.stringify(error));
          return;
        }
      }
      // You can also use other technology types as required.
    }
    if (isoDep == undefined) {
      hilog.error(0x0000, 'testTag', 'readerModeCb getIsoDep is invalid');
      return;
    }

    // Connect to the NFC tag via IsoDep.
    try {
        isoDep.connect(); 
    } catch (error) {
        hilog.error(0x0000, 'testTag', 'readerModeCb isoDep.connect() error = %{public}s', JSON.stringify(error));
        return;
    }
    if (!isoDep.isConnected()) {
      hilog.error(0x0000, 'testTag', 'readerModeCb isoDep.isConnected() false.');
      return;
    }

    // Send a command to the connected NFC tag to obtain the response data.
    let cmdData = [0x01, 0x02, 0x03, 0x04]; // Modify the command data as required.
    try {
      isoDep.transmit(cmdData).then((response : number[]) => {
        hilog.info(0x0000, 'testTag', 'readerModeCb isoDep.transmit() response = %{public}s.', JSON.stringify(response));
      }).catch((err : BusinessError)=> {
        hilog.error(0x0000, 'testTag', 'readerModeCb isoDep.transmit() err = %{public}s.', JSON.stringify(err));
        return;
      });
    } catch (businessError) {
      hilog.error(0x0000, 'testTag', 'readerModeCb isoDep.transmit() businessError = %{public}s.', JSON.stringify(businessError));
      return;
    }
  } else {
    hilog.info(0x0000, 'testTag', 'readerModeCb readerModeCb error %{public}s', JSON.stringify(error));
  }
}

export default class EntryAbility extends UIAbility {
  onCreate(want: Want, launchParam: AbilityConstant.LaunchParam) {
    hilog.info(0x0000, 'testTag', '%{public}s', 'Ability onCreate');

    // Check whether the device supports the NFC feature.
    if (!canIUse("SystemCapability.Communication.NFC.Core")) {
      hilog.error(0x0000, 'testTag', 'nfc unavailable.');
      return;
    }

    // Initialize element names of the NFC tag based on the application information.
    nfcTagElementName = {
      bundleName: want.bundleName ?? '',
      abilityName: want.abilityName ?? '',
      moduleName: want.moduleName,
    }
  }

  onForeground() {
    // Switch the application to the foreground and call the foreground dispatch API to enable the foreground application to preferentially process the discovered NFC tag.
    hilog.info(0x0000, 'testTag', '%{public}s', 'Ability onForeground');
    if (nfcTagElementName != undefined) {
      // Select an appropriate technology type based on service requirements.
      let techList : number[] = [tag.NFC_A, tag.NFC_B, tag.NFC_F, tag.NFC_V];
      try {
        tag.on('readerMode', nfcTagElementName, techList, readerModeCb);
        foregroundRegister = true;
      } catch (error) {
        hilog.error(0x0000, 'testTag', 'on readerMode error = %{public}s', JSON.stringify(error));
      }
    }
  }

  onBackground() {
    hilog.info(0x0000, 'testTag', '%{public}s', 'Ability onBackground');
    // When exiting the NFC tag page, call the tag.off API to exit the foreground dispatch mode.
    if (foregroundRegister) {
      foregroundRegister = false;
      try {
        tag.off('readerMode', nfcTagElementName);
      } catch (error) {
        hilog.error(0x0000, 'testTag', 'off readerMode error = %{public}s', JSON.stringify(error));
      }
    }
  }
}
```

### Accessing an NFC Tag Without Starting an Application
1. In the **module.json5** configuration file, declare the NFC tag operation permission, the NFC tag action, and the technology type.
2. Import related modules.
3. Obtain an NFC tag object of the specific technology type.
4. Read and write the tag data.

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

              // The actions field must contain ohos.nfc.tag.action.TAG_FOUND.
              "ohos.nfc.tag.action.TAG_FOUND"
            ],

            // You must define at least one technology type based on service requirements. **tag-tech/** is the prefix, followed by the technology type description.
            "uris": [
              {
                  "type":"tag-tech/NfcA"
              },
              {
                  "type":"tag-tech/IsoDep"
              }
              //  Add other technology types if necessary.
              // Example: NfcB/NfcF/NfcV/Ndef/MifareClassic/MifareUL/NdefFormatable
            ]
          }
        ]
      }
    ],
    "requestPermissions": [
      {
        // Add the NFC tag operation permission.
        "name": "ohos.permission.NFC_TAG",
        "reason": "$string:app_name",
      }
    ]
```

```ts
import { tag } from '@kit.ConnectivityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { hilog } from '@kit.PerformanceAnalysisKit';
import { AbilityConstant, UIAbility, Want } from '@kit.AbilityKit';

export default class EntryAbility extends UIAbility {
  onCreate(want: Want, launchParam: AbilityConstant.LaunchParam) {
    hilog.info(0x0000, 'testTag', '%{public}s', 'Ability onCreate');

    // Obtain an NFC tag object of the specific technology type.
    let tagInfo : tag.TagInfo;
    try {
      tagInfo = tag.getTagInfo(want);
    } catch (error) {
      hilog.error(0x0000, 'testTag', 'getTagInfo error = %{public}s', JSON.stringify(error));
      return;
    }

    if (tagInfo == null || tagInfo == undefined) {
      hilog.error(0x0000, 'testTag', 'tagInfo is invalid');
      return;
    }
    if (tagInfo.uid == null || tagInfo.uid == undefined) {
      hilog.error(0x0000, 'testTag', 'uid is invalid');
      return;
    }
    if (tagInfo.technology == null || tagInfo.technology == undefined || tagInfo.technology.length == 0) {
      hilog.error(0x0000, 'testTag', 'technology is invalid');
      return;
    }

    // The NFC tag may support multiple technology types. Select a specific technology type to read or write tag data.
    // The following sample code is based on the IsoDep technology.
    let isoDep : tag.IsoDepTag | null = null;
    for (let i = 0; i < tagInfo.technology.length; i++) {
      if (tagInfo.technology[i] == tag.ISO_DEP) {
        try {
          isoDep = tag.getIsoDep(tagInfo);
        } catch (error) {
          hilog.error(0x0000, 'testTag', 'getIsoDep error = %{public}s', JSON.stringify(error));
          return;
        }
      }
      // You can also use other technology types as required.
    }
    if (isoDep == undefined) {
      hilog.error(0x0000, 'testTag', 'getIsoDep is invalid');
      return;
    }

    // Connect to the NFC tag via IsoDep.
    try {
        isoDep.connect(); 
    } catch (error) {
        hilog.error(0x0000, 'testTag', 'isoDep.connect() error = %{public}s', JSON.stringify(error));
        return;
    }
    if (!isoDep.isConnected()) {
      hilog.error(0x0000, 'testTag', 'isoDep.isConnected() false.');
      return;
    }

    // Send a command to the connected NFC tag to obtain the response data.
    let cmdData = [0x01, 0x02, 0x03, 0x04]; // Modify the command data as required.
    try {
      isoDep.transmit(cmdData).then((response : number[]) => {
        hilog.info(0x0000, 'testTag', 'isoDep.transmit() response = %{public}s.', JSON.stringify(response));
      }).catch((err : BusinessError)=> {
        hilog.error(0x0000, 'testTag', 'isoDep.transmit() err = %{public}s.', JSON.stringify(err));
        return;
      });
    } catch (businessError) {
      hilog.error(0x0000, 'testTag', 'isoDep.transmit() businessError = %{public}s.', JSON.stringify(businessError));
      return;
    }
  }
}
```
