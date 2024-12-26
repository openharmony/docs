# 动态卡片利用router事件跳转到指定UIAbility

在动态卡片中使用[postCardAction](../reference/apis-arkui/js-apis-postCardAction.md#postcardaction)接口的router能力，能够快速拉起动态卡片提供方应用的指定UIAbility(页面)，因此UIAbility较多的应用往往会通过卡片提供不同的跳转按钮，实现一键直达的效果。例如相机卡片，卡片上提供拍照、录像等按钮，点击不同按钮将拉起相机应用的不同UIAbility，从而提高用户的体验。

![WidgerCameraCard](figures/WidgerCameraCard.png)

> **说明：**
>
> 本文主要介绍动态卡片的事件开发。对于静态卡片，请参见[FormLink](../reference/apis-arkui/arkui-ts/ts-container-formlink.md)。

示例代码开发步骤：
- 1：创建动态卡片
  - 在工程的 entry 模块中，通过右键操作添加动态的 ArkTs 卡片 WidgetEventRouterCard，此卡片将作为后续交互的入口点
- 2：构建ArkTs卡片页面代码布局与逻辑
  - 找到WidgetEventRouterCard卡片页面对应代码文件（通常在src/main/ets相关目录下），可替换为示例代码，确保代码语法及资源引用无误。
  - 示例代码的卡片页面布局中有两个按钮，点击其中一个按钮时调用postCardAction向指定UIAbility发送router事件，并在事件内定义需要传递的内容。
  ```ts
  //src/main/ets/widgeteventroutercard/pages/WidgetEventRouterCardCard.ets
  
  @Entry
  @Component
  struct WidgetEventRouterCard {
    build() {
      Column() {
        Text($r('app.string.JumpLabel'))
          .fontColor('#FFFFFF')
          .opacity(0.9)
          .fontSize(14)
          .margin({ top: '8%', left: '10%' })
        Row() {
          Column() {
            Button() {
              Text($r('app.string.ButtonA_label'))
                .fontColor('#45A6F4')
                .fontSize(12)
            }
            .width(120)
            .height(32)
            .margin({ top: '20%' })
            .backgroundColor('#FFFFFF')
            .borderRadius(16)
            .onClick(() => {
              postCardAction(this, {
                action: 'router',
                abilityName: 'EntryAbility',
                params: { targetPage: 'funA' }
              });
            })
  
            Button() {
              Text($r('app.string.ButtonB_label'))
                .fontColor('#45A6F4')
                .fontSize(12)
            }
            .width(120)
            .height(32)
            .margin({ top: '8%', bottom: '15vp' })
            .backgroundColor('#FFFFFF')
            .borderRadius(16)
            .onClick(() => {
              postCardAction(this, {
                action: 'router',
                abilityName: 'EntryAbility',
                params: { targetPage: 'funB' }
              });
            })
          }
        }.width('100%').height('80%')
        .justifyContent(FlexAlign.Center)
      }
      .width('100%')
      .height('100%')
      .alignItems(HorizontalAlign.Start)
      .backgroundImage($r('app.media.CardEvent'))
      .backgroundImageSize(ImageSize.Cover)
    }
  }
  ```
  
- 3：(可选)资源配置
   - 字符串资源：根据实际需要在src/main/resources/base/element/string.json，按 JSON 格式添加卡片所需字段，保存并保证引用一致。
   - 背景图片资源：根据实际需要将图片添加到src/main/resources/base/media目录，在ArkTs卡片页面代码中正确引用。
  
- 4：处理router事件
  - 在UIAbility中接收router事件并获取参数，根据传递的params不同，选择拉起不同的页面。可在EntryAbility.ets中替换如下代码
  
  ```ts
  //src/main/ets/entryability/EntryAbility.ets
  
  import { AbilityConstant, UIAbility, Want } from '@kit.AbilityKit';
  import { window } from '@kit.ArkUI';
  import { hilog } from '@kit.PerformanceAnalysisKit';
  
  const TAG: string = 'EntryAbility';
  const DOMAIN_NUMBER: number = 0xFF00;

  export default class EntryAbility extends UIAbility {
    private selectPage: string = '';
    private currentWindowStage: window.WindowStage | null = null;
  
    onCreate(want: Want, launchParam: AbilityConstant.LaunchParam): void {
      // 获取router事件中传递的targetPage参数
      hilog.info(DOMAIN_NUMBER, TAG, `Ability onCreate: ${JSON.stringify(want?.parameters)}`);
      if (want?.parameters?.params) {
        // want.parameters.params 对应 postCardAction() 中 params 内容
        let params: Record<string, Object> = JSON.parse(want.parameters.params as string);
        this.selectPage = params.targetPage as string;
        hilog.info(DOMAIN_NUMBER, TAG, `onCreate selectPage: ${this.selectPage}`);
      }
    }
  
    // 如果UIAbility已在后台运行，在收到Router事件后会触发onNewWant生命周期回调
    onNewWant(want: Want, launchParam: AbilityConstant.LaunchParam): void {
      hilog.info(DOMAIN_NUMBER, TAG, `Ability onNewWant: ${JSON.stringify(want?.parameters)}`);
      if (want?.parameters?.params) {
        // want.parameters.params 对应 postCardAction() 中 params 内容
        let params: Record<string, Object> = JSON.parse(want.parameters.params as string);
        this.selectPage = params.targetPage as string;
        hilog.info(DOMAIN_NUMBER, TAG, `onNewWant selectPage: ${this.selectPage}`);
      }
      if (this.currentWindowStage !== null) {
        this.onWindowStageCreate(this.currentWindowStage);
      }
    }
  
    onWindowStageCreate(windowStage: window.WindowStage): void {
      // Main window is created, set main page for this ability
      let targetPage: string;
      // 根据传递的targetPage不同，选择拉起不同的页面
      switch (this.selectPage) {
        case 'funA':
          targetPage = 'pages/FunA'; //与实际的UIAbility页面路径保持一致
          break;
        case 'funB':
          targetPage = 'pages/FunB'; //与实际的UIAbility页面路径保持一致
          break;
        default:
          targetPage = 'pages/Index'; //与实际的UIAbility页面路径保持一致
      }
      if (this.currentWindowStage === null) {
        this.currentWindowStage = windowStage;
      }
      windowStage.loadContent(targetPage, (err, data) => {
        if (err.code) {
          hilog.error(DOMAIN_NUMBER, TAG, 'Failed to load the content. Cause: %{public}s', JSON.stringify(err) ?? '');
          return;
        }
        hilog.info(DOMAIN_NUMBER, TAG, 'Succeeded in loading the content. Data: %{public}s', JSON.stringify(data) ?? '');
      });
    }
  }
  ```
- 5：创建跳转后的UIAbility页面
  - 在pages文件夹下新建FunA.ets和FunB.ets，按需求构建页面布局与逻辑。
- 6：注册UIAbility页面
  - 打开resources目录下main_pages.json，确认新建FunA.ets和FunB.ets已正确注册在src数组中。
- 七：调试测试
  - 运行应用，点击动态卡片触发router事件，检查页面跳转是否正确，通过日志输出排查问题并修复。