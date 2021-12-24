# Device Management<a name="EN-US_TOPIC_0000001188452063"></a>

>![](../../public_sys-resources/icon-note.gif) **NOTE:** 
>The initial APIs of this module are supported since API version 7. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import<a name="s56d19203690d4782bfc74069abb6bd71"></a>

```
import deviceManager from '@ohos.distributedHardware.deviceManager';
```

## deviceManager.createDeviceManager<a name="section192192415554"></a>

createDeviceManager\(bundleName: string, callback: AsyncCallback<DeviceManager\>\): void

Creates a  **DeviceManager**  instance.

-   Parameters

    <a name="table69661135912"></a>
    <table><thead align="left"><tr id="row149668318915"><th class="cellrowborder" valign="top" width="13.719999999999999%" id="mcps1.1.5.1.1"><p id="p7966738914"><a name="p7966738914"></a><a name="p7966738914"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="25.919999999999998%" id="mcps1.1.5.1.2"><p id="p296713699"><a name="p296713699"></a><a name="p296713699"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="6.34%" id="mcps1.1.5.1.3"><p id="p196718315911"><a name="p196718315911"></a><a name="p196718315911"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="54.02%" id="mcps1.1.5.1.4"><p id="p9967231197"><a name="p9967231197"></a><a name="p9967231197"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row99671533914"><td class="cellrowborder" valign="top" width="13.719999999999999%" headers="mcps1.1.5.1.1 "><p id="p79671633910"><a name="p79671633910"></a><a name="p79671633910"></a>bundleName</p>
    </td>
    <td class="cellrowborder" valign="top" width="25.919999999999998%" headers="mcps1.1.5.1.2 "><p id="p11967433914"><a name="p11967433914"></a><a name="p11967433914"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="6.34%" headers="mcps1.1.5.1.3 "><p id="p19671336916"><a name="p19671336916"></a><a name="p19671336916"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="54.02%" headers="mcps1.1.5.1.4 "><p id="p69671631796"><a name="p69671631796"></a><a name="p69671631796"></a>Bundle name of the application.</p>
    </td>
    </tr>
    <tr id="row144561193533"><td class="cellrowborder" valign="top" width="13.719999999999999%" headers="mcps1.1.5.1.1 "><p id="p8457201918533"><a name="p8457201918533"></a><a name="p8457201918533"></a>callback</p>
    </td>
    <td class="cellrowborder" valign="top" width="25.919999999999998%" headers="mcps1.1.5.1.2 "><p id="p1445861918533"><a name="p1445861918533"></a><a name="p1445861918533"></a>AsyncCallback&lt;<a href="#section189341937163212">DeviceManager</a>&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="6.34%" headers="mcps1.1.5.1.3 "><p id="p445881995310"><a name="p445881995310"></a><a name="p445881995310"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="54.02%" headers="mcps1.1.5.1.4 "><p id="p462263815412"><a name="p462263815412"></a><a name="p462263815412"></a>Callback invoked to return the <strong id="b1594143115516"><a name="b1594143115516"></a><a name="b1594143115516"></a>DeviceManager</strong> instance created.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Example

    ```
    deviceManager.createDeviceManager("ohos.samples.jshelloworld", (err, data) => {     
        if (err) { 
            console.info("createDeviceManager err:" + JSON.stringify(err));    
            return;
        }
        console.info("createDeviceManager success");
        this.dmInstance = data;
    });
    ```


## DeviceStateChangeAction<a name="section156981915134813"></a>

Enumerates the device states.

