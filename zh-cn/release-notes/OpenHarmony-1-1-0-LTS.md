# OpenHarmony 1.1.0 LTS（2021-04-01）<a name="ZH-CN_TOPIC_0000001095652840"></a>

-   [版本概述](#section1846294912228)
-   [源码获取](#section84808293211)
    -   [通过镜像站点获取](#section8394142222113)
    -   [通过repo下载](#section7180193542317)

-   [更新说明](#section175225345334)
-   [已修复缺陷列表](#section11935243172612)

## 版本概述<a name="section1846294912228"></a>

首次发布LTS（long-term support）长期支持版本OpenHarmony 1.1.0，本版本在1.0版本的基础上新增了部分功能和修复了部分缺陷。

-   OpenHarmony1.1.0扩充组件能力，新增AI子系统、电源管理子系统、泛Sensor子系统、升级子系统。
-   OpenHarmony1.1.0有了统一AI引擎框架。
-   liteos-m内核完成三方可移植性重构。
-   驱动子系统完善了WIFI、Sensor、Input、Display的驱动模型。
-   图形子系统针对UI能力及JS框架性能和内存得到优化。
-   对目录结构及组件仓做了大幅优化。

## 源码获取<a name="section84808293211"></a>

### 通过镜像站点获取<a name="section8394142222113"></a>

**表 1**  源码获取路径

<a name="table14394152217216"></a>
<table><thead align="left"><tr id="row15394132214217"><th class="cellrowborder" valign="top" width="25%" id="mcps1.2.5.1.1"><p id="p15394122214219"><a name="p15394122214219"></a><a name="p15394122214219"></a>版本源码</p>
</th>
<th class="cellrowborder" valign="top" width="25%" id="mcps1.2.5.1.2"><p id="p10394112292119"><a name="p10394112292119"></a><a name="p10394112292119"></a>版本信息</p>
</th>
<th class="cellrowborder" valign="top" width="25%" id="mcps1.2.5.1.3"><p id="p039562213211"><a name="p039562213211"></a><a name="p039562213211"></a>下载站点</p>
</th>
<th class="cellrowborder" valign="top" width="25%" id="mcps1.2.5.1.4"><p id="p1039572272110"><a name="p1039572272110"></a><a name="p1039572272110"></a>SHA256校验码</p>
</th>
</tr>
</thead>
<tbody><tr id="row9395722182111"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 "><p id="p039514225215"><a name="p039514225215"></a><a name="p039514225215"></a>全量代码</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 "><p id="p839514220217"><a name="p839514220217"></a><a name="p839514220217"></a>1.1.0</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="p339552222120"><a name="p339552222120"></a><a name="p339552222120"></a><a href="https://repo.huaweicloud.com/harmonyos/os/1.1.0/code-1.1.0.tar.gz" target="_blank" rel="noopener noreferrer">站点</a></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.4 "><p id="p19395142202117"><a name="p19395142202117"></a><a name="p19395142202117"></a><a href="https://repo.huaweicloud.com/harmonyos/os/1.1.0/code-1.1.0.tar.gz.sha256" target="_blank" rel="noopener noreferrer">SHA256 校验码</a></p>
</td>
</tr>
<tr id="row1739512225217"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 "><p id="p1839592272117"><a name="p1839592272117"></a><a name="p1839592272117"></a>Hi3861解决方案（二进制）</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 "><p id="p7395722112113"><a name="p7395722112113"></a><a name="p7395722112113"></a>1.1.0</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="p53957224215"><a name="p53957224215"></a><a name="p53957224215"></a><a href="https://repo.huaweicloud.com/harmonyos/os/1.1.0/wifiiot-1.1.0.tar.gz" target="_blank" rel="noopener noreferrer">站点</a></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.4 "><p id="p183959226211"><a name="p183959226211"></a><a name="p183959226211"></a><a href="https://repo.huaweicloud.com/harmonyos/os/1.1.0/wifiiot-1.1.0.tar.gz.sha256" target="_blank" rel="noopener noreferrer">SHA256 校验码</a></p>
</td>
</tr>
<tr id="row16395122262110"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 "><p id="p12395172242118"><a name="p12395172242118"></a><a name="p12395172242118"></a>Hi3518解决方案（二进制）</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 "><p id="p12395182210215"><a name="p12395182210215"></a><a name="p12395182210215"></a>1.1.0</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="p133952022162113"><a name="p133952022162113"></a><a name="p133952022162113"></a><a href="https://repo.huaweicloud.com/harmonyos/os/1.1.0/ipcamera_hi3518ev300-1.1.0.tar.gz" target="_blank" rel="noopener noreferrer">站点</a></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.4 "><p id="p2039542211214"><a name="p2039542211214"></a><a name="p2039542211214"></a><a href="https://repo.huaweicloud.com/harmonyos/os/1.1.0/ipcamera_hi3518ev300-1.1.0.tar.gz.sha256" target="_blank" rel="noopener noreferrer">SHA256 校验码</a></p>
</td>
</tr>
<tr id="row1839592272117"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 "><p id="p8395322182113"><a name="p8395322182113"></a><a name="p8395322182113"></a>Hi3516解决方案（二进制）</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 "><p id="p20395152262114"><a name="p20395152262114"></a><a name="p20395152262114"></a>1.1.0</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="p1639552272118"><a name="p1639552272118"></a><a name="p1639552272118"></a><a href="https://repo.huaweicloud.com/harmonyos/os/1.1.0/ipcamera_hi3516dv300-1.1.0.tar.gz" target="_blank" rel="noopener noreferrer">站点</a></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.4 "><p id="p12396132216212"><a name="p12396132216212"></a><a name="p12396132216212"></a><a href="https://repo.huaweicloud.com/harmonyos/os/1.1.0/ipcamera_hi3516dv300-1.1.0.tar.gz.sha256" target="_blank" rel="noopener noreferrer">SHA256 校验码</a></p>
</td>
</tr>
<tr id="row3396822162120"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 "><p id="p18506191313914"><a name="p18506191313914"></a><a name="p18506191313914"></a>Release Notes</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 "><p id="p10396102282110"><a name="p10396102282110"></a><a name="p10396102282110"></a>1.1.0</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="p15396192232119"><a name="p15396192232119"></a><a name="p15396192232119"></a><a href="https://repo.huaweicloud.com/harmonyos/os/1.1.0/OpenHarmony_Release_Notes_zh_cn.zip" target="_blank" rel="noopener noreferrer">站点</a></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.4 "><p id="p039662242117"><a name="p039662242117"></a><a name="p039662242117"></a>-</p>
</td>
</tr>
</tbody>
</table>

### 通过repo下载<a name="section7180193542317"></a>

下载命令如下：

```
repo init -u https://gitee.com/openharmony/manifest.git -b refs/tags/OpenHarmony_release_v1.1.0 --no-repo-verify
repo sync -c
```

## 更新说明<a name="section175225345334"></a>

本版本完全继承了OpenHarmony 1.0的所有特性，并在OpenHarmony 1.0版本的基础上，对各模块进行了功能扩展和优化，详情请参考下表 。

**表 2**  特性更新说明

<a name="table143385853320"></a>
<table><thead align="left"><tr id="row53375863312"><th class="cellrowborder" valign="top" width="13.38%" id="mcps1.2.5.1.1"><p id="p20331858193317"><a name="p20331858193317"></a><a name="p20331858193317"></a>类别</p>
</th>
<th class="cellrowborder" valign="top" width="38.54%" id="mcps1.2.5.1.2"><p id="p1133115820331"><a name="p1133115820331"></a><a name="p1133115820331"></a>新增特性</p>
</th>
<th class="cellrowborder" valign="top" width="28.410000000000004%" id="mcps1.2.5.1.3"><p id="p162468531345"><a name="p162468531345"></a><a name="p162468531345"></a>修改特性</p>
</th>
<th class="cellrowborder" valign="top" width="19.67%" id="mcps1.2.5.1.4"><p id="p9985141863716"><a name="p9985141863716"></a><a name="p9985141863716"></a>删除特性</p>
</th>
</tr>
</thead>
<tbody><tr id="row333115812331"><td class="cellrowborder" valign="top" width="13.38%" headers="mcps1.2.5.1.1 "><p id="p31751943143520"><a name="p31751943143520"></a><a name="p31751943143520"></a>内核</p>
</td>
<td class="cellrowborder" valign="top" width="38.54%" headers="mcps1.2.5.1.2 "><a name="ul4760125719351"></a><a name="ul4760125719351"></a><ul id="ul4760125719351"><li>LiteOS-M支持Cortex-M7、Cortex-M33和RISC-V芯片架构，新增对应的单板target样例。</li><li>LiteOS-M支持MPU功能。</li><li>LiteOS-M支持部分POSIX接口。</li><li>LiteOS-M支持FatFS文件系统。</li><li>LiteOS-M支持异常回调函数注册机制。</li><li>LiteOS-M三方芯片易适配性架构调整。</li><li>LiteOS-M、LiteOS-A支持堆内存调测功能，包括内存泄漏、踩内存、内存统计。</li><li>LiteOS-M、LiteOS-A支持TLSF堆内存算法，提高内存申请和释放效率，降低碎片率。</li></ul>
</td>
<td class="cellrowborder" valign="top" width="28.410000000000004%" headers="mcps1.2.5.1.3 "><p id="p207894916364"><a name="p207894916364"></a><a name="p207894916364"></a>LiteOS-A调度优化。</p>
</td>
<td class="cellrowborder" valign="top" width="19.67%" headers="mcps1.2.5.1.4 "><p id="p2098521893713"><a name="p2098521893713"></a><a name="p2098521893713"></a>None</p>
</td>
</tr>
<tr id="row173335873311"><td class="cellrowborder" valign="top" width="13.38%" headers="mcps1.2.5.1.1 "><p id="p8294101513612"><a name="p8294101513612"></a><a name="p8294101513612"></a>泛Sensor</p>
</td>
<td class="cellrowborder" valign="top" width="38.54%" headers="mcps1.2.5.1.2 "><p id="p29882273369"><a name="p29882273369"></a><a name="p29882273369"></a>新增Sensor组件，提供了Sensor列表查询、Sensor启停、Sensor订阅/去订阅、设置数据上报模式、设置采样间隔等功能。</p>
</td>
<td class="cellrowborder" valign="top" width="28.410000000000004%" headers="mcps1.2.5.1.3 "><p id="p175171027115517"><a name="p175171027115517"></a><a name="p175171027115517"></a>None</p>
</td>
<td class="cellrowborder" valign="top" width="19.67%" headers="mcps1.2.5.1.4 "><p id="p555482725510"><a name="p555482725510"></a><a name="p555482725510"></a>None</p>
</td>
</tr>
<tr id="row15331058133314"><td class="cellrowborder" valign="top" width="13.38%" headers="mcps1.2.5.1.1 "><p id="p135282348360"><a name="p135282348360"></a><a name="p135282348360"></a>全球化</p>
</td>
<td class="cellrowborder" valign="top" width="38.54%" headers="mcps1.2.5.1.2 "><p id="p127721442123615"><a name="p127721442123615"></a><a name="p127721442123615"></a>新增79种语言的数字格式化、日期和时间格式化、单复数C/C++国际化接口。</p>
</td>
<td class="cellrowborder" valign="top" width="28.410000000000004%" headers="mcps1.2.5.1.3 "><p id="p5589227195515"><a name="p5589227195515"></a><a name="p5589227195515"></a>None</p>
</td>
<td class="cellrowborder" valign="top" width="19.67%" headers="mcps1.2.5.1.4 "><p id="p156111127125519"><a name="p156111127125519"></a><a name="p156111127125519"></a>None</p>
</td>
</tr>
<tr id="row1034145820330"><td class="cellrowborder" valign="top" width="13.38%" headers="mcps1.2.5.1.1 "><p id="p194507512361"><a name="p194507512361"></a><a name="p194507512361"></a>JS应用开发框架</p>
</td>
<td class="cellrowborder" valign="top" width="38.54%" headers="mcps1.2.5.1.2 "><a name="ul156745563613"></a><a name="ul156745563613"></a><ul id="ul156745563613"><li>新增JS前端opacity全局属性支持。</li><li>新增prompt.showDialog API。</li><li>新增二维码组件qrcode。</li><li>新增事件冒泡机制</li></ul>
</td>
<td class="cellrowborder" valign="top" width="28.410000000000004%" headers="mcps1.2.5.1.3 "><a name="ul1521675183713"></a><a name="ul1521675183713"></a><ul id="ul1521675183713"><li>国际化性能优化，加速页面跳转，支持数字国际化及时间日期转换。</li><li>前端布局能力增强，部分样式值支持设置百分比。</li><li>input及switch组件尺寸自适应能力增强。</li><li>image组件能力增强，支持显示应用私有数据目录图片。</li><li>image-animator组件能力增强，支持结束帧指定。</li><li>canvas组件能力增强，新增部分API。</li><li>device.getInfo API增强，新增部分返回字段。</li><li>DFX能力增强，支持跟踪异常的方法栈。</li></ul>
</td>
<td class="cellrowborder" valign="top" width="19.67%" headers="mcps1.2.5.1.4 "><p id="p86015315379"><a name="p86015315379"></a><a name="p86015315379"></a>国际化功能不再支持回溯特性。</p>
</td>
</tr>
<tr id="row334175803317"><td class="cellrowborder" valign="top" width="13.38%" headers="mcps1.2.5.1.1 "><p id="p243416212389"><a name="p243416212389"></a><a name="p243416212389"></a>测试</p>
</td>
<td class="cellrowborder" valign="top" width="38.54%" headers="mcps1.2.5.1.2 "><a name="ul46498614381"></a><a name="ul46498614381"></a><ul id="ul46498614381"><li>新增测试工具按照用例级别筛选要执行的测试用例。</li><li>新增测试demo用例。</li></ul>
</td>
<td class="cellrowborder" valign="top" width="28.410000000000004%" headers="mcps1.2.5.1.3 "><p id="p18996183216557"><a name="p18996183216557"></a><a name="p18996183216557"></a>None</p>
</td>
<td class="cellrowborder" valign="top" width="19.67%" headers="mcps1.2.5.1.4 "><p id="p153093375512"><a name="p153093375512"></a><a name="p153093375512"></a>None</p>
</td>
</tr>
<tr id="row834358143319"><td class="cellrowborder" valign="top" width="13.38%" headers="mcps1.2.5.1.1 "><p id="p104871716123812"><a name="p104871716123812"></a><a name="p104871716123812"></a>图形</p>
</td>
<td class="cellrowborder" valign="top" width="38.54%" headers="mcps1.2.5.1.2 "><a name="ul164401121203816"></a><a name="ul164401121203816"></a><ul id="ul164401121203816"><li>新增组件级旋转缩放、组件级透明度。</li><li>新增事件冒泡机制，新增旋转表冠事件。</li><li>新增GIF图片解析显示，新增百分比宽高布局，新增Video和二维码控件。</li></ul>
</td>
<td class="cellrowborder" valign="top" width="28.410000000000004%" headers="mcps1.2.5.1.3 "><p id="p5908129143819"><a name="p5908129143819"></a><a name="p5908129143819"></a>局部渲染和SIMD性能优化。</p>
</td>
<td class="cellrowborder" valign="top" width="19.67%" headers="mcps1.2.5.1.4 "><p id="p29561057105519"><a name="p29561057105519"></a><a name="p29561057105519"></a>None</p>
</td>
</tr>
<tr id="row2216639113811"><td class="cellrowborder" valign="top" width="13.38%" headers="mcps1.2.5.1.1 "><p id="p11452451173813"><a name="p11452451173813"></a><a name="p11452451173813"></a>公共基础</p>
</td>
<td class="cellrowborder" valign="top" width="38.54%" headers="mcps1.2.5.1.2 "><a name="ul139511255113815"></a><a name="ul139511255113815"></a><ul id="ul139511255113815"><li>新增dump系统属性功能。</li><li>为上层各模块新增内存池管理接口。</li></ul>
</td>
<td class="cellrowborder" valign="top" width="28.410000000000004%" headers="mcps1.2.5.1.3 "><p id="p1770461785620"><a name="p1770461785620"></a><a name="p1770461785620"></a>None</p>
</td>
<td class="cellrowborder" valign="top" width="19.67%" headers="mcps1.2.5.1.4 "><p id="p998117571553"><a name="p998117571553"></a><a name="p998117571553"></a>None</p>
</td>
</tr>
<tr id="row119944512385"><td class="cellrowborder" valign="top" width="13.38%" headers="mcps1.2.5.1.1 "><p id="p20115719395"><a name="p20115719395"></a><a name="p20115719395"></a>驱动</p>
</td>
<td class="cellrowborder" valign="top" width="38.54%" headers="mcps1.2.5.1.2 "><a name="ul100191223919"></a><a name="ul100191223919"></a><ul id="ul100191223919"><li>新增sensor、input、display驱动模型。</li><li>新增mipi dsi以及pwm（脉冲宽度调制）。</li><li>新增WIFI HDI接口以及WIFI的流控。</li><li>新增驱动框架IO服务分组特性。</li></ul>
</td>
<td class="cellrowborder" valign="top" width="28.410000000000004%" headers="mcps1.2.5.1.3 "><p id="p460532073911"><a name="p460532073911"></a><a name="p460532073911"></a>优化驱动加载流程，支持分段加载。</p>
</td>
<td class="cellrowborder" valign="top" width="19.67%" headers="mcps1.2.5.1.4 "><p id="p7319581551"><a name="p7319581551"></a><a name="p7319581551"></a>None</p>
</td>
</tr>
<tr id="row18711154213388"><td class="cellrowborder" valign="top" width="13.38%" headers="mcps1.2.5.1.1 "><p id="p185909284392"><a name="p185909284392"></a><a name="p185909284392"></a>分布式通信</p>
</td>
<td class="cellrowborder" valign="top" width="38.54%" headers="mcps1.2.5.1.2 "><a name="ul126884329393"></a><a name="ul126884329393"></a><ul id="ul126884329393"><li>新增WiFi Aware特性模块。</li><li>IPC新增对非对齐序列化的支持。</li></ul>
</td>
<td class="cellrowborder" valign="top" width="28.410000000000004%" headers="mcps1.2.5.1.3 "><p id="p114241375617"><a name="p114241375617"></a><a name="p114241375617"></a>None</p>
</td>
<td class="cellrowborder" valign="top" width="19.67%" headers="mcps1.2.5.1.4 "><p id="p6261458185513"><a name="p6261458185513"></a><a name="p6261458185513"></a>None</p>
</td>
</tr>
<tr id="row933514718399"><td class="cellrowborder" valign="top" width="13.38%" headers="mcps1.2.5.1.1 "><p id="p15353948123912"><a name="p15353948123912"></a><a name="p15353948123912"></a>安全</p>
</td>
<td class="cellrowborder" valign="top" width="38.54%" headers="mcps1.2.5.1.2 "><a name="ul16110105811391"></a><a name="ul16110105811391"></a><ul id="ul16110105811391"><li>新增HUKS提供SHA256/RSA3072/RSA2048/AES128/ECC安全算法以及接口，以及提供密钥管理和存储能力。</li><li>HiChain提供轻量非账号的轻量级组件，用于设备群组管理和认证，支撑软总线通讯安全；提供API给系统服务与应用。</li><li>权限管理新增统一的权限管理机制，满足轻量设备权限授权需求。</li></ul>
</td>
<td class="cellrowborder" valign="top" width="28.410000000000004%" headers="mcps1.2.5.1.3 "><p id="p10854883569"><a name="p10854883569"></a><a name="p10854883569"></a>None</p>
</td>
<td class="cellrowborder" valign="top" width="19.67%" headers="mcps1.2.5.1.4 "><p id="p848858175517"><a name="p848858175517"></a><a name="p848858175517"></a>None</p>
</td>
</tr>
<tr id="row1413119125400"><td class="cellrowborder" valign="top" width="13.38%" headers="mcps1.2.5.1.1 "><p id="p57091617134017"><a name="p57091617134017"></a><a name="p57091617134017"></a>AI子系统</p>
</td>
<td class="cellrowborder" valign="top" width="38.54%" headers="mcps1.2.5.1.2 "><a name="ul327962215408"></a><a name="ul327962215408"></a><ul id="ul327962215408"><li>新增统一的AI引擎框架，实现算法能力快速插件化集成。框架中主要包含插件管理、模块管理和通信管理等模块，对AI算法能力进行生命周期管理和按需部署</li><li>为开发者提供开发指南，并提供2个基于AI引擎框架开发的AI能力插件和对应的AI应用Sample，方便开发者在AI引擎框架中快速集成AI算法能力。</li></ul>
</td>
<td class="cellrowborder" valign="top" width="28.410000000000004%" headers="mcps1.2.5.1.3 "><p id="p7131191264012"><a name="p7131191264012"></a><a name="p7131191264012"></a>None</p>
</td>
<td class="cellrowborder" valign="top" width="19.67%" headers="mcps1.2.5.1.4 "><p id="p1170145845518"><a name="p1170145845518"></a><a name="p1170145845518"></a>None</p>
</td>
</tr>
<tr id="row98001376403"><td class="cellrowborder" valign="top" width="13.38%" headers="mcps1.2.5.1.1 "><p id="p16588112824019"><a name="p16588112824019"></a><a name="p16588112824019"></a>升级服务</p>
</td>
<td class="cellrowborder" valign="top" width="38.54%" headers="mcps1.2.5.1.2 "><p id="p163773464015"><a name="p163773464015"></a><a name="p163773464015"></a>新增轻量级设备升级能力框架，框架包括升级包的效验和解析能力，以及安装的接口，统一轻设备升级能力框架。</p>
</td>
<td class="cellrowborder" valign="top" width="28.410000000000004%" headers="mcps1.2.5.1.3 "><p id="p1080010712403"><a name="p1080010712403"></a><a name="p1080010712403"></a>None</p>
</td>
<td class="cellrowborder" valign="top" width="19.67%" headers="mcps1.2.5.1.4 "><p id="p119211587555"><a name="p119211587555"></a><a name="p119211587555"></a>None</p>
</td>
</tr>
<tr id="row3104039184016"><td class="cellrowborder" valign="top" width="13.38%" headers="mcps1.2.5.1.1 "><p id="p12573854134019"><a name="p12573854134019"></a><a name="p12573854134019"></a>XTS认证</p>
</td>
<td class="cellrowborder" valign="top" width="38.54%" headers="mcps1.2.5.1.2 "><p id="p15893189204113"><a name="p15893189204113"></a><a name="p15893189204113"></a>增加AI、DFX、global、OTA兼容性测试用例。</p>
</td>
<td class="cellrowborder" valign="top" width="28.410000000000004%" headers="mcps1.2.5.1.3 "><p id="p1170111714112"><a name="p1170111714112"></a><a name="p1170111714112"></a>应用程序框架、公共通信、分布式任务调度、IOT、内核等测试能力增强。</p>
</td>
<td class="cellrowborder" valign="top" width="19.67%" headers="mcps1.2.5.1.4 "><p id="p3114115820554"><a name="p3114115820554"></a><a name="p3114115820554"></a>None</p>
</td>
</tr>
<tr id="row95402484401"><td class="cellrowborder" valign="top" width="13.38%" headers="mcps1.2.5.1.1 "><p id="p1031291510411"><a name="p1031291510411"></a><a name="p1031291510411"></a>编译构建</p>
</td>
<td class="cellrowborder" valign="top" width="38.54%" headers="mcps1.2.5.1.2 "><a name="ul061324164112"></a><a name="ul061324164112"></a><ul id="ul061324164112"><li>新增命令行工具hb, 采用hb set和hb build方式构建，并支持在源码目录下及任意子目录下构建。</li><li>支持独立芯片厂商组件。</li><li>支持使用组件名单独构建组件。</li><li>支持按开发板自定义编译工具链和编译选项。</li></ul>
</td>
<td class="cellrowborder" valign="top" width="28.410000000000004%" headers="mcps1.2.5.1.3 "><p id="p1167916358411"><a name="p1167916358411"></a><a name="p1167916358411"></a>产品配置与build_lite仓解耦，修改为“vendor/解决方案厂商/产品/config.json”。</p>
</td>
<td class="cellrowborder" valign="top" width="19.67%" headers="mcps1.2.5.1.4 "><p id="p16136758125519"><a name="p16136758125519"></a><a name="p16136758125519"></a>None</p>
</td>
</tr>
<tr id="row16281465401"><td class="cellrowborder" valign="top" width="13.38%" headers="mcps1.2.5.1.1 "><p id="p0889841174116"><a name="p0889841174116"></a><a name="p0889841174116"></a>电源管理</p>
</td>
<td class="cellrowborder" valign="top" width="38.54%" headers="mcps1.2.5.1.2 "><a name="ul175961462411"></a><a name="ul175961462411"></a><ul id="ul175961462411"><li>电量查询功能。</li><li>亮屏锁管理功能及接口。</li></ul>
</td>
<td class="cellrowborder" valign="top" width="28.410000000000004%" headers="mcps1.2.5.1.3 "><p id="p3628746194013"><a name="p3628746194013"></a><a name="p3628746194013"></a>None</p>
</td>
<td class="cellrowborder" valign="top" width="19.67%" headers="mcps1.2.5.1.4 "><p id="p3158165885517"><a name="p3158165885517"></a><a name="p3158165885517"></a>None</p>
</td>
</tr>
</tbody>
</table>

组件仓优化如下表所示。

> **说明：** 
>-   只读归档：组件仓归档到新的组织并设置为只读（openharmony-retired）。
>-   三方芯片代码与OS解耦，海思芯片SDK由Vendor目录迁移到device/hisilicon。

**表 3**  组建仓库优化

<a name="table91984129177"></a>
<table><thead align="left"><tr id="row51981312101713"><th class="cellrowborder" valign="top" width="33.64%" id="mcps1.2.4.1.1"><p id="p194252040214"><a name="p194252040214"></a><a name="p194252040214"></a>OpenHarmony1.0</p>
</th>
<th class="cellrowborder" valign="top" width="37.059999999999995%" id="mcps1.2.4.1.2"><p id="p242515412216"><a name="p242515412216"></a><a name="p242515412216"></a>OpenHarmony1.1.0</p>
</th>
<th class="cellrowborder" valign="top" width="29.299999999999997%" id="mcps1.2.4.1.3"><p id="p5425144729"><a name="p5425144729"></a><a name="p5425144729"></a>优化方式</p>
</th>
</tr>
</thead>
<tbody><tr id="row21528111414"><td class="cellrowborder" valign="top" width="33.64%" headers="mcps1.2.4.1.1 "><p id="p14614112117"><a name="p14614112117"></a><a name="p14614112117"></a>ace_lite_jsfwk</p>
</td>
<td class="cellrowborder" valign="top" width="37.059999999999995%" headers="mcps1.2.4.1.2 "><p id="p8619114115"><a name="p8619114115"></a><a name="p8619114115"></a>ace_engine_lite</p>
</td>
<td class="cellrowborder" valign="top" width="29.299999999999997%" headers="mcps1.2.4.1.3 "><p id="p1661811711"><a name="p1661811711"></a><a name="p1661811711"></a>仓名变更</p>
</td>
</tr>
<tr id="row1152121117112"><td class="cellrowborder" valign="top" width="33.64%" headers="mcps1.2.4.1.1 "><p id="p57121115112"><a name="p57121115112"></a><a name="p57121115112"></a>ace_interfaces_innerkits_builtin</p>
</td>
<td class="cellrowborder" valign="top" width="37.059999999999995%" headers="mcps1.2.4.1.2 "><p id="p1771119118"><a name="p1771119118"></a><a name="p1771119118"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="29.299999999999997%" headers="mcps1.2.4.1.3 "><p id="p127161115114"><a name="p127161115114"></a><a name="p127161115114"></a>只读归档</p>
</td>
</tr>
<tr id="row191521611211"><td class="cellrowborder" valign="top" width="33.64%" headers="mcps1.2.4.1.1 "><p id="p12711117113"><a name="p12711117113"></a><a name="p12711117113"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="37.059999999999995%" headers="mcps1.2.4.1.2 "><p id="p9711112118"><a name="p9711112118"></a><a name="p9711112118"></a>ai_engine</p>
</td>
<td class="cellrowborder" valign="top" width="29.299999999999997%" headers="mcps1.2.4.1.3 "><p id="p15714118113"><a name="p15714118113"></a><a name="p15714118113"></a>新增组件</p>
</td>
</tr>
<tr id="row20151011611"><td class="cellrowborder" valign="top" width="33.64%" headers="mcps1.2.4.1.1 "><p id="p2715118118"><a name="p2715118118"></a><a name="p2715118118"></a>hiviewdfx_frameworks_hievent_lite</p>
</td>
<td class="cellrowborder" valign="top" width="37.059999999999995%" headers="mcps1.2.4.1.2 "><p id="p1751117113"><a name="p1751117113"></a><a name="p1751117113"></a>hiviewdfx_hievent_lite</p>
</td>
<td class="cellrowborder" valign="top" width="29.299999999999997%" headers="mcps1.2.4.1.3 "><p id="p2710111617"><a name="p2710111617"></a><a name="p2710111617"></a>仓名变更</p>
</td>
</tr>
<tr id="row61511511213"><td class="cellrowborder" valign="top" width="33.64%" headers="mcps1.2.4.1.1 "><p id="p1276111112"><a name="p1276111112"></a><a name="p1276111112"></a>hiviewdfx_frameworks_hilog_lite</p>
</td>
<td class="cellrowborder" valign="top" width="37.059999999999995%" headers="mcps1.2.4.1.2 "><p id="p37191115116"><a name="p37191115116"></a><a name="p37191115116"></a>hiviewdfx_hilog_lite</p>
</td>
<td class="cellrowborder" valign="top" width="29.299999999999997%" headers="mcps1.2.4.1.3 "><p id="p19711111311"><a name="p19711111311"></a><a name="p19711111311"></a>仓名变更</p>
</td>
</tr>
<tr id="row111511011014"><td class="cellrowborder" valign="top" width="33.64%" headers="mcps1.2.4.1.1 "><p id="p9713112114"><a name="p9713112114"></a><a name="p9713112114"></a>hiviewdfx_utils_lite</p>
</td>
<td class="cellrowborder" valign="top" width="37.059999999999995%" headers="mcps1.2.4.1.2 "><p id="p14718119112"><a name="p14718119112"></a><a name="p14718119112"></a>hiviewdfx_hiview_lite</p>
</td>
<td class="cellrowborder" valign="top" width="29.299999999999997%" headers="mcps1.2.4.1.3 "><p id="p579111716"><a name="p579111716"></a><a name="p579111716"></a>仓名变更</p>
</td>
</tr>
<tr id="row101511711311"><td class="cellrowborder" valign="top" width="33.64%" headers="mcps1.2.4.1.1 "><p id="p187711715"><a name="p187711715"></a><a name="p187711715"></a>hiviewdfx_frameworks_ddrdump_lite</p>
</td>
<td class="cellrowborder" valign="top" width="37.059999999999995%" headers="mcps1.2.4.1.2 "><p id="p1173111319"><a name="p1173111319"></a><a name="p1173111319"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="29.299999999999997%" headers="mcps1.2.4.1.3 "><p id="p18741118112"><a name="p18741118112"></a><a name="p18741118112"></a>只读归档</p>
</td>
</tr>
<tr id="row111517117112"><td class="cellrowborder" valign="top" width="33.64%" headers="mcps1.2.4.1.1 "><p id="p1385115116"><a name="p1385115116"></a><a name="p1385115116"></a>hiviewdfx_interfaces_innerkits_hievent_lite</p>
</td>
<td class="cellrowborder" valign="top" width="37.059999999999995%" headers="mcps1.2.4.1.2 "><p id="p1881111212"><a name="p1881111212"></a><a name="p1881111212"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="29.299999999999997%" headers="mcps1.2.4.1.3 "><p id="p1987112018"><a name="p1987112018"></a><a name="p1987112018"></a>只读归档</p>
</td>
</tr>
<tr id="row015131111115"><td class="cellrowborder" valign="top" width="33.64%" headers="mcps1.2.4.1.1 "><p id="p128121116110"><a name="p128121116110"></a><a name="p128121116110"></a>hiviewdfx_interfaces_innerkits_hilog</p>
</td>
<td class="cellrowborder" valign="top" width="37.059999999999995%" headers="mcps1.2.4.1.2 "><p id="p17817111017"><a name="p17817111017"></a><a name="p17817111017"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="29.299999999999997%" headers="mcps1.2.4.1.3 "><p id="p12819111216"><a name="p12819111216"></a><a name="p12819111216"></a>只读归档</p>
</td>
</tr>
<tr id="row215161113114"><td class="cellrowborder" valign="top" width="33.64%" headers="mcps1.2.4.1.1 "><p id="p1981611219"><a name="p1981611219"></a><a name="p1981611219"></a>hiviewdfx_interfaces_kits_hilog</p>
</td>
<td class="cellrowborder" valign="top" width="37.059999999999995%" headers="mcps1.2.4.1.2 "><p id="p198121115114"><a name="p198121115114"></a><a name="p198121115114"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="29.299999999999997%" headers="mcps1.2.4.1.3 "><p id="p20812111817"><a name="p20812111817"></a><a name="p20812111817"></a>只读归档</p>
</td>
</tr>
<tr id="row41513111818"><td class="cellrowborder" valign="top" width="33.64%" headers="mcps1.2.4.1.1 "><p id="p58111119112"><a name="p58111119112"></a><a name="p58111119112"></a>hiviewdfx_interfaces_kits_hilog_lite</p>
</td>
<td class="cellrowborder" valign="top" width="37.059999999999995%" headers="mcps1.2.4.1.2 "><p id="p9812111313"><a name="p9812111313"></a><a name="p9812111313"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="29.299999999999997%" headers="mcps1.2.4.1.3 "><p id="p281211415"><a name="p281211415"></a><a name="p281211415"></a>只读归档</p>
</td>
</tr>
<tr id="row71516112112"><td class="cellrowborder" valign="top" width="33.64%" headers="mcps1.2.4.1.1 "><p id="p287112011"><a name="p287112011"></a><a name="p287112011"></a>hiviewdfx_services_hilogcat_lite</p>
</td>
<td class="cellrowborder" valign="top" width="37.059999999999995%" headers="mcps1.2.4.1.2 "><p id="p14813119111"><a name="p14813119111"></a><a name="p14813119111"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="29.299999999999997%" headers="mcps1.2.4.1.3 "><p id="p2817111113"><a name="p2817111113"></a><a name="p2817111113"></a>只读归档</p>
</td>
</tr>
<tr id="row12151611714"><td class="cellrowborder" valign="top" width="33.64%" headers="mcps1.2.4.1.1 "><p id="p1786119114"><a name="p1786119114"></a><a name="p1786119114"></a>hiviewdfx_services_hiview_lite</p>
</td>
<td class="cellrowborder" valign="top" width="37.059999999999995%" headers="mcps1.2.4.1.2 "><p id="p129111112115"><a name="p129111112115"></a><a name="p129111112115"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="29.299999999999997%" headers="mcps1.2.4.1.3 "><p id="p3991111116"><a name="p3991111116"></a><a name="p3991111116"></a>只读归档</p>
</td>
</tr>
<tr id="row31517113116"><td class="cellrowborder" valign="top" width="33.64%" headers="mcps1.2.4.1.1 "><p id="p695111118"><a name="p695111118"></a><a name="p695111118"></a>iothardware_hals_wifiiot_lite</p>
</td>
<td class="cellrowborder" valign="top" width="37.059999999999995%" headers="mcps1.2.4.1.2 "><p id="p797111718"><a name="p797111718"></a><a name="p797111718"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="29.299999999999997%" headers="mcps1.2.4.1.3 "><p id="p6911119115"><a name="p6911119115"></a><a name="p6911119115"></a>只读归档</p>
</td>
</tr>
<tr id="row815112117113"><td class="cellrowborder" valign="top" width="33.64%" headers="mcps1.2.4.1.1 "><p id="p0941110120"><a name="p0941110120"></a><a name="p0941110120"></a>iothardware_interfaces_kits_wifiiot_lite</p>
</td>
<td class="cellrowborder" valign="top" width="37.059999999999995%" headers="mcps1.2.4.1.2 "><p id="p1291711016"><a name="p1291711016"></a><a name="p1291711016"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="29.299999999999997%" headers="mcps1.2.4.1.3 "><p id="p79211318"><a name="p79211318"></a><a name="p79211318"></a>只读归档</p>
</td>
</tr>
<tr id="row4151161119118"><td class="cellrowborder" valign="top" width="33.64%" headers="mcps1.2.4.1.1 "><p id="p6910115120"><a name="p6910115120"></a><a name="p6910115120"></a>iothardware_frameworks_wifiiot_lite</p>
</td>
<td class="cellrowborder" valign="top" width="37.059999999999995%" headers="mcps1.2.4.1.2 "><p id="p17961117116"><a name="p17961117116"></a><a name="p17961117116"></a>iothardware_peripheral</p>
</td>
<td class="cellrowborder" valign="top" width="29.299999999999997%" headers="mcps1.2.4.1.3 "><p id="p11912117114"><a name="p11912117114"></a><a name="p11912117114"></a>仓名变更</p>
</td>
</tr>
<tr id="row31511111415"><td class="cellrowborder" valign="top" width="33.64%" headers="mcps1.2.4.1.1 "><p id="p159411316"><a name="p159411316"></a><a name="p159411316"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="37.059999999999995%" headers="mcps1.2.4.1.2 "><p id="p09111113114"><a name="p09111113114"></a><a name="p09111113114"></a>applications_camera_sample_communication</p>
</td>
<td class="cellrowborder" valign="top" width="29.299999999999997%" headers="mcps1.2.4.1.3 "><p id="p1599111217"><a name="p1599111217"></a><a name="p1599111217"></a>新增组件</p>
</td>
</tr>
<tr id="row1015115110114"><td class="cellrowborder" valign="top" width="33.64%" headers="mcps1.2.4.1.1 "><p id="p20914113110"><a name="p20914113110"></a><a name="p20914113110"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="37.059999999999995%" headers="mcps1.2.4.1.2 "><p id="p17917119110"><a name="p17917119110"></a><a name="p17917119110"></a>applications_camera_screensaver_app</p>
</td>
<td class="cellrowborder" valign="top" width="29.299999999999997%" headers="mcps1.2.4.1.3 "><p id="p1101911618"><a name="p1101911618"></a><a name="p1101911618"></a>新增组件</p>
</td>
</tr>
<tr id="row91511211912"><td class="cellrowborder" valign="top" width="33.64%" headers="mcps1.2.4.1.1 "><p id="p151017111018"><a name="p151017111018"></a><a name="p151017111018"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="37.059999999999995%" headers="mcps1.2.4.1.2 "><p id="p1510101119117"><a name="p1510101119117"></a><a name="p1510101119117"></a>sensors_miscdevice_lite</p>
</td>
<td class="cellrowborder" valign="top" width="29.299999999999997%" headers="mcps1.2.4.1.3 "><p id="p1910101116115"><a name="p1910101116115"></a><a name="p1910101116115"></a>新增组件</p>
</td>
</tr>
<tr id="row61519111318"><td class="cellrowborder" valign="top" width="33.64%" headers="mcps1.2.4.1.1 "><p id="p1108111919"><a name="p1108111919"></a><a name="p1108111919"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="37.059999999999995%" headers="mcps1.2.4.1.2 "><p id="p1510131119115"><a name="p1510131119115"></a><a name="p1510131119115"></a>sensors_sensor_lite</p>
</td>
<td class="cellrowborder" valign="top" width="29.299999999999997%" headers="mcps1.2.4.1.3 "><p id="p4101611813"><a name="p4101611813"></a><a name="p4101611813"></a>新增组件</p>
</td>
</tr>
<tr id="row121512111715"><td class="cellrowborder" valign="top" width="33.64%" headers="mcps1.2.4.1.1 "><p id="p1010011814"><a name="p1010011814"></a><a name="p1010011814"></a>xts_tools_lite</p>
</td>
<td class="cellrowborder" valign="top" width="37.059999999999995%" headers="mcps1.2.4.1.2 "><p id="p41018111019"><a name="p41018111019"></a><a name="p41018111019"></a>xts_tools</p>
</td>
<td class="cellrowborder" valign="top" width="29.299999999999997%" headers="mcps1.2.4.1.3 "><p id="p5100111114"><a name="p5100111114"></a><a name="p5100111114"></a>仓名变更</p>
</td>
</tr>
<tr id="row61512111110"><td class="cellrowborder" valign="top" width="33.64%" headers="mcps1.2.4.1.1 "><p id="p16101113112"><a name="p16101113112"></a><a name="p16101113112"></a>security_services_iam_lite</p>
</td>
<td class="cellrowborder" valign="top" width="37.059999999999995%" headers="mcps1.2.4.1.2 "><p id="p15106119117"><a name="p15106119117"></a><a name="p15106119117"></a>security_permission</p>
</td>
<td class="cellrowborder" valign="top" width="29.299999999999997%" headers="mcps1.2.4.1.3 "><p id="p141041112120"><a name="p141041112120"></a><a name="p141041112120"></a>仓名变更</p>
</td>
</tr>
<tr id="row131518112113"><td class="cellrowborder" valign="top" width="33.64%" headers="mcps1.2.4.1.1 "><p id="p11103112120"><a name="p11103112120"></a><a name="p11103112120"></a>security_interfaces_innerkits_iam_lite</p>
</td>
<td class="cellrowborder" valign="top" width="37.059999999999995%" headers="mcps1.2.4.1.2 "><p id="p510011411"><a name="p510011411"></a><a name="p510011411"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="29.299999999999997%" headers="mcps1.2.4.1.3 "><p id="p610211215"><a name="p610211215"></a><a name="p610211215"></a>只读归档</p>
</td>
</tr>
<tr id="row101511611812"><td class="cellrowborder" valign="top" width="33.64%" headers="mcps1.2.4.1.1 "><p id="p14111911619"><a name="p14111911619"></a><a name="p14111911619"></a>security_interfaces_kits_iam_lite</p>
</td>
<td class="cellrowborder" valign="top" width="37.059999999999995%" headers="mcps1.2.4.1.2 "><p id="p91121113116"><a name="p91121113116"></a><a name="p91121113116"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="29.299999999999997%" headers="mcps1.2.4.1.3 "><p id="p131111111115"><a name="p131111111115"></a><a name="p131111111115"></a>只读归档</p>
</td>
</tr>
<tr id="row6151161119116"><td class="cellrowborder" valign="top" width="33.64%" headers="mcps1.2.4.1.1 "><p id="p10112111511"><a name="p10112111511"></a><a name="p10112111511"></a>security_services_secure_os</p>
</td>
<td class="cellrowborder" valign="top" width="37.059999999999995%" headers="mcps1.2.4.1.2 "><p id="p911181119116"><a name="p911181119116"></a><a name="p911181119116"></a>security_itrustee_ree_lite</p>
</td>
<td class="cellrowborder" valign="top" width="29.299999999999997%" headers="mcps1.2.4.1.3 "><p id="p0111111212"><a name="p0111111212"></a><a name="p0111111212"></a>仓名变更</p>
</td>
</tr>
<tr id="row7151151116115"><td class="cellrowborder" valign="top" width="33.64%" headers="mcps1.2.4.1.1 "><p id="p111118115118"><a name="p111118115118"></a><a name="p111118115118"></a>security_interfaces_innerkits_secure_os</p>
</td>
<td class="cellrowborder" valign="top" width="37.059999999999995%" headers="mcps1.2.4.1.2 "><p id="p141110111714"><a name="p141110111714"></a><a name="p141110111714"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="29.299999999999997%" headers="mcps1.2.4.1.3 "><p id="p31112111813"><a name="p31112111813"></a><a name="p31112111813"></a>只读归档</p>
</td>
</tr>
<tr id="row3151011618"><td class="cellrowborder" valign="top" width="33.64%" headers="mcps1.2.4.1.1 "><p id="p13111411519"><a name="p13111411519"></a><a name="p13111411519"></a>security_frameworks_secure_os</p>
</td>
<td class="cellrowborder" valign="top" width="37.059999999999995%" headers="mcps1.2.4.1.2 "><p id="p3111116118"><a name="p3111116118"></a><a name="p3111116118"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="29.299999999999997%" headers="mcps1.2.4.1.3 "><p id="p311131113119"><a name="p311131113119"></a><a name="p311131113119"></a>只读归档</p>
</td>
</tr>
<tr id="row315171112116"><td class="cellrowborder" valign="top" width="33.64%" headers="mcps1.2.4.1.1 "><p id="p12111611410"><a name="p12111611410"></a><a name="p12111611410"></a>security_services_app_verify</p>
</td>
<td class="cellrowborder" valign="top" width="37.059999999999995%" headers="mcps1.2.4.1.2 "><p id="p311161117112"><a name="p311161117112"></a><a name="p311161117112"></a>security_appverify</p>
</td>
<td class="cellrowborder" valign="top" width="29.299999999999997%" headers="mcps1.2.4.1.3 "><p id="p1611111412"><a name="p1611111412"></a><a name="p1611111412"></a>仓名变更</p>
</td>
</tr>
<tr id="row1715116111215"><td class="cellrowborder" valign="top" width="33.64%" headers="mcps1.2.4.1.1 "><p id="p101116112118"><a name="p101116112118"></a><a name="p101116112118"></a>security_interfaces_innerkits_app_verify</p>
</td>
<td class="cellrowborder" valign="top" width="37.059999999999995%" headers="mcps1.2.4.1.2 "><p id="p1412141112111"><a name="p1412141112111"></a><a name="p1412141112111"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="29.299999999999997%" headers="mcps1.2.4.1.3 "><p id="p31251119116"><a name="p31251119116"></a><a name="p31251119116"></a>只读归档</p>
</td>
</tr>
<tr id="row61514112110"><td class="cellrowborder" valign="top" width="33.64%" headers="mcps1.2.4.1.1 "><p id="p201218117114"><a name="p201218117114"></a><a name="p201218117114"></a>security_services_hichainsdk_lite</p>
</td>
<td class="cellrowborder" valign="top" width="37.059999999999995%" headers="mcps1.2.4.1.2 "><p id="p1512101119119"><a name="p1512101119119"></a><a name="p1512101119119"></a>security_deviceauth</p>
</td>
<td class="cellrowborder" valign="top" width="29.299999999999997%" headers="mcps1.2.4.1.3 "><p id="p612161111119"><a name="p612161111119"></a><a name="p612161111119"></a>仓名变更</p>
</td>
</tr>
<tr id="row17151161117116"><td class="cellrowborder" valign="top" width="33.64%" headers="mcps1.2.4.1.1 "><p id="p121217111515"><a name="p121217111515"></a><a name="p121217111515"></a>security_interfaces_innerkits_hichainsdk_lite</p>
</td>
<td class="cellrowborder" valign="top" width="37.059999999999995%" headers="mcps1.2.4.1.2 "><p id="p18127113119"><a name="p18127113119"></a><a name="p18127113119"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="29.299999999999997%" headers="mcps1.2.4.1.3 "><p id="p121220116110"><a name="p121220116110"></a><a name="p121220116110"></a>只读归档</p>
</td>
</tr>
<tr id="row191501611710"><td class="cellrowborder" valign="top" width="33.64%" headers="mcps1.2.4.1.1 "><p id="p17121114120"><a name="p17121114120"></a><a name="p17121114120"></a>security_services_huks_lite</p>
</td>
<td class="cellrowborder" valign="top" width="37.059999999999995%" headers="mcps1.2.4.1.2 "><p id="p1412811119"><a name="p1412811119"></a><a name="p1412811119"></a>security_huks</p>
</td>
<td class="cellrowborder" valign="top" width="29.299999999999997%" headers="mcps1.2.4.1.3 "><p id="p14129117112"><a name="p14129117112"></a><a name="p14129117112"></a>仓名变更</p>
</td>
</tr>
<tr id="row6150191115118"><td class="cellrowborder" valign="top" width="33.64%" headers="mcps1.2.4.1.1 "><p id="p412181117112"><a name="p412181117112"></a><a name="p412181117112"></a>security_interfaces_innerkits_huks_lite</p>
</td>
<td class="cellrowborder" valign="top" width="37.059999999999995%" headers="mcps1.2.4.1.2 "><p id="p191201115110"><a name="p191201115110"></a><a name="p191201115110"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="29.299999999999997%" headers="mcps1.2.4.1.3 "><p id="p31281110114"><a name="p31281110114"></a><a name="p31281110114"></a>只读归档</p>
</td>
</tr>
<tr id="row16150161113118"><td class="cellrowborder" valign="top" width="33.64%" headers="mcps1.2.4.1.1 "><p id="p01212110114"><a name="p01212110114"></a><a name="p01212110114"></a>security_frameworks_crypto_lite</p>
</td>
<td class="cellrowborder" valign="top" width="37.059999999999995%" headers="mcps1.2.4.1.2 "><p id="p10132115118"><a name="p10132115118"></a><a name="p10132115118"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="29.299999999999997%" headers="mcps1.2.4.1.3 "><p id="p1138111015"><a name="p1138111015"></a><a name="p1138111015"></a>只读归档</p>
</td>
</tr>
<tr id="row415015111419"><td class="cellrowborder" valign="top" width="33.64%" headers="mcps1.2.4.1.1 "><p id="p12131011513"><a name="p12131011513"></a><a name="p12131011513"></a>security_interfaces_innerkits_crypto_lite</p>
</td>
<td class="cellrowborder" valign="top" width="37.059999999999995%" headers="mcps1.2.4.1.2 "><p id="p61315112013"><a name="p61315112013"></a><a name="p61315112013"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="29.299999999999997%" headers="mcps1.2.4.1.3 "><p id="p413141116112"><a name="p413141116112"></a><a name="p413141116112"></a>只读归档</p>
</td>
</tr>
<tr id="row615012111417"><td class="cellrowborder" valign="top" width="33.64%" headers="mcps1.2.4.1.1 "><p id="p613121110118"><a name="p613121110118"></a><a name="p613121110118"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="37.059999999999995%" headers="mcps1.2.4.1.2 "><p id="p31341114116"><a name="p31341114116"></a><a name="p31341114116"></a>signcenter_tool</p>
</td>
<td class="cellrowborder" valign="top" width="29.299999999999997%" headers="mcps1.2.4.1.3 "><p id="p9136119111"><a name="p9136119111"></a><a name="p9136119111"></a>新增组件</p>
</td>
</tr>
<tr id="row915021114110"><td class="cellrowborder" valign="top" width="33.64%" headers="mcps1.2.4.1.1 "><p id="p141381118111"><a name="p141381118111"></a><a name="p141381118111"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="37.059999999999995%" headers="mcps1.2.4.1.2 "><p id="p11331113111"><a name="p11331113111"></a><a name="p11331113111"></a>third_party_cryptsetup</p>
</td>
<td class="cellrowborder" valign="top" width="29.299999999999997%" headers="mcps1.2.4.1.3 "><p id="p101391111113"><a name="p101391111113"></a><a name="p101391111113"></a>新增组件</p>
</td>
</tr>
<tr id="row1515010111813"><td class="cellrowborder" valign="top" width="33.64%" headers="mcps1.2.4.1.1 "><p id="p17135111112"><a name="p17135111112"></a><a name="p17135111112"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="37.059999999999995%" headers="mcps1.2.4.1.2 "><p id="p41313111116"><a name="p41313111116"></a><a name="p41313111116"></a>third_party_JSON-C</p>
</td>
<td class="cellrowborder" valign="top" width="29.299999999999997%" headers="mcps1.2.4.1.3 "><p id="p16134113114"><a name="p16134113114"></a><a name="p16134113114"></a>新增组件</p>
</td>
</tr>
<tr id="row1815031117116"><td class="cellrowborder" valign="top" width="33.64%" headers="mcps1.2.4.1.1 "><p id="p0133113116"><a name="p0133113116"></a><a name="p0133113116"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="37.059999999999995%" headers="mcps1.2.4.1.2 "><p id="p1014171117120"><a name="p1014171117120"></a><a name="p1014171117120"></a>third_party_libuuid</p>
</td>
<td class="cellrowborder" valign="top" width="29.299999999999997%" headers="mcps1.2.4.1.3 "><p id="p914171117112"><a name="p914171117112"></a><a name="p914171117112"></a>新增组件</p>
</td>
</tr>
<tr id="row51501611515"><td class="cellrowborder" valign="top" width="33.64%" headers="mcps1.2.4.1.1 "><p id="p191418111412"><a name="p191418111412"></a><a name="p191418111412"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="37.059999999999995%" headers="mcps1.2.4.1.2 "><p id="p0147111618"><a name="p0147111618"></a><a name="p0147111618"></a>third_party_LVM2</p>
</td>
<td class="cellrowborder" valign="top" width="29.299999999999997%" headers="mcps1.2.4.1.3 "><p id="p1814181111112"><a name="p1814181111112"></a><a name="p1814181111112"></a>新增组件</p>
</td>
</tr>
<tr id="row151504111413"><td class="cellrowborder" valign="top" width="33.64%" headers="mcps1.2.4.1.1 "><p id="p15143119111"><a name="p15143119111"></a><a name="p15143119111"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="37.059999999999995%" headers="mcps1.2.4.1.2 "><p id="p121413112115"><a name="p121413112115"></a><a name="p121413112115"></a>third_party_popt</p>
</td>
<td class="cellrowborder" valign="top" width="29.299999999999997%" headers="mcps1.2.4.1.3 "><p id="p1114311312"><a name="p1114311312"></a><a name="p1114311312"></a>新增组件</p>
</td>
</tr>
<tr id="row1215061120115"><td class="cellrowborder" valign="top" width="33.64%" headers="mcps1.2.4.1.1 "><p id="p4142114111"><a name="p4142114111"></a><a name="p4142114111"></a>communication_interfaces_kits_wifi_lite</p>
</td>
<td class="cellrowborder" valign="top" width="37.059999999999995%" headers="mcps1.2.4.1.2 "><p id="p161441110113"><a name="p161441110113"></a><a name="p161441110113"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="29.299999999999997%" headers="mcps1.2.4.1.3 "><p id="p101419116115"><a name="p101419116115"></a><a name="p101419116115"></a>只读归档</p>
</td>
</tr>
<tr id="row131502115117"><td class="cellrowborder" valign="top" width="33.64%" headers="mcps1.2.4.1.1 "><p id="p14141611315"><a name="p14141611315"></a><a name="p14141611315"></a>communication_frameworks_wifi_lite</p>
</td>
<td class="cellrowborder" valign="top" width="37.059999999999995%" headers="mcps1.2.4.1.2 "><p id="p514181112117"><a name="p514181112117"></a><a name="p514181112117"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="29.299999999999997%" headers="mcps1.2.4.1.3 "><p id="p414151119114"><a name="p414151119114"></a><a name="p414151119114"></a>只读归档</p>
</td>
</tr>
<tr id="row715010118116"><td class="cellrowborder" valign="top" width="33.64%" headers="mcps1.2.4.1.1 "><p id="p71551114114"><a name="p71551114114"></a><a name="p71551114114"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="37.059999999999995%" headers="mcps1.2.4.1.2 "><p id="p5151711312"><a name="p5151711312"></a><a name="p5151711312"></a>communication_wifi_lite</p>
</td>
<td class="cellrowborder" valign="top" width="29.299999999999997%" headers="mcps1.2.4.1.3 "><p id="p181512118118"><a name="p181512118118"></a><a name="p181512118118"></a>新增组件</p>
</td>
</tr>
<tr id="row14150121110113"><td class="cellrowborder" valign="top" width="33.64%" headers="mcps1.2.4.1.1 "><p id="p1215711419"><a name="p1215711419"></a><a name="p1215711419"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="37.059999999999995%" headers="mcps1.2.4.1.2 "><p id="p151515117117"><a name="p151515117117"></a><a name="p151515117117"></a>powermgr_powermgr_lite</p>
</td>
<td class="cellrowborder" valign="top" width="29.299999999999997%" headers="mcps1.2.4.1.3 "><p id="p1015191116115"><a name="p1015191116115"></a><a name="p1015191116115"></a>新增组件</p>
</td>
</tr>
<tr id="row12150511311"><td class="cellrowborder" valign="top" width="33.64%" headers="mcps1.2.4.1.1 "><p id="p8152011815"><a name="p8152011815"></a><a name="p8152011815"></a>distributedschedule_services_dtbschedmgr_lite</p>
</td>
<td class="cellrowborder" valign="top" width="37.059999999999995%" headers="mcps1.2.4.1.2 "><p id="p815811918"><a name="p815811918"></a><a name="p815811918"></a>distributedschedule_dms_fwk_lite</p>
</td>
<td class="cellrowborder" valign="top" width="29.299999999999997%" headers="mcps1.2.4.1.3 "><p id="p18151113120"><a name="p18151113120"></a><a name="p18151113120"></a>仓名变更</p>
</td>
</tr>
<tr id="row2015061110115"><td class="cellrowborder" valign="top" width="33.64%" headers="mcps1.2.4.1.1 "><p id="p191516111514"><a name="p191516111514"></a><a name="p191516111514"></a>distributedschedule_services_safwk_lite</p>
</td>
<td class="cellrowborder" valign="top" width="37.059999999999995%" headers="mcps1.2.4.1.2 "><p id="p19151111512"><a name="p19151111512"></a><a name="p19151111512"></a>distributedschedule_safwk_lite</p>
</td>
<td class="cellrowborder" valign="top" width="29.299999999999997%" headers="mcps1.2.4.1.3 "><p id="p11581116114"><a name="p11581116114"></a><a name="p11581116114"></a>仓名变更</p>
</td>
</tr>
<tr id="row51509113120"><td class="cellrowborder" valign="top" width="33.64%" headers="mcps1.2.4.1.1 "><p id="p111531111115"><a name="p111531111115"></a><a name="p111531111115"></a>distributedschedule_services_samgr_lite</p>
</td>
<td class="cellrowborder" valign="top" width="37.059999999999995%" headers="mcps1.2.4.1.2 "><p id="p20151711418"><a name="p20151711418"></a><a name="p20151711418"></a>distributedschedule_samgr_lite</p>
</td>
<td class="cellrowborder" valign="top" width="29.299999999999997%" headers="mcps1.2.4.1.3 "><p id="p111541118116"><a name="p111541118116"></a><a name="p111541118116"></a>仓名变更</p>
</td>
</tr>
<tr id="row1115018112114"><td class="cellrowborder" valign="top" width="33.64%" headers="mcps1.2.4.1.1 "><p id="p516171112110"><a name="p516171112110"></a><a name="p516171112110"></a>distributedschedule_interfaces_innerkits_samgr_lite</p>
</td>
<td class="cellrowborder" valign="top" width="37.059999999999995%" headers="mcps1.2.4.1.2 "><p id="p4163112118"><a name="p4163112118"></a><a name="p4163112118"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="29.299999999999997%" headers="mcps1.2.4.1.3 "><p id="p61621110114"><a name="p61621110114"></a><a name="p61621110114"></a>只读归档</p>
</td>
</tr>
<tr id="row13150311413"><td class="cellrowborder" valign="top" width="33.64%" headers="mcps1.2.4.1.1 "><p id="p416211212"><a name="p416211212"></a><a name="p416211212"></a>distributedschedule_interfaces_kits_samgr_lite</p>
</td>
<td class="cellrowborder" valign="top" width="37.059999999999995%" headers="mcps1.2.4.1.2 "><p id="p1116171111117"><a name="p1116171111117"></a><a name="p1116171111117"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="29.299999999999997%" headers="mcps1.2.4.1.3 "><p id="p716161119113"><a name="p716161119113"></a><a name="p716161119113"></a>只读归档</p>
</td>
</tr>
<tr id="row1515017111511"><td class="cellrowborder" valign="top" width="33.64%" headers="mcps1.2.4.1.1 "><p id="p6162117115"><a name="p6162117115"></a><a name="p6162117115"></a>multimedia_frameworks_audio_lite</p>
</td>
<td class="cellrowborder" valign="top" width="37.059999999999995%" headers="mcps1.2.4.1.2 "><p id="p13166111112"><a name="p13166111112"></a><a name="p13166111112"></a>multimedia_audio_lite</p>
</td>
<td class="cellrowborder" valign="top" width="29.299999999999997%" headers="mcps1.2.4.1.3 "><p id="p0163112120"><a name="p0163112120"></a><a name="p0163112120"></a>仓名变更</p>
</td>
</tr>
<tr id="row1115081110117"><td class="cellrowborder" valign="top" width="33.64%" headers="mcps1.2.4.1.1 "><p id="p21619111411"><a name="p21619111411"></a><a name="p21619111411"></a>multimedia_frameworks_camera_lite</p>
</td>
<td class="cellrowborder" valign="top" width="37.059999999999995%" headers="mcps1.2.4.1.2 "><p id="p3168113114"><a name="p3168113114"></a><a name="p3168113114"></a>multimedia_camera_lite</p>
</td>
<td class="cellrowborder" valign="top" width="29.299999999999997%" headers="mcps1.2.4.1.3 "><p id="p4161011316"><a name="p4161011316"></a><a name="p4161011316"></a>仓名变更</p>
</td>
</tr>
<tr id="row415010116114"><td class="cellrowborder" valign="top" width="33.64%" headers="mcps1.2.4.1.1 "><p id="p1161111410"><a name="p1161111410"></a><a name="p1161111410"></a>multimedia_frameworks_player_lite</p>
</td>
<td class="cellrowborder" valign="top" width="37.059999999999995%" headers="mcps1.2.4.1.2 "><p id="p151691115110"><a name="p151691115110"></a><a name="p151691115110"></a>multimedia_media_lite</p>
</td>
<td class="cellrowborder" valign="top" width="29.299999999999997%" headers="mcps1.2.4.1.3 "><p id="p31720110114"><a name="p31720110114"></a><a name="p31720110114"></a>仓名变更</p>
</td>
</tr>
<tr id="row61502116111"><td class="cellrowborder" valign="top" width="33.64%" headers="mcps1.2.4.1.1 "><p id="p141751114116"><a name="p141751114116"></a><a name="p141751114116"></a>multimedia_hals_camera_lite</p>
</td>
<td class="cellrowborder" valign="top" width="37.059999999999995%" headers="mcps1.2.4.1.2 "><p id="p01720119111"><a name="p01720119111"></a><a name="p01720119111"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="29.299999999999997%" headers="mcps1.2.4.1.3 "><p id="p81717111213"><a name="p81717111213"></a><a name="p81717111213"></a>只读归档</p>
</td>
</tr>
<tr id="row915010112116"><td class="cellrowborder" valign="top" width="33.64%" headers="mcps1.2.4.1.1 "><p id="p2177111117"><a name="p2177111117"></a><a name="p2177111117"></a>multimedia_frameworks_recorder_lite</p>
</td>
<td class="cellrowborder" valign="top" width="37.059999999999995%" headers="mcps1.2.4.1.2 "><p id="p71712119117"><a name="p71712119117"></a><a name="p71712119117"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="29.299999999999997%" headers="mcps1.2.4.1.3 "><p id="p17171111015"><a name="p17171111015"></a><a name="p17171111015"></a>只读归档</p>
</td>
</tr>
<tr id="row1615019111111"><td class="cellrowborder" valign="top" width="33.64%" headers="mcps1.2.4.1.1 "><p id="p91710114111"><a name="p91710114111"></a><a name="p91710114111"></a>multimedia_interfaces_kits_audio_lite</p>
</td>
<td class="cellrowborder" valign="top" width="37.059999999999995%" headers="mcps1.2.4.1.2 "><p id="p1917411114"><a name="p1917411114"></a><a name="p1917411114"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="29.299999999999997%" headers="mcps1.2.4.1.3 "><p id="p1173111914"><a name="p1173111914"></a><a name="p1173111914"></a>只读归档</p>
</td>
</tr>
<tr id="row1815012111119"><td class="cellrowborder" valign="top" width="33.64%" headers="mcps1.2.4.1.1 "><p id="p0171111214"><a name="p0171111214"></a><a name="p0171111214"></a>multimedia_interfaces_kits_camera_lite</p>
</td>
<td class="cellrowborder" valign="top" width="37.059999999999995%" headers="mcps1.2.4.1.2 "><p id="p11717111819"><a name="p11717111819"></a><a name="p11717111819"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="29.299999999999997%" headers="mcps1.2.4.1.3 "><p id="p1017811112"><a name="p1017811112"></a><a name="p1017811112"></a>只读归档</p>
</td>
</tr>
<tr id="row715020117112"><td class="cellrowborder" valign="top" width="33.64%" headers="mcps1.2.4.1.1 "><p id="p71716113114"><a name="p71716113114"></a><a name="p71716113114"></a>multimedia_interfaces_kits_player_lite</p>
</td>
<td class="cellrowborder" valign="top" width="37.059999999999995%" headers="mcps1.2.4.1.2 "><p id="p12189114114"><a name="p12189114114"></a><a name="p12189114114"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="29.299999999999997%" headers="mcps1.2.4.1.3 "><p id="p21811111319"><a name="p21811111319"></a><a name="p21811111319"></a>只读归档</p>
</td>
</tr>
<tr id="row8150151118120"><td class="cellrowborder" valign="top" width="33.64%" headers="mcps1.2.4.1.1 "><p id="p17188116110"><a name="p17188116110"></a><a name="p17188116110"></a>multimedia_interfaces_kits_recorder_lite</p>
</td>
<td class="cellrowborder" valign="top" width="37.059999999999995%" headers="mcps1.2.4.1.2 "><p id="p81813118110"><a name="p81813118110"></a><a name="p81813118110"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="29.299999999999997%" headers="mcps1.2.4.1.3 "><p id="p1518111114110"><a name="p1518111114110"></a><a name="p1518111114110"></a>只读归档</p>
</td>
</tr>
<tr id="row201491811815"><td class="cellrowborder" valign="top" width="33.64%" headers="mcps1.2.4.1.1 "><p id="p171831118117"><a name="p171831118117"></a><a name="p171831118117"></a>multimedia_services_media_lite</p>
</td>
<td class="cellrowborder" valign="top" width="37.059999999999995%" headers="mcps1.2.4.1.2 "><p id="p18188111815"><a name="p18188111815"></a><a name="p18188111815"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="29.299999999999997%" headers="mcps1.2.4.1.3 "><p id="p71812111316"><a name="p71812111316"></a><a name="p71812111316"></a>只读归档</p>
</td>
</tr>
<tr id="row141493116113"><td class="cellrowborder" valign="top" width="33.64%" headers="mcps1.2.4.1.1 "><p id="p14189112013"><a name="p14189112013"></a><a name="p14189112013"></a>kernel_liteos_a_huawei_proprietary_fs_proc</p>
</td>
<td class="cellrowborder" valign="top" width="37.059999999999995%" headers="mcps1.2.4.1.2 "><p id="p201817111115"><a name="p201817111115"></a><a name="p201817111115"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="29.299999999999997%" headers="mcps1.2.4.1.3 "><p id="p1918611618"><a name="p1918611618"></a><a name="p1918611618"></a>只读归档</p>
</td>
</tr>
<tr id="row101495114110"><td class="cellrowborder" valign="top" width="33.64%" headers="mcps1.2.4.1.1 "><p id="p1418101116111"><a name="p1418101116111"></a><a name="p1418101116111"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="37.059999999999995%" headers="mcps1.2.4.1.2 "><p id="p171818117118"><a name="p171818117118"></a><a name="p171818117118"></a>third_party_mksh</p>
</td>
<td class="cellrowborder" valign="top" width="29.299999999999997%" headers="mcps1.2.4.1.3 "><p id="p2018121120115"><a name="p2018121120115"></a><a name="p2018121120115"></a>新增组件</p>
</td>
</tr>
<tr id="row1614917113112"><td class="cellrowborder" valign="top" width="33.64%" headers="mcps1.2.4.1.1 "><p id="p5191111414"><a name="p5191111414"></a><a name="p5191111414"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="37.059999999999995%" headers="mcps1.2.4.1.2 "><p id="p1419201115118"><a name="p1419201115118"></a><a name="p1419201115118"></a>third_party_optimized_routines</p>
</td>
<td class="cellrowborder" valign="top" width="29.299999999999997%" headers="mcps1.2.4.1.3 "><p id="p18191711211"><a name="p18191711211"></a><a name="p18191711211"></a>新增组件</p>
</td>
</tr>
<tr id="row7149121120114"><td class="cellrowborder" valign="top" width="33.64%" headers="mcps1.2.4.1.1 "><p id="p151918117112"><a name="p151918117112"></a><a name="p151918117112"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="37.059999999999995%" headers="mcps1.2.4.1.2 "><p id="p181916111611"><a name="p181916111611"></a><a name="p181916111611"></a>third_party_toybox</p>
</td>
<td class="cellrowborder" valign="top" width="29.299999999999997%" headers="mcps1.2.4.1.3 "><p id="p121914111618"><a name="p121914111618"></a><a name="p121914111618"></a>新增组件</p>
</td>
</tr>
<tr id="row151491117117"><td class="cellrowborder" valign="top" width="33.64%" headers="mcps1.2.4.1.1 "><p id="p171911112114"><a name="p171911112114"></a><a name="p171911112114"></a>vendor_huawei_camera</p>
</td>
<td class="cellrowborder" valign="top" width="37.059999999999995%" headers="mcps1.2.4.1.2 "><p id="p7191111814"><a name="p7191111814"></a><a name="p7191111814"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="29.299999999999997%" headers="mcps1.2.4.1.3 "><p id="p219191115110"><a name="p219191115110"></a><a name="p219191115110"></a>只读归档</p>
</td>
</tr>
<tr id="row614919115118"><td class="cellrowborder" valign="top" width="33.64%" headers="mcps1.2.4.1.1 "><p id="p101919111111"><a name="p101919111111"></a><a name="p101919111111"></a>vendor_huawei_wifi_iot</p>
</td>
<td class="cellrowborder" valign="top" width="37.059999999999995%" headers="mcps1.2.4.1.2 "><p id="p1119101111111"><a name="p1119101111111"></a><a name="p1119101111111"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="29.299999999999997%" headers="mcps1.2.4.1.3 "><p id="p1919111114115"><a name="p1919111114115"></a><a name="p1919111114115"></a>只读归档</p>
</td>
</tr>
<tr id="row12149811717"><td class="cellrowborder" valign="top" width="33.64%" headers="mcps1.2.4.1.1 "><p id="p10198119114"><a name="p10198119114"></a><a name="p10198119114"></a>startup_services_bootstrap_lite</p>
</td>
<td class="cellrowborder" valign="top" width="37.059999999999995%" headers="mcps1.2.4.1.2 "><p id="p72031119117"><a name="p72031119117"></a><a name="p72031119117"></a>startup_bootstrap_lite</p>
</td>
<td class="cellrowborder" valign="top" width="29.299999999999997%" headers="mcps1.2.4.1.3 "><p id="p1320121116111"><a name="p1320121116111"></a><a name="p1320121116111"></a>仓名变更</p>
</td>
</tr>
<tr id="row114991110114"><td class="cellrowborder" valign="top" width="33.64%" headers="mcps1.2.4.1.1 "><p id="p420161112113"><a name="p420161112113"></a><a name="p420161112113"></a>startup_frameworks_syspara_lite</p>
</td>
<td class="cellrowborder" valign="top" width="37.059999999999995%" headers="mcps1.2.4.1.2 "><p id="p122018111319"><a name="p122018111319"></a><a name="p122018111319"></a>startup_syspara_lite</p>
</td>
<td class="cellrowborder" valign="top" width="29.299999999999997%" headers="mcps1.2.4.1.3 "><p id="p1420711016"><a name="p1420711016"></a><a name="p1420711016"></a>仓名变更</p>
</td>
</tr>
<tr id="row1914981112110"><td class="cellrowborder" valign="top" width="33.64%" headers="mcps1.2.4.1.1 "><p id="p82041113119"><a name="p82041113119"></a><a name="p82041113119"></a>startup_hals_syspara_lite</p>
</td>
<td class="cellrowborder" valign="top" width="37.059999999999995%" headers="mcps1.2.4.1.2 "><p id="p8204110113"><a name="p8204110113"></a><a name="p8204110113"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="29.299999999999997%" headers="mcps1.2.4.1.3 "><p id="p5203116116"><a name="p5203116116"></a><a name="p5203116116"></a>只读归档</p>
</td>
</tr>
<tr id="row714910111119"><td class="cellrowborder" valign="top" width="33.64%" headers="mcps1.2.4.1.1 "><p id="p102011112114"><a name="p102011112114"></a><a name="p102011112114"></a>startup_interfaces_kits_syspara_lite</p>
</td>
<td class="cellrowborder" valign="top" width="37.059999999999995%" headers="mcps1.2.4.1.2 "><p id="p132081116113"><a name="p132081116113"></a><a name="p132081116113"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="29.299999999999997%" headers="mcps1.2.4.1.3 "><p id="p02016111419"><a name="p02016111419"></a><a name="p02016111419"></a>只读归档</p>
</td>
</tr>
<tr id="row614917115119"><td class="cellrowborder" valign="top" width="33.64%" headers="mcps1.2.4.1.1 "><p id="p02081112120"><a name="p02081112120"></a><a name="p02081112120"></a>graphic_lite</p>
</td>
<td class="cellrowborder" valign="top" width="37.059999999999995%" headers="mcps1.2.4.1.2 "><p id="p5201011512"><a name="p5201011512"></a><a name="p5201011512"></a>graphic_surface</p>
</td>
<td class="cellrowborder" valign="top" width="29.299999999999997%" headers="mcps1.2.4.1.3 "><p id="p320111116119"><a name="p320111116119"></a><a name="p320111116119"></a>仓名变更</p>
</td>
</tr>
<tr id="row7149101110119"><td class="cellrowborder" valign="top" width="33.64%" headers="mcps1.2.4.1.1 "><p id="p1621711214"><a name="p1621711214"></a><a name="p1621711214"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="37.059999999999995%" headers="mcps1.2.4.1.2 "><p id="p32118113119"><a name="p32118113119"></a><a name="p32118113119"></a>graphic_ui</p>
</td>
<td class="cellrowborder" valign="top" width="29.299999999999997%" headers="mcps1.2.4.1.3 "><p id="p152161111110"><a name="p152161111110"></a><a name="p152161111110"></a>新增组件</p>
</td>
</tr>
<tr id="row121496111617"><td class="cellrowborder" valign="top" width="33.64%" headers="mcps1.2.4.1.1 "><p id="p1021211311"><a name="p1021211311"></a><a name="p1021211311"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="37.059999999999995%" headers="mcps1.2.4.1.2 "><p id="p9211611416"><a name="p9211611416"></a><a name="p9211611416"></a>graphic_utils</p>
</td>
<td class="cellrowborder" valign="top" width="29.299999999999997%" headers="mcps1.2.4.1.3 "><p id="p221161120115"><a name="p221161120115"></a><a name="p221161120115"></a>新增组件</p>
</td>
</tr>
<tr id="row1214911111518"><td class="cellrowborder" valign="top" width="33.64%" headers="mcps1.2.4.1.1 "><p id="p102112111216"><a name="p102112111216"></a><a name="p102112111216"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="37.059999999999995%" headers="mcps1.2.4.1.2 "><p id="p2217117111"><a name="p2217117111"></a><a name="p2217117111"></a>graphic_wms</p>
</td>
<td class="cellrowborder" valign="top" width="29.299999999999997%" headers="mcps1.2.4.1.3 "><p id="p3211911717"><a name="p3211911717"></a><a name="p3211911717"></a>新增组件</p>
</td>
</tr>
<tr id="row51493111319"><td class="cellrowborder" valign="top" width="33.64%" headers="mcps1.2.4.1.1 "><p id="p9219111514"><a name="p9219111514"></a><a name="p9219111514"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="37.059999999999995%" headers="mcps1.2.4.1.2 "><p id="p62116115113"><a name="p62116115113"></a><a name="p62116115113"></a>third_party_giflib</p>
</td>
<td class="cellrowborder" valign="top" width="29.299999999999997%" headers="mcps1.2.4.1.3 "><p id="p4214116111"><a name="p4214116111"></a><a name="p4214116111"></a>新增组件</p>
</td>
</tr>
<tr id="row1714912115118"><td class="cellrowborder" valign="top" width="33.64%" headers="mcps1.2.4.1.1 "><p id="p4211911616"><a name="p4211911616"></a><a name="p4211911616"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="37.059999999999995%" headers="mcps1.2.4.1.2 "><p id="p15223111413"><a name="p15223111413"></a><a name="p15223111413"></a>third_party_qrcodegen</p>
</td>
<td class="cellrowborder" valign="top" width="29.299999999999997%" headers="mcps1.2.4.1.3 "><p id="p622811418"><a name="p622811418"></a><a name="p622811418"></a>新增组件</p>
</td>
</tr>
<tr id="row191496119117"><td class="cellrowborder" valign="top" width="33.64%" headers="mcps1.2.4.1.1 "><p id="p172251120118"><a name="p172251120118"></a><a name="p172251120118"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="37.059999999999995%" headers="mcps1.2.4.1.2 "><p id="p42212114119"><a name="p42212114119"></a><a name="p42212114119"></a>drivers_adapter_khdf_linux</p>
</td>
<td class="cellrowborder" valign="top" width="29.299999999999997%" headers="mcps1.2.4.1.3 "><p id="p5222111619"><a name="p5222111619"></a><a name="p5222111619"></a>新增组件</p>
</td>
</tr>
<tr id="row8149911112"><td class="cellrowborder" valign="top" width="33.64%" headers="mcps1.2.4.1.1 "><p id="p52261114112"><a name="p52261114112"></a><a name="p52261114112"></a>drivers_hdf_lite</p>
</td>
<td class="cellrowborder" valign="top" width="37.059999999999995%" headers="mcps1.2.4.1.2 "><p id="p12211113115"><a name="p12211113115"></a><a name="p12211113115"></a>drivers_adapter_khdf_liteos</p>
</td>
<td class="cellrowborder" valign="top" width="29.299999999999997%" headers="mcps1.2.4.1.3 "><p id="p10221811516"><a name="p10221811516"></a><a name="p10221811516"></a>仓名变更</p>
</td>
</tr>
<tr id="row201491111616"><td class="cellrowborder" valign="top" width="33.64%" headers="mcps1.2.4.1.1 "><p id="p1221011413"><a name="p1221011413"></a><a name="p1221011413"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="37.059999999999995%" headers="mcps1.2.4.1.2 "><p id="p192216111512"><a name="p192216111512"></a><a name="p192216111512"></a>drivers_adapter_uhdf</p>
</td>
<td class="cellrowborder" valign="top" width="29.299999999999997%" headers="mcps1.2.4.1.3 "><p id="p15221211811"><a name="p15221211811"></a><a name="p15221211811"></a>新增组件</p>
</td>
</tr>
<tr id="row1414910111413"><td class="cellrowborder" valign="top" width="33.64%" headers="mcps1.2.4.1.1 "><p id="p142241114118"><a name="p142241114118"></a><a name="p142241114118"></a>drivers_hdf_frameworks</p>
</td>
<td class="cellrowborder" valign="top" width="37.059999999999995%" headers="mcps1.2.4.1.2 "><p id="p11222112113"><a name="p11222112113"></a><a name="p11222112113"></a>drivers_framework</p>
</td>
<td class="cellrowborder" valign="top" width="29.299999999999997%" headers="mcps1.2.4.1.3 "><p id="p2236111911"><a name="p2236111911"></a><a name="p2236111911"></a>仓名变更</p>
</td>
</tr>
<tr id="row17149201118115"><td class="cellrowborder" valign="top" width="33.64%" headers="mcps1.2.4.1.1 "><p id="p423111617"><a name="p423111617"></a><a name="p423111617"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="37.059999999999995%" headers="mcps1.2.4.1.2 "><p id="p123121110114"><a name="p123121110114"></a><a name="p123121110114"></a>drivers_peripheral_audio</p>
</td>
<td class="cellrowborder" valign="top" width="29.299999999999997%" headers="mcps1.2.4.1.3 "><p id="p52317112119"><a name="p52317112119"></a><a name="p52317112119"></a>新增组件</p>
</td>
</tr>
<tr id="row141491711613"><td class="cellrowborder" valign="top" width="33.64%" headers="mcps1.2.4.1.1 "><p id="p12236117112"><a name="p12236117112"></a><a name="p12236117112"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="37.059999999999995%" headers="mcps1.2.4.1.2 "><p id="p182317115110"><a name="p182317115110"></a><a name="p182317115110"></a>drivers_peripheral_codec</p>
</td>
<td class="cellrowborder" valign="top" width="29.299999999999997%" headers="mcps1.2.4.1.3 "><p id="p12231311617"><a name="p12231311617"></a><a name="p12231311617"></a>新增组件</p>
</td>
</tr>
<tr id="row1414916111017"><td class="cellrowborder" valign="top" width="33.64%" headers="mcps1.2.4.1.1 "><p id="p5234119116"><a name="p5234119116"></a><a name="p5234119116"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="37.059999999999995%" headers="mcps1.2.4.1.2 "><p id="p11231411813"><a name="p11231411813"></a><a name="p11231411813"></a>drivers_peripheral_display</p>
</td>
<td class="cellrowborder" valign="top" width="29.299999999999997%" headers="mcps1.2.4.1.3 "><p id="p12351119113"><a name="p12351119113"></a><a name="p12351119113"></a>新增组件</p>
</td>
</tr>
<tr id="row3149511414"><td class="cellrowborder" valign="top" width="33.64%" headers="mcps1.2.4.1.1 "><p id="p82315117116"><a name="p82315117116"></a><a name="p82315117116"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="37.059999999999995%" headers="mcps1.2.4.1.2 "><p id="p16230111914"><a name="p16230111914"></a><a name="p16230111914"></a>drivers_peripheral_format</p>
</td>
<td class="cellrowborder" valign="top" width="29.299999999999997%" headers="mcps1.2.4.1.3 "><p id="p32313119113"><a name="p32313119113"></a><a name="p32313119113"></a>新增组件</p>
</td>
</tr>
<tr id="row914981120116"><td class="cellrowborder" valign="top" width="33.64%" headers="mcps1.2.4.1.1 "><p id="p52412111819"><a name="p52412111819"></a><a name="p52412111819"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="37.059999999999995%" headers="mcps1.2.4.1.2 "><p id="p6248114114"><a name="p6248114114"></a><a name="p6248114114"></a>drivers_peripheral_input</p>
</td>
<td class="cellrowborder" valign="top" width="29.299999999999997%" headers="mcps1.2.4.1.3 "><p id="p1724191113119"><a name="p1724191113119"></a><a name="p1724191113119"></a>新增组件</p>
</td>
</tr>
<tr id="row1114961117118"><td class="cellrowborder" valign="top" width="33.64%" headers="mcps1.2.4.1.1 "><p id="p62471111120"><a name="p62471111120"></a><a name="p62471111120"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="37.059999999999995%" headers="mcps1.2.4.1.2 "><p id="p182414112011"><a name="p182414112011"></a><a name="p182414112011"></a>drivers_peripheral_sensor</p>
</td>
<td class="cellrowborder" valign="top" width="29.299999999999997%" headers="mcps1.2.4.1.3 "><p id="p11243112120"><a name="p11243112120"></a><a name="p11243112120"></a>新增组件</p>
</td>
</tr>
<tr id="row151491611914"><td class="cellrowborder" valign="top" width="33.64%" headers="mcps1.2.4.1.1 "><p id="p16244113118"><a name="p16244113118"></a><a name="p16244113118"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="37.059999999999995%" headers="mcps1.2.4.1.2 "><p id="p124171117113"><a name="p124171117113"></a><a name="p124171117113"></a>drivers_peripheral_wlan</p>
</td>
<td class="cellrowborder" valign="top" width="29.299999999999997%" headers="mcps1.2.4.1.3 "><p id="p124151114115"><a name="p124151114115"></a><a name="p124151114115"></a>新增组件</p>
</td>
</tr>
<tr id="row1314817111011"><td class="cellrowborder" valign="top" width="33.64%" headers="mcps1.2.4.1.1 "><p id="p18248111615"><a name="p18248111615"></a><a name="p18248111615"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="37.059999999999995%" headers="mcps1.2.4.1.2 "><p id="p10241911211"><a name="p10241911211"></a><a name="p10241911211"></a>global_cust_lite</p>
</td>
<td class="cellrowborder" valign="top" width="29.299999999999997%" headers="mcps1.2.4.1.3 "><p id="p16242011718"><a name="p16242011718"></a><a name="p16242011718"></a>新增组件</p>
</td>
</tr>
<tr id="row101482011311"><td class="cellrowborder" valign="top" width="33.64%" headers="mcps1.2.4.1.1 "><p id="p122520111815"><a name="p122520111815"></a><a name="p122520111815"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="37.059999999999995%" headers="mcps1.2.4.1.2 "><p id="p1625181116113"><a name="p1625181116113"></a><a name="p1625181116113"></a>global_i18n_lite</p>
</td>
<td class="cellrowborder" valign="top" width="29.299999999999997%" headers="mcps1.2.4.1.3 "><p id="p1725111617"><a name="p1725111617"></a><a name="p1725111617"></a>新增组件</p>
</td>
</tr>
<tr id="row171486113113"><td class="cellrowborder" valign="top" width="33.64%" headers="mcps1.2.4.1.1 "><p id="p1325191119117"><a name="p1325191119117"></a><a name="p1325191119117"></a>global_frameworks_resmgr_lite</p>
</td>
<td class="cellrowborder" valign="top" width="37.059999999999995%" headers="mcps1.2.4.1.2 "><p id="p22518111418"><a name="p22518111418"></a><a name="p22518111418"></a>global_resmgr_lite</p>
</td>
<td class="cellrowborder" valign="top" width="29.299999999999997%" headers="mcps1.2.4.1.3 "><p id="p3254112113"><a name="p3254112113"></a><a name="p3254112113"></a>仓名变更</p>
</td>
</tr>
<tr id="row111489112012"><td class="cellrowborder" valign="top" width="33.64%" headers="mcps1.2.4.1.1 ">&nbsp;&nbsp;</td>
<td class="cellrowborder" valign="top" width="37.059999999999995%" headers="mcps1.2.4.1.2 "><p id="p0254111118"><a name="p0254111118"></a><a name="p0254111118"></a>third_party_icu</p>
</td>
<td class="cellrowborder" valign="top" width="29.299999999999997%" headers="mcps1.2.4.1.3 "><p id="p12571116118"><a name="p12571116118"></a><a name="p12571116118"></a>新增组件</p>
</td>
</tr>
<tr id="row11148141118119"><td class="cellrowborder" valign="top" width="33.64%" headers="mcps1.2.4.1.1 "><p id="p102581116119"><a name="p102581116119"></a><a name="p102581116119"></a>global_interfaces_innerkits_resmgr_lite</p>
</td>
<td class="cellrowborder" valign="top" width="37.059999999999995%" headers="mcps1.2.4.1.2 "><p id="p4251711817"><a name="p4251711817"></a><a name="p4251711817"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="29.299999999999997%" headers="mcps1.2.4.1.3 "><p id="p13251511916"><a name="p13251511916"></a><a name="p13251511916"></a>只读归档</p>
</td>
</tr>
<tr id="row6148151110115"><td class="cellrowborder" valign="top" width="33.64%" headers="mcps1.2.4.1.1 "><p id="p12615112116"><a name="p12615112116"></a><a name="p12615112116"></a>communication_frameworks_ipc_lite</p>
</td>
<td class="cellrowborder" valign="top" width="37.059999999999995%" headers="mcps1.2.4.1.2 "><p id="p3262011110"><a name="p3262011110"></a><a name="p3262011110"></a>communication_ipc_lite</p>
</td>
<td class="cellrowborder" valign="top" width="29.299999999999997%" headers="mcps1.2.4.1.3 "><p id="p326911918"><a name="p326911918"></a><a name="p326911918"></a>仓名变更</p>
</td>
</tr>
<tr id="row1914816117116"><td class="cellrowborder" valign="top" width="33.64%" headers="mcps1.2.4.1.1 "><p id="p92617119117"><a name="p92617119117"></a><a name="p92617119117"></a>communication_interfaces_kits_ipc_lite</p>
</td>
<td class="cellrowborder" valign="top" width="37.059999999999995%" headers="mcps1.2.4.1.2 "><p id="p19262113112"><a name="p19262113112"></a><a name="p19262113112"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="29.299999999999997%" headers="mcps1.2.4.1.3 "><p id="p426181116113"><a name="p426181116113"></a><a name="p426181116113"></a>只读归档</p>
</td>
</tr>
<tr id="row014821113115"><td class="cellrowborder" valign="top" width="33.64%" headers="mcps1.2.4.1.1 "><p id="p92621113111"><a name="p92621113111"></a><a name="p92621113111"></a>communication_interfaces_kits_softbuskit_lite</p>
</td>
<td class="cellrowborder" valign="top" width="37.059999999999995%" headers="mcps1.2.4.1.2 "><p id="p1926121111115"><a name="p1926121111115"></a><a name="p1926121111115"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="29.299999999999997%" headers="mcps1.2.4.1.3 "><p id="p112612115114"><a name="p112612115114"></a><a name="p112612115114"></a>只读归档</p>
</td>
</tr>
<tr id="row1914861120118"><td class="cellrowborder" valign="top" width="33.64%" headers="mcps1.2.4.1.1 "><p id="p8261111817"><a name="p8261111817"></a><a name="p8261111817"></a>communication_hals_wifi_lite</p>
</td>
<td class="cellrowborder" valign="top" width="37.059999999999995%" headers="mcps1.2.4.1.2 "><p id="p182616115114"><a name="p182616115114"></a><a name="p182616115114"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="29.299999999999997%" headers="mcps1.2.4.1.3 "><p id="p16262113119"><a name="p16262113119"></a><a name="p16262113119"></a>只读归档</p>
</td>
</tr>
<tr id="row214812111114"><td class="cellrowborder" valign="top" width="33.64%" headers="mcps1.2.4.1.1 "><p id="p32710114119"><a name="p32710114119"></a><a name="p32710114119"></a>communication_services_softbus_lite</p>
</td>
<td class="cellrowborder" valign="top" width="37.059999999999995%" headers="mcps1.2.4.1.2 "><p id="p2272116112"><a name="p2272116112"></a><a name="p2272116112"></a>communication_softbus_lite</p>
</td>
<td class="cellrowborder" valign="top" width="29.299999999999997%" headers="mcps1.2.4.1.3 "><p id="p172712113120"><a name="p172712113120"></a><a name="p172712113120"></a>仓名变更</p>
</td>
</tr>
<tr id="row16148161112119"><td class="cellrowborder" valign="top" width="33.64%" headers="mcps1.2.4.1.1 "><p id="p15271011110"><a name="p15271011110"></a><a name="p15271011110"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="37.059999999999995%" headers="mcps1.2.4.1.2 "><p id="p12741115115"><a name="p12741115115"></a><a name="p12741115115"></a>communication_wifi_aware</p>
</td>
<td class="cellrowborder" valign="top" width="29.299999999999997%" headers="mcps1.2.4.1.3 "><p id="p527141115118"><a name="p527141115118"></a><a name="p527141115118"></a>新增组件</p>
</td>
</tr>
<tr id="row111487119113"><td class="cellrowborder" valign="top" width="33.64%" headers="mcps1.2.4.1.1 "><p id="p11274111517"><a name="p11274111517"></a><a name="p11274111517"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="37.059999999999995%" headers="mcps1.2.4.1.2 "><p id="p1927811318"><a name="p1927811318"></a><a name="p1927811318"></a>update_ota_lite</p>
</td>
<td class="cellrowborder" valign="top" width="29.299999999999997%" headers="mcps1.2.4.1.3 "><p id="p16271112014"><a name="p16271112014"></a><a name="p16271112014"></a>新增组件</p>
</td>
</tr>
<tr id="row20148151117114"><td class="cellrowborder" valign="top" width="33.64%" headers="mcps1.2.4.1.1 "><p id="p1027131119119"><a name="p1027131119119"></a><a name="p1027131119119"></a>vendor_hisi_hi35xx_hi35xx_init</p>
</td>
<td class="cellrowborder" valign="top" width="37.059999999999995%" headers="mcps1.2.4.1.2 "><p id="p102712111813"><a name="p102712111813"></a><a name="p102712111813"></a>device_hisilicon_build</p>
</td>
<td class="cellrowborder" valign="top" width="29.299999999999997%" headers="mcps1.2.4.1.3 "><p id="p152716117114"><a name="p152716117114"></a><a name="p152716117114"></a>仓名变更</p>
</td>
</tr>
<tr id="row1314861117110"><td class="cellrowborder" valign="top" width="33.64%" headers="mcps1.2.4.1.1 "><p id="p1028511716"><a name="p1028511716"></a><a name="p1028511716"></a>vendor_hisi_hi35xx_platform</p>
</td>
<td class="cellrowborder" valign="top" width="37.059999999999995%" headers="mcps1.2.4.1.2 "><p id="p4281411410"><a name="p4281411410"></a><a name="p4281411410"></a>device_hisilicon_drivers</p>
</td>
<td class="cellrowborder" valign="top" width="29.299999999999997%" headers="mcps1.2.4.1.3 "><p id="p8287111119"><a name="p8287111119"></a><a name="p8287111119"></a>仓名变更</p>
</td>
</tr>
<tr id="row121481911218"><td class="cellrowborder" valign="top" width="33.64%" headers="mcps1.2.4.1.1 "><p id="p15281211918"><a name="p15281211918"></a><a name="p15281211918"></a>vendor_hisi_hi35xx_hardware</p>
</td>
<td class="cellrowborder" valign="top" width="37.059999999999995%" headers="mcps1.2.4.1.2 "><p id="p128111118119"><a name="p128111118119"></a><a name="p128111118119"></a>device_hisilicon_hardware</p>
</td>
<td class="cellrowborder" valign="top" width="29.299999999999997%" headers="mcps1.2.4.1.3 "><p id="p7283111416"><a name="p7283111416"></a><a name="p7283111416"></a>仓名变更</p>
</td>
</tr>
<tr id="row11148171116110"><td class="cellrowborder" valign="top" width="33.64%" headers="mcps1.2.4.1.1 "><p id="p42810113116"><a name="p42810113116"></a><a name="p42810113116"></a>vendor_hisi_hi35xx_hi3518ev300</p>
</td>
<td class="cellrowborder" valign="top" width="37.059999999999995%" headers="mcps1.2.4.1.2 "><p id="p1282111814"><a name="p1282111814"></a><a name="p1282111814"></a>device_hisilicon_hispark_aries</p>
</td>
<td class="cellrowborder" valign="top" width="29.299999999999997%" headers="mcps1.2.4.1.3 "><p id="p22817111716"><a name="p22817111716"></a><a name="p22817111716"></a>仓名变更</p>
</td>
</tr>
<tr id="row614813111113"><td class="cellrowborder" valign="top" width="33.64%" headers="mcps1.2.4.1.1 "><p id="p182811116114"><a name="p182811116114"></a><a name="p182811116114"></a>vendor_hisi_hi3861_hi3861</p>
</td>
<td class="cellrowborder" valign="top" width="37.059999999999995%" headers="mcps1.2.4.1.2 "><p id="p4285112119"><a name="p4285112119"></a><a name="p4285112119"></a>device_hisilicon_hispark_pegasus</p>
</td>
<td class="cellrowborder" valign="top" width="29.299999999999997%" headers="mcps1.2.4.1.3 "><p id="p12821110110"><a name="p12821110110"></a><a name="p12821110110"></a>仓名变更</p>
</td>
</tr>
<tr id="row214821119120"><td class="cellrowborder" valign="top" width="33.64%" headers="mcps1.2.4.1.1 "><p id="p3291811612"><a name="p3291811612"></a><a name="p3291811612"></a>vendor_hisi_hi35xx_hi3516dv300</p>
</td>
<td class="cellrowborder" valign="top" width="37.059999999999995%" headers="mcps1.2.4.1.2 "><p id="p13291811715"><a name="p13291811715"></a><a name="p13291811715"></a>device_hisilicon_hispark_taurus</p>
</td>
<td class="cellrowborder" valign="top" width="29.299999999999997%" headers="mcps1.2.4.1.3 "><p id="p11294111615"><a name="p11294111615"></a><a name="p11294111615"></a>仓名变更</p>
</td>
</tr>
<tr id="row1314820111319"><td class="cellrowborder" valign="top" width="33.64%" headers="mcps1.2.4.1.1 "><p id="p19297115119"><a name="p19297115119"></a><a name="p19297115119"></a>vendor_hisi_hi35xx_middleware</p>
</td>
<td class="cellrowborder" valign="top" width="37.059999999999995%" headers="mcps1.2.4.1.2 "><p id="p202961117117"><a name="p202961117117"></a><a name="p202961117117"></a>device_hisilicon_modules</p>
</td>
<td class="cellrowborder" valign="top" width="29.299999999999997%" headers="mcps1.2.4.1.3 "><p id="p329151119110"><a name="p329151119110"></a><a name="p329151119110"></a>仓名变更</p>
</td>
</tr>
<tr id="row214814111719"><td class="cellrowborder" valign="top" width="33.64%" headers="mcps1.2.4.1.1 "><p id="p162920111814"><a name="p162920111814"></a><a name="p162920111814"></a>vendor_hisi_hi35xx_middleware_source_third_party_ffmpeg</p>
</td>
<td class="cellrowborder" valign="top" width="37.059999999999995%" headers="mcps1.2.4.1.2 "><p id="p12294111112"><a name="p12294111112"></a><a name="p12294111112"></a>device_hisilicon_third_party_ffmpeg</p>
</td>
<td class="cellrowborder" valign="top" width="29.299999999999997%" headers="mcps1.2.4.1.3 "><p id="p18291011915"><a name="p18291011915"></a><a name="p18291011915"></a>仓名变更</p>
</td>
</tr>
<tr id="row131486110119"><td class="cellrowborder" valign="top" width="33.64%" headers="mcps1.2.4.1.1 "><p id="p12291611916"><a name="p12291611916"></a><a name="p12291611916"></a>vendor_hisi_hi35xx_thirdparty_uboot_src</p>
</td>
<td class="cellrowborder" valign="top" width="37.059999999999995%" headers="mcps1.2.4.1.2 "><p id="p1293111018"><a name="p1293111018"></a><a name="p1293111018"></a>device_hisilicon_third_party_uboot</p>
</td>
<td class="cellrowborder" valign="top" width="29.299999999999997%" headers="mcps1.2.4.1.3 "><p id="p22914111616"><a name="p22914111616"></a><a name="p22914111616"></a>仓名变更</p>
</td>
</tr>
<tr id="row181487111915"><td class="cellrowborder" valign="top" width="33.64%" headers="mcps1.2.4.1.1 "><p id="p43013110113"><a name="p43013110113"></a><a name="p43013110113"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="37.059999999999995%" headers="mcps1.2.4.1.2 "><p id="p03019111017"><a name="p03019111017"></a><a name="p03019111017"></a>vendor_hisilicon</p>
</td>
<td class="cellrowborder" valign="top" width="29.299999999999997%" headers="mcps1.2.4.1.3 "><p id="p4303114118"><a name="p4303114118"></a><a name="p4303114118"></a>新增组件</p>
</td>
</tr>
<tr id="row111481411211"><td class="cellrowborder" valign="top" width="33.64%" headers="mcps1.2.4.1.1 "><p id="p11301411119"><a name="p11301411119"></a><a name="p11301411119"></a>vendor_hisi_hi35xx_hi3516dv300_uboot</p>
</td>
<td class="cellrowborder" valign="top" width="37.059999999999995%" headers="mcps1.2.4.1.2 "><p id="p1330151111112"><a name="p1330151111112"></a><a name="p1330151111112"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="29.299999999999997%" headers="mcps1.2.4.1.3 "><p id="p20304119111"><a name="p20304119111"></a><a name="p20304119111"></a>只读归档</p>
</td>
</tr>
<tr id="row714841112111"><td class="cellrowborder" valign="top" width="33.64%" headers="mcps1.2.4.1.1 "><p id="p33014114112"><a name="p33014114112"></a><a name="p33014114112"></a>vendor_hisi_hi35xx_hi3518ev300_uboot</p>
</td>
<td class="cellrowborder" valign="top" width="37.059999999999995%" headers="mcps1.2.4.1.2 "><p id="p5303111218"><a name="p5303111218"></a><a name="p5303111218"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="29.299999999999997%" headers="mcps1.2.4.1.3 "><p id="p1230611911"><a name="p1230611911"></a><a name="p1230611911"></a>只读归档</p>
</td>
</tr>
<tr id="row614841113116"><td class="cellrowborder" valign="top" width="33.64%" headers="mcps1.2.4.1.1 "><p id="p530811415"><a name="p530811415"></a><a name="p530811415"></a>aafwk_interfaces_innerkits_abilitykit_lite</p>
</td>
<td class="cellrowborder" valign="top" width="37.059999999999995%" headers="mcps1.2.4.1.2 "><p id="p2030511717"><a name="p2030511717"></a><a name="p2030511717"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="29.299999999999997%" headers="mcps1.2.4.1.3 "><p id="p93061110118"><a name="p93061110118"></a><a name="p93061110118"></a>只读归档</p>
</td>
</tr>
<tr id="row181482111119"><td class="cellrowborder" valign="top" width="33.64%" headers="mcps1.2.4.1.1 "><p id="p203191115119"><a name="p203191115119"></a><a name="p203191115119"></a>aafwk_interfaces_innerkits_intent_lite</p>
</td>
<td class="cellrowborder" valign="top" width="37.059999999999995%" headers="mcps1.2.4.1.2 "><p id="p831141113117"><a name="p831141113117"></a><a name="p831141113117"></a>aafwk_aafwk_lite</p>
</td>
<td class="cellrowborder" valign="top" width="29.299999999999997%" headers="mcps1.2.4.1.3 "><p id="p3312112015"><a name="p3312112015"></a><a name="p3312112015"></a>仓名变更</p>
</td>
</tr>
<tr id="row2147191115115"><td class="cellrowborder" valign="top" width="33.64%" headers="mcps1.2.4.1.1 "><p id="p1331611912"><a name="p1331611912"></a><a name="p1331611912"></a>aafwk_interfaces_innerkits_abilitymgr_lite</p>
</td>
<td class="cellrowborder" valign="top" width="37.059999999999995%" headers="mcps1.2.4.1.2 "><p id="p1431111419"><a name="p1431111419"></a><a name="p1431111419"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="29.299999999999997%" headers="mcps1.2.4.1.3 "><p id="p331911211"><a name="p331911211"></a><a name="p331911211"></a>只读归档</p>
</td>
</tr>
<tr id="row1114718115118"><td class="cellrowborder" valign="top" width="33.64%" headers="mcps1.2.4.1.1 "><p id="p33191113118"><a name="p33191113118"></a><a name="p33191113118"></a>appexecfwk_kits_appkit_lite</p>
</td>
<td class="cellrowborder" valign="top" width="37.059999999999995%" headers="mcps1.2.4.1.2 "><p id="p631151110111"><a name="p631151110111"></a><a name="p631151110111"></a>appexecfwk_appexecfwk_lite</p>
</td>
<td class="cellrowborder" valign="top" width="29.299999999999997%" headers="mcps1.2.4.1.3 "><p id="p1312111915"><a name="p1312111915"></a><a name="p1312111915"></a>仓名变更</p>
</td>
</tr>
<tr id="row161475111210"><td class="cellrowborder" valign="top" width="33.64%" headers="mcps1.2.4.1.1 "><p id="p7311111417"><a name="p7311111417"></a><a name="p7311111417"></a>aafwk_frameworks_kits_ability_lite</p>
</td>
<td class="cellrowborder" valign="top" width="37.059999999999995%" headers="mcps1.2.4.1.2 "><p id="p4311711515"><a name="p4311711515"></a><a name="p4311711515"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="29.299999999999997%" headers="mcps1.2.4.1.3 "><p id="p831171111119"><a name="p831171111119"></a><a name="p831171111119"></a>只读归档</p>
</td>
</tr>
<tr id="row14147411211"><td class="cellrowborder" valign="top" width="33.64%" headers="mcps1.2.4.1.1 ">&nbsp;&nbsp;</td>
<td class="cellrowborder" valign="top" width="37.059999999999995%" headers="mcps1.2.4.1.2 "><p id="p163241112114"><a name="p163241112114"></a><a name="p163241112114"></a>developtools_packing_tool</p>
</td>
<td class="cellrowborder" valign="top" width="29.299999999999997%" headers="mcps1.2.4.1.3 "><p id="p432151112116"><a name="p432151112116"></a><a name="p432151112116"></a>新增组件</p>
</td>
</tr>
<tr id="row4147191110114"><td class="cellrowborder" valign="top" width="33.64%" headers="mcps1.2.4.1.1 "><p id="p23217111112"><a name="p23217111112"></a><a name="p23217111112"></a>aafwk_interfaces_kits_ability_lite</p>
</td>
<td class="cellrowborder" valign="top" width="37.059999999999995%" headers="mcps1.2.4.1.2 "><p id="p183215111713"><a name="p183215111713"></a><a name="p183215111713"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="29.299999999999997%" headers="mcps1.2.4.1.3 "><p id="p1323111015"><a name="p1323111015"></a><a name="p1323111015"></a>只读归档</p>
</td>
</tr>
<tr id="row16147121116119"><td class="cellrowborder" valign="top" width="33.64%" headers="mcps1.2.4.1.1 "><p id="p1532141113116"><a name="p1532141113116"></a><a name="p1532141113116"></a>appexecfwk_frameworks_bundle_lite</p>
</td>
<td class="cellrowborder" valign="top" width="37.059999999999995%" headers="mcps1.2.4.1.2 "><p id="p153216111015"><a name="p153216111015"></a><a name="p153216111015"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="29.299999999999997%" headers="mcps1.2.4.1.3 "><p id="p2323113117"><a name="p2323113117"></a><a name="p2323113117"></a>只读归档</p>
</td>
</tr>
<tr id="row914731112115"><td class="cellrowborder" valign="top" width="33.64%" headers="mcps1.2.4.1.1 "><p id="p632811312"><a name="p632811312"></a><a name="p632811312"></a>aafwk_services_abilitymgr_lite</p>
</td>
<td class="cellrowborder" valign="top" width="37.059999999999995%" headers="mcps1.2.4.1.2 "><p id="p93218111018"><a name="p93218111018"></a><a name="p93218111018"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="29.299999999999997%" headers="mcps1.2.4.1.3 "><p id="p163231112115"><a name="p163231112115"></a><a name="p163231112115"></a>只读归档</p>
</td>
</tr>
<tr id="row1614741113117"><td class="cellrowborder" valign="top" width="33.64%" headers="mcps1.2.4.1.1 "><p id="p33321115113"><a name="p33321115113"></a><a name="p33321115113"></a>appexecfwk_interfaces_innerkits_appexecfwk_lite</p>
</td>
<td class="cellrowborder" valign="top" width="37.059999999999995%" headers="mcps1.2.4.1.2 "><p id="p23313111314"><a name="p23313111314"></a><a name="p23313111314"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="29.299999999999997%" headers="mcps1.2.4.1.3 "><p id="p1933181110113"><a name="p1933181110113"></a><a name="p1933181110113"></a>只读归档</p>
</td>
</tr>
<tr id="row201471911116"><td class="cellrowborder" valign="top" width="33.64%" headers="mcps1.2.4.1.1 "><p id="p103316111314"><a name="p103316111314"></a><a name="p103316111314"></a>appexecfwk_interfaces_innerkits_bundlemgr_lite</p>
</td>
<td class="cellrowborder" valign="top" width="37.059999999999995%" headers="mcps1.2.4.1.2 "><p id="p14339111417"><a name="p14339111417"></a><a name="p14339111417"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="29.299999999999997%" headers="mcps1.2.4.1.3 "><p id="p193314114117"><a name="p193314114117"></a><a name="p193314114117"></a>只读归档</p>
</td>
</tr>
<tr id="row121474111718"><td class="cellrowborder" valign="top" width="33.64%" headers="mcps1.2.4.1.1 "><p id="p93317112013"><a name="p93317112013"></a><a name="p93317112013"></a>appexecfwk_services_bundlemgr_lite</p>
</td>
<td class="cellrowborder" valign="top" width="37.059999999999995%" headers="mcps1.2.4.1.2 "><p id="p0331211910"><a name="p0331211910"></a><a name="p0331211910"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="29.299999999999997%" headers="mcps1.2.4.1.3 "><p id="p43318111120"><a name="p43318111120"></a><a name="p43318111120"></a>只读归档</p>
</td>
</tr>
<tr id="row61471111819"><td class="cellrowborder" valign="top" width="33.64%" headers="mcps1.2.4.1.1 "><p id="p103361113118"><a name="p103361113118"></a><a name="p103361113118"></a>aafwk_frameworks_kits_content_lite</p>
</td>
<td class="cellrowborder" valign="top" width="37.059999999999995%" headers="mcps1.2.4.1.2 "><p id="p1133611212"><a name="p1133611212"></a><a name="p1133611212"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="29.299999999999997%" headers="mcps1.2.4.1.3 "><p id="p123411115112"><a name="p123411115112"></a><a name="p123411115112"></a>只读归档</p>
</td>
</tr>
</tbody>
</table>

## 已修复缺陷列表<a name="section11935243172612"></a>

针对OpenHarmony 1.0版本的缺陷列表，解决并修复的问题请参见下表。

**表 4**  修复问题列表

<a name="table1934113413913"></a>
<table><thead align="left"><tr id="row4341334203914"><th class="cellrowborder" valign="top" width="22.650000000000002%" id="mcps1.2.3.1.1"><p id="p711564410397"><a name="p711564410397"></a><a name="p711564410397"></a>ISSUE</p>
</th>
<th class="cellrowborder" valign="top" width="77.35%" id="mcps1.2.3.1.2"><p id="p411564416397"><a name="p411564416397"></a><a name="p411564416397"></a>问题描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row934223410393"><td class="cellrowborder" valign="top" width="22.650000000000002%" headers="mcps1.2.3.1.1 "><p id="p133271454113911"><a name="p133271454113911"></a><a name="p133271454113911"></a><a href="https://gitee.com/openharmony/multimedia_camera_lite/issues/I3EALU" target="_blank" rel="noopener noreferrer">I3EALU</a></p>
</td>
<td class="cellrowborder" valign="top" width="77.35%" headers="mcps1.2.3.1.2 "><p id="p1132775483917"><a name="p1132775483917"></a><a name="p1132775483917"></a>【多媒体】cameraActs 用例执行时，找不到相机配置文件，初始失败的问题</p>
</td>
</tr>
<tr id="row0342133417396"><td class="cellrowborder" valign="top" width="22.650000000000002%" headers="mcps1.2.3.1.1 "><p id="p153278540395"><a name="p153278540395"></a><a name="p153278540395"></a><a href="https://gitee.com/openharmony/drivers_adapter_khdf_liteos/issues/I3D71U" target="_blank" rel="noopener noreferrer">I3D71U</a></p>
</td>
<td class="cellrowborder" valign="top" width="77.35%" headers="mcps1.2.3.1.2 "><p id="p93271254153915"><a name="p93271254153915"></a><a name="p93271254153915"></a>【驱动】反复reset，启动到hmac_main_init SUCCESSULLY后，高概率出现系统挂死问题</p>
</td>
</tr>
<tr id="row8342934173920"><td class="cellrowborder" valign="top" width="22.650000000000002%" headers="mcps1.2.3.1.1 "><p id="p7328145410392"><a name="p7328145410392"></a><a name="p7328145410392"></a><a href="https://gitee.com/openharmony/community/issues/I3EGUX" target="_blank" rel="noopener noreferrer">I3EGUX</a></p>
</td>
<td class="cellrowborder" valign="top" width="77.35%" headers="mcps1.2.3.1.2 "><p id="p9328654193918"><a name="p9328654193918"></a><a name="p9328654193918"></a>【可靠性问题】反复reset，出现一次KIdle进程crash，系统挂死无法启动</p>
</td>
</tr>
<tr id="row034213453916"><td class="cellrowborder" valign="top" width="22.650000000000002%" headers="mcps1.2.3.1.1 "><p id="p132875473912"><a name="p132875473912"></a><a name="p132875473912"></a><a href="https://gitee.com/openharmony/community/issues/I3DHIL" target="_blank" rel="noopener noreferrer">I3DHIL</a></p>
</td>
<td class="cellrowborder" valign="top" width="77.35%" headers="mcps1.2.3.1.2 "><p id="p17328105420391"><a name="p17328105420391"></a><a name="p17328105420391"></a>【系统问题】HI3518开源板剩余空间不足，导致ACTS用例大量失败</p>
</td>
</tr>
</tbody>
</table>

