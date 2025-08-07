# 卡片编辑开发指导
<!--Kit: Form Kit-->
<!--Subsystem: Ability-->
<!--Owner: @cx983299475-->
<!--SE: @xueyulong-->
<!--TSE: @chenmingze-->

桌面提供统一的卡片编辑页，卡片提供方使用卡片框架提供的[FormEditExtensionAbility](../reference/apis-form-kit/js-apis-app-form-formEditExtensionAbility.md)开发卡片编辑功能。

## 开发步骤
1. 在工程的entry模块中，新建名为EntryFormEditAbility的代码文件。在EntryFormEditAbility文件中，实现[startSecondPage](../reference/apis-form-kit/js-apis-inner-application-formEditExtensionContext.md#startsecondpage)方法，在[onSessionCreate](../reference/apis-ability-kit/js-apis-app-ability-uiExtensionAbility.md#onsessioncreate)回调方法中，加载一级卡片编辑页，并将startSecondPage方法的实现传递给一级卡片编辑页。

```ts
// src/main/ets/entryformeditability/EntryFormEditAbility.ets

import { FormEditExtensionAbility } from '@kit.FormKit';
import { Want,UIExtensionContentSession } from '@kit.AbilityKit';
import { ExtensionEvent } from '../pages/model/ExtensionEvent';

const TAG: string = 'FormEditDemo[EntryFormEditAbility] -->';
export default class EntryFormEditAbility extends FormEditExtensionAbility {
  onCreate() {
    console.info(`${TAG} onCreate`);
  }
  onForeground(): void {
    console.info(`${TAG} EntryFormEditAbility onForeground.....`);
  }
  onBackground(): void {
    console.info(`${TAG} EntryFormEditAbility onBackground......`);
  }
  onDestroy(): void {
    console.info(`${TAG} EntryFormEditAbility onDestroy......`);
  }
  onSessionCreate(want: Want, session: UIExtensionContentSession) {
    console.info(`${TAG} onSessionCreate start..... want: ${JSON.stringify(want)}`);
    let storage: LocalStorage = new LocalStorage();
    let extensionEvent: ExtensionEvent = new ExtensionEvent();
    extensionEvent.setStartSecondPage(() => this.startSecondPage());
    storage.setOrCreate('extensionEvent', extensionEvent);
    try {
      session.loadContent('pages/Extension', storage);
      session.setWindowBackgroundColor('#00000000');
    } catch (e) {
      console.error(`${TAG} EntryFormEditAbility loadContent err, want: ${JSON.stringify(e)}`);
    }
  }
  onSessionDestroy(session: UIExtensionContentSession) {
    console.info(`${TAG} onSessionDestroy`);
  }
  private startSecondPage(): void {
    const bundleName: string = this.context.extensionAbilityInfo.bundleName;
    const secPageAbilityName: string = 'FormEditSecPageAbility';
    console.info(`${TAG} startSecondPage. bundleName: ${bundleName}, secPageAbilityName: ${secPageAbilityName}.`);
    try {
      this.context.startSecondPage({
        bundleName: bundleName,
        parameters: {
          "secPageAbilityName": secPageAbilityName
        }
      });
    } catch (err) {
      console.error(`${TAG} startSecondPage failed: ${err}`);
    }
  }
};
```

2. 新增Extension文件，用于展示卡片一级编辑页。

```ts
// src/main/ets/pages/Extension.ets

import { UIExtensionContentSession } from '@kit.AbilityKit';
import { ExtensionEvent } from './model/ExtensionEvent';

let storage = new LocalStorage();
const TAG: string = 'FormEditDemo[Extension] -->';
@Entry(storage)
@Component
struct Extension {
  @State message: string = 'UIExtension Provider';
  private session: UIExtensionContentSession | undefined = storage.get<UIExtensionContentSession>('session');
  private extensionEvent: ExtensionEvent | undefined = storage.get<ExtensionEvent>('extensionEvent');
  onPageShow() {
    console.info(`${TAG} onPageShow. extensionEvent: ${JSON.stringify(this.extensionEvent)}, session: ${JSON.stringify(this.session)}.`);
  }
  build() {
    Row() {
      Column() {
        Text(this.message)
          .fontSize(20)
          .fontWeight(FontWeight.Bold)
          .textAlign(TextAlign.Center)
        Button("添加")
          .width('80%')
          .type(ButtonType.Capsule)
          .margin({
            top: 20
          })
          .onClick(() => {
            console.info(`${TAG} Button onClick`);
            this.extensionEvent?.startFormEditSecondPage();
          })
      }
    }
    .justifyContent(FlexAlign.Center)
    .width('100%')
  }
}
```

3. 新增ExtensionEvent文件，使用startFormEditSecondPage方法调用[startSecondPage](../reference/apis-form-kit/js-apis-inner-application-formEditExtensionContext.md#startsecondpage)方法。

```ts
// src/main/ets/widget/pages/model/ExtensionEvent.ets

const TAG: string = 'FormEditDemo[ExtensionEvent] -->';
export class ExtensionEvent {
  private startSecondPage: () => void = () => {
    console.info(`${TAG} startSecondPage is empty!`);
  };
  public setStartSecondPage(startSecondPage: () => void) {
    console.info(`${TAG} setStartSecondPage`);
    this.startSecondPage = startSecondPage;
  }
  public startFormEditSecondPage(): void {
    console.info(`${TAG} startFormEditSecondPage`);
    this.startSecondPage();
  }
}

```

4. 在应用的[module.json5](../quick-start/module-configuration-file.md)配置文件中添加卡片编辑配置信息。

```json
"extensionAbilities": [
  {
    "name": "EntryFormEditAbility",
    "srcEntry": "./ets/entryformeditability/EntryFormEditAbility.ets",
    "type": "formEdit"
  }
]
```

5. 在卡片的[form_config.json](./arkts-ui-widget-configuration.md#配置文件字段说明)配置文件中添加formConfigAbility配置项信息。

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
6. 在开发视图的resource/base/profile/main_pages.json文件中，注册Extension页面文件。

```json
{
  "src": [
    "pages/Index",
    "pages/Extension"
  ]
}
```