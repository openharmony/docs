# Redirecting to a UIAbility Through the router Event

The **router** capability of the **postCardAction** API can be used in a widget to quickly start a specific UIAbility of the widget provider. By leveraging this capability, an application can provide in the widget multiple buttons, each of which targets a different target UIAbility. For example, a camera widget can provide the buttons that redirect the user to the UIAbility for taking a photo and the UIAbility for recording a video.

![WidgerCameraCard](figures/WidgerCameraCard.png)

> **NOTE**
>
> This topic describes development for dynamic widgets. For static widgets, see [FormLink](../reference/arkui-ts/ts-container-formlink.md).


Generally, a button is used to start a page. Below is an example:


- Design two buttons on the widget page. When one of the buttons is clicked, **postCardAction** is called to send a router event to the specified UIAbility, with the content to be transferred defined in the event.
  
  ```ts
  @Entry
  @Component
  struct WidgetCard {
    build() {
      Column() {
        Button ('Function A')
          .onClick(() => {
            console.info('Jump to EntryAbility funA');
            postCardAction(this, {
              action: 'router',
              abilityName: 'EntryAbility', // Only the UIAbility of the current application is allowed.
              params: {
                targetPage: 'funA' // Process the information in the EntryAbility.
              }
            });
          })
  
        Button ('Function B')
          .onClick(() => {
            console.info('Jump to EntryAbility funB');
            postCardAction(this, {
              action: 'router',
              abilityName: 'EntryAbility', // Only the UIAbility of the current application is allowed.
              params: {
                targetPage: 'funB' // Process the information in the EntryAbility.
              }
            });
          })
      }
      .width('100%')
      .height('100%').justifyContent(FlexAlign.SpaceAround)
    }
  }
  ```

- The UIAbility receives the router event and obtains parameters. It then starts the page specified by **params**.
  
  ```ts
  import UIAbility from '@ohos.app.ability.UIAbility';
  import window from '@ohos.window';
  import Want from '@ohos.app.ability.Want';
  import Base from '@ohos.base';
  import AbilityConstant from '@ohos.app.ability.AbilityConstant';
  
  let selectPage: string = "";
  let currentWindowStage: window.WindowStage | null = null;

  export default class EntryAbility extends UIAbility {
    // If the UIAbility is started for the first time, the onCreate lifecycle callback is triggered after the router event is received.
    onCreate(want: Want, launchParam: AbilityConstant.LaunchParam) {
      // Obtain the targetPage parameter passed in the router event.
      console.info("onCreate want:" + JSON.stringify(want));
      if (want.parameters?.params !== undefined) {
        let params: Record<string, string> = JSON.parse(want.parameters?.params.toString());
        console.info("onCreate router targetPage:" + params.targetPage);
        selectPage = params.targetPage;
      }
    }
    // If the UIAbility is running in the background, the onNewWant lifecycle callback is triggered after the router event is received.
    onNewWant(want: Want, launchParam: AbilityConstant.LaunchParam) {
      console.info("onNewWant want:" + JSON.stringify(want));
      if (want.parameters?.params !== undefined) {
        let params: Record<string, string> = JSON.parse(want.parameters?.params.toString());
        console.info("onNewWant router targetPage:" + params.targetPage);
        selectPage = params.targetPage;
      }
      if (currentWindowStage != null) {
        this.onWindowStageCreate(currentWindowStage);
      }
    }

    onWindowStageCreate(windowStage: window.WindowStage) {
      let targetPage: string;
      // Start the page specified by targetPage.
      switch (selectPage) {
        case 'funA':
          targetPage = 'pages/FunA';
          break;
        case 'funB':
          targetPage = 'pages/FunB';
          break;
        default:
          targetPage = 'pages/Index';
      }
      if (currentWindowStage === null) {
        currentWindowStage = windowStage;
      }
      windowStage.loadContent(targetPage, (err: Base.BusinessError) => {
        if (err && err.code) {
          console.info('Failed to load the content. Cause: %{public}s', JSON.stringify(err));
          return;
        }
      });
    }
  };
  ```
