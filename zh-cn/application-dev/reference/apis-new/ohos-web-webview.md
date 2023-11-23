# @ohos.web.webview    
eb控制能力，[web](../arkui-ts/ts-basic-components-web.md)组件提供网页显示的能力。  
> **说明**   
>本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
## 导入模块  
  
```js    
import webview from '@ohos.web.webview'    
```  
    
## WebHeader    
Web组件返回的请求/响应头对象。  
 **系统能力:**  SystemCapability.Web.Webview.Core    
### 属性    
 **系统能力:**  SystemCapability.Web.Webview.Core    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| headerKey | string | false | true | 请求/响应头的key。 |  
| headerValue | string | false | true |  |  
    
## WebHitTestType    
    
 **系统能力:**  SystemCapability.Web.Webview.Core    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| EditText | 0 | 可编辑的区域。 |  
| Email | 1 | 电子邮件地址。 |  
| HttpAnchor | 2 | 超链接，其src为http。 |  
| HttpAnchorImg | 3 | 带有超链接的图片，其中超链接的src为http。 |  
| Img | 4 | HTML::img标签。 |  
| Map | 5 | 地理地址。 |  
| Phone | 6 | 电话号码。 |  
| Unknown | 7 | 未知内容。 |  
    
## SecureDnsMode<sup>(10+)</sup>    
Web组件使用HTTPDNS的模式。    
    
 **系统能力:**  SystemCapability.Web.Webview.Core    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| OFF | 0 | 不使用HTTPDNS， 可以用于撤销之前使用的HTTPDNS配置。 |  
| AUTO | 1 | 自动模式，用于解析的设定dns服务器不可用时，可自动回落至系统DNS。 |  
| SECURE_ONLY | 2 | 强制使用设定的HTTPDNS服务器进行域名解析。 |  
    
## HitTestValue    
提供点击区域的元素信息。示例代码参考getHitTestValue。  
 **系统能力:**  SystemCapability.Web.Webview.Core    
### 属性    
 **系统能力:**  SystemCapability.Web.Webview.Core    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| type | WebHitTestType | false | true | 当前被点击区域的元素类型。 |  
| extra | string | false | true | 点击区域的附加参数信息。若被点击区域为图片或链接，则附加参数信息为其url地址。 |  
    
## WebCustomScheme    
自定义协议配置。  
 **系统能力:**  SystemCapability.Web.Webview.Core    
### 属性    
 **系统能力:**  SystemCapability.Web.Webview.Core    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| schemeName | string | false | true | 自定义协议名称。最大长度为32，其字符仅支持小写字母、数字、'.'、'+'、'-'。 |  
| isSupportCORS | boolean | false | true | 是否支持跨域请求。 |  
| isSupportFetch | boolean | false | true | 是否支持fetch请求。 |  
    
## WebStorageOrigin    
提供Web SQL数据库的使用信息。  
 **系统能力:**  SystemCapability.Web.Webview.Core    
### 属性    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| origin | string | false | true | 指定源的字符串索引。 |  
| usage | number | false | true | 指定源的存储量。 |  
| quota | number | false | true | 指定源的存储配额。 |  
    
## once    
订阅一次指定类型Web事件的回调。  
 **调用形式：**     
- once(type: string, callback: Callback\<void>): void  
  
 **系统能力:**  SystemCapability.Web.Webview.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | string | true | Web事件的类型，目前支持："webInited"（Web初始化完成）。 |  
| callback | Callback<void> | true | 所订阅的回调函数。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
    
 **示例代码：**   
```ts    
// xxx.ets  
import web_webview from '@ohos.web.webview'  
  
web_webview.once("webInited", () => {  
  console.log("setCookie")  
  web_webview.WebCookieManager.setCookie("https://www.example.com", "a=b")  
})  
  
@Entry  
@Component  
struct WebComponent {  
  controller: web_webview.WebviewController = new web_webview.WebviewController();  
  
  build() {  
    Column() {  
      Web({ src: 'www.example.com', controller: this.controller })  
    }  
  }  
}  
    
```    
  
    
## WebStorage    
通过WebStorage可管理Web SQL数据库接口和HTML5 Web存储接口，每个应用中的所有Web组件共享一个WebStorage。  
 **系统能力:**  SystemCapability.Web.Webview.Core    
### deleteAllData    
清除Web SQL数据库当前使用的所有存储。  
 **调用形式：**     
- static deleteAllData(): void  
  
 **系统能力:**  SystemCapability.Web.Webview.Core    
 **示例代码：**   
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
            web_webview.WebStorage.deleteAllData();  
          } catch (error) {  
            let e: business_error.BusinessError = error as business_error.BusinessError;  
            console.error(`ErrorCode: ${e.code},  Message: ${e.message}`);  
          }  
        })  
      Web({ src: $rawfile('index.html'), controller: this.controller })  
        .databaseAccess(true)  
    }  
  }  
}  
    
```    
  
    
### deleteOrigin    
清除指定源所使用的存储。  
 **调用形式：**     
- static deleteOrigin(origin: string): void  
  
 **系统能力:**  SystemCapability.Web.Webview.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| origin | string | true | 指定源的字符串索引，来自于[getOrigins](#getorigins)。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 17100011 | Invalid origin. |  
    
 **示例代码：**   
```ts    
// xxx.ets  
import web_webview from '@ohos.web.webview';  
import business_error from '@ohos.base';  
  
@Entry  
@Component  
struct WebComponent {  
  controller: web_webview.WebviewController = new web_webview.WebviewController();  
  origin: string = "resource://rawfile/";  
  
  build() {  
    Column() {  
      Button('deleteOrigin')  
        .onClick(() => {  
          try {  
            web_webview.WebStorage.deleteOrigin(this.origin);  
          } catch (error) {  
            let e: business_error.BusinessError = error as business_error.BusinessError;  
            console.error(`ErrorCode: ${e.code},  Message: ${e.message}`);  
          }  
  
        })  
      Web({ src: $rawfile('index.html'), controller: this.controller })  
        .databaseAccess(true)  
    }  
  }  
}  
    
```    
  
    
### getOrigins    
以回调方式异步获取当前使用Web SQL数据库的所有源的信息。  
 **调用形式：**     
    
- static getOrigins(): Promise\<Array\<WebStorageOrigin>>    
起始版本： 9    
- static getOrigins(callback: AsyncCallback\<Array\<WebStorageOrigin>>): void    
起始版本： 9  
  
 **系统能力:**  SystemCapability.Web.Webview.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 以数组方式返回源的信息，信息内容参考[WebStorageOrigin](#webstorageorigin)。 |  
| Promise<Array<WebStorageOrigin>> | Promise实例，用于获取当前所有源的信息，信息内容参考[WebStorageOrigin](#webstorageorigin)。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 17100012 | Invalid web storage origin. |  
    
 **示例代码1：**   
示例（callback）:  
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
      Button('getOrigins')  
        .onClick(() => {  
          try {  
            web_webview.WebStorage.getOrigins((error, origins) => {  
              if (error) {  
                console.log('error: ' + JSON.stringify(error));  
                return;  
              }  
              for (let i = 0; i < origins.length; i++) {  
                console.log('origin: ' + origins[i].origin);  
                console.log('usage: ' + origins[i].usage);  
                console.log('quota: ' + origins[i].quota);  
              }  
            })  
          } catch (error) {  
            let e: business_error.BusinessError = error as business_error.BusinessError;  
            console.error(`ErrorCode: ${e.code},  Message: ${e.message}`);  
          }  
  
        })  
      Web({ src: $rawfile('index.html'), controller: this.controller })  
        .databaseAccess(true)  
    }  
  }  
}  
    
```    
  
    
 **示例代码2：**   
示例（Promise）:  
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
      Button('getOrigins')  
        .onClick(() => {  
          try {  
            web_webview.WebStorage.getOrigins()  
              .then(origins => {  
                for (let i = 0; i < origins.length; i++) {  
                  console.log('origin: ' + origins[i].origin);  
                  console.log('usage: ' + origins[i].usage);  
                  console.log('quota: ' + origins[i].quota);  
                }  
              })  
              .catch((e : business_error.BusinessError) => {  
                console.log('error: ' + JSON.stringify(e));  
              })  
          } catch (error) {  
            let e: business_error.BusinessError = error as business_error.BusinessError;  
            console.error(`ErrorCode: ${e.code},  Message: ${e.message}`);  
          }  
  
        })  
      Web({ src: $rawfile('index.html'), controller: this.controller })  
        .databaseAccess(true)  
    }  
  }  
}  
    
```    
  
    
### getOriginQuota    
使用callback回调异步获取指定源的Web SQL数据库的存储配额，配额以字节为单位。  
 **调用形式：**     
    
- static getOriginQuota(origin: string): Promise\<number>    
起始版本： 9    
- static getOriginQuota(origin: string, callback: AsyncCallback\<number>): void    
起始版本： 9  
  
 **系统能力:**  SystemCapability.Web.Webview.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| origin | string | true | 指定源的字符串索引 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 指定源的存储配额 |  
| Promise<number> | Promise实例，用于获取指定源的存储配额。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 17100011 | Invalid origin. |  
    
 **示例代码1：**   
示例（callback）:  
```ts    
// xxx.ets  
import web_webview from '@ohos.web.webview';  
import business_error from '@ohos.base';  
  
@Entry  
@Component  
struct WebComponent {  
  controller: web_webview.WebviewController = new web_webview.WebviewController();  
  origin: string = "resource://rawfile/";  
  
  build() {  
    Column() {  
      Button('getOriginQuota')  
        .onClick(() => {  
          try {  
            web_webview.WebStorage.getOriginQuota(this.origin, (error, quota) => {  
              if (error) {  
                console.log('error: ' + JSON.stringify(error));  
                return;  
              }  
              console.log('quota: ' + quota);  
            })  
          } catch (error) {  
            let e: business_error.BusinessError = error as business_error.BusinessError;  
            console.error(`ErrorCode: ${e.code},  Message: ${e.message}`);  
          }  
  
        })  
      Web({ src: $rawfile('index.html'), controller: this.controller })  
        .databaseAccess(true)  
    }  
  }  
}  
    
```    
  
    
 **示例代码2：**   
示例（Promise）:  
```ts    
// xxx.ets  
import web_webview from '@ohos.web.webview';  
import business_error from '@ohos.base';  
  
@Entry  
@Component  
struct WebComponent {  
  controller: web_webview.WebviewController = new web_webview.WebviewController();  
  origin: string = "resource://rawfile/";  
  
  build() {  
    Column() {  
      Button('getOriginQuota')  
        .onClick(() => {  
          try {  
            web_webview.WebStorage.getOriginQuota(this.origin)  
              .then(quota => {  
                console.log('quota: ' + quota);  
              })  
              .catch((e : business_error.BusinessError) => {  
                console.log('error: ' + JSON.stringify(e));  
              })  
          } catch (error) {  
            let e: business_error.BusinessError = error as business_error.BusinessError;  
            console.error(`ErrorCode: ${e.code},  Message: ${e.message}`);  
          }  
  
        })  
      Web({ src: $rawfile('index.html'), controller: this.controller })  
        .databaseAccess(true)  
    }  
  }  
}  
    
```    
  
    
### getOriginUsage    
以回调方式异步获取指定源的Web SQL数据库的存储量，存储量以字节为单位。  
 **调用形式：**     
    
- static getOriginUsage(origin: string): Promise\<number>    
起始版本： 9    
- static getOriginUsage(origin: string, callback: AsyncCallback\<number>): void    
起始版本： 9  
  
 **系统能力:**  SystemCapability.Web.Webview.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| origin | string | true | 指定源的字符串索引 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 指定源的存储量。 |  
| Promise<number> | Promise实例，用于获取指定源的存储量。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 17100011 | Invalid origin. |  
    
 **示例代码1：**   
示例（callback）:  
```ts    
// xxx.ets  
import web_webview from '@ohos.web.webview';  
import business_error from '@ohos.base';  
  
@Entry  
@Component  
struct WebComponent {  
  controller: web_webview.WebviewController = new web_webview.WebviewController();  
  origin: string = "resource://rawfile/";  
  
  build() {  
    Column() {  
      Button('getOriginUsage')  
        .onClick(() => {  
          try {  
            web_webview.WebStorage.getOriginUsage(this.origin, (error, usage) => {  
              if (error) {  
                console.log('error: ' + JSON.stringify(error));  
                return;  
              }  
              console.log('usage: ' + usage);  
            })  
          } catch (error) {  
            let e: business_error.BusinessError = error as business_error.BusinessError;  
            console.error(`ErrorCode: ${e.code},  Message: ${e.message}`);  
          }  
  
        })  
      Web({ src: $rawfile('index.html'), controller: this.controller })  
        .databaseAccess(true)  
    }  
  }  
}  
    
```    
  
    
 **示例代码2：**   
示例（Promise）:  
```ts    
// xxx.ets  
import web_webview from '@ohos.web.webview';  
import business_error from '@ohos.base';  
  
@Entry  
@Component  
struct WebComponent {  
  controller: web_webview.WebviewController = new web_webview.WebviewController();  
  origin: string = "resource://rawfile/";  
  
  build() {  
    Column() {  
      Button('getOriginUsage')  
        .onClick(() => {  
          try {  
            web_webview.WebStorage.getOriginUsage(this.origin)  
              .then(usage => {  
                console.log('usage: ' + usage);  
              })  
              .catch((e : business_error.BusinessError) => {  
                console.log('error: ' + JSON.stringify(e));  
              })  
          } catch (error) {  
            let e: business_error.BusinessError = error as business_error.BusinessError;  
            console.error(`ErrorCode: ${e.code},  Message: ${e.message}`);  
          }  
  
        })  
      Web({ src: $rawfile('index.html'), controller: this.controller })  
        .databaseAccess(true)  
    }  
  }  
}  
    
```    
  
    
## WebDataBase    
<span style="letter-spacing: 0px;">web组件数据库管理对象。</span>  
 **系统能力:**  SystemCapability.Web.Webview.Core    
### existHttpAuthCredentials    
判断是否存在任何已保存的HTTP身份验证凭据，该方法为同步方法。存在返回true，不存在返回false。  
 **调用形式：**     
- static existHttpAuthCredentials(): boolean  
  
 **系统能力:**  SystemCapability.Web.Webview.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | 是否存在任何已保存的HTTP身份验证凭据。存在返回true，不存在返回false |  
    
 **示例代码：**   
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
      Button('existHttpAuthCredentials')  
        .onClick(() => {  
          try {  
            let result = web_webview.WebDataBase.existHttpAuthCredentials();  
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
  
    
### deleteHttpAuthCredentials    
清除所有已保存的HTTP身份验证凭据，该方法为同步方法。  
 **调用形式：**     
- static deleteHttpAuthCredentials(): void  
  
 **系统能力:**  SystemCapability.Web.Webview.Core    
 **示例代码：**   
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
      Button('deleteHttpAuthCredentials')  
        .onClick(() => {  
          try {  
            web_webview.WebDataBase.deleteHttpAuthCredentials();  
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
  
    
### getHttpAuthCredentials    
检索给定主机和域的HTTP身份验证凭据，该方法为同步方法。  
 **调用形式：**     
- static getHttpAuthCredentials(host: string, realm: string): Array\<string>  
  
 **系统能力:**  SystemCapability.Web.Webview.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| host | string | true | HTTP身份验证凭据应用的主机。 |  
| realm | string | true | HTTP身份验证凭据应用的域。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Array<string> | 包含用户名和密码的组数，检索失败返回空数组。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 | Invalid input parameter. |  
    
 **示例代码：**   
```ts    
// xxx.ets  
import web_webview from '@ohos.web.webview';  
import business_error from '@ohos.base';  
  
@Entry  
@Component  
struct WebComponent {  
  controller: web_webview.WebviewController = new web_webview.WebviewController();  
  host: string = "www.spincast.org";  
  realm: string = "protected example";  
  username_password: string[] = [];  
  
