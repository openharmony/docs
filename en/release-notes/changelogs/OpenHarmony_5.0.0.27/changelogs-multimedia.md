# Multimedia Changelog

## cl.multimedia.1 APIs of @ohos.multimedia.movingphotoview Changed

**Access Level**

System and public APIs

**Reason for Change**

This change is caused by the SysCap change of MovingphotoView, which is a Media Library capability component developed on the ArkUI framework. Specifically, the ownership of the MovingPhotoView component is changed from ArkUI to Media Library Kit, and SysCap of MovingPhotoView is changed from SystemCapability.ArkUI.ArkUI.Full to SystemCapability.FileManagement.PhotoAccessHelper.Core.

**Change Impact**

This change is a non-compatible change. Only SysCap on which the APIs depend is adjusted, and the API usage is not affected.

Before change:

SysCap of the MovingPhotoView component must be SystemCapability.ArkUI.ArkUI.Full. To determine whether a device supports the MovingPhotoView component, use **canIUse("SystemCapability.ArkUI.ArkUI.Full")**.

After change:

SysCap of the MovingPhotoView component must be SystemCapability.FileManagement.PhotoAccessHelper.Core. To determine whether a device supports the MovingPhotoView component, use **canIUse("SystemCapability.FileManagement.PhotoAccessHelper.Core")**.

**Start API Level**

12

**Change Since**

OpenHarmony SDK 5.0.0.27

**Key API/Component Changes**

All APIs of the @ohos.multimedia.movingphotoview module.

**Adaptation Guide**

The device-define of the SDK contains both SystemCapability.ArkUI.ArkUI.Full and SystemCapability.FileManagement.PhotoAccessHelper.Core, or does not contain either of them. Generally, the code involving the MovingPhotoView component does not need to be adapted. If the **canIUse()** API is used in your code to check whether the MovingPhotoView component is supported, you need to change SysCap passed in by the API.
