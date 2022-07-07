# GrallocFuncs<a name="ZH-CN_TOPIC_0000001290840924"></a>

## **概述**<a name="section481904924083932"></a>

**所属模块:**

[Display](_display.md)

## **汇总**<a name="section160962433083932"></a>

## Public 属性<a name="pub-attribs"></a>

<a name="table1422884737083932"></a>
<table><thead align="left"><tr id="row45614191083932"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p666486137083932"><a name="p666486137083932"></a><a name="p666486137083932"></a>Public 属性</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1149852111083932"><a name="p1149852111083932"></a><a name="p1149852111083932"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row541240503083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p364074532083932"><a name="p364074532083932"></a><a name="p364074532083932"></a>( <a href="_gralloc_funcs.md#ad464e01f90c8289be348a9b164e8d002">AllocMem</a> )(const <a href="_alloc_info.md">AllocInfo</a> *info, BufferHandle **handle)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1611408024083932"><a name="p1611408024083932"></a><a name="p1611408024083932"></a>显示内存分配。 <a href="_gralloc_funcs.md#ad464e01f90c8289be348a9b164e8d002">更多...</a></p>
</td>
</tr>
<tr id="row133722613083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p4695716083932"><a name="p4695716083932"></a><a name="p4695716083932"></a>( <a href="_gralloc_funcs.md#a21b7734697bce45f94dac9b9673e7053">FreeMem</a> )(BufferHandle *handle)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p808435649083932"><a name="p808435649083932"></a><a name="p808435649083932"></a>显示内存释放。 <a href="_gralloc_funcs.md#a21b7734697bce45f94dac9b9673e7053">更多...</a></p>
</td>
</tr>
<tr id="row1484958572083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1811417485083932"><a name="p1811417485083932"></a><a name="p1811417485083932"></a>( <a href="_gralloc_funcs.md#aa72c7646e6a1912974b41d09ce117013">Mmap</a> )(BufferHandle *handle)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p163296420083932"><a name="p163296420083932"></a><a name="p163296420083932"></a>显示内存映射，将内存映射到对应的进程地址空间中。 <a href="_gralloc_funcs.md#aa72c7646e6a1912974b41d09ce117013">更多...</a></p>
</td>
</tr>
<tr id="row774695322083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1954306548083932"><a name="p1954306548083932"></a><a name="p1954306548083932"></a>( <a href="_gralloc_funcs.md#a8a2291b770540589a66fe9d8c0762ef1">MmapYUV</a> )(BufferHandle *handle, YUVDescInfo *info)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p190181101083932"><a name="p190181101083932"></a><a name="p190181101083932"></a>YUV 内存映射。 <a href="_gralloc_funcs.md#a8a2291b770540589a66fe9d8c0762ef1">更多...</a></p>
</td>
</tr>
<tr id="row155177217083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1100011718083932"><a name="p1100011718083932"></a><a name="p1100011718083932"></a>( <a href="_gralloc_funcs.md#aa894fd86ddbe1040b75b12691fce3341">MmapCache</a> )(BufferHandle *handle)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p861817199083932"><a name="p861817199083932"></a><a name="p861817199083932"></a>显示内存映射，将内存映射为 cache 内存到对应的进程地址空间中。 <a href="_gralloc_funcs.md#aa894fd86ddbe1040b75b12691fce3341">更多...</a></p>
</td>
</tr>
<tr id="row616693282083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p425960103083932"><a name="p425960103083932"></a><a name="p425960103083932"></a>( <a href="_gralloc_funcs.md#a2ddb5fa5aaf52e126b632ad53cfe371f">Unmap</a> )(BufferHandle *handle)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p28080018083932"><a name="p28080018083932"></a><a name="p28080018083932"></a>内存反映射，将内存进行反映射。 <a href="_gralloc_funcs.md#a2ddb5fa5aaf52e126b632ad53cfe371f">更多...</a></p>
</td>
</tr>
<tr id="row180217570083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1781444919083932"><a name="p1781444919083932"></a><a name="p1781444919083932"></a>( <a href="_gralloc_funcs.md#aec87b6470d03a6d5065c6098f4bcca8f">FlushCache</a> )(BufferHandle *handle)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2117693539083932"><a name="p2117693539083932"></a><a name="p2117693539083932"></a>刷新cache，刷新cache里的内容到内存并且使cache里的内容无效。 <a href="_gralloc_funcs.md#aec87b6470d03a6d5065c6098f4bcca8f">更多...</a></p>
</td>
</tr>
<tr id="row1524794038083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1682996249083932"><a name="p1682996249083932"></a><a name="p1682996249083932"></a>( <a href="_gralloc_funcs.md#a476f649466ed60e04e8450d65795cfa9">FlushMCache</a> )(BufferHandle *handle)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p7490735083932"><a name="p7490735083932"></a><a name="p7490735083932"></a>刷新Mmap映射的cache，刷新Mmap映射的cache里的内容到内存并且使cache里的内容无效。 <a href="_gralloc_funcs.md#a476f649466ed60e04e8450d65795cfa9">更多...</a></p>
</td>
</tr>
<tr id="row961229086083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2025136297083932"><a name="p2025136297083932"></a><a name="p2025136297083932"></a>( <a href="_gralloc_funcs.md#adb81671e3fcf5f9d09e159bc0cb4a8b5">InvalidateCache</a> )(BufferHandle *handle)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p294295699083932"><a name="p294295699083932"></a><a name="p294295699083932"></a>使cache中的内容无效用以存储更新内存内容。 <a href="_gralloc_funcs.md#adb81671e3fcf5f9d09e159bc0cb4a8b5">更多...</a></p>
</td>
</tr>
<tr id="row687963188083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1965543947083932"><a name="p1965543947083932"></a><a name="p1965543947083932"></a>( <a href="_gralloc_funcs.md#a104b340552ca7e60edda3725b0b61040">IsSupportedAlloc</a> )(uint32_t num, const <a href="_verify_alloc_info.md">VerifyAllocInfo</a> *infos, bool *supporteds)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1255865432083932"><a name="p1255865432083932"></a><a name="p1255865432083932"></a>检测给定的VerifyAllocInfo数组信息能否申请内存成功。 <a href="_gralloc_funcs.md#a104b340552ca7e60edda3725b0b61040">更多...</a></p>
</td>
</tr>
</tbody>
</table>

