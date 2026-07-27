# Class (WebCookieManager)
<!--Kit: ArkWeb-->
<!--Subsystem: Web-->
<!--Owner: @aohui-->
<!--Designer: @yaomingliu-->
<!--Tester: @ghiker-->
<!--Adviser: @HelloShuo-->

WebCookieManager是Web组件的cookie管理器，提供对Web组件中cookie的全局管理能力。开发者通过该类可以实现cookie的获取、设置、保存、清除以及权限控制等操作。该类的所有方法均为静态方法，应用中的所有Web组件共享一个WebCookieManager实例。cookie的格式遵循[RFC6265](https://www.rfc-editor.org/rfc/rfc6265)标准。

使用隐私模式浏览网页时，cookie、缓存等数据不会写入本地持久化存储；隐私模式的Web组件销毁后，这些数据将被清除，不会保留。

> **说明：**
>
> - 本模块首批接口从API version 9开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。
>
> - 本Class首批接口从API version 9开始支持。
>
> - 示例效果请以真机运行为准。
>
> - 静态方法必须在用户界面（UI）线程上使用。

## 导入模块

```ts
import { webview } from '@kit.ArkWeb';
```

## fetchCookieSync<sup>11+</sup>

static fetchCookieSync(url: string, incognito?: boolean): string

获取指定url对应cookie的值。

> **说明：**
>
> - 系统会自动清理过期的cookie，对于同名key的数据，新数据将会覆盖前一个数据。
> 
> - 为了获取可正常使用的cookie值，fetchCookieSync需传入完整链接。
> 
> - fetchCookieSync用于获取所有的cookie值，每条cookie值之间会通过"; "进行分隔，但无法单独获取某一条特定的cookie值。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名 | 类型   | 必填 | 说明                      |
| ------ | ------ | ---- | :------------------------ |
| url    | string | 是   | 要获取的cookie所属的url，建议使用完整的url。 |
| incognito    | boolean | 否   | true表示获取隐私模式下webview的内存cookies，false表示正常非隐私模式下的cookies。<br>默认值：false。<br>传入undefined或null会抛出异常错误码401。 |

**返回值：**

| 类型   | 说明                      |
| ------ | ------------------------- |
| string | 指定url对应的cookie的值。 |

**错误码：**

以下错误码的详细介绍请参见[Webview错误码](errorcode-webview.md)、[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                               |
| -------- | ------------------------------------------------------ |
| 17100002 | URL error. No valid cookie found for the specified URL. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |

**示例：**

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
            let value = webview.WebCookieManager.fetchCookieSync('https://www.example.com');
            console.info("fetchCookieSync cookie = " + value);
          } catch (error) {
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
          }
        })
      Web({ src: 'www.example.com', controller: this.controller })
    }
  }
}
```

## fetchCookieSync

static fetchCookieSync(url: string, incognito?: boolean, includePartitionedCookies?: boolean): string

获取指定url对应的cookies，可以通过可选参数incognito指定是否获取隐私模式下的cookies，也可以通过可选参数includePartitionedCookies指定是否获取第一方partitioned cookie。

> **说明：**
>
> - 系统会自动清理过期的cookie，对于同名key的数据，新数据将会覆盖前一个数据。
>
> - 为了获取可正常使用的cookie值，fetchCookieSync需传入完整链接。
>
> - fetchCookieSync用于获取所有的cookie值，每条cookie值之间会通过"; "进行分隔，但无法单独获取某一条特定的cookie值。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名 | 类型   | 必填 | 说明                      |
| ------ | ------ | ---- | :------------------------ |
| url    | string | 是   | 要获取的cookie所属的url，建议使用完整的url。 |
| incognito    | boolean | 否   | true表示获取隐私模式下webview的内存cookies，false表示获取非隐私模式下的cookies。<br>默认值：false。<br>传入undefined或null会抛出异常错误码401。 |
| includePartitionedCookies | boolean | 否 | true表示允许获取第一方partitioned cookies，false表示不允许获取第一方partitioned cookies。<br>默认值：false。<br>传入undefined或null会抛出异常错误码401。 |

**返回值：**

| 类型   | 说明                      |
| ------ | ------------------------- |
| string | 指定url对应的cookies。 |

**错误码：**

以下错误码的详细介绍请参见[Webview错误码](errorcode-webview.md)、[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                               |
| -------- | ------------------------------------------------------ |
| 17100002 | URL error. No valid cookie found for the specified URL. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |

**示例：**

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
            let value = webview.WebCookieManager.fetchCookieSync('https://www.example.com', false, true);
            console.info("fetchCookieSync cookie = " + value);
          } catch (error) {
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
          }
        })
      Web({ src: 'www.example.com', controller: this.controller })
    }
  }
}
```

## fetchCookie<sup>11+</sup>

static fetchCookie(url: string, callback: AsyncCallback\<string>): void

异步callback方式获取指定url对应cookie的值。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名 | 类型   | 必填 | 说明                      |
| ------ | ------ | ---- | :------------------------ |
| url    | string | 是   | 要获取的cookie所属的url，建议使用完整的url。 |
| callback | AsyncCallback\<string> | 是 | callback回调，用于获取cookie |

