# Window Type Development Overview

<!--Kit: ArkUI-->
<!--Subsystem: Window-->
<!--Owner: @fei_1007-->
<!--Designer: @gcw_sPCsris4; @qinliwen0417-->
<!--Tester: @qinliwen0417-->
<!--Adviser: @ge-yafang-->
<!-- md-trans-meta sourceCommit=58ff40ad92758153f7b55166a9e6e0a0e9be5d28 translatedAt=2026-07-13T10:01:11.978Z pushedAt=2026-07-13T11:36:16.664Z -->

Windows are divided into two types: system windows and app windows.

## System Window

A system window is a window that performs system-specific functions, such as the volume bar, wallpaper, notification panel, status bar, and navigation bar. <!--Del-->For details, see [WindowType](../reference/apis-arkui/js-apis-window-sys.md#windowtype7).<!--DelEnd-->

## App Window

Different from system windows, app windows refer to windows related to app display and are used to show app content. Based on management methods and purposes, app windows can be further divided into main windows and auxiliary windows.

### Main Window

A main window is created by default when a UIAbility is created. It is displayed as an independent task card in the task management UI and is used to show the main UIAbility UI of the app.

### Auxiliary Window

Auxiliary windows are created and destroyed by the app itself. They are not displayed as an independent task card in the task management interface and can be used to show auxiliary content of the app, such as dialogs.

Auxiliary windows include:

- Subwindow

  In the stage model, created using the [createSubWindow()](../reference/apis-arkui/arkts-apis-window-WindowStage.md#createsubwindow9-1) or [createSubWindowWithOptions()](../reference/apis-arkui/arkts-apis-window-WindowStage.md#createsubwindowwithoptions11) API. For details, see [Subwindow Development Guide](subwindow-guide.md).

  When the [createSubWindowWithOptions()](../reference/apis-arkui/arkts-apis-window-WindowStage.md#createsubwindowwithoptions11) API is used with the **zLevelAboveParentLoosened** attribute set to **true**, the created subwindow is called an independent subwindow.

- Global floating window (that is, **WindowType.TYPE_FLOAT**). For details, see [Global Floating Window Development Guide](global-floating-window-guide.md).

- Dialog window (that is, **WindowType.TYPE_DIALOG**). For details, see [Dialog Window Development Guide](dialog-window-guide.md).

- [Picture-in-picture](../reference/apis-arkui/js-apis-pipWindow.md)

- [Floating ball](../reference/apis-arkui/js-apis-floatingBall.md)

- [Float view](../reference/apis-arkui/js-apis-floatView.md)