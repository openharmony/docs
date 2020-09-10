# Graphics Subsystem<a name="EN-US_TOPIC_0000001051979319"></a>

## Overview<a name="section5243712115918"></a>

The graphics subsystem mainly includes user interface \(UI\) components, layout, animator, font, input event, window management, rendering and drawing modules. It builds an application framework based on the LiteOS to develop  applications on Internet of Things \(IoT\) devices with small hardware resources.

Module description:

-   Components: provides application components, including the UIView, UIViewGoup, UIButton, UILabel, UILabelButton, UIList, and UISlider.
-   Layout: lays out components, including Flexlayout, GridLayout, and ListLayout.
-   Animator: defines functions for customizing animators.
-   Fonts: defines functions related to fonts.
-   Event: processes basic events, including click, press, drag, and long press.
-   Tasks: manages tasks.
-   Input: processes input events.
-   Display: processes display events.
-   Render: renders and draws components.
-   Draw2d: draws lines, rectangles, circles, arcs, images, and texts, and interconnects with software rendering and hardware acceleration.
-   Surface: applies for and releases shared memory.
-   Window: manages windows, including creating, showing, hiding a window, and combining windows.
-   Adapter: interconnects with underlying interfaces of the adaptation layer.

## Directory Structure<a name="section99241319175914"></a>

**Table  1**  Directory structure of source code for the graphics subsystem

<a name="table2977131081412"></a>
<table><thead align="left"><tr id="row7977610131417"><th class="cellrowborder" valign="top" width="17.7%" id="mcps1.2.3.1.1"><p id="p18792459121314"><a name="p18792459121314"></a><a name="p18792459121314"></a>Directory</p>
</th>
<th class="cellrowborder" valign="top" width="82.3%" id="mcps1.2.3.1.2"><p id="p77921459191317"><a name="p77921459191317"></a><a name="p77921459191317"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row17977171010144"><td class="cellrowborder" valign="top" width="17.7%" headers="mcps1.2.3.1.1 "><p id="p2793159171311"><a name="p2793159171311"></a><a name="p2793159171311"></a>config</p>
</td>
<td class="cellrowborder" valign="top" width="82.3%" headers="mcps1.2.3.1.2 "><p id="p879375920132"><a name="p879375920132"></a><a name="p879375920132"></a>Configuration files</p>
</td>
</tr>
<tr id="row6978161091412"><td class="cellrowborder" valign="top" width="17.7%" headers="mcps1.2.3.1.1 "><p id="p37931659101311"><a name="p37931659101311"></a><a name="p37931659101311"></a>frameworks/surface</p>
</td>
<td class="cellrowborder" valign="top" width="82.3%" headers="mcps1.2.3.1.2 "><p id="p6793059171318"><a name="p6793059171318"></a><a name="p6793059171318"></a>Shared memory</p>
</td>
</tr>
<tr id="row6978201031415"><td class="cellrowborder" valign="top" width="17.7%" headers="mcps1.2.3.1.1 "><p id="p117935599130"><a name="p117935599130"></a><a name="p117935599130"></a>frameworks/ui</p>
</td>
<td class="cellrowborder" valign="top" width="82.3%" headers="mcps1.2.3.1.2 "><p id="p0793185971316"><a name="p0793185971316"></a><a name="p0793185971316"></a>UI module, which defines functions related to UI components, animators and fonts.</p>
</td>
</tr>
<tr id="row1897841071415"><td class="cellrowborder" valign="top" width="17.7%" headers="mcps1.2.3.1.1 "><p id="p16793185961315"><a name="p16793185961315"></a><a name="p16793185961315"></a>hals</p>
</td>
<td class="cellrowborder" valign="top" width="82.3%" headers="mcps1.2.3.1.2 "><p id="p14793959161317"><a name="p14793959161317"></a><a name="p14793959161317"></a>Hardware abstraction layer (HAL) logic</p>
</td>
</tr>
<tr id="row1420633124613"><td class="cellrowborder" valign="top" width="17.7%" headers="mcps1.2.3.1.1 "><p id="p16207133194613"><a name="p16207133194613"></a><a name="p16207133194613"></a>interfaces/ui</p>
</td>
<td class="cellrowborder" valign="top" width="82.3%" headers="mcps1.2.3.1.2 "><p id="p182076317465"><a name="p182076317465"></a><a name="p182076317465"></a>Header files of open APIs related to the UI module</p>
</td>
</tr>
<tr id="row1679114715461"><td class="cellrowborder" valign="top" width="17.7%" headers="mcps1.2.3.1.1 "><p id="p1079120477466"><a name="p1079120477466"></a><a name="p1079120477466"></a>interfaces/utils</p>
</td>
<td class="cellrowborder" valign="top" width="82.3%" headers="mcps1.2.3.1.2 "><p id="p1279144754611"><a name="p1279144754611"></a><a name="p1279144754611"></a>Header files of utils for the graphics subsystem</p>
</td>
</tr>
<tr id="row1534591617478"><td class="cellrowborder" valign="top" width="17.7%" headers="mcps1.2.3.1.1 "><p id="p43456161472"><a name="p43456161472"></a><a name="p43456161472"></a>services/ims</p>
</td>
<td class="cellrowborder" valign="top" width="82.3%" headers="mcps1.2.3.1.2 "><p id="p23451616124717"><a name="p23451616124717"></a><a name="p23451616124717"></a>Input event management, including processing and distributing input events such as click and press.</p>
</td>
</tr>
<tr id="row1044522874716"><td class="cellrowborder" valign="top" width="17.7%" headers="mcps1.2.3.1.1 "><p id="p644516283476"><a name="p644516283476"></a><a name="p644516283476"></a>services/wms</p>
</td>
<td class="cellrowborder" valign="top" width="82.3%" headers="mcps1.2.3.1.2 "><p id="p194451528144716"><a name="p194451528144716"></a><a name="p194451528144716"></a>Window management, including creating, managing, and combining windows.</p>
</td>
</tr>
<tr id="row48471930154713"><td class="cellrowborder" valign="top" width="17.7%" headers="mcps1.2.3.1.1 "><p id="p4847830134713"><a name="p4847830134713"></a><a name="p4847830134713"></a>utils</p>
</td>
<td class="cellrowborder" valign="top" width="82.3%" headers="mcps1.2.3.1.2 "><p id="p8847193074715"><a name="p8847193074715"></a><a name="p8847193074715"></a>Public library of the graphics subsystem</p>
</td>
</tr>
</tbody>
</table>

## Constraints<a name="section37625514114"></a>

-   Language version
    -   C++ 11 or later

-   The specifications of the application framework vary depending on the System-on-a-Chip \(SoC\) and underlying OS capabilities.
    -   Cortex-M RAM and ROM:
        -   RAM: greater than 100 KB \(recommended\)
        -   ROM: greater than 300 KB

    -   Cortex-A RAM/ROM:
        -   RAM: greater than 1 MB \(recommended\)
        -   ROM: greater than 1 MB



## Adding a UI Component<a name="section266451716115"></a>

All components inherit from the base class UIView and share common attributes and styles. UI components are classified into common and container ones. You can add child components for a container component, but not for a common component.

Store new header files in the  **interfaces/ui/components**  directory and .cpp files in the  **frameworks/ui/src/components**  directory. Override  **OnDraw**  function to draw this UI component. Add the new file to the  **frameworks/ui/BUILD.gn**  directory and it will be compiled to  **libui.so**  during building.

## Repositories Involved<a name="section78781240113620"></a>

graphic\_lite

