# AIPageInteraction

<!--Kit: ArkWeb-->
<!--Subsystem: Web-->
<!--Owner: @zhushengle-->
<!--Designer: @yyyiye-->
<!--Tester: @ghiker-->
<!--Adviser: @HelloShuo-->
<!-- md-trans-meta sourceCommit=83a123fed8576a7a579f4752a2ba1d3b16228342 translatedAt=2026-08-13T13:27:10.715Z pushedAt=2026-08-17T08:38:02.802Z -->

Starting from API version 26.0.0, `AIPageInteraction` defines the page interaction JSON command protocol supported by [executeAIPageCommand](./arkts-apis-webview-WebviewController.md), including element-level input operations such as click, focus, type text, and send keyboard events, as well as operations that change the page state, such as page scrolling, dropdown option selection, file upload, and zoom control. Before calling this API, the app needs to serialize the command object into a JSON string.

> **NOTE**
>
> - `command` must be a JSON object string.
> - The `method` field value is case-sensitive. Use the values listed in [Command Overview](#command-overview).
> - When the return value is not empty, it is a JSON string. The app can parse it with `JSON.parse` before use.
> - When the web page is unavailable, the command cannot be executed, or no result is returned, the API returns an empty string.
> - For query commands, see [AIPageCommand](./arkts-apis-webview-AIPageCommand.md).

## Command Overview

| method | Function | Input Parameter Format | Return Format | Description |
| ---- | ---- | ---- | ---- | ---- |
| [click](#click) | Clicks the target element | [ClickCommand](#clickcommand) | None | Makes the target element respond to a click event, without considering whether a real mouse event is generated. |
| [focus](#focus) | Moves focus to the target element | [FocusCommand](#focuscommand) | None | Moves focus to the target element so that it can receive subsequent interactions such as keyboard input. |
| [cursor_position](#cursor_position) | Obtains the current text caret position | None | [CursorPositionResult](#cursorpositionresult) | Obtains the position of the text caret on the current page. The coordinates are relative to the Web component. |
| [type](#type) | Enters text into the target element | [TypeCommand](#typecommand) | None | Inserts text at the specified position in the target element, and supports clearing before input. If the target element does not have focus, focus is obtained first before input. |
| [send_keys](#send_keys) | Sends keyboard events | [SendKeysCommand](#sendkeyscommand) | None | Sends keyboard events to the frontend, supporting function keys, number keys, letter keys, symbol keys, editing keys, navigation keys, and modifier keys. |
| [scroll](#scroll) | Scrolls the page | [ScrollCommand](#scrollcommand) | [CommandResult](./arkts-apis-webview-AIPageResult.md#commandresult) | Scrolls the page based on the coordinate point and offset. |
| [select](#select) | Selects a drop-down option | [SelectCommand](#selectcommand) | [CommandResult](./arkts-apis-webview-AIPageResult.md#commandresult) | Selects an option of the `<select>` tag. |
| [uploadFile](#uploadfile) | Uploads a file | [UploadFileCommand](#uploadfilecommand) | [CommandResult](./arkts-apis-webview-AIPageResult.md#commandresult) | Sets the file list of the `<input type='file'>` tag. |
| [setZoomLevel](#setzoomlevel) | Sets the web page zoom ratio | [SetZoomLevelCommand](#setzoomlevelcommand) | [CommandResult](./arkts-apis-webview-AIPageResult.md#commandresult) | Sets the zoom ratio of the current web page, equivalent to CTRL+Wheel zooming. |

## Target Element Locating

The `click`, `focus`, and `type` commands require the target element positioning parameters to specify the operation object. The following two methods are supported:

| Name | Type | Description |
| ---- | ---- | ---- |
| xpath | string | XPath of the target element, which can be obtained through [getFullDom](./arkts-apis-webview-AIPageCommand.md#getfulldom) or [getLiteDom](./arkts-apis-webview-AIPageCommand.md#getlitedom). |
| nodeid | string | Node ID of the target element, which can be obtained through the `id` field returned by [getFullDom](./arkts-apis-webview-AIPageCommand.md#getfulldom) or [getLiteDom](./arkts-apis-webview-AIPageCommand.md#getlitedom). |

> **NOTE**
>
> - `xpath` and `nodeid` are mutually exclusive. If both are passed, `nodeid` takes precedence.

## Return Format

### Success

Operation commands (click, focus, type, send_keys) return the following on success:

```json
{
  "code": 10,
  "message": "success"
}
```

Query commands (cursor_position) return a result object on success. See the description of each command.

### Failure

If any command fails, the following is returned:

```json
{
  "code": <Error code>,
  "error": "<Error message>"
}
```

For error code values, see [Command Execution Result Code Description](./arkts-apis-webview-AIPageResult.md#command-execution-result-code-description).

## click

Clicks the target element to make it respond to a click event, regardless of whether a real mouse event is generated.

### ClickCommand

Locate the target element by XPath:

```json
{
  "method": "click",
  "params": {
    "xpath": "/html[1]/body[1]/button[1]"
  }
}
```

Locate the target element by node identifier:

```json
{
  "method": "click",
  "params": {
    "nodeid": "frameToken|documentToken|12"
  }
}
```

### Input Parameter Description

| Name | Sub-Parameter | Parameter Item | Type | Mandatory | Description |
| ---- | ---- | ---- | ---- | ---- | ---- |
| method | - | - | string | Yes | Command name, fixed to `click`. |
| params | - | - | Object | Yes | Command parameter. |
| params | - | xpath | string | No | XPath of the target element. `xpath` and `nodeid` are mutually exclusive. If both are passed, `nodeid` takes precedence. |
| params | - | nodeid | string | No | Node identifier of the target element. `xpath` and `nodeid` are mutually exclusive. If both are passed, `nodeid` takes precedence. |

> **NOTE**
>
> - `params` must contain one of `xpath` or `nodeid`, which is used for locating the target element.
>

### Response Description

An empty string is returned when the command is executed successfully.

### Request Example

```json
{
  "method": "click",
  "params": {
    "xpath": "/html[1]/body[1]/button[1]"
  }
}
```

### Response Example

Empty string.

## focus

Makes the target element obtain focus.

### FocusCommand

Locate the target element by XPath:

```json
{
  "method": "focus",
  "params": {
    "xpath": "/html[1]/body[1]/input[1]"
  }
}
```

Locate the target element by node identifier:

```json
{
  "method": "focus",
  "params": {
    "nodeid": "frameToken|documentToken|12"
  }
}
```

### Input Parameter Description

| Name | Sub-Parameter | Parameter Item | Type | Mandatory | Description |
| ---- | ---- | ---- | ---- | ---- | ---- |
| method | - | - | string | Yes | Command name, fixed to `focus`. |
| params | - | - | Object | Yes | Command parameter. |
| params | - | xpath | string | No | XPath of the target element. `xpath` and `nodeid` are mutually exclusive. If both are passed, `nodeid` takes precedence. |
| params | - | nodeid | string | No | Node ID of the target element. `xpath` and `nodeid` are mutually exclusive. If both are passed, `nodeid` takes precedence. |

> **NOTE**
>
> - `params` must contain one of `xpath` or `nodeid`, which is used for locating the target element.

### Response Description

An empty string is returned when the command is executed successfully.

### Request Example

```json
{
  "method": "focus",
  "params": {
    "nodeid": "frameToken|documentToken|12"
  }
}
```

### Response Example

Empty string.

## cursor_position

Obtains the position of the caret in the current page. The returned coordinates are the offset relative to the top-left corner of the Web component.

### Request Description

This command does not require the `params` parameter.

### CursorPositionResult

```json
{
  "result": {
    "x": 100,
    "y": 200
  }
}
```

### Response Description

| Field | Subfield | Type | Description |
| ---- | ---- | ---- | ---- |
| result | - | Object | Position information of the text caret. |
| result | x | number | X coordinate of the text caret, relative to the Web component. |
| result | y | number | Y coordinate of the text caret, relative to the Web component. |

> **NOTE**
>
> - The coordinates are relative to the Web component, not the absolute coordinates of the page.

### Request Example

```json
{
  "method": "cursor_position"
}
```

### Response Example

```json
{
  "result": {
    "x": 100,
    "y": 200
  }
}
```

## type

Inputs text into the target element. Supports inserting text at a specified position in the target element, and supports clearing before input. If the target element has not obtained focus, it will first be focused before input.

### TypeCommand

```json
{
  "method": "type",
  "params": {
    "xpath": "/html[1]/body[1]/input[1]",
    "text": "Text to be entered.",
    "index": 0,
    "clear": true
  }
}
```

### Input Parameter Description

| Name | Sub-Parameter | Parameter Item | Type | Mandatory | Description |
| ---- | ---- | ---- | ---- | ---- | ---- |
| method | - | - | string | Yes | Command name, fixed to `type`. |
| params | - | - | Object | Yes | Command parameter. |
| params | - | xpath | string | No | XPath of the target element. `xpath` and `nodeid` are mutually exclusive. If both are passed, `nodeid` takes precedence. |
| params | - | nodeid | string | No | Node ID of the target element. `xpath` and `nodeid` are mutually exclusive. If both are passed, `nodeid` takes precedence. |
| params | - | text | string | Yes | Text content to be entered. |
| params | - | index | number | No | Position where the text is inserted, starting from 0. If the length of the existing text in the input box is less than `index`, the text is appended at the end. The default value is **0**. |
| params | - | clear | boolean | No | Whether to clear the existing text in the target element before input. The default value is **false**. |

> **NOTE**
>
> - `params` must contain one of `xpath` or `nodeid`, used for locating the target element.
> - If the target element does not have focus, it will first be focused before performing the input operation.
> - When `index` is **0**, the text is inserted at the very beginning of the existing text.
> - When `clear` is **true**, all text in the target element is cleared first, and then `text` is inserted at the `index` position.

### Response Description

An empty string is returned when the command is executed successfully.

### Request Example

```json
{
  "method": "type",
  "params": {
    "xpath": "/html[1]/body[1]/input[1]",
    "text": "Hello World",
    "index": 0,
    "clear": true
  }
}
```

### Response Example

Empty String.

## send_keys

Sends keyboard events to the frontend.

### SendKeysCommand

```json
{
  "method": "send_keys",
  "params": {
    "key": "PageDown",
    "keyaction": "keydown"
  }
}
```

### Input Parameter Description

| Name | Sub-Parameter | Parameter Item | Type | Mandatory | Description |
| ---- | ---- | ---- | ---- | ---- | ---- |
| method | - | - | string | Yes | Command name, fixed to `send_keys`. |
| params | - | - | Object | Yes | Command parameters. |
| params | - | key | string | Yes | Name of the key to send. For details about the value, see [Description of params.key Field Values for send_keys](#description-of-paramskey-field-values-for-send_keys). Letter keys are case-sensitive. |
| params | - | keyaction | string | Yes | Key action type, which can be `keydown` or `keyup`. |

> **NOTE**
>
> - Letter keys are case-sensitive. For example, `KeyA` and `Keya` represent different keys.
> - You can send `keydown` and `keyup` consecutively to simulate a complete key operation.

### Description of params.key Field Values for send_keys

| Category | Supported Keys |
| ---- | ---- |
| Function key | F1, F2, F3, F4, F5, F6, F7, F8, F9, F10, F11, F12 |
| Number key | Digit0, Digit1, Digit2, Digit3, Digit4, Digit5, Digit6, Digit7, Digit8, Digit9 |
| Letter key | KeyA to KeyZ, Keya to Keyz (case-sensitive) |
| Symbol key | Backquote, Minus, Equal, Backslash |
| Editing key | Backspace, Tab, Delete, Insert, Enter, Escape |
| Navigation key | ArrowDown, ArrowUp, ArrowLeft, ArrowRight, Home, End, PageUp, PageDown |
| Modifier key | Shift, Control, Alt, ShiftLeft |

### Response Description

An empty string is returned when the command is executed successfully.

### Request Example

```json
{
  "method": "send_keys",
  "params": {
    "key": "PageDown",
    "keyaction": "keydown"
  }
}
```

### Response Example

Empty String.

## scroll

Scrolls the current web page. Controls the page scroll position by coordinates and distance, and triggers a wheel event.

### ScrollCommand

```json
{
  "method": "scroll",
  "params": {
    "x": 100,
    "y": 200,
    "deltaX": 0,
    "deltaY": -300,
    "speed": 800
  }
}
```

### Input Parameter Description

| Name | Sub-Parameter | Parameter Item | Type | Mandatory | Description |
| ---- | ---- | ---- | ---- | ---- | ---- |
| method | - | - | string | Yes | Command name, fixed to `scroll`. |
| params | - | - | Object | Yes | Command parameter. |
| params | - | x | number | Yes | Mouse X coordinate at which the wheel event is triggered. In the viewport coordinate system, the upper left corner is the origin (0, 0), and the value increases to the right. The unit is CSS pixel. If this parameter is missing, `{"code":391}` is returned. If the coordinate falls inside a scrollable element, that element is scrolled; if it falls in a blank area of the page, the page root is scrolled. |
| params | - | y | number | Yes | Mouse Y coordinate at which the wheel event is triggered. In the viewport coordinate system, the upper left corner is the origin (0, 0), and the value increases downward. The unit is CSS pixel. If this parameter is missing, `{"code":391}` is returned. If the coordinate falls inside a scrollable element, that element is scrolled; if it falls in a blank area of the page, the page root is scrolled. |
| params | - | deltaX | number | No | Horizontal wheel event delta. A negative value scrolls the page to the right (shows the content on the right, that is, `scrollLeft` increases), and a positive value scrolls the page to the left (shows the content on the left, that is, `scrollLeft` decreases). The unit is CSS pixel. If this parameter is not passed, the default value is 0 (no horizontal scrolling occurs). |
| params | - | deltaY | number | No | Vertical wheel event delta. A negative value scrolls the page downward (shows the content below, that is, `scrollTop` increases), and a positive value scrolls the page upward (shows the content above, that is, `scrollTop` decreases). The unit is CSS pixel. If this parameter is not passed, the default value is 0 (no vertical scrolling occurs). |
| params | - | speed | number | No | Scroll speed. The value range is [-2147483648, 2147483647]: a negative value reaches the target position immediately without a scroll animation; 0 returns `{"code":392}`; a positive value performs the scroll animation at the specified speed. If this parameter is not passed, the default value is 800. |

> **NOTE**
>
> - The `scroll` command is in fire-and-forget mode. The result is returned immediately after the command is sent successfully, without waiting for the gesture to complete.
> - Consecutively sent scroll commands are queued and executed in order by the Chromium gesture controller, and no command is lost.
> - The final scroll distance may have a slight deviation due to floating-point rounding (usually less than 1 pixel).

### Response Description

Returns `{"code":10,"message":"success"}` on success; returns an error code JSON on failure. Common error codes are listed in the table below:

| Error code | Trigger Condition |
| ---- | ---- |
| 110 | The `params` field is not a JSON object. |
| 132 | The browser or host is empty, which usually indicates that the Web instance is unavailable. |
| 350 | Failed to deliver the scroll command. |
| 391 | The required parameter `x` or `y` is missing. |
| 392 | The value or type of `x`/`y`/`deltaX`/`deltaY`/`speed` is invalid (for example, `speed=0`). |

### Request Example

```json
{
  "method": "scroll",
  "params": {
    "x": 180,
    "y": 320,
    "deltaY": -300
  }
}
```

### Response Example

Success:

```json
{
  "code": 10,
  "message": "success"
}
```

On failure:

`391` (the required parameter `x` or `y` is missing):

```json
{
  "code": 391,
  "message": "missing param: x"
}
```

`392` (`speed` value or type is invalid, for example `speed=0`):

```json
{
  "code": 392,
  "message": "invalid param: speed"
}
```

## select

Selects an option from the drop-down list of a select element. Locates the select element by XPath and selects an option by index or value.

### SelectCommand

```json
{
  "method": "select",
  "params": {
    "xpath": "//select[@id='country']",
    "indexes": [2]
  }
}
```

### Input Parameter Description

| Name | Sub-Parameter | Parameter Item | Type | Mandatory | Description |
| ---- | ---- | ---- | ---- | ---- | ---- |
| method | - | - | string | Yes | Command name, fixed to `select`. |
| params | - | - | Object | Yes | Command parameter. |
| params | - | xpath | string | Yes | XPath 1.0 locating expression. The first matched node is used. If it is missing or is an empty string, `{"code":115}` is returned. |
| params | - | indexes | Array\<number\> | No | Index list of the `<option>` child elements, counted from 0 and corresponding to the `<option>` child elements under `<select>` in DOM order (excluding the level offset of `<optgroup>`). At least one of `indexes` and `values` must be provided. If neither is provided, `{"code":251}` is returned. If both are provided, `indexes` takes precedence. |
| params | - | values | Array\<string\> | No | List of the `value` attribute values of the `<option>` elements. Traverses all `<option>` child elements of `<select>` and compares `option.value` with the passed-in values. At least one of `indexes` and `values` must be provided. If neither is provided, `{"code":251}` is returned. If both are provided, `indexes` takes precedence. |

> **NOTE**
>
> - If the selected option contains a disabled item, `{"code":255}` is returned.
> - A multi-select element (`<select multiple>`) can accept multiple indexes. If multiple indexes are passed to a single-select element, an error is returned.

### Response Description

Returns `{"code":10,"message":"success"}` on success; returns an error code JSON on failure. Common error codes are listed in the table below:

| Error code | Trigger Condition |
| ---- | ---- |
| 110 | The `params` field is not a JSON object. |
| 115 | `xpath` is missing or its value is an empty string. |
| 131 | The element matched by `xpath` does not exist. |
| 132 | The browser or host is empty, which usually indicates that the Web instance is unavailable. |
| 161 | `xpath` matches an element that is not a `<select>` element. |
| 251 | Neither `indexes` nor `values` is provided, or both are empty arrays. |
| 252 | The `indexes` index is out of bounds (less than 0 or greater than or equal to the number of options). |
| 253 | No value in `values` matches any item in the option list. |
| 254 | Multiple indexes are passed to a single-select `<select>`. |
| 255 | The selected option is disabled. |
| 256 | The `<select>` element has no option child element. |

### Request Example

```json
{
  "method": "select",
  "params": {
    "xpath": "//select[@id='country']",
    "indexes": [1, 3]
  }
}
```

### Response Example

Success:

```json
{
  "code": 10,
  "message": "success"
}
```

On failure:

`131` (the element matched by `xpath` does not exist):

```json
{
  "code": 131,
  "message": "element not found"
}
```

`161` (`xpath` matches an element that is not a `<select>` element):

```json
{
  "code": 161,
  "message": "element type mismatch"
}
```

`251` (Neither `indexes` nor `values` is provided):

```json
{
  "code": 251,
  "message": "indexes or values required"
}
```

`252` (Index out of bounds):

```json
{
  "code": 252,
  "message": "index out of range"
}
```

`255` (The selected option is disabled):

```json
{
  "code": 255,
  "message": "option is disabled"
}
```

`391` (missing `xpath` or is an empty string):

```json
{
  "code": 391,
  "message": "missing param: xpath"
}
```

## uploadFile

Sets the file path for input[type=file] elements. Locates elements via XPath, and supports setting single or multiple file paths.

### UploadFileCommand

```json
{
  "method": "uploadFile",
  "params": {
    "xpath": "//input[@type='file']",
    "files": ["/data/local/tmp/test.pdf"]
  }
}
```

### Input Parameter Description

| Name | Sub-Parameter | Parameter Item | Type | Mandatory | Description |
| ---- | ---- | ---- | ---- | ---- | ---- |
| method | - | - | string | Yes | Command name, fixed to `uploadFile`. |
| params | - | - | Object | Yes | Command parameter. |
| params | - | xpath | string | Yes | XPath 1.0 locating expression, which takes the first matching node. Returns `{"code":391}` when it is missing or an empty string. |
| params | - | files | Array\<string\> | Yes | List of absolute file paths. The paths are normalized. Returns `{"code":372}` when it is missing or an empty array. Array elements must be non-empty strings; an empty string returns `{"code":371}`. |

> **NOTE**
>
> - File paths are normalized (symbolic links resolved). Returns `{"code":370,"message":"failed to resolve file path: <path>"}` when the path cannot be resolved.
> - Path existence and readability are non-blocking warnings and do not affect command execution. Warning information is appended to the `message` field in the format `"success; warnings: <path>: <reason>"`.
> - When `xpath` matches a non-`input[type=file]` element, the upload is rejected and `{"code":352,"message":"upload target is not file input"}` is returned.

### Response Description

Returns `{"code":10,"message":"success"}` on successful command execution (warning information is appended to the `message` field when non-blocking warnings exist); returns an error code JSON on failure. Common error codes are listed in the table below:

| Error code | Trigger Condition |
| ---- | ---- |
| 110 | The `params` field is not a JSON object. |
| 131 | The element matched by `xpath` does not exist, or the DOM search returns no result. |
| 132 | The browser or host is empty, which usually indicates that the Web instance is unavailable. |
| 350 | Failed to deliver the file upload command. |
| 351 | Failed to initialize the file upload channel. |
| 352 | Failed to execute the file upload (including the case where the upload is rejected when `xpath` matches a non-`<input type='file'>` element). |
| 353 | Failed to parse the element search response. |
| 370 | The file path cannot be resolved (including the path traversal component `..`). |
| 371 | The file path is an empty string. |
| 372 | The file list is empty or not provided. |
| 391 | `xpath` is missing or an empty string. |

### Request Example

```json
{
  "method": "uploadFile",
  "params": {
    "xpath": "//input[@type='file' and @name='upload']",
    "files": ["/data/local/tmp/file1.pdf", "/data/local/tmp/file2.pdf"]
  }
}
```

### Response Example

On success:

```json
{
  "code": 10,
  "message": "success"
}
```

On success with warnings:

```json
{
  "code": 10,
  "message": "success; warnings: /path/file.pdf: path does not exist"
}
```

On failure:

`131` (the element matched by `xpath` does not exist):

```json
{
  "code": 131,
  "message": "element not found"
}
```

`352` (`xpath` matched to a non-`<input type='file'>` element):

```json
{
  "code": 352,
  "message": "upload target is not file input"
}
```

`370` (file path cannot be resolved):

```json
{
  "code": 370,
  "message": "failed to resolve file path: /data/local/tmp/missing.pdf"
}
```

`371` (file path is an empty string):

```json
{
  "code": 371,
  "message": "file path is empty"
}
```

`372` (file list is empty or not provided):

```json
{
  "code": 372,
  "message": "files list is empty"
}
```

`391` (missing `xpath` or is an empty string):

```json
{
  "code": 391,
  "message": "missing param: xpath"
}
```

## setZoomLevel

Sets the zoom level of the current web page. This command is equivalent to the user manually zooming with CTRL+Wheel, scaling the entire web page (CSS page zoom). The zoom level is persisted to the Chromium HostZoomMap and shares storage with manual zoom.

### SetZoomLevelCommand

```json
{
  "method": "setZoomLevel",
  "params": {
    "zoomLevel": 1.5
  }
}
```

### Input Parameter Description

| Name | Sub-parameter | Parameter Item | Type | Mandatory | Description |
| ---- | ---- | ---- | ---- | ---- | ---- |
| method | - | - | string | Yes | Command name, fixed to `setZoomLevel`. |
| params | - | - | Object | Yes | Command parameter. |
| params | - | zoomLevel | number | Yes | Page zoom ratio. 1.0 indicates 100% (original size), 2.0 indicates 200%, and 0.5 indicates 50%. The value range is [0.25, 5.0]. |

> **NOTE**
>
> - When the app disables zoom via [zoomControlAccess](./arkts-basic-components-web-attributes.md#zoomcontrolaccess22), this command returns `{"code":482}`.
> - When `zoomLevel` is a non-numeric type (string, array, object, or null), it is treated uniformly as a missing field, and `{"code":391}` is returned.
> - NaN, Infinity, and -Infinity are not valid JSON values and will be rejected at the JSON parsing stage, so they will not enter this command.

### Response Description

Returns `{"code":10,"message":"success"}` on success; returns an error code JSON on failure. Common error codes are listed in the table below:

| Error code | Trigger Condition |
| ---- | ---- |
| 110 | The `params` field is not a JSON object. |
| 132 | The browser or host is empty, which usually indicates that the Web instance is unavailable. |
| 391 | `zoomLevel` is missing or is a non-numeric type (string, array, object, or null). |
| 480 | The value is out of the range `[0.25, 5.0]`, and the page zoom ratio is not changed. |
| 481 | The value is invalid, such as a negative number, zero, or NaN, and the page zoom ratio is not changed. |
| 482 | The app disables zoom control (`zoomControlAccess=false`), and the page zoom ratio is not changed. |

### Test Page

```html
<!-- index.html -->
<!DOCTYPE html>
<html>
  <body>
    <h1>Zoom Level Demo</h1>
    <p>The current zoom level can be queried through getZoomLevel and modified through setZoomLevel.</p>
  </body>
</html>
```

### Request Example

```json
{
  "method": "setZoomLevel",
  "params": {
    "zoomLevel": 1.5
  }
}
```

### Response Example

On success (page zoomed to 150%):

```json
{
  "code": 10,
  "message": "success"
}
```

On failure:

`391` (missing `zoomLevel` or not a numeric type):

```json
{
  "code": 391,
  "message": "missing param: zoomLevel"
}
```

`480` (value out of range `[0.25, 5.0]`, page zoom ratio unchanged):

```json
{
  "code": 480,
  "message": "zoom level out of range"
}
```

`481` (invalid value, e.g., negative or zero, page zoom level unchanged):

```json
{
  "code": 481,
  "message": "zoom level invalid"
}
```

`482` (app disabled zoom control, page zoom level unchanged):

```json
{
  "code": 482,
  "message": "zoom control is disabled"
}
```
<!--no_check-->