**错误码：**

以下错误码的详细介绍请参见[Webview错误码](errorcode-webview.md)、[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                               |
| -------- | ------------------------------------------------------ |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 17100002 | URL error. No valid cookie found for the specified URL.   |

**示例：**

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
      Button('fetchCookie')
        .onClick(() => {
          try {
            webview.WebCookieManager.fetchCookie('https://www.example.com', (error, cookie) => {
              if (error) {
                console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
                return;
              }
              if (cookie) {
                console.info('fetchCookie cookie = ' + cookie);
              }
            })
          } catch (error) {
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
          }
        })
      Web({ src: 'www.example.com', controller: this.controller })
    }
  }
}
```

## fetchCookie<sup>11+</sup>

static fetchCookie(url: string): Promise\<string>

以Promise方式异步获取指定url对应cookie的值。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名 | 类型   | 必填 | 说明                      |
| ------ | ------ | ---- | :------------------------ |
| url    | string | 是   | 要获取的cookie所属的url，建议使用完整的url。 |

**返回值：**

| 类型   | 说明                      |
| ------ | ------------------------- |
| Promise\<string> | Promise实例，用于获取指定url对应的cookie值。 |

**错误码：**

以下错误码的详细介绍请参见[Webview错误码](errorcode-webview.md)、[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                               |
| -------- | ------------------------------------------------------ |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 17100002 | URL error. No valid cookie found for the specified URL.  |

**示例：**

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
      Button('fetchCookie')
        .onClick(() => {
          try {
            webview.WebCookieManager.fetchCookie('https://www.example.com')
              .then(cookie => {
                console.info("fetchCookie cookie = " + cookie);
              })
              .catch((error: BusinessError) => {
                console.error(`ErrorCode: ${error.code},  Message: ${error.message}`);
              })
          } catch (error) {
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
          }
        })
      Web({ src: 'www.example.com', controller: this.controller })
    }
  }
}
```

## fetchCookie<sup>14+</sup>

static fetchCookie(url: string, incognito: boolean): Promise\<string>

以Promise方式异步获取指定url对应cookie的值。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名 | 类型   | 必填 | 说明                      |
| ------ | ------ | ---- | :------------------------ |
| url    | string | 是   | 要获取的cookie所属的url，建议使用完整的url。 |
| incognito    | boolean | 是   | true表示获取隐私模式下webview的内存cookies，false表示正常非隐私模式下的cookies。 |

**返回值：**

| 类型   | 说明                      |
| ------ | ------------------------- |
| Promise\<string> | Promise实例，用于获取指定url对应的cookie值。 |

**错误码：**

以下错误码的详细介绍请参见[Webview错误码](errorcode-webview.md)、[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                               |
| -------- | ------------------------------------------------------ |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 17100002 | URL error. No valid cookie found for the specified URL. |

**示例：**

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
      Button('fetchCookie')
        .onClick(() => {
          try {
            webview.WebCookieManager.fetchCookie('https://www.example.com', false)
              .then(cookie => {
                console.info("fetchCookie cookie = " + cookie);
              })
              .catch((error: BusinessError) => {
                console.error(`ErrorCode: ${error.code},  Message: ${error.message}`);
              })
          } catch (error) {
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
          }
        })
      Web({ src: 'www.example.com', controller: this.controller })
    }
  }
}
```

## fetchCookie

static fetchCookie(url: string, incognito: boolean, includePartitionedCookies: boolean): Promise\<string>

获取指定url对应的cookies，可以通过参数incognito指定是否获取隐私模式下的cookies，也可以通过参数includePartitionedCookies指定是否获取第一方partitioned cookie。使用Promise异步回调。

**起始版本：** 26.0.0

**模型约束：** 此接口仅可在Stage模型下使用。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名 | 类型   | 必填 | 说明                      |
| ------ | ------ | ---- | :------------------------ |
| url    | string | 是   | 要获取的cookie所属的url，建议使用完整的url。 |
| incognito    | boolean | 是   | true表示获取隐私模式下webview的内存cookies，false表示获取非隐私模式下的cookies。 <br>传入undefined或null会抛出异常错误码401。 |
| includePartitionedCookies | boolean | 是 | true表示允许获取第一方partitioned cookies，false表示不允许获取第一方partitioned cookies。 <br>传入undefined或null会抛出异常错误码401。 |

**返回值：**

| 类型   | 说明                      |
| ------ | ------------------------- |
| Promise\<string> | Promise对象，用于获取指定url对应的cookies。 |

**错误码：**

以下错误码的详细介绍请参见[Webview错误码](errorcode-webview.md)、[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                               |
| -------- | ------------------------------------------------------ |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 17100002 | URL error. No valid cookie found for the specified URL. |

**示例：**

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
      Button('fetchCookie')
        .onClick(() => {
          try {
            webview.WebCookieManager.fetchCookie('https://www.example.com', false, true)
              .then(cookie => {
                console.info("fetchCookie cookie = " + cookie);
              })
              .catch((error: BusinessError) => {
                console.error(`ErrorCode: ${error.code},  Message: ${error.message}`);
              })
          } catch (error) {
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
          }
        })
      Web({ src: 'www.example.com', controller: this.controller })
    }
  }
}
```

