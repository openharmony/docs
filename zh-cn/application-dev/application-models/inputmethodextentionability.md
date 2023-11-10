# InputMethodExtensionAbility

## 使用场景
[InputMethodExtensionAbility](../reference/apis/js-apis-inputmethod-extension-ability.md)基于[ExtensionAbility](extensionability-overview.md)框架，用于开发输入法应用。

[InputMethodExtensionAbility](../reference/apis/js-apis-inputmethod-extension-ability.md)实例及其所在的ExtensionAbility进程的整个生命周期，都是由输入法框架进行调度管理。输入法框架提供了[InputMethodExtensionAbility](../reference/apis/js-apis-inputmethod-extension-ability.md)基类，开发者需要派生此基类，以实现输入法应用生命周期开始和销毁时的相关初始化操作和资源清理工作等。

[InputMethodExtensionAbility](../reference/apis/js-apis-inputmethod-extension-ability.md)通过[InputMethodExtensionContext](../reference/apis/js-apis-inputmethod-extension-context.md)提供相关能力。


## 实现一个输入法应用

[InputMethodExtensionAbility](../reference/apis/js-apis-inputmethod-extension-ability.md)提供了onCreate()和onDestroy()生命周期回调，根据需要重写对应的回调方法。InputMethodExtensionAbility的生命周期如下：

- **onCreate()**

  服务被首次创建时触发该回调，开发者可以在此进行一些初始化的操作，例如注册公共事件监听等。

  > **说明：**
  >
  > 如果服务已创建，再次启动该InputMethodExtensionAbility不会触发onCreate()回调。

- **onDestroy()**

  当不再使用服务且准备将该实例销毁时，触发该回调。开发者可以在该回调中清理资源，如注销监听等。


## 开发步骤

开发者在实现一个输入法应用时，需要在DevEco Studio工程中新建一个InputMethodExtensionAbility，具体步骤如下：

1. 在工程Module对应的ets目录下，右键选择“New > Directory”，新建一个目录，并命名为InputMethodExtensionAbility。

2. 在InputMethodExtensionAbility目录下，右键选择“New > File”，新建四个文件，分别为KeyboardController.ts、InputMethodService.ts、Index.ets以及KeyboardKeyData.ts。目录如下：

```
/src/main/
├── ets/inputmethodextability
│   └──model/KeyboardController.ts			# 显示键盘
│   └──InputMethodService.ts				# 自定义类继承InputMethodExtensionAbility并加上需要的生命周期回调
│   └──pages
│      └── Index.ets						# 绘制键盘，添加输入删除功能
│      └── KeyboardKeyData.ts			    # 键盘属性定义
├── resources/base/profile/main_pages.json   
```

## 文件介绍

1. InputMethodService.ts文件。

   在InputMethodService.ts文件中，增加导入InputMethodExtensionAbility的依赖包，自定义类继承InputMethodExtensionAbility并加上需要的生命周期回调。

   ```ts
   import Want from '@ohos.app.ability.Want';
   import InputMethodExtensionAbility from '@ohos.InputMethodExtensionAbility';
   import keyboardController from './model/KeyboardController'
   
   export default class InputDemoService extends InputMethodExtensionAbility {
   
     onCreate(want: Want): void {
       keyboardController.onCreate(this.context); // 初始化窗口并注册对输入法框架的事件监听
     }
   
     onDestroy(): void {
       console.log("onDestroy.");
       keyboardController.onDestroy(); // 销毁窗口并去注册事件监听
     }
   }
   ```

