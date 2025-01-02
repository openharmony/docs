# Managing Cookies and Data Storage


## Cookie Management

A cookie is a segment of data sent from the server to the client to uniquely identify a user during network access. The client may hold the data and provide it to the server at later interactions so that the server can quickly identify the client identity and status.

When the **SameSite** attribute of a cookie is not specified, the default value is **SameSite=Lax**. The cookie is sent only when the user navigates to the source site of the cookie and is not sent in cross-site requests.

The **Web** component provides the [WebCookieManager](../reference/apis-arkweb/js-apis-webview.md#webcookiemanager) class for you to manage cookie information, which is stored in the **/proc/{pid}/root/data/storage/el2/base/cache/web/Cookiesd** file in the application sandbox path.

The following uses [configCookieSync()](../reference/apis-arkweb/js-apis-webview.md#configcookiesync11) as an example to describe how to set a cookie's value to **value=test** for **www\.example.com**. For details about functions and usage of other APIs, see [WebCookieManager()](../reference/apis-arkweb/js-apis-webview.md#webcookiemanager).


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


## Cache and Storage Management

Network resource requests are relatively time-consuming during website access. You can store resources locally by means of **cache** and **Dom Storage** to fasten the access to the same website.


### Cache

Use [cacheMode()](../reference/apis-arkweb/ts-basic-components-web.md#cachemode) to configure the cache mode for page resources. Four cache modes are supported:

- **Default**: Page resources in a cache that has not expired are preferentially used. If the cache does not exist, page resources are obtained from the network.

- **None**: Page resources are loaded from the cache. If the cache does not exist, page resources are obtained from the network.

- **Online**: Page resources are not loaded from the cache. All resources are obtained from the network.

- **Only**: Page resources are only loaded from the cache.


In the following example, the cache mode is set to **None**.



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


  To obtain up-to-date resources, you can use [removeCache()](../reference/apis-arkweb/js-apis-webview.md#removecache) to clear cached resources. The sample code is as follows:

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
            // If this parameter is set to true, the cache in both the ROM and RAM is cleared. If this parameter is set to false, only the cache in the RAM is cleared.
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

Dom Storage falls into Session Storage and Local Storage. Wherein, Session Storage applies to the temporary data, and its data storage and release follow the session lifecycle; Local Storage applies to the persistent data, which is flushed to the application directory. In both storage modes, data is stored in a form of key-value pair, and is usually used when a page that needs to be stored on the client is accessed. You can use [domStorageAccess()](../reference/apis-arkweb/ts-basic-components-web.md#domstorageaccess) to enable Dom Storage. The following is the sample code:



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
