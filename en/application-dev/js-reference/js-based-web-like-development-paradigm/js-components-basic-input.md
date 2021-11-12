# input<a name="EN-US_TOPIC_0000001173324647"></a>

The  **<input\>**  component provides an interactive interface to receive user input. It can be a radio button, check box, button, single-line text box, and more.

## Permission List<a name="section11257113618419"></a>

None

## Child Component<a name="section9288143101012"></a>

Not supported

## Attribute<a name="section2907183951110"></a>

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
<th class="cellrowborder" valign="top" width="35.76%" id="mcps1.1.6.1.5"><p id="a1d574a0044ed42ec8a2603bc82734232"><a name="a1d574a0044ed42ec8a2603bc82734232"></a><a name="a1d574a0044ed42ec8a2603bc82734232"></a>Triggered when</p>
</th>
</tr>
</thead>
<tbody><tr id="row634417439274"><td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.1 "><p id="p72442555275"><a name="p72442555275"></a><a name="p72442555275"></a>type</p>
</td>
<td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.2 "><p id="p324455511276"><a name="p324455511276"></a><a name="p324455511276"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="10.48%" headers="mcps1.1.6.1.3 "><p id="p16244055182716"><a name="p16244055182716"></a><a name="p16244055182716"></a>text</p>
</td>
<td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.6.1.4 "><p id="p3244155102714"><a name="p3244155102714"></a><a name="p3244155102714"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="35.76%" headers="mcps1.1.6.1.5 "><p id="p924475517275"><a name="p924475517275"></a><a name="p924475517275"></a>Type of the input component. Available values include <span id="ph15675399414"><a name="ph15675399414"></a><a name="ph15675399414"></a><strong id="b83541911123611"><a name="b83541911123611"></a><a name="b83541911123611"></a>text</strong>, <strong id="b156006161365"><a name="b156006161365"></a><a name="b156006161365"></a>email</strong>, <strong id="b1389319187364"><a name="b1389319187364"></a><a name="b1389319187364"></a>date</strong>, <strong id="b17253623133610"><a name="b17253623133610"></a><a name="b17253623133610"></a>time</strong>, <strong id="b694311245368"><a name="b694311245368"></a><a name="b694311245368"></a>number</strong>, <strong id="b8826192763614"><a name="b8826192763614"></a><a name="b8826192763614"></a>password</strong>, </span><strong id="b157607296367"><a name="b157607296367"></a><a name="b157607296367"></a>button</strong>, <strong id="b192811231193612"><a name="b192811231193612"></a><a name="b192811231193612"></a>checkbox</strong>, and <strong id="b39501932123616"><a name="b39501932123616"></a><a name="b39501932123616"></a>radio</strong>.</p>
<p id="p1524485513274"><a name="p1524485513274"></a><a name="p1524485513274"></a>The <strong id="b59971579367"><a name="b59971579367"></a><a name="b59971579367"></a>text</strong>, <strong id="b412925983614"><a name="b412925983614"></a><a name="b412925983614"></a>email</strong>, <strong id="b42617014378"><a name="b42617014378"></a><a name="b42617014378"></a>date</strong>, <strong id="b1395915173720"><a name="b1395915173720"></a><a name="b1395915173720"></a>time</strong>, <strong id="b11407333711"><a name="b11407333711"></a><a name="b11407333711"></a>number</strong>, and <strong id="b12487347379"><a name="b12487347379"></a><a name="b12487347379"></a>password</strong> types can be dynamically switched and modified. </p>
<p id="p17244175532712"><a name="p17244175532712"></a><a name="p17244175532712"></a>The <strong id="b66701121123710"><a name="b66701121123710"></a><a name="b66701121123710"></a>button</strong>, <strong id="b1772519228379"><a name="b1772519228379"></a><a name="b1772519228379"></a>checkbox</strong>, and <strong id="b3750102423713"><a name="b3750102423713"></a><a name="b3750102423713"></a>radio</strong> types cannot be dynamically modified. Available values include:</p>
<a name="ul324417555275"></a><a name="ul324417555275"></a><ul id="ul324417555275"><li><strong id="b312413331652"><a name="b312413331652"></a><a name="b312413331652"></a>button</strong>: a button that can be clicked</li><li><strong id="b203263812249"><a name="b203263812249"></a><a name="b203263812249"></a>checkbox</strong>: a check box</li><li><strong id="b8292121938"><a name="b8292121938"></a><a name="b8292121938"></a>radio</strong>: a radio button that allows users to select one from multiple others with the same name</li><li><strong id="b166864913293"><a name="b166864913293"></a><a name="b166864913293"></a>text</strong>: a single-line text field</li><li><strong id="b18160637657"><a name="b18160637657"></a><a name="b18160637657"></a>email</strong>: a field used for an email address</li><li><strong id="b161243814516"><a name="b161243814516"></a><a name="b161243814516"></a>date</strong>: date control, including the year, month, and day, but excluding time</li><li><strong id="b1644983911514"><a name="b1644983911514"></a><a name="b1644983911514"></a>time</strong>: time control, without the time zone</li><li><strong id="b5368840559"><a name="b5368840559"></a><a name="b5368840559"></a>number</strong>: field for entering digits</li><li><strong id="b362814111511"><a name="b362814111511"></a><a name="b362814111511"></a>password</strong>: password field, in which characters will be shielded<div class="note" id="note45664136102"><a name="note45664136102"></a><a name="note45664136102"></a><span class="notetitle"> NOTE: </span><div class="notebody"><p id="p1551717289101"><a name="p1551717289101"></a><a name="p1551717289101"></a>For wearables, only <strong id="b21340211936"><a name="b21340211936"></a><a name="b21340211936"></a>button</strong>, <strong id="b14107223132"><a name="b14107223132"></a><a name="b14107223132"></a>radio</strong>, and <strong id="b1093818254310"><a name="b1093818254310"></a><a name="b1093818254310"></a>checkbox</strong> types are supported.</p>
</div></div>
</li></ul>
</td>
</tr>
<tr id="row43454437272"><td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.1 "><p id="p5245185582713"><a name="p5245185582713"></a><a name="p5245185582713"></a>checked</p>
</td>
<td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.2 "><p id="p202456551277"><a name="p202456551277"></a><a name="p202456551277"></a>boolean</p>
</td>
<td class="cellrowborder" valign="top" width="10.48%" headers="mcps1.1.6.1.3 "><p id="p1245165520272"><a name="p1245165520272"></a><a name="p1245165520272"></a>false</p>
</td>
<td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.6.1.4 "><p id="p6245855172718"><a name="p6245855172718"></a><a name="p6245855172718"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="35.76%" headers="mcps1.1.6.1.5 "><p id="p12245115512279"><a name="p12245115512279"></a><a name="p12245115512279"></a>Whether the <strong id="b142024206232"><a name="b142024206232"></a><a name="b142024206232"></a>&lt;input&gt;</strong> component is selected. This attribute is valid only when <strong id="b12202112072313"><a name="b12202112072313"></a><a name="b12202112072313"></a>type</strong> is set to <strong id="b16202162042314"><a name="b16202162042314"></a><a name="b16202162042314"></a>checkbox</strong> or <strong id="b202037208232"><a name="b202037208232"></a><a name="b202037208232"></a>radio</strong>.</p>
</td>
</tr>
<tr id="row834544342712"><td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.1 "><p id="p19245855182719"><a name="p19245855182719"></a><a name="p19245855182719"></a>name</p>
</td>
<td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.2 "><p id="p2245955192720"><a name="p2245955192720"></a><a name="p2245955192720"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="10.48%" headers="mcps1.1.6.1.3 "><p id="p14245115502719"><a name="p14245115502719"></a><a name="p14245115502719"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.6.1.4 "><p id="p32451755182718"><a name="p32451755182718"></a><a name="p32451755182718"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="35.76%" headers="mcps1.1.6.1.5 "><p id="p20245135542717"><a name="p20245135542717"></a><a name="p20245135542717"></a>Name of the input component.</p>
</td>
</tr>
<tr id="row18345124342713"><td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.1 "><p id="p0245185592712"><a name="p0245185592712"></a><a name="p0245185592712"></a>value</p>
</td>
<td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.2 "><p id="p1224525518275"><a name="p1224525518275"></a><a name="p1224525518275"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="10.48%" headers="mcps1.1.6.1.3 "><p id="p5245115582715"><a name="p5245115582715"></a><a name="p5245115582715"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.6.1.4 "><p id="p624515512278"><a name="p624515512278"></a><a name="p624515512278"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="35.76%" headers="mcps1.1.6.1.5 "><p id="p0245255112710"><a name="p0245255112710"></a><a name="p0245255112710"></a>Value of the input component. When <strong id="b13677653019"><a name="b13677653019"></a><a name="b13677653019"></a>type</strong> is <strong id="b136511685302"><a name="b136511685302"></a><a name="b136511685302"></a>radio</strong>, this attribute is mandatory and the value must be unique for radio buttons with the same name.</p>
</td>
</tr>
<tr id="row1360803719278"><td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.1 "><p id="p52451955152716"><a name="p52451955152716"></a><a name="p52451955152716"></a>placeholder</p>
</td>
<td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.2 "><p id="p2246135512274"><a name="p2246135512274"></a><a name="p2246135512274"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="10.48%" headers="mcps1.1.6.1.3 "><p id="p12462557277"><a name="p12462557277"></a><a name="p12462557277"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.6.1.4 "><p id="p6246125562716"><a name="p6246125562716"></a><a name="p6246125562716"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="35.76%" headers="mcps1.1.6.1.5 "><p id="p4246205572711"><a name="p4246205572711"></a><a name="p4246205572711"></a>Content of the hint text. This attribute is available only when the component type is set to <strong id="b29081929613"><a name="b29081929613"></a><a name="b29081929613"></a>text</strong>, <strong id="b15573141610"><a name="b15573141610"></a><a name="b15573141610"></a>email</strong>, <strong id="b1367410610620"><a name="b1367410610620"></a><a name="b1367410610620"></a>date</strong>, <strong id="b1258719818618"><a name="b1258719818618"></a><a name="b1258719818618"></a>time</strong>, <strong id="b128485356122"><a name="b128485356122"></a><a name="b128485356122"></a>number</strong>, or <strong id="b1921103313122"><a name="b1921103313122"></a><a name="b1921103313122"></a>password</strong>.</p>
</td>
</tr>
<tr id="row10729734112719"><td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.1 "><p id="p524615562717"><a name="p524615562717"></a><a name="p524615562717"></a>maxlength</p>
</td>
<td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.2 "><p id="p4246165562713"><a name="p4246165562713"></a><a name="p4246165562713"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="10.48%" headers="mcps1.1.6.1.3 "><p id="p1246135522711"><a name="p1246135522711"></a><a name="p1246135522711"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.6.1.4 "><p id="p13246185517271"><a name="p13246185517271"></a><a name="p13246185517271"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="35.76%" headers="mcps1.1.6.1.5 "><p id="p1224635514274"><a name="p1224635514274"></a><a name="p1224635514274"></a>Maximum number of characters that can be entered in the input box. If no value is specified, the number of characters is not limited.</p>
</td>
</tr>
<tr id="row1125513210279"><td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.1 "><p id="p14246125513277"><a name="p14246125513277"></a><a name="p14246125513277"></a>enterkeytype</p>
</td>
<td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.2 "><p id="p7246055112718"><a name="p7246055112718"></a><a name="p7246055112718"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="10.48%" headers="mcps1.1.6.1.3 "><p id="p1324615552276"><a name="p1324615552276"></a><a name="p1324615552276"></a>default</p>
</td>
<td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.6.1.4 "><p id="p10246115514272"><a name="p10246115514272"></a><a name="p10246115514272"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="35.76%" headers="mcps1.1.6.1.5 "><p id="p1824635502717"><a name="p1824635502717"></a><a name="p1824635502717"></a>Dynamic modification is not supported.</p>
<p id="p12246255112712"><a name="p12246255112712"></a><a name="p12246255112712"></a>Available values include:</p>
<a name="ul52461055142716"></a><a name="ul52461055142716"></a><ul id="ul52461055142716"><li>default</li><li>next</li><li>go</li><li>done</li><li>send</li><li>Search</li></ul>
<div class="note" id="note1524765512720"><a name="note1524765512720"></a><a name="note1524765512720"></a><span class="notetitle"> NOTE: </span><div class="notebody"><p id="p124795592715"><a name="p124795592715"></a><a name="p124795592715"></a>The soft keyboard is automatically collapsed after you click the <strong id="b1861043823418"><a name="b1861043823418"></a><a name="b1861043823418"></a>Enter</strong> button, except when <strong id="b2064315920354"><a name="b2064315920354"></a><a name="b2064315920354"></a>next</strong> is displayed for the button.</p>
</div></div>
</td>
</tr>
<tr id="row2461329122714"><td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.1 "><p id="p8247655162711"><a name="p8247655162711"></a><a name="p8247655162711"></a>headericon</p>
</td>
<td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.2 "><p id="p18247145520271"><a name="p18247145520271"></a><a name="p18247145520271"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="10.48%" headers="mcps1.1.6.1.3 "><p id="p824715572713"><a name="p824715572713"></a><a name="p824715572713"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.6.1.4 "><p id="p2247135582717"><a name="p2247135582717"></a><a name="p2247135582717"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="35.76%" headers="mcps1.1.6.1.5 "><p id="p20247755102711"><a name="p20247755102711"></a><a name="p20247755102711"></a>Icon resource path before text input. This icon does not support click events and is unavailable for <strong id="b87532361769"><a name="b87532361769"></a><a name="b87532361769"></a>button</strong>, <strong id="b15753163612613"><a name="b15753163612613"></a><a name="b15753163612613"></a>checkbox</strong>, and <strong id="b17754736663"><a name="b17754736663"></a><a name="b17754736663"></a>radio</strong> types. The supported icon image formats are JPG, PNG, and SVG.</p>
</td>
</tr>
<tr id="row16836876325"><td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.1 "><p id="p983712712329"><a name="p983712712329"></a><a name="p983712712329"></a>showcounter<sup id="sup19271132920334"><a name="sup19271132920334"></a><a name="sup19271132920334"></a>5+</sup></p>
</td>
<td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.2 "><p id="p178371971325"><a name="p178371971325"></a><a name="p178371971325"></a>boolean</p>
</td>
<td class="cellrowborder" valign="top" width="10.48%" headers="mcps1.1.6.1.3 "><p id="p28374743210"><a name="p28374743210"></a><a name="p28374743210"></a>false</p>
</td>
<td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.6.1.4 "><p id="p6837677327"><a name="p6837677327"></a><a name="p6837677327"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="35.76%" headers="mcps1.1.6.1.5 "><p id="p11837472328"><a name="p11837472328"></a><a name="p11837472328"></a>Whether to display the character counter for an input box. This attribute takes effect only when <strong id="b2518112655814"><a name="b2518112655814"></a><a name="b2518112655814"></a>maxlength</strong> is set.</p>
</td>
</tr>
<tr id="row07211971743"><td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.1 "><p id="p177221571244"><a name="p177221571244"></a><a name="p177221571244"></a>menuoptions<sup id="sup154944401542"><a name="sup154944401542"></a><a name="sup154944401542"></a>5+</sup></p>
</td>
<td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.2 "><p id="p8722157248"><a name="p8722157248"></a><a name="p8722157248"></a>Array&lt;<a href="#table83621954963">MenuOption</a>&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="10.48%" headers="mcps1.1.6.1.3 "><p id="p167221878414"><a name="p167221878414"></a><a name="p167221878414"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.6.1.4 "><p id="p197227713411"><a name="p197227713411"></a><a name="p197227713411"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="35.76%" headers="mcps1.1.6.1.5 "><p id="p207221573417"><a name="p207221573417"></a><a name="p207221573417"></a>Menu options displayed after users touch the <strong id="b3847114112495"><a name="b3847114112495"></a><a name="b3847114112495"></a>More</strong> button.</p>
</td>
</tr>
<tr id="row45541828184811"><td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.1 "><p id="p95550281483"><a name="p95550281483"></a><a name="p95550281483"></a>autofocus<sup id="sup1775142235010"><a name="sup1775142235010"></a><a name="sup1775142235010"></a>6+</sup></p>
</td>
<td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.2 "><p id="p1955511286485"><a name="p1955511286485"></a><a name="p1955511286485"></a>boolean</p>
</td>
<td class="cellrowborder" valign="top" width="10.48%" headers="mcps1.1.6.1.3 "><p id="p6555192874812"><a name="p6555192874812"></a><a name="p6555192874812"></a>false</p>
</td>
<td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.6.1.4 "><p id="p3555142844817"><a name="p3555142844817"></a><a name="p3555142844817"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="35.76%" headers="mcps1.1.6.1.5 "><p id="p135551628184820"><a name="p135551628184820"></a><a name="p135551628184820"></a>Whether to automatically obtain the focus.</p>
<div class="note" id="note9175194313116"><a name="note9175194313116"></a><a name="note9175194313116"></a><span class="notetitle"> NOTE: </span><div class="notebody"><p id="p554143517446"><a name="p554143517446"></a><a name="p554143517446"></a>This attribute setting does not take effect on the application home page. You can enable a text box on the home page to automatically obtain focus, by delaying the <strong id="b435318566233"><a name="b435318566233"></a><a name="b435318566233"></a>focus</strong> method call (for about 100–500 ms) in <strong id="b1336020563235"><a name="b1336020563235"></a><a name="b1336020563235"></a>onActive</strong>.</p>
</div></div>
</td>
</tr>
<tr id="row1261993119486"><td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.1 "><p id="p16196311485"><a name="p16196311485"></a><a name="p16196311485"></a>selectedstart<sup id="sup151911922125019"><a name="sup151911922125019"></a><a name="sup151911922125019"></a>6+</sup></p>
</td>
<td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.2 "><p id="p126191631104819"><a name="p126191631104819"></a><a name="p126191631104819"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="10.48%" headers="mcps1.1.6.1.3 "><p id="p7619163110489"><a name="p7619163110489"></a><a name="p7619163110489"></a>-1</p>
</td>
<td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.6.1.4 "><p id="p1619123120488"><a name="p1619123120488"></a><a name="p1619123120488"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="35.76%" headers="mcps1.1.6.1.5 "><p id="p9619113118488"><a name="p9619113118488"></a><a name="p9619113118488"></a>Start position for text selection.</p>
</td>
</tr>
<tr id="row1823083417484"><td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.1 "><p id="p42301334184813"><a name="p42301334184813"></a><a name="p42301334184813"></a>selectedend<sup id="sup759182155017"><a name="sup759182155017"></a><a name="sup759182155017"></a>6+</sup></p>
</td>
<td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.2 "><p id="p1523013444810"><a name="p1523013444810"></a><a name="p1523013444810"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="10.48%" headers="mcps1.1.6.1.3 "><p id="p1823053404815"><a name="p1823053404815"></a><a name="p1823053404815"></a>-1</p>
</td>
<td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.6.1.4 "><p id="p162301434104819"><a name="p162301434104819"></a><a name="p162301434104819"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="35.76%" headers="mcps1.1.6.1.5 "><p id="p2023014344489"><a name="p2023014344489"></a><a name="p2023014344489"></a>End position for text selection.</p>
</td>
</tr>
<tr id="row6428183714485"><td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.1 "><p id="p11428837134811"><a name="p11428837134811"></a><a name="p11428837134811"></a>softkeyboardenabled<sup id="sup135541120205017"><a name="sup135541120205017"></a><a name="sup135541120205017"></a>6+</sup></p>
</td>
<td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.2 "><p id="p18428837114816"><a name="p18428837114816"></a><a name="p18428837114816"></a>boolean</p>
</td>
<td class="cellrowborder" valign="top" width="10.48%" headers="mcps1.1.6.1.3 "><p id="p124281037144812"><a name="p124281037144812"></a><a name="p124281037144812"></a>true</p>
</td>
<td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.6.1.4 "><p id="p842823714486"><a name="p842823714486"></a><a name="p842823714486"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="35.76%" headers="mcps1.1.6.1.5 "><p id="p1642873734813"><a name="p1642873734813"></a><a name="p1642873734813"></a>Whether to display the soft keyboard during editing.</p>
</td>
</tr>
<tr id="row18278391483"><td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.1 "><p id="p10827143911483"><a name="p10827143911483"></a><a name="p10827143911483"></a>showpasswordicon<sup id="sup65401815115011"><a name="sup65401815115011"></a><a name="sup65401815115011"></a>6+</sup></p>
</td>
<td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.2 "><p id="p882719398489"><a name="p882719398489"></a><a name="p882719398489"></a>boolean</p>
</td>
<td class="cellrowborder" valign="top" width="10.48%" headers="mcps1.1.6.1.3 "><p id="p1082753994811"><a name="p1082753994811"></a><a name="p1082753994811"></a>true</p>
</td>
<td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.6.1.4 "><p id="p13827183954817"><a name="p13827183954817"></a><a name="p13827183954817"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="35.76%" headers="mcps1.1.6.1.5 "><p id="p10828939174817"><a name="p10828939174817"></a><a name="p10828939174817"></a>Whether to display the icon at the end of the password text box. The setting is valid only when <strong id="b8922113173716"><a name="b8922113173716"></a><a name="b8922113173716"></a>type</strong> is set to <strong id="b17325183893716"><a name="b17325183893716"></a><a name="b17325183893716"></a>password</strong>.</p>
</td>
</tr>
</tbody>
</table>

