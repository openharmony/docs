# User Authentication<a name="EN-US_TOPIC_0000001189766193"></a>

>![](../public_sys-resources/icon-note.gif) **NOTE:** 
>The initial APIs of this module are supported since API version 6. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Applicable Devices<a name="section16881239114912"></a>

<a name="table857714145377"></a>
<table><thead align="left"><tr id="row55778146373"><th class="cellrowborder" valign="top" width="25%" id="mcps1.1.5.1.1"><p id="p7577141417376"><a name="p7577141417376"></a><a name="p7577141417376"></a>Phone</p>
</th>
<th class="cellrowborder" valign="top" width="25%" id="mcps1.1.5.1.2"><p id="p487719816463"><a name="p487719816463"></a><a name="p487719816463"></a>Tablet</p>
</th>
<th class="cellrowborder" valign="top" width="25%" id="mcps1.1.5.1.3"><p id="p135771614203720"><a name="p135771614203720"></a><a name="p135771614203720"></a>Smart TV</p>
</th>
<th class="cellrowborder" valign="top" width="25%" id="mcps1.1.5.1.4"><p id="p25772014133712"><a name="p25772014133712"></a><a name="p25772014133712"></a>Wearable</p>
</th>
</tr>
</thead>
<tbody><tr id="row8578151423715"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.1 "><p id="p65782014203718"><a name="p65782014203718"></a><a name="p65782014203718"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.2 "><p id="p148771182469"><a name="p148771182469"></a><a name="p148771182469"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.3 "><p id="p45783141377"><a name="p45783141377"></a><a name="p45783141377"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.5.1.4 "><p id="p11578161443718"><a name="p11578161443718"></a><a name="p11578161443718"></a>No</p>
</td>
</tr>
</tbody>
</table>

## Modules to Import<a name="s56d19203690d4782bfc74069abb6bd71"></a>

```
import userIAM_userAuth from '@ohos.userIAM.userAuth';
```

## Required Permissions<a name="section11257113618419"></a>

ohos.permission.ACCESS\_BIOMETRIC

## Sample Code<a name="section1278784362016"></a>

```
import userIAM_userAuth from '@ohos.userIAM.userAuth';

export default {
    startAuth() {
        console.info("start auth");
        let tipCallback = (tip)=>{
            console.info("receive tip: errorCode(" + tip.errorCode + ") code(" + tip.tipCode + ") event(" +
                tip.tipEvent + ") info(" + tip.tipInfo + ")");
            // Add the logic for displaying the prompt message.
        };
        let auth = userIAM_userAuth.getAuthenticator();
        auth.on("tip", tipCallback);
        auth.execute("FACE_ONLY", "S2").then((code)=>{
            auth.off("tip", tipCallback);
            console.info("auth success");
            // Add the logic for authentication success.
        }).catch((code)=>{
            auth.off("tip", tipCallback);
            console.error("auth fail, code = " + code);
            // Add the logic for authentication failure.
        });
    },

    checkAuthSupport() {
        console.info("start check auth support");
        let auth = userIAM_userAuth.getAuthenticator();
        let checkCode = auth.checkAvailability("FACE_ONLY", "S2");
        if (checkCode == userIAM_userAuth.CheckAvailabilityResult.SUPPORTED) {
            console.info("check auth support success");
            // Add the logic for the specified authentication type supported.
        } else {
            console.error("check auth support fail, code = " + checkCode);
            // Add the logic for the authentication type that is not supported.
        }
    },

    cancelAuth() {
        console.info("start cancel auth");
        let auth = userIAM_userAuth.getAuthenticator();
        let cancelCode = auth.cancel();
        if (cancelCode == userIAM_userAuth.Result.SUCCESS) {
            console.info("cancel auth success");
        } else {
            console.error("cancel auth fail");
        }
    }
}
```

## userIAM\_userAuth.getAuthenticator<a name="section1853612361618"></a>

getAuthenticator\(\): Authenticator

Obtains an  **Authenticator**  object for user authentication.  <sup>6+</sup>

Obtains an  **Authenticator**  object to check the device's capability of user authentication, perform or cancel user authentication, and obtain the tips generated in the authentication process.  <sup>7+</sup>

-   Return values

    <a name="t3e93239d9b134b80957bcdd4acb05291"></a>
    <table><thead align="left"><tr id="recc81d9f995d44aa87ba9d714b756569"><th class="cellrowborder" valign="top" width="16.05%" id="mcps1.1.3.1.1"><p id="a6b166163db284e5ca8dc0190b36ae40a"><a name="a6b166163db284e5ca8dc0190b36ae40a"></a><a name="a6b166163db284e5ca8dc0190b36ae40a"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="83.95%" id="mcps1.1.3.1.2"><p id="a4ba8ead9ee7b48298d9a6ed10659f13b"><a name="a4ba8ead9ee7b48298d9a6ed10659f13b"></a><a name="a4ba8ead9ee7b48298d9a6ed10659f13b"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="r64430cb15b54497f88ea6330b9a7454c"><td class="cellrowborder" valign="top" width="16.05%" headers="mcps1.1.3.1.1 "><p id="p1449417172406"><a name="p1449417172406"></a><a name="p1449417172406"></a><a href="#section166491757105314">Authenticator</a></p>
    </td>
    <td class="cellrowborder" valign="top" width="83.95%" headers="mcps1.1.3.1.2 "><p id="a1c9b8d1829ef489e9e0fd1863190d228"><a name="a1c9b8d1829ef489e9e0fd1863190d228"></a><a name="a1c9b8d1829ef489e9e0fd1863190d228"></a><strong id="b31051251645"><a name="b31051251645"></a><a name="b31051251645"></a>Authenticator</strong> object obtained.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Example

    ```
    let authenticator = userIAM_userAuth.getAuthenticator();
    ```


## Authenticator<a name="section166491757105314"></a>

Provides an  **Authenticator**  object.

### execute<a name="section1872713918515"></a>

execute\(type: string, level: string, callback: AsyncCallback<number\>\): void

Performs user authentication and returns the authentication result using an asynchronous callback.

