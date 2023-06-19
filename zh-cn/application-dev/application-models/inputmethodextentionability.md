# InputMethodExtensionAbility

## 使用场景
[InputMethodExtensionAbility](../reference/apis/js-apis-inputmethod-extension-ability.md)基于[ExtensionAbility](extensionability-overview.md)框架，用于开发输入法应用。

[InputMethodExtensionAbility](../reference/apis/js-apis-inputmethod-extension-ability.md)实例及其所在的ExtensionAbility进程的整个生命周期，都是由输入法框架进行调度管理。输入法框架提供了[InputMethodExtensionAbility](../reference/apis/js-apis-inputmethod-extension-ability.md)基类，开发者需要派生此基类，以实现输入法应用生命周期开始和销毁时的相关初始化操作和资源清理工作等。

[InputMethodExtensionAbility](../reference/apis/js-apis-inputmethod-extension-ability.md)通过[InputMethodExtensionContext](../reference/apis/js-apis-inputmethod-extension-context.md)提供相关能力。


## 实现一个输入法应用

[InputMethodExtensionAbility](../reference/apis/js-apis-inputmethod-extension-ability.md)提供了onCreate()和onDestory()生命周期回调，根据需要重写对应的回调方法。InputMethodExtensionAbility的生命周期如下：

- **onCreate**
  服务被首次创建时触发该回调，开发者可以在此进行一些初始化的操作，例如注册公共事件监听等。

  > **说明：**
  >
  > 如果服务已创建，再次启动该InputMethodExtensionAbility不会触发onCreate()回调。

- **onDestroy**
  当不再使用服务且准备将该实例销毁时，触发该回调。开发者可以在该回调中清理资源，如注销监听等。


## 开发步骤

开发者在实现一个输入法应用时，需要在DevEco Studio工程中新建一个InputMethodExtensionAbility，具体步骤如下：

在工程Module对应的ets目录下，右键选择“New &gt; Extention Ability > InputMethod”，即可创建出InputMethodExtensionAbility的最小化模板。

