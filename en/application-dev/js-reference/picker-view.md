# picker-view<a name="EN-US_TOPIC_0000001115814828"></a>

-   [Overview](#en-us_topic_0000001058988952_section48017573337)
-   [Child Component](#en-us_topic_0000001058988952_section54292411343)
-   [Attribute](#en-us_topic_0000001058988952_section121957126347)
-   [Event](#en-us_topic_0000001058988952_section18155133771112)
-   [Style](#en-us_topic_0000001058988952_section198061172344)
-   [Example Code](#en-us_topic_0000001058988952_section738534695417)

## Overview<a name="en-us_topic_0000001058988952_section48017573337"></a>

The  **<picker-view\>**  component provides the view that shows an embedded scrollable selector on the screen.

## Child Component<a name="en-us_topic_0000001058988952_section54292411343"></a>

Not supported

## Attribute<a name="en-us_topic_0000001058988952_section121957126347"></a>

<a name="en-us_topic_0000001058988952_table20633101642315"></a>
<table><thead align="left"><tr id="en-us_topic_0000001058988952_row663331618238"><th class="cellrowborder" valign="top" width="23.119999999999997%" id="mcps1.1.6.1.1"><p id="en-us_topic_0000001058988952_en-us_topic_0000001058340523_a9ba8c579217b4b8b841b035f1d28b20e"><a name="en-us_topic_0000001058988952_en-us_topic_0000001058340523_a9ba8c579217b4b8b841b035f1d28b20e"></a><a name="en-us_topic_0000001058988952_en-us_topic_0000001058340523_a9ba8c579217b4b8b841b035f1d28b20e"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="23.119999999999997%" id="mcps1.1.6.1.2"><p id="en-us_topic_0000001058988952_en-us_topic_0000001058340523_a633002333b024497914a4b172446f14e"><a name="en-us_topic_0000001058988952_en-us_topic_0000001058340523_a633002333b024497914a4b172446f14e"></a><a name="en-us_topic_0000001058988952_en-us_topic_0000001058340523_a633002333b024497914a4b172446f14e"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="10.48%" id="mcps1.1.6.1.3"><p id="en-us_topic_0000001058988952_en-us_topic_0000001058340523_a4950f7884c6540b9ad523ac34657d952"><a name="en-us_topic_0000001058988952_en-us_topic_0000001058340523_a4950f7884c6540b9ad523ac34657d952"></a><a name="en-us_topic_0000001058988952_en-us_topic_0000001058340523_a4950f7884c6540b9ad523ac34657d952"></a>Default Value</p>
</th>
<th class="cellrowborder" valign="top" width="7.5200000000000005%" id="mcps1.1.6.1.4"><p id="en-us_topic_0000001058988952_p824610360217"><a name="en-us_topic_0000001058988952_p824610360217"></a><a name="en-us_topic_0000001058988952_p824610360217"></a>Mandatory</p>
</th>
<th class="cellrowborder" valign="top" width="35.76%" id="mcps1.1.6.1.5"><p id="en-us_topic_0000001058988952_en-us_topic_0000001058340523_a1313564aa9404a338447087d5918c17d"><a name="en-us_topic_0000001058988952_en-us_topic_0000001058340523_a1313564aa9404a338447087d5918c17d"></a><a name="en-us_topic_0000001058988952_en-us_topic_0000001058340523_a1313564aa9404a338447087d5918c17d"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="en-us_topic_0000001058988952_row6290565914"><td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.1 "><p id="en-us_topic_0000001058988952_p136971571796"><a name="en-us_topic_0000001058988952_p136971571796"></a><a name="en-us_topic_0000001058988952_p136971571796"></a>type</p>
</td>
<td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.2 "><p id="en-us_topic_0000001058988952_p36971373918"><a name="en-us_topic_0000001058988952_p36971373918"></a><a name="en-us_topic_0000001058988952_p36971373918"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="10.48%" headers="mcps1.1.6.1.3 "><p id="en-us_topic_0000001058988952_p3697774912"><a name="en-us_topic_0000001058988952_p3697774912"></a><a name="en-us_topic_0000001058988952_p3697774912"></a>text</p>
</td>
<td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.6.1.4 "><p id="en-us_topic_0000001058988952_p12697377919"><a name="en-us_topic_0000001058988952_p12697377919"></a><a name="en-us_topic_0000001058988952_p12697377919"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="35.76%" headers="mcps1.1.6.1.5 "><p id="en-us_topic_0000001058988952_p126974719915"><a name="en-us_topic_0000001058988952_p126974719915"></a><a name="en-us_topic_0000001058988952_p126974719915"></a>Type of the scrollable selector, which cannot be changed dynamically. Available values are as follows:</p>
<a name="en-us_topic_0000001058988952_ul16977711916"></a><a name="en-us_topic_0000001058988952_ul16977711916"></a><ul id="en-us_topic_0000001058988952_ul16977711916"><li><strong id="en-us_topic_0000001058988952_b184817616590"><a name="en-us_topic_0000001058988952_b184817616590"></a><a name="en-us_topic_0000001058988952_b184817616590"></a>text</strong>: text selector</li><li><strong id="en-us_topic_0000001058988952_b116831455916"><a name="en-us_topic_0000001058988952_b116831455916"></a><a name="en-us_topic_0000001058988952_b116831455916"></a>time</strong>: time selector</li><li><strong id="en-us_topic_0000001058988952_b42691554144215"><a name="en-us_topic_0000001058988952_b42691554144215"></a><a name="en-us_topic_0000001058988952_b42691554144215"></a>date</strong>: date selector</li><li><strong id="en-us_topic_0000001058988952_b540355819423"><a name="en-us_topic_0000001058988952_b540355819423"></a><a name="en-us_topic_0000001058988952_b540355819423"></a>datetime</strong>: date and time selector</li><li><strong id="en-us_topic_0000001058988952_b222813410439"><a name="en-us_topic_0000001058988952_b222813410439"></a><a name="en-us_topic_0000001058988952_b222813410439"></a>multi-text</strong>: multi-column text selector</li></ul>
</td>
</tr>
<tr id="en-us_topic_0000001058988952_row36332165231"><td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.1 "><p id="en-us_topic_0000001058988952_en-us_topic_0000001058340523_adb8a73146d764f2aab50fc046169ab26"><a name="en-us_topic_0000001058988952_en-us_topic_0000001058340523_adb8a73146d764f2aab50fc046169ab26"></a><a name="en-us_topic_0000001058988952_en-us_topic_0000001058340523_adb8a73146d764f2aab50fc046169ab26"></a>id</p>
</td>
<td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.2 "><p id="en-us_topic_0000001058988952_en-us_topic_0000001058340523_a06898db2627246f78e85d4fbadeee85c"><a name="en-us_topic_0000001058988952_en-us_topic_0000001058340523_a06898db2627246f78e85d4fbadeee85c"></a><a name="en-us_topic_0000001058988952_en-us_topic_0000001058340523_a06898db2627246f78e85d4fbadeee85c"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="10.48%" headers="mcps1.1.6.1.3 "><p id="en-us_topic_0000001058988952_en-us_topic_0000001058340523_ae685ead324a647bcba1bbb45c9402dd6"><a name="en-us_topic_0000001058988952_en-us_topic_0000001058340523_ae685ead324a647bcba1bbb45c9402dd6"></a><a name="en-us_topic_0000001058988952_en-us_topic_0000001058340523_ae685ead324a647bcba1bbb45c9402dd6"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.6.1.4 "><p id="en-us_topic_0000001058988952_p42461736102118"><a name="en-us_topic_0000001058988952_p42461736102118"></a><a name="en-us_topic_0000001058988952_p42461736102118"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="35.76%" headers="mcps1.1.6.1.5 "><p id="en-us_topic_0000001058988952_en-us_topic_0000001058340523_a692121725a9b4ebbae65cd22b94b672e"><a name="en-us_topic_0000001058988952_en-us_topic_0000001058340523_a692121725a9b4ebbae65cd22b94b672e"></a><a name="en-us_topic_0000001058988952_en-us_topic_0000001058340523_a692121725a9b4ebbae65cd22b94b672e"></a>Unique ID of a component.</p>
</td>
</tr>
<tr id="en-us_topic_0000001058988952_row13633131616239"><td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.1 "><p id="en-us_topic_0000001058988952_en-us_topic_0000001058340523_a7c032d302e1d437eac59680e066308b0"><a name="en-us_topic_0000001058988952_en-us_topic_0000001058340523_a7c032d302e1d437eac59680e066308b0"></a><a name="en-us_topic_0000001058988952_en-us_topic_0000001058340523_a7c032d302e1d437eac59680e066308b0"></a>style</p>
</td>
<td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.2 "><p id="en-us_topic_0000001058988952_en-us_topic_0000001058340523_a6ba72f5c52df4fba9b02b5dffa26677e"><a name="en-us_topic_0000001058988952_en-us_topic_0000001058340523_a6ba72f5c52df4fba9b02b5dffa26677e"></a><a name="en-us_topic_0000001058988952_en-us_topic_0000001058340523_a6ba72f5c52df4fba9b02b5dffa26677e"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="10.48%" headers="mcps1.1.6.1.3 "><p id="en-us_topic_0000001058988952_en-us_topic_0000001058340523_a23cec1f95fd04ff1b3b20f58844ea654"><a name="en-us_topic_0000001058988952_en-us_topic_0000001058340523_a23cec1f95fd04ff1b3b20f58844ea654"></a><a name="en-us_topic_0000001058988952_en-us_topic_0000001058340523_a23cec1f95fd04ff1b3b20f58844ea654"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.6.1.4 "><p id="en-us_topic_0000001058988952_p17246836142119"><a name="en-us_topic_0000001058988952_p17246836142119"></a><a name="en-us_topic_0000001058988952_p17246836142119"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="35.76%" headers="mcps1.1.6.1.5 "><p id="en-us_topic_0000001058988952_en-us_topic_0000001058340523_ab9c92d331da44a0e9114f6760340680a"><a name="en-us_topic_0000001058988952_en-us_topic_0000001058340523_ab9c92d331da44a0e9114f6760340680a"></a><a name="en-us_topic_0000001058988952_en-us_topic_0000001058340523_ab9c92d331da44a0e9114f6760340680a"></a>Style declaration of a component.</p>
</td>
</tr>
<tr id="en-us_topic_0000001058988952_row10634131610230"><td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.1 "><p id="en-us_topic_0000001058988952_en-us_topic_0000001058340523_a3e97d6d2a5b84e06bf619049840a00a8"><a name="en-us_topic_0000001058988952_en-us_topic_0000001058340523_a3e97d6d2a5b84e06bf619049840a00a8"></a><a name="en-us_topic_0000001058988952_en-us_topic_0000001058340523_a3e97d6d2a5b84e06bf619049840a00a8"></a>class</p>
</td>
<td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.2 "><p id="en-us_topic_0000001058988952_en-us_topic_0000001058340523_af0974175e9434735b035a4db9146aa04"><a name="en-us_topic_0000001058988952_en-us_topic_0000001058340523_af0974175e9434735b035a4db9146aa04"></a><a name="en-us_topic_0000001058988952_en-us_topic_0000001058340523_af0974175e9434735b035a4db9146aa04"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="10.48%" headers="mcps1.1.6.1.3 "><p id="en-us_topic_0000001058988952_en-us_topic_0000001058340523_aa5caace6225b440eba13dc2230f3ef0f"><a name="en-us_topic_0000001058988952_en-us_topic_0000001058340523_aa5caace6225b440eba13dc2230f3ef0f"></a><a name="en-us_topic_0000001058988952_en-us_topic_0000001058340523_aa5caace6225b440eba13dc2230f3ef0f"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.6.1.4 "><p id="en-us_topic_0000001058988952_p324614367213"><a name="en-us_topic_0000001058988952_p324614367213"></a><a name="en-us_topic_0000001058988952_p324614367213"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="35.76%" headers="mcps1.1.6.1.5 "><p id="en-us_topic_0000001058988952_en-us_topic_0000001058340523_a2f6321cf45ae481983a88dcc2f900900"><a name="en-us_topic_0000001058988952_en-us_topic_0000001058340523_a2f6321cf45ae481983a88dcc2f900900"></a><a name="en-us_topic_0000001058988952_en-us_topic_0000001058340523_a2f6321cf45ae481983a88dcc2f900900"></a>Style class of a component, which is used to refer to a style table.</p>
</td>
</tr>
<tr id="en-us_topic_0000001058988952_row1634171618236"><td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.1 "><p id="en-us_topic_0000001058988952_en-us_topic_0000001058340523_p1786251117156"><a name="en-us_topic_0000001058988952_en-us_topic_0000001058340523_p1786251117156"></a><a name="en-us_topic_0000001058988952_en-us_topic_0000001058340523_p1786251117156"></a>ref</p>
</td>
<td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.2 "><p id="en-us_topic_0000001058988952_en-us_topic_0000001058340523_p1086241119157"><a name="en-us_topic_0000001058988952_en-us_topic_0000001058340523_p1086241119157"></a><a name="en-us_topic_0000001058988952_en-us_topic_0000001058340523_p1086241119157"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="10.48%" headers="mcps1.1.6.1.3 "><p id="en-us_topic_0000001058988952_en-us_topic_0000001058340523_p586281111151"><a name="en-us_topic_0000001058988952_en-us_topic_0000001058340523_p586281111151"></a><a name="en-us_topic_0000001058988952_en-us_topic_0000001058340523_p586281111151"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.6.1.4 "><p id="en-us_topic_0000001058988952_p1624612362219"><a name="en-us_topic_0000001058988952_p1624612362219"></a><a name="en-us_topic_0000001058988952_p1624612362219"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="35.76%" headers="mcps1.1.6.1.5 "><p id="en-us_topic_0000001058988952_en-us_topic_0000001058340523_p113416153342"><a name="en-us_topic_0000001058988952_en-us_topic_0000001058340523_p113416153342"></a><a name="en-us_topic_0000001058988952_en-us_topic_0000001058340523_p113416153342"></a>Used to register reference information of child elements<span id="en-us_topic_0000001058988952_en-us_topic_0000001058340523_ph5815920163518"><a name="en-us_topic_0000001058988952_en-us_topic_0000001058340523_ph5815920163518"></a><a name="en-us_topic_0000001058988952_en-us_topic_0000001058340523_ph5815920163518"></a> or child components</span>. The reference information is registered with the parent component on <strong id="en-us_topic_0000001058988952_en-us_topic_0000001058340523_b08212202354"><a name="en-us_topic_0000001058988952_en-us_topic_0000001058340523_b08212202354"></a><a name="en-us_topic_0000001058988952_en-us_topic_0000001058340523_b08212202354"></a>$refs</strong>.</p>
</td>
</tr>
<tr id="en-us_topic_0000001058988952_row1863421642313"><td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.1 "><p id="en-us_topic_0000001058988952_en-us_topic_0000001058340523_ab8d3c8007e0a42b9962e0db009e7be9d"><a name="en-us_topic_0000001058988952_en-us_topic_0000001058340523_ab8d3c8007e0a42b9962e0db009e7be9d"></a><a name="en-us_topic_0000001058988952_en-us_topic_0000001058340523_ab8d3c8007e0a42b9962e0db009e7be9d"></a>disabled</p>
</td>
<td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.2 "><p id="en-us_topic_0000001058988952_en-us_topic_0000001058340523_a05782d6a1a5d42918bc95813dca610d6"><a name="en-us_topic_0000001058988952_en-us_topic_0000001058340523_a05782d6a1a5d42918bc95813dca610d6"></a><a name="en-us_topic_0000001058988952_en-us_topic_0000001058340523_a05782d6a1a5d42918bc95813dca610d6"></a>boolean</p>
</td>
<td class="cellrowborder" valign="top" width="10.48%" headers="mcps1.1.6.1.3 "><p id="en-us_topic_0000001058988952_en-us_topic_0000001058340523_a3e2f721f63a74e4b974e9bd5e2f88994"><a name="en-us_topic_0000001058988952_en-us_topic_0000001058340523_a3e2f721f63a74e4b974e9bd5e2f88994"></a><a name="en-us_topic_0000001058988952_en-us_topic_0000001058340523_a3e2f721f63a74e4b974e9bd5e2f88994"></a>false</p>
</td>
<td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.6.1.4 "><p id="en-us_topic_0000001058988952_p192476368214"><a name="en-us_topic_0000001058988952_p192476368214"></a><a name="en-us_topic_0000001058988952_p192476368214"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="35.76%" headers="mcps1.1.6.1.5 "><p id="en-us_topic_0000001058988952_en-us_topic_0000001058340523_a4065980a1e914cf98acce5250ee4ae5a"><a name="en-us_topic_0000001058988952_en-us_topic_0000001058340523_a4065980a1e914cf98acce5250ee4ae5a"></a><a name="en-us_topic_0000001058988952_en-us_topic_0000001058340523_a4065980a1e914cf98acce5250ee4ae5a"></a>Whether a component is disabled. If it is disabled, it cannot respond to user interaction.</p>
</td>
</tr>
<tr id="en-us_topic_0000001058988952_row1263451617236"><td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.1 "><p id="en-us_topic_0000001058988952_en-us_topic_0000001058340523_a751c9d46a62348ec902c7fdf97468b9d"><a name="en-us_topic_0000001058988952_en-us_topic_0000001058340523_a751c9d46a62348ec902c7fdf97468b9d"></a><a name="en-us_topic_0000001058988952_en-us_topic_0000001058340523_a751c9d46a62348ec902c7fdf97468b9d"></a>data</p>
</td>
<td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.2 "><p id="en-us_topic_0000001058988952_en-us_topic_0000001058340523_a8e6d1bb4d0bc423fb8466ee3acd1882f"><a name="en-us_topic_0000001058988952_en-us_topic_0000001058340523_a8e6d1bb4d0bc423fb8466ee3acd1882f"></a><a name="en-us_topic_0000001058988952_en-us_topic_0000001058340523_a8e6d1bb4d0bc423fb8466ee3acd1882f"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="10.48%" headers="mcps1.1.6.1.3 "><p id="en-us_topic_0000001058988952_en-us_topic_0000001058340523_ab8cb15c9c3444b13b64945788131dce6"><a name="en-us_topic_0000001058988952_en-us_topic_0000001058340523_ab8cb15c9c3444b13b64945788131dce6"></a><a name="en-us_topic_0000001058988952_en-us_topic_0000001058340523_ab8cb15c9c3444b13b64945788131dce6"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.6.1.4 "><p id="en-us_topic_0000001058988952_p22471736132114"><a name="en-us_topic_0000001058988952_p22471736132114"></a><a name="en-us_topic_0000001058988952_p22471736132114"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="35.76%" headers="mcps1.1.6.1.5 "><p id="en-us_topic_0000001058988952_en-us_topic_0000001058340523_aa3f56a32296b4e85bcda2d2c00d0884f"><a name="en-us_topic_0000001058988952_en-us_topic_0000001058340523_aa3f56a32296b4e85bcda2d2c00d0884f"></a><a name="en-us_topic_0000001058988952_en-us_topic_0000001058340523_aa3f56a32296b4e85bcda2d2c00d0884f"></a>Attribute set for a component to facilitate data storage and reading.</p>
</td>
</tr>
</tbody>
</table>

Text selector \(**type**  is  **text**\)

<a name="en-us_topic_0000001058988952_ta708bd4856a044b79bae50a2ce6981b8"></a>
<table><thead align="left"><tr id="en-us_topic_0000001058988952_re08662644cee4140ad0d5bac7978cd9b"><th class="cellrowborder" valign="top" width="24.007599240075994%" id="mcps1.1.6.1.1"><p id="en-us_topic_0000001058988952_af5b093e471ec47119f04bf2fe91b6f64"><a name="en-us_topic_0000001058988952_af5b093e471ec47119f04bf2fe91b6f64"></a><a name="en-us_topic_0000001058988952_af5b093e471ec47119f04bf2fe91b6f64"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="10.808919108089192%" id="mcps1.1.6.1.2"><p id="en-us_topic_0000001058988952_a8c2c2f6a645749b7852ec7dcadaca702"><a name="en-us_topic_0000001058988952_a8c2c2f6a645749b7852ec7dcadaca702"></a><a name="en-us_topic_0000001058988952_a8c2c2f6a645749b7852ec7dcadaca702"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="8.62913708629137%" id="mcps1.1.6.1.3"><p id="en-us_topic_0000001058988952_aa63c3dd750aa44fb9ec9031e632f4f5f"><a name="en-us_topic_0000001058988952_aa63c3dd750aa44fb9ec9031e632f4f5f"></a><a name="en-us_topic_0000001058988952_aa63c3dd750aa44fb9ec9031e632f4f5f"></a>Default Value</p>
</th>
<th class="cellrowborder" valign="top" width="7.14928507149285%" id="mcps1.1.6.1.4"><p id="en-us_topic_0000001058988952_aee9661e3366543aeac6aa37e48de4c87"><a name="en-us_topic_0000001058988952_aee9661e3366543aeac6aa37e48de4c87"></a><a name="en-us_topic_0000001058988952_aee9661e3366543aeac6aa37e48de4c87"></a>Mandatory</p>
</th>
<th class="cellrowborder" valign="top" width="49.4050594940506%" id="mcps1.1.6.1.5"><p id="en-us_topic_0000001058988952_a2dc04c78fce4402d9dead84ab8412bb3"><a name="en-us_topic_0000001058988952_a2dc04c78fce4402d9dead84ab8412bb3"></a><a name="en-us_topic_0000001058988952_a2dc04c78fce4402d9dead84ab8412bb3"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="en-us_topic_0000001058988952_re8122915226c4596b2bffeae21e37b10"><td class="cellrowborder" valign="top" width="24.007599240075994%" headers="mcps1.1.6.1.1 "><p id="en-us_topic_0000001058988952_p64901432865"><a name="en-us_topic_0000001058988952_p64901432865"></a><a name="en-us_topic_0000001058988952_p64901432865"></a>range</p>
</td>
<td class="cellrowborder" valign="top" width="10.808919108089192%" headers="mcps1.1.6.1.2 "><p id="en-us_topic_0000001058988952_p194901326610"><a name="en-us_topic_0000001058988952_p194901326610"></a><a name="en-us_topic_0000001058988952_p194901326610"></a>Array</p>
</td>
<td class="cellrowborder" valign="top" width="8.62913708629137%" headers="mcps1.1.6.1.3 "><p id="en-us_topic_0000001058988952_p16490183216616"><a name="en-us_topic_0000001058988952_p16490183216616"></a><a name="en-us_topic_0000001058988952_p16490183216616"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.14928507149285%" headers="mcps1.1.6.1.4 "><p id="en-us_topic_0000001058988952_p12490132765"><a name="en-us_topic_0000001058988952_p12490132765"></a><a name="en-us_topic_0000001058988952_p12490132765"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="49.4050594940506%" headers="mcps1.1.6.1.5 "><p id="en-us_topic_0000001058988952_p879110395507"><a name="en-us_topic_0000001058988952_p879110395507"></a><a name="en-us_topic_0000001058988952_p879110395507"></a>Value range of the text selector.</p>
<div class="note" id="en-us_topic_0000001058988952_note195791919121"><a name="en-us_topic_0000001058988952_note195791919121"></a><a name="en-us_topic_0000001058988952_note195791919121"></a><span class="notetitle"> NOTE: </span><div class="notebody"><p id="en-us_topic_0000001058988952_p11957191913124"><a name="en-us_topic_0000001058988952_p11957191913124"></a><a name="en-us_topic_0000001058988952_p11957191913124"></a>Use the data binding mode, for example, range = {{data}}. Declare the corresponding variable <strong id="en-us_topic_0000001058988952_b1056351631112"><a name="en-us_topic_0000001058988952_b1056351631112"></a><a name="en-us_topic_0000001058988952_b1056351631112"></a>data: ["15", "20", "25"]</strong> in the JavaScript.</p>
</div></div>
</td>
</tr>
<tr id="en-us_topic_0000001058988952_row2068183074711"><td class="cellrowborder" valign="top" width="24.007599240075994%" headers="mcps1.1.6.1.1 "><p id="en-us_topic_0000001058988952_p54902321765"><a name="en-us_topic_0000001058988952_p54902321765"></a><a name="en-us_topic_0000001058988952_p54902321765"></a>selected</p>
</td>
<td class="cellrowborder" valign="top" width="10.808919108089192%" headers="mcps1.1.6.1.2 "><p id="en-us_topic_0000001058988952_p24901321469"><a name="en-us_topic_0000001058988952_p24901321469"></a><a name="en-us_topic_0000001058988952_p24901321469"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="8.62913708629137%" headers="mcps1.1.6.1.3 "><p id="en-us_topic_0000001058988952_p14901932863"><a name="en-us_topic_0000001058988952_p14901932863"></a><a name="en-us_topic_0000001058988952_p14901932863"></a>0</p>
</td>
<td class="cellrowborder" valign="top" width="7.14928507149285%" headers="mcps1.1.6.1.4 "><p id="en-us_topic_0000001058988952_p1049018321869"><a name="en-us_topic_0000001058988952_p1049018321869"></a><a name="en-us_topic_0000001058988952_p1049018321869"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="49.4050594940506%" headers="mcps1.1.6.1.5 "><p id="en-us_topic_0000001058988952_p649017329613"><a name="en-us_topic_0000001058988952_p649017329613"></a><a name="en-us_topic_0000001058988952_p649017329613"></a>Default value of the text selector. The value is the index of <strong id="en-us_topic_0000001058988952_b121361525737"><a name="en-us_topic_0000001058988952_b121361525737"></a><a name="en-us_topic_0000001058988952_b121361525737"></a>range</strong>.</p>
</td>
</tr>
<tr id="en-us_topic_0000001058988952_row1045119531711"><td class="cellrowborder" valign="top" width="24.007599240075994%" headers="mcps1.1.6.1.1 "><p id="en-us_topic_0000001058988952_p54526530112"><a name="en-us_topic_0000001058988952_p54526530112"></a><a name="en-us_topic_0000001058988952_p54526530112"></a>indicatorprefix</p>
</td>
<td class="cellrowborder" valign="top" width="10.808919108089192%" headers="mcps1.1.6.1.2 "><p id="en-us_topic_0000001058988952_p24521553119"><a name="en-us_topic_0000001058988952_p24521553119"></a><a name="en-us_topic_0000001058988952_p24521553119"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="8.62913708629137%" headers="mcps1.1.6.1.3 "><p id="en-us_topic_0000001058988952_p14524531315"><a name="en-us_topic_0000001058988952_p14524531315"></a><a name="en-us_topic_0000001058988952_p14524531315"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.14928507149285%" headers="mcps1.1.6.1.4 "><p id="en-us_topic_0000001058988952_p134526535117"><a name="en-us_topic_0000001058988952_p134526535117"></a><a name="en-us_topic_0000001058988952_p134526535117"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="49.4050594940506%" headers="mcps1.1.6.1.5 "><p id="en-us_topic_0000001058988952_p114526534115"><a name="en-us_topic_0000001058988952_p114526534115"></a><a name="en-us_topic_0000001058988952_p114526534115"></a>Prefix field added when a value is specified for the text selector.</p>
</td>
</tr>
<tr id="en-us_topic_0000001058988952_row115191458171210"><td class="cellrowborder" valign="top" width="24.007599240075994%" headers="mcps1.1.6.1.1 "><p id="en-us_topic_0000001058988952_p2052015584123"><a name="en-us_topic_0000001058988952_p2052015584123"></a><a name="en-us_topic_0000001058988952_p2052015584123"></a>indicatorsuffix</p>
</td>
<td class="cellrowborder" valign="top" width="10.808919108089192%" headers="mcps1.1.6.1.2 "><p id="en-us_topic_0000001058988952_p0520458141213"><a name="en-us_topic_0000001058988952_p0520458141213"></a><a name="en-us_topic_0000001058988952_p0520458141213"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="8.62913708629137%" headers="mcps1.1.6.1.3 "><p id="en-us_topic_0000001058988952_p25201358191214"><a name="en-us_topic_0000001058988952_p25201358191214"></a><a name="en-us_topic_0000001058988952_p25201358191214"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.14928507149285%" headers="mcps1.1.6.1.4 "><p id="en-us_topic_0000001058988952_p952085813124"><a name="en-us_topic_0000001058988952_p952085813124"></a><a name="en-us_topic_0000001058988952_p952085813124"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="49.4050594940506%" headers="mcps1.1.6.1.5 "><p id="en-us_topic_0000001058988952_p175201958121212"><a name="en-us_topic_0000001058988952_p175201958121212"></a><a name="en-us_topic_0000001058988952_p175201958121212"></a>Suffix field added when a value is specified for the text selector.</p>
</td>
</tr>
</tbody>
</table>

Time selector \(**type**  is  **time**\)

<a name="en-us_topic_0000001058988952_table89366820719"></a>
<table><thead align="left"><tr id="en-us_topic_0000001058988952_row49367819714"><th class="cellrowborder" valign="top" width="24.000000000000004%" id="mcps1.1.6.1.1"><p id="en-us_topic_0000001058988952_p1493614815715"><a name="en-us_topic_0000001058988952_p1493614815715"></a><a name="en-us_topic_0000001058988952_p1493614815715"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="10.810000000000002%" id="mcps1.1.6.1.2"><p id="en-us_topic_0000001058988952_p2936881677"><a name="en-us_topic_0000001058988952_p2936881677"></a><a name="en-us_topic_0000001058988952_p2936881677"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="8.63%" id="mcps1.1.6.1.3"><p id="en-us_topic_0000001058988952_p79362815719"><a name="en-us_topic_0000001058988952_p79362815719"></a><a name="en-us_topic_0000001058988952_p79362815719"></a>Default Value</p>
</th>
<th class="cellrowborder" valign="top" width="7.15%" id="mcps1.1.6.1.4"><p id="en-us_topic_0000001058988952_p12936584719"><a name="en-us_topic_0000001058988952_p12936584719"></a><a name="en-us_topic_0000001058988952_p12936584719"></a>Mandatory</p>
</th>
<th class="cellrowborder" valign="top" width="49.410000000000004%" id="mcps1.1.6.1.5"><p id="en-us_topic_0000001058988952_p15936198876"><a name="en-us_topic_0000001058988952_p15936198876"></a><a name="en-us_topic_0000001058988952_p15936198876"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="en-us_topic_0000001058988952_row2937108277"><td class="cellrowborder" valign="top" width="24.000000000000004%" headers="mcps1.1.6.1.1 "><p id="en-us_topic_0000001058988952_p077212191171"><a name="en-us_topic_0000001058988952_p077212191171"></a><a name="en-us_topic_0000001058988952_p077212191171"></a>containsecond</p>
</td>
<td class="cellrowborder" valign="top" width="10.810000000000002%" headers="mcps1.1.6.1.2 "><p id="en-us_topic_0000001058988952_p1177214198714"><a name="en-us_topic_0000001058988952_p1177214198714"></a><a name="en-us_topic_0000001058988952_p1177214198714"></a>boolean</p>
</td>
<td class="cellrowborder" valign="top" width="8.63%" headers="mcps1.1.6.1.3 "><p id="en-us_topic_0000001058988952_p87721619275"><a name="en-us_topic_0000001058988952_p87721619275"></a><a name="en-us_topic_0000001058988952_p87721619275"></a>false</p>
</td>
<td class="cellrowborder" valign="top" width="7.15%" headers="mcps1.1.6.1.4 "><p id="en-us_topic_0000001058988952_p127721919372"><a name="en-us_topic_0000001058988952_p127721919372"></a><a name="en-us_topic_0000001058988952_p127721919372"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="49.410000000000004%" headers="mcps1.1.6.1.5 "><p id="en-us_topic_0000001058988952_p13773101919719"><a name="en-us_topic_0000001058988952_p13773101919719"></a><a name="en-us_topic_0000001058988952_p13773101919719"></a>Whether seconds are contained.</p>
</td>
</tr>
<tr id="en-us_topic_0000001058988952_row1293719814712"><td class="cellrowborder" valign="top" width="24.000000000000004%" headers="mcps1.1.6.1.1 "><p id="en-us_topic_0000001058988952_p577314191171"><a name="en-us_topic_0000001058988952_p577314191171"></a><a name="en-us_topic_0000001058988952_p577314191171"></a>selected</p>
</td>
<td class="cellrowborder" valign="top" width="10.810000000000002%" headers="mcps1.1.6.1.2 "><p id="en-us_topic_0000001058988952_p177735196711"><a name="en-us_topic_0000001058988952_p177735196711"></a><a name="en-us_topic_0000001058988952_p177735196711"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="8.63%" headers="mcps1.1.6.1.3 "><p id="en-us_topic_0000001058988952_p127734191714"><a name="en-us_topic_0000001058988952_p127734191714"></a><a name="en-us_topic_0000001058988952_p127734191714"></a><span id="en-us_topic_0000001058988952_ph61411732205214"><a name="en-us_topic_0000001058988952_ph61411732205214"></a><a name="en-us_topic_0000001058988952_ph61411732205214"></a>Current time</span></p>
</td>
<td class="cellrowborder" valign="top" width="7.15%" headers="mcps1.1.6.1.4 "><p id="en-us_topic_0000001058988952_p16773151914716"><a name="en-us_topic_0000001058988952_p16773151914716"></a><a name="en-us_topic_0000001058988952_p16773151914716"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="49.410000000000004%" headers="mcps1.1.6.1.5 "><p id="en-us_topic_0000001058988952_p5241145091814"><a name="en-us_topic_0000001058988952_p5241145091814"></a><a name="en-us_topic_0000001058988952_p5241145091814"></a>Default value of the time selector, in the format of HH:mm.</p>
<p id="en-us_topic_0000001058988952_p57739191974"><a name="en-us_topic_0000001058988952_p57739191974"></a><a name="en-us_topic_0000001058988952_p57739191974"></a>If seconds are contained, the format is HH:mm:ss.</p>
</td>
</tr>
<tr id="en-us_topic_0000001058988952_row3976191332214"><td class="cellrowborder" valign="top" width="24.000000000000004%" headers="mcps1.1.6.1.1 "><p id="en-us_topic_0000001058988952_p095363112111"><a name="en-us_topic_0000001058988952_p095363112111"></a><a name="en-us_topic_0000001058988952_p095363112111"></a>hours</p>
</td>
<td class="cellrowborder" valign="top" width="10.810000000000002%" headers="mcps1.1.6.1.2 "><p id="en-us_topic_0000001058988952_p6953193114218"><a name="en-us_topic_0000001058988952_p6953193114218"></a><a name="en-us_topic_0000001058988952_p6953193114218"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="8.63%" headers="mcps1.1.6.1.3 "><p id="en-us_topic_0000001058988952_p81051142202817"><a name="en-us_topic_0000001058988952_p81051142202817"></a><a name="en-us_topic_0000001058988952_p81051142202817"></a>-<sup id="en-us_topic_0000001058988952_sup14229658122718"><a name="en-us_topic_0000001058988952_sup14229658122718"></a><a name="en-us_topic_0000001058988952_sup14229658122718"></a>5+</sup></p>
</td>
<td class="cellrowborder" valign="top" width="7.15%" headers="mcps1.1.6.1.4 "><p id="en-us_topic_0000001058988952_p0953193112117"><a name="en-us_topic_0000001058988952_p0953193112117"></a><a name="en-us_topic_0000001058988952_p0953193112117"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="49.410000000000004%" headers="mcps1.1.6.1.5 "><p id="en-us_topic_0000001058988952_p1095393116216"><a name="en-us_topic_0000001058988952_p1095393116216"></a><a name="en-us_topic_0000001058988952_p1095393116216"></a>Time format used by the time selector. Available values include:</p>
<a name="en-us_topic_0000001058988952_ul11382144442112"></a><a name="en-us_topic_0000001058988952_ul11382144442112"></a><ul id="en-us_topic_0000001058988952_ul11382144442112"><li><strong id="en-us_topic_0000001058988952_b793617752019"><a name="en-us_topic_0000001058988952_b793617752019"></a><a name="en-us_topic_0000001058988952_b793617752019"></a>12</strong>: displayed in 12-hour format and distinguished by a.m. and p.m.</li><li><strong id="en-us_topic_0000001058988952_b273115197214"><a name="en-us_topic_0000001058988952_b273115197214"></a><a name="en-us_topic_0000001058988952_b273115197214"></a>24</strong>: displayed in 24-hour format<div class="note" id="en-us_topic_0000001058988952_note189471313104"><a name="en-us_topic_0000001058988952_note189471313104"></a><a name="en-us_topic_0000001058988952_note189471313104"></a><span class="notetitle"> NOTE: </span><div class="notebody"><p id="en-us_topic_0000001058988952_p9947193114104"><a name="en-us_topic_0000001058988952_p9947193114104"></a><a name="en-us_topic_0000001058988952_p9947193114104"></a>The default value is the most commonly-used hour format in the current locale. <sup id="en-us_topic_0000001058988952_sup319942110314"><a name="en-us_topic_0000001058988952_sup319942110314"></a><a name="en-us_topic_0000001058988952_sup319942110314"></a>5+</sup></p>
</div></div>
</li></ul>
</td>
</tr>
</tbody>
</table>

Date selector \(**type**  is  **date**\)

<a name="en-us_topic_0000001058988952_table174784493618"></a>
<table><thead align="left"><tr id="en-us_topic_0000001058988952_row54789491561"><th class="cellrowborder" valign="top" width="24.000000000000004%" id="mcps1.1.6.1.1"><p id="en-us_topic_0000001058988952_p14781849561"><a name="en-us_topic_0000001058988952_p14781849561"></a><a name="en-us_topic_0000001058988952_p14781849561"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="10.810000000000002%" id="mcps1.1.6.1.2"><p id="en-us_topic_0000001058988952_p447834912613"><a name="en-us_topic_0000001058988952_p447834912613"></a><a name="en-us_topic_0000001058988952_p447834912613"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="8.63%" id="mcps1.1.6.1.3"><p id="en-us_topic_0000001058988952_p12479749564"><a name="en-us_topic_0000001058988952_p12479749564"></a><a name="en-us_topic_0000001058988952_p12479749564"></a>Default Value</p>
</th>
<th class="cellrowborder" valign="top" width="7.15%" id="mcps1.1.6.1.4"><p id="en-us_topic_0000001058988952_p13479749560"><a name="en-us_topic_0000001058988952_p13479749560"></a><a name="en-us_topic_0000001058988952_p13479749560"></a>Mandatory</p>
</th>
<th class="cellrowborder" valign="top" width="49.410000000000004%" id="mcps1.1.6.1.5"><p id="en-us_topic_0000001058988952_p247913495610"><a name="en-us_topic_0000001058988952_p247913495610"></a><a name="en-us_topic_0000001058988952_p247913495610"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="en-us_topic_0000001058988952_row1047910498616"><td class="cellrowborder" valign="top" width="24.000000000000004%" headers="mcps1.1.6.1.1 "><p id="en-us_topic_0000001058988952_p167682562062"><a name="en-us_topic_0000001058988952_p167682562062"></a><a name="en-us_topic_0000001058988952_p167682562062"></a>start</p>
</td>
<td class="cellrowborder" valign="top" width="10.810000000000002%" headers="mcps1.1.6.1.2 "><p id="en-us_topic_0000001058988952_p67689566612"><a name="en-us_topic_0000001058988952_p67689566612"></a><a name="en-us_topic_0000001058988952_p67689566612"></a>&lt;time&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="8.63%" headers="mcps1.1.6.1.3 "><p id="en-us_topic_0000001058988952_p1576817561266"><a name="en-us_topic_0000001058988952_p1576817561266"></a><a name="en-us_topic_0000001058988952_p1576817561266"></a>1970-1-1</p>
</td>
<td class="cellrowborder" valign="top" width="7.15%" headers="mcps1.1.6.1.4 "><p id="en-us_topic_0000001058988952_p476819561368"><a name="en-us_topic_0000001058988952_p476819561368"></a><a name="en-us_topic_0000001058988952_p476819561368"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="49.410000000000004%" headers="mcps1.1.6.1.5 "><p id="en-us_topic_0000001058988952_p87681568618"><a name="en-us_topic_0000001058988952_p87681568618"></a><a name="en-us_topic_0000001058988952_p87681568618"></a>Start date of the date selector, in the format of YYYY-MM-DD.</p>
</td>
</tr>
<tr id="en-us_topic_0000001058988952_row3479549162"><td class="cellrowborder" valign="top" width="24.000000000000004%" headers="mcps1.1.6.1.1 "><p id="en-us_topic_0000001058988952_p117686568615"><a name="en-us_topic_0000001058988952_p117686568615"></a><a name="en-us_topic_0000001058988952_p117686568615"></a>end</p>
</td>
<td class="cellrowborder" valign="top" width="10.810000000000002%" headers="mcps1.1.6.1.2 "><p id="en-us_topic_0000001058988952_p19768115614615"><a name="en-us_topic_0000001058988952_p19768115614615"></a><a name="en-us_topic_0000001058988952_p19768115614615"></a>&lt;time&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="8.63%" headers="mcps1.1.6.1.3 "><p id="en-us_topic_0000001058988952_p27686569618"><a name="en-us_topic_0000001058988952_p27686569618"></a><a name="en-us_topic_0000001058988952_p27686569618"></a>2100-12-31</p>
</td>
<td class="cellrowborder" valign="top" width="7.15%" headers="mcps1.1.6.1.4 "><p id="en-us_topic_0000001058988952_p1076912564617"><a name="en-us_topic_0000001058988952_p1076912564617"></a><a name="en-us_topic_0000001058988952_p1076912564617"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="49.410000000000004%" headers="mcps1.1.6.1.5 "><p id="en-us_topic_0000001058988952_p1176915562611"><a name="en-us_topic_0000001058988952_p1176915562611"></a><a name="en-us_topic_0000001058988952_p1176915562611"></a>End date of the date selector, in the format of YYYY-MM-DD.</p>
</td>
</tr>
<tr id="en-us_topic_0000001058988952_row147919493619"><td class="cellrowborder" valign="top" width="24.000000000000004%" headers="mcps1.1.6.1.1 "><p id="en-us_topic_0000001058988952_p20769056565"><a name="en-us_topic_0000001058988952_p20769056565"></a><a name="en-us_topic_0000001058988952_p20769056565"></a>selected</p>
</td>
<td class="cellrowborder" valign="top" width="10.810000000000002%" headers="mcps1.1.6.1.2 "><p id="en-us_topic_0000001058988952_p1376935613619"><a name="en-us_topic_0000001058988952_p1376935613619"></a><a name="en-us_topic_0000001058988952_p1376935613619"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="8.63%" headers="mcps1.1.6.1.3 "><p id="en-us_topic_0000001058988952_p177694568616"><a name="en-us_topic_0000001058988952_p177694568616"></a><a name="en-us_topic_0000001058988952_p177694568616"></a>Current date</p>
</td>
<td class="cellrowborder" valign="top" width="7.15%" headers="mcps1.1.6.1.4 "><p id="en-us_topic_0000001058988952_p076925617611"><a name="en-us_topic_0000001058988952_p076925617611"></a><a name="en-us_topic_0000001058988952_p076925617611"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="49.410000000000004%" headers="mcps1.1.6.1.5 "><p id="en-us_topic_0000001058988952_p17695564620"><a name="en-us_topic_0000001058988952_p17695564620"></a><a name="en-us_topic_0000001058988952_p17695564620"></a>Default value of the date selector, in the format of YYYY-MM-DD.</p>
</td>
</tr>
<tr id="en-us_topic_0000001058988952_row106371036261"><td class="cellrowborder" valign="top" width="24.000000000000004%" headers="mcps1.1.6.1.1 "><p id="en-us_topic_0000001058988952_p2238125117139"><a name="en-us_topic_0000001058988952_p2238125117139"></a><a name="en-us_topic_0000001058988952_p2238125117139"></a>lunar<sup id="en-us_topic_0000001058988952_sup6301324133317"><a name="en-us_topic_0000001058988952_sup6301324133317"></a><a name="en-us_topic_0000001058988952_sup6301324133317"></a>5+</sup></p>
</td>
<td class="cellrowborder" valign="top" width="10.810000000000002%" headers="mcps1.1.6.1.2 "><p id="en-us_topic_0000001058988952_p023825181319"><a name="en-us_topic_0000001058988952_p023825181319"></a><a name="en-us_topic_0000001058988952_p023825181319"></a>boolean</p>
</td>
<td class="cellrowborder" valign="top" width="8.63%" headers="mcps1.1.6.1.3 "><p id="en-us_topic_0000001058988952_p18238115116134"><a name="en-us_topic_0000001058988952_p18238115116134"></a><a name="en-us_topic_0000001058988952_p18238115116134"></a>false</p>
</td>
<td class="cellrowborder" valign="top" width="7.15%" headers="mcps1.1.6.1.4 "><p id="en-us_topic_0000001058988952_p0238851121311"><a name="en-us_topic_0000001058988952_p0238851121311"></a><a name="en-us_topic_0000001058988952_p0238851121311"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="49.410000000000004%" headers="mcps1.1.6.1.5 "><p id="en-us_topic_0000001058988952_p14238195141316"><a name="en-us_topic_0000001058988952_p14238195141316"></a><a name="en-us_topic_0000001058988952_p14238195141316"></a>Whether the pop-up window displays the lunar calendar.</p>
</td>
</tr>
</tbody>
</table>

Date and time selector \(**type**  is  **datetime**\)

<a name="en-us_topic_0000001058988952_table1188511392120"></a>
<table><thead align="left"><tr id="en-us_topic_0000001058988952_row16886193915128"><th class="cellrowborder" valign="top" width="24.000000000000004%" id="mcps1.1.6.1.1"><p id="en-us_topic_0000001058988952_p58868399129"><a name="en-us_topic_0000001058988952_p58868399129"></a><a name="en-us_topic_0000001058988952_p58868399129"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="10.810000000000002%" id="mcps1.1.6.1.2"><p id="en-us_topic_0000001058988952_p19886739161213"><a name="en-us_topic_0000001058988952_p19886739161213"></a><a name="en-us_topic_0000001058988952_p19886739161213"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="8.63%" id="mcps1.1.6.1.3"><p id="en-us_topic_0000001058988952_p138864393128"><a name="en-us_topic_0000001058988952_p138864393128"></a><a name="en-us_topic_0000001058988952_p138864393128"></a>Default Value</p>
</th>
<th class="cellrowborder" valign="top" width="7.15%" id="mcps1.1.6.1.4"><p id="en-us_topic_0000001058988952_p288653914122"><a name="en-us_topic_0000001058988952_p288653914122"></a><a name="en-us_topic_0000001058988952_p288653914122"></a>Mandatory</p>
</th>
<th class="cellrowborder" valign="top" width="49.410000000000004%" id="mcps1.1.6.1.5"><p id="en-us_topic_0000001058988952_p1886193931212"><a name="en-us_topic_0000001058988952_p1886193931212"></a><a name="en-us_topic_0000001058988952_p1886193931212"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="en-us_topic_0000001058988952_row288753919128"><td class="cellrowborder" valign="top" width="24.000000000000004%" headers="mcps1.1.6.1.1 "><p id="en-us_topic_0000001058988952_p20887539141215"><a name="en-us_topic_0000001058988952_p20887539141215"></a><a name="en-us_topic_0000001058988952_p20887539141215"></a>selected</p>
</td>
<td class="cellrowborder" valign="top" width="10.810000000000002%" headers="mcps1.1.6.1.2 "><p id="en-us_topic_0000001058988952_p788753910126"><a name="en-us_topic_0000001058988952_p788753910126"></a><a name="en-us_topic_0000001058988952_p788753910126"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="8.63%" headers="mcps1.1.6.1.3 "><p id="en-us_topic_0000001058988952_p16887539111214"><a name="en-us_topic_0000001058988952_p16887539111214"></a><a name="en-us_topic_0000001058988952_p16887539111214"></a>Current date and time</p>
</td>
<td class="cellrowborder" valign="top" width="7.15%" headers="mcps1.1.6.1.4 "><p id="en-us_topic_0000001058988952_p4887203911129"><a name="en-us_topic_0000001058988952_p4887203911129"></a><a name="en-us_topic_0000001058988952_p4887203911129"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="49.410000000000004%" headers="mcps1.1.6.1.5 "><p id="en-us_topic_0000001058988952_p33848571013"><a name="en-us_topic_0000001058988952_p33848571013"></a><a name="en-us_topic_0000001058988952_p33848571013"></a>Default value of the date and time selector. The value can be in the format of MM-DD-HH-mm or YYYY-MM-DD-HH-mm. If the year is not set, the current year is used by default. The value you set is the date selected by default in the pop-up window.</p>
</td>
</tr>
<tr id="en-us_topic_0000001058988952_row25569188246"><td class="cellrowborder" valign="top" width="24.000000000000004%" headers="mcps1.1.6.1.1 "><p id="en-us_topic_0000001058988952_p7249338141710"><a name="en-us_topic_0000001058988952_p7249338141710"></a><a name="en-us_topic_0000001058988952_p7249338141710"></a>hours</p>
</td>
<td class="cellrowborder" valign="top" width="10.810000000000002%" headers="mcps1.1.6.1.2 "><p id="en-us_topic_0000001058988952_p1814251913247"><a name="en-us_topic_0000001058988952_p1814251913247"></a><a name="en-us_topic_0000001058988952_p1814251913247"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="8.63%" headers="mcps1.1.6.1.3 "><p id="en-us_topic_0000001058988952_p51424195244"><a name="en-us_topic_0000001058988952_p51424195244"></a><a name="en-us_topic_0000001058988952_p51424195244"></a>24</p>
<p id="en-us_topic_0000001058988952_p52731028173117"><a name="en-us_topic_0000001058988952_p52731028173117"></a><a name="en-us_topic_0000001058988952_p52731028173117"></a>-<sup id="en-us_topic_0000001058988952_sup627311285313"><a name="en-us_topic_0000001058988952_sup627311285313"></a><a name="en-us_topic_0000001058988952_sup627311285313"></a>5+</sup></p>
</td>
<td class="cellrowborder" valign="top" width="7.15%" headers="mcps1.1.6.1.4 "><p id="en-us_topic_0000001058988952_p171426196242"><a name="en-us_topic_0000001058988952_p171426196242"></a><a name="en-us_topic_0000001058988952_p171426196242"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="49.410000000000004%" headers="mcps1.1.6.1.5 "><p id="en-us_topic_0000001058988952_p1314251932418"><a name="en-us_topic_0000001058988952_p1314251932418"></a><a name="en-us_topic_0000001058988952_p1314251932418"></a>Time format used by the date and time selector. Available values include:</p>
<a name="en-us_topic_0000001058988952_ul15923173119204"></a><a name="en-us_topic_0000001058988952_ul15923173119204"></a><ul id="en-us_topic_0000001058988952_ul15923173119204"><li><strong id="en-us_topic_0000001058988952_b113902010491"><a name="en-us_topic_0000001058988952_b113902010491"></a><a name="en-us_topic_0000001058988952_b113902010491"></a>12</strong>: displayed in 12-hour format and distinguished by a.m. and p.m.</li><li><strong id="en-us_topic_0000001058988952_b253865114918"><a name="en-us_topic_0000001058988952_b253865114918"></a><a name="en-us_topic_0000001058988952_b253865114918"></a>24</strong>: displayed in 24-hour format<div class="note" id="en-us_topic_0000001058988952_note1880145011113"><a name="en-us_topic_0000001058988952_note1880145011113"></a><a name="en-us_topic_0000001058988952_note1880145011113"></a><span class="notetitle"> NOTE: </span><div class="notebody"><p id="en-us_topic_0000001058988952_p1988165031111"><a name="en-us_topic_0000001058988952_p1988165031111"></a><a name="en-us_topic_0000001058988952_p1988165031111"></a>The default value is the most commonly-used hour format in the current locale. <sup id="en-us_topic_0000001058988952_sup11183114910314"><a name="en-us_topic_0000001058988952_sup11183114910314"></a><a name="en-us_topic_0000001058988952_sup11183114910314"></a>5+</sup></p>
</div></div>
</li></ul>
</td>
</tr>
<tr id="en-us_topic_0000001058988952_row1742363212240"><td class="cellrowborder" valign="top" width="24.000000000000004%" headers="mcps1.1.6.1.1 "><p id="en-us_topic_0000001058988952_p1820281519182"><a name="en-us_topic_0000001058988952_p1820281519182"></a><a name="en-us_topic_0000001058988952_p1820281519182"></a>lunar<sup id="en-us_topic_0000001058988952_sup370711541116"><a name="en-us_topic_0000001058988952_sup370711541116"></a><a name="en-us_topic_0000001058988952_sup370711541116"></a>5+</sup></p>
</td>
<td class="cellrowborder" valign="top" width="10.810000000000002%" headers="mcps1.1.6.1.2 "><p id="en-us_topic_0000001058988952_p9202131571819"><a name="en-us_topic_0000001058988952_p9202131571819"></a><a name="en-us_topic_0000001058988952_p9202131571819"></a>boolean</p>
</td>
<td class="cellrowborder" valign="top" width="8.63%" headers="mcps1.1.6.1.3 "><p id="en-us_topic_0000001058988952_p520313152182"><a name="en-us_topic_0000001058988952_p520313152182"></a><a name="en-us_topic_0000001058988952_p520313152182"></a>false</p>
</td>
<td class="cellrowborder" valign="top" width="7.15%" headers="mcps1.1.6.1.4 "><p id="en-us_topic_0000001058988952_p142031715201812"><a name="en-us_topic_0000001058988952_p142031715201812"></a><a name="en-us_topic_0000001058988952_p142031715201812"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="49.410000000000004%" headers="mcps1.1.6.1.5 "><p id="en-us_topic_0000001058988952_p16203181541812"><a name="en-us_topic_0000001058988952_p16203181541812"></a><a name="en-us_topic_0000001058988952_p16203181541812"></a>Whether the pop-up window displays the lunar calendar.</p>
</td>
</tr>
</tbody>
</table>

Multi-column text selector \(**type**  is  **multi-text**\)

<a name="en-us_topic_0000001058988952_table1886619321772"></a>
<table><thead align="left"><tr id="en-us_topic_0000001058988952_row198671332179"><th class="cellrowborder" valign="top" width="24.000000000000004%" id="mcps1.1.6.1.1"><p id="en-us_topic_0000001058988952_p168677321871"><a name="en-us_topic_0000001058988952_p168677321871"></a><a name="en-us_topic_0000001058988952_p168677321871"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="10.810000000000002%" id="mcps1.1.6.1.2"><p id="en-us_topic_0000001058988952_p38670322711"><a name="en-us_topic_0000001058988952_p38670322711"></a><a name="en-us_topic_0000001058988952_p38670322711"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="8.63%" id="mcps1.1.6.1.3"><p id="en-us_topic_0000001058988952_p178670321276"><a name="en-us_topic_0000001058988952_p178670321276"></a><a name="en-us_topic_0000001058988952_p178670321276"></a>Default Value</p>
</th>
<th class="cellrowborder" valign="top" width="7.15%" id="mcps1.1.6.1.4"><p id="en-us_topic_0000001058988952_p9867183215719"><a name="en-us_topic_0000001058988952_p9867183215719"></a><a name="en-us_topic_0000001058988952_p9867183215719"></a>Mandatory</p>
</th>
<th class="cellrowborder" valign="top" width="49.410000000000004%" id="mcps1.1.6.1.5"><p id="en-us_topic_0000001058988952_p168671324711"><a name="en-us_topic_0000001058988952_p168671324711"></a><a name="en-us_topic_0000001058988952_p168671324711"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="en-us_topic_0000001058988952_row3757154961319"><td class="cellrowborder" valign="top" width="24.000000000000004%" headers="mcps1.1.6.1.1 "><p id="en-us_topic_0000001058988952_p12757204951314"><a name="en-us_topic_0000001058988952_p12757204951314"></a><a name="en-us_topic_0000001058988952_p12757204951314"></a>columns</p>
</td>
<td class="cellrowborder" valign="top" width="10.810000000000002%" headers="mcps1.1.6.1.2 "><p id="en-us_topic_0000001058988952_p13757124918137"><a name="en-us_topic_0000001058988952_p13757124918137"></a><a name="en-us_topic_0000001058988952_p13757124918137"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="8.63%" headers="mcps1.1.6.1.3 "><p id="en-us_topic_0000001058988952_p0757144914132"><a name="en-us_topic_0000001058988952_p0757144914132"></a><a name="en-us_topic_0000001058988952_p0757144914132"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.15%" headers="mcps1.1.6.1.4 "><p id="en-us_topic_0000001058988952_p14757149111317"><a name="en-us_topic_0000001058988952_p14757149111317"></a><a name="en-us_topic_0000001058988952_p14757149111317"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="49.410000000000004%" headers="mcps1.1.6.1.5 "><p id="en-us_topic_0000001058988952_p1675884931313"><a name="en-us_topic_0000001058988952_p1675884931313"></a><a name="en-us_topic_0000001058988952_p1675884931313"></a>Number of columns in the multi-column text selector.</p>
</td>
</tr>
<tr id="en-us_topic_0000001058988952_row3867103214710"><td class="cellrowborder" valign="top" width="24.000000000000004%" headers="mcps1.1.6.1.1 "><p id="en-us_topic_0000001058988952_p793074416717"><a name="en-us_topic_0000001058988952_p793074416717"></a><a name="en-us_topic_0000001058988952_p793074416717"></a>range</p>
</td>
<td class="cellrowborder" valign="top" width="10.810000000000002%" headers="mcps1.1.6.1.2 "><p id="en-us_topic_0000001058988952_p793010441976"><a name="en-us_topic_0000001058988952_p793010441976"></a><a name="en-us_topic_0000001058988952_p793010441976"></a>Two-dimensional array</p>
</td>
<td class="cellrowborder" valign="top" width="8.63%" headers="mcps1.1.6.1.3 "><p id="en-us_topic_0000001058988952_p7930174418712"><a name="en-us_topic_0000001058988952_p7930174418712"></a><a name="en-us_topic_0000001058988952_p7930174418712"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.15%" headers="mcps1.1.6.1.4 "><p id="en-us_topic_0000001058988952_p2930444971"><a name="en-us_topic_0000001058988952_p2930444971"></a><a name="en-us_topic_0000001058988952_p2930444971"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="49.410000000000004%" headers="mcps1.1.6.1.5 "><p id="en-us_topic_0000001058988952_p139301644675"><a name="en-us_topic_0000001058988952_p139301644675"></a><a name="en-us_topic_0000001058988952_p139301644675"></a>Items of the multi-column text selector. <strong id="en-us_topic_0000001058988952_b164211558164916"><a name="en-us_topic_0000001058988952_b164211558164916"></a><a name="en-us_topic_0000001058988952_b164211558164916"></a>range</strong> is a two-dimensional array that indicates the number of columns. Each item in the array indicates the data of each column, for example, <strong id="en-us_topic_0000001058988952_b1751216441149"><a name="en-us_topic_0000001058988952_b1751216441149"></a><a name="en-us_topic_0000001058988952_b1751216441149"></a>[["a","b"], ["c","d"]]</strong>.</p>
<div class="note" id="en-us_topic_0000001058988952_note112201642121219"><a name="en-us_topic_0000001058988952_note112201642121219"></a><a name="en-us_topic_0000001058988952_note112201642121219"></a><span class="notetitle"> NOTE: </span><div class="notebody"><p id="en-us_topic_0000001058988952_p8220114221212"><a name="en-us_topic_0000001058988952_p8220114221212"></a><a name="en-us_topic_0000001058988952_p8220114221212"></a>Use the data binding mode, for example, range = {{data}}. Declare the corresponding variable <strong id="en-us_topic_0000001058988952_b4470649201410"><a name="en-us_topic_0000001058988952_b4470649201410"></a><a name="en-us_topic_0000001058988952_b4470649201410"></a>data: [["a","b"], ["c","d"]]</strong> in the JavaScript.</p>
</div></div>
</td>
</tr>
<tr id="en-us_topic_0000001058988952_row18671332572"><td class="cellrowborder" valign="top" width="24.000000000000004%" headers="mcps1.1.6.1.1 "><p id="en-us_topic_0000001058988952_p693016441273"><a name="en-us_topic_0000001058988952_p693016441273"></a><a name="en-us_topic_0000001058988952_p693016441273"></a>selected</p>
</td>
<td class="cellrowborder" valign="top" width="10.810000000000002%" headers="mcps1.1.6.1.2 "><p id="en-us_topic_0000001058988952_p159306448720"><a name="en-us_topic_0000001058988952_p159306448720"></a><a name="en-us_topic_0000001058988952_p159306448720"></a>Array</p>
</td>
<td class="cellrowborder" valign="top" width="8.63%" headers="mcps1.1.6.1.3 "><p id="en-us_topic_0000001058988952_p18930544471"><a name="en-us_topic_0000001058988952_p18930544471"></a><a name="en-us_topic_0000001058988952_p18930544471"></a>0,0,0,...</p>
</td>
<td class="cellrowborder" valign="top" width="7.15%" headers="mcps1.1.6.1.4 "><p id="en-us_topic_0000001058988952_p69305448719"><a name="en-us_topic_0000001058988952_p69305448719"></a><a name="en-us_topic_0000001058988952_p69305448719"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="49.410000000000004%" headers="mcps1.1.6.1.5 "><p id="en-us_topic_0000001058988952_p12930144373"><a name="en-us_topic_0000001058988952_p12930144373"></a><a name="en-us_topic_0000001058988952_p12930144373"></a>Default value of the multi-column text selector, which is an array consisting of the indexes of the selected items in each column.</p>
</td>
</tr>
</tbody>
</table>

## Event<a name="en-us_topic_0000001058988952_section18155133771112"></a>

Text selector \(**type**  is  **text**\)

<a name="en-us_topic_0000001058988952_table1215511375116"></a>
<table><thead align="left"><tr id="en-us_topic_0000001058988952_row161551337151111"><th class="cellrowborder" valign="top" width="16.16161616161616%" id="mcps1.1.4.1.1"><p id="en-us_topic_0000001058988952_p51559378116"><a name="en-us_topic_0000001058988952_p51559378116"></a><a name="en-us_topic_0000001058988952_p51559378116"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="41.41414141414141%" id="mcps1.1.4.1.2"><p id="en-us_topic_0000001058988952_p18156737201115"><a name="en-us_topic_0000001058988952_p18156737201115"></a><a name="en-us_topic_0000001058988952_p18156737201115"></a>Parameter</p>
</th>
<th class="cellrowborder" valign="top" width="42.42424242424242%" id="mcps1.1.4.1.3"><p id="en-us_topic_0000001058988952_p9156133771110"><a name="en-us_topic_0000001058988952_p9156133771110"></a><a name="en-us_topic_0000001058988952_p9156133771110"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="en-us_topic_0000001058988952_row11156937161112"><td class="cellrowborder" valign="top" width="16.16161616161616%" headers="mcps1.1.4.1.1 "><p id="en-us_topic_0000001058988952_p1915683711116"><a name="en-us_topic_0000001058988952_p1915683711116"></a><a name="en-us_topic_0000001058988952_p1915683711116"></a>change</p>
</td>
<td class="cellrowborder" valign="top" width="41.41414141414141%" headers="mcps1.1.4.1.2 "><p id="en-us_topic_0000001058988952_p6156173791118"><a name="en-us_topic_0000001058988952_p6156173791118"></a><a name="en-us_topic_0000001058988952_p6156173791118"></a>{ newValue: newValue, newSelected: newSelected }</p>
</td>
<td class="cellrowborder" valign="top" width="42.42424242424242%" headers="mcps1.1.4.1.3 "><p id="en-us_topic_0000001058988952_p0156133721114"><a name="en-us_topic_0000001058988952_p0156133721114"></a><a name="en-us_topic_0000001058988952_p0156133721114"></a>Triggered when a value is specified for the text selector.</p>
</td>
</tr>
</tbody>
</table>

Time selector \(**type**  is  **time**\)

<a name="en-us_topic_0000001058988952_table2156173771110"></a>
<table><thead align="left"><tr id="en-us_topic_0000001058988952_row515673721113"><th class="cellrowborder" valign="top" width="16.16161616161616%" id="mcps1.1.4.1.1"><p id="en-us_topic_0000001058988952_p1015683721120"><a name="en-us_topic_0000001058988952_p1015683721120"></a><a name="en-us_topic_0000001058988952_p1015683721120"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="41.41414141414141%" id="mcps1.1.4.1.2"><p id="en-us_topic_0000001058988952_p1215723721116"><a name="en-us_topic_0000001058988952_p1215723721116"></a><a name="en-us_topic_0000001058988952_p1215723721116"></a>Parameter</p>
</th>
<th class="cellrowborder" valign="top" width="42.42424242424242%" id="mcps1.1.4.1.3"><p id="en-us_topic_0000001058988952_p111571237171120"><a name="en-us_topic_0000001058988952_p111571237171120"></a><a name="en-us_topic_0000001058988952_p111571237171120"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="en-us_topic_0000001058988952_row515712377119"><td class="cellrowborder" valign="top" width="16.16161616161616%" headers="mcps1.1.4.1.1 "><p id="en-us_topic_0000001058988952_p10157837121120"><a name="en-us_topic_0000001058988952_p10157837121120"></a><a name="en-us_topic_0000001058988952_p10157837121120"></a>change</p>
</td>
<td class="cellrowborder" valign="top" width="41.41414141414141%" headers="mcps1.1.4.1.2 "><p id="en-us_topic_0000001058988952_p3157133711111"><a name="en-us_topic_0000001058988952_p3157133711111"></a><a name="en-us_topic_0000001058988952_p3157133711111"></a>{ hour: hour, minute: minute<span id="en-us_topic_0000001058988952_ph10157103720116"><a name="en-us_topic_0000001058988952_ph10157103720116"></a><a name="en-us_topic_0000001058988952_ph10157103720116"></a>, [second:second] </span>}</p>
</td>
<td class="cellrowborder" valign="top" width="42.42424242424242%" headers="mcps1.1.4.1.3 "><p id="en-us_topic_0000001058988952_p71572376117"><a name="en-us_topic_0000001058988952_p71572376117"></a><a name="en-us_topic_0000001058988952_p71572376117"></a>Triggered when a value is specified for the time selector.</p>
<p id="en-us_topic_0000001058988952_p015793716115"><a name="en-us_topic_0000001058988952_p015793716115"></a><a name="en-us_topic_0000001058988952_p015793716115"></a>If seconds are contained, the value contains hour, minute, and second.</p>
</td>
</tr>
</tbody>
</table>

Date selector \(**type**  is  **date**\)

<a name="en-us_topic_0000001058988952_table1115743720119"></a>
<table><thead align="left"><tr id="en-us_topic_0000001058988952_row015817374117"><th class="cellrowborder" valign="top" width="15.370000000000001%" id="mcps1.1.4.1.1"><p id="en-us_topic_0000001058988952_p6158163711119"><a name="en-us_topic_0000001058988952_p6158163711119"></a><a name="en-us_topic_0000001058988952_p6158163711119"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="34.22%" id="mcps1.1.4.1.2"><p id="en-us_topic_0000001058988952_p41581137181117"><a name="en-us_topic_0000001058988952_p41581137181117"></a><a name="en-us_topic_0000001058988952_p41581137181117"></a>Parameter</p>
</th>
<th class="cellrowborder" valign="top" width="50.41%" id="mcps1.1.4.1.3"><p id="en-us_topic_0000001058988952_p171581037161112"><a name="en-us_topic_0000001058988952_p171581037161112"></a><a name="en-us_topic_0000001058988952_p171581037161112"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="en-us_topic_0000001058988952_row2158143720115"><td class="cellrowborder" valign="top" width="15.370000000000001%" headers="mcps1.1.4.1.1 "><p id="en-us_topic_0000001058988952_p1015817378119"><a name="en-us_topic_0000001058988952_p1015817378119"></a><a name="en-us_topic_0000001058988952_p1015817378119"></a>change</p>
</td>
<td class="cellrowborder" valign="top" width="34.22%" headers="mcps1.1.4.1.2 "><p id="en-us_topic_0000001058988952_p7158153715114"><a name="en-us_topic_0000001058988952_p7158153715114"></a><a name="en-us_topic_0000001058988952_p7158153715114"></a>{ year:year, month:month, day:day }</p>
</td>
<td class="cellrowborder" valign="top" width="50.41%" headers="mcps1.1.4.1.3 "><p id="en-us_topic_0000001058988952_p1515853716114"><a name="en-us_topic_0000001058988952_p1515853716114"></a><a name="en-us_topic_0000001058988952_p1515853716114"></a>Triggered when a value is specified for the date selector.</p>
</td>
</tr>
</tbody>
</table>

Date and time selector \(**type**  is  **datetime**\)

<a name="en-us_topic_0000001058988952_table1715863781117"></a>
<table><thead align="left"><tr id="en-us_topic_0000001058988952_row7158163751117"><th class="cellrowborder" valign="top" width="15.370000000000001%" id="mcps1.1.4.1.1"><p id="en-us_topic_0000001058988952_p14158137181119"><a name="en-us_topic_0000001058988952_p14158137181119"></a><a name="en-us_topic_0000001058988952_p14158137181119"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="34.22%" id="mcps1.1.4.1.2"><p id="en-us_topic_0000001058988952_p91595374117"><a name="en-us_topic_0000001058988952_p91595374117"></a><a name="en-us_topic_0000001058988952_p91595374117"></a>Parameter</p>
</th>
<th class="cellrowborder" valign="top" width="50.41%" id="mcps1.1.4.1.3"><p id="en-us_topic_0000001058988952_p21591037191117"><a name="en-us_topic_0000001058988952_p21591037191117"></a><a name="en-us_topic_0000001058988952_p21591037191117"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="en-us_topic_0000001058988952_row8159203718118"><td class="cellrowborder" valign="top" width="15.370000000000001%" headers="mcps1.1.4.1.1 "><p id="en-us_topic_0000001058988952_p2015913771110"><a name="en-us_topic_0000001058988952_p2015913771110"></a><a name="en-us_topic_0000001058988952_p2015913771110"></a>change</p>
</td>
<td class="cellrowborder" valign="top" width="34.22%" headers="mcps1.1.4.1.2 "><p id="en-us_topic_0000001058988952_p12159337101118"><a name="en-us_topic_0000001058988952_p12159337101118"></a><a name="en-us_topic_0000001058988952_p12159337101118"></a>{ year:year, month:month, day:day,  hour:hour, minute:minute }</p>
</td>
<td class="cellrowborder" valign="top" width="50.41%" headers="mcps1.1.4.1.3 "><p id="en-us_topic_0000001058988952_p81591637161118"><a name="en-us_topic_0000001058988952_p81591637161118"></a><a name="en-us_topic_0000001058988952_p81591637161118"></a>Triggered when a value is specified for the date and time selector.</p>
</td>
</tr>
</tbody>
</table>

Multi-text selector \(**type**  is  **multi-text**\)

<a name="en-us_topic_0000001058988952_table10159337131117"></a>
<table><thead align="left"><tr id="en-us_topic_0000001058988952_row16159153791118"><th class="cellrowborder" valign="top" width="13.969999999999999%" id="mcps1.1.4.1.1"><p id="en-us_topic_0000001058988952_p1159193717110"><a name="en-us_topic_0000001058988952_p1159193717110"></a><a name="en-us_topic_0000001058988952_p1159193717110"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="36.9%" id="mcps1.1.4.1.2"><p id="en-us_topic_0000001058988952_p10160193711111"><a name="en-us_topic_0000001058988952_p10160193711111"></a><a name="en-us_topic_0000001058988952_p10160193711111"></a>Parameter</p>
</th>
<th class="cellrowborder" valign="top" width="49.13%" id="mcps1.1.4.1.3"><p id="en-us_topic_0000001058988952_p17160637151113"><a name="en-us_topic_0000001058988952_p17160637151113"></a><a name="en-us_topic_0000001058988952_p17160637151113"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="en-us_topic_0000001058988952_row12160163714119"><td class="cellrowborder" valign="top" width="13.969999999999999%" headers="mcps1.1.4.1.1 "><p id="en-us_topic_0000001058988952_p416053751119"><a name="en-us_topic_0000001058988952_p416053751119"></a><a name="en-us_topic_0000001058988952_p416053751119"></a>columnchange</p>
</td>
<td class="cellrowborder" valign="top" width="36.9%" headers="mcps1.1.4.1.2 "><p id="en-us_topic_0000001058988952_p616013761119"><a name="en-us_topic_0000001058988952_p616013761119"></a><a name="en-us_topic_0000001058988952_p616013761119"></a>{ column:column, newValue:newValue, newSelected:newSelected }</p>
</td>
<td class="cellrowborder" valign="top" width="49.13%" headers="mcps1.1.4.1.3 "><p id="en-us_topic_0000001058988952_p71601037111114"><a name="en-us_topic_0000001058988952_p71601037111114"></a><a name="en-us_topic_0000001058988952_p71601037111114"></a>Triggered when the value of a column in the multi-column selector changes. <strong id="en-us_topic_0000001058988952_b4614145720513"><a name="en-us_topic_0000001058988952_b4614145720513"></a><a name="en-us_topic_0000001058988952_b4614145720513"></a>column</strong> indicates the column whose value has changed, <strong id="en-us_topic_0000001058988952_b19620357165119"><a name="en-us_topic_0000001058988952_b19620357165119"></a><a name="en-us_topic_0000001058988952_b19620357165119"></a>newValue</strong> indicates the selected value, and <strong id="en-us_topic_0000001058988952_b7620165717514"><a name="en-us_topic_0000001058988952_b7620165717514"></a><a name="en-us_topic_0000001058988952_b7620165717514"></a>newSelected</strong> indicates the index of the selected value.</p>
</td>
</tr>
</tbody>
</table>

## Style<a name="en-us_topic_0000001058988952_section198061172344"></a>

<a name="en-us_topic_0000001058988952_table1711341991019"></a>
<table><thead align="left"><tr id="en-us_topic_0000001058988952_row10113191981014"><th class="cellrowborder" valign="top" width="23.11768823117688%" id="mcps1.1.6.1.1"><p id="en-us_topic_0000001058988952_en-us_topic_0000001059340528_a14a0c012a26248cfbec6b13dcc4f2cbe"><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_a14a0c012a26248cfbec6b13dcc4f2cbe"></a><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_a14a0c012a26248cfbec6b13dcc4f2cbe"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="20.477952204779523%" id="mcps1.1.6.1.2"><p id="en-us_topic_0000001058988952_en-us_topic_0000001059340528_a8dc328a555a74157a00de86181fc3a7b"><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_a8dc328a555a74157a00de86181fc3a7b"></a><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_a8dc328a555a74157a00de86181fc3a7b"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="8.869113088691131%" id="mcps1.1.6.1.3"><p id="en-us_topic_0000001058988952_en-us_topic_0000001059340528_a41a31e48d0c74ad4982add2655515c82"><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_a41a31e48d0c74ad4982add2655515c82"></a><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_a41a31e48d0c74ad4982add2655515c82"></a>Default Value</p>
</th>
<th class="cellrowborder" valign="top" width="7.519248075192481%" id="mcps1.1.6.1.4"><p id="en-us_topic_0000001058988952_p1114171941016"><a name="en-us_topic_0000001058988952_p1114171941016"></a><a name="en-us_topic_0000001058988952_p1114171941016"></a>Mandatory</p>
</th>
<th class="cellrowborder" valign="top" width="40.01599840015999%" id="mcps1.1.6.1.5"><p id="en-us_topic_0000001058988952_en-us_topic_0000001059340528_af7a726e456f7485c87bd4e0527bc6584"><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_af7a726e456f7485c87bd4e0527bc6584"></a><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_af7a726e456f7485c87bd4e0527bc6584"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="en-us_topic_0000001058988952_row1347185310102"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="en-us_topic_0000001058988952_p19283105419106"><a name="en-us_topic_0000001058988952_p19283105419106"></a><a name="en-us_topic_0000001058988952_p19283105419106"></a>color</p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p id="en-us_topic_0000001058988952_p62834542108"><a name="en-us_topic_0000001058988952_p62834542108"></a><a name="en-us_topic_0000001058988952_p62834542108"></a>&lt;color&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p id="en-us_topic_0000001058988952_p1796644433018"><a name="en-us_topic_0000001058988952_p1796644433018"></a><a name="en-us_topic_0000001058988952_p1796644433018"></a>#ffffff</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p id="en-us_topic_0000001058988952_p7283145491016"><a name="en-us_topic_0000001058988952_p7283145491016"></a><a name="en-us_topic_0000001058988952_p7283145491016"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="en-us_topic_0000001058988952_p028305411019"><a name="en-us_topic_0000001058988952_p028305411019"></a><a name="en-us_topic_0000001058988952_p028305411019"></a>Font color of a candidate item.</p>
</td>
</tr>
<tr id="en-us_topic_0000001058988952_row1548135317105"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="en-us_topic_0000001058988952_p0283854111014"><a name="en-us_topic_0000001058988952_p0283854111014"></a><a name="en-us_topic_0000001058988952_p0283854111014"></a>font-size</p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p id="en-us_topic_0000001058988952_p15283105491016"><a name="en-us_topic_0000001058988952_p15283105491016"></a><a name="en-us_topic_0000001058988952_p15283105491016"></a>&lt;length&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p id="en-us_topic_0000001058988952_p8212164592915"><a name="en-us_topic_0000001058988952_p8212164592915"></a><a name="en-us_topic_0000001058988952_p8212164592915"></a>16px</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p id="en-us_topic_0000001058988952_p62831154151017"><a name="en-us_topic_0000001058988952_p62831154151017"></a><a name="en-us_topic_0000001058988952_p62831154151017"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="en-us_topic_0000001058988952_p128315481011"><a name="en-us_topic_0000001058988952_p128315481011"></a><a name="en-us_topic_0000001058988952_p128315481011"></a>Font size of a candidate item. The value is of the length type, in pixels.</p>
</td>
</tr>
<tr id="en-us_topic_0000001058988952_row124651248131013"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="en-us_topic_0000001058988952_p13284125471017"><a name="en-us_topic_0000001058988952_p13284125471017"></a><a name="en-us_topic_0000001058988952_p13284125471017"></a>selected-color</p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p id="en-us_topic_0000001058988952_p12284125418108"><a name="en-us_topic_0000001058988952_p12284125418108"></a><a name="en-us_topic_0000001058988952_p12284125418108"></a>&lt;color&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p id="en-us_topic_0000001058988952_p105331535284"><a name="en-us_topic_0000001058988952_p105331535284"></a><a name="en-us_topic_0000001058988952_p105331535284"></a>#ff0a69f7</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p id="en-us_topic_0000001058988952_p15284105451010"><a name="en-us_topic_0000001058988952_p15284105451010"></a><a name="en-us_topic_0000001058988952_p15284105451010"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="en-us_topic_0000001058988952_p1528455431014"><a name="en-us_topic_0000001058988952_p1528455431014"></a><a name="en-us_topic_0000001058988952_p1528455431014"></a>Font color of the selected item.</p>
</td>
</tr>
<tr id="en-us_topic_0000001058988952_row9466124811102"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="en-us_topic_0000001058988952_p5284135412105"><a name="en-us_topic_0000001058988952_p5284135412105"></a><a name="en-us_topic_0000001058988952_p5284135412105"></a>selected-font-size</p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p id="en-us_topic_0000001058988952_p152844542101"><a name="en-us_topic_0000001058988952_p152844542101"></a><a name="en-us_topic_0000001058988952_p152844542101"></a>&lt;length&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p id="en-us_topic_0000001058988952_p204881543202716"><a name="en-us_topic_0000001058988952_p204881543202716"></a><a name="en-us_topic_0000001058988952_p204881543202716"></a>20px</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p id="en-us_topic_0000001058988952_p728515431019"><a name="en-us_topic_0000001058988952_p728515431019"></a><a name="en-us_topic_0000001058988952_p728515431019"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="en-us_topic_0000001058988952_p13285354141014"><a name="en-us_topic_0000001058988952_p13285354141014"></a><a name="en-us_topic_0000001058988952_p13285354141014"></a>Font size of the selected item. The value is of the length type, in pixels.</p>
</td>
</tr>
<tr id="en-us_topic_0000001058988952_row113429202318"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="en-us_topic_0000001058988952_p9907142512314"><a name="en-us_topic_0000001058988952_p9907142512314"></a><a name="en-us_topic_0000001058988952_p9907142512314"></a>disappear-color<sup id="en-us_topic_0000001058988952_sup32414291368"><a name="en-us_topic_0000001058988952_sup32414291368"></a><a name="en-us_topic_0000001058988952_sup32414291368"></a>5+</sup></p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p id="en-us_topic_0000001058988952_p18907132520319"><a name="en-us_topic_0000001058988952_p18907132520319"></a><a name="en-us_topic_0000001058988952_p18907132520319"></a>&lt;color&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p id="en-us_topic_0000001058988952_p290772520317"><a name="en-us_topic_0000001058988952_p290772520317"></a><a name="en-us_topic_0000001058988952_p290772520317"></a>#ffffff</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p id="en-us_topic_0000001058988952_p990717258312"><a name="en-us_topic_0000001058988952_p990717258312"></a><a name="en-us_topic_0000001058988952_p990717258312"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="en-us_topic_0000001058988952_p190762513313"><a name="en-us_topic_0000001058988952_p190762513313"></a><a name="en-us_topic_0000001058988952_p190762513313"></a>Font color of the items that gradually disappear. Disappearing items are the top option and bottom option of a column containing five options in total.</p>
</td>
</tr>
<tr id="en-us_topic_0000001058988952_row191375231735"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="en-us_topic_0000001058988952_p17907925931"><a name="en-us_topic_0000001058988952_p17907925931"></a><a name="en-us_topic_0000001058988952_p17907925931"></a>disappear-font-size<sup id="en-us_topic_0000001058988952_sup4441838969"><a name="en-us_topic_0000001058988952_sup4441838969"></a><a name="en-us_topic_0000001058988952_sup4441838969"></a>5+</sup></p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p id="en-us_topic_0000001058988952_p179077251334"><a name="en-us_topic_0000001058988952_p179077251334"></a><a name="en-us_topic_0000001058988952_p179077251334"></a>&lt;length&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p id="en-us_topic_0000001058988952_p1690792517315"><a name="en-us_topic_0000001058988952_p1690792517315"></a><a name="en-us_topic_0000001058988952_p1690792517315"></a>14px</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p id="en-us_topic_0000001058988952_p8907125035"><a name="en-us_topic_0000001058988952_p8907125035"></a><a name="en-us_topic_0000001058988952_p8907125035"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="en-us_topic_0000001058988952_p1590772517315"><a name="en-us_topic_0000001058988952_p1590772517315"></a><a name="en-us_topic_0000001058988952_p1590772517315"></a>Font size of the items that gradually disappear. Disappearing items are the top option and bottom option of a column containing five options in total.</p>
</td>
</tr>
<tr id="en-us_topic_0000001058988952_row1980274191013"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="en-us_topic_0000001058988952_p1796816913103"><a name="en-us_topic_0000001058988952_p1796816913103"></a><a name="en-us_topic_0000001058988952_p1796816913103"></a>font-family</p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p id="en-us_topic_0000001058988952_p179691397103"><a name="en-us_topic_0000001058988952_p179691397103"></a><a name="en-us_topic_0000001058988952_p179691397103"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p id="en-us_topic_0000001058988952_p19695918107"><a name="en-us_topic_0000001058988952_p19695918107"></a><a name="en-us_topic_0000001058988952_p19695918107"></a>sans-serif</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p id="en-us_topic_0000001058988952_p179692918105"><a name="en-us_topic_0000001058988952_p179692918105"></a><a name="en-us_topic_0000001058988952_p179692918105"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="en-us_topic_0000001058988952_p7969799106"><a name="en-us_topic_0000001058988952_p7969799106"></a><a name="en-us_topic_0000001058988952_p7969799106"></a>Font type of an item. Font family, in which fonts are separated by commas (,). Each font is set using a font name or font family name. The first font in the family or the font specified in <a href="custom-font-styles.md#EN-US_TOPIC_0000001162414611">Custom Font Styles</a> is used for the text.</p>
</td>
</tr>
<tr id="en-us_topic_0000001058988952_row511415191109"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="en-us_topic_0000001058988952_en-us_topic_0000001059340528_a8bc81ecef4934adf91deb1d6167045d7"><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_a8bc81ecef4934adf91deb1d6167045d7"></a><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_a8bc81ecef4934adf91deb1d6167045d7"></a>width</p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p id="en-us_topic_0000001058988952_en-us_topic_0000001059340528_a59692217b9c94353a020a2f0a20f01a7"><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_a59692217b9c94353a020a2f0a20f01a7"></a><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_a59692217b9c94353a020a2f0a20f01a7"></a>&lt;length&gt; | &lt;percentage&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p id="en-us_topic_0000001058988952_en-us_topic_0000001059340528_p3948114217528"><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_p3948114217528"></a><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_p3948114217528"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p id="en-us_topic_0000001058988952_p1911451991018"><a name="en-us_topic_0000001058988952_p1911451991018"></a><a name="en-us_topic_0000001058988952_p1911451991018"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="en-us_topic_0000001058988952_en-us_topic_0000001059340528_p624653010258"><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_p624653010258"></a><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_p624653010258"></a>Component width.</p>
<p id="en-us_topic_0000001058988952_en-us_topic_0000001059340528_p84811050134010"><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_p84811050134010"></a><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_p84811050134010"></a>If this attribute is not set, the width required for the element content is used. </p>
</td>
</tr>
<tr id="en-us_topic_0000001058988952_row1311417191107"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="en-us_topic_0000001058988952_en-us_topic_0000001059340528_a738cc687552c4b8cb1aa9f9e7d9ea8c2"><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_a738cc687552c4b8cb1aa9f9e7d9ea8c2"></a><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_a738cc687552c4b8cb1aa9f9e7d9ea8c2"></a>height</p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p id="en-us_topic_0000001058988952_en-us_topic_0000001059340528_a82c5d9c65b3646ec92afe5f0f47a2149"><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_a82c5d9c65b3646ec92afe5f0f47a2149"></a><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_a82c5d9c65b3646ec92afe5f0f47a2149"></a>&lt;length&gt;<span id="en-us_topic_0000001058988952_en-us_topic_0000001059340528_ph11748352163918"><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_ph11748352163918"></a><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_ph11748352163918"></a></span> | &lt;percentage&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p id="en-us_topic_0000001058988952_en-us_topic_0000001059340528_a7e6c7daafecf475888d0420835662eb4"><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_a7e6c7daafecf475888d0420835662eb4"></a><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_a7e6c7daafecf475888d0420835662eb4"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p id="en-us_topic_0000001058988952_p141141219131018"><a name="en-us_topic_0000001058988952_p141141219131018"></a><a name="en-us_topic_0000001058988952_p141141219131018"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="en-us_topic_0000001058988952_en-us_topic_0000001059340528_p1477601264"><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_p1477601264"></a><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_p1477601264"></a>Component height.</p>
<p id="en-us_topic_0000001058988952_en-us_topic_0000001059340528_p208761554184020"><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_p208761554184020"></a><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_p208761554184020"></a>If this length attribute is not set, the length required for the element content is used. </p>
</td>
</tr>
<tr id="en-us_topic_0000001058988952_row1211571951015"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="en-us_topic_0000001058988952_en-us_topic_0000001059340528_a8ff18465b8f0453c836067e5902b7eb6"><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_a8ff18465b8f0453c836067e5902b7eb6"></a><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_a8ff18465b8f0453c836067e5902b7eb6"></a>padding</p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p id="en-us_topic_0000001058988952_en-us_topic_0000001059340528_a53628f36a25a4823a901d5b66860f44e"><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_a53628f36a25a4823a901d5b66860f44e"></a><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_a53628f36a25a4823a901d5b66860f44e"></a>&lt;length&gt; | &lt;percentage&gt;<sup id="en-us_topic_0000001058988952_en-us_topic_0000001059340528_sup1886516813013"><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_sup1886516813013"></a><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_sup1886516813013"></a>5+</sup></p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p id="en-us_topic_0000001058988952_en-us_topic_0000001059340528_adc824deaee924821a47a798b589f22c8"><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_adc824deaee924821a47a798b589f22c8"></a><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_adc824deaee924821a47a798b589f22c8"></a>0</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p id="en-us_topic_0000001058988952_en-us_topic_0000001059340528_p19729127112814"><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_p19729127112814"></a><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_p19729127112814"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="en-us_topic_0000001058988952_en-us_topic_0000001059340528_p157435053316"><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_p157435053316"></a><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_p157435053316"></a>Shorthand attribute to set all padding attributes.</p>
<div class="p" id="en-us_topic_0000001058988952_en-us_topic_0000001059340528_a68a6d5ddc59c49f0aaddd82e75932524"><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_a68a6d5ddc59c49f0aaddd82e75932524"></a><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_a68a6d5ddc59c49f0aaddd82e75932524"></a>The attribute can have one to four values:<a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_ul15202134923211"></a><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_ul15202134923211"></a><ul id="en-us_topic_0000001058988952_en-us_topic_0000001059340528_ul15202134923211"><li><p id="en-us_topic_0000001058988952_en-us_topic_0000001059340528_p10614155353215"><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_p10614155353215"></a><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_p10614155353215"></a>If you set only one value, it specifies the padding for four sides.</p>
</li><li><p id="en-us_topic_0000001058988952_en-us_topic_0000001059340528_p10614175393216"><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_p10614175393216"></a><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_p10614175393216"></a>If you set two values, the first value specifies the top and bottom padding, and the second value specifies the left and right padding.</p>
</li><li><p id="en-us_topic_0000001058988952_en-us_topic_0000001059340528_p8614205393214"><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_p8614205393214"></a><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_p8614205393214"></a>If you set three values, the first value specifies the top padding, the second value specifies the left and right padding, and the third value specifies the bottom padding.</p>
</li><li><p id="en-us_topic_0000001058988952_en-us_topic_0000001059340528_p106141853193215"><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_p106141853193215"></a><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_p106141853193215"></a>If you set four values, they respectively specify the padding for top, right, bottom, and left sides (in clockwise order).</p>
</li></ul>
</div>
</td>
</tr>
<tr id="en-us_topic_0000001058988952_row19115121921016"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="en-us_topic_0000001058988952_en-us_topic_0000001059340528_ab0185a7b5a4944f3b38f8c71c8ca794d"><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_ab0185a7b5a4944f3b38f8c71c8ca794d"></a><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_ab0185a7b5a4944f3b38f8c71c8ca794d"></a>padding-[left|top|right|bottom]</p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p id="en-us_topic_0000001058988952_en-us_topic_0000001059340528_a49dd523e2f1b4253a19231e776dc1951"><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_a49dd523e2f1b4253a19231e776dc1951"></a><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_a49dd523e2f1b4253a19231e776dc1951"></a>&lt;length&gt; | &lt;percentage&gt;<sup id="en-us_topic_0000001058988952_en-us_topic_0000001059340528_sup19949912807"><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_sup19949912807"></a><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_sup19949912807"></a>5+</sup></p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p id="en-us_topic_0000001058988952_en-us_topic_0000001059340528_af52ecd93919b4fa08ae4d376e3d544a2"><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_af52ecd93919b4fa08ae4d376e3d544a2"></a><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_af52ecd93919b4fa08ae4d376e3d544a2"></a>0</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p id="en-us_topic_0000001058988952_en-us_topic_0000001059340528_p11729374289"><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_p11729374289"></a><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_p11729374289"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="en-us_topic_0000001058988952_en-us_topic_0000001059340528_a3575ab240d384ab1a21119ea3428ab7d"><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_a3575ab240d384ab1a21119ea3428ab7d"></a><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_a3575ab240d384ab1a21119ea3428ab7d"></a>Left, top, right, and bottom padding (in px).</p>
</td>
</tr>
<tr id="en-us_topic_0000001058988952_row111631915102"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="en-us_topic_0000001058988952_en-us_topic_0000001059340528_p769124717365"><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_p769124717365"></a><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_p769124717365"></a>padding-[start|end]</p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p id="en-us_topic_0000001058988952_en-us_topic_0000001059340528_p157617124374"><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_p157617124374"></a><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_p157617124374"></a>&lt;length&gt; | &lt;percentage&gt;<sup id="en-us_topic_0000001058988952_en-us_topic_0000001059340528_sup8490161513019"><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_sup8490161513019"></a><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_sup8490161513019"></a>5+</sup></p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p id="en-us_topic_0000001058988952_en-us_topic_0000001059340528_p1069144703616"><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_p1069144703616"></a><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_p1069144703616"></a>0</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p id="en-us_topic_0000001058988952_en-us_topic_0000001059340528_p1373027182819"><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_p1373027182819"></a><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_p1373027182819"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="en-us_topic_0000001058988952_en-us_topic_0000001059340528_p1269184753610"><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_p1269184753610"></a><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_p1269184753610"></a>Start and end padding.</p>
</td>
</tr>
<tr id="en-us_topic_0000001058988952_row1711681901013"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="en-us_topic_0000001058988952_en-us_topic_0000001059340528_afa508e5429d948b2b561943d6b2f0f31"><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_afa508e5429d948b2b561943d6b2f0f31"></a><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_afa508e5429d948b2b561943d6b2f0f31"></a>margin</p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p id="en-us_topic_0000001058988952_en-us_topic_0000001059340528_a4dab4f9d97a74a27a45b7ef1d2ab08e6"><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_a4dab4f9d97a74a27a45b7ef1d2ab08e6"></a><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_a4dab4f9d97a74a27a45b7ef1d2ab08e6"></a>&lt;length&gt; | &lt;percentage&gt;<sup id="en-us_topic_0000001058988952_en-us_topic_0000001059340528_sup1433352175220"><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_sup1433352175220"></a><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_sup1433352175220"></a>5+</sup></p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p id="en-us_topic_0000001058988952_en-us_topic_0000001059340528_a5e3c234d78214e8180b51d237adda154"><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_a5e3c234d78214e8180b51d237adda154"></a><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_a5e3c234d78214e8180b51d237adda154"></a>0</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p id="en-us_topic_0000001058988952_en-us_topic_0000001059340528_p4730774285"><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_p4730774285"></a><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_p4730774285"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="en-us_topic_0000001058988952_en-us_topic_0000001059340528_a1d350e36a773420baf5ebb930cd5ad66"><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_a1d350e36a773420baf5ebb930cd5ad66"></a><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_a1d350e36a773420baf5ebb930cd5ad66"></a>Shorthand attribute to set margins for all sides in a declaration. The attribute can have one to four values:</p>
<a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_ul5333133311105"></a><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_ul5333133311105"></a><ul id="en-us_topic_0000001058988952_en-us_topic_0000001059340528_ul5333133311105"><li><p id="en-us_topic_0000001058988952_en-us_topic_0000001059340528_p03345339103"><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_p03345339103"></a><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_p03345339103"></a>If you set only one value, it specifies the margin for all the four sides.</p>
</li><li><p id="en-us_topic_0000001058988952_en-us_topic_0000001059340528_p1133420334108"><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_p1133420334108"></a><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_p1133420334108"></a>If you set two values, the first value is for the top and bottom sides and the second value for the left and right sides.</p>
</li><li><p id="en-us_topic_0000001058988952_en-us_topic_0000001059340528_p193341533191015"><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_p193341533191015"></a><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_p193341533191015"></a>If you set three values, the first value is for the top, the second value for the left and right, and the third value for the bottom.</p>
</li><li><p id="en-us_topic_0000001058988952_en-us_topic_0000001059340528_p733412334102"><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_p733412334102"></a><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_p733412334102"></a>If you set four values, they are margins for top, right, bottom, and left sides, respectively.</p>
</li></ul>
</td>
</tr>
<tr id="en-us_topic_0000001058988952_row18117161920106"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="en-us_topic_0000001058988952_en-us_topic_0000001059340528_a70939a36b2b04dd8bec21f5bddc8637e"><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_a70939a36b2b04dd8bec21f5bddc8637e"></a><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_a70939a36b2b04dd8bec21f5bddc8637e"></a>margin-[left|top|right|bottom]</p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p id="en-us_topic_0000001058988952_en-us_topic_0000001059340528_ae53ac9ac370d483990e04ea9789c1e49"><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_ae53ac9ac370d483990e04ea9789c1e49"></a><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_ae53ac9ac370d483990e04ea9789c1e49"></a>&lt;length&gt; | &lt;percentage&gt;<sup id="en-us_topic_0000001058988952_en-us_topic_0000001059340528_sup378331720532"><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_sup378331720532"></a><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_sup378331720532"></a>5+</sup></p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p id="en-us_topic_0000001058988952_en-us_topic_0000001059340528_a180cd037e6174e5c82f35a3a66b6f2ec"><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_a180cd037e6174e5c82f35a3a66b6f2ec"></a><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_a180cd037e6174e5c82f35a3a66b6f2ec"></a>0</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p id="en-us_topic_0000001058988952_en-us_topic_0000001059340528_p773013742811"><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_p773013742811"></a><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_p773013742811"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="en-us_topic_0000001058988952_en-us_topic_0000001059340528_a487d09add6e54c5c89fa4f22e9318271"><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_a487d09add6e54c5c89fa4f22e9318271"></a><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_a487d09add6e54c5c89fa4f22e9318271"></a>Left, top, right, and bottom margins.</p>
</td>
</tr>
<tr id="en-us_topic_0000001058988952_row14117181910105"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="en-us_topic_0000001058988952_en-us_topic_0000001059340528_p9492107123816"><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_p9492107123816"></a><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_p9492107123816"></a>margin-[start|end]</p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p id="en-us_topic_0000001058988952_en-us_topic_0000001059340528_p157617124374_1"><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_p157617124374_1"></a><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_p157617124374_1"></a>&lt;length&gt; | &lt;percentage&gt;<sup id="en-us_topic_0000001058988952_en-us_topic_0000001059340528_sup8490161513019_1"><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_sup8490161513019_1"></a><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_sup8490161513019_1"></a>5+</sup></p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p id="en-us_topic_0000001058988952_en-us_topic_0000001059340528_p1549213793811"><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_p1549213793811"></a><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_p1549213793811"></a>0</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p id="en-us_topic_0000001058988952_p171171219161016"><a name="en-us_topic_0000001058988952_p171171219161016"></a><a name="en-us_topic_0000001058988952_p171171219161016"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="en-us_topic_0000001058988952_en-us_topic_0000001059340528_p1049212715388"><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_p1049212715388"></a><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_p1049212715388"></a>Start and end margins.</p>
</td>
</tr>
<tr id="en-us_topic_0000001058988952_row1411710190107"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="en-us_topic_0000001058988952_en-us_topic_0000001059340528_a222bb48f24014f2eb2b16a1a840bbebb"><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_a222bb48f24014f2eb2b16a1a840bbebb"></a><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_a222bb48f24014f2eb2b16a1a840bbebb"></a>border</p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p id="en-us_topic_0000001058988952_en-us_topic_0000001059340528_a79b4eaf9983c44d0aad39ff04d0997a8"><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_a79b4eaf9983c44d0aad39ff04d0997a8"></a><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_a79b4eaf9983c44d0aad39ff04d0997a8"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p id="en-us_topic_0000001058988952_en-us_topic_0000001059340528_aac320f4f0a42401aa7fa778d9829d77c"><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_aac320f4f0a42401aa7fa778d9829d77c"></a><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_aac320f4f0a42401aa7fa778d9829d77c"></a>0</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p id="en-us_topic_0000001058988952_p1911851919109"><a name="en-us_topic_0000001058988952_p1911851919109"></a><a name="en-us_topic_0000001058988952_p1911851919109"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="en-us_topic_0000001058988952_en-us_topic_0000001059340528_a9cd962871a4c467a8e1ef452621d5cd7"><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_a9cd962871a4c467a8e1ef452621d5cd7"></a><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_a9cd962871a4c467a8e1ef452621d5cd7"></a>Shorthand attribute to set all borders. You can set <strong id="en-us_topic_0000001058988952_en-us_topic_0000001059340528_b79128342503"><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_b79128342503"></a><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_b79128342503"></a>border-width</strong>, <strong id="en-us_topic_0000001058988952_en-us_topic_0000001059340528_b9366173919505"><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_b9366173919505"></a><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_b9366173919505"></a>border-style</strong>, and <strong id="en-us_topic_0000001058988952_en-us_topic_0000001059340528_b184351248205019"><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_b184351248205019"></a><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_b184351248205019"></a>border-color</strong> in sequence. Default values are used for attributes that are not set.</p>
</td>
</tr>
<tr id="en-us_topic_0000001058988952_row411881914105"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="en-us_topic_0000001058988952_en-us_topic_0000001059340528_a987708c0864a4128af094334f1b024b3"><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_a987708c0864a4128af094334f1b024b3"></a><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_a987708c0864a4128af094334f1b024b3"></a>border-style</p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p id="en-us_topic_0000001058988952_en-us_topic_0000001059340528_p513631613319"><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_p513631613319"></a><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_p513631613319"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p id="en-us_topic_0000001058988952_en-us_topic_0000001059340528_a2567083af59c40e58e3e4d9b0ddf1485"><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_a2567083af59c40e58e3e4d9b0ddf1485"></a><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_a2567083af59c40e58e3e4d9b0ddf1485"></a>solid</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p id="en-us_topic_0000001058988952_p0118519171015"><a name="en-us_topic_0000001058988952_p0118519171015"></a><a name="en-us_topic_0000001058988952_p0118519171015"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="en-us_topic_0000001058988952_en-us_topic_0000001059340528_p342285712314"><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_p342285712314"></a><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_p342285712314"></a>Shorthand attribute to set the style for all borders. Available values are as follows:</p>
<a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_ul1470834505612"></a><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_ul1470834505612"></a><ul id="en-us_topic_0000001058988952_en-us_topic_0000001059340528_ul1470834505612"><li><strong id="en-us_topic_0000001058988952_en-us_topic_0000001059340528_b143453286360"><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_b143453286360"></a><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_b143453286360"></a>dotted</strong>: Dotted border. The radius of a dot is half of border-width.</li><li><strong id="en-us_topic_0000001058988952_en-us_topic_0000001059340528_b792117280367"><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_b792117280367"></a><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_b792117280367"></a>dashed</strong>: Dashed border</li></ul>
<a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_ul15621125545612"></a><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_ul15621125545612"></a><ul id="en-us_topic_0000001058988952_en-us_topic_0000001059340528_ul15621125545612"><li><strong id="en-us_topic_0000001058988952_en-us_topic_0000001059340528_b1335862963610"><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_b1335862963610"></a><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_b1335862963610"></a>solid</strong>: Solid border</li></ul>
</td>
</tr>
<tr id="en-us_topic_0000001058988952_row15118141919102"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="en-us_topic_0000001058988952_en-us_topic_0000001059340528_p119531437370"><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_p119531437370"></a><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_p119531437370"></a>border-[left|top|right|bottom]-style</p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p id="en-us_topic_0000001058988952_en-us_topic_0000001059340528_p129532037175"><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_p129532037175"></a><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_p129532037175"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p id="en-us_topic_0000001058988952_en-us_topic_0000001059340528_p495312372717"><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_p495312372717"></a><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_p495312372717"></a>solid</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p id="en-us_topic_0000001058988952_en-us_topic_0000001059340528_p169534375717"><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_p169534375717"></a><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_p169534375717"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="en-us_topic_0000001058988952_en-us_topic_0000001059340528_p595353718719"><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_p595353718719"></a><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_p595353718719"></a>Styles of the left, top, right, and bottom borders. The available values are <strong id="en-us_topic_0000001058988952_en-us_topic_0000001059340528_b17769171311540"><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_b17769171311540"></a><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_b17769171311540"></a>dotted</strong>, <strong id="en-us_topic_0000001058988952_en-us_topic_0000001059340528_b237141519547"><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_b237141519547"></a><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_b237141519547"></a>dashed</strong>, and <strong id="en-us_topic_0000001058988952_en-us_topic_0000001059340528_b8949161613540"><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_b8949161613540"></a><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_b8949161613540"></a>solid</strong>.</p>
</td>
</tr>
<tr id="en-us_topic_0000001058988952_row8119111971010"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="en-us_topic_0000001058988952_en-us_topic_0000001059340528_a8afd82b1aba547d3b0188b749518b2de"><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_a8afd82b1aba547d3b0188b749518b2de"></a><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_a8afd82b1aba547d3b0188b749518b2de"></a>border-[left|top|right|bottom]</p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p id="en-us_topic_0000001058988952_en-us_topic_0000001059340528_ac4b8a3b39e5446b5868f1f2989dc9590"><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_ac4b8a3b39e5446b5868f1f2989dc9590"></a><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_ac4b8a3b39e5446b5868f1f2989dc9590"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p id="en-us_topic_0000001058988952_en-us_topic_0000001059340528_a3420bc82bd17458ab82fa996ade7064c"><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_a3420bc82bd17458ab82fa996ade7064c"></a><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_a3420bc82bd17458ab82fa996ade7064c"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p id="en-us_topic_0000001058988952_en-us_topic_0000001059340528_p67303762810"><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_p67303762810"></a><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_p67303762810"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="en-us_topic_0000001058988952_en-us_topic_0000001059340528_af4178a066c344412afbd38f4b0c44818"><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_af4178a066c344412afbd38f4b0c44818"></a><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_af4178a066c344412afbd38f4b0c44818"></a>Shorthand attribute to set the borders for every side respectively. You can set <strong id="en-us_topic_0000001058988952_en-us_topic_0000001059340528_b122415514554"><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_b122415514554"></a><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_b122415514554"></a>border-width</strong>, <strong id="en-us_topic_0000001058988952_en-us_topic_0000001059340528_b12296178135513"><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_b12296178135513"></a><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_b12296178135513"></a>border-style</strong>, and <strong id="en-us_topic_0000001058988952_en-us_topic_0000001059340528_b1129701210553"><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_b1129701210553"></a><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_b1129701210553"></a>border-color</strong> in sequence. Default values are used for attributes that are not set.</p>
</td>
</tr>
<tr id="en-us_topic_0000001058988952_row17119719131017"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="en-us_topic_0000001058988952_en-us_topic_0000001059340528_adf0e0afedc774afca9cda0e509391029"><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_adf0e0afedc774afca9cda0e509391029"></a><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_adf0e0afedc774afca9cda0e509391029"></a>border-width</p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p id="en-us_topic_0000001058988952_en-us_topic_0000001059340528_a0782ea2c45eb4864a8df82f30dd2cd5f"><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_a0782ea2c45eb4864a8df82f30dd2cd5f"></a><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_a0782ea2c45eb4864a8df82f30dd2cd5f"></a>&lt;length&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p id="en-us_topic_0000001058988952_en-us_topic_0000001059340528_a395cbedd521145bd820b9171ee2dd7ac"><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_a395cbedd521145bd820b9171ee2dd7ac"></a><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_a395cbedd521145bd820b9171ee2dd7ac"></a>0</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p id="en-us_topic_0000001058988952_p1912017193102"><a name="en-us_topic_0000001058988952_p1912017193102"></a><a name="en-us_topic_0000001058988952_p1912017193102"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="en-us_topic_0000001058988952_en-us_topic_0000001059340528_a7ae60621ea3341818a03bfdffa641894"><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_a7ae60621ea3341818a03bfdffa641894"></a><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_a7ae60621ea3341818a03bfdffa641894"></a>Shorthand attribute to set the width of all borders<span id="en-us_topic_0000001058988952_en-us_topic_0000001059340528_ph07997369365"><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_ph07997369365"></a><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_ph07997369365"></a>, or separately set the width of each border</span>.</p>
</td>
</tr>
<tr id="en-us_topic_0000001058988952_row1912051911100"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="en-us_topic_0000001058988952_en-us_topic_0000001059340528_a7371edc07c664266a2e1866f31ad0d0c"><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_a7371edc07c664266a2e1866f31ad0d0c"></a><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_a7371edc07c664266a2e1866f31ad0d0c"></a>border-[left|top|right|bottom]-width</p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p id="en-us_topic_0000001058988952_en-us_topic_0000001059340528_a2faa532b841948a7b6598542b4eccc7b"><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_a2faa532b841948a7b6598542b4eccc7b"></a><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_a2faa532b841948a7b6598542b4eccc7b"></a>&lt;length&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p id="en-us_topic_0000001058988952_en-us_topic_0000001059340528_a87f38cfa47f54bc18c32f9671c0f9ca6"><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_a87f38cfa47f54bc18c32f9671c0f9ca6"></a><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_a87f38cfa47f54bc18c32f9671c0f9ca6"></a>0</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p id="en-us_topic_0000001058988952_p111201719151010"><a name="en-us_topic_0000001058988952_p111201719151010"></a><a name="en-us_topic_0000001058988952_p111201719151010"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="en-us_topic_0000001058988952_en-us_topic_0000001059340528_a20386e66c3834d5f96cf9435c4715c5b"><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_a20386e66c3834d5f96cf9435c4715c5b"></a><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_a20386e66c3834d5f96cf9435c4715c5b"></a>Attribute to set widths of left, top, right, and bottom borders.</p>
</td>
</tr>
<tr id="en-us_topic_0000001058988952_row61201319131014"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="en-us_topic_0000001058988952_en-us_topic_0000001059340528_a40a816cf0a03489d81f209a8aa7d81a6"><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_a40a816cf0a03489d81f209a8aa7d81a6"></a><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_a40a816cf0a03489d81f209a8aa7d81a6"></a>border-color</p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p id="en-us_topic_0000001058988952_en-us_topic_0000001059340528_afcc7c948ae0947b2a78002d31f2f9748"><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_afcc7c948ae0947b2a78002d31f2f9748"></a><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_afcc7c948ae0947b2a78002d31f2f9748"></a>&lt;color&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p id="en-us_topic_0000001058988952_en-us_topic_0000001059340528_ae0909d2b896342f9b2196fe0dce72920"><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_ae0909d2b896342f9b2196fe0dce72920"></a><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_ae0909d2b896342f9b2196fe0dce72920"></a>black</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p id="en-us_topic_0000001058988952_p212016198103"><a name="en-us_topic_0000001058988952_p212016198103"></a><a name="en-us_topic_0000001058988952_p212016198103"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="en-us_topic_0000001058988952_en-us_topic_0000001059340528_a76fd98995e1d4217aa703fecd69325c7"><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_a76fd98995e1d4217aa703fecd69325c7"></a><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_a76fd98995e1d4217aa703fecd69325c7"></a>Shorthand attribute to set the color of all borders<span id="en-us_topic_0000001058988952_en-us_topic_0000001059340528_ph9587639113619"><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_ph9587639113619"></a><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_ph9587639113619"></a>, or separately set the color of each border</span>.</p>
</td>
</tr>
<tr id="en-us_topic_0000001058988952_row212031961010"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="en-us_topic_0000001058988952_en-us_topic_0000001059340528_a2afc646d6a2549548bcd5c4b9bed1fb5"><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_a2afc646d6a2549548bcd5c4b9bed1fb5"></a><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_a2afc646d6a2549548bcd5c4b9bed1fb5"></a>border-[left|top|right|bottom]-color</p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p id="en-us_topic_0000001058988952_en-us_topic_0000001059340528_a34556866a4f54f5da88f148fc698867b"><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_a34556866a4f54f5da88f148fc698867b"></a><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_a34556866a4f54f5da88f148fc698867b"></a>&lt;color&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p id="en-us_topic_0000001058988952_en-us_topic_0000001059340528_a8ff58e18553846a38e82c69149e2aa30"><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_a8ff58e18553846a38e82c69149e2aa30"></a><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_a8ff58e18553846a38e82c69149e2aa30"></a>black</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p id="en-us_topic_0000001058988952_p17121919111015"><a name="en-us_topic_0000001058988952_p17121919111015"></a><a name="en-us_topic_0000001058988952_p17121919111015"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="en-us_topic_0000001058988952_en-us_topic_0000001059340528_a5c85947d388c4c7fbf0de07b022bb44e"><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_a5c85947d388c4c7fbf0de07b022bb44e"></a><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_a5c85947d388c4c7fbf0de07b022bb44e"></a>Attribute to set colors of left, top, right, and bottom borders.</p>
</td>
</tr>
<tr id="en-us_topic_0000001058988952_row7121919181020"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="en-us_topic_0000001058988952_en-us_topic_0000001059340528_a65974e3078c447a383fb9237cc4ffa32"><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_a65974e3078c447a383fb9237cc4ffa32"></a><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_a65974e3078c447a383fb9237cc4ffa32"></a>border-radius</p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p id="en-us_topic_0000001058988952_en-us_topic_0000001059340528_a413fd0aea8b243349a19f825e96ee8b6"><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_a413fd0aea8b243349a19f825e96ee8b6"></a><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_a413fd0aea8b243349a19f825e96ee8b6"></a>&lt;length&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p id="en-us_topic_0000001058988952_en-us_topic_0000001059340528_af786857698c74e259f52589a6670a0a1"><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_af786857698c74e259f52589a6670a0a1"></a><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_af786857698c74e259f52589a6670a0a1"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p id="en-us_topic_0000001058988952_en-us_topic_0000001059340528_p67306752816"><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_p67306752816"></a><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_p67306752816"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="en-us_topic_0000001058988952_en-us_topic_0000001059340528_a52ca834f42124d3b8b12bbf54914fc96"><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_a52ca834f42124d3b8b12bbf54914fc96"></a><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_a52ca834f42124d3b8b12bbf54914fc96"></a>Attribute to set the radius of round borders of an element. <span id="en-us_topic_0000001058988952_en-us_topic_0000001059340528_ph1249443123611"><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_ph1249443123611"></a><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_ph1249443123611"></a>This attribute cannot be used to set the width, color, or style of a specific border. To set the width or color, you need to set <strong id="en-us_topic_0000001058988952_en-us_topic_0000001059340528_b124211434362"><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_b124211434362"></a><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_b124211434362"></a>border-width</strong>, <strong id="en-us_topic_0000001058988952_en-us_topic_0000001059340528_b124894383615"><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_b124894383615"></a><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_b124894383615"></a>border-color</strong>, or <strong id="en-us_topic_0000001058988952_en-us_topic_0000001059340528_b7166134516465"><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_b7166134516465"></a><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_b7166134516465"></a>border-style</strong> for all the borders at the same time.</span></p>
</td>
</tr>
<tr id="en-us_topic_0000001058988952_row5121151961016"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="en-us_topic_0000001058988952_en-us_topic_0000001059340528_a466f1f8bc2fb404e82e8417c5133eacb"><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_a466f1f8bc2fb404e82e8417c5133eacb"></a><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_a466f1f8bc2fb404e82e8417c5133eacb"></a>border-[top|bottom]-[left|right]-radius</p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p id="en-us_topic_0000001058988952_en-us_topic_0000001059340528_a499fe910d0284647abc48b1bd0eb4868"><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_a499fe910d0284647abc48b1bd0eb4868"></a><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_a499fe910d0284647abc48b1bd0eb4868"></a>&lt;length&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p id="en-us_topic_0000001058988952_en-us_topic_0000001059340528_ac142d1054eee499f948069f46129c492"><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_ac142d1054eee499f948069f46129c492"></a><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_ac142d1054eee499f948069f46129c492"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p id="en-us_topic_0000001058988952_en-us_topic_0000001059340528_p27305718283"><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_p27305718283"></a><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_p27305718283"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="en-us_topic_0000001058988952_en-us_topic_0000001059340528_a63757091a86c4ced97f0c39d37a2117c"><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_a63757091a86c4ced97f0c39d37a2117c"></a><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_a63757091a86c4ced97f0c39d37a2117c"></a>Attribute to receptively set the radii of upper-left, upper-right, lower-right, and lower-left rounded corners</p>
</td>
</tr>
<tr id="en-us_topic_0000001058988952_row61211319111013"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="en-us_topic_0000001058988952_en-us_topic_0000001059340528_ae335be2c6150440fb31b40b1ca117858"><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_ae335be2c6150440fb31b40b1ca117858"></a><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_ae335be2c6150440fb31b40b1ca117858"></a>background</p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p id="en-us_topic_0000001058988952_en-us_topic_0000001059340528_a394a81171c5c4d1aa81b94fc5d2f0f07"><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_a394a81171c5c4d1aa81b94fc5d2f0f07"></a><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_a394a81171c5c4d1aa81b94fc5d2f0f07"></a>&lt;linear-gradient&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p id="en-us_topic_0000001058988952_en-us_topic_0000001059340528_a0734de04e90e470cb608e8d5f42c6874"><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_a0734de04e90e470cb608e8d5f42c6874"></a><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_a0734de04e90e470cb608e8d5f42c6874"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p id="en-us_topic_0000001058988952_en-us_topic_0000001059340528_p15730197132811"><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_p15730197132811"></a><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_p15730197132811"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="en-us_topic_0000001058988952_en-us_topic_0000001059340528_a1d2985ee819d4cfd87861080354def51"><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_a1d2985ee819d4cfd87861080354def51"></a><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_a1d2985ee819d4cfd87861080354def51"></a>This attribute supports <a href="gradient-styles.md#EN-US_TOPIC_0000001115974726">Gradient Styles</a> only but is not compatible with <strong id="en-us_topic_0000001058988952_en-us_topic_0000001059340528_b389373419292"><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_b389373419292"></a><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_b389373419292"></a>background-color</strong> or <strong id="en-us_topic_0000001058988952_en-us_topic_0000001059340528_b0399637142918"><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_b0399637142918"></a><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_b0399637142918"></a>background-image</strong>.</p>
</td>
</tr>
<tr id="en-us_topic_0000001058988952_row121221119171011"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="en-us_topic_0000001058988952_en-us_topic_0000001059340528_a2977672444224b738a566c61225961c2"><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_a2977672444224b738a566c61225961c2"></a><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_a2977672444224b738a566c61225961c2"></a>background-color</p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p id="en-us_topic_0000001058988952_en-us_topic_0000001059340528_a87186748ed7c4694aef0095d8a7f8e43"><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_a87186748ed7c4694aef0095d8a7f8e43"></a><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_a87186748ed7c4694aef0095d8a7f8e43"></a>&lt;color&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p id="en-us_topic_0000001058988952_en-us_topic_0000001059340528_a2775a3cca8994bec9b754af0d2455eb5"><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_a2775a3cca8994bec9b754af0d2455eb5"></a><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_a2775a3cca8994bec9b754af0d2455eb5"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p id="en-us_topic_0000001058988952_en-us_topic_0000001059340528_p17730577282"><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_p17730577282"></a><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_p17730577282"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="en-us_topic_0000001058988952_en-us_topic_0000001059340528_a372b6089bf9746f091c91fa49b571f1d"><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_a372b6089bf9746f091c91fa49b571f1d"></a><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_a372b6089bf9746f091c91fa49b571f1d"></a>Background color.</p>
</td>
</tr>
<tr id="en-us_topic_0000001058988952_row0122151991011"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="en-us_topic_0000001058988952_en-us_topic_0000001059340528_ab2dff80cd59c4db1bf4293172f89735e"><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_ab2dff80cd59c4db1bf4293172f89735e"></a><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_ab2dff80cd59c4db1bf4293172f89735e"></a>background-image</p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p id="en-us_topic_0000001058988952_en-us_topic_0000001059340528_ad9a7e9f2469b45238a6a0ac6da232286"><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_ad9a7e9f2469b45238a6a0ac6da232286"></a><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_ad9a7e9f2469b45238a6a0ac6da232286"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p id="en-us_topic_0000001058988952_en-us_topic_0000001059340528_a73fb72c96edd488ba74c364568e345c6"><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_a73fb72c96edd488ba74c364568e345c6"></a><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_a73fb72c96edd488ba74c364568e345c6"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p id="en-us_topic_0000001058988952_en-us_topic_0000001059340528_p7730976285"><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_p7730976285"></a><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_p7730976285"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="en-us_topic_0000001058988952_en-us_topic_0000001059340528_a24de29e3cb4d476fabe55d48d69350a8"><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_a24de29e3cb4d476fabe55d48d69350a8"></a><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_a24de29e3cb4d476fabe55d48d69350a8"></a>Background image. Currently, this attribute is not compatible with <strong id="en-us_topic_0000001058988952_en-us_topic_0000001059340528_b17699154763620"><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_b17699154763620"></a><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_b17699154763620"></a>background-color</strong> or <strong id="en-us_topic_0000001058988952_en-us_topic_0000001059340528_b87001647163613"><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_b87001647163613"></a><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_b87001647163613"></a>background</strong>. Local image resources are supported.</p>
<p id="en-us_topic_0000001058988952_en-us_topic_0000001059340528_p45914251572"><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_p45914251572"></a><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_p45914251572"></a>Example:</p>
<p id="en-us_topic_0000001058988952_en-us_topic_0000001059340528_p16184973578"><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_p16184973578"></a><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_p16184973578"></a>background-image: url("/common/background.png")</p>
</td>
</tr>
<tr id="en-us_topic_0000001058988952_row1112341916103"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="en-us_topic_0000001058988952_en-us_topic_0000001059340528_af81424fd1fbf4f5da65ea5d136390494"><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_af81424fd1fbf4f5da65ea5d136390494"></a><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_af81424fd1fbf4f5da65ea5d136390494"></a>background-size</p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_ul1065173641310"></a><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_ul1065173641310"></a><ul id="en-us_topic_0000001058988952_en-us_topic_0000001059340528_ul1065173641310"><li>string</li><li>&lt;length&gt; &lt;length&gt;</li><li>&lt;percentage&gt; &lt;percentage&gt;</li></ul>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p id="en-us_topic_0000001058988952_en-us_topic_0000001059340528_a222f4e09239a4ab08880d1d9544d337c"><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_a222f4e09239a4ab08880d1d9544d337c"></a><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_a222f4e09239a4ab08880d1d9544d337c"></a>auto</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p id="en-us_topic_0000001058988952_en-us_topic_0000001059340528_p137309714282"><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_p137309714282"></a><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_p137309714282"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="en-us_topic_0000001058988952_en-us_topic_0000001059340528_p91971112114318"><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_p91971112114318"></a><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_p91971112114318"></a>Background image size.</p>
<a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_ul41331853154111"></a><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_ul41331853154111"></a><ul id="en-us_topic_0000001058988952_en-us_topic_0000001059340528_ul41331853154111"><li>The <strong id="en-us_topic_0000001058988952_en-us_topic_0000001059340528_b1229715499365"><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_b1229715499365"></a><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_b1229715499365"></a>string</strong> values are as follows:<a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_ul13611494111"></a><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_ul13611494111"></a><ul id="en-us_topic_0000001058988952_en-us_topic_0000001059340528_ul13611494111"><li><strong id="en-us_topic_0000001058988952_en-us_topic_0000001059340528_b4759749163610"><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_b4759749163610"></a><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_b4759749163610"></a>contain</strong>: Expands the image to the maximum size so that the height and width of the image are applicable to the content area.</li><li><strong id="en-us_topic_0000001058988952_en-us_topic_0000001059340528_b437619381712"><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_b437619381712"></a><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_b437619381712"></a>cover</strong>: Extends the background image to a large enough size so that the background image completely covers the background area. Some parts of the image may not be displayed in the background area.</li><li><strong id="en-us_topic_0000001058988952_en-us_topic_0000001059340528_b1425512535366"><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_b1425512535366"></a><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_b1425512535366"></a>auto</strong>: The original image width-height ratio is retained.</li></ul>
</li><li>The two <strong id="en-us_topic_0000001058988952_en-us_topic_0000001059340528_b13309145193614"><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_b13309145193614"></a><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_b13309145193614"></a>&lt;length&gt;</strong> values are as follows:<p id="en-us_topic_0000001058988952_en-us_topic_0000001059340528_p1840244924418"><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_p1840244924418"></a><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_p1840244924418"></a>Width and height of the background image. The first value indicates the width, and the second value indicates the height. If you only set one value, the other value is set to <strong id="en-us_topic_0000001058988952_en-us_topic_0000001059340528_b146661156143617"><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_b146661156143617"></a><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_b146661156143617"></a>auto</strong> by default.</p>
</li><li>The two <strong id="en-us_topic_0000001058988952_en-us_topic_0000001059340528_b1667415763613"><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_b1667415763613"></a><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_b1667415763613"></a>&lt;percentage&gt;</strong> values are as follows:<p id="en-us_topic_0000001058988952_en-us_topic_0000001059340528_p17936154410457"><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_p17936154410457"></a><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_p17936154410457"></a>Width and height of the background image in percentage of the parent element. The first value indicates the width, and the second value indicates the height. If you only set one value, the other value is set to <strong id="en-us_topic_0000001058988952_en-us_topic_0000001059340528_b1524319254"><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_b1524319254"></a><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_b1524319254"></a>auto</strong> by default.</p>
</li></ul>
</td>
</tr>
<tr id="en-us_topic_0000001058988952_row412418198105"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="en-us_topic_0000001058988952_en-us_topic_0000001059340528_a9957170386754fb5b648ba2114bd52d4"><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_a9957170386754fb5b648ba2114bd52d4"></a><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_a9957170386754fb5b648ba2114bd52d4"></a>background-repeat</p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p id="en-us_topic_0000001058988952_en-us_topic_0000001059340528_a155b4cc325e747279694d36c2fa69bcc"><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_a155b4cc325e747279694d36c2fa69bcc"></a><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_a155b4cc325e747279694d36c2fa69bcc"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p id="en-us_topic_0000001058988952_en-us_topic_0000001059340528_a82029c0dc1d540cf994f690b451c48f4"><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_a82029c0dc1d540cf994f690b451c48f4"></a><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_a82029c0dc1d540cf994f690b451c48f4"></a>repeat</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p id="en-us_topic_0000001058988952_en-us_topic_0000001059340528_p1673015702810"><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_p1673015702810"></a><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_p1673015702810"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="en-us_topic_0000001058988952_en-us_topic_0000001059340528_afb8e41c117884b368a0f1df348be8e54"><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_afb8e41c117884b368a0f1df348be8e54"></a><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_afb8e41c117884b368a0f1df348be8e54"></a>How a background image is repeatedly drawn. By default, a background image is repeated both horizontally and vertically.</p>
<a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_ul8236153103612"></a><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_ul8236153103612"></a><ul id="en-us_topic_0000001058988952_en-us_topic_0000001059340528_ul8236153103612"><li><strong id="en-us_topic_0000001058988952_en-us_topic_0000001059340528_b1363463710"><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_b1363463710"></a><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_b1363463710"></a>repeat</strong>: Repeatedly draws images along the x-axis and y-axis at the same time.</li><li><strong id="en-us_topic_0000001058988952_en-us_topic_0000001059340528_b267416916377"><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_b267416916377"></a><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_b267416916377"></a>repeat-x</strong>: Repeatedly draws images along the x-axis.</li><li><strong id="en-us_topic_0000001058988952_en-us_topic_0000001059340528_b625561011379"><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_b625561011379"></a><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_b625561011379"></a>repeat-y</strong>: Repeatedly draws images along the y-axis.</li><li><strong id="en-us_topic_0000001058988952_en-us_topic_0000001059340528_b1122181133715"><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_b1122181133715"></a><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_b1122181133715"></a>no-repeat</strong>: The image is not drawn repeatedly.</li></ul>
</td>
</tr>
<tr id="en-us_topic_0000001058988952_row10124151961014"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="en-us_topic_0000001058988952_en-us_topic_0000001059340528_a709eb4a9fa87428897bebb4a98693df2"><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_a709eb4a9fa87428897bebb4a98693df2"></a><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_a709eb4a9fa87428897bebb4a98693df2"></a>background-position</p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_ul8874155216502"></a><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_ul8874155216502"></a><ul id="en-us_topic_0000001058988952_en-us_topic_0000001059340528_ul8874155216502"><li>string string</li><li>&lt;length&gt; &lt;length&gt;</li><li>&lt;percentage&gt; &lt;percentage&gt;</li></ul>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p id="en-us_topic_0000001058988952_en-us_topic_0000001059340528_a6f8f5d1c92f447bd868a841ad1a33cb1"><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_a6f8f5d1c92f447bd868a841ad1a33cb1"></a><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_a6f8f5d1c92f447bd868a841ad1a33cb1"></a>0px 0px</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p id="en-us_topic_0000001058988952_en-us_topic_0000001059340528_p173010720280"><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_p173010720280"></a><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_p173010720280"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_ul1590812103363"></a><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_ul1590812103363"></a><ul id="en-us_topic_0000001058988952_en-us_topic_0000001059340528_ul1590812103363"><li>Using keywords: If only one keyword is specified, the other value is <strong id="en-us_topic_0000001058988952_en-us_topic_0000001059340528_b5234102011540"><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_b5234102011540"></a><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_b5234102011540"></a>center</strong> by default. The two values define the horizontal position and vertical position, respectively.<a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_ul1453531734716"></a><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_ul1453531734716"></a><ul id="en-us_topic_0000001058988952_en-us_topic_0000001059340528_ul1453531734716"><li><strong id="en-us_topic_0000001058988952_en-us_topic_0000001059340528_b0982111273712"><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_b0982111273712"></a><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_b0982111273712"></a>left</strong>: leftmost in the horizontal direction</li><li><strong id="en-us_topic_0000001058988952_en-us_topic_0000001059340528_b866713583912"><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_b866713583912"></a><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_b866713583912"></a>right</strong>: rightmost in the horizontal direction</li><li><strong id="en-us_topic_0000001058988952_en-us_topic_0000001059340528_b5886013193716"><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_b5886013193716"></a><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_b5886013193716"></a>top</strong>: top in the vertical direction</li><li><strong id="en-us_topic_0000001058988952_en-us_topic_0000001059340528_b84197142376"><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_b84197142376"></a><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_b84197142376"></a>bottom</strong>: bottom in the vertical direction</li><li><strong id="en-us_topic_0000001058988952_en-us_topic_0000001059340528_b14894114103710"><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_b14894114103710"></a><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_b14894114103710"></a>center</strong>: center position</li></ul>
</li></ul>
<a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_ul10908121023615"></a><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_ul10908121023615"></a><ul id="en-us_topic_0000001058988952_en-us_topic_0000001059340528_ul10908121023615"><li>Using <strong id="en-us_topic_0000001058988952_en-us_topic_0000001059340528_b11401615193715"><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_b11401615193715"></a><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_b11401615193715"></a>&lt;length&gt;</strong>: The first value indicates the horizontal position, and the second value indicates the vertical position. <strong id="en-us_topic_0000001058988952_en-us_topic_0000001059340528_b1341381819379"><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_b1341381819379"></a><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_b1341381819379"></a>0 0</strong> indicates the upper left corner. The unit is pixel. If only one value is specified, the other one is <strong id="en-us_topic_0000001058988952_en-us_topic_0000001059340528_b48671516183714"><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_b48671516183714"></a><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_b48671516183714"></a>50%</strong>.</li><li>Using <strong id="en-us_topic_0000001058988952_en-us_topic_0000001059340528_b5492717163712"><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_b5492717163712"></a><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_b5492717163712"></a>&lt;percentage&gt;</strong>: The first value indicates the horizontal position, and the second value indicates the vertical position. <strong id="en-us_topic_0000001058988952_en-us_topic_0000001059340528_b164741723183712"><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_b164741723183712"></a><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_b164741723183712"></a>0% 0%</strong> indicates the upper left corner. <strong id="en-us_topic_0000001058988952_en-us_topic_0000001059340528_b64022245377"><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_b64022245377"></a><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_b64022245377"></a>100% 100%</strong> indicates the lower right corner. If only one value is specified, the other one is <strong id="en-us_topic_0000001058988952_en-us_topic_0000001059340528_b7893424163718"><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_b7893424163718"></a><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_b7893424163718"></a>50%</strong>.</li><li>Using both <strong id="en-us_topic_0000001058988952_en-us_topic_0000001059340528_b154811725193718"><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_b154811725193718"></a><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_b154811725193718"></a>&lt;percentage&gt;</strong> and <strong id="en-us_topic_0000001058988952_en-us_topic_0000001059340528_b34834254377"><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_b34834254377"></a><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_b34834254377"></a>&lt;length&gt;</strong>.</li></ul>
</td>
</tr>
<tr id="en-us_topic_0000001058988952_row812611915107"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="en-us_topic_0000001058988952_en-us_topic_0000001059340528_p134581712103910"><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_p134581712103910"></a><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_p134581712103910"></a>opacity</p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p id="en-us_topic_0000001058988952_en-us_topic_0000001059340528_a45185999ae584676af4c36467c2ade8b"><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_a45185999ae584676af4c36467c2ade8b"></a><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_a45185999ae584676af4c36467c2ade8b"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p id="en-us_topic_0000001058988952_en-us_topic_0000001059340528_a09ff20dda8e44794bca18c84f413d972"><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_a09ff20dda8e44794bca18c84f413d972"></a><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_a09ff20dda8e44794bca18c84f413d972"></a>1</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p id="en-us_topic_0000001058988952_en-us_topic_0000001059340528_p1873011722814"><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_p1873011722814"></a><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_p1873011722814"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="en-us_topic_0000001058988952_en-us_topic_0000001059340528_p122515161139"><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_p122515161139"></a><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_p122515161139"></a>Transparency of an element. The value ranges from <strong id="en-us_topic_0000001058988952_en-us_topic_0000001059340528_b1871715526385"><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_b1871715526385"></a><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_b1871715526385"></a>0</strong> to <strong id="en-us_topic_0000001058988952_en-us_topic_0000001059340528_b177181452103815"><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_b177181452103815"></a><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_b177181452103815"></a>1</strong>. The value <strong id="en-us_topic_0000001058988952_en-us_topic_0000001059340528_b13718155210380"><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_b13718155210380"></a><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_b13718155210380"></a>1</strong> means opaque, and <strong id="en-us_topic_0000001058988952_en-us_topic_0000001059340528_b6718152103818"><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_b6718152103818"></a><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_b6718152103818"></a>0</strong> means completely transparent.</p>
</td>
</tr>
<tr id="en-us_topic_0000001058988952_row112671911011"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="en-us_topic_0000001058988952_en-us_topic_0000001059340528_aeda9e2f8d8344958bf4f43d429dcb55e"><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_aeda9e2f8d8344958bf4f43d429dcb55e"></a><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_aeda9e2f8d8344958bf4f43d429dcb55e"></a>display</p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p id="en-us_topic_0000001058988952_en-us_topic_0000001059340528_p1544115441446"><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_p1544115441446"></a><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_p1544115441446"></a>string</p>
<p id="en-us_topic_0000001058988952_en-us_topic_0000001059340528_aaaa164aa970b490fb048e5f260f1c661"><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_aaaa164aa970b490fb048e5f260f1c661"></a><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_aaaa164aa970b490fb048e5f260f1c661"></a></p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p id="en-us_topic_0000001058988952_en-us_topic_0000001059340528_aa5ce61466c9847dbb7f44852338d9006"><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_aa5ce61466c9847dbb7f44852338d9006"></a><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_aa5ce61466c9847dbb7f44852338d9006"></a>flex</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p id="en-us_topic_0000001058988952_en-us_topic_0000001059340528_p167303762818"><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_p167303762818"></a><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_p167303762818"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="en-us_topic_0000001058988952_en-us_topic_0000001059340528_p23704018414"><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_p23704018414"></a><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_p23704018414"></a>How and whether to display the box containing an element. Available values are as follows:</p>
<a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_ul12227103394916"></a><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_ul12227103394916"></a><ul id="en-us_topic_0000001058988952_en-us_topic_0000001059340528_ul12227103394916"><li><strong id="en-us_topic_0000001058988952_en-us_topic_0000001059340528_b57468289377"><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_b57468289377"></a><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_b57468289377"></a>flex</strong>: flexible layout</li><li><strong id="en-us_topic_0000001058988952_en-us_topic_0000001059340528_b18887133293920"><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_b18887133293920"></a><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_b18887133293920"></a>none</strong>: The element is hidden.</li></ul>
</td>
</tr>
<tr id="en-us_topic_0000001058988952_row712781941016"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="en-us_topic_0000001058988952_en-us_topic_0000001059340528_aa2ed1da39c8e4ad78829712734226ab9"><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_aa2ed1da39c8e4ad78829712734226ab9"></a><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_aa2ed1da39c8e4ad78829712734226ab9"></a>visibility</p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p id="en-us_topic_0000001058988952_en-us_topic_0000001059340528_p15475737486"><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_p15475737486"></a><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_p15475737486"></a>string</p>
<p id="en-us_topic_0000001058988952_en-us_topic_0000001059340528_aabfb0eb044194745af56c313f40e7781"><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_aabfb0eb044194745af56c313f40e7781"></a><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_aabfb0eb044194745af56c313f40e7781"></a></p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p id="en-us_topic_0000001058988952_en-us_topic_0000001059340528_acaca80d4ef9a4f0d87adf92cb2d1ff9a"><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_acaca80d4ef9a4f0d87adf92cb2d1ff9a"></a><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_acaca80d4ef9a4f0d87adf92cb2d1ff9a"></a>visible</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p id="en-us_topic_0000001058988952_en-us_topic_0000001059340528_p57301471281"><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_p57301471281"></a><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_p57301471281"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="en-us_topic_0000001058988952_en-us_topic_0000001059340528_p1568839154517"><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_p1568839154517"></a><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_p1568839154517"></a>Whether to display an element. Invisible borders occupy layout space. (To remove the borders, set the <strong id="en-us_topic_0000001058988952_en-us_topic_0000001059340528_b15844103015378"><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_b15844103015378"></a><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_b15844103015378"></a>display</strong> attribute to <strong id="en-us_topic_0000001058988952_en-us_topic_0000001059340528_b4845153013712"><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_b4845153013712"></a><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_b4845153013712"></a>none</strong>.) Available values are as follows:</p>
<a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_ul751984164920"></a><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_ul751984164920"></a><ul id="en-us_topic_0000001058988952_en-us_topic_0000001059340528_ul751984164920"><li><strong id="en-us_topic_0000001058988952_en-us_topic_0000001059340528_b17429331133711"><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_b17429331133711"></a><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_b17429331133711"></a>visible</strong>: The element is visible.</li><li><strong id="en-us_topic_0000001058988952_en-us_topic_0000001059340528_b109191231193710"><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_b109191231193710"></a><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_b109191231193710"></a>hidden</strong>: The element is hidden but still takes up space.</li></ul>
<div class="note" id="en-us_topic_0000001058988952_en-us_topic_0000001059340528_note4549524649"><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_note4549524649"></a><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_note4549524649"></a><span class="notetitle"> NOTE: </span><div class="notebody"><p id="en-us_topic_0000001058988952_en-us_topic_0000001059340528_p25499241642"><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_p25499241642"></a><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_p25499241642"></a>If both <strong id="en-us_topic_0000001058988952_en-us_topic_0000001059340528_b719810016405"><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_b719810016405"></a><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_b719810016405"></a>visibility</strong> and <strong id="en-us_topic_0000001058988952_en-us_topic_0000001059340528_b187052264018"><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_b187052264018"></a><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_b187052264018"></a>display</strong> are set, only <strong id="en-us_topic_0000001058988952_en-us_topic_0000001059340528_b107788924011"><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_b107788924011"></a><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_b107788924011"></a>display</strong> takes effect.</p>
</div></div>
</td>
</tr>
<tr id="en-us_topic_0000001058988952_row19127619151012"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="en-us_topic_0000001058988952_en-us_topic_0000001059340528_ad74a6a48aca7439e9344c18c26b4177e"><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_ad74a6a48aca7439e9344c18c26b4177e"></a><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_ad74a6a48aca7439e9344c18c26b4177e"></a>flex</p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p id="en-us_topic_0000001058988952_en-us_topic_0000001059340528_a2e6e5192a1534872be5fcfd9f83e3fdc"><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_a2e6e5192a1534872be5fcfd9f83e3fdc"></a><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_a2e6e5192a1534872be5fcfd9f83e3fdc"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p id="en-us_topic_0000001058988952_en-us_topic_0000001059340528_a8512eda38e25410685be8a8992890257"><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_a8512eda38e25410685be8a8992890257"></a><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_a8512eda38e25410685be8a8992890257"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p id="en-us_topic_0000001058988952_en-us_topic_0000001059340528_p1373057132812"><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_p1373057132812"></a><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_p1373057132812"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="en-us_topic_0000001058988952_en-us_topic_0000001059340528_a11c317cdfa7d4066878d86c6b3bcbd82"><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_a11c317cdfa7d4066878d86c6b3bcbd82"></a><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_a11c317cdfa7d4066878d86c6b3bcbd82"></a>How to divide available space of the parent component for a child component.</p>
<p id="en-us_topic_0000001058988952_en-us_topic_0000001059340528_p6968144051814"><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_p6968144051814"></a><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_p6968144051814"></a>You can set one, two<sup id="en-us_topic_0000001058988952_en-us_topic_0000001059340528_sup894453017315"><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_sup894453017315"></a><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_sup894453017315"></a>5+</sup>, or three<sup id="en-us_topic_0000001058988952_en-us_topic_0000001059340528_sup1255142393114"><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_sup1255142393114"></a><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_sup1255142393114"></a>5+</sup> values for this style.</p>
<p id="en-us_topic_0000001058988952_en-us_topic_0000001059340528_p16733313171911"><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_p16733313171911"></a><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_p16733313171911"></a>Set one value in either of the following ways:</p>
<a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_ul93371539192211"></a><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_ul93371539192211"></a><ul id="en-us_topic_0000001058988952_en-us_topic_0000001059340528_ul93371539192211"><li>A unitless number to set <strong id="en-us_topic_0000001058988952_en-us_topic_0000001059340528_b152581117781"><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_b152581117781"></a><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_b152581117781"></a>flex-grow</strong>.</li><li>A valid width value<sup id="en-us_topic_0000001058988952_en-us_topic_0000001059340528_sup133014373318"><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_sup133014373318"></a><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_sup133014373318"></a>5+</sup> to set <strong id="en-us_topic_0000001058988952_en-us_topic_0000001059340528_b182101331199"><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_b182101331199"></a><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_b182101331199"></a>flex-basis</strong>.</li></ul>
<p id="en-us_topic_0000001058988952_en-us_topic_0000001059340528_p6786171632018"><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_p6786171632018"></a><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_p6786171632018"></a>Set two values<sup id="en-us_topic_0000001058988952_en-us_topic_0000001059340528_sup39514502313"><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_sup39514502313"></a><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_sup39514502313"></a>5+</sup> in the following ways:</p>
<p id="en-us_topic_0000001058988952_en-us_topic_0000001059340528_p6400429122011"><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_p6400429122011"></a><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_p6400429122011"></a>The first value must be a unitless number used to set <strong id="en-us_topic_0000001058988952_en-us_topic_0000001059340528_b171516283129"><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_b171516283129"></a><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_b171516283129"></a>flex-grow</strong>. The second value must be either of the following:</p>
<a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_ul767043502219"></a><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_ul767043502219"></a><ul id="en-us_topic_0000001058988952_en-us_topic_0000001059340528_ul767043502219"><li>A unitless number to set <strong id="en-us_topic_0000001058988952_en-us_topic_0000001059340528_b1428375141313"><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_b1428375141313"></a><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_b1428375141313"></a>flex-shrink</strong>.</li><li>A valid width value to set <strong id="en-us_topic_0000001058988952_en-us_topic_0000001059340528_b1632495651416"><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_b1632495651416"></a><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_b1632495651416"></a>flex-basis</strong>.</li></ul>
<p id="en-us_topic_0000001058988952_en-us_topic_0000001059340528_p748416351217"><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_p748416351217"></a><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_p748416351217"></a>Set three values<sup id="en-us_topic_0000001058988952_en-us_topic_0000001059340528_sup168671312151514"><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_sup168671312151514"></a><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_sup168671312151514"></a>5+</sup> in the following ways:</p>
<p id="en-us_topic_0000001058988952_en-us_topic_0000001059340528_p7373204832111"><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_p7373204832111"></a><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_p7373204832111"></a>The first value must be a unitless number used to set <strong id="en-us_topic_0000001058988952_en-us_topic_0000001059340528_b19419131221612"><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_b19419131221612"></a><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_b19419131221612"></a>flex-grow</strong>. The second value must be a unitless number used to set <strong id="en-us_topic_0000001058988952_en-us_topic_0000001059340528_b19378733181612"><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_b19378733181612"></a><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_b19378733181612"></a>flex-shrink</strong>. The third value must be a valid width value used to set <strong id="en-us_topic_0000001058988952_en-us_topic_0000001059340528_b47717118176"><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_b47717118176"></a><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_b47717118176"></a>flex-basis</strong>.</p>
<div class="note" id="en-us_topic_0000001058988952_en-us_topic_0000001059340528_note34891253201520"><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_note34891253201520"></a><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_note34891253201520"></a><span class="notetitle"> NOTE: </span><div class="notebody"><p id="en-us_topic_0000001058988952_en-us_topic_0000001059340528_p1248915538152"><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_p1248915538152"></a><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_p1248915538152"></a>This style takes effect only when the container is any of the following components: <strong id="en-us_topic_0000001058988952_en-us_topic_0000001059340528_b17156153131"><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_b17156153131"></a><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_b17156153131"></a>&lt;div&gt;</strong>, <strong id="en-us_topic_0000001058988952_en-us_topic_0000001059340528_b1201415151311"><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_b1201415151311"></a><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_b1201415151311"></a>&lt;list-item&gt;</strong>, <strong id="en-us_topic_0000001058988952_en-us_topic_0000001059340528_b72031515132"><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_b72031515132"></a><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_b72031515132"></a>&lt;refresh&gt;</strong>, <strong id="en-us_topic_0000001058988952_en-us_topic_0000001059340528_b1920131551310"><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_b1920131551310"></a><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_b1920131551310"></a>&lt;stepper-item&gt;</strong><sup id="en-us_topic_0000001058988952_en-us_topic_0000001059340528_sup17201815121317"><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_sup17201815121317"></a><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_sup17201815121317"></a>5+</sup>, and <strong id="en-us_topic_0000001058988952_en-us_topic_0000001059340528_b2211915121313"><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_b2211915121313"></a><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_b2211915121313"></a>&lt;tabs&gt;</strong>.</p>
</div></div>
</td>
</tr>
<tr id="en-us_topic_0000001058988952_row131281919121011"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="en-us_topic_0000001058988952_en-us_topic_0000001059340528_a5d88cacaaf5c4f6a87390ab916b695c6"><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_a5d88cacaaf5c4f6a87390ab916b695c6"></a><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_a5d88cacaaf5c4f6a87390ab916b695c6"></a>flex-grow</p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p id="en-us_topic_0000001058988952_en-us_topic_0000001059340528_a2c379e3af283446da446f1631e572efd"><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_a2c379e3af283446da446f1631e572efd"></a><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_a2c379e3af283446da446f1631e572efd"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p id="en-us_topic_0000001058988952_en-us_topic_0000001059340528_aa374f6c7415a4ee48a06930d76c55be7"><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_aa374f6c7415a4ee48a06930d76c55be7"></a><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_aa374f6c7415a4ee48a06930d76c55be7"></a>0</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p id="en-us_topic_0000001058988952_p17128131991015"><a name="en-us_topic_0000001058988952_p17128131991015"></a><a name="en-us_topic_0000001058988952_p17128131991015"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="en-us_topic_0000001058988952_en-us_topic_0000001059340528_p4437122419557"><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_p4437122419557"></a><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_p4437122419557"></a>How much a child component will grow. The value specifies allocation of the remaining space on the main axis of the parent component. Size of available space = Container size - Total size of all child components. Value <strong id="en-us_topic_0000001058988952_en-us_topic_0000001059340528_b1682343583716"><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_b1682343583716"></a><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_b1682343583716"></a>0</strong> indicates that the child component does not grow.</p>
<div class="note" id="en-us_topic_0000001058988952_en-us_topic_0000001059340528_note201231734212"><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_note201231734212"></a><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_note201231734212"></a><span class="notetitle"> NOTE: </span><div class="notebody"><p id="en-us_topic_0000001058988952_en-us_topic_0000001059340528_p184555314553"><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_p184555314553"></a><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_p184555314553"></a>This style takes effect only when the container is any of the following components: <strong id="en-us_topic_0000001058988952_en-us_topic_0000001059340528_b18575165615499"><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_b18575165615499"></a><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_b18575165615499"></a>&lt;div&gt;</strong>, <strong id="en-us_topic_0000001058988952_en-us_topic_0000001059340528_b8575165618495"><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_b8575165618495"></a><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_b8575165618495"></a>&lt;list-item&gt;</strong>, <strong id="en-us_topic_0000001058988952_en-us_topic_0000001059340528_b125751756164917"><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_b125751756164917"></a><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_b125751756164917"></a>&lt;refresh&gt;</strong>, <strong id="en-us_topic_0000001058988952_en-us_topic_0000001059340528_b15751456104920"><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_b15751456104920"></a><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_b15751456104920"></a>&lt;stepper-item&gt;</strong><sup id="en-us_topic_0000001058988952_en-us_topic_0000001059340528_sup257595611492"><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_sup257595611492"></a><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_sup257595611492"></a>5+</sup>, and <strong id="en-us_topic_0000001058988952_en-us_topic_0000001059340528_b55761856114912"><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_b55761856114912"></a><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_b55761856114912"></a>&lt;tabs&gt;</strong>.</p>
</div></div>
</td>
</tr>
<tr id="en-us_topic_0000001058988952_row0128219191010"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="en-us_topic_0000001058988952_en-us_topic_0000001059340528_ac65ef7e2b1f24a13b09c495f643168c9"><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_ac65ef7e2b1f24a13b09c495f643168c9"></a><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_ac65ef7e2b1f24a13b09c495f643168c9"></a>flex-shrink</p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p id="en-us_topic_0000001058988952_en-us_topic_0000001059340528_a98e7d367f0e649699892ae5bad6ade37"><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_a98e7d367f0e649699892ae5bad6ade37"></a><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_a98e7d367f0e649699892ae5bad6ade37"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p id="en-us_topic_0000001058988952_en-us_topic_0000001059340528_a422d978368814d12a33201cb839060ee"><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_a422d978368814d12a33201cb839060ee"></a><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_a422d978368814d12a33201cb839060ee"></a>1</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p id="en-us_topic_0000001058988952_p11128419201019"><a name="en-us_topic_0000001058988952_p11128419201019"></a><a name="en-us_topic_0000001058988952_p11128419201019"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="en-us_topic_0000001058988952_en-us_topic_0000001059340528_ab032342dfe56460ca742800de482ca0f"><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_ab032342dfe56460ca742800de482ca0f"></a><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_ab032342dfe56460ca742800de482ca0f"></a>How much a child component will shrink. The shrink occurs only when the sum of default child component widths is greater than that of the parent component. Value <strong id="en-us_topic_0000001058988952_en-us_topic_0000001059340528_b783242395"><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_b783242395"></a><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_b783242395"></a>0</strong> indicates that the child component does not shrink.</p>
<div class="note" id="en-us_topic_0000001058988952_en-us_topic_0000001059340528_note147160917217"><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_note147160917217"></a><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_note147160917217"></a><span class="notetitle"> NOTE: </span><div class="notebody"><p id="en-us_topic_0000001058988952_en-us_topic_0000001059340528_p844914328577"><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_p844914328577"></a><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_p844914328577"></a>This style takes effect only when the container is any of the following components: <strong id="en-us_topic_0000001058988952_en-us_topic_0000001059340528_b1168212543127"><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_b1168212543127"></a><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_b1168212543127"></a>&lt;div&gt;</strong>, <strong id="en-us_topic_0000001058988952_en-us_topic_0000001059340528_b76821454121211"><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_b76821454121211"></a><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_b76821454121211"></a>&lt;list-item&gt;</strong>, <strong id="en-us_topic_0000001058988952_en-us_topic_0000001059340528_b1168255411126"><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_b1168255411126"></a><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_b1168255411126"></a>&lt;refresh&gt;</strong>, <strong id="en-us_topic_0000001058988952_en-us_topic_0000001059340528_b10682155415120"><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_b10682155415120"></a><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_b10682155415120"></a>&lt;stepper-item&gt;</strong><sup id="en-us_topic_0000001058988952_en-us_topic_0000001059340528_sup10683145491215"><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_sup10683145491215"></a><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_sup10683145491215"></a>5+</sup>, and <strong id="en-us_topic_0000001058988952_en-us_topic_0000001059340528_b1868385461211"><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_b1868385461211"></a><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_b1868385461211"></a>&lt;tabs&gt;</strong>.</p>
</div></div>
</td>
</tr>
<tr id="en-us_topic_0000001058988952_row18129519151011"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="en-us_topic_0000001058988952_en-us_topic_0000001059340528_a82c323a994634032963169eeee1a55e4"><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_a82c323a994634032963169eeee1a55e4"></a><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_a82c323a994634032963169eeee1a55e4"></a>flex-basis</p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p id="en-us_topic_0000001058988952_en-us_topic_0000001059340528_p1148910787"><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_p1148910787"></a><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_p1148910787"></a>&lt;length&gt;</p>
<p id="en-us_topic_0000001058988952_en-us_topic_0000001059340528_a43613cf0c2184c0d8b44e8d292f6edb7"><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_a43613cf0c2184c0d8b44e8d292f6edb7"></a><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_a43613cf0c2184c0d8b44e8d292f6edb7"></a></p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p id="en-us_topic_0000001058988952_en-us_topic_0000001059340528_ab9e1c7dc25f840e58993af05c1d32109"><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_ab9e1c7dc25f840e58993af05c1d32109"></a><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_ab9e1c7dc25f840e58993af05c1d32109"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p id="en-us_topic_0000001058988952_p101299192109"><a name="en-us_topic_0000001058988952_p101299192109"></a><a name="en-us_topic_0000001058988952_p101299192109"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="en-us_topic_0000001058988952_en-us_topic_0000001059340528_a0993ef9b0ef64785a76e6310dd834f09"><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_a0993ef9b0ef64785a76e6310dd834f09"></a><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_a0993ef9b0ef64785a76e6310dd834f09"></a>Initial length of the flex item on the main axis.</p>
<div class="note" id="en-us_topic_0000001058988952_en-us_topic_0000001059340528_note62848141222"><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_note62848141222"></a><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_note62848141222"></a><span class="notetitle"> NOTE: </span><div class="notebody"><p id="en-us_topic_0000001058988952_en-us_topic_0000001059340528_p16711745115718"><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_p16711745115718"></a><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_p16711745115718"></a>This style takes effect only when the container is any of the following components: <strong id="en-us_topic_0000001058988952_en-us_topic_0000001059340528_b18795155631219"><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_b18795155631219"></a><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_b18795155631219"></a>&lt;div&gt;</strong>, <strong id="en-us_topic_0000001058988952_en-us_topic_0000001059340528_b107951056121217"><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_b107951056121217"></a><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_b107951056121217"></a>&lt;list-item&gt;</strong>, <strong id="en-us_topic_0000001058988952_en-us_topic_0000001059340528_b2795105619128"><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_b2795105619128"></a><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_b2795105619128"></a>&lt;refresh&gt;</strong>, <strong id="en-us_topic_0000001058988952_en-us_topic_0000001059340528_b1579510564126"><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_b1579510564126"></a><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_b1579510564126"></a>&lt;stepper-item&gt;</strong><sup id="en-us_topic_0000001058988952_en-us_topic_0000001059340528_sup187953565122"><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_sup187953565122"></a><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_sup187953565122"></a>5+</sup>, and <strong id="en-us_topic_0000001058988952_en-us_topic_0000001059340528_b11796456201211"><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_b11796456201211"></a><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_b11796456201211"></a>&lt;tabs&gt;</strong>.</p>
</div></div>
</td>
</tr>
<tr id="en-us_topic_0000001058988952_row812931912102"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="en-us_topic_0000001058988952_en-us_topic_0000001059340528_a50180d720a374549ae72c848e53320cb"><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_a50180d720a374549ae72c848e53320cb"></a><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_a50180d720a374549ae72c848e53320cb"></a>position</p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p id="en-us_topic_0000001058988952_en-us_topic_0000001059340528_a63672ed9a4c040f7a6ec9c8089b79bb6"><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_a63672ed9a4c040f7a6ec9c8089b79bb6"></a><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_a63672ed9a4c040f7a6ec9c8089b79bb6"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p id="en-us_topic_0000001058988952_en-us_topic_0000001059340528_a2666820c71eb420485e4d20e55b4eabe"><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_a2666820c71eb420485e4d20e55b4eabe"></a><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_a2666820c71eb420485e4d20e55b4eabe"></a>relative</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p id="en-us_topic_0000001058988952_en-us_topic_0000001059340528_p1173107172814"><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_p1173107172814"></a><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_p1173107172814"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="en-us_topic_0000001058988952_en-us_topic_0000001059340528_ae28abf4e47a740efbd45a8f280577912"><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_ae28abf4e47a740efbd45a8f280577912"></a><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_ae28abf4e47a740efbd45a8f280577912"></a>Positioning type of an element. Dynamic changes are not supported.</p>
<a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_ul17185232185014"></a><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_ul17185232185014"></a><ul id="en-us_topic_0000001058988952_en-us_topic_0000001059340528_ul17185232185014"><li><strong id="en-us_topic_0000001058988952_en-us_topic_0000001059340528_b1894911155394"><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_b1894911155394"></a><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_b1894911155394"></a>fixed</strong>: The element is positioned related to the browser window.</li><li><strong id="en-us_topic_0000001058988952_en-us_topic_0000001059340528_b823115152390"><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_b823115152390"></a><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_b823115152390"></a>absolute</strong>: The element is positioned absolutely to its parent element.</li><li><strong id="en-us_topic_0000001058988952_en-us_topic_0000001059340528_b736151417395"><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_b736151417395"></a><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_b736151417395"></a>relative</strong>: The element is positioned relative to its normal position.</li></ul>
<div class="note" id="en-us_topic_0000001058988952_en-us_topic_0000001059340528_note167617191219"><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_note167617191219"></a><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_note167617191219"></a><span class="notetitle"> NOTE: </span><div class="notebody"><p id="en-us_topic_0000001058988952_en-us_topic_0000001059340528_p1839092815101"><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_p1839092815101"></a><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_p1839092815101"></a>The <strong id="en-us_topic_0000001058988952_en-us_topic_0000001059340528_b13941713133910"><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_b13941713133910"></a><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_b13941713133910"></a>absolute</strong> attribute takes effect only when the parent component is <strong id="en-us_topic_0000001058988952_en-us_topic_0000001059340528_b1099913173916"><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_b1099913173916"></a><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_b1099913173916"></a>&lt;div&gt;</strong> or <strong id="en-us_topic_0000001058988952_en-us_topic_0000001059340528_b181001413123919"><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_b181001413123919"></a><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_b181001413123919"></a>&lt;stack&gt;</strong>.</p>
</div></div>
</td>
</tr>
<tr id="en-us_topic_0000001058988952_row51300197108"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="en-us_topic_0000001058988952_en-us_topic_0000001059340528_a70405cb9696b4329ac7625af93310018"><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_a70405cb9696b4329ac7625af93310018"></a><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_a70405cb9696b4329ac7625af93310018"></a>[left|top<span id="en-us_topic_0000001058988952_en-us_topic_0000001059340528_ph14927143614712"><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_ph14927143614712"></a><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_ph14927143614712"></a>|right|bottom</span>]</p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p id="en-us_topic_0000001058988952_en-us_topic_0000001059340528_p1849062221214"><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_p1849062221214"></a><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_p1849062221214"></a>&lt;length&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p id="en-us_topic_0000001058988952_en-us_topic_0000001059340528_a579ac7c03d1d46758ebaacd565d86ed3"><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_a579ac7c03d1d46758ebaacd565d86ed3"></a><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_a579ac7c03d1d46758ebaacd565d86ed3"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p id="en-us_topic_0000001058988952_en-us_topic_0000001059340528_p187314719288"><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_p187314719288"></a><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_p187314719288"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="en-us_topic_0000001058988952_en-us_topic_0000001059340528_a9a662a62cd9b40eaa0cb9ca082b6d1c2"><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_a9a662a62cd9b40eaa0cb9ca082b6d1c2"></a><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_a9a662a62cd9b40eaa0cb9ca082b6d1c2"></a><strong id="en-us_topic_0000001058988952_en-us_topic_0000001059340528_b481348173914"><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_b481348173914"></a><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_b481348173914"></a>left|top</strong><span id="en-us_topic_0000001058988952_en-us_topic_0000001059340528_ph4818118173914"><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_ph4818118173914"></a><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_ph4818118173914"></a><strong id="en-us_topic_0000001058988952_en-us_topic_0000001059340528_b68143833912"><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_b68143833912"></a><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_b68143833912"></a>|right|bottom</strong></span> must be used together with <strong id="en-us_topic_0000001058988952_en-us_topic_0000001059340528_b881916818394"><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_b881916818394"></a><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_b881916818394"></a>position</strong> to determine the offset position of an element.</p>
<a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_ul12671003525"></a><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_ul12671003525"></a><ul id="en-us_topic_0000001058988952_en-us_topic_0000001059340528_ul12671003525"><li>The <strong id="en-us_topic_0000001058988952_en-us_topic_0000001059340528_b885117712398"><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_b885117712398"></a><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_b885117712398"></a>left</strong> attribute specifies the left edge position of the element. This attribute defines the offset between the left edge of a positioned element and that of a block included in the element.</li><li>The <strong id="en-us_topic_0000001058988952_en-us_topic_0000001059340528_b65591759395"><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_b65591759395"></a><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_b65591759395"></a>top</strong> attribute specifies the top edge position of the element. This attribute defines the offset between the top edge of a positioned element and that of a block included in the element.</li><li>The <strong id="en-us_topic_0000001058988952_en-us_topic_0000001059340528_b179013323910"><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_b179013323910"></a><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_b179013323910"></a>right</strong> attribute specifies the right edge position of the element. This attribute defines the offset between the right edge of a positioned element and that of a block included in the element. </li><li>The <strong id="en-us_topic_0000001058988952_en-us_topic_0000001059340528_b77091602397"><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_b77091602397"></a><a name="en-us_topic_0000001058988952_en-us_topic_0000001059340528_b77091602397"></a>bottom</strong> attribute specifies the bottom edge position of the element. This attribute defines the offset between the bottom edge of a positioned element and that of a block included in the element. </li></ul>
</td>
</tr>
</tbody>
</table>

## Example Code<a name="en-us_topic_0000001058988952_section738534695417"></a>

```
<!-- xxx.hml -->
<div class="container" @swipe="handleSwipe">
  <text class="title">
    Selected: {{time}}
  </text>
  <picker-view class="time-picker" type="time" selected="{{defaultTime}}" @change="handleChange"></picker-view>
</div>
```

```
/* xxx.css */
.container {
  flex-direction: column;
  justify-content: center;
  align-items: center;
  left: 0px;
  top: 0px;
  width: 454px;
  height: 454px;
}
.title {
  font-size: 30px;
  text-align: center;
}
.time-picker {
  width: 500px;
  height: 400px;
  margin-top: 20px;
}
```

```
/* xxx.js */
export default {
  data: {
    defaultTime: "",
    time: "",
  },
  onInit() {
    this.defaultTime = this.now();
  },
  handleChange(data) {
    this.time = this.concat(data.hour, data.minute);
  },
  now() {
    const date = new Date();
    const hours = date.getHours();
    const minutes = date.getMinutes();
    return this.concat(hours, minutes);
  },

  fill(value) {
    return (value > 9 ? "" : "0") + value;
  },

  concat(hours, minutes) {
    return `${this.fill(hours)}:${this.fill(minutes)}`;
  },
}
```

![](figures/sssssss.png)

