# File Subsystem Changelog

## cl.file.1 Deprecation of @ohos.file.picker PhotoViewMIMETypes, PhotoSelectOptions, PhotoSelectResult, PhotoSaveOptions, and PhotoViewPicker and its select() and save()

**Access Level**

Public API

**Reason for Change**

To ensure evolution of **PhotoViewPicker**, the PhotoViewPicker APIs of @ohos.file.picker are deprecated.

**Change Impact**

This change is a non-compatible change. When **PhotoViewMIMETypes**, **PhotoSelectOptions**, **PhotoSelectResult**, **PhotoSaveOptions**, and **PhotoViewPicker** and its **select()** and **save()** are used, a message is displayed, indicating that these APIs are deprecated. You are advised to use the substitute APIs.

**Start API Level**

9

**Change Since**

OpenHarmony SDK 5.0.0.35

**Deprecated APIs/Components**

|            API           |               Description              |           Substitute API           |
| :---------------------------- | :---------------------------------- | :--------------------------- |
| picker.PhotoViewMIMETypes | Use **photoAccessHelper.PhotoViewMIMETypes** instead.| photoAccessHelper.PhotoViewMIMETypes |
| picker.PhotoSelectOptions | Use **photoAccessHelper.PhotoSelectOptions** instead.| photoAccessHelper.PhotoSelectOptions |
| picker.PhotoSelectResult | Use **photoAccessHelper.PhotoSelectResult** instead.| photoAccessHelper.PhotoSelectResult |
| picker.PhotoSaveOptions | Use **photoAccessHelper.PhotoSaveOptions** instead.| photoAccessHelper.PhotoSaveOptions |
| picker.PhotoViewPicker | Use **photoAccessHelper.PhotoViewPicker** instead.| photoAccessHelper.PhotoViewPicker |
| picker.PhotoViewPicker#select(option?: PhotoSelectOptions): Promise<\PhotoSelectResult> | Use the substitute API of **photoAccessHelper**.| photoAccessHelper.PhotoViewPicker#select(option?: PhotoSelectOptions): Promise<\PhotoSelectResult> |
| picker.PhotoViewPicker#select(option: PhotoSelectOptions, callback: AsyncCallback<\PhotoSelectResult>): void | Use the substitute API of **photoAccessHelper**.| photoAccessHelper.PhotoViewPicker#select(option: PhotoSelectOptions, callback: AsyncCallback<\PhotoSelectResult>): void |
| picker.PhotoViewPicker#select(callback: AsyncCallback<\PhotoSelectResult>): void | Use the substitute API of **photoAccessHelper**.| photoAccessHelper.PhotoViewPicker#select(callback: AsyncCallback<\PhotoSelectResult>): void |
| picker.PhotoViewPicker#save(option?: PhotoSaveOptions): Promise<Array<\string>> | Use **SaveButton** instead.| SaveButton |
| picker.PhotoViewPicker#save(option: PhotoSaveOptions, callback: AsyncCallback<Array<\string>>): void | Use **SaveButton** instead.| SaveButton |
| picker.PhotoViewPicker#save(callback: AsyncCallback<Array<\string>>): void | Use **SaveButton** instead.| SaveButton |


**Adaptation Guide**

Use the substitute APIs of @ohos.file.photoAccessHelper and **SaveButton** to replace the deprecated APIs of @ohos.file.picker.

For details about how to use the new APIs, see [@ohos.file.photoAccessHelper (Album Management)](../../../application-dev/reference/apis-media-library-kit/js-apis-photoAccessHelper.md) and [SaveButton](../../../application-dev/reference/apis-arkui/arkui-ts/ts-security-components-savebutton.md).
