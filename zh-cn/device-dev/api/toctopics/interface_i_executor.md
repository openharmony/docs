# IExecutor<a name="ZH-CN_TOPIC_0000001343000865"></a>

## **概述**<a name="section469037295083932"></a>

**所属模块:**

[HdfFaceAuth](_hdf_face_auth.md)  |  [HdfPinAuth](_hdf_pin_auth.md)

## **汇总**<a name="section1144202075083932"></a>

## Public 成员函数<a name="pub-methods"></a>

<a name="table5164944083932"></a>
<table><thead align="left"><tr id="row1858843643083932"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p879439741083932"><a name="p879439741083932"></a><a name="p879439741083932"></a>Public 成员函数</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1039543774083932"><a name="p1039543774083932"></a><a name="p1039543774083932"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row1526233198083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1502012440083932"><a name="p1502012440083932"></a><a name="p1502012440083932"></a><a href="interface_i_executor.md#a8a6851061e68784ea43519184c8bf3a2">GetExecutorInfo</a> ([out] struct <a href="_executor_info.md">ExecutorInfo</a> executorInfo)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p47147484083932"><a name="p47147484083932"></a><a name="p47147484083932"></a>获取执行器信息，人脸认证服务将执行器注册到用户认证框架时需要通过该接口获取对应信息。 <a href="interface_i_executor.md#a8a6851061e68784ea43519184c8bf3a2">更多...</a></p>
</td>
</tr>
<tr id="row1498290190083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1835611819083932"><a name="p1835611819083932"></a><a name="p1835611819083932"></a><a href="interface_i_executor.md#afef283a8ebb3c5512ed7bc2e6b0160c2">GetTemplateInfo</a> ([in] unsigned long templateId, [out] struct <a href="_template_info.md">TemplateInfo</a> templateInfo)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p234930513083932"><a name="p234930513083932"></a><a name="p234930513083932"></a>获取凭据模版信息。 <a href="interface_i_executor.md#afef283a8ebb3c5512ed7bc2e6b0160c2">更多...</a></p>
</td>
</tr>
<tr id="row716075603083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1052122336083932"><a name="p1052122336083932"></a><a name="p1052122336083932"></a><a href="interface_i_executor.md#a86914f3f155246747b2c536fd8633cec">OnRegisterFinish</a> ([in] unsigned long[] templateIdList, [in] unsigned char[] frameworkPublicKey, [in] unsigned char[] extraInfo)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p783335380083932"><a name="p783335380083932"></a><a name="p783335380083932"></a>完成执行器注册，对人脸特征模版进行对账，用于删除无效的人脸特征模板及相关信息。 <a href="interface_i_executor.md#a86914f3f155246747b2c536fd8633cec">更多...</a></p>
</td>
</tr>
<tr id="row840907127083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1605863122083932"><a name="p1605863122083932"></a><a name="p1605863122083932"></a><a href="interface_i_executor.md#ab27db4e9e8b470f437530cdad965f430">Enroll</a> ([in] unsigned long scheduleId, [in] unsigned char[] extraInfo, [in] <a href="interface_i_executor_callback.md">IExecutorCallback</a> callbackObj)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p364530187083932"><a name="p364530187083932"></a><a name="p364530187083932"></a>注册人脸特征模版。 <a href="interface_i_executor.md#ab27db4e9e8b470f437530cdad965f430">更多...</a></p>
</td>
</tr>
<tr id="row1597541111083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2109898685083932"><a name="p2109898685083932"></a><a name="p2109898685083932"></a><a href="interface_i_executor.md#a204eacb0141b31c6cbbcc578886595cf">Authenticate</a> ([in] unsigned long scheduleId, [in] unsigned long[] templateIdList, [in] unsigned char[] extraInfo, [in] <a href="interface_i_executor_callback.md">IExecutorCallback</a> callbackObj)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p105626878083932"><a name="p105626878083932"></a><a name="p105626878083932"></a>人脸认证。 <a href="interface_i_executor.md#a204eacb0141b31c6cbbcc578886595cf">更多...</a></p>
</td>
</tr>
<tr id="row1709937903083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p172434695083932"><a name="p172434695083932"></a><a name="p172434695083932"></a><a href="interface_i_executor.md#a3d236bdeee52e5ae4d60683d07bdad98">Identify</a> ([in] unsigned long scheduleId, [in] unsigned char[] extraInfo, [in] <a href="interface_i_executor_callback.md">IExecutorCallback</a> callbackObj)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p911986026083932"><a name="p911986026083932"></a><a name="p911986026083932"></a>人脸识别。 <a href="interface_i_executor.md#a3d236bdeee52e5ae4d60683d07bdad98">更多...</a></p>
</td>
</tr>
<tr id="row233286453083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1243998181083932"><a name="p1243998181083932"></a><a name="p1243998181083932"></a><a href="interface_i_executor.md#a1ab39256fcee3704cba74e8241ffb2e8">Delete</a> ([in] unsigned long[] templateIdList)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p175309620083932"><a name="p175309620083932"></a><a name="p175309620083932"></a>删除人脸特征模版。 <a href="interface_i_executor.md#a1ab39256fcee3704cba74e8241ffb2e8">更多...</a></p>
</td>
</tr>
<tr id="row499781434083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1154687884083932"><a name="p1154687884083932"></a><a name="p1154687884083932"></a><a href="interface_i_executor.md#a5f73507fe8466f49c3c136432baae364">Cancel</a> ([in] unsigned long scheduleId)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p52558301083932"><a name="p52558301083932"></a><a name="p52558301083932"></a>取消操作请求。 <a href="interface_i_executor.md#a5f73507fe8466f49c3c136432baae364">更多...</a></p>
</td>
</tr>
<tr id="row1222668836083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1924029272083932"><a name="p1924029272083932"></a><a name="p1924029272083932"></a><a href="interface_i_executor.md#ad7ef470c0a6902e445e5574aaf3ff5c8">SendCommand</a> ([in] int commandId, [in] unsigned char[] extraInfo, [in] <a href="interface_i_executor_callback.md">IExecutorCallback</a> callbackObj)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2047309509083932"><a name="p2047309509083932"></a><a name="p2047309509083932"></a>发送人脸认证功能相关操作命令。 <a href="interface_i_executor.md#ad7ef470c0a6902e445e5574aaf3ff5c8">更多...</a></p>
</td>
</tr>
<tr id="row219347005083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1117032525083932"><a name="p1117032525083932"></a><a name="p1117032525083932"></a><a href="interface_i_executor.md#a8a6851061e68784ea43519184c8bf3a3">GetExecutorInfo</a> ([out] struct <a href="_executor_info.md">ExecutorInfo</a> executorInfo)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2043536704083932"><a name="p2043536704083932"></a><a name="p2043536704083932"></a>获取执行器信息，口令认证服务将执行器注册到用户认证框架时需要通过该接口获取对应信息。 <a href="interface_i_executor.md#a8a6851061e68784ea43519184c8bf3a3">更多...</a></p>
</td>
</tr>
<tr id="row4052530083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p895041056083932"><a name="p895041056083932"></a><a name="p895041056083932"></a><a href="interface_i_executor.md#a86914f3f155246747b2c536fd8633ced">OnRegisterFinish</a> ([in] unsigned long[] templateIdList, [in] unsigned char[] frameworkPublicKey, [in] unsigned char[] extraInfo)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1810869097083932"><a name="p1810869097083932"></a><a name="p1810869097083932"></a>完成执行器注册，对口令模版信息进行对账，用于删除无效的口令模板及相关信息。 <a href="interface_i_executor.md#a86914f3f155246747b2c536fd8633ced">更多...</a></p>
</td>
</tr>
<tr id="row461080624083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1728410182083932"><a name="p1728410182083932"></a><a name="p1728410182083932"></a><a href="interface_i_executor.md#a693ddb05b172ed09b8c9d699960528c4">OnSetData</a> ([in] unsigned long scheduleId, [in] unsigned long authSubType, [in] unsigned char[] data)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p274994463083932"><a name="p274994463083932"></a><a name="p274994463083932"></a>设置口令数据，口令认证驱动处理注册或认证口令请求时，如果口令数据由口令认证服务获取，需要通过该接口将口令数据传给口令认证驱动。 <a href="interface_i_executor.md#a693ddb05b172ed09b8c9d699960528c4">更多...</a></p>
</td>
</tr>
<tr id="row1726425044083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2112925662083932"><a name="p2112925662083932"></a><a name="p2112925662083932"></a><a href="interface_i_executor.md#ab27db4e9e8b470f437530cdad965f431">Enroll</a> ([in] unsigned long scheduleId, [in] unsigned char[] extraInfo, [in] <a href="interface_i_executor_callback.md">IExecutorCallback</a> callbackObj)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p33670915083932"><a name="p33670915083932"></a><a name="p33670915083932"></a>注册口令。 <a href="interface_i_executor.md#ab27db4e9e8b470f437530cdad965f431">更多...</a></p>
</td>
</tr>
<tr id="row1220923898083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p929759292083932"><a name="p929759292083932"></a><a name="p929759292083932"></a><a href="interface_i_executor.md#ad041b9539730632eab9357bb272e499d">Authenticate</a> ([in] unsigned long scheduleId, [in] unsigned long templateId, [in] unsigned char[] extraInfo, [in] <a href="interface_i_executor_callback.md">IExecutorCallback</a> callbackObj)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1433265728083932"><a name="p1433265728083932"></a><a name="p1433265728083932"></a>认证口令。 <a href="interface_i_executor.md#ad041b9539730632eab9357bb272e499d">更多...</a></p>
</td>
</tr>
<tr id="row1331273288083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p411290291083932"><a name="p411290291083932"></a><a name="p411290291083932"></a><a href="interface_i_executor.md#ace3654793e82fa026fcecd87da10906a">Delete</a> ([in] unsigned long templateId)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p584914108083932"><a name="p584914108083932"></a><a name="p584914108083932"></a>删除口令。 <a href="interface_i_executor.md#ace3654793e82fa026fcecd87da10906a">更多...</a></p>
</td>
</tr>
<tr id="row1079643151083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p312019652083932"><a name="p312019652083932"></a><a name="p312019652083932"></a><a href="interface_i_executor.md#ad7ef470c0a6902e445e5574aaf3ff5c9">SendCommand</a> ([in] int commandId, [in] unsigned char[] extraInfo, [in] <a href="interface_i_executor_callback.md">IExecutorCallback</a> callbackObj)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1520997717083932"><a name="p1520997717083932"></a><a name="p1520997717083932"></a>发送口令认证功能相关操作命令。 <a href="interface_i_executor.md#ad7ef470c0a6902e445e5574aaf3ff5c9">更多...</a></p>
</td>
</tr>
</tbody>
</table>

