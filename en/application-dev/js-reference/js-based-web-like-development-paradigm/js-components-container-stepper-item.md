# stepper-item<a name="EN-US_TOPIC_0000001127125034"></a>

The  **<stepper-item\>**  component displays a step in the step navigator. This component is the child component of  **<stepper\>**.

>![](../../public_sys-resources/icon-note.gif) **NOTE:** 
>This component is supported since API version 5.

## Permission List<a name="section11257113618419"></a>

None

## Child Component<a name="section9288143101012"></a>

Supported

## Attribute<a name="section2907183951110"></a>

In addition to the attributes in  [Universal Attributes](js-components-common-attributes.md), the following attributes are supported.

<a name="table20633101642315"></a>
<table><thead align="left"><tr id="row663331618238"><th class="cellrowborder" valign="top" width="23.119999999999997%" id="mcps1.1.6.1.1"><p id="a45273e2103004ff3bdd3375013e96a2a"><a name="a45273e2103004ff3bdd3375013e96a2a"></a><a name="a45273e2103004ff3bdd3375013e96a2a"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="23.119999999999997%" id="mcps1.1.6.1.2"><p id="ad5b10d4a60e44bb4a8bbb3b4416d7b27"><a name="ad5b10d4a60e44bb4a8bbb3b4416d7b27"></a><a name="ad5b10d4a60e44bb4a8bbb3b4416d7b27"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="10.48%" id="mcps1.1.6.1.3"><p id="ab2ae3d9f60d6475ab95ba095851a9d07"><a name="ab2ae3d9f60d6475ab95ba095851a9d07"></a><a name="ab2ae3d9f60d6475ab95ba095851a9d07"></a>Default Value</p>
</th>
<th class="cellrowborder" valign="top" width="7.5200000000000005%" id="mcps1.1.6.1.4"><p id="p824610360217"><a name="p824610360217"></a><a name="p824610360217"></a>Mandatory</p>
</th>
<th class="cellrowborder" valign="top" width="35.76%" id="mcps1.1.6.1.5"><p id="af5c3b773ed0a42e589819a6c8d257ca1"><a name="af5c3b773ed0a42e589819a6c8d257ca1"></a><a name="af5c3b773ed0a42e589819a6c8d257ca1"></a>Triggered when</p>
</th>
</tr>
</thead>
<tbody><tr id="row5283312343"><td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.1 "><p id="p228421219417"><a name="p228421219417"></a><a name="p228421219417"></a>label</p>
</td>
<td class="cellrowborder" valign="top" width="23.119999999999997%" headers="mcps1.1.6.1.2 "><p id="p1628411126418"><a name="p1628411126418"></a><a name="p1628411126418"></a><a href="#table119681501422">Label</a></p>
</td>
<td class="cellrowborder" valign="top" width="10.48%" headers="mcps1.1.6.1.3 "><p id="p228441219417"><a name="p228441219417"></a><a name="p228441219417"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.5200000000000005%" headers="mcps1.1.6.1.4 "><p id="p928417121844"><a name="p928417121844"></a><a name="p928417121844"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="35.76%" headers="mcps1.1.6.1.5 "><p id="p46212038248"><a name="p46212038248"></a><a name="p46212038248"></a>Button text at the bottom of the customized step navigator. Dynamic modification is not supported. If this attribute is not set, <strong id="b244691335510"><a name="b244691335510"></a><a name="b244691335510"></a>BACK</strong> and <strong id="b128548113558"><a name="b128548113558"></a><a name="b128548113558"></a>NEXT</strong> will be used by default as button text in case the system language is not Chinese. For the first step, there is no previous button. For the last step, the text on the next button is <strong id="b8844136185718"><a name="b8844136185718"></a><a name="b8844136185718"></a>START</strong> for non-Chinese languages by default.</p>
</td>
</tr>
</tbody>
</table>

**Table  1**  Label parameters

