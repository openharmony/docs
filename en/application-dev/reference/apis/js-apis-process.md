# Obtaining Process Information<a name="EN-US_TOPIC_0000001237480785"></a>

>![](../../public_sys-resources/icon-note.gif) **NOTE:** 
>The initial APIs of this module are supported since API version 7. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import<a name="s56d19203690d4782bfc74069abb6bd71"></a>

```
import process from '@ohos.process';
```

## Required Permissions<a name="section11257113618419"></a>

None

## Attributes<a name="section3317114914546"></a>

<a name="table11454105725410"></a>
<table><thead align="left"><tr id="row7455457115414"><th class="cellrowborder" valign="top" width="14.399999999999999%" id="mcps1.1.6.1.1"><p id="p84551257175410"><a name="p84551257175410"></a><a name="p84551257175410"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="21.16%" id="mcps1.1.6.1.2"><p id="p134557578549"><a name="p134557578549"></a><a name="p134557578549"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="8.39%" id="mcps1.1.6.1.3"><p id="p34551957175411"><a name="p34551957175411"></a><a name="p34551957175411"></a>Readable</p>
</th>
<th class="cellrowborder" valign="top" width="8.110000000000001%" id="mcps1.1.6.1.4"><p id="p2045510572545"><a name="p2045510572545"></a><a name="p2045510572545"></a>Writable</p>
</th>
<th class="cellrowborder" valign="top" width="47.94%" id="mcps1.1.6.1.5"><p id="p145575714544"><a name="p145575714544"></a><a name="p145575714544"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row16455135745414"><td class="cellrowborder" valign="top" width="14.399999999999999%" headers="mcps1.1.6.1.1 "><p id="p17455657165416"><a name="p17455657165416"></a><a name="p17455657165416"></a>egid</p>
</td>
<td class="cellrowborder" valign="top" width="21.16%" headers="mcps1.1.6.1.2 "><p id="p1973158115511"><a name="p1973158115511"></a><a name="p1973158115511"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="8.39%" headers="mcps1.1.6.1.3 "><p id="p84554571547"><a name="p84554571547"></a><a name="p84554571547"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="8.110000000000001%" headers="mcps1.1.6.1.4 "><p id="p114551657185413"><a name="p114551657185413"></a><a name="p114551657185413"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="47.94%" headers="mcps1.1.6.1.5 "><p id="p14455857115415"><a name="p14455857115415"></a><a name="p14455857115415"></a>Effective group identifier (EGID) of a process.</p>
</td>
</tr>
<tr id="row184551357135416"><td class="cellrowborder" valign="top" width="14.399999999999999%" headers="mcps1.1.6.1.1 "><p id="p8455135711544"><a name="p8455135711544"></a><a name="p8455135711544"></a>euid</p>
</td>
<td class="cellrowborder" valign="top" width="21.16%" headers="mcps1.1.6.1.2 "><p id="p6943158185519"><a name="p6943158185519"></a><a name="p6943158185519"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="8.39%" headers="mcps1.1.6.1.3 "><p id="p3455185745417"><a name="p3455185745417"></a><a name="p3455185745417"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="8.110000000000001%" headers="mcps1.1.6.1.4 "><p id="p2045585717548"><a name="p2045585717548"></a><a name="p2045585717548"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="47.94%" headers="mcps1.1.6.1.5 "><p id="p94821125817"><a name="p94821125817"></a><a name="p94821125817"></a>Effective user identifier (EUID) of a process.</p>
</td>
</tr>
<tr id="row3455357115411"><td class="cellrowborder" valign="top" width="14.399999999999999%" headers="mcps1.1.6.1.1 "><p id="p1345585785412"><a name="p1345585785412"></a><a name="p1345585785412"></a>gid</p>
</td>
<td class="cellrowborder" valign="top" width="21.16%" headers="mcps1.1.6.1.2 "><p id="p136661259155511"><a name="p136661259155511"></a><a name="p136661259155511"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="8.39%" headers="mcps1.1.6.1.3 "><p id="p04561457185415"><a name="p04561457185415"></a><a name="p04561457185415"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="8.110000000000001%" headers="mcps1.1.6.1.4 "><p id="p64561757195414"><a name="p64561757195414"></a><a name="p64561757195414"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="47.94%" headers="mcps1.1.6.1.5 "><p id="p6455857135420"><a name="p6455857135420"></a><a name="p6455857135420"></a>Group identifier (GID) of a process.</p>
</td>
</tr>
<tr id="row1456857195411"><td class="cellrowborder" valign="top" width="14.399999999999999%" headers="mcps1.1.6.1.1 "><p id="p1145614577542"><a name="p1145614577542"></a><a name="p1145614577542"></a>uid</p>
</td>
<td class="cellrowborder" valign="top" width="21.16%" headers="mcps1.1.6.1.2 "><p id="p105921606564"><a name="p105921606564"></a><a name="p105921606564"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="8.39%" headers="mcps1.1.6.1.3 "><p id="p16456125755417"><a name="p16456125755417"></a><a name="p16456125755417"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="8.110000000000001%" headers="mcps1.1.6.1.4 "><p id="p3456257165416"><a name="p3456257165416"></a><a name="p3456257165416"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="47.94%" headers="mcps1.1.6.1.5 "><p id="p1545610579549"><a name="p1545610579549"></a><a name="p1545610579549"></a>User identifier (UID) of a process.</p>
</td>
</tr>
<tr id="row134569575540"><td class="cellrowborder" valign="top" width="14.399999999999999%" headers="mcps1.1.6.1.1 "><p id="p5456155775414"><a name="p5456155775414"></a><a name="p5456155775414"></a>groups</p>
</td>
<td class="cellrowborder" valign="top" width="21.16%" headers="mcps1.1.6.1.2 "><p id="p1094449195614"><a name="p1094449195614"></a><a name="p1094449195614"></a>number[]</p>
</td>
<td class="cellrowborder" valign="top" width="8.39%" headers="mcps1.1.6.1.3 "><p id="p1745695725412"><a name="p1745695725412"></a><a name="p1745695725412"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="8.110000000000001%" headers="mcps1.1.6.1.4 "><p id="p19456195718542"><a name="p19456195718542"></a><a name="p19456195718542"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="47.94%" headers="mcps1.1.6.1.5 "><p id="p12456257145411"><a name="p12456257145411"></a><a name="p12456257145411"></a>Array with supplementary group IDs.</p>
</td>
</tr>
<tr id="row2456155735410"><td class="cellrowborder" valign="top" width="14.399999999999999%" headers="mcps1.1.6.1.1 "><p id="p145695716545"><a name="p145695716545"></a><a name="p145695716545"></a>pid</p>
</td>
<td class="cellrowborder" valign="top" width="21.16%" headers="mcps1.1.6.1.2 "><p id="p917781619565"><a name="p917781619565"></a><a name="p917781619565"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="8.39%" headers="mcps1.1.6.1.3 "><p id="p145625711546"><a name="p145625711546"></a><a name="p145625711546"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="8.110000000000001%" headers="mcps1.1.6.1.4 "><p id="p17456105745419"><a name="p17456105745419"></a><a name="p17456105745419"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="47.94%" headers="mcps1.1.6.1.5 "><p id="p1545612577543"><a name="p1545612577543"></a><a name="p1545612577543"></a>Process ID (PID) of a process.</p>
</td>
</tr>
<tr id="row195001712125615"><td class="cellrowborder" valign="top" width="14.399999999999999%" headers="mcps1.1.6.1.1 "><p id="p0501171213567"><a name="p0501171213567"></a><a name="p0501171213567"></a>ppid</p>
</td>
<td class="cellrowborder" valign="top" width="21.16%" headers="mcps1.1.6.1.2 "><p id="p69521816125613"><a name="p69521816125613"></a><a name="p69521816125613"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="8.39%" headers="mcps1.1.6.1.3 "><p id="p550171217569"><a name="p550171217569"></a><a name="p550171217569"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="8.110000000000001%" headers="mcps1.1.6.1.4 "><p id="p19501612175616"><a name="p19501612175616"></a><a name="p19501612175616"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="47.94%" headers="mcps1.1.6.1.5 "><p id="p2050111216567"><a name="p2050111216567"></a><a name="p2050111216567"></a>Parent process ID (PPID) of a process.</p>
</td>
</tr>
<tr id="row383373231019"><td class="cellrowborder" valign="top" width="14.399999999999999%" headers="mcps1.1.6.1.1 "><p id="p28339326100"><a name="p28339326100"></a><a name="p28339326100"></a>tid<sup id="sup515125418117"><a name="sup515125418117"></a><a name="sup515125418117"></a>8+</sup></p>
</td>
<td class="cellrowborder" valign="top" width="21.16%" headers="mcps1.1.6.1.2 "><p id="p1083318320102"><a name="p1083318320102"></a><a name="p1083318320102"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="8.39%" headers="mcps1.1.6.1.3 "><p id="p983433218101"><a name="p983433218101"></a><a name="p983433218101"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="8.110000000000001%" headers="mcps1.1.6.1.4 "><p id="p58341432121020"><a name="p58341432121020"></a><a name="p58341432121020"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="47.94%" headers="mcps1.1.6.1.5 "><p id="p16834532191011"><a name="p16834532191011"></a><a name="p16834532191011"></a>Thread ID (TID) of a process.</p>
</td>
</tr>
</tbody>
</table>

