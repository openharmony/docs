# LightFlashEffect<a name="ZH-CN_TOPIC_0000001291040600"></a>

## **概述**<a name="section1955957378083932"></a>

**所属模块:**

[Light](_light.md)

## **汇总**<a name="section1817743917083932"></a>

## Public 属性<a name="pub-attribs"></a>

<a name="table1081821512083932"></a>
<table><thead align="left"><tr id="row529886619083932"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p432570527083932"><a name="p432570527083932"></a><a name="p432570527083932"></a>Public 属性</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p900891196083932"><a name="p900891196083932"></a><a name="p900891196083932"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row918477357083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1726871398083932"><a name="p1726871398083932"></a><a name="p1726871398083932"></a><a href="_light_flash_effect.md#ab826532d7023cd30fe55a88047872668">flashMode</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry542189037083932p0"><a name="entry542189037083932p0"></a><a name="entry542189037083932p0"></a>闪烁模式。</p>
</td>
</tr>
<tr id="row688828486083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p400818480083932"><a name="p400818480083932"></a><a name="p400818480083932"></a><a href="_light_flash_effect.md#a3e40dd2a9ce6d6a743b8909cc07e13cb">onTime</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry738143371083932p0"><a name="entry738143371083932p0"></a><a name="entry738143371083932p0"></a>表示灯在闪烁期间点亮时持续的时间（毫秒）。</p>
</td>
</tr>
<tr id="row480597317083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1089585852083932"><a name="p1089585852083932"></a><a name="p1089585852083932"></a><a href="_light_flash_effect.md#aa443ef8750d8fbe86bb84cd76f6dd428">offTime</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry237931153083932p0"><a name="entry237931153083932p0"></a><a name="entry237931153083932p0"></a>表示灯在闪烁期间熄灭时持续的时间（毫秒）。</p>
</td>
</tr>
</tbody>
</table>

## **详细描述**<a name="section625734993083932"></a>

定义闪烁参数。

这些参数包括闪烁模式以及闪烁期间指示灯的打开和关闭时间。

**Since：**

3.1

## **类成员变量说明**<a name="section503084669083932"></a>

## flashMode<a name="ab826532d7023cd30fe55a88047872668"></a>

```
int32_t LightFlashEffect::flashMode
```

**描述：**

闪烁模式，详见[LightFlashMode](_light.md#gaacf9823c64514a279833614add26ab5d)。

## offTime<a name="aa443ef8750d8fbe86bb84cd76f6dd428"></a>

```
int32_t LightFlashEffect::offTime
```

**描述：**

表示灯在闪烁期间熄灭时持续的时间（毫秒）。

## onTime<a name="a3e40dd2a9ce6d6a743b8909cc07e13cb"></a>

```
int32_t LightFlashEffect::onTime
```

**描述：**

表示灯在闪烁期间点亮时持续的时间（毫秒）。

