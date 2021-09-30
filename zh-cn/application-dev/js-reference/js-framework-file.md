# 文件组织<a name="ZH-CN_TOPIC_0000001164130750"></a>

-   [目录结构](#zh-cn_topic_0000001127125012_section119431650182015)
-   [文件访问规则](#zh-cn_topic_0000001127125012_section6620355202117)
-   [媒体文件格式](#zh-cn_topic_0000001127125012_section79731562617)

## 目录结构<a name="zh-cn_topic_0000001127125012_section119431650182015"></a>

JS FA应用的JS模块\(entry/src/main/js/module\)的典型开发目录结构如下：

**图 1**  目录结构<a name="zh-cn_topic_0000001127125012_fig72881050193012"></a>  


![](figures/unnaming-(1).png)

**图 2**  多实例资源共享目录结构<sup>5+</sup><a name="zh-cn_topic_0000001127125012_fig103221917162010"></a>  
![](figures/多实例资源共享目录结构5+.png "多实例资源共享目录结构5+")

目录结构中文件分类如下：

-   .hml结尾的HML模板文件，这个文件用来描述当前页面的文件布局结构。
-   .css结尾的CSS样式文件，这个文件用于描述页面样式。
-   .js结尾的JS文件，这个文件用于处理页面和用户的交互。

各个文件夹的作用：

-   app.js文件用于全局JavaScript逻辑和应用生命周期管理，详见[app.js](js-framework-js-file.md#ZH-CN_TOPIC_0000001209210691)说明。
-   pages目录用于存放所有组件页面。
-   common目录用于存放公共资源文件，比如：媒体资源，自定义组件和JS文件。
-   resources目录用于存放资源配置文件，比如：多分辨率加载等配置文件，详见[资源限定与访问](js-framework-resource-restriction.md#ZH-CN_TOPIC_0000001164130752)章节。
-   share目录<sup>5+</sup>用于配置多个实例共享的资源内容，比如：share中的图片和JSON文件可被default1和default2实例共享。

>![](../public_sys-resources/icon-note.gif) **说明：** 
>-   i18n和resources是开发保留文件夹，不可重命名。
>-   如果share目录中的资源和实例\(default\)中的资源文件同名且目录一致时，实例中资源的优先级高于share中资源的优先级。
>-   share目录当前不支持i18n。
>-   在使用DevEco Studio进行应用开发时，目录结构中的可选文件夹需要开发者根据实际情况自行创建。

## 文件访问规则<a name="zh-cn_topic_0000001127125012_section6620355202117"></a>

应用资源可通过绝对路径或相对路径的方式进行访问，本开发框架中绝对路径以"/"开头，相对路径以"./"或"../"。具体访问规则如下：

-   引用代码文件，推荐使用相对路径，比如：../common/utils.js。
-   引用资源文件，推荐使用绝对路径。比如：/common/xxx.png。
-   公共代码文件和资源文件推荐放在common下，通过以上两条规则进行访问。
-   CSS样式文件中通过url\(\)函数创建<url\>数据类型，如：url\(/common/xxx.png\)。

>![](../public_sys-resources/icon-note.gif) **说明：** 
>当代码文件A需要引用代码文件B时：
>-   如果代码文件A和文件B位于同一目录，则代码文件B引用资源文件时可使用相对路径，也可使用绝对路径。
>-   如果代码文件A和文件B位于不同目录，则代码文件B引用资源文件时必须使用绝对路径。因为Webpack打包时，代码文件B的目录会发生变化。
>-   在js文件中通过数据绑定的方式指定资源文件路径时，必须使用绝对路径。

## 媒体文件格式<a name="zh-cn_topic_0000001127125012_section79731562617"></a>

**表 1**  支持的图片格式

<a name="zh-cn_topic_0000001127125012_table59058237819"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001127125012_row890542312811"><th class="cellrowborder" valign="top" width="33.33333333333333%" id="mcps1.2.4.1.1"><p id="zh-cn_topic_0000001127125012_p1290662316815"><a name="zh-cn_topic_0000001127125012_p1290662316815"></a><a name="zh-cn_topic_0000001127125012_p1290662316815"></a>格式</p>
</th>
<th class="cellrowborder" valign="top" width="33.33333333333333%" id="mcps1.2.4.1.2"><p id="zh-cn_topic_0000001127125012_p390618231583"><a name="zh-cn_topic_0000001127125012_p390618231583"></a><a name="zh-cn_topic_0000001127125012_p390618231583"></a>支持版本</p>
</th>
<th class="cellrowborder" valign="top" width="33.33333333333333%" id="mcps1.2.4.1.3"><p id="zh-cn_topic_0000001127125012_p12906623088"><a name="zh-cn_topic_0000001127125012_p12906623088"></a><a name="zh-cn_topic_0000001127125012_p12906623088"></a>支持的文件类型</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001127125012_row49065231788"><td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.1 "><p id="zh-cn_topic_0000001127125012_p10906112316811"><a name="zh-cn_topic_0000001127125012_p10906112316811"></a><a name="zh-cn_topic_0000001127125012_p10906112316811"></a>BMP</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.2 "><p id="zh-cn_topic_0000001127125012_p139066231811"><a name="zh-cn_topic_0000001127125012_p139066231811"></a><a name="zh-cn_topic_0000001127125012_p139066231811"></a>API Version 3+</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.3 "><p id="zh-cn_topic_0000001127125012_p590619232813"><a name="zh-cn_topic_0000001127125012_p590619232813"></a><a name="zh-cn_topic_0000001127125012_p590619232813"></a>.bmp</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001127125012_row1690615234816"><td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.1 "><p id="zh-cn_topic_0000001127125012_p6906122313816"><a name="zh-cn_topic_0000001127125012_p6906122313816"></a><a name="zh-cn_topic_0000001127125012_p6906122313816"></a>GIF</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.2 "><p id="zh-cn_topic_0000001127125012_p1906152319810"><a name="zh-cn_topic_0000001127125012_p1906152319810"></a><a name="zh-cn_topic_0000001127125012_p1906152319810"></a>API Version 3+</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.3 "><p id="zh-cn_topic_0000001127125012_p290662317818"><a name="zh-cn_topic_0000001127125012_p290662317818"></a><a name="zh-cn_topic_0000001127125012_p290662317818"></a>.gif</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001127125012_row5906823580"><td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.1 "><p id="zh-cn_topic_0000001127125012_p109061423685"><a name="zh-cn_topic_0000001127125012_p109061423685"></a><a name="zh-cn_topic_0000001127125012_p109061423685"></a>JPEG</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.2 "><p id="zh-cn_topic_0000001127125012_p89064231083"><a name="zh-cn_topic_0000001127125012_p89064231083"></a><a name="zh-cn_topic_0000001127125012_p89064231083"></a>API Version 3+</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.3 "><p id="zh-cn_topic_0000001127125012_p109061723488"><a name="zh-cn_topic_0000001127125012_p109061723488"></a><a name="zh-cn_topic_0000001127125012_p109061723488"></a>.jpg</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001127125012_row310155772112"><td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.1 "><p id="zh-cn_topic_0000001127125012_p17101195717217"><a name="zh-cn_topic_0000001127125012_p17101195717217"></a><a name="zh-cn_topic_0000001127125012_p17101195717217"></a>PNG</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.2 "><p id="zh-cn_topic_0000001127125012_p10102195772114"><a name="zh-cn_topic_0000001127125012_p10102195772114"></a><a name="zh-cn_topic_0000001127125012_p10102195772114"></a>API Version 3+</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.3 "><p id="zh-cn_topic_0000001127125012_p161021157162120"><a name="zh-cn_topic_0000001127125012_p161021157162120"></a><a name="zh-cn_topic_0000001127125012_p161021157162120"></a>.png</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001127125012_row942813247228"><td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.1 "><p id="zh-cn_topic_0000001127125012_p6428152432218"><a name="zh-cn_topic_0000001127125012_p6428152432218"></a><a name="zh-cn_topic_0000001127125012_p6428152432218"></a>WebP</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.2 "><p id="zh-cn_topic_0000001127125012_p342820248225"><a name="zh-cn_topic_0000001127125012_p342820248225"></a><a name="zh-cn_topic_0000001127125012_p342820248225"></a>API Version 3+</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.3 "><p id="zh-cn_topic_0000001127125012_p04281246226"><a name="zh-cn_topic_0000001127125012_p04281246226"></a><a name="zh-cn_topic_0000001127125012_p04281246226"></a>.webp</p>
</td>
</tr>
</tbody>
</table>

**表 2**  支持的视频格式

<a name="zh-cn_topic_0000001127125012_table31310367289"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001127125012_row713736152813"><th class="cellrowborder" valign="top" width="33.33333333333333%" id="mcps1.2.4.1.1"><p id="zh-cn_topic_0000001127125012_p11383616283"><a name="zh-cn_topic_0000001127125012_p11383616283"></a><a name="zh-cn_topic_0000001127125012_p11383616283"></a>格式</p>
</th>
<th class="cellrowborder" valign="top" width="33.33333333333333%" id="mcps1.2.4.1.2"><p id="zh-cn_topic_0000001127125012_p513183616281"><a name="zh-cn_topic_0000001127125012_p513183616281"></a><a name="zh-cn_topic_0000001127125012_p513183616281"></a>支持版本</p>
</th>
<th class="cellrowborder" valign="top" width="33.33333333333333%" id="mcps1.2.4.1.3"><p id="zh-cn_topic_0000001127125012_p91353619287"><a name="zh-cn_topic_0000001127125012_p91353619287"></a><a name="zh-cn_topic_0000001127125012_p91353619287"></a>支持的文件类型</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001127125012_row1613136102817"><td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.1 "><p id="zh-cn_topic_0000001127125012_p1713736192820"><a name="zh-cn_topic_0000001127125012_p1713736192820"></a><a name="zh-cn_topic_0000001127125012_p1713736192820"></a>H.264 AVC</p>
<p id="zh-cn_topic_0000001127125012_p181343620281"><a name="zh-cn_topic_0000001127125012_p181343620281"></a><a name="zh-cn_topic_0000001127125012_p181343620281"></a>Baseline Profile (BP)</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.2 "><p id="zh-cn_topic_0000001127125012_p5148365289"><a name="zh-cn_topic_0000001127125012_p5148365289"></a><a name="zh-cn_topic_0000001127125012_p5148365289"></a>API Version 3+</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.3 "><p id="zh-cn_topic_0000001127125012_p1014136162818"><a name="zh-cn_topic_0000001127125012_p1014136162818"></a><a name="zh-cn_topic_0000001127125012_p1014136162818"></a>.3gp</p>
<p id="zh-cn_topic_0000001127125012_p121418360288"><a name="zh-cn_topic_0000001127125012_p121418360288"></a><a name="zh-cn_topic_0000001127125012_p121418360288"></a>.mp4</p>
</td>
</tr>
</tbody>
</table>

