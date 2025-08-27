# 场景动效类型互动卡片开发指导
<!--Kit: Form Kit-->
<!--Subsystem: Ability-->
<!--Owner: @cx983299475-->
<!--Designer: @xueyulong-->
<!--Tester: @chenmingze-->
<!--Adviser: @Brilliantry_Rui-->
本文档提供了场景动效类型互动卡片的开发指导，包括卡片非激活态和激活态UI界面开发、卡片配置文件开发。

## 接口说明

场景动效类型互动卡片关键接口如下表所示。

**表1** 主要接口

| 接口名                                                                                                                                                                                                 | 描述                 |
|-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|--------------------|
| [onLiveFormCreate(liveFormInfo: LiveFormInfo, session: UIExtensionContentSession): void](../reference/apis-form-kit/js-apis-app-form-LiveFormExtensionAbility.md#onliveformcreate)                  | 互动卡片界面对象创建的回调函数。   |
| [onLiveFormDestroy(liveFormInfo: LiveFormInfo): void](../reference/apis-form-kit/js-apis-app-form-LiveFormExtensionAbility.md#onliveformdestroy)                                                    | 互动卡片界面对象销毁、资源清理的回调函数。  |
| [startAbilityByLiveForm(want: Want): Promise&lt;void&gt;](../reference/apis-form-kit/js-apis-application-LiveFormExtensionContext.md#startabilitybyliveform)| 拉起互动卡片提供方（应用）的页面。 |
| [formProvider.requestOverflow(formId: string, overflowInfo: formInfo.OverflowInfo): Promise&lt;void&gt;](../reference/apis-form-kit/js-apis-app-form-formProvider.md#formproviderrequestoverflow20) | 卡片提供方发起互动卡片动效请求。   |
| [formProvider.cancelOverflow(formId: string): Promise&lt;void&gt;](../reference/apis-form-kit/js-apis-app-form-formProvider.md#formprovidercanceloverflow20)                                        | 卡片提供方发起取消互动卡片动效请求。 |
| [formProvider.getFormRect(formId: string): Promise&lt;formInfo.Rect&gt;](../reference/apis-form-kit/js-apis-app-form-formProvider.md#formprovidergetformrect20)                                        | 卡片提供方查询卡片位置、尺寸。 |

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
        storage.setOrCreate('context', this.context);
        storage.setOrCreate('session', session);
        let formId: string = liveFormInfo.formId;
        storage.setOrCreate('formId', formId);
    
        // 获取卡片圆角信息
        let borderRadius: number = liveFormInfo.borderRadius;
        storage.setOrCreate('borderRadius', borderRadius);
    
        // liveFormInfo.rect字段表示非激活态卡片组件相对激活态UI的位置和尺寸信息
        let formRect: formInfo.Rect = liveFormInfo.rect;
        storage.setOrCreate('formRect', formRect);
        console.log(`MyLiveFormExtensionAbility onSessionCreate formId: ${formId}` +
          `, borderRadius: ${borderRadius}, formRectInfo: ${JSON.stringify(formRect)}`);
    
        // 加载互动页面
        session.loadContent('myliveformextensionability/pages/MyLiveFormPage', storage);
      }
    
      onLiveFormDestroy(liveFormInfo: LiveFormInfo) {
        console.log(`MyLiveFormExtensionAbility onDestroy`);
      }
    };
    ```

2. 实现互动卡片页面

    ```ts
    // entry/src/main/ets/myliveformextensionability/pages/MyLiveFormPage.ets
    import { formInfo, formProvider } from '@kit.FormKit';
    import { BusinessError } from '@kit.BasicServicesKit';
    import LiveFormExtensionContext from 'application/LiveFormExtensionContext';
    import { Constants } from '../../common/Constants';
    
    const ANIMATION_RECT_SIZE: number = 100;
    const END_SCALE: number = 1.5;
    const END_TRANSLATE: number = -300;
    
    @Entry
    @Component
    struct MyLiveFormPage {
      @State columnScale: number = 1.0;
      @State columnTranslate: number = 0.0;
    
      private uiContext: UIContext | undefined = undefined;
      private storageForMyLiveFormPage: LocalStorage | undefined = undefined;
      private formId: string | undefined = undefined;
      private formRect: formInfo.Rect | undefined = undefined;
      private formBorderRadius: number | undefined = undefined;
      private liveFormContext: LiveFormExtensionContext | undefined = undefined;

      aboutToAppear(): void {
        this.uiContext = this.getUIContext();
        if (!this.uiContext) {
          console.warn("no uiContext");
          return;
        }
        this.initParams();
      }
    
      private initParams(): void {
        this.storageForMyLiveFormPage = this.uiContext?.getSharedLocalStorage();
        this.formId = this.storageForMyLiveFormPage?.get<string>('formId');
        this.formRect = this.storageForMyLiveFormPage?.get<formInfo.Rect>('formRect');
        this.formBorderRadius = this.storageForMyLiveFormPage?.get<number>('borderRadius');
        this.liveFormContext = this.storageForMyLiveFormPage?.get<LiveFormExtensionContext>('context');
      }
    
      // 执行动效
      private runAnimation(): void {
        this.uiContext?.animateTo({
          duration: Constants.OVERFLOW_DURATION,
          curve: Curve.Ease
        }, () => {
          this.columnScale = END_SCALE;
          this.columnTranslate = END_TRANSLATE;
        });
      }

       private startAbilityByLiveForm(): void {
        try {
          // 请开发者替换为实际的want信息
          this.liveFormContext?.startAbilityByLiveForm({
            bundleName: 'com.example.liveformdemo',
            abilityName: 'EntryAbility',
          })
            .then(() => {
              console.info('startAbilityByLiveForm succeed');
            })
            .catch((err: BusinessError) => {
              console.error(`startAbilityByLiveForm failed, code is ${err?.code}, message is ${err?.message}`);
            });
        } catch (e) {
          console.error(`startAbilityByLiveForm failed, code is ${e?.code}, message is ${e?.message}`);
        }
      }

      build() {
        Stack({alignContent: Alignment.TopStart}) {
          // 背景组件，和普通卡片等大
          Column()
            .width(this.formRect? this.formRect.width : 0)
            .height(this.formRect? this.formRect.height : 0)
            .offset({
              x: this.formRect? this.formRect.left : 0,
              y: this.formRect? this.formRect.top : 0,
            })
            .borderRadius(this.formBorderRadius ? this.formBorderRadius : 0)
            .backgroundColor('#2875F5')
          Stack() {
            this.buildContent();
          }
          .width('100%')
          .height('100%')
        }
        .width('100%')
        .height('100%')
        .onClick(() => {
          console.info('MyLiveFormPage click to start ability');
          if (!this.liveFormContext) {
            console.info('MyLiveFormPage liveFormContext is empty');
            return;
          }
          this.startAbilityByLiveForm();
        })
      }
    
      @Builder
      buildContent() {
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
            if (!this.formId) {
              console.info('MyLiveFormPage formId is empty, cancel overflow failed');
              return;
            }
            console.info('MyLiveFormPage cancel overflow animation');
            formProvider.cancelOverflow(this.formId);
          })
      }
    }
    ```

3. 互动卡片LiveFormExtensionAbility配置

    在module.json5配置文件中[extensionAbilities标签](../quick-start/module-configuration-file.md#extensionabilities标签)下配置LiveFormExtensionAbility。
    
    ```ts
    // entry/src/main/module.json5
        ...
        "extensionAbilities": [
          {
            "name": "MyLiveFormExtensionAbility",
            "srcEntry": "./ets/myliveformextensionability/MyLiveFormExtensionAbility.ets",
            "description": "MyLiveFormExtensionAbility",
            "type": "liveForm"
          }
        ]
        ...
    ```
    
    在main_pages.json文件中声明互动卡片页面。
    
    ```ts
    // entry/src/main/resources/base/profile/main_pages.json
    {
      "src": [
        "pages/Index",
        "myliveformextensionability/pages/MyLiveFormPage"
      ]
    }
    ```

### 卡片非激活态UI开发

1. 非激活态卡片页面实现

    非激活态卡片页面开发同普通卡片开发流程完全一致，在widgetCard.ets中完成。widgetCard.ets文件在卡片创建时自动生成，卡片创建流程可以参考[创建ArkTS卡片](arkts-ui-widget-creation.md)。在非激活态卡片页面实现点击卡片时，发起卡片动效请求。
    
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

    在form_config.json配置文件中新增sceneAnimationParams配置项。
    
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

    互动卡片通过调用[formProvider.requestOverflow](../reference/apis-form-kit/js-apis-app-form-formProvider.md#formproviderrequestoverflow20)接口触发动效，调用时需要明确：（1）动效申请范围。（2）动效持续时间。（3）是否使用系统提供的默认切换动效。具体可参考[formInfo.OverflowInfo](../reference/apis-form-kit/js-apis-app-form-formInfo.md#overflowinfo20)。其中，互动卡片可以通过调用[formProvider.getFormRect](../reference/apis-form-kit/js-apis-app-form-formProvider.md#formprovidergetformrect20)接口获取卡片尺寸和在窗口内的位置信息。卡片提供方以此计算动效申请范围，单位为vp。计算规则具体请参考[互动卡片请求参数约束](arkts-ui-liveform-sceneanimation-overview.md#请求参数约束)。
    
    ```ts
    // entry/src/main/ets/entryformability/EntryFormAbility.ets
    import {
      formInfo,
      formProvider,
      FormExtensionAbility,
    } from '@kit.FormKit';
    import { BusinessError } from '@kit.BasicServicesKit';
    import { Constants } from '../common/Constants';
    
    export default class EntryFormAbility extends FormExtensionAbility {
      async onFormEvent(formId: string, message: string) {
        let shortMessage: string = JSON.parse(message)['message'];
    
        // 当接收的 message 为 requestOverflow，触发互动卡片动效
        if (shortMessage === 'requestOverflow') {
          let formRect: formInfo.Rect = await formProvider.getFormRect(formId);
          this.requestOverflow(formId, formRect.width, formRect.height);
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
            // 动效申请范围
            area: { left: left, top: top, width: width, height: height },
            // 动效持续时间
            duration: duration,
            // 指定是否使用系统提供的默认切换动效
            useDefaultAnimation: true,
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
以下是按照本文档代码示例开发而成的效果demo，demo执行动效时，点击按钮，将调用 [formProvider.cancelOverflow](../reference/apis-form-kit/js-apis-app-form-formProvider.md#formprovidercanceloverflow20) 接口，打断当前破框动效，卡片切换为非激活态。

![live-form-base-demo.gif](figures/live-form-base-demo.gif)