<a name="table119681501422"></a>
<table><thead align="left"><tr id="row9968170228"><th class="cellrowborder" valign="top" width="11.06%" id="mcps1.2.5.1.1"><p id="p18968201227"><a name="p18968201227"></a><a name="p18968201227"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="9.08%" id="mcps1.2.5.1.2"><p id="p199691501328"><a name="p199691501328"></a><a name="p199691501328"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="8.450000000000001%" id="mcps1.2.5.1.3"><p id="p139699019213"><a name="p139699019213"></a><a name="p139699019213"></a>Default Value</p>
</th>
<th class="cellrowborder" valign="top" width="71.41%" id="mcps1.2.5.1.4"><p id="p1969507219"><a name="p1969507219"></a><a name="p1969507219"></a>Triggered when</p>
</th>
</tr>
</thead>
<tbody><tr id="row1496930728"><td class="cellrowborder" valign="top" width="11.06%" headers="mcps1.2.5.1.1 "><p id="p3969110127"><a name="p3969110127"></a><a name="p3969110127"></a>prevLabel</p>
</td>
<td class="cellrowborder" valign="top" width="9.08%" headers="mcps1.2.5.1.2 "><p id="p99691100212"><a name="p99691100212"></a><a name="p99691100212"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="8.450000000000001%" headers="mcps1.2.5.1.3 "><p id="p1996919011215"><a name="p1996919011215"></a><a name="p1996919011215"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="71.41%" headers="mcps1.2.5.1.4 "><p id="p8969202219"><a name="p8969202219"></a><a name="p8969202219"></a>Text content of the previous button at the bottom of the step navigator.</p>
</td>
</tr>
<tr id="row296910827"><td class="cellrowborder" valign="top" width="11.06%" headers="mcps1.2.5.1.1 "><p id="p896910627"><a name="p896910627"></a><a name="p896910627"></a>nextLabel</p>
</td>
<td class="cellrowborder" valign="top" width="9.08%" headers="mcps1.2.5.1.2 "><p id="p1696900529"><a name="p1696900529"></a><a name="p1696900529"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="8.450000000000001%" headers="mcps1.2.5.1.3 "><p id="p18969301227"><a name="p18969301227"></a><a name="p18969301227"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="71.41%" headers="mcps1.2.5.1.4 "><p id="p159691801223"><a name="p159691801223"></a><a name="p159691801223"></a>Text content of the next button at the bottom of the step navigator.</p>
</td>
</tr>
<tr id="row119116012913"><td class="cellrowborder" valign="top" width="11.06%" headers="mcps1.2.5.1.1 "><p id="p99121704918"><a name="p99121704918"></a><a name="p99121704918"></a>status</p>
</td>
<td class="cellrowborder" valign="top" width="9.08%" headers="mcps1.2.5.1.2 "><p id="p1912401095"><a name="p1912401095"></a><a name="p1912401095"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="8.450000000000001%" headers="mcps1.2.5.1.3 "><p id="p149121201396"><a name="p149121201396"></a><a name="p149121201396"></a>normal</p>
</td>
<td class="cellrowborder" valign="top" width="71.41%" headers="mcps1.2.5.1.4 "><p id="p491230493"><a name="p491230493"></a><a name="p491230493"></a>Initial status of the current step in the step navigator. Available values are as follows:</p>
<a name="ul15229514162318"></a><a name="ul15229514162318"></a><ul id="ul15229514162318"><li><strong id="b1154153512114"><a name="b1154153512114"></a><a name="b1154153512114"></a>normal</strong>: The right button is clickable and can navigate users to the next step when it is clicked.</li></ul>
<a name="ul5182101916236"></a><a name="ul5182101916236"></a><ul id="ul5182101916236"><li><strong id="b24961139713"><a name="b24961139713"></a><a name="b24961139713"></a>disabled</strong>: The right button is grayed out and unavailable.</li></ul>
<a name="ul16451423182317"></a><a name="ul16451423182317"></a><ul id="ul16451423182317"><li><strong id="b193436428112"><a name="b193436428112"></a><a name="b193436428112"></a>waiting</strong>: The right button is not displayed, and a progress bar is displayed instead.</li></ul>
</td>
</tr>
</tbody>
</table>

## Style<a name="section1326042123512"></a>

In addition to the styles in  [Universal Styles](js-components-common-styles.md), the following styles are supported.

