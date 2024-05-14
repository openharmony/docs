# 使用隐私模式 


开发者在创建Web组件时，可以将可选参数[incognitoMode](../reference/apis-arkweb/ts-basic-components-web.md#incognitomode)设置为'true'，来开启Web组件的隐私模式。 当使用隐私模式时，浏览网页时的cookies、 cache data 等数据不会保存在本地的持久化文件，当隐私模式的Web组件被销毁时，cookies、 cache data等数据将不被记录下来。

- 创建隐私模式的[Web组件](../reference/apis-arkweb/ts-basic-components-web.md#web)。
 
   ```ts
  // xxx.ets
  import web_webview from '@ohos.web.webview'

  @Entry
  @Component
  struct WebComponent {
    controller: web_webview.WebviewController = new web_webview.WebviewController()
    build() {
      Column() {
        Web({ src: 'www.example.com', controller: this.controller, incognitoMode: true })
      }
    }
  }
  ```

- 通过[isIncogntoMode](../reference/apis-arkweb/js-apis-webview.md#isincognitomode11) 判断当前Web组件是否是隐私模式。

  ```ts
  // xxx.ets
  import web_webview from '@ohos.web.webview'
  import business_error from '@ohos.base'

  @Entry
  @Component
  struct WebComponent {
    controller: web_webview.WebviewController = new web_webview.WebviewController();

    build() {
      Column() {
        Button('isIncognitoMode')
          .onClick(() => {
            try {
              let result = this.controller.isIncognitoMode();
              console.log('isIncognitoMode' + result);
            } catch (error) {
              let e: business_error.BusinessError = error as business_error.BusinessError;
              console.error(`ErrorCode: ${e.code},  Message: ${e.message}`);
            }
          })
        Web({ src: 'www.example.com', controller: this.controller })
      }
    }
  }
  ```

隐私模式提供了一系列接口，用于操作地理位置、Cookie以及Cache Data。

- 通过[allowGeolocation](../reference/apis-arkweb/js-apis-webview.md#allowgeolocation)设置隐私模式下的Web组件允许指定来源使用地理位置。

  ```ts
  // xxx.ets
  import web_webview from '@ohos.web.webview';
  import business_error from '@ohos.base';

  @Entry
  @Component
  struct WebComponent {
    controller: web_webview.WebviewController = new web_webview.WebviewController();
    origin: string = "file:///";

    build() {
      Column() {
        Button('allowGeolocation')
          .onClick(() => {
            try {
              // allowGeolocation第二个参数表示隐私模式（true）或非隐私模式（false）下，允许指定来源使用地理位置。
              web_webview.GeolocationPermissions.allowGeolocation(this.origin, true);
            } catch (error) {
              let e: business_error.BusinessError = error as business_error.BusinessError;
              console.error(`ErrorCode: ${e.code},  Message: ${e.message}`);
            }
          })
        Web({ src: 'www.example.com', controller: this.controller, incognitoMode: true })
      }
    }
  }
  ```

- 通过[deleteGeolocation](../reference/apis-arkweb/js-apis-webview.md#deletegeolocation)清除隐私模式下指定来源的地理位置权限状态。

  ```ts
  // xxx.ets
  import web_webview from '@ohos.web.webview';
  import business_error from '@ohos.base';

  @Entry
  @Component
  struct WebComponent {
    controller: web_webview.WebviewController = new web_webview.WebviewController();
    origin: string = "file:///";

    build() {
      Column() {
        Button('deleteGeolocation')
          .onClick(() => {
            try {
              // deleteGeolocation第二个参数表示隐私模式（true）或非隐私模式（false）下，清除指定来源的地理位置权限状态。
              web_webview.GeolocationPermissions.deleteGeolocation(this.origin, true);
            } catch (error) {
              let e: business_error.BusinessError = error as business_error.BusinessError;
              console.error(`ErrorCode: ${e.code},  Message: ${e.message}`);
            }
          })
        Web({ src: 'www.example.com', controller: this.controller, incognitoMode: true })
      }
    }
  }
  ```

- 通过[getAccessibleGeolocation](../reference/apis-arkweb/js-apis-webview.md#getaccessiblegeolocation)以回调方式异步获取隐私模式下指定源的地理位置权限状态。

  ```ts
  // xxx.ets
  import web_webview from '@ohos.web.webview';
  import business_error from '@ohos.base';

  @Entry
  @Component
  struct WebComponent {
    controller: web_webview.WebviewController = new web_webview.WebviewController();
    origin: string = "file:///";

    build() {
      Column() {
        Button('getAccessibleGeolocation')
          .onClick(() => {
            try {
              // getAccessibleGeolocation第三个参数表示隐私模式（true）或非隐私模式（false）下，以回调方式异步获取指定源的地理位置权限状态。
              web_webview.GeolocationPermissions.getAccessibleGeolocation(this.origin, (error, result) => {
                if (error) {
                  console.log('getAccessibleGeolocationAsync error: ' + JSON.stringify(error));
                  return;
                }
                console.log('getAccessibleGeolocationAsync result: ' + result);
              }, true);
            } catch (error) {
              let e: business_error.BusinessError = error as business_error.BusinessError;
              console.error(`ErrorCode: ${e.code},  Message: ${e.message}`);
            }
          })
        Web({ src: 'www.example.com', controller: this.controller, incognitoMode: true })
      }
    }
  }
  ```

- 通过[deleteAllData](../reference/apis-arkweb/js-apis-webview.md#deletealldata)清除隐私模式下Web SQL当前使用的所有存储。

  ```ts
  // xxx.ets
  import web_webview from '@ohos.web.webview';
  import business_error from '@ohos.base';

  @Entry
  @Component
  struct WebComponent {
    controller: web_webview.WebviewController = new web_webview.WebviewController();

    build() {
      Column() {
        Button('deleteAllData')
          .onClick(() => {
            try {
              // deleteAllData参数表示删除所有隐私模式（true）或非隐私模式（false）下，内存中的web数据。
              web_webview.WebStorage.deleteAllData(true);
            } catch (error) {
              let e: business_error.BusinessError = error as business_error.BusinessError;
              console.error(`ErrorCode: ${e.code},  Message: ${e.message}`);
            }
          })
        Web({ src: $rawfile('index.html'), controller: this.controller, incognitoMode: true })
          .databaseAccess(true)
      }
    }
  }
  ```

- 通过[fetchCookieSync](../reference/apis-arkweb/js-apis-webview.md#fetchcookiesync11)获取隐私模式下指定url对应cookie的值。

  ```ts
  // xxx.ets
  import web_webview from '@ohos.web.webview'
  import business_error from '@ohos.base'

  @Entry
  @Component
  struct WebComponent {
    controller: web_webview.WebviewController = new web_webview.WebviewController();

    build() {
      Column() {
        Button('fetchCookieSync')
          .onClick(() => {
            try {
              // fetchCookieSync第二个参数表示获取隐私模式（true）或非隐私模式（false）下，webview的内存cookies。
              let value = web_webview.WebCookieManager.fetchCookieSync('https://www.example.com', true);
              console.log("fetchCookieSync cookie = " + value);
            } catch (error) {
              let e:business_error.BusinessError = error as business_error.BusinessError;
              console.error(`ErrorCode: ${e.code},  Message: ${e.message}`);
            }
          })
        Web({ src: 'www.example.com', controller: this.controller, incognitoMode: true })
      }
    }
  }
  ```

- 通过[configCookieSync](../reference/apis-arkweb/js-apis-webview.md#configcookiesync11)设置隐私模式下指定url的单个cookie的值。

  ```ts
  // xxx.ets
  import web_webview from '@ohos.web.webview'
  import business_error from '@ohos.base'

  @Entry
  @Component
  struct WebComponent {
    controller: web_webview.WebviewController = new web_webview.WebviewController();

    build() {
      Column() {
        Button('configCookieSync')
          .onClick(() => {
            try {
              // configCookieSync第三个参数表示获取隐私模式（true）或非隐私模式（false）下，对应url的cookies。
              web_webview.WebCookieManager.configCookieSync('https://www.example.com', 'a=b', true);
            } catch (error) {
              let e:business_error.BusinessError = error as business_error.BusinessError;
              console.error(`ErrorCode: ${e.code},  Message: ${e.message}`);
            }
          })
        Web({ src: 'www.example.com', controller: this.controller, incognitoMode: true })
      }
    }
  }
  ```

- 通过[existCookie](../reference/apis-arkweb/js-apis-webview.md#existcookie)查询隐私模式下是否存在cookie。

  ```ts
  // xxx.ets
  import web_webview from '@ohos.web.webview'

  @Entry
  @Component
  struct WebComponent {
    controller: web_webview.WebviewController = new web_webview.WebviewController();

    build() {
      Column() {
        Button('existCookie')
          .onClick(() => {
            // existCookie参数表示隐私模式（true）或非隐私模式（false）下，查询是否存在cookies。
            let result = web_webview.WebCookieManager.existCookie(true);
            console.log("result: " + result);
          })
        Web({ src: 'www.example.com', controller: this.controller, incognitoMode: true })
      }
    }
  }
  ```

- 通过[clearAllCookiesSync](../reference/apis-arkweb/js-apis-webview.md#clearallcookiessync11)清除隐私模式下所有cookie。 

  ```ts
  // xxx.ets
  import web_webview from '@ohos.web.webview'

  @Entry
  @Component
  struct WebComponent {
    controller: web_webview.WebviewController = new web_webview.WebviewController();

    build() {
      Column() {
        Button('clearAllCookiesSync')
          .onClick(() => {
            // clearAllCookiesSync参数表示清除隐私模式（true）或非隐私模式（false）下，webview的所有内存cookies。
            web_webview.WebCookieManager.clearAllCookiesSync(true);
          })
        Web({ src: 'www.example.com', controller: this.controller, incognitoMode: true })
      }
    }
  }
  ```
