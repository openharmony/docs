# 定时器<a name="ZH-CN_TOPIC_0000001173324687"></a>

## 导入模块<a name="section7480141454919"></a>

无需导入。

## 权限列表<a name="section11257113618419"></a>

无

## setTimeout<a name="section691616559215"></a>

setTimeout\(handler\[,delay\[,…args\]\]\): number

设置一个定时器，该定时器在定时器到期后执行一个函数。

-   参数

    <a name="t80f094cffa594e7e842eccce3bf1eb19"></a>
    <table><thead align="left"><tr id="rd6c76d49b85e4aea9496fd457b189a2a"><th class="cellrowborder" valign="top" width="14.180000000000001%" id="mcps1.1.5.1.1"><p id="aca3ed031fef246189779018bbcab4df3"><a name="aca3ed031fef246189779018bbcab4df3"></a><a name="aca3ed031fef246189779018bbcab4df3"></a>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="16.61%" id="mcps1.1.5.1.2"><p id="a89f9e11cc75c4aa9b0b31af966020f61"><a name="a89f9e11cc75c4aa9b0b31af966020f61"></a><a name="a89f9e11cc75c4aa9b0b31af966020f61"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="6.3%" id="mcps1.1.5.1.3"><p id="a411664c3845840d4b2a6845105703f3b"><a name="a411664c3845840d4b2a6845105703f3b"></a><a name="a411664c3845840d4b2a6845105703f3b"></a>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="62.91%" id="mcps1.1.5.1.4"><p id="ac962681702ac49e09c77a1270af9ecb2"><a name="ac962681702ac49e09c77a1270af9ecb2"></a><a name="ac962681702ac49e09c77a1270af9ecb2"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="r9d3ffb29e7e74ff4b18e0a3e3ad04925"><td class="cellrowborder" valign="top" width="14.180000000000001%" headers="mcps1.1.5.1.1 "><p id="p1411112320620"><a name="p1411112320620"></a><a name="p1411112320620"></a>handler</p>
    </td>
    <td class="cellrowborder" valign="top" width="16.61%" headers="mcps1.1.5.1.2 "><p id="p11016237618"><a name="p11016237618"></a><a name="p11016237618"></a>Function</p>
    </td>
    <td class="cellrowborder" valign="top" width="6.3%" headers="mcps1.1.5.1.3 "><p id="p1892231068"><a name="p1892231068"></a><a name="p1892231068"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="62.91%" headers="mcps1.1.5.1.4 "><p id="p788516491307"><a name="p788516491307"></a><a name="p788516491307"></a>定时器到期后执行函数。</p>
    </td>
    </tr>
    <tr id="r57344f1bd4304d548bf54ba81dbe8fa5"><td class="cellrowborder" valign="top" width="14.180000000000001%" headers="mcps1.1.5.1.1 "><p id="p13718237614"><a name="p13718237614"></a><a name="p13718237614"></a>delay</p>
    </td>
    <td class="cellrowborder" valign="top" width="16.61%" headers="mcps1.1.5.1.2 "><p id="p261239618"><a name="p261239618"></a><a name="p261239618"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="6.3%" headers="mcps1.1.5.1.3 "><p id="p17516231062"><a name="p17516231062"></a><a name="p17516231062"></a>否</p>
    </td>
    <td class="cellrowborder" valign="top" width="62.91%" headers="mcps1.1.5.1.4 "><p id="p1943234615"><a name="p1943234615"></a><a name="p1943234615"></a>延迟的毫秒数，函数的调用会在该延迟之后发生。如果省略该参数，delay取默认值0，意味着“马上”执行，或尽快执行。</p>
    </td>
    </tr>
    <tr id="r41a55619ed484b7092dfc843ebd4fba1"><td class="cellrowborder" valign="top" width="14.180000000000001%" headers="mcps1.1.5.1.1 "><p id="p103182316615"><a name="p103182316615"></a><a name="p103182316615"></a>...args</p>
    </td>
    <td class="cellrowborder" valign="top" width="16.61%" headers="mcps1.1.5.1.2 "><p id="p1321231162"><a name="p1321231162"></a><a name="p1321231162"></a>Array&lt;any&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="6.3%" headers="mcps1.1.5.1.3 "><p id="p11111231363"><a name="p11111231363"></a><a name="p11111231363"></a>否</p>
    </td>
    <td class="cellrowborder" valign="top" width="62.91%" headers="mcps1.1.5.1.4 "><p id="p139991022863"><a name="p139991022863"></a><a name="p139991022863"></a>附加参数，一旦定时器到期，它们会作为参数传递给handler。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   返回值

    <a name="table1430416594311"></a>
    <table><thead align="left"><tr id="row230485973113"><th class="cellrowborder" valign="top" width="15.97%" id="mcps1.1.3.1.1"><p id="p430405913312"><a name="p430405913312"></a><a name="p430405913312"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="84.03%" id="mcps1.1.3.1.2"><p id="p830413599312"><a name="p830413599312"></a><a name="p830413599312"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row130435914317"><td class="cellrowborder" valign="top" width="15.97%" headers="mcps1.1.3.1.1 "><p id="p4305759143119"><a name="p4305759143119"></a><a name="p4305759143119"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="84.03%" headers="mcps1.1.3.1.2 "><p id="p130555923110"><a name="p130555923110"></a><a name="p130555923110"></a>timeout定时器的ID。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   示例

    ```
    export default {    
      setTimeOut() {        
        var timeoutID = setTimeout(function() {            
          console.log('delay 1s');
        }, 1000);    
      }
    }
    ```


