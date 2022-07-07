# IUserAuthInterface<a name="ZH-CN_TOPIC_0000001290721092"></a>

## **概述**<a name="section1227191444083932"></a>

**所属模块:**

[HdfUserAuth](_hdf_user_auth.md)

## **汇总**<a name="section1687275211083932"></a>

## Public 成员函数<a name="pub-methods"></a>

<a name="table337346372083932"></a>
<table><thead align="left"><tr id="row1773557114083932"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1337605810083932"><a name="p1337605810083932"></a><a name="p1337605810083932"></a>Public 成员函数</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p2147277193083932"><a name="p2147277193083932"></a><a name="p2147277193083932"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row237780163083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p530284515083932"><a name="p530284515083932"></a><a name="p530284515083932"></a><a href="interface_i_user_auth_interface.md#af5e9a41099b747e8743b397212d8add5">Init</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1610472950083932"><a name="p1610472950083932"></a><a name="p1610472950083932"></a>初始化用户认证驱动缓存信息，用于用户认证框架进程启动时初始化信息。 <a href="interface_i_user_auth_interface.md#af5e9a41099b747e8743b397212d8add5">更多...</a></p>
</td>
</tr>
<tr id="row837766621083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p33213820083932"><a name="p33213820083932"></a><a name="p33213820083932"></a><a href="interface_i_user_auth_interface.md#a88556ba0180af521b155ea8da6a32e0f">AddExecutor</a> ([in] struct <a href="_executor_register_info.md">ExecutorRegisterInfo</a> info, [out] unsigned long index, [out] unsigned char[] publicKey, [out] unsigned long[] templateIds)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p382646333083932"><a name="p382646333083932"></a><a name="p382646333083932"></a>添加认证执行器来获取认证能力，用于各认证基础服务如口令认证服务等将认证能力对接到用户认证框架。 <a href="interface_i_user_auth_interface.md#a88556ba0180af521b155ea8da6a32e0f">更多...</a></p>
</td>
</tr>
<tr id="row1955457243083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1774947362083932"><a name="p1774947362083932"></a><a name="p1774947362083932"></a><a href="interface_i_user_auth_interface.md#aec2e48c0586bf349cb33251adc995bff">DeleteExecutor</a> ([in] unsigned long index)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1496221575083932"><a name="p1496221575083932"></a><a name="p1496221575083932"></a>删除执行器，用于清理失效的执行器信息。 <a href="interface_i_user_auth_interface.md#aec2e48c0586bf349cb33251adc995bff">更多...</a></p>
</td>
</tr>
<tr id="row566313535083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1115072246083932"><a name="p1115072246083932"></a><a name="p1115072246083932"></a><a href="interface_i_user_auth_interface.md#a029552b8f757dfc1956ee757b4b4b8cf">OpenSession</a> ([in] int userId, [out] unsigned char[] challenge)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p609769525083932"><a name="p609769525083932"></a><a name="p609769525083932"></a>开启一个认证凭据管理会话，用于在请求管理用户认证凭据前获取有效挑战值。 <a href="interface_i_user_auth_interface.md#a029552b8f757dfc1956ee757b4b4b8cf">更多...</a></p>
</td>
</tr>
<tr id="row81708018083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1099053623083932"><a name="p1099053623083932"></a><a name="p1099053623083932"></a><a href="interface_i_user_auth_interface.md#af908de55815cddc4b0d688f3c250b793">CloseSession</a> ([in] int userId)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1762575742083932"><a name="p1762575742083932"></a><a name="p1762575742083932"></a>关闭认证凭据管理会话，完成用户认证凭据管理请求处理后，调用该接口使原挑战值失效。 <a href="interface_i_user_auth_interface.md#af908de55815cddc4b0d688f3c250b793">更多...</a></p>
</td>
</tr>
<tr id="row182156736083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1606675899083932"><a name="p1606675899083932"></a><a name="p1606675899083932"></a><a href="interface_i_user_auth_interface.md#adb62cd9b5c1940116a7a16a8e3154877">BeginEnrollment</a> ([in] int userId, [in] unsigned char[] authToken, [in] struct <a href="_enroll_param.md">EnrollParam</a> param, [out] struct <a href="_schedule_info.md">ScheduleInfo</a> info)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1794004419083932"><a name="p1794004419083932"></a><a name="p1794004419083932"></a>开始注册用户认证凭据。当注册凭据类型为口令且该用户已经注册了口令凭据时，将会更新口令凭据。 <a href="interface_i_user_auth_interface.md#adb62cd9b5c1940116a7a16a8e3154877">更多...</a></p>
</td>
</tr>
<tr id="row605207179083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1961986248083932"><a name="p1961986248083932"></a><a name="p1961986248083932"></a><a href="interface_i_user_auth_interface.md#a9b2d4811a1b3892d4fb5ec5bf38ad7da">UpdateEnrollmentResult</a> ([in] int userId, [in] unsigned char[] scheduleResult, [out] unsigned long credentialId, [out] struct <a href="_credential_info.md">CredentialInfo</a> oldInfo)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1749896479083932"><a name="p1749896479083932"></a><a name="p1749896479083932"></a>更新用户凭据注册结果，完成凭据注册。 <a href="interface_i_user_auth_interface.md#a9b2d4811a1b3892d4fb5ec5bf38ad7da">更多...</a></p>
</td>
</tr>
<tr id="row2011522520083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p308468014083932"><a name="p308468014083932"></a><a name="p308468014083932"></a><a href="interface_i_user_auth_interface.md#a1da08f174a805983974a07e69de9178f">CancelEnrollment</a> ([in] int userId)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1200009984083932"><a name="p1200009984083932"></a><a name="p1200009984083932"></a>取消注册请求。 <a href="interface_i_user_auth_interface.md#a1da08f174a805983974a07e69de9178f">更多...</a></p>
</td>
</tr>
<tr id="row881606033083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1856502907083932"><a name="p1856502907083932"></a><a name="p1856502907083932"></a><a href="interface_i_user_auth_interface.md#a067653f2c734d874eca3333327ecb105">DeleteCredential</a> ([in] int userId, [in] unsigned long credentialId, [in] unsigned char[] authToken, [out] struct <a href="_credential_info.md">CredentialInfo</a> info)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p957119779083932"><a name="p957119779083932"></a><a name="p957119779083932"></a>删除用户凭据信息。 <a href="interface_i_user_auth_interface.md#a067653f2c734d874eca3333327ecb105">更多...</a></p>
</td>
</tr>
<tr id="row1050076661083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p741356916083932"><a name="p741356916083932"></a><a name="p741356916083932"></a><a href="interface_i_user_auth_interface.md#a7cf41a857d2271384083e735a27ae99b">GetCredential</a> ([in] int userId, [in] enum <a href="_hdf_face_auth.md#ga89fed1f0b2adadc0ab678c1c6b9570a1">AuthType</a> authType, [out] struct <a href="_credential_info.md">CredentialInfo</a>[] infos)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1809243916083932"><a name="p1809243916083932"></a><a name="p1809243916083932"></a>查询用户凭据信息。 <a href="interface_i_user_auth_interface.md#a7cf41a857d2271384083e735a27ae99b">更多...</a></p>
</td>
</tr>
<tr id="row424978766083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p363377693083932"><a name="p363377693083932"></a><a name="p363377693083932"></a><a href="interface_i_user_auth_interface.md#ac90c35540e9b890e41e2d6c487050cfb">GetSecureInfo</a> ([in] int userId, [out] unsigned long secureUid, [out] struct <a href="_enrolled_info.md">EnrolledInfo</a>[] infos)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1260341772083932"><a name="p1260341772083932"></a><a name="p1260341772083932"></a>查询用户安全信息。 <a href="interface_i_user_auth_interface.md#ac90c35540e9b890e41e2d6c487050cfb">更多...</a></p>
</td>
</tr>
<tr id="row1698380496083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p348934836083932"><a name="p348934836083932"></a><a name="p348934836083932"></a><a href="interface_i_user_auth_interface.md#ab1d298ace80663cebc2ff4b70d4deb51">DeleteUser</a> ([in] int userId, [in] unsigned char[] authToken, [out] struct <a href="_credential_info.md">CredentialInfo</a>[] deletedInfos)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1155413433083932"><a name="p1155413433083932"></a><a name="p1155413433083932"></a>删除用户口令认证凭据，在用户IAM系统内删除该用户，该请求由用户触发。 <a href="interface_i_user_auth_interface.md#ab1d298ace80663cebc2ff4b70d4deb51">更多...</a></p>
</td>
</tr>
<tr id="row1374675279083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1108903019083932"><a name="p1108903019083932"></a><a name="p1108903019083932"></a><a href="interface_i_user_auth_interface.md#a94f878edba5af952a12f07efe34ed0af">EnforceDeleteUser</a> ([in] int userId, [out] struct <a href="_credential_info.md">CredentialInfo</a>[] deletedInfos)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1709048810083932"><a name="p1709048810083932"></a><a name="p1709048810083932"></a>强制删除用户，该请求由系统内管理用户的模块触发。 <a href="interface_i_user_auth_interface.md#a94f878edba5af952a12f07efe34ed0af">更多...</a></p>
</td>
</tr>
<tr id="row1134046471083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p823154183083932"><a name="p823154183083932"></a><a name="p823154183083932"></a><a href="interface_i_user_auth_interface.md#aa9883fcf175fa45d66cd491fb70e9789">BeginAuthentication</a> ([in] unsigned long contextId, [in] struct <a href="_auth_solution.md">AuthSolution</a> param, [out] struct <a href="_schedule_info.md">ScheduleInfo</a>[] scheduleInfos)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1894714598083932"><a name="p1894714598083932"></a><a name="p1894714598083932"></a>开始认证用户，并生成认证方案。 <a href="interface_i_user_auth_interface.md#aa9883fcf175fa45d66cd491fb70e9789">更多...</a></p>
</td>
</tr>
<tr id="row1542194983083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p295656359083932"><a name="p295656359083932"></a><a name="p295656359083932"></a><a href="interface_i_user_auth_interface.md#a544d7d05371d9ed836fd05cc925e6aee">UpdateAuthenticationResult</a> ([in] unsigned long contextId, [in] unsigned char[] scheduleResult, [out] struct <a href="_auth_result_info.md">AuthResultInfo</a> info)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p562969156083932"><a name="p562969156083932"></a><a name="p562969156083932"></a>更新认证结果，评估认证方案的认证结果。 <a href="interface_i_user_auth_interface.md#a544d7d05371d9ed836fd05cc925e6aee">更多...</a></p>
</td>
</tr>
<tr id="row2035860306083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p439208521083932"><a name="p439208521083932"></a><a name="p439208521083932"></a><a href="interface_i_user_auth_interface.md#a1b40d54f0ca53c9861047e1292da1bdd">CancelAuthentication</a> ([in] unsigned long contextId)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p755241698083932"><a name="p755241698083932"></a><a name="p755241698083932"></a>取消用户认证请求。 <a href="interface_i_user_auth_interface.md#a1b40d54f0ca53c9861047e1292da1bdd">更多...</a></p>
</td>
</tr>
<tr id="row926339190083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2065978886083932"><a name="p2065978886083932"></a><a name="p2065978886083932"></a><a href="interface_i_user_auth_interface.md#a7d5cc3d88eb38be13b6e11e3f040d295">BeginIdentification</a> ([in] unsigned long contextId, [in] enum <a href="_hdf_face_auth.md#ga89fed1f0b2adadc0ab678c1c6b9570a1">AuthType</a> authType, [in] byte[] challenge, [in] unsigned int executorId, [out] struct <a href="_schedule_info.md">ScheduleInfo</a> scheduleInfo)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1503231347083932"><a name="p1503231347083932"></a><a name="p1503231347083932"></a>开始用户身份识别，并生成识别方案。 <a href="interface_i_user_auth_interface.md#a7d5cc3d88eb38be13b6e11e3f040d295">更多...</a></p>
</td>
</tr>
<tr id="row1093861273083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p884240519083932"><a name="p884240519083932"></a><a name="p884240519083932"></a><a href="interface_i_user_auth_interface.md#a0b1f179c1f2c2a0c74dccf8748ba522b">UpdateIdentificationResult</a> ([in] unsigned long contextId, [in] unsigned char[] scheduleResult, [out] struct <a href="_identify_result_info.md">IdentifyResultInfo</a> info)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p440565883083932"><a name="p440565883083932"></a><a name="p440565883083932"></a>更新用户身份识别结果，生成身份识别方案的结果 <a href="interface_i_user_auth_interface.md#a0b1f179c1f2c2a0c74dccf8748ba522b">更多...</a></p>
</td>
</tr>
<tr id="row1365216154083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p39878494083932"><a name="p39878494083932"></a><a name="p39878494083932"></a><a href="interface_i_user_auth_interface.md#ac40da86ed33f222e80fa3352200898c5">CancelIdentification</a> ([in] unsigned long contextId)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2088507364083932"><a name="p2088507364083932"></a><a name="p2088507364083932"></a>取消用户身份识别请求。 <a href="interface_i_user_auth_interface.md#ac40da86ed33f222e80fa3352200898c5">更多...</a></p>
</td>
</tr>
<tr id="row263537786083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1418221030083932"><a name="p1418221030083932"></a><a name="p1418221030083932"></a><a href="interface_i_user_auth_interface.md#ab6a147bddfc41f1b92ef59ed8cd4c5e0">GetAuthTrustLevel</a> ([in] int userId, [in] enum <a href="_hdf_face_auth.md#ga89fed1f0b2adadc0ab678c1c6b9570a1">AuthType</a> authType, [out] unsigned int authTrustLevel)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p391835328083932"><a name="p391835328083932"></a><a name="p391835328083932"></a>获取当前认证类型的认证结果可信等级。 <a href="interface_i_user_auth_interface.md#ab6a147bddfc41f1b92ef59ed8cd4c5e0">更多...</a></p>
</td>
</tr>
<tr id="row522415719083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p651794351083932"><a name="p651794351083932"></a><a name="p651794351083932"></a><a href="interface_i_user_auth_interface.md#a7992c1c140913aa69ef8ab7679434fe2">GetValidSolution</a> ([in] int userId, [in] enum <a href="_hdf_face_auth.md#ga89fed1f0b2adadc0ab678c1c6b9570a1">AuthType</a>[] authTypes, [in] unsigned int authTrustLevel, [out] enum <a href="_hdf_face_auth.md#ga89fed1f0b2adadc0ab678c1c6b9570a1">AuthType</a>[] validTypes)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p723525310083932"><a name="p723525310083932"></a><a name="p723525310083932"></a>获取指定认证结果可信等级下有效的认证方式。 <a href="interface_i_user_auth_interface.md#a7992c1c140913aa69ef8ab7679434fe2">更多...</a></p>
</td>
</tr>
</tbody>
</table>