## **详细描述**<a name="section1143581881083932"></a>

定义执行器标准API接口。接口可用于：

-   获取执行器信息。
-   获取凭据模版信息。
-   注册人脸特征模版，进行用户人脸认证，删除人脸特征模版等。
-   注册口令，认证口令，删除口令等。

**Since：**

3.2

**Version:**

1.0

## **成员函数说明**<a name="section467481822083932"></a>

## Authenticate\(\) \[1/2\]<a name="ad041b9539730632eab9357bb272e499d"></a>

```
IExecutor::Authenticate ([in] unsigned long scheduleId, [in] unsigned long templateId, [in] unsigned char[] extraInfo, [in] IExecutorCallback callbackObj )
```

**描述：**

认证口令。

**参数：**

<a name="table1837709003083932"></a>
<table><thead align="left"><tr id="row1338618940083932"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p587319778083932"><a name="p587319778083932"></a><a name="p587319778083932"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p522052830083932"><a name="p522052830083932"></a><a name="p522052830083932"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row1642328794083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry296276268083932p0"><a name="entry296276268083932p0"></a><a name="entry296276268083932p0"></a>scheduleId</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1213568136083932p0"><a name="entry1213568136083932p0"></a><a name="entry1213568136083932p0"></a>调度ID，用于标识一次操作请求的调度过程。</p>
</td>
</tr>
<tr id="row1630034988083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry171849795083932p0"><a name="entry171849795083932p0"></a><a name="entry171849795083932p0"></a>templateId</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry218920481083932p0"><a name="entry218920481083932p0"></a><a name="entry218920481083932p0"></a>指定要认证的模版ID。</p>
</td>
</tr>
<tr id="row1089773734083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1522472763083932p0"><a name="entry1522472763083932p0"></a><a name="entry1522472763083932p0"></a>extraInfo</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry529776366083932p0"><a name="entry529776366083932p0"></a><a name="entry529776366083932p0"></a>其他相关信息，用于支持信息扩展。</p>
</td>
</tr>
<tr id="row1487084190083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry174380030083932p0"><a name="entry174380030083932p0"></a><a name="entry174380030083932p0"></a>callbackObj</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1277166372083932p0"><a name="entry1277166372083932p0"></a><a name="entry1277166372083932p0"></a>回调对象<a href="interface_i_executor_callback.md">IExecutorCallback</a>。</p>
</td>
</tr>
</tbody>
</table>

