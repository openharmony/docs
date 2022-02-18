# HiAppEvent<a name="EN-US_TOPIC_0000001163817362"></a>

>![](../../public_sys-resources/icon-note.gif) **NOTE:** 
>The initial APIs of this module are supported since API version 7. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import<a name="s56d19203690d4782bfc74069abb6bd71"></a>

```
import hiAppEvent from '@ohos.hiAppEvent';
```

## System Capabilities

SystemCapability.HiviewDFX.HiAppEvent

## hiAppEvent.write<a name="section570630172512"></a>

write\(eventName: string, eventType: EventType, keyValues: object, callback: AsyncCallback<void\>\): void

Writes event information to the event file of the current day. This function supports JSON parameters and uses an asynchronous callback to return the result.

-   Parameters

    <a name="table1054125415456"></a>
    <table><thead align="left"><tr id="row354155454518"><th class="cellrowborder" valign="top" width="15.030000000000001%" id="mcps1.1.5.1.1"><p id="p17541135415455"><a name="p17541135415455"></a><a name="p17541135415455"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="24.430000000000003%" id="mcps1.1.5.1.2"><p id="p454195484516"><a name="p454195484516"></a><a name="p454195484516"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="7.870000000000002%" id="mcps1.1.5.1.3"><p id="p115414549454"><a name="p115414549454"></a><a name="p115414549454"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="52.67000000000001%" id="mcps1.1.5.1.4"><p id="p155411354104516"><a name="p155411354104516"></a><a name="p155411354104516"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row6541155413451"><td class="cellrowborder" valign="top" width="15.030000000000001%" headers="mcps1.1.5.1.1 "><p id="p125411454184516"><a name="p125411454184516"></a><a name="p125411454184516"></a>eventName</p>
    </td>
    <td class="cellrowborder" valign="top" width="24.430000000000003%" headers="mcps1.1.5.1.2 "><p id="p5541195416452"><a name="p5541195416452"></a><a name="p5541195416452"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="7.870000000000002%" headers="mcps1.1.5.1.3 "><p id="p754115424514"><a name="p754115424514"></a><a name="p754115424514"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="52.67000000000001%" headers="mcps1.1.5.1.4 "><p id="p185421054144516"><a name="p185421054144516"></a><a name="p185421054144516"></a>Indicates the application event name.</p>
    </td>
    </tr>
    <tr id="row2542145416459"><td class="cellrowborder" valign="top" width="15.030000000000001%" headers="mcps1.1.5.1.1 "><p id="p19542185415455"><a name="p19542185415455"></a><a name="p19542185415455"></a>eventType</p>
    </td>
    <td class="cellrowborder" valign="top" width="24.430000000000003%" headers="mcps1.1.5.1.2 "><p id="p20542205474519"><a name="p20542205474519"></a><a name="p20542205474519"></a><a href="#section099619567453">EventType</a></p>
    </td>
    <td class="cellrowborder" valign="top" width="7.870000000000002%" headers="mcps1.1.5.1.3 "><p id="p1354295494510"><a name="p1354295494510"></a><a name="p1354295494510"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="52.67000000000001%" headers="mcps1.1.5.1.4 "><p id="p754216544454"><a name="p754216544454"></a><a name="p754216544454"></a>Indicates the application event type.</p>
    </td>
    </tr>
    <tr id="row354265418456"><td class="cellrowborder" valign="top" width="15.030000000000001%" headers="mcps1.1.5.1.1 "><p id="p1354215547452"><a name="p1354215547452"></a><a name="p1354215547452"></a>keyValues</p>
    </td>
    <td class="cellrowborder" valign="top" width="24.430000000000003%" headers="mcps1.1.5.1.2 "><p id="p754225416456"><a name="p754225416456"></a><a name="p754225416456"></a>object</p>
    </td>
    <td class="cellrowborder" valign="top" width="7.870000000000002%" headers="mcps1.1.5.1.3 "><p id="p55421654124517"><a name="p55421654124517"></a><a name="p55421654124517"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="52.67000000000001%" headers="mcps1.1.5.1.4 "><p id="p55431154164513"><a name="p55431154164513"></a><a name="p55431154164513"></a>Indicates an array of JSON parameters of the application event. A key must be a string, and a value must be a string, number, boolean, or Array (which can only be a string, number, or boolean).</p>
    </td>
    </tr>
    <tr id="row87751758579"><td class="cellrowborder" valign="top" width="15.030000000000001%" headers="mcps1.1.5.1.1 "><p id="p777595810712"><a name="p777595810712"></a><a name="p777595810712"></a>callback</p>
    </td>
    <td class="cellrowborder" valign="top" width="24.430000000000003%" headers="mcps1.1.5.1.2 "><p id="p1577513581719"><a name="p1577513581719"></a><a name="p1577513581719"></a>AsyncCallback&lt;void&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="7.870000000000002%" headers="mcps1.1.5.1.3 "><p id="p157753585718"><a name="p157753585718"></a><a name="p157753585718"></a>No</p>
    </td>
    <td class="cellrowborder" valign="top" width="52.67000000000001%" headers="mcps1.1.5.1.4 "><p id="p1065434111303"><a name="p1065434111303"></a><a name="p1065434111303"></a>Indicates the callback function, which can be used to process the received return value.</p>
    <a name="ul182248492307"></a><a name="ul182248492307"></a><ul id="ul182248492307"><li>Value <strong id="b27171235133215"><a name="b27171235133215"></a><a name="b27171235133215"></a>0</strong> indicates that the event verification is successful, and the event will be written to the event file asynchronously. </li><li>A value greater than <strong id="b89271810175013"><a name="b89271810175013"></a><a name="b89271810175013"></a>0</strong> indicates that invalid parameters are present in the event, and the event will be written to the event file asynchronously after the invalid parameters are ignored. </li><li>A value smaller than <strong id="b8363151395017"><a name="b8363151395017"></a><a name="b8363151395017"></a>0</strong> indicates that the event verification fails, and the event will not be written to the event file.</li></ul>
    </td>
    </tr>
    </tbody>
    </table>

