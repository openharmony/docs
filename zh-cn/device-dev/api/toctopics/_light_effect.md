# LightEffect<a name="ZH-CN_TOPIC_0000001343321037"></a>

## **概述**<a name="section1147972513083932"></a>

**所属模块:**

[Light](_light.md)

## **汇总**<a name="section313404902083932"></a>

## Public 属性<a name="pub-attribs"></a>

<a name="table61387272083932"></a>
<table><thead align="left"><tr id="row1244601602083932"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p2118606758083932"><a name="p2118606758083932"></a><a name="p2118606758083932"></a>Public 属性</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p908157595083932"><a name="p908157595083932"></a><a name="p908157595083932"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row1846593007083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1547968504083932"><a name="p1547968504083932"></a><a name="p1547968504083932"></a><a href="_light_effect.md#ad05572f8b8fa7f9d38d7850e17a544b6">lightBrightness</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry1937577923083932p0"><a name="entry1937577923083932p0"></a><a name="entry1937577923083932p0"></a>亮度值。</p>
</td>
</tr>
<tr id="row263875979083932"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1528935367083932"><a name="p1528935367083932"></a><a name="p1528935367083932"></a><a href="_light_effect.md#a7b873884cefd200f86ac8fad1113d42d">flashEffect</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="entry838770974083932p0"><a name="entry838770974083932p0"></a><a name="entry838770974083932p0"></a>闪烁模式。</p>
</td>
</tr>
</tbody>
</table>

## **详细描述**<a name="section1932455450083932"></a>

定义灯的效果参数。

参数包括亮度和闪烁模式。

**Since：**

3.1

## **类成员变量说明**<a name="section2023114594083932"></a>

## flashEffect<a name="a7b873884cefd200f86ac8fad1113d42d"></a>

```
struct LightFlashEffect LightEffect::flashEffect
```

**描述：**

闪烁模式。详见[LightFlashEffect](_light_flash_effect.md)。

## lightBrightness<a name="ad05572f8b8fa7f9d38d7850e17a544b6"></a>

```
int32_t LightEffect::lightBrightness
```

**描述：**

亮度值：Bits 24–31为扩展位，Bits 16–23为红色，bits 8–15为绿色，bits 0–7为蓝色。 如果字节段不等于0，指示打开相应颜色的灯。

