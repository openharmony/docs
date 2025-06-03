# 场景动效类型互动卡片开发指导

本文档提供了场景类型互动卡片的开发指导，包括：卡片非激活态和激活态 UI 界面开发，卡片配置文件开发，根据此文档，可以实现一个场景动效类型互动卡片动效 demo。

## 开发接入指导

互动卡片定位上是普通卡片的能力的增强，所以开发者需要首先完成普通卡片的业务开发。而后在特定业务环节通过接口请求，触发互动卡片特有的互动卡片动效。因此可以分为以下几个步骤：

### 卡片非激活态 UI 开发
非激活态卡片 UI 开发同普通卡片开发流程完全一致，在 widgetCard.ets 中完成，卡片信息更新、UI刷新逻辑在对应 FormExtensionAbility 中完成。

**代码样例：entry/src/main/ets/widget/pages/WidgetCard.ets**

```ts
@Entry
@Component
struct WidgetCard {
  /*
   * The title.
   */
  readonly title: string = '点击触发互动卡片动效';
  /*
   * The action type.
   */
  readonly actionType: string = 'message';
  /*
   * The ability name.
   */
  readonly abilityName: string = 'EntryFormAbility';
  /*
   * The message.
   */
  readonly message: string = 'requestOverflow';
  /*
   * The width percentage setting.
   */
  readonly fullWidthPercent: string = '100%';
  /*
   * The height percentage setting.
   */
  readonly fullHeightPercent: string = '100%';

  build() {
    Row() {
      Column() {
        Text(this.title)
          .fontSize($r('app.float.font_size'))
          .fontWeight(FontWeight.Medium)
          .fontColor($r('sys.color.font_primary'))
      }
      .width(this.fullWidthPercent)
    }
    .height(this.fullHeightPercent)
    .onClick(() => {
      postCardAction(this, {
        action: this.actionType,
        abilityName: this.abilityName,
        params: {
          message: this.message
        }
      });
    })
  }
}
```

### 卡片激活态 UI 开发
卡片激活态由 LiveFormExtensionAbility 进程承载。LiveFormExtensionAbility 是专供 3D 互动卡片，用于卡片激活态开发的特殊类型 UIExtensionAbility 。其特点在于：开发者可以在通过 LiveFormExtensionAbility **在卡片区域嵌入应用提供的自定义 UI**。 LiveFormExtensionAbility 会在独立于 UIAbility 的进程中运行，完成其页面的布局和渲染。

关于 LiveFormExtensionAbility 生命周期管理等详细信息，可参考 [LiveFormExtensionAbility](../reference/apis-form-kit/js-apis-app-form-LiveFormExtensionAbility.md)。

**代码样例：entry/src/main/ets/myliveformextensionability/MyLiveFormExtensionAbility.ets**

```ts
import { LiveFormInfo } from '@kit.FormKit';
import { LiveFormExtensionAbility } from '@kit.FormKit';
import { UIExtensionContentSession } from '@kit.AbilityKit';

export default class MyLiveFormExtensionAbility extends LiveFormExtensionAbility {
  onLiveFormCreate(liveFormInfo: LiveFormInfo, session: UIExtensionContentSession) {
    let storage: LocalStorage = new LocalStorage();
    storage.setOrCreate('session', session);

    // 获取参卡片 ID 与激活态渲染区域
    let formId: string = liveFormInfo.formId as string;
    storage.setOrCreate('formId', formId);
    console.log(`MyLiveFormExtensionAbility onSessionCreate formId: ${formId}`);

    // 加载提供方页面
    session.loadContent('myliveformextensionability/pages/MyLiveFormPage', storage);
    this.context.setBackgroundImage($r('app.media.background'));
  }

  onLiveFormDestroy(liveFormInfo: LiveFormInfo) {
    console.log(`MyLiveFormExtensionAbility onDestroy`);
  }
};
```

在 module.json 中，在 extensionAbilities 配置项中增加 MyLiveFormExtensionAbility 配置。其中 type 字段为 liveForm。

**代码样例：entry/src/main/module.json**

```ts
    "extensionAbilities": [
      {
        "name": "MyLiveFormExtensionAbility",
        "srcEntry": "./ets/myliveformextensionability/MyLiveFormExtensionAbility.ets",
        "description": "$string:MyLiveFormExtensionAbility_desc",
        "label": "$string:MyLiveFormExtensionAbility_label",
        "type": "liveForm"
      }
    ]
```

激活态对应页面效果实现。

**代码样例：entry/src/main/ets/myliveformextensionability/pages/MyLiveFormPage.ets**