-   Example

    ```
    hiAppEvent.write("test_event", hiAppEvent.EventType.FAULT, {"int_data":100, "str_data":"strValue"}, (err, value) => {
        if (err) {
            // Event writing exception: Write the event to the event file after the invalid parameters in the event are ignored, or stop writing the event if the event verification fails.
            console.error(`failed to write event because ${err.code}`);
            return;
        }
    
        // Event writing succeeded.
        console.log(`success to write event: ${value}`);
    });
    ```


## hiAppEvent.write<a name="section0857164934517"></a>

write\(eventName: string, eventType: EventType, keyValues: object\): Promise<void\>

Writes event information to the event file of the current day. This function supports JSON parameters and uses a promise to return the result.

-   Parameters

    <a name="table11857249104514"></a>
    <table><thead align="left"><tr id="row198584493457"><th class="cellrowborder" valign="top" width="13.969999999999999%" id="mcps1.1.5.1.1"><p id="p128580494453"><a name="p128580494453"></a><a name="p128580494453"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="13.389999999999999%" id="mcps1.1.5.1.2"><p id="p2085813494456"><a name="p2085813494456"></a><a name="p2085813494456"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="8.23%" id="mcps1.1.5.1.3"><p id="p1285894934516"><a name="p1285894934516"></a><a name="p1285894934516"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="64.41%" id="mcps1.1.5.1.4"><p id="p48581849104511"><a name="p48581849104511"></a><a name="p48581849104511"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row98581498450"><td class="cellrowborder" valign="top" width="13.969999999999999%" headers="mcps1.1.5.1.1 "><p id="p1185884919459"><a name="p1185884919459"></a><a name="p1185884919459"></a>eventName</p>
    </td>
    <td class="cellrowborder" valign="top" width="13.389999999999999%" headers="mcps1.1.5.1.2 "><p id="p28586495454"><a name="p28586495454"></a><a name="p28586495454"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="8.23%" headers="mcps1.1.5.1.3 "><p id="p2858144912459"><a name="p2858144912459"></a><a name="p2858144912459"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="64.41%" headers="mcps1.1.5.1.4 "><p id="p8858164984518"><a name="p8858164984518"></a><a name="p8858164984518"></a>Indicates the application event name.</p>
    </td>
    </tr>
    <tr id="row198584495457"><td class="cellrowborder" valign="top" width="13.969999999999999%" headers="mcps1.1.5.1.1 "><p id="p128583494450"><a name="p128583494450"></a><a name="p128583494450"></a>eventType</p>
    </td>
    <td class="cellrowborder" valign="top" width="13.389999999999999%" headers="mcps1.1.5.1.2 "><p id="p13858449194517"><a name="p13858449194517"></a><a name="p13858449194517"></a><a href="#section099619567453">EventType</a></p>
    </td>
    <td class="cellrowborder" valign="top" width="8.23%" headers="mcps1.1.5.1.3 "><p id="p1785894934513"><a name="p1785894934513"></a><a name="p1785894934513"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="64.41%" headers="mcps1.1.5.1.4 "><p id="p198581349194515"><a name="p198581349194515"></a><a name="p198581349194515"></a>Indicates the application event type.</p>
    </td>
    </tr>
    <tr id="row78580497453"><td class="cellrowborder" valign="top" width="13.969999999999999%" headers="mcps1.1.5.1.1 "><p id="p2085819494459"><a name="p2085819494459"></a><a name="p2085819494459"></a>keyValues</p>
    </td>
    <td class="cellrowborder" valign="top" width="13.389999999999999%" headers="mcps1.1.5.1.2 "><p id="p8859749154519"><a name="p8859749154519"></a><a name="p8859749154519"></a>object</p>
    </td>
    <td class="cellrowborder" valign="top" width="8.23%" headers="mcps1.1.5.1.3 "><p id="p1385984964515"><a name="p1385984964515"></a><a name="p1385984964515"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="64.41%" headers="mcps1.1.5.1.4 "><p id="p1859114984515"><a name="p1859114984515"></a><a name="p1859114984515"></a>Indicates an array of JSON parameters of the application event. A key must be a string, and a value must be a string, number, boolean, or Array (which can only be a string, number, or boolean).</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Return values

    <a name="table10811610134713"></a>
    <table><thead align="left"><tr id="row7811410124716"><th class="cellrowborder" valign="top" width="26.06%" id="mcps1.1.3.1.1"><p id="p118116107479"><a name="p118116107479"></a><a name="p118116107479"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="73.94%" id="mcps1.1.3.1.2"><p id="p8811910124715"><a name="p8811910124715"></a><a name="p8811910124715"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row1181161019479"><td class="cellrowborder" valign="top" width="26.06%" headers="mcps1.1.3.1.1 "><p id="p15811181004712"><a name="p15811181004712"></a><a name="p15811181004712"></a>Promise&lt;void&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="73.94%" headers="mcps1.1.3.1.2 "><p id="p14811710164718"><a name="p14811710164718"></a><a name="p14811710164718"></a>Promise used to process the callback in the <strong id="b1588612407278"><a name="b1588612407278"></a><a name="b1588612407278"></a>then()</strong> and <strong id="b116252458275"><a name="b116252458275"></a><a name="b116252458275"></a>catch()</strong> methods when event writing succeeded or failed.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Example

    ```
    hiAppEvent.write("test_event", hiAppEvent.EventType.FAULT, {"int_data":100, "str_data":"strValue"})
        .then((value) => {
            // Event writing succeeded.
            console.log(`success to write event: ${value}`);
        }).catch((err) => {
            // Event writing exception: Write the event to the event file after the invalid parameters in the event are ignored, or stop writing the event if the event verification fails.
            console.error(`failed to write event because ${err.code}`);
        });
    ```


