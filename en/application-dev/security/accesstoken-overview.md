# Access Control Overview

## Introduction
AccessTokenManager (ATM) implements unified app permission management based on access tokens on OpenHarmony.

By default, apps can access limited system resources. However, in some cases, an app needs to access excess data (including personal data) and functions of the system or another app to implement extended functions. Systems or apps must also share their data or functions through interfaces in an explicit manner. OpenHarmony uses app permissions to perform access control and prevent improper or malicious use of these data or functions.

App permissions are used to protect the following objects:

- Data: personal data (such as photos, Contacts, calendar, and location), device data (such as device ID, camera, and microphone), and app data.
- Functions: device functions (such as making calls, sending SMS messages, and connecting to the Internet) and app functions (such as displaying windows and creating shortcuts).

Without the required permissions, an app cannot access or perform operations on the target object. Permissions must be clearly defined for apps. With app permissions, the system can standardize the behavior of apps and protect user privacy. Before an app accesses the target object, the target object verifies the app's permissions and denies the access if the app does not have required permissions.

Currently, ATM performs app permission verification based on the token identity (Token ID). A token ID identifies an app. The ATM manages app permissions based on the app's token ID.

## How to Develop

Determine the permissions required for an app to access data or perform an operation. Declare the required permissions in the app installation package.

Determine whether the required permissions need to be authorized by users. If yes, provide a dialog box dynamically to request user authorization.

After the user grants permissions to the app, the app can access the data or perform the operation.

The figure below shows the process.

![](figures/figure1.png)

## When to Use

### Scenarios

The following describes two common scenarios.

- **Video playback apps**

    Video playback apps need to use multimedia functions and read and write media files stored on storage devices. Therefore, the apps must have at least the following permissions:

    * ohos.permission.READ_MEDIA (allowing the app to read external media files)

    * ohos.permission.WRITE_MEDIA (allowing the app to read and write external media files)

- **Photography apps**

    Photography apps need to use the camera function. Before accessing the camera service, the app must have the following permission:

    ohos.permission.CAMERA (allowing the app to use the camera to take photos and record videos).

### Basic Principles

Observe the following principles for permission management:

- Provide clear description about the app functions and scenarios and permissions required for using the app so that users can clearly know why, when, and how to apply for permissions for using the app. Do not induce or mislead users' authorization. The permissions on an app must comply with the description provided in the app.
- Use the principle of least authority for user permissions. Allow only necessary permissions for service functions.
- When an app is started for the first time, avoid frequently displaying pop-up windows for users to apply for multiple permissions. Allow users to apply for permissions only when they need to use the corresponding service functions.
- If a user rejects to authorize a permission, the user can still use functions irrelevant to this permission and can register and access the app.
- Provide no more message if a user rejects the authorization required by a function. Provide onscreen instructions to direct the user to give authorization in System Settings if the user triggers this function again or needs to use this function.

- All the permissions granted to apps must come from the Permission List. Custom permissions are not allowed for apps currently.

## Permission Levels

To protect user privacy, ATM defines different permission levels based on the sensitivity of the data involved or the security threat of the ability.

### App APL

The ability privilege level (APL) defines the priority of the app permission requested. Apps of different APLs can apply for permissions of different levels.

The table below describes the APLs.

| APL         | Description                                  |
| ---------------- | -------------------------------------- |
| system_core | The apps of this level provide core abilities of the operating system.|
| system_basic| The apps of this level provide basic system services.    |
| Normal      | The apps of this level are normal apps.                            |

By default, apps are of the normal APL. To declare the system_basic or higher APL:
- The APL must be approved by the app store.
- The APL must be declared in the **apl** field of the app's profile in the app installation package, and a profile signing certificate must be generated. For details, see [Configuring OpenHarmony App Signature Information]( https://developer.harmonyos.com/en/docs/documentation/doc-guides/ohos-debugging-and-running-0000001263040487#section17660437768).

