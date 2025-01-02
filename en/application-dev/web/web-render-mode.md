# Rendering Modes of the Web Component

The **Web** component supports two rendering modes.

**Asynchronous Rendering Mode (Default)**

` renderMode: RenderMode.ASYNC_RENDER`

Displays a **Web** component as a graphics surface node independently in asynchronous rendering mode. You are advised to use this mode on application pages that consist of only **Web** components to achieve better performance and lower power consumption.

**Synchronous Rendering Mode**

` renderMode: RenderMode.SYNC_RENDER`

Displays a **Web** component as a canvas node with the system component in synchronous rendering mode. This mode renders longer **Web** component content but consumes more performance resources.

> **NOTE**
>
> For details about the enumerated values, see [RenderMode](../reference/apis-arkweb/ts-basic-components-web.md#rendermode12).

## Specifications and Constraints

**Asynchronous Rendering Mode**

- The maximum width and height of a **Web** component cannot exceed 7,680 pixels (physical pixels). Otherwise, a white screen is displayed.
- Dynamic mode switching is not supported.

**Synchronous Rendering Mode**

- The maximum width and height of a **Web** component cannot exceed 500,000 pixels (physical pixels). Otherwise, a white screen is displayed.
- Direct Digital Synthesis (DSS) is not supported.
- Dynamic mode switching is not supported.

## When to Use

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
             renderMode: RenderMode.ASYNC_RENDER // Set the rendering mode.
         })
     }
  }
}
```

![web-render-mode](figures/web-render-mode.png)
