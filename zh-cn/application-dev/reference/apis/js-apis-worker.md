# 启动一个worker<a name="ZH-CN_TOPIC_0000001172830331"></a>

>![](../../public_sys-resources/icon-note.gif) **说明：** 
>从 API Version 7 开始支持。

## 导入模块<a name="s56d19203690d4782bfc74069abb6bd71"></a>

```
import worker from '@ohos.worker';
```

## 权限<a name="section11257113618419"></a>

无

## 属性<a name="section1578718135716"></a>

<a name="table17771723175716"></a>
<table><thead align="left"><tr id="row1977112237573"><th class="cellrowborder" valign="top" width="15.870000000000001%" id="mcps1.1.6.1.1"><p id="p12771142335710"><a name="p12771142335710"></a><a name="p12771142335710"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="18.19%" id="mcps1.1.6.1.2"><p id="p12771202325716"><a name="p12771202325716"></a><a name="p12771202325716"></a>参数类型</p>
</th>
<th class="cellrowborder" valign="top" width="11.64%" id="mcps1.1.6.1.3"><p id="p1577117232576"><a name="p1577117232576"></a><a name="p1577117232576"></a>可读</p>
</th>
<th class="cellrowborder" valign="top" width="10.31%" id="mcps1.1.6.1.4"><p id="p2771623185711"><a name="p2771623185711"></a><a name="p2771623185711"></a>可写</p>
</th>
<th class="cellrowborder" valign="top" width="43.99%" id="mcps1.1.6.1.5"><p id="p197711223155714"><a name="p197711223155714"></a><a name="p197711223155714"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="row877142318577"><td class="cellrowborder" valign="top" width="15.870000000000001%" headers="mcps1.1.6.1.1 "><p id="p1771192315710"><a name="p1771192315710"></a><a name="p1771192315710"></a>parentPort</p>
</td>
<td class="cellrowborder" valign="top" width="18.19%" headers="mcps1.1.6.1.2 "><p id="p396011395812"><a name="p396011395812"></a><a name="p396011395812"></a><a href="#section36872023123912">DedicatedWorkerGlobalScope</a></p>
</td>
<td class="cellrowborder" valign="top" width="11.64%" headers="mcps1.1.6.1.3 "><p id="p677122335711"><a name="p677122335711"></a><a name="p677122335711"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="10.31%" headers="mcps1.1.6.1.4 "><p id="p17719232577"><a name="p17719232577"></a><a name="p17719232577"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="43.99%" headers="mcps1.1.6.1.5 "><p id="p205212394586"><a name="p205212394586"></a><a name="p205212394586"></a>worker线程用于与宿主线程通信的对象</p>
</td>
</tr>
</tbody>
</table>

## WorkerOptions<a name="section189341937163212"></a>

worker构造函数函数的选项信息，用于为worker添加其他信息。

<a name="table728861911417"></a>
<table><thead align="left"><tr id="row62887198149"><th class="cellrowborder" valign="top" width="15.870000000000001%" id="mcps1.1.6.1.1"><p id="p928811911410"><a name="p928811911410"></a><a name="p928811911410"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="18.19%" id="mcps1.1.6.1.2"><p id="p8288191916149"><a name="p8288191916149"></a><a name="p8288191916149"></a>参数类型</p>
</th>
<th class="cellrowborder" valign="top" width="11.64%" id="mcps1.1.6.1.3"><p id="p14288131911418"><a name="p14288131911418"></a><a name="p14288131911418"></a>可读</p>
</th>
<th class="cellrowborder" valign="top" width="10.31%" id="mcps1.1.6.1.4"><p id="p1928861921411"><a name="p1928861921411"></a><a name="p1928861921411"></a>可写</p>
</th>
<th class="cellrowborder" valign="top" width="43.99%" id="mcps1.1.6.1.5"><p id="p728815191149"><a name="p728815191149"></a><a name="p728815191149"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="row528891919142"><td class="cellrowborder" valign="top" width="15.870000000000001%" headers="mcps1.1.6.1.1 "><p id="p3288191991414"><a name="p3288191991414"></a><a name="p3288191991414"></a>type</p>
</td>
<td class="cellrowborder" valign="top" width="18.19%" headers="mcps1.1.6.1.2 "><p id="p3288121901418"><a name="p3288121901418"></a><a name="p3288121901418"></a>"classic"</p>
</td>
<td class="cellrowborder" valign="top" width="11.64%" headers="mcps1.1.6.1.3 "><p id="p182881319191414"><a name="p182881319191414"></a><a name="p182881319191414"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="10.31%" headers="mcps1.1.6.1.4 "><p id="p1176125118471"><a name="p1176125118471"></a><a name="p1176125118471"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="43.99%" headers="mcps1.1.6.1.5 "><p id="p1428811192144"><a name="p1428811192144"></a><a name="p1428811192144"></a>按照指定方式执行脚本。</p>
</td>
</tr>
<tr id="row11288719111417"><td class="cellrowborder" valign="top" width="15.870000000000001%" headers="mcps1.1.6.1.1 "><p id="p10288419131415"><a name="p10288419131415"></a><a name="p10288419131415"></a>name</p>
</td>
<td class="cellrowborder" valign="top" width="18.19%" headers="mcps1.1.6.1.2 "><p id="p428914193147"><a name="p428914193147"></a><a name="p428914193147"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="11.64%" headers="mcps1.1.6.1.3 "><p id="p3289121912146"><a name="p3289121912146"></a><a name="p3289121912146"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="10.31%" headers="mcps1.1.6.1.4 "><p id="p8289319111415"><a name="p8289319111415"></a><a name="p8289319111415"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="43.99%" headers="mcps1.1.6.1.5 "><p id="p1228991915144"><a name="p1228991915144"></a><a name="p1228991915144"></a>worker的名称。</p>
</td>
</tr>
</tbody>
</table>

## Worker<a name="section182179935414"></a>

