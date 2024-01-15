# Using System Pickers

A Picker is implemented by an independent system process. It provides a safe, built-in way for users to grant your application access to only selected resources. By starting a Picker component, the application can directly access the resources, such as images or documents, selected by the user using the Picker.

For example, an audio player can obtain the path of the audio file selected by the user via **AudioViewPicker**, and play the audio clip.

Currently, the following Picker components are available:

- [AudioViewPicker](#audioviewpicker): allows to select or save audio files.

- [DocumentViewPicker](#documentviewpicker): allows to select or save documents.

- [PhotoViewPicker](#photoviewpicker): allows to select or save images or videos.

- [Contacts Picker](#contacts picker): allows to select a contact.

## AudioViewPicker

You can use **AudioViewPicker** if your application needs to access or save audio files in a user directory.

- To enable an application to access audio files in a user directory without requesting the ohos.permission.READ_AUDIO permission, use **AudioViewPicker** in FilePicker. For details, see [Selecting Audio Clips](../../file-management/select-user-file.md#selecting-audio-clips).

- To enable an application to modify audio files in a user directory without requesting the ohos.permission.WRITE_AUDIO permission, use **AudioViewPicker** in FilePicker. For details, see [Saving Audio Clips](../../file-management/save-user-file.md#saving-audio-clips).

## DocumentViewPicker

You can use **DocumentViewPicker** if your application needs to access or save non-media files in a user directory.

- To enable an application to access non-media files in a user directory without requesting the ohos.permission.READ_DOCUMENT permission, use **DocumentViewPicker** in FilePicker. For details, see [Selecting Documents](../../file-management/select-user-file.md#selecting-documents).

- To enable an application to modify non-media files in a user directory without requesting the ohos.permission.WRITE_DOCUMENT permission, use **DocumentViewPicker** in FilePicker. For details, see [Saving Documents](../../file-management/save-user-file.md#saving-documents).


## PhotoViewPicker

You can use **PhotoViewPicker** if your application needs to access or save images or videos in a user directory.

- To enable an application to access images or videos in a user directory without requesting the ohos.permission.READ_IMAGEVIDEO permission, use **PhotoViewPicker** in FilePicker. For details, see [Selecting Images or Videos](../../file-management/select-user-file.md#selecting-images-or-videos).

- To enable an application to modify images or videos in a user directory without requesting the ohos.permission.WRITE_IMAGEVIDEO permission, use **PhotoViewPicker** in FilePicker. For details, see [Saving Images or Videos](../../file-management/save-user-file.md#saving-images-or-videos).


## Contacts Picker

You can use **Contacts Picker** if your application needs to read or write Contacts data.

- To enable an application to read Contacts data without requesting the ohos.permission.READ_CONTACTS permission, use **Contacts Picker**. For details, see [contact.selectContacts](../../reference/apis/js-apis-contact.md#contactselectcontacts10).
