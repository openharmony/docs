# CredentialInfo<a name="ZH-CN_TOPIC_0000001290561164"></a>

## **概述**<a name="section77778516083931"></a>

**所属模块:**

[HdfUserAuth](_hdf_user_auth.md)

## **汇总**<a name="section1248649955083931"></a>

## Public 属性<a name="pub-attribs"></a>

<a name="table1220815979083931"></a>
<table><thead align="left"><tr id="row1178480788083931"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p856468291083931"><a name="p856468291083931"></a><a name="p856468291083931"></a>Public 属性</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1166463240083931"><a name="p1166463240083931"></a><a name="p1166463240083931"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row1292596916083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p481361782083931"><a name="p481361782083931"></a><a name="p481361782083931"></a><a href="_credential_info.md#aab7d1675c5b2fcbdf2699a414003efe4">credentialId</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1850076750083931p0"><a name="entry1850076750083931p0"></a><a name="entry1850076750083931p0"></a>认证凭据ID。</p>
</td>
</tr>
<tr id="row1972758463083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p542770005083931"><a name="p542770005083931"></a><a name="p542770005083931"></a><a href="_credential_info.md#a56d90609a149c7e11968697106a03ea3">index</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1008624480083931p0"><a name="entry1008624480083931p0"></a><a name="entry1008624480083931p0"></a>用户认证框架的执行器索引。</p>
</td>
</tr>
<tr id="row1286512413083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p55517824083931"><a name="p55517824083931"></a><a name="p55517824083931"></a><a href="_credential_info.md#a70f556d96c14a56faa8addd29da6c6f9">templateId</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry751294085083931p0"><a name="entry751294085083931p0"></a><a name="entry751294085083931p0"></a>认证凭据模版ID。</p>
</td>
</tr>
<tr id="row1449568959083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p528906229083931"><a name="p528906229083931"></a><a name="p528906229083931"></a><a href="_credential_info.md#aa5b6abdeb49854d35f9ac99bdfe1988a">authType</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1317141642083931p0"><a name="entry1317141642083931p0"></a><a name="entry1317141642083931p0"></a>用户认证凭据类型AuthType}。</p>
</td>
</tr>
<tr id="row1645482864083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p36089754083931"><a name="p36089754083931"></a><a name="p36089754083931"></a><a href="_credential_info.md#ac348f4304930dc17957385ecec9d0ad3">executorType</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry68331525083931p0"><a name="entry68331525083931p0"></a><a name="entry68331525083931p0"></a>执行器类型。</p>
</td>
</tr>
<tr id="row872389986083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p423391985083931"><a name="p423391985083931"></a><a name="p423391985083931"></a><a href="_credential_info.md#a2215ed43cddeebb9b9a63f9977975ed1">executorId</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1892383508083931p0"><a name="entry1892383508083931p0"></a><a name="entry1892383508083931p0"></a>既定用户认证凭据类型的执行器ID。</p>
</td>
</tr>
<tr id="row177878022083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p429240012083931"><a name="p429240012083931"></a><a name="p429240012083931"></a><a href="_credential_info.md#a934bfcff52c779c18e053c90aed21513">extraInfo</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1161007345083931p0"><a name="entry1161007345083931p0"></a><a name="entry1161007345083931p0"></a>其他相关信息，用于支持信息扩展。</p>
</td>
</tr>
</tbody>
</table>

## **详细描述**<a name="section786622901083931"></a>

认证凭据信息。

**自动:**

3.2

**Version：**

1.0

## **类成员变量说明**<a name="section1093075793083931"></a>

## authType<a name="aa5b6abdeb49854d35f9ac99bdfe1988a"></a>

```
enum AuthType CredentialInfo::authType
```

**描述：**

用户认证凭据类型。

## credentialId<a name="aab7d1675c5b2fcbdf2699a414003efe4"></a>

```
unsigned long CredentialInfo::credentialId
```

**描述：**

认证凭据ID。

## executorId<a name="a2215ed43cddeebb9b9a63f9977975ed1"></a>

```
unsigned int CredentialInfo::executorId
```

**描述：**

既定用户认证凭据类型的执行器ID。

## executorType<a name="ac348f4304930dc17957385ecec9d0ad3"></a>

```
unsigned int CredentialInfo::executorType
```

**描述：**

执行器类型。

## extraInfo<a name="a934bfcff52c779c18e053c90aed21513"></a>

```
unsigned char [] CredentialInfo::extraInfo
```

**描述：**

其他相关信息，用于支持信息扩展。

## index<a name="a56d90609a149c7e11968697106a03ea3"></a>

```
unsigned long CredentialInfo::index
```

**描述：**

用户认证框架的执行器索引。

## templateId<a name="a70f556d96c14a56faa8addd29da6c6f9"></a>

```
unsigned long CredentialInfo::templateId
```

**描述：**

认证凭据模版ID。