## hiAppEvent.configure<a name="section5378143772018"></a>

configure\(config: ConfigOption\): boolean

Configures the application event logging function, such as setting the event logging switch and maximum size of the directory that stores the event logging files.

-   Parameters

    <a name="table1252915782516"></a>
    <table><thead align="left"><tr id="row35293782515"><th class="cellrowborder" valign="top" width="11.51%" id="mcps1.1.5.1.1"><p id="p35291371251"><a name="p35291371251"></a><a name="p35291371251"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="16.39%" id="mcps1.1.5.1.2"><p id="p75296712250"><a name="p75296712250"></a><a name="p75296712250"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="7.9%" id="mcps1.1.5.1.3"><p id="p105291377254"><a name="p105291377254"></a><a name="p105291377254"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="64.2%" id="mcps1.1.5.1.4"><p id="p155291674252"><a name="p155291674252"></a><a name="p155291674252"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row652919711259"><td class="cellrowborder" valign="top" width="11.51%" headers="mcps1.1.5.1.1 "><p id="p18529970251"><a name="p18529970251"></a><a name="p18529970251"></a>config</p>
    </td>
    <td class="cellrowborder" valign="top" width="16.39%" headers="mcps1.1.5.1.2 "><p id="p65296742520"><a name="p65296742520"></a><a name="p65296742520"></a><a href="#section1877154515916">ConfigOption</a></p>
    </td>
    <td class="cellrowborder" valign="top" width="7.9%" headers="mcps1.1.5.1.3 "><p id="p155299792512"><a name="p155299792512"></a><a name="p155299792512"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="64.2%" headers="mcps1.1.5.1.4 "><p id="p38353293497"><a name="p38353293497"></a><a name="p38353293497"></a>Configuration items for application event logging.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Return values

    <a name="table253014717256"></a>
    <table><thead align="left"><tr id="row3530471251"><th class="cellrowborder" valign="top" width="26.06%" id="mcps1.1.3.1.1"><p id="p195304762520"><a name="p195304762520"></a><a name="p195304762520"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="73.94%" id="mcps1.1.3.1.2"><p id="p1353017722518"><a name="p1353017722518"></a><a name="p1353017722518"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row2053010792510"><td class="cellrowborder" valign="top" width="26.06%" headers="mcps1.1.3.1.1 "><p id="p155308717259"><a name="p155308717259"></a><a name="p155308717259"></a>boolean</p>
    </td>
    <td class="cellrowborder" valign="top" width="73.94%" headers="mcps1.1.3.1.2 "><p id="p1953016720258"><a name="p1953016720258"></a><a name="p1953016720258"></a>Returns <strong id="b188031557115015"><a name="b188031557115015"></a><a name="b188031557115015"></a>true</strong> if the configuration is successful; returns <strong id="b1612180105111"><a name="b1612180105111"></a><a name="b1612180105111"></a>false</strong> otherwise.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Example

    ```
    // Configure the application event logging switch.
    hiAppEvent.configure({
        disable: true
    });
    
    // Configure the maximum size of the directory that stores the event logging files.
    hiAppEvent.configure({
        maxStorage: '100M'
    });
    ```


