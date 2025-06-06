# 场景动效类型互动卡片开发指导

本文档提供了场景类型互动卡片的开发指导，包括卡片非激活态和激活态UI界面开发、卡片配置文件开发。

## 接口说明

场景动效类型互动卡片关键接口如下表所示。

**表1** 主要接口

| 接口名                                                                                                                                                                                                 | 描述                 |
|-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|--------------------|
| [onLiveFormCreate(liveFormInfo: LiveFormInfo, session: UIExtensionContentSession): void](../reference/apis-form-kit/js-apis-app-form-LiveFormExtensionAbility.md#onliveformcreate)                  | 互动卡片界面对象创建的回调函数。   |
| [onLiveFormDestroy(liveFormInfo: LiveFormInfo): void](../reference/apis-form-kit/js-apis-app-form-LiveFormExtensionAbility.md#onliveformdestroy)                                                    | 互动卡片界面对象销毁、资源清理的回调函数。  |
| [formProvider.requestOverflow(formId: string, overflowInfo: formInfo.OverflowInfo): Promise&lt;void&gt;](../reference/apis-form-kit/js-apis-app-form-formProvider.md#formproviderrequestoverflow20) | 卡片提供方发起互动卡片动效请求。   |
| [formProvider.cancelOverflow(formId: string): Promise&lt;void&gt;](../reference/apis-form-kit/js-apis-app-form-formProvider.md#formprovidercanceloverflow20)                                        | 卡片提供方发起取消互动卡片动效请求。 |

## 开发流程

### 卡片激活态UI开发

1. 创建互动卡片

通过[LiveFormExtensionAbility](../reference/apis-form-kit/js-apis-app-form-LiveFormExtensionAbility.md)创建互动卡片，创建时加载互动卡片页面。

```ts
// entry/src/main/ets/myliveformextensionability/MyLiveFormExtensionAbility.ets
import { formInfo, LiveFormInfo, LiveFormExtensionAbility } from '@kit.FormKit';
import { UIExtensionContentSession } from '@kit.AbilityKit';

export default class MyLiveFormExtensionAbility extends LiveFormExtensionAbility {
  onLiveFormCreate(liveFormInfo: LiveFormInfo, session: UIExtensionContentSession) {
    let storage: LocalStorage = new LocalStorage();
    storage.setOrCreate('session', session);

    // 获取卡片信息
    let formId: string = liveFormInfo.formId;
    storage.setOrCreate('formId', formId);
    let formRect: formInfo.Rect = liveFormInfo.rect;
    storage.setOrCreate('formRect', formRect);
    let borderRadius: number = liveFormInfo.borderRadius;
    storage.setOrCreate('borderRadius', borderRadius);
    console.log(`MyLiveFormExtensionAbility onSessionCreate formId: ${formId}, borderRadius: ${borderRadius}` +
      `, formRect: ${JSON.stringify(formRect)}`);

    // 加载互动页面
    session.loadContent('myliveformextensionability/pages/MyLiveFormPage', storage);
  }

  onLiveFormDestroy(liveFormInfo: LiveFormInfo) {
    console.log(`MyLiveFormExtensionAbility onDestroy`);
  }
};
```

2. 互动卡片页面实现

```ts
// entry/src/main/ets/myliveformextensionability/pages/MyLiveFormPage.ets
import { UIExtensionContentSession } from '@kit.AbilityKit';
import { formInfo, formProvider } from '@kit.FormKit';
import { Constants } from '../../common/Constants';

const ANIMATION_RECT_SIZE: number = 100;
const END_SCALE: number = 1.5;
const END_TRANSLATE: number = -300;
let storageForMyLiveFormPage = LocalStorage.getShared();

@Entry(storageForMyLiveFormPage)
@Component
struct MyLiveFormPage {
  @State columnScale: number = 1.0;
  @State columnTranslate: number = 0.0;

  private session: UIExtensionContentSession | undefined =
    storageForMyLiveFormPage?.get<UIExtensionContentSession>('session');
  private formId: string | undefined = storageForMyLiveFormPage?.get<string>('formId');
  private formRect: formInfo.Rect | undefined = storageForMyLiveFormPage?.get<formInfo.Rect>('formRect');
  private formBorderRadius: number | undefined = storageForMyLiveFormPage?.get<number>('borderRadius');

  // 执行动效
  private runAnimation(): void {
    animateTo({
      duration: Constants.OVERFLOW_DURATION,
      curve: Curve.Ease
    }, () => {
      this.columnScale = END_SCALE;
      this.columnTranslate = END_TRANSLATE;
    });
  }

  build() {
    Stack() {
      // 背景组件，和普通卡片等大
      Column()
        .width(this.formRect ? this.formRect.width : 0)
        .height(this.formRect ? this.formRect.height : 0)
        .borderRadius(this.formBorderRadius ? this.formBorderRadius : 0)
        .backgroundColor('#2875F5')

      Stack()
        .width(ANIMATION_RECT_SIZE)
        .height(ANIMATION_RECT_SIZE)
        .backgroundColor(Color.White)
        .scale({
          x: this.columnScale,
          y: this.columnScale,
        })
        .translate({
          y: this.columnTranslate
        })
        .onAppear(() => {
          // 在页面出现时执行动效
          this.runAnimation();
        })

      Button('强制取消动效')
        .backgroundColor(Color.Grey)
        .onClick(() => {
          console.log('MyLiveFormPage cancel overflow animation');
          formProvider.cancelOverflow(this.formId);
        })
    }
    .width('100%')
    .height('100%')
  }
}
```

3. 互动卡片LiveFormExtensionAbility配置

在[module.json5配置文件extensionAbilities标签](../quick-start/module-configuration-file.md#extensionabilities标签)下配置LiveFormExtensionAbility。

```ts
// entry/src/main/module.json5
    ...
    "extensionAbilities": [
      {
        "name": "MyLiveFormExtensionAbility",
        "srcEntry": "./ets/myliveformextensionability/MyLiveFormExtensionAbility.ets",
        "description": "$string:MyLiveFormExtensionAbility_desc",
        "label": "$string:MyLiveFormExtensionAbility_label",
        "type": "liveForm"
      }
    ]
    ...
```


### 卡片非激活态UI开发

1. 非激活态卡片页面实现

非激活态卡片页面开发同普通卡片开发流程完全一致，在widgetCard.ets中完成。在非激活态卡片页面实现，点击卡片时，请求卡片动效。

```ts
// entry/src/main/ets/widget/pages/WidgetCard.ets
@Entry
@Component
struct WidgetCard {
  build() {
    Row() {
      Column() {
        Text('点击触发互动卡片动效')
          .fontSize($r('app.float.font_size'))
          .fontWeight(FontWeight.Medium)
          .fontColor($r('sys.color.font_primary'))
      }
      .width('100%')
    }
    .height('100%')
    .onClick(() => {
      // 点击卡片时，选择向EntryFormAbility发送消息，并在其onFormEvent回调中调用formProvider.requestOverflow，请求卡片动效
      postCardAction(this, {
        action: 'message',
        abilityName: 'EntryFormAbility',
        params: {
          message: 'requestOverflow'
        }
      });
    })
  }
}
```

2. form_config.json配置

在form_config.json配置文件中，新增sceneAnimationParams配置项。

```ts
// entry/src/main/resources/base/profile/form_config.json
{
  "forms": [
    {
      "name": "widget",
      "displayName": "$string:widget_display_name",
      "description": "$string:widget_desc",
      "src": "./ets/widget/pages/WidgetCard.ets",
      "uiSyntax": "arkts",
      "window": {
        "designWidth": 720,
        "autoDesignWidth": true
      },
      "colorMode": "auto",
      "isDefault": true,
      "updateEnabled": true,
      "scheduledUpdateTime": "10:30",
      "updateDuration": 1,
      "defaultDimension": "2*2",
      "supportDimensions": [
        "2*2"
      ],
      "formConfigAbility": "ability://EntryAbility",
      "dataProxyEnabled": false,
      "isDynamic": true,
      "transparencyEnabled": false,
      "metadata": [],
      "sceneAnimationParams": {
        "abilityName": "MyLiveFormExtensionAbility"
      }
    }
  ]
}
```

### 互动卡片动效实现

1. 触发互动卡片动效

在加桌时，互动卡片可以通过[onUpdateForm](../reference/apis-form-kit/js-apis-app-form-formExtensionAbility.md#formextensionabilityonupdateform)生命周期回调中的wantParams参数获取卡片实际尺寸。卡片提供方以此计算动效申请范围，坐标计算时，以上图A点为（0,0）点，计算矩形EFGH对应参数，单位为vp。

```ts
// entry/src/main/ets/entryformability/EntryFormAbility.ets
import {
  formInfo,
  formProvider,
  FormExtensionAbility,
} from '@kit.FormKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { preferences } from '@kit.ArkData';
import { Constants } from '../common/Constants';
import { Utils } from '../common/Utils';

const DB_NAME: string = 'myStore'

export default class EntryFormAbility extends FormExtensionAbility {
  onUpdateForm(formId: string, wantParams?: Record<string, Object>) {
    // 当卡片加桌时，wantParams 参数将不为空，提供卡片尺寸信息
    if (wantParams) {
      this.saveFormSize(formId, wantParams);
    }
  }

  // 解析卡片尺寸信息，并保存在数据库中
  private saveFormSize(formId: string, wantParams: Record<string, Object>) {
    let width = 0;
    let height = 0;
    width = wantParams[formInfo.FormParam.FORM_WIDTH_VP_KEY] as number;
    height = wantParams[formInfo.FormParam.FORM_HEIGHT_VP_KEY] as number;
    console.log(`onUpdateForm, formId: ${formId}, size:[${width}, ${height}]`);
    let promise: Promise<preferences.Preferences> = preferences.getPreferences(this.context, DB_NAME);

    // 将卡片尺寸信息写入数据库
    Utils.writeFormSize(promise, formId, width, height);
  }

  // 从数据库中读取卡片尺寸信息
  private async getFormSize(formId: string): Promise<number[]> {
    let storeDB: preferences.Preferences =  await preferences.getPreferences(this.context, DB_NAME);
    let formCardInfo: string[] = await Utils.readFormSize(formId, storeDB);
    return [Number.parseFloat(formCardInfo[0]), Number.parseFloat(formCardInfo[1])];
  }

  async onFormEvent(formId: string, message: string) {
    let shortMessage: string = JSON.parse(message)['message'];

    // 当接收的 message 为 requestOverflow，触发互动卡片动效
    if (shortMessage === 'requestOverflow') {
      let sizeInfo = await this.getFormSize(formId);
      this.requestOverflow(formId, sizeInfo[0], sizeInfo[1]);
      return;
    }
  }

  private requestOverflow(formId: string, formWidth: number, formHeight: number): void {
    if (formWidth <= 0 || formHeight <= 0) {
      console.log('requestOverflow failed, form size is not correct.');
      return;
    }

    // 基于卡片自身尺寸信息，计算卡片动效渲染区域
    let left: number = -Constants.OVERFLOW_LEFT_RATIO * formWidth;
    let top: number = -Constants.OVERFLOW_TOP_RATIO * formHeight;
    let width: number = Constants.OVERFLOW_WIDTH_RATIO * formWidth;
    let height: number = Constants.OVERFLOW_HEIGHT_RATIO * formHeight;
    let duration: number = Constants.OVERFLOW_DURATION;

    // 发起互动卡片动效申请
    try {
      formProvider.requestOverflow(formId, {
        area: { left: left, top: top, width: width, height: height },
        duration: duration
      }).then(() => {
        console.log('requestOverflow requestOverflow succeed');
      }).catch((error: BusinessError) => {
        console.log(`requestOverflow requestOverflow catch error` + `, code: ${error.code}, message: ${error.message}`);
      })
    } catch (e) {
      console.log(`requestOverflow call requestOverflow catch error` + `, code: ${e.code}, message: ${e.message}`);
    }
  }
}
```

2. 互动卡片动效工具函数实现

```ts
// entry/src/main/ets/common/Utils.ets
import { preferences } from '@kit.ArkData';
import { BusinessError } from '@kit.BasicServicesKit';

export class Utils {
  // 卡片尺寸信息写数据库
  public static writeFormSize(promise: Promise<preferences.Preferences>, formId: string, width: number,
    height: number): void {
    promise.then(async (storeDB: preferences.Preferences) => {
      console.log('writeCardInfoSizeToDB, Succeeded to get preferences.');
      await storeDB.put('width_' + formId, `${width}`);
      await storeDB.put('height_' + formId, `${height}`);
      await storeDB.flush();
    }).catch((err: BusinessError) => {
      console.log(`writeCardInfoSizeToDB, Failed to get preferences. ${JSON.stringify(err)}`);
    });
  }

  // 从数据库中读取卡片信息
  public static async readFormSize(formId: string, storeDB: preferences.Preferences): Promise<string[]> {
    try {
      let widthInfo = await storeDB.get('width_' + formId, '-1');
      let heightInfo = await storeDB.get('height_' + formId, '-1');
      console.log(`Succeeded to get cardInfo: ${widthInfo}, ${heightInfo}`);
      return [widthInfo.toString(), heightInfo.toString()];
    } catch(err) {
      console.log(`Failed to get preferences. ${JSON.stringify(err)}`);
      return [''];
    }
  }
}
```

```ts
// entry/src/main/ets/common/Constants.ets
// 动效相关常量的开发
export class Constants {
  // 互动卡片动效超范围，左侧偏移百分比 = 偏移值/卡片宽度
  public static readonly OVERFLOW_LEFT_RATIO: number = 0.1;

  // 互动卡片动效超范围，上侧偏移百分比 = 偏移值/卡片高度
  public static readonly OVERFLOW_TOP_RATIO: number = 0.15;

  // 互动卡片动效超范围，宽度放大百分比
  public static readonly OVERFLOW_WIDTH_RATIO: number = 1.2;

  // 互动卡片动效超范围，高度放大百分比
  public static readonly OVERFLOW_HEIGHT_RATIO: number = 1.3;

  // 互动卡片动效超范围，动效时长
  public static readonly OVERFLOW_DURATION: number = 3500;
}
```

## 实现效果
![live-form-base-demo.gif](figures/live-form-base-demo.gif)