  build() {  
    Column() {  
      Button('getHttpAuthCredentials')  
        .onClick(() => {  
          try {  
            this.username_password = web_webview.WebDataBase.getHttpAuthCredentials(this.host, this.realm);  
            console.log('num: ' + this.username_password.length);  
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
  
    
### saveHttpAuthCredentials    
保存给定主机和域的HTTP身份验证凭据，该方法为同步方法。  
 **调用形式：**     
- static saveHttpAuthCredentials(host: string, realm: string, username: string, password: string): void  
  
 **系统能力:**  SystemCapability.Web.Webview.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| host | string | true | HTTP身份验证凭据应用的主机。 |  
| realm | string | true | HTTP身份验证凭据应用的域。 |  
| username | string | true | 用户名。 |  
| password | string | true | 密码。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 | Invalid input parameter. |  
    
 **示例代码：**   
```ts    
// xxx.ets  
import web_webview from '@ohos.web.webview';  
import business_error from '@ohos.base';  
  
@Entry  
@Component  
struct WebComponent {  
  controller: web_webview.WebviewController = new web_webview.WebviewController();  
  host: string = "www.spincast.org";  
  realm: string = "protected example";  
  
  build() {  
    Column() {  
      Button('saveHttpAuthCredentials')  
        .onClick(() => {  
          try {  
            web_webview.WebDataBase.saveHttpAuthCredentials(this.host, this.realm, "Stromgol", "Laroche");  
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
  
    
## GeolocationPermissions    
web组件地理位置权限管理对象。  
 **系统能力:**  SystemCapability.Web.Webview.Core    
### allowGeolocation    
允许指定来源使用地理位置接口。  
 **调用形式：**     
- static allowGeolocation(origin: string): void  
  
 **系统能力:**  SystemCapability.Web.Webview.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| origin | string | true | 指定源的字符串索引 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 | Invalid input parameter. |  
| 17100011 | Invalid origin. |  
    
 **示例代码：**   
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
            web_webview.GeolocationPermissions.allowGeolocation(this.origin);  
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
  
    
### deleteGeolocation    
清除指定来源的地理位置权限状态。  
 **调用形式：**     
- static deleteGeolocation(origin: string): void  
  
 **系统能力:**  SystemCapability.Web.Webview.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| origin | string | true | 指定源的字符串索引 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 | Invalid input parameter. |  
| 17100011 | Invalid origin. |  
    
 **示例代码：**   
```ts    
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
            web_webview.GeolocationPermissions.deleteGeolocation(this.origin);  
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
  
    
### deleteAllGeolocation    
清除所有来源的地理位置权限状态。  
 **调用形式：**     
- static deleteAllGeolocation(): void  
  
 **系统能力:**  SystemCapability.Web.Webview.Core    
 **示例代码：**   
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
      Button('deleteAllGeolocation')  
        .onClick(() => {  
          try {  
            web_webview.GeolocationPermissions.deleteAllGeolocation();  
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
  
    
### getAccessibleGeolocation    
以回调方式异步获取指定源的地理位置权限状态。  
 **调用形式：**     
    
- static getAccessibleGeolocation(origin: string): Promise\<boolean>    
起始版本： 9    
- static getAccessibleGeolocation(origin: string, callback: AsyncCallback\<boolean>): void    
起始版本： 9  
  
 **系统能力:**  SystemCapability.Web.Webview.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| origin | string | true |  <span style="letter-spacing: 0px;">指定源的字符串索引</span><br/> |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 返回指定源的地理位置权限状态。获取成功，true表示已授权，false表示拒绝访问。获取失败，表示不存在指定源的权限状态。 |  
| Promise<boolean> | Promise实例，用于获取指定源的权限状态，获取成功，true表示已授权，false表示拒绝访问。获取失败，表示不存在指定源的权限状态。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 | Invalid input parameter. |  
| 17100011 | Invalid origin. |  
    
 **示例代码1：**   
示例（callback）:  
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
            });  
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
  
    
 **示例代码2：**   
示例（Promise）:  
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
            web_webview.GeolocationPermissions.getAccessibleGeolocation(this.origin)  
              .then(result => {  
                console.log('getAccessibleGeolocationPromise result: ' + result);  
              }).catch((error : business_error.BusinessError) => {  
              console.log('getAccessibleGeolocationPromise error: ' + JSON.stringify(error));  
            });  
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
  
    
### getStoredGeolocation    
以回调方式异步获取已存储地理位置权限状态的所有源信息。  
 **调用形式：**     
    
- static getStoredGeolocation(): Promise\<Array\<string>>    
起始版本： 9    
- static getStoredGeolocation(callback: AsyncCallback\<Array\<string>>): void    
起始版本： 9  
  
 **系统能力:**  SystemCapability.Web.Webview.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 返回已存储地理位置权限状态的所有源信息。 |  
| Promise<Array<string>> | Promise实例，用于获取已存储地理位置权限状态的所有源信息。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 | Invalid input parameter. |  
    
 **示例代码1：**   
示例（callback）:  
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
      Button('getStoredGeolocation')  
        .onClick(() => {  
          try {  
            web_webview.GeolocationPermissions.getStoredGeolocation((error, origins) => {  
              if (error) {  
                console.log('getStoredGeolocationAsync error: ' + JSON.stringify(error));  
                return;  
              }  
              let origins_str: string = origins.join();  
              console.log('getStoredGeolocationAsync origins: ' + origins_str);  
            });  
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
  
    
 **示例代码2：**   
示例（Promise）:  
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
      Button('getStoredGeolocation')  
        .onClick(() => {  
          try {  
            web_webview.GeolocationPermissions.getStoredGeolocation()  
              .then(origins => {  
                let origins_str: string = origins.join();  
                console.log('getStoredGeolocationPromise origins: ' + origins_str);  
              }).catch((error : business_error.BusinessError) => {  
              console.log('getStoredGeolocationPromise error: ' + JSON.stringify(error));  
            });  
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
  
    
## WebCookieManager    
通过WebCookie可以控制Web组件中的cookie的各种行为，其中每个应用中的所有web组件共享一个WebCookieManager实例。  
 **系统能力:**  SystemCapability.Web.Webview.Core    
### getCookie    
获取指定url对应cookie的值。。  
 **调用形式：**     
- static getCookie(url: string): string  
  
 **系统能力:**  SystemCapability.Web.Webview.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| url | string | true | 要获取的cookie所属的url，建议使用完整的url。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| string | 指定url对应的cookie的值。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 | Invalid input parameter. |  
| 17100002 | Invalid url. |  
    
 **示例代码：**   
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
      Button('getCookie')  
        .onClick(() => {  
          try {  
            let value = web_webview.WebCookieManager.getCookie('https://www.example.com');  
            console.log("value: " + value);  
          } catch (error) {  
            let e:business_error.BusinessError = error as business_error.BusinessError;  
            console.error(`ErrorCode: ${e.code},  Message: ${e.message}`);  
          }  
        })  
      Web({ src: 'www.example.com', controller: this.controller })  
    }  
  }  
}  
    
```    
  
    
### setCookie    
为指定url设置单个cookie的值。  
 **调用形式：**     
- static setCookie(url: string, value: string): void  
  
 **系统能力:**  SystemCapability.Web.Webview.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| url | string | true | 要设置的cookie所属的url，建议使用完整的url。 |  
| value | string | true | 要设置的cookie的值。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 | fetchCookieSync |  
| 17100002 | Invalid url. |  
| 17100005 | Invalid cookie value. |  
    
 **示例代码：**   
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
      Button('setCookie')  
        .onClick(() => {  
          try {  
            web_webview.WebCookieManager.setCookie('https://www.example.com', 'a=b');  
          } catch (error) {  
            let e:business_error.BusinessError = error as business_error.BusinessError;  
            console.error(`ErrorCode: ${e.code},  Message: ${e.message}`);  
          }  
        })  
      Web({ src: 'www.example.com', controller: this.controller })  
    }  
  }  
}  
    
```    
  
    
### saveCookieAsync    
将当前存在内存中的cookie异步保存到磁盘中。  
 **调用形式：**     
    
- static saveCookieAsync(): Promise\<void>    
起始版本： 9    
- static saveCookieAsync(callback: AsyncCallback\<void>): void    
起始版本： 9  
  
 **系统能力:**  SystemCapability.Web.Webview.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | callback回调，用于获取cookie是否成功保存。 |  
| Promise<void> | Promise实例，用于获取cookie是否成功保存。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
    
 **示例代码1：**   
示例（callback）:  
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
      Button('saveCookieAsync')  
        .onClick(() => {  
          try {  
            web_webview.WebCookieManager.saveCookieAsync((error) => {  
              if (error) {  
                console.log("error: " + error);  
              }  
            })  
          } catch (error) {  
            let e:business_error.BusinessError = error as business_error.BusinessError;  
            console.error(`ErrorCode: ${e.code},  Message: ${e.message}`);  
          }  
        })  
      Web({ src: 'www.example.com', controller: this.controller })  
    }  
  }  
}  
    
```    
  
    
 **示例代码2：**   
示例（Promise）:  
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
      Button('saveCookieAsync')  
        .onClick(() => {  
          try {  
            web_webview.WebCookieManager.saveCookieAsync()  
              .then(() => {  
                console.log("saveCookieAsyncCallback success!");  
              })  
              .catch((error:business_error.BusinessError) => {  
                console.error("error: " + error);  
              });  
          } catch (error) {  
            let e:business_error.BusinessError = error as business_error.BusinessError;  
            console.error(`ErrorCode: ${e.code},  Message: ${e.message}`);  
          }  
        })  
      Web({ src: 'www.example.com', controller: this.controller })  
    }  
  }  
}  
    
```    
  
    
### isCookieAllowed    
获取WebCookieManager实例是否拥有发送和接收cookie的权限。  
 **调用形式：**     
- static isCookieAllowed(): boolean  
  
 **系统能力:**  SystemCapability.Web.Webview.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | 是否拥有发送和接收cookie的权限，默认为true。 |  
    
 **示例代码：**   
```ts    
// xxx.ets  
import web_webview from '@ohos.web.webview'  
  
@Entry  
@Component  
struct WebComponent {  
  controller: web_webview.WebviewController = new web_webview.WebviewController();  
  
  build() {  
    Column() {  
      Button('isCookieAllowed')  
        .onClick(() => {  
          let result = web_webview.WebCookieManager.isCookieAllowed();  
          console.log("result: " + result);  
        })  
      Web({ src: 'www.example.com', controller: this.controller })  
    }  
  }  
}  
    
```    
  
    
### putAcceptCookieEnabled    
设置WebCookieManager实例是否拥有发送和接收cookie的权限。  
 **调用形式：**     
- static putAcceptCookieEnabled(accept: boolean): void  
  
 **系统能力:**  SystemCapability.Web.Webview.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| accept | boolean | true | 设置是否拥有发送和接收cookie的权限。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
    
 **示例代码：**   
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
      Button('putAcceptCookieEnabled')  
        .onClick(() => {  
          try {  
            web_webview.WebCookieManager.putAcceptCookieEnabled(false);  
          } catch (error) {  
            let e:business_error.BusinessError = error as business_error.BusinessError;  
            console.error(`ErrorCode: ${e.code},  Message: ${e.message}`);  
          }  
        })  
      Web({ src: 'www.example.com', controller: this.controller })  
    }  
  }  
}  
    
```    
  
    
### isThirdPartyCookieAllowed    
获取WebCookieManager实例是否拥有发送和接收第三方cookie的权限。  
 **调用形式：**     
- static isThirdPartyCookieAllowed(): boolean  
  
 **系统能力:**  SystemCapability.Web.Webview.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | 是否拥有发送和接收第三方cookie的权限，默认为false。 |  
    
 **示例代码：**   
```ts    
// xxx.ets  
import web_webview from '@ohos.web.webview'  
  
@Entry  
@Component  
struct WebComponent {  
  controller: web_webview.WebviewController = new web_webview.WebviewController();  
  
  build() {  
    Column() {  
      Button('isThirdPartyCookieAllowed')  
        .onClick(() => {  
          let result = web_webview.WebCookieManager.isThirdPartyCookieAllowed();  
          console.log("result: " + result);  
        })  
      Web({ src: 'www.example.com', controller: this.controller })  
    }  
  }  
}  
    
```    
  
    
### putAcceptThirdPartyCookieEnabled    
设置WebCookieManager实例是否拥有发送和接收第三方cookie的权限。  
 **调用形式：**     
- static putAcceptThirdPartyCookieEnabled(accept: boolean): void  
  
 **系统能力:**  SystemCapability.Web.Webview.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| accept | boolean | true | 设置是否拥有发送和接收第三方cookie的权限。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
    
 **示例代码：**   
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
      Button('putAcceptThirdPartyCookieEnabled')  
        .onClick(() => {  
          try {  
            web_webview.WebCookieManager.putAcceptThirdPartyCookieEnabled(false);  
          } catch (error) {  
            let e:business_error.BusinessError = error as business_error.BusinessError;  
            console.error(`ErrorCode: ${e.code},  Message: ${e.message}`);  
          }  
        })  
      Web({ src: 'www.example.com', controller: this.controller })  
    }  
  }  
}  
    
```    
  
    
### existCookie    
获取是否存在cookie。  
 **调用形式：**     
- static existCookie(): boolean  
  
 **系统能力:**  SystemCapability.Web.Webview.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | 是否拥有发送和接收第三方cookie的权限。 |  
    
 **示例代码：**   
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
          let result = web_webview.WebCookieManager.existCookie();  
          console.log("result: " + result);  
        })  
      Web({ src: 'www.example.com', controller: this.controller })  
    }  
  }  
}  
    
```    
  
    
### deleteEntireCookie    
清除所有cookie。  
 **调用形式：**     
- static deleteEntireCookie(): void  
  
 **系统能力:**  SystemCapability.Web.Webview.Core    
 **示例代码：**   
```ts    
import web_webview from '@ohos.web.webview'  
  
@Entry  
@Component  
struct WebComponent {  
  controller: web_webview.WebviewController = new web_webview.WebviewController();  
  
  build() {  
    Column() {  
      Button('deleteEntireCookie')  
        .onClick(() => {  
          web_webview.WebCookieManager.deleteEntireCookie();  
        })  
      Web({ src: 'www.example.com', controller: this.controller })  
    }  
  }  
}  
    
```    
  
    
### deleteSessionCookie    
清除所有会话cookie。  
 **调用形式：**     
- static deleteSessionCookie(): void  
  
 **系统能力:**  SystemCapability.Web.Webview.Core    
 **示例代码：**   
```ts    
// xxx.ets  
import web_webview from '@ohos.web.webview'  
  
@Entry  
@Component  
struct WebComponent {  
  controller: web_webview.WebviewController = new web_webview.WebviewController();  
  
  build() {  
    Column() {  
      Button('deleteSessionCookie')  
        .onClick(() => {  
          web_webview.WebCookieManager.deleteSessionCookie();  
        })  
      Web({ src: 'www.example.com', controller: this.controller })  
    }  
  }  
}  
    