## ChildProcess<a name="section6521387200"></a>

Provides methods for a process to obtain the standard input and output of its child processes, send signals, and close its child processes.

### Attributes<a name="section18482944113517"></a>

<a name="table20482104463514"></a>
<table><thead align="left"><tr id="row1348214444357"><th class="cellrowborder" valign="top" width="15.870000000000001%" id="mcps1.1.6.1.1"><p id="p184822443351"><a name="p184822443351"></a><a name="p184822443351"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="10.86%" id="mcps1.1.6.1.2"><p id="p1648254415353"><a name="p1648254415353"></a><a name="p1648254415353"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="9.34%" id="mcps1.1.6.1.3"><p id="p9482124413355"><a name="p9482124413355"></a><a name="p9482124413355"></a>Readable</p>
</th>
<th class="cellrowborder" valign="top" width="11.51%" id="mcps1.1.6.1.4"><p id="p3482124493515"><a name="p3482124493515"></a><a name="p3482124493515"></a>Writable</p>
</th>
<th class="cellrowborder" valign="top" width="52.42%" id="mcps1.1.6.1.5"><p id="p12482104483513"><a name="p12482104483513"></a><a name="p12482104483513"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row148254473513"><td class="cellrowborder" valign="top" width="15.870000000000001%" headers="mcps1.1.6.1.1 "><p id="p188761547113820"><a name="p188761547113820"></a><a name="p188761547113820"></a>pid</p>
</td>
<td class="cellrowborder" valign="top" width="10.86%" headers="mcps1.1.6.1.2 "><p id="p3482124417356"><a name="p3482124417356"></a><a name="p3482124417356"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="9.34%" headers="mcps1.1.6.1.3 "><p id="p16483194443514"><a name="p16483194443514"></a><a name="p16483194443514"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="11.51%" headers="mcps1.1.6.1.4 "><p id="p64838449351"><a name="p64838449351"></a><a name="p64838449351"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="52.42%" headers="mcps1.1.6.1.5 "><p id="p7678105615402"><a name="p7678105615402"></a><a name="p7678105615402"></a>PID of the child process.</p>
</td>
</tr>
<tr id="row1483164414352"><td class="cellrowborder" valign="top" width="15.870000000000001%" headers="mcps1.1.6.1.1 "><p id="p17483184419352"><a name="p17483184419352"></a><a name="p17483184419352"></a>ppid</p>
</td>
<td class="cellrowborder" valign="top" width="10.86%" headers="mcps1.1.6.1.2 "><p id="p9483184410355"><a name="p9483184410355"></a><a name="p9483184410355"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="9.34%" headers="mcps1.1.6.1.3 "><p id="p1348384415359"><a name="p1348384415359"></a><a name="p1348384415359"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="11.51%" headers="mcps1.1.6.1.4 "><p id="p1448312449355"><a name="p1448312449355"></a><a name="p1448312449355"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="52.42%" headers="mcps1.1.6.1.5 "><p id="p19949102034110"><a name="p19949102034110"></a><a name="p19949102034110"></a>PPID of the child process.</p>
</td>
</tr>
<tr id="row13483164419353"><td class="cellrowborder" valign="top" width="15.870000000000001%" headers="mcps1.1.6.1.1 "><p id="p10260103644215"><a name="p10260103644215"></a><a name="p10260103644215"></a>exitCode</p>
</td>
<td class="cellrowborder" valign="top" width="10.86%" headers="mcps1.1.6.1.2 "><p id="p4483174443517"><a name="p4483174443517"></a><a name="p4483174443517"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="9.34%" headers="mcps1.1.6.1.3 "><p id="p1483134419353"><a name="p1483134419353"></a><a name="p1483134419353"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="11.51%" headers="mcps1.1.6.1.4 "><p id="p648354483510"><a name="p648354483510"></a><a name="p648354483510"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="52.42%" headers="mcps1.1.6.1.5 "><p id="p348319442351"><a name="p348319442351"></a><a name="p348319442351"></a>Exit code of the child process.</p>
</td>
</tr>
<tr id="row1818591014310"><td class="cellrowborder" valign="top" width="15.870000000000001%" headers="mcps1.1.6.1.1 "><p id="p133731715204318"><a name="p133731715204318"></a><a name="p133731715204318"></a>killed</p>
</td>
<td class="cellrowborder" valign="top" width="10.86%" headers="mcps1.1.6.1.2 "><p id="p20186181084318"><a name="p20186181084318"></a><a name="p20186181084318"></a>boolean</p>
</td>
<td class="cellrowborder" valign="top" width="9.34%" headers="mcps1.1.6.1.3 "><p id="p61861510174314"><a name="p61861510174314"></a><a name="p61861510174314"></a>Yes</p>
</td>
<td class="cellrowborder" valign="top" width="11.51%" headers="mcps1.1.6.1.4 "><p id="p6186151034317"><a name="p6186151034317"></a><a name="p6186151034317"></a>No</p>
</td>
<td class="cellrowborder" valign="top" width="52.42%" headers="mcps1.1.6.1.5 "><p id="p518611015431"><a name="p518611015431"></a><a name="p518611015431"></a>Whether the parent process successfully sends a signal to the child process to terminate it.</p>
</td>
</tr>
</tbody>
</table>

