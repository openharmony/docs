# OHOS::UIYAxis<a name="ZH-CN_TOPIC_0000001054879554"></a>

-   [Overview](#section1358605286165634)
-   [Summary](#section1354342696165634)
-   [Public Member Functions](#pub-methods)
-   [Additional Inherited Members](#inherited)

## **Overview**<a name="section1358605286165634"></a>

**Related Modules:**

[Graphic](Graphic.md)

**Description:**

Defines the unique attributes and functions for the y-axis. This class is used in  [UIChart](OHOS-UIChart.md). 

See also
:   [UIAxis](OHOS-UIAxis.md) 

**Since:**

1.0

**Version:**

1.0

## **Summary**<a name="section1354342696165634"></a>

## Public Member Functions<a name="pub-methods"></a>

<a name="table1319278037165634"></a>
<table><thead align="left"><tr id="row1609323627165634"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1697702007165634"><a name="p1697702007165634"></a><a name="p1697702007165634"></a>Function</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p325819850165634"><a name="p325819850165634"></a><a name="p325819850165634"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1590979951165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p925238957165634"><a name="p925238957165634"></a><a name="p925238957165634"></a><a href="Graphic.md#ga0f9a52b48bcd8170b4a64a891a88fb5c">UIYAxis</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p600638650165634"><a name="p600638650165634"></a><a name="p600638650165634"></a> </p>
<p id="p422509849165634"><a name="p422509849165634"></a><a name="p422509849165634"></a>A constructor used to create a <strong id="b436446671165634"><a name="b436446671165634"></a><a name="b436446671165634"></a><a href="OHOS-UIYAxis.md">UIYAxis</a></strong> instance. </p>
</td>
</tr>
<tr id="row1943978676165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1510542075165634"><a name="p1510542075165634"></a><a name="p1510542075165634"></a><a href="Graphic.md#ga0dc204e8a15fa66762af58142552557c">~UIYAxis</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1642436509165634"><a name="p1642436509165634"></a><a name="p1642436509165634"></a>virtual </p>
<p id="p1522828366165634"><a name="p1522828366165634"></a><a name="p1522828366165634"></a>A destructor used to delete the <strong id="b1781026216165634"><a name="b1781026216165634"></a><a name="b1781026216165634"></a><a href="OHOS-UIYAxis.md">UIYAxis</a></strong> instance. </p>
</td>
</tr>
<tr id="row191501393165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p901791928165634"><a name="p901791928165634"></a><a name="p901791928165634"></a><a href="Graphic.md#gae70c8c411116746a2ab73a6f9bbd1233">TranslateToPixel</a> (int16_t &amp;value) override</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1215650374165634"><a name="p1215650374165634"></a><a name="p1215650374165634"></a>void </p>
<p id="p1074765067165634"><a name="p1074765067165634"></a><a name="p1074765067165634"></a>Translates data into the y coordinate of a pixel. </p>
</td>
</tr>
<tr id="row824212867165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p142329146165634"><a name="p142329146165634"></a><a name="p142329146165634"></a><a href="Graphic.md#gae635d27e0a4eba30002e3607c42b914a">SetDataRange</a> (uint16_t min, uint16_t max) override</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1628213426165634"><a name="p1628213426165634"></a><a name="p1628213426165634"></a>bool </p>
<p id="p351604435165634"><a name="p351604435165634"></a><a name="p351604435165634"></a>Sets the value range of the y-axis. </p>
</td>
</tr>
<tr id="row400998330165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1766217264165634"><a name="p1766217264165634"></a><a name="p1766217264165634"></a><a href="Graphic.md#gaf67c1b25c1d1a3ba694cb47f7e9fda85">SetMarkNum</a> (uint16_t count) override</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p176512981165634"><a name="p176512981165634"></a><a name="p176512981165634"></a>void </p>
<p id="p1410157354165634"><a name="p1410157354165634"></a><a name="p1410157354165634"></a>Sets the number of scales on the Y axis. </p>
</td>
</tr>
<tr id="row1073324154165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1108252504165634"><a name="p1108252504165634"></a><a name="p1108252504165634"></a><a href="Graphic.md#gad79f1c694abce57af451b8f7b0b17c35">UIAxis</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1715479873165634"><a name="p1715479873165634"></a><a name="p1715479873165634"></a> </p>
<p id="p831003108165634"><a name="p831003108165634"></a><a name="p831003108165634"></a>A constructor used to create a <strong id="b572794130165634"><a name="b572794130165634"></a><a name="b572794130165634"></a><a href="OHOS-UIAxis.md">UIAxis</a></strong> instance. </p>
</td>
</tr>
<tr id="row142992077165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1257440548165634"><a name="p1257440548165634"></a><a name="p1257440548165634"></a><a href="Graphic.md#gaacc9ac178b3b235f1186297021eb98d8">~UIAxis</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p434128547165634"><a name="p434128547165634"></a><a name="p434128547165634"></a>virtual </p>
<p id="p604983607165634"><a name="p604983607165634"></a><a name="p604983607165634"></a>A destructor used to delete the <strong id="b29164433165634"><a name="b29164433165634"></a><a name="b29164433165634"></a><a href="OHOS-UIAxis.md">UIAxis</a></strong> instance. </p>
</td>
</tr>
<tr id="row1487340631165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1165317992165634"><a name="p1165317992165634"></a><a name="p1165317992165634"></a><a href="Graphic.md#ga2f46b702f1543c5076a8957a94a780d3">GetViewType</a> () const override</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1821004710165634"><a name="p1821004710165634"></a><a name="p1821004710165634"></a>UIViewType </p>
<p id="p692598599165634"><a name="p692598599165634"></a><a name="p692598599165634"></a>Obtains the view type. </p>
</td>
</tr>
<tr id="row2097692116165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1083485744165634"><a name="p1083485744165634"></a><a name="p1083485744165634"></a><a href="Graphic.md#ga8ceec5e67fa2c4f161bd9af1f0788bbe">SetLineColor</a> (const <a href="OHOS-Color32.md">ColorType</a> &amp;color)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p795053987165634"><a name="p795053987165634"></a><a name="p795053987165634"></a>void </p>
<p id="p2006687271165634"><a name="p2006687271165634"></a><a name="p2006687271165634"></a>Sets the line color of the coordinate axis. </p>
</td>
</tr>
<tr id="row1452898135165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p236960785165634"><a name="p236960785165634"></a><a name="p236960785165634"></a><a href="Graphic.md#ga5360803f425055de52af5f7fa1081cfe">OnDraw</a> (const <a href="OHOS-Rect.md">Rect</a> &amp;invalidatedArea) override</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p178163306165634"><a name="p178163306165634"></a><a name="p178163306165634"></a>void </p>
<p id="p1517247351165634"><a name="p1517247351165634"></a><a name="p1517247351165634"></a>Called when a view is drawn. </p>
</td>
</tr>
<tr id="row1093342265165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1112094444165634"><a name="p1112094444165634"></a><a name="p1112094444165634"></a><a href="Graphic.md#gad1bf4d83270c0a4ba04f3cffbc67bb97">OnPreDraw</a> (const <a href="OHOS-Rect.md">Rect</a> &amp;invalidatedArea) override</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1410338912165634"><a name="p1410338912165634"></a><a name="p1410338912165634"></a>bool </p>
<p id="p982623463165634"><a name="p982623463165634"></a><a name="p982623463165634"></a>Called before a view is drawn. This function is used to check whether the parent view of this view needs to be redrawn so as to optimize the drawing process. </p>
</td>
</tr>
<tr id="row224748711165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p483761556165634"><a name="p483761556165634"></a><a name="p483761556165634"></a><a href="Graphic.md#gadae043c6d43d5436ec0374e5d128c654">UIViewGroup</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1845115639165634"><a name="p1845115639165634"></a><a name="p1845115639165634"></a> </p>
<p id="p292050627165634"><a name="p292050627165634"></a><a name="p292050627165634"></a>A default constructor used to create a <strong id="b403042441165634"><a name="b403042441165634"></a><a name="b403042441165634"></a><a href="OHOS-UIViewGroup.md">UIViewGroup</a></strong> instance. </p>
</td>
</tr>
<tr id="row2004622783165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1222606622165634"><a name="p1222606622165634"></a><a name="p1222606622165634"></a><a href="Graphic.md#ga19ec065bd41a01f0925a4a9ffa450d1c">~UIViewGroup</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p390754339165634"><a name="p390754339165634"></a><a name="p390754339165634"></a>virtual </p>
<p id="p973755352165634"><a name="p973755352165634"></a><a name="p973755352165634"></a>A destructor used to delete the <strong id="b989760026165634"><a name="b989760026165634"></a><a name="b989760026165634"></a><a href="OHOS-UIViewGroup.md">UIViewGroup</a></strong> instance. </p>
</td>
</tr>
<tr id="row1121039723165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1242323017165634"><a name="p1242323017165634"></a><a name="p1242323017165634"></a><a href="Graphic.md#gad5756764839a844ee9bee0c186798029">GetViewType</a> () const override</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1759673218165634"><a name="p1759673218165634"></a><a name="p1759673218165634"></a>UIViewType </p>
<p id="p222505028165634"><a name="p222505028165634"></a><a name="p222505028165634"></a>Obtains the view type. </p>
</td>
</tr>
<tr id="row1343819339165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p860023429165634"><a name="p860023429165634"></a><a name="p860023429165634"></a><a href="Graphic.md#gacf5db120308ac7783c493f5437f06cee">Add</a> (<a href="OHOS-UIView.md">UIView</a> *view)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1840124839165634"><a name="p1840124839165634"></a><a name="p1840124839165634"></a>virtual void </p>
<p id="p523818652165634"><a name="p523818652165634"></a><a name="p523818652165634"></a>Adds a child view. </p>
</td>
</tr>
<tr id="row603289217165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1522899029165634"><a name="p1522899029165634"></a><a name="p1522899029165634"></a><a href="Graphic.md#ga84195a993bfe50d8302435ababb63966">Insert</a> (<a href="OHOS-UIView.md">UIView</a> *prevView, <a href="OHOS-UIView.md">UIView</a> *insertView)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1852057451165634"><a name="p1852057451165634"></a><a name="p1852057451165634"></a>virtual void </p>
<p id="p2119780407165634"><a name="p2119780407165634"></a><a name="p2119780407165634"></a>Inserts a new child view behind the current one. </p>
</td>
</tr>
<tr id="row1614163164165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p850440772165634"><a name="p850440772165634"></a><a name="p850440772165634"></a><a href="Graphic.md#ga25523928b24d6692f18aed31edb07006">Remove</a> (<a href="OHOS-UIView.md">UIView</a> *view)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1761536861165634"><a name="p1761536861165634"></a><a name="p1761536861165634"></a>virtual void </p>
<p id="p1137723286165634"><a name="p1137723286165634"></a><a name="p1137723286165634"></a>Removes a child view. </p>
</td>
</tr>
<tr id="row1581670928165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p162761134165634"><a name="p162761134165634"></a><a name="p162761134165634"></a><a href="Graphic.md#gaf3ee08173d92932687809049e3c11e9b">RemoveAll</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p377827363165634"><a name="p377827363165634"></a><a name="p377827363165634"></a>virtual void </p>
<p id="p1328998621165634"><a name="p1328998621165634"></a><a name="p1328998621165634"></a>Removes all child views. </p>
</td>
</tr>
<tr id="row545046504165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1821058673165634"><a name="p1821058673165634"></a><a name="p1821058673165634"></a><a href="Graphic.md#ga7ea54fc6ef3a8b7dec1bf88ab189f7c7">GetTargetView</a> (const <a href="OHOS-Point.md">Point</a> &amp;point, <a href="OHOS-UIView.md">UIView</a> **last) override</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1093596007165634"><a name="p1093596007165634"></a><a name="p1093596007165634"></a>virtual void </p>
<p id="p578674314165634"><a name="p578674314165634"></a><a name="p578674314165634"></a>Obtains the target child view that is visible and can respond to touch events based on given coordinates. </p>
</td>
</tr>
<tr id="row1372359113165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1501912464165634"><a name="p1501912464165634"></a><a name="p1501912464165634"></a><a href="Graphic.md#ga776c6c1640cb88b537af227fa5eb0725">MoveChildByOffset</a> (int16_t x, int16_t y)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p603817458165634"><a name="p603817458165634"></a><a name="p603817458165634"></a>virtual void </p>
<p id="p91558875165634"><a name="p91558875165634"></a><a name="p91558875165634"></a>Moves all child views. </p>
</td>
</tr>
<tr id="row1983156640165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1729473563165634"><a name="p1729473563165634"></a><a name="p1729473563165634"></a><a href="Graphic.md#ga6fed8238b89b013552c5a247aa2471df">GetChildrenHead</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1825817739165634"><a name="p1825817739165634"></a><a name="p1825817739165634"></a><a href="OHOS-UIView.md">UIView</a> * </p>
<p id="p286910180165634"><a name="p286910180165634"></a><a name="p286910180165634"></a>Obtains the first child view in this view group. </p>
</td>
</tr>
<tr id="row2060306711165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p589963350165634"><a name="p589963350165634"></a><a name="p589963350165634"></a><a href="Graphic.md#ga1361baa76fbabd2fc81cc249c6868691">GetChildrenTail</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p976431771165634"><a name="p976431771165634"></a><a name="p976431771165634"></a><a href="OHOS-UIView.md">UIView</a> * </p>
<p id="p1165223967165634"><a name="p1165223967165634"></a><a name="p1165223967165634"></a>Obtains the last child view in this view group. </p>
</td>
</tr>
<tr id="row1147509504165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1139534050165634"><a name="p1139534050165634"></a><a name="p1139534050165634"></a><a href="Graphic.md#gad53c52e619a54358a413a836ae0c1861">SetDisallowIntercept</a> (bool flag)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p271932831165634"><a name="p271932831165634"></a><a name="p271932831165634"></a>void </p>
<p id="p1147742550165634"><a name="p1147742550165634"></a><a name="p1147742550165634"></a>Sets whether this view group is intercepted upon touch events. </p>
</td>
</tr>
<tr id="row371849873165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2006812737165634"><a name="p2006812737165634"></a><a name="p2006812737165634"></a><a href="Graphic.md#gae9f6ddb5819392546463d6371147c486">GetChildById</a> (const char *id) const override</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p399762069165634"><a name="p399762069165634"></a><a name="p399762069165634"></a><a href="OHOS-UIView.md">UIView</a> * </p>
<p id="p1647850064165634"><a name="p1647850064165634"></a><a name="p1647850064165634"></a>Obtains the target child view with a specified ID. </p>
</td>
</tr>
<tr id="row2117265481165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p177058102165634"><a name="p177058102165634"></a><a name="p177058102165634"></a><a href="Graphic.md#ga6442ba36114d739df1b17ca8943cc087">SetAutoSize</a> (bool state)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1357867626165634"><a name="p1357867626165634"></a><a name="p1357867626165634"></a>void </p>
<p id="p601234619165634"><a name="p601234619165634"></a><a name="p601234619165634"></a>Sets whether the size of this view group is adaptive to that of all child views. </p>
</td>
</tr>
<tr id="row1122076657165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1763992411165634"><a name="p1763992411165634"></a><a name="p1763992411165634"></a><a href="Graphic.md#ga7aad5b50d945efe5f9304bc978b2001c">UIView</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p644427621165634"><a name="p644427621165634"></a><a name="p644427621165634"></a> </p>
<p id="p2003114398165634"><a name="p2003114398165634"></a><a name="p2003114398165634"></a>A default constructor used to create an <strong id="b595974258165634"><a name="b595974258165634"></a><a name="b595974258165634"></a><a href="OHOS-UIView.md">UIView</a></strong> instance. </p>
</td>
</tr>
<tr id="row867068538165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1591593448165634"><a name="p1591593448165634"></a><a name="p1591593448165634"></a><a href="Graphic.md#ga57d429bb1cd71782f3b825f1bc6b9362">UIView</a> (const char *id)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1476069287165634"><a name="p1476069287165634"></a><a name="p1476069287165634"></a> </p>
<p id="p1737353269165634"><a name="p1737353269165634"></a><a name="p1737353269165634"></a>A constructor used to create an <strong id="b337564961165634"><a name="b337564961165634"></a><a name="b337564961165634"></a><a href="OHOS-UIView.md">UIView</a></strong> instance. </p>
</td>
</tr>
<tr id="row460826276165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p934253392165634"><a name="p934253392165634"></a><a name="p934253392165634"></a><a href="Graphic.md#ga17f0ffc1090bdcce0f88288da5962012">~UIView</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p46673093165634"><a name="p46673093165634"></a><a name="p46673093165634"></a>virtual </p>
<p id="p1833570573165634"><a name="p1833570573165634"></a><a name="p1833570573165634"></a>A destructor used to delete the <strong id="b1862364028165634"><a name="b1862364028165634"></a><a name="b1862364028165634"></a><a href="OHOS-UIView.md">UIView</a></strong> instance. </p>
</td>
</tr>
<tr id="row1414626749165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p343048922165634"><a name="p343048922165634"></a><a name="p343048922165634"></a><a href="Graphic.md#gab70473cd0d8fe7c9d4bb817caeee9153">OnPostDraw</a> (const <a href="OHOS-Rect.md">Rect</a> &amp;invalidatedArea)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1822676769165634"><a name="p1822676769165634"></a><a name="p1822676769165634"></a>virtual void </p>
<p id="p278277837165634"><a name="p278277837165634"></a><a name="p278277837165634"></a>Called after a view is drawn. </p>
</td>
</tr>
<tr id="row1656449394165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1219756545165634"><a name="p1219756545165634"></a><a name="p1219756545165634"></a><a href="Graphic.md#ga81726238adeda1efa989be6ed4f4fe5b">ReMeasure</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1624898135165634"><a name="p1624898135165634"></a><a name="p1624898135165634"></a>virtual void </p>
<p id="p1097952711165634"><a name="p1097952711165634"></a><a name="p1097952711165634"></a>Remeasures the view size. </p>
</td>
</tr>
<tr id="row66793133165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1567857767165634"><a name="p1567857767165634"></a><a name="p1567857767165634"></a><a href="Graphic.md#ga2a9a38b8450fbb196277238a51fbbf99">Invalidate</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1801835430165634"><a name="p1801835430165634"></a><a name="p1801835430165634"></a>void </p>
<p id="p1952408197165634"><a name="p1952408197165634"></a><a name="p1952408197165634"></a>Refreshes the invalidated area of the view. </p>
</td>
</tr>
<tr id="row1096702763165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1775072627165634"><a name="p1775072627165634"></a><a name="p1775072627165634"></a><a href="Graphic.md#gaf0e6b65ced8b931642f2a80c195962d2">InvalidateRect</a> (const <a href="OHOS-Rect.md">Rect</a> &amp;invalidatedArea)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1180094521165634"><a name="p1180094521165634"></a><a name="p1180094521165634"></a>void </p>
<p id="p1272670015165634"><a name="p1272670015165634"></a><a name="p1272670015165634"></a>Refreshes a view in a specified invalidated area. </p>
</td>
</tr>
<tr id="row1799070456165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p137968999165634"><a name="p137968999165634"></a><a name="p137968999165634"></a><a href="Graphic.md#gac311aa47301d727c35fc31f8630d016e">OnLongPressEvent</a> (const <a href="OHOS-LongPressEvent.md">LongPressEvent</a> &amp;event)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1493489706165634"><a name="p1493489706165634"></a><a name="p1493489706165634"></a>virtual bool </p>
<p id="p414218642165634"><a name="p414218642165634"></a><a name="p414218642165634"></a>Called when the view is long pressed. </p>
</td>
</tr>
<tr id="row631766337165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1578081148165634"><a name="p1578081148165634"></a><a name="p1578081148165634"></a><a href="Graphic.md#gac0e10556ff99b8a92bfb11df6456d605">OnDragStartEvent</a> (const <a href="OHOS-DragEvent.md">DragEvent</a> &amp;event)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1382886097165634"><a name="p1382886097165634"></a><a name="p1382886097165634"></a>virtual bool </p>
<p id="p1129123971165634"><a name="p1129123971165634"></a><a name="p1129123971165634"></a>Called when the view starts to drag. </p>
</td>
</tr>
<tr id="row37646893165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p579156659165634"><a name="p579156659165634"></a><a name="p579156659165634"></a><a href="Graphic.md#ga46249c8caf06b81590d9450e30a31147">OnDragEvent</a> (const <a href="OHOS-DragEvent.md">DragEvent</a> &amp;event)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1587459074165634"><a name="p1587459074165634"></a><a name="p1587459074165634"></a>virtual bool </p>
<p id="p1716651077165634"><a name="p1716651077165634"></a><a name="p1716651077165634"></a>Called when the view is being dragged. </p>
</td>
</tr>
<tr id="row542575869165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1331383763165634"><a name="p1331383763165634"></a><a name="p1331383763165634"></a><a href="Graphic.md#ga1799d33be73f64ed2066f50d7e65468d">OnDragEndEvent</a> (const <a href="OHOS-DragEvent.md">DragEvent</a> &amp;event)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p825182806165634"><a name="p825182806165634"></a><a name="p825182806165634"></a>virtual bool </p>
<p id="p1745852806165634"><a name="p1745852806165634"></a><a name="p1745852806165634"></a>Called when the view stops dragging. </p>
</td>
</tr>
<tr id="row1733912922165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p607611768165634"><a name="p607611768165634"></a><a name="p607611768165634"></a><a href="Graphic.md#gad08697a29aae4c58267f494b66b9a547">OnClickEvent</a> (const <a href="OHOS-ClickEvent.md">ClickEvent</a> &amp;event)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1555834850165634"><a name="p1555834850165634"></a><a name="p1555834850165634"></a>virtual void </p>
<p id="p887834600165634"><a name="p887834600165634"></a><a name="p887834600165634"></a>Called when the view is clicked. </p>
</td>
</tr>
<tr id="row1188632671165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1971903653165634"><a name="p1971903653165634"></a><a name="p1971903653165634"></a><a href="Graphic.md#gafa544ff2d27785a9410a80689f1ad3b1">OnPressEvent</a> (const <a href="OHOS-PressEvent.md">PressEvent</a> &amp;event)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1814457885165634"><a name="p1814457885165634"></a><a name="p1814457885165634"></a>virtual void </p>
<p id="p1757390039165634"><a name="p1757390039165634"></a><a name="p1757390039165634"></a>Called when the view is pressed. </p>
</td>
</tr>
<tr id="row2021228716165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1394395340165634"><a name="p1394395340165634"></a><a name="p1394395340165634"></a><a href="Graphic.md#ga7bd1a74563b059b03fbf66f9add53ee3">OnReleaseEvent</a> (const <a href="OHOS-ReleaseEvent.md">ReleaseEvent</a> &amp;event)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p103280983165634"><a name="p103280983165634"></a><a name="p103280983165634"></a>virtual void </p>
<p id="p1854870255165634"><a name="p1854870255165634"></a><a name="p1854870255165634"></a>Called when the view is released. </p>
</td>
</tr>
<tr id="row835095497165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p116424091165634"><a name="p116424091165634"></a><a name="p116424091165634"></a><a href="Graphic.md#ga8f01ff25a33b20df0758f564148e579d">OnCancelEvent</a> (const <a href="OHOS-CancelEvent.md">CancelEvent</a> &amp;event)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1847946949165634"><a name="p1847946949165634"></a><a name="p1847946949165634"></a>virtual void </p>
<p id="p1343487371165634"><a name="p1343487371165634"></a><a name="p1343487371165634"></a>Called when a click event on the view is canceled. </p>
</td>
</tr>
<tr id="row464384825165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p995218717165634"><a name="p995218717165634"></a><a name="p995218717165634"></a><a href="Graphic.md#gad8e3cf5f0dd003a6aa932ef04e7b59f2">SetOnDragListener</a> (<a href="OHOS-UIView-OnDragListener.md">OnDragListener</a> *onDragListener)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p610699152165634"><a name="p610699152165634"></a><a name="p610699152165634"></a>void </p>
<p id="p1756241063165634"><a name="p1756241063165634"></a><a name="p1756241063165634"></a>Sets a drag event listener for the view. </p>
</td>
</tr>
<tr id="row153055806165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2054207936165634"><a name="p2054207936165634"></a><a name="p2054207936165634"></a><a href="Graphic.md#ga45a02cba4887c5c0b8e243941bcdc5cb">GetOnDragListener</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2095852412165634"><a name="p2095852412165634"></a><a name="p2095852412165634"></a><a href="OHOS-UIView-OnDragListener.md">OnDragListener</a> *&amp; </p>
<p id="p2528349165634"><a name="p2528349165634"></a><a name="p2528349165634"></a>Obtains the drag event listener for the view. </p>
</td>
</tr>
<tr id="row1324974719165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p980983683165634"><a name="p980983683165634"></a><a name="p980983683165634"></a><a href="Graphic.md#ga4564bf8d8c7184e9c02bf33c9e171fa3">SetOnClickListener</a> (<a href="OHOS-UIView-OnClickListener.md">OnClickListener</a> *onClickListener)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p733762541165634"><a name="p733762541165634"></a><a name="p733762541165634"></a>void </p>
<p id="p478125797165634"><a name="p478125797165634"></a><a name="p478125797165634"></a>Sets a click event listener for the view. </p>
</td>
</tr>
<tr id="row1222782314165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p698460950165634"><a name="p698460950165634"></a><a name="p698460950165634"></a><a href="Graphic.md#ga35e885cb380c37245fa4305bba10cd4a">GetOnClickListener</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1390327148165634"><a name="p1390327148165634"></a><a name="p1390327148165634"></a><a href="OHOS-UIView-OnClickListener.md">OnClickListener</a> *&amp; </p>
<p id="p325246889165634"><a name="p325246889165634"></a><a name="p325246889165634"></a>Obtains the click event listener for the view. </p>
</td>
</tr>
<tr id="row553903905165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p335432804165634"><a name="p335432804165634"></a><a name="p335432804165634"></a><a href="Graphic.md#gabcbe7a0adce600424f7f0d5a7396eb5b">SetOnLongPressListener</a> (<a href="OHOS-UIView-OnLongPressListener.md">OnLongPressListener</a> *onLongPressListener)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p748702950165634"><a name="p748702950165634"></a><a name="p748702950165634"></a>void </p>
<p id="p180017859165634"><a name="p180017859165634"></a><a name="p180017859165634"></a>Sets a long-press event listener for the view. </p>
</td>
</tr>
<tr id="row473236076165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p37564084165634"><a name="p37564084165634"></a><a name="p37564084165634"></a><a href="Graphic.md#gaafd4d354f5f111e758d046109fd7f656">GetOnLongPressListener</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p857351053165634"><a name="p857351053165634"></a><a name="p857351053165634"></a><a href="OHOS-UIView-OnLongPressListener.md">OnLongPressListener</a> *&amp; </p>
<p id="p1221071918165634"><a name="p1221071918165634"></a><a name="p1221071918165634"></a>Obtains the long-press event listener for the view. </p>
</td>
</tr>
<tr id="row141126447165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1045654952165634"><a name="p1045654952165634"></a><a name="p1045654952165634"></a><a href="Graphic.md#gadd697fbf481f98d9d6ca8b67390071af">SetOnTouchListener</a> (<a href="OHOS-UIView-OnTouchListener.md">OnTouchListener</a> *onTouchListener)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1115323219165634"><a name="p1115323219165634"></a><a name="p1115323219165634"></a>void </p>
<p id="p368815993165634"><a name="p368815993165634"></a><a name="p368815993165634"></a>Sets a touch event listener for the view. </p>
</td>
</tr>
<tr id="row660724570165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1841541961165634"><a name="p1841541961165634"></a><a name="p1841541961165634"></a><a href="Graphic.md#gae7c65c68653103dae85acdcef78777a6">GetTouchListener</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p580731707165634"><a name="p580731707165634"></a><a name="p580731707165634"></a><a href="OHOS-UIView-OnTouchListener.md">OnTouchListener</a> *&amp; </p>
<p id="p207918630165634"><a name="p207918630165634"></a><a name="p207918630165634"></a>Obtains the touch event listener for the view. </p>
</td>
</tr>
<tr id="row612705024165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1540178721165634"><a name="p1540178721165634"></a><a name="p1540178721165634"></a><a href="Graphic.md#gaeea67a3a84b4ffe9bfeda418b82184cc">SetParent</a> (<a href="OHOS-UIView.md">UIView</a> *parent)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1918033795165634"><a name="p1918033795165634"></a><a name="p1918033795165634"></a>void </p>
<p id="p602781695165634"><a name="p602781695165634"></a><a name="p602781695165634"></a>Sets the parent view for the view. </p>
</td>
</tr>
<tr id="row620311438165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1833670568165634"><a name="p1833670568165634"></a><a name="p1833670568165634"></a><a href="Graphic.md#ga706530e4a38108615d5e0c918685ec96">GetParent</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1661505842165634"><a name="p1661505842165634"></a><a name="p1661505842165634"></a><a href="OHOS-UIView.md">UIView</a> * </p>
<p id="p2000849672165634"><a name="p2000849672165634"></a><a name="p2000849672165634"></a>Obtains the parent view of the view. </p>
</td>
</tr>
<tr id="row1177745384165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1440152614165634"><a name="p1440152614165634"></a><a name="p1440152614165634"></a><a href="Graphic.md#ga02bec5de07d93cabc45affba79eba4ad">SetNextSibling</a> (<a href="OHOS-UIView.md">UIView</a> *sibling)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1610398218165634"><a name="p1610398218165634"></a><a name="p1610398218165634"></a>void </p>
<p id="p1035028193165634"><a name="p1035028193165634"></a><a name="p1035028193165634"></a>Sets the next sibling view for the view. </p>
</td>
</tr>
<tr id="row1945476015165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1160345526165634"><a name="p1160345526165634"></a><a name="p1160345526165634"></a><a href="Graphic.md#gab0030977b30ddc9f2e15dbc2f58937e6">GetNextSibling</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p890548904165634"><a name="p890548904165634"></a><a name="p890548904165634"></a><a href="OHOS-UIView.md">UIView</a> * </p>
<p id="p1570373838165634"><a name="p1570373838165634"></a><a name="p1570373838165634"></a>Obtains the next sibling view of the view. </p>
</td>
</tr>
<tr id="row1843660660165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1983504884165634"><a name="p1983504884165634"></a><a name="p1983504884165634"></a><a href="Graphic.md#ga07e7e1f268bd6ce975f4f0f8487af5d0">SetVisible</a> (bool visible)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p365339072165634"><a name="p365339072165634"></a><a name="p365339072165634"></a>virtual void </p>
<p id="p1023008215165634"><a name="p1023008215165634"></a><a name="p1023008215165634"></a>Sets whether the view is visible. </p>
</td>
</tr>
<tr id="row820006828165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2131692263165634"><a name="p2131692263165634"></a><a name="p2131692263165634"></a><a href="Graphic.md#gaee178fc0a86ac03a6bdf2ade0c1914c8">IsVisible</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1817885238165634"><a name="p1817885238165634"></a><a name="p1817885238165634"></a>bool </p>
<p id="p1860009084165634"><a name="p1860009084165634"></a><a name="p1860009084165634"></a>Checks whether the view is visible. </p>
</td>
</tr>
<tr id="row1336170676165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1332379726165634"><a name="p1332379726165634"></a><a name="p1332379726165634"></a><a href="Graphic.md#gaf9fb55fd9aa397f7158f1515e90bce02">SetTouchable</a> (bool touch)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1797888165634"><a name="p1797888165634"></a><a name="p1797888165634"></a>void </p>
<p id="p732958906165634"><a name="p732958906165634"></a><a name="p732958906165634"></a>Sets whether the view is touchable. </p>
</td>
</tr>
<tr id="row1876704042165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1474962975165634"><a name="p1474962975165634"></a><a name="p1474962975165634"></a><a href="Graphic.md#ga502a53fb77b260fa36b5b3adf82e2340">IsTouchable</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2064357194165634"><a name="p2064357194165634"></a><a name="p2064357194165634"></a>bool </p>
<p id="p1764212885165634"><a name="p1764212885165634"></a><a name="p1764212885165634"></a>Checks whether the view is touchable. </p>
</td>
</tr>
<tr id="row75095062165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p986473273165634"><a name="p986473273165634"></a><a name="p986473273165634"></a><a href="Graphic.md#gab06abe0fe824c048f3b72974f9a8f0d0">SetDraggable</a> (bool draggable)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1824749951165634"><a name="p1824749951165634"></a><a name="p1824749951165634"></a>void </p>
<p id="p1031082293165634"><a name="p1031082293165634"></a><a name="p1031082293165634"></a>Sets whether the view is draggable. </p>
</td>
</tr>
<tr id="row1125914703165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1139480874165634"><a name="p1139480874165634"></a><a name="p1139480874165634"></a><a href="Graphic.md#ga25bb796ff400c767d622cbed280fc500">IsDraggable</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p825458776165634"><a name="p825458776165634"></a><a name="p825458776165634"></a>bool </p>
<p id="p1540928252165634"><a name="p1540928252165634"></a><a name="p1540928252165634"></a>Checks whether the view is draggable. </p>
</td>
</tr>
<tr id="row606302111165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1807294771165634"><a name="p1807294771165634"></a><a name="p1807294771165634"></a><a href="Graphic.md#ga6c08e49bf7a82a7ebaef0f251e7a6f85">SetDragParentInstead</a> (bool dragParentInstead)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2063417495165634"><a name="p2063417495165634"></a><a name="p2063417495165634"></a>void </p>
<p id="p538433942165634"><a name="p538433942165634"></a><a name="p538433942165634"></a>Sets whether to transfer the drag event to the parent view for processing when the view is being dragged. </p>
</td>
</tr>
<tr id="row681769271165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p245351001165634"><a name="p245351001165634"></a><a name="p245351001165634"></a><a href="Graphic.md#gaf0c462bc31e779b1898ad4cdfdad6faf">IsDragParentInstead</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1085138306165634"><a name="p1085138306165634"></a><a name="p1085138306165634"></a>bool </p>
<p id="p1710980719165634"><a name="p1710980719165634"></a><a name="p1710980719165634"></a>Obtains whether the view transfers a drag event to the parent view for processing. </p>
</td>
</tr>
<tr id="row1224505715165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1805990868165634"><a name="p1805990868165634"></a><a name="p1805990868165634"></a><a href="Graphic.md#ga86cb8d364f18494d67636c55babced5c">GetRect</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1504915779165634"><a name="p1504915779165634"></a><a name="p1504915779165634"></a><a href="OHOS-Rect.md">Rect</a> </p>
<p id="p968920237165634"><a name="p968920237165634"></a><a name="p968920237165634"></a>Obtains the absolute rectangle area of the view. When the view has deformation such as rotation, the rectangle area is the intersection set of the absolute rectangle area and deformation matrix. </p>
</td>
</tr>
<tr id="row1732309792165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1875579176165634"><a name="p1875579176165634"></a><a name="p1875579176165634"></a><a href="Graphic.md#ga06e79704a19f2a238982076cac3d059b">GetVisibleRect</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p692164408165634"><a name="p692164408165634"></a><a name="p692164408165634"></a><a href="OHOS-Rect.md">Rect</a> </p>
<p id="p1877142290165634"><a name="p1877142290165634"></a><a name="p1877142290165634"></a>Obtains the visible absolute rectangle area of the view. </p>
</td>
</tr>
<tr id="row134322850165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1084557024165634"><a name="p1084557024165634"></a><a name="p1084557024165634"></a><a href="Graphic.md#gab3f8993b3953f27bfc61d53429916cba">GetMaskedRect</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p758355355165634"><a name="p758355355165634"></a><a name="p758355355165634"></a><a href="OHOS-Rect.md">Rect</a> </p>
<p id="p1939672469165634"><a name="p1939672469165634"></a><a name="p1939672469165634"></a>Obtains the valid absolute rectangle area of the view. The valid area refers to the area where the view can be displayed. Generally, the valid area is the same as the visible view area, but they may be different in the grid layout. </p>
</td>
</tr>
<tr id="row312621984165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1436483808165634"><a name="p1436483808165634"></a><a name="p1436483808165634"></a><a href="Graphic.md#ga64cf308a09999def1192f9c4e0f17f0a">GetOrigRect</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p717841416165634"><a name="p717841416165634"></a><a name="p717841416165634"></a><a href="OHOS-Rect.md">Rect</a> </p>
<p id="p1527379351165634"><a name="p1527379351165634"></a><a name="p1527379351165634"></a>Obtains the absolute rectangle area of the view. </p>
</td>
</tr>
<tr id="row818557817165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p397821142165634"><a name="p397821142165634"></a><a name="p397821142165634"></a><a href="Graphic.md#ga9db88eae712676359d02a92be14fa316">GetContentRect</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p870543160165634"><a name="p870543160165634"></a><a name="p870543160165634"></a>virtual <a href="OHOS-Rect.md">Rect</a> </p>
<p id="p962168319165634"><a name="p962168319165634"></a><a name="p962168319165634"></a>Obtains the content of the absolute rectangle area of the view. This area excludes padding. </p>
</td>
</tr>
<tr id="row100550583165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p909401637165634"><a name="p909401637165634"></a><a name="p909401637165634"></a><a href="Graphic.md#gae9b96837fa1d45648a2a6fbbfcc5eb4a">GetRelativeRect</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p230472426165634"><a name="p230472426165634"></a><a name="p230472426165634"></a><a href="OHOS-Rect.md">Rect</a> </p>
<p id="p1548236289165634"><a name="p1548236289165634"></a><a name="p1548236289165634"></a>Obtains the rectangular area of the view relative to the parent view, that is, the rectangular area relative to the coordinates of the parent view. </p>
</td>
</tr>
<tr id="row193633910165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2143380229165634"><a name="p2143380229165634"></a><a name="p2143380229165634"></a><a href="Graphic.md#gae6c5f3bcf99dc837bcecd60c38d3df5a">ResizeVisibleArea</a> (int16_t x, int16_t y, int16_t width, int16_t height)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p867456345165634"><a name="p867456345165634"></a><a name="p867456345165634"></a>void </p>
<p id="p829434107165634"><a name="p829434107165634"></a><a name="p829434107165634"></a>Adjusts the size of the visible area. This operation may affect the final display size. </p>
</td>
</tr>
<tr id="row142166590165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1907225627165634"><a name="p1907225627165634"></a><a name="p1907225627165634"></a><a href="Graphic.md#ga3375ec5ef059fd88c657af4552d2fa4f">SetWidth</a> (int16_t width)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1498544826165634"><a name="p1498544826165634"></a><a name="p1498544826165634"></a>virtual void </p>
<p id="p1386484901165634"><a name="p1386484901165634"></a><a name="p1386484901165634"></a>Sets the width for the view. </p>
</td>
</tr>
<tr id="row1439516893165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1368732794165634"><a name="p1368732794165634"></a><a name="p1368732794165634"></a><a href="Graphic.md#ga90cf8cffb98d71c30d6fc1d118442dbd">GetWidth</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1757510384165634"><a name="p1757510384165634"></a><a name="p1757510384165634"></a>virtual int16_t </p>
<p id="p812238574165634"><a name="p812238574165634"></a><a name="p812238574165634"></a>Obtains the width for the view. </p>
</td>
</tr>
<tr id="row181939193165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1437534335165634"><a name="p1437534335165634"></a><a name="p1437534335165634"></a><a href="Graphic.md#ga9c7110620d5dc3a7bd3efe1fc2edd125">SetHeight</a> (int16_t height)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p715782244165634"><a name="p715782244165634"></a><a name="p715782244165634"></a>virtual void </p>
<p id="p1906211829165634"><a name="p1906211829165634"></a><a name="p1906211829165634"></a>Sets the height for the view. </p>
</td>
</tr>
<tr id="row150702027165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p210876512165634"><a name="p210876512165634"></a><a name="p210876512165634"></a><a href="Graphic.md#ga9b35f4603a561c7a9a29b023a022ac97">GetHeight</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p825673360165634"><a name="p825673360165634"></a><a name="p825673360165634"></a>virtual int16_t </p>
<p id="p537716405165634"><a name="p537716405165634"></a><a name="p537716405165634"></a>Obtains the height for the view. </p>
</td>
</tr>
<tr id="row1341429742165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1392063271165634"><a name="p1392063271165634"></a><a name="p1392063271165634"></a><a href="Graphic.md#gae985b607d2f0701911778bf20d640ccd">Resize</a> (int16_t width, int16_t height)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p540212519165634"><a name="p540212519165634"></a><a name="p540212519165634"></a>virtual void </p>
<p id="p1471674965165634"><a name="p1471674965165634"></a><a name="p1471674965165634"></a>Adjusts the size of the view. </p>
</td>
</tr>
<tr id="row1388042681165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p871087393165634"><a name="p871087393165634"></a><a name="p871087393165634"></a><a href="Graphic.md#gaded403626558d28e62bf5632ccbb24b5">SetX</a> (int16_t x)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1312403173165634"><a name="p1312403173165634"></a><a name="p1312403173165634"></a>virtual void </p>
<p id="p1011091011165634"><a name="p1011091011165634"></a><a name="p1011091011165634"></a>Sets the x-coordinate for the view. </p>
</td>
</tr>
<tr id="row851506778165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2097892159165634"><a name="p2097892159165634"></a><a name="p2097892159165634"></a><a href="Graphic.md#ga89dc5f8fb1cb4b2259dc0439185359f1">GetX</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p219976230165634"><a name="p219976230165634"></a><a name="p219976230165634"></a>int16_t </p>
<p id="p2066565259165634"><a name="p2066565259165634"></a><a name="p2066565259165634"></a>Obtains the x-coordinate for the view. </p>
</td>
</tr>
<tr id="row838659282165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2132466997165634"><a name="p2132466997165634"></a><a name="p2132466997165634"></a><a href="Graphic.md#gaaa8edc224cf1c7deb2724fb225960877">SetY</a> (int16_t y)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2006056631165634"><a name="p2006056631165634"></a><a name="p2006056631165634"></a>virtual void </p>
<p id="p412734372165634"><a name="p412734372165634"></a><a name="p412734372165634"></a>Sets the y-coordinate for the view. </p>
</td>
</tr>
<tr id="row1375110751165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1296145422165634"><a name="p1296145422165634"></a><a name="p1296145422165634"></a><a href="Graphic.md#ga193619d649204b0e9bb854d3b30275c3">GetY</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2124970602165634"><a name="p2124970602165634"></a><a name="p2124970602165634"></a>int16_t </p>
<p id="p1772729439165634"><a name="p1772729439165634"></a><a name="p1772729439165634"></a>Obtains the y-coordinate for the view. </p>
</td>
</tr>
<tr id="row54462817165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1363738455165634"><a name="p1363738455165634"></a><a name="p1363738455165634"></a><a href="Graphic.md#gab34233f6aeae330b025969137d03e67a">SetPosition</a> (int16_t x, int16_t y)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2007080063165634"><a name="p2007080063165634"></a><a name="p2007080063165634"></a>virtual void </p>
<p id="p2052720943165634"><a name="p2052720943165634"></a><a name="p2052720943165634"></a>Sets the position for the view. </p>
</td>
</tr>
<tr id="row1251658737165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p560128200165634"><a name="p560128200165634"></a><a name="p560128200165634"></a><a href="Graphic.md#gaf8ce4c009f23b7175b2b34bac4a74262">SetPosition</a> (int16_t x, int16_t y, int16_t width, int16_t height)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1896501383165634"><a name="p1896501383165634"></a><a name="p1896501383165634"></a>virtual void </p>
<p id="p1001932795165634"><a name="p1001932795165634"></a><a name="p1001932795165634"></a>Adjusts the position and size of the view. </p>
</td>
</tr>
<tr id="row564266215165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p800246592165634"><a name="p800246592165634"></a><a name="p800246592165634"></a><a href="Graphic.md#gab2ce8c11abbd55f40687f38a52511b11">IsViewGroup</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p803053009165634"><a name="p803053009165634"></a><a name="p803053009165634"></a>bool </p>
<p id="p37158883165634"><a name="p37158883165634"></a><a name="p37158883165634"></a>Checks whether the view is a container view. </p>
</td>
</tr>
<tr id="row233232851165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p78552627165634"><a name="p78552627165634"></a><a name="p78552627165634"></a><a href="Graphic.md#ga980fc6824c64cfae6af8657aee17af88">SetIntercept</a> (bool isIntercept)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1421418267165634"><a name="p1421418267165634"></a><a name="p1421418267165634"></a>void </p>
<p id="p1104063886165634"><a name="p1104063886165634"></a><a name="p1104063886165634"></a>Sets whether to intercept the drag event. If intercepted, the view does not transfer the drag event to the parent view after local processing. </p>
</td>
</tr>
<tr id="row610049291165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1548844955165634"><a name="p1548844955165634"></a><a name="p1548844955165634"></a><a href="Graphic.md#ga8623abbbeff458c0cb2d7dc0d1f21e4a">SetTransformMap</a> (const <a href="OHOS-TransformMap.md">TransformMap</a> &amp;transMap)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1493547725165634"><a name="p1493547725165634"></a><a name="p1493547725165634"></a>void </p>
<p id="p582713522165634"><a name="p582713522165634"></a><a name="p582713522165634"></a>Sets the affine transformation matrix. </p>
</td>
</tr>
<tr id="row1047701823165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1071868835165634"><a name="p1071868835165634"></a><a name="p1071868835165634"></a><a href="Graphic.md#gab8cee5a7052a88722768c8ed1324abc1">GetTransformMap</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p110062956165634"><a name="p110062956165634"></a><a name="p110062956165634"></a><a href="OHOS-TransformMap.md">TransformMap</a> &amp; </p>
<p id="p1670910652165634"><a name="p1670910652165634"></a><a name="p1670910652165634"></a>Obtains an affine transformation matrix. </p>
</td>
</tr>
<tr id="row1361721138165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2018588986165634"><a name="p2018588986165634"></a><a name="p2018588986165634"></a><a href="Graphic.md#ga0caaa15c9b304673331e778a266be77f">SetViewId</a> (const char *id)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1359942981165634"><a name="p1359942981165634"></a><a name="p1359942981165634"></a>void </p>
<p id="p1687048246165634"><a name="p1687048246165634"></a><a name="p1687048246165634"></a>Sets the view ID. </p>
</td>
</tr>
<tr id="row1217580608165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p51562655165634"><a name="p51562655165634"></a><a name="p51562655165634"></a><a href="Graphic.md#gad6c7644bd2abfa3c92d80776b0bd1936">GetViewId</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2145048679165634"><a name="p2145048679165634"></a><a name="p2145048679165634"></a>const char * </p>
<p id="p1979592202165634"><a name="p1979592202165634"></a><a name="p1979592202165634"></a>Obtains the view ID. </p>
</td>
</tr>
<tr id="row535118162165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1495826716165634"><a name="p1495826716165634"></a><a name="p1495826716165634"></a><a href="Graphic.md#ga77a961aa53567c5214508b4569801c16">SetViewIndex</a> (int16_t <a href="UTILS.md#ga1d3748ca570dcb09a2fb28e8015107dd">index</a>)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p926639386165634"><a name="p926639386165634"></a><a name="p926639386165634"></a>void </p>
<p id="p566960640165634"><a name="p566960640165634"></a><a name="p566960640165634"></a>Sets the view index. </p>
</td>
</tr>
<tr id="row720679813165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1681952387165634"><a name="p1681952387165634"></a><a name="p1681952387165634"></a><a href="Graphic.md#ga62f51715b6d420a296ebe0296717b906">GetViewIndex</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1036291527165634"><a name="p1036291527165634"></a><a name="p1036291527165634"></a>int16_t </p>
<p id="p279465914165634"><a name="p279465914165634"></a><a name="p279465914165634"></a>Obtains the view index. </p>
</td>
</tr>
<tr id="row2126100543165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1108363396165634"><a name="p1108363396165634"></a><a name="p1108363396165634"></a><a href="Graphic.md#gaca871fa2f8219e7ea9388e212d1f1e69">LayoutChildren</a> (bool neeInvalidate=false)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1910414471165634"><a name="p1910414471165634"></a><a name="p1910414471165634"></a>virtual void </p>
<p id="p218812594165634"><a name="p218812594165634"></a><a name="p218812594165634"></a>Lays out all child views according to the preset arrangement mode. </p>
</td>
</tr>
<tr id="row633626342165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p736336136165634"><a name="p736336136165634"></a><a name="p736336136165634"></a><a href="Graphic.md#ga443b86ee9275b0421b37a47bad3264dc">LayoutCenterOfParent</a> (int16_t xOffSet=0, int16_t yOffset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2087241885165634"><a name="p2087241885165634"></a><a name="p2087241885165634"></a>void </p>
<p id="p1683909207165634"><a name="p1683909207165634"></a><a name="p1683909207165634"></a>Lays out the view in the center of the parent view. </p>
</td>
</tr>
<tr id="row1622067215165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p773643462165634"><a name="p773643462165634"></a><a name="p773643462165634"></a><a href="Graphic.md#ga94999b271f27cd5d6bfaf303f7d5c708">LayoutLeftOfParent</a> (int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1612858739165634"><a name="p1612858739165634"></a><a name="p1612858739165634"></a>void </p>
<p id="p214480330165634"><a name="p214480330165634"></a><a name="p214480330165634"></a>Lays out the view on the left of the parent view. </p>
</td>
</tr>
<tr id="row332296772165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p957090632165634"><a name="p957090632165634"></a><a name="p957090632165634"></a><a href="Graphic.md#ga479528ed259b5539e423955f2b60517d">LayoutRightOfParent</a> (int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1216937475165634"><a name="p1216937475165634"></a><a name="p1216937475165634"></a>void </p>
<p id="p1083868474165634"><a name="p1083868474165634"></a><a name="p1083868474165634"></a>Lays out the view on the right of the parent view. </p>
</td>
</tr>
<tr id="row245234070165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p379533408165634"><a name="p379533408165634"></a><a name="p379533408165634"></a><a href="Graphic.md#ga859288ea61ad23ba7e381bbc07769e83">LayoutTopOfParent</a> (int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p566828844165634"><a name="p566828844165634"></a><a name="p566828844165634"></a>void </p>
<p id="p326289222165634"><a name="p326289222165634"></a><a name="p326289222165634"></a>Lays out the view on the top of the parent view. </p>
</td>
</tr>
<tr id="row1923004839165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p7613166165634"><a name="p7613166165634"></a><a name="p7613166165634"></a><a href="Graphic.md#ga809aeee4792ae58218a0bcfcb94d5cdc">LayoutBottomOfParent</a> (int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p903101545165634"><a name="p903101545165634"></a><a name="p903101545165634"></a>void </p>
<p id="p101089674165634"><a name="p101089674165634"></a><a name="p101089674165634"></a>Lays out the view on the bottom of the parent view. </p>
</td>
</tr>
<tr id="row1288045888165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p8184907165634"><a name="p8184907165634"></a><a name="p8184907165634"></a><a href="Graphic.md#gac7f5f2584c716a56fee3783f8dea6246">AlignLeftToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p96274520165634"><a name="p96274520165634"></a><a name="p96274520165634"></a>void </p>
<p id="p2112871518165634"><a name="p2112871518165634"></a><a name="p2112871518165634"></a>Aligns the view with the left of a sibling view. </p>
</td>
</tr>
<tr id="row1148152290165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1929503913165634"><a name="p1929503913165634"></a><a name="p1929503913165634"></a><a href="Graphic.md#gabb1ac454cdf95593c1e387d5e272433c">AlignRightToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1660338033165634"><a name="p1660338033165634"></a><a name="p1660338033165634"></a>void </p>
<p id="p369139121165634"><a name="p369139121165634"></a><a name="p369139121165634"></a>Aligns the view with the right of a sibling view. </p>
</td>
</tr>
<tr id="row1461736349165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p583943392165634"><a name="p583943392165634"></a><a name="p583943392165634"></a><a href="Graphic.md#ga903d7cbc59bac06d728b7f6435c9a504">AlignTopToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1977320285165634"><a name="p1977320285165634"></a><a name="p1977320285165634"></a>void </p>
<p id="p983956424165634"><a name="p983956424165634"></a><a name="p983956424165634"></a>Aligns the view with the top of a sibling view. </p>
</td>
</tr>
<tr id="row1612940676165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2128594368165634"><a name="p2128594368165634"></a><a name="p2128594368165634"></a><a href="Graphic.md#ga7607c3f9661932c495d080e9d92fb1a3">AlignBottomToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p489019898165634"><a name="p489019898165634"></a><a name="p489019898165634"></a>void </p>
<p id="p1549355103165634"><a name="p1549355103165634"></a><a name="p1549355103165634"></a>Aligns the view with the bottom of a sibling view. </p>
</td>
</tr>
<tr id="row712754755165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1993885135165634"><a name="p1993885135165634"></a><a name="p1993885135165634"></a><a href="Graphic.md#gac23776dbc2fce7ff30d57438abfa5230">AlignHorCenterToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p962627603165634"><a name="p962627603165634"></a><a name="p962627603165634"></a>void </p>
<p id="p700574733165634"><a name="p700574733165634"></a><a name="p700574733165634"></a>Aligns the view with the center of a sibling view in the x-axis. </p>
</td>
</tr>
<tr id="row1991441196165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p279779080165634"><a name="p279779080165634"></a><a name="p279779080165634"></a><a href="Graphic.md#gad3caa27aa0cb73ec4656e7d23aa222de">AlignVerCenterToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1406563862165634"><a name="p1406563862165634"></a><a name="p1406563862165634"></a>void </p>
<p id="p1275106483165634"><a name="p1275106483165634"></a><a name="p1275106483165634"></a>Aligns the view with the center of a sibling view in the y-axis. </p>
</td>
</tr>
<tr id="row528044548165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p874046325165634"><a name="p874046325165634"></a><a name="p874046325165634"></a><a href="Graphic.md#ga58f1a34a943c4492970f901d63bbc3d8">LayoutLeftToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p45125670165634"><a name="p45125670165634"></a><a name="p45125670165634"></a>void </p>
<p id="p429042124165634"><a name="p429042124165634"></a><a name="p429042124165634"></a>Lays out the view on the left of a sibling view. </p>
</td>
</tr>
<tr id="row40489353165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p826390930165634"><a name="p826390930165634"></a><a name="p826390930165634"></a><a href="Graphic.md#gac4cd64de5291759add164825a323a0d6">LayoutRightToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p677755515165634"><a name="p677755515165634"></a><a name="p677755515165634"></a>void </p>
<p id="p1522117379165634"><a name="p1522117379165634"></a><a name="p1522117379165634"></a>Lays out the view on the right of a sibling view. </p>
</td>
</tr>
<tr id="row883534543165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p50786990165634"><a name="p50786990165634"></a><a name="p50786990165634"></a><a href="Graphic.md#gaaa8385807e3a9bea46f8dcc326252a70">LayoutTopToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p319126928165634"><a name="p319126928165634"></a><a name="p319126928165634"></a>void </p>
<p id="p744670365165634"><a name="p744670365165634"></a><a name="p744670365165634"></a>Lays out the view on the above of a sibling view. </p>
</td>
</tr>
<tr id="row1095794494165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1495756913165634"><a name="p1495756913165634"></a><a name="p1495756913165634"></a><a href="Graphic.md#gaa23a68e8ef0fb13b362218e71cf67ace">LayoutBottomToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p583288765165634"><a name="p583288765165634"></a><a name="p583288765165634"></a>void </p>
<p id="p812507346165634"><a name="p812507346165634"></a><a name="p812507346165634"></a>Lays out the view on the below of a sibling view. </p>
</td>
</tr>
<tr id="row2067312083165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p29550775165634"><a name="p29550775165634"></a><a name="p29550775165634"></a><a href="Graphic.md#ga535942844ebee554d413e960634a2867">SetStyle</a> (<a href="OHOS-Style.md">Style</a> &amp;style)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p18473264165634"><a name="p18473264165634"></a><a name="p18473264165634"></a>void </p>
<p id="p1868044500165634"><a name="p1868044500165634"></a><a name="p1868044500165634"></a>Sets the view style. </p>
</td>
</tr>
<tr id="row47999395165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1010702508165634"><a name="p1010702508165634"></a><a name="p1010702508165634"></a><a href="Graphic.md#ga0945c2f05815dc2e466ef9ceaca2f700">SetStyle</a> (uint8_t key, int64_t value)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p524626412165634"><a name="p524626412165634"></a><a name="p524626412165634"></a>virtual void </p>
<p id="p2010955239165634"><a name="p2010955239165634"></a><a name="p2010955239165634"></a>Sets a style. </p>
</td>
</tr>
<tr id="row131238153165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p838680340165634"><a name="p838680340165634"></a><a name="p838680340165634"></a><a href="Graphic.md#ga4ea19bc9f4b487946c9e29e63b54a0e6">GetStyle</a> (uint8_t key) const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p199878358165634"><a name="p199878358165634"></a><a name="p199878358165634"></a>virtual int64_t </p>
<p id="p1454231468165634"><a name="p1454231468165634"></a><a name="p1454231468165634"></a>Obtains the value of a style. </p>
</td>
</tr>
<tr id="row1399573475165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p929769511165634"><a name="p929769511165634"></a><a name="p929769511165634"></a><a href="Graphic.md#ga1b28213d4c2cd0f8324bce3fe56eb7bb">GetStyleConst</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p624654272165634"><a name="p624654272165634"></a><a name="p624654272165634"></a>const <a href="OHOS-Style.md">Style</a> &amp; </p>
<p id="p730196994165634"><a name="p730196994165634"></a><a name="p730196994165634"></a>Obtains the view style. This function applies to scenarios where the style does not need to be modified, which saves memory. </p>
</td>
</tr>
<tr id="row625705507165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p211312448165634"><a name="p211312448165634"></a><a name="p211312448165634"></a><a href="Graphic.md#ga4854963aa969ee20a6cd174a70f5cd23">operator new</a> (size_t size)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p480276639165634"><a name="p480276639165634"></a><a name="p480276639165634"></a>void * </p>
<p id="p1849936932165634"><a name="p1849936932165634"></a><a name="p1849936932165634"></a>Overrides the <strong id="b400480901165634"><a name="b400480901165634"></a><a name="b400480901165634"></a>new</strong> function. </p>
</td>
</tr>
<tr id="row1645436163165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1756765970165634"><a name="p1756765970165634"></a><a name="p1756765970165634"></a><a href="Graphic.md#gadf1997a0f56ac2b220e7f0f8e8e0a6ef">operator delete</a> (void *p)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1054298215165634"><a name="p1054298215165634"></a><a name="p1054298215165634"></a>void </p>
<p id="p1099152171165634"><a name="p1099152171165634"></a><a name="p1099152171165634"></a>Overrides the <strong id="b216529155165634"><a name="b216529155165634"></a><a name="b216529155165634"></a>delete</strong> function. </p>
</td>
</tr>
</tbody>
</table>

## Additional Inherited Members<a name="inherited"></a>

<a name="table1305199478165634"></a>
<table><thead align="left"><tr id="row79763235165634"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p101664887165634"><a name="p101664887165634"></a><a name="p101664887165634"></a>Additional Inherited Member Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1651010360165634"><a name="p1651010360165634"></a><a name="p1651010360165634"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row830238853165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1219732109165634"><a name="p1219732109165634"></a><a name="p1219732109165634"></a><a href="Graphic.md#ga34fe81b667a13b06a579600827e0531b">GetAllChildRelativeRect</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p122851399165634"><a name="p122851399165634"></a><a name="p122851399165634"></a>Obtains the rectangle area of a new view group after being adaptive to the size of all child views. </p>
</td>
</tr>
<tr id="row625813663165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2135896869165634"><a name="p2135896869165634"></a><a name="p2135896869165634"></a><a href="Graphic.md#ga06a5bd621f6532fe5c8fd08a2c1314b2">OnChildChanged</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1253160341165634"><a name="p1253160341165634"></a><a name="p1253160341165634"></a>Performs operations needed after a child view is added or removed. </p>
</td>
</tr>
<tr id="row1103311014165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1649995746165634"><a name="p1649995746165634"></a><a name="p1649995746165634"></a><a href="Graphic.md#ga82ac8a2ca47014ecb5e142e1cd7d30c1">childrenHead_</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1542930330165634"><a name="p1542930330165634"></a><a name="p1542930330165634"></a>Indicates the pointer to the first child view of this view group. </p>
</td>
</tr>
<tr id="row1902310157165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1114446525165634"><a name="p1114446525165634"></a><a name="p1114446525165634"></a><a href="Graphic.md#gaa0d6d1c8775e4765f8ae40d4573e0a83">childrenTail_</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p739629064165634"><a name="p739629064165634"></a><a name="p739629064165634"></a>Indicates the pointer to the last child view of this view group. </p>
</td>
</tr>
<tr id="row703019150165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p286903286165634"><a name="p286903286165634"></a><a name="p286903286165634"></a><a href="Graphic.md#gaba49c636834e80a53373dd4c3687e298">childrenNum_</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p800118918165634"><a name="p800118918165634"></a><a name="p800118918165634"></a>Represents the number of child views. </p>
</td>
</tr>
<tr id="row617736728165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p851614474165634"><a name="p851614474165634"></a><a name="p851614474165634"></a><a href="Graphic.md#ga732108111fa141d8ad1d8a76f761307b">isDragging_</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p634473020165634"><a name="p634473020165634"></a><a name="p634473020165634"></a>Specifies the sliding state of this view group. </p>
</td>
</tr>
<tr id="row1536674304165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p459720694165634"><a name="p459720694165634"></a><a name="p459720694165634"></a><a href="Graphic.md#ga712f1c3641cb16674202fbc723af8b74">disallowIntercept_</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1719527714165634"><a name="p1719527714165634"></a><a name="p1719527714165634"></a>Specifies whether this view group is intercepted upon touch events. </p>
</td>
</tr>
<tr id="row328329993165634"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p525764449165634"><a name="p525764449165634"></a><a name="p525764449165634"></a><a href="Graphic.md#ga1053e3677195fd4f98d68196d31d2cb5">isAutoSize_</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p296262392165634"><a name="p296262392165634"></a><a name="p296262392165634"></a>Specifies whether the size of this view group is adaptive to that of all child views. </p>
</td>
</tr>
</tbody>
</table>