**返回：**

0 表示操作成功。

非0 表示操作失败。

## Authenticate\(\) \[2/2\]<a name="a204eacb0141b31c6cbbcc578886595cf"></a>

```
IExecutor::Authenticate ([in] unsigned long scheduleId, [in] unsigned long[] templateIdList, [in] unsigned char[] extraInfo, [in] IExecutorCallback callbackObj )
```

**描述：**

人脸认证。

**参数：**

<a name="table1637414952083932"></a>
<table><thead align="left"><tr id="row1515112765083932"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1961880662083932"><a name="p1961880662083932"></a><a name="p1961880662083932"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p927412770083932"><a name="p927412770083932"></a><a name="p927412770083932"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row1227163092083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1199433968083932p0"><a name="entry1199433968083932p0"></a><a name="entry1199433968083932p0"></a>scheduleId</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry402203013083932p0"><a name="entry402203013083932p0"></a><a name="entry402203013083932p0"></a>调度ID，用于标识一次操作请求的调度过程。</p>
</td>
</tr>
<tr id="row1585561937083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry554602625083932p0"><a name="entry554602625083932p0"></a><a name="entry554602625083932p0"></a>templateIdList</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry355784982083932p0"><a name="entry355784982083932p0"></a><a name="entry355784982083932p0"></a>指定要认证的模版ID列表。</p>
</td>
</tr>
<tr id="row279970572083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1140911406083932p0"><a name="entry1140911406083932p0"></a><a name="entry1140911406083932p0"></a>extraInfo</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1246762441083932p0"><a name="entry1246762441083932p0"></a><a name="entry1246762441083932p0"></a>其他相关信息，用于支持信息扩展。</p>
</td>
</tr>
<tr id="row423766018083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry352819731083932p0"><a name="entry352819731083932p0"></a><a name="entry352819731083932p0"></a>callbackObj</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1131987098083932p0"><a name="entry1131987098083932p0"></a><a name="entry1131987098083932p0"></a>回调对象<a href="interface_i_executor_callback.md">IExecutorCallback</a>。</p>
</td>
</tr>
</tbody>
</table>

