# Starting a System Application


This topic describes how to start a system application. It also lists the supported redirection capabilities of system applications.

## Methods of Starting a System Application

In addition to the methods described in the preceding topics (for example, using **openLink** to start a specified application or using **startAbilitybyType** to specify an application of the specified type), you can use the following methods to start a system application:

- **Using Picker Components**

    System applications like Camera, Files, and Contacts provide **Picker** components, which allow your application to leverage their common functions without applying for permissions, for example, accessing resource files of users.

    An application starts a system-level **Picker** component (such as **DocumentViewPicker**, **PhotoViewPicker**, or **ContactsPicker**). The user selects files, photos, or contacts on the component, and the application obtains the result returned by the component. For example, an audio player can obtain the path of the audio file selected by the user via **AudioViewPicker**, and play the audio clip.

    > **NOTE**
    >
    > The system-level **Picker** components have been pre-authorized. When using such a component, you can temporarily access the corresponding resources without requesting the permissions. For example, before accessing a user's image, an application normally needs to request user authorization. However, by using **PhotoViewPicker**, the application can directly access the image selected by the user.
    >
    > A system-level **Picker** component is implemented by an independent system process.


- **Using Specific APIs**

    System applications like Settings, Phone, and Calendar provide certain APIs, through which your application can directly redirect users to them.

## Capabilities That Support Redirection to System Applications

### Settings

Currently, the following screens in Settings can be directly opened:
- **Permission setting**: When an application uses [requestPermissionsFromUser()](../reference/apis-ability-kit/js-apis-abilityAccessCtrl.md#requestpermissionsfromuser9) to display a dialog box to request certain permissions from the user and the user rejects the request, the application cannot use this API to open the dialog box again. However, it can call [requestPermissionOnSetting](../reference/apis-ability-kit/js-apis-abilityAccessCtrl.md#requestpermissiononsetting12) to open the permission setting dialog box.

  The following uses the microphone permission as an example to show how to display the permission setting dialog box during [requesting user authorization for the second time](../security/AccessToken/request-user-authorization-second.md). The sample code in this topic applies to all permissions in the [application's permission groups](../security/AccessToken/app-permission-group-list.md). You only need to replace the corresponding permission names. The following are some common scenarios:
  
    - Displaying the location permission setting dialog box
    - Displaying the camera permission setting dialog box
    - Displaying the image and video permission setting dialog box
    - Displaying the music and audio permission setting dialog box
    - Displaying the contacts permission setting dialog box
    - Displaying the calendar permission setting dialog box


- **Notification management**: When an application uses [requestEnableNotification()](../reference/apis-notification-kit/js-apis-notificationManager.md#notificationmanagerrequestenablenotification10) to display a dialog box for notification authorization and the user rejects the authorization, the application cannot use this API to open the dialog box again. However, it can call [openNotificationSettings()](../reference/apis-notification-kit/js-apis-notificationManager.md#notificationmanageropennotificationsettings13) to open the notification management dialog box.



<!--RP1-->
<!--RP1End-->


### Phone
[Telephony Kit](../telephony/telephony-overview.md) provides [makeCall()](../reference/apis-telephony-kit/js-apis-call.md#callmakecall7), which allows users to jump to the dialing screen, where the number to dial is displayed.

### Calendar
[Calendar Kit](../calendarmanager/calendarmanager-overview.md) provides [addEvent](../reference/apis-calendar-kit/js-apis-calendarManager.md#addevent), which allows users to create a schedule.



### Contacts
[Contacts Kit](../contacts/contacts-intro.md) provides the Contacts Picker, which is used to start the Contacts application and read contact data. For details, see [Contact Selection with Picker](../contacts/contacts-intro.md#contact-selection).

<!--RP2-->
### Camera

[Camera Kit](../media/camera/camera-overview.md) provides the Camera Picker for photo capture and video recording. For details, see [Using the Camera Picker (ArkTS)](media/camera/camera-picker.md).
<!--RP2End-->

### Files
[Core File Kit](../file-management/core-file-kit-intro.md) provides the DocumentViewPicker and AudioViewPicker.
- The DocumentViewPicker is used to access and save documents in the public directory. For details, see [Selecting Documents](../file-management/select-user-file.md#selecting-documents) and [Saving Documents](../file-management/save-user-file.md#saving-documents).
- The AudioViewPicker is used to access and save audio files in the public directory. For details, see [Selecting Audio Clips](../file-management/select-user-file.md#selecting-audio-clips) and [Saving Audio Clips](../file-management/save-user-file.md#saving-audio-clips).

### Gallery (Media Library)
[Media Library Kit](../media/medialibrary/photoAccessHelper-overview.md) provides the PhotoViewPicker for accessing and saving images or video files in the public directory. For details, see [Selecting Media Assets Using Picker](../media/medialibrary/photoAccessHelper-photoviewpicker.md) and [Creating a Media Asset Using SaveButton](../media/medialibrary/photoAccessHelper-savebutton.md).

<!--RP3-->
<!--RP3End-->
