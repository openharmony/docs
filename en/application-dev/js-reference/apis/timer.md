# Timer<a name="EN-US_TOPIC_0000001115814848"></a>

-   [Module to Import](#en-us_topic_0000001058562847_section7480141454919)
-   [Permission List](#en-us_topic_0000001058562847_section11257113618419)
-   [setTimeout\(handler\[, delay\[, ...args\]\]\)](#en-us_topic_0000001058562847_section691616559215)
-   [clearTimeout\(timeoutID\)](#en-us_topic_0000001058562847_section591824471012)
-   [setInterval\(handler\[, delay\[, ...args\]\]\)](#en-us_topic_0000001058562847_section3644185910144)
-   [clearInterval\(intervalID\)](#en-us_topic_0000001058562847_section16451595149)

## Module to Import<a name="en-us_topic_0000001058562847_section7480141454919"></a>

None

## Permission List<a name="en-us_topic_0000001058562847_section11257113618419"></a>

None

## setTimeout\(handler\[, delay\[, ...args\]\]\)<a name="en-us_topic_0000001058562847_section691616559215"></a>

Sets a timer for the system to call a function after the timer goes off.

-   Parameters

    <a name="en-us_topic_0000001058562847_t80f094cffa594e7e842eccce3bf1eb19"></a>
    <table><thead align="left"><tr id="en-us_topic_0000001058562847_rd6c76d49b85e4aea9496fd457b189a2a"><th class="cellrowborder" valign="top" width="14.180000000000001%" id="mcps1.1.5.1.1"><p id="en-us_topic_0000001058562847_aca3ed031fef246189779018bbcab4df3"><a name="en-us_topic_0000001058562847_aca3ed031fef246189779018bbcab4df3"></a><a name="en-us_topic_0000001058562847_aca3ed031fef246189779018bbcab4df3"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="16.61%" id="mcps1.1.5.1.2"><p id="en-us_topic_0000001058562847_a89f9e11cc75c4aa9b0b31af966020f61"><a name="en-us_topic_0000001058562847_a89f9e11cc75c4aa9b0b31af966020f61"></a><a name="en-us_topic_0000001058562847_a89f9e11cc75c4aa9b0b31af966020f61"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="6.3%" id="mcps1.1.5.1.3"><p id="en-us_topic_0000001058562847_a411664c3845840d4b2a6845105703f3b"><a name="en-us_topic_0000001058562847_a411664c3845840d4b2a6845105703f3b"></a><a name="en-us_topic_0000001058562847_a411664c3845840d4b2a6845105703f3b"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="62.91%" id="mcps1.1.5.1.4"><p id="en-us_topic_0000001058562847_ac962681702ac49e09c77a1270af9ecb2"><a name="en-us_topic_0000001058562847_ac962681702ac49e09c77a1270af9ecb2"></a><a name="en-us_topic_0000001058562847_ac962681702ac49e09c77a1270af9ecb2"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="en-us_topic_0000001058562847_r9d3ffb29e7e74ff4b18e0a3e3ad04925"><td class="cellrowborder" valign="top" width="14.180000000000001%" headers="mcps1.1.5.1.1 "><p id="en-us_topic_0000001058562847_p1411112320620"><a name="en-us_topic_0000001058562847_p1411112320620"></a><a name="en-us_topic_0000001058562847_p1411112320620"></a>handler</p>
    </td>
    <td class="cellrowborder" valign="top" width="16.61%" headers="mcps1.1.5.1.2 "><p id="en-us_topic_0000001058562847_p11016237618"><a name="en-us_topic_0000001058562847_p11016237618"></a><a name="en-us_topic_0000001058562847_p11016237618"></a>Function</p>
    </td>
    <td class="cellrowborder" valign="top" width="6.3%" headers="mcps1.1.5.1.3 "><p id="en-us_topic_0000001058562847_p1892231068"><a name="en-us_topic_0000001058562847_p1892231068"></a><a name="en-us_topic_0000001058562847_p1892231068"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="62.91%" headers="mcps1.1.5.1.4 "><p id="en-us_topic_0000001058562847_p788516491307"><a name="en-us_topic_0000001058562847_p788516491307"></a><a name="en-us_topic_0000001058562847_p788516491307"></a>Function to be called after the timer goes off.</p>
    </td>
    </tr>
    <tr id="en-us_topic_0000001058562847_r57344f1bd4304d548bf54ba81dbe8fa5"><td class="cellrowborder" valign="top" width="14.180000000000001%" headers="mcps1.1.5.1.1 "><p id="en-us_topic_0000001058562847_p13718237614"><a name="en-us_topic_0000001058562847_p13718237614"></a><a name="en-us_topic_0000001058562847_p13718237614"></a>delay</p>
    </td>
    <td class="cellrowborder" valign="top" width="16.61%" headers="mcps1.1.5.1.2 "><p id="en-us_topic_0000001058562847_p261239618"><a name="en-us_topic_0000001058562847_p261239618"></a><a name="en-us_topic_0000001058562847_p261239618"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="6.3%" headers="mcps1.1.5.1.3 "><p id="en-us_topic_0000001058562847_p17516231062"><a name="en-us_topic_0000001058562847_p17516231062"></a><a name="en-us_topic_0000001058562847_p17516231062"></a>No</p>
    </td>
    <td class="cellrowborder" valign="top" width="62.91%" headers="mcps1.1.5.1.4 "><p id="en-us_topic_0000001058562847_p1943234615"><a name="en-us_topic_0000001058562847_p1943234615"></a><a name="en-us_topic_0000001058562847_p1943234615"></a>Number of milliseconds delayed before the execution. If this parameter is left empty, the default value <strong id="en-us_topic_0000001058562847_b1264512254010"><a name="en-us_topic_0000001058562847_b1264512254010"></a><a name="en-us_topic_0000001058562847_b1264512254010"></a>0</strong> is used, which means that the execution starts immediately or as soon as possible.</p>
    </td>
    </tr>
    <tr id="en-us_topic_0000001058562847_r41a55619ed484b7092dfc843ebd4fba1"><td class="cellrowborder" valign="top" width="14.180000000000001%" headers="mcps1.1.5.1.1 "><p id="en-us_topic_0000001058562847_p103182316615"><a name="en-us_topic_0000001058562847_p103182316615"></a><a name="en-us_topic_0000001058562847_p103182316615"></a>...args</p>
    </td>
    <td class="cellrowborder" valign="top" width="16.61%" headers="mcps1.1.5.1.2 "><p id="en-us_topic_0000001058562847_p1321231162"><a name="en-us_topic_0000001058562847_p1321231162"></a><a name="en-us_topic_0000001058562847_p1321231162"></a>Array&lt;any&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="6.3%" headers="mcps1.1.5.1.3 "><p id="en-us_topic_0000001058562847_p11111231363"><a name="en-us_topic_0000001058562847_p11111231363"></a><a name="en-us_topic_0000001058562847_p11111231363"></a>No</p>
    </td>
    <td class="cellrowborder" valign="top" width="62.91%" headers="mcps1.1.5.1.4 "><p id="en-us_topic_0000001058562847_p139991022863"><a name="en-us_topic_0000001058562847_p139991022863"></a><a name="en-us_topic_0000001058562847_p139991022863"></a>Additional parameter to pass to the handler after the timer goes off.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Return Value

    **timeoutID**: timer ID

-   Example

    ```
    var timeoutID = setTimeout(function() {
      console.log('delay 1s');
    }, 1000);
    ```


## clearTimeout\(timeoutID\)<a name="en-us_topic_0000001058562847_section591824471012"></a>

Cancels the timer created via  **setTimeout\(\)**.

-   Parameter

    <a name="en-us_topic_0000001058562847_table242593951313"></a>
    <table><thead align="left"><tr id="en-us_topic_0000001058562847_row1642533921320"><th class="cellrowborder" valign="top" width="14.180000000000001%" id="mcps1.1.5.1.1"><p id="en-us_topic_0000001058562847_p15425539131316"><a name="en-us_topic_0000001058562847_p15425539131316"></a><a name="en-us_topic_0000001058562847_p15425539131316"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="9.700000000000001%" id="mcps1.1.5.1.2"><p id="en-us_topic_0000001058562847_p442518395136"><a name="en-us_topic_0000001058562847_p442518395136"></a><a name="en-us_topic_0000001058562847_p442518395136"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="6.18%" id="mcps1.1.5.1.3"><p id="en-us_topic_0000001058562847_p6425153915136"><a name="en-us_topic_0000001058562847_p6425153915136"></a><a name="en-us_topic_0000001058562847_p6425153915136"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="69.94%" id="mcps1.1.5.1.4"><p id="en-us_topic_0000001058562847_p9425193910134"><a name="en-us_topic_0000001058562847_p9425193910134"></a><a name="en-us_topic_0000001058562847_p9425193910134"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="en-us_topic_0000001058562847_row1442613913132"><td class="cellrowborder" valign="top" width="14.180000000000001%" headers="mcps1.1.5.1.1 "><p id="en-us_topic_0000001058562847_p16426133931310"><a name="en-us_topic_0000001058562847_p16426133931310"></a><a name="en-us_topic_0000001058562847_p16426133931310"></a>timeoutID</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.700000000000001%" headers="mcps1.1.5.1.2 "><p id="en-us_topic_0000001058562847_p16426639151316"><a name="en-us_topic_0000001058562847_p16426639151316"></a><a name="en-us_topic_0000001058562847_p16426639151316"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="6.18%" headers="mcps1.1.5.1.3 "><p id="en-us_topic_0000001058562847_p1426739141312"><a name="en-us_topic_0000001058562847_p1426739141312"></a><a name="en-us_topic_0000001058562847_p1426739141312"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="69.94%" headers="mcps1.1.5.1.4 "><p id="en-us_topic_0000001058562847_p6426183941319"><a name="en-us_topic_0000001058562847_p6426183941319"></a><a name="en-us_topic_0000001058562847_p6426183941319"></a>ID of the timer to cancel, which is returned by <strong id="en-us_topic_0000001058562847_b5804644564"><a name="en-us_topic_0000001058562847_b5804644564"></a><a name="en-us_topic_0000001058562847_b5804644564"></a>setTimeout()</strong></p>
    </td>
    </tr>
    </tbody>
    </table>

-   Example

    ```
    var timeoutID = setTimeout(function() {
      console.log('do after 1s delay.');
    }, 1000);
    
    clearTimeout(timeoutID);
    ```


## setInterval\(handler\[, delay\[, ...args\]\]\)<a name="en-us_topic_0000001058562847_section3644185910144"></a>

Sets a repeating timer for the system to repeatedly call a function at a fixed interval.

-   Parameters

    <a name="en-us_topic_0000001058562847_table2064413592143"></a>
    <table><thead align="left"><tr id="en-us_topic_0000001058562847_row16441591142"><th class="cellrowborder" valign="top" width="14.180000000000001%" id="mcps1.1.5.1.1"><p id="en-us_topic_0000001058562847_p0644195915145"><a name="en-us_topic_0000001058562847_p0644195915145"></a><a name="en-us_topic_0000001058562847_p0644195915145"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="16.61%" id="mcps1.1.5.1.2"><p id="en-us_topic_0000001058562847_p1264413594142"><a name="en-us_topic_0000001058562847_p1264413594142"></a><a name="en-us_topic_0000001058562847_p1264413594142"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="6.3%" id="mcps1.1.5.1.3"><p id="en-us_topic_0000001058562847_p86449591147"><a name="en-us_topic_0000001058562847_p86449591147"></a><a name="en-us_topic_0000001058562847_p86449591147"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="62.91%" id="mcps1.1.5.1.4"><p id="en-us_topic_0000001058562847_p16644185991417"><a name="en-us_topic_0000001058562847_p16644185991417"></a><a name="en-us_topic_0000001058562847_p16644185991417"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="en-us_topic_0000001058562847_row264495931412"><td class="cellrowborder" valign="top" width="14.180000000000001%" headers="mcps1.1.5.1.1 "><p id="en-us_topic_0000001058562847_p8644659161413"><a name="en-us_topic_0000001058562847_p8644659161413"></a><a name="en-us_topic_0000001058562847_p8644659161413"></a>handler</p>
    </td>
    <td class="cellrowborder" valign="top" width="16.61%" headers="mcps1.1.5.1.2 "><p id="en-us_topic_0000001058562847_p7645259181410"><a name="en-us_topic_0000001058562847_p7645259181410"></a><a name="en-us_topic_0000001058562847_p7645259181410"></a>Function</p>
    </td>
    <td class="cellrowborder" valign="top" width="6.3%" headers="mcps1.1.5.1.3 "><p id="en-us_topic_0000001058562847_p12645259111415"><a name="en-us_topic_0000001058562847_p12645259111415"></a><a name="en-us_topic_0000001058562847_p12645259111415"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="62.91%" headers="mcps1.1.5.1.4 "><p id="en-us_topic_0000001058562847_p4645155931418"><a name="en-us_topic_0000001058562847_p4645155931418"></a><a name="en-us_topic_0000001058562847_p4645155931418"></a>Function to be called repeatedly</p>
    </td>
    </tr>
    <tr id="en-us_topic_0000001058562847_row264575911146"><td class="cellrowborder" valign="top" width="14.180000000000001%" headers="mcps1.1.5.1.1 "><p id="en-us_topic_0000001058562847_p17645159201410"><a name="en-us_topic_0000001058562847_p17645159201410"></a><a name="en-us_topic_0000001058562847_p17645159201410"></a>delay</p>
    </td>
    <td class="cellrowborder" valign="top" width="16.61%" headers="mcps1.1.5.1.2 "><p id="en-us_topic_0000001058562847_p3645175951416"><a name="en-us_topic_0000001058562847_p3645175951416"></a><a name="en-us_topic_0000001058562847_p3645175951416"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="6.3%" headers="mcps1.1.5.1.3 "><p id="en-us_topic_0000001058562847_p1645185981412"><a name="en-us_topic_0000001058562847_p1645185981412"></a><a name="en-us_topic_0000001058562847_p1645185981412"></a>No</p>
    </td>
    <td class="cellrowborder" valign="top" width="62.91%" headers="mcps1.1.5.1.4 "><p id="en-us_topic_0000001058562847_p13645559141415"><a name="en-us_topic_0000001058562847_p13645559141415"></a><a name="en-us_topic_0000001058562847_p13645559141415"></a>Number of milliseconds delayed before the execution</p>
    </td>
    </tr>
    <tr id="en-us_topic_0000001058562847_row96452594148"><td class="cellrowborder" valign="top" width="14.180000000000001%" headers="mcps1.1.5.1.1 "><p id="en-us_topic_0000001058562847_p4645105911412"><a name="en-us_topic_0000001058562847_p4645105911412"></a><a name="en-us_topic_0000001058562847_p4645105911412"></a>...args</p>
    </td>
    <td class="cellrowborder" valign="top" width="16.61%" headers="mcps1.1.5.1.2 "><p id="en-us_topic_0000001058562847_p1564595951413"><a name="en-us_topic_0000001058562847_p1564595951413"></a><a name="en-us_topic_0000001058562847_p1564595951413"></a>Array&lt;any&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="6.3%" headers="mcps1.1.5.1.3 "><p id="en-us_topic_0000001058562847_p12645175971411"><a name="en-us_topic_0000001058562847_p12645175971411"></a><a name="en-us_topic_0000001058562847_p12645175971411"></a>No</p>
    </td>
    <td class="cellrowborder" valign="top" width="62.91%" headers="mcps1.1.5.1.4 "><p id="en-us_topic_0000001058562847_p12645105991413"><a name="en-us_topic_0000001058562847_p12645105991413"></a><a name="en-us_topic_0000001058562847_p12645105991413"></a>Additional parameter to pass to the handler after the timer goes off</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Return Value

    **intervalID**: ID of the repeating timer

-   Example

    ```
    var intervalID = setInterval(function() {
      console.log('do very 1s.');
    }, 1000);
    ```


## clearInterval\(intervalID\)<a name="en-us_topic_0000001058562847_section16451595149"></a>

Cancels the repeating timer set via  **setInterval\(\)**.

-   Parameter

    <a name="en-us_topic_0000001058562847_table86463597147"></a>
    <table><thead align="left"><tr id="en-us_topic_0000001058562847_row146462597148"><th class="cellrowborder" valign="top" width="14.180000000000001%" id="mcps1.1.5.1.1"><p id="en-us_topic_0000001058562847_p176461759111416"><a name="en-us_topic_0000001058562847_p176461759111416"></a><a name="en-us_topic_0000001058562847_p176461759111416"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="9.700000000000001%" id="mcps1.1.5.1.2"><p id="en-us_topic_0000001058562847_p8646195918141"><a name="en-us_topic_0000001058562847_p8646195918141"></a><a name="en-us_topic_0000001058562847_p8646195918141"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="6.18%" id="mcps1.1.5.1.3"><p id="en-us_topic_0000001058562847_p19646165981415"><a name="en-us_topic_0000001058562847_p19646165981415"></a><a name="en-us_topic_0000001058562847_p19646165981415"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="69.94%" id="mcps1.1.5.1.4"><p id="en-us_topic_0000001058562847_p8646185961419"><a name="en-us_topic_0000001058562847_p8646185961419"></a><a name="en-us_topic_0000001058562847_p8646185961419"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="en-us_topic_0000001058562847_row12646125914143"><td class="cellrowborder" valign="top" width="14.180000000000001%" headers="mcps1.1.5.1.1 "><p id="en-us_topic_0000001058562847_p1964675951413"><a name="en-us_topic_0000001058562847_p1964675951413"></a><a name="en-us_topic_0000001058562847_p1964675951413"></a>intervalID</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.700000000000001%" headers="mcps1.1.5.1.2 "><p id="en-us_topic_0000001058562847_p1864625921419"><a name="en-us_topic_0000001058562847_p1864625921419"></a><a name="en-us_topic_0000001058562847_p1864625921419"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="6.18%" headers="mcps1.1.5.1.3 "><p id="en-us_topic_0000001058562847_p3646145921419"><a name="en-us_topic_0000001058562847_p3646145921419"></a><a name="en-us_topic_0000001058562847_p3646145921419"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="69.94%" headers="mcps1.1.5.1.4 "><p id="en-us_topic_0000001058562847_p7646459141416"><a name="en-us_topic_0000001058562847_p7646459141416"></a><a name="en-us_topic_0000001058562847_p7646459141416"></a>ID of the repeating timer to cancel, which is returned by <strong id="en-us_topic_0000001058562847_b1855918269134"><a name="en-us_topic_0000001058562847_b1855918269134"></a><a name="en-us_topic_0000001058562847_b1855918269134"></a>setInterval()</strong>.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Example

    ```
    var intervalID = setInterval(function() {
      console.log('do very 1s.');
    }, 1000);
    
    clearInterval(intervalID);
    ```