**返回：**

0 表示操作成功。

非0 表示操作失败。

## Cancel\(\)<a name="a5f73507fe8466f49c3c136432baae364"></a>

```
IExecutor::Cancel ([in] unsigned long scheduleId)
```

**描述：**

取消操作请求。

**参数：**

<a name="table1991809266083932"></a>
<table><thead align="left"><tr id="row1434739451083932"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p553403003083932"><a name="p553403003083932"></a><a name="p553403003083932"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1074437084083932"><a name="p1074437084083932"></a><a name="p1074437084083932"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row1561249518083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1229873896083932p0"><a name="entry1229873896083932p0"></a><a name="entry1229873896083932p0"></a>scheduleId</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1276980634083932p0"><a name="entry1276980634083932p0"></a><a name="entry1276980634083932p0"></a>调度ID，用于标识一次操作请求的调度过程。</p>
</td>
</tr>
</tbody>
</table>

**返回：**

0 表示操作成功。

非0 表示操作失败。

## Delete\(\) \[1/2\]<a name="ace3654793e82fa026fcecd87da10906a"></a>

```
IExecutor::Delete ([in] unsigned long templateId)
```

**描述：**

删除口令。

**参数：**

<a name="table282907124083932"></a>
<table><thead align="left"><tr id="row1497978969083932"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p497865946083932"><a name="p497865946083932"></a><a name="p497865946083932"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1866796295083932"><a name="p1866796295083932"></a><a name="p1866796295083932"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row1203300347083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry13821758083932p0"><a name="entry13821758083932p0"></a><a name="entry13821758083932p0"></a>templateId</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1159299670083932p0"><a name="entry1159299670083932p0"></a><a name="entry1159299670083932p0"></a>模版ID。</p>
</td>
</tr>
</tbody>
</table>

**返回：**

0 表示操作成功。

非0 表示操作失败。

## Delete\(\) \[2/2\]<a name="a1ab39256fcee3704cba74e8241ffb2e8"></a>

```
IExecutor::Delete ([in] unsigned long[] templateIdList)
```

**描述：**

删除人脸特征模版。

**参数：**

<a name="table322318137083932"></a>
<table><thead align="left"><tr id="row687356778083932"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p977570184083932"><a name="p977570184083932"></a><a name="p977570184083932"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p422932379083932"><a name="p422932379083932"></a><a name="p422932379083932"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row1009063150083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry249490758083932p0"><a name="entry249490758083932p0"></a><a name="entry249490758083932p0"></a>templateIdList</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1736846506083932p0"><a name="entry1736846506083932p0"></a><a name="entry1736846506083932p0"></a>指定要删除的模版ID列表。</p>
</td>
</tr>
</tbody>
</table>

