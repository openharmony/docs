# CompVerInfo<a name="ZH-CN_TOPIC_0000001290721064"></a>

## **概述**<a name="section1595103712083931"></a>

**所属模块:**

[Codec](_codec.md)

## **汇总**<a name="section1719897946083931"></a>

## Public 属性<a name="pub-attribs"></a>

<a name="table937566150083931"></a>
<table><thead align="left"><tr id="row192942557083931"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p207959429083931"><a name="p207959429083931"></a><a name="p207959429083931"></a>Public 属性</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1487591791083931"><a name="p1487591791083931"></a><a name="p1487591791083931"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row1506480123083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p437823756083931"><a name="p437823756083931"></a><a name="p437823756083931"></a><a href="_comp_ver_info.md#abdf39a273d75ccc61aec9c5a1d9e238b">compName</a> [<a href="_codec.md#gaf71324c57f05ff9e24bd384925dd6b17">NAME_LENGTH</a>]</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry107806604083931p0"><a name="entry107806604083931p0"></a><a name="entry107806604083931p0"></a>组件名称</p>
</td>
</tr>
<tr id="row2012552949083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1843485403083931"><a name="p1843485403083931"></a><a name="p1843485403083931"></a><a href="_comp_ver_info.md#a38b30a75560e2486415a76eaa6a54282">compUUID</a> [<a href="_codec.md#ga9226162b034cc837cd977f0fcf611c2c">UUID_LENGTH</a>]</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry874474224083931p0"><a name="entry874474224083931p0"></a><a name="entry874474224083931p0"></a>组件的UUID标识符</p>
</td>
</tr>
<tr id="row1055702381083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1642364471083931"><a name="p1642364471083931"></a><a name="p1642364471083931"></a><a href="_comp_ver_info.md#a897eefef94c1712dc02efd491ac82b1f">compVersion</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry496036987083931p0"><a name="entry496036987083931p0"></a><a name="entry496036987083931p0"></a>OMX组件版本信息</p>
</td>
</tr>
<tr id="row1606892600083931"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1654467233083931"><a name="p1654467233083931"></a><a name="p1654467233083931"></a><a href="_comp_ver_info.md#a052419e45fa3043259fe32dd5e5948ff">specVersion</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1368101756083931p0"><a name="entry1368101756083931p0"></a><a name="entry1368101756083931p0"></a>构建组件所依据的规范的版本信息</p>
</td>
</tr>
</tbody>
</table>

## **Details**<a name="section1514693582083931"></a>

## **详细描述**<a name="section781493380083931"></a>

## **类成员变量说明**<a name="section908877702083931"></a>

## compName<a name="abdf39a273d75ccc61aec9c5a1d9e238b"></a>

```
char CompVerInfo::compName[NAME_LENGTH]
```

**描述：**

组件名称

## compUUID<a name="a38b30a75560e2486415a76eaa6a54282"></a>

```
uint8_t CompVerInfo::compUUID[UUID_LENGTH]
```

**描述：**

组件的UUID标识符

## compVersion<a name="a897eefef94c1712dc02efd491ac82b1f"></a>

```
union OMX_VERSIONTYPE CompVerInfo::compVersion
```

**描述：**

OMX组件版本信息

## specVersion<a name="a052419e45fa3043259fe32dd5e5948ff"></a>

```
union OMX_VERSIONTYPE CompVerInfo::specVersion
```

**描述：**

构建组件所依据的规范的版本信息

