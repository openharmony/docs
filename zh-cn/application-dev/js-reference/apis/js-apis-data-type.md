# 数据类型描述<a name="ZH-CN_TOPIC_0000001209570723"></a>

-   [导入模块](#zh-cn_topic_0000001129943828_s56d19203690d4782bfc74069abb6bd71)
-   [权限](#zh-cn_topic_0000001129943828_section11257113618419)
-   [SubscribeType](#zh-cn_topic_0000001129943828_section099619567453)
-   [KVStoreType](#zh-cn_topic_0000001129943828_section720518449379)
-   [SecurityLevel](#zh-cn_topic_0000001129943828_section205876465372)
-   [Options](#zh-cn_topic_0000001129943828_section16417114202216)
-   [SyncMode](#zh-cn_topic_0000001129943828_section53541759205119)
-   [ValueType](#zh-cn_topic_0000001129943828_section19236155475512)
-   [Value](#zh-cn_topic_0000001129943828_section12882825611)
-   [Entry](#zh-cn_topic_0000001129943828_section1467716175115)
-   [ChangeNotification](#zh-cn_topic_0000001129943828_section9868357105716)

>![](../../public_sys-resources/icon-note.gif) **说明：** 
>从 API Version 7 开始支持。

## 导入模块<a name="zh-cn_topic_0000001129943828_s56d19203690d4782bfc74069abb6bd71"></a>

```
import factory from '@ohos.data.distributeddata';
```

## 权限<a name="zh-cn_topic_0000001129943828_section11257113618419"></a>

无

## SubscribeType<a name="zh-cn_topic_0000001129943828_section099619567453"></a>

描述订阅类型。

<a name="zh-cn_topic_0000001129943828_table20633101642315"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001129943828_row663331618238"><th class="cellrowborder" valign="top" width="27.900000000000002%" id="mcps1.1.4.1.1"><p id="zh-cn_topic_0000001129943828_a3d0fc780cc904c1cbab7991251622f65"><a name="zh-cn_topic_0000001129943828_a3d0fc780cc904c1cbab7991251622f65"></a><a name="zh-cn_topic_0000001129943828_a3d0fc780cc904c1cbab7991251622f65"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="12.43%" id="mcps1.1.4.1.2"><p id="zh-cn_topic_0000001129943828_aace9cae4ba0d4939bfa048460f61c3c7"><a name="zh-cn_topic_0000001129943828_aace9cae4ba0d4939bfa048460f61c3c7"></a><a name="zh-cn_topic_0000001129943828_aace9cae4ba0d4939bfa048460f61c3c7"></a>默认值</p>
</th>
<th class="cellrowborder" valign="top" width="59.67%" id="mcps1.1.4.1.3"><p id="zh-cn_topic_0000001129943828_afec895de33f94e3c87ee7acc20190a17"><a name="zh-cn_topic_0000001129943828_afec895de33f94e3c87ee7acc20190a17"></a><a name="zh-cn_topic_0000001129943828_afec895de33f94e3c87ee7acc20190a17"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001129943828_row188481425182510"><td class="cellrowborder" valign="top" width="27.900000000000002%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001129943828_p52851329122117"><a name="zh-cn_topic_0000001129943828_p52851329122117"></a><a name="zh-cn_topic_0000001129943828_p52851329122117"></a>SUBSCRIBE_TYPE_LOCAL</p>
</td>
<td class="cellrowborder" valign="top" width="12.43%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001129943828_p2282152962115"><a name="zh-cn_topic_0000001129943828_p2282152962115"></a><a name="zh-cn_topic_0000001129943828_p2282152962115"></a>0</p>
</td>
<td class="cellrowborder" valign="top" width="59.67%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001129943828_p328012293211"><a name="zh-cn_topic_0000001129943828_p328012293211"></a><a name="zh-cn_topic_0000001129943828_p328012293211"></a>表示订阅本地数据变更。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001129943828_row0461622112513"><td class="cellrowborder" valign="top" width="27.900000000000002%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001129943828_p12106173918219"><a name="zh-cn_topic_0000001129943828_p12106173918219"></a><a name="zh-cn_topic_0000001129943828_p12106173918219"></a>SUBSCRIBE_TYPE_REMOTE</p>
</td>
<td class="cellrowborder" valign="top" width="12.43%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001129943828_p1310553911218"><a name="zh-cn_topic_0000001129943828_p1310553911218"></a><a name="zh-cn_topic_0000001129943828_p1310553911218"></a>1</p>
</td>
<td class="cellrowborder" valign="top" width="59.67%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001129943828_p15865395215"><a name="zh-cn_topic_0000001129943828_p15865395215"></a><a name="zh-cn_topic_0000001129943828_p15865395215"></a>表示订阅远端数据变更。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001129943828_row1424110293364"><td class="cellrowborder" valign="top" width="27.900000000000002%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001129943828_p8242729133612"><a name="zh-cn_topic_0000001129943828_p8242729133612"></a><a name="zh-cn_topic_0000001129943828_p8242729133612"></a>SUBSCRIBE_TYPE_ALL</p>
</td>
<td class="cellrowborder" valign="top" width="12.43%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001129943828_p1243629153617"><a name="zh-cn_topic_0000001129943828_p1243629153617"></a><a name="zh-cn_topic_0000001129943828_p1243629153617"></a>2</p>
</td>
<td class="cellrowborder" valign="top" width="59.67%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001129943828_p202430293369"><a name="zh-cn_topic_0000001129943828_p202430293369"></a><a name="zh-cn_topic_0000001129943828_p202430293369"></a>表示订阅远端和本地数据变更。</p>
</td>
</tr>
</tbody>
</table>

## KVStoreType<a name="zh-cn_topic_0000001129943828_section720518449379"></a>

用于指定创建的数据库的类型。

<a name="zh-cn_topic_0000001129943828_table20205174420379"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001129943828_row1620654416375"><th class="cellrowborder" valign="top" width="27.900000000000002%" id="mcps1.1.4.1.1"><p id="zh-cn_topic_0000001129943828_p820614447373"><a name="zh-cn_topic_0000001129943828_p820614447373"></a><a name="zh-cn_topic_0000001129943828_p820614447373"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="12.43%" id="mcps1.1.4.1.2"><p id="zh-cn_topic_0000001129943828_p1520611449379"><a name="zh-cn_topic_0000001129943828_p1520611449379"></a><a name="zh-cn_topic_0000001129943828_p1520611449379"></a>默认值</p>
</th>
<th class="cellrowborder" valign="top" width="59.67%" id="mcps1.1.4.1.3"><p id="zh-cn_topic_0000001129943828_p1820654413373"><a name="zh-cn_topic_0000001129943828_p1820654413373"></a><a name="zh-cn_topic_0000001129943828_p1820654413373"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001129943828_row8206144420370"><td class="cellrowborder" valign="top" width="27.900000000000002%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001129943828_p1206744133718"><a name="zh-cn_topic_0000001129943828_p1206744133718"></a><a name="zh-cn_topic_0000001129943828_p1206744133718"></a>DEVICE_COLLABORATION</p>
</td>
<td class="cellrowborder" valign="top" width="12.43%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001129943828_p102065442377"><a name="zh-cn_topic_0000001129943828_p102065442377"></a><a name="zh-cn_topic_0000001129943828_p102065442377"></a>0</p>
</td>
<td class="cellrowborder" valign="top" width="59.67%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001129943828_p720618443371"><a name="zh-cn_topic_0000001129943828_p720618443371"></a><a name="zh-cn_topic_0000001129943828_p720618443371"></a>表示设备协同数据库。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001129943828_row4206104463714"><td class="cellrowborder" valign="top" width="27.900000000000002%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001129943828_p220604419371"><a name="zh-cn_topic_0000001129943828_p220604419371"></a><a name="zh-cn_topic_0000001129943828_p220604419371"></a>SINGLE_VERSION</p>
</td>
<td class="cellrowborder" valign="top" width="12.43%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001129943828_p320674473712"><a name="zh-cn_topic_0000001129943828_p320674473712"></a><a name="zh-cn_topic_0000001129943828_p320674473712"></a>1</p>
</td>
<td class="cellrowborder" valign="top" width="59.67%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001129943828_p6822541173610"><a name="zh-cn_topic_0000001129943828_p6822541173610"></a><a name="zh-cn_topic_0000001129943828_p6822541173610"></a>表示单版本数据库。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001129943828_row5952210133711"><td class="cellrowborder" valign="top" width="27.900000000000002%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001129943828_p1895321017372"><a name="zh-cn_topic_0000001129943828_p1895321017372"></a><a name="zh-cn_topic_0000001129943828_p1895321017372"></a>MULTI_VERSION</p>
</td>
<td class="cellrowborder" valign="top" width="12.43%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001129943828_p395341016374"><a name="zh-cn_topic_0000001129943828_p395341016374"></a><a name="zh-cn_topic_0000001129943828_p395341016374"></a>2</p>
</td>
<td class="cellrowborder" valign="top" width="59.67%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001129943828_p995381014377"><a name="zh-cn_topic_0000001129943828_p995381014377"></a><a name="zh-cn_topic_0000001129943828_p995381014377"></a>表示多版本数据库。此类型当前不允许使用。</p>
</td>
</tr>
</tbody>
</table>

## SecurityLevel<a name="zh-cn_topic_0000001129943828_section205876465372"></a>

用于指定创建的数据库的安全级别。

<a name="zh-cn_topic_0000001129943828_table1558710464373"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001129943828_row35874465377"><th class="cellrowborder" valign="top" width="20.849999999999998%" id="mcps1.1.4.1.1"><p id="zh-cn_topic_0000001129943828_p2587346173718"><a name="zh-cn_topic_0000001129943828_p2587346173718"></a><a name="zh-cn_topic_0000001129943828_p2587346173718"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="10.879999999999999%" id="mcps1.1.4.1.2"><p id="zh-cn_topic_0000001129943828_p105874461372"><a name="zh-cn_topic_0000001129943828_p105874461372"></a><a name="zh-cn_topic_0000001129943828_p105874461372"></a>默认值</p>
</th>
<th class="cellrowborder" valign="top" width="68.27%" id="mcps1.1.4.1.3"><p id="zh-cn_topic_0000001129943828_p858804612376"><a name="zh-cn_topic_0000001129943828_p858804612376"></a><a name="zh-cn_topic_0000001129943828_p858804612376"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001129943828_row195888462377"><td class="cellrowborder" valign="top" width="20.849999999999998%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001129943828_p85881846133712"><a name="zh-cn_topic_0000001129943828_p85881846133712"></a><a name="zh-cn_topic_0000001129943828_p85881846133712"></a>NO_LEVEL</p>
</td>
<td class="cellrowborder" valign="top" width="10.879999999999999%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001129943828_p155881146183714"><a name="zh-cn_topic_0000001129943828_p155881146183714"></a><a name="zh-cn_topic_0000001129943828_p155881146183714"></a>0</p>
</td>
<td class="cellrowborder" valign="top" width="68.27%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001129943828_p058820464374"><a name="zh-cn_topic_0000001129943828_p058820464374"></a><a name="zh-cn_topic_0000001129943828_p058820464374"></a>表示数据库不设置安全级别。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001129943828_row6588204620378"><td class="cellrowborder" valign="top" width="20.849999999999998%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001129943828_p958884623720"><a name="zh-cn_topic_0000001129943828_p958884623720"></a><a name="zh-cn_topic_0000001129943828_p958884623720"></a>S0</p>
</td>
<td class="cellrowborder" valign="top" width="10.879999999999999%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001129943828_p75881146173720"><a name="zh-cn_topic_0000001129943828_p75881146173720"></a><a name="zh-cn_topic_0000001129943828_p75881146173720"></a>1</p>
</td>
<td class="cellrowborder" valign="top" width="68.27%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001129943828_p358834673718"><a name="zh-cn_topic_0000001129943828_p358834673718"></a><a name="zh-cn_topic_0000001129943828_p358834673718"></a>表示数据库的安全级别为公共级别安全，当数据泄露时不会产生影响。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001129943828_row858810465372"><td class="cellrowborder" valign="top" width="20.849999999999998%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001129943828_p25881146133714"><a name="zh-cn_topic_0000001129943828_p25881146133714"></a><a name="zh-cn_topic_0000001129943828_p25881146133714"></a>S1</p>
</td>
<td class="cellrowborder" valign="top" width="10.879999999999999%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001129943828_p1958874612370"><a name="zh-cn_topic_0000001129943828_p1958874612370"></a><a name="zh-cn_topic_0000001129943828_p1958874612370"></a>2</p>
</td>
<td class="cellrowborder" valign="top" width="68.27%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001129943828_p205885469370"><a name="zh-cn_topic_0000001129943828_p205885469370"></a><a name="zh-cn_topic_0000001129943828_p205885469370"></a>表示数据库的安全级别为低级别安全，当数据泄露时会产生较低影响。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001129943828_row93891331184019"><td class="cellrowborder" valign="top" width="20.849999999999998%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001129943828_p23904313405"><a name="zh-cn_topic_0000001129943828_p23904313405"></a><a name="zh-cn_topic_0000001129943828_p23904313405"></a>S2</p>
</td>
<td class="cellrowborder" valign="top" width="10.879999999999999%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001129943828_p10390133119408"><a name="zh-cn_topic_0000001129943828_p10390133119408"></a><a name="zh-cn_topic_0000001129943828_p10390133119408"></a>3</p>
</td>
<td class="cellrowborder" valign="top" width="68.27%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001129943828_p8390153114014"><a name="zh-cn_topic_0000001129943828_p8390153114014"></a><a name="zh-cn_topic_0000001129943828_p8390153114014"></a>表示数据库的安全级别为中级别安全，当数据泄露时会产生较大影响。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001129943828_row18665352407"><td class="cellrowborder" valign="top" width="20.849999999999998%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001129943828_p26613351409"><a name="zh-cn_topic_0000001129943828_p26613351409"></a><a name="zh-cn_topic_0000001129943828_p26613351409"></a>S3</p>
</td>
<td class="cellrowborder" valign="top" width="10.879999999999999%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001129943828_p1066735114011"><a name="zh-cn_topic_0000001129943828_p1066735114011"></a><a name="zh-cn_topic_0000001129943828_p1066735114011"></a>5</p>
</td>
<td class="cellrowborder" valign="top" width="68.27%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001129943828_p9671535174014"><a name="zh-cn_topic_0000001129943828_p9671535174014"></a><a name="zh-cn_topic_0000001129943828_p9671535174014"></a>表示数据库的安全级别为高级别安全，当数据泄露时会产生重大影响。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001129943828_row2698955134015"><td class="cellrowborder" valign="top" width="20.849999999999998%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001129943828_p7699165512403"><a name="zh-cn_topic_0000001129943828_p7699165512403"></a><a name="zh-cn_topic_0000001129943828_p7699165512403"></a>S4</p>
</td>
<td class="cellrowborder" valign="top" width="10.879999999999999%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001129943828_p869935594018"><a name="zh-cn_topic_0000001129943828_p869935594018"></a><a name="zh-cn_topic_0000001129943828_p869935594018"></a>6</p>
</td>
<td class="cellrowborder" valign="top" width="68.27%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001129943828_p06991755174017"><a name="zh-cn_topic_0000001129943828_p06991755174017"></a><a name="zh-cn_topic_0000001129943828_p06991755174017"></a>表示数据库的安全级别为关键级别安全，当数据泄露时会产生严重影响。</p>
</td>
</tr>
</tbody>
</table>

## Options<a name="zh-cn_topic_0000001129943828_section16417114202216"></a>

用于提供创建数据库的配置信息。

<a name="zh-cn_topic_0000001129943828_table139428218117"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001129943828_row8943821510"><th class="cellrowborder" valign="top" width="16.32%" id="mcps1.1.5.1.1"><p id="zh-cn_topic_0000001129943828_p139439212111"><a name="zh-cn_topic_0000001129943828_p139439212111"></a><a name="zh-cn_topic_0000001129943828_p139439212111"></a>参数名</p>
</th>
<th class="cellrowborder" valign="top" width="20.61%" id="mcps1.1.5.1.2"><p id="zh-cn_topic_0000001129943828_p5943721919"><a name="zh-cn_topic_0000001129943828_p5943721919"></a><a name="zh-cn_topic_0000001129943828_p5943721919"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="10.41%" id="mcps1.1.5.1.3"><p id="zh-cn_topic_0000001129943828_p189431218119"><a name="zh-cn_topic_0000001129943828_p189431218119"></a><a name="zh-cn_topic_0000001129943828_p189431218119"></a>必填</p>
</th>
<th class="cellrowborder" valign="top" width="52.66%" id="mcps1.1.5.1.4"><p id="zh-cn_topic_0000001129943828_p11943142518"><a name="zh-cn_topic_0000001129943828_p11943142518"></a><a name="zh-cn_topic_0000001129943828_p11943142518"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001129943828_row1794311214119"><td class="cellrowborder" valign="top" width="16.32%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001129943828_p15237173214282"><a name="zh-cn_topic_0000001129943828_p15237173214282"></a><a name="zh-cn_topic_0000001129943828_p15237173214282"></a>createIfMissing</p>
</td>
<td class="cellrowborder" valign="top" width="20.61%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001129943828_p794412718"><a name="zh-cn_topic_0000001129943828_p794412718"></a><a name="zh-cn_topic_0000001129943828_p794412718"></a>boolean</p>
</td>
<td class="cellrowborder" valign="top" width="10.41%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001129943828_p79441213120"><a name="zh-cn_topic_0000001129943828_p79441213120"></a><a name="zh-cn_topic_0000001129943828_p79441213120"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="52.66%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000001129943828_p2944424110"><a name="zh-cn_topic_0000001129943828_p2944424110"></a><a name="zh-cn_topic_0000001129943828_p2944424110"></a>当数据库文件不存在时是否创建数据库。默认创建。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001129943828_row5944129113"><td class="cellrowborder" valign="top" width="16.32%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001129943828_p8944929118"><a name="zh-cn_topic_0000001129943828_p8944929118"></a><a name="zh-cn_topic_0000001129943828_p8944929118"></a>encrypt</p>
</td>
<td class="cellrowborder" valign="top" width="20.61%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001129943828_p1294420220114"><a name="zh-cn_topic_0000001129943828_p1294420220114"></a><a name="zh-cn_topic_0000001129943828_p1294420220114"></a>boolean</p>
</td>
<td class="cellrowborder" valign="top" width="10.41%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001129943828_p29447211119"><a name="zh-cn_topic_0000001129943828_p29447211119"></a><a name="zh-cn_topic_0000001129943828_p29447211119"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="52.66%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000001129943828_p89451526118"><a name="zh-cn_topic_0000001129943828_p89451526118"></a><a name="zh-cn_topic_0000001129943828_p89451526118"></a>设置数据库文件是否加密。默认不加密。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001129943828_row109451529112"><td class="cellrowborder" valign="top" width="16.32%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001129943828_p199911462912"><a name="zh-cn_topic_0000001129943828_p199911462912"></a><a name="zh-cn_topic_0000001129943828_p199911462912"></a>backup</p>
</td>
<td class="cellrowborder" valign="top" width="20.61%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001129943828_p19455210120"><a name="zh-cn_topic_0000001129943828_p19455210120"></a><a name="zh-cn_topic_0000001129943828_p19455210120"></a>boolean</p>
</td>
<td class="cellrowborder" valign="top" width="10.41%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001129943828_p89451721915"><a name="zh-cn_topic_0000001129943828_p89451721915"></a><a name="zh-cn_topic_0000001129943828_p89451721915"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="52.66%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000001129943828_p139457210111"><a name="zh-cn_topic_0000001129943828_p139457210111"></a><a name="zh-cn_topic_0000001129943828_p139457210111"></a>设置数据库文件是否备份。默认备份。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001129943828_row897612832918"><td class="cellrowborder" valign="top" width="16.32%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001129943828_p1977152810299"><a name="zh-cn_topic_0000001129943828_p1977152810299"></a><a name="zh-cn_topic_0000001129943828_p1977152810299"></a>autoSync</p>
</td>
<td class="cellrowborder" valign="top" width="20.61%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001129943828_p119771328102918"><a name="zh-cn_topic_0000001129943828_p119771328102918"></a><a name="zh-cn_topic_0000001129943828_p119771328102918"></a>boolean</p>
</td>
<td class="cellrowborder" valign="top" width="10.41%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001129943828_p2977152892910"><a name="zh-cn_topic_0000001129943828_p2977152892910"></a><a name="zh-cn_topic_0000001129943828_p2977152892910"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="52.66%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000001129943828_p997722815297"><a name="zh-cn_topic_0000001129943828_p997722815297"></a><a name="zh-cn_topic_0000001129943828_p997722815297"></a>设置数据库文件是否自动同步。默认自动同步。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001129943828_row13783123212295"><td class="cellrowborder" valign="top" width="16.32%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001129943828_p107838327292"><a name="zh-cn_topic_0000001129943828_p107838327292"></a><a name="zh-cn_topic_0000001129943828_p107838327292"></a>kvStoreType</p>
</td>
<td class="cellrowborder" valign="top" width="20.61%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001129943828_p10783113292916"><a name="zh-cn_topic_0000001129943828_p10783113292916"></a><a name="zh-cn_topic_0000001129943828_p10783113292916"></a><a href="#zh-cn_topic_0000001129943828_section720518449379">KVStoreType</a></p>
</td>
<td class="cellrowborder" valign="top" width="10.41%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001129943828_p5784432182914"><a name="zh-cn_topic_0000001129943828_p5784432182914"></a><a name="zh-cn_topic_0000001129943828_p5784432182914"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="52.66%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000001129943828_p478417326295"><a name="zh-cn_topic_0000001129943828_p478417326295"></a><a name="zh-cn_topic_0000001129943828_p478417326295"></a>设置要创建的数据库类型。默认为多设备协同数据库。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001129943828_row41583015306"><td class="cellrowborder" valign="top" width="16.32%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001129943828_p51583020305"><a name="zh-cn_topic_0000001129943828_p51583020305"></a><a name="zh-cn_topic_0000001129943828_p51583020305"></a>securityLevel</p>
</td>
<td class="cellrowborder" valign="top" width="20.61%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001129943828_p81596014308"><a name="zh-cn_topic_0000001129943828_p81596014308"></a><a name="zh-cn_topic_0000001129943828_p81596014308"></a><a href="#zh-cn_topic_0000001129943828_section205876465372">SecurityLevel</a></p>
</td>
<td class="cellrowborder" valign="top" width="10.41%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001129943828_p181591400305"><a name="zh-cn_topic_0000001129943828_p181591400305"></a><a name="zh-cn_topic_0000001129943828_p181591400305"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="52.66%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000001129943828_p121591808302"><a name="zh-cn_topic_0000001129943828_p121591808302"></a><a name="zh-cn_topic_0000001129943828_p121591808302"></a>设置数据库安全级别。默认不设置安全级别。</p>
</td>
</tr>
</tbody>
</table>

## SyncMode<a name="zh-cn_topic_0000001129943828_section53541759205119"></a>

用于指定同步模式。

<a name="zh-cn_topic_0000001129943828_table8354105916513"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001129943828_row1354105910516"><th class="cellrowborder" valign="top" width="27.900000000000002%" id="mcps1.1.4.1.1"><p id="zh-cn_topic_0000001129943828_p33541759165113"><a name="zh-cn_topic_0000001129943828_p33541759165113"></a><a name="zh-cn_topic_0000001129943828_p33541759165113"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="12.43%" id="mcps1.1.4.1.2"><p id="zh-cn_topic_0000001129943828_p235418596518"><a name="zh-cn_topic_0000001129943828_p235418596518"></a><a name="zh-cn_topic_0000001129943828_p235418596518"></a>默认值</p>
</th>
<th class="cellrowborder" valign="top" width="59.67%" id="mcps1.1.4.1.3"><p id="zh-cn_topic_0000001129943828_p183541159105112"><a name="zh-cn_topic_0000001129943828_p183541159105112"></a><a name="zh-cn_topic_0000001129943828_p183541159105112"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001129943828_row7354175995119"><td class="cellrowborder" valign="top" width="27.900000000000002%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001129943828_p6355155955114"><a name="zh-cn_topic_0000001129943828_p6355155955114"></a><a name="zh-cn_topic_0000001129943828_p6355155955114"></a>PULL_ONLY</p>
</td>
<td class="cellrowborder" valign="top" width="12.43%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001129943828_p10355195935119"><a name="zh-cn_topic_0000001129943828_p10355195935119"></a><a name="zh-cn_topic_0000001129943828_p10355195935119"></a>0</p>
</td>
<td class="cellrowborder" valign="top" width="59.67%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001129943828_p33554599512"><a name="zh-cn_topic_0000001129943828_p33554599512"></a><a name="zh-cn_topic_0000001129943828_p33554599512"></a>表示只能从远端拉取数据到本端。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001129943828_row1035565965119"><td class="cellrowborder" valign="top" width="27.900000000000002%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001129943828_p193147910536"><a name="zh-cn_topic_0000001129943828_p193147910536"></a><a name="zh-cn_topic_0000001129943828_p193147910536"></a>PUSH_ONLY</p>
</td>
<td class="cellrowborder" valign="top" width="12.43%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001129943828_p11355185965112"><a name="zh-cn_topic_0000001129943828_p11355185965112"></a><a name="zh-cn_topic_0000001129943828_p11355185965112"></a>1</p>
</td>
<td class="cellrowborder" valign="top" width="59.67%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001129943828_p143551959205110"><a name="zh-cn_topic_0000001129943828_p143551959205110"></a><a name="zh-cn_topic_0000001129943828_p143551959205110"></a>表示只能从本端推送数据到对端。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001129943828_row935516595516"><td class="cellrowborder" valign="top" width="27.900000000000002%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001129943828_p482031615539"><a name="zh-cn_topic_0000001129943828_p482031615539"></a><a name="zh-cn_topic_0000001129943828_p482031615539"></a>PUSH_PULL</p>
</td>
<td class="cellrowborder" valign="top" width="12.43%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001129943828_p15355145995118"><a name="zh-cn_topic_0000001129943828_p15355145995118"></a><a name="zh-cn_topic_0000001129943828_p15355145995118"></a>2</p>
</td>
<td class="cellrowborder" valign="top" width="59.67%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001129943828_p83561598516"><a name="zh-cn_topic_0000001129943828_p83561598516"></a><a name="zh-cn_topic_0000001129943828_p83561598516"></a>表示从本端推送数据到远端，然后从远端拉取数据到对端。</p>
</td>
</tr>
</tbody>
</table>

## ValueType<a name="zh-cn_topic_0000001129943828_section19236155475512"></a>

用于表示数据类型。

只能被内部应用使用。

<a name="zh-cn_topic_0000001129943828_table1923665410559"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001129943828_row2236185411552"><th class="cellrowborder" valign="top" width="27.900000000000002%" id="mcps1.1.4.1.1"><p id="zh-cn_topic_0000001129943828_p1723755417554"><a name="zh-cn_topic_0000001129943828_p1723755417554"></a><a name="zh-cn_topic_0000001129943828_p1723755417554"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="12.43%" id="mcps1.1.4.1.2"><p id="zh-cn_topic_0000001129943828_p1523745410556"><a name="zh-cn_topic_0000001129943828_p1523745410556"></a><a name="zh-cn_topic_0000001129943828_p1523745410556"></a>默认值</p>
</th>
<th class="cellrowborder" valign="top" width="59.67%" id="mcps1.1.4.1.3"><p id="zh-cn_topic_0000001129943828_p10237454125510"><a name="zh-cn_topic_0000001129943828_p10237454125510"></a><a name="zh-cn_topic_0000001129943828_p10237454125510"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001129943828_row13237165420553"><td class="cellrowborder" valign="top" width="27.900000000000002%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001129943828_p623715475519"><a name="zh-cn_topic_0000001129943828_p623715475519"></a><a name="zh-cn_topic_0000001129943828_p623715475519"></a>STRING</p>
</td>
<td class="cellrowborder" valign="top" width="12.43%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001129943828_p12237125410557"><a name="zh-cn_topic_0000001129943828_p12237125410557"></a><a name="zh-cn_topic_0000001129943828_p12237125410557"></a>0</p>
</td>
<td class="cellrowborder" valign="top" width="59.67%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001129943828_p3237175419556"><a name="zh-cn_topic_0000001129943828_p3237175419556"></a><a name="zh-cn_topic_0000001129943828_p3237175419556"></a>表示值类型为字符串。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001129943828_row16237185419559"><td class="cellrowborder" valign="top" width="27.900000000000002%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001129943828_p202378547551"><a name="zh-cn_topic_0000001129943828_p202378547551"></a><a name="zh-cn_topic_0000001129943828_p202378547551"></a>INTEGER</p>
</td>
<td class="cellrowborder" valign="top" width="12.43%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001129943828_p11238175416559"><a name="zh-cn_topic_0000001129943828_p11238175416559"></a><a name="zh-cn_topic_0000001129943828_p11238175416559"></a>1</p>
</td>
<td class="cellrowborder" valign="top" width="59.67%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001129943828_p2023820548551"><a name="zh-cn_topic_0000001129943828_p2023820548551"></a><a name="zh-cn_topic_0000001129943828_p2023820548551"></a>表示值类型为整数。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001129943828_row1123865425514"><td class="cellrowborder" valign="top" width="27.900000000000002%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001129943828_p122381554145510"><a name="zh-cn_topic_0000001129943828_p122381554145510"></a><a name="zh-cn_topic_0000001129943828_p122381554145510"></a>FLOAT</p>
</td>
<td class="cellrowborder" valign="top" width="12.43%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001129943828_p923819542558"><a name="zh-cn_topic_0000001129943828_p923819542558"></a><a name="zh-cn_topic_0000001129943828_p923819542558"></a>2</p>
</td>
<td class="cellrowborder" valign="top" width="59.67%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001129943828_p17238454105516"><a name="zh-cn_topic_0000001129943828_p17238454105516"></a><a name="zh-cn_topic_0000001129943828_p17238454105516"></a>表示值类型为浮点数。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001129943828_row068212344590"><td class="cellrowborder" valign="top" width="27.900000000000002%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001129943828_p66831534145911"><a name="zh-cn_topic_0000001129943828_p66831534145911"></a><a name="zh-cn_topic_0000001129943828_p66831534145911"></a>BYTE_ARRAY</p>
</td>
<td class="cellrowborder" valign="top" width="12.43%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001129943828_p1768343455917"><a name="zh-cn_topic_0000001129943828_p1768343455917"></a><a name="zh-cn_topic_0000001129943828_p1768343455917"></a>3</p>
</td>
<td class="cellrowborder" valign="top" width="59.67%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001129943828_p1684173416596"><a name="zh-cn_topic_0000001129943828_p1684173416596"></a><a name="zh-cn_topic_0000001129943828_p1684173416596"></a>表示值类型为字节数组。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001129943828_row28813815919"><td class="cellrowborder" valign="top" width="27.900000000000002%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001129943828_p1389123814598"><a name="zh-cn_topic_0000001129943828_p1389123814598"></a><a name="zh-cn_topic_0000001129943828_p1389123814598"></a>BOOLEAN</p>
</td>
<td class="cellrowborder" valign="top" width="12.43%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001129943828_p1089338195918"><a name="zh-cn_topic_0000001129943828_p1089338195918"></a><a name="zh-cn_topic_0000001129943828_p1089338195918"></a>4</p>
</td>
<td class="cellrowborder" valign="top" width="59.67%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001129943828_p589538175910"><a name="zh-cn_topic_0000001129943828_p589538175910"></a><a name="zh-cn_topic_0000001129943828_p589538175910"></a>表示值类型为布尔值。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001129943828_row59211240145919"><td class="cellrowborder" valign="top" width="27.900000000000002%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0000001129943828_p1921114013599"><a name="zh-cn_topic_0000001129943828_p1921114013599"></a><a name="zh-cn_topic_0000001129943828_p1921114013599"></a>DOUBLE</p>
</td>
<td class="cellrowborder" valign="top" width="12.43%" headers="mcps1.1.4.1.2 "><p id="zh-cn_topic_0000001129943828_p1921124018594"><a name="zh-cn_topic_0000001129943828_p1921124018594"></a><a name="zh-cn_topic_0000001129943828_p1921124018594"></a>5</p>
</td>
<td class="cellrowborder" valign="top" width="59.67%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000001129943828_p4921174085915"><a name="zh-cn_topic_0000001129943828_p4921174085915"></a><a name="zh-cn_topic_0000001129943828_p4921174085915"></a>表示值类型为双浮点数。</p>
</td>
</tr>
</tbody>
</table>

## Value<a name="zh-cn_topic_0000001129943828_section12882825611"></a>

存储在数据库中的对象。

<a name="zh-cn_topic_0000001129943828_table1459620431636"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001129943828_row25971143435"><th class="cellrowborder" valign="top" width="15.870000000000001%" id="mcps1.1.6.1.1"><p id="zh-cn_topic_0000001129943828_p1559716434320"><a name="zh-cn_topic_0000001129943828_p1559716434320"></a><a name="zh-cn_topic_0000001129943828_p1559716434320"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="27.029999999999998%" id="mcps1.1.6.1.2"><p id="zh-cn_topic_0000001129943828_p3597743539"><a name="zh-cn_topic_0000001129943828_p3597743539"></a><a name="zh-cn_topic_0000001129943828_p3597743539"></a>参数类型</p>
</th>
<th class="cellrowborder" valign="top" width="7.85%" id="mcps1.1.6.1.3"><p id="zh-cn_topic_0000001129943828_p15971343131"><a name="zh-cn_topic_0000001129943828_p15971343131"></a><a name="zh-cn_topic_0000001129943828_p15971343131"></a>可读</p>
</th>
<th class="cellrowborder" valign="top" width="9.67%" id="mcps1.1.6.1.4"><p id="zh-cn_topic_0000001129943828_p1459715436311"><a name="zh-cn_topic_0000001129943828_p1459715436311"></a><a name="zh-cn_topic_0000001129943828_p1459715436311"></a>可写</p>
</th>
<th class="cellrowborder" valign="top" width="39.58%" id="mcps1.1.6.1.5"><p id="zh-cn_topic_0000001129943828_p75975439316"><a name="zh-cn_topic_0000001129943828_p75975439316"></a><a name="zh-cn_topic_0000001129943828_p75975439316"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001129943828_row95971943839"><td class="cellrowborder" valign="top" width="15.870000000000001%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001129943828_p85976431431"><a name="zh-cn_topic_0000001129943828_p85976431431"></a><a name="zh-cn_topic_0000001129943828_p85976431431"></a>type</p>
</td>
<td class="cellrowborder" valign="top" width="27.029999999999998%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001129943828_p2059710431030"><a name="zh-cn_topic_0000001129943828_p2059710431030"></a><a name="zh-cn_topic_0000001129943828_p2059710431030"></a><a href="#zh-cn_topic_0000001129943828_section19236155475512">ValueType</a></p>
</td>
<td class="cellrowborder" valign="top" width="7.85%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001129943828_p1059711439317"><a name="zh-cn_topic_0000001129943828_p1059711439317"></a><a name="zh-cn_topic_0000001129943828_p1059711439317"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="9.67%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001129943828_p659715430317"><a name="zh-cn_topic_0000001129943828_p659715430317"></a><a name="zh-cn_topic_0000001129943828_p659715430317"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="39.58%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001129943828_p2059719436313"><a name="zh-cn_topic_0000001129943828_p2059719436313"></a><a name="zh-cn_topic_0000001129943828_p2059719436313"></a>值类型。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001129943828_row185973435316"><td class="cellrowborder" valign="top" width="15.870000000000001%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001129943828_p1559710432310"><a name="zh-cn_topic_0000001129943828_p1559710432310"></a><a name="zh-cn_topic_0000001129943828_p1559710432310"></a>value</p>
</td>
<td class="cellrowborder" valign="top" width="27.029999999999998%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001129943828_p16597144318312"><a name="zh-cn_topic_0000001129943828_p16597144318312"></a><a name="zh-cn_topic_0000001129943828_p16597144318312"></a>Uint8Array | string | number | boolean</p>
</td>
<td class="cellrowborder" valign="top" width="7.85%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001129943828_p12597194313317"><a name="zh-cn_topic_0000001129943828_p12597194313317"></a><a name="zh-cn_topic_0000001129943828_p12597194313317"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="9.67%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001129943828_p1259710431236"><a name="zh-cn_topic_0000001129943828_p1259710431236"></a><a name="zh-cn_topic_0000001129943828_p1259710431236"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="39.58%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001129943828_p10597843034"><a name="zh-cn_topic_0000001129943828_p10597843034"></a><a name="zh-cn_topic_0000001129943828_p10597843034"></a>返回值。Uint8Array的长度小于4MB。</p>
</td>
</tr>
</tbody>
</table>

## Entry<a name="zh-cn_topic_0000001129943828_section1467716175115"></a>

表示存储在分布式数据库中的键值对。

<a name="zh-cn_topic_0000001129943828_table1678101205113"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001129943828_row11678161175117"><th class="cellrowborder" valign="top" width="15.870000000000001%" id="mcps1.1.6.1.1"><p id="zh-cn_topic_0000001129943828_p106785111512"><a name="zh-cn_topic_0000001129943828_p106785111512"></a><a name="zh-cn_topic_0000001129943828_p106785111512"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="27.029999999999998%" id="mcps1.1.6.1.2"><p id="zh-cn_topic_0000001129943828_p1567817115512"><a name="zh-cn_topic_0000001129943828_p1567817115512"></a><a name="zh-cn_topic_0000001129943828_p1567817115512"></a>参数类型</p>
</th>
<th class="cellrowborder" valign="top" width="7.85%" id="mcps1.1.6.1.3"><p id="zh-cn_topic_0000001129943828_p1678101125110"><a name="zh-cn_topic_0000001129943828_p1678101125110"></a><a name="zh-cn_topic_0000001129943828_p1678101125110"></a>可读</p>
</th>
<th class="cellrowborder" valign="top" width="9.67%" id="mcps1.1.6.1.4"><p id="zh-cn_topic_0000001129943828_p1767831195117"><a name="zh-cn_topic_0000001129943828_p1767831195117"></a><a name="zh-cn_topic_0000001129943828_p1767831195117"></a>可写</p>
</th>
<th class="cellrowborder" valign="top" width="39.58%" id="mcps1.1.6.1.5"><p id="zh-cn_topic_0000001129943828_p196786118515"><a name="zh-cn_topic_0000001129943828_p196786118515"></a><a name="zh-cn_topic_0000001129943828_p196786118515"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001129943828_row1667919113510"><td class="cellrowborder" valign="top" width="15.870000000000001%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001129943828_p1632904315112"><a name="zh-cn_topic_0000001129943828_p1632904315112"></a><a name="zh-cn_topic_0000001129943828_p1632904315112"></a>key</p>
</td>
<td class="cellrowborder" valign="top" width="27.029999999999998%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001129943828_p7679111185111"><a name="zh-cn_topic_0000001129943828_p7679111185111"></a><a name="zh-cn_topic_0000001129943828_p7679111185111"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="7.85%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001129943828_p136792135115"><a name="zh-cn_topic_0000001129943828_p136792135115"></a><a name="zh-cn_topic_0000001129943828_p136792135115"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="9.67%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001129943828_p186799120516"><a name="zh-cn_topic_0000001129943828_p186799120516"></a><a name="zh-cn_topic_0000001129943828_p186799120516"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="39.58%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001129943828_p26792013514"><a name="zh-cn_topic_0000001129943828_p26792013514"></a><a name="zh-cn_topic_0000001129943828_p26792013514"></a>键值。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001129943828_row267931185113"><td class="cellrowborder" valign="top" width="15.870000000000001%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001129943828_p867951145114"><a name="zh-cn_topic_0000001129943828_p867951145114"></a><a name="zh-cn_topic_0000001129943828_p867951145114"></a>value</p>
</td>
<td class="cellrowborder" valign="top" width="27.029999999999998%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001129943828_p86791318519"><a name="zh-cn_topic_0000001129943828_p86791318519"></a><a name="zh-cn_topic_0000001129943828_p86791318519"></a><a href="#zh-cn_topic_0000001129943828_section12882825611">Value</a></p>
</td>
<td class="cellrowborder" valign="top" width="7.85%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001129943828_p14679181175114"><a name="zh-cn_topic_0000001129943828_p14679181175114"></a><a name="zh-cn_topic_0000001129943828_p14679181175114"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="9.67%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001129943828_p16797195110"><a name="zh-cn_topic_0000001129943828_p16797195110"></a><a name="zh-cn_topic_0000001129943828_p16797195110"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="39.58%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001129943828_p166791011516"><a name="zh-cn_topic_0000001129943828_p166791011516"></a><a name="zh-cn_topic_0000001129943828_p166791011516"></a>值对象。</p>
</td>
</tr>
</tbody>
</table>

## ChangeNotification<a name="zh-cn_topic_0000001129943828_section9868357105716"></a>

数据变更时通知的对象，包括数据插入、更新和删除。

<a name="zh-cn_topic_0000001129943828_table78681657195717"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001129943828_row138681857165718"><th class="cellrowborder" valign="top" width="15.870000000000001%" id="mcps1.1.6.1.1"><p id="zh-cn_topic_0000001129943828_p0868205785716"><a name="zh-cn_topic_0000001129943828_p0868205785716"></a><a name="zh-cn_topic_0000001129943828_p0868205785716"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="27.029999999999998%" id="mcps1.1.6.1.2"><p id="zh-cn_topic_0000001129943828_p2086805735714"><a name="zh-cn_topic_0000001129943828_p2086805735714"></a><a name="zh-cn_topic_0000001129943828_p2086805735714"></a>参数类型</p>
</th>
<th class="cellrowborder" valign="top" width="7.85%" id="mcps1.1.6.1.3"><p id="zh-cn_topic_0000001129943828_p13869145775710"><a name="zh-cn_topic_0000001129943828_p13869145775710"></a><a name="zh-cn_topic_0000001129943828_p13869145775710"></a>可读</p>
</th>
<th class="cellrowborder" valign="top" width="9.67%" id="mcps1.1.6.1.4"><p id="zh-cn_topic_0000001129943828_p1886919575575"><a name="zh-cn_topic_0000001129943828_p1886919575575"></a><a name="zh-cn_topic_0000001129943828_p1886919575575"></a>可写</p>
</th>
<th class="cellrowborder" valign="top" width="39.58%" id="mcps1.1.6.1.5"><p id="zh-cn_topic_0000001129943828_p9869175715718"><a name="zh-cn_topic_0000001129943828_p9869175715718"></a><a name="zh-cn_topic_0000001129943828_p9869175715718"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001129943828_row7869155795710"><td class="cellrowborder" valign="top" width="15.870000000000001%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001129943828_p81594559583"><a name="zh-cn_topic_0000001129943828_p81594559583"></a><a name="zh-cn_topic_0000001129943828_p81594559583"></a>insertEntries</p>
</td>
<td class="cellrowborder" valign="top" width="27.029999999999998%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001129943828_p3869457195712"><a name="zh-cn_topic_0000001129943828_p3869457195712"></a><a name="zh-cn_topic_0000001129943828_p3869457195712"></a><a href="#zh-cn_topic_0000001129943828_section1467716175115">Entry</a>[]</p>
</td>
<td class="cellrowborder" valign="top" width="7.85%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001129943828_p6869115735719"><a name="zh-cn_topic_0000001129943828_p6869115735719"></a><a name="zh-cn_topic_0000001129943828_p6869115735719"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="9.67%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001129943828_p286925765713"><a name="zh-cn_topic_0000001129943828_p286925765713"></a><a name="zh-cn_topic_0000001129943828_p286925765713"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="39.58%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001129943828_p188701857135710"><a name="zh-cn_topic_0000001129943828_p188701857135710"></a><a name="zh-cn_topic_0000001129943828_p188701857135710"></a>数据添加记录。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001129943828_row787019578574"><td class="cellrowborder" valign="top" width="15.870000000000001%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001129943828_p1287045745715"><a name="zh-cn_topic_0000001129943828_p1287045745715"></a><a name="zh-cn_topic_0000001129943828_p1287045745715"></a>updateEntries</p>
</td>
<td class="cellrowborder" valign="top" width="27.029999999999998%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001129943828_p5212185939"><a name="zh-cn_topic_0000001129943828_p5212185939"></a><a name="zh-cn_topic_0000001129943828_p5212185939"></a><a href="#zh-cn_topic_0000001129943828_section1467716175115">Entry</a>[]</p>
</td>
<td class="cellrowborder" valign="top" width="7.85%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001129943828_p1087045713577"><a name="zh-cn_topic_0000001129943828_p1087045713577"></a><a name="zh-cn_topic_0000001129943828_p1087045713577"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="9.67%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001129943828_p1487035713575"><a name="zh-cn_topic_0000001129943828_p1487035713575"></a><a name="zh-cn_topic_0000001129943828_p1487035713575"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="39.58%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001129943828_p3870145711570"><a name="zh-cn_topic_0000001129943828_p3870145711570"></a><a name="zh-cn_topic_0000001129943828_p3870145711570"></a>数据更新记录。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001129943828_row18863111108"><td class="cellrowborder" valign="top" width="15.870000000000001%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001129943828_p18864111506"><a name="zh-cn_topic_0000001129943828_p18864111506"></a><a name="zh-cn_topic_0000001129943828_p18864111506"></a>deleteEntries</p>
</td>
<td class="cellrowborder" valign="top" width="27.029999999999998%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001129943828_p13119713317"><a name="zh-cn_topic_0000001129943828_p13119713317"></a><a name="zh-cn_topic_0000001129943828_p13119713317"></a><a href="#zh-cn_topic_0000001129943828_section1467716175115">Entry</a>[]</p>
</td>
<td class="cellrowborder" valign="top" width="7.85%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001129943828_p48641111301"><a name="zh-cn_topic_0000001129943828_p48641111301"></a><a name="zh-cn_topic_0000001129943828_p48641111301"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="9.67%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001129943828_p1864617019"><a name="zh-cn_topic_0000001129943828_p1864617019"></a><a name="zh-cn_topic_0000001129943828_p1864617019"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="39.58%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001129943828_p2864414014"><a name="zh-cn_topic_0000001129943828_p2864414014"></a><a name="zh-cn_topic_0000001129943828_p2864414014"></a>数据删除记录。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001129943828_row79531857013"><td class="cellrowborder" valign="top" width="15.870000000000001%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001129943828_p0953151013"><a name="zh-cn_topic_0000001129943828_p0953151013"></a><a name="zh-cn_topic_0000001129943828_p0953151013"></a>deviceId</p>
</td>
<td class="cellrowborder" valign="top" width="27.029999999999998%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001129943828_p1953451208"><a name="zh-cn_topic_0000001129943828_p1953451208"></a><a name="zh-cn_topic_0000001129943828_p1953451208"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="7.85%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001129943828_p169541959012"><a name="zh-cn_topic_0000001129943828_p169541959012"></a><a name="zh-cn_topic_0000001129943828_p169541959012"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="9.67%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001129943828_p295485903"><a name="zh-cn_topic_0000001129943828_p295485903"></a><a name="zh-cn_topic_0000001129943828_p295485903"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="39.58%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001129943828_p109541451017"><a name="zh-cn_topic_0000001129943828_p109541451017"></a><a name="zh-cn_topic_0000001129943828_p109541451017"></a>设备ID。此处为设备UUID。</p>
</td>
</tr>
</tbody>
</table>