### wait<a name="section9594134194318"></a>

wait\(\): Promise<number\>

Waits until the child process ends. This method uses a promise to return the exit code of the child process.

-   Return values

    <a name="table37864874412"></a>
    <table><thead align="left"><tr id="row1778638104418"><th class="cellrowborder" valign="top" width="25.790000000000003%" id="mcps1.1.3.1.1"><p id="p1778613834415"><a name="p1778613834415"></a><a name="p1778613834415"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="74.21%" id="mcps1.1.3.1.2"><p id="p6786118124414"><a name="p6786118124414"></a><a name="p6786118124414"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row678611818445"><td class="cellrowborder" valign="top" width="25.790000000000003%" headers="mcps1.1.3.1.1 "><p id="p731033633210"><a name="p731033633210"></a><a name="p731033633210"></a>Promise&lt;number&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="74.21%" headers="mcps1.1.3.1.2 "><p id="p6786118144419"><a name="p6786118144419"></a><a name="p6786118144419"></a>Promise used to return the exit code of the child process.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Example

    ```
    var child = process.runCmd('ls');
    var result = child.wait();
    result.then(val=>{
        console.log("result = " + val);
    })
    ```


### getOutput<a name="section1732152812716"></a>

getOutput\(\): Promise<Uint8Array\>

Obtains the standard output of the child process.

-   Return values

    <a name="table034112818718"></a>
    <table><thead align="left"><tr id="row10341728976"><th class="cellrowborder" valign="top" width="30.98%" id="mcps1.1.3.1.1"><p id="p234182810716"><a name="p234182810716"></a><a name="p234182810716"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="69.02000000000001%" id="mcps1.1.3.1.2"><p id="p83412820713"><a name="p83412820713"></a><a name="p83412820713"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row183552814711"><td class="cellrowborder" valign="top" width="30.98%" headers="mcps1.1.3.1.1 "><p id="p035328878"><a name="p035328878"></a><a name="p035328878"></a>Promise&lt;Uint8Array&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="69.02000000000001%" headers="mcps1.1.3.1.2 "><p id="p83512284717"><a name="p83512284717"></a><a name="p83512284717"></a>Promise used to return the standard output in a Uint8Array.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Example

    ```
    var child = process.runCmd('ls');
    var result = child.wait();
    child.getOutput.then(val=>{
        console.log("child.getOutput = " + val);
    })
    ```


### getErrorOutput<a name="section14671040141315"></a>

getErrorOutput\(\): Promise<Uint8Array\>

Obtains the standard error output of the child process.

-   Return values

    <a name="table76721340131314"></a>
    <table><thead align="left"><tr id="row46721040191315"><th class="cellrowborder" valign="top" width="30.36%" id="mcps1.1.3.1.1"><p id="p3672140111313"><a name="p3672140111313"></a><a name="p3672140111313"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="69.64%" id="mcps1.1.3.1.2"><p id="p967214407133"><a name="p967214407133"></a><a name="p967214407133"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row767214407135"><td class="cellrowborder" valign="top" width="30.36%" headers="mcps1.1.3.1.1 "><p id="p767294017137"><a name="p767294017137"></a><a name="p767294017137"></a>Promise&lt;Uint8Array&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="69.64%" headers="mcps1.1.3.1.2 "><p id="p9672144081314"><a name="p9672144081314"></a><a name="p9672144081314"></a>Promise used to return the standard error output in a Uint8Array.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Example

    ```
    var child = process.runCmd('madir test.text');
    var result = child.wait();
    child.getErrorOutput.then(val=>{
        console.log("child.getErrorOutput= " + val);
    })
    ```


### close<a name="section28221257121518"></a>

close\(\):  void

Closes the child process in running.

-   Example

    ```
    var child = process.runCmd('sleep 5; ls');
    child.close();
    ```


### kill<a name="section9528134162114"></a>

kill\(signal: number | string\): void

Sends a signal to the specified child process to terminate it.

-   Parameters

    <a name="table157841181443"></a>
    <table><thead align="left"><tr id="row10784188164412"><th class="cellrowborder" valign="top" width="14.82%" id="mcps1.1.5.1.1"><p id="p167847814420"><a name="p167847814420"></a><a name="p167847814420"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="26.71%" id="mcps1.1.5.1.2"><p id="p078418815441"><a name="p078418815441"></a><a name="p078418815441"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="12.879999999999999%" id="mcps1.1.5.1.3"><p id="p14784082449"><a name="p14784082449"></a><a name="p14784082449"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="45.59%" id="mcps1.1.5.1.4"><p id="p1878468104412"><a name="p1878468104412"></a><a name="p1878468104412"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row27851385447"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="p2785284442"><a name="p2785284442"></a><a name="p2785284442"></a>signal</p>
    </td>
    <td class="cellrowborder" valign="top" width="26.71%" headers="mcps1.1.5.1.2 "><p id="p47857813448"><a name="p47857813448"></a><a name="p47857813448"></a>number | string</p>
    </td>
    <td class="cellrowborder" valign="top" width="12.879999999999999%" headers="mcps1.1.5.1.3 "><p id="p147859815443"><a name="p147859815443"></a><a name="p147859815443"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="45.59%" headers="mcps1.1.5.1.4 "><p id="p2078588194411"><a name="p2078588194411"></a><a name="p2078588194411"></a>Number or string to send.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Example

    ```
    var child = process.runCmd('sleep 5; ls');
    child.kill(9);
    ```


## process.isIsolatedProcess<sup>8+</sup><a name="section18531656131211"></a>

isIsolatedProcess\(\): boolean

Checks whether the process is isolated.

-   Return values

    <a name="table16748145772610"></a>
    <table><thead align="left"><tr id="row13748857132613"><th class="cellrowborder" valign="top" width="20.990000000000002%" id="mcps1.1.3.1.1"><p id="p5748125722616"><a name="p5748125722616"></a><a name="p5748125722616"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="79.01%" id="mcps1.1.3.1.2"><p id="p8748155719267"><a name="p8748155719267"></a><a name="p8748155719267"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row16748135742613"><td class="cellrowborder" valign="top" width="20.990000000000002%" headers="mcps1.1.3.1.1 "><p id="p6748757162618"><a name="p6748757162618"></a><a name="p6748757162618"></a>boolean</p>
    </td>
    <td class="cellrowborder" valign="top" width="79.01%" headers="mcps1.1.3.1.2 "><p id="p16749057182614"><a name="p16749057182614"></a><a name="p16749057182614"></a>Returns <strong id="b1257840101118"><a name="b1257840101118"></a><a name="b1257840101118"></a>true</strong> if the process is isolated; returns <strong id="b295119021219"><a name="b295119021219"></a><a name="b295119021219"></a>false</strong> otherwise.</p>
    </td>
    </tr>
    </tbody>
    </table>


