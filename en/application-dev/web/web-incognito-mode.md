# Using Incognito Mode


When creating a **\<Web>** component, you can enable incognito mode for it by setting the optional parameter [incognitoMode](../reference/apis-arkweb/ts-basic-components-web.md#incognitomode) to **true**. When incognito mode, data such as cookies and cache data during web page browsing is not stored in local persistent files. This means that such data is lost when the **\<Web>** component is destroyed.

- Create a [\<Web>](../reference/apis-arkweb/ts-basic-components-web.md#web) component in incognito mode.
 
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

- Use [isIncogntoMode](../reference/apis-arkweb/js-apis-webview.md#isincognitomode) to check whether the current \**<Web>** component is in incognitomode.

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

In incognito mode, you can use the following APIs for geolocation information, cookies, and cache data:

- Use [allowGeolocation](../reference/apis-arkweb/js-apis-webview.md#allowgeolocation) to allow the specified origin to use the geolocation information.

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

- Use [deleteGeolocation](../reference/apis-arkweb/js-apis-webview.md#deletegeolocation) to clear the geolocation permission status of a specified origin.

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

- Use [getAccessibleGeolocation](../reference/apis-arkweb/js-apis-webview.md#getaccessiblegeolocation) to asynchronously obtain the geolocation permission status of the specified origin.

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

- Use [deleteAllData](../reference/apis-arkweb/js-apis-webview.md#deletealldata) to delete all data in the Web SQL Database.

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

- Use [fetchCookieSync](../reference/apis-arkweb/js-apis-webview.md#fetchcookiesync) to obtain the cookie corresponding to the specified URL.

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

- Use [configCookieSync](../reference/apis-arkweb/js-apis-webview.md#configcookiesync) to set a cookie for the specified URL.

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

- Use [existCookie](../reference/apis-arkweb/js-apis-webview.md#existcookie) to check whether cookies exist.

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
            let result = web_webview.WebCookieManager.existCookie(true);
            console.log("result: " + result);
          })
        Web({ src: 'www.example.com', controller: this.controller, incognitoMode: true })
      }
    }
  }
  ```

- Use [clearAllCookiesSync](../reference/apis-arkweb/js-apis-webview.md#clearallcookiessync) to delete all cookies.

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
            web_webview.WebCookieManager.clearAllCookiesSync(true);
          })
        Web({ src: 'www.example.com', controller: this.controller, incognitoMode: true })
      }
    }
  }
  ```