**返回：**

0 表示操作成功。

非0 表示操作失败。

## Enroll\(\) \[1/2\]<a name="ab27db4e9e8b470f437530cdad965f430"></a>

```
IExecutor::Enroll ([in] unsigned long scheduleId, [in] unsigned char[] extraInfo, [in] IExecutorCallback callbackObj )
```

**描述：**

注册人脸特征模版。

**参数：**

<a name="table18685495083932"></a>
<table><thead align="left"><tr id="row1287766736083932"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1192142581083932"><a name="p1192142581083932"></a><a name="p1192142581083932"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1514241933083932"><a name="p1514241933083932"></a><a name="p1514241933083932"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row112641424083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1473937372083932p0"><a name="entry1473937372083932p0"></a><a name="entry1473937372083932p0"></a>scheduleId</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1513975808083932p0"><a name="entry1513975808083932p0"></a><a name="entry1513975808083932p0"></a>调度ID，用于标识一次操作请求的调度过程。</p>
</td>
</tr>
<tr id="row1849102979083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry525915306083932p0"><a name="entry525915306083932p0"></a><a name="entry525915306083932p0"></a>extraInfo</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry2041579613083932p0"><a name="entry2041579613083932p0"></a><a name="entry2041579613083932p0"></a>其他相关信息，用于支持信息扩展。</p>
</td>
</tr>
<tr id="row1986118196083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry2028653387083932p0"><a name="entry2028653387083932p0"></a><a name="entry2028653387083932p0"></a>callbackObj</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry55659147083932p0"><a name="entry55659147083932p0"></a><a name="entry55659147083932p0"></a>回调对象<a href="interface_i_executor_callback.md">IExecutorCallback</a>。</p>
</td>
</tr>
</tbody>
</table>

**返回：**

0 表示操作成功。

非0 表示操作失败。

## Enroll\(\) \[2/2\]<a name="ab27db4e9e8b470f437530cdad965f431"></a>

```
IExecutor::Enroll ([in] unsigned long scheduleId, [in] unsigned char[] extraInfo, [in] IExecutorCallback callbackObj )
```

**描述：**

注册口令。

**参数：**

<a name="table885897900083932"></a>
<table><thead align="left"><tr id="row988557899083932"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1991050707083932"><a name="p1991050707083932"></a><a name="p1991050707083932"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p69503568083932"><a name="p69503568083932"></a><a name="p69503568083932"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row1764514060083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1241131123083932p0"><a name="entry1241131123083932p0"></a><a name="entry1241131123083932p0"></a>scheduleId</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1854532679083932p0"><a name="entry1854532679083932p0"></a><a name="entry1854532679083932p0"></a>调度ID，用于标识一次操作请求的调度过程。</p>
</td>
</tr>
<tr id="row2110208460083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1772534686083932p0"><a name="entry1772534686083932p0"></a><a name="entry1772534686083932p0"></a>extraInfo</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry473671603083932p0"><a name="entry473671603083932p0"></a><a name="entry473671603083932p0"></a>其他相关信息，用于支持信息扩展。</p>
</td>
</tr>
<tr id="row80797290083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry685320840083932p0"><a name="entry685320840083932p0"></a><a name="entry685320840083932p0"></a>callbackObj</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry102933601083932p0"><a name="entry102933601083932p0"></a><a name="entry102933601083932p0"></a>回调对象<a href="interface_i_executor_callback.md">IExecutorCallback</a>。</p>
</td>
</tr>
</tbody>
</table>

**返回：**

0 表示操作成功。

非0 表示操作失败。

## GetExecutorInfo\(\) \[1/2\]<a name="a8a6851061e68784ea43519184c8bf3a2"></a>

```
IExecutor::GetExecutorInfo ([out] struct ExecutorInfo executorInfo)
```

**描述：**

获取执行器信息，人脸认证服务将执行器注册到用户认证框架时需要通过该接口获取对应信息。

**参数：**

<a name="table1330177223083932"></a>
<table><thead align="left"><tr id="row747107360083932"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p542729965083932"><a name="p542729965083932"></a><a name="p542729965083932"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p834614609083932"><a name="p834614609083932"></a><a name="p834614609083932"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row1741384528083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry790024005083932p0"><a name="entry790024005083932p0"></a><a name="entry790024005083932p0"></a>executorInfo</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry2049438117083932p0"><a name="entry2049438117083932p0"></a><a name="entry2049438117083932p0"></a>执行器信息<a href="_executor_info.md">ExecutorInfo</a>。</p>
</td>
</tr>
</tbody>
</table>

