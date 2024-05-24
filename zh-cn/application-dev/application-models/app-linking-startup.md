# 使用App Linking实现应用间跳转
App Linking，又称为应用链接，是一种使用结合Web Linking和Deep Linking的链接技术，是Deep Linking的升级版，无论应用是否已安装，都可以跳转到链接指定的内容。

## 适用场景
App Linking可以用于Deep Linking的所有场景，同时需要指定应用唯一性，保障应用未安装情况下能够跳转到浏览器页面。

## 实现原理
App Linking在Deep Linking的实现基础上，新增域名校验流程，通过访问App Linking配置的域名服务器，获取配置的跳转应用，从Deep Linking匹配到的应用中过滤出配置的跳转应用。如果该应用未匹配上，则跳转至浏览器尝试打开域名配置的网页链接。

## 开发指导
基于App Linking的应用间跳转，被拉起方除了需要注册scheme为“https”的URL skill，还需要参考[App Linking 开发指南](app-linking.md)进行云侧配置。

被拉起方APP注册好URL skill之后，调用openLink接口完成跳转。

### 注册应用URL skill
被拉起方APP在module.json5中声明URL skill。例如，声明应用关联的URL是example://，需要进行如下配置：

```json
{
  "module": {
    "abilities": [
      {
        "name": "EntryAbility",
        "srcEntry": "./ets/entryability/EntryAbility.ts",
        "icon": "$media:icon",
        "label": "$string:EntryAbility_label",
        "startWindowIcon": "$media:icon",
        "startWindowBackground": "$color:start_window_background",
        "skills": [
          {
            "action": [
                // 根据uri匹配规则，action为空无法匹配uri，需至少设置任意一个action
                "ohos.want.action.viewData"
            ],
            "uris": [
              {
                // scheme配置
                "scheme": "example",
              }
            ],
            "domainVerify": true
          }
        ]
      }
    ]
  }
}
```

* 注意
  modules.json5的各个参数配置的说明详见：[module.json5配置文件](../quick-start/module-configuration-file.md)

### App Linking触发跳转

App Linking通过[openLink](../reference/apis-ability-kit/js-apis-inner-application-uiAbilityContext.md#uiabilitycontextopenlink12)接口触发应用间跳转。

openLink接口只需传入App Linking链接，和启动的[openLinkOptions](../reference/apis-ability-kit/js-apis-app-ability-openLinkOptions.md)配置，就可以触发跳转到其他应用。系统会根据传入的link匹配到符合skill配置的应用。<br>openLink接口进行Deep Linking跳转时，options中的`appLinkingOnly`需要置为`true`，通过[uri本地匹配](explicit-implicit-want-mappings.md#uri匹配规则)寻找到匹配项，并经过云侧域名检验过滤，当过滤后的应用为一个时直接跳转至该应用，当过滤后的应用为0个时则自动跳转至浏览器相应页面。
<br>openLink接口使用的示例代码如下：

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
        let link: string = "example://";
        let openLinkOptions: OpenLinkOptions = {
          // 匹配App Linking
          appLinkingOnly: true
        };

        try {
          context.openLink(link, openLinkOptions)
            .then(() => {
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