<a name="table6699101504818"></a>
<table><thead align="left"><tr id="row15699315154810"><th class="cellrowborder" valign="top" width="27.900000000000002%" id="mcps1.1.4.1.1"><p id="p1369961514489"><a name="p1369961514489"></a><a name="p1369961514489"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="12.43%" id="mcps1.1.4.1.2"><p id="p206991915184810"><a name="p206991915184810"></a><a name="p206991915184810"></a>Default Value</p>
</th>
<th class="cellrowborder" valign="top" width="59.67%" id="mcps1.1.4.1.3"><p id="p7700141594810"><a name="p7700141594810"></a><a name="p7700141594810"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1270061514484"><td class="cellrowborder" valign="top" width="27.900000000000002%" headers="mcps1.1.4.1.1 "><p id="p870051512486"><a name="p870051512486"></a><a name="p870051512486"></a>ONLINE</p>
</td>
<td class="cellrowborder" valign="top" width="12.43%" headers="mcps1.1.4.1.2 "><p id="p970015156487"><a name="p970015156487"></a><a name="p970015156487"></a>0</p>
</td>
<td class="cellrowborder" valign="top" width="59.67%" headers="mcps1.1.4.1.3 "><p id="p167001015104813"><a name="p167001015104813"></a><a name="p167001015104813"></a>The device is online.</p>
</td>
</tr>
<tr id="row1470012151487"><td class="cellrowborder" valign="top" width="27.900000000000002%" headers="mcps1.1.4.1.1 "><p id="p11701151510489"><a name="p11701151510489"></a><a name="p11701151510489"></a>READY</p>
</td>
<td class="cellrowborder" valign="top" width="12.43%" headers="mcps1.1.4.1.2 "><p id="p6701121504814"><a name="p6701121504814"></a><a name="p6701121504814"></a>1</p>
</td>
<td class="cellrowborder" valign="top" width="59.67%" headers="mcps1.1.4.1.3 "><p id="p1885516471376"><a name="p1885516471376"></a><a name="p1885516471376"></a>The device is ready, and the device information has been synchronized.</p>
</td>
</tr>
<tr id="row5701515114812"><td class="cellrowborder" valign="top" width="27.900000000000002%" headers="mcps1.1.4.1.1 "><p id="p13701115164819"><a name="p13701115164819"></a><a name="p13701115164819"></a>OFFLINE</p>
</td>
<td class="cellrowborder" valign="top" width="12.43%" headers="mcps1.1.4.1.2 "><p id="p170121554812"><a name="p170121554812"></a><a name="p170121554812"></a>2</p>
</td>
<td class="cellrowborder" valign="top" width="59.67%" headers="mcps1.1.4.1.3 "><p id="p205289373811"><a name="p205289373811"></a><a name="p205289373811"></a>The device is offline.</p>
</td>
</tr>
<tr id="row617412310499"><td class="cellrowborder" valign="top" width="27.900000000000002%" headers="mcps1.1.4.1.1 "><p id="p1317533134911"><a name="p1317533134911"></a><a name="p1317533134911"></a>CHANGE</p>
</td>
<td class="cellrowborder" valign="top" width="12.43%" headers="mcps1.1.4.1.2 "><p id="p717715318492"><a name="p717715318492"></a><a name="p717715318492"></a>3</p>
</td>
<td class="cellrowborder" valign="top" width="59.67%" headers="mcps1.1.4.1.3 "><p id="p15721234163815"><a name="p15721234163815"></a><a name="p15721234163815"></a>The device information is changed.</p>
</td>
</tr>
</tbody>
</table>

## DeviceType<a name="section3487151562613"></a>

Enumerates device types.