-   Example

    ```
    var result = process.isIsolatedProcess();
    ```


## process.isAppUid<sup>8+</sup><a name="section3483872142"></a>

isAppUid\(v:number\): boolean

Checks whether a UID belongs to this app.

-   Parameters

    <a name="table1130031918288"></a>
    <table><thead align="left"><tr id="row5300181932814"><th class="cellrowborder" valign="top" width="14.82%" id="mcps1.1.5.1.1"><p id="p13300131917284"><a name="p13300131917284"></a><a name="p13300131917284"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="14.729999999999999%" id="mcps1.1.5.1.2"><p id="p12301131912284"><a name="p12301131912284"></a><a name="p12301131912284"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="9.16%" id="mcps1.1.5.1.3"><p id="p13011819122814"><a name="p13011819122814"></a><a name="p13011819122814"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="61.29%" id="mcps1.1.5.1.4"><p id="p10301141922817"><a name="p10301141922817"></a><a name="p10301141922817"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row1630116194285"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="p438853552813"><a name="p438853552813"></a><a name="p438853552813"></a>v</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.729999999999999%" headers="mcps1.1.5.1.2 "><p id="p530151916283"><a name="p530151916283"></a><a name="p530151916283"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="p12301819172811"><a name="p12301819172811"></a><a name="p12301819172811"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="p9302111962811"><a name="p9302111962811"></a><a name="p9302111962811"></a>UID.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Return values

    <a name="table193021119132815"></a>
    <table><thead align="left"><tr id="row630281915283"><th class="cellrowborder" valign="top" width="20.990000000000002%" id="mcps1.1.3.1.1"><p id="p13303619192811"><a name="p13303619192811"></a><a name="p13303619192811"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="79.01%" id="mcps1.1.3.1.2"><p id="p93034196281"><a name="p93034196281"></a><a name="p93034196281"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row0303201917288"><td class="cellrowborder" valign="top" width="20.990000000000002%" headers="mcps1.1.3.1.1 "><p id="p93031719172815"><a name="p93031719172815"></a><a name="p93031719172815"></a>boolean</p>
    </td>
    <td class="cellrowborder" valign="top" width="79.01%" headers="mcps1.1.3.1.2 "><p id="p2044064714286"><a name="p2044064714286"></a><a name="p2044064714286"></a>Returns <strong id="b11496154718238"><a name="b11496154718238"></a><a name="b11496154718238"></a>true</strong> if the UID is the app's UID; returns <strong id="b1549674712316"><a name="b1549674712316"></a><a name="b1549674712316"></a>false</strong> otherwise.</p>
    </td>
    </tr>
    </tbody>
    </table>


-   Example

    ```
    var result = process.isAppUid(688);
    ```


## process.is64Bit<sup>8+</sup><a name="section19430255141411"></a>

is64Bit\(\): boolean

Checks whether the operating environment is of 64-bit.

-   Return values

    <a name="table18430115511149"></a>
    <table><thead align="left"><tr id="row4430165512148"><th class="cellrowborder" valign="top" width="21.02%" id="mcps1.1.3.1.1"><p id="p94301555141"><a name="p94301555141"></a><a name="p94301555141"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="78.97999999999999%" id="mcps1.1.3.1.2"><p id="p6430185515144"><a name="p6430185515144"></a><a name="p6430185515144"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row9430125531413"><td class="cellrowborder" valign="top" width="21.02%" headers="mcps1.1.3.1.1 "><p id="p14430655121410"><a name="p14430655121410"></a><a name="p14430655121410"></a>boolean</p>
    </td>
    <td class="cellrowborder" valign="top" width="78.97999999999999%" headers="mcps1.1.3.1.2 "><p id="p943075571418"><a name="p943075571418"></a><a name="p943075571418"></a>Returns <strong id="b542211113264"><a name="b542211113264"></a><a name="b542211113264"></a>true</strong> if the operating environment is of 64-bit; returns <strong id="b1142231110265"><a name="b1142231110265"></a><a name="b1142231110265"></a>false</strong> otherwise.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Example

    ```
    var ressult = process.is64Bit();
    ```


## process.getUidForName<sup>8+</sup><a name="section1727712617154"></a>

getUidForName\(v:string\): number

Obtains the process UID based on the process name.

-   Parameters

    <a name="table10277142671518"></a>
    <table><thead align="left"><tr id="row1727719261158"><th class="cellrowborder" valign="top" width="14.82%" id="mcps1.1.5.1.1"><p id="p17277122616159"><a name="p17277122616159"></a><a name="p17277122616159"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="14.729999999999999%" id="mcps1.1.5.1.2"><p id="p11277172619159"><a name="p11277172619159"></a><a name="p11277172619159"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="9.16%" id="mcps1.1.5.1.3"><p id="p1127732661515"><a name="p1127732661515"></a><a name="p1127732661515"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="61.29%" id="mcps1.1.5.1.4"><p id="p102775264152"><a name="p102775264152"></a><a name="p102775264152"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row16277122631517"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="p192771126131510"><a name="p192771126131510"></a><a name="p192771126131510"></a>v</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.729999999999999%" headers="mcps1.1.5.1.2 "><p id="p827814265151"><a name="p827814265151"></a><a name="p827814265151"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="p122783261158"><a name="p122783261158"></a><a name="p122783261158"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="p22781526111515"><a name="p22781526111515"></a><a name="p22781526111515"></a>Process name.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Return values

    <a name="table12278152615151"></a>
    <table><thead align="left"><tr id="row1527842610155"><th class="cellrowborder" valign="top" width="21.02%" id="mcps1.1.3.1.1"><p id="p182781267158"><a name="p182781267158"></a><a name="p182781267158"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="78.97999999999999%" id="mcps1.1.3.1.2"><p id="p52781826161511"><a name="p52781826161511"></a><a name="p52781826161511"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row19278112681516"><td class="cellrowborder" valign="top" width="21.02%" headers="mcps1.1.3.1.1 "><p id="p927822691514"><a name="p927822691514"></a><a name="p927822691514"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="78.97999999999999%" headers="mcps1.1.3.1.2 "><p id="p18278426161512"><a name="p18278426161512"></a><a name="p18278426161512"></a>Process UID.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Example

    ```
    var pres = process.getUidForName("tool")
    ```


## process.getThreadPriority<sup>8+</sup><a name="section10468310163512"></a>

getThreadPriority\(v:number\): number

Obtains the thread priority based on the specified TID.

