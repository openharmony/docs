# 跨应用方式

本文将介绍应用间跳转方式，

- [通过openLink方式启动](#通过openLink方式启动)

- [通过startAbility显式拉起启动](#通过startAbility显式拉起启动)

- [通过startAbility隐式拉起启动](#通过startAbility隐式拉起启动)

## 通过openLink方式启动

从API 11版本，系统提供了新的[`openLink()`](../reference/apis-ability-kit/js-apis-inner-application-uiAbilityContext.md#uiabilitycontextopenlink)接口，当三方应用需要跳转到其他三方应用时，可以通过[`openLink()`](../reference/apis-ability-kit/js-apis-inner-application-uiAbilityContext.md#uiabilitycontextopenlink)方法隐式匹配uri启动UIAbility。如果启动请求方想要启动唯一的UIAbility，可以通过配置AppLinking，在[`openLink()`](../reference/apis-ability-kit/js-apis-inner-application-uiAbilityContext.md#uiabilitycontextopenlink)的启动请求中设置appLinkingOnly参数为true，匹配并启动唯一配置[AppLinking](app-linking.md)的UIAbility。示例中的context的获取方式请参见[获取UIAbility的上下文信息](uiability-usage.md#获取uiability的上下文信息)。

```ts
import common from '@ohos.app.ability.common';
import OpenLinkOptions from '@ohos.app.ability.OpenLinkOptions';
import { BusinessError } from '@ohos.base';
import hilog from '@ohos.hilog';

const TAG: string = '[UIAbilityComponentsOpenLink]';
const DOMAIN_NUMBER: number = 0xFF00;

@Entry
@Component
struct Index {
  build() {
    Button('start link', { type: ButtonType.Capsule, stateEffect: true })
      .width('87%')
      .height('5%')
      .margin({ bottom: '12vp' })
      .onClick(() => {
        let context: common.UIAbilityContext = getContext(this) as common.UIAbilityContext;
        let link: string = "https://www.example.com";
        let openLinkOptions: OpenLinkOptions = {
          // 匹配的abilities选项是否需要通过AppLinking域名校验，匹配到唯一配置过的应用ability
          appLinkingOnly: true,
          // 同want中的parameter，用于传递的参数
          parameters: {demo_key: "demo_value"}
        };

        try {
          context.openLink(link, openLinkOptions, (err, data) => {
            // AbilityResult callback回调，仅在被拉起ability死亡时触发
            hilog.info(DOMAIN_NUMBER, TAG, 'open link success. Callback result:' + JSON.stringify(data));
          }).then(() => {
            hilog.info(DOMAIN_NUMBER, TAG, 'open link success.');
          }).catch((err: BusinessError) => {
            hilog.error(DOMAIN_NUMBER, TAG, `open link failed. Code is ${err.code}, message is ${err.message}`);
          })
        } catch (paramError) {
          hilog.error(DOMAIN_NUMBER, TAG, `Failed to start link. Code is ${paramError.code}, message is ${paramError.message}`);
        }
      })
  }
}
```

## 通过startAbility显式拉起启动

从API 12版本开始，除三方应用跳转其他三方应用场景外，其他场景仍可通过显式want指定ability启动。请参考[使用显式Want启动应用组件](ability-startup-with-explicit-want.md#使用显式want启动应用组件)。

## 通过startAbility隐式拉起启动

隐式拉起需要通过构建隐式want（具体请参考[隐式Want匹配原理](explicit-implicit-want-mappings.md#隐式want匹配原理)），在启动过程中去匹配对应的应用ability，当存在多个匹配的应用ability时，系统将弹出应用选择框供用户选择。请参考[使用隐式Want打开网址](ability-startup-with-implicit-want.md#使用隐式want打开网址)。