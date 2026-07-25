# Environment: Querying the Device Environment
<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @zzq212050299-->
<!--Designer: @s10021109-->
<!--Tester: @TerryTsao-->
<!--Adviser: @zhang_yixin13-->

You may want your application to behave differently based on the device environment where the application is running, for example, switching to dark mode or a specific language. In this case, you need the **Environment** API for device environment query.

The **Environment** API is a singleton object created by the ArkUI framework at application startup, providing [AppStorage](./arkts-appstorage.md) with immutable primitive-type properties reflecting the application's runtime state.

The **Environment** API enables reading system environment variables and writing their values to AppStorage. You must access these values through AppStorage. For details, see [Environment Built-in Parameters](#environment-built-in-parameters).

Before reading this topic, you are advised to read [AppStorage](./arkts-appstorage.md).

## Environment Built-in Parameters

| Key| Data Type| Description                                     |
| ------------------ | ------------------ | ------------------ |
| accessibilityEnabled              | string                  | Whether to enable screen reader accessibility. **true**: enable; **false**: disable.|
| colorMode              | [ColorMode](../../reference/apis-arkui/arkui-ts/ts-state-management-environment-variables.md#colormode)                  | Color mode.<br>- **ColorMode.LIGHT**: light color mode.<br>- **ColorMode.DARK**: dark color mode.                |
| fontScale              | number                  | Font scale. To enable the font scale to change with the system, set the [configuration](../../quick-start/app-configuration-file.md#configuration) tag.<br>The default value follows the default system settings.               |
| fontWeightScale              | number                  | Font weight scale. The value range varies by system or device model.<br>The default value follows the default system settings.               |
| layoutDirection              | [LayoutDirection](../../reference/apis-arkui/arkui-ts/ts-state-management-environment-variables.md#layoutdirection)                  | Layout direction.<br>**LayoutDirection.LTR**: from left to right.<br>**LayoutDirection.RTL**: from right to left.                |
| languageCode              | string                  | System language code. The value must be in lowercase, for example, **zh**.<br>The default value follows the default system settings.                |

## Constraints

**Environment** can be called only when [UIContext](../../reference/apis-arkui/arkts-apis-uicontext-uicontext.md) is specified. You call this API inside [runScopedTask](../../reference/apis-arkui/arkts-apis-uicontext-uicontext.md#runscopedtask) to make context explicit. If the call is not made in a location where the UI context is explicit\, no device environment data can be obtained.
  <!-- @[limiting_condition](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/EnvironmentProject/entry/src/main/ets/entryability/EntryAbilityDemo.ets) -->
  
  ``` TypeScript
  import { UIAbility } from '@kit.AbilityKit';
  import { window } from '@kit.ArkUI';
  
  export default class EntryAbility extends UIAbility {
    onWindowStageCreate(windowStage: window.WindowStage) {
      windowStage.loadContent('pages/Index');
      let window = windowStage.getMainWindow();
      window.then(window => {
        let uiContext = window.getUIContext();
        uiContext.runScopedTask(() => {
          Environment.envProp('languageCode', 'en');
        });
      });
    }
  }
  ```

## Use Scenarios

### Accessing Environment Parameters from the UI

- Use Environment.[envProp](../../reference/apis-arkui/arkui-ts/ts-state-management.md#envprop10) to store device environment variables in AppStorage.

  <!-- @[showfirst_details](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/EnvirommentProjet/entry/src/main/ets/pages/ShowDetails.ets) -->
  
  ``` TypeScript
  // Store languageCode to AppStorage. The default value is en.
  Environment.envProp('languageCode', 'en');
  ```

- Obtain the value of **languageCode** through @StorageProp in the custom component.

  <!-- @[showsecond_details](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/EnvirommentProjet/entry/src/main/ets/pages/ShowDetails.ets) -->
  
  ``` TypeScript
  @StorageProp('languageCode') lang: string = 'en';
  ```

The chain of updates is as follows: Environment > AppStorage > Component.

> **NOTE**
>
> The application cannot modify environment variables. Therefore, @StorageProp is used to obtain them. In this way, even if environment variables are modified in the component, the modification is not synchronized back to AppStorage, affecting the result of obtaining the environment variables in other components.
  <!-- @[ui_Environment](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/EnvirommentProjet/entry/src/main/ets/pages/UiEnvironment.ets) -->
  
  ``` TypeScript
  // Store languageCode to AppStorage.
  Environment.envProp('languageCode', 'en');
  
  @Entry
  @Component
  struct UiEnvironment {
    @StorageProp('languageCode') languageCode: string = 'en';
  
    build() {
      Row() {
        Column() {
          // Obtain the current device language code.
          Text(this.languageCode)
        }
      }
    }
  }
  ```

### Using Environment in Application Logic
  <!-- @[applied_logic](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/EnvirommentProjet/entry/src/main/ets/pages/AppliedLogic.ets) -->
  
  ``` TypeScript
  import { hilog } from '@kit.PerformanceAnalysisKit';
  
  const DOMAIN = 0x0001;
  const TAG = 'environmentalProject';
  
  // Store languageCode to AppStorage.
  Environment.envProp('languageCode', 'en');
  // Obtain the one-way bound languageCode variable from AppStorage.
  const lang: SubscribedAbstractProperty<string> = AppStorage.prop('languageCode');
  
  if (lang.get() === 'en') {
    // Replace $r('app.string.AppliedLogic_Hello') with the actual resource file. In this example, the value in the resource file is 'Hello!'.
    hilog.info(DOMAIN, TAG, `${$r('app.string.AppliedLogic_Hello')}`);
  } else {
    hilog.info(DOMAIN, TAG, 'Hello!');
  }
  ```