**返回：**

0 表示操作成功。

非0 表示操作失败。

## GetExecutorInfo\(\) \[2/2\]<a name="a8a6851061e68784ea43519184c8bf3a3"></a>

```
IExecutor::GetExecutorInfo ([out] struct ExecutorInfo executorInfo)
```

**描述：**

获取执行器信息，口令认证服务将执行器注册到用户认证框架时需要通过该接口获取对应信息。

**参数：**

<a name="table1580958059083932"></a>
<table><thead align="left"><tr id="row1572625599083932"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1212067862083932"><a name="p1212067862083932"></a><a name="p1212067862083932"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1976475429083932"><a name="p1976475429083932"></a><a name="p1976475429083932"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row1074965513083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1101280409083932p0"><a name="entry1101280409083932p0"></a><a name="entry1101280409083932p0"></a>executorInfo</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry638393926083932p0"><a name="entry638393926083932p0"></a><a name="entry638393926083932p0"></a>执行器信息<a href="_executor_info.md">ExecutorInfo</a>。</p>
</td>
</tr>
</tbody>
</table>

**返回：**

0 表示操作成功。

非0 表示操作失败。

## GetTemplateInfo\(\)<a name="afef283a8ebb3c5512ed7bc2e6b0160c2"></a>

```
IExecutor::GetTemplateInfo ([in] unsigned long templateId, [out] struct TemplateInfo templateInfo )
```

**描述：**

获取凭据模版信息。

**参数：**

<a name="table670258763083932"></a>
<table><thead align="left"><tr id="row150737522083932"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1659573005083932"><a name="p1659573005083932"></a><a name="p1659573005083932"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1105414243083932"><a name="p1105414243083932"></a><a name="p1105414243083932"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row738572415083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry2013158860083932p0"><a name="entry2013158860083932p0"></a><a name="entry2013158860083932p0"></a>templateId</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry325846509083932p0"><a name="entry325846509083932p0"></a><a name="entry325846509083932p0"></a>凭据模版ID。</p>
</td>
</tr>
<tr id="row389987851083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry687683598083932p0"><a name="entry687683598083932p0"></a><a name="entry687683598083932p0"></a>templateInfo</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry363185966083932p0"><a name="entry363185966083932p0"></a><a name="entry363185966083932p0"></a>凭据模版信息<a href="_template_info.md">TemplateInfo</a>。</p>
</td>
</tr>
</tbody>
</table>

**返回：**

0 表示操作成功。

非0 表示操作失败。

## Identify\(\)<a name="a3d236bdeee52e5ae4d60683d07bdad98"></a>

```
IExecutor::Identify ([in] unsigned long scheduleId, [in] unsigned char[] extraInfo, [in] IExecutorCallback callbackObj )
```

**描述：**

人脸识别。

**参数：**

<a name="table374880443083932"></a>
<table><thead align="left"><tr id="row1943127101083932"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p275498778083932"><a name="p275498778083932"></a><a name="p275498778083932"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1285551675083932"><a name="p1285551675083932"></a><a name="p1285551675083932"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row292325037083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry577864853083932p0"><a name="entry577864853083932p0"></a><a name="entry577864853083932p0"></a>scheduleId</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1567434723083932p0"><a name="entry1567434723083932p0"></a><a name="entry1567434723083932p0"></a>调度ID，用于标识一次操作请求的调度过程。</p>
</td>
</tr>
<tr id="row112912316083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry2099191202083932p0"><a name="entry2099191202083932p0"></a><a name="entry2099191202083932p0"></a>extraInfo</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1841568780083932p0"><a name="entry1841568780083932p0"></a><a name="entry1841568780083932p0"></a>其他相关信息，用于支持信息扩展。</p>
</td>
</tr>
<tr id="row971335970083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1004600900083932p0"><a name="entry1004600900083932p0"></a><a name="entry1004600900083932p0"></a>callbackObj</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1580948607083932p0"><a name="entry1580948607083932p0"></a><a name="entry1580948607083932p0"></a>回调对象<a href="interface_i_executor_callback.md">IExecutorCallback</a>。</p>
</td>
</tr>
</tbody>
</table>

**返回：**

0 表示操作成功。

非0 表示操作失败。

## OnRegisterFinish\(\) \[1/2\]<a name="a86914f3f155246747b2c536fd8633cec"></a>

