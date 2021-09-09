# Introduction<a name="EN-US_TOPIC_0000001166764513"></a>

-   [Quick Start Process](#section7825218111517)
-   [Introduction to the Development Board](#en-us_topic_0000001053666242_section047719215429)
-   [Development Board Specifications](#en-us_topic_0000001053666242_section15192203316533)

This document helps you quickly understand how to set up a standard OpenHarmony system, and how to build, burn, and start the system. You can develop the standard system in Windows and build source code in Linux.

This document uses the recommended Hi3516D V300 development board as an example.

## Quick Start Process<a name="section7825218111517"></a>

The following figure shows the process of getting started for the standard system, during which, you can set up the Ubuntu development environment in Docker mode or by using the installation package.

**Figure  1**  Getting started for the standard system<a name="fig19162195553211"></a>  
![](figure/getting-started-for-the-standard-system.png "getting-started-for-the-standard-system")

## Introduction to the Development Board<a name="en-us_topic_0000001053666242_section047719215429"></a>

Hi3516D V300 is a next-generation system on chip \(SoC\) designed for the industry-dedicated smart HD IP camera. It introduces a next-generation image signal processor \(ISP\), the H.265 video compression encoder, and a high-performance NNIE engine, leading the industry in terms of low bit rate, high image quality, intelligent processing and analysis, and low power consumption.

**Figure  2**  Hi3516D V300 front view<a name="fig202901538183412"></a>  
![](figure/hi3516d-v300-front-view-27.png "hi3516d-v300-front-view-27")

## Development Board Specifications<a name="en-us_topic_0000001053666242_section15192203316533"></a>

**Table  1**  Specifications of the Hi3516 development board

<a name="en-us_topic_0000001053666242_table31714894311"></a>
<table><thead align="left"><tr id="en-us_topic_0000001053666242_row10171198194310"><th class="cellrowborder" valign="top" width="14.77%" id="mcps1.2.3.1.1"><p id="en-us_topic_0000001053666242_a2b235e9ed55f4338886788f140e648a0"><a name="en-us_topic_0000001053666242_a2b235e9ed55f4338886788f140e648a0"></a><a name="en-us_topic_0000001053666242_a2b235e9ed55f4338886788f140e648a0"></a>Item</p>
</th>
<th class="cellrowborder" valign="top" width="85.22999999999999%" id="mcps1.2.3.1.2"><p id="en-us_topic_0000001053666242_p9702458104014"><a name="en-us_topic_0000001053666242_p9702458104014"></a><a name="en-us_topic_0000001053666242_p9702458104014"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="en-us_topic_0000001053666242_row0171168114311"><td class="cellrowborder" valign="top" width="14.77%" headers="mcps1.2.3.1.1 "><p id="en-us_topic_0000001053666242_p1698185431418"><a name="en-us_topic_0000001053666242_p1698185431418"></a><a name="en-us_topic_0000001053666242_p1698185431418"></a>Processor and internal memory</p>
</td>
<td class="cellrowborder" valign="top" width="85.22999999999999%" headers="mcps1.2.3.1.2 "><a name="en-us_topic_0000001053666242_ul1147113537186"></a><a name="en-us_topic_0000001053666242_ul1147113537186"></a><ul id="en-us_topic_0000001053666242_ul1147113537186"><li>Hi3516D V300</li><li>1 GB DDR3</li><li>8 GB eMMC4.5</li></ul>
</td>
</tr>
<tr id="en-us_topic_0000001053666242_row21721687435"><td class="cellrowborder" valign="top" width="14.77%" headers="mcps1.2.3.1.1 "><p id="en-us_topic_0000001053666242_p817216810435"><a name="en-us_topic_0000001053666242_p817216810435"></a><a name="en-us_topic_0000001053666242_p817216810435"></a>External components</p>
</td>
<td class="cellrowborder" valign="top" width="85.22999999999999%" headers="mcps1.2.3.1.2 "><a name="en-us_topic_0000001053666242_ul179543016208"></a><a name="en-us_topic_0000001053666242_ul179543016208"></a><ul id="en-us_topic_0000001053666242_ul179543016208"><li>Ethernet port</li><li>Audio and video<a name="en-us_topic_0000001053666242_ul5941311869"></a><a name="en-us_topic_0000001053666242_ul5941311869"></a><ul id="en-us_topic_0000001053666242_ul5941311869"><li>One voice input</li><li>One mono (AC_L) output, connected to a 3 W power amplifier (LM4871)</li><li>Micro-HDMI (one HDMI 1.4)</li></ul>
</li><li>Cameras<a name="en-us_topic_0000001053666242_ul924263620"></a><a name="en-us_topic_0000001053666242_ul924263620"></a><ul id="en-us_topic_0000001053666242_ul924263620"><li>Sensor IMX335</li><li>M12 lens with a focal length of 4 mm and an aperture of 1.8</li></ul>
</li><li>Display<a name="en-us_topic_0000001053666242_ul101471711667"></a><a name="en-us_topic_0000001053666242_ul101471711667"></a><ul id="en-us_topic_0000001053666242_ul101471711667"><li>2.35-inch LCD connector</li><li>5.5-inch LCD connector</li></ul>
</li><li>External components and interfaces<a name="en-us_topic_0000001053666242_ul089255556"></a><a name="en-us_topic_0000001053666242_ul089255556"></a><ul id="en-us_topic_0000001053666242_ul089255556"><li>microSD card interface</li><li>JTAG/I2S interface</li><li>ADC interface</li><li>Steer gear interface</li><li>Grove connector</li><li>USB 2.0 (Type C)</li><li>Three function keys: two custom keys and one update key</li><li>LED indicator (including green and red)</li></ul>
</li></ul>
</td>
</tr>
</tbody>
</table>