<a name="table204891515112611"></a>
<table><thead align="left"><tr id="row449141516261"><th class="cellrowborder" valign="top" width="27.900000000000002%" id="mcps1.1.4.1.1"><p id="p104911315112617"><a name="p104911315112617"></a><a name="p104911315112617"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="12.43%" id="mcps1.1.4.1.2"><p id="p10493141514261"><a name="p10493141514261"></a><a name="p10493141514261"></a>Default Value</p>
</th>
<th class="cellrowborder" valign="top" width="59.67%" id="mcps1.1.4.1.3"><p id="p2049351517269"><a name="p2049351517269"></a><a name="p2049351517269"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row9493151522618"><td class="cellrowborder" valign="top" width="27.900000000000002%" headers="mcps1.1.4.1.1 "><p id="p135801431142714"><a name="p135801431142714"></a><a name="p135801431142714"></a>SPEAKER</p>
</td>
<td class="cellrowborder" valign="top" width="12.43%" headers="mcps1.1.4.1.2 "><p id="p1549331542617"><a name="p1549331542617"></a><a name="p1549331542617"></a>0x0A</p>
</td>
<td class="cellrowborder" valign="top" width="59.67%" headers="mcps1.1.4.1.3 "><p id="p1249311159262"><a name="p1249311159262"></a><a name="p1249311159262"></a>Smart speaker.</p>
</td>
</tr>
<tr id="row1049491562615"><td class="cellrowborder" valign="top" width="27.900000000000002%" headers="mcps1.1.4.1.1 "><p id="p1494121502620"><a name="p1494121502620"></a><a name="p1494121502620"></a>PHONE</p>
</td>
<td class="cellrowborder" valign="top" width="12.43%" headers="mcps1.1.4.1.2 "><p id="p74942157268"><a name="p74942157268"></a><a name="p74942157268"></a>0x0E</p>
</td>
<td class="cellrowborder" valign="top" width="59.67%" headers="mcps1.1.4.1.3 "><p id="p1342433711302"><a name="p1342433711302"></a><a name="p1342433711302"></a>Phone.</p>
</td>
</tr>
<tr id="row185261110182813"><td class="cellrowborder" valign="top" width="27.900000000000002%" headers="mcps1.1.4.1.1 "><p id="p3527510202816"><a name="p3527510202816"></a><a name="p3527510202816"></a>TABLET</p>
</td>
<td class="cellrowborder" valign="top" width="12.43%" headers="mcps1.1.4.1.2 "><p id="p652761019282"><a name="p652761019282"></a><a name="p652761019282"></a>0x11</p>
</td>
<td class="cellrowborder" valign="top" width="59.67%" headers="mcps1.1.4.1.3 "><p id="p252719101285"><a name="p252719101285"></a><a name="p252719101285"></a>Tablet.</p>
</td>
</tr>
<tr id="row4844121311285"><td class="cellrowborder" valign="top" width="27.900000000000002%" headers="mcps1.1.4.1.1 "><p id="p484411322815"><a name="p484411322815"></a><a name="p484411322815"></a>WEARABLE</p>
</td>
<td class="cellrowborder" valign="top" width="12.43%" headers="mcps1.1.4.1.2 "><p id="p14844181314284"><a name="p14844181314284"></a><a name="p14844181314284"></a>0x6D</p>
</td>
<td class="cellrowborder" valign="top" width="59.67%" headers="mcps1.1.4.1.3 "><p id="p384591318283"><a name="p384591318283"></a><a name="p384591318283"></a>Wearable.</p>
</td>
</tr>
<tr id="row17168195511287"><td class="cellrowborder" valign="top" width="27.900000000000002%" headers="mcps1.1.4.1.1 "><p id="p9168115512815"><a name="p9168115512815"></a><a name="p9168115512815"></a>TV</p>
</td>
<td class="cellrowborder" valign="top" width="12.43%" headers="mcps1.1.4.1.2 "><p id="p19168135517285"><a name="p19168135517285"></a><a name="p19168135517285"></a>0x9C</p>
</td>
<td class="cellrowborder" valign="top" width="59.67%" headers="mcps1.1.4.1.3 "><p id="p1216835519289"><a name="p1216835519289"></a><a name="p1216835519289"></a>Smart TV.</p>
</td>
</tr>
</tbody>
</table>

## DeviceInfo<a name="section393611281845"></a>

Defines device information.

