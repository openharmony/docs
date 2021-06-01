# progress<a name="EN-US_TOPIC_0000001115974744"></a>

-   [Permission List](#en-us_topic_0000001058670841_section11257113618419)
-   [Child Component](#en-us_topic_0000001058670841_section9288143101012)
-   [Attribute](#en-us_topic_0000001058670841_section2907183951110)
-   [Event](#en-us_topic_0000001058670841_section164912362544)
-   [Style](#en-us_topic_0000001058670841_section5775351116)
-   [Example Code](#en-us_topic_0000001058670841_section493033510346)

The  **<progress\>**  component is used to provide a progress bar that displays the progress of content loading or operation processing.

## Permission List<a name="en-us_topic_0000001058670841_section11257113618419"></a>

None

## Child Component<a name="en-us_topic_0000001058670841_section9288143101012"></a>

Not supported

## Attribute<a name="en-us_topic_0000001058670841_section2907183951110"></a>

<a name="en-us_topic_0000001058670841_table20633101642315"></a>
<table><thead align="left"><tr id="en-us_topic_0000001058670841_row663331618238"><th class="cellrowborder" valign="top" width="23.119999999999997%" id="mcps1.1.6.1.1"><p id="en-us_topic_0000001058670841_en-us_topic_0000001058340523_a9ba8c579217b4b8b841b035f1d28b20e"><a name="en-us_topic_0000001058670841_en-us_topic_0000001058340523_a9ba8c579217b4b8b841b035f1d28b20e"></a><a name="en-us_topic_0000001058670841_en-us_topic_0000001058340523_a9ba8c579217b4b8b841b035f1d28b20e"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="23.119999999999997%" id="mcps1.1.6.1.2"><p id="en-us_topic_0000001058670841_en-us_topic_0000001058340523_a633002333b024497914a4b172446f14e"><a name="en-us_topic_0000001058670841_en-us_topic_0000001058340523_a633002333b024497914a4b172446f14e"></a><a name="en-us_topic_0000001058670841_en-us_topic_0000001058340523_a633002333b024497914a4b172446f14e"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="10.48%" id="mcps1.1.6.1.3"><p id="en-us_topic_0000001058670841_en-us_topic_0000001058340523_a4950f7884c6540b9ad523ac34657d952"><a name="en-us_topic_0000001058670841_en-us_topic_0000001058340523_a4950f7884c6540b9ad523ac34657d952"></a><a name="en-us_topic_0000001058670841_en-us_topic_0000001058340523_a4950f7884c6540b9ad523ac34657d952"></a>Default Value</p>
</th>
<th class="cellrowborder" valign="top" width="7.5200000000000005%" id="mcps1.1.6.1.4"><p id="en-us_topic_0000001058670841_p824610360217"><a name="en-us_topic_0000001058670841_p824610360217"></a><a name="en-us_topic_0000001058670841_p824610360217"></a>Mandatory</p>
</th>
<th class="cellrowborder" valign="top" width="35.76%" id="mcps1.1.6.1.5"><p id="en-us_topic_0000001058670841_en-us_topic_0000001058340523_a1313564aa9404a338447087d5918c17d"><a name="en-us_topic_0000001058670841_en-us_topic_0000001058340523_a1313564aa9404a338447087d5918c17d"></a><a name="en-us_topic_0000001058670841_en-us_topic_0000001058340523_a1313564aa9404a338447087d5918c17d"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="en-us_topic_0000001058670841_row6863121675218"><td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.1 "><p id="en-us_topic_0000001058670841_p1751189523"><a name="en-us_topic_0000001058670841_p1751189523"></a><a name="en-us_topic_0000001058670841_p1751189523"></a>type</p>
</td>
<td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.2 "><p id="en-us_topic_0000001058670841_p17591819528"><a name="en-us_topic_0000001058670841_p17591819528"></a><a name="en-us_topic_0000001058670841_p17591819528"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="10.48%" headers="mcps1.1.6.1.3 "><p id="en-us_topic_0000001058670841_p125151855212"><a name="en-us_topic_0000001058670841_p125151855212"></a><a name="en-us_topic_0000001058670841_p125151855212"></a>horizontal</p>
</td>
<td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.6.1.4 "><p id="en-us_topic_0000001058670841_p14512188523"><a name="en-us_topic_0000001058670841_p14512188523"></a><a name="en-us_topic_0000001058670841_p14512188523"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="35.76%" headers="mcps1.1.6.1.5 "><p id="en-us_topic_0000001058670841_p1510182522"><a name="en-us_topic_0000001058670841_p1510182522"></a><a name="en-us_topic_0000001058670841_p1510182522"></a>Type of the progress bar, which cannot be changed dynamically. Available values are as follows:</p>
<a name="en-us_topic_0000001058670841_ul11541820527"></a><a name="en-us_topic_0000001058670841_ul11541820527"></a><ul id="en-us_topic_0000001058670841_ul11541820527"><li><strong id="en-us_topic_0000001058670841_b18309101417563"><a name="en-us_topic_0000001058670841_b18309101417563"></a><a name="en-us_topic_0000001058670841_b18309101417563"></a>horizontal</strong>: linear progress bar</li><li><strong id="en-us_topic_0000001058670841_b196571440135618"><a name="en-us_topic_0000001058670841_b196571440135618"></a><a name="en-us_topic_0000001058670841_b196571440135618"></a>circular</strong>: loading progress bar</li><li><strong id="en-us_topic_0000001058670841_b16931854165616"><a name="en-us_topic_0000001058670841_b16931854165616"></a><a name="en-us_topic_0000001058670841_b16931854165616"></a>ring</strong>: ring progress bar</li><li><strong id="en-us_topic_0000001058670841_b146913331714"><a name="en-us_topic_0000001058670841_b146913331714"></a><a name="en-us_topic_0000001058670841_b146913331714"></a>scale-ring</strong>: ring progress bar with a scale</li><li><strong id="en-us_topic_0000001058670841_b12958985218"><a name="en-us_topic_0000001058670841_b12958985218"></a><a name="en-us_topic_0000001058670841_b12958985218"></a>arc</strong>: arc progress bar</li><li><strong id="en-us_topic_0000001058670841_b3326182912218"><a name="en-us_topic_0000001058670841_b3326182912218"></a><a name="en-us_topic_0000001058670841_b3326182912218"></a>eclipse</strong><sup id="en-us_topic_0000001058670841_sup790255053720"><a name="en-us_topic_0000001058670841_sup790255053720"></a><a name="en-us_topic_0000001058670841_sup790255053720"></a>5+</sup>: eclipse progress bar</li></ul>
</td>
</tr>
<tr id="en-us_topic_0000001058670841_row36332165231"><td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.1 "><p id="en-us_topic_0000001058670841_en-us_topic_0000001058340523_adb8a73146d764f2aab50fc046169ab26"><a name="en-us_topic_0000001058670841_en-us_topic_0000001058340523_adb8a73146d764f2aab50fc046169ab26"></a><a name="en-us_topic_0000001058670841_en-us_topic_0000001058340523_adb8a73146d764f2aab50fc046169ab26"></a>id</p>
</td>
<td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.2 "><p id="en-us_topic_0000001058670841_en-us_topic_0000001058340523_a06898db2627246f78e85d4fbadeee85c"><a name="en-us_topic_0000001058670841_en-us_topic_0000001058340523_a06898db2627246f78e85d4fbadeee85c"></a><a name="en-us_topic_0000001058670841_en-us_topic_0000001058340523_a06898db2627246f78e85d4fbadeee85c"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="10.48%" headers="mcps1.1.6.1.3 "><p id="en-us_topic_0000001058670841_en-us_topic_0000001058340523_ae685ead324a647bcba1bbb45c9402dd6"><a name="en-us_topic_0000001058670841_en-us_topic_0000001058340523_ae685ead324a647bcba1bbb45c9402dd6"></a><a name="en-us_topic_0000001058670841_en-us_topic_0000001058340523_ae685ead324a647bcba1bbb45c9402dd6"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.6.1.4 "><p id="en-us_topic_0000001058670841_p42461736102118"><a name="en-us_topic_0000001058670841_p42461736102118"></a><a name="en-us_topic_0000001058670841_p42461736102118"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="35.76%" headers="mcps1.1.6.1.5 "><p id="en-us_topic_0000001058670841_en-us_topic_0000001058340523_a692121725a9b4ebbae65cd22b94b672e"><a name="en-us_topic_0000001058670841_en-us_topic_0000001058340523_a692121725a9b4ebbae65cd22b94b672e"></a><a name="en-us_topic_0000001058670841_en-us_topic_0000001058340523_a692121725a9b4ebbae65cd22b94b672e"></a>Unique ID of a component.</p>
</td>
</tr>
<tr id="en-us_topic_0000001058670841_row13633131616239"><td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.1 "><p id="en-us_topic_0000001058670841_en-us_topic_0000001058340523_a7c032d302e1d437eac59680e066308b0"><a name="en-us_topic_0000001058670841_en-us_topic_0000001058340523_a7c032d302e1d437eac59680e066308b0"></a><a name="en-us_topic_0000001058670841_en-us_topic_0000001058340523_a7c032d302e1d437eac59680e066308b0"></a>style</p>
</td>
<td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.2 "><p id="en-us_topic_0000001058670841_en-us_topic_0000001058340523_a6ba72f5c52df4fba9b02b5dffa26677e"><a name="en-us_topic_0000001058670841_en-us_topic_0000001058340523_a6ba72f5c52df4fba9b02b5dffa26677e"></a><a name="en-us_topic_0000001058670841_en-us_topic_0000001058340523_a6ba72f5c52df4fba9b02b5dffa26677e"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="10.48%" headers="mcps1.1.6.1.3 "><p id="en-us_topic_0000001058670841_en-us_topic_0000001058340523_a23cec1f95fd04ff1b3b20f58844ea654"><a name="en-us_topic_0000001058670841_en-us_topic_0000001058340523_a23cec1f95fd04ff1b3b20f58844ea654"></a><a name="en-us_topic_0000001058670841_en-us_topic_0000001058340523_a23cec1f95fd04ff1b3b20f58844ea654"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.6.1.4 "><p id="en-us_topic_0000001058670841_p17246836142119"><a name="en-us_topic_0000001058670841_p17246836142119"></a><a name="en-us_topic_0000001058670841_p17246836142119"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="35.76%" headers="mcps1.1.6.1.5 "><p id="en-us_topic_0000001058670841_en-us_topic_0000001058340523_ab9c92d331da44a0e9114f6760340680a"><a name="en-us_topic_0000001058670841_en-us_topic_0000001058340523_ab9c92d331da44a0e9114f6760340680a"></a><a name="en-us_topic_0000001058670841_en-us_topic_0000001058340523_ab9c92d331da44a0e9114f6760340680a"></a>Style declaration of a component.</p>
</td>
</tr>
<tr id="en-us_topic_0000001058670841_row10634131610230"><td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.1 "><p id="en-us_topic_0000001058670841_en-us_topic_0000001058340523_a3e97d6d2a5b84e06bf619049840a00a8"><a name="en-us_topic_0000001058670841_en-us_topic_0000001058340523_a3e97d6d2a5b84e06bf619049840a00a8"></a><a name="en-us_topic_0000001058670841_en-us_topic_0000001058340523_a3e97d6d2a5b84e06bf619049840a00a8"></a>class</p>
</td>
<td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.2 "><p id="en-us_topic_0000001058670841_en-us_topic_0000001058340523_af0974175e9434735b035a4db9146aa04"><a name="en-us_topic_0000001058670841_en-us_topic_0000001058340523_af0974175e9434735b035a4db9146aa04"></a><a name="en-us_topic_0000001058670841_en-us_topic_0000001058340523_af0974175e9434735b035a4db9146aa04"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="10.48%" headers="mcps1.1.6.1.3 "><p id="en-us_topic_0000001058670841_en-us_topic_0000001058340523_aa5caace6225b440eba13dc2230f3ef0f"><a name="en-us_topic_0000001058670841_en-us_topic_0000001058340523_aa5caace6225b440eba13dc2230f3ef0f"></a><a name="en-us_topic_0000001058670841_en-us_topic_0000001058340523_aa5caace6225b440eba13dc2230f3ef0f"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.6.1.4 "><p id="en-us_topic_0000001058670841_p324614367213"><a name="en-us_topic_0000001058670841_p324614367213"></a><a name="en-us_topic_0000001058670841_p324614367213"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="35.76%" headers="mcps1.1.6.1.5 "><p id="en-us_topic_0000001058670841_en-us_topic_0000001058340523_a2f6321cf45ae481983a88dcc2f900900"><a name="en-us_topic_0000001058670841_en-us_topic_0000001058340523_a2f6321cf45ae481983a88dcc2f900900"></a><a name="en-us_topic_0000001058670841_en-us_topic_0000001058340523_a2f6321cf45ae481983a88dcc2f900900"></a>Style class of a component, which is used to refer to a style table.</p>
</td>
</tr>
<tr id="en-us_topic_0000001058670841_row1634171618236"><td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.1 "><p id="en-us_topic_0000001058670841_en-us_topic_0000001058340523_p1786251117156"><a name="en-us_topic_0000001058670841_en-us_topic_0000001058340523_p1786251117156"></a><a name="en-us_topic_0000001058670841_en-us_topic_0000001058340523_p1786251117156"></a>ref</p>
</td>
<td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.2 "><p id="en-us_topic_0000001058670841_en-us_topic_0000001058340523_p1086241119157"><a name="en-us_topic_0000001058670841_en-us_topic_0000001058340523_p1086241119157"></a><a name="en-us_topic_0000001058670841_en-us_topic_0000001058340523_p1086241119157"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="10.48%" headers="mcps1.1.6.1.3 "><p id="en-us_topic_0000001058670841_en-us_topic_0000001058340523_p586281111151"><a name="en-us_topic_0000001058670841_en-us_topic_0000001058340523_p586281111151"></a><a name="en-us_topic_0000001058670841_en-us_topic_0000001058340523_p586281111151"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.6.1.4 "><p id="en-us_topic_0000001058670841_p1624612362219"><a name="en-us_topic_0000001058670841_p1624612362219"></a><a name="en-us_topic_0000001058670841_p1624612362219"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="35.76%" headers="mcps1.1.6.1.5 "><p id="en-us_topic_0000001058670841_en-us_topic_0000001058340523_p113416153342"><a name="en-us_topic_0000001058670841_en-us_topic_0000001058340523_p113416153342"></a><a name="en-us_topic_0000001058670841_en-us_topic_0000001058340523_p113416153342"></a>Used to register reference information of child elements<span id="en-us_topic_0000001058670841_en-us_topic_0000001058340523_ph5815920163518"><a name="en-us_topic_0000001058670841_en-us_topic_0000001058340523_ph5815920163518"></a><a name="en-us_topic_0000001058670841_en-us_topic_0000001058340523_ph5815920163518"></a> or child components</span>. The reference information is registered with the parent component on <strong id="en-us_topic_0000001058670841_en-us_topic_0000001058340523_b08212202354"><a name="en-us_topic_0000001058670841_en-us_topic_0000001058340523_b08212202354"></a><a name="en-us_topic_0000001058670841_en-us_topic_0000001058340523_b08212202354"></a>$refs</strong>.</p>
</td>
</tr>
<tr id="en-us_topic_0000001058670841_row1263451617236"><td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.1 "><p id="en-us_topic_0000001058670841_en-us_topic_0000001058340523_a751c9d46a62348ec902c7fdf97468b9d"><a name="en-us_topic_0000001058670841_en-us_topic_0000001058340523_a751c9d46a62348ec902c7fdf97468b9d"></a><a name="en-us_topic_0000001058670841_en-us_topic_0000001058340523_a751c9d46a62348ec902c7fdf97468b9d"></a>data</p>
</td>
<td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.2 "><p id="en-us_topic_0000001058670841_en-us_topic_0000001058340523_a8e6d1bb4d0bc423fb8466ee3acd1882f"><a name="en-us_topic_0000001058670841_en-us_topic_0000001058340523_a8e6d1bb4d0bc423fb8466ee3acd1882f"></a><a name="en-us_topic_0000001058670841_en-us_topic_0000001058340523_a8e6d1bb4d0bc423fb8466ee3acd1882f"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="10.48%" headers="mcps1.1.6.1.3 "><p id="en-us_topic_0000001058670841_en-us_topic_0000001058340523_ab8cb15c9c3444b13b64945788131dce6"><a name="en-us_topic_0000001058670841_en-us_topic_0000001058340523_ab8cb15c9c3444b13b64945788131dce6"></a><a name="en-us_topic_0000001058670841_en-us_topic_0000001058340523_ab8cb15c9c3444b13b64945788131dce6"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.6.1.4 "><p id="en-us_topic_0000001058670841_p22471736132114"><a name="en-us_topic_0000001058670841_p22471736132114"></a><a name="en-us_topic_0000001058670841_p22471736132114"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="35.76%" headers="mcps1.1.6.1.5 "><p id="en-us_topic_0000001058670841_en-us_topic_0000001058340523_aa3f56a32296b4e85bcda2d2c00d0884f"><a name="en-us_topic_0000001058670841_en-us_topic_0000001058340523_aa3f56a32296b4e85bcda2d2c00d0884f"></a><a name="en-us_topic_0000001058670841_en-us_topic_0000001058340523_aa3f56a32296b4e85bcda2d2c00d0884f"></a>Attribute set for a component to facilitate data storage and reading.</p>
</td>
</tr>
</tbody>
</table>

Different types of progress bars support different attributes.

-   When the type is  **horizontal**,  **ring**, or  **scale-ring**, the following attributes are supported.

    <a name="en-us_topic_0000001058670841_table2074230113515"></a>
    <table><thead align="left"><tr id="en-us_topic_0000001058670841_row1474313083519"><th class="cellrowborder" valign="top" width="23.52%" id="mcps1.1.6.1.1"><p id="en-us_topic_0000001058670841_p107434016350"><a name="en-us_topic_0000001058670841_p107434016350"></a><a name="en-us_topic_0000001058670841_p107434016350"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="11.76%" id="mcps1.1.6.1.2"><p id="en-us_topic_0000001058670841_p37433017350"><a name="en-us_topic_0000001058670841_p37433017350"></a><a name="en-us_topic_0000001058670841_p37433017350"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="11.72%" id="mcps1.1.6.1.3"><p id="en-us_topic_0000001058670841_p1274316043517"><a name="en-us_topic_0000001058670841_p1274316043517"></a><a name="en-us_topic_0000001058670841_p1274316043517"></a>Default Value</p>
    </th>
    <th class="cellrowborder" valign="top" width="8%" id="mcps1.1.6.1.4"><p id="en-us_topic_0000001058670841_p37437033519"><a name="en-us_topic_0000001058670841_p37437033519"></a><a name="en-us_topic_0000001058670841_p37437033519"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="45%" id="mcps1.1.6.1.5"><p id="en-us_topic_0000001058670841_p174314073517"><a name="en-us_topic_0000001058670841_p174314073517"></a><a name="en-us_topic_0000001058670841_p174314073517"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="en-us_topic_0000001058670841_row974313023514"><td class="cellrowborder" valign="top" width="23.52%" headers="mcps1.1.6.1.1 "><p id="en-us_topic_0000001058670841_p674313053511"><a name="en-us_topic_0000001058670841_p674313053511"></a><a name="en-us_topic_0000001058670841_p674313053511"></a>percent</p>
    </td>
    <td class="cellrowborder" valign="top" width="11.76%" headers="mcps1.1.6.1.2 "><p id="en-us_topic_0000001058670841_p16743708352"><a name="en-us_topic_0000001058670841_p16743708352"></a><a name="en-us_topic_0000001058670841_p16743708352"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="11.72%" headers="mcps1.1.6.1.3 "><p id="en-us_topic_0000001058670841_p157435053511"><a name="en-us_topic_0000001058670841_p157435053511"></a><a name="en-us_topic_0000001058670841_p157435053511"></a>0</p>
    </td>
    <td class="cellrowborder" valign="top" width="8%" headers="mcps1.1.6.1.4 "><p id="en-us_topic_0000001058670841_p1374370133511"><a name="en-us_topic_0000001058670841_p1374370133511"></a><a name="en-us_topic_0000001058670841_p1374370133511"></a>No</p>
    </td>
    <td class="cellrowborder" valign="top" width="45%" headers="mcps1.1.6.1.5 "><p id="en-us_topic_0000001058670841_p5743704359"><a name="en-us_topic_0000001058670841_p5743704359"></a><a name="en-us_topic_0000001058670841_p5743704359"></a>Current progress. The value ranges from 0 to 100.</p>
    </td>
    </tr>
    <tr id="en-us_topic_0000001058670841_row16743104352"><td class="cellrowborder" valign="top" width="23.52%" headers="mcps1.1.6.1.1 "><p id="en-us_topic_0000001058670841_p1874313063517"><a name="en-us_topic_0000001058670841_p1874313063517"></a><a name="en-us_topic_0000001058670841_p1874313063517"></a>secondarypercent </p>
    </td>
    <td class="cellrowborder" valign="top" width="11.76%" headers="mcps1.1.6.1.2 "><p id="en-us_topic_0000001058670841_p127431015355"><a name="en-us_topic_0000001058670841_p127431015355"></a><a name="en-us_topic_0000001058670841_p127431015355"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="11.72%" headers="mcps1.1.6.1.3 "><p id="en-us_topic_0000001058670841_p1374317016354"><a name="en-us_topic_0000001058670841_p1374317016354"></a><a name="en-us_topic_0000001058670841_p1374317016354"></a>0</p>
    </td>
    <td class="cellrowborder" valign="top" width="8%" headers="mcps1.1.6.1.4 "><p id="en-us_topic_0000001058670841_p774320103519"><a name="en-us_topic_0000001058670841_p774320103519"></a><a name="en-us_topic_0000001058670841_p774320103519"></a>No</p>
    </td>
    <td class="cellrowborder" valign="top" width="45%" headers="mcps1.1.6.1.5 "><p id="en-us_topic_0000001058670841_p1974310173512"><a name="en-us_topic_0000001058670841_p1974310173512"></a><a name="en-us_topic_0000001058670841_p1974310173512"></a>Secondary progress. The value ranges from 0 to 100.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   When the type is  **ring**  or  **scale-ring**, the following attributes are supported.

    <a name="en-us_topic_0000001058670841_table2311759143520"></a>
    <table><thead align="left"><tr id="en-us_topic_0000001058670841_row13121059163511"><th class="cellrowborder" valign="top" width="11%" id="mcps1.1.6.1.1"><p id="en-us_topic_0000001058670841_p6312155919354"><a name="en-us_topic_0000001058670841_p6312155919354"></a><a name="en-us_topic_0000001058670841_p6312155919354"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="23%" id="mcps1.1.6.1.2"><p id="en-us_topic_0000001058670841_p73121259183512"><a name="en-us_topic_0000001058670841_p73121259183512"></a><a name="en-us_topic_0000001058670841_p73121259183512"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="13%" id="mcps1.1.6.1.3"><p id="en-us_topic_0000001058670841_p1312359103512"><a name="en-us_topic_0000001058670841_p1312359103512"></a><a name="en-us_topic_0000001058670841_p1312359103512"></a>Default Value</p>
    </th>
    <th class="cellrowborder" valign="top" width="8%" id="mcps1.1.6.1.4"><p id="en-us_topic_0000001058670841_p20312175983514"><a name="en-us_topic_0000001058670841_p20312175983514"></a><a name="en-us_topic_0000001058670841_p20312175983514"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="45%" id="mcps1.1.6.1.5"><p id="en-us_topic_0000001058670841_p123121159113515"><a name="en-us_topic_0000001058670841_p123121159113515"></a><a name="en-us_topic_0000001058670841_p123121159113515"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="en-us_topic_0000001058670841_row0312195911351"><td class="cellrowborder" valign="top" width="11%" headers="mcps1.1.6.1.1 "><p id="en-us_topic_0000001058670841_p43126599354"><a name="en-us_topic_0000001058670841_p43126599354"></a><a name="en-us_topic_0000001058670841_p43126599354"></a>clockwise </p>
    </td>
    <td class="cellrowborder" valign="top" width="23%" headers="mcps1.1.6.1.2 "><p id="en-us_topic_0000001058670841_p11312659113520"><a name="en-us_topic_0000001058670841_p11312659113520"></a><a name="en-us_topic_0000001058670841_p11312659113520"></a>boolean</p>
    </td>
    <td class="cellrowborder" valign="top" width="13%" headers="mcps1.1.6.1.3 "><p id="en-us_topic_0000001058670841_p6312359133511"><a name="en-us_topic_0000001058670841_p6312359133511"></a><a name="en-us_topic_0000001058670841_p6312359133511"></a>true</p>
    </td>
    <td class="cellrowborder" valign="top" width="8%" headers="mcps1.1.6.1.4 "><p id="en-us_topic_0000001058670841_p131218599350"><a name="en-us_topic_0000001058670841_p131218599350"></a><a name="en-us_topic_0000001058670841_p131218599350"></a>No</p>
    </td>
    <td class="cellrowborder" valign="top" width="45%" headers="mcps1.1.6.1.5 "><p id="en-us_topic_0000001058670841_p12312175919356"><a name="en-us_topic_0000001058670841_p12312175919356"></a><a name="en-us_topic_0000001058670841_p12312175919356"></a>Whether the ring progress bar uses clockwise.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   When the type is  **arc** or  **eclipse**<sup>5+</sup>, the following attribute is supported.

    <a name="en-us_topic_0000001058670841_table7731318123620"></a>
    <table><thead align="left"><tr id="en-us_topic_0000001058670841_row107321518113612"><th class="cellrowborder" valign="top" width="23.52%" id="mcps1.1.6.1.1"><p id="en-us_topic_0000001058670841_p9732118103619"><a name="en-us_topic_0000001058670841_p9732118103619"></a><a name="en-us_topic_0000001058670841_p9732118103619"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="11.76%" id="mcps1.1.6.1.2"><p id="en-us_topic_0000001058670841_p107321618103616"><a name="en-us_topic_0000001058670841_p107321618103616"></a><a name="en-us_topic_0000001058670841_p107321618103616"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="11.72%" id="mcps1.1.6.1.3"><p id="en-us_topic_0000001058670841_p127321718173617"><a name="en-us_topic_0000001058670841_p127321718173617"></a><a name="en-us_topic_0000001058670841_p127321718173617"></a>Default Value</p>
    </th>
    <th class="cellrowborder" valign="top" width="8%" id="mcps1.1.6.1.4"><p id="en-us_topic_0000001058670841_p17321418153617"><a name="en-us_topic_0000001058670841_p17321418153617"></a><a name="en-us_topic_0000001058670841_p17321418153617"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="45%" id="mcps1.1.6.1.5"><p id="en-us_topic_0000001058670841_p573281814364"><a name="en-us_topic_0000001058670841_p573281814364"></a><a name="en-us_topic_0000001058670841_p573281814364"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="en-us_topic_0000001058670841_row1773251817366"><td class="cellrowborder" valign="top" width="23.52%" headers="mcps1.1.6.1.1 "><p id="en-us_topic_0000001058670841_p27322018143612"><a name="en-us_topic_0000001058670841_p27322018143612"></a><a name="en-us_topic_0000001058670841_p27322018143612"></a>percent</p>
    </td>
    <td class="cellrowborder" valign="top" width="11.76%" headers="mcps1.1.6.1.2 "><p id="en-us_topic_0000001058670841_p37321718113612"><a name="en-us_topic_0000001058670841_p37321718113612"></a><a name="en-us_topic_0000001058670841_p37321718113612"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="11.72%" headers="mcps1.1.6.1.3 "><p id="en-us_topic_0000001058670841_p12732171817366"><a name="en-us_topic_0000001058670841_p12732171817366"></a><a name="en-us_topic_0000001058670841_p12732171817366"></a>0</p>
    </td>
    <td class="cellrowborder" valign="top" width="8%" headers="mcps1.1.6.1.4 "><p id="en-us_topic_0000001058670841_p8732101843613"><a name="en-us_topic_0000001058670841_p8732101843613"></a><a name="en-us_topic_0000001058670841_p8732101843613"></a>No</p>
    </td>
    <td class="cellrowborder" valign="top" width="45%" headers="mcps1.1.6.1.5 "><p id="en-us_topic_0000001058670841_p14732318113613"><a name="en-us_topic_0000001058670841_p14732318113613"></a><a name="en-us_topic_0000001058670841_p14732318113613"></a>Current progress. The value ranges from 0 to 100.</p>
    </td>
    </tr>
    </tbody>
    </table>


## Event<a name="en-us_topic_0000001058670841_section164912362544"></a>

<a name="en-us_topic_0000001058670841_table836435619510"></a>
<table><thead align="left"><tr id="en-us_topic_0000001058670841_row153658563517"><th class="cellrowborder" valign="top" width="24.852485248524854%" id="mcps1.1.4.1.1"><p id="en-us_topic_0000001058670841_en-us_topic_0000001058460527_a487aa1c493e84ca68567b4b65051674d"><a name="en-us_topic_0000001058670841_en-us_topic_0000001058460527_a487aa1c493e84ca68567b4b65051674d"></a><a name="en-us_topic_0000001058670841_en-us_topic_0000001058460527_a487aa1c493e84ca68567b4b65051674d"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="29.552955295529554%" id="mcps1.1.4.1.2"><p id="en-us_topic_0000001058670841_en-us_topic_0000001058460527_adc4b506cda3043508da6ee7649c12ca4"><a name="en-us_topic_0000001058670841_en-us_topic_0000001058460527_adc4b506cda3043508da6ee7649c12ca4"></a><a name="en-us_topic_0000001058670841_en-us_topic_0000001058460527_adc4b506cda3043508da6ee7649c12ca4"></a>Parameter</p>
</th>
<th class="cellrowborder" valign="top" width="45.5945594559456%" id="mcps1.1.4.1.3"><p id="en-us_topic_0000001058670841_en-us_topic_0000001058460527_a59e4cbe58a5c42a7a4585bc8365783bc"><a name="en-us_topic_0000001058670841_en-us_topic_0000001058460527_a59e4cbe58a5c42a7a4585bc8365783bc"></a><a name="en-us_topic_0000001058670841_en-us_topic_0000001058460527_a59e4cbe58a5c42a7a4585bc8365783bc"></a>Triggered when</p>
</th>
</tr>
</thead>
<tbody><tr id="en-us_topic_0000001058670841_row336512569516"><td class="cellrowborder" valign="top" width="24.852485248524854%" headers="mcps1.1.4.1.1 "><p id="en-us_topic_0000001058670841_en-us_topic_0000001058460527_a58fb4b1d870f466e955cf5ea879c4d4a"><a name="en-us_topic_0000001058670841_en-us_topic_0000001058460527_a58fb4b1d870f466e955cf5ea879c4d4a"></a><a name="en-us_topic_0000001058670841_en-us_topic_0000001058460527_a58fb4b1d870f466e955cf5ea879c4d4a"></a>touchstart</p>
</td>
<td class="cellrowborder" valign="top" width="29.552955295529554%" headers="mcps1.1.4.1.2 "><p id="en-us_topic_0000001058670841_en-us_topic_0000001058460527_abefebd99301b4bdebb798d1b9df24d8d"><a name="en-us_topic_0000001058670841_en-us_topic_0000001058460527_abefebd99301b4bdebb798d1b9df24d8d"></a><a name="en-us_topic_0000001058670841_en-us_topic_0000001058460527_abefebd99301b4bdebb798d1b9df24d8d"></a><a href="universal-events.md#en-us_topic_0000001058460527_tdb541af4e4db41d7a92e9b6e3c93f606">TouchEvent</a></p>
</td>
<td class="cellrowborder" valign="top" width="45.5945594559456%" headers="mcps1.1.4.1.3 "><p id="en-us_topic_0000001058670841_en-us_topic_0000001058460527_afa4290e2620f4f5fbdcb74dcae84e536"><a name="en-us_topic_0000001058670841_en-us_topic_0000001058460527_afa4290e2620f4f5fbdcb74dcae84e536"></a><a name="en-us_topic_0000001058670841_en-us_topic_0000001058460527_afa4290e2620f4f5fbdcb74dcae84e536"></a>The tapping starts</p>
</td>
</tr>
<tr id="en-us_topic_0000001058670841_row1236519563517"><td class="cellrowborder" valign="top" width="24.852485248524854%" headers="mcps1.1.4.1.1 "><p id="en-us_topic_0000001058670841_en-us_topic_0000001058460527_a23e0317cfee94650be4dcd2280c3e94e"><a name="en-us_topic_0000001058670841_en-us_topic_0000001058460527_a23e0317cfee94650be4dcd2280c3e94e"></a><a name="en-us_topic_0000001058670841_en-us_topic_0000001058460527_a23e0317cfee94650be4dcd2280c3e94e"></a>touchmove</p>
</td>
<td class="cellrowborder" valign="top" width="29.552955295529554%" headers="mcps1.1.4.1.2 "><p id="en-us_topic_0000001058670841_en-us_topic_0000001058460527_aea26e4f9575044dc8fb65080f3a6684a"><a name="en-us_topic_0000001058670841_en-us_topic_0000001058460527_aea26e4f9575044dc8fb65080f3a6684a"></a><a name="en-us_topic_0000001058670841_en-us_topic_0000001058460527_aea26e4f9575044dc8fb65080f3a6684a"></a><a href="universal-events.md#en-us_topic_0000001058460527_tdb541af4e4db41d7a92e9b6e3c93f606">TouchEvent</a></p>
</td>
<td class="cellrowborder" valign="top" width="45.5945594559456%" headers="mcps1.1.4.1.3 "><p id="en-us_topic_0000001058670841_en-us_topic_0000001058460527_a37f7cc43d82c4ee18512bd079349079d"><a name="en-us_topic_0000001058670841_en-us_topic_0000001058460527_a37f7cc43d82c4ee18512bd079349079d"></a><a name="en-us_topic_0000001058670841_en-us_topic_0000001058460527_a37f7cc43d82c4ee18512bd079349079d"></a>The tapping moves</p>
</td>
</tr>
<tr id="en-us_topic_0000001058670841_row18365145615516"><td class="cellrowborder" valign="top" width="24.852485248524854%" headers="mcps1.1.4.1.1 "><p id="en-us_topic_0000001058670841_en-us_topic_0000001058460527_ad0728eeac06143bbb4a6fdf1ed5c6d91"><a name="en-us_topic_0000001058670841_en-us_topic_0000001058460527_ad0728eeac06143bbb4a6fdf1ed5c6d91"></a><a name="en-us_topic_0000001058670841_en-us_topic_0000001058460527_ad0728eeac06143bbb4a6fdf1ed5c6d91"></a>touchcancel</p>
</td>
<td class="cellrowborder" valign="top" width="29.552955295529554%" headers="mcps1.1.4.1.2 "><p id="en-us_topic_0000001058670841_en-us_topic_0000001058460527_a59e2819eae2b4d3e935991b43156347b"><a name="en-us_topic_0000001058670841_en-us_topic_0000001058460527_a59e2819eae2b4d3e935991b43156347b"></a><a name="en-us_topic_0000001058670841_en-us_topic_0000001058460527_a59e2819eae2b4d3e935991b43156347b"></a><a href="universal-events.md#en-us_topic_0000001058460527_tdb541af4e4db41d7a92e9b6e3c93f606">TouchEvent</a></p>
</td>
<td class="cellrowborder" valign="top" width="45.5945594559456%" headers="mcps1.1.4.1.3 "><p id="en-us_topic_0000001058670841_en-us_topic_0000001058460527_a739d9ef0db624f6284554aeaeddffa0a"><a name="en-us_topic_0000001058670841_en-us_topic_0000001058460527_a739d9ef0db624f6284554aeaeddffa0a"></a><a name="en-us_topic_0000001058670841_en-us_topic_0000001058460527_a739d9ef0db624f6284554aeaeddffa0a"></a>The tapping is interrupted</p>
</td>
</tr>
<tr id="en-us_topic_0000001058670841_row63651566517"><td class="cellrowborder" valign="top" width="24.852485248524854%" headers="mcps1.1.4.1.1 "><p id="en-us_topic_0000001058670841_en-us_topic_0000001058460527_a233e2f6ff39f49fd97b8f233875d01d4"><a name="en-us_topic_0000001058670841_en-us_topic_0000001058460527_a233e2f6ff39f49fd97b8f233875d01d4"></a><a name="en-us_topic_0000001058670841_en-us_topic_0000001058460527_a233e2f6ff39f49fd97b8f233875d01d4"></a>touchend</p>
</td>
<td class="cellrowborder" valign="top" width="29.552955295529554%" headers="mcps1.1.4.1.2 "><p id="en-us_topic_0000001058670841_en-us_topic_0000001058460527_a439e69aaf158448e99b3c81cbc9fd624"><a name="en-us_topic_0000001058670841_en-us_topic_0000001058460527_a439e69aaf158448e99b3c81cbc9fd624"></a><a name="en-us_topic_0000001058670841_en-us_topic_0000001058460527_a439e69aaf158448e99b3c81cbc9fd624"></a><a href="universal-events.md#en-us_topic_0000001058460527_tdb541af4e4db41d7a92e9b6e3c93f606">TouchEvent</a></p>
</td>
<td class="cellrowborder" valign="top" width="45.5945594559456%" headers="mcps1.1.4.1.3 "><p id="en-us_topic_0000001058670841_en-us_topic_0000001058460527_a05c0fe4e05ef4154acee8a06ad56a2de"><a name="en-us_topic_0000001058670841_en-us_topic_0000001058460527_a05c0fe4e05ef4154acee8a06ad56a2de"></a><a name="en-us_topic_0000001058670841_en-us_topic_0000001058460527_a05c0fe4e05ef4154acee8a06ad56a2de"></a>The tapping ends</p>
</td>
</tr>
<tr id="en-us_topic_0000001058670841_row1536575611516"><td class="cellrowborder" valign="top" width="24.852485248524854%" headers="mcps1.1.4.1.1 "><p id="en-us_topic_0000001058670841_en-us_topic_0000001058460527_a2fb4de45b1594f6fa1a7da45ce0db57f"><a name="en-us_topic_0000001058670841_en-us_topic_0000001058460527_a2fb4de45b1594f6fa1a7da45ce0db57f"></a><a name="en-us_topic_0000001058670841_en-us_topic_0000001058460527_a2fb4de45b1594f6fa1a7da45ce0db57f"></a>click</p>
</td>
<td class="cellrowborder" valign="top" width="29.552955295529554%" headers="mcps1.1.4.1.2 "><p id="en-us_topic_0000001058670841_en-us_topic_0000001058460527_af86bf1da40504ed2a8d14213a42536ab"><a name="en-us_topic_0000001058670841_en-us_topic_0000001058460527_af86bf1da40504ed2a8d14213a42536ab"></a><a name="en-us_topic_0000001058670841_en-us_topic_0000001058460527_af86bf1da40504ed2a8d14213a42536ab"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="45.5945594559456%" headers="mcps1.1.4.1.3 "><p id="en-us_topic_0000001058670841_en-us_topic_0000001058460527_a1d32f00c38c440ddaa63c3f3e01d4e09"><a name="en-us_topic_0000001058670841_en-us_topic_0000001058460527_a1d32f00c38c440ddaa63c3f3e01d4e09"></a><a name="en-us_topic_0000001058670841_en-us_topic_0000001058460527_a1d32f00c38c440ddaa63c3f3e01d4e09"></a>A component is clicked</p>
</td>
</tr>
<tr id="en-us_topic_0000001058670841_row183661256758"><td class="cellrowborder" valign="top" width="24.852485248524854%" headers="mcps1.1.4.1.1 "><p id="en-us_topic_0000001058670841_en-us_topic_0000001058460527_aa7dc63d1b4924872bbff6a6a100e928f"><a name="en-us_topic_0000001058670841_en-us_topic_0000001058460527_aa7dc63d1b4924872bbff6a6a100e928f"></a><a name="en-us_topic_0000001058670841_en-us_topic_0000001058460527_aa7dc63d1b4924872bbff6a6a100e928f"></a>longpress</p>
</td>
<td class="cellrowborder" valign="top" width="29.552955295529554%" headers="mcps1.1.4.1.2 "><p id="en-us_topic_0000001058670841_en-us_topic_0000001058460527_a39186f4ff74544d89ace56ea87d9937b"><a name="en-us_topic_0000001058670841_en-us_topic_0000001058460527_a39186f4ff74544d89ace56ea87d9937b"></a><a name="en-us_topic_0000001058670841_en-us_topic_0000001058460527_a39186f4ff74544d89ace56ea87d9937b"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="45.5945594559456%" headers="mcps1.1.4.1.3 "><p id="en-us_topic_0000001058670841_en-us_topic_0000001058460527_a44b8585170304b5596c41714772e605e"><a name="en-us_topic_0000001058670841_en-us_topic_0000001058460527_a44b8585170304b5596c41714772e605e"></a><a name="en-us_topic_0000001058670841_en-us_topic_0000001058460527_a44b8585170304b5596c41714772e605e"></a>A component is long pressed</p>
</td>
</tr>
<tr id="en-us_topic_0000001058670841_row5366185613517"><td class="cellrowborder" valign="top" width="24.852485248524854%" headers="mcps1.1.4.1.1 "><p id="en-us_topic_0000001058670841_en-us_topic_0000001058460527_p12706561061"><a name="en-us_topic_0000001058670841_en-us_topic_0000001058460527_p12706561061"></a><a name="en-us_topic_0000001058670841_en-us_topic_0000001058460527_p12706561061"></a>swipe<sup id="en-us_topic_0000001058670841_en-us_topic_0000001058460527_sup35424382912"><a name="en-us_topic_0000001058670841_en-us_topic_0000001058460527_sup35424382912"></a><a name="en-us_topic_0000001058670841_en-us_topic_0000001058460527_sup35424382912"></a>5+</sup></p>
</td>
<td class="cellrowborder" valign="top" width="29.552955295529554%" headers="mcps1.1.4.1.2 "><p id="en-us_topic_0000001058670841_en-us_topic_0000001058460527_p11711056161"><a name="en-us_topic_0000001058670841_en-us_topic_0000001058460527_p11711056161"></a><a name="en-us_topic_0000001058670841_en-us_topic_0000001058460527_p11711056161"></a><a href="universal-events.md#en-us_topic_0000001058460527_table111811577714">SwipeEvent</a></p>
</td>
<td class="cellrowborder" valign="top" width="45.5945594559456%" headers="mcps1.1.4.1.3 "><p id="en-us_topic_0000001058670841_en-us_topic_0000001058460527_p2711556162"><a name="en-us_topic_0000001058670841_en-us_topic_0000001058460527_p2711556162"></a><a name="en-us_topic_0000001058670841_en-us_topic_0000001058460527_p2711556162"></a>A user quickly swipes on a component.</p>
</td>
</tr>
</tbody>
</table>

## Style<a name="en-us_topic_0000001058670841_section5775351116"></a>

Horizontal progress bar, of which  **type**  is  **horizontal**

<a name="en-us_topic_0000001058670841_t3c94bfbdec6f4ef08febb9d98feb69de"></a>
<table><thead align="left"><tr id="en-us_topic_0000001058670841_r53b2a254c9d645feb7260feb7770ab81"><th class="cellrowborder" valign="top" width="15.841584158415841%" id="mcps1.1.6.1.1"><p id="en-us_topic_0000001058670841_a5d8aa9ff3111452b8d0de276c88b44b5"><a name="en-us_topic_0000001058670841_a5d8aa9ff3111452b8d0de276c88b44b5"></a><a name="en-us_topic_0000001058670841_a5d8aa9ff3111452b8d0de276c88b44b5"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="11.941194119411943%" id="mcps1.1.6.1.2"><p id="en-us_topic_0000001058670841_afca70efa86e8438ebc402dcba820a465"><a name="en-us_topic_0000001058670841_afca70efa86e8438ebc402dcba820a465"></a><a name="en-us_topic_0000001058670841_afca70efa86e8438ebc402dcba820a465"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="26.672667266726673%" id="mcps1.1.6.1.3"><p id="en-us_topic_0000001058670841_ae063aedcf344463b9e0c5b2363d9441a"><a name="en-us_topic_0000001058670841_ae063aedcf344463b9e0c5b2363d9441a"></a><a name="en-us_topic_0000001058670841_ae063aedcf344463b9e0c5b2363d9441a"></a>Default Value</p>
</th>
<th class="cellrowborder" valign="top" width="6.9306930693069315%" id="mcps1.1.6.1.4"><p id="en-us_topic_0000001058670841_aba5cfe9b5b3c47ca890b6fca516a68d2"><a name="en-us_topic_0000001058670841_aba5cfe9b5b3c47ca890b6fca516a68d2"></a><a name="en-us_topic_0000001058670841_aba5cfe9b5b3c47ca890b6fca516a68d2"></a>Mandatory</p>
</th>
<th class="cellrowborder" valign="top" width="38.613861386138616%" id="mcps1.1.6.1.5"><p id="en-us_topic_0000001058670841_a91770a169ad44da99a22c882ce41bf86"><a name="en-us_topic_0000001058670841_a91770a169ad44da99a22c882ce41bf86"></a><a name="en-us_topic_0000001058670841_a91770a169ad44da99a22c882ce41bf86"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="en-us_topic_0000001058670841_r8d7d69585da2411897bd21e25bdf945b"><td class="cellrowborder" valign="top" width="15.841584158415841%" headers="mcps1.1.6.1.1 "><p id="en-us_topic_0000001058670841_a76c0c59c9ef342648d24b3def45827d8"><a name="en-us_topic_0000001058670841_a76c0c59c9ef342648d24b3def45827d8"></a><a name="en-us_topic_0000001058670841_a76c0c59c9ef342648d24b3def45827d8"></a>color</p>
</td>
<td class="cellrowborder" valign="top" width="11.941194119411943%" headers="mcps1.1.6.1.2 "><p id="en-us_topic_0000001058670841_a7e7fc8b3939f4d8c8da8246c80ae85b8"><a name="en-us_topic_0000001058670841_a7e7fc8b3939f4d8c8da8246c80ae85b8"></a><a name="en-us_topic_0000001058670841_a7e7fc8b3939f4d8c8da8246c80ae85b8"></a>&lt;color&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="26.672667266726673%" headers="mcps1.1.6.1.3 "><p id="en-us_topic_0000001058670841_p57261722152113"><a name="en-us_topic_0000001058670841_p57261722152113"></a><a name="en-us_topic_0000001058670841_p57261722152113"></a>#ff007dff</p>
</td>
<td class="cellrowborder" valign="top" width="6.9306930693069315%" headers="mcps1.1.6.1.4 "><p id="en-us_topic_0000001058670841_a45701b1485b44c0f97505e521710d4de"><a name="en-us_topic_0000001058670841_a45701b1485b44c0f97505e521710d4de"></a><a name="en-us_topic_0000001058670841_a45701b1485b44c0f97505e521710d4de"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="38.613861386138616%" headers="mcps1.1.6.1.5 "><p id="en-us_topic_0000001058670841_a5e442a4aedc84f0c95aa140a6ec8713c"><a name="en-us_topic_0000001058670841_a5e442a4aedc84f0c95aa140a6ec8713c"></a><a name="en-us_topic_0000001058670841_a5e442a4aedc84f0c95aa140a6ec8713c"></a>Color of the progress bar</p>
</td>
</tr>
<tr id="en-us_topic_0000001058670841_rfadd2e86d5a547398a318b82fe88ddcd"><td class="cellrowborder" valign="top" width="15.841584158415841%" headers="mcps1.1.6.1.1 "><p id="en-us_topic_0000001058670841_ae2d0777495164c409e85313fdf1c6a78"><a name="en-us_topic_0000001058670841_ae2d0777495164c409e85313fdf1c6a78"></a><a name="en-us_topic_0000001058670841_ae2d0777495164c409e85313fdf1c6a78"></a>stroke-width</p>
</td>
<td class="cellrowborder" valign="top" width="11.941194119411943%" headers="mcps1.1.6.1.2 "><p id="en-us_topic_0000001058670841_ab0e2ad53dc6545fab26a0dcaedafadcf"><a name="en-us_topic_0000001058670841_ab0e2ad53dc6545fab26a0dcaedafadcf"></a><a name="en-us_topic_0000001058670841_ab0e2ad53dc6545fab26a0dcaedafadcf"></a>&lt;length&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="26.672667266726673%" headers="mcps1.1.6.1.3 "><p id="en-us_topic_0000001058670841_p163627544235"><a name="en-us_topic_0000001058670841_p163627544235"></a><a name="en-us_topic_0000001058670841_p163627544235"></a>4px </p>
<p id="en-us_topic_0000001058670841_p149261166381"><a name="en-us_topic_0000001058670841_p149261166381"></a><a name="en-us_topic_0000001058670841_p149261166381"></a></p>
</td>
<td class="cellrowborder" valign="top" width="6.9306930693069315%" headers="mcps1.1.6.1.4 "><p id="en-us_topic_0000001058670841_a33f30b29f52e4f899dc0086815e1474c"><a name="en-us_topic_0000001058670841_a33f30b29f52e4f899dc0086815e1474c"></a><a name="en-us_topic_0000001058670841_a33f30b29f52e4f899dc0086815e1474c"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="38.613861386138616%" headers="mcps1.1.6.1.5 "><p id="en-us_topic_0000001058670841_acd7ffaee82cb4bfcb75c4b4c87dc512b"><a name="en-us_topic_0000001058670841_acd7ffaee82cb4bfcb75c4b4c87dc512b"></a><a name="en-us_topic_0000001058670841_acd7ffaee82cb4bfcb75c4b4c87dc512b"></a>Width of the progress bar</p>
</td>
</tr>
<tr id="en-us_topic_0000001058670841_row21738425241"><td class="cellrowborder" valign="top" width="15.841584158415841%" headers="mcps1.1.6.1.1 "><p id="en-us_topic_0000001058670841_p02571753202620"><a name="en-us_topic_0000001058670841_p02571753202620"></a><a name="en-us_topic_0000001058670841_p02571753202620"></a>background-color </p>
</td>
<td class="cellrowborder" valign="top" width="11.941194119411943%" headers="mcps1.1.6.1.2 "><p id="en-us_topic_0000001058670841_p8257155332614"><a name="en-us_topic_0000001058670841_p8257155332614"></a><a name="en-us_topic_0000001058670841_p8257155332614"></a>&lt;color&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="26.672667266726673%" headers="mcps1.1.6.1.3 "><p id="en-us_topic_0000001058670841_p1989061072811"><a name="en-us_topic_0000001058670841_p1989061072811"></a><a name="en-us_topic_0000001058670841_p1989061072811"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="6.9306930693069315%" headers="mcps1.1.6.1.4 "><p id="en-us_topic_0000001058670841_p82571153192611"><a name="en-us_topic_0000001058670841_p82571153192611"></a><a name="en-us_topic_0000001058670841_p82571153192611"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="38.613861386138616%" headers="mcps1.1.6.1.5 "><p id="en-us_topic_0000001058670841_p106571314275"><a name="en-us_topic_0000001058670841_p106571314275"></a><a name="en-us_topic_0000001058670841_p106571314275"></a>Background color of the progress bar</p>
</td>
</tr>
<tr id="en-us_topic_0000001058670841_row517332532717"><td class="cellrowborder" valign="top" width="15.841584158415841%" headers="mcps1.1.6.1.1 "><p id="en-us_topic_0000001058670841_p51731025172713"><a name="en-us_topic_0000001058670841_p51731025172713"></a><a name="en-us_topic_0000001058670841_p51731025172713"></a>secondary-color </p>
</td>
<td class="cellrowborder" valign="top" width="11.941194119411943%" headers="mcps1.1.6.1.2 "><p id="en-us_topic_0000001058670841_p1617322572712"><a name="en-us_topic_0000001058670841_p1617322572712"></a><a name="en-us_topic_0000001058670841_p1617322572712"></a>&lt;color&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="26.672667266726673%" headers="mcps1.1.6.1.3 "><p id="en-us_topic_0000001058670841_p117332552710"><a name="en-us_topic_0000001058670841_p117332552710"></a><a name="en-us_topic_0000001058670841_p117332552710"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="6.9306930693069315%" headers="mcps1.1.6.1.4 "><p id="en-us_topic_0000001058670841_p1917315255277"><a name="en-us_topic_0000001058670841_p1917315255277"></a><a name="en-us_topic_0000001058670841_p1917315255277"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="38.613861386138616%" headers="mcps1.1.6.1.5 "><p id="en-us_topic_0000001058670841_p2174122512271"><a name="en-us_topic_0000001058670841_p2174122512271"></a><a name="en-us_topic_0000001058670841_p2174122512271"></a>Color of the secondary progress bar</p>
</td>
</tr>
</tbody>
</table>

Circular progress bar \(**type**  is  **circular**\)

<a name="en-us_topic_0000001058670841_table1155720932812"></a>
<table><thead align="left"><tr id="en-us_topic_0000001058670841_row1655719918284"><th class="cellrowborder" valign="top" width="15.841584158415841%" id="mcps1.1.6.1.1"><p id="en-us_topic_0000001058670841_p95572913285"><a name="en-us_topic_0000001058670841_p95572913285"></a><a name="en-us_topic_0000001058670841_p95572913285"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="11.881188118811883%" id="mcps1.1.6.1.2"><p id="en-us_topic_0000001058670841_p75579962816"><a name="en-us_topic_0000001058670841_p75579962816"></a><a name="en-us_topic_0000001058670841_p75579962816"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="26.732673267326728%" id="mcps1.1.6.1.3"><p id="en-us_topic_0000001058670841_p4557896289"><a name="en-us_topic_0000001058670841_p4557896289"></a><a name="en-us_topic_0000001058670841_p4557896289"></a>Default Value</p>
</th>
<th class="cellrowborder" valign="top" width="6.9306930693069315%" id="mcps1.1.6.1.4"><p id="en-us_topic_0000001058670841_p75576914287"><a name="en-us_topic_0000001058670841_p75576914287"></a><a name="en-us_topic_0000001058670841_p75576914287"></a>Mandatory</p>
</th>
<th class="cellrowborder" valign="top" width="38.613861386138616%" id="mcps1.1.6.1.5"><p id="en-us_topic_0000001058670841_p1055711952815"><a name="en-us_topic_0000001058670841_p1055711952815"></a><a name="en-us_topic_0000001058670841_p1055711952815"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="en-us_topic_0000001058670841_row755710910285"><td class="cellrowborder" valign="top" width="15.841584158415841%" headers="mcps1.1.6.1.1 "><p id="en-us_topic_0000001058670841_p1055818912284"><a name="en-us_topic_0000001058670841_p1055818912284"></a><a name="en-us_topic_0000001058670841_p1055818912284"></a>color</p>
</td>
<td class="cellrowborder" valign="top" width="11.881188118811883%" headers="mcps1.1.6.1.2 "><p id="en-us_topic_0000001058670841_p115587942811"><a name="en-us_topic_0000001058670841_p115587942811"></a><a name="en-us_topic_0000001058670841_p115587942811"></a>&lt;color&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="26.732673267326728%" headers="mcps1.1.6.1.3 "><p id="en-us_topic_0000001058670841_p14706141316531"><a name="en-us_topic_0000001058670841_p14706141316531"></a><a name="en-us_topic_0000001058670841_p14706141316531"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="6.9306930693069315%" headers="mcps1.1.6.1.4 "><p id="en-us_topic_0000001058670841_p05583932819"><a name="en-us_topic_0000001058670841_p05583932819"></a><a name="en-us_topic_0000001058670841_p05583932819"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="38.613861386138616%" headers="mcps1.1.6.1.5 "><p id="en-us_topic_0000001058670841_p1955818992820"><a name="en-us_topic_0000001058670841_p1955818992820"></a><a name="en-us_topic_0000001058670841_p1955818992820"></a>Color of the dot on the loading progress bar</p>
</td>
</tr>
</tbody>
</table>

Ring or scale-ring progress bar \(**type**  is  **ring**  or  **scale-ring**\)

<a name="en-us_topic_0000001058670841_table1537513464181"></a>
<table><thead align="left"><tr id="en-us_topic_0000001058670841_row1237554618186"><th class="cellrowborder" valign="top" width="15.841584158415841%" id="mcps1.1.6.1.1"><p id="en-us_topic_0000001058670841_p637584661816"><a name="en-us_topic_0000001058670841_p637584661816"></a><a name="en-us_topic_0000001058670841_p637584661816"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="24.152415241524153%" id="mcps1.1.6.1.2"><p id="en-us_topic_0000001058670841_p53751346191816"><a name="en-us_topic_0000001058670841_p53751346191816"></a><a name="en-us_topic_0000001058670841_p53751346191816"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="14.461446144614461%" id="mcps1.1.6.1.3"><p id="en-us_topic_0000001058670841_p183751046171811"><a name="en-us_topic_0000001058670841_p183751046171811"></a><a name="en-us_topic_0000001058670841_p183751046171811"></a>Default Value</p>
</th>
<th class="cellrowborder" valign="top" width="6.9306930693069315%" id="mcps1.1.6.1.4"><p id="en-us_topic_0000001058670841_p173752046131812"><a name="en-us_topic_0000001058670841_p173752046131812"></a><a name="en-us_topic_0000001058670841_p173752046131812"></a>Mandatory</p>
</th>
<th class="cellrowborder" valign="top" width="38.613861386138616%" id="mcps1.1.6.1.5"><p id="en-us_topic_0000001058670841_p19375154617185"><a name="en-us_topic_0000001058670841_p19375154617185"></a><a name="en-us_topic_0000001058670841_p19375154617185"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="en-us_topic_0000001058670841_row1837534691818"><td class="cellrowborder" valign="top" width="15.841584158415841%" headers="mcps1.1.6.1.1 "><p id="en-us_topic_0000001058670841_p3849195472110"><a name="en-us_topic_0000001058670841_p3849195472110"></a><a name="en-us_topic_0000001058670841_p3849195472110"></a>color</p>
</td>
<td class="cellrowborder" valign="top" width="24.152415241524153%" headers="mcps1.1.6.1.2 "><p id="en-us_topic_0000001058670841_p14849205417213"><a name="en-us_topic_0000001058670841_p14849205417213"></a><a name="en-us_topic_0000001058670841_p14849205417213"></a>&lt;color&gt; | &lt;linear-gradient&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="14.461446144614461%" headers="mcps1.1.6.1.3 "><p id="en-us_topic_0000001058670841_p48495548218"><a name="en-us_topic_0000001058670841_p48495548218"></a><a name="en-us_topic_0000001058670841_p48495548218"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="6.9306930693069315%" headers="mcps1.1.6.1.4 "><p id="en-us_topic_0000001058670841_p284914543213"><a name="en-us_topic_0000001058670841_p284914543213"></a><a name="en-us_topic_0000001058670841_p284914543213"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="38.613861386138616%" headers="mcps1.1.6.1.5 "><p id="en-us_topic_0000001058670841_p151721122192918"><a name="en-us_topic_0000001058670841_p151721122192918"></a><a name="en-us_topic_0000001058670841_p151721122192918"></a>Color of the ring progress bar. The <strong id="en-us_topic_0000001058670841_b724283216309"><a name="en-us_topic_0000001058670841_b724283216309"></a><a name="en-us_topic_0000001058670841_b724283216309"></a>ring</strong> type supports the linear gradient color.</p>
<div class="note" id="en-us_topic_0000001058670841_note11079430164"><a name="en-us_topic_0000001058670841_note11079430164"></a><a name="en-us_topic_0000001058670841_note11079430164"></a><span class="notetitle"> NOTE: </span><div class="notebody"><p id="en-us_topic_0000001058670841_p1010744361610"><a name="en-us_topic_0000001058670841_p1010744361610"></a><a name="en-us_topic_0000001058670841_p1010744361610"></a>The linear gradient color supports only two color attribute formats, for example, <strong id="en-us_topic_0000001058670841_b1625485113015"><a name="en-us_topic_0000001058670841_b1625485113015"></a><a name="en-us_topic_0000001058670841_b1625485113015"></a>color = linear-gradient(#ff0000, #00ff00)</strong>.</p>
</div></div>
</td>
</tr>
<tr id="en-us_topic_0000001058670841_row14416102211213"><td class="cellrowborder" valign="top" width="15.841584158415841%" headers="mcps1.1.6.1.1 "><p id="en-us_topic_0000001058670841_p7850135412217"><a name="en-us_topic_0000001058670841_p7850135412217"></a><a name="en-us_topic_0000001058670841_p7850135412217"></a>background-color</p>
</td>
<td class="cellrowborder" valign="top" width="24.152415241524153%" headers="mcps1.1.6.1.2 "><p id="en-us_topic_0000001058670841_p188504547217"><a name="en-us_topic_0000001058670841_p188504547217"></a><a name="en-us_topic_0000001058670841_p188504547217"></a>&lt;color&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="14.461446144614461%" headers="mcps1.1.6.1.3 "><p id="en-us_topic_0000001058670841_p128500549213"><a name="en-us_topic_0000001058670841_p128500549213"></a><a name="en-us_topic_0000001058670841_p128500549213"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="6.9306930693069315%" headers="mcps1.1.6.1.4 "><p id="en-us_topic_0000001058670841_p985015547217"><a name="en-us_topic_0000001058670841_p985015547217"></a><a name="en-us_topic_0000001058670841_p985015547217"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="38.613861386138616%" headers="mcps1.1.6.1.5 "><p id="en-us_topic_0000001058670841_p1585014540215"><a name="en-us_topic_0000001058670841_p1585014540215"></a><a name="en-us_topic_0000001058670841_p1585014540215"></a>Background color of the ring progress bar.</p>
</td>
</tr>
<tr id="en-us_topic_0000001058670841_row1556129122116"><td class="cellrowborder" valign="top" width="15.841584158415841%" headers="mcps1.1.6.1.1 "><p id="en-us_topic_0000001058670841_p178506545218"><a name="en-us_topic_0000001058670841_p178506545218"></a><a name="en-us_topic_0000001058670841_p178506545218"></a>secondary-color</p>
</td>
<td class="cellrowborder" valign="top" width="24.152415241524153%" headers="mcps1.1.6.1.2 "><p id="en-us_topic_0000001058670841_p14850185442115"><a name="en-us_topic_0000001058670841_p14850185442115"></a><a name="en-us_topic_0000001058670841_p14850185442115"></a>&lt;color&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="14.461446144614461%" headers="mcps1.1.6.1.3 "><p id="en-us_topic_0000001058670841_p1285012546213"><a name="en-us_topic_0000001058670841_p1285012546213"></a><a name="en-us_topic_0000001058670841_p1285012546213"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="6.9306930693069315%" headers="mcps1.1.6.1.4 "><p id="en-us_topic_0000001058670841_p6850654172116"><a name="en-us_topic_0000001058670841_p6850654172116"></a><a name="en-us_topic_0000001058670841_p6850654172116"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="38.613861386138616%" headers="mcps1.1.6.1.5 "><p id="en-us_topic_0000001058670841_p16850115482113"><a name="en-us_topic_0000001058670841_p16850115482113"></a><a name="en-us_topic_0000001058670841_p16850115482113"></a>Color of the secondary ring progress bar.</p>
</td>
</tr>
<tr id="en-us_topic_0000001058670841_row109611629172118"><td class="cellrowborder" valign="top" width="15.841584158415841%" headers="mcps1.1.6.1.1 "><p id="en-us_topic_0000001058670841_p639523362212"><a name="en-us_topic_0000001058670841_p639523362212"></a><a name="en-us_topic_0000001058670841_p639523362212"></a>stroke-width</p>
</td>
<td class="cellrowborder" valign="top" width="24.152415241524153%" headers="mcps1.1.6.1.2 "><p id="en-us_topic_0000001058670841_p1239520334229"><a name="en-us_topic_0000001058670841_p1239520334229"></a><a name="en-us_topic_0000001058670841_p1239520334229"></a>&lt;length&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="14.461446144614461%" headers="mcps1.1.6.1.3 "><p id="en-us_topic_0000001058670841_p1798517818391"><a name="en-us_topic_0000001058670841_p1798517818391"></a><a name="en-us_topic_0000001058670841_p1798517818391"></a>10 px</p>
</td>
<td class="cellrowborder" valign="top" width="6.9306930693069315%" headers="mcps1.1.6.1.4 "><p id="en-us_topic_0000001058670841_p839517333229"><a name="en-us_topic_0000001058670841_p839517333229"></a><a name="en-us_topic_0000001058670841_p839517333229"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="38.613861386138616%" headers="mcps1.1.6.1.5 "><p id="en-us_topic_0000001058670841_p113951633172217"><a name="en-us_topic_0000001058670841_p113951633172217"></a><a name="en-us_topic_0000001058670841_p113951633172217"></a>Width of the ring progress bar.</p>
</td>
</tr>
<tr id="en-us_topic_0000001058670841_row6895103153610"><td class="cellrowborder" valign="top" width="15.841584158415841%" headers="mcps1.1.6.1.1 "><p id="en-us_topic_0000001058670841_p2087515118365"><a name="en-us_topic_0000001058670841_p2087515118365"></a><a name="en-us_topic_0000001058670841_p2087515118365"></a>scale-width</p>
</td>
<td class="cellrowborder" valign="top" width="24.152415241524153%" headers="mcps1.1.6.1.2 "><p id="en-us_topic_0000001058670841_p14875181119368"><a name="en-us_topic_0000001058670841_p14875181119368"></a><a name="en-us_topic_0000001058670841_p14875181119368"></a>&lt;length&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="14.461446144614461%" headers="mcps1.1.6.1.3 "><p id="en-us_topic_0000001058670841_p7875141183616"><a name="en-us_topic_0000001058670841_p7875141183616"></a><a name="en-us_topic_0000001058670841_p7875141183616"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="6.9306930693069315%" headers="mcps1.1.6.1.4 "><p id="en-us_topic_0000001058670841_p68751411153613"><a name="en-us_topic_0000001058670841_p68751411153613"></a><a name="en-us_topic_0000001058670841_p68751411153613"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="38.613861386138616%" headers="mcps1.1.6.1.5 "><p id="en-us_topic_0000001058670841_p5875211113612"><a name="en-us_topic_0000001058670841_p5875211113612"></a><a name="en-us_topic_0000001058670841_p5875211113612"></a>Scale thickness of the ring progress bar with a scale. This style takes effect only when the type is <strong id="en-us_topic_0000001058670841_b1286494621612"><a name="en-us_topic_0000001058670841_b1286494621612"></a><a name="en-us_topic_0000001058670841_b1286494621612"></a>scale-ring</strong>.</p>
</td>
</tr>
<tr id="en-us_topic_0000001058670841_row167446753610"><td class="cellrowborder" valign="top" width="15.841584158415841%" headers="mcps1.1.6.1.1 "><p id="en-us_topic_0000001058670841_p1687516115364"><a name="en-us_topic_0000001058670841_p1687516115364"></a><a name="en-us_topic_0000001058670841_p1687516115364"></a>scale-number</p>
</td>
<td class="cellrowborder" valign="top" width="24.152415241524153%" headers="mcps1.1.6.1.2 "><p id="en-us_topic_0000001058670841_p08765113363"><a name="en-us_topic_0000001058670841_p08765113363"></a><a name="en-us_topic_0000001058670841_p08765113363"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="14.461446144614461%" headers="mcps1.1.6.1.3 "><p id="en-us_topic_0000001058670841_p7876131133618"><a name="en-us_topic_0000001058670841_p7876131133618"></a><a name="en-us_topic_0000001058670841_p7876131133618"></a>120</p>
</td>
<td class="cellrowborder" valign="top" width="6.9306930693069315%" headers="mcps1.1.6.1.4 "><p id="en-us_topic_0000001058670841_p7876711133618"><a name="en-us_topic_0000001058670841_p7876711133618"></a><a name="en-us_topic_0000001058670841_p7876711133618"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="38.613861386138616%" headers="mcps1.1.6.1.5 "><p id="en-us_topic_0000001058670841_p1687671117364"><a name="en-us_topic_0000001058670841_p1687671117364"></a><a name="en-us_topic_0000001058670841_p1687671117364"></a>Number of scales of the ring progress bar with a scale. This style takes effect only when the type is <strong id="en-us_topic_0000001058670841_b155185320162"><a name="en-us_topic_0000001058670841_b155185320162"></a><a name="en-us_topic_0000001058670841_b155185320162"></a>scale-ring</strong>.</p>
</td>
</tr>
</tbody>
</table>

Arc progress bar, of which  **type**  is  **arc**

<a name="en-us_topic_0000001058670841_table146111227294"></a>
<table><thead align="left"><tr id="en-us_topic_0000001058670841_row961102182918"><th class="cellrowborder" valign="top" width="20.842084208420843%" id="mcps1.1.6.1.1"><p id="en-us_topic_0000001058670841_p1561114219295"><a name="en-us_topic_0000001058670841_p1561114219295"></a><a name="en-us_topic_0000001058670841_p1561114219295"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="12.221222122212222%" id="mcps1.1.6.1.2"><p id="en-us_topic_0000001058670841_p1661116214291"><a name="en-us_topic_0000001058670841_p1661116214291"></a><a name="en-us_topic_0000001058670841_p1661116214291"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="13.851385138513853%" id="mcps1.1.6.1.3"><p id="en-us_topic_0000001058670841_p86111628290"><a name="en-us_topic_0000001058670841_p86111628290"></a><a name="en-us_topic_0000001058670841_p86111628290"></a>Default Value</p>
</th>
<th class="cellrowborder" valign="top" width="11.08110811081108%" id="mcps1.1.6.1.4"><p id="en-us_topic_0000001058670841_p126111820294"><a name="en-us_topic_0000001058670841_p126111820294"></a><a name="en-us_topic_0000001058670841_p126111820294"></a>Mandatory</p>
</th>
<th class="cellrowborder" valign="top" width="42.004200420042004%" id="mcps1.1.6.1.5"><p id="en-us_topic_0000001058670841_p16611172162919"><a name="en-us_topic_0000001058670841_p16611172162919"></a><a name="en-us_topic_0000001058670841_p16611172162919"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="en-us_topic_0000001058670841_row161172152916"><td class="cellrowborder" valign="top" width="20.842084208420843%" headers="mcps1.1.6.1.1 "><p id="en-us_topic_0000001058670841_p1732210516366"><a name="en-us_topic_0000001058670841_p1732210516366"></a><a name="en-us_topic_0000001058670841_p1732210516366"></a>color</p>
</td>
<td class="cellrowborder" valign="top" width="12.221222122212222%" headers="mcps1.1.6.1.2 "><p id="en-us_topic_0000001058670841_p18322145153610"><a name="en-us_topic_0000001058670841_p18322145153610"></a><a name="en-us_topic_0000001058670841_p18322145153610"></a>&lt;color&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="13.851385138513853%" headers="mcps1.1.6.1.3 "><p id="en-us_topic_0000001058670841_p23221751143616"><a name="en-us_topic_0000001058670841_p23221751143616"></a><a name="en-us_topic_0000001058670841_p23221751143616"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="11.08110811081108%" headers="mcps1.1.6.1.4 "><p id="en-us_topic_0000001058670841_p432255116368"><a name="en-us_topic_0000001058670841_p432255116368"></a><a name="en-us_topic_0000001058670841_p432255116368"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="42.004200420042004%" headers="mcps1.1.6.1.5 "><p id="en-us_topic_0000001058670841_p2322051193614"><a name="en-us_topic_0000001058670841_p2322051193614"></a><a name="en-us_topic_0000001058670841_p2322051193614"></a>Color of the arc progress bar.</p>
</td>
</tr>
<tr id="en-us_topic_0000001058670841_row615084732920"><td class="cellrowborder" valign="top" width="20.842084208420843%" headers="mcps1.1.6.1.1 "><p id="en-us_topic_0000001058670841_p19233161103811"><a name="en-us_topic_0000001058670841_p19233161103811"></a><a name="en-us_topic_0000001058670841_p19233161103811"></a>background-color</p>
</td>
<td class="cellrowborder" valign="top" width="12.221222122212222%" headers="mcps1.1.6.1.2 "><p id="en-us_topic_0000001058670841_p1223319112386"><a name="en-us_topic_0000001058670841_p1223319112386"></a><a name="en-us_topic_0000001058670841_p1223319112386"></a>&lt;color&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="13.851385138513853%" headers="mcps1.1.6.1.3 "><p id="en-us_topic_0000001058670841_p7233111133814"><a name="en-us_topic_0000001058670841_p7233111133814"></a><a name="en-us_topic_0000001058670841_p7233111133814"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="11.08110811081108%" headers="mcps1.1.6.1.4 "><p id="en-us_topic_0000001058670841_p1723371143810"><a name="en-us_topic_0000001058670841_p1723371143810"></a><a name="en-us_topic_0000001058670841_p1723371143810"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="42.004200420042004%" headers="mcps1.1.6.1.5 "><p id="en-us_topic_0000001058670841_p6233511381"><a name="en-us_topic_0000001058670841_p6233511381"></a><a name="en-us_topic_0000001058670841_p6233511381"></a>Background color of the arc progress bar.</p>
</td>
</tr>
<tr id="en-us_topic_0000001058670841_row142659209408"><td class="cellrowborder" valign="top" width="20.842084208420843%" headers="mcps1.1.6.1.1 "><p id="en-us_topic_0000001058670841_p98738424715"><a name="en-us_topic_0000001058670841_p98738424715"></a><a name="en-us_topic_0000001058670841_p98738424715"></a>stroke-width</p>
</td>
<td class="cellrowborder" valign="top" width="12.221222122212222%" headers="mcps1.1.6.1.2 "><p id="en-us_topic_0000001058670841_p1687319424713"><a name="en-us_topic_0000001058670841_p1687319424713"></a><a name="en-us_topic_0000001058670841_p1687319424713"></a>&lt;length&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="13.851385138513853%" headers="mcps1.1.6.1.3 "><p id="en-us_topic_0000001058670841_p10840175014427"><a name="en-us_topic_0000001058670841_p10840175014427"></a><a name="en-us_topic_0000001058670841_p10840175014427"></a>4px</p>
</td>
<td class="cellrowborder" valign="top" width="11.08110811081108%" headers="mcps1.1.6.1.4 "><p id="en-us_topic_0000001058670841_p1873342671"><a name="en-us_topic_0000001058670841_p1873342671"></a><a name="en-us_topic_0000001058670841_p1873342671"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="42.004200420042004%" headers="mcps1.1.6.1.5 "><p id="en-us_topic_0000001058670841_p188730421175"><a name="en-us_topic_0000001058670841_p188730421175"></a><a name="en-us_topic_0000001058670841_p188730421175"></a>Width of the arc progress bar.</p>
<div class="note" id="en-us_topic_0000001058670841_note1436241013318"><a name="en-us_topic_0000001058670841_note1436241013318"></a><a name="en-us_topic_0000001058670841_note1436241013318"></a><span class="notetitle"> NOTE: </span><div class="notebody"><p id="en-us_topic_0000001058670841_p43626101533"><a name="en-us_topic_0000001058670841_p43626101533"></a><a name="en-us_topic_0000001058670841_p43626101533"></a>A larger width value means that the progress bar is closer to the center of the circle. The width is always within the radius range.</p>
</div></div>
</td>
</tr>
<tr id="en-us_topic_0000001058670841_row1280652394013"><td class="cellrowborder" valign="top" width="20.842084208420843%" headers="mcps1.1.6.1.1 "><p id="en-us_topic_0000001058670841_p1192581376"><a name="en-us_topic_0000001058670841_p1192581376"></a><a name="en-us_topic_0000001058670841_p1192581376"></a>start-angle</p>
</td>
<td class="cellrowborder" valign="top" width="12.221222122212222%" headers="mcps1.1.6.1.2 "><p id="en-us_topic_0000001058670841_p1719258277"><a name="en-us_topic_0000001058670841_p1719258277"></a><a name="en-us_topic_0000001058670841_p1719258277"></a>&lt;deg&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="13.851385138513853%" headers="mcps1.1.6.1.3 "><p id="en-us_topic_0000001058670841_p320958271"><a name="en-us_topic_0000001058670841_p320958271"></a><a name="en-us_topic_0000001058670841_p320958271"></a>240</p>
</td>
<td class="cellrowborder" valign="top" width="11.08110811081108%" headers="mcps1.1.6.1.4 "><p id="en-us_topic_0000001058670841_p16203581878"><a name="en-us_topic_0000001058670841_p16203581878"></a><a name="en-us_topic_0000001058670841_p16203581878"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="42.004200420042004%" headers="mcps1.1.6.1.5 "><p id="en-us_topic_0000001058670841_p112012582717"><a name="en-us_topic_0000001058670841_p112012582717"></a><a name="en-us_topic_0000001058670841_p112012582717"></a>Start angle of the arc progress bar, which starts from the direction of zero o'clock. The value ranges from 0 to 360 degrees (clockwise).</p>
</td>
</tr>
<tr id="en-us_topic_0000001058670841_row16108193116405"><td class="cellrowborder" valign="top" width="20.842084208420843%" headers="mcps1.1.6.1.1 "><p id="en-us_topic_0000001058670841_p204511458375"><a name="en-us_topic_0000001058670841_p204511458375"></a><a name="en-us_topic_0000001058670841_p204511458375"></a>total-angle</p>
</td>
<td class="cellrowborder" valign="top" width="12.221222122212222%" headers="mcps1.1.6.1.2 "><p id="en-us_topic_0000001058670841_p154521558371"><a name="en-us_topic_0000001058670841_p154521558371"></a><a name="en-us_topic_0000001058670841_p154521558371"></a>&lt;deg&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="13.851385138513853%" headers="mcps1.1.6.1.3 "><p id="en-us_topic_0000001058670841_p74521558678"><a name="en-us_topic_0000001058670841_p74521558678"></a><a name="en-us_topic_0000001058670841_p74521558678"></a>240</p>
</td>
<td class="cellrowborder" valign="top" width="11.08110811081108%" headers="mcps1.1.6.1.4 "><p id="en-us_topic_0000001058670841_p14521158774"><a name="en-us_topic_0000001058670841_p14521158774"></a><a name="en-us_topic_0000001058670841_p14521158774"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="42.004200420042004%" headers="mcps1.1.6.1.5 "><p id="en-us_topic_0000001058670841_p745211583716"><a name="en-us_topic_0000001058670841_p745211583716"></a><a name="en-us_topic_0000001058670841_p745211583716"></a>Total length of the arc progress bar. The value ranges from –360 to 360. A negative number indicates anticlockwise.</p>
</td>
</tr>
<tr id="en-us_topic_0000001058670841_row132153110406"><td class="cellrowborder" valign="top" width="20.842084208420843%" headers="mcps1.1.6.1.1 "><p id="en-us_topic_0000001058670841_p2489145710819"><a name="en-us_topic_0000001058670841_p2489145710819"></a><a name="en-us_topic_0000001058670841_p2489145710819"></a>center-x</p>
</td>
<td class="cellrowborder" valign="top" width="12.221222122212222%" headers="mcps1.1.6.1.2 "><p id="en-us_topic_0000001058670841_p1378435564714"><a name="en-us_topic_0000001058670841_p1378435564714"></a><a name="en-us_topic_0000001058670841_p1378435564714"></a>&lt;length&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="13.851385138513853%" headers="mcps1.1.6.1.3 "><p id="en-us_topic_0000001058670841_p548911574817"><a name="en-us_topic_0000001058670841_p548911574817"></a><a name="en-us_topic_0000001058670841_p548911574817"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="11.08110811081108%" headers="mcps1.1.6.1.4 "><p id="en-us_topic_0000001058670841_p144897571081"><a name="en-us_topic_0000001058670841_p144897571081"></a><a name="en-us_topic_0000001058670841_p144897571081"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="42.004200420042004%" headers="mcps1.1.6.1.5 "><p id="en-us_topic_0000001058670841_p154894570813"><a name="en-us_topic_0000001058670841_p154894570813"></a><a name="en-us_topic_0000001058670841_p154894570813"></a>Center of the arc progress bar (with the upper left corner of this widget as the coordinate origin). This style must be used together with <strong id="en-us_topic_0000001058670841_b10862143410196"><a name="en-us_topic_0000001058670841_b10862143410196"></a><a name="en-us_topic_0000001058670841_b10862143410196"></a>center-y</strong> and <strong id="en-us_topic_0000001058670841_b3868934121914"><a name="en-us_topic_0000001058670841_b3868934121914"></a><a name="en-us_topic_0000001058670841_b3868934121914"></a>radius</strong>.</p>
</td>
</tr>
<tr id="en-us_topic_0000001058670841_row1488143111409"><td class="cellrowborder" valign="top" width="20.842084208420843%" headers="mcps1.1.6.1.1 "><p id="en-us_topic_0000001058670841_p1898218571884"><a name="en-us_topic_0000001058670841_p1898218571884"></a><a name="en-us_topic_0000001058670841_p1898218571884"></a>center-y</p>
</td>
<td class="cellrowborder" valign="top" width="12.221222122212222%" headers="mcps1.1.6.1.2 "><p id="en-us_topic_0000001058670841_p76431057204714"><a name="en-us_topic_0000001058670841_p76431057204714"></a><a name="en-us_topic_0000001058670841_p76431057204714"></a>&lt;length&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="13.851385138513853%" headers="mcps1.1.6.1.3 "><p id="en-us_topic_0000001058670841_p4982557182"><a name="en-us_topic_0000001058670841_p4982557182"></a><a name="en-us_topic_0000001058670841_p4982557182"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="11.08110811081108%" headers="mcps1.1.6.1.4 "><p id="en-us_topic_0000001058670841_p1982165710812"><a name="en-us_topic_0000001058670841_p1982165710812"></a><a name="en-us_topic_0000001058670841_p1982165710812"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="42.004200420042004%" headers="mcps1.1.6.1.5 "><p id="en-us_topic_0000001058670841_p09827579819"><a name="en-us_topic_0000001058670841_p09827579819"></a><a name="en-us_topic_0000001058670841_p09827579819"></a>Center of the arc progress bar (with the upper left corner of this widget as the coordinate origin). This style must be used together with <strong id="en-us_topic_0000001058670841_b13704558131918"><a name="en-us_topic_0000001058670841_b13704558131918"></a><a name="en-us_topic_0000001058670841_b13704558131918"></a>center-x</strong> and <strong id="en-us_topic_0000001058670841_b1070995818199"><a name="en-us_topic_0000001058670841_b1070995818199"></a><a name="en-us_topic_0000001058670841_b1070995818199"></a>radius</strong>.</p>
</td>
</tr>
<tr id="en-us_topic_0000001058670841_row294916317406"><td class="cellrowborder" valign="top" width="20.842084208420843%" headers="mcps1.1.6.1.1 "><p id="en-us_topic_0000001058670841_p1073135912815"><a name="en-us_topic_0000001058670841_p1073135912815"></a><a name="en-us_topic_0000001058670841_p1073135912815"></a>radius</p>
</td>
<td class="cellrowborder" valign="top" width="12.221222122212222%" headers="mcps1.1.6.1.2 "><p id="en-us_topic_0000001058670841_p6732759386"><a name="en-us_topic_0000001058670841_p6732759386"></a><a name="en-us_topic_0000001058670841_p6732759386"></a>&lt;length&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="13.851385138513853%" headers="mcps1.1.6.1.3 "><p id="en-us_topic_0000001058670841_p127321959086"><a name="en-us_topic_0000001058670841_p127321959086"></a><a name="en-us_topic_0000001058670841_p127321959086"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="11.08110811081108%" headers="mcps1.1.6.1.4 "><p id="en-us_topic_0000001058670841_p197325591783"><a name="en-us_topic_0000001058670841_p197325591783"></a><a name="en-us_topic_0000001058670841_p197325591783"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="42.004200420042004%" headers="mcps1.1.6.1.5 "><p id="en-us_topic_0000001058670841_p2732759982"><a name="en-us_topic_0000001058670841_p2732759982"></a><a name="en-us_topic_0000001058670841_p2732759982"></a>Radius of the arc progress bar. This style must be used together with <strong id="en-us_topic_0000001058670841_b14309114232012"><a name="en-us_topic_0000001058670841_b14309114232012"></a><a name="en-us_topic_0000001058670841_b14309114232012"></a>center-x</strong> and <strong id="en-us_topic_0000001058670841_b14474174412014"><a name="en-us_topic_0000001058670841_b14474174412014"></a><a name="en-us_topic_0000001058670841_b14474174412014"></a>center-y</strong>.</p>
</td>
</tr>
</tbody>
</table>

type=eclipse<sup>5+</sup>

<a name="en-us_topic_0000001058670841_table5191155852510"></a>
<table><thead align="left"><tr id="en-us_topic_0000001058670841_row119205815258"><th class="cellrowborder" valign="top" width="20.842084208420843%" id="mcps1.1.6.1.1"><p id="en-us_topic_0000001058670841_p1719211587252"><a name="en-us_topic_0000001058670841_p1719211587252"></a><a name="en-us_topic_0000001058670841_p1719211587252"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="12.221222122212222%" id="mcps1.1.6.1.2"><p id="en-us_topic_0000001058670841_p15192185817259"><a name="en-us_topic_0000001058670841_p15192185817259"></a><a name="en-us_topic_0000001058670841_p15192185817259"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="13.851385138513853%" id="mcps1.1.6.1.3"><p id="en-us_topic_0000001058670841_p11192125852514"><a name="en-us_topic_0000001058670841_p11192125852514"></a><a name="en-us_topic_0000001058670841_p11192125852514"></a>Default Value</p>
</th>
<th class="cellrowborder" valign="top" width="11.08110811081108%" id="mcps1.1.6.1.4"><p id="en-us_topic_0000001058670841_p16192155813256"><a name="en-us_topic_0000001058670841_p16192155813256"></a><a name="en-us_topic_0000001058670841_p16192155813256"></a>Mandatory</p>
</th>
<th class="cellrowborder" valign="top" width="42.004200420042004%" id="mcps1.1.6.1.5"><p id="en-us_topic_0000001058670841_p91921583256"><a name="en-us_topic_0000001058670841_p91921583256"></a><a name="en-us_topic_0000001058670841_p91921583256"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="en-us_topic_0000001058670841_row1819265882513"><td class="cellrowborder" valign="top" width="20.842084208420843%" headers="mcps1.1.6.1.1 "><p id="en-us_topic_0000001058670841_p181923589254"><a name="en-us_topic_0000001058670841_p181923589254"></a><a name="en-us_topic_0000001058670841_p181923589254"></a>color</p>
</td>
<td class="cellrowborder" valign="top" width="12.221222122212222%" headers="mcps1.1.6.1.2 "><p id="en-us_topic_0000001058670841_p11192258182515"><a name="en-us_topic_0000001058670841_p11192258182515"></a><a name="en-us_topic_0000001058670841_p11192258182515"></a>&lt;color&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="13.851385138513853%" headers="mcps1.1.6.1.3 "><p id="en-us_topic_0000001058670841_p519235819253"><a name="en-us_topic_0000001058670841_p519235819253"></a><a name="en-us_topic_0000001058670841_p519235819253"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="11.08110811081108%" headers="mcps1.1.6.1.4 "><p id="en-us_topic_0000001058670841_p19192115802515"><a name="en-us_topic_0000001058670841_p19192115802515"></a><a name="en-us_topic_0000001058670841_p19192115802515"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="42.004200420042004%" headers="mcps1.1.6.1.5 "><p id="en-us_topic_0000001058670841_p1019225811258"><a name="en-us_topic_0000001058670841_p1019225811258"></a><a name="en-us_topic_0000001058670841_p1019225811258"></a>Color of the eclipse progress bar.</p>
</td>
</tr>
<tr id="en-us_topic_0000001058670841_row11920586256"><td class="cellrowborder" valign="top" width="20.842084208420843%" headers="mcps1.1.6.1.1 "><p id="en-us_topic_0000001058670841_p719210585259"><a name="en-us_topic_0000001058670841_p719210585259"></a><a name="en-us_topic_0000001058670841_p719210585259"></a>background-color</p>
</td>
<td class="cellrowborder" valign="top" width="12.221222122212222%" headers="mcps1.1.6.1.2 "><p id="en-us_topic_0000001058670841_p121920588253"><a name="en-us_topic_0000001058670841_p121920588253"></a><a name="en-us_topic_0000001058670841_p121920588253"></a>&lt;color&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="13.851385138513853%" headers="mcps1.1.6.1.3 "><p id="en-us_topic_0000001058670841_p16193125814250"><a name="en-us_topic_0000001058670841_p16193125814250"></a><a name="en-us_topic_0000001058670841_p16193125814250"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="11.08110811081108%" headers="mcps1.1.6.1.4 "><p id="en-us_topic_0000001058670841_p4193115813254"><a name="en-us_topic_0000001058670841_p4193115813254"></a><a name="en-us_topic_0000001058670841_p4193115813254"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="42.004200420042004%" headers="mcps1.1.6.1.5 "><p id="en-us_topic_0000001058670841_p1319395813257"><a name="en-us_topic_0000001058670841_p1319395813257"></a><a name="en-us_topic_0000001058670841_p1319395813257"></a>Background color of the eclipse progress bar.</p>
</td>
</tr>
</tbody>
</table>

In addition to the preceding styles, all types of process bars support the following styles.

<a name="en-us_topic_0000001058670841_table149851649561"></a>
<table><thead align="left"><tr id="en-us_topic_0000001058670841_row8985164195618"><th class="cellrowborder" valign="top" width="23.11768823117688%" id="mcps1.1.6.1.1"><p id="en-us_topic_0000001058670841_en-us_topic_0000001059340528_a14a0c012a26248cfbec6b13dcc4f2cbe"><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_a14a0c012a26248cfbec6b13dcc4f2cbe"></a><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_a14a0c012a26248cfbec6b13dcc4f2cbe"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="20.477952204779523%" id="mcps1.1.6.1.2"><p id="en-us_topic_0000001058670841_en-us_topic_0000001059340528_a8dc328a555a74157a00de86181fc3a7b"><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_a8dc328a555a74157a00de86181fc3a7b"></a><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_a8dc328a555a74157a00de86181fc3a7b"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="8.869113088691131%" id="mcps1.1.6.1.3"><p id="en-us_topic_0000001058670841_en-us_topic_0000001059340528_a41a31e48d0c74ad4982add2655515c82"><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_a41a31e48d0c74ad4982add2655515c82"></a><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_a41a31e48d0c74ad4982add2655515c82"></a>Default Value</p>
</th>
<th class="cellrowborder" valign="top" width="7.519248075192481%" id="mcps1.1.6.1.4"><p id="en-us_topic_0000001058670841_p16985943568"><a name="en-us_topic_0000001058670841_p16985943568"></a><a name="en-us_topic_0000001058670841_p16985943568"></a>Mandatory</p>
</th>
<th class="cellrowborder" valign="top" width="40.01599840015999%" id="mcps1.1.6.1.5"><p id="en-us_topic_0000001058670841_en-us_topic_0000001059340528_af7a726e456f7485c87bd4e0527bc6584"><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_af7a726e456f7485c87bd4e0527bc6584"></a><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_af7a726e456f7485c87bd4e0527bc6584"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="en-us_topic_0000001058670841_row2985194145619"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="en-us_topic_0000001058670841_en-us_topic_0000001059340528_a8bc81ecef4934adf91deb1d6167045d7"><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_a8bc81ecef4934adf91deb1d6167045d7"></a><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_a8bc81ecef4934adf91deb1d6167045d7"></a>width</p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p id="en-us_topic_0000001058670841_en-us_topic_0000001059340528_a59692217b9c94353a020a2f0a20f01a7"><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_a59692217b9c94353a020a2f0a20f01a7"></a><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_a59692217b9c94353a020a2f0a20f01a7"></a>&lt;length&gt; | &lt;percentage&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p id="en-us_topic_0000001058670841_en-us_topic_0000001059340528_p3948114217528"><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_p3948114217528"></a><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_p3948114217528"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p id="en-us_topic_0000001058670841_p1898594155611"><a name="en-us_topic_0000001058670841_p1898594155611"></a><a name="en-us_topic_0000001058670841_p1898594155611"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="en-us_topic_0000001058670841_en-us_topic_0000001059340528_p624653010258"><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_p624653010258"></a><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_p624653010258"></a>Component width.</p>
<p id="en-us_topic_0000001058670841_en-us_topic_0000001059340528_p84811050134010"><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_p84811050134010"></a><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_p84811050134010"></a>If this attribute is not set, the width required for the element content is used. </p>
</td>
</tr>
<tr id="en-us_topic_0000001058670841_row69851445611"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="en-us_topic_0000001058670841_en-us_topic_0000001059340528_a738cc687552c4b8cb1aa9f9e7d9ea8c2"><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_a738cc687552c4b8cb1aa9f9e7d9ea8c2"></a><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_a738cc687552c4b8cb1aa9f9e7d9ea8c2"></a>height</p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p id="en-us_topic_0000001058670841_en-us_topic_0000001059340528_a82c5d9c65b3646ec92afe5f0f47a2149"><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_a82c5d9c65b3646ec92afe5f0f47a2149"></a><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_a82c5d9c65b3646ec92afe5f0f47a2149"></a>&lt;length&gt;<span id="en-us_topic_0000001058670841_en-us_topic_0000001059340528_ph11748352163918"><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_ph11748352163918"></a><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_ph11748352163918"></a></span> | &lt;percentage&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p id="en-us_topic_0000001058670841_en-us_topic_0000001059340528_a7e6c7daafecf475888d0420835662eb4"><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_a7e6c7daafecf475888d0420835662eb4"></a><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_a7e6c7daafecf475888d0420835662eb4"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p id="en-us_topic_0000001058670841_p99861149561"><a name="en-us_topic_0000001058670841_p99861149561"></a><a name="en-us_topic_0000001058670841_p99861149561"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="en-us_topic_0000001058670841_en-us_topic_0000001059340528_p1477601264"><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_p1477601264"></a><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_p1477601264"></a>Component height.</p>
<p id="en-us_topic_0000001058670841_en-us_topic_0000001059340528_p208761554184020"><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_p208761554184020"></a><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_p208761554184020"></a>If this length attribute is not set, the length required for the element content is used. </p>
</td>
</tr>
<tr id="en-us_topic_0000001058670841_row169861540565"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="en-us_topic_0000001058670841_en-us_topic_0000001059340528_a8ff18465b8f0453c836067e5902b7eb6"><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_a8ff18465b8f0453c836067e5902b7eb6"></a><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_a8ff18465b8f0453c836067e5902b7eb6"></a>padding</p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p id="en-us_topic_0000001058670841_en-us_topic_0000001059340528_a53628f36a25a4823a901d5b66860f44e"><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_a53628f36a25a4823a901d5b66860f44e"></a><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_a53628f36a25a4823a901d5b66860f44e"></a>&lt;length&gt; | &lt;percentage&gt;<sup id="en-us_topic_0000001058670841_en-us_topic_0000001059340528_sup1886516813013"><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_sup1886516813013"></a><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_sup1886516813013"></a>5+</sup></p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p id="en-us_topic_0000001058670841_en-us_topic_0000001059340528_adc824deaee924821a47a798b589f22c8"><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_adc824deaee924821a47a798b589f22c8"></a><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_adc824deaee924821a47a798b589f22c8"></a>0</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p id="en-us_topic_0000001058670841_en-us_topic_0000001059340528_p19729127112814"><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_p19729127112814"></a><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_p19729127112814"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="en-us_topic_0000001058670841_en-us_topic_0000001059340528_p157435053316"><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_p157435053316"></a><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_p157435053316"></a>Shorthand attribute to set all padding attributes.</p>
<div class="p" id="en-us_topic_0000001058670841_en-us_topic_0000001059340528_a68a6d5ddc59c49f0aaddd82e75932524"><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_a68a6d5ddc59c49f0aaddd82e75932524"></a><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_a68a6d5ddc59c49f0aaddd82e75932524"></a>The attribute can have one to four values:<a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_ul15202134923211"></a><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_ul15202134923211"></a><ul id="en-us_topic_0000001058670841_en-us_topic_0000001059340528_ul15202134923211"><li><p id="en-us_topic_0000001058670841_en-us_topic_0000001059340528_p10614155353215"><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_p10614155353215"></a><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_p10614155353215"></a>If you set only one value, it specifies the padding for four sides.</p>
</li><li><p id="en-us_topic_0000001058670841_en-us_topic_0000001059340528_p10614175393216"><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_p10614175393216"></a><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_p10614175393216"></a>If you set two values, the first value specifies the top and bottom padding, and the second value specifies the left and right padding.</p>
</li><li><p id="en-us_topic_0000001058670841_en-us_topic_0000001059340528_p8614205393214"><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_p8614205393214"></a><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_p8614205393214"></a>If you set three values, the first value specifies the top padding, the second value specifies the left and right padding, and the third value specifies the bottom padding.</p>
</li><li><p id="en-us_topic_0000001058670841_en-us_topic_0000001059340528_p106141853193215"><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_p106141853193215"></a><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_p106141853193215"></a>If you set four values, they respectively specify the padding for top, right, bottom, and left sides (in clockwise order).</p>
</li></ul>
</div>
</td>
</tr>
<tr id="en-us_topic_0000001058670841_row69871640565"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="en-us_topic_0000001058670841_en-us_topic_0000001059340528_ab0185a7b5a4944f3b38f8c71c8ca794d"><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_ab0185a7b5a4944f3b38f8c71c8ca794d"></a><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_ab0185a7b5a4944f3b38f8c71c8ca794d"></a>padding-[left|top|right|bottom]</p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p id="en-us_topic_0000001058670841_en-us_topic_0000001059340528_a49dd523e2f1b4253a19231e776dc1951"><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_a49dd523e2f1b4253a19231e776dc1951"></a><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_a49dd523e2f1b4253a19231e776dc1951"></a>&lt;length&gt; | &lt;percentage&gt;<sup id="en-us_topic_0000001058670841_en-us_topic_0000001059340528_sup19949912807"><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_sup19949912807"></a><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_sup19949912807"></a>5+</sup></p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p id="en-us_topic_0000001058670841_en-us_topic_0000001059340528_af52ecd93919b4fa08ae4d376e3d544a2"><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_af52ecd93919b4fa08ae4d376e3d544a2"></a><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_af52ecd93919b4fa08ae4d376e3d544a2"></a>0</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p id="en-us_topic_0000001058670841_en-us_topic_0000001059340528_p11729374289"><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_p11729374289"></a><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_p11729374289"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="en-us_topic_0000001058670841_en-us_topic_0000001059340528_a3575ab240d384ab1a21119ea3428ab7d"><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_a3575ab240d384ab1a21119ea3428ab7d"></a><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_a3575ab240d384ab1a21119ea3428ab7d"></a>Left, top, right, and bottom padding (in px).</p>
</td>
</tr>
<tr id="en-us_topic_0000001058670841_row149872419562"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="en-us_topic_0000001058670841_en-us_topic_0000001059340528_p769124717365"><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_p769124717365"></a><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_p769124717365"></a>padding-[start|end]</p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p id="en-us_topic_0000001058670841_en-us_topic_0000001059340528_p157617124374"><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_p157617124374"></a><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_p157617124374"></a>&lt;length&gt; | &lt;percentage&gt;<sup id="en-us_topic_0000001058670841_en-us_topic_0000001059340528_sup8490161513019"><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_sup8490161513019"></a><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_sup8490161513019"></a>5+</sup></p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p id="en-us_topic_0000001058670841_en-us_topic_0000001059340528_p1069144703616"><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_p1069144703616"></a><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_p1069144703616"></a>0</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p id="en-us_topic_0000001058670841_en-us_topic_0000001059340528_p1373027182819"><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_p1373027182819"></a><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_p1373027182819"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="en-us_topic_0000001058670841_en-us_topic_0000001059340528_p1269184753610"><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_p1269184753610"></a><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_p1269184753610"></a>Start and end padding.</p>
</td>
</tr>
<tr id="en-us_topic_0000001058670841_row498744105616"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="en-us_topic_0000001058670841_en-us_topic_0000001059340528_afa508e5429d948b2b561943d6b2f0f31"><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_afa508e5429d948b2b561943d6b2f0f31"></a><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_afa508e5429d948b2b561943d6b2f0f31"></a>margin</p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p id="en-us_topic_0000001058670841_en-us_topic_0000001059340528_a4dab4f9d97a74a27a45b7ef1d2ab08e6"><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_a4dab4f9d97a74a27a45b7ef1d2ab08e6"></a><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_a4dab4f9d97a74a27a45b7ef1d2ab08e6"></a>&lt;length&gt; | &lt;percentage&gt;<sup id="en-us_topic_0000001058670841_en-us_topic_0000001059340528_sup1433352175220"><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_sup1433352175220"></a><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_sup1433352175220"></a>5+</sup></p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p id="en-us_topic_0000001058670841_en-us_topic_0000001059340528_a5e3c234d78214e8180b51d237adda154"><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_a5e3c234d78214e8180b51d237adda154"></a><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_a5e3c234d78214e8180b51d237adda154"></a>0</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p id="en-us_topic_0000001058670841_en-us_topic_0000001059340528_p4730774285"><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_p4730774285"></a><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_p4730774285"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="en-us_topic_0000001058670841_en-us_topic_0000001059340528_a1d350e36a773420baf5ebb930cd5ad66"><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_a1d350e36a773420baf5ebb930cd5ad66"></a><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_a1d350e36a773420baf5ebb930cd5ad66"></a>Shorthand attribute to set margins for all sides in a declaration. The attribute can have one to four values:</p>
<a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_ul5333133311105"></a><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_ul5333133311105"></a><ul id="en-us_topic_0000001058670841_en-us_topic_0000001059340528_ul5333133311105"><li><p id="en-us_topic_0000001058670841_en-us_topic_0000001059340528_p03345339103"><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_p03345339103"></a><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_p03345339103"></a>If you set only one value, it specifies the margin for all the four sides.</p>
</li><li><p id="en-us_topic_0000001058670841_en-us_topic_0000001059340528_p1133420334108"><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_p1133420334108"></a><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_p1133420334108"></a>If you set two values, the first value is for the top and bottom sides and the second value for the left and right sides.</p>
</li><li><p id="en-us_topic_0000001058670841_en-us_topic_0000001059340528_p193341533191015"><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_p193341533191015"></a><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_p193341533191015"></a>If you set three values, the first value is for the top, the second value for the left and right, and the third value for the bottom.</p>
</li><li><p id="en-us_topic_0000001058670841_en-us_topic_0000001059340528_p733412334102"><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_p733412334102"></a><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_p733412334102"></a>If you set four values, they are margins for top, right, bottom, and left sides, respectively.</p>
</li></ul>
</td>
</tr>
<tr id="en-us_topic_0000001058670841_row119881144567"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="en-us_topic_0000001058670841_en-us_topic_0000001059340528_a70939a36b2b04dd8bec21f5bddc8637e"><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_a70939a36b2b04dd8bec21f5bddc8637e"></a><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_a70939a36b2b04dd8bec21f5bddc8637e"></a>margin-[left|top|right|bottom]</p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p id="en-us_topic_0000001058670841_en-us_topic_0000001059340528_ae53ac9ac370d483990e04ea9789c1e49"><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_ae53ac9ac370d483990e04ea9789c1e49"></a><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_ae53ac9ac370d483990e04ea9789c1e49"></a>&lt;length&gt; | &lt;percentage&gt;<sup id="en-us_topic_0000001058670841_en-us_topic_0000001059340528_sup378331720532"><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_sup378331720532"></a><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_sup378331720532"></a>5+</sup></p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p id="en-us_topic_0000001058670841_en-us_topic_0000001059340528_a180cd037e6174e5c82f35a3a66b6f2ec"><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_a180cd037e6174e5c82f35a3a66b6f2ec"></a><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_a180cd037e6174e5c82f35a3a66b6f2ec"></a>0</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p id="en-us_topic_0000001058670841_en-us_topic_0000001059340528_p773013742811"><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_p773013742811"></a><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_p773013742811"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="en-us_topic_0000001058670841_en-us_topic_0000001059340528_a487d09add6e54c5c89fa4f22e9318271"><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_a487d09add6e54c5c89fa4f22e9318271"></a><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_a487d09add6e54c5c89fa4f22e9318271"></a>Left, top, right, and bottom margins.</p>
</td>
</tr>
<tr id="en-us_topic_0000001058670841_row10988746561"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="en-us_topic_0000001058670841_en-us_topic_0000001059340528_p9492107123816"><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_p9492107123816"></a><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_p9492107123816"></a>margin-[start|end]</p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p id="en-us_topic_0000001058670841_en-us_topic_0000001059340528_p157617124374_1"><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_p157617124374_1"></a><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_p157617124374_1"></a>&lt;length&gt; | &lt;percentage&gt;<sup id="en-us_topic_0000001058670841_en-us_topic_0000001059340528_sup8490161513019_1"><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_sup8490161513019_1"></a><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_sup8490161513019_1"></a>5+</sup></p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p id="en-us_topic_0000001058670841_en-us_topic_0000001059340528_p1549213793811"><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_p1549213793811"></a><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_p1549213793811"></a>0</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p id="en-us_topic_0000001058670841_p189883475616"><a name="en-us_topic_0000001058670841_p189883475616"></a><a name="en-us_topic_0000001058670841_p189883475616"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="en-us_topic_0000001058670841_en-us_topic_0000001059340528_p1049212715388"><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_p1049212715388"></a><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_p1049212715388"></a>Start and end margins.</p>
</td>
</tr>
<tr id="en-us_topic_0000001058670841_row6988146563"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="en-us_topic_0000001058670841_en-us_topic_0000001059340528_a222bb48f24014f2eb2b16a1a840bbebb"><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_a222bb48f24014f2eb2b16a1a840bbebb"></a><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_a222bb48f24014f2eb2b16a1a840bbebb"></a>border</p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p id="en-us_topic_0000001058670841_en-us_topic_0000001059340528_a79b4eaf9983c44d0aad39ff04d0997a8"><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_a79b4eaf9983c44d0aad39ff04d0997a8"></a><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_a79b4eaf9983c44d0aad39ff04d0997a8"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p id="en-us_topic_0000001058670841_en-us_topic_0000001059340528_aac320f4f0a42401aa7fa778d9829d77c"><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_aac320f4f0a42401aa7fa778d9829d77c"></a><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_aac320f4f0a42401aa7fa778d9829d77c"></a>0</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p id="en-us_topic_0000001058670841_p99892465610"><a name="en-us_topic_0000001058670841_p99892465610"></a><a name="en-us_topic_0000001058670841_p99892465610"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="en-us_topic_0000001058670841_en-us_topic_0000001059340528_a9cd962871a4c467a8e1ef452621d5cd7"><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_a9cd962871a4c467a8e1ef452621d5cd7"></a><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_a9cd962871a4c467a8e1ef452621d5cd7"></a>Shorthand attribute to set all borders. You can set <strong id="en-us_topic_0000001058670841_en-us_topic_0000001059340528_b79128342503"><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_b79128342503"></a><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_b79128342503"></a>border-width</strong>, <strong id="en-us_topic_0000001058670841_en-us_topic_0000001059340528_b9366173919505"><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_b9366173919505"></a><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_b9366173919505"></a>border-style</strong>, and <strong id="en-us_topic_0000001058670841_en-us_topic_0000001059340528_b184351248205019"><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_b184351248205019"></a><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_b184351248205019"></a>border-color</strong> in sequence. Default values are used for attributes that are not set.</p>
</td>
</tr>
<tr id="en-us_topic_0000001058670841_row5989124155612"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="en-us_topic_0000001058670841_en-us_topic_0000001059340528_a987708c0864a4128af094334f1b024b3"><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_a987708c0864a4128af094334f1b024b3"></a><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_a987708c0864a4128af094334f1b024b3"></a>border-style</p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p id="en-us_topic_0000001058670841_en-us_topic_0000001059340528_p513631613319"><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_p513631613319"></a><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_p513631613319"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p id="en-us_topic_0000001058670841_en-us_topic_0000001059340528_a2567083af59c40e58e3e4d9b0ddf1485"><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_a2567083af59c40e58e3e4d9b0ddf1485"></a><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_a2567083af59c40e58e3e4d9b0ddf1485"></a>solid</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p id="en-us_topic_0000001058670841_p1099016414564"><a name="en-us_topic_0000001058670841_p1099016414564"></a><a name="en-us_topic_0000001058670841_p1099016414564"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="en-us_topic_0000001058670841_en-us_topic_0000001059340528_p342285712314"><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_p342285712314"></a><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_p342285712314"></a>Shorthand attribute to set the style for all borders. Available values are as follows:</p>
<a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_ul1470834505612"></a><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_ul1470834505612"></a><ul id="en-us_topic_0000001058670841_en-us_topic_0000001059340528_ul1470834505612"><li><strong id="en-us_topic_0000001058670841_en-us_topic_0000001059340528_b143453286360"><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_b143453286360"></a><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_b143453286360"></a>dotted</strong>: Dotted border. The radius of a dot is half of border-width.</li><li><strong id="en-us_topic_0000001058670841_en-us_topic_0000001059340528_b792117280367"><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_b792117280367"></a><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_b792117280367"></a>dashed</strong>: Dashed border</li></ul>
<a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_ul15621125545612"></a><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_ul15621125545612"></a><ul id="en-us_topic_0000001058670841_en-us_topic_0000001059340528_ul15621125545612"><li><strong id="en-us_topic_0000001058670841_en-us_topic_0000001059340528_b1335862963610"><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_b1335862963610"></a><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_b1335862963610"></a>solid</strong>: Solid border</li></ul>
</td>
</tr>
<tr id="en-us_topic_0000001058670841_row19915465619"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="en-us_topic_0000001058670841_en-us_topic_0000001059340528_p119531437370"><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_p119531437370"></a><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_p119531437370"></a>border-[left|top|right|bottom]-style</p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p id="en-us_topic_0000001058670841_en-us_topic_0000001059340528_p129532037175"><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_p129532037175"></a><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_p129532037175"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p id="en-us_topic_0000001058670841_en-us_topic_0000001059340528_p495312372717"><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_p495312372717"></a><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_p495312372717"></a>solid</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p id="en-us_topic_0000001058670841_en-us_topic_0000001059340528_p169534375717"><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_p169534375717"></a><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_p169534375717"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="en-us_topic_0000001058670841_en-us_topic_0000001059340528_p595353718719"><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_p595353718719"></a><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_p595353718719"></a>Styles of the left, top, right, and bottom borders. The available values are <strong id="en-us_topic_0000001058670841_en-us_topic_0000001059340528_b17769171311540"><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_b17769171311540"></a><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_b17769171311540"></a>dotted</strong>, <strong id="en-us_topic_0000001058670841_en-us_topic_0000001059340528_b237141519547"><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_b237141519547"></a><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_b237141519547"></a>dashed</strong>, and <strong id="en-us_topic_0000001058670841_en-us_topic_0000001059340528_b8949161613540"><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_b8949161613540"></a><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_b8949161613540"></a>solid</strong>.</p>
</td>
</tr>
<tr id="en-us_topic_0000001058670841_row6991941568"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="en-us_topic_0000001058670841_en-us_topic_0000001059340528_a8afd82b1aba547d3b0188b749518b2de"><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_a8afd82b1aba547d3b0188b749518b2de"></a><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_a8afd82b1aba547d3b0188b749518b2de"></a>border-[left|top|right|bottom]</p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p id="en-us_topic_0000001058670841_en-us_topic_0000001059340528_ac4b8a3b39e5446b5868f1f2989dc9590"><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_ac4b8a3b39e5446b5868f1f2989dc9590"></a><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_ac4b8a3b39e5446b5868f1f2989dc9590"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p id="en-us_topic_0000001058670841_en-us_topic_0000001059340528_a3420bc82bd17458ab82fa996ade7064c"><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_a3420bc82bd17458ab82fa996ade7064c"></a><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_a3420bc82bd17458ab82fa996ade7064c"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p id="en-us_topic_0000001058670841_en-us_topic_0000001059340528_p67303762810"><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_p67303762810"></a><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_p67303762810"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="en-us_topic_0000001058670841_en-us_topic_0000001059340528_af4178a066c344412afbd38f4b0c44818"><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_af4178a066c344412afbd38f4b0c44818"></a><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_af4178a066c344412afbd38f4b0c44818"></a>Shorthand attribute to set the borders for every side respectively. You can set <strong id="en-us_topic_0000001058670841_en-us_topic_0000001059340528_b122415514554"><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_b122415514554"></a><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_b122415514554"></a>border-width</strong>, <strong id="en-us_topic_0000001058670841_en-us_topic_0000001059340528_b12296178135513"><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_b12296178135513"></a><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_b12296178135513"></a>border-style</strong>, and <strong id="en-us_topic_0000001058670841_en-us_topic_0000001059340528_b1129701210553"><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_b1129701210553"></a><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_b1129701210553"></a>border-color</strong> in sequence. Default values are used for attributes that are not set.</p>
</td>
</tr>
<tr id="en-us_topic_0000001058670841_row1699234195618"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="en-us_topic_0000001058670841_en-us_topic_0000001059340528_adf0e0afedc774afca9cda0e509391029"><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_adf0e0afedc774afca9cda0e509391029"></a><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_adf0e0afedc774afca9cda0e509391029"></a>border-width</p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p id="en-us_topic_0000001058670841_en-us_topic_0000001059340528_a0782ea2c45eb4864a8df82f30dd2cd5f"><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_a0782ea2c45eb4864a8df82f30dd2cd5f"></a><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_a0782ea2c45eb4864a8df82f30dd2cd5f"></a>&lt;length&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p id="en-us_topic_0000001058670841_en-us_topic_0000001059340528_a395cbedd521145bd820b9171ee2dd7ac"><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_a395cbedd521145bd820b9171ee2dd7ac"></a><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_a395cbedd521145bd820b9171ee2dd7ac"></a>0</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p id="en-us_topic_0000001058670841_p19921144563"><a name="en-us_topic_0000001058670841_p19921144563"></a><a name="en-us_topic_0000001058670841_p19921144563"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="en-us_topic_0000001058670841_en-us_topic_0000001059340528_a7ae60621ea3341818a03bfdffa641894"><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_a7ae60621ea3341818a03bfdffa641894"></a><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_a7ae60621ea3341818a03bfdffa641894"></a>Shorthand attribute to set the width of all borders<span id="en-us_topic_0000001058670841_en-us_topic_0000001059340528_ph07997369365"><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_ph07997369365"></a><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_ph07997369365"></a>, or separately set the width of each border</span>.</p>
</td>
</tr>
<tr id="en-us_topic_0000001058670841_row799216445613"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="en-us_topic_0000001058670841_en-us_topic_0000001059340528_a7371edc07c664266a2e1866f31ad0d0c"><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_a7371edc07c664266a2e1866f31ad0d0c"></a><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_a7371edc07c664266a2e1866f31ad0d0c"></a>border-[left|top|right|bottom]-width</p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p id="en-us_topic_0000001058670841_en-us_topic_0000001059340528_a2faa532b841948a7b6598542b4eccc7b"><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_a2faa532b841948a7b6598542b4eccc7b"></a><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_a2faa532b841948a7b6598542b4eccc7b"></a>&lt;length&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p id="en-us_topic_0000001058670841_en-us_topic_0000001059340528_a87f38cfa47f54bc18c32f9671c0f9ca6"><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_a87f38cfa47f54bc18c32f9671c0f9ca6"></a><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_a87f38cfa47f54bc18c32f9671c0f9ca6"></a>0</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p id="en-us_topic_0000001058670841_p199922416566"><a name="en-us_topic_0000001058670841_p199922416566"></a><a name="en-us_topic_0000001058670841_p199922416566"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="en-us_topic_0000001058670841_en-us_topic_0000001059340528_a20386e66c3834d5f96cf9435c4715c5b"><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_a20386e66c3834d5f96cf9435c4715c5b"></a><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_a20386e66c3834d5f96cf9435c4715c5b"></a>Attribute to set widths of left, top, right, and bottom borders.</p>
</td>
</tr>
<tr id="en-us_topic_0000001058670841_row15992194105613"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="en-us_topic_0000001058670841_en-us_topic_0000001059340528_a40a816cf0a03489d81f209a8aa7d81a6"><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_a40a816cf0a03489d81f209a8aa7d81a6"></a><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_a40a816cf0a03489d81f209a8aa7d81a6"></a>border-color</p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p id="en-us_topic_0000001058670841_en-us_topic_0000001059340528_afcc7c948ae0947b2a78002d31f2f9748"><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_afcc7c948ae0947b2a78002d31f2f9748"></a><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_afcc7c948ae0947b2a78002d31f2f9748"></a>&lt;color&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p id="en-us_topic_0000001058670841_en-us_topic_0000001059340528_ae0909d2b896342f9b2196fe0dce72920"><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_ae0909d2b896342f9b2196fe0dce72920"></a><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_ae0909d2b896342f9b2196fe0dce72920"></a>black</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p id="en-us_topic_0000001058670841_p99931746562"><a name="en-us_topic_0000001058670841_p99931746562"></a><a name="en-us_topic_0000001058670841_p99931746562"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="en-us_topic_0000001058670841_en-us_topic_0000001059340528_a76fd98995e1d4217aa703fecd69325c7"><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_a76fd98995e1d4217aa703fecd69325c7"></a><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_a76fd98995e1d4217aa703fecd69325c7"></a>Shorthand attribute to set the color of all borders<span id="en-us_topic_0000001058670841_en-us_topic_0000001059340528_ph9587639113619"><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_ph9587639113619"></a><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_ph9587639113619"></a>, or separately set the color of each border</span>.</p>
</td>
</tr>
<tr id="en-us_topic_0000001058670841_row2099384185618"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="en-us_topic_0000001058670841_en-us_topic_0000001059340528_a2afc646d6a2549548bcd5c4b9bed1fb5"><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_a2afc646d6a2549548bcd5c4b9bed1fb5"></a><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_a2afc646d6a2549548bcd5c4b9bed1fb5"></a>border-[left|top|right|bottom]-color</p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p id="en-us_topic_0000001058670841_en-us_topic_0000001059340528_a34556866a4f54f5da88f148fc698867b"><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_a34556866a4f54f5da88f148fc698867b"></a><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_a34556866a4f54f5da88f148fc698867b"></a>&lt;color&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p id="en-us_topic_0000001058670841_en-us_topic_0000001059340528_a8ff58e18553846a38e82c69149e2aa30"><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_a8ff58e18553846a38e82c69149e2aa30"></a><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_a8ff58e18553846a38e82c69149e2aa30"></a>black</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p id="en-us_topic_0000001058670841_p4993347563"><a name="en-us_topic_0000001058670841_p4993347563"></a><a name="en-us_topic_0000001058670841_p4993347563"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="en-us_topic_0000001058670841_en-us_topic_0000001059340528_a5c85947d388c4c7fbf0de07b022bb44e"><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_a5c85947d388c4c7fbf0de07b022bb44e"></a><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_a5c85947d388c4c7fbf0de07b022bb44e"></a>Attribute to set colors of left, top, right, and bottom borders.</p>
</td>
</tr>
<tr id="en-us_topic_0000001058670841_row2099312416562"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="en-us_topic_0000001058670841_en-us_topic_0000001059340528_a65974e3078c447a383fb9237cc4ffa32"><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_a65974e3078c447a383fb9237cc4ffa32"></a><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_a65974e3078c447a383fb9237cc4ffa32"></a>border-radius</p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p id="en-us_topic_0000001058670841_en-us_topic_0000001059340528_a413fd0aea8b243349a19f825e96ee8b6"><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_a413fd0aea8b243349a19f825e96ee8b6"></a><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_a413fd0aea8b243349a19f825e96ee8b6"></a>&lt;length&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p id="en-us_topic_0000001058670841_en-us_topic_0000001059340528_af786857698c74e259f52589a6670a0a1"><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_af786857698c74e259f52589a6670a0a1"></a><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_af786857698c74e259f52589a6670a0a1"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p id="en-us_topic_0000001058670841_en-us_topic_0000001059340528_p67306752816"><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_p67306752816"></a><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_p67306752816"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="en-us_topic_0000001058670841_en-us_topic_0000001059340528_a52ca834f42124d3b8b12bbf54914fc96"><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_a52ca834f42124d3b8b12bbf54914fc96"></a><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_a52ca834f42124d3b8b12bbf54914fc96"></a>Attribute to set the radius of round borders of an element. <span id="en-us_topic_0000001058670841_en-us_topic_0000001059340528_ph1249443123611"><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_ph1249443123611"></a><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_ph1249443123611"></a>This attribute cannot be used to set the width, color, or style of a specific border. To set the width or color, you need to set <strong id="en-us_topic_0000001058670841_en-us_topic_0000001059340528_b124211434362"><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_b124211434362"></a><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_b124211434362"></a>border-width</strong>, <strong id="en-us_topic_0000001058670841_en-us_topic_0000001059340528_b124894383615"><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_b124894383615"></a><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_b124894383615"></a>border-color</strong>, or <strong id="en-us_topic_0000001058670841_en-us_topic_0000001059340528_b7166134516465"><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_b7166134516465"></a><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_b7166134516465"></a>border-style</strong> for all the borders at the same time.</span></p>
</td>
</tr>
<tr id="en-us_topic_0000001058670841_row149936410561"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="en-us_topic_0000001058670841_en-us_topic_0000001059340528_a466f1f8bc2fb404e82e8417c5133eacb"><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_a466f1f8bc2fb404e82e8417c5133eacb"></a><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_a466f1f8bc2fb404e82e8417c5133eacb"></a>border-[top|bottom]-[left|right]-radius</p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p id="en-us_topic_0000001058670841_en-us_topic_0000001059340528_a499fe910d0284647abc48b1bd0eb4868"><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_a499fe910d0284647abc48b1bd0eb4868"></a><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_a499fe910d0284647abc48b1bd0eb4868"></a>&lt;length&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p id="en-us_topic_0000001058670841_en-us_topic_0000001059340528_ac142d1054eee499f948069f46129c492"><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_ac142d1054eee499f948069f46129c492"></a><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_ac142d1054eee499f948069f46129c492"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p id="en-us_topic_0000001058670841_en-us_topic_0000001059340528_p27305718283"><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_p27305718283"></a><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_p27305718283"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="en-us_topic_0000001058670841_en-us_topic_0000001059340528_a63757091a86c4ced97f0c39d37a2117c"><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_a63757091a86c4ced97f0c39d37a2117c"></a><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_a63757091a86c4ced97f0c39d37a2117c"></a>Attribute to receptively set the radii of upper-left, upper-right, lower-right, and lower-left rounded corners</p>
</td>
</tr>
<tr id="en-us_topic_0000001058670841_row099818419561"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="en-us_topic_0000001058670841_en-us_topic_0000001059340528_p134581712103910"><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_p134581712103910"></a><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_p134581712103910"></a>opacity</p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p id="en-us_topic_0000001058670841_en-us_topic_0000001059340528_a45185999ae584676af4c36467c2ade8b"><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_a45185999ae584676af4c36467c2ade8b"></a><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_a45185999ae584676af4c36467c2ade8b"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p id="en-us_topic_0000001058670841_en-us_topic_0000001059340528_a09ff20dda8e44794bca18c84f413d972"><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_a09ff20dda8e44794bca18c84f413d972"></a><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_a09ff20dda8e44794bca18c84f413d972"></a>1</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p id="en-us_topic_0000001058670841_en-us_topic_0000001059340528_p1873011722814"><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_p1873011722814"></a><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_p1873011722814"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="en-us_topic_0000001058670841_en-us_topic_0000001059340528_p122515161139"><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_p122515161139"></a><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_p122515161139"></a>Transparency of an element. The value ranges from <strong id="en-us_topic_0000001058670841_en-us_topic_0000001059340528_b1871715526385"><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_b1871715526385"></a><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_b1871715526385"></a>0</strong> to <strong id="en-us_topic_0000001058670841_en-us_topic_0000001059340528_b177181452103815"><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_b177181452103815"></a><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_b177181452103815"></a>1</strong>. The value <strong id="en-us_topic_0000001058670841_en-us_topic_0000001059340528_b13718155210380"><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_b13718155210380"></a><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_b13718155210380"></a>1</strong> means opaque, and <strong id="en-us_topic_0000001058670841_en-us_topic_0000001059340528_b6718152103818"><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_b6718152103818"></a><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_b6718152103818"></a>0</strong> means completely transparent.</p>
</td>
</tr>
<tr id="en-us_topic_0000001058670841_row89981419567"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="en-us_topic_0000001058670841_en-us_topic_0000001059340528_aeda9e2f8d8344958bf4f43d429dcb55e"><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_aeda9e2f8d8344958bf4f43d429dcb55e"></a><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_aeda9e2f8d8344958bf4f43d429dcb55e"></a>display</p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p id="en-us_topic_0000001058670841_en-us_topic_0000001059340528_p1544115441446"><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_p1544115441446"></a><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_p1544115441446"></a>string</p>
<p id="en-us_topic_0000001058670841_en-us_topic_0000001059340528_aaaa164aa970b490fb048e5f260f1c661"><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_aaaa164aa970b490fb048e5f260f1c661"></a><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_aaaa164aa970b490fb048e5f260f1c661"></a></p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p id="en-us_topic_0000001058670841_en-us_topic_0000001059340528_aa5ce61466c9847dbb7f44852338d9006"><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_aa5ce61466c9847dbb7f44852338d9006"></a><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_aa5ce61466c9847dbb7f44852338d9006"></a>flex</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p id="en-us_topic_0000001058670841_en-us_topic_0000001059340528_p167303762818"><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_p167303762818"></a><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_p167303762818"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="en-us_topic_0000001058670841_en-us_topic_0000001059340528_p23704018414"><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_p23704018414"></a><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_p23704018414"></a>How and whether to display the box containing an element. Available values are as follows:</p>
<a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_ul12227103394916"></a><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_ul12227103394916"></a><ul id="en-us_topic_0000001058670841_en-us_topic_0000001059340528_ul12227103394916"><li><strong id="en-us_topic_0000001058670841_en-us_topic_0000001059340528_b57468289377"><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_b57468289377"></a><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_b57468289377"></a>flex</strong>: flexible layout</li><li><strong id="en-us_topic_0000001058670841_en-us_topic_0000001059340528_b18887133293920"><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_b18887133293920"></a><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_b18887133293920"></a>none</strong>: The element is hidden.</li></ul>
</td>
</tr>
<tr id="en-us_topic_0000001058670841_row11999241569"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="en-us_topic_0000001058670841_en-us_topic_0000001059340528_aa2ed1da39c8e4ad78829712734226ab9"><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_aa2ed1da39c8e4ad78829712734226ab9"></a><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_aa2ed1da39c8e4ad78829712734226ab9"></a>visibility</p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p id="en-us_topic_0000001058670841_en-us_topic_0000001059340528_p15475737486"><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_p15475737486"></a><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_p15475737486"></a>string</p>
<p id="en-us_topic_0000001058670841_en-us_topic_0000001059340528_aabfb0eb044194745af56c313f40e7781"><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_aabfb0eb044194745af56c313f40e7781"></a><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_aabfb0eb044194745af56c313f40e7781"></a></p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p id="en-us_topic_0000001058670841_en-us_topic_0000001059340528_acaca80d4ef9a4f0d87adf92cb2d1ff9a"><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_acaca80d4ef9a4f0d87adf92cb2d1ff9a"></a><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_acaca80d4ef9a4f0d87adf92cb2d1ff9a"></a>visible</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p id="en-us_topic_0000001058670841_en-us_topic_0000001059340528_p57301471281"><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_p57301471281"></a><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_p57301471281"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="en-us_topic_0000001058670841_en-us_topic_0000001059340528_p1568839154517"><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_p1568839154517"></a><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_p1568839154517"></a>Whether to display an element. Invisible borders occupy layout space. (To remove the borders, set the <strong id="en-us_topic_0000001058670841_en-us_topic_0000001059340528_b15844103015378"><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_b15844103015378"></a><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_b15844103015378"></a>display</strong> attribute to <strong id="en-us_topic_0000001058670841_en-us_topic_0000001059340528_b4845153013712"><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_b4845153013712"></a><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_b4845153013712"></a>none</strong>.) Available values are as follows:</p>
<a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_ul751984164920"></a><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_ul751984164920"></a><ul id="en-us_topic_0000001058670841_en-us_topic_0000001059340528_ul751984164920"><li><strong id="en-us_topic_0000001058670841_en-us_topic_0000001059340528_b17429331133711"><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_b17429331133711"></a><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_b17429331133711"></a>visible</strong>: The element is visible.</li><li><strong id="en-us_topic_0000001058670841_en-us_topic_0000001059340528_b109191231193710"><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_b109191231193710"></a><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_b109191231193710"></a>hidden</strong>: The element is hidden but still takes up space.</li></ul>
<div class="note" id="en-us_topic_0000001058670841_en-us_topic_0000001059340528_note4549524649"><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_note4549524649"></a><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_note4549524649"></a><span class="notetitle"> NOTE: </span><div class="notebody"><p id="en-us_topic_0000001058670841_en-us_topic_0000001059340528_p25499241642"><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_p25499241642"></a><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_p25499241642"></a>If both <strong id="en-us_topic_0000001058670841_en-us_topic_0000001059340528_b719810016405"><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_b719810016405"></a><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_b719810016405"></a>visibility</strong> and <strong id="en-us_topic_0000001058670841_en-us_topic_0000001059340528_b187052264018"><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_b187052264018"></a><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_b187052264018"></a>display</strong> are set, only <strong id="en-us_topic_0000001058670841_en-us_topic_0000001059340528_b107788924011"><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_b107788924011"></a><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_b107788924011"></a>display</strong> takes effect.</p>
</div></div>
</td>
</tr>
<tr id="en-us_topic_0000001058670841_row179991441561"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="en-us_topic_0000001058670841_en-us_topic_0000001059340528_ad74a6a48aca7439e9344c18c26b4177e"><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_ad74a6a48aca7439e9344c18c26b4177e"></a><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_ad74a6a48aca7439e9344c18c26b4177e"></a>flex</p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p id="en-us_topic_0000001058670841_en-us_topic_0000001059340528_a2e6e5192a1534872be5fcfd9f83e3fdc"><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_a2e6e5192a1534872be5fcfd9f83e3fdc"></a><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_a2e6e5192a1534872be5fcfd9f83e3fdc"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p id="en-us_topic_0000001058670841_en-us_topic_0000001059340528_a8512eda38e25410685be8a8992890257"><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_a8512eda38e25410685be8a8992890257"></a><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_a8512eda38e25410685be8a8992890257"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p id="en-us_topic_0000001058670841_en-us_topic_0000001059340528_p1373057132812"><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_p1373057132812"></a><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_p1373057132812"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="en-us_topic_0000001058670841_en-us_topic_0000001059340528_a11c317cdfa7d4066878d86c6b3bcbd82"><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_a11c317cdfa7d4066878d86c6b3bcbd82"></a><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_a11c317cdfa7d4066878d86c6b3bcbd82"></a>How to divide available space of the parent component for a child component.</p>
<p id="en-us_topic_0000001058670841_en-us_topic_0000001059340528_p6968144051814"><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_p6968144051814"></a><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_p6968144051814"></a>You can set one, two<sup id="en-us_topic_0000001058670841_en-us_topic_0000001059340528_sup894453017315"><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_sup894453017315"></a><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_sup894453017315"></a>5+</sup>, or three<sup id="en-us_topic_0000001058670841_en-us_topic_0000001059340528_sup1255142393114"><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_sup1255142393114"></a><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_sup1255142393114"></a>5+</sup> values for this style.</p>
<p id="en-us_topic_0000001058670841_en-us_topic_0000001059340528_p16733313171911"><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_p16733313171911"></a><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_p16733313171911"></a>Set one value in either of the following ways:</p>
<a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_ul93371539192211"></a><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_ul93371539192211"></a><ul id="en-us_topic_0000001058670841_en-us_topic_0000001059340528_ul93371539192211"><li>A unitless number to set <strong id="en-us_topic_0000001058670841_en-us_topic_0000001059340528_b152581117781"><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_b152581117781"></a><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_b152581117781"></a>flex-grow</strong>.</li><li>A valid width value<sup id="en-us_topic_0000001058670841_en-us_topic_0000001059340528_sup133014373318"><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_sup133014373318"></a><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_sup133014373318"></a>5+</sup> to set <strong id="en-us_topic_0000001058670841_en-us_topic_0000001059340528_b182101331199"><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_b182101331199"></a><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_b182101331199"></a>flex-basis</strong>.</li></ul>
<p id="en-us_topic_0000001058670841_en-us_topic_0000001059340528_p6786171632018"><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_p6786171632018"></a><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_p6786171632018"></a>Set two values<sup id="en-us_topic_0000001058670841_en-us_topic_0000001059340528_sup39514502313"><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_sup39514502313"></a><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_sup39514502313"></a>5+</sup> in the following ways:</p>
<p id="en-us_topic_0000001058670841_en-us_topic_0000001059340528_p6400429122011"><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_p6400429122011"></a><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_p6400429122011"></a>The first value must be a unitless number used to set <strong id="en-us_topic_0000001058670841_en-us_topic_0000001059340528_b171516283129"><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_b171516283129"></a><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_b171516283129"></a>flex-grow</strong>. The second value must be either of the following:</p>
<a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_ul767043502219"></a><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_ul767043502219"></a><ul id="en-us_topic_0000001058670841_en-us_topic_0000001059340528_ul767043502219"><li>A unitless number to set <strong id="en-us_topic_0000001058670841_en-us_topic_0000001059340528_b1428375141313"><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_b1428375141313"></a><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_b1428375141313"></a>flex-shrink</strong>.</li><li>A valid width value to set <strong id="en-us_topic_0000001058670841_en-us_topic_0000001059340528_b1632495651416"><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_b1632495651416"></a><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_b1632495651416"></a>flex-basis</strong>.</li></ul>
<p id="en-us_topic_0000001058670841_en-us_topic_0000001059340528_p748416351217"><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_p748416351217"></a><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_p748416351217"></a>Set three values<sup id="en-us_topic_0000001058670841_en-us_topic_0000001059340528_sup168671312151514"><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_sup168671312151514"></a><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_sup168671312151514"></a>5+</sup> in the following ways:</p>
<p id="en-us_topic_0000001058670841_en-us_topic_0000001059340528_p7373204832111"><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_p7373204832111"></a><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_p7373204832111"></a>The first value must be a unitless number used to set <strong id="en-us_topic_0000001058670841_en-us_topic_0000001059340528_b19419131221612"><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_b19419131221612"></a><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_b19419131221612"></a>flex-grow</strong>. The second value must be a unitless number used to set <strong id="en-us_topic_0000001058670841_en-us_topic_0000001059340528_b19378733181612"><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_b19378733181612"></a><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_b19378733181612"></a>flex-shrink</strong>. The third value must be a valid width value used to set <strong id="en-us_topic_0000001058670841_en-us_topic_0000001059340528_b47717118176"><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_b47717118176"></a><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_b47717118176"></a>flex-basis</strong>.</p>
<div class="note" id="en-us_topic_0000001058670841_en-us_topic_0000001059340528_note34891253201520"><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_note34891253201520"></a><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_note34891253201520"></a><span class="notetitle"> NOTE: </span><div class="notebody"><p id="en-us_topic_0000001058670841_en-us_topic_0000001059340528_p1248915538152"><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_p1248915538152"></a><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_p1248915538152"></a>This style takes effect only when the container is any of the following components: <strong id="en-us_topic_0000001058670841_en-us_topic_0000001059340528_b17156153131"><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_b17156153131"></a><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_b17156153131"></a>&lt;div&gt;</strong>, <strong id="en-us_topic_0000001058670841_en-us_topic_0000001059340528_b1201415151311"><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_b1201415151311"></a><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_b1201415151311"></a>&lt;list-item&gt;</strong>, <strong id="en-us_topic_0000001058670841_en-us_topic_0000001059340528_b72031515132"><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_b72031515132"></a><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_b72031515132"></a>&lt;refresh&gt;</strong>, <strong id="en-us_topic_0000001058670841_en-us_topic_0000001059340528_b1920131551310"><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_b1920131551310"></a><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_b1920131551310"></a>&lt;stepper-item&gt;</strong><sup id="en-us_topic_0000001058670841_en-us_topic_0000001059340528_sup17201815121317"><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_sup17201815121317"></a><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_sup17201815121317"></a>5+</sup>, and <strong id="en-us_topic_0000001058670841_en-us_topic_0000001059340528_b2211915121313"><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_b2211915121313"></a><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_b2211915121313"></a>&lt;tabs&gt;</strong>.</p>
</div></div>
</td>
</tr>
<tr id="en-us_topic_0000001058670841_row302515612"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="en-us_topic_0000001058670841_en-us_topic_0000001059340528_a5d88cacaaf5c4f6a87390ab916b695c6"><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_a5d88cacaaf5c4f6a87390ab916b695c6"></a><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_a5d88cacaaf5c4f6a87390ab916b695c6"></a>flex-grow</p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p id="en-us_topic_0000001058670841_en-us_topic_0000001059340528_a2c379e3af283446da446f1631e572efd"><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_a2c379e3af283446da446f1631e572efd"></a><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_a2c379e3af283446da446f1631e572efd"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p id="en-us_topic_0000001058670841_en-us_topic_0000001059340528_aa374f6c7415a4ee48a06930d76c55be7"><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_aa374f6c7415a4ee48a06930d76c55be7"></a><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_aa374f6c7415a4ee48a06930d76c55be7"></a>0</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p id="en-us_topic_0000001058670841_p1102515614"><a name="en-us_topic_0000001058670841_p1102515614"></a><a name="en-us_topic_0000001058670841_p1102515614"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="en-us_topic_0000001058670841_en-us_topic_0000001059340528_p4437122419557"><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_p4437122419557"></a><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_p4437122419557"></a>How much a child component will grow. The value specifies allocation of the remaining space on the main axis of the parent component. Size of available space = Container size - Total size of all child components. Value <strong id="en-us_topic_0000001058670841_en-us_topic_0000001059340528_b1682343583716"><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_b1682343583716"></a><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_b1682343583716"></a>0</strong> indicates that the child component does not grow.</p>
<div class="note" id="en-us_topic_0000001058670841_en-us_topic_0000001059340528_note201231734212"><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_note201231734212"></a><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_note201231734212"></a><span class="notetitle"> NOTE: </span><div class="notebody"><p id="en-us_topic_0000001058670841_en-us_topic_0000001059340528_p184555314553"><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_p184555314553"></a><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_p184555314553"></a>This style takes effect only when the container is any of the following components: <strong id="en-us_topic_0000001058670841_en-us_topic_0000001059340528_b18575165615499"><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_b18575165615499"></a><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_b18575165615499"></a>&lt;div&gt;</strong>, <strong id="en-us_topic_0000001058670841_en-us_topic_0000001059340528_b8575165618495"><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_b8575165618495"></a><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_b8575165618495"></a>&lt;list-item&gt;</strong>, <strong id="en-us_topic_0000001058670841_en-us_topic_0000001059340528_b125751756164917"><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_b125751756164917"></a><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_b125751756164917"></a>&lt;refresh&gt;</strong>, <strong id="en-us_topic_0000001058670841_en-us_topic_0000001059340528_b15751456104920"><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_b15751456104920"></a><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_b15751456104920"></a>&lt;stepper-item&gt;</strong><sup id="en-us_topic_0000001058670841_en-us_topic_0000001059340528_sup257595611492"><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_sup257595611492"></a><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_sup257595611492"></a>5+</sup>, and <strong id="en-us_topic_0000001058670841_en-us_topic_0000001059340528_b55761856114912"><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_b55761856114912"></a><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_b55761856114912"></a>&lt;tabs&gt;</strong>.</p>
</div></div>
</td>
</tr>
<tr id="en-us_topic_0000001058670841_row6025155619"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="en-us_topic_0000001058670841_en-us_topic_0000001059340528_ac65ef7e2b1f24a13b09c495f643168c9"><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_ac65ef7e2b1f24a13b09c495f643168c9"></a><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_ac65ef7e2b1f24a13b09c495f643168c9"></a>flex-shrink</p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p id="en-us_topic_0000001058670841_en-us_topic_0000001059340528_a98e7d367f0e649699892ae5bad6ade37"><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_a98e7d367f0e649699892ae5bad6ade37"></a><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_a98e7d367f0e649699892ae5bad6ade37"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p id="en-us_topic_0000001058670841_en-us_topic_0000001059340528_a422d978368814d12a33201cb839060ee"><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_a422d978368814d12a33201cb839060ee"></a><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_a422d978368814d12a33201cb839060ee"></a>1</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p id="en-us_topic_0000001058670841_p191175115618"><a name="en-us_topic_0000001058670841_p191175115618"></a><a name="en-us_topic_0000001058670841_p191175115618"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="en-us_topic_0000001058670841_en-us_topic_0000001059340528_ab032342dfe56460ca742800de482ca0f"><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_ab032342dfe56460ca742800de482ca0f"></a><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_ab032342dfe56460ca742800de482ca0f"></a>How much a child component will shrink. The shrink occurs only when the sum of default child component widths is greater than that of the parent component. Value <strong id="en-us_topic_0000001058670841_en-us_topic_0000001059340528_b783242395"><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_b783242395"></a><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_b783242395"></a>0</strong> indicates that the child component does not shrink.</p>
<div class="note" id="en-us_topic_0000001058670841_en-us_topic_0000001059340528_note147160917217"><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_note147160917217"></a><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_note147160917217"></a><span class="notetitle"> NOTE: </span><div class="notebody"><p id="en-us_topic_0000001058670841_en-us_topic_0000001059340528_p844914328577"><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_p844914328577"></a><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_p844914328577"></a>This style takes effect only when the container is any of the following components: <strong id="en-us_topic_0000001058670841_en-us_topic_0000001059340528_b1168212543127"><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_b1168212543127"></a><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_b1168212543127"></a>&lt;div&gt;</strong>, <strong id="en-us_topic_0000001058670841_en-us_topic_0000001059340528_b76821454121211"><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_b76821454121211"></a><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_b76821454121211"></a>&lt;list-item&gt;</strong>, <strong id="en-us_topic_0000001058670841_en-us_topic_0000001059340528_b1168255411126"><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_b1168255411126"></a><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_b1168255411126"></a>&lt;refresh&gt;</strong>, <strong id="en-us_topic_0000001058670841_en-us_topic_0000001059340528_b10682155415120"><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_b10682155415120"></a><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_b10682155415120"></a>&lt;stepper-item&gt;</strong><sup id="en-us_topic_0000001058670841_en-us_topic_0000001059340528_sup10683145491215"><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_sup10683145491215"></a><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_sup10683145491215"></a>5+</sup>, and <strong id="en-us_topic_0000001058670841_en-us_topic_0000001059340528_b1868385461211"><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_b1868385461211"></a><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_b1868385461211"></a>&lt;tabs&gt;</strong>.</p>
</div></div>
</td>
</tr>
<tr id="en-us_topic_0000001058670841_row412511565"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="en-us_topic_0000001058670841_en-us_topic_0000001059340528_a82c323a994634032963169eeee1a55e4"><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_a82c323a994634032963169eeee1a55e4"></a><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_a82c323a994634032963169eeee1a55e4"></a>flex-basis</p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p id="en-us_topic_0000001058670841_en-us_topic_0000001059340528_p1148910787"><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_p1148910787"></a><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_p1148910787"></a>&lt;length&gt;</p>
<p id="en-us_topic_0000001058670841_en-us_topic_0000001059340528_a43613cf0c2184c0d8b44e8d292f6edb7"><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_a43613cf0c2184c0d8b44e8d292f6edb7"></a><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_a43613cf0c2184c0d8b44e8d292f6edb7"></a></p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p id="en-us_topic_0000001058670841_en-us_topic_0000001059340528_ab9e1c7dc25f840e58993af05c1d32109"><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_ab9e1c7dc25f840e58993af05c1d32109"></a><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_ab9e1c7dc25f840e58993af05c1d32109"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p id="en-us_topic_0000001058670841_p6117575611"><a name="en-us_topic_0000001058670841_p6117575611"></a><a name="en-us_topic_0000001058670841_p6117575611"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="en-us_topic_0000001058670841_en-us_topic_0000001059340528_a0993ef9b0ef64785a76e6310dd834f09"><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_a0993ef9b0ef64785a76e6310dd834f09"></a><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_a0993ef9b0ef64785a76e6310dd834f09"></a>Initial length of the flex item on the main axis.</p>
<div class="note" id="en-us_topic_0000001058670841_en-us_topic_0000001059340528_note62848141222"><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_note62848141222"></a><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_note62848141222"></a><span class="notetitle"> NOTE: </span><div class="notebody"><p id="en-us_topic_0000001058670841_en-us_topic_0000001059340528_p16711745115718"><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_p16711745115718"></a><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_p16711745115718"></a>This style takes effect only when the container is any of the following components: <strong id="en-us_topic_0000001058670841_en-us_topic_0000001059340528_b18795155631219"><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_b18795155631219"></a><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_b18795155631219"></a>&lt;div&gt;</strong>, <strong id="en-us_topic_0000001058670841_en-us_topic_0000001059340528_b107951056121217"><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_b107951056121217"></a><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_b107951056121217"></a>&lt;list-item&gt;</strong>, <strong id="en-us_topic_0000001058670841_en-us_topic_0000001059340528_b2795105619128"><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_b2795105619128"></a><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_b2795105619128"></a>&lt;refresh&gt;</strong>, <strong id="en-us_topic_0000001058670841_en-us_topic_0000001059340528_b1579510564126"><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_b1579510564126"></a><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_b1579510564126"></a>&lt;stepper-item&gt;</strong><sup id="en-us_topic_0000001058670841_en-us_topic_0000001059340528_sup187953565122"><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_sup187953565122"></a><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_sup187953565122"></a>5+</sup>, and <strong id="en-us_topic_0000001058670841_en-us_topic_0000001059340528_b11796456201211"><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_b11796456201211"></a><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_b11796456201211"></a>&lt;tabs&gt;</strong>.</p>
</div></div>
</td>
</tr>
<tr id="en-us_topic_0000001058670841_row19111545613"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="en-us_topic_0000001058670841_en-us_topic_0000001059340528_a50180d720a374549ae72c848e53320cb"><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_a50180d720a374549ae72c848e53320cb"></a><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_a50180d720a374549ae72c848e53320cb"></a>position</p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p id="en-us_topic_0000001058670841_en-us_topic_0000001059340528_a63672ed9a4c040f7a6ec9c8089b79bb6"><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_a63672ed9a4c040f7a6ec9c8089b79bb6"></a><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_a63672ed9a4c040f7a6ec9c8089b79bb6"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p id="en-us_topic_0000001058670841_en-us_topic_0000001059340528_a2666820c71eb420485e4d20e55b4eabe"><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_a2666820c71eb420485e4d20e55b4eabe"></a><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_a2666820c71eb420485e4d20e55b4eabe"></a>relative</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p id="en-us_topic_0000001058670841_en-us_topic_0000001059340528_p1173107172814"><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_p1173107172814"></a><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_p1173107172814"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="en-us_topic_0000001058670841_en-us_topic_0000001059340528_ae28abf4e47a740efbd45a8f280577912"><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_ae28abf4e47a740efbd45a8f280577912"></a><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_ae28abf4e47a740efbd45a8f280577912"></a>Positioning type of an element. Dynamic changes are not supported.</p>
<a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_ul17185232185014"></a><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_ul17185232185014"></a><ul id="en-us_topic_0000001058670841_en-us_topic_0000001059340528_ul17185232185014"><li><strong id="en-us_topic_0000001058670841_en-us_topic_0000001059340528_b1894911155394"><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_b1894911155394"></a><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_b1894911155394"></a>fixed</strong>: The element is positioned related to the browser window.</li><li><strong id="en-us_topic_0000001058670841_en-us_topic_0000001059340528_b823115152390"><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_b823115152390"></a><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_b823115152390"></a>absolute</strong>: The element is positioned absolutely to its parent element.</li><li><strong id="en-us_topic_0000001058670841_en-us_topic_0000001059340528_b736151417395"><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_b736151417395"></a><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_b736151417395"></a>relative</strong>: The element is positioned relative to its normal position.</li></ul>
<div class="note" id="en-us_topic_0000001058670841_en-us_topic_0000001059340528_note167617191219"><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_note167617191219"></a><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_note167617191219"></a><span class="notetitle"> NOTE: </span><div class="notebody"><p id="en-us_topic_0000001058670841_en-us_topic_0000001059340528_p1839092815101"><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_p1839092815101"></a><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_p1839092815101"></a>The <strong id="en-us_topic_0000001058670841_en-us_topic_0000001059340528_b13941713133910"><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_b13941713133910"></a><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_b13941713133910"></a>absolute</strong> attribute takes effect only when the parent component is <strong id="en-us_topic_0000001058670841_en-us_topic_0000001059340528_b1099913173916"><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_b1099913173916"></a><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_b1099913173916"></a>&lt;div&gt;</strong> or <strong id="en-us_topic_0000001058670841_en-us_topic_0000001059340528_b181001413123919"><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_b181001413123919"></a><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_b181001413123919"></a>&lt;stack&gt;</strong>.</p>
</div></div>
</td>
</tr>
<tr id="en-us_topic_0000001058670841_row18275205614"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="en-us_topic_0000001058670841_en-us_topic_0000001059340528_a70405cb9696b4329ac7625af93310018"><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_a70405cb9696b4329ac7625af93310018"></a><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_a70405cb9696b4329ac7625af93310018"></a>[left|top<span id="en-us_topic_0000001058670841_en-us_topic_0000001059340528_ph14927143614712"><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_ph14927143614712"></a><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_ph14927143614712"></a>|right|bottom</span>]</p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p id="en-us_topic_0000001058670841_en-us_topic_0000001059340528_p1849062221214"><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_p1849062221214"></a><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_p1849062221214"></a>&lt;length&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p id="en-us_topic_0000001058670841_en-us_topic_0000001059340528_a579ac7c03d1d46758ebaacd565d86ed3"><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_a579ac7c03d1d46758ebaacd565d86ed3"></a><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_a579ac7c03d1d46758ebaacd565d86ed3"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p id="en-us_topic_0000001058670841_en-us_topic_0000001059340528_p187314719288"><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_p187314719288"></a><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_p187314719288"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="en-us_topic_0000001058670841_en-us_topic_0000001059340528_a9a662a62cd9b40eaa0cb9ca082b6d1c2"><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_a9a662a62cd9b40eaa0cb9ca082b6d1c2"></a><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_a9a662a62cd9b40eaa0cb9ca082b6d1c2"></a><strong id="en-us_topic_0000001058670841_en-us_topic_0000001059340528_b481348173914"><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_b481348173914"></a><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_b481348173914"></a>left|top</strong><span id="en-us_topic_0000001058670841_en-us_topic_0000001059340528_ph4818118173914"><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_ph4818118173914"></a><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_ph4818118173914"></a><strong id="en-us_topic_0000001058670841_en-us_topic_0000001059340528_b68143833912"><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_b68143833912"></a><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_b68143833912"></a>|right|bottom</strong></span> must be used together with <strong id="en-us_topic_0000001058670841_en-us_topic_0000001059340528_b881916818394"><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_b881916818394"></a><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_b881916818394"></a>position</strong> to determine the offset position of an element.</p>
<a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_ul12671003525"></a><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_ul12671003525"></a><ul id="en-us_topic_0000001058670841_en-us_topic_0000001059340528_ul12671003525"><li>The <strong id="en-us_topic_0000001058670841_en-us_topic_0000001059340528_b885117712398"><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_b885117712398"></a><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_b885117712398"></a>left</strong> attribute specifies the left edge position of the element. This attribute defines the offset between the left edge of a positioned element and that of a block included in the element.</li><li>The <strong id="en-us_topic_0000001058670841_en-us_topic_0000001059340528_b65591759395"><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_b65591759395"></a><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_b65591759395"></a>top</strong> attribute specifies the top edge position of the element. This attribute defines the offset between the top edge of a positioned element and that of a block included in the element.</li><li>The <strong id="en-us_topic_0000001058670841_en-us_topic_0000001059340528_b179013323910"><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_b179013323910"></a><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_b179013323910"></a>right</strong> attribute specifies the right edge position of the element. This attribute defines the offset between the right edge of a positioned element and that of a block included in the element. </li><li>The <strong id="en-us_topic_0000001058670841_en-us_topic_0000001059340528_b77091602397"><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_b77091602397"></a><a name="en-us_topic_0000001058670841_en-us_topic_0000001059340528_b77091602397"></a>bottom</strong> attribute specifies the bottom edge position of the element. This attribute defines the offset between the bottom edge of a positioned element and that of a block included in the element. </li></ul>
</td>
</tr>
</tbody>
</table>

## Example Code<a name="en-us_topic_0000001058670841_section493033510346"></a>

```
<!--xxx.hml -->
<div class="container">
  <progress class="min-progress" type="scale-ring"  percent= "10" secondarypercent="50"></progress>
  <progress class="min-progress" type="horizontal" percent= "10" secondarypercent="50"></progress>
  <progress class="min-progress" type="arc" percent= "10"></progress>
  <progress class="min-progress" type="ring" percent= "10" secondarypercent="50"></progress>
</div>
```

```
/* xxx.css */
.container {
  flex-direction: column;
  height: 100%;
  width: 100%;
  align-items: center;
}
.min-progress {
  width: 300px;
  height: 300px;
}
```

![](figures/progress.png)

