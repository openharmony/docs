# OpenHarmony 5.0.0 Release


## Version Description

OpenHarmony 5.0.0 Release continuously improves its standard system capabilities. It provides the following enhancements over OpenHarmony 4.1 Release:

The application framework has introduced more lifecycle management capabilities and child process related capabilities. It can now conduct more refined scheduling and management of tasks at application runtime. The lifecycle management capabilities have been refined, and the application launching and redirection capabilities have been improved. ArkUI has further opened up the rendering capabilities of custom nodes and improved the components' capability to call through C APIs. Bundle management has improved the efficiency of application packaging and enriched the operational scenarios for end users when using applications (such as creating application clones and home screen shortcuts). The connection capabilities and specifications of DSoftBus have been further enhanced. The distributed data management capabilities have been further strengthened. While ensuring the rational sharing of data, security has been enhanced. The Sendable mechanism adaptation capabilities of other modules have also been improved. File management has further improved the Picker's capabilities, achieving rational control and use of file resources. Media capabilities in audio and video playback and recording have been further enhanced. Support has been added for multiple audio, video, and image encoding formats. More detailed playback control operations are now supported. The camera provides more powerful capabilities, enriching the scenarios for end users to take photos. The framework capabilities, video encoding and decoding capabilities, and audio and video application capabilities have been improved. The media library has enriched the usage scenarios and provides a better user experience.

Multiple subsystems have further aligned with ArkTS to enhance NDK C API capabilities, such as ArkUI's adaptability to third-party frameworks, Unified Data Management Framework (UDMF), graphics rendering, playback framework, camera, graphics codec, network management, internationalization, time and time zone, input method framework, and pasteboard.

OpenHarmony 5.0.0 Release is the official release version for API level 12.

A more detailed description of the enhancements is as follows:


### Application Framework

- You can create JS or native child processes for time-consuming operations.

- A wider range of lifecycle events, such as **onNewWant**, are provided for abilities.

- An ability can return the AbilityResult to the caller without proactively destroying itself.

- Context supports the conversion of sendable objects for passing the context in multithreading environments.

- Application-level font settings are supported.

- The AppStartUp framework is introduced to provide a simple and efficient method for initializing components during application startup, improving startup performance.

- APIs for starting atomic services are added, and two startup modes are provided: pop-up and embedded.

- Enhanced auto-fill capabilities: The **TextInput** component supports auto-save and auto-fill for more data types.

- Enhanced widget capabilities: The monochrome mode, inverse color, gradient color collision, exquisite visual display (such as blur, shadow, and rounded corners), and natural background integration.

- The Ability Assistant (AA) tool supports implicit application startup.

- Deep Link and App Linking are provided to reduce usage costs for developers and improve navigation security.

- Secure application restart capabilities are provided.

- The system environment now includes notifications for changes in font size and weight.

- The UIAbilityContext capabilities are enhanced as follows:
  - Obtaining the WindowStage
  - Enabling an application to proactively switch its UIAbility to the background

- The following application lifecycles are added:
  - **OnDestroy** lifecycle for the AbilityStage
  - **onWindowStageWillDestroy** lifecycle for the UIAbility

- The wait-for-debugging mode is added for applications.

- During cross-device migration, an application can migrate from one ability to another ability.

- During cross-device migration, an application can use asynchronous APIs to save data.

- During cross-device migration, an application can be started in advance in pull scenarios by configuring the immediate startup field.


### ArkUI

- Component customization is further enhanced with the introduction of **Modifier**, **ContentModifier**, and **DrawModifier**. Attributes can be added to existing components, component content can be customized, and fully custom rendering is supported.

