# Lifecycle<a name="EN-US_TOPIC_0000001173164671"></a>

## Application Lifecycle<a name="section9779102014714"></a>

You can define the following application lifecycle functions in the  **app.js**  file.

<a name="table8760251124713"></a>
<table><thead align="left"><tr id="row147612518471"><th class="cellrowborder" valign="top" width="21.052105210521052%" id="mcps1.1.5.1.1"><p id="p8761165113471"><a name="p8761165113471"></a><a name="p8761165113471"></a>Attribute</p>
</th>
<th class="cellrowborder" valign="top" width="18.421842184218423%" id="mcps1.1.5.1.2"><p id="p157613518475"><a name="p157613518475"></a><a name="p157613518475"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="21.052105210521052%" id="mcps1.1.5.1.3"><p id="p19761051154711"><a name="p19761051154711"></a><a name="p19761051154711"></a>Description</p>
</th>
<th class="cellrowborder" valign="top" width="39.473947394739476%" id="mcps1.1.5.1.4"><p id="p1976105174713"><a name="p1976105174713"></a><a name="p1976105174713"></a>Called When</p>
</th>
</tr>
</thead>
<tbody><tr id="row12761165124716"><td class="cellrowborder" valign="top" width="21.052105210521052%" headers="mcps1.1.5.1.1 "><p id="p15761105113478"><a name="p15761105113478"></a><a name="p15761105113478"></a>onCreate</p>
</td>
<td class="cellrowborder" valign="top" width="18.421842184218423%" headers="mcps1.1.5.1.2 "><p id="p1476285124715"><a name="p1476285124715"></a><a name="p1476285124715"></a>() =&gt; void</p>
</td>
<td class="cellrowborder" valign="top" width="21.052105210521052%" headers="mcps1.1.5.1.3 "><p id="p7762165124714"><a name="p7762165124714"></a><a name="p7762165124714"></a>Listens for application creation.</p>
</td>
<td class="cellrowborder" valign="top" width="39.473947394739476%" headers="mcps1.1.5.1.4 "><p id="p47628519476"><a name="p47628519476"></a><a name="p47628519476"></a>The application is created.</p>
</td>
</tr>
<tr id="row846314312512"><td class="cellrowborder" valign="top" width="21.052105210521052%" headers="mcps1.1.5.1.1 "><p id="p246417315512"><a name="p246417315512"></a><a name="p246417315512"></a>onShow<sup id="sup9720688529"><a name="sup9720688529"></a><a name="sup9720688529"></a>6+</sup></p>
</td>
<td class="cellrowborder" valign="top" width="18.421842184218423%" headers="mcps1.1.5.1.2 "><p id="p19386104510"><a name="p19386104510"></a><a name="p19386104510"></a>() =&gt; void</p>
</td>
<td class="cellrowborder" valign="top" width="21.052105210521052%" headers="mcps1.1.5.1.3 "><p id="p1546413125110"><a name="p1546413125110"></a><a name="p1546413125110"></a>Listens for whether the application is running in the foreground.</p>
</td>
<td class="cellrowborder" valign="top" width="39.473947394739476%" headers="mcps1.1.5.1.4 "><p id="p84646335116"><a name="p84646335116"></a><a name="p84646335116"></a>The application is running in the foreground.</p>
</td>
</tr>
<tr id="row2035233945117"><td class="cellrowborder" valign="top" width="21.052105210521052%" headers="mcps1.1.5.1.1 "><p id="p73531398511"><a name="p73531398511"></a><a name="p73531398511"></a>onHide<sup id="sup78997116520"><a name="sup78997116520"></a><a name="sup78997116520"></a>6+</sup></p>
</td>
<td class="cellrowborder" valign="top" width="18.421842184218423%" headers="mcps1.1.5.1.2 "><p id="p28393441516"><a name="p28393441516"></a><a name="p28393441516"></a>() =&gt; void</p>
</td>
<td class="cellrowborder" valign="top" width="21.052105210521052%" headers="mcps1.1.5.1.3 "><p id="p43531839145118"><a name="p43531839145118"></a><a name="p43531839145118"></a>Listens for whether the application is running in the background.</p>
</td>
<td class="cellrowborder" valign="top" width="39.473947394739476%" headers="mcps1.1.5.1.4 "><p id="p2041805635112"><a name="p2041805635112"></a><a name="p2041805635112"></a>The application is running in the background.</p>
</td>
</tr>
<tr id="row7762751174719"><td class="cellrowborder" valign="top" width="21.052105210521052%" headers="mcps1.1.5.1.1 "><p id="p176215118478"><a name="p176215118478"></a><a name="p176215118478"></a>onDestroy</p>
</td>
<td class="cellrowborder" valign="top" width="18.421842184218423%" headers="mcps1.1.5.1.2 "><p id="p1576295114474"><a name="p1576295114474"></a><a name="p1576295114474"></a>() =&gt; void</p>
</td>
<td class="cellrowborder" valign="top" width="21.052105210521052%" headers="mcps1.1.5.1.3 "><p id="p37621351104718"><a name="p37621351104718"></a><a name="p37621351104718"></a>Listens for application uninstallation.</p>
</td>
<td class="cellrowborder" valign="top" width="39.473947394739476%" headers="mcps1.1.5.1.4 "><p id="p976265111475"><a name="p976265111475"></a><a name="p976265111475"></a>The application exits.</p>
</td>
</tr>
</tbody>
</table>

