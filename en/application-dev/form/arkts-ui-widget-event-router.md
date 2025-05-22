# Launching the UIAbility of the Widget Provider Through the router Event

The **router** capability of the [postCardAction](../reference/apis-arkui/js-apis-postCardAction.md#postcardaction) API can be used in a dynamic widget to quickly start a specific UIAbility of the widget provider. By leveraging this capability, an application can provide in the widget multiple buttons, each of which targets a different target UIAbility. For example, a camera widget can provide the buttons that redirect the user to the UIAbility for taking a photo and the UIAbility for recording a video.

![WidgerCameraCard](figures/WidgerCameraCard.png)

> **NOTE**
>
> This topic describes development for dynamic widgets. For static widgets, see [FormLink](../reference/apis-arkui/arkui-ts/ts-container-formlink.md).

## How to Develop
1. Create a dynamic widget.

   In the **entry** module of the project, create an ArkTS widget named WidgetEventRouterCard.

2. Build the code for the ArkTS widget page layout.

   Design two buttons on the widget page. When one of the buttons is clicked, **postCardAction** is called to send a router event to the specified UIAbility, with the content to be transferred defined in the event.

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

4. Process the router event.

   The UIAbility receives the router event and obtains parameters. It then starts the page specified by **params**.
  
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
         // Obtain the targetPage parameter passed in the router event.
         hilog.info(DOMAIN_NUMBER, TAG, `Ability onCreate: ${JSON.stringify(want?.parameters)}`);
         if (want?.parameters?.params) {
           // want.parameters.params corresponds to params in postCardAction().
           let params: Record<string, Object> = JSON.parse(want.parameters.params as string);
           this.selectPage = params.targetPage as string;
           hilog.info(DOMAIN_NUMBER, TAG, `onCreate selectPage: ${this.selectPage}`);
         }
       }
     
       // If the UIAbility is running in the background, the onNewWant lifecycle callback is triggered after the router event is received.
       onNewWant(want: Want, launchParam: AbilityConstant.LaunchParam): void {
         hilog.info(DOMAIN_NUMBER, TAG, `Ability onNewWant: ${JSON.stringify(want?.parameters)}`);
         if (want?.parameters?.params) {
           // want.parameters.params corresponds to params in postCardAction().
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
         // Start the page specified by targetPage.
         switch (this.selectPage) {
           case 'funA':
             targetPage = 'pages/FunA'; // Use the actual UIAbility page path.
             break;
           case 'funB':
             targetPage = 'pages/FunB'; // Use the actual UIAbility page path.
             break;
           default:
             targetPage = 'pages/Index'; // Use the actual UIAbility page path.
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
5. Create the UIAbility page, which is the target of the redirection.

   Create **FunA.ets** and **FunB.ets** in the **pages** folder to build the page layout.

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

6. Register the UIAbility pages.

   Open the **main_pages.json** file and register **FunA.ets** and **FunB.ets** in the **src** array.
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