<a name="table12936182811414"></a>
<table><thead align="left"><tr id="row29363281946"><th class="cellrowborder" valign="top" width="17.378262173782623%" id="mcps1.1.5.1.1"><p id="p13936328646"><a name="p13936328646"></a><a name="p13936328646"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="21.547845215478453%" id="mcps1.1.5.1.2"><p id="p1993619281940"><a name="p1993619281940"></a><a name="p1993619281940"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="7.519248075192481%" id="mcps1.1.5.1.3"><p id="p093617285420"><a name="p093617285420"></a><a name="p093617285420"></a>Mandatory</p>
</th>
<th class="cellrowborder" valign="top" width="53.554644535546444%" id="mcps1.1.5.1.4"><p id="p129367281645"><a name="p129367281645"></a><a name="p129367281645"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row793610281849"><td class="cellrowborder" valign="top" width="17.378262173782623%" headers="mcps1.1.5.1.1 "><p id="p15204122815397"><a name="p15204122815397"></a><a name="p15204122815397"></a>deviceId</p>
</td>
<td class="cellrowborder" valign="top" width="21.547845215478453%" headers="mcps1.1.5.1.2 "><p id="p1493611281443"><a name="p1493611281443"></a><a name="p1493611281443"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.5.1.3 "><p id="p99364281045"><a name="p99364281045"></a><a name="p99364281045"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="53.554644535546444%" headers="mcps1.1.5.1.4 "><p id="p13936162810411"><a name="p13936162810411"></a><a name="p13936162810411"></a>Unique device identifier.</p>
</td>
</tr>
<tr id="row39363281414"><td class="cellrowborder" valign="top" width="17.378262173782623%" headers="mcps1.1.5.1.1 "><p id="p793642810415"><a name="p793642810415"></a><a name="p793642810415"></a>deviceName</p>
</td>
<td class="cellrowborder" valign="top" width="21.547845215478453%" headers="mcps1.1.5.1.2 "><p id="p19936228946"><a name="p19936228946"></a><a name="p19936228946"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.5.1.3 "><p id="p139363281843"><a name="p139363281843"></a><a name="p139363281843"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="53.554644535546444%" headers="mcps1.1.5.1.4 "><p id="p1693619288413"><a name="p1693619288413"></a><a name="p1693619288413"></a>Device name.</p>
</td>
</tr>
<tr id="row5184135114013"><td class="cellrowborder" valign="top" width="17.378262173782623%" headers="mcps1.1.5.1.1 "><p id="p18185145174020"><a name="p18185145174020"></a><a name="p18185145174020"></a>deviceType</p>
</td>
<td class="cellrowborder" valign="top" width="21.547845215478453%" headers="mcps1.1.5.1.2 "><p id="p1918618512408"><a name="p1918618512408"></a><a name="p1918618512408"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="7.519248075192481%" headers="mcps1.1.5.1.3 "><p id="p518619574014"><a name="p518619574014"></a><a name="p518619574014"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="53.554644535546444%" headers="mcps1.1.5.1.4 "><p id="p918685154010"><a name="p918685154010"></a><a name="p918685154010"></a>Device type.</p>
</td>
</tr>
</tbody>
</table>

## DeviceManager<a name="section189341937163212"></a>

Creates a  **DeviceManager**  instance to obtain information about trusted devices and local devices. Before calling any method in  **DeviceManager**, you must use  **createDeviceManager**  to create a  **DeviceManager**  instance, for example,  **dmInstance**.

### release<a name="section1410593619146"></a>

release\(\): void

Releases the  **DeviceManager**  instance that is no longer used.

-   Example

    ```
    dmInstance.release();
    ```


### getTrustedDeviceListSync<a name="section1852711414016"></a>

getTrustedDeviceListSync\(\): Array<DeviceInfo\>

Obtains all trusted devices synchronously.

-   Return values

    <a name="table8199123221417"></a>
    <table><thead align="left"><tr id="row111999321149"><th class="cellrowborder" valign="top" width="24.09%" id="mcps1.1.3.1.1"><p id="p1919911321141"><a name="p1919911321141"></a><a name="p1919911321141"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="75.91%" id="mcps1.1.3.1.2"><p id="p1520073216149"><a name="p1520073216149"></a><a name="p1520073216149"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row6200332141417"><td class="cellrowborder" valign="top" width="24.09%" headers="mcps1.1.3.1.1 "><p id="p12200173218149"><a name="p12200173218149"></a><a name="p12200173218149"></a>Array&lt;<a href="#section393611281845">DeviceInfo</a>&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="75.91%" headers="mcps1.1.3.1.2 "><p id="p162001332141414"><a name="p162001332141414"></a><a name="p162001332141414"></a>List of trusted devices obtained.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Example

    ```
    var deviceInfoList = dmInstance.getTrustedDeviceListSync();
    ```


### on\('deviceStateChange'\)<a name="section101188432076"></a>

on\(type: 'deviceStateChange',  callback: Callback<\{ action: DeviceStateChangeAction, device: DeviceInfo \}\>\): void

Subscribes to changes in the device state.