## ConfigOption<a name="section1877154515916"></a>

Provides the configuration items for application event logging.

<a name="t1e7d4d4f9078490d8dcdbb56465b8ab3"></a>
<table><thead align="left"><tr id="r85a1aa805727476a8e768b658530fc49"><th class="cellrowborder" valign="top" width="13.08%" id="mcps1.1.5.1.1"><p id="a58cac6e212134a42a245df58d7b6f3a3"><a name="a58cac6e212134a42a245df58d7b6f3a3"></a><a name="a58cac6e212134a42a245df58d7b6f3a3"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="10.5%" id="mcps1.1.5.1.2"><p id="ae520989fe4be4482acdfdf2c26d6517d"><a name="ae520989fe4be4482acdfdf2c26d6517d"></a><a name="ae520989fe4be4482acdfdf2c26d6517d"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="10.63%" id="mcps1.1.5.1.3"><p id="a6b396dd84a564272a6f3d4732b4e12fe"><a name="a6b396dd84a564272a6f3d4732b4e12fe"></a><a name="a6b396dd84a564272a6f3d4732b4e12fe"></a>Mandatory</p>
</th>
<th class="cellrowborder" valign="top" width="65.79%" id="mcps1.1.5.1.4"><p id="ae728420f819e42d1b31424ac9747665b"><a name="ae728420f819e42d1b31424ac9747665b"></a><a name="ae728420f819e42d1b31424ac9747665b"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="r3e8e2a236aee4030b7f7878cf5bc7537"><td class="cellrowborder" valign="top" width="13.08%" headers="mcps1.1.5.1.1 "><p id="ada6eeced8a7c481dac17cdb7d5c37dce"><a name="ada6eeced8a7c481dac17cdb7d5c37dce"></a><a name="ada6eeced8a7c481dac17cdb7d5c37dce"></a>disable</p>
</td>
<td class="cellrowborder" valign="top" width="10.5%" headers="mcps1.1.5.1.2 "><p id="a89ee25b3dc1045b5aa724c83751b3c0f"><a name="a89ee25b3dc1045b5aa724c83751b3c0f"></a><a name="a89ee25b3dc1045b5aa724c83751b3c0f"></a>boolean</p>
</td>
<td class="cellrowborder" valign="top" width="10.63%" headers="mcps1.1.5.1.3 "><p id="p936187569"><a name="p936187569"></a><a name="p936187569"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="65.79%" headers="mcps1.1.5.1.4 "><p id="a42ab0decfa2a497782c54a4edfc72b8a"><a name="a42ab0decfa2a497782c54a4edfc72b8a"></a><a name="a42ab0decfa2a497782c54a4edfc72b8a"></a>Application event logging switch. The value <strong id="b13365319489"><a name="b13365319489"></a><a name="b13365319489"></a>true</strong> means to disable the application event logging function, and the value <strong id="b4491356184818"><a name="b4491356184818"></a><a name="b4491356184818"></a>false</strong> means the opposite.</p>
</td>
</tr>
<tr id="row860615273611"><td class="cellrowborder" valign="top" width="13.08%" headers="mcps1.1.5.1.1 "><p id="p116072272610"><a name="p116072272610"></a><a name="p116072272610"></a>maxStorage</p>
</td>
<td class="cellrowborder" valign="top" width="10.5%" headers="mcps1.1.5.1.2 "><p id="p9607727863"><a name="p9607727863"></a><a name="p9607727863"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="10.63%" headers="mcps1.1.5.1.3 "><p id="p66070271869"><a name="p66070271869"></a><a name="p66070271869"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="65.79%" headers="mcps1.1.5.1.4 "><p id="p96071927366"><a name="p96071927366"></a><a name="p96071927366"></a>Maximum size of the event file storage directory. The default value is <strong id="b1263295715012"><a name="b1263295715012"></a><a name="b1263295715012"></a>10M</strong>. If the specified size is exceeded, the oldest event logging files in the storage directory will be deleted to free up space.</p>
</td>
</tr>
</tbody>
</table>

