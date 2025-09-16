# Environment: Querying the Device Environment
<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @zzq212050299-->
<!--Designer: @s10021109-->
<!--Tester: @TerryTsao-->
<!--Adviser: @zhang_yixin13-->

You may want your application to behave differently based on the device environment where the application is running, for example, switching to dark mode or a specific language. In this case, you need the **Environment** API for device environment query.

**Environment** is a singleton object created by the ArkUI framework during application launch, providing AppStorage with immutable primitive-type properties reflecting the application's runtime state.

The **Environment** API enables reading system environment variables and writing their values to AppStorage. You must access these values through AppStorage. For details, see [Environment Built-in Parameters](#environment-built-in-parameters).

Before reading this topic, you are advised to read [AppStorage](./arkts-appstorage.md).

## Environment Built-in Parameters

| Key| Data Type| Description                                     |
| ------------------ | ------------------ | ------------------ |
| accessibilityEnabled              | boolean                  | Whether to enable screen reader accessibility. The value **true** means to enable screen reader accessibility, and **false** means the opposite.|
| colorMode              | ColorMode                  | Color mode.<br>- **ColorMode.LIGHT**: light color mode.<br>- **ColorMode.DARK**: dark color mode.                |
| fontScale              | number                  | Font scale. To enable the font scale to change with the system, set the [configuration](../../quick-start/app-configuration-file.md#configuration) tag.<br>The default value follows the default system settings.               |
| fontWeightScale              | number                  | Font weight. The value range varies by system or device model.<br>The default value follows the default system settings.               |
| layoutDirection              | LayoutDirection                  | Layout direction.<br>**LayoutDirection.LTR**: from left to right.<br>**LayoutDirection.RTL**: from right to left.                |
| languageCode              | string                  | System language code. The value must be in lowercase, for example, **zh**.<br>The default value follows the default system settings.                |

## Use Scenarios

### Accessing Environment Parameters from the UI

- Use Environment.[envProp](../../reference/apis-arkui/arkui-ts/ts-state-management.md#envprop10) to store device environment variables in AppStorage.

  ```ts
  // Store languageCode (default value: en) to AppStorage.
  Environment.envProp('languageCode', 'en');
  ```

- Decorate the variables with \@StorageProp to link them with components.

  ```ts
  @StorageProp('languageCode') lang: string = 'en';
  ```

The chain of updates is as follows: Environment > AppStorage > Component.

> **NOTE**
>
> An \@StorageProp decorated variable can be locally modified, but the change will not be updated to AppStorage. This is because environment variables are read-only.

```ts
// Store languageCode to AppStorage.
Environment.envProp('languageCode', 'en');

@Entry
@Component
struct Index {
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

```ts
// Store languageCode to AppStorage.
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

**Environment** can be called only when the [UIContext](../../reference/apis-arkui/arkts-apis-uicontext-uicontext.md) is specified. You can specify the context in [runScopedTask](../../reference/apis-arkui/arkts-apis-uicontext-uicontext.md#runscopedtask). If **Environment** is called without explicit **UIContext**, no device environment data can be obtained.

```ts
// EntryAbility.ets
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
