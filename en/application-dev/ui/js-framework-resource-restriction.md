# Resource Limitations and Access<a name="EN-US_TOPIC_0000001173164731"></a>

## Resource Qualifiers<a name="section197802036142011"></a>

The name of a resource qualifier consists of one or more qualifiers that represent the application scenarios or device characteristics, covering the screen density, and more. The qualifiers are separated using hyphens \(-\). When creating a qualifiers file under  **resources**, you need to understand the file naming conventions and the rules for matching qualifiers files and the device status.

## Naming Conventions for Resource Qualifiers<a name="section550585117202"></a>

-   Qualifiers are ordered in the following sequence: screen density. You can select one or multiple qualifiers to name your file based on your application scenarios and device characteristics, while following the preceding sequence. 
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
<tbody><tr id="row1890413245238"><td class="cellrowborder" valign="top" width="23.400000000000002%" headers="mcps1.2.3.1.1 "><p id="p2090532442315"><a name="p2090532442315"></a><a name="p2090532442315"></a>Screen density</p>
</td>
<td class="cellrowborder" valign="top" width="76.6%" headers="mcps1.2.3.1.2 "><p id="p2389144311231"><a name="p2389144311231"></a><a name="p2389144311231"></a>Indicates the screen density of the device, in dpi. The value can be:</p>
<a name="ul1311184562317"></a><a name="ul1311184562317"></a><ul id="ul1311184562317"><li><strong id="b199641873345"><a name="b199641873345"></a><a name="b199641873345"></a>ldpi</strong>: low-density screen (~120 dpi) (0.75 x Reference density)</li><li><strong id="b13727115783416"><a name="b13727115783416"></a><a name="b13727115783416"></a>mdpi</strong>: medium-density screen (~160 dpi) (reference density)</li><li><strong id="b4271212193512"><a name="b4271212193512"></a><a name="b4271212193512"></a>hdpi</strong>: high-density screen (~240 dpi) (1.5 x Reference density)</li><li><strong id="b2780515183515"><a name="b2780515183515"></a><a name="b2780515183515"></a>xhdpi</strong>: extra high-density screen (~320 dpi) (2.0 x Reference density)</li><li><strong id="b5206125518356"><a name="b5206125518356"></a><a name="b5206125518356"></a>xxhdpi</strong>: extra extra high-density screen (~480 dpi) (3.0 x Reference density)</li><li><strong id="b11485359103511"><a name="b11485359103511"></a><a name="b11485359103511"></a>xxxhdpi</strong>: extra extra extra high-density screen (~640 dpi) (4.0 x Reference density)</li></ul>
</td>
</tr>
</tbody>
</table>

## **Rules for Matching Qualifiers Files and Device Resources**<a name="section59927387241"></a>

-   Qualifiers are matched with the device resources in the following priorities: MCC and MNC \> screen orientation \> dark mode \> device type \> screen density. If no matching resource qualifier file is found, the default resource qualifier file is used.
-   If a qualifier file contains resource qualifiers, their values must be consistent with the current device status so that the file can be used for matching the device status. For example, the  **res-hdpi.json**  qualifier file does not match the device density  **xhdpi**.

## Referencing Resources in the JS Module<a name="section7516798256"></a>

You can use the $r syntax in the application development files  **.hml**  and  **.js**  to format the JSON resources in the  **resources**  directory of the JS module and obtain the corresponding resources.

<a name="table1595144416585"></a>
<table><thead align="left"><tr id="row1295119445588"><th class="cellrowborder" valign="top" width="11.41114111411141%" id="mcps1.1.4.1.1"><p id="p18951844195815"><a name="p18951844195815"></a><a name="p18951844195815"></a>Attribute</p>
</th>
<th class="cellrowborder" valign="top" width="23.17231723172317%" id="mcps1.1.4.1.2"><p id="p16951044135813"><a name="p16951044135813"></a><a name="p16951044135813"></a>Type</p>
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

>![](../public_sys-resources/icon-note.gif) **NOTE:** 
>The resource qualifier file does not support color enumeration.

