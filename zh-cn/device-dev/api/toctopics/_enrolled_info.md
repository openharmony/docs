# EnrolledInfo<a name="ZH-CN_TOPIC_0000001290721068"></a>

## **概述**<a name="section1755661138083931"></a>

**所属模块:**

[HdfUserAuth](_hdf_user_auth.md)

## **汇总**<a name="section471752535083931"></a>

## Public 属性<a name="pub-attribs"></a>

<a name="table946910417083931"></a>
<table><thead align="left"><tr id="row1755720511083931"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p577363493083931"><a name="p577363493083931"></a><a name="p577363493083931"></a>Public 属性</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1564808932083931"><a name="p1564808932083931"></a><a name="p1564808932083931"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row1504255780083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p372863826083931"><a name="p372863826083931"></a><a name="p372863826083931"></a><a href="_enrolled_info.md#a19611e9adecbca1944e73c931798de97">enrolledId</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry755786820083931p0"><a name="entry755786820083931p0"></a><a name="entry755786820083931p0"></a>注册ID，用户注册新的认证凭据时会更新注册ID。</p>
</td>
</tr>
<tr id="row1886527828083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1790439094083931"><a name="p1790439094083931"></a><a name="p1790439094083931"></a><a href="_enrolled_info.md#aa9413c348b59c5004a3d5d60ec0e4ac7">authType</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1381456003083931p0"><a name="entry1381456003083931p0"></a><a name="entry1381456003083931p0"></a>用户认证凭据类型。</p>
</td>
</tr>
</tbody>
</table>

## **详细描述**<a name="section1079378640083931"></a>

注册信息。

**Since：**

3.2

**Version：**

1.0

## **类成员变量说明**<a name="section465351968083931"></a>

## authType<a name="aa9413c348b59c5004a3d5d60ec0e4ac7"></a>

```
enum AuthType EnrolledInfo::authType
```

**描述：**

用户认证凭据类型AuthType\}。

## enrolledId<a name="a19611e9adecbca1944e73c931798de97"></a>

```
unsigned long EnrolledInfo::enrolledId
```

**描述：**

注册ID，用户注册新的认证凭据时会更新注册ID。