## **详细描述**<a name="section418964124083932"></a>

声明用户认证驱动的API接口。

**Since：**

3.2

**Version：**

1.0

## **成员函数说明**<a name="section1867228215083932"></a>

## AddExecutor\(\)<a name="a88556ba0180af521b155ea8da6a32e0f"></a>

```
IUserAuthInterface::AddExecutor ([in] struct ExecutorRegisterInfo info, [out] unsigned long index, [out] unsigned char[] publicKey, [out] unsigned long[] templateIds )
```

**描述：**

添加认证执行器来获取认证能力，用于各认证基础服务如口令认证服务等将认证能力对接到用户认证框架。

**参数：**

<a name="table990851221083932"></a>
<table><thead align="left"><tr id="row9082387083932"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p829790831083932"><a name="p829790831083932"></a><a name="p829790831083932"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1211834419083932"><a name="p1211834419083932"></a><a name="p1211834419083932"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row1889450046083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1639261350083932p0"><a name="entry1639261350083932p0"></a><a name="entry1639261350083932p0"></a>info</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry381310006083932p0"><a name="entry381310006083932p0"></a><a name="entry381310006083932p0"></a>执行器注册信息<a href="_executor_register_info.md">ExecutorRegisterInfo</a>。</p>
</td>
</tr>
<tr id="row1247028229083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1464545305083932p0"><a name="entry1464545305083932p0"></a><a name="entry1464545305083932p0"></a>index</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1817052948083932p0"><a name="entry1817052948083932p0"></a><a name="entry1817052948083932p0"></a>用户认证框架的执行器索引。</p>
</td>
</tr>
<tr id="row152322463083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry2056922786083932p0"><a name="entry2056922786083932p0"></a><a name="entry2056922786083932p0"></a>publicKey</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1790567386083932p0"><a name="entry1790567386083932p0"></a><a name="entry1790567386083932p0"></a>用户认证框架公钥。</p>
</td>
</tr>
<tr id="row1779359246083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry199072245083932p0"><a name="entry199072245083932p0"></a><a name="entry199072245083932p0"></a>templateIds</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1027340544083932p0"><a name="entry1027340544083932p0"></a><a name="entry1027340544083932p0"></a>该执行器已注册的模版ID列表。</p>
</td>
</tr>
</tbody>
</table>

