# 窗口旋转

<!--Kit: ArkUI-->
<!--Subsystem: Window-->
<!--Owner: @fei_1007-->
<!--Designer: @gcw_sPCsris4; @qinliwen0417-->
<!--Tester: @qinliwen0417-->
<!--Adviser: @ge-yafang-->

## 窗口旋转简介

移动设备在用户手中可以任意改变握持方向。在特定场景下，应用需要根据用户握持的方向调整显示页面，或者主动指定在固定方向显示页面，以提供更好的用户体验。比如，双手操作的游戏更倾向于在横屏显示，视频类应用更倾向于在全屏播放和小窗播放间自由切换。

提供了横竖屏旋转功能，可满足应用开发者设置应用不同方向的显示策略。

设备有四个显示方向：当用户正向握持设备时，若屏幕的宽度大于高度时，称为横屏（LANDSCAPE），与之倒置的方向则称为反向横屏（LANDSCAPE_INVERTED）；若屏幕高度大于宽度时，称为竖屏（PORTRAIT），与之倒置的方向称为反向竖屏（PORTRAIT_INVERTED）。

系统会根据应用设置的旋转策略、设备当前握持方向（重力传感器Sensor角度）、系统旋转锁定开关状态（可下拉控制中心查看/设置）、应用所处的场景（比如分屏、智慧多窗悬浮窗、应用后台等），综合判断并决定应用的显示方向。针对搭载OpenHarmony 7.0.0及以上版本的设备，系统还会结合系统智感旋转开关状态（支持智感传感器的设备，可通过**设置>系统>智感旋转**开启智感旋转开关）决定应用的显示方向。

仅主窗口支持设置旋转策略，对非主窗口设置旋转策略不生效不报错，不影响显示方向。

“应用所处的场景”影响显示方向的大致原则为：

- 若应用主窗口全屏显示，改变旋转策略后，显示方向变化会立刻生效。

- 若应用主窗口没有全屏显示，改变旋转策略后不会立刻生效，当应用主窗口进入全屏显示后方向变化才会生效。

