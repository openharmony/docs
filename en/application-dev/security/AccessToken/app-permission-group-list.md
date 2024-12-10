# Application Permission Groups

## Usage Guidelines

- It will be helpful if you understand [permission groups and permissions](app-permission-mgmt-overview.md#permission-groups-and-permissions) before requesting permission groups for your application.

- A permission group is a logical grouping of related permissions. When a permission is requested, the members of the group are presented together in the user interface, making it easier for the user to manage permissions. If the user grants the permission, all the permissions in the permission group will be granted in a unified manner. For security purposes, the Location, Contacts, Call Logs, Phone, Messaging, and Calendar permission groups do not support unified authorization.
  
  The following uses the Location and Camera permission groups as an example.

  - When an application requests only the ohos.permission.APPROXIMATELY_LOCATION permission (belong to the Location permission group), a dialog box containing only the requested permission will be displayed to request user authorization.
  - When an application requests the ohos.permission.APPROXIMATELY_LOCATION and ohos.permission.LOCATION permissions (belonging to the Location permission group), a dialog box containing only the requested permissions will be displayed to request user authorization.
  - When an app requests ohos.permission.APPROXIMATELY_LOCATION (belonging to the Location permission group) and ohos.permission.CAMERA (belonging to the Camera permission group), two dialog boxes will be displayed to request the location and camera permissions, respectively.

- The following lists the permission groups supported by the system. For details about the permissions, see [Permissions for All Applications](permissions-for-all.md).

<!--RP1-->

## Location

- [ohos.permission.LOCATION_IN_BACKGROUND](permissions-for-all.md#ohospermissionlocation_in_background)

- [ohos.permission.LOCATION](permissions-for-all.md#ohospermissionlocation)

- [ohos.permission.APPROXIMATELY_LOCATION](permissions-for-all.md#ohospermissionapproximately_location)

## Camera

- [ohos.permission.CAMERA](permissions-for-all.md#ohospermissioncamera)

## Microphone

- [ohos.permission.MICROPHONE](permissions-for-all.md#ohospermissionmicrophone)

## Contacts

- [ohos.permission.READ_CONTACTS](permissions-for-system-apps.md#ohospermissionread_contacts)

- [ohos.permission.WRITE_CONTACTS](permissions-for-system-apps.md#ohospermissionwrite_contacts)

## Calendar

- [ohos.permission.READ_CALENDAR](permissions-for-all.md#ohospermissionread_calendar)

- [ohos.permission.WRITE_CALENDAR](permissions-for-all.md#ohospermissionwrite_calendar)

- [ohos.permission.READ_WHOLE_CALENDAR](permissions-for-system-apps.md#ohospermissionread_whole_calendar)

- [ohos.permission.WRITE_WHOLE_CALENDAR](permissions-for-system-apps.md#ohospermissionwrite_whole_calendar)

## Fitness

- [ohos.permission.ACTIVITY_MOTION](permissions-for-all.md#ohospermissionactivity_motion)

## Body Sensors

- [ohos.permission.READ_HEALTH_DATA](permissions-for-all.md#ohospermissionread_health_data)

## Images and Videos

- [ohos.permission.WRITE_IMAGEVIDEO](permissions-for-system-apps.md#ohospermissionwrite_imagevideo)

- [ohos.permission.READ_IMAGEVIDEO](permissions-for-system-apps.md#ohospermissionread_imagevideo)

- [ohos.permission.MEDIA_LOCATION](permissions-for-all.md#ohospermissionmedia_location)

- [ohos.permission.SHORT_TERM_WRITE_IMAGEVIDEO](permissions-for-system-apps.md#ohospermissionshort_term_write_imagevideo)

## Music and Audio

- [ohos.permission.WRITE_AUDIO](permissions-for-system-apps.md#ohospermissionwrite_audio)

- [ohos.permission.READ_AUDIO](permissions-for-system-apps.md#ohospermissionread_audio)

## Ad Tracking

- [ohos.permission.APP_TRACKING_CONSENT](permissions-for-all.md#ohospermissionapp_tracking_consent)

## Installed Bundle List

- [ohos.permission.GET_INSTALLED_BUNDLE_LIST](permissions-for-system-apps.md#ohospermissionget_installed_bundle_list)

## Multi-device Collaboration

- [ohos.permission.DISTRIBUTED_DATASYNC](permissions-for-all.md#ohospermissiondistributed_datasync)

## Bluetooth

- [ohos.permission.ACCESS_BLUETOOTH](permissions-for-all.md#ohospermissionaccess_bluetooth)

## Phone

- [ohos.permission.ANSWER_CALL](permissions-for-system-apps.md#ohospermissionanswer_call)

- [ohos.permission.MANAGE_VOICEMAIL](permissions-for-system-apps.md#ohospermissionmanage_voicemail)

## Call Logs

- [ohos.permission.READ_CALL_LOG](permissions-for-system-apps.md#ohospermissionread_call_log)

- [ohos.permission.WRITE_CALL_LOG](permissions-for-system-apps.md#ohospermissionwrite_call_log)

## Messaging

- [ohos.permission.READ_CELL_MESSAGES](permissions-for-system-apps.md#ohospermissionread_cell_messages)

- [ohos.permission.READ_MESSAGES](permissions-for-system-apps.md#ohospermissionread_messages)

- [ohos.permission.RECEIVE_MMS](permissions-for-system-apps.md#ohospermissionreceive_mms)

- [ohos.permission.RECEIVE_SMS](permissions-for-system-apps.md#ohospermissionreceive_sms)

- [ohos.permission.RECEIVE_WAP_MESSAGES](permissions-for-system-apps.md#ohospermissionreceive_wap_messages)

- [ohos.permission.SEND_MESSAGES](permissions-for-system-apps.md#ohospermissionsend_messages)

## Pasteboard

- [ohos.permission.READ_PASTEBOARD](permissions-for-system-apps.md#ohospermissionread_pasteboard)

## Directory

- [ohos.permission.READ_WRITE_DOWNLOAD_DIRECTORY](permissions-for-all.md#ohospermissionread_write_download_directory)

- [ohos.permission.READ_WRITE_DESKTOP_DIRECTORY](permissions-for-system-apps.md#ohospermissionread_write_desktop_directory)

- [ohos.permission.READ_WRITE_DOCUMENTS_DIRECTORY](permissions-for-all.md#ohospermissionread_write_documents_directory)

## NearLink

- [ohos.permission.ACCESS_NEARLINK](permissions-for-all.md#ohospermissionaccess_nearlink)

<!--RP1End-->

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

  - (Recommended) Use [Picker](../../media/medialibrary/photoAccessHelper-photoviewpicker.md) to read images and videos in the media library, and use [SaveButton](../../media/medialibrary/photoAccessHelper-savebutton.md#using-savebutton) to save images and videos in the media library. This solution is recommended because the application does not need any permission.
  - Apply for the <!--RP5-->[ohos.permission.READ_IMAGEVIDEO](permissions-for-system-apps.md#ohospermissionread_imagevideo) or [ohos.permission.WRITE_IMAGEVIDEO](permissions-for-system-apps.md#ohospermissionwrite_imagevideo)<!--RP5End--> permission to read images and videos in the media library.

- To read audio clips in the media library:

  Apply for the restricted permission <!--RP6-->[ohos.permission.READ_AUDIO](permissions-for-system-apps.md#ohospermissionread_audio) or [ohos.permission.WRITE_AUDIO](permissions-for-system-apps.md#ohospermissionwrite_audio)<!--RP6End--> to read or write audio files in the media library.

- To read documents in **Files**:

  Use the file Picker to read documents in **Files**. For details, see [Selecting Documents](../../file-management/select-user-file.md#selecting-documents) and [Saving Documents](../../file-management/save-user-file.md#saving-documents).

<!--no_check-->