**返回：**

0 表示操作成功。

非0 表示操作失败。

## BeginAuthentication\(\)<a name="aa9883fcf175fa45d66cd491fb70e9789"></a>

```
IUserAuthInterface::BeginAuthentication ([in] unsigned long contextId, [in] struct AuthSolution param, [out] struct ScheduleInfo[] scheduleInfos )
```

**描述：**

开始认证用户，并生成认证方案。

**参数：**

<a name="table961547038083932"></a>
<table><thead align="left"><tr id="row1395710033083932"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p720378497083932"><a name="p720378497083932"></a><a name="p720378497083932"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p517007085083932"><a name="p517007085083932"></a><a name="p517007085083932"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row1548268194083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1169608776083932p0"><a name="entry1169608776083932p0"></a><a name="entry1169608776083932p0"></a>contextId</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry794872334083932p0"><a name="entry794872334083932p0"></a><a name="entry794872334083932p0"></a>上下文索引。</p>
</td>
</tr>
<tr id="row1164120814083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry2099890379083932p0"><a name="entry2099890379083932p0"></a><a name="entry2099890379083932p0"></a>param</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1191232542083932p0"><a name="entry1191232542083932p0"></a><a name="entry1191232542083932p0"></a>认证方案<a href="_auth_solution.md">AuthSolution</a>。</p>
</td>
</tr>
<tr id="row1857440955083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1786003927083932p0"><a name="entry1786003927083932p0"></a><a name="entry1786003927083932p0"></a>scheduleInfos</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry595746620083932p0"><a name="entry595746620083932p0"></a><a name="entry595746620083932p0"></a>调度信息<a href="_schedule_info.md">ScheduleInfo</a>。</p>
</td>
</tr>
</tbody>
</table>

