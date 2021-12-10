# 获取进程相关的信息<a name="ZH-CN_TOPIC_0000001151456638"></a>

>![](../../public_sys-resources/icon-note.gif) **说明：** 
>从 API Version 7 开始支持。

## 导入模块<a name="s56d19203690d4782bfc74069abb6bd71"></a>

```
import process from '@ohos.process';
```

## 权限<a name="section11257113618419"></a>

无

## 属性<a name="section3317114914546"></a>

<a name="table11454105725410"></a>
<table><thead align="left"><tr id="row7455457115414"><th class="cellrowborder" valign="top" width="14.399999999999999%" id="mcps1.1.6.1.1"><p id="p84551257175410"><a name="p84551257175410"></a><a name="p84551257175410"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="21.16%" id="mcps1.1.6.1.2"><p id="p134557578549"><a name="p134557578549"></a><a name="p134557578549"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="8.39%" id="mcps1.1.6.1.3"><p id="p34551957175411"><a name="p34551957175411"></a><a name="p34551957175411"></a>可读</p>
</th>
<th class="cellrowborder" valign="top" width="8.110000000000001%" id="mcps1.1.6.1.4"><p id="p2045510572545"><a name="p2045510572545"></a><a name="p2045510572545"></a>可写</p>
</th>
<th class="cellrowborder" valign="top" width="47.94%" id="mcps1.1.6.1.5"><p id="p145575714544"><a name="p145575714544"></a><a name="p145575714544"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="row16455135745414"><td class="cellrowborder" valign="top" width="14.399999999999999%" headers="mcps1.1.6.1.1 "><p id="p17455657165416"><a name="p17455657165416"></a><a name="p17455657165416"></a>egid</p>
</td>
<td class="cellrowborder" valign="top" width="21.16%" headers="mcps1.1.6.1.2 "><p id="p1973158115511"><a name="p1973158115511"></a><a name="p1973158115511"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="8.39%" headers="mcps1.1.6.1.3 "><p id="p84554571547"><a name="p84554571547"></a><a name="p84554571547"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="8.110000000000001%" headers="mcps1.1.6.1.4 "><p id="p114551657185413"><a name="p114551657185413"></a><a name="p114551657185413"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="47.94%" headers="mcps1.1.6.1.5 "><p id="p14455857115415"><a name="p14455857115415"></a><a name="p14455857115415"></a>获取进程的有效组标识。</p>
</td>
</tr>
<tr id="row184551357135416"><td class="cellrowborder" valign="top" width="14.399999999999999%" headers="mcps1.1.6.1.1 "><p id="p8455135711544"><a name="p8455135711544"></a><a name="p8455135711544"></a>euid</p>
</td>
<td class="cellrowborder" valign="top" width="21.16%" headers="mcps1.1.6.1.2 "><p id="p6943158185519"><a name="p6943158185519"></a><a name="p6943158185519"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="8.39%" headers="mcps1.1.6.1.3 "><p id="p3455185745417"><a name="p3455185745417"></a><a name="p3455185745417"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="8.110000000000001%" headers="mcps1.1.6.1.4 "><p id="p2045585717548"><a name="p2045585717548"></a><a name="p2045585717548"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="47.94%" headers="mcps1.1.6.1.5 "><p id="p94821125817"><a name="p94821125817"></a><a name="p94821125817"></a>获取进程的有效用户身份。</p>
</td>
</tr>
<tr id="row3455357115411"><td class="cellrowborder" valign="top" width="14.399999999999999%" headers="mcps1.1.6.1.1 "><p id="p1345585785412"><a name="p1345585785412"></a><a name="p1345585785412"></a>gid</p>
</td>
<td class="cellrowborder" valign="top" width="21.16%" headers="mcps1.1.6.1.2 "><p id="p136661259155511"><a name="p136661259155511"></a><a name="p136661259155511"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="8.39%" headers="mcps1.1.6.1.3 "><p id="p04561457185415"><a name="p04561457185415"></a><a name="p04561457185415"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="8.110000000000001%" headers="mcps1.1.6.1.4 "><p id="p64561757195414"><a name="p64561757195414"></a><a name="p64561757195414"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="47.94%" headers="mcps1.1.6.1.5 "><p id="p6455857135420"><a name="p6455857135420"></a><a name="p6455857135420"></a>获取进程的组标识。</p>
</td>
</tr>
<tr id="row1456857195411"><td class="cellrowborder" valign="top" width="14.399999999999999%" headers="mcps1.1.6.1.1 "><p id="p1145614577542"><a name="p1145614577542"></a><a name="p1145614577542"></a>uid</p>
</td>
<td class="cellrowborder" valign="top" width="21.16%" headers="mcps1.1.6.1.2 "><p id="p105921606564"><a name="p105921606564"></a><a name="p105921606564"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="8.39%" headers="mcps1.1.6.1.3 "><p id="p16456125755417"><a name="p16456125755417"></a><a name="p16456125755417"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="8.110000000000001%" headers="mcps1.1.6.1.4 "><p id="p3456257165416"><a name="p3456257165416"></a><a name="p3456257165416"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="47.94%" headers="mcps1.1.6.1.5 "><p id="p1545610579549"><a name="p1545610579549"></a><a name="p1545610579549"></a>获取进程的用户标识。</p>
</td>
</tr>
<tr id="row134569575540"><td class="cellrowborder" valign="top" width="14.399999999999999%" headers="mcps1.1.6.1.1 "><p id="p5456155775414"><a name="p5456155775414"></a><a name="p5456155775414"></a>groups</p>
</td>
<td class="cellrowborder" valign="top" width="21.16%" headers="mcps1.1.6.1.2 "><p id="p1094449195614"><a name="p1094449195614"></a><a name="p1094449195614"></a>number[]</p>
</td>
<td class="cellrowborder" valign="top" width="8.39%" headers="mcps1.1.6.1.3 "><p id="p1745695725412"><a name="p1745695725412"></a><a name="p1745695725412"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="8.110000000000001%" headers="mcps1.1.6.1.4 "><p id="p19456195718542"><a name="p19456195718542"></a><a name="p19456195718542"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="47.94%" headers="mcps1.1.6.1.5 "><p id="p12456257145411"><a name="p12456257145411"></a><a name="p12456257145411"></a>获取一个带有补充组id的数组。</p>
</td>
</tr>
<tr id="row2456155735410"><td class="cellrowborder" valign="top" width="14.399999999999999%" headers="mcps1.1.6.1.1 "><p id="p145695716545"><a name="p145695716545"></a><a name="p145695716545"></a>pid</p>
</td>
<td class="cellrowborder" valign="top" width="21.16%" headers="mcps1.1.6.1.2 "><p id="p917781619565"><a name="p917781619565"></a><a name="p917781619565"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="8.39%" headers="mcps1.1.6.1.3 "><p id="p145625711546"><a name="p145625711546"></a><a name="p145625711546"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="8.110000000000001%" headers="mcps1.1.6.1.4 "><p id="p17456105745419"><a name="p17456105745419"></a><a name="p17456105745419"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="47.94%" headers="mcps1.1.6.1.5 "><p id="p1545612577543"><a name="p1545612577543"></a><a name="p1545612577543"></a>获取当前进程的pid。</p>
</td>
</tr>
<tr id="row195001712125615"><td class="cellrowborder" valign="top" width="14.399999999999999%" headers="mcps1.1.6.1.1 "><p id="p0501171213567"><a name="p0501171213567"></a><a name="p0501171213567"></a>ppid</p>
</td>
<td class="cellrowborder" valign="top" width="21.16%" headers="mcps1.1.6.1.2 "><p id="p69521816125613"><a name="p69521816125613"></a><a name="p69521816125613"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="8.39%" headers="mcps1.1.6.1.3 "><p id="p550171217569"><a name="p550171217569"></a><a name="p550171217569"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="8.110000000000001%" headers="mcps1.1.6.1.4 "><p id="p19501612175616"><a name="p19501612175616"></a><a name="p19501612175616"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="47.94%" headers="mcps1.1.6.1.5 "><p id="p2050111216567"><a name="p2050111216567"></a><a name="p2050111216567"></a>获取当前进程的父进程的pid。</p>
</td>
</tr>
</tbody>
</table>

