# 指向性跳转

## 概述
指向性跳转指拉起方在拉起的时候有明确的意图想要拉起目标应用Ability，该目标应用Ability可以是限定uri或指定want的应用Ability，例如进入地图的打车页面、点击社交软件进行分享。指向性跳转主要可分为[应用链接](#应用链接)和[指定Ability跳转](#指定ability跳转)两种方式，优先推荐使用应用链接的方式进行跳转，使用指定Ability跳转其他应用的方式在API 12版本限制三方应用使用。

## 应用链接

### 概述
应用链接是指可以触发跳转到应用相应页面的链接，通过使用应用链接，应用可以从一个应用页面跳转到另一个应用页面。被拉起方只需要向拉起方提供自己的应用链接，拉起方便可通过被拉起方提供的应用链接跳转到被拉起方指定的页面，从而实现引流，提升转化。

URL的基本格式：`scheme://host[:port]/path/`
- scheme：协议名称，例如http、https，Deep Linking链接可自定义；
- host：域名或ip地址，例如`developer.huawei.com`就是域名，`127.0.0.1`就是ip地址；
- port：端口号，例如`developer.huawei.com:80`后面的80就是端口号；
- path：路径，表示域名服务器上的目录或文件路径，例如`developer.huawei.com/consumer/`中`consumer`就是路径。

根据使用场景，不同的link又可分为Deep Linking、Web Linking和App Linking。
- Deep Linking：深度链接，是指通过uri可以跳转到特定应用的一种链接。
- Web Linking：网页链接，是指通过uri可以跳转到浏览器特定网页的一种链接；
- App Linking：应用链接，结合Deep Linking和Web Linking技术，是指可以跳转到经过网络域名校验的特定应用的一种链接。
<br>三种链接的区别如下：

| Link类型 | Deep Linking | Web Linking | App Linking |
| -------------- | --------------- | ------- | ------- |
| 无安装时体验 | 接口返回16000019错误，并且弹出“无法打开此文件”提示框 | 需设备安装浏览器用于匹配，无浏览器时现象与DeepLink相同 | 跳转至浏览器AppLink配置相关网页 |
| 匹配多个应用<br>（弹出应用选择框） | 可匹配多个应用，匹配条件可通用 | 固定匹配浏览器 | 只匹配配置应用或跳转浏览器 |
| 是否需要云侧域名服务器 | 否 | 否 | 是 |


### 注册应用URL skill
对于需要被拉起的应用，需要配置URL的skill并安装到设备上，对外提供URL，其他应用就可以通过这个URL去匹配并启动配置的应用。例如，声明应用关联的URL是https://www.test.com，则需要进行如下配置：

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
              "entity.system.browsable"
            ],
            "actions": [
              "ohos.want.action.viewData"
            ],
            "uris": [
              {
                // scheme配置
                "scheme": "https",
                // 声明关联的域名
                "host": "www.test.com"
              }
            ],
            // 是否打开域名校验开关
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

### 应用链接触发跳转

应用链接可以通过[openLink](../reference/apis-ability-kit/js-apis-inner-application-uiAbilityContext.md#uiabilitycontextopenlink12)和[startAbility](../reference/apis-ability-kit/js-apis-inner-application-uiAbilityContext.md#uiabilitycontextstartability)(不推荐)接口触发应用跳转。

#### 通过openLink接口启动(推荐)
openLink接口只需传入应用链接，和启动的[openLinkOptions](../reference/apis-ability-kit/js-apis-app-ability-openLinkOptions.md)配置，就可以触发跳转到其他应用.系统会根据传入的link匹配到符合skill配置的应用。<br>当options中的appLinkingOnly为true时，系统会匹配AppLink,匹配到的应用会经过应用市场域名检查（需联网）返回域名校验检查的唯一匹配项或未匹配结果；当options中的appLinkingOnly为false时，只会通过[uri本地匹配](explicit-implicit-want-mappings.md#uri匹配规则)寻找到匹配项，当匹配到多个时，会拉起应用选择框。如果开发者想要限定应用链接不出现应用选择框，可以使用[AppLinking技术](app-linking.md)。
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
          // 匹配的abilities选项是否需要通过AppLinking域名校验，匹配到唯一配置过的应用ability
          appLinkingOnly: true,
          // 同want中的parameter，用于传递的参数
          parameters: {demo_key: "demo_value"}
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

#### 通过startAbility接口启动(不推荐)

startAbility接口是将应用链接放入want中，通过调用[隐式want匹配](explicit-implicit-want-mappings.md#隐式want匹配原理)的方法触发应用跳转，这种方式只支持Deep Linking，不支持Web Linking和App Linking。
实现方法如下：

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

### 指定Ability跳转

指定Ability跳转是指通过startAbility接口传入显式Want启动其他应用的Ability；**从API 12开始,指定Ability跳转限制三方应用使用，只允许系统应用使用**。使用方法参考[启动其他应用的UIAbility](uiability-intra-device-interaction.md#启动其他应用的uiability)。
