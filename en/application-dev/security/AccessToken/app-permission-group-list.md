# Application Permission Groups

<!--Kit: Ability Kit-->
<!--Subsystem: Security-->
<!--Owner: @xia-bubai-->
<!--SE: @linshuqing; @hehehe-li-->
<!--TSE: @leiyuqian-->

## Usage Guidelines

- It will be helpful if you understand [permission groups and permissions](app-permission-mgmt-overview.md#permission-groups-and-permissions) before requesting permission groups for your application.

- A permission group is a logical grouping of related permissions. When a permission is requested, the members of the group are presented together in the user interface, making it easier for the user to manage permissions. If the user grants the permission, all the permissions in the permission group will be granted in a unified manner. For security purposes, the Location, Contacts, Call Logs, Phone, Messaging, and Calendar permission groups do not support unified authorization.

  The following uses the Location and Camera permission groups as an example.

  - When an application requests only the ohos.permission.APPROXIMATELY_LOCATION permission (belong to the Location permission group), a dialog box containing only the requested permission will be displayed to request user authorization.
  - When an application requests the ohos.permission.APPROXIMATELY_LOCATION and ohos.permission.LOCATION permissions (belonging to the Location permission group), a dialog box containing only the requested permissions will be displayed to request user authorization.
  - When an application requests ohos.permission.APPROXIMATELY_LOCATION (belonging to the Location permission group) and ohos.permission.CAMERA (belonging to the Camera permission group), two dialog boxes will be displayed to request the location and camera permissions, respectively.

- The following lists the permission groups supported by the system. For details about the permissions, see [Open user_grant Permissions](permissions-for-all-user.md).

## Location <!--Del-->Information<!--DelEnd-->

- [ohos.permission.LOCATION_IN_BACKGROUND](permissions-for-all-user.md#ohospermissionlocation_in_background)

- [ohos.permission.LOCATION](permissions-for-all-user.md#ohospermissionlocation)

- [ohos.permission.APPROXIMATELY_LOCATION](permissions-for-all-user.md#ohospermissionapproximately_location)

## Camera

- [ohos.permission.CAMERA](permissions-for-all-user.md#ohospermissioncamera)

## Microphone

- [ohos.permission.MICROPHONE](permissions-for-all-user.md#ohospermissionmicrophone)

## Contacts

- [ohos.permission.READ_CONTACTS](restricted-permissions.md#ohospermissionread_contacts)

- [ohos.permission.WRITE_CONTACTS](restricted-permissions.md#ohospermissionwrite_contacts)

## Calendar

- [ohos.permission.READ_CALENDAR](permissions-for-all-user.md#ohospermissionread_calendar)
 
- [ohos.permission.WRITE_CALENDAR](permissions-for-all-user.md#ohospermissionwrite_calendar)
 
<!--Del-->
- [ohos.permission.READ_WHOLE_CALENDAR](permissions-for-system-apps-user.md#ohospermissionread_whole_calendar)

- [ohos.permission.WRITE_WHOLE_CALENDAR](permissions-for-system-apps-user.md#ohospermissionwrite_whole_calendar)
<!--DelEnd-->

<!--RP1-->
## Fitness

- [ohos.permission.ACTIVITY_MOTION](permissions-for-all-user.md#ohospermissionactivity_motion)

## Body Sensors

- [ohos.permission.READ_HEALTH_DATA](permissions-for-all-user.md#ohospermissionread_health_data)
<!--RP1End-->

## Images and Videos

- [ohos.permission.WRITE_IMAGEVIDEO](restricted-permissions.md#ohospermissionwrite_imagevideo)

- [ohos.permission.READ_IMAGEVIDEO](restricted-permissions.md#ohospermissionread_imagevideo)

- [ohos.permission.MEDIA_LOCATION](permissions-for-all-user.md#ohospermissionmedia_location)

- [ohos.permission.SHORT_TERM_WRITE_IMAGEVIDEO](restricted-permissions.md#ohospermissionshort_term_write_imagevideo)

## Music and Audio

- [ohos.permission.WRITE_AUDIO](restricted-permissions.md#ohospermissionwrite_audio)

- [ohos.permission.READ_AUDIO](restricted-permissions.md#ohospermissionread_audio)

<!--RP2-->
## Ad Tracking

- [ohos.permission.APP_TRACKING_CONSENT](permissions-for-all-user.md#ohospermissionapp_tracking_consent)
<!--RP2End-->

<!--Del-->
## Installed Bundle List

- [ohos.permission.GET_INSTALLED_BUNDLE_LIST](permissions-for-system-apps-user.md#ohospermissionget_installed_bundle_list)
<!--DelEnd-->

<!--RP3-->
## Multi-device Collaboration

- [ohos.permission.DISTRIBUTED_DATASYNC](permissions-for-all-user.md#ohospermissiondistributed_datasync)

## Bluetooth

- [ohos.permission.ACCESS_BLUETOOTH](permissions-for-all-user.md#ohospermissionaccess_bluetooth)

## NearLink

- [ohos.permission.ACCESS_NEARLINK](permissions-for-all-user.md#ohospermissionaccess_nearlink)
<!--RP3End-->

<!--Del-->
## Phone

- [ohos.permission.ANSWER_CALL](permissions-for-system-apps-user.md#ohospermissionanswer_call)

- [ohos.permission.MANAGE_VOICEMAIL](permissions-for-system-apps-user.md#ohospermissionmanage_voicemail)

## Call Logs

- [ohos.permission.READ_CALL_LOG](permissions-for-system-apps-user.md#ohospermissionread_call_log)

- [ohos.permission.WRITE_CALL_LOG](permissions-for-system-apps-user.md#ohospermissionwrite_call_log)

## Messaging

- [ohos.permission.READ_CELL_MESSAGES](permissions-for-system-apps-user.md#ohospermissionread_cell_messages)

- [ohos.permission.READ_MESSAGES](permissions-for-system-apps-user.md#ohospermissionread_messages)

- [ohos.permission.RECEIVE_MMS](permissions-for-system-apps-user.md#ohospermissionreceive_mms)

- [ohos.permission.RECEIVE_SMS](permissions-for-system-apps-user.md#ohospermissionreceive_sms)

- [ohos.permission.RECEIVE_WAP_MESSAGES](permissions-for-system-apps-user.md#ohospermissionreceive_wap_messages)

- [ohos.permission.SEND_MESSAGES](permissions-for-system-apps-user.md#ohospermissionsend_messages)
<!--DelEnd-->

## Pasteboard

- [ohos.permission.READ_PASTEBOARD](restricted-permissions.md#ohospermissionread_pasteboard)

## Screenshots

- [ohos.permission.CUSTOM_SCREEN_CAPTURE](permissions-for-all-user.md#ohospermissioncustom_screen_capture)

## Directory

> **NOTE**
> <br>The permissions are available only to 2-in-1 device applications.

- [ohos.permission.READ_WRITE_DOWNLOAD_DIRECTORY](permissions-for-all-user.md#ohospermissionread_write_download_directory)

- [ohos.permission.READ_WRITE_DESKTOP_DIRECTORY](restricted-permissions.md#ohospermissionread_write_desktop_directory)
- [ohos.permission.READ_WRITE_DOCUMENTS_DIRECTORY](permissions-for-all-user.md#ohospermissionread_write_documents_directory)

## Files<sup>(deprecated)</sup>

> **NOTE**
> This permission group is deprecated since API version 12.

<!--Del-->
- ohos.permission.READ_DOCUMENT

- ohos.permission.WRITE_DOCUMENT
<!--DelEnd-->
- ohos.permission.READ_MEDIA

- ohos.permission.WRITE_MEDIA

**Alternative solution**:

- To read or write images or videos in the media library:

  - (Recommended) Use [Picker](../../media/medialibrary/photoAccessHelper-photoviewpicker.md) to read images and videos in the media library, and use the [SaveButton/authorization pop-up window](../../media/medialibrary/photoAccessHelper-savebutton.md) to save images and videos in the media library. This solution is recommended because the application does not need any permission.
  - Request the restricted permission [ohos.permission.READ_IMAGEVIDEO](restricted-permissions.md#ohospermissionread_imagevideo) or [ohos.permission.WRITE_IMAGEVIDEO](restricted-permissions.md#ohospermissionwrite_imagevideo).

- To read audio clips in the media library:

  Request the restricted permission [ohos.permission.READ_AUDIO](restricted-permissions.md#ohospermissionread_audio) or [ohos.permission.WRITE_AUDIO](restricted-permissions.md#ohospermissionwrite_audio).

- To read documents in **Files**:

  Use the file Picker to read documents in **Files**. For details, see [Selecting Documents](../../file-management/select-user-file.md#selecting-documents) and [Saving Documents](../../file-management/save-user-file.md#saving-documents).
