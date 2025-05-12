# Environment: Device Environment Query


If you need the environment parameters of the device where the application runs to set different scenarios, such as multi-language support and dark/light color mode, use Environment to query the parameters.


Environment is a singleton object created by the ArkUI framework at application startup. It provides a range of application state attributes to AppStorage that describe the device environment in which the application is running. Environment and its attributes are immutable. All property values are of simple types only.


Environment provides the capability of reading some environment variables of the system (for details, see [Environment Built-in Parameters](#environment-built-in-parameters)) and writing the values of the variables to AppStorage. Therefore, you can use AppStorage to obtain the values of environment variables.

Before reading this topic, you are advised to read [AppStorage](./arkts-appstorage.md).

## Environment Built-in Parameters

| Key| Data Type| Description                                     |
| ------------------ | ------------------ | ------------------ |
| accessibilityEnabled              | boolean                  | Whether to enable accessibility.                |
| colorMode              | ColorMode                  | Color mode. The options are as follows:<br>- **ColorMode.LIGHT**: light mode.<br>- **ColorMode.DARK**: dark mode.                |
| fontScale              | number                  | Font scale. To enable the font scale to change with the system, set the [configuration](./app-configuration-file.md#configuration) tag.               |
| fontWeightScale              | number                  | Font weight.               |
| layoutDirection              | LayoutDirection                  | Layout direction. The options are as follows:<br>- **LayoutDirection.LTR**: from left to right.<br>- **LayoutDirection.RTL**: from right to left.                |
| languageCode              | string                  | System language value. The value must be in lowercase, for example, **zh**.                |


## Use Scenarios


### Accessing Environment Parameters from UI

- Use **Environment.envProp** to save the environment variables of the device to AppStorage.

  ```ts
  // Save languageCode to AppStorage. The default value is en.
  Environment.envProp('languageCode', 'en');
  ```

- Decorate the variables with \@StorageProp to link them with components.

  ```ts
  @StorageProp('languageCode') lang: string = 'en';
  ```

The chain of updates is as follows: Environment > AppStorage > Component.

> **NOTE**
>
> An \@StorageProp decorated variable can be locally modified, but the change will not be updated to AppStorage. This is because the environment variable parameters are read-only to the application.


```ts
// Save the device language code to AppStorage.
Environment.envProp('languageCode', 'en');

@Entry
@Component
struct Index {
  @StorageProp('languageCode') languageCode: string = 'en';

  build() {
    Row() {
      Column() {
        // Output the current device language code.
        Text(this.languageCode)
      }
    }
  }
}
```


### Using Environment in Application Logic


```ts
// Use Environment.envProp to save the device language code to AppStorage.
Environment.envProp('languageCode', 'en');
// Obtain the one-way bound languageCode variable from AppStorage.
const lang: SubscribedAbstractProperty<string> = AppStorage.prop('languageCode');

if (lang.get() === 'en') {
  console.info('Hi');
} else {
  console.info('Bonjour');
}
```


## Constraints


Environment can be called only when the [UIContext](../reference/apis-arkui/js-apis-arkui-UIContext.md#uicontext) is specified. The UIContext is specified when [runScopedTask](../reference/apis-arkui/js-apis-arkui-UIContext.md#runscopedtask) is called. If Environment is called otherwise, no device environment data can be obtained.


```ts
// EntryAbility.ets
import { UIAbility } from '@kit.AbilityKit';
import { window } from '@kit.ArkUI';

export default class EntryAbility extends UIAbility {
  onWindowStageCreate(windowStage: window.WindowStage) {
    windowStage.loadContent('pages/Index');
    let window = windowStage.getMainWindow()
    window.then(window => {
      let uicontext = window.getUIContext()
      uicontext.runScopedTask(() => {
        Environment.envProp('languageCode', 'en');
      })
    })
  }
}
```
