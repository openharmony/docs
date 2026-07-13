# Class (WebContextMenuParam)
<!--Kit: ArkWeb-->
<!--Subsystem: Web-->
<!--Owner: @zourongchun-->
<!--Designer: @zhufenghao-->
<!--Tester: @ghiker-->
<!--Adviser: @HelloShuo-->

WebContextMenuParam是ArkWeb组件中用于承载长按页面元素或鼠标右键弹出的上下文菜单信息的参数类，作为`onContextMenuShow`事件回调的数据载体，封装了菜单弹出位置、链接地址、媒体类型、选中文本、编辑状态等关键信息。

自定义Web组件上下文菜单时，使用WebContextMenuParam获取用户长按/右击位置的网页元素详细信息（如链接URL、图片内容、媒体类型、输入框类型、编辑状态等），判断用户操作场景，决定是否拦截默认菜单并构建自定义菜单项。

自定义Web组件长按或右键菜单（如替换默认菜单、提供差异化菜单项、预览图片等）时，在`onContextMenuShow`事件回调中使用WebContextMenuParam获取上下文信息。

示例代码参考[onContextMenuShow](./arkts-basic-components-web-events.md#oncontextmenushow9)。

> **说明：**
>
> - Web组件从API version 8开始支持。WebContextMenuParam类从API version 9开始支持，后续版本的新增接口，采用上角标单独标记接口的起始版本。
>
> - 示例效果请以真机运行为准。

## constructor<sup>9+</sup>

constructor()

WebContextMenuParam的构造函数。

**系统能力：** SystemCapability.Web.Webview.Core

## x<sup>9+</sup>

x(): number

弹出菜单的x坐标，相对于Web组件左上角的水平距离。

**系统能力：** SystemCapability.Web.Webview.Core

**返回值：**

| 类型     | 说明                                 |
| ------ |------------------------------------|
| number | 获取成功时返回非负整数，失败时返回-1。<br>单位：px（物理像素）。 |

## y<sup>9+</sup>

y(): number

弹出菜单的y坐标，相对于Web组件左上角的垂直距离。

**系统能力：** SystemCapability.Web.Webview.Core

**返回值：**

| 类型     | 说明                 |
| ------ | ------------------ |
| number | 获取成功时返回非负整数，失败时返回-1。<br>单位：px（物理像素）。 |

## getLinkUrl<sup>9+</sup>

getLinkUrl(): string

获取经过安全检查的URL链接地址，用于构建自定义菜单时提供"打开链接"、"分享链接"、"复制链接"等操作。

> **说明：**
> 与getUnfilteredLinkUrl()相比，该方法会对URL进行安全检查；与getSourceUrl()相比，该方法获取的是长按位置处的链接URL，而getSourceUrl()获取的是选中元素的src属性URL（如图像、媒体等资源）。

**系统能力：** SystemCapability.Web.Webview.Core

**返回值：**

| 类型     | 说明                        |
| ------ | ------------------------- |
| string | 如果长按位置是链接，返回经过安全检查的URL链接，否则返回空字符串。 |

## getUnfilteredLinkUrl<sup>9+</sup>

getUnfilteredLinkUrl(): string

获取未经安全检查的原始URL链接地址，用于需要原始链接信息进行特殊处理（如链接分析、安全审计等）的场景。

**系统能力：** SystemCapability.Web.Webview.Core

**返回值：**

| 类型     | 说明                    |
| ------ | --------------------- |
| string | 如果长按位置是链接，返回原始的URL链接，否则返回空字符串。 |

## getSourceUrl<sup>9+</sup>

getSourceUrl(): string

获取元素的sourceUrl链接（如图片src、视频src等），用于预览媒体内容、下载资源或在自定义菜单中提供相关操作。

**系统能力：** SystemCapability.Web.Webview.Core

**返回值：**

| 类型     | 说明                       |
| ------ | ------------------------ |
| string | 如果选中的元素有src属性，返回src的URL。返回URL的最大上限为2MB，超出上限时返回空字符串。 |

## existsImageContents<sup>9+</sup>

existsImageContents(): boolean

判断当前长按位置是否存在图像内容，用于在自定义菜单中提供"保存图片"、"预览图片"、"设为壁纸"等图片相关功能。如果长按位置是图片或包含图像资源的元素，返回true，否则返回false。

**系统能力：** SystemCapability.Web.Webview.Core

**返回值：**

| 类型      | 说明                        |
| ------- | ------------------------- |
| boolean | 长按位置存在图片返回true，否则返回false。 |

## getMediaType<sup>9+</sup>

getMediaType(): ContextMenuMediaType

获取网页元素的媒体类型（如图片、视频、音频等），用于根据不同类型提供差异化的上下文菜单选项（如视频提供播放、下载，图片提供保存、预览等）。

> **说明：**
> 该方法从API 9开始支持；getContextMenuMediaType()从API 22开始支持，提供更丰富的媒体类型识别能力。如需兼容API 9及以上版本，请使用getMediaType()；如需使用API 22新增的媒体类型能力，请使用getContextMenuMediaType()。

**系统能力：** SystemCapability.Web.Webview.Core

**返回值：**

| 类型                                       | 说明        |
| ---------------------------------------- | --------- |
| [ContextMenuMediaType](./arkts-basic-components-web-e.md#contextmenumediatype9) | 网页元素的媒体类型，包括图片、视频、音频等不同类型，用于区分用户点击的网页元素种类。 |

## getSelectionText<sup>9+</sup>

getSelectionText(): string

获取菜单上下文中选中的文本内容，用于在自定义菜单中提供"复制"、"分享"、"翻译"、"搜索"等文本操作功能。

**系统能力：** SystemCapability.Web.Webview.Core

**返回值：**

| 类型     | 说明                   |
| ------ | -------------------- |
| string | 菜单上下文选中文本内容。如果存在选中的文本，返回选中的文本内容；不存在则返回空字符串。 |

## getSourceType<sup>9+</sup>

getSourceType(): ContextMenuSourceType

获取上下文菜单事件的触发来源（如鼠标右键、长按操作等），用于根据不同来源调整菜单展示样式或提供差异化的菜单选项。

**系统能力：** SystemCapability.Web.Webview.Core

**返回值：**

| 类型                                       | 说明      |
| ---------------------------------------- | ------- |
| [ContextMenuSourceType](./arkts-basic-components-web-e.md#contextmenusourcetype9) | 菜单事件的触发来源类型，包括鼠标右键、长按等不同的触发方式。 |

## getInputFieldType<sup>9+</sup>

getInputFieldType(): ContextMenuInputFieldType

获取网页元素的输入框类型（如文本框、密码框、搜索框等），用于根据输入框类型提供合适的编辑菜单选项（如文本框提供粘贴、全选，密码框只提供复制或隐藏密码等）。

**系统能力：** SystemCapability.Web.Webview.Core

**返回值：**

| 类型                                       | 说明     |
| ---------------------------------------- | ------ |
| [ContextMenuInputFieldType](./arkts-basic-components-web-e.md#contextmenuinputfieldtype9) | 网页元素输入框的类型，包括文本框、密码框、邮箱框等不同类型，用于识别当前焦点所在的输入元素种类。 |

## isEditable<sup>9+</sup>

isEditable(): boolean

根据网页元素的contenteditable属性、tagName等判断元素是否可编辑。如果元素可以编辑（如input、textarea或contenteditable元素），返回true，否则返回false。用于在自定义菜单中动态显示或隐藏编辑相关选项（如可编辑时显示粘贴、剪切、全选，不可编辑时隐藏这些选项）。

**系统能力：** SystemCapability.Web.Webview.Core

**返回值：**

| 类型      | 说明                         |
| ------- | -------------------------- |
| boolean | 返回网页元素是否可编辑。 |

## getEditStateFlags<sup>9+</sup>

getEditStateFlags(): number

获取网页元素的可编辑标识（包含具体的编辑状态信息），用于精细控制自定义菜单选项的显示逻辑（如根据是否可复制、可粘贴、可撤销等显示对应的菜单项）。

**系统能力：** SystemCapability.Web.Webview.Core

**返回值：**

| 类型     | 说明                                       |
| ------ | ---------------------------------------- |
| number | 获取网页元素可编辑标识，参照[ContextMenuEditStateFlags](./arkts-basic-components-web-e.md#contextmenueditstateflags9)。 |

## getPreviewWidth<sup>13+</sup>

getPreviewWidth(): number

获取网页元素预览图的宽，用于计算预览图的显示位置和尺寸，确保预览图在自定义菜单中正确显示。当长按或右击的元素是图片时，可调用此方法获取图片预览的宽度；如果元素不是图片或无法获取预览图，返回-1。通常与getPreviewHeight配合使用。

**系统能力：** SystemCapability.Web.Webview.Core

**返回值：**

| 类型     | 说明       |
| ------ | ----------- |
| number | 存在预览图时返回预览图的宽，否则返回-1。<br>单位：px（物理像素）。 |

## getPreviewHeight<sup>13+</sup>

getPreviewHeight(): number

获取网页元素预览图的高，用于计算预览图的显示位置和尺寸，确保预览图在自定义菜单中正确显示。当长按或右击的元素是图片时，可调用此方法获取图片预览的高度；如果元素不是图片或无法获取预览图，返回-1。通常与getPreviewWidth配合使用。

**系统能力：** SystemCapability.Web.Webview.Core

**返回值：**

| 类型     | 说明       |
| ------ | ----------  |
| number | 存在预览图时返回预览图的高，否则返回-1。<br>单位：px（物理像素）。 |

## getContextMenuMediaType<sup>22+</sup>

getContextMenuMediaType(): ContextMenuDataMediaType

在上报上下文菜单事件时，获取上下文菜单中网页元素的媒体类型。

**系统能力：** SystemCapability.Web.Webview.Core

**返回值：**

| 类型     | 说明       |
| ------ | ----------  |
| [ContextMenuDataMediaType](./arkts-basic-components-web-e.md#contextmenudatamediatype22) | 网页元素的媒体类型，包括图片、视频、音频等不同类型，用于区分用户点击的网页元素种类。 |