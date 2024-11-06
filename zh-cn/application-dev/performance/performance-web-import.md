# Web组件开发性能提升指导

## 简介

开发者实现在应用中跳转显示网页需要分为两个方面：使用@ohos.web.webview提供Web控制能力；使用Web组件提供网页显示的能力。在实际应用中往往由于各种原因导致首次跳转Web网页或Web组件内跳转时出现白屏、卡顿等情况。本文介绍提升Web首页加载与Web网页间跳转速度的几种方法,并提供[示例源码](https://gitee.com/openharmony/applications_app_samples/tree/master/code/Performance/PerformanceLibrary/feature/webPerformance)。

## 优化思路

用户在使用Web组件显示网页时往往会经历四个阶段：无反馈-->白屏-->网页渲染-->完全展示，系统会在各个阶段内分别进行WebView初始化、建立网络连接、接受数据与渲染页面等操作，如图一所示是WebView的启动阶段。

图一 Web组件显示页面的阶段

![Web组件显示页面的阶段](./figures/web-display-stage.png)

要优化Web组件的首页加载性能，可以从图例标记的三个阶段来进行优化：

1. 在WebView的初始化阶段：应用打开WebView的第一步是启动浏览器内核，而这段时间由于WebView还不存在，所有后续的步骤是完全阻塞的。因此可以考虑在应用中预先完成初始化WebView，以及在初始化的同时通过预先加载组件内核、完成网络请求等方法，使得WebView初始化不是完全的阻塞后续步骤，从而减小耗时。
2. 在建立连接阶段：当开发者提前知道访问的网页地址，我们可以预先建立连接，进行DNS预解析。
3. 在接收资源数据阶段：当开发者预先知道用户下一页会点击什么页面的时候，可以合理使用缓存和预加载，将该页面的资源提前下载到缓存中。

综上所述，开发者可以通过方法1和2来提升Web首页加载速度，在应用创建Ability的时候，在OnCreate阶段预先初始化内核。随后在onAppear阶段进行预解析DNS、预连接要加载的首页。  
在网页跳转的场景，开发者也可以通过方法3，在onPageEnd阶段预加载下一个要访问的页面，提升Web网页间的跳转和显示速度，如图二所示。

图二 Web组件的生命周期回调函数

![Web组件的生命周期回调函数](./figures/web-life-cycle.png)

## 优化方法

### 提前初始化内核

当应用首次打开时，默认不会初始化浏览器内核，只有当创建WebView实例的时候，才会开始初始化浏览器内核。  
为了能提前初始化WebView实例，@ohos.web.webview提供了initializeWebEngine方法。该方法实现在Web组件初始化之前，通过接口加载Web引擎的动态库文件，从而提前进行Web组件动态库的加载和Web内核主进程的初始化，最终以提高启动性能，减少白屏时间。  
使用方法如下：
```javascript
// ../src/main/ets/pages/WebInitialized.ets

import webview from '@ohos.web.webview';

  aboutToAppear() {
    // 通过WebviewController可以控制Web组件各种行为。一个WebviewController对象只能控制一个Web组件，且必须在Web组件和WebviewController绑定后，才能调用WebviewController上的方法（静态方法除外）。
    webview.WebviewController.initializeWebEngine();
}
```

### 预解析DNS、预连接
WebView在onAppear阶段进行预连接socket， 当Web内核真正发起请求的时候会直接复用预连接的socket，如果当前预解析还没完成，真正发起网络请求进行DNS解析的时候也会复用当前正在执行的DNS解析任务。同理即使预连接的socket还没有连接成功，Web内核也会复用当前正在连接中的socket，进而优化资源的加载过程。  
@ohos.web.webview提供了prepareForPageLoad方法实现预连接url，在加载url之前调用此API，对url只进行DNS解析、socket建链操作，并不获取主资源子资源。  
参数：

| 参数名            | 类型      | 说明                                                                                        |
|----------------|---------|-------------------------------------------------------------------------------------------|
| url            | string  | 预连接的url。                                                                                  |
| preconnectable | boolean | 是否进行预连接。如果preconnectable为true，则对url进行dns解析，socket建链预连接；如果preconnectable为false，则不做任何预连接操作。 |
| numSockets     | number  | 要预连接的socket数。socket数目连接需要大于0，最多允许6个连接。                                                    |

使用方法如下：  
```javascript
// 开启预连接需要先使用上述方法预加载WebView内核。
webview.WebviewController.initializeWebEngine();
// 启动预连接，连接地址为即将打开的网址。
webview.WebviewController.prepareForPageLoad("https://www.example.com", true, 2);
```

### 预加载下一页
开发者可以在onPageEnd阶段进行预加载，当真正去加载下一个页面的时候，如果预加载已经成功，则相当于直接从缓存中加载页面资源，速度更快。一般来说能够准确预测到用户下一步要访问的页面的时候，可以进行预加载将要访问的页面，比如小说下一页， 浏览器在地址栏输入过程中识别到用户将要访问的页面等。  
@ohos.web.webview提供prefetchPage方法实现在预测到将要加载的页面之前调用，提前下载页面所需的资源，包括主资源子资源，但不会执行网页JavaScript代码或呈现网页，以加快加载速度。  
参数：

| 参数名               | 类型                | 说明             |
|-------------------|-------------------|----------------|
| url               | string            | 预加载的url。       |
| additionalHeaders | Array\<WebHeader> | url的附加HTTP请求头。 |

使用方法如下：
```typescript
// src/main/ets/pages/WebBrowser.ets

import { webview } from '@kit.ArkWeb';

@Entry
@Component
struct WebComponent {
  controller: webview.WebviewController = new webview.WebviewController();

  build() {
    Column() {
      // ...
      Web({ src: 'https://www.example.com', controller: this.controller })
        .onPageEnd((event) => {
          //  ...
          // 在确定即将跳转的页面时开启预加载，url请替换真实地址
          this.controller.prefetchPage('https://www.example.com/nextpage');
        })
        .width('100%')
        .height('80%')

      Button('下一页')
        .onClick(() => {
          // ...
          // 跳转下一页
          this.controller.loadUrl('https://www.example.com/nextpage');
        })
    }
  }
}
```

## 性能分析

### 场景示例

构建通过点击按钮跳转Web网页和在网页内跳转页面的场景，在点击按钮触发跳转事件、Web组件触发OnPageEnd事件处使用Hilog打点记录时间戳。

#### 反例

入口页通过router实现跳转
```javascript
// ../src/main/ets/pages/WebUninitialized.ets

Button('进入网页')
  .onClick(() => {
    hilog.info(0x0001, "WebPerformance", "UnInitializedWeb");
    router.pushUrl({ url: 'pages/WebBrowser' });
  })
```
Web页使用Web组件加载指定网页
```javascript
// ../src/main/ets/pages/WebBrowser.ets

Web({ src: 'https://www.example.com', controller: this.controller })
  .domStorageAccess(true)
  .onPageEnd((event) => {
     if (event) {
       hilog.info(0x0001, "WebPerformance", "WebPageOpenEnd");
     }
  })
```

#### 正例

入口页提前进行Web组件的初始化和预连接

```typescript
// ../src/main/ets/pages/WebInitialized.ets
  
import { webview } from '@kit.ArkWeb';
import { router } from '@kit.ArkUI';
import { hilog } from '@kit.PerformanceAnalysisKit';

@Entry
@Component
struct WebComponent {
  controller: webview.WebviewController = new webview.WebviewController();

  aboutToAppear() {
    webview.WebviewController.initializeWebEngine();
    webview.WebviewController.prepareForPageLoad("https://www.example.com", true, 2);
  }

  build() {
    Column() {
      Button('进入网页')
        .onClick(() => {
          hilog.info(0x0001, "WebPerformance", "InitializedWeb");
          router.pushUrl({ url: 'pages/WebBrowser' });
        })
    }
  }
}
```
Web页加载的同时使用prefetchPage预加载下一页
```typescript
// ../src/main/ets/pages/WebBrowser.ets

import { webview } from '@kit.ArkWeb';
import { hilog } from '@kit.PerformanceAnalysisKit';

@Entry
@Component
struct WebComponent {
  controller: webview.WebviewController = new webview.WebviewController();

  build() {
    Column() {
      // ...
      Web({ src: 'https://www.example.com', controller: this.controller })
        .domStorageAccess(true)
        .onPageEnd((event) => {
          if (event) {
            hilog.info(0x0001, "WebPerformance", "WebPageOpenEnd");
            this.controller.prefetchPage('https://www.example.com/nextpage');
          }
        })
    }
  }
}
```

### 数据对比

通过分别抓取正反示例的trace数据后使用SmartPerf Host工具分析可以得出以下结论：

![hilog](./figures/web-hilog.png)

从点击按钮进入Web首页到Web组件触发OnPageEnd事件，表示首页加载完成。对比优化前后时延可以得出，使用提前初始化内核和预解析、预连接可以减少平均100ms左右的加载时间。

![首页完成时延](./figures/web-open-time-chart.png)

从Web首页内点击跳转下一页按钮到Web组件触发OnPageEnd事件，表示页面间跳转完成。对比优化前后时延可以得出，使用预加载下一页方法可以减少平均40~50ms左右的跳转时间。

![跳转完成时延](./figures/web-route-time-chart.png)

<!--no_check-->
