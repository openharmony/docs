# image-animator<a name="EN-US_TOPIC_0000001162414623"></a>

-   [Child Component](#en-us_topic_0000001058830740_section393521619565)
-   [Attribute](#en-us_topic_0000001058830740_section1342212415618)
-   [Event](#en-us_topic_0000001058830740_section17969351566)
-   [Style](#en-us_topic_0000001058830740_section567195511491)
-   [Method](#en-us_topic_0000001058830740_section1428810433566)
-   [Example](#en-us_topic_0000001058830740_section118221913375)

The  **<image-animator\>**  component is used to provide an image frame animator.

## Child Component<a name="en-us_topic_0000001058830740_section393521619565"></a>

Not supported

## Attribute<a name="en-us_topic_0000001058830740_section1342212415618"></a>

<a name="en-us_topic_0000001058830740_table20633101642315"></a>
<table><thead align="left"><tr id="en-us_topic_0000001058830740_row663331618238"><th class="cellrowborder" valign="top" width="23.119999999999997%" id="mcps1.1.6.1.1"><p id="en-us_topic_0000001058830740_en-us_topic_0000001058340523_a9ba8c579217b4b8b841b035f1d28b20e"><a name="en-us_topic_0000001058830740_en-us_topic_0000001058340523_a9ba8c579217b4b8b841b035f1d28b20e"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001058340523_a9ba8c579217b4b8b841b035f1d28b20e"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="23.119999999999997%" id="mcps1.1.6.1.2"><p id="en-us_topic_0000001058830740_en-us_topic_0000001058340523_a633002333b024497914a4b172446f14e"><a name="en-us_topic_0000001058830740_en-us_topic_0000001058340523_a633002333b024497914a4b172446f14e"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001058340523_a633002333b024497914a4b172446f14e"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="10.48%" id="mcps1.1.6.1.3"><p id="en-us_topic_0000001058830740_en-us_topic_0000001058340523_a4950f7884c6540b9ad523ac34657d952"><a name="en-us_topic_0000001058830740_en-us_topic_0000001058340523_a4950f7884c6540b9ad523ac34657d952"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001058340523_a4950f7884c6540b9ad523ac34657d952"></a>Default Value</p>
</th>
<th class="cellrowborder" valign="top" width="7.5200000000000005%" id="mcps1.1.6.1.4"><p id="en-us_topic_0000001058830740_p824610360217"><a name="en-us_topic_0000001058830740_p824610360217"></a><a name="en-us_topic_0000001058830740_p824610360217"></a>Mandatory</p>
</th>
<th class="cellrowborder" valign="top" width="35.76%" id="mcps1.1.6.1.5"><p id="en-us_topic_0000001058830740_en-us_topic_0000001058340523_a1313564aa9404a338447087d5918c17d"><a name="en-us_topic_0000001058830740_en-us_topic_0000001058340523_a1313564aa9404a338447087d5918c17d"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001058340523_a1313564aa9404a338447087d5918c17d"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="en-us_topic_0000001058830740_row6678114174919"><td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.1 "><p id="en-us_topic_0000001058830740_p425710265496"><a name="en-us_topic_0000001058830740_p425710265496"></a><a name="en-us_topic_0000001058830740_p425710265496"></a>images</p>
</td>
<td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.2 "><p id="en-us_topic_0000001058830740_p1257142694916"><a name="en-us_topic_0000001058830740_p1257142694916"></a><a name="en-us_topic_0000001058830740_p1257142694916"></a>Array&lt;ImageFrame&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="10.48%" headers="mcps1.1.6.1.3 "><p id="en-us_topic_0000001058830740_p1725752654912"><a name="en-us_topic_0000001058830740_p1725752654912"></a><a name="en-us_topic_0000001058830740_p1725752654912"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.6.1.4 "><p id="en-us_topic_0000001058830740_p1025752610497"><a name="en-us_topic_0000001058830740_p1025752610497"></a><a name="en-us_topic_0000001058830740_p1025752610497"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="35.76%" headers="mcps1.1.6.1.5 "><p id="en-us_topic_0000001058830740_p1225732612491"><a name="en-us_topic_0000001058830740_p1225732612491"></a><a name="en-us_topic_0000001058830740_p1225732612491"></a>Image frame information. The frame information includes the image path, size, and location. Currently, the following image formats are supported: PNG and JPG. For details about <strong id="en-us_topic_0000001058830740_b1451343442511"><a name="en-us_topic_0000001058830740_b1451343442511"></a><a name="en-us_topic_0000001058830740_b1451343442511"></a>ImageFrame</strong>, see <a href="#en-us_topic_0000001058830740_table67453165913">Table 1</a>.</p>
<div class="note" id="en-us_topic_0000001058830740_note1925732612497"><a name="en-us_topic_0000001058830740_note1925732612497"></a><a name="en-us_topic_0000001058830740_note1925732612497"></a><span class="notetitle"> NOTE: </span><div class="notebody"><p id="en-us_topic_0000001058830740_p3257226184915"><a name="en-us_topic_0000001058830740_p3257226184915"></a><a name="en-us_topic_0000001058830740_p3257226184915"></a>Set this attribute using data binding, for example, <strong id="en-us_topic_0000001058830740_b3644923191911"><a name="en-us_topic_0000001058830740_b3644923191911"></a><a name="en-us_topic_0000001058830740_b3644923191911"></a>images = {{images}}</strong>. Declare the corresponding variable <strong id="en-us_topic_0000001058830740_b3583125942516"><a name="en-us_topic_0000001058830740_b3583125942516"></a><a name="en-us_topic_0000001058830740_b3583125942516"></a>images: [{src: "/common/heart-rate01.png"}, {src: "/common/heart-rate02.png"}]</strong> in the JavaScript.</p>
</div></div>
</td>
</tr>
<tr id="en-us_topic_0000001058830740_row739819164910"><td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.1 "><p id="en-us_topic_0000001058830740_p16257626134912"><a name="en-us_topic_0000001058830740_p16257626134912"></a><a name="en-us_topic_0000001058830740_p16257626134912"></a>iteration</p>
</td>
<td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.2 "><p id="en-us_topic_0000001058830740_p18257112611492"><a name="en-us_topic_0000001058830740_p18257112611492"></a><a name="en-us_topic_0000001058830740_p18257112611492"></a>number | string</p>
</td>
<td class="cellrowborder" valign="top" width="10.48%" headers="mcps1.1.6.1.3 "><p id="en-us_topic_0000001058830740_p22571126184915"><a name="en-us_topic_0000001058830740_p22571126184915"></a><a name="en-us_topic_0000001058830740_p22571126184915"></a>infinite</p>
</td>
<td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.6.1.4 "><p id="en-us_topic_0000001058830740_p14257202694917"><a name="en-us_topic_0000001058830740_p14257202694917"></a><a name="en-us_topic_0000001058830740_p14257202694917"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="35.76%" headers="mcps1.1.6.1.5 "><p id="en-us_topic_0000001058830740_p22571326114916"><a name="en-us_topic_0000001058830740_p22571326114916"></a><a name="en-us_topic_0000001058830740_p22571326114916"></a>Number of times that the frame animation is played. <strong id="en-us_topic_0000001058830740_b20158158192210"><a name="en-us_topic_0000001058830740_b20158158192210"></a><a name="en-us_topic_0000001058830740_b20158158192210"></a>number</strong> indicates a fixed number of playback operations, and <strong id="en-us_topic_0000001058830740_b1272110157230"><a name="en-us_topic_0000001058830740_b1272110157230"></a><a name="en-us_topic_0000001058830740_b1272110157230"></a>infinite</strong> indicates an unlimited number of playback operations.</p>
</td>
</tr>
<tr id="en-us_topic_0000001058830740_row163991791492"><td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.1 "><p id="en-us_topic_0000001058830740_p12576265493"><a name="en-us_topic_0000001058830740_p12576265493"></a><a name="en-us_topic_0000001058830740_p12576265493"></a>reverse</p>
</td>
<td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.2 "><p id="en-us_topic_0000001058830740_p15257826194918"><a name="en-us_topic_0000001058830740_p15257826194918"></a><a name="en-us_topic_0000001058830740_p15257826194918"></a>boolean</p>
</td>
<td class="cellrowborder" valign="top" width="10.48%" headers="mcps1.1.6.1.3 "><p id="en-us_topic_0000001058830740_p122573263499"><a name="en-us_topic_0000001058830740_p122573263499"></a><a name="en-us_topic_0000001058830740_p122573263499"></a>false</p>
</td>
<td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.6.1.4 "><p id="en-us_topic_0000001058830740_p12571626134910"><a name="en-us_topic_0000001058830740_p12571626134910"></a><a name="en-us_topic_0000001058830740_p12571626134910"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="35.76%" headers="mcps1.1.6.1.5 "><p id="en-us_topic_0000001058830740_p925816262499"><a name="en-us_topic_0000001058830740_p925816262499"></a><a name="en-us_topic_0000001058830740_p925816262499"></a>Playback sequence. The value <strong id="en-us_topic_0000001058830740_b67459152416"><a name="en-us_topic_0000001058830740_b67459152416"></a><a name="en-us_topic_0000001058830740_b67459152416"></a>false</strong> indicates that images are played from the first one to the last one, and <strong id="en-us_topic_0000001058830740_b175171216307"><a name="en-us_topic_0000001058830740_b175171216307"></a><a name="en-us_topic_0000001058830740_b175171216307"></a>true</strong> indicates that images are played from the last one to the first one.</p>
</td>
</tr>
<tr id="en-us_topic_0000001058830740_row320318310493"><td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.1 "><p id="en-us_topic_0000001058830740_p425862611491"><a name="en-us_topic_0000001058830740_p425862611491"></a><a name="en-us_topic_0000001058830740_p425862611491"></a>fixedsize</p>
</td>
<td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.2 "><p id="en-us_topic_0000001058830740_p3258182604914"><a name="en-us_topic_0000001058830740_p3258182604914"></a><a name="en-us_topic_0000001058830740_p3258182604914"></a>boolean</p>
</td>
<td class="cellrowborder" valign="top" width="10.48%" headers="mcps1.1.6.1.3 "><p id="en-us_topic_0000001058830740_p1425852684910"><a name="en-us_topic_0000001058830740_p1425852684910"></a><a name="en-us_topic_0000001058830740_p1425852684910"></a>true</p>
</td>
<td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.6.1.4 "><p id="en-us_topic_0000001058830740_p625862612497"><a name="en-us_topic_0000001058830740_p625862612497"></a><a name="en-us_topic_0000001058830740_p625862612497"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="35.76%" headers="mcps1.1.6.1.5 "><p id="en-us_topic_0000001058830740_p7258626174910"><a name="en-us_topic_0000001058830740_p7258626174910"></a><a name="en-us_topic_0000001058830740_p7258626174910"></a>Whether the image size is fixed to the widget size. <strong id="en-us_topic_0000001058830740_b919917296321"><a name="en-us_topic_0000001058830740_b919917296321"></a><a name="en-us_topic_0000001058830740_b919917296321"></a>true</strong>: The image size is the same as the widget size. In this case, the width, height, top, and left attributes of the image are invalid. <strong id="en-us_topic_0000001058830740_b89251240113218"><a name="en-us_topic_0000001058830740_b89251240113218"></a><a name="en-us_topic_0000001058830740_b89251240113218"></a>false</strong>: The width, height, top, and left attributes of each image must be set separately.</p>
</td>
</tr>
<tr id="en-us_topic_0000001058830740_row168157599487"><td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.1 "><p id="en-us_topic_0000001058830740_p15258152613494"><a name="en-us_topic_0000001058830740_p15258152613494"></a><a name="en-us_topic_0000001058830740_p15258152613494"></a>duration</p>
</td>
<td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.2 "><p id="en-us_topic_0000001058830740_p8258102610496"><a name="en-us_topic_0000001058830740_p8258102610496"></a><a name="en-us_topic_0000001058830740_p8258102610496"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="10.48%" headers="mcps1.1.6.1.3 "><p id="en-us_topic_0000001058830740_p9258112654910"><a name="en-us_topic_0000001058830740_p9258112654910"></a><a name="en-us_topic_0000001058830740_p9258112654910"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.6.1.4 "><p id="en-us_topic_0000001058830740_p1225814262495"><a name="en-us_topic_0000001058830740_p1225814262495"></a><a name="en-us_topic_0000001058830740_p1225814262495"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="35.76%" headers="mcps1.1.6.1.5 "><p id="en-us_topic_0000001058830740_p9258102684910"><a name="en-us_topic_0000001058830740_p9258102684910"></a><a name="en-us_topic_0000001058830740_p9258102684910"></a>Single video playback duration. The unit can be s (standing for seconds) or ms. The default unit is ms. If the value is <strong id="en-us_topic_0000001058830740_b165541819123316"><a name="en-us_topic_0000001058830740_b165541819123316"></a><a name="en-us_topic_0000001058830740_b165541819123316"></a>0</strong>, no image is played. The value change takes effect only at the start of the next cycle.</p>
</td>
</tr>
<tr id="en-us_topic_0000001058830740_row15460155375910"><td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.1 "><p id="en-us_topic_0000001058830740_p204611353105915"><a name="en-us_topic_0000001058830740_p204611353105915"></a><a name="en-us_topic_0000001058830740_p204611353105915"></a>fillmode<sup id="en-us_topic_0000001058830740_sup4224194014312"><a name="en-us_topic_0000001058830740_sup4224194014312"></a><a name="en-us_topic_0000001058830740_sup4224194014312"></a>5+</sup></p>
</td>
<td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.2 "><p id="en-us_topic_0000001058830740_p1461125318597"><a name="en-us_topic_0000001058830740_p1461125318597"></a><a name="en-us_topic_0000001058830740_p1461125318597"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="10.48%" headers="mcps1.1.6.1.3 "><p id="en-us_topic_0000001058830740_p11461155311592"><a name="en-us_topic_0000001058830740_p11461155311592"></a><a name="en-us_topic_0000001058830740_p11461155311592"></a>forwards</p>
</td>
<td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.6.1.4 "><p id="en-us_topic_0000001058830740_p3461135316592"><a name="en-us_topic_0000001058830740_p3461135316592"></a><a name="en-us_topic_0000001058830740_p3461135316592"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="35.76%" headers="mcps1.1.6.1.5 "><p id="en-us_topic_0000001058830740_p48661353174"><a name="en-us_topic_0000001058830740_p48661353174"></a><a name="en-us_topic_0000001058830740_p48661353174"></a>Status of the frame animation after its playback is complete. Available values are as follows:</p>
<a name="en-us_topic_0000001058830740_ul183656592213"></a><a name="en-us_topic_0000001058830740_ul183656592213"></a><ul id="en-us_topic_0000001058830740_ul183656592213"><li><strong id="en-us_topic_0000001058830740_b4108122744120"><a name="en-us_topic_0000001058830740_b4108122744120"></a><a name="en-us_topic_0000001058830740_b4108122744120"></a>none</strong>: Restores to the initial status.</li><li><strong id="en-us_topic_0000001058830740_b8540732144117"><a name="en-us_topic_0000001058830740_b8540732144117"></a><a name="en-us_topic_0000001058830740_b8540732144117"></a>forwards</strong>: Retains the ending status defined for the last key frame.</li></ul>
</td>
</tr>
<tr id="en-us_topic_0000001058830740_row36332165231"><td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.1 "><p id="en-us_topic_0000001058830740_en-us_topic_0000001058340523_adb8a73146d764f2aab50fc046169ab26"><a name="en-us_topic_0000001058830740_en-us_topic_0000001058340523_adb8a73146d764f2aab50fc046169ab26"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001058340523_adb8a73146d764f2aab50fc046169ab26"></a>id</p>
</td>
<td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.2 "><p id="en-us_topic_0000001058830740_en-us_topic_0000001058340523_a06898db2627246f78e85d4fbadeee85c"><a name="en-us_topic_0000001058830740_en-us_topic_0000001058340523_a06898db2627246f78e85d4fbadeee85c"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001058340523_a06898db2627246f78e85d4fbadeee85c"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="10.48%" headers="mcps1.1.6.1.3 "><p id="en-us_topic_0000001058830740_en-us_topic_0000001058340523_ae685ead324a647bcba1bbb45c9402dd6"><a name="en-us_topic_0000001058830740_en-us_topic_0000001058340523_ae685ead324a647bcba1bbb45c9402dd6"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001058340523_ae685ead324a647bcba1bbb45c9402dd6"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.6.1.4 "><p id="en-us_topic_0000001058830740_p42461736102118"><a name="en-us_topic_0000001058830740_p42461736102118"></a><a name="en-us_topic_0000001058830740_p42461736102118"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="35.76%" headers="mcps1.1.6.1.5 "><p id="en-us_topic_0000001058830740_en-us_topic_0000001058340523_a692121725a9b4ebbae65cd22b94b672e"><a name="en-us_topic_0000001058830740_en-us_topic_0000001058340523_a692121725a9b4ebbae65cd22b94b672e"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001058340523_a692121725a9b4ebbae65cd22b94b672e"></a>Unique ID of a component.</p>
</td>
</tr>
<tr id="en-us_topic_0000001058830740_row13633131616239"><td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.1 "><p id="en-us_topic_0000001058830740_en-us_topic_0000001058340523_a7c032d302e1d437eac59680e066308b0"><a name="en-us_topic_0000001058830740_en-us_topic_0000001058340523_a7c032d302e1d437eac59680e066308b0"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001058340523_a7c032d302e1d437eac59680e066308b0"></a>style</p>
</td>
<td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.2 "><p id="en-us_topic_0000001058830740_en-us_topic_0000001058340523_a6ba72f5c52df4fba9b02b5dffa26677e"><a name="en-us_topic_0000001058830740_en-us_topic_0000001058340523_a6ba72f5c52df4fba9b02b5dffa26677e"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001058340523_a6ba72f5c52df4fba9b02b5dffa26677e"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="10.48%" headers="mcps1.1.6.1.3 "><p id="en-us_topic_0000001058830740_en-us_topic_0000001058340523_a23cec1f95fd04ff1b3b20f58844ea654"><a name="en-us_topic_0000001058830740_en-us_topic_0000001058340523_a23cec1f95fd04ff1b3b20f58844ea654"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001058340523_a23cec1f95fd04ff1b3b20f58844ea654"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.6.1.4 "><p id="en-us_topic_0000001058830740_p17246836142119"><a name="en-us_topic_0000001058830740_p17246836142119"></a><a name="en-us_topic_0000001058830740_p17246836142119"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="35.76%" headers="mcps1.1.6.1.5 "><p id="en-us_topic_0000001058830740_en-us_topic_0000001058340523_ab9c92d331da44a0e9114f6760340680a"><a name="en-us_topic_0000001058830740_en-us_topic_0000001058340523_ab9c92d331da44a0e9114f6760340680a"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001058340523_ab9c92d331da44a0e9114f6760340680a"></a>Style declaration of a component.</p>
</td>
</tr>
<tr id="en-us_topic_0000001058830740_row10634131610230"><td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.1 "><p id="en-us_topic_0000001058830740_en-us_topic_0000001058340523_a3e97d6d2a5b84e06bf619049840a00a8"><a name="en-us_topic_0000001058830740_en-us_topic_0000001058340523_a3e97d6d2a5b84e06bf619049840a00a8"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001058340523_a3e97d6d2a5b84e06bf619049840a00a8"></a>class</p>
</td>
<td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.2 "><p id="en-us_topic_0000001058830740_en-us_topic_0000001058340523_af0974175e9434735b035a4db9146aa04"><a name="en-us_topic_0000001058830740_en-us_topic_0000001058340523_af0974175e9434735b035a4db9146aa04"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001058340523_af0974175e9434735b035a4db9146aa04"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="10.48%" headers="mcps1.1.6.1.3 "><p id="en-us_topic_0000001058830740_en-us_topic_0000001058340523_aa5caace6225b440eba13dc2230f3ef0f"><a name="en-us_topic_0000001058830740_en-us_topic_0000001058340523_aa5caace6225b440eba13dc2230f3ef0f"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001058340523_aa5caace6225b440eba13dc2230f3ef0f"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.6.1.4 "><p id="en-us_topic_0000001058830740_p324614367213"><a name="en-us_topic_0000001058830740_p324614367213"></a><a name="en-us_topic_0000001058830740_p324614367213"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="35.76%" headers="mcps1.1.6.1.5 "><p id="en-us_topic_0000001058830740_en-us_topic_0000001058340523_a2f6321cf45ae481983a88dcc2f900900"><a name="en-us_topic_0000001058830740_en-us_topic_0000001058340523_a2f6321cf45ae481983a88dcc2f900900"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001058340523_a2f6321cf45ae481983a88dcc2f900900"></a>Style class of a component, which is used to refer to a style table.</p>
</td>
</tr>
<tr id="en-us_topic_0000001058830740_row1634171618236"><td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.1 "><p id="en-us_topic_0000001058830740_en-us_topic_0000001058340523_p1786251117156"><a name="en-us_topic_0000001058830740_en-us_topic_0000001058340523_p1786251117156"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001058340523_p1786251117156"></a>ref</p>
</td>
<td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.2 "><p id="en-us_topic_0000001058830740_en-us_topic_0000001058340523_p1086241119157"><a name="en-us_topic_0000001058830740_en-us_topic_0000001058340523_p1086241119157"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001058340523_p1086241119157"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="10.48%" headers="mcps1.1.6.1.3 "><p id="en-us_topic_0000001058830740_en-us_topic_0000001058340523_p586281111151"><a name="en-us_topic_0000001058830740_en-us_topic_0000001058340523_p586281111151"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001058340523_p586281111151"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.6.1.4 "><p id="en-us_topic_0000001058830740_p1624612362219"><a name="en-us_topic_0000001058830740_p1624612362219"></a><a name="en-us_topic_0000001058830740_p1624612362219"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="35.76%" headers="mcps1.1.6.1.5 "><p id="en-us_topic_0000001058830740_en-us_topic_0000001058340523_p113416153342"><a name="en-us_topic_0000001058830740_en-us_topic_0000001058340523_p113416153342"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001058340523_p113416153342"></a>Used to register reference information of child elements<span id="en-us_topic_0000001058830740_en-us_topic_0000001058340523_ph5815920163518"><a name="en-us_topic_0000001058830740_en-us_topic_0000001058340523_ph5815920163518"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001058340523_ph5815920163518"></a> or child components</span>. The reference information is registered with the parent component on <strong id="en-us_topic_0000001058830740_en-us_topic_0000001058340523_b08212202354"><a name="en-us_topic_0000001058830740_en-us_topic_0000001058340523_b08212202354"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001058340523_b08212202354"></a>$refs</strong>.</p>
</td>
</tr>
<tr id="en-us_topic_0000001058830740_row1863421642313"><td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.1 "><p id="en-us_topic_0000001058830740_en-us_topic_0000001058340523_ab8d3c8007e0a42b9962e0db009e7be9d"><a name="en-us_topic_0000001058830740_en-us_topic_0000001058340523_ab8d3c8007e0a42b9962e0db009e7be9d"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001058340523_ab8d3c8007e0a42b9962e0db009e7be9d"></a>disabled</p>
</td>
<td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.2 "><p id="en-us_topic_0000001058830740_en-us_topic_0000001058340523_a05782d6a1a5d42918bc95813dca610d6"><a name="en-us_topic_0000001058830740_en-us_topic_0000001058340523_a05782d6a1a5d42918bc95813dca610d6"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001058340523_a05782d6a1a5d42918bc95813dca610d6"></a>boolean</p>
</td>
<td class="cellrowborder" valign="top" width="10.48%" headers="mcps1.1.6.1.3 "><p id="en-us_topic_0000001058830740_en-us_topic_0000001058340523_a3e2f721f63a74e4b974e9bd5e2f88994"><a name="en-us_topic_0000001058830740_en-us_topic_0000001058340523_a3e2f721f63a74e4b974e9bd5e2f88994"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001058340523_a3e2f721f63a74e4b974e9bd5e2f88994"></a>false</p>
</td>
<td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.6.1.4 "><p id="en-us_topic_0000001058830740_p192476368214"><a name="en-us_topic_0000001058830740_p192476368214"></a><a name="en-us_topic_0000001058830740_p192476368214"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="35.76%" headers="mcps1.1.6.1.5 "><p id="en-us_topic_0000001058830740_en-us_topic_0000001058340523_a4065980a1e914cf98acce5250ee4ae5a"><a name="en-us_topic_0000001058830740_en-us_topic_0000001058340523_a4065980a1e914cf98acce5250ee4ae5a"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001058340523_a4065980a1e914cf98acce5250ee4ae5a"></a>Whether a component is disabled. If it is disabled, it cannot respond to user interaction.</p>
</td>
</tr>
<tr id="en-us_topic_0000001058830740_row1263451617236"><td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.1 "><p id="en-us_topic_0000001058830740_en-us_topic_0000001058340523_a751c9d46a62348ec902c7fdf97468b9d"><a name="en-us_topic_0000001058830740_en-us_topic_0000001058340523_a751c9d46a62348ec902c7fdf97468b9d"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001058340523_a751c9d46a62348ec902c7fdf97468b9d"></a>data</p>
</td>
<td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.2 "><p id="en-us_topic_0000001058830740_en-us_topic_0000001058340523_a8e6d1bb4d0bc423fb8466ee3acd1882f"><a name="en-us_topic_0000001058830740_en-us_topic_0000001058340523_a8e6d1bb4d0bc423fb8466ee3acd1882f"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001058340523_a8e6d1bb4d0bc423fb8466ee3acd1882f"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="10.48%" headers="mcps1.1.6.1.3 "><p id="en-us_topic_0000001058830740_en-us_topic_0000001058340523_ab8cb15c9c3444b13b64945788131dce6"><a name="en-us_topic_0000001058830740_en-us_topic_0000001058340523_ab8cb15c9c3444b13b64945788131dce6"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001058340523_ab8cb15c9c3444b13b64945788131dce6"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.6.1.4 "><p id="en-us_topic_0000001058830740_p22471736132114"><a name="en-us_topic_0000001058830740_p22471736132114"></a><a name="en-us_topic_0000001058830740_p22471736132114"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="35.76%" headers="mcps1.1.6.1.5 "><p id="en-us_topic_0000001058830740_en-us_topic_0000001058340523_aa3f56a32296b4e85bcda2d2c00d0884f"><a name="en-us_topic_0000001058830740_en-us_topic_0000001058340523_aa3f56a32296b4e85bcda2d2c00d0884f"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001058340523_aa3f56a32296b4e85bcda2d2c00d0884f"></a>Attribute set for a component to facilitate data storage and reading.</p>
</td>
</tr>
</tbody>
</table>

**Table  1**  ImageFrame description

<a name="en-us_topic_0000001058830740_table67453165913"></a>
<table><thead align="left"><tr id="en-us_topic_0000001058830740_row127451816696"><th class="cellrowborder" valign="top" width="11.330000000000002%" id="mcps1.2.6.1.1"><p id="en-us_topic_0000001058830740_p20745516799"><a name="en-us_topic_0000001058830740_p20745516799"></a><a name="en-us_topic_0000001058830740_p20745516799"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="9.860000000000001%" id="mcps1.2.6.1.2"><p id="en-us_topic_0000001058830740_p6745181616919"><a name="en-us_topic_0000001058830740_p6745181616919"></a><a name="en-us_topic_0000001058830740_p6745181616919"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="10.810000000000002%" id="mcps1.2.6.1.3"><p id="en-us_topic_0000001058830740_p27452161915"><a name="en-us_topic_0000001058830740_p27452161915"></a><a name="en-us_topic_0000001058830740_p27452161915"></a>Default Value</p>
</th>
<th class="cellrowborder" valign="top" width="10.000000000000002%" id="mcps1.2.6.1.4"><p id="en-us_topic_0000001058830740_p187461164918"><a name="en-us_topic_0000001058830740_p187461164918"></a><a name="en-us_topic_0000001058830740_p187461164918"></a>Mandatory</p>
</th>
<th class="cellrowborder" valign="top" width="58.00000000000001%" id="mcps1.2.6.1.5"><p id="en-us_topic_0000001058830740_p174651611917"><a name="en-us_topic_0000001058830740_p174651611917"></a><a name="en-us_topic_0000001058830740_p174651611917"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="en-us_topic_0000001058830740_row974611615915"><td class="cellrowborder" valign="top" width="11.330000000000002%" headers="mcps1.2.6.1.1 "><p id="en-us_topic_0000001058830740_p27461616392"><a name="en-us_topic_0000001058830740_p27461616392"></a><a name="en-us_topic_0000001058830740_p27461616392"></a>src</p>
</td>
<td class="cellrowborder" valign="top" width="9.860000000000001%" headers="mcps1.2.6.1.2 "><p id="en-us_topic_0000001058830740_p1874612161194"><a name="en-us_topic_0000001058830740_p1874612161194"></a><a name="en-us_topic_0000001058830740_p1874612161194"></a>&lt;uri&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="10.810000000000002%" headers="mcps1.2.6.1.3 "><p id="en-us_topic_0000001058830740_p167462161197"><a name="en-us_topic_0000001058830740_p167462161197"></a><a name="en-us_topic_0000001058830740_p167462161197"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="10.000000000000002%" headers="mcps1.2.6.1.4 "><p id="en-us_topic_0000001058830740_p674612161914"><a name="en-us_topic_0000001058830740_p674612161914"></a><a name="en-us_topic_0000001058830740_p674612161914"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="58.00000000000001%" headers="mcps1.2.6.1.5 "><p id="en-us_topic_0000001058830740_p87460161592"><a name="en-us_topic_0000001058830740_p87460161592"></a><a name="en-us_topic_0000001058830740_p87460161592"></a>Image path.<span id="en-us_topic_0000001058830740_ph5230045184011"><a name="en-us_topic_0000001058830740_ph5230045184011"></a><a name="en-us_topic_0000001058830740_ph5230045184011"></a> The image format can be SVG, PNG, or JPG.</span></p>
</td>
</tr>
<tr id="en-us_topic_0000001058830740_row1574611161790"><td class="cellrowborder" valign="top" width="11.330000000000002%" headers="mcps1.2.6.1.1 "><p id="en-us_topic_0000001058830740_p1674621619911"><a name="en-us_topic_0000001058830740_p1674621619911"></a><a name="en-us_topic_0000001058830740_p1674621619911"></a>width</p>
</td>
<td class="cellrowborder" valign="top" width="9.860000000000001%" headers="mcps1.2.6.1.2 "><p id="en-us_topic_0000001058830740_p4746516691"><a name="en-us_topic_0000001058830740_p4746516691"></a><a name="en-us_topic_0000001058830740_p4746516691"></a>&lt;length&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="10.810000000000002%" headers="mcps1.2.6.1.3 "><p id="en-us_topic_0000001058830740_p1874661618915"><a name="en-us_topic_0000001058830740_p1874661618915"></a><a name="en-us_topic_0000001058830740_p1874661618915"></a>0</p>
</td>
<td class="cellrowborder" valign="top" width="10.000000000000002%" headers="mcps1.2.6.1.4 "><p id="en-us_topic_0000001058830740_p13746161615914"><a name="en-us_topic_0000001058830740_p13746161615914"></a><a name="en-us_topic_0000001058830740_p13746161615914"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="58.00000000000001%" headers="mcps1.2.6.1.5 "><p id="en-us_topic_0000001058830740_p57461162915"><a name="en-us_topic_0000001058830740_p57461162915"></a><a name="en-us_topic_0000001058830740_p57461162915"></a>Image width</p>
</td>
</tr>
<tr id="en-us_topic_0000001058830740_row1746131615914"><td class="cellrowborder" valign="top" width="11.330000000000002%" headers="mcps1.2.6.1.1 "><p id="en-us_topic_0000001058830740_p137467160910"><a name="en-us_topic_0000001058830740_p137467160910"></a><a name="en-us_topic_0000001058830740_p137467160910"></a>height</p>
</td>
<td class="cellrowborder" valign="top" width="9.860000000000001%" headers="mcps1.2.6.1.2 "><p id="en-us_topic_0000001058830740_p12285145181014"><a name="en-us_topic_0000001058830740_p12285145181014"></a><a name="en-us_topic_0000001058830740_p12285145181014"></a>&lt;length&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="10.810000000000002%" headers="mcps1.2.6.1.3 "><p id="en-us_topic_0000001058830740_p3285144571012"><a name="en-us_topic_0000001058830740_p3285144571012"></a><a name="en-us_topic_0000001058830740_p3285144571012"></a>0</p>
</td>
<td class="cellrowborder" valign="top" width="10.000000000000002%" headers="mcps1.2.6.1.4 "><p id="en-us_topic_0000001058830740_p728514520106"><a name="en-us_topic_0000001058830740_p728514520106"></a><a name="en-us_topic_0000001058830740_p728514520106"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="58.00000000000001%" headers="mcps1.2.6.1.5 "><p id="en-us_topic_0000001058830740_p1174619161998"><a name="en-us_topic_0000001058830740_p1174619161998"></a><a name="en-us_topic_0000001058830740_p1174619161998"></a>Image height</p>
</td>
</tr>
<tr id="en-us_topic_0000001058830740_row157461216990"><td class="cellrowborder" valign="top" width="11.330000000000002%" headers="mcps1.2.6.1.1 "><p id="en-us_topic_0000001058830740_p157461916297"><a name="en-us_topic_0000001058830740_p157461916297"></a><a name="en-us_topic_0000001058830740_p157461916297"></a>top</p>
</td>
<td class="cellrowborder" valign="top" width="9.860000000000001%" headers="mcps1.2.6.1.2 "><p id="en-us_topic_0000001058830740_p172301247131019"><a name="en-us_topic_0000001058830740_p172301247131019"></a><a name="en-us_topic_0000001058830740_p172301247131019"></a>&lt;length&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="10.810000000000002%" headers="mcps1.2.6.1.3 "><p id="en-us_topic_0000001058830740_p152301647141015"><a name="en-us_topic_0000001058830740_p152301647141015"></a><a name="en-us_topic_0000001058830740_p152301647141015"></a>0</p>
</td>
<td class="cellrowborder" valign="top" width="10.000000000000002%" headers="mcps1.2.6.1.4 "><p id="en-us_topic_0000001058830740_p15230164731016"><a name="en-us_topic_0000001058830740_p15230164731016"></a><a name="en-us_topic_0000001058830740_p15230164731016"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="58.00000000000001%" headers="mcps1.2.6.1.5 "><p id="en-us_topic_0000001058830740_p11863511151119"><a name="en-us_topic_0000001058830740_p11863511151119"></a><a name="en-us_topic_0000001058830740_p11863511151119"></a>Vertical coordinate of the image relative to the upper left corner of the widget</p>
</td>
</tr>
<tr id="en-us_topic_0000001058830740_row107477161396"><td class="cellrowborder" valign="top" width="11.330000000000002%" headers="mcps1.2.6.1.1 "><p id="en-us_topic_0000001058830740_p57474161995"><a name="en-us_topic_0000001058830740_p57474161995"></a><a name="en-us_topic_0000001058830740_p57474161995"></a>left</p>
</td>
<td class="cellrowborder" valign="top" width="9.860000000000001%" headers="mcps1.2.6.1.2 "><p id="en-us_topic_0000001058830740_p317644961019"><a name="en-us_topic_0000001058830740_p317644961019"></a><a name="en-us_topic_0000001058830740_p317644961019"></a>&lt;length&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="10.810000000000002%" headers="mcps1.2.6.1.3 "><p id="en-us_topic_0000001058830740_p19176154951014"><a name="en-us_topic_0000001058830740_p19176154951014"></a><a name="en-us_topic_0000001058830740_p19176154951014"></a>0</p>
</td>
<td class="cellrowborder" valign="top" width="10.000000000000002%" headers="mcps1.2.6.1.4 "><p id="en-us_topic_0000001058830740_p1176049201020"><a name="en-us_topic_0000001058830740_p1176049201020"></a><a name="en-us_topic_0000001058830740_p1176049201020"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="58.00000000000001%" headers="mcps1.2.6.1.5 "><p id="en-us_topic_0000001058830740_p191151321151111"><a name="en-us_topic_0000001058830740_p191151321151111"></a><a name="en-us_topic_0000001058830740_p191151321151111"></a>Horizontal coordinate of the image relative to the upper left corner of the widget</p>
</td>
</tr>
</tbody>
</table>

## Event<a name="en-us_topic_0000001058830740_section17969351566"></a>

<a name="en-us_topic_0000001058830740_table836435619510"></a>
<table><thead align="left"><tr id="en-us_topic_0000001058830740_row153658563517"><th class="cellrowborder" valign="top" width="24.852485248524854%" id="mcps1.1.4.1.1"><p id="en-us_topic_0000001058830740_en-us_topic_0000001058460527_a487aa1c493e84ca68567b4b65051674d"><a name="en-us_topic_0000001058830740_en-us_topic_0000001058460527_a487aa1c493e84ca68567b4b65051674d"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001058460527_a487aa1c493e84ca68567b4b65051674d"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="29.552955295529554%" id="mcps1.1.4.1.2"><p id="en-us_topic_0000001058830740_en-us_topic_0000001058460527_adc4b506cda3043508da6ee7649c12ca4"><a name="en-us_topic_0000001058830740_en-us_topic_0000001058460527_adc4b506cda3043508da6ee7649c12ca4"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001058460527_adc4b506cda3043508da6ee7649c12ca4"></a>Parameter</p>
</th>
<th class="cellrowborder" valign="top" width="45.5945594559456%" id="mcps1.1.4.1.3"><p id="en-us_topic_0000001058830740_en-us_topic_0000001058460527_a59e4cbe58a5c42a7a4585bc8365783bc"><a name="en-us_topic_0000001058830740_en-us_topic_0000001058460527_a59e4cbe58a5c42a7a4585bc8365783bc"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001058460527_a59e4cbe58a5c42a7a4585bc8365783bc"></a>Triggered when</p>
</th>
</tr>
</thead>
<tbody><tr id="en-us_topic_0000001058830740_row287217513517"><td class="cellrowborder" valign="top" width="24.852485248524854%" headers="mcps1.1.4.1.1 "><p id="en-us_topic_0000001058830740_p2602207165111"><a name="en-us_topic_0000001058830740_p2602207165111"></a><a name="en-us_topic_0000001058830740_p2602207165111"></a>start</p>
</td>
<td class="cellrowborder" valign="top" width="29.552955295529554%" headers="mcps1.1.4.1.2 "><p id="en-us_topic_0000001058830740_p19602157185119"><a name="en-us_topic_0000001058830740_p19602157185119"></a><a name="en-us_topic_0000001058830740_p19602157185119"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="45.5945594559456%" headers="mcps1.1.4.1.3 "><p id="en-us_topic_0000001058830740_p146021079518"><a name="en-us_topic_0000001058830740_p146021079518"></a><a name="en-us_topic_0000001058830740_p146021079518"></a>Triggered when the frame animation starts</p>
</td>
</tr>
<tr id="en-us_topic_0000001058830740_row0878102155118"><td class="cellrowborder" valign="top" width="24.852485248524854%" headers="mcps1.1.4.1.1 "><p id="en-us_topic_0000001058830740_p1760237135118"><a name="en-us_topic_0000001058830740_p1760237135118"></a><a name="en-us_topic_0000001058830740_p1760237135118"></a>pause</p>
</td>
<td class="cellrowborder" valign="top" width="29.552955295529554%" headers="mcps1.1.4.1.2 "><p id="en-us_topic_0000001058830740_p160214745113"><a name="en-us_topic_0000001058830740_p160214745113"></a><a name="en-us_topic_0000001058830740_p160214745113"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="45.5945594559456%" headers="mcps1.1.4.1.3 "><p id="en-us_topic_0000001058830740_p26027715112"><a name="en-us_topic_0000001058830740_p26027715112"></a><a name="en-us_topic_0000001058830740_p26027715112"></a>Triggered when the frame animation pauses</p>
</td>
</tr>
<tr id="en-us_topic_0000001058830740_row151519594509"><td class="cellrowborder" valign="top" width="24.852485248524854%" headers="mcps1.1.4.1.1 "><p id="en-us_topic_0000001058830740_p86027735118"><a name="en-us_topic_0000001058830740_p86027735118"></a><a name="en-us_topic_0000001058830740_p86027735118"></a>stop</p>
</td>
<td class="cellrowborder" valign="top" width="29.552955295529554%" headers="mcps1.1.4.1.2 "><p id="en-us_topic_0000001058830740_p196024715513"><a name="en-us_topic_0000001058830740_p196024715513"></a><a name="en-us_topic_0000001058830740_p196024715513"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="45.5945594559456%" headers="mcps1.1.4.1.3 "><p id="en-us_topic_0000001058830740_p760216735110"><a name="en-us_topic_0000001058830740_p760216735110"></a><a name="en-us_topic_0000001058830740_p760216735110"></a>Triggered when the frame animation stops</p>
</td>
</tr>
<tr id="en-us_topic_0000001058830740_row189025517507"><td class="cellrowborder" valign="top" width="24.852485248524854%" headers="mcps1.1.4.1.1 "><p id="en-us_topic_0000001058830740_p4602147175120"><a name="en-us_topic_0000001058830740_p4602147175120"></a><a name="en-us_topic_0000001058830740_p4602147175120"></a>resume </p>
</td>
<td class="cellrowborder" valign="top" width="29.552955295529554%" headers="mcps1.1.4.1.2 "><p id="en-us_topic_0000001058830740_p12602137155110"><a name="en-us_topic_0000001058830740_p12602137155110"></a><a name="en-us_topic_0000001058830740_p12602137155110"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="45.5945594559456%" headers="mcps1.1.4.1.3 "><p id="en-us_topic_0000001058830740_p160267105114"><a name="en-us_topic_0000001058830740_p160267105114"></a><a name="en-us_topic_0000001058830740_p160267105114"></a>Triggered when the frame animation resumes</p>
</td>
</tr>
<tr id="en-us_topic_0000001058830740_row336512569516"><td class="cellrowborder" valign="top" width="24.852485248524854%" headers="mcps1.1.4.1.1 "><p id="en-us_topic_0000001058830740_en-us_topic_0000001058460527_a58fb4b1d870f466e955cf5ea879c4d4a"><a name="en-us_topic_0000001058830740_en-us_topic_0000001058460527_a58fb4b1d870f466e955cf5ea879c4d4a"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001058460527_a58fb4b1d870f466e955cf5ea879c4d4a"></a>touchstart</p>
</td>
<td class="cellrowborder" valign="top" width="29.552955295529554%" headers="mcps1.1.4.1.2 "><p id="en-us_topic_0000001058830740_en-us_topic_0000001058460527_abefebd99301b4bdebb798d1b9df24d8d"><a name="en-us_topic_0000001058830740_en-us_topic_0000001058460527_abefebd99301b4bdebb798d1b9df24d8d"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001058460527_abefebd99301b4bdebb798d1b9df24d8d"></a><a href="universal-events.md#en-us_topic_0000001058460527_tdb541af4e4db41d7a92e9b6e3c93f606">TouchEvent</a></p>
</td>
<td class="cellrowborder" valign="top" width="45.5945594559456%" headers="mcps1.1.4.1.3 "><p id="en-us_topic_0000001058830740_en-us_topic_0000001058460527_afa4290e2620f4f5fbdcb74dcae84e536"><a name="en-us_topic_0000001058830740_en-us_topic_0000001058460527_afa4290e2620f4f5fbdcb74dcae84e536"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001058460527_afa4290e2620f4f5fbdcb74dcae84e536"></a>The tapping starts</p>
</td>
</tr>
<tr id="en-us_topic_0000001058830740_row1236519563517"><td class="cellrowborder" valign="top" width="24.852485248524854%" headers="mcps1.1.4.1.1 "><p id="en-us_topic_0000001058830740_en-us_topic_0000001058460527_a23e0317cfee94650be4dcd2280c3e94e"><a name="en-us_topic_0000001058830740_en-us_topic_0000001058460527_a23e0317cfee94650be4dcd2280c3e94e"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001058460527_a23e0317cfee94650be4dcd2280c3e94e"></a>touchmove</p>
</td>
<td class="cellrowborder" valign="top" width="29.552955295529554%" headers="mcps1.1.4.1.2 "><p id="en-us_topic_0000001058830740_en-us_topic_0000001058460527_aea26e4f9575044dc8fb65080f3a6684a"><a name="en-us_topic_0000001058830740_en-us_topic_0000001058460527_aea26e4f9575044dc8fb65080f3a6684a"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001058460527_aea26e4f9575044dc8fb65080f3a6684a"></a><a href="universal-events.md#en-us_topic_0000001058460527_tdb541af4e4db41d7a92e9b6e3c93f606">TouchEvent</a></p>
</td>
<td class="cellrowborder" valign="top" width="45.5945594559456%" headers="mcps1.1.4.1.3 "><p id="en-us_topic_0000001058830740_en-us_topic_0000001058460527_a37f7cc43d82c4ee18512bd079349079d"><a name="en-us_topic_0000001058830740_en-us_topic_0000001058460527_a37f7cc43d82c4ee18512bd079349079d"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001058460527_a37f7cc43d82c4ee18512bd079349079d"></a>The tapping moves</p>
</td>
</tr>
<tr id="en-us_topic_0000001058830740_row18365145615516"><td class="cellrowborder" valign="top" width="24.852485248524854%" headers="mcps1.1.4.1.1 "><p id="en-us_topic_0000001058830740_en-us_topic_0000001058460527_ad0728eeac06143bbb4a6fdf1ed5c6d91"><a name="en-us_topic_0000001058830740_en-us_topic_0000001058460527_ad0728eeac06143bbb4a6fdf1ed5c6d91"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001058460527_ad0728eeac06143bbb4a6fdf1ed5c6d91"></a>touchcancel</p>
</td>
<td class="cellrowborder" valign="top" width="29.552955295529554%" headers="mcps1.1.4.1.2 "><p id="en-us_topic_0000001058830740_en-us_topic_0000001058460527_a59e2819eae2b4d3e935991b43156347b"><a name="en-us_topic_0000001058830740_en-us_topic_0000001058460527_a59e2819eae2b4d3e935991b43156347b"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001058460527_a59e2819eae2b4d3e935991b43156347b"></a><a href="universal-events.md#en-us_topic_0000001058460527_tdb541af4e4db41d7a92e9b6e3c93f606">TouchEvent</a></p>
</td>
<td class="cellrowborder" valign="top" width="45.5945594559456%" headers="mcps1.1.4.1.3 "><p id="en-us_topic_0000001058830740_en-us_topic_0000001058460527_a739d9ef0db624f6284554aeaeddffa0a"><a name="en-us_topic_0000001058830740_en-us_topic_0000001058460527_a739d9ef0db624f6284554aeaeddffa0a"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001058460527_a739d9ef0db624f6284554aeaeddffa0a"></a>The tapping is interrupted</p>
</td>
</tr>
<tr id="en-us_topic_0000001058830740_row63651566517"><td class="cellrowborder" valign="top" width="24.852485248524854%" headers="mcps1.1.4.1.1 "><p id="en-us_topic_0000001058830740_en-us_topic_0000001058460527_a233e2f6ff39f49fd97b8f233875d01d4"><a name="en-us_topic_0000001058830740_en-us_topic_0000001058460527_a233e2f6ff39f49fd97b8f233875d01d4"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001058460527_a233e2f6ff39f49fd97b8f233875d01d4"></a>touchend</p>
</td>
<td class="cellrowborder" valign="top" width="29.552955295529554%" headers="mcps1.1.4.1.2 "><p id="en-us_topic_0000001058830740_en-us_topic_0000001058460527_a439e69aaf158448e99b3c81cbc9fd624"><a name="en-us_topic_0000001058830740_en-us_topic_0000001058460527_a439e69aaf158448e99b3c81cbc9fd624"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001058460527_a439e69aaf158448e99b3c81cbc9fd624"></a><a href="universal-events.md#en-us_topic_0000001058460527_tdb541af4e4db41d7a92e9b6e3c93f606">TouchEvent</a></p>
</td>
<td class="cellrowborder" valign="top" width="45.5945594559456%" headers="mcps1.1.4.1.3 "><p id="en-us_topic_0000001058830740_en-us_topic_0000001058460527_a05c0fe4e05ef4154acee8a06ad56a2de"><a name="en-us_topic_0000001058830740_en-us_topic_0000001058460527_a05c0fe4e05ef4154acee8a06ad56a2de"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001058460527_a05c0fe4e05ef4154acee8a06ad56a2de"></a>The tapping ends</p>
</td>
</tr>
<tr id="en-us_topic_0000001058830740_row1536575611516"><td class="cellrowborder" valign="top" width="24.852485248524854%" headers="mcps1.1.4.1.1 "><p id="en-us_topic_0000001058830740_en-us_topic_0000001058460527_a2fb4de45b1594f6fa1a7da45ce0db57f"><a name="en-us_topic_0000001058830740_en-us_topic_0000001058460527_a2fb4de45b1594f6fa1a7da45ce0db57f"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001058460527_a2fb4de45b1594f6fa1a7da45ce0db57f"></a>click</p>
</td>
<td class="cellrowborder" valign="top" width="29.552955295529554%" headers="mcps1.1.4.1.2 "><p id="en-us_topic_0000001058830740_en-us_topic_0000001058460527_af86bf1da40504ed2a8d14213a42536ab"><a name="en-us_topic_0000001058830740_en-us_topic_0000001058460527_af86bf1da40504ed2a8d14213a42536ab"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001058460527_af86bf1da40504ed2a8d14213a42536ab"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="45.5945594559456%" headers="mcps1.1.4.1.3 "><p id="en-us_topic_0000001058830740_en-us_topic_0000001058460527_a1d32f00c38c440ddaa63c3f3e01d4e09"><a name="en-us_topic_0000001058830740_en-us_topic_0000001058460527_a1d32f00c38c440ddaa63c3f3e01d4e09"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001058460527_a1d32f00c38c440ddaa63c3f3e01d4e09"></a>A component is clicked</p>
</td>
</tr>
<tr id="en-us_topic_0000001058830740_row183661256758"><td class="cellrowborder" valign="top" width="24.852485248524854%" headers="mcps1.1.4.1.1 "><p id="en-us_topic_0000001058830740_en-us_topic_0000001058460527_aa7dc63d1b4924872bbff6a6a100e928f"><a name="en-us_topic_0000001058830740_en-us_topic_0000001058460527_aa7dc63d1b4924872bbff6a6a100e928f"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001058460527_aa7dc63d1b4924872bbff6a6a100e928f"></a>longpress</p>
</td>
<td class="cellrowborder" valign="top" width="29.552955295529554%" headers="mcps1.1.4.1.2 "><p id="en-us_topic_0000001058830740_en-us_topic_0000001058460527_a39186f4ff74544d89ace56ea87d9937b"><a name="en-us_topic_0000001058830740_en-us_topic_0000001058460527_a39186f4ff74544d89ace56ea87d9937b"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001058460527_a39186f4ff74544d89ace56ea87d9937b"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="45.5945594559456%" headers="mcps1.1.4.1.3 "><p id="en-us_topic_0000001058830740_en-us_topic_0000001058460527_a44b8585170304b5596c41714772e605e"><a name="en-us_topic_0000001058830740_en-us_topic_0000001058460527_a44b8585170304b5596c41714772e605e"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001058460527_a44b8585170304b5596c41714772e605e"></a>A component is long pressed</p>
</td>
</tr>
<tr id="en-us_topic_0000001058830740_row5366185613517"><td class="cellrowborder" valign="top" width="24.852485248524854%" headers="mcps1.1.4.1.1 "><p id="en-us_topic_0000001058830740_en-us_topic_0000001058460527_p12706561061"><a name="en-us_topic_0000001058830740_en-us_topic_0000001058460527_p12706561061"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001058460527_p12706561061"></a>swipe<sup id="en-us_topic_0000001058830740_en-us_topic_0000001058460527_sup35424382912"><a name="en-us_topic_0000001058830740_en-us_topic_0000001058460527_sup35424382912"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001058460527_sup35424382912"></a>5+</sup></p>
</td>
<td class="cellrowborder" valign="top" width="29.552955295529554%" headers="mcps1.1.4.1.2 "><p id="en-us_topic_0000001058830740_en-us_topic_0000001058460527_p11711056161"><a name="en-us_topic_0000001058830740_en-us_topic_0000001058460527_p11711056161"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001058460527_p11711056161"></a><a href="universal-events.md#en-us_topic_0000001058460527_table111811577714">SwipeEvent</a></p>
</td>
<td class="cellrowborder" valign="top" width="45.5945594559456%" headers="mcps1.1.4.1.3 "><p id="en-us_topic_0000001058830740_en-us_topic_0000001058460527_p2711556162"><a name="en-us_topic_0000001058830740_en-us_topic_0000001058460527_p2711556162"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001058460527_p2711556162"></a>A user quickly swipes on a component.</p>
</td>
</tr>
</tbody>
</table>

## Style<a name="en-us_topic_0000001058830740_section567195511491"></a>

<a name="en-us_topic_0000001058830740_table1744514388541"></a>
<table><thead align="left"><tr id="en-us_topic_0000001058830740_row1244614388545"><th class="cellrowborder" valign="top" width="23.11768823117688%" id="mcps1.1.6.1.1"><p id="en-us_topic_0000001058830740_en-us_topic_0000001059340528_a14a0c012a26248cfbec6b13dcc4f2cbe"><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_a14a0c012a26248cfbec6b13dcc4f2cbe"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_a14a0c012a26248cfbec6b13dcc4f2cbe"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="20.477952204779523%" id="mcps1.1.6.1.2"><p id="en-us_topic_0000001058830740_en-us_topic_0000001059340528_a8dc328a555a74157a00de86181fc3a7b"><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_a8dc328a555a74157a00de86181fc3a7b"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_a8dc328a555a74157a00de86181fc3a7b"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="8.869113088691131%" id="mcps1.1.6.1.3"><p id="en-us_topic_0000001058830740_en-us_topic_0000001059340528_a41a31e48d0c74ad4982add2655515c82"><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_a41a31e48d0c74ad4982add2655515c82"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_a41a31e48d0c74ad4982add2655515c82"></a>Default Value</p>
</th>
<th class="cellrowborder" valign="top" width="7.519248075192481%" id="mcps1.1.6.1.4"><p id="en-us_topic_0000001058830740_p117421754619"><a name="en-us_topic_0000001058830740_p117421754619"></a><a name="en-us_topic_0000001058830740_p117421754619"></a>Mandatory</p>
</th>
<th class="cellrowborder" valign="top" width="40.01599840015999%" id="mcps1.1.6.1.5"><p id="en-us_topic_0000001058830740_en-us_topic_0000001059340528_af7a726e456f7485c87bd4e0527bc6584"><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_af7a726e456f7485c87bd4e0527bc6584"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_af7a726e456f7485c87bd4e0527bc6584"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="en-us_topic_0000001058830740_row13446238145410"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="en-us_topic_0000001058830740_en-us_topic_0000001059340528_a8bc81ecef4934adf91deb1d6167045d7"><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_a8bc81ecef4934adf91deb1d6167045d7"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_a8bc81ecef4934adf91deb1d6167045d7"></a>width</p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p id="en-us_topic_0000001058830740_en-us_topic_0000001059340528_a59692217b9c94353a020a2f0a20f01a7"><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_a59692217b9c94353a020a2f0a20f01a7"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_a59692217b9c94353a020a2f0a20f01a7"></a>&lt;length&gt; | &lt;percentage&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p id="en-us_topic_0000001058830740_en-us_topic_0000001059340528_p3948114217528"><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_p3948114217528"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_p3948114217528"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p id="en-us_topic_0000001058830740_p13174101704612"><a name="en-us_topic_0000001058830740_p13174101704612"></a><a name="en-us_topic_0000001058830740_p13174101704612"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="en-us_topic_0000001058830740_en-us_topic_0000001059340528_p624653010258"><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_p624653010258"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_p624653010258"></a>Component width.</p>
<p id="en-us_topic_0000001058830740_en-us_topic_0000001059340528_p84811050134010"><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_p84811050134010"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_p84811050134010"></a>If this attribute is not set, the width required for the element content is used. </p>
</td>
</tr>
<tr id="en-us_topic_0000001058830740_row7446738195418"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="en-us_topic_0000001058830740_en-us_topic_0000001059340528_a738cc687552c4b8cb1aa9f9e7d9ea8c2"><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_a738cc687552c4b8cb1aa9f9e7d9ea8c2"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_a738cc687552c4b8cb1aa9f9e7d9ea8c2"></a>height</p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p id="en-us_topic_0000001058830740_en-us_topic_0000001059340528_a82c5d9c65b3646ec92afe5f0f47a2149"><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_a82c5d9c65b3646ec92afe5f0f47a2149"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_a82c5d9c65b3646ec92afe5f0f47a2149"></a>&lt;length&gt;<span id="en-us_topic_0000001058830740_en-us_topic_0000001059340528_ph11748352163918"><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_ph11748352163918"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_ph11748352163918"></a></span> | &lt;percentage&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p id="en-us_topic_0000001058830740_en-us_topic_0000001059340528_a7e6c7daafecf475888d0420835662eb4"><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_a7e6c7daafecf475888d0420835662eb4"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_a7e6c7daafecf475888d0420835662eb4"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p id="en-us_topic_0000001058830740_p71741417194619"><a name="en-us_topic_0000001058830740_p71741417194619"></a><a name="en-us_topic_0000001058830740_p71741417194619"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="en-us_topic_0000001058830740_en-us_topic_0000001059340528_p1477601264"><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_p1477601264"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_p1477601264"></a>Component height.</p>
<p id="en-us_topic_0000001058830740_en-us_topic_0000001059340528_p208761554184020"><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_p208761554184020"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_p208761554184020"></a>If this length attribute is not set, the length required for the element content is used. </p>
</td>
</tr>
<tr id="en-us_topic_0000001058830740_row18446638145412"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="en-us_topic_0000001058830740_en-us_topic_0000001059340528_a8ff18465b8f0453c836067e5902b7eb6"><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_a8ff18465b8f0453c836067e5902b7eb6"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_a8ff18465b8f0453c836067e5902b7eb6"></a>padding</p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p id="en-us_topic_0000001058830740_en-us_topic_0000001059340528_a53628f36a25a4823a901d5b66860f44e"><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_a53628f36a25a4823a901d5b66860f44e"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_a53628f36a25a4823a901d5b66860f44e"></a>&lt;length&gt; | &lt;percentage&gt;<sup id="en-us_topic_0000001058830740_en-us_topic_0000001059340528_sup1886516813013"><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_sup1886516813013"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_sup1886516813013"></a>5+</sup></p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p id="en-us_topic_0000001058830740_en-us_topic_0000001059340528_adc824deaee924821a47a798b589f22c8"><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_adc824deaee924821a47a798b589f22c8"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_adc824deaee924821a47a798b589f22c8"></a>0</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p id="en-us_topic_0000001058830740_en-us_topic_0000001059340528_p19729127112814"><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_p19729127112814"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_p19729127112814"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="en-us_topic_0000001058830740_en-us_topic_0000001059340528_p157435053316"><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_p157435053316"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_p157435053316"></a>Shorthand attribute to set all padding attributes.</p>
<div class="p" id="en-us_topic_0000001058830740_en-us_topic_0000001059340528_a68a6d5ddc59c49f0aaddd82e75932524"><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_a68a6d5ddc59c49f0aaddd82e75932524"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_a68a6d5ddc59c49f0aaddd82e75932524"></a>The attribute can have one to four values:<a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_ul15202134923211"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_ul15202134923211"></a><ul id="en-us_topic_0000001058830740_en-us_topic_0000001059340528_ul15202134923211"><li><p id="en-us_topic_0000001058830740_en-us_topic_0000001059340528_p10614155353215"><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_p10614155353215"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_p10614155353215"></a>If you set only one value, it specifies the padding for four sides.</p>
</li><li><p id="en-us_topic_0000001058830740_en-us_topic_0000001059340528_p10614175393216"><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_p10614175393216"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_p10614175393216"></a>If you set two values, the first value specifies the top and bottom padding, and the second value specifies the left and right padding.</p>
</li><li><p id="en-us_topic_0000001058830740_en-us_topic_0000001059340528_p8614205393214"><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_p8614205393214"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_p8614205393214"></a>If you set three values, the first value specifies the top padding, the second value specifies the left and right padding, and the third value specifies the bottom padding.</p>
</li><li><p id="en-us_topic_0000001058830740_en-us_topic_0000001059340528_p106141853193215"><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_p106141853193215"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_p106141853193215"></a>If you set four values, they respectively specify the padding for top, right, bottom, and left sides (in clockwise order).</p>
</li></ul>
</div>
</td>
</tr>
<tr id="en-us_topic_0000001058830740_row24464380544"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="en-us_topic_0000001058830740_en-us_topic_0000001059340528_ab0185a7b5a4944f3b38f8c71c8ca794d"><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_ab0185a7b5a4944f3b38f8c71c8ca794d"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_ab0185a7b5a4944f3b38f8c71c8ca794d"></a>padding-[left|top|right|bottom]</p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p id="en-us_topic_0000001058830740_en-us_topic_0000001059340528_a49dd523e2f1b4253a19231e776dc1951"><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_a49dd523e2f1b4253a19231e776dc1951"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_a49dd523e2f1b4253a19231e776dc1951"></a>&lt;length&gt; | &lt;percentage&gt;<sup id="en-us_topic_0000001058830740_en-us_topic_0000001059340528_sup19949912807"><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_sup19949912807"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_sup19949912807"></a>5+</sup></p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p id="en-us_topic_0000001058830740_en-us_topic_0000001059340528_af52ecd93919b4fa08ae4d376e3d544a2"><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_af52ecd93919b4fa08ae4d376e3d544a2"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_af52ecd93919b4fa08ae4d376e3d544a2"></a>0</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p id="en-us_topic_0000001058830740_en-us_topic_0000001059340528_p11729374289"><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_p11729374289"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_p11729374289"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="en-us_topic_0000001058830740_en-us_topic_0000001059340528_a3575ab240d384ab1a21119ea3428ab7d"><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_a3575ab240d384ab1a21119ea3428ab7d"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_a3575ab240d384ab1a21119ea3428ab7d"></a>Left, top, right, and bottom padding (in px).</p>
</td>
</tr>
<tr id="en-us_topic_0000001058830740_row1144723845412"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="en-us_topic_0000001058830740_en-us_topic_0000001059340528_p769124717365"><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_p769124717365"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_p769124717365"></a>padding-[start|end]</p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p id="en-us_topic_0000001058830740_en-us_topic_0000001059340528_p157617124374"><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_p157617124374"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_p157617124374"></a>&lt;length&gt; | &lt;percentage&gt;<sup id="en-us_topic_0000001058830740_en-us_topic_0000001059340528_sup8490161513019"><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_sup8490161513019"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_sup8490161513019"></a>5+</sup></p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p id="en-us_topic_0000001058830740_en-us_topic_0000001059340528_p1069144703616"><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_p1069144703616"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_p1069144703616"></a>0</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p id="en-us_topic_0000001058830740_en-us_topic_0000001059340528_p1373027182819"><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_p1373027182819"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_p1373027182819"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="en-us_topic_0000001058830740_en-us_topic_0000001059340528_p1269184753610"><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_p1269184753610"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_p1269184753610"></a>Start and end padding.</p>
</td>
</tr>
<tr id="en-us_topic_0000001058830740_row11447438175410"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="en-us_topic_0000001058830740_en-us_topic_0000001059340528_afa508e5429d948b2b561943d6b2f0f31"><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_afa508e5429d948b2b561943d6b2f0f31"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_afa508e5429d948b2b561943d6b2f0f31"></a>margin</p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p id="en-us_topic_0000001058830740_en-us_topic_0000001059340528_a4dab4f9d97a74a27a45b7ef1d2ab08e6"><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_a4dab4f9d97a74a27a45b7ef1d2ab08e6"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_a4dab4f9d97a74a27a45b7ef1d2ab08e6"></a>&lt;length&gt; | &lt;percentage&gt;<sup id="en-us_topic_0000001058830740_en-us_topic_0000001059340528_sup1433352175220"><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_sup1433352175220"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_sup1433352175220"></a>5+</sup></p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p id="en-us_topic_0000001058830740_en-us_topic_0000001059340528_a5e3c234d78214e8180b51d237adda154"><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_a5e3c234d78214e8180b51d237adda154"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_a5e3c234d78214e8180b51d237adda154"></a>0</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p id="en-us_topic_0000001058830740_en-us_topic_0000001059340528_p4730774285"><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_p4730774285"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_p4730774285"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="en-us_topic_0000001058830740_en-us_topic_0000001059340528_a1d350e36a773420baf5ebb930cd5ad66"><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_a1d350e36a773420baf5ebb930cd5ad66"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_a1d350e36a773420baf5ebb930cd5ad66"></a>Shorthand attribute to set margins for all sides in a declaration. The attribute can have one to four values:</p>
<a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_ul5333133311105"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_ul5333133311105"></a><ul id="en-us_topic_0000001058830740_en-us_topic_0000001059340528_ul5333133311105"><li><p id="en-us_topic_0000001058830740_en-us_topic_0000001059340528_p03345339103"><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_p03345339103"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_p03345339103"></a>If you set only one value, it specifies the margin for all the four sides.</p>
</li><li><p id="en-us_topic_0000001058830740_en-us_topic_0000001059340528_p1133420334108"><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_p1133420334108"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_p1133420334108"></a>If you set two values, the first value is for the top and bottom sides and the second value for the left and right sides.</p>
</li><li><p id="en-us_topic_0000001058830740_en-us_topic_0000001059340528_p193341533191015"><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_p193341533191015"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_p193341533191015"></a>If you set three values, the first value is for the top, the second value for the left and right, and the third value for the bottom.</p>
</li><li><p id="en-us_topic_0000001058830740_en-us_topic_0000001059340528_p733412334102"><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_p733412334102"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_p733412334102"></a>If you set four values, they are margins for top, right, bottom, and left sides, respectively.</p>
</li></ul>
</td>
</tr>
<tr id="en-us_topic_0000001058830740_row144473383544"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="en-us_topic_0000001058830740_en-us_topic_0000001059340528_a70939a36b2b04dd8bec21f5bddc8637e"><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_a70939a36b2b04dd8bec21f5bddc8637e"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_a70939a36b2b04dd8bec21f5bddc8637e"></a>margin-[left|top|right|bottom]</p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p id="en-us_topic_0000001058830740_en-us_topic_0000001059340528_ae53ac9ac370d483990e04ea9789c1e49"><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_ae53ac9ac370d483990e04ea9789c1e49"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_ae53ac9ac370d483990e04ea9789c1e49"></a>&lt;length&gt; | &lt;percentage&gt;<sup id="en-us_topic_0000001058830740_en-us_topic_0000001059340528_sup378331720532"><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_sup378331720532"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_sup378331720532"></a>5+</sup></p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p id="en-us_topic_0000001058830740_en-us_topic_0000001059340528_a180cd037e6174e5c82f35a3a66b6f2ec"><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_a180cd037e6174e5c82f35a3a66b6f2ec"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_a180cd037e6174e5c82f35a3a66b6f2ec"></a>0</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p id="en-us_topic_0000001058830740_en-us_topic_0000001059340528_p773013742811"><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_p773013742811"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_p773013742811"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="en-us_topic_0000001058830740_en-us_topic_0000001059340528_a487d09add6e54c5c89fa4f22e9318271"><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_a487d09add6e54c5c89fa4f22e9318271"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_a487d09add6e54c5c89fa4f22e9318271"></a>Left, top, right, and bottom margins.</p>
</td>
</tr>
<tr id="en-us_topic_0000001058830740_row944743811541"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="en-us_topic_0000001058830740_en-us_topic_0000001059340528_p9492107123816"><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_p9492107123816"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_p9492107123816"></a>margin-[start|end]</p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p id="en-us_topic_0000001058830740_en-us_topic_0000001059340528_p157617124374_1"><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_p157617124374_1"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_p157617124374_1"></a>&lt;length&gt; | &lt;percentage&gt;<sup id="en-us_topic_0000001058830740_en-us_topic_0000001059340528_sup8490161513019_1"><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_sup8490161513019_1"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_sup8490161513019_1"></a>5+</sup></p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p id="en-us_topic_0000001058830740_en-us_topic_0000001059340528_p1549213793811"><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_p1549213793811"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_p1549213793811"></a>0</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p id="en-us_topic_0000001058830740_p117511744618"><a name="en-us_topic_0000001058830740_p117511744618"></a><a name="en-us_topic_0000001058830740_p117511744618"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="en-us_topic_0000001058830740_en-us_topic_0000001059340528_p1049212715388"><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_p1049212715388"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_p1049212715388"></a>Start and end margins.</p>
</td>
</tr>
<tr id="en-us_topic_0000001058830740_row16447238155411"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="en-us_topic_0000001058830740_en-us_topic_0000001059340528_a222bb48f24014f2eb2b16a1a840bbebb"><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_a222bb48f24014f2eb2b16a1a840bbebb"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_a222bb48f24014f2eb2b16a1a840bbebb"></a>border</p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p id="en-us_topic_0000001058830740_en-us_topic_0000001059340528_a79b4eaf9983c44d0aad39ff04d0997a8"><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_a79b4eaf9983c44d0aad39ff04d0997a8"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_a79b4eaf9983c44d0aad39ff04d0997a8"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p id="en-us_topic_0000001058830740_en-us_topic_0000001059340528_aac320f4f0a42401aa7fa778d9829d77c"><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_aac320f4f0a42401aa7fa778d9829d77c"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_aac320f4f0a42401aa7fa778d9829d77c"></a>0</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p id="en-us_topic_0000001058830740_p11175131715467"><a name="en-us_topic_0000001058830740_p11175131715467"></a><a name="en-us_topic_0000001058830740_p11175131715467"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="en-us_topic_0000001058830740_en-us_topic_0000001059340528_a9cd962871a4c467a8e1ef452621d5cd7"><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_a9cd962871a4c467a8e1ef452621d5cd7"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_a9cd962871a4c467a8e1ef452621d5cd7"></a>Shorthand attribute to set all borders. You can set <strong id="en-us_topic_0000001058830740_en-us_topic_0000001059340528_b79128342503"><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_b79128342503"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_b79128342503"></a>border-width</strong>, <strong id="en-us_topic_0000001058830740_en-us_topic_0000001059340528_b9366173919505"><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_b9366173919505"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_b9366173919505"></a>border-style</strong>, and <strong id="en-us_topic_0000001058830740_en-us_topic_0000001059340528_b184351248205019"><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_b184351248205019"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_b184351248205019"></a>border-color</strong> in sequence. Default values are used for attributes that are not set.</p>
</td>
</tr>
<tr id="en-us_topic_0000001058830740_row4447138115414"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="en-us_topic_0000001058830740_en-us_topic_0000001059340528_a987708c0864a4128af094334f1b024b3"><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_a987708c0864a4128af094334f1b024b3"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_a987708c0864a4128af094334f1b024b3"></a>border-style</p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p id="en-us_topic_0000001058830740_en-us_topic_0000001059340528_p513631613319"><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_p513631613319"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_p513631613319"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p id="en-us_topic_0000001058830740_en-us_topic_0000001059340528_a2567083af59c40e58e3e4d9b0ddf1485"><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_a2567083af59c40e58e3e4d9b0ddf1485"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_a2567083af59c40e58e3e4d9b0ddf1485"></a>solid</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p id="en-us_topic_0000001058830740_p617531717464"><a name="en-us_topic_0000001058830740_p617531717464"></a><a name="en-us_topic_0000001058830740_p617531717464"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="en-us_topic_0000001058830740_en-us_topic_0000001059340528_p342285712314"><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_p342285712314"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_p342285712314"></a>Shorthand attribute to set the style for all borders. Available values are as follows:</p>
<a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_ul1470834505612"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_ul1470834505612"></a><ul id="en-us_topic_0000001058830740_en-us_topic_0000001059340528_ul1470834505612"><li><strong id="en-us_topic_0000001058830740_en-us_topic_0000001059340528_b143453286360"><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_b143453286360"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_b143453286360"></a>dotted</strong>: Dotted border. The radius of a dot is half of border-width.</li><li><strong id="en-us_topic_0000001058830740_en-us_topic_0000001059340528_b792117280367"><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_b792117280367"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_b792117280367"></a>dashed</strong>: Dashed border</li></ul>
<a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_ul15621125545612"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_ul15621125545612"></a><ul id="en-us_topic_0000001058830740_en-us_topic_0000001059340528_ul15621125545612"><li><strong id="en-us_topic_0000001058830740_en-us_topic_0000001059340528_b1335862963610"><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_b1335862963610"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_b1335862963610"></a>solid</strong>: Solid border</li></ul>
</td>
</tr>
<tr id="en-us_topic_0000001058830740_row1656512239262"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="en-us_topic_0000001058830740_en-us_topic_0000001059340528_p119531437370"><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_p119531437370"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_p119531437370"></a>border-[left|top|right|bottom]-style</p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p id="en-us_topic_0000001058830740_en-us_topic_0000001059340528_p129532037175"><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_p129532037175"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_p129532037175"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p id="en-us_topic_0000001058830740_en-us_topic_0000001059340528_p495312372717"><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_p495312372717"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_p495312372717"></a>solid</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p id="en-us_topic_0000001058830740_en-us_topic_0000001059340528_p169534375717"><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_p169534375717"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_p169534375717"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="en-us_topic_0000001058830740_en-us_topic_0000001059340528_p595353718719"><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_p595353718719"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_p595353718719"></a>Styles of the left, top, right, and bottom borders. The available values are <strong id="en-us_topic_0000001058830740_en-us_topic_0000001059340528_b17769171311540"><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_b17769171311540"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_b17769171311540"></a>dotted</strong>, <strong id="en-us_topic_0000001058830740_en-us_topic_0000001059340528_b237141519547"><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_b237141519547"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_b237141519547"></a>dashed</strong>, and <strong id="en-us_topic_0000001058830740_en-us_topic_0000001059340528_b8949161613540"><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_b8949161613540"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_b8949161613540"></a>solid</strong>.</p>
</td>
</tr>
<tr id="en-us_topic_0000001058830740_row19448113811542"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="en-us_topic_0000001058830740_en-us_topic_0000001059340528_a8afd82b1aba547d3b0188b749518b2de"><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_a8afd82b1aba547d3b0188b749518b2de"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_a8afd82b1aba547d3b0188b749518b2de"></a>border-[left|top|right|bottom]</p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p id="en-us_topic_0000001058830740_en-us_topic_0000001059340528_ac4b8a3b39e5446b5868f1f2989dc9590"><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_ac4b8a3b39e5446b5868f1f2989dc9590"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_ac4b8a3b39e5446b5868f1f2989dc9590"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p id="en-us_topic_0000001058830740_en-us_topic_0000001059340528_a3420bc82bd17458ab82fa996ade7064c"><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_a3420bc82bd17458ab82fa996ade7064c"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_a3420bc82bd17458ab82fa996ade7064c"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p id="en-us_topic_0000001058830740_en-us_topic_0000001059340528_p67303762810"><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_p67303762810"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_p67303762810"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="en-us_topic_0000001058830740_en-us_topic_0000001059340528_af4178a066c344412afbd38f4b0c44818"><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_af4178a066c344412afbd38f4b0c44818"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_af4178a066c344412afbd38f4b0c44818"></a>Shorthand attribute to set the borders for every side respectively. You can set <strong id="en-us_topic_0000001058830740_en-us_topic_0000001059340528_b122415514554"><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_b122415514554"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_b122415514554"></a>border-width</strong>, <strong id="en-us_topic_0000001058830740_en-us_topic_0000001059340528_b12296178135513"><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_b12296178135513"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_b12296178135513"></a>border-style</strong>, and <strong id="en-us_topic_0000001058830740_en-us_topic_0000001059340528_b1129701210553"><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_b1129701210553"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_b1129701210553"></a>border-color</strong> in sequence. Default values are used for attributes that are not set.</p>
</td>
</tr>
<tr id="en-us_topic_0000001058830740_row124481638165417"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="en-us_topic_0000001058830740_en-us_topic_0000001059340528_adf0e0afedc774afca9cda0e509391029"><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_adf0e0afedc774afca9cda0e509391029"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_adf0e0afedc774afca9cda0e509391029"></a>border-width</p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p id="en-us_topic_0000001058830740_en-us_topic_0000001059340528_a0782ea2c45eb4864a8df82f30dd2cd5f"><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_a0782ea2c45eb4864a8df82f30dd2cd5f"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_a0782ea2c45eb4864a8df82f30dd2cd5f"></a>&lt;length&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p id="en-us_topic_0000001058830740_en-us_topic_0000001059340528_a395cbedd521145bd820b9171ee2dd7ac"><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_a395cbedd521145bd820b9171ee2dd7ac"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_a395cbedd521145bd820b9171ee2dd7ac"></a>0</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p id="en-us_topic_0000001058830740_p16175131724618"><a name="en-us_topic_0000001058830740_p16175131724618"></a><a name="en-us_topic_0000001058830740_p16175131724618"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="en-us_topic_0000001058830740_en-us_topic_0000001059340528_a7ae60621ea3341818a03bfdffa641894"><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_a7ae60621ea3341818a03bfdffa641894"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_a7ae60621ea3341818a03bfdffa641894"></a>Shorthand attribute to set the width of all borders<span id="en-us_topic_0000001058830740_en-us_topic_0000001059340528_ph07997369365"><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_ph07997369365"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_ph07997369365"></a>, or separately set the width of each border</span>.</p>
</td>
</tr>
<tr id="en-us_topic_0000001058830740_row54481038165410"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="en-us_topic_0000001058830740_en-us_topic_0000001059340528_a7371edc07c664266a2e1866f31ad0d0c"><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_a7371edc07c664266a2e1866f31ad0d0c"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_a7371edc07c664266a2e1866f31ad0d0c"></a>border-[left|top|right|bottom]-width</p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p id="en-us_topic_0000001058830740_en-us_topic_0000001059340528_a2faa532b841948a7b6598542b4eccc7b"><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_a2faa532b841948a7b6598542b4eccc7b"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_a2faa532b841948a7b6598542b4eccc7b"></a>&lt;length&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p id="en-us_topic_0000001058830740_en-us_topic_0000001059340528_a87f38cfa47f54bc18c32f9671c0f9ca6"><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_a87f38cfa47f54bc18c32f9671c0f9ca6"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_a87f38cfa47f54bc18c32f9671c0f9ca6"></a>0</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p id="en-us_topic_0000001058830740_p11175151717466"><a name="en-us_topic_0000001058830740_p11175151717466"></a><a name="en-us_topic_0000001058830740_p11175151717466"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="en-us_topic_0000001058830740_en-us_topic_0000001059340528_a20386e66c3834d5f96cf9435c4715c5b"><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_a20386e66c3834d5f96cf9435c4715c5b"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_a20386e66c3834d5f96cf9435c4715c5b"></a>Attribute to set widths of left, top, right, and bottom borders.</p>
</td>
</tr>
<tr id="en-us_topic_0000001058830740_row1744817385547"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="en-us_topic_0000001058830740_en-us_topic_0000001059340528_a40a816cf0a03489d81f209a8aa7d81a6"><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_a40a816cf0a03489d81f209a8aa7d81a6"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_a40a816cf0a03489d81f209a8aa7d81a6"></a>border-color</p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p id="en-us_topic_0000001058830740_en-us_topic_0000001059340528_afcc7c948ae0947b2a78002d31f2f9748"><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_afcc7c948ae0947b2a78002d31f2f9748"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_afcc7c948ae0947b2a78002d31f2f9748"></a>&lt;color&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p id="en-us_topic_0000001058830740_en-us_topic_0000001059340528_ae0909d2b896342f9b2196fe0dce72920"><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_ae0909d2b896342f9b2196fe0dce72920"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_ae0909d2b896342f9b2196fe0dce72920"></a>black</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p id="en-us_topic_0000001058830740_p1017518177465"><a name="en-us_topic_0000001058830740_p1017518177465"></a><a name="en-us_topic_0000001058830740_p1017518177465"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="en-us_topic_0000001058830740_en-us_topic_0000001059340528_a76fd98995e1d4217aa703fecd69325c7"><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_a76fd98995e1d4217aa703fecd69325c7"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_a76fd98995e1d4217aa703fecd69325c7"></a>Shorthand attribute to set the color of all borders<span id="en-us_topic_0000001058830740_en-us_topic_0000001059340528_ph9587639113619"><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_ph9587639113619"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_ph9587639113619"></a>, or separately set the color of each border</span>.</p>
</td>
</tr>
<tr id="en-us_topic_0000001058830740_row844813835410"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="en-us_topic_0000001058830740_en-us_topic_0000001059340528_a2afc646d6a2549548bcd5c4b9bed1fb5"><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_a2afc646d6a2549548bcd5c4b9bed1fb5"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_a2afc646d6a2549548bcd5c4b9bed1fb5"></a>border-[left|top|right|bottom]-color</p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p id="en-us_topic_0000001058830740_en-us_topic_0000001059340528_a34556866a4f54f5da88f148fc698867b"><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_a34556866a4f54f5da88f148fc698867b"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_a34556866a4f54f5da88f148fc698867b"></a>&lt;color&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p id="en-us_topic_0000001058830740_en-us_topic_0000001059340528_a8ff58e18553846a38e82c69149e2aa30"><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_a8ff58e18553846a38e82c69149e2aa30"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_a8ff58e18553846a38e82c69149e2aa30"></a>black</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p id="en-us_topic_0000001058830740_p11175417184611"><a name="en-us_topic_0000001058830740_p11175417184611"></a><a name="en-us_topic_0000001058830740_p11175417184611"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="en-us_topic_0000001058830740_en-us_topic_0000001059340528_a5c85947d388c4c7fbf0de07b022bb44e"><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_a5c85947d388c4c7fbf0de07b022bb44e"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_a5c85947d388c4c7fbf0de07b022bb44e"></a>Attribute to set colors of left, top, right, and bottom borders.</p>
</td>
</tr>
<tr id="en-us_topic_0000001058830740_row944813389540"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="en-us_topic_0000001058830740_en-us_topic_0000001059340528_a65974e3078c447a383fb9237cc4ffa32"><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_a65974e3078c447a383fb9237cc4ffa32"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_a65974e3078c447a383fb9237cc4ffa32"></a>border-radius</p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p id="en-us_topic_0000001058830740_en-us_topic_0000001059340528_a413fd0aea8b243349a19f825e96ee8b6"><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_a413fd0aea8b243349a19f825e96ee8b6"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_a413fd0aea8b243349a19f825e96ee8b6"></a>&lt;length&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p id="en-us_topic_0000001058830740_en-us_topic_0000001059340528_af786857698c74e259f52589a6670a0a1"><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_af786857698c74e259f52589a6670a0a1"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_af786857698c74e259f52589a6670a0a1"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p id="en-us_topic_0000001058830740_en-us_topic_0000001059340528_p67306752816"><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_p67306752816"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_p67306752816"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="en-us_topic_0000001058830740_en-us_topic_0000001059340528_a52ca834f42124d3b8b12bbf54914fc96"><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_a52ca834f42124d3b8b12bbf54914fc96"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_a52ca834f42124d3b8b12bbf54914fc96"></a>Attribute to set the radius of round borders of an element. <span id="en-us_topic_0000001058830740_en-us_topic_0000001059340528_ph1249443123611"><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_ph1249443123611"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_ph1249443123611"></a>This attribute cannot be used to set the width, color, or style of a specific border. To set the width or color, you need to set <strong id="en-us_topic_0000001058830740_en-us_topic_0000001059340528_b124211434362"><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_b124211434362"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_b124211434362"></a>border-width</strong>, <strong id="en-us_topic_0000001058830740_en-us_topic_0000001059340528_b124894383615"><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_b124894383615"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_b124894383615"></a>border-color</strong>, or <strong id="en-us_topic_0000001058830740_en-us_topic_0000001059340528_b7166134516465"><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_b7166134516465"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_b7166134516465"></a>border-style</strong> for all the borders at the same time.</span></p>
</td>
</tr>
<tr id="en-us_topic_0000001058830740_row104494382546"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="en-us_topic_0000001058830740_en-us_topic_0000001059340528_a466f1f8bc2fb404e82e8417c5133eacb"><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_a466f1f8bc2fb404e82e8417c5133eacb"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_a466f1f8bc2fb404e82e8417c5133eacb"></a>border-[top|bottom]-[left|right]-radius</p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p id="en-us_topic_0000001058830740_en-us_topic_0000001059340528_a499fe910d0284647abc48b1bd0eb4868"><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_a499fe910d0284647abc48b1bd0eb4868"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_a499fe910d0284647abc48b1bd0eb4868"></a>&lt;length&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p id="en-us_topic_0000001058830740_en-us_topic_0000001059340528_ac142d1054eee499f948069f46129c492"><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_ac142d1054eee499f948069f46129c492"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_ac142d1054eee499f948069f46129c492"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p id="en-us_topic_0000001058830740_en-us_topic_0000001059340528_p27305718283"><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_p27305718283"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_p27305718283"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="en-us_topic_0000001058830740_en-us_topic_0000001059340528_a63757091a86c4ced97f0c39d37a2117c"><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_a63757091a86c4ced97f0c39d37a2117c"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_a63757091a86c4ced97f0c39d37a2117c"></a>Attribute to receptively set the radii of upper-left, upper-right, lower-right, and lower-left rounded corners</p>
</td>
</tr>
<tr id="en-us_topic_0000001058830740_row1344912384548"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="en-us_topic_0000001058830740_en-us_topic_0000001059340528_ae335be2c6150440fb31b40b1ca117858"><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_ae335be2c6150440fb31b40b1ca117858"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_ae335be2c6150440fb31b40b1ca117858"></a>background</p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p id="en-us_topic_0000001058830740_en-us_topic_0000001059340528_a394a81171c5c4d1aa81b94fc5d2f0f07"><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_a394a81171c5c4d1aa81b94fc5d2f0f07"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_a394a81171c5c4d1aa81b94fc5d2f0f07"></a>&lt;linear-gradient&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p id="en-us_topic_0000001058830740_en-us_topic_0000001059340528_a0734de04e90e470cb608e8d5f42c6874"><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_a0734de04e90e470cb608e8d5f42c6874"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_a0734de04e90e470cb608e8d5f42c6874"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p id="en-us_topic_0000001058830740_en-us_topic_0000001059340528_p15730197132811"><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_p15730197132811"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_p15730197132811"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="en-us_topic_0000001058830740_en-us_topic_0000001059340528_a1d2985ee819d4cfd87861080354def51"><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_a1d2985ee819d4cfd87861080354def51"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_a1d2985ee819d4cfd87861080354def51"></a>This attribute supports <a href="gradient-styles.md#EN-US_TOPIC_0000001115974726">Gradient Styles</a> only but is not compatible with <strong id="en-us_topic_0000001058830740_en-us_topic_0000001059340528_b389373419292"><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_b389373419292"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_b389373419292"></a>background-color</strong> or <strong id="en-us_topic_0000001058830740_en-us_topic_0000001059340528_b0399637142918"><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_b0399637142918"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_b0399637142918"></a>background-image</strong>.</p>
</td>
</tr>
<tr id="en-us_topic_0000001058830740_row15449838185416"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="en-us_topic_0000001058830740_en-us_topic_0000001059340528_a2977672444224b738a566c61225961c2"><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_a2977672444224b738a566c61225961c2"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_a2977672444224b738a566c61225961c2"></a>background-color</p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p id="en-us_topic_0000001058830740_en-us_topic_0000001059340528_a87186748ed7c4694aef0095d8a7f8e43"><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_a87186748ed7c4694aef0095d8a7f8e43"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_a87186748ed7c4694aef0095d8a7f8e43"></a>&lt;color&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p id="en-us_topic_0000001058830740_en-us_topic_0000001059340528_a2775a3cca8994bec9b754af0d2455eb5"><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_a2775a3cca8994bec9b754af0d2455eb5"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_a2775a3cca8994bec9b754af0d2455eb5"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p id="en-us_topic_0000001058830740_en-us_topic_0000001059340528_p17730577282"><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_p17730577282"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_p17730577282"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="en-us_topic_0000001058830740_en-us_topic_0000001059340528_a372b6089bf9746f091c91fa49b571f1d"><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_a372b6089bf9746f091c91fa49b571f1d"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_a372b6089bf9746f091c91fa49b571f1d"></a>Background color.</p>
</td>
</tr>
<tr id="en-us_topic_0000001058830740_row54491338115412"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="en-us_topic_0000001058830740_en-us_topic_0000001059340528_ab2dff80cd59c4db1bf4293172f89735e"><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_ab2dff80cd59c4db1bf4293172f89735e"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_ab2dff80cd59c4db1bf4293172f89735e"></a>background-image</p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p id="en-us_topic_0000001058830740_en-us_topic_0000001059340528_ad9a7e9f2469b45238a6a0ac6da232286"><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_ad9a7e9f2469b45238a6a0ac6da232286"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_ad9a7e9f2469b45238a6a0ac6da232286"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p id="en-us_topic_0000001058830740_en-us_topic_0000001059340528_a73fb72c96edd488ba74c364568e345c6"><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_a73fb72c96edd488ba74c364568e345c6"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_a73fb72c96edd488ba74c364568e345c6"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p id="en-us_topic_0000001058830740_en-us_topic_0000001059340528_p7730976285"><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_p7730976285"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_p7730976285"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="en-us_topic_0000001058830740_en-us_topic_0000001059340528_a24de29e3cb4d476fabe55d48d69350a8"><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_a24de29e3cb4d476fabe55d48d69350a8"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_a24de29e3cb4d476fabe55d48d69350a8"></a>Background image. Currently, this attribute is not compatible with <strong id="en-us_topic_0000001058830740_en-us_topic_0000001059340528_b17699154763620"><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_b17699154763620"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_b17699154763620"></a>background-color</strong> or <strong id="en-us_topic_0000001058830740_en-us_topic_0000001059340528_b87001647163613"><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_b87001647163613"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_b87001647163613"></a>background</strong>. Local image resources are supported.</p>
<p id="en-us_topic_0000001058830740_en-us_topic_0000001059340528_p45914251572"><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_p45914251572"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_p45914251572"></a>Example:</p>
<p id="en-us_topic_0000001058830740_en-us_topic_0000001059340528_p16184973578"><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_p16184973578"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_p16184973578"></a>background-image: url("/common/background.png")</p>
</td>
</tr>
<tr id="en-us_topic_0000001058830740_row6449238185416"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="en-us_topic_0000001058830740_en-us_topic_0000001059340528_af81424fd1fbf4f5da65ea5d136390494"><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_af81424fd1fbf4f5da65ea5d136390494"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_af81424fd1fbf4f5da65ea5d136390494"></a>background-size</p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_ul1065173641310"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_ul1065173641310"></a><ul id="en-us_topic_0000001058830740_en-us_topic_0000001059340528_ul1065173641310"><li>string</li><li>&lt;length&gt; &lt;length&gt;</li><li>&lt;percentage&gt; &lt;percentage&gt;</li></ul>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p id="en-us_topic_0000001058830740_en-us_topic_0000001059340528_a222f4e09239a4ab08880d1d9544d337c"><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_a222f4e09239a4ab08880d1d9544d337c"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_a222f4e09239a4ab08880d1d9544d337c"></a>auto</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p id="en-us_topic_0000001058830740_en-us_topic_0000001059340528_p137309714282"><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_p137309714282"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_p137309714282"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="en-us_topic_0000001058830740_en-us_topic_0000001059340528_p91971112114318"><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_p91971112114318"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_p91971112114318"></a>Background image size.</p>
<a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_ul41331853154111"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_ul41331853154111"></a><ul id="en-us_topic_0000001058830740_en-us_topic_0000001059340528_ul41331853154111"><li>The <strong id="en-us_topic_0000001058830740_en-us_topic_0000001059340528_b1229715499365"><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_b1229715499365"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_b1229715499365"></a>string</strong> values are as follows:<a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_ul13611494111"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_ul13611494111"></a><ul id="en-us_topic_0000001058830740_en-us_topic_0000001059340528_ul13611494111"><li><strong id="en-us_topic_0000001058830740_en-us_topic_0000001059340528_b4759749163610"><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_b4759749163610"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_b4759749163610"></a>contain</strong>: Expands the image to the maximum size so that the height and width of the image are applicable to the content area.</li><li><strong id="en-us_topic_0000001058830740_en-us_topic_0000001059340528_b437619381712"><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_b437619381712"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_b437619381712"></a>cover</strong>: Extends the background image to a large enough size so that the background image completely covers the background area. Some parts of the image may not be displayed in the background area.</li><li><strong id="en-us_topic_0000001058830740_en-us_topic_0000001059340528_b1425512535366"><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_b1425512535366"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_b1425512535366"></a>auto</strong>: The original image width-height ratio is retained.</li></ul>
</li><li>The two <strong id="en-us_topic_0000001058830740_en-us_topic_0000001059340528_b13309145193614"><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_b13309145193614"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_b13309145193614"></a>&lt;length&gt;</strong> values are as follows:<p id="en-us_topic_0000001058830740_en-us_topic_0000001059340528_p1840244924418"><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_p1840244924418"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_p1840244924418"></a>Width and height of the background image. The first value indicates the width, and the second value indicates the height. If you only set one value, the other value is set to <strong id="en-us_topic_0000001058830740_en-us_topic_0000001059340528_b146661156143617"><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_b146661156143617"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_b146661156143617"></a>auto</strong> by default.</p>
</li><li>The two <strong id="en-us_topic_0000001058830740_en-us_topic_0000001059340528_b1667415763613"><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_b1667415763613"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_b1667415763613"></a>&lt;percentage&gt;</strong> values are as follows:<p id="en-us_topic_0000001058830740_en-us_topic_0000001059340528_p17936154410457"><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_p17936154410457"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_p17936154410457"></a>Width and height of the background image in percentage of the parent element. The first value indicates the width, and the second value indicates the height. If you only set one value, the other value is set to <strong id="en-us_topic_0000001058830740_en-us_topic_0000001059340528_b1524319254"><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_b1524319254"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_b1524319254"></a>auto</strong> by default.</p>
</li></ul>
</td>
</tr>
<tr id="en-us_topic_0000001058830740_row94491238155415"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="en-us_topic_0000001058830740_en-us_topic_0000001059340528_a9957170386754fb5b648ba2114bd52d4"><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_a9957170386754fb5b648ba2114bd52d4"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_a9957170386754fb5b648ba2114bd52d4"></a>background-repeat</p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p id="en-us_topic_0000001058830740_en-us_topic_0000001059340528_a155b4cc325e747279694d36c2fa69bcc"><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_a155b4cc325e747279694d36c2fa69bcc"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_a155b4cc325e747279694d36c2fa69bcc"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p id="en-us_topic_0000001058830740_en-us_topic_0000001059340528_a82029c0dc1d540cf994f690b451c48f4"><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_a82029c0dc1d540cf994f690b451c48f4"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_a82029c0dc1d540cf994f690b451c48f4"></a>repeat</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p id="en-us_topic_0000001058830740_en-us_topic_0000001059340528_p1673015702810"><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_p1673015702810"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_p1673015702810"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="en-us_topic_0000001058830740_en-us_topic_0000001059340528_afb8e41c117884b368a0f1df348be8e54"><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_afb8e41c117884b368a0f1df348be8e54"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_afb8e41c117884b368a0f1df348be8e54"></a>How a background image is repeatedly drawn. By default, a background image is repeated both horizontally and vertically.</p>
<a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_ul8236153103612"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_ul8236153103612"></a><ul id="en-us_topic_0000001058830740_en-us_topic_0000001059340528_ul8236153103612"><li><strong id="en-us_topic_0000001058830740_en-us_topic_0000001059340528_b1363463710"><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_b1363463710"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_b1363463710"></a>repeat</strong>: Repeatedly draws images along the x-axis and y-axis at the same time.</li><li><strong id="en-us_topic_0000001058830740_en-us_topic_0000001059340528_b267416916377"><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_b267416916377"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_b267416916377"></a>repeat-x</strong>: Repeatedly draws images along the x-axis.</li><li><strong id="en-us_topic_0000001058830740_en-us_topic_0000001059340528_b625561011379"><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_b625561011379"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_b625561011379"></a>repeat-y</strong>: Repeatedly draws images along the y-axis.</li><li><strong id="en-us_topic_0000001058830740_en-us_topic_0000001059340528_b1122181133715"><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_b1122181133715"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_b1122181133715"></a>no-repeat</strong>: The image is not drawn repeatedly.</li></ul>
</td>
</tr>
<tr id="en-us_topic_0000001058830740_row94491738105419"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="en-us_topic_0000001058830740_en-us_topic_0000001059340528_a709eb4a9fa87428897bebb4a98693df2"><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_a709eb4a9fa87428897bebb4a98693df2"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_a709eb4a9fa87428897bebb4a98693df2"></a>background-position</p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_ul8874155216502"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_ul8874155216502"></a><ul id="en-us_topic_0000001058830740_en-us_topic_0000001059340528_ul8874155216502"><li>string string</li><li>&lt;length&gt; &lt;length&gt;</li><li>&lt;percentage&gt; &lt;percentage&gt;</li></ul>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p id="en-us_topic_0000001058830740_en-us_topic_0000001059340528_a6f8f5d1c92f447bd868a841ad1a33cb1"><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_a6f8f5d1c92f447bd868a841ad1a33cb1"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_a6f8f5d1c92f447bd868a841ad1a33cb1"></a>0px 0px</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p id="en-us_topic_0000001058830740_en-us_topic_0000001059340528_p173010720280"><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_p173010720280"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_p173010720280"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_ul1590812103363"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_ul1590812103363"></a><ul id="en-us_topic_0000001058830740_en-us_topic_0000001059340528_ul1590812103363"><li>Using keywords: If only one keyword is specified, the other value is <strong id="en-us_topic_0000001058830740_en-us_topic_0000001059340528_b5234102011540"><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_b5234102011540"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_b5234102011540"></a>center</strong> by default. The two values define the horizontal position and vertical position, respectively.<a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_ul1453531734716"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_ul1453531734716"></a><ul id="en-us_topic_0000001058830740_en-us_topic_0000001059340528_ul1453531734716"><li><strong id="en-us_topic_0000001058830740_en-us_topic_0000001059340528_b0982111273712"><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_b0982111273712"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_b0982111273712"></a>left</strong>: leftmost in the horizontal direction</li><li><strong id="en-us_topic_0000001058830740_en-us_topic_0000001059340528_b866713583912"><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_b866713583912"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_b866713583912"></a>right</strong>: rightmost in the horizontal direction</li><li><strong id="en-us_topic_0000001058830740_en-us_topic_0000001059340528_b5886013193716"><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_b5886013193716"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_b5886013193716"></a>top</strong>: top in the vertical direction</li><li><strong id="en-us_topic_0000001058830740_en-us_topic_0000001059340528_b84197142376"><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_b84197142376"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_b84197142376"></a>bottom</strong>: bottom in the vertical direction</li><li><strong id="en-us_topic_0000001058830740_en-us_topic_0000001059340528_b14894114103710"><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_b14894114103710"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_b14894114103710"></a>center</strong>: center position</li></ul>
</li></ul>
<a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_ul10908121023615"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_ul10908121023615"></a><ul id="en-us_topic_0000001058830740_en-us_topic_0000001059340528_ul10908121023615"><li>Using <strong id="en-us_topic_0000001058830740_en-us_topic_0000001059340528_b11401615193715"><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_b11401615193715"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_b11401615193715"></a>&lt;length&gt;</strong>: The first value indicates the horizontal position, and the second value indicates the vertical position. <strong id="en-us_topic_0000001058830740_en-us_topic_0000001059340528_b1341381819379"><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_b1341381819379"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_b1341381819379"></a>0 0</strong> indicates the upper left corner. The unit is pixel. If only one value is specified, the other one is <strong id="en-us_topic_0000001058830740_en-us_topic_0000001059340528_b48671516183714"><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_b48671516183714"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_b48671516183714"></a>50%</strong>.</li><li>Using <strong id="en-us_topic_0000001058830740_en-us_topic_0000001059340528_b5492717163712"><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_b5492717163712"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_b5492717163712"></a>&lt;percentage&gt;</strong>: The first value indicates the horizontal position, and the second value indicates the vertical position. <strong id="en-us_topic_0000001058830740_en-us_topic_0000001059340528_b164741723183712"><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_b164741723183712"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_b164741723183712"></a>0% 0%</strong> indicates the upper left corner. <strong id="en-us_topic_0000001058830740_en-us_topic_0000001059340528_b64022245377"><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_b64022245377"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_b64022245377"></a>100% 100%</strong> indicates the lower right corner. If only one value is specified, the other one is <strong id="en-us_topic_0000001058830740_en-us_topic_0000001059340528_b7893424163718"><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_b7893424163718"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_b7893424163718"></a>50%</strong>.</li><li>Using both <strong id="en-us_topic_0000001058830740_en-us_topic_0000001059340528_b154811725193718"><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_b154811725193718"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_b154811725193718"></a>&lt;percentage&gt;</strong> and <strong id="en-us_topic_0000001058830740_en-us_topic_0000001059340528_b34834254377"><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_b34834254377"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_b34834254377"></a>&lt;length&gt;</strong>.</li></ul>
</td>
</tr>
<tr id="en-us_topic_0000001058830740_row20450143885416"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="en-us_topic_0000001058830740_en-us_topic_0000001059340528_p134581712103910"><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_p134581712103910"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_p134581712103910"></a>opacity</p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p id="en-us_topic_0000001058830740_en-us_topic_0000001059340528_a45185999ae584676af4c36467c2ade8b"><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_a45185999ae584676af4c36467c2ade8b"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_a45185999ae584676af4c36467c2ade8b"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p id="en-us_topic_0000001058830740_en-us_topic_0000001059340528_a09ff20dda8e44794bca18c84f413d972"><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_a09ff20dda8e44794bca18c84f413d972"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_a09ff20dda8e44794bca18c84f413d972"></a>1</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p id="en-us_topic_0000001058830740_en-us_topic_0000001059340528_p1873011722814"><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_p1873011722814"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_p1873011722814"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="en-us_topic_0000001058830740_en-us_topic_0000001059340528_p122515161139"><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_p122515161139"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_p122515161139"></a>Transparency of an element. The value ranges from <strong id="en-us_topic_0000001058830740_en-us_topic_0000001059340528_b1871715526385"><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_b1871715526385"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_b1871715526385"></a>0</strong> to <strong id="en-us_topic_0000001058830740_en-us_topic_0000001059340528_b177181452103815"><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_b177181452103815"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_b177181452103815"></a>1</strong>. The value <strong id="en-us_topic_0000001058830740_en-us_topic_0000001059340528_b13718155210380"><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_b13718155210380"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_b13718155210380"></a>1</strong> means opaque, and <strong id="en-us_topic_0000001058830740_en-us_topic_0000001059340528_b6718152103818"><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_b6718152103818"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_b6718152103818"></a>0</strong> means completely transparent.</p>
</td>
</tr>
<tr id="en-us_topic_0000001058830740_row1450123865418"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="en-us_topic_0000001058830740_en-us_topic_0000001059340528_aeda9e2f8d8344958bf4f43d429dcb55e"><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_aeda9e2f8d8344958bf4f43d429dcb55e"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_aeda9e2f8d8344958bf4f43d429dcb55e"></a>display</p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p id="en-us_topic_0000001058830740_en-us_topic_0000001059340528_p1544115441446"><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_p1544115441446"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_p1544115441446"></a>string</p>
<p id="en-us_topic_0000001058830740_en-us_topic_0000001059340528_aaaa164aa970b490fb048e5f260f1c661"><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_aaaa164aa970b490fb048e5f260f1c661"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_aaaa164aa970b490fb048e5f260f1c661"></a></p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p id="en-us_topic_0000001058830740_en-us_topic_0000001059340528_aa5ce61466c9847dbb7f44852338d9006"><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_aa5ce61466c9847dbb7f44852338d9006"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_aa5ce61466c9847dbb7f44852338d9006"></a>flex</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p id="en-us_topic_0000001058830740_en-us_topic_0000001059340528_p167303762818"><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_p167303762818"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_p167303762818"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="en-us_topic_0000001058830740_en-us_topic_0000001059340528_p23704018414"><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_p23704018414"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_p23704018414"></a>How and whether to display the box containing an element. Available values are as follows:</p>
<a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_ul12227103394916"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_ul12227103394916"></a><ul id="en-us_topic_0000001058830740_en-us_topic_0000001059340528_ul12227103394916"><li><strong id="en-us_topic_0000001058830740_en-us_topic_0000001059340528_b57468289377"><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_b57468289377"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_b57468289377"></a>flex</strong>: flexible layout</li><li><strong id="en-us_topic_0000001058830740_en-us_topic_0000001059340528_b18887133293920"><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_b18887133293920"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_b18887133293920"></a>none</strong>: The element is hidden.</li></ul>
</td>
</tr>
<tr id="en-us_topic_0000001058830740_row194503380541"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="en-us_topic_0000001058830740_en-us_topic_0000001059340528_aa2ed1da39c8e4ad78829712734226ab9"><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_aa2ed1da39c8e4ad78829712734226ab9"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_aa2ed1da39c8e4ad78829712734226ab9"></a>visibility</p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p id="en-us_topic_0000001058830740_en-us_topic_0000001059340528_p15475737486"><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_p15475737486"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_p15475737486"></a>string</p>
<p id="en-us_topic_0000001058830740_en-us_topic_0000001059340528_aabfb0eb044194745af56c313f40e7781"><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_aabfb0eb044194745af56c313f40e7781"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_aabfb0eb044194745af56c313f40e7781"></a></p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p id="en-us_topic_0000001058830740_en-us_topic_0000001059340528_acaca80d4ef9a4f0d87adf92cb2d1ff9a"><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_acaca80d4ef9a4f0d87adf92cb2d1ff9a"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_acaca80d4ef9a4f0d87adf92cb2d1ff9a"></a>visible</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p id="en-us_topic_0000001058830740_en-us_topic_0000001059340528_p57301471281"><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_p57301471281"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_p57301471281"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="en-us_topic_0000001058830740_en-us_topic_0000001059340528_p1568839154517"><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_p1568839154517"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_p1568839154517"></a>Whether to display an element. Invisible borders occupy layout space. (To remove the borders, set the <strong id="en-us_topic_0000001058830740_en-us_topic_0000001059340528_b15844103015378"><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_b15844103015378"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_b15844103015378"></a>display</strong> attribute to <strong id="en-us_topic_0000001058830740_en-us_topic_0000001059340528_b4845153013712"><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_b4845153013712"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_b4845153013712"></a>none</strong>.) Available values are as follows:</p>
<a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_ul751984164920"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_ul751984164920"></a><ul id="en-us_topic_0000001058830740_en-us_topic_0000001059340528_ul751984164920"><li><strong id="en-us_topic_0000001058830740_en-us_topic_0000001059340528_b17429331133711"><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_b17429331133711"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_b17429331133711"></a>visible</strong>: The element is visible.</li><li><strong id="en-us_topic_0000001058830740_en-us_topic_0000001059340528_b109191231193710"><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_b109191231193710"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_b109191231193710"></a>hidden</strong>: The element is hidden but still takes up space.</li></ul>
<div class="note" id="en-us_topic_0000001058830740_en-us_topic_0000001059340528_note4549524649"><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_note4549524649"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_note4549524649"></a><span class="notetitle"> NOTE: </span><div class="notebody"><p id="en-us_topic_0000001058830740_en-us_topic_0000001059340528_p25499241642"><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_p25499241642"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_p25499241642"></a>If both <strong id="en-us_topic_0000001058830740_en-us_topic_0000001059340528_b719810016405"><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_b719810016405"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_b719810016405"></a>visibility</strong> and <strong id="en-us_topic_0000001058830740_en-us_topic_0000001059340528_b187052264018"><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_b187052264018"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_b187052264018"></a>display</strong> are set, only <strong id="en-us_topic_0000001058830740_en-us_topic_0000001059340528_b107788924011"><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_b107788924011"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_b107788924011"></a>display</strong> takes effect.</p>
</div></div>
</td>
</tr>
<tr id="en-us_topic_0000001058830740_row13450113811544"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="en-us_topic_0000001058830740_en-us_topic_0000001059340528_ad74a6a48aca7439e9344c18c26b4177e"><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_ad74a6a48aca7439e9344c18c26b4177e"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_ad74a6a48aca7439e9344c18c26b4177e"></a>flex</p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p id="en-us_topic_0000001058830740_en-us_topic_0000001059340528_a2e6e5192a1534872be5fcfd9f83e3fdc"><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_a2e6e5192a1534872be5fcfd9f83e3fdc"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_a2e6e5192a1534872be5fcfd9f83e3fdc"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p id="en-us_topic_0000001058830740_en-us_topic_0000001059340528_a8512eda38e25410685be8a8992890257"><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_a8512eda38e25410685be8a8992890257"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_a8512eda38e25410685be8a8992890257"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p id="en-us_topic_0000001058830740_en-us_topic_0000001059340528_p1373057132812"><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_p1373057132812"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_p1373057132812"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="en-us_topic_0000001058830740_en-us_topic_0000001059340528_a11c317cdfa7d4066878d86c6b3bcbd82"><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_a11c317cdfa7d4066878d86c6b3bcbd82"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_a11c317cdfa7d4066878d86c6b3bcbd82"></a>How to divide available space of the parent component for a child component.</p>
<p id="en-us_topic_0000001058830740_en-us_topic_0000001059340528_p6968144051814"><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_p6968144051814"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_p6968144051814"></a>You can set one, two<sup id="en-us_topic_0000001058830740_en-us_topic_0000001059340528_sup894453017315"><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_sup894453017315"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_sup894453017315"></a>5+</sup>, or three<sup id="en-us_topic_0000001058830740_en-us_topic_0000001059340528_sup1255142393114"><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_sup1255142393114"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_sup1255142393114"></a>5+</sup> values for this style.</p>
<p id="en-us_topic_0000001058830740_en-us_topic_0000001059340528_p16733313171911"><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_p16733313171911"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_p16733313171911"></a>Set one value in either of the following ways:</p>
<a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_ul93371539192211"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_ul93371539192211"></a><ul id="en-us_topic_0000001058830740_en-us_topic_0000001059340528_ul93371539192211"><li>A unitless number to set <strong id="en-us_topic_0000001058830740_en-us_topic_0000001059340528_b152581117781"><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_b152581117781"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_b152581117781"></a>flex-grow</strong>.</li><li>A valid width value<sup id="en-us_topic_0000001058830740_en-us_topic_0000001059340528_sup133014373318"><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_sup133014373318"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_sup133014373318"></a>5+</sup> to set <strong id="en-us_topic_0000001058830740_en-us_topic_0000001059340528_b182101331199"><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_b182101331199"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_b182101331199"></a>flex-basis</strong>.</li></ul>
<p id="en-us_topic_0000001058830740_en-us_topic_0000001059340528_p6786171632018"><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_p6786171632018"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_p6786171632018"></a>Set two values<sup id="en-us_topic_0000001058830740_en-us_topic_0000001059340528_sup39514502313"><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_sup39514502313"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_sup39514502313"></a>5+</sup> in the following ways:</p>
<p id="en-us_topic_0000001058830740_en-us_topic_0000001059340528_p6400429122011"><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_p6400429122011"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_p6400429122011"></a>The first value must be a unitless number used to set <strong id="en-us_topic_0000001058830740_en-us_topic_0000001059340528_b171516283129"><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_b171516283129"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_b171516283129"></a>flex-grow</strong>. The second value must be either of the following:</p>
<a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_ul767043502219"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_ul767043502219"></a><ul id="en-us_topic_0000001058830740_en-us_topic_0000001059340528_ul767043502219"><li>A unitless number to set <strong id="en-us_topic_0000001058830740_en-us_topic_0000001059340528_b1428375141313"><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_b1428375141313"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_b1428375141313"></a>flex-shrink</strong>.</li><li>A valid width value to set <strong id="en-us_topic_0000001058830740_en-us_topic_0000001059340528_b1632495651416"><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_b1632495651416"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_b1632495651416"></a>flex-basis</strong>.</li></ul>
<p id="en-us_topic_0000001058830740_en-us_topic_0000001059340528_p748416351217"><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_p748416351217"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_p748416351217"></a>Set three values<sup id="en-us_topic_0000001058830740_en-us_topic_0000001059340528_sup168671312151514"><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_sup168671312151514"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_sup168671312151514"></a>5+</sup> in the following ways:</p>
<p id="en-us_topic_0000001058830740_en-us_topic_0000001059340528_p7373204832111"><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_p7373204832111"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_p7373204832111"></a>The first value must be a unitless number used to set <strong id="en-us_topic_0000001058830740_en-us_topic_0000001059340528_b19419131221612"><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_b19419131221612"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_b19419131221612"></a>flex-grow</strong>. The second value must be a unitless number used to set <strong id="en-us_topic_0000001058830740_en-us_topic_0000001059340528_b19378733181612"><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_b19378733181612"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_b19378733181612"></a>flex-shrink</strong>. The third value must be a valid width value used to set <strong id="en-us_topic_0000001058830740_en-us_topic_0000001059340528_b47717118176"><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_b47717118176"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_b47717118176"></a>flex-basis</strong>.</p>
<div class="note" id="en-us_topic_0000001058830740_en-us_topic_0000001059340528_note34891253201520"><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_note34891253201520"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_note34891253201520"></a><span class="notetitle"> NOTE: </span><div class="notebody"><p id="en-us_topic_0000001058830740_en-us_topic_0000001059340528_p1248915538152"><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_p1248915538152"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_p1248915538152"></a>This style takes effect only when the container is any of the following components: <strong id="en-us_topic_0000001058830740_en-us_topic_0000001059340528_b17156153131"><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_b17156153131"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_b17156153131"></a>&lt;div&gt;</strong>, <strong id="en-us_topic_0000001058830740_en-us_topic_0000001059340528_b1201415151311"><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_b1201415151311"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_b1201415151311"></a>&lt;list-item&gt;</strong>, <strong id="en-us_topic_0000001058830740_en-us_topic_0000001059340528_b72031515132"><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_b72031515132"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_b72031515132"></a>&lt;refresh&gt;</strong>, <strong id="en-us_topic_0000001058830740_en-us_topic_0000001059340528_b1920131551310"><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_b1920131551310"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_b1920131551310"></a>&lt;stepper-item&gt;</strong><sup id="en-us_topic_0000001058830740_en-us_topic_0000001059340528_sup17201815121317"><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_sup17201815121317"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_sup17201815121317"></a>5+</sup>, and <strong id="en-us_topic_0000001058830740_en-us_topic_0000001059340528_b2211915121313"><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_b2211915121313"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_b2211915121313"></a>&lt;tabs&gt;</strong>.</p>
</div></div>
</td>
</tr>
<tr id="en-us_topic_0000001058830740_row13450138205418"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="en-us_topic_0000001058830740_en-us_topic_0000001059340528_a5d88cacaaf5c4f6a87390ab916b695c6"><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_a5d88cacaaf5c4f6a87390ab916b695c6"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_a5d88cacaaf5c4f6a87390ab916b695c6"></a>flex-grow</p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p id="en-us_topic_0000001058830740_en-us_topic_0000001059340528_a2c379e3af283446da446f1631e572efd"><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_a2c379e3af283446da446f1631e572efd"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_a2c379e3af283446da446f1631e572efd"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p id="en-us_topic_0000001058830740_en-us_topic_0000001059340528_aa374f6c7415a4ee48a06930d76c55be7"><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_aa374f6c7415a4ee48a06930d76c55be7"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_aa374f6c7415a4ee48a06930d76c55be7"></a>0</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p id="en-us_topic_0000001058830740_p81768178466"><a name="en-us_topic_0000001058830740_p81768178466"></a><a name="en-us_topic_0000001058830740_p81768178466"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="en-us_topic_0000001058830740_en-us_topic_0000001059340528_p4437122419557"><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_p4437122419557"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_p4437122419557"></a>How much a child component will grow. The value specifies allocation of the remaining space on the main axis of the parent component. Size of available space = Container size - Total size of all child components. Value <strong id="en-us_topic_0000001058830740_en-us_topic_0000001059340528_b1682343583716"><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_b1682343583716"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_b1682343583716"></a>0</strong> indicates that the child component does not grow.</p>
<div class="note" id="en-us_topic_0000001058830740_en-us_topic_0000001059340528_note201231734212"><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_note201231734212"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_note201231734212"></a><span class="notetitle"> NOTE: </span><div class="notebody"><p id="en-us_topic_0000001058830740_en-us_topic_0000001059340528_p184555314553"><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_p184555314553"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_p184555314553"></a>This style takes effect only when the container is any of the following components: <strong id="en-us_topic_0000001058830740_en-us_topic_0000001059340528_b18575165615499"><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_b18575165615499"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_b18575165615499"></a>&lt;div&gt;</strong>, <strong id="en-us_topic_0000001058830740_en-us_topic_0000001059340528_b8575165618495"><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_b8575165618495"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_b8575165618495"></a>&lt;list-item&gt;</strong>, <strong id="en-us_topic_0000001058830740_en-us_topic_0000001059340528_b125751756164917"><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_b125751756164917"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_b125751756164917"></a>&lt;refresh&gt;</strong>, <strong id="en-us_topic_0000001058830740_en-us_topic_0000001059340528_b15751456104920"><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_b15751456104920"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_b15751456104920"></a>&lt;stepper-item&gt;</strong><sup id="en-us_topic_0000001058830740_en-us_topic_0000001059340528_sup257595611492"><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_sup257595611492"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_sup257595611492"></a>5+</sup>, and <strong id="en-us_topic_0000001058830740_en-us_topic_0000001059340528_b55761856114912"><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_b55761856114912"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_b55761856114912"></a>&lt;tabs&gt;</strong>.</p>
</div></div>
</td>
</tr>
<tr id="en-us_topic_0000001058830740_row845016384549"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="en-us_topic_0000001058830740_en-us_topic_0000001059340528_ac65ef7e2b1f24a13b09c495f643168c9"><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_ac65ef7e2b1f24a13b09c495f643168c9"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_ac65ef7e2b1f24a13b09c495f643168c9"></a>flex-shrink</p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p id="en-us_topic_0000001058830740_en-us_topic_0000001059340528_a98e7d367f0e649699892ae5bad6ade37"><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_a98e7d367f0e649699892ae5bad6ade37"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_a98e7d367f0e649699892ae5bad6ade37"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p id="en-us_topic_0000001058830740_en-us_topic_0000001059340528_a422d978368814d12a33201cb839060ee"><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_a422d978368814d12a33201cb839060ee"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_a422d978368814d12a33201cb839060ee"></a>1</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p id="en-us_topic_0000001058830740_p1917613178465"><a name="en-us_topic_0000001058830740_p1917613178465"></a><a name="en-us_topic_0000001058830740_p1917613178465"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="en-us_topic_0000001058830740_en-us_topic_0000001059340528_ab032342dfe56460ca742800de482ca0f"><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_ab032342dfe56460ca742800de482ca0f"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_ab032342dfe56460ca742800de482ca0f"></a>How much a child component will shrink. The shrink occurs only when the sum of default child component widths is greater than that of the parent component. Value <strong id="en-us_topic_0000001058830740_en-us_topic_0000001059340528_b783242395"><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_b783242395"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_b783242395"></a>0</strong> indicates that the child component does not shrink.</p>
<div class="note" id="en-us_topic_0000001058830740_en-us_topic_0000001059340528_note147160917217"><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_note147160917217"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_note147160917217"></a><span class="notetitle"> NOTE: </span><div class="notebody"><p id="en-us_topic_0000001058830740_en-us_topic_0000001059340528_p844914328577"><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_p844914328577"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_p844914328577"></a>This style takes effect only when the container is any of the following components: <strong id="en-us_topic_0000001058830740_en-us_topic_0000001059340528_b1168212543127"><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_b1168212543127"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_b1168212543127"></a>&lt;div&gt;</strong>, <strong id="en-us_topic_0000001058830740_en-us_topic_0000001059340528_b76821454121211"><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_b76821454121211"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_b76821454121211"></a>&lt;list-item&gt;</strong>, <strong id="en-us_topic_0000001058830740_en-us_topic_0000001059340528_b1168255411126"><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_b1168255411126"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_b1168255411126"></a>&lt;refresh&gt;</strong>, <strong id="en-us_topic_0000001058830740_en-us_topic_0000001059340528_b10682155415120"><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_b10682155415120"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_b10682155415120"></a>&lt;stepper-item&gt;</strong><sup id="en-us_topic_0000001058830740_en-us_topic_0000001059340528_sup10683145491215"><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_sup10683145491215"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_sup10683145491215"></a>5+</sup>, and <strong id="en-us_topic_0000001058830740_en-us_topic_0000001059340528_b1868385461211"><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_b1868385461211"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_b1868385461211"></a>&lt;tabs&gt;</strong>.</p>
</div></div>
</td>
</tr>
<tr id="en-us_topic_0000001058830740_row144511738195411"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="en-us_topic_0000001058830740_en-us_topic_0000001059340528_a82c323a994634032963169eeee1a55e4"><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_a82c323a994634032963169eeee1a55e4"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_a82c323a994634032963169eeee1a55e4"></a>flex-basis</p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p id="en-us_topic_0000001058830740_en-us_topic_0000001059340528_p1148910787"><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_p1148910787"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_p1148910787"></a>&lt;length&gt;</p>
<p id="en-us_topic_0000001058830740_en-us_topic_0000001059340528_a43613cf0c2184c0d8b44e8d292f6edb7"><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_a43613cf0c2184c0d8b44e8d292f6edb7"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_a43613cf0c2184c0d8b44e8d292f6edb7"></a></p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p id="en-us_topic_0000001058830740_en-us_topic_0000001059340528_ab9e1c7dc25f840e58993af05c1d32109"><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_ab9e1c7dc25f840e58993af05c1d32109"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_ab9e1c7dc25f840e58993af05c1d32109"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p id="en-us_topic_0000001058830740_p0176817154612"><a name="en-us_topic_0000001058830740_p0176817154612"></a><a name="en-us_topic_0000001058830740_p0176817154612"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="en-us_topic_0000001058830740_en-us_topic_0000001059340528_a0993ef9b0ef64785a76e6310dd834f09"><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_a0993ef9b0ef64785a76e6310dd834f09"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_a0993ef9b0ef64785a76e6310dd834f09"></a>Initial length of the flex item on the main axis.</p>
<div class="note" id="en-us_topic_0000001058830740_en-us_topic_0000001059340528_note62848141222"><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_note62848141222"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_note62848141222"></a><span class="notetitle"> NOTE: </span><div class="notebody"><p id="en-us_topic_0000001058830740_en-us_topic_0000001059340528_p16711745115718"><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_p16711745115718"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_p16711745115718"></a>This style takes effect only when the container is any of the following components: <strong id="en-us_topic_0000001058830740_en-us_topic_0000001059340528_b18795155631219"><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_b18795155631219"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_b18795155631219"></a>&lt;div&gt;</strong>, <strong id="en-us_topic_0000001058830740_en-us_topic_0000001059340528_b107951056121217"><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_b107951056121217"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_b107951056121217"></a>&lt;list-item&gt;</strong>, <strong id="en-us_topic_0000001058830740_en-us_topic_0000001059340528_b2795105619128"><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_b2795105619128"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_b2795105619128"></a>&lt;refresh&gt;</strong>, <strong id="en-us_topic_0000001058830740_en-us_topic_0000001059340528_b1579510564126"><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_b1579510564126"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_b1579510564126"></a>&lt;stepper-item&gt;</strong><sup id="en-us_topic_0000001058830740_en-us_topic_0000001059340528_sup187953565122"><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_sup187953565122"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_sup187953565122"></a>5+</sup>, and <strong id="en-us_topic_0000001058830740_en-us_topic_0000001059340528_b11796456201211"><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_b11796456201211"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_b11796456201211"></a>&lt;tabs&gt;</strong>.</p>
</div></div>
</td>
</tr>
<tr id="en-us_topic_0000001058830740_row184519384544"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="en-us_topic_0000001058830740_en-us_topic_0000001059340528_a50180d720a374549ae72c848e53320cb"><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_a50180d720a374549ae72c848e53320cb"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_a50180d720a374549ae72c848e53320cb"></a>position</p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p id="en-us_topic_0000001058830740_en-us_topic_0000001059340528_a63672ed9a4c040f7a6ec9c8089b79bb6"><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_a63672ed9a4c040f7a6ec9c8089b79bb6"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_a63672ed9a4c040f7a6ec9c8089b79bb6"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p id="en-us_topic_0000001058830740_en-us_topic_0000001059340528_a2666820c71eb420485e4d20e55b4eabe"><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_a2666820c71eb420485e4d20e55b4eabe"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_a2666820c71eb420485e4d20e55b4eabe"></a>relative</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p id="en-us_topic_0000001058830740_en-us_topic_0000001059340528_p1173107172814"><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_p1173107172814"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_p1173107172814"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="en-us_topic_0000001058830740_en-us_topic_0000001059340528_ae28abf4e47a740efbd45a8f280577912"><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_ae28abf4e47a740efbd45a8f280577912"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_ae28abf4e47a740efbd45a8f280577912"></a>Positioning type of an element. Dynamic changes are not supported.</p>
<a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_ul17185232185014"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_ul17185232185014"></a><ul id="en-us_topic_0000001058830740_en-us_topic_0000001059340528_ul17185232185014"><li><strong id="en-us_topic_0000001058830740_en-us_topic_0000001059340528_b1894911155394"><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_b1894911155394"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_b1894911155394"></a>fixed</strong>: The element is positioned related to the browser window.</li><li><strong id="en-us_topic_0000001058830740_en-us_topic_0000001059340528_b823115152390"><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_b823115152390"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_b823115152390"></a>absolute</strong>: The element is positioned absolutely to its parent element.</li><li><strong id="en-us_topic_0000001058830740_en-us_topic_0000001059340528_b736151417395"><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_b736151417395"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_b736151417395"></a>relative</strong>: The element is positioned relative to its normal position.</li></ul>
<div class="note" id="en-us_topic_0000001058830740_en-us_topic_0000001059340528_note167617191219"><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_note167617191219"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_note167617191219"></a><span class="notetitle"> NOTE: </span><div class="notebody"><p id="en-us_topic_0000001058830740_en-us_topic_0000001059340528_p1839092815101"><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_p1839092815101"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_p1839092815101"></a>The <strong id="en-us_topic_0000001058830740_en-us_topic_0000001059340528_b13941713133910"><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_b13941713133910"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_b13941713133910"></a>absolute</strong> attribute takes effect only when the parent component is <strong id="en-us_topic_0000001058830740_en-us_topic_0000001059340528_b1099913173916"><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_b1099913173916"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_b1099913173916"></a>&lt;div&gt;</strong> or <strong id="en-us_topic_0000001058830740_en-us_topic_0000001059340528_b181001413123919"><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_b181001413123919"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_b181001413123919"></a>&lt;stack&gt;</strong>.</p>
</div></div>
</td>
</tr>
<tr id="en-us_topic_0000001058830740_row1545123811547"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="en-us_topic_0000001058830740_en-us_topic_0000001059340528_a70405cb9696b4329ac7625af93310018"><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_a70405cb9696b4329ac7625af93310018"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_a70405cb9696b4329ac7625af93310018"></a>[left|top<span id="en-us_topic_0000001058830740_en-us_topic_0000001059340528_ph14927143614712"><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_ph14927143614712"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_ph14927143614712"></a>|right|bottom</span>]</p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p id="en-us_topic_0000001058830740_en-us_topic_0000001059340528_p1849062221214"><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_p1849062221214"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_p1849062221214"></a>&lt;length&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p id="en-us_topic_0000001058830740_en-us_topic_0000001059340528_a579ac7c03d1d46758ebaacd565d86ed3"><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_a579ac7c03d1d46758ebaacd565d86ed3"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_a579ac7c03d1d46758ebaacd565d86ed3"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p id="en-us_topic_0000001058830740_en-us_topic_0000001059340528_p187314719288"><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_p187314719288"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_p187314719288"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="en-us_topic_0000001058830740_en-us_topic_0000001059340528_a9a662a62cd9b40eaa0cb9ca082b6d1c2"><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_a9a662a62cd9b40eaa0cb9ca082b6d1c2"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_a9a662a62cd9b40eaa0cb9ca082b6d1c2"></a><strong id="en-us_topic_0000001058830740_en-us_topic_0000001059340528_b481348173914"><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_b481348173914"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_b481348173914"></a>left|top</strong><span id="en-us_topic_0000001058830740_en-us_topic_0000001059340528_ph4818118173914"><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_ph4818118173914"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_ph4818118173914"></a><strong id="en-us_topic_0000001058830740_en-us_topic_0000001059340528_b68143833912"><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_b68143833912"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_b68143833912"></a>|right|bottom</strong></span> must be used together with <strong id="en-us_topic_0000001058830740_en-us_topic_0000001059340528_b881916818394"><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_b881916818394"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_b881916818394"></a>position</strong> to determine the offset position of an element.</p>
<a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_ul12671003525"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_ul12671003525"></a><ul id="en-us_topic_0000001058830740_en-us_topic_0000001059340528_ul12671003525"><li>The <strong id="en-us_topic_0000001058830740_en-us_topic_0000001059340528_b885117712398"><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_b885117712398"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_b885117712398"></a>left</strong> attribute specifies the left edge position of the element. This attribute defines the offset between the left edge of a positioned element and that of a block included in the element.</li><li>The <strong id="en-us_topic_0000001058830740_en-us_topic_0000001059340528_b65591759395"><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_b65591759395"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_b65591759395"></a>top</strong> attribute specifies the top edge position of the element. This attribute defines the offset between the top edge of a positioned element and that of a block included in the element.</li><li>The <strong id="en-us_topic_0000001058830740_en-us_topic_0000001059340528_b179013323910"><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_b179013323910"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_b179013323910"></a>right</strong> attribute specifies the right edge position of the element. This attribute defines the offset between the right edge of a positioned element and that of a block included in the element. </li><li>The <strong id="en-us_topic_0000001058830740_en-us_topic_0000001059340528_b77091602397"><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_b77091602397"></a><a name="en-us_topic_0000001058830740_en-us_topic_0000001059340528_b77091602397"></a>bottom</strong> attribute specifies the bottom edge position of the element. This attribute defines the offset between the bottom edge of a positioned element and that of a block included in the element. </li></ul>
</td>
</tr>
</tbody>
</table>

## Method<a name="en-us_topic_0000001058830740_section1428810433566"></a>

<a name="en-us_topic_0000001058830740_ta27ae6832ab647a880ab27801368ec17"></a>
<table><thead align="left"><tr id="en-us_topic_0000001058830740_r00746cc3f4244fd7bf405d1640b42842"><th class="cellrowborder" valign="top" width="10.89%" id="mcps1.1.4.1.1"><p id="en-us_topic_0000001058830740_a6853bf471a534d9185a46033e5301a3c"><a name="en-us_topic_0000001058830740_a6853bf471a534d9185a46033e5301a3c"></a><a name="en-us_topic_0000001058830740_a6853bf471a534d9185a46033e5301a3c"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="10.9%" id="mcps1.1.4.1.2"><p id="en-us_topic_0000001058830740_a2f6b46265ccd412b8be977c934e2e06e"><a name="en-us_topic_0000001058830740_a2f6b46265ccd412b8be977c934e2e06e"></a><a name="en-us_topic_0000001058830740_a2f6b46265ccd412b8be977c934e2e06e"></a>Parameter</p>
</th>
<th class="cellrowborder" valign="top" width="78.21000000000001%" id="mcps1.1.4.1.3"><p id="en-us_topic_0000001058830740_ab97e815e4f734c4290f4f7cb608e45d4"><a name="en-us_topic_0000001058830740_ab97e815e4f734c4290f4f7cb608e45d4"></a><a name="en-us_topic_0000001058830740_ab97e815e4f734c4290f4f7cb608e45d4"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="en-us_topic_0000001058830740_rfd984b5dab4c419fb56fb95b53614076"><td class="cellrowborder" valign="top" width="10.89%" headers="mcps1.1.4.1.1 "><p id="en-us_topic_0000001058830740_a650170fd03b64d42894295d360ad74dd"><a name="en-us_topic_0000001058830740_a650170fd03b64d42894295d360ad74dd"></a><a name="en-us_topic_0000001058830740_a650170fd03b64d42894295d360ad74dd"></a>start</p>
</td>
<td class="cellrowborder" valign="top" width="10.9%" headers="mcps1.1.4.1.2 "><p id="en-us_topic_0000001058830740_a634a82d9b27a449891db2c1e04622259"><a name="en-us_topic_0000001058830740_a634a82d9b27a449891db2c1e04622259"></a><a name="en-us_topic_0000001058830740_a634a82d9b27a449891db2c1e04622259"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="78.21000000000001%" headers="mcps1.1.4.1.3 "><p id="en-us_topic_0000001058830740_a8ab976e5b8344f9b9849843a5b30128a"><a name="en-us_topic_0000001058830740_a8ab976e5b8344f9b9849843a5b30128a"></a><a name="en-us_topic_0000001058830740_a8ab976e5b8344f9b9849843a5b30128a"></a>Starts to play the frame animation of an image. If this method is called again, the playback starts from the first frame.</p>
</td>
</tr>
<tr id="en-us_topic_0000001058830740_r15b7a1086fd047ea984b9cb4955dd98c"><td class="cellrowborder" valign="top" width="10.89%" headers="mcps1.1.4.1.1 "><p id="en-us_topic_0000001058830740_aab35a49bf5d440958734b6b30ae5c129"><a name="en-us_topic_0000001058830740_aab35a49bf5d440958734b6b30ae5c129"></a><a name="en-us_topic_0000001058830740_aab35a49bf5d440958734b6b30ae5c129"></a>pause</p>
</td>
<td class="cellrowborder" valign="top" width="10.9%" headers="mcps1.1.4.1.2 "><p id="en-us_topic_0000001058830740_aaf270b3435ba4d1ba5c038066d3d08a8"><a name="en-us_topic_0000001058830740_aaf270b3435ba4d1ba5c038066d3d08a8"></a><a name="en-us_topic_0000001058830740_aaf270b3435ba4d1ba5c038066d3d08a8"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="78.21000000000001%" headers="mcps1.1.4.1.3 "><p id="en-us_topic_0000001058830740_a4ea339c3428f474696fe3491579ac922"><a name="en-us_topic_0000001058830740_a4ea339c3428f474696fe3491579ac922"></a><a name="en-us_topic_0000001058830740_a4ea339c3428f474696fe3491579ac922"></a>Pauses the frame animation playback of an image.</p>
</td>
</tr>
<tr id="en-us_topic_0000001058830740_row2389173613484"><td class="cellrowborder" valign="top" width="10.89%" headers="mcps1.1.4.1.1 "><p id="en-us_topic_0000001058830740_p183906365481"><a name="en-us_topic_0000001058830740_p183906365481"></a><a name="en-us_topic_0000001058830740_p183906365481"></a>stop</p>
</td>
<td class="cellrowborder" valign="top" width="10.9%" headers="mcps1.1.4.1.2 "><p id="en-us_topic_0000001058830740_p18390193624812"><a name="en-us_topic_0000001058830740_p18390193624812"></a><a name="en-us_topic_0000001058830740_p18390193624812"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="78.21000000000001%" headers="mcps1.1.4.1.3 "><p id="en-us_topic_0000001058830740_p18390136184810"><a name="en-us_topic_0000001058830740_p18390136184810"></a><a name="en-us_topic_0000001058830740_p18390136184810"></a>Stops the frame animation playback of an image.</p>
</td>
</tr>
<tr id="en-us_topic_0000001058830740_row2051494718486"><td class="cellrowborder" valign="top" width="10.89%" headers="mcps1.1.4.1.1 "><p id="en-us_topic_0000001058830740_p16514124764810"><a name="en-us_topic_0000001058830740_p16514124764810"></a><a name="en-us_topic_0000001058830740_p16514124764810"></a>resume</p>
</td>
<td class="cellrowborder" valign="top" width="10.9%" headers="mcps1.1.4.1.2 "><p id="en-us_topic_0000001058830740_p16515144764811"><a name="en-us_topic_0000001058830740_p16515144764811"></a><a name="en-us_topic_0000001058830740_p16515144764811"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="78.21000000000001%" headers="mcps1.1.4.1.3 "><p id="en-us_topic_0000001058830740_p18515847164812"><a name="en-us_topic_0000001058830740_p18515847164812"></a><a name="en-us_topic_0000001058830740_p18515847164812"></a>Resumes the frame animation playback of an image.</p>
</td>
</tr>
<tr id="en-us_topic_0000001058830740_row16356183618265"><td class="cellrowborder" valign="top" width="10.89%" headers="mcps1.1.4.1.1 "><p id="en-us_topic_0000001058830740_p53572364269"><a name="en-us_topic_0000001058830740_p53572364269"></a><a name="en-us_topic_0000001058830740_p53572364269"></a>getState</p>
</td>
<td class="cellrowborder" valign="top" width="10.9%" headers="mcps1.1.4.1.2 "><p id="en-us_topic_0000001058830740_p835743613261"><a name="en-us_topic_0000001058830740_p835743613261"></a><a name="en-us_topic_0000001058830740_p835743613261"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="78.21000000000001%" headers="mcps1.1.4.1.3 "><p id="en-us_topic_0000001058830740_p5357183632618"><a name="en-us_topic_0000001058830740_p5357183632618"></a><a name="en-us_topic_0000001058830740_p5357183632618"></a>Obtains the playback state. Available values are as follows:</p>
<a name="en-us_topic_0000001058830740_ul1465819221205"></a><a name="en-us_topic_0000001058830740_ul1465819221205"></a><ul id="en-us_topic_0000001058830740_ul1465819221205"><li>Playing</li><li>Paused</li><li>Stopped</li></ul>
</td>
</tr>
</tbody>
</table>

## Example<a name="en-us_topic_0000001058830740_section118221913375"></a>

```
<!-- xxx.hml -->
<div class="container">
  <image-animator class="animator" ref="animator" images="{{frames}}" duration="1s" />
  <div class="btn-box">
    <input class="btn" type="button" value="start" @click="handleStart" />
    <input class="btn" type="button" value="stop" @click="handleStop" />
    <input class="btn" type="button" value="pause" @click="handlePause" />
    <input class="btn" type="button" value="resume" @click="handleResume" />
  </div>
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
.animator {
  width: 70px;
  height: 70px;
}
.btn-box {
  width: 264px;
  height: 120px;
  flex-wrap: wrap;
  justify-content: space-around;
  align-items: center;
}
.btn {
  border-radius: 8px;
  width: 120px;
  margin-top: 8px;
}
```

```
//xxx.js
export default {
  data: {
    frames: [
      {
        src: "/common/asserts/heart78.png",
      },
      {
        src: "/common/asserts/heart79.png",
      },
      {
        src: "/common/asserts/heart80.png",
      },
      {
        src: "/common/asserts/heart81.png",
      },
      {
        src: "/common/asserts/heart82.png",
      },
      {
        src: "/common/asserts/heart83.png",
      },
      {
        src: "/common/asserts/heart84.png",
      },
      {
        src: "/common/asserts/heart85.png",
      },
      {
        src: "/common/asserts/heart86.png",
      },
      {
        src: "/common/asserts/heart87.png",
      },
      {
        src: "/common/asserts/heart88.png",
      },
      {
        src: "/common/asserts/heart89.png",
      },
      {
        src: "/common/asserts/heart90.png",
      },
      {
        src: "/common/asserts/heart91.png",
      },
      {
        src: "/common/asserts/heart92.png",
      },
      {
        src: "/common/asserts/heart93.png",
      },
      {
        src: "/common/asserts/heart94.png",
      },
      {
        src: "/common/asserts/heart95.png",
      },
      {
        src: "/common/asserts/heart96.png",
      },
    ],
  },
  handleStart() {
    this.$refs.animator.start();
  },
  handlePause() {
    this.$refs.animator.pause();
  },
  handleResume() {
    this.$refs.animator.resume();
  },
  handleStop() {
    this.$refs.animator.stop();
  },
};
```

![](figures/image-animator.gif)