-   Parameters

    <a name="table823014113119"></a>
    <table><thead align="left"><tr id="row2231164193114"><th class="cellrowborder" valign="top" width="17.931793179317932%" id="mcps1.1.5.1.1"><p id="p223118483116"><a name="p223118483116"></a><a name="p223118483116"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="20.282028202820282%" id="mcps1.1.5.1.2"><p id="p72314414319"><a name="p72314414319"></a><a name="p72314414319"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="5.66056605660566%" id="mcps1.1.5.1.3"><p id="p18231134103113"><a name="p18231134103113"></a><a name="p18231134103113"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="56.12561256125613%" id="mcps1.1.5.1.4"><p id="p52311341319"><a name="p52311341319"></a><a name="p52311341319"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row15438135171917"><td class="cellrowborder" valign="top" width="17.931793179317932%" headers="mcps1.1.5.1.1 "><p id="p9438151111918"><a name="p9438151111918"></a><a name="p9438151111918"></a>type</p>
    </td>
    <td class="cellrowborder" valign="top" width="20.282028202820282%" headers="mcps1.1.5.1.2 "><p id="p10438751171919"><a name="p10438751171919"></a><a name="p10438751171919"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="5.66056605660566%" headers="mcps1.1.5.1.3 "><p id="p124386512193"><a name="p124386512193"></a><a name="p124386512193"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="56.12561256125613%" headers="mcps1.1.5.1.4 "><p id="p1943935141916"><a name="p1943935141916"></a><a name="p1943935141916"></a>Event type. The value is <strong id="b1279168134313"><a name="b1279168134313"></a><a name="b1279168134313"></a>deviceStateChange</strong>, which indicates a device state change event.</p>
    </td>
    </tr>
    <tr id="row152317414310"><td class="cellrowborder" valign="top" width="17.931793179317932%" headers="mcps1.1.5.1.1 "><p id="p10231740318"><a name="p10231740318"></a><a name="p10231740318"></a>callback</p>
    </td>
    <td class="cellrowborder" valign="top" width="20.282028202820282%" headers="mcps1.1.5.1.2 "><p id="p3232194193117"><a name="p3232194193117"></a><a name="p3232194193117"></a>Callback&lt;{ action: <a href="#section156981915134813">DeviceStateChangeAction</a>, device: <a href="#section393611281845">DeviceInfo</a> }&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="5.66056605660566%" headers="mcps1.1.5.1.3 "><p id="p3232044311"><a name="p3232044311"></a><a name="p3232044311"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="56.12561256125613%" headers="mcps1.1.5.1.4 "><p id="p11232154133112"><a name="p11232154133112"></a><a name="p11232154133112"></a>Callback invoked to return the device information and state.</p>
    </td>
    </tr>
    </tbody>
    </table>


-   Example

    ```
    dmInstance.on('deviceStateChange', (data) => {      
          console.info("deviceStateChange on:" + JSON.stringify(data));
        }
    );
    ```


### off\('deviceStateChange'\)<a name="section134699111387"></a>

off\(type: 'deviceStateChange', callback?: Call	 back<\{ action: DeviceStateChangeAction, device: DeviceInfo \}\>\): void

Unsubscribes from changes in the device state.

