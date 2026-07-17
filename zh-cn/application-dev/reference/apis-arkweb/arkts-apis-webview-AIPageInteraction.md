# AIPageInteraction
<!--Kit: ArkWeb-->
<!--Subsystem: Web-->
<!--Owner: @zhushengle-->
<!--Designer: @yyyiye-->
<!--Tester: @ghiker-->
<!--Adviser: @HelloShuo-->

从API版本26.0.0开始，`AIPageInteraction`定义[executeAIPageCommand](./arkts-apis-webview-WebviewController.md#executeaipagecommand)支持的页面交互类JSON命令协议，包括点击、聚焦、输入文本、发送键盘事件等元素级输入操作，以及页面滚动、下拉选项选中、文件上传、缩放控制等会改变页面状态的操作。调用该接口前，应用需要将命令对象序列化为JSON字符串。

> **说明：**
>
> - `command`必须为JSON对象字符串。
> - `method`字段取值区分大小写，需使用[命令总览](#命令总览)中列出的取值。
> - 返回值非空时为JSON字符串，应用可通过`JSON.parse`解析后使用。
> - 当网页不可用、命令无法执行或无结果返回时，接口返回空字符串。
> - 查询类命令请参见[AIPageCommand](./arkts-apis-webview-AIPageCommand.md)。

## 命令总览

| method | 功能 | 入参格式 | 返回格式 | 说明 |
| ---- | ---- | ---- | ---- | ---- |
| [click](#click) | 点击目标元素 | [ClickCommand](#clickcommand) | 无 | 使目标元素响应点击事件(click event)，不关注是否产生真实的鼠标事件(mouse event)。 |
| [focus](#focus) | 使目标元素获取焦点 | [FocusCommand](#focuscommand) | 无 | 将焦点移动到目标元素，使其可以接收键盘输入等后续交互。 |
| [cursor_position](#cursor_position) | 获取当前文本插入符位置 | 无 | [CursorPositionResult](#cursorpositionresult) | 获取当前页面中文本插入符（caret）的位置，坐标相对于Web组件。 |
| [type](#type) | 向目标元素输入文本 | [TypeCommand](#typecommand) | 无 | 在目标元素指定位置插入文本，支持先清空后输入。若目标元素未获取焦点，先获取焦点再输入。 |
| [send_keys](#send_keys) | 发送键盘事件 | [SendKeysCommand](#sendkeyscommand) | 无 | 向前端发送键盘事件，支持功能键、数字键、字母键、符号键、编辑键、导航键和修饰键。 |
| [scroll](#scroll) | 页面滚动 | [ScrollCommand](#scrollcommand) | [CommandResult](./arkts-apis-webview-AIPageResult.md#commandresult) | 根据坐标点和偏移量滚动页面。 |
| [select](#select) | 选中下拉选项 | [SelectCommand](#selectcommand) | [CommandResult](./arkts-apis-webview-AIPageResult.md#commandresult) | 选中`<select>`标签的选项。 |
| [uploadFile](#uploadfile) | 文件上传 | [UploadFileCommand](#uploadfilecommand) | [CommandResult](./arkts-apis-webview-AIPageResult.md#commandresult) | 设置`<input type='file'>`标签的文件列表。 |
| [setZoomLevel](#setzoomlevel) | 设置网页缩放比例 | [SetZoomLevelCommand](#setzoomlevelcommand) | [CommandResult](./arkts-apis-webview-AIPageResult.md#commandresult) | 设置当前网页的缩放比例，等价于CTRL+Wheel缩放。 |

## 通用目标元素定位

`click`、`focus`、`type`命令需要通过目标元素定位参数指定操作对象，支持以下两种方式：

| 参数 | 类型 | 说明 |
| ---- | ---- | ---- |
| xpath | string | 目标元素的XPath，可通过[getFullDom](./arkts-apis-webview-AIPageCommand.md#getfulldom)或[getLiteDom](./arkts-apis-webview-AIPageCommand.md#getlitedom)获取。 |
| nodeid | string | 目标元素的节点标识，可通过[getFullDom](./arkts-apis-webview-AIPageCommand.md#getfulldom)或[getLiteDom](./arkts-apis-webview-AIPageCommand.md#getlitedom)返回的`id`字段获取。 |

> **说明：**
>
> - `xpath`与`nodeid`互斥，均传入时以`nodeid`为准。

## 返回格式

### 成功

操作类命令（click、focus、type、send_keys）成功时返回：

```json
{
  "code": 10,
  "message": "success"
}
```

查询类命令（cursor_position）成功时返回结果对象，参见各命令说明。

### 失败

任意命令失败时返回：

```json
{
  "code": <错误码>,
  "error": "<错误信息>"
}
```

错误码取值参见[命令执行结果码说明](./arkts-apis-webview-AIPageResult.md#命令执行结果码说明)。

## click

点击目标元素，使其响应点击事件(click event)，不关注是否产生真实的鼠标事件(mouse event)。

### ClickCommand

通过XPath定位目标元素：

```json
{
  "method": "click",
  "params": {
    "xpath": "/html[1]/body[1]/button[1]"
  }
}
```

通过节点标识定位目标元素：

```json
{
  "method": "click",
  "params": {
    "nodeid": "frameToken|documentToken|12"
  }
}
```

### 入参说明

| 参数 | 子参数 | 参数项 | 类型 | 必填 | 说明 |
| ---- | ---- | ---- | ---- | ---- | ---- |
| method | - | - | string | 是 | 命令名称，固定为`click`。 |
| params | - | - | Object | 是 | 命令参数。 |
| params | - | xpath | string | 否 | 目标元素的XPath。`xpath`与`nodeid`互斥，均传入时以`nodeid`为准。 |
| params | - | nodeid | string | 否 | 目标元素的节点标识。`xpath`与`nodeid`互斥，均传入时以`nodeid`为准。 |

> **说明：**
>
> - `params`中必须包含`xpath`或`nodeid`中的一个，用于定位目标元素。
>
### 返回说明

命令执行成功时返回空字符串。

### 请求示例

```json
{
  "method": "click",
  "params": {
    "xpath": "/html[1]/body[1]/button[1]"
  }
}
```

### 返回示例

空字符串。

## focus

使目标元素获取焦点。

### FocusCommand

通过XPath定位目标元素：

```json
{
  "method": "focus",
  "params": {
    "xpath": "/html[1]/body[1]/input[1]"
  }
}
```

通过节点标识定位目标元素：

```json
{
  "method": "focus",
  "params": {
    "nodeid": "frameToken|documentToken|12"
  }
}
```

### 入参说明

| 参数 | 子参数 | 参数项 | 类型 | 必填 | 说明 |
| ---- | ---- | ---- | ---- | ---- | ---- |
| method | - | - | string | 是 | 命令名称，固定为`focus`。 |
| params | - | - | Object | 是 | 命令参数。 |
| params | - | xpath | string | 否 | 目标元素的XPath。`xpath`与`nodeid`互斥，均传入时以`nodeid`为准。 |
| params | - | nodeid | string | 否 | 目标元素的节点标识。`xpath`与`nodeid`互斥，均传入时以`nodeid`为准。 |

> **说明：**
>
> - `params`中必须包含`xpath`或`nodeid`中的一个，用于定位目标元素。

### 返回说明

命令执行成功时返回空字符串。

### 请求示例

```json
{
  "method": "focus",
  "params": {
    "nodeid": "frameToken|documentToken|12"
  }
}
```

### 返回示例

空字符串。

## cursor_position

获取当前页面中文本插入符（caret）的位置，返回的坐标为相对于Web组件左上角的偏移量。

### 请求说明

该命令不需要`params`参数。

### CursorPositionResult

```json
{
  "result": {
    "x": 100,
    "y": 200
  }
}
```

### 返回说明

| 字段 | 子字段 | 类型 | 说明 |
| ---- | ---- | ---- | ---- |
| result | - | Object | 文本插入符位置信息。 |
| result | x | number | 文本插入符的x坐标，相对于Web组件。 |
| result | y | number | 文本插入符的y坐标，相对于Web组件。 |

> **说明：**
>
> - 坐标相对于Web组件的位置，非页面绝对坐标。

### 请求示例

```json
{
  "method": "cursor_position"
}
```

### 返回示例

```json
{
  "result": {
    "x": 100,
    "y": 200
  }
}
```

## type

向目标元素输入文本。支持在目标元素的指定位置插入文本，支持先清空后输入。若目标元素未获取焦点，会先使其获取焦点再输入。

### TypeCommand

```json
{
  "method": "type",
  "params": {
    "xpath": "/html[1]/body[1]/input[1]",
    "text": "需要输入的文本",
    "index": 0,
    "clear": true
  }
}
```

### 入参说明

| 参数 | 子参数 | 参数项 | 类型 | 必填 | 说明 |
| ---- | ---- | ---- | ---- | ---- | ---- |
| method | - | - | string | 是 | 命令名称，固定为`type`。 |
| params | - | - | Object | 是 | 命令参数。 |
| params | - | xpath | string | 否 | 目标元素的XPath。`xpath`与`nodeid`互斥，均传入时以`nodeid`为准。 |
| params | - | nodeid | string | 否 | 目标元素的节点标识。`xpath`与`nodeid`互斥，均传入时以`nodeid`为准。 |
| params | - | text | string | 是 | 需要输入的文本内容。 |
| params | - | index | number | 否 | 文本插入位置，从0开始。当输入框内已有文本长度小于`index`时，在末尾追加。默认值为0。 |
| params | - | clear | boolean | 否 | 是否在输入前先清空目标元素中的已有文本。默认值为false。 |

> **说明：**
>
> - `params`中必须包含`xpath`或`nodeid`中的一个，用于定位目标元素。
> - 若目标元素未获取焦点，会先使其获取焦点再执行输入操作。
> - `index`为0时表示在已有文本的最前面插入。
> - 当`clear`为`true`时，会先清空目标元素中的全部文本，再在`index`位置插入`text`。

### 返回说明

命令执行成功时返回空字符串。

### 请求示例

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

### 返回示例

空字符串。

## send_keys

向前端发送键盘事件。

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

### 入参说明

| 参数 | 子参数 | 参数项 | 类型 | 必填 | 说明 |
| ---- | ---- | ---- | ---- | ---- | ---- |
| method | - | - | string | 是 | 命令名称，固定为`send_keys`。 |
| params | - | - | Object | 是 | 命令参数。 |
| params | - | key | string | 是 | 需要发送的按键名称，取值请参见[send_keys的params.key字段取值说明](#send_keys的paramskey字段取值说明)。发送字母时大小写敏感。 |
| params | - | keyaction | string | 是 | 按键动作类型，取值为`keydown`或`keyup`。 |

> **说明：**
>
> - 发送字母时大小写敏感，例如`KeyA`和`Keya`表示不同的按键。
> - 可通过连续发送`keydown`和`keyup`模拟完整的按键操作。

### send_keys的params.key字段取值说明

| 分类 | 支持的按键 |
| ---- | ---- |
| 功能键 | F1、F2、F3、F4、F5、F6、F7、F8、F9、F10、F11、F12 |
| 数字键 | Digit0、Digit1、Digit2、Digit3、Digit4、Digit5、Digit6、Digit7、Digit8、Digit9 |
| 字母键 | KeyA ~ KeyZ、Keya ~ Keyz（大小写敏感） |
| 符号键 | Backquote、Minus、Equal、Backslash |
| 编辑键 | Backspace、Tab、Delete、Insert、Enter、Escape |
| 导航键 | ArrowDown、ArrowUp、ArrowLeft、ArrowRight、Home、End、PageUp、PageDown |
| 修饰键 | Shift、Control、Alt、ShiftLeft |

### 返回说明

命令执行成功时返回空字符串。

### 请求示例

```json
{
  "method": "send_keys",
  "params": {
    "key": "PageDown",
    "keyaction": "keydown"
  }
}
```

### 返回示例

空字符串。

## scroll

滚动当前网页。通过坐标和距离控制页面滚动位置，触发wheel事件。

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

### 入参说明

| 参数 | 子参数 | 参数项 | 类型 | 必填 | 说明 |
| ---- | ---- | ---- | ---- | ---- | ---- |
| method | - | - | string | 是 | 命令名称，固定为`scroll`。 |
| params | - | - | Object | 是 | 命令参数。 |
| params | - | x | number | 是 | wheel事件触发的鼠标X坐标。视口坐标系，左上角为原点(0, 0)，向右递增，单位为CSS像素。缺失时返回`{"code":391}`。若该坐标落在可滚动元素内部，则滚动该元素；若落在页面空白区域，则滚动页面根。 |
| params | - | y | number | 是 | wheel事件触发的鼠标Y坐标。视口坐标系，左上角为原点(0, 0)，向下递增，单位为CSS像素。缺失时返回`{"code":391}`。若该坐标落在可滚动元素内部，则滚动该元素；若落在页面空白区域，则滚动页面根。 |
| params | - | deltaX | number | 否 | 水平方向wheel事件增量。负值使页面向右滚动（显示右侧内容，即`scrollLeft`增大），正值使页面向左滚动（显示左侧内容，即`scrollLeft`减小）。单位为CSS像素。不传入时默认为0（不发生水平滚动）。 |
| params | - | deltaY | number | 否 | 垂直方向wheel事件增量。负值使页面向下滚动（显示下方内容，即`scrollTop`增大），正值使页面向上滚动（显示上方内容，即`scrollTop`减小）。单位为CSS像素。不传入时默认为0（不发生垂直滚动）。 |
| params | - | speed | number | 否 | 滚动速度。取值范围[-2147483648, 2147483647]：负值立刻到达目标位置，无滚动动画；0返回`{"code":392}`；正值按指定速度进行滚动动画。不传入时默认为800。 |

> **说明：**
>
> - `scroll`命令为即发即忘模式，命令发送成功后立即返回结果，不等待手势执行完成。
> - 连续发送的滚动命令由Chromium手势控制器排队顺序执行，不会丢失命令。
> - 最终滚动距离可能因浮点数舍入存在微小偏差（通常小于1像素）。

### 返回说明

命令执行成功时返回`{"code":10,"message":"success"}`；失败时返回错误码JSON，常见错误码见下表：

| 错误码 | 触发条件 |
| ---- | ---- |
| 110 | `params`字段非JSON对象 |
| 132 | browser或host为空，通常表示Web实例不可用 |
| 350 | 滚动命令下发失败 |
| 391 | 缺少必要参数`x`或`y` |
| 392 | `x`/`y`/`deltaX`/`deltaY`/`speed`取值或类型无效（如`speed=0`） |

### 请求示例

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

### 返回示例

成功：

```json
{
  "code": 10,
  "message": "success"
}
```

失败：

`391`（缺少必要参数`x`或`y`）：

```json
{
  "code": 391,
  "message": "missing param: x"
}
```

`392`（`speed`取值或类型无效，例如`speed=0`）：

```json
{
  "code": 392,
  "message": "invalid param: speed"
}
```

## select

选中select元素的下拉选项。通过XPath定位select元素，按索引或值选中option。

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

### 入参说明

| 参数 | 子参数 | 参数项 | 类型 | 必填 | 说明 |
| ---- | ---- | ---- | ---- | ---- | ---- |
| method | - | - | string | 是 | 命令名称，固定为`select`。 |
| params | - | - | Object | 是 | 命令参数。 |
| params | - | xpath | string | 是 | XPath 1.0定位表达式，取首个匹配节点。缺失或为空字符串时返回`{"code":115}`。 |
| params | - | indexes | Array\<number\> | 否 | `<option>`子元素的索引列表，从0开始计数，按DOM顺序对应`<select>`下的`<option>`子元素（不含`<optgroup>`层级偏移）。与`values`至少提供一个，两者均未提供时返回`{"code":251}`。与`values`同时提供时`indexes`优先。 |
| params | - | values | Array\<string\> | 否 | `<option>`元素的`value`属性值列表。遍历`<select>`的所有`<option>`子元素，比对`option.value`与传入值。与`indexes`至少提供一个，两者均未提供时返回`{"code":251}`。与`indexes`同时提供时`indexes`优先。 |

> **说明：**
>
> - 选中的option包含被禁用项时，返回`{"code":255}`。
> - 多选元素（`<select multiple>`）可传入多个索引；单选元素传入多个索引时返回错误。

### 返回说明

命令执行成功时返回`{"code":10,"message":"success"}`；失败时返回错误码JSON，常见错误码见下表：

| 错误码 | 触发条件 |
| ---- | ---- |
| 110 | `params`字段非JSON对象 |
| 115 | 缺少`xpath`或其值为空字符串 |
| 131 | `xpath`匹配的元素不存在 |
| 132 | browser或host为空，通常表示Web实例不可用 |
| 161 | `xpath`匹配到非`<select>`元素 |
| 251 | `indexes`和`values`均未提供或均为空数组 |
| 252 | `indexes`索引越界（小于0或大于等于option数量） |
| 253 | `values`中的值在option列表中无匹配项 |
| 254 | 单选`<select>`传入多个索引 |
| 255 | 选中的option被禁用 |
| 256 | `<select>`元素无option子元素 |

### 请求示例

```json
{
  "method": "select",
  "params": {
    "xpath": "//select[@id='country']",
    "indexes": [1, 3]
  }
}
```

### 返回示例

成功：

```json
{
  "code": 10,
  "message": "success"
}
```

失败：

`131`（`xpath`匹配的元素不存在）：

```json
{
  "code": 131,
  "message": "element not found"
}
```

`161`（`xpath`匹配到非`<select>`元素）：

```json
{
  "code": 161,
  "message": "element type mismatch"
}
```

`251`（`indexes`和`values`均未提供）：

```json
{
  "code": 251,
  "message": "indexes or values required"
}
```

`252`（索引越界）：

```json
{
  "code": 252,
  "message": "index out of range"
}
```

`255`（选中的option被禁用）：

```json
{
  "code": 255,
  "message": "option is disabled"
}
```

`391`（缺少`xpath`或为空字符串）：

```json
{
  "code": 391,
  "message": "missing param: xpath"
}
```

## uploadFile

为input[type=file]元素设置文件路径。通过XPath定位元素，支持设置单个或多个文件路径。

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

### 入参说明

| 参数 | 子参数 | 参数项 | 类型 | 必填 | 说明 |
| ---- | ---- | ---- | ---- | ---- | ---- |
| method | - | - | string | 是 | 命令名称，固定为`uploadFile`。 |
| params | - | - | Object | 是 | 命令参数。 |
| params | - | xpath | string | 是 | XPath 1.0定位表达式，取首个匹配节点。缺失或为空字符串时返回`{"code":391}`。 |
| params | - | files | Array\<string\> | 是 | 文件绝对路径列表。路径经过规范化处理。缺失或为空数组时返回`{"code":372}`。数组元素须为非空字符串，空字符串返回`{"code":371}`。 |

> **说明：**
>
> - 文件路径经过规范化处理（解析符号链接）。路径无法解析时返回`{"code":370,"message":"failed to resolve file path: <path>"}`。
> - 路径存在性和可读性为非阻塞警告，不影响命令执行。警告信息附加在`message`字段中，格式为`"success; warnings: <path>: <reason>"`。
> - `xpath`匹配到非`input[type=file]`元素时，上传被拒绝，返回`{"code":352,"message":"upload target is not file input"}`。

### 返回说明

命令执行成功时返回`{"code":10,"message":"success"}`（存在非阻塞警告时`message`字段追加警告信息）；失败时返回错误码JSON，常见错误码见下表：

| 错误码 | 触发条件 |
| ---- | ---- |
| 110 | `params`字段非JSON对象 |
| 131 | `xpath`匹配的元素不存在，或DOM搜索无结果 |
| 132 | browser或host为空，通常表示Web实例不可用 |
| 350 | 文件上传命令下发失败 |
| 351 | 文件上传通道初始化失败 |
| 352 | 文件上传执行失败（含`xpath`匹配到非`<input type='file'>`元素时上传被拒绝） |
| 353 | 元素搜索响应解析失败 |
| 370 | 文件路径无法解析（含路径遍历组件`..`） |
| 371 | 文件路径为空字符串 |
| 372 | 文件列表为空或未提供 |
| 391 | 缺少`xpath`或为空字符串 |

### 请求示例

```json
{
  "method": "uploadFile",
  "params": {
    "xpath": "//input[@type='file' and @name='upload']",
    "files": ["/data/local/tmp/file1.pdf", "/data/local/tmp/file2.pdf"]
  }
}
```

### 返回示例

成功时：

```json
{
  "code": 10,
  "message": "success"
}
```

成功但含警告时：

```json
{
  "code": 10,
  "message": "success; warnings: /path/file.pdf: path does not exist"
}
```

失败：

`131`（`xpath`匹配的元素不存在）：

```json
{
  "code": 131,
  "message": "element not found"
}
```

`352`（`xpath`匹配到非`<input type='file'>`元素）：

```json
{
  "code": 352,
  "message": "upload target is not file input"
}
```

`370`（文件路径无法解析）：

```json
{
  "code": 370,
  "message": "failed to resolve file path: /data/local/tmp/missing.pdf"
}
```

`371`（文件路径为空字符串）：

```json
{
  "code": 371,
  "message": "file path is empty"
}
```

`372`（文件列表为空或未提供）：

```json
{
  "code": 372,
  "message": "files list is empty"
}
```

`391`（缺少`xpath`或为空字符串）：

```json
{
  "code": 391,
  "message": "missing param: xpath"
}
```

## setZoomLevel

设置当前网页的缩放比例。命令等价于用户手动CTRL+Wheel缩放，整体缩放网页（CSS page zoom）。缩放比例会持久化到Chromium HostZoomMap，与手动缩放共享存储。

### SetZoomLevelCommand

```json
{
  "method": "setZoomLevel",
  "params": {
    "zoomLevel": 1.5
  }
}
```

### 入参说明

| 参数 | 子参数 | 参数项 | 类型 | 必填 | 说明 |
| ---- | ---- | ---- | ---- | ---- | ---- |
| method | - | - | string | 是 | 命令名称，固定为`setZoomLevel`。 |
| params | - | - | Object | 是 | 命令参数。 |
| params | - | zoomLevel | number | 是 | 网页缩放比例。1.0表示100%（原始大小），2.0表示200%，0.5表示50%。取值范围[0.25, 5.0]。 |

> **说明：**
>
> - 当应用通过[zoomControlAccess](./arkts-basic-components-web-attributes.md#zoomcontrolaccess22)禁用缩放时，本命令返回`{"code":482}`。
> - `zoomLevel`为非数字类型（字符串、数组、对象、null）时，统一按缺少字段处理，返回`{"code":391}`。
> - NaN/Infinity/-Infinity不是合法JSON数值，会在JSON解析阶段被拒绝，不会进入本命令。

### 返回说明

命令执行成功时返回`{"code":10,"message":"success"}`；失败时返回错误码JSON，常见错误码见下表：

| 错误码 | 触发条件 |
| ---- | ---- |
| 110 | `params`字段非JSON对象 |
| 132 | browser或host为空，通常表示Web实例不可用 |
| 391 | 缺少`zoomLevel`或为非数字类型（字符串、数组、对象、null） |
| 480 | 取值超出范围`[0.25, 5.0]`，页面缩放比例未改变 |
| 481 | 取值非法如负数、零或NaN，页面缩放比例未改变 |
| 482 | 应用禁用了缩放控制（`zoomControlAccess=false`），页面缩放比例未改变 |

### 测试页面

```html
<!-- index.html -->
<!DOCTYPE html>
<html>
  <body>
    <h1>Zoom Level Demo</h1>
    <p>当前缩放比例可通过getZoomLevel查询，通过setZoomLevel修改。</p>
  </body>
</html>
```

### 请求示例

```json
{
  "method": "setZoomLevel",
  "params": {
    "zoomLevel": 1.5
  }
}
```

### 返回示例

成功时（页面放大至150%）：

```json
{
  "code": 10,
  "message": "success"
}
```

失败：

`391`（缺少`zoomLevel`或为非数字类型）：

```json
{
  "code": 391,
  "message": "missing param: zoomLevel"
}
```

`480`（取值超出范围`[0.25, 5.0]`，页面缩放比例未改变）：

```json
{
  "code": 480,
  "message": "zoom level out of range"
}
```

`481`（取值非法如负数或零，页面缩放比例未改变）：

```json
{
  "code": 481,
  "message": "zoom level invalid"
}
```

`482`（应用禁用了缩放控制，页面缩放比例未改变）：

```json
{
  "code": 482,
  "message": "zoom control is disabled"
}
```
