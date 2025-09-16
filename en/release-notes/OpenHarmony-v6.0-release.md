# OpenHarmony 6.0 Release


## Version Overview

OpenHarmony 6.0 Release further enhances the capabilities of ArkUI components, providing more secure and flexible component layouts. It strengthens window capabilities by adding support for text display in windows. It improves distributed data management by supporting asset and asset group management, and enables applications to display standardized data. It also enhances location services and input method framework capabilities, among others.

A more detailed description of the enhancements is as follows:


### Application Framework

- AppServiceExtensionAbility module: introduces extended capabilities for background services, including lifecycle callbacks for creation, destruction, connection, and disconnection. ([API Reference](https://gitcode.com/openharmony/docs/blob/OpenHarmony-6.0-Release/en/application-dev/reference/apis-ability-kit/js-apis-app-ability-appServiceExtensionAbility.md))

- Permission management: Applications can now query their own permission status. ([API Reference](https://gitcode.com/openharmony/docs/blob/OpenHarmony-6.0-Release/en/application-dev/reference/apis-ability-kit/js-apis-abilityAccessCtrl.md#getselfpermissionstatus20))

- Decorator intent development: facilitates the integration of existing functionalities into system entry points using decorators. ([Guide](https://gitcode.com/openharmony/docs/blob/OpenHarmony-6.0-Release/en/application-dev/application-models/insight-intent-decorator-development.md))

- Widget development: adds support for interactive widgets. ([Guide](https://gitcode.com/openharmony/docs/blob/OpenHarmony-6.0-Release/en/application-dev/form/arkts-ui-liveform-overview.md))

- Kiosk mode: adds support for kiosk mode. Kiosk mode is a special device lock mode that ensures the device UI serves only specific interaction scenarios. ([Guide](https://gitcode.com/RayShih/docs/blob/master/en/application-dev/reference/apis-ability-kit/js-apis-app-ability-kioskManager.md))

- AppStartup: enhances configuration options in feature-type HAPs and introduces task matching rules. ([Guide](https://gitcode.com/openharmony/docs/blob/OpenHarmony-6.0-Release/en/application-dev/application-models/app-startup.md#supported-scope))

### ArkUI

- Component layout enhancements:

  - Default background extension: automatically extends component backgrounds into non-safe areas, such as **SafeAreaPadding**, AI navigation bars, and status bars, for an immersive experience. ([API Reference](https://gitcode.com/openharmony/docs/blob/OpenHarmony-6.0-Release/en/application-dev/reference/apis-arkui/arkui-ts/ts-universal-attributes-background.md#background20))

  - Ignoring layout margins: allows components to ignore layout margins when adjacent to non-safe areas, such as **SafeAreaPadding**, AI navigation bars, and status bars, providing more flexible layout options. ([API Reference](https://gitcode.com/openharmony/docs/blob/OpenHarmony-6.0-Release/en/application-dev/reference/apis-arkui/arkui-ts/ts-universal-attributes-expand-safe-area.md#ignorelayoutsafearea20))

  - Basic layout capabilities: introduces **LayoutPolicy** for width and height, including **matchParent**, **wrapContent**, and **fitAtIdealSize**. ([API Reference](https://gitcode.com/openharmony/docs/blob/OpenHarmony-6.0-Release/en/application-dev/reference/apis-arkui/arkui-ts/ts-types.md#layoutpolicy15))

- Navigation dual-pane mode: adds support for setting default placeholder pages in **Navigation** dual-pane mode. ([API Reference](https://gitcode.com/openharmony/docs/blob/OpenHarmony-6.0-Release/en/application-dev/reference/apis-arkui/arkui-ts/ts-basic-components-xcomponent.md#lockcanvas20))

- UX visual effects optimization: optimizes menu positioning during drag operations, ensuring smooth transitions and reasonable spacing between the menu and drag image. Components now support P3 color gamut display.

- XComponent canvas access: The new **lockCanvas** API allows you to directly draw on the XComponent using an ArkTS object, simplifying the drawing process. ([API Reference](https://gitcode.com/openharmony/docs/blob/OpenHarmony-6.0-Release/en/application-dev/reference/apis-arkui/js-apis-arkui-frameNode.md#cancelanimations20))

- Implicit animation cancellation: provides the capability to cancel implicit animations. ([API Reference](https://gitcode.com/openharmony/docs/blob/OpenHarmony-6.0-Release/en/application-dev/reference/apis-arkui/js-apis-arkui-frameNode.md#cancelanimations20))

- Customization for **SaveButton** components: adds support for customizing icons and text in **SaveButton** components. ([API Reference](https://gitcode.com/openharmony/docs/blob/OpenHarmony-6.0-Release/en/application-dev/reference/apis-arkui/arkui-ts/ts-security-components-savebutton.md#savebuttonattribute))

- Gesture event reporting: supports comprehensive gesture event reporting, including basic gesture recognition, long press, pinch, rotate, and swipe. ([API Reference](https://gitcode.com/openharmony/docs/blob/OpenHarmony-6.0-Release/en/application-dev/reference/apis-arkui/arkts-apis-uicontext-uiobserver.md#onwillclick12))

- Rendering node capabilities in NDK: enhances rendering node capabilities, including creation, mounting, rendering properties, custom drawing, redrawing, drawing priority, and dirty region clipping, along with property animations and event interception. ([API Reference](https://gitcode.com/openharmony/docs/blob/OpenHarmony-6.0-Release/en/application-dev/reference/apis-arkui/capi-native-render-h.md))


### ArkWeb

- Chromium kernel upgrade: upgrades the Chromium kernel from version 114 to 132.  

- Enhanced interaction capabilities: introduces features like disabling zoom with modifier keys, forced gesture zoom, gesture focus, and custom text menus.

- PointerEvent for stylus: adds support for PointerEvent for stylus input.

- Custom error pages: allows returning custom error pages for network loading errors. ([API Reference](https://gitcode.com/openharmony/docs/blob/OpenHarmony-6.0-Release/en/application-dev/reference/apis-arkweb/arkts-basic-components-web-events.md#onoverrideerrorpage20))


### Window Management

- Focus management: Windows can now default to not gaining focus on display, with focus gained upon click. ([API Reference](https://gitcode.com/openharmony/docs/blob/OpenHarmony-6.0-Release/en/application-dev/reference/apis-arkui/js-apis-window.md#showwindow20))

- Input method animation callbacks: adds callbacks for input method animations, facilitating smoother transitions. ([API Reference](https://gitcode.com/openharmony/docs/blob/OpenHarmony-6.0-Release/en/application-dev/reference/apis-arkui/js-apis-window.md#onkeyboardwillshow20))

- Custom font unloading: introduces C API support for unloading custom fonts to free up memory. ([API Reference](https://gitcode.com/openharmony/docs/blob/OpenHarmony-6.0-Release/en/application-dev/reference/apis-arkgraphics2d/capi-drawing-register-font-h.md#oh_drawing_unregisterfont))

- Text vertical alignment: adds support for setting text vertical alignment. ([API Reference](https://gitcode.com/openharmony/docs/blob/OpenHarmony-6.0-Release/en/application-dev/reference/apis-arkgraphics2d/js-apis-graphics-text.md#textverticalalign20))

- Copying styles and shadows: enables copying of paragraph styles, text styles, and text shadow objects. ([API Reference](https://gitcode.com/openharmony/docs/blob/OpenHarmony-6.0-Release/en/application-dev/reference/apis-arkgraphics2d/capi-drawing-text-typography-h.md#oh_drawing_copytypographystyle))

- Shaping by individual characters: supports shaping text by individual characters, enhancing text rendering. ([API Reference](https://gitcode.com/openharmony/docs/blob/OpenHarmony-6.0-Release/en/application-dev/reference/apis-arkgraphics2d/capi-drawing-text-run-h.md#oh_drawing_getrunfont))

### Graphics

- Automatic spacing for Chinese and western text: automatically adjusts spacing between Chinese and western characters and removes leading spaces during layout. Also, supports changing text color without re-layout and not following the system's high-contrast text switch settings. ([API Reference](https://gitcode.com/openharmony/docs/blob/OpenHarmony-6.0-Release/en/application-dev/reference/apis-arkgraphics2d/js-apis-graphics-text.md#paragraphstyle))

- HDR encoding for ASTC: adds support for HDR quality encoding in ASTC image encoding. ([API Reference](https://gitcode.com/openharmony/docs/blob/OpenHarmony-6.0-Release/en/application-dev/reference/apis-image-kit/arkts-apis-image-i.md#packingoption))

- HDR brightening for components: introduces HDR brightening effects for component content, enhancing visual quality. ([API Reference](https://gitcode.com/openharmony/docs/blob/OpenHarmony-6.0-Release/en/application-dev/reference/apis-arkgraphics2d/js-apis-uiEffect-sys.md#hdrbrightnessratio20))

- NativeFence interface: provides operations for blocking fenceFd, including setting a specified time, permanent blocking, closing, and checking validity. ([Guide](https://gitcode.com/openharmony/docs/blob/OpenHarmony-6.0-Release/en/application-dev/graphics/native-fence-guidelines.md))

### Bundle Management

- Shortcut visibility: introduces the **setShortcutVisibleForSelf** API to control the visibility of the current application's shortcuts. ([API Reference](https://gitcode.com/openharmony/docs/blob/OpenHarmony-6.0-Release/en/application-dev/reference/apis-ability-kit/js-apis-shortcutManager.md))

- Ability information retrieval: adds the **getAbilityInfo** API to retrieve application ability information based on a specified URI. ([API Reference](https://gitcode.com/openharmony/docs/blob/OpenHarmony-6.0-Release/en/application-dev/reference/apis-ability-kit/js-apis-bundleManager.md#bundlemanagergetabilityinfo20))


### Distributed Data Management

- Asset and asset group management: adds APIs for managing assets and asset groups. ([Guide](https://gitcode.com/openharmony/docs/blob/OpenHarmony-6.0-Release/en/application-dev/database/data-sync-of-distributed-data-object.md#asset-sync-mechanism))

- Standard widget interface: provides standard widget interfaces based on standardized data structures for visualizing data.

- UDMF enhancements: introduces lifecycle management capabilities for DataHub, system sharing, picker, and context menu data channels, with ArkTS and C API support. ([API Reference - ArkTS APIs](https://gitcode.com/openharmony/docs/blob/OpenHarmony-6.0-Release/en/application-dev/reference/apis-arkdata/js-apis-data-unifiedDataChannel.md#intention), [API Reference - C APIs](https://gitcode.com/openharmony/docs/blob/OpenHarmony-6.0-Release/en/application-dev/reference/apis-arkdata/capi-udmf-h.md#enum-description))
  Note: DataHub is only added in C APIs; ArkTS is already supported.

- Attachment transfer progress: adds support for listening for attachment transfer progress and resuming transfers. ([API Reference](https://gitcode.com/openharmony/docs/blob/OpenHarmony-6.0-Release/en/application-dev/reference/apis-arkdata/js-apis-data-distributedobject.md#onprogresschanged20))


### DSoftBus

Enhanced connection capabilities: introduces new low-level connection capability interfaces to enhance connection capabilities. ([Guide](https://gitcode.com/openharmony/docs/blob/OpenHarmony-6.0-Release/en/application-dev/distributedservice/linnkEnhance_development-guide.md))


### Distributed Services

Local device name retrieval: adds C API support for retrieving the local device name. ([API Reference](https://gitcode.com/openharmony/docs/blob/OpenHarmony-6.0-Release/en/application-dev/reference/apis-distributedservice-kit/capi-devicemanager.md))

### Distributed Device Management

Mechanical device management: introduces a mechanical device management service for smart mechanical accessories like pan-tilt units and robotic arms, providing interaction and control capabilities. ([Guide](https://gitcode.com/openharmony/docs/tree/master/en/application-dev/reference/apis-mechanic-kit))


### Common Event and Notification

Third-party application notification settings: adds support for third-party applications to retrieve notification ringtone and vibration settings. ([API Reference](https://gitcode.com/openharmony/docs/blob/OpenHarmony-6.0-Release/en/application-dev/reference/apis-notification-kit/js-apis-notificationManager.md#notificationmanagergetnotificationsetting20))


### Compiler and Runtime

- Memory leak detection: introduces capabilities for detecting memory leaks in system JSVM engine API calls. ([Guide](https://gitcode.com/openharmony/docs/blob/OpenHarmony-6.0-Release/en/application-dev/napi/jsvm-frequently-questions.md))

- FastBuffer object: introduces the FastBuffer object, a more efficient buffer container for representing fixed-length byte sequences, specifically designed for storing binary data. ([Guide](https://gitcode.com/openharmony/docs/blob/OpenHarmony-6.0-Release/en/application-dev/reference/apis-arkts/js-apis-fastbuffer.md))

- Dynamic XML serialization: adds support for generating XML files using dynamic serialization. ([API Reference](https://gitcode.com/openharmony/docs/blob/OpenHarmony-6.0-Release/en/application-dev/reference/apis-arkts/js-apis-xml.md))


### Basic Communications

Wi-Fi connection confirmation: adds support for prompting confirmation when connecting to a candidate network and providing a callback for confirmation. ([API Reference](https://gitcode.com/openharmony/docs/blob/OpenHarmony-6.0-Release/en/application-dev/reference/apis-connectivity-kit/js-apis-wifiManager.md#wifimanagerconnecttocandidateconfigwithuseraction20))


### Location Services

Straight-line distance calculation: adds support for calculating the straight-line distance between two locations. ([API Reference](https://gitcode.com/openharmony/docs/blob/OpenHarmony-6.0-Release/en/application-dev/reference/apis-location-kit/js-apis-geoLocationManager.md#geolocationmanagergetdistancebetweenlocations20))


### Multimodal Input

- Mouse coordinate API: adds C API support for retrieving the coordinates of the mouse on the screen. ([API Reference](https://gitcode.com/openharmony/docs/blob/OpenHarmony-6.0-Release/en/application-dev/reference/apis-input-kit/capi-oh-input-manager-h.md#oh_input_getpointerlocation))

- Touchscreen reporting rate: adds C API support for querying the maximum number of touch reports supported by the device. ([API Reference](https://gitcode.com/openharmony/docs/blob/OpenHarmony-6.0-Release/en/application-dev/reference/apis-input-kit/capi-oh-input-manager-h.md#oh_input_querymaxtouchpoints))

- Relative coordinate system: adds C API support for setting and querying mouse and touchscreen events in a relative coordinate system on a specified screen. For details, search for "relative coordinate system" in [API Reference](https://gitcode.com/openharmony/docs/blob/OpenHarmony-6.0-Release/en/application-dev/reference/apis-input-kit/capi-oh-input-manager-h.md).

### DFX

- HiDebug stack trace: introduces support for using HiDebug to perform stack traces on the application's main thread. ([Guide](https://gitcode.com/openharmony/docs/blob/OpenHarmony-6.0-Release/en/application-dev/dfx/hidebug-guidelines-ndk.md#obtaining-stack-information))

- Sanitizer event integration: supports integrating sanitizer events with HiAppEvent. ([Guide](https://gitcode.com/openharmony/docs/blob/OpenHarmony-6.0-Release/en/application-dev/dfx/hiappevent-watcher-address-sanitizer-events.md))

- CPP_CRASH event configuration: adds support for setting parameters to control log content via the **SetEventConfig** API. ([Guide](https://gitcode.com/openharmony/docs/blob/OpenHarmony-6.0-Release/en/application-dev/dfx/hiappevent-watcher-crash-events.md#customizing-crash-log-specifications))

- Page transition history: For applications with page transitions, fault log files will include page transition history. ([Guide](https://gitcode.com/openharmony/docs/blob/OpenHarmony-6.0-Release/en/application-dev/dfx/cppcrash-guidelines.md#faults-with-page-switching-history))

- **addProcessorFromConfig** API: adds support for asynchronously adding data processors and their configuration information. ([API Reference](https://gitcode.com/openharmony/docs/blob/OpenHarmony-6.0-Release/en/application-dev/reference/apis-performance-analysis-kit/js-apis-hiviewdfx-hiappevent.md#hiappeventaddprocessorfromconfig20))

- HiAppEvent C APIs: adds the **EVENT_APP_KILLED** API for subscribing to application termination events. ([API Reference](https://gitcode.com/openharmony/docs/blob/OpenHarmony-6.0-Release/en/application-dev/reference/apis-performance-analysis-kit/capi-hiappevent-event-h.md#event_app_killed))

### Update

Streaming physical A/B upgrade: introduces streaming physical A/B upgrades, allowing for simultaneous download and installation to reduce storage space usage on user devices. ([Description](https://gitee.com/openharmony/update_updater/blob/master/README.md))


### Media

- Live streaming ROI encoding: adds support for high-quality ROI encoding in live streaming scenarios. ([Guide](https://gitcode.com/openharmony/docs/blob/OpenHarmony-6.0-Release/en/application-dev/media/avcodec/video-encoding-ROI.md))

- Texture data support: Image creation supports texture data as input and output, with customizable textures. ([Guide](https://gitcode.com/openharmony/docs/blob/OpenHarmony-6.0-Release/en/application-dev/media/image/image-effect-guidelines.md))

- Media metadata and thumbnails: adds support for querying media metadata and thumbnails from network streams.

- Camera white balance: adds support for querying and setting camera white balance.

- Camera pressure management: introduces camera pressure management APIs for reporting system pressure status.

### Audio

- Audio engine 2.0: upgrades the audio engine to version 2.0, improving overall efficiency and reducing playback latency.

- Audio workgroup management: adds support for applications to enhance their audio thread's system supply to achieve better audio processing performance. ([Guide](https://gitcode.com/openharmony/docs/blob/OpenHarmony-6.0-Release/en/application-dev/media/audio/audio-workgroup.md))

- Low-latency audio monitoring: adds support for low-latency audio monitoring, enabling real-time audio transmission to wired headphones with lower latency. ([Guide](https://gitcode.com/openharmony/docs/blob/OpenHarmony-6.0-Release/en/application-dev/media/audio/audio-ear-monitor-loopback.md))

- NFC audio playback and recording: adds support for playback and recording on NFC audio devices, allowing applications to query the current audio output type as an NFC device type.

- High-quality AEC for live streaming: adds support for high-definition AEC recording in live streaming scenarios, enabling applications to use the new live streaming recording stream type.


### Security

- Certificate management: introduces the **openAuthorizeDialog** API to launch a user certificate authorization dialog box. After user authorization, applications can use the authorized certificate credentials for two-way TLS authentication or document signing. ([API Reference](https://gitcode.com/openharmony/docs/blob/OpenHarmony-6.0-Release/en/application-dev/reference/apis-device-certificate-kit/js-apis-certManagerDialog.md#certificatemanagerdialogopenauthorizedialog20))

- Crypto framework: The crypto framework provides C APIs for asymmetric encryption/decryption, signing, key agreement, key derivation, message authentication codes, and random number generation. It also supports conversion between ASN1 and R|S formatted sm2 signature data and adds support for the DES algorithm. ([Guide](https://gitcode.com/openharmony/docs/blob/OpenHarmony-6.0-Release/en/application-dev/security/CryptoArchitectureKit/Readme-CN.md))

- Certificate framework: adds support for retrieving the issuer name of certificates or certificate revocation lists in UTF-8 encoding. ([API Reference](https://gitcode.com/openharmony/docs/blob/OpenHarmony-6.0-Release/en/application-dev/reference/apis-device-certificate-kit/js-apis-cert.md#tostring20))

- Certificate chain verification: adds support for trusting system-preinstalled root certificates. ([API Reference](https://gitcode.com/openharmony/docs/blob/OpenHarmony-6.0-Release/en/application-dev/reference/apis-device-certificate-kit/js-apis-cert.md#certchainvalidationparameters11))

### Network Management

Network probing and tracing: adds C API support for network probing ([API Reference](https://gitcode.com/openharmony/docs/blob/OpenHarmony-6.0-Release/en/application-dev/reference/apis-network-kit/capi-net-connection-h.md#oh_netconn_queryproberesult)) and tracing routes ([API Reference](https://gitcode.com/openharmony/docs/blob/OpenHarmony-6.0-Release/en/application-dev/reference/apis-network-kit/capi-net-connection-h.md#oh_netconn_querytraceroute)).

### Test Framework

- White-box performance testing: introduces a white-box performance testing framework that supports measuring CPU/memory usage for specified code segments, application cold start response time, and frame rates in scrolling scenarios. ([API Reference](https://gitcode.com/openharmony/docs/blob/OpenHarmony-6.0-Release/en/application-dev/reference/apis-test-kit/js-apis-perftest.md))

- Multi-screen UI testing: adds support for finding components and simulating operations on specified screens in multi-screen scenarios. ([API Reference](https://gitcode.com/openharmony/docs/blob/OpenHarmony-6.0-Release/en/application-dev/reference/apis-test-kit/js-apis-uitest.md#belongingdisplay20))

- Text input UI testing: adds support for optional text input in text input scenarios. ([API Reference](https://gitcode.com/openharmony/docs/blob/OpenHarmony-6.0-Release/en/application-dev/reference/apis-test-kit/js-apis-uitest.md#inputtextmode20))

### Input Method Framework

- Floating soft keyboard and candidate window: adds support for **startMoving** in floating soft keyboards and candidate word windows. ([API Reference](https://gitcode.com/openharmony/docs/blob/OpenHarmony-6.0-Release/en/application-dev/reference/apis-ime-kit/js-apis-inputmethodengine.md#startmoving15))

- Input method management via hdc command: adds support for managing input methods using the hdc command. ([Guide](https://gitcode.com/openharmony/docs/blob/OpenHarmony-6.0-Release/en/application-dev/inputmethod/inputmethod-hdc-commands-guide.md))

- Abandoning text input: adds support for abandoning ongoing text input in edit boxes. ([API Reference](https://gitcode.com/openharmony/docs/blob/OpenHarmony-6.0-Release/en/application-dev/reference/apis-ime-kit/js-apis-inputmethod.md#discardtypingtext20))

- Perceiving placeholder text and ability name: adds support for perceiving placeholder text in edit boxes and the name of the associated ability. ([API Reference](https://gitcode.com/openharmony/docs/blob/OpenHarmony-6.0-Release/en/application-dev/reference/apis-ime-kit/js-apis-inputmethodengine.md#editorattribute))

- SMS verification code edit box: adds support for SMS verification code edit boxes. ([API Reference](https://gitcode.com/openharmony/docs/blob/OpenHarmony-6.0-Release/en/application-dev/reference/apis-ime-kit/js-apis-inputmethod.md#textinputtype10))

- Automatic capitalization mode: adds support for automatic capitalization mode. ([API Reference](https://gitcode.com/openharmony/docs/blob/OpenHarmony-6.0-Release/en/application-dev/reference/apis-ime-kit/js-apis-inputmethodengine.md#capitalizemode20))

### Upload and Download

Task management: adds support for setting task timeouts, rate limiting, and downloading data to public files. ([API Reference](https://gitcode.com/openharmony/docs/blob/OpenHarmony-6.0-Release/en/application-dev/reference/apis-basic-services-kit/js-apis-request.md#minspeed20))

### Power Management

- System API for device activity: adds a system API to refresh the device activity status (for example, resetting screen timeout). ([API Reference](https://gitcode.com/openharmony/docs/blob/OpenHarmony-6.0-Release/en/application-dev/reference/apis-basic-services-kit/js-apis-power-sys.md#powerrefreshactivity20))

- Power mode enumeration: adds a custom power-saving mode to the power mode enumeration. ([API Reference](https://gitcode.com/openharmony/docs/blob/OpenHarmony-6.0-Release/en/application-dev/reference/apis-basic-services-kit/js-apis-power.md#devicepowermode9))


## Version Mapping

**Table 1** Version mapping of software and tools

| Software/Tool| Version| Remarks|
| -------- | -------- | -------- |
| OpenHarmony | 6.0 Release | NA |
| Public SDK | Ohos_sdk_public 6.0.0.47 (API Version 20 Release) | This toolkit is intended for application developers and does not contain system APIs that require system permissions. It is provided as standard in DevEco Studio.|
| (Optional) HUAWEI DevEco Studio| 6.0.0 Release | Recommended for developing OpenHarmony applications.<br>*To be provided after release.*|
| (Optional) HUAWEI DevEco Device Tool| 4.0 Release | Recommended for developing OpenHarmony smart devices<br>[Click here](https://device.harmonyos.com/cn/develop/ide#download).|


## Source Code Acquisition


### Prerequisites

1. Register your account with Gitee.

2. Register an SSH public key for access to Gitee.

3. Install the [git client](https://git-scm.com/book/en/v2/Getting-Started-Installing-Git) and [git-lfs](https://gitee.com/vcs-all-in-one/git-lfs?_from=gitee_search#downloading), and configure user information.
   ```
   git config --global user.name "yourname"
   git config --global user.email "your-email-address"
   git config --global credential.helper store
   ```

4. Install the **repo** tool.
   ```
   curl -s https://gitee.com/oschina/repo/raw/fork_flow/repo-py3 > /usr/local/bin/repo  # If you do not have the permission, download the tool to another directory and add that directory to environment variables. chmod a+x /usr/local/bin/repo
   pip3 install -i https://repo.huaweicloud.com/repository/pypi/simple requests
   ```


### Acquiring Source Code Using the repo Tool

**Method 1: Using SSH (Recommended)**

Use the **repo** tool to download the source code over SSH. (You must have an SSH public key for access to Gitee.)

- Obtain the source code from the version branch. You can obtain the latest source code of the specified version branch, which includes all changes up to the time you run the commands.
   ```
   repo init -u git@gitee.com:openharmony/manifest.git -b OpenHarmony-6.0-Release --no-repo-verify
   repo sync -c
   repo forall -c 'git lfs pull'
   ```
   
- Obtain the source code from the version tag, which is the same as that released with the version.
   ```
   repo init -u git@gitee.com:openharmony/manifest.git -b refs/tags/OpenHarmony-v6.0-Release --no-repo-verify
   repo sync -c
   repo forall -c 'git lfs pull'
   ```

**Method 2**

Use the **repo** tool to download the source code over HTTPS.

- Obtain the source code from the version branch. You can obtain the latest source code of the specified version branch, which includes all changes up to the time you run the commands.
   ```
   repo init -u https://gitee.com/openharmony/manifest -b OpenHarmony-6.0-Release --no-repo-verify
   repo sync -c
   repo forall -c 'git lfs pull'
   ```
   
- Obtain the source code from the version tag, which is the same as that released with the version.
   ```
   repo init -u https://gitee.com/openharmony/manifest -b refs/tags/OpenHarmony-v6.0-Release --no-repo-verify
   repo sync -c
   repo forall -c 'git lfs pull'
   ```


### Acquiring Source Code from Mirrors


**Table 2** Mirrors for acquiring source code

| Source Code                               | Version| Mirror                                                | SHA-256 Checksum                                            | Software Package Size|
| --------------------------------------- | ------------ | ------------------------------------------------------------ | ------------------------------------------------------------ | -------- |
| Full code base (for mini, small, and standard systems)       | 6.0 Release    | [Download](https://repo.huaweicloud.com/openharmony/os/6.0-Release/code-v6.0-Release.tar.gz) | [Download](https://repo.huaweicloud.com/openharmony/os/6.0-Release/code-v6.0-Release.tar.gz.sha256) | 54.7 GB |
| Hi3861 solution (binary)       | 6.0 Release    | [Download](https://repo.huaweicloud.com/openharmony/os/6.0-Release/hispark_pegasus.tar.gz) | [Download](https://repo.huaweicloud.com/openharmony/os/6.0-Release/hispark_pegasus.tar.gz.sha256) | 28.8 MB |
| Hi3516 solution-LiteOS (binary)| 6.0 Release    | [Download](https://repo.huaweicloud.com/openharmony/os/6.0-Release/hispark_taurus_LiteOS.tar.gz) | [Download](https://repo.huaweicloud.com/openharmony/os/6.0-Release/hispark_taurus_LiteOS.tar.gz.sha256) | 353.5 MB |
| Hi3516 solution-Linux (binary) | 6.0 Release    | [Download](https://repo.huaweicloud.com/openharmony/os/6.0-Release/hispark_taurus_Linux.tar.gz) | [Download](https://repo.huaweicloud.com/openharmony/os/6.0-Release/hispark_taurus_Linux.tar.gz.sha256) | 235.1 MB |
| RK3568 standard system solution (binary) ROM package       | 6.0 Release    | [Download](https://repo.huaweicloud.com/openharmony/os/6.0-Release/dayu200_standard_arm32_rom.tar.gz) | [Download](https://repo.huaweicloud.com/openharmony/os/6.0-Release/dayu200_standard_arm32_rom.tar.gz.sha256) | 	3.6 GB |
| RK3568 standard system solution (binary) XTS package       | 6.0 Release    | [Download](https://repo.huaweicloud.com/openharmony/os/6.0-Release/dayu200_standard_arm32_xts.tar.gz) | [Download](https://repo.huaweicloud.com/openharmony/os/6.0-Release/dayu200_standard_arm32_xts.tar.gz.sha256) | 	4.1 GB |
| Public SDK package for the standard system (macOS)            | 6.0.0.47 | [Download](https://repo.huaweicloud.com/openharmony/os/6.0-Release/ohos-sdk-mac-public.tar.gz) | [Download](https://repo.huaweicloud.com/openharmony/os/6.0-Release/ohos-sdk-mac-public.tar.gz.sha256) | 1.3 GB |
| Public SDK package for the standard system (macOS-M1)            | 6.0.0.47  | [Download](https://repo.huaweicloud.com/openharmony/os/6.0-Release/L2-SDK-MAC-M1-PUBLIC.tar.gz) | [Download](https://repo.huaweicloud.com/openharmony/os/6.0-Release/L2-SDK-MAC-M1-PUBLIC.tar.gz.sha256) | 1.2 GB |
| Public SDK package for the standard system (Windows/Linux)  | 6.0.0.47   | [Download](https://repo.huaweicloud.com/openharmony/os/6.0-Release/ohos-sdk-windows_linux-public.tar.gz) | [Download](https://repo.huaweicloud.com/openharmony/os/6.0-Release/ohos-sdk-windows_linux-public.tar.gz.sha256) | 	2.3 GB |


## Resolved Issues

**Table 3** Resolved issues

| Issue No.| Issue|
| ------- | ------- |
| ICAWPJ | During XTS testing, a callback (a local function of a case) registered with **on** was not unregistered with **off**. Later cases triggered this callback, but it failed due to the referenced JS function being destructed, causing test failures.|
| ICD55I | During XTS testing, the ActsTelephonyContactTest suite failed due to a timeout when the contact service of the RK3568 development board accessed datashare.|
| ICENKX | During XTS testing, the service code of asset creation APIs was not distinguished, leading to test failures.|
| ICE0E0 | The com.ohos.systemui process frequently freezes due to INPUT_EVENT_SOCKET_TIMEOUT.|
| ICCUL7 | The OS_IPC_1_743 thread in the /system/bin/bootanimation process occasionally crashes due to libaccessibilityconfig.z.so crashing.|
| ICCXYS | The OS_IPC_6_979 thread in the foundation process rarely crashes due to libhilog.so crashing.|


## Known Issues

**Table 4** Known issues

| Issue No.| Issue| Impact| To Be Resolved By|
| -------- | -------- | -------- | -------- |
| ICW13P | The sliding comment section in Douyin-like applications runs at 43 fps, not meeting the baseline requirement.| Slightly impacts user experience.| 2025-09-30|
| ICW0P4 | The boot completion delay is slightly worse than the earlier version.| Slightly impacts user experience.| 2025-09-30|
| ICW129 | The contact list sliding frame rate is 42 fps, not meeting the baseline requirement.| Slightly impacts user experience.| 2025-12-30|
| ICV8O8 | The com.ohos.systemui process experiences memory leaks during wukong stress testing.| System anomalies, recoverable by rebooting.| 2025-09-30|
| ICWA4N<br>ICWA56 | The com.ohos.mms process occasionally crashes due to anonymous or deleteAction.| SMS app anomalies, recoverable by restarting the application.| 2025-09-30|
| ICUCVF | The hilogd.server thread in the /system/bin/hilogd process rarely crashes.| HiLog logging anomalies, recoverable by rebooting.| 2025-09-30|
| ICW9XX | The m.ohos.contacts thread in the com.ohos.contacts process rarely crashes due to libace_compatible.z.so.| Contacts application anomalies, recoverable by restarting the application.| 2025-09-30|
