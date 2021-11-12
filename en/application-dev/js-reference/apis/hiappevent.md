# HiAppEvent<a name="EN-US_TOPIC_0000001162414647"></a>

## Modules to Import<a name="en-us_topic_0000001150092213_s56d19203690d4782bfc74069abb6bd71"></a>

```
import hiappevent from '@ohos.hiappevent';
```

## Required Permissions<a name="en-us_topic_0000001150092213_section11257113618419"></a>

None.

## Functions<a name="en-us_topic_0000001150092213_section125675489541"></a>

## write\(string, EventType, any..., AsyncCallback<number\>\)<a name="en-us_topic_0000001150092213_section192192415554"></a>

Writes event information to the event file of the current day. This function supports variable parameters and uses an asynchronous callback to return the result.

**Parameters**

<a name="en-us_topic_0000001150092213_table1051173843112"></a>
<table><thead align="left"><tr id="en-us_topic_0000001150092213_row551638113119"><th class="cellrowborder" valign="top" width="13.969999999999999%" id="mcps1.1.5.1.1"><p id="en-us_topic_0000001150092213_p2512384316"><a name="en-us_topic_0000001150092213_p2512384316"></a><a name="en-us_topic_0000001150092213_p2512384316"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="13.389999999999999%" id="mcps1.1.5.1.2"><p id="en-us_topic_0000001150092213_p1551113810318"><a name="en-us_topic_0000001150092213_p1551113810318"></a><a name="en-us_topic_0000001150092213_p1551113810318"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="8.23%" id="mcps1.1.5.1.3"><p id="en-us_topic_0000001150092213_p3519387317"><a name="en-us_topic_0000001150092213_p3519387317"></a><a name="en-us_topic_0000001150092213_p3519387317"></a>Mandatory</p>
</th>
<th class="cellrowborder" valign="top" width="64.41%" id="mcps1.1.5.1.4"><p id="en-us_topic_0000001150092213_p1351123815315"><a name="en-us_topic_0000001150092213_p1351123815315"></a><a name="en-us_topic_0000001150092213_p1351123815315"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="en-us_topic_0000001150092213_row13511538183119"><td class="cellrowborder" valign="top" width="13.969999999999999%" headers="mcps1.1.5.1.1 "><p id="en-us_topic_0000001150092213_p1551838113117"><a name="en-us_topic_0000001150092213_p1551838113117"></a><a name="en-us_topic_0000001150092213_p1551838113117"></a>eventName</p>
</td>
<td class="cellrowborder" valign="top" width="13.389999999999999%" headers="mcps1.1.5.1.2 "><p id="en-us_topic_0000001150092213_p1051133893111"><a name="en-us_topic_0000001150092213_p1051133893111"></a><a name="en-us_topic_0000001150092213_p1051133893111"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="8.23%" headers="mcps1.1.5.1.3 "><p id="en-us_topic_0000001150092213_p155183816314"><a name="en-us_topic_0000001150092213_p155183816314"></a><a name="en-us_topic_0000001150092213_p155183816314"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="64.41%" headers="mcps1.1.5.1.4 "><p id="en-us_topic_0000001150092213_p1551173863113"><a name="en-us_topic_0000001150092213_p1551173863113"></a><a name="en-us_topic_0000001150092213_p1551173863113"></a>Indicates the app event name.</p>
</td>
</tr>
<tr id="en-us_topic_0000001150092213_row18516388310"><td class="cellrowborder" valign="top" width="13.969999999999999%" headers="mcps1.1.5.1.1 "><p id="en-us_topic_0000001150092213_p3511938103117"><a name="en-us_topic_0000001150092213_p3511938103117"></a><a name="en-us_topic_0000001150092213_p3511938103117"></a>eventType</p>
</td>
<td class="cellrowborder" valign="top" width="13.389999999999999%" headers="mcps1.1.5.1.2 "><p id="en-us_topic_0000001150092213_p55183820313"><a name="en-us_topic_0000001150092213_p55183820313"></a><a name="en-us_topic_0000001150092213_p55183820313"></a>EventType</p>
</td>
<td class="cellrowborder" valign="top" width="8.23%" headers="mcps1.1.5.1.3 "><p id="en-us_topic_0000001150092213_p13511138123117"><a name="en-us_topic_0000001150092213_p13511138123117"></a><a name="en-us_topic_0000001150092213_p13511138123117"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="64.41%" headers="mcps1.1.5.1.4 "><p id="en-us_topic_0000001150092213_p75213386311"><a name="en-us_topic_0000001150092213_p75213386311"></a><a name="en-us_topic_0000001150092213_p75213386311"></a>Indicates the app event type.</p>
</td>
</tr>
<tr id="en-us_topic_0000001150092213_row05293803113"><td class="cellrowborder" valign="top" width="13.969999999999999%" headers="mcps1.1.5.1.1 "><p id="en-us_topic_0000001150092213_p1452193814313"><a name="en-us_topic_0000001150092213_p1452193814313"></a><a name="en-us_topic_0000001150092213_p1452193814313"></a>params</p>
</td>
<td class="cellrowborder" valign="top" width="13.389999999999999%" headers="mcps1.1.5.1.2 "><p id="en-us_topic_0000001150092213_p185283815313"><a name="en-us_topic_0000001150092213_p185283815313"></a><a name="en-us_topic_0000001150092213_p185283815313"></a>any...</p>
</td>
<td class="cellrowborder" valign="top" width="8.23%" headers="mcps1.1.5.1.3 "><p id="en-us_topic_0000001150092213_p25283811312"><a name="en-us_topic_0000001150092213_p25283811312"></a><a name="en-us_topic_0000001150092213_p25283811312"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="64.41%" headers="mcps1.1.5.1.4 "><p id="en-us_topic_0000001150092213_p552193863115"><a name="en-us_topic_0000001150092213_p552193863115"></a><a name="en-us_topic_0000001150092213_p552193863115"></a>Indicates an array of parameters of the app event. Enter the name and value of each parameter in sequence. A parameter name must be a string, and a parameter value must be a string, number, boolean, or Array (which can only be a string, number, or boolean).</p>
</td>
</tr>
<tr id="en-us_topic_0000001150092213_row13838183316719"><td class="cellrowborder" valign="top" width="13.969999999999999%" headers="mcps1.1.5.1.1 "><p id="en-us_topic_0000001150092213_p28393335711"><a name="en-us_topic_0000001150092213_p28393335711"></a><a name="en-us_topic_0000001150092213_p28393335711"></a>callback</p>
</td>
<td class="cellrowborder" valign="top" width="13.389999999999999%" headers="mcps1.1.5.1.2 "><p id="en-us_topic_0000001150092213_p48396339719"><a name="en-us_topic_0000001150092213_p48396339719"></a><a name="en-us_topic_0000001150092213_p48396339719"></a>AsyncCallback&lt;number&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="8.23%" headers="mcps1.1.5.1.3 "><p id="en-us_topic_0000001150092213_p1783913331671"><a name="en-us_topic_0000001150092213_p1783913331671"></a><a name="en-us_topic_0000001150092213_p1783913331671"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="64.41%" headers="mcps1.1.5.1.4 "><p id="en-us_topic_0000001150092213_p9749191318299"><a name="en-us_topic_0000001150092213_p9749191318299"></a><a name="en-us_topic_0000001150092213_p9749191318299"></a>Indicates the callback function, which can be used to process the received return value.</p>
<a name="en-us_topic_0000001150092213_ul988644310291"></a><a name="en-us_topic_0000001150092213_ul988644310291"></a><ul id="en-us_topic_0000001150092213_ul988644310291"><li>Value <strong id="en-us_topic_0000001150092213_b293623314256"><a name="en-us_topic_0000001150092213_b293623314256"></a><a name="en-us_topic_0000001150092213_b293623314256"></a>0</strong> indicates that the event parameter verification is successful, and the event will be written to the event file asynchronously. </li><li>A value greater than 0 indicates that invalid parameters are present in the event, and the event will be written to the event file asynchronously after the invalid parameters are ignored. </li><li>A value less than 0 indicates that the event parameter verification fails, and the event will not be written to the event file asynchronously.</li></ul>
</td>
</tr>
</tbody>
</table>

