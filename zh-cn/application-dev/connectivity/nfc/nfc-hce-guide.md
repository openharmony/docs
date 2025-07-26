# HCE卡模拟开发指南

## 简介
近场通信(Near Field Communication，NFC)是一种短距高频的无线电技术，在13.56MHz频率运行，通信距离一般在10厘米距离内。HCE(Host Card Emulation)，称为基于主机的卡模拟，表示不依赖安全单元芯片，电子设备上的应用程序模拟NFC卡片和NFC读卡器通信，实现NFC刷卡业务。

## 场景介绍
应用程序模拟NFC卡片，和NFC读卡器通信完成NFC刷卡业务。从使用场景上，可以分成HCE应用前台刷卡和HCE应用后台刷卡。
- HCE应用前台刷卡<br>
前台刷卡是指在触碰NFC读卡器之前，用户明确想使用在电子设备上打开特定的应用程序和NFC读卡器进行刷卡操作。当用户打开应用程序在前台，并且进入应用的刷卡页面时，电子设备触碰NFC读卡器后，会把刷卡交易数据分发给前台应用。若应用切换至后台或退出运行时，前台优先分发规则也随即被暂停。
- HCE应用后台刷卡<br>
后台刷卡是指不打开特定的HCE应用程序，当电子设备触碰NFC读卡器时，根据NFC读卡器选择的应用ID（Applet ID，AID）匹配到HCE应用程序，并自动和匹配的HCE应用程序通信完成刷卡交易。如果NFC读卡器选择的应用ID，匹配到多个HCE应用程序时，说明存在冲突，需要用户打开指定的HCE应用，重新靠近NFC读卡器触发刷卡。

## HCE应用刷卡的约束条件
1. 基于刷卡安全性考虑，不论HCE应用是前台方式还是后台方式刷卡，均不支持电子设备在灭屏或熄屏状态下的HCE刷卡操作。<br>
2. 电子设备必须具备NFC控制器芯片，才支持HCE刷卡能力。对于是否具有NFC安全单元芯片，没有约束要求。<br>
3. HCE应用程序需要声明NFC卡模拟权限，具体见示例。<br>

## 接口说明

NFC卡模拟完整的API说明以及实例代码请参考：[NFC卡模拟接口](../../reference/apis-connectivity-kit/js-apis-cardEmulation.md)。

完成HCE卡模拟功能，可能使用到下面的接口。

| 接口名                             | 功能描述                                                                       |
| ---------------------------------- | ------------------------------------------------------------------------------ |
| start(elementName: ElementName, aidList: string[]): void                   | 启动HCE业务功能。包括设置当前应用为前台优先，动态注册AID列表。                                                               |
| stop(elementName: ElementName): void  | 停止HCE业务功能。包括取消APDU数据接收的订阅、退出当前应用前台优先、释放动态注册的AID列表。                                                     |
| on(type: 'hceCmd', callback: AsyncCallback\<number[]>): void                | 订阅回调，用于接收对端读卡设备发送的APDU数据。                                                     |
| transmit(response: number[]): Promise\<void>                  | 发送APDU数据到对端读卡设备。|
| off(type: 'hceCmd', callback?: AsyncCallback\<number[]>): void| 取消APDU数据接收的订阅。|

## 开发准备