**返回：**

0 表示操作成功。

非0 表示操作失败。

## BeginEnrollment\(\)<a name="adb62cd9b5c1940116a7a16a8e3154877"></a>

```
IUserAuthInterface::BeginEnrollment ([in] int userId, [in] unsigned char[] authToken, [in] struct EnrollParam param, [out] struct ScheduleInfo info )
```

**描述：**

开始注册用户认证凭据。当注册凭据类型为口令且该用户已经注册了口令凭据时，将会更新口令凭据。

**参数：**

<a name="table48892431083932"></a>
<table><thead align="left"><tr id="row639097849083932"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1976332964083932"><a name="p1976332964083932"></a><a name="p1976332964083932"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p357109677083932"><a name="p357109677083932"></a><a name="p357109677083932"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row487055845083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1089380751083932p0"><a name="entry1089380751083932p0"></a><a name="entry1089380751083932p0"></a>userId</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1791023633083932p0"><a name="entry1791023633083932p0"></a><a name="entry1791023633083932p0"></a>用户ID。</p>
</td>
</tr>
<tr id="row2109551678083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1781632705083932p0"><a name="entry1781632705083932p0"></a><a name="entry1781632705083932p0"></a>authToken</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry512534102083932p0"><a name="entry512534102083932p0"></a><a name="entry512534102083932p0"></a>用户口令认证令牌。</p>
</td>
</tr>
<tr id="row1814408570083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry68027083083932p0"><a name="entry68027083083932p0"></a><a name="entry68027083083932p0"></a>param</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1452138267083932p0"><a name="entry1452138267083932p0"></a><a name="entry1452138267083932p0"></a>注册凭据参数<a href="_enroll_param.md">EnrollParam</a>。</p>
</td>
</tr>
<tr id="row2041480311083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1877182120083932p0"><a name="entry1877182120083932p0"></a><a name="entry1877182120083932p0"></a>info</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1017925418083932p0"><a name="entry1017925418083932p0"></a><a name="entry1017925418083932p0"></a>调度信息<a href="_schedule_info.md">ScheduleInfo</a>。</p>
</td>
</tr>
</tbody>
</table>

**返回：**

0 表示操作成功。

非0 表示操作失败。

## BeginIdentification\(\)<a name="a7d5cc3d88eb38be13b6e11e3f040d295"></a>

```
IUserAuthInterface::BeginIdentification ([in] unsigned long contextId, [in] enum AuthType authType, [in] byte[] challenge, [in] unsigned int executorId, [out] struct ScheduleInfo scheduleInfo )
```

**描述：**

开始用户身份识别，并生成识别方案。

**参数：**

<a name="table193794024083932"></a>
<table><thead align="left"><tr id="row423399631083932"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p472547653083932"><a name="p472547653083932"></a><a name="p472547653083932"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p367625832083932"><a name="p367625832083932"></a><a name="p367625832083932"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row451647715083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1139312400083932p0"><a name="entry1139312400083932p0"></a><a name="entry1139312400083932p0"></a>contextId</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry726142688083932p0"><a name="entry726142688083932p0"></a><a name="entry726142688083932p0"></a>上下文索引。</p>
</td>
</tr>
<tr id="row1786084697083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1435179964083932p0"><a name="entry1435179964083932p0"></a><a name="entry1435179964083932p0"></a>authType</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1178225957083932p0"><a name="entry1178225957083932p0"></a><a name="entry1178225957083932p0"></a>用户身份识别类型AuthType}。</p>
</td>
</tr>
<tr id="row180343461083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1302344505083932p0"><a name="entry1302344505083932p0"></a><a name="entry1302344505083932p0"></a>scheduleInfo</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry2103416048083932p0"><a name="entry2103416048083932p0"></a><a name="entry2103416048083932p0"></a>调度信息<a href="_schedule_info.md">ScheduleInfo</a>。</p>
</td>
</tr>
</tbody>
</table>

**返回：**

0 表示操作成功。

非0 表示操作失败。

## CancelAuthentication\(\)<a name="a1b40d54f0ca53c9861047e1292da1bdd"></a>

```
IUserAuthInterface::CancelAuthentication ([in] unsigned long contextId)
```

**描述：**

取消用户认证请求。

**参数：**

<a name="table868857070083932"></a>
<table><thead align="left"><tr id="row1247270366083932"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1698556444083932"><a name="p1698556444083932"></a><a name="p1698556444083932"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1230089482083932"><a name="p1230089482083932"></a><a name="p1230089482083932"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row1494189544083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry502417982083932p0"><a name="entry502417982083932p0"></a><a name="entry502417982083932p0"></a>contextId</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1134275392083932p0"><a name="entry1134275392083932p0"></a><a name="entry1134275392083932p0"></a>上下文索引。</p>
</td>
</tr>
</tbody>
</table>