**Example**

```
hiappevent.write("testEvent", hiappevent.EventType.FAULT, "intData", 100, "strData", "strValue", (err, value) => {
    if (err) {
        // Event writing failed: The event contains invalid parameters or the event parameter verification fails.
        console.error(`failed to write event because ${err}`);
        return;
    }

    // Event writing succeeded.
    console.log(`success to write event: ${value}`);
});
```

## write\(string, EventType, any...\)<a name="en-us_topic_0000001150092213_section1696563334210"></a>

Writes event information to the event file of the current day. This function supports variable parameters and uses an asynchronous promise to return the result.

**Parameters**

<a name="en-us_topic_0000001150092213_table1096583374216"></a>
<table><thead align="left"><tr id="en-us_topic_0000001150092213_row1296612339427"><th class="cellrowborder" valign="top" width="13.969999999999999%" id="mcps1.1.5.1.1"><p id="en-us_topic_0000001150092213_p696663354219"><a name="en-us_topic_0000001150092213_p696663354219"></a><a name="en-us_topic_0000001150092213_p696663354219"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="13.389999999999999%" id="mcps1.1.5.1.2"><p id="en-us_topic_0000001150092213_p179660332421"><a name="en-us_topic_0000001150092213_p179660332421"></a><a name="en-us_topic_0000001150092213_p179660332421"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="8.23%" id="mcps1.1.5.1.3"><p id="en-us_topic_0000001150092213_p11966143312427"><a name="en-us_topic_0000001150092213_p11966143312427"></a><a name="en-us_topic_0000001150092213_p11966143312427"></a>Mandatory</p>
</th>
<th class="cellrowborder" valign="top" width="64.41%" id="mcps1.1.5.1.4"><p id="en-us_topic_0000001150092213_p596610331427"><a name="en-us_topic_0000001150092213_p596610331427"></a><a name="en-us_topic_0000001150092213_p596610331427"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="en-us_topic_0000001150092213_row6966113310425"><td class="cellrowborder" valign="top" width="13.969999999999999%" headers="mcps1.1.5.1.1 "><p id="en-us_topic_0000001150092213_p796623344217"><a name="en-us_topic_0000001150092213_p796623344217"></a><a name="en-us_topic_0000001150092213_p796623344217"></a>eventName</p>
</td>
<td class="cellrowborder" valign="top" width="13.389999999999999%" headers="mcps1.1.5.1.2 "><p id="en-us_topic_0000001150092213_p596683319422"><a name="en-us_topic_0000001150092213_p596683319422"></a><a name="en-us_topic_0000001150092213_p596683319422"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="8.23%" headers="mcps1.1.5.1.3 "><p id="en-us_topic_0000001150092213_p17966193374218"><a name="en-us_topic_0000001150092213_p17966193374218"></a><a name="en-us_topic_0000001150092213_p17966193374218"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="64.41%" headers="mcps1.1.5.1.4 "><p id="en-us_topic_0000001150092213_p19661533194218"><a name="en-us_topic_0000001150092213_p19661533194218"></a><a name="en-us_topic_0000001150092213_p19661533194218"></a>Indicates the app event name.</p>
</td>
</tr>
<tr id="en-us_topic_0000001150092213_row896623314429"><td class="cellrowborder" valign="top" width="13.969999999999999%" headers="mcps1.1.5.1.1 "><p id="en-us_topic_0000001150092213_p17966153316425"><a name="en-us_topic_0000001150092213_p17966153316425"></a><a name="en-us_topic_0000001150092213_p17966153316425"></a>eventType</p>
</td>
<td class="cellrowborder" valign="top" width="13.389999999999999%" headers="mcps1.1.5.1.2 "><p id="en-us_topic_0000001150092213_p496613364212"><a name="en-us_topic_0000001150092213_p496613364212"></a><a name="en-us_topic_0000001150092213_p496613364212"></a>EventType</p>
</td>
<td class="cellrowborder" valign="top" width="8.23%" headers="mcps1.1.5.1.3 "><p id="en-us_topic_0000001150092213_p10966233134216"><a name="en-us_topic_0000001150092213_p10966233134216"></a><a name="en-us_topic_0000001150092213_p10966233134216"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="64.41%" headers="mcps1.1.5.1.4 "><p id="en-us_topic_0000001150092213_p1796643344218"><a name="en-us_topic_0000001150092213_p1796643344218"></a><a name="en-us_topic_0000001150092213_p1796643344218"></a>Indicates the app event type.</p>
</td>
</tr>
<tr id="en-us_topic_0000001150092213_row1696653315423"><td class="cellrowborder" valign="top" width="13.969999999999999%" headers="mcps1.1.5.1.1 "><p id="en-us_topic_0000001150092213_p109660332428"><a name="en-us_topic_0000001150092213_p109660332428"></a><a name="en-us_topic_0000001150092213_p109660332428"></a>params</p>
</td>
<td class="cellrowborder" valign="top" width="13.389999999999999%" headers="mcps1.1.5.1.2 "><p id="en-us_topic_0000001150092213_p1396663313428"><a name="en-us_topic_0000001150092213_p1396663313428"></a><a name="en-us_topic_0000001150092213_p1396663313428"></a>any...</p>
</td>
<td class="cellrowborder" valign="top" width="8.23%" headers="mcps1.1.5.1.3 "><p id="en-us_topic_0000001150092213_p1196673354215"><a name="en-us_topic_0000001150092213_p1196673354215"></a><a name="en-us_topic_0000001150092213_p1196673354215"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="64.41%" headers="mcps1.1.5.1.4 "><p id="en-us_topic_0000001150092213_p199671338422"><a name="en-us_topic_0000001150092213_p199671338422"></a><a name="en-us_topic_0000001150092213_p199671338422"></a>Indicates an array of parameters of the app event. Enter the name and value of each parameter in sequence. A parameter name must be a string, and a parameter value must be a string, number, boolean, or Array (which can only be a string, number, or boolean).</p>
</td>
</tr>
</tbody>
</table>

