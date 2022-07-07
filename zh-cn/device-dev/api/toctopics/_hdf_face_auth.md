# HdfFaceAuth<a name="ZH-CN_TOPIC_0000001343320957"></a>

## **汇总**<a name="section648220771083931"></a>

## 文件<a name="files"></a>

<a name="table2093631390083931"></a>
<table><thead align="left"><tr id="row1599940175083931"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1333928861083931"><a name="p1333928861083931"></a><a name="p1333928861083931"></a>文件</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p726490853083931"><a name="p726490853083931"></a><a name="p726490853083931"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row172788939083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1448176995083931"><a name="p1448176995083931"></a><a name="p1448176995083931"></a><a href="_face_auth_types_8idl.md">FaceAuthTypes.idl</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1566933474083931"><a name="p1566933474083931"></a><a name="p1566933474083931"></a>定义人脸认证驱动的枚举类和数据结构。</p>
</td>
</tr>
<tr id="row344403104083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1937723029083931"><a name="p1937723029083931"></a><a name="p1937723029083931"></a><a href="face__auth_2_i_executor_8idl.md">FACEAUTH_IExecutor.idl</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p714653400083931"><a name="p714653400083931"></a><a name="p714653400083931"></a>定义执行器接口，用于获取执行器，获取凭据模版信息，注册人脸特征模版，进行用户人脸认证，删除人脸特征模版等。</p>
</td>
</tr>
<tr id="row2044305785083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1737301034083931"><a name="p1737301034083931"></a><a name="p1737301034083931"></a><a href="face__auth_2_i_executor_callback_8idl.md">FACEAUTH_IExecutorCallback.idl</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2073376055083931"><a name="p2073376055083931"></a><a name="p2073376055083931"></a>定义异步API接口回调，用于返回异步接口的请求处理结果和信息。</p>
</td>
</tr>
<tr id="row2055379007083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1820359348083931"><a name="p1820359348083931"></a><a name="p1820359348083931"></a><a href="_i_face_auth_interface_8idl.md">IFaceAuthInterface.idl</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2104924531083931"><a name="p2104924531083931"></a><a name="p2104924531083931"></a>定义获取人脸认证驱动的执行器列表接口，用于从人脸认证驱动获取执行器对象列表。</p>
</td>
</tr>
</tbody>
</table>

## 类<a name="nested-classes"></a>

<a name="table1655689647083931"></a>
<table><thead align="left"><tr id="row1033524432083931"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p800402755083931"><a name="p800402755083931"></a><a name="p800402755083931"></a>类</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1286411586083931"><a name="p1286411586083931"></a><a name="p1286411586083931"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row989369301083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1937222217083931"><a name="p1937222217083931"></a><a name="p1937222217083931"></a><a href="_executor_info.md">ExecutorInfo</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1153460819083931"><a name="p1153460819083931"></a><a name="p1153460819083931"></a>执行器信息。 <a href="_executor_info.md">更多...</a></p>
</td>
</tr>
<tr id="row1752261330083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1319718462083931"><a name="p1319718462083931"></a><a name="p1319718462083931"></a><a href="_template_info.md">TemplateInfo</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1629021993083931"><a name="p1629021993083931"></a><a name="p1629021993083931"></a>凭据模版信息。 <a href="_template_info.md">更多...</a></p>
</td>
</tr>
<tr id="row1104779253083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p471781008083931"><a name="p471781008083931"></a><a name="p471781008083931"></a><a href="interface_i_executor.md">IExecutor</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1298099139083931"><a name="p1298099139083931"></a><a name="p1298099139083931"></a>定义执行器接口，用于获取执行器，获取凭据模版信息，注册人脸特征模版，进行用户人脸认证，删除人脸特征模版等。 <a href="interface_i_executor.md">更多...</a></p>
</td>
</tr>
<tr id="row1900821775083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1371389704083931"><a name="p1371389704083931"></a><a name="p1371389704083931"></a><a href="interface_i_executor_callback.md">IExecutorCallback</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2115445396083931"><a name="p2115445396083931"></a><a name="p2115445396083931"></a>定义异步API接口回调，用于返回异步接口的请求处理结果和信息。使用细节见<a href="interface_i_executor.md">IExecutor</a>。 <a href="interface_i_executor_callback.md">更多...</a></p>
</td>
</tr>
<tr id="row682330119083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1149884755083931"><a name="p1149884755083931"></a><a name="p1149884755083931"></a><a href="interface_i_face_auth_interface.md">IFaceAuthInterface</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1508234290083931"><a name="p1508234290083931"></a><a name="p1508234290083931"></a>定义获取人脸认证驱动的执行器列表接口。 <a href="interface_i_face_auth_interface.md">更多...</a></p>
</td>
</tr>
</tbody>
</table>

## 枚举<a name="enum-members"></a>