### HCE应用支持前台或后台刷卡的选择
HCE应用开发者根据业务需要，可以选择实现前台刷卡或者后台刷卡。两种不同的刷卡方式，代码实现上会存在一些差异。
- HCE应用前台刷卡<br>
1. 在配置文件module.json5中，不需要静态声明NFC读卡器选择的应用ID（AID），而是通过[start](../../reference/apis-connectivity-kit/js-apis-cardEmulation.md#start9)来动态注册。
2. HCE应用的刷卡页面退出时，需要显性调用[stop](../../reference/apis-connectivity-kit/js-apis-cardEmulation.md#stop9)来释放动态注册的AID刷卡配置项。
- HCE应用后台刷卡<br>
1. 在配置文件module.json5中，需要静态声明NFC读卡器选择的应用ID（AID）。根据业务选择， 选择声明的AID是属于Payment类型，还是Other类型。
2. 如果选择Payment类型，该HCE应用会在系统设置页面的NFC"默认付款应用"里出现。用户必须选择该HCE应用作为默认支付应用后，才能实现后台刷卡功能。由于提供了默认支付应用的选项， 因此Payment类型的HCE应用，不会出现多个冲突的情况。
3. 如果选择Other类型，该HCE应用不会出现在系统设置页面的NFC"默认付款应用"里，但是多个HCE应用如果都声明了相同的Other类型的AID时，会出现冲突的可能。
4. HCE应用后台刷卡的实现，不需要调用接口start和stop。

> **注意：**
>
> - 从API version 9之后的应用开发新增支持Stage模型，作为目前主推并长期演进的模型。
> - HCE示例代码的提供，全部按照Stage模型来说明。

## 开发步骤

### HCE应用前台刷卡
1. 在module.json5文件中声明NFC卡模拟权限，以及声明HCE特定的action。
2. import需要的NFC卡模拟模块和其他相关的模块。
3. 判断设备是否支持NFC能力和HCE能力。
4. 使能前台HCE应用程序优先处理NFC刷卡功能。
5. 订阅HCE APDU数据的接收。
6. 完成HCE刷卡APDU数据的接收和发送。
7. 退出应用程序NFC刷卡页面时，退出前台优先功能。

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

              // actions必须包含"ohos.nfc.cardemulation.action.HOST_APDU_SERVICE"
              "ohos.nfc.cardemulation.action.HOST_APDU_SERVICE"
            ]
          }
        ]
      }
    ],
    "requestPermissions": [
      {
        // 添加使用NFC卡模拟需要的权限
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
    // 应用程序根据自己业务实现，检查接收到的指令内容，发送匹配的响应数据
    hilog.info(0x0000, 'testTag', 'hceCommand = %{public}s', JSON.stringify(hceCommand));
    let responseData = [0x90, 0x00]; // 根据接收到的不同指令更改响应数据
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

    // 判断设备是否支持NFC能力和HCE能力
    if (!canIUse("SystemCapability.Communication.NFC.Core")) {
      hilog.error(0x0000, 'testTag', 'nfc unavailable.');
      return;
    }
    if (!cardEmulation.hasHceCapability()) {
      hilog.error(0x0000, 'testTag', 'hce unavailable.');
      return;
    }

    // 根据应用程序信息，初始化正确的值
    hceElementName = {
      bundleName: want.bundleName ?? '',
      abilityName: want.abilityName ?? '',
      moduleName: want.moduleName,
    }
    hceService = new cardEmulation.HceService();
  }

  onForeground() {
    // 应用进入前台
    hilog.info(0x0000, 'testTag', '%{public}s', 'Ability onForeground');
    if (hceElementName != undefined) {
      try {
        // 调用接口使能前台HCE应用程序优先处理NFC刷卡功能
        let aidList = ["A0000000031010", "A0000000031011"]; // 修改为正确的aid
        hceService.start(hceElementName, aidList);

        // 订阅HCE APDU数据的接收
        hceService.on('hceCmd', hceCommandCb);
      } catch (error) {
        hilog.error(0x0000, 'testTag', 'hceService.start error = %{public}s', JSON.stringify(error));
      }
    }
  }

  onBackground() {
    // 应用退到后台
    hilog.info(0x0000, 'testTag', '%{public}s', 'Ability onBackground');
    // 退出应用程序NFC标签页面时，调用tag模块退出前台优先功能
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

### HCE应用后台刷卡
1. 在module.json5文件中声明NFC卡模拟权限，声明HCE特定的action，声明应用能够处理的AID。
2. import需要的NFC卡模拟模块和其他相关的模块。
3. 判断设备是否支持NFC能力和HCE能力。
4. 订阅HCE APDU数据的接收。
5. 完成HCE刷卡APDU数据的接收和发送。
6. 退出应用程序时，退出订阅功能。

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

              // actions必须包含"ohos.nfc.cardemulation.action.HOST_APDU_SERVICE"
              "ohos.nfc.cardemulation.action.HOST_APDU_SERVICE"
            ]
          }
        ],

        // 根据业务需要至少定义一个Payment类型或Other类型的AID，可以定义多个
        "metadata": [
          {
            "name": "payment-aid",
            "value": "A0000000031010" // 定义Payment类型的AID
          },
          {
            "name": "other-aid",
            "value": "A0000000031011" // 定义Other类型的AID
          }
        ]
      }
    ],
    "requestPermissions": [
      {
        // 添加使用NFC卡模拟需要的权限
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

    // 应用程序根据自己业务实现，检查接收到的指令内容，发送匹配的响应数据
    hilog.info(0x0000, 'testTag', 'hceCommand = %{public}s', JSON.stringify(hceCommand));
    let responseData = [0x90, 0x00]; // 根据接收到的不同指令更改响应数据
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

    // 判断设备是否支持NFC能力和HCE能力
    if (!canIUse("SystemCapability.Communication.NFC.Core")) {
      hilog.error(0x0000, 'testTag', 'nfc unavailable.');
      return;
    }
    if (!cardEmulation.hasHceCapability()) {
      hilog.error(0x0000, 'testTag', 'hce unavailable.');
      return;
    }

    // 应用程序被运行到前台时，订阅HCE刷卡数据的接收
    hceService = new cardEmulation.HceService();
    hceService.on('hceCmd', hceCommandCb);
  }

  onForeground() {
    // 应用进入前台
    hilog.info(0x0000, 'testTag', '%{public}s', 'Ability onForeground');
  }

  onDestroy() {
    hilog.info(0x0000, 'testTag', '%{public}s', 'Ability onDestroy');
    // 退出应用程序，取消订阅接受HCE刷卡数据
    hceService.off('hceCmd', hceCommandCb);
  }
}
```