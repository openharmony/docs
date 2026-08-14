# Window Z-Order

<!--Kit: ArkUI-->
<!--Subsystem: Window-->
<!--Owner: @fei_1007-->
<!--Designer: @gcw_sPCsris4-->
<!--Tester: @qinliwen0417-->
<!--Adviser: @ge-yafang-->
<!-- md-trans-meta sourceCommit=58ff40ad92758153f7b55166a9e6e0a0e9be5d28 translatedAt=2026-07-13T10:01:23.573Z pushedAt=2026-07-13T12:09:08.568Z -->

## When to Use

**Window z-order** (**ZOrder**) refers to the stacking order of multiple windows on the screen, which determines the front-to-back display relationship of windows.

The larger the z-order value, the closer the window is displayed to the front and can cover windows with smaller z-order values. Conversely, windows with smaller z-order values may be obscured by other windows.

For third-party apps, the z-order of a window cannot be directly modified, but the display z-order of subwindows can be indirectly affected by controlling the **zLevel** attribute.

The system controls the visibility and interaction priority of the user interface by managing **ZOrder** and **zLevel**.

This section systematically explains the window z-order management mechanism from five aspects: basic concepts, z-order rules, parent-child window relationships, the TopMost window mechanism, and related API examples.

## Basic Concepts and Z-Order Rules

### ZOrder and zLevel

**ZOrder** represents the window stacking order maintained internally by the system. The larger the value, the closer the window is to the front. Third-party apps cannot directly modify **ZOrder**.

**zLevel** represents the relative z-order between subwindows within an app that can be controlled by third-party apps, and is only effective for non-modal subwindows. The value range of zLevel is [-10000, 10000], and the default value is **0**. The greater the **zLevel** value, the larger the corresponding **ZOrder**, and the closer the window is to the front.

### Z-Order Rules for Window zLevel

- **Subwindows with different zLevels**

  - A window with a higher zLevel always covers a window with a lower zLevel. Even if a window with a lower zLevel is clicked, it will not be raised above the window with a higher zLevel.

