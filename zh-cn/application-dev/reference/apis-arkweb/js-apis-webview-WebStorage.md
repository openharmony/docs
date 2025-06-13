# Class (WebStorage)

通过WebStorage可管理Web SQL数据库接口和HTML5 Web存储接口，每个应用中的所有Web组件共享一个WebStorage。

> **说明：**
>
> - 本模块接口从API version 9开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。
>
> - 示例效果请以真机运行为准，当前IDE预览器不支持。
>
> - 目前调用WebStorage下的方法，都需要先加载Web组件。

## deleteOrigin

static deleteOrigin(origin: string): void

清除指定源所使用的存储。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名 | 类型   | 必填 | 说明                     |
| ------ | ------ | ---- | ------------------------ |
| origin | string | 是   | 指定源的字符串索引，来自于[getOrigins](#getorigins)。 |

**错误码：**

以下错误码的详细介绍请参见[webview错误码](errorcode-webview.md)。

| 错误码ID | 错误信息                                               |
| -------- | ------------------------------------------------------ |
| 17100011 | Invalid origin.                             |
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
  origin: string = "resource://rawfile/";

  build() {
    Column() {
      Button('deleteOrigin')
        .onClick(() => {
          try {
            webview.WebStorage.deleteOrigin(this.origin);
          } catch (error) {
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
          }

        })
      Web({ src: $rawfile('index.html'), controller: this.controller })
        .databaseAccess(true)
    }
  }
}
```

加载的html文件。
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
        msg = '<p>数据表已创建，且插入了两条数据。</p>';

        document.querySelector('#status').innerHTML = msg;
      });

      db.transaction(function(tx){
        tx.executeSql('SELECT * FROM LOGS', [], function (tx, results) {
          var len = results.rows.length,i;
          msg = "<p>查询记录条数：" + len + "</p>";

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
  <div id="status" name="status">状态信息</div>
  </body>
  </html>
 ```

## getOrigins

static getOrigins(callback: AsyncCallback\<Array\<WebStorageOrigin>>): void

以回调方式异步获取当前使用Web SQL数据库的所有源的信息。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名   | 类型                                   | 必填 | 说明                                                   |
| -------- | -------------------------------------- | ---- | ------------------------------------------------------ |
| callback | AsyncCallback\<Array\<[WebStorageOrigin](./js-apis-webview-i.md#webstorageorigin)>> | 是   | 以数组方式返回源的信息。 |

**错误码：**

以下错误码的详细介绍请参见[webview错误码](errorcode-webview.md)。

| 错误码ID | 错误信息                                               |
| -------- | ------------------------------------------------------ |
| 17100012 | Invalid web storage origin.                             |
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
      Button('getOrigins')
        .onClick(() => {
          try {
            webview.WebStorage.getOrigins((error, origins) => {
              if (error) {
                console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
                return;
              }
              for (let i = 0; i < origins.length; i++) {
                console.log('origin: ' + origins[i].origin);
                console.log('usage: ' + origins[i].usage);
                console.log('quota: ' + origins[i].quota);
              }
            })
          } catch (error) {
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
          }

        })
      Web({ src: $rawfile('index.html'), controller: this.controller })
        .databaseAccess(true)
    }
  }
}
```

加载的html文件，请参考[deleteOrigin](#deleteorigin)接口下的html文件。

## getOrigins

static getOrigins(): Promise\<Array\<WebStorageOrigin>>

以Promise方式异步获取当前使用Web SQL数据库的所有源的信息。

**系统能力：** SystemCapability.Web.Webview.Core

**返回值：**

| 类型                             | 说明                                                         |
| -------------------------------- | ------------------------------------------------------------ |
| Promise\<Array\<[WebStorageOrigin](./js-apis-webview-i.md#webstorageorigin)>> | Promise实例，用于获取当前所有源的信息。 |

**错误码：**

以下错误码的详细介绍请参见[webview错误码](errorcode-webview.md)。

| 错误码ID | 错误信息                                               |
| -------- | ------------------------------------------------------ |
| 17100012 | Invalid web storage origin.                             |
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
      Button('getOrigins')
        .onClick(() => {
          try {
            webview.WebStorage.getOrigins()
              .then(origins => {
                for (let i = 0; i < origins.length; i++) {
                  console.log('origin: ' + origins[i].origin);
                  console.log('usage: ' + origins[i].usage);
                  console.log('quota: ' + origins[i].quota);
                }
              })
              .catch((e: BusinessError) => {
                console.log('error: ' + JSON.stringify(e));
              })
          } catch (error) {
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
          }

        })
      Web({ src: $rawfile('index.html'), controller: this.controller })
        .databaseAccess(true)
    }
  }
}
```

