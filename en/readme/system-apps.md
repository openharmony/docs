# System Applications<a name="ZH-CN_TOPIC_0000001103601750"></a>

## Introduction<a name="section663544819225"></a>

This module provides some system applications that are applicable to the OpenHarmony standard system, such as Launcher, SystemUI, and Settings. It also provides specific examples for you to build applications that can be run on all standard-system devices.

Currently, OpenHarmony supports the following system applications:

1.  Launcher: acts as a main entry for all applications and provides UIs for display and human-machine interactions of installed applications.
2.  SystemUI: consists of the navigation bar and system status bar. The navigation bar provides page navigation, and the status bar displays the system status, such as the time and charging status.
3.  Settings: provides features such as device management, application management, and brightness setting.
4.  Contacts: provides features such as the dialer, call record query/deletion, contacts list, contact details query, and contact management.
5.  Messaging: provides features such as SMS message management (send, receive, view, and delete) and SMS delivery report.
6.  Phone: allows users to answer and end voice calls and enable or disable mobile data.
7.  Camera: provides features such as preview, photo taking, thumbnail display, and image browsing.
8.  Gallery: allows users to manage, browse, view, and edit photos, videos, and albums.

Note:
In the OpenHarmony 3.1 Release version, only the code for the Gallery application can be built with the released IDE and SDK. The code of other system applications is still being adapted and optimized, which is expected to be completed by April 30, 2022. The actual supported applications are subject to the final release.

## Directory Structure<a name="section161941989596"></a>

```
/applications/
├── launcher         # Launcher application code
├── systemui         # SystemUI application code
├── settings         # Settings application code
├── hap              # Binary code for system applications
├── contacts         # Contacts application code
├── mms              # Messaging application code
├── call             # Phone application code
├── camera           # Camera application code
├── photos           # Gallery application code
```

## Repositories Involved<a name="section1371113476307"></a>

**System applications**

[applications\_settings](https://gitee.com/openharmony/applications_settings)

[applications\_launcher](https://gitee.com/openharmony/applications_launcher)

[applications\_systemui](https://gitee.com/openharmony/applications_systemui)

[applications\_hap](https://gitee.com/openharmony/applications_hap)

[applications\_contacts](https://gitee.com/openharmony/applications_contacts)

[applications\_mms](https://gitee.com/openharmony/applications_mms)

[applications\_call](https://gitee.com/openharmony/applications_call)

[applications\_camera](https://gitee.com/openharmony/applications_camera)

[applications\_photos](https://gitee.com/openharmony/applications_photos)