2. KeyboardController.ts文件。

   ```ts
   import common from '@ohos.app.ability.common';
   import display from '@ohos.display';
   import inputMethodEngine from '@ohos.inputMethodEngine';
   import InputMethodExtensionContext from '@ohos.InputMethodExtensionContext';
   
   // 调用输入法框架的getInputMethodAbility方法获取实例，并由此实例调用输入法框架功能接口
   const inputMethodAbility: inputMethodEngine.InputMethodAbility = inputMethodEngine.getInputMethodAbility();
   
   export class KeyboardController {
     private mContext: InputMethodExtensionContext | undefined = undefined; // 保存InputMethodExtensionAbility中的context属性
     private panel: inputMethodEngine.Panel | undefined = undefined; 
     private textInputClient: inputMethodEngine.InputClient | undefined = undefined; 
     private keyboardController: inputMethodEngine.KeyboardController | undefined = undefined;
   
     constructor() {
     }
   
     public onCreate(context: InputMethodExtensionContext): void
     {
       this.mContext = context;
       this.initWindow(); // 初始化窗口
       this.registerListener(); // 注册对输入法框架的事件监听
     }
   
     public onDestroy(): void // 应用生命周期销毁
     {
       this.unRegisterListener(); // 去注册事件监听
       if(this.panel) { // 销毁窗口
         this.panel.hide();
         inputMethodAbility.destroyPanel(this.panel);
       }
       if(this.mContext) {
         this.mContext.destroy();
       }
     }
   
     public insertText(text: string): void {
       if(this.textInputClient) {
         this.textInputClient.insertText(text);
       }
     }
   
     public deleteForward(length: number): void {
       if(this.textInputClient) {
         this.textInputClient.deleteForward(length);
       }
     }
   
     private initWindow(): void // 初始化窗口
     {
       if(this.mContext === undefined) {
         return;
       }
       let dis = display.getDefaultDisplaySync();
       let dWidth = dis.width;
       let dHeight = dis.height;
       let keyHeightRate = 0.47;
       let keyHeight = dHeight * keyHeightRate;
       let nonBarPosition = dHeight - keyHeight;
       let panelInfo: inputMethodEngine.PanelInfo = {
         type: inputMethodEngine.PanelType.SOFT_KEYBOARD,
         flag: inputMethodEngine.PanelFlag.FLG_FIXED
       };
       inputMethodAbility.createPanel(this.mContext, panelInfo).then(async (inputPanel: inputMethodEngine.Panel) => {
         this.panel = inputPanel;
         if(this.panel) {
           await this.panel.resize(dWidth, keyHeight);
           await this.panel.moveTo(0, nonBarPosition);
           await this.panel.setUiContent('inputmethodextability/pages/Index');
         }
       });
     }
   
     private registerListener(): void
     {
       this.registerInputListener(); // 注册对输入法框架服务的监听
       ...
       // 注册隐藏键盘事件监听等
     }
   
     private registerInputListener(): void { // 注册对输入法框架服务的开启及停止事件监听
       inputMethodAbility.on('inputStart', (kbController, textInputClient) => {
         this.textInputClient = textInputClient; // 此为输入法客户端实例，由此调用输入法框架提供给输入法应用的功能接口
         this.keyboardController = kbController;
       })
       inputMethodAbility.on('inputStop', () => {
         this.onDestroy(); // 销毁KeyboardController
       });
     }
   
     private unRegisterListener(): void
     {
       inputMethodAbility.off('inputStart');
       inputMethodAbility.off('inputStop', () => {});
     }
   }
   
   const keyboardController = new KeyboardController();
   
   export default keyboardController;
   ```

3. KeyboardKeyData.ts文件。

   定义软键盘的按键显示内容。

   ```ts
   export interface sourceListType {
     content: string,
   }
   
   export let numberSourceListData: sourceListType[] = [
     {
       content: '1'
     },
     {
       content: '2'
     },
     {
       content: '3'
     },
     {
       content: '4'
     },
     {
       content: '5'
     },
     {
       content: '6'
     },
     {
       content: '7'
     },
     {
       content: '8'
     },
     {
       content: '9'
     },
     {
       content: '0'
     }
   ]
   ```

