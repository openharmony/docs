# image-animator<a name="EN-US_TOPIC_0000001173324625"></a>

The  **<image-animator\>**  component is used to provide an image frame animator.

## Child Component<a name="section393521619565"></a>

Not supported

## Attribute<a name="section1342212415618"></a>

In addition to the attributes in  [Universal Attributes](js-components-common-attributes.md), the following attributes are supported.

<a name="table20633101642315"></a>
<table><thead align="left"><tr id="row663331618238"><th class="cellrowborder" valign="top" width="23.119999999999997%" id="mcps1.1.6.1.1"><p id="aa872998ac2d84843a3c5161889afffef"><a name="aa872998ac2d84843a3c5161889afffef"></a><a name="aa872998ac2d84843a3c5161889afffef"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="23.119999999999997%" id="mcps1.1.6.1.2"><p id="ab2111648ee0e4f6d881be8954e7acaab"><a name="ab2111648ee0e4f6d881be8954e7acaab"></a><a name="ab2111648ee0e4f6d881be8954e7acaab"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="10.48%" id="mcps1.1.6.1.3"><p id="ab377d1c90900478ea4ecab51e9a058af"><a name="ab377d1c90900478ea4ecab51e9a058af"></a><a name="ab377d1c90900478ea4ecab51e9a058af"></a>Default Value</p>
</th>
<th class="cellrowborder" valign="top" width="7.5200000000000005%" id="mcps1.1.6.1.4"><p id="p824610360217"><a name="p824610360217"></a><a name="p824610360217"></a>Mandatory</p>
</th>
<th class="cellrowborder" valign="top" width="35.76%" id="mcps1.1.6.1.5"><p id="a1d574a0044ed42ec8a2603bc82734232"><a name="a1d574a0044ed42ec8a2603bc82734232"></a><a name="a1d574a0044ed42ec8a2603bc82734232"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row6678114174919"><td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.1 "><p id="p425710265496"><a name="p425710265496"></a><a name="p425710265496"></a>images</p>
</td>
<td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.2 "><p id="p1257142694916"><a name="p1257142694916"></a><a name="p1257142694916"></a>Array&lt;ImageFrame&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="10.48%" headers="mcps1.1.6.1.3 "><p id="p1725752654912"><a name="p1725752654912"></a><a name="p1725752654912"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.6.1.4 "><p id="p1025752610497"><a name="p1025752610497"></a><a name="p1025752610497"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="35.76%" headers="mcps1.1.6.1.5 "><p id="p1225732612491"><a name="p1225732612491"></a><a name="p1225732612491"></a>Image frame information. The frame information includes the image path, size, and location. Currently, the following image formats are supported: PNG and JPG. For details about <strong id="b1451343442511"><a name="b1451343442511"></a><a name="b1451343442511"></a>ImageFrame</strong>, see <a href="#table67453165913">Table 1</a>.</p>
<div class="note" id="note1925732612497"><a name="note1925732612497"></a><a name="note1925732612497"></a><span class="notetitle"> NOTE: </span><div class="notebody"><p id="p3257226184915"><a name="p3257226184915"></a><a name="p3257226184915"></a>Set this attribute using data binding, for example, <strong id="b3644923191911"><a name="b3644923191911"></a><a name="b3644923191911"></a>images = {{images}}</strong>. Declare the corresponding variable <strong id="b3583125942516"><a name="b3583125942516"></a><a name="b3583125942516"></a>images: [{src: "/common/heart-rate01.png"}, {src: "/common/heart-rate02.png"}]</strong> in the JavaScript.</p>
<p id="p205711340134919"><a name="p205711340134919"></a><a name="p205711340134919"></a>Declare the variable <strong id="b152638162228"><a name="b152638162228"></a><a name="b152638162228"></a>images: [{src: "/common/heart-rate01.png", duration: "100"}, {src: "/common/heart-rate02.png", duration: "200"}]</strong> in the JavaScript. You can set the duration (in milliseconds) of each image frame. <sup id="sup1083881410267"><a name="sup1083881410267"></a><a name="sup1083881410267"></a>6+</sup></p>
</div></div>
</td>
</tr>
<tr id="row2926174817528"><td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.1 "><p id="p1292784811523"><a name="p1292784811523"></a><a name="p1292784811523"></a>predecode<sup id="sup31371043122616"><a name="sup31371043122616"></a><a name="sup31371043122616"></a>6+</sup></p>
</td>
<td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.2 "><p id="p292713488521"><a name="p292713488521"></a><a name="p292713488521"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="10.48%" headers="mcps1.1.6.1.3 "><p id="p9927134812527"><a name="p9927134812527"></a><a name="p9927134812527"></a>0</p>
</td>
<td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.6.1.4 "><p id="p14927134818521"><a name="p14927134818521"></a><a name="p14927134818521"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="35.76%" headers="mcps1.1.6.1.5 "><p id="p792704825216"><a name="p792704825216"></a><a name="p792704825216"></a>Whether to enable pre-decoding. The default value is 0, indicating that pre-decoding is disabled. If this parameter is set to 2, the last two images are loaded to the cache in advance to improve the performance when the current page is played.</p>
</td>
</tr>
<tr id="row739819164910"><td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.1 "><p id="p16257626134912"><a name="p16257626134912"></a><a name="p16257626134912"></a>iteration</p>
</td>
<td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.2 "><p id="p18257112611492"><a name="p18257112611492"></a><a name="p18257112611492"></a>number | string</p>
</td>
<td class="cellrowborder" valign="top" width="10.48%" headers="mcps1.1.6.1.3 "><p id="p22571126184915"><a name="p22571126184915"></a><a name="p22571126184915"></a>infinite</p>
</td>
<td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.6.1.4 "><p id="p14257202694917"><a name="p14257202694917"></a><a name="p14257202694917"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="35.76%" headers="mcps1.1.6.1.5 "><p id="p22571326114916"><a name="p22571326114916"></a><a name="p22571326114916"></a>Number of times that the frame animation is played. <strong id="b20158158192210"><a name="b20158158192210"></a><a name="b20158158192210"></a>number</strong> indicates a fixed number of playback operations, and <strong id="b1272110157230"><a name="b1272110157230"></a><a name="b1272110157230"></a>infinite</strong> indicates an unlimited number of playback operations.</p>
</td>
</tr>
<tr id="row163991791492"><td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.1 "><p id="p12576265493"><a name="p12576265493"></a><a name="p12576265493"></a>reverse</p>
</td>
<td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.2 "><p id="p15257826194918"><a name="p15257826194918"></a><a name="p15257826194918"></a>boolean</p>
</td>
<td class="cellrowborder" valign="top" width="10.48%" headers="mcps1.1.6.1.3 "><p id="p122573263499"><a name="p122573263499"></a><a name="p122573263499"></a>false</p>
</td>
<td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.6.1.4 "><p id="p12571626134910"><a name="p12571626134910"></a><a name="p12571626134910"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="35.76%" headers="mcps1.1.6.1.5 "><p id="p925816262499"><a name="p925816262499"></a><a name="p925816262499"></a>Playback sequence. The value <strong id="b67459152416"><a name="b67459152416"></a><a name="b67459152416"></a>false</strong> indicates that images are played from the first one to the last one, and <strong id="b175171216307"><a name="b175171216307"></a><a name="b175171216307"></a>true</strong> indicates that images are played from the last one to the first one.</p>
</td>
</tr>
<tr id="row320318310493"><td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.1 "><p id="p425862611491"><a name="p425862611491"></a><a name="p425862611491"></a>fixedsize</p>
</td>
<td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.2 "><p id="p3258182604914"><a name="p3258182604914"></a><a name="p3258182604914"></a>boolean</p>
</td>
<td class="cellrowborder" valign="top" width="10.48%" headers="mcps1.1.6.1.3 "><p id="p1425852684910"><a name="p1425852684910"></a><a name="p1425852684910"></a>true</p>
</td>
<td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.6.1.4 "><p id="p625862612497"><a name="p625862612497"></a><a name="p625862612497"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="35.76%" headers="mcps1.1.6.1.5 "><p id="p7258626174910"><a name="p7258626174910"></a><a name="p7258626174910"></a>Whether the image size is fixed to the widget size. <strong id="b919917296321"><a name="b919917296321"></a><a name="b919917296321"></a>true</strong>: The image size is the same as the widget size. In this case, the width, height, top, and left attributes of the image are invalid. <strong id="b89251240113218"><a name="b89251240113218"></a><a name="b89251240113218"></a>false</strong>: The width, height, top, and left attributes of each image must be set separately.</p>
</td>
</tr>
<tr id="row168157599487"><td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.1 "><p id="p15258152613494"><a name="p15258152613494"></a><a name="p15258152613494"></a>duration</p>
</td>
<td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.2 "><p id="p8258102610496"><a name="p8258102610496"></a><a name="p8258102610496"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="10.48%" headers="mcps1.1.6.1.3 "><p id="p9258112654910"><a name="p9258112654910"></a><a name="p9258112654910"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.6.1.4 "><p id="p1225814262495"><a name="p1225814262495"></a><a name="p1225814262495"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="35.76%" headers="mcps1.1.6.1.5 "><p id="p9258102684910"><a name="p9258102684910"></a><a name="p9258102684910"></a>Single video playback duration. The unit can be s (standing for seconds) or ms. The default unit is ms. If the value is <strong id="b165541819123316"><a name="b165541819123316"></a><a name="b165541819123316"></a>0</strong>, no image is played. The value change takes effect only at the start of the next cycle. If image-specific durations have been set, the settings of this attribute do not take effect.</p>
</td>
</tr>
<tr id="row15460155375910"><td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.1 "><p id="p204611353105915"><a name="p204611353105915"></a><a name="p204611353105915"></a>fillmode<sup id="sup4224194014312"><a name="sup4224194014312"></a><a name="sup4224194014312"></a>5+</sup></p>
</td>
<td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.2 "><p id="p1461125318597"><a name="p1461125318597"></a><a name="p1461125318597"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="10.48%" headers="mcps1.1.6.1.3 "><p id="p11461155311592"><a name="p11461155311592"></a><a name="p11461155311592"></a>forwards</p>
</td>
<td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.6.1.4 "><p id="p3461135316592"><a name="p3461135316592"></a><a name="p3461135316592"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="35.76%" headers="mcps1.1.6.1.5 "><p id="p48661353174"><a name="p48661353174"></a><a name="p48661353174"></a>Status of the frame animation after its playback is complete. Available values are as follows:</p>
<a name="ul183656592213"></a><a name="ul183656592213"></a><ul id="ul183656592213"><li><strong id="b4108122744120"><a name="b4108122744120"></a><a name="b4108122744120"></a>none</strong>: Restores to the initial status.</li><li><strong id="b8540732144117"><a name="b8540732144117"></a><a name="b8540732144117"></a>forwards</strong>: Retains the ending status defined for the last key frame.</li></ul>
</td>
</tr>
</tbody>
</table>

