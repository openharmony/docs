# EventPackage<a name="ZH-CN_TOPIC_0000001291040572"></a>

## **概述**<a name="section1650199742083932"></a>

**所属模块:**

[Input](_input.md)

## **汇总**<a name="section739273342083932"></a>

## Public 属性<a name="pub-attribs"></a>

<a name="table806007342083932"></a>
<table><thead align="left"><tr id="row808574995083932"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p765714874083932"><a name="p765714874083932"></a><a name="p765714874083932"></a>Public 属性</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p185478516083932"><a name="p185478516083932"></a><a name="p185478516083932"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row1956237387083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p581204524083932"><a name="p581204524083932"></a><a name="p581204524083932"></a><a href="_event_package.md#ab525a4b18a5600226c650981ae9aa09f">type</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1815442495083932p0"><a name="entry1815442495083932p0"></a><a name="entry1815442495083932p0"></a>输入事件的属性</p>
</td>
</tr>
<tr id="row1832978063083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1528946490083932"><a name="p1528946490083932"></a><a name="p1528946490083932"></a><a href="_event_package.md#a90645cf873e7e3f40b9510d37fbd3809">code</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1242667260083932p0"><a name="entry1242667260083932p0"></a><a name="entry1242667260083932p0"></a>输入事件的特定编码项</p>
</td>
</tr>
<tr id="row530339467083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2049631447083932"><a name="p2049631447083932"></a><a name="p2049631447083932"></a><a href="_event_package.md#a5bd163e436b5bba741cc4fbb7535307e">value</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1338221300083932p0"><a name="entry1338221300083932p0"></a><a name="entry1338221300083932p0"></a>输入事件编码项对应的值</p>
</td>
</tr>
<tr id="row1650649991083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p913021691083932"><a name="p913021691083932"></a><a name="p913021691083932"></a><a href="_event_package.md#a541702f4539b6aa3b7f9f7b46520fa07">timestamp</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1833301717083932p0"><a name="entry1833301717083932p0"></a><a name="entry1833301717083932p0"></a>输入事件对应的时间戳</p>
</td>
</tr>
</tbody>
</table>

## **详细描述**<a name="section1886340574083932"></a>

input事件数据包结构。

## **类成员变量说明**<a name="section187058527083932"></a>

## code<a name="a90645cf873e7e3f40b9510d37fbd3809"></a>

```
uint32_t EventPackage::code
```

**描述：**

输入事件的特定编码项

## timestamp<a name="a541702f4539b6aa3b7f9f7b46520fa07"></a>

```
uint64_t EventPackage::timestamp
```

**描述：**

输入事件对应的时间戳

## type<a name="ab525a4b18a5600226c650981ae9aa09f"></a>

```
uint32_t EventPackage::type
```

**描述：**

输入事件的属性

## value<a name="a5bd163e436b5bba741cc4fbb7535307e"></a>

```
int32_t EventPackage::value
```

**描述：**

输入事件编码项对应的值

