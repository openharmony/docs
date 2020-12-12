# OHOS::RootView<a name="ZH-CN_TOPIC_0000001054598173"></a>

-   [Overview](#section651609870165632)
-   [Summary](#section1820329393165632)
-   [Data Structures](#nested-classes)
-   [Public Member Functions](#pub-methods)
-   [Static Public Member Functions](#pub-static-methods)
-   [Additional Inherited Members](#inherited)

## **Overview**<a name="section651609870165632"></a>

**Related Modules:**

[Graphic](Graphic.md)

**Description:**

Defines the functions related to a root view which contains its child views and represents the root node in a tree structure. 

**Since:**

1.0

**Version:**

1.0

## **Summary**<a name="section1820329393165632"></a>

## Data Structures<a name="nested-classes"></a>

<a name="table1580657165165632"></a>
<table><thead align="left"><tr id="row582393534165632"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p116860300165632"><a name="p116860300165632"></a><a name="p116860300165632"></a>Data Structure Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p762963105165632"><a name="p762963105165632"></a><a name="p762963105165632"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row766316538165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p906594144165632"><a name="p906594144165632"></a><a name="p906594144165632"></a><a href="OHOS-RootView-OnKeyActListener.md">OnKeyActListener</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p349916009165632"><a name="p349916009165632"></a><a name="p349916009165632"></a>Represents the listener for monitoring physical key events. </p>
</td>
</tr>
<tr id="row1772186851165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1452764137165632"><a name="p1452764137165632"></a><a name="p1452764137165632"></a><a href="OHOS-RootView-OnVirtualDeviceEventListener.md">OnVirtualDeviceEventListener</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1256259183165632"><a name="p1256259183165632"></a><a name="p1256259183165632"></a>Listens for the input events triggered by a virtual device other than human touching or physical pressing. </p>
</td>
</tr>
</tbody>
</table>

## Public Member Functions<a name="pub-methods"></a>

<a name="table83880507165632"></a>
<table><thead align="left"><tr id="row1183200629165632"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p465802542165632"><a name="p465802542165632"></a><a name="p465802542165632"></a>Function</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1173686444165632"><a name="p1173686444165632"></a><a name="p1173686444165632"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1626559944165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p198062393165632"><a name="p198062393165632"></a><a name="p198062393165632"></a><a href="Graphic.md#ga7b96c15cdbe0edd5045e479b3b2fe1eb">GetViewType</a> () const override</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1758197340165632"><a name="p1758197340165632"></a><a name="p1758197340165632"></a>UIViewType </p>
<p id="p1753490238165632"><a name="p1753490238165632"></a><a name="p1753490238165632"></a>Obtains the view type. </p>
</td>
</tr>
<tr id="row1274530324165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1245693290165632"><a name="p1245693290165632"></a><a name="p1245693290165632"></a><a href="Graphic.md#gaffcd945698a2df5f3fde5342c74719a9">OnKeyEvent</a> (const <a href="OHOS-KeyEvent.md">KeyEvent</a> &amp;event)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1744937850165632"><a name="p1744937850165632"></a><a name="p1744937850165632"></a>virtual void </p>
<p id="p908053526165632"><a name="p908053526165632"></a><a name="p908053526165632"></a>Executes a physical key event. </p>
</td>
</tr>
<tr id="row1764480926165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1530818509165632"><a name="p1530818509165632"></a><a name="p1530818509165632"></a><a href="Graphic.md#ga3c0fce0e3a6c1b83324e54468d077bb0">SetOnKeyActListener</a> (<a href="OHOS-RootView-OnKeyActListener.md">OnKeyActListener</a> *onKeyActListener)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1838164180165632"><a name="p1838164180165632"></a><a name="p1838164180165632"></a>void </p>
<p id="p795903618165632"><a name="p795903618165632"></a><a name="p795903618165632"></a>Sets the listener that contains a callback to be invoked upon a physical key event. </p>
</td>
</tr>
<tr id="row365142260165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1451047058165632"><a name="p1451047058165632"></a><a name="p1451047058165632"></a><a href="Graphic.md#ga00303597af333088c06a45346f4a77f2">ClearOnKeyActListener</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p704376768165632"><a name="p704376768165632"></a><a name="p704376768165632"></a>void </p>
<p id="p1213474275165632"><a name="p1213474275165632"></a><a name="p1213474275165632"></a>Clears the listener for monitoring physical key events. </p>
</td>
</tr>
<tr id="row707883923165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p391979182165632"><a name="p391979182165632"></a><a name="p391979182165632"></a><a href="Graphic.md#gae86a0b7fa1a2c4fee021cb7bed2d418c">OnVirtualDeviceEvent</a> (const <a href="OHOS-VirtualDeviceEvent.md">VirtualDeviceEvent</a> &amp;event)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p397405836165632"><a name="p397405836165632"></a><a name="p397405836165632"></a>virtual void </p>
<p id="p825654363165632"><a name="p825654363165632"></a><a name="p825654363165632"></a>Executes an input event triggered by a virtual device. </p>
</td>
</tr>
<tr id="row519868834165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2098201439165632"><a name="p2098201439165632"></a><a name="p2098201439165632"></a><a href="Graphic.md#gac12473c0dc9b293f6be9553afbb7c5d6">SetOnVirtualDeviceEventListener</a> (<a href="OHOS-RootView-OnVirtualDeviceEventListener.md">OnVirtualDeviceEventListener</a> *onVirtualDeviceEventListener)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1504809186165632"><a name="p1504809186165632"></a><a name="p1504809186165632"></a>void </p>
<p id="p1419172972165632"><a name="p1419172972165632"></a><a name="p1419172972165632"></a>Sets a listener for monitoring the input events of a virtual device. </p>
</td>
</tr>
<tr id="row791837733165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p215926203165632"><a name="p215926203165632"></a><a name="p215926203165632"></a><a href="Graphic.md#ga0b550a305c0cda1dc510b2446c56ed82">ClearOnVirtualDeviceEventListener</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2095379240165632"><a name="p2095379240165632"></a><a name="p2095379240165632"></a>void </p>
<p id="p1222579690165632"><a name="p1222579690165632"></a><a name="p1222579690165632"></a>Clears the listener for monitoring the input events of a virtual device. </p>
</td>
</tr>
<tr id="row909513309165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p83299218165632"><a name="p83299218165632"></a><a name="p83299218165632"></a><a href="Graphic.md#gadae043c6d43d5436ec0374e5d128c654">UIViewGroup</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p202549274165632"><a name="p202549274165632"></a><a name="p202549274165632"></a> </p>
<p id="p2036581132165632"><a name="p2036581132165632"></a><a name="p2036581132165632"></a>A default constructor used to create a <strong id="b1348248266165632"><a name="b1348248266165632"></a><a name="b1348248266165632"></a><a href="OHOS-UIViewGroup.md">UIViewGroup</a></strong> instance. </p>
</td>
</tr>
<tr id="row834029451165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p821595094165632"><a name="p821595094165632"></a><a name="p821595094165632"></a><a href="Graphic.md#ga19ec065bd41a01f0925a4a9ffa450d1c">~UIViewGroup</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1554279647165632"><a name="p1554279647165632"></a><a name="p1554279647165632"></a>virtual </p>
<p id="p1005106713165632"><a name="p1005106713165632"></a><a name="p1005106713165632"></a>A destructor used to delete the <strong id="b1802281854165632"><a name="b1802281854165632"></a><a name="b1802281854165632"></a><a href="OHOS-UIViewGroup.md">UIViewGroup</a></strong> instance. </p>
</td>
</tr>
<tr id="row1810740876165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p607615076165632"><a name="p607615076165632"></a><a name="p607615076165632"></a><a href="Graphic.md#gad5756764839a844ee9bee0c186798029">GetViewType</a> () const override</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1486138481165632"><a name="p1486138481165632"></a><a name="p1486138481165632"></a>UIViewType </p>
<p id="p465497555165632"><a name="p465497555165632"></a><a name="p465497555165632"></a>Obtains the view type. </p>
</td>
</tr>
<tr id="row1825187239165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p619715891165632"><a name="p619715891165632"></a><a name="p619715891165632"></a><a href="Graphic.md#gacf5db120308ac7783c493f5437f06cee">Add</a> (<a href="OHOS-UIView.md">UIView</a> *view)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p619694526165632"><a name="p619694526165632"></a><a name="p619694526165632"></a>virtual void </p>
<p id="p915471506165632"><a name="p915471506165632"></a><a name="p915471506165632"></a>Adds a child view. </p>
</td>
</tr>
<tr id="row1412864876165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p491836747165632"><a name="p491836747165632"></a><a name="p491836747165632"></a><a href="Graphic.md#ga84195a993bfe50d8302435ababb63966">Insert</a> (<a href="OHOS-UIView.md">UIView</a> *prevView, <a href="OHOS-UIView.md">UIView</a> *insertView)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p689781465165632"><a name="p689781465165632"></a><a name="p689781465165632"></a>virtual void </p>
<p id="p663557770165632"><a name="p663557770165632"></a><a name="p663557770165632"></a>Inserts a new child view behind the current one. </p>
</td>
</tr>
<tr id="row1259445797165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1623325988165632"><a name="p1623325988165632"></a><a name="p1623325988165632"></a><a href="Graphic.md#ga25523928b24d6692f18aed31edb07006">Remove</a> (<a href="OHOS-UIView.md">UIView</a> *view)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p684209957165632"><a name="p684209957165632"></a><a name="p684209957165632"></a>virtual void </p>
<p id="p443262030165632"><a name="p443262030165632"></a><a name="p443262030165632"></a>Removes a child view. </p>
</td>
</tr>
<tr id="row218241287165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1665993399165632"><a name="p1665993399165632"></a><a name="p1665993399165632"></a><a href="Graphic.md#gaf3ee08173d92932687809049e3c11e9b">RemoveAll</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1154416743165632"><a name="p1154416743165632"></a><a name="p1154416743165632"></a>virtual void </p>
<p id="p1329852597165632"><a name="p1329852597165632"></a><a name="p1329852597165632"></a>Removes all child views. </p>
</td>
</tr>
<tr id="row1924369948165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1142581958165632"><a name="p1142581958165632"></a><a name="p1142581958165632"></a><a href="Graphic.md#ga7ea54fc6ef3a8b7dec1bf88ab189f7c7">GetTargetView</a> (const <a href="OHOS-Point.md">Point</a> &amp;point, <a href="OHOS-UIView.md">UIView</a> **last) override</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p364911595165632"><a name="p364911595165632"></a><a name="p364911595165632"></a>virtual void </p>
<p id="p423637006165632"><a name="p423637006165632"></a><a name="p423637006165632"></a>Obtains the target child view that is visible and can respond to touch events based on given coordinates. </p>
</td>
</tr>
<tr id="row978462115165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1276407353165632"><a name="p1276407353165632"></a><a name="p1276407353165632"></a><a href="Graphic.md#ga776c6c1640cb88b537af227fa5eb0725">MoveChildByOffset</a> (int16_t x, int16_t y)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1245358188165632"><a name="p1245358188165632"></a><a name="p1245358188165632"></a>virtual void </p>
<p id="p987933896165632"><a name="p987933896165632"></a><a name="p987933896165632"></a>Moves all child views. </p>
</td>
</tr>
<tr id="row2019145432165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1336760282165632"><a name="p1336760282165632"></a><a name="p1336760282165632"></a><a href="Graphic.md#ga6fed8238b89b013552c5a247aa2471df">GetChildrenHead</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1309465365165632"><a name="p1309465365165632"></a><a name="p1309465365165632"></a><a href="OHOS-UIView.md">UIView</a> * </p>
<p id="p1235120881165632"><a name="p1235120881165632"></a><a name="p1235120881165632"></a>Obtains the first child view in this view group. </p>
</td>
</tr>
<tr id="row1107402690165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p258657416165632"><a name="p258657416165632"></a><a name="p258657416165632"></a><a href="Graphic.md#ga1361baa76fbabd2fc81cc249c6868691">GetChildrenTail</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1820100299165632"><a name="p1820100299165632"></a><a name="p1820100299165632"></a><a href="OHOS-UIView.md">UIView</a> * </p>
<p id="p1302253489165632"><a name="p1302253489165632"></a><a name="p1302253489165632"></a>Obtains the last child view in this view group. </p>
</td>
</tr>
<tr id="row88836036165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p435214586165632"><a name="p435214586165632"></a><a name="p435214586165632"></a><a href="Graphic.md#gad53c52e619a54358a413a836ae0c1861">SetDisallowIntercept</a> (bool flag)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1392590045165632"><a name="p1392590045165632"></a><a name="p1392590045165632"></a>void </p>
<p id="p1751910921165632"><a name="p1751910921165632"></a><a name="p1751910921165632"></a>Sets whether this view group is intercepted upon touch events. </p>
</td>
</tr>
<tr id="row1264387947165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p974459675165632"><a name="p974459675165632"></a><a name="p974459675165632"></a><a href="Graphic.md#gae9f6ddb5819392546463d6371147c486">GetChildById</a> (const char *id) const override</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p814617112165632"><a name="p814617112165632"></a><a name="p814617112165632"></a><a href="OHOS-UIView.md">UIView</a> * </p>
<p id="p5176929165632"><a name="p5176929165632"></a><a name="p5176929165632"></a>Obtains the target child view with a specified ID. </p>
</td>
</tr>
<tr id="row1695645361165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1398741581165632"><a name="p1398741581165632"></a><a name="p1398741581165632"></a><a href="Graphic.md#ga6442ba36114d739df1b17ca8943cc087">SetAutoSize</a> (bool state)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p942389971165632"><a name="p942389971165632"></a><a name="p942389971165632"></a>void </p>
<p id="p1006337906165632"><a name="p1006337906165632"></a><a name="p1006337906165632"></a>Sets whether the size of this view group is adaptive to that of all child views. </p>
</td>
</tr>
<tr id="row1381944982165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1171690566165632"><a name="p1171690566165632"></a><a name="p1171690566165632"></a><a href="Graphic.md#ga7aad5b50d945efe5f9304bc978b2001c">UIView</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p453171128165632"><a name="p453171128165632"></a><a name="p453171128165632"></a> </p>
<p id="p1462014504165632"><a name="p1462014504165632"></a><a name="p1462014504165632"></a>A default constructor used to create an <strong id="b98135121165632"><a name="b98135121165632"></a><a name="b98135121165632"></a><a href="OHOS-UIView.md">UIView</a></strong> instance. </p>
</td>
</tr>
<tr id="row223392002165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1292892328165632"><a name="p1292892328165632"></a><a name="p1292892328165632"></a><a href="Graphic.md#ga57d429bb1cd71782f3b825f1bc6b9362">UIView</a> (const char *id)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p433250343165632"><a name="p433250343165632"></a><a name="p433250343165632"></a> </p>
<p id="p1224412590165632"><a name="p1224412590165632"></a><a name="p1224412590165632"></a>A constructor used to create an <strong id="b1209759479165632"><a name="b1209759479165632"></a><a name="b1209759479165632"></a><a href="OHOS-UIView.md">UIView</a></strong> instance. </p>
</td>
</tr>
<tr id="row116268307165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p560039032165632"><a name="p560039032165632"></a><a name="p560039032165632"></a><a href="Graphic.md#ga17f0ffc1090bdcce0f88288da5962012">~UIView</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p906718185165632"><a name="p906718185165632"></a><a name="p906718185165632"></a>virtual </p>
<p id="p169300877165632"><a name="p169300877165632"></a><a name="p169300877165632"></a>A destructor used to delete the <strong id="b1430547881165632"><a name="b1430547881165632"></a><a name="b1430547881165632"></a><a href="OHOS-UIView.md">UIView</a></strong> instance. </p>
</td>
</tr>
<tr id="row247712944165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1661504357165632"><a name="p1661504357165632"></a><a name="p1661504357165632"></a><a href="Graphic.md#gac295fe4851eed72f48e9a63771416d71">OnPreDraw</a> (const <a href="OHOS-Rect.md">Rect</a> &amp;invalidatedArea)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p425849565165632"><a name="p425849565165632"></a><a name="p425849565165632"></a>virtual bool </p>
<p id="p2003896998165632"><a name="p2003896998165632"></a><a name="p2003896998165632"></a>Called before a view is drawn. This function is used to check whether the parent view of this view needs to be redrawn so as to optimize the drawing process. </p>
</td>
</tr>
<tr id="row247354765165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p257818404165632"><a name="p257818404165632"></a><a name="p257818404165632"></a><a href="Graphic.md#ga9a5f43bdc03cde30323b570bfb7ae425">OnDraw</a> (const <a href="OHOS-Rect.md">Rect</a> &amp;invalidatedArea)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p326635179165632"><a name="p326635179165632"></a><a name="p326635179165632"></a>virtual void </p>
<p id="p140108877165632"><a name="p140108877165632"></a><a name="p140108877165632"></a>Called when a view is drawn. </p>
</td>
</tr>
<tr id="row832121571165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p888928975165632"><a name="p888928975165632"></a><a name="p888928975165632"></a><a href="Graphic.md#gab70473cd0d8fe7c9d4bb817caeee9153">OnPostDraw</a> (const <a href="OHOS-Rect.md">Rect</a> &amp;invalidatedArea)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p690846291165632"><a name="p690846291165632"></a><a name="p690846291165632"></a>virtual void </p>
<p id="p718735653165632"><a name="p718735653165632"></a><a name="p718735653165632"></a>Called after a view is drawn. </p>
</td>
</tr>
<tr id="row625434779165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1845970435165632"><a name="p1845970435165632"></a><a name="p1845970435165632"></a><a href="Graphic.md#ga81726238adeda1efa989be6ed4f4fe5b">ReMeasure</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1383165943165632"><a name="p1383165943165632"></a><a name="p1383165943165632"></a>virtual void </p>
<p id="p379785818165632"><a name="p379785818165632"></a><a name="p379785818165632"></a>Remeasures the view size. </p>
</td>
</tr>
<tr id="row1419536671165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1337828143165632"><a name="p1337828143165632"></a><a name="p1337828143165632"></a><a href="Graphic.md#ga2a9a38b8450fbb196277238a51fbbf99">Invalidate</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p291122741165632"><a name="p291122741165632"></a><a name="p291122741165632"></a>void </p>
<p id="p1806334759165632"><a name="p1806334759165632"></a><a name="p1806334759165632"></a>Refreshes the invalidated area of the view. </p>
</td>
</tr>
<tr id="row635410131165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1351567130165632"><a name="p1351567130165632"></a><a name="p1351567130165632"></a><a href="Graphic.md#gaf0e6b65ced8b931642f2a80c195962d2">InvalidateRect</a> (const <a href="OHOS-Rect.md">Rect</a> &amp;invalidatedArea)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p956903223165632"><a name="p956903223165632"></a><a name="p956903223165632"></a>void </p>
<p id="p353832507165632"><a name="p353832507165632"></a><a name="p353832507165632"></a>Refreshes a view in a specified invalidated area. </p>
</td>
</tr>
<tr id="row270156817165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1881493854165632"><a name="p1881493854165632"></a><a name="p1881493854165632"></a><a href="Graphic.md#gac311aa47301d727c35fc31f8630d016e">OnLongPressEvent</a> (const <a href="OHOS-LongPressEvent.md">LongPressEvent</a> &amp;event)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p677020827165632"><a name="p677020827165632"></a><a name="p677020827165632"></a>virtual bool </p>
<p id="p1918620088165632"><a name="p1918620088165632"></a><a name="p1918620088165632"></a>Called when the view is long pressed. </p>
</td>
</tr>
<tr id="row895394409165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1977888378165632"><a name="p1977888378165632"></a><a name="p1977888378165632"></a><a href="Graphic.md#gac0e10556ff99b8a92bfb11df6456d605">OnDragStartEvent</a> (const <a href="OHOS-DragEvent.md">DragEvent</a> &amp;event)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p265118273165632"><a name="p265118273165632"></a><a name="p265118273165632"></a>virtual bool </p>
<p id="p1543893557165632"><a name="p1543893557165632"></a><a name="p1543893557165632"></a>Called when the view starts to drag. </p>
</td>
</tr>
<tr id="row306185083165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p383793622165632"><a name="p383793622165632"></a><a name="p383793622165632"></a><a href="Graphic.md#ga46249c8caf06b81590d9450e30a31147">OnDragEvent</a> (const <a href="OHOS-DragEvent.md">DragEvent</a> &amp;event)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p908795513165632"><a name="p908795513165632"></a><a name="p908795513165632"></a>virtual bool </p>
<p id="p1609980384165632"><a name="p1609980384165632"></a><a name="p1609980384165632"></a>Called when the view is being dragged. </p>
</td>
</tr>
<tr id="row952255327165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p341448821165632"><a name="p341448821165632"></a><a name="p341448821165632"></a><a href="Graphic.md#ga1799d33be73f64ed2066f50d7e65468d">OnDragEndEvent</a> (const <a href="OHOS-DragEvent.md">DragEvent</a> &amp;event)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p237039094165632"><a name="p237039094165632"></a><a name="p237039094165632"></a>virtual bool </p>
<p id="p276473208165632"><a name="p276473208165632"></a><a name="p276473208165632"></a>Called when the view stops dragging. </p>
</td>
</tr>
<tr id="row946919294165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1572031846165632"><a name="p1572031846165632"></a><a name="p1572031846165632"></a><a href="Graphic.md#gad08697a29aae4c58267f494b66b9a547">OnClickEvent</a> (const <a href="OHOS-ClickEvent.md">ClickEvent</a> &amp;event)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p75413544165632"><a name="p75413544165632"></a><a name="p75413544165632"></a>virtual void </p>
<p id="p1064377988165632"><a name="p1064377988165632"></a><a name="p1064377988165632"></a>Called when the view is clicked. </p>
</td>
</tr>
<tr id="row325978381165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1670619867165632"><a name="p1670619867165632"></a><a name="p1670619867165632"></a><a href="Graphic.md#gafa544ff2d27785a9410a80689f1ad3b1">OnPressEvent</a> (const <a href="OHOS-PressEvent.md">PressEvent</a> &amp;event)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p886723774165632"><a name="p886723774165632"></a><a name="p886723774165632"></a>virtual void </p>
<p id="p416125495165632"><a name="p416125495165632"></a><a name="p416125495165632"></a>Called when the view is pressed. </p>
</td>
</tr>
<tr id="row1953978312165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p619000017165632"><a name="p619000017165632"></a><a name="p619000017165632"></a><a href="Graphic.md#ga7bd1a74563b059b03fbf66f9add53ee3">OnReleaseEvent</a> (const <a href="OHOS-ReleaseEvent.md">ReleaseEvent</a> &amp;event)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1899004243165632"><a name="p1899004243165632"></a><a name="p1899004243165632"></a>virtual void </p>
<p id="p516852971165632"><a name="p516852971165632"></a><a name="p516852971165632"></a>Called when the view is released. </p>
</td>
</tr>
<tr id="row1310533053165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1356397118165632"><a name="p1356397118165632"></a><a name="p1356397118165632"></a><a href="Graphic.md#ga8f01ff25a33b20df0758f564148e579d">OnCancelEvent</a> (const <a href="OHOS-CancelEvent.md">CancelEvent</a> &amp;event)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p332686336165632"><a name="p332686336165632"></a><a name="p332686336165632"></a>virtual void </p>
<p id="p1674248835165632"><a name="p1674248835165632"></a><a name="p1674248835165632"></a>Called when a click event on the view is canceled. </p>
</td>
</tr>
<tr id="row1128208523165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1975255656165632"><a name="p1975255656165632"></a><a name="p1975255656165632"></a><a href="Graphic.md#gad8e3cf5f0dd003a6aa932ef04e7b59f2">SetOnDragListener</a> (<a href="OHOS-UIView-OnDragListener.md">OnDragListener</a> *onDragListener)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p8777622165632"><a name="p8777622165632"></a><a name="p8777622165632"></a>void </p>
<p id="p579649238165632"><a name="p579649238165632"></a><a name="p579649238165632"></a>Sets a drag event listener for the view. </p>
</td>
</tr>
<tr id="row1696701129165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p959890459165632"><a name="p959890459165632"></a><a name="p959890459165632"></a><a href="Graphic.md#ga45a02cba4887c5c0b8e243941bcdc5cb">GetOnDragListener</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p58887690165632"><a name="p58887690165632"></a><a name="p58887690165632"></a><a href="OHOS-UIView-OnDragListener.md">OnDragListener</a> *&amp; </p>
<p id="p38563108165632"><a name="p38563108165632"></a><a name="p38563108165632"></a>Obtains the drag event listener for the view. </p>
</td>
</tr>
<tr id="row1008801744165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2026323077165632"><a name="p2026323077165632"></a><a name="p2026323077165632"></a><a href="Graphic.md#ga4564bf8d8c7184e9c02bf33c9e171fa3">SetOnClickListener</a> (<a href="OHOS-UIView-OnClickListener.md">OnClickListener</a> *onClickListener)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p323783043165632"><a name="p323783043165632"></a><a name="p323783043165632"></a>void </p>
<p id="p158154864165632"><a name="p158154864165632"></a><a name="p158154864165632"></a>Sets a click event listener for the view. </p>
</td>
</tr>
<tr id="row196780415165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1906322382165632"><a name="p1906322382165632"></a><a name="p1906322382165632"></a><a href="Graphic.md#ga35e885cb380c37245fa4305bba10cd4a">GetOnClickListener</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1746094219165632"><a name="p1746094219165632"></a><a name="p1746094219165632"></a><a href="OHOS-UIView-OnClickListener.md">OnClickListener</a> *&amp; </p>
<p id="p689865036165632"><a name="p689865036165632"></a><a name="p689865036165632"></a>Obtains the click event listener for the view. </p>
</td>
</tr>
<tr id="row1909396285165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p84304565165632"><a name="p84304565165632"></a><a name="p84304565165632"></a><a href="Graphic.md#gabcbe7a0adce600424f7f0d5a7396eb5b">SetOnLongPressListener</a> (<a href="OHOS-UIView-OnLongPressListener.md">OnLongPressListener</a> *onLongPressListener)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1402036512165632"><a name="p1402036512165632"></a><a name="p1402036512165632"></a>void </p>
<p id="p865365526165632"><a name="p865365526165632"></a><a name="p865365526165632"></a>Sets a long-press event listener for the view. </p>
</td>
</tr>
<tr id="row2007691825165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p494275242165632"><a name="p494275242165632"></a><a name="p494275242165632"></a><a href="Graphic.md#gaafd4d354f5f111e758d046109fd7f656">GetOnLongPressListener</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p718794851165632"><a name="p718794851165632"></a><a name="p718794851165632"></a><a href="OHOS-UIView-OnLongPressListener.md">OnLongPressListener</a> *&amp; </p>
<p id="p1006422104165632"><a name="p1006422104165632"></a><a name="p1006422104165632"></a>Obtains the long-press event listener for the view. </p>
</td>
</tr>
<tr id="row588651665165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1448546521165632"><a name="p1448546521165632"></a><a name="p1448546521165632"></a><a href="Graphic.md#gadd697fbf481f98d9d6ca8b67390071af">SetOnTouchListener</a> (<a href="OHOS-UIView-OnTouchListener.md">OnTouchListener</a> *onTouchListener)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p400345897165632"><a name="p400345897165632"></a><a name="p400345897165632"></a>void </p>
<p id="p941743586165632"><a name="p941743586165632"></a><a name="p941743586165632"></a>Sets a touch event listener for the view. </p>
</td>
</tr>
<tr id="row2092210354165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2087960254165632"><a name="p2087960254165632"></a><a name="p2087960254165632"></a><a href="Graphic.md#gae7c65c68653103dae85acdcef78777a6">GetTouchListener</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p371263740165632"><a name="p371263740165632"></a><a name="p371263740165632"></a><a href="OHOS-UIView-OnTouchListener.md">OnTouchListener</a> *&amp; </p>
<p id="p1851583004165632"><a name="p1851583004165632"></a><a name="p1851583004165632"></a>Obtains the touch event listener for the view. </p>
</td>
</tr>
<tr id="row874069916165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p119698781165632"><a name="p119698781165632"></a><a name="p119698781165632"></a><a href="Graphic.md#gaeea67a3a84b4ffe9bfeda418b82184cc">SetParent</a> (<a href="OHOS-UIView.md">UIView</a> *parent)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p780909971165632"><a name="p780909971165632"></a><a name="p780909971165632"></a>void </p>
<p id="p97110683165632"><a name="p97110683165632"></a><a name="p97110683165632"></a>Sets the parent view for the view. </p>
</td>
</tr>
<tr id="row810749423165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p964541028165632"><a name="p964541028165632"></a><a name="p964541028165632"></a><a href="Graphic.md#ga706530e4a38108615d5e0c918685ec96">GetParent</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p130206750165632"><a name="p130206750165632"></a><a name="p130206750165632"></a><a href="OHOS-UIView.md">UIView</a> * </p>
<p id="p166979317165632"><a name="p166979317165632"></a><a name="p166979317165632"></a>Obtains the parent view of the view. </p>
</td>
</tr>
<tr id="row2142469770165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1927572109165632"><a name="p1927572109165632"></a><a name="p1927572109165632"></a><a href="Graphic.md#ga02bec5de07d93cabc45affba79eba4ad">SetNextSibling</a> (<a href="OHOS-UIView.md">UIView</a> *sibling)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p339993370165632"><a name="p339993370165632"></a><a name="p339993370165632"></a>void </p>
<p id="p1747681655165632"><a name="p1747681655165632"></a><a name="p1747681655165632"></a>Sets the next sibling view for the view. </p>
</td>
</tr>
<tr id="row677824561165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1292760646165632"><a name="p1292760646165632"></a><a name="p1292760646165632"></a><a href="Graphic.md#gab0030977b30ddc9f2e15dbc2f58937e6">GetNextSibling</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2077669664165632"><a name="p2077669664165632"></a><a name="p2077669664165632"></a><a href="OHOS-UIView.md">UIView</a> * </p>
<p id="p62019738165632"><a name="p62019738165632"></a><a name="p62019738165632"></a>Obtains the next sibling view of the view. </p>
</td>
</tr>
<tr id="row684582929165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1806093666165632"><a name="p1806093666165632"></a><a name="p1806093666165632"></a><a href="Graphic.md#ga07e7e1f268bd6ce975f4f0f8487af5d0">SetVisible</a> (bool visible)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1726616031165632"><a name="p1726616031165632"></a><a name="p1726616031165632"></a>virtual void </p>
<p id="p199979524165632"><a name="p199979524165632"></a><a name="p199979524165632"></a>Sets whether the view is visible. </p>
</td>
</tr>
<tr id="row204985595165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p34114943165632"><a name="p34114943165632"></a><a name="p34114943165632"></a><a href="Graphic.md#gaee178fc0a86ac03a6bdf2ade0c1914c8">IsVisible</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1964441812165632"><a name="p1964441812165632"></a><a name="p1964441812165632"></a>bool </p>
<p id="p1177215958165632"><a name="p1177215958165632"></a><a name="p1177215958165632"></a>Checks whether the view is visible. </p>
</td>
</tr>
<tr id="row749242977165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p865854260165632"><a name="p865854260165632"></a><a name="p865854260165632"></a><a href="Graphic.md#gaf9fb55fd9aa397f7158f1515e90bce02">SetTouchable</a> (bool touch)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1684738946165632"><a name="p1684738946165632"></a><a name="p1684738946165632"></a>void </p>
<p id="p1258263896165632"><a name="p1258263896165632"></a><a name="p1258263896165632"></a>Sets whether the view is touchable. </p>
</td>
</tr>
<tr id="row1956738295165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1364998646165632"><a name="p1364998646165632"></a><a name="p1364998646165632"></a><a href="Graphic.md#ga502a53fb77b260fa36b5b3adf82e2340">IsTouchable</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1536149917165632"><a name="p1536149917165632"></a><a name="p1536149917165632"></a>bool </p>
<p id="p267578062165632"><a name="p267578062165632"></a><a name="p267578062165632"></a>Checks whether the view is touchable. </p>
</td>
</tr>
<tr id="row544477274165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p668830301165632"><a name="p668830301165632"></a><a name="p668830301165632"></a><a href="Graphic.md#gab06abe0fe824c048f3b72974f9a8f0d0">SetDraggable</a> (bool draggable)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p55840097165632"><a name="p55840097165632"></a><a name="p55840097165632"></a>void </p>
<p id="p1389882199165632"><a name="p1389882199165632"></a><a name="p1389882199165632"></a>Sets whether the view is draggable. </p>
</td>
</tr>
<tr id="row841832190165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p467207376165632"><a name="p467207376165632"></a><a name="p467207376165632"></a><a href="Graphic.md#ga25bb796ff400c767d622cbed280fc500">IsDraggable</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p160968747165632"><a name="p160968747165632"></a><a name="p160968747165632"></a>bool </p>
<p id="p1065093757165632"><a name="p1065093757165632"></a><a name="p1065093757165632"></a>Checks whether the view is draggable. </p>
</td>
</tr>
<tr id="row56017511165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p602518163165632"><a name="p602518163165632"></a><a name="p602518163165632"></a><a href="Graphic.md#ga6c08e49bf7a82a7ebaef0f251e7a6f85">SetDragParentInstead</a> (bool dragParentInstead)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1065805238165632"><a name="p1065805238165632"></a><a name="p1065805238165632"></a>void </p>
<p id="p1476893810165632"><a name="p1476893810165632"></a><a name="p1476893810165632"></a>Sets whether to transfer the drag event to the parent view for processing when the view is being dragged. </p>
</td>
</tr>
<tr id="row1975833474165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1313890052165632"><a name="p1313890052165632"></a><a name="p1313890052165632"></a><a href="Graphic.md#gaf0c462bc31e779b1898ad4cdfdad6faf">IsDragParentInstead</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p533658480165632"><a name="p533658480165632"></a><a name="p533658480165632"></a>bool </p>
<p id="p1136215312165632"><a name="p1136215312165632"></a><a name="p1136215312165632"></a>Obtains whether the view transfers a drag event to the parent view for processing. </p>
</td>
</tr>
<tr id="row923707524165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p138983867165632"><a name="p138983867165632"></a><a name="p138983867165632"></a><a href="Graphic.md#ga86cb8d364f18494d67636c55babced5c">GetRect</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p34786674165632"><a name="p34786674165632"></a><a name="p34786674165632"></a><a href="OHOS-Rect.md">Rect</a> </p>
<p id="p1522307216165632"><a name="p1522307216165632"></a><a name="p1522307216165632"></a>Obtains the absolute rectangle area of the view. When the view has deformation such as rotation, the rectangle area is the intersection set of the absolute rectangle area and deformation matrix. </p>
</td>
</tr>
<tr id="row1491240846165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p631052417165632"><a name="p631052417165632"></a><a name="p631052417165632"></a><a href="Graphic.md#ga06e79704a19f2a238982076cac3d059b">GetVisibleRect</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p997041485165632"><a name="p997041485165632"></a><a name="p997041485165632"></a><a href="OHOS-Rect.md">Rect</a> </p>
<p id="p396835966165632"><a name="p396835966165632"></a><a name="p396835966165632"></a>Obtains the visible absolute rectangle area of the view. </p>
</td>
</tr>
<tr id="row1514528917165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p10209415165632"><a name="p10209415165632"></a><a name="p10209415165632"></a><a href="Graphic.md#gab3f8993b3953f27bfc61d53429916cba">GetMaskedRect</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1426704787165632"><a name="p1426704787165632"></a><a name="p1426704787165632"></a><a href="OHOS-Rect.md">Rect</a> </p>
<p id="p640035165632"><a name="p640035165632"></a><a name="p640035165632"></a>Obtains the valid absolute rectangle area of the view. The valid area refers to the area where the view can be displayed. Generally, the valid area is the same as the visible view area, but they may be different in the grid layout. </p>
</td>
</tr>
<tr id="row1253939515165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p557169017165632"><a name="p557169017165632"></a><a name="p557169017165632"></a><a href="Graphic.md#ga64cf308a09999def1192f9c4e0f17f0a">GetOrigRect</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1573108790165632"><a name="p1573108790165632"></a><a name="p1573108790165632"></a><a href="OHOS-Rect.md">Rect</a> </p>
<p id="p393795007165632"><a name="p393795007165632"></a><a name="p393795007165632"></a>Obtains the absolute rectangle area of the view. </p>
</td>
</tr>
<tr id="row1679054071165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p889318592165632"><a name="p889318592165632"></a><a name="p889318592165632"></a><a href="Graphic.md#ga9db88eae712676359d02a92be14fa316">GetContentRect</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1448347371165632"><a name="p1448347371165632"></a><a name="p1448347371165632"></a>virtual <a href="OHOS-Rect.md">Rect</a> </p>
<p id="p144143468165632"><a name="p144143468165632"></a><a name="p144143468165632"></a>Obtains the content of the absolute rectangle area of the view. This area excludes padding. </p>
</td>
</tr>
<tr id="row717654178165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1442384228165632"><a name="p1442384228165632"></a><a name="p1442384228165632"></a><a href="Graphic.md#gae9b96837fa1d45648a2a6fbbfcc5eb4a">GetRelativeRect</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p264066532165632"><a name="p264066532165632"></a><a name="p264066532165632"></a><a href="OHOS-Rect.md">Rect</a> </p>
<p id="p1856938383165632"><a name="p1856938383165632"></a><a name="p1856938383165632"></a>Obtains the rectangular area of the view relative to the parent view, that is, the rectangular area relative to the coordinates of the parent view. </p>
</td>
</tr>
<tr id="row951368167165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1722439567165632"><a name="p1722439567165632"></a><a name="p1722439567165632"></a><a href="Graphic.md#gae6c5f3bcf99dc837bcecd60c38d3df5a">ResizeVisibleArea</a> (int16_t x, int16_t y, int16_t width, int16_t height)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1394531979165632"><a name="p1394531979165632"></a><a name="p1394531979165632"></a>void </p>
<p id="p1349796306165632"><a name="p1349796306165632"></a><a name="p1349796306165632"></a>Adjusts the size of the visible area. This operation may affect the final display size. </p>
</td>
</tr>
<tr id="row1730731951165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1369324511165632"><a name="p1369324511165632"></a><a name="p1369324511165632"></a><a href="Graphic.md#ga3375ec5ef059fd88c657af4552d2fa4f">SetWidth</a> (int16_t width)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1548133734165632"><a name="p1548133734165632"></a><a name="p1548133734165632"></a>virtual void </p>
<p id="p1843565227165632"><a name="p1843565227165632"></a><a name="p1843565227165632"></a>Sets the width for the view. </p>
</td>
</tr>
<tr id="row2002887603165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1043217289165632"><a name="p1043217289165632"></a><a name="p1043217289165632"></a><a href="Graphic.md#ga90cf8cffb98d71c30d6fc1d118442dbd">GetWidth</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p802466514165632"><a name="p802466514165632"></a><a name="p802466514165632"></a>virtual int16_t </p>
<p id="p1905930696165632"><a name="p1905930696165632"></a><a name="p1905930696165632"></a>Obtains the width for the view. </p>
</td>
</tr>
<tr id="row499227659165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1400269270165632"><a name="p1400269270165632"></a><a name="p1400269270165632"></a><a href="Graphic.md#ga9c7110620d5dc3a7bd3efe1fc2edd125">SetHeight</a> (int16_t height)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p498984220165632"><a name="p498984220165632"></a><a name="p498984220165632"></a>virtual void </p>
<p id="p1966959704165632"><a name="p1966959704165632"></a><a name="p1966959704165632"></a>Sets the height for the view. </p>
</td>
</tr>
<tr id="row1558323702165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p635258213165632"><a name="p635258213165632"></a><a name="p635258213165632"></a><a href="Graphic.md#ga9b35f4603a561c7a9a29b023a022ac97">GetHeight</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p225348142165632"><a name="p225348142165632"></a><a name="p225348142165632"></a>virtual int16_t </p>
<p id="p1047090772165632"><a name="p1047090772165632"></a><a name="p1047090772165632"></a>Obtains the height for the view. </p>
</td>
</tr>
<tr id="row1318382443165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p664836957165632"><a name="p664836957165632"></a><a name="p664836957165632"></a><a href="Graphic.md#gae985b607d2f0701911778bf20d640ccd">Resize</a> (int16_t width, int16_t height)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1425330836165632"><a name="p1425330836165632"></a><a name="p1425330836165632"></a>virtual void </p>
<p id="p1465930402165632"><a name="p1465930402165632"></a><a name="p1465930402165632"></a>Adjusts the size of the view. </p>
</td>
</tr>
<tr id="row639168851165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1972576498165632"><a name="p1972576498165632"></a><a name="p1972576498165632"></a><a href="Graphic.md#gaded403626558d28e62bf5632ccbb24b5">SetX</a> (int16_t x)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p752278706165632"><a name="p752278706165632"></a><a name="p752278706165632"></a>virtual void </p>
<p id="p672631124165632"><a name="p672631124165632"></a><a name="p672631124165632"></a>Sets the x-coordinate for the view. </p>
</td>
</tr>
<tr id="row244859198165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1234770520165632"><a name="p1234770520165632"></a><a name="p1234770520165632"></a><a href="Graphic.md#ga89dc5f8fb1cb4b2259dc0439185359f1">GetX</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p691693433165632"><a name="p691693433165632"></a><a name="p691693433165632"></a>int16_t </p>
<p id="p1623275262165632"><a name="p1623275262165632"></a><a name="p1623275262165632"></a>Obtains the x-coordinate for the view. </p>
</td>
</tr>
<tr id="row1298400814165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p377154581165632"><a name="p377154581165632"></a><a name="p377154581165632"></a><a href="Graphic.md#gaaa8edc224cf1c7deb2724fb225960877">SetY</a> (int16_t y)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p114755264165632"><a name="p114755264165632"></a><a name="p114755264165632"></a>virtual void </p>
<p id="p585636354165632"><a name="p585636354165632"></a><a name="p585636354165632"></a>Sets the y-coordinate for the view. </p>
</td>
</tr>
<tr id="row743001658165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1087461506165632"><a name="p1087461506165632"></a><a name="p1087461506165632"></a><a href="Graphic.md#ga193619d649204b0e9bb854d3b30275c3">GetY</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p990603179165632"><a name="p990603179165632"></a><a name="p990603179165632"></a>int16_t </p>
<p id="p1686792700165632"><a name="p1686792700165632"></a><a name="p1686792700165632"></a>Obtains the y-coordinate for the view. </p>
</td>
</tr>
<tr id="row1904763984165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1495352092165632"><a name="p1495352092165632"></a><a name="p1495352092165632"></a><a href="Graphic.md#gab34233f6aeae330b025969137d03e67a">SetPosition</a> (int16_t x, int16_t y)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p68976754165632"><a name="p68976754165632"></a><a name="p68976754165632"></a>virtual void </p>
<p id="p1890627210165632"><a name="p1890627210165632"></a><a name="p1890627210165632"></a>Sets the position for the view. </p>
</td>
</tr>
<tr id="row1002361329165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p591923574165632"><a name="p591923574165632"></a><a name="p591923574165632"></a><a href="Graphic.md#gaf8ce4c009f23b7175b2b34bac4a74262">SetPosition</a> (int16_t x, int16_t y, int16_t width, int16_t height)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p707689870165632"><a name="p707689870165632"></a><a name="p707689870165632"></a>virtual void </p>
<p id="p1993722651165632"><a name="p1993722651165632"></a><a name="p1993722651165632"></a>Adjusts the position and size of the view. </p>
</td>
</tr>
<tr id="row1447688734165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1433973677165632"><a name="p1433973677165632"></a><a name="p1433973677165632"></a><a href="Graphic.md#gab2ce8c11abbd55f40687f38a52511b11">IsViewGroup</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1393209852165632"><a name="p1393209852165632"></a><a name="p1393209852165632"></a>bool </p>
<p id="p2086127000165632"><a name="p2086127000165632"></a><a name="p2086127000165632"></a>Checks whether the view is a container view. </p>
</td>
</tr>
<tr id="row68134579165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1383223512165632"><a name="p1383223512165632"></a><a name="p1383223512165632"></a><a href="Graphic.md#ga980fc6824c64cfae6af8657aee17af88">SetIntercept</a> (bool isIntercept)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p507049389165632"><a name="p507049389165632"></a><a name="p507049389165632"></a>void </p>
<p id="p1425069250165632"><a name="p1425069250165632"></a><a name="p1425069250165632"></a>Sets whether to intercept the drag event. If intercepted, the view does not transfer the drag event to the parent view after local processing. </p>
</td>
</tr>
<tr id="row404090368165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p396944049165632"><a name="p396944049165632"></a><a name="p396944049165632"></a><a href="Graphic.md#ga8623abbbeff458c0cb2d7dc0d1f21e4a">SetTransformMap</a> (const <a href="OHOS-TransformMap.md">TransformMap</a> &amp;transMap)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p165728468165632"><a name="p165728468165632"></a><a name="p165728468165632"></a>void </p>
<p id="p758751469165632"><a name="p758751469165632"></a><a name="p758751469165632"></a>Sets the affine transformation matrix. </p>
</td>
</tr>
<tr id="row1912632100165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1502294144165632"><a name="p1502294144165632"></a><a name="p1502294144165632"></a><a href="Graphic.md#gab8cee5a7052a88722768c8ed1324abc1">GetTransformMap</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1247962668165632"><a name="p1247962668165632"></a><a name="p1247962668165632"></a><a href="OHOS-TransformMap.md">TransformMap</a> &amp; </p>
<p id="p1876600836165632"><a name="p1876600836165632"></a><a name="p1876600836165632"></a>Obtains an affine transformation matrix. </p>
</td>
</tr>
<tr id="row1681231009165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1734923289165632"><a name="p1734923289165632"></a><a name="p1734923289165632"></a><a href="Graphic.md#ga0caaa15c9b304673331e778a266be77f">SetViewId</a> (const char *id)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1811849867165632"><a name="p1811849867165632"></a><a name="p1811849867165632"></a>void </p>
<p id="p607062860165632"><a name="p607062860165632"></a><a name="p607062860165632"></a>Sets the view ID. </p>
</td>
</tr>
<tr id="row22984707165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p927628409165632"><a name="p927628409165632"></a><a name="p927628409165632"></a><a href="Graphic.md#gad6c7644bd2abfa3c92d80776b0bd1936">GetViewId</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1350331912165632"><a name="p1350331912165632"></a><a name="p1350331912165632"></a>const char * </p>
<p id="p1930837746165632"><a name="p1930837746165632"></a><a name="p1930837746165632"></a>Obtains the view ID. </p>
</td>
</tr>
<tr id="row127207263165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p516085423165632"><a name="p516085423165632"></a><a name="p516085423165632"></a><a href="Graphic.md#ga77a961aa53567c5214508b4569801c16">SetViewIndex</a> (int16_t <a href="UTILS.md#ga1d3748ca570dcb09a2fb28e8015107dd">index</a>)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1465473349165632"><a name="p1465473349165632"></a><a name="p1465473349165632"></a>void </p>
<p id="p439497825165632"><a name="p439497825165632"></a><a name="p439497825165632"></a>Sets the view index. </p>
</td>
</tr>
<tr id="row1534331134165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p576305324165632"><a name="p576305324165632"></a><a name="p576305324165632"></a><a href="Graphic.md#ga62f51715b6d420a296ebe0296717b906">GetViewIndex</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p898172728165632"><a name="p898172728165632"></a><a name="p898172728165632"></a>int16_t </p>
<p id="p617358351165632"><a name="p617358351165632"></a><a name="p617358351165632"></a>Obtains the view index. </p>
</td>
</tr>
<tr id="row593642283165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1387184194165632"><a name="p1387184194165632"></a><a name="p1387184194165632"></a><a href="Graphic.md#gaca871fa2f8219e7ea9388e212d1f1e69">LayoutChildren</a> (bool neeInvalidate=false)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1211103027165632"><a name="p1211103027165632"></a><a name="p1211103027165632"></a>virtual void </p>
<p id="p55376202165632"><a name="p55376202165632"></a><a name="p55376202165632"></a>Lays out all child views according to the preset arrangement mode. </p>
</td>
</tr>
<tr id="row2118051727165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1443946226165632"><a name="p1443946226165632"></a><a name="p1443946226165632"></a><a href="Graphic.md#ga443b86ee9275b0421b37a47bad3264dc">LayoutCenterOfParent</a> (int16_t xOffSet=0, int16_t yOffset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1999096720165632"><a name="p1999096720165632"></a><a name="p1999096720165632"></a>void </p>
<p id="p944842727165632"><a name="p944842727165632"></a><a name="p944842727165632"></a>Lays out the view in the center of the parent view. </p>
</td>
</tr>
<tr id="row1794063235165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p502505458165632"><a name="p502505458165632"></a><a name="p502505458165632"></a><a href="Graphic.md#ga94999b271f27cd5d6bfaf303f7d5c708">LayoutLeftOfParent</a> (int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1021199867165632"><a name="p1021199867165632"></a><a name="p1021199867165632"></a>void </p>
<p id="p673973349165632"><a name="p673973349165632"></a><a name="p673973349165632"></a>Lays out the view on the left of the parent view. </p>
</td>
</tr>
<tr id="row991996316165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1041807991165632"><a name="p1041807991165632"></a><a name="p1041807991165632"></a><a href="Graphic.md#ga479528ed259b5539e423955f2b60517d">LayoutRightOfParent</a> (int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2085733085165632"><a name="p2085733085165632"></a><a name="p2085733085165632"></a>void </p>
<p id="p613597764165632"><a name="p613597764165632"></a><a name="p613597764165632"></a>Lays out the view on the right of the parent view. </p>
</td>
</tr>
<tr id="row1510660242165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2071692711165632"><a name="p2071692711165632"></a><a name="p2071692711165632"></a><a href="Graphic.md#ga859288ea61ad23ba7e381bbc07769e83">LayoutTopOfParent</a> (int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p964925558165632"><a name="p964925558165632"></a><a name="p964925558165632"></a>void </p>
<p id="p1264178835165632"><a name="p1264178835165632"></a><a name="p1264178835165632"></a>Lays out the view on the top of the parent view. </p>
</td>
</tr>
<tr id="row371054640165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1743680721165632"><a name="p1743680721165632"></a><a name="p1743680721165632"></a><a href="Graphic.md#ga809aeee4792ae58218a0bcfcb94d5cdc">LayoutBottomOfParent</a> (int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1007773355165632"><a name="p1007773355165632"></a><a name="p1007773355165632"></a>void </p>
<p id="p735577087165632"><a name="p735577087165632"></a><a name="p735577087165632"></a>Lays out the view on the bottom of the parent view. </p>
</td>
</tr>
<tr id="row860397841165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2134014868165632"><a name="p2134014868165632"></a><a name="p2134014868165632"></a><a href="Graphic.md#gac7f5f2584c716a56fee3783f8dea6246">AlignLeftToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p958564795165632"><a name="p958564795165632"></a><a name="p958564795165632"></a>void </p>
<p id="p1545445105165632"><a name="p1545445105165632"></a><a name="p1545445105165632"></a>Aligns the view with the left of a sibling view. </p>
</td>
</tr>
<tr id="row1337064525165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1622830630165632"><a name="p1622830630165632"></a><a name="p1622830630165632"></a><a href="Graphic.md#gabb1ac454cdf95593c1e387d5e272433c">AlignRightToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p806369905165632"><a name="p806369905165632"></a><a name="p806369905165632"></a>void </p>
<p id="p1984814743165632"><a name="p1984814743165632"></a><a name="p1984814743165632"></a>Aligns the view with the right of a sibling view. </p>
</td>
</tr>
<tr id="row602595271165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2058826792165632"><a name="p2058826792165632"></a><a name="p2058826792165632"></a><a href="Graphic.md#ga903d7cbc59bac06d728b7f6435c9a504">AlignTopToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p899271075165632"><a name="p899271075165632"></a><a name="p899271075165632"></a>void </p>
<p id="p473825650165632"><a name="p473825650165632"></a><a name="p473825650165632"></a>Aligns the view with the top of a sibling view. </p>
</td>
</tr>
<tr id="row670251107165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p214187794165632"><a name="p214187794165632"></a><a name="p214187794165632"></a><a href="Graphic.md#ga7607c3f9661932c495d080e9d92fb1a3">AlignBottomToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p370017000165632"><a name="p370017000165632"></a><a name="p370017000165632"></a>void </p>
<p id="p1811781153165632"><a name="p1811781153165632"></a><a name="p1811781153165632"></a>Aligns the view with the bottom of a sibling view. </p>
</td>
</tr>
<tr id="row654451648165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1573529050165632"><a name="p1573529050165632"></a><a name="p1573529050165632"></a><a href="Graphic.md#gac23776dbc2fce7ff30d57438abfa5230">AlignHorCenterToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p330803484165632"><a name="p330803484165632"></a><a name="p330803484165632"></a>void </p>
<p id="p1863902044165632"><a name="p1863902044165632"></a><a name="p1863902044165632"></a>Aligns the view with the center of a sibling view in the x-axis. </p>
</td>
</tr>
<tr id="row499493161165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p654269613165632"><a name="p654269613165632"></a><a name="p654269613165632"></a><a href="Graphic.md#gad3caa27aa0cb73ec4656e7d23aa222de">AlignVerCenterToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1261737535165632"><a name="p1261737535165632"></a><a name="p1261737535165632"></a>void </p>
<p id="p1858457233165632"><a name="p1858457233165632"></a><a name="p1858457233165632"></a>Aligns the view with the center of a sibling view in the y-axis. </p>
</td>
</tr>
<tr id="row746220570165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p894142359165632"><a name="p894142359165632"></a><a name="p894142359165632"></a><a href="Graphic.md#ga58f1a34a943c4492970f901d63bbc3d8">LayoutLeftToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p498166879165632"><a name="p498166879165632"></a><a name="p498166879165632"></a>void </p>
<p id="p1735676026165632"><a name="p1735676026165632"></a><a name="p1735676026165632"></a>Lays out the view on the left of a sibling view. </p>
</td>
</tr>
<tr id="row489409660165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1613500469165632"><a name="p1613500469165632"></a><a name="p1613500469165632"></a><a href="Graphic.md#gac4cd64de5291759add164825a323a0d6">LayoutRightToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1321497016165632"><a name="p1321497016165632"></a><a name="p1321497016165632"></a>void </p>
<p id="p3331904165632"><a name="p3331904165632"></a><a name="p3331904165632"></a>Lays out the view on the right of a sibling view. </p>
</td>
</tr>
<tr id="row393679624165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p306362151165632"><a name="p306362151165632"></a><a name="p306362151165632"></a><a href="Graphic.md#gaaa8385807e3a9bea46f8dcc326252a70">LayoutTopToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2085003847165632"><a name="p2085003847165632"></a><a name="p2085003847165632"></a>void </p>
<p id="p1788776293165632"><a name="p1788776293165632"></a><a name="p1788776293165632"></a>Lays out the view on the above of a sibling view. </p>
</td>
</tr>
<tr id="row997199588165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1751818678165632"><a name="p1751818678165632"></a><a name="p1751818678165632"></a><a href="Graphic.md#gaa23a68e8ef0fb13b362218e71cf67ace">LayoutBottomToSibling</a> (const char *id, int16_t offset=0)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1026850590165632"><a name="p1026850590165632"></a><a name="p1026850590165632"></a>void </p>
<p id="p1839269811165632"><a name="p1839269811165632"></a><a name="p1839269811165632"></a>Lays out the view on the below of a sibling view. </p>
</td>
</tr>
<tr id="row556969475165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p739513141165632"><a name="p739513141165632"></a><a name="p739513141165632"></a><a href="Graphic.md#ga535942844ebee554d413e960634a2867">SetStyle</a> (<a href="OHOS-Style.md">Style</a> &amp;style)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p587226824165632"><a name="p587226824165632"></a><a name="p587226824165632"></a>void </p>
<p id="p152456856165632"><a name="p152456856165632"></a><a name="p152456856165632"></a>Sets the view style. </p>
</td>
</tr>
<tr id="row160627079165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1600701267165632"><a name="p1600701267165632"></a><a name="p1600701267165632"></a><a href="Graphic.md#ga0945c2f05815dc2e466ef9ceaca2f700">SetStyle</a> (uint8_t key, int64_t value)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p290782456165632"><a name="p290782456165632"></a><a name="p290782456165632"></a>virtual void </p>
<p id="p1812582372165632"><a name="p1812582372165632"></a><a name="p1812582372165632"></a>Sets a style. </p>
</td>
</tr>
<tr id="row1498643320165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p480999325165632"><a name="p480999325165632"></a><a name="p480999325165632"></a><a href="Graphic.md#ga4ea19bc9f4b487946c9e29e63b54a0e6">GetStyle</a> (uint8_t key) const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1029402627165632"><a name="p1029402627165632"></a><a name="p1029402627165632"></a>virtual int64_t </p>
<p id="p1492074496165632"><a name="p1492074496165632"></a><a name="p1492074496165632"></a>Obtains the value of a style. </p>
</td>
</tr>
<tr id="row917239071165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p368313236165632"><a name="p368313236165632"></a><a name="p368313236165632"></a><a href="Graphic.md#ga1b28213d4c2cd0f8324bce3fe56eb7bb">GetStyleConst</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1041183290165632"><a name="p1041183290165632"></a><a name="p1041183290165632"></a>const <a href="OHOS-Style.md">Style</a> &amp; </p>
<p id="p2081916268165632"><a name="p2081916268165632"></a><a name="p2081916268165632"></a>Obtains the view style. This function applies to scenarios where the style does not need to be modified, which saves memory. </p>
</td>
</tr>
<tr id="row1651789317165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p457587690165632"><a name="p457587690165632"></a><a name="p457587690165632"></a><a href="Graphic.md#ga4854963aa969ee20a6cd174a70f5cd23">operator new</a> (size_t size)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p938943965165632"><a name="p938943965165632"></a><a name="p938943965165632"></a>void * </p>
<p id="p1315207778165632"><a name="p1315207778165632"></a><a name="p1315207778165632"></a>Overrides the <strong id="b815694494165632"><a name="b815694494165632"></a><a name="b815694494165632"></a>new</strong> function. </p>
</td>
</tr>
<tr id="row1750664143165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1309614097165632"><a name="p1309614097165632"></a><a name="p1309614097165632"></a><a href="Graphic.md#gadf1997a0f56ac2b220e7f0f8e8e0a6ef">operator delete</a> (void *p)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1213478340165632"><a name="p1213478340165632"></a><a name="p1213478340165632"></a>void </p>
<p id="p2003686686165632"><a name="p2003686686165632"></a><a name="p2003686686165632"></a>Overrides the <strong id="b290419296165632"><a name="b290419296165632"></a><a name="b290419296165632"></a>delete</strong> function. </p>
</td>
</tr>
</tbody>
</table>

## Static Public Member Functions<a name="pub-static-methods"></a>

<a name="table709779601165632"></a>
<table><thead align="left"><tr id="row1297186081165632"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p613427300165632"><a name="p613427300165632"></a><a name="p613427300165632"></a>Function</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p818150235165632"><a name="p818150235165632"></a><a name="p818150235165632"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row630516659165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p916098652165632"><a name="p916098652165632"></a><a name="p916098652165632"></a><a href="Graphic.md#ga924ce70adcad92d852ba1d1faa441ac8">GetInstance</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p783181842165632"><a name="p783181842165632"></a><a name="p783181842165632"></a>static <a href="OHOS-RootView.md">RootView</a> * </p>
<p id="p2017125619165632"><a name="p2017125619165632"></a><a name="p2017125619165632"></a>Obtains a singleton <strong id="b1626358503165632"><a name="b1626358503165632"></a><a name="b1626358503165632"></a><a href="OHOS-RootView.md">RootView</a></strong> instance. </p>
</td>
</tr>
<tr id="row1311356606165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1923666132165632"><a name="p1923666132165632"></a><a name="p1923666132165632"></a><a href="Graphic.md#gabb3c193eea516b09f9ed6932b298ab9a">FindSubView</a> (const <a href="OHOS-UIView.md">UIView</a> &amp;parentView, const <a href="OHOS-UIView.md">UIView</a> *subView)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1472957158165632"><a name="p1472957158165632"></a><a name="p1472957158165632"></a>static bool </p>
<p id="p140364954165632"><a name="p140364954165632"></a><a name="p140364954165632"></a>Checks whether the target view is one of the child views of the specified parent view. </p>
</td>
</tr>
</tbody>
</table>

## Additional Inherited Members<a name="inherited"></a>

<a name="table1421909069165632"></a>
<table><thead align="left"><tr id="row1102522003165632"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p779010931165632"><a name="p779010931165632"></a><a name="p779010931165632"></a>Additional Inherited Member Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p95325564165632"><a name="p95325564165632"></a><a name="p95325564165632"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row2087332862165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1300413075165632"><a name="p1300413075165632"></a><a name="p1300413075165632"></a><a href="Graphic.md#ga34fe81b667a13b06a579600827e0531b">GetAllChildRelativeRect</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1582759402165632"><a name="p1582759402165632"></a><a name="p1582759402165632"></a>Obtains the rectangle area of a new view group after being adaptive to the size of all child views. </p>
</td>
</tr>
<tr id="row36220115165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1618936665165632"><a name="p1618936665165632"></a><a name="p1618936665165632"></a><a href="Graphic.md#ga06a5bd621f6532fe5c8fd08a2c1314b2">OnChildChanged</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p359012809165632"><a name="p359012809165632"></a><a name="p359012809165632"></a>Performs operations needed after a child view is added or removed. </p>
</td>
</tr>
<tr id="row444449776165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1302953249165632"><a name="p1302953249165632"></a><a name="p1302953249165632"></a><a href="Graphic.md#ga82ac8a2ca47014ecb5e142e1cd7d30c1">childrenHead_</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1638633923165632"><a name="p1638633923165632"></a><a name="p1638633923165632"></a>Indicates the pointer to the first child view of this view group. </p>
</td>
</tr>
<tr id="row606775936165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p328618252165632"><a name="p328618252165632"></a><a name="p328618252165632"></a><a href="Graphic.md#gaa0d6d1c8775e4765f8ae40d4573e0a83">childrenTail_</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1141861447165632"><a name="p1141861447165632"></a><a name="p1141861447165632"></a>Indicates the pointer to the last child view of this view group. </p>
</td>
</tr>
<tr id="row1273179986165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p320400327165632"><a name="p320400327165632"></a><a name="p320400327165632"></a><a href="Graphic.md#gaba49c636834e80a53373dd4c3687e298">childrenNum_</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p932932649165632"><a name="p932932649165632"></a><a name="p932932649165632"></a>Represents the number of child views. </p>
</td>
</tr>
<tr id="row1017599308165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2092841113165632"><a name="p2092841113165632"></a><a name="p2092841113165632"></a><a href="Graphic.md#ga732108111fa141d8ad1d8a76f761307b">isDragging_</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2117034799165632"><a name="p2117034799165632"></a><a name="p2117034799165632"></a>Specifies the sliding state of this view group. </p>
</td>
</tr>
<tr id="row563804569165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p276573205165632"><a name="p276573205165632"></a><a name="p276573205165632"></a><a href="Graphic.md#ga712f1c3641cb16674202fbc723af8b74">disallowIntercept_</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p946954858165632"><a name="p946954858165632"></a><a name="p946954858165632"></a>Specifies whether this view group is intercepted upon touch events. </p>
</td>
</tr>
<tr id="row1305151741165632"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1354136731165632"><a name="p1354136731165632"></a><a name="p1354136731165632"></a><a href="Graphic.md#ga1053e3677195fd4f98d68196d31d2cb5">isAutoSize_</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p348070249165632"><a name="p348070249165632"></a><a name="p348070249165632"></a>Specifies whether the size of this view group is adaptive to that of all child views. </p>
</td>
</tr>
</tbody>
</table>