**Return Values**

<a name="en-us_topic_0000001150092213_table106721328171713"></a>
<table><thead align="left"><tr id="en-us_topic_0000001150092213_row9672122817176"><th class="cellrowborder" valign="top" width="26.06%" id="mcps1.1.3.1.1"><p id="en-us_topic_0000001150092213_p106728288171"><a name="en-us_topic_0000001150092213_p106728288171"></a><a name="en-us_topic_0000001150092213_p106728288171"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="73.94%" id="mcps1.1.3.1.2"><p id="en-us_topic_0000001150092213_p5672112817178"><a name="en-us_topic_0000001150092213_p5672112817178"></a><a name="en-us_topic_0000001150092213_p5672112817178"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="en-us_topic_0000001150092213_row06721528191711"><td class="cellrowborder" valign="top" width="26.06%" headers="mcps1.1.3.1.1 "><p id="en-us_topic_0000001150092213_p107821612171919"><a name="en-us_topic_0000001150092213_p107821612171919"></a><a name="en-us_topic_0000001150092213_p107821612171919"></a>Promise&lt;void&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="73.94%" headers="mcps1.1.3.1.2 "><p id="en-us_topic_0000001150092213_p4672828141718"><a name="en-us_topic_0000001150092213_p4672828141718"></a><a name="en-us_topic_0000001150092213_p4672828141718"></a>Indicates the promise used to return the execution result.</p>
</td>
</tr>
</tbody>
</table>

