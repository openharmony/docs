# 输入法开发服务术语
<!--Kit: IME Kit-->
<!--Subsystem: MiscServices-->
<!--Owner: @codexu62-->
<!--Designer: @andeszhang-->
<!--Tester: @murphy84-->
<!--Adviser: @zhang_yixin13-->

## B

### Base experience mode; 基础访问模式

对输入法应用进行安全管控的模式约束，严格遵从仅提供基础打字功能。

## C

### CustomInput; 自定义输入框

开发者自定义的文本输入控件，通过集成[InputMethodController](../reference/apis-ime-kit/js-apis-inputmethod.md#inputmethodcontroller)实现与输入法的绑定。

## D

### DARK_IMMERSIVE; 深色沉浸模式

输入法沉浸式模式的一种，使输入法面板呈现深色主题的沉浸效果。

## E

### EditorAttribute; 编辑框属性

描述编辑框的特征属性，包含inputPattern、enterKeyType、immersiveMode等字段。

### ExtensionContext; 扩展能力上下文

Extension能力的上下文环境，提供启动、停止、绑定、解绑Ability的能力。

## F

### FLAG_FIXED; 固定态

输入法面板位置固定在屏幕底部的状态类型。

### FLAG_FLOATING; 悬浮态

输入法面板可浮动移动的状态类型。

### FLAG_CANDIDATE; 候选词态

输入法面板显示用户输入候选词的状态类型。

### Full experience mode; 完整体验模式

输入法应用的完整体验模式，提供完整的输入法功能。

## I

### IME Kit; 输入法开发服务

建立编辑框所在应用与输入法应用之间的通信通道，确保文本输入功能协作，也为系统应用提供管理输入法应用的能力。

### ImmersiveEffect; 沉浸效果

输入法面板的视觉呈现效果，包括渐变模式和流光模式。

### ImmersiveMode; 沉浸模式

输入法面板的沉浸显示模式，包括浅色沉浸、深色沉浸，由输入法应用设置。

### InputMethodExtensionAbility; 输入法扩展能力

输入法Extension ability组件，支持开发者自行开发输入法应用。

### InputMethodSubtype; 输入法子类型

输入法的不同输入模式或语言，如中文键盘、英文键盘。

### input_method_config.json; 子类型配置文件

配置输入法子类型信息的JSON文件，包含子类型数组（subtypes）定义各子类型的icon、id、label、locale等属性。

### IME command tool; IME命令工具

使用IME命令管理输入法，包括查询输入法、启用/禁用输入法、切换输入法访问模式、切换当前输入法。

## K

### KeyboardAppearance; 键盘显示模式

编辑框期望的键盘显示模式，包括沉浸模式和非沉浸模式。

### KeyboardController; 键盘控制器

输入法中控制软键盘显示、事件监听、文本操作的控制器类。

## L

### LIGHT_IMMERSIVE; 浅色沉浸模式

输入法沉浸模式的一种，使输入法面板呈现浅色主题的沉浸效果。

## P

### Panel; 输入法面板

输入法应用创建的窗口组件，用于显示软键盘或状态栏。

### PanelFlag; 面板状态类型

输入法面板的状态类型枚举，包括固定态（FLAG_FIXED）、悬浮态（FLAG_FLOATING）、候选词态（FLAG_CANDIDATE）。

### PanelInfo; 面板配置信息

创建输入法面板时的配置信息，包含type（面板类型）和flag（面板状态）。

### PanelType; 面板类型枚举

输入法面板的类型枚举，包括软键盘类型（SOFT_KEYBOARD）和状态栏类型（STATUS_BAR）。

### PreviewText; 预上屏

在用户输入确认前，提前显示输入文本的预览功能。

## S

### SOFT_KEYBOARD; 软键盘

由按键组成的虚拟键盘，用于文本输入的面板类型。

### SystemPanel; 系统面板

输入法软键盘窗口在系统输入法面板中显示，输入法软键盘窗口相对系统面板存在偏移区域。