## fetchAllCookies<sup>23+</sup>

static fetchAllCookies(incognito: boolean): Promise\<Array\<WebHttpCookie\>\>

获取所有cookie，使用Promise异步回调。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| --------- | ------- | -- | -------------------------------------- |
| incognito | boolean | 是 | true表示获取隐私模式下webview的所有cookie，false表示正常非隐私模式下的所有cookie。 |

**返回值：**

| 类型   | 说明                      |
| ------ | ------------------------- |
| Promise\<Array\<[WebHttpCookie](./arkts-apis-webview-i.md#webhttpcookie23)\>\> | Promise对象，用于获取所有cookie及其对应的字段值。 |

**示例：**

```ts
// xxx.ets
import { webview } from '@kit.ArkWeb';
import { BusinessError } from '@kit.BasicServicesKit';

@Entry
@Component
struct WebComponent {
  controller: webview.WebviewController = new webview.WebviewController()

  build() {
    Row() {
      Column() {
        Button('Config Cookie')
        .onClick(() => {
          try {
            webview.WebCookieManager.configCookieSync('https://www.example.com', 'a=b');
          } catch (error) {
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
          }
        })

        Button('Get All Cookies')
        .onClick(() => {
          webview.WebCookieManager.fetchAllCookies(false).then((cookies) => {
            for (let i = 0; i < cookies.length; i++) {
              console.info('fetchAllCookies cookie[' + i + '].name = ' + cookies[i].name);
              console.info('fetchAllCookies cookie[' + i + '].value = ' + cookies[i].value);
            }
          })
        })

        Web({ src: 'https://www.example.com', controller: this.controller})
      }
    }
  }
}
```

## configCookieSync<sup>11+</sup>

static configCookieSync(url: string, value: string, incognito?: boolean): void

为指定url设置单个cookie的值。

> **说明：**
>
> - configCookieSync中的url，可以指定域名的方式来使得页面内请求也附带上cookie。
>
> - cookie每30s周期性保存到磁盘中，也可以使用接口[saveCookieAsync](#savecookieasync)进行强制落盘。
>
> - value参数必须遵循Set-Cookie HTTP响应头的格式。形式为"key=value"的键值对，后面可跟随以分号分隔的cookie属性列表（例如"key=value;Max-Age=100"）。
> 
> - 若存在相同host、path和名称的cookie，将被新cookie替换。若设置的cookie已过期，则不会存储该cookie。如需设置多个cookie，应多次调用此方法。
>
> - 若通过configCookieSync进行两次或多次设置cookie，则每次设置的cookie之间会通过"; "进行分隔。
>
> - 如果指定的值包含"Secure"属性，则url必须使用"https://"协议。
>
> - 如果要覆盖HttpOnly的cookies，需要在value中指定HttpOnly属性。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名 | 类型   | 必填 | 说明                      |
| ------ | ------ | ---- | :------------------------ |
| url    | string | 是   | 要设置的cookie所属的url，建议使用完整的url。 |
| value  | string | 是   | 要设置的cookie的值。      |
| incognito    | boolean | 否   | true表示设置隐私模式下对应url的cookies，false表示设置正常非隐私模式下对应url的cookies。<br>默认值：false。 <br>传入undefined或null会抛出异常错误码401。|

**错误码：**

以下错误码的详细介绍请参见[Webview错误码](errorcode-webview.md)、[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                               |
| -------- | ------------------------------------------------------ |
| 17100002 | URL error. No valid cookie found for the specified URL.  |
| 17100005 | The provided cookie value is invalid. It must follow the format specified in RFC 6265. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |

**示例：**

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
            // configCookieSync每次仅支持设置单个cookie值。
            webview.WebCookieManager.configCookieSync('https://www.example.com', 'a=b');
          } catch (error) {
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
          }
        })
      Web({ src: 'www.example.com', controller: this.controller })
    }
  }
}
```

## configCookieSync<sup>14+</sup>

static configCookieSync(url: string, value: string, incognito: boolean, includeHttpOnly: boolean): void

为指定url设置cookie的值。

> **说明：**
>
> - configCookieSync中的url，可以指定域名的方式来使得页面内请求也附带上cookie。
>
> - cookie每30s周期性保存到磁盘中，也可以使用接口[saveCookieAsync](#savecookieasync)进行强制落盘。
>
> - value参数必须遵循Set-Cookie HTTP响应头的格式。形式为"key=value"的键值对，后面可跟随以分号分隔的cookie属性列表（例如"key=value;Max-Age=100"）。
> 
> - 若存在相同host、path和名称的cookie，将被新cookie替换。若设置的cookie已过期，则不会存储该cookie。如需设置多个cookie，应多次调用此方法。
>
> - 若通过configCookieSync进行两次或多次设置cookie，则每次设置的cookie之间会通过"; "进行分隔。
>
> - 如果指定的值包含"Secure"属性，则url必须使用"https://"协议。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名 | 类型   | 必填 | 说明                      |
| ------ | ------ | ---- | :------------------------ |
| url    | string | 是   | 要设置的cookie所属的url，建议使用完整的url。 |
| value  | string | 是   | 要设置的cookie的值。      |
| incognito    | boolean | 是   | true表示设置隐私模式下对应url的cookies，false表示设置正常非隐私模式下对应url的cookies。 |
| includeHttpOnly    | boolean | 是   | true表示允许覆盖含有http-only的cookies，false表示不允许覆盖含有http-only的cookies。 |

**错误码：**

以下错误码的详细介绍请参见[Webview错误码](errorcode-webview.md)、[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                               |
| -------- | ------------------------------------------------------ |
| 17100002 | URL error. No valid cookie found for the specified URL.  |
| 17100005 | The provided cookie value is invalid. It must follow the format specified in RFC 6265. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |

**示例：**

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
            // 仅支持设置单个cookie值。
            webview.WebCookieManager.configCookieSync('https://www.example.com', 'a=b', false, false);
          } catch (error) {
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
          }
        })
      Web({ src: 'www.example.com', controller: this.controller })
    }
  }
}
```

