# Overview<a name="EN-US_TOPIC_0000001116414108"></a>

-   [About the Document](#section189422248491)
-   [Restrictions](#section65191625782)
-   [DevEco Studio Evolution Roadmap](#section187875207166)

## About the Document<a name="section189422248491"></a>

DevEco Studio is an integrated development environment \(IDE\) of HarmonyOS apps. As HarmonyOS is developed based on OpenHarmony, DevEco Studio can also be used to develop OpenHarmony apps.

The process of developing an OpenHarmony app using DevEco Studio is the same as that of developing a HarmonyOS app. This document describes the differences between OpenHarmony and HarmonyOS app development.

-   **Environment setup**: You need to manually configure the SDK for the OpenHarmony app development. For details, see  [Configuring the OpenHarmony SDK](configuring-the-openharmony-sdk.md).
-   **Signature configuration for debugging**: To run an OpenHarmony app on a real device, you need to sign the app first. For instructions, see  [Configuring the OpenHarmony App Signature](configuring-the-openharmony-app-signature.md).
-   **App running on a real device**: To run your app on a real device, you need to use the hdc tool to push the HAP package of the OpenHarmony to the real device for installation. For details, see  [Installing and Running Your OpenHarmony App](installing-and-running-your-openharmony-app.md).

For details about how to use DevEco Studio, see  [HUAWEI DevEco Studio User Guide](https://developer.harmonyos.com/en/docs/documentation/doc-guides/tools_overview-0000001053582387).

## Restrictions<a name="section65191625782"></a>

-   OpenHarmony supports only app development in JS.
-   Developing OpenHarmony apps in DevEco Studio is supported on Windows.

DevEco Studio serves as a development tool for both OpenHarmony and HarmonyOS apps. Refer to the following table for descriptions about the IDE function differences between OpenHarmony and HarmonyOS.

<a name="table852516933419"></a>
<table><thead align="left"><tr id="row1952618913415"><th class="cellrowborder" valign="top" width="29.882988298829883%" id="mcps1.1.4.1.1"><p id="p165268963418"><a name="p165268963418"></a><a name="p165268963418"></a>Feature</p>
</th>
<th class="cellrowborder" valign="top" width="36.783678367836785%" id="mcps1.1.4.1.2"><p id="p25262914349"><a name="p25262914349"></a><a name="p25262914349"></a>HarmonyOS</p>
</th>
<th class="cellrowborder" valign="top" width="33.33333333333333%" id="mcps1.1.4.1.3"><p id="p125265912343"><a name="p125265912343"></a><a name="p125265912343"></a>OpenHarmony</p>
</th>
</tr>
</thead>
<tbody><tr id="row3627192183319"><td class="cellrowborder" valign="top" width="29.882988298829883%" headers="mcps1.1.4.1.1 "><p id="p1362817213320"><a name="p1362817213320"></a><a name="p1362817213320"></a>Creating modules</p>
</td>
<td class="cellrowborder" valign="top" width="36.783678367836785%" headers="mcps1.1.4.1.2 "><p id="p8226191353"><a name="p8226191353"></a><a name="p8226191353"></a><strong id="b17226139143511"><a name="b17226139143511"></a><a name="b17226139143511"></a>√</strong></p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.1.4.1.3 "><p id="p14226894353"><a name="p14226894353"></a><a name="p14226894353"></a><strong id="b122614963510"><a name="b122614963510"></a><a name="b122614963510"></a>X</strong></p>
</td>
</tr>
<tr id="row955132319355"><td class="cellrowborder" valign="top" width="29.882988298829883%" headers="mcps1.1.4.1.1 "><p id="p1655172423517"><a name="p1655172423517"></a><a name="p1655172423517"></a>Service widgets</p>
</td>
<td class="cellrowborder" valign="top" width="36.783678367836785%" headers="mcps1.1.4.1.2 "><p id="p1555192493516"><a name="p1555192493516"></a><a name="p1555192493516"></a><strong id="b11551102403511"><a name="b11551102403511"></a><a name="b11551102403511"></a>√</strong></p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.1.4.1.3 "><p id="p85511324183514"><a name="p85511324183514"></a><a name="p85511324183514"></a><strong id="b255116244356"><a name="b255116244356"></a><a name="b255116244356"></a>X</strong></p>
</td>
</tr>
<tr id="row1552619933411"><td class="cellrowborder" valign="top" width="29.882988298829883%" headers="mcps1.1.4.1.1 "><p id="p11430122863614"><a name="p11430122863614"></a><a name="p11430122863614"></a>Automatic signing</p>
</td>
<td class="cellrowborder" valign="top" width="36.783678367836785%" headers="mcps1.1.4.1.2 "><p id="p243122863614"><a name="p243122863614"></a><a name="p243122863614"></a><strong id="b14431122873617"><a name="b14431122873617"></a><a name="b14431122873617"></a>√</strong></p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.1.4.1.3 "><p id="p4431162819362"><a name="p4431162819362"></a><a name="p4431162819362"></a><strong id="b4431328163619"><a name="b4431328163619"></a><a name="b4431328163619"></a>X</strong></p>
</td>
</tr>
<tr id="row115263913344"><td class="cellrowborder" valign="top" width="29.882988298829883%" headers="mcps1.1.4.1.1 "><p id="p1323118352362"><a name="p1323118352362"></a><a name="p1323118352362"></a>Remote emulator</p>
</td>
<td class="cellrowborder" valign="top" width="36.783678367836785%" headers="mcps1.1.4.1.2 "><p id="p723143573614"><a name="p723143573614"></a><a name="p723143573614"></a><strong id="b8231173533613"><a name="b8231173533613"></a><a name="b8231173533613"></a>√</strong></p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.1.4.1.3 "><p id="p7231435143619"><a name="p7231435143619"></a><a name="p7231435143619"></a><strong id="b1523111352363"><a name="b1523111352363"></a><a name="b1523111352363"></a>X</strong></p>
</td>
</tr>
<tr id="row183441037105115"><td class="cellrowborder" valign="top" width="29.882988298829883%" headers="mcps1.1.4.1.1 "><p id="p5345237155119"><a name="p5345237155119"></a><a name="p5345237155119"></a>Local emulator</p>
</td>
<td class="cellrowborder" valign="top" width="36.783678367836785%" headers="mcps1.1.4.1.2 "><p id="p393214320517"><a name="p393214320517"></a><a name="p393214320517"></a><strong id="b1693264315118"><a name="b1693264315118"></a><a name="b1693264315118"></a>√</strong></p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.1.4.1.3 "><p id="p139324438515"><a name="p139324438515"></a><a name="p139324438515"></a><strong id="b169321543175116"><a name="b169321543175116"></a><a name="b169321543175116"></a>X</strong></p>
</td>
</tr>
<tr id="row15269933419"><td class="cellrowborder" valign="top" width="29.882988298829883%" headers="mcps1.1.4.1.1 "><p id="p152318351369"><a name="p152318351369"></a><a name="p152318351369"></a>Using DevEco Studio for debugging, log viewing, and optimization</p>
</td>
<td class="cellrowborder" valign="top" width="36.783678367836785%" headers="mcps1.1.4.1.2 "><p id="p623118353360"><a name="p623118353360"></a><a name="p623118353360"></a><strong id="b10231535143615"><a name="b10231535143615"></a><a name="b10231535143615"></a>√</strong></p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.1.4.1.3 "><p id="p192313353367"><a name="p192313353367"></a><a name="p192313353367"></a><strong id="b1423123514368"><a name="b1423123514368"></a><a name="b1423123514368"></a>X</strong></p>
</td>
</tr>
<tr id="row7357734143617"><td class="cellrowborder" valign="top" width="29.882988298829883%" headers="mcps1.1.4.1.1 "><p id="p76694468363"><a name="p76694468363"></a><a name="p76694468363"></a>Cloud testing</p>
</td>
<td class="cellrowborder" valign="top" width="36.783678367836785%" headers="mcps1.1.4.1.2 "><p id="p2066918465369"><a name="p2066918465369"></a><a name="p2066918465369"></a><strong id="b3669546133610"><a name="b3669546133610"></a><a name="b3669546133610"></a>√</strong></p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.1.4.1.3 "><p id="p1266910467363"><a name="p1266910467363"></a><a name="p1266910467363"></a><strong id="b11669144693616"><a name="b11669144693616"></a><a name="b11669144693616"></a>X</strong></p>
</td>
</tr>
<tr id="row124331939191517"><td class="cellrowborder" valign="top" width="29.882988298829883%" headers="mcps1.1.4.1.1 "><p id="p146691546143619"><a name="p146691546143619"></a><a name="p146691546143619"></a>Security testing</p>
</td>
<td class="cellrowborder" valign="top" width="36.783678367836785%" headers="mcps1.1.4.1.2 "><p id="p614815145371"><a name="p614815145371"></a><a name="p614815145371"></a><strong id="b101485149375"><a name="b101485149375"></a><a name="b101485149375"></a>√</strong></p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.1.4.1.3 "><p id="p1514811149374"><a name="p1514811149374"></a><a name="p1514811149374"></a><strong id="b01481614133717"><a name="b01481614133717"></a><a name="b01481614133717"></a>X</strong></p>
</td>
</tr>
</tbody>
</table>

## DevEco Studio Evolution Roadmap<a name="section187875207166"></a>

Refer to the following figure for when the HUAWEI DevEco Studio support for OpenHarmony app development is available in different phases.

![](figures/en-us_image_0000001163571565.png)