-   Parameters

    <a name="table14435501767"></a>
    <table><thead align="left"><tr id="row2043517012615"><th class="cellrowborder" valign="top" width="11.03%" id="mcps1.1.5.1.1"><p id="p1943514016617"><a name="p1943514016617"></a><a name="p1943514016617"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="22.58%" id="mcps1.1.5.1.2"><p id="p8435701860"><a name="p8435701860"></a><a name="p8435701860"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="8.21%" id="mcps1.1.5.1.3"><p id="p14351802615"><a name="p14351802615"></a><a name="p14351802615"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="58.18%" id="mcps1.1.5.1.4"><p id="p743517014619"><a name="p743517014619"></a><a name="p743517014619"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row14436901969"><td class="cellrowborder" valign="top" width="11.03%" headers="mcps1.1.5.1.1 "><p id="p124361401667"><a name="p124361401667"></a><a name="p124361401667"></a>type</p>
    </td>
    <td class="cellrowborder" valign="top" width="22.58%" headers="mcps1.1.5.1.2 "><p id="p543612012618"><a name="p543612012618"></a><a name="p543612012618"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="8.21%" headers="mcps1.1.5.1.3 "><p id="p164361007619"><a name="p164361007619"></a><a name="p164361007619"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="58.18%" headers="mcps1.1.5.1.4 "><p id="p9436110360"><a name="p9436110360"></a><a name="p9436110360"></a>Authentication type. Only <strong id="b74282058165612"><a name="b74282058165612"></a><a name="b74282058165612"></a>FACE_ONLY</strong> is supported.</p>
    <p id="p18764165418403"><a name="p18764165418403"></a><a name="p18764165418403"></a><strong id="b16718485101"><a name="b16718485101"></a><a name="b16718485101"></a>ALL</strong> is reserved and not supported by the current version.</p>
    </td>
    </tr>
    <tr id="row14368013620"><td class="cellrowborder" valign="top" width="11.03%" headers="mcps1.1.5.1.1 "><p id="p104367018619"><a name="p104367018619"></a><a name="p104367018619"></a>level</p>
    </td>
    <td class="cellrowborder" valign="top" width="22.58%" headers="mcps1.1.5.1.2 "><p id="p1743660865"><a name="p1743660865"></a><a name="p1743660865"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="8.21%" headers="mcps1.1.5.1.3 "><p id="p1436701661"><a name="p1436701661"></a><a name="p1436701661"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="58.18%" headers="mcps1.1.5.1.4 "><p id="p154361901865"><a name="p154361901865"></a><a name="p154361901865"></a>Security level of the authentication. It can be <strong id="b82810554407"><a name="b82810554407"></a><a name="b82810554407"></a>S1</strong> (lowest), <strong id="b3281185516404"><a name="b3281185516404"></a><a name="b3281185516404"></a>S2</strong>, <strong id="b128245518408"><a name="b128245518408"></a><a name="b128245518408"></a>S3</strong>, or <strong id="b8282195554014"><a name="b8282195554014"></a><a name="b8282195554014"></a>S4</strong> (highest).</p>
    <p id="p14362004616"><a name="p14362004616"></a><a name="p14362004616"></a>Devices capable of 3D facial recognition support S3 and lower-level authentication.</p>
    <p id="p643610065"><a name="p643610065"></a><a name="p643610065"></a>Devices capable of 2D facial recognition support S2 and lower-level authentication.</p>
    </td>
    </tr>
    <tr id="row104368020612"><td class="cellrowborder" valign="top" width="11.03%" headers="mcps1.1.5.1.1 "><p id="p1043620269"><a name="p1043620269"></a><a name="p1043620269"></a>callback</p>
    </td>
    <td class="cellrowborder" valign="top" width="22.58%" headers="mcps1.1.5.1.2 "><p id="p9769113785519"><a name="p9769113785519"></a><a name="p9769113785519"></a>AsyncCallback&lt;number&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="8.21%" headers="mcps1.1.5.1.3 "><p id="p12436100266"><a name="p12436100266"></a><a name="p12436100266"></a>No</p>
    </td>
    <td class="cellrowborder" valign="top" width="58.18%" headers="mcps1.1.5.1.4 "><p id="p104368014612"><a name="p104368014612"></a><a name="p104368014612"></a>Callback invoked to return the authentication result</p>
    </td>
    </tr>
    </tbody>
    </table>

    Callback return values

    <a name="table3436601460"></a>
    <table><thead align="left"><tr id="row18437201162"><th class="cellrowborder" valign="top" width="12.33%" id="mcps1.1.3.1.1"><p id="p743710263"><a name="p743710263"></a><a name="p743710263"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="87.67%" id="mcps1.1.3.1.2"><p id="p1443714017615"><a name="p1443714017615"></a><a name="p1443714017615"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row12437180360"><td class="cellrowborder" valign="top" width="12.33%" headers="mcps1.1.3.1.1 "><p id="p10437190768"><a name="p10437190768"></a><a name="p10437190768"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="87.67%" headers="mcps1.1.3.1.2 "><p id="p643717017615"><a name="p643717017615"></a><a name="p643717017615"></a>Authentication result. See <a href="#section71321544144418">AuthenticationResult</a>.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Example

    ```
    authenticator.execute("FACE_ONLY", "S2", (code)=>{
        if (code == userIAM_userAuth.AuthenticationResult.SUCCESS) {
            console.info("auth success");
            return;
        }
        console.error("auth fail, code = " + code);
    })
    ```


### execute<a name="section9740122912611"></a>

execute\(type:string, level:string\): Promise<number\>

Performs user authentication and returns the authentication result using a promise.

-   Parameters

    <a name="table1710811176517"></a>
    <table><thead align="left"><tr id="row1010821745114"><th class="cellrowborder" valign="top" width="11.03%" id="mcps1.1.5.1.1"><p id="p1610801715512"><a name="p1610801715512"></a><a name="p1610801715512"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="11.64%" id="mcps1.1.5.1.2"><p id="p111081217185110"><a name="p111081217185110"></a><a name="p111081217185110"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="7.1499999999999995%" id="mcps1.1.5.1.3"><p id="p161081517145119"><a name="p161081517145119"></a><a name="p161081517145119"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="70.17999999999999%" id="mcps1.1.5.1.4"><p id="p3108317135115"><a name="p3108317135115"></a><a name="p3108317135115"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row810913170514"><td class="cellrowborder" valign="top" width="11.03%" headers="mcps1.1.5.1.1 "><p id="p91091117195117"><a name="p91091117195117"></a><a name="p91091117195117"></a>type</p>
    </td>
    <td class="cellrowborder" valign="top" width="11.64%" headers="mcps1.1.5.1.2 "><p id="p1810941775114"><a name="p1810941775114"></a><a name="p1810941775114"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="7.1499999999999995%" headers="mcps1.1.5.1.3 "><p id="p1210915176517"><a name="p1210915176517"></a><a name="p1210915176517"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="70.17999999999999%" headers="mcps1.1.5.1.4 "><p id="p19109111735111"><a name="p19109111735111"></a><a name="p19109111735111"></a>Authentication type. Only <strong id="b7977192195712"><a name="b7977192195712"></a><a name="b7977192195712"></a>FACE_ONLY</strong> is supported.</p>
    <p id="p33401722105117"><a name="p33401722105117"></a><a name="p33401722105117"></a><strong id="b810618395"><a name="b810618395"></a><a name="b810618395"></a>ALL</strong> is reserved and not supported by the current version.</p>
    </td>
    </tr>
    <tr id="row131091517105113"><td class="cellrowborder" valign="top" width="11.03%" headers="mcps1.1.5.1.1 "><p id="p010915173518"><a name="p010915173518"></a><a name="p010915173518"></a>level</p>
    </td>
    <td class="cellrowborder" valign="top" width="11.64%" headers="mcps1.1.5.1.2 "><p id="p9109161718518"><a name="p9109161718518"></a><a name="p9109161718518"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="7.1499999999999995%" headers="mcps1.1.5.1.3 "><p id="p9109141785119"><a name="p9109141785119"></a><a name="p9109141785119"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="70.17999999999999%" headers="mcps1.1.5.1.4 "><p id="p785974215531"><a name="p785974215531"></a><a name="p785974215531"></a>Security level of the authentication. It can be <strong id="b15960143804616"><a name="b15960143804616"></a><a name="b15960143804616"></a>S1</strong> (lowest), <strong id="b896033844616"><a name="b896033844616"></a><a name="b896033844616"></a>S2</strong>, <strong id="b1096013819464"><a name="b1096013819464"></a><a name="b1096013819464"></a>S3</strong>, or <strong id="b99601438144615"><a name="b99601438144615"></a><a name="b99601438144615"></a>S4</strong> (highest).</p>
    <p id="p7109181716519"><a name="p7109181716519"></a><a name="p7109181716519"></a>Devices capable of 3D facial recognition support S3 and lower-level authentication.</p>
    <p id="p121090173514"><a name="p121090173514"></a><a name="p121090173514"></a>Devices capable of 2D facial recognition support S2 and lower-level authentication.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Return values

    <a name="table1676131219370"></a>
    <table><thead align="left"><tr id="row9761171212377"><th class="cellrowborder" valign="top" width="17.51%" id="mcps1.1.3.1.1"><p id="p47611812173716"><a name="p47611812173716"></a><a name="p47611812173716"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="82.49%" id="mcps1.1.3.1.2"><p id="p17619128372"><a name="p17619128372"></a><a name="p17619128372"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row107617126379"><td class="cellrowborder" valign="top" width="17.51%" headers="mcps1.1.3.1.1 "><p id="p63601172573"><a name="p63601172573"></a><a name="p63601172573"></a>Promise&lt;number&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="82.49%" headers="mcps1.1.3.1.2 "><p id="p26666151431"><a name="p26666151431"></a><a name="p26666151431"></a>Promise used to return the authentication result. The number in the promise indicates the authentication result. See <a href="#section71321544144418">AuthenticationResult</a>.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Example

    ```
    let authenticator = userIAM_userAuth.getAuthenticator();
    authenticator.execute("FACE_ONLY", "S2").then((code)=>{
        authenticator.off("tip", tipCallback);
        console.info("auth success");
    }).catch((code)=>{
        authenticator.off("tip", tipCallback);
        console.error("auth fail, code = " + code);
    });
    ```