## EventType<a name="section099619567453"></a>

Enumerates event types.

<a name="table20633101642315"></a>
<table><thead align="left"><tr id="row663331618238"><th class="cellrowborder" valign="top" width="27.900000000000002%" id="mcps1.1.4.1.1"><p id="a3d0fc780cc904c1cbab7991251622f65"><a name="a3d0fc780cc904c1cbab7991251622f65"></a><a name="a3d0fc780cc904c1cbab7991251622f65"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="12.43%" id="mcps1.1.4.1.2"><p id="aace9cae4ba0d4939bfa048460f61c3c7"><a name="aace9cae4ba0d4939bfa048460f61c3c7"></a><a name="aace9cae4ba0d4939bfa048460f61c3c7"></a>Default Value</p>
</th>
<th class="cellrowborder" valign="top" width="59.67%" id="mcps1.1.4.1.3"><p id="afec895de33f94e3c87ee7acc20190a17"><a name="afec895de33f94e3c87ee7acc20190a17"></a><a name="afec895de33f94e3c87ee7acc20190a17"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row188481425182510"><td class="cellrowborder" valign="top" width="27.900000000000002%" headers="mcps1.1.4.1.1 "><p id="p13876443113318"><a name="p13876443113318"></a><a name="p13876443113318"></a>FAULT</p>
</td>
<td class="cellrowborder" valign="top" width="12.43%" headers="mcps1.1.4.1.2 "><p id="p2282152962115"><a name="p2282152962115"></a><a name="p2282152962115"></a>1</p>
</td>
<td class="cellrowborder" valign="top" width="59.67%" headers="mcps1.1.4.1.3 "><p id="p28751543103312"><a name="p28751543103312"></a><a name="p28751543103312"></a>Fault event</p>
</td>
</tr>
<tr id="row0461622112513"><td class="cellrowborder" valign="top" width="27.900000000000002%" headers="mcps1.1.4.1.1 "><p id="p68697436338"><a name="p68697436338"></a><a name="p68697436338"></a>STATISTIC</p>
</td>
<td class="cellrowborder" valign="top" width="12.43%" headers="mcps1.1.4.1.2 "><p id="p1310553911218"><a name="p1310553911218"></a><a name="p1310553911218"></a>2</p>
</td>
<td class="cellrowborder" valign="top" width="59.67%" headers="mcps1.1.4.1.3 "><p id="p14868114312331"><a name="p14868114312331"></a><a name="p14868114312331"></a>Statistical event</p>
</td>
</tr>
<tr id="row91702048195619"><td class="cellrowborder" valign="top" width="27.900000000000002%" headers="mcps1.1.4.1.1 "><p id="p123991673342"><a name="p123991673342"></a><a name="p123991673342"></a>SECURITY</p>
</td>
<td class="cellrowborder" valign="top" width="12.43%" headers="mcps1.1.4.1.2 "><p id="p14170114811561"><a name="p14170114811561"></a><a name="p14170114811561"></a>3</p>
</td>
<td class="cellrowborder" valign="top" width="59.67%" headers="mcps1.1.4.1.3 "><p id="p1539912793411"><a name="p1539912793411"></a><a name="p1539912793411"></a>Security event</p>
</td>
</tr>
<tr id="row717094895612"><td class="cellrowborder" valign="top" width="27.900000000000002%" headers="mcps1.1.4.1.1 "><p id="p10231410193416"><a name="p10231410193416"></a><a name="p10231410193416"></a>BEHAVIOR</p>
</td>
<td class="cellrowborder" valign="top" width="12.43%" headers="mcps1.1.4.1.2 "><p id="p1817134815569"><a name="p1817134815569"></a><a name="p1817134815569"></a>4</p>
</td>
<td class="cellrowborder" valign="top" width="59.67%" headers="mcps1.1.4.1.3 "><p id="p523171020343"><a name="p523171020343"></a><a name="p523171020343"></a>Behavior event</p>
</td>
</tr>
</tbody>
</table>

