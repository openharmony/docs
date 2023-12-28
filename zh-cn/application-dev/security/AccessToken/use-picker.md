# 使用系统Picker

Picker由系统独立进程实现，应用可以通过拉起Picker组件，用户在Picker上选择对应的资源（如图片、文档等），应用可以获取Picker返回的结果。

例如，一个音频播放器应用可以通过AudioViewPicker让用户选择音频文件，然后获取所选的音频文件路径进行播放。

目前支持的Picker组件有：

- [音频Picker（AudioViewPicker）](#音频picker)：选择、保存音频文件

- [文件Picker（DocumentViewPicker）](#文件picker)：选择、保存文档文件

- [照片Picker（PhotoViewPicker）](#照片picker)：选择、保存图片文件

- [联系人Picker（Contacts Picker）](#contacts-picker)：选择联系人

## 音频Picker

使用音频Picker（AudioViewPicker）可访问、保存用户公共目录的音频文件。

- 在应用需要申请权限**ohos.permission.READ_AUDIO**以访问用户公共目录的音频文件时，可以使用FilePicker中的AudioViewPicker替代，使用方式请参考：[选择音频类文件](../../file-management/select-user-file.md#选择音频类文件)。

- 在应用需要申请权限**ohos.permission.WRITE_AUDIO**以修改用户公共目录的音频文件时，可以使用FilePicker中的AudioViewPicker替代，使用方式请参考：[保存音频类文件](../../file-management/save-user-file.md#保存音频类文件)。

## 文件Picker

使用文件Picker（DocumentViewPicker）可访问、保存公共目录中非媒体类型的文件。

- 在应用需要申请权限**ohos.permission.READ_DOCUMENT**以访问用户公共目录中非媒体类型的文件时，可以使用FilePicker中的DocumentViewPicker替代，使用方式请参考：[选择文档类文件](../../file-management/select-user-file.md#选择文档类文件)。

- 在应用需要申请权限**ohos.permission.WRITE_DOCUMENT**以修改用户公共目录中非媒体类型的文件时，可以使用FilePicker中的DocumentViewPicker替代，使用方式请参考：[保存文档类文件](../../file-management/save-user-file.md#保存文档类文件)。


## 照片Picker

使用照片Picker（PhotoViewPicker）可访问、保存公共目录的图片或视频文件。

- 在应用需要申请权限**ohos.permission.READ_IMAGEVIDEO**以访问用户公共目录的图片或视频文件时，可以使用FilePicker中的PhotoViewPicker替代，使用方式请参考：[选择图片或视频类文件](../../file-management/select-user-file.md#选择图片或视频类文件)。

- 在应用需要申请权限**ohos.permission.WRITE_IMAGEVIDEO**以修改用户公共目录的图片或视频文件时，可以使用FilePicker中的PhotoViewPicker替代，使用方式请参考：[保存图片或视频类文件](../../file-management/select-user-file.md#保存图片或视频类文件)。


## 联系人Picker

使用联系人Picker（Contacts Picker）可读取、写入联系人数据。

- 在应用需要申请权限**ohos.permission.READ_CONTACTS**以读取联系人数据时，可以使用Contacts Picker替代，使用方式请参考：[contact.selectContacts](../../reference/apis/js-apis-contact.md##contactselectcontacts10)。