### Permission Levels

The permissions open to apps vary with the permission level. The permission levels include the following in ascending order of seniority.

- **normal**

    The normal permission allows access to common system resources beyond the default rules. Access to these system resources (including data and functions) has minor risks on user privacy and other apps.

    The permissions of this level are available only to apps of the normal or higher APL.

- **system_basic**

    The system_basic permission allows access to resources related to basic operating system services. The basic services are basic functions provided or preconfigured by the system, such as system setting and identity authentication. Access to these resources may have considerable risks to user privacy and other apps.

    The permissions of this level are available only to the apps of the system_basic APL.

- **system_core**

    The system_core permission allows access to core resources of the operating system. These resources are the underlying core services of the system. If these resources are corrupted, the OS cannot run properly.
    
    The permissions of this type are not open to any app currently.

### ACL

As described above, permission levels and app APLs are in one-to-one correspondence. In principle, **an app with a lower APL cannot apply for higher permissions by default**.

The Access Control List (ACL) makes low-level apps to have high-level permissions.

**Example**

The APL of app A is normal. App A needs to have permission B (system_basic level) and permission C (normal level). In this case, you can use the ACL to grant permission B to app A.

For details, see [Using the ACL](#usingacl).

## Permission Authorization Modes

Permissions can be classified into the following types based on the authorization mode:

- **system_grant**

    The app permissions are authorized by the system. This type of apps cannot access user or device sensitive information. The allowed operations have minor impact on the system or other apps.

    For a system_grant app, the system automatically grants the required permissions to the app when the app is installed. The system_grant permission list must be presented to users on the details page of the app store.

- **user_grant**

    The app permissions must be authorized by users. This type of apps may access user or device sensitive information. The allowed operations may have a critical impact on the system or other apps.

    This type of permissions must be declared in the app installation package and authorized by users dynamically during the running of the app. The app has the permission only after user authorization.

    For example, in the [Permission List](#permissionlist), the permissions for the microphone and camera are user_grant permissions. The list provides reasons for using the permissions.

    The user_grant permission list must also be presented on the details page of the app store.

## Authorization Processes

The process for an app obtaining the required permissions varies

depending on the permission authorization mode.

- For a system_grant permission, you need to [declare the permission](accesstoken-guidelines.md) in the **config.json** file. The permission will be pre-granted when the app is installed.

- For a user_grant permission, you need to [declare the permission](accesstoken-guidelines.md) in the **config.json** file, and a dialog box needs to be displayed to request user authorization during the running of the app.

### Permission Authorization Process (user_grant)

The procedure is as follows:

1. In the **config.json** file, declare the permissions required by the app. For details, see [Access Control Development](accesstoken-guidelines.md).

2. Associate the object that requires the permissions in the app with the target permissions. In this way, the user knows the operations to be granted with the specified permissions.

3. Check whether the user has granted the required permissions to the app when the app is running. If yes, the app can access the data or perform the operation. If the user has not granted the permissions to the app, display a dialog box requesting the user authorization when the app attempts to access the data or perform the operation.

4. Check the user authorization result. Allow the next step only after the user has granted the permissions to the app.

**Precautions**

- Check the app's permission each time before the operation requiring the permission is performed.

- To check whether a user has granted specific permissions to your app, use the [verifyAccessToken](../reference/apis/js-apis-abilityAccessCtrl.md) method. This method returns [PERMISSION_GRANTED](../reference/apis/js-apis-abilityAccessCtrl.md) or [PERMISSION_DENIED](../reference/apis/js-apis-abilityAccessCtrl.md). For details about the sample code, see [Access Control Development](accesstoken-guidelines.md).
- Users must be able to understand and control the authorization of user_grant permissions. During the running process, the app requiring user authorization must proactively call the API to dynamically request the authorization. Then, the system displays a dialog box asking the user to grant the requested permission. The user will determine whether to grant the permission based on the running context of the app.
- The permission authorized is not permanent, because the user may revoke the authorization at any time. Therefore, even if the user has granted the requested permission to the app, the app must check for the permission before calling the API controlled by this permission.

### Using the ACL

If the permission required by an app has higher level than the app's APL, you can use the ACL to grant the permissions required.

In addition to the preceding [authorization processes](#authorizationprocesses), you need to declare the ACL.

In addition to declaring the required permissions in the **config.json** file, you must declare the high-level permissions in the app's [profile](accesstoken-guidelines.md). The subsequent steps remain unchanged.

**NOTE**

* The ACL must be approved by the app store.
* Declare the target ACL in the **acl** field of the app's profile in the app installation package, and generate a profile signing certificate. For details, see [Configuring OpenHarmony App Signature Information]( https://developer.harmonyos.com/en/docs/documentation/doc-guides/ohos-debugging-and-running-0000001263040487#section17660437768).

## Permission List

The following lists the permissions defined by the system.

| Permission                                                  | APL    | Authorization Mode    | Enable ACL| Description                                                    |
| -------------------------------------------------------- | ------------ | ------------ | ------- | ------------------------------------------------------------ |
| ohos.permission.USE_BLUETOOTH                            | normal       | system_grant | TRUE    | Allows an app to access to Bluetooth configuration.                                    |
| ohos.permission.DISCOVER_BLUETOOTH                       | normal       | system_grant | TRUE    | Allows an app to configure Bluetooth on a device, initiate or cancel a scan for Bluetooth devices, and pair with Bluetooth devices.          |
| ohos.permission.MANAGE_BLUETOOTH                         | system_basic | system_grant | TRUE    | Allows an app to pair with a Bluetooth device and access the Contacts or messages of the device.      |
| ohos.permission.INTERNET                                 | normal       | system_grant | TRUE    | Allows an app to access the Internet.                                      |
| ohos.permission.MODIFY_AUDIO_SETTINGS                    | normal       | system_grant | TRUE    | Allows an app to modify audio settings.                                      |
| ohos.permission.GET_TELEPHONY_STATE                      | system_basic | system_grant | TRUE    | Allows an app to read telephony information.                                       |
| ohos.permission.REQUIRE_FORM                             | system_basic | system_grant | TRUE    | Allows an app to obtain the Ability Form.                                  |
| ohos.permission.GET_NETWORK_INFO                         | normal       | system_grant | TRUE    | Allows an app to obtain network information.                                  |
| ohos.permission.PLACE_CALL                               | system_basic | system_grant | TRUE    | Allows an app to make calls without starting the dialer.                                      |
| ohos.permission.SET_NETWORK_INFO                         | normal       | system_grant | TRUE    | Allows an app to set data network information.                                      |
| ohos.permission.REMOVE_CACHE_FILES                       | system_basic | system_grant | TRUE    | Allows the cache of the specified app to be cleared.                                    |
| ohos.permission.REBOOT                                   | system_basic | system_grant | TRUE    | Allows an app to restart the device.                                          |
| ohos.permission.RUNNING_LOCK                             | normal       | system_grant | TRUE    | Allows an app to obtain a running lock.              |
| ohos.permission.ENROLL_BIOMETRIC                         | system_core  | system_grant | FALSE   | Allows an app to add or remove biometric data.                            |
| ohos.permission.ACCESS_BIOMETRIC                         | normal       | system_grant | FALSE   | Allows an app to use biometric recognition for identity authentication.                  |
| ohos.permission.ACCESS_BIOMETRIC_INTERNAL                | system_core  | system_grant | FALSE   | Allows an app to apply for or release biometric recognition resources.                      |
| ohos.permission.RESET_BIOMETRIC_LOCKOUT                  | system_core  | system_grant | FALSE   | Allows an app to reset the maximum number of failures allowed before biometric authentication is locked.                    |
| ohos.permission.SET_TIME                                 | system_basic | system_grant | TRUE    | Allows an app to set the system time.                                      |
| ohos.permission.SET_TIME_ZONE                            | system_basic | system_grant | TRUE    | Allows an app to set the system time zone.                                      |
| ohos.permission.DOWNLOAD_SESSION_MANAGER                 | system_core  | system_grant | TRUE    | Allows an app to manage the downloaded sessions.                                  |
| ohos.permission.COMMONEVENT_STICKY                       | normal       | system_grant | TRUE    | Allows an app to publish sticky common events.                                  |
| ohos.permission.SYSTEM_FLOAT_WINDOW                      | normal       | system_grant | TRUE    | Allows an app to be displayed in a floating window on top of other apps.                                  |
| ohos.permission.POWER_MANAGER                            | system_core  | system_grant | TRUE    | Allows an app to hibernate or wake up the device by calling APIs.        |
| ohos.permission.REFRESH_USER_ACTION                      | system_basic | system_grant | TRUE    | Allows an app to reset the screen timeout counter when a user input event occurs, such as pressing a key or tapping the screen.                |
| ohos.permission.POWER_OPTIMIZATION                       | system_basic | system_grant | TRUE    | Allows an app to set power saving mode, obtain configuration of the power saving mode, and receive notifications of the configuration changes.|
| ohos.permission.REBOOT_RECOVERY                          | system_basic | system_grant | TRUE    | Allows an app to restart the device and enter Recovery mode.                        |
| ohos.permission.MANAGE_LOCAL_ACCOUNTS                    | system_basic | system_grant | TRUE    | Allows an app to manage local user accounts.                                  |
| ohos.permission.INTERACT_ACROSS_LOCAL_ACCOUNTS           | system_basic | system_grant | TRUE    | Allows access between multiple OS accounts.                              |
| ohos.permission.VIBRATE                                  | normal       | system_grant | TRUE    | Allows an app to control motor vibration.                                      |
| ohos.permission.CONNECT_IME_ABILITY                      | system_core  | system_grant | TRUE    | Allows an app or service to bind the **InputMethodAbility**.                 |
| ohos.permission.CONNECT_SCREEN_SAVER_ABILITY             | system_core  | system_grant | TRUE    | Allows an app or service to bind the **ScreenSaverAbility**.                   |
| ohos.permission.READ_SCREEN_SAVER                        | system_basic | system_grant | TRUE    | Allows an app to read the screen saver information, such as the list of screen savers that have been installed and the activated one.                                  |
| ohos.permission.WRITE_SCREEN_SAVER                       | system_basic | system_grant | TRUE    | Allows an app to modify the screen saver information, such as activating and previewing a screen saver.                                  |
| ohos.permission.SET_WALLPAPER                            | normal       | system_grant | TRUE    | Allows an app to set a static wallpaper.                                      |
| ohos.permission.GET_WALLPAPER                            | system_basic | system_grant | TRUE    | Allows an app to read wallpaper files.                                      |
| ohos.permission.CHANGE_ABILITY_ENABLED_STATE             | system_basic | system_grant | TRUE    | Allows an app to enable or disable an app or component.                            |
| ohos.permission.ACCESS_MISSIONS                          | system_basic | system_grant | TRUE    | Allows an app to obtain information about running processes and tasks in a task stack.                                    |
| ohos.permission.CLEAN_BACKGROUND_PROCESSES               | normal       | system_grant | TRUE    | Allows an app to clear background processes based on their bundle names.                          |
| ohos.permission.KEEP_BACKGROUND_RUNNING                  | normal       | system_grant | TRUE    | Allows a service ability to keep running in the background.                         |
| ohos.permission.UPDATE_CONFIGURATION                     | system_basic | system_grant | TRUE    | Allows an app to modify system settings.                                          |
| ohos.permission.GRANT_SENSITIVE_PERMISSIONS              | system_core  | system_grant | TRUE    | Allows an app to grant sensitive permissions to other apps.                            |
| ohos.permission.REVOKE_SENSITIVE_PERMISSIONS             | system_core  | system_grant | TRUE    | Allows an app to revoke sensitive permissions granted to other apps.                      |
| ohos.permission.GET_SENSITIVE_PERMISSIONS                | system_core  | system_grant | TRUE    | Allows an app to obtain the sensitive permissions that have been granted to other apps.                      |
| ohos.permission.INTERACT_ACROSS_LOCAL_ACCOUNTS_EXTENSION | system_core  | system_grant | TRUE    | Allows an app to set the attributes of apps of other users.                    |
| ohos.permission.LISTEN_BUNDLE_CHANGE                     | system_basic | system_grant | TRUE    | Allows an app to listen for changes in other apps, when they are installed, updated, or uninstalled.            |
| ohos.permission.GET_BUNDLE_INFO                          | normal       | system_grant | TRUE    | Allows a non-system app to obtain information about other apps.                                |
| ohos.permission.ACCELEROMETER                            | normal       | system_grant | TRUE    | Allows an app to read data from an acceleration sensor, uncalibrated acceleration sensor, or linear acceleration sensor.                            |
| ohos.permission.GYROSCOPE                                | normal       | system_grant | TRUE    | Allows an app to read data from a gyroscope sensor or uncalibrated gyroscope sensor.                            |
| ohos.permission.GET_BUNDLE_INFO_PRIVILEGED               | system_basic | system_grant | TRUE    | Allows a non-system app to obtain information about other apps.                                |
| ohos.permission.INSTALL_BUNDLE                           | system_core  | system_grant | TRUE    | Allows an app to install and uninstall other apps.                                |
| ohos.permission.MANAGE_SHORTCUTS                         | system_core  | system_grant | TRUE    | Allows an app to query and start shortcuts of other apps.|
| ohos.permission.radio.ACCESS_FM_AM                       | system_core  | system_grant | TRUE    | Allows an app to access radio services.                                |
| ohos.permission.SET_TELEPHONY_STATE                      | system_basic | system_grant | TRUE    | Allows an app to change the telephone state.                               |
| ohos.permission.START_ABILIIES_FROM_BACKGROUND           | system_basic | system_grant | TRUE    | Allows an app to start Feature abilities in the background.                                      |
| ohos.permission.BUNDLE_ACTIVE_INFO                       | system_basic | system_grant | TRUE    | Allows an app to obtain how long other apps have been running in the foreground or background.            |
| ohos.permission.START_INVISIBLE_ABILITY                  | system_core  | system_grant | TRUE    | Allows an app to start an invisible ability.                   |
| ohos.permission.sec.ACCESS_UDID                          | system_basic | system_grant | TRUE    | Allows an app to obtain the Unified Device ID (UDID).                                        |
| ohos.permission.LAUNCH_DATA_PRIVACY_CENTER               | system_basic | system_grant | TRUE    | Allows an app to switch from its privacy statement page to the <b>Data & privacy</b> page.            |
| ohos.permission.MANAGE_MEDIA_RESOURCES                   | system_basic | system_grant | TRUE    | Allows an app to obtain and manage the media resources that are being played on the device.|
| ohos.permission.PUBLISH_AGENT_REMINDER                   | normal       | system_grant | TRUE    | Allows an app to use agent-powered reminders.                                |
| ohos.permission.CONTROL_TASK_SYNC_ANIMATOR               | system_core  | system_grant | TRUE    | Allows apps to use sync task animations.                                  |
| ohos.permission.INPUT_MONITORING                         | system_core  | system_grant | TRUE    | Allows the app to listen for input events. Only the system signature apps can apply for this permission.          |
| ohos.permission.MANAGE_MISSIONS                          | system_core  | system_grant | TRUE    | Allows users to manage ability task stacks.                                  |
| ohos.permission.NOTIFICATION_CONTROLLER                  | system_core  | system_grant | TRUE    | Allows an app to manage and subscribe to notifications. Currently, only system apps can apply for this permission.  |
| ohos.permission.CONNECTIVITY_INTERNAL                    | system_basic | system_grant | TRUE    | Allows the app to obtain network information or modify network settings. Currently, only system apps can apply for this permission.|
| ohos.permission.ANSWER_CALL                              | system_basic | user_grant   | TRUE    | Allows the app to answer incoming calls.                                          |
| ohos.permission.READ_CALENDAR                            | normal       | user_grant   | TRUE    | Allows an app to read calendar data.                                      |
| ohos.permission.READ_CALL_LOG                            | system_basic | user_grant   | TRUE    | Allows an app to read call logs.                                      |
| ohos.permission.READ_CELL_MESSAGES                       | system_basic | user_grant   | TRUE    | Allows an app to read cell broadcast messages received by the device.                        |
| ohos.permission.READ_CONTACTS                            | system_basic | user_grant   | TRUE    | Allows an app to read contacts.                                    |
| ohos.permission.READ_MESSAGES                            | system_basic | user_grant   | TRUE    | Allows an app to read messages.                                        |
| ohos.permission.RECEIVE_MMS                              | system_basic | user_grant   | TRUE    | Allows the app to receive and process MMS messages.                                    |
| ohos.permission.RECEIVE_SMS                              | system_basic | user_grant   | TRUE    | Allows the app to receive and process SMS messages.                                    |
| ohos.permission.RECEIVE_WAP_MESSAGES                     | system_basic | user_grant   | TRUE    | Allows the app to receive and process WAP messages.                                 |
| ohos.permission.MICROPHONE                               | normal       | user_grant   | TRUE    | Allows an app to access the microphone.                                        |
| ohos.permission.SEND_MESSAGES                            | system_basic | user_grant   | TRUE    | Allows an app to send messages.                                          |
| ohos.permission.WRITE_CALENDAR                           | normal       | user_grant   | TRUE    | Allows an app to add, remove, and modify calendar events.                          |
| ohos.permission.WRITE_CALL_LOG                           | system_basic | user_grant   | TRUE    | Allows an app to add, remove, and modify call logs.                          |
| ohos.permission.WRITE_CONTACTS                           | system_basic | user_grant   | TRUE    | Allows an app to add, remove, and modify contacts.                        |
| ohos.permission.DISTRIBUTED_DATASYNC                     | normal       | user_grant   | TRUE    | Allows an app to exchange data with other devices.                                  |
| ohos.permission.MANAGE_VOICEMAIL                         | system_basic | user_grant   | TRUE    | Allows an app to add messages in the voice mailbox.                                    |
| ohos.permission.LOCATION_IN_BACKGROUND                   | normal       | user_grant   | FALSE   | Allows an app running in the background to obtain the device location.                      |
| ohos.permission.LOCATION                                 | normal       | user_grant   | TRUE    | Allows an app to obtain the device location.                                  |
| ohos.permission.MEDIA_LOCATION                           | normal       | user_grant   | TRUE    | Allow an app to access geographical locations in the user's media file.                  |
| ohos.permission.CAMERA                                   | normal       | user_grant   | TRUE    | Allows an app to use the camera to take photos and record videos.                        |
| ohos.permission.READ_MEDIA                               | normal       | user_grant   | TRUE    | Allows an app to read media files from the user's external storage.                  |
| ohos.permission.WRITE_MEDIA                              | normal       | user_grant   | TRUE    | Allows an app to read media files from and write media files into the user's external storage.                  |
| ohos.permission.ACTIVITY_MOTION                          | normal       | user_grant   | TRUE    | Allows an app to read the current workout status of the user.                            |
| ohos.permission.READ_HEALTH_DATA                         | normal       | user_grant   | TRUE    | Allows an app to read the health data of the user.                                |
