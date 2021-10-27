# 入门介绍<a name="ZH-CN_TOPIC_0000001166764513"></a>

-   [快速入门流程](#section7825218111517)
-   [开发板简介](#zh-cn_topic_0000001053666242_section047719215429)
-   [开发板规格](#zh-cn_topic_0000001053666242_section15192203316533)

开发者可通过本文快速掌握OpenHarmony标准系统的环境搭建、编译、烧录、启动等操作。标准系统可以使用Windows环境进行开发、烧录，使用Linux环境进行编译。

本文将以当前推荐的Hi3516DV300开发板为例对上述操作进行说明。

## 快速入门流程<a name="section7825218111517"></a>

标准系统快速入门流程如下图所示，其中“搭建Ubuntu环境及编译”环节可根据实际情况选择docker方式或工具包方式其中一种即可。

**图 1**  标准环境快速入门流程<a name="fig19162195553211"></a>  
![](figures/标准环境快速入门流程.png "标准环境快速入门流程")

## 开发板简介<a name="zh-cn_topic_0000001053666242_section047719215429"></a>

Hi3516DV300作为新一代行业专用Smart HD IP摄像机SOC，集成新一代ISP\(Image Signal Processor\)、H.265视频压缩编码器，同时集成高性能NNIE引擎，使得Hi3516DV300在低码率、高画质、智能处理和分析、低功耗等方面引领行业水平。

**图 2**  Hi3516单板正面外观图<a name="fig202901538183412"></a>  
![](figures/Hi3516单板正面外观图-0.png "Hi3516单板正面外观图-0")

## 开发板规格<a name="zh-cn_topic_0000001053666242_section15192203316533"></a>

**表 1**  Hi3516开发板规格清单

<a name="zh-cn_topic_0000001053666242_table31714894311"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001053666242_row10171198194310"><th class="cellrowborder" valign="top" width="14.77%" id="mcps1.2.3.1.1"><p id="zh-cn_topic_0000001053666242_a2b235e9ed55f4338886788f140e648a0"><a name="zh-cn_topic_0000001053666242_a2b235e9ed55f4338886788f140e648a0"></a><a name="zh-cn_topic_0000001053666242_a2b235e9ed55f4338886788f140e648a0"></a>规格类型</p>
</th>
<th class="cellrowborder" valign="top" width="85.22999999999999%" id="mcps1.2.3.1.2"><p id="zh-cn_topic_0000001053666242_p9702458104014"><a name="zh-cn_topic_0000001053666242_p9702458104014"></a><a name="zh-cn_topic_0000001053666242_p9702458104014"></a>规格清单</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001053666242_row0171168114311"><td class="cellrowborder" valign="top" width="14.77%" headers="mcps1.2.3.1.1 "><p id="zh-cn_topic_0000001053666242_p1698185431418"><a name="zh-cn_topic_0000001053666242_p1698185431418"></a><a name="zh-cn_topic_0000001053666242_p1698185431418"></a><strong id="zh-cn_topic_0000001053666242_b127621861200"><a name="zh-cn_topic_0000001053666242_b127621861200"></a><a name="zh-cn_topic_0000001053666242_b127621861200"></a>处理器及内部存储</strong></p>
</td>
<td class="cellrowborder" valign="top" width="85.22999999999999%" headers="mcps1.2.3.1.2 "><a name="zh-cn_topic_0000001053666242_ul1147113537186"></a><a name="zh-cn_topic_0000001053666242_ul1147113537186"></a><ul id="zh-cn_topic_0000001053666242_ul1147113537186"><li>Hi3516DV300芯片</li><li>DDR3 1GB</li><li>eMMC4.5，8GB容量</li></ul>
</td>
</tr>
<tr id="zh-cn_topic_0000001053666242_row21721687435"><td class="cellrowborder" valign="top" width="14.77%" headers="mcps1.2.3.1.1 "><p id="zh-cn_topic_0000001053666242_p817216810435"><a name="zh-cn_topic_0000001053666242_p817216810435"></a><a name="zh-cn_topic_0000001053666242_p817216810435"></a><strong id="zh-cn_topic_0000001053666242_b1172016266246"><a name="zh-cn_topic_0000001053666242_b1172016266246"></a><a name="zh-cn_topic_0000001053666242_b1172016266246"></a>外部器件</strong></p>
</td>
<td class="cellrowborder" valign="top" width="85.22999999999999%" headers="mcps1.2.3.1.2 "><a name="zh-cn_topic_0000001053666242_ul179543016208"></a><a name="zh-cn_topic_0000001053666242_ul179543016208"></a><ul id="zh-cn_topic_0000001053666242_ul179543016208"><li>以太网口</li><li>音频视频<a name="zh-cn_topic_0000001053666242_ul5941311869"></a><a name="zh-cn_topic_0000001053666242_ul5941311869"></a><ul id="zh-cn_topic_0000001053666242_ul5941311869"><li>1路语音输入</li><li>1路单声道(AC_L)输出，接3W功率放大器(LM4871)</li><li>MicroHDMI（1路HDMI 1.4）</li></ul>
</li><li>摄像头<a name="zh-cn_topic_0000001053666242_ul924263620"></a><a name="zh-cn_topic_0000001053666242_ul924263620"></a><ul id="zh-cn_topic_0000001053666242_ul924263620"><li>传感器IMX335</li><li>镜头M12，焦距4mm，光圈1.8</li></ul>
</li><li>显示屏<a name="zh-cn_topic_0000001053666242_ul101471711667"></a><a name="zh-cn_topic_0000001053666242_ul101471711667"></a><ul id="zh-cn_topic_0000001053666242_ul101471711667"><li>LCD连接器（2.35寸）</li><li>LCD连接器（5.5寸）</li></ul>
</li><li>外部器件及接口<a name="zh-cn_topic_0000001053666242_ul089255556"></a><a name="zh-cn_topic_0000001053666242_ul089255556"></a><ul id="zh-cn_topic_0000001053666242_ul089255556"><li>SD卡接口</li><li>JTAG/I2S接口</li><li>ADC接口</li><li>舵机接口</li><li>Grove连接器</li><li>USB2.0(Type C)</li><li>功能按键3个，2个用户自定义按键，1个升级按键</li><li>LED指示灯，绿灯，红灯</li></ul>
</li></ul>
</td>
</tr>
</tbody>
</table>

