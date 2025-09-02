# AtomicServiceWeb

**AtomicServiceWeb** is an advanced web component offering customization to meet specific demands. It shields irrelevant APIs from the native **Web** component and extends functionality through JavaScript capabilities.

> **NOTE**
>
> - This component is supported since API version 12. Updates will be marked with a superscript to indicate their earliest API version.
> - You can preview how this component looks on a real device, but not in DevEco Studio Previewer.

## Required Permissions

**ohos.permission.INTERNET**, required for accessing online web pages. For details about how to apply for a permission, see [Declaring Permissions](../../../security/AccessToken/declare-permissions.md).

## Modules to Import

```
import { AtomicServiceWeb } from '@kit.ArkUI';
```

## Child Components

Not supported

## Attributes

The [universal attributes](ts-component-general-attributes.md) are not supported.

## AtomicServiceWeb

```
AtomicServiceWeb({
  src: ResourceStr,
  controller: AtomicServiceWebController,
  navPathStack?: NavPathStack,
  mixedMode?: MixedMode,
  darkMode?: WebDarkMode,
  forceDarkAccess?: boolean,
  nestedScroll?: NestedScrollOptions | NestedScrollOptionsExt,
  onMessage?: Callback<OnMessageEvent>,
  onErrorReceive?: Callback<OnErrorReceiveEvent>,
  onHttpErrorReceive?: Callback<OnHttpErrorReceiveEvent>,
  onPageBegin?: Callback<OnPageBeginEvent>,
  onPageEnd?: Callback<OnPageEndEvent>,
  onControllerAttached?: Callback<void>,
  onLoadIntercept?: Callback<OnLoadInterceptEvent, boolean>,
  onProgressChange?: Callback<OnProgressChangeEvent>
})
```

