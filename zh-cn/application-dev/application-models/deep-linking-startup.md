# 使用Deep Linking实现应用间跳转

<!--Kit: Ability Kit-->
<!--Subsystem: Ability-->
<!--Owner: @hanchen45; @Luobniz21-->
<!--Designer: @ccllee1-->
<!--Tester: @lixueqing513-->
<!--Adviser: @huipeizi-->

采用Deep Linking进行跳转时，系统会根据接口中传入的uri信息，在本地已安装的应用中寻找到符合条件的应用并进行拉起。当匹配到多个应用时，会拉起应用选择框。

## 实现原理

Deep Linking基于隐式Want匹配机制中的uri匹配来查询、拉起目标应用。隐式Want的uri匹配规则详见[uri匹配规则](explicit-implicit-want-mappings.md#uri匹配规则)。


## 目标应用操作指导

### 配置module.json5文件

为了能够支持被其他应用访问，目标应用需要在[module.json5配置文件](../quick-start/module-configuration-file.md)中配置[skills标签](../quick-start/module-configuration-file.md#skills标签)。

> **说明：**
> 
> skills标签下默认包含一个skill对象，用于标识应用入口。应用跳转链接不能在该skill对象中配置，需要创建独立的skill对象。如果存在多个跳转场景，需要在skills标签下创建不同的skill对象，否则会导致配置无法生效。
> 
> Deep Linking中的scheme取值不以"ohos"开头。通常不为"https"、"http"、"file"等已被系统应用使用的值，否则会匹配到对应的系统应用。


配置示例如下：

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
            "actions": [
              // actions不能为空，actions为空会造成目标方匹配失败。
              "ohos.want.action.viewData"
            ],
            "uris": [
              {
                // scheme必选，可以自定义，以link为例，需要替换为实际的scheme
                "scheme": "link",
                // host必选，配置待匹配的域名
                "host": "www.example.com"
              }
            ]
          } // 新增一个skill对象，用于跳转场景。如果存在多个跳转场景，需配置多个skill对象。
        ]
      }
    ]
  }
}
```

### 获取并解析拉起方传入的应用链接

在目标应用的UIAbility的[onCreate()](../reference/apis-ability-kit/js-apis-app-ability-uiAbility.md#oncreate)或者[onNewWant()](../reference/apis-ability-kit/js-apis-app-ability-uiAbility.md#onnewwant)生命周期回调中，获取、解析拉起方传入的应用链接。

```ts
// 以EntryAbility.ets为例
import { AbilityConstant, UIAbility, Want } from '@kit.AbilityKit';
import { url } from '@kit.ArkTS';

export default class EntryAbility extends UIAbility {
  onCreate(want: Want, launchParam: AbilityConstant.LaunchParam): void {
    // 从want中获取传入的链接信息。
    // 如传入的url为：link://www.example.com/programs?action=showall
    let uri = want?.uri;
    if (uri) {
      // 从链接中解析query参数，拿到参数后，开发者可根据自己的业务需求进行后续的处理。
      let urlObject = url.URL.parseURL(want?.uri);
      let action = urlObject.params.get('action');
      // 例如，当action为showall时，展示所有的节目。
      if (action === "showall") {
         // ...
      }
    }
  }
}
```

## 拉起方应用实现应用跳转

下面通过三个案例，分别介绍如何使用[openLink()](../reference/apis-ability-kit/js-apis-inner-application-uiAbilityContext.md#openlink12)与[startAbility()](../reference/apis-ability-kit/js-apis-inner-application-uiAbilityContext.md#startability)接口实现应用跳转，以及如何在[Web组件](../reference/apis-arkweb/arkts-basic-components-web.md)中实现应用跳转。

### 使用openLink实现应用跳转

在[openLink](../reference/apis-ability-kit/js-apis-inner-application-uiAbilityContext.md#openlink12)接口的link字段中传入目标应用的URL信息，并将options字段中的[appLinkingOnly](../reference/apis-ability-kit/js-apis-app-ability-openLinkOptions.md#openlinkoptions)配置为`false`。


示例代码如下：

```ts
import { common, OpenLinkOptions } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { hilog } from '@kit.PerformanceAnalysisKit';

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
        let context = this.getUIContext().getHostContext() as common.UIAbilityContext;
        let link: string = "link://www.example.com";
        let openLinkOptions: OpenLinkOptions = {
          appLinkingOnly: false
        };

        try {
          context.openLink(link, openLinkOptions)
            .then(() => {
              hilog.info(DOMAIN_NUMBER, TAG, 'openLink success.');
            }).catch((err: BusinessError) => {
              hilog.error(DOMAIN_NUMBER, TAG, `openLink failed. Code is ${err.code}, message is ${err.message}`);
            });
        } catch (paramError) {
          hilog.error(DOMAIN_NUMBER, TAG, `Failed to start link. Code is ${paramError.code}, message is ${paramError.message}`);
        }
      })
  }
}
```

### 使用startAbility实现应用跳转

[startAbility](../reference/apis-ability-kit/js-apis-inner-application-uiAbilityContext.md#startability)接口是将应用链接放入want中，通过调用[隐式want匹配](explicit-implicit-want-mappings.md#隐式want匹配原理)的方法触发应用跳转。


示例代码如下：

```ts
import { common, Want } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { hilog } from '@kit.PerformanceAnalysisKit';

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
        let context = this.getUIContext().getHostContext() as common.UIAbilityContext;
        let want: Want = {
          uri: "link://www.example.com"
        };

        try {
          context.startAbility(want).then(() => {
            hilog.info(DOMAIN_NUMBER, TAG, 'startAbility success.');
          }).catch((err: BusinessError) => {
            hilog.error(DOMAIN_NUMBER, TAG, `startAbility failed. Code is ${err.code}, message is ${err.message}`);
          });
        } catch (paramError) {
          hilog.error(DOMAIN_NUMBER, TAG, `Failed to start ability. Code is ${paramError.code}, message is ${paramError.message}`);
        }
      })
  }
}
```

### 使用Web组件实现应用跳转

Web组件可以在[onLoadIntercept](../reference/apis-arkweb/arkts-basic-components-web-events.md#onloadintercept10)的回调函数中实现应用跳转。

示例代码如下：

```ts
// index.ets
import { webview } from '@kit.ArkWeb';
import { BusinessError } from '@kit.BasicServicesKit';
import { common } from '@kit.AbilityKit';

@Entry
@Component
struct WebComponent {
  controller: webview.WebviewController = new webview.WebviewController();

  build() {
    Column() {
      Web({ src: $rawfile('index.html'), controller: this.controller })
        .onLoadIntercept((event) => {
          const url: string = event.data.getRequestUrl();
          if (url === 'link://www.example.com') {
            (this.getUIContext().getHostContext() as common.UIAbilityContext).openLink(url)
              .then(() => {
                console.log('openLink success');
              }).catch((err: BusinessError) => {
                console.error('openLink failed, err:' + JSON.stringify(err));
              });
            return true;
          }
          // 返回true表示阻止此次加载，否则允许此次加载
          return false;
        })
    }
  }
}
```

前端页面代码：
```html
// index.html
<!DOCTYPE html>
<html>
<head>
    <meta charset="UTF-8">
</head>
<body>
<h1>Hello World</h1>
<!--方式一、通过绑定事件window.open方法实现跳转-->
<button class="doOpenLink" onclick="doOpenLink()">跳转其他应用一</button>
<!--方式二、通过超链接实现跳转-->
<a href="link://www.example.com">跳转其他应用二</a>
</body>
</html>
<script>
    function doOpenLink() {
        window.open("link://www.example.com")
    }
</script>
```