## **详细描述**<a name="section2102685812083932"></a>

显示内存驱动接口结构体，定义显示内存驱动接口函数指针。

## **类成员变量说明**<a name="section721191420083932"></a>

## AllocMem<a name="ad464e01f90c8289be348a9b164e8d002"></a>

```
int32_t(* GrallocFuncs::AllocMem) (const AllocInfo *info, BufferHandle **handle)
```

**描述：**

显示内存分配。

根据GUI图形系统传递的参数分配内存，分配的内存根据类型可分为共享内存、cache内存和非cache内存等。

**参数：**

<a name="table87698718083932"></a>
<table><thead align="left"><tr id="row1722739895083932"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p295208259083932"><a name="p295208259083932"></a><a name="p295208259083932"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1469840484083932"><a name="p1469840484083932"></a><a name="p1469840484083932"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row1192261331083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1340136073083932p0"><a name="entry1340136073083932p0"></a><a name="entry1340136073083932p0"></a>info</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry572831451083932p0"><a name="entry572831451083932p0"></a><a name="entry572831451083932p0"></a>输入参数，指示申请内存AllocInfo信息.</p>
</td>
</tr>
<tr id="row800800881083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry387243559083932p0"><a name="entry387243559083932p0"></a><a name="entry387243559083932p0"></a>handle</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1103321896083932p0"><a name="entry1103321896083932p0"></a><a name="entry1103321896083932p0"></a>输入参数，指向申请的内存handle指针。</p>
</td>
</tr>
</tbody>
</table>

**返回：**

DISPLAY\_SUCCESS 表示执行成功。

