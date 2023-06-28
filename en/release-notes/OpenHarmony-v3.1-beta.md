# OpenHarmony 3.1 Beta

## Version Description

OpenHarmony 3.1 Beta provides the following enhancements over OpenHarmony 3.0 LTS:

- Enhanced basic capabilities for the standard system: The CMA usage is improved in the kernel. The background rendering module of RenderService is added to the Graphics subsystem. The STA and SoftAP features are provided for short-range communications. The geomagnetic field algorithm APIs are provided. The sensor driver model capability is enhanced. Application account query and subscription are supported. New globalization features are introduced. Unified build templates are provided for the Compilation and Building subsystem. Front-end compilation toolchains for Windows, macOS, and Linux are provided for the Multi-language Runtime subsystem. Previewer is supported for JS runtime. Six third-party JS libraries (JSON Processing, EventBus, VCard, Protobuf, RxJS, and libphonenumber) are supported. Time and time zone management is supported. The HiSysEvent module is added to DFX to provide query and subscription interfaces.

- Enhanced distributed capabilities for the standard system: The distributed device profile is added. Distributed data management supports cross-device synchronization and subscription. DSoftBus supports network switchover. The distributed file system supports StatFS APIs.

- Enhanced application framework capabilities for the standard system: The ArkUI-based custom drawing capability and Lottie animation capability are added. The implicit query and multi-HAP installation are added for the bundle management framework. Permission management, notification vibration setting, notification sound setting and query, do-not-disturb (DND) notification, and session notification are added for the Common Event and Notification subsystem.

- Enhanced system application capabilities for the standard system: Text input and landscape-mode layout display for the input method application, SMS application information management, call log and dialer display in the contacts application, and more options in **Settings** are supported.

- Enhanced capabilities for the mini system: The lightweight HiStreamer supports the customizable media pipeline framework. The Linux init process supports hot swap. The OS lightweight kernel and driver startup are optimized. The quick startup capability is supported.


## Version Mapping

**Table 1** Version mapping of software and tools

| Software/Tool| Version| Remarks|
| -------- | -------- | -------- |
| OpenHarmony | 3.1 Beta | NA |
| SDK | Ohos_sdk 3.1 Beta (API Version 8 Beta)| NA |
| (Optional) HUAWEI DevEco Studio| 3.0 Beta2 | Recommended for developing OpenHarmony applications|
| (Optional) HUAWEI DevEco Device Tool| 3.0 Beta2 | Recommended for developing OpenHarmony smart devices|


## Source Code Acquisition

### Prerequisites

