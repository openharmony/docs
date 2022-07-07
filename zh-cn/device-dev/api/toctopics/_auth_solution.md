# AuthSolution<a name="ZH-CN_TOPIC_0000001290561160"></a>

## **概述**<a name="section1143203525083931"></a>

**所属模块:**

[HdfUserAuth](_hdf_user_auth.md)

## **汇总**<a name="section451681852083931"></a>

## Public 属性<a name="pub-attribs"></a>

<a name="table191543464083931"></a>
<table><thead align="left"><tr id="row244532472083931"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p516265015083931"><a name="p516265015083931"></a><a name="p516265015083931"></a>Public 属性</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p21537312083931"><a name="p21537312083931"></a><a name="p21537312083931"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row648915776083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p649784361083931"><a name="p649784361083931"></a><a name="p649784361083931"></a><a href="_auth_solution.md#ab2e6776d691a894eda136298049a2713">userId</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry2108125126083931p0"><a name="entry2108125126083931p0"></a><a name="entry2108125126083931p0"></a>用户ID。</p>
</td>
</tr>
<tr id="row210575359083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p623506869083931"><a name="p623506869083931"></a><a name="p623506869083931"></a><a href="_auth_solution.md#aa84eea17c9feed3feee7b4a3c57b2fb9">authTrustLevel</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1599296404083931p0"><a name="entry1599296404083931p0"></a><a name="entry1599296404083931p0"></a>认证结果可信等级。</p>
</td>
</tr>
<tr id="row893223318083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1706077978083931"><a name="p1706077978083931"></a><a name="p1706077978083931"></a><a href="_auth_solution.md#a4a13ff7a177537d8bf5ff6442250c370">authType</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry628981084083931p0"><a name="entry628981084083931p0"></a><a name="entry628981084083931p0"></a>用户认证凭据类型AuthType}。</p>
</td>
</tr>
<tr id="row1171644054083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1551960356083931"><a name="p1551960356083931"></a><a name="p1551960356083931"></a><a href="_auth_solution.md#afd3a081eed70f22a23056f801efd9ecb">executorId</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1715553153083931p0"><a name="entry1715553153083931p0"></a><a name="entry1715553153083931p0"></a>既定用户认证凭据类型的执行器ID。</p>
</td>
</tr>
<tr id="row845004356083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p197383787083931"><a name="p197383787083931"></a><a name="p197383787083931"></a><a href="_auth_solution.md#a1c45838ebacd1befbc355ff678311104">challenge</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry2093753060083931p0"><a name="entry2093753060083931p0"></a><a name="entry2093753060083931p0"></a>挑战值，用于签发认证令牌。</p>
</td>
</tr>
</tbody>
</table>

## **详细描述**<a name="section230303189083931"></a>

认证方案。

**Since：**

3.2

**Version：**

1.0

## **类成员变量说明**<a name="section1202041817083931"></a>

## authTrustLevel<a name="aa84eea17c9feed3feee7b4a3c57b2fb9"></a>

```
unsigned int AuthSolution::authTrustLevel
```

**描述：**

认证结果可信等级。

## authType<a name="a4a13ff7a177537d8bf5ff6442250c370"></a>

```
enum AuthType AuthSolution::authType
```

**描述：**

用户认证凭据类型AuthType\}。

## challenge<a name="a1c45838ebacd1befbc355ff678311104"></a>

```
unsigned char [] AuthSolution::challenge
```

**描述：**

挑战值，用于签发认证令牌。

## executorId<a name="afd3a081eed70f22a23056f801efd9ecb"></a>

```
unsigned int AuthSolution::executorId
```

**描述：**

既定用户认证凭据类型的执行器ID。

## userId<a name="ab2e6776d691a894eda136298049a2713"></a>

```
int AuthSolution::userId
```

**描述：**

用户ID。

