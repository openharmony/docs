# OpenHarmony 1.0.1 \(2021-03-15\)<a name="EN-US_TOPIC_0000001125880475"></a>

-   [Overview](#section1677664815431)
-   [Kernel](#section11256141314463)
    -   [New Features](#section1834713384464)
    -   [Modified Features](#section6894155811483)

-   [Pan-sensor](#section457103914819)
    -   [New Features](#section1157114391480)

-   [Globalization](#section13453154420488)
    -   [New Features](#section7453174417481)

-   [JS Application Framework](#section146946144818)
    -   [New Features](#section16654654819)
    -   [Modified Features](#section16114654811)
    -   [Deleted Features](#section7634619486)

-   [Testing](#section5857174710485)
    -   [New Features](#section4857247154819)

-   [Graphics](#section116345457492)
    -   [New Features](#section526413158501)
    -   [Modified Features](#section112652156501)

-   [Utils](#section981315393543)
    -   [New Features](#section168131939145418)

-   [Driver](#section1793134012548)
    -   [New Features](#section69313406541)
    -   [Modified Features](#section10931340175420)

-   [Intelligent Soft Bus](#section11286194113540)
    -   [New Features](#section14286104112546)

-   [Security](#section4535841205411)
    -   [New Features](#section35351941175420)

-   [AI](#section11847124175419)
    -   [New Features](#section148472413546)

-   [Update](#section09814210543)
    -   [New Features](#section7981542105417)

-   [XTS](#section429384295416)
    -   [New Features](#section929316426547)
    -   [Modified Features](#section829419420543)

-   [Compilation and Building](#section104691342105411)
    -   [New Features](#section34699428546)
    -   [Modified Features](#section946974210546)

-   [Power Management](#section13166639141617)
    -   [New Features](#section313912368292)

-   [Module Repository Optimization](#section13139145855718)

## Overview<a name="section1677664815431"></a>

OpenHarmony 1.0.1 supports more subsystems, including the AI, power management, pan-sensor, and update subsystems, and provides a unified AI engine framework. The LiteOS Cortex-M kernel has been reconstructed for porting third-party chips to OpenHarmony. The driver subsystem provides models for the WLAN, sensor, input, and display drivers. The graphics subsystem has been optimized for an enhanced UI and improved performance and memory for the JS application framework. In addition, the directory structure and module repositories have been significantly improved.

## Kernel<a name="section11256141314463"></a>

### New Features<a name="section1834713384464"></a>

-   The LiteOS Cortex-M kernel supports the Cortex-M7, Cortex-M33, and RISC-V chip architecture, and the corresponding samples are provided.
-   The LiteOS Cortex-M kernel supports the memory protection unit \(MPU\).
-   The LiteOS Cortex-M kernel supports some POSIX APIs.
-   The LiteOS Cortex-M kernel supports the FatFS file system.
-   The LiteOS Cortex-M kernel supports the registration of exception callbacks.
-   The architecture of the LiteOS Cortex-M kernel has been adjusted for third-party chips to adapt to OpenHarmony.
-   The LiteOS Cortex-M and LiteOS Cortex-A kernels support the heap memory debugging functionalities, covering memory leakage, illegal access to the memory, and memory statistics.
-   The LiteOS Cortex-M and LiteOS Cortex-A kernels support the TLSF heap memory algorithm, which improves the efficiency of memory application and release and reduces the fragmentation rate.

### Modified Features<a name="section6894155811483"></a>

-   LiteOS Cortex-A scheduling has been optimized.

## Pan-sensor<a name="section457103914819"></a>

### New Features<a name="section1157114391480"></a>

-   A sensor module has been added. You can now query the sensor list, enable or disable a sensor, subscribe to or unsubscribe from sensor data, set the data reporting mode of a sensor, and set sensor options such as the data sampling interval.

## Globalization<a name="section13453154420488"></a>

### New Features<a name="section7453174417481"></a>

-   C/C++ APIs have been added for number, date, time, and singular-plural formatting in 79 languages.

## JS Application Framework<a name="section146946144818"></a>

### New Features<a name="section16654654819"></a>

-   A global JavaScript UI attribute,  **opacity**, has been added.
-   A  **prompt.showDialog**  API has been added.
-   A QR code component  **qrcode**  has been added.
-   Event pop-ups have been added.

### Modified Features<a name="section16114654811"></a>

-   Internationalization has been improved, with quicker page redirections. Number internationalization and time/date conversions are now available.
-   The UI layout has been enhanced, with percentage values supported for some styles.
-   The size adaptation capabilities of the  **input**  and  **switch**  components have been enhanced.
-   The  **image**  component supports access to images in an application's private directory.
-   The  **image-animator**  component allows you to specify the end frame.
-   Some APIs have been made available for the  **canvas**  component.
-   Some return fields have been added for the  **device.getInfo**  API.
-   DFX can trace methods that encounter exceptions and output a list of such methods.

### Deleted Features<a name="section7634619486"></a>

-   Backtracking is no longer supported for internationalization functions.

## Testing<a name="section5857174710485"></a>

### New Features<a name="section4857247154819"></a>

-   The testing tool can filter test cases to execute based on the case level.
-   Demo test cases have been added.

## Graphics<a name="section116345457492"></a>

### New Features<a name="section526413158501"></a>

-   Component rotation, scaling, and opacity management have been added.
-   Event pop-ups and the crown rotation event have been added.
-   There is now GIF image parsing and display, percentage-based width and height layout, and video and QR code controls.

### Modified Features<a name="section112652156501"></a>

-   Partial rendering and SIMD performance have been optimized.

## Utils<a name="section981315393543"></a>

### New Features<a name="section168131939145418"></a>

-   System attribute dumping is supported.
-   Memory pool management APIs have been added for upper-layer modules.

## Driver<a name="section1793134012548"></a>

### New Features<a name="section69313406541"></a>

-   The sensor, input, and display driver models have been added.
-   The MIPI DSI and pulse width modulation \(PWM\) have been added.
-   Hardware Driver Interfaces \(HDIs\) and Wi-Fi flow control have been added.
-   The I/O service grouping feature has been added for the Hardware Driver Foundation \(HDF\).

### Modified Features<a name="section10931340175420"></a>

-   Driver loading has been optimized. It can now be accomplished in segmented parts.

## Intelligent Soft Bus<a name="section11286194113540"></a>

### New Features<a name="section14286104112546"></a>

-   A Wi-Fi Aware module has been added.
-   IPC supports non-aligned marshalling.

## Security<a name="section4535841205411"></a>

### New Features<a name="section35351941175420"></a>

-   HUKS provides the SHA-256, RSA-3072, RSA-2048, AES-128, and ECC security algorithms and APIs, as well as key management and storage.
-   The lightweight HiChain is available for managing and authenticating device groups, and ensuring the communication security based on the Intelligent Soft Bus. It does not require device login using an account. It also provides APIs for system services and applications.
-   A unified permission management system has been added to manage permissions for lightweight devices.

## AI<a name="section11847124175419"></a>

### New Features<a name="section148472413546"></a>

-   A unified AI engine framework has been added to implement quick integration of AI algorithm plug-ins. The framework consists of plug-in management, module management, and communications management modules. This framework provides lifecycle management and allows for on-demand deployment of AI algorithms.
-   A developer guide, and two AI capability plug-ins developed based on the AI engine framework and two AI application samples are provided for you to quickly integrate AI algorithms in the AI engine framework.

## Update<a name="section09814210543"></a>

### New Features<a name="section7981542105417"></a>

-   An update capability framework for mini-system devices has been added. It provides APIs for update package verification, parsing, and installation.

## XTS<a name="section429384295416"></a>

### New Features<a name="section929316426547"></a>

-   AI, DFX, globalization, and OTA compatibility test cases have been added.

### Modified Features<a name="section829419420543"></a>

-   Capabilities for the application framework, Intelligent Soft Bus, distributed scheduler, IoT, and kernel have been enhanced.

## Compilation and Building<a name="section104691342105411"></a>

### New Features<a name="section34699428546"></a>

-   The command line tool hb has been added. It provides the  **hb set**  and  **hb build**  commands for building in the source code directory or any subdirectory.
-   Components provided by independent chip vendors are supported.
-   Components can be built independently based on the component name.
-   The build toolchain and options can be customized for different development boards.

### Modified Features<a name="section946974210546"></a>

-   The product configuration has been decoupled from the  **build\_lite**  repository and is stored in  **vendor/solution vendor/product/config.json**.

## Power Management<a name="section13166639141617"></a>

### New Features<a name="section313912368292"></a>

-   Battery level query is now supported.
-   Always-on screen functionalities have been added, along with corresponding APIs.

## Module Repository Optimization<a name="section13139145855718"></a>

<a name="table135021051501"></a>
<table><thead align="left"><tr id="row128991056015"><th class="cellrowborder" valign="top" width="33.36%" id="mcps1.1.4.1.1"><p id="p78991551504"><a name="p78991551504"></a><a name="p78991551504"></a>OpenHarmony 1.0</p>
</th>
<th class="cellrowborder" valign="top" width="33.43%" id="mcps1.1.4.1.2"><p id="p11899135701"><a name="p11899135701"></a><a name="p11899135701"></a>OpenHarmony 1.0.1</p>
</th>
<th class="cellrowborder" valign="top" width="33.21%" id="mcps1.1.4.1.3"><p id="p20899554011"><a name="p20899554011"></a><a name="p20899554011"></a>Optimization</p>
</th>
</tr>
</thead>
<tbody><tr id="row18991355019"><td class="cellrowborder" valign="top" width="33.36%" headers="mcps1.1.4.1.1 "><p id="p38991651802"><a name="p38991651802"></a><a name="p38991651802"></a>ace_lite_jsfwk</p>
</td>
<td class="cellrowborder" valign="top" width="33.43%" headers="mcps1.1.4.1.2 "><p id="p28991051202"><a name="p28991051202"></a><a name="p28991051202"></a>ace_engine_lite</p>
</td>
<td class="cellrowborder" valign="top" width="33.21%" headers="mcps1.1.4.1.3 "><p id="p4899851503"><a name="p4899851503"></a><a name="p4899851503"></a>The repository name has been changed.</p>
</td>
</tr>
<tr id="row38991351015"><td class="cellrowborder" valign="top" width="33.36%" headers="mcps1.1.4.1.1 "><p id="p1989910515019"><a name="p1989910515019"></a><a name="p1989910515019"></a>ace_interfaces_innerkits_builtin</p>
</td>
<td class="cellrowborder" valign="top" width="33.43%" headers="mcps1.1.4.1.2 ">&nbsp;&nbsp;</td>
<td class="cellrowborder" valign="top" width="33.21%" headers="mcps1.1.4.1.3 "><p id="p48991551507"><a name="p48991551507"></a><a name="p48991551507"></a>Read-only archiving</p>
</td>
</tr>
<tr id="row16899454019"><td class="cellrowborder" valign="top" width="33.36%" headers="mcps1.1.4.1.1 ">&nbsp;&nbsp;</td>
<td class="cellrowborder" valign="top" width="33.43%" headers="mcps1.1.4.1.2 "><p id="p2899351009"><a name="p2899351009"></a><a name="p2899351009"></a>ai_engine</p>
</td>
<td class="cellrowborder" valign="top" width="33.21%" headers="mcps1.1.4.1.3 "><p id="p58991256010"><a name="p58991256010"></a><a name="p58991256010"></a>New module</p>
</td>
</tr>
<tr id="row14899155409"><td class="cellrowborder" valign="top" width="33.36%" headers="mcps1.1.4.1.1 "><p id="p1789916520011"><a name="p1789916520011"></a><a name="p1789916520011"></a>hiviewdfx_frameworks_hievent_lite</p>
</td>
<td class="cellrowborder" valign="top" width="33.43%" headers="mcps1.1.4.1.2 "><p id="p9899551909"><a name="p9899551909"></a><a name="p9899551909"></a>hiviewdfx_hievent_lite</p>
</td>
<td class="cellrowborder" valign="top" width="33.21%" headers="mcps1.1.4.1.3 "><p id="p18991851203"><a name="p18991851203"></a><a name="p18991851203"></a>The repository name has been changed.</p>
</td>
</tr>
<tr id="row789911515019"><td class="cellrowborder" valign="top" width="33.36%" headers="mcps1.1.4.1.1 "><p id="p4900651807"><a name="p4900651807"></a><a name="p4900651807"></a>hiviewdfx_frameworks_hilog_lite</p>
</td>
<td class="cellrowborder" valign="top" width="33.43%" headers="mcps1.1.4.1.2 "><p id="p1900151503"><a name="p1900151503"></a><a name="p1900151503"></a>hiviewdfx_hilog_lite</p>
</td>
<td class="cellrowborder" valign="top" width="33.21%" headers="mcps1.1.4.1.3 "><p id="p19001258015"><a name="p19001258015"></a><a name="p19001258015"></a>The repository name has been changed.</p>
</td>
</tr>
<tr id="row090015516018"><td class="cellrowborder" valign="top" width="33.36%" headers="mcps1.1.4.1.1 "><p id="p189001351400"><a name="p189001351400"></a><a name="p189001351400"></a>hiviewdfx_utils_lite</p>
</td>
<td class="cellrowborder" valign="top" width="33.43%" headers="mcps1.1.4.1.2 "><p id="p89001953019"><a name="p89001953019"></a><a name="p89001953019"></a>hiviewdfx_hiview_lite</p>
</td>
<td class="cellrowborder" valign="top" width="33.21%" headers="mcps1.1.4.1.3 "><p id="p89007519012"><a name="p89007519012"></a><a name="p89007519012"></a>The repository name has been changed.</p>
</td>
</tr>
<tr id="row8900351206"><td class="cellrowborder" valign="top" width="33.36%" headers="mcps1.1.4.1.1 "><p id="p18900185100"><a name="p18900185100"></a><a name="p18900185100"></a>hiviewdfx_frameworks_ddrdump_lite</p>
</td>
<td class="cellrowborder" valign="top" width="33.43%" headers="mcps1.1.4.1.2 ">&nbsp;&nbsp;</td>
<td class="cellrowborder" valign="top" width="33.21%" headers="mcps1.1.4.1.3 "><p id="p1490018511020"><a name="p1490018511020"></a><a name="p1490018511020"></a>Read-only archiving</p>
</td>
</tr>
<tr id="row169001451604"><td class="cellrowborder" valign="top" width="33.36%" headers="mcps1.1.4.1.1 "><p id="p179001854019"><a name="p179001854019"></a><a name="p179001854019"></a>hiviewdfx_interfaces_innerkits_hievent_lite</p>
</td>
<td class="cellrowborder" valign="top" width="33.43%" headers="mcps1.1.4.1.2 ">&nbsp;&nbsp;</td>
<td class="cellrowborder" valign="top" width="33.21%" headers="mcps1.1.4.1.3 "><p id="p390011512017"><a name="p390011512017"></a><a name="p390011512017"></a>Read-only archiving</p>
</td>
</tr>
<tr id="row1990015602"><td class="cellrowborder" valign="top" width="33.36%" headers="mcps1.1.4.1.1 "><p id="p129001151404"><a name="p129001151404"></a><a name="p129001151404"></a>hiviewdfx_interfaces_innerkits_hilog</p>
</td>
<td class="cellrowborder" valign="top" width="33.43%" headers="mcps1.1.4.1.2 ">&nbsp;&nbsp;</td>
<td class="cellrowborder" valign="top" width="33.21%" headers="mcps1.1.4.1.3 "><p id="p590025106"><a name="p590025106"></a><a name="p590025106"></a>Read-only archiving</p>
</td>
</tr>
<tr id="row09002051508"><td class="cellrowborder" valign="top" width="33.36%" headers="mcps1.1.4.1.1 "><p id="p390095603"><a name="p390095603"></a><a name="p390095603"></a>hiviewdfx_interfaces_kits_hilog</p>
</td>
<td class="cellrowborder" valign="top" width="33.43%" headers="mcps1.1.4.1.2 ">&nbsp;&nbsp;</td>
<td class="cellrowborder" valign="top" width="33.21%" headers="mcps1.1.4.1.3 "><p id="p1390025504"><a name="p1390025504"></a><a name="p1390025504"></a>Read-only archiving</p>
</td>
</tr>
<tr id="row1900454019"><td class="cellrowborder" valign="top" width="33.36%" headers="mcps1.1.4.1.1 "><p id="p690013514012"><a name="p690013514012"></a><a name="p690013514012"></a>hiviewdfx_interfaces_kits_hilog_lite</p>
</td>
<td class="cellrowborder" valign="top" width="33.43%" headers="mcps1.1.4.1.2 ">&nbsp;&nbsp;</td>
<td class="cellrowborder" valign="top" width="33.21%" headers="mcps1.1.4.1.3 "><p id="p15900956013"><a name="p15900956013"></a><a name="p15900956013"></a>Read-only archiving</p>
</td>
</tr>
<tr id="row13900951602"><td class="cellrowborder" valign="top" width="33.36%" headers="mcps1.1.4.1.1 "><p id="p18900051106"><a name="p18900051106"></a><a name="p18900051106"></a>hiviewdfx_services_hilogcat_lite</p>
</td>
<td class="cellrowborder" valign="top" width="33.43%" headers="mcps1.1.4.1.2 ">&nbsp;&nbsp;</td>
<td class="cellrowborder" valign="top" width="33.21%" headers="mcps1.1.4.1.3 "><p id="p12900155602"><a name="p12900155602"></a><a name="p12900155602"></a>Read-only archiving</p>
</td>
</tr>
<tr id="row59001951809"><td class="cellrowborder" valign="top" width="33.36%" headers="mcps1.1.4.1.1 "><p id="p1190095906"><a name="p1190095906"></a><a name="p1190095906"></a>hiviewdfx_services_hiview_lite</p>
</td>
<td class="cellrowborder" valign="top" width="33.43%" headers="mcps1.1.4.1.2 ">&nbsp;&nbsp;</td>
<td class="cellrowborder" valign="top" width="33.21%" headers="mcps1.1.4.1.3 "><p id="p69001951103"><a name="p69001951103"></a><a name="p69001951103"></a>Read-only archiving</p>
</td>
</tr>
<tr id="row149001453013"><td class="cellrowborder" valign="top" width="33.36%" headers="mcps1.1.4.1.1 "><p id="p179001152013"><a name="p179001152013"></a><a name="p179001152013"></a>iothardware_hals_wifiiot_lite</p>
</td>
<td class="cellrowborder" valign="top" width="33.43%" headers="mcps1.1.4.1.2 ">&nbsp;&nbsp;</td>
<td class="cellrowborder" valign="top" width="33.21%" headers="mcps1.1.4.1.3 "><p id="p2901859018"><a name="p2901859018"></a><a name="p2901859018"></a>Read-only archiving</p>
</td>
</tr>
<tr id="row199011654015"><td class="cellrowborder" valign="top" width="33.36%" headers="mcps1.1.4.1.1 "><p id="p1490115301"><a name="p1490115301"></a><a name="p1490115301"></a>iothardware_interfaces_kits_wifiiot_lite</p>
</td>
<td class="cellrowborder" valign="top" width="33.43%" headers="mcps1.1.4.1.2 ">&nbsp;&nbsp;</td>
<td class="cellrowborder" valign="top" width="33.21%" headers="mcps1.1.4.1.3 "><p id="p7901653019"><a name="p7901653019"></a><a name="p7901653019"></a>Read-only archiving</p>
</td>
</tr>
<tr id="row2090125101"><td class="cellrowborder" valign="top" width="33.36%" headers="mcps1.1.4.1.1 "><p id="p190117513010"><a name="p190117513010"></a><a name="p190117513010"></a>iothardware_frameworks_wifiiot_lite</p>
</td>
<td class="cellrowborder" valign="top" width="33.43%" headers="mcps1.1.4.1.2 "><p id="p189011351501"><a name="p189011351501"></a><a name="p189011351501"></a>iothardware_peripheral</p>
</td>
<td class="cellrowborder" valign="top" width="33.21%" headers="mcps1.1.4.1.3 "><p id="p1190119515013"><a name="p1190119515013"></a><a name="p1190119515013"></a>The repository name has been changed.</p>
</td>
</tr>
<tr id="row5901175902"><td class="cellrowborder" valign="top" width="33.36%" headers="mcps1.1.4.1.1 ">&nbsp;&nbsp;</td>
<td class="cellrowborder" valign="top" width="33.43%" headers="mcps1.1.4.1.2 "><p id="p109011755019"><a name="p109011755019"></a><a name="p109011755019"></a>applications_camera_sample_communication</p>
</td>
<td class="cellrowborder" valign="top" width="33.21%" headers="mcps1.1.4.1.3 "><p id="p209011455011"><a name="p209011455011"></a><a name="p209011455011"></a>New module</p>
</td>
</tr>
<tr id="row12901251206"><td class="cellrowborder" valign="top" width="33.36%" headers="mcps1.1.4.1.1 ">&nbsp;&nbsp;</td>
<td class="cellrowborder" valign="top" width="33.43%" headers="mcps1.1.4.1.2 "><p id="p12901051000"><a name="p12901051000"></a><a name="p12901051000"></a>applications_camera_screensaver_app</p>
</td>
<td class="cellrowborder" valign="top" width="33.21%" headers="mcps1.1.4.1.3 "><p id="p15901758014"><a name="p15901758014"></a><a name="p15901758014"></a>New module</p>
</td>
</tr>
<tr id="row79011551003"><td class="cellrowborder" valign="top" width="33.36%" headers="mcps1.1.4.1.1 ">&nbsp;&nbsp;</td>
<td class="cellrowborder" valign="top" width="33.43%" headers="mcps1.1.4.1.2 "><p id="p1090111513011"><a name="p1090111513011"></a><a name="p1090111513011"></a>sensors_miscdevice_lite</p>
</td>
<td class="cellrowborder" valign="top" width="33.21%" headers="mcps1.1.4.1.3 "><p id="p19011152018"><a name="p19011152018"></a><a name="p19011152018"></a>New module</p>
</td>
</tr>
<tr id="row18901751205"><td class="cellrowborder" valign="top" width="33.36%" headers="mcps1.1.4.1.1 ">&nbsp;&nbsp;</td>
<td class="cellrowborder" valign="top" width="33.43%" headers="mcps1.1.4.1.2 "><p id="p7901051301"><a name="p7901051301"></a><a name="p7901051301"></a>sensors_sensor_lite</p>
</td>
<td class="cellrowborder" valign="top" width="33.21%" headers="mcps1.1.4.1.3 "><p id="p7901252014"><a name="p7901252014"></a><a name="p7901252014"></a>New module</p>
</td>
</tr>
<tr id="row1990114512019"><td class="cellrowborder" valign="top" width="33.36%" headers="mcps1.1.4.1.1 "><p id="p10901135405"><a name="p10901135405"></a><a name="p10901135405"></a>xts_tools_lite</p>
</td>
<td class="cellrowborder" valign="top" width="33.43%" headers="mcps1.1.4.1.2 "><p id="p16901551807"><a name="p16901551807"></a><a name="p16901551807"></a>xts_tools</p>
</td>
<td class="cellrowborder" valign="top" width="33.21%" headers="mcps1.1.4.1.3 "><p id="p169011451706"><a name="p169011451706"></a><a name="p169011451706"></a>The repository name has been changed.</p>
</td>
</tr>
<tr id="row49019510016"><td class="cellrowborder" valign="top" width="33.36%" headers="mcps1.1.4.1.1 "><p id="p390113517013"><a name="p390113517013"></a><a name="p390113517013"></a>security_services_iam_lite</p>
</td>
<td class="cellrowborder" valign="top" width="33.43%" headers="mcps1.1.4.1.2 "><p id="p590112515010"><a name="p590112515010"></a><a name="p590112515010"></a>security_permission</p>
</td>
<td class="cellrowborder" valign="top" width="33.21%" headers="mcps1.1.4.1.3 "><p id="p179011251300"><a name="p179011251300"></a><a name="p179011251300"></a>The repository name has been changed.</p>
</td>
</tr>
<tr id="row1190120511014"><td class="cellrowborder" valign="top" width="33.36%" headers="mcps1.1.4.1.1 "><p id="p29021551601"><a name="p29021551601"></a><a name="p29021551601"></a>security_interfaces_innerkits_iam_lite</p>
</td>
<td class="cellrowborder" valign="top" width="33.43%" headers="mcps1.1.4.1.2 ">&nbsp;&nbsp;</td>
<td class="cellrowborder" valign="top" width="33.21%" headers="mcps1.1.4.1.3 "><p id="p99021751009"><a name="p99021751009"></a><a name="p99021751009"></a>Read-only archiving</p>
</td>
</tr>
<tr id="row15902153011"><td class="cellrowborder" valign="top" width="33.36%" headers="mcps1.1.4.1.1 "><p id="p1390216512012"><a name="p1390216512012"></a><a name="p1390216512012"></a>security_interfaces_kits_iam_lite</p>
</td>
<td class="cellrowborder" valign="top" width="33.43%" headers="mcps1.1.4.1.2 ">&nbsp;&nbsp;</td>
<td class="cellrowborder" valign="top" width="33.21%" headers="mcps1.1.4.1.3 "><p id="p189021551008"><a name="p189021551008"></a><a name="p189021551008"></a>Read-only archiving</p>
</td>
</tr>
<tr id="row5902757019"><td class="cellrowborder" valign="top" width="33.36%" headers="mcps1.1.4.1.1 "><p id="p3902750014"><a name="p3902750014"></a><a name="p3902750014"></a>security_services_secure_os</p>
</td>
<td class="cellrowborder" valign="top" width="33.43%" headers="mcps1.1.4.1.2 "><p id="p89021451008"><a name="p89021451008"></a><a name="p89021451008"></a>security_itrustee_ree_lite</p>
</td>
<td class="cellrowborder" valign="top" width="33.21%" headers="mcps1.1.4.1.3 "><p id="p790295805"><a name="p790295805"></a><a name="p790295805"></a>The repository name has been changed.</p>
</td>
</tr>
<tr id="row13902158011"><td class="cellrowborder" valign="top" width="33.36%" headers="mcps1.1.4.1.1 "><p id="p15902185306"><a name="p15902185306"></a><a name="p15902185306"></a>security_interfaces_innerkits_secure_os</p>
</td>
<td class="cellrowborder" valign="top" width="33.43%" headers="mcps1.1.4.1.2 ">&nbsp;&nbsp;</td>
<td class="cellrowborder" valign="top" width="33.21%" headers="mcps1.1.4.1.3 "><p id="p18902459015"><a name="p18902459015"></a><a name="p18902459015"></a>Read-only archiving</p>
</td>
</tr>
<tr id="row2902651507"><td class="cellrowborder" valign="top" width="33.36%" headers="mcps1.1.4.1.1 "><p id="p2090295504"><a name="p2090295504"></a><a name="p2090295504"></a>security_frameworks_secure_os</p>
</td>
<td class="cellrowborder" valign="top" width="33.43%" headers="mcps1.1.4.1.2 ">&nbsp;&nbsp;</td>
<td class="cellrowborder" valign="top" width="33.21%" headers="mcps1.1.4.1.3 "><p id="p4902252003"><a name="p4902252003"></a><a name="p4902252003"></a>Read-only archiving</p>
</td>
</tr>
<tr id="row12902115409"><td class="cellrowborder" valign="top" width="33.36%" headers="mcps1.1.4.1.1 "><p id="p390214518017"><a name="p390214518017"></a><a name="p390214518017"></a>security_services_app_verify</p>
</td>
<td class="cellrowborder" valign="top" width="33.43%" headers="mcps1.1.4.1.2 "><p id="p159021851709"><a name="p159021851709"></a><a name="p159021851709"></a>security_appverify</p>
</td>
<td class="cellrowborder" valign="top" width="33.21%" headers="mcps1.1.4.1.3 "><p id="p209021751609"><a name="p209021751609"></a><a name="p209021751609"></a>The repository name has been changed.</p>
</td>
</tr>
<tr id="row790215515011"><td class="cellrowborder" valign="top" width="33.36%" headers="mcps1.1.4.1.1 "><p id="p17902165204"><a name="p17902165204"></a><a name="p17902165204"></a>security_interfaces_innerkits_app_verify</p>
</td>
<td class="cellrowborder" valign="top" width="33.43%" headers="mcps1.1.4.1.2 ">&nbsp;&nbsp;</td>
<td class="cellrowborder" valign="top" width="33.21%" headers="mcps1.1.4.1.3 "><p id="p3902145906"><a name="p3902145906"></a><a name="p3902145906"></a>Read-only archiving</p>
</td>
</tr>
<tr id="row189021251020"><td class="cellrowborder" valign="top" width="33.36%" headers="mcps1.1.4.1.1 "><p id="p39021051909"><a name="p39021051909"></a><a name="p39021051909"></a>security_services_hichainsdk_lite</p>
</td>
<td class="cellrowborder" valign="top" width="33.43%" headers="mcps1.1.4.1.2 "><p id="p99021551601"><a name="p99021551601"></a><a name="p99021551601"></a>security_deviceauth</p>
</td>
<td class="cellrowborder" valign="top" width="33.21%" headers="mcps1.1.4.1.3 "><p id="p4902755017"><a name="p4902755017"></a><a name="p4902755017"></a>The repository name has been changed.</p>
</td>
</tr>
<tr id="row69024513016"><td class="cellrowborder" valign="top" width="33.36%" headers="mcps1.1.4.1.1 "><p id="p11902151703"><a name="p11902151703"></a><a name="p11902151703"></a>security_interfaces_innerkits_hichainsdk_lite</p>
</td>
<td class="cellrowborder" valign="top" width="33.43%" headers="mcps1.1.4.1.2 ">&nbsp;&nbsp;</td>
<td class="cellrowborder" valign="top" width="33.21%" headers="mcps1.1.4.1.3 "><p id="p16902135004"><a name="p16902135004"></a><a name="p16902135004"></a>Read-only archiving</p>
</td>
</tr>
<tr id="row7902751304"><td class="cellrowborder" valign="top" width="33.36%" headers="mcps1.1.4.1.1 "><p id="p290217510010"><a name="p290217510010"></a><a name="p290217510010"></a>security_services_huks_lite</p>
</td>
<td class="cellrowborder" valign="top" width="33.43%" headers="mcps1.1.4.1.2 "><p id="p129030517016"><a name="p129030517016"></a><a name="p129030517016"></a>security_huks</p>
</td>
<td class="cellrowborder" valign="top" width="33.21%" headers="mcps1.1.4.1.3 "><p id="p1590311518017"><a name="p1590311518017"></a><a name="p1590311518017"></a>The repository name has been changed.</p>
</td>
</tr>
<tr id="row39036518019"><td class="cellrowborder" valign="top" width="33.36%" headers="mcps1.1.4.1.1 "><p id="p49031354014"><a name="p49031354014"></a><a name="p49031354014"></a>security_interfaces_innerkits_huks_lite</p>
</td>
<td class="cellrowborder" valign="top" width="33.43%" headers="mcps1.1.4.1.2 ">&nbsp;&nbsp;</td>
<td class="cellrowborder" valign="top" width="33.21%" headers="mcps1.1.4.1.3 "><p id="p159031151900"><a name="p159031151900"></a><a name="p159031151900"></a>Read-only archiving</p>
</td>
</tr>
<tr id="row11903951002"><td class="cellrowborder" valign="top" width="33.36%" headers="mcps1.1.4.1.1 "><p id="p119032510018"><a name="p119032510018"></a><a name="p119032510018"></a>security_frameworks_crypto_lite</p>
</td>
<td class="cellrowborder" valign="top" width="33.43%" headers="mcps1.1.4.1.2 ">&nbsp;&nbsp;</td>
<td class="cellrowborder" valign="top" width="33.21%" headers="mcps1.1.4.1.3 "><p id="p99031516017"><a name="p99031516017"></a><a name="p99031516017"></a>Read-only archiving</p>
</td>
</tr>
<tr id="row179032052011"><td class="cellrowborder" valign="top" width="33.36%" headers="mcps1.1.4.1.1 "><p id="p4903155907"><a name="p4903155907"></a><a name="p4903155907"></a>security_interfaces_innerkits_crypto_lite</p>
</td>
<td class="cellrowborder" valign="top" width="33.43%" headers="mcps1.1.4.1.2 ">&nbsp;&nbsp;</td>
<td class="cellrowborder" valign="top" width="33.21%" headers="mcps1.1.4.1.3 "><p id="p39031451709"><a name="p39031451709"></a><a name="p39031451709"></a>Read-only archiving</p>
</td>
</tr>
<tr id="row790305404"><td class="cellrowborder" valign="top" width="33.36%" headers="mcps1.1.4.1.1 ">&nbsp;&nbsp;</td>
<td class="cellrowborder" valign="top" width="33.43%" headers="mcps1.1.4.1.2 "><p id="p13903756014"><a name="p13903756014"></a><a name="p13903756014"></a>signcenter_tool</p>
</td>
<td class="cellrowborder" valign="top" width="33.21%" headers="mcps1.1.4.1.3 "><p id="p2090355800"><a name="p2090355800"></a><a name="p2090355800"></a>New module</p>
</td>
</tr>
<tr id="row14903155009"><td class="cellrowborder" valign="top" width="33.36%" headers="mcps1.1.4.1.1 ">&nbsp;&nbsp;</td>
<td class="cellrowborder" valign="top" width="33.43%" headers="mcps1.1.4.1.2 "><p id="p12903155709"><a name="p12903155709"></a><a name="p12903155709"></a>third_party_cryptsetup</p>
</td>
<td class="cellrowborder" valign="top" width="33.21%" headers="mcps1.1.4.1.3 "><p id="p1390315517010"><a name="p1390315517010"></a><a name="p1390315517010"></a>New module</p>
</td>
</tr>
<tr id="row1290315709"><td class="cellrowborder" valign="top" width="33.36%" headers="mcps1.1.4.1.1 ">&nbsp;&nbsp;</td>
<td class="cellrowborder" valign="top" width="33.43%" headers="mcps1.1.4.1.2 "><p id="p1903951609"><a name="p1903951609"></a><a name="p1903951609"></a>third_party_JSON-C</p>
</td>
<td class="cellrowborder" valign="top" width="33.21%" headers="mcps1.1.4.1.3 "><p id="p18903851808"><a name="p18903851808"></a><a name="p18903851808"></a>New module</p>
</td>
</tr>
<tr id="row169031550016"><td class="cellrowborder" valign="top" width="33.36%" headers="mcps1.1.4.1.1 ">&nbsp;&nbsp;</td>
<td class="cellrowborder" valign="top" width="33.43%" headers="mcps1.1.4.1.2 "><p id="p1090318516019"><a name="p1090318516019"></a><a name="p1090318516019"></a>third_party_libuuid</p>
</td>
<td class="cellrowborder" valign="top" width="33.21%" headers="mcps1.1.4.1.3 "><p id="p2090313517013"><a name="p2090313517013"></a><a name="p2090313517013"></a>New module</p>
</td>
</tr>
<tr id="row1290305509"><td class="cellrowborder" valign="top" width="33.36%" headers="mcps1.1.4.1.1 ">&nbsp;&nbsp;</td>
<td class="cellrowborder" valign="top" width="33.43%" headers="mcps1.1.4.1.2 "><p id="p139031053012"><a name="p139031053012"></a><a name="p139031053012"></a>third_party_LVM2</p>
</td>
<td class="cellrowborder" valign="top" width="33.21%" headers="mcps1.1.4.1.3 "><p id="p119039519019"><a name="p119039519019"></a><a name="p119039519019"></a>New module</p>
</td>
</tr>
<tr id="row189031351503"><td class="cellrowborder" valign="top" width="33.36%" headers="mcps1.1.4.1.1 ">&nbsp;&nbsp;</td>
<td class="cellrowborder" valign="top" width="33.43%" headers="mcps1.1.4.1.2 "><p id="p16904652008"><a name="p16904652008"></a><a name="p16904652008"></a>third_party_popt</p>
</td>
<td class="cellrowborder" valign="top" width="33.21%" headers="mcps1.1.4.1.3 "><p id="p690417513011"><a name="p690417513011"></a><a name="p690417513011"></a>New module</p>
</td>
</tr>
<tr id="row13904135302"><td class="cellrowborder" valign="top" width="33.36%" headers="mcps1.1.4.1.1 "><p id="p390410516020"><a name="p390410516020"></a><a name="p390410516020"></a>communication_interfaces_kits_wifi_lite</p>
</td>
<td class="cellrowborder" valign="top" width="33.43%" headers="mcps1.1.4.1.2 ">&nbsp;&nbsp;</td>
<td class="cellrowborder" valign="top" width="33.21%" headers="mcps1.1.4.1.3 "><p id="p1490425305"><a name="p1490425305"></a><a name="p1490425305"></a>Read-only archiving</p>
</td>
</tr>
<tr id="row59041451107"><td class="cellrowborder" valign="top" width="33.36%" headers="mcps1.1.4.1.1 "><p id="p13904145808"><a name="p13904145808"></a><a name="p13904145808"></a>communication_frameworks_wifi_lite</p>
</td>
<td class="cellrowborder" valign="top" width="33.43%" headers="mcps1.1.4.1.2 ">&nbsp;&nbsp;</td>
<td class="cellrowborder" valign="top" width="33.21%" headers="mcps1.1.4.1.3 "><p id="p99045513014"><a name="p99045513014"></a><a name="p99045513014"></a>Read-only archiving</p>
</td>
</tr>
<tr id="row179049518012"><td class="cellrowborder" valign="top" width="33.36%" headers="mcps1.1.4.1.1 ">&nbsp;&nbsp;</td>
<td class="cellrowborder" valign="top" width="33.43%" headers="mcps1.1.4.1.2 "><p id="p13904751702"><a name="p13904751702"></a><a name="p13904751702"></a>communication_wifi_lite</p>
</td>
<td class="cellrowborder" valign="top" width="33.21%" headers="mcps1.1.4.1.3 "><p id="p390410514013"><a name="p390410514013"></a><a name="p390410514013"></a>New module</p>
</td>
</tr>
<tr id="row890412510020"><td class="cellrowborder" valign="top" width="33.36%" headers="mcps1.1.4.1.1 ">&nbsp;&nbsp;</td>
<td class="cellrowborder" valign="top" width="33.43%" headers="mcps1.1.4.1.2 "><p id="p99046513011"><a name="p99046513011"></a><a name="p99046513011"></a>powermgr_powermgr_lite</p>
</td>
<td class="cellrowborder" valign="top" width="33.21%" headers="mcps1.1.4.1.3 "><p id="p1990445707"><a name="p1990445707"></a><a name="p1990445707"></a>New module</p>
</td>
</tr>
<tr id="row1390495903"><td class="cellrowborder" valign="top" width="33.36%" headers="mcps1.1.4.1.1 "><p id="p1390405403"><a name="p1390405403"></a><a name="p1390405403"></a>distributedschedule_services_dtbschedmgr_lite</p>
</td>
<td class="cellrowborder" valign="top" width="33.43%" headers="mcps1.1.4.1.2 "><p id="p18904359010"><a name="p18904359010"></a><a name="p18904359010"></a>distributedschedule_dms_fwk_lite</p>
</td>
<td class="cellrowborder" valign="top" width="33.21%" headers="mcps1.1.4.1.3 "><p id="p59041515012"><a name="p59041515012"></a><a name="p59041515012"></a>The repository name has been changed.</p>
</td>
</tr>
<tr id="row89041511017"><td class="cellrowborder" valign="top" width="33.36%" headers="mcps1.1.4.1.1 "><p id="p4904185205"><a name="p4904185205"></a><a name="p4904185205"></a>distributedschedule_services_safwk_lite</p>
</td>
<td class="cellrowborder" valign="top" width="33.43%" headers="mcps1.1.4.1.2 "><p id="p169041051601"><a name="p169041051601"></a><a name="p169041051601"></a>distributedschedule_safwk_lite</p>
</td>
<td class="cellrowborder" valign="top" width="33.21%" headers="mcps1.1.4.1.3 "><p id="p16904558011"><a name="p16904558011"></a><a name="p16904558011"></a>The repository name has been changed.</p>
</td>
</tr>
<tr id="row129041051309"><td class="cellrowborder" valign="top" width="33.36%" headers="mcps1.1.4.1.1 "><p id="p1990418519016"><a name="p1990418519016"></a><a name="p1990418519016"></a>distributedschedule_services_samgr_lite</p>
</td>
<td class="cellrowborder" valign="top" width="33.43%" headers="mcps1.1.4.1.2 "><p id="p7904451500"><a name="p7904451500"></a><a name="p7904451500"></a>distributedschedule_samgr_lite</p>
</td>
<td class="cellrowborder" valign="top" width="33.21%" headers="mcps1.1.4.1.3 "><p id="p69041515016"><a name="p69041515016"></a><a name="p69041515016"></a>The repository name has been changed.</p>
</td>
</tr>
<tr id="row29041654012"><td class="cellrowborder" valign="top" width="33.36%" headers="mcps1.1.4.1.1 "><p id="p6904251409"><a name="p6904251409"></a><a name="p6904251409"></a>distributedschedule_interfaces_innerkits_samgr_lite</p>
</td>
<td class="cellrowborder" valign="top" width="33.43%" headers="mcps1.1.4.1.2 ">&nbsp;&nbsp;</td>
<td class="cellrowborder" valign="top" width="33.21%" headers="mcps1.1.4.1.3 "><p id="p49054519014"><a name="p49054519014"></a><a name="p49054519014"></a>Read-only archiving</p>
</td>
</tr>
<tr id="row490519515016"><td class="cellrowborder" valign="top" width="33.36%" headers="mcps1.1.4.1.1 "><p id="p1590518513015"><a name="p1590518513015"></a><a name="p1590518513015"></a>distributedschedule_interfaces_kits_samgr_lite</p>
</td>
<td class="cellrowborder" valign="top" width="33.43%" headers="mcps1.1.4.1.2 ">&nbsp;&nbsp;</td>
<td class="cellrowborder" valign="top" width="33.21%" headers="mcps1.1.4.1.3 "><p id="p590512516020"><a name="p590512516020"></a><a name="p590512516020"></a>Read-only archiving</p>
</td>
</tr>
<tr id="row390515106"><td class="cellrowborder" valign="top" width="33.36%" headers="mcps1.1.4.1.1 "><p id="p189051352019"><a name="p189051352019"></a><a name="p189051352019"></a>multimedia_frameworks_audio_lite</p>
</td>
<td class="cellrowborder" valign="top" width="33.43%" headers="mcps1.1.4.1.2 "><p id="p13905651405"><a name="p13905651405"></a><a name="p13905651405"></a>multimedia_audio_lite</p>
</td>
<td class="cellrowborder" valign="top" width="33.21%" headers="mcps1.1.4.1.3 "><p id="p1390511520013"><a name="p1390511520013"></a><a name="p1390511520013"></a>The repository name has been changed.</p>
</td>
</tr>
<tr id="row29051051303"><td class="cellrowborder" valign="top" width="33.36%" headers="mcps1.1.4.1.1 "><p id="p2090535308"><a name="p2090535308"></a><a name="p2090535308"></a>multimedia_frameworks_camera_lite</p>
</td>
<td class="cellrowborder" valign="top" width="33.43%" headers="mcps1.1.4.1.2 "><p id="p6905753013"><a name="p6905753013"></a><a name="p6905753013"></a>multimedia_camera_lite</p>
</td>
<td class="cellrowborder" valign="top" width="33.21%" headers="mcps1.1.4.1.3 "><p id="p2090510511013"><a name="p2090510511013"></a><a name="p2090510511013"></a>The repository name has been changed.</p>
</td>
</tr>
<tr id="row1890565703"><td class="cellrowborder" valign="top" width="33.36%" headers="mcps1.1.4.1.1 "><p id="p69051651509"><a name="p69051651509"></a><a name="p69051651509"></a>multimedia_frameworks_player_lite</p>
</td>
<td class="cellrowborder" valign="top" width="33.43%" headers="mcps1.1.4.1.2 "><p id="p89051758015"><a name="p89051758015"></a><a name="p89051758015"></a>multimedia_media_lite</p>
</td>
<td class="cellrowborder" valign="top" width="33.21%" headers="mcps1.1.4.1.3 "><p id="p109052513016"><a name="p109052513016"></a><a name="p109052513016"></a>The repository name has been changed.</p>
</td>
</tr>
<tr id="row19051050015"><td class="cellrowborder" valign="top" width="33.36%" headers="mcps1.1.4.1.1 "><p id="p139051156020"><a name="p139051156020"></a><a name="p139051156020"></a>multimedia_hals_camera_lite</p>
</td>
<td class="cellrowborder" valign="top" width="33.43%" headers="mcps1.1.4.1.2 ">&nbsp;&nbsp;</td>
<td class="cellrowborder" valign="top" width="33.21%" headers="mcps1.1.4.1.3 "><p id="p1190555805"><a name="p1190555805"></a><a name="p1190555805"></a>Read-only archiving</p>
</td>
</tr>
<tr id="row15905451704"><td class="cellrowborder" valign="top" width="33.36%" headers="mcps1.1.4.1.1 "><p id="p20905651702"><a name="p20905651702"></a><a name="p20905651702"></a>multimedia_frameworks_recorder_lite</p>
</td>
<td class="cellrowborder" valign="top" width="33.43%" headers="mcps1.1.4.1.2 ">&nbsp;&nbsp;</td>
<td class="cellrowborder" valign="top" width="33.21%" headers="mcps1.1.4.1.3 "><p id="p39051251013"><a name="p39051251013"></a><a name="p39051251013"></a>Read-only archiving</p>
</td>
</tr>
<tr id="row209051950012"><td class="cellrowborder" valign="top" width="33.36%" headers="mcps1.1.4.1.1 "><p id="p159051559016"><a name="p159051559016"></a><a name="p159051559016"></a>multimedia_interfaces_kits_audio_lite</p>
</td>
<td class="cellrowborder" valign="top" width="33.43%" headers="mcps1.1.4.1.2 ">&nbsp;&nbsp;</td>
<td class="cellrowborder" valign="top" width="33.21%" headers="mcps1.1.4.1.3 "><p id="p129051653013"><a name="p129051653013"></a><a name="p129051653013"></a>Read-only archiving</p>
</td>
</tr>
<tr id="row7905851019"><td class="cellrowborder" valign="top" width="33.36%" headers="mcps1.1.4.1.1 "><p id="p109054519019"><a name="p109054519019"></a><a name="p109054519019"></a>multimedia_interfaces_kits_camera_lite</p>
</td>
<td class="cellrowborder" valign="top" width="33.43%" headers="mcps1.1.4.1.2 ">&nbsp;&nbsp;</td>
<td class="cellrowborder" valign="top" width="33.21%" headers="mcps1.1.4.1.3 "><p id="p79063518015"><a name="p79063518015"></a><a name="p79063518015"></a>Read-only archiving</p>
</td>
</tr>
<tr id="row79061552006"><td class="cellrowborder" valign="top" width="33.36%" headers="mcps1.1.4.1.1 "><p id="p59062516015"><a name="p59062516015"></a><a name="p59062516015"></a>multimedia_interfaces_kits_player_lite</p>
</td>
<td class="cellrowborder" valign="top" width="33.43%" headers="mcps1.1.4.1.2 ">&nbsp;&nbsp;</td>
<td class="cellrowborder" valign="top" width="33.21%" headers="mcps1.1.4.1.3 "><p id="p5906195601"><a name="p5906195601"></a><a name="p5906195601"></a>Read-only archiving</p>
</td>
</tr>
<tr id="row9906651205"><td class="cellrowborder" valign="top" width="33.36%" headers="mcps1.1.4.1.1 "><p id="p1190613512010"><a name="p1190613512010"></a><a name="p1190613512010"></a>multimedia_interfaces_kits_recorder_lite</p>
</td>
<td class="cellrowborder" valign="top" width="33.43%" headers="mcps1.1.4.1.2 ">&nbsp;&nbsp;</td>
<td class="cellrowborder" valign="top" width="33.21%" headers="mcps1.1.4.1.3 "><p id="p19061551016"><a name="p19061551016"></a><a name="p19061551016"></a>Read-only archiving</p>
</td>
</tr>
<tr id="row32651402491"><td class="cellrowborder" valign="top" width="33.36%" headers="mcps1.1.4.1.1 "><p id="p15265194016496"><a name="p15265194016496"></a><a name="p15265194016496"></a>multimedia_services_media_lite</p>
</td>
<td class="cellrowborder" valign="top" width="33.43%" headers="mcps1.1.4.1.2 ">&nbsp;&nbsp;</td>
<td class="cellrowborder" valign="top" width="33.21%" headers="mcps1.1.4.1.3 "><p id="p4377165314916"><a name="p4377165314916"></a><a name="p4377165314916"></a>Read-only archiving</p>
</td>
</tr>
<tr id="row19061253012"><td class="cellrowborder" valign="top" width="33.36%" headers="mcps1.1.4.1.1 "><p id="p6906651108"><a name="p6906651108"></a><a name="p6906651108"></a>kernel_liteos_a_huawei_proprietary_fs_proc</p>
</td>
<td class="cellrowborder" valign="top" width="33.43%" headers="mcps1.1.4.1.2 ">&nbsp;&nbsp;</td>
<td class="cellrowborder" valign="top" width="33.21%" headers="mcps1.1.4.1.3 "><p id="p190635804"><a name="p190635804"></a><a name="p190635804"></a>Read-only archiving</p>
</td>
</tr>
<tr id="row09064517018"><td class="cellrowborder" valign="top" width="33.36%" headers="mcps1.1.4.1.1 ">&nbsp;&nbsp;</td>
<td class="cellrowborder" valign="top" width="33.43%" headers="mcps1.1.4.1.2 "><p id="p109061459014"><a name="p109061459014"></a><a name="p109061459014"></a>third_party_mksh</p>
</td>
<td class="cellrowborder" valign="top" width="33.21%" headers="mcps1.1.4.1.3 "><p id="p7906257017"><a name="p7906257017"></a><a name="p7906257017"></a>New module</p>
</td>
</tr>
<tr id="row690635003"><td class="cellrowborder" valign="top" width="33.36%" headers="mcps1.1.4.1.1 ">&nbsp;&nbsp;</td>
<td class="cellrowborder" valign="top" width="33.43%" headers="mcps1.1.4.1.2 "><p id="p9906551104"><a name="p9906551104"></a><a name="p9906551104"></a>third_party_optimized_routines</p>
</td>
<td class="cellrowborder" valign="top" width="33.21%" headers="mcps1.1.4.1.3 "><p id="p1690655209"><a name="p1690655209"></a><a name="p1690655209"></a>New module</p>
</td>
</tr>
<tr id="row4906951707"><td class="cellrowborder" valign="top" width="33.36%" headers="mcps1.1.4.1.1 ">&nbsp;&nbsp;</td>
<td class="cellrowborder" valign="top" width="33.43%" headers="mcps1.1.4.1.2 "><p id="p1290685708"><a name="p1290685708"></a><a name="p1290685708"></a>third_party_toybox</p>
</td>
<td class="cellrowborder" valign="top" width="33.21%" headers="mcps1.1.4.1.3 "><p id="p19062051309"><a name="p19062051309"></a><a name="p19062051309"></a>New module</p>
</td>
</tr>
<tr id="row15906451400"><td class="cellrowborder" valign="top" width="33.36%" headers="mcps1.1.4.1.1 "><p id="p990625604"><a name="p990625604"></a><a name="p990625604"></a>vendor_huawei_camera</p>
</td>
<td class="cellrowborder" valign="top" width="33.43%" headers="mcps1.1.4.1.2 ">&nbsp;&nbsp;</td>
<td class="cellrowborder" valign="top" width="33.21%" headers="mcps1.1.4.1.3 "><p id="p129061251702"><a name="p129061251702"></a><a name="p129061251702"></a>Read-only archiving</p>
</td>
</tr>
<tr id="row1490614514010"><td class="cellrowborder" valign="top" width="33.36%" headers="mcps1.1.4.1.1 "><p id="p1190655105"><a name="p1190655105"></a><a name="p1190655105"></a>vendor_huawei_wifi_iot</p>
</td>
<td class="cellrowborder" valign="top" width="33.43%" headers="mcps1.1.4.1.2 ">&nbsp;&nbsp;</td>
<td class="cellrowborder" valign="top" width="33.21%" headers="mcps1.1.4.1.3 "><p id="p149071354015"><a name="p149071354015"></a><a name="p149071354015"></a>Read-only archiving</p>
</td>
</tr>
<tr id="row1290715517015"><td class="cellrowborder" valign="top" width="33.36%" headers="mcps1.1.4.1.1 "><p id="p29071151309"><a name="p29071151309"></a><a name="p29071151309"></a>startup_services_bootstrap_lite</p>
</td>
<td class="cellrowborder" valign="top" width="33.43%" headers="mcps1.1.4.1.2 "><p id="p119075510011"><a name="p119075510011"></a><a name="p119075510011"></a>startup_bootstrap_lite</p>
</td>
<td class="cellrowborder" valign="top" width="33.21%" headers="mcps1.1.4.1.3 "><p id="p9907255016"><a name="p9907255016"></a><a name="p9907255016"></a>The repository name has been changed.</p>
</td>
</tr>
<tr id="row2907165707"><td class="cellrowborder" valign="top" width="33.36%" headers="mcps1.1.4.1.1 "><p id="p9907451206"><a name="p9907451206"></a><a name="p9907451206"></a>startup_frameworks_syspara_lite</p>
</td>
<td class="cellrowborder" valign="top" width="33.43%" headers="mcps1.1.4.1.2 "><p id="p1490712516010"><a name="p1490712516010"></a><a name="p1490712516010"></a>startup_syspara_lite</p>
</td>
<td class="cellrowborder" valign="top" width="33.21%" headers="mcps1.1.4.1.3 "><p id="p59072514018"><a name="p59072514018"></a><a name="p59072514018"></a>The repository name has been changed.</p>
</td>
</tr>
<tr id="row9907053012"><td class="cellrowborder" valign="top" width="33.36%" headers="mcps1.1.4.1.1 "><p id="p159076513015"><a name="p159076513015"></a><a name="p159076513015"></a>startup_hals_syspara_lite</p>
</td>
<td class="cellrowborder" valign="top" width="33.43%" headers="mcps1.1.4.1.2 ">&nbsp;&nbsp;</td>
<td class="cellrowborder" valign="top" width="33.21%" headers="mcps1.1.4.1.3 "><p id="p09081451600"><a name="p09081451600"></a><a name="p09081451600"></a>Read-only archiving</p>
</td>
</tr>
<tr id="row17908751903"><td class="cellrowborder" valign="top" width="33.36%" headers="mcps1.1.4.1.1 "><p id="p39084514010"><a name="p39084514010"></a><a name="p39084514010"></a>startup_interfaces_kits_syspara_lite</p>
</td>
<td class="cellrowborder" valign="top" width="33.43%" headers="mcps1.1.4.1.2 ">&nbsp;&nbsp;</td>
<td class="cellrowborder" valign="top" width="33.21%" headers="mcps1.1.4.1.3 "><p id="p1490818519019"><a name="p1490818519019"></a><a name="p1490818519019"></a>Read-only archiving</p>
</td>
</tr>
<tr id="row10908125707"><td class="cellrowborder" valign="top" width="33.36%" headers="mcps1.1.4.1.1 "><p id="p990814513015"><a name="p990814513015"></a><a name="p990814513015"></a>graphic_lite</p>
</td>
<td class="cellrowborder" valign="top" width="33.43%" headers="mcps1.1.4.1.2 "><p id="p15908951808"><a name="p15908951808"></a><a name="p15908951808"></a>graphic_surface</p>
</td>
<td class="cellrowborder" valign="top" width="33.21%" headers="mcps1.1.4.1.3 "><p id="p4908135408"><a name="p4908135408"></a><a name="p4908135408"></a>The repository name has been changed.</p>
</td>
</tr>
<tr id="row199081551901"><td class="cellrowborder" valign="top" width="33.36%" headers="mcps1.1.4.1.1 ">&nbsp;&nbsp;</td>
<td class="cellrowborder" valign="top" width="33.43%" headers="mcps1.1.4.1.2 "><p id="p199081051301"><a name="p199081051301"></a><a name="p199081051301"></a>graphic_ui</p>
</td>
<td class="cellrowborder" valign="top" width="33.21%" headers="mcps1.1.4.1.3 "><p id="p179086517016"><a name="p179086517016"></a><a name="p179086517016"></a>New module</p>
</td>
</tr>
<tr id="row199086519015"><td class="cellrowborder" valign="top" width="33.36%" headers="mcps1.1.4.1.1 ">&nbsp;&nbsp;</td>
<td class="cellrowborder" valign="top" width="33.43%" headers="mcps1.1.4.1.2 "><p id="p169081751402"><a name="p169081751402"></a><a name="p169081751402"></a>graphic_utils</p>
</td>
<td class="cellrowborder" valign="top" width="33.21%" headers="mcps1.1.4.1.3 "><p id="p990815906"><a name="p990815906"></a><a name="p990815906"></a>New module</p>
</td>
</tr>
<tr id="row1908155706"><td class="cellrowborder" valign="top" width="33.36%" headers="mcps1.1.4.1.1 ">&nbsp;&nbsp;</td>
<td class="cellrowborder" valign="top" width="33.43%" headers="mcps1.1.4.1.2 "><p id="p12908851907"><a name="p12908851907"></a><a name="p12908851907"></a>graphic_wms</p>
</td>
<td class="cellrowborder" valign="top" width="33.21%" headers="mcps1.1.4.1.3 "><p id="p139084511017"><a name="p139084511017"></a><a name="p139084511017"></a>New module</p>
</td>
</tr>
<tr id="row13908751904"><td class="cellrowborder" valign="top" width="33.36%" headers="mcps1.1.4.1.1 ">&nbsp;&nbsp;</td>
<td class="cellrowborder" valign="top" width="33.43%" headers="mcps1.1.4.1.2 "><p id="p16909151205"><a name="p16909151205"></a><a name="p16909151205"></a>third_party_giflib</p>
</td>
<td class="cellrowborder" valign="top" width="33.21%" headers="mcps1.1.4.1.3 "><p id="p89091851807"><a name="p89091851807"></a><a name="p89091851807"></a>New module</p>
</td>
</tr>
<tr id="row890914518017"><td class="cellrowborder" valign="top" width="33.36%" headers="mcps1.1.4.1.1 ">&nbsp;&nbsp;</td>
<td class="cellrowborder" valign="top" width="33.43%" headers="mcps1.1.4.1.2 "><p id="p090913519020"><a name="p090913519020"></a><a name="p090913519020"></a>third_party_qrcodegen</p>
</td>
<td class="cellrowborder" valign="top" width="33.21%" headers="mcps1.1.4.1.3 "><p id="p8909453015"><a name="p8909453015"></a><a name="p8909453015"></a>New module</p>
</td>
</tr>
<tr id="row14909954015"><td class="cellrowborder" valign="top" width="33.36%" headers="mcps1.1.4.1.1 ">&nbsp;&nbsp;</td>
<td class="cellrowborder" valign="top" width="33.43%" headers="mcps1.1.4.1.2 "><p id="p5909758010"><a name="p5909758010"></a><a name="p5909758010"></a>drivers_adapter_khdf_linux</p>
</td>
<td class="cellrowborder" valign="top" width="33.21%" headers="mcps1.1.4.1.3 "><p id="p1590975106"><a name="p1590975106"></a><a name="p1590975106"></a>New module</p>
</td>
</tr>
<tr id="row16909251302"><td class="cellrowborder" valign="top" width="33.36%" headers="mcps1.1.4.1.1 "><p id="p199097510018"><a name="p199097510018"></a><a name="p199097510018"></a>drivers_hdf_lite</p>
</td>
<td class="cellrowborder" valign="top" width="33.43%" headers="mcps1.1.4.1.2 "><p id="p790955108"><a name="p790955108"></a><a name="p790955108"></a>drivers_adapter_khdf_liteos</p>
</td>
<td class="cellrowborder" valign="top" width="33.21%" headers="mcps1.1.4.1.3 "><p id="p20909251301"><a name="p20909251301"></a><a name="p20909251301"></a>The repository name has been changed.</p>
</td>
</tr>
<tr id="row16909256018"><td class="cellrowborder" valign="top" width="33.36%" headers="mcps1.1.4.1.1 ">&nbsp;&nbsp;</td>
<td class="cellrowborder" valign="top" width="33.43%" headers="mcps1.1.4.1.2 "><p id="p09101651205"><a name="p09101651205"></a><a name="p09101651205"></a>drivers_adapter_uhdf</p>
</td>
<td class="cellrowborder" valign="top" width="33.21%" headers="mcps1.1.4.1.3 "><p id="p18910251107"><a name="p18910251107"></a><a name="p18910251107"></a>New module</p>
</td>
</tr>
<tr id="row13910559012"><td class="cellrowborder" valign="top" width="33.36%" headers="mcps1.1.4.1.1 "><p id="p1891011517010"><a name="p1891011517010"></a><a name="p1891011517010"></a>drivers_hdf_frameworks</p>
</td>
<td class="cellrowborder" valign="top" width="33.43%" headers="mcps1.1.4.1.2 "><p id="p6910954011"><a name="p6910954011"></a><a name="p6910954011"></a>drivers_framework</p>
</td>
<td class="cellrowborder" valign="top" width="33.21%" headers="mcps1.1.4.1.3 "><p id="p89102518017"><a name="p89102518017"></a><a name="p89102518017"></a>The repository name has been changed.</p>
</td>
</tr>
<tr id="row39101851804"><td class="cellrowborder" valign="top" width="33.36%" headers="mcps1.1.4.1.1 ">&nbsp;&nbsp;</td>
<td class="cellrowborder" valign="top" width="33.43%" headers="mcps1.1.4.1.2 "><p id="p119101951909"><a name="p119101951909"></a><a name="p119101951909"></a>drivers_peripheral_audio</p>
</td>
<td class="cellrowborder" valign="top" width="33.21%" headers="mcps1.1.4.1.3 "><p id="p79105515016"><a name="p79105515016"></a><a name="p79105515016"></a>New module</p>
</td>
</tr>
<tr id="row49101352014"><td class="cellrowborder" valign="top" width="33.36%" headers="mcps1.1.4.1.1 ">&nbsp;&nbsp;</td>
<td class="cellrowborder" valign="top" width="33.43%" headers="mcps1.1.4.1.2 "><p id="p29101751908"><a name="p29101751908"></a><a name="p29101751908"></a>drivers_peripheral_codec</p>
</td>
<td class="cellrowborder" valign="top" width="33.21%" headers="mcps1.1.4.1.3 "><p id="p29109516013"><a name="p29109516013"></a><a name="p29109516013"></a>New module</p>
</td>
</tr>
<tr id="row69101651604"><td class="cellrowborder" valign="top" width="33.36%" headers="mcps1.1.4.1.1 ">&nbsp;&nbsp;</td>
<td class="cellrowborder" valign="top" width="33.43%" headers="mcps1.1.4.1.2 "><p id="p79101552020"><a name="p79101552020"></a><a name="p79101552020"></a>drivers_peripheral_display</p>
</td>
<td class="cellrowborder" valign="top" width="33.21%" headers="mcps1.1.4.1.3 "><p id="p1910756017"><a name="p1910756017"></a><a name="p1910756017"></a>New module</p>
</td>
</tr>
<tr id="row16910125109"><td class="cellrowborder" valign="top" width="33.36%" headers="mcps1.1.4.1.1 ">&nbsp;&nbsp;</td>
<td class="cellrowborder" valign="top" width="33.43%" headers="mcps1.1.4.1.2 "><p id="p19911651009"><a name="p19911651009"></a><a name="p19911651009"></a>drivers_peripheral_format</p>
</td>
<td class="cellrowborder" valign="top" width="33.21%" headers="mcps1.1.4.1.3 "><p id="p39113518019"><a name="p39113518019"></a><a name="p39113518019"></a>New module</p>
</td>
</tr>
<tr id="row179119516018"><td class="cellrowborder" valign="top" width="33.36%" headers="mcps1.1.4.1.1 ">&nbsp;&nbsp;</td>
<td class="cellrowborder" valign="top" width="33.43%" headers="mcps1.1.4.1.2 "><p id="p139111651602"><a name="p139111651602"></a><a name="p139111651602"></a>drivers_peripheral_input</p>
</td>
<td class="cellrowborder" valign="top" width="33.21%" headers="mcps1.1.4.1.3 "><p id="p1491114519013"><a name="p1491114519013"></a><a name="p1491114519013"></a>New module</p>
</td>
</tr>
<tr id="row189114517010"><td class="cellrowborder" valign="top" width="33.36%" headers="mcps1.1.4.1.1 ">&nbsp;&nbsp;</td>
<td class="cellrowborder" valign="top" width="33.43%" headers="mcps1.1.4.1.2 "><p id="p09115513010"><a name="p09115513010"></a><a name="p09115513010"></a>drivers_peripheral_sensor</p>
</td>
<td class="cellrowborder" valign="top" width="33.21%" headers="mcps1.1.4.1.3 "><p id="p59111558013"><a name="p59111558013"></a><a name="p59111558013"></a>New module</p>
</td>
</tr>
<tr id="row159111853017"><td class="cellrowborder" valign="top" width="33.36%" headers="mcps1.1.4.1.1 ">&nbsp;&nbsp;</td>
<td class="cellrowborder" valign="top" width="33.43%" headers="mcps1.1.4.1.2 "><p id="p19911555019"><a name="p19911555019"></a><a name="p19911555019"></a>drivers_peripheral_wlan</p>
</td>
<td class="cellrowborder" valign="top" width="33.21%" headers="mcps1.1.4.1.3 "><p id="p791113512014"><a name="p791113512014"></a><a name="p791113512014"></a>New module</p>
</td>
</tr>
<tr id="row99111150015"><td class="cellrowborder" valign="top" width="33.36%" headers="mcps1.1.4.1.1 ">&nbsp;&nbsp;</td>
<td class="cellrowborder" valign="top" width="33.43%" headers="mcps1.1.4.1.2 "><p id="p09118516019"><a name="p09118516019"></a><a name="p09118516019"></a>global_cust_lite</p>
</td>
<td class="cellrowborder" valign="top" width="33.21%" headers="mcps1.1.4.1.3 "><p id="p109118512013"><a name="p109118512013"></a><a name="p109118512013"></a>New module</p>
</td>
</tr>
<tr id="row1191135703"><td class="cellrowborder" valign="top" width="33.36%" headers="mcps1.1.4.1.1 ">&nbsp;&nbsp;</td>
<td class="cellrowborder" valign="top" width="33.43%" headers="mcps1.1.4.1.2 "><p id="p59111551405"><a name="p59111551405"></a><a name="p59111551405"></a>global_i18n_lite</p>
</td>
<td class="cellrowborder" valign="top" width="33.21%" headers="mcps1.1.4.1.3 "><p id="p1491175703"><a name="p1491175703"></a><a name="p1491175703"></a>New module</p>
</td>
</tr>
<tr id="row11911115801"><td class="cellrowborder" valign="top" width="33.36%" headers="mcps1.1.4.1.1 "><p id="p159111553016"><a name="p159111553016"></a><a name="p159111553016"></a>global_frameworks_resmgr_lite</p>
</td>
<td class="cellrowborder" valign="top" width="33.43%" headers="mcps1.1.4.1.2 "><p id="p149111851608"><a name="p149111851608"></a><a name="p149111851608"></a>global_resmgr_lite</p>
</td>
<td class="cellrowborder" valign="top" width="33.21%" headers="mcps1.1.4.1.3 "><p id="p16911456013"><a name="p16911456013"></a><a name="p16911456013"></a>The repository name has been changed.</p>
</td>
</tr>
<tr id="row17911257010"><td class="cellrowborder" valign="top" width="33.36%" headers="mcps1.1.4.1.1 ">&nbsp;&nbsp;</td>
<td class="cellrowborder" valign="top" width="33.43%" headers="mcps1.1.4.1.2 "><p id="p1991211515015"><a name="p1991211515015"></a><a name="p1991211515015"></a>third_party_icu</p>
</td>
<td class="cellrowborder" valign="top" width="33.21%" headers="mcps1.1.4.1.3 "><p id="p17912175808"><a name="p17912175808"></a><a name="p17912175808"></a>New module</p>
</td>
</tr>
<tr id="row69121257015"><td class="cellrowborder" valign="top" width="33.36%" headers="mcps1.1.4.1.1 "><p id="p139129511011"><a name="p139129511011"></a><a name="p139129511011"></a>global_interfaces_innerkits_resmgr_lite</p>
</td>
<td class="cellrowborder" valign="top" width="33.43%" headers="mcps1.1.4.1.2 ">&nbsp;&nbsp;</td>
<td class="cellrowborder" valign="top" width="33.21%" headers="mcps1.1.4.1.3 "><p id="p19121651105"><a name="p19121651105"></a><a name="p19121651105"></a>Read-only archiving</p>
</td>
</tr>
<tr id="row129122051305"><td class="cellrowborder" valign="top" width="33.36%" headers="mcps1.1.4.1.1 "><p id="p1691295602"><a name="p1691295602"></a><a name="p1691295602"></a>communication_frameworks_ipc_lite</p>
</td>
<td class="cellrowborder" valign="top" width="33.43%" headers="mcps1.1.4.1.2 "><p id="p1091210518012"><a name="p1091210518012"></a><a name="p1091210518012"></a>communication_ipc_lite</p>
</td>
<td class="cellrowborder" valign="top" width="33.21%" headers="mcps1.1.4.1.3 "><p id="p19912458020"><a name="p19912458020"></a><a name="p19912458020"></a>The repository name has been changed.</p>
</td>
</tr>
<tr id="row291295508"><td class="cellrowborder" valign="top" width="33.36%" headers="mcps1.1.4.1.1 "><p id="p209121510017"><a name="p209121510017"></a><a name="p209121510017"></a>communication_interfaces_kits_ipc_lite</p>
</td>
<td class="cellrowborder" valign="top" width="33.43%" headers="mcps1.1.4.1.2 ">&nbsp;&nbsp;</td>
<td class="cellrowborder" valign="top" width="33.21%" headers="mcps1.1.4.1.3 "><p id="p1291217511018"><a name="p1291217511018"></a><a name="p1291217511018"></a>Read-only archiving</p>
</td>
</tr>
<tr id="row199121951509"><td class="cellrowborder" valign="top" width="33.36%" headers="mcps1.1.4.1.1 "><p id="p119125517016"><a name="p119125517016"></a><a name="p119125517016"></a>communication_interfaces_kits_softbuskit_lite</p>
</td>
<td class="cellrowborder" valign="top" width="33.43%" headers="mcps1.1.4.1.2 ">&nbsp;&nbsp;</td>
<td class="cellrowborder" valign="top" width="33.21%" headers="mcps1.1.4.1.3 "><p id="p199127511014"><a name="p199127511014"></a><a name="p199127511014"></a>Read-only archiving</p>
</td>
</tr>
<tr id="row69127510010"><td class="cellrowborder" valign="top" width="33.36%" headers="mcps1.1.4.1.1 "><p id="p209129510013"><a name="p209129510013"></a><a name="p209129510013"></a>communication_hals_wifi_lite</p>
</td>
<td class="cellrowborder" valign="top" width="33.43%" headers="mcps1.1.4.1.2 ">&nbsp;&nbsp;</td>
<td class="cellrowborder" valign="top" width="33.21%" headers="mcps1.1.4.1.3 "><p id="p13912851018"><a name="p13912851018"></a><a name="p13912851018"></a>Read-only archiving</p>
</td>
</tr>
<tr id="row12912351309"><td class="cellrowborder" valign="top" width="33.36%" headers="mcps1.1.4.1.1 "><p id="p16912559013"><a name="p16912559013"></a><a name="p16912559013"></a>communication_services_softbus_lite</p>
</td>
<td class="cellrowborder" valign="top" width="33.43%" headers="mcps1.1.4.1.2 "><p id="p17912151808"><a name="p17912151808"></a><a name="p17912151808"></a>communication_softbus_lite</p>
</td>
<td class="cellrowborder" valign="top" width="33.21%" headers="mcps1.1.4.1.3 "><p id="p20912051904"><a name="p20912051904"></a><a name="p20912051904"></a>The repository name has been changed.</p>
</td>
</tr>
<tr id="row99128517010"><td class="cellrowborder" valign="top" width="33.36%" headers="mcps1.1.4.1.1 ">&nbsp;&nbsp;</td>
<td class="cellrowborder" valign="top" width="33.43%" headers="mcps1.1.4.1.2 "><p id="p139126520013"><a name="p139126520013"></a><a name="p139126520013"></a>communication_wifi_aware</p>
</td>
<td class="cellrowborder" valign="top" width="33.21%" headers="mcps1.1.4.1.3 "><p id="p891385705"><a name="p891385705"></a><a name="p891385705"></a>New module</p>
</td>
</tr>
<tr id="row159139518017"><td class="cellrowborder" valign="top" width="33.36%" headers="mcps1.1.4.1.1 ">&nbsp;&nbsp;</td>
<td class="cellrowborder" valign="top" width="33.43%" headers="mcps1.1.4.1.2 "><p id="p391365808"><a name="p391365808"></a><a name="p391365808"></a>update_ota_lite</p>
</td>
<td class="cellrowborder" valign="top" width="33.21%" headers="mcps1.1.4.1.3 "><p id="p69131252020"><a name="p69131252020"></a><a name="p69131252020"></a>New module</p>
</td>
</tr>
<tr id="row139135511018"><td class="cellrowborder" valign="top" width="33.36%" headers="mcps1.1.4.1.1 "><p id="p1691317511019"><a name="p1691317511019"></a><a name="p1691317511019"></a>vendor_hisi_hi35xx_hi35xx_init</p>
</td>
<td class="cellrowborder" valign="top" width="33.43%" headers="mcps1.1.4.1.2 "><p id="p199131956012"><a name="p199131956012"></a><a name="p199131956012"></a>device_hisilicon_build</p>
</td>
<td class="cellrowborder" valign="top" width="33.21%" headers="mcps1.1.4.1.3 "><p id="p79133512013"><a name="p79133512013"></a><a name="p79133512013"></a>The repository name has been changed.</p>
</td>
</tr>
<tr id="row29131151901"><td class="cellrowborder" valign="top" width="33.36%" headers="mcps1.1.4.1.1 "><p id="p1913125306"><a name="p1913125306"></a><a name="p1913125306"></a>vendor_hisi_hi35xx_platform</p>
</td>
<td class="cellrowborder" valign="top" width="33.43%" headers="mcps1.1.4.1.2 "><p id="p15913054011"><a name="p15913054011"></a><a name="p15913054011"></a>device_hisilicon_drivers</p>
</td>
<td class="cellrowborder" valign="top" width="33.21%" headers="mcps1.1.4.1.3 "><p id="p139139512019"><a name="p139139512019"></a><a name="p139139512019"></a>The repository name has been changed.</p>
</td>
</tr>
<tr id="row19913251008"><td class="cellrowborder" valign="top" width="33.36%" headers="mcps1.1.4.1.1 "><p id="p17913655013"><a name="p17913655013"></a><a name="p17913655013"></a>vendor_hisi_hi35xx_hardware</p>
</td>
<td class="cellrowborder" valign="top" width="33.43%" headers="mcps1.1.4.1.2 "><p id="p16913151004"><a name="p16913151004"></a><a name="p16913151004"></a>device_hisilicon_hardware</p>
</td>
<td class="cellrowborder" valign="top" width="33.21%" headers="mcps1.1.4.1.3 "><p id="p1191316520013"><a name="p1191316520013"></a><a name="p1191316520013"></a>The repository name has been changed.</p>
</td>
</tr>
<tr id="row199135511012"><td class="cellrowborder" valign="top" width="33.36%" headers="mcps1.1.4.1.1 "><p id="p179131051804"><a name="p179131051804"></a><a name="p179131051804"></a>vendor_hisi_hi35xx_hi3518ev300</p>
</td>
<td class="cellrowborder" valign="top" width="33.43%" headers="mcps1.1.4.1.2 "><p id="p1291319518016"><a name="p1291319518016"></a><a name="p1291319518016"></a>device_hisilicon_hispark_aries</p>
</td>
<td class="cellrowborder" valign="top" width="33.21%" headers="mcps1.1.4.1.3 "><p id="p5913125106"><a name="p5913125106"></a><a name="p5913125106"></a>The repository name has been changed.</p>
</td>
</tr>
<tr id="row139131351308"><td class="cellrowborder" valign="top" width="33.36%" headers="mcps1.1.4.1.1 "><p id="p10913457011"><a name="p10913457011"></a><a name="p10913457011"></a>vendor_hisi_hi3861_hi3861</p>
</td>
<td class="cellrowborder" valign="top" width="33.43%" headers="mcps1.1.4.1.2 "><p id="p16913165403"><a name="p16913165403"></a><a name="p16913165403"></a>device_hisilicon_hispark_pegasus</p>
</td>
<td class="cellrowborder" valign="top" width="33.21%" headers="mcps1.1.4.1.3 "><p id="p1191365602"><a name="p1191365602"></a><a name="p1191365602"></a>The repository name has been changed.</p>
</td>
</tr>
<tr id="row99131651908"><td class="cellrowborder" valign="top" width="33.36%" headers="mcps1.1.4.1.1 "><p id="p1191365000"><a name="p1191365000"></a><a name="p1191365000"></a>vendor_hisi_hi35xx_hi3516dv300</p>
</td>
<td class="cellrowborder" valign="top" width="33.43%" headers="mcps1.1.4.1.2 "><p id="p2913195102"><a name="p2913195102"></a><a name="p2913195102"></a>device_hisilicon_hispark_taurus</p>
</td>
<td class="cellrowborder" valign="top" width="33.21%" headers="mcps1.1.4.1.3 "><p id="p1491320518015"><a name="p1491320518015"></a><a name="p1491320518015"></a>The repository name has been changed.</p>
</td>
</tr>
<tr id="row11913651308"><td class="cellrowborder" valign="top" width="33.36%" headers="mcps1.1.4.1.1 "><p id="p19913955017"><a name="p19913955017"></a><a name="p19913955017"></a>vendor_hisi_hi35xx_middleware</p>
</td>
<td class="cellrowborder" valign="top" width="33.43%" headers="mcps1.1.4.1.2 "><p id="p89132513013"><a name="p89132513013"></a><a name="p89132513013"></a>device_hisilicon_modules</p>
</td>
<td class="cellrowborder" valign="top" width="33.21%" headers="mcps1.1.4.1.3 "><p id="p17913115909"><a name="p17913115909"></a><a name="p17913115909"></a>The repository name has been changed.</p>
</td>
</tr>
<tr id="row1913252013"><td class="cellrowborder" valign="top" width="33.36%" headers="mcps1.1.4.1.1 "><p id="p29141351408"><a name="p29141351408"></a><a name="p29141351408"></a>vendor_hisi_hi35xx_middleware_source_third_party_ffmpeg</p>
</td>
<td class="cellrowborder" valign="top" width="33.43%" headers="mcps1.1.4.1.2 "><p id="p791420518016"><a name="p791420518016"></a><a name="p791420518016"></a>device_hisilicon_third_party_ffmpeg</p>
</td>
<td class="cellrowborder" valign="top" width="33.21%" headers="mcps1.1.4.1.3 "><p id="p1391418512014"><a name="p1391418512014"></a><a name="p1391418512014"></a>The repository name has been changed.</p>
</td>
</tr>
<tr id="row19914251203"><td class="cellrowborder" valign="top" width="33.36%" headers="mcps1.1.4.1.1 "><p id="p69141751009"><a name="p69141751009"></a><a name="p69141751009"></a>vendor_hisi_hi35xx_thirdparty_uboot_src</p>
</td>
<td class="cellrowborder" valign="top" width="33.43%" headers="mcps1.1.4.1.2 "><p id="p12914751907"><a name="p12914751907"></a><a name="p12914751907"></a>device_hisilicon_third_party_uboot</p>
</td>
<td class="cellrowborder" valign="top" width="33.21%" headers="mcps1.1.4.1.3 "><p id="p2914350011"><a name="p2914350011"></a><a name="p2914350011"></a>The repository name has been changed.</p>
</td>
</tr>
<tr id="row791405607"><td class="cellrowborder" valign="top" width="33.36%" headers="mcps1.1.4.1.1 ">&nbsp;&nbsp;</td>
<td class="cellrowborder" valign="top" width="33.43%" headers="mcps1.1.4.1.2 "><p id="p1191410510011"><a name="p1191410510011"></a><a name="p1191410510011"></a>vendor_hisilicon</p>
</td>
<td class="cellrowborder" valign="top" width="33.21%" headers="mcps1.1.4.1.3 "><p id="p2914451805"><a name="p2914451805"></a><a name="p2914451805"></a>New module</p>
</td>
</tr>
<tr id="row1491415901"><td class="cellrowborder" valign="top" width="33.36%" headers="mcps1.1.4.1.1 "><p id="p8914951407"><a name="p8914951407"></a><a name="p8914951407"></a>vendor_hisi_hi35xx_hi3516dv300_uboot</p>
</td>
<td class="cellrowborder" valign="top" width="33.43%" headers="mcps1.1.4.1.2 ">&nbsp;&nbsp;</td>
<td class="cellrowborder" valign="top" width="33.21%" headers="mcps1.1.4.1.3 "><p id="p2091415516011"><a name="p2091415516011"></a><a name="p2091415516011"></a>Read-only archiving</p>
</td>
</tr>
<tr id="row119143517013"><td class="cellrowborder" valign="top" width="33.36%" headers="mcps1.1.4.1.1 "><p id="p1491495903"><a name="p1491495903"></a><a name="p1491495903"></a>vendor_hisi_hi35xx_hi3518ev300_uboot</p>
</td>
<td class="cellrowborder" valign="top" width="33.43%" headers="mcps1.1.4.1.2 ">&nbsp;&nbsp;</td>
<td class="cellrowborder" valign="top" width="33.21%" headers="mcps1.1.4.1.3 "><p id="p159141551304"><a name="p159141551304"></a><a name="p159141551304"></a>Read-only archiving</p>
</td>
</tr>
<tr id="row12914651909"><td class="cellrowborder" valign="top" width="33.36%" headers="mcps1.1.4.1.1 "><p id="p13914851607"><a name="p13914851607"></a><a name="p13914851607"></a>aafwk_interfaces_innerkits_abilitykit_lite</p>
</td>
<td class="cellrowborder" valign="top" width="33.43%" headers="mcps1.1.4.1.2 ">&nbsp;&nbsp;</td>
<td class="cellrowborder" valign="top" width="33.21%" headers="mcps1.1.4.1.3 "><p id="p12914115109"><a name="p12914115109"></a><a name="p12914115109"></a>Read-only archiving</p>
</td>
</tr>
<tr id="row29141957010"><td class="cellrowborder" valign="top" width="33.36%" headers="mcps1.1.4.1.1 "><p id="p139141657020"><a name="p139141657020"></a><a name="p139141657020"></a>aafwk_interfaces_innerkits_intent_lite</p>
</td>
<td class="cellrowborder" valign="top" width="33.43%" headers="mcps1.1.4.1.2 "><p id="p2091435204"><a name="p2091435204"></a><a name="p2091435204"></a>aafwk_aafwk_lite</p>
</td>
<td class="cellrowborder" valign="top" width="33.21%" headers="mcps1.1.4.1.3 "><p id="p391418514016"><a name="p391418514016"></a><a name="p391418514016"></a>The repository name has been changed.</p>
</td>
</tr>
<tr id="row19144513010"><td class="cellrowborder" valign="top" width="33.36%" headers="mcps1.1.4.1.1 "><p id="p49153516011"><a name="p49153516011"></a><a name="p49153516011"></a>aafwk_interfaces_innerkits_abilitymgr_lite</p>
</td>
<td class="cellrowborder" valign="top" width="33.43%" headers="mcps1.1.4.1.2 ">&nbsp;&nbsp;</td>
<td class="cellrowborder" valign="top" width="33.21%" headers="mcps1.1.4.1.3 "><p id="p9915952001"><a name="p9915952001"></a><a name="p9915952001"></a>Read-only archiving</p>
</td>
</tr>
<tr id="row11915115409"><td class="cellrowborder" valign="top" width="33.36%" headers="mcps1.1.4.1.1 "><p id="p11915751906"><a name="p11915751906"></a><a name="p11915751906"></a>appexecfwk_kits_appkit_lite</p>
</td>
<td class="cellrowborder" valign="top" width="33.43%" headers="mcps1.1.4.1.2 "><p id="p159151651909"><a name="p159151651909"></a><a name="p159151651909"></a>appexecfwk_appexecfwk_lite</p>
</td>
<td class="cellrowborder" valign="top" width="33.21%" headers="mcps1.1.4.1.3 "><p id="p15915195103"><a name="p15915195103"></a><a name="p15915195103"></a>The repository name has been changed.</p>
</td>
</tr>
<tr id="row10915551806"><td class="cellrowborder" valign="top" width="33.36%" headers="mcps1.1.4.1.1 "><p id="p159152051602"><a name="p159152051602"></a><a name="p159152051602"></a>aafwk_frameworks_kits_ability_lite</p>
</td>
<td class="cellrowborder" valign="top" width="33.43%" headers="mcps1.1.4.1.2 ">&nbsp;&nbsp;</td>
<td class="cellrowborder" valign="top" width="33.21%" headers="mcps1.1.4.1.3 "><p id="p11915135109"><a name="p11915135109"></a><a name="p11915135109"></a>Read-only archiving</p>
</td>
</tr>
<tr id="row119151456011"><td class="cellrowborder" valign="top" width="33.36%" headers="mcps1.1.4.1.1 ">&nbsp;&nbsp;</td>
<td class="cellrowborder" valign="top" width="33.43%" headers="mcps1.1.4.1.2 "><p id="p139151754014"><a name="p139151754014"></a><a name="p139151754014"></a>developtools_packing_tool</p>
</td>
<td class="cellrowborder" valign="top" width="33.21%" headers="mcps1.1.4.1.3 "><p id="p13915251019"><a name="p13915251019"></a><a name="p13915251019"></a>New module</p>
</td>
</tr>
<tr id="row1291575909"><td class="cellrowborder" valign="top" width="33.36%" headers="mcps1.1.4.1.1 "><p id="p79156518010"><a name="p79156518010"></a><a name="p79156518010"></a>aafwk_interfaces_kits_ability_lite</p>
</td>
<td class="cellrowborder" valign="top" width="33.43%" headers="mcps1.1.4.1.2 ">&nbsp;&nbsp;</td>
<td class="cellrowborder" valign="top" width="33.21%" headers="mcps1.1.4.1.3 "><p id="p189155518018"><a name="p189155518018"></a><a name="p189155518018"></a>Read-only archiving</p>
</td>
</tr>
<tr id="row6915155303"><td class="cellrowborder" valign="top" width="33.36%" headers="mcps1.1.4.1.1 "><p id="p5915125206"><a name="p5915125206"></a><a name="p5915125206"></a>appexecfwk_frameworks_bundle_lite</p>
</td>
<td class="cellrowborder" valign="top" width="33.43%" headers="mcps1.1.4.1.2 ">&nbsp;&nbsp;</td>
<td class="cellrowborder" valign="top" width="33.21%" headers="mcps1.1.4.1.3 "><p id="p3915751018"><a name="p3915751018"></a><a name="p3915751018"></a>Read-only archiving</p>
</td>
</tr>
<tr id="row209151159020"><td class="cellrowborder" valign="top" width="33.36%" headers="mcps1.1.4.1.1 "><p id="p891585809"><a name="p891585809"></a><a name="p891585809"></a>aafwk_services_abilitymgr_lite</p>
</td>
<td class="cellrowborder" valign="top" width="33.43%" headers="mcps1.1.4.1.2 ">&nbsp;&nbsp;</td>
<td class="cellrowborder" valign="top" width="33.21%" headers="mcps1.1.4.1.3 "><p id="p791585006"><a name="p791585006"></a><a name="p791585006"></a>Read-only archiving</p>
</td>
</tr>
<tr id="row209156517018"><td class="cellrowborder" valign="top" width="33.36%" headers="mcps1.1.4.1.1 "><p id="p09151755010"><a name="p09151755010"></a><a name="p09151755010"></a>appexecfwk_interfaces_innerkits_appexecfwk_lite</p>
</td>
<td class="cellrowborder" valign="top" width="33.43%" headers="mcps1.1.4.1.2 ">&nbsp;&nbsp;</td>
<td class="cellrowborder" valign="top" width="33.21%" headers="mcps1.1.4.1.3 "><p id="p09151551700"><a name="p09151551700"></a><a name="p09151551700"></a>Read-only archiving</p>
</td>
</tr>
<tr id="row491614520017"><td class="cellrowborder" valign="top" width="33.36%" headers="mcps1.1.4.1.1 "><p id="p69161151506"><a name="p69161151506"></a><a name="p69161151506"></a>appexecfwk_interfaces_innerkits_bundlemgr_lite</p>
</td>
<td class="cellrowborder" valign="top" width="33.43%" headers="mcps1.1.4.1.2 ">&nbsp;&nbsp;</td>
<td class="cellrowborder" valign="top" width="33.21%" headers="mcps1.1.4.1.3 "><p id="p791618511016"><a name="p791618511016"></a><a name="p791618511016"></a>Read-only archiving</p>
</td>
</tr>
<tr id="row59162058016"><td class="cellrowborder" valign="top" width="33.36%" headers="mcps1.1.4.1.1 "><p id="p1991645809"><a name="p1991645809"></a><a name="p1991645809"></a>appexecfwk_services_bundlemgr_lite</p>
</td>
<td class="cellrowborder" valign="top" width="33.43%" headers="mcps1.1.4.1.2 ">&nbsp;&nbsp;</td>
<td class="cellrowborder" valign="top" width="33.21%" headers="mcps1.1.4.1.3 "><p id="p1091605202"><a name="p1091605202"></a><a name="p1091605202"></a>Read-only archiving</p>
</td>
</tr>
<tr id="row2916054019"><td class="cellrowborder" valign="top" width="33.36%" headers="mcps1.1.4.1.1 "><p id="p169164515019"><a name="p169164515019"></a><a name="p169164515019"></a>aafwk_frameworks_kits_content_lite</p>
</td>
<td class="cellrowborder" valign="top" width="33.43%" headers="mcps1.1.4.1.2 ">&nbsp;&nbsp;</td>
<td class="cellrowborder" valign="top" width="33.21%" headers="mcps1.1.4.1.3 "><p id="p991617517013"><a name="p991617517013"></a><a name="p991617517013"></a>Read-only archiving</p>
</td>
</tr>
</tbody>
</table>

\* Read-only archiving means archiving a module repository to the  **openharmony-retired**  organization and setting the repository to read-only.

\* Code for third-party chips has been decoupled from the OS. HiSilicon chip SDKs have been moved from the  **vendor**  directory to the  **device/hisilicon**  directory.

