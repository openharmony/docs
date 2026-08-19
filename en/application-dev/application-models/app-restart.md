# App Restart

<!--Kit: Ability Kit-->
<!--Subsystem: Ability-->
<!--Owner: @wendel-->
<!--Designer: @wendel-->
<!--Tester: @liangchengguang-->
<!--Adviser: @HelloCrease-->
<!-- md-trans-meta sourceCommit=4e0381b7e020c41db397612c40b40dfd307459e8 translatedAt=2026-08-18T01:28:31.531Z pushedAt=2026-08-18T03:50:13.252Z -->

App restart is used to reinitialize an app or restore its normal state in different scenarios. The system provides proactive app restart, proactive atomic service restart, and passive app restart for fault recovery. Developers can select an appropriate solution based on actual requirements.

## App Proactive Restart for Reinitialization

The system provides two ways to proactively restart an app: restart without retaining the application window and restart with the application window retained. The following table compares the capabilities of the two proactive restart methods. You can select a method based on your service requirements.

| Comparison Dimension | Restart Without Retaining the Application Window | Restart with the Application Window Retained |
| --------- | ------------------- | ----------------- |
| Applicable Scenario | The app encounters an internal state issue and needs complete reinitialization; the app completes a dynamic update and needs to start from the initial state. | The app encounters an internal state issue and needs complete reinitialization without exposing the home screen; the app completes a dynamic update and needs to start from the initial state without exposing the home screen. |
| User Experience | Lacks continuity; the user view shows the home screen. The user may experience a sense of interruption. | Provides continuity; the user view stays on the app. This avoids a sense of interruption in the user experience. |
| API | ApplicationContext.restartApp<sup>12+</sup> | UIAbilityContext.restartApp<sup>22+</sup> |

### Restart Without Retaining the Application Window