**返回：**

0 表示操作成功。

非0 表示操作失败。

## CancelEnrollment\(\)<a name="a1da08f174a805983974a07e69de9178f"></a>

```
IUserAuthInterface::CancelEnrollment ([in] int userId)
```

**描述：**

取消注册请求。

**参数：**

<a name="table795250790083932"></a>
<table><thead align="left"><tr id="row793857438083932"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p85000552083932"><a name="p85000552083932"></a><a name="p85000552083932"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p13215484083932"><a name="p13215484083932"></a><a name="p13215484083932"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row1820412342083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry565378204083932p0"><a name="entry565378204083932p0"></a><a name="entry565378204083932p0"></a>userId</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry2047443311083932p0"><a name="entry2047443311083932p0"></a><a name="entry2047443311083932p0"></a>用户ID。</p>
</td>
</tr>
</tbody>
</table>

**返回：**

0 表示操作成功。

非0 表示操作失败。

## CancelIdentification\(\)<a name="ac40da86ed33f222e80fa3352200898c5"></a>

```
IUserAuthInterface::CancelIdentification ([in] unsigned long contextId)
```

**描述：**

取消用户身份识别请求。

**参数：**

<a name="table1820492707083932"></a>
<table><thead align="left"><tr id="row1751521537083932"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p20203911083932"><a name="p20203911083932"></a><a name="p20203911083932"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p307007141083932"><a name="p307007141083932"></a><a name="p307007141083932"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row1553821422083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry710081150083932p0"><a name="entry710081150083932p0"></a><a name="entry710081150083932p0"></a>contextId</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1594577745083932p0"><a name="entry1594577745083932p0"></a><a name="entry1594577745083932p0"></a>上下文索引。</p>
</td>
</tr>
</tbody>
</table>

**返回：**

0 表示操作成功。

非0 表示操作失败。

## CloseSession\(\)<a name="af908de55815cddc4b0d688f3c250b793"></a>

```
IUserAuthInterface::CloseSession ([in] int userId)
```

**描述：**

关闭认证凭据管理会话，完成用户认证凭据管理请求处理后，调用该接口使原挑战值失效。

**参数：**

<a name="table303600907083932"></a>
<table><thead align="left"><tr id="row1407573218083932"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p309868852083932"><a name="p309868852083932"></a><a name="p309868852083932"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1047822580083932"><a name="p1047822580083932"></a><a name="p1047822580083932"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row1852835697083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1947818347083932p0"><a name="entry1947818347083932p0"></a><a name="entry1947818347083932p0"></a>userId</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry2131342620083932p0"><a name="entry2131342620083932p0"></a><a name="entry2131342620083932p0"></a>用户ID。</p>
</td>
</tr>
</tbody>
</table>

**返回：**

0 表示操作成功。

非0 表示操作失败。

## DeleteCredential\(\)<a name="a067653f2c734d874eca3333327ecb105"></a>

```
IUserAuthInterface::DeleteCredential ([in] int userId, [in] unsigned long credentialId, [in] unsigned char[] authToken, [out] struct CredentialInfo info )
```

**描述：**

删除用户凭据信息。

**参数：**

<a name="table950509375083932"></a>
<table><thead align="left"><tr id="row1033785737083932"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p2091355750083932"><a name="p2091355750083932"></a><a name="p2091355750083932"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p622585002083932"><a name="p622585002083932"></a><a name="p622585002083932"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row1120883041083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry948683558083932p0"><a name="entry948683558083932p0"></a><a name="entry948683558083932p0"></a>userId</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry169561412083932p0"><a name="entry169561412083932p0"></a><a name="entry169561412083932p0"></a>用户ID。</p>
</td>
</tr>
<tr id="row1418929846083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry769533807083932p0"><a name="entry769533807083932p0"></a><a name="entry769533807083932p0"></a>credentialId</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1973020356083932p0"><a name="entry1973020356083932p0"></a><a name="entry1973020356083932p0"></a>凭据ID。</p>
</td>
</tr>
<tr id="row1682666873083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1623701451083932p0"><a name="entry1623701451083932p0"></a><a name="entry1623701451083932p0"></a>authToken</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1951144380083932p0"><a name="entry1951144380083932p0"></a><a name="entry1951144380083932p0"></a>用户口令认证令牌。</p>
</td>
</tr>
<tr id="row372757927083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1514129914083932p0"><a name="entry1514129914083932p0"></a><a name="entry1514129914083932p0"></a>info</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry532657438083932p0"><a name="entry532657438083932p0"></a><a name="entry532657438083932p0"></a>删除的凭据信息<a href="_credential_info.md">CredentialInfo</a>。</p>
</td>
</tr>
</tbody>
</table>

**返回：**

0 表示操作成功。

非0 表示操作失败。

## DeleteExecutor\(\)<a name="aec2e48c0586bf349cb33251adc995bff"></a>

```
IUserAuthInterface::DeleteExecutor ([in] unsigned long index)
```

**描述：**

删除执行器，用于清理失效的执行器信息。

**参数：**

<a name="table1906706757083932"></a>
<table><thead align="left"><tr id="row2044674325083932"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p486695874083932"><a name="p486695874083932"></a><a name="p486695874083932"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p545536922083932"><a name="p545536922083932"></a><a name="p545536922083932"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row216903695083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry229901027083932p0"><a name="entry229901027083932p0"></a><a name="entry229901027083932p0"></a>index</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry61529498083932p0"><a name="entry61529498083932p0"></a><a name="entry61529498083932p0"></a>用户认证框架的执行器索引。</p>
</td>
</tr>
</tbody>
</table>

**返回：**

0 表示操作成功。

