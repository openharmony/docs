# menu<a name="EN-US_TOPIC_0000001162414625"></a>

-   [Permission List](#en-us_topic_0000001058562841_section11257113618419)
-   [Child Component](#en-us_topic_0000001058562841_section9288143101012)
-   [Attribute](#en-us_topic_0000001058562841_section2907183951110)
-   [Event](#en-us_topic_0000001058562841_section5624519222)
-   [Style](#en-us_topic_0000001058562841_section5775351116)
-   [Method](#en-us_topic_0000001058562841_section47669296127)
-   [Example Code](#en-us_topic_0000001058562841_section54636714136)

The  **<menu\>**  component provides menus as temporary pop-up windows to display operations that can be performed by users.

## Permission List<a name="en-us_topic_0000001058562841_section11257113618419"></a>

None

## Child Component<a name="en-us_topic_0000001058562841_section9288143101012"></a>

**[<option\>](option.md#EN-US_TOPIC_0000001115974742)**

## Attribute<a name="en-us_topic_0000001058562841_section2907183951110"></a>

<a name="en-us_topic_0000001058562841_table20633101642315"></a>
<table><thead align="left"><tr id="en-us_topic_0000001058562841_row663331618238"><th class="cellrowborder" valign="top" width="23.119999999999997%" id="mcps1.1.6.1.1"><p id="en-us_topic_0000001058562841_en-us_topic_0000001058340523_a9ba8c579217b4b8b841b035f1d28b20e"><a name="en-us_topic_0000001058562841_en-us_topic_0000001058340523_a9ba8c579217b4b8b841b035f1d28b20e"></a><a name="en-us_topic_0000001058562841_en-us_topic_0000001058340523_a9ba8c579217b4b8b841b035f1d28b20e"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="23.119999999999997%" id="mcps1.1.6.1.2"><p id="en-us_topic_0000001058562841_en-us_topic_0000001058340523_a633002333b024497914a4b172446f14e"><a name="en-us_topic_0000001058562841_en-us_topic_0000001058340523_a633002333b024497914a4b172446f14e"></a><a name="en-us_topic_0000001058562841_en-us_topic_0000001058340523_a633002333b024497914a4b172446f14e"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="10.48%" id="mcps1.1.6.1.3"><p id="en-us_topic_0000001058562841_en-us_topic_0000001058340523_a4950f7884c6540b9ad523ac34657d952"><a name="en-us_topic_0000001058562841_en-us_topic_0000001058340523_a4950f7884c6540b9ad523ac34657d952"></a><a name="en-us_topic_0000001058562841_en-us_topic_0000001058340523_a4950f7884c6540b9ad523ac34657d952"></a>Default Value</p>
</th>
<th class="cellrowborder" valign="top" width="7.5200000000000005%" id="mcps1.1.6.1.4"><p id="en-us_topic_0000001058562841_p824610360217"><a name="en-us_topic_0000001058562841_p824610360217"></a><a name="en-us_topic_0000001058562841_p824610360217"></a>Mandatory</p>
</th>
<th class="cellrowborder" valign="top" width="35.76%" id="mcps1.1.6.1.5"><p id="en-us_topic_0000001058562841_en-us_topic_0000001058340523_a1313564aa9404a338447087d5918c17d"><a name="en-us_topic_0000001058562841_en-us_topic_0000001058340523_a1313564aa9404a338447087d5918c17d"></a><a name="en-us_topic_0000001058562841_en-us_topic_0000001058340523_a1313564aa9404a338447087d5918c17d"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="en-us_topic_0000001058562841_row20739039202112"><td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.1 "><p id="en-us_topic_0000001058562841_p12805174016214"><a name="en-us_topic_0000001058562841_p12805174016214"></a><a name="en-us_topic_0000001058562841_p12805174016214"></a>target</p>
</td>
<td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.2 "><p id="en-us_topic_0000001058562841_p0805154015212"><a name="en-us_topic_0000001058562841_p0805154015212"></a><a name="en-us_topic_0000001058562841_p0805154015212"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="10.48%" headers="mcps1.1.6.1.3 "><p id="en-us_topic_0000001058562841_p14805134011215"><a name="en-us_topic_0000001058562841_p14805134011215"></a><a name="en-us_topic_0000001058562841_p14805134011215"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.6.1.4 "><p id="en-us_topic_0000001058562841_p17805194002114"><a name="en-us_topic_0000001058562841_p17805194002114"></a><a name="en-us_topic_0000001058562841_p17805194002114"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="35.76%" headers="mcps1.1.6.1.5 "><p id="en-us_topic_0000001058562841_p168053400214"><a name="en-us_topic_0000001058562841_p168053400214"></a><a name="en-us_topic_0000001058562841_p168053400214"></a>Target element selector. After the target element selector is used, a menu is automatically displayed when you click the target element. The pop-up menu is preferentially displayed in the lower right corner of the target element. When the visible space on the right is insufficient, the menu is moved leftward. When the visible space in the lower part is insufficient, the menu is moved upward.</p>
</td>
</tr>
<tr id="en-us_topic_0000001058562841_row1131933611219"><td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.1 "><p id="en-us_topic_0000001058562841_p380514401217"><a name="en-us_topic_0000001058562841_p380514401217"></a><a name="en-us_topic_0000001058562841_p380514401217"></a>type</p>
</td>
<td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.2 "><p id="en-us_topic_0000001058562841_p380511401214"><a name="en-us_topic_0000001058562841_p380511401214"></a><a name="en-us_topic_0000001058562841_p380511401214"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="10.48%" headers="mcps1.1.6.1.3 "><p id="en-us_topic_0000001058562841_p3805174011211"><a name="en-us_topic_0000001058562841_p3805174011211"></a><a name="en-us_topic_0000001058562841_p3805174011211"></a>click</p>
</td>
<td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.6.1.4 "><p id="en-us_topic_0000001058562841_p1805124013218"><a name="en-us_topic_0000001058562841_p1805124013218"></a><a name="en-us_topic_0000001058562841_p1805124013218"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="35.76%" headers="mcps1.1.6.1.5 "><p id="en-us_topic_0000001058562841_p11805124032118"><a name="en-us_topic_0000001058562841_p11805124032118"></a><a name="en-us_topic_0000001058562841_p11805124032118"></a>Mode in which the target element triggers the pop-up window. Available values are as follows:</p>
<a name="en-us_topic_0000001058562841_ul168051640152119"></a><a name="en-us_topic_0000001058562841_ul168051640152119"></a><ul id="en-us_topic_0000001058562841_ul168051640152119"><li><strong id="en-us_topic_0000001058562841_b363812611517"><a name="en-us_topic_0000001058562841_b363812611517"></a><a name="en-us_topic_0000001058562841_b363812611517"></a>click</strong>: Click the element to trigger the pop-up window.</li><li><strong id="en-us_topic_0000001058562841_b193081910125114"><a name="en-us_topic_0000001058562841_b193081910125114"></a><a name="en-us_topic_0000001058562841_b193081910125114"></a>longpress</strong>: Press and hold the element to trigger the pop-up window.</li></ul>
</td>
</tr>
<tr id="en-us_topic_0000001058562841_row142917338215"><td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.1 "><p id="en-us_topic_0000001058562841_p6805840192110"><a name="en-us_topic_0000001058562841_p6805840192110"></a><a name="en-us_topic_0000001058562841_p6805840192110"></a>title</p>
</td>
<td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.2 "><p id="en-us_topic_0000001058562841_p7805640162120"><a name="en-us_topic_0000001058562841_p7805640162120"></a><a name="en-us_topic_0000001058562841_p7805640162120"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="10.48%" headers="mcps1.1.6.1.3 "><p id="en-us_topic_0000001058562841_p1805104018214"><a name="en-us_topic_0000001058562841_p1805104018214"></a><a name="en-us_topic_0000001058562841_p1805104018214"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.6.1.4 "><p id="en-us_topic_0000001058562841_p158051240102116"><a name="en-us_topic_0000001058562841_p158051240102116"></a><a name="en-us_topic_0000001058562841_p158051240102116"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="35.76%" headers="mcps1.1.6.1.5 "><p id="en-us_topic_0000001058562841_p780544014218"><a name="en-us_topic_0000001058562841_p780544014218"></a><a name="en-us_topic_0000001058562841_p780544014218"></a>Title of the pop-up window.</p>
</td>
</tr>
<tr id="en-us_topic_0000001058562841_row36332165231"><td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.1 "><p id="en-us_topic_0000001058562841_en-us_topic_0000001058340523_adb8a73146d764f2aab50fc046169ab26"><a name="en-us_topic_0000001058562841_en-us_topic_0000001058340523_adb8a73146d764f2aab50fc046169ab26"></a><a name="en-us_topic_0000001058562841_en-us_topic_0000001058340523_adb8a73146d764f2aab50fc046169ab26"></a>id</p>
</td>
<td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.2 "><p id="en-us_topic_0000001058562841_en-us_topic_0000001058340523_a06898db2627246f78e85d4fbadeee85c"><a name="en-us_topic_0000001058562841_en-us_topic_0000001058340523_a06898db2627246f78e85d4fbadeee85c"></a><a name="en-us_topic_0000001058562841_en-us_topic_0000001058340523_a06898db2627246f78e85d4fbadeee85c"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="10.48%" headers="mcps1.1.6.1.3 "><p id="en-us_topic_0000001058562841_en-us_topic_0000001058340523_ae685ead324a647bcba1bbb45c9402dd6"><a name="en-us_topic_0000001058562841_en-us_topic_0000001058340523_ae685ead324a647bcba1bbb45c9402dd6"></a><a name="en-us_topic_0000001058562841_en-us_topic_0000001058340523_ae685ead324a647bcba1bbb45c9402dd6"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.6.1.4 "><p id="en-us_topic_0000001058562841_p42461736102118"><a name="en-us_topic_0000001058562841_p42461736102118"></a><a name="en-us_topic_0000001058562841_p42461736102118"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="35.76%" headers="mcps1.1.6.1.5 "><p id="en-us_topic_0000001058562841_en-us_topic_0000001058340523_a692121725a9b4ebbae65cd22b94b672e"><a name="en-us_topic_0000001058562841_en-us_topic_0000001058340523_a692121725a9b4ebbae65cd22b94b672e"></a><a name="en-us_topic_0000001058562841_en-us_topic_0000001058340523_a692121725a9b4ebbae65cd22b94b672e"></a>Unique ID of a component.</p>
</td>
</tr>
<tr id="en-us_topic_0000001058562841_row13633131616239"><td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.1 "><p id="en-us_topic_0000001058562841_en-us_topic_0000001058340523_a7c032d302e1d437eac59680e066308b0"><a name="en-us_topic_0000001058562841_en-us_topic_0000001058340523_a7c032d302e1d437eac59680e066308b0"></a><a name="en-us_topic_0000001058562841_en-us_topic_0000001058340523_a7c032d302e1d437eac59680e066308b0"></a>style</p>
</td>
<td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.2 "><p id="en-us_topic_0000001058562841_en-us_topic_0000001058340523_a6ba72f5c52df4fba9b02b5dffa26677e"><a name="en-us_topic_0000001058562841_en-us_topic_0000001058340523_a6ba72f5c52df4fba9b02b5dffa26677e"></a><a name="en-us_topic_0000001058562841_en-us_topic_0000001058340523_a6ba72f5c52df4fba9b02b5dffa26677e"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="10.48%" headers="mcps1.1.6.1.3 "><p id="en-us_topic_0000001058562841_en-us_topic_0000001058340523_a23cec1f95fd04ff1b3b20f58844ea654"><a name="en-us_topic_0000001058562841_en-us_topic_0000001058340523_a23cec1f95fd04ff1b3b20f58844ea654"></a><a name="en-us_topic_0000001058562841_en-us_topic_0000001058340523_a23cec1f95fd04ff1b3b20f58844ea654"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.6.1.4 "><p id="en-us_topic_0000001058562841_p17246836142119"><a name="en-us_topic_0000001058562841_p17246836142119"></a><a name="en-us_topic_0000001058562841_p17246836142119"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="35.76%" headers="mcps1.1.6.1.5 "><p id="en-us_topic_0000001058562841_en-us_topic_0000001058340523_ab9c92d331da44a0e9114f6760340680a"><a name="en-us_topic_0000001058562841_en-us_topic_0000001058340523_ab9c92d331da44a0e9114f6760340680a"></a><a name="en-us_topic_0000001058562841_en-us_topic_0000001058340523_ab9c92d331da44a0e9114f6760340680a"></a>Style declaration of a component.</p>
</td>
</tr>
<tr id="en-us_topic_0000001058562841_row10634131610230"><td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.1 "><p id="en-us_topic_0000001058562841_en-us_topic_0000001058340523_a3e97d6d2a5b84e06bf619049840a00a8"><a name="en-us_topic_0000001058562841_en-us_topic_0000001058340523_a3e97d6d2a5b84e06bf619049840a00a8"></a><a name="en-us_topic_0000001058562841_en-us_topic_0000001058340523_a3e97d6d2a5b84e06bf619049840a00a8"></a>class</p>
</td>
<td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.2 "><p id="en-us_topic_0000001058562841_en-us_topic_0000001058340523_af0974175e9434735b035a4db9146aa04"><a name="en-us_topic_0000001058562841_en-us_topic_0000001058340523_af0974175e9434735b035a4db9146aa04"></a><a name="en-us_topic_0000001058562841_en-us_topic_0000001058340523_af0974175e9434735b035a4db9146aa04"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="10.48%" headers="mcps1.1.6.1.3 "><p id="en-us_topic_0000001058562841_en-us_topic_0000001058340523_aa5caace6225b440eba13dc2230f3ef0f"><a name="en-us_topic_0000001058562841_en-us_topic_0000001058340523_aa5caace6225b440eba13dc2230f3ef0f"></a><a name="en-us_topic_0000001058562841_en-us_topic_0000001058340523_aa5caace6225b440eba13dc2230f3ef0f"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.6.1.4 "><p id="en-us_topic_0000001058562841_p324614367213"><a name="en-us_topic_0000001058562841_p324614367213"></a><a name="en-us_topic_0000001058562841_p324614367213"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="35.76%" headers="mcps1.1.6.1.5 "><p id="en-us_topic_0000001058562841_en-us_topic_0000001058340523_a2f6321cf45ae481983a88dcc2f900900"><a name="en-us_topic_0000001058562841_en-us_topic_0000001058340523_a2f6321cf45ae481983a88dcc2f900900"></a><a name="en-us_topic_0000001058562841_en-us_topic_0000001058340523_a2f6321cf45ae481983a88dcc2f900900"></a>Style class of a component, which is used to refer to a style table.</p>
</td>
</tr>
</tbody>
</table>

## Event<a name="en-us_topic_0000001058562841_section5624519222"></a>

<a name="en-us_topic_0000001058562841_table116210562217"></a>
<table><thead align="left"><tr id="en-us_topic_0000001058562841_row2062135192210"><th class="cellrowborder" valign="top" width="18.459999999999997%" id="mcps1.1.4.1.1"><p id="en-us_topic_0000001058562841_p166255172219"><a name="en-us_topic_0000001058562841_p166255172219"></a><a name="en-us_topic_0000001058562841_p166255172219"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="30.769999999999996%" id="mcps1.1.4.1.2"><p id="en-us_topic_0000001058562841_p76225152215"><a name="en-us_topic_0000001058562841_p76225152215"></a><a name="en-us_topic_0000001058562841_p76225152215"></a>Parameter</p>
</th>
<th class="cellrowborder" valign="top" width="50.77%" id="mcps1.1.4.1.3"><p id="en-us_topic_0000001058562841_p0621562216"><a name="en-us_topic_0000001058562841_p0621562216"></a><a name="en-us_topic_0000001058562841_p0621562216"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="en-us_topic_0000001058562841_row19622532212"><td class="cellrowborder" valign="top" width="18.459999999999997%" headers="mcps1.1.4.1.1 "><p id="en-us_topic_0000001058562841_p5629512216"><a name="en-us_topic_0000001058562841_p5629512216"></a><a name="en-us_topic_0000001058562841_p5629512216"></a>selected</p>
</td>
<td class="cellrowborder" valign="top" width="30.769999999999996%" headers="mcps1.1.4.1.2 "><p id="en-us_topic_0000001058562841_p6621258220"><a name="en-us_topic_0000001058562841_p6621258220"></a><a name="en-us_topic_0000001058562841_p6621258220"></a>{ value:value }</p>
</td>
<td class="cellrowborder" valign="top" width="50.77%" headers="mcps1.1.4.1.3 "><p id="en-us_topic_0000001058562841_p963205112214"><a name="en-us_topic_0000001058562841_p963205112214"></a><a name="en-us_topic_0000001058562841_p963205112214"></a>Triggered when a value in the menu is selected. The returned value is the <strong id="en-us_topic_0000001058562841_b8348518817"><a name="en-us_topic_0000001058562841_b8348518817"></a><a name="en-us_topic_0000001058562841_b8348518817"></a>value</strong> attribute of the <strong id="en-us_topic_0000001058562841_b46757201362"><a name="en-us_topic_0000001058562841_b46757201362"></a><a name="en-us_topic_0000001058562841_b46757201362"></a>&lt;option&gt;</strong> component.</p>
</td>
</tr>
<tr id="en-us_topic_0000001058562841_row13636516229"><td class="cellrowborder" valign="top" width="18.459999999999997%" headers="mcps1.1.4.1.1 "><p id="en-us_topic_0000001058562841_p463550229"><a name="en-us_topic_0000001058562841_p463550229"></a><a name="en-us_topic_0000001058562841_p463550229"></a>cancel</p>
</td>
<td class="cellrowborder" valign="top" width="30.769999999999996%" headers="mcps1.1.4.1.2 "><p id="en-us_topic_0000001058562841_p17633542217"><a name="en-us_topic_0000001058562841_p17633542217"></a><a name="en-us_topic_0000001058562841_p17633542217"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="50.77%" headers="mcps1.1.4.1.3 "><p id="en-us_topic_0000001058562841_p6639512225"><a name="en-us_topic_0000001058562841_p6639512225"></a><a name="en-us_topic_0000001058562841_p6639512225"></a>Triggered when an operation is canceled by the user</p>
</td>
</tr>
</tbody>
</table>

## Style<a name="en-us_topic_0000001058562841_section5775351116"></a>

<a name="en-us_topic_0000001058562841_table2161249145918"></a>
<table><thead align="left"><tr id="en-us_topic_0000001058562841_row14571349135914"><th class="cellrowborder" valign="top" width="19.038096190380962%" id="mcps1.1.6.1.1"><p id="en-us_topic_0000001058562841_p1357174955919"><a name="en-us_topic_0000001058562841_p1357174955919"></a><a name="en-us_topic_0000001058562841_p1357174955919"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="23.847615238476152%" id="mcps1.1.6.1.2"><p id="en-us_topic_0000001058562841_p10572498599"><a name="en-us_topic_0000001058562841_p10572498599"></a><a name="en-us_topic_0000001058562841_p10572498599"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="12.118788121187881%" id="mcps1.1.6.1.3"><p id="en-us_topic_0000001058562841_p0577492597"><a name="en-us_topic_0000001058562841_p0577492597"></a><a name="en-us_topic_0000001058562841_p0577492597"></a>Default Value</p>
</th>
<th class="cellrowborder" valign="top" width="8.269173082691731%" id="mcps1.1.6.1.4"><p id="en-us_topic_0000001058562841_p14571549115915"><a name="en-us_topic_0000001058562841_p14571549115915"></a><a name="en-us_topic_0000001058562841_p14571549115915"></a>Mandatory</p>
</th>
<th class="cellrowborder" valign="top" width="36.72632736726327%" id="mcps1.1.6.1.5"><p id="en-us_topic_0000001058562841_p1957144913597"><a name="en-us_topic_0000001058562841_p1957144913597"></a><a name="en-us_topic_0000001058562841_p1957144913597"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="en-us_topic_0000001058562841_row6571249185917"><td class="cellrowborder" valign="top" width="19.038096190380962%" headers="mcps1.1.6.1.1 "><p id="en-us_topic_0000001058562841_p648847164018"><a name="en-us_topic_0000001058562841_p648847164018"></a><a name="en-us_topic_0000001058562841_p648847164018"></a>text-color</p>
</td>
<td class="cellrowborder" valign="top" width="23.847615238476152%" headers="mcps1.1.6.1.2 "><p id="en-us_topic_0000001058562841_p248647114016"><a name="en-us_topic_0000001058562841_p248647114016"></a><a name="en-us_topic_0000001058562841_p248647114016"></a>&lt;color&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="12.118788121187881%" headers="mcps1.1.6.1.3 "><p id="en-us_topic_0000001058562841_p94820474409"><a name="en-us_topic_0000001058562841_p94820474409"></a><a name="en-us_topic_0000001058562841_p94820474409"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="8.269173082691731%" headers="mcps1.1.6.1.4 "><p id="en-us_topic_0000001058562841_p9481447154011"><a name="en-us_topic_0000001058562841_p9481447154011"></a><a name="en-us_topic_0000001058562841_p9481447154011"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="36.72632736726327%" headers="mcps1.1.6.1.5 "><p id="en-us_topic_0000001058562841_p348114711406"><a name="en-us_topic_0000001058562841_p348114711406"></a><a name="en-us_topic_0000001058562841_p348114711406"></a>Font color of the menu.</p>
</td>
</tr>
<tr id="en-us_topic_0000001058562841_row1758549135917"><td class="cellrowborder" valign="top" width="19.038096190380962%" headers="mcps1.1.6.1.1 "><p id="en-us_topic_0000001058562841_p1648147114015"><a name="en-us_topic_0000001058562841_p1648147114015"></a><a name="en-us_topic_0000001058562841_p1648147114015"></a>font-size</p>
</td>
<td class="cellrowborder" valign="top" width="23.847615238476152%" headers="mcps1.1.6.1.2 "><p id="en-us_topic_0000001058562841_p1048447184017"><a name="en-us_topic_0000001058562841_p1048447184017"></a><a name="en-us_topic_0000001058562841_p1048447184017"></a>&lt;length&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="12.118788121187881%" headers="mcps1.1.6.1.3 "><p id="en-us_topic_0000001058562841_p1648104720401"><a name="en-us_topic_0000001058562841_p1648104720401"></a><a name="en-us_topic_0000001058562841_p1648104720401"></a>30px</p>
</td>
<td class="cellrowborder" valign="top" width="8.269173082691731%" headers="mcps1.1.6.1.4 "><p id="en-us_topic_0000001058562841_p1048947144019"><a name="en-us_topic_0000001058562841_p1048947144019"></a><a name="en-us_topic_0000001058562841_p1048947144019"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="36.72632736726327%" headers="mcps1.1.6.1.5 "><p id="en-us_topic_0000001058562841_p7483472407"><a name="en-us_topic_0000001058562841_p7483472407"></a><a name="en-us_topic_0000001058562841_p7483472407"></a>Font size of the menu.</p>
</td>
</tr>
<tr id="en-us_topic_0000001058562841_row132490289519"><td class="cellrowborder" valign="top" width="19.038096190380962%" headers="mcps1.1.6.1.1 "><p id="en-us_topic_0000001058562841_p523512225579"><a name="en-us_topic_0000001058562841_p523512225579"></a><a name="en-us_topic_0000001058562841_p523512225579"></a>allow-scale</p>
</td>
<td class="cellrowborder" valign="top" width="23.847615238476152%" headers="mcps1.1.6.1.2 "><p id="en-us_topic_0000001058562841_p923522212570"><a name="en-us_topic_0000001058562841_p923522212570"></a><a name="en-us_topic_0000001058562841_p923522212570"></a>boolean</p>
</td>
<td class="cellrowborder" valign="top" width="12.118788121187881%" headers="mcps1.1.6.1.3 "><p id="en-us_topic_0000001058562841_p11235322145714"><a name="en-us_topic_0000001058562841_p11235322145714"></a><a name="en-us_topic_0000001058562841_p11235322145714"></a>true</p>
</td>
<td class="cellrowborder" valign="top" width="8.269173082691731%" headers="mcps1.1.6.1.4 "><p id="en-us_topic_0000001058562841_p12235112285712"><a name="en-us_topic_0000001058562841_p12235112285712"></a><a name="en-us_topic_0000001058562841_p12235112285712"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="36.72632736726327%" headers="mcps1.1.6.1.5 "><p id="en-us_topic_0000001058562841_p1023513229570"><a name="en-us_topic_0000001058562841_p1023513229570"></a><a name="en-us_topic_0000001058562841_p1023513229570"></a>Whether the font size changes with the system's font size settings.</p>
<div class="note" id="en-us_topic_0000001058562841_note654942113818"><a name="en-us_topic_0000001058562841_note654942113818"></a><a name="en-us_topic_0000001058562841_note654942113818"></a><span class="notetitle"> NOTE: </span><div class="notebody"><p id="en-us_topic_0000001058562841_p65496211811"><a name="en-us_topic_0000001058562841_p65496211811"></a><a name="en-us_topic_0000001058562841_p65496211811"></a>If the <strong id="en-us_topic_0000001058562841_b1536242895218"><a name="en-us_topic_0000001058562841_b1536242895218"></a><a name="en-us_topic_0000001058562841_b1536242895218"></a>config-changes</strong> tag of <strong id="en-us_topic_0000001058562841_b6367152819525"><a name="en-us_topic_0000001058562841_b6367152819525"></a><a name="en-us_topic_0000001058562841_b6367152819525"></a>fontSize</strong> is configured for abilities in the <strong id="en-us_topic_0000001058562841_b2367228115217"><a name="en-us_topic_0000001058562841_b2367228115217"></a><a name="en-us_topic_0000001058562841_b2367228115217"></a>config.json</strong> file, the setting takes effect without application restart.</p>
</div></div>
</td>
</tr>
<tr id="en-us_topic_0000001058562841_row145381758113919"><td class="cellrowborder" valign="top" width="19.038096190380962%" headers="mcps1.1.6.1.1 "><p id="en-us_topic_0000001058562841_p194815477404"><a name="en-us_topic_0000001058562841_p194815477404"></a><a name="en-us_topic_0000001058562841_p194815477404"></a>letter-spacing</p>
</td>
<td class="cellrowborder" valign="top" width="23.847615238476152%" headers="mcps1.1.6.1.2 "><p id="en-us_topic_0000001058562841_p37495218161"><a name="en-us_topic_0000001058562841_p37495218161"></a><a name="en-us_topic_0000001058562841_p37495218161"></a>&lt;length&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="12.118788121187881%" headers="mcps1.1.6.1.3 "><p id="en-us_topic_0000001058562841_p14914764019"><a name="en-us_topic_0000001058562841_p14914764019"></a><a name="en-us_topic_0000001058562841_p14914764019"></a>0</p>
</td>
<td class="cellrowborder" valign="top" width="8.269173082691731%" headers="mcps1.1.6.1.4 "><p id="en-us_topic_0000001058562841_p1449164754014"><a name="en-us_topic_0000001058562841_p1449164754014"></a><a name="en-us_topic_0000001058562841_p1449164754014"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="36.72632736726327%" headers="mcps1.1.6.1.5 "><p id="en-us_topic_0000001058562841_p3491247144010"><a name="en-us_topic_0000001058562841_p3491247144010"></a><a name="en-us_topic_0000001058562841_p3491247144010"></a>Character spacing of the menu.</p>
</td>
</tr>
<tr id="en-us_topic_0000001058562841_row096611589394"><td class="cellrowborder" valign="top" width="19.038096190380962%" headers="mcps1.1.6.1.1 "><p id="en-us_topic_0000001058562841_p125014744010"><a name="en-us_topic_0000001058562841_p125014744010"></a><a name="en-us_topic_0000001058562841_p125014744010"></a>font-style</p>
</td>
<td class="cellrowborder" valign="top" width="23.847615238476152%" headers="mcps1.1.6.1.2 "><p id="en-us_topic_0000001058562841_p151754142516"><a name="en-us_topic_0000001058562841_p151754142516"></a><a name="en-us_topic_0000001058562841_p151754142516"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="12.118788121187881%" headers="mcps1.1.6.1.3 "><p id="en-us_topic_0000001058562841_p165064724014"><a name="en-us_topic_0000001058562841_p165064724014"></a><a name="en-us_topic_0000001058562841_p165064724014"></a>normal</p>
</td>
<td class="cellrowborder" valign="top" width="8.269173082691731%" headers="mcps1.1.6.1.4 "><p id="en-us_topic_0000001058562841_p95094794012"><a name="en-us_topic_0000001058562841_p95094794012"></a><a name="en-us_topic_0000001058562841_p95094794012"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="36.72632736726327%" headers="mcps1.1.6.1.5 "><p id="en-us_topic_0000001058562841_p12501473405"><a name="en-us_topic_0000001058562841_p12501473405"></a><a name="en-us_topic_0000001058562841_p12501473405"></a>Font style of the menu. For details, see <a href="text.md#en-us_topic_0000001058830803_section5775351116">font-style</a> of the <strong id="en-us_topic_0000001058562841_b15474121215508"><a name="en-us_topic_0000001058562841_b15474121215508"></a><a name="en-us_topic_0000001058562841_b15474121215508"></a>text</strong> component.</p>
</td>
</tr>
<tr id="en-us_topic_0000001058562841_row1418395911393"><td class="cellrowborder" valign="top" width="19.038096190380962%" headers="mcps1.1.6.1.1 "><p id="en-us_topic_0000001058562841_p155010479409"><a name="en-us_topic_0000001058562841_p155010479409"></a><a name="en-us_topic_0000001058562841_p155010479409"></a>font-weight</p>
</td>
<td class="cellrowborder" valign="top" width="23.847615238476152%" headers="mcps1.1.6.1.2 "><p id="en-us_topic_0000001058562841_p18501047114020"><a name="en-us_topic_0000001058562841_p18501047114020"></a><a name="en-us_topic_0000001058562841_p18501047114020"></a>number | string</p>
</td>
<td class="cellrowborder" valign="top" width="12.118788121187881%" headers="mcps1.1.6.1.3 "><p id="en-us_topic_0000001058562841_p150647124016"><a name="en-us_topic_0000001058562841_p150647124016"></a><a name="en-us_topic_0000001058562841_p150647124016"></a>normal</p>
</td>
<td class="cellrowborder" valign="top" width="8.269173082691731%" headers="mcps1.1.6.1.4 "><p id="en-us_topic_0000001058562841_p450204744010"><a name="en-us_topic_0000001058562841_p450204744010"></a><a name="en-us_topic_0000001058562841_p450204744010"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="36.72632736726327%" headers="mcps1.1.6.1.5 "><p id="en-us_topic_0000001058562841_p7501247174015"><a name="en-us_topic_0000001058562841_p7501247174015"></a><a name="en-us_topic_0000001058562841_p7501247174015"></a>Font weight of the menu. For details, see <a href="text.md#en-us_topic_0000001058830803_section5775351116">font-weight</a> of the <strong id="en-us_topic_0000001058562841_b254187164920"><a name="en-us_topic_0000001058562841_b254187164920"></a><a name="en-us_topic_0000001058562841_b254187164920"></a>text</strong> component.</p>
</td>
</tr>
<tr id="en-us_topic_0000001058562841_row15576105923914"><td class="cellrowborder" valign="top" width="19.038096190380962%" headers="mcps1.1.6.1.1 "><p id="en-us_topic_0000001058562841_p14758185516400"><a name="en-us_topic_0000001058562841_p14758185516400"></a><a name="en-us_topic_0000001058562841_p14758185516400"></a>font-family</p>
</td>
<td class="cellrowborder" valign="top" width="23.847615238476152%" headers="mcps1.1.6.1.2 "><p id="en-us_topic_0000001058562841_p207583555404"><a name="en-us_topic_0000001058562841_p207583555404"></a><a name="en-us_topic_0000001058562841_p207583555404"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="12.118788121187881%" headers="mcps1.1.6.1.3 "><p id="en-us_topic_0000001058562841_p177581955144014"><a name="en-us_topic_0000001058562841_p177581955144014"></a><a name="en-us_topic_0000001058562841_p177581955144014"></a>sans-serif</p>
</td>
<td class="cellrowborder" valign="top" width="8.269173082691731%" headers="mcps1.1.6.1.4 "><p id="en-us_topic_0000001058562841_p275845519402"><a name="en-us_topic_0000001058562841_p275845519402"></a><a name="en-us_topic_0000001058562841_p275845519402"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="36.72632736726327%" headers="mcps1.1.6.1.5 "><p id="en-us_topic_0000001058562841_p11758155515409"><a name="en-us_topic_0000001058562841_p11758155515409"></a><a name="en-us_topic_0000001058562841_p11758155515409"></a>Font family, in which fonts are separated by commas (,). Each font is set using a font name or font family name. The first font that exists in the system or the font specified by <a href="custom-font-styles.md#EN-US_TOPIC_0000001162414611">Custom Font Styles</a> in the family is selected as the font for the text.</p>
</td>
</tr>
</tbody>
</table>

## Method<a name="en-us_topic_0000001058562841_section47669296127"></a>

The following methods are supported.

<a name="en-us_topic_0000001058562841_table5423142414911"></a>
<table><thead align="left"><tr id="en-us_topic_0000001058562841_row342362484919"><th class="cellrowborder" valign="top" width="18.459999999999997%" id="mcps1.1.4.1.1"><p id="en-us_topic_0000001058562841_p2423924114916"><a name="en-us_topic_0000001058562841_p2423924114916"></a><a name="en-us_topic_0000001058562841_p2423924114916"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="30.769999999999996%" id="mcps1.1.4.1.2"><p id="en-us_topic_0000001058562841_p124231524104914"><a name="en-us_topic_0000001058562841_p124231524104914"></a><a name="en-us_topic_0000001058562841_p124231524104914"></a>Parameter</p>
</th>
<th class="cellrowborder" valign="top" width="50.77%" id="mcps1.1.4.1.3"><p id="en-us_topic_0000001058562841_p104230246498"><a name="en-us_topic_0000001058562841_p104230246498"></a><a name="en-us_topic_0000001058562841_p104230246498"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="en-us_topic_0000001058562841_row1642392418498"><td class="cellrowborder" valign="top" width="18.459999999999997%" headers="mcps1.1.4.1.1 "><p id="en-us_topic_0000001058562841_p165281286428"><a name="en-us_topic_0000001058562841_p165281286428"></a><a name="en-us_topic_0000001058562841_p165281286428"></a>show</p>
</td>
<td class="cellrowborder" valign="top" width="30.769999999999996%" headers="mcps1.1.4.1.2 "><p id="en-us_topic_0000001058562841_p9528428204212"><a name="en-us_topic_0000001058562841_p9528428204212"></a><a name="en-us_topic_0000001058562841_p9528428204212"></a>{ x:x,  y:y }</p>
</td>
<td class="cellrowborder" valign="top" width="50.77%" headers="mcps1.1.4.1.3 "><p id="en-us_topic_0000001058562841_p11528112816422"><a name="en-us_topic_0000001058562841_p11528112816422"></a><a name="en-us_topic_0000001058562841_p11528112816422"></a>Displays the menu. <em id="en-us_topic_0000001058562841_i41846563220"><a name="en-us_topic_0000001058562841_i41846563220"></a><a name="en-us_topic_0000001058562841_i41846563220"></a>x</em> and <em id="en-us_topic_0000001058562841_i9806858529"><a name="en-us_topic_0000001058562841_i9806858529"></a><a name="en-us_topic_0000001058562841_i9806858529"></a>y</em> specify the position of the displayed menu. <em id="en-us_topic_0000001058562841_i1683071319418"><a name="en-us_topic_0000001058562841_i1683071319418"></a><a name="en-us_topic_0000001058562841_i1683071319418"></a>x</em> indicates the X-axis coordinate from the left edge of the visible area, and does not include any scrolling offset. <em id="en-us_topic_0000001058562841_i1864241546"><a name="en-us_topic_0000001058562841_i1864241546"></a><a name="en-us_topic_0000001058562841_i1864241546"></a>y</em> indicates the Y-axis coordinate from the upper edge of the visible area, and does not include any scrolling offset or a status bar. The menu is preferentially displayed in the lower right corner. When the visible space on the right is insufficient, the menu is moved leftward. When the visible space in the lower part is insufficient, the menu is moved upward.</p>
</td>
</tr>
</tbody>
</table>

## Example Code<a name="en-us_topic_0000001058562841_section54636714136"></a>

```
<!-- xxx.hml -->
<div class="container">
  <text onclick="onTextClick" class="title-text">Show popup menu.</text>
  <menu id="apiMenu" onselected="onMenuSelected">
    <option value="Item 1">Item 1</option>
    <option value="Item 2">Item 2</option>
    <option value="Item 3">Item 3</option>
  </menu>
</div>
```

```
/* xxx.css */
.container {
  flex-direction: column;
  align-items: flex-start;
  justify-content: center;
}
.title-text {
  margin: 20px;
}
```

```
// xxx.js
import prompt from '@system.prompt';
export default {
  onMenuSelected(e) {
    prompt.showToast({
      message: e.value
    })
  },
  onTextClick() {
    this.$element("apiMenu").show({x:280,y:120});
  }
}
```

![](figures/menu13.gif)