<a name="table1744514388541"></a>
<table><thead align="left"><tr id="row1244614388545"><th class="cellrowborder" valign="top" width="23.11768823117688%" id="mcps1.1.6.1.1"><p id="a4e80fb5a797c4328af30d59e2c570c71"><a name="a4e80fb5a797c4328af30d59e2c570c71"></a><a name="a4e80fb5a797c4328af30d59e2c570c71"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="20.477952204779523%" id="mcps1.1.6.1.2"><p id="a4238bd3a376645a3ad8498d3916ed6c8"><a name="a4238bd3a376645a3ad8498d3916ed6c8"></a><a name="a4238bd3a376645a3ad8498d3916ed6c8"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="8.869113088691131%" id="mcps1.1.6.1.3"><p id="a5ece9efc3a1d464a868f9557e4784a97"><a name="a5ece9efc3a1d464a868f9557e4784a97"></a><a name="a5ece9efc3a1d464a868f9557e4784a97"></a>Default Value</p>
</th>
<th class="cellrowborder" valign="top" width="7.519248075192481%" id="mcps1.1.6.1.4"><p id="p117421754619"><a name="p117421754619"></a><a name="p117421754619"></a>Mandatory</p>
</th>
<th class="cellrowborder" valign="top" width="40.01599840015999%" id="mcps1.1.6.1.5"><p id="a2454f35c1eef44b4bb681caaa3ce48fc"><a name="a2454f35c1eef44b4bb681caaa3ce48fc"></a><a name="a2454f35c1eef44b4bb681caaa3ce48fc"></a>Triggered when</p>
</th>
</tr>
</thead>
<tbody><tr id="row492070486"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="p16782113422516"><a name="p16782113422516"></a><a name="p16782113422516"></a>color</p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p id="p678210342255"><a name="p678210342255"></a><a name="p678210342255"></a>&lt;color&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p id="p0942146308"><a name="p0942146308"></a><a name="p0942146308"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p id="p9782134122511"><a name="p9782134122511"></a><a name="p9782134122511"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="p15360112213810"><a name="p15360112213810"></a><a name="p15360112213810"></a>Text color.</p>
</td>
</tr>
<tr id="row926613588711"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="p15365537102518"><a name="p15365537102518"></a><a name="p15365537102518"></a>font-size</p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p id="p1636517375255"><a name="p1636517375255"></a><a name="p1636517375255"></a>&lt;length&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p id="p7365103717256"><a name="p7365103717256"></a><a name="p7365103717256"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p id="p336663712252"><a name="p336663712252"></a><a name="p336663712252"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="p836022215814"><a name="p836022215814"></a><a name="p836022215814"></a>Text size.</p>
</td>
</tr>
<tr id="row1747615510720"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="p3376124017256"><a name="p3376124017256"></a><a name="p3376124017256"></a>allow-scale</p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p id="p1437654010251"><a name="p1437654010251"></a><a name="p1437654010251"></a>boolean</p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p id="p1376154072515"><a name="p1376154072515"></a><a name="p1376154072515"></a>true</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p id="p1937615404253"><a name="p1937615404253"></a><a name="p1937615404253"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="p536014229815"><a name="p536014229815"></a><a name="p536014229815"></a>Whether the text size changes with the system's font size settings.</p>
</td>
</tr>
<tr id="row79081352873"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="p0781642162510"><a name="p0781642162510"></a><a name="p0781642162510"></a>font-style</p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p id="p107816428255"><a name="p107816428255"></a><a name="p107816428255"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p id="p17811342142514"><a name="p17811342142514"></a><a name="p17811342142514"></a>normal</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p id="p189135463810"><a name="p189135463810"></a><a name="p189135463810"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="p10377104215812"><a name="p10377104215812"></a><a name="p10377104215812"></a>Text font style. Available values are as follows:</p>
<a name="ul6878946122313"></a><a name="ul6878946122313"></a><ul id="ul6878946122313"><li><strong id="b696623911113"><a name="b696623911113"></a><a name="b696623911113"></a>normal</strong>: standard font style</li><li><strong id="b157518456114"><a name="b157518456114"></a><a name="b157518456114"></a>italic</strong>: italic font style</li></ul>
</td>
</tr>
<tr id="row1033315491718"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="p9764174572513"><a name="p9764174572513"></a><a name="p9764174572513"></a>font-weight</p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p id="p37641045112510"><a name="p37641045112510"></a><a name="p37641045112510"></a>number|string</p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p id="p1976434511252"><a name="p1976434511252"></a><a name="p1976434511252"></a>normal</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p id="p63843547813"><a name="p63843547813"></a><a name="p63843547813"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="p107081551486"><a name="p107081551486"></a><a name="p107081551486"></a>Text font weight. The number value must be an exact multiple of 100 ranging from 100 to 900. The default value is 400. A larger value indicates a bigger weight. Available values of the string type are <strong id="b5723193018461"><a name="b5723193018461"></a><a name="b5723193018461"></a>lighter</strong>, <strong id="b2072493013464"><a name="b2072493013464"></a><a name="b2072493013464"></a>normal</strong>, <strong id="b8724173034612"><a name="b8724173034612"></a><a name="b8724173034612"></a>bold</strong>, or <strong id="b127259306468"><a name="b127259306468"></a><a name="b127259306468"></a>bolder</strong>.</p>
</td>
</tr>
<tr id="row387010448715"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="p1693494732511"><a name="p1693494732511"></a><a name="p1693494732511"></a>text-decoration</p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p id="p7934124713256"><a name="p7934124713256"></a><a name="p7934124713256"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p id="p1493416479256"><a name="p1493416479256"></a><a name="p1493416479256"></a>none</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p id="p198071106919"><a name="p198071106919"></a><a name="p198071106919"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="p169212584815"><a name="p169212584815"></a><a name="p169212584815"></a>Text modifier. Available values are as follows:</p>
<a name="ul1768145382318"></a><a name="ul1768145382318"></a><ul id="ul1768145382318"><li><strong id="b1627816474112"><a name="b1627816474112"></a><a name="b1627816474112"></a>underline</strong>: An underline is used.</li><li><strong id="b245013501810"><a name="b245013501810"></a><a name="b245013501810"></a>line-through</strong>: A strikethrough is used.</li><li><strong id="b27555510116"><a name="b27555510116"></a><a name="b27555510116"></a>none</strong>: The standard text is used.</li></ul>
</td>
</tr>
<tr id="row279314411076"><td class="cellrowborder" valign="top" width="23.11768823117688%" headers="mcps1.1.6.1.1 "><p id="p1543212507250"><a name="p1543212507250"></a><a name="p1543212507250"></a>font-family</p>
</td>
<td class="cellrowborder" valign="top" width="20.477952204779523%" headers="mcps1.1.6.1.2 "><p id="p1243215092510"><a name="p1243215092510"></a><a name="p1243215092510"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="8.869113088691131%" headers="mcps1.1.6.1.3 "><p id="p34321750192510"><a name="p34321750192510"></a><a name="p34321750192510"></a>sans-serif</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.6.1.4 "><p id="p19356791696"><a name="p19356791696"></a><a name="p19356791696"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="40.01599840015999%" headers="mcps1.1.6.1.5 "><p id="p18361661099"><a name="p18361661099"></a><a name="p18361661099"></a>Font family, in which fonts are separated by commas (,). Each font is set using a font name or font family name. The first font in the family or the font specified by <a href="js-components-common-customizing-font.md">Custom Font Styles</a> is used for the text.</p>
</td>
</tr>
</tbody>
</table>