- Custom nodes and native rendering nodes are opened up. [Custom nodes](https://gitee.com/OpenHarmony/docs/blob/master/en/application-dev/ui/arkts-user-defined.md) are node objects with some basic capabilities of underlying entity nodes. They can be mixed and displayed with built-in components through custom placeholder nodes. They have customization capabilities for individual nodes, such as measurement and layout, setting basic attributes, setting event listeners, and custom drawing and rendering content. There are three types of custom objects: FrameNode, RenderNode, and BuilderNode.  
  - **BuilderNode**: provides APIs for a BuilderNode – a custom node that can be used to mount native components.
  - **FrameNode**: provides APIs for a FrameNode, which represents an entity node in the component tree. It can be used by a NodeController to mount a BuilderNode (that holds the FrameNode) to a NodeContainer or mount a RenderNode to another FrameNode.
  - **RenderNode**: provides APIs for creating a RenderNode in custom drawing settings at the native side.
  - **NodeController**: provides APIs for managing custom nodes, such as creating, showing, and updating custom nodes, and APIs for mounting custom nodes to a NodeContainer component.

- The NDK capabilities of components suitable for third-party frameworks are enhanced, covering component creation, attribute setting, event registration, customization, and component tree building.

- The capabilities of the **Navigation** component are enhanced, including the single- and dual-column switching animation, interruption and resumption of transition animations, and listening capabilities for the page lifecycle.

- The visual effect, animation, and interaction refresh of components are supported. Aging, mirror language, and screen reading are supported.

- You can define the color, shape, rounded corner, size, position, and shadow for menu and dialog box components.

- The node customization capability is enhanced to provide FrameNode customization and node agents.
  - Nodes can be dynamically added or deleted.
  - Universal attributes and events can be set for nodes.
  - The capability of traversing the node tree is supported.
  - Component information can be accessed through nodes, and additional event callbacks can be registered.
  - Custom node measurement, layout, and rendering are supported.

- The custom extension capability is enhanced to provide a variety of modifiers.
  - Modifiers of basic components are provided to support chain calls and parameter passing, and can inherit to implement custom modifiers.
  - **AttributeUpdater** is introduced to support direct attribute updates.
  - **GestureModifier** is introduced to support dynamic gesture settings.
  - **DrawModifier** is introduced to extend the drawing content of native components.
  - **ContentModifier** is introduced for certain components, supporting customization of component content styles with custom Builder methods.

- The capabilities of the **Navigation** component are enhanced as follows:
  - The **onWillShow** and **onWillHide** lifecycles are supported.
  - Transition animations support interruption and resumption.
  - The page content is extended to the status bar.
  - Singleton redirection is supported.
  - The custom animation capability is enhanced.

- The advanced text capabilities are enhanced as follows:
  - **Text** components support attribute strings.
  - Images and texts can be dragged between WebView and ArkUI applications.
  - RichEditor supports hint settings.


### Bundle Manager

- Application clone access and management are supported. Applications can access application clones through simple configuration.

- Home screen shortcuts are supported. Users can dynamically add shortcuts to the home screen.

- The system-level HSP and ArkWeb can be upgraded independently, and preset applications can be updated independently.

- A recovery mechanism is provided upon OTA update interruption. If a power outage or service crash occurs during an OTA update, the OTA process is restored upon restart, continuing to install or update the applications.

- The **cache** directory can be automatically cleared when device space is insufficient.

- Native software packages can be packed, installed, and uninstalled.

- The packaging tool compresses an application package to reduce its size for distribution.

- The service module (HSP/HAR) supports the **router_map.json** configuration, implementing dynamic route decoupling between modules.

- The integrated HSP is supported. Multiple applications in a group can use the integrated HSP to share code and resources.

- Uninstalling updates is supported. Preinstalled applications that have been updated from AppGallery can be restored to the preinstalled version by uninstalling the updates.

- APIs are provided to install and query in-house applications, allowing for in-house application management.

- Unified resource cache is provided, covering overlay and theme switching scenarios.

- Decompression of GZIP files is supported.

- The **resfile** directory is introduced, which stores various resource files. During application installation, these resources are decompressed to the application sandbox path.


### DSoftBus

- IPC provides basic C APIs, including serialization, deserialization, and message sending and receiving.

- Transmission priority control is added for BR/BLE connections to improve the success rate of BLE discovery and broadcasting.

- BR/BLE link multiplexing is supported. The multiplexing process is not interrupted by services, improving the success rate of multiplexing.

- Multi-medium networking is supported to avoid repeated authentication and improve authentication efficiency.

- Logical channels can be decoupled from physical links to increase the connection success rate.

- The transmission module provides encryption and decryption APIs, and supports the capabilities of canceling the binding process and configuring the timeout interval.

- IPC supports asynchronous message sending and provides high-performance JS interfaces for reading and writing the shared memory.

- The common parts of IPC_Core and IPC_Single are decoupled, continuously optimizing the memory usage.


### Distributed Data Management

- RelationalStore and Preferences support access to shared sandbox data.

- The RDB supports opening in read-only mode.

- UDMF supports compatibility queries for UTD and MIME types.

- Data asset synchronization is optimized in the migration scenario.

- Distributed data management with E-class encryption is supported.

- In the inverted index construction scenario, an external tokenizer can be specified for an application.

- NDK C APIs support UDMF data drag and drop across devices.

- Preferences support serializable JSON objects and key-based precise subscription.

- relational_store supports TS synchronous APIs.

- UDMF supports batch transactions, and introduces 4 common data struct definitions and 40 UTD data types.

- data_share is optimized in terms of resource usage, access control, and access precision.


### Distributed Hardware

- Refined ACL management is provided. ACLs can be added, deleted, modified, and queried based on devices, users, accounts, and bundle names.

- The quality is hardened to improve the stability and reliability of functions.

- Applications are able to manage trusted and untrusted device resources, and query, filter, sort, and listen for device information.

- A device authentication framework is provided to support PIN code, tapping, scanning, and getting-close, supporting various authentication interaction entries.

- Device networking, online/offline, and peripheral device scanning capabilities are introduced for device resource management.


### Distributed DeviceProfile

- Device data is restructured at multiple levels to improve the execution efficiency of data addition, deletion, modification, and query.

- The quality is hardened, and background link establishment is optimized to improve stability and reliability.

- System services can add, delete, modify, and query cross-device trust relationships, trusted device information, device system information, service information, and service feature information, and subscribe to data change notifications.

- On-demand data synchronization and Bluetooth heartbeat broadcast synchronization across devices are supported. Data can be categorized into toggle data, static data, and dynamic data for service parties to define and operate different types of data based on their own data characteristics.


### File Management

- Incremental backup is provided for files and cloud space.

- APIs are provided for an application to obtain the backup data volume details, allowing an application to report the number of data records to be backed up (for example, the number of short messages) and exception events during backup and restore.

- The SA is allowed to access the backup and restore framework.

- The picker capabilities are enhanced. Audio Picker allows users to select multiple items at a time. Download Picker is added, allowing applications to directly save files to the **Download/*bundleName*** directory. In addition, subsequent access to this directory does not require permission authorization, complementing the download experience of browser applications.

- Applications can obtain the access permission of public directories (**Download**, **Desktop**, and **Document**) by applying for permissions (supported on some devices, subject to **syscap** judgment). Direct access is not allowed without permissions requested.

- Applications can select files or directories through File Picker and obtain temporary access permissions to the files or directories. Persistent access is also supported. Files or directories that are not persisted cannot be accessed after the applications exit.

- Stream file access APIs, such as **CreateStream** and **fdopenStream**, are added.

- The APIs for setting and obtaining extended attributes are added.


### Graphics and Window Manager

**Graphics**

- The native image module supports NativeWindowBuffer.

- The native vsync is supported, supporting multiple callbacks per frame.

- NDK C APIs related to variable frame rates are provided.

- ColorSpaceManager supports the sendable capability.

- The font engine supports the text shadow capability and underline alignment.

- The graphics drawing interface improves drawing capabilities.

- The drawing capability is enhanced to support vector primitive drawing, bitmap drawing, style visual effect, and shadow effect for text.

- The bitmap ArkTS and C APIs are enhanced to support format conversion, premultiplication of transparency, and effect processing.

- The NDK capability of the text engine is enhanced to support line spacing and various wrapping policies.

- The NDK capability of the surface is enhanced to provide C APIs for obtaining the YUV data location, surface ID, and buffer queue size, as well as attaching and detaching.

- LTPO frame control is introduced.

- The 3D component capability is enhanced to support loading and editing of 3D scenes.

- OpenGL ES extensions are provided.

- The performance and energy efficiency are further optimized.

**Window Manager**

- The **display.getDisplayByIdSync** API is provided to work with the multi-screen feature, allowing applications to synchronously obtain information about the screen where the ability is located through the ID.

- Information about the available area on the screen can be obtained.

- The text color of the status bar can be set based on the page color in ArkUI.

- Applications can obtain the color attribute of the status bar.

- The cross-platform capability is enhanced. APIs such as **loadContentByName** and **windowSizeChange** adapt to the cross-platform capability.


### Media

**Audio**

- Audio focus enhancement: Audio focus sessions are supported, allowing an application to set concurrent playback policies and to play silently without interrupting background audio playback.

- More audio output devices, such as DP and USB headsets, are supported. Switching of the default output device (earpiece and speaker) is also supported.

- The audio stream type for video calls is added, optimizing the audio stream playback experience in this scenario.

- A unified volume component is added for easy of use, reducing development complexity.

- The style of the in-app casting component can be customized.

- The ringtone list query and custom ringtone settings are supported.

- Internal audio recording allows filtering by stream type and application.

- Low-power audio playback supports speed adjustment and sound effect processing.

- HD audio playback is supported for both wired and Bluetooth headsets.

- Spatial audio rendering is supported for external playback.

- VoIP voice calls support low-latency channels.

- System sound management allows applications to obtain the system tone list and customize system tones.

**Playback**

- The playback start and seek performance of the player is optimized to reduce the latency.

- Multiple playback protocols or formats are added: DASH protocol, and AMR, APE, and WAV PCM-MULAW audio formats.

- Multiple playback control capabilities are added: video playback with multiple audio tracks, changing the output surface during video playback, silent playback, precise seek, playback range setting, and subtitle setting.

- The streaming media buffer size can be configured. The audio offload mode is supported.

- Enhanced streaming media playback capability: The streaming media cache policy is optimized, reducing frame freezing.

- More playback speed options (0.5x and 1.5x) are introduced.

- More playback formats (such as AMR) are supported.

- More audio encoding parameters (such as the bit depth) are introduced.

- Low-power audio playback (offload) is supported.

- Precise seeking is supported.

- Users can switch the video to another window during video playback.

- Header customization is introduced, allowing users to add custom information during streaming media playback.

- FLV live streaming is supported.

- Applications can automatically switch to a proper bit rate based on the network quality during online playback.

**Recording**

- Enhanced audio recording capability: Audio can be recorded in MP3, WAV, and PCM (µ-law) formats.

- Image rotation parameters can be dynamically configured.

- Layered encoding is introduced for video recording.

**Media metadata**

Identification of HDR Vivid videos is supported.

**Screen Capture**

- Screen capture protection can be exempted for the application's own privacy windows, providing a privacy confirmation window and screen capture status prompt.

- Images in a specified window can be excluded during screen capture.

- Screen rotation can be configured and rotation parameters can be dynamically adjusted.

- The microphone and system sound can be captured simultaneously.

- C APIs are provided to record the system screen and sound.

- Applications can obtain screen capture data in surface mode.

- Applications can configure screen capture content to follow screen rotation.

- Screen capture cannot be performed concurrently with cellular calls.

- The microphone and system sound can be captured simultaneously.

- A privacy dialog box is provided for screen capture. Screen capture can be started only after being authorized by the user.

- Screen capture supports excluding the window with the specified window ID.

- Screen capture supports excluding the audio of the application itself.

DRM

- DRM plug-in management and DRM scheme integration are supported.

- DRM certificate downloads are supported.

- Online and offline authorization of DRM programs is supported.

- Decryption of DRM programs in secure or non-secure mode is supported.

- Secure video channels are supported.

- Authorization, decryption, and playback of HLS+TS/DASH+fMP4 DRM programs are supported.

- The integration of the AVPlayer and AVCodec playback framework is supported.

**Audio/Video Codecs**

- AVTranscoder APIs are added to reduce the bit rate and output video files in AVC, AAC, and MP4 formats, reducing the amount of data to be transmitted or stored.

- APE decoding and demuxing are supported.

- MP3 encoding and muxing are supported.

- Parsing of SRT subtitles is supported.

- H.264/H.265 hardware encoders support the setting of long-term reference frames and reference frame encoding on a per-frame basis, depending on hardware chip capabilities.

- H.264/H.265 hardware encoders support the setting of encoding QP on a per-frame basis, depending on hardware chip capabilities.

- H.264/H.265 hardware codec supports low-latency frame output (one-in-one-out), depending on hardware chip capabilities.

- H.264/H.265 hardware encoders support the resetting of the bit rate and frame rate, depending on hardware chip capabilities.

- H.264/H.265 hardware encoders support hierarchical-P temporal scalability, depending on hardware chip capabilities.

- Parsing of FMP4 files is supported.

- In surface mode, surface switching is supported during hardware decoding.

**DRM**

- The AVPlayer and AVCodec can parse DRM information for DASH programs, decrypt H.265 videos encapsulated in TS, and decrypt audio clips.

- AVCodec DRM adaptation now includes settings for decryption parameters.

**Camera**

- The following modes are added: time-lapse, panorama, light painting, wide aperture video, and fluorescence.

- A one-touch PerConfig mechanism is added for cameras to ensure consistent effects and simplifies development.

- The deferred photo delivery process is optimized to improve the performance and quality of photos and videos.

- New C APIs are added to match the capabilities of ArkTS APIs.

- The camera experience is enhanced with features like mirroring, zoom, image stabilization, burst shooting, and camera status notification.

- Camera modes are enhanced, including Pro, Super macro, Super slow motion, and Safe.

- The camera is enhanced to support moving photos, HDR Vivid capture, and deferred photo delivery.

- The camera effect is enhanced to support black and white colors and portrait blurring.

- Camera control is enhanced. The frame rate can be dynamically configured, and information such as the focal length and ambient brightness can be returned.

**Image**

- The EXIF read and write capabilities are enhanced, supporting batch read and write operations on EXIF data. The number of playback times can be obtained for GIF files.

- HDR dual-layer codec and conversion between HDR and SDR are supported.

- HEIF encoding and decoding and DNG decoding are supported.

- The compilation framework is supplemented based on NDK C APIs, including base classes for effects and filters, and custom algorithms.

- HEIF decoding is supported.

- DNG decoding is supported.

- C APIs are provided for image encoding and decoding.

- Image codec supports HDR effects (depending on platform capabilities).

- The EXIF coverage and batch EXIF read/write capabilities are supported.

- Images in HEIF and JPEG formats can be decoded into the YUV format.

- GIF decoding is enhanced, allowing applications to obtain the number of playback times and frame transition mode.

- The WebP format supports retrieval of the frame delay time.

- JPEG codec hardware acceleration is enhanced (depending on platform capabilities).

- The image editing NDK interface is open, supporting pipeline orchestration, effectors, and filter chains.

**Media Library**

- A new deferred photo delivery process is introduced, including consumption-only, direct saving, and editing and saving after photographing.

- The hdc command in developer mode can be used to read images and videos in the public storage area of the media library.

- The hdc command in developer mode can be used to parse the names of images and video files encrypted by the media library.

- The mediatool in root mode can be used to preset image and video resources.

- Applications can identify HDR images and videos and provide HDR LCD thumbnails.

- The media library is enhanced to refresh search indexes in a timely manner when images and videos are deleted.

- Video tagging, natural semantics, and detection of human and pet heads are supported.

- Applications can now generate OCR information for images in a timely manner.

- Applications can locate images and videos in the smart album.

- Applications can parse the longitude and latitude of videos.

- Permission optimizations allow applications to maintain long-term read/write permissions for their own saved images and videos.

- Applications are allowed to export videos to the application sandbox.

- The flow control mechanism for malicious applications accessing cloud images is enhanced.

- The media library now publishes change notifications when cloud images change.

- Watermarks and filters for deferred photo delivery now support editing and reversibility. The mechanism for accurately identifying and reporting application access to original images and videos is optimized.

- The storage space occupied by images and videos, including thumbnail space, is now accurately calculated.

- Applications can use C APIs to read images and videos.

- Applications can query named portrait information.

- The media library allows users to take, save, and read moving photos, set the frame information of the moving photo cover, and set the moving photo effect mode.

- A new ringtone library is added to support preset ringtones and custom ringtones.

- Shooting mode information can now be uploaded to the cloud.

- DFX capabilities are enhanced to include static user data, time-consuming behavior, deletion behavior, and application behavior statistics.


### Common Event and Notification

- The CEM tool supports the release of custom common events.

- A generic interface is added to Emitter to directly transfer sendable objects.

- Synchronous query of the enabled status of notifications is supported.

- Authorized application can customize notification ringtones.

- Applications can create live notifications of the progress bar type in system proxy mode.

- Different application clones can publish notifications.

- A synchronous interface is provided to query the notification authorization status.

- System applications can batch query authorized notifications and live window application lists and statuses.

- System applications can publish emergency event notifications.

- System applications can subscribe to notifications by device type for reminder coordination between mobile phones and other devices.

- System applications can set badges for other applications.

- In Do Not Disturb mode, an application trustlist can be configured, and applications within the trustlist are not affected by Do Not Disturb mode.

- System applications can delete and re-add statically subscribed-to common events while running.


### Communications

- Third-party applications can connect to hotspots through network management.

- The DHCP service is optimized to support retrieval of information such as the peer name and IP address.

- Security for saved hotspot password information is enhanced.

- The number of threads and architecture of the WLAN service are optimized.


### Location

- During continuous locating, error code information that affects locating can be listened for.

- APIs related to GNSS satellite status information and continuous locating are optimized.

- The security compilation options of the location service are enhanced.

- The location permission policy for service widgets is optimized.


### Telephony Service

- Applications can obtain the IMEISV and the PLMN code of the resident base station.

- The telephony service process load and DFX are optimized, including independent build and deployment, improved traceability, and stability.


### Network Management

**Network Management Capabilities**

- You can create a NetConnection object to connect to a specified Wi-Fi hotspot.

- NDK C APIs are provided for network management status listening and application-level proxy listening.

- The network management process load and DFX are optimized, including independent build and deployment, enabling FFRT to reduce the number of threads, reducing the memory overhead, improving traceability, and improving the automatic recovery capability after a crash.

**Network Protocol Stack Capabilities**

- A TCP socket can be upgraded to a TLS socket to improve communication security.

- A TLS socket supports skipping certificate verification to avoid scenarios where certificates cannot be verified.

- All sockets can obtain the local IP address and port number.

- HTTP supports the configuration of certificate pinning information.

- HTTP supports the Brotli compression algorithm.

- The HTTP protocol stack can automatically read certificates installed by the system and users.

- The HTTP proxy supports secure storage of usernames and passwords, automatic update of proxy authentication credentials, and automatic reading of proxy configurations when the previewer is used.

- WebSocket supports capabilities such as obtaining header information and setting proxies, with reduced power consumption.

- TLSSocket supports sending of ArrayBuffer data and use of the system default certificates.


### Power

- The charging current can be obtained, allowing third-party applications to obtain the current of the device through **nowCurrent**.

- Temperature control actions in airplane mode are supported. You can customize temperature control policies to control devices to enter airplane mode.

- The WorkSource proxy running lock can assist the resource scheduler in power consumption control.

- In low power situations, devices can automatically enter the S4 sleep mode after waking up from the S3 sleep mode, implementing ultra-long standby.

- After system startup, it is now possible to read and broadcast the presence information of device shells or covers, and to configure kernel nodes of battery information and whether to broadcast.

- The DIM display status is supported. The screen is turned off after the system enters the DIM state, improving user experience.

- The screen pre-display capability is supported. The screen is powered on but does not display any information.

- A timeout for screen off can be set.

- Temperature simulation debugging is supported.

- ArkTS and C APIs related to hibernation are provided.

- The power service operates independently as the powermgr process.


### USB

- Access control is enhanced for USB device configuration management.

- The USB standard data transfer mode (interrupt transfer and bulk transfer) is enhanced.

- Security management of standard USB peripherals is supported.

- Applications can obtain the transmission rate of USB devices and activation status of USB interfaces.

- A verification system for establishing wired USB peripheral connections is introduced.

- Presetting default USB ports is supported.

- Multi-user concurrency scenarios are supported.

- The DFX capability is enhanced to streamline the USB service restart process upon an exception.

- The application's defenses against unauthorized access are fortified.


### Startup

- Native software packages can be packed, installed, run, and uninstalled. A native software package development and release system is now available, facilitating the rapid construction of productivity software ecosystem capabilities and improving development efficiency for system developers.

- A resettable Open Anonymous Device Identifier (ODID) is provided to replace real-world UDIDs and other hardware identifiers.

- The bftpd command can be executed to debug sandbox data access in user mode.

- Applications can query and obtain the real ODID information.

- Maintenance commands are extended to include viewing the running status of each service process, FD status in the looper, and timer information.

- The appspawn module supports the **bftpd** command and provides the access, read, and write capabilities for directories in the specified application sandbox.

- A restriction is placed on the number of processes that can be forked during application incubation.

- During application incubation, environment information can be set for application processes.

- During application incubation, sandbox data can be isolated per account for atomic services.

- After the foundation process is restarted due to an exception, the init process can vote again to ensure that the BOOTCOMPLETE event can be initiated again.


### Globalization

- C APIs are provided to support internationalization capabilities in line with the ICU4C standard.

- The internationalization formatting capability supports screen size adaptation.

- Pseudo-localization testing is fully supported.

- C APIs are provided for resource file management.

- String resources support tags for translatability.

- Support for less common language character sets is now provided.


### Security

**Crypto Framework**

- C APIs are provided for some typical encryption and decryption algorithms to match ArkTS APIs.

- The SM4-GCM algorithm interface is supported.

- The crypto framework supports the HKDF key derivation algorithm, provides RSA encryption and decryption capabilities, and provides JS synchronous APIs for the library.

**Certificate Management**

- APIs are provided to invoke the certificate management page.

- APIs are provided to obtain the private certificate list of an application.

- The certificate framework provides UIs and APIs for managing system service certificate credentials.

**Access Control**

- Access control
  - The geographical location permission supports one-time authorization options.
  - The permission management application page of the Settings page can be displayed.

- DLP:
  - Applications can check whether the current system provides the DLP feature.
  - DLP file control for printing is supported.
  - Copy and paste authorization for users in batches is supported.

- SELinux:
  - The capability of ignoring specified directories during recursive tagging is supported.
  - SELinux policy control rules are added, requiring fine-grained management of ioctl permissions using allowxperm.

- Code signature
  - The signing tool supports the signing of HQF packages in developer mode.
  - The signing tool supports the signing of ELF files that are not suffixed with .so in the **libs** directory of the application package.
  - The signing tool supports the signing of native package (.hnp) code in the application package.

**User IAM**

- Password validity period check is supported.

- Key recovery is supported.

- Cross-device password authentication is supported for user identity authentication.

- Embedded identity authentication components are provided for facial recognition and fingerprint recognition.

- The complexity of registered passwords can be checked.

- Cross-user credential information recording, query, and authentication are supported.

- Applications can set the password validity period.

- The DFX capability is enhanced to support automatic authentication cancellation when the caller (application) switches to the background or ends its lifecycle.

**Account**

- Local accounts can be deregistered.

- When creating a local account, you can specify a short account name (used as the personal folder name).

- Querying local account names is now supported.

- A new privacy account type is introduced.

- A new unlock authentication intent is introduced.

- New graphical and four-digit PIN credential types are introduced.

- Multiple accounts can run concurrently (one account running in the foreground and the others running in the background).

- The number of system accounts that can be logged in to at the same time can be configured.

- Privacy accounts can be created.

- APIs are provided for adding and authenticating credentials across accounts.

- APIs are provided for cross-device credential authentication.

- Southbound extended domain account authentication protocols are supported.

- Configuration of domain server information is supported.


### ArkCompiler

**ArkTS Front-end Compiler**

- The syntax is enhanced. The compilation target is switched from es2017 to es2021, and source code files with es2018 to es2021 syntax features can be compiled.

- The code obfuscation capabilities are enhanced: stack restoration, file-level non-obfuscation, obfuscation of HAP and HSP module file names, and trustlist wildcard.

**ArkTS Runtime**

- Module lazy loading is supported. Execution files are loaded synchronously when variables are actually used, improving application startup performance.

- The concurrency capabilities are enhanced. The sendable object sharing mechanism is provided to optimize object communication across threads. TaskPool provides features such as task queues, continuous tasks, and periodic tasks.

- Debugging is enhanced to support reverse debugging and Smart Stepinto.

- Tunning is enhanced to support hiperf/profiler hybrid stack and multi-instance heap dump.

**ArkTS Utility**

- High-precision floating-point operations, StringDecoder (string decoding), stream data processing, and bit vectors are supported.

**JSVM**

- A system JS engine is provided to support high-performance running of JavaScript and WASM.

**Frontend Compilation Toolchain**

- The frontend compiler provides the Ark bytecode file format and instruction set specifications.

- The frontend compiler supports the loading of compiler plug-ins configured within DevEco Studio.

- The frontend compiler is enhanced to eliminate unnecessary branches for constants/variables within functions and across files.

- The frontend compiler is optimized to reduce compilation time.

- The frontend compiler supports exception stackback and debugging of closed-source HAR packages.

- The **target** option of the TypeScript compiler is changed from ES2017 to ES2021.

**Code Obfuscation**

- The time performance and memory usage are optimized.

- HAP file names can be obfuscated.

- Some files can be configured for not being obfuscated.

- Wildcard characters can be used in the trustlist.

- The row and column numbers can be reserved in the **nameCache** file to support DevEco Studio stack parsing.

**Concurrency**

- Sendable memory data types are supported, including the Sendable class, Sendable container (Array, Map, Set, Int8Array, Int16Array, Int32Array, Uint8Array, Uint16Array and Uint32Array), JSON parsing into Sendable objects, and asynchronous locking.

- The maximum number of Worker threads is increased to 64, and a total JS memory limit for the process is 1.5 GB.

- TaskPool supports task monitoring. It can listen for task distribution, execution start, successful execution, and failed execution events.

- TaskPool provides APIs to determine whether a function is a concurrent function.

- TaskPool supports continuous tasks.

- TaskPool supports serial queues to ensure the task execution sequence.

- TaskPool supports deferred task execution.

- TaskPool can collect statistics on the execution duration, including the CPU duration and I/O duration.

**Modularization**

The HAR files of the same version are treated as a singleton. That is, when an HAP and HSP depend on the same instance, only one instance is loaded during running.

**Debugging**

- Time Travel Debugging (TTD) is supported.

- Hybrid stackback of HiPerf and Profiler is supported.

- **callFunctionOn** is supported.

- Multi-instance heap dumps are supported.

- Fast cold start of ApplyChange is supported.

- Smart step into is supported.

**LLVM/Rust Compiler**

- Applications support TSan options.

- The Rust community can now compile targets for OpenHarmony.

**LLDB**

MiniDebug is supported.

**Linter**

Automatic fixes for 14 ArkTS rules are added in DevEco Studio.

**Musl C Library**

- The C library supports the locales zh_CN or zh_CN.UTF-8.

- The fdsan capability is supported, and fdsan-related APIs are opened up.

- The C library interface **fopencookie** is now accessible within the NDK.

**Standard JS Engine**

- The sourcemap file address information can be passed during JS script compilation. If an exception occurs, the source information converted by sourcemap is provided.

- Applications can check whether JS objects belong to the basic JS types.

- JS loose equality (== operation) is supported.

- String references can be created and persistent strings can be used.


### MSDP

**Drag Framework**

- You can rotate and drag and drop a window as it rotates.

- Applications can configure whether to hide the badge during the drag process.

- The data receiver can customize the cut and copy behavior.

- A more exquisite drag-and-drop visual experience is provided, including effects like transparency, shadows, and rounded corners.

- Multiple objects can be dragged and selected, enriching the drag-and-drop experience.

- The drag-and-drop behavior can be customized, enabling actions like cut/copy based on shortcut keys.

- Lightweight logging is supported to enhance the DFX capability.

**Screen Hopping**

- Control for both ends to initiate **activate** interface calls simultaneously is provided.

- Timing issues of screen hopping are optimized to reduce system dependencies and eliminate timing issues between multiple processes.

- Screen hopping management performance is improved, with a higher success rate and lower latency.

- The service architecture is optimized to improve stability, reliability, and performance.

- The performance benchmarking tool is provided to improve the DFX capability.


### Multimodal Input

- C APIs are provided to support device information query.

- Screen unlock events triggered by swiping up from the bottom can be reported.

- Events from irregularly shaped windows can be reported. Mouse events in the transparent area of an irregularly shaped window are transparently transmitted, but those in the non-transparent area are blocked.

- The following knuckle-based interaction events are supported: rendering paths traced by knuckle movements, animating these knuckle paths, capturing screenshots by making circular gestures with a knuckle, performing extended screen captures with an 'S' gesture, and starting screen recording through a double-tap gesture using two knuckles.

- The Smart Button is provided, enhancing the existing fingerprint button capability.

- Infrared capabilities are supported, providing external frequency data to the caller device.

- The mouse and touchpad can adapt to window rotation. In the event distribution module, the mouse coordinates are rotated and distributed to the correct window based on the window rotation information synchronized by the window.

- The capability to launch system applications by pressing combination keys is supported. When the screen is off, pressing the combination keys does not launch the screenshot application. When the screen is locked, you must long press the combination keys to launch the screenshot application. Different applications are launched when you press or long press the same key. The capability of shielding combination keys through interfaces is also supported.

- The stylus can be double-tapped to start the shorthand. When the screen is off, double-tapping of the stylus can be correctly identified.

- The touchpad display-control ratio curve model is adapted. Based on this model, the multimodal input data preprocessing module processes the received touchpad single-point touch data.

- The stylus can be used to continuously take snippets. Users can use the stylus for input and use the touchscreen for touch interaction. The annotation window responds to the stylus input, and the application window at the bottom responds to the touchscreen operations.

- The pointer position information can be displayed and dynamically enabled or disabled. The number of touch pointers, touch position, and moving speed can be displayed.

- Applications can listen for events from the power button and volume button. When the call application receives an event from the volume button or power button, it mutes the ringtone of incoming calls.

- The performance benchmarking tool is provided to record key service logs. The demonID is used to distinguish service logs. Fault benchmarking is supplemented or added to ensure that all faults in the domain have corresponding event benchmarks, improving the DFX capability.

- KeyCode is added to support custom common events for screen reading.


### Pan-Sensor

**Vibrator**

- Some asynchronous query APIs offer their synchronous counterparts.

- The system can better use the vibrator component to trigger vibrations based on different component capability levels.

- A set of simple and common haptic feedback effects is introduced, with adjustable intensity levels.

- Query APIs and synchronous APIs used to stop vibration are introduced.

**Sensor**

- Some asynchronous query APIs offer their synchronous counterparts.

- C APIs are provided to support linear acceleration and game rotation vector sensors.

- Synchronous sensor query APIs are introduced.

- Error code 14500102 is added for the sensor module, indicating that the queried sensor type is not supported by the device.

- Infrared and color temperature parameters are introduced into the reported ambient light data.


### Accessibility Service

- Zoom-in gestures are supported.

- Proactive broadcast capabilities are provided, allowing for proactive announcements of changing information in some dynamically changing scenarios for applications adapted for screen reading.

- Active focus capabilities are provided, enabling requests for proactive focusing on components in certain scenarios for applications adapted for screen reading.

- Color inversion is supported, which reverses the display color to meet the needs of some visually impaired users.

- High-contrast text is supported.

- Audio in mono mode consolidates the audio signal from both left and right channels into a single track, meeting the needs of some hearing-impaired users.

- The adjustable volume balance feature enables users to equalize the volume output between left and right ears, meeting the needs of some hearing-impaired users.

- Screen touch control is enhanced to support touch duration and ignoring of repeated touches.

- Touch browsing mode is supported, allowing visually impaired users to control the screen of smart devices in an interactive manner through touch browsing interactions.

- The capability of recognizing multi-finger interaction gestures is added for screen reading, enhancing the interaction experience of visually impaired users in screen reading mode.


### Resource Scheduler

**Background Task**

- Applications can request different types of continuous tasks at the same time.

- When an application requests a continuous task of the DATA_TRANSFER type, a download notification can be returned to the application for progress updates.

**Performance, Power, and Thermal Control**

- The system load level is determined based on the current temperature, load, and whether the system is in a high-load scenario. After an application registers the system load callback, the application can adaptively reduce its service load based on the system load level, thereby reducing the overall machine load.

**Agent-powered Reminder**

- When an application requests a duplicate calendar reminder, it is now possible to specify exclusion days when reminders are not made.

- When an application requests a reminder, it can use **wantAgent** to pass **parameters**. When the user touches the reminder, **parameters** is carried to display the target UIAbility.

- When an application queries released reminders, the corresponding reminder ID is returned in the query result.

**Agent-powered Reminder**

- A query interface is added to obtain the reminder ID.

- **WantAgent** can carry **parameters**.

- **ExcludeDate** is added to specify the date when the reminder is not triggered.

- The end time of a reminder can be set in **ReminderRequestCalendar**.


### Test Framework

- Compatibility testing is provided for cross-platform interfaces.

- The DFX capability of the UiTest framework is enhanced and the efficiency is improved.

- SmartPerf-Host supports micro indicator analysis.

- SmartPEF devices can capture frame freezing traces, process-level memory, CPU usage, and network information.

- Wukong supports pressure test settings and memory information collection.


### DFX

- An API is provided to check whether the HDC debugger is connected.

- The trace function can be enabled in developer mode.

- Awareness of the main thread timeout event is now open.

- The errorManager allows TaskPool and Worker to listen for unhandled Reject events.

- The FFRT coroutine and HiTrace tuning capabilities in distributed scenarios are introduced.

- HiProfiler memory analysis supports the JS-native hybrid stack.

- The quality data, performance data, and power consumption data of Performance Analysis Kit are open.

- C++ crash supports asynchronous tracing.

- File access in the application sandbox is introduced for hdc debugging.

- Applications support TSan detection.


### Kernel

- Thread QoS level marking and scheduling are provided based on user interaction relationships.
- C APIs are provided for QoS scheduling based on user interaction.


### Upload and Download

- **request.agent.Fault** has refined error types to assist you in quickly locating issues with API usage.

- **request.agent.Config** has added a proxy member, supporting the setting of the network proxy address for tasks.

- **request.agent.Task.start** supports restarting of a failed or stopped task.

- **request.agent.Task** supports the setting of the TLS certificate pinning using the **network.json** file.

- **request.agent.FileSpec** allows you to specify all file paths in the **base** directory of the application sandbox, facilitating sandbox file management. It also allows you to upload public files, such as Gallery files and Album files, in the foreground to reduce the overhead caused by extra copy.

- The notification bar for background tasks is optimized.

- The directory of an upload or download task can be any location within the **base** directory.

- If a download task fails, users can choose to restart the download task from the point of failure.

- Applications can listen for responses to upload and download tasks.

- Certificate pinning is supported during upload and download.

- User files can be specified for upload and download tasks in frontend mode (the read and write permissions must be obtained in advance).

- The number of tasks is optimized, so that more unfinished tasks can exist at the same time.


### Input Method Framework

- NDK C APIs are provided to support the use of the input method by self-drawn UI components, including starting and exiting the input method and processing text display requests.

- The callback timing when invoking the keyboard is optimized, allowing input method applications to adjust the keyboard display content in a timely manner based on the input box attributes.

- The basic mode and full experience mode of the input method are supported.

- The automatic capitalization mode is supported.

- The pre-display feature is supported.

- The rotation experience of the input method panel when the screen rotates is optimized.

- A new unified input method panel is introduced.


### Time and Time Zone

- System APIs are provided for forcibly refreshing the NTP time and obtaining the current NTP time.

- NDK C APIs are provided for obtaining the time zone.

- The APIs for asynchronously obtaining the system time are deprecated. Synchronous APIs (**getTime** and **getUptime**) are introduced.


### Pasteboard

- NDK C APIs are provided to offer the pasteboard capability.

- A cross-device pasteboard switch is provided.

- For applications upgraded to API 12 or later, the read permission verification is added to the pasteboard read interface.

- Permission control is added to the pasteboard read interface. When using the pasteboard security components, you can directly read pasteboard data without applying for permissions. When using a custom component, you must obtain user authorization before reading the pasteboard data.

- The pasteboard supports UMDF standard data types.


### Web

- The network takeover feature is enhanced to obtain the frame URL of a request and the resource type of an intercepted request.

- The pre-display capability of the input method in the web scenario is supported.

- Keyboard hosting of **Web** components is supported.

- Synchronous drawing of **Web** components and native ArkUI components is supported.

- Directories that can be accessed across domains using the File protocol can be set.

- Applications can now specify rendering child processes.

- **Web** components support the acceleration gyroscope.

- **Web** components support intelligent filling of HTML5 pages.

- **Web** component support backward and forward cache.

- The soft keyboard avoidance mechanism of **Web** component has been optimized to support the Resize and Offset modes.

- W3C allows you to customize the cursor style.

- W3C supports the **\<datalist>** element.

- The web kernel can identify HEIF images.

- Interception-free injection of offline resources is supported.

- Applications can define their own DNS.

- Universal links are supported.

- Asynchronous JSBridge is supported.

- **expandSafeArea** is introduced.

- Applications can query the avoid area.

- The ANR awareness capability of JS threads is supported.

- Uploading of the **\<input>** element with the file type is supported.

- Applications can customize menu options.

- The network takeover feature can obtain the resource type and frame URL of an intercepted request.


### Theme Framework

- The theme can be enabled through the folder directory. Compared with the compressed package, the theme enabling performance is improved.

- Widget resources can be managed, including the operations to add, delete, modify, and query theme widgets.

- Themes can be enabled for external screen devices.

- The theme enabled feature does not support the switchover of the current **active** directory.


### Build

The version of CMake version used for building is upgraded from 3.16.5 to 3.28.2.


## Mapping relationship

**Table 1** Version mapping of software and tools

| Software/Tool| Version| Remarks| 
| -------- | -------- | -------- |
| OpenHarmony | 5.0.0 Release | NA | 
| Public SDK | Ohos_sdk_public 5.0.0.71 (API Version 12 Release) | This toolkit is intended for application developers and does not contain system APIs that require system permissions.| 
| (Optional) HUAWEI DevEco Studio| 5.0.0 Release | Recommended for developing OpenHarmony applications<br>[Click here](https://developer.huawei.com/consumer/cn/download/).| 
| (Optional) HUAWEI DevEco Device Tool| 4.0 Release | Recommended for developing OpenHarmony smart devices<br>[Click here](https://device.harmonyos.com/cn/develop/ide#download). | 


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
   repo init -u git@gitee.com:openharmony/manifest.git -b OpenHarmony-5.0.0-Release --no-repo-verify
   repo sync -c
   repo forall -c 'git lfs pull'
   ```
   
- Obtain the source code from the version tag, which is the same as that released with the version.
   ```
   repo init -u git@gitee.com:openharmony/manifest.git -b refs/tags/OpenHarmony-v5.0.0-Release --no-repo-verify
   repo sync -c
   repo forall -c 'git lfs pull'
   ```

**Method 2**

Use the **repo** tool to download the source code over HTTPS.

- Obtain the source code from the version branch. You can obtain the latest source code of the version branch, which includes the code that has been incorporated into the branch up until the time you run the following commands:
   ```
   repo init -u https://gitee.com/openharmony/manifest -b OpenHarmony-5.0.0-Release --no-repo-verify
   repo sync -c
   repo forall -c 'git lfs pull'
   ```
   
- Obtain the source code from the version tag, which is the same as that released with the version.
   ```
   repo init -u https://gitee.com/openharmony/manifest -b refs/tags/OpenHarmony-v5.0.0-Release --no-repo-verify
   repo sync -c
   repo forall -c 'git lfs pull'
   ```


### Acquiring Source Code from Mirrors


**Table 2** Mirrors for acquiring source code

| Source Code                               | Version| Mirror                                                | SHA-256 Checksum                                            | Software Package Size|
| --------------------------------------- | ------------ | ------------------------------------------------------------ | ------------------------------------------------------------ | -------- |
| Full code base (for mini, small, and standard systems)       | 5.0.0 Release    | [Download](https://repo.huaweicloud.com/openharmony/os/5.0.0-Release/code-v5.0.0-Release.tar.gz)| [Download](https://repo.huaweicloud.com/openharmony/os/5.0.0-Release/code-v5.0.0-Release.tar.gz.sha256)| 41.8 GB |
| Hi3861 solution (binary)       | 5.0.0 Release    | [Download](https://repo.huaweicloud.com/openharmony/os/5.0.0-Release/hispark_pegasus.tar.gz) | [Download](https://repo.huaweicloud.com/openharmony/os/5.0.0-Release/hispark_pegasus.tar.gz.sha256) | 27.1 MB |
| Hi3516 solution-LiteOS (binary)| 5.0.0 Release    | [Download](https://repo.huaweicloud.com/openharmony/os/5.0.0-Release/hispark_taurus_LiteOS.tar.gz) | [Download](https://repo.huaweicloud.com/openharmony/os/5.0.0-Release/hispark_taurus_LiteOS.tar.gz.sha256) | 328.3 MB |
| Hi3516 solution-Linux (binary) | 5.0.0 Release    | [Download](https://repo.huaweicloud.com/openharmony/os/5.0.0-Release/hispark_taurus_Linux.tar.gz) | [Download](https://repo.huaweicloud.com/openharmony/os/5.0.0-Release/hispark_taurus_Linux.tar.gz.sha256) | 220.4 MB |
| RK3568 standard system solution (binary)       | 5.0.0 Release    | [Download](https://repo.huaweicloud.com/openharmony/os/5.0.0-Release/dayu200_standard_arm32_20240929.tar.gz)| [Download](https://repo.huaweicloud.com/openharmony/os/5.0.0-Release/dayu200_standard_arm32_20240929.tar.gz.sha256)| 11.7 GB |
| Public SDK package for the standard system (macOS)            | 5.0.0.71 | [Download](https://repo.huaweicloud.com/openharmony/os/5.0.0-Release/ohos-sdk-mac-public.tar.gz) | [Download](https://repo.huaweicloud.com/openharmony/os/5.0.0-Release/ohos-sdk-mac-public.tar.gz.sha256) | 1.3 GB |
| Public SDK package for the standard system (macOS-M1)            | 5.0.0.71  | [Download](https://repo.huaweicloud.com/openharmony/os/5.0.0-Release/L2-SDK-MAC-M1-PUBLIC.tar.gz) | [Download](https://repo.huaweicloud.com/openharmony/os/5.0.0-Release/L2-SDK-MAC-M1-PUBLIC.tar.gz.sha256) | 1.2 GB |
| Public SDK package for the standard system (Windows/Linux)  | 5.0.0.71   | [Download](https://repo.huaweicloud.com/openharmony/os/5.0.0-Release/ohos-sdk-windows_linux-public.tar.gz) | [Download](https://repo.huaweicloud.com/openharmony/os/5.0.0-Release/ohos-sdk-windows_linux-public.tar.gz.sha256) | 2.5 GB |


## Resolved Issues

**Table 3** Resolved issues

| Issue No.| Description| 
| -------- | -------- |
| IA686U | There is a high probability that a C++ crash occurs in libace_napi.z.so of the OS_FFRT_2_0 thread in the com.ohos.photos process.|
| I9YC9X | There is a high probability that system freezing occurs in libark_jsruntime.so due to LIFECYCLE_TIMEOUT in the com.ohos.camera process.|
| I9TE52 | There is a possibility that app freezing occurs in libark_jsruntime.so due to THREAD_BLOCK_6S in the com.ohos.photos process.|
| I9TDUU | Key application: There is a low probability that app freezing occurs in libace_compatible.z.so due to THREAD_BLOCK_6S in the ohos.samples.distributedcalc process.|
| I9TE5K | There is a low probability that app freezing occurs in libunwind.z.so due to THREAD_BLOCK_6S in the com.ohos.photos process.|
| I9TJGB | There is a low probability that a C++ crash occurs in libmali-bifrost-g52-g7p0-ohos.so of the RSRenderThread thread in the com.ohos.camera process.|
| IA5EC3 | There is a low probability that app freezing occurs in libskia_canvaskit.z.so due to THREAD_BLOCK_6S in the com.ohos.updateapp process.|
| IA5I3D | There is a low probability that app freezing occurs in librender_service_base.z.so due to THREAD_BLOCK_6S in the com.ohos.smartperf process.|
| IA4G47 | There is an extremely low probability that a C++ crash occurs in libhcodec.z.so of the av_codec_service thread of the av_codec_service process.|
| I9TDMQ | Key application: There is an extremely low probability that app freezing occurs in libskia_canvaskit.z.so due to THREAD_BLOCK_6S in the com.ohos.settings process.|


## Unfixed Vulnerabilities

**Table 4** Known issues

| Issue No.| Description| Impact| To Be Resolved By| 
| -------- | -------- | -------- | -------- |
| I9S5ZN | There is a low probability that app freezing occurs in libunwind.z.so due to THREAD_BLOCK_6S in the com.ohos.settings process.| The Settings page freezes.<br>Workaround: Restart the Settings application.| 2024-10-15| 
| I9S600 | There is a low probability that app freezing occurs in libark_jsruntime.so due to THREAD_BLOCK_6S in the com.ohos.settings process.| The Settings page freezes.<br>Workaround: Restart the Settings application.| 2024-10-15| 
| IAB2U3<br>IAK2J2 | There is a low probability that a C++ crash occurs in libaudio_client.z.so of the OS_APAsyncRunne thread of the audio_server process.| This issue does not affect user services. No workaround is required.| 2024-10-15| 
| IAIRFB | There is a low probability that a C++ crash occurs in libweb_engine.so of the com.ohos.note thread of the com.ohos.note process.| The application will exit unexpectedly. This issue can be resolved by restarting the application.| 2024-10-15| 
| I9SXZ8 | There is a low probability that app freezing occurs in libark_jsruntime.so due to THREAD_BLOCK_6S in the com.ohos.contacts process.| The application freezes when you open the Contacts application to query call records. This issue can be resolved by restarting the Contacts application.| 2024-10-15| 
| IAKLLD | There is a low probability that a C++ crash occurs in libaudio_policy_service.z.so of the SaInit2 thread of the audio_server process.| The process restarts. This issue does not affect user services. No workaround is required.| 2024-10-15| 
| IA56CU | There is a low probability that a C++ crash occurs in libweb_engine.so of the com.ohos.note thread of the com.ohos.note process.| The application will exit unexpectedly. This issue can be resolved by restarting the application.| 2024-09-30| 
| IA5AMJ | There is a low probability that app freezing occurs in libark_jsruntime.so due to THREAD_BLOCK_6S in the com.ohos.launcher process.| The screen freezes for about 3 seconds when you access the multi-task screen. After the loading is complete, the screen recovers.| 2024-09-30| 
| IA5AIT | There is a low probability that system freezing occurs in render_service due to SERVICE_BLOCK.| The application screen freezes and does not respond. This issue can be resolved by restarting the device.| 2024-10-15| 
| IA6RH6 | There is a high probability that app freezing occurs in libbtframework.z.so due to THREAD_BLOCK_6S in the com.ohos.settings process.| The Settings application might not respond. This issue can be resolved by restarting the Settings application.| 2024-10-15| 
| IA6RFX | There is a high probability that a C++ crash occurs in libbtservice.z.so of the OSaInit0 thread in the bluetooth_service process.| Bluetooth-related application might crash. This issue can be resolved by restarting the application.| 2024-10-15| 
| IA8KGR | There is a low probability that a C++ crash occurs in libbluetooth_server.z.so of the OS_IPC_12_22172 thread of the bluetooth_service process.| Bluetooth-related application might crash. This issue can be resolved by restarting the application.| 2024-10-15| 
| IAQC64 | Randomly open several applications and then open the Settings application. When you return to the home screen and repeatedly access the background interface, the Settings application may encounter a memory leakage of 32 KB for each operation.| The Settings application may exit unexpectedly. This issue can be resolved by restarting the application.| 2024-10-15| 
| IASE04 | In the memory test of OpenHarmony on the RK3568 development board, the resident memory of the render_service process exceeds the baseline (31 MB).| The memory usage of the entire system is higher than expected.| 2024-10-15| 
| IASDWO | The sliding frame rate for accessing the Weibo home page through a browser is lower than the specification baseline.| Browsing experience is affected.| 2024-10-15| 
