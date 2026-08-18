# Window Focus

<!--Kit: ArkUI-->
<!--Subsystem: Window-->
<!--Owner: @fei_1007-->
<!--Designer: @gcw_sPCsris4-->
<!--Tester: @qinliwen0417-->
<!--Adviser: @ge-yafang-->
<!-- md-trans-meta sourceCommit=0d88cc2609499932569930500f1a6723fd824448 translatedAt=2026-08-11T10:11:42.071Z pushedAt=2026-08-11T11:30:25.595Z -->

## When to Use

**Window Focus** refers to the state of a window within a screen group that is currently capable of receiving keyboard events. The system uses the focus mechanism to ensure that user input is correctly routed to the target UI component.

Within a screen group, there is one and only one window in the focus state, which is called the **Focus Window**. The focus window can not only respond to keyboard input but also enjoy higher priority in resource scheduling, such as receiving system preference in rendering and task execution. The system can only bring up the input method for text entry after the window successfully gains focus.

## Basic Concepts and Mechanism Introduction

### Screen Group

A screen group is a set of logically associated display areas in the system, with each screen group independently maintaining its window stack and focus state. **Each screen group has one and only one focus window**, and the focus states of different screen groups do not affect each other.

### Window Focus State

**Window focus state** indicates whether the current window can receive user input events (such as click and key press).

- The main states are as follows:

  - **WINDOW_ACTIVE**: The window has gained focus and can respond to user operations.

  - **WINDOW_INACTIVE**: The window has lost focus and cannot receive input.

- Typical scenario: The window automatically gains focus after the app starts; the original window loses focus when switching to another app.

- You can listen for changes in window focus state through the [on('windowEvent')](../reference/apis-arkui/arkts-apis-window-Window.md#onwindowevent10) API.

### Window Highlight State Management

**Window Highlight State** indicates whether the current window is in a visual highlight state. Visual highlight is a UI feedback mechanism that communicates to the user that this window is currently active, interactive, or being emphasized by the system by changing the window's appearance (such as title bar color, border style, transparency, and shadow).

- Window highlight state supports app windows (including main windows and subwindows), but does not support system windows.

- A window being in the highlight state does not mean it has gained focus; however, a focus window is always in the highlight state.

- There are two highlight modes: exclusive highlight and non-exclusive highlight.

  - Exclusive highlight mode: Only one window is highlighted, and other windows of the app automatically lose highlighting.

  - Non-exclusive highlight mode: Multiple windows within the app (such as parent and child windows) are highlighted simultaneously.

- Typical scenario for exclusive highlight: In a multi-subwindow app, only the title bar of the currently operated subwindow is highlighted.

- Typical scenario for non-exclusive highlight: In a professional design tool, the user operates the main view and the parameter settings panel simultaneously, and the system allows both windows to be highlighted at the same time to indicate that they are both in an active state.

- You can listen for window highlight state changes through the [on('windowHighlightChange')](../reference/apis-arkui/arkts-apis-window-Window.md#onwindowhighlightchange15) API.

## Focus-Related Development Scenarios

| Feature | Typical Scenario | Corresponding API |
| -------- | -------- | -------- |
| Listening for window focus changes | Listen for window focus changes to control background behavior when the window loses focus, such as pausing animations, releasing resources. | [on('windowEvent')](../reference/apis-arkui/arkts-apis-window-Window.md#onwindowevent10) |
| Listening for window highlight state changes | Listen for window highlight state changes to dynamically adjust UI styles, such as title bar color and borders. | [on('windowHighlightChange')](../reference/apis-arkui/arkts-apis-window-Window.md#onwindowhighlightchange15) |
| Setting whether the window can gain focus | Control whether a window participates in focus competition. For example, a banner message notification is set to not gain focus, so as not to interrupt the user's input method input. | [setWindowFocusable()](../reference/apis-arkui/arkts-apis-window-Window.md#setwindowfocusable9) |
| Transferring window focus within the same app | Perform focus switching between multiple windows within an app to ensure a smooth focus navigation experience. For example, switching editing windows on a multi-window UI. | [shiftAppWindowFocus()](../reference/apis-arkui/arkts-apis-window-f.md#windowshiftappwindowfocus11) |
| Determining whether the window has gained focus | Determine the window's focus state, which can be used to prevent inactive windows from performing sensitive operations. | [isFocused()](../reference/apis-arkui/arkts-apis-window-Window.md#isfocused12) |
| Setting whether the window is exclusively highlighted | When setting the window to exclusive highlight, it can be used to focus window operations and enhance user attention.<br/>When setting the window to non-exclusive highlight, it can be used for multi-tab design, supporting multiple windows to remain highlighted simultaneously. | [setExclusivelyHighlighted()](../reference/apis-arkui/arkts-apis-window-Window.md#setexclusivelyhighlighted15) |
| Querying whether the window is in the highlight state | Determine whether the current window is visually highlighted, which can be used for scenarios such as UI state synchronization. | [isWindowHighlighted()](../reference/apis-arkui/arkts-apis-window-Window.md#iswindowhighlighted18) |
| Showing the current window | Can be used to display the main window, child windows, global floating windows, and system windows.<br/>If `focusOnShow: false` is passed in, the window cannot gain focus when displayed. | [showWindow(options: ShowWindowOptions)](../reference/apis-arkui/arkts-apis-window-Window.md#showwindow20) |

> **NOTE**
>
> - For listener APIs: Use the corresponding **off()** API to remove the relevant listener when the page is destroyed to avoid memory leaks.
>
> - Page loading takes precedence over display: When calling APIs such as **showWindow()** to display a window, ensure that the page has been loaded using **loadContent()** or **setUIContent**.
>
> - Use the exclusive window highlight mode appropriately: Avoid abusing [setExclusivelyHighlighted()](../reference/apis-arkui/arkts-apis-window-Window.md#setexclusivelyhighlighted15), which may lead to a fragmented user experience.
>
> - Combining state query and listening APIs: When entering a page for the first time, use **isWindowHighlighted()**/**isFocused()** to obtain the initial state, and then listen for subsequent changes through the corresponding **on('windowHighlightChange')**/**on('windowEvent')** APIs to implement relevant adaptations and operations.