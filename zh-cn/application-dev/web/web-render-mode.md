# Web组件渲染模式

Web组件支持两种渲染模式。

**异步渲染模式（默认）**

` renderMode: RenderMode.ASYNC_RENDER`

异步渲染模式下，Web组件作为图形surface节点，独立送显。建议在仅由Web组件构成的应用页面中使用此模式，有更好的性能和更低的功耗表现。

**同步渲染模式**

` renderMode: RenderMode.SYNC_RENDER`

同步渲染模式下，Web组件作为图形canvas节点，Web渲染跟随系统组件一起送显。可以渲染更长Web组件内容，但会消耗更多的性能资源。

> **说明：**
>
> 接口枚举值定义请查看[RenderMode枚举说明](../reference/apis-arkweb/ts-basic-components-web.md#rendermode12枚举说明)。

## 规格与约束

**异步渲染模式**

- Web组件的宽高最大规格不超过7,680px（物理像素），超过则会导致白屏。
- 不支持动态切换模式。

**同步渲染模式**

- Web组件的宽高最大规格不超过500,000px（物理像素），超过则会导致白屏。
- 不支持DSS合成。
- 不支持动态切换模式。

## 使用场景

```typescript
// renderMode.ets
import { webview } from '@kit.ArkWeb';

@Entry
@Component
struct WebHeightPage {
  private webviewController: WebviewController = new webview.WebviewController()

  build() {
     Column() {
         Web({
             src: "https://www.example.com/",
             controller: this.webviewController,
             renderMode: RenderMode.ASYNC_RENDER // 设置渲染模式
         })
     }
  }
}
```

![web-render-mode](figures/web-render-mode.png)


