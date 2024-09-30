# 拉起系统应用


本章节介绍拉起系统应用的方式，以及支持跳转系统应用的能力清单。

## 拉起系统应用的方式

拉起系统应用除了采用使用前面章节介绍的方式（比如使用openlink拉起指定应用、使用startAbilitybyType指定类型的应用），还可以采用如下方式。

- **使用系统Picker组件**

    相机、文件管理、联系人等系统应用提供了系统Picker组件，支持开发者无需申请权限、即可使用系统应用的一些常用功能，比如访问用户的资源文件。

    应用拉起系统Picker组件（文件选择器、照片选择器、联系人选择器等）后，由用户在Picker上选择对应的文件、照片、联系人等资源，应用即可获取到Picker的返回结果。例如，一个音频播放器应用可以通过AudioViewPicker让用户选择音频文件，然后获取所选的音频文件路径进行播放。

    > **说明：**
    > 由于系统Picker已经获取了对应权限的预授权，开发者使用系统Picker时，无需再次申请权限也可临时受限访问对应的资源。例如，当应用需要读取用户图片时，可通过使用照片Picker，在用户选择所需要的图片资源后，直接返回该图片资源，而不需要授予应用读取图片文件的权限。
    >
    > 系统Picker由系统独立进程实现。
   

- **使用特定接口**

    设置、电话、日历等应用提供了一些接口，通过这些接口可以直接跳转系统应用。

## 支持跳转系统应用的能力清单

### 设置

当前支持直接拉起设置应用中如下页面，未列出的暂不支持。
- 权限设置页面：[Ability Kit](abilitykit-overview.md)提供[requestPermissionOnSetting](../reference/apis-ability-kit/js-apis-abilityAccessCtrl.md#requestpermissiononsetting12)接口，支持拉起权限设置页面。详见[二次向用户申请授权](../security/AccessToken/request-user-authorization-second.md)。
- 通知管理页面：[Notification Kit](../notification/notification-overview.md)提供[openNotificationSettings()](../reference/apis-notification-kit/js-apis-notificationManager.md#notificationmanageropennotificationsettings13)接口，支持拉起通知管理页面。


<!--RP1-->
<!--RP1End-->


### 电话
[Telephony Kit](../telephony/telephony-overview.md)提供[makeCall()](../reference/apis-telephony-kit/js-apis-call.md#callmakecall7)接口，支持跳转到拨号界面，并显示待拨出的号码。

### 日历
[Calendar Kit](../calendarmanager/calendarmanager-overview.md)提供[addEvent](../reference/apis-calendar-kit/js-apis-calendarManager.md#addevent)接口，用于创建日程。



### 联系人
[Contacts Kit](../contacts/contacts-intro.md)提供联系人Picker（Contacts Picker），用于拉起联系人应用，读取联系人数据人。详见[选择联系人](../contacts/contacts-intro.md#选择联系人)。

<!--RP2-->
### 相机
[Camera Kit](../media/camera/camera-overview.md)提供了相机Picker （Camera Picker），用于拍照、录制。详见[cameraPicker](../reference/apis-camera-kit/js-apis-cameraPicker.md)。
<!--RP2End-->

### 文件管理
[Core File Kit](../file-management/core-file-kit-intro.md)提供了文件Picker和音频Picker。
- 文件Picker（DocumentViewPicker）：用于访问、保存公共目录中文档类文件。详见[选择文档类文件](../file-management/select-user-file.md#选择文档类文件)、[保存文档类文件](../file-management/save-user-file.md#保存文档类文件)。
- 音频Picker（AudioViewPicker）：用于访问、保存公共目录的图片或视频文件。详见[选择音频类文件](../file-management/select-user-file.md#选择音频类文件)、[保存音频类文件](../file-management/save-user-file.md#保存音频类文件)。

### 图库（媒体库）
[Media Library Kit](../media/medialibrary/photoAccessHelper-overview.md)提供了照片Picker（PhotoViewPicker），用于访问、保存公共目录的图片或视频文件。详见[选择媒体库资源](../media/medialibrary/photoAccessHelper-photoviewpicker.md) 、[创建媒体资源](../media/medialibrary/photoAccessHelper-savebutton.md)。