其他值表示执行失败，具体错误码查看[DispErrCode](_display.md#ga12a925dadef7573cd74d63d06824f9b0)。

## FlushCache<a name="aec87b6470d03a6d5065c6098f4bcca8f"></a>

```
int32_t(* GrallocFuncs::FlushCache) (BufferHandle *handle)
```

**描述：**

刷新cache，刷新cache里的内容到内存并且使cache里的内容无效。

**参数：**

<a name="table1040992079083932"></a>
<table><thead align="left"><tr id="row299933855083932"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1582066299083932"><a name="p1582066299083932"></a><a name="p1582066299083932"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1101814382083932"><a name="p1101814382083932"></a><a name="p1101814382083932"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row1834242721083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1309153871083932p0"><a name="entry1309153871083932p0"></a><a name="entry1309153871083932p0"></a>handle</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1281464728083932p0"><a name="entry1281464728083932p0"></a><a name="entry1281464728083932p0"></a>输出参数，待刷新cache的handle指针。</p>
</td>
</tr>
</tbody>
</table>

**返回：**

DISPLAY\_SUCCESS 表示执行成功。

其他值表示执行失败，具体错误码查看[DispErrCode](_display.md#ga12a925dadef7573cd74d63d06824f9b0)。

## FlushMCache<a name="a476f649466ed60e04e8450d65795cfa9"></a>

```
int32_t(* GrallocFuncs::FlushMCache) (BufferHandle *handle)
```

**描述：**

刷新Mmap映射的cache，刷新Mmap映射的cache里的内容到内存并且使cache里的内容无效。

**参数：**

<a name="table696283175083932"></a>
<table><thead align="left"><tr id="row143536068083932"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1793290789083932"><a name="p1793290789083932"></a><a name="p1793290789083932"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1705642752083932"><a name="p1705642752083932"></a><a name="p1705642752083932"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row579727284083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry399119086083932p0"><a name="entry399119086083932p0"></a><a name="entry399119086083932p0"></a>handle</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1710354475083932p0"><a name="entry1710354475083932p0"></a><a name="entry1710354475083932p0"></a>输出参数，待刷新cache的handle指针。</p>
</td>
</tr>
</tbody>
</table>

**返回：**

DISPLAY\_SUCCESS 表示执行成功。

其他值表示执行失败，具体错误码查看[DispErrCode](_display.md#ga12a925dadef7573cd74d63d06824f9b0)。

## FreeMem<a name="a21b7734697bce45f94dac9b9673e7053"></a>

```
void(* GrallocFuncs::FreeMem) (BufferHandle *handle)
```

**描述：**

显示内存释放。

**参数：**

<a name="table629633933083932"></a>
<table><thead align="left"><tr id="row1662848930083932"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1436380555083932"><a name="p1436380555083932"></a><a name="p1436380555083932"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p2068881394083932"><a name="p2068881394083932"></a><a name="p2068881394083932"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row364055729083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1784921850083932p0"><a name="entry1784921850083932p0"></a><a name="entry1784921850083932p0"></a>handle</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry344428114083932p0"><a name="entry344428114083932p0"></a><a name="entry344428114083932p0"></a>输入参数，待释放的内存handle指针。</p>
</td>
</tr>
</tbody>
</table>

**返回：**

成功返回有效地址，失败返回NULL。

## InvalidateCache<a name="adb81671e3fcf5f9d09e159bc0cb4a8b5"></a>

```
int32_t(* GrallocFuncs::InvalidateCache) (BufferHandle *handle)
```

**描述：**

使cache中的内容无效用以存储更新内存内容。

**参数：**

<a name="table1105494962083932"></a>
<table><thead align="left"><tr id="row932446405083932"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1981666807083932"><a name="p1981666807083932"></a><a name="p1981666807083932"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1798687018083932"><a name="p1798687018083932"></a><a name="p1798687018083932"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row1234801048083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry203451672083932p0"><a name="entry203451672083932p0"></a><a name="entry203451672083932p0"></a>handle</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry2020453321083932p0"><a name="entry2020453321083932p0"></a><a name="entry2020453321083932p0"></a>输出参数，待无效cache的handle指针。</p>
</td>
</tr>
</tbody>
</table>

**返回：**

DISPLAY\_SUCCESS 表示执行成功。

其他值表示执行失败，具体错误码查看[DispErrCode](_display.md#ga12a925dadef7573cd74d63d06824f9b0)。

## IsSupportedAlloc<a name="a104b340552ca7e60edda3725b0b61040"></a>

```
int32_t(* GrallocFuncs::IsSupportedAlloc) (uint32_t num, const VerifyAllocInfo *infos, bool *supporteds)
```

**描述：**

检测给定的VerifyAllocInfo数组信息能否申请内存成功。

**参数：**

<a name="table432729366083932"></a>
<table><thead align="left"><tr id="row2077295084083932"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1440201815083932"><a name="p1440201815083932"></a><a name="p1440201815083932"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p6208660083932"><a name="p6208660083932"></a><a name="p6208660083932"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row1984169443083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry51101091083932p0"><a name="entry51101091083932p0"></a><a name="entry51101091083932p0"></a>num</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry966649424083932p0"><a name="entry966649424083932p0"></a><a name="entry966649424083932p0"></a>输入参数，VerifyAllocInfo数组个数。</p>
</td>
</tr>
<tr id="row832096639083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1468204938083932p0"><a name="entry1468204938083932p0"></a><a name="entry1468204938083932p0"></a>infos</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1787639697083932p0"><a name="entry1787639697083932p0"></a><a name="entry1787639697083932p0"></a>输出参数，VerifyAllocInfo数组首地址。</p>
</td>
</tr>
<tr id="row1389966326083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry89539909083932p0"><a name="entry89539909083932p0"></a><a name="entry89539909083932p0"></a>supporteds</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1440386603083932p0"><a name="entry1440386603083932p0"></a><a name="entry1440386603083932p0"></a>输出参数，supporteds数组首地址, 表示能否申请成功。</p>
</td>
</tr>
</tbody>
</table>

**返回：**

DISPLAY\_SUCCESS 表示执行成功。

其他值表示执行失败，具体错误码查看[DispErrCode](_display.md#ga12a925dadef7573cd74d63d06824f9b0)。

## Mmap<a name="aa72c7646e6a1912974b41d09ce117013"></a>

```
void*(* GrallocFuncs::Mmap) (BufferHandle *handle)
```

**描述：**

显示内存映射，将内存映射到对应的进程地址空间中。

**参数：**

<a name="table288434781083932"></a>
<table><thead align="left"><tr id="row1184699342083932"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1833985404083932"><a name="p1833985404083932"></a><a name="p1833985404083932"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1447189630083932"><a name="p1447189630083932"></a><a name="p1447189630083932"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row2097448080083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry962692834083932p0"><a name="entry962692834083932p0"></a><a name="entry962692834083932p0"></a>handle</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1608550259083932p0"><a name="entry1608550259083932p0"></a><a name="entry1608550259083932p0"></a>输入参数，待映射内存handle指针。</p>
</td>
</tr>
</tbody>
</table>

**返回：**

成功返回有效地址，失败返回NULL。

## MmapCache<a name="aa894fd86ddbe1040b75b12691fce3341"></a>

```
void*(* GrallocFuncs::MmapCache) (BufferHandle *handle)
```

**描述：**

显示内存映射，将内存映射为 cache 内存到对应的进程地址空间中。

**参数：**

<a name="table1856527607083932"></a>
<table><thead align="left"><tr id="row1195018433083932"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p729128100083932"><a name="p729128100083932"></a><a name="p729128100083932"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1823291823083932"><a name="p1823291823083932"></a><a name="p1823291823083932"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row124266417083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry42796722083932p0"><a name="entry42796722083932p0"></a><a name="entry42796722083932p0"></a>handle</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry911241940083932p0"><a name="entry911241940083932p0"></a><a name="entry911241940083932p0"></a>输出参数，待映射内存 handle 指针。</p>
</td>
</tr>
</tbody>
</table>

**返回：**

成功返回有效地址，失败返回 NULL。

## MmapYUV<a name="a8a2291b770540589a66fe9d8c0762ef1"></a>

```
void*(* GrallocFuncs::MmapYUV) (BufferHandle *handle, YUVDescInfo *info)
```

**描述：**

YUV 内存映射。

**参数：**

<a name="table1949310981083932"></a>
<table><thead align="left"><tr id="row1938657894083932"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1281146386083932"><a name="p1281146386083932"></a><a name="p1281146386083932"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1688982764083932"><a name="p1688982764083932"></a><a name="p1688982764083932"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row1594557702083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1706927807083932p0"><a name="entry1706927807083932p0"></a><a name="entry1706927807083932p0"></a>handle</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1307878132083932p0"><a name="entry1307878132083932p0"></a><a name="entry1307878132083932p0"></a>输出参数，指示内存映射的输出缓存。</p>
</td>
</tr>
<tr id="row1112568530083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1839233403083932p0"><a name="entry1839233403083932p0"></a><a name="entry1839233403083932p0"></a>info</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1256180608083932p0"><a name="entry1256180608083932p0"></a><a name="entry1256180608083932p0"></a>输出参数，指示内存映射的YUVDescInfo信息。</p>
</td>
</tr>
</tbody>
</table>

**返回：**

成功返回有效地址，失败返回 NULL。

## Unmap<a name="a2ddb5fa5aaf52e126b632ad53cfe371f"></a>

```
int32_t(* GrallocFuncs::Unmap) (BufferHandle *handle)
```

**描述：**

内存反映射，将内存进行反映射。

**参数：**

<a name="table1396555674083932"></a>
<table><thead align="left"><tr id="row1499217962083932"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1205275774083932"><a name="p1205275774083932"></a><a name="p1205275774083932"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p555810268083932"><a name="p555810268083932"></a><a name="p555810268083932"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row1466942505083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="entry1904676101083932p0"><a name="entry1904676101083932p0"></a><a name="entry1904676101083932p0"></a>handle</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1655136553083932p0"><a name="entry1655136553083932p0"></a><a name="entry1655136553083932p0"></a>输出参数，待反映射内存handle指针。</p>
</td>
</tr>
</tbody>
</table>

**返回：**

DISPLAY\_SUCCESS 表示执行成功。

其他值表示执行失败，具体错误码查看[DispErrCode](_display.md#ga12a925dadef7573cd74d63d06824f9b0)。