```
IExecutor::OnRegisterFinish ([in] unsigned long[] templateIdList, [in] unsigned char[] frameworkPublicKey, [in] unsigned char[] extraInfo )
```

**描述：**

完成执行器注册，对人脸特征模版进行对账，用于删除无效的人脸特征模板及相关信息。

**参数：**

<a name="table1135621074083932"></a>
<table><thead align="left"><tr id="row155709126083932"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1136168257083932"><a name="p1136168257083932"></a><a name="p1136168257083932"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p303247987083932"><a name="p303247987083932"></a><a name="p303247987083932"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row481255335083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry388265707083932p0"><a name="entry388265707083932p0"></a><a name="entry388265707083932p0"></a>templateIdList</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1003032858083932p0"><a name="entry1003032858083932p0"></a><a name="entry1003032858083932p0"></a>用户认证框架内由该执行器注册的人脸特征模版ID列表。</p>
</td>
</tr>
<tr id="row1767544281083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry106895405083932p0"><a name="entry106895405083932p0"></a><a name="entry106895405083932p0"></a>frameworkPublicKey</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1102695688083932p0"><a name="entry1102695688083932p0"></a><a name="entry1102695688083932p0"></a>用户认证框架的公钥，用于校验用户认证框架私钥签名的信息。</p>
</td>
</tr>
<tr id="row43027816083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry455426407083932p0"><a name="entry455426407083932p0"></a><a name="entry455426407083932p0"></a>extraInfo</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1804709126083932p0"><a name="entry1804709126083932p0"></a><a name="entry1804709126083932p0"></a>其他相关信息，用于支持信息扩展。</p>
</td>
</tr>
</tbody>
</table>

**返回：**

0 表示操作成功。

非0 表示操作失败。

## OnRegisterFinish\(\) \[2/2\]<a name="a86914f3f155246747b2c536fd8633ced"></a>

```
IExecutor::OnRegisterFinish ([in] unsigned long[] templateIdList, [in] unsigned char[] frameworkPublicKey, [in] unsigned char[] extraInfo )
```

**描述：**

完成执行器注册，对口令模版信息进行对账，用于删除无效的口令模板及相关信息。

**参数：**

<a name="table1611374929083932"></a>
<table><thead align="left"><tr id="row1966791130083932"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p332390018083932"><a name="p332390018083932"></a><a name="p332390018083932"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1697638183083932"><a name="p1697638183083932"></a><a name="p1697638183083932"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row350284309083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry241967473083932p0"><a name="entry241967473083932p0"></a><a name="entry241967473083932p0"></a>templateIdList</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry473361364083932p0"><a name="entry473361364083932p0"></a><a name="entry473361364083932p0"></a>用户认证框架内由该执行器注册的口令凭据模版ID列表。</p>
</td>
</tr>
<tr id="row1612567855083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry812012417083932p0"><a name="entry812012417083932p0"></a><a name="entry812012417083932p0"></a>frameworkPublicKey</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1019712081083932p0"><a name="entry1019712081083932p0"></a><a name="entry1019712081083932p0"></a>用户认证框架的公钥，用于校验用户认证框架私钥签名的信息。</p>
</td>
</tr>
<tr id="row805649358083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry10509882083932p0"><a name="entry10509882083932p0"></a><a name="entry10509882083932p0"></a>extraInfo</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1580489444083932p0"><a name="entry1580489444083932p0"></a><a name="entry1580489444083932p0"></a>其他相关信息，用于支持信息扩展。</p>
</td>
</tr>
</tbody>
</table>

**返回：**

0 表示操作成功。

非0 表示操作失败。

## OnSetData\(\)<a name="a693ddb05b172ed09b8c9d699960528c4"></a>

```
IExecutor::OnSetData ([in] unsigned long scheduleId, [in] unsigned long authSubType, [in] unsigned char[] data )
```

**描述：**

设置口令数据，口令认证驱动处理注册或认证口令请求时，如果口令数据由口令认证服务获取，需要通过该接口将口令数据传给口令认证驱动。

**参数：**

