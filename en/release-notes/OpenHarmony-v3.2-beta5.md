# OpenHarmony 3.2 Beta5


## Version Description

OpenHarmony 3.2 Beta5 provides the following enhancements over OpenHarmony 3.2 Beta4:

**Enhanced basic capabilities for the standard system**

The startup performance of the WebView component is optimized. Configuration management and input event support capabilities are enhanced. JSON files can be imported and loaded in modular mode.

The task pool and the TS2AOT-tool of the host version are provided. The dynamic library of the HAP package can be loaded without being compressed. The compiler runtime supports shared packages in the same application.

The dynamic shared library can be installed, updated, uninstalled, packed, and unpacked. For an application that is not configured with an entry icon, a default icon is displayed on the home screen. The runtime capability of the HAR shared package can be verified.

The local database is changed for widgets. Protection against frequent restart is provided for applications. The ServiceExtensionAbility component supports the asynchronous **onConnected** lifecycle.

Binding and authentication between local accounts and domain accounts are supported. A basic framework is provided for domain account management services. Direct creation of local users is forbidden.

The capabilities for controlling power indicators and lights are provided.

The HDI driver display layer supports horizontal mirroring and vertical mirroring.

**Enhanced application development framework for the standard system**

The process of compiling the shared package is added to the toolchain.

ArkUI supports obtaining of resources by resource name.

The component supports multi-level menus and group menus.

The process of compiling the HAR package is added.

The HAP compilation process is adapted so that .d.ets declaration files can be identified during HAP compilation.

**Enhanced distributed capabilities for the standard system**

BLE connection parameters can be configured, and the connection process is optimized.


## Version Mapping

**Table 1** Version mapping of software and tools

| Software/Tool| Version| Remarks|
| -------- | -------- | -------- |
| OpenHarmony | 3.2 Beta5 | NA |
| Public SDK | Ohos_sdk_public 3.2.10.6 (API Version 9 Beta5) | This toolkit is intended for application developers and does not contain system APIs that require system permissions.<br>It is provided as standard in DevEco Studio.|
| (Optional) HUAWEI DevEco Studio| 3.1 Beta1 | Recommended for developing OpenHarmony applications |
| (Optional) HUAWEI DevEco Device Tool| 3.1 Beta2 | Recommended for developing OpenHarmony smart devices |


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

4. Run the following commands to install the **repo** tool:
  
   ```
   curl -s https://gitee.com/oschina/repo/raw/fork_flow/repo-py3 > /usr/local/bin/repo  # If you do not have the permission, download the tool to another directory and configure it as an environment variable by running the chmod a+x /usr/local/bin/repo command.
   pip3 install -i https://repo.huaweicloud.com/repository/pypi/simple requests
   ```


### Acquiring Source Code Using the repo Tool

**Method 1 (recommended)**

Use the **repo** tool to download the source code over SSH. (You must have an SSH public key for access to Gitee.)

- Obtain the source code from the version branch. You can obtain the latest source code of the version branch, which includes the code that has been incorporated into the branch up until the time you run the following commands:
   ```
   repo init -u git@gitee.com:openharmony/manifest.git -b OpenHarmony-3.2-Beta5 --no-repo-verify
   repo sync -c
   repo forall -c 'git lfs pull'
   ```
   
- Obtain the source code from the version tag, which is the same as that released with the version.
   ```
   repo init -u git@gitee.com:openharmony/manifest.git -b refs/tags/OpenHarmony-v3.2-Beta5 --no-repo-verify
   repo sync -c
   repo forall -c 'git lfs pull'
   ```

**Method 2**

Use the **repo** tool to download the source code over HTTPS.

- Obtain the source code from the version branch. You can obtain the latest source code of the version branch, which includes the code that has been incorporated into the branch up until the time you run the following commands:
   ```
   repo init -u https://gitee.com/openharmony/manifest -b OpenHarmony-3.2-Beta5 --no-repo-verify
   repo sync -c
   repo forall -c 'git lfs pull'
   ```
   
