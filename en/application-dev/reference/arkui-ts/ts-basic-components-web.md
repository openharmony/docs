# Web

> **NOTE**<br>
> This component is supported since API version 8. Updates will be marked with a superscript to indicate their earliest API version.

The **<Web\>** component can be used to display web pages.

## Required Permissions
ohos.permission.INTERNET, required only for accessing online web pages.

## Child Components

None

## APIs

-   Web\(options: { src: string, controller?: WebController }\)

    Table 1 Parameters of options

    | Name       | Type                            | Mandatory | Default Value | Description                     |
    | ---------- | ------------------------------- | --------- | ------------- | ------------------------------- |
    | src        | string                          | Yes       | -             | Address of a web page resource. |
    | controller | [WebController](#webcontroller) | No        | -             | Controller.                     |


> ![icon-note.gif](public_sys-resources/icon-note.gif) **NOTE**
>
> - Transition animation is not supported.
> - Multi-instance is not supported.
> - Only local audio and video are supported for playback.

## Attributes
| Name              | Type                                     | Default Value  | Description                              |
| ----------------- | ---------------------------------------- | -------------- | ---------------------------------------- |
| domStorageAccess  | boolean                                  | false          | Whether to enable the DOM Storage API permission. By default, the permission is disabled. |
| fileAccess        | boolean                                  | true           | Whether to enable in-application rawfile access through [$rawfile(filepath/filename)](../../ui/ts-application-resource-access.md). By default, this feature is enabled. |
| imageAccess       | boolean                                  | true           | Whether to enable automatic image loading. By default, this feature is enabled. |
| javaScriptProxy   | { <br>  object: object, <br> name: string, <br> methodList: Array\<string\>, <br> controller: WebController <br>} | -              | JavaScript object to be injected into the window. Methods of this object can be invoked in the window. The parameters in this attribute cannot be updated.<br> **object** indicates the object to be registered. Methods can be declared, but not attributes. The parameters and return value can only be of the string, number, or Boolean type.<br> **name** indicates the name of the object to be registered, which is the same as that invoked in the window. After registration, the window can use this name to access the JavaScript object at the application side.<br> **methodList** indicates the methods of the JavaScript object to be registered at the application side.<br> **controller** indicates the controller. |
| javaScriptAccess  | boolean                                  | true           | Whether JavaScript scripts can be executed. By default, JavaScript scripts can be executed. |
| mixedMode         | MixedMode                                | MixedMode.None | Whether to enable loading of HTTP and HTTPS hybrid content can be loaded. By default, this feature is disabled. |
| onlineImageAccess | boolean                                  | true           | Whether to enable access to online images through HTTP and HTTPS. By default, this feature is enabled. |
| zoomAccess        | boolean                                  | true           | Whether to enable zoom gestures. By default, zoom gestures are enabled. |

> **NOTE**<br> 
> Only the following universal attributes are supported: [width](ts-universal-attributes-size.md#Attributes), [height](ts-universal-attributes-size.md#Attributes), [padding](ts-universal-attributes-size.md#Attributes), [margin](ts-universal-attributes-size.md#Attributes), and [border](ts-universal-attributes-border.md#Attributes).
- <span id="MixedMode">MixedMode</span>

  | Name       | Description                              |
  | ---------- | ---------------------------------------- |
  | All        | HTTP and HTTPS hybrid content can be loaded. This means that all insecure content can be loaded. |
  | Compatible | HTTP and HTTPS hybrid content can be loaded in compatibility mode. This means that some insecure content may be loaded. |
  | None       | HTTP and HTTPS hybrid content cannot be loaded. |

## Events

Universal events are not supported.

| Name                                     | Description                              |
| ---------------------------------------- | ---------------------------------------- |
| onAlert(callback: (event?: { url: string; message: string; result: [JsResult](#jsresult) }) => boolean) | <p>Triggered when **alert()** is invoked to display an alert dialog box on the web page.<br>If the callback returns **false**, the default dialog box is displayed. If the callback returns **true**, a system application can invoke the system dialog box capability (allows only the confirm operation) and invoke the **JsResult** API to notify the **\<Web>** component of the user's operation.<br>**url**: URL of the web page where the dialog box is displayed.<br>**message**: information displayed in the dialog box.<br>**JsResult**: notifies the **\<Web>** component of the user's operation.</p> |
| onBeforeUnload(callback: (event?: { url: string; message: string; result: [JsResult](#jsresult) }) => boolean) | <p>Triggered when the current page is about to exit after the user refreshes or closes the page.<br>If the callback returns **false**, the default dialog box is displayed. If the callback returns **true**, a system application can invoke the system dialog box capability (allows the confirm and cancel operations) and invoke the **JsResult** API to notify the **\<Web>** component of the user's operation.<br>**url**: URL of the web page where the dialog box is displayed.<br>**message**: information displayed in the dialog box.<br>**JsResult**: notifies the **\<Web>** component of the user's operation.</p> |
| onConfirm(callback: (event?: { url: string; message: string; result: [JsResult](#jsresult) }) => boolean) | <p>Triggered when **confirm()** is invoked to display a confirmation dialog box on the web page.<br>If the callback returns **false**, the default dialog box is displayed. If the callback returns **true**, a system application can invoke the system dialog box capability (allows the confirm and cancel operations) and invoke the **JsResult** API to notify the **\<Web>** component of the user's operation.<br>**url**: URL of the web page where the dialog box is displayed.<br>**message**: information displayed in the dialog box.<br>**JsResult**: notifies the **\<Web>** component of the user's operation.</p> |
| onConsole(callback: (event?: { message: [ConsoleMessage](#consolemessage) }) => boolean) | <p>Triggered when the host application is notified of a JavaScript console message.<br>**message**: console message.</p> |
| onDownloadStart(callback: (event?: { url: string, userAgent: string, contentDisposition: string, mimetype: string, contentLength: number }) => void) | <p>Triggered when a download task starts on the web page.<br>**url**: URL for the download task.<br>**userAgent**: name of the user agent (UA) for the download task.<br>**contentDisposition**: Content-Disposition response header returned by the server, which may be empty.<br>**mimetype**: content media type (MIME) returned by the server.<br>**contentLength**: length of the file returned by the server.</p> |
| onErrorReceive(callback: (event?: { request: [WebResourceRequest](#webresourceerror), error: [WebResourceError](#webresourceerror) }) => void) | <p>Triggered when an error occurs during web page loading.<br>For better results, simplify the implementation logic in the callback.<br>**request**: encapsulation of a web page request.<br>**error**: encapsulation of a web page resource loading error.</p> |
| onHttpErrorReceive(callback: (event?: { request: [WebResourceRequest](#webresourceerror), response: [WebResourceResponse](#webresourceresponse) }) => void) | <p>Triggered when an HTTP error (the response code is greater than or equal to 400) occurs during web page resource loading.<br>**request**: encapsulation of a web page request.<br>**response**: encapsulation of a web page response.</p> |
| onPageBegin(callback: (event?: { url: string }) => void) | <p>Triggered when the web page starts to be loaded. This API is triggered only for the main frame content, and not for the iframe or frameset content.<br>**url**: URL of the page.</p> |
| onPageEnd(callback: (event?: { url: string }) => void) | <p>Triggered when the web page loading is complete. This API is triggered only for the main frame content.<br>**url**: URL of the page.</p> |
| onProgressChange(callback: (event?: { newProgress: number }) => void) | <p>Triggered when the web page loading progress changes.<br>**newProgress**: new loading progress. The value is an integer ranging from 0 to 100.</p> |
| onTitleReceive(callback: (event?: { title: string }) => void) | <p>Triggered when the document title of the web page is changed.<br>**title**: document title.</p> |

### ConsoleMessage

- APIs

  | Name                            | Description                              |
  | ------------------------------- | ---------------------------------------- |
  | getLineNumber(): number         | Obtains the number of rows in the **ConsoleMessage**. |
  | getMessage(): string            | Obtains the log information of the **ConsoleMessage**. |
  | getMessageLevel(): MessageLevel | Obtains the log information level of the **ConsoleMessage**. |
  | getSourceId(): string           | Obtains the path and name of the web page source file. |

- MessageLevel enums

  | Name  | Description        |
  | ----- | ------------------ |
  | Debug | Debug level.       |
  | Error | Error level.       |
  | Info  | Information level. |
  | Log   | Log level.         |
  | Warn  | Warning level.     |

### JsResult

Represents the result returned to the **\<Web>** component to indicate the operation performed in the dialog box.

- APIs

  | Name                  | Description                              |
  | --------------------- | ---------------------------------------- |
  | handleCancel(): void  | <p>Notifies the **\<Web>** component that the user touches the **Cancel** button in the dialog box.  |
  | handleConfirm(): void | <p>Notifies the **\<Web>** component that the user touches the **Confirm** button in the dialog box. |

### WebResourceError

- APIs

  | Name                   | Description                              |
  | ---------------------- | ---------------------------------------- |
  | getErrorCode(): number | Obtains the error code for resource loading. |
  | getErrorInfo(): string | Obtains error information about resource loading. |

### WebResourceRequest

- APIs

  | Name                                     | Description                              |
  | ---------------------------------------- | ---------------------------------------- |
  | getRequestHeader(): Array\<[Header](#header)\> | Obtains the information about the resource request header. |
  | getRequestUrl(): string                  | Obtains the URL of the resource request. |
  | isMainFrame(): boolean                   | Checks whether the resource request is in the main frame. |
  | isRedirect(): boolean                    | Checks whether the resource request is redirected by the server. |
  | isRequestGesture(): boolean              | Checks whether the resource request is associated with a gesture (for example, a tap). |

### Header

Describes the request/response header object returned by the **\<Web>** component.

- Parameters

  | Name        | Type   | Description                           |
  | ----------- | ------ | ------------------------------------- |
  | headerKey   | string | Key of the request/response header.   |
  | headerValue | string | Value of the request/response header. |


### WebResourceResponse

- APIs

  | Name                                     | Description                              |
  | ---------------------------------------- | ---------------------------------------- |
  | getReasonMessage(): string               | Obtains the status code description of the resource response. |
  | getResponseCode(): number                | Obtains the status code of the resource response. |
  | getResponseData(): string                | Obtains the data in the resource response. |
  | getResponseEncoding(): string            | Obtains the encoding of the resource response. |
  | getResponseHeader(): Array\<[Header](#header)\> | Obtains the resource response header.    |
  | getResponseMimeType(): string            | Obtains the media (MIME) type of the resource response. |

## WebController

Defines a **WebController** to control the behavior of the **\<Web>** component. A **WebController** can control only one **\<Web>** component, and the APIs in the **WebController** can be invoked only after it has been bound to the target **\<Web>** component.

### Creating an Object

```
webController: WebController = new WebController()
```

### accessBackward

accessBackward(): boolean

Checks whether going to the previous page can be performed on the current page.

### accessForward

accessForward(): boolean

Checks whether going to the next page can be performed on the current page.

### accessStep

accessStep(step: number): boolean

Indicates whether a specific number of steps forward or backward can be performed on the current page.

- Parameters

  | Name | Type   | Mandatory | Default Value | Description                              |
  | ---- | ------ | --------- | ------------- | ---------------------------------------- |
  | step | number | Yes       | -             | Number of the steps to take. A positive number means going forward, and a negative number means going backward. |

- Return value

  | Type    | Description                              |
  | ------- | ---------------------------------------- |
  | boolean | Whether to go forward or backward from the current page. |

### backward

backward(): void

Goes to the previous page based on the history stack. This API is generally used together with **accessBackward**.

### deleteJavaScriptRegister

deleteJavaScriptRegister(name: string): void

Deletes a specific application JavaScript object that is registered with the window through **registerJavaScriptProxy**.

- Parameters

  | Name | Type   | Mandatory | Default Value | Description                              |
  | ---- | ------ | --------- | ------------- | ---------------------------------------- |
  | name | string | Yes       | -             | Name of the registered JavaScript object, which can be used to invoke the corresponding object on the application side from the web side. |

### forward

forward(): void

Goes to the next page based on the history stack. This API is generally used together with **accessForward**.

### getHitTest

getHitTest(): HitTestType

Obtains the element type of the area being clicked.	

- HitTestType enums

  | Name          | Description                              |
  | ------------- | ---------------------------------------- |
  | EditText      | Editable area.                           |
  | Email         | Email address.                           |
  | HttpAnchor    | Hyperlink where **src** is **http**.     |
  | HttpAnchorImg | Image with a hyperlink, where **src** is **http**. |
  | Img           | HTML::img tag.                           |
  | Map           | Geographical address.                    |
  | PhoneNumber   | Phone number.                            |
  | Unknown       | Unknown content.                         |

### loadData

loadData(options: { data: string, mimeType: string, encoding: string, baseUrl?: string, historyUrl?: string }): void

Loads data. If **baseUrl** is empty, the specified character string will be loaded using the data protocol.

If **baseUrl** is set to a data URL, the encoded string will be loaded by the **\<Web>** component using the data protocol.

If **baseUrl** is set to an HTTP or HTTPS URL, the encoded string will be processed by the **\<Web>** component as a non-encoded string in a manner similar to **loadUrl**.

- options

  | Name       | Type   | Mandatory | Default Value | Description                              |
  | ---------- | ------ | --------- | ------------- | ---------------------------------------- |
  | data       | string | Yes       | -             | Character string obtained after being Base64 or URL encoded. |
  | mimeType   | string | Yes       | -             | Media type (MIME).                       |
  | encoding   | string | Yes       | -             | Encoding type, which can be Base64 or URL. |
  | baseUrl    | string | No        | -             | URL (HTTP/HTTPS/data compliant), which is assigned by the **\<Web>** component to **window.origin**. |
  | historyUrl | string | No        | -             | Historical record URL. If this parameter is not empty, it can be managed in historical records to implement page going backward and forward. This parameter is invalid when **baseUrl** is left empty. |

### loadUrl

loadUrl(options:{ url: string, headers?: Array\<Header\> }): void

Loads a URL using the specified HTTP header.

The object injected through **loadUrl** is valid only in the current document. It will be invalid on a new page navigated to through **loadUrl**.

Objects injected through **registerJavaScriptProxy** are still valid on a new page navigated to through **loadUrl**.

- options

  | Name    | Type                       | Mandatory | Default Value | Description                              |
  | ------- | -------------------------- | --------- | ------------- | ---------------------------------------- |
  | url     | string                     | Yes       | -             | URL to load.                             |
  | headers | Array\<[Header](#header)\> | No        | []            | Additional HTTP request header of the URL. |

### onActive

onActive(): void

Invoked to instruct the **\<Web>** component to enter the active state.

### onInactive

onInactive(): void

Invoked to instruct the **\<Web>** component to enter the inactive state.

### refresh

refresh(): void

Invoked to instruct the **\<Web>** component to refresh the web page.

### registerJavaScriptProxy

registerJavaScriptProxy(options: { object: object, name: string, methodList: Array\<string\> }): void

Injects a JavaScript object into the window and invokes the methods of the object in the window. After the registration, the **refresh** API must be invoked for the registration to take effect.

- options

  | Name       | Type            | Mandatory | Default Value | Description                              |
  | ---------- | --------------- | --------- | ------------- | ---------------------------------------- |
  | object     | object          | Yes       | -             | Application-side JavaScript object to be registered. Methods can be declared, but not attributes. The parameters and return value can only be of the string, number, or Boolean type. |
  | name       | string          | Yes       | -             | Name of the object to be registered, which is the same as that invoked in the window. After registration, the window can use this name to access the JavaScript object at the application side. |
  | methodList | Array\<string\> | Yes       | -             | Methods of the JavaScript object to be registered at the application side. |

### runJavaScript

runJavaScript(options: { script: string, callback?: (result: string) => void }): void

Asynchronously executes a JavaScript script. This API uses a callback to return the script execution result.**runJavaScript** can be invoked only after **loadUrl** is executed. For example, it can be executed in **onPageEnd**.

- options

  | Name     | Type                     | Mandatory | Default Value | Description                              |
  | -------- | ------------------------ | --------- | ------------- | ---------------------------------------- |
  | script   | string                   | Yes       | -             | JavaScript script.                       |
  | callback | (result: string) => void | No        | -             | Callback used to return the result. The value **null** indicates that the JavaScript script fails to be executed or no value is returned. |

### stop

stop(): void

Stops page loading.

## Example

```
// webComponent.ets
@Entry
@Component
struct WebComponent {
  @State javaScriptAccess: boolean = true;
  @State fileAccess: boolean = true;
  controller: WebController = new WebController();
  build() {
    Column() {
      Web({ src: $rawfile('index.html'), controller: this.controller })
      .javaScriptAccess(this.javaScriptAccess)
      .fileAccess(this.fileAccess)
      .onPageEnd(e => {
        // test() has been defined in index.html.
        this.controller.runJavaScript({ script: 'test()' });
        console.log("url: ", e.url);
      })
    }
  }
}
```
```
<!-- index.html -->
<!DOCTYPE html>
<html>
<meta charset="utf-8">
<body>
    Hello world!
</body>
<script type="text/javascript">
	function test() {
		console.log('Ark WebComponent');
	}
</script>
</html>
```

![](figures/Web.png)