**Decorator**: @Component

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name                  | Type                                                                                                              | Mandatory| Decorator      | Description                                                                                                                 |
|----------------------|------------------------------------------------------------------------------------------------------------------|----|-------------|----------------------------------------------------------------------------------------------------------------------|
| src                  | [ResourceStr](ts-types.md#resourcestr)                                                                           | Yes | -           | Web page resource address. Accessing network resources requires configuring service domain names in AppGallery Connect, and accessing local resources only supports files within the package (**$rawfile**). Dynamic updating of the address through state variables (for example, @State) is not supported. The loaded web page supports calling system capabilities through the APIs provided by the JS SDK, with the specifics governed by the JS SDK.|
| controller           | [AtomicServiceWebController](#atomicservicewebcontroller)                                                        | Yes | @ObjectLink | Controller for controlling the behavior of the **AtomicServiceWeb** component.                                                             |
| navPathStack         | [NavPathStack](ts-basic-components-navigation.md#navpathstack10)                                                 | No | -           | Information about the navigation stack. When **NavDestination** serves as the root container of the page, **NavPathStack** corresponding to the **NavDestination** container must be passed to handle page routing.                                          |
| mixedMode            | [MixedMode](../../apis-arkweb/arkts-basic-components-web-e.md#mixedmode)                                          | No | @Prop       | Whether to enable loading of HTTP and HTTPS mixed content. By default, this feature is disabled.                                                   |
| darkMode             | [WebDarkMode](../../apis-arkweb/arkts-basic-components-web-e.md#webdarkmode9)                                     | No | @Prop       | Web dark mode. By default, web dark mode is disabled.                                                                                                     |
| forceDarkAccess      | boolean                                                                                                          | No | @Prop       | Whether to enable forcible dark mode for the web page. This feature is disabled by default. This API is effective only when web dark mode is enabled.                                                                         |
| nestedScroll<sup>15+</sup>      | [NestedScrollOptions](../../apis-arkui/arkui-ts/ts-container-scrollable-common.md#nestedscrolloptions10) \| [NestedScrollOptionsExt](../../apis-arkweb/arkts-basic-components-web-i.md#nestedscrolloptionsext14) | No | @Prop       | Nested scrolling options.<br>**Atomic service API**: This API can be used in atomic services since API version 15.                                                                             |
| onMessage            | Callback\<[OnMessageEvent](#onmessageevent)\>                                                                    | No | -           | Callback invoked when the HTML5 page sends a message through the **postMessage()** API of the JS SDK, and the **AtomicServiceWeb** component's corresponding page is returned or destroyed.                                                             |
| onErrorReceive       | Callback\<[OnErrorReceiveEvent](#onerrorreceiveevent)\>                                                          | No | -           | Callback invoked when an error occurs during web page loading. For performance reasons, simplify the implementation logic in the callback. This callback is invoked when there is no network connection.                                                                |
| onHttpErrorReceive   | Callback\<[OnHttpErrorReceiveEvent](#onhttperrorreceiveevent)\>                                                  | No | -           | Callback invoked when an HTTP error (the response code is greater than or equal to 400) occurs during web page resource loading.                                                                                    |
| onPageBegin          | Callback\<[OnPageBeginEvent](#onpagebeginevent)\>                                                                | No | -           | Callback invoked when the web page starts to be loaded. It is invoked only for the main frame content, and not for the iframe or frameset content.                                                             |
| onPageEnd            | Callback\<[OnPageEndEvent](#onpageendevent)\>                                                                    | No | -           | Callback invoked when the web page loading is complete. It is invoked only for the main frame content.                                                                                           |
| onControllerAttached | Callback\<void\>                                                                                                 | No | -           | Callback invoked when a controller is attached to the **AtomicServiceWeb** component.                                                                                        |
| onLoadIntercept      | [OnLoadInterceptCallback](#onloadinterceptcallback) | No | -  | Callback invoked when the **AtomicServiceWeb** component is about to load the URL. It is used to determine whether to block the loading. By default, the loading is allowed.                                                                             |
| onProgressChange     | Callback\<[OnProgressChangeEvent](../../apis-arkweb/arkts-basic-components-web-i.md#onprogresschangeevent12)\>        | No | -           | Callback invoked when the web page loading progress changes.                                                                                                     |

## AtomicServiceWebController

Implements an **AtomicServiceWebController** object for controlling the behavior of the **AtomicServiceWeb** component. An **AtomicServiceWebController** can control only one **AtomicServiceWeb** component, and the APIs on the **AtomicServiceWebController** can be called only after it has been bound to the target **AtomicServiceWeb** component.

**Decorator Type**: @Observed

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

### getUserAgent

getUserAgent(): string

Obtains the default user agent of this web page.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Return value**

| Type    | Description     |
|--------|---------|
| string | Default user agent. For details about the specifications and usage scenarios, see [Developing User-Agent](../../../web/web-default-userAgent.md).|

**Error codes**

For details about the error codes, see [Webview Error Codes](../../apis-arkweb/errorcode-webview.md).

| ID   | Error Message                                                                                            |
|----------|--------------------------------------------------------------------------------------------------|
| 17100001 | Init error. The AtomicServiceWebController must be associated with a AtomicServiceWeb component. |

### getCustomUserAgent

getCustomUserAgent(): string

Obtains a custom user agent.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Return value**

| Type    | Description        |
|--------|------------|
| string | Information about the custom user agent. For details about the specifications and usage scenarios, see [Developing User-Agent](../../../web/web-default-userAgent.md).|

**Error codes**

For details about the error codes, see [Webview Error Codes](../../apis-arkweb/errorcode-webview.md).

| ID   | Error Message                                                                                            |
|----------|--------------------------------------------------------------------------------------------------|
| 17100001 | Init error. The AtomicServiceWebController must be associated with a AtomicServiceWeb component. |

### setCustomUserAgent

setCustomUserAgent(userAgent: string): void

Sets a custom user agent, which will overwrite the default user agent.

Set the user agent in the **onControllerAttached** callback to ensure that it takes effect. For details about the setting, see the example. Avoid setting the user agent in **onLoadIntercept**. Otherwise, the setting may fail occasionally.

> **NOTE**
>
>If a URL is set for the **Web** component **src** and **UserAgent** is not set in the **onControllerAttached** callback, calling **setCustomUserAgent** may cause mismatches between the loaded page and the intended user agent.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name      | Type    | Mandatory| Description                                                                      |
|-----------|--------|----|--------------------------------------------------------------------------|
| userAgent | string | Yes | Information about the custom user agent. It is recommended that you obtain the current default user agent through [getUserAgent](#getuseragent) and then customize the obtained user agent.|

**Error codes**

For details about the error codes, see [Webview Error Codes](../../apis-arkweb/errorcode-webview.md).

| ID   | Error Message                                                                                            |
|----------|--------------------------------------------------------------------------------------------------|
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 17100001 | Init error. The AtomicServiceWebController must be associated with a AtomicServiceWeb component. |

### refresh

refresh(): void

Refreshes the web page.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Error codes**

For details about the error codes, see [Webview Error Codes](../../apis-arkweb/errorcode-webview.md).

| ID   | Error Message                                                                                            |
|----------|--------------------------------------------------------------------------------------------------|
| 17100001 | Init error. The AtomicServiceWebController must be associated with a AtomicServiceWeb component. |

### forward

forward(): void

Moves to the next page based on the history stack. This API is generally used together with [accessForward](#accessforward).

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Error codes**

For details about the error codes, see [Webview Error Codes](../../apis-arkweb/errorcode-webview.md).

| ID   | Error Message                                                                                            |
|----------|--------------------------------------------------------------------------------------------------|
| 17100001 | Init error. The AtomicServiceWebController must be associated with a AtomicServiceWeb component. |

### backward

backward(): void

Moves to the previous page based on the history stack. This API is generally used together with [accessBackward](#accessbackward).

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Error codes**

For details about the error codes, see [Webview Error Codes](../../apis-arkweb/errorcode-webview.md).

| ID   | Error Message                                                                                            |
|----------|--------------------------------------------------------------------------------------------------|
| 17100001 | Init error. The AtomicServiceWebController must be associated with a AtomicServiceWeb component. |

### accessForward

accessForward(): boolean

Checks whether going to the next page can be performed on this page.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Return value**

| Type     | Description                   |
|---------|-----------------------|
| boolean | Returns **true** if going to the next page can be performed on the current page; returns **false** otherwise.|

**Error codes**

For details about the error codes, see [Webview Error Codes](../../apis-arkweb/errorcode-webview.md).

| ID   | Error Message                                                                                            |
|----------|--------------------------------------------------------------------------------------------------|
| 17100001 | Init error. The AtomicServiceWebController must be associated with a AtomicServiceWeb component. |

### accessBackward

accessBackward(): boolean

Checks whether going to the previous page can be performed on this page.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Return value**

| Type     | Description                   |
|---------|-----------------------|
| boolean | Returns **true** if going to the previous page can be performed on the current page; returns **false** otherwise.|

**Error codes**

For details about the error codes, see [Webview Error Codes](../../apis-arkweb/errorcode-webview.md).

| ID   | Error Message                                                                                            |
|----------|--------------------------------------------------------------------------------------------------|
| 17100001 | Init error. The AtomicServiceWebController must be associated with a AtomicServiceWeb component. |

### accessStep

accessStep(step: number): boolean

Checks whether this page can navigate forward or backward by the specified number of steps.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name | Type    | Mandatory| Description                   |
|------|--------|----|-----------------------|
| step | number | Yes | Number of the steps to take. A positive number means to go forward, and a negative number means to go backward.|

**Return value**

| Type     | Description       |
|---------|-----------|
| boolean | Whether the page can navigate forward or backward by the specified number of steps. Returns **true** if navigation can be performed on the current page; returns **false** otherwise.|

**Error codes**

For details about the error codes, see [Webview Error Codes](../../apis-arkweb/errorcode-webview.md).

| ID   | Error Message                                                                                            |
|----------|--------------------------------------------------------------------------------------------------|
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed. |
| 17100001 | Init error. The AtomicServiceWebController must be associated with a AtomicServiceWeb component. |

### loadUrl

loadUrl(url: string | Resource, headers?: Array\<WebHeader>): void

Loads a specified URL.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name    | Type                             | Mandatory| Description            |
|---------|---------------------------------|----|:---------------|
| url     | string \| [Resource](../../apis-arkui/arkui-ts/ts-types.md#resource)               | Yes | URL to load.    |
| headers | Array\<[WebHeader](#webheader)> | No | Additional HTTP request header of the URL.|

**Error codes**

For details about the error codes, see [Webview Error Codes](../../apis-arkweb/errorcode-webview.md).

| ID   | Error Message                                                                                            |
|----------|--------------------------------------------------------------------------------------------------|
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. 3.Parameter verification failed. |
| 17100001 | Init error. The AtomicServiceWebController must be associated with a AtomicServiceWeb component. |
| 17100002 | Invalid url.                                                                                     |
| 17100003 | Invalid resource path or file type.                                                              |

## WebHeader

Describes the request/response header returned by the **AtomicServiceWeb** component.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name         | Type    | Read-Only| Optional| Description           |
|-------------|--------|----|----|---------------|
| headerKey   | string | No | No | Key of the request/response header.  |
| headerValue | string | No | No | Value of the request/response header.|

## OnMessageEvent

Represents the callback invoked when the page is navigated back or destroyed.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name  | Type      | Mandatory| Description   |
|------|----------|----|-------|
| data | object[] | Yes | Message list.|

## OnErrorReceiveEvent

Represents the callback invoked when an error occurs during web page loading.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name     | Type                                                                                   | Mandatory| Description             |
|---------|---------------------------------------------------------------------------------------|----|-----------------|
| request | [WebResourceRequest](../../apis-arkweb/arkts-basic-components-web-WebResourceRequest.md) | Yes | Encapsulation of a web page request.     |
| error   | [WebResourceError](../../apis-arkweb/arkts-basic-components-web-WebResourceError.md)     | Yes | Encapsulation of a web page resource loading error.|

## OnHttpErrorReceiveEvent

Represents the callback invoked when an HTTP error occurs during web page resource loading.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name      | Type                                                                                     | Mandatory| Description        |
|----------|-----------------------------------------------------------------------------------------|----|------------|
| request  | [WebResourceRequest](../../apis-arkweb/arkts-basic-components-web-WebResourceRequest.md)   | Yes | Encapsulation of a web page request.|
| response | [WebResourceResponse](../../apis-arkweb/arkts-basic-components-web-WebResourceResponse.md) | Yes | Encapsulation of a resource response.|

## OnPageBeginEvent

Represents the callback invoked when the web page loading begins.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name | Type    | Mandatory| Description       |
|-----|--------|----|-----------|
| url | string | Yes | URL of the page.|

## OnPageEndEvent

Represents the callback invoked when the web page loading ends.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name | Type    | Mandatory| Description       |
|-----|--------|----|-----------|
| url | string | Yes | URL of the page.|

## OnLoadInterceptEvent

Represents the event triggered when resource loading is intercepted.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name            | Type     | Mandatory  | Description                                      |
| -------------- | ---- | ---- | ---------------------------------------- |
| data | [WebResourceRequest](../../apis-arkweb/arkts-basic-components-web-WebResourceRequest.md) | Yes| Encapsulation of a web page request.|

## OnProgressChangeEvent

Represents the callback invoked when the web page loading progress changes.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

| Name            | Type     | Mandatory  | Description                                      |
| -------------- | ---- | ---- | ---------------------------------------- |
| newProgress | number | Yes| New loading progress. The value is an integer ranging from 0 to 100.                      |

## OnLoadInterceptCallback

type OnLoadInterceptCallback = (event: OnLoadInterceptEvent) => boolean

Represents the callback invoked when resource loading is intercepted.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.ArkUI.ArkUI.Full

**Parameters**

| Name | Type    | Mandatory| Description                   |
|------|--------|----|-----------------------|
| event | OnLoadInterceptEvent | Yes | Event triggered when resource loading is intercepted.|

**Return value**

| Type     | Description       |
|---------|-----------|
| boolean | Whether the resource is intercepted.|

## Events

The [universal events](ts-component-general-events.md) are not supported.

## Example

### Example 1

This example loads a local web page:

```ts
// xxx.ets
import { AtomicServiceWeb, AtomicServiceWebController } from '@kit.ArkUI';

@Entry
@Component
struct WebComponent {
  @State controller: AtomicServiceWebController = new AtomicServiceWebController();
  
  build() {
    Column() {
      AtomicServiceWeb({ src: $rawfile("index.html"), controller: this.controller })
    }
  }
}
```

### Example 2

This example loads an online web page:

```ts
// xxx.ets
import { AtomicServiceWeb, AtomicServiceWebController } from '@kit.ArkUI';

@Entry
@Component
struct WebComponent {
    @State controller: AtomicServiceWebController = new AtomicServiceWebController();

    build() {
        Column() {
            AtomicServiceWeb({ src: 'https://www.example.com', controller: this.controller })
        }
    }
}
```

### Example 3

This example demonstrates how to load a web page within a **NavDestination** container.

```ts
// xxx.ets
import { AtomicServiceWeb, AtomicServiceWebController } from '@kit.ArkUI';

@Builder
export function WebComponentBuilder(name: string, param: Object) {
  WebComponent()
}

@Component
struct WebComponent {
  navPathStack: NavPathStack = new NavPathStack();
  @State controller: AtomicServiceWebController = new AtomicServiceWebController();

  build() {
    NavDestination() {
      AtomicServiceWeb({ src: $rawfile("index.html"), controller: this.controller, navPathStack: this.navPathStack })
    }
    .onReady((context: NavDestinationContext) => {
      this.navPathStack = context.pathStack;
    })
  }
}
```

### Example 4

This example sets the **onMessage()** event callback.

```ts
// xxx.ets
import { AtomicServiceWeb, AtomicServiceWebController, OnMessageEvent } from '@kit.ArkUI';

@Entry
@Component
struct WebComponent {
  @State controller: AtomicServiceWebController = new AtomicServiceWebController();

  build() {
    Column() {
      AtomicServiceWeb({
        src: $rawfile("index.html"),
        controller: this.controller,
        // Called when the user clicks Send Message and then Back on an HTML5 page.
        onMessage: (event: OnMessageEvent) => {
          console.info(`[AtomicServiceWebLog] onMessage data = ${JSON.stringify(event.data)}`);
        }
      })
    }
  }
}
```

```html
// index.html
<!DOCTYPE html>
<html>
<meta charset="utf-8">
<!-- Import the JS SDK file. -->
<script src="../js/atomicservice-sdk.js" type="text/javascript"></script>
<body>
<h1>JS SDK - postMessage()</h1>
<br/>
<button type="button" onclick="postMessage({ name: 'Jerry', age: 18 });">Send Message</button>
<br/>
<button type="button" onclick="back();">Back</button>
</body>
<script type="text/javascript">
    function postMessage(data) {
        // API provided by the JS SDK for sending messages.
        has.asWeb.postMessage({
            data: data,
            callback: (err, res) => {
                if (err) {
                    console.error(`[AtomicServiceWebLog H5] postMessage error err. Code: ${err.code}, message: ${err.message}`);
                } else {
                    console.info(`[AtomicServiceWebLog H5] postMessage success res = ${JSON.stringify(res)}`);
                }
            }
        });
    }

    function back() {
        // Router API provided by the JS SDK for navigation back.
        has.router.back({
            delta: 1
        });
    }
</script>
</html>
```

### Example 5

This example sets the web page loading event callbacks.

```ts
// xxx.ets
import {
  AtomicServiceWeb,
  AtomicServiceWebController,
  OnErrorReceiveEvent,
  OnHttpErrorReceiveEvent,
  OnPageBeginEvent,
  OnPageEndEvent
} from '@kit.ArkUI';

@Entry
@Component
struct WebComponent {
  @State controller: AtomicServiceWebController = new AtomicServiceWebController();

  build() {
    Column() {
      AtomicServiceWeb({
        src: $rawfile('index.html'),
        controller: this.controller,
        // Invoked when an error occurs during web page loading.
        onErrorReceive: (event: OnErrorReceiveEvent) => {
          console.info(`AtomicServiceWebLog onErrorReceive event = ${JSON.stringify({
            requestUrl: event.request?.getRequestUrl(),
            requestMethod: event.request?.getRequestMethod(),
            errorCode: event.error?.getErrorCode(),
            errorInfo: event.error?.getErrorInfo()
          })}`);
        },
        // Invoked when an HTTP error occurs during web page resource loading.
        onHttpErrorReceive: (event: OnHttpErrorReceiveEvent) => {
          console.info(`AtomicServiceWebLog onHttpErrorReceive event = ${JSON.stringify({
            requestUrl: event.request?.getRequestUrl(),
            requestMethod: event.request?.getRequestMethod(),
            responseCode: event.response?.getResponseCode(),
            responseData: event.response?.getResponseData(),
          })}`);
        },
        // Invoked when the web page starts to be loaded.
        onPageBegin: (event: OnPageBeginEvent) => {
          console.info(`AtomicServiceWebLog onPageBegin event = ${JSON.stringify({
            url: event.url
          })}`);
        },
        // Invoked when loading of the web page is complete.
        onPageEnd: (event: OnPageEndEvent) => {
          console.info(`AtomicServiceWebLog onPageEnd event = ${JSON.stringify({
            url: event.url
          })}`);
        }
      })
    }
  }
}
```

### Example 6

This example demonstrates how to use **AtomicServiceWeb** and **AtomicServiceWebController**.

```ts
// xxx.ets
import {
  AtomicServiceWeb,
  AtomicServiceWebController,
  OnErrorReceiveEvent,
  OnHttpErrorReceiveEvent,
  OnPageBeginEvent,
  OnPageEndEvent,
  OnMessageEvent,
  OnLoadInterceptEvent,
  OnProgressChangeEvent
} from '@kit.ArkUI';

@Entry
@Component
struct WebComponent {
  @State darkMode: WebDarkMode = WebDarkMode.On;
  @State forceDarkAccess: boolean = true;
  @State mixedMode: MixedMode = MixedMode.None;
  @State controller: AtomicServiceWebController = new AtomicServiceWebController();
  @State num: number = 1;

  build() {
    Column() {
      Button('accessForward').onClick(() => {
        console.info(`AtomicServiceWebLog accessForward = ${this.controller.accessForward()}`);
      })
      Button('accessBackward').onClick(() => {
        console.info(`AtomicServiceWebLog accessBackward = ${this.controller.accessBackward()}`);
      })
      Button('accessStep').onClick(() => {
        console.info(`AtomicServiceWebLog accessStep = ${this.controller.accessStep(1)}`);
      })
      Button('forward').onClick(() => {
        console.info(`AtomicServiceWebLog forward = ${this.controller.forward()}`);
      })
      Button('backward').onClick(() => {
        console.info(`AtomicServiceWebLog backward = ${this.controller.backward()}`);
      })
      Button('refresh').onClick(() => {
        console.info(`AtomicServiceWebLog refresh = ${this.controller.refresh()}`);
      })
      Button('loadUrl').onClick(() => {
        console.info(`AtomicServiceWebLog loadUrl = ${this.controller.loadUrl('https://www.baidu.com/')}`);
      })
      Button('Dark Mode').onClick(() => {
        this.forceDarkAccess = !this.forceDarkAccess;
      })
      Button('mixedMode').onClick(() => {
        this.mixedMode = this.mixedMode == MixedMode.None ? MixedMode.All : MixedMode.None;
      })
      Button('Click').onClick(() => {
        console.info(`AtomicServiceWebLog getUserAgent = ${this.controller.getUserAgent()}`);
        console.info(`AtomicServiceWebLog getCustomUserAgent = ${this.controller.getCustomUserAgent()}`);
        this.controller.setCustomUserAgent('test' + this.num++);

        console.info(`AtomicServiceWebLog getUserAgent after set = ${this.controller.getUserAgent()}`);
        console.info(`AtomicServiceWebLog getCustomUserAgent after set = ${this.controller.getCustomUserAgent()}`);
      })
      AtomicServiceWeb({
        src: 'https://www.example.com',
        mixedMode: this.mixedMode,
        darkMode: this.darkMode,
        forceDarkAccess: this.forceDarkAccess,
        controller: this.controller,
        onControllerAttached: () => {
          console.info("AtomicServiceWebLog onControllerAttached call back success");
        },
        onLoadIntercept: (event: OnLoadInterceptEvent) => {
          console.info("AtomicServiceWebLog onLoadIntercept call back success " + JSON.stringify({
            getRequestUrl: event.data.getRequestUrl(),
            getRequestMethod: event.data.getRequestMethod(),
            getRequestHeader: event.data.getRequestHeader(),
            isRequestGesture: event.data.isRequestGesture(),
            isMainFrame: event.data.isMainFrame(),
            isRedirect: event.data.isRedirect(),
          }))
          return false;
        },
        onProgressChange: (event: OnProgressChangeEvent) => {
          console.info("AtomicServiceWebLog onProgressChange call back success " + JSON.stringify(event));
        },
        onMessage: (event: OnMessageEvent) => {
          console.info("onMessage call back success " + JSON.stringify(event));
        },
        onPageBegin: (event: OnPageBeginEvent) => {
          console.info("onPageBegin call back success " + JSON.stringify(event));
        },
        onPageEnd: (event: OnPageEndEvent) => {
          console.info("onPageEnd call back success " + JSON.stringify(event));
        },
        onHttpErrorReceive: (event: OnHttpErrorReceiveEvent) => {
          console.info("onHttpErrorReceive call back success " + JSON.stringify(event));
        },
        onErrorReceive: (event: OnErrorReceiveEvent) => {
          console.info("onErrorReceive call back success " + JSON.stringify(event));
        }
      })
    }
  }
}
```

### Example 7

This example shows how to set nested scrolling.

```ts
import { AtomicServiceWeb, AtomicServiceWebController } from '@kit.ArkUI';

@Entry
@Component
struct AtomicServiceNestedScroll {
  @State controller: AtomicServiceWebController = new AtomicServiceWebController();
  @State mode: string = 'PARALLEL mode (click to switch)';
  @State nestedScroll: NestedScrollOptions | NestedScrollOptionsExt = {
    scrollForward: NestedScrollMode.PARALLEL,
    scrollBackward: NestedScrollMode.PARALLEL
  };

  build() {
    Scroll() {
      Column() {
        Text("Nested Web - Header")
          .height("15%")
          .width("100%")
          .fontSize(30)
          .backgroundColor(Color.Yellow)
        Button(this.mode)
          .margin({ top: 10, bottom: 10 })
          .onClick(() => {
            if (!(this.nestedScroll as NestedScrollOptions).scrollForward) {
              this.mode = 'SELF_FIRST mode (click to switch)';
              this.nestedScroll = {
                scrollForward: NestedScrollMode.SELF_FIRST,
                scrollBackward: NestedScrollMode.SELF_FIRST
              }
            } else {
              this.mode = 'PARENT_FIRST mode (click to switch)';
              this.nestedScroll = {
                scrollUp: NestedScrollMode.PARENT_FIRST,
                scrollDown: NestedScrollMode.PARENT_FIRST
              }
            }
          })
        AtomicServiceWeb({
          src: 'https://www.example.com',
          controller: this.controller,
          nestedScroll: this.nestedScroll
        })
        Text("Nested Web - Footer")
          .height("15%")
          .width("100%")
          .fontSize(30)
          .backgroundColor(Color.Yellow)
      }
    }
  }
}
```
<!--no_check-->