**Example**

```
hiappevent.write("testEvent", hiappevent.EventType.FAULT, "intData", 100, "strData", "strValue")
    .then((value) => {
        // Event writing succeeded.
        console.log(`success to write event: ${value}`);
    }).catch((err) => {
        // Event writing failed: The event contains invalid parameters or the event parameter verification fails.
        console.error(`failed to write event because ${err}`);
    });
```

## writeJson\(string, EventType, object, AsyncCallback<number\>\)<a name="en-us_topic_0000001150092213_section570630172512"></a>

Writes event information to the event file of the current day. This function supports JSON parameters and uses an asynchronous callback to return the result.

**Parameters**

<a name="en-us_topic_0000001150092213_table1054125415456"></a>
<table><thead align="left"><tr id="en-us_topic_0000001150092213_row354155454518"><th class="cellrowborder" valign="top" width="13.969999999999999%" id="mcps1.1.5.1.1"><p id="en-us_topic_0000001150092213_p17541135415455"><a name="en-us_topic_0000001150092213_p17541135415455"></a><a name="en-us_topic_0000001150092213_p17541135415455"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="13.389999999999999%" id="mcps1.1.5.1.2"><p id="en-us_topic_0000001150092213_p454195484516"><a name="en-us_topic_0000001150092213_p454195484516"></a><a name="en-us_topic_0000001150092213_p454195484516"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="8.23%" id="mcps1.1.5.1.3"><p id="en-us_topic_0000001150092213_p115414549454"><a name="en-us_topic_0000001150092213_p115414549454"></a><a name="en-us_topic_0000001150092213_p115414549454"></a>Mandatory</p>
</th>
<th class="cellrowborder" valign="top" width="64.41%" id="mcps1.1.5.1.4"><p id="en-us_topic_0000001150092213_p155411354104516"><a name="en-us_topic_0000001150092213_p155411354104516"></a><a name="en-us_topic_0000001150092213_p155411354104516"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="en-us_topic_0000001150092213_row6541155413451"><td class="cellrowborder" valign="top" width="13.969999999999999%" headers="mcps1.1.5.1.1 "><p id="en-us_topic_0000001150092213_p125411454184516"><a name="en-us_topic_0000001150092213_p125411454184516"></a><a name="en-us_topic_0000001150092213_p125411454184516"></a>eventName</p>
</td>
<td class="cellrowborder" valign="top" width="13.389999999999999%" headers="mcps1.1.5.1.2 "><p id="en-us_topic_0000001150092213_p5541195416452"><a name="en-us_topic_0000001150092213_p5541195416452"></a><a name="en-us_topic_0000001150092213_p5541195416452"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="8.23%" headers="mcps1.1.5.1.3 "><p id="en-us_topic_0000001150092213_p754115424514"><a name="en-us_topic_0000001150092213_p754115424514"></a><a name="en-us_topic_0000001150092213_p754115424514"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="64.41%" headers="mcps1.1.5.1.4 "><p id="en-us_topic_0000001150092213_p185421054144516"><a name="en-us_topic_0000001150092213_p185421054144516"></a><a name="en-us_topic_0000001150092213_p185421054144516"></a>Indicates the app event name.</p>
</td>
</tr>
<tr id="en-us_topic_0000001150092213_row2542145416459"><td class="cellrowborder" valign="top" width="13.969999999999999%" headers="mcps1.1.5.1.1 "><p id="en-us_topic_0000001150092213_p19542185415455"><a name="en-us_topic_0000001150092213_p19542185415455"></a><a name="en-us_topic_0000001150092213_p19542185415455"></a>eventType</p>
</td>
<td class="cellrowborder" valign="top" width="13.389999999999999%" headers="mcps1.1.5.1.2 "><p id="en-us_topic_0000001150092213_p20542205474519"><a name="en-us_topic_0000001150092213_p20542205474519"></a><a name="en-us_topic_0000001150092213_p20542205474519"></a>EventType</p>
</td>
<td class="cellrowborder" valign="top" width="8.23%" headers="mcps1.1.5.1.3 "><p id="en-us_topic_0000001150092213_p1354295494510"><a name="en-us_topic_0000001150092213_p1354295494510"></a><a name="en-us_topic_0000001150092213_p1354295494510"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="64.41%" headers="mcps1.1.5.1.4 "><p id="en-us_topic_0000001150092213_p754216544454"><a name="en-us_topic_0000001150092213_p754216544454"></a><a name="en-us_topic_0000001150092213_p754216544454"></a>Indicates the app event type.</p>
</td>
</tr>
<tr id="en-us_topic_0000001150092213_row354265418456"><td class="cellrowborder" valign="top" width="13.969999999999999%" headers="mcps1.1.5.1.1 "><p id="en-us_topic_0000001150092213_p1354215547452"><a name="en-us_topic_0000001150092213_p1354215547452"></a><a name="en-us_topic_0000001150092213_p1354215547452"></a>jsonParam</p>
</td>
<td class="cellrowborder" valign="top" width="13.389999999999999%" headers="mcps1.1.5.1.2 "><p id="en-us_topic_0000001150092213_p754225416456"><a name="en-us_topic_0000001150092213_p754225416456"></a><a name="en-us_topic_0000001150092213_p754225416456"></a>object</p>
</td>
<td class="cellrowborder" valign="top" width="8.23%" headers="mcps1.1.5.1.3 "><p id="en-us_topic_0000001150092213_p55421654124517"><a name="en-us_topic_0000001150092213_p55421654124517"></a><a name="en-us_topic_0000001150092213_p55421654124517"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="64.41%" headers="mcps1.1.5.1.4 "><p id="en-us_topic_0000001150092213_p55431154164513"><a name="en-us_topic_0000001150092213_p55431154164513"></a><a name="en-us_topic_0000001150092213_p55431154164513"></a>Indicates an array of JSON parameters of the app event. A key must be a string, and a value must be a string, number, boolean, or Array (which can only be a string, number, or boolean).</p>
</td>
</tr>
<tr id="en-us_topic_0000001150092213_row87751758579"><td class="cellrowborder" valign="top" width="13.969999999999999%" headers="mcps1.1.5.1.1 "><p id="en-us_topic_0000001150092213_p777595810712"><a name="en-us_topic_0000001150092213_p777595810712"></a><a name="en-us_topic_0000001150092213_p777595810712"></a>callback</p>
</td>
<td class="cellrowborder" valign="top" width="13.389999999999999%" headers="mcps1.1.5.1.2 "><p id="en-us_topic_0000001150092213_p1577513581719"><a name="en-us_topic_0000001150092213_p1577513581719"></a><a name="en-us_topic_0000001150092213_p1577513581719"></a>AsyncCallback&lt;number&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="8.23%" headers="mcps1.1.5.1.3 "><p id="en-us_topic_0000001150092213_p157753585718"><a name="en-us_topic_0000001150092213_p157753585718"></a><a name="en-us_topic_0000001150092213_p157753585718"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="64.41%" headers="mcps1.1.5.1.4 "><p id="en-us_topic_0000001150092213_p1065434111303"><a name="en-us_topic_0000001150092213_p1065434111303"></a><a name="en-us_topic_0000001150092213_p1065434111303"></a>Indicates the callback function, which can be used to process the received return value.</p>
<a name="en-us_topic_0000001150092213_ul182248492307"></a><a name="en-us_topic_0000001150092213_ul182248492307"></a><ul id="en-us_topic_0000001150092213_ul182248492307"><li>Value <strong id="en-us_topic_0000001150092213_b27171235133215"><a name="en-us_topic_0000001150092213_b27171235133215"></a><a name="en-us_topic_0000001150092213_b27171235133215"></a>0</strong> indicates that the event parameter verification is successful, and the event will be written to the event file asynchronously. </li><li>A value greater than 0 indicates that invalid parameters are present in the event, and the event will be written to the event file asynchronously after the invalid parameters are ignored. </li><li>A value less than 0 indicates that the event parameter verification fails, and the event will not be written to the event file asynchronously.</li></ul>
</td>
</tr>
</tbody>
</table>