<a name="table322975760083931"></a>
<table><thead align="left"><tr id="row1380623404083931"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1977969354083931"><a name="p1977969354083931"></a><a name="p1977969354083931"></a>枚举</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p2047584958083931"><a name="p2047584958083931"></a><a name="p2047584958083931"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row1185042555083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1959297579083931"><a name="p1959297579083931"></a><a name="p1959297579083931"></a><a href="_hdf_face_auth.md#ga89fed1f0b2adadc0ab678c1c6b9570a1">AuthType</a> : int {   <a href="_hdf_user_auth.md#gga89fed1f0b2adadc0ab678c1c6b9570a1a048efb7462d3f8cced82716c66926168">PIN</a> = 1, <a href="_hdf_user_auth.md#gga89fed1f0b2adadc0ab678c1c6b9570a1a5cfae78048cf95359061c2e812e7d691">FACE</a> = 2, <a href="_hdf_user_auth.md#gga89fed1f0b2adadc0ab678c1c6b9570a1ad03eae85b35bf9bc22d787c8913b795a">FINGERPRINT</a> = 4, <a href="_hdf_user_auth.md#gga89fed1f0b2adadc0ab678c1c6b9570a1ab1d5eac4b1dca480c8056eaea7663b7a">ALL</a> = 0 }</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1343085904083931"><a name="p1343085904083931"></a><a name="p1343085904083931"></a>枚举用户认证凭据类型。 <a href="_hdf_face_auth.md#ga89fed1f0b2adadc0ab678c1c6b9570a1">更多...</a></p>
</td>
</tr>
<tr id="row1341457117083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p532923950083931"><a name="p532923950083931"></a><a name="p532923950083931"></a><a href="_hdf_face_auth.md#gaef26ea73ebd494278e243c53b41ea7e5">ExecutorRole</a> : int {   <a href="_hdf_user_auth.md#ggaef26ea73ebd494278e243c53b41ea7e5a539c54e76bcc96cddb85f0cabcff39ec">COLLECTOR</a> = 1, <a href="_hdf_user_auth.md#ggaef26ea73ebd494278e243c53b41ea7e5a1286a5d974d0c68d7bc43ffc0576a6d4">VERIFIER</a> = 2, <a href="_hdf_user_auth.md#ggaef26ea73ebd494278e243c53b41ea7e5a7eebd77a403f81c5968b4c2898ee6fd4">ALL_IN_ONE</a> = 3 }</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p217308245083931"><a name="p217308245083931"></a><a name="p217308245083931"></a>枚举执行器角色。 <a href="_hdf_face_auth.md#gaef26ea73ebd494278e243c53b41ea7e5">更多...</a></p>
</td>
</tr>
<tr id="row2061403646083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p761965490083931"><a name="p761965490083931"></a><a name="p761965490083931"></a><a href="_hdf_face_auth.md#ga955c57d8720719916dd806106356fa0f">ExecutorSecureLevel</a> : int {   <a href="_hdf_user_auth.md#gga955c57d8720719916dd806106356fa0fa0cd05a2adda94d3c676fca84f96c0638">ESL0</a> = 0, <a href="_hdf_user_auth.md#gga955c57d8720719916dd806106356fa0fae6a34bbf2764541238bf81569faf29d3">ESL1</a> = 1, <a href="_hdf_user_auth.md#gga955c57d8720719916dd806106356fa0fa8f898bca57625d548a011ba2aaf4285f">ESL2</a> = 2, <a href="_hdf_user_auth.md#gga955c57d8720719916dd806106356fa0fa9a6fb8a4530b6a09dba2fbfdf2e6c2e9">ESL3</a> = 3 }</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1592877291083931"><a name="p1592877291083931"></a><a name="p1592877291083931"></a>枚举执行器安全等级。 <a href="_hdf_face_auth.md#ga955c57d8720719916dd806106356fa0f">更多...</a></p>
</td>
</tr>
<tr id="row210691285083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1026827513083931"><a name="p1026827513083931"></a><a name="p1026827513083931"></a><a href="_hdf_face_auth.md#ga5633c8cc52bef1a4df7539c7bb6febe7">CommandId</a> : int { <a href="_hdf_pin_auth.md#gga5633c8cc52bef1a4df7539c7bb6febe7aef06794dc31ae453a7541e94ff9b91f9">LOCK_TEMPLATE</a> = 1, <a href="_hdf_pin_auth.md#gga5633c8cc52bef1a4df7539c7bb6febe7aa08e755bda3ab12a2bb435f63b9f55f4">UNLOCK_TEMPLATE</a> = 2, <a href="_hdf_pin_auth.md#gga5633c8cc52bef1a4df7539c7bb6febe7a68bc2d8d236ae8bc93b213bbfbd36741">VENDOR_COMMAND_BEGIN</a> = 10000, <a href="_hdf_pin_auth.md#gga5633c8cc52bef1a4df7539c7bb6febe7a88ec7d5086d2469ba843c7fcceade8a6">DEFAULT</a> = 0 }</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1759594805083931"><a name="p1759594805083931"></a><a name="p1759594805083931"></a>枚举人脸认证功能相关操作命令。 <a href="_hdf_face_auth.md#ga5633c8cc52bef1a4df7539c7bb6febe7">更多...</a></p>
</td>
</tr>
<tr id="row1788872894083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p159559424083931"><a name="p159559424083931"></a><a name="p159559424083931"></a><a href="_hdf_face_auth.md#gafe283e29a705391d97054a4b9d5fe007">FaceTipsCode</a> : int {   <a href="_hdf_face_auth.md#ggafe283e29a705391d97054a4b9d5fe007aa973b57b70bddf6e04ea0d1d8ac84bbc">FACE_AUTH_TIP_TOO_BRIGHT</a> = 1, <a href="_hdf_face_auth.md#ggafe283e29a705391d97054a4b9d5fe007a9e812580c2600ebd4847ac05478805fe">FACE_AUTH_TIP_TOO_DARK</a> = 2, <a href="_hdf_face_auth.md#ggafe283e29a705391d97054a4b9d5fe007adbd6a2cd4effac8f2d08a406c21cee17">FACE_AUTH_TIP_TOO_CLOSE</a> = 3, <a href="_hdf_face_auth.md#ggafe283e29a705391d97054a4b9d5fe007a557c72d5d5dd9cc4ca52406d442a085e">FACE_AUTH_TIP_TOO_FAR</a> = 4,   <a href="_hdf_face_auth.md#ggafe283e29a705391d97054a4b9d5fe007ac573361a2c459a0d0f95f7691819611b">FACE_AUTH_TIP_TOO_HIGH</a> = 5, <a href="_hdf_face_auth.md#ggafe283e29a705391d97054a4b9d5fe007a1fbbe62377b7746848761d4fc1e591d8">FACE_AUTH_TIP_TOO_LOW</a> = 6, <a href="_hdf_face_auth.md#ggafe283e29a705391d97054a4b9d5fe007a8b8f69a132ab5e9e4770fbe25efe6810">FACE_AUTH_TIP_TOO_RIGHT</a> = 7, <a href="_hdf_face_auth.md#ggafe283e29a705391d97054a4b9d5fe007a4f1f1ab1bed69c0968981c6ecc52a572">FACE_AUTH_TIP_TOO_LEFT</a> = 8,   <a href="_hdf_face_auth.md#ggafe283e29a705391d97054a4b9d5fe007a19f794720c79aaeb2b2cb895eca6c4fd">FACE_AUTH_TIP_TOO_MUCH_MOTION</a> = 9, <a href="_hdf_face_auth.md#ggafe283e29a705391d97054a4b9d5fe007a93c89c83ede9a3b5a15e90a1975176b7">FACE_AUTH_TIP_POOR_GAZE</a> = 10, <a href="_hdf_face_auth.md#ggafe283e29a705391d97054a4b9d5fe007aa41ae58b84dbfe8b467de7a11ad236f8">FACE_AUTH_TIP_NOT_DETECTED</a> = 11, <a href="_hdf_face_auth.md#ggafe283e29a705391d97054a4b9d5fe007abef2f1de5f74c324a7dd8958a279caab">VENDOR_FACE_AUTH_TIP_BEGIN</a> = 10000 }</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p416560126083931"><a name="p416560126083931"></a><a name="p416560126083931"></a>枚举提示信息编码。 <a href="_hdf_face_auth.md#gafe283e29a705391d97054a4b9d5fe007">更多...</a></p>
</td>
</tr>
</tbody>
</table>