## ChildProcess<a name="section6521387200"></a>

主进程可以获取子进程的标准输入输出，以及发送信号和关闭子进程。

### 属性<a name="section18482944113517"></a>

<a name="table20482104463514"></a>
<table><thead align="left"><tr id="row1348214444357"><th class="cellrowborder" valign="top" width="15.870000000000001%" id="mcps1.1.6.1.1"><p id="p184822443351"><a name="p184822443351"></a><a name="p184822443351"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="10.86%" id="mcps1.1.6.1.2"><p id="p1648254415353"><a name="p1648254415353"></a><a name="p1648254415353"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="9.34%" id="mcps1.1.6.1.3"><p id="p9482124413355"><a name="p9482124413355"></a><a name="p9482124413355"></a>可读</p>
</th>
<th class="cellrowborder" valign="top" width="11.51%" id="mcps1.1.6.1.4"><p id="p3482124493515"><a name="p3482124493515"></a><a name="p3482124493515"></a>可写</p>
</th>
<th class="cellrowborder" valign="top" width="52.42%" id="mcps1.1.6.1.5"><p id="p12482104483513"><a name="p12482104483513"></a><a name="p12482104483513"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="row148254473513"><td class="cellrowborder" valign="top" width="15.870000000000001%" headers="mcps1.1.6.1.1 "><p id="p188761547113820"><a name="p188761547113820"></a><a name="p188761547113820"></a>pid</p>
</td>
<td class="cellrowborder" valign="top" width="10.86%" headers="mcps1.1.6.1.2 "><p id="p3482124417356"><a name="p3482124417356"></a><a name="p3482124417356"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="9.34%" headers="mcps1.1.6.1.3 "><p id="p16483194443514"><a name="p16483194443514"></a><a name="p16483194443514"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="11.51%" headers="mcps1.1.6.1.4 "><p id="p64838449351"><a name="p64838449351"></a><a name="p64838449351"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="52.42%" headers="mcps1.1.6.1.5 "><p id="p7678105615402"><a name="p7678105615402"></a><a name="p7678105615402"></a>子进程的pid。</p>
</td>
</tr>
<tr id="row1483164414352"><td class="cellrowborder" valign="top" width="15.870000000000001%" headers="mcps1.1.6.1.1 "><p id="p17483184419352"><a name="p17483184419352"></a><a name="p17483184419352"></a>ppid</p>
</td>
<td class="cellrowborder" valign="top" width="10.86%" headers="mcps1.1.6.1.2 "><p id="p9483184410355"><a name="p9483184410355"></a><a name="p9483184410355"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="9.34%" headers="mcps1.1.6.1.3 "><p id="p1348384415359"><a name="p1348384415359"></a><a name="p1348384415359"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="11.51%" headers="mcps1.1.6.1.4 "><p id="p1448312449355"><a name="p1448312449355"></a><a name="p1448312449355"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="52.42%" headers="mcps1.1.6.1.5 "><p id="p19949102034110"><a name="p19949102034110"></a><a name="p19949102034110"></a>子进程的父进程的pid。</p>
</td>
</tr>
<tr id="row13483164419353"><td class="cellrowborder" valign="top" width="15.870000000000001%" headers="mcps1.1.6.1.1 "><p id="p10260103644215"><a name="p10260103644215"></a><a name="p10260103644215"></a>exitCode</p>
</td>
<td class="cellrowborder" valign="top" width="10.86%" headers="mcps1.1.6.1.2 "><p id="p4483174443517"><a name="p4483174443517"></a><a name="p4483174443517"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="9.34%" headers="mcps1.1.6.1.3 "><p id="p1483134419353"><a name="p1483134419353"></a><a name="p1483134419353"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="11.51%" headers="mcps1.1.6.1.4 "><p id="p648354483510"><a name="p648354483510"></a><a name="p648354483510"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="52.42%" headers="mcps1.1.6.1.5 "><p id="p348319442351"><a name="p348319442351"></a><a name="p348319442351"></a>子进程的退出码。</p>
</td>
</tr>
<tr id="row1818591014310"><td class="cellrowborder" valign="top" width="15.870000000000001%" headers="mcps1.1.6.1.1 "><p id="p133731715204318"><a name="p133731715204318"></a><a name="p133731715204318"></a>killed</p>
</td>
<td class="cellrowborder" valign="top" width="10.86%" headers="mcps1.1.6.1.2 "><p id="p20186181084318"><a name="p20186181084318"></a><a name="p20186181084318"></a>boolean</p>
</td>
<td class="cellrowborder" valign="top" width="9.34%" headers="mcps1.1.6.1.3 "><p id="p61861510174314"><a name="p61861510174314"></a><a name="p61861510174314"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="11.51%" headers="mcps1.1.6.1.4 "><p id="p6186151034317"><a name="p6186151034317"></a><a name="p6186151034317"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="52.42%" headers="mcps1.1.6.1.5 "><p id="p518611015431"><a name="p518611015431"></a><a name="p518611015431"></a>父进程给子进程发信号是否成功。</p>
</td>
</tr>
</tbody>
</table>