- Obtain the source code from the version tag, which is the same as that released with the version.
   ```
   repo init -u https://gitee.com/openharmony/manifest -b refs/tags/OpenHarmony-v3.2-Beta5 --no-repo-verify
   repo sync -c
   repo forall -c 'git lfs pull'
   ```


### Acquiring Source Code from Mirrors

**Table 2** Mirrors for acquiring source code

| Source Code                               | Version| Mirror                                                | SHA-256 Checksum                                            | Software Package Size|
| --------------------------------------- | ------------ | ------------------------------------------------------------ | ------------------------------------------------------------ | -------- |
| Full code base (for mini, small, and standard systems)       | 3.2 Beta5    | [Download](https://repo.huaweicloud.com/harmonyos/os/3.2-Beta5/code-v3.2-Beta5.tar.gz) | [Download](https://repo.huaweicloud.com/harmonyos/os/3.2-Beta5/code-v3.2-Beta5.tar.gz.sha256) | 21.3 GB |
| Hi3861 solution (binary)       | 3.2 Beta5    | [Download](https://repo.huaweicloud.com/harmonyos/os/3.2-Beta5/hispark_pegasus.tar.gz) | [Download](https://repo.huaweicloud.com/harmonyos/os/3.2-Beta5/hispark_pegasus.tar.gz.sha256) | 22.9 MB |
| Hi3516 solution-LiteOS (binary)| 3.2 Beta5    | [Download](https://repo.huaweicloud.com/openharmony/os/3.2-Beta5/hispark_taurus_LiteOS.tar.gz) | [Download](https://repo.huaweicloud.com/openharmony/os/3.2-Beta5/hispark_taurus_LiteOS.tar.gz.sha256) | 293.6 MB |
| Hi3516 solution-Linux (binary) | 3.2 Beta5    | [Download](hispark_taurus_Linux.tar.gz) | [Download](https://repo.huaweicloud.com/openharmony/os/3.2-Beta5/hispark_taurus_Linux.tar.gz.sha256) | 174.3 MB |
| RK3568 standard system solution (binary)       | 3.2 Beta5    | [Download](https://repo.huaweicloud.com/harmonyos/os/3.2-Beta5/dayu200_standard_arm32_20230201.tar.gz) | [Download](https://repo.huaweicloud.com/harmonyos/os/3.2-Beta5/dayu200_standard_arm32_20230201.tar.gz.sha256) | 3.9 GB |
| Public SDK package for the standard system (macOS)            | 3.2.10.6      | [Download](https://repo.huaweicloud.com/harmonyos/os/3.2-Beta5/ohos-sdk-mac-public.tar.gz) | [Download](https://repo.huaweicloud.com/harmonyos/os/3.2-Beta5/ohos-sdk-mac-public.tar.gz.sha256) | 674.5 MB |
| Public SDK package for the standard system (macOS-M1)            | 3.2.10.6      | [Download](https://repo.huaweicloud.com/harmonyos/os/3.2-Beta5/L2-SDK-MAC-M1-PUBLIC.tar.gz)| [Download](https://repo.huaweicloud.com/harmonyos/os/3.2-Beta5/L2-SDK-MAC-M1-PUBLIC.tar.gz.sha256)| 634.5 MB |
| Public SDK package for the standard system (Windows\Linux)  | 3.2.10.6      | [Download](https://repo.huaweicloud.com/harmonyos/os/3.2-Beta5/ohos-sdk-windows_linux-public.tar.gz) | [Download](https://repo.huaweicloud.com/harmonyos/os/3.2-Beta5/ohos-sdk-windows_linux-public.tar.gz.sha256) | 1.6 GB |



## **What's New**

This version has the following updates to OpenHarmony 3.2 Beta4.

### SDK Updates

From this version on, only the public SDK is released. You can obtain the public SDK from the mirror or download it from DevEco Studio for your application development.

To use the full SDK that contains system APIs, you must download the full code, compile and build an SDK file, and switch to the full SDK on DevEco Studio. For details about how to compile the full SDK using the source code, see [Full SDK Compilation Guide](../application-dev/faqs/full-sdk-compile-guide.md).


### Feature Updates

**Table 3** New and enhanced features

| Subsystem| Standard System| Mini and Small Systems|
| -------- | -------- | -------- |
| ArkUI | - Resources can be obtained by resource name.<br>- The component supports multi-level menus and group menus.<br>- The compilation capability is enhanced.<br>The following requirements are involved:<br>I683Z1 [New function] Adaptation to resource name–based resource retrieval<br>I68DBH [Basic capability] Providing multi-level menus and group menus<br>I68DRY [New function] Adding the HAR package compilation process<br>I68DRY [New function] Adapting to the HAP compilation process so that .d.ets declaration files can be identified during HAP compilation<br>I68DRY [New function] Adding the shared package compilation process to the toolchain| NA |
| Web subsystem| The WebView component supports the following new capabilities:<br>- Web pages can be loaded and displayed, including historical records, forward, and backward. Events can be reported during page loading. The webmessage supports the arraybuffer type. The fetch supports custom protocols.<br>- The following capabilities are added to configuration management: scroll bar and scroll position, network loading interception configuration, determining whether a page contains images, obtaining the source URL, request method, and website icon, and font management.<br>- The web context menu can obtain the selected content on the page.<br>- Interaction normalization is available for input events, and original input events are supported.<br>- Several W3C interfaces are supported.<br>The following requirements are involved:<br>I6BFPR [Function enhancement] [WebView component] Web page loading and display (supporting historical records and forward and backward list management)<br>I6BFRC [Function enhancement] [WebView component] W3C interface support (HTML-partial test cases)<br>I6BFS6 [Function enhancement] [WebView component] W3C interface support (CSS-partial test cases)<br>I6BFSK [Function enhancement] [WebView component] Web page loading and display (1. arraybuffer type support by webmessage)<br>I6BFTS [Function enhancement] [WebView component] W3C interface support (1. appmanifest)<br>I6BFUD [Function enhancement] [WebView component] Web page loading and display (1. custom protocols for fetch)<br>I6BFUM [Function enhancement] [WebView component] Status callback for web pages (1. page loading events)<br>I6BFV4 [Function enhancement] [WebView component] WebView configuration management (1. scroll bar and scroll position)<br>I6BFXF [Function enhancement] [WebView component] WebView configuration management (1. network loading interception configuration 2. Determining whether a page contains images 3. Obtaining the source URL, request method, and website icon)<br>I6BFXT [Function enhancement] [WebView component] WebView configuration management (1. font management)<br>I6BFY9 [Function enhancement] [WebView component] Input event support (1. interaction normalization)<br>I6BG4H [Function enhancement] [WebView component] Input event support (1. original input events)<br>I6BG59 [Function enhancement] [WebView component] Selecting and copying content on web pages (1. obtaining selected content from the web context menu)| NA |
| Security| - Mini system devices support authentication session cancellation.<br>- HUKS supports RSA signature enhancement.<br>The following requirements are involved:<br>I65VLX [Function enhancement] Authentication session cancellation for mini system devices<br>I611S5 [New specifications] RSA signature enhancement by HUKS| NA |
| Bundle management framework| - Implicit query is enhanced.<br>- Creation of a TS code optimization directory is supported.<br>- **bundleName** in **provision** can be verified during signature verification.<br>- A default icon is displayed on the home screen for an application for which no entry icon is configured.<br>- The following basic capabilities are added: packaging, unpacking, installing, updating, and uninstalling the dynamic shared library, and verifying the runtime capability of the HAR shared package.<br>The following requirements are involved:<br>I6BD9G [Basic capability] Enhancement to implicit query<br>I6BD9E [Basic capability] Creating a TS code optimization directory<br>I6BD99 [Basic capability] Verifying **bundleName** in **provision** during signature verification<br>I6BD8Z [Basic capability] Displaying a default icon on the home screen for an application for which no entry icon is configured<br>I6BD92 [New function] Packaging and unpacking the dynamic shared library<br>I6BD96 [New specifications] Installing, updating, and uninstalling the dynamic shared library<br>I6BD9I Verifying the runtime capability of the HAR shared package| NA |
| Building and runtime| - **taskpool**, a TS/JS task pool concurrency API, is added.<br>- The TSAOT function on the host side is supported. The TSC supports the export and import of .d.ts and .d.ets declaration files.<br>The following requirements are involved:<br>I65G6O [Basic capability] [Closed-source HAR package] Export and import of .d.ts and .d.ets declaration files<br>I64QIR [taskpool] TS/JS task pool concurrency APIs<br>I65HID [Function enhancement] TS2AOT-tool of the host version| NA |
| Pan-sensor service| The control of a single logical light is supported.<br>The following requirements are involved:<br>I63TFA [New specifications] Single logical light control| NA |
| Media| The APIs for playing and recording audio and video are reconstructed.<br>The following requirements are involved:<br>I63GTA [Reconstruction] Integration of audio and video playback APIs<br>I66VL5 [Reconstruction] Integration of audio and video recording APIs| NA |
| Startup subsystem| Symbols are hidden for the NAPI module, and the dependency on the static library module is changed to the dependency on the dynamic library module.<br>The following requirements are involved:<br>I698CV [Symbol optimization] Symbols hidden for the NAPI module; changing from the dependency on the static library module to the dependency on the dynamic library module| NA |
| Common event and notification subsystem| The local notification database is changed.<br>The following requirement is involved:<br>I67E9A [Basic capability] Local notification database switchover| NA |
| Graphics subsystem| Camera preview image is supported.<br>The following requirements are involved:<br>I6BDOH [RenderService] [New function] Camera preview image| NA |
| Location service| The network location framework is supported.<br>The following requirements are involved:<br>I5X4S9 [New feature] Network location framework| NA |
| File storage| - Unified URI processing is added for application files.<br>- Temporary authorization and unified open entry are added for user data.<br>The following requirements are involved:<br>I687C8 [New capability] Unified URI processing for application files<br>I64U8W [Basic capability] Temporary authorization and unified open entry for user data| NA |
| Ability framework| - The restart of resident processes is optimized.<br>- The widget database can be switched.<br>- The asynchronous **onConnected** lifecycle is provided.<br>The following requirements are involved:<br>I65M3F [Basic capability] ShellCommand execution control<br>I65V83 [Basic capability] ServiceExtensionAbility support for asynchronous **onConnected** lifecycle<br>I61H21 [Basic capability] Change of the local widget database<br>I63UJ5 [Ability] [ability_runtime] Exception handling in API version 8 and earlier versions<br>I6BDCW [Basic capability] Forbidden to load code in the **data** directory during application loading<br>I6BDDU [Basic capability] Default ability launch mode of the FA model: Standard<br>I6BDE2 [Basic capability] Protection against frequent restart of resident applications| NA |

For details about the API changes, see [API Differences](api-diff/v3.2-beta5/Readme-EN.md).

For details about the API changes of each subsystem, see [Changelogs](changelogs/v3.2-beta5/Readme-EN.md).

### Chip and Development Board Adaptation

For details about the adaptation status, see [SIG-Devboard](https://gitee.com/openharmony/community/blob/master/sig/sig_devboard/sig_devboard.md).


### Samples

  **Table 4** New samples

| Subsystem| Name| Introduction| Programming Language|
| -------- | -------- | -------- | -------- |
| Multimedia subsystem| [QR code scanning](https://gitee.com/openharmony/applications_app_samples/tree/OpenHarmony-3.2-Beta5/media/Scan)| The sample app is used to scan QR code. With the app, you can select a QR code image from a folder to identify the QR code information.| ArkTS|
| ArkUI | [Home Page of the Application Market](https://gitee.com/openharmony/applications_app_samples/tree/OpenHarmony-3.2-Beta5/MultiDeviceAppDev/AppMarket)| This sample shows the home page of the application market. The page has different display effects in the small window and large window, reflecting the capability of one-time development for multi-device deployment.| ArkTS|
| File management subsystem| [File Management](https://gitee.com/openharmony/applications_app_samples/tree/OpenHarmony-3.2-Beta5/FileManager/FileIo)| This sample demonstrates file management. It uses the [mediaLibrary](https://gitee.com/openharmony/docs/blob/master/zh-cn/application-dev/reference/apis/js-apis-medialibrary.md), [userFileManager](https://gitee.com/openharmony/docs/blob/master/en/application-dev/reference/apis/js-apis-userFileManager.md) and [fileio](https://gitee.com/openharmony/docs/blob/master/en/application-dev/reference/apis/js-apis-fileio.md) APIs to add and access media library files and files in the application sandbox.| ArkTS|
| Ability framework| [Gallery Widget](https://gitee.com/openharmony/applications_app_samples/tree/OpenHarmony-3.2-Beta5/ability/GalleryForm)| This sample demonstrates the display of **Gallery** images in a widget and periodic update of the widget.| ArkTS|


For more information, visit [Samples](https://gitee.com/openharmony/applications_app_samples).


## Resolved Issues

**Table 5** Resolved issues

| Issue No.| Description|
| -------- | -------- |
| I5KMQX | [RK3568] The delay for switching from the **Contacts** tab to the **Call**subtab does not meet the requirement.|
| I5UFS1 | Vulnerability CVE-2022-2347 detected during the scanning of the DAS U-Boot component.|
| I5UDY5 | Linux kernel vulnerability: CVE-2022-41218.|
| I5YPMZ | Linux kernel vulnerability: CVE-2022-3344.|


## Known Issues

**Table 6** Known issues

| Issue No.| Description| Impact| To Be Resolved By|
| -------- | -------- | -------- | -------- |
| I6ATXO | [RK3568] The execution result of the OpenGL test suite contains failed items during XTS test.| The test case used to test the OpenGL interface is not adapted after other modules of the system are changed. The modules or applications that use the OpenGL interface are not affected, and the risk is controllable.| 2023-02-05|
| I6B1IC | [RK3568] [Low probability 1/10] [XTS] The ispserver thread in the /vendor/bin/ispserver process causes a cpp crash in librkaiq.z.so.| In the pressure test, there is a low probability that the ipserver thread causes a cpp crash. The ipserver thread can be automatically restarted, and services are not affected.| 2023-02-05|
| I6BJ9Z<br>I6BJ82 | alloc_file_pseudo memory leakage occurs.| The accept4 reference count is unbalanced, causing memory leakage on selinux_netlbl_sock_genattr, new_inode_pseudo, and inet_create. No patch is available in the upstream community yet, and the issue will be resolved once a patch is released in the upstream community.| 2023-03-30|
| I641A2<br>I64726 | The Bluetooth module has silent pairing issues. Other devices can be completely controlled through the Bluetooth keyboard and mouse after silent pairing.| This issue will be resolved in the form of a requirement in later versions.| 2023-03-30|
| I6BRTS | Invoking the **rdb::executeSql** interface may cause memory leakage.| Memory leakage occurs when the **rdb::executeSql** interface is repeatedly called during initialization. This interface is called only during application initialization, and therefore the impact of memory leakage is controllable.| 2023-02-10|
| I6AZ4T | Memory leakage exists for applications with the **\<textInput>** component.| Memory leakage occurs when the **\<textInput>** component is repeatedly called at a high frequency. The root cause is that the memory is not reclaimed during the calling of the third-party library flutter. We will first check whether the problem is caused by the open-source flutter component.| 2023-02-10|

<!--no_check-->