# FaceAuthTypes.idl<a name="ZH-CN_TOPIC_0000001290561172"></a>

## **概述**<a name="section460706065083932"></a>

**所属模块:**

[HdfFaceAuth](_hdf_face_auth.md)

## **汇总**<a name="section1105619112083932"></a>

## 类<a name="nested-classes"></a>

<a name="table2120448074083932"></a>
<table><thead align="left"><tr id="row2090042142083932"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1779657875083932"><a name="p1779657875083932"></a><a name="p1779657875083932"></a>类</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p383790839083932"><a name="p383790839083932"></a><a name="p383790839083932"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row1477287140083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1937222217083931"><a name="p1937222217083931"></a><a name="p1937222217083931"></a><a href="_executor_info.md">ExecutorInfo</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1153460819083931"><a name="p1153460819083931"></a><a name="p1153460819083931"></a>执行器信息。 <a href="_executor_info.md">更多...</a></p>
</td>
</tr>
<tr id="row1383214123083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1319718462083931"><a name="p1319718462083931"></a><a name="p1319718462083931"></a><a href="_template_info.md">TemplateInfo</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1629021993083931"><a name="p1629021993083931"></a><a name="p1629021993083931"></a>凭据模版信息。 <a href="_template_info.md">更多...</a></p>
</td>
</tr>
</tbody>
</table>

## 枚举<a name="enum-members"></a>

