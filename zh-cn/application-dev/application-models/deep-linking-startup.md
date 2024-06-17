# 使用Deep Linking实现应用间跳转

采用Deep Linking时，系统会根据[openLink()](../reference/apis-ability-kit/js-apis-inner-application-uiAbilityContext.md#uiabilitycontextopenlink12)或[startAbility](../reference/apis-ability-kit/js-apis-inner-application-uiAbilityContext.md#uiabilitycontextstartability)接口中传入的uri信息，按照[uri匹配规则](explicit-implicit-want-mappings.md#uri匹配规则)在本地已安装的应用中，寻找到符合URL skill配置的应用并进行拉起。当匹配到多个应用时，会拉起应用选择框。

## 适用场景
Deep Linking可以用于应用的社交分享、沉默唤醒、广告引流等场景。

## 实现原理

系统会根据

Deep Linking基于隐式Want匹配机制中的uri匹配来查询、拉起目标应用。隐式Want的uri匹配规则详见[uri匹配规则](explicit-implicit-want-mappings.md#uri匹配规则)。


## 目标应用在配置文件中注册URL skill

为了能够支持被其他应用访问，目标应用需要在[module.json5配置文件](../quick-start/module-configuration-file.md)中声明URL skill。其中，uri字段的scheme的取值支持自定义，可以定义为任意不包含特殊字符、非`ohos`开头的字符串。

例如，声明应用关联的URL是"example://"，配置示例如下：

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


## 拉起方应用实现应用跳转

下面通过两个案例，分别介绍如何使用[openLink()](../reference/apis-ability-kit/js-apis-inner-application-uiAbilityContext.md#uiabilitycontextopenlink12)与[startAbility](../reference/apis-ability-kit/js-apis-inner-application-uiAbilityContext.md#uiabilitycontextstartability)接口实现应用跳转。

### 使用openLink打开浏览器页面

在[openLink](../reference/apis-ability-kit/js-apis-inner-application-uiAbilityContext.md#uiabilitycontextopenlink12)接口的link字段中传入目标应用的URL信息，并将options字段中的`appLinkingOnly`配置置为`false`。


示例代码如下：

```ts
import { common } from '@kit.AbilityKit';
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
        let link: string = "http://www.test.demo";
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

### 使用startAbility实现应用跳转

startAbility接口是将应用链接放入want中，通过调用[隐式want匹配](explicit-implicit-want-mappings.md#隐式want匹配原理)的方法触发应用跳转。通过startAbility接口启动时，还需要自己传入待匹配的action和entity。


示例代码如下：

```ts
import { common } from '@kit.AbilityKit';
import OpenLinkOptions from '@ohos.app.ability.OpenLinkOptions';
import { BusinessError } from '@ohos.base';
import hilog from '@ohos.hilog';

const TAG: string = '[UIAbilityComponentsOpenLink]';
const DOMAIN_NUMBER: number = 0xFF00;

@Entry
@Component
struct Index {
  build() {
    Button('start ability', { type: ButtonType.Capsule, stateEffect: true })
      .width('87%')
      .height('5%')
      .margin({ bottom: '12vp' })
      .onClick(() => {
        let context: common.UIAbilityContext = getContext(this) as common.UIAbilityContext;
        let want: Want = {
            url: "https://www.example.com"
        };

        try {
          context.startAbility(want).then(() => {
            hilog.info(DOMAIN_NUMBER, TAG, 'start ability success.');
          }).catch((err: BusinessError) => {
            hilog.error(DOMAIN_NUMBER, TAG, `start ability failed. Code is ${err.code}, message is ${err.message}`);
          })
        } catch (paramError) {
          hilog.error(DOMAIN_NUMBER, TAG, `Failed to start ability. Code is ${paramError.code}, message is ${paramError.message}`);
        }
      })
  }
}
```