# 使用Deep Linking实现应用间跳转

采用Deep Linking进行跳转时，系统会根据接口中传入的uri信息，在本地已安装的应用中寻找到符合条件的应用并进行拉起。当匹配到多个应用时，会拉起应用选择框。

## 实现原理

Deep Linking基于隐式Want匹配机制中的uri匹配来查询、拉起目标应用。隐式Want的uri匹配规则详见[uri匹配规则](explicit-implicit-want-mappings.md#uri匹配规则)。


## 目标应用在配置文件中注册应用链接

为了能够支持被其他应用访问，目标应用需要在[module.json5配置文件](../quick-start/module-configuration-file.md)的skills字段中声明应用链接。其中，uri字段的scheme的取值支持自定义，可以定义为任意不包含特殊字符、非`ohos`开头的字符串。

> **说明：**
> 
> Deep Linking中的scheme取值通常不为https、http、file，否则会拉起默认的系统浏览器。



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
            "actions": [
              // actions不能为空，actions为空会造成目标方匹配失败
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
          }
        ]
      }
    ]
  }
}
```


## 拉起方应用实现应用跳转

下面通过三个案例，分别介绍如何使用[openLink()](../reference/apis-ability-kit/js-apis-inner-application-uiAbilityContext.md#uiabilitycontextopenlink12)与[startAbility()](../reference/apis-ability-kit/js-apis-inner-application-uiAbilityContext.md#uiabilitycontextstartability)接口实现应用跳转，以及如何在[Web组件](../reference/apis-arkweb/ts-basic-components-web.md)中实现应用跳转。

### 使用openLink实现应用跳转

在[openLink](../reference/apis-ability-kit/js-apis-inner-application-uiAbilityContext.md#uiabilitycontextopenlink12)接口的link字段中传入目标应用的URL信息，并将options字段中的`appLinkingOnly`配置为`false`。


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
        let link: string = "link://www.example.com";
        let openLinkOptions: OpenLinkOptions = {
          appLinkingOnly: false
        };

        try {
          context.openLink(link, openLinkOptions)
            .then(() => {
              hilog.info(DOMAIN_NUMBER, TAG, 'open link success.');
            }).catch((err: BusinessError) => {
              hilog.error(DOMAIN_NUMBER, TAG, `open link failed. Code is ${err.code}, message is ${err.message}`);
            });
        } catch (paramError) {
          hilog.error(DOMAIN_NUMBER, TAG, `Failed to start link. Code is ${paramError.code}, message is ${paramError.message}`);
        }
      })
  }
}
```

### 使用startAbility实现应用跳转

[startAbility](../reference/apis-ability-kit/js-apis-inner-application-uiAbilityContext.md#uiabilitycontextstartability)接口是将应用链接放入want中，通过调用[隐式want匹配](explicit-implicit-want-mappings.md#隐式want匹配原理)的方法触发应用跳转。通过[startAbility](../reference/apis-ability-kit/js-apis-inner-application-uiAbilityContext.md#uiabilitycontextstartability)接口启动时，还需要自己传入待匹配的action和entity。


示例代码如下：

```ts
import { common, Want } from '@kit.AbilityKit';
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
            uri: "link://www.example.com"
        };

        try {
          context.startAbility(want).then(() => {
            hilog.info(DOMAIN_NUMBER, TAG, 'start ability success.');
          }).catch((err: BusinessError) => {
            hilog.error(DOMAIN_NUMBER, TAG, `start ability failed. Code is ${err.code}, message is ${err.message}`);
          });
        } catch (paramError) {
          hilog.error(DOMAIN_NUMBER, TAG, `Failed to start ability. Code is ${paramError.code}, message is ${paramError.message}`);
        }
      })
  }
}
```

### 使用Web组件实现应用跳转

Web组件需要跳转DeepLink链接应用时，可通过拦截回调[onLoadIntercept](../reference/apis-arkweb/ts-basic-components-web.md#onloadintercept10)中对定义的事件进行处理，实现应用跳转。

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
            (getContext() as common.UIAbilityContext).openLink(url)
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