**Table  1**  MenuOption<sup>5+</sup>

<a name="table83621954963"></a>
<table><thead align="left"><tr id="row536212545619"><th class="cellrowborder" valign="top" width="33.33333333333333%" id="mcps1.2.4.1.1"><p id="p143621541967"><a name="p143621541967"></a><a name="p143621541967"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="33.33333333333333%" id="mcps1.2.4.1.2"><p id="p936215541620"><a name="p936215541620"></a><a name="p936215541620"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="33.33333333333333%" id="mcps1.2.4.1.3"><p id="p23626541665"><a name="p23626541665"></a><a name="p23626541665"></a>Triggered when</p>
</th>
</tr>
</thead>
<tbody><tr id="row5362254461"><td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.1 "><p id="p33631541265"><a name="p33631541265"></a><a name="p33631541265"></a>icon</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.2 "><p id="p536311543619"><a name="p536311543619"></a><a name="p536311543619"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.3 "><p id="p73631954762"><a name="p73631954762"></a><a name="p73631954762"></a>Path of the icon for a menu option.</p>
</td>
</tr>
<tr id="row136319547613"><td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.1 "><p id="p12363654367"><a name="p12363654367"></a><a name="p12363654367"></a>content</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.2 "><p id="p1936312549617"><a name="p1936312549617"></a><a name="p1936312549617"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.3 "><p id="p1036311548616"><a name="p1036311548616"></a><a name="p1036311548616"></a>Text content of a menu option.</p>
</td>
</tr>
</tbody>
</table>

