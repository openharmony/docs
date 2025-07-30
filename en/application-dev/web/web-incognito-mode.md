# Using Incognito Mode


When creating a **Web** component, you can enable incognito mode for it by setting the optional parameter [incognitoMode](../reference/apis-arkweb/arkts-basic-components-web-i.md#weboptions) to **true**. When incognito mode is enabled, data such as cookies and cache data during web page browsing is not stored in local persistent files. This means that such data is lost when the **Web** component is destroyed.

- Create a [Web](../reference/apis-arkweb/arkts-basic-components-web.md) component in incognito mode.
 
   ```ts
  // xxx.ets
  import { webview } from '@kit.ArkWeb';

  @Entry
  @Component
  struct WebComponent {
    controller: webview.WebviewController = new webview.WebviewController();

    build() {
      Column() {
        Web({ src: 'www.example.com', controller: this.controller, incognitoMode: true })
      }
    }
  }
  ```

- Use [isIncognitoMode](../reference/apis-arkweb/arkts-apis-webview-WebviewController.md#isincognitomode11) to determine whether incognito mode is enabled for the current **Web** component.

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
        Button('isIncognitoMode')
          .onClick(() => {
            try {
              let result = this.controller.isIncognitoMode();
              console.log('isIncognitoMode' + result);
            } catch (error) {
              console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
            }
          })
        Web({ src: 'www.example.com', controller: this.controller })
      }
    }
  }
  ```

In incognito mode, you can use the following APIs for geolocation information, cookies, and cache data:

- Use [allowGeolocation](../reference/apis-arkweb/arkts-apis-webview-GeolocationPermissions.md#allowgeolocation) to allow the specified origin to use the geolocation information.

  ```ts
  // xxx.ets
  import { webview } from '@kit.ArkWeb';
  import { BusinessError } from '@kit.BasicServicesKit';

  @Entry
  @Component
  struct WebComponent {
    controller: webview.WebviewController = new webview.WebviewController();
    origin: string = "file:///";

    build() {
      Column() {
        Button('allowGeolocation')
          .onClick(() => {
            try {
              // The second parameter of allowGeolocation specifies whether to allow the specified origin to use the geolocation information in incognito mode (true) or in non-incognito mode (false).
              webview.GeolocationPermissions.allowGeolocation(this.origin, true);
            } catch (error) {
              console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
            }
          })
        Web({ src: 'www.example.com', controller: this.controller, incognitoMode: true })
      }
    }
  }
  ```

- Use [deleteGeolocation](../reference/apis-arkweb/arkts-apis-webview-GeolocationPermissions.md#deletegeolocation) to clear the geolocation permission status of a specified origin.

  ```ts
  // xxx.ets
  import { webview } from '@kit.ArkWeb';
  import { BusinessError } from '@kit.BasicServicesKit';

  @Entry
  @Component
  struct WebComponent {
    controller: webview.WebviewController = new webview.WebviewController();
    origin: string = "file:///";

    build() {
      Column() {
        Button('deleteGeolocation')
          .onClick(() => {
            try {
              // The second parameter of deleteGeolocation specifies whether to clear the geolocation permission status of a specified origin in incognito mode (true) or in non-incognito mode (false).
              webview.GeolocationPermissions.deleteGeolocation(this.origin, true);
            } catch (error) {
              console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
            }
          })
        Web({ src: 'www.example.com', controller: this.controller, incognitoMode: true })
      }
    }
  }
  ```

- Use [getAccessibleGeolocation](../reference/apis-arkweb/arkts-apis-webview-GeolocationPermissions.md#getaccessiblegeolocation) to asynchronously obtain the geolocation permission status of the specified origin.

  ```ts
  // xxx.ets
  import { webview } from '@kit.ArkWeb';
  import { BusinessError } from '@kit.BasicServicesKit';

  @Entry
  @Component
  struct WebComponent {
    controller: webview.WebviewController = new webview.WebviewController();
    origin: string = "file:///";

    build() {
      Column() {
        Button('getAccessibleGeolocation')
          .onClick(() => {
            try {
              // The third parameter of getAccessibleGeolocation specifies whether to obtain the geolocation permission status of the specified origin in incognito mode (true) or in non-incognito mode (false). This API uses an asynchronous callback to return the result.
              webview.GeolocationPermissions.getAccessibleGeolocation(this.origin, (error, result) => {
                if (error) {
                  console.log('getAccessibleGeolocationAsync error: ' + JSON.stringify(error));
                  return;
                }
                console.log('getAccessibleGeolocationAsync result: ' + result);
              }, true);
            } catch (error) {
              console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
            }
          })
        Web({ src: 'www.example.com', controller: this.controller, incognitoMode: true })
      }
    }
  }
  ```

- Use [deleteAllData](../reference/apis-arkweb/arkts-apis-webview-WebStorage.md#deletealldata) to delete all data in the Web SQL Database.

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
        Button('deleteAllData')
          .onClick(() => {
            try {
              // The parameter of deleteAllData specifies whether to delete all data in the Web SQL Database in incognito mode (true) or in non-incognito mode (false).
              webview.WebStorage.deleteAllData(true);
            } catch (error) {
              console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
            }
          })
        Web({ src: $rawfile('index.html'), controller: this.controller, incognitoMode: true })
          .databaseAccess(true)
      }
    }
  }
  ```

  HTML file to be loaded:
   ```html
  <!-- index.html -->
  <!DOCTYPE html>
  <html>
  <head>
    <meta charset="UTF-8">
    <title>test</title>
    <script type="text/javascript">

      var db = openDatabase('mydb','1.0','Test DB',2 * 1024 * 1024);
      var msg;

      db.transaction(function(tx){
        tx.executeSql('INSERT INTO LOGS (id,log) VALUES(1,"test1")');
        tx.executeSql('INSERT INTO LOGS (id,log) VALUES(2,"test2")');
        msg = '<p>Data table created, with two data records inserted.</p>';

        document.querySelector('#status').innerHTML = msg;
      });

      db.transaction(function(tx){
        tx.executeSql('SELECT * FROM LOGS', [], function (tx, results) {
          var len = results.rows.length,i;
          msg = "<p>Number of records: " + len + "</p>";

          document.querySelector('#status').innerHTML += msg;

              for(i = 0; i < len; i++){
                msg = "<p><b>" + results.rows.item(i).log + "</b></p>";

          document.querySelector('#status').innerHTML += msg;
          }
        },null);
      });

      </script>
  </head>
  <body>
  <div id="status" name="status">Status</div>
  </body>
  </html>
  ```