```    
  
    
## WebMessageType<sup>(10+)</sup>    
[webMessagePort](#webmessageport)接口所支持的数据类型。    
    
 **系统能力:**  SystemCapability.Web.Webview.Core    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| NOT_SUPPORT | 0 | 不支持的数据类型。 |  
| STRING | 1 | 字符串类型。 |  
| NUMBER | 2 | 数值类型。 |  
| BOOLEAN | 3 | 布尔类型。 |  
| ARRAY_BUFFER | 4 | 原始二进制数据缓冲区。 |  
| ARRAY | 5 | 数组类型。 |  
| ERROR | 6 | 错误类型。 |  
    
## WebMessageExt<sup>(10+)</sup>    
[webMessagePort](#webmessageport)接口接收、发送的的数据对象。  
 **系统能力:**  SystemCapability.Web.Webview.Core    
### getType<sup>(10+)</sup>    
获取数据对象的类型。  
 **调用形式：**     
- getType(): WebMessageType  
  
 **系统能力:**  SystemCapability.Web.Webview.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| WebMessageType | [webMessagePort](#webmessageport)接口所支持的数据类型。 |  
    
### getString<sup>(10+)</sup>    
获取数据对象的字符串类型数据。完整示例代码参考[onMessageEventExt](#onmessageeventext10)。  
 **调用形式：**     
- getString(): string  
  
 **系统能力:**  SystemCapability.Web.Webview.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| string | 返回字符串类型的数据。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 17100014 | The type does not match with the value of the web message. |  
    
### getNumber<sup>(10+)</sup>    
获取数据对象的数值类型数据。完整示例代码参考[onMessageEventExt](#onmessageeventext10)。  
 **调用形式：**     
- getNumber(): number  
  
 **系统能力:**  SystemCapability.Web.Webview.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| number | 返回数值类型的数据。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 17100014 | The type does not match with the value of the web message. |  
    
### getBoolean<sup>(10+)</sup>    
获取数据对象的布尔类型数据。完整示例代码参考[onMessageEventExt](#onmessageeventext10)。  
 **调用形式：**     
- getBoolean(): boolean  
  
 **系统能力:**  SystemCapability.Web.Webview.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | 返回布尔类型的数据。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 17100014 | The type does not match with the value of the web message. |  
    
### getArrayBuffer<sup>(10+)</sup>    
获取数据对象的原始二进制数据。完整示例代码参考[onMessageEventExt](#onmessageeventext10)。  
 **调用形式：**     
- getArrayBuffer(): ArrayBuffer  
  
 **系统能力:**  SystemCapability.Web.Webview.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| ArrayBuffer | 返回原始二进制数据。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 17100014 | The type does not match with the value of the web message. |  
    
### getArray<sup>(10+)</sup>    
获取数据对象的数组类型数据。完整示例代码参考[onMessageEventExt](#onmessageeventext10)。  
 **调用形式：**     
- getArray(): Array\<string | number | boolean>  
  
 **系统能力:**  SystemCapability.Web.Webview.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Array<string | number | boolean> | 返回数组类型的数据。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 17100014 | The type does not match with the value of the web message. |  
    
### getError<sup>(10+)</sup>    
获取数据对象的错误类型数据。完整示例代码参考[onMessageEventExt](#onmessageeventext10)。  
 **调用形式：**     
- getError(): Error  
  
 **系统能力:**  SystemCapability.Web.Webview.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Error | 返回错误对象类型的数据。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 17100014 | The type does not match with the value of the web message. |  
    
### setType<sup>(10+)</sup>    
设置数据对象的类型。  
 **调用形式：**     
- setType(type: WebMessageType): void  
  
 **系统能力:**  SystemCapability.Web.Webview.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| type | WebMessageType | true | [webMessagePort](#webmessageport)接口所支持的数据类型。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 17100014 | The type does not match with the value of the web message. |  
    
### setString<sup>(10+)</sup>    
设置数据对象的字符串类型数据。完整示例代码参考[onMessageEventExt](#onmessageeventext10)。  
 **调用形式：**     
- setString(message: string): void  
  
 **系统能力:**  SystemCapability.Web.Webview.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| message | string | true | 字符串类型数据。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 17100014 | The type does not match with the value of the web message. |  
    
### setNumber<sup>(10+)</sup>    
设置数据对象的数值类型数据。完整示例代码参考[onMessageEventExt](#onmessageeventext10)。  
 **调用形式：**     
- setNumber(message: number): void  
  
 **系统能力:**  SystemCapability.Web.Webview.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| message | number | true | 数值类型数据。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 17100014 | The type does not match with the value of the web message. |  
    
### setBoolean<sup>(10+)</sup>    
设置数据对象的布尔类型数据。完整示例代码参考[onMessageEventExt](#onmessageeventext10)。  
 **调用形式：**     
- setBoolean(message: boolean): void  
  
 **系统能力:**  SystemCapability.Web.Webview.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| message | boolean | true | 布尔类型数据。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 17100014 | The type does not match with the value of the web message. |  
    
### setArrayBuffer<sup>(10+)</sup>    
设置数据对象的原始二进制数据。完整示例代码参考[onMessageEventExt](#onmessageeventext10)。  
 **调用形式：**     
- setArrayBuffer(message: ArrayBuffer): void  
  
 **系统能力:**  SystemCapability.Web.Webview.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| message | ArrayBuffer | true | 原始二进制类型数据。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 17100014 | The type does not match with the value of the web message. |  
    
### setArray<sup>(10+)</sup>    
设置数据对象的数组类型数据。完整示例代码参考[onMessageEventExt](#onmessageeventext10)。  
 **调用形式：**     
- setArray(message: Array\<string | number | boolean>): void  
  
 **系统能力:**  SystemCapability.Web.Webview.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| message | Array<string \| number \| boolean> | true | 数组类型数据。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 17100014 | The type does not match with the value of the web message. |  
    
### setError<sup>(10+)</sup>    
设置数据对象的错误对象类型数据。完整示例代码参考[onMessageEventExt](#onmessageeventext10)。  
 **调用形式：**     
- setError(message: Error): void  
  
 **系统能力:**  SystemCapability.Web.Webview.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| message | Error | true | 错误对象类型数据。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 17100014 | The type does not match with the value of the web message. |  
    
## WebMessage    
用于描述[WebMessagePort](#webmessageport)所支持的数据类型。    
    
| 取值范围 | 说明 |  
| --------| --------|  
| ArrayBuffer | 二进制类型数据。 |  
| string | 字符串类型数据。 |  
    
## WebMessagePort    
通过WebMessagePort可以进行消息的发送以及接收。  
 **系统能力:**  SystemCapability.Web.Webview.Core    
### 属性    
 **系统能力:**  SystemCapability.Web.Webview.Core    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| isExtentionType<sup>(10+)</sup> | boolean | false | false | 创建WebMessagePort时是否指定使用扩展增强接口。 |  
    
### close    
关闭该消息端口。在使用close前，请先使用[createWebMessagePorts](#createwebmessageports)创建消息端口。  
 **调用形式：**     
- close(): void  
  
 **系统能力:**  SystemCapability.Web.Webview.Core    
### postMessageEvent    
发送消息。完整示例代码参考[postMessage](#postmessage)。  
 **调用形式：**     
- postMessageEvent(message: WebMessage): void  
  
 **系统能力:**  SystemCapability.Web.Webview.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| message | WebMessage | true | 要发送的消息。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 17100010 | Can not post message using this port. |  
    
 **示例代码：**   
```ts    
// xxx.ets  
import web_webview from '@ohos.web.webview';  
import business_error from '@ohos.base';  
  
@Entry  
@Component  
struct WebComponent {  
  controller: web_webview.WebviewController = new web_webview.WebviewController();  
  ports: web_webview.WebMessagePort[] = [];  
  