> **说明：**
> 在编译输入法应用时，要使用system_basic级别的签名，否则无法拉起输入法键盘。
> [签名指导](https://developer.harmonyos.com/cn/docs/documentation/doc-guides/ohos-auto-configuring-signature-information-0000001271659465)

最小化模板为一个最基本的输入法应用，包含软键盘拉起以及输入删除功能。后续开发者可在此基础上添加功能，如隐藏键盘等，实现自己的输入法应用。

最小化模板主要包含四个文件，分别为KeyboardController.ts、InputMethodService.ts、Index.ets以及KeyboardKeyData.ts。目录如下：

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
   import InputMethodExtensionAbility from '@ohos.InputMethodExtensionAbility';
   import { KeyboardController } from './model/KeyboardController'
   
   export default class InputDemoService extends InputMethodExtensionAbility {
     private keyboardController: KeyboardController;
   
     onCreate(want) {
       this.keyboardController = new KeyboardController(this.context);
       this.keyboardController.onCreate();  // 初始化窗口并注册对输入法框架的事件监听
     }
   
     onDestroy() {
       console.log("onDestroy.");
       this.keyboardController.onDestroy();  // 销毁窗口并去注册事件监听
     }
   }
   ```

2. KeyboardController.ts文件。

   ```ts
   import inputMethodEngine from '@ohos.inputMethodEngine';
   import display from '@ohos.display';
   import windowManager from '@ohos.window';
   
   // 调用输入法框架的getInputMethodAbility方法获取实例，并由此实例调用输入法框架功能接口
   globalThis.inputAbility = inputMethodEngine.getInputMethodAbility();
   
   export class KeyboardController {
     mContext;	// 保存InputMethodExtensionAbility中的context属性
     WINDOW_TYPE_INPUT_METHOD_FLOAT = 2105;		// 定义窗口类型，2105代表输入法窗口类型，用于创建输入法应用窗口
     windowName = 'inputApp';
     private windowHeight: number = 0;
     private windowWidth: number = 0;
     private nonBarPosition: number = 0;
     private isWindowShowing: boolean = false;
   
     constructor(context) {
       this.mContext = context;
     }
   
     public onCreate(): void
     {
       this.initWindow();				// 初始化窗口
       this.registerListener();		// 注册对输入法框架的事件监听
     }
   
     public onDestroy(): void			// 应用生命周期销毁
     {
       this.unRegisterListener();		// 去注册事件监听
       let win = windowManager.findWindow(this.windowName);
       win.destroyWindow();				// 销毁窗口
     }
   
     private initWindow(): void		// 初始化窗口
     {
       let dis = display.getDefaultDisplaySync();
       let dWidth = dis.width;
       let dHeight = dis.height;
       let keyHeightRate = 0.47;
       let keyHeight = dHeight * keyHeightRate;
       this.windowWidth = dWidth;
       this.windowHeight = keyHeight;
       this.nonBarPosition = dHeight - keyHeight;
   
       let config = {
         name: this.windowName,
         windowType: this.WINDOW_TYPE_INPUT_METHOD_FLOAT,
         ctx: this.mContext
       }
       windowManager.createWindow(config).then((win) => {	// 根据窗口类型创建窗口
         win.resize(dWidth, keyHeight).then(() => {
           win.moveWindowTo(0, this.nonBarPosition).then(() => {
             win.setUIContent('pages/InputMethodExtAbility/Index').then(() => {
             });
           });
         });
       });
     }
   
     private registerListener(): void
     {
       this.registerInputListener();	// 注册对输入法框架服务的监听
       globalThis.inputAbility.on('keyboardShow', () => {	// 注册显示键盘事件监听
         if (this.isWindowShowing) {
           return;
         }
         this.isWindowShowing = true;
         this.showHighWindow();	// 显示窗口
       });
       ...
       // 注册隐藏键盘事件监听等
     }
   
     private registerInputListener() {		// 注册对输入法框架服务的开启及停止事件监听
       globalThis.inputAbility.on('inputStart', (kbController, textInputClient) => {
         globalThis.textInputClient = textInputClient;		// 此为输入法客户端实例，由此调用输入法框架提供给输入法应用的功能接口
         globalThis.keyboardController = kbController;
       })
       globalThis.inputAbility.on('inputStop', (imeId) => {
         if (imeId == "包名/Ability名") {
           this.mContext.destroy();	// 销毁InputMethodExtensionAbility服务
         }
       });
     }
   
     private unRegisterListener(): void
     {
       globalThis.inputAbility.off('inputStart');
       globalThis.inputAbility.off('inputStop', () => {});
       globalThis.inputAbility.off('keyboardShow');
     }
   
     private showHighWindow() {
       let win = windowManager.findWindow(this.windowName)
       win.resize(this.windowWidth, this.windowHeight).then(() => {
         win.moveWindowTo(0, this.nonBarPosition).then(() => {
           win.showWindow().then(() => {
             this.isWindowShowing = false;
           })
         })
       })
     }
   }
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
   import { numberSourceListData, sourceListType } from './keyboardKeyData'
   
   @Component
   struct keyItem {
     private keyValue: sourceListType
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
       .onTouch((event: TouchEvent) => {
         if (event.type === TouchType.Down) {
           globalThis.textInputClient.insertText(this.keyValue.content);
         }
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
       .onTouch((event: TouchEvent) => {
         if (event.type === TouchType.Down) {
           globalThis.textInputClient.deleteForward(1);
         }
       })
     }
   }
   
   // 数字键盘
   @Component
   struct numberMenu {
     private numberList: sourceListType[]
   
     build() {
       Flex({ direction: FlexDirection.Column, alignItems: ItemAlign.Center, justifyContent: FlexAlign.SpaceEvenly }) {
         Flex({ justifyContent: FlexAlign.SpaceBetween }) {
           ForEach(this.numberList, (item: sourceListType) => {  // 数字键盘第一行
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

   ```ts
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


