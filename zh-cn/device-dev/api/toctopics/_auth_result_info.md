# AuthResultInfo<a name="ZH-CN_TOPIC_0000001290721060"></a>

## **概述**<a name="section1433095883083931"></a>

**所属模块:**

[HdfUserAuth](_hdf_user_auth.md)

## **汇总**<a name="section791226132083931"></a>

## Public 属性<a name="pub-attribs"></a>

<a name="table2008772198083931"></a>
<table><thead align="left"><tr id="row412133687083931"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p666827025083931"><a name="p666827025083931"></a><a name="p666827025083931"></a>Public 属性</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1655008805083931"><a name="p1655008805083931"></a><a name="p1655008805083931"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row167203194083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1776815318083931"><a name="p1776815318083931"></a><a name="p1776815318083931"></a><a href="_auth_result_info.md#a16d3bfa7cb0dd2d5366c76f7e0282843">result</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry571261850083931p0"><a name="entry571261850083931p0"></a><a name="entry571261850083931p0"></a>用户身份认证结果。</p>
</td>
</tr>
<tr id="row195818929083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1203818848083931"><a name="p1203818848083931"></a><a name="p1203818848083931"></a><a href="_auth_result_info.md#aad5ef1be00b2a3605d5c7e15ea80a5af">freezingTime</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p9890122713917"><a name="p9890122713917"></a><a name="p9890122713917"></a>认证方式被冻结的时间。</p>
</td>
</tr>
<tr id="row122173883083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1073752370083931"><a name="p1073752370083931"></a><a name="p1073752370083931"></a><a href="_auth_result_info.md#ae85238c13c3dffc551a858590d8104cc">remainTimes</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1052150911083931p0"><a name="entry1052150911083931p0"></a><a name="entry1052150911083931p0"></a>认证方式距离被冻结的可处理认证请求次数。</p>
</td>
</tr>
<tr id="row2134801186083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p571603485083931"><a name="p571603485083931"></a><a name="p571603485083931"></a><a href="_auth_result_info.md#aafb542b87b3bb85050c240ba94845642">msgs</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1447101335083931p0"><a name="entry1447101335083931p0"></a><a name="entry1447101335083931p0"></a>执行器发送的消息。</p>
</td>
</tr>
<tr id="row2074991184083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p727513556083931"><a name="p727513556083931"></a><a name="p727513556083931"></a><a href="_auth_result_info.md#acb6a5382e17b3462aaa311893b488a4b">token</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1505457236083931p0"><a name="entry1505457236083931p0"></a><a name="entry1505457236083931p0"></a>用户身份认证令牌。</p>
</td>
</tr>
</tbody>
</table>

## **详细描述**<a name="section1811409461083931"></a>

用户身份认证结果信息。

**Since：**

3.2

**Version：**

1.0

## **类成员变量说明**<a name="section1726170864083931"></a>

## freezingTime<a name="aad5ef1be00b2a3605d5c7e15ea80a5af"></a>

```
int AuthResultInfo::freezingTime
```

**描述：**

认证方式被冻结的时间。

## msgs<a name="aafb542b87b3bb85050c240ba94845642"></a>

```
struct ExecutorSendMsg [] AuthResultInfo::msgs
```

**描述：**

执行器发送的消息。

## remainTimes<a name="ae85238c13c3dffc551a858590d8104cc"></a>

```
int AuthResultInfo::remainTimes
```

**描述：**

认证方式距离被冻结的可处理认证请求次数。

## result<a name="a16d3bfa7cb0dd2d5366c76f7e0282843"></a>

```
unsigned int AuthResultInfo::result
```

**描述：**

用户身份认证结果。

## token<a name="acb6a5382e17b3462aaa311893b488a4b"></a>

```
unsigned char [] AuthResultInfo::token
```

**描述：**

用户身份认证令牌。