## Event<a name="section107763162597"></a>

Provides constants that define the names of all predefined events.

<a name="table728861911417"></a>
<table><thead align="left"><tr id="row62887198149"><th class="cellrowborder" valign="top" width="33.550000000000004%" id="mcps1.1.6.1.1"><p id="p928811911410"><a name="p928811911410"></a><a name="p928811911410"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="12.6%" id="mcps1.1.6.1.2"><p id="p8288191916149"><a name="p8288191916149"></a><a name="p8288191916149"></a>Parameter Type</p>
</th>
<th class="cellrowborder" valign="top" width="7.6899999999999995%" id="mcps1.1.6.1.3"><p id="p14288131911418"><a name="p14288131911418"></a><a name="p14288131911418"></a>Readable</p>
</th>
<th class="cellrowborder" valign="top" width="8.43%" id="mcps1.1.6.1.4"><p id="p1928861921411"><a name="p1928861921411"></a><a name="p1928861921411"></a>Writable</p>
</th>
<th class="cellrowborder" valign="top" width="37.730000000000004%" id="mcps1.1.6.1.5"><p id="p728815191149"><a name="p728815191149"></a><a name="p728815191149"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row528891919142"><td class="cellrowborder" valign="top" width="33.550000000000004%" headers="mcps1.1.6.1.1 "><p id="p3288191991414"><a name="p3288191991414"></a><a name="p3288191991414"></a>USER_LOGIN</p>
</td>
<td class="cellrowborder" valign="top" width="12.6%" headers="mcps1.1.6.1.2 "><p id="p3288121901418"><a name="p3288121901418"></a><a name="p3288121901418"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="7.6899999999999995%" headers="mcps1.1.6.1.3 "><p id="p182881319191414"><a name="p182881319191414"></a><a name="p182881319191414"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="8.43%" headers="mcps1.1.6.1.4 "><p id="p1928801914148"><a name="p1928801914148"></a><a name="p1928801914148"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="37.730000000000004%" headers="mcps1.1.6.1.5 "><p id="p1428811192144"><a name="p1428811192144"></a><a name="p1428811192144"></a>User login event.</p>
</td>
</tr>
<tr id="row72571514202916"><td class="cellrowborder" valign="top" width="33.550000000000004%" headers="mcps1.1.6.1.1 "><p id="p18257151413298"><a name="p18257151413298"></a><a name="p18257151413298"></a>USER_LOGOUT</p>
</td>
<td class="cellrowborder" valign="top" width="12.6%" headers="mcps1.1.6.1.2 "><p id="p3976112512293"><a name="p3976112512293"></a><a name="p3976112512293"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="7.6899999999999995%" headers="mcps1.1.6.1.3 "><p id="p1497682515293"><a name="p1497682515293"></a><a name="p1497682515293"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="8.43%" headers="mcps1.1.6.1.4 "><p id="p1697613259298"><a name="p1697613259298"></a><a name="p1697613259298"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="37.730000000000004%" headers="mcps1.1.6.1.5 "><p id="p162571914162912"><a name="p162571914162912"></a><a name="p162571914162912"></a>User logout event.</p>
</td>
</tr>
<tr id="row37723173299"><td class="cellrowborder" valign="top" width="33.550000000000004%" headers="mcps1.1.6.1.1 "><p id="p07721917182914"><a name="p07721917182914"></a><a name="p07721917182914"></a>DISTRIBUTED_SERVICE_START</p>
</td>
<td class="cellrowborder" valign="top" width="12.6%" headers="mcps1.1.6.1.2 "><p id="p8324132810299"><a name="p8324132810299"></a><a name="p8324132810299"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="7.6899999999999995%" headers="mcps1.1.6.1.3 "><p id="p20324928192912"><a name="p20324928192912"></a><a name="p20324928192912"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="8.43%" headers="mcps1.1.6.1.4 "><p id="p1432413281294"><a name="p1432413281294"></a><a name="p1432413281294"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="37.730000000000004%" headers="mcps1.1.6.1.5 "><p id="p19772191715296"><a name="p19772191715296"></a><a name="p19772191715296"></a>Distributed service startup event.</p>
</td>
</tr>
</tbody>
</table>