## 变量<a name="var-members"></a>

<a name="table723662332083931"></a>
<table><thead align="left"><tr id="row1969741936083931"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1556180013083931"><a name="p1556180013083931"></a><a name="p1556180013083931"></a>变量 名称</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p84771495083931"><a name="p84771495083931"></a><a name="p84771495083931"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row1749386586083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1315201920194"><a name="p1315201920194"></a><a name="p1315201920194"></a>package ohos.hdi.face_auth.v1_0</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p346903012185"><a name="p346903012185"></a><a name="p346903012185"></a>人脸认证接口的包路径</p>
</td>
</tr>
</tbody>
</table>

## **详细描述**<a name="section2106622738083931"></a>

提供人脸认证驱动的标准API接口。

人脸认证驱动为人脸认证服务提供统一的访问接口。获取人脸认证驱动代理后，人脸认证服务可以调用相关接口获取执行器，获取人脸认证执行器后， 人脸认证服务可以调用相关接口获取执行器，获取凭据模版信息，注册人脸特征模版，进行用户人脸认证，删除人脸特征模版等。

**Since：**

3.2

## **枚举类型说明**<a name="section1428907106083931"></a>

## AuthType<a name="ga89fed1f0b2adadc0ab678c1c6b9570a1"></a>

```
enum AuthType : int
```

**描述：**

枚举用户认证凭据类型。

