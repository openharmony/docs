# OHOS::AnimatorManager<a name="EN-US_TOPIC_0000001054799617"></a>

-   [Overview](#section842818002165633)
-   [Summary](#section981813086165633)
-   [Public Member Functions](#pub-methods)
-   [Static Public Member Functions](#pub-static-methods)

## **Overview**<a name="section842818002165633"></a>

**Related Modules:**

[Graphic](graphic.md)

**Description:**

Represents the animator manager. 

This is a singleton class used to manage  **[Animator](ohos-animator.md)**  instances.

See also
:   [Task](ohos-task.md) 

**Since:**

1.0

**Version:**

1.0

## **Summary**<a name="section981813086165633"></a>

## Public Member Functions<a name="pub-methods"></a>

<a name="table1471980344165633"></a>
<table><thead align="left"><tr id="row1257542546165633"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p866992708165633"><a name="p866992708165633"></a><a name="p866992708165633"></a>Function</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1304480807165633"><a name="p1304480807165633"></a><a name="p1304480807165633"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1235131250165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p649327797165633"><a name="p649327797165633"></a><a name="p649327797165633"></a><a href="graphic.md#gadfc9e9cf812f172fb1b6ca7efb7ba099">Init</a> () override</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p331485052165633"><a name="p331485052165633"></a><a name="p331485052165633"></a> void </p>
<p id="p1471799759165633"><a name="p1471799759165633"></a><a name="p1471799759165633"></a>Initializes this task. </p>
</td>
</tr>
<tr id="row265411545165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p399222143165633"><a name="p399222143165633"></a><a name="p399222143165633"></a><a href="graphic.md#ga8b60ed045dc2a3370498a3e6922d5400">Add</a> (<a href="ohos-animator.md">Animator</a> *animator)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1229243753165633"><a name="p1229243753165633"></a><a name="p1229243753165633"></a>void </p>
<p id="p780036434165633"><a name="p780036434165633"></a><a name="p780036434165633"></a>Adds the <strong id="b1719100570165633"><a name="b1719100570165633"></a><a name="b1719100570165633"></a><a href="ohos-animator.md">Animator</a></strong> instance to the <strong id="b1728053793165633"><a name="b1728053793165633"></a><a name="b1728053793165633"></a><a href="ohos-animatormanager.md">AnimatorManager</a></strong> linked list for management, so that the <strong id="b1583504059165633"><a name="b1583504059165633"></a><a name="b1583504059165633"></a>Run</strong> function of the <strong id="b1190512301165633"><a name="b1190512301165633"></a><a name="b1190512301165633"></a><a href="ohos-animator.md">Animator</a></strong> class is called once for each frame. </p>
</td>
</tr>
<tr id="row1553464071165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p143587825165633"><a name="p143587825165633"></a><a name="p143587825165633"></a><a href="graphic.md#ga493d53a9e4a47b79d30c0d37f96a69da">Remove</a> (const <a href="ohos-animator.md">Animator</a> *animator)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p78182987165633"><a name="p78182987165633"></a><a name="p78182987165633"></a>void </p>
<p id="p1089015991165633"><a name="p1089015991165633"></a><a name="p1089015991165633"></a>Removes the <strong id="b1909839878165633"><a name="b1909839878165633"></a><a name="b1909839878165633"></a><a href="ohos-animator.md">Animator</a></strong> instance from the <strong id="b1369708338165633"><a name="b1369708338165633"></a><a name="b1369708338165633"></a><a href="ohos-animatormanager.md">AnimatorManager</a></strong> linked list. </p>
</td>
</tr>
<tr id="row2000255519165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1302203241165633"><a name="p1302203241165633"></a><a name="p1302203241165633"></a><a href="graphic.md#ga8a7c3d733fc2112171a2e075dd425a5c">Callback</a> () override</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p72717811165633"><a name="p72717811165633"></a><a name="p72717811165633"></a> void </p>
<p id="p869619010165633"><a name="p869619010165633"></a><a name="p869619010165633"></a>Called when this task is executed. </p>
</td>
</tr>
<tr id="row800558951165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1168525279165633"><a name="p1168525279165633"></a><a name="p1168525279165633"></a><a href="graphic.md#gad94964a9139150b967ad640ea2076312">Task</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1515931337165633"><a name="p1515931337165633"></a><a name="p1515931337165633"></a>  </p>
<p id="p1839129463165633"><a name="p1839129463165633"></a><a name="p1839129463165633"></a>A constructor used to create a <strong id="b883107237165633"><a name="b883107237165633"></a><a name="b883107237165633"></a><a href="ohos-task.md">Task</a></strong> instance. </p>
</td>
</tr>
<tr id="row1905571613165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p362725515165633"><a name="p362725515165633"></a><a name="p362725515165633"></a><a href="graphic.md#gaa7c50eb360b6a4478b5332b8bf565940">Task</a> (uint32_t period)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1283898913165633"><a name="p1283898913165633"></a><a name="p1283898913165633"></a> </p>
<p id="p71823204165633"><a name="p71823204165633"></a><a name="p71823204165633"></a>A constructor used to create a <strong id="b1410128944165633"><a name="b1410128944165633"></a><a name="b1410128944165633"></a><a href="ohos-task.md">Task</a></strong> instance with the specified running period. </p>
</td>
</tr>
<tr id="row1886884364165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1957505009165633"><a name="p1957505009165633"></a><a name="p1957505009165633"></a><a href="graphic.md#ga293d4e1533ea98cdebbbffe1afed38ef">~Task</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1546990022165633"><a name="p1546990022165633"></a><a name="p1546990022165633"></a> virtual </p>
<p id="p457135781165633"><a name="p457135781165633"></a><a name="p457135781165633"></a>A destructor used to delete the <strong id="b1415142522165633"><a name="b1415142522165633"></a><a name="b1415142522165633"></a><a href="ohos-task.md">Task</a></strong> instance. </p>
</td>
</tr>
<tr id="row568763311165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p525673999165633"><a name="p525673999165633"></a><a name="p525673999165633"></a><a href="graphic.md#gac6e9fe7bde72bf506558a6f0d0287a92">SetPeriod</a> (uint32_t period)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1885733026165633"><a name="p1885733026165633"></a><a name="p1885733026165633"></a>void </p>
<p id="p1426249650165633"><a name="p1426249650165633"></a><a name="p1426249650165633"></a>Sets the running period for this task. </p>
</td>
</tr>
<tr id="row167723943165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p283621662165633"><a name="p283621662165633"></a><a name="p283621662165633"></a><a href="graphic.md#gabdbfe69d5f5da3cc5bbb1749d281af62">SetLastRun</a> (uint32_t lastRun)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p76374405165633"><a name="p76374405165633"></a><a name="p76374405165633"></a>void </p>
<p id="p2065138536165633"><a name="p2065138536165633"></a><a name="p2065138536165633"></a>Sets the end time for this task. </p>
</td>
</tr>
<tr id="row1094580857165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1853039595165633"><a name="p1853039595165633"></a><a name="p1853039595165633"></a><a href="graphic.md#gabd53b86c63b41172af155b8a7f86b84c">GetPeriod</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1404545767165633"><a name="p1404545767165633"></a><a name="p1404545767165633"></a>uint32_t </p>
<p id="p1355522921165633"><a name="p1355522921165633"></a><a name="p1355522921165633"></a>Obtains the running period of this task. </p>
</td>
</tr>
<tr id="row128354856165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p27438960165633"><a name="p27438960165633"></a><a name="p27438960165633"></a><a href="graphic.md#ga2d4c9fbb026686623ff4d6e0b19d4960">GetLastRun</a> () const</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p791837069165633"><a name="p791837069165633"></a><a name="p791837069165633"></a>uint32_t </p>
<p id="p2115499990165633"><a name="p2115499990165633"></a><a name="p2115499990165633"></a>Obtains the end time of this task. </p>
</td>
</tr>
<tr id="row765352346165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p553526484165633"><a name="p553526484165633"></a><a name="p553526484165633"></a><a href="graphic.md#ga96ed6680b2b9ad667e51d60554013020">TaskExecute</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1637349339165633"><a name="p1637349339165633"></a><a name="p1637349339165633"></a> void </p>
<p id="p544712675165633"><a name="p544712675165633"></a><a name="p544712675165633"></a>Executes this task. </p>
</td>
</tr>
<tr id="row2037023031165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1467501693165633"><a name="p1467501693165633"></a><a name="p1467501693165633"></a><a href="graphic.md#ga4854963aa969ee20a6cd174a70f5cd23">operator new</a> (size_t size)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p628259952165633"><a name="p628259952165633"></a><a name="p628259952165633"></a>void * </p>
<p id="p1264044643165633"><a name="p1264044643165633"></a><a name="p1264044643165633"></a>Overrides the <strong id="b177380305165633"><a name="b177380305165633"></a><a name="b177380305165633"></a>new</strong> function. </p>
</td>
</tr>
<tr id="row750344929165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2093291029165633"><a name="p2093291029165633"></a><a name="p2093291029165633"></a><a href="graphic.md#gadf1997a0f56ac2b220e7f0f8e8e0a6ef">operator delete</a> (void *p)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p764705953165633"><a name="p764705953165633"></a><a name="p764705953165633"></a>void </p>
<p id="p1703366488165633"><a name="p1703366488165633"></a><a name="p1703366488165633"></a>Overrides the <strong id="b1655450590165633"><a name="b1655450590165633"></a><a name="b1655450590165633"></a>delete</strong> function. </p>
</td>
</tr>
</tbody>
</table>

## Static Public Member Functions<a name="pub-static-methods"></a>

<a name="table1065199768165633"></a>
<table><thead align="left"><tr id="row1644711138165633"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1649814170165633"><a name="p1649814170165633"></a><a name="p1649814170165633"></a>Function</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p887188064165633"><a name="p887188064165633"></a><a name="p887188064165633"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1040648548165633"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1660761719165633"><a name="p1660761719165633"></a><a name="p1660761719165633"></a><a href="graphic.md#ga3ed818079b3501922f422b150f891d13">GetInstance</a> ()</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1903944264165633"><a name="p1903944264165633"></a><a name="p1903944264165633"></a>static <a href="ohos-animatormanager.md">AnimatorManager</a> * </p>
<p id="p1552380832165633"><a name="p1552380832165633"></a><a name="p1552380832165633"></a>Obtains the <strong id="b1032486720165633"><a name="b1032486720165633"></a><a name="b1032486720165633"></a><a href="ohos-animatormanager.md">AnimatorManager</a></strong> instance. </p>
</td>
</tr>
</tbody>
</table>