1.  Register your account with Gitee.
2.  Register an SSH public key for access to Gitee.
3.  Install the [git client](https://git-scm.com/book/en/v2) and [git-lfs](https://gitee.com/vcs-all-in-one/git-lfs?_from=gitee_search#downloading), and configure basic user information.

    ```
    git config --global user.name "yourname"
    git config --global user.email "your-email-address"
    git config --global credential.helper store
    ```

4.  Run the following commands to install the **repo** tool:

    ```
    curl -s https://gitee.com/oschina/repo/raw/fork_flow/repo-py3 > /usr/local/bin/repo  # If you do not have the access permission to this directory, download the tool to any other accessible directory and configure the directory to the environment variable.
    chmod a+x /usr/local/bin/repo
    pip3 install -i https://repo.huaweicloud.com/repository/pypi/simple requests
    ```

### Acquiring Source Code Using the repo Tool

**Method 1 (recommended)**

Use the **repo** tool to download the source code over SSH. (You must have an SSH public key for access to Gitee.)

```
repo init -u git@gitee.com:openharmony/manifest.git -b refs/tags/OpenHarmony-v3.1-Beta --no-repo-verify
repo sync -c
repo forall -c 'git lfs pull'
```

**Method 2**

Use the **repo** tool to download the source code over HTTPS.

```
repo init -u https://gitee.com/openharmony/manifest.git -b refs/tags/OpenHarmony-v3.1-Beta --no-repo-verify
repo sync -c
repo forall -c 'git lfs pull'
```

### Acquiring Source Code from Mirrors

**Table 2** Mirrors for acquiring source code

| Source Code| Version| Mirror| SHA-256 Checksum|
| -------------------------------- | ------------ | ------------ | ---------------- |
| Full code base (for mini, small, and standard systems)| 3.1 Beta     | [Download](https://repo.huaweicloud.com/harmonyos/os/3.1-Beta/code-v3.1-Beta.tar.gz)| [Download](https://repo.huaweicloud.com/harmonyos/os/3.1-Beta/code-v3.1-Beta.tar.gz.sha256)|
| Hi3516 standard system solution (binary)| 3.1 Beta     | [Download](https://repo.huaweicloud.com/harmonyos/os/3.1-Beta/standard_hi3516.tar.gz)| [Download](https://repo.huaweicloud.com/harmonyos/os/3.1-Beta/standard_hi3516.tar.gz.sha256)|
| RK3568 standard system solution (binary)| 3.1 Beta     | [Download](https://repo.huaweicloud.com/harmonyos/os/3.1-Beta/standard_rk3568.tar.gz)| [Download](https://repo.huaweicloud.com/harmonyos/os/3.1-Beta/standard_rk3568.tar.gz.sha256)|
| Hi3861 mini system solution (binary)| 3.1 Beta     | [Download](https://repo.huaweicloud.com/harmonyos/os/3.1-Beta/hispark_pegasus.tar.gz)| [Download](https://repo.huaweicloud.com/harmonyos/os/3.1-Beta/hispark_pegasus.tar.gz.sha256)|
| Hi3516 mini system solution - LiteOS (binary)| 3.1 Beta     | [Download](https://repo.huaweicloud.com/harmonyos/os/3.1-Beta/hispark_taurus.tar.gz)| [Download](https://repo.huaweicloud.com/harmonyos/os/3.1-Beta/hispark_taurus.tar.gz.sha256)|
| Hi3516 mini system solution - Linux (binary)| 3.1 Beta     | [Download](https://repo.huaweicloud.com/harmonyos/os/3.1-Beta/hispark_taurus_linux.tar.gz)| [Download](https://repo.huaweicloud.com/harmonyos/os/3.1-Beta/hispark_taurus_linux.tar.gz.sha256)|
| Standard system SDK package (macOS)| 3.1 Beta     | [Download](https://repo.huaweicloud.com/harmonyos/os/3.1-Beta/ohos-sdk-mac.tar.gz)| [Download](https://repo.huaweicloud.com/harmonyos/os/3.1-Beta/ohos-sdk-mac.tar.gz.sha256)|
| Standard system SDK package (Windows/Linux)| 3.1 Beta     | [Download](https://repo.huaweicloud.com/harmonyos/os/3.1-Beta/ohos-sdk.tar.gz)| [Download](https://repo.huaweicloud.com/harmonyos/os/3.1-Beta/ohos-sdk.tar.gz.sha256)|
| Compiler toolchain| - | [Download](https://repo.huaweicloud.com/harmonyos/os/2.0/tool_chain/)| - |


## What's New

This version has the following updates to OpenHarmony 3.0 LTS.


### Feature Updates

**Table 3** New and enhanced features

| Subsystem| Standard System| Mini and Small Systems|
| -------- | -------- | -------- |
| Bundle management framework| -&nbsp;I4MBSE: Provides the home screen bundle management client.<br>-&nbsp;I4MBSF: Supports cache clearing.<br>-&nbsp;I4MBSG: Supports installation package information query.<br>-&nbsp;I4MBSD: Supports multi-HAP installation.<br>-&nbsp;I4MBSH: Supports signature verification during multi-HAP installation.<br>-&nbsp;I4MBSC: Supports the **srcPath** field for modules and abilities.| NA |
| Distributed Scheduler subsystem| - I4MBRW: Samgr supports intra-process system ability list control.<br>- I4MBRV: Samgr supports maintenance of the system service status list.<br>- I4MBRZ: Samgr supports initialization of the full service list.<br>- I4MBRY: Samgr supports maintenance of the system process status list.<br>- I4MBRX: Samgr supports loading a specific system service. | NA |
| DeviceProfile subsystem| - I4NY23: Insertion, deletion, and query of local device profiles.<br>- I4NY1X: Query of remote device profiles.<br>- I4NY1T: Subscription to remote profile changes.<br>- I4NY1W: Cross-device profile synchronization. | NA |
| Account subsystem| - I4MBQW: Application account addition and deletion.<br>- I4MBQV: Restrictions on the basic information about application accounts.<br>- I4MBQU: Application account subscription and unsubscription.<br>- I4MBQT: Application account function setting and content modification.<br>- I4MBQS: Application account information query.<br>- I4IT3U: Basic information management for application accounts. | NA |
| Pan-sensor subsystem| - I3NJ96: Acceleration sensor data reporting.<br>- I3NJ8H: Gyroscope sensor data reporting.<br>- I3NJ7J: Ambient light sensor data reporting.<br>- I3NJ76: Magnetic field sensor data reporting.<br>- I4MBRP: Magnetic declination and dip.<br>- I4MBRQ: Horizontal intensity and total intensity of the magnetic field. | NA |
| USB subsystem| I410OZ:<br>-&nbsp;Querying the list of connected USB devices.<br>-&nbsp;Obtaining the temporary permission to access USB devices.<br>-&nbsp;Setting USB device configurations and interfaces.<br>-&nbsp;Data transfer using USB devices.| NA |
| Multi-language Runtime subsystem| -&nbsp;I4MBUK: The default runtime of JS/TS is changed from quickjs to ARK. <br>-&nbsp;I4MBUJ: The memory reclaim capability of ARK runtime is enhanced. The concurrent marking and concurrent compression algorithms are supported. Some regions can be selected for compression GC, reducing the GC pause time by 30%.| NA |
| Globalization subsystem| -&nbsp;Added globalization features: singular and plural rules, string sorting, phone number processing, calendar and local calendar, weights and measures and formatting, locale representations and attributes, time segment formatting, alphabet retrieval, Unicode character attributes, wrapping and line feed.<br>-&nbsp;Supports system resources and rawfile resources.| NA |
| DSoftBus subsystem| - I4FZ29: DSoftBus provides the Ext API for transmission. <br> - I4FZ25: DSoftBus supports network switching. | - I4FZ29: DSoftBus provides the Ext API for transmission. <br> - I4FZ25: DSoftBus supports network switching. |
| Startup subsystem| NA | - I3XGJH: init basic environment building.<br>- I3XGKV: System parameter management.<br>- I3XGLN: init script management.<br>- I3XGMQ: Basic permission management.<br>- I3XGN8: Boot image building and loading.<br>- I3XGKV: uevent management.<br>- I3XGNM: Burning mode. |
| Media subsystem| NA | - I4BX5Z: HiStreamer supports audio playback and control.<br>- I4BX8A: HiStreamer supports playback of MP3 and WAV audio files.<br>- I4BX9E: HiStreamer playback engine framework requirements are met.<br>- I4DK89: HiStreamer plugin framework requirements are met.<br>- I4DK8D: HiStreamer performance and DFX requirements are met. |
| Graphics subsystem| New design of the OpenHarmony graphics stack:<br>Added the background rendering feature to the UI framework.<br>Supports the access to the background rendering module of RenderService from ArkUI components.| NA |
| Kernel subsystem| Kernel (Linux 5.10): <br>- I4LUG4: Supports Contiguous Memory Area (CMA) reuse. (Currently, only Hi3516D V300 is supported.)<br>- I4LX4G: Supports anonymous Virtual Memory Area (VMA) naming. (Currently, only Hi3516D V300 is supported.) | - I3ND6Y: Optimized OS kernel and driver startup performance. |
| Startup subsystem| NA | - I3NTCT: The Linux init process supports hot swap. |
| Distributed Data Management subsystem| NA | - I4H3JJ: Provides distributed objects for small-system devices. |
| Telephony subsystem| NA | - I4JQ2N: Provides HTTP JS APIs.<br>- I4JQ3G: Supports HTTP 2.0. |
| Misc Services subsystem| I4MBQE:<br>Enables applications to read the system time.<br>Enables applications to read the system time zone.<br>Provides time change notifications.<br>Provides time zone change notifications.<br>Provides minute change notifications.| NA |
| Compilation and Building subsystem| - I4K7E3: Provides a unified compilation command as the compilation entry.<br>- I4KCNB: Supports the unified gn template. | - I4MBQN: Supports a unified compilation entry and uses **build.sh** to compile mini- and small-system devices.<br>- I4MBQP: Supports a unified compilation process.<br>- I4MBQR: Supports unified product configuration. |
| File Storage subsystem| - I4MBS2: Provides StatFS JS interfaces for obtaining the total space and free space of a device. | NA |
| Driver subsystem| - I4L3KK: The drive capability of sensor components is enhanced. The sensor sampling rate can be dynamically configured, the three-axis direction can be statically configured, and the ambient light gain can be adjusted. <br>- I4L3LF: The sensor driver model capability is enhanced to support cross-process service obtaining and invoking of sensor HDIs. <br>- I4MBTS: Provides more capabilities for HDF input devices and supports data reporting of joystick devices. <br>- I4MBTR: The default reference implementation of the Display HDI interface for the standard system is provided based on the DRM display architecture, which helps vendors to adapt the HDI. <br>- I4HPR7: Provides the hcs macro parsing mechanism. During compilation, the hc-gen tool is used to parse the driver parameters into parameters involved in the macro definition. The driver accesses these macro definition parameters through the hcs macro-format interface. <br>- I4KVJQ: Supports system-level sleep/wakeup of the Linux and LiteOS kernels. <br>- I4L3ZZF: Supports synchronous/asynchronous power management invoking and provides a synchronous/asynchronous mechanism for HDF device sleep/wakeup management. | - I4L3KK: The drive capability of sensor components is enhanced. The sensor sampling rate can be dynamically configured, the three-axis direction can be statically configured, and the ambient light gain can be adjusted. <br>Provides more capabilities for HDF input devices (running on Linux) and supports data reporting of joystick devices. <br>- I4HPR7: Provides the hcs macro parsing mechanism. During compilation, the hc-gen tool is used to parse the driver parameters into parameters involved in the macro definition. The driver accesses these macro definition parameters through the hcs macro-format interface. <br>- I4KVJQ: Supports system-level sleep/wakeup of the Linux and LiteOS kernels. <br>- I4L3ZZF: Supports synchronous/asynchronous power management invoking and provides a synchronous/asynchronous mechanism for HDF device sleep/wakeup management. |
| ArkUI| - I4MBUY: Added **target** to the event to obtain the size.<br>- I4MBUZ: The **\<Swiper>** component supports cache setting.<br>- I4MBV1: The **\<Image>** component supports synchronous and asynchronous rendering setting.<br>- I4MBV3: Added the component polymorphic style setting to the style setting feature.<br>- I4MBV5: Added the pop-up text for menu content extension to the **\<AlphabetIndexer>** component.<br>- I4MBV6: Added the custom container components to the component customization feature.<br>- I4MBV7: Added scroll bar style customization.<br>- I4MBV8: Added switching forbidden for the **\<Swiper>** component.<br>- I4MBV9: Added tab bar content customization for the **\<Tabs>** component.<br>- I4MBVA: Added title bar setting for the **\<Navigation>** component.<br>- I4MBVB: Added toolbar display/hide control for the **\<toolbar>** component.<br>- I4MBVC: Added content customization for the **\<toolbar>** component.<br>- I4MBVD: Added the SysCap declaration compilation feature.<br>- I4MBVE: Added the JSSDK compilation feature.<br>- I4MBVF: Added the **Config.json** compilation feature.<br>- I4MBVG: Added the breakpoint debugging feature for single-instance debugging.<br>- I4MBVH: Added the attach debugging feature for single-instance debugging.<br>- I4MBVI: Added the declarative paradigm compilation feature to support compilation and verification.<br>- I4MBVJ: Added the JS module shared compilation feature.<br>- I4MBVK: Added the HAR reference and compilation feature.<br>- I4MBVL: Added the HPM reference and compilation feature.<br>- I4MBVN: Added the vertical display of the slider bar.<br>- I4MBVO: Added the content customization feature for the **\<popup>** component.<br>- I4MBVP: Added the drawing capability for the **\<canvas>** component.<br>- I4MBVQ: Enhanced the capabilities of the **\<canvas>** component.<br>- I4MBVR: Added the touch target setting.<br>- I4MBVS: Added the support for Lottie animation.<br>- I4MBVT: Added the feature for obtaining the component size.<br>- I4MBVU: Added content customization to the **\<menu>** component.<br>- I4MBVV: Added the support for the **\<swipe>** gesture.<br>- I4MBVW: Added the inspector capability for UI preview.<br>- I4MBVX: Added the non-route file preview feature.<br>- I4MBVY: Added the NAPI preview feature.<br>- I4MBVZ: Added the declarative paradigm preview feature with the basic preview supported.<br>- I4MBW2: Added the declarative paradigm hot loading feature for modification to the existing nodes.<br>- I4MBW3: Added the declarative paradigm hot loading feature for node addition.<br>- I4MBW4: Added the declarative paradigm hot loading feature for node deletion.<br>- I4MBW5: Added the component preview feature and the page component preview.<br>Added the universal attribute **touchable** to specify whether a component is touchable. <br>Added the basic component **\<Marquee>**. <br>Added the basic component **\<Gauge>**. <br>Added the basic component **\<TextArea>**. <br>Added the basic component **\<TextInput>**. <br>Added the basic component **\<Toggle>**. <br>Added the container component **\<Stepper>**. <br>Added the container component **\<StepperItem>**. <br>Added the global UI method **\<ActionSheet>**.| NA |
| DFX subsystem| - I4MBQH: Added the **HiSysEvent** class and provided the query and subscription interfaces.<br>- I4MBQJ: Provides the tool query or subscription system event.<br>- I4MBQL: Added the C interface of the **HiAppEvent** class. | NA |
| Application subsystems| - I4MBU1: Added **Settings** data management APIs. <br>- I4MBU3: Added time setting. <br>- I4MBU5: Supports sound management. <br>- I4MBU6: Added **Settings** data management. <br>- I4MBU7: Added **Settings** default value management.<br>- I4MBU8: Added differentiated construction of multiple device forms in **Settings**.<br>- I4MBU9: Added component-based notifications. | NA |


### API Updates

For details, see the following:

_[JS API Differences](api-diff/v3.1-beta/js-apidiff-v3.1-beta.md)_

_[Native API Differences](api-diff/v3.1-beta/native-apidiff-v3.1-beta.md)_

_[Changelog](api-diff/v3.1-beta/changelog-v3.1-beta.md)_


### Chip and Development Board Adaptation

For details about the adaptation status, see [SIG_DevBoard](https://gitee.com/openharmony/community/blob/master/sig/sig_devboard/sig_devboard.md).


### Samples &amp; Codelabs


#### New Samples

**Table 4** New samples

| Name| Introduction| Programming Language|
| -------- | -------- | -------- |
| [ArkTS Common Event](https://gitee.com/openharmony/app_samples/tree/master/Notification/CommonEvent) | This sample shows how to use **CommonEvent** APIs in ArkTS to create subscribers and subscribe to, publish, and unsubscribe from common events. | ArkTS |
| [Air Quality](https://gitee.com/openharmony/app_samples/tree/master/common/AirQuality)| This sample implements a simple air quality app using JS. The app displays air quality information using line wrapping and historical data in a bar chart.| JS |
| [Distributed Calculator](https://gitee.com/openharmony/app_samples/tree/master/common/DistributeCalc)| This sample implements a simple calculator app using JS distributed features. The calculator can perform simple numerical calculations and start a remote calculator Feature Ability (FA) to perform collaborative calculation.| JS |
| [ArkTS Notification](https://gitee.com/openharmony/app_samples/tree/master/common/Notification) | This sample shows how to create and delete a slot in ArkTS, and how to publish and cancel a notification. | ArkTS |
| [ArkTS Resource Management](https://gitee.com/openharmony/app_samples/tree/master/common/ResourceManager) | This sample shows how to call resource management APIs in ArkTS to obtain strings and images. | ArkTS |
| [Kika Keyboard](https://gitee.com/openharmony/app_samples/tree/master/CompleteApps/KikaInput) | This sample shows how to implement a lightweight input method app, Kika Keyboard, that can run on smart devices powered by OpenHarmony.| JS |
| [ArkTS Distributed Data Management](https://gitee.com/openharmony/app_samples/tree/master/data/Kvstore) | This sample shows how to use distributed data management in ArkTS, including creating a **KvManager** instance and using KvStore data transfer. | ArkTS |
| [Lightweight Data Storage](https://gitee.com/openharmony/app_samples/tree/master/data/LiteStorage) | Lightweight data storage supports lightweight key-value operations and allows local apps to store a small amount of data. This sample shows how to add offerings to the shopping cart, remove offerings from the shopping cart, and saving the shopping cart. The shopping cart information is retained even when the app is closed. This reflects the lightweight storage feature.| ArkTS |
| [ArkTS Process](https://gitee.com/openharmony/app_samples/tree/master/ETSUI/Process) | This sample shows how to obtain process information and start a child process to run a shell script in ArkTS. With this sample, you can obtain the running time, obtain and change the working directory of a process, send a signal to a specific process, start or close a child process, and exit the current process. | ArkTS |
| [ArkTS Running Lock](https://gitee.com/openharmony/app_samples/tree/master/common/Runninglock) | This sample shows how to test the running lock that prevents the system from entering sleep mode. It uses the black and white wallpapers to simulate the screen-off and screen-on states.| ArkTS |
| [String Codec](https://gitee.com/openharmony/app_samples/tree/master/Util/UtilStringCodec) | This sample shows how to output strings in a specified format and output error codes in text format. It also demonstrates string encoding and decoding.| ArkTS |
| [JS Audio Playback and Management](https://gitee.com/openharmony/app_samples/tree/master/media/JsAudioPlayer)| This sample shows how to use the JS-based audio playback feature and set the volume.| JS |
| [JS Video](https://gitee.com/openharmony/app_samples/tree/master/media/JsVideo) | This sample shows how to use the JS UI component **\<video>** to implement video playback. You can play a video clip and pause the playback through the control bar of the **\<video>** component.| JS |
| [Dot Test](https://gitee.com/openharmony/app_samples/tree/master/DFX/JsDotTest)| This sample illustrates the dot test function, including application dotting and performance dotting.| JS |
| [JS Worker](https://gitee.com/openharmony/app_samples/tree/master/thread/JsWorker) | This sample shows how to start a worker thread in JS and implement the communication between the worker thread and host thread.| JS |
| [canvas Component](https://gitee.com/openharmony/app_samples/tree/master/UI/JsCanvas)| This sample shows how to use the **\<canvas>** component to customize drawings.| JS |
| [JS Dialog](https://gitee.com/openharmony/app_samples/tree/master/UI/JsDialog)| The JS UI component **\<dialog>** allows users to customize the dialog box style and layout. This sample shows how to use a custom dialog box to implement contacts addition and deletion.| JS |
| [JSList Offerings](https://gitee.com/openharmony/app_samples/tree/master/UI/JsList)| This sample shows how to apply **<list\>** component in the offering classification list. In **<listGroup\>**, two **<list-item\>** components are used to display the list in the collapsed and expanded state. After a list is touched, the corresponding list items are displayed.| JS |
| [JS Panel](https://gitee.com/openharmony/app_samples/tree/master/UI/JsPanel) | The JS container component **\<panel>** provides a lightweight, slidable content display panel. The panel attributes such as the triggering mode and display height can be customized. This sample shows how to display the offering details and service guarantee on the panel.| JS |
| [JS svg](https://gitee.com/openharmony/app_samples/tree/master/UI/JsSvg) | This sample shows how to use the JS component **<svg\>** and its child components, including **<rect\>**, **<circle\>**, **<ellipse\>**, **<path\>**, **<line\>**, **<polygon\>**, **<polyline\>**, **<text\>**, **<animate\>**, and **<animateTransform\>**.| JS |
| [Custom JS Components](https://gitee.com/openharmony/app_samples/tree/master/UI/JSUICustomComponent)| Custom components are existing components encapsulated based on service requirements. A custom component can be invoked multiple times in a project to improve the code readability. This sample shows how to use custom JS components, including basic usage, custom events, Props, and event parameters.| JS |


#### New Codelabs

**Table 5** New codelabs

| Name| Introduction| Programming Language|
| -------- | -------- | -------- |
| [Synced Sketchpad (ArkTS)](https://gitee.com/openharmony/codelabs/tree/master/Distributed/DistributeDatabaseDrawEts)| This codelab shows how to implement synchronous writing and interaction between multiple devices based on the distributed feature.| ArkTS |
| [Distributed Database](https://gitee.com/openharmony/codelabs/tree/master/Data/JsDistributedData)| This codelab shows how to use the Distributed Data Service APIs to facilitate consistent data access between devices.| JS |
| [Relational Database](https://gitee.com/openharmony/codelabs/tree/master/Data/JSRelationshipData)| This codelab shows how to quickly develop database-related application services based on the relational database and data management capability.| JS |
| [Shopping (ArkTS)](https://gitee.com/openharmony/codelabs/tree/master/ETSUI/ShoppingEts) | This codelab shows how to implement a shopping app based on OpenHarmony ArkTS UI components. | ArkTS |
| [Transition Animation (ArkTS)](https://gitee.com/openharmony/codelabs/tree/master/ETSUI/TransitionAnimation) | This codelab shows how to implement page transition, component transition, and transition of shared elements based on OpenHarmony ArkUI components. | ArkTS |
| [slider Usage (ArkTS)](https://gitee.com/openharmony/codelabs/tree/master/ETSUI/SliderExample) | This codelab shows how to use the OpenHarmony ArkUI component **\<slider>** to implement the animation effect when users adjust the size and speed of the windmill. | ArkTS |
| [Dialog Box (ArkTS)](https://gitee.com/openharmony/codelabs/tree/master/ETSUI/CustomDialogEts) | This codelab shows how to implement an alert dialog box and custom dialog box based on OpenHarmony ArkTS UI components. | ArkTS |


## Resolved Issues

**Table 6** Resolved issues

| Issue No.| Description|
| -------- | -------- |
| [I48IM7](https://gitee.com/openharmony/hiviewdfx_hilog/issues/I48IM7) | During the hilog pressure test, **hilogd** restarts unexpectedly, and the **hilog** command cannot be used.|
| I48YPH | [DSoftBus - Networking] During the testing of the getting-offline - discovery - networking cycle, there are 3 failures among all the 110 attempts.|
| [I4BVVW](https://gitee.com/openharmony/communication_dsoftbus/issues/I4BVVW) | [DSoftBus - Networking] The success rate of automatic networking between a standard-system device and mobile phone is 97%.|
| I4BXY1 | There is no sound in the first few seconds of a video recording, the sound and image are out of sync, frame freezing occurs, and noises occur when the audio source was far away during recording.|
| [3ZJ1D](https://gitee.com/openharmony/kernel_liteos_a/issues/I3ZJ1D) | There is a possibility that the user mode fails in the XTS pressure test of the permission case.|


## Known Issues

**Table 7** Known issues

| Issue No.| Description| Impact| To Be Resolved On|
| -------- | -------- | -------- | -------- |
| [I4NRS5](https://gitee.com/openharmony/kernel_linux_5.10/issues/I4NRS5) | [Kernel subsystem] A CVE vulnerability exists.| No patch has been released for the Linux kernel. The kernel will be updated after the patch is released in the community.| Depending on the patch release in the community|
| [I4MGJM](https://gitee.com/openharmony/drivers_peripheral/issues/I4MGJM) | [HDF/Camera] The case fails when the RK3568 board runs the camera HDI tests.| The photographing and preview functions are normal. The recording function can be started but cannot be stopped.| 2021/12/31 |
| I4OECR | An Ark stack exception occurs during XTS running (low probability).| There is a low probability that the Ark stack becomes abnormal during the XTS pressure test. This issue occurs only once in 48 hours. The exception stack is reported only in the log and does not affect the functions.| 2022/01/05|
| [I4OBTW](https://gitee.com/openharmony/ability_ability_runtime/issues/I4OBTW) | After all XTS cases are executed and the application is installed, aa start failures occur, affecting the OpenHarmony pipeline stability test.| During the XTS pressure test, when 100 application packages are installed in batches in a short period of time, 2 of them cannot be started. User experience is not affected.| 2022/01/05|
| I4OLHF | [Ark subsystem] The test process is abnormal due to the com.amsst.amsMissionSnapshotTest process.| This issue occurs occasionally during high-pressure tests.| 2022/01/05|
| I4OLUK | [Ark subsystem] The process stack is abnormal due to the com.ohos.systemui process.| This issue occurs occasionally during high-pressure tests.| 2022/01/05|