## clearTimeout<a name="section591824471012"></a>

clearTimeout\(timeoutID: number\): void

取消了先前通过调用setTimeout\(\)建立的定时器。

-   参数

    <a name="table242593951313"></a>
    <table><thead align="left"><tr id="row1642533921320"><th class="cellrowborder" valign="top" width="14.180000000000001%" id="mcps1.1.5.1.1"><p id="p15425539131316"><a name="p15425539131316"></a><a name="p15425539131316"></a>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="9.700000000000001%" id="mcps1.1.5.1.2"><p id="p442518395136"><a name="p442518395136"></a><a name="p442518395136"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="6.18%" id="mcps1.1.5.1.3"><p id="p6425153915136"><a name="p6425153915136"></a><a name="p6425153915136"></a>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="69.94%" id="mcps1.1.5.1.4"><p id="p9425193910134"><a name="p9425193910134"></a><a name="p9425193910134"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row1442613913132"><td class="cellrowborder" valign="top" width="14.180000000000001%" headers="mcps1.1.5.1.1 "><p id="p16426133931310"><a name="p16426133931310"></a><a name="p16426133931310"></a>timeoutID</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.700000000000001%" headers="mcps1.1.5.1.2 "><p id="p16426639151316"><a name="p16426639151316"></a><a name="p16426639151316"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="6.18%" headers="mcps1.1.5.1.3 "><p id="p1426739141312"><a name="p1426739141312"></a><a name="p1426739141312"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="69.94%" headers="mcps1.1.5.1.4 "><p id="p6426183941319"><a name="p6426183941319"></a><a name="p6426183941319"></a>要取消定时器的ID， 是由setTimeout()返回的。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   示例

    ```
    export default {    
      clearTimeOut() {        
        var timeoutID = setTimeout(function() {            
          console.log('do after 1s delay.');        
        }, 1000);        
        clearTimeout(timeoutID);    
      }
    }
    ```


## setInterval<a name="section3644185910144"></a>

setInterval\(handler\[, delay\[, ...args\]\]\): number

重复调用一个函数，在每次调用之间具有固定的时间延迟。

