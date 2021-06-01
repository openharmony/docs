# File Organization<a name="EN-US_TOPIC_0000001115974720"></a>

-   [Directory Structure](#en-us_topic_0000001058830797_section119431650182015)
-   [File Access Rules](#en-us_topic_0000001058830797_section6620355202117)
-   [Media File Formats](#en-us_topic_0000001058830797_section79731562617)

## Directory Structure<a name="en-us_topic_0000001058830797_section119431650182015"></a>

The following figure shows the typical directory structure of the JavaScript module \(**entry/src/main/js/module**\) for an application with feature abilities \(FA\) using JavaScript APIs.

**Figure  1**  Directory structure<a name="en-us_topic_0000001058830797_fig72881050193012"></a>  


![](figures/unnaming-(1).png)

**Figure  2**  Directory structure for resource sharing  <sup>5+</sup><a name="en-us_topic_0000001058830797_fig103221917162010"></a>  
![](figures/directory-structure-for-resource-sharing-5+.png "directory-structure-for-resource-sharing-5+")

Functions of the files are as follows:

-   **.hml**  files describe the page layout.
-   **.css**  files describe the page style.
-   **.js**  files process the interactions between pages and users.

Functions of the folders are as follows:

-   The  **app.js**  file manages global JavaScript logics and application lifecycle.
-   The  **pages**  directory stores all component pages.
-   The  **common**  directory stores public resource files, such as media resources, custom components,  and  **.js**  files.
-   The  **resources**  directory stores resource configuration files, covering global styles and multi-resolution loading.
-   The  **share**  directory is used to configure resources shared by multiple instances. For example, images and JSON files in this directory can be shared by  **default1**  and  **default2**  instances.

>![](public_sys-resources/icon-note.gif) **NOTE:** 
>-   The following reserved folders cannot be renamed:
>    -   share
>    -   resources
>-   If the same resource name and directory are used under the  **share**  directory and the instance \(**default**\) directory, the resource in the instance directory will be used when you reference the directory.

## File Access Rules<a name="en-us_topic_0000001058830797_section6620355202117"></a>

Application resources can be accessed via an absolute or relative path. In the JS UI framework, an absolute path starts with a slash \(/\), and a relative path starts with  **./**  or  **../**. The rules are as follows:

-   To reference a code file, use a relative path, for example,  **../common/utils.js**.
-   To reference a resource file, use an absolute path, for example,  **/common/xxx.png**.
-   Store code files and resource files in the  **common**  directory and access the files in a required fashion.
-   In a  **.css**  file, use the  **url\(\)**  function to create a URL, for example,  **url\(/common/xxx.png\)**.

>![](public_sys-resources/icon-note.gif) **NOTE:** 
>When code file A needs to reference code file B:
>-   If code files A and B are in the same directory, you can use either a relative or absolute path in code file B to reference resource files.
>-   If code files A and B are in different directories, you must use an absolute path in code file B to reference resource files because the directory of code file B changes during Webpack packaging.
>Use an absolute path if you want to dynamically change the resource file path through data binding in a  **.js**  file.

## Media File Formats<a name="en-us_topic_0000001058830797_section79731562617"></a>

**Table  1**  Supported image formats

<a name="en-us_topic_0000001058830797_table59058237819"></a>
<table><thead align="left"><tr id="en-us_topic_0000001058830797_row890542312811"><th class="cellrowborder" valign="top" width="33.33333333333333%" id="mcps1.2.4.1.1"><p id="en-us_topic_0000001058830797_p1290662316815"><a name="en-us_topic_0000001058830797_p1290662316815"></a><a name="en-us_topic_0000001058830797_p1290662316815"></a>Image Format</p>
</th>
<th class="cellrowborder" valign="top" width="33.33333333333333%" id="mcps1.2.4.1.2"><p id="en-us_topic_0000001058830797_p390618231583"><a name="en-us_topic_0000001058830797_p390618231583"></a><a name="en-us_topic_0000001058830797_p390618231583"></a>API Version</p>
</th>
<th class="cellrowborder" valign="top" width="33.33333333333333%" id="mcps1.2.4.1.3"><p id="en-us_topic_0000001058830797_p12906623088"><a name="en-us_topic_0000001058830797_p12906623088"></a><a name="en-us_topic_0000001058830797_p12906623088"></a>File Format</p>
</th>
</tr>
</thead>
<tbody><tr id="en-us_topic_0000001058830797_row49065231788"><td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.1 "><p id="en-us_topic_0000001058830797_p10906112316811"><a name="en-us_topic_0000001058830797_p10906112316811"></a><a name="en-us_topic_0000001058830797_p10906112316811"></a>BMP</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.2 "><p id="en-us_topic_0000001058830797_p139066231811"><a name="en-us_topic_0000001058830797_p139066231811"></a><a name="en-us_topic_0000001058830797_p139066231811"></a>API Version 3+</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.3 "><p id="en-us_topic_0000001058830797_p590619232813"><a name="en-us_topic_0000001058830797_p590619232813"></a><a name="en-us_topic_0000001058830797_p590619232813"></a>.bmp</p>
</td>
</tr>
<tr id="en-us_topic_0000001058830797_row1690615234816"><td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.1 "><p id="en-us_topic_0000001058830797_p6906122313816"><a name="en-us_topic_0000001058830797_p6906122313816"></a><a name="en-us_topic_0000001058830797_p6906122313816"></a>GIF</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.2 "><p id="en-us_topic_0000001058830797_p1906152319810"><a name="en-us_topic_0000001058830797_p1906152319810"></a><a name="en-us_topic_0000001058830797_p1906152319810"></a>API Version 3+</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.3 "><p id="en-us_topic_0000001058830797_p290662317818"><a name="en-us_topic_0000001058830797_p290662317818"></a><a name="en-us_topic_0000001058830797_p290662317818"></a>.gif</p>
</td>
</tr>
<tr id="en-us_topic_0000001058830797_row5906823580"><td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.1 "><p id="en-us_topic_0000001058830797_p109061423685"><a name="en-us_topic_0000001058830797_p109061423685"></a><a name="en-us_topic_0000001058830797_p109061423685"></a>JPEG</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.2 "><p id="en-us_topic_0000001058830797_p89064231083"><a name="en-us_topic_0000001058830797_p89064231083"></a><a name="en-us_topic_0000001058830797_p89064231083"></a>API Version 3+</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.3 "><p id="en-us_topic_0000001058830797_p109061723488"><a name="en-us_topic_0000001058830797_p109061723488"></a><a name="en-us_topic_0000001058830797_p109061723488"></a>.jpg</p>
</td>
</tr>
<tr id="en-us_topic_0000001058830797_row310155772112"><td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.1 "><p id="en-us_topic_0000001058830797_p17101195717217"><a name="en-us_topic_0000001058830797_p17101195717217"></a><a name="en-us_topic_0000001058830797_p17101195717217"></a>PNG</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.2 "><p id="en-us_topic_0000001058830797_p10102195772114"><a name="en-us_topic_0000001058830797_p10102195772114"></a><a name="en-us_topic_0000001058830797_p10102195772114"></a>API Version 3+</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.3 "><p id="en-us_topic_0000001058830797_p161021157162120"><a name="en-us_topic_0000001058830797_p161021157162120"></a><a name="en-us_topic_0000001058830797_p161021157162120"></a>.png</p>
</td>
</tr>
<tr id="en-us_topic_0000001058830797_row942813247228"><td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.1 "><p id="en-us_topic_0000001058830797_p6428152432218"><a name="en-us_topic_0000001058830797_p6428152432218"></a><a name="en-us_topic_0000001058830797_p6428152432218"></a>WebP</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.2 "><p id="en-us_topic_0000001058830797_p342820248225"><a name="en-us_topic_0000001058830797_p342820248225"></a><a name="en-us_topic_0000001058830797_p342820248225"></a>API Version 3+</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.3 "><p id="en-us_topic_0000001058830797_p04281246226"><a name="en-us_topic_0000001058830797_p04281246226"></a><a name="en-us_topic_0000001058830797_p04281246226"></a>.webp</p>
</td>
</tr>
</tbody>
</table>

