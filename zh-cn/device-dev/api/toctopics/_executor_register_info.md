# ExecutorRegisterInfo<a name="ZH-CN_TOPIC_0000001290840920"></a>

## **概述**<a name="section1092537736083932"></a>

**所属模块:**

[HdfUserAuth](_hdf_user_auth.md)

## **汇总**<a name="section1467282690083932"></a>

## Public 属性<a name="pub-attribs"></a>

<a name="table24004931083932"></a>
<table><thead align="left"><tr id="row825957394083932"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1315179125083932"><a name="p1315179125083932"></a><a name="p1315179125083932"></a>Public 属性</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1053634866083932"><a name="p1053634866083932"></a><a name="p1053634866083932"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row729082264083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p161433750083932"><a name="p161433750083932"></a><a name="p161433750083932"></a><a href="_executor_register_info.md#a81dabdd1c9decd917b6a315fb95e7445">authType</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1099455911083932p0"><a name="entry1099455911083932p0"></a><a name="entry1099455911083932p0"></a>用户认证凭据类型。</p>
</td>
</tr>
<tr id="row849372920083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p507251524083932"><a name="p507251524083932"></a><a name="p507251524083932"></a><a href="_executor_register_info.md#afdb8d54e0b592d31c21057ded772258a">executorRole</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry2137416881083932p0"><a name="entry2137416881083932p0"></a><a name="entry2137416881083932p0"></a>执行器角色ExecutorRole。</p>
</td>
</tr>
<tr id="row25048626083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p21955703083932"><a name="p21955703083932"></a><a name="p21955703083932"></a><a href="_executor_register_info.md#a9ca69e124b3f8f98e237307bfc00ff30">executorId</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry682838914083932p0"><a name="entry682838914083932p0"></a><a name="entry682838914083932p0"></a>既定用户认证凭据类型的执行器ID。</p>
</td>
</tr>
<tr id="row1361485407083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1511205241083932"><a name="p1511205241083932"></a><a name="p1511205241083932"></a><a href="_executor_register_info.md#a8d4dbf2ef16c873266661a7c1ff55281">executorType</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry635393857083932p0"><a name="entry635393857083932p0"></a><a name="entry635393857083932p0"></a>执行器类型，根据执行器支持的认证能力进行分类。</p>
</td>
</tr>
<tr id="row1715792482083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p241475313083932"><a name="p241475313083932"></a><a name="p241475313083932"></a><a href="_executor_register_info.md#aaf140766227a3cbffb2abc87d6a93fd5">esl</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1712445110083932p0"><a name="entry1712445110083932p0"></a><a name="entry1712445110083932p0"></a>执行器安全等级ExecutorSecureLevel。</p>
</td>
</tr>
<tr id="row1277710227083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p984960853083932"><a name="p984960853083932"></a><a name="p984960853083932"></a><a href="_executor_register_info.md#a139ab760a136715238a865101bff3b0d">publicKey</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1745374104083932p0"><a name="entry1745374104083932p0"></a><a name="entry1745374104083932p0"></a>执行器公钥，用于校验该执行器私钥签名的信息。</p>
</td>
</tr>
</tbody>
</table>

## **详细描述**<a name="section1266971750083932"></a>

执行器注册信息。

**Since：**

3.2

**Version：**

1.0

## **类成员变量说明**<a name="section728149904083932"></a>

## authType<a name="a81dabdd1c9decd917b6a315fb95e7445"></a>

```
enum AuthType ExecutorRegisterInfo::authType
```

**描述：**

用户认证凭据类型。

## esl<a name="aaf140766227a3cbffb2abc87d6a93fd5"></a>

```
enum ExecutorSecureLevel ExecutorRegisterInfo::esl
```

**描述：**

执行器安全等级ExecutorSecureLevel。

## executorId<a name="a9ca69e124b3f8f98e237307bfc00ff30"></a>

```
unsigned int ExecutorRegisterInfo::executorId
```

**描述：**

既定用户认证凭据类型的执行器ID。

## executorRole<a name="afdb8d54e0b592d31c21057ded772258a"></a>

```
enum ExecutorRole ExecutorRegisterInfo::executorRole
```

**描述：**

执行器角色ExecutorRole。

## executorType<a name="a8d4dbf2ef16c873266661a7c1ff55281"></a>

```
unsigned int ExecutorRegisterInfo::executorType
```

**描述：**

执行器类型，根据执行器支持的认证能力进行分类。

## publicKey<a name="a139ab760a136715238a865101bff3b0d"></a>

```
unsigned char [] ExecutorRegisterInfo::publicKey
```

**描述：**

执行器公钥，用于校验该执行器私钥签名的信息。

