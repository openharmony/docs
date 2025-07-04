# Multimedia Changelog

## cl.multimedia.1 APIs of @ohos.multimedia.medialibrary Changed

**Access Level**

Public API

**Reason for Change**

When dynamic photos are set to autoplay, they zoom in to 1.1 times their original size. This zoom effect is particularly noticeable and somewhat jarring when users swipe left or right to navigate through dynamic photos, causing a flickering and shaking effect. To enhance user experience, dynamic photos will no longer zoom in when set to autoplay.

**Impact of the Change**

This change requires application adaptation.

The default UX behavior of the **autoPlay** API in the @ohos.multimedia.medialibrary module has been updated.

Before change: Dynamic photos zoom in to 1.1 times their size when set to autoplay.

After change: Dynamic photos will no longer zoom in when set to autoplay.

**Start API Level**

13

**Change Since**

OpenHarmony SDK 5.0.0.46

**Key API/Component Changes**

API **autoPlay** of the @ohos.multimedia.medialibrary module

**Adaptation Guide**

No adaptation is required.
