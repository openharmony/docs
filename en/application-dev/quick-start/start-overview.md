# Preparations<a name="EN-US_TOPIC_0000001063968051"></a>

## Task Description<a name="section2073881513322"></a>

This document is intended for novices at developing OpenHarmony apps. You will learn the development procedure from the following sections to build two pages and implement redirection from the first page to the second one. The following figure shows how the pages look on the  [Previewer](https://developer.harmonyos.com/en/docs/documentation/doc-guides/previewer-0000001054328973#ZH-CN_TOPIC_0000001056725592__section16523172216252).

For best results, use the  [latest version of DevEco Studio](https://developer.harmonyos.com/en/develop/deveco-studio#download)  for your development.

![](figures/3.png)

**Table  1**  Comparison between  ArkUI paradigms

<a name="table1663194773617"></a>
<table><thead align="left"><tr id="row20632174793610"><th class="cellrowborder" valign="top" width="17.88%" id="mcps1.2.4.1.1"><p id="p1863274783615"><a name="p1863274783615"></a><a name="p1863274783615"></a>Comparison Item</p>
</th>
<th class="cellrowborder" valign="top" width="41.730000000000004%" id="mcps1.2.4.1.2"><p id="p344415455554"><a name="p344415455554"></a><a name="p344415455554"></a>JavaScript-based Web-like Development Paradigm</p>
</th>
<th class="cellrowborder" valign="top" width="40.39%" id="mcps1.2.4.1.3"><p id="p20391115416559"><a name="p20391115416559"></a><a name="p20391115416559"></a>TypeScript-based Declarative Development Paradigm</p>
</th>
</tr>
</thead>
<tbody><tr id="row15632164733618"><td class="cellrowborder" valign="top" width="17.88%" headers="mcps1.2.4.1.1 "><p id="p166323477367"><a name="p166323477367"></a><a name="p166323477367"></a>Language</p>
</td>
<td class="cellrowborder" valign="top" width="41.730000000000004%" headers="mcps1.2.4.1.2 "><p id="p16321947123618"><a name="p16321947123618"></a><a name="p16321947123618"></a>JS</p>
</td>
<td class="cellrowborder" valign="top" width="40.39%" headers="mcps1.2.4.1.3 "><p id="p1563224773617"><a name="p1563224773617"></a><a name="p1563224773617"></a>eTS</p>
</td>
</tr>
<tr id="row17632144716361"><td class="cellrowborder" valign="top" width="17.88%" headers="mcps1.2.4.1.1 "><p id="p10632184713363"><a name="p10632184713363"></a><a name="p10632184713363"></a>Paradigm</p>
</td>
<td class="cellrowborder" valign="top" width="41.730000000000004%" headers="mcps1.2.4.1.2 "><p id="p13632447133617"><a name="p13632447133617"></a><a name="p13632447133617"></a>Web-like paradigm</p>
</td>
<td class="cellrowborder" valign="top" width="40.39%" headers="mcps1.2.4.1.3 "><p id="p15632114710367"><a name="p15632114710367"></a><a name="p15632114710367"></a>Declarative paradigm</p>
</td>
</tr>
<tr id="row2632134753615"><td class="cellrowborder" valign="top" width="17.88%" headers="mcps1.2.4.1.1 "><p id="p46321947183612"><a name="p46321947183612"></a><a name="p46321947183612"></a>Execution</p>
</td>
<td class="cellrowborder" valign="top" width="41.730000000000004%" headers="mcps1.2.4.1.2 "><p id="p1363244717361"><a name="p1363244717361"></a><a name="p1363244717361"></a>Handled by the framework; data-driven automatic UI update</p>
</td>
<td class="cellrowborder" valign="top" width="40.39%" headers="mcps1.2.4.1.3 "><p id="p1463274733610"><a name="p1463274733610"></a><a name="p1463274733610"></a>Handled by the framework; data-driven automatic UI update</p>
</td>
</tr>
<tr id="row126321547173610"><td class="cellrowborder" valign="top" width="17.88%" headers="mcps1.2.4.1.1 "><p id="p963314717366"><a name="p963314717366"></a><a name="p963314717366"></a>Advantages</p>
</td>
<td class="cellrowborder" valign="top" width="41.730000000000004%" headers="mcps1.2.4.1.2 "><p id="p963314710361"><a name="p963314710361"></a><a name="p963314710361"></a>Simple and easy to use</p>
</td>
<td class="cellrowborder" valign="top" width="40.39%" headers="mcps1.2.4.1.3 "><p id="p963315474367"><a name="p963315474367"></a><a name="p963315474367"></a>Simplified development, less memory usage, and higher running performance</p>
</td>
</tr>
</tbody>
</table>
## Before You Start<a name="section965173113911"></a>

1.  Install DevEco Studio and configure the development environment. For details, see  [Configuring the OpenHarmony SDK](configuring-openharmony-sdk.md).
2.  Create a project as instructed in  [Creating an OpenHarmony Project](create-openharmony-project.md).
    -   If you are using the JavaScript language, select  **Empty Ability**  for  **Template**  and  **JS**  for  **Language**.
    
3.  Use the  [previewer](https://developer.harmonyos.com/en/docs/documentation/doc-guides/previewer-0000001054328973#EN-US_TOPIC_0000001056725592__section16523172216252)  or  [emulator](https://developer.harmonyos.com/en/docs/documentation/doc-guides/run_simulator-0000001053303709)  to run the project.

Now you have created your first OpenHarmony project. You can continue the development by following instructions in  [Getting Started with JavaScript](start-with-js.md).

