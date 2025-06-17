# OpenHarmony 5.0.3 Release


## Version Description

OpenHarmony 5.0.3 Release continuously improves the capabilities of the standard system, rolling out API 15 via quick iteration. Compared with 5.0.2 Release, OpenHarmony 5.0.3 Release has the following new or enhanced features:

ArkUI provides more advanced attribute settings of components and exquisite animations. For 2-in-1 devices, the window management capability supports more types of device screens or windows. The Unified Data Management Framework (UDMF) of distributed data management is improved with a new smart data platform to provide data intelligence on the device. More external devices, such as game controllers, are also supported.

[OpenHarmony 5.0.1(API 13)](./OpenHarmony-v5.0.1-release.md) and [OpenHarmony 5.0.2(API 14)](./OpenHarmony-v5.0.2-release.md) are fast iteration versions. For details, refer to the corresponding version descriptions.

A more detailed description of the enhancements is as follows:


### Application framework

- Definitions and C APIs of the component startup parameter **Want** are added. ([API Reference](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.3-Release/en/application-dev/reference/apis-ability-kit/_ability_base.md))

- The application context can be created based on the specified physical screen ID so that other screen information can be obtained and used. ([API Reference](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.3-Release/en/application-dev/reference/apis-ability-kit/js-apis-inner-application-context.md#contextcreatedisplaycontext15))

- The UIAbility can be started through the C API. ([API Reference](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.3-Release/en/application-dev/reference/apis-ability-kit/_ability_runtime.md#oh_abilityruntime_startselfuiability))

- Callbacks for pre-closing applications are added, which can be used to ask users whether to execute or cancel operations immediately. ([API Reference of UIAbility](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.3-Release/en/application-dev/reference/apis-ability-kit/js-apis-app-ability-uiAbility.md#uiabilityonpreparetoterminateasync15), [API Reference of AbilityStage](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.3-Release/en/application-dev/reference/apis-ability-kit/js-apis-app-ability-abilityStage.md#abilitystageonprepareterminationasync15))


### ArkUI

- The route navigation capability is enhanced as follows:  
  - The **Navigation** component supports the setting of whether to enable the animation during switching between single and double column modes. ([API Reference](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.3-Release/en/application-dev/reference/apis-arkui/arkui-ts/ts-basic-components-navigation.md#enablemodechangeanimation15))
  - The **NavDestination** component supports a callback during page returning for processing the return parameters of the **pop** API ([API Reference](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.3-Release/en/application-dev/reference/apis-arkui/arkui-ts/ts-basic-components-navdestination.md#onresult15)), and the setting of whether to hide the back button in the title bar ([API Reference](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.3-Release/en/application-dev/reference/apis-arkui/arkui-ts/ts-basic-components-navdestination.md#hidebackbutton15)).
  - The **NavDestination** component also supports the custom transition animation for a single page ([API Reference](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.3-Release/en/application-dev/reference/apis-arkui/arkui-ts/ts-basic-components-navdestination.md#customtransition15)) and the system transition animation type enumeration ([API Reference](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.3-Release/en/application-dev/reference/apis-arkui/arkui-ts/ts-basic-components-navdestination.md#navigationsystemtransitiontype14)).

- The text and input components are enhanced as follows:  
  - The **TextInput**, **TextArea**, and **Search** components support setting whether to prevent back button operations (**onBackPressed**). ([API Reference of TextInput](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.3-Release/en/application-dev/reference/apis-arkui/arkui-ts/ts-basic-components-textinput.md#stopbackpress15), [API Reference of TextArea](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.3-Release/en/application-dev/reference/apis-arkui/arkui-ts/ts-basic-components-textarea.md#stopbackpress15), [API Reference of Search](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.3-Release/en/application-dev/reference/apis-arkui/arkui-ts/ts-basic-components-search.md#stopbackpress15))
  - The **TextInput**, **TextArea**, and **Search** components support triggering a callback when the text content is about to change. ([API Reference of TextInput](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.3-Release/en/application-dev/reference/apis-arkui/arkui-ts/ts-basic-components-textinput.md#onwillchange15), [API Reference of TextArea](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.3-Release/en/application-dev/reference/apis-arkui/arkui-ts/ts-basic-components-textarea.md#onwillchange15), [API Reference of Search](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.3-Release/en/application-dev/reference/apis-arkui/arkui-ts/ts-basic-components-search.md#onwillchange15))
  - Styled strings allow you to set images of the **ResourceStr** type ([API Reference](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.3-Release/en/application-dev/reference/apis-arkui/arkui-ts/ts-universal-styled-string.md#resourceimageattachmentoptions15)) and obtain the image color filter ([API Reference of RichEditor](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.3-Release/en/application-dev/reference/apis-arkui/arkui-ts/ts-universal-styled-string.md#imageattachment)).
  - The **TextInput**, **TextArea**, **Search**, and **RichEditor** components support the setting of the keyboard appearance. ([API Reference of TextInput](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.3-Release/en/application-dev/reference/apis-arkui/arkui-ts/ts-basic-components-textinput.md#keyboardappearance15), [API Reference of TextArea](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.3-Release/en/application-dev/reference/apis-arkui/arkui-ts/ts-basic-components-textarea.md#keyboardappearance15), [API Reference of Search](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.3-Release/en/application-dev/reference/apis-arkui/arkui-ts/ts-basic-components-search.md#keyboardappearance15), [API Reference of RichEditor](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.3-Release/en/application-dev/reference/apis-arkui/arkui-ts/ts-basic-components-richeditor.md#keyboardappearance15))
  - Components support the capabilities of inserting text at a specified position and deleting text within a specified range in the editable content. ([API Reference](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.3-Release/en/application-dev/reference/apis-arkui/arkui-ts/ts-types.md#addtext15))

- The **Image** and **Video** components are enhanced as follows:  
  - The **Image** component allows you to reset the filling color of images by passing the [ColorContent](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.3-Release/en/application-dev/reference/apis-arkui/arkui-ts/ts-basic-components-image.md#colorcontent15) type, which takes effect only for SVG images. ([API Reference](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.3-Release/en/application-dev/reference/apis-arkui/arkui-ts/ts-basic-components-image.md#fillcolor15))
  - The **Image** component supports automatic conversion based on the image matrix. For example, in scenarios similar to the gallery, images can be automatically converted to achieve the optimal display of grid thumbnails. ([API Reference](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.3-Release/en/application-dev/reference/apis-arkui/arkui-ts/ts-basic-components-image.md#imagematrix15))
  - The **Video** component supports the setting of whether to respond to keyboard shortcuts. ([API Reference](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.3-Release/en/application-dev/reference/apis-arkui/arkui-ts/ts-media-components-video.md#enableshortcutkey15))

- The popup capability is enhanced as follows:  
  - The **Popup** component supports the setting of attributes for popup page display and related effects, such as **levelMode**, **levelUniqueId**, and **immersiveMode**. ([API Reference of PromptAction](https://gitee.com/openharmony/docs/blob/master/en/application-dev/reference/apis-arkui/js-apis-arkui-UIContext.md#promptaction), [API Reference of Custom Dialog Box](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.3-Release/en/application-dev/reference/apis-arkui/arkui-ts/ts-methods-custom-dialog-box.md#customdialogcontrolleroptions), [API Reference of showAlertDialog](https://gitee.com/openharmony/docs/blob/master/en/application-dev/reference/apis-arkui/js-apis-arkui-UIContext.md#showalertdialog), [API Reference of showActionSheet](https://gitee.com/openharmony/docs/blob/master/en/application-dev/reference/apis-arkui/js-apis-arkui-UIContext.md#showactionsheet))
  - The **bindSheet** attribute supports the **radius** attribute for setting the corner radius of the sheet, and the **detentSelection** attribute for non-gesture switching. ([API Reference](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.3-Release/en/application-dev/reference/apis-arkui/arkui-ts/ts-universal-attributes-sheet-transition.md#sheetoptions))
  - The **Popup** component supports the **keyboardAvoidMode** attribute for setting whether popups avoid the soft keyboard. ([API Reference](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.3-Release/en/application-dev/reference/apis-arkui/arkui-ts/ts-universal-attributes-popup.md#popupoptions-class-description))
  - The **Popup** component allows you to set the distance to avoid the keyboard. In ArkTS APIs, this feature is achieved through the **keyboardAvoidDistance** attribute. ([C API Reference](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.3-Release/en/application-dev/reference/apis-arkui/_ark_u_i___native_dialog_a_p_i__2.md#setkeyboardavoiddistance), [ArkTS API Reference of Custom Dialogs](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.3-Release/en/application-dev/reference/apis-arkui/arkui-ts/ts-methods-custom-dialog-box.md#customdialogcontrolleroptions), [ArkTS API Reference of Base Dialog](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.3-Release/en/application-dev/reference/apis-arkui/js-apis-promptAction.md#basedialogoptions11))

- The **Swiper** and **Tabs** components are enhanced as follows:  
  - The **Swiper** and **Tabs** components support jumps with animations, ([C API Reference of the Swiper Component](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.3-Release/en/application-dev/reference/apis-arkui/_ark_u_i___native_module.md#arkui_swiperanimationmode), [ArkTS API Reference of the Swiper Component](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.3-Release/en/application-dev/reference/apis-arkui/arkui-ts/ts-container-swiper.md#swiperanimationmode15), and [ArkTS API Reference of the Tabs Component](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.3-Release/en/application-dev/reference/apis-arkui/arkui-ts/ts-container-tabs.md#animationmode12))
     and the setting of the page flipping mode using the mouse wheel. ([API Reference of the Tabs Component](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.3-Release/en/application-dev/reference/apis-arkui/arkui-ts/ts-container-tabs.md#pageflipmode15), [API Reference of the Swiper Component](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.3-Release/en/application-dev/reference/apis-arkui/arkui-ts/ts-container-swiper.md#pageflipmode15))
  - The **Swiper** component supports the event for intercepting swipe behavior, which can be used to determine whether the swipe behavior is allowed. In C APIs, this feature is achieved through the **NODE_SWIPER_EVENT_ON_CONTENT_WILL_SCROLL** attribute. ([C API Reference](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.3-Release/en/application-dev/reference/apis-arkui/_ark_u_i___native_module.md#arkui_nodeeventtype), [ArkTS API Reference](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.3-Release/en/application-dev/reference/apis-arkui/arkui-ts/ts-container-swiper.md#oncontentwillscroll15))
  - The **Tabs** component supports new parameters for setting the universal attributes for the tab bar. ([API Reference](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.3-Release/en/application-dev/reference/apis-arkui/arkui-ts/ts-container-tabs.md#tabsoptions15))

- The capabilities of the **UIContext** object are enhanced as follows:  
  - Parameters of **OverlayManager** are added for setting whether to render the root overlay node. ([API Reference](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.3-Release/en/application-dev/reference/apis-arkui/js-apis-arkui-UIContext.md#setoverlaymanageroptions15))
  - The screenshot of a loaded component can be obtained based on **uniqueId**. ([API Reference](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.3-Release/en/application-dev/reference/apis-arkui/js-apis-arkui-UIContext.md#getwithuniqueid15)).
  - The layout information of the atomic service menu bar relative to the window can be obtained. ([API Reference](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.3-Release/en/application-dev/reference/apis-arkui/js-apis-arkui-UIContext.md#getbarrect15))
  - The drag data of the progress bar can be obtained. ([C API Reference](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.3-Release/en/application-dev/reference/apis-arkui/_ark_u_i___native_module.md#oh_arkui_dragevent_startdataloading), [ArkTS API Reference](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.3-Release/en/application-dev/reference/apis-arkui/js-apis-arkui-UIContext.md#canceldataloading15))

- The common capabilities of C APIs are enhanced as follows:  
  - C APIs are added to support callback methods of component layout completion and component drawing completion. ([API Reference of Component Layout Completion Callback](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.3-Release/en/application-dev/reference/apis-arkui/_ark_u_i___native_module.md#oh_arkui_registerlayoutcallbackonnodehandle), [API Reference of Component Drawing Completion Callback](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.3-Release/en/application-dev/reference/apis-arkui/_ark_u_i___native_module.md#oh_arkui_registerdrawcallbackonnodehandle))
  - The property style **NODE_IMMUTABLE_FONT_WEIGHT** of C APIs is added, which can be used to set that the font weight is not affected by any changes in the system font weight settings. ([API Reference](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.3-Release/en/application-dev/reference/apis-arkui/_ark_u_i___native_module.md#arkui_nodeattributetype))
  - The **NODE_BACKDROP_BLUR** property is added to the **Node** property of C APIs. ([API Reference](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.3-Release/en/application-dev/reference/apis-arkui/_ark_u_i___native_module.md#arkui_nodeattributetype))
  - A C API is added for focus control and focus event processing. ([API Reference](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.3-Release/en/application-dev/reference/apis-arkui/native__interface__focus_8h.md))
  - A C API is added for forwarding clone events. ([API Reference](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.3-Release/en/application-dev/reference/apis-arkui/_ark_u_i___event_module.md#oh_arkui_pointerevent_postclonedevent))
  - A C API is added to universal events for obtaining the ID of the tap pointer that triggers the current tap event. ([API Reference](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.3-Release/en/application-dev/reference/apis-arkui/_ark_u_i___event_module.md#oh_arkui_pointerevent_getchangedpointerid))
  - C APIs are added for obtaining component snapshots. ([API Reference](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.3-Release/en/application-dev/reference/apis-arkui/_ark_u_i___native_module.md#oh_arkui_getnodesnapshot))
  - The **NODE_CHECKBOX_GROUP** related capabilities are added.  ([API Reference](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.3-Release/en/application-dev/reference/apis-arkui/_ark_u_i___native_module.md))

- Whether the current tap event is from the left or right hand can be obtained, which involves the following data objects:
  - The **hand** property of the **FingerInfo** object. ([API Reference](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.3-Release/en/application-dev/reference/apis-arkui/arkui-ts/ts-gesture-settings.md#fingerinfo8))
  - The **hand** property of the **TouchObject** object. ([API Reference](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.0-Release/en/application-dev/reference/apis-arkui/arkui-ts/ts-universal-events-touch.md#touchobject))
  - The **hand** property of the **ClickEvent** object. ([API Reference](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.3-Release/en/application-dev/reference/apis-arkui/arkui-ts/ts-universal-events-click.md#clickevent))

- Gesture recognizers support finger count limits.
  - Related C APIs are added to NDK. ([API Reference](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.3-Release/en/application-dev/reference/apis-arkui/_ark_u_i___native_module.md#oh_arkui_setgesturerecognizerlimitfingercount))
  - Gesture APIs support the **isFingerCountLimited** property, which is used to set whether to check the number of fingers that tap the screen.  ([API Reference of Long Press Gesture](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.3-Release/en/application-dev/reference/apis-arkui/arkui-ts/ts-basic-gestures-longpressgesture.md), [API Reference of Pan Gesture](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.3-Release/en/application-dev/reference/apis-arkui/arkui-ts/ts-basic-gestures-pangesture.md), [API Reference of Pinch Gesture](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.3-Release/en/application-dev/reference/apis-arkui/arkui-ts/ts-basic-gestures-pinchgesture.md), [API Reference of Rotation Gesture](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.3-Release/en/application-dev/reference/apis-arkui/arkui-ts/ts-basic-gestures-rotationgesture.md), and [API Reference of Swipe Gesture](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.3-Release/en/application-dev/reference/apis-arkui/arkui-ts/ts-basic-gestures-swipegesture.md) and [API Reference of Tap Gesture](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.3-Release/en/application-dev/reference/apis-arkui/arkui-ts/ts-basic-gestures-tapgesture.md))

- The capabilities of setting the mode for processing key events and re-dispatching key events are added as follows:  
  - A C API for setting the mode of processing key events is added to NDK. ([API Reference](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.3-Release/en/application-dev/reference/apis-arkui/_ark_u_i___native_module.md#oh_arkui_focussetkeyprocessingmode))
  - The **NODE_DISPATCH_KEY_EVENT** (component key event re-dispatch event) is added to **ArkUI_NodeEventType** in NDK. ([API Reference](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.3-Release/en/application-dev/reference/apis-arkui/_ark_u_i___native_module.md#arkui_nodeeventtype))
  - An ArkTS API for setting the mode of key event processing is added to **UIContext**. ([API Reference](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.3-Release/en/application-dev/reference/apis-arkui/js-apis-arkui-UIContext.md#setkeyprocessingmode15))
  - An ArkTS API for distributing key events to specified components is added to **UIContext**. ([API Reference](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.3-Release/en/application-dev/reference/apis-arkui/js-apis-arkui-UIContext.md#dispatchkeyevent15))

- The **TextPicker** component allows you to disable the text style change animation and default text style during the scrolling process. ([API Reference](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.3-Release/en/application-dev/reference/apis-arkui/arkui-ts/ts-basic-components-textpicker.md#disabletextstyleanimation15))

- The **Progress** component supports a C API for setting the linear progress indicator style. ([API Reference](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.3-Release/en/application-dev/reference/apis-arkui/_ark_u_i___native_module.md#oh_arkui_progresslinearstyleoption_create))

- **FrameNode** supports cross-language capabilities ([API Reference](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.3-Release/en/application-dev/reference/apis-arkui/js-apis-arkui-frameNode.md#setcrosslanguageoptions15)) and expansion modes of child nodes during node traversal ([API Reference](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.3-Release/en/application-dev/reference/apis-arkui/js-apis-arkui-frameNode.md#expandmode15)).

- The **Indicator** component is added, which provides two types of navigation indicators: dot indicators and digit indicators. ([API Reference](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.3-Release/en/application-dev/reference/apis-arkui/arkui-ts/ts-swiper-components-indicator.md))

- Third-party platforms connecting to the ArkUI accessibility framework support searching for the next or previous focus (**ARKUI_ACCESSIBILITY_NATIVE_ACTION_TYPE_NEXT_HTML_ITEM**, **ARKUI_ACCESSIBILITY_NATIVE_ACTION_TYPE_PREVIOUS_HTML_ITEM**) ([API Reference](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.3-Release/en/application-dev/reference/apis-arkui/arkui_native_interface_accessibility.md#arkui_accessibility_actiontype)) and multi-instance scenarios ([API Reference](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.3-Release/en/application-dev/reference/apis-arkui/arkui_native_interface_accessibility.md#arkui_accessibilityprovidercallbackswithinstance)).

- The **NavDestination** component information of the ohos.arkui.observer module supports the **NavDestination** type and **uniqueId**. ([API Reference](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.3-Release/en/application-dev/reference/apis-arkui/js-apis-arkui-observer.md#navdestinationinfo))

- The **PatternLock** component allows you to set whether unselected dots in the grid are automatically selected when the password path passes over them. ([API Reference](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.3-Release/en/application-dev/reference/apis-arkui/arkui-ts/ts-basic-components-patternlock.md#skipunselectedpoint15))

- Focus axis events are added to universal events to support the response to the game controller axis event ([C API Reference](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.3-Release/en/application-dev/reference/apis-arkui/_ark_u_i___event_module.md#oh_arkui_axisevent_getaxisaction), [ArkTS API Reference](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.3-Release/en/application-dev/reference/apis-arkui/arkui-ts/ts-universal-events-focus_axis.md)).

- A C API is added for obtaining the action type of the current axis event. ([C API Reference](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.3-Release/en/application-dev/reference/apis-arkui/_ark_u_i___event_module.md#oh_arkui_focusaxisevent_getaxisvalue))

- The size attributes support adaptation of width and height to the parent component's layout. ([API Reference](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.3-Release/en/application-dev/reference/apis-arkui/arkui-ts/ts-universal-attributes-size.md#width15))

- The capability of obtaining component screenshots supports the definition of the component screenshot region. ([API Reference](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.3-Release/en/application-dev/reference/apis-arkui/js-apis-arkui-componentSnapshot.md#snapshotregion15))

- The **Security** component allows you to set the alignment of the icon and text ([API Reference](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.3-Release/en/application-dev/reference/apis-arkui/arkui-ts/ts-securitycomponent-attributes.md#align15)) and the radius of four border corners ([API Reference](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.3-Release/en/application-dev/reference/apis-arkui/arkui-ts/ts-securitycomponent-attributes.md#borderradius15)).


### Window Management

- The PiP window information, such as the ID and size, can be obtained. ([API Reference](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.3-Release/en/application-dev/reference/apis-arkui/js-apis-pipWindow.md#getpipwindowinfo15))

- The layout information of all windows visible on a display can be obtained. ([API Reference](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.3-Release/en/application-dev/reference/apis-arkui/js-apis-window.md#windowgetallwindowlayoutinfo15))

- The display density information of the current window can be obtained ([API Reference](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.3-Release/en/application-dev/reference/apis-arkui/js-apis-window.md#getwindowdensityinfo15)), the system density change event of the window can be subscribed ([API Reference](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.3-Release/en/application-dev/reference/apis-arkui/js-apis-window.md#onsystemdensitychange15)), and the display size scale factor of the main window can be set by itself ([API Reference](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.3-Release/en/application-dev/reference/apis-arkui/js-apis-window.md#setcustomdensity15)).

- The window movement configuration is added. Currently, the screen ID can be defined, and a window can be moved to another screen. ([API Reference](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.3-Release/en/application-dev/reference/apis-arkui/js-apis-window.md#movewindowtoasync15))

- C APIs of the window management are added. You can use the APIs to set and obtain the properties of a window, and set its status bar style and navigation bar style. ([API Reference](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.3-Release/en/application-dev/reference/apis-arkui/oh__window_8h.md))

- The fold status enumeration of the display module introduces multiple status definitions for the second fold axis. ([API Reference](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.3-Release/en/application-dev/reference/apis-arkui/js-apis-display.md#foldstatus10))

- An API is added for setting the size limits for this application window on the 2-in-1 device. ([API Reference](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.3-Release/en/application-dev/reference/apis-arkui/js-apis-window.md#setwindowlimits15))

- An API is added for specifying the cursor position within the window and moving the window. ([API Reference](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.3-Release/en/application-dev/reference/apis-arkui/js-apis-window.md#startmoving15))

- An asynchronous callback function is added for subscribing to the window close event on the 2-in-1 device. ([API Reference](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.3-Release/en/application-dev/reference/apis-arkui/js-apis-window.md#onwindowwillclose15))

- The PiP window size change event can be subscribed to. ([API Reference](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.3-Release/en/application-dev/reference/apis-arkui/js-apis-pipWindow.md#onpipwindowsizechange15))

- The title of the title bar can be dynamically set. ([API Reference](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.3-Release/en/application-dev/reference/apis-arkui/js-apis-window.md#setwindowtitle15))

- The supported window modes (**FULL_SCREEN**, **FLOATING**, and **SPLIT**) of the main window can be set. ([API Reference](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.3-Release/en/application-dev/reference/apis-arkui/js-apis-window.md#setsupportedwindowmodes15))


### Bundle Management

In **ApplicationInfo**, the definition **installSource** is enhanced with three new options: **ota**, **recovery**, and application bundle name. ([API Reference](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.3-Release/en/application-dev/reference/apis-ability-kit/js-apis-bundleManager-applicationInfo.md#applicationinfo-1))


### Distributed Data Management

- UDMF supports the capability of adding data of a specified type and content, and the corresponding query API is added. ([API Reference](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.3-Release/en/application-dev/reference/apis-arkdata/js-apis-data-unifiedDataChannel.md#addentry15))

- A smart data platform is added to provide data intelligence capabilities on the device, enabling AI-powered data processing on devices. ([User Guide](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.3-Release/en/application-dev/database/aip-data-intelligence-overview.md), [API Reference](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.3-Release/en/application-dev/reference/apis-arkdata/js-apis-data-intelligence.md))

- UDMF supports the capability of obtaining progress information and data. ([API Reference](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.3-Release/en/application-dev/reference/apis-arkdata/js-apis-data-unifiedDataChannel.md#dataprogresslistener15))


### File Management

- The definition and operation capabilities of atomic files are added. ([API Reference](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.3-Release/en/application-dev/reference/apis-core-file-kit/js-apis-file-fs.md#atomicfile15))

- The total size and available size of the device's built-in storage can be obtained. ([API Reference](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.3-Release/en/application-dev/reference/apis-core-file-kit/js-apis-file-storage-statistics.md#storagestatisticsgettotalsize15))

- The **Stat** attribute supports three new properties: **atimeNs** (time of the last access to the file), **mtimeNs** (time of the last modification to the file), and **ctimeNs** (time of the last status change of the file). ([API Reference](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.3-Release/en/application-dev/reference/apis-core-file-kit/js-apis-file-fs.md#stat))

- The file selector supports batch file authorization. ([User Guide](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.3-Release/en/application-dev/file-management/select-user-file.md#selecting-documents), [API Reference](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.3-Release/en/application-dev/reference/apis-core-file-kit/js-apis-file-picker.md#documentselectoptions))


### Media

**Video Encoding**


C APIs are added to support the video variable refresh rate feature. ([User Guide](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.3-Release/en/application-dev/media/avcodec/video-variable-refreshrate.md))


**Image Processing**


- A **PixelMap** object can be created from a surface ID without specifying the region. ([API Reference](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.3-Release/en/application-dev/reference/apis-image-kit/js-apis-image.md#imagecreatepixelmapfromsurface15))

- A C API is added for obtaining the memory address where the pixels of a **PixelMap** are stored. ([API Reference](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.3-Release/en/application-dev/reference/apis-image-kit/_image___native_module.md#oh_pixelmapnative_accesspixels))


**Screen Recording**


- A C API is added for setting whether to display the cursor during screen recording. ([API Reference](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.3-Release/en/application-dev/reference/apis-media-kit/_a_v_screen_capture.md#oh_avscreencapture_showcursor))

- A callback is added for obtaining the screen ID during screen recording. ([API Reference](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.3-Release/en/application-dev/reference/apis-media-kit/_a_v_screen_capture.md#oh_avscreencapture_setdisplaycallback))


**Camera**


- The type of a distributed camera can be obtained. ([API Reference](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.3-Release/en/application-dev/reference/apis-camera-kit/js-apis-camera.md#hostdevicetype15))

- The mirror recording is supported. ([API Reference](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.3-Release/en/application-dev/reference/apis-camera-kit/js-apis-camera.md#enablemirror13))


**Media Library**


Images in the album can be previewed and replaced through **photoPicker**. ([API Reference](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.3-Release/en/application-dev/reference/apis-media-library-kit/ohos-file-PhotoPickerComponent.md#replacephotopickerpreview15))


### Graphics

- The **Tool** class is added for converting values of the **ResourceColor** type to the **common2D.Color** objects. ([API Reference](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.3-Release/en/application-dev/reference/apis-arkgraphics2d/js-apis-graphics-drawing.md#tool15))

- You are allowed to set whether the drawing font follows the theme font. ([C API Reference](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.3-Release/en/application-dev/reference/apis-arkgraphics2d/_drawing.md#oh_drawing_fontsetthemefontfollowed), [ArkTS API Reference](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.3-Release/en/application-dev/reference/apis-arkgraphics2d/js-apis-graphics-drawing.md#setthemefontfollowed15))

- A C API is added for obtaining the transformation matrix calculated based on the rotation angle set by the producer and the actual valid content area of the buffer. ([API Reference](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.3-Release/en/application-dev/reference/apis-arkgraphics2d/_o_h___native_image.md#oh_nativeimage_getbuffermatrix))

- **NativeBuffer** supports two new formats: **NATIVEBUFFER_PIXEL_FMT_BLOB** and **NATIVEBUFFER_PIXEL_FMT_RGBA16_FLOAT**. ([API Reference](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.3-Release/en/application-dev/reference/apis-arkgraphics2d/_o_h___native_buffer.md#oh_nativebuffer_format-1))


### Programming Language Runtime

A maximum of 64 runtime environments can be created for a process, and the total number of Worker threads and runtime environments created by a process cannot exceed 80.


### Communications

- Wi-Fi 7 and Wi-Fi 7+ are supported. ([API Reference](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.3-Release/en/application-dev/reference/apis-connectivity-kit/js-apis-wifiManager.md#wificategory12))

- The **wifiManager** module supports the checking of whether a hotspot is active. ([API Reference](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.3-Release/en/application-dev/reference/apis-connectivity-kit/js-apis-wifiManager.md#wifimanagerishotspotactive15))

- The Wi-Fi management capabilities of the **wifiManager** module are available to enterprise applications. ([API Reference](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.3-Release/en/application-dev/reference/apis-connectivity-kit/js-apis-wifiManager.md#wifimanagerenablewifi15))


### Network Management

The URL of the system-level proxy auto-config (PAC) script can be set. ([C API Reference](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.3-Release/en/application-dev/reference/apis-network-kit/_net_connection.md#oh_netconn_setpacurl), [ArkTS API Reference](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.3-Release/en/application-dev/reference/apis-network-kit/js-apis-net-connection.md#connectionsetpacurl15))


### DFX

- HiLog supports the setting of the minimum log level for application logging. ([C API Reference](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.3-Release/en/application-dev/reference/apis-performance-analysis-kit/_hi_log.md#oh_log_setminloglevel), [ArkTS API Reference](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.3-Release/en/application-dev/reference/apis-performance-analysis-kit/js-apis-hilog.md#hilogsetminloglevel15))

- The sandbox of a debug application can be accessed through hdc to read logs and resources in the sandbox in the debugging state. ([User Guide](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.3-Release/en/application-dev/dfx/hdc.md#running-the-interactive-command))

- HiAppEvent enhances the debugging capabilities for the main thread jank events. ([User Guide](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.3-Release/en/application-dev/dfx/hiappevent-watcher-mainthreadjank-events.md), [API Reference](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.3-Release/en/application-dev/reference/apis-performance-analysis-kit/js-apis-hiviewdfx-hiappevent.md#hiappeventseteventconfig15))


### NDK

The development capability based on the OpenMP library is supported. ([User Guide](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.3-Release/en/application-dev/napi/openmp-overview.md))


### Device Management

- The button events of the game controller can be identified and distributed. ([API Reference](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.3-Release/en/application-dev/reference/apis-input-kit/js-apis-keycode.md#keycode))

- The motion awareness capability is added for sensing user gestures and actions. ([User Guide](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.3-Release/en/application-dev/device/stationary/motion-guidelines.md), [API Reference](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.3-Release/en/application-dev/reference/apis-multimodalawareness-kit/js-apis-awareness-motion.md))


### Enterprise Customization

- The browser policy can be set for a specified browser. ([API Reference](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.3-Release/en/application-dev/reference/apis-mdm-kit/js-apis-enterprise-browser.md#browsersetmanagedbrowserpolicy15))

- The network proxy of a specified user can be set (only for 2-in-1 devices). ([API Reference](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.3-Release/en/application-dev/reference/apis-mdm-kit/js-apis-enterprise-networkManager.md#networkmanagersetglobalproxyforaccount15))


### Input Method

- The state of the input method can be obtained. ([API Reference](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.3-Release/en/application-dev/reference/apis-ime-kit/js-apis-inputmethod.md#getinputmethodstate15))

- APIs are added for custom communication between input method applications and text boxes. ([API Reference of Input Method Framework](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.3-Release/en/application-dev/reference/apis-ime-kit/js-apis-inputmethod.md#messagehandleronmessage15), [API Reference of Input Method Service](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.3-Release/en/application-dev/reference/apis-ime-kit/js-apis-inputmethodengine.md#messagehandleronmessage15))

- The input method keyboard window can be moved. ([API Reference](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.3-Release/en/application-dev/reference/apis-ime-kit/js-apis-inputmethodengine.md#startmoving15))


### Pasteboard

The progress indicator can be set. ([C API Reference](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.3-Release/en/application-dev/reference/apis-basic-services-kit/_pasteboard.md#oh_pasteboard_getdataparams_setprogressindicator), [ArkTS API Reference](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.3-Release/en/application-dev/reference/apis-basic-services-kit/js-apis-pasteboard.md#progressindicator15))


### Web

The cookies can be persisted. ([API Reference](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.3-Release/en/application-dev/reference/apis-arkweb/js-apis-webview.md#savecookiesync15))


### Upload and Download

- The upload and download tasks can be grouped and notifications can be displayed by group. ([API Reference](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.3-Release/en/application-dev/reference/apis-basic-services-kit/js-apis-request.md#requestagentcreategroup15))

- A maximum of 8192 characters can be contained in an upload or download URL. ([API Reference](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.3-Release/en/application-dev/reference/apis-basic-services-kit/js-apis-request.md#uploadconfig6))

- Multiple files can be uploaded through a single upload request by setting the **multipart** parameter in **Config**. ([API Reference](https://gitee.com/openharmony/docs/blob/master/en/application-dev/reference/apis-basic-services-kit/js-apis-request.md#config10))

- The notification bar can be customized. ([API Reference](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.3-Release/en/application-dev/reference/apis-basic-services-kit/js-apis-request.md#notification15))


### Globalization

- The standard ICU C library (ICU4C) supports Unicode string processing (ustring.h) and ICU text abstract representation (utext.h). ([API Reference](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.3-Release/en/application-dev/reference/native-lib/icu4c.md))

- The simplified representation of a language can be obtained. For example, the simplified representation of **en-Latn-US** is **en**. ([API Reference](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.3-Release/en/application-dev/reference/apis-localization-kit/js-apis-i18n.md#getsimplifiedlanguage15))


### Resource Scheduler

A listener callback for the canceling of a continuous task is added. ([API Reference](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.3-Release/en/application-dev/reference/apis-backgroundtasks-kit/js-apis-resourceschedule-backgroundTaskManager.md#backgroundtaskmanageroncontinuoustaskcancel15))


## Mapping Relationship

**Table 1** Version mapping of software and tools

| Software/Tool| Version| Remarks| 
| -------- | -------- | -------- |
| OpenHarmony | 5.0.3 Release | NA | 
| Public SDK | Ohos_sdk_public 5.0.3.135 (API Version 15 Release) | This toolkit is intended for application developers and does not contain system APIs that require system permissions. It is provided as standard in DevEco Studio.| 
| (Optional) HUAWEI DevEco Studio| 5.0.3 Release | Recommended for developing OpenHarmony applications.| 
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

4. Run the following commands to install the **repo** tool:
   ```
   curl -s https://gitee.com/oschina/repo/raw/fork_flow/repo-py3 > /usr/local/bin/repo  #If you do not have the permission, download the tool to another directory and configure it as an environment variable by running the chmod a+x /usr/local/bin/repo command.
   pip3 install -i https://repo.huaweicloud.com/repository/pypi/simple requests
   ```


### Acquiring Source Code Using the repo Tool

**Method 1 (recommended)**

Use the **repo** tool to download the source code over SSH. (You must have an SSH public key for access to Gitee.)

- Obtain the source code from the version branch. You can obtain the latest source code of the version branch, which includes the code that has been incorporated into the branch up until the time you run the following commands:
   ```
   repo init -u git@gitee.com:openharmony/manifest.git -b OpenHarmony-5.0.3-Release --no-repo-verify
   repo sync -c
   repo forall -c 'git lfs pull'
   ```
   
- Obtain the source code from the version tag, which is the same as that released with the version.
   ```
   repo init -u git@gitee.com:openharmony/manifest.git -b refs/tags/OpenHarmony-v5.0.3-Release --no-repo-verify
   repo sync -c
   repo forall -c 'git lfs pull'
   ```

**Method 2**

Use the **repo** tool to download the source code over HTTPS.

- Obtain the source code from the version branch. You can obtain the latest source code of the version branch, which includes the code that has been incorporated into the branch up until the time you run the following commands:
   ```
   repo init -u https://gitee.com/openharmony/manifest -b OpenHarmony-5.0.3-Release --no-repo-verify
   repo sync -c
   repo forall -c 'git lfs pull'
   ```
   
- Obtain the source code from the version tag, which is the same as that released with the version.
   ```
   repo init -u https://gitee.com/openharmony/manifest -b refs/tags/OpenHarmony-v5.0.3-Release --no-repo-verify
   repo sync -c
   repo forall -c 'git lfs pull'
   ```


### Acquiring Source Code from Mirrors


**Table 2** Mirrors for acquiring source code

| Source Code                               | Version| Mirror                                                | SHA-256 Checksum                                            | Software Package Size|
| --------------------------------------- | ------------ | ------------------------------------------------------------ | ------------------------------------------------------------ | -------- |
| Full code base (for mini, small, and standard systems)       | 5.0.3 Release    | [Download](https://repo.huaweicloud.com/openharmony/os/5.0.3-Release/code-v5.0.3-Release.tar.gz) | [Download](https://repo.huaweicloud.com/openharmony/os/5.0.3-Release/code-v5.0.3-Release.tar.gz.sha256)| 43.3 GB |
| Hi3861 solution (binary)       | 5.0.3 Release    | [Download](https://repo.huaweicloud.com/openharmony/os/5.0.3-Release/hispark_pegasus.tar.gz) | [Download](https://repo.huaweicloud.com/openharmony/os/5.0.3-Release/hispark_pegasus.tar.gz.sha256)| 27.2 MB |
| Hi3516 solution-LiteOS (binary)| 5.0.3 Release    | [Download](https://repo.huaweicloud.com/openharmony/os/5.0.3-Release/hispark_taurus_LiteOS.tar.gz) | [Download](https://repo.huaweicloud.com/openharmony/os/5.0.3-Release/hispark_taurus_LiteOS.tar.gz.sha256) | 328.7 MB |
| Hi3516 solution-Linux (binary) | 5.0.3 Release    | [Download](https://repo.huaweicloud.com/openharmony/os/5.0.3-Release/hispark_taurus_Linux.tar.gz) | [Download](https://repo.huaweicloud.com/openharmony/os/5.0.3-Release/hispark_taurus_Linux.tar.gz.sha256)| 221.4 MB |
| RK3568 standard system solution (binary)       | 5.0.3 Release    | [Download](https://repo.huaweicloud.com/openharmony/os/5.0.3-Release/dayu200_standard_arm32.tar.gz)| [Download](https://repo.huaweicloud.com/openharmony/os/5.0.3-Release/dayu200_standard_arm32.tar.gz.sha256)| 13.2 GB |
| Public SDK package for the standard system (macOS)            | 5.0.3.135 | [Download](https://repo.huaweicloud.com/openharmony/os/5.0.3-Release/ohos-sdk-mac-public.tar.gz) | [Download](https://repo.huaweicloud.com/openharmony/os/5.0.3-Release/ohos-sdk-mac-public.tar.gz.sha256)| 1.3 GB |
| Public SDK package for the standard system (macOS-M1)            | 5.0.3.135  | [Download](https://repo.huaweicloud.com/openharmony/os/5.0.3-Release/L2-SDK-MAC-M1-PUBLIC.tar.gz)| [Download](https://repo.huaweicloud.com/openharmony/os/5.0.3-Release/L2-SDK-MAC-M1-PUBLIC.tar.gz.sha256)| 1.2 GB |
| Public SDK package for the standard system (Windows/Linux)  | 5.0.3.135   | [Download](https://repo.huaweicloud.com/openharmony/os/5.0.3-Release/ohos-sdk-windows_linux-public.tar.gz)| [Download](https://repo.huaweicloud.com/openharmony/os/5.0.3-Release/ohos-sdk-windows_linux-public.tar.gz.sha256)| 4.3 GB |


## Resolved Issues

**Table 3** Resolved issues

| Issue No.| Description| 
| ------- | ------- |
| IANQF3 | There is a high probability that the system restarts during the WuKong pressure test.|
| IBJ6LH | The new security verification mechanism may cause long processing duration for deleting multiple images, affecting user experience.|
| IBDPFF | There is a low probability that a C++ crash occurs in the **SaOndemand** thread of the **intell_voice_service** process, and the crash stack is **libintell_voice_server.z.so**.|

## Unfixed Vulnerabilities

**Table 4** Known issues

| ISSUE | Description| Impact| To Be Resolved By| 
| -------- | -------- | -------- | -------- |
| IBTXFK | It may take more than 1000 ms to delete multiple images from Gallery.| User experience is affected.| 2025-04-30|
| IBTCKR | It may take more than 160 ms from when the SystemUI status bar is pulled down to when the content rendering is complete.| User experience is affected.| 2025-04-30|
| IBTCJQ | The frame rate for zooming in or out of an FWX image is less than 60 fps.| User experience is affected.| 2025-04-30|
| IBBZPS | There is a low probability that a C++ crash occurs in the **OS_IPC_0_1067** thread of the **com.ohos.systemui** process, and the crash stack is **ld-musl-arm.so.1(__libc_free+172)**.| The system is abnormal, and users are unaware of the exception.| 2025-04-30| 
| IBE36X<br>IBO3MF | There is a low probability that system freezing occurs in **render_service** due to **SERVICE_BLOCK**.| A black screen is displayed when the home screen does not respond. After the screen recovers, the home screen is displayed.| 2025-04-30|
| IBINUK | There is a probability that system freezing occurs in **libcamera_framework.z.so** due to **LIFECYCLE_TIMEOUT** in the **com.ohos.camera** process.| The camera cannot be invoked, which can be recovered after restart.| 2025-04-30|