- Use [fetchCookieSync](../reference/apis-arkweb/arkts-apis-webview-WebCookieManager.md#fetchcookiesync11) to obtain the cookie corresponding to the specified URL.

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
        Button('fetchCookieSync')
          .onClick(() => {
            try {
              // The second parameter of fetchCookieSync specifies whether to obtain the cookie in incognito mode (true) or in non-incognito mode (false).
              let value = webview.WebCookieManager.fetchCookieSync('https://www.example.com', true);
              console.log("fetchCookieSync cookie = " + value);
            } catch (error) {
              console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
            }
          })
        Web({ src: 'www.example.com', controller: this.controller, incognitoMode: true })
      }
    }
  }
  ```

- Use [configCookieSync](../reference/apis-arkweb/arkts-apis-webview-WebCookieManager.md#configcookiesync11) to set a cookie for the specified URL.

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
              // The third parameter of configCookieSync specifies whether to obtain the cookie for the specified URL in incognito mode (true) or non-incognito mode (false).
              webview.WebCookieManager.configCookieSync('https://www.example.com', 'a=b', true);
            } catch (error) {
              console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
            }
          })
        Web({ src: 'www.example.com', controller: this.controller, incognitoMode: true })
      }
    }
  }
  ```

- Use [existCookie](../reference/apis-arkweb/arkts-apis-webview-WebCookieManager.md#existcookie) to check whether cookies exist.

  ```ts
  // xxx.ets
  import { webview } from '@kit.ArkWeb';

  @Entry
  @Component
  struct WebComponent {
    controller: webview.WebviewController = new webview.WebviewController();

    build() {
      Column() {
        Button('existCookie')
          .onClick(() => {
            // The parameter of existCookie specifies whether to check for cookies in incognito mode (true) or in non-incognito mode (false).
            let result = webview.WebCookieManager.existCookie(true);
            console.log("result: " + result);
          })
        Web({ src: 'www.example.com', controller: this.controller, incognitoMode: true })
      }
    }
  }
  ```

- Use [clearAllCookiesSync](../reference/apis-arkweb/arkts-apis-webview-WebCookieManager.md#clearallcookiessync11) to clear all cookies.

  ```ts
  // xxx.ets
  import { webview } from '@kit.ArkWeb';

  @Entry
  @Component
  struct WebComponent {
    controller: webview.WebviewController = new webview.WebviewController();

    build() {
      Column() {
        Button('clearAllCookiesSync')
          .onClick(() => {
            // The parameter of clearAllCookiesSync specifies whether to delete all cookies in incognito mode (true) or in non-incognito mode (false).
            webview.WebCookieManager.clearAllCookiesSync(true);
          })
        Web({ src: 'www.example.com', controller: this.controller, incognitoMode: true })
      }
    }
  }
  ```