-   Parameters

    <a name="table1546841011357"></a>
    <table><thead align="left"><tr id="row14469111063515"><th class="cellrowborder" valign="top" width="14.82%" id="mcps1.1.5.1.1"><p id="p346951013359"><a name="p346951013359"></a><a name="p346951013359"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="14.729999999999999%" id="mcps1.1.5.1.2"><p id="p246918103351"><a name="p246918103351"></a><a name="p246918103351"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="9.16%" id="mcps1.1.5.1.3"><p id="p6469171013513"><a name="p6469171013513"></a><a name="p6469171013513"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="61.29%" id="mcps1.1.5.1.4"><p id="p1446917101352"><a name="p1446917101352"></a><a name="p1446917101352"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row5469910143518"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="p1247011033512"><a name="p1247011033512"></a><a name="p1247011033512"></a>v</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.729999999999999%" headers="mcps1.1.5.1.2 "><p id="p18470171083516"><a name="p18470171083516"></a><a name="p18470171083516"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="p7470110113512"><a name="p7470110113512"></a><a name="p7470110113512"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="p1327223011365"><a name="p1327223011365"></a><a name="p1327223011365"></a>TID.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Return values

    <a name="table1947018103358"></a>
    <table><thead align="left"><tr id="row134713108353"><th class="cellrowborder" valign="top" width="21.02%" id="mcps1.1.3.1.1"><p id="p84712101359"><a name="p84712101359"></a><a name="p84712101359"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="78.97999999999999%" id="mcps1.1.3.1.2"><p id="p44711910103519"><a name="p44711910103519"></a><a name="p44711910103519"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row154710105354"><td class="cellrowborder" valign="top" width="21.02%" headers="mcps1.1.3.1.1 "><p id="p1447181023517"><a name="p1447181023517"></a><a name="p1447181023517"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="78.97999999999999%" headers="mcps1.1.3.1.2 "><p id="p8471110183520"><a name="p8471110183520"></a><a name="p8471110183520"></a>Priority of the thread.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Example

    ```
    var tid = process.tid;
    var pres = process.getThreadPriority(tid);
    ```


## process.getStartRealtime<sup>8+</sup><a name="section1336514287167"></a>

getStartRealtime\(\) :number

Obtains the duration, in milliseconds, from the time the system starts to the time the process starts.

-   Return values

    <a name="table191971559142420"></a>
    <table><thead align="left"><tr id="row1119785919245"><th class="cellrowborder" valign="top" width="20.990000000000002%" id="mcps1.1.3.1.1"><p id="p2197115962417"><a name="p2197115962417"></a><a name="p2197115962417"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="79.01%" id="mcps1.1.3.1.2"><p id="p1419713599243"><a name="p1419713599243"></a><a name="p1419713599243"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row10198175982415"><td class="cellrowborder" valign="top" width="20.990000000000002%" headers="mcps1.1.3.1.1 "><p id="p719855942415"><a name="p719855942415"></a><a name="p719855942415"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="79.01%" headers="mcps1.1.3.1.2 "><p id="p1119875918248"><a name="p1119875918248"></a><a name="p1119875918248"></a>Time duration obtained.</p>
    </td>
    </tr>
    </tbody>
    </table>


-   Example

    ```
    var realtime = process.getStartRealtime();
    ```



## process.getPastCputime<sup>8+</sup><a name="section93991533201718"></a>

getPastCputime\(\) :number

Obtains the CPU time \(in milliseconds\) from the time the process starts to the current time.

-   Return values

    <a name="table935012126260"></a>
    <table><thead align="left"><tr id="row12350111272614"><th class="cellrowborder" valign="top" width="20.990000000000002%" id="mcps1.1.3.1.1"><p id="p1635081217266"><a name="p1635081217266"></a><a name="p1635081217266"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="79.01%" id="mcps1.1.3.1.2"><p id="p335014125263"><a name="p335014125263"></a><a name="p335014125263"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row835171215263"><td class="cellrowborder" valign="top" width="20.990000000000002%" headers="mcps1.1.3.1.1 "><p id="p1914922192620"><a name="p1914922192620"></a><a name="p1914922192620"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="79.01%" headers="mcps1.1.3.1.2 "><p id="p135118122264"><a name="p135118122264"></a><a name="p135118122264"></a>CPU time obtained.</p>
    </td>
    </tr>
    </tbody>
    </table>


-   Example

    ```
    var result = process.getPastCputime() ;
    ```


## process.getSystemConfig<sup>8+</sup><a name="section872533219413"></a>

getSystemConfig\(name:number\): number

Obtains the system configuration.

-   Parameters

    <a name="table187251232124112"></a>
    <table><thead align="left"><tr id="row1726153264119"><th class="cellrowborder" valign="top" width="14.82%" id="mcps1.1.5.1.1"><p id="p187261932204117"><a name="p187261932204117"></a><a name="p187261932204117"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="14.729999999999999%" id="mcps1.1.5.1.2"><p id="p19726163214110"><a name="p19726163214110"></a><a name="p19726163214110"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="9.16%" id="mcps1.1.5.1.3"><p id="p472613325413"><a name="p472613325413"></a><a name="p472613325413"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="61.29%" id="mcps1.1.5.1.4"><p id="p15726133284110"><a name="p15726133284110"></a><a name="p15726133284110"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row672763214419"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="p12727432174114"><a name="p12727432174114"></a><a name="p12727432174114"></a>name</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.729999999999999%" headers="mcps1.1.5.1.2 "><p id="p1372743216418"><a name="p1372743216418"></a><a name="p1372743216418"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="p2727153213419"><a name="p2727153213419"></a><a name="p2727153213419"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="p1572743215418"><a name="p1572743215418"></a><a name="p1572743215418"></a>System configuration parameter name.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Return values

    <a name="table2727123213413"></a>
    <table><thead align="left"><tr id="row117281232184114"><th class="cellrowborder" valign="top" width="21.02%" id="mcps1.1.3.1.1"><p id="p97281232104111"><a name="p97281232104111"></a><a name="p97281232104111"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="78.97999999999999%" id="mcps1.1.3.1.2"><p id="p1572853218415"><a name="p1572853218415"></a><a name="p1572853218415"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row14728732174120"><td class="cellrowborder" valign="top" width="21.02%" headers="mcps1.1.3.1.1 "><p id="p4728153254120"><a name="p4728153254120"></a><a name="p4728153254120"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="78.97999999999999%" headers="mcps1.1.3.1.2 "><p id="p3728193216419"><a name="p3728193216419"></a><a name="p3728193216419"></a>System configuration obtained.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Example

    ```
    var _SC_ARG_MAX = 0
    var pres = process.getSystemConfig(_SC_ARG_MAX)
    ```


## process.getEnvironmentVar<sup>8+</sup><a name="section3554201415462"></a>

getEnvironmentVar\(name:string\): string

Obtains the value of an environment variable.

