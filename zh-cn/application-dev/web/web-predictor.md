# 加速Web页面的访问

当Web页面加载缓慢时，可以使用预连接、预加载和预获取post请求的能力加速Web页面的访问。

## 预解析和预连接

可以通过[prepareForPageLoad()](../reference/apis-arkweb/js-apis-webview.md#prepareforpageload10)来预解析或者预连接将要加载的页面。

  在下面的示例中，在Web组件的onAppear中对要加载的页面进行预连接。

```ts
// xxx.ets
import web_webview from '@ohos.web.webview';

@Entry
@Component
struct WebComponent {
  webviewController: web_webview.WebviewController = new web_webview.WebviewController();
  build() {
    Column() {
      Button('loadData')
        .onClick(() => {
          if (this.webviewController.accessBackward()) {
            this.webviewController.backward();
          }
        })
      Web({ src: 'https://www.example.com/', controller: this.webviewController})
        .onAppear(() => {
            // 指定第二个参数为true，代表要进行预连接，如果为false该接口只会对网址进行dns预解析
            // 第三个参数为要预连接socket的个数。最多允许6个。
            web_webview.WebviewController.prepareForPageLoad('https://www.example.com/', true, 2);
        })
    }
  }
}
```

也可以通过[initializeBrowserEngine()](../reference/apis-arkweb/js-apis-webview.md#initializewebengine)来提前初始化内核，然后在初始化内核后调用
[prepareForPageLoad()](../reference/apis-arkweb/js-apis-webview.md#prepareforpageload10)对即将要加载的页面进行预解析、预连接。这种方式适合提前对首页进行
预解析、预连接。

  在下面的示例中，Ability的onCreate中提前初始化Web内核并对首页进行预连接。

```ts
// xxx.ets
import UIAbility from '@ohos.app.ability.UIAbility';
import web_webview from '@ohos.web.webview';
import AbilityConstant from '@ohos.app.ability.AbilityConstant';
import Want from '@ohos.app.ability.Want';

export default class EntryAbility extends UIAbility {
    onCreate(want: Want, launchParam: AbilityConstant.LaunchParam) {
        console.log("EntryAbility onCreate");
        web_webview.WebviewController.initializeWebEngine();
        // 预连接时，需要將'https://www.example.com'替换成真实要访问的网站地址。
        web_webview.WebviewController.prepareForPageLoad("https://www.example.com/", true, 2);
        AppStorage.setOrCreate("abilityWant", want);
        console.log("EntryAbility onCreate done");
    }
}
```

## 预加载

如果能够预测到Web组件将要加载的页面或者即将要跳转的页面。可以通过[prefetchPage()](../reference/apis-arkweb/js-apis-webview.md#prefetchpage10)来预加载即将要加载页面。

预加载会提前下载页面所需的资源，包括主资源子资源，但不会执行网页JavaScript代码。预加载是WebviewController的实例方法，需要一个已经关联好Web组件的WebviewController实例。

在下面的示例中，在onPageEnd的时候触发写一个要访问的页面的预加载。
  
```ts
// xxx.ets
import web_webview from '@ohos.web.webview';

@Entry
@Component
struct WebComponent {
  webviewController: web_webview.WebviewController = new web_webview.WebviewController();
  build() {
    Column() {
      Web({ src: 'https://www.example.com/', controller: this.webviewController})
        .onPageEnd(() => {
            // 预加载https://www.iana.org/help/example-domains。
            this.webviewController.prefetchPage('https://www.iana.org/help/example-domains');
        })
    }
  }
}
```

## 预获取post请求

可以通过[prefetchResource()](../reference/apis-arkweb/js-apis-webview.md#prefetchresource12)预获取将要加载页面中的post请求。在页面加载结束时，可以通过[clearPrefetchedResource()](../reference/apis-arkweb/js-apis-webview.md#clearprefetchedresource12)清除后续不再使用的预获取资源缓存。

  以下示例，在Web组件onAppear中，对要加载页面中的post请求进行预获取。在onPageEnd中，可以清除预获取的post请求缓存。

```ts
// xxx.ets
import web_webview from '@ohos.web.webview';

@Entry
@Component
struct WebComponent {
  webviewController: web_webview.WebviewController = new web_webview.WebviewController();
  build() {
    Column() {
      Web({ src: "https://www.example.com/", controller: this.webviewController})
        .onAppear(() => {
            // 预获取时，需要將"https://www.example1.com/post?e=f&g=h"替换成真实要访问的网站地址。
            web_webview.WebviewController.prefetchResource(
              {url:"https://www.example1.com/post?e=f&g=h",
              method:"POST",
              formData:"a=x&b=y",},
              [{headerKey:"c",
                headerValue:"z",},],
              "KeyX", 500);
        })
        .onPageEnd(() => {
            // 清除后续不再使用的预获取资源缓存。
            web_webview.WebviewController.clearPrefetchedResource(["KeyX",]);
        })
    }
  }
}
```

如果能够预测到Web组件将要加载页面或者即将要跳转页面中的post请求。可以通过[prefetchResource()](../reference/apis-arkweb/js-apis-webview.md#prefetchresource12)预获取即将要加载页面的post请求。

  以下示例，在onPageEnd中，触发预获取一个要访问页面的post请求。

```ts
// xxx.ets
import web_webview from '@ohos.web.webview';

@Entry
@Component
struct WebComponent {
  webviewController: web_webview.WebviewController = new web_webview.WebviewController();
  build() {
    Column() {
      Web({ src: 'https://www.example.com/', controller: this.webviewController})
        .onPageEnd(() => {
            // 预获取时，需要將"https://www.example1.com/post?e=f&g=h"替换成真实要访问的网站地址。
            web_webview.WebviewController.prefetchResource(
              {url:"https://www.example1.com/post?e=f&g=h",
              method:"POST",
              formData:"a=x&b=y",},
              [{headerKey:"c",
                headerValue:"z",},],
              "KeyX", 500);
        })
    }
  }
}
```

也可以通过[initializeBrowserEngine()](../reference/apis-arkweb/js-apis-webview.md#initializewebengine)提前初始化内核，然后在初始化内核后调用[prefetchResource()](../reference/apis-arkweb/js-apis-webview.md#prefetchresource12)预获取将要加载页面中的post请求。这种方式适合提前预获取首页的post请求。

  以下示例，在Ability的onCreate中，提前初始化Web内核并预获取首页的post请求。

```ts
// xxx.ets
import UIAbility from '@ohos.app.ability.UIAbility';
import web_webview from '@ohos.web.webview';
import AbilityConstant from '@ohos.app.ability.AbilityConstant';
import Want from '@ohos.app.ability.Want';

export default class EntryAbility extends UIAbility {
    onCreate(want: Want, launchParam: AbilityConstant.LaunchParam) {
        console.log("EntryAbility onCreate");
        web_webview.WebviewController.initializeWebEngine();
        // 预获取时，需要將"https://www.example1.com/post?e=f&g=h"替换成真实要访问的网站地址。
        web_webview.WebviewController.prefetchResource(
          {url:"https://www.example1.com/post?e=f&g=h",
          method:"POST",
          formData:"a=x&b=y",},
          [{headerKey:"c",
            headerValue:"z",},],
          "KeyX", 500);
        AppStorage.setOrCreate("abilityWant", want);
        console.log("EntryAbility onCreate done");
    }
}
```