<a name="table269694978083932"></a>
<table><thead align="left"><tr id="row934236411083932"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p2020382675083932"><a name="p2020382675083932"></a><a name="p2020382675083932"></a>枚举</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p175491675083932"><a name="p175491675083932"></a><a name="p175491675083932"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row1986965401083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p481189335083932"><a name="p481189335083932"></a><a name="p481189335083932"></a><a href="_hdf_face_auth.md#ga89fed1f0b2adadc0ab678c1c6b9570a1">AuthType</a> : int {   <a href="_hdf_user_auth.md#gga89fed1f0b2adadc0ab678c1c6b9570a1a048efb7462d3f8cced82716c66926168">PIN</a> = 1, <a href="_hdf_user_auth.md#gga89fed1f0b2adadc0ab678c1c6b9570a1a5cfae78048cf95359061c2e812e7d691">FACE</a> = 2, <a href="_hdf_user_auth.md#gga89fed1f0b2adadc0ab678c1c6b9570a1ad03eae85b35bf9bc22d787c8913b795a">FINGERPRINT</a> = 4, <a href="_hdf_user_auth.md#gga89fed1f0b2adadc0ab678c1c6b9570a1a048efb7462d3f8cced82716c66926168">PIN</a> = 1,   <a href="_hdf_user_auth.md#gga89fed1f0b2adadc0ab678c1c6b9570a1a5cfae78048cf95359061c2e812e7d691">FACE</a> = 2, <a href="_hdf_user_auth.md#gga89fed1f0b2adadc0ab678c1c6b9570a1ad03eae85b35bf9bc22d787c8913b795a">FINGERPRINT</a> = 4, <a href="_hdf_user_auth.md#gga89fed1f0b2adadc0ab678c1c6b9570a1ab1d5eac4b1dca480c8056eaea7663b7a">ALL</a> = 0, <a href="_hdf_user_auth.md#gga89fed1f0b2adadc0ab678c1c6b9570a1a048efb7462d3f8cced82716c66926168">PIN</a> = 1,   <a href="_hdf_user_auth.md#gga89fed1f0b2adadc0ab678c1c6b9570a1a5cfae78048cf95359061c2e812e7d691">FACE</a> = 2, <a href="_hdf_user_auth.md#gga89fed1f0b2adadc0ab678c1c6b9570a1ad03eae85b35bf9bc22d787c8913b795a">FINGERPRINT</a> = 4 }</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p533322208083932"><a name="p533322208083932"></a><a name="p533322208083932"></a>枚举用户认证凭据类型。 <a href="_hdf_face_auth.md#ga89fed1f0b2adadc0ab678c1c6b9570a1">更多...</a></p>
</td>
</tr>
<tr id="row774637080083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p671489491083932"><a name="p671489491083932"></a><a name="p671489491083932"></a><a href="_hdf_face_auth.md#gaef26ea73ebd494278e243c53b41ea7e5">ExecutorRole</a> : int {   <a href="_hdf_user_auth.md#ggaef26ea73ebd494278e243c53b41ea7e5a539c54e76bcc96cddb85f0cabcff39ec">COLLECTOR</a> = 1, <a href="_hdf_user_auth.md#ggaef26ea73ebd494278e243c53b41ea7e5a1286a5d974d0c68d7bc43ffc0576a6d4">VERIFIER</a> = 2, <a href="_hdf_user_auth.md#ggaef26ea73ebd494278e243c53b41ea7e5a7eebd77a403f81c5968b4c2898ee6fd4">ALL_IN_ONE</a> = 3, <a href="_hdf_user_auth.md#ggaef26ea73ebd494278e243c53b41ea7e5a539c54e76bcc96cddb85f0cabcff39ec">COLLECTOR</a> = 1,   <a href="_hdf_user_auth.md#ggaef26ea73ebd494278e243c53b41ea7e5a1286a5d974d0c68d7bc43ffc0576a6d4">VERIFIER</a> = 2, <a href="_hdf_user_auth.md#ggaef26ea73ebd494278e243c53b41ea7e5a7eebd77a403f81c5968b4c2898ee6fd4">ALL_IN_ONE</a> = 3, <a href="_hdf_user_auth.md#ggaef26ea73ebd494278e243c53b41ea7e5a539c54e76bcc96cddb85f0cabcff39ec">COLLECTOR</a> = 1, <a href="_hdf_user_auth.md#ggaef26ea73ebd494278e243c53b41ea7e5a1286a5d974d0c68d7bc43ffc0576a6d4">VERIFIER</a> = 2,   <a href="_hdf_user_auth.md#ggaef26ea73ebd494278e243c53b41ea7e5a7eebd77a403f81c5968b4c2898ee6fd4">ALL_IN_ONE</a> = 3 }</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1503848380083932"><a name="p1503848380083932"></a><a name="p1503848380083932"></a>枚举执行器角色。 <a href="_hdf_face_auth.md#gaef26ea73ebd494278e243c53b41ea7e5">更多...</a></p>
</td>
</tr>
<tr id="row1795241799083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1571349198083932"><a name="p1571349198083932"></a><a name="p1571349198083932"></a><a href="_hdf_face_auth.md#ga955c57d8720719916dd806106356fa0f">ExecutorSecureLevel</a> : int {   <a href="_hdf_user_auth.md#gga955c57d8720719916dd806106356fa0fa0cd05a2adda94d3c676fca84f96c0638">ESL0</a> = 0, <a href="_hdf_user_auth.md#gga955c57d8720719916dd806106356fa0fae6a34bbf2764541238bf81569faf29d3">ESL1</a> = 1, <a href="_hdf_user_auth.md#gga955c57d8720719916dd806106356fa0fa8f898bca57625d548a011ba2aaf4285f">ESL2</a> = 2, <a href="_hdf_user_auth.md#gga955c57d8720719916dd806106356fa0fa9a6fb8a4530b6a09dba2fbfdf2e6c2e9">ESL3</a> = 3,   <a href="_hdf_user_auth.md#gga955c57d8720719916dd806106356fa0fa0cd05a2adda94d3c676fca84f96c0638">ESL0</a> = 0, <a href="_hdf_user_auth.md#gga955c57d8720719916dd806106356fa0fae6a34bbf2764541238bf81569faf29d3">ESL1</a> = 1, <a href="_hdf_user_auth.md#gga955c57d8720719916dd806106356fa0fa8f898bca57625d548a011ba2aaf4285f">ESL2</a> = 2, <a href="_hdf_user_auth.md#gga955c57d8720719916dd806106356fa0fa9a6fb8a4530b6a09dba2fbfdf2e6c2e9">ESL3</a> = 3,   <a href="_hdf_user_auth.md#gga955c57d8720719916dd806106356fa0fa0cd05a2adda94d3c676fca84f96c0638">ESL0</a> = 0, <a href="_hdf_user_auth.md#gga955c57d8720719916dd806106356fa0fae6a34bbf2764541238bf81569faf29d3">ESL1</a> = 1, <a href="_hdf_user_auth.md#gga955c57d8720719916dd806106356fa0fa8f898bca57625d548a011ba2aaf4285f">ESL2</a> = 2, <a href="_hdf_user_auth.md#gga955c57d8720719916dd806106356fa0fa9a6fb8a4530b6a09dba2fbfdf2e6c2e9">ESL3</a> = 3 }</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p747298066083932"><a name="p747298066083932"></a><a name="p747298066083932"></a>枚举执行器安全等级。 <a href="_hdf_face_auth.md#ga955c57d8720719916dd806106356fa0f">更多...</a></p>
</td>
</tr>
<tr id="row1590262705083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1105987357083932"><a name="p1105987357083932"></a><a name="p1105987357083932"></a><a href="_hdf_face_auth.md#ga5633c8cc52bef1a4df7539c7bb6febe7">CommandId</a> : int { <a href="_hdf_pin_auth.md#gga5633c8cc52bef1a4df7539c7bb6febe7aef06794dc31ae453a7541e94ff9b91f9">LOCK_TEMPLATE</a> = 1, <a href="_hdf_pin_auth.md#gga5633c8cc52bef1a4df7539c7bb6febe7aa08e755bda3ab12a2bb435f63b9f55f4">UNLOCK_TEMPLATE</a> = 2, <a href="_hdf_pin_auth.md#gga5633c8cc52bef1a4df7539c7bb6febe7a68bc2d8d236ae8bc93b213bbfbd36741">VENDOR_COMMAND_BEGIN</a> = 10000, <a href="_hdf_pin_auth.md#gga5633c8cc52bef1a4df7539c7bb6febe7a88ec7d5086d2469ba843c7fcceade8a6">DEFAULT</a> = 0 }</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p282401638083932"><a name="p282401638083932"></a><a name="p282401638083932"></a>枚举人脸认证功能相关操作命令。 <a href="_hdf_face_auth.md#ga5633c8cc52bef1a4df7539c7bb6febe7">更多...</a></p>
</td>
</tr>
<tr id="row1582388955083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p273402293083932"><a name="p273402293083932"></a><a name="p273402293083932"></a><a href="_hdf_face_auth.md#gafe283e29a705391d97054a4b9d5fe007">FaceTipsCode</a> : int {   <a href="_hdf_face_auth.md#ggafe283e29a705391d97054a4b9d5fe007aa973b57b70bddf6e04ea0d1d8ac84bbc">FACE_AUTH_TIP_TOO_BRIGHT</a> = 1, <a href="_hdf_face_auth.md#ggafe283e29a705391d97054a4b9d5fe007a9e812580c2600ebd4847ac05478805fe">FACE_AUTH_TIP_TOO_DARK</a> = 2, <a href="_hdf_face_auth.md#ggafe283e29a705391d97054a4b9d5fe007adbd6a2cd4effac8f2d08a406c21cee17">FACE_AUTH_TIP_TOO_CLOSE</a> = 3, <a href="_hdf_face_auth.md#ggafe283e29a705391d97054a4b9d5fe007a557c72d5d5dd9cc4ca52406d442a085e">FACE_AUTH_TIP_TOO_FAR</a> = 4,   <a href="_hdf_face_auth.md#ggafe283e29a705391d97054a4b9d5fe007ac573361a2c459a0d0f95f7691819611b">FACE_AUTH_TIP_TOO_HIGH</a> = 5, <a href="_hdf_face_auth.md#ggafe283e29a705391d97054a4b9d5fe007a1fbbe62377b7746848761d4fc1e591d8">FACE_AUTH_TIP_TOO_LOW</a> = 6, <a href="_hdf_face_auth.md#ggafe283e29a705391d97054a4b9d5fe007a8b8f69a132ab5e9e4770fbe25efe6810">FACE_AUTH_TIP_TOO_RIGHT</a> = 7, <a href="_hdf_face_auth.md#ggafe283e29a705391d97054a4b9d5fe007a4f1f1ab1bed69c0968981c6ecc52a572">FACE_AUTH_TIP_TOO_LEFT</a> = 8,   <a href="_hdf_face_auth.md#ggafe283e29a705391d97054a4b9d5fe007a19f794720c79aaeb2b2cb895eca6c4fd">FACE_AUTH_TIP_TOO_MUCH_MOTION</a> = 9, <a href="_hdf_face_auth.md#ggafe283e29a705391d97054a4b9d5fe007a93c89c83ede9a3b5a15e90a1975176b7">FACE_AUTH_TIP_POOR_GAZE</a> = 10, <a href="_hdf_face_auth.md#ggafe283e29a705391d97054a4b9d5fe007aa41ae58b84dbfe8b467de7a11ad236f8">FACE_AUTH_TIP_NOT_DETECTED</a> = 11, <a href="_hdf_face_auth.md#ggafe283e29a705391d97054a4b9d5fe007abef2f1de5f74c324a7dd8958a279caab">VENDOR_FACE_AUTH_TIP_BEGIN</a> = 10000 }</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p473451831083932"><a name="p473451831083932"></a><a name="p473451831083932"></a>枚举提示信息编码。 <a href="_hdf_face_auth.md#gafe283e29a705391d97054a4b9d5fe007">更多...</a></p>
</td>
</tr>
</tbody>
</table>

## 变量<a name="var-members"></a>

<a name="table1656818448083932"></a>
<table><thead align="left"><tr id="row744051659083932"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p525329986083932"><a name="p525329986083932"></a><a name="p525329986083932"></a>变量 名称</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1607147272083932"><a name="p1607147272083932"></a><a name="p1607147272083932"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row1462048829083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1315201920194"><a name="p1315201920194"></a><a name="p1315201920194"></a>package ohos.hdi.face_auth.v1_0</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p346903012185"><a name="p346903012185"></a><a name="p346903012185"></a>人脸认证接口的包路径</p>
</td>
</tr>
</tbody>
</table>

## **详细描述**<a name="section1384108304083932"></a>

定义人脸认证驱动的枚举类和数据结构。

**Since：**

3.2

