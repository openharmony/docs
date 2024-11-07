# Web组件大小自适应页面内容布局

使用Web组件大小自适应页面内容布局模式`layoutMode(WebLayoutMode.FIT_CONTENT)`时，能使Web组件的大小根据页面内容自适应变化。

适用于Web组件需要根据网页高度撑开，与其他原生组件一起滚动的场景，如：

- 浏览长文章。Web组件同一布局层级有其他原生组件，如评论区、工具栏等。
- 长页面首页。Web组件同一布局层级有其他原生组件，如宫格菜单。

## 规格与约束

1. 建议配置[渲染模式](web-render-mode.md)为同步渲染模式，避免因为组件大小超出限制导致异常场景（白屏，布局错误）。
2. 建议配置[过滚动模式](../reference/apis-arkweb/ts-basic-components-web.md#overscrollmode11)为关闭状态。当过滚动模式开启时，当用户在Web界面上滑动到边缘时，Web会通过弹性动画弹回界面，会与Scroll组件的回弹相互冲突，影响体验。
3. [键盘避让](../reference/apis-arkweb/ts-basic-components-web.md#keyboardavoidmode12)属性配置为RESIZE_CONTENT时，该避让模式不生效。
4. 不支持对页面进行缩放。
5. 不支持通过Web组件的height属性修改组件高度。
6. 仅支持根据页面内容自适应组件高度，不支持自适应宽度。

## 使用场景

```typescript
// fit_content_test.ets
import { webview } from '@kit.ArkWeb';

@Entry
@Component
struct WebHeightPage {
  private webviewController: WebviewController = new webview.WebviewController()
  private scroller: Scroller = new Scroller()

  build() {
    Navigation() {
      Column() {
        Scroll(this.scroller) {
          Column() {
            Web({
              src: $rawfile("fit_content.html"),
              controller: this.webviewController,
              renderMode: RenderMode.SYNC_RENDER // 设置为同步渲染模式
            })
              .layoutMode(WebLayoutMode.FIT_CONTENT) // 设置为Web组件大小自适应页面内容
              .overScrollMode(OverScrollMode.NEVER) // 设置过滚动模式为关闭状态
            Text("评论区")
              .fontSize(28)
              .fontColor("#FF0F0F")
              .height(100)
              .width("100%")
              .backgroundColor("#f89f0f")
          }
        }

      }
    }
    .title("标题栏")
  }
}
```

```
<!--fit_content.html-->
<!DOCTYPE html>
<html>
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1, user-scalable=no">
    <title>Fit-Content</title>
</head>
<body>
<div>
    <div><h2 id="使用场景">使用场景</h2>
        <p>ArkWeb（方舟Web）提供了Web组件，用于在应用程序中显示Web页面内容。常见使用场景包括：</p>
        <ul>
            <li><p>
                应用集成Web页面：应用可以在页面中使用Web组件，嵌入Web页面内容，以降低开发成本，提升开发、运营效率。</p>
            </li>
            <li><p>
                浏览器网页浏览场景：浏览器类应用可以使用Web组件，打开三方网页，使用无痕模式浏览Web页面，设置广告拦截等。</p>
            </li>
            <li><p>小程序：小程序类宿主应用可以使用Web组件，渲染小程序的页面。</p></li>
        </ul>
    </div>
    <div><h2 id="能力范围">能力范围</h2>
        <p>Web组件为开发者提供了丰富的控制Web页面能力。包括：</p>
        <ul>
            <li><p>Web页面加载：声明式加载Web页面和离屏加载Web页面等。</p></li>
            <li><p>生命周期管理：组件生命周期状态变化，通知Web页面的加载状态变化等。</p></li>
            <li><p>常用属性与事件：UserAgent管理、Cookie与存储管理、字体与深色模式管理、权限管理等。</p>
            </li>
            <li><p>
                与应用界面交互：自定义文本选择菜单、上下文菜单、文件上传界面等与应用界面交互能力。</p>
            </li>
            <li><p>App通过JavaScriptProxy，与Web页面进行JavaScript交互。</p></li>
            <li><p>安全与隐私：无痕浏览模式、广告拦截、坚盾守护模式等。</p></li>
            <li><p>维测能力：Devtools工具调试能力，使用crashpad收集Web组件崩溃信息。
            </p></li>
            <li><p>
                其他高阶能力：与原生组件同层渲染、Web组件的网络托管、Web组件的媒体播放托管、Web组件输入框拉起自定义输入法、等。</p>
            </li>
        </ul>
    </div>
    <div><h2 id="约束与限制">约束与限制</h2>
        <ul>
            <li>Web内核版本：ArkWeb基于谷歌Chromium内核开发，使用的Chromium版本为M114。</li>
        </ul>
    </div>
</div>
</body>
</html>
```


![web-fit-content](figures/web-fit-content.gif)


