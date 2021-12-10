# File Organization<a name="EN-US_TOPIC_0000001127125012"></a>

## Directory Structure<a name="section119431650182015"></a>

The following figure shows the typical directory structure of the JavaScript module \(**entry/src/main/js/module**\) for an application with feature abilities \(FA\) using JavaScript APIs.

**Figure  1**  Directory structure<a name="fig72881050193012"></a>  


![](figures/unnaming-(1).png)

**Figure  2**  Directory structure for resource sharing  <sup>5+</sup><a name="fig103221917162010"></a>  
![](figures/directory-structure-for-resource-sharing-5+.png "directory-structure-for-resource-sharing-5+")

Functions of the files are as follows:

-   **.hml**  files describe the page layout.
-   **.css**  files describe the page style.
-   **.js**  files process the interactions between pages and users.

Functions of the folders are as follows:

-   The  **app.js**  file manages global JavaScript logics and application lifecycle. For details, see  [app.js](js-framework-js-file.md).
-   The  **pages**  directory stores all component pages.
-   The  **common**  directory stores public resource files, such as media resources, custom components,  and  **.js**  files.
-   The  **resources**  directory stores resource configuration files, for example, for multi-resolution loading. For details, see  [Resource Limitations and Access](js-framework-resource-restriction.md).
-   The  **share**  directory<sup>5+</sup>  is used to configure resources shared by multiple instances. For example, images and JSON files in this directory can be shared by  **default1**  and  **default2**  instances.

>![](../../public_sys-resources/icon-note.gif) **NOTE:** 
>-   Reserved folders \(**i18n**  and  **resources**\) cannot be renamed.
>-   If the same resource name and directory are used under the  **share**  directory and the instance \(**default**\) directory, the resource in the instance directory will be used when you reference the directory.
>-   The  **share**  directory does not support  **i18n**.
>-   You should create the optional folders \(shown in the directory structure\) as needed after you create the project in DevEco Studio.

## File Access Rules<a name="section6620355202117"></a>

Application resources can be accessed via an absolute or relative path. In the JS UI framework, an absolute path starts with a slash \(/\), and a relative path starts with  **./**  or  **../**. The rules are as follows:

-   To reference a code file, use a relative path, for example,  **../common/utils.js**.
-   To reference a resource file, use an absolute path, for example,  **/common/xxx.png**.
-   Store code files and resource files in the  **common**  directory and access the files in a required fashion.
-   In a  **.css**  file, use the  **url\(\)**  function to create a URL, for example,  **url\(/common/xxx.png\)**.

>![](../../public_sys-resources/icon-note.gif) **NOTE:** 
>When code file A needs to reference code file B:
>-   If code files A and B are in the same directory, you can use either a relative or absolute path in code file B to reference resource files.
>-   If code files A and B are in different directories, you must use an absolute path in code file B to reference resource files because the directory of code file B changes during Webpack packaging.
>-   Use an absolute path if you want to dynamically change the resource file path through data binding in a  **.js**  file.

## Media File Formats<a name="section79731562617"></a>

**Table  1**  Supported image formats

<a name="table59058237819"></a>
<table><thead align="left"><tr id="row890542312811"><th class="cellrowborder" valign="top" width="33.33333333333333%" id="mcps1.2.4.1.1"><p id="p1290662316815"><a name="p1290662316815"></a><a name="p1290662316815"></a>Image Format</p>
</th>
<th class="cellrowborder" valign="top" width="33.33333333333333%" id="mcps1.2.4.1.2"><p id="p390618231583"><a name="p390618231583"></a><a name="p390618231583"></a>API Version</p>
</th>
<th class="cellrowborder" valign="top" width="33.33333333333333%" id="mcps1.2.4.1.3"><p id="p12906623088"><a name="p12906623088"></a><a name="p12906623088"></a>File Format</p>
</th>
</tr>
</thead>
<tbody><tr id="row49065231788"><td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.1 "><p id="p10906112316811"><a name="p10906112316811"></a><a name="p10906112316811"></a>BMP</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.2 "><p id="p139066231811"><a name="p139066231811"></a><a name="p139066231811"></a>API Version 3+</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.3 "><p id="p590619232813"><a name="p590619232813"></a><a name="p590619232813"></a>.bmp</p>
</td>
</tr>
<tr id="row1690615234816"><td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.1 "><p id="p6906122313816"><a name="p6906122313816"></a><a name="p6906122313816"></a>GIF</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.2 "><p id="p1906152319810"><a name="p1906152319810"></a><a name="p1906152319810"></a>API Version 3+</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.3 "><p id="p290662317818"><a name="p290662317818"></a><a name="p290662317818"></a>.gif</p>
</td>
</tr>
<tr id="row5906823580"><td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.1 "><p id="p109061423685"><a name="p109061423685"></a><a name="p109061423685"></a>JPEG</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.2 "><p id="p89064231083"><a name="p89064231083"></a><a name="p89064231083"></a>API Version 3+</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.3 "><p id="p109061723488"><a name="p109061723488"></a><a name="p109061723488"></a>.jpg</p>
</td>
</tr>
<tr id="row310155772112"><td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.1 "><p id="p17101195717217"><a name="p17101195717217"></a><a name="p17101195717217"></a>PNG</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.2 "><p id="p10102195772114"><a name="p10102195772114"></a><a name="p10102195772114"></a>API Version 3+</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.3 "><p id="p161021157162120"><a name="p161021157162120"></a><a name="p161021157162120"></a>.png</p>
</td>
</tr>
<tr id="row942813247228"><td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.1 "><p id="p6428152432218"><a name="p6428152432218"></a><a name="p6428152432218"></a>WebP</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.2 "><p id="p342820248225"><a name="p342820248225"></a><a name="p342820248225"></a>API Version 3+</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.3 "><p id="p04281246226"><a name="p04281246226"></a><a name="p04281246226"></a>.webp</p>
</td>
</tr>
</tbody>
</table>

**Table  2**  Supported video formats

<a name="table31310367289"></a>
<table><thead align="left"><tr id="row713736152813"><th class="cellrowborder" valign="top" width="33.33333333333333%" id="mcps1.2.4.1.1"><p id="p11383616283"><a name="p11383616283"></a><a name="p11383616283"></a>Video Formats</p>
</th>
<th class="cellrowborder" valign="top" width="33.33333333333333%" id="mcps1.2.4.1.2"><p id="p513183616281"><a name="p513183616281"></a><a name="p513183616281"></a>API Version</p>
</th>
<th class="cellrowborder" valign="top" width="33.33333333333333%" id="mcps1.2.4.1.3"><p id="p91353619287"><a name="p91353619287"></a><a name="p91353619287"></a>File Formats</p>
</th>
</tr>
</thead>
<tbody><tr id="row1613136102817"><td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.1 "><p id="p1713736192820"><a name="p1713736192820"></a><a name="p1713736192820"></a>H.264 AVC</p>
<p id="p181343620281"><a name="p181343620281"></a><a name="p181343620281"></a>Baseline Profile (BP)</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.2 "><p id="p5148365289"><a name="p5148365289"></a><a name="p5148365289"></a>API Version 3+</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.3 "><p id="p1014136162818"><a name="p1014136162818"></a><a name="p1014136162818"></a>.3gp</p>
<p id="p121418360288"><a name="p121418360288"></a><a name="p121418360288"></a>.mp4</p>
</td>
</tr>
</tbody>
</table>

