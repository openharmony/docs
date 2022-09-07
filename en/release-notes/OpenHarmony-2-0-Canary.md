# OpenHarmony 2.0 Canary \(2021-06-01\)

## Version Description

On the basis of OpenHarmony 1.1.0, OpenHarmony 2.0 adds the version for the standard system, which delivers the following functions:

-   Twenty-two subsystems have been added to support comprehensive OS capabilities and app development for screened devices with a memory greater than 128 MB.
-   Three preset apps, Launcher, Settings, and SystemUI, have been provided.
-   A brand-new OpenHarmony application framework and JS UI framework have been provided.
-   JavaScript app development capabilities have been provided.
-   A media framework has been provided to support the development of audio and video functions.
-   The Java UI framework has been provided to support window management, image synthesis, and GPU rendering capabilities.

## Version Mapping

**Table  1**  Version mapping of software and tools

| Software                             | Version                     | Remarks                                            |
| ------------------------------------ | --------------------------- | -------------------------------------------------- |
| OpenHarmony                          | 2.0 Canary                  | N/A                                                |
| (Optional) HUAWEI DevEco Studio      | DevEco Studio 2.1 Release   | It is recommended for developing OpenHarmony apps. |
| (Optional) HUAWEI DevEco Device Tool | Deveco DeviceTool 2.2 Beta1 | It is recommended for OpenHarmony smart devices.   |


## Source Code Acquisition


### Acquiring Source Code Using the repo Tool

**Method 1 (recommended)**: Use the **repo** tool to download the source code over SSH. (You must have registered an SSH public key for access to Gitee.)


 ```shell
repo init -u git@gitee.com:openharmony/manifest.git -b refs/tags/OpenHarmony-2.0-Canary --no-repo-verify
repo sync -c
repo forall -c 'git lfs pull'
 ```

**Method 2**: Use the **repo** tool to download the source code over HTTPS.



```shell
repo init -u https://gitee.com/openharmony/manifest.git -b refs/tags/OpenHarmony-2.0-Canary --no-repo-verify
repo sync -c
repo forall -c 'git lfs pull'
```


### Acquiring Source Code from Mirrors

**Table  2** Mirrors for acquiring source code

| Source&nbsp;Code | Version | Mirror | SHA-256&nbsp;Checksum |
| -------- | -------- | -------- | -------- |
| Full&nbsp;code&nbsp;base | 2.0 | [Download](https://repo.huaweicloud.com/harmonyos/os/2.0/code-2.0-canary_20210601.tar.gz) | [Download](https://repo.huaweicloud.com/harmonyos/os/2.0/code-2.0-canary_20210601.tar.gz.sha256) |
| Release&nbsp;Notes | 2.0 | [Download](https://gitee.com/openharmony/docs/blob/master/en/release-notes/OpenHarmony-2-0-Canary.md) | - |


## What's New

This version inherits all the features of OpenHarmony 1.1.0 and adds the version form for the standard system. The following table describes the specific features added for the version form.

**Table  3**  New features

| Subsystem                    | New Feature                                                  |
| ---------------------------- | ------------------------------------------------------------ |
| Kernel                       | The OpenHarmony kernel is built based on the open-source Linux kernel LTS release and forms a complete kernel baseline by merging the common vulnerabilities and exposures (CVE) patches and features for OpenHarmony upper-layer adaptation. |
| Distributed File             | Provided JavaScript APIs for local file synchronization, including reading and writing files, accessing directories, and collecting file statistics. |
| Graphics                     | - Provided window management functions, including creating and destroying windows and managing window stacks.<br/>- Added the synthesizer function, which implements CPU, GPU, and TDE synthesis.<br/>- Added the BufferQueue function to support inter-process communication.<br/>- Added the VSync management function. |
| Driver                       | Added the user-space driver framework.                       |
| Power Management             | Added power management capabilities, including powering off the device, turning on/off the device screen, adjusting the brightness, querying the battery status, and managing the system power and running lock. |
| Multimodal Input             | Added the single-touch input capability.                     |
| Startup                      | Added JavaScript APIs for managing system attributes.        |
| Update                       | - Added the OTA update using a full package.<br/>- Added the OTA update using a differential package.<br/>- Added JavaScript APIs for managing system attributes. |
| Account                      | Provided login status management of distributed cloud accounts. |
| Compilation and Building     | - Added building of targets by module name or submodule name.<br/>- Supported access of different chip platforms and configuration of the product module list. |
| Testing                      | Added the developer test capability of conducting C++ API unit tests and API performance tests. |
| Data Management              | Provided lightweight key-value operations for local apps to store a small amount of data. As the stored data is already loaded in the memory, the faster data access speed achieves a higher work efficiency. |
| Programming Language Runtime | Provided the compilation and execution environment for programs developed with JavaScript, and C/C++, basic libraries that support the runtime, and the runtime-associated APIs, compilers, and auxiliary tools. |
| Distributed Scheduler        | Provided the capabilities of starting, registering, querying, and managing system services. |
| JS UI framework              | - Provided more than 40 basic UI components and container components.<br/>- Provided standard CSS animations.<br/>- Provided the atomic layout and grid layout.<br/>- Provided a UI programming framework that supports the web-development-like paradigm.<br/>- Provided the JavaScript API extension mechanism. |
| Multimedia                   | - Added basic functions of media playback and recording.<br/>- Added basic functions of camera management and sampling.<br/>- Added basic functions of audio volume and device management. |
| Event Notification           | Added basic functions of publishing, subscribing to, and receiving common events. |
| Misc Services                | Added the function of setting the time.                      |
| Application framework        | Provided bundle installation, uninstallation, running, and management capabilities. |
| Telephony                    | - Provided the capabilities of obtaining the signal strength and the network registration status.<br/>- Provided the capability of obtaining the SIM card status.<br/>- Provided the capabilities of making, rejecting, and ending calls.<br/>- Provided the capabilities of sending and receiving SMS messages. |
| Utils                        | Provides some common enhanced APIs for development using C and C++. |
| Development Tools            | - Provided the device connection debugger.<br/>- Provided the performance tracing capability.<br/>- Provided real-time memory analysis, trace, and device-side plug-ins. |
| DSoftBus                     | - Provided inter-process communication (IPC) and remote procedure call (RPC) capabilities.<br/>- Provided soft bus services including device discovery, networking, and transmission.<br/>- Provided basic WLAN capabilities, including enabling/disabling, scanning, and connecting to a station. |
| XTS                          | Provided test case suites for maintaining the compatibility of common APIs for subsystems. |
| System Apps                  | Home screen:<br/>- Provided the capabilities of displaying all app icons, starting an app, and uninstalling an app.<br/>- Provided the Launcher system app that allows switching between the grid layout and list layout.<br/>- Provided recent task management to support hot start and task deletion.<br/>Settings:<br/>- Provided the Settings system app that allows users to set the brightness and time and to query app and device information.<br/>SystemUI:<br/>- Provided the system status bar to display time and battery information.<br/>- Provided the display of system navigation. |
| DFX                          | - Provided the logging function.<br/>- Provided fault information collection and subscription.<br/>- Provided APIs for logging system events.<br/>- Provided the framework and APIs for logging app events. |
| Globalization                | - Provided the capability of parsing and reading i18n resources.<br/>- Provided the capability of formatting the date and time. |
| Security                     | - Provided system permission management, including system permission declaration, parsing of the permissions requested or declared during app installation, permission query, and permission granting.<br/>- Provided the app signature and signature verification capabilities.<br/>- Provided mutual authentication and device group management for trusted P2P devices. |

