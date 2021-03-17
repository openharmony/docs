# Startup<a name="EN-US_TOPIC_0000001063402122"></a>

-   [Limitations and Constraints](#section2029921310472)

The startup subsystem provides the functions of starting key system processes after the kernel is started and before applications are started, and restoring the system to factory settings. The subsystem consists of the following modules:

-   init module

    This module corresponds to the init process, which is the first user-space process started after the kernel is initialized. Upon startup, the init process reads and parses the configuration file  **init.cfg**. Based on the parsing result, the init module executes the commands listed in  [Table 2](init-module.md#table122681439144112)  in  [init Module](init-module.md)  and starts the key system service processes in sequence with corresponding permissions granted.

-   appspawn module

    This module spawns application processes upon receiving commands from the application framework, configures permissions for new processes, and calls the entry function of the application framework.

-   bootstrap module

    This module provides entry identifiers for starting services and features. When the Samgr is started, the entry function identified by boostrap is called and system services are started.

-   syspara module

    This module provides APIs for obtaining device information, such as the product name, brand name, and manufacturer name, based on the OpenHarmony Product Compatibility Specifications \(PCS\). It also provides APIs for setting and obtaining system parameters.

-   startup module

    This module obtains and sets system attributes for the large system.

    Supported system attributes consist of device information such as the device type and product name and system information such as the system version and API version.


## Limitations and Constraints<a name="section2029921310472"></a>

The directories of startup subsystem are applicable to different platforms.

**Table  1**  Directories and applicable platforms of the startup subsystem

<a name="table2144134816420"></a>
<table><thead align="left"><tr id="row11143184819429"><th class="cellrowborder" valign="top" width="32%" id="mcps1.2.3.1.1"><p id="p014334816421"><a name="p014334816421"></a><a name="p014334816421"></a>Directory</p>
</th>
<th class="cellrowborder" valign="top" width="68%" id="mcps1.2.3.1.2"><p id="p21434480422"><a name="p21434480422"></a><a name="p21434480422"></a>Applicable Platform</p>
</th>
</tr>
</thead>
<tbody><tr id="row171431248114219"><td class="cellrowborder" valign="top" width="32%" headers="mcps1.2.3.1.1 "><p id="p214334884214"><a name="p214334884214"></a><a name="p214334884214"></a>base/startup/appspawn_lite</p>
</td>
<td class="cellrowborder" valign="top" width="68%" headers="mcps1.2.3.1.2 "><p id="p35161141183916"><a name="p35161141183916"></a><a name="p35161141183916"></a>Small-system devices (reference memory ≥ 1 MB), for example, Hi3516D V300 and Hi3518E V300</p>
</td>
</tr>
<tr id="row1814320488422"><td class="cellrowborder" valign="top" width="32%" headers="mcps1.2.3.1.1 "><p id="p1314315485427"><a name="p1314315485427"></a><a name="p1314315485427"></a>base/startup/bootstrap_lite</p>
</td>
<td class="cellrowborder" valign="top" width="68%" headers="mcps1.2.3.1.2 "><p id="p136879536392"><a name="p136879536392"></a><a name="p136879536392"></a>Mini-system devices (reference memory ≥ 128 KB), for example, Hi3861 V100</p>
</td>
</tr>
<tr id="row1114304818420"><td class="cellrowborder" align="left" valign="top" width="32%" headers="mcps1.2.3.1.1 "><p id="p181431448194220"><a name="p181431448194220"></a><a name="p181431448194220"></a>base/startup/init_lite</p>
</td>
<td class="cellrowborder" valign="top" width="68%" headers="mcps1.2.3.1.2 "><p id="p865161134018"><a name="p865161134018"></a><a name="p865161134018"></a>Small-system devices (reference memory ≥ 1 MB), for example, Hi3516D V300 and Hi3518E V300</p>
</td>
</tr>
<tr id="row2014324824218"><td class="cellrowborder" valign="top" width="32%" headers="mcps1.2.3.1.1 "><p id="p14143348184215"><a name="p14143348184215"></a><a name="p14143348184215"></a>base/startup/syspara_lite</p>
</td>
<td class="cellrowborder" valign="top" width="68%" headers="mcps1.2.3.1.2 "><a name="ul15501216165214"></a><a name="ul15501216165214"></a><ul id="ul15501216165214"><li>Mini-system devices (reference memory ≥ 128 KB), for example, Hi3861 V100</li><li>Small-system devices (reference memory ≥ 1 MB), for example, Hi3516D V300 and Hi3518E V300</li></ul>
</td>
</tr>
</tbody>
</table>

<a name="table199918224599"></a>
<table><thead align="left"><tr id="row69992022175918"><th class="cellrowborder" valign="top" width="32.36%" id="mcps1.1.3.1.1"><p id="p699919222593"><a name="p699919222593"></a><a name="p699919222593"></a>Directory</p>
</th>
<th class="cellrowborder" valign="top" width="67.64%" id="mcps1.1.3.1.2"><p id="p11999132285919"><a name="p11999132285919"></a><a name="p11999132285919"></a>Applicable Platform</p>
</th>
</tr>
</thead>
<tbody><tr id="row10019234596"><td class="cellrowborder" valign="top" width="32.36%" headers="mcps1.1.3.1.1 "><p id="p17042345911"><a name="p17042345911"></a><a name="p17042345911"></a>base/startup/startup</p>
</td>
<td class="cellrowborder" valign="top" width="67.64%" headers="mcps1.1.3.1.2 "><p id="p4092313592"><a name="p4092313592"></a><a name="p4092313592"></a>Large-system devices (reference memory ≥ 1 GB)</p>
</td>
</tr>
<tr id="row15052311597"><td class="cellrowborder" valign="top" width="32.36%" headers="mcps1.1.3.1.1 "><p id="p10019232591"><a name="p10019232591"></a><a name="p10019232591"></a>base/startup/systemrestore</p>
</td>
<td class="cellrowborder" valign="top" width="67.64%" headers="mcps1.1.3.1.2 "><p id="p90323125911"><a name="p90323125911"></a><a name="p90323125911"></a>Large-system devices (reference memory ≥ 1 GB)</p>
</td>
</tr>
</tbody>
</table>

-   init module
    -   After being burnt to the development board, the configuration file  **init.cfg**  changes to read-only. If you want to modify the file, you must repack and burn the rootfs image again.
    -   The configuration file  **init.cfg**  must be in JSON format.

-   bootstrap module: The zInit code needs to be configured in the link script.
-   syspara module: The SetParameter and GetParameter APIs can only be called by applications whose UID is greater than 1000.