  build() {  
    Column() {  
      Button('postMessageEvent')  
        .onClick(() => {  
          try {  
            this.ports = this.controller.createWebMessagePorts();  
            this.controller.postMessage('__init_port__', [this.ports[0]], '*');  
            this.ports[1].postMessageEvent("post message from ets to html5");  
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
  
    
### onMessageEvent    
注册回调函数，接收HTML侧发送过来的消息。完整示例代码参考[postMessage](#postmessage)。  
 **调用形式：**     
    
- onMessageEvent(callback: (result: WebMessage) => void): void    
起始版本： 9  
  
 **系统能力:**  SystemCapability.Web.Webview.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 接收到的消息。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 17100006 | Can not register message event using this port. |  
    
 **示例代码：**   
```ts    
// xxx.ets  
import web_webview from '@ohos.web.webview';  
import business_error from '@ohos.base';  
  
@Entry  
@Component  
struct WebComponent {  
  controller: web_webview.WebviewController = new web_webview.WebviewController();  
  ports: web_webview.WebMessagePort[] = [];  
  
  build() {  
    Column() {  
      Button('onMessageEvent')  
        .onClick(() => {  
          try {  
            this.ports = this.controller.createWebMessagePorts();  
            this.ports[1].onMessageEvent((msg) => {  
              if (typeof(msg) == "string") {  
                console.log("received string message from html5, string is:" + msg);  
              } else if (typeof(msg) == "object") {  
                if (msg instanceof ArrayBuffer) {  
                  console.log("received arraybuffer from html5, length is:" + msg.byteLength);  
                } else {  
                  console.log("not support");  
                }  
              } else {  
                console.log("not support");  
              }  
            })  
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
  
    
### postMessageEventExt<sup>(10+)</sup>    
发送消息。完整示例代码参考[onMessageEventExt](#onmessageeventext10)。  
 **调用形式：**     
- postMessageEventExt(message: WebMessageExt): void  
  
 **系统能力:**  SystemCapability.Web.Webview.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| message | WebMessageExt | true | 要发送的消息。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 17100010 | Can not post message using this port. |  
    
### onMessageEventExt<sup>(10+)</sup>    
注册回调函数，接收HTML5侧发送过来的消息。  
 **调用形式：**     
    
- onMessageEventExt(callback: (result: WebMessageExt) => void): void    
起始版本： 10  
  
 **系统能力:**  SystemCapability.Web.Webview.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 接收到的消息。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 17100006 | Can not register message event using this port. |  
    
 **示例代码1：**   
```ts    
// xxx.ets  
import web_webview from '@ohos.web.webview';  
import business_error from '@ohos.base';  
  
// 应用与网页互发消息的示例：使用"init_web_messageport"的通道，通过端口0在应用侧接受网页发送的消息，通过端口1在网页侧接受应用发送的消息。  
@Entry  
@Component  
struct WebComponent {  
  controller: web_webview.WebviewController = new web_webview.WebviewController();  
  ports: web_webview.WebMessagePort[] = [];  
  nativePort: web_webview.WebMessagePort | null = null;  
  @State msg1: string = "";  
  @State msg2: string = "";  
  message: web_webview.WebMessageExt = new web_webview.WebMessageExt();  
  
  build() {  
    Column() {  
      Text(this.msg1).fontSize(16)  
      Text(this.msg2).fontSize(16)  
      Button('SendToH5')  
        .onClick(() => {  
          // 使用本侧端口发送消息给HTML5  
          try {  
            console.log("In ArkTS side send true start");  
            if (this.nativePort) {  
              this.message.setString("helloFromEts");  
              this.nativePort.postMessageEventExt(this.message);  
            }  
          }  
          catch (error) {  
            let e: business_error.BusinessError = error as business_error.BusinessError;  
            console.log("In ArkTS side send message catch error:" + e.code + ", msg:" + e.message);  
          }  
        })  
  
      Web({ src: $rawfile('index.html'), controller: this.controller })  
        .onPageEnd(() => {  
          console.log("In ArkTS side message onPageEnd init mesaage channel");  
          // 1. 创建消息端口  
          this.ports = this.controller.createWebMessagePorts(true);  
          // 2. 发送端口1到HTML5  
          this.controller.postMessage("init_web_messageport", [this.ports[1]], "*");  
          // 3. 保存端口0到本地  
          this.nativePort = this.ports[0];  
          // 4. 设置回调函数  
          this.nativePort.onMessageEventExt((result) => {  
            console.log("In ArkTS side got message");  
            try {  
              let type = result.getType();  
              console.log("In ArkTS side getType:" + type);  
              switch (type) {  
                case web_webview.WebMessageType.STRING: {  
                  this.msg1 = "result type:" + typeof (result.getString());  
                  this.msg2 = "result getString:" + ((result.getString()));  
                  break;  
                }  
                case web_webview.WebMessageType.NUMBER: {  
                  this.msg1 = "result type:" + typeof (result.getNumber());  
                  this.msg2 = "result getNumber:" + ((result.getNumber()));  
                  break;  
                }  
                case web_webview.WebMessageType.BOOLEAN: {  
                  this.msg1 = "result type:" + typeof (result.getBoolean());  
                  this.msg2 = "result getBoolean:" + ((result.getBoolean()));  
                  break;  
                }  
                case web_webview.WebMessageType.ARRAY_BUFFER: {  
                  this.msg1 = "result type:" + typeof (result.getArrayBuffer());  
                  this.msg2 = "result getArrayBuffer byteLength:" + ((result.getArrayBuffer().byteLength));  
                  break;  
                }  
                case web_webview.WebMessageType.ARRAY: {  
                  this.msg1 = "result type:" + typeof (result.getArray());  
                  this.msg2 = "result getArray:" + result.getArray();  
                  break;  
                }  
                case web_webview.WebMessageType.ERROR: {  
                  this.msg1 = "result type:" + typeof (result.getError());  
                  this.msg2 = "result getError:" + result.getError();  
                  break;  
                }  
                default: {  
                  this.msg1 = "default break, type:" + type;  
                  break;  
                }  
              }  
            }  
            catch (error) {  
              let e: business_error.BusinessError = error as business_error.BusinessError;  
              console.error(`ErrorCode: ${e.code},  Message: ${e.message}`);  
            }  
          });  
        })  
    }  
  }  
}  
    
```    
  
    
 **示例代码2：**   
加载的html文件。  
```null    
<!--index.html-->  
<!DOCTYPE html>  
<html lang="en-gb">  
<head>  
    <title>WebView MessagePort Demo</title>  
</head>  
  
<body>  
<h1>Html5 Send and Receive Message</h1>  
<h3 id="msg">Receive string:</h3>  
<h3 id="msg2">Receive arraybuffer:</h3>  
<div style="font-size: 10pt; text-align: center;">  
    <input type="button" value="Send String" onclick="postStringToApp();" />  
  
</div>  
</body>  
<script src="index.js"></script>  
</html>  
```  
  
```js  
//index.js  
var h5Port;  
window.addEventListener('message', function(event) {  
    if (event.data == 'init_web_messageport') {  
        if(event.ports[0] != null) {  
            h5Port = event.ports[0]; // 1. 保存从ets侧发送过来的端口  
            h5Port.onmessage = function(event) {  
                console.log("hwd In html got message");  
                // 2. 接收ets侧发送过来的消息.  
                var result = event.data;  
                console.log("In html got message, typeof: ", typeof(result));  
                console.log("In html got message, result: ", (result));  
                if (typeof(result) == "string") {  
                    console.log("In html got message, String: ", result);  
                    document.getElementById("msg").innerHTML  =  "String:" + result;  
                } else if (typeof(result) == "number") {  
                  console.log("In html side got message, number: ", result);  
                    document.getElementById("msg").innerHTML = "Number:" + result;  
                } else if (typeof(result) == "boolean") {  
                    console.log("In html side got message, boolean: ", result);  
                    document.getElementById("msg").innerHTML = "Boolean:" + result;  
                } else if (typeof(result) == "object") {  
                    if (result instanceof ArrayBuffer) {  
                        document.getElementById("msg2").innerHTML  =  "ArrayBuffer:" + result.byteLength;  
                        console.log("In html got message, byteLength: ", result.byteLength);  
                    } else if (result instanceof Error) {  
                        console.log("In html error message, err:" + (result));  
                        console.log("In html error message, typeof err:" + typeof(result));  
                        document.getElementById("msg2").innerHTML  =  "Error:" + result.name + ", msg:" + result.message;  
                    } else if (result instanceof Array) {  
                        console.log("In html got message, Array");  
                        console.log("In html got message, Array length:" + result.length);  
                        console.log("In html got message, Array[0]:" + (result[0]));  
                        console.log("In html got message, typeof Array[0]:" + typeof(result[0]));  
                        document.getElementById("msg2").innerHTML  =  "Array len:" + result.length + ", value:" + result;  
                    } else {  
                        console.log("In html got message, not any instance of support type");  
                        document.getElementById("msg").innerHTML  = "not any instance of support type";  
                    }  
                } else {  
                    console.log("In html got message, not support type");  
                    document.getElementById("msg").innerHTML  = "not support type";  
                }  
            }  
            h5Port.onmessageerror = (event) => {  
                console.error(`hwd In html Error receiving message: ${event}`);  
            };  
        }  
    }  
})  
  
// 使用h5Port往ets侧发送String类型的消息.  
function postStringToApp() {  
    if (h5Port) {  
        console.log("In html send string message");  
        h5Port.postMessage("hello");  
        console.log("In html send string message end");  
    } else {  
        console.error("In html h5port is null, please init first");  
    }  
}  
    
```    
  
    
## HistoryItem    
页面历史记录项。  
 **系统能力:**  SystemCapability.Web.Webview.Core    
### 属性    
 **系统能力:**  SystemCapability.Web.Webview.Core    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| icon | image.PixelMap | false | true | 历史页面图标的PixelMap对象。 |  
| historyUrl | string | false | true | 历史记录项的url地址。 |  
| historyRawUrl | string | false | true | 历史记录项的原始url地址。 |  
| title | string | false | true | 历史记录项的标题。 |  
    
## BackForwardList    
当前Webview的历史信息列表。  
 **系统能力:**  SystemCapability.Web.Webview.Core    
### 属性    
 **系统能力:**  SystemCapability.Web.Webview.Core    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| currentIndex | number | false | true | 当前在页面历史列表中的索引。 |  
| size | number | false | true | 历史列表中索引的数量，最多保存50条，超过时起始记录会被覆盖。 |  
    
### getItemAtIndex    
获取历史列表中指定索引的历史记录项信息。  
 **调用形式：**     
- getItemAtIndex(index: number): HistoryItem  
  
 **系统能力:**  SystemCapability.Web.Webview.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| index | number | true | 指定历史列表中的索引。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| HistoryItem | 历史记录项。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
    
 **示例代码：**   
```ts    
// xxx.ets  
import web_webview from '@ohos.web.webview';  
import image from "@ohos.multimedia.image";  
import business_error from '@ohos.base';  
  
@Entry  
@Component  
struct WebComponent {  
  controller: web_webview.WebviewController = new web_webview.WebviewController();  
  @State icon: image.PixelMap | undefined = undefined;  
  
  build() {  
    Column() {  
      Button('getBackForwardEntries')  
        .onClick(() => {  
          try {  
            let list = this.controller.getBackForwardEntries();  
            let historyItem = list.getItemAtIndex(list.currentIndex);  
            console.log("HistoryItem: " + JSON.stringify(historyItem));  
            this.icon = historyItem.icon;  
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
  
    
## JsMessageType<sup>(10+)</sup>    
[runJavaScirptExt](#runjavascriptext10)接口脚本执行后返回的结果的类型。    
    
 **系统能力:**  SystemCapability.Web.Webview.Core    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| NOT_SUPPORT | 0 | 不支持的数据类型。 |  
| STRING | 1 | 字符串类型。 |  
| NUMBER | 2 | 数值类型。 |  
| BOOLEAN | 3 | 布尔类型。 |  
| ARRAY_BUFFER | 4 | 原始二进制数据缓冲区。 |  
| ARRAY | 5 | 数组类型。 |  
    
## JsMessageExt<sup>(10+)</sup>    
[runJavaScirptExt](#runjavascriptext10)接口执行脚本返回的数据对象。  
 **系统能力:**  SystemCapability.Web.Webview.Core    
### getType<sup>(10+)</sup>    
获取数据对象的类型。。  
 **调用形式：**     
- getType(): JsMessageType  
  
 **系统能力:**  SystemCapability.Web.Webview.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| JsMessageType | [runJavaScirptExt](#runjavascriptext10)接口脚本执行后返回的结果的类型。 |  
    
### getString<sup>(10+)</sup>    
获取数据对象的字符串类型数据。完整示例代码参考[runJavaScriptExt](#runjavascriptext10)。  
 **调用形式：**     
- getString(): string  
  
 **系统能力:**  SystemCapability.Web.Webview.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| string | 返回字符串类型的数据。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 17100014 | The type does not match with the value of the result. |  
    
### getNumber<sup>(10+)</sup>    
获取数据对象的数值类型数据。完整示例代码参考[runJavaScriptExt](#runjavascriptext10)。  
 **调用形式：**     
- getNumber(): number  
  
 **系统能力:**  SystemCapability.Web.Webview.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| number | 返回数值类型的数据。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 17100014 | The type does not match with the value of the result. |  
    
### getBoolean<sup>(10+)</sup>    
获取数据对象的布尔类型数据。完整示例代码参考[runJavaScriptExt](#runjavascriptext10)。  
 **调用形式：**     
- getBoolean(): boolean  
  
 **系统能力:**  SystemCapability.Web.Webview.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | 返回布尔类型的数据。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 17100014 | The type does not match with the value of the result. |  
    
### getArrayBuffer<sup>(10+)</sup>    
获取数据对象的原始二进制数据。完整示例代码参考[runJavaScriptExt](#runjavascriptext10)。  
 **调用形式：**     
- getArrayBuffer(): ArrayBuffer  
  
 **系统能力:**  SystemCapability.Web.Webview.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| ArrayBuffer | 返回原始二进制数据。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 17100014 | The type does not match with the value of the result. |  
    
### getArray<sup>(10+)</sup>    
获取数据对象的数组类型数据。完整示例代码参考[onMessageEventExt](#onmessageeventext10)。  
 **调用形式：**     
- getArray(): Array\<string | number | boolean>  
  
 **系统能力:**  SystemCapability.Web.Webview.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Array<string | number | boolean> | 返回数组类型的数据。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 17100014 | The type does not match with the value of the web message. |  
    
## WebviewController    
通过WebviewController可以控制Web组件各种行为。一个WebviewController对象只能控制一个Web组件，且必须在Web组件和WebviewController绑定后，才能调用WebviewController上的方法（静态方法除外）。  
 **系统能力:**  SystemCapability.Web.Webview.Core    
### initializeWebEngine    
在 Web 组件初始化之前，通过此接口加载 Web 引擎的动态库文件，以提高启动性能。  
 **调用形式：**     
- static initializeWebEngine(): void  
  
 **系统能力:**  SystemCapability.Web.Webview.Core    
 **示例代码：**   
```ts    
// xxx.ts  
import UIAbility from '@ohos.app.ability.UIAbility';  
import web_webview from '@ohos.web.webview';  
import AbilityConstant from '@ohos.app.ability.AbilityConstant';  
import Want from '@ohos.app.ability.Want';  
  
export default class EntryAbility extends UIAbility {  
  onCreate(want: Want, launchParam: AbilityConstant.LaunchParam) {  
    console.log("EntryAbility onCreate")  
    web_webview.WebviewController.initializeWebEngine()  
    console.log("EntryAbility onCreate done")  
  }  
}  
    
```    
  
    
### setHttpDns<sup>(10+)</sup>    
设置Web组件是否使用HTTPDNS解析dns。  
 **调用形式：**     
- static setHttpDns(secureDnsMode: SecureDnsMode, secureDnsConfig: string): void  
  
 **系统能力:**  SystemCapability.Web.Webview.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| secureDnsMode | SecureDnsMode | true | 使用HTTPDNS的模式。 |  
| secureDnsConfig | string | true | HTTPDNS server的配置，必须是https协议并且只允许配置一个server。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
    
 **示例代码：**   
```ts    
// xxx.ts  
import UIAbility from '@ohos.app.ability.UIAbility';  
import web_webview from '@ohos.web.webview';  
import AbilityConstant from '@ohos.app.ability.AbilityConstant';  
import Want from '@ohos.app.ability.Want';  
import business_error from '@ohos.base';  
  
export default class EntryAbility extends UIAbility {  
  onCreate(want: Want, launchParam: AbilityConstant.LaunchParam) {  
    console.log("EntryAbility onCreate")  
    try {  
      web_webview.WebviewController.setHttpDns(web_webview.SecureDnsMode.AUTO, "https://example1.test")  
    } catch (error) {  
      let e: business_error.BusinessError = error as business_error.BusinessError;  
      console.error(`ErrorCode: ${e.code},  Message: ${e.message}`);  
    }  
  
    AppStorage.setOrCreate("abilityWant", want);  
    console.log("EntryAbility onCreate done")  
  }  
}  
    
```    
  
    
### setWebDebuggingAccess    
设置是否启用网页调试功能。详情请参考[Devtools工具](../../web/web-debugging-with-devtools.md)。  
 **调用形式：**     
- static setWebDebuggingAccess(webDebuggingAccess: boolean): void  
  
 **系统能力:**  SystemCapability.Web.Webview.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| webDebuggingAccess | boolean | true | 设置是否启用网页调试功能。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
    
 **示例代码：**   
```ts    
// xxx.ets  
import web_webview from '@ohos.web.webview';  
import business_error from '@ohos.base';  
  
@Entry  
@Component  
struct WebComponent {  
  controller: web_webview.WebviewController = new web_webview.WebviewController();  
  
  aboutToAppear(): void {  
    try {  
      web_webview.WebviewController.setWebDebuggingAccess(true);  
    } catch (error) {  
      let e: business_error.BusinessError = error as business_error.BusinessError;  
      console.error(`ErrorCode: ${e.code},  Message: ${e.message}`);  
    }  
  }  
  
  build() {  
    Column() {  
      Web({ src: 'www.example.com', controller: this.controller })  
    }  
  }  
}  
    
```    
  
    
### accessForward    
当前页面是否可前进，即当前页面是否有前进历史记录。  
 **调用形式：**     
- accessForward(): boolean  
  
 **系统能力:**  SystemCapability.Web.Webview.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | 可以前进返回true，否则返回false。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 17100001 | Init error. The WebviewController must be associated with a Web component. |  
    
 **示例代码：**   
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
      Button('accessForward')  
        .onClick(() => {  
          try {  
            let result = this.controller.accessForward();  
            console.log('result:' + result);  
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
  
    
### accessBackward    
当前页面是否可后退，即当前页面是否有返回历史记录。  
 **调用形式：**     
- accessBackward(): boolean  
  
 **系统能力:**  SystemCapability.Web.Webview.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | 可以后退返回true,否则返回false。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 17100001 | Init error. The WebviewController must be associated with a Web compoent. |  
    
 **示例代码：**   
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
      Button('accessBackward')  
        .onClick(() => {  
          try {  
            let result = this.controller.accessBackward();  
            console.log('result:' + result);  
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
  
    
### accessStep    
当前页面是否可前进或者后退给定的step步。  
 **调用形式：**     
- accessStep(step: number): boolean  
  
 **系统能力:**  SystemCapability.Web.Webview.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| step | number | true | 要跳转的步数，正数代表前进，负数代表后退。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | 页面是否前进或后退 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 17100001 | Init error. The WebviewController must be associated with a Web compoent. |  
    
 **示例代码：**   
```ts    
// xxx.ets  
import web_webview from '@ohos.web.webview';  
import business_error from '@ohos.base';  
  
@Entry  
@Component  
struct WebComponent {  
  controller: web_webview.WebviewController = new web_webview.WebviewController();  
  @State steps: number = 2;  
  
  build() {  
    Column() {  
      Button('accessStep')  
        .onClick(() => {  
          try {  
            let result = this.controller.accessStep(this.steps);  
            console.log('result:' + result);  
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
  
    
### forward    
按照历史栈，前进一个页面。一般结合accessForward一起使用。  
 **调用形式：**     
- forward(): void  
  
 **系统能力:**  SystemCapability.Web.Webview.Core    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 17100001 | Init error. The WebviewController must be associated with a Web compoent. |  
    
 **示例代码：**   
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
      Button('forward')  
        .onClick(() => {  
          try {  
            this.controller.forward();  
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
  
    
### backward    
按照历史栈，后退一个页面。一般结合accessBackward一起使用。  
 **调用形式：**     
- backward(): void  
  
 **系统能力:**  SystemCapability.Web.Webview.Core    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 17100001 | Init error. The WebviewController must be associated with a Web compoent. |  
    
 **示例代码：**   
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
      Button('backward')  
        .onClick(() => {  
          try {  
            this.controller.backward();  
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
  
    
### clearHistory    
删除所有前进后退记录。  
 **调用形式：**     
- clearHistory(): void  
  
 **系统能力:**  SystemCapability.Web.Webview.Core    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 17100001 | Init error. The WebviewController must be associated with a Web compoent. |  
    
 **示例代码：**   
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
      Button('clearHistory')  
        .onClick(() => {  
          try {  
            this.controller.clearHistory();  
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
  
    
### onActive    
调用此接口通知Web组件进入前台激活状态。  
 **调用形式：**     
- onActive(): void  
  
 **系统能力:**  SystemCapability.Web.Webview.Core    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 17100001 | Init error. The WebviewController must be associated with a Web compoent. |  
    
 **示例代码：**   
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
      Button('onActive')  
        .onClick(() => {  
          try {  
            this.controller.onActive();  
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
  
    
### onInactive    
调用此接口通知Web组件进入未激活状态。  
 **调用形式：**     
- onInactive(): void  
  
 **系统能力:**  SystemCapability.Web.Webview.Core    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 17100001 | Init error. The WebviewController must be associated with a Web compoent. |  
    
 **示例代码：**   
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
      Button('onInactive')  
        .onClick(() => {  
          try {  
            this.controller.onInactive();  
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
  
    
### refresh    
调用此接口通知Web组件刷新网页。  
 **调用形式：**     
- refresh(): void  
  
 **系统能力:**  SystemCapability.Web.Webview.Core    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 17100001 | Init error. The WebviewController must be associated with a Web compoent. |  
    
 **示例代码：**   
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
      Button('refresh')  
        .onClick(() => {  
          try {  
            this.controller.refresh();  
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
  
    
### loadData    
加载指定的数据。  
 **调用形式：**     
- loadData(data: string, mimeType: string, encoding: string, baseUrl?: string, historyUrl?: string): void  
  
 **系统能力:**  SystemCapability.Web.Webview.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| data | string | true | 按照"Base64"或者"URL"编码后的一段字符串。 |  
| mimeType | string | true | 媒体类型（MIME）。 |  
| encoding | string | true | 编码类型，具体为"Base64"或者"URL"编码。 |  
| baseUrl | string | false | 指定的一个URL路径（"http"/"https"/"data"协议），并由Web组件赋值给window.origin。 |  
| historyUrl | string | false | 用作历史记录所使用的URL。非空时，历史记录以此URL进行管理。当baseUrl为空时，此属性无效。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 17100001 | Init error. The WebviewController must be associated with a Web compoent. |  
| 17100002 | Invalid url. |  
    
 **示例代码：**   
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
      Button('loadData')  
        .onClick(() => {  
          try {  
            this.controller.loadData(  
              "<html><body bgcolor=\"white\">Source:source</body></html>",  
              "text/html",  
              "UTF-8"  
            );  
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
  
    
### loadUrl    
加载指定的URL。  
 **调用形式：**     
- loadUrl(url: string | Resource, headers?: Array\<WebHeader>): void  
  
 **系统能力:**  SystemCapability.Web.Webview.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| url | string | true | 需要加载的 URL。 |  
| headers | Array<WebHeader> | false | URL的附加HTTP请求头。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 17100001 | Init error. The WebviewController must be associated with a Web compoent. |  
| 17100002 | Invalid url. |  
| 17100003 | Invalid resource path or file type. |  
    
 **示例代码：**   
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
      Button('loadUrl')  
        .onClick(() => {  
          try {  
            // 需要加载的URL是string类型。  
            this.controller.loadUrl('www.example.com');  
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
  
    
### getHitTest    
获取当前被点击区域的元素类型。  
 **调用形式：**     
- getHitTest(): WebHitTestType  
  
 **系统能力:**  SystemCapability.Web.Webview.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| WebHitTestType | 被点击区域的元素类型。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 17100001 | Init error. The WebviewController must be associated with a Web compoent. |  
    
 **示例代码：**   
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
      Button('getHitTest')  
        .onClick(() => {  
          try {  
            let hitTestType = this.controller.getHitTest();  
            console.log("hitTestType: " + hitTestType);  
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
  
    
### storeWebArchive    
以回调方式异步保存当前页面。  
 **调用形式：**     
    
- storeWebArchive(baseName: string, autoName: boolean): Promise\<string>    
起始版本： 9    
- storeWebArchive(baseName: string, autoName: boolean, callback: AsyncCallback\<string>): void    
起始版本： 9  
  
 **系统能力:**  SystemCapability.Web.Webview.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| baseName | string | true | 文件存储路径，该值不能为空。 |  
| autoName | boolean | true | 决定是否自动生成文件名。 如果为false，则将baseName作为文件存储路径。 如果为true，则假定baseName是一个目录，将根据当前页的Url自动生成文件名。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 返回文件存储路径，保存网页失败会返回null。 |  
| Promise<string> | Promise实例，保存成功返回文件路径，保存失败返回null。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 17100001 | Init error. The WebviewController must be associated with a Web compoent. |  
| 17100003 | Invalid resource path or file type. |  
    
 **示例代码1：**   
示例（callback）:  
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
      Button('storeWebArchive')  
        .onClick(() => {  
          try {  
            this.controller.storeWebArchive("/data/storage/el2/base/", true, (error, filename) => {  
              if (error) {  
                console.info(`save web archive error: ` + JSON.stringify(error))  
                return;  
              }  
              if (filename != null) {  
                console.info(`save web archive success: ${filename}`)  
              }  
            });  
          } catch (error) {  
            let e:business_error.BusinessError = error as business_error.BusinessError;  
            console.error(`ErrorCode: ${e.code},  Message: ${e.message}`);  
          }  
        })  
      Web({ src: 'www.example.com', controller: this.controller })  
    }  
  }  
}  
    
```    
  
    
 **示例代码2：**   
示例（Promise）:  
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
      Button('storeWebArchive')  
        .onClick(() => {  
          try {  
            this.controller.storeWebArchive("/data/storage/el2/base/", true)  
              .then(filename => {  
                if (filename != null) {  
                  console.info(`save web archive success: ${filename}`)  
                }  
              })  
              .catch((error:business_error.BusinessError) => {  
                console.log('error: ' + JSON.stringify(error));  
              })  
          } catch (error) {  
            let e:business_error.BusinessError = error as business_error.BusinessError;  
            console.error(`ErrorCode: ${e.code},  Message: ${e.message}`);  
          }  
        })  
      Web({ src: 'www.example.com', controller: this.controller })  
    }  
  }  
}  
    
```    
  
    
### zoom    
调整当前网页的缩放比例，[zoomAccess](../arkui-ts/ts-basic-components-web.md#zoomaccess)需为true。  
 **调用形式：**     
- zoom(factor: number): void  
  
 **系统能力:**  SystemCapability.Web.Webview.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| factor | number | true | 基于当前网页所需调整的相对缩放比例，入参要求大于0，当入参为1时为默认加载网页的缩放比例，入参小于1为缩小，入参大于1为放大。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 17100001 | Init error. The WebviewController must be associated with a Web compoent. |  
| 17100004 | Function not enable. |  
    
 **示例代码：**   
```ts    
// xxx.ets  
import web_webview from '@ohos.web.webview';  
import business_error from '@ohos.base';  
  
@Entry  
@Component  
struct WebComponent {  
  controller: web_webview.WebviewController = new web_webview.WebviewController();  
  @State factor: number = 1;  
  
  build() {  
    Column() {  
      Button('zoom')  
        .onClick(() => {  
          try {  
            this.controller.zoom(this.factor);  
          } catch (error) {  
            let e: business_error.BusinessError = error as business_error.BusinessError;  
            console.error(`ErrorCode: ${e.code},  Message: ${e.message}`);  
          }  
        })  
      Web({ src: 'www.example.com', controller: this.controller })  
        .zoomAccess(true)  
    }  
  }  
}  
    
```    
  
    
### zoomIn    
调用此接口将当前网页进行放大，比例为20%。  
 **调用形式：**     
- zoomIn(): void  
  
 **系统能力:**  SystemCapability.Web.Webview.Core    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 17100001 | Init error. The WebviewController must be associated with a Web compoent. |  
| 17100004 | Function not enable. |  
    
 **示例代码：**   
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
      Button('zoomIn')  
        .onClick(() => {  
          try {  
            this.controller.zoomIn();  
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
  
    
### zoomOut    
调用此接口将当前网页进行缩小，比例为20%。  
 **调用形式：**     
- zoomOut(): void  
  
 **系统能力:**  SystemCapability.Web.Webview.Core    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 17100001 | Init error. The WebviewController must be associated with a Web compoent. |  
| 17100004 | Function not enable. |  
    
 **示例代码：**   
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
      Button('zoomOut')  
        .onClick(() => {  
          try {  
            this.controller.zoomOut();  
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
  
    
### getHitTestValue    
获取当前被点击区域的元素信息。  
 **调用形式：**     
- getHitTestValue(): HitTestValue  
  
 **系统能力:**  SystemCapability.Web.Webview.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| HitTestValue | 点击区域的元素信息。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 17100001 | Init error. The WebviewController must be associated with a Web compoent. |  
    
 **示例代码：**   
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
      Button('getHitTestValue')  
        .onClick(() => {  
          try {  
            let hitValue = this.controller.getHitTestValue();  
            console.log("hitType: " + hitValue.type);  
            console.log("extra: " + hitValue.extra);  
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
  
    
### getWebId    
获取当前Web组件的索引值，用于多个Web组件的管理。  
 **调用形式：**     
- getWebId(): number  
  
 **系统能力:**  SystemCapability.Web.Webview.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| number | 当前Web组件的索引值。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 17100001 | Init error. The WebviewController must be associated with a Web compoent. |  
    
 **示例代码：**   
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
      Button('getWebId')  
        .onClick(() => {  
          try {  
            let id = this.controller.getWebId();  
            console.log("id: " + id);  
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
  
    
### getUserAgent    
获取当前默认用户代理。  
 **调用形式：**     
- getUserAgent(): string  
  
 **系统能力:**  SystemCapability.Web.Webview.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| string | 默认用户代理。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 17100001 | Init error. The WebviewController must be associated with a Web compoent. |  
    
 **示例代码：**   
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
      Button('getUserAgent')  
        .onClick(() => {  
          try {  
            let userAgent = this.controller.getUserAgent();  
            console.log("userAgent: " + userAgent);  
          } catch (error) {  
            let e:business_error.BusinessError = error as business_error.BusinessError;  
            console.error(`ErrorCode: ${e.code},  Message: ${e.message}`);  
          }  
        })  
      Web({ src: 'www.example.com', controller: this.controller })  
    }  
  }  
}  
    
```    
  
    
### getTitle    
获取当前网页的标题。  
 **调用形式：**     
- getTitle(): string  
  
 **系统能力:**  SystemCapability.Web.Webview.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| string | 当前网页的标题。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 17100001 | Init error. The WebviewController must be associated with a Web compoent. |  
    
 **示例代码：**   
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
      Button('getTitle')  
        .onClick(() => {  
          try {  
            let title = this.controller.getTitle();  
            console.log("title: " + title);  
          } catch (error) {  
            let e:business_error.BusinessError = error as business_error.BusinessError;  
            console.error(`ErrorCode: ${e.code},  Message: ${e.message}`);  
          }  
        })  
      Web({ src: 'www.example.com', controller: this.controller })  
    }  
  }  
}  
    
```    
  
    
### getPageHeight    
获取当前网页的页面高度。  
 **调用形式：**     
- getPageHeight(): number  
  
 **系统能力:**  SystemCapability.Web.Webview.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| number | 当前网页的页面高度。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 17100001 | Init error. The WebviewController must be associated with a Web compoent. |  
    
 **示例代码：**   
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
      Button('getPageHeight')  
        .onClick(() => {  
          try {  
            let pageHeight = this.controller.getPageHeight();  
            console.log("pageHeight : " + pageHeight);  
          } catch (error) {  
            let e:business_error.BusinessError = error as business_error.BusinessError;  
            console.error(`ErrorCode: ${e.code},  Message: ${e.message}`);  
          }  
        })  
      Web({ src: 'www.example.com', controller: this.controller })  
    }  
  }  
}  
    
```    
  
    
### backOrForward    
按照历史栈，前进或者后退指定步长的页面，当历史栈中不存在对应步长的页面时，不会进行页面跳转。前进或者后退页面时，直接使用已加载过的网页，无需重新加载网页。  
 **调用形式：**     
- backOrForward(step: number): void  
  
 **系统能力:**  SystemCapability.Web.Webview.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| step | number | true | 需要前进或后退的步长。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 17100001 | Init error. The WebviewController must be associated with a Web compoent. |  
    
 **示例代码：**   
```ts    
// xxx.ets  
import web_webview from '@ohos.web.webview';  
import business_error from '@ohos.base';  
  
@Entry  
@Component  
struct WebComponent {  
  controller: web_webview.WebviewController = new web_webview.WebviewController();  
  @State step: number = -2;  
  
  build() {  
    Column() {  
      Button('backOrForward')  
        .onClick(() => {  
          try {  
            this.controller.backOrForward(this.step);  
          } catch (error) {  
            let e:business_error.BusinessError = error as business_error.BusinessError;  
            console.error(`ErrorCode: ${e.code},  Message: ${e.message}`);  
          }  
        })  
      Web({ src: 'www.example.com', controller: this.controller })  
    }  
  }  
}  
    
```    
  
    
### requestFocus    
使当前web页面获取焦点。  
 **调用形式：**     
- requestFocus(): void  
  
 **系统能力:**  SystemCapability.Web.Webview.Core    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 17100001 | Init error. The WebviewController must be associated with a Web compoent. |  
    
 **示例代码：**   
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
      Button('requestFocus')  
        .onClick(() => {  
          try {  
            this.controller.requestFocus();  
          } catch (error) {  
            let e: business_error.BusinessError = error as business_error.BusinessError;  
            console.error(`ErrorCode: ${e.code},  Message: ${e.message}`);  
          }  
        });  
      Web({ src: 'www.example.com', controller: this.controller })  
    }  
  }  
}  
    
```    
  
    
### createWebMessagePorts    
创建Web消息端口。完整示例代码参考[onMessageEventExt](#onmessageeventext10)。  
 **调用形式：**     
- createWebMessagePorts(isExtentionType?: boolean): Array\<WebMessagePort>  
  
 **系统能力:**  SystemCapability.Web.Webview.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| isExtentionType | boolean | false | 是否使用扩展增强接口，默认false不使用。 从API version 10开始，该接口支持此参数。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Array<WebMessagePort> | web消息端口列表。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 17100001 | Init error. The WebviewController must be associated with a Web compoent. |  
    
 **示例代码：**   
```ts    
// xxx.ets  
import web_webview from '@ohos.web.webview';  
import business_error from '@ohos.base';  
  
@Entry  
@Component  
struct WebComponent {  
  controller: web_webview.WebviewController = new web_webview.WebviewController();  
  ports: web_webview.WebMessagePort[] = [];  
  
  build() {  
    Column() {  
      Button('createWebMessagePorts')  
        .onClick(() => {  
          try {  
            this.ports = this.controller.createWebMessagePorts();  
            console.log("createWebMessagePorts size:" + this.ports.length)  
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
  
    
### createWebMessagePorts<sup>(10+)</sup>    
创建Web消息端口。完整示例代码参考[onMessageEventExt](#onmessageeventext10)。  
 **调用形式：**     
- createWebMessagePorts(isExtentionType?: boolean): Array\<WebMessagePort>  
  
 **系统能力:**  SystemCapability.Web.Webview.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| isExtentionType | boolean | false | 是否使用扩展增强接口，默认false不使用。 从API version 10开始，该接口支持此参数。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Array<WebMessagePort> | web消息端口列表。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 17100001 | Init error. The WebviewController must be associated with a Web compoent. |  
    
 **示例代码：**   
```ts    
// xxx.ets  
import web_webview from '@ohos.web.webview';  
import business_error from '@ohos.base';  
  
@Entry  
@Component  
struct WebComponent {  
  controller: web_webview.WebviewController = new web_webview.WebviewController();  
  ports: web_webview.WebMessagePort[] = [];  
  
  build() {  
    Column() {  
      Button('createWebMessagePorts')  
        .onClick(() => {  
          try {  
            this.ports = this.controller.createWebMessagePorts();  
            console.log("createWebMessagePorts size:" + this.ports.length)  
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
  
    
### postMessage    
发送Web消息端口到HTML。  
 **调用形式：**     
- postMessage(name: string, ports: Array\<WebMessagePort>, uri: string): void  
  
 **系统能力:**  SystemCapability.Web.Webview.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| name | string | true | 要发送的消息名称。 |  
| ports | Array<WebMessagePort> | true | 要发送的消息端口。 |  
| uri | string | true | 接收该消息的URI。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 17100001 | Init error. The WebviewController must be associated with a Web compoent. |  
    
 **示例代码1：**   
```ts    
// xxx.ets  
import web_webview from '@ohos.web.webview';  
import business_error from '@ohos.base';  
  
@Entry  
@Component  
struct WebComponent {  
  controller: web_webview.WebviewController = new web_webview.WebviewController();  
  ports: web_webview.WebMessagePort[] = [];  
  @State sendFromEts: string = 'Send this message from ets to HTML';  
  @State receivedFromHtml: string = 'Display received message send from HTML';  
  
  build() {  
    Column() {  
      // 展示接收到的来自HTML的内容  
      Text(this.receivedFromHtml)  
      // 输入框的内容发送到html  
      TextInput({ placeholder: 'Send this message from ets to HTML' })  
        .onChange((value: string) => {  
          this.sendFromEts = value;  
        })  
  
      Button('postMessage')  
        .onClick(() => {  
          try {  
            // 1、创建两个消息端口。  
            this.ports = this.controller.createWebMessagePorts();  
            // 2、在应用侧的消息端口(如端口1)上注册回调事件。  
            this.ports[1].onMessageEvent((result: web_webview.WebMessage) => {  
              let msg = 'Got msg from HTML:';  
              if (typeof(result) == "string") {  
                console.log("received string message from html5, string is:" + result);  
                msg = msg + result;  
              } else if (typeof(result) == "object") {  
                if (result instanceof ArrayBuffer) {  
                  console.log("received arraybuffer from html5, length is:" + result.byteLength);  
                  msg = msg + "lenght is " + result.byteLength;  
                } else {  
                  console.log("not support");  
                }  
              } else {  
                console.log("not support");  
              }  
              this.receivedFromHtml = msg;  
            })  
            // 3、将另一个消息端口(如端口0)发送到HTML侧，由HTML侧保存并使用。  
            this.controller.postMessage('__init_port__', [this.ports[0]], '*');  
          } catch (error) {  
            let e: business_error.BusinessError = error as business_error.BusinessError;  
            console.error(`ErrorCode: ${e.code},  Message: ${e.message}`);  
          }  
        })  
  
      // 4、使用应用侧的端口给另一个已经发送到html的端口发送消息。  
      Button('SendDataToHTML')  
        .onClick(() => {  
          try {  
            if (this.ports  this.ports[1]) {  
              this.ports[1].postMessageEvent(this.sendFromEts);  
            } else {  
              console.error(`ports is null, Please initialize first`);  
            }  
          } catch (error) {  
            let e: business_error.BusinessError = error as business_error.BusinessError;  
            console.error(`ErrorCode: ${e.code},  Message: ${e.message}`);  
          }  
        })  
      Web({ src: $rawfile('index.html'), controller: this.controller })  
    }  
  }  
}  
    
```    
  
    
 **示例代码2：**   
加载的html文件。  
```null    
<!--index.html-->  
<!DOCTYPE html>  
<html>  
<head>  
    <meta name="viewport" content="width=device-width, initial-scale=1.0">  
    <title>WebView Message Port Demo</title>  
</head>  
  
  <body>  
    <h1>WebView Message Port Demo</h1>  
    <div>  
        <input type="button" value="SendToEts" onclick="PostMsgToEts(msgFromJS.value);"/>  
  
        <input id="msgFromJS" type="text" value="send this message from HTML to ets"/>  
  
    </div>  
    <p class="output">display received message send from ets  
  </body>  
  <script src="xxx.js"></script>  
</html>  
```  
  
```js  
//xxx.js  
var h5Port;  
var output = document.querySelector('.output');  
window.addEventListener('message', function (event) {  
    if (event.data == '__init_port__') {  
        if (event.ports[0] != null) {  
            h5Port = event.ports[0]; // 1. 保存从ets侧发送过来的端口  
            h5Port.onmessage = function (event) {  
              // 2. 接收ets侧发送过来的消息.  
              var msg = 'Got message from ets:';  
              var result = event.data;  
              if (typeof(result) == "string") {  
                console.log("received string message from html5, string is:" + result);  
                msg = msg + result;  
              } else if (typeof(result) == "object") {  
                if (result instanceof ArrayBuffer) {  
                  console.log("received arraybuffer from html5, length is:" + result.byteLength);  
                  msg = msg + "lenght is " + result.byteLength;  
                } else {  
                  console.log("not support");  
                }  
              } else {  
                console.log("not support");  
              }  
              output.innerHTML = msg;  
            }  
        }  
    }  
})  
  
// 3. 使用h5Port往ets侧发送消息.  
function PostMsgToEts(data) {  
    if (h5Port) {  
      h5Port.postMessage(data);  
    } else {  
      console.error("h5Port is null, Please initialize first");  
    }  
}  
    
```    
  
    
### stop    
停止页面加载。  
 **调用形式：**     
- stop(): void  
  
 **系统能力:**  SystemCapability.Web.Webview.Core    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 17100001 | Init error. The WebviewController must be associated with a Web compoent. |  
    
 **示例代码：**   
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
      Button('stop')  
        .onClick(() => {  
          try {  
            this.controller.stop();  
          } catch (error) {  
            let e:business_error.BusinessError = error as business_error.BusinessError;  
            console.error(`ErrorCode: ${e.code},  Message: ${e.message}`);  
          }  
        });  
      Web({ src: 'www.example.com', controller: this.controller })  
    }  
  }  
}  
    
```    
  
    
### registerJavaScriptProxy    
注入JavaScript对象到window对象中，并在window对象中调用该对象的方法。注册后，须调用[refresh](#refresh)接口生效。  
 **调用形式：**     
- registerJavaScriptProxy(object: object, name: string, methodList: Array\<string>): void  
  
 **系统能力:**  SystemCapability.Web.Webview.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| object | object | true | 参与注册的应用侧JavaScript对象。只能声明方法，不能声明属性 。其中方法的参数和返回类型只能为string，number，boolean |  
| name | string | true | 注册对象的名称，与window中调用的对象名一致。注册后window对象可以通过此名字访问应用侧JavaScript对象。 |  
| methodList | Array<string> | true | 参与注册的应用侧JavaScript对象的方法。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 17100001 | Init error. The WebviewController must be associated with a Web compoent. |  
    
 **示例代码1：**   
```ts    
// xxx.ets  
import web_webview from '@ohos.web.webview';  
import business_error from '@ohos.base';  
  
class testObj {  
  constructor() {  
  }  
  
  test(): string {  
    console.log('ArkUI Web Component');  
    return "ArkUI Web Component";  
  }  
  
  toString(): void {  
    console.log('Web Component toString');  
  }  
}  
  
class webObj {  
  constructor() {  
  }  
  
  webTest(): string {  
    console.log('Web test');  
    return "Web test";  
  }  
  
  webString(): void {  
    console.log('Web test toString');  
  }  
}  
  
@Entry  
@Component  
struct Index {  
  controller: web_webview.WebviewController = new web_webview.WebviewController();  
  @State testObjtest: testObj = new testObj();  
  @State webTestObj: webObj = new webObj();  
  build() {  
    Column() {  
      Button('refresh')  
        .onClick(() => {  
          try {  
            this.controller.refresh();  
          } catch (error) {  
            let e: business_error.BusinessError = error as business_error.BusinessError;  
            console.error(`ErrorCode: ${e.code},  Message: ${e.message}`);  
          }  
        })  
      Button('Register JavaScript To Window')  
        .onClick(() => {  
          try {  
            this.controller.registerJavaScriptProxy(this.testObjtest, "objName", ["test", "toString"]);  
            this.controller.registerJavaScriptProxy(this.webTestObj, "objTestName", ["webTest", "webString"]);  
          } catch (error) {  
            let e: business_error.BusinessError = error as business_error.BusinessError;  
            console.error(`ErrorCode: ${e.code},  Message: ${e.message}`);  
          }  
        })  
      Web({ src: $rawfile('index.html'), controller: this.controller })  
        .javaScriptAccess(true)  
    }  
  }  
}  
    
```    
  
    
 **示例代码2：**   
加载的html文件。  
```ts    
<!-- index.html --><!DOCTYPE html><html>    <meta charset="utf-8">    <body>      <button type="button" onclick="htmlTest()">Click Me!</button>      <p id="demo">      <p id="webDemo">    </body>    <script type="text/javascript">    function htmlTest() {      // This function call expects to return "ArkUI Web Component"      let str=objName.test();      document.getElementById("demo").innerHTML=str;      console.log('objName.test result:'+ str)  
      // This function call expects to return "Web test"      let webStr = objTestName.webTest();      document.getElementById("webDemo").innerHTML=webStr;      console.log('objTestName.webTest result:'+ webStr)    }</script></html>    
```    
  
    
### deleteJavaScriptRegister    
删除通过registerJavaScriptProxy注册到window上的指定name的应用侧JavaScript对象。删除后，须调用[refresh](#refresh)接口。  
 **调用形式：**     
- deleteJavaScriptRegister(name: string): void  
  
 **系统能力:**  SystemCapability.Web.Webview.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| name | string | true | 注册对象的名称，可在网页侧JavaScript中通过此名称调用应用侧JavaScript对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 17100001 | Init error. The WebviewController must be associated with a Web compoent. |  
| 17100008 | Cannot delete JavaScriptProxy. |  
    
 **示例代码：**   
```ts    
// xxx.ets  
import web_webview from '@ohos.web.webview';  
import business_error from '@ohos.base';  
  
class testObj {  
  constructor() {  
  }  
  
  test(): string {  
    return "ArkUI Web Component";  
  }  
  
  toString(): void {  
    console.log('Web Component toString');  
  }  
}  
  
@Entry  
@Component  
struct WebComponent {  
  controller: web_webview.WebviewController = new web_webview.WebviewController();  
  @State testObjtest: testObj = new testObj();  
  @State name: string = 'objName';  
  build() {  
    Column() {  
      Button('refresh')  
        .onClick(() => {  
          try {  
            this.controller.refresh();  
          } catch (error) {  
            let e: business_error.BusinessError = error as business_error.BusinessError;  
            console.error(`ErrorCode: ${e.code},  Message: ${e.message}`);  
          }  
        })  
      Button('Register JavaScript To Window')  
        .onClick(() => {  
          try {  
            this.controller.registerJavaScriptProxy(this.testObjtest, this.name, ["test", "toString"]);  
          } catch (error) {  
            let e: business_error.BusinessError = error as business_error.BusinessError;  
            console.error(`ErrorCode: ${e.code},  Message: ${e.message}`);  
          }  
        })  
      Button('deleteJavaScriptRegister')  
        .onClick(() => {  
          try {  
            this.controller.deleteJavaScriptRegister(this.name);  
          } catch (error) {  
            let e: business_error.BusinessError = error as business_error.BusinessError;  
            console.error(`ErrorCode: ${e.code},  Message: ${e.message}`);  
          }  
        })  
      Web({ src: $rawfile('index.html'), controller: this.controller })  
        .javaScriptAccess(true)  
    }  
  }  
}  
    
```    
  
    
### searchAllAsync    
异步查找网页中所有匹配关键字'searchString'的内容并高亮，结果通过[onSearchResultReceive](../arkui-ts/ts-basic-components-web.md#onsearchresultreceive9)异步返回。  
 **调用形式：**     
- searchAllAsync(searchString: string): void  
  
 **系统能力:**  SystemCapability.Web.Webview.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| searchString | string | true | 查找的关键字。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 17100001 | Init error. The WebviewController must be associated with a Web compoent. |  
    
 **示例代码1：**   
```ts    
// xxx.ets  
import web_webview from '@ohos.web.webview';  
import business_error from '@ohos.base';  
  
@Entry  
@Component  
struct WebComponent {  
  controller: web_webview.WebviewController = new web_webview.WebviewController();  
  @State searchString: string = "Hello World";  
  
  build() {  
    Column() {  
      Button('searchString')  
        .onClick(() => {  
          try {  
            this.controller.searchAllAsync(this.searchString);  
          } catch (error) {  
            let e: business_error.BusinessError = error as business_error.BusinessError;  
            console.error(`ErrorCode: ${e.code},  Message: ${e.message}`);  
          }  
        })  
      Web({ src: $rawfile('index.html'), controller: this.controller })  
        .onSearchResultReceive(ret => {  
          if (ret) {  
            console.log("on search result receive:" + "[cur]" + ret.activeMatchOrdinal +  
              "[total]" + ret.numberOfMatches + "[isDone]" + ret.isDoneCounting);  
          }  
        })  
    }  
  }  
}  
    
```    
  
    
 **示例代码2：**   
加载的html文件。  
```null    
<!-- index.html --><!DOCTYPE html><html>  <body>    Hello World Highlight Hello World  </body></html>    
```    
  
    
### clearMatches    
清除所有通过[searchAllAsync](#searchallasync)匹配到的高亮字符查找结果。  
 **调用形式：**     
- clearMatches(): void  
  
 **系统能力:**  SystemCapability.Web.Webview.Core    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 17100001 | Init error. The WebviewController must be associated with a Web compoent. |  
    
 **示例代码：**   
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
      Button('clearMatches')  
        .onClick(() => {  
          try {  
            this.controller.clearMatches();  
          } catch (error) {  
            let e: business_error.BusinessError = error as business_error.BusinessError;  
            console.error(`ErrorCode: ${e.code},  Message: ${e.message}`);  
          }  
        })  
      Web({ src: $rawfile('index.html'), controller: this.controller })  
    }  
  }  
}  
    
```    
  
    
### searchNext    
滚动到下一个匹配的查找结果并高亮。  
 **调用形式：**     
- searchNext(forward: boolean): void  
  
 **系统能力:**  SystemCapability.Web.Webview.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| forward | boolean | true | 从前向后或者逆向查找。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 17100001 | Init error. The WebviewController must be associated with a Web compoent. |  
    
 **示例代码：**   
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
      Button('searchNext')  
        .onClick(() => {  
          try {  
            this.controller.searchNext(true);  
          } catch (error) {  
            let e: business_error.BusinessError = error as business_error.BusinessError;  
            console.error(`ErrorCode: ${e.code},  Message: ${e.message}`);  
          }  
        })  
      Web({ src: $rawfile('index.html'), controller: this.controller })  
    }  
  }  
}  
    
```    
  
    
### clearSslCache    
清除Web组件记录的SSL证书错误事件对应的用户操作行为。  
 **调用形式：**     
- clearSslCache(): void  
  
 **系统能力:**  SystemCapability.Web.Webview.Core    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 17100001 | Init error. The WebviewController must be associated with a Web compoent. |  
    
 **示例代码：**   
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
      Button('clearSslCache')  
        .onClick(() => {  
          try {  
            this.controller.clearSslCache();  
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
  
    
### clearClientAuthenticationCache    
清除Web组件记录的客户端证书请求事件对应的用户操作行为。  
 **调用形式：**     
- clearClientAuthenticationCache(): void  
  
 **系统能力:**  SystemCapability.Web.Webview.Core    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 17100001 | Init error. The WebviewController must be associated with a Web compoent. |  
    
 **示例代码：**   
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
      Button('clearClientAuthenticationCache')  
        .onClick(() => {  
          try {  
            this.controller.clearClientAuthenticationCache();  
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
  
    
### runJavaScript    
异步执行JavaScript脚本，并通过回调方式返回脚本执行的结果。runJavaScript需要在loadUrl完成后，比如onPageEnd中调用。  
 **调用形式：**     
    
- runJavaScript(script: string): Promise\<string>    
起始版本： 9    
- runJavaScript(script: string, callback: AsyncCallback\<string>): void    
起始版本： 9  
  
 **系统能力:**  SystemCapability.Web.Webview.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| script | string | true | JavaScript脚本。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调执行JavaScript脚本结果。JavaScript脚本若执行失败或无返回值时，返回null。 |  
| Promise<string> | Promise实例，返回脚本执行的结果，执行失败返回null。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 17100001 | Init error. The WebviewController must be associated with a Web compoent. |  
    
 **示例代码1：**   
示例（callback）:  
```ts    
import web_webview from '@ohos.web.webview';  
import business_error from '@ohos.base';  
  
@Entry  
@Component  
struct WebComponent {  
  controller: web_webview.WebviewController = new web_webview.WebviewController();  
  @State webResult: string = ''  
  
  build() {  
    Column() {  
      Text(this.webResult).fontSize(20)  
      Web({ src: $rawfile('index.html'), controller: this.controller })  
        .javaScriptAccess(true)  
        .onPageEnd(e => {  
          try {  
            this.controller.runJavaScript(  
              'test()',  
              (error, result) => {  
                if (error) {  
                  console.info(`run JavaScript error: ` + JSON.stringify(error))  
                  return;  
                }  
                if (result) {  
                  this.webResult = result  
                  console.info(`The test() return value is: ${result}`)  
                }  
              });  
            if (e) {  
              console.info('url: ', e.url);  
            }  
          } catch (error) {  
            let e: business_error.BusinessError = error as business_error.BusinessError;  
            console.error(`ErrorCode: ${e.code},  Message: ${e.message}`);  
          }  
        })  
    }  
  }  
}  
    
```    
  
    
 **示例代码2：**   
加载的html文件。  
```null    
<!-- index.html --><!DOCTYPE html><html>  <meta charset="utf-8">  <body>      Hello world!  </body>  <script type="text/javascript">  function test() {      console.log('Ark WebComponent')      return "This value is from index.html"  }  </script></html>    
```    
  
    
 **示例代码3：**   
示例（Promise）:  
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
      Web({ src: $rawfile('index.html'), controller: this.controller })  
        .javaScriptAccess(true)  
        .onPageEnd(e => {  
          try {  
            this.controller.runJavaScript('test()')  
              .then((result) => {  
                console.log('result: ' + result);  
              })  
              .catch((error: business_error.BusinessError) => {  
                console.error("error: " + error);  
              })  
            if (e) {  
              console.info('url: ', e.url);  
            }  
          } catch (error) {  
            let e: business_error.BusinessError = error as business_error.BusinessError;  
            console.error(`ErrorCode: ${e.code},  Message: ${e.message}`);  
          }  
        })  
    }  
  }  
}  
    
```    
  
    
 **示例代码4：**   
加载的html文件。  
```null    
<!-- index.html --><!DOCTYPE html><html>  <meta charset="utf-8">  <body>      Hello world!  </body>  <script type="text/javascript">  function test() {      console.log('Ark WebComponent')      return "This value is from index.html"  }  </script></html>    
```    
  
    
### runJavaScriptExt<sup>(10+)</sup>    
异步执行JavaScript脚本，并通过回调方式返回脚本执行的结果。runJavaScriptExt需要在loadUrl完成后，比如onPageEnd中调用。  
 **调用形式：**     
    
- runJavaScriptExt(script: string): Promise\<JsMessageExt>    
起始版本： 10    
- runJavaScriptExt(script: string, callback: AsyncCallback\<JsMessageExt>): void    
起始版本： 10  
  
 **系统能力:**  SystemCapability.Web.Webview.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| script | string | true | JavaScript脚本。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 回调执行JavaScript脚本结果。 |  
| Promise<JsMessageExt> | Promise实例，返回脚本执行的结果。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 17100001 | Init error. The WebviewController must be associated with a Web compoent. |  
    
 **示例代码1：**   
示例（callback）:  
```ts    
import web_webview from '@ohos.web.webview';  
import business_error from '@ohos.base';  
  
@Entry  
@Component  
struct WebComponent {  
  controller: web_webview.WebviewController = new web_webview.WebviewController();  
  @State msg1: string = ''  
  @State msg2: string = ''  
  
  build() {  
    Column() {  
      Text(this.msg1).fontSize(20)  
      Text(this.msg2).fontSize(20)  
      Web({ src: $rawfile('index.html'), controller: this.controller })  
        .javaScriptAccess(true)  
        .onPageEnd(e => {  
          try {  
            this.controller.runJavaScriptExt(  
              'test()',  
              (error, result) => {  
                if (error) {  
                  console.info(`run JavaScript error: ` + JSON.stringify(error))  
                  return;  
                }  
                if (result) {  
                  try {  
                    let type = result.getType();  
                    switch (type) {  
                      case web_webview.JsMessageType.STRING: {  
                        this.msg1 = "result type:" + typeof (result.getString());  
                        this.msg2 = "result getString:" + ((result.getString()));  
                        break;  
                      }  
                      case web_webview.JsMessageType.NUMBER: {  
                        this.msg1 = "result type:" + typeof (result.getNumber());  
                        this.msg2 = "result getNumber:" + ((result.getNumber()));  
                        break;  
                      }  
                      case web_webview.JsMessageType.BOOLEAN: {  
                        this.msg1 = "result type:" + typeof (result.getBoolean());  
                        this.msg2 = "result getBoolean:" + ((result.getBoolean()));  
                        break;  
                      }  
                      case web_webview.JsMessageType.ARRAY_BUFFER: {  
                        this.msg1 = "result type:" + typeof (result.getArrayBuffer());  
                        this.msg2 = "result getArrayBuffer byteLength:" + ((result.getArrayBuffer().byteLength));  
                        break;  
                      }  
                      case web_webview.JsMessageType.ARRAY: {  
                        this.msg1 = "result type:" + typeof (result.getArray());  
                        this.msg2 = "result getArray:" + result.getArray();  
                        break;  
                      }  
                      default: {  
                        this.msg1 = "default break, type:" + type;  
                        break;  
                      }  
                    }  
                  }  
                  catch (resError) {  
                    let e: business_error.BusinessError = resError as business_error.BusinessError;  
                    console.error(`ErrorCode: ${e.code},  Message: ${e.message}`);  
                  }  
                }  
              });  
            if (e) {  
              console.info('url: ', e.url);  
            }  
          } catch (error) {  
            let e: business_error.BusinessError = error as business_error.BusinessError;  
            console.error(`ErrorCode: ${e.code},  Message: ${e.message}`);  
          }  
        })  
    }  
  }  
}  
    
```    
  
    
 **示例代码2：**   
加载的html文件。  
```null    
<!-- index.html --><!DOCTYPE html><html lang="en-gb"><body><h1>run JavaScript Ext demo</h1></body><script type="text/javascript">function test() {  return "hello, world";}</script></html>    
```    
  
    
 **示例代码3：**   
示例（Promise）:  
```ts    
// xxx.ets  
import web_webview from '@ohos.web.webview';  
import business_error from '@ohos.base';  
  
@Entry  
@Component  
struct WebComponent {  
  controller: web_webview.WebviewController = new web_webview.WebviewController();  
  @State webResult: string = '';  
  @State msg1: string = ''  
  @State msg2: string = ''  
  
  build() {  
    Column() {  
      Text(this.webResult).fontSize(20)  
      Text(this.msg1).fontSize(20)  
      Text(this.msg2).fontSize(20)  
      Web({ src: $rawfile('index.html'), controller: this.controller })  
        .javaScriptAccess(true)  
        .onPageEnd(() => {  
          this.controller.runJavaScriptExt('test()')  
            .then((result) => {  
              try {  
                let type = result.getType();  
                switch (type) {  
                  case web_webview.JsMessageType.STRING: {  
                    this.msg1 = "result type:" + typeof (result.getString());  
                    this.msg2 = "result getString:" + ((result.getString()));  
                    break;  
                  }  
                  case web_webview.JsMessageType.NUMBER: {  
                    this.msg1 = "result type:" + typeof (result.getNumber());  
                    this.msg2 = "result getNumber:" + ((result.getNumber()));  
                    break;  
                  }  
                  case web_webview.JsMessageType.BOOLEAN: {  
                    this.msg1 = "result type:" + typeof (result.getBoolean());  
                    this.msg2 = "result getBoolean:" + ((result.getBoolean()));  
                    break;  
                  }  
                  case web_webview.JsMessageType.ARRAY_BUFFER: {  
                    this.msg1 = "result type:" + typeof (result.getArrayBuffer());  
                    this.msg2 = "result getArrayBuffer byteLength:" + ((result.getArrayBuffer().byteLength));  
                    break;  
                  }  
                  case web_webview.JsMessageType.ARRAY: {  
                    this.msg1 = "result type:" + typeof (result.getArray());  
                    this.msg2 = "result getArray:" + result.getArray();  
                    break;  
                  }  
                  default: {  
                    this.msg1 = "default break, type:" + type;  
                    break;  
                  }  
                }  
              }  
              catch (resError) {  
                let e: business_error.BusinessError = resError as business_error.BusinessError;  
                console.error(`ErrorCode: ${e.code},  Message: ${e.message}`);  
              }  
            })  
            .catch((error: business_error.BusinessError) => {  
              console.error("error: " + error);  
            })  
        })  
    }  
  }  
}  
    
```    
  
    
 **示例代码4：**   
加载的html文件。  
```null    
<!-- index.html --><!DOCTYPE html><html lang="en-gb"><body><h1>run JavaScript Ext demo</h1></body><script type="text/javascript">function test() {  return "hello, world";}</script></html>    
```    
  
    
### getUrl    
获取当前页面的url地址。  
 **调用形式：**     
- getUrl(): string  
  
 **系统能力:**  SystemCapability.Web.Webview.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| string | 当前页面的url地址。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 17100001 | Init error. The WebviewController must be associated with a Web compoent. |  
    
 **示例代码：**   
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
      Button('getUrl')  
        .onClick(() => {  
          try {  
            let url = this.controller.getUrl();  
            console.log("url: " + url);  
          } catch (error) {  
            let e:business_error.BusinessError = error as business_error.BusinessError;  
            console.error(`ErrorCode: ${e.code},  Message: ${e.message}`);  
          }  
        })  
      Web({ src: 'www.example.com', controller: this.controller })  
    }  
  }  
}  
    
```    
  
    
### pageUp    
将Webview的内容向上滚动半个视框大小或者跳转到页面最顶部，通过top入参控制。  
 **调用形式：**     
- pageUp(top: boolean): void  
  
 **系统能力:**  SystemCapability.Web.Webview.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| top | boolean | true | 是否跳转到页面最顶部，设置为false时将页面内容向上滚动半个视框大小，设置为true时跳转到页面最顶部。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 17100001 | Init error. The WebviewController must be associated with a Web compoent. |  
    
 **示例代码：**   
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
      Button('pageUp')  
        .onClick(() => {  
          try {  
            this.controller.pageUp(false);  
          } catch (error) {  
            let e:business_error.BusinessError = error as business_error.BusinessError;  
            console.error(`ErrorCode: ${e.code},  Message: ${e.message}`);  
          }  
        })  
      Web({ src: 'www.example.com', controller: this.controller })  
    }  
  }  
}  
    
```    
  
    
### pageDown    
将Webview的内容向下滚动半个视框大小或者跳转到页面最底部，通过bottom入参控制。  
 **调用形式：**     
- pageDown(bottom: boolean): void  
  
 **系统能力:**  SystemCapability.Web.Webview.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| bottom | boolean | true | 是否跳转到页面最底部，设置为false时将页面内容向下滚动半个视框大小，设置为true时跳转到页面最底部。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 17100001 | Init error. The WebviewController must be associated with a Web compoent. |  
    
 **示例代码：**   
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
      Button('pageDown')  
        .onClick(() => {  
          try {  
            this.controller.pageDown(false);  
          } catch (error) {  
            let e:business_error.BusinessError = error as business_error.BusinessError;  
            console.error(`ErrorCode: ${e.code},  Message: ${e.message}`);  
          }  
        })  
      Web({ src: 'www.example.com', controller: this.controller })  
    }  
  }  
}  
    
```    
  
    
### getOriginalUrl    
获取当前页面的原始url地址。  
 **调用形式：**     
- getOriginalUrl(): string  
  
 **系统能力:**  SystemCapability.Web.Webview.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| string | 当前页面的原始url地址。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 17100001 | Init error. The WebviewController must be associated with a Web compoent. |  
    
 **示例代码：**   
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
      Button('getOrgUrl')  
        .onClick(() => {  
          try {  
            let url = this.controller.getOriginalUrl();  
            console.log("original url: " + url);  
          } catch (error) {  
            let e:business_error.BusinessError = error as business_error.BusinessError;  
            console.error(`ErrorCode: ${e.code},  Message: ${e.message}`);  
          }  
        })  
      Web({ src: 'www.example.com', controller: this.controller })  
    }  
  }  
}  
    
```    
  
    
### getFavicon    
获取页面的favicon图标。  
 **调用形式：**     
- getFavicon(): image.PixelMap  
  
 **系统能力:**  SystemCapability.Web.Webview.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| image.PixelMap | 页面favicon图标的PixelMap对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 17100001 | Init error. The WebviewController must be associated with a Web compoent. |  
    
 **示例代码：**   
```ts    
// xxx.ets  
import web_webview from '@ohos.web.webview';  
import image from "@ohos.multimedia.image";  
import business_error from '@ohos.base';  
  
@Entry  
@Component  
struct WebComponent {  
  controller: web_webview.WebviewController = new web_webview.WebviewController();  
  @State pixelmap: image.PixelMap | undefined = undefined;  
  
  build() {  
    Column() {  
      Button('getFavicon')  
        .onClick(() => {  
          try {  
            this.pixelmap = this.controller.getFavicon();  
          } catch (error) {  
            let e:business_error.BusinessError = error as business_error.BusinessError;  
            console.error(`ErrorCode: ${e.code},  Message: ${e.message}`);  
          }  
        })  
      Web({ src: 'www.example.com', controller: this.controller })  
    }  
  }  
}  
    
```    
  
    
### setNetworkAvailable    
onLine属性。  
 **调用形式：**     
- setNetworkAvailable(enable: boolean): void  
  
 **系统能力:**  SystemCapability.Web.Webview.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| enable | boolean | true | 是否使能window.navigator.onLine。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 17100001 | Init error. The WebviewController must be associated with a Web compoent. |  
    
 **示例代码1：**   
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
      Button('setNetworkAvailable')  
        .onClick(() => {  
          try {  
            this.controller.setNetworkAvailable(true);  
          } catch (error) {  
            let e:business_error.BusinessError = error as business_error.BusinessError;  
            console.error(`ErrorCode: ${e.code},  Message: ${e.message}`);  
          }  
        })  
      Web({ src: $rawfile('index.html'), controller: this.controller })  
    }  
  }  
}  
    
```    
  
    
 **示例代码2：**   
加载的html文件。  
```ts    
<!-- index.html --><!DOCTYPE html><html><body><h1>online 属性</h1><p id="demo"><button onclick="func()">click</button><script>    let online = navigator.onLine;    document.getElementById("demo").innerHTML = "浏览器在线：" + online;  
    function func(){      var online = navigator.onLine;      document.getElementById("demo").innerHTML = "浏览器在线：" + online;    }</script></body></html>    
```    
  
    
### hasImage    
异步查找当前页面是否存在图像。  
 **调用形式：**     
    
- hasImage(): Promise\<boolean>    
起始版本： 9    
- hasImage(callback: AsyncCallback\<boolean>): void    
起始版本： 9  
  
 **系统能力:**  SystemCapability.Web.Webview.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 返回查找页面是否存在图像。 |  
| Promise<boolean> | Promise实例，返回查找页面是否存在图像。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 17100001 | Init error. The WebviewController must be associated with a Web compoent. |  
    
 **示例代码1：**   
示例（callback）:  
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
      Button('hasImageCb')  
        .onClick(() => {  
          try {  
            this.controller.hasImage((error, data) => {  
              if (error) {  
                console.info(`hasImage error: ` + JSON.stringify(error))  
                return;  
              }  
              console.info("hasImage: " + data);  
            });  
          } catch (error) {  
            let e:business_error.BusinessError = error as business_error.BusinessError;  
            console.error(`ErrorCode: ${e.code},  Message: ${e.message}`);  
          }  
        })  
      Web({ src: 'www.example.com', controller: this.controller })  
    }  
  }  
}  
    
```    
  
    
 **示例代码2：**   
示例（Promise）:  
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
      Button('hasImagePm')  
        .onClick(() => {  
          try {  
            this.controller.hasImage().then((data) => {  
              console.info('hasImage: ' + data);  
            })  
            .catch((error:business_error.BusinessError) => {  
              console.error("error: " + error);  
            })  
          } catch (error) {  
            let e:business_error.BusinessError = error as business_error.BusinessError;  
            console.error(`ErrorCode: ${e.code},  Message: ${e.message}`);  
          }  
        })  
      Web({ src: 'www.example.com', controller: this.controller })  
    }  
  }  
}  
    
```    
  
    
### getBackForwardEntries    
获取当前Webview的历史信息列表。  
 **调用形式：**     
- getBackForwardEntries(): BackForwardList  
  
 **系统能力:**  SystemCapability.Web.Webview.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| BackForwardList | 当前Webview的历史信息列表。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 17100001 | Init error. The WebviewController must be associated with a Web compoent. |  
    
 **示例代码：**   
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
      Button('getBackForwardEntries')  
        .onClick(() => {  
          try {  
            let list = this.controller.getBackForwardEntries()  
          } catch (error) {  
            let e:business_error.BusinessError = error as business_error.BusinessError;  
            console.error(`ErrorCode: ${e.code},  Message: ${e.message}`);  
          }  
        })  
      Web({ src: 'www.example.com', controller: this.controller })  
    }  
  }  
}  
    
```    
  
    
### removeCache    
清除应用中的资源缓存文件，此方法将会清除同一应用中所有webview的缓存文件。  
 **调用形式：**     
- removeCache(clearRom: boolean): void  
  
 **系统能力:**  SystemCapability.Web.Webview.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| clearRom | boolean | true | 设置为true时同时清除rom和ram中的缓存，设置为false时只清除ram中的缓存。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 17100001 | Init error. The WebviewController must be associated with a Web compoent. |  
    
 **示例代码：**   
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
      Button('removeCache')  
        .onClick(() => {  
          try {  
            this.controller.removeCache(false);  
          } catch (error) {  
            let e:business_error.BusinessError = error as business_error.BusinessError;  
            console.error(`ErrorCode: ${e.code},  Message: ${e.message}`);  
          }  
        })  
      Web({ src: 'www.example.com', controller: this.controller })  
    }  
  }  
}  
    
```    
  
    
### scrollTo    
将页面滚动到指定的绝对位置。  
 **调用形式：**     
- scrollTo(x: number, y: number): void  
  
 **系统能力:**  SystemCapability.Web.Webview.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| x | number | true | 绝对位置的水平坐标，当传入数值为负数时，按照传入0处理。 |  
| y | number | true | 绝对位置的垂直坐标，当传入数值为负数时，按照传入0处理。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 17100001 | Init error. The WebviewController must be associated with a Web compoent. |  
    
 **示例代码1：**   
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
      Button('scrollTo')  
        .onClick(() => {  
          try {  
            this.controller.scrollTo(50, 50);  
          } catch (error) {  
            let e:business_error.BusinessError = error as business_error.BusinessError;  
            console.error(`ErrorCode: ${e.code},  Message: ${e.message}`);  
          }  
        })  
      Web({ src: $rawfile('index.html'), controller: this.controller })  
    }  
  }  
}  
    
```    
  
    
 **示例代码2：**   
加载的html文件。  
```ts    
<!--index.html-->  
<!DOCTYPE html>  
<html>  
<head>  
    <title>Demo</title>  
    <style>  
        body {  
            width:3000px;  
            height:3000px;  
            padding-right:170px;  
            padding-left:170px;  
            border:5px solid blueviolet  
        }  
    </style>  
</head>  
<body>  
Scroll Test  
</body>  
</html>  
    
```    
  
    
### scrollBy    
将页面滚动指定的偏移量。  
 **调用形式：**     
- scrollBy(deltaX: number, deltaY: number): void  
  
 **系统能力:**  SystemCapability.Web.Webview.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| deltaX | number | true | 水平偏移量，其中水平向右为正方向。 |  
| deltaY | number | true | 垂直偏移量，其中垂直向下为正方向。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 17100001 | Init error. The WebviewController must be associated with a Web compoent. |  
    
 **示例代码1：**   
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
      Button('scrollBy')  
        .onClick(() => {  
          try {  
            this.controller.scrollBy(50, 50);  
          } catch (error) {  
            let e:business_error.BusinessError = error as business_error.BusinessError;  
            console.error(`ErrorCode: ${e.code},  Message: ${e.message}`);  
          }  
        })  
      Web({ src: $rawfile('index.html'), controller: this.controller })  
    }  
  }  
}  
    
```    
  
    
 **示例代码2：**   
加载的html文件。  
```null    
<!--index.html-->  
<!DOCTYPE html>  
<html>  
<head>  
    <title>Demo</title>  
    <style>  
        body {  
            width:3000px;  
            height:3000px;  
            padding-right:170px;  
            padding-left:170px;  
            border:5px solid blueviolet  
        }  
    </style>  
</head>  
<body>  
Scroll Test  
</body>  
</html>  
    
```    
  
    
### slideScroll    
按照指定速度模拟对页面的轻扫滚动动作。  
 **调用形式：**     
- slideScroll(vx: number, vy: number): void  
  
 **系统能力:**  SystemCapability.Web.Webview.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| vx | number | true | 轻扫滚动的水平速度分量，其中水平向右为速度正方向。 |  
| vy | number | true | 轻扫滚动的垂直速度分量，其中垂直向下为速度正方向。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 17100001 | Init error. The WebviewController must be associated with a Web compoent. |  
    
 **示例代码1：**   
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
      Button('slideScroll')  
        .onClick(() => {  
          try {  
            this.controller.slideScroll(500, 500);  
          } catch (error) {  
            let e:business_error.BusinessError = error as business_error.BusinessError;  
            console.error(`ErrorCode: ${e.code},  Message: ${e.message}`);   
          }  
        })  
      Web({ src: $rawfile('index.html'), controller: this.controller })  
    }  
  }  
}  
    
```    
  
    
 **示例代码2：**   
加载的html文件。  
```null    
<!--index.html-->  
<!DOCTYPE html>  
<html>  
<head>  
    <title>Demo</title>  
    <style>  
        body {  
            width:3000px;  
            height:3000px;  
            padding-right:170px;  
            padding-left:170px;  
            border:5px solid blueviolet  
        }  
    </style>  
</head>  
<body>  
Scroll Test  
</body>  
</html>  
    
```    
  
    
### serializeWebState    
将当前Webview的页面状态历史记录信息序列化。  
 **调用形式：**     
- serializeWebState(): Uint8Array  
  
 **系统能力:**  SystemCapability.Web.Webview.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Uint8Array | 当前Webview的页面状态历史记录序列化后的数据。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 17100001 | Init error. The WebviewController must be associated with a Web compoent. |  
    
 **示例代码1：**   
1.对文件的操作需要导入文件管理模块，详情请参考[文件管理](./js-apis-file-fs.md)。  
```ts    
// xxx.ets  
import web_webview from '@ohos.web.webview';  
import fs from '@ohos.file.fs';  
import business_error from '@ohos.base';  
  
@Entry  
@Component  
struct WebComponent {  
  controller: web_webview.WebviewController = new web_webview.WebviewController();  
  
  build() {  
    Column() {  
      Button('serializeWebState')  
        .onClick(() => {  
          try {  
            let state = this.controller.serializeWebState();  
            let path:string | undefined = AppStorage.get("cacheDir");  
            if (path) {  
              path += '/WebState';  
              // 以同步方法打开文件。  
              let file = fs.openSync(path, fs.OpenMode.READ_WRITE | fs.OpenMode.CREATE);  
              fs.writeSync(file.fd, state.buffer);  
              fs.closeSync(file.fd);  
            }  
          } catch (error) {  
            let e:business_error.BusinessError = error as business_error.BusinessError;  
            console.error(`ErrorCode: ${e.code},  Message: ${e.message}`);  
          }  
        })  
      Web({ src: 'www.example.com', controller: this.controller })  
    }  
  }  
}  
    
```    
  
    
 **示例代码2：**   
2.修改EntryAbility.ts。获取应用缓存文件路径。  
```ts    
// xxx.ts  
import UIAbility from '@ohos.app.ability.UIAbility';  
import AbilityConstant from '@ohos.app.ability.AbilityConstant';  
import Want from '@ohos.app.ability.Want';  
  
export default class EntryAbility extends UIAbility {  
    onCreate(want: Want, launchParam: AbilityConstant.LaunchParam) {  
        // 通过在AppStorage对象上绑定cacheDir，可以实现UIAbility组件与Page之间的数据同步。  
        AppStorage.setOrCreate("cacheDir", this.context.cacheDir);  
    }  
}  
    
```    
  
    
### restoreWebState    
当前Webview从序列化数据中恢复页面状态历史记录。  
 **调用形式：**     
- restoreWebState(state: Uint8Array): void  
  
 **系统能力:**  SystemCapability.Web.Webview.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| state | Uint8Array | true | 页面状态历史记录序列化数据。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 17100001 | Init error. The WebviewController must be associated with a Web compoent. |  
    
 **示例代码1：**   
1.对文件的操作需要导入文件管理模块，详情请参考[文件管理](./js-apis-file-fs.md)。  
```ts    
// xxx.ets  
import web_webview from '@ohos.web.webview';  
import fs from '@ohos.file.fs';  
import business_error from '@ohos.base';  
  
@Entry  
@Component  
struct WebComponent {  
  controller: web_webview.WebviewController = new web_webview.WebviewController();  
  
  build() {  
    Column() {  
      Button('RestoreWebState')  
        .onClick(() => {  
          try {  
            let path:string | undefined = AppStorage.get("cacheDir");  
            if (path) {  
              path += '/WebState';  
              // 以同步方法打开文件。  
              let file = fs.openSync(path, fs.OpenMode.READ_WRITE);  
              let stat = fs.statSync(path);  
              let size = stat.size;  
              let buf = new ArrayBuffer(size);  
              fs.read(file.fd, buf, (err, readLen) => {  
                if (err) {  
                  console.info("mkdir failed with error message: " + err.message + ", error code: " + err.code);  
                } else {  
                  console.info("read file data succeed");  
                  this.controller.restoreWebState(new Uint8Array(buf.slice(0, readLen)));  
                  fs.closeSync(file);  
                }  
              });  
            }  
          } catch (error) {  
            let e:business_error.BusinessError = error as business_error.BusinessError;  
            console.error(`ErrorCode: ${e.code},  Message: ${e.message}`);  
          }  
        })  
      Web({ src: 'www.example.com', controller: this.controller })  
    }  
  }  
}  
    
```    
  
    
 **示例代码2：**   
2.修改EntryAbility.ts。获取应用缓存文件路径。  
```ts    
// xxx.ts  
import UIAbility from '@ohos.app.ability.UIAbility';  
import AbilityConstant from '@ohos.app.ability.AbilityConstant';  
import Want from '@ohos.app.ability.Want';  
  
export default class EntryAbility extends UIAbility {  
    onCreate(want: Want, launchParam: AbilityConstant.LaunchParam) {  
        // 通过在AppStorage对象上绑定cacheDir，可以实现UIAbility组件与Page之间的数据同步。  
        AppStorage.setOrCreate("cacheDir", this.context.cacheDir);  
    }  
}  
    
```    
  
    
### customizeSchemes    
配置Web自定义协议请求的权限。建议在任何Web组件初始化之前进行调用。  
 **调用形式：**     
- static customizeSchemes(schemes: Array\<WebCustomScheme>): void  
  
 **系统能力:**  SystemCapability.Web.Webview.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| schemes | Array<WebCustomScheme> | true | 自定义协议配置，最多支持同时配置10个自定义协议。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
    
 **示例代码：**   
```ts    
// xxx.ets  
import web_webview from '@ohos.web.webview';  
import business_error from '@ohos.base';  
  
@Entry  
@Component  
struct WebComponent {  
  controller: web_webview.WebviewController = new web_webview.WebviewController();  
  responseweb: WebResourceResponse = new WebResourceResponse()  
  scheme1: web_webview.WebCustomScheme = {schemeName: "name1", isSupportCORS: true, isSupportFetch: true}  
  scheme2: web_webview.WebCustomScheme = {schemeName: "name2", isSupportCORS: true, isSupportFetch: true}  
  scheme3: web_webview.WebCustomScheme = {schemeName: "name3", isSupportCORS: true, isSupportFetch: true}  
  
  aboutToAppear():void {  
    try {  
      web_webview.WebviewController.customizeSchemes([this.scheme1, this.scheme2, this.scheme3])  
    } catch(error) {  
      let e:business_error.BusinessError = error as business_error.BusinessError;  
      console.error(`ErrorCode: ${e.code},  Message: ${e.message}`);  
    }  
  }  
  
  build() {  
    Column() {  
      Web({ src: 'www.example.com', controller: this.controller })  
        .onInterceptRequest((event) => {  
          if (event) {  
            console.log('url:' + event.request.getRequestUrl())  
          }  
          return this.responseweb  
        })  
    }  
  }  
}  
    
```    
  
    
### getCertificate<sup>(10+)</sup>    
获取当前网站的证书信息。使用web组件加载https网站，会进行SSL证书校验，该接口会通过异步返回当前网站的X509格式证书（X509Cert证书类型定义见[X509Cert](./js-apis-cert.md#x509cert)定义），便于开发者展示网站证书信息。  
 **调用形式：**     
    
- getCertificate(): Promise\<Array\<cert.X509Cert>>    
起始版本： 10    
- getCertificate(callback: AsyncCallback\<Array\<cert.X509Cert>>): void    
起始版本： 10  
  
 **系统能力:**  SystemCapability.Web.Webview.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 通过AsyncCallback异步返回当前网站的X509格式证书。 |  
| Promise<Array<cert.X509Cert>> | Promise实例，用于获取当前加载的https网站的X509格式证书数组。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 17100001 | Init error. The WebviewController must be associated with a Web compoent. |  
| 401 |  |  
    
 **示例代码1：**   
示例（Promise）:  
```ts    
// xxx.ets  
import web_webview from '@ohos.web.webview';  
import business_error from '@ohos.base';  
import cert from '@ohos.security.cert';  
  
function Uint8ArrayToString(dataArray:Uint8Array) {  
  let dataString = ''  
  for (let i = 0; i < dataArray.length; i++) {  
    dataString += String.fromCharCode(dataArray[i])  
  }  
  return dataString  
}  
  
function ParseX509CertInfo(x509CertArray:Array<cert.X509Cert>) {  
  let res: string = 'getCertificate success: len = ' + x509CertArray.length;  
  for (let i = 0; i < x509CertArray.length; i++) {  
    res += ', index = ' + i + ', issuer name = '  
    + Uint8ArrayToString(x509CertArray[i].getIssuerName().data) + ', subject name = '  
    + Uint8ArrayToString(x509CertArray[i].getSubjectName().data) + ', valid start = '  
    + x509CertArray[i].getNotBeforeTime()  
    + ', valid end = ' + x509CertArray[i].getNotAfterTime()  
  }  
  return res  
}  
  
@Entry  
@Component  
struct Index {  
  // outputStr在UI界面显示调试信息  
  @State outputStr: string = ''  
  webviewCtl: web_webview.WebviewController = new web_webview.WebviewController();  
  
  build() {  
    Row() {  
      Column() {  
        List({space: 20, initialIndex: 0}) {  
          ListItem() {  
            Button() {  
              Text('load bad ssl')  
                .fontSize(10)  
                .fontWeight(FontWeight.Bold)  
            }  
            .type(ButtonType.Capsule)  
            .onClick(() => {  
              // 加载一个过期的证书网站，查看获取到的证书信息  
              this.webviewCtl.loadUrl('https://expired.badssl.com')  
            })  
            .height(50)  
          }  
  
          ListItem() {  
            Button() {  
              Text('load example')  
                .fontSize(10)  
                .fontWeight(FontWeight.Bold)  
            }  
            .type(ButtonType.Capsule)  
            .onClick(() => {  
              // 加载一个https网站，查看网站的证书信息  
              this.webviewCtl.loadUrl('https://www.example.com')  
            })  
            .height(50)  
          }  
  
          ListItem() {  
            Button() {  
              Text('getCertificate Promise')  
                .fontSize(10)  
                .fontWeight(FontWeight.Bold)  
            }  
            .type(ButtonType.Capsule)  
            .onClick(() => {  
              try {  
                this.webviewCtl.getCertificate().then((x509CertArray:Array<cert.X509Cert>) => {  
                  this.outputStr = ParseX509CertInfo(x509CertArray);  
                })  
              } catch (error) {  
                let e:business_error.BusinessError = error as business_error.BusinessError;  
                this.outputStr = 'getCertificate failed: ' + e.code + ", errMsg: " + e.message;  
              }  
            })  
            .height(50)  
          }  
  
          ListItem() {  
            Button() {  
              Text('getCertificate AsyncCallback')  
                .fontSize(10)  
                .fontWeight(FontWeight.Bold)  
            }  
            .type(ButtonType.Capsule)  
            .onClick(() => {  
              try {  
                this.webviewCtl.getCertificate((error:business_error.BusinessError, x509CertArray:Array<cert.X509Cert>) => {  
                  if (error) {  
                    this.outputStr = 'getCertificate failed: ' + error.code + ", errMsg: " + error.message;  
                  } else {  
                    this.outputStr = ParseX509CertInfo(x509CertArray);  
                  }  
                })  
              } catch (error) {  
                let e:business_error.BusinessError = error as business_error.BusinessError;  
                this.outputStr = 'getCertificate failed: ' + e.code + ", errMsg: " + e.message;  
              }  
            })  
            .height(50)  
          }  
        }  
        .listDirection(Axis.Horizontal)  
        .height('10%')  
  
        Text(this.outputStr)  
          .width('100%')  
          .fontSize(10)  
  
        Web({ src: 'https://www.example.com', controller: this.webviewCtl })  
          .fileAccess(true)  
          .javaScriptAccess(true)  
          .domStorageAccess(true)  
          .onlineImageAccess(true)  
          .onPageEnd((e) => {  
            if(e) {  
              this.outputStr = 'onPageEnd : url = ' + e.url  
            }  
          })  
          .onSslErrorEventReceive((e) => {  
            // 忽略ssl证书错误，便于测试一些证书过期的网站，如：https://expired.badssl.com  
            e.handler.handleConfirm()  
          })  
          .width('100%')  
          .height('70%')  
      }  
      .height('100%')  
    }  
  }  
}  
    
```    
  
    
 **示例代码2：**   
示例（callback）:  
```ts    
// xxx.ets  
import web_webview from '@ohos.web.webview';  
import business_error from '@ohos.base';  
import cert from '@ohos.security.cert';  
  
function Uint8ArrayToString(dataArray:Uint8Array) {  
  let dataString = ''  
  for (let i = 0; i < dataArray.length; i++) {  
    dataString += String.fromCharCode(dataArray[i])  
  }  
  return dataString  
}  
  
function ParseX509CertInfo(x509CertArray:Array<cert.X509Cert>) {  
  let res: string = 'getCertificate success: len = ' + x509CertArray.length;  
  for (let i = 0; i < x509CertArray.length; i++) {  
    res += ', index = ' + i + ', issuer name = '  
    + Uint8ArrayToString(x509CertArray[i].getIssuerName().data) + ', subject name = '  
    + Uint8ArrayToString(x509CertArray[i].getSubjectName().data) + ', valid start = '  
    + x509CertArray[i].getNotBeforeTime()  
    + ', valid end = ' + x509CertArray[i].getNotAfterTime()  
  }  
  return res  
}  
  
@Entry  
@Component  
struct Index {  
  // outputStr在UI界面显示调试信息  
  @State outputStr: string = ''  
  webviewCtl: web_webview.WebviewController = new web_webview.WebviewController();  
  
  build() {  
    Row() {  
      Column() {  
        List({space: 20, initialIndex: 0}) {  
          ListItem() {  
            Button() {  
              Text('load bad ssl')  
                .fontSize(10)  
                .fontWeight(FontWeight.Bold)  
            }  
            .type(ButtonType.Capsule)  
            .onClick(() => {  
              // 加载一个过期的证书网站，查看获取到的证书信息  
              this.webviewCtl.loadUrl('https://expired.badssl.com')  
            })  
            .height(50)  
          }  
  
          ListItem() {  
            Button() {  
              Text('load example')  
                .fontSize(10)  
                .fontWeight(FontWeight.Bold)  
            }  
            .type(ButtonType.Capsule)  
            .onClick(() => {  
              // 加载一个https网站，查看网站的证书信息  
              this.webviewCtl.loadUrl('https://www.example.com')  
            })  
            .height(50)  
          }  
  
          ListItem() {  
            Button() {  
              Text('getCertificate Promise')  
                .fontSize(10)  
                .fontWeight(FontWeight.Bold)  
            }  
            .type(ButtonType.Capsule)  
            .onClick(() => {  
              try {  
                this.webviewCtl.getCertificate().then((x509CertArray:Array<cert.X509Cert>) => {  
                  this.outputStr = ParseX509CertInfo(x509CertArray);  
                })  
              } catch (error) {  
                let e:business_error.BusinessError = error as business_error.BusinessError;  
                this.outputStr = 'getCertificate failed: ' + e.code + ", errMsg: " + e.message;  
              }  
            })  
            .height(50)  
          }  
  
          ListItem() {  
            Button() {  
              Text('getCertificate AsyncCallback')  
                .fontSize(10)  
                .fontWeight(FontWeight.Bold)  
            }  
            .type(ButtonType.Capsule)  
            .onClick(() => {  
              try {  
                this.webviewCtl.getCertificate((error:business_error.BusinessError, x509CertArray:Array<cert.X509Cert>) => {  
                  if (error) {  
                    this.outputStr = 'getCertificate failed: ' + error.code + ", errMsg: " + error.message;  
                  } else {  
                    this.outputStr = ParseX509CertInfo(x509CertArray);  
                  }  
                })  
              } catch (error) {  
                let e:business_error.BusinessError = error as business_error.BusinessError;  
                this.outputStr = 'getCertificate failed: ' + e.code + ", errMsg: " + e.message;  
              }  
            })  
            .height(50)  
          }  
        }  
        .listDirection(Axis.Horizontal)  
        .height('10%')  
  
        Text(this.outputStr)  
          .width('100%')  
          .fontSize(10)  
  
        Web({ src: 'https://www.example.com', controller: this.webviewCtl })  
          .fileAccess(true)  
          .javaScriptAccess(true)  
          .domStorageAccess(true)  
          .onlineImageAccess(true)  
          .onPageEnd((e) => {  
            if (e) {  
              this.outputStr = 'onPageEnd : url = ' + e.url  
            }  
          })  
          .onSslErrorEventReceive((e) => {  
            // 忽略ssl证书错误，便于测试一些证书过期的网站，如：https://expired.badssl.com  
            e.handler.handleConfirm()  
          })  
          .width('100%')  
          .height('70%')  
      }  
      .height('100%')  
    }  
  }  
}  
    
```    
  
    
### setAudioMuted<sup>(10+)</sup>    
设置网页静音。  
 **调用形式：**     
- setAudioMuted(mute: boolean): void  
  
 **系统能力:**  SystemCapability.Web.Webview.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| mute | boolean | true | 表示是否将网页设置为静音状态，true表示设置为静音状态，false表示取消静音状态。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 17100001 | Init error. The WebviewController must be associated with a Web compoent. |  
    
 **示例代码：**   
```ts    
// xxx.ets  
import web_webview from '@ohos.web.webview'  
  
@Entry  
@Component  
struct WebComponent {  
  controller: web_webview.WebviewController = new web_webview.WebviewController()  
  @State muted: boolean = false  
  build() {  
    Column() {  
      Button("Toggle Mute")  
        .onClick(event => {  
          this.muted = !this.muted  
          this.controller.setAudioMuted(this.muted)  
        })  
      Web({ src: 'www.example.com', controller: this.controller })  
    }  
  }  
}  
    
```    
  
    
### prefetchPage<sup>(10+)</sup>    
在预测到将要加载的页面之前调用，提前下载页面所需的资源，包括主资源子资源，但不会执行网页JavaScript代码或呈现网页，以加快加载速度。  
 **调用形式：**     
- prefetchPage(url: string, additionalHeaders?: Array\<WebHeader>): void  
  
 **系统能力:**  SystemCapability.Web.Webview.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| url | string | true | 预加载的url。 |  
| additionalHeaders | Array<WebHeader> | false | url的附加HTTP请求头。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 17100001 | Init error. The WebviewController must be associated with a Web compoent. |  
| 17100002 |  |  
    
 **示例代码：**   
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
      Button('prefetchPopularPage')  
        .onClick(() => {  
          try {  
            // 预加载时，需要将'https://www.example.com'替换成一个真实的网站地址。  
            this.controller.prefetchPage('https://www.example.com');  
          } catch (error) {  
            let e:business_error.BusinessError = error as business_error.BusinessError;  
            console.error(`ErrorCode: ${e.code},  Message: ${e.message}`);  
          }  
        })  
      // 需要将'www.example1.com'替换成一个真实的网站地址。  
      Web({ src: 'www.example1.com', controller: this.controller })  
    }  
  }  
}  
    
```    
  
    
### prepareForPageLoad<sup>(10+)</sup>    
预连接url，在加载url之前调用此API，对url只进行dns解析，socket建链操作，并不获取主资源子资源。  
 **调用形式：**     
- static prepareForPageLoad(url: string, preconnectable: boolean, numSockets: number): void  
  
 **系统能力:**  SystemCapability.Web.Webview.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| url | string | true | 预连接的url。 |  
| preconnectable | boolean | true | 是否进行预连接。如果preconnectable为true，则对url进行dns解析，socket建链预连接；如果preconnectable为false，则不做任何预连接操作。 |  
| numSockets | number | true | 要预连接的socket数。socket数目连接需要大于0，最多允许6个连接。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 17100002 | Invalid url. |  
| 171000013 | The number of preconnect sockets is invalid. |  
    
 **示例代码：**   
```ts    
// xxx.ts  
import UIAbility from '@ohos.app.ability.UIAbility';  
import web_webview from '@ohos.web.webview';  
import AbilityConstant from '@ohos.app.ability.AbilityConstant';  
import Want from '@ohos.app.ability.Want';  
  
export default class EntryAbility extends UIAbility {  
    onCreate(want: Want, launchParam: AbilityConstant.LaunchParam) {  
        console.log("EntryAbility onCreate")  
        web_webview.WebviewController.initializeWebEngine()  
        // 预连接时，需要將'https://www.example.com'替换成一个真实的网站地址。  
        web_webview.WebviewController.prepareForPageLoad("https://www.example.com", true, 2);  
        AppStorage.setOrCreate("abilityWant", want)  
        console.log("EntryAbility onCreate done")  
    }  
}  
    
```    
  
    
### setCustomUserAgent<sup>(10+)</sup>    
设置自定义用户代理。  
 **调用形式：**     
- setCustomUserAgent(userAgent: string): void  
  
 **系统能力:**  SystemCapability.Web.Webview.Core    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| userAgent | string | true | 用户自定义代理信息。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 17100001 | Init error. The WebviewController must be associated with a Web compoent. |  
    
 **示例代码：**   
```ts    
// xxx.ets  
import web_webview from '@ohos.web.webview'  
import business_error from '@ohos.base'  
  
@Entry  
@Component  
struct WebComponent {  
  controller: web_webview.WebviewController = new web_webview.WebviewController();  
  @State userAgent: string = 'test'  
  
  build() {  
    Column() {  
      Button('setCustomUserAgent')  
        .onClick(() => {  
          try {  
            this.controller.setCustomUserAgent(this.userAgent);  
          } catch (error) {  
            let e:business_error.BusinessError = error as business_error.BusinessError;  
            console.error(`ErrorCode: ${e.code},  Message: ${e.message}`);  
          }  
        })  
      Web({ src: 'www.example.com', controller: this.controller })  
    }  
  }  
}  
    
```    
  
    
### getCustomUserAgent<sup>(10+)</sup>    
获取自定义用户代理。  
 **调用形式：**     
- getCustomUserAgent(): string  
  
 **系统能力:**  SystemCapability.Web.Webview.Core    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| string | 用户自定义代理信息。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 17100001 | Init error. The WebviewController must be associated with a Web compoent. |  
    
 **示例代码：**   
```ts    
// xxx.ets  
import web_webview from '@ohos.web.webview'  
import business_error from '@ohos.base'  
  
@Entry  
@Component  
struct WebComponent {  
  controller: web_webview.WebviewController = new web_webview.WebviewController();  
  @State userAgent: string = ''  
  
  build() {  
    Column() {  
      Button('getCustomUserAgent')  
        .onClick(() => {  
          try {  
            this.userAgent = this.controller.getCustomUserAgent();  
            console.log("userAgent: " + this.userAgent);  
          } catch (error) {  
            let e:business_error.BusinessError = error as business_error.BusinessError;  
            console.error(`ErrorCode: ${e.code},  Message: ${e.message}`);  
          }  
        })  
      Web({ src: 'www.example.com', controller: this.controller })  
    }  
  }  
}  
    
```    
  