Since API version 12, ApplicationContext provides the [restartApp](../reference/apis-ability-kit/js-apis-inner-application-applicationContext.md#applicationcontextrestartapp12) API to proactively restart the app and start the specified UIAbility. The current application window is not retained during the restart, which is equivalent to completely restarting the app. The onDestroy lifecycle callback of the Ability in the app is not triggered during the restart.

The following constraints and limitations apply:

- This API can be called only from the main thread.

- The app to be restarted must be in the focused state.

- Repeatedly calling the restart API within 3 seconds is not supported.

Sample code:

<!-- @[restartapp_withoutWindow](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Ability/restartapp/entry/src/main/ets/pages/Index.ets) --> 

``` TypeScript
import { hilog } from '@kit.PerformanceAnalysisKit';
import { common, Want } from '@kit.AbilityKit';

@Entry
@Component
struct Index {
  @State message: string = 'restartApp';
  private context = this.getUIContext().getHostContext()?.getApplicationContext() as common.ApplicationContext;

  build() {
    RelativeContainer() {
      Button(this.message)
        .id('HelloWorld')
        .fontSize($r('app.float.page_text_font_size'))
        .fontWeight(FontWeight.Bold)
        .alignRules({
          center: { anchor: '__container__', align: VerticalAlign.Center },
          middle: { anchor: '__container__', align: HorizontalAlign.Center }
        })
        .onClick(() => {
          let want: Want = {
            bundleName: 'com.example.restartapp',
            abilityName: 'EntryAbility'
          };
          if (this.context) {
            try {
              this.context.restartApp(want);
            } catch (err) {
              hilog.error(0x0000, 'testTag', `restart failed: ${err.code}, ${err.message}`);
            }
          } else {
            hilog.error(0x0000, 'testTag', "%{public}s", 'AppContext is null');
          }
        })
    }
    .height('100%')
    .width('100%')
  }
}
```

### Restarting with the Application Window Retained

Since API version 22, UIAbilityContext provides the [restartApp](../reference/apis-ability-kit/js-apis-inner-application-uiAbilityContext.md#restartapp22) API, which restarts the process where the current UIAbility resides and starts a specified UIAbility in the app. Unlike the restartApp API of ApplicationContext, this API allows you to retain the current window or switch to a new window. During the restart, the onDestroy lifecycle callback of the Ability in the process is not triggered.

The following constraints and limitations apply:

- This API can be called only from the main thread.

- The app to be restarted must be in the focused state.

- Repeatedly calling the restart API within 3 seconds is not supported.

Sample code:

1. Specify the current UIAbility to refresh the current window to its initial state after the restart.

   <!-- @[restartapp_withOldWindow](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Ability/restartapp/entry/src/main/ets/pages/Index2.ets) --> 

   ``` TypeScript
   import { hilog } from '@kit.PerformanceAnalysisKit';
   import { common, Want } from '@kit.AbilityKit';
   
   @Entry
   @Component
   struct Index {
     @State message: string = 'restartApp with window';
   
     build() {
       RelativeContainer() {
         Button(this.message)
           .id('HelloWorld')
           .fontSize($r('app.float.page_text_font_size'))
           .fontWeight(FontWeight.Bold)
           .alignRules({
             center: { anchor: '__container__', align: VerticalAlign.Center },
             middle: { anchor: '__container__', align: HorizontalAlign.Center }
           })
           .onClick(async () => {
             // Specify the current UIAbility and refresh the current window.
             let want: Want = {
               bundleName: 'com.example.restartapp',
               abilityName: 'EntryAbility'
             };
             let context = this.getUIContext().getHostContext() as common.UIAbilityContext;
             try {
               await context.restartApp(want);
               hilog.info(0x0000, 'testTag', 'restart success');
             } catch (err) {
               hilog.error(0x0000, 'testTag', `restart failed: ${err.code}, ${err.message}`);
             }
           })
       }
       .height('100%')
       .width('100%')
     }
   }
   ```

2. Specify another UIAbility in the app to jump to and open a new Ability window after the restart.

   <!-- @[restartapp_withNewWindow](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Ability/restartapp/entry/src/main/ets/pages/Index3.ets) --> 

   ``` TypeScript
   import { hilog } from '@kit.PerformanceAnalysisKit';
   import { common, Want } from '@kit.AbilityKit';
   
   @Entry
   @Component
   struct Index {
     @State message: string = 'restartApp to new page';
   
     build() {
       RelativeContainer() {
         Button(this.message)
           .id('HelloWorld')
           .fontSize($r('app.float.page_text_font_size'))
           .fontWeight(FontWeight.Bold)
           .alignRules({
             center: { anchor: '__container__', align: VerticalAlign.Center },
             middle: { anchor: '__container__', align: HorizontalAlign.Center }
           })
           .onClick(async () => {
             // Specify another UIAbility in the application and jump to a new window.
             let want: Want = {
               bundleName: 'com.example.restartapp',
               abilityName: 'SecondAbility'
             };
             let context = this.getUIContext().getHostContext() as common.UIAbilityContext;
             try {
               await context.restartApp(want);
               hilog.info(0x0000, 'testTag', 'restart success');
             } catch (err) {
               hilog.error(0x0000, 'testTag', `restart failed: ${err.code}, ${err.message}`);
             }
           })
       }
       .height('100%')
       .width('100%')
     }
   }
   ```

## Active Restart of an Atomic Service

Since API version 20, the system provides a dedicated restart API [restartSelfAtomicService](../reference/apis-ability-kit/js-apis-app-ability-abilityManager.md#abilitymanagerrestartselfatomicservice20) for atomic services, which is used to trigger an atomic service update and restart the current atomic service. During the restart, the current atomic service window is not retained, and the onDestroy lifecycle callback of the old Ability is not triggered.

The following constraints and limitations apply:

- Only atomic services launched in standalone window mode are supported.

- Repeatedly calling the restart API within 3 seconds is not supported.

An atomic service is a special form of an app and can also be restarted by following [App Proactive Restart for Reinitialization](#app-proactive-restart-for-reinitialization).

The following table compares the capabilities of the three methods for proactively restarting an atomic service. You can choose a method based on your service requirements.

| Comparison Dimension | Atomic Service Proactive Restart | Restart Without Retaining the Atomic Service Window | Restart While Retaining the Atomic Service Window |
| --------- | ----------------  | ------------------- | ----------------- |
| Applicable Scenario | The atomic service proactively triggers an update and reinitializes itself; the atomic service encounters an internal state issue and needs a complete reinitialization. | The atomic service encounters an internal state issue and needs a complete reinitialization; the atomic service completes a dynamic update and needs to start from the initial state. | The atomic service encounters an internal state issue and needs a complete reinitialization without exposing the home screen; the atomic service completes a dynamic update and needs to start from the initial state without exposing the home screen. |
| User Experience | Not continuous; the home screen is visible in the user view. The user may feel a sense of discontinuity. | Not continuous; the home screen is visible in the user view. The user may feel a sense of discontinuity. | Continuous; the user view stays on the app. This avoids a sense of discontinuity for the user. |
| Update Without Installation | Supported                          | Not supported                           | Not supported                      |
| API | AbilityManager.restartSelfAtomicService<sup>20+</sup> | ApplicationContext.restartApp<sup>12+</sup> | UIAbilityContext.restartApp<sup>22+</sup> |

Sample code:

``` TypeScript
import { AbilityConstant, EmbeddableUIAbility, Want, abilityManager } from '@kit.AbilityKit';
import { hilog } from '@kit.PerformanceAnalysisKit';
import { BusinessError } from '@kit.BasicServicesKit';

const DOMAIN = 0x0000;

export default class DemoAbility extends EmbeddableUIAbility {
  onCreate(want: Want, launchParam: AbilityConstant.LaunchParam): void {
    hilog.info(DOMAIN, 'DemoAbility', 'DemoAbility onCreate');
    try {
      // Trigger the current atomic service restart.
      abilityManager.restartSelfAtomicService(this.context);
      hilog.info(DOMAIN, 'DemoAbility', 'restartSelfAtomicService success');
    } catch (e) {
      hilog.error(DOMAIN, 'DemoAbility', `restartSelfAtomicService error: ${JSON.stringify(e as BusinessError)}`);
    }
  }
}
```

## Passive Restart for App Fault Recovery

The app fault recovery restart APIs are provided by the appRecovery module. For details, see [App Recovery Development Guide](../dfx/apprecovery-guidelines.md).