### cancel<sup>7+</sup><a name="section18396828125"></a>

cancel\(\): number

Cancels the current authentication.

-   Return values

    <a name="table1590525122517"></a>
    <table><thead align="left"><tr id="row259042512515"><th class="cellrowborder" valign="top" width="17.51%" id="mcps1.1.3.1.1"><p id="p15901425142510"><a name="p15901425142510"></a><a name="p15901425142510"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="82.49%" id="mcps1.1.3.1.2"><p id="p145901525142512"><a name="p145901525142512"></a><a name="p145901525142512"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row15901225182518"><td class="cellrowborder" valign="top" width="17.51%" headers="mcps1.1.3.1.1 "><p id="p9590182532510"><a name="p9590182532510"></a><a name="p9590182532510"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="82.49%" headers="mcps1.1.3.1.2 "><p id="p3590102592516"><a name="p3590102592516"></a><a name="p3590102592516"></a>Whether the authentication is canceled. For details, see <a href="#section593513424528">Result</a>.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Example

    ```
    let authenticator = userIAM_userAuth.getAuthenticator();
    let cancelCode = authenticator.cancel();
    if (cancelCode == userIAM_userAuth.Result.SUCCESS) {
        console.info("cancel auth success");
    } else {
        console.error("cancel auth fail");
    }
    ```


### checkAvailability<sup>7+</sup><a name="section14839102171416"></a>

checkAvailability\(type: AuthType, level: SecureLevel\): number

Checks whether the device supports the specified authentication type and security level.

-   Parameters

    <a name="table102411744184118"></a>
    <table><thead align="left"><tr id="row12241104454114"><th class="cellrowborder" valign="top" width="11.03%" id="mcps1.1.5.1.1"><p id="p72411440415"><a name="p72411440415"></a><a name="p72411440415"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="11.64%" id="mcps1.1.5.1.2"><p id="p9241144484112"><a name="p9241144484112"></a><a name="p9241144484112"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="7.1499999999999995%" id="mcps1.1.5.1.3"><p id="p13241544114118"><a name="p13241544114118"></a><a name="p13241544114118"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="70.17999999999999%" id="mcps1.1.5.1.4"><p id="p224154414116"><a name="p224154414116"></a><a name="p224154414116"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row13241144416415"><td class="cellrowborder" valign="top" width="11.03%" headers="mcps1.1.5.1.1 "><p id="p17241124474110"><a name="p17241124474110"></a><a name="p17241124474110"></a>type</p>
    </td>
    <td class="cellrowborder" valign="top" width="11.64%" headers="mcps1.1.5.1.2 "><p id="p1724220443411"><a name="p1724220443411"></a><a name="p1724220443411"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="7.1499999999999995%" headers="mcps1.1.5.1.3 "><p id="p142421244144114"><a name="p142421244144114"></a><a name="p142421244144114"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="70.17999999999999%" headers="mcps1.1.5.1.4 "><p id="p8242134416410"><a name="p8242134416410"></a><a name="p8242134416410"></a>Authentication type. Only <strong id="b1035323028"><a name="b1035323028"></a><a name="b1035323028"></a>FACE_ONLY</strong> is supported.</p>
    <p id="p1924244411416"><a name="p1924244411416"></a><a name="p1924244411416"></a><strong id="b553343868"><a name="b553343868"></a><a name="b553343868"></a>ALL</strong> is reserved and not supported by the current version.</p>
    </td>
    </tr>
    <tr id="row324224414116"><td class="cellrowborder" valign="top" width="11.03%" headers="mcps1.1.5.1.1 "><p id="p1124264474112"><a name="p1124264474112"></a><a name="p1124264474112"></a>level</p>
    </td>
    <td class="cellrowborder" valign="top" width="11.64%" headers="mcps1.1.5.1.2 "><p id="p102421744174111"><a name="p102421744174111"></a><a name="p102421744174111"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="7.1499999999999995%" headers="mcps1.1.5.1.3 "><p id="p42422044164115"><a name="p42422044164115"></a><a name="p42422044164115"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="70.17999999999999%" headers="mcps1.1.5.1.4 "><p id="p7242164415411"><a name="p7242164415411"></a><a name="p7242164415411"></a>Security level of the authentication. It can be <strong id="b333736859"><a name="b333736859"></a><a name="b333736859"></a>S1</strong> (lowest), <strong id="b1107708564"><a name="b1107708564"></a><a name="b1107708564"></a>S2</strong>, <strong id="b661259336"><a name="b661259336"></a><a name="b661259336"></a>S3</strong>, or <strong id="b1867933861"><a name="b1867933861"></a><a name="b1867933861"></a>S4</strong> (highest).</p>
    <p id="p11242164412416"><a name="p11242164412416"></a><a name="p11242164412416"></a>Devices capable of 3D facial recognition support S3 and lower-level authentication.</p>
    <p id="p1242144464114"><a name="p1242144464114"></a><a name="p1242144464114"></a>Devices capable of 2D facial recognition support S2 and lower-level authentication.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Return values

    <a name="table1916214213435"></a>
    <table><thead align="left"><tr id="row1516282154317"><th class="cellrowborder" valign="top" width="17.51%" id="mcps1.1.3.1.1"><p id="p51621621164311"><a name="p51621621164311"></a><a name="p51621621164311"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="82.49%" id="mcps1.1.3.1.2"><p id="p616272110436"><a name="p616272110436"></a><a name="p616272110436"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row9162162124315"><td class="cellrowborder" valign="top" width="17.51%" headers="mcps1.1.3.1.1 "><p id="p1416262112436"><a name="p1416262112436"></a><a name="p1416262112436"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="82.49%" headers="mcps1.1.3.1.2 "><p id="p2162102116439"><a name="p2162102116439"></a><a name="p2162102116439"></a>Check result. For details, see <a href="#section856311913566">CheckAvailabilityResult</a>.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Example

    ```
    let authenticator = userIAM_userAuth.getAuthenticator();
    let checkCode = authenticator.checkAvailability("FACE_ONLY", "S2");
    if (checkCode == userIAM_userAuth.CheckAvailabilityResult.SUPPORTED) {
        console.info("check auth support success");
    } else {
        console.error("check auth support fail, code = " + checkCode);
    }
    ```


### on<sup>7+</sup><a name="section1139819911154"></a>

on\(type: "tip", callback: Callback<Tip\>\) : void;

Subscribes to the events of the specified type.

-   Parameters

    <a name="table682711182510"></a>
    <table><thead align="left"><tr id="row38211119253"><th class="cellrowborder" valign="top" width="11.03%" id="mcps1.1.5.1.1"><p id="p1483101114250"><a name="p1483101114250"></a><a name="p1483101114250"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="12.629999999999999%" id="mcps1.1.5.1.2"><p id="p138311112257"><a name="p138311112257"></a><a name="p138311112257"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="6.16%" id="mcps1.1.5.1.3"><p id="p118319117253"><a name="p118319117253"></a><a name="p118319117253"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="70.17999999999999%" id="mcps1.1.5.1.4"><p id="p183171110259"><a name="p183171110259"></a><a name="p183171110259"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row683191192515"><td class="cellrowborder" valign="top" width="11.03%" headers="mcps1.1.5.1.1 "><p id="p583121102520"><a name="p583121102520"></a><a name="p583121102520"></a>type</p>
    </td>
    <td class="cellrowborder" valign="top" width="12.629999999999999%" headers="mcps1.1.5.1.2 "><p id="p148311114256"><a name="p148311114256"></a><a name="p148311114256"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="6.16%" headers="mcps1.1.5.1.3 "><p id="p158301192518"><a name="p158301192518"></a><a name="p158301192518"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="70.17999999999999%" headers="mcps1.1.5.1.4 "><p id="p1883201115259"><a name="p1883201115259"></a><a name="p1883201115259"></a>Event type. Currently, only <strong id="b745040141017"><a name="b745040141017"></a><a name="b745040141017"></a>tip</strong> is supported. An event is triggered when the authentication service sends a message to the caller.</p>
    </td>
    </tr>
    <tr id="row58314116257"><td class="cellrowborder" valign="top" width="11.03%" headers="mcps1.1.5.1.1 "><p id="p58316116251"><a name="p58316116251"></a><a name="p58316116251"></a>callback</p>
    </td>
    <td class="cellrowborder" valign="top" width="12.629999999999999%" headers="mcps1.1.5.1.2 "><p id="p379213486256"><a name="p379213486256"></a><a name="p379213486256"></a>Callback&lt;Tip&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="6.16%" headers="mcps1.1.5.1.3 "><p id="p12831611192510"><a name="p12831611192510"></a><a name="p12831611192510"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="70.17999999999999%" headers="mcps1.1.5.1.4 "><p id="p183662056132512"><a name="p183662056132512"></a><a name="p183662056132512"></a>Callback used to report the event of the specified type. Currently, only the <strong id="b10471104135112"><a name="b10471104135112"></a><a name="b10471104135112"></a>tip</strong> event is supported.</p>
    </td>
    </tr>
    </tbody>
    </table>