**Example**

```
hiappevent.writeJson("testEvent", hiappevent.EventType.FAULT, {"intData":100, "strData":"strValue"}, (err, value) => {
    if (err) {
        // Event writing failed: The event contains invalid parameters or the event parameter verification fails.
        console.error(`failed to write event because ${err}`);
        return;
    }

    // Event writing succeeded.
    console.log(`success to write event: ${value}`);
});
```

## writeJson\(string, EventType, object\)<a name="en-us_topic_0000001150092213_section0857164934517"></a>

Writes event information to the event file of the current day. This function supports JSON parameters and uses an asynchronous promise to return the result.

**Parameters**

<a name="en-us_topic_0000001150092213_table11857249104514"></a>
<table><thead align="left"><tr id="en-us_topic_0000001150092213_row198584493457"><th class="cellrowborder" valign="top" width="13.969999999999999%" id="mcps1.1.5.1.1"><p id="en-us_topic_0000001150092213_p128580494453"><a name="en-us_topic_0000001150092213_p128580494453"></a><a name="en-us_topic_0000001150092213_p128580494453"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="13.389999999999999%" id="mcps1.1.5.1.2"><p id="en-us_topic_0000001150092213_p2085813494456"><a name="en-us_topic_0000001150092213_p2085813494456"></a><a name="en-us_topic_0000001150092213_p2085813494456"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="8.23%" id="mcps1.1.5.1.3"><p id="en-us_topic_0000001150092213_p1285894934516"><a name="en-us_topic_0000001150092213_p1285894934516"></a><a name="en-us_topic_0000001150092213_p1285894934516"></a>Mandatory</p>
</th>
<th class="cellrowborder" valign="top" width="64.41%" id="mcps1.1.5.1.4"><p id="en-us_topic_0000001150092213_p48581849104511"><a name="en-us_topic_0000001150092213_p48581849104511"></a><a name="en-us_topic_0000001150092213_p48581849104511"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="en-us_topic_0000001150092213_row98581498450"><td class="cellrowborder" valign="top" width="13.969999999999999%" headers="mcps1.1.5.1.1 "><p id="en-us_topic_0000001150092213_p1185884919459"><a name="en-us_topic_0000001150092213_p1185884919459"></a><a name="en-us_topic_0000001150092213_p1185884919459"></a>eventName</p>
</td>
<td class="cellrowborder" valign="top" width="13.389999999999999%" headers="mcps1.1.5.1.2 "><p id="en-us_topic_0000001150092213_p28586495454"><a name="en-us_topic_0000001150092213_p28586495454"></a><a name="en-us_topic_0000001150092213_p28586495454"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="8.23%" headers="mcps1.1.5.1.3 "><p id="en-us_topic_0000001150092213_p2858144912459"><a name="en-us_topic_0000001150092213_p2858144912459"></a><a name="en-us_topic_0000001150092213_p2858144912459"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="64.41%" headers="mcps1.1.5.1.4 "><p id="en-us_topic_0000001150092213_p8858164984518"><a name="en-us_topic_0000001150092213_p8858164984518"></a><a name="en-us_topic_0000001150092213_p8858164984518"></a>Indicates the app event name.</p>
</td>
</tr>
<tr id="en-us_topic_0000001150092213_row198584495457"><td class="cellrowborder" valign="top" width="13.969999999999999%" headers="mcps1.1.5.1.1 "><p id="en-us_topic_0000001150092213_p128583494450"><a name="en-us_topic_0000001150092213_p128583494450"></a><a name="en-us_topic_0000001150092213_p128583494450"></a>eventType</p>
</td>
<td class="cellrowborder" valign="top" width="13.389999999999999%" headers="mcps1.1.5.1.2 "><p id="en-us_topic_0000001150092213_p13858449194517"><a name="en-us_topic_0000001150092213_p13858449194517"></a><a name="en-us_topic_0000001150092213_p13858449194517"></a>EventType</p>
</td>
<td class="cellrowborder" valign="top" width="8.23%" headers="mcps1.1.5.1.3 "><p id="en-us_topic_0000001150092213_p1785894934513"><a name="en-us_topic_0000001150092213_p1785894934513"></a><a name="en-us_topic_0000001150092213_p1785894934513"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="64.41%" headers="mcps1.1.5.1.4 "><p id="en-us_topic_0000001150092213_p198581349194515"><a name="en-us_topic_0000001150092213_p198581349194515"></a><a name="en-us_topic_0000001150092213_p198581349194515"></a>Indicates the app event type.</p>
</td>
</tr>
<tr id="en-us_topic_0000001150092213_row78580497453"><td class="cellrowborder" valign="top" width="13.969999999999999%" headers="mcps1.1.5.1.1 "><p id="en-us_topic_0000001150092213_p2085819494459"><a name="en-us_topic_0000001150092213_p2085819494459"></a><a name="en-us_topic_0000001150092213_p2085819494459"></a>jsonParam</p>
</td>
<td class="cellrowborder" valign="top" width="13.389999999999999%" headers="mcps1.1.5.1.2 "><p id="en-us_topic_0000001150092213_p8859749154519"><a name="en-us_topic_0000001150092213_p8859749154519"></a><a name="en-us_topic_0000001150092213_p8859749154519"></a>object</p>
</td>
<td class="cellrowborder" valign="top" width="8.23%" headers="mcps1.1.5.1.3 "><p id="en-us_topic_0000001150092213_p1385984964515"><a name="en-us_topic_0000001150092213_p1385984964515"></a><a name="en-us_topic_0000001150092213_p1385984964515"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="64.41%" headers="mcps1.1.5.1.4 "><p id="en-us_topic_0000001150092213_p1859114984515"><a name="en-us_topic_0000001150092213_p1859114984515"></a><a name="en-us_topic_0000001150092213_p1859114984515"></a>Indicates an array of JSON parameters of the app event. A key must be a string, and a value must be a string, number, boolean, or Array (which can only be a string, number, or boolean).</p>
</td>
</tr>
</tbody>
</table>

