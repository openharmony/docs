# Class (ProxyController)
<!--Kit: ArkWeb-->
<!--Subsystem: Web-->
<!--Owner: @aohui-->
<!--SE: @yaomingliu-->
<!--TSE: @ghiker-->

此类用于为应用程序设置代理。

> **说明：**
>
> - 本模块首批接口从API version 9开始支持。后续版本如有新增内容，则采用上角标单独标记该内容的起始版本。
>
> - 本Class首批接口从API version 15开始支持。
>
> - 示例效果请以真机运行为准，当前DevEco Studio预览器不支持。

## 导入模块

```ts
import { webview } from '@kit.ArkWeb';
```

## applyProxyOverride<sup>15+</sup>

static applyProxyOverride(proxyConfig: ProxyConfig, callback: OnProxyConfigChangeCallback): void

设置应用中所有Web使用的代理配置，与[insertBypassRule](./arkts-apis-webview-ProxyConfig.md#insertbypassrule15)中插入的bypass规则匹配的URL将不会使用代理，而是直接向URL指定的源地址发起请求。代理设置成功后，不保证网络连接后会立即使用新的代理设置，在加载页面之前请等待监听器触发，这个监听器将在UI线程上被调用。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名          | 类型     |  必填  | 说明           |
| ---------------| ------- | ---- | ------------- |
| proxyConfig     | [ProxyConfig](./arkts-apis-webview-ProxyConfig.md)  | 是   | 对代理的配置。 |
| callback     | [OnProxyConfigChangeCallback](./arkts-apis-webview-t.md#onproxyconfigchangecallback15)   | 是   | 代理设置成功的回调。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)说明文档。

| 错误码ID | 错误信息                              |
| -------- | ------------------------------------- |
|  401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |

**示例：**

完整示例代码参考[removeProxyOverride](./arkts-apis-webview-ProxyController.md#removeproxyoverride15)。

## removeProxyOverride<sup>15+</sup>

static removeProxyOverride(callback: OnProxyConfigChangeCallback): void

移除代理配置。移除代理配置后，不保证网络连接后会立即使用新的代理设置，在加载页面之前等待监听器，这个监听器将在UI线程上被调用。

**系统能力：** SystemCapability.Web.Webview.Core

**参数：**

| 参数名          | 类型     |  必填  | 说明           |
| ---------------| ------- | ---- | ------------- |
| callback     | [OnProxyConfigChangeCallback](./arkts-apis-webview-t.md#onproxyconfigchangecallback15)   | 是   | 代理设置成功的回调。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)说明文档。

| 错误码ID | 错误信息                              |
| -------- | ------------------------------------- |
|  401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types.  |

**示例：**

```ts
// xxx.ets
import { webview } from '@kit.ArkWeb';
import { BusinessError } from '@kit.BasicServicesKit';

@Entry
@Component
struct WebComponent {
  controller: webview.WebviewController = new webview.WebviewController();
  proxyRules: webview.ProxyRule[] = [];

  build() {
    Row() {
      Column() {
        Button("applyProxyOverride").onClick(()=>{
          let proxyConfig:webview.ProxyConfig = new webview.ProxyConfig();
          //优先使用第一个代理配置https://proxy.XXX.com
          //代理失败后会回落到直连服务器insertDirectRule
          try {
            proxyConfig.insertProxyRule("https://proxy.XXX.com", webview.ProxySchemeFilter.MATCH_ALL_SCHEMES);
          } catch (error) {
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
          }
          try {
            proxyConfig.insertDirectRule(webview.ProxySchemeFilter.MATCH_HTTP);
          } catch (error) {
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
          }
          try {
            proxyConfig.insertBypassRule("*.example.com");
          } catch (error) {
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
          }
          proxyConfig.clearImplicitRules();
          proxyConfig.bypassHostnamesWithoutPeriod();
          try {
            proxyConfig.enableReverseBypass(true);
          } catch (error) {
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
          }
          let bypassRules = proxyConfig.getBypassRules();
          for (let i = 0; i < bypassRules.length; i++) {
            console.log("bypassRules: " + bypassRules[i]);
          }
          this.proxyRules = proxyConfig.getProxyRules();
          for (let i = 0; i < this.proxyRules.length; i++) {
            console.log("SchemeFiletr: " + this.proxyRules[i].getSchemeFilter());
            console.log("Url: " + this.proxyRules[i].getUrl());
          }
          let isReverseBypassRule = proxyConfig.isReverseBypassEnabled();
          console.log("isReverseBypassRules: " + isReverseBypassRule);
          try {
            webview.ProxyController.applyProxyOverride(proxyConfig, () => {
              console.log("PROXYCONTROLLER proxy changed");
            });
          } catch (error) {
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
          }
        })
        Button("loadUrl-https").onClick(()=>{
          this.controller.loadUrl("https://www.example.com")
        })
        Button("loadUrl-http").onClick(()=>{
          this.controller.loadUrl("http://www.example.com")
        })
        Button("removeProxyOverride").onClick(()=>{
          try {
          webview.ProxyController.removeProxyOverride(() => {
            console.log("PROXYCONTROLLER proxy changed");
          });
          } catch (error) {
            console.error(`ErrorCode: ${(error as BusinessError).code},  Message: ${(error as BusinessError).message}`);
          }
        })
        Web({ src: 'www.example.com', controller: this.controller})
      }
      .width('100%')
    }
    .height('100%')
  }
}

```