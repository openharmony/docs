# KVManager配置信息<a name="ZH-CN_TOPIC_0000001164290734"></a>

-   [导入模块](#zh-cn_topic_0000001175852127_s56d19203690d4782bfc74069abb6bd71)
-   [权限](#zh-cn_topic_0000001175852127_section11257113618419)
-   [UserType](#zh-cn_topic_0000001175852127_section099619567453)
-   [KVManagerConfig](#zh-cn_topic_0000001175852127_section4346145712159)
-   [UserInfo](#zh-cn_topic_0000001175852127_section12882825611)

>![](../../public_sys-resources/icon-note.gif) **说明：** 
>从 API Version 7 开始支持。

## 导入模块<a name="zh-cn_topic_0000001175852127_s56d19203690d4782bfc74069abb6bd71"></a>

```
import factory from '@ohos.data.distributeddata';
```

## 权限<a name="zh-cn_topic_0000001175852127_section11257113618419"></a>

无

## UserType<a name="zh-cn_topic_0000001175852127_section099619567453"></a>

描述用户类型。

<a name="zh-cn_topic_0000001175852127_table20633101642315"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001175852127_row663331618238"><th class="cellrowborder" valign="top" width="27.900000000000002%" id="mcps1.1.4.1.1"><p id="zh-cn_topic_0000001175852127_a3d0fc780cc904c1cbab7991251622f65"><a name="zh-cn_topic_0000001175852127_a3d0fc780cc904c1cbab7991251622f65"></a><a name="zh-cn_topic_0000001175852127_a3d0fc780cc904c1cbab7991251622f65"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="12.43%" id="mcps1.1.4.1.2"><p id="zh-cn_topic_0000001175852127_aace9cae4ba0d4939bfa048460f61c3c7"><a name="zh-cn_topic_0000001175852127_aace9cae4ba0d4939bfa048460f61c3c7"></a><a name="zh-cn_topic_0000001175852127_aace9cae4ba0d4939bfa048460f61c3c7"></a>默认值</p>
</th>
<th class="cellrowborder" valign="top" width="59.67%" id="mcps1.1.4.1.3"><p id="zh-cn_topic_0000001175852127_afec895de33f94e3c87ee7acc20190a17"><a name="zh-cn_topic_0000001175852127_afec895de33f94e3c87ee7acc20190a17"></a><a name="zh-cn_topic_0000001175852127_afec895de33f94e3c87ee7acc20190a17"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001175852127_row188481425182510"><td class="cellrowborder" valign="top" width="27.900000000000002%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001175852127_p52851329122117"><a name="zh-cn_topic_0000001175852127_p52851329122117"></a><a name="zh-cn_topic_0000001175852127_p52851329122117"></a>SAME_USER_ID</p>
</td>
<td class="cellrowborder" valign="top" width="12.43%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001175852127_p127372258515"><a name="zh-cn_topic_0000001175852127_p127372258515"></a><a name="zh-cn_topic_0000001175852127_p127372258515"></a>0</p>
</td>
<td class="cellrowborder" valign="top" width="59.67%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001175852127_p328012293211"><a name="zh-cn_topic_0000001175852127_p328012293211"></a><a name="zh-cn_topic_0000001175852127_p328012293211"></a>表示使用同一帐户登录不同设备的用户。</p>
</td>
</tr>
</tbody>
</table>

## KVManagerConfig<a name="zh-cn_topic_0000001175852127_section4346145712159"></a>

提供KVManager实例的配置信息。

包括调用者的包名称和分布式网络类型。

<a name="zh-cn_topic_0000001175852127_table1346155718156"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001175852127_row3346135713159"><th class="cellrowborder" valign="top" width="15.870000000000001%" id="mcps1.1.6.1.1"><p id="zh-cn_topic_0000001175852127_p193461057151516"><a name="zh-cn_topic_0000001175852127_p193461057151516"></a><a name="zh-cn_topic_0000001175852127_p193461057151516"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="10.86%" id="mcps1.1.6.1.2"><p id="zh-cn_topic_0000001175852127_p034685781510"><a name="zh-cn_topic_0000001175852127_p034685781510"></a><a name="zh-cn_topic_0000001175852127_p034685781510"></a>参数类型</p>
</th>
<th class="cellrowborder" valign="top" width="9.34%" id="mcps1.1.6.1.3"><p id="zh-cn_topic_0000001175852127_p9346135719158"><a name="zh-cn_topic_0000001175852127_p9346135719158"></a><a name="zh-cn_topic_0000001175852127_p9346135719158"></a>可读</p>
</th>
<th class="cellrowborder" valign="top" width="11.51%" id="mcps1.1.6.1.4"><p id="zh-cn_topic_0000001175852127_p11347175791511"><a name="zh-cn_topic_0000001175852127_p11347175791511"></a><a name="zh-cn_topic_0000001175852127_p11347175791511"></a>可写</p>
</th>
<th class="cellrowborder" valign="top" width="52.42%" id="mcps1.1.6.1.5"><p id="zh-cn_topic_0000001175852127_p143471757191518"><a name="zh-cn_topic_0000001175852127_p143471757191518"></a><a name="zh-cn_topic_0000001175852127_p143471757191518"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001175852127_row1734745719159"><td class="cellrowborder" valign="top" width="15.870000000000001%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001175852127_p14347115721510"><a name="zh-cn_topic_0000001175852127_p14347115721510"></a><a name="zh-cn_topic_0000001175852127_p14347115721510"></a>userInfo</p>
</td>
<td class="cellrowborder" valign="top" width="10.86%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001175852127_p1347125715158"><a name="zh-cn_topic_0000001175852127_p1347125715158"></a><a name="zh-cn_topic_0000001175852127_p1347125715158"></a><a href="#zh-cn_topic_0000001175852127_section12882825611">UserInfo</a></p>
</td>
<td class="cellrowborder" valign="top" width="9.34%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001175852127_p3347175741518"><a name="zh-cn_topic_0000001175852127_p3347175741518"></a><a name="zh-cn_topic_0000001175852127_p3347175741518"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="11.51%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001175852127_p11347257131512"><a name="zh-cn_topic_0000001175852127_p11347257131512"></a><a name="zh-cn_topic_0000001175852127_p11347257131512"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="52.42%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001175852127_p1234735715159"><a name="zh-cn_topic_0000001175852127_p1234735715159"></a><a name="zh-cn_topic_0000001175852127_p1234735715159"></a>用户信息。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001175852127_row53477574154"><td class="cellrowborder" valign="top" width="15.870000000000001%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001175852127_p123472579150"><a name="zh-cn_topic_0000001175852127_p123472579150"></a><a name="zh-cn_topic_0000001175852127_p123472579150"></a>bundleName</p>
</td>
<td class="cellrowborder" valign="top" width="10.86%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001175852127_p334745751511"><a name="zh-cn_topic_0000001175852127_p334745751511"></a><a name="zh-cn_topic_0000001175852127_p334745751511"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="9.34%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001175852127_p11347145771516"><a name="zh-cn_topic_0000001175852127_p11347145771516"></a><a name="zh-cn_topic_0000001175852127_p11347145771516"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="11.51%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001175852127_p20347135712155"><a name="zh-cn_topic_0000001175852127_p20347135712155"></a><a name="zh-cn_topic_0000001175852127_p20347135712155"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="52.42%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001175852127_p10347175720159"><a name="zh-cn_topic_0000001175852127_p10347175720159"></a><a name="zh-cn_topic_0000001175852127_p10347175720159"></a>应用包名。长度应小于1KB。</p>
</td>
</tr>
</tbody>
</table>

## UserInfo<a name="zh-cn_topic_0000001175852127_section12882825611"></a>

用户信息管理类。

<a name="zh-cn_topic_0000001175852127_table1459620431636"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001175852127_row25971143435"><th class="cellrowborder" valign="top" width="15.870000000000001%" id="mcps1.1.6.1.1"><p id="zh-cn_topic_0000001175852127_p1559716434320"><a name="zh-cn_topic_0000001175852127_p1559716434320"></a><a name="zh-cn_topic_0000001175852127_p1559716434320"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="10.86%" id="mcps1.1.6.1.2"><p id="zh-cn_topic_0000001175852127_p3597743539"><a name="zh-cn_topic_0000001175852127_p3597743539"></a><a name="zh-cn_topic_0000001175852127_p3597743539"></a>参数类型</p>
</th>
<th class="cellrowborder" valign="top" width="9.34%" id="mcps1.1.6.1.3"><p id="zh-cn_topic_0000001175852127_p15971343131"><a name="zh-cn_topic_0000001175852127_p15971343131"></a><a name="zh-cn_topic_0000001175852127_p15971343131"></a>可读</p>
</th>
<th class="cellrowborder" valign="top" width="11.51%" id="mcps1.1.6.1.4"><p id="zh-cn_topic_0000001175852127_p1459715436311"><a name="zh-cn_topic_0000001175852127_p1459715436311"></a><a name="zh-cn_topic_0000001175852127_p1459715436311"></a>可写</p>
</th>
<th class="cellrowborder" valign="top" width="52.42%" id="mcps1.1.6.1.5"><p id="zh-cn_topic_0000001175852127_p75975439316"><a name="zh-cn_topic_0000001175852127_p75975439316"></a><a name="zh-cn_topic_0000001175852127_p75975439316"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001175852127_row95971943839"><td class="cellrowborder" valign="top" width="15.870000000000001%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001175852127_p10946136141716"><a name="zh-cn_topic_0000001175852127_p10946136141716"></a><a name="zh-cn_topic_0000001175852127_p10946136141716"></a>userId</p>
</td>
<td class="cellrowborder" valign="top" width="10.86%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001175852127_p2059710431030"><a name="zh-cn_topic_0000001175852127_p2059710431030"></a><a name="zh-cn_topic_0000001175852127_p2059710431030"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="9.34%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001175852127_p1059711439317"><a name="zh-cn_topic_0000001175852127_p1059711439317"></a><a name="zh-cn_topic_0000001175852127_p1059711439317"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="11.51%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001175852127_p659715430317"><a name="zh-cn_topic_0000001175852127_p659715430317"></a><a name="zh-cn_topic_0000001175852127_p659715430317"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="52.42%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001175852127_p2059719436313"><a name="zh-cn_topic_0000001175852127_p2059719436313"></a><a name="zh-cn_topic_0000001175852127_p2059719436313"></a>表示需要设置的用户ID。长度应小于1KB。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001175852127_row185973435316"><td class="cellrowborder" valign="top" width="15.870000000000001%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001175852127_p1559710432310"><a name="zh-cn_topic_0000001175852127_p1559710432310"></a><a name="zh-cn_topic_0000001175852127_p1559710432310"></a>userType</p>
</td>
<td class="cellrowborder" valign="top" width="10.86%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001175852127_p16597144318312"><a name="zh-cn_topic_0000001175852127_p16597144318312"></a><a name="zh-cn_topic_0000001175852127_p16597144318312"></a><a href="#zh-cn_topic_0000001175852127_section099619567453">UserType</a></p>
</td>
<td class="cellrowborder" valign="top" width="9.34%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001175852127_p12597194313317"><a name="zh-cn_topic_0000001175852127_p12597194313317"></a><a name="zh-cn_topic_0000001175852127_p12597194313317"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="11.51%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001175852127_p1259710431236"><a name="zh-cn_topic_0000001175852127_p1259710431236"></a><a name="zh-cn_topic_0000001175852127_p1259710431236"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="52.42%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001175852127_p10597843034"><a name="zh-cn_topic_0000001175852127_p10597843034"></a><a name="zh-cn_topic_0000001175852127_p10597843034"></a>表示需要设置的用户类型。</p>
</td>
</tr>
</tbody>
</table>

