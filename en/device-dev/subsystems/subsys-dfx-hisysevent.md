# Development Guidelines on HiSysEvent<a name="EN-US_TOPIC_0000001091101688"></a>

## Overview<a name="section77571101789"></a>

HiSysEvent provides event logging APIs for OpenHarmony to record important information of key processes during system running, helping you locate faults. In addition, you can upload the log data to the cloud for big data analytics.

## Available APIs<a name="section13480315886"></a>

The following table lists the C++ APIs provided by the  **HiSysEvent**  class.

For details about the  **HiSysEvent**  class, see the API reference.

**Table  1**  C++ APIs provided by HiSysEvent

<a name="table1972602519328"></a>
<table><thead align="left"><tr id="row5726112593219"><th class="cellrowborder" valign="top" width="57.38999999999999%" id="mcps1.2.3.1.1"><p id="p1472602523216"><a name="p1472602523216"></a><a name="p1472602523216"></a>API</p>
</th>
<th class="cellrowborder" valign="top" width="42.61%" id="mcps1.2.3.1.2"><p id="p12726112512322"><a name="p12726112512322"></a><a name="p12726112512322"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row47261259328"><td class="cellrowborder" valign="top" width="57.38999999999999%" headers="mcps1.2.3.1.1 "><p id="p15726112583213"><a name="p15726112583213"></a><a name="p15726112583213"></a>template&lt;typename... Types&gt; static int Write(const std::string &amp;domain, const std::string &amp;eventName, EventType type, Types... keyValues)</p>
</td>
<td class="cellrowborder" valign="top" width="42.61%" headers="mcps1.2.3.1.2 "><p id="p14727325133216"><a name="p14727325133216"></a><a name="p14727325133216"></a>Logs system events.</p>
<p id="p167271525203213"><a name="p167271525203213"></a><a name="p167271525203213"></a>Input arguments:</p>
<a name="ul0727102516327"></a><a name="ul0727102516327"></a><ul id="ul0727102516327"><li>domain: Indicates the domain related to the event. You can use a preconfigured domain or customize a domain as needed. The name of a custom domain can contain a maximum of 16 characters, including digits (0-9) and uppercase letters (A-Z). It must start with a letter.</li><li>eventName: Indicates the event name. The value contains a maximum of 32 characters, including digits (0 to 9), lowercase letters (a-z), uppercase letters (A-Z), and underscores (_). It must start with a letter and cannot end with an underscore (_).</li><li>type: Indicates the event type. For details, see <strong id="b137231746124214"><a name="b137231746124214"></a><a name="b137231746124214"></a>EventType</strong>.</li><li>keyValues: Indicates the key-value pairs of event parameters. It can be in the format of the basic data type, <strong id="b1270524734214"><a name="b1270524734214"></a><a name="b1270524734214"></a>std::string</strong>, <strong id="b1870517478422"><a name="b1870517478422"></a><a name="b1870517478422"></a>std::vector<em id="i5705114724211"><a name="i5705114724211"></a><a name="i5705114724211"></a>&lt;basic data type&gt;</em></strong>, or <strong id="b2070614724211"><a name="b2070614724211"></a><a name="b2070614724211"></a>std:vector&lt;std::string&gt;</strong>. The value contains a maximum of 48 characters, including digits (0 to 9), lowercase letters (a-z), uppercase letters (A-Z), and underscores (_). It must start with a letter and cannot end with an underscore (_). The number of parameter names cannot exceed 32.</li></ul>
<p id="p1727152513217"><a name="p1727152513217"></a><a name="p1727152513217"></a>Return value: Returns <strong id="b1893811237358"><a name="b1893811237358"></a><a name="b1893811237358"></a>0</strong> if the operation is successful; returns a value less than <strong id="b99381232350"><a name="b99381232350"></a><a name="b99381232350"></a>0</strong> otherwise.</p>
</td>
</tr>
</tbody>
</table>

**Table  2**  Description of HiSysEvent::Domain APIs

