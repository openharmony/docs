# TemplateInfo<a name="ZH-CN_TOPIC_0000001343000901"></a>

## **概述**<a name="section345436867083932"></a>

**所属模块:**

[HdfFaceAuth](_hdf_face_auth.md)  |  [HdfPinAuth](_hdf_pin_auth.md)

## **汇总**<a name="section1377347419083932"></a>

## Public 属性<a name="pub-attribs"></a>

<a name="table2123316035083932"></a>
<table><thead align="left"><tr id="row212390871083932"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1254984687083932"><a name="p1254984687083932"></a><a name="p1254984687083932"></a>Public 属性</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1195340879083932"><a name="p1195340879083932"></a><a name="p1195340879083932"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row1230169192083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1286355366083932"><a name="p1286355366083932"></a><a name="p1286355366083932"></a><a href="_template_info.md#a8c5417586b5711484c8bc927b3b538ec">executorType</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1176154165083932p0"><a name="entry1176154165083932p0"></a><a name="entry1176154165083932p0"></a>执行器类型，根据执行器支持的算法类型进行分类。</p>
</td>
</tr>
<tr id="row1809236057083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1266795129083932"><a name="p1266795129083932"></a><a name="p1266795129083932"></a><a href="_template_info.md#a1c59555bb26a93b85d23cdd3db4ff8eb">freezingTime</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1289637561083932p0"><a name="entry1289637561083932p0"></a><a name="entry1289637561083932p0"></a>认证方式被冻结的时间。</p>
</td>
</tr>
<tr id="row160026449083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p438937869083932"><a name="p438937869083932"></a><a name="p438937869083932"></a><a href="_template_info.md#ade61db27150f086659727667c93173ed">remainTimes</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1663735605083932p0"><a name="entry1663735605083932p0"></a><a name="entry1663735605083932p0"></a>认证方式距离被冻结的可处理认证请求次数。</p>
</td>
</tr>
<tr id="row882650012083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1456356285083932"><a name="p1456356285083932"></a><a name="p1456356285083932"></a><a href="_template_info.md#a8798c0e9ecedccf29cfc5e79fe32c337">extraInfo</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry413323377083932p0"><a name="entry413323377083932p0"></a><a name="entry413323377083932p0"></a>其他相关信息，用于支持信息扩展。</p>
</td>
</tr>
</tbody>
</table>

## **详细描述**<a name="section1139527980083932"></a>

凭据模版信息。

**Since：**

3.2

**Version：**

1.0

## **类成员变量说明**<a name="section851281607083932"></a>

## executorType<a name="a8c5417586b5711484c8bc927b3b538ec"></a>

```
unsigned int TemplateInfo::executorType
```

**描述：**

执行器类型，根据执行器支持的算法类型进行分类。

## extraInfo<a name="a8798c0e9ecedccf29cfc5e79fe32c337"></a>

```
unsigned char [] TemplateInfo::extraInfo
```

**描述：**

其他相关信息，用于支持信息扩展。

## freezingTime<a name="a1c59555bb26a93b85d23cdd3db4ff8eb"></a>

```
int TemplateInfo::freezingTime
```

**描述：**

认证方式被冻结的时间。

## remainTimes<a name="ade61db27150f086659727667c93173ed"></a>

```
int TemplateInfo::remainTimes
```

**描述：**

认证方式距离被冻结的可处理认证请求次数。