## configCookie<sup>11+</sup>

static configCookie(url: string, value: string, callback: AsyncCallback\<void>): void

异步callback方式为指定url设置单个cookie的值。

> **说明：**
>
> - configCookie中的url，可以指定域名的方式来使得页面内请求也附带上cookie。
>
> - cookie每30s周期性保存到磁盘中，也可以使用接口[saveCookieAsync](#savecookieasync)进行强制落盘。
>
> - value参数必须遵循Set-Cookie HTTP响应头的格式。形式为"key=value"的键值对，后面可跟随以分号分隔的cookie属性列表（例如"key=value;Max-Age=100"）。
> 
> - 若存在相同host、path和名称的cookie，将被新cookie替换。若设置的cookie已过期，则不会存储该cookie。如需设置多个cookie，应多次调用此方法。
>
> - 若通过configCookie进行两次或多次设置cookie，则每次设置的cookie之间会通过"; "进行分隔。
>
> - 如果指定的值包含"Secure"属性，则url必须使用"https://"协议。
>
> - 如果要覆盖HttpOnly的cookies，需要在value中指定HttpOnly属性。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名 | 类型   | 必填 | 说明                      |
| ------ | ------ | ---- | :------------------------ |
| url    | string | 是   | 要设置的cookie所属的url，建议使用完整的url。 |
| value  | string | 是   | 要设置的cookie的值。      |
| callback | AsyncCallback\<void> | 是 | callback回调，用于获取设置cookie的结果 |

**错误码：**

以下错误码的详细介绍请参见[Webview错误码](errorcode-webview.md)、[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                               |
| -------- | ------------------------------------------------------ |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 17100002 | URL error. No valid cookie found for the specified URL.  |
| 17100005 | The provided cookie value is invalid. It must follow the format specified in RFC 6265. |

**示例：**

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
      Button('configCookie')
        .onClick(() => {
          try {
            webview.WebCookieManager.configCookie('https://www.example.com', "a=b", (error) => {
              if (error) {
                console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
              }
            })
          } catch (error) {
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
          }
        })
      Web({ src: 'www.example.com', controller: this.controller })
    }
  }
}
```

## configCookie<sup>11+</sup>

static configCookie(url: string, value: string): Promise\<void>

为指定url设置单个cookie的值。使用Promise异步回调。

> **说明：**
>
> - configCookie中的url，可以指定域名的方式来使得页面内请求也附带上cookie。
>
> - cookie每30s周期性保存到磁盘中，也可以使用接口[saveCookieAsync](#savecookieasync)进行强制落盘。
>
> - value参数必须遵循Set-Cookie HTTP响应头的格式。形式为"key=value"的键值对，后面可跟随以分号分隔的cookie属性列表（例如"key=value;Max-Age=100"）。
> 
> - 若存在相同host、path和名称的cookie，将被新cookie替换。若设置的cookie已过期，则不会存储该cookie。如需设置多个cookie，应多次调用此方法。
>
> - 若通过configCookie进行两次或多次设置cookie，则每次设置的cookie之间会通过"; "进行分隔。
>
> - 如果指定的值包含"Secure"属性，则url必须使用"https://"协议。
>
> - 如果要覆盖HttpOnly的cookies，需要在value中指定HttpOnly属性。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名 | 类型   | 必填 | 说明                      |
| ------ | ------ | ---- | :------------------------ |
| url    | string | 是   | 要设置的cookie所属的url，建议使用完整的url。 |
| value  | string | 是   | 要设置的cookie的值。      |

**返回值：**

| 类型   | 说明                      |
| ------ | ------------------------- |
| Promise\<void> | Promise实例，用于获取指定url设置单个cookie值是否成功。 |

**错误码：**

以下错误码的详细介绍请参见[Webview错误码](errorcode-webview.md)、[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                |
| -------- | ------------------------------------------------------ |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 17100002 | URL error. No valid cookie found for the specified URL. |
| 17100005 | The provided cookie value is invalid. It must follow the format specified in RFC 6265. |

**示例：**

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
      Button('configCookie')
        .onClick(() => {
          try {
            webview.WebCookieManager.configCookie('https://www.example.com', 'a=b')
              .then(() => {
                console.info('configCookie success!');
              })
              .catch((error: BusinessError) => {
                console.info('error: ' + JSON.stringify(error));
              })
          } catch (error) {
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
          }
        })
      Web({ src: 'www.example.com', controller: this.controller })
    }
  }
}
```

