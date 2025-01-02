# 文件子系统Changelog

## cl.file.1 @ohos.file.picker PhotoViewMIMETypes、PhotoSelectOptions、PhotoSelectResult、PhotoSaveOptions、PhotoViewPicker及其内部select和save接口废弃

**访问级别**

公开接口。

**废弃原因**

为了满足PhotoViewPicker后续演进，@ohos.file.picker文件内PhotoViewPicker相关接口废弃。

**废弃影响**

该变更为非兼容性变更。使用PhotoViewMIMETypes、PhotoSelectOptions、PhotoSelectResult、PhotoSaveOptions、PhotoViewPicker及其内部select和save接口会有废弃提示。建议迁移使用替代接口。

**起始 API Level**

9

**废弃发生的版本**

从OpenHarmony SDK 5.0.0.35开始。

**废弃的接口/组件**

|            接口声明            |               废弃说明               |           代替接口            |
| :----------------------------: | :----------------------------------: | :---------------------------: |
| picker.PhotoViewMIMETypes | 使用photoAccessHelper.PhotoViewMIMETypes替换 | photoAccessHelper.PhotoViewMIMETypes |
| picker.PhotoSelectOptions | 使用photoAccessHelper.PhotoSelectOptions替换 | photoAccessHelper.PhotoSelectOptions |
| picker.PhotoSelectResult | 使用photoAccessHelper.PhotoSelectResult替换 | photoAccessHelper.PhotoSelectResult |
| picker.PhotoSaveOptions | 使用photoAccessHelper.PhotoSaveOptions替换 | photoAccessHelper.PhotoSaveOptions |
| picker.PhotoViewPicker | 使用photoAccessHelper.PhotoViewPicker替换 | photoAccessHelper.PhotoViewPicker |
| picker.PhotoViewPicker#select(option?: PhotoSelectOptions): Promise<PhotoSelectResult> | 使用photoAccessHelper中替代接口替换 | photoAccessHelper.PhotoViewPicker#select(option?: PhotoSelectOptions): Promise<PhotoSelectResult> |
| picker.PhotoViewPicker#select(option: PhotoSelectOptions, callback: AsyncCallback<PhotoSelectResult>): void | 使用photoAccessHelper中替代接口替换 | photoAccessHelper.PhotoViewPicker#select(option: PhotoSelectOptions, callback: AsyncCallback<PhotoSelectResult>): void |
| picker.PhotoViewPicker#select(callback: AsyncCallback<PhotoSelectResult>): void | 使用photoAccessHelper中替代接口替换 | photoAccessHelper.PhotoViewPicker#select(callback: AsyncCallback<PhotoSelectResult>): void |
| picker.PhotoViewPicker#save(option?: PhotoSaveOptions): Promise<Array<string>> | 使用SaveButton替换 | SaveButton |
| picker.PhotoViewPicker#save(option: PhotoSaveOptions, callback: AsyncCallback<Array<string>>): void | 使用SaveButton替换 | SaveButton |
| picker.PhotoViewPicker#save(callback: AsyncCallback<Array<string>>): void | 使用SaveButton替换 | SaveButton |


**适配指导**

开发者需将使用@ohos.file.picker模块废弃接口的地方适配修改为@ohos.file.photoAccessHelper模块以及save_button模块对应接口。

新接口使用指南请参考 [photoAccessHelper 使用指导](../../../application-dev/reference/apis-media-library-kit/js-apis-photoAccessHelper.md)和[SaveButton使用指导](../../../application-dev/reference/apis-arkui/arkui-ts/ts-security-components-savebutton.md)。