-   Parameters

    <a name="table1554101419462"></a>
    <table><thead align="left"><tr id="row9555131415465"><th class="cellrowborder" valign="top" width="14.82%" id="mcps1.1.5.1.1"><p id="p25559140465"><a name="p25559140465"></a><a name="p25559140465"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="14.729999999999999%" id="mcps1.1.5.1.2"><p id="p65551014124619"><a name="p65551014124619"></a><a name="p65551014124619"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="9.16%" id="mcps1.1.5.1.3"><p id="p55569142467"><a name="p55569142467"></a><a name="p55569142467"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="61.29%" id="mcps1.1.5.1.4"><p id="p1855641454611"><a name="p1855641454611"></a><a name="p1855641454611"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row755681414469"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="p145561714164615"><a name="p145561714164615"></a><a name="p145561714164615"></a>name</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.729999999999999%" headers="mcps1.1.5.1.2 "><p id="p4556121444615"><a name="p4556121444615"></a><a name="p4556121444615"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="p055681484619"><a name="p055681484619"></a><a name="p055681484619"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="p755612143463"><a name="p755612143463"></a><a name="p755612143463"></a>Environment variable name.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Return values

    <a name="table75571014164610"></a>
    <table><thead align="left"><tr id="row75571914184619"><th class="cellrowborder" valign="top" width="21.02%" id="mcps1.1.3.1.1"><p id="p12557101474617"><a name="p12557101474617"></a><a name="p12557101474617"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="78.97999999999999%" id="mcps1.1.3.1.2"><p id="p9557191417469"><a name="p9557191417469"></a><a name="p9557191417469"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row8557121474617"><td class="cellrowborder" valign="top" width="21.02%" headers="mcps1.1.3.1.1 "><p id="p948123084713"><a name="p948123084713"></a><a name="p948123084713"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="78.97999999999999%" headers="mcps1.1.3.1.2 "><p id="p18558141494617"><a name="p18558141494617"></a><a name="p18558141494617"></a>Value of the environment variable.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Example

    ```
    var pres = process.getEnvironmentVar("PATH")
    ```


## process.runCmd<a name="section19358326587"></a>

runCmd\(command: string, options?: \{ timeout : number, killSignal : number | string, maxBuffer : number \}\) : ChildProcess

Forks a new process to run a shell command and returns the  **ChildProcess**  object.

-   Parameters

    <a name="table1112161035716"></a>
    <table><thead align="left"><tr id="row191251055716"><th class="cellrowborder" valign="top" width="14.82%" id="mcps1.1.5.1.1"><p id="p1812191011573"><a name="p1812191011573"></a><a name="p1812191011573"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="14.729999999999999%" id="mcps1.1.5.1.2"><p id="p111231095720"><a name="p111231095720"></a><a name="p111231095720"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="9.16%" id="mcps1.1.5.1.3"><p id="p812161055714"><a name="p812161055714"></a><a name="p812161055714"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="61.29%" id="mcps1.1.5.1.4"><p id="p131331025718"><a name="p131331025718"></a><a name="p131331025718"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row12131310175711"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="p131301018576"><a name="p131301018576"></a><a name="p131301018576"></a>command</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.729999999999999%" headers="mcps1.1.5.1.2 "><p id="p813151075720"><a name="p813151075720"></a><a name="p813151075720"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="p313121025712"><a name="p313121025712"></a><a name="p313121025712"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="p1613131075715"><a name="p1613131075715"></a><a name="p1613131075715"></a>Shell command to run.</p>
    </td>
    </tr>
    <tr id="row187851287441"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="p187851487447"><a name="p187851487447"></a><a name="p187851487447"></a>options</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.729999999999999%" headers="mcps1.1.5.1.2 "><p id="p13785987448"><a name="p13785987448"></a><a name="p13785987448"></a>Object</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="p1878538154411"><a name="p1878538154411"></a><a name="p1878538154411"></a>No</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="p127684914432"><a name="p127684914432"></a><a name="p127684914432"></a>Related parameters.</p>
    </td>
    </tr>
    </tbody>
    </table>

    **Table  1**  options

    <a name="table395819335512"></a>
    <table><thead align="left"><tr id="row4958133185116"><th class="cellrowborder" valign="top" width="14.56%" id="mcps1.2.5.1.1"><p id="p1795813315511"><a name="p1795813315511"></a><a name="p1795813315511"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="20.48%" id="mcps1.2.5.1.2"><p id="p1895883395120"><a name="p1895883395120"></a><a name="p1895883395120"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="9.700000000000001%" id="mcps1.2.5.1.3"><p id="p17958633125116"><a name="p17958633125116"></a><a name="p17958633125116"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="55.26%" id="mcps1.2.5.1.4"><p id="p15958133312518"><a name="p15958133312518"></a><a name="p15958133312518"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row1958833125117"><td class="cellrowborder" valign="top" width="14.56%" headers="mcps1.2.5.1.1 "><p id="p1984204213513"><a name="p1984204213513"></a><a name="p1984204213513"></a>timeout</p>
    </td>
    <td class="cellrowborder" valign="top" width="20.48%" headers="mcps1.2.5.1.2 "><p id="p11958733115110"><a name="p11958733115110"></a><a name="p11958733115110"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.700000000000001%" headers="mcps1.2.5.1.3 "><p id="p1995817337517"><a name="p1995817337517"></a><a name="p1995817337517"></a>No</p>
    </td>
    <td class="cellrowborder" valign="top" width="55.26%" headers="mcps1.2.5.1.4 "><p id="p3958113385114"><a name="p3958113385114"></a><a name="p3958113385114"></a>Maximum running time (in ms) of the child process. When the running time of the child process exceeds the value of this parameter, the parent process sends a <strong id="b16581181141220"><a name="b16581181141220"></a><a name="b16581181141220"></a>killSignal</strong> to the child process to terminate it. The default value is <strong id="b83520247124"><a name="b83520247124"></a><a name="b83520247124"></a>0</strong>.</p>
    </td>
    </tr>
    <tr id="row15974103410012"><td class="cellrowborder" valign="top" width="14.56%" headers="mcps1.2.5.1.1 "><p id="p18974173412018"><a name="p18974173412018"></a><a name="p18974173412018"></a>killSignal</p>
    </td>
    <td class="cellrowborder" valign="top" width="20.48%" headers="mcps1.2.5.1.2 "><p id="p1397433413014"><a name="p1397433413014"></a><a name="p1397433413014"></a>number  | string</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.700000000000001%" headers="mcps1.2.5.1.3 "><p id="p1497411347015"><a name="p1497411347015"></a><a name="p1497411347015"></a>No</p>
    </td>
    <td class="cellrowborder" valign="top" width="55.26%" headers="mcps1.2.5.1.4 "><p id="p6975134106"><a name="p6975134106"></a><a name="p6975134106"></a>Signal sent to the child process when the running time of a child process exceeds the timeout period. The default value is <strong id="b112802023141411"><a name="b112802023141411"></a><a name="b112802023141411"></a>SIGTERM</strong>.</p>
    </td>
    </tr>
    <tr id="row7848832602"><td class="cellrowborder" valign="top" width="14.56%" headers="mcps1.2.5.1.1 "><p id="p138496321602"><a name="p138496321602"></a><a name="p138496321602"></a>maxBuffer</p>
    </td>
    <td class="cellrowborder" valign="top" width="20.48%" headers="mcps1.2.5.1.2 "><p id="p138499328017"><a name="p138499328017"></a><a name="p138499328017"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.700000000000001%" headers="mcps1.2.5.1.3 "><p id="p784919321409"><a name="p784919321409"></a><a name="p784919321409"></a>No</p>
    </td>
    <td class="cellrowborder" valign="top" width="55.26%" headers="mcps1.2.5.1.4 "><p id="p610211102610"><a name="p610211102610"></a><a name="p610211102610"></a>Maximum buffer size for the standard input and output of the child process. When the size is exceeded, the child process will be terminated. The default value is <strong id="b17684182611617"><a name="b17684182611617"></a><a name="b17684182611617"></a>1024 * 1024</strong>.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Return values

    <a name="table214161065718"></a>
    <table><thead align="left"><tr id="row21412108574"><th class="cellrowborder" valign="top" width="20.990000000000002%" id="mcps1.1.3.1.1"><p id="p714201014577"><a name="p714201014577"></a><a name="p714201014577"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="79.01%" id="mcps1.1.3.1.2"><p id="p2014131085719"><a name="p2014131085719"></a><a name="p2014131085719"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row1715121005719"><td class="cellrowborder" valign="top" width="20.990000000000002%" headers="mcps1.1.3.1.1 "><p id="p915110115714"><a name="p915110115714"></a><a name="p915110115714"></a><a href="#section6521387200">ChildProcess</a></p>
    </td>
    <td class="cellrowborder" valign="top" width="79.01%" headers="mcps1.1.3.1.2 "><p id="p1738116141104"><a name="p1738116141104"></a><a name="p1738116141104"></a><strong id="b3379103153119"><a name="b3379103153119"></a><a name="b3379103153119"></a>ChildProcess</strong> object.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Example

    ```
    var child = process.runCmd('ls', { maxBuffer : 2 });
    var result = child.wait();
    child.getOutput.then(val=>{
        console.log("child.getOutput = " + val);
    })
    ```


