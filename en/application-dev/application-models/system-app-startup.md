# Starting a System Application


This topic describes how to start a system application. It also lists the supported redirection capabilities of system applications.

## Access Using System-Level \<Picker> Components

With system-level **\<Picker>** components, you can use certain common functions of system applications, such as Camera, Files, and Contacts, without applying for permissions. For example, an audio player can obtain the path of the audio file selected by the user via **AudioViewPicker**, and play the audio clip.


### Working Principles

An application starts a system-level **\<Picker>** component (such as **DocumentViewPicker**, **PhotoViewPicker**, or **ContactsPicker**). The user selects files, photos, or contacts on the component, and the application obtains the result returned by the component.

A system-level **\<Picker>** component is implemented by an independent system process.


### Supported System-Level **\<Picker>** Components

The table below lists the system-level **\<Picker>** components that are currently supported.

> **NOTE**
> 
> The system-level **\<Picker>** components have been pre-authorized. When using such a component, you can temporarily access the corresponding resources without requesting the permissions. For example, before accessing a user's image, an application normally needs to request user authorization. However, by using **PhotoViewPicker**, the application can directly access the image selected by the user.


| Picker Type| Usage| Operation Guide|
| -------- | -------- |-------- |
| DocumentViewPicker| Used to access and save documents in the public directory.|- [Selecting Documents](../file-management/select-user-file.md#selecting-documents)<br> - [Saving Documents](../file-management/save-user-file.md#saving-documents)|
| AudioViewPicker| Used to access and store audio files in the public directory of the user.|- [Selecting Audio Clips](../file-management/select-user-file.md#selecting-audio-clips)<br> - [Saving Audio Clips](../file-management/save-user-file.md#saving-audio-clips)|
| PhotoViewPicker| Used to access and save images or video files in the public directory.| - [Selecting Media Assets Using Picker](../media/medialibrary/photoAccessHelper-photoviewpicker.md)<br> - [Creating a Media Asset Using \<SaveButton>](../media/medialibrary/photoAccessHelper-savebutton.md)|
| CameraPicker| Used to start the system camera to take photos and record videos.|[cameraPicker](../reference/apis-camera-kit/js-apis-cameraPicker.md) |
| ContactsPicker| Used to start the Contacts application and read contacts data.|[Selecting Contacts](../contacts/contacts-intro.md#contact-selection)|
<!--RP1--><!--RP1End-->




## Using Interfaces Provided by System Applications

System applications provide certain interfaces for others to access.

> **NOTE**
> 
> Currently, these interfaces can be used only in applications, but not on web pages.

| System Application| Usage| Operation Guide|
| -------- | -------- |-------- |
| Phone| Launch the call screen and display the dialed number.| [makeCall()](../reference/apis-telephony-kit/js-apis-call.md#callmakecall7) |
| Calendar| Create a calendar event.| [addEvent](../reference/apis-calendar-kit/js-apis-calendarManager.md#addevent) |
<!--RP2--><!--RP2End-->

<!--RP3--><!--RP3End-->

 <!--no_check--> 