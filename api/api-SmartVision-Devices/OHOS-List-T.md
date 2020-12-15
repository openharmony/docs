# OHOS::List< T \><a name="ZH-CN_TOPIC_0000001055678126"></a>

-   [Overview](#section112029841165635)
-   [Summary](#section1952163899165635)
-   [Public Member Functions](#pub-methods)

## **Overview**<a name="section112029841165635"></a>

**Related Modules:**

[Graphic](Graphic.md)

**Description:**

template<typename T\> class OHOS::List< T \>

Defines a linked list template class, which implements the data structure of bidirectional linked list and provides basic functions such as adding, deleting, inserting, clearing, popping up, and obtaining the size of the linked list. 

Parameters
:   **Since:**

1.0

**Version:**

1.0

## **Summary**<a name="section1952163899165635"></a>

## Public Member Functions<a name="pub-methods"></a>

<a name="table1984745982165635"></a>
<table><thead align="left"><tr id="row680866996165635"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p426880779165635"><a name="p426880779165635"></a><a name="p426880779165635"></a>Function</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p177827933165635"><a name="p177827933165635"></a><a name="p177827933165635"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row318042812165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1777274287165635"><a name="p1777274287165635"></a><a name="p1777274287165635"></a><a href="Graphic.md#ga92532583f91e7cb84255ddbacc34b3e6">List</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1553581868165635"><a name="p1553581868165635"></a><a name="p1553581868165635"></a> </p>
<p id="p1136020634165635"><a name="p1136020634165635"></a><a name="p1136020634165635"></a>A default constructor used to create a <strong id="b2137059864165635"><a name="b2137059864165635"></a><a name="b2137059864165635"></a><a href="OHOS-List-T.md">List</a></strong> instance. The initial size is <strong id="b1120555874165635"><a name="b1120555874165635"></a><a name="b1120555874165635"></a>0</strong>. </p>
</td>
</tr>
<tr id="row119520833165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1293956602165635"><a name="p1293956602165635"></a><a name="p1293956602165635"></a><a href="Graphic.md#gae36a1bb98e3352c2b97423ca340a51a9">~List</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p219617794165635"><a name="p219617794165635"></a><a name="p219617794165635"></a>virtual </p>
<p id="p798798292165635"><a name="p798798292165635"></a><a name="p798798292165635"></a>A destructor used to delete the <strong id="b209822821165635"><a name="b209822821165635"></a><a name="b209822821165635"></a><a href="OHOS-List-T.md">List</a></strong> instance. </p>
</td>
</tr>
<tr id="row604219397165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p780291015165635"><a name="p780291015165635"></a><a name="p780291015165635"></a><a href="Graphic.md#ga5e52d77c60c7710ca70ba3720b260c6a">Front</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p899472178165635"><a name="p899472178165635"></a><a name="p899472178165635"></a>const T </p>
<p id="p756131665165635"><a name="p756131665165635"></a><a name="p756131665165635"></a>Obtains the head node data of a linked list. </p>
</td>
</tr>
<tr id="row910456168165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p89072996165635"><a name="p89072996165635"></a><a name="p89072996165635"></a><a href="Graphic.md#gae5c3f6272b58c45f458c475a79ebfe3d">Back</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1583434282165635"><a name="p1583434282165635"></a><a name="p1583434282165635"></a>const T </p>
<p id="p820049372165635"><a name="p820049372165635"></a><a name="p820049372165635"></a>Obtains the tail node data of a linked list. </p>
</td>
</tr>
<tr id="row921390080165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1427712362165635"><a name="p1427712362165635"></a><a name="p1427712362165635"></a><a href="Graphic.md#gad26996a2802e32e89ecefa8311fe5d27">PushBack</a> (T data)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1964610046165635"><a name="p1964610046165635"></a><a name="p1964610046165635"></a>void </p>
<p id="p605398702165635"><a name="p605398702165635"></a><a name="p605398702165635"></a>Inserts data at the end of a linked list. </p>
</td>
</tr>
<tr id="row1532353928165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1502124602165635"><a name="p1502124602165635"></a><a name="p1502124602165635"></a><a href="Graphic.md#ga5084ab98dce9aab41b216f73a04ed8b6">PushFront</a> (T data)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p776887779165635"><a name="p776887779165635"></a><a name="p776887779165635"></a>void </p>
<p id="p858313863165635"><a name="p858313863165635"></a><a name="p858313863165635"></a>Inserts data at the start of a linked list. </p>
</td>
</tr>
<tr id="row754628560165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p494361909165635"><a name="p494361909165635"></a><a name="p494361909165635"></a><a href="Graphic.md#ga667b81954fd60474b575b4aa9c6bc193">PopBack</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1295018559165635"><a name="p1295018559165635"></a><a name="p1295018559165635"></a>void </p>
<p id="p2123917574165635"><a name="p2123917574165635"></a><a name="p2123917574165635"></a>Pops up a data record at the end of a linked list. </p>
</td>
</tr>
<tr id="row548688137165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p552465295165635"><a name="p552465295165635"></a><a name="p552465295165635"></a><a href="Graphic.md#ga0fa953b7476412923f25d079431f7189">PopFront</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p590727485165635"><a name="p590727485165635"></a><a name="p590727485165635"></a>void </p>
<p id="p282489849165635"><a name="p282489849165635"></a><a name="p282489849165635"></a>Pops up a data record at the start of a linked list. </p>
</td>
</tr>
<tr id="row104155177165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2034796618165635"><a name="p2034796618165635"></a><a name="p2034796618165635"></a><a href="Graphic.md#ga3bdd5d105c9e7d7e18456dfb55ba8b45">Insert</a> (<a href="OHOS-ListNode-T.md">ListNode</a>&lt; T &gt; *node, T data)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p358751571165635"><a name="p358751571165635"></a><a name="p358751571165635"></a>void </p>
<p id="p1770208796165635"><a name="p1770208796165635"></a><a name="p1770208796165635"></a>Inserts data before a specified node, which follows the inserted data node. </p>
</td>
</tr>
<tr id="row1805196026165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p267388466165635"><a name="p267388466165635"></a><a name="p267388466165635"></a><a href="Graphic.md#gaf3806e9581846930ad5bf063ced38367">Remove</a> (<a href="OHOS-ListNode-T.md">ListNode</a>&lt; T &gt; *node)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1714892438165635"><a name="p1714892438165635"></a><a name="p1714892438165635"></a>void </p>
<p id="p1969169867165635"><a name="p1969169867165635"></a><a name="p1969169867165635"></a>Deletes a data node. </p>
</td>
</tr>
<tr id="row939817188165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p6598609165635"><a name="p6598609165635"></a><a name="p6598609165635"></a><a href="Graphic.md#ga2292866786c9f888bc722ffcebc7c831">Clear</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1246484310165635"><a name="p1246484310165635"></a><a name="p1246484310165635"></a>void </p>
<p id="p2002991211165635"><a name="p2002991211165635"></a><a name="p2002991211165635"></a>Deletes all nodes from a linked list. </p>
</td>
</tr>
<tr id="row1255668620165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p285140010165635"><a name="p285140010165635"></a><a name="p285140010165635"></a><a href="Graphic.md#ga74dcfe1a4b37d6fabbcdb5f8049fb578">Head</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2077390972165635"><a name="p2077390972165635"></a><a name="p2077390972165635"></a><a href="OHOS-ListNode-T.md">ListNode</a>&lt; T &gt; * </p>
<p id="p1818416871165635"><a name="p1818416871165635"></a><a name="p1818416871165635"></a>Obtains the head node address of a linked list. </p>
</td>
</tr>
<tr id="row680472244165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p757518061165635"><a name="p757518061165635"></a><a name="p757518061165635"></a><a href="Graphic.md#gab60fda7a08504db2cf992de435ad1848">Tail</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2052140208165635"><a name="p2052140208165635"></a><a name="p2052140208165635"></a><a href="OHOS-ListNode-T.md">ListNode</a>&lt; T &gt; * </p>
<p id="p388481241165635"><a name="p388481241165635"></a><a name="p388481241165635"></a>Obtains the tail node address of a linked list. </p>
</td>
</tr>
<tr id="row881285602165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p581095916165635"><a name="p581095916165635"></a><a name="p581095916165635"></a><a href="Graphic.md#ga8fe8647f764773c29d3fa70c9b70eb2a">Begin</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p547048985165635"><a name="p547048985165635"></a><a name="p547048985165635"></a><a href="OHOS-ListNode-T.md">ListNode</a>&lt; T &gt; * </p>
<p id="p599958256165635"><a name="p599958256165635"></a><a name="p599958256165635"></a>Obtains the head node address of a linked list. </p>
</td>
</tr>
<tr id="row1597366128165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p870561826165635"><a name="p870561826165635"></a><a name="p870561826165635"></a><a href="Graphic.md#ga839de65540644c9725b31959367355c5">End</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1454770158165635"><a name="p1454770158165635"></a><a name="p1454770158165635"></a>const <a href="OHOS-ListNode-T.md">ListNode</a>&lt; T &gt; * </p>
<p id="p1859283043165635"><a name="p1859283043165635"></a><a name="p1859283043165635"></a>Obtains the end node address of a linked list. </p>
</td>
</tr>
<tr id="row204495948165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p79547494165635"><a name="p79547494165635"></a><a name="p79547494165635"></a><a href="Graphic.md#ga93ec1e9e9b778751aa53b7afb0b67258">Next</a> (const <a href="OHOS-ListNode-T.md">ListNode</a>&lt; T &gt; *node) const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p787681452165635"><a name="p787681452165635"></a><a name="p787681452165635"></a><a href="OHOS-ListNode-T.md">ListNode</a>&lt; T &gt; * </p>
<p id="p2084334696165635"><a name="p2084334696165635"></a><a name="p2084334696165635"></a>Obtains the address of the node following the specified <strong id="b452821008165635"><a name="b452821008165635"></a><a name="b452821008165635"></a>node</strong>. </p>
</td>
</tr>
<tr id="row853341551165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1607580242165635"><a name="p1607580242165635"></a><a name="p1607580242165635"></a><a href="Graphic.md#ga48f81f9faa9f4057ae8f84e437d90442">IsEmpty</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1566449271165635"><a name="p1566449271165635"></a><a name="p1566449271165635"></a>bool </p>
<p id="p1969350451165635"><a name="p1969350451165635"></a><a name="p1969350451165635"></a>Checks whether a linked list is empty. </p>
</td>
</tr>
<tr id="row392341436165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p512661201165635"><a name="p512661201165635"></a><a name="p512661201165635"></a><a href="Graphic.md#gae209f40639cdee7a5b07dc6587dac170">Size</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p969107549165635"><a name="p969107549165635"></a><a name="p969107549165635"></a>uint16_t </p>
<p id="p357992429165635"><a name="p357992429165635"></a><a name="p357992429165635"></a>Obtains the size of a linked list. </p>
</td>
</tr>
<tr id="row1805641529165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2010439154165635"><a name="p2010439154165635"></a><a name="p2010439154165635"></a><a href="Graphic.md#ga4854963aa969ee20a6cd174a70f5cd23">operator new</a> (size_t size)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p844519038165635"><a name="p844519038165635"></a><a name="p844519038165635"></a>void * </p>
<p id="p149145582165635"><a name="p149145582165635"></a><a name="p149145582165635"></a>Overrides the <strong id="b715370262165635"><a name="b715370262165635"></a><a name="b715370262165635"></a>new</strong> function. </p>
</td>
</tr>
<tr id="row439790050165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1625682496165635"><a name="p1625682496165635"></a><a name="p1625682496165635"></a><a href="Graphic.md#gadf1997a0f56ac2b220e7f0f8e8e0a6ef">operator delete</a> (void *p)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1809824728165635"><a name="p1809824728165635"></a><a name="p1809824728165635"></a>void </p>
<p id="p485708064165635"><a name="p485708064165635"></a><a name="p485708064165635"></a>Overrides the <strong id="b1916054916165635"><a name="b1916054916165635"></a><a name="b1916054916165635"></a>delete</strong> function. </p>
</td>
</tr>
</tbody>
</table>

