# 使用Web Linking实现浏览器跳转
Web Linking，本质上是Deep Linking的一种，即uri scheme定义为http或https的Deep Linking，就是Web Linking。Web Linking实现了从链接直达Web应用具体页面的跳转。
 
## 实现原理
Web Linking基于隐式Want匹配机制中的uri匹配拉起Web应用，跳转到指定网页。隐式Want的uri匹配规则详见：[uri匹配](explicit-implicit-want-mappings.md#uri匹配规则)。

## 开发指导
基于Web Linking的浏览器跳转，浏览器应用需要注册URL skill和Action skill，skill uris的scheme需要包含http或https，skill actions列表需要包含"ohos.want.action.viewData"。

被拉起方APP注册好skill之后，调用openLink接口完成跳转。

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
            "entities": [
              "entity.system.home",
              "entity.system.browsable"
            ],
            "actions": [
              "action.system.home",
              "ohos.want.action.viewData"
            ],
            "uris": [
              {
                "scheme": "https",
                "host": "www.example.com"
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

### Web Linking触发跳转

Web Linking通过[openLink](../reference/apis-ability-kit/js-apis-inner-application-uiAbilityContext.md#uiabilitycontextopenlink12)接口触发应用间跳转。

openLink接口只需传入Web Linking链接，和启动的[openLinkOptions](../reference/apis-ability-kit/js-apis-app-ability-openLinkOptions.md)配置，就可以触发跳转到其他应用。系统会根据传入的link匹配到Web应用。<br>openLink接口进行Web Linking跳转时，options中的`appLinkingOnly`需要置为`false`，通过[uri本地匹配](explicit-implicit-want-mappings.md#uri匹配规则)寻找到匹配项，当匹配到多个Web应用时，会拉起应用选择框。
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
        let link: string = "https://www.example.com";
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