-   Parameters

    <a name="table18791185053312"></a>
    <table><thead align="left"><tr id="row47921950163318"><th class="cellrowborder" valign="top" width="17.931793179317932%" id="mcps1.1.5.1.1"><p id="p27921505339"><a name="p27921505339"></a><a name="p27921505339"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="24.482448244824482%" id="mcps1.1.5.1.2"><p id="p1579285018334"><a name="p1579285018334"></a><a name="p1579285018334"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="7.770777077707772%" id="mcps1.1.5.1.3"><p id="p97921450143320"><a name="p97921450143320"></a><a name="p97921450143320"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="49.81498149814981%" id="mcps1.1.5.1.4"><p id="p17792350173319"><a name="p17792350173319"></a><a name="p17792350173319"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row8792250123315"><td class="cellrowborder" valign="top" width="17.931793179317932%" headers="mcps1.1.5.1.1 "><p id="p10793155033312"><a name="p10793155033312"></a><a name="p10793155033312"></a>type</p>
    </td>
    <td class="cellrowborder" valign="top" width="24.482448244824482%" headers="mcps1.1.5.1.2 "><p id="p157931850173315"><a name="p157931850173315"></a><a name="p157931850173315"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="7.770777077707772%" headers="mcps1.1.5.1.3 "><p id="p177931950143316"><a name="p177931950143316"></a><a name="p177931950143316"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="49.81498149814981%" headers="mcps1.1.5.1.4 "><p id="p1879312503335"><a name="p1879312503335"></a><a name="p1879312503335"></a>Event type. The value <strong id="b10256255145015"><a name="b10256255145015"></a><a name="b10256255145015"></a>deviceStateChange</strong> indicates an event of device state change.</p>
    </td>
    </tr>
    <tr id="row5794135012339"><td class="cellrowborder" valign="top" width="17.931793179317932%" headers="mcps1.1.5.1.1 "><p id="p197941750143320"><a name="p197941750143320"></a><a name="p197941750143320"></a>callback</p>
    </td>
    <td class="cellrowborder" valign="top" width="24.482448244824482%" headers="mcps1.1.5.1.2 "><p id="p279418508335"><a name="p279418508335"></a><a name="p279418508335"></a>Callback&lt;{ action: <a href="#section156981915134813">DeviceStateChangeAction</a>, device: <a href="#section393611281845">DeviceInfo</a>  }&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="7.770777077707772%" headers="mcps1.1.5.1.3 "><p id="p279485073313"><a name="p279485073313"></a><a name="p279485073313"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="49.81498149814981%" headers="mcps1.1.5.1.4 "><p id="p142116971010"><a name="p142116971010"></a><a name="p142116971010"></a>Callback used to return the device state changes.</p>
    </td>
    </tr>
    </tbody>
    </table>


-   Example

    ```
    dmInstance.off('deviceStateChange', (data) => {      
          console.info('deviceStateChange' + JSON.stringify(data));
       }
    );
    ```


### on\('serviceDie'\)<a name="section151111734384"></a>

on\(type: 'serviceDie', callback: \(\) =\> void\): void

Subscribes to dead events of the  **DeviceManager**  service.

-   Parameters

    <a name="table1912114614611"></a>
    <table><thead align="left"><tr id="row2091215468618"><th class="cellrowborder" valign="top" width="17.931793179317932%" id="mcps1.1.5.1.1"><p id="p49133461260"><a name="p49133461260"></a><a name="p49133461260"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="22.092209220922093%" id="mcps1.1.5.1.2"><p id="p12913124611619"><a name="p12913124611619"></a><a name="p12913124611619"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="6.760676067606759%" id="mcps1.1.5.1.3"><p id="p1691310461868"><a name="p1691310461868"></a><a name="p1691310461868"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="53.21532153215321%" id="mcps1.1.5.1.4"><p id="p11913164610620"><a name="p11913164610620"></a><a name="p11913164610620"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row2091312460610"><td class="cellrowborder" valign="top" width="17.931793179317932%" headers="mcps1.1.5.1.1 "><p id="p4913134614620"><a name="p4913134614620"></a><a name="p4913134614620"></a>type</p>
    </td>
    <td class="cellrowborder" valign="top" width="22.092209220922093%" headers="mcps1.1.5.1.2 "><p id="p29144462067"><a name="p29144462067"></a><a name="p29144462067"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="6.760676067606759%" headers="mcps1.1.5.1.3 "><p id="p29141146461"><a name="p29141146461"></a><a name="p29141146461"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="53.21532153215321%" headers="mcps1.1.5.1.4 "><p id="p291417464617"><a name="p291417464617"></a><a name="p291417464617"></a>Event type. The value <strong id="b1040503814298"><a name="b1040503814298"></a><a name="b1040503814298"></a>serviceDie</strong> indicates an event reported when the <strong id="b11215122991019"><a name="b11215122991019"></a><a name="b11215122991019"></a>DeviceManager</strong> service is terminated unexpectedly.</p>
    </td>
    </tr>
    <tr id="row7915154613614"><td class="cellrowborder" valign="top" width="17.931793179317932%" headers="mcps1.1.5.1.1 "><p id="p1091504612615"><a name="p1091504612615"></a><a name="p1091504612615"></a>callback</p>
    </td>
    <td class="cellrowborder" valign="top" width="22.092209220922093%" headers="mcps1.1.5.1.2 "><p id="p14196827333"><a name="p14196827333"></a><a name="p14196827333"></a>() =&gt; void</p>
    </td>
    <td class="cellrowborder" valign="top" width="6.760676067606759%" headers="mcps1.1.5.1.3 "><p id="p9916114613620"><a name="p9916114613620"></a><a name="p9916114613620"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="53.21532153215321%" headers="mcps1.1.5.1.4 "><p id="p1391704610616"><a name="p1391704610616"></a><a name="p1391704610616"></a>Callback invoked when a dead event of the <strong id="b383916403128"><a name="b383916403128"></a><a name="b383916403128"></a>DeviceManager</strong> service occurs.</p>
    </td>
    </tr>
    </tbody>
    </table>