## process.abort<a name="section564715329325"></a>

abort\(\): void

Aborts a process and generates a core file. This method will cause a process to exit immediately. Exercise caution when using this method.

-   Example

    ```
    process.abort();
    ```


## process.on<a name="section2394161818344"></a>

on\(type: string, listener: EventListener\): void

Stores the events triggered by the user.

-   Parameters

    <a name="table97411514490"></a>
    <table><thead align="left"><tr id="row137601516499"><th class="cellrowborder" valign="top" width="14.82%" id="mcps1.1.5.1.1"><p id="p27631520491"><a name="p27631520491"></a><a name="p27631520491"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="22.68%" id="mcps1.1.5.1.2"><p id="p167691514913"><a name="p167691514913"></a><a name="p167691514913"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="10.12%" id="mcps1.1.5.1.3"><p id="p676101554917"><a name="p676101554917"></a><a name="p676101554917"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="52.38%" id="mcps1.1.5.1.4"><p id="p9774157491"><a name="p9774157491"></a><a name="p9774157491"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row107791514917"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="p12771515144912"><a name="p12771515144912"></a><a name="p12771515144912"></a>type</p>
    </td>
    <td class="cellrowborder" valign="top" width="22.68%" headers="mcps1.1.5.1.2 "><p id="p10771815134911"><a name="p10771815134911"></a><a name="p10771815134911"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="10.12%" headers="mcps1.1.5.1.3 "><p id="p97771554918"><a name="p97771554918"></a><a name="p97771554918"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="52.38%" headers="mcps1.1.5.1.4 "><p id="p137713153495"><a name="p137713153495"></a><a name="p137713153495"></a>Type of the events to store. </p>
    </td>
    </tr>
    <tr id="row158298389506"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="p38301938105018"><a name="p38301938105018"></a><a name="p38301938105018"></a>listener</p>
    </td>
    <td class="cellrowborder" valign="top" width="22.68%" headers="mcps1.1.5.1.2 "><p id="p118305385503"><a name="p118305385503"></a><a name="p118305385503"></a><a href="#table4113811060">EventListener</a></p>
    </td>
    <td class="cellrowborder" valign="top" width="10.12%" headers="mcps1.1.5.1.3 "><p id="p18927121585115"><a name="p18927121585115"></a><a name="p18927121585115"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="52.38%" headers="mcps1.1.5.1.4 "><p id="p1883013382505"><a name="p1883013382505"></a><a name="p1883013382505"></a>Callback invoked to return the event.</p>
    </td>
    </tr>
    </tbody>
    </table>

    **Table  2**  EventListener

    <a name="table4113811060"></a>
    <table><thead align="left"><tr id="row181132115610"><th class="cellrowborder" valign="top" width="50%" id="mcps1.2.3.1.1"><p id="p5113191361"><a name="p5113191361"></a><a name="p5113191361"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="50%" id="mcps1.2.3.1.2"><p id="p161131811561"><a name="p161131811561"></a><a name="p161131811561"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row5113313614"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p241813217619"><a name="p241813217619"></a><a name="p241813217619"></a>EventListener = (evt: Object) =&gt; void</p>
    </td>
    <td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p151131011166"><a name="p151131011166"></a><a name="p151131011166"></a>Event to store.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Example

    ```
    process.on("data", (e)=>{
        console.log("data callback");
    })
    ```


## process.off<a name="section1228205293415"></a>

off\(type: string\): boolean

Deletes the event stored by the user.

-   Parameters

    <a name="table15223195413589"></a>
    <table><thead align="left"><tr id="row722305475810"><th class="cellrowborder" valign="top" width="14.82%" id="mcps1.1.5.1.1"><p id="p1722375495810"><a name="p1722375495810"></a><a name="p1722375495810"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="14.729999999999999%" id="mcps1.1.5.1.2"><p id="p1222315547583"><a name="p1222315547583"></a><a name="p1222315547583"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="9.16%" id="mcps1.1.5.1.3"><p id="p10223165410588"><a name="p10223165410588"></a><a name="p10223165410588"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="61.29%" id="mcps1.1.5.1.4"><p id="p192238546586"><a name="p192238546586"></a><a name="p192238546586"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row112232547583"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="p1014218415590"><a name="p1014218415590"></a><a name="p1014218415590"></a>type</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.729999999999999%" headers="mcps1.1.5.1.2 "><p id="p1314216415913"><a name="p1314216415913"></a><a name="p1314216415913"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="p71427411593"><a name="p71427411593"></a><a name="p71427411593"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="p14142749591"><a name="p14142749591"></a><a name="p14142749591"></a>Type of the event to delete.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Return values

    <a name="table922785415814"></a>
    <table><thead align="left"><tr id="row92271854115813"><th class="cellrowborder" valign="top" width="20.990000000000002%" id="mcps1.1.3.1.1"><p id="p1822715542582"><a name="p1822715542582"></a><a name="p1822715542582"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="79.01%" id="mcps1.1.3.1.2"><p id="p1622725445816"><a name="p1622725445816"></a><a name="p1622725445816"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row322716540586"><td class="cellrowborder" valign="top" width="20.990000000000002%" headers="mcps1.1.3.1.1 "><p id="p4227105415813"><a name="p4227105415813"></a><a name="p4227105415813"></a>boolean</p>
    </td>
    <td class="cellrowborder" valign="top" width="79.01%" headers="mcps1.1.3.1.2 "><p id="p20227155415582"><a name="p20227155415582"></a><a name="p20227155415582"></a>Returns <strong id="b9330203617455"><a name="b9330203617455"></a><a name="b9330203617455"></a>true</strong> if the event is deleted; returns <strong id="b1815112412453"><a name="b1815112412453"></a><a name="b1815112412453"></a>false</strong> otherwise.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Example

    ```
    process.on("data", (e)=>{
        console.log("data callback");
    })
    var result = process.off("data");
    ```