非0 表示操作失败。

## DeleteUser\(\)<a name="ab1d298ace80663cebc2ff4b70d4deb51"></a>

```
IUserAuthInterface::DeleteUser ([in] int userId, [in] unsigned char[] authToken, [out] struct CredentialInfo[] deletedInfos )
```

**描述：**

删除用户口令认证凭据，在用户IAM系统内删除该用户，该请求由用户触发。

**参数：**

<a name="table51347317083932"></a>
<table><thead align="left"><tr id="row1242908163083932"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p2019950456083932"><a name="p2019950456083932"></a><a name="p2019950456083932"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1215194624083932"><a name="p1215194624083932"></a><a name="p1215194624083932"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row1414767989083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1865844633083932p0"><a name="entry1865844633083932p0"></a><a name="entry1865844633083932p0"></a>userId</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry352140196083932p0"><a name="entry352140196083932p0"></a><a name="entry352140196083932p0"></a>用户ID。</p>
</td>
</tr>
<tr id="row110953004083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1519273053083932p0"><a name="entry1519273053083932p0"></a><a name="entry1519273053083932p0"></a>authToken</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry415406670083932p0"><a name="entry415406670083932p0"></a><a name="entry415406670083932p0"></a>用户口令认证令牌。</p>
</td>
</tr>
<tr id="row1579444541083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1659795622083932p0"><a name="entry1659795622083932p0"></a><a name="entry1659795622083932p0"></a>deletedInfos</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry463449134083932p0"><a name="entry463449134083932p0"></a><a name="entry463449134083932p0"></a>删除的凭据信息<a href="_credential_info.md">CredentialInfo</a>。</p>
</td>
</tr>
</tbody>
</table>

**返回：**

0 表示操作成功。

非0 表示操作失败。

## EnforceDeleteUser\(\)<a name="a94f878edba5af952a12f07efe34ed0af"></a>

```
IUserAuthInterface::EnforceDeleteUser ([in] int userId, [out] struct CredentialInfo[] deletedInfos )
```

**描述：**

强制删除用户，该请求由系统内管理用户的模块触发。

**参数：**

<a name="table1762860646083932"></a>
<table><thead align="left"><tr id="row1621330852083932"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1593810293083932"><a name="p1593810293083932"></a><a name="p1593810293083932"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p267838758083932"><a name="p267838758083932"></a><a name="p267838758083932"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row1129740061083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry2066834820083932p0"><a name="entry2066834820083932p0"></a><a name="entry2066834820083932p0"></a>userId</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1273281301083932p0"><a name="entry1273281301083932p0"></a><a name="entry1273281301083932p0"></a>用户ID。</p>
</td>
</tr>
<tr id="row1268227141083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry723162035083932p0"><a name="entry723162035083932p0"></a><a name="entry723162035083932p0"></a>deletedInfos</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry683691791083932p0"><a name="entry683691791083932p0"></a><a name="entry683691791083932p0"></a>删除的凭据信息<a href="_credential_info.md">CredentialInfo</a>。</p>
</td>
</tr>
</tbody>
</table>

**返回：**

0 表示操作成功。

非0 表示操作失败。

## GetAuthTrustLevel\(\)<a name="ab6a147bddfc41f1b92ef59ed8cd4c5e0"></a>

```
IUserAuthInterface::GetAuthTrustLevel ([in] int userId, [in] enum AuthType authType, [out] unsigned int authTrustLevel )
```

**描述：**

获取当前认证类型的认证结果可信等级。

**参数：**

<a name="table172021081083932"></a>
<table><thead align="left"><tr id="row309216490083932"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1891466132083932"><a name="p1891466132083932"></a><a name="p1891466132083932"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p976915076083932"><a name="p976915076083932"></a><a name="p976915076083932"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row195755707083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1697266656083932p0"><a name="entry1697266656083932p0"></a><a name="entry1697266656083932p0"></a>userId</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry2078966445083932p0"><a name="entry2078966445083932p0"></a><a name="entry2078966445083932p0"></a>用户ID。</p>
</td>
</tr>
<tr id="row329793131083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1649136380083932p0"><a name="entry1649136380083932p0"></a><a name="entry1649136380083932p0"></a>authType</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry624465296083932p0"><a name="entry624465296083932p0"></a><a name="entry624465296083932p0"></a>认证类型<a href="_hdf_user_auth.md#ga89fed1f0b2adadc0ab678c1c6b9570a1">AuthType</a>。</p>
</td>
</tr>
<tr id="row1129966380083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry36277897083932p0"><a name="entry36277897083932p0"></a><a name="entry36277897083932p0"></a>authTrustLevel</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1329954937083932p0"><a name="entry1329954937083932p0"></a><a name="entry1329954937083932p0"></a>认证结果可信等级。</p>
</td>
</tr>
</tbody>
</table>

**返回：**

0 表示操作成功。

非0 表示操作失败。

## GetCredential\(\)<a name="a7cf41a857d2271384083e735a27ae99b"></a>

```
IUserAuthInterface::GetCredential ([in] int userId, [in] enum AuthType authType, [out] struct CredentialInfo[] infos )
```

**描述：**

查询用户凭据信息。

**参数：**

<a name="table870432680083932"></a>
<table><thead align="left"><tr id="row1148670168083932"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1650411234083932"><a name="p1650411234083932"></a><a name="p1650411234083932"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1531797458083932"><a name="p1531797458083932"></a><a name="p1531797458083932"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row1184869170083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1998442492083932p0"><a name="entry1998442492083932p0"></a><a name="entry1998442492083932p0"></a>userId</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1143734229083932p0"><a name="entry1143734229083932p0"></a><a name="entry1143734229083932p0"></a>用户ID。</p>
</td>
</tr>
<tr id="row1722632304083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry2090811929083932p0"><a name="entry2090811929083932p0"></a><a name="entry2090811929083932p0"></a>authType</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry681182585083932p0"><a name="entry681182585083932p0"></a><a name="entry681182585083932p0"></a>凭据类型<a href="_hdf_user_auth.md#ga89fed1f0b2adadc0ab678c1c6b9570a1">AuthType</a>。</p>
</td>
</tr>
<tr id="row1448320734083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry2100763661083932p0"><a name="entry2100763661083932p0"></a><a name="entry2100763661083932p0"></a>infos</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1323501121083932p0"><a name="entry1323501121083932p0"></a><a name="entry1323501121083932p0"></a>凭据信息<a href="_credential_info.md">CredentialInfo</a>。</p>
</td>
</tr>
</tbody>
</table>

