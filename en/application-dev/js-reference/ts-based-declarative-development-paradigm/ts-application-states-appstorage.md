# AppStorage<a name="EN-US_TOPIC_0000001119929480"></a>

**AppStorage**  is a singleton object in an application and is created by the UI framework when the application is started. It is designed to provide central storage for variable application state attributes.  **AppStorage**  contains all the state attributes that need to be accessed throughout the application. The  **AppStorage**  retains all attributes and their values as long as the application remains running, and the attribute values can be accessed through unique key values.

The UI component can synchronize the application state data with the  **AppStorage**  through the decorators. The implementation of the application service logic can also access the  **AppStorage**  through APIs.

The selection state property of the  **AppStorage**  can be synchronized with different data sources or data sinks. These data sources and data sinks can be local or remote on the device and have different functions, such as data persistence. Such data sources and data sinks can be implemented independently of the UI in service logics.

By default, the attributes in the  **AppStorage**  are changeable, and  **AppStorage**  can also use immutable \(read-only\) attributes.

## AppStorage APIs<a name="en-us_topic_0000001103218748_section89909382526"></a>

<a name="en-us_topic_0000001103218748_table109mcpsimp"></a>
<table><thead align="left"><tr id="en-us_topic_0000001103218748_row115mcpsimp"><th class="cellrowborder" valign="top" width="11.700000000000001%" id="mcps1.1.5.1.1"><p id="en-us_topic_0000001103218748_p117mcpsimp"><a name="en-us_topic_0000001103218748_p117mcpsimp"></a><a name="en-us_topic_0000001103218748_p117mcpsimp"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="13.96%" id="mcps1.1.5.1.2"><p id="en-us_topic_0000001103218748_p119mcpsimp"><a name="en-us_topic_0000001103218748_p119mcpsimp"></a><a name="en-us_topic_0000001103218748_p119mcpsimp"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="12.379999999999999%" id="mcps1.1.5.1.3"><p id="p1566112607"><a name="p1566112607"></a><a name="p1566112607"></a>Return Value</p>
</th>
<th class="cellrowborder" valign="top" width="61.96%" id="mcps1.1.5.1.4"><p id="en-us_topic_0000001103218748_p121mcpsimp"><a name="en-us_topic_0000001103218748_p121mcpsimp"></a><a name="en-us_topic_0000001103218748_p121mcpsimp"></a>Definition</p>
</th>
</tr>
</thead>
<tbody><tr id="en-us_topic_0000001103218748_row122mcpsimp"><td class="cellrowborder" valign="top" width="11.700000000000001%" headers="mcps1.1.5.1.1 "><p id="en-us_topic_0000001103218748_p124mcpsimp"><a name="en-us_topic_0000001103218748_p124mcpsimp"></a><a name="en-us_topic_0000001103218748_p124mcpsimp"></a>Link</p>
</td>
<td class="cellrowborder" valign="top" width="13.96%" headers="mcps1.1.5.1.2 "><p id="en-us_topic_0000001103218748_p126mcpsimp"><a name="en-us_topic_0000001103218748_p126mcpsimp"></a><a name="en-us_topic_0000001103218748_p126mcpsimp"></a>key: string</p>
</td>
<td class="cellrowborder" valign="top" width="12.379999999999999%" headers="mcps1.1.5.1.3 "><p id="p185664215018"><a name="p185664215018"></a><a name="p185664215018"></a>@Link</p>
</td>
<td class="cellrowborder" valign="top" width="61.96%" headers="mcps1.1.5.1.4 "><p id="en-us_topic_0000001103218748_p128mcpsimp"><a name="en-us_topic_0000001103218748_p128mcpsimp"></a><a name="en-us_topic_0000001103218748_p128mcpsimp"></a>Returns a bidirectional data binding to this attribute if there is data with a given key, meaning that changes made to the data by a variable or component will be synchronized to the <strong id="b256152252519"><a name="b256152252519"></a><a name="b256152252519"></a>AppStorage</strong>, and changes made to the data by the <strong id="b2044815293254"><a name="b2044815293254"></a><a name="b2044815293254"></a>AppStorage</strong> will be synchronized to the variable or component. If the attribute with this key does not exist or is read-only, <strong id="b105824492514"><a name="b105824492514"></a><a name="b105824492514"></a>undefined</strong> is returned.</p>
</td>
</tr>
<tr id="row327610512417"><td class="cellrowborder" valign="top" width="11.700000000000001%" headers="mcps1.1.5.1.1 "><p id="p142761957415"><a name="p142761957415"></a><a name="p142761957415"></a>SetAndLink</p>
</td>
<td class="cellrowborder" valign="top" width="13.96%" headers="mcps1.1.5.1.2 "><p id="p240416172411"><a name="p240416172411"></a><a name="p240416172411"></a>key : String</p>
<p id="p540414171943"><a name="p540414171943"></a><a name="p540414171943"></a>defaultValue: T</p>
</td>
<td class="cellrowborder" valign="top" width="12.379999999999999%" headers="mcps1.1.5.1.3 "><p id="p96661522744"><a name="p96661522744"></a><a name="p96661522744"></a>@Link</p>
</td>
<td class="cellrowborder" valign="top" width="61.96%" headers="mcps1.1.5.1.4 "><p id="p13277851841"><a name="p13277851841"></a><a name="p13277851841"></a>Similar to the <strong id="b673182616"><a name="b673182616"></a><a name="b673182616"></a>Link</strong> API. If the current key is stored in the <strong id="b117871016261"><a name="b117871016261"></a><a name="b117871016261"></a>AppStorage</strong>, the value corresponding to the key is returned. If the key has not been created, a <strong id="b1132564213289"><a name="b1132564213289"></a><a name="b1132564213289"></a>Link</strong> instance corresponding to the default value is created and returned.</p>
</td>
</tr>
<tr id="en-us_topic_0000001103218748_row129mcpsimp"><td class="cellrowborder" valign="top" width="11.700000000000001%" headers="mcps1.1.5.1.1 "><p id="en-us_topic_0000001103218748_p131mcpsimp"><a name="en-us_topic_0000001103218748_p131mcpsimp"></a><a name="en-us_topic_0000001103218748_p131mcpsimp"></a>Prop</p>
</td>
<td class="cellrowborder" valign="top" width="13.96%" headers="mcps1.1.5.1.2 "><p id="en-us_topic_0000001103218748_p133mcpsimp"><a name="en-us_topic_0000001103218748_p133mcpsimp"></a><a name="en-us_topic_0000001103218748_p133mcpsimp"></a>key: string</p>
</td>
<td class="cellrowborder" valign="top" width="12.379999999999999%" headers="mcps1.1.5.1.3 "><p id="p55660211014"><a name="p55660211014"></a><a name="p55660211014"></a>@Prop</p>
</td>
<td class="cellrowborder" valign="top" width="61.96%" headers="mcps1.1.5.1.4 "><p id="en-us_topic_0000001103218748_p135mcpsimp"><a name="en-us_topic_0000001103218748_p135mcpsimp"></a><a name="en-us_topic_0000001103218748_p135mcpsimp"></a>Returns a one-way data binding to an attribute with a given key if the attribute exists. This one-way binding means that changes to the attribute can only be synchronized to variables or components through <strong id="b1983822114277"><a name="b1983822114277"></a><a name="b1983822114277"></a>AppStorage</strong>. The variable returned by this method is an immutable variable, which is applicable to the variable and immutable state attributes. If the attribute with this key does not exist, <strong id="b1420194122713"><a name="b1420194122713"></a><a name="b1420194122713"></a>undefined</strong> is returned.</p>
<div class="note" id="en-us_topic_0000001103218748_note1886831124618"><a name="en-us_topic_0000001103218748_note1886831124618"></a><a name="en-us_topic_0000001103218748_note1886831124618"></a><span class="notetitle"> NOTE: </span><div class="notebody"><p id="p522015411452"><a name="p522015411452"></a><a name="p522015411452"></a>The attribute value type corresponding to the <strong id="b131815112279"><a name="b131815112279"></a><a name="b131815112279"></a>prop</strong> method is of a simple type.</p>
</div></div>
</td>
</tr>
<tr id="row13351212193"><td class="cellrowborder" valign="top" width="11.700000000000001%" headers="mcps1.1.5.1.1 "><p id="p835812194"><a name="p835812194"></a><a name="p835812194"></a>SetAndProp</p>
</td>
<td class="cellrowborder" valign="top" width="13.96%" headers="mcps1.1.5.1.2 "><p id="p1228852918920"><a name="p1228852918920"></a><a name="p1228852918920"></a>key : string</p>
<p id="p132888294919"><a name="p132888294919"></a><a name="p132888294919"></a>defaultValue: S</p>
</td>
<td class="cellrowborder" valign="top" width="12.379999999999999%" headers="mcps1.1.5.1.3 "><p id="p035712792"><a name="p035712792"></a><a name="p035712792"></a>@Prop</p>
</td>
<td class="cellrowborder" valign="top" width="61.96%" headers="mcps1.1.5.1.4 "><p id="p18161144416910"><a name="p18161144416910"></a><a name="p18161144416910"></a>Similar to the <strong id="b129457583275"><a name="b129457583275"></a><a name="b129457583275"></a>Prop</strong> API. If the current key is stored in the <strong id="b12291153112817"><a name="b12291153112817"></a><a name="b12291153112817"></a>AppStorage</strong>, the value corresponding to the key is returned. If the key has not been created, a <strong id="b19872518172815"><a name="b19872518172815"></a><a name="b19872518172815"></a>Prop</strong> instance corresponding to the default value is created and returned.</p>
</td>
</tr>
<tr id="en-us_topic_0000001103218748_row136mcpsimp"><td class="cellrowborder" valign="top" width="11.700000000000001%" headers="mcps1.1.5.1.1 "><p id="en-us_topic_0000001103218748_p138mcpsimp"><a name="en-us_topic_0000001103218748_p138mcpsimp"></a><a name="en-us_topic_0000001103218748_p138mcpsimp"></a>Has</p>
</td>
<td class="cellrowborder" valign="top" width="13.96%" headers="mcps1.1.5.1.2 "><p id="en-us_topic_0000001103218748_p140mcpsimp"><a name="en-us_topic_0000001103218748_p140mcpsimp"></a><a name="en-us_topic_0000001103218748_p140mcpsimp"></a>key: string</p>
</td>
<td class="cellrowborder" valign="top" width="12.379999999999999%" headers="mcps1.1.5.1.3 "><p id="p125661627019"><a name="p125661627019"></a><a name="p125661627019"></a>boolean</p>
</td>
<td class="cellrowborder" valign="top" width="61.96%" headers="mcps1.1.5.1.4 "><p id="en-us_topic_0000001103218748_p142mcpsimp"><a name="en-us_topic_0000001103218748_p142mcpsimp"></a><a name="en-us_topic_0000001103218748_p142mcpsimp"></a>Checks whether the attribute corresponding to the key value exists.</p>
</td>
</tr>
<tr id="en-us_topic_0000001103218748_row150mcpsimp"><td class="cellrowborder" valign="top" width="11.700000000000001%" headers="mcps1.1.5.1.1 "><p id="en-us_topic_0000001103218748_p1363415429353"><a name="en-us_topic_0000001103218748_p1363415429353"></a><a name="en-us_topic_0000001103218748_p1363415429353"></a>Keys</p>
</td>
<td class="cellrowborder" valign="top" width="13.96%" headers="mcps1.1.5.1.2 "><p id="en-us_topic_0000001103218748_p154mcpsimp"><a name="en-us_topic_0000001103218748_p154mcpsimp"></a><a name="en-us_topic_0000001103218748_p154mcpsimp"></a>void</p>
</td>
<td class="cellrowborder" valign="top" width="12.379999999999999%" headers="mcps1.1.5.1.3 "><p id="p19566522014"><a name="p19566522014"></a><a name="p19566522014"></a>array&lt;string&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="61.96%" headers="mcps1.1.5.1.4 "><p id="en-us_topic_0000001103218748_p156mcpsimp"><a name="en-us_topic_0000001103218748_p156mcpsimp"></a><a name="en-us_topic_0000001103218748_p156mcpsimp"></a>Returns an array of strings containing all keys.</p>
</td>
</tr>
<tr id="row3460194012589"><td class="cellrowborder" valign="top" width="11.700000000000001%" headers="mcps1.1.5.1.1 "><p id="p1846mcpsimp"><a name="p1846mcpsimp"></a><a name="p1846mcpsimp"></a>Get</p>
</td>
<td class="cellrowborder" valign="top" width="13.96%" headers="mcps1.1.5.1.2 "><p id="p263019299243"><a name="p263019299243"></a><a name="p263019299243"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="12.379999999999999%" headers="mcps1.1.5.1.3 "><p id="p14566921105"><a name="p14566921105"></a><a name="p14566921105"></a>T or undefined</p>
</td>
<td class="cellrowborder" valign="top" width="61.96%" headers="mcps1.1.5.1.4 "><p id="p1850mcpsimp"><a name="p1850mcpsimp"></a><a name="p1850mcpsimp"></a>Obtains the value of the key.</p>
</td>
</tr>
<tr id="row4460184019583"><td class="cellrowborder" valign="top" width="11.700000000000001%" headers="mcps1.1.5.1.1 "><p id="p4826171212519"><a name="p4826171212519"></a><a name="p4826171212519"></a>Set</p>
</td>
<td class="cellrowborder" valign="top" width="13.96%" headers="mcps1.1.5.1.2 "><p id="p11826512152517"><a name="p11826512152517"></a><a name="p11826512152517"></a>string, newValue : T</p>
</td>
<td class="cellrowborder" valign="top" width="12.379999999999999%" headers="mcps1.1.5.1.3 "><p id="p185671321506"><a name="p185671321506"></a><a name="p185671321506"></a>void</p>
</td>
<td class="cellrowborder" valign="top" width="61.96%" headers="mcps1.1.5.1.4 "><p id="p1982671202510"><a name="p1982671202510"></a><a name="p1982671202510"></a>Replaces the value of a saved key.</p>
</td>
</tr>
<tr id="row546074014585"><td class="cellrowborder" valign="top" width="11.700000000000001%" headers="mcps1.1.5.1.1 "><p id="p1799852316279"><a name="p1799852316279"></a><a name="p1799852316279"></a>SetOrCreate</p>
</td>
<td class="cellrowborder" valign="top" width="13.96%" headers="mcps1.1.5.1.2 "><p id="p146505413272"><a name="p146505413272"></a><a name="p146505413272"></a>string, newValue : T</p>
</td>
<td class="cellrowborder" valign="top" width="12.379999999999999%" headers="mcps1.1.5.1.3 "><p id="p168731437917"><a name="p168731437917"></a><a name="p168731437917"></a>boolean</p>
</td>
<td class="cellrowborder" valign="top" width="61.96%" headers="mcps1.1.5.1.4 "><p id="p639717522815"><a name="p639717522815"></a><a name="p639717522815"></a>If an attribute with the same name exists: returns <strong id="b28651779307"><a name="b28651779307"></a><a name="b28651779307"></a>true</strong> if the attribute can be modified, and <strong id="b57431415123013"><a name="b57431415123013"></a><a name="b57431415123013"></a>false</strong> otherwise.</p>
<p id="p17541322112611"><a name="p17541322112611"></a><a name="p17541322112611"></a>If the attribute with the same name does not exist: Create the first attribute whose value is the <strong id="b13513114214300"><a name="b13513114214300"></a><a name="b13513114214300"></a>defaultValue</strong>. The <strong id="b3232681318"><a name="b3232681318"></a><a name="b3232681318"></a>null</strong> and <strong id="b17924171163110"><a name="b17924171163110"></a><a name="b17924171163110"></a>undefined</strong> values are not supported.</p>
</td>
</tr>
<tr id="row350321491214"><td class="cellrowborder" valign="top" width="11.700000000000001%" headers="mcps1.1.5.1.1 "><p id="p17503121481216"><a name="p17503121481216"></a><a name="p17503121481216"></a>Delete</p>
</td>
<td class="cellrowborder" valign="top" width="13.96%" headers="mcps1.1.5.1.2 "><p id="p6503161417122"><a name="p6503161417122"></a><a name="p6503161417122"></a>key : string</p>
</td>
<td class="cellrowborder" valign="top" width="12.379999999999999%" headers="mcps1.1.5.1.3 "><p id="p205031814191212"><a name="p205031814191212"></a><a name="p205031814191212"></a>boolean</p>
</td>
<td class="cellrowborder" valign="top" width="61.96%" headers="mcps1.1.5.1.4 "><p id="p05031014141211"><a name="p05031014141211"></a><a name="p05031014141211"></a>Deletes an attribute. If the attribute exists, <strong id="b1920473013116"><a name="b1920473013116"></a><a name="b1920473013116"></a>true</strong> is returned. Otherwise, <strong id="b98112040193114"><a name="b98112040193114"></a><a name="b98112040193114"></a>false</strong> is returned.</p>
</td>
</tr>
<tr id="row12261203911401"><td class="cellrowborder" valign="top" width="11.700000000000001%" headers="mcps1.1.5.1.1 "><p id="p202611739204016"><a name="p202611739204016"></a><a name="p202611739204016"></a>Clear</p>
</td>
<td class="cellrowborder" valign="top" width="13.96%" headers="mcps1.1.5.1.2 "><p id="p526118395407"><a name="p526118395407"></a><a name="p526118395407"></a>none</p>
</td>
<td class="cellrowborder" valign="top" width="12.379999999999999%" headers="mcps1.1.5.1.3 "><p id="p326173910400"><a name="p326173910400"></a><a name="p326173910400"></a>boolean</p>
</td>
<td class="cellrowborder" valign="top" width="61.96%" headers="mcps1.1.5.1.4 "><p id="p22611139114012"><a name="p22611139114012"></a><a name="p22611139114012"></a>Deletes all attributes. If a state variable still references any of the attributes, <strong id="b15300751153119"><a name="b15300751153119"></a><a name="b15300751153119"></a>false</strong> is returned.</p>
</td>
</tr>
<tr id="row14209473411"><td class="cellrowborder" valign="top" width="11.700000000000001%" headers="mcps1.1.5.1.1 "><p id="p12420347194115"><a name="p12420347194115"></a><a name="p12420347194115"></a>IsMutable</p>
</td>
<td class="cellrowborder" valign="top" width="13.96%" headers="mcps1.1.5.1.2 "><p id="p10420174754114"><a name="p10420174754114"></a><a name="p10420174754114"></a>key: string</p>
</td>
<td class="cellrowborder" valign="top" width="12.379999999999999%" headers="mcps1.1.5.1.3 ">&nbsp;&nbsp;</td>
<td class="cellrowborder" valign="top" width="61.96%" headers="mcps1.1.5.1.4 "><p id="p1942074711417"><a name="p1942074711417"></a><a name="p1942074711417"></a>Specifies whether the attribute exists and can be changed.</p>
</td>
</tr>
</tbody>
</table>

>![](../../public_sys-resources/icon-note.gif) **NOTE:** 
>Currently, the API can process only basic data and cannot modify a value in an object.

## Example<a name="en-us_topic_0000001103218748_section195112274815"></a>

```
let link1 = AppStorage.Link('PropA')
let link2 = AppStorage.Link('PropA')
let prop = AppStorage.Prop('PropA')

link1 = 47  // causes link1 == link2 == prop == 47
link2 = link1 + prop  // causes link1 == link2 == prop == 94
prop = 1  // error, prop is immutable
```