### wait<a name="section9594134194318"></a>

wait\(\): Promise<number\>

等待子进程运行结束，返回promise对象，其值为子进程的退出码。

-   返回值：

    <a name="table37864874412"></a>
    <table><thead align="left"><tr id="row1778638104418"><th class="cellrowborder" valign="top" width="25.790000000000003%" id="mcps1.1.3.1.1"><p id="p1778613834415"><a name="p1778613834415"></a><a name="p1778613834415"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="74.21%" id="mcps1.1.3.1.2"><p id="p6786118124414"><a name="p6786118124414"></a><a name="p6786118124414"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row678611818445"><td class="cellrowborder" valign="top" width="25.790000000000003%" headers="mcps1.1.3.1.1 "><p id="p731033633210"><a name="p731033633210"></a><a name="p731033633210"></a>Promise&lt;number&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="74.21%" headers="mcps1.1.3.1.2 "><p id="p6786118144419"><a name="p6786118144419"></a><a name="p6786118144419"></a>异步返回子进程的退出码。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   示例：

    ```
    import process from '@ohos.process';
    var child = process.runCmd('ls');
    var result = child.wait();
    result.then(val=>{
        console.log("result = " + val);
    })
    ```


### getOutput<a name="section1732152812716"></a>

getOutput\(\): Promise<Uint8Array\>