<a name="table667054584083931"></a>
<table><thead align="left"><tr id="row1475511252083931"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p834610609083931"><a name="p834610609083931"></a><a name="p834610609083931"></a>枚举值</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1805323874083931"><a name="p1805323874083931"></a><a name="p1805323874083931"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row506321814083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry762719791083931p0"><a name="entry762719791083931p0"></a><a name="entry762719791083931p0"></a><strong id="gga89fed1f0b2adadc0ab678c1c6b9570a1a048efb7462d3f8cced82716c66926168"><a name="gga89fed1f0b2adadc0ab678c1c6b9570a1a048efb7462d3f8cced82716c66926168"></a><a name="gga89fed1f0b2adadc0ab678c1c6b9570a1a048efb7462d3f8cced82716c66926168"></a></strong>PIN</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p11463985083931"><a name="p11463985083931"></a><a name="p11463985083931"></a>认证凭据类型为口令。</p>
<p id="p15981114642014"><a name="p15981114642014"></a><a name="p15981114642014"></a></p>
</td>
</tr>
<tr id="row294552817083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1715352724083931p0"><a name="entry1715352724083931p0"></a><a name="entry1715352724083931p0"></a><strong id="gga89fed1f0b2adadc0ab678c1c6b9570a1a5cfae78048cf95359061c2e812e7d691"><a name="gga89fed1f0b2adadc0ab678c1c6b9570a1a5cfae78048cf95359061c2e812e7d691"></a><a name="gga89fed1f0b2adadc0ab678c1c6b9570a1a5cfae78048cf95359061c2e812e7d691"></a></strong>FACE</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p973981204083931"><a name="p973981204083931"></a><a name="p973981204083931"></a>认证凭据类型为人脸。</p>
<p id="p2098194610209"><a name="p2098194610209"></a><a name="p2098194610209"></a></p>
</td>
</tr>
<tr id="row139539738083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1547202402083931p0"><a name="entry1547202402083931p0"></a><a name="entry1547202402083931p0"></a><strong id="gga89fed1f0b2adadc0ab678c1c6b9570a1ad03eae85b35bf9bc22d787c8913b795a"><a name="gga89fed1f0b2adadc0ab678c1c6b9570a1ad03eae85b35bf9bc22d787c8913b795a"></a><a name="gga89fed1f0b2adadc0ab678c1c6b9570a1ad03eae85b35bf9bc22d787c8913b795a"></a></strong>FINGERPRINT</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p8543828083931"><a name="p8543828083931"></a><a name="p8543828083931"></a>认证凭据类型为指纹。</p>
<p id="p598124614203"><a name="p598124614203"></a><a name="p598124614203"></a></p>
</td>
</tr>
<tr id="row1463715555083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1172050606083931p0"><a name="entry1172050606083931p0"></a><a name="entry1172050606083931p0"></a><strong id="gga89fed1f0b2adadc0ab678c1c6b9570a1ab1d5eac4b1dca480c8056eaea7663b7a"><a name="gga89fed1f0b2adadc0ab678c1c6b9570a1ab1d5eac4b1dca480c8056eaea7663b7a"></a><a name="gga89fed1f0b2adadc0ab678c1c6b9570a1ab1d5eac4b1dca480c8056eaea7663b7a"></a></strong>ALL</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p293603434083931"><a name="p293603434083931"></a><a name="p293603434083931"></a>表示包含所有认证凭据类型。</p>
<p id="p898124615200"><a name="p898124615200"></a><a name="p898124615200"></a></p>
</td>
</tr>
</tbody>
</table>

## CommandId<a name="ga5633c8cc52bef1a4df7539c7bb6febe7"></a>

```
enum CommandId : int
```

**描述：**

枚举人脸认证功能相关操作命令。