-   Example

    ```
    let authenticator = userIAM_userAuth.getAuthenticator();
    let tipCallback = (tip)=>{
        console.info("receive tip: errorCode(" + tip.errorCode + ") code(" + tip.tipCode +") event(" +
            tip.tipEvent + ") info(" + tip.tipInfo + ")");
    };
    authenticator.on("tip", tipCallback);
    ```


### off<sup>7+</sup><a name="section571162712017"></a>

off\(type: "tip", callback?: Callback<Tip\>\) : void;

Unsubscribes from the events of the specified type.

-   Parameters

    <a name="table128591727133319"></a>
    <table><thead align="left"><tr id="row68591627173314"><th class="cellrowborder" valign="top" width="11.03%" id="mcps1.1.5.1.1"><p id="p14859927173316"><a name="p14859927173316"></a><a name="p14859927173316"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="12.629999999999999%" id="mcps1.1.5.1.2"><p id="p198591027103318"><a name="p198591027103318"></a><a name="p198591027103318"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="6.16%" id="mcps1.1.5.1.3"><p id="p185962703314"><a name="p185962703314"></a><a name="p185962703314"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="70.17999999999999%" id="mcps1.1.5.1.4"><p id="p585910275337"><a name="p585910275337"></a><a name="p585910275337"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row16859122710335"><td class="cellrowborder" valign="top" width="11.03%" headers="mcps1.1.5.1.1 "><p id="p14859182711330"><a name="p14859182711330"></a><a name="p14859182711330"></a>type</p>
    </td>
    <td class="cellrowborder" valign="top" width="12.629999999999999%" headers="mcps1.1.5.1.2 "><p id="p13859192733313"><a name="p13859192733313"></a><a name="p13859192733313"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="6.16%" headers="mcps1.1.5.1.3 "><p id="p108591127193314"><a name="p108591127193314"></a><a name="p108591127193314"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="70.17999999999999%" headers="mcps1.1.5.1.4 "><p id="p5859162716332"><a name="p5859162716332"></a><a name="p5859162716332"></a>Event type. Currently, only <strong id="b3114155914109"><a name="b3114155914109"></a><a name="b3114155914109"></a>tip</strong> is supported.</p>
    </td>
    </tr>
    <tr id="row12859727163312"><td class="cellrowborder" valign="top" width="11.03%" headers="mcps1.1.5.1.1 "><p id="p15860122713332"><a name="p15860122713332"></a><a name="p15860122713332"></a>callback</p>
    </td>
    <td class="cellrowborder" valign="top" width="12.629999999999999%" headers="mcps1.1.5.1.2 "><p id="p1186012753311"><a name="p1186012753311"></a><a name="p1186012753311"></a>Callback&lt;Tip&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="6.16%" headers="mcps1.1.5.1.3 "><p id="p118602275333"><a name="p118602275333"></a><a name="p118602275333"></a>No</p>
    </td>
    <td class="cellrowborder" valign="top" width="70.17999999999999%" headers="mcps1.1.5.1.4 "><p id="p18601727103313"><a name="p18601727103313"></a><a name="p18601727103313"></a>Callback used to report the event of the specified type. Currently, only the <strong id="b57354610564"><a name="b57354610564"></a><a name="b57354610564"></a>tip</strong> event is supported. If this parameter is not specified, all callbacks corresponding to <strong id="b947313614579"><a name="b947313614579"></a><a name="b947313614579"></a>type</strong> will be canceled.</p>
    </td>
    </tr>
    </tbody>
    </table>


-   Example

    ```
    let authenticator = userIAM_userAuth.getAuthenticator();
    let tipCallback = (tip)=>{
        console.info("receive tip: errorCode(" + tip.errorCode + ") code(" + tip.tipCode + ") event(" +
            tip.tipEvent + ") info(" + tip.tipInfo + ")");
    };
    // Unsubscribe from a specified callback.
    authenticator.off("tip", tipCallback);
    
    // Unsubscribe from all callbacks.
    authenticator.off("tip");
    ```


## AuthenticationResult<a name="section71321544144418"></a>

Enumerates the authentication results.

