# Using Incognito Mode

<!--Kit: ArkWeb-->
<!--Subsystem: Web-->
<!--Owner: @aohui-->
<!--Designer: @yaomingliu-->
<!--Tester: @ghiker-->
<!--Adviser: @HelloShuo-->
<!-- md-trans-meta sourceCommit=95d707f76a454a7ac9a469c434369c3b8ffcfeb1 translatedAt=2026-08-14T03:47:03.717Z pushedAt=2026-08-14T08:48:43.210Z -->

When you browse web pages in incognito mode, data such as cookies and caches is not written to local persistent storage. After the Web component in incognito mode is destroyed, this data is cleared and will not be retained.

## Enabling Incognito Mode

When creating a Web component, you can enable incognito mode for it by setting the optional parameter [incognitoMode](../reference/apis-arkweb/arkts-basic-components-web-i.md#weboptions) to **true**.

- Create a [Web](../reference/apis-arkweb/arkts-basic-components-web.md) component in incognito mode.

  <!-- @[create_a_web_component_in_privacy_mode](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkWeb/SetBasicAttrsEvts/SetBasicAttrsEvtsOne/entry/src/main/ets/pages/IncognitoMode_one.ets) -->

  ``` TypeScript
  import { webview } from '@kit.ArkWeb';
  
  @Entry
  @Component
  struct WebComponent {
    controller: webview.WebviewController = new webview.WebviewController();
  
    build() {
      Column() {
        Web({ src: 'www.example.com', controller: this.controller, incognitoMode: true });
      }
    }
  }
  ```

- Use [isIncognitoMode](../reference/apis-arkweb/arkts-apis-webview-WebviewController.md#isincognitomode11) to determine whether incognito mode is enabled for the current **Web** component.

  <!-- @[determine_whether_the_current_web_component_is_in_privacy_mode](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkWeb/SetBasicAttrsEvts/SetBasicAttrsEvtsOne/entry/src/main/ets/pages/IncognitoMode_two.ets) -->

  ``` TypeScript
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
              console.info('isIncognitoMode' + result);
            } catch (error) {
              console.error(
                `ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
            }
          })
        Web({ src: 'www.example.com', controller: this.controller });
      }
    }
  }
  ```

## Operating Geolocation in Incognito Mode

- Use [allowGeolocation](../reference/apis-arkweb/arkts-apis-webview-GeolocationPermissions.md#allowgeolocation) to allow the specified origin to use the geolocation information.

  <!-- @[setting_the_web_component_in_privacy_mode_allows_specifying_the_geolocation_of_the_source_used](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkWeb/SetBasicAttrsEvts/SetBasicAttrsEvtsOne/entry/src/main/ets/pages/AllowGeolocation.ets) -->

  ``` TypeScript
  import { webview } from '@kit.ArkWeb';
  import { BusinessError } from '@kit.BasicServicesKit';
  
  @Entry
  @Component
  struct WebComponent {
    controller: webview.WebviewController = new webview.WebviewController();
    origin: string = 'file:///';
  
    build() {
      Column() {
        Button('allowGeolocation')
          .onClick(() => {
            try {
              // The second parameter of allowGeolocation specifies whether to allow the specified origin to use the geolocation information in incognito mode (true) or in non-incognito mode (false).
              webview.GeolocationPermissions.allowGeolocation(this.origin, true);
            } catch (error) {
              console.error(
                `ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
            }
          })
        Web({ src: 'www.example.com', controller: this.controller, incognitoMode: true });
      }
    }
  }
  ```

- Use [deleteGeolocation](../reference/apis-arkweb/arkts-apis-webview-GeolocationPermissions.md#deletegeolocation) to clear the geolocation permission status of a specified origin.

  <!-- @[clear_the_geolocation_permission_status_of_the_specified_source_in_privacy_mode](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkWeb/SetBasicAttrsEvts/SetBasicAttrsEvtsOne/entry/src/main/ets/pages/DeleteGeolocation.ets) -->

  ``` TypeScript
  import { webview } from '@kit.ArkWeb';
  import { BusinessError } from '@kit.BasicServicesKit';
  
  @Entry
  @Component
  struct WebComponent {
    controller: webview.WebviewController = new webview.WebviewController();
    origin: string = 'file:///';
  
    build() {
      Column() {
        Button('deleteGeolocation')
          .onClick(() => {
            try {
              // The second parameter of deleteGeolocation specifies whether to clear the geolocation permission status of a specified origin in incognito mode (true) or in non-incognito mode (false).
              webview.GeolocationPermissions.deleteGeolocation(this.origin, true);
            } catch (error) {
              console.error(
                `ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
            }
          })
        Web({ src: 'www.example.com', controller: this.controller, incognitoMode: true });
      }
    }
  }
  ```

- Use [getAccessibleGeolocation](../reference/apis-arkweb/arkts-apis-webview-GeolocationPermissions.md#getaccessiblegeolocation) to asynchronously obtain the geolocation permission status of the specified origin.

  <!-- @[asynchronously_obtains_the_geolocation_permission_status_of_the_specified_source_in_privacy_mode](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkWeb/SetBasicAttrsEvts/SetBasicAttrsEvtsOne/entry/src/main/ets/pages/GetAccessibleGeolocation.ets) -->

  ``` TypeScript
  import { webview } from '@kit.ArkWeb';
  import { BusinessError } from '@kit.BasicServicesKit';
  
  @Entry
  @Component
  struct WebComponent {
    controller: webview.WebviewController = new webview.WebviewController();
    origin: string = 'file:///';
  
    build() {
      Column() {
        Button('getAccessibleGeolocation')
          .onClick(() => {
            try {
              // The third parameter of getAccessibleGeolocation specifies whether to obtain the geolocation permission status of the specified origin in incognito mode (true) or non-incognito mode (false).
              // This API uses an asynchronous callback to return the result.
              webview.GeolocationPermissions.getAccessibleGeolocation(this.origin, (error, result) => {
                if (error) {
                  console.error(`getAccessibleGeolocationAsync error: + Code: ${error.code}, message: ${error.message}`);
                  return;
                }
                console.info('getAccessibleGeolocationAsync result: ' + result);
              }, true);
            } catch (error) {
              console.error(
                `ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
            }
          })
        Web({ src: 'www.example.com', controller: this.controller, incognitoMode: true });
      }
    }
  }
  ```

## Clearing Web Data in Memory in Incognito Mode

- Use [deleteAllData](../reference/apis-arkweb/arkts-apis-webview-WebStorage.md#deletealldata) to delete all data in the Web SQL Database.

  <!-- @[clear_all_storage_currently_used_by_web_sql_in_privacy_mode](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkWeb/SetBasicAttrsEvts/SetBasicAttrsEvtsOne/entry/src/main/ets/pages/DeleteAllData.ets) -->

  ``` TypeScript
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
              console.error(
                `ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
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

## Managing Cookies in Incognito Mode

- Use [fetchCookieSync](../reference/apis-arkweb/arkts-apis-webview-WebCookieManager.md#fetchcookiesync11) to obtain the cookie corresponding to the specified URL.

  <!-- @[obtain_the_value_of_the_cookie_corresponding_to_the_specified_url_in_privacy_mode](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkWeb/SetBasicAttrsEvts/SetBasicAttrsEvtsOne/entry/src/main/ets/pages/FetchCookieSync.ets) -->

  ``` TypeScript
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
              console.info('fetchCookieSync cookie = ' + value);
            } catch (error) {
              console.error(
                `ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
            }
          })
        Web({ src: 'www.example.com', controller: this.controller, incognitoMode: true });
      }
    }
  }
  ```

- Use [configCookieSync](../reference/apis-arkweb/arkts-apis-webview-WebCookieManager.md#configcookiesync11) to set a cookie for the specified URL.

  <!-- @[set_the_value_of_a_single_cookie_for_a_specified_url_in_privacy_mode](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkWeb/SetBasicAttrsEvts/SetBasicAttrsEvtsOne/entry/src/main/ets/pages/ConfigCookieSync.ets) -->

  ``` TypeScript
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
              // The third parameter of configCookieSync specifies the cookies for the corresponding url in incognito mode (true) or non-incognito mode (false).
              webview.WebCookieManager.configCookieSync('https://www.example.com', 'a=b', true);
            } catch (error) {
              console.error(
                `ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
            }
          })
        Web({ src: 'www.example.com', controller: this.controller, incognitoMode: true });
      }
    }
  }
  ```

- Use [existCookie](../reference/apis-arkweb/arkts-apis-webview-WebCookieManager.md#existcookie) to check whether cookies exist.

  <!-- @[check_whether_cookies_exist_in_mode](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkWeb/SetBasicAttrsEvts/SetBasicAttrsEvtsOne/entry/src/main/ets/pages/ExistCookie.ets) -->

  ``` TypeScript
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
            console.info('result: ' + result);
          })
        Web({ src: 'www.example.com', controller: this.controller, incognitoMode: true });
      }
    }
  }
  ```

- Use [clearAllCookiesSync](../reference/apis-arkweb/arkts-apis-webview-WebCookieManager.md#clearallcookiessync11) to clear all cookies.

  <!-- @[clear_all_cookies_in_privacy_mode](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkWeb/SetBasicAttrsEvts/SetBasicAttrsEvtsOne/entry/src/main/ets/pages/ClearAllCookiesSync.ets) -->

  ``` TypeScript
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
        Web({ src: 'www.example.com', controller: this.controller, incognitoMode: true });
      }
    }
  }
  ```