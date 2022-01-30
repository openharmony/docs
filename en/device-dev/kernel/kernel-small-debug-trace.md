# Trace<a name="EN-US_TOPIC_0000001123695263"></a>

## Basic Concepts<a name="section531482192018"></a>

Trace is a functional framework provided by the kernel for tracing key processes of modules. You can implement trace at key positions for modules based on mechanism requirements, and export the traced information as files or in other modes for further analysis.

The requirements for trace are as follows:

1.  The information needs to be recorded as soon as possible to minimize the impact on the system time sequence.
2.  Use as little space as possible to store as much as possible data to reduce memory consumption.

## Working Principles<a name="section5125124532010"></a>

Initialize the trace function at the beginning of the kernel startup. When the modules that support the trace function are initialized, register the trace type and callback functions. The position of the trace point that triggers trace recording can be determined by each module.

When a trace point is triggered, the trace module encapsulates the input information and adds the trace frame header information, including the trace type, ID of the running CPU, ID of the running task, relative timestamp of the running task, and ID of the running process. Then, the trace frame is recorded in a pre-requested cyclic buffer.

If too many frames are recorded in the cyclic buffer, earlier frames will be overwritten to ensure that the information in the buffer is always the latest. The traced data in the cyclic buffer can be exported, for example, by using file dumping, for further analysis. The exported files are sorted by timestamp.

![](figure/en-us_image_0000001127390512.png)

## Usage<a name="section1381714413216"></a>

1.  Configure the trace macro  **LOSCFG\_KERNEL\_TRACE**, which is disabled by default. You can enable it by choosing  **Kernel**  \>  **Enable Trace Feature**  on the  **menuconfig**.
2.  Call  **OsTraceInit**  to complete trace initialization.
3.  Define the traceframe structure of the module in  **los\_trace\_frame.h**, and implement the trace callback function of the module in  **los\_trace\_frame.c**.
4.  Call  **LOS\_TraceReg**  to register trace in the initialization or earlier phase for the modules to be traced.
5.  Enable the trace function at the position where the tracing starts and disable the trace function at the position where the tracing stops.
6.  Call  **LOS\_Trace2File**  to export traced data to a file.
7.  Perform further data analysis based on the frame header and frame body structure.

**Available APIs**

The following table describes APIs available for the OpenHarmony LiteOS-A trace framework. For more details about the APIs, see the API reference.

**Table  1**  Trace Interface Description

<a name="table818431314338"></a>
<table><thead align="left"><tr id="row151841613163315"><th class="cellrowborder" valign="top" width="33.33333333333333%" id="mcps1.2.4.1.1"><p id="p159375113174"><a name="p159375113174"></a><a name="p159375113174"></a>Category</p>
</th>
<th class="cellrowborder" valign="top" width="33.33333333333333%" id="mcps1.2.4.1.2"><p id="p199385118173"><a name="p199385118173"></a><a name="p199385118173"></a>API</p>
</th>
<th class="cellrowborder" valign="top" width="33.33333333333333%" id="mcps1.2.4.1.3"><p id="p18937511175"><a name="p18937511175"></a><a name="p18937511175"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1918541303315"><td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.1 "><p id="p518551319333"><a name="p518551319333"></a><a name="p518551319333"></a>Tracing information</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.2 "><p id="p19185513103317"><a name="p19185513103317"></a><a name="p19185513103317"></a>LOS_Trace</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.3 "><p id="p1118515135337"><a name="p1118515135337"></a><a name="p1118515135337"></a>Traces information.</p>
</td>
</tr>
<tr id="row13185111320331"><td class="cellrowborder" rowspan="2" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.1 "><p id="p13512294508"><a name="p13512294508"></a><a name="p13512294508"></a>Registration and unregistration</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.2 "><p id="p151852013203318"><a name="p151852013203318"></a><a name="p151852013203318"></a>LOS_TraceReg</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.3 "><p id="p1318571310338"><a name="p1318571310338"></a><a name="p1318571310338"></a>Registers the trace type.</p>
</td>
</tr>
<tr id="row201858136336"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p6185171393311"><a name="p6185171393311"></a><a name="p6185171393311"></a>LOS_TraceUnreg</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p1185181363313"><a name="p1185181363313"></a><a name="p1185181363313"></a>Unregisters the trace type.</p>
</td>
</tr>
<tr id="row1518581363317"><td class="cellrowborder" rowspan="2" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.1 "><p id="p20974111585115"><a name="p20974111585115"></a><a name="p20974111585115"></a>Switch</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.2 "><p id="p91858132336"><a name="p91858132336"></a><a name="p91858132336"></a>LOS_TraceTypeSwitch</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.3 "><p id="p11185121313333"><a name="p11185121313333"></a><a name="p11185121313333"></a>Enables or disables the specified type of trace.</p>
</td>
</tr>
<tr id="row14185101310339"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p1185151323311"><a name="p1185151323311"></a><a name="p1185151323311"></a>LOS_TraceSwitch</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p61852135331"><a name="p61852135331"></a><a name="p61852135331"></a>Enables or disables the trace function.</p>
</td>
</tr>
<tr id="row71858133339"><td class="cellrowborder" rowspan="2" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.1 "><p id="p12306322125115"><a name="p12306322125115"></a><a name="p12306322125115"></a>Data export</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.2 "><p id="p481141115110"><a name="p481141115110"></a><a name="p481141115110"></a>LOS_TraceBufDataGet</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.3 "><p id="p131851813173314"><a name="p131851813173314"></a><a name="p131851813173314"></a>Exports trace data to the heap cache. (The cache space is allocated internally and must be released explicitly.)</p>
</td>
</tr>
<tr id="row10185131373310"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p31851139333"><a name="p31851139333"></a><a name="p31851139333"></a>LOS_Trace2File</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p121856132333"><a name="p121856132333"></a><a name="p121856132333"></a>Saves the trace data to the file system (depending on the file system).</p>
</td>
</tr>
</tbody>
</table>

>![](../public_sys-resources/icon-note.gif) **NOTE:** 
>-   The frame buffer is a cyclic buffer. When it is full, a subsequent write will cause overwrite of the oldest data. You can configure the buffer size in the  **LOS\_TRACE\_BUFFER\_SIZE**  macro in  **los\_config.h**. The default size is  **512**  KiB.
>-   Although trace has completed the assembly and recording as soon as possible, it still has impact on the overall performance of the system.
>-   Trace supports concurrent recording of multiple modules. You can reduce the data analysis volume by enabling or disabling the trace function for different modules on demand.
>-   The task, memory, and liteipc modules of the kernel support the trace recording function.