<a name="table13669434121217"></a>
<table><thead align="left"><tr id="row9669334131219"><th class="cellrowborder" valign="top" width="23.09%" id="mcps1.1.4.1.1"><p id="p111771959133"><a name="p111771959133"></a><a name="p111771959133"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="15.89%" id="mcps1.1.4.1.2"><p id="p893019504312"><a name="p893019504312"></a><a name="p893019504312"></a>Default Value</p>
</th>
<th class="cellrowborder" valign="top" width="61.019999999999996%" id="mcps1.1.4.1.3"><p id="p067013412125"><a name="p067013412125"></a><a name="p067013412125"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1670133421217"><td class="cellrowborder" valign="top" width="23.09%" headers="mcps1.1.4.1.1 "><p id="p1067063461216"><a name="p1067063461216"></a><a name="p1067063461216"></a>NO_SUPPORT</p>
</td>
<td class="cellrowborder" valign="top" width="15.89%" headers="mcps1.1.4.1.2 "><p id="p1593015514315"><a name="p1593015514315"></a><a name="p1593015514315"></a>-1</p>
</td>
<td class="cellrowborder" valign="top" width="61.019999999999996%" headers="mcps1.1.4.1.3 "><p id="p17670193413127"><a name="p17670193413127"></a><a name="p17670193413127"></a>The device does not support the current authentication mode.</p>
</td>
</tr>
<tr id="row267013412122"><td class="cellrowborder" valign="top" width="23.09%" headers="mcps1.1.4.1.1 "><p id="p17670123431218"><a name="p17670123431218"></a><a name="p17670123431218"></a>SUCCESS</p>
</td>
<td class="cellrowborder" valign="top" width="15.89%" headers="mcps1.1.4.1.2 "><p id="p79304554310"><a name="p79304554310"></a><a name="p79304554310"></a>0</p>
</td>
<td class="cellrowborder" valign="top" width="61.019999999999996%" headers="mcps1.1.4.1.3 "><p id="p10670234121217"><a name="p10670234121217"></a><a name="p10670234121217"></a>The authentication is successful.</p>
</td>
</tr>
<tr id="row1567017345126"><td class="cellrowborder" valign="top" width="23.09%" headers="mcps1.1.4.1.1 "><p id="p9670734131216"><a name="p9670734131216"></a><a name="p9670734131216"></a>COMPARE_FAILURE</p>
</td>
<td class="cellrowborder" valign="top" width="15.89%" headers="mcps1.1.4.1.2 "><p id="p1493011512434"><a name="p1493011512434"></a><a name="p1493011512434"></a>1</p>
</td>
<td class="cellrowborder" valign="top" width="61.019999999999996%" headers="mcps1.1.4.1.3 "><p id="p567043413124"><a name="p567043413124"></a><a name="p567043413124"></a>The feature comparison failed.</p>
</td>
</tr>
<tr id="row5211123611311"><td class="cellrowborder" valign="top" width="23.09%" headers="mcps1.1.4.1.1 "><p id="p10211536171317"><a name="p10211536171317"></a><a name="p10211536171317"></a>CANCELED</p>
</td>
<td class="cellrowborder" valign="top" width="15.89%" headers="mcps1.1.4.1.2 "><p id="p139315554317"><a name="p139315554317"></a><a name="p139315554317"></a>2</p>
</td>
<td class="cellrowborder" valign="top" width="61.019999999999996%" headers="mcps1.1.4.1.3 "><p id="p15211163612131"><a name="p15211163612131"></a><a name="p15211163612131"></a>The user cancels the authentication.</p>
</td>
</tr>
<tr id="row123711738191311"><td class="cellrowborder" valign="top" width="23.09%" headers="mcps1.1.4.1.1 "><p id="p13715382131"><a name="p13715382131"></a><a name="p13715382131"></a>TIMEOUT</p>
</td>
<td class="cellrowborder" valign="top" width="15.89%" headers="mcps1.1.4.1.2 "><p id="p169315544317"><a name="p169315544317"></a><a name="p169315544317"></a>3</p>
</td>
<td class="cellrowborder" valign="top" width="61.019999999999996%" headers="mcps1.1.4.1.3 "><p id="p437143871317"><a name="p437143871317"></a><a name="p437143871317"></a>The authentication has timed out.</p>
</td>
</tr>
<tr id="row1924414459133"><td class="cellrowborder" valign="top" width="23.09%" headers="mcps1.1.4.1.1 "><p id="p19244045131317"><a name="p19244045131317"></a><a name="p19244045131317"></a>CAMERA_FAIL</p>
</td>
<td class="cellrowborder" valign="top" width="15.89%" headers="mcps1.1.4.1.2 "><p id="p2931115164317"><a name="p2931115164317"></a><a name="p2931115164317"></a>4</p>
</td>
<td class="cellrowborder" valign="top" width="61.019999999999996%" headers="mcps1.1.4.1.3 "><p id="p18244945171311"><a name="p18244945171311"></a><a name="p18244945171311"></a>The camera failed to start.</p>
</td>
</tr>
<tr id="row922984711139"><td class="cellrowborder" valign="top" width="23.09%" headers="mcps1.1.4.1.1 "><p id="p92301547171314"><a name="p92301547171314"></a><a name="p92301547171314"></a>BUSY</p>
</td>
<td class="cellrowborder" valign="top" width="15.89%" headers="mcps1.1.4.1.2 "><p id="p093119519435"><a name="p093119519435"></a><a name="p093119519435"></a>5</p>
</td>
<td class="cellrowborder" valign="top" width="61.019999999999996%" headers="mcps1.1.4.1.3 "><p id="p1523004718135"><a name="p1523004718135"></a><a name="p1523004718135"></a>The authentication service is not available. Try again later.</p>
</td>
</tr>
<tr id="row1730364931319"><td class="cellrowborder" valign="top" width="23.09%" headers="mcps1.1.4.1.1 "><p id="p163031949101319"><a name="p163031949101319"></a><a name="p163031949101319"></a>INVALID_PARAMETERS</p>
</td>
<td class="cellrowborder" valign="top" width="15.89%" headers="mcps1.1.4.1.2 "><p id="p139316510439"><a name="p139316510439"></a><a name="p139316510439"></a>6</p>
</td>
<td class="cellrowborder" valign="top" width="61.019999999999996%" headers="mcps1.1.4.1.3 "><p id="p13303149131314"><a name="p13303149131314"></a><a name="p13303149131314"></a>The authentication parameters are invalid.</p>
</td>
</tr>
<tr id="row1064113515137"><td class="cellrowborder" valign="top" width="23.09%" headers="mcps1.1.4.1.1 "><p id="p364215513139"><a name="p364215513139"></a><a name="p364215513139"></a>LOCKED</p>
</td>
<td class="cellrowborder" valign="top" width="15.89%" headers="mcps1.1.4.1.2 "><p id="p6931115134311"><a name="p6931115134311"></a><a name="p6931115134311"></a>7</p>
</td>
<td class="cellrowborder" valign="top" width="61.019999999999996%" headers="mcps1.1.4.1.3 "><p id="p4642175118131"><a name="p4642175118131"></a><a name="p4642175118131"></a>The user account is locked because the number of authentication failures has reached the threshold.</p>
</td>
</tr>
<tr id="row092092618146"><td class="cellrowborder" valign="top" width="23.09%" headers="mcps1.1.4.1.1 "><p id="p1392032601417"><a name="p1392032601417"></a><a name="p1392032601417"></a>NOT_ENROLLED</p>
</td>
<td class="cellrowborder" valign="top" width="15.89%" headers="mcps1.1.4.1.2 "><p id="p1393135134314"><a name="p1393135134314"></a><a name="p1393135134314"></a>8</p>
</td>
<td class="cellrowborder" valign="top" width="61.019999999999996%" headers="mcps1.1.4.1.3 "><p id="p1492013267149"><a name="p1492013267149"></a><a name="p1492013267149"></a>No authentication credential is registered.</p>
</td>
</tr>
<tr id="row1243382981414"><td class="cellrowborder" valign="top" width="23.09%" headers="mcps1.1.4.1.1 "><p id="p943312931411"><a name="p943312931411"></a><a name="p943312931411"></a>GENERAL_ERROR</p>
</td>
<td class="cellrowborder" valign="top" width="15.89%" headers="mcps1.1.4.1.2 "><p id="p693105124317"><a name="p693105124317"></a><a name="p693105124317"></a>100</p>
</td>
<td class="cellrowborder" valign="top" width="61.019999999999996%" headers="mcps1.1.4.1.3 "><p id="p1443311292143"><a name="p1443311292143"></a><a name="p1443311292143"></a>Other errors.</p>
</td>
</tr>
</tbody>
</table>

## Tip<sup>7+</sup><a name="section1715119258316"></a>

Defines the object of the tip generated during the authentication process.