<a name="table983050416083931"></a>
<table><thead align="left"><tr id="row770517995083931"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1847692861083931"><a name="p1847692861083931"></a><a name="p1847692861083931"></a>枚举值</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1356354253083931"><a name="p1356354253083931"></a><a name="p1356354253083931"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row1089701121083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1378875880083931p0"><a name="entry1378875880083931p0"></a><a name="entry1378875880083931p0"></a><strong id="gga5633c8cc52bef1a4df7539c7bb6febe7aef06794dc31ae453a7541e94ff9b91f9"><a name="gga5633c8cc52bef1a4df7539c7bb6febe7aef06794dc31ae453a7541e94ff9b91f9"></a><a name="gga5633c8cc52bef1a4df7539c7bb6febe7aef06794dc31ae453a7541e94ff9b91f9"></a></strong>LOCK_TEMPLATE</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1865878260083931"><a name="p1865878260083931"></a><a name="p1865878260083931"></a>锁定人脸模版。</p>
<p id="p399111469202"><a name="p399111469202"></a><a name="p399111469202"></a></p>
</td>
</tr>
<tr id="row1027713854083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1786148552083931p0"><a name="entry1786148552083931p0"></a><a name="entry1786148552083931p0"></a><strong id="gga5633c8cc52bef1a4df7539c7bb6febe7aa08e755bda3ab12a2bb435f63b9f55f4"><a name="gga5633c8cc52bef1a4df7539c7bb6febe7aa08e755bda3ab12a2bb435f63b9f55f4"></a><a name="gga5633c8cc52bef1a4df7539c7bb6febe7aa08e755bda3ab12a2bb435f63b9f55f4"></a></strong>UNLOCK_TEMPLATE</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p60105672083931"><a name="p60105672083931"></a><a name="p60105672083931"></a>解锁人脸模版。</p>
<p id="p149911446122011"><a name="p149911446122011"></a><a name="p149911446122011"></a></p>
</td>
</tr>
<tr id="row1710137863083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1330595345083931p0"><a name="entry1330595345083931p0"></a><a name="entry1330595345083931p0"></a><strong id="gga5633c8cc52bef1a4df7539c7bb6febe7a68bc2d8d236ae8bc93b213bbfbd36741"><a name="gga5633c8cc52bef1a4df7539c7bb6febe7a68bc2d8d236ae8bc93b213bbfbd36741"></a><a name="gga5633c8cc52bef1a4df7539c7bb6febe7a68bc2d8d236ae8bc93b213bbfbd36741"></a></strong>VENDOR_COMMAND_BEGIN</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1680685679083931"><a name="p1680685679083931"></a><a name="p1680685679083931"></a>用于厂商自定义操作指令。</p>
<p id="p5991134612019"><a name="p5991134612019"></a><a name="p5991134612019"></a></p>
</td>
</tr>
<tr id="row2106992161083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1885705662083931p0"><a name="entry1885705662083931p0"></a><a name="entry1885705662083931p0"></a><strong id="gga5633c8cc52bef1a4df7539c7bb6febe7a88ec7d5086d2469ba843c7fcceade8a6"><a name="gga5633c8cc52bef1a4df7539c7bb6febe7a88ec7d5086d2469ba843c7fcceade8a6"></a><a name="gga5633c8cc52bef1a4df7539c7bb6febe7a88ec7d5086d2469ba843c7fcceade8a6"></a></strong>DEFAULT</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p444215577083931"><a name="p444215577083931"></a><a name="p444215577083931"></a>默认无效操作命令。</p>
<p id="p1199134614202"><a name="p1199134614202"></a><a name="p1199134614202"></a></p>
</td>
</tr>
</tbody>
</table>

## ExecutorRole<a name="gaef26ea73ebd494278e243c53b41ea7e5"></a>

```
enum ExecutorRole : int
```

**描述：**

枚举执行器角色。

<a name="table1463709933083931"></a>
<table><thead align="left"><tr id="row2023176482083931"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1098294237083931"><a name="p1098294237083931"></a><a name="p1098294237083931"></a>枚举值</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p2128830327083931"><a name="p2128830327083931"></a><a name="p2128830327083931"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row818068173083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1421755205083931p0"><a name="entry1421755205083931p0"></a><a name="entry1421755205083931p0"></a><strong id="ggaef26ea73ebd494278e243c53b41ea7e5a539c54e76bcc96cddb85f0cabcff39ec"><a name="ggaef26ea73ebd494278e243c53b41ea7e5a539c54e76bcc96cddb85f0cabcff39ec"></a><a name="ggaef26ea73ebd494278e243c53b41ea7e5a539c54e76bcc96cddb85f0cabcff39ec"></a></strong>COLLECTOR</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1231865016083931"><a name="p1231865016083931"></a><a name="p1231865016083931"></a>执行器角色为采集器，提供用户认证时的数据采集能力，需要和认证器配合完成用户认证。</p>
<p id="p6254762018"><a name="p6254762018"></a><a name="p6254762018"></a></p>
</td>
</tr>
<tr id="row183398746083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry621292987083931p0"><a name="entry621292987083931p0"></a><a name="entry621292987083931p0"></a><strong id="ggaef26ea73ebd494278e243c53b41ea7e5a1286a5d974d0c68d7bc43ffc0576a6d4"><a name="ggaef26ea73ebd494278e243c53b41ea7e5a1286a5d974d0c68d7bc43ffc0576a6d4"></a><a name="ggaef26ea73ebd494278e243c53b41ea7e5a1286a5d974d0c68d7bc43ffc0576a6d4"></a></strong>VERIFIER</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p428509617083931"><a name="p428509617083931"></a><a name="p428509617083931"></a>执行器角色为认证器，提供用户认证时数据处理能力，读取存储凭据模板信息并完成比对。</p>
<p id="p821947112013"><a name="p821947112013"></a><a name="p821947112013"></a></p>
</td>
</tr>
<tr id="row777619028083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1674790191083931p0"><a name="entry1674790191083931p0"></a><a name="entry1674790191083931p0"></a><strong id="ggaef26ea73ebd494278e243c53b41ea7e5a7eebd77a403f81c5968b4c2898ee6fd4"><a name="ggaef26ea73ebd494278e243c53b41ea7e5a7eebd77a403f81c5968b4c2898ee6fd4"></a><a name="ggaef26ea73ebd494278e243c53b41ea7e5a7eebd77a403f81c5968b4c2898ee6fd4"></a></strong>ALL_IN_ONE</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p556138893083931"><a name="p556138893083931"></a><a name="p556138893083931"></a>执行器角色为全功能执行器，可提供用户认证数据采集、处理、储存及比对能力。</p>
<p id="p72204714208"><a name="p72204714208"></a><a name="p72204714208"></a></p>
</td>
</tr>
</tbody>
</table>