## Style<a name="section066012492913"></a>

In addition to the styles in  [Universal Styles](js-components-common-styles.md), the following styles are supported.

<a name="table168129500519"></a>
<table><thead align="left"><tr id="row3812115020515"><th class="cellrowborder" valign="top" width="23.11768823117688%" id="mcps1.1.6.1.1"><p id="p178128502053"><a name="p178128502053"></a><a name="p178128502053"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="20.537946205379463%" id="mcps1.1.6.1.2"><p id="p781295016511"><a name="p781295016511"></a><a name="p781295016511"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="22.757724227577242%" id="mcps1.1.6.1.3"><p id="p178126501150"><a name="p178126501150"></a><a name="p178126501150"></a>Default Value</p>
</th>
<th class="cellrowborder" valign="top" width="7.58924107589241%" id="mcps1.1.6.1.4"><p id="p19812950754"><a name="p19812950754"></a><a name="p19812950754"></a>Mandatory</p>
</th>
<th class="cellrowborder" valign="top" width="25.997400259974%" id="mcps1.1.6.1.5"><p id="p381218501456"><a name="p381218501456"></a><a name="p381218501456"></a>Triggered when</p>
</th>
</tr>
</thead>
<tbody><tr id="row581317501655"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="p12813750459"><a name="p12813750459"></a><a name="p12813750459"></a>color</p>
</td>
<td class="cellrowborder" valign="top" width="20.537946205379463%" headers="mcps1.1.6.1.2 "><p id="p148132501751"><a name="p148132501751"></a><a name="p148132501751"></a>&lt;color&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="22.757724227577242%" headers="mcps1.1.6.1.3 "><p id="p16813350256"><a name="p16813350256"></a><a name="p16813350256"></a>#e6000000</p>
</td>
<td class="cellrowborder" valign="top" width="7.58924107589241%" headers="mcps1.1.6.1.4 "><p id="p1481311501514"><a name="p1481311501514"></a><a name="p1481311501514"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="25.997400259974%" headers="mcps1.1.6.1.5 "><p id="p138135501758"><a name="p138135501758"></a><a name="p138135501758"></a>Font color of the single-line text box or button.</p>
</td>
</tr>
<tr id="row13813175013515"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="p118131250153"><a name="p118131250153"></a><a name="p118131250153"></a>font-size</p>
</td>
<td class="cellrowborder" valign="top" width="20.537946205379463%" headers="mcps1.1.6.1.2 "><p id="p19813155013512"><a name="p19813155013512"></a><a name="p19813155013512"></a>&lt;length&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="22.757724227577242%" headers="mcps1.1.6.1.3 "><p id="p88134501155"><a name="p88134501155"></a><a name="p88134501155"></a>16px</p>
</td>
<td class="cellrowborder" valign="top" width="7.58924107589241%" headers="mcps1.1.6.1.4 "><p id="p381305019519"><a name="p381305019519"></a><a name="p381305019519"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="25.997400259974%" headers="mcps1.1.6.1.5 "><p id="p148131050253"><a name="p148131050253"></a><a name="p148131050253"></a>Font size of the single-line text box or button. </p>
</td>
</tr>
<tr id="row481312502519"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="p3813050954"><a name="p3813050954"></a><a name="p3813050954"></a>allow-scale</p>
</td>
<td class="cellrowborder" valign="top" width="20.537946205379463%" headers="mcps1.1.6.1.2 "><p id="p138139503518"><a name="p138139503518"></a><a name="p138139503518"></a>boolean</p>
</td>
<td class="cellrowborder" valign="top" width="22.757724227577242%" headers="mcps1.1.6.1.3 "><p id="p181455012517"><a name="p181455012517"></a><a name="p181455012517"></a>true</p>
</td>
<td class="cellrowborder" valign="top" width="7.58924107589241%" headers="mcps1.1.6.1.4 "><p id="p8814145015518"><a name="p8814145015518"></a><a name="p8814145015518"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="25.997400259974%" headers="mcps1.1.6.1.5 "><p id="p12814195013511"><a name="p12814195013511"></a><a name="p12814195013511"></a>Whether the font size changes with the system's font size settings.</p>
<div class="note" id="note1781416501358"><a name="note1781416501358"></a><a name="note1781416501358"></a><span class="notetitle"> NOTE: </span><div class="notebody"><p id="p13814145011511"><a name="p13814145011511"></a><a name="p13814145011511"></a>If the <strong id="b524714361237"><a name="b524714361237"></a><a name="b524714361237"></a>config-changes</strong> tag of <strong id="b19256136236"><a name="b19256136236"></a><a name="b19256136236"></a>fontSize</strong> is configured for abilities in the <strong id="b32576360318"><a name="b32576360318"></a><a name="b32576360318"></a>config.json</strong> file, the setting takes effect without application restart.</p>
</div></div>
</td>
</tr>
<tr id="row781413506518"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="p581410501158"><a name="p581410501158"></a><a name="p581410501158"></a>placeholder-color</p>
</td>
<td class="cellrowborder" valign="top" width="20.537946205379463%" headers="mcps1.1.6.1.2 "><p id="p1781419501555"><a name="p1781419501555"></a><a name="p1781419501555"></a>&lt;color&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="22.757724227577242%" headers="mcps1.1.6.1.3 "><p id="p4814450854"><a name="p4814450854"></a><a name="p4814450854"></a>#99000000</p>
</td>
<td class="cellrowborder" valign="top" width="7.58924107589241%" headers="mcps1.1.6.1.4 "><p id="p12814350357"><a name="p12814350357"></a><a name="p12814350357"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="25.997400259974%" headers="mcps1.1.6.1.5 "><p id="p138140501751"><a name="p138140501751"></a><a name="p138140501751"></a>Color of the hint text in the single-line text box. This attribute is available when the component type is set to <strong id="b1165245531811"><a name="b1165245531811"></a><a name="b1165245531811"></a>text</strong>, <strong id="b7887185781818"><a name="b7887185781818"></a><a name="b7887185781818"></a>email</strong>, <strong id="b662675991816"><a name="b662675991816"></a><a name="b662675991816"></a>date</strong>, <strong id="b104879121919"><a name="b104879121919"></a><a name="b104879121919"></a>time</strong>, <strong id="b936871841920"><a name="b936871841920"></a><a name="b936871841920"></a>number</strong>, or <strong id="b6737912171919"><a name="b6737912171919"></a><a name="b6737912171919"></a>password</strong>.</p>
</td>
</tr>
<tr id="row58141650752"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="p1381435012518"><a name="p1381435012518"></a><a name="p1381435012518"></a>font-weight</p>
</td>
<td class="cellrowborder" valign="top" width="20.537946205379463%" headers="mcps1.1.6.1.2 "><p id="p98141250450"><a name="p98141250450"></a><a name="p98141250450"></a>number | string</p>
</td>
<td class="cellrowborder" valign="top" width="22.757724227577242%" headers="mcps1.1.6.1.3 "><p id="p198141507512"><a name="p198141507512"></a><a name="p198141507512"></a>normal</p>
</td>
<td class="cellrowborder" valign="top" width="7.58924107589241%" headers="mcps1.1.6.1.4 "><p id="p20814185015510"><a name="p20814185015510"></a><a name="p20814185015510"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="25.997400259974%" headers="mcps1.1.6.1.5 "><p id="p1281455014516"><a name="p1281455014516"></a><a name="p1281455014516"></a>Font weight of the single-line text box or button. For details, see <a href="js-components-basic-text.md#section5775351116">font-weight</a> of the <strong id="b131111751153712"><a name="b131111751153712"></a><a name="b131111751153712"></a>text</strong> component.</p>
</td>
</tr>
<tr id="row1167411433019"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="p18674104193019"><a name="p18674104193019"></a><a name="p18674104193019"></a>caret-color<sup id="sup628114393018"><a name="sup628114393018"></a><a name="sup628114393018"></a>6+</sup></p>
</td>
<td class="cellrowborder" valign="top" width="20.537946205379463%" headers="mcps1.1.6.1.2 "><p id="p13674194173010"><a name="p13674194173010"></a><a name="p13674194173010"></a>&lt;color&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="22.757724227577242%" headers="mcps1.1.6.1.3 "><p id="p12674164113010"><a name="p12674164113010"></a><a name="p12674164113010"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.58924107589241%" headers="mcps1.1.6.1.4 "><p id="p5674114183020"><a name="p5674114183020"></a><a name="p5674114183020"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="25.997400259974%" headers="mcps1.1.6.1.5 "><p id="p18674134153015"><a name="p18674134153015"></a><a name="p18674134153015"></a>Color of the input cursor.</p>
</td>
</tr>
</tbody>
</table>

