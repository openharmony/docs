# 管理Cookie及数据存储

Cookie是服务端发送客户端的数据。客户端持有Cookie，便于服务端快速识别身份和状态。

当Cookie的SameSite属性未指定时，默认值为SameSite=Lax。这种设置下，Cookie仅在用户导航到其源站点时发送，不会在跨站请求中发送。

## Cookie管理

Web组件提供[WebCookieManager](../reference/apis-arkweb/js-apis-webview-WebCookieManager.md#class-webcookiemanager)类来管理Cookie信息。Cookie信息存储在应用沙箱路径下/proc/{pid}/root/data/storage/el2/base/cache/web/Cookies的文件中。

下面以[configCookieSync()](../reference/apis-arkweb/js-apis-webview-WebCookieManager.md#configcookiesync11)接口为例，为“www\.example.com”设置单个Cookie的值“value=test”。其他Cookie的相关功能及使用，请参考[WebCookieManager()](../reference/apis-arkweb/js-apis-webview-WebCookieManager.md#class-webcookiemanager)接口文档。


```ts
// xxx.ets
import { webview } from '@kit.ArkWeb';
import { BusinessError } from '@kit.BasicServicesKit';

@Entry
@Component
struct WebComponent {
  controller: webview.WebviewController = new webview.WebviewController();

  build() {
    Column() {
      Button('configCookieSync')
        .onClick(() => {
          try {
            webview.WebCookieManager.configCookieSync('https://www.example.com', 'value=test');
          } catch (error) {
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
          }
        })
      Web({ src: 'www.example.com', controller: this.controller })
    }
  }
}
```

> **说明：**
>
> Cookie每30s周期性保存到磁盘中，也可以使用接口[saveCookieAsync](../reference/apis-arkweb/js-apis-webview-WebCookieManager.md#savecookieasync)进行强制落盘。

## 缓存与存储管理

在访问网站时，网络资源请求通常需要较长的时间。开发者可以通过Cache和Dom Storage等手段将资源保存到本地，以提高访问同一网站的速度。


### Cache

使用[cacheMode()](../reference/apis-arkweb/ts-basic-components-web-attributes.md#cachemode)配置页面资源的缓存模式，Web组件为开发者提供四种缓存模式，分别为：

- Default：优先使用未过期的缓存。如果缓存不存在，则从网络获取。

- None：加载资源使用缓存。如果缓存中无该资源，则从网络中获取。

- Online：加载资源不使用缓存。全部从网络中获取。

- Only：只从缓存中加载资源。


在下面的示例中，缓存设置为None模式。



```ts
// xxx.ets
import { webview } from '@kit.ArkWeb';

@Entry
@Component
struct WebComponent {
  @State mode: CacheMode = CacheMode.None;
  controller: webview.WebviewController = new webview.WebviewController();

  build() {
    Column() {
      Web({ src: 'www.example.com', controller: this.controller })
        .cacheMode(this.mode)
    }
  }
}
```


为了获取最新资源，开发者可以通过[removeCache()](../reference/apis-arkweb/js-apis-webview-WebviewController.md#removecache)接口清除已经缓存的资源，示例代码如下：

```ts
// xxx.ets
import { webview } from '@kit.ArkWeb';
import { BusinessError } from '@kit.BasicServicesKit';

@Entry
@Component
struct WebComponent {
  @State mode: CacheMode = CacheMode.None;
  controller: webview.WebviewController = new webview.WebviewController();

  build() {
    Column() {
      Button('removeCache')
        .onClick(() => {
          try {
            // 设置为true时同时清除rom和ram中的缓存，设置为false时只清除ram中的缓存
            this.controller.removeCache(true);
          } catch (error) {
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
          }
        })
      Web({ src: 'www.example.com', controller: this.controller })
        .cacheMode(this.mode)
    }
  }
}
```


### Dom Storage

Dom Storage包含了Session Storage和Local Storage两类。Session Storage为临时数据，其存储与释放跟随会话生命周期；Local Storage为持久化数据，保存在应用目录下。两者的数据均通过Key-Value的形式存储，在访问需要客户端存储的页面时使用。开发者可以通过Web组件的属性接口[domStorageAccess()](../reference/apis-arkweb/ts-basic-components-web-attributes.md#domstorageaccess)进行使能配置，示例如下：



```ts
// xxx.ets
import { webview } from '@kit.ArkWeb';

@Entry
@Component
struct WebComponent {
  controller: webview.WebviewController = new webview.WebviewController();

  build() {
    Column() {
      Web({ src: 'www.example.com', controller: this.controller })
        .domStorageAccess(true)
    }
  }
}
```