使用以下方法前，均需先构造worker实例，Worker类继承[EventTarget](#section256019311465)。

### constructor<a name="section10131143931118"></a>

constructor\(scriptURL: string, options?: WorkerOptions\)

worker构造函数。

-   参数：

    <a name="table761145571116"></a>
    <table><thead align="left"><tr id="row1961555161115"><th class="cellrowborder" valign="top" width="14.82%" id="mcps1.1.5.1.1"><p id="p9611355171115"><a name="p9611355171115"></a><a name="p9611355171115"></a>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="20.9%" id="mcps1.1.5.1.2"><p id="p661185512119"><a name="p661185512119"></a><a name="p661185512119"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="10.77%" id="mcps1.1.5.1.3"><p id="p361855171113"><a name="p361855171113"></a><a name="p361855171113"></a>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="53.510000000000005%" id="mcps1.1.5.1.4"><p id="p17611550112"><a name="p17611550112"></a><a name="p17611550112"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row1061555121112"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="p761175511117"><a name="p761175511117"></a><a name="p761175511117"></a>scriptURL</p>
    </td>
    <td class="cellrowborder" valign="top" width="20.9%" headers="mcps1.1.5.1.2 "><p id="p461155191111"><a name="p461155191111"></a><a name="p461155191111"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="10.77%" headers="mcps1.1.5.1.3 "><p id="p106165561111"><a name="p106165561111"></a><a name="p106165561111"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="53.510000000000005%" headers="mcps1.1.5.1.4 "><p id="p361655121112"><a name="p361655121112"></a><a name="p361655121112"></a>worker执行脚本的url，路径规范：若DevEco新建工程在pages同级下没有workers目录，需要新建workers目录，将脚本文件放入workers目录。</p>
    </td>
    </tr>
    <tr id="row261115517115"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="p106155541112"><a name="p106155541112"></a><a name="p106155541112"></a>options</p>
    </td>
    <td class="cellrowborder" valign="top" width="20.9%" headers="mcps1.1.5.1.2 "><p id="p186155516113"><a name="p186155516113"></a><a name="p186155516113"></a><a href="#section189341937163212">WorkerOptions</a></p>
    </td>
    <td class="cellrowborder" valign="top" width="10.77%" headers="mcps1.1.5.1.3 "><p id="p1161105511118"><a name="p1161105511118"></a><a name="p1161105511118"></a>否</p>
    </td>
    <td class="cellrowborder" valign="top" width="53.510000000000005%" headers="mcps1.1.5.1.4 "><p id="p1862255141118"><a name="p1862255141118"></a><a name="p1862255141118"></a>worker构造的选项。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   返回值：

    <a name="table362855181117"></a>
    <table><thead align="left"><tr id="row1462255191114"><th class="cellrowborder" valign="top" width="20.990000000000002%" id="mcps1.1.3.1.1"><p id="p1621355121115"><a name="p1621355121115"></a><a name="p1621355121115"></a>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="79.01%" id="mcps1.1.3.1.2"><p id="p16295571119"><a name="p16295571119"></a><a name="p16295571119"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row116275516110"><td class="cellrowborder" valign="top" width="20.990000000000002%" headers="mcps1.1.3.1.1 "><p id="p76295515112"><a name="p76295515112"></a><a name="p76295515112"></a>worker</p>
    </td>
    <td class="cellrowborder" valign="top" width="79.01%" headers="mcps1.1.3.1.2 "><p id="p362195531112"><a name="p362195531112"></a><a name="p362195531112"></a>执行Worker构造函数生成的Worker对象，失败则返回undefined。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   示例：

    ```
    import worker from '@ohos.worker';
    const worker = new worker.Worker("workers/worker.js", {name:"first worker"});
    ```


### postMessage<a name="section1410593619146"></a>

postMessage\(message: Object, options?: PostMessageOptions\): void

向worker线程发送消息，数据的传输采用结构化克隆算法。

-   参数：

    <a name="table114831131512"></a>
    <table><thead align="left"><tr id="row914851141517"><th class="cellrowborder" valign="top" width="14.82%" id="mcps1.1.5.1.1"><p id="p214819113159"><a name="p214819113159"></a><a name="p214819113159"></a>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="23.06%" id="mcps1.1.5.1.2"><p id="p1214921121519"><a name="p1214921121519"></a><a name="p1214921121519"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="10.870000000000001%" id="mcps1.1.5.1.3"><p id="p11491711141512"><a name="p11491711141512"></a><a name="p11491711141512"></a>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="51.24999999999999%" id="mcps1.1.5.1.4"><p id="p171491011171512"><a name="p171491011171512"></a><a name="p171491011171512"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row91491211131519"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="p914912115156"><a name="p914912115156"></a><a name="p914912115156"></a>message</p>
    </td>
    <td class="cellrowborder" valign="top" width="23.06%" headers="mcps1.1.5.1.2 "><p id="p1114918116154"><a name="p1114918116154"></a><a name="p1114918116154"></a>Object</p>
    </td>
    <td class="cellrowborder" valign="top" width="10.870000000000001%" headers="mcps1.1.5.1.3 "><p id="p314916118154"><a name="p314916118154"></a><a name="p314916118154"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="51.24999999999999%" headers="mcps1.1.5.1.4 "><p id="p814951171516"><a name="p814951171516"></a><a name="p814951171516"></a>发送至worker的数据。</p>
    </td>
    </tr>
    <tr id="row5149511191511"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="p161491511151511"><a name="p161491511151511"></a><a name="p161491511151511"></a>options</p>
    </td>
    <td class="cellrowborder" valign="top" width="23.06%" headers="mcps1.1.5.1.2 "><p id="p858904361718"><a name="p858904361718"></a><a name="p858904361718"></a><a href="#section176401093245">PostMessageOptions</a></p>
    </td>
    <td class="cellrowborder" valign="top" width="10.870000000000001%" headers="mcps1.1.5.1.3 "><p id="p61491811131518"><a name="p61491811131518"></a><a name="p61491811131518"></a>否</p>
    </td>
    <td class="cellrowborder" valign="top" width="51.24999999999999%" headers="mcps1.1.5.1.4 "><p id="p67490772615"><a name="p67490772615"></a><a name="p67490772615"></a>可转移对象是 ArrayBuffer 的实例对象。transferList数组中不可传入null。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   示例：

    ```
    import worker from '@ohos.worker';
    const worker = new worker.Worker("workers/worker.js");
    worker.postMessage("hello world");
    
    const worker = new worker.Worker("workers/worker.js");
    var buffer = new ArrayBuffer(8);
    worker.postMessage(buffer, [buffer]);
    ```


### on<a name="section1201327272"></a>

on\(type: string, listener: EventListener\): void

向worker添加一个事件监听。

-   参数：

    <a name="table7033219276"></a>
    <table><thead align="left"><tr id="row120143262719"><th class="cellrowborder" valign="top" width="14.82%" id="mcps1.1.5.1.1"><p id="p13115322273"><a name="p13115322273"></a><a name="p13115322273"></a>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="16.24%" id="mcps1.1.5.1.2"><p id="p911732152715"><a name="p911732152715"></a><a name="p911732152715"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="7.6499999999999995%" id="mcps1.1.5.1.3"><p id="p15183232715"><a name="p15183232715"></a><a name="p15183232715"></a>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="61.29%" id="mcps1.1.5.1.4"><p id="p181132192710"><a name="p181132192710"></a><a name="p181132192710"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row161532162715"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="p101732182712"><a name="p101732182712"></a><a name="p101732182712"></a>type</p>
    </td>
    <td class="cellrowborder" valign="top" width="16.24%" headers="mcps1.1.5.1.2 "><p id="p2115329277"><a name="p2115329277"></a><a name="p2115329277"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="7.6499999999999995%" headers="mcps1.1.5.1.3 "><p id="p17123242710"><a name="p17123242710"></a><a name="p17123242710"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="p6143272720"><a name="p6143272720"></a><a name="p6143272720"></a>监听事件的type。</p>
    </td>
    </tr>
    <tr id="row3193202715"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="p6115326275"><a name="p6115326275"></a><a name="p6115326275"></a>listener</p>
    </td>
    <td class="cellrowborder" valign="top" width="16.24%" headers="mcps1.1.5.1.2 "><p id="p171183272714"><a name="p171183272714"></a><a name="p171183272714"></a><a href="#section53411747134914">EventListener</a></p>
    </td>
    <td class="cellrowborder" valign="top" width="7.6499999999999995%" headers="mcps1.1.5.1.3 "><p id="p4183292710"><a name="p4183292710"></a><a name="p4183292710"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="p5173202714"><a name="p5173202714"></a><a name="p5173202714"></a>回调的事件。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   示例：

    ```
    import worker from '@ohos.worker';
    const worker = new worker.Worker("workers/worker.js")
    worker.on("alert", (e)=>{
        console.log("alert listener callback");
    })
    ```


### once<a name="section74391240133513"></a>

once\(type: string, listener: EventListener\): void

向worker添加一个事件监听，事件监听只执行一次便自动删除。

-   参数：

    <a name="table143916408357"></a>
    <table><thead align="left"><tr id="row16439440193511"><th class="cellrowborder" valign="top" width="14.82%" id="mcps1.1.5.1.1"><p id="p1743974013513"><a name="p1743974013513"></a><a name="p1743974013513"></a>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="16.24%" id="mcps1.1.5.1.2"><p id="p543924014354"><a name="p543924014354"></a><a name="p543924014354"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="7.6499999999999995%" id="mcps1.1.5.1.3"><p id="p0439114073513"><a name="p0439114073513"></a><a name="p0439114073513"></a>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="61.29%" id="mcps1.1.5.1.4"><p id="p34398400359"><a name="p34398400359"></a><a name="p34398400359"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row843916409354"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="p7439840163518"><a name="p7439840163518"></a><a name="p7439840163518"></a>type</p>
    </td>
    <td class="cellrowborder" valign="top" width="16.24%" headers="mcps1.1.5.1.2 "><p id="p1144044063511"><a name="p1144044063511"></a><a name="p1144044063511"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="7.6499999999999995%" headers="mcps1.1.5.1.3 "><p id="p15440194023510"><a name="p15440194023510"></a><a name="p15440194023510"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="p14401409359"><a name="p14401409359"></a><a name="p14401409359"></a>监听事件的type。</p>
    </td>
    </tr>
    <tr id="row4440040103517"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="p644034018354"><a name="p644034018354"></a><a name="p644034018354"></a>listener</p>
    </td>
    <td class="cellrowborder" valign="top" width="16.24%" headers="mcps1.1.5.1.2 "><p id="p144401640163510"><a name="p144401640163510"></a><a name="p144401640163510"></a><a href="#section53411747134914">EventListener</a></p>
    </td>
    <td class="cellrowborder" valign="top" width="7.6499999999999995%" headers="mcps1.1.5.1.3 "><p id="p44401740163511"><a name="p44401740163511"></a><a name="p44401740163511"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="p1944074073514"><a name="p1944074073514"></a><a name="p1944074073514"></a>回调的事件。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   示例：

    ```
    import worker from '@ohos.worker';
    const worker = new worker.Worker("workers/worker.js");
    worker.once("alert", (e)=>{
        console.log("alert listener callback");
    })
    ```


### off<a name="section8902182918363"></a>

off\(type: string, listener?: EventListener\): void

删除worker的事件监听。

-   参数：

    <a name="table190342913364"></a>
    <table><thead align="left"><tr id="row11903172973618"><th class="cellrowborder" valign="top" width="14.82%" id="mcps1.1.5.1.1"><p id="p1690342920362"><a name="p1690342920362"></a><a name="p1690342920362"></a>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="16.24%" id="mcps1.1.5.1.2"><p id="p1490382916367"><a name="p1490382916367"></a><a name="p1490382916367"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="7.6499999999999995%" id="mcps1.1.5.1.3"><p id="p99037299364"><a name="p99037299364"></a><a name="p99037299364"></a>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="61.29%" id="mcps1.1.5.1.4"><p id="p1690372953611"><a name="p1690372953611"></a><a name="p1690372953611"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row2090362933610"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="p1190462923619"><a name="p1190462923619"></a><a name="p1190462923619"></a>type</p>
    </td>
    <td class="cellrowborder" valign="top" width="16.24%" headers="mcps1.1.5.1.2 "><p id="p12904192913367"><a name="p12904192913367"></a><a name="p12904192913367"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="7.6499999999999995%" headers="mcps1.1.5.1.3 "><p id="p090462973617"><a name="p090462973617"></a><a name="p090462973617"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="p20904122918367"><a name="p20904122918367"></a><a name="p20904122918367"></a>需要删除事件的type。</p>
    </td>
    </tr>
    <tr id="row690452973612"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="p12904329163616"><a name="p12904329163616"></a><a name="p12904329163616"></a>listener</p>
    </td>
    <td class="cellrowborder" valign="top" width="16.24%" headers="mcps1.1.5.1.2 "><p id="p2904429173617"><a name="p2904429173617"></a><a name="p2904429173617"></a><a href="#section53411747134914">EventListener</a></p>
    </td>
    <td class="cellrowborder" valign="top" width="7.6499999999999995%" headers="mcps1.1.5.1.3 "><p id="p6904152916366"><a name="p6904152916366"></a><a name="p6904152916366"></a>否</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="p29042297361"><a name="p29042297361"></a><a name="p29042297361"></a>需要删除的回调的事件。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   示例：

    ```
    import worker from '@ohos.worker';
    const worker = new worker.Worker("workers/worker.js");
    worker.off("alert");
    ```


### terminate<a name="section17586211104214"></a>

terminate\(\): void

关闭worker线程，终止worker接收消息。

-   示例：

    ```
    import worker from '@ohos.worker';
    const worker = new worker.Worker("workers/worker.js")
    worker.terminate()
    ```


### onexit<a name="section1478913292320"></a>

onexit?: \(code: number\) =\> void

Worker对象的onexit属性表示worker退出时被调用的事件处理程序，处理程序在宿主线程中执行。

-   参数：

    <a name="table144251138562"></a>
    <table><thead align="left"><tr id="row194251138269"><th class="cellrowborder" valign="top" width="14.82%" id="mcps1.1.5.1.1"><p id="p1642515387612"><a name="p1642515387612"></a><a name="p1642515387612"></a>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="16.24%" id="mcps1.1.5.1.2"><p id="p542513381612"><a name="p542513381612"></a><a name="p542513381612"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="7.6499999999999995%" id="mcps1.1.5.1.3"><p id="p1642513812611"><a name="p1642513812611"></a><a name="p1642513812611"></a>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="61.29%" id="mcps1.1.5.1.4"><p id="p0425133812610"><a name="p0425133812610"></a><a name="p0425133812610"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row1742512381861"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="p24258382612"><a name="p24258382612"></a><a name="p24258382612"></a>code</p>
    </td>
    <td class="cellrowborder" valign="top" width="16.24%" headers="mcps1.1.5.1.2 "><p id="p174261438564"><a name="p174261438564"></a><a name="p174261438564"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="7.6499999999999995%" headers="mcps1.1.5.1.3 "><p id="p1842612383620"><a name="p1842612383620"></a><a name="p1842612383620"></a>否</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="p1242614381868"><a name="p1242614381868"></a><a name="p1242614381868"></a>worker退出的code。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   示例：

    ```
    import worker from '@ohos.worker';
    const worker = new worker.Worker("workers/worker.js")
    worker.onexit = function(e) {
        console.log("onexit")
    }
    ```


### onerror<a name="section89811422210"></a>

onerror?: \(err: ErrorEvent\) =\> void

Worker对象的onerror属性表示worker在执行过程中发生异常被调用的事件处理程序，处理程序在宿主线程中执行。

-   参数：

    <a name="table69831416228"></a>
    <table><thead align="left"><tr id="row8989145222"><th class="cellrowborder" valign="top" width="14.82%" id="mcps1.1.5.1.1"><p id="p1298181418228"><a name="p1298181418228"></a><a name="p1298181418228"></a>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="16.24%" id="mcps1.1.5.1.2"><p id="p49801492217"><a name="p49801492217"></a><a name="p49801492217"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="7.6499999999999995%" id="mcps1.1.5.1.3"><p id="p189810140222"><a name="p189810140222"></a><a name="p189810140222"></a>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="61.29%" id="mcps1.1.5.1.4"><p id="p1899131418229"><a name="p1899131418229"></a><a name="p1899131418229"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row699191413222"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="p09919145226"><a name="p09919145226"></a><a name="p09919145226"></a>err</p>
    </td>
    <td class="cellrowborder" valign="top" width="16.24%" headers="mcps1.1.5.1.2 "><p id="p1099214172218"><a name="p1099214172218"></a><a name="p1099214172218"></a><a href="#section11241623172418">ErrorEvent</a></p>
    </td>
    <td class="cellrowborder" valign="top" width="7.6499999999999995%" headers="mcps1.1.5.1.3 "><p id="p1199111442211"><a name="p1199111442211"></a><a name="p1199111442211"></a>否</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="p89991432215"><a name="p89991432215"></a><a name="p89991432215"></a>异常数据。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   示例：

    ```
    import worker from '@ohos.worker';
    const worker = new worker.Worker("workers/worker.js")
    worker.onerror = function(e) {
        console.log("onerror")
    }
    ```


### onmessage<a name="section516520044515"></a>

onmessage?: \(event: MessageEvent\) =\> void

Worker对象的onmessage属性表示宿主线程接收到来自其创建的worker通过parentPort.postMessage接口发送的消息时被调用的事件处理程序，处理程序在宿主线程中执行。

-   参数：

    <a name="table216615019451"></a>
    <table><thead align="left"><tr id="row416618034516"><th class="cellrowborder" valign="top" width="14.82%" id="mcps1.1.5.1.1"><p id="p17166180154519"><a name="p17166180154519"></a><a name="p17166180154519"></a>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="16.24%" id="mcps1.1.5.1.2"><p id="p7166605458"><a name="p7166605458"></a><a name="p7166605458"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="7.6499999999999995%" id="mcps1.1.5.1.3"><p id="p1916610174515"><a name="p1916610174515"></a><a name="p1916610174515"></a>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="61.29%" id="mcps1.1.5.1.4"><p id="p516610024519"><a name="p516610024519"></a><a name="p516610024519"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row10166407457"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="p61667010455"><a name="p61667010455"></a><a name="p61667010455"></a>event</p>
    </td>
    <td class="cellrowborder" valign="top" width="16.24%" headers="mcps1.1.5.1.2 "><p id="p4166170164515"><a name="p4166170164515"></a><a name="p4166170164515"></a><a href="#section191271455124710">MessageEvent</a></p>
    </td>
    <td class="cellrowborder" valign="top" width="7.6499999999999995%" headers="mcps1.1.5.1.3 "><p id="p016719074513"><a name="p016719074513"></a><a name="p016719074513"></a>否</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="p816770194518"><a name="p816770194518"></a><a name="p816770194518"></a>收到的worker消息数据。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   示例：

    ```
    import worker from '@ohos.worker';
    const worker = new worker.Worker("workers/worker.js")
    worker.onmessage = function(e) {
        console.log("onerror")
    }
    ```


### onmessageerror<a name="section85981145102714"></a>

onmessageerror?: \(event: MessageEvent\) =\> void

Worker对象的onmessageerror属性表示当 Worker 对象接收到一条无法被序列化的消息时被调用的事件处理程序，处理程序在宿主线程中执行。

-   参数：

    <a name="table195981745202716"></a>
    <table><thead align="left"><tr id="row2059984512271"><th class="cellrowborder" valign="top" width="14.82%" id="mcps1.1.5.1.1"><p id="p14599174562718"><a name="p14599174562718"></a><a name="p14599174562718"></a>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="16.24%" id="mcps1.1.5.1.2"><p id="p135991645152710"><a name="p135991645152710"></a><a name="p135991645152710"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="7.6499999999999995%" id="mcps1.1.5.1.3"><p id="p1159924522712"><a name="p1159924522712"></a><a name="p1159924522712"></a>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="61.29%" id="mcps1.1.5.1.4"><p id="p8599194522717"><a name="p8599194522717"></a><a name="p8599194522717"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row5599145102715"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="p45991645172719"><a name="p45991645172719"></a><a name="p45991645172719"></a>event</p>
    </td>
    <td class="cellrowborder" valign="top" width="16.24%" headers="mcps1.1.5.1.2 "><p id="p135991645122712"><a name="p135991645122712"></a><a name="p135991645122712"></a><a href="#section191271455124710">MessageEvent</a></p>
    </td>
    <td class="cellrowborder" valign="top" width="7.6499999999999995%" headers="mcps1.1.5.1.3 "><p id="p18599134519278"><a name="p18599134519278"></a><a name="p18599134519278"></a>否</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="p10600134514271"><a name="p10600134514271"></a><a name="p10600134514271"></a>异常数据。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   示例：

    ```
    import worker from '@ohos.worker';
    const worker = new worker.Worker("workers/worker.js")
    worker.onmessageerror= function(e) {
        console.log("onmessageerror")
    }
    ```


## EventTarget<a name="section256019311465"></a>

### addEventListener<a name="section16405103834511"></a>

addEventListener\(type: string, listener: EventListener\): void

向worker添加一个事件监听。

-   参数：

    <a name="table12405138134519"></a>
    <table><thead align="left"><tr id="row1040553815452"><th class="cellrowborder" valign="top" width="14.82%" id="mcps1.1.5.1.1"><p id="p1040523804519"><a name="p1040523804519"></a><a name="p1040523804519"></a>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="16.24%" id="mcps1.1.5.1.2"><p id="p740553818457"><a name="p740553818457"></a><a name="p740553818457"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="7.6499999999999995%" id="mcps1.1.5.1.3"><p id="p11405183814513"><a name="p11405183814513"></a><a name="p11405183814513"></a>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="61.29%" id="mcps1.1.5.1.4"><p id="p54066385459"><a name="p54066385459"></a><a name="p54066385459"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row94061238174510"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="p194061438164512"><a name="p194061438164512"></a><a name="p194061438164512"></a>type</p>
    </td>
    <td class="cellrowborder" valign="top" width="16.24%" headers="mcps1.1.5.1.2 "><p id="p8406163864513"><a name="p8406163864513"></a><a name="p8406163864513"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="7.6499999999999995%" headers="mcps1.1.5.1.3 "><p id="p4406173816452"><a name="p4406173816452"></a><a name="p4406173816452"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="p440603894519"><a name="p440603894519"></a><a name="p440603894519"></a>监听事件的type。</p>
    </td>
    </tr>
    <tr id="row1840693864519"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="p1140603814450"><a name="p1140603814450"></a><a name="p1140603814450"></a>listener</p>
    </td>
    <td class="cellrowborder" valign="top" width="16.24%" headers="mcps1.1.5.1.2 "><p id="p104061338184515"><a name="p104061338184515"></a><a name="p104061338184515"></a><a href="#section53411747134914">EventListener</a></p>
    </td>
    <td class="cellrowborder" valign="top" width="7.6499999999999995%" headers="mcps1.1.5.1.3 "><p id="p1040663812451"><a name="p1040663812451"></a><a name="p1040663812451"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="p19406113874515"><a name="p19406113874515"></a><a name="p19406113874515"></a>回调的事件。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   示例：

    ```
    import worker from '@ohos.worker';
    const worker = new worker.Worker("workers/worker.js")
    worker.addEventListener("alert", (e)=>{
        console.log("alert listener callback");
    })
    ```


### removeEventListener<a name="section1437219413469"></a>

removeEventListener\(type: string, callback?: EventListener\): void

删除worker的事件监听。

-   参数：

    <a name="table53725413461"></a>
    <table><thead align="left"><tr id="row837284174614"><th class="cellrowborder" valign="top" width="14.82%" id="mcps1.1.5.1.1"><p id="p1637216414614"><a name="p1637216414614"></a><a name="p1637216414614"></a>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="16.24%" id="mcps1.1.5.1.2"><p id="p1037220454619"><a name="p1037220454619"></a><a name="p1037220454619"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="7.6499999999999995%" id="mcps1.1.5.1.3"><p id="p2372547464"><a name="p2372547464"></a><a name="p2372547464"></a>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="61.29%" id="mcps1.1.5.1.4"><p id="p1937217484617"><a name="p1937217484617"></a><a name="p1937217484617"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row437224104618"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="p193735414619"><a name="p193735414619"></a><a name="p193735414619"></a>type</p>
    </td>
    <td class="cellrowborder" valign="top" width="16.24%" headers="mcps1.1.5.1.2 "><p id="p63731542468"><a name="p63731542468"></a><a name="p63731542468"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="7.6499999999999995%" headers="mcps1.1.5.1.3 "><p id="p1437320413469"><a name="p1437320413469"></a><a name="p1437320413469"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="p23739494618"><a name="p23739494618"></a><a name="p23739494618"></a>需要删除事件的type。</p>
    </td>
    </tr>
    <tr id="row8373174114617"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="p43731644464"><a name="p43731644464"></a><a name="p43731644464"></a>callback</p>
    </td>
    <td class="cellrowborder" valign="top" width="16.24%" headers="mcps1.1.5.1.2 "><p id="p1737324114614"><a name="p1737324114614"></a><a name="p1737324114614"></a><a href="#section53411747134914">EventListener</a></p>
    </td>
    <td class="cellrowborder" valign="top" width="7.6499999999999995%" headers="mcps1.1.5.1.3 "><p id="p0373243465"><a name="p0373243465"></a><a name="p0373243465"></a>否</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="p132381754719"><a name="p132381754719"></a><a name="p132381754719"></a>需要删除的回调的事件。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   示例：

    ```
    import worker from '@ohos.worker';
    const worker = new worker.Worker("workers/worker.js")
    worker.removeEventListener("alert")
    ```


### dispatchEvent<a name="section1593912134916"></a>

dispatchEvent\(event: Event\): boolean

分发定义在worker的事件。

-   参数：

    <a name="table859431224913"></a>
    <table><thead align="left"><tr id="row859451213495"><th class="cellrowborder" valign="top" width="14.82%" id="mcps1.1.5.1.1"><p id="p11594111215495"><a name="p11594111215495"></a><a name="p11594111215495"></a>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="16.24%" id="mcps1.1.5.1.2"><p id="p175946122494"><a name="p175946122494"></a><a name="p175946122494"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="7.6499999999999995%" id="mcps1.1.5.1.3"><p id="p85941912124919"><a name="p85941912124919"></a><a name="p85941912124919"></a>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="61.29%" id="mcps1.1.5.1.4"><p id="p2059551219493"><a name="p2059551219493"></a><a name="p2059551219493"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row45951812184915"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="p11595612144910"><a name="p11595612144910"></a><a name="p11595612144910"></a>event</p>
    </td>
    <td class="cellrowborder" valign="top" width="16.24%" headers="mcps1.1.5.1.2 "><p id="p17595712184913"><a name="p17595712184913"></a><a name="p17595712184913"></a><a href="#section1674694018507">Event</a></p>
    </td>
    <td class="cellrowborder" valign="top" width="7.6499999999999995%" headers="mcps1.1.5.1.3 "><p id="p20595101217490"><a name="p20595101217490"></a><a name="p20595101217490"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="p18595712144914"><a name="p18595712144914"></a><a name="p18595712144914"></a>需要分发的事件。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   返回值：

    <a name="table4536208105515"></a>
    <table><thead align="left"><tr id="row25360810551"><th class="cellrowborder" valign="top" width="20.990000000000002%" id="mcps1.1.3.1.1"><p id="p2536685552"><a name="p2536685552"></a><a name="p2536685552"></a>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="79.01%" id="mcps1.1.3.1.2"><p id="p185371287554"><a name="p185371287554"></a><a name="p185371287554"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row55371387555"><td class="cellrowborder" valign="top" width="20.990000000000002%" headers="mcps1.1.3.1.1 "><p id="p353718195511"><a name="p353718195511"></a><a name="p353718195511"></a>boolean</p>
    </td>
    <td class="cellrowborder" valign="top" width="79.01%" headers="mcps1.1.3.1.2 "><p id="p165388817555"><a name="p165388817555"></a><a name="p165388817555"></a>分发的结果，false表示分发失败。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   示例：

    ```
    import worker from '@ohos.worker';
    const worker = new worker.Worker("workers/worker.js")
    worker.dispatchEvent({type:"alert"})
    ```


### removeAllListener<a name="section1795215505533"></a>

removeAllListener\(\): void

删除worker的所有事件监听。

-   示例：

    ```
    import worker from '@ohos.worker';
    const worker = new worker.Worker("workers/worker.js")
    worker.removeAllListener({type:"alert"})
    ```


## DedicatedWorkerGlobalScope<a name="section36872023123912"></a>

worker线程用于与宿主线程通信的类，通过postMessage接口发送消息给宿主线程、close接口关闭worker线程，DedicatedWorkerGlobalScope类继承[WorkerGlobalScope](#section12882825611)。

### postMessage<a name="section1570345794013"></a>

postMessage\(message: Object, options?: PostMessageOptions\): void

worker向宿主线程发送消息。

-   参数：

    <a name="table137041557154020"></a>
    <table><thead align="left"><tr id="row97049574404"><th class="cellrowborder" valign="top" width="14.82%" id="mcps1.1.5.1.1"><p id="p0704165764012"><a name="p0704165764012"></a><a name="p0704165764012"></a>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="25.869999999999997%" id="mcps1.1.5.1.2"><p id="p1570465764014"><a name="p1570465764014"></a><a name="p1570465764014"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="9.39%" id="mcps1.1.5.1.3"><p id="p15704157104011"><a name="p15704157104011"></a><a name="p15704157104011"></a>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="49.919999999999995%" id="mcps1.1.5.1.4"><p id="p6704115794013"><a name="p6704115794013"></a><a name="p6704115794013"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row11704165784014"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="p16704357174017"><a name="p16704357174017"></a><a name="p16704357174017"></a>message</p>
    </td>
    <td class="cellrowborder" valign="top" width="25.869999999999997%" headers="mcps1.1.5.1.2 "><p id="p970435754019"><a name="p970435754019"></a><a name="p970435754019"></a>Object</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.39%" headers="mcps1.1.5.1.3 "><p id="p1670405744010"><a name="p1670405744010"></a><a name="p1670405744010"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="49.919999999999995%" headers="mcps1.1.5.1.4 "><p id="p10704457184013"><a name="p10704457184013"></a><a name="p10704457184013"></a>发送至worker的数据。</p>
    </td>
    </tr>
    <tr id="row15704957194018"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="p3705125754018"><a name="p3705125754018"></a><a name="p3705125754018"></a>options</p>
    </td>
    <td class="cellrowborder" valign="top" width="25.869999999999997%" headers="mcps1.1.5.1.2 "><p id="p19705125716402"><a name="p19705125716402"></a><a name="p19705125716402"></a><a href="#section176401093245">PostMessageOptions</a></p>
    </td>
    <td class="cellrowborder" valign="top" width="9.39%" headers="mcps1.1.5.1.3 "><p id="p1570535784016"><a name="p1570535784016"></a><a name="p1570535784016"></a>否</p>
    </td>
    <td class="cellrowborder" valign="top" width="49.919999999999995%" headers="mcps1.1.5.1.4 "><p id="p8705857154016"><a name="p8705857154016"></a><a name="p8705857154016"></a>可转移对象是ArrayBuffer的实例对象。transferList数组中不可传入null。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   示例：

    ```
    // main.js
    import worker from '@ohos.worker';
    const worker = new worker.Worker("workers/worker.js")
    worker.postMessage("hello world")
    worker.onmessage = function(e) {
        console.log("receive data from worker.js")
    }
    
    // worker.js
    import worker from "@ohos.worker";
    const parentPort = worker.parentPort;
    parentPort.onmessage = function(e){
        parentPort.postMessage("receive data from main.js")
    }
    ```


### close<a name="section849610376427"></a>

close\(\): void

关闭worker线程，终止worker接收消息。

-   示例：

    ```
    // main.js
    import worker from '@ohos.worker';
    const worker = new worker.Worker("workers/worker.js")
    
    // worker.js
    import worker from "@ohos.worker";
    const parentPort = worker.parentPort;
    parentPort.onmessage = function(e) {
        parentPort.close()
    }
    ```


### onmessage<a name="section1371121184815"></a>

onmessage?: \(event: MessageEvent\) =\> void

DedicatedWorkerGlobalScope的onmessage属性表示worker线程收到来自其宿主线程通过worker.postMessage接口发送的消息时被调用的事件处理程序，处理程序在worker线程中执行。

-   参数：

    <a name="table137182118481"></a>
    <table><thead align="left"><tr id="row4372182164815"><th class="cellrowborder" valign="top" width="14.82%" id="mcps1.1.5.1.1"><p id="p2372521144814"><a name="p2372521144814"></a><a name="p2372521144814"></a>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="16.24%" id="mcps1.1.5.1.2"><p id="p437213213483"><a name="p437213213483"></a><a name="p437213213483"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="7.6499999999999995%" id="mcps1.1.5.1.3"><p id="p15372182118484"><a name="p15372182118484"></a><a name="p15372182118484"></a>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="61.29%" id="mcps1.1.5.1.4"><p id="p1637282113484"><a name="p1637282113484"></a><a name="p1637282113484"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row103721521164820"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="p13721821124817"><a name="p13721821124817"></a><a name="p13721821124817"></a>event</p>
    </td>
    <td class="cellrowborder" valign="top" width="16.24%" headers="mcps1.1.5.1.2 "><p id="p16372172144812"><a name="p16372172144812"></a><a name="p16372172144812"></a><a href="#section191271455124710">MessageEvent</a></p>
    </td>
    <td class="cellrowborder" valign="top" width="7.6499999999999995%" headers="mcps1.1.5.1.3 "><p id="p1737232117486"><a name="p1737232117486"></a><a name="p1737232117486"></a>否</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="p6372142184820"><a name="p6372142184820"></a><a name="p6372142184820"></a>收到的worker消息数据。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   示例：

    ```
    // main.js
    import worker from '@ohos.worker';
    const worker = new worker.Worker("workers/worker.js")
    worker.postMessage("hello world")
    
    // worker.js
    import worker from "@ohos.worker";
    const parentPort = worker.parentPort;
    parentPort.onmessage = function(e) {
        console.log("receive main.js message")
    }
    ```


### onmessageerror<a name="section16116749135015"></a>

onmessageerror?: \(event: MessageEvent\) =\> void

DedicatedWorkerGlobalScope的onmessageerror属性表示当 Worker 对象接收到一条无法被反序列化的消息时被调用的事件处理程序，处理程序在worker线程中执行。

-   参数：

    <a name="table21169494501"></a>
    <table><thead align="left"><tr id="row1411794917507"><th class="cellrowborder" valign="top" width="14.82%" id="mcps1.1.5.1.1"><p id="p2117134985012"><a name="p2117134985012"></a><a name="p2117134985012"></a>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="16.24%" id="mcps1.1.5.1.2"><p id="p161171949165016"><a name="p161171949165016"></a><a name="p161171949165016"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="7.6499999999999995%" id="mcps1.1.5.1.3"><p id="p5117104915501"><a name="p5117104915501"></a><a name="p5117104915501"></a>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="61.29%" id="mcps1.1.5.1.4"><p id="p111734915011"><a name="p111734915011"></a><a name="p111734915011"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row311784995013"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="p1117249195020"><a name="p1117249195020"></a><a name="p1117249195020"></a>event</p>
    </td>
    <td class="cellrowborder" valign="top" width="16.24%" headers="mcps1.1.5.1.2 "><p id="p10117154917508"><a name="p10117154917508"></a><a name="p10117154917508"></a><a href="#section191271455124710">MessageEvent</a></p>
    </td>
    <td class="cellrowborder" valign="top" width="7.6499999999999995%" headers="mcps1.1.5.1.3 "><p id="p711744911507"><a name="p711744911507"></a><a name="p711744911507"></a>否</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="p201188499500"><a name="p201188499500"></a><a name="p201188499500"></a>异常数据。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   示例：

    ```
    // main.js
    import worker from '@ohos.worker';
    const worker = new worker.Worker("workers/worker.js")
    
    // worker.js
    import worker from "@ohos.worker";
    const parentPort = worker.parentPort;
    parentPort.onmessageerror= function(e) {
        console.log("worker.js onmessageerror")
    }
    ```


## PostMessageOptions<a name="section176401093245"></a>

明确数据传递过程中需要转移所有权对象的类，传递所有权的对象必须是ArrayBuffer。

<a name="table1564010972415"></a>
<table><thead align="left"><tr id="row3640129112415"><th class="cellrowborder" valign="top" width="15.870000000000001%" id="mcps1.1.6.1.1"><p id="p1364089142412"><a name="p1364089142412"></a><a name="p1364089142412"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="10.86%" id="mcps1.1.6.1.2"><p id="p564013912415"><a name="p564013912415"></a><a name="p564013912415"></a>参数类型</p>
</th>
<th class="cellrowborder" valign="top" width="9.34%" id="mcps1.1.6.1.3"><p id="p1264016913243"><a name="p1264016913243"></a><a name="p1264016913243"></a>可读</p>
</th>
<th class="cellrowborder" valign="top" width="11.51%" id="mcps1.1.6.1.4"><p id="p1164089172413"><a name="p1164089172413"></a><a name="p1164089172413"></a>可写</p>
</th>
<th class="cellrowborder" valign="top" width="52.42%" id="mcps1.1.6.1.5"><p id="p7640169172410"><a name="p7640169172410"></a><a name="p7640169172410"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="row1064016982410"><td class="cellrowborder" valign="top" width="15.870000000000001%" headers="mcps1.1.6.1.1 "><p id="p156410962416"><a name="p156410962416"></a><a name="p156410962416"></a>transfer</p>
</td>
<td class="cellrowborder" valign="top" width="10.86%" headers="mcps1.1.6.1.2 "><p id="p59311042152414"><a name="p59311042152414"></a><a name="p59311042152414"></a>Object[]</p>
</td>
<td class="cellrowborder" valign="top" width="9.34%" headers="mcps1.1.6.1.3 "><p id="p17641179102414"><a name="p17641179102414"></a><a name="p17641179102414"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="11.51%" headers="mcps1.1.6.1.4 "><p id="p1864112919241"><a name="p1864112919241"></a><a name="p1864112919241"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="52.42%" headers="mcps1.1.6.1.5 "><p id="p18641139162415"><a name="p18641139162415"></a><a name="p18641139162415"></a>ArrayBuffer数组，用于传递所有权。</p>
</td>
</tr>
</tbody>
</table>

## Event<a name="section1674694018507"></a>

事件类。

<a name="table127461440175015"></a>
<table><thead align="left"><tr id="row10746640145010"><th class="cellrowborder" valign="top" width="15.870000000000001%" id="mcps1.1.6.1.1"><p id="p1174613403508"><a name="p1174613403508"></a><a name="p1174613403508"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="13.569999999999999%" id="mcps1.1.6.1.2"><p id="p1274614055018"><a name="p1274614055018"></a><a name="p1274614055018"></a>参数类型</p>
</th>
<th class="cellrowborder" valign="top" width="9.700000000000001%" id="mcps1.1.6.1.3"><p id="p37460409501"><a name="p37460409501"></a><a name="p37460409501"></a>可读</p>
</th>
<th class="cellrowborder" valign="top" width="8.44%" id="mcps1.1.6.1.4"><p id="p137461340145015"><a name="p137461340145015"></a><a name="p137461340145015"></a>可写</p>
</th>
<th class="cellrowborder" valign="top" width="52.42%" id="mcps1.1.6.1.5"><p id="p874616406508"><a name="p874616406508"></a><a name="p874616406508"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="row117475400509"><td class="cellrowborder" valign="top" width="15.870000000000001%" headers="mcps1.1.6.1.1 "><p id="p1074754095015"><a name="p1074754095015"></a><a name="p1074754095015"></a>type</p>
</td>
<td class="cellrowborder" valign="top" width="13.569999999999999%" headers="mcps1.1.6.1.2 "><p id="p5747240135016"><a name="p5747240135016"></a><a name="p5747240135016"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="9.700000000000001%" headers="mcps1.1.6.1.3 "><p id="p197471409508"><a name="p197471409508"></a><a name="p197471409508"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="8.44%" headers="mcps1.1.6.1.4 "><p id="p1974719408501"><a name="p1974719408501"></a><a name="p1974719408501"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="52.42%" headers="mcps1.1.6.1.5 "><p id="p974715404504"><a name="p974715404504"></a><a name="p974715404504"></a>指定事件的type。</p>
</td>
</tr>
<tr id="row1360594017519"><td class="cellrowborder" valign="top" width="15.870000000000001%" headers="mcps1.1.6.1.1 "><p id="p3605340165112"><a name="p3605340165112"></a><a name="p3605340165112"></a>timeStamp</p>
</td>
<td class="cellrowborder" valign="top" width="13.569999999999999%" headers="mcps1.1.6.1.2 "><p id="p260516404519"><a name="p260516404519"></a><a name="p260516404519"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="9.700000000000001%" headers="mcps1.1.6.1.3 "><p id="p1360513406518"><a name="p1360513406518"></a><a name="p1360513406518"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="8.44%" headers="mcps1.1.6.1.4 "><p id="p86051440205116"><a name="p86051440205116"></a><a name="p86051440205116"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="52.42%" headers="mcps1.1.6.1.5 "><p id="p860554020511"><a name="p860554020511"></a><a name="p860554020511"></a>事件创建时的时间戳（精度为毫秒）。</p>
</td>
</tr>
</tbody>
</table>

## EventListener<a name="section53411747134914"></a>

事件监听类。

### \(evt: Event\): void | Promise<void\><a name="section1915072122913"></a>

执行的回调函数。

-   参数：

    <a name="table9785174213215"></a>
    <table><thead align="left"><tr id="row3786042153218"><th class="cellrowborder" valign="top" width="14.82%" id="mcps1.1.5.1.1"><p id="p8786154293216"><a name="p8786154293216"></a><a name="p8786154293216"></a>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="16.24%" id="mcps1.1.5.1.2"><p id="p127865425324"><a name="p127865425324"></a><a name="p127865425324"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="7.6499999999999995%" id="mcps1.1.5.1.3"><p id="p678610423329"><a name="p678610423329"></a><a name="p678610423329"></a>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="61.29%" id="mcps1.1.5.1.4"><p id="p87861442183219"><a name="p87861442183219"></a><a name="p87861442183219"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row1478624283213"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="p1078654213218"><a name="p1078654213218"></a><a name="p1078654213218"></a>evt</p>
    </td>
    <td class="cellrowborder" valign="top" width="16.24%" headers="mcps1.1.5.1.2 "><p id="p14893142103417"><a name="p14893142103417"></a><a name="p14893142103417"></a><a href="#section1674694018507">Event</a></p>
    </td>
    <td class="cellrowborder" valign="top" width="7.6499999999999995%" headers="mcps1.1.5.1.3 "><p id="p14786194293211"><a name="p14786194293211"></a><a name="p14786194293211"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="p1178674203218"><a name="p1178674203218"></a><a name="p1178674203218"></a>回调的事件类。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   返回值

    <a name="t3e93239d9b134b80957bcdd4acb05291"></a>
    <table><thead align="left"><tr id="recc81d9f995d44aa87ba9d714b756569"><th class="cellrowborder" valign="top" width="33.93%" id="mcps1.1.3.1.1"><p id="aa3137ce511d140fba6cc93513a7a91e3"><a name="aa3137ce511d140fba6cc93513a7a91e3"></a><a name="aa3137ce511d140fba6cc93513a7a91e3"></a>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="66.07%" id="mcps1.1.3.1.2"><p id="a4ba8ead9ee7b48298d9a6ed10659f13b"><a name="a4ba8ead9ee7b48298d9a6ed10659f13b"></a><a name="a4ba8ead9ee7b48298d9a6ed10659f13b"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="r64430cb15b54497f88ea6330b9a7454c"><td class="cellrowborder" valign="top" width="33.93%" headers="mcps1.1.3.1.1 "><p id="p132211316155619"><a name="p132211316155619"></a><a name="p132211316155619"></a>void | Promise&lt;void&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="66.07%" headers="mcps1.1.3.1.2 "><p id="a1c9b8d1829ef489e9e0fd1863190d228"><a name="a1c9b8d1829ef489e9e0fd1863190d228"></a><a name="a1c9b8d1829ef489e9e0fd1863190d228"></a>无返回值或者以Promise形式返回。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   示例：

    ```
    import worker from '@ohos.worker';
    const worker = new worker.Worker("workers/worker.js");
    worker.addEventListener("alert", (e)=>{
        console.log("alert listener callback");
    })
    ```


## ErrorEvent<a name="section11241623172418"></a>

错误事件类，用于表示worker执行过程中出现异常的详细信息，ErrorEvent类继承[Event](#section1674694018507)。

<a name="table1224152319247"></a>
<table><thead align="left"><tr id="row19241723192418"><th class="cellrowborder" valign="top" width="15.870000000000001%" id="mcps1.1.6.1.1"><p id="p10241192313249"><a name="p10241192313249"></a><a name="p10241192313249"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="10.86%" id="mcps1.1.6.1.2"><p id="p924292382417"><a name="p924292382417"></a><a name="p924292382417"></a>参数类型</p>
</th>
<th class="cellrowborder" valign="top" width="9.34%" id="mcps1.1.6.1.3"><p id="p11242202318246"><a name="p11242202318246"></a><a name="p11242202318246"></a>可读</p>
</th>
<th class="cellrowborder" valign="top" width="11.51%" id="mcps1.1.6.1.4"><p id="p1424272312240"><a name="p1424272312240"></a><a name="p1424272312240"></a>可写</p>
</th>
<th class="cellrowborder" valign="top" width="52.42%" id="mcps1.1.6.1.5"><p id="p15242152362419"><a name="p15242152362419"></a><a name="p15242152362419"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="row8242122316243"><td class="cellrowborder" valign="top" width="15.870000000000001%" headers="mcps1.1.6.1.1 "><p id="p12428233244"><a name="p12428233244"></a><a name="p12428233244"></a>message</p>
</td>
<td class="cellrowborder" valign="top" width="10.86%" headers="mcps1.1.6.1.2 "><p id="p3242112322418"><a name="p3242112322418"></a><a name="p3242112322418"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="9.34%" headers="mcps1.1.6.1.3 "><p id="p524262312244"><a name="p524262312244"></a><a name="p524262312244"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="11.51%" headers="mcps1.1.6.1.4 "><p id="p13242102362418"><a name="p13242102362418"></a><a name="p13242102362418"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="52.42%" headers="mcps1.1.6.1.5 "><p id="p92421123192418"><a name="p92421123192418"></a><a name="p92421123192418"></a>异常发生的错误信息。</p>
</td>
</tr>
<tr id="row0242223192410"><td class="cellrowborder" valign="top" width="15.870000000000001%" headers="mcps1.1.6.1.1 "><p id="p7242142392413"><a name="p7242142392413"></a><a name="p7242142392413"></a>filename</p>
</td>
<td class="cellrowborder" valign="top" width="10.86%" headers="mcps1.1.6.1.2 "><p id="p92421239248"><a name="p92421239248"></a><a name="p92421239248"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="9.34%" headers="mcps1.1.6.1.3 "><p id="p424215236241"><a name="p424215236241"></a><a name="p424215236241"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="11.51%" headers="mcps1.1.6.1.4 "><p id="p0242223172411"><a name="p0242223172411"></a><a name="p0242223172411"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="52.42%" headers="mcps1.1.6.1.5 "><p id="p524262320241"><a name="p524262320241"></a><a name="p524262320241"></a>出现异常所在的文件。</p>
</td>
</tr>
<tr id="row434214463257"><td class="cellrowborder" valign="top" width="15.870000000000001%" headers="mcps1.1.6.1.1 "><p id="p5342164692515"><a name="p5342164692515"></a><a name="p5342164692515"></a>lineno</p>
</td>
<td class="cellrowborder" valign="top" width="10.86%" headers="mcps1.1.6.1.2 "><p id="p13342164622515"><a name="p13342164622515"></a><a name="p13342164622515"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="9.34%" headers="mcps1.1.6.1.3 "><p id="p13342194619258"><a name="p13342194619258"></a><a name="p13342194619258"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="11.51%" headers="mcps1.1.6.1.4 "><p id="p1934244652517"><a name="p1934244652517"></a><a name="p1934244652517"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="52.42%" headers="mcps1.1.6.1.5 "><p id="p23428465259"><a name="p23428465259"></a><a name="p23428465259"></a>异常所在的行数。</p>
</td>
</tr>
<tr id="row888217500256"><td class="cellrowborder" valign="top" width="15.870000000000001%" headers="mcps1.1.6.1.1 "><p id="p78821850182511"><a name="p78821850182511"></a><a name="p78821850182511"></a>colno</p>
</td>
<td class="cellrowborder" valign="top" width="10.86%" headers="mcps1.1.6.1.2 "><p id="p16882155017251"><a name="p16882155017251"></a><a name="p16882155017251"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="9.34%" headers="mcps1.1.6.1.3 "><p id="p188826506257"><a name="p188826506257"></a><a name="p188826506257"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="11.51%" headers="mcps1.1.6.1.4 "><p id="p1088219502255"><a name="p1088219502255"></a><a name="p1088219502255"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="52.42%" headers="mcps1.1.6.1.5 "><p id="p1288319505259"><a name="p1288319505259"></a><a name="p1288319505259"></a>异常所在的列数。</p>
</td>
</tr>
<tr id="row81624652614"><td class="cellrowborder" valign="top" width="15.870000000000001%" headers="mcps1.1.6.1.1 "><p id="p7161746182619"><a name="p7161746182619"></a><a name="p7161746182619"></a>error</p>
</td>
<td class="cellrowborder" valign="top" width="10.86%" headers="mcps1.1.6.1.2 "><p id="p316846162613"><a name="p316846162613"></a><a name="p316846162613"></a>Object</p>
</td>
<td class="cellrowborder" valign="top" width="9.34%" headers="mcps1.1.6.1.3 "><p id="p61764614263"><a name="p61764614263"></a><a name="p61764614263"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="11.51%" headers="mcps1.1.6.1.4 "><p id="p1817104615262"><a name="p1817104615262"></a><a name="p1817104615262"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="52.42%" headers="mcps1.1.6.1.5 "><p id="p3175462267"><a name="p3175462267"></a><a name="p3175462267"></a>异常类型。</p>
</td>
</tr>
</tbody>
</table>

## MessageEvent<a name="section191271455124710"></a>

消息类，持有worker线程间传递的数据。

<a name="table10128155524711"></a>
<table><thead align="left"><tr id="row1412855554719"><th class="cellrowborder" valign="top" width="15.870000000000001%" id="mcps1.1.6.1.1"><p id="p61283559473"><a name="p61283559473"></a><a name="p61283559473"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="10.86%" id="mcps1.1.6.1.2"><p id="p61281155134713"><a name="p61281155134713"></a><a name="p61281155134713"></a>参数类型</p>
</th>
<th class="cellrowborder" valign="top" width="9.34%" id="mcps1.1.6.1.3"><p id="p1312855520479"><a name="p1312855520479"></a><a name="p1312855520479"></a>可读</p>
</th>
<th class="cellrowborder" valign="top" width="11.51%" id="mcps1.1.6.1.4"><p id="p612855514717"><a name="p612855514717"></a><a name="p612855514717"></a>可写</p>
</th>
<th class="cellrowborder" valign="top" width="52.42%" id="mcps1.1.6.1.5"><p id="p17128755194716"><a name="p17128755194716"></a><a name="p17128755194716"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="row11128105544715"><td class="cellrowborder" valign="top" width="15.870000000000001%" headers="mcps1.1.6.1.1 "><p id="p141281755204713"><a name="p141281755204713"></a><a name="p141281755204713"></a>data</p>
</td>
<td class="cellrowborder" valign="top" width="10.86%" headers="mcps1.1.6.1.2 "><p id="p9128655144715"><a name="p9128655144715"></a><a name="p9128655144715"></a>T</p>
</td>
<td class="cellrowborder" valign="top" width="9.34%" headers="mcps1.1.6.1.3 "><p id="p91286553472"><a name="p91286553472"></a><a name="p91286553472"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="11.51%" headers="mcps1.1.6.1.4 "><p id="p111292558478"><a name="p111292558478"></a><a name="p111292558478"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="52.42%" headers="mcps1.1.6.1.5 "><p id="p612905514479"><a name="p612905514479"></a><a name="p612905514479"></a>线程间传递的数据。</p>
</td>
</tr>
</tbody>
</table>

## WorkerGlobalScope<a name="section12882825611"></a>

worker线程自身的运行环境，WorkerGlobalScope类继承[EventTarget](#section256019311465)。

### 属性<a name="section3626134611546"></a>

<a name="table5668145611542"></a>
<table><thead align="left"><tr id="row196681856175413"><th class="cellrowborder" valign="top" width="15.870000000000001%" id="mcps1.1.6.1.1"><p id="p466895614541"><a name="p466895614541"></a><a name="p466895614541"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="18.18%" id="mcps1.1.6.1.2"><p id="p466975610548"><a name="p466975610548"></a><a name="p466975610548"></a>参数类型</p>
</th>
<th class="cellrowborder" valign="top" width="7.48%" id="mcps1.1.6.1.3"><p id="p176692565546"><a name="p176692565546"></a><a name="p176692565546"></a>可读</p>
</th>
<th class="cellrowborder" valign="top" width="6.05%" id="mcps1.1.6.1.4"><p id="p5669185620548"><a name="p5669185620548"></a><a name="p5669185620548"></a>可写</p>
</th>
<th class="cellrowborder" valign="top" width="52.42%" id="mcps1.1.6.1.5"><p id="p766916567549"><a name="p766916567549"></a><a name="p766916567549"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="row15669185613547"><td class="cellrowborder" valign="top" width="15.870000000000001%" headers="mcps1.1.6.1.1 "><p id="p16692567543"><a name="p16692567543"></a><a name="p16692567543"></a>name</p>
</td>
<td class="cellrowborder" valign="top" width="18.18%" headers="mcps1.1.6.1.2 "><p id="p12669256175418"><a name="p12669256175418"></a><a name="p12669256175418"></a>string</p>
</td>
<td class="cellrowborder" valign="top" width="7.48%" headers="mcps1.1.6.1.3 "><p id="p1266912564547"><a name="p1266912564547"></a><a name="p1266912564547"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="6.05%" headers="mcps1.1.6.1.4 "><p id="p166955618549"><a name="p166955618549"></a><a name="p166955618549"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="52.42%" headers="mcps1.1.6.1.5 "><p id="p196697562549"><a name="p196697562549"></a><a name="p196697562549"></a>worker的名字，有new Worker时指定。</p>
</td>
</tr>
<tr id="row1266905611549"><td class="cellrowborder" valign="top" width="15.870000000000001%" headers="mcps1.1.6.1.1 "><p id="p7669456155412"><a name="p7669456155412"></a><a name="p7669456155412"></a>self</p>
</td>
<td class="cellrowborder" valign="top" width="18.18%" headers="mcps1.1.6.1.2 "><p id="p36698567543"><a name="p36698567543"></a><a name="p36698567543"></a><a href="#section12882825611">WorkerGlobalScope</a> &amp; typeof globalThis</p>
</td>
<td class="cellrowborder" valign="top" width="7.48%" headers="mcps1.1.6.1.3 "><p id="p15669115675415"><a name="p15669115675415"></a><a name="p15669115675415"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="6.05%" headers="mcps1.1.6.1.4 "><p id="p106701356125415"><a name="p106701356125415"></a><a name="p106701356125415"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="52.42%" headers="mcps1.1.6.1.5 "><p id="p116701563546"><a name="p116701563546"></a><a name="p116701563546"></a>WorkerGlobalScope本身。</p>
</td>
</tr>
</tbody>
</table>

### onerror<a name="section1234812184551"></a>

onerror?: \(ev: ErrorEvent\) =\> void

WorkerGlobalScope的onerror属性表示worker在执行过程中发生异常被调用的事件处理程序，处理程序在worker线程中执行。

-   参数：

    <a name="table434981814553"></a>
    <table><thead align="left"><tr id="row11349131825513"><th class="cellrowborder" valign="top" width="14.82%" id="mcps1.1.5.1.1"><p id="p18349131825511"><a name="p18349131825511"></a><a name="p18349131825511"></a>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="16.24%" id="mcps1.1.5.1.2"><p id="p93491186552"><a name="p93491186552"></a><a name="p93491186552"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="7.6499999999999995%" id="mcps1.1.5.1.3"><p id="p1034921855514"><a name="p1034921855514"></a><a name="p1034921855514"></a>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="61.29%" id="mcps1.1.5.1.4"><p id="p19349201812556"><a name="p19349201812556"></a><a name="p19349201812556"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row43491218115511"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="p1935041812559"><a name="p1935041812559"></a><a name="p1935041812559"></a>ev</p>
    </td>
    <td class="cellrowborder" valign="top" width="16.24%" headers="mcps1.1.5.1.2 "><p id="p1135091805513"><a name="p1135091805513"></a><a name="p1135091805513"></a><a href="#section11241623172418">ErrorEvent</a></p>
    </td>
    <td class="cellrowborder" valign="top" width="7.6499999999999995%" headers="mcps1.1.5.1.3 "><p id="p535041814557"><a name="p535041814557"></a><a name="p535041814557"></a>否</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="p935017188559"><a name="p935017188559"></a><a name="p935017188559"></a>异常数据。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   示例：

    ```
    // main.js
    import worker from '@ohos.worker';
    const worker = new worker.Worker("workers/worker.js")
    
    // worker.js
    import worker from "@ohos.worker";
    const parentPort = worker.parentPort
    parentPort.onerror = function(e){
        console.log("worker.js onerror")
    }
    ```


