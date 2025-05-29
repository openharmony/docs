# Editing and Updating the Widget Content

The home screen provides a unified widget editing page. The widget provider uses [FormEditExtensionAbility](../reference/apis-form-kit/js-apis-app-form-formEditExtensionAbility.md) provided by the widget framework to develop the widget editing function.

## How to Develop
1. In the entry module of the project, create a code file named EntryFormEditAbility. In the EntryFormEditAbility file, implement the [startSecondPage](../reference/apis-form-kit/js-apis-inner-application-formEditExtensionContext.md#startsecondpage) method. In the [onSessionCreate](../reference/apis-form-kit/js-apis-app-form-formEditExtensionAbility.md#onsessioncreate) callback method, load the level-1 widget editing page and transfer the implementation of the **startSecondPage** method to the level-1 widget editing page.

```ts
// src/main/ets/entryformeditability/EntryFormEditAbility.ets

import { FormEditExtensionAbility } from '@kit.FormKit';
import { Want,UIExtensionContentSession } from '@kit.AbilityKit';
import { ExtensionEvent } from '../pages/model/ExtensionEvent';

const TAG: string = 'FormEditDemo[EntryFormEditAbility] -->';
export default class EntryFormEditAbility extends FormEditExtensionAbility {
  onCreate() {
    console.log(`${TAG} onCreate`);
  }
  onForeground(): void {
    console.log(`${TAG} EntryFormEditAbility onForeground.....`);
  }
  onBackground(): void {
    console.log(`${TAG} EntryFormEditAbility onBackground......`);
  }
  onDestroy(): void {
    console.log(`${TAG} EntryFormEditAbility onDestroy......`);
  }
  onSessionCreate(want: Want, session: UIExtensionContentSession) {
    console.log(`${TAG} onSessionCreate start..... want: ${JSON.stringify(want)}`);
    let storage: LocalStorage = new LocalStorage();
    let extensionEvent: ExtensionEvent = new ExtensionEvent();
    extensionEvent.setStartSecondPage(() => this.startSecondPage());
    storage.setOrCreate('extensionEvent', extensionEvent);
    try {
      session.loadContent('pages/Extension', storage);
      session.setWindowBackgroundColor('#00000000');
    } catch (e) {
      console.log(`${TAG} EntryFormEditAbility loadContent err, want: ${JSON.stringify(e)}`);
    }
  }
  onSessionDestroy(session: UIExtensionContentSession) {
    console.log(`${TAG} onSessionDestroy`);
  }
  private startSecondPage(): void {
    const bundleName: string = this.context.extensionAbilityInfo.bundleName;
    const secPageAbilityName: string = 'FormEditSecPageAbility';
    console.log(`${TAG} startSecondPage. bundleName: ${bundleName}, secPageAbilityName: ${secPageAbilityName}.`);
    try {
      this.context.startSecondPage({
        bundleName: bundleName,
        parameters: {
          "secPageAbilityName": secPageAbilityName
        }
      });
    } catch (err) {
      console.log(`${TAG} startSecondPage failed: ${err}`);
    }
  }
};
```

2. Add an extension file to display the level-1 editing page of the widget.

```ts
// src/main/ets/pages/Extension.ets

import { UIExtensionContentSession } from '@kit.AbilityKit';
import { ExtensionEvent } from './model/ExtensionEvent';

let storage = LocalStorage.getShared();
const TAG: string = 'FormEditDemo[Extension] -->';
@Entry(storage)
@Component
struct Extension {
  @State message: string = 'UIExtension Provider';
  private session: UIExtensionContentSession | undefined = storage.get<UIExtensionContentSession>('session');
  private extensionEvent: ExtensionEvent | undefined = storage.get<ExtensionEvent>('extensionEvent');
  onPageShow() {
    console.log(`${TAG} onPageShow. extensionEvent: ${JSON.stringify(this.extensionEvent)}, session: ${JSON.stringify(this.session)}.`);
  }
  build() {
    Row() {
      Column() {
        Text(this.message)
          .fontSize(20)
          .fontWeight(FontWeight.Bold)
          .textAlign(TextAlign.Center)
        Button("Add")
          .width('80%')
          .type(ButtonType.Capsule)
          .margin({
            top: 20
          })
          .onClick(() => {
            console.log(`${TAG} Button onClick`);
            this.extensionEvent?.startFormEditSecondPage();
          })
      }
    }
    .justifyContent(FlexAlign.Center)
    .width('100%')
  }
}
```

3. Add the ExtensionEvent file and use the **startFormEditSecondPage** method to invoke the [startSecondPage](../reference/apis-form-kit/js-apis-inner-application-formEditExtensionContext.md#startsecondpage) method.

```ts
// src/main/ets/widget/pages/model/ExtensionEvent.ets

const TAG: string = 'FormEditDemo[ExtensionEvent] -->';
export class ExtensionEvent {
  private startSecondPage: () => void = () => {
    console.log(`${TAG} startSecondPage is empty!`);
  };
  public setStartSecondPage(startSecondPage: () => void) {
    console.log(`${TAG} setStartSecondPage`);
    this.startSecondPage = startSecondPage;
  }
  public startFormEditSecondPage(): void {
    console.log(`${TAG} startFormEditSecondPage`);
    this.startSecondPage();
  }
}

```

4. Add the widget editing configuration to the [module.json5](../quick-start/module-configuration-file.md) configuration file of the application.

```json
"extensionAbilities": [
  {
    "name": "EntryFormEditAbility",
    "srcEntry": "./ets/entryformeditability/EntryFormEditAbility.ets",
    "type": "formEdit"
  }
]
```

5. Add the formConfigAbility configuration to the [form_config.json](./arkts-ui-widget-configuration.md) configuration file of the widget.

```json
{
  "forms": [
    {
      "name": "widget",
      "displayName": "$string:widget_display_name",
      "description": "$string:widget_desc",
      "src": "./ets/widget/pages/WidgetCard.ets",
      "uiSyntax": "arkts",
      "formConfigAbility": "ability://EntryFormEditAbility",
      "window": {
        "designWidth": 720,
        "autoDesignWidth": true
      },
      "colorMode": "auto",
      "isDynamic": true,
      "isDefault": true,
      "updateEnabled": false,
      "scheduledUpdateTime": "10:30",
      "updateDuration": 1,
      "defaultDimension": "1*2",
      "supportDimensions": [
        "1*2",
        "2*2",
        "2*4",
        "4*4"
      ]
    }
  ]
}
```
6. Register the Extension page file in the **resource/base/profile/main_pages.json** file in the development view.

```json
{
  "src": [
    "pages/Index",
    "pages/Extension"
  ]
}
```