<a name="table0103172561814"></a>
<table><thead align="left"><tr id="row12103152513185"><th class="cellrowborder" valign="top" width="17.931793179317932%" id="mcps1.1.5.1.1"><p id="p1610322561817"><a name="p1610322561817"></a><a name="p1610322561817"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="12.271227122712272%" id="mcps1.1.5.1.2"><p id="p20103132551816"><a name="p20103132551816"></a><a name="p20103132551816"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="10.551055105510551%" id="mcps1.1.5.1.3"><p id="p1103172518188"><a name="p1103172518188"></a><a name="p1103172518188"></a>Mandatory</p>
</th>
<th class="cellrowborder" valign="top" width="59.245924592459254%" id="mcps1.1.5.1.4"><p id="p19103125141812"><a name="p19103125141812"></a><a name="p19103125141812"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row201031125101812"><td class="cellrowborder" valign="top" width="17.931793179317932%" headers="mcps1.1.5.1.1 "><p id="p293518218251"><a name="p293518218251"></a><a name="p293518218251"></a>errorCode</p>
</td>
<td class="cellrowborder" valign="top" width="12.271227122712272%" headers="mcps1.1.5.1.2 "><p id="p39351925253"><a name="p39351925253"></a><a name="p39351925253"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="10.551055105510551%" headers="mcps1.1.5.1.3 "><p id="p8935162182512"><a name="p8935162182512"></a><a name="p8935162182512"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="59.245924592459254%" headers="mcps1.1.5.1.4 "><p id="p109351224253"><a name="p109351224253"></a><a name="p109351224253"></a>Whether the tip is obtained successfully. For details, see <a href="#section593513424528">Result</a>.</p>
</td>
</tr>
<tr id="row750201314232"><td class="cellrowborder" valign="top" width="17.931793179317932%" headers="mcps1.1.5.1.1 "><p id="p5501413112313"><a name="p5501413112313"></a><a name="p5501413112313"></a>tipEvent</p>
</td>
<td class="cellrowborder" valign="top" width="12.271227122712272%" headers="mcps1.1.5.1.2 "><p id="p7501313142310"><a name="p7501313142310"></a><a name="p7501313142310"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="10.551055105510551%" headers="mcps1.1.5.1.3 "><p id="p550141313239"><a name="p550141313239"></a><a name="p550141313239"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="59.245924592459254%" headers="mcps1.1.5.1.4 "><p id="p750191318235"><a name="p750191318235"></a><a name="p750191318235"></a>Tip event. For details, see <a href="#section1153812013016">TipEvent</a>. Currently, only <strong id="b395253613581"><a name="b395253613581"></a><a name="b395253613581"></a>RESULT</strong> and <strong id="b463344015819"><a name="b463344015819"></a><a name="b463344015819"></a>ACQUIRE</strong> are supported.</p>
</td>
</tr>
<tr id="row15961154932110"><td class="cellrowborder" valign="top" width="17.931793179317932%" headers="mcps1.1.5.1.1 "><p id="p7961849132118"><a name="p7961849132118"></a><a name="p7961849132118"></a>tipCode</p>
</td>
<td class="cellrowborder" valign="top" width="12.271227122712272%" headers="mcps1.1.5.1.2 "><p id="p696174992115"><a name="p696174992115"></a><a name="p696174992115"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="10.551055105510551%" headers="mcps1.1.5.1.3 "><p id="p179611349202119"><a name="p179611349202119"></a><a name="p179611349202119"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="59.245924592459254%" headers="mcps1.1.5.1.4 "><p id="p1268332205"><a name="p1268332205"></a><a name="p1268332205"></a>Tip code.</p>
<a name="ul27904101853"></a><a name="ul27904101853"></a><ul id="ul27904101853"><li>If <strong id="b274502255918"><a name="b274502255918"></a><a name="b274502255918"></a>tipEvent</strong> is <strong id="b861743319598"><a name="b861743319598"></a><a name="b861743319598"></a>RESULT</strong>, the tip code provides the authentication result. For details, see <a href="#section71321544144418">AuthenticationResult</a>.</li><li>If <strong id="b3416111616017"><a name="b3416111616017"></a><a name="b3416111616017"></a>tipEvent</strong> is <strong id="b3305420604"><a name="b3305420604"></a><a name="b3305420604"></a>ACQUIRE</strong>, the tip code provides prompt information. For details, see <a href="#section169263103510">TipCode</a>.</li></ul>
</td>
</tr>
<tr id="row1123617362210"><td class="cellrowborder" valign="top" width="17.931793179317932%" headers="mcps1.1.5.1.1 "><p id="p11236133152211"><a name="p11236133152211"></a><a name="p11236133152211"></a>tipInfo</p>
</td>
<td class="cellrowborder" valign="top" width="12.271227122712272%" headers="mcps1.1.5.1.2 "><p id="p162361038223"><a name="p162361038223"></a><a name="p162361038223"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="10.551055105510551%" headers="mcps1.1.5.1.3 "><p id="p423616312211"><a name="p423616312211"></a><a name="p423616312211"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="59.245924592459254%" headers="mcps1.1.5.1.4 "><p id="p423623152215"><a name="p423623152215"></a><a name="p423623152215"></a>Description of the tip code.</p>
</td>
</tr>
</tbody>
</table>

## Result<sup>7+</sup><a name="section593513424528"></a>

Enumerates the operation results.

<a name="table126611263545"></a>
<table><thead align="left"><tr id="row726616267548"><th class="cellrowborder" valign="top" width="23.09%" id="mcps1.1.4.1.1"><p id="p72661226165420"><a name="p72661226165420"></a><a name="p72661226165420"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="15.89%" id="mcps1.1.4.1.2"><p id="p326652695417"><a name="p326652695417"></a><a name="p326652695417"></a>Default Value</p>
</th>
<th class="cellrowborder" valign="top" width="61.019999999999996%" id="mcps1.1.4.1.3"><p id="p826652645415"><a name="p826652645415"></a><a name="p826652645415"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row182661626155417"><td class="cellrowborder" valign="top" width="23.09%" headers="mcps1.1.4.1.1 "><p id="p26197342545"><a name="p26197342545"></a><a name="p26197342545"></a>SUCCESS</p>
</td>
<td class="cellrowborder" valign="top" width="15.89%" headers="mcps1.1.4.1.2 "><p id="p132668261547"><a name="p132668261547"></a><a name="p132668261547"></a>0</p>
</td>
<td class="cellrowborder" valign="top" width="61.019999999999996%" headers="mcps1.1.4.1.3 "><p id="p1826612266546"><a name="p1826612266546"></a><a name="p1826612266546"></a>Successful</p>
</td>
</tr>
<tr id="row72661264545"><td class="cellrowborder" valign="top" width="23.09%" headers="mcps1.1.4.1.1 "><p id="p6266142695411"><a name="p6266142695411"></a><a name="p6266142695411"></a>FAILED</p>
</td>
<td class="cellrowborder" valign="top" width="15.89%" headers="mcps1.1.4.1.2 "><p id="p0266226125416"><a name="p0266226125416"></a><a name="p0266226125416"></a>1</p>
</td>
<td class="cellrowborder" valign="top" width="61.019999999999996%" headers="mcps1.1.4.1.3 "><p id="p1926732665417"><a name="p1926732665417"></a><a name="p1926732665417"></a>Failed</p>
</td>
</tr>
</tbody>
</table>

## CheckAvailabilityResult<sup>7+</sup><a name="section856311913566"></a>

Enumerates the device authentication capability check results.

<a name="table14378506576"></a>
<table><thead align="left"><tr id="row2037840155712"><th class="cellrowborder" valign="top" width="26.450000000000003%" id="mcps1.1.4.1.1"><p id="p9378130165713"><a name="p9378130165713"></a><a name="p9378130165713"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="12.53%" id="mcps1.1.4.1.2"><p id="p33782085717"><a name="p33782085717"></a><a name="p33782085717"></a>Default Value</p>
</th>
<th class="cellrowborder" valign="top" width="61.019999999999996%" id="mcps1.1.4.1.3"><p id="p63789055712"><a name="p63789055712"></a><a name="p63789055712"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row163789055718"><td class="cellrowborder" valign="top" width="26.450000000000003%" headers="mcps1.1.4.1.1 "><p id="p1037815085719"><a name="p1037815085719"></a><a name="p1037815085719"></a>SUPPORTED</p>
</td>
<td class="cellrowborder" valign="top" width="12.53%" headers="mcps1.1.4.1.2 "><p id="p537813025717"><a name="p537813025717"></a><a name="p537813025717"></a>0</p>
</td>
<td class="cellrowborder" valign="top" width="61.019999999999996%" headers="mcps1.1.4.1.3 "><p id="p1437811075710"><a name="p1437811075710"></a><a name="p1437811075710"></a>The device supports the specified authentication type and security level.</p>
</td>
</tr>
<tr id="row53788019573"><td class="cellrowborder" valign="top" width="26.450000000000003%" headers="mcps1.1.4.1.1 "><p id="p15378150165711"><a name="p15378150165711"></a><a name="p15378150165711"></a>AUTH_TYPE_NOT_SUPPORT</p>
</td>
<td class="cellrowborder" valign="top" width="12.53%" headers="mcps1.1.4.1.2 "><p id="p133788015720"><a name="p133788015720"></a><a name="p133788015720"></a>1</p>
</td>
<td class="cellrowborder" valign="top" width="61.019999999999996%" headers="mcps1.1.4.1.3 "><p id="p1137840205720"><a name="p1137840205720"></a><a name="p1137840205720"></a>The device does not support the specified authentication type.</p>
</td>
</tr>
<tr id="row1037819010575"><td class="cellrowborder" valign="top" width="26.450000000000003%" headers="mcps1.1.4.1.1 "><p id="p20378104577"><a name="p20378104577"></a><a name="p20378104577"></a>SECURE_LEVEL_NOT_SUPPORT</p>
</td>
<td class="cellrowborder" valign="top" width="12.53%" headers="mcps1.1.4.1.2 "><p id="p837814010572"><a name="p837814010572"></a><a name="p837814010572"></a>2</p>
</td>
<td class="cellrowborder" valign="top" width="61.019999999999996%" headers="mcps1.1.4.1.3 "><p id="p237840165715"><a name="p237840165715"></a><a name="p237840165715"></a>The device does not support the specified authentication security level.</p>
</td>
</tr>
<tr id="row17379140205718"><td class="cellrowborder" valign="top" width="26.450000000000003%" headers="mcps1.1.4.1.1 "><p id="p1237914015575"><a name="p1237914015575"></a><a name="p1237914015575"></a>DISTRIBUTED_AUTH_NOT_SUPPORT</p>
</td>
<td class="cellrowborder" valign="top" width="12.53%" headers="mcps1.1.4.1.2 "><p id="p15379506574"><a name="p15379506574"></a><a name="p15379506574"></a>3</p>
</td>
<td class="cellrowborder" valign="top" width="61.019999999999996%" headers="mcps1.1.4.1.3 "><p id="p937920155713"><a name="p937920155713"></a><a name="p937920155713"></a>The device does not support distributed authentication.</p>
</td>
</tr>
<tr id="row1437919065719"><td class="cellrowborder" valign="top" width="26.450000000000003%" headers="mcps1.1.4.1.1 "><p id="p155941319115819"><a name="p155941319115819"></a><a name="p155941319115819"></a>NOT_ENROLLED</p>
</td>
<td class="cellrowborder" valign="top" width="12.53%" headers="mcps1.1.4.1.2 "><p id="p15379160115716"><a name="p15379160115716"></a><a name="p15379160115716"></a>4</p>
</td>
<td class="cellrowborder" valign="top" width="61.019999999999996%" headers="mcps1.1.4.1.3 "><p id="p237916017577"><a name="p237916017577"></a><a name="p237916017577"></a>The device does not have the authentication credential.</p>
</td>
</tr>
<tr id="row1445217195614"><td class="cellrowborder" valign="top" width="26.450000000000003%" headers="mcps1.1.4.1.1 "><p id="p6452476565"><a name="p6452476565"></a><a name="p6452476565"></a>PARAM_NUM_ERROR</p>
</td>
<td class="cellrowborder" valign="top" width="12.53%" headers="mcps1.1.4.1.2 "><p id="p44522755613"><a name="p44522755613"></a><a name="p44522755613"></a>5</p>
</td>
<td class="cellrowborder" valign="top" width="61.019999999999996%" headers="mcps1.1.4.1.3 "><p id="p24521077564"><a name="p24521077564"></a><a name="p24521077564"></a>The number of parameters is incorrect.</p>
</td>
</tr>
</tbody>
</table>

