# Display Management Overview
<!--Kit: ArkUI-->
<!--Subsystem: Window-->
<!--Owner: @oh_wangxk; @logn-->
<!--Designer: @hejunfei1991-->
<!--Tester: @qinliwen0417-->
<!--Adviser: @ge-yafang-->

Display management is centered around the oversight of a device's displays, which includes physical, virtual, and foldable displays. It involves managing their properties and serving as a broadcaster to relay monitored information to services that have subscribed to display information.

Display management includes the following capabilities:

- Obtaining the display properties, such as resolution, physical pixel density, and dimensions.
- Listening for various display events, including rotation, resolution changes, refresh rate changes, and folding state changes.
- Creating and using virtual screens. This capability is available only for system applications.

For details about how to obtain display properties and listen for status changes, see [Using OH_DisplayManager to Obtain Basic Display Information and Listen for Status Changes (C/C++)](native-display-manager.md) and [Using Display to Obtain Display Properties and Listen for Status Changes (ArkTS)](screenProperty-guideline.md).<!--Del--> For details about how to use virtual screens, see [Creating and Using a Virtual Screen (ArkTS) (for System Applications Only)](virtualScreen-guideline.md).<!--DelEnd-->

## Constraints

- The Display and Screen APIs must be used in the system that supports the SystemCapability.Window.SessionManager capability. For details, see <!--RP1-->[SystemCapability](../reference/syscap.md).<!--RP1End-->
- In multi-display implementation, the Screen API is available only for system applications, and certain APIs require the ohos.permission.CAPTURE_SCREEN permission.
