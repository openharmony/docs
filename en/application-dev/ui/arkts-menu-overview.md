# Menu Overview

<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @H-xinwei-->
<!--Designer: @zhanghaibo0-->
<!--Tester: @lxl007-->
<!--Adviser: @Brilliantry_Rui-->
<!-- md-trans-meta sourceCommit=3617037f719a273622289ce7b8b4beb6d174e3b3 translatedAt=2026-08-04T06:35:08.237Z pushedAt=2026-08-04T07:43:35.147Z -->

A menu is a pop-up window that allows users to perform specific actions. It typically appears when users right-click, long-press, or touch an item.

## When to Use

| API|Use Case |
| ----------| ----------------------------------- |
| [Menu control (Menu)](arkts-popup-and-menu-components-menu.md)| Used to bind actions to specified components, such as displaying operation options when an icon is long-pressed.|
| [Global menu independent of UI components (openMenu)](arkts-popup-and-menu-components-uicontext-menu.md)| Used to provide operation options in scenarios where UI components cannot be directly accessed, for example, in event callbacks.|

## Constraints

* When [bindMenu](../reference/apis-arkui/arkui-ts/ts-universal-attributes-menu.md#bindmenu11) is triggered via the **isShow** parameter or [bindContextMenu](../reference/apis-arkui/arkui-ts/ts-universal-attributes-menu.md#bindcontextmenu12) is triggered via the **isShown** parameter, the menu requires complete page construction before display. Therefore, avoid setting **isShow** or **isShown** to **true** during the page build phase, as this may cause incorrect menu positioning and rendering.

* When using **openMenu**, you must provide valid [TargetInfo](../reference/apis-arkui/arkts-apis-uicontext-i.md#targetinfo18). Otherwise, the menu won't display correctly.

* For details about other specifications, see [Menu Control](../reference/apis-arkui/arkui-ts/ts-universal-attributes-menu.md) and [openMenu](../reference/apis-arkui/arkts-apis-uicontext-promptaction.md#openmenu18).

## Lifecycle

The normal sequence is **aboutToAppear** > **onWillAppear** > **onAppear** > **onDidAppear** > **aboutToDisappear** > **onWillDisappear** > **onDisappear** > **onDidDisappear**.

| Name| Type| Description|
| --- | --- | --- |
| aboutToAppear  | () =>  void | Callback invoked when the menu is about to appear.|
| onAppear | () =>  void | Callback invoked after the menu appears.|
| aboutToDisappear | () =>  void | Callback invoked when the menu is about to disappear.|
| onDisappear  | () =>  void | Callback invoked after the menu disappears.|
| onWillAppear | [Callback](../reference/apis-arkui/arkui-ts/ts-types.md#callback12)\<void> | Event callback before the menu display animation starts.<br />**Note:** aboutToAppear is triggered during initialization, while onWillAppear is triggered before the animation starts. onWillAppear is executed after aboutToAppear.|
| onDidAppear | [Callback](../reference/apis-arkui/arkui-ts/ts-types.md#callback12)\<void> | Event callback after the menu pops up.<br />**Note:**<br />1. When you tap the button quickly, the menu pops up and disappears rapidly. In this case, onWillDisappear may take effect before onDidAppear.<br />2. If the menu is closed before the entrance animation completes, this callback is not triggered.<br/>3. onAppear and onDidAppear share the same trigger timing, and onDidAppear takes effect after onAppear.|
| onWillDisappear | [Callback](../reference/apis-arkui/arkui-ts/ts-types.md#callback12)\<void> | Event callback before the menu exit animation starts.<br />**Note:**<br />1. When you tap the button quickly, the menu pops up and disappears rapidly. In this case, onWillDisappear may take effect before onDidAppear.<br/>2. aboutToDisappear and onWillDisappear share the same trigger timing, and onWillDisappear takes effect after aboutToDisappear.|
| onDidDisappear | [Callback](../reference/apis-arkui/arkui-ts/ts-types.md#callback12)\<void> | Event callback after the menu disappears.<br />**Note:** onDisappear and onDidDisappear share the same trigger timing, and onDidDisappear takes effect after onDisappear.|