## TipEvent<sup>7+</sup><a name="section1153812013016"></a>

Enumerates the tip events occurred during the authentication process.

<a name="table1074514020"></a>
<table><thead align="left"><tr id="row97851103"><th class="cellrowborder" valign="top" width="23.09%" id="mcps1.1.4.1.1"><p id="p57125111015"><a name="p57125111015"></a><a name="p57125111015"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="15.89%" id="mcps1.1.4.1.2"><p id="p18719511508"><a name="p18719511508"></a><a name="p18719511508"></a>Default Value</p>
</th>
<th class="cellrowborder" valign="top" width="61.019999999999996%" id="mcps1.1.4.1.3"><p id="p10795114016"><a name="p10795114016"></a><a name="p10795114016"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row187851708"><td class="cellrowborder" valign="top" width="23.09%" headers="mcps1.1.4.1.1 "><p id="p1691615491829"><a name="p1691615491829"></a><a name="p1691615491829"></a>RESULT</p>
</td>
<td class="cellrowborder" valign="top" width="15.89%" headers="mcps1.1.4.1.2 "><p id="p2076914171447"><a name="p2076914171447"></a><a name="p2076914171447"></a>1</p>
</td>
<td class="cellrowborder" valign="top" width="61.019999999999996%" headers="mcps1.1.4.1.3 "><p id="p8786917340"><a name="p8786917340"></a><a name="p8786917340"></a>Credential enrollment result or authentication result.</p>
</td>
</tr>
<tr id="row107135117020"><td class="cellrowborder" valign="top" width="23.09%" headers="mcps1.1.4.1.1 "><p id="p47105111011"><a name="p47105111011"></a><a name="p47105111011"></a>CANCEL</p>
</td>
<td class="cellrowborder" valign="top" width="15.89%" headers="mcps1.1.4.1.2 "><p id="p4812516016"><a name="p4812516016"></a><a name="p4812516016"></a>2</p>
</td>
<td class="cellrowborder" valign="top" width="61.019999999999996%" headers="mcps1.1.4.1.3 "><p id="p168115111016"><a name="p168115111016"></a><a name="p168115111016"></a>Credential enrollment or authentication canceled.</p>
</td>
</tr>
<tr id="row17825117010"><td class="cellrowborder" valign="top" width="23.09%" headers="mcps1.1.4.1.1 "><p id="p12815119016"><a name="p12815119016"></a><a name="p12815119016"></a>ACQUIRE</p>
</td>
<td class="cellrowborder" valign="top" width="15.89%" headers="mcps1.1.4.1.2 "><p id="p5812517010"><a name="p5812517010"></a><a name="p5812517010"></a>3</p>
</td>
<td class="cellrowborder" valign="top" width="61.019999999999996%" headers="mcps1.1.4.1.3 "><p id="p11818511209"><a name="p11818511209"></a><a name="p11818511209"></a>Tips generated in the credential enrollment or authentication process.</p>
</td>
</tr>
<tr id="row198951101"><td class="cellrowborder" valign="top" width="23.09%" headers="mcps1.1.4.1.1 "><p id="p13813511703"><a name="p13813511703"></a><a name="p13813511703"></a>BUSY</p>
</td>
<td class="cellrowborder" valign="top" width="15.89%" headers="mcps1.1.4.1.2 "><p id="p10818519013"><a name="p10818519013"></a><a name="p10818519013"></a>4</p>
</td>
<td class="cellrowborder" valign="top" width="61.019999999999996%" headers="mcps1.1.4.1.3 "><p id="p681251500"><a name="p681251500"></a><a name="p681251500"></a>Credential enrollment or authentication unavailable.</p>
</td>
</tr>
<tr id="row1981951706"><td class="cellrowborder" valign="top" width="23.09%" headers="mcps1.1.4.1.1 "><p id="p3813511202"><a name="p3813511202"></a><a name="p3813511202"></a>OUT_OF_MEM</p>
</td>
<td class="cellrowborder" valign="top" width="15.89%" headers="mcps1.1.4.1.2 "><p id="p1381751606"><a name="p1381751606"></a><a name="p1381751606"></a>5</p>
</td>
<td class="cellrowborder" valign="top" width="61.019999999999996%" headers="mcps1.1.4.1.3 "><p id="p885510011"><a name="p885510011"></a><a name="p885510011"></a>Insufficient memory.</p>
</td>
</tr>
<tr id="row15812511403"><td class="cellrowborder" valign="top" width="23.09%" headers="mcps1.1.4.1.1 "><p id="p861612371530"><a name="p861612371530"></a><a name="p861612371530"></a>FACE_ID</p>
</td>
<td class="cellrowborder" valign="top" width="15.89%" headers="mcps1.1.4.1.2 "><p id="p17835114015"><a name="p17835114015"></a><a name="p17835114015"></a>6</p>
</td>
<td class="cellrowborder" valign="top" width="61.019999999999996%" headers="mcps1.1.4.1.3 "><p id="p14819518014"><a name="p14819518014"></a><a name="p14819518014"></a>Index of a face authentication credential.</p>
</td>
</tr>
</tbody>
</table>

## TipCode<sup>7+</sup><a name="section169263103510"></a>

Enumerates the tip codes generated during the authentication process.