加载的html文件，请参考[deleteOrigin](#deleteorigin)接口下的html文件。

## getOriginQuota

static getOriginQuota(origin: string, callback: AsyncCallback\<number>): void

使用callback回调异步获取指定源的Web SQL数据库的存储配额，配额以字节为单位。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名   | 类型                  | 必填 | 说明               |
| -------- | --------------------- | ---- | ------------------ |
| origin   | string                | 是   | 指定源的字符串索引。 |
| callback | AsyncCallback\<number> | 是   | 指定源的存储配额。<br>number是long型整数，范围为(-2,147,483,648)~(2,147,483,647)。   |

**错误码：**

以下错误码的详细介绍请参见[webview错误码](errorcode-webview.md)。

| 错误码ID | 错误信息                                               |
| -------- | ------------------------------------------------------ |
| 17100011 | Invalid origin.                             |
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
  origin: string = "resource://rawfile/";

  build() {
    Column() {
      Button('getOriginQuota')
        .onClick(() => {
          try {
            webview.WebStorage.getOriginQuota(this.origin, (error, quota) => {
              if (error) {
                console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
                return;
              }
              console.log('quota: ' + quota);
            })
          } catch (error) {
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
          }

        })
      Web({ src: $rawfile('index.html'), controller: this.controller })
        .databaseAccess(true)
    }
  }
}
```

加载的html文件，请参考[deleteOrigin](#deleteorigin)接口下的html文件。

## getOriginQuota

static getOriginQuota(origin: string): Promise\<number>

以Promise方式异步获取指定源的Web SQL数据库的存储配额，配额以字节为单位。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名 | 类型   | 必填 | 说明               |
| ------ | ------ | ---- | ------------------ |
| origin | string | 是   | 指定源的字符串索引 |

**返回值：**

| 类型            | 说明                                    |
| --------------- | --------------------------------------- |
| Promise\<number> | Promise实例，用于获取指定源的存储配额。 |

**错误码：**

以下错误码的详细介绍请参见[webview错误码](errorcode-webview.md)。

| 错误码ID | 错误信息                                               |
| -------- | ------------------------------------------------------ |
| 17100011 | Invalid origin.                             |
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
  origin: string = "resource://rawfile/";

  build() {
    Column() {
      Button('getOriginQuota')
        .onClick(() => {
          try {
            webview.WebStorage.getOriginQuota(this.origin)
              .then(quota => {
                console.log('quota: ' + quota);
              })
              .catch((e: BusinessError) => {
                console.log('error: ' + JSON.stringify(e));
              })
          } catch (error) {
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
          }

        })
      Web({ src: $rawfile('index.html'), controller: this.controller })
        .databaseAccess(true)
    }
  }
}
```

加载的html文件，请参考[deleteOrigin](#deleteorigin)接口下的html文件。

## getOriginUsage

static getOriginUsage(origin: string, callback: AsyncCallback\<number>): void

以回调方式异步获取指定源的Web SQL数据库的存储量，存储量以字节为单位。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名   | 类型                  | 必填 | 说明               |
| -------- | --------------------- | ---- | ------------------ |
| origin   | string                | 是   | 指定源的字符串索引 |
| callback | AsyncCallback\<number> | 是   | 指定源的存储量。   |

**错误码：**

以下错误码的详细介绍请参见[webview错误码](errorcode-webview.md)。

| 错误码ID | 错误信息                                               |
| -------- | ------------------------------------------------------ |
| 17100011 | Invalid origin.                             |
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
  origin: string = "resource://rawfile/";

  build() {
    Column() {
      Button('getOriginUsage')
        .onClick(() => {
          try {
            webview.WebStorage.getOriginUsage(this.origin, (error, usage) => {
              if (error) {
                console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
                return;
              }
              console.log('usage: ' + usage);
            })
          } catch (error) {
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
          }

        })
      Web({ src: $rawfile('index.html'), controller: this.controller })
        .databaseAccess(true)
    }
  }
}
```

加载的html文件，请参考[deleteOrigin](#deleteorigin)接口下的html文件。

## getOriginUsage

static getOriginUsage(origin: string): Promise\<number>

以Promise方式异步获取指定源的Web SQL数据库的存储量，存储量以字节为单位。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名 | 类型   | 必填 | 说明               |
| ------ | ------ | ---- | ------------------ |
| origin | string | 是   | 指定源的字符串索引 |

**返回值：**

| 类型            | 说明                                  |
| --------------- | ------------------------------------- |
| Promise\<number> | Promise实例，用于获取指定源的存储量。 |

**错误码：**

以下错误码的详细介绍请参见[webview错误码](errorcode-webview.md)。

| 错误码ID | 错误信息                                              |
| -------- | ----------------------------------------------------- |
| 17100011 | Invalid origin.                            |
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
  origin: string = "resource://rawfile/";

  build() {
    Column() {
      Button('getOriginUsage')
        .onClick(() => {
          try {
            webview.WebStorage.getOriginUsage(this.origin)
              .then(usage => {
                console.log('usage: ' + usage);
              }).catch((e: BusinessError) => {
              console.error('error: ' + JSON.stringify(e));
            })
          } catch (error) {
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
          }
        })
      Web({ src: $rawfile('index.html'), controller: this.controller })
        .databaseAccess(true)
    }
  }
}
```

加载的html文件，请参考[deleteOrigin](#deleteorigin)接口下的html文件。

## deleteAllData

static deleteAllData(incognito?: boolean): void

清除Web SQL数据库当前使用的所有存储。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名 | 类型   | 必填 | 说明               |
| ------ | ------ | ---- | ------------------ |
| incognito<sup>11+</sup>    | boolean | 否   | true表示删除所有隐私模式下内存中的web数据，false表示删除正常非隐私模式下Web的SQL数据库当前使用的所有存储。 |

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
      Button('deleteAllData')
        .onClick(() => {
          try {
            webview.WebStorage.deleteAllData();
          } catch (error) {
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
          }
        })
      Web({ src: $rawfile('index.html'), controller: this.controller })
        .databaseAccess(true)
    }
  }
}
```

加载的html文件，请参考[deleteOrigin](#deleteorigin)接口下加载的html文件。