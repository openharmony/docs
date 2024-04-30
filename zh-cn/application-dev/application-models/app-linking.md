# App Linking开发指南

## 简介

App Linking是通过https链接直接将用户带到应用程序中的特定内容的一种技术。 App Linking可以增加应用程序的流量，帮助开发者发现最常使用的应用程序内容，并使用户更流畅的浏览已安装应用程序中的内容。

相比Deeplink技术，App Linking更安全可靠，体验更佳。

1. 使用Deeplink技术的场景下，多个应用可以配置相同的域名等链接信息，系统无法识别哪个是受信应用，存在被仿冒的可能。而App Linking通过域名校验技术可以帮助用户消除歧义，识别受信任的目标应用，并直达受信任的目标应用。
2. 由于App Linking 利用的是HTTPS网址以及与网站的关联，若目标应用未安装，会直接跳转到浏览器打开相应的网页。

## 集成指南

若要使用App Linking功能，需要做如下操作：

* 声明应用关联的网站域名
* 添加代码到应用的Ability中以处理传入的链接
* 在开发者网站上关联应用
* 验证App Linking是否正常工作

### 声明应用关联的网站域名

在应用的module.json5文件中进行如下配置，以声明应用关联的域名地址，并开启域名校验开关。

* "actions"列表中包含"ohos.want.action.viewData"。
* "entities"列表中包含"entity.system.browsable"。
* "uris"列表中包含"scheme"为"https"且"domainVerify"为true的元素。
  uri的匹配规则参考[uri匹配](explicit-implicit-want-mappings.md#uri匹配规则),
  domainVerify为true代表开启域名校验开关。

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

* 注意
  modules.json5的各个参数配置的说明详见：[module.json5配置文件](../quick-start/module-configuration-file.md)

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

### 验证App Linking是否正常工作

编写demo应用，通过UIAbilityContext.openLink接口，传入应用的链接，拉起目标应用。

* 注意：
  openLink接口提供了两种拉起目标应用的方式，开发者可根据业务需求进行选择。

  1. 仅以App Linking的方式打开应用
     将`appLinkingOnly`参数设为true，若有匹配的应用，则直接打开目标应用。若无App Linking匹配的应用，则抛异常给开发者进行处理。
  2. App Linking优先的方式打开应用
     将`appLinkingOnly`参数设为false或者默认，则为App Linking优先的方式打开应用。若有App Linking匹配的应用，则直接打开目标应用。若无App Linking匹配的应用，则尝试以deeplink的方式打开应用。

  为了方便验证App Linking是否配置正确，此处选择方式1进行示例。

```ts
import common from '@ohos.app.ability.common'
import { BusinessError } from '@ohos.base'

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
        // 仅以App Linking的方式打开应用
        context.openLink(link, { appLinkingOnly: true })
          .then(() => {
            console.info('openlink success.');
          })
          .catch((error: BusinessError) => {
            console.error(`openlink failed. error:${JSON.stringify(error)}`);
          });
      })
  }
}
```

在demo应用中执行上述代码，如果demo应用成功拉起目标应用，则成功配置App Linking。

### FAQ

1. App Linking支持的系统版本
   OpenHarmony 5.0及最新版本

2. 应用的Modules.json5文件skills设置不正确
   检查"host"字段中是否是应用所对应的域名。

3. 服务器配置不正确
   检查服务器的 JSON 配置，并确保 `appIdentifier` 的值正确无误。

4. 系统尚未完成域名校验
   在设备上安装应用，需等待至少 20 秒，确保异步验证流程完成。