获取子进程的标准输出。

-   返回值：

    <a name="table034112818718"></a>
    <table><thead align="left"><tr id="row10341728976"><th class="cellrowborder" valign="top" width="30.98%" id="mcps1.1.3.1.1"><p id="p234182810716"><a name="p234182810716"></a><a name="p234182810716"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="69.02000000000001%" id="mcps1.1.3.1.2"><p id="p83412820713"><a name="p83412820713"></a><a name="p83412820713"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row183552814711"><td class="cellrowborder" valign="top" width="30.98%" headers="mcps1.1.3.1.1 "><p id="p035328878"><a name="p035328878"></a><a name="p035328878"></a>Promise&lt;Uint8Array&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="69.02000000000001%" headers="mcps1.1.3.1.2 "><p id="p83512284717"><a name="p83512284717"></a><a name="p83512284717"></a>异步返回标准输出的字节流。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   示例：

    ```
    import process from '@ohos.process';
    var child = process.runCmd('ls');
    var result = child.wait();
    child.getOutput.then(val=>{
        console.log("child.getOutput = " + val);
    })
    ```


### getErrorOutput<a name="section14671040141315"></a>

getErrorOutput\(\): Promise<Uint8Array\>

getErrorOutput函数用来获取子进程的标准错误输出。

-   返回值：

    <a name="table76721340131314"></a>
    <table><thead align="left"><tr id="row46721040191315"><th class="cellrowborder" valign="top" width="30.36%" id="mcps1.1.3.1.1"><p id="p3672140111313"><a name="p3672140111313"></a><a name="p3672140111313"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="69.64%" id="mcps1.1.3.1.2"><p id="p967214407133"><a name="p967214407133"></a><a name="p967214407133"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row767214407135"><td class="cellrowborder" valign="top" width="30.36%" headers="mcps1.1.3.1.1 "><p id="p767294017137"><a name="p767294017137"></a><a name="p767294017137"></a>Promise&lt;Uint8Array&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="69.64%" headers="mcps1.1.3.1.2 "><p id="p9672144081314"><a name="p9672144081314"></a><a name="p9672144081314"></a>异步返回标准错误输出的字节流。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   示例：

    ```
    import process from '@ohos.process';
    var child = process.runCmd('madir test.text');
    var result = child.wait();
    child.getErrorOutput.then(val=>{
        console.log("child.getErrorOutput= " + val);
    })
    ```


### close<a name="section28221257121518"></a>

close\(\):  void

关闭正在运行的子进程。

-   示例：

    ```
    import process from '@ohos.process';
    var child = process.runCmd('sleep 5; ls');
    child.close();
    ```


### kill<a name="section9528134162114"></a>

kill\(signal: number | string\): void

kill函数用来发送信号给子进程，结束指定进程。

-   参数：

    <a name="table157841181443"></a>
    <table><thead align="left"><tr id="row10784188164412"><th class="cellrowborder" valign="top" width="14.82%" id="mcps1.1.5.1.1"><p id="p167847814420"><a name="p167847814420"></a><a name="p167847814420"></a>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="26.71%" id="mcps1.1.5.1.2"><p id="p078418815441"><a name="p078418815441"></a><a name="p078418815441"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="12.879999999999999%" id="mcps1.1.5.1.3"><p id="p14784082449"><a name="p14784082449"></a><a name="p14784082449"></a>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="45.59%" id="mcps1.1.5.1.4"><p id="p1878468104412"><a name="p1878468104412"></a><a name="p1878468104412"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row27851385447"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="p2785284442"><a name="p2785284442"></a><a name="p2785284442"></a>signal</p>
    </td>
    <td class="cellrowborder" valign="top" width="26.71%" headers="mcps1.1.5.1.2 "><p id="p47857813448"><a name="p47857813448"></a><a name="p47857813448"></a>number | string</p>
    </td>
    <td class="cellrowborder" valign="top" width="12.879999999999999%" headers="mcps1.1.5.1.3 "><p id="p147859815443"><a name="p147859815443"></a><a name="p147859815443"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="45.59%" headers="mcps1.1.5.1.4 "><p id="p2078588194411"><a name="p2078588194411"></a><a name="p2078588194411"></a>数字或字符串。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   示例：

    ```
    import process from '@ohos.process';
    var child = process.runCmd('sleep 5; ls');
    child.kill(9);
    ```


## process.runCmd<a name="section19358326587"></a>

runCmd\(command: string, options?: \{ timeout : number, killSignal ：number | string, maxBuffer : number \}\) : ChildProcess

通过runcmd可以fork一个新的进程来运行一段shell，并返回ChildProcess对象。