## configCookie<sup>14+</sup>

static configCookie(url: string, value: string, incognito: boolean, includeHttpOnly: boolean): Promise\<void>

为指定url设置单个cookie的值。使用Promise异步回调。

> **说明：**
>
> - configCookie中的url，可以指定域名的方式来使得页面内请求也附带上cookie。
>
> - cookie每30s周期性保存到磁盘中，也可以使用接口[saveCookieAsync](#savecookieasync)进行强制落盘。
>
> - value参数必须遵循Set-Cookie HTTP响应头的格式。形式为"key=value"的键值对，后面可跟随以分号分隔的cookie属性列表（例如"key=value;Max-Age=100"）。
> 
> - 若存在相同host、path和名称的cookie，将被新cookie替换。若设置的cookie已过期，则不会存储该cookie。如需设置多个cookie，应多次调用此方法。
>
> - 若通过configCookie进行两次或多次设置cookie，则每次设置的cookie之间会通过"; "进行分隔。
>
> - 如果指定的值包含"Secure"属性，则url必须使用"https://"协议。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名 | 类型   | 必填 | 说明                      |
| ------ | ------ | ---- | :------------------------ |
| url    | string | 是   | 要设置的cookie所属的url，建议使用完整的url。 |
| value  | string | 是   | 要设置的cookie的值。      |
| incognito    | boolean | 是   | true表示设置隐私模式下对应url的cookies，false表示设置正常非隐私模式下对应url的cookies。 |
| includeHttpOnly    | boolean | 是   | true表示允许覆盖含有http-only的cookies，false表示不允许覆盖含有http-only的cookies。 |

**返回值：**

| 类型   | 说明                      |
| ------ | ------------------------- |
| Promise\<void> | Promise实例，用于获取指定url设置单个cookie值是否成功。 |

**错误码：**

以下错误码的详细介绍请参见[Webview错误码](errorcode-webview.md)、[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                |
| -------- | ------------------------------------------------------ |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 17100002 | URL error. No valid cookie found for the specified URL. |
| 17100005 | The provided cookie value is invalid. It must follow the format specified in RFC 6265. |

**示例：**

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
      Button('configCookie')
        .onClick(() => {
          try {
            webview.WebCookieManager.configCookie('https://www.example.com', 'a=b', false, false)
              .then(() => {
                console.info('configCookie success!');
              })
              .catch((error: BusinessError) => {
                console.info('error: ' + JSON.stringify(error));
              })
          } catch (error) {
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
          }
        })
      Web({ src: 'www.example.com', controller: this.controller })
    }
  }
}
```

## saveCookieSync<sup>15+</sup>

static saveCookieSync(): void

将当前可通过fetchCookie获取到的所有需要持久化的cookie同步保存到磁盘中。

**系统能力：** SystemCapability.Web.Webview.Core

> **说明：**
>
> - saveCookieSync用于强制将需要持久化的cookies写入磁盘。PC/2in1和Tablet设备不会持久化session cookie，即使调用saveCookieSync，也不会将session cookie写入磁盘。
>
> - saveCookieSync将阻塞调用者直到操作完成，期间可能会执行I/O操作。

**示例：**

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
      Button('saveCookieSync')
        .onClick(() => {
          try {
            webview.WebCookieManager.saveCookieSync();
          } catch (error) {
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
          }
        })
      Web({ src: 'www.example.com', controller: this.controller })
    }
  }
}
```

## saveCookieAsync

static saveCookieAsync(callback: AsyncCallback\<void>): void

将当前可通过fetchCookie获取到的所有需要持久化的cookie异步保存到磁盘中。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名   | 类型                   | 必填 | 说明                                               |
| -------- | ---------------------- | ---- | :------------------------------------------------- |
| callback | AsyncCallback\<void> | 是   | callback回调，用于获取cookie是否成功保存。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                |
| -------- | ------------------------------------------------------ |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed. |

**示例：**

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
      Button('saveCookieAsync')
        .onClick(() => {
          try {
            webview.WebCookieManager.saveCookieAsync((error) => {
              if (error) {
                console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
              }
            })
          } catch (error) {
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
          }
        })
      Web({ src: 'www.example.com', controller: this.controller })
    }
  }
}
```

## saveCookieAsync

static saveCookieAsync(): Promise\<void>

将当前可通过fetchCookie获取到的所有需要持久化的cookie以Promise方法异步保存到磁盘中。

**系统能力：** SystemCapability.Web.Webview.Core

**返回值：**

| 类型             | 说明                                      |
| ---------------- | ----------------------------------------- |
| Promise\<void> | Promise实例，用于获取cookie是否成功保存。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                |
| -------- | ------------------------------------------------------ |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed. |

**示例：**

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
      Button('saveCookieAsync')
        .onClick(() => {
          try {
            webview.WebCookieManager.saveCookieAsync()
              .then(() => {
                console.info("saveCookieAsyncCallback success!");
              })
              .catch((error: BusinessError) => {
                console.error("error: " + error);
              });
          } catch (error) {
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
          }
        })
      Web({ src: 'www.example.com', controller: this.controller })
    }
  }
}
```

