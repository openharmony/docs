# Resource Limitations and Access<a name="EN-US_TOPIC_0000001173164731"></a>

>![](../../public_sys-resources/icon-note.gif) **NOTE:** 
>-   Screen density is supported since API version 4.
>-   Other qualifiers are supported since API version 6.

## Resource Qualifiers<a name="section197802036142011"></a>

The name of a resource qualifier consists of one or more qualifiers that represent the application scenarios or device characteristics, covering the screen density, and more. The qualifiers are separated using hyphens \(-\). When creating a qualifiers file under  **resources**, you need to understand the file naming conventions and the rules for matching qualifiers files and the device status.

## Naming Conventions for Resource Qualifiers<a name="section550585117202"></a>

-   Qualifiers are ordered in the following sequence: screen density. You can select one or multiple qualifiers to name your file based on your application scenarios and device characteristics, while following the preceding sequence. The MCC and MNC must exist at the same time.
-   The qualifiers are separated using hyphens \(-\), for example,  **res-dark-ldpi.json**.
-   Value range of qualifiers: The value of each qualifier must meet the requirements specified in the following table. Otherwise, the resource files in the  **resources**  directory cannot be matched. The qualifiers are case sensitive.
-   Qualifier prefix: The name of a qualifier file in the  **resources**  file has the prefix  **res**, for example,  **res-ldpi.json**.
-   Default resource qualifier file: By default, the resource qualifier file in  **resources**  is  **res-defaults.json**.
-   In the resource qualifier file, color enumeration cannot be used to set resources.

**Table  1**  Resource qualifiers

<a name="table153971631192110"></a>
<table><thead align="left"><tr id="row1397133152114"><th class="cellrowborder" valign="top" width="23.400000000000002%" id="mcps1.2.3.1.1"><p id="p7397331152114"><a name="p7397331152114"></a><a name="p7397331152114"></a>Data Type</p>
</th>
<th class="cellrowborder" valign="top" width="76.6%" id="mcps1.2.3.1.2"><p id="p1139719318218"><a name="p1139719318218"></a><a name="p1139719318218"></a>Description and Value Range</p>
</th>
</tr>
</thead>
<tbody><tr id="row23971331152113"><td class="cellrowborder" valign="top" width="23.400000000000002%" headers="mcps1.2.3.1.1 "><p id="p2039763152117"><a name="p2039763152117"></a><a name="p2039763152117"></a>MCC and MNC<sup id="sup7466692017"><a name="sup7466692017"></a><a name="sup7466692017"></a>6+</sup></p>
</td>
<td class="cellrowborder" valign="top" width="76.6%" headers="mcps1.2.3.1.2 "><p id="p639717316215"><a name="p639717316215"></a><a name="p639717316215"></a>Indicates the device MCC and SIM card MNC, for example, <strong id="b11630231320"><a name="b11630231320"></a><a name="b11630231320"></a>mcc460-mnc01</strong> and <strong id="b17690924113212"><a name="b17690924113212"></a><a name="b17690924113212"></a>mcc460-mnc02</strong>.</p>
</td>
</tr>
<tr id="row8397103116219"><td class="cellrowborder" valign="top" width="23.400000000000002%" headers="mcps1.2.3.1.1 "><p id="p839793118219"><a name="p839793118219"></a><a name="p839793118219"></a>Screen orientation<sup id="sup78689519016"><a name="sup78689519016"></a><a name="sup78689519016"></a>6+</sup></p>
</td>
<td class="cellrowborder" valign="top" width="76.6%" headers="mcps1.2.3.1.2 "><p id="p11696114442212"><a name="p11696114442212"></a><a name="p11696114442212"></a>Indicates the screen orientation of the device. The value can be:</p>
<a name="ul1315894982211"></a><a name="ul1315894982211"></a><ul id="ul1315894982211"><li><strong id="b188270309941914"><a name="b188270309941914"></a><a name="b188270309941914"></a>vertical</strong>: portrait orientation</li><li><strong id="b52137644541914"><a name="b52137644541914"></a><a name="b52137644541914"></a>horizontal</strong>: landscape orientation</li></ul>
</td>
</tr>
<tr id="row13397123192111"><td class="cellrowborder" valign="top" width="23.400000000000002%" headers="mcps1.2.3.1.1 "><p id="p9397931102115"><a name="p9397931102115"></a><a name="p9397931102115"></a>Device type<sup id="sup1333010908"><a name="sup1333010908"></a><a name="sup1333010908"></a>6+</sup></p>
</td>
<td class="cellrowborder" valign="top" width="76.6%" headers="mcps1.2.3.1.2 "><p id="p38048942312"><a name="p38048942312"></a><a name="p38048942312"></a>Indicates the device type. The value can be:</p>
<a name="ul13333911182311"></a><a name="ul13333911182311"></a><ul id="ul13333911182311"><li><strong id="b3391500441914"><a name="b3391500441914"></a><a name="b3391500441914"></a>phone</strong>: smartphone</li><li><strong id="b69101096941914"><a name="b69101096941914"></a><a name="b69101096941914"></a>tablet</strong>: tablet</li><li><strong id="b148897339141914"><a name="b148897339141914"></a><a name="b148897339141914"></a>tv</strong>: smart TV</li><li><strong id="b134224205041914"><a name="b134224205041914"></a><a name="b134224205041914"></a>wearable</strong>: wearable</li></ul>
</td>
</tr>
<tr id="row1890413245238"><td class="cellrowborder" valign="top" width="23.400000000000002%" headers="mcps1.2.3.1.1 "><p id="p2090532442315"><a name="p2090532442315"></a><a name="p2090532442315"></a>Screen density</p>
</td>
<td class="cellrowborder" valign="top" width="76.6%" headers="mcps1.2.3.1.2 "><p id="p2389144311231"><a name="p2389144311231"></a><a name="p2389144311231"></a>Indicates the screen density of the device, in dpi. The value can be:</p>
<a name="ul1311184562317"></a><a name="ul1311184562317"></a><ul id="ul1311184562317"><li><strong id="b199641873345"><a name="b199641873345"></a><a name="b199641873345"></a>ldpi</strong>: low-density screen (~120 dpi) (0.75 x Reference density)</li><li><strong id="b13727115783416"><a name="b13727115783416"></a><a name="b13727115783416"></a>mdpi</strong>: medium-density screen (~160 dpi) (reference density)</li><li><strong id="b4271212193512"><a name="b4271212193512"></a><a name="b4271212193512"></a>hdpi</strong>: high-density screen (~240 dpi) (1.5 x Reference density)</li><li><strong id="b2780515183515"><a name="b2780515183515"></a><a name="b2780515183515"></a>xhdpi</strong>: extra high-density screen (~320 dpi) (2.0 x Reference density)</li><li><strong id="b5206125518356"><a name="b5206125518356"></a><a name="b5206125518356"></a>xxhdpi</strong>: extra extra high-density screen (~480 dpi) (3.0 x Reference density)</li><li><strong id="b11485359103511"><a name="b11485359103511"></a><a name="b11485359103511"></a>xxxhdpi</strong>: extra extra extra high-density screen (~640 dpi) (4.0 x Reference density)</li></ul>
</td>
</tr>
</tbody>
</table>