-   参数：

    <a name="table1112161035716"></a>
    <table><thead align="left"><tr id="row191251055716"><th class="cellrowborder" valign="top" width="14.82%" id="mcps1.1.5.1.1"><p id="p1812191011573"><a name="p1812191011573"></a><a name="p1812191011573"></a>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="14.729999999999999%" id="mcps1.1.5.1.2"><p id="p111231095720"><a name="p111231095720"></a><a name="p111231095720"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="9.16%" id="mcps1.1.5.1.3"><p id="p812161055714"><a name="p812161055714"></a><a name="p812161055714"></a>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="61.29%" id="mcps1.1.5.1.4"><p id="p131331025718"><a name="p131331025718"></a><a name="p131331025718"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row12131310175711"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="p131301018576"><a name="p131301018576"></a><a name="p131301018576"></a>command</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.729999999999999%" headers="mcps1.1.5.1.2 "><p id="p813151075720"><a name="p813151075720"></a><a name="p813151075720"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="p313121025712"><a name="p313121025712"></a><a name="p313121025712"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="p1613131075715"><a name="p1613131075715"></a><a name="p1613131075715"></a>shell命令。</p>
    </td>
    </tr>
    <tr id="row187851287441"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="p187851487447"><a name="p187851487447"></a><a name="p187851487447"></a>options</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.729999999999999%" headers="mcps1.1.5.1.2 "><p id="p13785987448"><a name="p13785987448"></a><a name="p13785987448"></a>Object</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="p1878538154411"><a name="p1878538154411"></a><a name="p1878538154411"></a>否</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="p127684914432"><a name="p127684914432"></a><a name="p127684914432"></a>相关选项参数。</p>
    </td>
    </tr>
    </tbody>
    </table>

    **表 1**  options

    <a name="table395819335512"></a>
    <table><thead align="left"><tr id="row4958133185116"><th class="cellrowborder" valign="top" width="14.56%" id="mcps1.2.5.1.1"><p id="p1795813315511"><a name="p1795813315511"></a><a name="p1795813315511"></a>名称</p>
    </th>
    <th class="cellrowborder" valign="top" width="20.48%" id="mcps1.2.5.1.2"><p id="p1895883395120"><a name="p1895883395120"></a><a name="p1895883395120"></a>参数类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="9.700000000000001%" id="mcps1.2.5.1.3"><p id="p17958633125116"><a name="p17958633125116"></a><a name="p17958633125116"></a>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="55.26%" id="mcps1.2.5.1.4"><p id="p15958133312518"><a name="p15958133312518"></a><a name="p15958133312518"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row1958833125117"><td class="cellrowborder" valign="top" width="14.56%" headers="mcps1.2.5.1.1 "><p id="p1984204213513"><a name="p1984204213513"></a><a name="p1984204213513"></a>timeout</p>
    </td>
    <td class="cellrowborder" valign="top" width="20.48%" headers="mcps1.2.5.1.2 "><p id="p11958733115110"><a name="p11958733115110"></a><a name="p11958733115110"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.700000000000001%" headers="mcps1.2.5.1.3 "><p id="p1995817337517"><a name="p1995817337517"></a><a name="p1995817337517"></a>否</p>
    </td>
    <td class="cellrowborder" valign="top" width="55.26%" headers="mcps1.2.5.1.4 "><p id="p3958113385114"><a name="p3958113385114"></a><a name="p3958113385114"></a>子进程运行的ms数，当子进程运行时间超出此时间，则父进程发送killSignal信号给子进程。timeout默认为0。</p>
    </td>
    </tr>
    <tr id="row15974103410012"><td class="cellrowborder" valign="top" width="14.56%" headers="mcps1.2.5.1.1 "><p id="p18974173412018"><a name="p18974173412018"></a><a name="p18974173412018"></a>killSignal</p>
    </td>
    <td class="cellrowborder" valign="top" width="20.48%" headers="mcps1.2.5.1.2 "><p id="p1397433413014"><a name="p1397433413014"></a><a name="p1397433413014"></a>number  | string</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.700000000000001%" headers="mcps1.2.5.1.3 "><p id="p1497411347015"><a name="p1497411347015"></a><a name="p1497411347015"></a>否</p>
    </td>
    <td class="cellrowborder" valign="top" width="55.26%" headers="mcps1.2.5.1.4 "><p id="p6975134106"><a name="p6975134106"></a><a name="p6975134106"></a>子进程运行时间超出timeout时，父进程发送killSignal 信号给子进程。killSignal 默认为'SIGTERM'。</p>
    </td>
    </tr>
    <tr id="row7848832602"><td class="cellrowborder" valign="top" width="14.56%" headers="mcps1.2.5.1.1 "><p id="p138496321602"><a name="p138496321602"></a><a name="p138496321602"></a>maxBuffer</p>
    </td>
    <td class="cellrowborder" valign="top" width="20.48%" headers="mcps1.2.5.1.2 "><p id="p138499328017"><a name="p138499328017"></a><a name="p138499328017"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.700000000000001%" headers="mcps1.2.5.1.3 "><p id="p784919321409"><a name="p784919321409"></a><a name="p784919321409"></a>否</p>
    </td>
    <td class="cellrowborder" valign="top" width="55.26%" headers="mcps1.2.5.1.4 "><p id="p610211102610"><a name="p610211102610"></a><a name="p610211102610"></a>子进程标准输入输出的最大缓冲区大小，当超出此大小时则终止子进程。maxBuffer默认1024*1024。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   返回值：

    <a name="table214161065718"></a>
    <table><thead align="left"><tr id="row21412108574"><th class="cellrowborder" valign="top" width="20.990000000000002%" id="mcps1.1.3.1.1"><p id="p714201014577"><a name="p714201014577"></a><a name="p714201014577"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="79.01%" id="mcps1.1.3.1.2"><p id="p2014131085719"><a name="p2014131085719"></a><a name="p2014131085719"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row1715121005719"><td class="cellrowborder" valign="top" width="20.990000000000002%" headers="mcps1.1.3.1.1 "><p id="p915110115714"><a name="p915110115714"></a><a name="p915110115714"></a><a href="#section6521387200">ChildProcess</a></p>
    </td>
    <td class="cellrowborder" valign="top" width="79.01%" headers="mcps1.1.3.1.2 "><p id="p1738116141104"><a name="p1738116141104"></a><a name="p1738116141104"></a>子进程对象。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   示例：

    ```
    import process from '@ohos.process';
    var child = process.runCmd('ls', { maxBuffer : 2 });
    var result = child.wait();
    child.getOutput.then(val=>{
        console.log("child.getOutput = " + val);
    }
    ```


