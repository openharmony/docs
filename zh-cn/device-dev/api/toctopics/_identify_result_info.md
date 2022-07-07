# IdentifyResultInfo<a name="ZH-CN_TOPIC_0000001343120337"></a>

## **概述**<a name="section562373673083932"></a>

**所属模块:**

[HdfUserAuth](_hdf_user_auth.md)

## **汇总**<a name="section1320732199083932"></a>

## Public 属性<a name="pub-attribs"></a>

<a name="table1791915667083932"></a>
<table><thead align="left"><tr id="row90895334083932"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1034534348083932"><a name="p1034534348083932"></a><a name="p1034534348083932"></a>Public 属性</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p774782210083932"><a name="p774782210083932"></a><a name="p774782210083932"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row901366770083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2034024170083932"><a name="p2034024170083932"></a><a name="p2034024170083932"></a><a href="_identify_result_info.md#a4f68bd9d0d72324c7eca1595a1c1b353">result</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry167553202083932p0"><a name="entry167553202083932p0"></a><a name="entry167553202083932p0"></a>用户身份识别结果。</p>
</td>
</tr>
<tr id="row363568265083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p30837179083932"><a name="p30837179083932"></a><a name="p30837179083932"></a><a href="_identify_result_info.md#af4a1f427f3364d4117b028160dcb6644">userId</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1418142832614"><a name="p1418142832614"></a><a name="p1418142832614"></a>用户ID。</p>
</td>
</tr>
<tr id="row154291547083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1954417774083932"><a name="p1954417774083932"></a><a name="p1954417774083932"></a><a href="_identify_result_info.md#aed6f349d6d0d9a34083ac18304a07eee">token</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1834996652083932p0"><a name="entry1834996652083932p0"></a><a name="entry1834996652083932p0"></a>用户身份识别令牌。</p>
</td>
</tr>
</tbody>
</table>

## **详细描述**<a name="section594672189083932"></a>

用户身份识别结果信息。

**Since：**

3.2

**Version:**

1.0

## **类成员变量说明**<a name="section285367804083932"></a>

## result<a name="a4f68bd9d0d72324c7eca1595a1c1b353"></a>

```
int IdentifyResultInfo::result
```

**描述：**

用户身份识别结果。

## token<a name="aed6f349d6d0d9a34083ac18304a07eee"></a>

```
unsigned char [] IdentifyResultInfo::token
```

**描述：**

用户身份识别令牌。

## userId<a name="af4a1f427f3364d4117b028160dcb6644"></a>

```
int IdentifyResultInfo::userId
```

**描述：**

用户ID。