## **Rules for Matching Qualifiers Files and Device Resources**<a name="section59927387241"></a>

-   Qualifiers are matched with the device resources in the following priorities: MCC and MNC \>screen orientation \> night mode \> device type \> screen density. If no matching resource qualifier file is found, the default resource qualifier file is used.
-   If a qualifier file contains resource qualifiers, their values must be consistent with the current device status so that the file can be used for matching the device status. For example, the  **res-hdpi.json**  qualifier file does not match the device density  **xhdpi**.

## Referencing Resources in the JS Module<a name="section7516798256"></a>

You can use the $r syntax in the application development files  **.hml**  and  **.js**  to format the JSON resources in the  **resources**  directory of the JS module and obtain the corresponding resources.

<a name="table1595144416585"></a>
<table><thead align="left"><tr id="row1295119445588"><th class="cellrowborder" valign="top" width="11.41114111411141%" id="mcps1.1.4.1.1"><p id="p18951844195815"><a name="p18951844195815"></a><a name="p18951844195815"></a>Attribute</p>
</th>
<th class="cellrowborder" valign="top" width="23.17231723172317%" id="mcps1.1.4.1.2"><p id="p16951044135813"><a name="p16951044135813"></a><a name="p16951044135813"></a>Data Type</p>
</th>
<th class="cellrowborder" valign="top" width="65.41654165416541%" id="mcps1.1.4.1.3"><p id="p1795154417586"><a name="p1795154417586"></a><a name="p1795154417586"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row8951164435812"><td class="cellrowborder" valign="top" width="11.41114111411141%" headers="mcps1.1.4.1.1 "><p id="p195124495814"><a name="p195124495814"></a><a name="p195124495814"></a>$r</p>
</td>
<td class="cellrowborder" valign="top" width="23.17231723172317%" headers="mcps1.1.4.1.2 "><p id="p3952164418589"><a name="p3952164418589"></a><a name="p3952164418589"></a>(key: string) =&gt; string</p>
</td>
<td class="cellrowborder" valign="top" width="65.41654165416541%" headers="mcps1.1.4.1.3 "><p id="p204636815564"><a name="p204636815564"></a><a name="p204636815564"></a>Obtains the resource content that matches the specific qualifiers, for example, <strong id="b2031311443445"><a name="b2031311443445"></a><a name="b2031311443445"></a>this.$r('strings.hello loaded)</strong>.</p>
<p id="p1146311815615"><a name="p1146311815615"></a><a name="p1146311815615"></a>Parameter description:</p>
<a name="ul18463178185617"></a><a name="ul18463178185617"></a><ul id="ul18463178185617"><li><strong id="b19598205334413"><a name="b19598205334413"></a><a name="b19598205334413"></a>key</strong>: key value defined in the resource qualifier file, for example, <strong id="b2956165194511"><a name="b2956165194511"></a><a name="b2956165194511"></a>strings.hello</strong>.</li></ul>
<p id="p174645835614"><a name="p174645835614"></a><a name="p174645835614"></a><strong id="b788814173455"><a name="b788814173455"></a><a name="b788814173455"></a>Example of res-defaults.json:</strong></p>
<pre class="screen" id="screen8464178165613"><a name="screen8464178165613"></a><a name="screen8464178165613"></a>{
    strings: {
        hello: 'hello world'
    }
}</pre>
</td>
</tr>
</tbody>
</table>

## Example<a name="section9710101017318"></a>

resources/res-dark.json:

```
{
    "image": {
        "clockFace": "common/dark_face.png"
    },
    "colors": {
	"background": "#000000"
    }
}
```

resources/res-defaults.json:

```
{
    "image": {
        "clockFace": "common/face.png"
    },
    "colors": {
	"background": "#ffffff"
    }
}
```

```
<!-- xxx.hml -->
<div style="background-color: {{ $r('colors.background') }}">
    <image src="{{ $r('image.clockFace') }}"></image>
</div>
```

>![](../../public_sys-resources/icon-note.gif) **NOTE:** 
>The resource qualifier file does not support color enumeration.

