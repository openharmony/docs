# 生命周期<a name="ZH-CN_TOPIC_0000001173164671"></a>

## 应用生命周期<a name="section9779102014714"></a>

在app.js中可以定义如下应用生命周期函数：

<a name="table8760251124713"></a>
<table><thead align="left"><tr id="row147612518471"><th class="cellrowborder" valign="top" width="21.052105210521052%" id="mcps1.1.5.1.1"><p id="p8761165113471"><a name="p8761165113471"></a><a name="p8761165113471"></a>属性</p>
</th>
<th class="cellrowborder" valign="top" width="18.421842184218423%" id="mcps1.1.5.1.2"><p id="p157613518475"><a name="p157613518475"></a><a name="p157613518475"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="21.052105210521052%" id="mcps1.1.5.1.3"><p id="p19761051154711"><a name="p19761051154711"></a><a name="p19761051154711"></a>描述</p>
</th>
<th class="cellrowborder" valign="top" width="39.473947394739476%" id="mcps1.1.5.1.4"><p id="p1976105174713"><a name="p1976105174713"></a><a name="p1976105174713"></a>触发时机</p>
</th>
</tr>
</thead>
<tbody><tr id="row12761165124716"><td class="cellrowborder" valign="top" width="21.052105210521052%" headers="mcps1.1.5.1.1 "><p id="p15761105113478"><a name="p15761105113478"></a><a name="p15761105113478"></a>onCreate</p>
</td>
<td class="cellrowborder" valign="top" width="18.421842184218423%" headers="mcps1.1.5.1.2 "><p id="p1476285124715"><a name="p1476285124715"></a><a name="p1476285124715"></a>() =&gt; void</p>
</td>
<td class="cellrowborder" valign="top" width="21.052105210521052%" headers="mcps1.1.5.1.3 "><p id="p7762165124714"><a name="p7762165124714"></a><a name="p7762165124714"></a>应用创建</p>
</td>
<td class="cellrowborder" valign="top" width="39.473947394739476%" headers="mcps1.1.5.1.4 "><p id="p47628519476"><a name="p47628519476"></a><a name="p47628519476"></a>当应用创建时调用。</p>
</td>
</tr>
<tr id="row846314312512"><td class="cellrowborder" valign="top" width="21.052105210521052%" headers="mcps1.1.5.1.1 "><p id="p246417315512"><a name="p246417315512"></a><a name="p246417315512"></a>onShow<sup id="sup9720688529"><a name="sup9720688529"></a><a name="sup9720688529"></a><span>6+</span></sup></p>
</td>
<td class="cellrowborder" valign="top" width="18.421842184218423%" headers="mcps1.1.5.1.2 "><p id="p19386104510"><a name="p19386104510"></a><a name="p19386104510"></a>() =&gt; void</p>
</td>
<td class="cellrowborder" valign="top" width="21.052105210521052%" headers="mcps1.1.5.1.3 "><p id="p1546413125110"><a name="p1546413125110"></a><a name="p1546413125110"></a>应用处于前台</p>
</td>
<td class="cellrowborder" valign="top" width="39.473947394739476%" headers="mcps1.1.5.1.4 "><p id="p84646335116"><a name="p84646335116"></a><a name="p84646335116"></a>当应用处于前台时触发。</p>
</td>
</tr>
<tr id="row2035233945117"><td class="cellrowborder" valign="top" width="21.052105210521052%" headers="mcps1.1.5.1.1 "><p id="p73531398511"><a name="p73531398511"></a><a name="p73531398511"></a>onHide<sup id="sup78997116520"><a name="sup78997116520"></a><a name="sup78997116520"></a><span>6+</span></sup></p>
</td>
<td class="cellrowborder" valign="top" width="18.421842184218423%" headers="mcps1.1.5.1.2 "><p id="p28393441516"><a name="p28393441516"></a><a name="p28393441516"></a>() =&gt; void</p>
</td>
<td class="cellrowborder" valign="top" width="21.052105210521052%" headers="mcps1.1.5.1.3 "><p id="p43531839145118"><a name="p43531839145118"></a><a name="p43531839145118"></a>应用处于后台</p>
</td>
<td class="cellrowborder" valign="top" width="39.473947394739476%" headers="mcps1.1.5.1.4 "><p id="p2041805635112"><a name="p2041805635112"></a><a name="p2041805635112"></a>当应用处于后台时触发。</p>
</td>
</tr>
<tr id="row7762751174719"><td class="cellrowborder" valign="top" width="21.052105210521052%" headers="mcps1.1.5.1.1 "><p id="p176215118478"><a name="p176215118478"></a><a name="p176215118478"></a>onDestroy</p>
</td>
<td class="cellrowborder" valign="top" width="18.421842184218423%" headers="mcps1.1.5.1.2 "><p id="p1576295114474"><a name="p1576295114474"></a><a name="p1576295114474"></a>() =&gt; void</p>
</td>
<td class="cellrowborder" valign="top" width="21.052105210521052%" headers="mcps1.1.5.1.3 "><p id="p37621351104718"><a name="p37621351104718"></a><a name="p37621351104718"></a>应用销毁</p>
</td>
<td class="cellrowborder" valign="top" width="39.473947394739476%" headers="mcps1.1.5.1.4 "><p id="p976265111475"><a name="p976265111475"></a><a name="p976265111475"></a>当应用退出时触发。</p>
</td>
</tr>
</tbody>
</table>