## ExecutorSecureLevel<a name="ga955c57d8720719916dd806106356fa0f"></a>

```
enum ExecutorSecureLevel : int
```

**描述：**

枚举执行器安全等级。

<a name="table915453515083931"></a>
<table><thead align="left"><tr id="row1927042998083931"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1333861681083931"><a name="p1333861681083931"></a><a name="p1333861681083931"></a>枚举值</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1264509921083931"><a name="p1264509921083931"></a><a name="p1264509921083931"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row273304069083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry741863942083931p0"><a name="entry741863942083931p0"></a><a name="entry741863942083931p0"></a><strong id="gga955c57d8720719916dd806106356fa0fa0cd05a2adda94d3c676fca84f96c0638"><a name="gga955c57d8720719916dd806106356fa0fa0cd05a2adda94d3c676fca84f96c0638"></a><a name="gga955c57d8720719916dd806106356fa0fa0cd05a2adda94d3c676fca84f96c0638"></a></strong>ESL0</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p935618226083931"><a name="p935618226083931"></a><a name="p935618226083931"></a>执行器安全级别为0，关键操作在无访问控制执行环境中完成。</p>
<p id="p311164711205"><a name="p311164711205"></a><a name="p311164711205"></a></p>
</td>
</tr>
<tr id="row1148670183083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1351765805083931p0"><a name="entry1351765805083931p0"></a><a name="entry1351765805083931p0"></a><strong id="gga955c57d8720719916dd806106356fa0fae6a34bbf2764541238bf81569faf29d3"><a name="gga955c57d8720719916dd806106356fa0fae6a34bbf2764541238bf81569faf29d3"></a><a name="gga955c57d8720719916dd806106356fa0fae6a34bbf2764541238bf81569faf29d3"></a></strong>ESL1</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1970603911083931"><a name="p1970603911083931"></a><a name="p1970603911083931"></a>执行器安全级别为1，关键操作在有访问控制的执行环境中完成。</p>
<p id="p61124711202"><a name="p61124711202"></a><a name="p61124711202"></a></p>
</td>
</tr>
<tr id="row1194419866083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry438634692083931p0"><a name="entry438634692083931p0"></a><a name="entry438634692083931p0"></a><strong id="gga955c57d8720719916dd806106356fa0fa8f898bca57625d548a011ba2aaf4285f"><a name="gga955c57d8720719916dd806106356fa0fa8f898bca57625d548a011ba2aaf4285f"></a><a name="gga955c57d8720719916dd806106356fa0fa8f898bca57625d548a011ba2aaf4285f"></a></strong>ESL2</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1144992693083931"><a name="p1144992693083931"></a><a name="p1144992693083931"></a>执行器安全级别为2，关键操作在可信执行环境中完成。</p>
<p id="p311164712204"><a name="p311164712204"></a><a name="p311164712204"></a></p>
</td>
</tr>
<tr id="row1008447743083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry17079890083931p0"><a name="entry17079890083931p0"></a><a name="entry17079890083931p0"></a><strong id="gga955c57d8720719916dd806106356fa0fa9a6fb8a4530b6a09dba2fbfdf2e6c2e9"><a name="gga955c57d8720719916dd806106356fa0fa9a6fb8a4530b6a09dba2fbfdf2e6c2e9"></a><a name="gga955c57d8720719916dd806106356fa0fa9a6fb8a4530b6a09dba2fbfdf2e6c2e9"></a></strong>ESL3</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1695917044083931"><a name="p1695917044083931"></a><a name="p1695917044083931"></a>执行器安全级别为3，关键操作在高安环境如独立安全芯片中完成。</p>
<p id="p41204732013"><a name="p41204732013"></a><a name="p41204732013"></a></p>
</td>
</tr>
</tbody>
</table>

## FaceTipsCode<a name="gafe283e29a705391d97054a4b9d5fe007"></a>

```
enum FaceTipsCode : int
```

**描述：**

枚举提示信息编码。