**Return Values**

<a name="en-us_topic_0000001150092213_table10811610134713"></a>
<table><thead align="left"><tr id="en-us_topic_0000001150092213_row7811410124716"><th class="cellrowborder" valign="top" width="26.06%" id="mcps1.1.3.1.1"><p id="en-us_topic_0000001150092213_p118116107479"><a name="en-us_topic_0000001150092213_p118116107479"></a><a name="en-us_topic_0000001150092213_p118116107479"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="73.94%" id="mcps1.1.3.1.2"><p id="en-us_topic_0000001150092213_p8811910124715"><a name="en-us_topic_0000001150092213_p8811910124715"></a><a name="en-us_topic_0000001150092213_p8811910124715"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="en-us_topic_0000001150092213_row1181161019479"><td class="cellrowborder" valign="top" width="26.06%" headers="mcps1.1.3.1.1 "><p id="en-us_topic_0000001150092213_p15811181004712"><a name="en-us_topic_0000001150092213_p15811181004712"></a><a name="en-us_topic_0000001150092213_p15811181004712"></a>Promise&lt;void&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="73.94%" headers="mcps1.1.3.1.2 "><p id="en-us_topic_0000001150092213_p14811710164718"><a name="en-us_topic_0000001150092213_p14811710164718"></a><a name="en-us_topic_0000001150092213_p14811710164718"></a>Indicates the promise used to return the execution result.</p>
</td>
</tr>
</tbody>
</table>