## Event<a name="section1721512551218"></a>

In addition to the events in  [Universal Events](js-components-common-events.md), the following events are supported.

-   When the input component type is set to  **text**,  **email**,  **date**,  **time**,  **number**, or  **password**, the following events are supported.

    <a name="table9215955923"></a>
    <table><thead align="left"><tr id="row02158552029"><th class="cellrowborder" valign="top" width="24.852485248524854%" id="mcps1.1.4.1.1"><p id="p1121618551728"><a name="p1121618551728"></a><a name="p1121618551728"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="29.552955295529554%" id="mcps1.1.4.1.2"><p id="p182161855921"><a name="p182161855921"></a><a name="p182161855921"></a>Parameter</p>
    </th>
    <th class="cellrowborder" valign="top" width="45.5945594559456%" id="mcps1.1.4.1.3"><p id="p921685513212"><a name="p921685513212"></a><a name="p921685513212"></a>Triggered when</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row102168555217"><td class="cellrowborder" valign="top" width="24.852485248524854%" headers="mcps1.1.4.1.1 "><p id="p1221625514210"><a name="p1221625514210"></a><a name="p1221625514210"></a>change</p>
    </td>
    <td class="cellrowborder" valign="top" width="29.552955295529554%" headers="mcps1.1.4.1.2 "><p id="p8216155822"><a name="p8216155822"></a><a name="p8216155822"></a>{ value:inputValue }</p>
    </td>
    <td class="cellrowborder" valign="top" width="45.5945594559456%" headers="mcps1.1.4.1.3 "><p id="p18216135511213"><a name="p18216135511213"></a><a name="p18216135511213"></a>Triggered when the content entered in the text box changes. The most recent text entered by the user is returned.</p>
    <div class="note" id="note32161955422"><a name="note32161955422"></a><a name="note32161955422"></a><span class="notetitle"> NOTE: </span><div class="notebody"><p id="p521616551527"><a name="p521616551527"></a><a name="p521616551527"></a>If you change the <strong id="b0472428225"><a name="b0472428225"></a><a name="b0472428225"></a>value</strong> attribute directly, this event will not be triggered.</p>
    </div></div>
    </td>
    </tr>
    <tr id="row152166550212"><td class="cellrowborder" valign="top" width="24.852485248524854%" headers="mcps1.1.4.1.1 "><p id="p1121695515215"><a name="p1121695515215"></a><a name="p1121695515215"></a>enterkeyclick</p>
    </td>
    <td class="cellrowborder" valign="top" width="29.552955295529554%" headers="mcps1.1.4.1.2 "><p id="p15216115511211"><a name="p15216115511211"></a><a name="p15216115511211"></a>{ value:enterKey }</p>
    </td>
    <td class="cellrowborder" valign="top" width="45.5945594559456%" headers="mcps1.1.4.1.3 "><p id="p162165551211"><a name="p162165551211"></a><a name="p162165551211"></a>Triggered when the <strong id="b151716216246"><a name="b151716216246"></a><a name="b151716216246"></a>Enter</strong> key on a soft keyboard is pressed. The type of the <strong id="b141714218245"><a name="b141714218245"></a><a name="b141714218245"></a>Enter</strong> key is returned, which is of the number type. Available values are as follows:</p>
    <a name="ul121665519215"></a><a name="ul121665519215"></a><ul id="ul121665519215"><li><strong id="b1548345132518"><a name="b1548345132518"></a><a name="b1548345132518"></a>2</strong>: returned if <strong id="b184901156253"><a name="b184901156253"></a><a name="b184901156253"></a>enterkeytype</strong> is <strong id="b124911657254"><a name="b124911657254"></a><a name="b124911657254"></a>go</strong>.</li><li><strong id="b751686253"><a name="b751686253"></a><a name="b751686253"></a>3</strong>: returned if <strong id="b1052188112512"><a name="b1052188112512"></a><a name="b1052188112512"></a>enterkeytype</strong> is <strong id="b18524802520"><a name="b18524802520"></a><a name="b18524802520"></a>search</strong>.</li><li><strong id="b746419112510"><a name="b746419112510"></a><a name="b746419112510"></a>4</strong>: returned if <strong id="b74652910250"><a name="b74652910250"></a><a name="b74652910250"></a>enterkeytype</strong> is <strong id="b13465189132516"><a name="b13465189132516"></a><a name="b13465189132516"></a>send</strong>.</li><li><strong id="b14743131042519"><a name="b14743131042519"></a><a name="b14743131042519"></a>5</strong>: returned if <strong id="b16743121016252"><a name="b16743121016252"></a><a name="b16743121016252"></a>enterkeytype</strong> is <strong id="b0744191012516"><a name="b0744191012516"></a><a name="b0744191012516"></a>next</strong>.</li><li><strong id="b133514143257"><a name="b133514143257"></a><a name="b133514143257"></a>6</strong>: returned if <strong id="b113411814112516"><a name="b113411814112516"></a><a name="b113411814112516"></a>enterkeytype</strong> is <strong id="b334151416257"><a name="b334151416257"></a><a name="b334151416257"></a>default</strong>, <strong id="b1934281412257"><a name="b1934281412257"></a><a name="b1934281412257"></a>done</strong>, or is not set.</li></ul>
    </td>
    </tr>
    <tr id="row1121715551027"><td class="cellrowborder" valign="top" width="24.852485248524854%" headers="mcps1.1.4.1.1 "><p id="p92175551422"><a name="p92175551422"></a><a name="p92175551422"></a>translate<sup id="sup13217195510219"><a name="sup13217195510219"></a><a name="sup13217195510219"></a>5+</sup></p>
    </td>
    <td class="cellrowborder" valign="top" width="29.552955295529554%" headers="mcps1.1.4.1.2 "><p id="p321795510218"><a name="p321795510218"></a><a name="p321795510218"></a>{ value: selectedText }</p>
    </td>
    <td class="cellrowborder" valign="top" width="45.5945594559456%" headers="mcps1.1.4.1.3 "><p id="p92171455627"><a name="p92171455627"></a><a name="p92171455627"></a>Triggered when users click the translate button in the pop menu displayed after they select a text segment. The selected text content is returned.</p>
    </td>
    </tr>
    <tr id="row1821711551524"><td class="cellrowborder" valign="top" width="24.852485248524854%" headers="mcps1.1.4.1.1 "><p id="p1321711551229"><a name="p1321711551229"></a><a name="p1321711551229"></a>share<sup id="sup182171255223"><a name="sup182171255223"></a><a name="sup182171255223"></a>5+</sup></p>
    </td>
    <td class="cellrowborder" valign="top" width="29.552955295529554%" headers="mcps1.1.4.1.2 "><p id="p92171555228"><a name="p92171555228"></a><a name="p92171555228"></a>{ value: selectedText }</p>
    </td>
    <td class="cellrowborder" valign="top" width="45.5945594559456%" headers="mcps1.1.4.1.3 "><p id="p122171055425"><a name="p122171055425"></a><a name="p122171055425"></a>Triggered when users click the share button in the pop menu displayed after they select a text segment. The selected text content is returned.</p>
    </td>
    </tr>
    <tr id="row1921717551028"><td class="cellrowborder" valign="top" width="24.852485248524854%" headers="mcps1.1.4.1.1 "><p id="p1821716555210"><a name="p1821716555210"></a><a name="p1821716555210"></a>search<sup id="sup20217175516211"><a name="sup20217175516211"></a><a name="sup20217175516211"></a>5+</sup></p>
    </td>
    <td class="cellrowborder" valign="top" width="29.552955295529554%" headers="mcps1.1.4.1.2 "><p id="p1421715514216"><a name="p1421715514216"></a><a name="p1421715514216"></a>{ value: selectedText }</p>
    </td>
    <td class="cellrowborder" valign="top" width="45.5945594559456%" headers="mcps1.1.4.1.3 "><p id="p20217175515210"><a name="p20217175515210"></a><a name="p20217175515210"></a>Triggered when users click the search button in the pop menu displayed after they select a text segment. The selected text content is returned.</p>
    </td>
    </tr>
    <tr id="row2021725516220"><td class="cellrowborder" valign="top" width="24.852485248524854%" headers="mcps1.1.4.1.1 "><p id="p521715553212"><a name="p521715553212"></a><a name="p521715553212"></a>optionselect<sup id="sup122171855227"><a name="sup122171855227"></a><a name="sup122171855227"></a>5+</sup></p>
    </td>
    <td class="cellrowborder" valign="top" width="29.552955295529554%" headers="mcps1.1.4.1.2 "><p id="p721885513216"><a name="p721885513216"></a><a name="p721885513216"></a>{ index:optionIndex, value: selectedText }</p>
    </td>
    <td class="cellrowborder" valign="top" width="45.5945594559456%" headers="mcps1.1.4.1.3 "><p id="p721812557212"><a name="p721812557212"></a><a name="p721812557212"></a>Triggered when users click a menu option in the pop menu displayed after they select a text segment. This event is valid only when the <strong id="b168471038173918"><a name="b168471038173918"></a><a name="b168471038173918"></a>menuoptions</strong> attribute is set. The option index and selected text content are returned.</p>
    </td>
    </tr>
    <tr id="row1180295735010"><td class="cellrowborder" valign="top" width="24.852485248524854%" headers="mcps1.1.4.1.1 "><p id="p17803157175014"><a name="p17803157175014"></a><a name="p17803157175014"></a>selectchange<sup id="sup774434715119"><a name="sup774434715119"></a><a name="sup774434715119"></a>6+</sup></p>
    </td>
    <td class="cellrowborder" valign="top" width="29.552955295529554%" headers="mcps1.1.4.1.2 "><p id="p13803157185013"><a name="p13803157185013"></a><a name="p13803157185013"></a>{ start: number, end: number }</p>
    </td>
    <td class="cellrowborder" valign="top" width="45.5945594559456%" headers="mcps1.1.4.1.3 "><p id="p4803155719505"><a name="p4803155719505"></a><a name="p4803155719505"></a>Triggered when the text selection changes.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   When the input component type is set to  **checkbox**  or  **radio**, the following events are supported.

    <a name="table722013552211"></a>
    <table><thead align="left"><tr id="row1220145519211"><th class="cellrowborder" valign="top" width="24.852485248524854%" id="mcps1.1.4.1.1"><p id="p1220755621"><a name="p1220755621"></a><a name="p1220755621"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="29.552955295529554%" id="mcps1.1.4.1.2"><p id="p322014550213"><a name="p322014550213"></a><a name="p322014550213"></a>Parameter</p>
    </th>
    <th class="cellrowborder" valign="top" width="45.5945594559456%" id="mcps1.1.4.1.3"><p id="p322117554212"><a name="p322117554212"></a><a name="p322117554212"></a>Triggered when</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row1622118559216"><td class="cellrowborder" valign="top" width="24.852485248524854%" headers="mcps1.1.4.1.1 "><p id="p922116551422"><a name="p922116551422"></a><a name="p922116551422"></a>change</p>
    </td>
    <td class="cellrowborder" valign="top" width="29.552955295529554%" headers="mcps1.1.4.1.2 "><p id="p1322185512210"><a name="p1322185512210"></a><a name="p1322185512210"></a>{ checked:true | false }</p>
    </td>
    <td class="cellrowborder" valign="top" width="45.5945594559456%" headers="mcps1.1.4.1.3 "><p id="p1822119551024"><a name="p1822119551024"></a><a name="p1822119551024"></a>Triggered when the checked status of the <strong id="b13256373400"><a name="b13256373400"></a><a name="b13256373400"></a>checkbox</strong> or <strong id="b17332143714015"><a name="b17332143714015"></a><a name="b17332143714015"></a>radio</strong> button changes.</p>
    </td>
    </tr>
    </tbody>
    </table>