<a name="table425137047083931"></a>
<table><thead align="left"><tr id="row571039918083931"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1255881444083931"><a name="p1255881444083931"></a><a name="p1255881444083931"></a>枚举值</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1086997502083931"><a name="p1086997502083931"></a><a name="p1086997502083931"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row316280158083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry10320200083931p0"><a name="entry10320200083931p0"></a><a name="entry10320200083931p0"></a><strong id="ggafe283e29a705391d97054a4b9d5fe007aa973b57b70bddf6e04ea0d1d8ac84bbc"><a name="ggafe283e29a705391d97054a4b9d5fe007aa973b57b70bddf6e04ea0d1d8ac84bbc"></a><a name="ggafe283e29a705391d97054a4b9d5fe007aa973b57b70bddf6e04ea0d1d8ac84bbc"></a></strong>FACE_AUTH_TIP_TOO_BRIGHT</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1559267983083931"><a name="p1559267983083931"></a><a name="p1559267983083931"></a>获取的人脸图像由于光照度高而过亮。</p>
<p id="p82344710208"><a name="p82344710208"></a><a name="p82344710208"></a></p>
</td>
</tr>
<tr id="row1068381790083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1741842390083931p0"><a name="entry1741842390083931p0"></a><a name="entry1741842390083931p0"></a><strong id="ggafe283e29a705391d97054a4b9d5fe007a9e812580c2600ebd4847ac05478805fe"><a name="ggafe283e29a705391d97054a4b9d5fe007a9e812580c2600ebd4847ac05478805fe"></a><a name="ggafe283e29a705391d97054a4b9d5fe007a9e812580c2600ebd4847ac05478805fe"></a></strong>FACE_AUTH_TIP_TOO_DARK</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1837920331083931"><a name="p1837920331083931"></a><a name="p1837920331083931"></a>获取的人脸图像由于光照度低而过暗。</p>
<p id="p9232475207"><a name="p9232475207"></a><a name="p9232475207"></a></p>
</td>
</tr>
<tr id="row377310871083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry410876475083931p0"><a name="entry410876475083931p0"></a><a name="entry410876475083931p0"></a><strong id="ggafe283e29a705391d97054a4b9d5fe007adbd6a2cd4effac8f2d08a406c21cee17"><a name="ggafe283e29a705391d97054a4b9d5fe007adbd6a2cd4effac8f2d08a406c21cee17"></a><a name="ggafe283e29a705391d97054a4b9d5fe007adbd6a2cd4effac8f2d08a406c21cee17"></a></strong>FACE_AUTH_TIP_TOO_CLOSE</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1522755444083931"><a name="p1522755444083931"></a><a name="p1522755444083931"></a>人脸离设备过近。</p>
<p id="p1523154710202"><a name="p1523154710202"></a><a name="p1523154710202"></a></p>
</td>
</tr>
<tr id="row100349342083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1153571474083931p0"><a name="entry1153571474083931p0"></a><a name="entry1153571474083931p0"></a><strong id="ggafe283e29a705391d97054a4b9d5fe007a557c72d5d5dd9cc4ca52406d442a085e"><a name="ggafe283e29a705391d97054a4b9d5fe007a557c72d5d5dd9cc4ca52406d442a085e"></a><a name="ggafe283e29a705391d97054a4b9d5fe007a557c72d5d5dd9cc4ca52406d442a085e"></a></strong>FACE_AUTH_TIP_TOO_FAR</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p351872560083931"><a name="p351872560083931"></a><a name="p351872560083931"></a>人脸离设备过远。</p>
<p id="p523184717202"><a name="p523184717202"></a><a name="p523184717202"></a></p>
</td>
</tr>
<tr id="row1732562545083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry978430991083931p0"><a name="entry978430991083931p0"></a><a name="entry978430991083931p0"></a><strong id="ggafe283e29a705391d97054a4b9d5fe007ac573361a2c459a0d0f95f7691819611b"><a name="ggafe283e29a705391d97054a4b9d5fe007ac573361a2c459a0d0f95f7691819611b"></a><a name="ggafe283e29a705391d97054a4b9d5fe007ac573361a2c459a0d0f95f7691819611b"></a></strong>FACE_AUTH_TIP_TOO_HIGH</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1100698360083931"><a name="p1100698360083931"></a><a name="p1100698360083931"></a>设备过高，只拍到人脸的上半部分。</p>
<p id="p723447152012"><a name="p723447152012"></a><a name="p723447152012"></a></p>
</td>
</tr>
<tr id="row1305119027083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1457331936083931p0"><a name="entry1457331936083931p0"></a><a name="entry1457331936083931p0"></a><strong id="ggafe283e29a705391d97054a4b9d5fe007a1fbbe62377b7746848761d4fc1e591d8"><a name="ggafe283e29a705391d97054a4b9d5fe007a1fbbe62377b7746848761d4fc1e591d8"></a><a name="ggafe283e29a705391d97054a4b9d5fe007a1fbbe62377b7746848761d4fc1e591d8"></a></strong>FACE_AUTH_TIP_TOO_LOW</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p72061444083931"><a name="p72061444083931"></a><a name="p72061444083931"></a>设备过低，只拍到人脸的下半部分。</p>
<p id="p1123124712018"><a name="p1123124712018"></a><a name="p1123124712018"></a></p>
</td>
</tr>
<tr id="row1910339135083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry702419378083931p0"><a name="entry702419378083931p0"></a><a name="entry702419378083931p0"></a><strong id="ggafe283e29a705391d97054a4b9d5fe007a8b8f69a132ab5e9e4770fbe25efe6810"><a name="ggafe283e29a705391d97054a4b9d5fe007a8b8f69a132ab5e9e4770fbe25efe6810"></a><a name="ggafe283e29a705391d97054a4b9d5fe007a8b8f69a132ab5e9e4770fbe25efe6810"></a></strong>FACE_AUTH_TIP_TOO_RIGHT</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1682720742083931"><a name="p1682720742083931"></a><a name="p1682720742083931"></a>设备偏右，只拍到人脸的右侧部分。</p>
<p id="p10231447122012"><a name="p10231447122012"></a><a name="p10231447122012"></a></p>
</td>
</tr>
<tr id="row280607311083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry374123721083931p0"><a name="entry374123721083931p0"></a><a name="entry374123721083931p0"></a><strong id="ggafe283e29a705391d97054a4b9d5fe007a4f1f1ab1bed69c0968981c6ecc52a572"><a name="ggafe283e29a705391d97054a4b9d5fe007a4f1f1ab1bed69c0968981c6ecc52a572"></a><a name="ggafe283e29a705391d97054a4b9d5fe007a4f1f1ab1bed69c0968981c6ecc52a572"></a></strong>FACE_AUTH_TIP_TOO_LEFT</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p898265568083931"><a name="p898265568083931"></a><a name="p898265568083931"></a>设备偏左，只拍到人脸的左侧部分。</p>
<p id="p112304710201"><a name="p112304710201"></a><a name="p112304710201"></a></p>
</td>
</tr>
<tr id="row649646915083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry428233979083931p0"><a name="entry428233979083931p0"></a><a name="entry428233979083931p0"></a><strong id="ggafe283e29a705391d97054a4b9d5fe007a19f794720c79aaeb2b2cb895eca6c4fd"><a name="ggafe283e29a705391d97054a4b9d5fe007a19f794720c79aaeb2b2cb895eca6c4fd"></a><a name="ggafe283e29a705391d97054a4b9d5fe007a19f794720c79aaeb2b2cb895eca6c4fd"></a></strong>FACE_AUTH_TIP_TOO_MUCH_MOTION</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p169693195083931"><a name="p169693195083931"></a><a name="p169693195083931"></a>人脸信息采集过程中，人脸移动过多。</p>
<p id="p1323184742010"><a name="p1323184742010"></a><a name="p1323184742010"></a></p>
</td>
</tr>
<tr id="row1332751554083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry789426223083931p0"><a name="entry789426223083931p0"></a><a name="entry789426223083931p0"></a><strong id="ggafe283e29a705391d97054a4b9d5fe007a93c89c83ede9a3b5a15e90a1975176b7"><a name="ggafe283e29a705391d97054a4b9d5fe007a93c89c83ede9a3b5a15e90a1975176b7"></a><a name="ggafe283e29a705391d97054a4b9d5fe007a93c89c83ede9a3b5a15e90a1975176b7"></a></strong>FACE_AUTH_TIP_POOR_GAZE</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p297459308083931"><a name="p297459308083931"></a><a name="p297459308083931"></a>用户未注视设备。</p>
<p id="p7234474207"><a name="p7234474207"></a><a name="p7234474207"></a></p>
</td>
</tr>
<tr id="row1785695082083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry761360885083931p0"><a name="entry761360885083931p0"></a><a name="entry761360885083931p0"></a><strong id="ggafe283e29a705391d97054a4b9d5fe007aa41ae58b84dbfe8b467de7a11ad236f8"><a name="ggafe283e29a705391d97054a4b9d5fe007aa41ae58b84dbfe8b467de7a11ad236f8"></a><a name="ggafe283e29a705391d97054a4b9d5fe007aa41ae58b84dbfe8b467de7a11ad236f8"></a></strong>FACE_AUTH_TIP_NOT_DETECTED</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p679605982083931"><a name="p679605982083931"></a><a name="p679605982083931"></a>未检测到人脸。</p>
<p id="p2231447152015"><a name="p2231447152015"></a><a name="p2231447152015"></a></p>
</td>
</tr>
<tr id="row673332189083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry254938881083931p0"><a name="entry254938881083931p0"></a><a name="entry254938881083931p0"></a><strong id="ggafe283e29a705391d97054a4b9d5fe007abef2f1de5f74c324a7dd8958a279caab"><a name="ggafe283e29a705391d97054a4b9d5fe007abef2f1de5f74c324a7dd8958a279caab"></a><a name="ggafe283e29a705391d97054a4b9d5fe007abef2f1de5f74c324a7dd8958a279caab"></a></strong>VENDOR_FACE_AUTH_TIP_BEGIN</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p413677117083931"><a name="p413677117083931"></a><a name="p413677117083931"></a>用于厂商自定义提示信息。</p>
<p id="p124547132010"><a name="p124547132010"></a><a name="p124547132010"></a></p>
</td>
</tr>
</tbody>
</table>

