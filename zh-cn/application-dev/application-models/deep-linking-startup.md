# 使用Deep Linking实现应用间跳转
Deep Linking，又称为深度链接，是一套链接服务，实现了从链接直达App内部页面的深度跳转。在目标方APP已安装的情况下，用户可以调用openLink接口，通过特定的url参数直接打开目标App的特定深度页面。

## 适用场景
Deep Linking可以用于APP社交分享、APP沉默唤醒、APP广告引流、应用商店优化、Web to APP等场景。

## 实现原理
Deep Linking基于隐式Want匹配机制中的uri匹配来查询、拉起目标APP。隐式Want的uri匹配规则详见：[uri匹配](explicit-implicit-want-mappings.md#uri匹配规则)。

## 开发指导
基于Deep Linking的应用间跳转，被拉起方APP需要注册URL skill，uri的scheme由被拉起方APP自定义，可以定义为任意不包含特殊字符、非`ohos`开头的字符串。

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
            ]
          }
        ]
      }
    ]
  }
}
```

* 注意
  modules.json5的各个参数配置的说明详见：[module.json5配置文件](../quick-start/module-configuration-file.md)

### Deep Linking触发跳转

Deep Linking通过[openLink](../reference/apis-ability-kit/js-apis-inner-application-uiAbilityContext.md#uiabilitycontextopenlink12)接口触发应用间跳转。

openLink接口只需传入Deep Linking链接，和启动的[openLinkOptions](../reference/apis-ability-kit/js-apis-app-ability-openLinkOptions.md)配置，就可以触发跳转到其他应用。系统会根据传入的link匹配到符合skill配置的应用。<br>openLink接口进行Deep Linking跳转时，options中的`appLinkingOnly`需要置为`false`，通过[uri本地匹配](explicit-implicit-want-mappings.md#uri匹配规则)寻找到匹配项，当匹配到多个时，会拉起应用选择框。
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
          appLinkingOnly: false
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