<a name="table800108643083932"></a>
<table><thead align="left"><tr id="row1995437317083932"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1862972029083932"><a name="p1862972029083932"></a><a name="p1862972029083932"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1610707328083932"><a name="p1610707328083932"></a><a name="p1610707328083932"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row661644360083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1275661396083932p0"><a name="entry1275661396083932p0"></a><a name="entry1275661396083932p0"></a>scheduleId</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry2006315082083932p0"><a name="entry2006315082083932p0"></a><a name="entry2006315082083932p0"></a>调度ID，用于标识一次操作请求的调度过程。</p>
</td>
</tr>
<tr id="row728745292083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry575701665083932p0"><a name="entry575701665083932p0"></a><a name="entry575701665083932p0"></a>authSubType</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1435116465083932p0"><a name="entry1435116465083932p0"></a><a name="entry1435116465083932p0"></a>口令子类型，如六位数字PIN码等。</p>
</td>
</tr>
<tr id="row645469889083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry627944486083932p0"><a name="entry627944486083932p0"></a><a name="entry627944486083932p0"></a>data</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry2004731078083932p0"><a name="entry2004731078083932p0"></a><a name="entry2004731078083932p0"></a>口令数据。</p>
</td>
</tr>
</tbody>
</table>

**返回：**

0 表示操作成功。

非0 表示操作失败。

## SendCommand\(\) \[1/2\]<a name="ad7ef470c0a6902e445e5574aaf3ff5c8"></a>

```
IExecutor::SendCommand ([in] int commandId, [in] unsigned char[] extraInfo, [in] IExecutorCallback callbackObj )
```

**描述：**

发送人脸认证功能相关操作命令。

**参数：**

<a name="table1149395960083932"></a>
<table><thead align="left"><tr id="row1521700013083932"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1843853278083932"><a name="p1843853278083932"></a><a name="p1843853278083932"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1113572525083932"><a name="p1113572525083932"></a><a name="p1113572525083932"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row1863172055083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1397453879083932p0"><a name="entry1397453879083932p0"></a><a name="entry1397453879083932p0"></a>commandId</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry844220211083932p0"><a name="entry844220211083932p0"></a><a name="entry844220211083932p0"></a>操作命令ID<a href="_hdf_pin_auth.md#ga5633c8cc52bef1a4df7539c7bb6febe7">CommandId</a>。</p>
</td>
</tr>
<tr id="row1218719975083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1617228816083932p0"><a name="entry1617228816083932p0"></a><a name="entry1617228816083932p0"></a>extraInfo</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry2110999951083932p0"><a name="entry2110999951083932p0"></a><a name="entry2110999951083932p0"></a>其他相关信息，用于支持信息扩展。</p>
</td>
</tr>
<tr id="row1402653501083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1455681325083932p0"><a name="entry1455681325083932p0"></a><a name="entry1455681325083932p0"></a>callbackObj</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1846744863083932p0"><a name="entry1846744863083932p0"></a><a name="entry1846744863083932p0"></a>回调对象<a href="interface_i_executor_callback.md">IExecutorCallback</a>。</p>
</td>
</tr>
</tbody>
</table>

**返回：**

0 表示操作成功。

非0 表示操作失败。

## SendCommand\(\) \[2/2\]<a name="ad7ef470c0a6902e445e5574aaf3ff5c9"></a>

```
IExecutor::SendCommand ([in] int commandId, [in] unsigned char[] extraInfo, [in] IExecutorCallback callbackObj )
```

**描述：**

发送口令认证功能相关操作命令。

**参数：**

<a name="table709906171083932"></a>
<table><thead align="left"><tr id="row50348707083932"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p64298703083932"><a name="p64298703083932"></a><a name="p64298703083932"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p670496018083932"><a name="p670496018083932"></a><a name="p670496018083932"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row804509809083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1061021432083932p0"><a name="entry1061021432083932p0"></a><a name="entry1061021432083932p0"></a>commandId</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1845075725083932p0"><a name="entry1845075725083932p0"></a><a name="entry1845075725083932p0"></a>操作命令ID<a href="_hdf_pin_auth.md#ga5633c8cc52bef1a4df7539c7bb6febe7">CommandId</a>。</p>
</td>
</tr>
<tr id="row828651446083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry728950925083932p0"><a name="entry728950925083932p0"></a><a name="entry728950925083932p0"></a>extraInfo</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry222851361083932p0"><a name="entry222851361083932p0"></a><a name="entry222851361083932p0"></a>其他相关信息，用于支持信息扩展。</p>
</td>
</tr>
<tr id="row554408708083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1609620301083932p0"><a name="entry1609620301083932p0"></a><a name="entry1609620301083932p0"></a>callbackObj</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry94337179083932p0"><a name="entry94337179083932p0"></a><a name="entry94337179083932p0"></a>回调对象<a href="interface_i_executor_callback.md">IExecutorCallback</a>。</p>
</td>
</tr>
</tbody>
</table>

**返回：**

0 表示操作成功。

非0 表示操作失败。

