# 使用App Linking实现应用间跳转
App Linking是通过https链接直接将用户带到应用程序中的特定内容的一种技术，无论应用是否已安装，都可以跳转到链接指定的内容。如果用户已经安装应用，用户可以通过App Linking直接打开应用原生页面来展示内容；如果用户尚未安装应用，用户可以通过App Linking跳转到对应的应用市场（或自定义网址）提升用户安装应用，安装完成后再通过此链接可以直接跳转到指定的内容。
<br>
相比Deep Linking技术，App Linking更安全可靠，体验更佳。

## 适用场景
1. 使用Deep Linking技术的场景下，多个应用可以配置相同的域名等链接信息，系统无法识别哪个是受信应用，存在被仿冒的可能。而App Linking通过域名校验技术可以帮助用户消除歧义，识别受信任的目标应用，并直达受信任的目标应用。
2. 由于App Linking 利用的是HTTPS网址以及与网站的关联，若目标应用未安装，会直接跳转到浏览器打开相应的网页。

## 实现原理
App Linking是在Deep Linking的实现基础上，新增域名校验流程，通过访问App Linking配置的域名服务器，获取配置的跳转应用，从Deep Linking匹配到的应用中过滤出配置的跳转应用。如果该应用未匹配上，则跳转至浏览器尝试打开域名配置的网页链接。

## 开发指导

若要使用App Linking功能，需要做如下操作：

* 声明应用关联的网站域名
* 添加代码到应用的Ability中以处理传入的链接
* 在开发者网站上关联应用
* 验证App Linking是否正常工作

被拉起方APP注册好URL skill之后，调用openLink接口完成跳转。

### 声明应用关联的网站域名

在应用的[module.json5配置文件](../quick-start/module-configuration-file.md)中进行如下配置，以声明应用关联的域名地址，并开启域名校验开关。

* "actions"列表中包含"ohos.want.action.viewData"。
* "entities"列表中包含"entity.system.browsable"。
* "uris"列表中包含"scheme"为"https"且"host"为域名地址的元素。
* "domainVerify"设置为true，表示开启域名校验开关。

例如，声明应用关联在域名是www.test.com，则需进行如下配置：

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
                // scheme必须配置为https
                "scheme": "https",
                // 声明关联的域名
                "host": "www.test.com"
              }
            ],
            // 打开域名校验开关
           "domainVerify": true
          }
        ]
      }
    ]
  }
}
```
> modules.json5的各个参数配置的说明详见：[module.json5配置文件](../quick-start/module-configuration-file.md)

### 添加代码到应用的Ability中以处理传入的链接

在应用的Ability(如EntryAbility)的onCreate()或者onNewWant()生命周期回调中添加代码，以处理传入的链接

```typescript
import { AbilityConstant, UIAbility, Want } from '@kit.AbilityKit';
import Url from '@ohos.url'

export default class EntryAbility extends UIAbility {
  onCreate(want: Want, launchParam: AbilityConstant.LaunchParam): void {
    // 从want中获取传入的链接信息。
    // 如传入的url为：https://www.test.com/goto?dst=DetailAbility
    let uri = want?.uri 
    if (uri) {
      // 解析query参数，根据参数做后续处理
      // 例如，开发者可以根据query参数的值进行二次跳转
      let urlObject = Url.URL.parseURL(want?.uri);
      let dstAbility = urlObject.params.get('dst') ?? "DetailAbility"; 
      console.info(`destination ability:${dstAbility}`);
      // ...
    }
  }
}
```

### 在开发者网站上关联应用

在开发者的网站上做如下配置，以关联应用。

1. 创建域名配置文件applinking.json
   内容为如下：

   ```json
   {
    "applinking": {
      "apps": [
        {
          "appIdentifier": "1234"
        }
      ]
    },
   }
   ```

   `appIdentifier`填写设备开发厂商的应用市场为该应用分配的唯一标识`app-identifer`。

   * 注意
     `app-identifer`为设备开发厂商的应用市场在应用上架时所分配的应用的唯一标识，在应用打包过程中，设备开发厂商负责将该标识`app-identifer`签入到应用的Hap包中。

2. 将配置文件放在域名服务器的固定目录下
   固定目录为：

   > https://*domain.name*/.well-known/applinking.json

   例如开发者的域名为www.test.com，则需将applinking.json文件放在如下位置：
   `https://www.test.com/.well-known/applinking.json`

### App Linking触发跳转

App Linking通过[openLink](../reference/apis-ability-kit/js-apis-inner-application-uiAbilityContext.md#uiabilitycontextopenlink12)接口触发应用间跳转。

openLink接口只需传入App Linking链接，和启动的[openLinkOptions](../reference/apis-ability-kit/js-apis-app-ability-openLinkOptions.md)配置，就可以触发跳转到其他应用。系统会根据传入的link匹配到符合skill配置的应用。

* 注意：
  openLink接口提供了两种拉起目标应用的方式，开发者可根据业务需求进行选择。

  1. 仅以App Linking的方式打开应用
     将`appLinkingOnly`参数设为true，若有匹配的应用，则直接打开目标应用。若无App Linking匹配的应用，则抛异常给开发者进行处理。
  2. App Linking优先的方式打开应用
     将`appLinkingOnly`参数设为false或者默认，则为App Linking优先的方式打开应用。若有App Linking匹配的应用，则直接打开目标应用。若无App Linking匹配的应用，则尝试以Deep Linking的方式打开应用。

<br>为了方便验证App Linking是否配置正确，此处选择方式1进行示例，示例代码如下：

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
        let link: string = "https://www.test.com/goto?dst=DetailAbility";
        let openLinkOptions: OpenLinkOptions = {
          // 仅以App Linking的方式打开应用
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

### FAQ

1. 应用的Modules.json5文件skills设置不正确
   检查"host"字段中是否是应用所对应的域名。

2. 服务器配置不正确
   检查服务器的 JSON 配置，并确保 `appIdentifier` 的值正确无误。

3. 系统尚未完成域名校验
   在设备上安装应用，需等待至少 20 秒，确保异步验证流程完成。