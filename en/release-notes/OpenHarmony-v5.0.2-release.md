# OpenHarmony 5.0.2 Release


## Version Description

OpenHarmony 5.0.2 Release continuously improves the capabilities of the standard system, rolling out API 14 via quick iteration. Compared with 5.0.1 Release, OpenHarmony 5.0.2 Release has the following new or enhanced features:

ArkUI and graphics capabilities are further enhanced with advanced component attributes and animations. Web capabilities are improved to meet more application requirements. New window management capabilities and window lifecycle behaviors are added for 2-in-1 devices. Customization options for enterprise applications are added to support flexible management.

A more detailed description of the enhancements is as follows:


### Application Framework

- The application startup page can be customized for 2-in-1 and tablet devices. ([API Reference](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.2-Release/en/application-dev/reference/apis-ability-kit/js-apis-app-ability-startOptions.md#properties))

- When **Want** is used to pass information between objects, the **parameters** parameter can carry the index of the application clone (**ohos.param.callerAppCloneIndex**). ([API Reference](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.2-Release/en/application-dev/reference/apis-ability-kit/js-apis-app-ability-want.md#properties))

- The application-level context can be obtained. ([API Reference](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.2-Release/en/application-dev/reference/apis-ability-kit/js-apis-app-ability-application.md#applicationgetapplicationcontext14))

- The package management capability can be called by third-party applications. ([API Reference](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.2-Release/en/application-dev/reference/apis-ability-kit/js-apis-bundleManager.md))

- The UIAbility backup and restoration capability is supported. ([API Reference](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.2-Release/en/application-dev/reference/apis-ability-kit/js-apis-inner-application-uiAbilityContext.md#uiabilitycontextsetrestoreenabled14), [Guide](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.2-Release/en/application-dev/application-models/ability-recover-guideline.md))

- The unique instance ID of multiple instances of an application can be obtained. ([API Reference](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.2-Release/en/application-dev/reference/apis-ability-kit/js-apis-inner-application-applicationContext.md#applicationcontextgetcurrentinstancekey14))

- The unique ID of the current system font (**fontId**) is added to the environment change information. ([API Reference](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.2-Release/en/application-dev/reference/apis-ability-kit/js-apis-app-ability-configuration.md#properties))

- A C API is added to obtain the compatible device type of the application and determine whether the application can directly run on the 2-in-1 device. ([API Reference](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.2-Release/en/application-dev/reference/apis-ability-kit/_bundle.md#oh_nativebundle_getcompatibledevicetype))


### ArkUI

- The route navigation capability is enhanced as follows:  
  - The navigation page stack can be restored upon abnormal exit. ([API Reference](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.2-Release/en/application-dev/reference/apis-arkui/arkui-ts/ts-basic-components-navigation.md#recoverable14))
  - The **NavDestination** component can be bound with the scrollable container. When the scrollable container is scrolled, the title bar and toolbar of all bound **NavDestination** components are displayed or hidden. ([API Reference](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.2-Release/en/application-dev/reference/apis-arkui/arkui-ts/ts-basic-components-navdestination.md#bindtoscrollable14))
  - The **Navigation** component supports system transition animation enums for a single page. The system title bar animation, content animation, and no animation can be set separately. ([API Reference](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.2-Release/en/application-dev/reference/apis-arkui/arkui-ts/ts-basic-components-navdestination.md#systemtransition14))
  - The router option of setting whether a page can be restored is added. ([API Reference](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.2-Release/en/application-dev/reference/apis-arkui/js-apis-router.md#routeroptions))

- The text and input components' capabilities are enhanced as follows:  
  - The styled string supports background color setting, hyperlink setting, and conversion to an HTML string. ([API Reference](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.2-Release/en/application-dev/reference/apis-arkui/arkui-ts/ts-universal-styled-string.md))
  - The **ImageSpan** component supports color filters for images. ([API Reference](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.2-Release/en/application-dev/reference/apis-arkui/arkui-ts/ts-basic-components-imagespan.md#colorfilter14))
  - The drawing area information of a specified character in the **Text** component can be obtained. ([API Reference](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.2-Release/en/application-dev/reference/apis-arkui/arkui-ts/ts-text-common.md#getrectsforrange14)). The keyboard avoidance mode during text input supports caret avoidance. ([API Reference](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.2-Release/en/application-dev/reference/apis-arkui/js-apis-arkui-UIContext.md#keyboardavoidmode11))
  - The **TextPicker** component supports event callback upon scrolling stop. ([API Reference](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.2-Release/en/application-dev/reference/apis-arkui/arkui-ts/ts-basic-components-textpicker.md#onscrollstop14))

- The scroll and swipe components' capabilities are enhanced as follows:  
  - The scrollable component supports the settings of content clipping area and edge fading effect. ([API Reference](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.2-Release/en/application-dev/reference/apis-arkui/arkui-ts/ts-container-scrollable-common.md))
  - The **List** component supports the setting of whether to display the preloaded list items and list item groups. ([API Reference](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.2-Release/en/application-dev/reference/apis-arkui/arkui-ts/ts-container-list.md#cachedcount14))
  - The **Grid** and **WaterFlow** components support the setting of whether to display the preloaded list items and list item groups. ([API Reference of the **Grid** component](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.2-Release/en/application-dev/reference/apis-arkui/arkui-ts/ts-container-grid.md#cachedcount14), [API Reference of the **WaterFlow** component](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.2-Release/en/application-dev/reference/apis-arkui/arkui-ts/ts-container-waterflow.md#cachedcount14))

- The common capabilities of C APIs are enhanced as follows:  
  - A key event callback with a return value can be registered for the **OH_NativeXComponent** instance. ([API Reference](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.2-Release/en/application-dev/reference/apis-arkui/_o_h___native_x_component.md#oh_nativexcomponent_registerkeyeventcallbackwithresult))
  - Custom attributes of a node can be obtained. ([API Reference](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.2-Release/en/application-dev/reference/apis-arkui/_ark_u_i___native_module.md#oh_arkui_nodeutils_getnodetype))
  - The **NodeAttributeType** supports a C API attribute for obtaining the total size of all child components when they are fully expanded in the scrollable component. ([API Reference](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.2-Release/en/application-dev/reference/apis-arkui/_ark_u_i___native_module.md#arkui_nodeattributetype))

- The key event supports the **unicode** object, which can be used to return the Unicode value of the key corresponding to the key event. ([API Reference](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.2-Release/en/application-dev/reference/apis-arkui/arkui-ts/ts-universal-events-key.md#keyevent))

- The **enableHoverMode** and **hoverModeArea** attributes are added to **SheetOptions** of the sheet transition to support the hover mode. ([API Reference](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.2-Release/en/application-dev/reference/apis-arkui/arkui-ts/ts-universal-attributes-sheet-transition.md#sheetoptions))

- **DatePickerDialog** supports the setting of the style of the lunar calendar switch. ([API Reference](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.2-Release/en/application-dev/reference/apis-arkui/arkui-ts/ts-methods-datepicker-dialog.md#lunarswitchstyle14))

- The six types of gesture events involved in the gesture processing capability support the setting of allowed event input types. ([API Reference](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.2-Release/en/application-dev/reference/apis-arkui/arkui-ts/ts-uigestureevent.md#allowedtypes14)). FreamNode supports new gesture events. ([API Reference](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.2-Release/en/application-dev/reference/apis-arkui/js-apis-arkui-frameNode.md#gestureevent14))

- The location attributes support the re-layout of components that form a chain. ([API Reference](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.2-Release/en/application-dev/reference/apis-arkui/arkui-ts/ts-universal-attributes-location.md#chainweight14)); the background attributes support the setting of removing the blur effect on the components within the window after the window loses focus. ([API Reference](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.2-Release/en/application-dev/reference/apis-arkui/arkui-ts/ts-universal-attributes-background.md#backgroundeffectoptions11))

- The component-level safe area padding can be set for containers. ([API Reference](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.2-Release/en/application-dev/reference/apis-arkui/arkui-ts/ts-universal-attributes-size.md#safeareapadding14))

- The Image component supports the setting of the image display orientation. ([API Reference](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.2-Release/en/application-dev/reference/apis-arkui/arkui-ts/ts-basic-components-image.md#orientation14))


### Window Management

- For applications on 2-in-1 devices, the listener for closing an application through the close button of the application window is supported. This API can be used to ignore the callback of the preset close switch. ([API Reference](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.2-Release/en/application-dev/reference/apis-arkui/js-apis-window.md#onwindowstageclose14))

- For applications on 2-in-1 devices, the size and position of the main window of an application can be customized in the **module.json5** file. ([Guide](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.2-Release/en/application-dev/quick-start/module-configuration-file.md#metadata))

- For applications on 2-in-1 devices, the capability of restoring the minimized applications to the foreground is supported. ([API Reference](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.2-Release/en/application-dev/reference/apis-arkui/js-apis-window.md#restore14))

- For applications on 2-in-1 devices, the capability of obtaining visible windows at specified coordinates in the application is supported. ([API Reference](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.2-Release/en/application-dev/reference/apis-arkui/js-apis-window.md#windowgetwindowsbycoordinate14))

- For applications on 2-in-1 devices, the capability of enabling or disabling the main window or child window to resize itself by dragging is supported. ([API Reference](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.2-Release/en/application-dev/reference/apis-arkui/js-apis-window.md#setresizebydragenabled14))

- For applications on 2-in-1 devices, the main window can be set to a modal window. ([API Reference](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.2-Release/en/application-dev/reference/apis-arkui/js-apis-window.md#setwindowmodal14))

- For applications on 2-in-1 devices, the time when the launch page disappears can be controlled by themselves. ([API Reference](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.2-Release/en/application-dev/reference/apis-arkui/js-apis-window.md#removestartingwindow14))

- For applications on 2-in-1 devices, you can set whether to enable the auto-save feature for the size of the main window. ([API Reference](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.2-Release/en/application-dev/reference/apis-arkui/js-apis-window.md#setwindowrectautosave14))

- For applications on 2-in-1 devices, you can set whether to show the window title bar and dock bar when the cursor hovers over the hot zone while the main window is in full-screen mode. ([API Reference](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.2-Release/en/application-dev/reference/apis-arkui/js-apis-window.md#settitleanddockhovershown14))

- For applications on 2-in-1 devices, you can set whether to display the maximize, minimize, and close buttons on the title bar of the main window. ([API Reference](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.2-Release/en/application-dev/reference/apis-arkui/js-apis-window.md#setwindowtitlebuttonvisible14))

- For applications on 2-in-1 devices, the main window can be placed above other application windows. ([API Reference](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.2-Release/en/application-dev/reference/apis-arkui/js-apis-window.md#setwindowtopmost14))

- For applications on 2-in-1 devices, you can move an application window without the system title bar. ([API Reference](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.2-Release/en/application-dev/reference/apis-arkui/js-apis-window.md#startmoving14))

- You can set an effect template for a window, for example, the background blur effect with perspective. ([API Reference](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.2-Release/en/application-dev/reference/apis-arkui/arkui-ts/ts-universal-attributes-use-effect.md#useeffect14))

- You can subscribe to the display change event of a window, for example, when the window is moved to another display. ([API Reference](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.2-Release/en/application-dev/reference/apis-arkui/js-apis-window.md#ondisplayidchange14))

- The modality type of the child window can be set. ([API Reference](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.2-Release/en/application-dev/reference/apis-arkui/js-apis-window.md#setsubwindowmodal14))


### Bundle Management

- HSP supports the declaration of UIAbility components except the entry ability in the configuration file. ([Guide](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.2-Release/en/application-dev/quick-start/in-app-hsp.md#constraints))

- The **orientation** attribute in the [abilities](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.2-Release/en/application-dev/quick-start/module-configuration-file.md#abilities) tag of the **module.json5** file can be configured using the resource index (**$string**).

- In the [extensionAbilities](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.2-Release/en/application-dev/quick-start/module-configuration-file.md#extensionabilities) tag of the **module.json5** file, the **extensionProcessMode** attribute supports the **runWithMainProcess** type, indicating that the **ExtensionAbility** and the main process of the application share the same process.

- In the [extensionAbilities](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.2-Release/en/application-dev/quick-start/module-configuration-file.md#extensionabilities) tag of the **module.json5** file, the **process** attribute is supported for running the **ExtensionAbility** whose type is **embeddedUI** in the same process with abilities.


### Distributed Data Management

- The newly added **flushSync** API can store data in the cached Preferences instance to the persistent file of the shared user preferences. ([API Reference](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.2-Release/en/application-dev/reference/apis-arkdata/js-apis-data-sendablePreferences.md#flushsync14))

- In the **StoreConfig** attribute of a relational database (RDB), the **cryptoParam** parameter is supported for customizing encryption parameters. ([API Reference](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.2-Release/en/application-dev/reference/apis-arkdata/js-apis-data-relationalStore.md#storeconfig))

- RDB supports the creation of concurrent transaction objects. ([API Reference](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.2-Release/en/application-dev/reference/apis-arkdata/js-apis-data-relationalStore.md))

- The Unified Data Management Framework (UDMF) supports the data structure of the content widget type (**ContentForm**). ([API Reference](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.2-Release/en/application-dev/reference/apis-arkdata/js-apis-data-uniformDataStruct.md#contentform14))

- UDMF supports the setting of **ShareOptions** for the application data. ([API Reference](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.2-Release/en/application-dev/reference/apis-arkdata/js-apis-data-unifiedDataChannel.md#unifieddatachannelsetappshareoptions14))


### File Management

- The name extension of a file that is successfully saved can be obtained. ([API Reference](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.2-Release/en/application-dev/reference/apis-core-file-kit/js-apis-file-picker.md#getselectedindex14))


### Media


- The streaming media supports more error codes to explain the exception scenarios. ([API Reference](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.2-Release/en/application-dev/reference/apis-media-kit/js-apis-media.md#averrorcode9))


- The playback control supports the capability of casting semi-modal objects. ([API Reference](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.2-Release/en/application-dev/reference/apis-avsession-kit/js-apis-avsession.md#avcastpickerhelper14))


- The screen recording supports a C API for setting the maximum frame rate. ([API Reference](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.2-Release/en/application-dev/reference/apis-media-kit/_a_v_screen_capture.md#oh_avscreencapture_setmaxvideoframerate))


- The media library supports the configuration of the text on the complete button, which can be displayed as "Done", "Send", or "Add". ([API Reference](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.2-Release/en/application-dev/reference/apis-media-library-kit/js-apis-photoAccessHelper.md#completebuttontext14))


- The **PhotoPickerComponent** of the media library supports the **videoPlayStateChangedCallback**. ([API Reference](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.2-Release/en/application-dev/reference/apis-media-library-kit/ohos-file-PhotoPickerComponent.md#videoplayerstate14))

- The **PhotoPickerComponent** of the media library supports the **onVideoPlayStateChanged** callback. ([API Reference](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.2-Release/en/application-dev/reference/apis-media-library-kit/ohos-file-PhotoPickerComponent.md#photopickercomponent))


- The camera supports a C API and an ArkTS API for setting the recording quality priority, with **HIGH-QUALITY** and **POWER-BALANCE** options. ([C API Reference](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.2-Release/en/application-dev/reference/apis-camera-kit/_o_h___camera.md#oh_capturesession_setqualityprioritization), [ArkTS API Reference](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.2-Release/en/application-dev/reference/apis-camera-kit/js-apis-camera.md#setqualityprioritization14))


### Graphics

- A C API is added to obtain the global font collection of the system. ([API Reference](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.2-Release/en/application-dev/reference/apis-arkgraphics2d/_drawing.md#oh_drawing_getfontcollectionglobalinstance))

- The C API capability of Decoupled VSync (DVSync) is added to improve the smoothness of self-drawing animations. ([API Reference](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.2-Release/en/application-dev/reference/apis-arkgraphics2d/_native_vsync.md#oh_nativevsync_dvsyncswitch))

- A blur effect filter is added, with the tile modes of the shader effect provided, which affects the blur effect of image edges. ([API Reference](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.2-Release/en/application-dev/reference/apis-arkgraphics2d/js-apis-effectKit.md#blur14))

- A C API is added to enable the browser to support dynamic frame rates. ([API Reference](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.2-Release/en/application-dev/reference/apis-arkgraphics2d/_native_vsync.md#oh_nativevsync_create_forassociatedwindow))


### Security

The ECC algorithm used by [asymmetric key generation and conversion](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.2-Release/en/application-dev/security/CryptoArchitectureKit/crypto-asym-key-generation-conversion-spec.md#string-parameter-1), [key agreement](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.2-Release/en/application-dev/security/CryptoArchitectureKit/crypto-key-agreement-overview.md#ecdh), and [signature verification](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.2-Release/en/application-dev/security/CryptoArchitectureKit/crypto-sign-sig-verify-overview.md#ecdsa) supports the secp256k1 curve.


### Enterprise Customization

- The capability of disabling the device camera is added for enterprise applications. ([API Reference](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.2-Release/en/application-dev/reference/apis-mdm-kit/js-apis-enterprise-restrictions.md#restrictionssetdisallowedpolicy))

- For enterprise application installation events, a callback is added to return the bundle name and account ID. ([API Reference](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.2-Release/en/application-dev/reference/apis-avcodec-kit/_codec_base.md#oh_aacprofile-1))

- Enterprise applications can delegate other applications to set device management policies. ([API Reference](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.2-Release/en/application-dev/reference/apis-mdm-kit/js-apis-enterprise-adminManager.md#adminmanagersetdelegatedpolicies14))

- Enterprise applications on the 2-in-1 device can enable or disable the device fingerprint authentication capability. ([API Reference](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.2-Release/en/application-dev/reference/apis-mdm-kit/js-apis-enterprise-restrictions.md#restrictionssetdisallowedpolicyforaccount14))

- Enterprise applications on the 2-in-1 device can disable the screen snapshot function. ([API Reference](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.2-Release/en/application-dev/reference/apis-mdm-kit/js-apis-enterprise-restrictions.md#restrictionsadddisallowedlistforaccount14))

- Enterprise applications on the 2-in-1 device support watermark configuration. ([API Reference](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.2-Release/en/application-dev/reference/apis-mdm-kit/js-apis-enterprise-securityManager.md#securitymanagersetwatermarkimage14))

- Enterprise applications on the 2-in-1 device support adding applications that need to be kept alive through the device administrator application. ([API Reference](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.2-Release/en/application-dev/reference/apis-mdm-kit/js-apis-enterprise-applicationManager.md#applicationmanageraddkeepaliveapps14))

- Enterprise applications on the 2-in-1 device support adding disallowed USB device types through the device administrator application. ([API Reference](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.2-Release/en/application-dev/reference/apis-mdm-kit/js-apis-enterprise-usbManager.md#usbmanageradddisallowedusbdevices14))


### USB

USB management supports checking whether applications have the permission to access USB accessories. ([API Reference](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.2-Release/en/application-dev/reference/apis-basic-services-kit/js-apis-usbManager.md#usbmanagerhasaccessoryright14))


### Input Method

In the input method framework, the **EditorAttribute** supports the bundle name of the application to which the editor belongs. ([API Reference](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.2-Release/en/application-dev/reference/apis-ime-kit/js-apis-inputmethodengine.md#editorattribute))


### Pasteboard

- The pasteboard supports the definition and use of content objects in multiple formats through MIME. ([API Reference](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.2-Release/en/application-dev/reference/apis-basic-services-kit/js-apis-pasteboard.md#pasteboardcreatedata14))

- A C API and an ArkTS API are added to obtain the content of the MIME type on the pasteboard. ([C API Reference](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.2-Release/en/application-dev/reference/apis-basic-services-kit/_pasteboard.md#oh_pasteboard_getmimetypes), [ArkTS API Reference](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.2-Release/en/application-dev/reference/apis-basic-services-kit/js-apis-pasteboard.md#getmimetypes14))


### Web

- When a user collapses the soft keyboard, the focus can be moved from the text box to the web body. ([API Reference](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.2-Release/en/application-dev/reference/apis-arkweb/ts-basic-components-web.md#bluronkeyboardhidemode14))

- A C API is added to obtain the URL of the last frame that calls **JavaScriptProxy**. ([API Reference](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.2-Release/en/application-dev/reference/apis-arkweb/_ark_web___controller_a_p_i.md#getlastjavascriptproxycallingframeurl))

- The default user agent can be obtained. ([API Reference](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.2-Release/en/application-dev/reference/apis-arkweb/js-apis-webview.md#getdefaultuseragent14))

- The cookie value can be set for a specified URL. ([API Reference](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.2-Release/en/application-dev/reference/apis-arkweb/js-apis-webview.md#configcookiesync14))

- The up, down, left, and right nested scrolling modes are supported. ([API Reference](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.2-Release/en/application-dev/reference/apis-arkweb/ts-basic-components-web.md#nestedscroll11))

- The memory occupied by the **Web** component can be automatically trimmed based on the specified memory pressure level. ([API Reference](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.2-Release/en/application-dev/reference/apis-arkweb/js-apis-webview.md#trimmemorybypressurelevel14))

- Web pages can be saved as PDF files. ([API Reference](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.2-Release/en/application-dev/reference/apis-arkweb/js-apis-webview.md#createpdf14))

- The duration of the scrolling animation can be set. ([scrollTo](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.2-Release/en/application-dev/reference/apis-arkweb/js-apis-webview.md#scrollto), [scrollBy](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.2-Release/en/application-dev/reference/apis-arkweb/js-apis-webview.md#scrollby))

- The scroll bar can be forcibly displayed. ([API Reference](https://gitee.com/openharmony/docs/blob/OpenHarmony-5.0.2-Release/en/application-dev/reference/apis-arkweb/ts-basic-components-web.md#forcedisplayscrollbar14))


## Mapping Relationship

**Table 1** Version mapping of software and tools

| Software/Tool| Version| Remarks| 
| -------- | -------- | -------- |
| OpenHarmony | 5.0.2 Release | NA | 
| Public SDK | Ohos_sdk_public 5.0.2.123 (API Version 14 Release) | This toolkit is intended for application developers and does not contain system APIs that require system permissions. It is provided as standard in DevEco Studio.| 
| (Optional) HUAWEI DevEco Studio| 5.0.2 Release | Recommended for developing OpenHarmony applications| 
| (Optional) HUAWEI DevEco Device Tool| 4.0 Release | Recommended for developing OpenHarmony smart devices| 


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
   curl -s https://gitee.com/oschina/repo/raw/fork_flow/repo-py3 > /usr/local/bin/repo # If you do not have the permission, download the tool to another directory and configure it as an environment variable by running the chmod a+x /usr/local/bin/repo command.
   pip3 install -i https://repo.huaweicloud.com/repository/pypi/simple requests
   ```


### Acquiring Source Code Using the repo Tool

**Method 1 (recommended)**

Use the **repo** tool to download the source code over SSH. (You must have an SSH public key for access to Gitee.)

- Obtain the source code from the version branch. You can obtain the latest source code of the version branch, which includes the code that has been incorporated into the branch up until the time you run the following commands:
   ```
   repo init -u git@gitee.com:openharmony/manifest.git -b OpenHarmony-5.0.2-Release --no-repo-verify
   repo sync -c
   repo forall -c 'git lfs pull'
   ```
   
- Obtain the source code from the version tag, which is the same as that released with the version.
   ```
   repo init -u git@gitee.com:openharmony/manifest.git -b refs/tags/OpenHarmony-v5.0.2-Release --no-repo-verify
   repo sync -c
   repo forall -c 'git lfs pull'
   ```

**Method 2**

Use the **repo** tool to download the source code over HTTPS.

- Obtain the source code from the version branch. You can obtain the latest source code of the version branch, which includes the code that has been incorporated into the branch up until the time you run the following commands:
   ```
   repo init -u https://gitee.com/openharmony/manifest -b OpenHarmony-5.0.2-Release --no-repo-verify
   repo sync -c
   repo forall -c 'git lfs pull'
   ```
   
- Obtain the source code from the version tag, which is the same as that released with the version.
   ```
   repo init -u https://gitee.com/openharmony/manifest -b refs/tags/OpenHarmony-v5.0.2-Release --no-repo-verify
   repo sync -c
   repo forall -c 'git lfs pull'
   ```


### Acquiring Source Code from Mirrors


**Table 2** Mirrors for acquiring source code

| Source Code                               | Version| Mirror                                                | SHA-256 Checksum                                            | Software Package Size|
| --------------------------------------- | ------------ | ------------------------------------------------------------ | ------------------------------------------------------------ | -------- |
| Full code base (for mini, small, and standard systems)       | 5.0.2 Release    | [Download](https://repo.huaweicloud.com/openharmony/os/5.0.2-Release/code-v5.0.2-Release.tar.gz)| [Download](https://repo.huaweicloud.com/openharmony/os/5.0.2-Release/code-v5.0.2-Release.tar.gz.sha256)| 42.5 GB |
| Hi3861 solution (binary)       | 5.0.2 Release    | [Download](https://repo.huaweicloud.com/openharmony/os/5.0.2-Release/hispark_pegasus.tar.gz) | [Download](https://repo.huaweicloud.com/openharmony/os/5.0.2-Release/hispark_pegasus.tar.gz.sha256)| 27.2 MB |
| Hi3516 solution-LiteOS (binary)| 5.0.2 Release    | [Download](https://repo.huaweicloud.com/openharmony/os/5.0.2-Release/hispark_taurus_LiteOS.tar.gz) | [Download](https://repo.huaweicloud.com/openharmony/os/5.0.2-Release/hispark_taurus_LiteOS.tar.gz.sha256) | 328.4 MB |
| Hi3516 solution-Linux (binary) | 5.0.2 Release    | [Download](https://repo.huaweicloud.com/openharmony/os/5.0.2-Release/hispark_taurus_Linux.tar.gz) | [Download](https://repo.huaweicloud.com/openharmony/os/5.0.2-Release/hispark_taurus_Linux.tar.gz.sha256) | 221.2 MB |
| RK3568 standard system solution (binary)       | 5.0.2 Release    | [Download](https://repo.huaweicloud.com/openharmony/os/5.0.2-Release/dayu200_standard_arm32.tar.gz) | [Download](https://repo.huaweicloud.com/openharmony/os/5.0.2-Release/dayu200_standard_arm32.tar.gz.sha256) | 13.1 GB |
| Public SDK package for the standard system (macOS)            | 5.0.2.123 | [Download](https://repo.huaweicloud.com/openharmony/os/5.0.2-Release/ohos-sdk-mac-public.tar.gz) | [Download](https://repo.huaweicloud.com/openharmony/os/5.0.2-Release/ohos-sdk-mac-public.tar.gz.sha256) | 1.3 GB |
| Public SDK package for the standard system (macOS-M1)            | 5.0.2.123  | [Download](https://repo.huaweicloud.com/openharmony/os/5.0.2-Release/L2-SDK-MAC-M1-PUBLIC.tar.gz) | [Download](https://repo.huaweicloud.com/openharmony/os/5.0.2-Release/L2-SDK-MAC-M1-PUBLIC.tar.gz.sha256) | 1.2 GB |
| Public SDK package for the standard system (Windows/Linux)  | 5.0.2.123   | [Download](https://repo.huaweicloud.com/openharmony/os/5.0.2-Release/ohos-sdk-windows_linux-public.tar.gz) | [Download](https://repo.huaweicloud.com/openharmony/os/5.0.2-Release/ohos-sdk-windows_linux-public.tar.gz.sha256) | 4.0 GB |


## Resolved Issues

**Table 3** Resolved issues

| Issue No.| Description| 
| ------- | ------- |
| I9SXZ8 | There is a low probability that app freezing occurs in libark_jsruntime.so due to THREAD_BLOCK_6S in the com.ohos.contacts process.|
| IA6RH6 | There is a high probability that app freezing occurs in libbtframework.z.so due to THREAD_BLOCK_6S in the com.ohos.settings process.|
| IASDWO | The sliding frame rate for accessing the Weibo home page through a browser is lower than the specification baseline.|
| IAZYOO | The RK3568 development board frequently encounters freezing issues during the WuKong comprehensive random pressure testing.|
| IB4L3E | There is a high probability that app freezing occurs in libcamera_framework.z.so due to LIFECYCLE_TIMEOUT in the com.ohos.camera process.|
| IAP85P | There is a low probability that a process with a low startup priority is terminated preferentially, resulting in a system freeze.|
| I9SXZ8 | There is a low probability that app freezing occurs in libark_jsruntime.so due to THREAD_BLOCK_6S in the com.ohos.contacts process.|
| IB36B2 | There is a low probability that a JS crash occurs in the com.ohos.mms process, and the problem stack is identified as close.|


## Unfixed Vulnerabilities

**Table 4** Known issues

| ISSUE | Description| Impact| To Be Resolved By| 
| -------- | -------- | -------- | -------- |
| IANQF3 | There is a high probability that the system restarts during the WuKong pressure test.| This issue leads to the device restarting<br>and is currently not preventable.| 2025-02-15| 
| IBJ6LH | The new security verification mechanism may cause long processing duration for deleting multiple images, affecting user experience.| This issue does not affect the use. No workaround is required.| 2025-02-15| 
| IBBZPS | There is a low probability that a C++ crash occurs in the **OS_IPC_0_1067** thread of the **com.ohos.systemui** process, and the crash stack is **ld-musl-arm.so.1(__libc_free+172)**.| The system is abnormal, and users are unaware of the exception.| 2025-02-15| 
| IBE36X | There is a low probability that system freezing occurs in **render_service** due to **SERVICE_BLOCK**.| A black screen is displayed when the home screen does not respond. After the screen recovers, the home screen is displayed.| 2025-02-15| 
| IBDPFF | There is a low probability that a C++ crash occurs in the **SaOndemand** thread of the **intell_voice_service** process, and the crash stack is **libintell_voice_server.z.so**.| The system is abnormal, and users are unaware of the exception.| 2025-02-15| 