**Table  1**  ImageFrame description

<a name="table67453165913"></a>
<table><thead align="left"><tr id="row127451816696"><th class="cellrowborder" valign="top" width="11.330000000000002%" id="mcps1.2.6.1.1"><p id="p20745516799"><a name="p20745516799"></a><a name="p20745516799"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="9.860000000000001%" id="mcps1.2.6.1.2"><p id="p6745181616919"><a name="p6745181616919"></a><a name="p6745181616919"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="10.810000000000002%" id="mcps1.2.6.1.3"><p id="p27452161915"><a name="p27452161915"></a><a name="p27452161915"></a>Default Value</p>
</th>
<th class="cellrowborder" valign="top" width="10.000000000000002%" id="mcps1.2.6.1.4"><p id="p187461164918"><a name="p187461164918"></a><a name="p187461164918"></a>Mandatory</p>
</th>
<th class="cellrowborder" valign="top" width="58.00000000000001%" id="mcps1.2.6.1.5"><p id="p174651611917"><a name="p174651611917"></a><a name="p174651611917"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row974611615915"><td class="cellrowborder" valign="top" width="11.330000000000002%" headers="mcps1.2.6.1.1 "><p id="p27461616392"><a name="p27461616392"></a><a name="p27461616392"></a>src</p>
</td>
<td class="cellrowborder" valign="top" width="9.860000000000001%" headers="mcps1.2.6.1.2 "><p id="p1874612161194"><a name="p1874612161194"></a><a name="p1874612161194"></a>&lt;uri&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="10.810000000000002%" headers="mcps1.2.6.1.3 "><p id="p167462161197"><a name="p167462161197"></a><a name="p167462161197"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="10.000000000000002%" headers="mcps1.2.6.1.4 "><p id="p674612161914"><a name="p674612161914"></a><a name="p674612161914"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="58.00000000000001%" headers="mcps1.2.6.1.5 "><p id="p87460161592"><a name="p87460161592"></a><a name="p87460161592"></a>Image path.<span id="ph5230045184011"><a name="ph5230045184011"></a><a name="ph5230045184011"></a> The image format can be SVG, PNG, or JPG.</span></p>
</td>
</tr>
<tr id="row1574611161790"><td class="cellrowborder" valign="top" width="11.330000000000002%" headers="mcps1.2.6.1.1 "><p id="p1674621619911"><a name="p1674621619911"></a><a name="p1674621619911"></a>width</p>
</td>
<td class="cellrowborder" valign="top" width="9.860000000000001%" headers="mcps1.2.6.1.2 "><p id="p4746516691"><a name="p4746516691"></a><a name="p4746516691"></a>&lt;length&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="10.810000000000002%" headers="mcps1.2.6.1.3 "><p id="p1874661618915"><a name="p1874661618915"></a><a name="p1874661618915"></a>0</p>
</td>
<td class="cellrowborder" valign="top" width="10.000000000000002%" headers="mcps1.2.6.1.4 "><p id="p13746161615914"><a name="p13746161615914"></a><a name="p13746161615914"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="58.00000000000001%" headers="mcps1.2.6.1.5 "><p id="p57461162915"><a name="p57461162915"></a><a name="p57461162915"></a>Image width</p>
</td>
</tr>
<tr id="row1746131615914"><td class="cellrowborder" valign="top" width="11.330000000000002%" headers="mcps1.2.6.1.1 "><p id="p137467160910"><a name="p137467160910"></a><a name="p137467160910"></a>height</p>
</td>
<td class="cellrowborder" valign="top" width="9.860000000000001%" headers="mcps1.2.6.1.2 "><p id="p12285145181014"><a name="p12285145181014"></a><a name="p12285145181014"></a>&lt;length&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="10.810000000000002%" headers="mcps1.2.6.1.3 "><p id="p3285144571012"><a name="p3285144571012"></a><a name="p3285144571012"></a>0</p>
</td>
<td class="cellrowborder" valign="top" width="10.000000000000002%" headers="mcps1.2.6.1.4 "><p id="p728514520106"><a name="p728514520106"></a><a name="p728514520106"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="58.00000000000001%" headers="mcps1.2.6.1.5 "><p id="p1174619161998"><a name="p1174619161998"></a><a name="p1174619161998"></a>Image height</p>
</td>
</tr>
<tr id="row157461216990"><td class="cellrowborder" valign="top" width="11.330000000000002%" headers="mcps1.2.6.1.1 "><p id="p157461916297"><a name="p157461916297"></a><a name="p157461916297"></a>top</p>
</td>
<td class="cellrowborder" valign="top" width="9.860000000000001%" headers="mcps1.2.6.1.2 "><p id="p172301247131019"><a name="p172301247131019"></a><a name="p172301247131019"></a>&lt;length&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="10.810000000000002%" headers="mcps1.2.6.1.3 "><p id="p152301647141015"><a name="p152301647141015"></a><a name="p152301647141015"></a>0</p>
</td>
<td class="cellrowborder" valign="top" width="10.000000000000002%" headers="mcps1.2.6.1.4 "><p id="p15230164731016"><a name="p15230164731016"></a><a name="p15230164731016"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="58.00000000000001%" headers="mcps1.2.6.1.5 "><p id="p11863511151119"><a name="p11863511151119"></a><a name="p11863511151119"></a>Vertical coordinate of the image relative to the upper left corner of the widget</p>
</td>
</tr>
<tr id="row107477161396"><td class="cellrowborder" valign="top" width="11.330000000000002%" headers="mcps1.2.6.1.1 "><p id="p57474161995"><a name="p57474161995"></a><a name="p57474161995"></a>left</p>
</td>
<td class="cellrowborder" valign="top" width="9.860000000000001%" headers="mcps1.2.6.1.2 "><p id="p317644961019"><a name="p317644961019"></a><a name="p317644961019"></a>&lt;length&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="10.810000000000002%" headers="mcps1.2.6.1.3 "><p id="p19176154951014"><a name="p19176154951014"></a><a name="p19176154951014"></a>0</p>
</td>
<td class="cellrowborder" valign="top" width="10.000000000000002%" headers="mcps1.2.6.1.4 "><p id="p1176049201020"><a name="p1176049201020"></a><a name="p1176049201020"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="58.00000000000001%" headers="mcps1.2.6.1.5 "><p id="p191151321151111"><a name="p191151321151111"></a><a name="p191151321151111"></a>Horizontal coordinate of the image relative to the upper left corner of the widget</p>
</td>
</tr>
<tr id="row243510340595"><td class="cellrowborder" valign="top" width="11.330000000000002%" headers="mcps1.2.6.1.1 "><p id="p1643633417593"><a name="p1643633417593"></a><a name="p1643633417593"></a>duration<sup id="sup10707409460"><a name="sup10707409460"></a><a name="sup10707409460"></a>6+</sup></p>
</td>
<td class="cellrowborder" valign="top" width="9.860000000000001%" headers="mcps1.2.6.1.2 "><p id="p1643620340595"><a name="p1643620340595"></a><a name="p1643620340595"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="10.810000000000002%" headers="mcps1.2.6.1.3 "><p id="p14436133455910"><a name="p14436133455910"></a><a name="p14436133455910"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="10.000000000000002%" headers="mcps1.2.6.1.4 "><p id="p5436134145916"><a name="p5436134145916"></a><a name="p5436134145916"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="58.00000000000001%" headers="mcps1.2.6.1.5 "><p id="p743613347596"><a name="p743613347596"></a><a name="p743613347596"></a>Playback duration of each image frame, in milliseconds.</p>
</td>
</tr>
</tbody>
</table>