## process.exit<a name="section114951112414"></a>

exit\(code: number\): void

Terminates this process.

-   Parameters

    <a name="table691919201218"></a>
    <table><thead align="left"><tr id="row14919182012210"><th class="cellrowborder" valign="top" width="14.82%" id="mcps1.1.5.1.1"><p id="p79202201623"><a name="p79202201623"></a><a name="p79202201623"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="14.729999999999999%" id="mcps1.1.5.1.2"><p id="p2092052010218"><a name="p2092052010218"></a><a name="p2092052010218"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="9.16%" id="mcps1.1.5.1.3"><p id="p89201020123"><a name="p89201020123"></a><a name="p89201020123"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="61.29%" id="mcps1.1.5.1.4"><p id="p2920142015220"><a name="p2920142015220"></a><a name="p2920142015220"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row19200201225"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="p169201020724"><a name="p169201020724"></a><a name="p169201020724"></a>code</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.729999999999999%" headers="mcps1.1.5.1.2 "><p id="p18920132014217"><a name="p18920132014217"></a><a name="p18920132014217"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="p13920320023"><a name="p13920320023"></a><a name="p13920320023"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="p592018206215"><a name="p592018206215"></a><a name="p592018206215"></a>Exit code of the process.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Example

    ```
    process.exit(0);
    ```


## process.cwd<a name="section13686195712218"></a>

cwd\(\): string

Obtains the working directory of this process.

-   Example

    ```
    var path = process.cwd();
    ```


## process.chdir<a name="section43111956114115"></a>

chdir\(dir: string\): void

Changes the working directory of this process.

-   Parameters

    <a name="table202677324416"></a>
    <table><thead align="left"><tr id="row162681432743"><th class="cellrowborder" valign="top" width="14.82%" id="mcps1.1.5.1.1"><p id="p1426818321943"><a name="p1426818321943"></a><a name="p1426818321943"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="14.729999999999999%" id="mcps1.1.5.1.2"><p id="p6268173214416"><a name="p6268173214416"></a><a name="p6268173214416"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="9.16%" id="mcps1.1.5.1.3"><p id="p4268183211410"><a name="p4268183211410"></a><a name="p4268183211410"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="61.29%" id="mcps1.1.5.1.4"><p id="p16268932748"><a name="p16268932748"></a><a name="p16268932748"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row19268183217420"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="p82682321645"><a name="p82682321645"></a><a name="p82682321645"></a>dir</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.729999999999999%" headers="mcps1.1.5.1.2 "><p id="p1226813321641"><a name="p1226813321641"></a><a name="p1226813321641"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="p726915322416"><a name="p726915322416"></a><a name="p726915322416"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="p026913215412"><a name="p026913215412"></a><a name="p026913215412"></a>New working directory.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Example

    ```
    process.chdir('/system');
    ```


## process.uptime<a name="section167881439204913"></a>

uptime\(\): number

Obtains the running time of this process.

-   Return values

    <a name="table1447184441513"></a>
    <table><thead align="left"><tr id="row134819448158"><th class="cellrowborder" valign="top" width="21.02%" id="mcps1.1.3.1.1"><p id="p34812447155"><a name="p34812447155"></a><a name="p34812447155"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="78.97999999999999%" id="mcps1.1.3.1.2"><p id="p548204471513"><a name="p548204471513"></a><a name="p548204471513"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row114894411519"><td class="cellrowborder" valign="top" width="21.02%" headers="mcps1.1.3.1.1 "><p id="p848104412156"><a name="p848104412156"></a><a name="p848104412156"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="78.97999999999999%" headers="mcps1.1.3.1.2 "><p id="p17605112914167"><a name="p17605112914167"></a><a name="p17605112914167"></a>Running time of the process, in seconds.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Example

    ```
    var time = process.uptime();
    ```


## process.kill<a name="section3121181316503"></a>

kill\(pid: number, signal: number\): boolean

Sends a signal to the specified process to terminate it.

-   Parameters

    <a name="table320419413195"></a>
    <table><thead align="left"><tr id="row17204104113196"><th class="cellrowborder" valign="top" width="14.82%" id="mcps1.1.5.1.1"><p id="p192040414196"><a name="p192040414196"></a><a name="p192040414196"></a>Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="14.729999999999999%" id="mcps1.1.5.1.2"><p id="p112051141111917"><a name="p112051141111917"></a><a name="p112051141111917"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="9.16%" id="mcps1.1.5.1.3"><p id="p1820513411192"><a name="p1820513411192"></a><a name="p1820513411192"></a>Mandatory</p>
    </th>
    <th class="cellrowborder" valign="top" width="61.29%" id="mcps1.1.5.1.4"><p id="p10205104171912"><a name="p10205104171912"></a><a name="p10205104171912"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row16205124115197"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="p17205194119198"><a name="p17205194119198"></a><a name="p17205194119198"></a>pid</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.729999999999999%" headers="mcps1.1.5.1.2 "><p id="p9206154111912"><a name="p9206154111912"></a><a name="p9206154111912"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="p129831811973"><a name="p129831811973"></a><a name="p129831811973"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="p4206174101910"><a name="p4206174101910"></a><a name="p4206174101910"></a>PID of the process, to which the signal will be sent.</p>
    </td>
    </tr>
    <tr id="row468541102118"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="p36851112210"><a name="p36851112210"></a><a name="p36851112210"></a>signal</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.729999999999999%" headers="mcps1.1.5.1.2 "><p id="p1368614117219"><a name="p1368614117219"></a><a name="p1368614117219"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="p56868110217"><a name="p56868110217"></a><a name="p56868110217"></a>Yes</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="p166869118217"><a name="p166869118217"></a><a name="p166869118217"></a>Signal to send.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Return values

    <a name="table320610411199"></a>
    <table><thead align="left"><tr id="row19206941101910"><th class="cellrowborder" valign="top" width="20.990000000000002%" id="mcps1.1.3.1.1"><p id="p16207134111917"><a name="p16207134111917"></a><a name="p16207134111917"></a>Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="79.01%" id="mcps1.1.3.1.2"><p id="p3207124181912"><a name="p3207124181912"></a><a name="p3207124181912"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row15207741141911"><td class="cellrowborder" valign="top" width="20.990000000000002%" headers="mcps1.1.3.1.1 "><p id="p1620714412197"><a name="p1620714412197"></a><a name="p1620714412197"></a>boolean</p>
    </td>
    <td class="cellrowborder" valign="top" width="79.01%" headers="mcps1.1.3.1.2 "><p id="p7207194141914"><a name="p7207194141914"></a><a name="p7207194141914"></a>Returns <strong id="b5691160144712"><a name="b5691160144712"></a><a name="b5691160144712"></a>true</strong> if the signal is sent successfully; returns <strong id="b5409191810479"><a name="b5409191810479"></a><a name="b5409191810479"></a>false</strong> otherwise.</p>
    </td>
    </tr>
    </tbody>
    </table>

-   Example

    ```
    var pres = process.pid
    var result = that.kill(pres, 28)
    ```


