# Loading Images Based on DPI<a name="EN-US_TOPIC_0000001162414607"></a>

-   [Defining Resource Files](#en-us_topic_0000001059308530_section1412713919386)
-   [Referencing Resources](#en-us_topic_0000001059308530_section123352511389)

An application developed based on the JS UI framework may be applied to different devices. Due to different DPIs of devices, different image resources may need to be configured. This framework allows devices with different DPIs to load different image resources. You only need to perform  [Defining Resource Files](#en-us_topic_0000001059308530_section1412713919386)  and  [Referencing Resources](#en-us_topic_0000001059308530_section123352511389)  to use this function.

## Defining Resource Files<a name="en-us_topic_0000001059308530_section1412713919386"></a>

In the  **/resources**  directory described in  [File Organization](file-organization.md#EN-US_TOPIC_0000001115974720), you can define resource files for devices with different DPIs. JSON files are used to save resource definitions in the framework. For example, the resource file  **res-ldpi.json**  applies to a low-density \(ldpi\) screen \(-120 dpi\), and the resource file  **res-xxhdpi.json**  applies to an ultra-high-density \(xxhdpi\) screen \(-480 dpi\).

The reference density is 160 dpi, and the low density is 0.75 x 160 dpi. For details, see  [Table 1](#en-us_topic_0000001059308530_table114361825185814).

**Table  1**  Configuration qualifiers for different pixel densities

<a name="en-us_topic_0000001059308530_table114361825185814"></a>
<table><thead align="left"><tr id="en-us_topic_0000001059308530_row1143610257585"><th class="cellrowborder" valign="top" width="23.1%" id="mcps1.2.3.1.1"><p id="en-us_topic_0000001059308530_p11436202514580"><a name="en-us_topic_0000001059308530_p11436202514580"></a><a name="en-us_topic_0000001059308530_p11436202514580"></a>Density Qualifier</p>
</th>
<th class="cellrowborder" valign="top" width="76.9%" id="mcps1.2.3.1.2"><p id="en-us_topic_0000001059308530_p1143612252586"><a name="en-us_topic_0000001059308530_p1143612252586"></a><a name="en-us_topic_0000001059308530_p1143612252586"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="en-us_topic_0000001059308530_row2043612251587"><td class="cellrowborder" valign="top" width="23.1%" headers="mcps1.2.3.1.1 "><p id="en-us_topic_0000001059308530_p34361025125819"><a name="en-us_topic_0000001059308530_p34361025125819"></a><a name="en-us_topic_0000001059308530_p34361025125819"></a>ldpi</p>
</td>
<td class="cellrowborder" valign="top" width="76.9%" headers="mcps1.2.3.1.2 "><p id="en-us_topic_0000001059308530_p17436112516581"><a name="en-us_topic_0000001059308530_p17436112516581"></a><a name="en-us_topic_0000001059308530_p17436112516581"></a>Low-density screen (~120 dpi) (0.75 x 160 dpi)</p>
</td>
</tr>
<tr id="en-us_topic_0000001059308530_row1436625145814"><td class="cellrowborder" valign="top" width="23.1%" headers="mcps1.2.3.1.1 "><p id="en-us_topic_0000001059308530_p1436152545811"><a name="en-us_topic_0000001059308530_p1436152545811"></a><a name="en-us_topic_0000001059308530_p1436152545811"></a>mdpi</p>
</td>
<td class="cellrowborder" valign="top" width="76.9%" headers="mcps1.2.3.1.2 "><p id="en-us_topic_0000001059308530_p18436102516585"><a name="en-us_topic_0000001059308530_p18436102516585"></a><a name="en-us_topic_0000001059308530_p18436102516585"></a>Medium-density screen (~160 dpi) (reference density)</p>
</td>
</tr>
<tr id="en-us_topic_0000001059308530_row5436025105811"><td class="cellrowborder" valign="top" width="23.1%" headers="mcps1.2.3.1.1 "><p id="en-us_topic_0000001059308530_p134361125115816"><a name="en-us_topic_0000001059308530_p134361125115816"></a><a name="en-us_topic_0000001059308530_p134361125115816"></a>hdpi</p>
</td>
<td class="cellrowborder" valign="top" width="76.9%" headers="mcps1.2.3.1.2 "><p id="en-us_topic_0000001059308530_p6436132514585"><a name="en-us_topic_0000001059308530_p6436132514585"></a><a name="en-us_topic_0000001059308530_p6436132514585"></a>High-density screen (~240 dpi) (1.5 x 160 dpi)</p>
</td>
</tr>
<tr id="en-us_topic_0000001059308530_row1543692565815"><td class="cellrowborder" valign="top" width="23.1%" headers="mcps1.2.3.1.1 "><p id="en-us_topic_0000001059308530_p84361625205810"><a name="en-us_topic_0000001059308530_p84361625205810"></a><a name="en-us_topic_0000001059308530_p84361625205810"></a>xhdpi</p>
</td>
<td class="cellrowborder" valign="top" width="76.9%" headers="mcps1.2.3.1.2 "><p id="en-us_topic_0000001059308530_p94361925185813"><a name="en-us_topic_0000001059308530_p94361925185813"></a><a name="en-us_topic_0000001059308530_p94361925185813"></a>Extra high-density screen (~320 dpi) (2.0 x 160 dpi).</p>
</td>
</tr>
<tr id="en-us_topic_0000001059308530_row17436132515589"><td class="cellrowborder" valign="top" width="23.1%" headers="mcps1.2.3.1.1 "><p id="en-us_topic_0000001059308530_p144364251583"><a name="en-us_topic_0000001059308530_p144364251583"></a><a name="en-us_topic_0000001059308530_p144364251583"></a>xxhdpi</p>
</td>
<td class="cellrowborder" valign="top" width="76.9%" headers="mcps1.2.3.1.2 "><p id="en-us_topic_0000001059308530_p17436025115810"><a name="en-us_topic_0000001059308530_p17436025115810"></a><a name="en-us_topic_0000001059308530_p17436025115810"></a>Extra extra high-density screen (~480 dpi) (3.0 x 160 dpi)</p>
</td>
</tr>
<tr id="en-us_topic_0000001059308530_row1543632565813"><td class="cellrowborder" valign="top" width="23.1%" headers="mcps1.2.3.1.1 "><p id="en-us_topic_0000001059308530_p124371254586"><a name="en-us_topic_0000001059308530_p124371254586"></a><a name="en-us_topic_0000001059308530_p124371254586"></a>xxxhdpi</p>
</td>
<td class="cellrowborder" valign="top" width="76.9%" headers="mcps1.2.3.1.2 "><p id="en-us_topic_0000001059308530_p14437182535819"><a name="en-us_topic_0000001059308530_p14437182535819"></a><a name="en-us_topic_0000001059308530_p14437182535819"></a>Extra extra extra high-density screen (~640 dpi) (4.0 x 160 dpi)</p>
</td>
</tr>
</tbody>
</table>

The format of the resource file content is as follows:

```
{
    "image": {
        "wearable": "common/wearable.png",
        "computer": "image/computer.jpg"
     }
}
```

## Referencing Resources<a name="en-us_topic_0000001059308530_section123352511389"></a>

You can use the  **$r**  syntax in  **.hml**  and  **.js**  files to format image resources and obtain different image resources for different DPI devices.

**Table  2**  Resource formatting

<a name="en-us_topic_0000001059308530_table155672264241"></a>
<table><thead align="left"><tr id="en-us_topic_0000001059308530_row205671726192419"><th class="cellrowborder" valign="top" width="25%" id="mcps1.2.5.1.1"><p id="en-us_topic_0000001059308530_p7567626172419"><a name="en-us_topic_0000001059308530_p7567626172419"></a><a name="en-us_topic_0000001059308530_p7567626172419"></a>Attribute</p>
</th>
<th class="cellrowborder" valign="top" width="25%" id="mcps1.2.5.1.2"><p id="en-us_topic_0000001059308530_p65670263242"><a name="en-us_topic_0000001059308530_p65670263242"></a><a name="en-us_topic_0000001059308530_p65670263242"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="25%" id="mcps1.2.5.1.3"><p id="en-us_topic_0000001059308530_p15567162619248"><a name="en-us_topic_0000001059308530_p15567162619248"></a><a name="en-us_topic_0000001059308530_p15567162619248"></a>Parameter</p>
</th>
<th class="cellrowborder" valign="top" width="25%" id="mcps1.2.5.1.4"><p id="en-us_topic_0000001059308530_p5567026112416"><a name="en-us_topic_0000001059308530_p5567026112416"></a><a name="en-us_topic_0000001059308530_p5567026112416"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="en-us_topic_0000001059308530_row556702632419"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 "><p id="en-us_topic_0000001059308530_p13567526122410"><a name="en-us_topic_0000001059308530_p13567526122410"></a><a name="en-us_topic_0000001059308530_p13567526122410"></a>$r</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 "><p id="en-us_topic_0000001059308530_p1567102615246"><a name="en-us_topic_0000001059308530_p1567102615246"></a><a name="en-us_topic_0000001059308530_p1567102615246"></a>Function</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000001059308530_p5912182294910"><a name="en-us_topic_0000001059308530_p5912182294910"></a><a name="en-us_topic_0000001059308530_p5912182294910"></a>Path: string, representation of the resource file path</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.4 "><p id="en-us_topic_0000001059308530_p85672026192415"><a name="en-us_topic_0000001059308530_p85672026192415"></a><a name="en-us_topic_0000001059308530_p85672026192415"></a>Replaces the resource path based on the DPI of the current device: <strong id="en-us_topic_0000001059308530_b1520314243578"><a name="en-us_topic_0000001059308530_b1520314243578"></a><a name="en-us_topic_0000001059308530_b1520314243578"></a>this.$r('image.wearable')</strong></p>
</td>
</tr>
</tbody>
</table>

>![](public_sys-resources/icon-note.gif) **NOTE:** 
>If the DPI of the device does not completely match any DPI defined in  [Table 1](#en-us_topic_0000001059308530_table114361825185814), a resource file closer to the DPI of the device is selected. For example, if the current device density is 2.7 x 160 dpi, resources defined in  **res-xxhdpi.json**  are selected. You can define a  **res-defaults.json**  file that will be selected by your application if required resource strings do not exist in  **res-xxhdpi.json**. If the required resource strings are still not found in  **res-defaults.json**, the image fails to be loaded.

-   Sample code for resource formatting

    ```
    <!-- xxx.hml -->
    <div>
      <!-- Use $r to set the path of the image resource in the JSON file. -->
      <image src="{{ $r('image.wearable') }}" class="image"></image>
      <image src="{{ computer }}" class="image"></image>
    </div>
    ```

    ```
    // xxx.js
    // The following example shows how to use $r in a .js file.
    export default {
      private: {
        computer: '',
      },
      onInit() {
        // Format resources.
        this.computer = this.$r('image.computer');
      },    
    }
    ```


