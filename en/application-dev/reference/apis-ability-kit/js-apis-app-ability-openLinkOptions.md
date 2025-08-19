# @ohos.app.ability.OpenLinkOptions (Optional Parameters of openLink)

**OpenLinkOptions** can be used as an input parameter of [openLink()](js-apis-inner-application-uiAbilityContext.md#openlink12) to indicate whether to enable only App Linking and pass in optional parameters in the form of key-value pairs.

> **NOTE**
>
> - The initial APIs of this module are supported since API version 12. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
> - The APIs of this module can be used only in the stage model.

## Modules to Import

```ts
import { OpenLinkOptions } from '@kit.AbilityKit';
```

## OpenLinkOptions

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

| Name| Type| Read Only| Optional| Description|
| -------- | -------- | -------- | -------- | -------- |
| appLinkingOnly | boolean | No| Yes| Whether the UIAbility must be started in App Linking mode.<br>- If this parameter is set to **true** and no UIAbility matches the URL in App Linking, the result is returned directly.<br>- If this parameter is set to **false** and no UIAbility matches the URL in App Linking, App Linking is degraded to Deep Link. The default value is **false**.<br>When the aa command is used to implicitly start an ability, you can set **--pb appLinkingOnly true** or **--pb appLinkingOnly false** to start the ability in App Linking mode.|
| parameters | Record\<string, Object> | No| Yes| List of parameters in Want.<br>**NOTE**: For details about the usage rules, see **parameters** in [want](./js-apis-app-ability-want.md).|

**Example**

  ```ts
  import { common, OpenLinkOptions, wantConstant } from '@kit.AbilityKit';
  import { hilog } from '@kit.PerformanceAnalysisKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  const DOMAIN = 0xeeee;
  const TAG: string = '[openLinkDemo]';

  @Entry
  @Component
  struct Index {
    @State message: string = 'I am caller';

    build() {
      Row() {
        Column() {
          Text(this.message)
            .fontSize(50)
            .fontWeight(FontWeight.Bold)
          Button('start browser', { type: ButtonType.Capsule, stateEffect: true })
            .width('87%')
            .height('5%')
            .margin({ bottom: '12vp' })
            .onClick(() => {
              let context = this.getUIContext().getHostContext() as common.UIAbilityContext;
              let link: string = 'https://www.example.com';
              let openLinkOptions: OpenLinkOptions = {
                appLinkingOnly: true,
                parameters: {
                  [wantConstant.Params.CONTENT_TITLE_KEY]: 'contentTitle',
                  keyString: 'str',
                  keyNumber: 200,
                  keyBool: false,
                  keyObj: {
                    keyObjKey: 'objValue',
                  }
                }
              };
              try {
                context.openLink(
                  link,
                  openLinkOptions,
                  (err, result) => {
                    hilog.error(DOMAIN, TAG, `openLink callback error.code: ${JSON.stringify(err)}`);
                    hilog.info(DOMAIN, TAG, `openLink callback result: ${JSON.stringify(result.resultCode)}`);
                    hilog.info(DOMAIN, TAG, `openLink callback result data: ${JSON.stringify(result.want)}`);
                  }
                ).then(() => {
                  hilog.info(DOMAIN, TAG, `open link success.`);
                }).catch((err: BusinessError) => {
                  hilog.error(DOMAIN, TAG, `open link failed, errCode: ${JSON.stringify(err.code)}`);
                });
              }
              catch (e) {
                hilog.error(DOMAIN, TAG, `open link failed, errCode: ${JSON.stringify(e.code)}`);
              }
            })
        }
        .width('100%')
      }
      .height('100%')
    }
  }
  ```