-   参数

    <a name="table2064413592143"></a>
    <table><thead align="left"><tr id="row16441591142"><th class="cellrowborder" valign="top" width="14.180000000000001%" id="mcps1.1.5.1.1"><p id="p0644195915145"><a name="p0644195915145"></a><a name="p0644195915145"></a>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="16.61%" id="mcps1.1.5.1.2"><p id="p1264413594142"><a name="p1264413594142"></a><a name="p1264413594142"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="6.3%" id="mcps1.1.5.1.3"><p id="p86449591147"><a name="p86449591147"></a><a name="p86449591147"></a>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="62.91%" id="mcps1.1.5.1.4"><p id="p16644185991417"><a name="p16644185991417"></a><a name="p16644185991417"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row264495931412"><td class="cellrowborder" valign="top" width="14.180000000000001%" headers="mcps1.1.5.1.1 "><p id="p8644659161413"><a name="p8644659161413"></a><a name="p8644659161413"></a>handler</p>
    </td>
    <td class="cellrowborder" valign="top" width="16.61%" headers="mcps1.1.5.1.2 "><p id="p7645259181410"><a name="p7645259181410"></a><a name="p7645259181410"></a>Function</p>
    </td>
    <td class="cellrowborder" valign="top" width="6.3%" headers="mcps1.1.5.1.3 "><p id="p12645259111415"><a name="p12645259111415"></a><a name="p12645259111415"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="62.91%" headers="mcps1.1.5.1.4 "><p id="p4645155931418"><a name="p4645155931418"></a><a name="p4645155931418"></a>要重复调用的函数。</p>
    </td>
    </tr>
    <tr id="row264575911146"><td class="cellrowborder" valign="top" width="14.180000000000001%" headers="mcps1.1.5.1.1 "><p id="p17645159201410"><a name="p17645159201410"></a><a name="p17645159201410"></a>delay</p>
    </td>
    <td class="cellrowborder" valign="top" width="16.61%" headers="mcps1.1.5.1.2 "><p id="p3645175951416"><a name="p3645175951416"></a><a name="p3645175951416"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="6.3%" headers="mcps1.1.5.1.3 "><p id="p1645185981412"><a name="p1645185981412"></a><a name="p1645185981412"></a>否</p>
    </td>
    <td class="cellrowborder" valign="top" width="62.91%" headers="mcps1.1.5.1.4 "><p id="p13645559141415"><a name="p13645559141415"></a><a name="p13645559141415"></a>延迟的毫秒数（一秒等于1000毫秒），函数的调用会在该延迟之后发生。</p>
    </td>
    </tr>
    <tr id="row96452594148"><td class="cellrowborder" valign="top" width="14.180000000000001%" headers="mcps1.1.5.1.1 "><p id="p4645105911412"><a name="p4645105911412"></a><a name="p4645105911412"></a>...args</p>
    </td>
    <td class="cellrowborder" valign="top" width="16.61%" headers="mcps1.1.5.1.2 "><p id="p1564595951413"><a name="p1564595951413"></a><a name="p1564595951413"></a>Array&lt;any&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="6.3%" headers="mcps1.1.5.1.3 "><p id="p12645175971411"><a name="p12645175971411"></a><a name="p12645175971411"></a>否</p>
    </td>
    <td class="cellrowborder" valign="top" width="62.91%" headers="mcps1.1.5.1.4 "><p id="p12645105991413"><a name="p12645105991413"></a><a name="p12645105991413"></a>附加参数，一旦定时器到期，他们会作为参数传递给handler。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   返回值

    <a name="table1947971515356"></a>
    <table><thead align="left"><tr id="row247915156359"><th class="cellrowborder" valign="top" width="12.18%" id="mcps1.1.3.1.1"><p id="p54794159353"><a name="p54794159353"></a><a name="p54794159353"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="87.82%" id="mcps1.1.3.1.2"><p id="p14798156359"><a name="p14798156359"></a><a name="p14798156359"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row747919155356"><td class="cellrowborder" valign="top" width="12.18%" headers="mcps1.1.3.1.1 "><p id="p6479101518359"><a name="p6479101518359"></a><a name="p6479101518359"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="87.82%" headers="mcps1.1.3.1.2 "><p id="p10479151518353"><a name="p10479151518353"></a><a name="p10479151518353"></a>intervallID重复定时器的ID。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   示例

    ```
    export default {    
      setInterval() {        
        var intervalID = setInterval(function() {            
          console.log('do very 1s.');        
        }, 1000);    
      }
    }
    ```


## clearInterval<a name="section16451595149"></a>

clearInterval\(intervalID: number\): void

可取消先前通过 setInterval\(\) 设置的重复定时任务。

-   参数

    <a name="table86463597147"></a>
    <table><thead align="left"><tr id="row146462597148"><th class="cellrowborder" valign="top" width="14.180000000000001%" id="mcps1.1.5.1.1"><p id="p176461759111416"><a name="p176461759111416"></a><a name="p176461759111416"></a>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="9.700000000000001%" id="mcps1.1.5.1.2"><p id="p8646195918141"><a name="p8646195918141"></a><a name="p8646195918141"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="6.18%" id="mcps1.1.5.1.3"><p id="p19646165981415"><a name="p19646165981415"></a><a name="p19646165981415"></a>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="69.94%" id="mcps1.1.5.1.4"><p id="p8646185961419"><a name="p8646185961419"></a><a name="p8646185961419"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row12646125914143"><td class="cellrowborder" valign="top" width="14.180000000000001%" headers="mcps1.1.5.1.1 "><p id="p1964675951413"><a name="p1964675951413"></a><a name="p1964675951413"></a>intervalID</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.700000000000001%" headers="mcps1.1.5.1.2 "><p id="p1864625921419"><a name="p1864625921419"></a><a name="p1864625921419"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="6.18%" headers="mcps1.1.5.1.3 "><p id="p3646145921419"><a name="p3646145921419"></a><a name="p3646145921419"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="69.94%" headers="mcps1.1.5.1.4 "><p id="p7646459141416"><a name="p7646459141416"></a><a name="p7646459141416"></a>要取消的重复定时器的ID，是由 setInterval() 返回的。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   示例

    ```
    export default {    
      clearInterval() {        
        var intervalID = setInterval(function() {
          console.log('do very 1s.');
        }, 1000);
        clearInterval(intervalID);
      }
    }
    ```