## putAcceptCookieEnabled

static putAcceptCookieEnabled(accept: boolean): void

设置WebCookieManager实例是否拥有发送和接收cookie的权限。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名 | 类型    | 必填 | 说明                                 |
| ------ | ------- | ---- | :----------------------------------- |
| accept | boolean | 是   | 设置是否拥有发送和接收cookie的权限，默认为true，表示拥有发送和接收cookie的权限。false表示没有发送和接收cookie的权限。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                |
| -------- | ------------------------------------------------------ |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed. |

**示例：**

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
      Button('putAcceptCookieEnabled')
        .onClick(() => {
          try {
            webview.WebCookieManager.putAcceptCookieEnabled(false);
          } catch (error) {
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
          }
        })
      Web({ src: 'www.example.com', controller: this.controller })
    }
  }
}
```

## isCookieAllowed

static isCookieAllowed(): boolean

获取WebCookieManager实例是否拥有发送和接收cookie的权限。

**系统能力：** SystemCapability.Web.Webview.Core

**返回值：**

| 类型    | 说明                             |
| ------- | -------------------------------- |
| boolean | 是否拥有发送和接收cookie的权限。<br>true表示拥有发送和接收cookie的权限，false表示无发送和接收cookie的权限。<br>默认值：true。 |

**示例：**

```ts
// xxx.ets
import { webview } from '@kit.ArkWeb';

@Entry
@Component
struct WebComponent {
  controller: webview.WebviewController = new webview.WebviewController();

  build() {
    Column() {
      Button('isCookieAllowed')
        .onClick(() => {
          let result = webview.WebCookieManager.isCookieAllowed();
          console.info("result: " + result);
        })
      Web({ src: 'www.example.com', controller: this.controller })
    }
  }
}
```

## putAcceptThirdPartyCookieEnabled

static putAcceptThirdPartyCookieEnabled(accept: boolean): void

设置WebCookieManager实例是否拥有发送和接收第三方cookie的权限。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名 | 类型    | 必填 | 说明                                       |
| ------ | ------- | ---- | :----------------------------------------- |
| accept | boolean | 是   | 是否允许设置、获取第三方cookie。<br>true表示允许设置、获取第三方cookie，false表示不允许设置、获取第三方cookie。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                |
| -------- | ------------------------------------------------------ |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed. |

**示例：**

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
      Button('putAcceptThirdPartyCookieEnabled')
        .onClick(() => {
          try {
            webview.WebCookieManager.putAcceptThirdPartyCookieEnabled(false);
          } catch (error) {
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
          }
        })
      Web({ src: 'www.example.com', controller: this.controller })
    }
  }
}
```

## isThirdPartyCookieAllowed

static isThirdPartyCookieAllowed(): boolean

获取WebCookieManager实例是否拥有发送和接收第三方cookie的权限。

**系统能力：** SystemCapability.Web.Webview.Core

**返回值：**

| 类型    | 说明                                   |
| ------- | -------------------------------------- |
| boolean | 是否拥有发送和接收第三方cookie的权限。<br>true表示拥有发送和接收第三方cookie的权限，false表示无发送和接收第三方cookie的权限。<br>默认值：false。 |

**示例：**

```ts
// xxx.ets
import { webview } from '@kit.ArkWeb';

@Entry
@Component
struct WebComponent {
  controller: webview.WebviewController = new webview.WebviewController();

  build() {
    Column() {
      Button('isThirdPartyCookieAllowed')
        .onClick(() => {
          let result = webview.WebCookieManager.isThirdPartyCookieAllowed();
          console.info("result: " + result);
        })
      Web({ src: 'www.example.com', controller: this.controller })
    }
  }
}
```

## existCookie

static existCookie(incognito?: boolean): boolean

获取是否存在cookie。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名 | 类型    | 必填 | 说明                                       |
| ------ | ------- | ---- | :----------------------------------------- |
| incognito<sup>11+</sup>    | boolean | 否   | true表示隐私模式下查询是否存在cookies，false表示正常非隐私模式下查询是否存在cookies。<br>默认值：false。<br>传入undefined或null时返回undefined。 |

**返回值：**

| 类型    | 说明                                   |
| ------- | -------------------------------------- |
| boolean | true表示存在cookie，false表示不存在cookie。 |