<a name="table142141234133615"></a>
<table><thead align="left"><tr id="row8214234193616"><th class="cellrowborder" valign="top" width="57.38999999999999%" id="mcps1.2.3.1.1"><p id="p13214183417365"><a name="p13214183417365"></a><a name="p13214183417365"></a>API</p>
</th>
<th class="cellrowborder" valign="top" width="42.61%" id="mcps1.2.3.1.2"><p id="p1721593463618"><a name="p1721593463618"></a><a name="p1721593463618"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row14215133418366"><td class="cellrowborder" valign="top" width="57.38999999999999%" headers="mcps1.2.3.1.1 "><p id="p22151634123614"><a name="p22151634123614"></a><a name="p22151634123614"></a>static const std::string AAFWK</p>
</td>
<td class="cellrowborder" valign="top" width="42.61%" headers="mcps1.2.3.1.2 "><p id="p19215163483612"><a name="p19215163483612"></a><a name="p19215163483612"></a>Ability management framework</p>
</td>
</tr>
<tr id="row10215134203618"><td class="cellrowborder" valign="top" width="57.38999999999999%" headers="mcps1.2.3.1.1 "><p id="p1935112710382"><a name="p1935112710382"></a><a name="p1935112710382"></a>static const std::string APPEXECFWK</p>
</td>
<td class="cellrowborder" valign="top" width="42.61%" headers="mcps1.2.3.1.2 "><p id="p2215183419362"><a name="p2215183419362"></a><a name="p2215183419362"></a>Application framework</p>
</td>
</tr>
<tr id="row2021515343365"><td class="cellrowborder" valign="top" width="57.38999999999999%" headers="mcps1.2.3.1.1 "><p id="p03509723812"><a name="p03509723812"></a><a name="p03509723812"></a>static const std::string ACCOUNT</p>
</td>
<td class="cellrowborder" valign="top" width="42.61%" headers="mcps1.2.3.1.2 "><p id="p142155348362"><a name="p142155348362"></a><a name="p142155348362"></a>Account subsystem</p>
</td>
</tr>
<tr id="row162151334143616"><td class="cellrowborder" valign="top" width="57.38999999999999%" headers="mcps1.2.3.1.1 "><p id="p2349778386"><a name="p2349778386"></a><a name="p2349778386"></a>static const std::string ACE</p>
</td>
<td class="cellrowborder" valign="top" width="42.61%" headers="mcps1.2.3.1.2 "><p id="p721510342365"><a name="p721510342365"></a><a name="p721510342365"></a>ACE subsystem</p>
</td>
</tr>
<tr id="row4215193413618"><td class="cellrowborder" valign="top" width="57.38999999999999%" headers="mcps1.2.3.1.1 "><p id="p173487753812"><a name="p173487753812"></a><a name="p173487753812"></a>static const std::string AI</p>
</td>
<td class="cellrowborder" valign="top" width="42.61%" headers="mcps1.2.3.1.2 "><p id="p182159347368"><a name="p182159347368"></a><a name="p182159347368"></a>AI subsystem</p>
</td>
</tr>
<tr id="row112151534193614"><td class="cellrowborder" valign="top" width="57.38999999999999%" headers="mcps1.2.3.1.1 "><p id="p19348975387"><a name="p19348975387"></a><a name="p19348975387"></a>static const std::string BARRIER_FREE</p>
</td>
<td class="cellrowborder" valign="top" width="42.61%" headers="mcps1.2.3.1.2 "><p id="p6215183412369"><a name="p6215183412369"></a><a name="p6215183412369"></a>Accessibility subsystem</p>
</td>
</tr>
<tr id="row1721573415364"><td class="cellrowborder" valign="top" width="57.38999999999999%" headers="mcps1.2.3.1.1 "><p id="p163474783815"><a name="p163474783815"></a><a name="p163474783815"></a>static const std::string BIOMETRICS</p>
</td>
<td class="cellrowborder" valign="top" width="42.61%" headers="mcps1.2.3.1.2 "><p id="p1521583443619"><a name="p1521583443619"></a><a name="p1521583443619"></a>Biometric recognition subsystem</p>
</td>
</tr>
<tr id="row321513423619"><td class="cellrowborder" valign="top" width="57.38999999999999%" headers="mcps1.2.3.1.1 "><p id="p334617713387"><a name="p334617713387"></a><a name="p334617713387"></a>static const std::string CCRUNTIME</p>
</td>
<td class="cellrowborder" valign="top" width="42.61%" headers="mcps1.2.3.1.2 "><p id="p1421513417361"><a name="p1421513417361"></a><a name="p1421513417361"></a>C/C++ operating environment subsystem</p>
</td>
</tr>
<tr id="row192165341362"><td class="cellrowborder" valign="top" width="57.38999999999999%" headers="mcps1.2.3.1.1 "><p id="p33458773814"><a name="p33458773814"></a><a name="p33458773814"></a>static const std::string COMMUNICATION</p>
</td>
<td class="cellrowborder" valign="top" width="42.61%" headers="mcps1.2.3.1.2 "><p id="p2216143411364"><a name="p2216143411364"></a><a name="p2216143411364"></a>Communication subsystem</p>
</td>
</tr>
<tr id="row52162034183611"><td class="cellrowborder" valign="top" width="57.38999999999999%" headers="mcps1.2.3.1.1 "><p id="p1634417123816"><a name="p1634417123816"></a><a name="p1634417123816"></a>static const std::string DEVELOPTOOLS</p>
</td>
<td class="cellrowborder" valign="top" width="42.61%" headers="mcps1.2.3.1.2 "><p id="p1121643473611"><a name="p1121643473611"></a><a name="p1121643473611"></a>Development toolchain subsystem</p>
</td>
</tr>
<tr id="row10216133483618"><td class="cellrowborder" valign="top" width="57.38999999999999%" headers="mcps1.2.3.1.1 "><p id="p834314716385"><a name="p834314716385"></a><a name="p834314716385"></a>static const std::string DISTRIBUTED_DATAMGR</p>
</td>
<td class="cellrowborder" valign="top" width="42.61%" headers="mcps1.2.3.1.2 "><p id="p621693417364"><a name="p621693417364"></a><a name="p621693417364"></a>Distributed data management subsystem</p>
</td>
</tr>
<tr id="row10216153414361"><td class="cellrowborder" valign="top" width="57.38999999999999%" headers="mcps1.2.3.1.1 "><p id="p8342127193813"><a name="p8342127193813"></a><a name="p8342127193813"></a>static const std::string DISTRIBUTED_SCHEDULE</p>
</td>
<td class="cellrowborder" valign="top" width="42.61%" headers="mcps1.2.3.1.2 "><p id="p1321603418362"><a name="p1321603418362"></a><a name="p1321603418362"></a>Distributed scheduler subsystem</p>
</td>
</tr>
<tr id="row18216934193616"><td class="cellrowborder" valign="top" width="57.38999999999999%" headers="mcps1.2.3.1.1 "><p id="p6342670388"><a name="p6342670388"></a><a name="p6342670388"></a>static const std::string GLOBAL</p>
</td>
<td class="cellrowborder" valign="top" width="42.61%" headers="mcps1.2.3.1.2 "><p id="p12162342368"><a name="p12162342368"></a><a name="p12162342368"></a>Globalization subsystem</p>
</td>
</tr>
<tr id="row1921643473618"><td class="cellrowborder" valign="top" width="57.38999999999999%" headers="mcps1.2.3.1.1 "><p id="p43413743815"><a name="p43413743815"></a><a name="p43413743815"></a>static const std::string GRAPHIC</p>
</td>
<td class="cellrowborder" valign="top" width="42.61%" headers="mcps1.2.3.1.2 "><p id="p921663443620"><a name="p921663443620"></a><a name="p921663443620"></a>Graphics subsystem</p>
</td>
</tr>
<tr id="row1216113412368"><td class="cellrowborder" valign="top" width="57.38999999999999%" headers="mcps1.2.3.1.1 "><p id="p434015743812"><a name="p434015743812"></a><a name="p434015743812"></a>static const std::string HIVIEWDFX</p>
</td>
<td class="cellrowborder" valign="top" width="42.61%" headers="mcps1.2.3.1.2 "><p id="p32165345365"><a name="p32165345365"></a><a name="p32165345365"></a>DFX subsystem</p>
</td>
</tr>
<tr id="row122165342363"><td class="cellrowborder" valign="top" width="57.38999999999999%" headers="mcps1.2.3.1.1 "><p id="p333912703815"><a name="p333912703815"></a><a name="p333912703815"></a>static const std::string IAWARE</p>
</td>
<td class="cellrowborder" valign="top" width="42.61%" headers="mcps1.2.3.1.2 "><p id="p82161134113614"><a name="p82161134113614"></a><a name="p82161134113614"></a>Scheduling and resource management subsystem</p>
</td>
</tr>
<tr id="row221673473618"><td class="cellrowborder" valign="top" width="57.38999999999999%" headers="mcps1.2.3.1.1 "><p id="p233815723812"><a name="p233815723812"></a><a name="p233815723812"></a>static const std::string INTELLI_ACCESSORIES</p>
</td>
<td class="cellrowborder" valign="top" width="42.61%" headers="mcps1.2.3.1.2 "><p id="p1121793463615"><a name="p1121793463615"></a><a name="p1121793463615"></a>Smart accessory subsystem</p>
</td>
</tr>
<tr id="row1821783414362"><td class="cellrowborder" valign="top" width="57.38999999999999%" headers="mcps1.2.3.1.1 "><p id="p173371976381"><a name="p173371976381"></a><a name="p173371976381"></a>static const std::string INTELLI_TV</p>
</td>
<td class="cellrowborder" valign="top" width="42.61%" headers="mcps1.2.3.1.2 "><p id="p1121716345369"><a name="p1121716345369"></a><a name="p1121716345369"></a>Smart TV subsystem</p>
</td>
</tr>
<tr id="row20217123483613"><td class="cellrowborder" valign="top" width="57.38999999999999%" headers="mcps1.2.3.1.1 "><p id="p733610743820"><a name="p733610743820"></a><a name="p733610743820"></a>static const std::string IVI_HARDWARE</p>
</td>
<td class="cellrowborder" valign="top" width="42.61%" headers="mcps1.2.3.1.2 "><p id="p321723443615"><a name="p321723443615"></a><a name="p321723443615"></a>IVI-dedicated hardware subsystem</p>
</td>
</tr>
<tr id="row112171334143617"><td class="cellrowborder" valign="top" width="57.38999999999999%" headers="mcps1.2.3.1.1 "><p id="p03351274383"><a name="p03351274383"></a><a name="p03351274383"></a>static const std::string LOCATION</p>
</td>
<td class="cellrowborder" valign="top" width="42.61%" headers="mcps1.2.3.1.2 "><p id="p6217193453611"><a name="p6217193453611"></a><a name="p6217193453611"></a>Location subsystem</p>
</td>
</tr>
<tr id="row221773418362"><td class="cellrowborder" valign="top" width="57.38999999999999%" headers="mcps1.2.3.1.1 "><p id="p03359773815"><a name="p03359773815"></a><a name="p03359773815"></a>static const std::string MSDP</p>
</td>
<td class="cellrowborder" valign="top" width="42.61%" headers="mcps1.2.3.1.2 "><p id="p621714342361"><a name="p621714342361"></a><a name="p621714342361"></a>MSDP subsystem</p>
</td>
</tr>
<tr id="row6217113473615"><td class="cellrowborder" valign="top" width="57.38999999999999%" headers="mcps1.2.3.1.1 "><p id="p18334177386"><a name="p18334177386"></a><a name="p18334177386"></a>static const std::string MULTI_MEDIA</p>
</td>
<td class="cellrowborder" valign="top" width="42.61%" headers="mcps1.2.3.1.2 "><p id="p1521763418365"><a name="p1521763418365"></a><a name="p1521763418365"></a>Multimedia subsystem</p>
</td>
</tr>
<tr id="row1621719347364"><td class="cellrowborder" valign="top" width="57.38999999999999%" headers="mcps1.2.3.1.1 "><p id="p18333147173816"><a name="p18333147173816"></a><a name="p18333147173816"></a>static const std::string MULTI_MODAL_INPUT</p>
</td>
<td class="cellrowborder" valign="top" width="42.61%" headers="mcps1.2.3.1.2 "><p id="p92171234133620"><a name="p92171234133620"></a><a name="p92171234133620"></a>Multimodal input subsystem</p>
</td>
</tr>
<tr id="row1121710348363"><td class="cellrowborder" valign="top" width="57.38999999999999%" headers="mcps1.2.3.1.1 "><p id="p153320793817"><a name="p153320793817"></a><a name="p153320793817"></a>static const std::string NOTIFICATION</p>
</td>
<td class="cellrowborder" valign="top" width="42.61%" headers="mcps1.2.3.1.2 "><p id="p10217163414360"><a name="p10217163414360"></a><a name="p10217163414360"></a>Common event and notification subsystem</p>
</td>
</tr>
<tr id="row9217133493616"><td class="cellrowborder" valign="top" width="57.38999999999999%" headers="mcps1.2.3.1.1 "><p id="p133315763820"><a name="p133315763820"></a><a name="p133315763820"></a>static const std::string POWERMGR</p>
</td>
<td class="cellrowborder" valign="top" width="42.61%" headers="mcps1.2.3.1.2 "><p id="p321715349360"><a name="p321715349360"></a><a name="p321715349360"></a>Power management subsystem</p>
</td>
</tr>
<tr id="row8217143413368"><td class="cellrowborder" valign="top" width="57.38999999999999%" headers="mcps1.2.3.1.1 "><p id="p163301279387"><a name="p163301279387"></a><a name="p163301279387"></a>static const std::string ROUTER</p>
</td>
<td class="cellrowborder" valign="top" width="42.61%" headers="mcps1.2.3.1.2 "><p id="p5218123414363"><a name="p5218123414363"></a><a name="p5218123414363"></a>Router subsystem</p>
</td>
</tr>
<tr id="row2021813344362"><td class="cellrowborder" valign="top" width="57.38999999999999%" headers="mcps1.2.3.1.1 "><p id="p1233027113819"><a name="p1233027113819"></a><a name="p1233027113819"></a>static const std::string SECURITY</p>
</td>
<td class="cellrowborder" valign="top" width="42.61%" headers="mcps1.2.3.1.2 "><p id="p92181034193613"><a name="p92181034193613"></a><a name="p92181034193613"></a>Security subsystem</p>
</td>
</tr>
<tr id="row1321812344367"><td class="cellrowborder" valign="top" width="57.38999999999999%" headers="mcps1.2.3.1.1 "><p id="p113291753813"><a name="p113291753813"></a><a name="p113291753813"></a>static const std::string SENSORS</p>
</td>
<td class="cellrowborder" valign="top" width="42.61%" headers="mcps1.2.3.1.2 "><p id="p20218143417362"><a name="p20218143417362"></a><a name="p20218143417362"></a>Pan-sensor subsystem</p>
</td>
</tr>
<tr id="row1721810349368"><td class="cellrowborder" valign="top" width="57.38999999999999%" headers="mcps1.2.3.1.1 "><p id="p8328270388"><a name="p8328270388"></a><a name="p8328270388"></a>static const std::string SOURCE_CODE_TRANSFORMER</p>
</td>
<td class="cellrowborder" valign="top" width="42.61%" headers="mcps1.2.3.1.2 "><p id="p1121893413614"><a name="p1121893413614"></a><a name="p1121893413614"></a>Application porting subsystem</p>
</td>
</tr>
<tr id="row1221812343368"><td class="cellrowborder" valign="top" width="57.38999999999999%" headers="mcps1.2.3.1.1 "><p id="p73273715382"><a name="p73273715382"></a><a name="p73273715382"></a>static const std::string STARTUP</p>
</td>
<td class="cellrowborder" valign="top" width="42.61%" headers="mcps1.2.3.1.2 "><p id="p021816348364"><a name="p021816348364"></a><a name="p021816348364"></a>Startup subsystem</p>
</td>
</tr>
<tr id="row62181634113613"><td class="cellrowborder" valign="top" width="57.38999999999999%" headers="mcps1.2.3.1.1 "><p id="p93261674389"><a name="p93261674389"></a><a name="p93261674389"></a>static const std::string TELEPHONY</p>
</td>
<td class="cellrowborder" valign="top" width="42.61%" headers="mcps1.2.3.1.2 "><p id="p1021843453616"><a name="p1021843453616"></a><a name="p1021843453616"></a>Telephony subsystem</p>
</td>
</tr>
<tr id="row2218153416363"><td class="cellrowborder" valign="top" width="57.38999999999999%" headers="mcps1.2.3.1.1 "><p id="p20326117193818"><a name="p20326117193818"></a><a name="p20326117193818"></a>static const std::string UPDATE</p>
</td>
<td class="cellrowborder" valign="top" width="42.61%" headers="mcps1.2.3.1.2 "><p id="p1221813473617"><a name="p1221813473617"></a><a name="p1221813473617"></a>Update subsystem</p>
</td>
</tr>
<tr id="row921893411361"><td class="cellrowborder" valign="top" width="57.38999999999999%" headers="mcps1.2.3.1.1 "><p id="p23251372386"><a name="p23251372386"></a><a name="p23251372386"></a>static const std::string USB</p>
</td>
<td class="cellrowborder" valign="top" width="42.61%" headers="mcps1.2.3.1.2 "><p id="p1421963493612"><a name="p1421963493612"></a><a name="p1421963493612"></a>USB subsystem</p>
</td>
</tr>
<tr id="row102191534183614"><td class="cellrowborder" valign="top" width="57.38999999999999%" headers="mcps1.2.3.1.1 "><p id="p1232397193818"><a name="p1232397193818"></a><a name="p1232397193818"></a>static const std::string WEARABLE_HARDWARE</p>
</td>
<td class="cellrowborder" valign="top" width="42.61%" headers="mcps1.2.3.1.2 "><p id="p1921919346367"><a name="p1921919346367"></a><a name="p1921919346367"></a>Wearable-dedicated hardware subsystem</p>
</td>
</tr>
<tr id="row721963413368"><td class="cellrowborder" valign="top" width="57.38999999999999%" headers="mcps1.2.3.1.1 "><p id="p63041770381"><a name="p63041770381"></a><a name="p63041770381"></a>static const std::string WEARABLE</p>
</td>
<td class="cellrowborder" valign="top" width="42.61%" headers="mcps1.2.3.1.2 "><p id="p18219143493618"><a name="p18219143493618"></a><a name="p18219143493618"></a>Wearable-dedicated service subsystem</p>
</td>
</tr>
<tr id="row845612549416"><td class="cellrowborder" valign="top" width="57.38999999999999%" headers="mcps1.2.3.1.1 "><p id="p13457155424112"><a name="p13457155424112"></a><a name="p13457155424112"></a>static const std::string OTHERS</p>
</td>
<td class="cellrowborder" valign="top" width="42.61%" headers="mcps1.2.3.1.2 "><p id="p44573548414"><a name="p44573548414"></a><a name="p44573548414"></a>Others</p>
</td>
</tr>
</tbody>
</table>

