# 窗口开发术语
<!--Kit: ArkUI-->
<!--Subsystem: Window-->
<!--Owner: @waterwin-->
<!--Designer: @nyankomiya-->
<!--Tester: @qinliwen0417-->
<!--Adviser: @ge-yafang-->

## 自由多窗模式

自由多窗模式是一种支持用户在移动设备上进行多任务处理的交互方式。

自由多窗下，允许用户在一块屏幕上同时显示多个应用窗口。此时的应用窗口为[自由窗口](#自由窗口)。

部分Tablet设备上，可通过下拉控制中心，点击“自由多窗”按钮开启自由多窗。

![freeWindows](figures/freeWindows.png)

## 自由窗口

自由窗口是一种允许用户在同一屏幕上以自由大小、位置显示的窗口状态。自由窗口支持拖拽、缩放和分屏组合，从而实现多任务处理。

自由窗口按照打开或者获取焦点的顺序在Z轴层叠排布。当自由窗口被点击或触摸时，将导致其Z轴高度提升，并获取焦点。

启动新的自由窗口时，默认以一定间距在上一个窗口的右下方层叠显示。

每个自由窗口默认会在窗口上方显示窗口标题栏，标题栏左侧显示应用图标，右侧显示三键控制按钮（窗口最大化/还原、窗口最小化和关闭窗口），且窗口标题栏支持额外的[沉浸式配置](https://developer.huawei.com/consumer/cn/doc/best-practices/bpta-multi-device-window-immersive#section1477255312219)。

自由窗口可以通过拖动窗口边缘调节窗口大小，可以通过拖动标题栏移动窗口位置。

![freeformWindow](figures/freeformWindow.png)

当前设备支持情况：

-  **2in1设备**：2in1设备上的窗口，默认为自由窗口。
-  **Tablet设备**：部分Tablet设备，支持开启[自由多窗模式](#自由多窗模式)（通过下拉控制中心，点击“自由多窗”按钮开启），开启此模式后，应用窗口默认为自由窗口。

## 沉浸式布局

沉浸式布局也称为沉浸式模式，通常指让应用的界面更加专注于内容，不希望用户被无关元素干扰。其开发需针对不同设备的屏幕特征、交互方式和系统规范进行适配优化。
 
沉浸式布局设计可参考[沉浸体验](https://developer.huawei.com/consumer/cn/doc/design-guides/practices-overview-0000001746498066#section1610419884617)，多设备场景下不同窗口形态的沉浸式开发的实现可以参考[窗口沉浸式最佳实践](https://developer.huawei.com/consumer/cn/doc/best-practices/bpta-multi-device-window-immersive)。

沉浸式布局在Tablet设备上的自由多窗和2in1设备与phone设备的定义不是一致的：

对于Tablet设备上的自由多窗和2in1设备，当窗口的[drawableRect](../reference/apis-arkui/arkts-apis-window-i.md#windowproperties)等于窗口的[windowRect](../reference/apis-arkui/arkts-apis-window-i.md#windowproperties)时，该窗口为沉浸式布局。子窗口有标题栏时为非沉浸式布局。

对于phone设备，当窗口的[isLayoutFullScreen](../reference/apis-arkui/arkts-apis-window-i.md#windowproperties)为true时，该窗口为沉浸式布局。