- **Subwindows with the same zLevel**

  - By default, the window created later has a higher z-order.

  - When the user taps a subwindow, its z-order is raised to the highest position within the same zLevel, implementing "tap-to-top."

  - If [setRaiseByClickEnabled()](../reference/apis-arkui/arkts-apis-window-Window.md#setraisebyclickenabled14) is called with **false**, the raise-on-tap feature is disabled, and the z-order remains unchanged when tapped.

### Z-Order Rules for Window Types

- **Z-order adjustment for windows of the same type**

  For windows of the same type (multiple main windows, multiple regular subwindows), the z-order can be adjusted by tapping or using shortcuts (such as **Alt+Tab**).

- **Default z-order of in-app subwindow types**

  The system assigns default z-orders to different types of subwindows. The priorities from high to low are as follows:

  | Window Type | Creation Method |
  | -------- | -------- |
  | App-modal subwindow | Call the [createSubWindowWithOptions()](../reference/apis-arkui/arkts-apis-window-Window.md#createsubwindowwithoptions12) API and set **isModal** to **true** and **modalityType** to **APPLICATION_MODALITY** in the subwindow parameters [SubWindowOptions](../reference/apis-arkui/arkts-apis-window-i.md#subwindowoptions11). |
  | Toast subwindow | Call the [showToast()](../reference/apis-arkui/arkts-apis-uicontext-promptaction.md#showtoast) API and set **showMode** to **TOP_MOST**. |
  | Text menu subwindow | Call the [showActionMenu()](../reference/apis-arkui/arkts-apis-uicontext-promptaction.md#showactionmenu) API and set **showInSubWindow** to **true**. |
  | Dialog subwindow | Call [openCustomDialog()](../reference/apis-arkui/arkts-apis-uicontext-promptaction.md#opencustomdialog12) with dialogContent and options parameters, and set **showInSubWindow** to **true**.<br>Call [openCustomDialog()](../reference/apis-arkui/arkts-apis-uicontext-promptaction.md#opencustomdialog12-1) with the options parameter, and set **showInSubWindow** to **true**.<br>Call [openCustomDialogWithController()](../reference/apis-arkui/arkts-apis-uicontext-promptaction.md#opencustomdialogwithcontroller18), and set **showInSubWindow** to **true**. |
  | Modal subwindow | Call the [createSubWindowWithOptions()](../reference/apis-arkui/arkts-apis-window-Window.md#createsubwindowwithoptions12) API and set **isModal** to **true** and **modalityType** to **WINDOW_MODALITY** in the subwindow parameters [SubWindowOptions](../reference/apis-arkui/arkts-apis-window-i.md#subwindowoptions11). |
  | Normal subwindow | The default subwindow created by calling the [createSubWindowWithOptions()](../reference/apis-arkui/arkts-apis-window-Window.md#createsubwindowwithoptions12) API. |

  Windows of different types cannot cross their z-order ranges by tapping or through APIs.

### Z-Order Rules for Parent-Child Windows

- When a parent window is raised, all its child windows are raised along with it; when a child window is raised, its parent window is also raised.

- The z-order of a child window is always higher than that of its parent window.

- A window can be raised by calling the [raiseToAppTop()](../reference/apis-arkui/arkts-apis-window-Window.md#raisetoapptop14) API or by tapping the window.

### Z-Order Rules for TopMost Windows

- In the [freeform window](window-terminology.md#freeform-window) state, an app's main window can call the [setWindowTopmost()](../reference/apis-arkui/arkts-apis-window-Window.md#setwindowtopmost14) API with **true** to place itself above other app windows, achieving an always-on-top display effect that is not obscured. This should be used appropriately to avoid affecting the user experience.

- Using this API requires the ohos.permission.WINDOW_TOPMOST permission.

## Z-Order Control Mechanisms

| Feature/Operation | Control Method | Effective Scope | Applicable Scenario |
| -------- | -------- | -------- | -------- |
| Z-order | System-managed | Effective across apps | Internal rendering order management |
| zLevel | setSubWindowZLevel()/Set when creating a window | Effective only within the same app | z-order management for subwindows |
| Window topmost | setWindowTopmost() | Effective across apps | Persistent windows such as video and navigation |
| Raise on tap | setRaiseByClickEnabled() | Effective across apps | Preventing accidental touches, fixed layouts |

## Z-Order Related Development Scenarios

| Feature | Typical Scenario | Corresponding API |
| -------- | -------- | -------- |
| Set main window to topmost | Used to place a window above other app windows without being obscured, such as in video calls, navigation, and other scenarios. | [setWindowTopmost()](../reference/apis-arkui/arkts-apis-window-Window.md#setwindowtopmost14) |
| Raise a subwindow to the top | Used to raise a subwindow to the topmost position among subwindows of the same type within the current app. This only takes effect within the scope of subwindows that share the same parent window and the same **zLevel** value in the current app.<br>For example, in a video conference with a floating toolbar, the main window displays the video feed, while subwindows include a chat box, a sharing control bar, and so on. When the chat box is tapped, **raiseToAppTop()** can be called to bring it to the top, preventing it from being obscured by other subwindows. | [raiseToAppTop()](../reference/apis-arkui/arkts-apis-window-Window.md#raisetoapptop14) |
| Disable/enable the subwindow raise-on-tap feature | Can be used for tool panels with fixed layouts to prevent z-order confusion caused by accidental user operations. | [setRaiseByClickEnabled()](../reference/apis-arkui/arkts-apis-window-Window.md#setraisebyclickenabled14) |
| Get the topmost window in the current app | Can determine the currently displayed topmost window (which may be the main window or a subwindow), used for scenarios such as logging or state synchronization. | [getLastWindow()](../reference/apis-arkui/arkts-apis-window-f.md#windowgetlastwindow9-1) |

> **NOTE**
>
> - Set **zLevel** appropriately to avoid z-order conflicts.
>
> - Use the TopMost feature with caution to avoid disrupting the system's multi-window experience.
>
> - For critical interfaces that require high-priority display, you can use [raiseToAppTop()](../reference/apis-arkui/arkts-apis-window-Window.md#raisetoapptop14) to ensure visibility. Before using this API, ensure that the window has called a **showWindow()** type API ([showWindow()](../reference/apis-arkui/arkts-apis-window-Window.md#showwindow9-1)/[showWindow(options: ShowWindowOptions)](../reference/apis-arkui/arkts-apis-window-Window.md#showwindow20)) and that the call has completed.
>
> - [setWindowTopmost()](../reference/apis-arkui/arkts-apis-window-Window.md#setwindowtopmost14) takes effect only in the [freeform window](window-terminology.md#freeform-window) state. You can use [isInFreeWindowMode()](../reference/apis-arkui/arkts-apis-window-Window.md#isinfreewindowmode22) to check whether the current window is in freeform window mode, and combine it with the [on('freeWindowModeChange')](../reference/apis-arkui/arkts-apis-window-Window.md#onfreewindowmodechange22) event listener to listen for window mode changes in real time, thereby accurately determining when it is safe to call [setWindowTopmost()](../reference/apis-arkui/arkts-apis-window-Window.md#setwindowtopmost14).