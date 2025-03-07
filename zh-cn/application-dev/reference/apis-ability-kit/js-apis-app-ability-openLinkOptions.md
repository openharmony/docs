# @ohos.app.ability.OpenLinkOptions (OpenLinkOptions)

OpenLinkOptions可以作为[openLink()](js-apis-inner-application-uiAbilityContext.md#uiabilitycontextopenlink12)的入参，用于标识是否仅打开AppLinking和传递键值对可选参数。

> **说明：**
>
> - 本模块首批接口从API version 12 开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>
> - 本模块接口仅可在Stage模型下使用。

## 导入模块

```ts
import { OpenLinkOptions } from '@kit.AbilityKit';
```

## 属性

**原子化服务API**：从API version 12开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

| 名称 | 类型 | 只读 | 可选 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| appLinkingOnly | boolean | 否 | 是 | 表示是否必须以AppLinking的方式启动UIAbility。<br />- 取值为true时，如果不存在与AppLinking相匹配的UIAbility，直接返回。<br />- 取值为false时，如果不存在与AppLinking相匹配的UIAbility，AppLinking会退化为DeepLink。默认值为false。<br />aa命令隐式拉起Ability时可以通过设置"--pb appLinkingOnly true/false"以AppLinking的方式进行启动。 |
| parameters | Record\<string, Object> | 否 | 是 | 表示WantParams参数。<br/>**说明**：具体使用规则请参考[want](./js-apis-app-ability-want.md)中的parameters属性。 |

**示例：**

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
              let context = getContext(this) as common.UIAbilityContext;
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