## Method<a name="section47669296127"></a>

In addition to the methods in  [Universal Methods](js-components-common-methods.md), the following events are supported.

<a name="t75606345ece64f818511af2963b4522d"></a>
<table><thead align="left"><tr id="rf7e96304e96b4abcada899f917623b50"><th class="cellrowborder" valign="top" width="16.88%" id="mcps1.1.4.1.1"><p id="abdd98ec01df046a7ac2f66a3fa4eda04"><a name="abdd98ec01df046a7ac2f66a3fa4eda04"></a><a name="abdd98ec01df046a7ac2f66a3fa4eda04"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="29.12%" id="mcps1.1.4.1.2"><p id="afa86bf0c638b4860a91ea0e6255b7744"><a name="afa86bf0c638b4860a91ea0e6255b7744"></a><a name="afa86bf0c638b4860a91ea0e6255b7744"></a>Parameter</p>
</th>
<th class="cellrowborder" valign="top" width="54%" id="mcps1.1.4.1.3"><p id="aa7783f4706e8434493b6e941e0100652"><a name="aa7783f4706e8434493b6e941e0100652"></a><a name="aa7783f4706e8434493b6e941e0100652"></a>Triggered when</p>
</th>
</tr>
</thead>
<tbody><tr id="r51da7a66ad844356a54fc7d198bbc496"><td class="cellrowborder" valign="top" width="16.88%" headers="mcps1.1.4.1.1 "><p id="a37c62c3017bc4b85813051fedae5523a"><a name="a37c62c3017bc4b85813051fedae5523a"></a><a name="a37c62c3017bc4b85813051fedae5523a"></a>focus</p>
</td>
<td class="cellrowborder" valign="top" width="29.12%" headers="mcps1.1.4.1.2 "><p id="a0fa3cdedaab94e11b1c1df493e671084"><a name="a0fa3cdedaab94e11b1c1df493e671084"></a><a name="a0fa3cdedaab94e11b1c1df493e671084"></a>{focus:true|false}: If <strong id="b42842569136"><a name="b42842569136"></a><a name="b42842569136"></a>focus</strong> is not passed, the default value <strong id="b95941968149"><a name="b95941968149"></a><a name="b95941968149"></a>true</strong> is used.</p>
</td>
<td class="cellrowborder" valign="top" width="54%" headers="mcps1.1.4.1.3 "><p id="abc7c81f1669e4e27bdc255ddf7c24167"><a name="abc7c81f1669e4e27bdc255ddf7c24167"></a><a name="abc7c81f1669e4e27bdc255ddf7c24167"></a>Obtains or loses the focus of a component. When the component type is set to text, email, date, time, number, or password, the input method can be displayed or collapsed.</p>
</td>
</tr>
<tr id="row17342754165611"><td class="cellrowborder" valign="top" width="16.88%" headers="mcps1.1.4.1.1 "><p id="p1343054115615"><a name="p1343054115615"></a><a name="p1343054115615"></a>showError</p>
</td>
<td class="cellrowborder" valign="top" width="29.12%" headers="mcps1.1.4.1.2 "><p id="p153431354175613"><a name="p153431354175613"></a><a name="p153431354175613"></a>{ error: string }</p>
</td>
<td class="cellrowborder" valign="top" width="54%" headers="mcps1.1.4.1.3 "><p id="p1034315465618"><a name="p1034315465618"></a><a name="p1034315465618"></a>Displays the error message. This attribute is available when the component type is set to text, email, date, time, number, or password.</p>
</td>
</tr>
<tr id="row4919162415418"><td class="cellrowborder" valign="top" width="16.88%" headers="mcps1.1.4.1.1 "><p id="p191914240419"><a name="p191914240419"></a><a name="p191914240419"></a>delete<sup id="sup1636182514275"><a name="sup1636182514275"></a><a name="sup1636182514275"></a>6+</sup></p>
</td>
<td class="cellrowborder" valign="top" width="29.12%" headers="mcps1.1.4.1.2 "><p id="p209201424104119"><a name="p209201424104119"></a><a name="p209201424104119"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="54%" headers="mcps1.1.4.1.3 "><p id="p2920424124118"><a name="p2920424124118"></a><a name="p2920424124118"></a>Deletes the text content based on the current cursor position when the input component type is set to <strong id="b4497036164114"><a name="b4497036164114"></a><a name="b4497036164114"></a>text</strong>, <strong id="b3497173619415"><a name="b3497173619415"></a><a name="b3497173619415"></a>email</strong>, <strong id="b949716360414"><a name="b949716360414"></a><a name="b949716360414"></a>date</strong>, <strong id="b5497236154118"><a name="b5497236154118"></a><a name="b5497236154118"></a>time</strong>, <strong id="b649783615419"><a name="b649783615419"></a><a name="b649783615419"></a>number</strong>, or <strong id="b1749743654115"><a name="b1749743654115"></a><a name="b1749743654115"></a>password</strong>. If the current input component does not have a cursor, the last character is deleted and the cursor is displayed by default.</p>
</td>
</tr>
</tbody>
</table>