## process.abort<a name="section564715329325"></a>

abort\(\): void

该方法会导致进程立即退出并生成一个核心文件，谨慎使用。

-   示例：

    ```
    import process from '@ohos.process';
    process.abort();
    ```


## process.on<a name="section2394161818344"></a>

on\(type: string, listener: EventListener\): void

用该方法来存储用户所触发的事件。

-   参数：

    <a name="table97411514490"></a>
    <table><thead align="left"><tr id="row137601516499"><th class="cellrowborder" valign="top" width="14.82%" id="mcps1.1.5.1.1"><p id="p27631520491"><a name="p27631520491"></a><a name="p27631520491"></a>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="22.68%" id="mcps1.1.5.1.2"><p id="p167691514913"><a name="p167691514913"></a><a name="p167691514913"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="10.12%" id="mcps1.1.5.1.3"><p id="p676101554917"><a name="p676101554917"></a><a name="p676101554917"></a>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="52.38%" id="mcps1.1.5.1.4"><p id="p9774157491"><a name="p9774157491"></a><a name="p9774157491"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row107791514917"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="p12771515144912"><a name="p12771515144912"></a><a name="p12771515144912"></a>type</p>
    </td>
    <td class="cellrowborder" valign="top" width="22.68%" headers="mcps1.1.5.1.2 "><p id="p10771815134911"><a name="p10771815134911"></a><a name="p10771815134911"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="10.12%" headers="mcps1.1.5.1.3 "><p id="p97771554918"><a name="p97771554918"></a><a name="p97771554918"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="52.38%" headers="mcps1.1.5.1.4 "><p id="p137713153495"><a name="p137713153495"></a><a name="p137713153495"></a>存储事件的type。</p>
    </td>
    </tr>
    <tr id="row158298389506"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="p38301938105018"><a name="p38301938105018"></a><a name="p38301938105018"></a>listener</p>
    </td>
    <td class="cellrowborder" valign="top" width="22.68%" headers="mcps1.1.5.1.2 "><p id="p118305385503"><a name="p118305385503"></a><a name="p118305385503"></a><a href="#table4113811060">EventListener</a></p>
    </td>
    <td class="cellrowborder" valign="top" width="10.12%" headers="mcps1.1.5.1.3 "><p id="p18927121585115"><a name="p18927121585115"></a><a name="p18927121585115"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="52.38%" headers="mcps1.1.5.1.4 "><p id="p1883013382505"><a name="p1883013382505"></a><a name="p1883013382505"></a>回调的事件。</p>
    </td>
    </tr>
    </tbody>
    </table>

    **表 2**  EventListener

    <a name="table4113811060"></a>
    <table><thead align="left"><tr id="row181132115610"><th class="cellrowborder" valign="top" width="50%" id="mcps1.2.3.1.1"><p id="p5113191361"><a name="p5113191361"></a><a name="p5113191361"></a>名称</p>
    </th>
    <th class="cellrowborder" valign="top" width="50%" id="mcps1.2.3.1.2"><p id="p161131811561"><a name="p161131811561"></a><a name="p161131811561"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row5113313614"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p241813217619"><a name="p241813217619"></a><a name="p241813217619"></a>EventListener = (evt: Object) <span>=</span><span>&gt;</span> void</p>
    </td>
    <td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p151131011166"><a name="p151131011166"></a><a name="p151131011166"></a>用户存储的事件。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   示例：

    ```
    import process from '@ohos.process';
    process.on("data", (e)=>{
        console.log("data callback");
    })
    ```