**示例：**

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
          let result = webview.WebCookieManager.existCookie();
          console.info("result: " + result);
        })
      Web({ src: 'www.example.com', controller: this.controller })
    }
  }
}
```

## clearAllCookiesSync<sup>11+</sup>

static clearAllCookiesSync(incognito?: boolean): void

清除所有cookie(包括会话cookie和持久化cookie)。如需仅清除会话cookie，请使用[clearSessionCookieSync](#clearsessioncookiesync11)。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名 | 类型    | 必填 | 说明                                       |
| ------ | ------- | ---- | :----------------------------------------- |
| incognito    | boolean | 否   | true表示清除隐私模式下Webview的所有内存cookies，false表示清除正常非隐私模式下的持久化cookies。<br>默认值：false。<br>传入undefined或null时不清除cookies。 |

**示例：**

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
          webview.WebCookieManager.clearAllCookiesSync();
        })
      Web({ src: 'www.example.com', controller: this.controller })
    }
  }
}
```

## clearAllCookies<sup>11+</sup>

static clearAllCookies(callback: AsyncCallback\<void>): void

清除所有cookie(包括会话cookie和持久化cookie)，使用callback异步回调。如需仅清除会话cookie，请使用[clearSessionCookie](#clearsessioncookie11)。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名   | 类型                   | 必填 | 说明                                               |
| -------- | ---------------------- | ---- | :------------------------------------------------- |
| callback | AsyncCallback\<void> | 是   | callback回调，用于获取清除所有cookie是否成功。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                |
| -------- | ------------------------------------------------------ |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |

**示例：**

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
      Button('clearAllCookies')
        .onClick(() => {
          try {
            webview.WebCookieManager.clearAllCookies((error) => {
              if (error) {
                console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
              }
            })
          } catch (error) {
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
          }
        })
      Web({ src: 'www.example.com', controller: this.controller })
    }
  }
}
```

## clearAllCookies<sup>11+</sup>

static clearAllCookies(): Promise\<void>

清除所有cookie(包括会话cookie和持久化cookie)，使用Promise异步回调。如需仅清除会话cookie，请使用[clearSessionCookie](#clearsessioncookie11-1)。

**系统能力：** SystemCapability.Web.Webview.Core

**返回值：**

| 类型             | 说明                                      |
| ---------------- | ----------------------------------------- |
| Promise\<void> | Promise实例，用于获取清除所有cookie是否成功。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                |
| -------- | ------------------------------------------------------ |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. |

**示例：**

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
      Button('clearAllCookies')
        .onClick(() => {
          webview.WebCookieManager.clearAllCookies()
            .then(() => {
              console.info("clearAllCookies success!");
            })
            .catch((error: BusinessError) => {
              console.error("error: " + error);
            });
        })
      Web({ src: 'www.example.com', controller: this.controller })
    }
  }
}
```

## clearSessionCookieSync<sup>11+</sup>

static clearSessionCookieSync(): void

清除所有会话cookie。

**系统能力：** SystemCapability.Web.Webview.Core

**示例：**

```ts
// xxx.ets
import { webview } from '@kit.ArkWeb';

@Entry
@Component
struct WebComponent {
  controller: webview.WebviewController = new webview.WebviewController();

  build() {
    Column() {
      Button('clearSessionCookieSync')
        .onClick(() => {
          webview.WebCookieManager.clearSessionCookieSync();
        })
      Web({ src: 'www.example.com', controller: this.controller })
    }
  }
}
```

## clearSessionCookie<sup>11+</sup>

static clearSessionCookie(callback: AsyncCallback\<void>): void

异步callback方式清除所有会话cookie。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名   | 类型                   | 必填 | 说明                                               |
| -------- | ---------------------- | ---- | :------------------------------------------------- |
| callback | AsyncCallback\<void> | 是   | callback回调，用于获取清除所有会话cookie是否成功。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                |
| -------- | ------------------------------------------------------ |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |

**示例：**

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
      Button('clearSessionCookie')
        .onClick(() => {
          try {
            webview.WebCookieManager.clearSessionCookie((error) => {
              if (error) {
                console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
              }
            })
          } catch (error) {
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
          }
        })
      Web({ src: 'www.example.com', controller: this.controller })
    }
  }
}
```

## clearSessionCookie<sup>11+</sup>

static clearSessionCookie(): Promise\<void>

清除所有会话cookie。使用Promise异步回调。

**系统能力：** SystemCapability.Web.Webview.Core

**返回值：**

| 类型             | 说明                                      |
| ---------------- | ----------------------------------------- |
| Promise\<void> | Promise实例，用于获取清除所有会话cookie是否成功。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                |
| -------- | ------------------------------------------------------ |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. |

**示例：**

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
      Button('clearSessionCookie')
        .onClick(() => {
          try {
            webview.WebCookieManager.clearSessionCookie()
              .then(() => {
                console.info("clearSessionCookie success!");
              })
              .catch((error: BusinessError) => {
                console.error("error: " + error);
              });
          } catch (error) {
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
          }
        })
      Web({ src: 'www.example.com', controller: this.controller })
    }
  }
}
```

## setLazyInitializeWebEngine<sup>22+</sup>

static setLazyInitializeWebEngine(lazy: boolean): void

设置是否延后初始化ArkWeb内核，不调用该方法时，默认不延后初始化ArkWeb内核。