**返回：**

0 表示操作成功。

非0 表示操作失败。

## GetSecureInfo\(\)<a name="ac90c35540e9b890e41e2d6c487050cfb"></a>

```
IUserAuthInterface::GetSecureInfo ([in] int userId, [out] unsigned long secureUid, [out] struct EnrolledInfo[] infos )
```

**描述：**

查询用户安全信息。

**参数：**

<a name="table1573374099083932"></a>
<table><thead align="left"><tr id="row616602898083932"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1153314517083932"><a name="p1153314517083932"></a><a name="p1153314517083932"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p645827729083932"><a name="p645827729083932"></a><a name="p645827729083932"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row1913505652083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry541448096083932p0"><a name="entry541448096083932p0"></a><a name="entry541448096083932p0"></a>userId</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry2035693773083932p0"><a name="entry2035693773083932p0"></a><a name="entry2035693773083932p0"></a>用户ID。</p>
</td>
</tr>
<tr id="row1804223788083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry485934528083932p0"><a name="entry485934528083932p0"></a><a name="entry485934528083932p0"></a>secureUid</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1382256996083932p0"><a name="entry1382256996083932p0"></a><a name="entry1382256996083932p0"></a>安全用户ID。</p>
</td>
</tr>
<tr id="row1099631963083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1706529719083932p0"><a name="entry1706529719083932p0"></a><a name="entry1706529719083932p0"></a>infos</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry144885378083932p0"><a name="entry144885378083932p0"></a><a name="entry144885378083932p0"></a>注册信息<a href="_enrolled_info.md">EnrolledInfo</a>。</p>
</td>
</tr>
</tbody>
</table>

**返回：**

0 表示操作成功。

非0 表示操作失败。

## GetValidSolution\(\)<a name="a7992c1c140913aa69ef8ab7679434fe2"></a>

```
IUserAuthInterface::GetValidSolution ([in] int userId, [in] enum AuthType[] authTypes, [in] unsigned int authTrustLevel, [out] enum AuthType[] validTypes )
```

**描述：**

获取指定认证结果可信等级下有效的认证方式。

**参数：**

<a name="table478847387083932"></a>
<table><thead align="left"><tr id="row441750221083932"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p2134473879083932"><a name="p2134473879083932"></a><a name="p2134473879083932"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1677002858083932"><a name="p1677002858083932"></a><a name="p1677002858083932"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row138693031083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1136240285083932p0"><a name="entry1136240285083932p0"></a><a name="entry1136240285083932p0"></a>userId</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1248525210083932p0"><a name="entry1248525210083932p0"></a><a name="entry1248525210083932p0"></a>用户ID。</p>
</td>
</tr>
<tr id="row1850361307083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1567486375083932p0"><a name="entry1567486375083932p0"></a><a name="entry1567486375083932p0"></a>authTypes</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1819505696083932p0"><a name="entry1819505696083932p0"></a><a name="entry1819505696083932p0"></a>用于筛选的认证方式列表<a href="_hdf_user_auth.md#ga89fed1f0b2adadc0ab678c1c6b9570a1">AuthType</a>。</p>
</td>
</tr>
<tr id="row1785999168083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1170140214083932p0"><a name="entry1170140214083932p0"></a><a name="entry1170140214083932p0"></a>authTrustLevel</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry526552446083932p0"><a name="entry526552446083932p0"></a><a name="entry526552446083932p0"></a>认证结果可信等级。</p>
</td>
</tr>
<tr id="row1716135443083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1113740888083932p0"><a name="entry1113740888083932p0"></a><a name="entry1113740888083932p0"></a>validTypes</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry542194817083932p0"><a name="entry542194817083932p0"></a><a name="entry542194817083932p0"></a>有效的认证方式列表<a href="_hdf_user_auth.md#ga89fed1f0b2adadc0ab678c1c6b9570a1">AuthType</a>。</p>
</td>
</tr>
</tbody>
</table>

**返回：**

0 表示操作成功。

非0 表示操作失败。

## Init\(\)<a name="af5e9a41099b747e8743b397212d8add5"></a>

```
IUserAuthInterface::Init ()
```

**描述：**

初始化用户认证驱动缓存信息，用于用户认证框架进程启动时初始化信息。

**返回：**

0 表示操作成功。

非0 表示操作失败。

## OpenSession\(\)<a name="a029552b8f757dfc1956ee757b4b4b8cf"></a>

```
IUserAuthInterface::OpenSession ([in] int userId, [out] unsigned char[] challenge )
```

**描述：**

开启一个认证凭据管理会话，用于在请求管理用户认证凭据前获取有效挑战值。

**参数：**

<a name="table231560708083932"></a>
<table><thead align="left"><tr id="row1468429862083932"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1305804375083932"><a name="p1305804375083932"></a><a name="p1305804375083932"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1278255151083932"><a name="p1278255151083932"></a><a name="p1278255151083932"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row1507541862083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry270774698083932p0"><a name="entry270774698083932p0"></a><a name="entry270774698083932p0"></a>userId</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1411909334083932p0"><a name="entry1411909334083932p0"></a><a name="entry1411909334083932p0"></a>用户ID。</p>
</td>
</tr>
<tr id="row1514732272083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry512100565083932p0"><a name="entry512100565083932p0"></a><a name="entry512100565083932p0"></a>challenge</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry9911549083932p0"><a name="entry9911549083932p0"></a><a name="entry9911549083932p0"></a>随机挑战值，用于生成用户身份认证令牌。</p>
</td>
</tr>
</tbody>
</table>

