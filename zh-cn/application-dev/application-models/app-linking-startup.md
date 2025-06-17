# 使用App Linking实现应用间跳转

## 简介

使用App Linking进行跳转时，系统会根据接口传入的uri信息（HTTPS链接）将用户引导至目标应用中的特定内容，无论应用是否已安装，用户都可以访问到链接对应的内容，整个跳转体验相比[Deep Linking](deep-linking-startup.md)方式更加顺畅。


## 适用场景

* 适用于对安全性要求较高的场景，避免出现目标应用被其它应用仿冒的问题。

* 适用于对体验要求较高的场景，不管目标应用是否安装，用户点击该链接都可以正常访问。

## 实现原理

* App Linking在Deep Linking基础上增加了域名校验环节，通过域名校验，可帮助用户消除歧义，识别合法归属于域名的应用，使链接更加安全可靠。

* App Linking要求对于同一HTTPS网址，有应用和网页两种内容的呈现方式。当应用安装时则优先打开应用去呈现内容；当应用未安装时，则打开浏览器呈现Web版的内容。


## 目标应用操作指导

目标应用如需支持App Linking功能，需要执行如下操作：

1. 声明应用关联的网站域名。
2. 在开发者网站上关联应用。
3. 添加代码到应用的Ability中，以处理传入的链接。


### 声明应用关联的网站域名

在应用的[module.json5配置文件](../quick-start/module-configuration-file.md)中进行如下配置，以声明应用关联的域名地址，并开启域名校验开关。

* "actions"列表中包含"ohos.want.action.viewData"。
* "entities"列表中包含"entity.system.browsable"。
* "uris"列表中包含"scheme"为"https"且"host"为域名地址的元素。
* "domainVerify"：设置为true，表示开启域名校验开关。

> **说明**：
>
> skills标签下默认包含一个skill对象，用于标识应用入口。应用跳转链接不能在该skill对象中配置，需要创建独立的skill对象。如果存在多个跳转场景，需要在skills标签下创建不同的skill对象，否则会导致配置无法生效。


例如，声明应用关联在域名是www.example.com，则需进行如下配置：

```json
{
  "module": {
    // ...
    "abilities": [
      {
        // ...
        "skills": [
          {
            "entities": [
              "entity.system.home"
            ],
            "actions": [
              "ohos.want.action.home"
            ]
          },
          {
            "entities": [
              // entities须包含"entity.system.browsable"
              "entity.system.browsable"
            ],
            "actions": [
              // actions须包含"ohos.want.action.viewData"
              "ohos.want.action.viewData"
            ],
            "uris": [
              {
                // scheme须配置为https
                "scheme": "https",
                // host须配置关联的域名
                "host": "www.example.com",
                // path可选，为了避免匹配到多个应用，建议配置该字段
                "path": "path1"
              }
            ],
            // domainVerify须设置为true
           "domainVerify": true
          } // 新增一个skill对象，用于跳转场景。如果存在多个跳转场景，需配置多个skill对象。
        ]
      }
    ]
  }
}
```


### 在开发者网站上关联应用

在开发者的网站上做如下配置，以关联应用。

1. 创建域名配置文件applinking.json。

   内容为如下：

   ```json
   {
    "applinking": {
      "apps": [
        {
          "appIdentifier": "1234"
        }
      ]
    }
   }
   ```

   `app-identifer`是在应用签名阶段为应用分配的唯一标识，即[HarmonyAppProvision配置文件](../security/app-provision-structure.md)中声明的`app-identifer`字段的值。

1. 将配置文件放在域名服务器的固定目录下。
   固定目录为：
   > https://*your.domain.name*/.well-known/applinking.json

   例如开发者的域名为www.example.com，则需将applinking.json文件放在如下位置：
   `https://www.example.com/.well-known/applinking.json`


### 添加代码到应用的Ability中以处理传入的链接

在应用的Ability(如EntryAbility)的onCreate()或者onNewWant()生命周期回调中添加代码，以处理传入的链接。

```ts
import { AbilityConstant, UIAbility, Want } from '@kit.AbilityKit';
import { url } from '@kit.ArkTS';

export default class EntryAbility extends UIAbility {
  onCreate(want: Want, launchParam: AbilityConstant.LaunchParam): void {
    // 从want中获取传入的链接信息。
    // 如传入的url为：https://www.example.com/programs?action=showall
    let uri = want?.uri 
    if (uri) {
      // 从链接中解析query参数，拿到参数后，开发者可根据自己的的务需求进行后续的处理。
      let urlObject = url.URL.parseURL(want?.uri);
      let action = urlObject.params.get('action')
      // 例如，当action为showall时，展示所有的节目。
      if (action === "showall") {
         // ...
      }
    }
  }
}
```



## 拉起方应用实现应用跳转

拉起方应用通过UIAbilityContext.openLink接口，传入目标应用的链接，拉起目标应用。

openLink接口提供了两种拉起目标应用的方式，开发者可根据业务需求进行选择。

  - **方式一：** 仅以App Linking的方式打开应用
     将`appLinkingOnly`参数设为true，若有匹配的应用，则直接打开目标应用。若无App Linking匹配的应用，则抛异常给开发者进行处理。

  - **方式二：** 以App Linking优先的方式打开应用
     将`appLinkingOnly`参数设为false或者默认，则为App Linking优先的方式打开应用。若有App Linking匹配的应用，则直接打开目标应用。若无App Linking匹配的应用，则尝试以Deep Linking的方式打开应用。

本文为了方便验证App Linking的配置是否正确，选择方式一，示例如下。

```ts
import common from '@ohos.app.ability.common';
import { BusinessError } from '@ohos.base';

@Entry
@Component
struct Index {
  build() {
    Button('start link', { type: ButtonType.Capsule, stateEffect: true })
      .width('87%')
      .height('5%')
      .margin({ bottom: '12vp' })
      .onClick(() => {
        let context: common.UIAbilityContext = this.getUIContext().getHostContext() as common.UIAbilityContext;
        let link: string = "https://www.example.com/programs?action=showall";
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

在拉起方应用中执行上述代码，如果能够成功拉起目标应用，表明目标应的App Linking配置正确。

## FAQ


1. 应用的Modules.json5文件skills设置不正确。

   检查"host"字段中是否是应用所对应的域名。

2. 开发者网站服务器配置不正确。

   * 检查服务器的 JSON 配置，并确保 `appIdentifier` 的值正确无误。
   * 检查`applinking.json`是否放置在正确的目录(`.well-known`)下，通过浏览器等方式访问该json文件的地址：https://*your.domain.name*/.well-known/applinking.json，确保能正常访问。

3. 系统尚未完成域名校验。

   在设备上安装应用，需等待至少20秒，确保异步验证流程完成。

4. 应用和域名的对应关系是怎样的？

   应用和域名的关系是多对多的关系：一个应用可以关联多个不同的域名，同样的，一个域名也可以关联多个不同的应用。

5. 如果同一域名关联了多个应用，那么该域名的链接将拉起哪个应用呢？

   开发者可以通过配置applinking.json以关联多个应用。如果每个应用的module.json5的uris字段配置的都是一样的，那么系统将弹出列表框供用户选择要拉起的目标应用。
   为了更好的体验，开发者也可以通过链接的path去区分拉起的目标应用，如链接`https://www.example.com/path1`拉起目标应用1，链接`https://www.example.com/path2`拉起目标应用2。
  