4. Index.ets文件。

   主要描绘了具体按键功能。如按下数字键，就会将数字内容在输入框中打印出来，按下删除键，就会将内容删除。

   同时在resources/base/profile/main_pages.json文件的src字段中添加此文件路径。

   ```ets
   import { numberSourceListData, sourceListType } from './keyboardKeyData';
   import keyboardController from '../model/KeyboardController';
   
   @Component
   struct keyItem {
     private keyValue: sourceListType = numberSourceListData[0];
     @State keyBgc: string = "#fff"
     @State keyFontColor: string = "#000"
   
     build() {
       Column() {
         Flex({ direction: FlexDirection.Column,
           alignItems: ItemAlign.Center, justifyContent: FlexAlign.Center }) {
           Text(this.keyValue.content).fontSize(20).fontColor(this.keyFontColor)
         }
       }
       .backgroundColor(this.keyBgc)
       .borderRadius(6)
       .width("8%")
       .height("65%")
       .onClick(() => {
         keyboardController.insertText(this.keyValue.content);
       })
     }
   }
   
   // 删除组件
   @Component
   export struct deleteItem {
     @State keyBgc: string = "#fff"
     @State keyFontColor: string = "#000"
   
     build() {
       Column() {
         Flex({ direction: FlexDirection.Column,
           alignItems: ItemAlign.Center, justifyContent: FlexAlign.Center }) {
           Text("删除").fontSize(20).fontColor(this.keyFontColor)
         }
       }
       .backgroundColor(this.keyBgc)
       .width("13%")
       .borderRadius(6)
       .onClick(() => {
         keyboardController.deleteForward(1);
       })
     }
   }
   
   // 数字键盘
   @Component
   struct numberMenu {
     private numberList: sourceListType[] = numberSourceListData;
   
     build() {
       Flex({ direction: FlexDirection.Column, alignItems: ItemAlign.Center, justifyContent: FlexAlign.SpaceEvenly }) {
         Flex({ justifyContent: FlexAlign.SpaceBetween }) {
           ForEach(this.numberList, (item: sourceListType) => { // 数字键盘第一行
             keyItem({ keyValue: item })
           }, (item: sourceListType) => item.content);
         }
         .padding({ top: "2%" })
         .width("96%")
         .height("25%")
   
         Flex({ justifyContent: FlexAlign.SpaceBetween }) {
           deleteItem()
         }
         .width("96%")
         .height("25%")
       }
     }
   }
   
   @Entry
   @Component
   struct Index {
     private numberList: sourceListType[] = numberSourceListData
   
     build() {
       Stack() {
         Flex({
           direction: FlexDirection.Column,
           alignItems: ItemAlign.Center,
           justifyContent: FlexAlign.End
         }) {
               Flex({
                 direction: FlexDirection.Column,
                 alignItems: ItemAlign.Center,
                 justifyContent: FlexAlign.SpaceBetween
               }) {
                 numberMenu({
                   numberList: this.numberList
                 })
               }
               .align(Alignment.End)
               .width("100%")
               .height("75%")
             }
         .height("100%").align(Alignment.End).backgroundColor("#cdd0d7")
       }
       .position({ x: 0, y: 0 }).zIndex(99999)
     }
   }
   ```

5. 在工程Module对应的[module.json5配置文件](../quick-start/module-configuration-file.md)中注册InputMethodExtensionAbility，type标签需要设置为“inputMethod”，srcEntry标签表示当前InputMethodExtensionAbility组件所对应的代码路径。

   ```json
   {
     "module": {
       ...
       "extensionAbilities": [
         {
           "description": "inputMethod",
           "icon": "$media:icon",
           "name": "InputMethodExtAbility",
           "srcEntry": "./ets/inputmethodextability/InputMethodService.ts",
           "type": "inputMethod",
           "exported": true,
         }
       ]
     }
   }
   ```

## 验证方法

1. 使用hdc命令，拉起选择输入法弹窗应用：`hdc shell aa start ability -a InputMethod -b cn.openharmonyinputmethodchoosedialog`

2. 在弹窗上显示的输入法应用列表中，选择并点击demo应用，将demo应用切换为当前输入法。

3. 点击任意编辑框，即可拉起输入法demo。

## 约束与限制

为了降低InputMethodExtensionAbility能力被三方应用滥用的风险，在InputMethodExtensionAbility中限制调用以下模块中的接口。

