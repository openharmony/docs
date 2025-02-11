# NFC标签读写开发指南

## 简介
近场通信(Near Field Communication，NFC)是一种短距高频的无线电技术，在13.56MHz频率运行，通信距离一般在10厘米距离内。电子设备可以通过NFC通信技术和NFC标签通信，从标签中读取数据，或写入数据到标签。
NFC标签可能会支持一种或多种通信技术，具体技术如下：
- NfcA (也称为 ISO 14443-3A)
- NfcB (也称为 ISO 14443-3B)
- NfcF (也称为 JIS 6319-4)
- NfcV (也称为 ISO 15693)
- IsoDep
- NDEF
- MifareClassic
- MifareUltralight

## 场景介绍
电子设备通过NFC天线位置触碰NFC标签卡片，完成NFC标签卡片的读取或写入。从使用场景上，可以分成NFC标签前台读写，和NFC标签后台读写。
- NFC标签前台读写<br>
前台读写是指在触碰NFC标签之前，用户先在电子设备上打开特定的应用程序，用户明确想使用所打开的应用程序和NFC标签进行读写操作。用户打开应用程序在前台，并且进入应用的刷卡页面之后，电子设备触碰NFC标签，只会把读取到的卡片分发给前台应用。
- NFC标签后台读写<br>
后台读写是指不打开特定的NFC标签应用程序，电子设备触碰发现NFC标签后，根据NFC标签的技术类型，分发给能够处理的应用程序。如果能匹配到多个应用程序，则弹出应用选择器列举出应用列表给用户手动选择。用户选择指定的应用后，自动跳转到应用程序的NFC标签读写卡页面。
- 标签读写约束条件<br>
不管是前台读写，还是后台读写，电子设备能够发现NFC标签的前提条件是设备必须是亮屏和解锁状态。

## 接口说明

NFC标签读写完整的JS API说明以及实例代码请参考：[NFC标签接口](../../reference/apis-connectivity-kit/js-apis-nfcTag.md)。

获取不同技术类型标签对象的接口说明如下表，根据不同技术的标签对象来执行NFC标签的读写。

| 接口名                             | 功能描述                                                                       |
| ---------------------------------- | ------------------------------------------------------------------------------ |
| getNfcA(tagInfo: TagInfo): NfcATag                    | 获取NfcA技术类型的标签对象。                                                               |
| getNfcB(tagInfo: TagInfo): NfcBTag                      | 获取NfcB技术类型的标签对象。                                                                |
| getNfcF(tagInfo: TagInfo): NfcFTag                 | 获取NfcF技术类型的标签对象。                                                               |
| getNfcV(tagInfo: TagInfo): NfcVTag                  | 获取NfcV技术类型的标签对象。                                                                |
| getIsoDep(tagInfo: TagInfo): IsoDepTag | 获取IsoDep技术类型的标签对象。                                                                |
| getNdef(tagInfo: TagInfo): NdefTag | 获取NDEF技术类型的标签对象。                                                            |
| getMifareClassic(tagInfo: TagInfo): MifareClassicTag         | 获取MifareClassic技术类型的标签对象。                                                        |
| getMifareUltralight(tagInfo: TagInfo): MifareUltralightTag         | 获取MifareUltralight技术类型的标签对象。                                                     |

## 开发步骤

### 前台读取标签
1. 在module.json5文件中声明NFC标签读取的权限，以及声明NFC标签特定的action。
2. import需要的tag模块和其他相关的模块。
3. 判断设备是否支持NFC能力。
4. 调用tag模块中前台优先的接口，使能前台应用程序优先处理所发现的NFC标签功能。
5. 获取特定技术类型的NFC标签对象。
6. 执行读写接口完成标签数据的读取或写入数据到标签。
7. 退出应用程序NFC标签页面时，调用tag模块退出前台优先功能。

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
              "action.system.home",

              // Add the nfc tag action to filter out for this application.
              "ohos.nfc.tag.action.TAG_FOUND"
            ]
          }
        ]
      }
    ],
    "requestPermissions": [
      {
        // Add the permission for nfc tag operations.
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
    // 获取特定技术类型的NFC标签对象
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

    // 执行读写接口完成标签数据的读取或写入数据到标签
    // use the IsoDep technology to access this nfc tag.
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
      // use other technology to access this nfc tag if necessary.
    }
    if (isoDep == undefined) {
      hilog.error(0x0000, 'testTag', 'readerModeCb getIsoDep is invalid');
      return;
    }

    // connect to this nfc tag using IsoDep technology.
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

    // transmit data to the connected tag.
    let cmdData = [0x01, 0x02, 0x03, 0x04]; // please change the raw data to be correct.
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

    // 判断设备是否支持NFC能力
    if (!canIUse("SystemCapability.Communication.NFC.Core")) {
      hilog.error(0x0000, 'testTag', 'nfc unavailable.');
      return;
    }

    nfcTagElementName = {
      bundleName: want.bundleName ?? '',
      abilityName: want.abilityName ?? '',
      moduleName: want.moduleName,
    }
  }

  onForeground() {
    // Ability has brought to foreground
    hilog.info(0x0000, 'testTag', '%{public}s', 'Ability onForeground');
    if (nfcTagElementName != undefined) {
      // 调用tag模块中前台优先的接口，使能前台应用程序优先处理所发现的NFC标签功能
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
    // Ability has back to background
    hilog.info(0x0000, 'testTag', '%{public}s', 'Ability onBackground');
    // 退出应用程序NFC标签页面时，调用tag模块退出前台优先功能
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

### 后台读取标签
1. 在module.json5文件中声明NFC标签读取的权限，声明NFC标签特定的action，以及声明本应用程序的能够处理的NFC标签技术类型。
2. import需要的tag模块和其他相关的模块。
3. 获取特定技术类型的NFC标签对象。
4. 执行读写接口完成标签数据的读取或写入数据到标签。

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
              "action.system.home",

              // Add the nfc tag action to filter out for this application.
              "ohos.nfc.tag.action.TAG_FOUND"
            ],
            "uris": [
              {
                  "type":"tag-tech/NfcA"
              },
              {
                  "type":"tag-tech/IsoDep"
              }
              // Add other technologies if necessary,
              // such as: NfcB/NfcF/NfcV/Ndef/MifareClassic/MifareUL/NdefFormatable
            ]
          }
        ]
      }
    ],
    "requestPermissions": [
      {
        // Add the permission for nfc tag operations.
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

    // 获取特定技术类型的NFC标签对象
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

    // 执行读写接口完成标签数据的读取或写入数据到标签
    // use the IsoDep technology to access this nfc tag.
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
      // use other technology to access this nfc tag if necessary.
    }
    if (isoDep == undefined) {
      hilog.error(0x0000, 'testTag', 'getIsoDep is invalid');
      return;
    }

    // connect to this nfc tag using IsoDep technology.
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

    // transmit data to the connected tag.
    let cmdData = [0x01, 0x02, 0x03, 0x04]; // please change the raw data to be correct.
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