```ts
import { UIExtensionContentSession } from '@kit.AbilityKit';
import { formProvider } from '@kit.FormKit';
import { Constants } from '../../common/Constants';
import { Utils } from '../../common/Utils';

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
  private formWidth: number = 0;
  private formHeight: number = 0;

  aboutToAppear(): void {
    this.initParams();
    console.log(`UIExtAbilityPage aboutToAppear, formId: ${this.formId}, formWidth: ${this.formWidth}` +
      `, formHeight: ${this.formHeight}`);
  }

  aboutToDisappear(): void {
    console.log('UIExtAbilityPage aboutToDisappear');
  }

  private initParams(): void {
    let paramsString: string = Utils.readParams();
    if (paramsString === '') {
      return;
    }
    let paramsList: string[] = paramsString.split(Constants.PARAMS_OUTER_SPLIT);
    let formRectList: string[] = paramsList[0].split(Constants.PARAMS_INNER_SPLIT);
    this.formWidth = Number.parseFloat(formRectList[0]);
    this.formHeight = Number.parseFloat(formRectList[1]);
  }

  private runAnimation(): void {
    animateTo({
      duration: Constants.OVERFLOW_DURATION,
      curve: Curve.Ease
    }, () => {
      this.columnScale = END_SCALE;
      this.columnTranslate = END_TRANSLATE;
    })
  }

  build() {
    Stack() {
      // 动效
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

相关常量见工具类 Constants.ets。

**代码样例：entry/src/main/ets/common/Constants.ets**

```ts
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

  // 应用文件前缀
  public static readonly FILE: string = '/data/storage/el2/base/haps/entry/files/params.txt';

  public static readonly PARAMS_INNER_SPLIT: string = ',';

  public static readonly PARAMS_OUTER_SPLIT: string = '#';
}
```

工具函数类 Utils.ets。

**代码样例：entry/src/main/ets/common/Utils.ets**

```ts
import { buffer } from '@kit.ArkTS';
import { fileIo as fs, ReadOptions } from '@kit.CoreFileKit';
import { Constants } from './Constants';
import { preferences } from '@kit.ArkData';
import { BusinessError } from '@kit.BasicServicesKit';

export class Utils {
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

  public static writeParams(paramsString: string): void {
    if (fs.accessSync(Constants.FILE)) {
      fs.rmdirSync(Constants.FILE);
      console.log(`Utils writeParams, ${Constants.FILE} is not exist`);
    }
    console.log(`Utils writeParams, paramsString: ${paramsString}`);

    let file = fs.openSync(Constants.FILE, fs.OpenMode.READ_WRITE | fs.OpenMode.CREATE);
    let writeLen = fs.writeSync(file.fd, paramsString);
    console.log(`Utils writeParams, The length of str is: ${writeLen}`);
    let arrayBuffer = new ArrayBuffer(1024);
    let readOptions: ReadOptions = {
      offset: 0,
      length: arrayBuffer.byteLength
    };
    let readLen = fs.readSync(file.fd, arrayBuffer, readOptions);
    let buf = buffer.from(arrayBuffer, 0, readLen);
    console.log(`Utils writeParams, the content of file: ${buf.toString()}`);
    fs.closeSync(file);
  }

  public static readParams(): string {
    console.log(`Utils readParams, start free case test ${fs.accessSync(Constants.FILE)}`);
    if (!fs.accessSync(Constants.FILE)) {
      return '';
    }
    console.log('Utils readParams, start free case test');
    let file: fs.File = fs.openSync(Constants.FILE, fs.OpenMode.READ_WRITE | fs.OpenMode.CREATE);
    return Utils.readParamsInner(file);
  }

  private static readParamsInner(file: fs.File): string {
    let arrayBuffer: ArrayBuffer = new ArrayBuffer(1024);
    let readOptions: ReadOptions = {
      offset: 0,
      length: arrayBuffer.byteLength
    };
    let readLen: number = fs.readSync(file.fd, arrayBuffer, readOptions);
    let buf: string = buffer.from(arrayBuffer, 0, readLen).toString();
    return buf;
  }
}
```

### 卡片配置声明

在 form_config.json 配置文件中，在对应卡片 widget 配置项中新 sceneAnimationParams，在其中需对应配置 MyLiveFormExtensionAbility 的类名，完成普通卡片 widgetCard.ets 和 LiveFormExtensionAbility 的匹配关系声明。

```ts
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

### 动效申请与业务编排