**Example**

```
hiappevent.writeJson("testEvent", hiappevent.EventType.FAULT, {"intData":100, "strData":"strValue"})
    .then((value) => {
        // Event writing succeeded.
        console.log(`success to write event: ${value}`);
    }).catch((err) => {
        // Event writing failed: The event contains invalid parameters or the event parameter verification fails.
        console.error(`failed to write event because ${err}`);
    });
```

## Enums<a name="en-us_topic_0000001150092213_section1978842154715"></a>

## EventType<a name="en-us_topic_0000001150092213_section099619567453"></a>

Enumerates event types.

<a name="en-us_topic_0000001150092213_table20633101642315"></a>
<table><thead align="left"><tr id="en-us_topic_0000001150092213_row663331618238"><th class="cellrowborder" valign="top" width="27.900000000000002%" id="mcps1.1.4.1.1"><p id="en-us_topic_0000001150092213_a3d0fc780cc904c1cbab7991251622f65"><a name="en-us_topic_0000001150092213_a3d0fc780cc904c1cbab7991251622f65"></a><a name="en-us_topic_0000001150092213_a3d0fc780cc904c1cbab7991251622f65"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="12.43%" id="mcps1.1.4.1.2"><p id="en-us_topic_0000001150092213_aace9cae4ba0d4939bfa048460f61c3c7"><a name="en-us_topic_0000001150092213_aace9cae4ba0d4939bfa048460f61c3c7"></a><a name="en-us_topic_0000001150092213_aace9cae4ba0d4939bfa048460f61c3c7"></a>Default Value</p>
</th>
<th class="cellrowborder" valign="top" width="59.67%" id="mcps1.1.4.1.3"><p id="en-us_topic_0000001150092213_afec895de33f94e3c87ee7acc20190a17"><a name="en-us_topic_0000001150092213_afec895de33f94e3c87ee7acc20190a17"></a><a name="en-us_topic_0000001150092213_afec895de33f94e3c87ee7acc20190a17"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="en-us_topic_0000001150092213_row188481425182510"><td class="cellrowborder" valign="top" width="27.900000000000002%" headers="mcps1.1.4.1.1 "><p id="en-us_topic_0000001150092213_p13876443113318"><a name="en-us_topic_0000001150092213_p13876443113318"></a><a name="en-us_topic_0000001150092213_p13876443113318"></a>FAULT</p>
</td>
<td class="cellrowborder" valign="top" width="12.43%" headers="mcps1.1.4.1.2 "><p id="en-us_topic_0000001150092213_p2282152962115"><a name="en-us_topic_0000001150092213_p2282152962115"></a><a name="en-us_topic_0000001150092213_p2282152962115"></a>1</p>
</td>
<td class="cellrowborder" valign="top" width="59.67%" headers="mcps1.1.4.1.3 "><p id="en-us_topic_0000001150092213_p28751543103312"><a name="en-us_topic_0000001150092213_p28751543103312"></a><a name="en-us_topic_0000001150092213_p28751543103312"></a>Fault event</p>
</td>
</tr>
<tr id="en-us_topic_0000001150092213_row0461622112513"><td class="cellrowborder" valign="top" width="27.900000000000002%" headers="mcps1.1.4.1.1 "><p id="en-us_topic_0000001150092213_p68697436338"><a name="en-us_topic_0000001150092213_p68697436338"></a><a name="en-us_topic_0000001150092213_p68697436338"></a>STATISTIC</p>
</td>
<td class="cellrowborder" valign="top" width="12.43%" headers="mcps1.1.4.1.2 "><p id="en-us_topic_0000001150092213_p1310553911218"><a name="en-us_topic_0000001150092213_p1310553911218"></a><a name="en-us_topic_0000001150092213_p1310553911218"></a>2</p>
</td>
<td class="cellrowborder" valign="top" width="59.67%" headers="mcps1.1.4.1.3 "><p id="en-us_topic_0000001150092213_p14868114312331"><a name="en-us_topic_0000001150092213_p14868114312331"></a><a name="en-us_topic_0000001150092213_p14868114312331"></a>Statistical event</p>
</td>
</tr>
<tr id="en-us_topic_0000001150092213_row91702048195619"><td class="cellrowborder" valign="top" width="27.900000000000002%" headers="mcps1.1.4.1.1 "><p id="en-us_topic_0000001150092213_p123991673342"><a name="en-us_topic_0000001150092213_p123991673342"></a><a name="en-us_topic_0000001150092213_p123991673342"></a>SECURITY</p>
</td>
<td class="cellrowborder" valign="top" width="12.43%" headers="mcps1.1.4.1.2 "><p id="en-us_topic_0000001150092213_p14170114811561"><a name="en-us_topic_0000001150092213_p14170114811561"></a><a name="en-us_topic_0000001150092213_p14170114811561"></a>3</p>
</td>
<td class="cellrowborder" valign="top" width="59.67%" headers="mcps1.1.4.1.3 "><p id="en-us_topic_0000001150092213_p1539912793411"><a name="en-us_topic_0000001150092213_p1539912793411"></a><a name="en-us_topic_0000001150092213_p1539912793411"></a>Security event</p>
</td>
</tr>
<tr id="en-us_topic_0000001150092213_row717094895612"><td class="cellrowborder" valign="top" width="27.900000000000002%" headers="mcps1.1.4.1.1 "><p id="en-us_topic_0000001150092213_p10231410193416"><a name="en-us_topic_0000001150092213_p10231410193416"></a><a name="en-us_topic_0000001150092213_p10231410193416"></a>BEHAVIOR</p>
</td>
<td class="cellrowborder" valign="top" width="12.43%" headers="mcps1.1.4.1.2 "><p id="en-us_topic_0000001150092213_p1817134815569"><a name="en-us_topic_0000001150092213_p1817134815569"></a><a name="en-us_topic_0000001150092213_p1817134815569"></a>4</p>
</td>
<td class="cellrowborder" valign="top" width="59.67%" headers="mcps1.1.4.1.3 "><p id="en-us_topic_0000001150092213_p523171020343"><a name="en-us_topic_0000001150092213_p523171020343"></a><a name="en-us_topic_0000001150092213_p523171020343"></a>System behavior event</p>
</td>
</tr>
</tbody>
</table>