## process.off<a name="section1228205293415"></a>

off\(type: string\): boolean

用该方法来删除用户存储的事件。

-   参数：

    <a name="table15223195413589"></a>
    <table><thead align="left"><tr id="row722305475810"><th class="cellrowborder" valign="top" width="14.82%" id="mcps1.1.5.1.1"><p id="p1722375495810"><a name="p1722375495810"></a><a name="p1722375495810"></a>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="14.729999999999999%" id="mcps1.1.5.1.2"><p id="p1222315547583"><a name="p1222315547583"></a><a name="p1222315547583"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="9.16%" id="mcps1.1.5.1.3"><p id="p10223165410588"><a name="p10223165410588"></a><a name="p10223165410588"></a>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="61.29%" id="mcps1.1.5.1.4"><p id="p192238546586"><a name="p192238546586"></a><a name="p192238546586"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row112232547583"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="p1014218415590"><a name="p1014218415590"></a><a name="p1014218415590"></a>type</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.729999999999999%" headers="mcps1.1.5.1.2 "><p id="p1314216415913"><a name="p1314216415913"></a><a name="p1314216415913"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="p71427411593"><a name="p71427411593"></a><a name="p71427411593"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="p14142749591"><a name="p14142749591"></a><a name="p14142749591"></a>删除事件的type。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   返回值：

    <a name="table922785415814"></a>
    <table><thead align="left"><tr id="row92271854115813"><th class="cellrowborder" valign="top" width="20.990000000000002%" id="mcps1.1.3.1.1"><p id="p1822715542582"><a name="p1822715542582"></a><a name="p1822715542582"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="79.01%" id="mcps1.1.3.1.2"><p id="p1622725445816"><a name="p1622725445816"></a><a name="p1622725445816"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row322716540586"><td class="cellrowborder" valign="top" width="20.990000000000002%" headers="mcps1.1.3.1.1 "><p id="p4227105415813"><a name="p4227105415813"></a><a name="p4227105415813"></a>boolean</p>
    </td>
    <td class="cellrowborder" valign="top" width="79.01%" headers="mcps1.1.3.1.2 "><p id="p20227155415582"><a name="p20227155415582"></a><a name="p20227155415582"></a>事件是否删除成功。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   示例：

    ```
    import process from '@ohos.process';
    process.on("data", (e)=>{
        console.log("data callback");
    })
    var result = process.off("data");
    ```


## process.exit<a name="section114951112414"></a>

exit\(code: number\): void

用该方法终止程序，谨慎使用。

-   参数：

    <a name="table691919201218"></a>
    <table><thead align="left"><tr id="row14919182012210"><th class="cellrowborder" valign="top" width="14.82%" id="mcps1.1.5.1.1"><p id="p79202201623"><a name="p79202201623"></a><a name="p79202201623"></a>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="14.729999999999999%" id="mcps1.1.5.1.2"><p id="p2092052010218"><a name="p2092052010218"></a><a name="p2092052010218"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="9.16%" id="mcps1.1.5.1.3"><p id="p89201020123"><a name="p89201020123"></a><a name="p89201020123"></a>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="61.29%" id="mcps1.1.5.1.4"><p id="p2920142015220"><a name="p2920142015220"></a><a name="p2920142015220"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row19200201225"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="p169201020724"><a name="p169201020724"></a><a name="p169201020724"></a>code</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.729999999999999%" headers="mcps1.1.5.1.2 "><p id="p18920132014217"><a name="p18920132014217"></a><a name="p18920132014217"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="p13920320023"><a name="p13920320023"></a><a name="p13920320023"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="p592018206215"><a name="p592018206215"></a><a name="p592018206215"></a>进程的退出码。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   示例：

    ```
    import process from '@ohos.process';
    process.exit(0);
    ```


## process.cwd<a name="section13686195712218"></a>

cwd\(\): string

用该方法获取进程的工作目录。

-   示例：

    ```
    import process from '@ohos.process';
    var path = process.cwd();
    ```


## process.chdir<a name="section43111956114115"></a>

chdir\(dir: string\): void

用该方法更改进程的当前工作目录。