## Example Code<a name="section106355275448"></a>

1.  Single-line text box

    ```
    <!-- xxx.hml -->
    <div class="content">
      <input id="input" class="input" type="text" value="" maxlength="20" enterkeytype="send"
        headericon="/common/search.svg" placeholder="Please input text" onchange="change"
        onenterkeyclick="enterkeyClick">
      </input>
      <input class="button" type="button" value="Submit" onclick="buttonClick"></input>
    </div>
    ```

    ```
    /* xxx.css */
    .content {
      width: 60%;
      flex-direction: column;
      align-items: center;
    }
    .input {
      placeholder-color: gray;
    }
    .button {
      background-color: gray;
      margin-top: 20px;
    }
    ```

    ```
    // xxx.js
    import prompt from '@system.prompt'
    export default {
      change(e){
        prompt.showToast({
          message: "value: " + e.value,
          duration: 3000,
        });
      },
      enterkeyClick(e){
        prompt.showToast({
          message: "enterkey clicked",
          duration: 3000,
        });
      },
      buttonClick(e){
        this.$element("input").showError({
          error: 'error text'
        });
      },
    }
    ```

    ![](figures/1-34.png)

2.  Common button

    ```
    <!-- xxx.hml -->
    <div class="div-button">
      <input class="button" type="button" value="Input-Button"></input>
    </div>
    ```

    ```
    /* xxx.css */
    .div-button {
      flex-direction: column;
      align-items: center;
    }
    .button {
      margin-top: 30px;
      width: 280px;
    }
    ```

    ![](figures/1-34.png)