## 页面生命周期<a name="section921934910481"></a>

在页面JS文件中可以定义如下页面生命周期函数：

<a name="table8214149144810"></a>
<table><thead align="left"><tr id="row320574954820"><th class="cellrowborder" valign="top" width="22.12%" id="mcps1.1.5.1.1"><p id="p6205184994816"><a name="p6205184994816"></a><a name="p6205184994816"></a>属性</p>
</th>
<th class="cellrowborder" valign="top" width="23.05%" id="mcps1.1.5.1.2"><p id="p1420594918484"><a name="p1420594918484"></a><a name="p1420594918484"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="17.23%" id="mcps1.1.5.1.3"><p id="p1420524994817"><a name="p1420524994817"></a><a name="p1420524994817"></a>描述</p>
</th>
<th class="cellrowborder" valign="top" width="37.6%" id="mcps1.1.5.1.4"><p id="p22055492486"><a name="p22055492486"></a><a name="p22055492486"></a>触发时机</p>
</th>
</tr>
</thead>
<tbody><tr id="row120616499486"><td class="cellrowborder" valign="top" width="22.12%" headers="mcps1.1.5.1.1 "><p id="p5205114974810"><a name="p5205114974810"></a><a name="p5205114974810"></a>onInit</p>
</td>
<td class="cellrowborder" valign="top" width="23.05%" headers="mcps1.1.5.1.2 "><p id="p220514918482"><a name="p220514918482"></a><a name="p220514918482"></a>() =&gt; void</p>
</td>
<td class="cellrowborder" valign="top" width="17.23%" headers="mcps1.1.5.1.3 "><p id="p122065491483"><a name="p122065491483"></a><a name="p122065491483"></a>页面初始化</p>
</td>
<td class="cellrowborder" valign="top" width="37.6%" headers="mcps1.1.5.1.4 "><p id="p72061949104813"><a name="p72061949104813"></a><a name="p72061949104813"></a>页面数据初始化完成时触发，只触发一次。</p>
</td>
</tr>
<tr id="row920612490483"><td class="cellrowborder" valign="top" width="22.12%" headers="mcps1.1.5.1.1 "><p id="p5206349114812"><a name="p5206349114812"></a><a name="p5206349114812"></a>onReady</p>
</td>
<td class="cellrowborder" valign="top" width="23.05%" headers="mcps1.1.5.1.2 "><p id="p1206164910486"><a name="p1206164910486"></a><a name="p1206164910486"></a>() =&gt; void</p>
</td>
<td class="cellrowborder" valign="top" width="17.23%" headers="mcps1.1.5.1.3 "><p id="p112066492486"><a name="p112066492486"></a><a name="p112066492486"></a>页面创建完成</p>
</td>
<td class="cellrowborder" valign="top" width="37.6%" headers="mcps1.1.5.1.4 "><p id="p19206649154818"><a name="p19206649154818"></a><a name="p19206649154818"></a>页面创建完成时触发，只触发一次。</p>
</td>
</tr>
<tr id="row920615493488"><td class="cellrowborder" valign="top" width="22.12%" headers="mcps1.1.5.1.1 "><p id="p16206144911482"><a name="p16206144911482"></a><a name="p16206144911482"></a>onShow</p>
</td>
<td class="cellrowborder" valign="top" width="23.05%" headers="mcps1.1.5.1.2 "><p id="p1020619492480"><a name="p1020619492480"></a><a name="p1020619492480"></a>() =&gt; void</p>
</td>
<td class="cellrowborder" valign="top" width="17.23%" headers="mcps1.1.5.1.3 "><p id="p72061349164819"><a name="p72061349164819"></a><a name="p72061349164819"></a>页面显示</p>
</td>
<td class="cellrowborder" valign="top" width="37.6%" headers="mcps1.1.5.1.4 "><p id="p1920684934812"><a name="p1920684934812"></a><a name="p1920684934812"></a>页面显示时触发。</p>
</td>
</tr>
<tr id="row14207184919481"><td class="cellrowborder" valign="top" width="22.12%" headers="mcps1.1.5.1.1 "><p id="p1820694917488"><a name="p1820694917488"></a><a name="p1820694917488"></a>onHide</p>
</td>
<td class="cellrowborder" valign="top" width="23.05%" headers="mcps1.1.5.1.2 "><p id="p1720694914485"><a name="p1720694914485"></a><a name="p1720694914485"></a>() =&gt; void</p>
</td>
<td class="cellrowborder" valign="top" width="17.23%" headers="mcps1.1.5.1.3 "><p id="p10207144914813"><a name="p10207144914813"></a><a name="p10207144914813"></a>页面消失</p>
</td>
<td class="cellrowborder" valign="top" width="37.6%" headers="mcps1.1.5.1.4 "><p id="p1020724994815"><a name="p1020724994815"></a><a name="p1020724994815"></a>页面消失时触发。</p>
</td>
</tr>
<tr id="row11207194916482"><td class="cellrowborder" valign="top" width="22.12%" headers="mcps1.1.5.1.1 "><p id="p16207849204813"><a name="p16207849204813"></a><a name="p16207849204813"></a>onDestroy</p>
</td>
<td class="cellrowborder" valign="top" width="23.05%" headers="mcps1.1.5.1.2 "><p id="p102071490484"><a name="p102071490484"></a><a name="p102071490484"></a>() =&gt; void</p>
</td>
<td class="cellrowborder" valign="top" width="17.23%" headers="mcps1.1.5.1.3 "><p id="p1520744911486"><a name="p1520744911486"></a><a name="p1520744911486"></a>页面销毁</p>
</td>
<td class="cellrowborder" valign="top" width="37.6%" headers="mcps1.1.5.1.4 "><p id="p82071649104811"><a name="p82071649104811"></a><a name="p82071649104811"></a>页面销毁时触发。</p>
</td>
</tr>
<tr id="row192082496486"><td class="cellrowborder" valign="top" width="22.12%" headers="mcps1.1.5.1.1 "><p id="p1420710493489"><a name="p1420710493489"></a><a name="p1420710493489"></a>onBackPress</p>
</td>
<td class="cellrowborder" valign="top" width="23.05%" headers="mcps1.1.5.1.2 "><p id="p12207649174810"><a name="p12207649174810"></a><a name="p12207649174810"></a>() =&gt; boolean</p>
</td>
<td class="cellrowborder" valign="top" width="17.23%" headers="mcps1.1.5.1.3 "><p id="p14207249154815"><a name="p14207249154815"></a><a name="p14207249154815"></a>返回按钮动作</p>
</td>
<td class="cellrowborder" valign="top" width="37.6%" headers="mcps1.1.5.1.4 "><p id="p1020714916483"><a name="p1020714916483"></a><a name="p1020714916483"></a>当用户点击返回按钮时触发。</p>
<a name="ul02081949144816"></a><a name="ul02081949144816"></a><ul id="ul02081949144816"><li>返回true表示页面自己处理返回逻辑。</li><li>返回false表示使用默认的返回逻辑。</li><li>不返回值会作为false处理。</li></ul>
</td>
</tr>
<tr id="row8208174916489"><td class="cellrowborder" valign="top" width="22.12%" headers="mcps1.1.5.1.1 "><p id="p1920810495486"><a name="p1920810495486"></a><a name="p1920810495486"></a>onActive()<sup id="sup1920884964819"><a name="sup1920884964819"></a><a name="sup1920884964819"></a>5+</sup></p>
</td>
<td class="cellrowborder" valign="top" width="23.05%" headers="mcps1.1.5.1.2 "><p id="p92081349194817"><a name="p92081349194817"></a><a name="p92081349194817"></a>() =&gt; void</p>
</td>
<td class="cellrowborder" valign="top" width="17.23%" headers="mcps1.1.5.1.3 "><p id="p1320812492487"><a name="p1320812492487"></a><a name="p1320812492487"></a>页面激活</p>
</td>
<td class="cellrowborder" valign="top" width="37.6%" headers="mcps1.1.5.1.4 "><p id="p820834974814"><a name="p820834974814"></a><a name="p820834974814"></a>页面激活时触发。</p>
</td>
</tr>
<tr id="row92091549174812"><td class="cellrowborder" valign="top" width="22.12%" headers="mcps1.1.5.1.1 "><p id="p12084494487"><a name="p12084494487"></a><a name="p12084494487"></a>onInactive()<sup id="sup3208349144814"><a name="sup3208349144814"></a><a name="sup3208349144814"></a>5+</sup></p>
</td>
<td class="cellrowborder" valign="top" width="23.05%" headers="mcps1.1.5.1.2 "><p id="p1820854911485"><a name="p1820854911485"></a><a name="p1820854911485"></a>() =&gt; void</p>
</td>
<td class="cellrowborder" valign="top" width="17.23%" headers="mcps1.1.5.1.3 "><p id="p2209114954816"><a name="p2209114954816"></a><a name="p2209114954816"></a>页面暂停</p>
</td>
<td class="cellrowborder" valign="top" width="37.6%" headers="mcps1.1.5.1.4 "><p id="p1220944974811"><a name="p1220944974811"></a><a name="p1220944974811"></a>页面暂停时触发。</p>
</td>
</tr>
<tr id="row020918491481"><td class="cellrowborder" valign="top" width="22.12%" headers="mcps1.1.5.1.1 "><p id="p5209849124815"><a name="p5209849124815"></a><a name="p5209849124815"></a>onNewRequest()<sup id="sup32095496485"><a name="sup32095496485"></a><a name="sup32095496485"></a>5+</sup></p>
</td>
<td class="cellrowborder" valign="top" width="23.05%" headers="mcps1.1.5.1.2 "><p id="p22091849144815"><a name="p22091849144815"></a><a name="p22091849144815"></a>() =&gt; void</p>
</td>
<td class="cellrowborder" valign="top" width="17.23%" headers="mcps1.1.5.1.3 "><p id="p72091149134813"><a name="p72091149134813"></a><a name="p72091149134813"></a>FA重新请求</p>
</td>
<td class="cellrowborder" valign="top" width="37.6%" headers="mcps1.1.5.1.4 "><p id="p1920974974818"><a name="p1920974974818"></a><a name="p1920974974818"></a>FA已经启动时收到新的请求后触发。</p>
</td>
</tr>
</tbody>
</table>

页面A的生命周期接口的调用顺序

-   打开页面A：onInit\(\) -\> onReady\(\) -\> onShow\(\)
-   在页面A打开页面B：onHide\(\)
-   从页面B返回页面A：onShow\(\)
-   退出页面A：onBackPress\(\) -\> onHide\(\) -\> onDestroy\(\)
-   页面隐藏到后台运行：onInactive\(\) -\> onHide\(\)
-   页面从后台运行恢复到前台：onShow\(\) -\> onActive\(\)

![](figures/zh-cn_image_0000001147417424.png)

