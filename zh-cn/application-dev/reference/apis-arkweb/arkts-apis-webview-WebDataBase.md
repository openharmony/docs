# Class (WebDataBase)
<!--Kit: ArkWeb-->
<!--Subsystem: Web-->
<!--Owner: @yuzhouhang1-->
<!--Designer: @handyohos-->
<!--Tester: @ghiker-->
<!--Adviser: @HelloShuo-->

Web组件数据库管理对象。

## 概述

WebDataBase是Web组件提供的数据库管理类，用于管理Web组件中的HTTP身份验证凭据，包括凭据的保存、查询、判断和删除操作。适用于需要自动管理Web应用HTTP身份验证凭据的场景，能够解决用户频繁输入用户名密码的问题，提升用户体验并减少重复操作。

### 基本概念

- **HTTP身份验证凭据**：包含用户名和密码的认证信息，用于访问受保护的HTTP资源。
- **主机和认证域**：凭据应用的目标主机和认证域。
- **同步方法**：WebDataBase提供的所有方法均为同步方法，调用后立即返回结果。

### 关键设计

WebDataBase采用静态类设计：
1. 提供静态方法管理HTTP身份验证凭据。
2. 支持凭据的保存、查询和删除操作。
3. 所有方法都需要先加载Web组件才能使用。

### 主要方法
| 方法名 | 说明 |
|--------|------|
| [getHttpAuthCredentials](#gethttpauthcredentials) | 检索给定主机和域的HTTP身份验证凭据。用于在需要重新登录或验证用户身份时获取已保存的凭据信息，例如应用重启后自动填充登录表单、访问需要身份验证的受保护网页等场景。 |
| [saveHttpAuthCredentials](#savehttpauthcredentials) | 保存给定主机和域的HTTP身份验证凭据。用于用户首次成功登录后保存凭据，以便下次访问相同网站时能够自动登录或无需重复输入认证信息，提升用户体验。 |
| [existHttpAuthCredentials](#existhttpauthcredentials) | 判断是否存在任何已保存的HTTP身份验证凭据。用于在应用启动时检查是否已保存凭据以决定是否显示登录页面，或在用户访问受保护资源前判断是否需要重新认证。 |
| [deleteHttpAuthCredentials](#deletehttpauthcredentials) | 清除所有已保存的HTTP身份验证凭据。用于用户退出登录、切换账户或清除应用数据时删除所有凭据信息，保护用户隐私和账户安全。 |

### 使用示例

```ts
import { webview } from '@kit.ArkWeb';

// 保存HTTP身份验证凭据
webview.WebDataBase.saveHttpAuthCredentials('www.example.com', 'protected', 'username', 'password');

// 检索凭据
let credentials = webview.WebDataBase.getHttpAuthCredentials('www.example.com', 'protected');

// 检查是否存在凭据
let exists = webview.WebDataBase.existHttpAuthCredentials();

// 删除所有凭据
webview.WebDataBase.deleteHttpAuthCredentials();
```

> **说明：**
>
> - 本模块首批接口从API version 9开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。
>
> - 本Class首批接口从API version 9开始支持。
>
> - 示例效果请以真机运行为准。
>
> - 目前调用WebDataBase下的方法，都需要先加载Web组件。

## 导入模块

```ts
import { webview } from '@kit.ArkWeb';
```

## getHttpAuthCredentials

static getHttpAuthCredentials(host: string, realm: string): Array\<string>

检索给定主机和域的HTTP身份验证凭据，该方法为同步方法。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名 | 类型   | 必填 | 说明                         |
| ------ | ------ | ---- | ---------------------------- |
| host   | string | 是   | HTTP身份验证凭据应用的主机地址，格式如'www.example.com'或'192.168.1.1'，不包含协议和端口号。 |
| realm  | string | 是   | HTTP身份验证凭据应用的认证域，表示在同一主机下进行身份验证的范围或保护区域，通常由服务器返回的WWW-Authenticate头指定。 |

**返回值：**

| 类型  | 说明                                         |
| ----- | -------------------------------------------- |
| Array\<string> | 包含用户名和密码的数组，检索失败返回空数组。 |

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
  host: string = 'www.spincast.org';
  realm: string = 'protected example';
  usernamePassword: string[] = [];

  build() {
    Column() {
      Button('getHttpAuthCredentials')
        .onClick(() => {
          try {
            this.usernamePassword = webview.WebDataBase.getHttpAuthCredentials(this.host, this.realm);
            console.info('num: ' + this.usernamePassword.length);
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

保存给定主机和域的HTTP身份验证凭据，该方法为同步方法。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名   | 类型   | 必填 | 说明                         |
| -------- | ------ | ---- | ---------------------------- |
| host     | string | 是   | HTTP身份验证凭据应用的主机，用于匹配凭据对应的主机。 |
| realm    | string | 是   | HTTP身份验证凭据应用的域，用于匹配凭据对应的认证域。   |
| username | string | 是 | 用于HTTP身份验证的用户名，表示访问受保护资源的身份标识。|
| password | string | 是 | 用于HTTP身份验证的密码，配合用户名完成身份验证。|

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
  host: string = 'www.spincast.org';
  realm: string = 'protected example';

  build() {
    Column() {
      Button('saveHttpAuthCredentials')
        .onClick(() => {
          try {
            webview.WebDataBase.saveHttpAuthCredentials(this.host, this.realm, 'Stromgol', 'Laroche');
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

判断是否存在任何已保存的HTTP身份验证凭据，该方法为同步方法。

**系统能力：** SystemCapability.Web.Webview.Core

**返回值：**

| 类型    | 说明                                                         |
| ------- | ------------------------------------------------------------ |
| boolean | 是否存在任何已保存的HTTP身份验证凭据。<br>存在返回true，不存在返回false。 |

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
      Button('existHttpAuthCredentials')
        .onClick(() => {
          try {
            if (webview.WebDataBase.existHttpAuthCredentials()) {
                console.info('HTTP auth credentials exist.');
              } else {
                console.info('No HTTP auth credentials found.');
              }
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

清除所有已保存的HTTP身份验证凭据，该方法为同步方法。

**系统能力：** SystemCapability.Web.Webview.Core

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