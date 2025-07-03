# OpenHarmony 5.1.0 Release


## Version Description

API version 18 is officially released in OpenHarmony 5.1.0 Release. Compared with the preceding OpenHarmony 5.0.3 Release featuring API version 15, this version introduces several notable new features and enhancements:

The ArkUI framework offers a broader range of component attribute settings, supports more sophisticated and visually appealing animations, and expands the capabilities of components that are called through C APIs. The media capabilities are enhanced with broader encoding and decoding support, refined playback control, and improved media session management. Application startup allows for more detailed configuration options. For distributed data management, the data processing capabilities of the Unified Data Management Framework (UDMF) and the Relational Database (RDB) are further strengthened. The standard web capabilities are further refined.

The following provides a detailed breakdown of the new features and enhancements, presented by the API version:

### Application Framework

- Adds the API for creating an application context based on the specified data encryption level to obtain the corresponding path. ([API Reference](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.1.0-Release/en/application-dev/reference/apis-ability-kit/js-apis-inner-application-context.md#contextcreateareamodecontext18))

- Adds the **processName** property for obtaining the process name of the current process synchronously. ([API Reference](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.1.0-Release/en/application-dev/reference/apis-ability-kit/js-apis-inner-application-context.md#properties))

- Adds support for obtaining the reason why an application is started (**LAUNCH_REASON_MESSAGE**). ([API Reference](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.1.0-Release/en/application-dev/reference/apis-ability-kit/js-apis-app-ability-wantConstant.md#params))

- Adds support for HAR, HSP, and SO files to the startup framework. ([Development Guidelines](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.1.0-Release/en/application-dev/application-models/app-startup.md#supported-scope), [API Reference](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.1.0-Release/en/application-dev/reference/apis-ability-kit/js-apis-app-appstartup-startupManager.md#ohosappappstartupstartupmanager))

- Adds support for specifying the maximum and minimum widths and heights (using **maxWindowWidth**, **maxWindowHeight**, **minWindowWidth**, and **minWindowHeight**) of the main window when starting an ability. ([API Reference](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.1.0-Release/en/application-dev/reference/apis-ability-kit/js-apis-app-ability-startOptions.md#properties))

- Adds support for obtaining the detailed reason why an application exits last time. ([Development Guidelines](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.1.0-Release/en/application-dev/application-models/ability-exit-info-record.md), [API Reference](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.1.0-Release/en/application-dev/reference/apis-ability-kit/js-apis-app-ability-abilityConstant.md#lastexitdetailinfo18))

- Adds support for setting the color mode of UIAbility. ([API Reference](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.1.0-Release/en/application-dev/reference/apis-ability-kit/js-apis-inner-application-uiAbilityContext.md#uiabilitycontextsetcolormode18))

- Adds the **minWindowWidth**, **minWindowHeight**, **maxWindowWidth**, and **maxWindowHeight** properties to **startOptions**, an input parameter of **startAbility**, for specifying the maximum and minimum widths and heights of a new window. ([API Reference](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.1.0-Release/en/application-dev/reference/apis-ability-kit/js-apis-app-ability-startOptions.md#properties))

- Adds support for passing **startOptions** when starting an ability using C APIs. ([API Reference](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.1.0-Release/en/application-dev/reference/apis-ability-kit/start__options_8h.md))

- Adds the C APIs for setting the display mode of the window and dock bar icons when an ability is started. ([API Reference](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.1.0-Release/en/application-dev/reference/apis-ability-kit/_ability_runtime.md#oh_abilityruntime_setstartoptionsstartvisibility))

- Adds the C APIs for obtaining application-level file directories. ([API Reference](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.1.0-Release/en/application-dev/reference/apis-ability-kit/_ability_runtime.md))

### Bundle Manager

Adds the following fields to the **module.json5** file that jointly specify the redirection target: **abilitySrcEntryDelegator**, which indicates the name of the UIAbility to which the current module should be redirected, and **abilityStageSrcEntryDelegator**, which specifies the name of the module (which cannot be the current module name) to which the current module should be redirected. ([Development Guidelines](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.1.0-Release/en/application-dev/quick-start/module-configuration-file.md#tags-in-the-configuration-file))

### ArkUI

- Enhances text and input component capabilities as follows:
  - Adds the **NODE_IMMUTABLE_FONT_WEIGHT** API to text components to enable the font weight to remain unaffected by changes in the system font weight settings. ([API Reference – C APIs](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.1.0-Release/en/application-dev/reference/apis-arkui/_ark_u_i___native_module.md#arkui_nodeattributetype))
  - Adds the APIs for providing sharing services for selected text ([API Reference](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.1.0-Release/en/application-dev/reference/apis-arkui/arkui-ts/ts-text-common.md#properties)) and for enabling line breaks to occur between any two syllabic units ([API Reference](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.1.0-Release/en/application-dev/reference/apis-arkui/arkui-ts/ts-appendix-enums.md#wordbreak11)).
  - Adds support to text components for displaying the context menu on selection in a separate window. ([API Reference](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.1.0-Release/en/application-dev/reference/apis-arkui/js-apis-arkui-UIContext.md#textmenucontroller16))
  - Adds the API to the **RichEditor** component for setting the maximum number of lines. ([API Reference](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.1.0-Release/en/application-dev/reference/apis-arkui/arkui-ts/ts-basic-components-richeditor.md#maxlength18))
  - Adds the API to the **TextInput** component for setting the ellipsis position. ([API Reference](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.1.0-Release/en/application-dev/reference/apis-arkui/arkui-ts/ts-basic-components-textinput.md#ellipsismode18))
  - Adds the API to the **TextInput**, **TextArea**, **Search**, and **RichEditor** components for enabling half leading. ([API Reference – TextInput](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.1.0-Release/en/application-dev/reference/apis-arkui/arkui-ts/ts-basic-components-textinput.md#halfleading18), [API Reference – TextArea](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.1.0-Release/en/application-dev/reference/apis-arkui/arkui-ts/ts-basic-components-textarea.md#halfleading18), [API Reference – Search](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.1.0-Release/en/application-dev/reference/apis-arkui/arkui-ts/ts-basic-components-search.md#halfleading18), [API Reference – RichEditor](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.1.0-Release/en/application-dev/reference/apis-arkui/arkui-ts/ts-basic-components-richeditor.md#richeditortextstyleresult))
  - Adds new content types for autofill in the **TextInput** and **TextArea** components, including license plate number and passport number. ([API Reference  – ArkTS APIs](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.1.0-Release/en/application-dev/reference/apis-arkui/arkui-ts/ts-basic-components-textinput.md#contenttype12), [API Reference – C APIs](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.1.0-Release/en/application-dev/reference/apis-arkui/_ark_u_i___native_module.md#arkui_textinputcontenttype))
  - Adds support to the **RichEditor** component for enabling haptic feedback in the preview menu triggered by a long press. ([API Reference](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.1.0-Release/en/application-dev/reference/apis-arkui/arkui-ts/ts-basic-components-richeditor.md#previewmenuoptions18))
  - Adds support to basic types for clearing the current preview text. ([API Reference](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.1.0-Release/en/application-dev/reference/apis-arkui/arkui-ts/ts-types.md#clearpreviewtext17))

- Adds the following APIs to enhance the general drag and drop capabilities:
  - APIs for defining custom drop animations ([API Reference](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.1.0-Release/en/application-dev/reference/apis-arkui/js-apis-arkui-UIContext.md#notifydragstartrequest18), [API Reference](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.1.0-Release/en/application-dev/reference/apis-arkui/arkui-ts/ts-universal-events-drag-drop.md#executedropanimation18))

  - API for customizing whether to trigger automatic scrolling for dragging to the edge of a scrollable component ([API Reference](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.1.0-Release/en/application-dev/reference/apis-arkui/arkui-ts/ts-universal-attributes-drag-drop.md#draginteractionoptions12))

- Enhances the dialog box capabilities as follows:
  - Adds the **levelOrder** API for setting the display sequence of dialog boxes, which enables control over which dialog box appears on top of others. ([Development Guidelines](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.1.0-Release/en/application-dev/ui/arkts-dialog-levelorder.md), [API Reference](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.1.0-Release/en/application-dev/reference/apis-arkui/js-apis-promptAction.md#showdialogoptions))
  - Adds the APIs for creating and closing custom dialog boxes in custom content. ([API Reference](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.1.0-Release/en/application-dev/reference/apis-arkui/js-apis-arkui-UIContext.md#opencustomdialogwithcontroller18))
  - Adds the **maxWidth** API for setting the maximum width for the **Popup** component. ([API Reference](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.1.0-Release/en/application-dev/reference/apis-arkui/arkui-ts/ohos-arkui-advanced-Popup.md#popupoptions))
  - Adds the **placement** API for setting the display position relative to the target node and the **placementOnTarget** API for setting whether to overlap the target node for sheets in the popup style. ([API Reference](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.1.0-Release/en/application-dev/reference/apis-arkui/arkui-ts/ts-universal-attributes-sheet-transition.md#sheetoptions))
  - Adds the **backgroundBlurStyleOptions** and **backgroundEffect** APIs for customizing the blur effect for menus and dialog boxes. ([API Reference – Menu](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.1.0-Release/en/application-dev/reference/apis-arkui/arkui-ts/ts-universal-attributes-menu.md#contextmenuoptions10), [API Reference – Dialog](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.1.0-Release/en/application-dev/reference/apis-arkui/js-apis-promptAction.md#showdialogoptions))
  - Adds support for two-way binding of variables through the !! syntax for modal transitions and menu items. ([API Reference– Sheet Transition](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.1.0-Release/en/application-dev/reference/apis-arkui/arkui-ts/ts-universal-attributes-sheet-transition.md#bindsheet), [API Reference – Modal Transition](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.1.0-Release/en/application-dev/reference/apis-arkui/arkui-ts/ts-universal-attributes-modal-transition.md#bindcontentcover), [API Reference – MenuItem](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.1.0-Release/en/application-dev/reference/apis-arkui/arkui-ts/ts-basic-components-menuitem.md#selected))
  - Adds the **keyboardAvoidDistance** API for setting the minimum distance between the dialog box and the keyboard after keyboard avoidance is applied. ([API Reference – ArkTS APIs](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.1.0-Release/en/application-dev/reference/apis-arkui/arkui-ts/ts-methods-custom-dialog-box.md#customdialogcontrolleroptions), [API Reference – C APIs](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.1.0-Release/en/application-dev/reference/apis-arkui/_ark_u_i___native_dialog_a_p_i__2.md))
  - Adds the **showInSubWindow** API for setting whether to display the sheet in a subwindow and the **effectEdge** API for setting the edge scrolling effect of the sheet. ([API Reference](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.1.0-Release/en/application-dev/reference/apis-arkui/arkui-ts/ts-universal-attributes-sheet-transition.md#sheetoptions))
  - Adds support for enabling haptic feedback in the menu. ([API Reference](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.1.0-Release/en/application-dev/reference/apis-arkui/arkui-ts/ts-universal-attributes-menu.md#hapticfeedbackmode18))

- Enhances the selection component capabilities as follows:
  - Adds the **SegmentButtonV2** component, which is used to create tab-style, single-select, and multi-select capsule-style buttons. ([API Reference](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.1.0-Release/en/application-dev/reference/apis-arkui/arkui-ts/ohos-arkui-advanced-SegmentButtonV2.md))
  - Adds callbacks triggered when an item enters the divider area for the **TextPicker** and **TimePicker** components. ([API Reference – TextPicker](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.1.0-Release/en/application-dev/reference/apis-arkui/arkui-ts/ts-basic-components-textpicker.md#onenterselectedarea18), [API Reference – TimePicker](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.1.0-Release/en/application-dev/reference/apis-arkui/arkui-ts/ts-basic-components-timepicker.md#onenterselectedarea18))
  - Adds the **start** and **end** properties to the **TimePicker** and **CalendarPicker** components for setting the start time and end time. ([API Reference – TimePicker](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.1.0-Release/en/application-dev/reference/apis-arkui/arkui-ts/ts-basic-components-timepicker.md#timepickeroptions), [API Reference – CalendarPicker](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.1.0-Release/en/application-dev/reference/apis-arkui/arkui-ts/ts-basic-components-calendarpicker.md#calendaroptions))
  - Adds the **enableCascade** API to the **TimePicker** component for setting whether the AM/PM indicator automatically switches based on the hour in 12-hour format. ([API Reference](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.1.0-Release/en/application-dev/reference/apis-arkui/arkui-ts/ts-basic-components-timepicker.md#enablecascade18))

- Enhances the scrollable and swipeable component capabilities as follows:
  - Adds the callbacks triggered when the selected element changes in the **Swiper** or **Tabs** component, returning index of the element that is about to be hidden is returned. ([API Reference – Swiper](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.1.0-Release/en/application-dev/reference/apis-arkui/arkui-ts/ts-container-swiper.md), [API Reference – Tabs](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.1.0-Release/en/application-dev/reference/apis-arkui/arkui-ts/ts-container-tabs.md))
  - Adds the API to the **Swiper** component for setting whether child components stop autoplay when the screen is pressed by fingers, a mouse device, or other input devices. ([API Reference – Swiper](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.1.0-Release/en/application-dev/reference/apis-arkui/arkui-ts/ts-container-swiper.md#onunselected18))
  - Enhances the C APIs of the **Swiper** component for setting whether to display the cached nodes, and the style of the digit-style navigation indicator and navigation arrow. ([API Reference – C APIs](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.1.0-Release/en/application-dev/reference/apis-arkui/_ark_u_i___native_module.md))
  - Adds the C APIs to the **List** component for setting layout styles and scrolling effects (**NODE_LIST_SCROLL_TO_INDEX_IN_GROUP**, **NODE_LIST_LANES**, **NODE_LIST_SCROLL_SNAP_ALIGN**, **NODE_LIST_MAINTAIN_VISIBLE_CONTENT_POSITION**). ([API Reference – C APIs](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.1.0-Release/en/application-dev/reference/apis-arkui/_ark_u_i___native_module.md#arkui_nodeattributetype))

- Adds the C API for configuring the callback for gesture interruption events. ([API Reference](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.1.0-Release/en/application-dev/reference/apis-arkui/_ark_u_i___native_gesture_a_p_i__2.md))

- Adds the C API for obtaining the width, height, and coordinates of the component hit by an event. ([API Reference – C APIs](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.1.0-Release/en/application-dev/reference/apis-arkui/_ark_u_i___event_module.md#functions))

- Adds the APIs for setting the custom focus movement logic for the component. ([API Reference – ArkTS APIs](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.1.0-Release/en/application-dev/reference/apis-arkui/arkui-ts/ts-universal-attributes-focus.md#nextfocus18), [API Reference – C APIs](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.1.0-Release/en/application-dev/reference/apis-arkui/_ark_u_i___native_module.md#arkui_focusmove))

- Adds the API for dynamically obtaining gesture configuration parameters, including the number of consecutive taps required for the gesture to be recognized. ([API Reference](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.1.0-Release/en/application-dev/reference/apis-arkui/arkui-ts/ts-gesture-blocking-enhancement.md#taprecognizer18))

- Adds support for returning gesture event information in the **onActionCancel** callback triggered when a gesture is canceled. ([API Reference – LongPressGesture](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.1.0-Release/en/application-dev/reference/apis-arkui/arkui-ts/ts-basic-gestures-longpressgesture.md#events), [API Reference – PanGesture](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.1.0-Release/en/application-dev/reference/apis-arkui/arkui-ts/ts-basic-gestures-pangesture.md#events), [API Reference – PinchGesture](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.1.0-Release/en/application-dev/reference/apis-arkui/arkui-ts/ts-basic-gestures-pinchgesture.md#events), [API Reference – RotationGesture](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.1.0-Release/en/application-dev/reference/apis-arkui/arkui-ts/ts-basic-gestures-rotationgesture.md#events))

- Adds the following accessibility APIs: API for setting the next focus target for the component during focus traversal ([API Reference](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.1.0-Release/en/application-dev/reference/apis-arkui/arkui-ts/ts-universal-attributes-accessibility.md#accessibilitynextfocusid18)), API for setting the role type of the accessibility component, which affects how the component is announced by screen readers ([API Reference](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.1.0-Release/en/application-dev/reference/apis-arkui/arkui-ts/ts-universal-attributes-accessibility.md#accessibilityrole18)), API for setting whether to enable automatic scrolling for screen readers when the current page has no focusable components ([API Reference](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.1.0-Release/en/application-dev/reference/apis-arkui/arkui-ts/ts-universal-attributes-accessibility.md#accessibilityscrolltriggerable18)).

- Adds support for setting the events occupied by the **EmbeddedComponent** or **UIExtensionComponent** component. ([API Reference](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.1.0-Release/en/application-dev/reference/apis-arkui/js-apis-arkui-uiExtension.md#occupyevents18))

- Adds the APIs for moving the current FrameNode to the specified position of the target FrameNode to implement cross-instance node migration. ([API Reference – ArkTS APIs](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.1.0-Release/en/application-dev/reference/apis-arkui/js-apis-arkui-frameNode.md#moveto18), [API Reference – C APIs](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.1.0-Release/en/application-dev/reference/apis-arkui/_ark_u_i___native_module.md#oh_arkui_nodeutils_moveto))

- Adds the lifecycle callbacks for NodeController: **onAttach**, **onDetach**, **onWillBind**, **onWillUnbind**, **onBind**, and **onUnbind**. ([API Reference](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.1.0-Release/en/application-dev/reference/apis-arkui/js-apis-arkui-nodeController.md))

- Adds the API for taking a snapshot of the provided **ComponentContent** object. ([API Reference](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.1.0-Release/en/application-dev/reference/apis-arkui/js-apis-arkui-UIContext.md#createfromcomponent18))

- Added APIs related to mouse axis events. ([API Reference – ArkTS APIs](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.1.0-Release/en/application-dev/reference/apis-arkui/arkui-ts/ts-universal-events-axis.md), [API Reference – C APIs](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.1.0-Release/en/application-dev/reference/apis-arkui/_ark_u_i___event_module.md#oh_arkui_axisevent_setpropagation))

- Adds the **OnActive** and **OnInActive** lifecycle callbacks to the **NavDestination** component. ([API Reference](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.1.0-Release/en/application-dev/reference/apis-arkui/arkui-ts/ts-basic-components-navdestination.md#onactive17))

- Adds the C APIs for obtaining the width, height, and coordinates of the component hit by an event. ([API Reference](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.1.0-Release/en/application-dev/reference/apis-arkui/_ark_u_i___event_module.md#oh_arkui_uiinputevent_geteventtargetwidth))

- Adds the API to the **UIContext** module for creating a UI instance that does not depend on a window. ([API Reference](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.1.0-Release/en/application-dev/reference/apis-arkui/js-apis-arkui-UIContext.md#createuicontextwithoutwindow17))

- Adds the API for setting the callback parameters for the **onVisibleAreaChange** event to restrict its execution interval. ([API Reference – ArkTS APIs](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.1.0-Release/en/application-dev/reference/apis-arkui/arkui-ts/ts-universal-component-visible-area-change-event.md#onvisibleareaapproximatechange17), [API Reference – C APIs](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.1.0-Release/en/application-dev/reference/apis-arkui/_ark_u_i___native_module.md#oh_arkui_visibleareaeventoptions_create))

- Adds the API to the **ImageAnimator** component for setting whether the component should automatically pause or resume based on its visibility using the system's **onVisibleAreaChange** event. ([API Reference](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.1.0-Release/en/application-dev/reference/apis-arkui/arkui-ts/ts-basic-components-imageanimator.md#monitorinvisiblearea17))

### Window Manager

- Adds a listener for the completion of the soft keyboard display animation. ([API Reference](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.1.0-Release/en/application-dev/reference/apis-arkui/js-apis-window.md#onkeyboarddidshow18))

- Adds the **LocalStorage** parameter to **PiPConfiguration** for creating a page-level UI state storage unit, which can be used to track the main window instance when multiple instances are involved. ([API Reference](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.1.0-Release/en/application-dev/reference/apis-arkui/js-apis-pipWindow.md#pipconfiguration))

- Adds the API for creating a virtual screen. ([API Reference](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.1.0-Release/en/application-dev/reference/apis-arkui/js-apis-display.md#displaycreatevirtualscreen16))


### Graphics

Adds the C APIs, including functions and enums, for offering GPU rendering capabilities for direct drawing to the screen buffer. ([API Reference]((https://gitee.com/openharmony/docs/blob/OpenHarmony-5.1.0-Release/en/application-dev/reference/apis-arkgraphics2d/drawing__path__effect_8h.md))


### Distributed Data Management

- Adds the **rootDir** configuration to RelationalStore, which allows you to open databases in non-database directories. ([API Reference](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.1.0-Release/en/application-dev/reference/apis-arkdata/js-apis-data-relationalStore.md#storeconfig))

- Adds the APIs to RelationalStore for obtaining the column data type based on the specified column index or column name. ([API Reference](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.1.0-Release/en/application-dev/reference/apis-arkdata/js-apis-data-relationalStore.md#getcolumntype18))

- Adds the API to UDMF for converting the provided data into a multi-style data structure, which is useful when the original data uses multiple records to represent different styles of the same data. ([API Reference](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.1.0-Release/en/application-dev/reference/apis-arkdata/js-apis-data-unifiedDataChannel.md#unifieddatachannelconvertrecordstoentries17))


### Media


**Audio**

- Adds support for audio output in Float32 format. ([API Reference](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.1.0-Release/en/application-dev/reference/apis-audio-kit/_o_h_audio.md#oh_audiostream_sampleformat))

- Adds support for spatial audio management. ([Development Guidelines](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.1.0-Release/en/application-dev/media/audio/public-audio-spatialization-management.md), [API Reference](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.1.0-Release/en/application-dev/reference/apis-audio-kit/js-apis-audio.md#getspatializationmanager18))

**Audio/Video Codecs**

- Adds the MPEG-2, MPEG-4, and H.263 support for video decoding. ([Development Guidelines](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.1.0-Release/en/application-dev/media/avcodec/avcodec-support-formats.md))

**Playback control**

- Adds the API for transparently transmitting SEI field data from the media player to an application, which is applicable to HTTP-FLV live streaming. ([API Reference](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.1.0-Release/en/application-dev/reference/apis-media-kit/js-apis-media.md#onseimessagereceived18))

- Adds **showFirstFrameOnPrepare** (whether to show the first frame after **prepare** is called) and **preferredBufferDurationForPlaying** (preferred buffer duration for playback) to the list of AVPlayer playback strategies. ([API Reference](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.1.0-Release/en/application-dev/reference/apis-media-kit/js-apis-media.md#setplaybackstrategy12))

- Adds support for playing pre-downloaded video data. ([API Reference](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.1.0-Release/en/application-dev/reference/apis-media-kit/js-apis-media.md#setmediaresourceloaderdelegate18))

- Adds **thresholdForAutoQuickPlay** to the list of AVPlayer playback strategies. ([API Reference](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.1.0-Release/en/application-dev/reference/apis-media-kit/js-apis-media.md#playbackstrategy12))

- Adds support for creating multiple **SoundPool** instances. ([API Reference](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.1.0-Release/en/application-dev/reference/apis-media-kit/js-apis-media.md#mediacreatesoundpool10))

- Adds **showFirstFrameOnPrepare** (whether to show the first frame after **prepare** is called) to the list of AVPlayer playback strategies. ([API Reference](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.1.0-Release/en/application-dev/reference/apis-media-kit/js-apis-media.md#playbackstrategy12))

- Adds **'setTargetLoopMode'** to the list of commands that can be sent by a cast controller ([API Reference](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.1.0-Release/en/application-dev/reference/apis-avsession-kit/js-apis-avsession.md#avcontrolcommandtype10)) and a listener for the loop mode setting event ([API Reference](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.1.0-Release/en/application-dev/reference/apis-avsession-kit/js-apis-avsession.md#onsettargetloopmode18)).

- Adds the **singleLyricText** property to audio sessions to support the display of lyrics of a single media asset. ([API Reference](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.1.0-Release/en/application-dev/reference/apis-avsession-kit/js-apis-avsession.md#avmetadata10))

**Image**

- Adds the C API for obtaining the editable flag of images. ([API Reference](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.1.0-Release/en/application-dev/reference/apis-image-kit/_image___native_module.md#oh_pixelmapinitializationoptions_geteditable))

**Recording**

- Adds the enum that defines the video fill mode during screen capture. ([API Reference](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.1.0-Release/en/application-dev/reference/apis-media-kit/js-apis-media.md#avscreencapturefillmode18))

- Adds the **enableStableQualityMode18** property to **AVRecorderProfile** for configuring whether to enable stable quality mode for video recording. ([API Reference](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.1.0-Release/en/application-dev/reference/apis-media-kit/js-apis-media.md#avrecorderprofile9))


### Programming Language Runtime

- Adds to TaskPool the support for specifying the task execution concurrency and queuing policy. ([API Reference](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.1.0-Release/en/application-dev/reference/apis-arkts/js-apis-taskpool.md#asyncrunner18))

- Adds to TaskPool the support for canceling a task in the task pool by task ID. ([API Reference](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.1.0-Release/en/application-dev/reference/apis-arkts/js-apis-taskpool.md#taskpoolcancel18))

- Adds the following API to the **collections** module ([API Reference](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.1.0-Release/en/application-dev/reference/apis-arkts/js-apis-arkts-collections.md#arktscollections-arkts-collections)):
  Array: from, isArray, of, copyWithin, lastIndexOf, some, reduceRight, reverse, toString, every, toLocaleString

  TypedArray: toString, toLocaleString, lastIndexOf, reduceRight

- Adds the **Sendable** feature for discarding the least recently used data to make room for new elements when the cache is full. ([API Reference](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.1.0-Release/en/application-dev/reference/apis-arkts/js-apis-arkts-utils.md#sendablelrucachek-v18))

- Adds to Worker the support for specifying the priority of a task during task creation. ([API Reference](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.1.0-Release/en/application-dev/reference/apis-arkts/js-apis-worker.md#threadworkerpriority18))


### Security

Adds support for group-based asset access control, which means you can add multiple applications of the same developer to a group to allow the applications in the same group to access data with each other. ([Development Guidelines](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.1.0-Release/en/application-dev/security/AssetStoreKit/asset-js-group-access-control.md))


### DFX

Adds support for dumping the original heap snapshot of the VM for the calling thread. ([API Reference](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.1.0-Release/en/application-dev/reference/apis-performance-analysis-kit/js-apis-hidebug.md#hidebugdumpjsrawheapdata18))


### Enterprise Customization

- Adds the **mtpClient**, **mtpServer**, and **resetFactory** APIs for enabling or disabling the corresponding features. ([API Reference](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.1.0-Release/en/application-dev/reference/apis-mdm-kit/js-apis-enterprise-restrictions.md#restrictionssetdisallowedpolicy))

- Adds support for installing a user certificate based on the system account. ([API Reference](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.1.0-Release/en/application-dev/reference/apis-mdm-kit/js-apis-enterprise-securityManager.md#securitymanagerinstallusercertificate18))

- Add support for subscribing to system events of account addition, deletion, and switching. ([API Reference](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.1.0-Release/en/application-dev/reference/apis-mdm-kit/js-apis-enterprise-adminManager.md#managedevent))

### Communications

- Adds the API for obtaining the virtual MAC address of the peer Bluetooth device over a client socket from the socket server. ([API Reference](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.1.0-Release/en/application-dev/reference/apis-connectivity-kit/js-apis-bluetooth-socket.md#socketgetdeviceid17))

- Adds the API for obtaining the name of a remote Bluetooth device. ([API Reference](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.1.0-Release/en/application-dev/reference/apis-connectivity-kit/js-apis-bluetooth-connection.md#connectiongetremotedevicename16))

- Adds the API for connecting all profiles, such as A2DP, HFP, and HID, allowed for a remote Bluetooth device. ([API Reference](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.1.0-Release/en/application-dev/reference/apis-connectivity-kit/js-apis-bluetooth-connection.md#connectionconnectallowedprofiles16))

- Adds the API for persisting the virtual MAC address of a remote Bluetooth device. ([API Reference](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.1.0-Release/en/application-dev/reference/apis-connectivity-kit/js-apis-bluetooth-access.md#accessaddpersistentdeviceid16))

- Adds geofence reporting modes that allow for reporting entry into the fence when an advertising packet is detected for the first time and reporting exit from the fence when no advertising packet is detected, with the reports including information from the advertising packets. ([API Reference](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.1.0-Release/en/application-dev/reference/apis-connectivity-kit/js-apis-bluetooth-ble.md#scanreportmode15))

- Adds the APIs for obtaining the RSSI, name, and Bluetooth class of the discovered Bluetooth device. ([API Reference](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.1.0-Release/en/application-dev/reference/apis-connectivity-kit/js-apis-bluetooth-connection.md#discoveryresult18))

- Adds the APIs for reading data from and writing data to the remote device through the socket. It supports returning of I/O errors, if any, when the connection is disconnected. ([API Reference](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.1.0-Release/en/application-dev/reference/apis-connectivity-kit/js-apis-bluetooth-socket.md#socketsppwriteasync18))

### Geolocation Manager

Adds the API for enabling listening for Bluetooth scan information reporting events to help auxiliary positioning. ([API Reference](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.1.0-Release/en/application-dev/reference/apis-location-kit/js-apis-geoLocationManager.md#geolocationmanageronbluetoothscanresultchange16))

### Network Management

Adds the API for obtaining the file descriptor of the **TLSSocket** object. ([API Reference](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.1.0-Release/en/application-dev/reference/apis-network-kit/js-apis-socket.md#getsocketfd16))

### Pasteboard

Adds the APIs for obtaining the number of times that the pasteboard data changes. ([API Reference – ArkTS APIs](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.1.0-Release/en/application-dev/reference/apis-basic-services-kit/js-apis-pasteboard.md#getchangecount18), [API Reference – C APIs](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.1.0-Release/en/application-dev/reference/apis-basic-services-kit/_pasteboard.md#oh_pasteboard_getchangecount))


### Input Method

Adds the callback triggered when the input method framework needs to display the text preview ([API Reference](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.1.0-Release/en/application-dev/reference/apis-ime-kit/js-apis-inputmethod.md#setpreviewtextcallback17)) and the API for subscribing to the event for text preview operations in an input method application ([API Reference](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.1.0-Release/en/application-dev/reference/apis-ime-kit/js-apis-inputmethod.md#onsetpreviewtext17)).

### Web

- Adds the API for obtaining the element information of the area being clicked last time. ([API Reference](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.1.0-Release/en/application-dev/reference/apis-arkweb/js-apis-webview.md#getlasthittest18))

- Adds the API for setting whether the **Web** component can change the font weight according to the system settings. ([API Reference](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.1.0-Release/en/application-dev/reference/apis-arkweb/ts-basic-components-web.md#enablefollowsystemfontweight18))

- Adds the API for setting whether to support an application to connect to the media controller. ([API Reference](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.1.0-Release/en/application-dev/reference/apis-arkweb/ts-basic-components-web.md#enablewebavsession18))

- Adds support for setting **accept** to specify the acceptable file types, which are in compliance with the W3C specifications. ([API Reference](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.1.0-Release/en/application-dev/reference/apis-arkweb/ts-basic-components-web.md#onshowfileselector9))

- Adds the static method for removing all webview cache files in an application. ([API Reference](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.1.0-Release/en/application-dev/reference/apis-arkweb/js-apis-webview.md#removeallcache18))

- Adds support for setting elements for same-layer rendering with a fixed width and height. ([API Reference](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.1.0-Release/en/application-dev/reference/apis-arkweb/ts-basic-components-web.md#nativeembedoptions16))

### Multimodal Input

Adds the API for subscribing to key press events. If the current application is in the foreground focus window, a callback is triggered when the specified key is pressed. ([API Reference](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.1.0-Release/en/application-dev/reference/apis-input-kit/js-apis-inputconsumer.md#inputconsumeronkeypressed16e))

### Upload and Download

- Adds support for the application cache download capability, which allows applications to cache files to the application memory or sandbox directory. ([API Reference](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.1.0-Release/en/application-dev/reference/apis-basic-services-kit/js-apis-request-cacheDownload.md))

- Adds the APIs for setting the maximum number of bytes that can be transmitted by a task per second ([API Reference](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.1.0-Release/en/application-dev/reference/apis-basic-services-kit/js-apis-request.md#setmaxspeed18)) and for setting the content type of the file to be uploaded in the form ([API Reference](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.1.0-Release/en/application-dev/reference/apis-basic-services-kit/js-apis-request.md#filespec10)).


### Resource Scheduler

- Adds the **backgroundProcessManager** module, which provides APIs to suppress and unsuppress child processes to prevent child processes from consuming excessive system resources and causing system stuttering. ([API Reference](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.1.0-Release/en/application-dev/reference/apis-backgroundtasks-kit/js-apis-backgroundProcessManager.md))

- Adds resource ID properties for specifying the reminder title and content, facilitating globalization. ([API Reference](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.1.0-Release/en/application-dev/reference/apis-backgroundtasks-kit/js-apis-reminderAgentManager.md#reminderrequest))


### Globalization

- Adds the APIs for obtaining the preferred temperature unit and start day of a week for a user. ([API Reference](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.1.0-Release/en/application-dev/reference/apis-localization-kit/js-apis-i18n.md#gettemperaturetype18))

- Adds the APIs for date/time formatting and number formatting. ([API Reference](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.1.0-Release/en/application-dev/reference/apis-localization-kit/js-apis-i18n.md#i18ngetsimpledatetimeformatbypattern18))

- Adds the API for formatting a number to a rich text object. ([API Reference](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.1.0-Release/en/application-dev/reference/apis-localization-kit/js-apis-i18n.md#stylednumberformat18))

- Adds the API for file path mirroring. ([API Reference](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.1.0-Release/en/application-dev/reference/apis-localization-kit/js-apis-i18n.md#getunicodewrappedfilepath18))


### Test Framework

- Adds the APIs for searching for matching components by ID and type in fuzzy matching or regular expression matching mode. ([API Reference – id](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.1.0-Release/en/application-dev/reference/apis-test-kit/js-apis-uitest.md#id18), [API Reference – type](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.1.0-Release/en/application-dev/reference/apis-test-kit/js-apis-uitest.md#type18))

- Adds the APIs for obtaining the component hint text ([API Reference](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.1.0-Release/en/application-dev/reference/apis-test-kit/js-apis-uitest.md#gethint18)) and searching for components by hint text ([API Reference](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.1.0-Release/en/application-dev/reference/apis-test-kit/js-apis-uitest.md#hint18)).

- Adds the APIs for scrolling on a component to search for the target component in the horizontal or vertical direction, which is available for swipeable components. ([API Reference](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.1.0-Release/en/application-dev/reference/apis-test-kit/js-apis-uitest.md#scrollsearch18))


## Mapping Relationship

**Table 1** Version mapping of software and tools

| Software/Tool| Version| Remarks| 
| -------- | -------- | -------- |
| OpenHarmony | 5.1.0 Release | NA | 
| Public SDK | Ohos_sdk_public 5.1.0.107 (API Version 18 Release) | This toolkit is intended for application developers and does not contain system APIs that require system permissions. It is provided as standard in DevEco Studio.| 
| (Optional) HUAWEI DevEco Studio| 5.1.0 Release | Recommended for developing OpenHarmony applications.<br>*To be released*| 
| (Optional) HUAWEI DevEco Device Tool| 4.0 Release | Recommended for developing OpenHarmony smart devices.| 


## Source Code Acquisition


### Prerequisites

1. Register your account with Gitee.

2. Register an SSH public key for access to Gitee.

3. Install the [git client](https://git-scm.com/book/en/v2/Getting-Started-Installing-Git) and [git-lfs](https://gitee.com/vcs-all-in-one/git-lfs?_from=gitee_search#downloading), and configure user information.
   ```
   git config --global user.name "yourname"
   git config --global user.email "your-email-address"
   git config --global credential.helper store
   ```

4. Install the **repo** tool.
   ```
   curl -s https://gitee.com/oschina/repo/raw/fork_flow/repo-py3 > /usr/local/bin/repo  # If you do not have the permission, download the tool to another directory and add that directory to environment variables. chmod a+x /usr/local/bin/repo
   pip3 install -i https://repo.huaweicloud.com/repository/pypi/simple requests
   ```


### Acquiring Source Code Using the repo Tool

**Method 1: Using SSH (Recommended)**

This method requires an SSH public key for access to Gitee.

- Obtain the source code from the version branch. You can obtain the latest source code of the specified version branch, which includes all changes up to the time you run the commands.
   ```
   repo init -u git@gitee.com:openharmony/manifest.git -b OpenHarmony-5.1.0-Release --no-repo-verify
   repo sync -c
   repo forall -c 'git lfs pull'
   ```
   
- Obtain the source code from the specified version tag, which is the same as that released with the version.
   ```
   repo init -u git@gitee.com:openharmony/manifest.git -b refs/tags/OpenHarmony-v5.1.0-Release --no-repo-verify
   repo sync -c
   repo forall -c 'git lfs pull'
   ```

**Method 2: Using HTTPS**

 

- Obtain the source code from the version branch. You can obtain the latest source code of the specified version branch, which includes all changes up to the time you run the commands.
   ```
   repo init -u https://gitee.com/openharmony/manifest -b OpenHarmony-5.1.0-Release --no-repo-verify
   repo sync -c
   repo forall -c 'git lfs pull'
   ```
   
- Obtain the source code from the specified version tag, which is the same as that released with the version.
   ```
   repo init -u https://gitee.com/openharmony/manifest -b refs/tags/OpenHarmony-v5.1.0-Release --no-repo-verify
   repo sync -c
   repo forall -c 'git lfs pull'
   ```


### Acquiring Source Code from Mirrors


**Table 2** Mirrors for acquiring source code

| Source Code                               | Version| Mirror                                                | SHA-256 Checksum                                            | Software Package Size|
| --------------------------------------- | ------------ | ------------------------------------------------------------ | ------------------------------------------------------------ | -------- |
| Full code base (for mini, small, and standard systems)       | 5.1.0 Release    | [Download](https://repo.huaweicloud.com/openharmony/os/5.1.0-Release/code-v5.1.0-Release.tar.gz) | [Download](https://repo.huaweicloud.com/openharmony/os/5.1.0-Release/code-v5.1.0-Release.tar.gz.sha256) | 49.1 GB |
| Hi3861 solution (binary)       | 5.1.0 Release    | [Download](https://repo.huaweicloud.com/openharmony/os/5.1.0-Release/hispark_pegasus.tar.gz) | [Download](https://repo.huaweicloud.com/openharmony/os/5.1.0-Release/hispark_pegasus.tar.gz.sha256) | 28.4 MB |
| Hi3516 solution-LiteOS (binary)| 5.1.0 Release    | [Download](https://repo.huaweicloud.com/openharmony/os/5.1.0-Release/hispark_taurus_LiteOS.tar.gz) | [Download](https://repo.huaweicloud.com/openharmony/os/5.1.0-Release/hispark_taurus_LiteOS.tar.gz.sha256) | 350.0 MB |
| Hi3516 solution-Linux (binary) | 5.1.0 Release    | [Download](https://repo.huaweicloud.com/openharmony/os/5.1.0-Release/hispark_taurus_Linux.tar.gz) | [Download](https://repo.huaweicloud.com/openharmony/os/5.1.0-Release/hispark_taurus_Linux.tar.gz.sha256) | 223.6 MB |
| RK3568 standard system solution (binary)       | 5.1.0 Release    | [Download](https://repo.huaweicloud.com/openharmony/os/5.1.0-Release/dayu200_standard_arm32.tar.gz) | [Download](https://repo.huaweicloud.com/openharmony/os/5.1.0-Release/dayu200_standard_arm32.tar.gz.sha256) | 	9.7 GB |
| Public SDK package for the standard system (macOS)            | 5.1.0.107 | [Download](https://repo.huaweicloud.com/openharmony/os/5.1.0-Release/ohos-sdk-mac-public.tar.gz) | [Download](https://repo.huaweicloud.com/openharmony/os/5.1.0-Release/ohos-sdk-mac-public.tar.gz.sha256) | 1.3 GB |
| Public SDK package for the standard system (macOS-M1)            | 5.1.0.107  | [Download](https://repo.huaweicloud.com/openharmony/os/5.1.0-Release/L2-SDK-MAC-M1-PUBLIC.tar.gz) | [Download](https://repo.huaweicloud.com/openharmony/os/5.1.0-Release/L2-SDK-MAC-M1-PUBLIC.tar.gz.sha256) | 1.2 GB |
| Public SDK package for the standard system (Windows/Linux)  | 5.1.0.107   | [Download](https://repo.huaweicloud.com/openharmony/os/5.1.0-Release/ohos-sdk-windows_linux-public.tar.gz) | [Download](https://repo.huaweicloud.com/openharmony/os/5.1.0-Release/ohos-sdk-windows_linux-public.tar.gz.sha256) | 3.2 GB |


## Resolved Issues

**Table 3** Resolved issues

| Issue No.| Description| 
| ------- | ------- |
| IBTXFK | It may take more than 1000 ms to delete multiple images from Gallery.|
| IBTCJQ | The frame rate for zooming in or out of an FWX image is less than 60 fps.|
| IBINUK | There is a probability that system freezing occurs in **libcamera_framework.z.so** due to **LIFECYCLE_TIMEOUT** in the **com.ohos.camera** process.|

## Known Issues

**Table 4** Known issues

| ISSUE | Description| Impact| To Be Resolved By| 
| -------- | -------- | -------- | -------- |
| IBTCKR | It may take more than 160 ms from when the SystemUI status bar is pulled down to when the content rendering is complete.| User experience is affected.| 2025-05-30|
| IBBZPS | There is a low probability that a C++ crash occurs in the **OS_IPC_0_1067** thread of the **com.ohos.systemui** process, and the crash stack is **ld-musl-arm.so.1(__libc_free+172)**.| The system malfunctions, and users may not notice the exception.| 2025-05-30| 
| IBE36X<br>IBO3MF | There is a low probability of system freezing in **render_service** due to **SERVICE_BLOCK**.| A black screen is displayed when the home screen does not respond. After the screen recovers, the home screen is displayed.| 2025-05-30|
| IC313T | The animation frame rate of scrolling the thumbnail list in Gallery does not meet the baseline requirements.| User experience is affected.  | 2025-05-10| 
| IC32I0 | The animation frame rates of scrolling on the Weibo home page and zooming on the Tmall page in the browser do not meet the baseline requirements.| User experience is affected.| 2025-05-30| 
| IC32SL | The time taken to complete the first browser startup does not meet the baseline requirements.| User experience is affected.| 2025-06-23| 
| IBUCOT | The measured resident memory of the **com.ohos.settingsdata** process is 16 MB, far exceeding the baseline requirements. | The memory usage does not meet the expectation, but does not affect actual use.| 2025-05-30| 
| IC4UFM | The key response delay of the call dialer does not meet the baseline requirements. | User experience is affected.| 2025-05-16| 
| IC04TG | A C++ crash may occur in **libarkweb_engine.so** of the **com.ohos.note** thread of the **com.ohos.note** process. | The Notepad application malfunctions and can be restored by restarting.| 2025-05-08| 
| IBZYWM | A C++ crash may occur in **libmali-bifrost-g52-g7p0-ohos.so** of the **com.ohos.CompositorGpuTh** thread of the **com.ohos.note** process. | The Notepad application malfunctions and can be restored by restarting.| 2025-05-08| 
| IC22OQ | There is a low probability that a C++ crash occurs in **libskia_canvaskit.z.so** of the **RSRenderThread** thread of the **com.ohos.note** process. | The Notepad application malfunctions and can be restored by restarting.| 2025-05-15| 
| IC4ZPS | During the XTS test, the **ActslocationErrorCodeApiTest** suite fails because the location service of the RK3568 development board does not support geofencing. | This issue has been solved in the master branch, and it can be handled by adding configuration items.<br>For details about the configuration, see [rk3568/config.json](https://gitee.com/openharmony/vendor_hihope/pulls/1505).| 2025-04-30| 
| IC57IO | Tapping the flight mode icon in Control Panel (accessed by swiping down from the upper right corner on the home screen) does not work. | This issue has been solved in the master branch, and it can be avoided by manually modifying the code.<br>For details about how to modify the code, see [data_provider_config.cpp configuration change](https://gitee.com/openharmony/distributeddatamgr_datamgr_service/pulls/2967).| 2025-04-30| 


<!--no_check-->