**返回：**

0 表示操作成功。

非0 表示操作失败。

## UpdateAuthenticationResult\(\)<a name="a544d7d05371d9ed836fd05cc925e6aee"></a>

```
IUserAuthInterface::UpdateAuthenticationResult ([in] unsigned long contextId, [in] unsigned char[] scheduleResult, [out] struct AuthResultInfo info )
```

**描述：**

更新认证结果，评估认证方案的认证结果。

**参数：**

<a name="table424471686083932"></a>
<table><thead align="left"><tr id="row455039458083932"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p506214336083932"><a name="p506214336083932"></a><a name="p506214336083932"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1613842544083932"><a name="p1613842544083932"></a><a name="p1613842544083932"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row1916012074083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry413971156083932p0"><a name="entry413971156083932p0"></a><a name="entry413971156083932p0"></a>contextId</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1631970797083932p0"><a name="entry1631970797083932p0"></a><a name="entry1631970797083932p0"></a>上下文索引。</p>
</td>
</tr>
<tr id="row1314227213083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry173022398083932p0"><a name="entry173022398083932p0"></a><a name="entry173022398083932p0"></a>scheduleResult</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1645594577083932p0"><a name="entry1645594577083932p0"></a><a name="entry1645594577083932p0"></a>执行器签发的认证结果。</p>
</td>
</tr>
<tr id="row180165424083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1778311337083932p0"><a name="entry1778311337083932p0"></a><a name="entry1778311337083932p0"></a>info</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry932859419083932p0"><a name="entry932859419083932p0"></a><a name="entry932859419083932p0"></a>认证结果信息<a href="_auth_result_info.md">AuthResultInfo</a>。</p>
</td>
</tr>
</tbody>
</table>

**返回：**

0 表示操作成功。

非0 表示操作失败。

## UpdateEnrollmentResult\(\)<a name="a9b2d4811a1b3892d4fb5ec5bf38ad7da"></a>

```
IUserAuthInterface::UpdateEnrollmentResult ([in] int userId, [in] unsigned char[] scheduleResult, [out] unsigned long credentialId, [out] struct CredentialInfo oldInfo )
```

**描述：**

更新用户凭据注册结果，完成凭据注册。

**参数：**

<a name="table1896294736083932"></a>
<table><thead align="left"><tr id="row1869700612083932"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1712544175083932"><a name="p1712544175083932"></a><a name="p1712544175083932"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1761813388083932"><a name="p1761813388083932"></a><a name="p1761813388083932"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row1467884428083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry655455660083932p0"><a name="entry655455660083932p0"></a><a name="entry655455660083932p0"></a>userId</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1580777275083932p0"><a name="entry1580777275083932p0"></a><a name="entry1580777275083932p0"></a>用户ID。</p>
</td>
</tr>
<tr id="row1424761749083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry2024255189083932p0"><a name="entry2024255189083932p0"></a><a name="entry2024255189083932p0"></a>scheduleResult</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry2134164444083932p0"><a name="entry2134164444083932p0"></a><a name="entry2134164444083932p0"></a>执行器签发的注册结果。</p>
</td>
</tr>
<tr id="row266697145083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry70243895083932p0"><a name="entry70243895083932p0"></a><a name="entry70243895083932p0"></a>credentialId</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry450042693083932p0"><a name="entry450042693083932p0"></a><a name="entry450042693083932p0"></a>凭据ID。</p>
</td>
</tr>
<tr id="row1153136277083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry2141646824083932p0"><a name="entry2141646824083932p0"></a><a name="entry2141646824083932p0"></a>oldInfo</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1060645857083932p0"><a name="entry1060645857083932p0"></a><a name="entry1060645857083932p0"></a>已经删除的凭据信息<a href="_credential_info.md">CredentialInfo</a>。</p>
</td>
</tr>
</tbody>
</table>

**返回：**

0 表示操作成功。

非0 表示操作失败。

## UpdateIdentificationResult\(\)<a name="a0b1f179c1f2c2a0c74dccf8748ba522b"></a>

```
IUserAuthInterface::UpdateIdentificationResult ([in] unsigned long contextId, [in] unsigned char[] scheduleResult, [out] struct IdentifyResultInfo info )
```

**描述：**

更新用户身份识别结果，生成身份识别方案的结果

**参数：**

<a name="table1571267427083932"></a>
<table><thead align="left"><tr id="row531421367083932"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p766552803083932"><a name="p766552803083932"></a><a name="p766552803083932"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p548694630083932"><a name="p548694630083932"></a><a name="p548694630083932"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row1907744077083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1926331975083932p0"><a name="entry1926331975083932p0"></a><a name="entry1926331975083932p0"></a>contextId</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1243616958083932p0"><a name="entry1243616958083932p0"></a><a name="entry1243616958083932p0"></a>上下文索引。</p>
</td>
</tr>
<tr id="row1828360871083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1549810734083932p0"><a name="entry1549810734083932p0"></a><a name="entry1549810734083932p0"></a>scheduleResult</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry69544906083932p0"><a name="entry69544906083932p0"></a><a name="entry69544906083932p0"></a>执行器签发的用户身份识别结果。</p>
</td>
</tr>
<tr id="row1630413999083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry224048372083932p0"><a name="entry224048372083932p0"></a><a name="entry224048372083932p0"></a>info</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry187156314083932p0"><a name="entry187156314083932p0"></a><a name="entry187156314083932p0"></a>用户身份识别结果<a href="_identify_result_info.md">IdentifyResultInfo</a>。</p>
</td>
</tr>
</tbody>
</table>

**返回：**

0 表示操作成功。

非0 表示操作失败。

