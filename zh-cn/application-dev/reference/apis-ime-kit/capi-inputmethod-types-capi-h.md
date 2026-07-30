# inputmethod_types_capi.h
<!--Kit: IME Kit-->
<!--Subsystem: MiscServices-->
<!--Owner: @codexu62-->
<!--Designer: @andeszhang-->
<!--Tester: @murphy84-->
<!--Adviser: @zhang_yixin13-->

## 概述

提供了输入法相关的类型定义，包含键盘状态、回车键功能类型，光标移动方向等。这些类型定义用于描述输入法应用与编辑框客户端之间的交互行为。键盘状态定义了软键盘的显示和隐藏状态；回车键功能类型定义了在不同输入场景下回车键的触发行为；光标移动方向定义了光标在编辑框中的移动操作。

**引用文件：** <inputmethod/inputmethod_types_capi.h>

**库：** libohinputmethod.so

**系统能力：** SystemCapability.MiscServices.InputMethodFramework

**起始版本：** 12

**相关模块：** [InputMethod](capi-inputmethod.md)

## 汇总

### 枚举

| 名称 | typedef关键字 | 描述 |
| -- | -- | -- |
| [InputMethod_KeyboardStatus](#inputmethod_keyboardstatus) | InputMethod_KeyboardStatus | 键盘状态。定义软键盘的显示和隐藏状态，用于在OH_TextEditorProxy_SendKeyboardStatusFunc回调中标识当前键盘状态。 |
| [InputMethod_EnterKeyType](#inputmethod_enterkeytype) | InputMethod_EnterKeyType | 回车键功能类型。定义在不同输入场景下回车键的触发行为，用于配置编辑框回车键的功能语义。 |
| [InputMethod_Direction](#inputmethod_direction) | InputMethod_Direction | 移动方向。该类型定义了在编辑框中光标或选择区域的移动方向，用于支持输入法应用实现光标移动、文本选择等编辑操作。 |
| [InputMethod_ExtendAction](#inputmethod_extendaction) | InputMethod_ExtendAction | 编辑框中文本的扩展编辑操作类型。该类型定义了可以对编辑框文本执行的常用编辑操作，包括全选、剪切、复制和粘贴。这些操作与系统剪贴板协同工作，用于实现输入法应用的文本编辑功能。 |
| [InputMethod_TextInputType](#inputmethod_textinputtype) | InputMethod_TextInputType | 文本输入类型。用于指定文本编辑框支持的输入类型，以便系统适配相应的输入法键盘。例如：NUMBER类型用于数字输入场景（如密码输入框、年龄输入框）；EMAIL_ADDRESS类型用于邮箱地址输入场景；URL类型用于网址输入场景。 |
| [InputMethod_CommandValueType](#inputmethod_commandvaluetype) | InputMethod_CommandValueType | 表示输入法扩展功能的私有数据类型。该类型定义了InputMethod_PrivateCommand中value的数据类型，用于支持输入法应用与客户端之间的私有参数传递。 |
| [InputMethod_ErrorCode](#inputmethod_errorcode) | InputMethod_ErrorCode | 输入法错误码。该类型定义了输入法框架中可能出现的错误码，涵盖了参数检查失败、包管理异常、输入法应用异常、输入框客户端异常等各种错误场景。开发者应根据具体的错误码判断错误类型并采取相应的错误处理措施。详细错误处理说明请参见[输入法框架错误码](errorcode-inputmethod-framework.md)。 |
| [InputMethod_RequestKeyboardReason](#inputmethod_requestkeyboardreason) | InputMethod_RequestKeyboardReason | 表示请求键盘输入的原因。用于区分不同的键盘触发场景，以便输入法进行针对性适配。 |

## 枚举类型说明

### InputMethod_KeyboardStatus

```c
enum InputMethod_KeyboardStatus
```

**描述**

键盘状态枚举，定义软键盘的显示和隐藏状态。该枚举用于在OH_TextEditorProxy_SendKeyboardStatusFunc回调中标识当前键盘的状态变化，编辑框客户端可根据键盘状态调整界面布局（如键盘弹起时避让编辑框区域）。

用途：标识软键盘的当前状态，用于编辑框客户端响应键盘显示/隐藏事件。

取值建议：在处理SendKeyboardStatusFunc回调时，根据IME_KEYBOARD_STATUS_SHOW调整界面避让键盘区域，根据IME_KEYBOARD_STATUS_HIDE恢复原始布局。IME_KEYBOARD_STATUS_NONE通常作为初始状态或过渡状态出现，一般不需要特殊处理。

枚举值间关系：枚举值从0开始连续递增（NONE→HIDE→SHOW），表示键盘状态从无状态→隐藏→显示的递进变化。

**起始版本：** 12

| 枚举项 | 描述 |
| -- | -- |
| IME_KEYBOARD_STATUS_NONE = 0 | 表示键盘状态为NONE，即键盘状态尚未确定或处于初始状态。该值通常在输入法框架初始化阶段使用，表示键盘尚未显示或隐藏的状态。在实际交互中较少出现，编辑框客户端一般不需要对NONE状态做特殊处理。 |
| IME_KEYBOARD_STATUS_HIDE = 1 | 键盘状态为隐藏，表示软键盘已收起或未弹出。编辑框客户端收到此状态后可恢复界面布局（如取消避让区域、恢复编辑框原始位置），因为键盘不再占据屏幕底部区域。 |
| IME_KEYBOARD_STATUS_SHOW = 2 | 键盘状态为显示，表示软键盘已弹出并占据屏幕底部区域。编辑框客户端收到此状态后应调整界面布局（如避让键盘区域、上移编辑框），确保输入区域不被键盘遮挡。 |

### InputMethod_EnterKeyType

```c
enum InputMethod_EnterKeyType
```

**描述**

回车键功能类型枚举，定义在不同输入场景下回车键的触发行为。该枚举用于配置编辑框的回车键功能语义，输入法框架根据EnterKeyType在键盘上显示对应的功能标签（如"搜索"、"发送"、"下一步"等），并触发相应的交互行为。

用途：指定编辑框回车键的功能语义，影响输入法键盘上回车键的标签和行为。

取值建议：根据编辑框的实际交互场景选择对应的EnterKeyType。搜索场景使用IME_ENTER_KEY_SEARCH，发送消息场景使用IME_ENTER_KEY_SEND，表单填写场景使用IME_ENTER_KEY_NEXT或IME_ENTER_KEY_DONE，多行文本输入场景使用IME_ENTER_KEY_NEWLINE。不确定场景使用IME_ENTER_KEY_UNSPECIFIED，系统将使用默认行为。

枚举值间关系：枚举值从0开始连续递增（0-8），共9个枚举项。各值之间无互斥关系，每个编辑框可独立配置一种EnterKeyType。IME_ENTER_KEY_UNSPECIFIED（0）和IME_ENTER_KEY_NONE（1）的区别在于：UNSPECIFIED表示未指定（系统使用默认行为），NONE表示明确指定回车键无特殊功能。

**起始版本：** 12

| 枚举项 | 描述 |
| -- | -- |
| IME_ENTER_KEY_UNSPECIFIED = 0 | 未指定，表示编辑框未明确设置回车键功能类型。系统将使用默认回车键行为（通常等同于换行）。适用于不需要特殊回车键行为的普通文本输入场景。 |
| IME_ENTER_KEY_NONE = 1 | 回车键功能类型为NONE，明确指定回车键无特殊功能。回车键将不触发任何特定行为，仅作为普通按键处理。适用于回车键不需要触发任何动作的场景。 |
| IME_ENTER_KEY_GO = 2 | 前往，表示回车键的功能为"前往"。按下回车键将触发导航到目标地址的操作。适用于URL输入框、浏览器地址栏等需要跳转到指定链接的场景。键盘上回车键标签显示为"前往"。 |
| IME_ENTER_KEY_SEARCH = 3 | 搜索，表示回车键的功能为"搜索"。按下回车键将触发搜索操作。适用于搜索输入框、搜索引擎等需要执行搜索查询的场景。键盘上回车键标签显示为"搜索"。 |
| IME_ENTER_KEY_SEND = 4 | 发送，表示回车键的功能为"发送"。按下回车键将触发发送消息或数据的操作。适用于即时消息输入框、邮件发送等需要提交发送内容的场景。键盘上回车键标签显示为"发送"。 |
| IME_ENTER_KEY_NEXT = 5 | 下一步，表示回车键的功能为"下一步"。按下回车键将焦点移动到下一个输入框。适用于多字段表单填写场景（如注册表单、地址填写），用户按下回车后自动跳转到下一个输入项。键盘上回车键标签显示为"下一步"。 |
| IME_ENTER_KEY_DONE = 6 | 完成，表示回车键的功能为"完成"。按下回车键将结束当前输入并关闭键盘。适用于表单最后一个输入框、确认输入等需要表示输入完成的场景。键盘上回车键标签显示为"完成"。 |
| IME_ENTER_KEY_PREVIOUS = 7 | 上一步，表示回车键的功能为"上一步"。按下回车键将焦点移动到上一个输入框。适用于多字段表单中需要返回上一个输入项的场景。键盘上回车键标签显示为"上一步"。 |
| IME_ENTER_KEY_NEWLINE = 8 | 换行，表示回车键的功能为"换行"。按下回车键将在文本中插入新行。适用于多行文本编辑场景（如备忘录、笔记编辑），用户需要通过回车键在文本中添加换行符。键盘上回车键标签显示为"换行"。 |

### InputMethod_Direction

```c
enum InputMethod_Direction
```

**描述**

移动方向枚举，定义了在编辑框中光标或选择区域的移动方向，用于支持输入法应用实现光标移动、文本选择等编辑操作。该枚举作为OH_TextEditorProxy_MoveCursorFunc回调的参数传入，指示输入法请求光标移动的方向。

用途：指定光标在编辑框中的移动方向，用于输入法应用控制光标位置。

取值建议：在实现MoveCursorFunc回调时，根据direction值移动光标。IME_DIRECTION_NONE通常表示无需移动，IME_DIRECTION_UP/DOWN用于垂直方向移动（多行文本场景），IME_DIRECTION_LEFT/RIGHT用于水平方向移动（单行或多行文本场景）。

枚举值间关系：枚举值从0开始连续递增（0-4），共5个枚举项。四个方向值（UP/DOWN/LEFT/RIGHT）覆盖了二维平面上的基本移动方向，NONE作为无移动的标识。UP和DOWN互为反向，LEFT和RIGHT互为反向。

**起始版本：** 12

| 枚举项 | 描述 |
| -- | -- |
| IME_DIRECTION_NONE = 0 | 无移动方向，表示光标不需要移动。该值通常作为默认值或占位值使用，输入法应用在不需要移动光标时传入此值。 |
| IME_DIRECTION_UP = 1 | 向上，表示光标向上移动一行。适用于多行文本编辑场景，输入法应用通过此值请求将光标从当前行移动到上一行。在单行文本场景中，向上移动通常无实际效果。 |
| IME_DIRECTION_DOWN = 2 | 向下，表示光标向下移动一行。适用于多行文本编辑场景，输入法应用通过此值请求将光标从当前行移动到下一行。在单行文本场景中，向下移动通常无实际效果。 |
| IME_DIRECTION_LEFT = 3 | 向左，表示光标向左移动一个字符位置。适用于所有文本编辑场景，输入法应用通过此值请求将光标前移一个字符。常用于删除前向文本后的光标回退操作。 |
| IME_DIRECTION_RIGHT = 4 | 向右，表示光标向右移动一个字符位置。适用于所有文本编辑场景，输入法应用通过此值请求将光标后移一个字符。常用于插入文本后的光标前进操作。 |

### InputMethod_ExtendAction

```c
enum InputMethod_ExtendAction
```

**描述**

编辑框中文本的扩展编辑操作类型枚举，定义了可以对编辑框文本执行的常用编辑操作，包括全选、剪切、复制和粘贴。这些操作与系统剪贴板协同工作，用于实现输入法应用的文本编辑功能。该枚举作为OH_TextEditorProxy_HandleExtendActionFunc回调的参数传入，指示输入法请求执行的编辑操作。

用途：指定输入法请求编辑框执行的文本编辑操作类型。

取值建议：在实现HandleExtendActionFunc回调时，根据action值执行对应的编辑操作。IME_EXTEND_ACTION_SELECT_ALL选中全部文本，IME_EXTEND_ACTION_CUT将选中文本剪切到剪贴板并删除原文本，IME_EXTEND_ACTION_COPY将选中文本复制到剪贴板（不删除原文本），IME_EXTEND_ACTION_PASTE将剪贴板内容插入到光标位置。

枚举值间关系：枚举值不连续（0, 3, 4, 5），SELECT_ALL值为0，CUT/COPY/PASTE值为3-5。这种不连续设计是因为CUT/COPY/PASTE属于剪贴板操作组（值连续），而SELECT_ALL属于独立操作。SELECT_ALL通常作为CUT/COPY的前置操作——先全选再剪切/复制。CUT和COPY互斥：CUT删除原文本，COPY保留原文本。

**起始版本：** 12

| 枚举项 | 描述 |
| -- | -- |
| IME_EXTEND_ACTION_SELECT_ALL = 0 | 全选，选中编辑框中的全部文本内容。该操作不涉及剪贴板，仅改变文本选择范围。常作为CUT或COPY操作的前置步骤——先全选再剪切或复制。执行后编辑框中的所有文本处于选中状态，用户可进一步操作（如剪切、复制）。 |
| IME_EXTEND_ACTION_CUT = 3 | 剪切，将编辑框中当前选中的文本剪切到系统剪贴板，同时从编辑框中删除被选中的文本。该操作需要编辑框中已有选中文本才能执行。剪切后剪贴板中保存被删除的文本内容，可通过PASTE操作粘贴到其他位置。适用于需要移动文本的场景。 |
| IME_EXTEND_ACTION_COPY = 4 | 复制，将编辑框中当前选中的文本复制到系统剪贴板，编辑框中的原文本保持不变。该操作需要编辑框中已有选中文本才能执行。复制后剪贴板中保存文本副本，可通过PASTE操作粘贴到其他位置。适用于需要重复文本的场景。与CUT的区别在于：COPY保留原文本，CUT删除原文本。 |
| IME_EXTEND_ACTION_PASTE = 5 | 粘贴，将系统剪贴板中的文本内容插入到编辑框光标位置。该操作需要系统剪贴板中有文本内容才能执行。粘贴后剪贴板内容被插入到光标所在位置，原光标后的文本自动后移。适用于需要将剪贴板文本插入编辑框的场景。 |

### InputMethod_TextInputType

```c
enum InputMethod_TextInputType
```

**描述**

文本输入类型枚举，用于指定文本编辑框支持的输入类型，以便系统适配相应的输入法键盘。不同的TextInputType将触发输入法框架展示不同的键盘布局（如数字键盘、邮箱键盘、URL键盘等），并设置相应的输入过滤规则。该枚举作为InputMethod_TextConfig的inputType属性，通过OH_TextConfig_SetInputType设置，通过OH_TextConfig_GetInputType获取。

用途：指定编辑框的文本输入类型，影响输入法键盘布局和输入过滤规则。

取值建议：根据编辑框的实际输入内容选择最匹配的TextInputType。普通文本使用IME_TEXT_INPUT_TYPE_TEXT，多行文本使用IME_TEXT_INPUT_TYPE_MULTILINE，纯数字使用IME_TEXT_INPUT_TYPE_NUMBER，密码使用IME_TEXT_INPUT_TYPE_VISIBLE_PASSWORD或IME_TEXT_INPUT_TYPE_NEW_PASSWORD，邮箱使用IME_TEXT_INPUT_TYPE_EMAIL_ADDRESS，验证码使用IME_TEXT_INPUT_TYPE_ONE_TIME_CODE。不确定类型时使用IME_TEXT_INPUT_TYPE_NONE（-1），系统将使用默认键盘布局。

枚举值间关系：枚举值从-1开始，NONE为-1，其余值从0开始连续递增（0-13），共14个枚举项。NONE（-1）为特殊值，表示未指定输入类型，与TEXT（0）的区别在于：NONE不触发特定键盘适配，TEXT触发普通文本键盘。密码相关类型（VISIBLE_PASSWORD=7、NUMBER_PASSWORD=8、SCREEN_LOCK_PASSWORD=9、NEW_PASSWORD=11）自成一组，系统对密码类型输入框可能启用安全输入模式。数字相关类型（NUMBER=2、NUMBER_PASSWORD=8、NUMBER_DECIMAL=12）将触发数字键盘布局。

**起始版本：** 12

| 枚举项 | 描述 |
| -- | -- |
| IME_TEXT_INPUT_TYPE_NONE = -1 | 文本输入类型为NONE，表示编辑框未指定特定的输入类型。系统将使用默认键盘布局，不针对特定输入场景进行优化。适用于不需要特殊键盘适配的场景或作为占位值使用。 |
| IME_TEXT_INPUT_TYPE_TEXT = 0 | 文本类型，表示编辑框接受普通文本输入。系统将展示标准文本键盘布局，支持字母、数字和符号输入。适用于一般的文本输入场景（如备注、评论等）。 |
| IME_TEXT_INPUT_TYPE_MULTILINE = 1 | 多行类型，表示编辑框支持多行文本输入。系统将展示支持换行的文本键盘布局，回车键功能为换行而非完成。适用于需要输入多段文本的场景（如备忘录、笔记编辑等）。 |
| IME_TEXT_INPUT_TYPE_NUMBER = 2 | 数字类型，表示编辑框仅接受数字输入。系统将展示数字键盘布局，仅包含0-9数字键。适用于纯数字输入场景（如年龄、数量、密码输入框等）。 |
| IME_TEXT_INPUT_TYPE_PHONE = 3 | 电话号码类型，表示编辑框接受电话号码输入。系统将展示电话号码键盘布局，包含0-9数字键及常用的电话号码符号（如+、-、*、#）。适用于电话号码输入场景。 |
| IME_TEXT_INPUT_TYPE_DATETIME = 4 | 日期类型，表示编辑框接受日期和时间输入。系统将展示日期输入键盘布局，包含数字和日期相关符号。适用于日期、时间输入场景（如日期选择器输入框）。 |
| IME_TEXT_INPUT_TYPE_EMAIL_ADDRESS = 5 | 邮箱地址类型，表示编辑框接受邮箱地址输入。系统将展示邮箱键盘布局，键盘上提供@和.com等邮箱地址常用符号的快捷键。适用于邮箱地址输入场景（如登录邮箱、注册表单邮箱字段）。 |
| IME_TEXT_INPUT_TYPE_URL = 6 | 链接类型，表示编辑框接受URL网址输入。系统将展示URL键盘布局，键盘上提供/、.com、.cn等网址常用符号的快捷键。适用于网址输入场景（如浏览器地址栏、链接输入框）。 |
| IME_TEXT_INPUT_TYPE_VISIBLE_PASSWORD = 7 | 密码类型，表示编辑框接受密码输入，且密码内容可见（非隐藏显示）。系统将展示文本键盘布局，但可能启用安全输入模式（如禁用截图、预览文本等）。适用于需要查看输入密码的场景（如密码确认输入框）。 |
| IME_TEXT_INPUT_TYPE_NUMBER_PASSWORD = 8 | 数字密码类型，表示编辑框仅接受数字密码输入。系统将展示数字键盘布局，并可能启用安全输入模式。适用于仅需数字密码的场景（如PIN码输入框、4位/6位数字密码输入框）。 |
| IME_TEXT_INPUT_TYPE_SCREEN_LOCK_PASSWORD = 9 | 锁屏密码类型，表示编辑框接受锁屏密码输入。系统将展示专用密码键盘布局，并启用最高级别的安全输入模式。适用于设备锁屏解锁密码输入场景。 |
| IME_TEXT_INPUT_TYPE_USER_NAME = 10 | 用户名类型，表示编辑框接受用户名输入。系统将展示文本键盘布局，可能提供用户名输入的优化（如自动补全建议）。适用于登录注册场景中的用户名输入框。 |
| IME_TEXT_INPUT_TYPE_NEW_PASSWORD = 11 | 新密码类型，表示编辑框接受新密码输入（如注册或修改密码场景）。系统将展示密码键盘布局，并可能启用安全输入模式和密码强度提示。适用于创建新密码或修改密码的输入场景。 |
| IME_TEXT_INPUT_TYPE_NUMBER_DECIMAL = 12 | 数字小数类型，表示编辑框接受带小数点的数字输入。系统将展示数字键盘布局，并额外提供小数点按键。适用于需要输入小数的场景（如金额输入、数值参数输入等）。 |
| IME_TEXT_INPUT_TYPE_ONE_TIME_CODE = 13 | 验证码类型，表示编辑框接受一次性验证码输入。系统将展示数字键盘布局，并可能从短信中自动提取验证码填充。适用于短信验证码、OTP验证码等自动填充场景。**起始版本：** 20 |

### InputMethod_CommandValueType

```c
enum InputMethod_CommandValueType
```

**描述**

私有数据类型枚举，定义了InputMethod_PrivateCommand中value的数据类型，用于支持输入法应用与客户端之间的私有参数传递。每个PrivateCommand实例只能持有一种类型的value，通过OH_PrivateCommand_GetValueType获取当前value的类型后，再调用对应的GetValue函数获取实际值。

用途：标识PrivateCommand实例中value的数据类型，指导接收方选择正确的GetValue函数。

取值建议：在获取PrivateCommand的value值之前，必须先通过OH_PrivateCommand_GetValueType获取类型，再根据类型选择对应的GetValue函数：IME_COMMAND_VALUE_TYPE_BOOL调用OH_PrivateCommand_GetBoolValue，IME_COMMAND_VALUE_TYPE_INT32调用OH_PrivateCommand_GetIntValue，IME_COMMAND_VALUE_TYPE_STRING调用OH_PrivateCommand_GetStrValue。IME_COMMAND_VALUE_TYPE_NONE表示未设置value，此时不应调用任何GetValue函数。

枚举值间关系：枚举值从0开始连续递增（0-3），共4个枚举项。NONE（0）为初始状态，表示PrivateCommand创建后尚未设置value。STRING/BOOL/INT32三个值类型互斥，同一个PrivateCommand实例在任意时刻只能持有其中一种类型的value。设置一种类型的value后，之前设置的value及其类型将被覆盖。

**起始版本：** 12

| 枚举项 | 描述 |
| -- | -- |
| IME_COMMAND_VALUE_TYPE_NONE = 0 | 私有数据类型为NONE，表示PrivateCommand实例尚未设置任何value值。该值为PrivateCommand创建后的默认类型状态，调用任何GetValue函数（GetBoolValue/GetIntValue/GetStrValue）将返回IME_ERR_QUERY_FAILED错误码。 |
| IME_COMMAND_VALUE_TYPE_STRING = 1 | 字符串类型，表示PrivateCommand实例的value为字符串数据。对应的设置函数为OH_PrivateCommand_SetStrValue，获取函数为OH_PrivateCommand_GetStrValue。适用于传递文本配置、URL、JSON格式参数等字符串语义的数据。 |
| IME_COMMAND_VALUE_TYPE_BOOL = 2 | 布尔类型，表示PrivateCommand实例的value为布尔数据（true或false）。对应的设置函数为OH_PrivateCommand_SetBoolValue，获取函数为OH_PrivateCommand_GetBoolValue。适用于传递开关状态、是否启用某功能等布尔语义的数据。 |
| IME_COMMAND_VALUE_TYPE_INT32 = 3 | 32位带符号整数类型，表示PrivateCommand实例的value为int32_t整数数据。对应的设置函数为OH_PrivateCommand_SetIntValue，获取函数为OH_PrivateCommand_GetIntValue。适用于传递数值参数、计数、版本号等整数语义的数据。 |

### InputMethod_ErrorCode

```c
enum InputMethod_ErrorCode
```

**描述**

输入法错误码枚举，定义了输入法框架中可能出现的错误码，涵盖了参数检查失败、包管理异常、输入法应用异常、输入框客户端异常等各种错误场景。开发者应根据具体的错误码判断错误类型并采取相应的错误处理措施。详细错误处理说明请参见[输入法框架错误码](errorcode-inputmethod-framework.md)。

用途：标识输入法框架中各类操作的执行结果和错误类型，用于接口返回值判断和错误处理。

取值建议：在调用输入法C API接口后，应检查返回值是否为IME_ERR_OK（0）。若返回非IME_ERR_OK值，根据具体错误码采取相应处理：IME_ERR_NULL_POINTER检查参数是否为NULL；IME_ERR_PARAMCHECK检查参数类型和范围；IME_ERR_IMCLIENT/IME_ERR_DETACHED检查输入框与输入法服务的连接状态；IME_ERR_IMENGINE检查输入法应用运行状态；IME_ERR_QUERY_FAILED检查查询条件和数据状态。

枚举值间关系：枚举值分为三组：通用错误码（0, 1, 401）、框架服务错误码（12800001-12800009）、C API专用错误码（12802000-12802001）。通用错误码适用于所有接口；框架服务错误码与系统服务状态相关；C API专用错误码针对C语言接口特有的空指针和查询失败场景。IME_ERR_OK（0）为成功标识，其余值为错误标识。

**起始版本：** 12

| 枚举项 | 描述 |
| -- | -- |
| IME_ERR_OK = 0 | 成功。表示操作正常完成，无需额外处理。所有输入法C API接口在正常执行后均返回此值。开发者无需对此错误码执行任何错误处理逻辑。 |
| IME_ERR_UNDEFINED = 1 | 未定义错误。可能是系统内部异常导致，建议检查系统日志并联系技术支持。该错误码表示输入法框架发生了无法归类到其他具体错误码的内部异常。 |
| IME_ERR_PARAMCHECK = 401 | 参数检查失败。可能是参数类型、范围或格式不正确，请检查输入参数是否符合接口要求。该错误码在传入参数不符合接口规格（如参数类型错误、字符串长度超出限制等）时返回。 |
| IME_ERR_PACKAGEMANAGER = 12800001 | 包管理异常。可能是输入法应用未正确安装或包信息异常，请检查输入法应用状态并重新安装。该错误码在系统包管理服务无法正确获取输入法应用信息时返回。 |
| IME_ERR_IMENGINE = 12800002 | 输入法应用异常。可能是输入法应用崩溃或未运行，建议重启输入法应用或切换到其他输入法。该错误码在输入法引擎无法正常工作时返回。 |
| IME_ERR_IMCLIENT = 12800003 | 输入框客户端异常。可能是输入框与输入法服务连接异常，请检查应用是否正确绑定输入法服务。该错误码在编辑框客户端与输入法服务之间的通信异常时返回。 |
| IME_ERR_CONFIG_PERSIST = 12800005 | 配置固化失败。当保存输入法配置到持久化存储失败时，会报此错误码。例如：保存输入法设置、切换输入法等场景。该错误码在输入法框架无法将配置变更持久化保存时返回。建议检查存储权限和存储空间是否充足，或稍后重试。 |
| IME_ERR_CONTROLLER = 12800006 | 输入法控制器异常。可能是输入法控制器初始化失败或服务异常，建议检查系统服务状态或重启设备。该错误码在输入法控制器无法正常工作时返回。 |
| IME_ERR_SETTINGS = 12800007 | 输入法设置器异常。可能是输入法设置参数无效或权限不足，请检查设置参数和权限配置。该错误码在输入法设置服务无法正常处理配置变更时返回。 |
| IME_ERR_IMMS = 12800008 | 输入法管理服务异常。可能是输入法管理服务未启动或异常终止，建议检查系统服务状态或重启输入法管理服务。该错误码在输入法管理服务（IMMS）无法正常工作时返回。 |
| IME_ERR_DETACHED = 12800009 | 输入框未绑定。可能是输入框与输入法服务未建立连接，请调用绑定接口重新建立连接。该错误码在编辑框未通过OH_InputMethodController_Attach绑定输入法服务时调用需要绑定关系的接口时返回。 |
| IME_ERR_NULL_POINTER = 12802000 | 空指针异常。可能是传入的参数为空指针，请检查输入参数是否正确初始化。该错误码在C API接口收到NULL指针参数时返回，属于C语言特有的参数错误类型。开发者应在调用接口前确保所有指针参数均为非NULL。 |
| IME_ERR_QUERY_FAILED = 12802001 | 查询失败。可能是查询条件无效或目标数据不存在，请检查查询参数和数据状态。该错误码在Get类接口的查询条件与实际数据不匹配时返回，典型场景：OH_PrivateCommand_GetBoolValue在value实际类型为int32_t时调用，将返回此错误码表示类型不匹配——命令中没有布尔值。 |

### InputMethod_RequestKeyboardReason

```c
enum InputMethod_RequestKeyboardReason
```

**描述**

请求键盘输入原因枚举，定义了触发键盘请求的不同触发源，用于区分不同的键盘触发场景，以便输入法进行针对性适配。该枚举作为InputMethod_AttachOptions的requestKeyboardReason属性，通过OH_InputMethodProxy_ShowTextInput传递给输入法框架。区分触发原因可以帮助输入法应用针对不同的交互场景优化键盘行为和输入体验。

用途：标识触发键盘弹出的原因（鼠标点击、触摸操作或其他），用于输入法应用针对性优化。

取值建议：根据实际触发场景选择对应的RequestKeyboardReason。鼠标点击输入框触发使用IME_REQUEST_REASON_MOUSE，触摸输入框触发使用IME_REQUEST_REASON_TOUCH，其他触发方式（如API调用、焦点切换等）使用IME_REQUEST_REASON_OTHER。不确定触发原因时使用IME_REQUEST_REASON_NONE，输入法将使用默认行为。

枚举值间关系：枚举值不连续（0, 1, 2, 20），NONE/MOUSE/TOUCH为常规触发源（值0-2连续），OTHER为特殊触发源（值20）。MOUSE和TOUCH分别代表两种最常见的用户直接交互触发方式，OTHER涵盖了所有非直接交互的触发场景。NONE不表示任何触发原因，通常作为默认值使用。

**起始版本：** 15

| 枚举项 | 描述 |
| -- | -- |
| IME_REQUEST_REASON_NONE = 0 | 表示没有特定的原因触发键盘请求。该值通常作为默认值使用，输入法框架将使用默认的键盘弹出行为。适用于不需要区分触发原因的场景或作为AttachOptions的初始值。 |
| IME_REQUEST_REASON_MOUSE = 1 | 表示键盘请求是由鼠标操作触发的。用户通过鼠标点击输入框区域触发键盘弹出，输入法应用可针对鼠标交互场景优化键盘行为（如提供更精确的光标定位、适配鼠标操作习惯的键盘布局）。适用于桌面设备或支持鼠标输入的平板设备场景。 |
| IME_REQUEST_REASON_TOUCH = 2 | 表示键盘请求是由触摸操作触发的。用户通过手指触摸输入框区域触发键盘弹出，输入法应用可针对触摸交互场景优化键盘行为（如提供更大的按键间距、适配触摸操作的键盘布局）。适用于移动设备的手指触摸交互场景。 |
| IME_REQUEST_REASON_OTHER = 20 | 表示键盘请求是由其他原因触发的，包括但不限于：程序主动调用ShowKeyboard/ShowTextInput接口、焦点自动切换、配置变更触发等非直接用户交互场景。输入法应用可针对此类场景做特殊适配（如不弹出过渡动画、使用紧凑键盘布局）。 |