>![](../../public_sys-resources/icon-note.gif) **NOTE:** 
>-   Height and width styles are not supported. The width of each item is the same as that of its container. The height of each item is the difference between the container height and the bottom button height.
>-   The  **posit**  style is not supported.

## Event<a name="section121081858163714"></a>

In addition to the events in  [Universal Events](js-components-common-events.md), the following events are supported.

<a name="table3706139102712"></a>
<table><thead align="left"><tr id="row3706394279"><th class="cellrowborder" valign="top" width="24.852485248524854%" id="mcps1.1.4.1.1"><p id="a426b8903842d48fa8012a24ff3c997eb"><a name="a426b8903842d48fa8012a24ff3c997eb"></a><a name="a426b8903842d48fa8012a24ff3c997eb"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="29.552955295529554%" id="mcps1.1.4.1.2"><p id="a53448ba47e5e4ae9bf7774c90820e970"><a name="a53448ba47e5e4ae9bf7774c90820e970"></a><a name="a53448ba47e5e4ae9bf7774c90820e970"></a>Parameter</p>
</th>
<th class="cellrowborder" valign="top" width="45.5945594559456%" id="mcps1.1.4.1.3"><p id="add489ff50c444f24b759162c7f4bad9a"><a name="add489ff50c444f24b759162c7f4bad9a"></a><a name="add489ff50c444f24b759162c7f4bad9a"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row144051516142716"><td class="cellrowborder" valign="top" width="24.852485248524854%" headers="mcps1.1.4.1.1 "><p id="p17545162122718"><a name="p17545162122718"></a><a name="p17545162122718"></a>appear</p>
</td>
<td class="cellrowborder" valign="top" width="29.552955295529554%" headers="mcps1.1.4.1.2 "><p id="p17545182113270"><a name="p17545182113270"></a><a name="p17545182113270"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="45.5945594559456%" headers="mcps1.1.4.1.3 "><p id="p18545172132717"><a name="p18545172132717"></a><a name="p18545172132717"></a>Triggered when this step is displayed.</p>
</td>
</tr>
<tr id="row79737130274"><td class="cellrowborder" valign="top" width="24.852485248524854%" headers="mcps1.1.4.1.1 "><p id="p105451921102718"><a name="p105451921102718"></a><a name="p105451921102718"></a>disappear</p>
</td>
<td class="cellrowborder" valign="top" width="29.552955295529554%" headers="mcps1.1.4.1.2 "><p id="p254582112712"><a name="p254582112712"></a><a name="p254582112712"></a>-</p>
</td>
<td class="cellrowborder" valign="top" width="45.5945594559456%" headers="mcps1.1.4.1.3 "><p id="p14545162142719"><a name="p14545162142719"></a><a name="p14545162142719"></a>Triggered when this step disappears.</p>
</td>
</tr>
</tbody>
</table>

## Method<a name="section2279124532420"></a>

Methods in  [Universal Methods](js-components-common-methods.md)  are not supported.

## Example Code<a name="section10326712123215"></a>

For details, see the  [stepper example code](js-components-container-stepper.md).

