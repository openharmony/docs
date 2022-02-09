# HiSysEvent打点指导<a name="ZH-CN_TOPIC_0000001231373947"></a>

-   [概述](#section77571101789)
    -   [功能简介](#section123133332175224)
	-   [约束与限制](#section123181432175224)
-   [开发指导](#section314416685113)
    -   [接口说明](#section13480315886)
    -   [开发实例](#section112771171317)

## 概述<a name="section77571101789"></a>

### 功能简介<a name="section123133332175224"></a>

HiSysEvent提供OpenHarmony打点接口，通过在关键路径打点记录系统在运行过程中的重要信息，辅助开发者定位问题，此外还支持开发者将数据上传到云进行大数据质量度量。

### 约束与限制<a name="section123181432175224"></a>

**HiSysEvent事件打点条件约束：**

- HiSysEvent事件打点结果取决于该HiSysEvent事件是否已在组件中进行配置，具体配置方法请参考[《HiSysEvent打点配置指导》](subsys-dfx-hisysevent-write-config.md)。

## 开发指导<a name="section314416685113"></a>

### 接口说明<a name="section13480315886"></a>

C++打点接口如下：

HiSysEvent类，具体的API详见接口文档 。

**表 1**  HiSysEvent接口介绍

<a name="table1972602519328"></a>
<table><thead align="left"><tr id="row5726112593219"><th class="cellrowborder" valign="top" width="57.38999999999999%" id="mcps1.2.3.1.1"><p id="p1472602523216"><a name="p1472602523216"></a><a name="p1472602523216"></a>接口名</p>
</th>
<th class="cellrowborder" valign="top" width="42.61%" id="mcps1.2.3.1.2"><p id="p12726112512322"><a name="p12726112512322"></a><a name="p12726112512322"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row47261259328"><td class="cellrowborder" valign="top" width="57.38999999999999%" headers="mcps1.2.3.1.1 "><p id="p15726112583213"><a name="p15726112583213"></a><a name="p15726112583213"></a>template&lt;typename... Types&gt; static int Write(const std::string &amp;domain, const std::string &amp;eventName, EventType type, Types... keyValues)</p>
</td>
<td class="cellrowborder" valign="top" width="42.61%" headers="mcps1.2.3.1.2 "><p id="p14727325133216"><a name="p14727325133216"></a><a name="p14727325133216"></a>接口功能：记录系统事件。</p>
<p id="p167271525203213"><a name="p167271525203213"></a><a name="p167271525203213"></a>输入参数：</p>
<a name="ul0727102516327"></a><a name="ul0727102516327"></a><ul id="ul0727102516327"><li>domain：事件的相关领域，需要使用预置领域请参考Domain，可自定义领域。自定义领域长度在16个字符以内，有效的字符是0-9、A-Z，以字母开头。</li><li>eventName：事件名，长度在32个字符以内，有效的字符是0-9、A-Z、_，以字母开头，不能以_结尾。</li><li>type：事件类型，参考EventType。</li><li>keyValues：事件参数键值对，支持基本的数据类型、std::string，以及std::vector&lt;基本类型&gt;、std:vector&lt;std::string&gt;。参数名长度在48个字符以内，有效的字符是0-9、A-Z、_，以字母开头，不能以_结尾。参数名的个数在32个以内。</li></ul>
<p id="p1727152513217"><a name="p1727152513217"></a><a name="p1727152513217"></a>返回值：成功返回0，错误返回小于0的值。</p>
</td>
</tr>
</tbody>
</table>

**表 2**  HiSysEvent::Domain接口介绍

<a name="table142141234133615"></a>
<table><thead align="left"><tr id="row8214234193616"><th class="cellrowborder" valign="top" width="57.38999999999999%" id="mcps1.2.3.1.1"><p id="p13214183417365"><a name="p13214183417365"></a><a name="p13214183417365"></a>成员</p>
</th>
<th class="cellrowborder" valign="top" width="42.61%" id="mcps1.2.3.1.2"><p id="p1721593463618"><a name="p1721593463618"></a><a name="p1721593463618"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row14215133418366"><td class="cellrowborder" valign="top" width="57.38999999999999%" headers="mcps1.2.3.1.1 "><p id="p22151634123614"><a name="p22151634123614"></a><a name="p22151634123614"></a>static const std::string AAFWK</p>
</td>
<td class="cellrowborder" valign="top" width="42.61%" headers="mcps1.2.3.1.2 "><p id="p19215163483612"><a name="p19215163483612"></a><a name="p19215163483612"></a>元能力子系统</p>
</td>
</tr>
<tr id="row10215134203618"><td class="cellrowborder" valign="top" width="57.38999999999999%" headers="mcps1.2.3.1.1 "><p id="p1935112710382"><a name="p1935112710382"></a><a name="p1935112710382"></a>static const std::string APPEXECFWK</p>
</td>
<td class="cellrowborder" valign="top" width="42.61%" headers="mcps1.2.3.1.2 "><p id="p2215183419362"><a name="p2215183419362"></a><a name="p2215183419362"></a>用户程序框架子系统</p>
</td>
</tr>
<tr id="row2021515343365"><td class="cellrowborder" valign="top" width="57.38999999999999%" headers="mcps1.2.3.1.1 "><p id="p03509723812"><a name="p03509723812"></a><a name="p03509723812"></a>static const std::string ACCOUNT</p>
</td>
<td class="cellrowborder" valign="top" width="42.61%" headers="mcps1.2.3.1.2 "><p id="p142155348362"><a name="p142155348362"></a><a name="p142155348362"></a>账号子系统</p>
</td>
</tr>
<tr id="row162151334143616"><td class="cellrowborder" valign="top" width="57.38999999999999%" headers="mcps1.2.3.1.1 "><p id="p2349778386"><a name="p2349778386"></a><a name="p2349778386"></a>static const std::string ACE</p>
</td>
<td class="cellrowborder" valign="top" width="42.61%" headers="mcps1.2.3.1.2 "><p id="p721510342365"><a name="p721510342365"></a><a name="p721510342365"></a>ACE子系统</p>
</td>
</tr>
<tr id="row4215193413618"><td class="cellrowborder" valign="top" width="57.38999999999999%" headers="mcps1.2.3.1.1 "><p id="p173487753812"><a name="p173487753812"></a><a name="p173487753812"></a>static const std::string AI</p>
</td>
<td class="cellrowborder" valign="top" width="42.61%" headers="mcps1.2.3.1.2 "><p id="p182159347368"><a name="p182159347368"></a><a name="p182159347368"></a>AI业务子系统</p>
</td>
</tr>
<tr id="row112151534193614"><td class="cellrowborder" valign="top" width="57.38999999999999%" headers="mcps1.2.3.1.1 "><p id="p19348975387"><a name="p19348975387"></a><a name="p19348975387"></a>static const std::string BARRIER_FREE</p>
</td>
<td class="cellrowborder" valign="top" width="42.61%" headers="mcps1.2.3.1.2 "><p id="p6215183412369"><a name="p6215183412369"></a><a name="p6215183412369"></a>无障碍软件服务子系统</p>
</td>
</tr>
<tr id="row1721573415364"><td class="cellrowborder" valign="top" width="57.38999999999999%" headers="mcps1.2.3.1.1 "><p id="p163474783815"><a name="p163474783815"></a><a name="p163474783815"></a>static const std::string BIOMETRICS</p>
</td>
<td class="cellrowborder" valign="top" width="42.61%" headers="mcps1.2.3.1.2 "><p id="p1521583443619"><a name="p1521583443619"></a><a name="p1521583443619"></a>生物特征识别服务子系统</p>
</td>
</tr>
<tr id="row321513423619"><td class="cellrowborder" valign="top" width="57.38999999999999%" headers="mcps1.2.3.1.1 "><p id="p334617713387"><a name="p334617713387"></a><a name="p334617713387"></a>static const std::string CCRUNTIME</p>
</td>
<td class="cellrowborder" valign="top" width="42.61%" headers="mcps1.2.3.1.2 "><p id="p1421513417361"><a name="p1421513417361"></a><a name="p1421513417361"></a>C/C++运行环境子系统</p>
</td>
</tr>
<tr id="row192165341362"><td class="cellrowborder" valign="top" width="57.38999999999999%" headers="mcps1.2.3.1.1 "><p id="p33458773814"><a name="p33458773814"></a><a name="p33458773814"></a>static const std::string COMMUNICATION</p>
</td>
<td class="cellrowborder" valign="top" width="42.61%" headers="mcps1.2.3.1.2 "><p id="p2216143411364"><a name="p2216143411364"></a><a name="p2216143411364"></a>公共通信子系统</p>
</td>
</tr>
<tr id="row52162034183611"><td class="cellrowborder" valign="top" width="57.38999999999999%" headers="mcps1.2.3.1.1 "><p id="p1634417123816"><a name="p1634417123816"></a><a name="p1634417123816"></a>static const std::string DEVELOPTOOLS</p>
</td>
<td class="cellrowborder" valign="top" width="42.61%" headers="mcps1.2.3.1.2 "><p id="p1121643473611"><a name="p1121643473611"></a><a name="p1121643473611"></a>研发工具链子系统</p>
</td>
</tr>
<tr id="row10216133483618"><td class="cellrowborder" valign="top" width="57.38999999999999%" headers="mcps1.2.3.1.1 "><p id="p834314716385"><a name="p834314716385"></a><a name="p834314716385"></a>static const std::string DISTRIBUTED_DATAMGR</p>
</td>
<td class="cellrowborder" valign="top" width="42.61%" headers="mcps1.2.3.1.2 "><p id="p621693417364"><a name="p621693417364"></a><a name="p621693417364"></a>分布式数据管理子系统</p>
</td>
</tr>
<tr id="row10216153414361"><td class="cellrowborder" valign="top" width="57.38999999999999%" headers="mcps1.2.3.1.1 "><p id="p8342127193813"><a name="p8342127193813"></a><a name="p8342127193813"></a>static const std::string DISTRIBUTED_SCHEDULE</p>
</td>
<td class="cellrowborder" valign="top" width="42.61%" headers="mcps1.2.3.1.2 "><p id="p1321603418362"><a name="p1321603418362"></a><a name="p1321603418362"></a>分布式任务调度子系统</p>
</td>
</tr>
<tr id="row18216934193616"><td class="cellrowborder" valign="top" width="57.38999999999999%" headers="mcps1.2.3.1.1 "><p id="p6342670388"><a name="p6342670388"></a><a name="p6342670388"></a>static const std::string GLOBAL</p>
</td>
<td class="cellrowborder" valign="top" width="42.61%" headers="mcps1.2.3.1.2 "><p id="p12162342368"><a name="p12162342368"></a><a name="p12162342368"></a>全球化子系统</p>
</td>
</tr>
<tr id="row1921643473618"><td class="cellrowborder" valign="top" width="57.38999999999999%" headers="mcps1.2.3.1.1 "><p id="p43413743815"><a name="p43413743815"></a><a name="p43413743815"></a>static const std::string GRAPHIC</p>
</td>
<td class="cellrowborder" valign="top" width="42.61%" headers="mcps1.2.3.1.2 "><p id="p921663443620"><a name="p921663443620"></a><a name="p921663443620"></a>图形子系统</p>
</td>
</tr>
<tr id="row1216113412368"><td class="cellrowborder" valign="top" width="57.38999999999999%" headers="mcps1.2.3.1.1 "><p id="p434015743812"><a name="p434015743812"></a><a name="p434015743812"></a>static const std::string HIVIEWDFX</p>
</td>
<td class="cellrowborder" valign="top" width="42.61%" headers="mcps1.2.3.1.2 "><p id="p32165345365"><a name="p32165345365"></a><a name="p32165345365"></a>DFX子系统</p>
</td>
</tr>
<tr id="row122165342363"><td class="cellrowborder" valign="top" width="57.38999999999999%" headers="mcps1.2.3.1.1 "><p id="p333912703815"><a name="p333912703815"></a><a name="p333912703815"></a>static const std::string IAWARE</p>
</td>
<td class="cellrowborder" valign="top" width="42.61%" headers="mcps1.2.3.1.2 "><p id="p82161134113614"><a name="p82161134113614"></a><a name="p82161134113614"></a>本地资源调度管控子系统</p>
</td>
</tr>
<tr id="row221673473618"><td class="cellrowborder" valign="top" width="57.38999999999999%" headers="mcps1.2.3.1.1 "><p id="p233815723812"><a name="p233815723812"></a><a name="p233815723812"></a>static const std::string INTELLI_ACCESSORIES</p>
</td>
<td class="cellrowborder" valign="top" width="42.61%" headers="mcps1.2.3.1.2 "><p id="p1121793463615"><a name="p1121793463615"></a><a name="p1121793463615"></a>智能配件业务子系统</p>
</td>
</tr>
<tr id="row1821783414362"><td class="cellrowborder" valign="top" width="57.38999999999999%" headers="mcps1.2.3.1.1 "><p id="p173371976381"><a name="p173371976381"></a><a name="p173371976381"></a>static const std::string INTELLI_TV</p>
</td>
<td class="cellrowborder" valign="top" width="42.61%" headers="mcps1.2.3.1.2 "><p id="p1121716345369"><a name="p1121716345369"></a><a name="p1121716345369"></a>智能电视业务子系统</p>
</td>
</tr>
<tr id="row20217123483613"><td class="cellrowborder" valign="top" width="57.38999999999999%" headers="mcps1.2.3.1.1 "><p id="p733610743820"><a name="p733610743820"></a><a name="p733610743820"></a>static const std::string IVI_HARDWARE</p>
</td>
<td class="cellrowborder" valign="top" width="42.61%" headers="mcps1.2.3.1.2 "><p id="p321723443615"><a name="p321723443615"></a><a name="p321723443615"></a>车机专有硬件服务子系统</p>
</td>
</tr>
<tr id="row112171334143617"><td class="cellrowborder" valign="top" width="57.38999999999999%" headers="mcps1.2.3.1.1 "><p id="p03351274383"><a name="p03351274383"></a><a name="p03351274383"></a>static const std::string LOCATION</p>
</td>
<td class="cellrowborder" valign="top" width="42.61%" headers="mcps1.2.3.1.2 "><p id="p6217193453611"><a name="p6217193453611"></a><a name="p6217193453611"></a>位置服务子系统</p>
</td>
</tr>
<tr id="row221773418362"><td class="cellrowborder" valign="top" width="57.38999999999999%" headers="mcps1.2.3.1.1 "><p id="p03359773815"><a name="p03359773815"></a><a name="p03359773815"></a>static const std::string MSDP</p>
</td>
<td class="cellrowborder" valign="top" width="42.61%" headers="mcps1.2.3.1.2 "><p id="p621714342361"><a name="p621714342361"></a><a name="p621714342361"></a>综合传感处理平台子系统</p>
</td>
</tr>
<tr id="row6217113473615"><td class="cellrowborder" valign="top" width="57.38999999999999%" headers="mcps1.2.3.1.1 "><p id="p18334177386"><a name="p18334177386"></a><a name="p18334177386"></a>static const std::string MULTI_MEDIA</p>
</td>
<td class="cellrowborder" valign="top" width="42.61%" headers="mcps1.2.3.1.2 "><p id="p1521763418365"><a name="p1521763418365"></a><a name="p1521763418365"></a>媒体子系统</p>
</td>
</tr>
<tr id="row1621719347364"><td class="cellrowborder" valign="top" width="57.38999999999999%" headers="mcps1.2.3.1.1 "><p id="p18333147173816"><a name="p18333147173816"></a><a name="p18333147173816"></a>static const std::string MULTI_MODAL_INPUT</p>
</td>
<td class="cellrowborder" valign="top" width="42.61%" headers="mcps1.2.3.1.2 "><p id="p92171234133620"><a name="p92171234133620"></a><a name="p92171234133620"></a>多模输入子系统</p>
</td>
</tr>
<tr id="row1121710348363"><td class="cellrowborder" valign="top" width="57.38999999999999%" headers="mcps1.2.3.1.1 "><p id="p153320793817"><a name="p153320793817"></a><a name="p153320793817"></a>static const std::string NOTIFICATION</p>
</td>
<td class="cellrowborder" valign="top" width="42.61%" headers="mcps1.2.3.1.2 "><p id="p10217163414360"><a name="p10217163414360"></a><a name="p10217163414360"></a>事件通知子系统</p>
</td>
</tr>
<tr id="row9217133493616"><td class="cellrowborder" valign="top" width="57.38999999999999%" headers="mcps1.2.3.1.1 "><p id="p133315763820"><a name="p133315763820"></a><a name="p133315763820"></a>static const std::string POWERMGR</p>
</td>
<td class="cellrowborder" valign="top" width="42.61%" headers="mcps1.2.3.1.2 "><p id="p321715349360"><a name="p321715349360"></a><a name="p321715349360"></a>电源服务子系统</p>
</td>
</tr>
<tr id="row8217143413368"><td class="cellrowborder" valign="top" width="57.38999999999999%" headers="mcps1.2.3.1.1 "><p id="p163301279387"><a name="p163301279387"></a><a name="p163301279387"></a>static const std::string ROUTER</p>
</td>
<td class="cellrowborder" valign="top" width="42.61%" headers="mcps1.2.3.1.2 "><p id="p5218123414363"><a name="p5218123414363"></a><a name="p5218123414363"></a>路由器业务子系统</p>
</td>
</tr>
<tr id="row2021813344362"><td class="cellrowborder" valign="top" width="57.38999999999999%" headers="mcps1.2.3.1.1 "><p id="p1233027113819"><a name="p1233027113819"></a><a name="p1233027113819"></a>static const std::string SECURITY</p>
</td>
<td class="cellrowborder" valign="top" width="42.61%" headers="mcps1.2.3.1.2 "><p id="p92181034193613"><a name="p92181034193613"></a><a name="p92181034193613"></a>安全子系统</p>
</td>
</tr>
<tr id="row1321812344367"><td class="cellrowborder" valign="top" width="57.38999999999999%" headers="mcps1.2.3.1.1 "><p id="p113291753813"><a name="p113291753813"></a><a name="p113291753813"></a>static const std::string SENSORS</p>
</td>
<td class="cellrowborder" valign="top" width="42.61%" headers="mcps1.2.3.1.2 "><p id="p20218143417362"><a name="p20218143417362"></a><a name="p20218143417362"></a>泛Sensor服务子系统</p>
</td>
</tr>
<tr id="row1721810349368"><td class="cellrowborder" valign="top" width="57.38999999999999%" headers="mcps1.2.3.1.1 "><p id="p8328270388"><a name="p8328270388"></a><a name="p8328270388"></a>static const std::string SOURCE_CODE_TRANSFORMER</p>
</td>
<td class="cellrowborder" valign="top" width="42.61%" headers="mcps1.2.3.1.2 "><p id="p1121893413614"><a name="p1121893413614"></a><a name="p1121893413614"></a>应用移植子系统</p>
</td>
</tr>
<tr id="row1221812343368"><td class="cellrowborder" valign="top" width="57.38999999999999%" headers="mcps1.2.3.1.1 "><p id="p73273715382"><a name="p73273715382"></a><a name="p73273715382"></a>static const std::string STARTUP</p>
</td>
<td class="cellrowborder" valign="top" width="42.61%" headers="mcps1.2.3.1.2 "><p id="p021816348364"><a name="p021816348364"></a><a name="p021816348364"></a>启动恢复子系统</p>
</td>
</tr>
<tr id="row62181634113613"><td class="cellrowborder" valign="top" width="57.38999999999999%" headers="mcps1.2.3.1.1 "><p id="p93261674389"><a name="p93261674389"></a><a name="p93261674389"></a>static const std::string TELEPHONY</p>
</td>
<td class="cellrowborder" valign="top" width="42.61%" headers="mcps1.2.3.1.2 "><p id="p1021843453616"><a name="p1021843453616"></a><a name="p1021843453616"></a>电话服务子系统</p>
</td>
</tr>
<tr id="row2218153416363"><td class="cellrowborder" valign="top" width="57.38999999999999%" headers="mcps1.2.3.1.1 "><p id="p20326117193818"><a name="p20326117193818"></a><a name="p20326117193818"></a>static const std::string UPDATE</p>
</td>
<td class="cellrowborder" valign="top" width="42.61%" headers="mcps1.2.3.1.2 "><p id="p1221813473617"><a name="p1221813473617"></a><a name="p1221813473617"></a>升级服务子系统</p>
</td>
</tr>
<tr id="row921893411361"><td class="cellrowborder" valign="top" width="57.38999999999999%" headers="mcps1.2.3.1.1 "><p id="p23251372386"><a name="p23251372386"></a><a name="p23251372386"></a>static const std::string USB</p>
</td>
<td class="cellrowborder" valign="top" width="42.61%" headers="mcps1.2.3.1.2 "><p id="p1421963493612"><a name="p1421963493612"></a><a name="p1421963493612"></a>USB服务子系统</p>
</td>
</tr>
<tr id="row102191534183614"><td class="cellrowborder" valign="top" width="57.38999999999999%" headers="mcps1.2.3.1.1 "><p id="p1232397193818"><a name="p1232397193818"></a><a name="p1232397193818"></a>static const std::string WEARABLE_HARDWARE</p>
</td>
<td class="cellrowborder" valign="top" width="42.61%" headers="mcps1.2.3.1.2 "><p id="p1921919346367"><a name="p1921919346367"></a><a name="p1921919346367"></a>穿戴专有硬件服务子系统</p>
</td>
</tr>
<tr id="row721963413368"><td class="cellrowborder" valign="top" width="57.38999999999999%" headers="mcps1.2.3.1.1 "><p id="p63041770381"><a name="p63041770381"></a><a name="p63041770381"></a>static const std::string WEARABLE</p>
</td>
<td class="cellrowborder" valign="top" width="42.61%" headers="mcps1.2.3.1.2 "><p id="p18219143493618"><a name="p18219143493618"></a><a name="p18219143493618"></a>穿戴业务子系统</p>
</td>
</tr>
<tr id="row845612549416"><td class="cellrowborder" valign="top" width="57.38999999999999%" headers="mcps1.2.3.1.1 "><p id="p13457155424112"><a name="p13457155424112"></a><a name="p13457155424112"></a>static const std::string OTHERS</p>
</td>
<td class="cellrowborder" valign="top" width="42.61%" headers="mcps1.2.3.1.2 "><p id="p44573548414"><a name="p44573548414"></a><a name="p44573548414"></a>其它</p>
</td>
</tr>
</tbody>
</table>

**表 3**  HiSysEvent::EventType接口介绍

<a name="table0944173117434"></a>
<table><thead align="left"><tr id="row694473134311"><th class="cellrowborder" valign="top" width="57.38999999999999%" id="mcps1.2.3.1.1"><p id="p394413113439"><a name="p394413113439"></a><a name="p394413113439"></a>接口名</p>
</th>
<th class="cellrowborder" valign="top" width="42.61%" id="mcps1.2.3.1.2"><p id="p199441431154317"><a name="p199441431154317"></a><a name="p199441431154317"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row1894416312438"><td class="cellrowborder" valign="top" width="57.38999999999999%" headers="mcps1.2.3.1.1 "><p id="p2094483154311"><a name="p2094483154311"></a><a name="p2094483154311"></a>FAULT</p>
</td>
<td class="cellrowborder" valign="top" width="42.61%" headers="mcps1.2.3.1.2 "><p id="p5944153124316"><a name="p5944153124316"></a><a name="p5944153124316"></a>故障类型事件</p>
</td>
</tr>
<tr id="row2944193134318"><td class="cellrowborder" valign="top" width="57.38999999999999%" headers="mcps1.2.3.1.1 "><p id="p494443144312"><a name="p494443144312"></a><a name="p494443144312"></a>STATISTIC</p>
</td>
<td class="cellrowborder" valign="top" width="42.61%" headers="mcps1.2.3.1.2 "><p id="p1494423111435"><a name="p1494423111435"></a><a name="p1494423111435"></a>统计类型事件</p>
</td>
</tr>
<tr id="row094463144311"><td class="cellrowborder" valign="top" width="57.38999999999999%" headers="mcps1.2.3.1.1 "><p id="p594443184315"><a name="p594443184315"></a><a name="p594443184315"></a>SECURITY</p>
</td>
<td class="cellrowborder" valign="top" width="42.61%" headers="mcps1.2.3.1.2 "><p id="p1194417316435"><a name="p1194417316435"></a><a name="p1194417316435"></a>安全类型事件</p>
</td>
</tr>
<tr id="row1294403119434"><td class="cellrowborder" valign="top" width="57.38999999999999%" headers="mcps1.2.3.1.1 "><p id="p17944431164319"><a name="p17944431164319"></a><a name="p17944431164319"></a>BEHAVIOR</p>
</td>
<td class="cellrowborder" valign="top" width="42.61%" headers="mcps1.2.3.1.2 "><p id="p5945203184318"><a name="p5945203184318"></a><a name="p5945203184318"></a>系统行为事件</p>
</td>
</tr>
</tbody>
</table>

### 开发实例<a name="section112771171317"></a>

C++接口实例

1.  源代码开发

    在类定义头文件或者类实现源文件中，包含HiSysEvent头文件：

    ```
    #include "hisysevent.h"
    ```

    假设在业务关注应用启动时间start\_app，在业务类实现相关源文件中使用（调用接口打点）：

    ```
    HiSysEvent::Write(HiSysEvent::Domain::AAFWK, "start_app", HiSysEvent::EventType::FAULT, "app_name", "com.demo");
    ```

2.  编译设置，在BUILD.gn里增加子系统SDK依赖：

    ```
    external_deps = [ "hisysevent_native:libhisysevent" ]
    ```
