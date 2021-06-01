# System Apps<a name="EN-US_TOPIC_0000001103601750"></a>

-   [Introduction](#section663544819225)
-   [Directory Structure](#section161941989596)
-   [Repositories Involved](#section1371113476307)

## Introduction<a name="section663544819225"></a>

This module provides some system apps that are applicable to the OpenHarmony standard system, such as Launcher, SystemUI, and Settings. It also provides specific examples for you to build standard-system apps, which can be installed on all devices running the standard system.

Currently, OpenHarmony supports the following system apps:

1.  Launcher: acts as a main entry for all apps and provides UIs for display and human-machine interactions of installed apps.
2.  SystemUI: consists of the navigation bar and system status bar. The navigation bar provides page navigation, and the status bar displays the system status, such as the time and charging status.
3.  Settings: provides functions such as device management, app management, and brightness setting.

## Directory Structure<a name="section161941989596"></a>

```
/applications/standard/
├── launcher         # Launcher app code
├── systemui         # SystemUI app code
├── settings         # Settings app code
├── hap              # Binary code for system apps
```

## Repositories Involved<a name="section1371113476307"></a>

**System apps**

applications\_standard\_settings

applications\_standard\_launcher

applications\_standard\_systemui

applications\_standard\_hap

