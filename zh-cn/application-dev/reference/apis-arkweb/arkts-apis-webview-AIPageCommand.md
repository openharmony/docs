# AIPageCommand
<!--Kit: ArkWeb-->
<!--Subsystem: Web-->
<!--Owner: @zourongchun-->
<!--Designer: @kurli1-->
<!--Tester: @ghiker-->
<!--Adviser: @HelloShuo-->

`AIPageCommand`定义[executeAIPageCommand](./arkts-apis-webview-WebviewController.md#executeaipagecommand)支持的JSON命令协议，包括不同命令的入参格式和返回格式。调用该接口前，应用需要将命令对象序列化为JSON字符串。

> **说明：**
>
> - `command`必须为JSON对象字符串。
> - `method`字段取值区分大小写，需使用[命令总览](#命令总览)中列出的取值。
> - 返回值非空时为JSON字符串，应用可通过`JSON.parse`解析后使用。
> - 当网页不可用、命令无法执行或无结果返回时，接口返回空字符串。

## 命令总览

| method | 功能 | 入参格式 | 返回格式 | 说明 |
| ---- | ---- | ---- | ---- | ---- |
| [getFullDom](#getfulldom) | 获取完整DOM树 | [FullDomCommand](#fulldomcommand) | [FullDomResult](#fulldomresult) | 返回树结构，不按筛选规则过滤节点。适用于需要完整层级结构的场景。 |
| [getLiteDom](#getlitedom) | 获取轻量DOM节点列表 | [LiteDomCommand](#litedomcommand) | [LiteDomResult](#litedomresult) | 返回扁平列表，支持按规则筛选节点。 |
| [screenCapture](#screencapture) | 获取网页元素截图 | [ScreenCaptureCommand](#screencapturecommand) | [ScreenCaptureResult](#screencaptureresult) | 返回Base64编码图片数据，支持获取当前网页视口截图或视口内目标元素截图。 |
| [getZoomLevel](#getzoomlevel) | 获取网页缩放比例 | [GetZoomLevelCommand](#getzoomlevelcommand) | [ZoomLevelResult](#zoomlevelresult) | 获取当前网页的缩放比例。 |

交互类命令请参见[AIPageInteraction](./arkts-apis-webview-AIPageInteraction.md)。

## 通用命令格式

| 参数 | 子参数 | 参数项 | 类型 | 必填 | 说明 |
| ---- | ---- | ---- | ---- | ---- | ---- |
| method | - | - | string | 是 | 命令名称。支持的取值请参见[命令总览](#命令总览)。 |
| params | - | - | Object | 否 | 命令参数。不同`method`对应的`params`格式不同。不传入时具体行为由各命令定义。 |

## getFullDom

获取当前网页的完整DOM树结构。该命令从文档根节点开始遍历，返回树形节点列表。

### FullDomCommand

```json
{
  "method": "getFullDom",
  "params": {
    "wants": [
      "rect",
      "visible",
      "xpath"
    ]
  }
}
```

### 入参说明

| 参数 | 子参数 | 参数项 | 类型 | 必填 | 说明 |
| ---- | ---- | ---- | ---- | ---- | ---- |
| method | - | - | string | 是 | 命令名称，固定为`getFullDom`。 |
| params | - | - | Object | 否 | 命令参数。不传入时使用默认返回字段。 |
| params | wants | - | Array\<string> | 否 | 指定需要在节点中追加返回的字段。数组项表示节点信息字段，取值请参见[getFullDom的params.wants字段取值说明](#getfulldom的paramswants字段取值说明)。`getFullDom`会默认请求`tag`、`text`和全部HTML属性。 |

> **说明：**
>
> `getFullDom`默认返回当前网页的`url`、`title`和`children_nodes`。`children_nodes`中的节点默认返回`tag`、`text`、`attributes`和`children_nodes`；其中`text`和`attributes`在字段值为空时不会返回。

### getFullDom的params.wants字段取值说明

| 取值 | 返回字段 | 返回类型 | 说明 |
| ---- | ---- | ---- | ---- |
| id | id | string | 请求返回ArkWeb生成的节点标识，不表示按HTML `id`属性筛选节点。该值由frame标识、文档作用域标识和DOM节点标识组合编码，用于区分返回结果中的节点；页面重新加载、frame重建或DOM重建后可能变化。仅在可生成节点标识时返回。如需读取HTML `id`属性，请查看返回节点的`attributes.id`。 |
| tag | tag | string | 节点标签名。元素节点返回小写HTML标签名，文本节点返回`#text`，ShadowRoot节点返回`#shadowRoot`。 |
| text | text | string | 节点文本内容。字段值为空时不返回该字段。 |
| title | title | string | 节点`title`属性值。字段值为空时不返回该字段。 |
| aria-label | aria-label | string | 节点`aria-label`属性值。字段值为空时不返回该字段。 |
| role | role | string | 节点语义角色。字段值为空时不返回该字段。 |
| aria-description | aria-description | string | 节点`aria-description`属性值。字段值为空时不返回该字段。 |
| rect | rect | Object | 节点矩形信息，包含`x`、`y`、`width`、`height`。 |
| bounds | bounds | Object | 节点矩形信息，包含`x`、`y`、`left`、`top`、`right`、`bottom`、`width`、`height`。 |
| visible | visible | boolean | 节点是否可见。true表示可见，false表示不可见。 |
| isInViewport | isInViewport | boolean | 节点是否在当前视口内。true表示在当前视口内，false表示不在当前视口内。 |
| clickable | clickable | boolean | 节点是否可点击。true表示可点击，false表示不可点击。 |
| touchable | touchable | boolean | 节点是否可触控。true表示可触控，false表示不可触控。当前判断逻辑与`clickable`一致。 |
| scrollable | scrollable | boolean | 节点是否可滚动。true表示可滚动，false表示不可滚动。 |
| inputable | inputable | boolean | 节点是否可输入。true表示可输入，false表示不可输入。 |
| url | url | string | 节点关联URL。按`href`、`src`、`action`、`data`、`poster`顺序读取并转换为完整URL。字段值为空时不返回该字段。 |
| xpath | xpath | string | 节点XPath。字段值为空时不返回该字段。 |
| hover | hover | string | 节点`cursor`样式值。字段值为空时不返回该字段。 |
| mouseover | mouseover | boolean | 节点是否声明`mouseover`内联事件。true表示已声明，false表示未声明。 |
| mouseenter | mouseenter | boolean | 节点是否声明`mouseenter`内联事件。true表示已声明，false表示未声明。 |
| value | value | string | 当节点为`select`元素时，返回当前选中值。 |
| options | options | Array\<Object> | 当节点为`select`元素时，返回选项列表。 |
| value_text | value_text | Array\<Object> | 当节点为`select`元素时，返回选项列表。 |
| focusable | focusable | boolean | 节点是否可获取焦点。true表示可获取焦点，false表示不可获取焦点。 |
| editable | editable | boolean | 节点是否可编辑。true表示可编辑，false表示不可编辑。 |
| settable | settable | boolean | 节点是否可设置值。true表示可设置值，false表示不可设置值。 |
| checked | checked | boolean | 节点是否处于选中状态。true表示处于选中状态，false表示不处于选中状态。 |
| expanded | expanded | boolean | 节点是否处于展开状态。true表示处于展开状态，false表示不处于展开状态。 |
| pressed | pressed | boolean | 节点是否处于按下状态。true表示处于按下状态，false表示不处于按下状态。 |
| selected | selected | boolean | 节点是否处于选择状态。true表示处于选择状态，false表示不处于选择状态。 |
| required | required | boolean | 节点是否为必填项。true表示为必填项，false表示为非必填项。 |
| autocomplete | autocomplete | string | 节点自动完成信息，优先读取`aria-autocomplete`属性，其次读取`autocomplete`属性。字段值为空时不返回该字段。 |
| keyshortcuts | keyshortcuts | string | 节点`aria-keyshortcuts`属性值。字段值为空时不返回该字段。 |

### FullDomResult

| 字段 | 子字段 | 字段项 | 类型 | 说明 |
| ---- | ---- | ---- | ---- | ---- |
| url | - | - | string | 当前网页URL。 |
| title | - | - | string | 当前网页标题。 |
| children_nodes | - | - | Array\<Object> | DOM树根节点列表。 |
| children_nodes | - | id | string | ArkWeb生成的节点标识，不是HTML `id`属性。仅在`wants`中包含`id`且可生成节点标识时返回。 |
| children_nodes | - | tag | string | 节点标签名。 |
| children_nodes | - | text | string | 节点文本内容。 |
| children_nodes | - | title | string | 节点`title`属性值。 |
| children_nodes | - | aria-label | string | 节点`aria-label`属性值。 |
| children_nodes | - | role | string | 节点语义角色。 |
| children_nodes | - | aria-description | string | 节点`aria-description`属性值。 |
| children_nodes | - | rect | Object | 节点矩形信息。 |
| children_nodes | rect | x | number | 节点矩形左上角x坐标。单位：px。 |
| children_nodes | rect | y | number | 节点矩形左上角y坐标，相对于当前节点所属frame的视口左上角。单位：px。 |
| children_nodes | rect | width | number | 节点矩形宽度。单位：px。 |
| children_nodes | rect | height | number | 节点矩形高度。单位：px。 |
| children_nodes | - | bounds | Object | 节点矩形信息。 |
| children_nodes | bounds | x | number | 节点矩形左上角x坐标。单位：px。 |
| children_nodes | bounds | y | number | 节点矩形左上角y坐标。单位：px。 |
| children_nodes | bounds | left | number | 节点矩形左边界。单位：px。 |
| children_nodes | bounds | top | number | 节点矩形上边界。单位：px。 |
| children_nodes | bounds | right | number | 节点矩形右边界。单位：px。 |
| children_nodes | bounds | bottom | number | 节点矩形下边界。单位：px。 |
| children_nodes | bounds | width | number | 节点矩形宽度。单位：px。 |
| children_nodes | bounds | height | number | 节点矩形高度。单位：px。 |
| children_nodes | - | visible | boolean | 节点是否可见。true表示可见，false表示不可见。 |
| children_nodes | - | isInViewport | boolean | 节点是否在当前视口内。true表示在当前视口内，false表示不在当前视口内。 |
| children_nodes | - | clickable | boolean | 节点是否可点击。true表示可点击，false表示不可点击。 |
| children_nodes | - | touchable | boolean | 节点是否可触控。true表示可触控，false表示不可触控。 |
| children_nodes | - | scrollable | boolean | 节点是否可滚动。true表示可滚动，false表示不可滚动。 |
| children_nodes | - | inputable | boolean | 节点是否可输入。true表示可输入，false表示不可输入。 |
| children_nodes | - | url | string | 节点关联URL。 |
| children_nodes | - | xpath | string | 节点XPath。 |
| children_nodes | - | hover | string | 节点`cursor`样式值。 |
| children_nodes | - | mouseover | boolean | 节点是否声明`mouseover`内联事件。true表示已声明，false表示未声明。 |
| children_nodes | - | mouseenter | boolean | 节点是否声明`mouseenter`内联事件。true表示已声明，false表示未声明。 |
| children_nodes | - | value | string | `select`元素当前选中值。 |
| children_nodes | - | options | Array\<Object> | `select`元素选项列表。 |
| children_nodes | - | value_text | Array\<Object> | `select`元素选项列表。 |
| children_nodes | options/value_text | value | string | `select`元素选项值。 |
| children_nodes | options/value_text | text | string | `select`元素选项文本。 |
| children_nodes | - | focusable | boolean | 节点是否可获取焦点。true表示可获取焦点，false表示不可获取焦点。 |
| children_nodes | - | editable | boolean | 节点是否可编辑。true表示可编辑，false表示不可编辑。 |
| children_nodes | - | settable | boolean | 节点是否可设置值。true表示可设置值，false表示不可设置值。 |
| children_nodes | - | checked | boolean | 节点是否处于选中状态。true表示处于选中状态，false表示不处于选中状态。 |
| children_nodes | - | expanded | boolean | 节点是否处于展开状态。true表示处于展开状态，false表示不处于展开状态。 |
| children_nodes | - | pressed | boolean | 节点是否处于按下状态。true表示处于按下状态，false表示不处于按下状态。 |
| children_nodes | - | selected | boolean | 节点是否处于选择状态。true表示处于选择状态，false表示不处于选择状态。 |
| children_nodes | - | required | boolean | 节点是否为必填项。true表示为必填项，false表示为非必填项。 |
| children_nodes | - | autocomplete | string | 节点自动完成信息。 |
| children_nodes | - | keyshortcuts | string | 节点`aria-keyshortcuts`属性值。 |
| children_nodes | - | attributes | Object | HTML属性集合。 |
| children_nodes | attributes | &lt;attributeName&gt; | string | HTML属性名及对应属性值。 |
| children_nodes | - | children_nodes | Array\<Object> | 当前节点的子节点列表。 |

> **说明：**
>
> - `children_nodes`中的节点字段由默认字段和`wants`共同决定。字段值为空时，部分字符串字段和`attributes`字段不会返回。
> - `getFullDom`会跳过`script`、`noscript`、`style`、`template`和`slot`元素子树。
> - `getFullDom`会遍历开放或关闭的作者Shadow DOM，不返回用户代理Shadow DOM。
> - 对于可解析的子frame，子frame根节点会合并到对应frame owner节点的`children_nodes`中。

### 请求示例

```json
{
  "method": "getFullDom",
  "params": {
    "wants": [
      "rect",
      "visible",
      "xpath"
    ]
  }
}
```

### 返回示例

```json
{
  "url": "https://www.example.com/",
  "title": "Example",
  "children_nodes": [
    {
      "tag": "html",
      "attributes": {
        "lang": "en"
      },
      "rect": {
        "x": 0,
        "y": 0,
        "width": 360,
        "height": 640
      },
      "visible": true,
      "xpath": "/html[1]",
      "children_nodes": [
        {
          "tag": "body",
          "children_nodes": [
            {
              "tag": "button",
              "attributes": {
                "id": "submit"
              },
              "rect": {
                "x": 24,
                "y": 36,
                "width": 96,
                "height": 40
              },
              "visible": true,
              "xpath": "/html[1]/body[1]/button[1]",
              "children_nodes": [
                {
                  "tag": "#text",
                  "text": "Submit",
                  "children_nodes": []
                }
              ]
            }
          ]
        }
      ]
    }
  ]
}
```

## getLiteDom

获取当前网页的轻量DOM节点列表。该命令会先根据`rules`筛选节点，再根据`wants`返回指定字段。

### LiteDomCommand

```json
{
  "method": "getLiteDom",
  "params": {
    "rules": {
      "tags": ["button", "a"],
      "isInViewport": true
    },
    "wants": [
      "id",
      "tag",
      "text",
      "rect",
      "clickable",
      "xpath",
      {
        "attributes": ["id", "class", "href"]
      }
    ]
  }
}
```

### 入参说明

| 参数 | 子参数 | 参数项 | 类型 | 必填 | 说明 |
| ---- | ---- | ---- | ---- | ---- | ---- |
| method | - | - | string | 是 | 命令名称，固定为`getLiteDom`。 |
| params | - | - | Object | 否 | 命令参数。不传入时不按规则筛选节点，并使用默认返回字段。 |
| params | rules | - | Object | 否 | 节点筛选规则。不传入时返回所有未被跳过的元素节点。 |
| params | rules | tags | Array\<string> | 否 | 按HTML标签名称筛选节点。当需要筛选特定类型的HTML元素时使用（如只获取按钮或链接），不传此条件时不按标签筛选。 |
| params | rules | attributes | Array\<string> \| Object | 否 | 按HTML属性筛选节点。传入Array时，判断节点是否包含指定属性；传入Object时，key表示属性名，value为非空字符串时表示属性值需要包含该字符串。 |
| params | rules | roles | Array\<string> | 否 | 按节点语义角色筛选节点。 |
| params | rules | clickable | boolean | 否 | 按节点是否可点击筛选。true表示筛选可点击的节点，false表示筛选不可点击的节点。 |
| params | rules | scrollable | boolean | 否 | 按节点是否可滚动筛选。true表示筛选可滚动的节点，false表示筛选不可滚动的节点。 |
| params | rules | isInViewport | boolean | 否 | 按节点是否在当前视口内筛选。true表示筛选在当前视口内的节点，false表示筛选不在当前视口内的节点。 |
| params | wants | - | Array\<string \| Object> | 否 | 指定需要在节点中追加返回的字段。`getLiteDom`会默认请求`tag`、`text`和`xpath`。 |
| params | wants | - | string | 否 | 数组项为string时，表示需要追加返回的节点信息字段，取值请参见[getLiteDom的params.wants字段取值说明](#getlitedom的paramswants字段取值说明)。 |
| params | wants | attributes | Array\<string> | 否 | 数组项为Object且包含`attributes`时，指定需要返回的HTML属性。 |

> **说明：**
>
> - `getLiteDom`默认返回当前网页的`url`、`title`和`nodes`。`nodes`中的节点默认返回`tag`、`text`和`xpath`；其中`text`在字段值为空时不会返回。
> - `isInViewport`会与其他筛选规则叠加生效。
> - `tags`、`attributes`、`roles`、`clickable`和`scrollable`之间满足任一规则即可匹配。
> - 如果未设置`tags`、`attributes`、`roles`、`clickable`和`scrollable`，则所有未被跳过的元素节点均满足筛选条件。

### getLiteDom的params.wants字段取值说明

| 取值 | 返回字段 | 返回类型 | 说明 |
| ---- | ---- | ---- | ---- |
| id | id | string | 请求返回ArkWeb生成的节点标识，不表示按HTML `id`属性筛选节点。该值由frame标识、文档作用域标识和DOM节点标识组合编码，用于区分返回结果中的节点；页面重新加载、frame重建或DOM重建后可能变化。仅在可生成节点标识时返回。如需读取HTML `id`属性，请在`wants`中通过`attributes`对象项请求`id`属性，并查看返回节点的`attributes.id`。 |
| tag | tag | string | 节点标签名。返回小写HTML标签名。 |
| text | text | string | 节点文本内容。字段值为空时不返回该字段。 |
| title | title | string | 节点`title`属性值。字段值为空时不返回该字段。 |
| aria-label | aria-label | string | 节点`aria-label`属性值。字段值为空时不返回该字段。 |
| role | role | string | 节点语义角色。字段值为空时不返回该字段。 |
| aria-description | aria-description | string | 节点`aria-description`属性值。字段值为空时不返回该字段。 |
| rect | rect | Object | 节点矩形信息，包含`x`、`y`、`width`、`height`。 |
| bounds | bounds | Object | 节点矩形信息，包含`x`、`y`、`left`、`top`、`right`、`bottom`、`width`、`height`。 |
| visible | visible | boolean | 节点是否可见。true表示可见，false表示不可见。 |
| isInViewport | isInViewport | boolean | 节点是否在当前视口内。true表示在当前视口内，false表示不在当前视口内。 |
| clickable | clickable | boolean | 节点是否可点击。true表示可点击，false表示不可点击。 |
| touchable | touchable | boolean | 节点是否可触控。true表示可触控，false表示不可触控。当前判断逻辑与`clickable`一致。 |
| scrollable | scrollable | boolean | 节点是否可滚动。true表示可滚动，false表示不可滚动。 |
| inputable | inputable | boolean | 节点是否可输入。true表示可输入，false表示不可输入。 |
| url | url | string | 节点关联URL。按`href`、`src`、`action`、`data`、`poster`顺序读取并转换为完整URL。字段值为空时不返回该字段。 |
| xpath | xpath | string | 节点XPath。字段值为空时不返回该字段。 |
| hover | hover | string | 节点`cursor`样式值。字段值为空时不返回该字段。 |
| mouseover | mouseover | boolean | 节点是否声明`mouseover`内联事件。true表示已声明，false表示未声明。 |
| mouseenter | mouseenter | boolean | 节点是否声明`mouseenter`内联事件。true表示已声明，false表示未声明。 |
| value | value | string | 当节点为`select`元素时，返回当前选中值。 |
| options | options | Array\<Object> | 当节点为`select`元素时，返回选项列表。 |
| value_text | value_text | Array\<Object> | 当节点为`select`元素时，返回选项列表。 |
| focusable | focusable | boolean | 节点是否可获取焦点。true表示可获取焦点，false表示不可获取焦点。 |
| editable | editable | boolean | 节点是否可编辑。true表示可编辑，false表示不可编辑。 |
| settable | settable | boolean | 节点是否可设置值。true表示可设置值，false表示不可设置值。 |
| checked | checked | boolean | 节点是否处于选中状态。true表示处于选中状态，false表示不处于选中状态。 |
| expanded | expanded | boolean | 节点是否处于展开状态。true表示处于展开状态，false表示不处于展开状态。 |
| pressed | pressed | boolean | 节点是否处于按下状态。true表示处于按下状态，false表示不处于按下状态。 |
| selected | selected | boolean | 节点是否处于选择状态。true表示处于选择状态，false表示不处于选择状态。 |
| required | required | boolean | 节点是否为必填项。true表示为必填项，false表示为非必填项。 |
| autocomplete | autocomplete | string | 节点自动完成信息，优先读取`aria-autocomplete`属性，其次读取`autocomplete`属性。字段值为空时不返回该字段。 |
| keyshortcuts | keyshortcuts | string | 节点`aria-keyshortcuts`属性值。字段值为空时不返回该字段。 |

### LiteDomResult

| 字段 | 子字段 | 字段项 | 类型 | 说明 |
| ---- | ---- | ---- | ---- | ---- |
| url | - | - | string | 当前网页URL。 |
| title | - | - | string | 当前网页标题。 |
| nodes | - | - | Array\<Object> | 符合筛选规则的节点列表。 |
| nodes | - | id | string | ArkWeb生成的节点标识，不是HTML `id`属性。仅在`wants`中包含`id`且可生成节点标识时返回。 |
| nodes | - | tag | string | 节点标签名。 |
| nodes | - | text | string | 节点文本内容。 |
| nodes | - | title | string | 节点`title`属性值。 |
| nodes | - | aria-label | string | 节点`aria-label`属性值。 |
| nodes | - | role | string | 节点语义角色。 |
| nodes | - | aria-description | string | 节点`aria-description`属性值。 |
| nodes | - | rect | Object | 节点矩形信息。 |
| nodes | rect | x | number | 节点矩形左上角x坐标。单位：px。 |
| nodes | rect | y | number | 节点矩形左上角y坐标，相对于当前节点所属frame的视口左上角。单位：px。 |
| nodes | rect | width | number | 节点矩形宽度。单位：px。 |
| nodes | rect | height | number | 节点矩形高度。单位：px。 |
| nodes | - | bounds | Object | 节点矩形信息。 |
| nodes | bounds | x | number | 节点矩形左上角x坐标。单位：px。 |
| nodes | bounds | y | number | 节点矩形左上角y坐标。单位：px。 |
| nodes | bounds | left | number | 节点矩形左边界。单位：px。 |
| nodes | bounds | top | number | 节点矩形上边界。单位：px。 |
| nodes | bounds | right | number | 节点矩形右边界。单位：px。 |
| nodes | bounds | bottom | number | 节点矩形下边界。单位：px。 |
| nodes | bounds | width | number | 节点矩形宽度。单位：px。 |
| nodes | bounds | height | number | 节点矩形高度。单位：px。 |
| nodes | - | visible | boolean | 节点是否可见。true表示可见，false表示不可见。 |
| nodes | - | isInViewport | boolean | 节点是否在当前视口内。true表示在当前视口内，false表示不在当前视口内。 |
| nodes | - | clickable | boolean | 节点是否可点击。true表示可点击，false表示不可点击。 |
| nodes | - | touchable | boolean | 节点是否可触控。true表示可触控，false表示不可触控。 |
| nodes | - | scrollable | boolean | 节点是否可滚动。true表示可滚动，false表示不可滚动。 |
| nodes | - | inputable | boolean | 节点是否可输入。true表示可输入，false表示不可输入。 |
| nodes | - | url | string | 节点关联URL。 |
| nodes | - | xpath | string | 节点XPath。 |
| nodes | - | hover | string | 节点`cursor`样式值。 |
| nodes | - | mouseover | boolean | 节点是否声明`mouseover`内联事件。true表示已声明，false表示未声明。 |
| nodes | - | mouseenter | boolean | 节点是否声明`mouseenter`内联事件。true表示已声明，false表示未声明。 |
| nodes | - | value | string | `select`元素当前选中值。 |
| nodes | - | options | Array\<Object> | `select`元素选项列表。 |
| nodes | - | value_text | Array\<Object> | `select`元素选项列表。 |
| nodes | options/value_text | value | string | `select`元素选项值。 |
| nodes | options/value_text | text | string | `select`元素选项文本。 |
| nodes | - | focusable | boolean | 节点是否可获取焦点。true表示可获取焦点，false表示不可获取焦点。 |
| nodes | - | editable | boolean | 节点是否可编辑。true表示可编辑，false表示不可编辑。 |
| nodes | - | settable | boolean | 节点是否可设置值。true表示可设置值，false表示不可设置值。 |
| nodes | - | checked | boolean | 节点是否处于选中状态。true表示处于选中状态，false表示不处于选中状态。 |
| nodes | - | expanded | boolean | 节点是否处于展开状态。true表示处于展开状态，false表示不处于展开状态。 |
| nodes | - | pressed | boolean | 节点是否处于按下状态。true表示处于按下状态，false表示不处于按下状态。 |
| nodes | - | selected | boolean | 节点是否处于选择状态。true表示处于选择状态，false表示不处于选择状态。 |
| nodes | - | required | boolean | 节点是否为必填项。true表示为必填项，false表示为非必填项。 |
| nodes | - | autocomplete | string | 节点自动完成信息。 |
| nodes | - | keyshortcuts | string | 节点`aria-keyshortcuts`属性值。 |
| nodes | - | attributes | Object | HTML属性集合。 |
| nodes | attributes | &lt;attributeName&gt; | string | HTML属性名及对应属性值。 |

> **说明：**
>
> - `nodes`中的节点字段由默认字段和`wants`共同决定。字段值为空时，部分字符串字段和`attributes`字段不会返回。
> - `getLiteDom`只返回元素节点，不返回文本节点。
> - `getLiteDom`会跳过`script`、`noscript`、`style`、`template`和`slot`元素子树。
> - `getLiteDom`会遍历开放或关闭的作者Shadow DOM，不返回用户代理Shadow DOM。
> - 结果包含可解析子frame中的节点。节点在每个frame内保持DOM遍历顺序，子frame节点会整体追加到当前frame节点列表之后；多个子frame的合并顺序由内部frame token集合决定。

### 请求示例

```json
{
  "method": "getLiteDom",
  "params": {
    "rules": {
      "tags": ["button", "a"],
      "isInViewport": true
    },
    "wants": [
      "id",
      "tag",
      "text",
      "rect",
      "clickable",
      "xpath",
      {
        "attributes": ["id", "class", "href"]
      }
    ]
  }
}
```

### 返回示例

```json
{
  "url": "https://www.example.com/",
  "title": "Example",
  "nodes": [
    {
      "id": "frameToken|documentToken|12",
      "tag": "button",
      "rect": {
        "x": 24,
        "y": 36,
        "width": 96,
        "height": 40
      },
      "clickable": true,
      "xpath": "/html[1]/body[1]/button[1]",
      "attributes": {
        "id": "submit",
        "class": "primary"
      }
    }
  ]
}
```

## screenCapture

获取当前网页视口截图或视口内目标元素截图，返回Base64编码的图片数据。

### ScreenCaptureCommand

### 入参说明

| 参数 | 子参数 | 参数项 | 类型 | 必填 | 说明 |
| ---- | ---- | ---- | ---- | ---- | ---- |
| method | - | - | string | 是 | 命令名称，固定为`screenCapture`。 |
| params | - | - | Object | 否 | 命令参数。不传或为空时获取当前网页视口截图。|
| params | nodeid | - | string | 否 | 目标元素的节点标识，可通过[getFullDom](#getfulldom)或[getLiteDom](#getlitedom)返回的`id`字段获取。 |
| params | xpath | - | string | 否 | 目标元素的XPath，可通过[getFullDom](#getfulldom)或[getLiteDom](#getlitedom)返回的`xpath`字段获取。 |

> **说明：**
>
> - `nodeid`与`xpath`互斥，均传入时以`nodeid`为准。两者均未传入时，默认获取当前网页视口截图。
> - 支持获取iframe元素截图，不支持跨域获取iframe内部元素截图；不支持获取同层渲染ArkUI组件的截图。

### ScreenCaptureResult

成功时返回PNG格式的Base64编码字符串。

> **说明：**
>
> - `nodeid`格式错误，返回`{"code": 392, "message": "invalid param: nodeid"}`；`nodeid`中的`frameToken`或`documentToken`与当前页面不匹配，返回`{"code": 392, "message": "invalid param: nodeid, token mismatch"}`。
> - 根据`nodeid`或`xpath`在页面中未找到目标元素，返回`{"code": 352, "message": "element not found"}`。

### 示例

通过节点标识获取目标元素截图：

```json
{
  "method": "screenCapture",
  "params": {
    "nodeid": "frameToken|documentToken|12"
  }
}
```

通过XPath获取目标元素截图：

```json
{
  "method": "screenCapture",
  "params": {
    "xpath": "/html/body/div/p[2]/a"
  }
}
```

> **说明：**
>
> - 开发者使用时需自行替换`nodeid`或`xpath`，可通过[getFullDom](#getfulldom)或[getLiteDom](#getlitedom)返回的`id`字段或`xpath`字段获取。

```ts
// xxx.ets
import { webview } from '@kit.ArkWeb';
import { BusinessError } from '@kit.BasicServicesKit';

interface CaptureParams {
  xpath?: string;
  nodeid?: string;
}

interface PageCommand {
  method: string;
  params?: CaptureParams;
}

@Entry
@Component
struct Index {
  private controller: webview.WebviewController = new webview.WebviewController();
  @State imgData: string = '';
  @State statusMsg: string = '';

  async capture() {
    this.imgData = '';
    this.statusMsg = '';

    try {
      const cmd: PageCommand = {
        method: 'screenCapture',
        params: {
          xpath: "/html/body/div/p[2]/a"
        }
      };

      const res = await this.controller.executeAIPageCommand(JSON.stringify(cmd)) as string;

      if (res.includes('"code"')) {
        this.statusMsg = `截图失败：${res} `;
        return;
      }

      this.imgData = res;
      this.statusMsg = '✅ 截图成功';
    } catch (e) {
      const error = e as BusinessError;
      this.statusMsg = `截图失败：${error.message}`;
    }
  }

  build() {
    Row() {
      Web({ src: 'https://www.example.com', controller: this.controller })
        .width('75%')
        .height('100%')

      Column({ space: 10 }) {
        Button('执行截图')
          .width('100%')
          .onClick(() => this.capture())

        Image(this.imgData ? `data:image/png;base64,${this.imgData}` : '')
          .width('100%')
          .aspectRatio(1)
          .backgroundColor('#F0F0F0')
          .objectFit(ImageFit.Contain)
          .border({ width: 1, color: '#DCDCDC' })

        if (this.statusMsg) {
          Text(this.statusMsg)
            .width('100%')
            .fontSize(12)
            .fontColor(this.statusMsg.includes('✅') ? '#4CAF50' : '#F44336')
            .textAlign(TextAlign.Center)
            .padding(8)
            .backgroundColor(this.statusMsg.includes('✅') ? '#E8F5E9' : '#FFEBEE')
            .borderRadius(4)
        }
      }
      .width('25%')
      .padding(10)
      .height('100%')
    }
    .width('100%')
    .height('100%')
  }
}
```


## getZoomLevel

获取当前网页的缩放比例。该命令为纯查询操作，不受[zoomControlAccess](./arkts-basic-components-web-attributes.md#zoomcontrolaccess22)限制。

### GetZoomLevelCommand

```json
{
  "method": "getZoomLevel",
  "params": {}
}
```

### 入参说明

| 参数 | 子参数 | 参数项 | 类型 | 必填 | 说明 |
| ---- | ---- | ---- | ---- | ---- | ---- |
| method | - | - | string | 是 | 命令名称，固定为`getZoomLevel`。 |
| params | - | - | Object | 否 | 命令参数。本命令不读取`params`内容，可传入空对象或不传入。 |

> **说明：**
>
> - 返回的`zoomLevel`字段为当前网页的缩放比例（1.0=100%），与[setZoomLevel](./arkts-apis-webview-AIPageInteraction.md#setzoomlevel)传入的语义一致。
> - [setZoomLevel](./arkts-apis-webview-AIPageInteraction.md#setzoomlevel)设置任意合法值后通过本命令读取，返回值误差不超过0.001。
> - 用户先通过CTRL+Wheel缩放，再调用本命令，返回用户当前缩放比例。

### ZoomLevelResult

| 字段 | 类型 | 说明 |
| ---- | ---- | ---- |
| code | number | 执行结果码。取值请参见[命令执行结果码说明](./arkts-apis-webview-AIPageResult.md#命令执行结果码说明)。 |
| message | string | 执行结果描述。成功时为`"success"`。 |
| zoomLevel | number | 当前网页缩放比例。成功时返回。 |

### 测试页面

```html
<!-- index.html -->
<!DOCTYPE html>
<html>
  <body>
    <h1>Zoom Level Demo</h1>
    <p>当前缩放比例可通过getZoomLevel查询，通过setZoomLevel（详见AIPageInteraction）修改。</p>
  </body>
</html>
```

### 请求示例

```json
{
  "method": "getZoomLevel",
  "params": {}
}
```

### 返回示例

成功时（页面当前缩放比例为1.5）：

```json
{
  "code": 10,
  "message": "success",
  "zoomLevel": 1.5
}
```

失败：

`132`（browser或host为空，通常表示Web实例不可用）：

```json
{
  "code": 132,
  "message": "browser or host is null"
}
```