## Style<a name="section1774719169253"></a>

Styles in  [Universal Styles](js-components-common-styles.md)  are supported.

## Event<a name="section17969351566"></a>

In addition to the events in  [Universal Events](js-components-common-events.md), the following events are supported.

<a name="table836435619510"></a>
<table><thead align="left"><tr id="row153658563517"><th class="cellrowborder" valign="top" width="24.852485248524854%" id="mcps1.1.4.1.1"><p id="a426b8903842d48fa8012a24ff3c997eb"><a name="a426b8903842d48fa8012a24ff3c997eb"></a><a name="a426b8903842d48fa8012a24ff3c997eb"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="29.552955295529554%" id="mcps1.1.4.1.2"><p id="a53448ba47e5e4ae9bf7774c90820e970"><a name="a53448ba47e5e4ae9bf7774c90820e970"></a><a name="a53448ba47e5e4ae9bf7774c90820e970"></a>Parameter</p>
</th>
<th class="cellrowborder" valign="top" width="45.5945594559456%" id="mcps1.1.4.1.3"><p id="add489ff50c444f24b759162c7f4bad9a"><a name="add489ff50c444f24b759162c7f4bad9a"></a><a name="add489ff50c444f24b759162c7f4bad9a"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row287217513517"><td class="cellrowborder" valign="top" width="24.852485248524854%" headers="mcps1.1.4.1.1 "><p id="p2602207165111"><a name="p2602207165111"></a><a name="p2602207165111"></a>start</p>
</td>
<td class="cellrowborder" valign="top" width="29.552955295529554%" headers="mcps1.1.4.1.2 "><p id="p19602157185119"><a name="p19602157185119"></a><a name="p19602157185119"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="45.5945594559456%" headers="mcps1.1.4.1.3 "><p id="p146021079518"><a name="p146021079518"></a><a name="p146021079518"></a>Triggered when the frame animation starts</p>
</td>
</tr>
<tr id="row0878102155118"><td class="cellrowborder" valign="top" width="24.852485248524854%" headers="mcps1.1.4.1.1 "><p id="p1760237135118"><a name="p1760237135118"></a><a name="p1760237135118"></a>pause</p>
</td>
<td class="cellrowborder" valign="top" width="29.552955295529554%" headers="mcps1.1.4.1.2 "><p id="p160214745113"><a name="p160214745113"></a><a name="p160214745113"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="45.5945594559456%" headers="mcps1.1.4.1.3 "><p id="p26027715112"><a name="p26027715112"></a><a name="p26027715112"></a>Triggered when the frame animation pauses</p>
</td>
</tr>
<tr id="row151519594509"><td class="cellrowborder" valign="top" width="24.852485248524854%" headers="mcps1.1.4.1.1 "><p id="p86027735118"><a name="p86027735118"></a><a name="p86027735118"></a>stop</p>
</td>
<td class="cellrowborder" valign="top" width="29.552955295529554%" headers="mcps1.1.4.1.2 "><p id="p196024715513"><a name="p196024715513"></a><a name="p196024715513"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="45.5945594559456%" headers="mcps1.1.4.1.3 "><p id="p760216735110"><a name="p760216735110"></a><a name="p760216735110"></a>Triggered when the frame animation stops</p>
</td>
</tr>
<tr id="row189025517507"><td class="cellrowborder" valign="top" width="24.852485248524854%" headers="mcps1.1.4.1.1 "><p id="p4602147175120"><a name="p4602147175120"></a><a name="p4602147175120"></a>resume </p>
</td>
<td class="cellrowborder" valign="top" width="29.552955295529554%" headers="mcps1.1.4.1.2 "><p id="p12602137155110"><a name="p12602137155110"></a><a name="p12602137155110"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="45.5945594559456%" headers="mcps1.1.4.1.3 "><p id="p160267105114"><a name="p160267105114"></a><a name="p160267105114"></a>Triggered when the frame animation resumes</p>
</td>
</tr>
</tbody>
</table>

