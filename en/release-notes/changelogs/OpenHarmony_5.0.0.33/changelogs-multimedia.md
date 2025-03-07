# Multimedia Changelog

## cl.multimedia.1 APIs of @ohos.multimedia.medialibrary Changed

**Access Level**

System and public APIs

**Reason for Change**

According to the requirements of the Ministry of Industry and Information Technology (MIIT) on the capability of recording application call behavior, the mediaLibrary interface capability must be changed.

**Change Impact**

This change is a non-compatible change.

All APIs provided by the @ohos.multimedia.medialibrary module will be deleted from the SDK and cannot be used by new applications. An error will be reported during compilation of historical code projects.

Later, for released applications, the original features provided by these APIs cannot be used, and error code 8000001 will be reported when any of them is called.

**Start API Level**

6

**Change Since**

OpenHarmony SDK 5.0.0.33

**Key API/Component Changes**

All APIs of the @ohos.multimedia.medialibrary module.

**Adaptation Guide**

Do not use the @ohos.multimedia.medialibrary module. Instead, use the @ohos.file.photoAccessHelper module to implement related features.

For details about how to use the new APIs, see [Media Library Kit User Guide](../../../application-dev/media/medialibrary/photoAccessHelper-overview.md).
