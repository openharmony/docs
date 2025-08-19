# ArkWeb简介
<!--Kit: ArkWeb-->
<!--Subsystem: Web-->
<!--Owner: @yp99ustc; @aohui; @zourongchun-->
<!--Designer: @LongLie; @yaomingliu; @zhufenghao-->
<!--Tester: @ghiker-->
<!--Adviser: @HelloCrease-->

## 需要权限

使用Web组件访问在线网页时需添加网络权限：ohos.permission.INTERNET，具体申请方式请参考[声明权限](../security/AccessToken/declare-permissions.md)。

  ```
  "requestPermissions":[
      {
        "name" : "ohos.permission.INTERNET"
      }
    ]
  ```

## 使用场景

ArkWeb（方舟Web）提供了Web组件，用于在应用程序中显示Web页面内容。常见使用场景包括：
- 应用集成Web页面：应用可以在页面中使用Web组件，嵌入Web页面内容，以降低开发成本，提升开发、运营效率。

- 浏览器网页浏览场景：浏览器类应用可以使用Web组件，打开三方网页，使用无痕模式浏览Web页面，设置广告拦截等。

- 小程序：小程序类宿主应用可以使用Web组件，渲染小程序的页面，实现同层渲染，视频托管等小程序的功能。

## 能力范围

Web组件为开发者提供了丰富的控制Web页面能力。包括：

- Web页面加载：声明式加载Web页面和离屏加载Web页面等。

- 生命周期管理：组件生命周期状态变化，通知Web页面的加载状态变化等。

- 常用属性与事件：User-Agent管理、Cookie与存储管理、字体与深色模式管理、权限管理等。

- 与应用界面交互：自定义文本选择菜单、上下文菜单、文件上传界面等与应用界面交互能力。

- App通过JavaScriptProxy，与Web页面进行JavaScript交互。

- 安全与隐私：无痕浏览模式、广告拦截、坚盾守护模式等。

- 维测能力：[DevTools工具](web-debugging-with-devtools.md)调试能力，使用crashpad收集Web组件崩溃信息。

- 其他高阶能力：与系统组件同层渲染、Web组件的网络托管、Web组件的媒体播放托管、Web组件输入框拉起自定义输入法、<!--RP1--><!--RP1End-->等。

## 约束与限制

- 可依据ArkWeb内核版本在相关网站查询W3C标准的支持情况。例如：https://developer.mozilla.org/en-US/ 和 https://webassembly.org/features/ 。

- Web内核版本：ArkWeb基于谷歌Chromium内核开发，系统版本与Chromium版本的对应关系如表格所示。从OpenHarmony 6.0开始，系统提供双内核方案。默认情况下，OpenHarmony 6.0版本系统使用M132内核，开发者也可以选择M114内核。

  | 系统版本 | Chromium版本 |
  |  ---|---|
  | OpenHarmony 4.0及之前 | M99 |
  | OpenHarmony 4.1-5.1 | M114 |
  | OpenHarmony 6.0 | M132（默认）<br>M114（可选，[M114适配指导](https://gitcode.com/openharmony-tpc/chromium_src/blob/132_trunk/web/ReleaseNote/CompatibleWithLegacyWebEngine.md)） |

## 相关实例

针对Web组件开发，有以下相关实例可供参考：

- [Web组件的使用（ArkTS）（API9）](https://gitee.com/openharmony/codelabs/tree/master/ETSUI/WebCookie)

- [Web组件抽奖案例（ArkTS）（API9）](https://gitee.com/openharmony/codelabs/tree/master/ETSUI/WebComponent)