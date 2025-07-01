# Class (WebDataBase)

Implements a **WebDataBase** object.

> **NOTE**
>
> - The initial APIs of this module are supported since API version 9. Updates will be marked with a superscript to indicate their earliest API version.
>
> - You can preview how this component looks on a real device, but not in DevEco Studio Previewer.
>
> - You must load the **Web** component before calling the APIs in **WebDataBase**.

## getHttpAuthCredentials

static getHttpAuthCredentials(host: string, realm: string): Array\<string>

Retrieves HTTP authentication credentials for a given host and realm. This API returns the result synchronously.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name| Type  | Mandatory| Description                        |
| ------ | ------ | ---- | ---------------------------- |
| host   | string | Yes  | Host to which HTTP authentication credentials apply.|
| realm  | string | Yes  | Realm to which HTTP authentication credentials apply.  |

**Return value**

| Type | Description                                        |
| ----- | -------------------------------------------- |
| Array\<string> | Returns the array of the matching user names and passwords if the operation is successful; returns an empty array otherwise.|

**Error codes**

For details about the error codes, see [Webview Error Codes](errorcode-webview.md).

| ID| Error Message                                               |
| -------- | ------------------------------------------------------ |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3. Parameter verification failed.|

**Example**

```ts
// xxx.ets
import { webview } from '@kit.ArkWeb';
import { BusinessError } from '@kit.BasicServicesKit';

@Entry
@Component
struct WebComponent {
  controller: webview.WebviewController = new webview.WebviewController();
  host: string = "www.spincast.org";
  realm: string = "protected example";
  username_password: string[] = [];

  build() {
    Column() {
      Button('getHttpAuthCredentials')
        .onClick(() => {
          try {
            this.username_password = webview.WebDataBase.getHttpAuthCredentials(this.host, this.realm);
            console.log('num: ' + this.username_password.length);
          } catch (error) {
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
          }
        })
      Web({ src: 'www.example.com', controller: this.controller })
    }
  }
}
```

## saveHttpAuthCredentials

static saveHttpAuthCredentials(host: string, realm: string, username: string, password: string): void

Saves HTTP authentication credentials for a given host and realm. This API returns the result synchronously.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name  | Type  | Mandatory| Description                        |
| -------- | ------ | ---- | ---------------------------- |
| host     | string | Yes  | Host to which HTTP authentication credentials apply.|
| realm    | string | Yes  | Realm to which HTTP authentication credentials apply.  |
| username | string | Yes  | User name.                    |
| password | string | Yes  | Password.                      |

**Error codes**

For details about the error codes, see [Webview Error Codes](errorcode-webview.md).

| ID| Error Message                                               |
| -------- | ------------------------------------------------------ |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed. |

**Example**

```ts
// xxx.ets
import { webview } from '@kit.ArkWeb';
import { BusinessError } from '@kit.BasicServicesKit';

@Entry
@Component
struct WebComponent {
  controller: webview.WebviewController = new webview.WebviewController();
  host: string = "www.spincast.org";
  realm: string = "protected example";

  build() {
    Column() {
      Button('saveHttpAuthCredentials')
        .onClick(() => {
          try {
            webview.WebDataBase.saveHttpAuthCredentials(this.host, this.realm, "Stromgol", "Laroche");
          } catch (error) {
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
          }
        })
      Web({ src: 'www.example.com', controller: this.controller })
    }
  }
}
```

## existHttpAuthCredentials

static existHttpAuthCredentials(): boolean

Checks whether any saved HTTP authentication credentials exist. This API returns the result synchronously.

**System capability**: SystemCapability.Web.Webview.Core

**Return value**

| Type   | Description                                                        |
| ------- | ------------------------------------------------------------ |
| boolean | Whether any saved HTTP authentication credentials exist.<br>Returns **true** if any saved HTTP authentication credentials exist; returns **false** otherwise.|

**Example**

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
      Button('existHttpAuthCredentials')
        .onClick(() => {
          try {
            let result = webview.WebDataBase.existHttpAuthCredentials();
          } catch (error) {
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
          }
        })
      Web({ src: 'www.example.com', controller: this.controller })
    }
  }
}
```

## deleteHttpAuthCredentials

static deleteHttpAuthCredentials(): void

Deletes all HTTP authentication credentials saved in the cache. This API returns the result synchronously.

**System capability**: SystemCapability.Web.Webview.Core

**Example**

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
      Button('deleteHttpAuthCredentials')
        .onClick(() => {
          try {
            webview.WebDataBase.deleteHttpAuthCredentials();
          } catch (error) {
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
          }
        })
      Web({ src: 'www.example.com', controller: this.controller })
    }
  }
}
```