**Table  3**  Description of HiSysEvent::EventType APIs

<a name="table0944173117434"></a>
<table><thead align="left"><tr id="row694473134311"><th class="cellrowborder" valign="top" width="57.38999999999999%" id="mcps1.2.3.1.1"><p id="p394413113439"><a name="p394413113439"></a><a name="p394413113439"></a>API</p>
</th>
<th class="cellrowborder" valign="top" width="42.61%" id="mcps1.2.3.1.2"><p id="p199441431154317"><a name="p199441431154317"></a><a name="p199441431154317"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1894416312438"><td class="cellrowborder" valign="top" width="57.38999999999999%" headers="mcps1.2.3.1.1 "><p id="p2094483154311"><a name="p2094483154311"></a><a name="p2094483154311"></a>FAULT</p>
</td>
<td class="cellrowborder" valign="top" width="42.61%" headers="mcps1.2.3.1.2 "><p id="p5944153124316"><a name="p5944153124316"></a><a name="p5944153124316"></a>Fault event</p>
</td>
</tr>
<tr id="row2944193134318"><td class="cellrowborder" valign="top" width="57.38999999999999%" headers="mcps1.2.3.1.1 "><p id="p494443144312"><a name="p494443144312"></a><a name="p494443144312"></a>STATISTIC</p>
</td>
<td class="cellrowborder" valign="top" width="42.61%" headers="mcps1.2.3.1.2 "><p id="p1494423111435"><a name="p1494423111435"></a><a name="p1494423111435"></a>Statistical event</p>
</td>
</tr>
<tr id="row094463144311"><td class="cellrowborder" valign="top" width="57.38999999999999%" headers="mcps1.2.3.1.1 "><p id="p594443184315"><a name="p594443184315"></a><a name="p594443184315"></a>SECURITY</p>
</td>
<td class="cellrowborder" valign="top" width="42.61%" headers="mcps1.2.3.1.2 "><p id="p1194417316435"><a name="p1194417316435"></a><a name="p1194417316435"></a>Security event</p>
</td>
</tr>
<tr id="row1294403119434"><td class="cellrowborder" valign="top" width="57.38999999999999%" headers="mcps1.2.3.1.1 "><p id="p17944431164319"><a name="p17944431164319"></a><a name="p17944431164319"></a>BEHAVIOR</p>
</td>
<td class="cellrowborder" valign="top" width="42.61%" headers="mcps1.2.3.1.2 "><p id="p5945203184318"><a name="p5945203184318"></a><a name="p5945203184318"></a>System behavior event</p>
</td>
</tr>
</tbody>
</table>

## How to Develop<a name="section112771171317"></a>

**C++**

1.  Develop the source code.

    Include the  **HiSysEvent**  header file in the class definition header file or class implementation source file. For example:

    ```
    #include "hisysevent.h"
    ```

    Add the event logging code. For example, if you want to log events specific to the app start time \(start\_app\), then add the following code to the service implementation source file:

    ```
    HiSysEvent::Write(HiSysEvent::Domain::AAFWK, "start_app", HiSysEvent::EventType::FAULT, "app_name", "com.demo");
    ```

2.  Configure compilation information. Specifically, add the subsystem SDK dependency to  **BUILD.gn**.

    ```
    external_deps = [ "hisysevent_native:libhisysevent" ]
    ```