<a name="table24611051858"></a>
<table><thead align="left"><tr id="row2046110515515"><th class="cellrowborder" valign="top" width="27.229999999999997%" id="mcps1.1.4.1.1"><p id="p146116515516"><a name="p146116515516"></a><a name="p146116515516"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="11.75%" id="mcps1.1.4.1.2"><p id="p1046195114511"><a name="p1046195114511"></a><a name="p1046195114511"></a>Default Value</p>
</th>
<th class="cellrowborder" valign="top" width="61.019999999999996%" id="mcps1.1.4.1.3"><p id="p646115119514"><a name="p646115119514"></a><a name="p646115119514"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1446125112511"><td class="cellrowborder" valign="top" width="27.229999999999997%" headers="mcps1.1.4.1.1 "><p id="p1646115116510"><a name="p1646115116510"></a><a name="p1646115116510"></a>FACE_AUTH_TIP_TOO_BRIGHT</p>
</td>
<td class="cellrowborder" valign="top" width="11.75%" headers="mcps1.1.4.1.2 "><p id="p1446116511154"><a name="p1446116511154"></a><a name="p1446116511154"></a>1</p>
</td>
<td class="cellrowborder" valign="top" width="61.019999999999996%" headers="mcps1.1.4.1.3 "><p id="p1946219513511"><a name="p1946219513511"></a><a name="p1946219513511"></a>The obtained facial image is too bright due to high illumination.</p>
</td>
</tr>
<tr id="row18462151455"><td class="cellrowborder" valign="top" width="27.229999999999997%" headers="mcps1.1.4.1.1 "><p id="p0880125468"><a name="p0880125468"></a><a name="p0880125468"></a>FACE_AUTH_TIP_TOO_DARK</p>
</td>
<td class="cellrowborder" valign="top" width="11.75%" headers="mcps1.1.4.1.2 "><p id="p046211517513"><a name="p046211517513"></a><a name="p046211517513"></a>2</p>
</td>
<td class="cellrowborder" valign="top" width="61.019999999999996%" headers="mcps1.1.4.1.3 "><p id="p204622513511"><a name="p204622513511"></a><a name="p204622513511"></a>The obtained facial image is too dark due to low illumination.</p>
</td>
</tr>
<tr id="row5462145110515"><td class="cellrowborder" valign="top" width="27.229999999999997%" headers="mcps1.1.4.1.1 "><p id="p1462051155"><a name="p1462051155"></a><a name="p1462051155"></a>FACE_AUTH_TIP_TOO_CLOSE</p>
</td>
<td class="cellrowborder" valign="top" width="11.75%" headers="mcps1.1.4.1.2 "><p id="p144621851453"><a name="p144621851453"></a><a name="p144621851453"></a>3</p>
</td>
<td class="cellrowborder" valign="top" width="61.019999999999996%" headers="mcps1.1.4.1.3 "><p id="p17462135114510"><a name="p17462135114510"></a><a name="p17462135114510"></a>The face is too close to the device.</p>
</td>
</tr>
<tr id="row346211514519"><td class="cellrowborder" valign="top" width="27.229999999999997%" headers="mcps1.1.4.1.1 "><p id="p114620510512"><a name="p114620510512"></a><a name="p114620510512"></a>FACE_AUTH_TIP_TOO_FAR</p>
</td>
<td class="cellrowborder" valign="top" width="11.75%" headers="mcps1.1.4.1.2 "><p id="p44629518511"><a name="p44629518511"></a><a name="p44629518511"></a>4</p>
</td>
<td class="cellrowborder" valign="top" width="61.019999999999996%" headers="mcps1.1.4.1.3 "><p id="p046255119510"><a name="p046255119510"></a><a name="p046255119510"></a>The face is too far away from the device.</p>
</td>
</tr>
<tr id="row1946216511254"><td class="cellrowborder" valign="top" width="27.229999999999997%" headers="mcps1.1.4.1.1 "><p id="p346265119520"><a name="p346265119520"></a><a name="p346265119520"></a>FACE_AUTH_TIP_TOO_HIGH</p>
</td>
<td class="cellrowborder" valign="top" width="11.75%" headers="mcps1.1.4.1.2 "><p id="p04621651955"><a name="p04621651955"></a><a name="p04621651955"></a>5</p>
</td>
<td class="cellrowborder" valign="top" width="61.019999999999996%" headers="mcps1.1.4.1.3 "><p id="p3462751456"><a name="p3462751456"></a><a name="p3462751456"></a>Only the upper part of the face is captured because the device is angled too high.</p>
</td>
</tr>
<tr id="row54624514512"><td class="cellrowborder" valign="top" width="27.229999999999997%" headers="mcps1.1.4.1.1 "><p id="p34625511550"><a name="p34625511550"></a><a name="p34625511550"></a>FACE_AUTH_TIP_TOO_LOW</p>
</td>
<td class="cellrowborder" valign="top" width="11.75%" headers="mcps1.1.4.1.2 "><p id="p1446275112519"><a name="p1446275112519"></a><a name="p1446275112519"></a>6</p>
</td>
<td class="cellrowborder" valign="top" width="61.019999999999996%" headers="mcps1.1.4.1.3 "><p id="p1046235115511"><a name="p1046235115511"></a><a name="p1046235115511"></a>Only the lower part of the face is captured because the device is angled too low.</p>
</td>
</tr>
<tr id="row446255116519"><td class="cellrowborder" valign="top" width="27.229999999999997%" headers="mcps1.1.4.1.1 "><p id="p1746220511855"><a name="p1746220511855"></a><a name="p1746220511855"></a>FACE_AUTH_TIP_TOO_RIGHT</p>
</td>
<td class="cellrowborder" valign="top" width="11.75%" headers="mcps1.1.4.1.2 "><p id="p6462125113516"><a name="p6462125113516"></a><a name="p6462125113516"></a>7</p>
</td>
<td class="cellrowborder" valign="top" width="61.019999999999996%" headers="mcps1.1.4.1.3 "><p id="p146213517514"><a name="p146213517514"></a><a name="p146213517514"></a>Only the right part of the face is captured because the device is deviated to the right.</p>
</td>
</tr>
<tr id="row446265118516"><td class="cellrowborder" valign="top" width="27.229999999999997%" headers="mcps1.1.4.1.1 "><p id="p16462185120517"><a name="p16462185120517"></a><a name="p16462185120517"></a>FACE_AUTH_TIP_TOO_LEFT</p>
</td>
<td class="cellrowborder" valign="top" width="11.75%" headers="mcps1.1.4.1.2 "><p id="p6462165110513"><a name="p6462165110513"></a><a name="p6462165110513"></a>8</p>
</td>
<td class="cellrowborder" valign="top" width="61.019999999999996%" headers="mcps1.1.4.1.3 "><p id="p846317510516"><a name="p846317510516"></a><a name="p846317510516"></a>Only the left part of the face is captured because the device is deviated to the left.</p>
</td>
</tr>
<tr id="row19463251155"><td class="cellrowborder" valign="top" width="27.229999999999997%" headers="mcps1.1.4.1.1 "><p id="p1446318511355"><a name="p1446318511355"></a><a name="p1446318511355"></a>FACE_AUTH_TIP_TOO_MUCH_MOTION</p>
</td>
<td class="cellrowborder" valign="top" width="11.75%" headers="mcps1.1.4.1.2 "><p id="p84638511759"><a name="p84638511759"></a><a name="p84638511759"></a>9</p>
</td>
<td class="cellrowborder" valign="top" width="61.019999999999996%" headers="mcps1.1.4.1.3 "><p id="p24631551257"><a name="p24631551257"></a><a name="p24631551257"></a>The face moves too fast during facial information collection.</p>
</td>
</tr>
<tr id="row194635511653"><td class="cellrowborder" valign="top" width="27.229999999999997%" headers="mcps1.1.4.1.1 "><p id="p146325120512"><a name="p146325120512"></a><a name="p146325120512"></a>FACE_AUTH_TIP_POOR_GAZE</p>
</td>
<td class="cellrowborder" valign="top" width="11.75%" headers="mcps1.1.4.1.2 "><p id="p746316511514"><a name="p746316511514"></a><a name="p746316511514"></a>10</p>
</td>
<td class="cellrowborder" valign="top" width="61.019999999999996%" headers="mcps1.1.4.1.3 "><p id="p746315511457"><a name="p746315511457"></a><a name="p746315511457"></a>The face is not facing the camera.</p>
</td>
</tr>
<tr id="row1746315110519"><td class="cellrowborder" valign="top" width="27.229999999999997%" headers="mcps1.1.4.1.1 "><p id="p64631051557"><a name="p64631051557"></a><a name="p64631051557"></a>FACE_AUTH_TIP_NOT_DETECTED</p>
</td>
<td class="cellrowborder" valign="top" width="11.75%" headers="mcps1.1.4.1.2 "><p id="p15463155112519"><a name="p15463155112519"></a><a name="p15463155112519"></a>11</p>
</td>
<td class="cellrowborder" valign="top" width="61.019999999999996%" headers="mcps1.1.4.1.3 "><p id="p1446319511451"><a name="p1446319511451"></a><a name="p1446319511451"></a>No face is detected.</p>
</td>
</tr>
</tbody>
</table>

