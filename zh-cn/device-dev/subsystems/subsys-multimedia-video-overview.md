# 音视频开发概述<a name="ZH-CN_TOPIC_0000001051770578"></a>


OpenHarmony音视频包括音视频播放和录制。

-   OpenHarmony音视频播放模块支持音视频播放业务的开发，主要包括音视频文件和音视频流播放、音量和播放进度控制等。
-   OpenHarmony录制模块支持音视频录制业务的开发，提供音视频录制相关的功能，包括设置录制视频画面尺寸、音视频编码码率、编码器类型、视频帧率、音频采样率、录制文件输出格式等。

## 基本概念<a name="section967213571204"></a>

在进行应用的开发OpenHarmony前，开发者应了解以下基本概念：

-   流媒体技术

    流媒体技术是把连续的影像和声音信息进行编码处理后放在网络服务器上，让浏览者一边下载、一边观看与收听，而不需要等整个多媒体文件下载完成就可以即时观看、收听的技术。


-   视频帧率

    帧率是用于测量显示帧数的度量，帧数就是在每秒钟时间里传输的图片数量。每秒钟帧数 \(FPS\) 越多，所显示的画面就会越流畅。

-   码率

    码率就是数据传输时单位时间传送的数据位数，常用单位是kbps即千位每秒。

-   采样率

    采样率为每秒从连续信号中提取并组成离散信号的采样个数，单位用赫兹（Hz）来表示。


## 编解码规格<a name="section1582020483111"></a>

OpenHarmony音视频编解码能力取决于具体设备类型，以当前已支持的开发板为例，规格见下表：

**表 1**  不同开发板编解码规格

<a name="table1611142712535"></a>
<table><thead align="left"><tr id="row5129278531"><th class="cellrowborder" valign="top" width="7.520752075207521%" id="mcps1.2.5.1.1"><p id="p163711594517"><a name="p163711594517"></a><a name="p163711594517"></a>设备类型</p>
</th>
<th class="cellrowborder" valign="top" width="8.24082408240824%" id="mcps1.2.5.1.2"><p id="p1112727195316"><a name="p1112727195316"></a><a name="p1112727195316"></a>开发板类型</p>
</th>
<th class="cellrowborder" valign="top" width="40.82408240824083%" id="mcps1.2.5.1.3"><p id="p14124279538"><a name="p14124279538"></a><a name="p14124279538"></a>解码规格</p>
</th>
<th class="cellrowborder" valign="top" width="43.41434143414341%" id="mcps1.2.5.1.4"><p id="p812132715535"><a name="p812132715535"></a><a name="p812132715535"></a>编码规格</p>
</th>
</tr>
</thead>
<tbody><tr id="row712427195316"><td class="cellrowborder" valign="top" width="7.520752075207521%" headers="mcps1.2.5.1.1 "><p id="p19371179459"><a name="p19371179459"></a><a name="p19371179459"></a>带屏摄像头类产品</p>
</td>
<td class="cellrowborder" valign="top" width="8.24082408240824%" headers="mcps1.2.5.1.2 "><p id="p1312182713535"><a name="p1312182713535"></a><a name="p1312182713535"></a>Hi3516</p>
</td>
<td class="cellrowborder" valign="top" width="40.82408240824083%" headers="mcps1.2.5.1.3 "><a name="ul178862023587"></a><a name="ul178862023587"></a><ul id="ul178862023587"><li>音频解码：支持MPEG-4 AAC Profile (AAC LC)、MPEG Audio Layer 3 (MP3)格式解码,支持单/双声道，支持MPEG-4(.mp4，.m4a)、MP3(.mp3)容器格式。</li><li>视频解码：支持H.265 HEVC/H.264 AVC格式解码（限自身编码码流），支持MPEG-4(.mp4)容器格式。</li></ul>
</td>
<td class="cellrowborder" valign="top" width="43.41434143414341%" headers="mcps1.2.5.1.4 "><a name="ul5101301882"></a><a name="ul5101301882"></a><ul id="ul5101301882"><li>音频编码：支持音频AAC_LC编码，支持单/双声道，支持MPEG-4(.mp4)容器格式。</li><li>视频编码：支持视频H.264/H.265编码，支持MPEG-4(.mp4)容器格式。</li></ul>
</td>
</tr>
<tr id="row01212273532"><td class="cellrowborder" valign="top" width="7.520752075207521%" headers="mcps1.2.5.1.1 "><p id="p33711914515"><a name="p33711914515"></a><a name="p33711914515"></a>无屏摄像头类产品</p>
</td>
<td class="cellrowborder" valign="top" width="8.24082408240824%" headers="mcps1.2.5.1.2 "><p id="p51202713531"><a name="p51202713531"></a><a name="p51202713531"></a>Hi3518</p>
</td>
<td class="cellrowborder" valign="top" width="40.82408240824083%" headers="mcps1.2.5.1.3 "><a name="ul11786193316820"></a><a name="ul11786193316820"></a><ul id="ul11786193316820"><li>音频解码：支持MPEG-4 AAC Profile (AAC LC)、MPEG Audio Layer 3 (MP3)格式解码，支持单/双声道，支持MPEG-4(.mp4，.m4a)、MP3(.mp3)容器格式。</li><li>视频解码：-</li></ul>
</td>
<td class="cellrowborder" valign="top" width="43.41434143414341%" headers="mcps1.2.5.1.4 "><a name="ul816485812814"></a><a name="ul816485812814"></a><ul id="ul816485812814"><li>音频编码：支持音频AAC_LC编码，支持单/双声道，支持MPEG-4(.mp4)容器格式。</li><li>视频编码：支持视频H.264/H.265编码，支持MPEG-4(.mp4)容器格式。</li></ul>
</td>
</tr>
<tr id="row1812172713534"><td class="cellrowborder" valign="top" width="7.520752075207521%" headers="mcps1.2.5.1.1 "><p id="p6371594514"><a name="p6371594514"></a><a name="p6371594514"></a>WLAN连接类设备</p>
</td>
<td class="cellrowborder" valign="top" width="8.24082408240824%" headers="mcps1.2.5.1.2 "><p id="p1212927165318"><a name="p1212927165318"></a><a name="p1212927165318"></a>Hi3861</p>
</td>
<td class="cellrowborder" valign="top" width="40.82408240824083%" headers="mcps1.2.5.1.3 "><p id="p9122271537"><a name="p9122271537"></a><a name="p9122271537"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="43.41434143414341%" headers="mcps1.2.5.1.4 "><p id="p2012122713531"><a name="p2012122713531"></a><a name="p2012122713531"></a>-</p>
</td>
</tr>
</tbody>
</table>

Hi3516和Hi3518更多详细的编解码规格请参考开发板自带的资料。

