# Managing Cookies and Data Storage

Cookies are data sent from the server to the client. The client holds cookies so that the server can quickly identify its identity and status.

For cookies, the default value of **SameSite** is **Lax**, indicating that cookies are sent only when a user navigates to the source site and are not sent in cross-site requests.

## Cookie Management

The **Web** component provides the [WebCookieManager](../reference/apis-arkweb/arkts-apis-webview-WebCookieManager.md) class to manage cookie information. Cookies are stored in the **/proc/{pid}/root/data/storage/el2/base/cache/web/Cookies** file in the application sandbox directory.

The following uses the [configCookieSync()](../reference/apis-arkweb/arkts-apis-webview-WebCookieManager.md#configcookiesync11) API to set a cookie value to **test** for **www\.example.com**. For details about features and usage of other APIs, see [WebCookieManager()](../reference/apis-arkweb/arkts-apis-webview-WebCookieManager.md).


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

> **NOTE**
>
> Cookies are saved to disks every 30 seconds. You can also use the [saveCookieAsync](../reference/apis-arkweb/arkts-apis-webview-WebCookieManager.md#savecookieasync) API to forcibly save cookies to disks. (Even if **saveCookieAsync** is called, session cookies are not written to disks in PCs/2-in-1 devices and tablets.)

## Cache and Storage Management

Network resource requests are relatively time-consuming during website access. You can store resources locally by means of **cache** and **Dom Storage** to fasten the access to the same website.


### Cache

Use [cacheMode()](../reference/apis-arkweb/arkts-basic-components-web-attributes.md#cachemode) to configure the cache mode for page resources. Four cache modes are supported:

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


To obtain up-to-date resources, you can use [removeCache()](../reference/apis-arkweb/arkts-apis-webview-WebviewController.md#removecache) to clear cached resources. The sample code is as follows:

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

Dom Storage falls into Session Storage and Local Storage. Session Storage holds temporary data and it is stored and released based on the session lifecycle. Local Storage holds persistent data and is stored in the application directory. In both storage modes, data is stored in a form of key-value pair, and used when a page that needs to be stored on the client is accessed. You can use [domStorageAccess()](../reference/apis-arkweb/arkts-basic-components-web-attributes.md#domstorageaccess) to enable Dom Storage. The following is the sample code:



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