卡片加桌过程时，[onUpdateForm](../reference/apis-form-kit/js-apis-app-form-formExtensionAbility.md#formextensionabilityonupdateform) 生命周期回调中，通过 wantParams 中返回卡片实际尺寸，并以此计算动效申请范围。

动效触发接口可参考 [formProvider.requestOverflow](../reference/apis-form-kit/js-apis-app-form-formProvider.md#formproviderrequestoverflow20)。

在用户点击时触发，典型时序图如下，对应在卡片 [onFormEvent](../reference/apis-form-kit/js-apis-app-form-formExtensionAbility.md#formextensionabilityonformevent) 生命周期回调处理。

图1 点击触发互动卡片动效时序图

![live-form-click-timeline.png](figures/live-form-click-timeline.png)

在卡片定时定点刷新场景下，典型时序图如下，对应在卡片 [onUpdateForm](../reference/apis-form-kit/js-apis-app-form-formExtensionAbility.md#formextensionabilityonupdateform) 生命周期回调处理。

图2 定时定点触发互动卡片动效时序图

![live-form-update-timeline.png](figures/live-form-update-timeline.png)

**代码示例：entry/src/main/ets/entryformability/EntryFormAbility.ets**

```ts
import {
  formBindingData,
  formInfo,
  formProvider,
  FormExtensionAbility,
} from '@kit.FormKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { Want } from '@kit.AbilityKit';
import { Constants } from '../common/Constants';
import { Utils } from '../common/Utils';
import { preferences } from '@kit.ArkData';

const DB_NAME: string = 'myStore'

export default class EntryFormAbility extends FormExtensionAbility {
  onAddForm(want: Want) {
    // Called to return a FormBindingData object.
    const formData = '';
    return formBindingData.createFormBindingData(formData);
  }

  onCastToNormalForm(formId: string) {
    // Called when the form provider is notified that a temporary form is successfully
    // converted to a normal form.
  }

  async onUpdateForm(formId: string, wantParams?: Record<string, Object>) {
    // Called to notify the form provider to update a specified form.
    if (wantParams) {
      this.saveFormSize(formId, wantParams);
    }
    let sizeInfo = await this.getFormSize(formId);
    this.requestOverflow(formId, sizeInfo[0], sizeInfo[1]);
  }

  private saveFormSize(formId: string, wantParams: Record<string, Object>) {
    let width = 0;
    let height = 0;
    width = wantParams[formInfo.FormParam.FORM_WIDTH_VP_KEY] as number;
    height = wantParams[formInfo.FormParam.FORM_HEIGHT_VP_KEY] as number;
    console.log(`onUpdateForm, formId: ${formId}, size:[${width}, ${height}]`);
    let promise: Promise<preferences.Preferences> = preferences.getPreferences(this.context, DB_NAME);
    Utils.writeFormSize(promise, formId, width, height);
  }

  private async getFormSize(formId: string): Promise<number[]> {
    let storeDB: preferences.Preferences =  await preferences.getPreferences(this.context, DB_NAME);
    let formCardInfo: string[] = await Utils.readFormSize(formId, storeDB);
    return [Number.parseFloat(formCardInfo[0]), Number.parseFloat(formCardInfo[1])];
  }

  async onFormEvent(formId: string, message: string) {
    // Called when a specified message event defined by the form provider is triggered.
    let shortMessage: string = JSON.parse(message)['message'];
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

    let left: number = -Constants.OVERFLOW_LEFT_RATIO * formWidth;
    let top: number = -Constants.OVERFLOW_TOP_RATIO * formHeight;
    let width: number = Constants.OVERFLOW_WIDTH_RATIO * formWidth;
    let height: number = Constants.OVERFLOW_HEIGHT_RATIO * formHeight;
    let duration: number = Constants.OVERFLOW_DURATION;

    // 保存卡片位置尺寸和请求参数信息
    let formRectString: string = formWidth + Constants.PARAMS_INNER_SPLIT + formHeight;
    let overflowParamsString: string = left + Constants.PARAMS_INNER_SPLIT + top + Constants.PARAMS_INNER_SPLIT +
      width + Constants.PARAMS_INNER_SPLIT + height + Constants.PARAMS_INNER_SPLIT + duration;
    Utils.writeParams(formRectString + Constants.PARAMS_OUTER_SPLIT + overflowParamsString);

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

  onRemoveForm(formId: string) {
    // Called to notify the form provider that a specified form has been destroyed.
  }

  onAcquireFormState(want: Want) {
    // Called to return a {@link FormState} object.
    return formInfo.FormState.READY;
  }
}
```

## demo 效果
![live-form-base-demo.gif](figures/live-form-base-demo.gif)

<!--Del-->
## 系统应用扩展能力开发指导
针对系统应用，互动卡片支持了更多扩展能力，详细可参考[场景动效类型互动卡片开发指导（系统应用）](arkts-ui-liveform-sceneanimation-development-system.md)。
<!--DelEnd-->