> **说明：**
>
> - 该接口为全局静态方法，须在使用ArkWeb组件和初始化ArkWeb内核前调用，否则该设置无效。
> 
> - 该接口仅适用于调用后会初始化CookieManager的接口，比如本类WebCookieManager的其他接口。调用本接口设置为true后，再调用适用的接口，会在初始化CookieManager时跳过初始化ArkWeb内核，后续需自行初始化ArkWeb内核。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名 | 类型   | 必填 | 说明                     |
| ---- | ------- | -- | ------------------------- |
| lazy | boolean | 是 | 是否延后初始化ArkWeb内核，true：延后，false：不延后。 |

**示例：**

```ts
// xxx.ets
import { webview } from '@kit.ArkWeb';

webview.WebCookieManager.setLazyInitializeWebEngine(true);

@Entry
@Component
struct WebComponent {
  controller: webview.WebviewController = new webview.WebviewController();

  aboutToAppear(): void {
    webview.WebCookieManager.configCookieSync('https://www.example.com', 'a=b');
    webview.WebCookieManager.fetchCookieSync('https://www.example.com');
  }

  build() {
    Column() {
      Web({ src: 'www.example.com', controller: this.controller })
    }
  }
}
```

## getCookie<sup>(deprecated)</sup>

static getCookie(url: string): string

获取指定url对应cookie的值。

> **说明：**
>
> 从API version 9开始支持，从API version 11开始废弃。建议使用[fetchCookieSync](#fetchcookiesync11)替代。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名 | 类型   | 必填 | 说明                      |
| ------ | ------ | ---- | :------------------------ |
| url    | string | 是   | 要获取的cookie所属的url，建议使用完整的url。 |

**返回值：**

| 类型   | 说明                      |
| ------ | ------------------------- |
| string | 指定url对应的cookie的值。 |

**错误码：**

以下错误码的详细介绍请参见[Webview错误码](errorcode-webview.md)、[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                               |
| -------- | ------------------------------------------------------ |
| 17100002 | URL error. No valid cookie found for the specified URL.  |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed. |

**示例：**

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
      Button('getCookie')
        .onClick(() => {
          try {
            let value = webview.WebCookieManager.getCookie('https://www.example.com');
            console.info("value: " + value);
          } catch (error) {
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
          }
        })
      Web({ src: 'www.example.com', controller: this.controller })
    }
  }
}
```

## setCookie<sup>(deprecated)</sup>

static setCookie(url: string, value: string): void

为指定url设置单个cookie的值。

> **说明：**
>
> 从API version 9开始支持，从API version 11开始废弃。建议使用[configCookieSync<sup>11+</sup>](#configcookiesync11)替代。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名 | 类型   | 必填 | 说明                      |
| ------ | ------ | ---- | :------------------------ |
| url    | string | 是   | 要设置的cookie所属的url，建议使用完整的url。 |
| value  | string | 是   | 要设置的cookie的值。      |

**错误码：**

以下错误码的详细介绍请参见[Webview错误码](errorcode-webview.md)、[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                               |
| -------- | ------------------------------------------------------ |
| 17100002 | URL error. No valid cookie found for the specified URL.  |
| 17100005 | The provided cookie value is invalid. It must follow the format specified in RFC 6265. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |

**示例：**

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
      Button('setCookie')
        .onClick(() => {
          try {
            webview.WebCookieManager.setCookie('https://www.example.com', 'a=b');
          } catch (error) {
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
          }
        })
      Web({ src: 'www.example.com', controller: this.controller })
    }
  }
}
```

## deleteEntireCookie<sup>(deprecated)</sup>

static deleteEntireCookie(): void

清除所有cookie。

> **说明：**
>
> 从API version 9开始支持，从API version 11开始废弃。建议使用[clearAllCookiesSync](#clearallcookiessync11)替代。

**系统能力：** SystemCapability.Web.Webview.Core

**示例：**

```ts
// xxx.ets
import { webview } from '@kit.ArkWeb';

@Entry
@Component
struct WebComponent {
  controller: webview.WebviewController = new webview.WebviewController();

  build() {
    Column() {
      Button('deleteEntireCookie')
        .onClick(() => {
          webview.WebCookieManager.deleteEntireCookie();
        })
      Web({ src: 'www.example.com', controller: this.controller })
    }
  }
}
```

## deleteSessionCookie<sup>(deprecated)</sup>

static deleteSessionCookie(): void

清除所有会话cookie。

> **说明：**
>
> 从API version 9开始支持，从API version 11开始废弃。建议使用[clearSessionCookieSync](#clearsessioncookiesync11)替代。

**系统能力：** SystemCapability.Web.Webview.Core

**示例：**

```ts
// xxx.ets
import { webview } from '@kit.ArkWeb';

@Entry
@Component
struct WebComponent {
  controller: webview.WebviewController = new webview.WebviewController();

  build() {
    Column() {
      Button('deleteSessionCookie')
        .onClick(() => {
          webview.WebCookieManager.deleteSessionCookie();
        })
      Web({ src: 'www.example.com', controller: this.controller })
    }
  }
}
```