## Page Lifecycle<a name="section921934910481"></a>

You can define the following page lifecycle functions in the  **.js**  file of the page.

<a name="table8214149144810"></a>
<table><thead align="left"><tr id="row320574954820"><th class="cellrowborder" valign="top" width="22.12%" id="mcps1.1.5.1.1"><p id="p6205184994816"><a name="p6205184994816"></a><a name="p6205184994816"></a>Attribute</p>
</th>
<th class="cellrowborder" valign="top" width="23.05%" id="mcps1.1.5.1.2"><p id="p1420594918484"><a name="p1420594918484"></a><a name="p1420594918484"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="17.23%" id="mcps1.1.5.1.3"><p id="p1420524994817"><a name="p1420524994817"></a><a name="p1420524994817"></a>Description</p>
</th>
<th class="cellrowborder" valign="top" width="37.6%" id="mcps1.1.5.1.4"><p id="p22055492486"><a name="p22055492486"></a><a name="p22055492486"></a>Called When</p>
</th>
</tr>
</thead>
<tbody><tr id="row120616499486"><td class="cellrowborder" valign="top" width="22.12%" headers="mcps1.1.5.1.1 "><p id="p5205114974810"><a name="p5205114974810"></a><a name="p5205114974810"></a>onInit</p>
</td>
<td class="cellrowborder" valign="top" width="23.05%" headers="mcps1.1.5.1.2 "><p id="p220514918482"><a name="p220514918482"></a><a name="p220514918482"></a>() =&gt; void</p>
</td>
<td class="cellrowborder" valign="top" width="17.23%" headers="mcps1.1.5.1.3 "><p id="p122065491483"><a name="p122065491483"></a><a name="p122065491483"></a>Listens for page initialization.</p>
</td>
<td class="cellrowborder" valign="top" width="37.6%" headers="mcps1.1.5.1.4 "><p id="p72061949104813"><a name="p72061949104813"></a><a name="p72061949104813"></a>Page initialization is complete. This function is called only once in the page lifecycle.</p>
</td>
</tr>
<tr id="row920612490483"><td class="cellrowborder" valign="top" width="22.12%" headers="mcps1.1.5.1.1 "><p id="p5206349114812"><a name="p5206349114812"></a><a name="p5206349114812"></a>onReady</p>
</td>
<td class="cellrowborder" valign="top" width="23.05%" headers="mcps1.1.5.1.2 "><p id="p1206164910486"><a name="p1206164910486"></a><a name="p1206164910486"></a>() =&gt; void</p>
</td>
<td class="cellrowborder" valign="top" width="17.23%" headers="mcps1.1.5.1.3 "><p id="p112066492486"><a name="p112066492486"></a><a name="p112066492486"></a>Listens for page creation.</p>
</td>
<td class="cellrowborder" valign="top" width="37.6%" headers="mcps1.1.5.1.4 "><p id="p19206649154818"><a name="p19206649154818"></a><a name="p19206649154818"></a>A page is created. This function is called only once in the page lifecycle.</p>
</td>
</tr>
<tr id="row920615493488"><td class="cellrowborder" valign="top" width="22.12%" headers="mcps1.1.5.1.1 "><p id="p16206144911482"><a name="p16206144911482"></a><a name="p16206144911482"></a>onShow</p>
</td>
<td class="cellrowborder" valign="top" width="23.05%" headers="mcps1.1.5.1.2 "><p id="p1020619492480"><a name="p1020619492480"></a><a name="p1020619492480"></a>() =&gt; void</p>
</td>
<td class="cellrowborder" valign="top" width="17.23%" headers="mcps1.1.5.1.3 "><p id="p72061349164819"><a name="p72061349164819"></a><a name="p72061349164819"></a>Listens for page display.</p>
</td>
<td class="cellrowborder" valign="top" width="37.6%" headers="mcps1.1.5.1.4 "><p id="p1920684934812"><a name="p1920684934812"></a><a name="p1920684934812"></a>The page is displayed.</p>
</td>
</tr>
<tr id="row14207184919481"><td class="cellrowborder" valign="top" width="22.12%" headers="mcps1.1.5.1.1 "><p id="p1820694917488"><a name="p1820694917488"></a><a name="p1820694917488"></a>onHide</p>
</td>
<td class="cellrowborder" valign="top" width="23.05%" headers="mcps1.1.5.1.2 "><p id="p1720694914485"><a name="p1720694914485"></a><a name="p1720694914485"></a>() =&gt; void</p>
</td>
<td class="cellrowborder" valign="top" width="17.23%" headers="mcps1.1.5.1.3 "><p id="p10207144914813"><a name="p10207144914813"></a><a name="p10207144914813"></a>Listens for page disappearance.</p>
</td>
<td class="cellrowborder" valign="top" width="37.6%" headers="mcps1.1.5.1.4 "><p id="p1020724994815"><a name="p1020724994815"></a><a name="p1020724994815"></a>The page disappears.</p>
</td>
</tr>
<tr id="row11207194916482"><td class="cellrowborder" valign="top" width="22.12%" headers="mcps1.1.5.1.1 "><p id="p16207849204813"><a name="p16207849204813"></a><a name="p16207849204813"></a>onDestroy</p>
</td>
<td class="cellrowborder" valign="top" width="23.05%" headers="mcps1.1.5.1.2 "><p id="p102071490484"><a name="p102071490484"></a><a name="p102071490484"></a>() =&gt; void</p>
</td>
<td class="cellrowborder" valign="top" width="17.23%" headers="mcps1.1.5.1.3 "><p id="p1520744911486"><a name="p1520744911486"></a><a name="p1520744911486"></a>Listens for page destruction.</p>
</td>
<td class="cellrowborder" valign="top" width="37.6%" headers="mcps1.1.5.1.4 "><p id="p82071649104811"><a name="p82071649104811"></a><a name="p82071649104811"></a>The page is destroyed.</p>
</td>
</tr>
<tr id="row192082496486"><td class="cellrowborder" valign="top" width="22.12%" headers="mcps1.1.5.1.1 "><p id="p1420710493489"><a name="p1420710493489"></a><a name="p1420710493489"></a>onBackPress</p>
</td>
<td class="cellrowborder" valign="top" width="23.05%" headers="mcps1.1.5.1.2 "><p id="p12207649174810"><a name="p12207649174810"></a><a name="p12207649174810"></a>() =&gt; boolean</p>
</td>
<td class="cellrowborder" valign="top" width="17.23%" headers="mcps1.1.5.1.3 "><p id="p14207249154815"><a name="p14207249154815"></a><a name="p14207249154815"></a>Listens for the back button action.</p>
</td>
<td class="cellrowborder" valign="top" width="37.6%" headers="mcps1.1.5.1.4 "><p id="p1020714916483"><a name="p1020714916483"></a><a name="p1020714916483"></a>The back button is touched.</p>
<a name="ul02081949144816"></a><a name="ul02081949144816"></a><ul id="ul02081949144816"><li><strong id="b1355813548581"><a name="b1355813548581"></a><a name="b1355813548581"></a>true</strong> means that the page processes the return logic.</li><li><strong id="b163335813598"><a name="b163335813598"></a><a name="b163335813598"></a>false</strong> means that the default return logic is used.</li><li>If no value is returned, the default return logic is used.</li></ul>
</td>
</tr>
<tr id="row8208174916489"><td class="cellrowborder" valign="top" width="22.12%" headers="mcps1.1.5.1.1 "><p id="p1920810495486"><a name="p1920810495486"></a><a name="p1920810495486"></a>onActive()<sup id="sup1920884964819"><a name="sup1920884964819"></a><a name="sup1920884964819"></a>5+</sup></p>
</td>
<td class="cellrowborder" valign="top" width="23.05%" headers="mcps1.1.5.1.2 "><p id="p92081349194817"><a name="p92081349194817"></a><a name="p92081349194817"></a>() =&gt; void</p>
</td>
<td class="cellrowborder" valign="top" width="17.23%" headers="mcps1.1.5.1.3 "><p id="p1320812492487"><a name="p1320812492487"></a><a name="p1320812492487"></a>Listens for page activation.</p>
</td>
<td class="cellrowborder" valign="top" width="37.6%" headers="mcps1.1.5.1.4 "><p id="p820834974814"><a name="p820834974814"></a><a name="p820834974814"></a>The page is activated.</p>
</td>
</tr>
<tr id="row92091549174812"><td class="cellrowborder" valign="top" width="22.12%" headers="mcps1.1.5.1.1 "><p id="p12084494487"><a name="p12084494487"></a><a name="p12084494487"></a>onInactive()<sup id="sup3208349144814"><a name="sup3208349144814"></a><a name="sup3208349144814"></a>5+</sup></p>
</td>
<td class="cellrowborder" valign="top" width="23.05%" headers="mcps1.1.5.1.2 "><p id="p1820854911485"><a name="p1820854911485"></a><a name="p1820854911485"></a>() =&gt; void</p>
</td>
<td class="cellrowborder" valign="top" width="17.23%" headers="mcps1.1.5.1.3 "><p id="p2209114954816"><a name="p2209114954816"></a><a name="p2209114954816"></a>Listens for page suspension.</p>
</td>
<td class="cellrowborder" valign="top" width="37.6%" headers="mcps1.1.5.1.4 "><p id="p1220944974811"><a name="p1220944974811"></a><a name="p1220944974811"></a>The page is suspended.</p>
</td>
</tr>
<tr id="row020918491481"><td class="cellrowborder" valign="top" width="22.12%" headers="mcps1.1.5.1.1 "><p id="p5209849124815"><a name="p5209849124815"></a><a name="p5209849124815"></a>onNewRequest()<sup id="sup32095496485"><a name="sup32095496485"></a><a name="sup32095496485"></a>5+</sup></p>
</td>
<td class="cellrowborder" valign="top" width="23.05%" headers="mcps1.1.5.1.2 "><p id="p22091849144815"><a name="p22091849144815"></a><a name="p22091849144815"></a>() =&gt; void</p>
</td>
<td class="cellrowborder" valign="top" width="17.23%" headers="mcps1.1.5.1.3 "><p id="p72091149134813"><a name="p72091149134813"></a><a name="p72091149134813"></a>Listens for a new FA request.</p>
</td>
<td class="cellrowborder" valign="top" width="37.6%" headers="mcps1.1.5.1.4 "><p id="p1920974974818"><a name="p1920974974818"></a><a name="p1920974974818"></a>The FA has been started and a new request is received.</p>
</td>
</tr>
</tbody>
</table>

The lifecycle functions of page A are called in the following sequence:

-   Open page A: onInit\(\) -\> onReady\(\) -\> onShow\(\)
-   Open page B on page A: onHide\(\)
-   Go back to page A from page B: onShow\(\)
-   Exit page A: onBackPress\(\) -\> onHide\(\) -\> onDestroy\(\)
-   Hide page A: onInactive\(\) -\> onHide\(\)
-   Show background page A on the foreground: onShow\(\) -\> onActive\(\)

![](figures/en-us_image_0000001147417424.png)