## Method<a name="section1428810433566"></a>

In addition to the methods in  [Universal Methods](js-components-common-methods.md), the following events are supported.

<a name="ta27ae6832ab647a880ab27801368ec17"></a>
<table><thead align="left"><tr id="r00746cc3f4244fd7bf405d1640b42842"><th class="cellrowborder" valign="top" width="10.89%" id="mcps1.1.4.1.1"><p id="a6853bf471a534d9185a46033e5301a3c"><a name="a6853bf471a534d9185a46033e5301a3c"></a><a name="a6853bf471a534d9185a46033e5301a3c"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="10.9%" id="mcps1.1.4.1.2"><p id="a2f6b46265ccd412b8be977c934e2e06e"><a name="a2f6b46265ccd412b8be977c934e2e06e"></a><a name="a2f6b46265ccd412b8be977c934e2e06e"></a>Parameter</p>
</th>
<th class="cellrowborder" valign="top" width="78.21000000000001%" id="mcps1.1.4.1.3"><p id="ab97e815e4f734c4290f4f7cb608e45d4"><a name="ab97e815e4f734c4290f4f7cb608e45d4"></a><a name="ab97e815e4f734c4290f4f7cb608e45d4"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="rfd984b5dab4c419fb56fb95b53614076"><td class="cellrowborder" valign="top" width="10.89%" headers="mcps1.1.4.1.1 "><p id="a650170fd03b64d42894295d360ad74dd"><a name="a650170fd03b64d42894295d360ad74dd"></a><a name="a650170fd03b64d42894295d360ad74dd"></a>start</p>
</td>
<td class="cellrowborder" valign="top" width="10.9%" headers="mcps1.1.4.1.2 "><p id="a634a82d9b27a449891db2c1e04622259"><a name="a634a82d9b27a449891db2c1e04622259"></a><a name="a634a82d9b27a449891db2c1e04622259"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="78.21000000000001%" headers="mcps1.1.4.1.3 "><p id="a8ab976e5b8344f9b9849843a5b30128a"><a name="a8ab976e5b8344f9b9849843a5b30128a"></a><a name="a8ab976e5b8344f9b9849843a5b30128a"></a>Starts to play the frame animation of an image. If this method is called again, the playback starts from the first frame.</p>
</td>
</tr>
<tr id="r15b7a1086fd047ea984b9cb4955dd98c"><td class="cellrowborder" valign="top" width="10.89%" headers="mcps1.1.4.1.1 "><p id="aab35a49bf5d440958734b6b30ae5c129"><a name="aab35a49bf5d440958734b6b30ae5c129"></a><a name="aab35a49bf5d440958734b6b30ae5c129"></a>pause</p>
</td>
<td class="cellrowborder" valign="top" width="10.9%" headers="mcps1.1.4.1.2 "><p id="aaf270b3435ba4d1ba5c038066d3d08a8"><a name="aaf270b3435ba4d1ba5c038066d3d08a8"></a><a name="aaf270b3435ba4d1ba5c038066d3d08a8"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="78.21000000000001%" headers="mcps1.1.4.1.3 "><p id="a4ea339c3428f474696fe3491579ac922"><a name="a4ea339c3428f474696fe3491579ac922"></a><a name="a4ea339c3428f474696fe3491579ac922"></a>Pauses the frame animation playback of an image.</p>
</td>
</tr>
<tr id="row2389173613484"><td class="cellrowborder" valign="top" width="10.89%" headers="mcps1.1.4.1.1 "><p id="p183906365481"><a name="p183906365481"></a><a name="p183906365481"></a>stop</p>
</td>
<td class="cellrowborder" valign="top" width="10.9%" headers="mcps1.1.4.1.2 "><p id="p18390193624812"><a name="p18390193624812"></a><a name="p18390193624812"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="78.21000000000001%" headers="mcps1.1.4.1.3 "><p id="p18390136184810"><a name="p18390136184810"></a><a name="p18390136184810"></a>Stops the frame animation playback of an image.</p>
</td>
</tr>
<tr id="row2051494718486"><td class="cellrowborder" valign="top" width="10.89%" headers="mcps1.1.4.1.1 "><p id="p16514124764810"><a name="p16514124764810"></a><a name="p16514124764810"></a>resume</p>
</td>
<td class="cellrowborder" valign="top" width="10.9%" headers="mcps1.1.4.1.2 "><p id="p16515144764811"><a name="p16515144764811"></a><a name="p16515144764811"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="78.21000000000001%" headers="mcps1.1.4.1.3 "><p id="p18515847164812"><a name="p18515847164812"></a><a name="p18515847164812"></a>Resumes the frame animation playback of an image.</p>
</td>
</tr>
<tr id="row16356183618265"><td class="cellrowborder" valign="top" width="10.89%" headers="mcps1.1.4.1.1 "><p id="p53572364269"><a name="p53572364269"></a><a name="p53572364269"></a>getState</p>
</td>
<td class="cellrowborder" valign="top" width="10.9%" headers="mcps1.1.4.1.2 "><p id="p835743613261"><a name="p835743613261"></a><a name="p835743613261"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="78.21000000000001%" headers="mcps1.1.4.1.3 "><p id="p5357183632618"><a name="p5357183632618"></a><a name="p5357183632618"></a>Obtains the playback state. Available values are as follows:</p>
<a name="ul1465819221205"></a><a name="ul1465819221205"></a><ul id="ul1465819221205"><li>Playing</li><li>Paused</li><li>Stopped</li></ul>
</td>
</tr>
</tbody>
</table>

## Example Code<a name="section118221913375"></a>

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