## Param<a name="section382852073116"></a>

Provides constants that define the names of all predefined event parameters.

<table><thead align="left"><tr id="row12828192018319"><th class="cellrowborder" valign="top" width="35.24%" id="mcps1.1.6.1.1"><p id="p1082932073115"><a name="p1082932073115"></a><a name="p1082932073115"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="12.45%" id="mcps1.1.6.1.2"><p id="p14829920163113"><a name="p14829920163113"></a><a name="p14829920163113"></a>Parameter Type</p>
</th>
<th class="cellrowborder" valign="top" width="7.82%" id="mcps1.1.6.1.3"><p id="p15829620133110"><a name="p15829620133110"></a><a name="p15829620133110"></a>Readable</p>
</th>
<th class="cellrowborder" valign="top" width="8.540000000000001%" id="mcps1.1.6.1.4"><p id="p3829192013312"><a name="p3829192013312"></a><a name="p3829192013312"></a>Writable</p>
</th>
<th class="cellrowborder" valign="top" width="35.949999999999996%" id="mcps1.1.6.1.5"><p id="p6829132018315"><a name="p6829132018315"></a><a name="p6829132018315"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row48291920183117"><td class="cellrowborder" valign="top" width="35.24%" headers="mcps1.1.6.1.1 "><p id="p9829162043119"><a name="p9829162043119"></a><a name="p9829162043119"></a>USER_ID</p>
</td>
<td class="cellrowborder" valign="top" width="12.45%" headers="mcps1.1.6.1.2 "><p id="p1182912013120"><a name="p1182912013120"></a><a name="p1182912013120"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="7.82%" headers="mcps1.1.6.1.3 "><p id="p188294201316"><a name="p188294201316"></a><a name="p188294201316"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="8.540000000000001%" headers="mcps1.1.6.1.4 "><p id="p88297205315"><a name="p88297205315"></a><a name="p88297205315"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="35.949999999999996%" headers="mcps1.1.6.1.5 "><p id="p4829620183115"><a name="p4829620183115"></a><a name="p4829620183115"></a>Custom user ID.</p>
</td>
</tr>
<tr id="row482992011315"><td class="cellrowborder" valign="top" width="35.24%" headers="mcps1.1.6.1.1 "><p id="p12829120163115"><a name="p12829120163115"></a><a name="p12829120163115"></a>DISTRIBUTED_SERVICE_NAME</p>
</td>
<td class="cellrowborder" valign="top" width="12.45%" headers="mcps1.1.6.1.2 "><p id="p78291420183111"><a name="p78291420183111"></a><a name="p78291420183111"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="7.82%" headers="mcps1.1.6.1.3 "><p id="p15829720143116"><a name="p15829720143116"></a><a name="p15829720143116"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="8.540000000000001%" headers="mcps1.1.6.1.4 "><p id="p18291920133110"><a name="p18291920133110"></a><a name="p18291920133110"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="35.949999999999996%" headers="mcps1.1.6.1.5 "><p id="p882916205315"><a name="p882916205315"></a><a name="p882916205315"></a>Distributed service name.</p>
</td>
</tr>
<tr id="row9829112019318"><td class="cellrowborder" valign="top" width="35.24%" headers="mcps1.1.6.1.1 "><p id="p8829220163110"><a name="p8829220163110"></a><a name="p8829220163110"></a>DISTRIBUTED_SERVICE_INSTANCE_ID</p>
</td>
<td class="cellrowborder" valign="top" width="12.45%" headers="mcps1.1.6.1.2 "><p id="p98299202316"><a name="p98299202316"></a><a name="p98299202316"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="7.82%" headers="mcps1.1.6.1.3 "><p id="p2829142017310"><a name="p2829142017310"></a><a name="p2829142017310"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="8.540000000000001%" headers="mcps1.1.6.1.4 "><p id="p2829152073111"><a name="p2829152073111"></a><a name="p2829152073111"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="35.949999999999996%" headers="mcps1.1.6.1.5 "><p id="p15829132023112"><a name="p15829132023112"></a><a name="p15829132023112"></a>Distributed service instance ID.</p>
</td>
</tr>
</tbody>
</table>