-   Example

    ```
    dmInstance.on("serviceDie", () => {      
          console.info("serviceDie on");
       }
    );
    ```


### off\('serviceDie'\)<a name="section158100531288"></a>

off\(type: 'serviceDie', callback?: \(\) =\> void\): void

Unsubscribes from dead events of the  **DeviceManager**  service.

-   Parameters

    <a name="table181884558136"></a>
    <table><thead align="left"><tr id="row1218915515139"><th class="cellrowborder" valign="top" width="17.931793179317932%" id="mcps1.1.5.1.1"><p id="p41901355191318"><a name="p41901355191318"></a><a name="p41901355191318"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="24.482448244824482%" id="mcps1.1.5.1.2"><p id="p6190205517131"><a name="p6190205517131"></a><a name="p6190205517131"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="7.770777077707772%" id="mcps1.1.5.1.3"><p id="p6190105561313"><a name="p6190105561313"></a><a name="p6190105561313"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="49.81498149814981%" id="mcps1.1.5.1.4"><p id="p019185511139"><a name="p019185511139"></a><a name="p019185511139"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row9192755151316"><td class="cellrowborder" valign="top" width="17.931793179317932%" headers="mcps1.1.5.1.1 "><p id="p519245531316"><a name="p519245531316"></a><a name="p519245531316"></a>type</p>
    </td>
    <td class="cellrowborder" valign="top" width="24.482448244824482%" headers="mcps1.1.5.1.2 "><p id="p111928552130"><a name="p111928552130"></a><a name="p111928552130"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="7.770777077707772%" headers="mcps1.1.5.1.3 "><p id="p14192195521317"><a name="p14192195521317"></a><a name="p14192195521317"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="49.81498149814981%" headers="mcps1.1.5.1.4 "><p id="p1319225511135"><a name="p1319225511135"></a><a name="p1319225511135"></a>Event type. The value <strong id="b174417818132"><a name="b174417818132"></a><a name="b174417818132"></a>serviceDie</strong> indicates an event reported when the <strong id="b7501288133"><a name="b7501288133"></a><a name="b7501288133"></a>DeviceManager</strong> service is terminated unexpectedly.</p>
    </td>
    </tr>
    <tr id="row19193555121318"><td class="cellrowborder" valign="top" width="17.931793179317932%" headers="mcps1.1.5.1.1 "><p id="p919385581319"><a name="p919385581319"></a><a name="p919385581319"></a>callback</p>
    </td>
    <td class="cellrowborder" valign="top" width="24.482448244824482%" headers="mcps1.1.5.1.2 "><p id="p1340719117399"><a name="p1340719117399"></a><a name="p1340719117399"></a>() =&gt; void</p>
    </td>
    <td class="cellrowborder" valign="top" width="7.770777077707772%" headers="mcps1.1.5.1.3 "><p id="p161931955151312"><a name="p161931955151312"></a><a name="p161931955151312"></a>No</p>
    </td>
    <td class="cellrowborder" valign="top" width="49.81498149814981%" headers="mcps1.1.5.1.4 "><p id="p176817315398"><a name="p176817315398"></a><a name="p176817315398"></a>Callback used to return the dead event of the <strong id="b1519912196133"><a name="b1519912196133"></a><a name="b1519912196133"></a>DeviceManager</strong> service.</p>
    </td>
    </tr>
    </tbody>
    </table>


-   Example

    ```
    dmInstance.off("serviceDie", () => {      
          console.info("serviceDie off");
      }
    );
    ```