3.  Check box

    ```
    <!-- xxx.hml -->
    <div class="content">
      <input onchange="checkboxOnChange" checked="true"' type="checkbox"></input>
    </div>
    ```

    ```
    /* xxx.css */
    .content{
      width: 100%;
      height: 200px;
      align-items: center; 
      justify-content: center;   
    }
    ```

    ```
    // xxx.js
    import prompt from '@system.prompt'
    export default {
      checkboxOnChange(e) {
        prompt.showToast({
          message:'checked: ' + e.checked,
          duration: 3000,
        });
      }
    }
    ```

    ![](figures/1-35.png)

4.  Radio button

    ```
    <!-- xxx.hml -->
    <div class="content">
      <input type="radio" checked='true' name="radioSample" value="radio1" onchange="onRadioChange('radio1')"></input>
      <input type="radio" checked='false' name="radioSample" value="radio2" onchange="onRadioChange('radio2')"></input>
      <input type="radio" checked='false' name="radioSample" value="radio3" onchange="onRadioChange('radio3')"></input>
    </div>
    ```

    ```
    /* xxx.css */
    .content{
      width: 100%;
      height: 200px;
      justify-content: center;
      align-items: center;
    }
    ```

    ```
    // xxx.js
    import prompt from '@system.prompt'
    export default {
      onRadioChange(inputValue, e) {
        if (inputValue === e.value) {
          prompt.showToast({
            message: 'The chosen radio is ' + e.value,
            duration: 3000,
          });
        }
      }
    }
    ```

    ![](figures/1-36.png)