-   参数：

    <a name="table202677324416"></a>
    <table><thead align="left"><tr id="row162681432743"><th class="cellrowborder" valign="top" width="14.82%" id="mcps1.1.5.1.1"><p id="p1426818321943"><a name="p1426818321943"></a><a name="p1426818321943"></a>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="14.729999999999999%" id="mcps1.1.5.1.2"><p id="p6268173214416"><a name="p6268173214416"></a><a name="p6268173214416"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="9.16%" id="mcps1.1.5.1.3"><p id="p4268183211410"><a name="p4268183211410"></a><a name="p4268183211410"></a>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="61.29%" id="mcps1.1.5.1.4"><p id="p16268932748"><a name="p16268932748"></a><a name="p16268932748"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row19268183217420"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="p82682321645"><a name="p82682321645"></a><a name="p82682321645"></a>dir</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.729999999999999%" headers="mcps1.1.5.1.2 "><p id="p1226813321641"><a name="p1226813321641"></a><a name="p1226813321641"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="p726915322416"><a name="p726915322416"></a><a name="p726915322416"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="p026913215412"><a name="p026913215412"></a><a name="p026913215412"></a>路径。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   示例：

    ```
    import process from '@ohos.process';
    process.chdir('/system');
    ```


## process.uptime<a name="section167881439204913"></a>

uptime\(\): number

获取当前系统已运行的秒数。

-   返回值：

    <a name="table1447184441513"></a>
    <table><thead align="left"><tr id="row134819448158"><th class="cellrowborder" valign="top" width="21.02%" id="mcps1.1.3.1.1"><p id="p34812447155"><a name="p34812447155"></a><a name="p34812447155"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="78.97999999999999%" id="mcps1.1.3.1.2"><p id="p548204471513"><a name="p548204471513"></a><a name="p548204471513"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row114894411519"><td class="cellrowborder" valign="top" width="21.02%" headers="mcps1.1.3.1.1 "><p id="p848104412156"><a name="p848104412156"></a><a name="p848104412156"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="78.97999999999999%" headers="mcps1.1.3.1.2 "><p id="p17605112914167"><a name="p17605112914167"></a><a name="p17605112914167"></a>当前系统已运行的秒数。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   示例：

    ```
    import process from '@ohos.process';
    var time = process.uptime();
    ```


## process.kill<a name="section3121181316503"></a>

kill\(pid: number，signal: number \): boolean

用该方法发送signal到指定的进程，结束指定进程。

-   参数：

    <a name="table320419413195"></a>
    <table><thead align="left"><tr id="row17204104113196"><th class="cellrowborder" valign="top" width="14.82%" id="mcps1.1.5.1.1"><p id="p192040414196"><a name="p192040414196"></a><a name="p192040414196"></a>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="14.729999999999999%" id="mcps1.1.5.1.2"><p id="p112051141111917"><a name="p112051141111917"></a><a name="p112051141111917"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="9.16%" id="mcps1.1.5.1.3"><p id="p1820513411192"><a name="p1820513411192"></a><a name="p1820513411192"></a>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="61.29%" id="mcps1.1.5.1.4"><p id="p10205104171912"><a name="p10205104171912"></a><a name="p10205104171912"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row16205124115197"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="p17205194119198"><a name="p17205194119198"></a><a name="p17205194119198"></a>pid</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.729999999999999%" headers="mcps1.1.5.1.2 "><p id="p9206154111912"><a name="p9206154111912"></a><a name="p9206154111912"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="p129831811973"><a name="p129831811973"></a><a name="p129831811973"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="p4206174101910"><a name="p4206174101910"></a><a name="p4206174101910"></a>进程的id。</p>
    </td>
    </tr>
    <tr id="row468541102118"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="p36851112210"><a name="p36851112210"></a><a name="p36851112210"></a>signal</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.729999999999999%" headers="mcps1.1.5.1.2 "><p id="p1368614117219"><a name="p1368614117219"></a><a name="p1368614117219"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="p56868110217"><a name="p56868110217"></a><a name="p56868110217"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="p166869118217"><a name="p166869118217"></a><a name="p166869118217"></a>发送的信号。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   返回值：

    <a name="table320610411199"></a>
    <table><thead align="left"><tr id="row19206941101910"><th class="cellrowborder" valign="top" width="20.990000000000002%" id="mcps1.1.3.1.1"><p id="p16207134111917"><a name="p16207134111917"></a><a name="p16207134111917"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="79.01%" id="mcps1.1.3.1.2"><p id="p3207124181912"><a name="p3207124181912"></a><a name="p3207124181912"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row15207741141911"><td class="cellrowborder" valign="top" width="20.990000000000002%" headers="mcps1.1.3.1.1 "><p id="p1620714412197"><a name="p1620714412197"></a><a name="p1620714412197"></a>boolean</p>
    </td>
    <td class="cellrowborder" valign="top" width="79.01%" headers="mcps1.1.3.1.2 "><p id="p7207194141914"><a name="p7207194141914"></a><a name="p7207194141914"></a>信号是否发送成功。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   示例：

    ```
    import process from '@ohos.process'
    var pres = process.pid
    var result = that.kill(pres, 28)
    ```


