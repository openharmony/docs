# Web

The **Web** component can be used to display web pages. It can be used with the [@ohos.web.webview](js-apis-webview.md) module, which provides APIs for web control.

> **NOTE**
>
> - This component is supported since API version 8. Updates will be marked with a superscript to indicate their earliest API version.
> - You can preview how this component looks on a real device, but not in DevEco Studio Previewer.

## Required Permissions

To use online resources, the application must have the **ohos.permission.INTERNET** permission. For details about how to apply for a permission, see [Declaring Permissions](../../security/AccessToken/declare-permissions.md).

## Child Components

Not supported

## APIs

Web(value: WebOptions)

> **NOTE**
>
> Transition animation is not supported.
>
> **Web** components on the same page must be bound to different **WebviewController** instances.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name       | Type                                    | Mandatory  | Description                                    |
| ---------- | ---------------------------------------- | ---- | ---------------------------------------- |
| value        | [WebOptions](#weboptions)   | Yes   | Web options.|

**Example**

Example of loading online web pages:

  ```ts
  // xxx.ets
  import { webview } from '@kit.ArkWeb';

  @Entry
  @Component
  struct WebComponent {
    controller: webview.WebviewController = new webview.WebviewController();

    build() {
      Column() {
        Web({ src: 'www.example.com', controller: this.controller })
      }
    }
  }
  ```

Example of loading online web pages in incognito mode:

  ```ts
  // xxx.ets
  import { webview } from '@kit.ArkWeb';

  @Entry
  @Component
  struct WebComponent {
    controller: webview.WebviewController = new webview.WebviewController();

    build() {
      Column() {
        Web({ src: 'www.example.com', controller: this.controller, incognitoMode: true })
      }
    }
  }
  ```

Example of rendering the **Web** component in synchronous mode:

  ```ts
  // xxx.ets
  import { webview } from '@kit.ArkWeb';

  @Entry
  @Component
  struct WebComponent {
    controller: webview.WebviewController = new webview.WebviewController();

    build() {
      Column() {
        Web({ src: 'www.example.com', controller: this.controller, renderMode: RenderMode.SYNC_RENDER })
      }
    }
  }
  ```

Example of using the **Web** component to specify the shared rendering process.

  ```ts
  // xxx.ets
  import { webview } from '@kit.ArkWeb';

  @Entry
  @Component
  struct WebComponent {
    controller: webview.WebviewController = new webview.WebviewController();

    build() {
      Column() {
        Web({ src: 'www.example.com', controller: this.controller, sharedRenderProcessToken: "111" })
        Web({ src: 'www.w3.org', controller: this.controller, sharedRenderProcessToken: "111" })
      }
    }
  }
  ```

Example of loading local web pages using **$rawfile()**:


  ```ts
  // xxx.ets
  import { webview } from '@kit.ArkWeb';

  @Entry
  @Component
  struct WebComponent {
    controller: webview.WebviewController = new webview.WebviewController();

    build() {
      Column() {
        // Load a local resource file through $rawfile.
        Web({ src: $rawfile("index.html"), controller: this.controller })
      }
    }
  }
  ```

The following is an example of loading a link with the hash (#) route through the resource protocol in Webview.

When **$rawfile** is used to load a URL contains a number sign (#), the content following the number sign is treated as a fragment. To avoid this issue, you can use the **resource://rawfile/** protocol prefix instead.  
  ```ts
  // xxx.ets
  import { webview } from '@kit.ArkWeb';

  @Entry
  @Component
  struct WebComponent {
    controller: webview.WebviewController = new webview.WebviewController();

    build() {
      Column() {
        // Load a local resource file through the resource protocol.
        Web({ src: "resource://rawfile/index.html#home", controller: this.controller })
      }
    }
  }
  ```

Create the **index.html** file in **src/main/resources/rawfile**.
```html
<!-- index.html -->
<!DOCTYPE html>
<html>
<body>
<div id="content"></div>

<script>
	function loadContent() {
	  var hash = window.location.hash;
	  var contentDiv = document.getElementById('content');

	  if (hash === '#home') {
		contentDiv.innerHTML = '<h1>Home Page</h1><p>Welcome to the Home Page!</p>';
	  } else {
		contentDiv.innerHTML = '<h1>Default Page</h1><p>This is the default content.</p>';
	  }
	}

	// Load the UI.
	window.addEventListener('load', loadContent);

	// Update the UI when the hash changes.
	window.addEventListener('hashchange', loadContent);
</script>
</body>
</html>
```

To load the local resource file in the sandbox path, you need to configure the [fileAccess](./ts-basic-components-web-attributes.md#fileaccess) permission of the file system in the application.

1. Obtain the sandbox path through the constructed singleton object **GlobalContext**.

   ```ts
   // GlobalContext.ets
   export class GlobalContext {
     private constructor() {}
     private static instance: GlobalContext;
     private _objects = new Map<string, Object>();

     public static getContext(): GlobalContext {
       if (!GlobalContext.instance) {
         GlobalContext.instance = new GlobalContext();
       }
       return GlobalContext.instance;
     }

     getObject(value: string): Object | undefined {
       return this._objects.get(value);
     }

     setObject(key: string, objectClass: Object): void {
       this._objects.set(key, objectClass);
     }
   }
   ```

   ```ts
   // xxx.ets
   import { webview } from '@kit.ArkWeb';
   import { GlobalContext } from '../GlobalContext';

   let url = 'file://' + GlobalContext.getContext().getObject("filesDir") + '/index.html';

   @Entry
   @Component
   struct WebComponent {
     controller: webview.WebviewController = new webview.WebviewController();

     build() {
       Column() {
         // Load the files in the sandbox.
         Web({ src: url, controller: this.controller })
         .fileAccess(true)
       }
     }
   }
   ```

2. Modify the **EntryAbility.ets** file.

   The following uses **filesDir** as an example to describe how to obtain the path of the sandbox. For details about how to obtain other paths, see [Obtaining Application File Paths](../../application-models/application-context-stage.md#obtaining-application-file-paths).

   ```ts
   // xxx.ets
   import { AbilityConstant, UIAbility, Want } from '@kit.AbilityKit';
   import { webview } from '@kit.ArkWeb';
   import { GlobalContext } from '../GlobalContext';

   export default class EntryAbility extends UIAbility {
     onCreate(want: Want, launchParam: AbilityConstant.LaunchParam) {
       // Data synchronization between the UIAbility component and UI can be implemented by binding filesDir to the GlobalContext object.
       GlobalContext.getContext().setObject("filesDir", this.context.filesDir);
       console.log("Sandbox path is " + GlobalContext.getContext().getObject("filesDir"));
     }
   }
   ```

   HTML file to be loaded:

   ```html
   <!-- index.html -->
   <!DOCTYPE html>
   <html>
       <body>
           <p>Hello World</p>
       </body>
   </html>
   ```

## WebOptions

Define web options through [APIs](#apis).

**System capability**: SystemCapability.Web.Webview.Core

| Name       | Type                                    | Mandatory  | Description                                    |
| ---------- | ---------------------------------------- | ---- | ---------------------------------------- |
| src        | string \| [Resource](../apis-arkui/arkui-ts/ts-types.md#resource)   | Yes   | Address of a web page resource. To access local resource files, use the **$rawfile** or **resource** protocol. To load a local resource file (in HTML or TXT format) in the sandbox outside of the application package, use **file://** to specify the path of the sandbox.<br>**src** cannot be dynamically changed through a state variable (for example, @State). To change the value, call [loadUrl()](./js-apis-webview-WebviewController.md#loadurl).|
| controller | [WebController](#webcontroller) \| [WebviewController<sup>9+</sup>](#webviewcontroller9)  | Yes   | The controller that controls various behaviors of **Web** components, including page navigation, declaration period status, and JavaScript interaction. This API is deprecated since API version 9. You are advised to use **WebviewController** instead.|
| renderMode<sup>12+</sup> | [RenderMode](./ts-basic-components-web-e.md#rendermode12)| No  | Rendering mode.<br>**RenderMode.ASYNC_RENDER** (default, cannot be dynamically adjusted): The **Web** component is rendered asynchronously.<br>**RenderMode.SYNC_RENDER**: The **Web** component is rendered synchronously within the current execution context.|
| incognitoMode<sup>11+</sup> | boolean | No| Whether to enable incognito mode. The value **true** means to enable incognito mode, and **false** means the opposite.<br> The default value is **false**.|
| sharedRenderProcessToken<sup>12+</sup> | string | No| The token of the shared rendering process specified by the **Web** component. In multi-rendering process mode, the **Web** component with the same token preferentially attempts to reuse the rendering process bound to the token. The token is bound to the rendering process when the rendering process is initialized. When the rendering process is not associated with a **Web** component, its binding to the token is removed.<br> Default value: **""** |

## WebviewController<sup>9+</sup>

type WebviewController = WebviewController

Provides methods for the web controller.

**System capability**: SystemCapability.Web.Webview.Core

| Type    | Description      |
| ------ | ---------- |
| [WebviewController](./js-apis-webview-WebviewController.md#class-webviewcontroller)  | Implements a **WebviewController** to control the behavior of the **Web** component. A **WebviewController** object can control only one **Web** component. Methods (except static methods) on the **WebviewController** can be called only after the **Web** component is bound to the **WebviewController**.|

## WebKeyboardController<sup>12+</sup>

Implements a controller to control the input, deletion, and closure of the custom keyboard. For details about the sample code, see [onInterceptKeyboardAttach](./ts-basic-components-web-events.md#oninterceptkeyboardattach12).

### constructor<sup>12+</sup>

constructor()

Constructs a **WebKeyboardController** API.

**System capability**: SystemCapability.Web.Webview.Core

### insertText<sup>12+</sup>

insertText(text: string): void

Inserts character into the **Web** component text box.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name| Type| Mandatory| Description|
| ------ | -------- | ---- | --------------------- |
| text | string | Yes| Character to insert into the **Web** component text box.|

### deleteForward<sup>12+</sup>

deleteForward(length: number): void

Deletes a specified number of characters forward in a **Web** component text box.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name| Type| Mandatory| Description                |
| ------ | -------- | ---- | ------------------------ |
| length | number   | Yes  | Length of characters to delete forward in a **Web** component text box.<br>The parameter has no value range. If the parameter value is greater than the character length, all characters before the cursor are deleted by default. If the parameter value is a negative number, the deletion is not performed.|

### deleteBackward12+</sup>

deleteBackward(length: number): void

Deletes a specified number of characters backward in a **Web** component text box.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name| Type| Mandatory| Description                |
| ------ | -------- | ---- | ------------------------ |
| length | number   | Yes  | Length of characters to delete backward in a **Web** component text box.<br>The parameter has no value range. If the parameter value is greater than the character length, all characters after the cursor are deleted by default. If the parameter value is a negative number, the deletion is not performed.|

### sendFunctionKey<sup>12+</sup>

sendFunctionKey(key: number): void

Inserts a function key. Currently, only the Enter key type is supported. For details about the value, see [EnterKeyType](../apis-ime-kit/js-apis-inputmethod.md#enterkeytype10).

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name| Type| Mandatory| Description                                  |
| ------ | -------- | ---- | ------------------------------------------ |
| key    | number   | Yes  | Function key to insert into the **Web** component text box. Currently, only the Enter key is supported.|

### close<sup>12+</sup>

close(): void

Closes this custom keyboard.

**System capability**: SystemCapability.Web.Webview.Core

## ConsoleMessage

Implements the **ConsoleMessage** object. For details about the sample code, see [onConsole](./ts-basic-components-web-events.md#onconsole).

### constructor

constructor(message: string, sourceId: string, lineNumber: number, messageLevel: MessageLevel)

Constructs a [ConsoleMessage](#consolemessage) object.

> **NOTE**
>
> This API is supported since API version 8 and deprecated since API version 9. You are advised to use [constructor](#constructor9) instead.

**System capability**: SystemCapability.Web.Webview.Core

### constructor<sup>9+</sup>

constructor()

Constructs a **ConsoleMessage** object.

**System capability**: SystemCapability.Web.Webview.Core

### getLineNumber

getLineNumber(): number

Obtains the number of lines of [ConsoleMessage](#consolemessage).

**System capability**: SystemCapability.Web.Webview.Core

**Return value**

| Type    | Description                  |
| ------ | -------------------- |
| number | Number of rows in the console message.|

### getMessage

getMessage(): string

Obtains the log information of this console message.

**System capability**: SystemCapability.Web.Webview.Core

**Return value**

| Type    | Description                    |
| ------ | ---------------------- |
| string | Log information of the console message.|

### getMessageLevel

getMessageLevel(): MessageLevel

Obtains the level of this console message.

**System capability**: SystemCapability.Web.Webview.Core

**Return value**

| Type                               | Description                    |
| --------------------------------- | ---------------------- |
| [MessageLevel](./ts-basic-components-web-e.md#messagelevel) | Level of the console message.|

### getSourceId

getSourceId(): string

Obtains the path and name of the web page source file.

**System capability**: SystemCapability.Web.Webview.Core

**Return value**

| Type    | Description           |
| ------ | ------------- |
| string | Path and name of the web page source file.|

## JsResult

Implements the **JsResult** object, which indicates the result returned to the **Web** component to indicate the user operation performed in the dialog box. For details about the sample code, see [onAlert] (./ts-basic-components-web-events.md#onalert).

### constructor

constructor()

Constructs a **JsResult** object.

**System capability**: SystemCapability.Web.Webview.Core

### handleCancel

handleCancel(): void

Notifies the **Web** component of the user's cancel operation in the dialog box.

**System capability**: SystemCapability.Web.Webview.Core

### handleConfirm

handleConfirm(): void

Notifies the **Web** component of the user's confirm operation in the dialog box.

**System capability**: SystemCapability.Web.Webview.Core

### handlePromptConfirm<sup>9+</sup>

handlePromptConfirm(result: string): void

Notifies the **Web** component of the user's confirm operation in the dialog box as well as the dialog box content.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name   | Type  | Mandatory  | Description       |
| ------ | ------ | ---- | ----------- |
| result | string | Yes   | User input in the dialog box.|

## FullScreenExitHandler<sup>9+</sup>

Implements a **FullScreenExitHandler** object for listening for exiting full screen mode. For details about the sample code, see [onFullScreenEnter](./ts-basic-components-web-events.md#onfullscreenenter9).

### constructor<sup>9+</sup>

constructor()

Constructs a **FullScreenExitHandler** API.

**System capability**: SystemCapability.Web.Webview.Core

### exitFullScreen<sup>9+</sup>

exitFullScreen(): void

Exits full screen mode.

**System capability**: SystemCapability.Web.Webview.Core

## ControllerHandler<sup>9+</sup>

Implements a **WebviewController** object for new **Web** components. For details about the sample code, see [onWindowNew](./ts-basic-components-web-events.md#onwindownew9).

**System capability**: SystemCapability.Web.Webview.Core

### constructor<sup>9+</sup>

constructor()

Constructs a **ControllerHandler** API.

**System capability**: SystemCapability.Web.Webview.Core

### setWebController<sup>9+</sup>

setWebController(controller: WebviewController): void

Sets a **WebviewController** object. If opening a new window is not needed, set the parameter to **null**.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name       | Type                                    | Mandatory| Description                                    |
| ---------- | ---------------------------------------- | ---- | ---------------------------------------- |
| controller | [WebviewController](./js-apis-webview-WebviewController.md#class-webviewcontroller) | Yes | **WebviewController** object of the **Web** component. If opening a new window is not needed, set it to **null**.|

## WebResourceError

Implements the **WebResourceError** object. For details about the sample code, see [onErrorReceive](./ts-basic-components-web-events.md#onerrorreceive).

### constructor

constructor()

Constructs a **WebResourceError** object.

**System capability**: SystemCapability.Web.Webview.Core

### getErrorCode

getErrorCode(): number

Obtains the error code for resource loading.

**System capability**: SystemCapability.Web.Webview.Core

**Return value**

| Type    | Description         |
| ------ | ----------- |
| number | Error code for resource loading. For details about error codes, see [WebNetErrorList](js-apis-netErrorList.md).|

### getErrorInfo

getErrorInfo(): string

Obtains error information about resource loading.

**System capability**: SystemCapability.Web.Webview.Core

**Return value**

| Type    | Description          |
| ------ | ------------ |
| string | Error information about resource loading.|

## WebResourceRequest

Implements the **WebResourceRequest** object. For details about the sample code, see [onErrorReceive](./ts-basic-components-web-events.md#onerrorreceive).

### constructor

constructor()

Constructs a **WebResourceRequest** object.

**System capability**: SystemCapability.Web.Webview.Core

### getRequestHeader

getRequestHeader(): Array\<Header\>

Obtains the information about the resource request header.

**System capability**: SystemCapability.Web.Webview.Core

**Return value**

| Type                        | Description        |
| -------------------------- | ---------- |
| Array\<[Header](#header)\> | Information about the resource request header.|

### getRequestUrl

getRequestUrl(): string

Obtains the URL of the resource request.

**System capability**: SystemCapability.Web.Webview.Core

**Return value**

| Type    | Description           |
| ------ | ------------- |
| string | URL of the resource request.|

### isMainFrame

isMainFrame(): boolean

Checks whether the resource request is in the main frame.

**System capability**: SystemCapability.Web.Webview.Core

**Return value**

| Type     | Description              |
| ------- | ---------------- |
| boolean | Whether the resource request is in the main frame.<br>The value **true** indicates that the resource request is in the main frame, and **false** indicates the opposite.|

### isRedirect

isRedirect(): boolean

Checks whether the resource request is redirected by the server.

**System capability**: SystemCapability.Web.Webview.Core

**Return value**

| Type     | Description              |
| ------- | ---------------- |
| boolean | Whether the resource request is redirected by the server.<br>The value **true** indicates that the resource request is redirected by the server, and **false** indicates the opposite.|

### isRequestGesture

isRequestGesture(): boolean

Checks whether the resource request is associated with a gesture (for example, a tap).

**System capability**: SystemCapability.Web.Webview.Core

**Return value**

| Type     | Description                  |
| ------- | -------------------- |
| boolean | Whether the resource request is associated with a gesture (for example, a tap).<br>The value **true** indicates that the resource request is associated with a gesture, and **false** indicates the opposite.|

### getRequestMethod<sup>9+</sup>

getRequestMethod(): string

Obtains the request method.

**System capability**: SystemCapability.Web.Webview.Core

**Return value**

| Type    | Description     |
| ------ | ------- |
| string | Request method.|

## Header

Describes the request/response header returned by the **Web** component.

**System capability**: SystemCapability.Web.Webview.Core

| Name         | Type    | Mandatory  | Description           |
| ----------- | ------ | ---- | ------------- |
| headerKey   | string | Yes   | Key of the request/response header.  |
| headerValue | string | Yes   | Value of the request/response header.|

## WebResourceResponse

Implements the **WebResourceResponse** object. For details about the sample code, see [onHttpErrorReceive](./ts-basic-components-web-events.md#onhttperrorreceive).

### constructor

constructor()

Constructs a **WebResourceResponse**.

**System capability**: SystemCapability.Web.Webview.Core

### getReasonMessage

getReasonMessage(): string

Obtains the status code description of the resource response.

**System capability**: SystemCapability.Web.Webview.Core

**Return value**

| Type    | Description           |
| ------ | ------------- |
| string | Status code description of the resource response.|

### getResponseCode

getResponseCode(): number

Obtains the status code of the resource response.

**System capability**: SystemCapability.Web.Webview.Core

**Return value**

| Type    | Description         |
| ------ | ----------- |
| number | Status code of the resource response.|

### getResponseData

getResponseData(): string

Obtains the data in the resource response.

**System capability**: SystemCapability.Web.Webview.Core

**Return value**

| Type    | Description       |
| ------ | --------- |
| string | Data in the resource response.|

### getResponseEncoding

getResponseEncoding(): string

Obtains the encoding string of the resource response.

**System capability**: SystemCapability.Web.Webview.Core

**Return value**

| Type    | Description        |
| ------ | ---------- |
| string | Encoding string of the resource response.|

### getResponseHeader

getResponseHeader() : Array\<Header\>

Obtains the resource response header.

**System capability**: SystemCapability.Web.Webview.Core

**Return value**

| Type                        | Description      |
| -------------------------- | -------- |
| Array\<[Header](#header)\> | Resource response header.|

### getResponseMimeType

getResponseMimeType(): string

Obtains the MIME type of the resource response.

**System capability**: SystemCapability.Web.Webview.Core

**Return value**

| Type    | Description                |
| ------ | ------------------ |
| string | MIME type of the resource response.|

### getResponseDataEx<sup>13+</sup>

getResponseDataEx(): string | number | ArrayBuffer | Resource | undefined

Obtains the data in the resource response. Multiple data types are supported.

**System capability**: SystemCapability.Web.Webview.Core

**Return value**

|Type|Description|
|---|---|
|string|String in HTML format.|
|number|Handle to the file.|
|ArrayBuffer|Binary data.|
|[Resource](../apis-arkui/arkui-ts/ts-types.md)|Resource referenced by **$rawfile()**.|
|undefined|No available data.|

### getResponseIsReady<sup>13+</sup>

getResponseIsReady(): boolean

Obtains whether the response data is ready.

**System capability**: SystemCapability.Web.Webview.Core

**Return value**

|Type|Description|
|---|---|
|boolean|**true** indicates that the response data is ready, and **false** indicates that the response data is not ready.|

### setResponseData<sup>9+</sup>

setResponseData(data: string \| number \| Resource \| ArrayBuffer): void

Sets the data in the resource response.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name | Type                                    | Mandatory  | Description                                    |
| ---- | ---------------------------------------- | ---- | ---------------------------------------- |
| data | string \| number \| [Resource](../apis-arkui/arkui-ts/ts-types.md)<sup>10+</sup> \| ArrayBuffer<sup>11+</sup> | Yes   | Resource response data to set. When set to a string, the value indicates a string in HTML format. When set to a number, the value indicates a file handle, which is closed by the system **Web** component. When set to a **Resource** object, the value indicates the file resources in the **rawfile** directory of the application. When set to an **ArrayBuffer** object, the value indicates the original binary data of a resource.|

### setResponseEncoding<sup>9+</sup>

setResponseEncoding(encoding: string): void

Sets the encoding string of the resource response.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name     | Type  | Mandatory  | Description        |
| -------- | ------ | ---- | ------------ |
| encoding | string | Yes   | Encoding string to set.|

### setResponseMimeType<sup>9+</sup>

setResponseMimeType(mimeType: string): void

Sets the MIME type of the resource response.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name     | Type  | Mandatory  | Description                |
| -------- | ------ | ---- | -------------------- |
| mimeType | string | Yes  | MIME type to set.|

### setReasonMessage<sup>9+</sup>

setReasonMessage(reason: string): void

Sets the status code description of the resource response.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name   | Type  | Mandatory  | Description           |
| ------ | ------ | ---- | --------------- |
| reason | string | Yes  | Status code description to set.|

### setResponseHeader<sup>9+</sup>

setResponseHeader(header: Array\<Header\>): void

Sets the resource response header.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name   | Type                      | Mandatory  | Description      |
| ------ | -------------------------- | ---- | ---------- |
| header | Array\<[Header](#header)\> | Yes  | Resource response header to set.|

### setResponseCode<sup>9+</sup>

setResponseCode(code: number): void

Sets the status code of the resource response.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name | Type  | Mandatory  | Description         |
| ---- | ------ | ---- | ------------- |
| code | number | Yes  | Status code to set. If the resource ends with an error, set the error code by referring to [@ohos.web.netErrorList](js-apis-netErrorList.md). Do not set the error code to **ERR_IO_PENDING**, which may block the synchronous **XMLHttpRequest**.|

### setResponseIsReady<sup>9+</sup>

setResponseIsReady(IsReady: boolean): void

Sets whether the resource response data is ready.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name  | Type   | Mandatory | Description         |
| ------- | ------- | ---- | ------------- |
| IsReady | boolean | Yes  | Whether the resource response data is ready.<br>The value **true** indicates that the resource response data is ready, and **false** indicates the opposite. Default value: **true**|

## FileSelectorResult<sup>9+</sup>

Notifies the **Web** component of the file selection result. For details about the sample code, see [onShowFileSelector](./ts-basic-components-web-events.md#onshowfileselector9).

### constructor<sup>9+</sup>

constructor()

Constructs a **FileSelectorResult**.

**System capability**: SystemCapability.Web.Webview.Core

### handleFileList<sup>9+</sup>

handleFileList(fileList: Array\<string\>): void

Instructs the **Web** component to select a file.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name     | Type           | Mandatory | Description        |
| -------- | --------------- | ---- | ------------ |
| fileList | Array\<string\> | Yes  | List of files to operate.|

## FileSelectorParam<sup>9+</sup>

Implements the **FileSelectorParam** object. For details about the sample code, see [onShowFileSelector](./ts-basic-components-web-events.md#onshowfileselector9).

### constructor<sup>9+</sup>

constructor()

Constructs a **FileSelectorParam**.

**System capability**: SystemCapability.Web.Webview.Core

### getTitle<sup>9+</sup>

getTitle(): string

Obtains the title of this file selector.

**System capability**: SystemCapability.Web.Webview.Core

**Return value**

| Type    | Description        |
| ------ | ---------- |
| string | Title of the file selector.|

### getMode<sup>9+</sup>

getMode(): FileSelectorMode

Obtains the mode of the file selector.

**System capability**: SystemCapability.Web.Webview.Core

**Return value**

| Type                                      | Description         |
| ---------------------------------------- | ----------- |
| [FileSelectorMode](./ts-basic-components-web-e.md#fileselectormode9) | Mode of the file selector.|

### getAcceptType<sup>9+</sup>

getAcceptType(): Array\<string\>

Obtains the file filtering type.

**System capability**: SystemCapability.Web.Webview.Core

**Return value**

| Type             | Description       |
| --------------- | --------- |
| Array\<string\> | File filtering type.|

### isCapture<sup>9+</sup>

isCapture(): boolean

Checks whether multimedia capabilities are invoked.

**System capability**: SystemCapability.Web.Webview.Core

**Return value**

| Type     | Description          |
| ------- | ------------ |
| boolean | Whether multimedia capabilities are invoked.<br>The value **true** indicates that multimedia capabilities are invoked, and **false** indicates the opposite.|

### getMimeTypes<sup>18+</sup>

getMimeTypes(): Array\<string\>

Obtains the MIME type of a file.

**System capability**: SystemCapability.Web.Webview.Core

**Return value**

| Type             | Description       |
| --------------- | --------- |
| Array\<string\> | MIME type of a file.|

## HttpAuthHandler<sup>9+</sup>

Implements the **HttpAuthHandler** object. For details about the sample code, see [onHttpAuthRequest](./ts-basic-components-web-events.md#onhttpauthrequest9).

### constructor<sup>9+</sup>

constructor()

Constructs an **HttpAuthHandler**.

**System capability**: SystemCapability.Web.Webview.Core

### cancel<sup>9+</sup>

cancel(): void

Cancels HTTP authentication as requested by the user.

**System capability**: SystemCapability.Web.Webview.Core

### confirm<sup>9+</sup>

confirm(userName: string, password: string): boolean

Performs HTTP authentication with the user name and password provided by the user.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name     | Type  | Mandatory | Description      |
| -------- | ------ | ---- | ---------- |
| userName | string | Yes  | HTTP authentication user name.|
| password      | string | Yes  | HTTP authentication password. |

**Return value**

| Type     | Description                   |
| ------- | --------------------- |
| boolean | Returns **true** if the authentication is successful; returns **false** otherwise.|

### isHttpAuthInfoSaved<sup>9+</sup>

isHttpAuthInfoSaved(): boolean

Sets whether to use the account name and password cached on the server for authentication.

**System capability**: SystemCapability.Web.Webview.Core

**Return value**

| Type     | Description                       |
| ------- | ------------------------- |
| boolean | Returns **true** if the authentication is successful; returns **false** otherwise.|

## SslErrorHandler<sup>9+</sup>

Implements an **SslErrorHandler** object. For details about the sample code, see [onSslErrorEventReceive](./ts-basic-components-web-events.md#onsslerroreventreceive9).

### constructor<sup>9+</sup>

constructor()

Constructs a **SslErrorHandler**.

**System capability**: SystemCapability.Web.Webview.Core

### handleCancel<sup>9+</sup>

handleCancel(): void

Cancels this request.

**System capability**: SystemCapability.Web.Webview.Core

### handleConfirm<sup>9+</sup>

handleConfirm(): void

Continues using the SSL certificate.

**System capability**: SystemCapability.Web.Webview.Core

## ClientAuthenticationHandler<sup>9+</sup>

Implements a **ClientAuthenticationHandler** object returned by the **Web** component. For details about the sample code, see [onClientAuthenticationRequest](./ts-basic-components-web-events.md#onclientauthenticationrequest9).

### constructor<sup>9+</sup>

constructor()

Constructs a **ClientAuthenticationHandler**.

**System capability**: SystemCapability.Web.Webview.Core

### confirm<sup>9+</sup>

confirm(priKeyFile : string, certChainFile : string): void

Uses the specified private key and client certificate chain.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name          | Type  | Mandatory  | Description              |
| ------------- | ------ | ---- | ------------------ |
| priKeyFile    | string | Yes   | Full path for storing the private key file. |
| certChainFile | string | Yes   | Full path for storing the certificate chain file.|

### confirm<sup>10+</sup>

confirm(authUri : string): void

Instructs the **Web** component to use the specified credentials (obtained from the certificate management module).

> **NOTE**
>
> The **ohos.permission.ACCESS_CERT_MANAGER** permission must be declared.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name    | Type  | Mandatory  | Description   |
| ------- | ------ | ---- | ------- |
| authUri | string | Yes   | Key value of the credentials.|

### cancel<sup>9+</sup>

cancel(): void

Cancels the client certificate request sent by the same host and port server. No additional event will be reported for requests from the same host and port server.

**System capability**: SystemCapability.Web.Webview.Core

### ignore<sup>9+</sup>

ignore(): void

Ignores this request.

**System capability**: SystemCapability.Web.Webview.Core

## PermissionRequest<sup>9+</sup>

Implements the **PermissionRequest** object. For details about the sample code, see [onPermissionRequest](./ts-basic-components-web-events.md#onpermissionrequest9).

### constructor<sup>9+</sup>

constructor()

Constructs a **PermissionRequest** object.

**System capability**: SystemCapability.Web.Webview.Core

### deny<sup>9+</sup>

deny(): void

Denies the permission requested by the web page.

**System capability**: SystemCapability.Web.Webview.Core

### getOrigin<sup>9+</sup>

getOrigin(): string

Obtains the origin of this web page.

**System capability**: SystemCapability.Web.Webview.Core

**Return value**

| Type    | Description          |
| ------ | ------------ |
| string | Origin of the web page that requests the permission.|

### getAccessibleResource<sup>9+</sup>

getAccessibleResource(): Array\<string\>

Obtains the list of accessible resources requested for the web page. For details about the resource types, see [ProtectedResourceType](./ts-basic-components-web-e.md#protectedresourcetype9).

**System capability**: SystemCapability.Web.Webview.Core

**Return value**

| Type             | Description           |
| --------------- | ------------- |
| Array\<string\> | List of accessible resources requested by the web page.|

### grant<sup>9+</sup>

grant(resources: Array\<string\>): void

Grants the permission for resources requested by the web page.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name      | Type           | Mandatory  | Description           |
| --------- | --------------- | ---- | --------------- |
| resources | Array\<string\> | Yes  | List of resources that can be requested by the web page with the permission to grant.|

## ScreenCaptureHandler<sup>10+</sup>

Implements the **ScreenCaptureHandler** object for accepting or rejecting a screen capture request. For details about the sample code, see [onScreenCaptureRequest](./ts-basic-components-web-events.md#onscreencapturerequest10).

### constructor<sup>10+</sup>

constructor()

Constructs a **ScreenCaptureHandler** object.

**System capability**: SystemCapability.Web.Webview.Core

### deny<sup>10+</sup>

deny(): void

Rejects this screen capture request.

**System capability**: SystemCapability.Web.Webview.Core

### getOrigin<sup>10+</sup>

getOrigin(): string

Obtains the origin of this web page.

**System capability**: SystemCapability.Web.Webview.Core

**Return value**

| Type    | Description          |
| ------ | ------------ |
| string | Origin of the web page that requests the permission.|

### grant<sup>10+</sup>

grant(config: ScreenCaptureConfig): void

Grants the screen capture permission.

> **NOTE**
>
> The **ohos.permission.MICROPHONE** permission must be declared.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name   | Type                                    | Mandatory  | Description   |
| ------ | ---------------------------------------- | ---- | ------- |
| config | [ScreenCaptureConfig](#screencaptureconfig10) | Yes  | Screen capture configuration.|

## EventResult<sup>12+</sup>

Represents the event consumption result sent to the **Web** component. For details about the supported events, see [TouchType](../apis-arkui/arkui-ts/ts-appendix-enums.md#touchtype). If the application does not consume the event, set this parameter to **false**, and the event will be consumed by the **Web** component. If the application has consumed the event, set this parameter to **true**, and the event will not be consumed by the **Web** component. For details about the sample code, see [onNativeEmbedGestureEvent](./ts-basic-components-web-events.md#onnativeembedgestureevent11).

### constructor<sup>12+</sup>

constructor()

Constructs a **EventResult** object.

**System capability**: SystemCapability.Web.Webview.Core

### setGestureEventResult<sup>12+</sup>

setGestureEventResult(result: boolean): void

Sets the gesture event consumption result.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name         | Type| Mandatory | Description            |
| --------------- | -------- | ----  |------- |
| result          | boolean  | Yes   | Whether to consume the gesture event.<br>The value **true** means to consume the gesture event, and **false** means the opposite. Default value: **true**|

**Example**

For details, see [onNativeEmbedGestureEvent](./ts-basic-components-web-events.md#onnativeembedgestureevent11).

### setGestureEventResult<sup>14+</sup>

setGestureEventResult(result: boolean, stopPropagation: boolean): void

Sets the gesture event consumption result.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name         | Type| Mandatory | Description            |
| --------------- | -------- | ----  |------- |
| result          | boolean  | Yes   | Whether the gesture event is consumed.<br>The value **true** means that the gesture event is consumed, and **false** means the opposite.<br>Default value: **true**|
| stopPropagation | boolean  | Yes  | Whether to stop propagation. This parameter is valid only when **result** is set to **true**.<br>The value **true** means to stop propagation, and **false** means the opposite.<br>Default value: **true**|

**Example**

For details, see [onNativeEmbedGestureEvent](./ts-basic-components-web-events.md#onnativeembedgestureevent11).

## WebContextMenuParam<sup>9+</sup>

Implements a context menu, which is displayed after the user clicks the right mouse button or long presses a specific element, such as an image or a link. For details about the sample code, see [onContextMenuShow](./ts-basic-components-web-events.md#oncontextmenushow9).

### constructor<sup>9+</sup>

constructor()

Constructs a **WebContextMenuParam** object.

**System capability**: SystemCapability.Web.Webview.Core

### x<sup>9+</sup>

x(): number

Obtains the X coordinate of the context menu.

**System capability**: SystemCapability.Web.Webview.Core

**Return value**

| Type    | Description                |
| ------ | ------------------ |
| number | If the display is normal, a non-negative integer is returned. Otherwise, **-1** is returned.<br>Unit: vp|

### y<sup>9+</sup>

y(): number

Obtains the Y coordinate of the context menu.

**System capability**: SystemCapability.Web.Webview.Core

**Return value**

| Type    | Description                |
| ------ | ------------------ |
| number | If the display is normal, a non-negative integer is returned. Otherwise, **-1** is returned.<br>Unit: vp|

### getLinkUrl<sup>9+</sup>

getLinkUrl(): string

Obtains the URL of the destination link.

**System capability**: SystemCapability.Web.Webview.Core

**Return value**

| Type    | Description                       |
| ------ | ------------------------- |
| string | If it is a link that is being long pressed, the URL that has passed the security check is returned.|

### getUnfilteredLinkUrl<sup>9+</sup>

getUnfilteredLinkUrl(): string

Obtains the URL of the destination link.

**System capability**: SystemCapability.Web.Webview.Core

**Return value**

| Type    | Description                   |
| ------ | --------------------- |
| string | If it is a link that is being long pressed, the original URL is returned.|

### getSourceUrl<sup>9+</sup>

getSourceUrl(): string

Obtain the source URL.

**System capability**: SystemCapability.Web.Webview.Core

**Return value**

| Type    | Description                      |
| ------ | ------------------------ |
| string | If the selected element has the **src** attribute, the URL in the **src** is returned.|

### existsImageContents<sup>9+</sup>

existsImageContents(): boolean

Checks whether image content exists.

**System capability**: SystemCapability.Web.Webview.Core

**Return value**

| Type     | Description                       |
| ------- | ------------------------- |
| boolean | The value **true** means that there is image content in the element being long pressed, and **false** means the opposite.|

### getMediaType<sup>9+</sup>

getMediaType(): ContextMenuMediaType

Obtains the media type of this web page element.

**System capability**: SystemCapability.Web.Webview.Core

**Return value**

| Type                                      | Description       |
| ---------------------------------------- | --------- |
| [ContextMenuMediaType](./ts-basic-components-web-e.md#contextmenumediatype9) | Media type of the web page element.|

### getSelectionText<sup>9+</sup>

getSelectionText(): string

Obtains the selected text.

**System capability**: SystemCapability.Web.Webview.Core

**Return value**

| Type    | Description                  |
| ------ | -------------------- |
| string | Selected text for the context menu. If no text is selected, null is returned.|

### getSourceType<sup>9+</sup>

getSourceType(): ContextMenuSourceType

Obtains the event source of the context menu.

**System capability**: SystemCapability.Web.Webview.Core

**Return value**

| Type                                      | Description     |
| ---------------------------------------- | ------- |
| [ContextMenuSourceType](./ts-basic-components-web-e.md#contextmenusourcetype9) | Event source of the context menu.|

### getInputFieldType<sup>9+</sup>

getInputFieldType(): ContextMenuInputFieldType

Obtains the input field type of this web page element.

**System capability**: SystemCapability.Web.Webview.Core

**Return value**

| Type                                      | Description    |
| ---------------------------------------- | ------ |
| [ContextMenuInputFieldType](./ts-basic-components-web-e.md#contextmenuinputfieldtype9) | Input field type.|

### isEditable<sup>9+</sup>

isEditable(): boolean

Checks whether this web page element is editable.

**System capability**: SystemCapability.Web.Webview.Core

**Return value**

| Type     | Description                        |
| ------- | -------------------------- |
| boolean | Returns **true** if the web page element is editable; returns **false** otherwise.|

### getEditStateFlags<sup>9+</sup>

getEditStateFlags(): number

Obtains the edit state flag of this web page element.

**System capability**: SystemCapability.Web.Webview.Core

**Return value**

| Type    | Description                                      |
| ------ | ---------------------------------------- |
| number | Edit state flag of the web page element. For details, see [ContextMenuEditStateFlags](./ts-basic-components-web-e.md#contextmenueditstateflags9).|

### getPreviewWidth<sup>13+</sup>

getPreviewWidth(): number

Obtains the width of a preview image.

**System capability**: SystemCapability.Web.Webview.Core

**Return value**

| Type    | Description      |
| ------ | ----------- |
| number | Width of a preview image.<br>Unit: vp|

### getPreviewHeight<sup>13+</sup>

getPreviewHeight(): number

Obtains the height of a preview image.

**System capability**: SystemCapability.Web.Webview.Core

**Return value**

| Type    | Description      |
| ------ | ----------  |
| number | Height of a preview image.<br>Unit: vp|

## WebContextMenuResult<sup>9+</sup>

Implements a **WebContextMenuResult** object. For details about the sample code, see [onContextMenuShow](./ts-basic-components-web-events.md#oncontextmenushow9).

### constructor<sup>9+</sup>

constructor()

Constructs a **WebContextMenuResult** object.

**System capability**: SystemCapability.Web.Webview.Core

### closeContextMenu<sup>9+</sup>

closeContextMenu(): void

Closes this context menu. This API must be called when no operations in **WebContextMenuResult** are performed.

**System capability**: SystemCapability.Web.Webview.Core

### copyImage<sup>9+</sup>

copyImage(): void

Copies the image specified in **WebContextMenuParam**.

**System capability**: SystemCapability.Web.Webview.Core

### copy<sup>9+</sup>

copy(): void

Copies text related to this context menu.

**System capability**: SystemCapability.Web.Webview.Core

### paste<sup>9+</sup>

paste(): void

Performs the paste operation related to this context menu.

> **NOTE**
>
> The **ohos.permission.READ_PASTEBOARD** permission must be declared.

**System capability**: SystemCapability.Web.Webview.Core

### cut<sup>9+</sup>

cut(): void

Performs the cut operation related to this context menu.

**System capability**: SystemCapability.Web.Webview.Core

### selectAll<sup>9+</sup>

selectAll(): void

Performs the select all operation related to this context menu.

**System capability**: SystemCapability.Web.Webview.Core

## JsGeolocation

Implements the **PermissionRequest** object. For details about the sample code, see [onGeolocationShow](./ts-basic-components-web-events.md#ongeolocationshow).

### constructor

constructor()

Constructs a **JsGeolocation** object.

**System capability**: SystemCapability.Web.Webview.Core

### invoke

invoke(origin: string, allow: boolean, retain: boolean): void

Sets the geolocation permission status of a web page.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name   | Type   | Mandatory | Description                                    |
| ------ | ------- | ---- | ---------------------------------------- |
| origin | string  | Yes  | Index of the origin.                              |
| allow  | boolean | Yes  | Geolocation permission status.<br>The value **true** means to enable the geolocation permission, and **false** means the opposite.                            |
| retain | boolean | Yes  | Whether the geolocation permission status can be saved to the system. You can manage the geolocation permissions saved to the system through the [GeolocationPermissions<sup>9+</sup>](./js-apis-webview-GeolocationPermissions.md#class-geolocationpermissions) API.<br>The value **true** indicates that the geolocation permission status can be saved to the system, and **false** indicates the opposite.|

## ScreenCaptureConfig<sup>10+</sup>

Provides the web screen capture configuration.

**System capability**: SystemCapability.Web.Webview.Core

| Name         | Type                                     | Mandatory  | Description        |
| ----------- | --------------------------------------- | ---- | ---------- |
| captureMode | [WebCaptureMode](./ts-basic-components-web-e.md#webcapturemode10) | Yes   | Web screen capture mode.|

## DataResubmissionHandler<sup>9+</sup>

Implements the **DataResubmissionHandler** object for resubmitting or canceling the web form data.

### constructor<sup>9+</sup>

constructor()

Constructs a **DataResubmissionHandler** object.

**System capability**: SystemCapability.Web.Webview.Core

### resend<sup>9+</sup>

resend(): void

Resends the web form data.

**System capability**: SystemCapability.Web.Webview.Core

**Example**

  ```ts
  // xxx.ets
  import { webview } from '@kit.ArkWeb';

  @Entry
  @Component
  struct WebComponent {
    controller: webview.WebviewController = new webview.WebviewController();

    build() {
      Column() {
        Web({ src: 'www.example.com', controller: this.controller })
          .onDataResubmitted((event) => {
            console.log('onDataResubmitted');
            event.handler.resend();
          })
      }
    }
  }
  ```

### cancel<sup>9+</sup>

cancel(): void

Cancels the resending of web form data.

**System capability**: SystemCapability.Web.Webview.Core

**Example**

  ```ts
  // xxx.ets
  import { webview } from '@kit.ArkWeb';

  @Entry
  @Component
  struct WebComponent {
    controller: webview.WebviewController = new webview.WebviewController();

    build() {
      Column() {
        Web({ src: 'www.example.com', controller: this.controller })
          .onDataResubmitted((event) => {
            console.log('onDataResubmitted');
            event.handler.cancel();
          })
      }
    }
  }
  ```

## WebController

Implements a **WebController** to control the behavior of the **Web** component. A **WebController** can control only one **Web** component, and the APIs in the **WebController** can be invoked only after it has been bound to the target **Web** component.

This API is deprecated since API version 9. You are advised to use [WebviewController<sup>9+</sup>](./js-apis-webview-WebviewController.md#class-webviewcontroller) instead.

### Creating an Object

<!--deprecated_code_no_check-->
```ts
let webController: WebController = new WebController()
```

### constructor<sup>(deprecated)</sup>

constructor()

Constructs a **WebController** object.

> **NOTE**
>
> This API is supported since API version 8 and deprecated since API version 9. No API is provided for substitute.

**System capability**: SystemCapability.Web.Webview.Core

### getCookieManager<sup>(deprecated)</sup>

getCookieManager(): WebCookie

Obtains the cookie management object of the **Web** component.

This API is deprecated since API version 9. You are advised to use [getCookie](./js-apis-webview-WebCookieManager.md#getcookiedeprecated) instead.

**System capability**: SystemCapability.Web.Webview.Core

**Return value**

| Type       | Description                                      |
| --------- | ---------------------------------------- |
| WebCookie | Cookie management object. For details, see [WebCookie](#webcookie).|

**Example**

  ```ts
  // xxx.ets
  @Entry
  @Component
  struct WebComponent {
    controller: WebController = new WebController()

    build() {
      Column() {
        Button('getCookieManager')
          .onClick(() => {
            let cookieManager = this.controller.getCookieManager()
          })
        Web({ src: 'www.example.com', controller: this.controller })
      }
    }
  }
  ```

### requestFocus<sup>(deprecated)</sup>

requestFocus()

Requests focus for this web page.

This API is deprecated since API version 9. You are advised to use [requestFocus<sup>9+</sup>](./js-apis-webview-WebviewController.md#requestfocus) instead.

**System capability**: SystemCapability.Web.Webview.Core

**Example**

  ```ts
  // xxx.ets
  @Entry
  @Component
  struct WebComponent {
    controller: WebController = new WebController()

    build() {
      Column() {
        Button('requestFocus')
          .onClick(() => {
            this.controller.requestFocus()
          })
        Web({ src: 'www.example.com', controller: this.controller })
      }
    }
  }
  ```

### accessBackward<sup>(deprecated)</sup>

accessBackward(): boolean

Checks whether going to the previous page can be performed on the current page.

This API is deprecated since API version 9. You are advised to use [accessBackward<sup>9+</sup>](./js-apis-webview-WebviewController.md#accessbackward) instead.

**System capability**: SystemCapability.Web.Webview.Core

**Return value**

| Type     | Description                   |
| ------- | --------------------- |
| boolean | If going to the previous page can be performed on the current page, **true** is returned; otherwise, **false** is returned.|

**Example**

  ```ts
  // xxx.ets
  @Entry
  @Component
  struct WebComponent {
    controller: WebController = new WebController()

    build() {
      Column() {
        Button('accessBackward')
          .onClick(() => {
            let result = this.controller.accessBackward()
            console.log('result:' + result)
          })
        Web({ src: 'www.example.com', controller: this.controller })
      }
    }
  }
  ```

### accessForward<sup>(deprecated)</sup>

accessForward(): boolean

Checks whether going to the next page can be performed on the current page.

This API is deprecated since API version 9. You are advised to use [accessForward<sup>9+</sup>](./js-apis-webview-WebviewController.md#accessforward) instead.

**System capability**: SystemCapability.Web.Webview.Core

**Return value**

| Type     | Description                   |
| ------- | --------------------- |
| boolean | If going to the next page can be performed on the current page, **true** is returned; otherwise, **false** is returned.|

**Example**

  ```ts
  // xxx.ets
  @Entry
  @Component
  struct WebComponent {
    controller: WebController = new WebController()

    build() {
      Column() {
        Button('accessForward')
          .onClick(() => {
            let result = this.controller.accessForward()
            console.log('result:' + result)
          })
        Web({ src: 'www.example.com', controller: this.controller })
      }
    }
  }
  ```

### accessStep<sup>(deprecated)</sup>

accessStep(step: number): boolean

Performs a specific number of steps forward or backward from the current page.

This API is deprecated since API version 9. You are advised to use [accessStep<sup>9+</sup>](./js-apis-webview-WebviewController.md#accessstep) instead.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name | Type  | Mandatory | Description                 |
| ---- | ------ | ---- | --------------------- |
| step | number | Yes  | Number of the steps to take. A positive number means to go forward, and a negative number means to go backward.|

**Return value**

| Type     | Description       |
| ------- | --------- |
| boolean | Whether going forward or backward from the current page is successful.|

**Example**

  ```ts
  // xxx.ets
  @Entry
  @Component
  struct WebComponent {
    controller: WebController = new WebController()
    @State steps: number = 2

    build() {
      Column() {
        Button('accessStep')
          .onClick(() => {
            let result = this.controller.accessStep(this.steps)
            console.log('result:' + result)
          })
        Web({ src: 'www.example.com', controller: this.controller })
      }
    }
  }
  ```

### backward<sup>(deprecated)</sup>

backward()

Goes to the previous page based on the history stack. This API is generally used together with **accessBackward**.

This API is deprecated since API version 9. You are advised to use [backward<sup>9+</sup>](./js-apis-webview-WebviewController.md#backward) instead.

**System capability**: SystemCapability.Web.Webview.Core

**Example**

  ```ts
  // xxx.ets
  @Entry
  @Component
  struct WebComponent {
    controller: WebController = new WebController()

    build() {
      Column() {
        Button('backward')
          .onClick(() => {
            this.controller.backward()
          })
        Web({ src: 'www.example.com', controller: this.controller })
      }
    }
  }
  ```

### forward<sup>(deprecated)</sup>

forward()

Goes to the next page based on the history stack. This API is generally used together with **accessForward**.

This API is deprecated since API version 9. You are advised to use [forward<sup>9+</sup>](./js-apis-webview-WebviewController.md#forward) instead.

**System capability**: SystemCapability.Web.Webview.Core

**Example**

  ```ts
  // xxx.ets
  @Entry
  @Component
  struct WebComponent {
    controller: WebController = new WebController()

    build() {
      Column() {
        Button('forward')
          .onClick(() => {
            this.controller.forward()
          })
        Web({ src: 'www.example.com', controller: this.controller })
      }
    }
  }
  ```

### deleteJavaScriptRegister<sup>(deprecated)</sup>

deleteJavaScriptRegister(name: string)

Deletes a specific application JavaScript object that is registered with the window through **registerJavaScriptProxy**. The deletion takes effect immediately, with no need for invoking the [refresh](#refreshdeprecated) API.

This API is deprecated since API version 9. You are advised to use [deleteJavaScriptRegister<sup>9+</sup>](./js-apis-webview-WebviewController.md#deletejavascriptregister) instead.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name | Type  | Mandatory | Description                                    |
| ---- | ------ | ---- | ---------------------------------------- |
| name | string | Yes  | Name of the registered JavaScript object, which can be used to invoke the corresponding object on the application side from the web side.|

**Example**

  ```ts
  // xxx.ets
  @Entry
  @Component
  struct WebComponent {
    controller: WebController = new WebController()
    @State name: string = 'Object'

    build() {
      Column() {
        Button('deleteJavaScriptRegister')
          .onClick(() => {
            this.controller.deleteJavaScriptRegister(this.name)
          })
        Web({ src: 'www.example.com', controller: this.controller })
      }
    }
  }
  ```

### getHitTest<sup>(deprecated)</sup>

getHitTest(): HitTestType

Obtains the element type of the area being clicked.

This API is deprecated since API version 9. You are advised to use [getHitTest<sup>9+</sup>](./js-apis-webview-WebviewController.md#gethittestdeprecated) instead.

**System capability**: SystemCapability.Web.Webview.Core

**Return value**

| Type                             | Description         |
| ------------------------------- | ----------- |
| [HitTestType](./ts-basic-components-web-e.md#hittesttype) | Element type of the area being clicked.|

**Example**

  ```ts
  // xxx.ets
  @Entry
  @Component
  struct WebComponent {
    controller: WebController = new WebController()

    build() {
      Column() {
        Button('getHitTest')
          .onClick(() => {
            let hitType = this.controller.getHitTest()
            console.log("hitType: " + hitType)
          })
        Web({ src: 'www.example.com', controller: this.controller })
      }
    }
  }
  ```

### loadData<sup>(deprecated)</sup>

loadData(options: { data: string, mimeType: string, encoding: string, baseUrl?: string, historyUrl?: string })

Loads data. If **baseUrl** is empty, the specified character string will be loaded using the data protocol.

If **baseUrl** is set to a data URL, the encoded string will be loaded by the **Web** component using the data protocol.

If **baseUrl** is set to an HTTP or HTTPS URL, the encoded string will be processed by the **Web** component as a non-encoded string in a manner similar to **loadUrl**.

This API is deprecated since API version 9. You are advised to use [loadData<sup>9+</sup>](./js-apis-webview-WebviewController.md#loaddata) instead.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name       | Type  | Mandatory  | Description                                    |
| ---------- | ------ | ---- | ---------------------------------------- |
| data       | string | Yes  | Character string obtained after being Base64 or URL encoded.             |
| mimeType   | string | Yes  | Media type (MIME).                             |
| encoding   | string | Yes  | Encoding type, which can be Base64 or URL.               |
| baseUrl    | string | No  | URL (HTTP/HTTPS/data compliant), which is assigned by the **Web** component to **window.origin**.|
| historyUrl | string | No  | Historical record URL. If this parameter is not empty, it can be managed in historical records to implement page going backward and forward. This parameter is invalid when **baseUrl** is left empty.|

**Example**

  ```ts
  // xxx.ets
  @Entry
  @Component
  struct WebComponent {
    controller: WebController = new WebController()

    build() {
      Column() {
        Button('loadData')
          .onClick(() => {
            this.controller.loadData({
              data: "<html><body bgcolor=\"white\">Source:<pre>source</pre></body></html>",
              mimeType: "text/html",
              encoding: "UTF-8"
            })
          })
        Web({ src: 'www.example.com', controller: this.controller })
      }
    }
  }
  ```

### loadUrl<sup>(deprecated)</sup>

loadUrl(options: { url: string | Resource, headers?: Array\<Header\> })

Loads a URL using the specified HTTP header.

The object injected through **loadUrl** is valid only in the current document. It will be invalid on a new page navigated to through **loadUrl**.

The object injected through **registerJavaScriptProxy** is still valid on a new page redirected through **loadUrl**.

This API is deprecated since API version 9. You are advised to use [loadUrl<sup>9+</sup>](./js-apis-webview-WebviewController.md#loadurl) instead.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name    | Type                      | Mandatory | Description          |
| -------- | -------------------------- | ---- | -------------- |
| url      | string \| Resource                     | Yes | URL to load.    |
| headers  | Array\<[Header](#header)\> | No   | Additional HTTP request header of the URL.<br>The default value is **[]**.|

**Example**

  ```ts
  // xxx.ets
  @Entry
  @Component
  struct WebComponent {
    controller: WebController = new WebController()

    build() {
      Column() {
        Button('loadUrl')
          .onClick(() => {
            this.controller.loadUrl({ url: 'www.example.com' })
          })
        Web({ src: 'www.example.com', controller: this.controller })
      }
    }
  }
  ```

### onActive<sup>(deprecated)</sup>

onActive(): void

Called when the **Web** component enters the active state.

This API is deprecated since API version 9. You are advised to use [onActive<sup>9+</sup>](./js-apis-webview-WebviewController.md#onactive) instead.

**System capability**: SystemCapability.Web.Webview.Core

**Example**

  ```ts
  // xxx.ets
  @Entry
  @Component
  struct WebComponent {
    controller: WebController = new WebController()

    build() {
      Column() {
        Button('onActive')
          .onClick(() => {
            this.controller.onActive()
          })
        Web({ src: 'www.example.com', controller: this.controller })
      }
    }
  }
  ```

### onInactive<sup>(deprecated)</sup>

onInactive(): void

Called when the **Web** component enters the inactive state.

This API is deprecated since API version 9. You are advised to use [onInactive<sup>9+</sup>](./js-apis-webview-WebviewController.md#oninactive) instead.

**System capability**: SystemCapability.Web.Webview.Core

**Example**

  ```ts
  // xxx.ets
  @Entry
  @Component
  struct WebComponent {
    controller: WebController = new WebController()

    build() {
      Column() {
        Button('onInactive')
          .onClick(() => {
            this.controller.onInactive()
          })
        Web({ src: 'www.example.com', controller: this.controller })
      }
    }
  }
  ```

### zoom<sup>(deprecated)</sup>

zoom(factor: number): void

Sets a zoom factor for the current web page.

This API is deprecated since API version 9. You are advised to use [zoom<sup>9+</sup>](./js-apis-webview-WebviewController.md#zoom) instead.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name   | Type  | Mandatory  | Description                          |
| ------ | ------ | ---- | ------------------------------ |
| factor | number | Yes   | Zoom factor to set. A positive value indicates zoom-in, and a negative value indicates zoom-out.|

**Example**

  ```ts
  // xxx.ets
  @Entry
  @Component
  struct WebComponent {
    controller: WebController = new WebController()
    @State factor: number = 1

    build() {
      Column() {
        Button('zoom')
          .onClick(() => {
            this.controller.zoom(this.factor)
          })
        Web({ src: 'www.example.com', controller: this.controller })
      }
    }
  }
  ```

### refresh<sup>(deprecated)</sup>

refresh()

Called when the **Web** component refreshes the web page.

This API is deprecated since API version 9. You are advised to use [refresh<sup>9+</sup>](./js-apis-webview-WebviewController.md#refresh) instead.

**System capability**: SystemCapability.Web.Webview.Core

**Example**

  ```ts
  // xxx.ets
  @Entry
  @Component
  struct WebComponent {
    controller: WebController = new WebController()

    build() {
      Column() {
        Button('refresh')
          .onClick(() => {
            this.controller.refresh()
          })
        Web({ src: 'www.example.com', controller: this.controller })
      }
    }
  }
  ```

### registerJavaScriptProxy<sup>(deprecated)</sup>

registerJavaScriptProxy(options: { object: object, name: string, methodList: Array\<string\> })

Registers a JavaScript object with the window. APIs of this object can then be invoked in the window. You must invoke the [refresh](#refreshdeprecated) API for the registration to take effect.

This API is deprecated since API version 9. You are advised to use [registerJavaScriptProxy<sup>9+</sup>](./js-apis-webview-WebviewController.md#registerjavascriptproxy) instead.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name       | Type           | Mandatory | Description                                    |
| ---------- | --------------- | ---- | ---------------------------------------- |
| object     | object          | Yes   | Application-side JavaScript object to be registered. Methods and attributes can be declared, but cannot be directly called on HTML5. The parameters and return value can only be of the string, number, or Boolean type.|
| name       | string          | Yes   | Name of the object to be registered, which is the same as that invoked in the window. After registration, the window can use this name to access the JavaScript object at the application side.|
| methodList | Array\<string\> | Yes   | Methods of the JavaScript object to be registered at the application side.                |

**Example**

  ```ts
  // xxx.ets
  class TestObj {
    constructor() {
    }

    test(): string {
      return "ArkUI Web Component"
    }

    toString(): void {
      console.log('Web Component toString')
    }
  }

  @Entry
  @Component
  struct Index {
    controller: WebController = new WebController()
    testObj = new TestObj();
    build() {
      Column() {
        Row() {
          Button('Register JavaScript To Window').onClick(() => {
            this.controller.registerJavaScriptProxy({
              object: this.testObj,
              name: "objName",
              methodList: ["test", "toString"],
            })
          })
        }
        Web({ src: $rawfile('index.html'), controller: this.controller })
          .javaScriptAccess(true)
      }
    }
  }
  ```

  HTML file to be loaded:
  ```html
  <!-- index.html -->
  <!DOCTYPE html>
  <html>
      <meta charset="utf-8">
      <body>
          Hello world!
      </body>
      <script type="text/javascript">
      function htmlTest() {
          str = objName.test("test function")
          console.log('objName.test result:'+ str)
      }
  </script>
  </html>

  ```

### runJavaScript<sup>(deprecated)</sup>

runJavaScript(options: { script: string, callback?: (result: string) => void })

Executes a JavaScript script. This API uses an asynchronous callback to return the script execution result. **runJavaScript** can be invoked only after **loadUrl** is executed. For example, it can be invoked in **onPageEnd**.

This API is deprecated since API version 9. You are advised to use [runJavaScript<sup>9+</sup>](./js-apis-webview-WebviewController.md#runjavascript) instead.

**System capability**: SystemCapability.Web.Webview.Core

**Parameters**

| Name     | Type                    | Mandatory| Description                                    |
| -------- | ------------------------ | ---- | ---------------------------------------- |
| script   | string                   | Yes  | JavaScript script.                           |
| callback | (result: string) => void | No  | Callback used to return the result. Returns **null** if the JavaScript script fails to be executed or no value is returned.|

**Example**

  ```ts
  // xxx.ets
  @Entry
  @Component
  struct WebComponent {
    controller: WebController = new WebController()
    @State webResult: string = ''
    build() {
      Column() {
        Text(this.webResult).fontSize(20)
        Web({ src: $rawfile('index.html'), controller: this.controller })
        .javaScriptAccess(true)
        .onPageEnd((event) => {
          this.controller.runJavaScript({
            script: 'test()',
            callback: (result: string)=> {
              this.webResult = result
              console.info(`The test() return value is: ${result}`)
            }})
          if (event) {
            console.info('url: ', event.url)
          }
        })
      }
    }
  }
  ```
  HTML file to be loaded:
  ```html
  <!-- index.html -->
  <!DOCTYPE html>
  <html>
    <meta charset="utf-8">
    <body>
        Hello world!
    </body>
    <script type="text/javascript">
    function test() {
        console.log('Ark WebComponent')
        return "This value is from index.html"
    }
    </script>
  </html>
  ```

### stop<sup>(deprecated)</sup>

stop()

Stops page loading.

This API is deprecated since API version 9. You are advised to use [stop<sup>9+</sup>](./js-apis-webview-WebviewController.md#stop) instead.

**System capability**: SystemCapability.Web.Webview.Core

**Example**

  ```ts
  // xxx.ets
  @Entry
  @Component
  struct WebComponent {
    controller: WebController = new WebController()

    build() {
      Column() {
        Button('stop')
          .onClick(() => {
            this.controller.stop()
          })
        Web({ src: 'www.example.com', controller: this.controller })
      }
    }
  }
  ```

### clearHistory<sup>(deprecated)</sup>

clearHistory(): void

Clears the browsing history.

This API is deprecated since API version 9. You are advised to use [clearHistory<sup>9+</sup>](./js-apis-webview-WebviewController.md#clearhistory) instead.

**System capability**: SystemCapability.Web.Webview.Core

**Example**

  ```ts
  // xxx.ets
  @Entry
  @Component
  struct WebComponent {
    controller: WebController = new WebController()

    build() {
      Column() {
        Button('clearHistory')
          .onClick(() => {
            this.controller.clearHistory()
          })
        Web({ src: 'www.example.com', controller: this.controller })
      }
    }
  }
  ```

## WebCookie

Manages behavior of cookies in **Web** components. All **Web** components in an application share a **WebCookie**. You can use the **getCookieManager** API in **controller** to obtain the **WebCookie** for subsequent cookie management.

### constructor

constructor()

Constructs a **WebCookie** object.

**System capability**: SystemCapability.Web.Webview.Core

### setCookie<sup>(deprecated)</sup>

setCookie()

Sets the cookie. This API returns the result synchronously. Returns **true** if the operation is successful; returns **false** otherwise.

This API is deprecated since API version 9. You are advised to use [setCookie<sup>9+</sup>](./js-apis-webview-WebCookieManager.md#setcookiedeprecated) instead.

**System capability**: SystemCapability.Web.Webview.Core

### saveCookie<sup>(deprecated)</sup>

saveCookie()

Saves the cookies in the memory to the drive. This API returns the result synchronously.

This API is deprecated since API version 9. You are advised to use [saveCookieAsync<sup>9+</sup>](./js-apis-webview-WebCookieManager.md#savecookieasync) instead.

**System capability**: SystemCapability.Web.Webview.Core