> **说明：**
>
> - 若导入被限制的模块，在编译时不报错，在运行时会返回错误的值，即undefined，导致不生效。
> - 当前未禁止对音频管理模块[@ohos.multimedia.audio (音频管理)](../reference/apis/js-apis-audio.md)的访问，但要求开发者应遵循以下约定：
>   - 不得因用户未授予录音权限而禁止用户使用输入法应用的非语音输入法功能；
>   - 仅允许InputMethodExtensionAbility处于前台时开展与录音相关的业务。如仅允许软键盘在前台且用户主动操作语音输入法时，才进行录音；应用切换到后台时，应主动停止录音；
>   - 系统会逐步增加对违反以上约定的行为进行管控和识别，因此未遵守此约定可能会造成业务功能异常。

**模块列表：** 

- [@ohos.ability.featureAbility (FeatureAbility模块)](../reference/apis/js-apis-ability-featureAbility.md)
- [@ohos.ability.particleAbility (ParticleAbility模块)](../reference/apis/js-apis-ability-particleAbility.md)
- [@ohos.account.distributedAccount (分布式帐号管理)](../reference/apis/js-apis-distributed-account.md)
- [@ohos.backgroundTaskManager (后台任务管理)](../reference/apis/js-apis-backgroundTaskManager.md)
- [@ohos.bluetooth (蓝牙)](../reference/apis/js-apis-bluetooth.md)
- [@ohos.bluetoothManager (蓝牙)](../reference/apis/js-apis-bluetoothManager.md)
- [@ohos.connectedTag (有源标签)](../reference/apis/js-apis-connectedTag.md)
- [@ohos.geolocation (位置服务)](../reference/apis/js-apis-geolocation.md)
- [@ohos.geoLocationManager (位置服务)](../reference/apis/js-apis-geoLocationManager.md)
- [@ohos.nfc.cardEmulation (标准NFC-cardEmulation)](../reference/apis/js-apis-cardEmulation.md)
- [@ohos.nfc.controller (标准NFC)](../reference/apis/js-apis-nfcController.md)
- [@ohos.nfc.tag (标准NFC-Tag)](../reference/apis/js-apis-nfcTag.md)
- [@ohos.reminderAgent (后台代理提醒)](../reference/apis/js-apis-reminderAgent.md)
- [@ohos.reminderAgentManager (后台代理提醒)](../reference/apis/js-apis-reminderAgentManager.md)
- [@ohos.sensor (传感器)](../reference/apis/js-apis-sensor.md)
- [@ohos.telephony.call (拨打电话)](../reference/apis/js-apis-call.md)
- [@ohos.telephony.data (蜂窝数据)](../reference/apis/js-apis-telephony-data.md)
- [@ohos.telephony.observer (observer)](../reference/apis/js-apis-observer.md)
- [@ohos.telephony.radio (网络搜索)](../reference/apis/js-apis-radio.md)
- [@ohos.telephony.sim (SIM卡管理)](../reference/apis/js-apis-sim.md)
- [@ohos.telephony.sms (短信服务)](../reference/apis/js-apis-sms.md)
- [@ohos.wallpaper (壁纸)](../reference/apis/js-apis-wallpaper.md)
- [@ohos.wifiext (WLAN扩展接口)](../reference/apis/js-apis-wifiext.md)
- [@ohos.wifiManager (WLAN)](../reference/apis/js-apis-wifiManager.md)
- [@ohos.wifiManagerExt (WLAN扩展接口)](../reference/apis/js-apis-wifiManagerExt.md)
- [@system.geolocation (地理位置)](../reference/apis/js-apis-system-location.md)
- [nfctech (标准NFC-Tag Nfc 技术)](../reference/apis/js-apis-nfctech.md)
- [tagSession (标准NFC-Tag TagSession)](../reference/apis/js-apis-tagSession.md)



## 相关实例

针对InputMethodExtensionAbility开发，有以下相关实例可供参考：

- [Kika输入法](https://gitee.com/openharmony/applications_app_samples/tree/OpenHarmony-4.0-Release/code/Solutions/InputMethod/KikaInput) 