不同旋转策略之间的差异及设备相关差异性可见[旋转策略及设备差异性](#旋转策略及设备差异性)。不同应用场景的旋转策略呈现与限制可见[旋转接口的行为限制](#旋转接口的行为限制)。

## 窗口旋转与屏幕方向的关系

通常说的窗口旋转是指应用调用[setPreferredOrientation()](../reference/apis-arkui/arkts-apis-window-Window.md#setpreferredorientation9-1)接口设置旋转策略，来改变应用在屏幕上的显示方向。更准确的说法是，应用通过旋转策略改变了屏幕的显示方向，系统通过屏幕显示方向变化，来改变屏幕上应用和系统组件（桌面、状态栏、下拉控制中心、下拉通知中心等）的显示方向和布局。这里的关键点是应用设置旋转策略后，影响的不仅是应用自身，还会影响屏幕上所有可见元素，也包括后台不可见的元素。这些元素最终通过一个旋转动画，从一个方向过渡到另外一个方向。

系统提供了屏幕属性[@ohos.display](../reference/apis-arkui/js-apis-display.md)来获取屏幕的基本信息，其中[Orientation](../reference/apis-arkui/js-apis-display.md#orientation10)即表示当前设备屏幕的显示方向。窗口旋转后屏幕属性对应的Orientation也会相应改变。需要注意，旋转策略的[Orientation](../reference/apis-arkui/arkts-apis-window-e.md#orientation9)与屏幕属性的[Orientation](../reference/apis-arkui/js-apis-display.md#orientation10)是不同的概念，尤其是四个方向代表的名称都一样，代表的含义是有所区别的。区别差异请参考[窗口方向](https://developer.huawei.com/consumer/cn/doc/best-practices/bpta-multi-device-window-direction)。

应用窗口的宽高比与屏幕属性的Orientation没有直接关系，不建议根据屏幕属性的Orientation来做窗口布局适配。屏幕属性的Orientation仅用于辅助sensor和相机的方向修正。

## 旋转接口的行为限制

应用在前台时，调用[setPreferredOrientation()](../reference/apis-arkui/arkts-apis-window-Window.md#setpreferredorientation9-1)接口设置旋转策略，系统会立刻判断当前屏幕的显示方向是否满足应用设置的旋转策略。

- 如果不满足，一般情况下系统会立刻触发一次旋转动效，调整应用的方向以满足旋转策略要求。例如：

  场景1：用户在应用旋转策略为“PORTRAIT”下竖屏握持手机，若应用改变旋转策略为“LANDSCAPE”。此时，应用显示方向会立刻旋转到横屏，即使用户仍然竖屏方向握持手机。

  场景2：用户在应用旋转策略为“PORTRAIT”下横屏握持手机，若应用改变旋转策略为“AUTO_ROTATION”。此时，应用的显示方向与握持角度不一致，应用会从竖屏显示立刻旋转到横屏显示。

- 特殊情况下，比如智慧多窗悬浮窗、分屏、多任务、应用后台、自由多窗等场景，应用设置旋转策略后，系统忽略此旋转策略，接口可正常调用，但应用显示方向并不会改变。仅当应用退出这些场景时，系统才根据应用设置的旋转策略，重新调整应用的显示布局。

  场景1：在分屏、智慧多窗悬浮窗等特殊的场景，系统为了保持显示效果，会强制应用按照竖屏方向布局显示。此时，若应用改变旋转策略为“LANDSCAPE”，应用显示方向不会变化。

  场景2：在自由多窗模式下，应用都会被强制成小窗显示。此时，若应用修改旋转策略，均不会触发旋转。

此外，应用的显示方向跟sensor强相关，在无sensor的设备上，设置旋转策略同样不会生效。比如：TV等设备没有sensor，可正常调用[setPreferredOrientation()](../reference/apis-arkui/arkts-apis-window-Window.md#setpreferredorientation9-1)接口，但实际应用方向不会变化。


## 旋转策略及设备差异性

应用可以通过在[module.json5配置文件](../quick-start/module-configuration-file.md)中配置"orientation"字段或者在运行时调用[setPreferredOrientation()](../reference/apis-arkui/arkts-apis-window-Window.md#setpreferredorientation9-1)接口设置"orientation"字段，设置应用的显示方向。无论是哪种方式设置的[orientation](../reference/apis-arkui/arkts-apis-window-e.md#orientation9)字段含义都一样，即旋转显示方向类型枚举（也叫旋转策略）。详情可参考[设置窗口的旋转策略](https://developer.huawei.com/consumer/cn/doc/best-practices/bpta-landscape-and-portrait-development#section58861731201715)。

系统提供了18种的方向类型枚举，以应对不同场景的需要。根据使用场景的不同，这些方向类型可分为：固定方向类型、自动旋转方向类型、临时方向类型和其他方向类型。

### 固定方向类型

| 名称 | 值 | 说明 |
| -------- | -------- | -------- |
| PORTRAIT | 1 | 表示竖屏显示模式。 |
| LANDSCAPE | 2 | 表示横屏显示模式。 |
| PORTRAIT_INVERTED | 3 | 表示反向竖屏显示模式。 |
| LANDSCAPE_INVERTED | 4 | 表示反向横屏显示模式。 |

这4种方向类型通常用于设置应用固定在设备的一个方向显示，如游戏类应用。不论用户如何握持设备，应用的显示方向均不会变化。

> **说明：**
> 
> 旋转策略的[Orientation](../reference/apis-arkui/arkts-apis-window-e.md#orientation9)与屏幕属性的[Orientation](../reference/apis-arkui/js-apis-display.md#orientation10)是不同的概念，尤其是四个方向代表的名称都一样，代表的含义是有所区别的。区别差异请参考[窗口方向](https://developer.huawei.com/consumer/cn/doc/best-practices/bpta-multi-device-window-direction)。

### 自动旋转方向类型

| 名称 | 值 | 说明 |
| -------- | -------- | -------- |
| AUTO_ROTATION | 5 | 跟随传感器自动旋转，可以旋转到竖屏、横屏、反向竖屏、反向横屏四个方向。 |
| AUTO_ROTATION_PORTRAIT | 6 | 跟随传感器自动竖向旋转，可以旋转到竖屏、反向竖屏，无法旋转到横屏、反向横屏。 |
| AUTO_ROTATION_LANDSCAPE | 7 | 跟随传感器自动横向旋转，可以旋转到横屏、反向横屏，无法旋转到竖屏、反向竖屏。 |
| AUTO_ROTATION_RESTRICTED | 8 | 跟随传感器自动旋转，可以旋转到竖屏、横屏、反向竖屏、反向横屏四个方向，且受控制中心的旋转开关控制。 |
| AUTO_ROTATION_PORTRAIT_RESTRICTED | 9 | 跟随传感器自动竖向旋转，可以旋转到竖屏、反向竖屏，无法旋转到横屏、反向横屏，且受控制中心的旋转开关控制。 |
| AUTO_ROTATION_LANDSCAPE_RESTRICTED | 10 | 跟随传感器自动横向旋转，可以旋转到横屏、反向横屏，无法旋转到竖屏、反向竖屏，且受控制中心的旋转开关控制。 |
| AUTO_ROTATION_UNSPECIFIED | 12 | 跟随传感器自动旋转，受控制中心的旋转开关控制，且可旋转方向受系统判定（如在某种设备，可以旋转到竖屏、横屏、反向横屏三个方向，无法旋转到反向竖屏）。 |

这7种显示方向类型，通常用于设置应用可以跟随重力传感器调整应用方向，以使得用户握持设备时应用始终保持正向显示页面。针对搭载OpenHarmony 7.0.0及以上版本的设备，新增支持设置应用跟随智感传感器调整应用方向，最终应用方向由重力传感器和智感传感器共同作用决定。

这7种方向类型根据不同的使用场景，也存在一些差异。比如：

- 带有“RESTRICTED”字样的类型“AUTO_ROTATION_RESTRICTED”、“AUTO_ROTATION_PORTRAIT_RESTRICTED”和“AUTO_ROTATION_LANDSCAPE_RESTRICTED”受控制中心的旋转开关控制。当旋转锁定打开时，设置了该类型的应用会固定在锁定的方向，不再跟随重力传感器调整页面。针对搭载OpenHarmony 7.0.0及以上版本的设备，当旋转锁定打开时，设置了该类型的应用会固定在锁定的方向，除了不再跟随重力传感器调整页面外，也不再跟随智感传感器调整页面。

- 带有“PORTRAIT”或“LANDSCAPE”的类型，将应用限制在“竖屏/反向竖屏”，“横屏/反向横屏”两个方向旋转。

- “AUTO_ROTATION_UNSPECIFIED”是比较特殊的自动旋转类型。该类型既支持自动旋转，又受控制中心旋转锁定控制，与“AUTO_ROTATION_RESTRICTED”非常类似。

> **说明：**
> 
> “AUTO_ROTATION_RESTRICTED”和“AUTO_ROTATION_UNSPECIFIED”两个旋转策略在功能上非常相似，都支持受到旋转锁定开关控制自动旋转。但在不同的产品上，这两个旋转策略还是有一些区别。
> 
> - **系统旋转锁定开关关闭**
> 
>   “AUTO_ROTATION_RESTRICTED”策略可以旋转到设备的四个方向。而“AUTO_ROTATION_UNSPECIFIED”策略，可以旋转到的方向受系统搭载的产品形态影响。在直板机或者设备处于类直板机形态时，该方向类型的应用支持旋转到竖屏、横屏、反向横屏三个方向，无法旋转到反向竖屏；而在平板或者设备处于类平板形态时，支持应用旋转到设备的四个方向。
> 
> - **系统旋转锁定开关打开**
> 
>   在直板机或者设备处于类直板机形态时，“AUTO_ROTATION_RESTRICTED”和“AUTO_ROTATION_UNSPECIFIED”都不支持锁定在横屏。当应用设置为这两个旋转策略且旋转到横屏时，再下拉控制中心开启旋转锁定，那么应用会被强制旋转到竖屏并保持旋转锁定状态。在平板或者设备处于类平板形态时， 这两个旋转策略则支持锁定在横屏。如果应用希望在直板机上支持自动旋转，且可以锁定到当前方向，则推荐优先使用“USER_ROTATION”类型的旋转策略。

### 临时方向类型

| 名称 | 值 | 说明 |
| -------- | -------- | -------- |
| USER_ROTATION_PORTRAIT | 13 | 调用时临时旋转到竖屏，之后跟随传感器自动旋转，受控制中心的旋转开关控制，且可旋转方向受系统判定。 |
| USER_ROTATION_LANDSCAPE | 14 | 调用时临时旋转到横屏，之后跟随传感器自动旋转，受控制中心的旋转开关控制，且可旋转方向受系统判定。 |
| USER_ROTATION_PORTRAIT_INVERTED | 15 | 调用时临时旋转到反向竖屏，之后跟随传感器自动旋转，受控制中心的旋转开关控制，且可旋转方向受系统判定。 |
| USER_ROTATION_LANDSCAPE_INVERTED | 16 | 调用时临时旋转到反向横屏，之后跟随传感器自动旋转，受控制中心的旋转开关控制，且可旋转方向受系统判定。 |

这4种方向类型受控制中心旋转锁定控制，同时支持根据重力传感器实现自动旋转。针对搭载OpenHarmony 7.0.0及以上版本的设备，新增支持根据智感传感器实现自动旋转（支持智感传感器的设备，可通过**设置>系统>智感旋转**开启智感旋转开关）。它们与“AUTO_ROTATION_RESTRICTED”的区别在于，这4种方向类型在应用设置时，会立即临时将应用旋转到指定方向。例如，用户竖屏握持手机且应用竖屏显示，当应用设置旋转策略为调整“USER_ROTATION_LANDSCAPE”时，应用会立刻旋转到横屏显示。这4种类型通常用于视频类应用在小窗播放进入全屏播放时使用。

> **说明：**
> 
> “USER_ROTATION_PORTRAIT_INVERTED”是比较特殊的临时方向类型，在不同的设备上有差异。
> 
> - 在直板机或设备处于类直板机形态时，设置“USER_ROTATION_PORTRAIT_INVERTED”旋转策略的应用无法临时旋转为反向竖屏，而是仍然以竖屏方向显示，且自动旋转时只能旋转到竖屏、横屏、反向横屏三个方向，无法旋转到反向竖屏。
> 
> - 在平板或者设备处于类平板形态时，在旋转锁定开关关闭时，可以支持自动旋转到竖屏、反向竖屏、横屏、反向横屏四个方向。

### 其他方向类型

| 名称 | 值 | 说明 |
| -------- | -------- | -------- |
| UNSPECIFIED | 0 | 表示未定义方向模式，由系统判定。 |
| LOCKED | 11 | 表示锁定模式。 |
| FOLLOW_DESKTOP | 17 | 表示跟随桌面的旋转模式。 |

这3种方向类型是在以下特定场景下使用的：

- “UNSPECIFIED”是未定义方向类型，即当应用既没有在module.json5文件设置，也没有在运行时调用setPreferredOrientation()设置时，系统默认应用使用该类型。此时，应用的显示方向由系统判定。通常直板机上默认竖屏显示且不支持旋转；平板上支持旋转到四个方向，且受控制中心系统旋转锁定开关控制。

- “LOCKED”是锁定模式，通常用于应用拉起应用场景。设置该策略的应用，被其他应用拉起时，保持和前一个应用相同的方向。此策略生效时，应用的方向也可能因为应用的切换等原因而改变。

- “FOLLOW_DESKTOP”是跟随桌面模式。通常直板机桌面固定竖屏显示不可旋转，平板桌面可以旋转。而折叠机比较特别，在折叠态时桌面与直板机一样不可旋转，但是在展开态时与平板规格一样可以旋转。
