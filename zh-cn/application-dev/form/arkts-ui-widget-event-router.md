# 卡片跳转到应用页面（router事件）

在动态卡片中使用[postCardAction](../reference/apis-arkui/js-apis-postCardAction.md#postcardaction-1)接口的router能力，能够快速拉起动态卡片提供方应用的指定UIAbility(页面)，因此UIAbility较多的应用往往会通过卡片提供不同的跳转按钮，实现一键直达的效果。例如相机卡片，卡片上提供拍照、录像等按钮，点击不同按钮将拉起相机应用的不同UIAbility，从而提高用户的体验。

![WidgerCameraCard](figures/WidgerCameraCard.png)

> **说明：**
>
> 本文主要介绍动态卡片的事件开发。对于静态卡片，请参见[FormLink](../reference/apis-arkui/arkui-ts/ts-container-formlink.md)。

## 开发步骤
1. 创建动态卡片

   在工程的 entry 模块中，新建名为WidgetEventRouterCard的ArkTs卡片。

2. 构建ArkTs卡片页面代码布局

   卡片页面布局中有两个按钮，点击其中一个按钮时调用postCardAction向指定UIAbility发送router事件，并在事件内定义需要传递的内容。

    ```ts
    //src/main/ets/widgeteventroutercard/pages/WidgetEventRouterCard.ets
    @Entry
    @Component
    struct WidgetEventRouterCard {
      build() {
        Column() {
          Text($r('app.string.JumpLabel'))
            .fontColor('#FFFFFF')
            .opacity(0.9)
            .fontSize(14)
            .margin({ top: '8%', left: '10%' })
          Row() {
            Column() {
              Button() {
                Text($r('app.string.ButtonA_label'))
                  .fontColor('#45A6F4')
                  .fontSize(12)
              }
              .width(120)
              .height(32)
              .margin({ top: '20%' })
              .backgroundColor('#FFFFFF')
              .borderRadius(16)
              .onClick(() => {
                postCardAction(this, {
                  action: 'router',
                  abilityName: 'EntryAbility',
                  params: { targetPage: 'funA' }
                });
              })
    
              Button() {
                Text($r('app.string.ButtonB_label'))
                  .fontColor('#45A6F4')
                  .fontSize(12)
              }
              .width(120)
              .height(32)
              .margin({ top: '8%', bottom: '15vp' })
              .backgroundColor('#FFFFFF')
              .borderRadius(16)
              .onClick(() => {
                postCardAction(this, {
                  action: 'router',
                  abilityName: 'EntryAbility',
                  params: { targetPage: 'funB' }
                });
              })
            }
          }.width('100%').height('80%')
          .justifyContent(FlexAlign.Center)
        }
        .width('100%')
        .height('100%')
        .alignItems(HorizontalAlign.Start)
        .backgroundImage($r('app.media.CardEvent'))
        .backgroundImageSize(ImageSize.Cover)
      }
    }
    ```

4. 处理router事件

   在UIAbility中接收router事件并获取参数，根据传递的params不同，选择拉起不同的页面。
  
     ```ts
     //src/main/ets/entryability/EntryAbility.ets
     import { AbilityConstant, UIAbility, Want } from '@kit.AbilityKit';
     import { window } from '@kit.ArkUI';
     import { hilog } from '@kit.PerformanceAnalysisKit';
     
     const TAG: string = 'EntryAbility';
     const DOMAIN_NUMBER: number = 0xFF00;
   
     export default class EntryAbility extends UIAbility {
       private selectPage: string = '';
       private currentWindowStage: window.WindowStage | null = null;
     
       onCreate(want: Want, launchParam: AbilityConstant.LaunchParam): void {
         // 获取router事件中传递的targetPage参数
         hilog.info(DOMAIN_NUMBER, TAG, `Ability onCreate: ${JSON.stringify(want?.parameters)}`);
         if (want?.parameters?.params) {
           // want.parameters.params 对应 postCardAction() 中 params 内容
           let params: Record<string, Object> = JSON.parse(want.parameters.params as string);
           this.selectPage = params.targetPage as string;
           hilog.info(DOMAIN_NUMBER, TAG, `onCreate selectPage: ${this.selectPage}`);
         }
       }
     
       // 如果UIAbility已在后台运行，在收到Router事件后会触发onNewWant生命周期回调
       onNewWant(want: Want, launchParam: AbilityConstant.LaunchParam): void {
         hilog.info(DOMAIN_NUMBER, TAG, `Ability onNewWant: ${JSON.stringify(want?.parameters)}`);
         if (want?.parameters?.params) {
           // want.parameters.params 对应 postCardAction() 中 params 内容
           let params: Record<string, Object> = JSON.parse(want.parameters.params as string);
           this.selectPage = params.targetPage as string;
           hilog.info(DOMAIN_NUMBER, TAG, `onNewWant selectPage: ${this.selectPage}`);
         }
         if (this.currentWindowStage !== null) {
           this.onWindowStageCreate(this.currentWindowStage);
         }
       }
     
       onWindowStageCreate(windowStage: window.WindowStage): void {
         // Main window is created, set main page for this ability
         let targetPage: string;
         // 根据传递的targetPage不同，选择拉起不同的页面
         switch (this.selectPage) {
           case 'funA':
             targetPage = 'pages/FunA'; //与实际的UIAbility页面路径保持一致
             break;
           case 'funB':
             targetPage = 'pages/FunB'; //与实际的UIAbility页面路径保持一致
             break;
           default:
             targetPage = 'pages/Index'; //与实际的UIAbility页面路径保持一致
         }
         if (this.currentWindowStage === null) {
           this.currentWindowStage = windowStage;
         }
         windowStage.loadContent(targetPage, (err, data) => {
           if (err.code) {
             hilog.error(DOMAIN_NUMBER, TAG, 'Failed to load the content. Cause: %{public}s', JSON.stringify(err) ?? '');
             return;
           }
           hilog.info(DOMAIN_NUMBER, TAG, 'Succeeded in loading the content. Data: %{public}s', JSON.stringify(data) ?? '');
         });
       }
     }
     ```
5. 创建跳转后的UIAbility页面

   在pages文件夹下新建FunA.ets和FunB.ets，构建页面布局。

    ```ts
   //src/main/ets/pages/FunA.ets
    @Entry
    @Component
    struct FunA {
      @State message: string = 'Hello World';
    
      build() {
        RelativeContainer() {
          Text(this.message)
            .id('HelloWorld')
            .fontSize(50)
            .fontWeight(FontWeight.Bold)
            .alignRules({
              center: { anchor: '__container__', align: VerticalAlign.Center },
              middle: { anchor: '__container__', align: HorizontalAlign.Center }
            })
        }
        .height('100%')
        .width('100%')
      }
    }
    ```

6. 注册UIAbility页面

   打开main_pages.json，将新建的FunA.ets和FunB.ets正确注册在src数组中。
   ```ts
   //src/main/resources/base/profile/main_pages.json
   {
     "src": [
       "pages/Index",
       "pages/FunA",
       "pages/FunB"
     ]
   }
    ```