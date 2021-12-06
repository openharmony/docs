# 获取进程相关的信息<a name="ZH-CN_TOPIC_0000001164806436"></a>

>![](../../public_sys-resources/icon-note.gif) **说明：** 
>从 API Version 7 开始支持。

## 导入模块<a name="zh-cn_topic_0000001164647334_s56d19203690d4782bfc74069abb6bd71"></a>

```
import process from '@ohos.process';
```

## 权限<a name="zh-cn_topic_0000001164647334_section11257113618419"></a>

无

## 属性<a name="zh-cn_topic_0000001164647334_section3317114914546"></a>

<a name="zh-cn_topic_0000001164647334_table11454105725410"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001164647334_row7455457115414"><th class="cellrowborder" valign="top" width="14.399999999999999%" id="mcps1.1.6.1.1"><p id="zh-cn_topic_0000001164647334_p84551257175410"><a name="zh-cn_topic_0000001164647334_p84551257175410"></a><a name="zh-cn_topic_0000001164647334_p84551257175410"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="21.16%" id="mcps1.1.6.1.2"><p id="zh-cn_topic_0000001164647334_p134557578549"><a name="zh-cn_topic_0000001164647334_p134557578549"></a><a name="zh-cn_topic_0000001164647334_p134557578549"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="8.39%" id="mcps1.1.6.1.3"><p id="zh-cn_topic_0000001164647334_p34551957175411"><a name="zh-cn_topic_0000001164647334_p34551957175411"></a><a name="zh-cn_topic_0000001164647334_p34551957175411"></a>可读</p>
</th>
<th class="cellrowborder" valign="top" width="8.110000000000001%" id="mcps1.1.6.1.4"><p id="zh-cn_topic_0000001164647334_p2045510572545"><a name="zh-cn_topic_0000001164647334_p2045510572545"></a><a name="zh-cn_topic_0000001164647334_p2045510572545"></a>可写</p>
</th>
<th class="cellrowborder" valign="top" width="47.94%" id="mcps1.1.6.1.5"><p id="zh-cn_topic_0000001164647334_p145575714544"><a name="zh-cn_topic_0000001164647334_p145575714544"></a><a name="zh-cn_topic_0000001164647334_p145575714544"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001164647334_row16455135745414"><td class="cellrowborder" valign="top" width="14.399999999999999%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001164647334_p17455657165416"><a name="zh-cn_topic_0000001164647334_p17455657165416"></a><a name="zh-cn_topic_0000001164647334_p17455657165416"></a>getEgid</p>
</td>
<td class="cellrowborder" valign="top" width="21.16%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001164647334_p1973158115511"><a name="zh-cn_topic_0000001164647334_p1973158115511"></a><a name="zh-cn_topic_0000001164647334_p1973158115511"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="8.39%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001164647334_p84554571547"><a name="zh-cn_topic_0000001164647334_p84554571547"></a><a name="zh-cn_topic_0000001164647334_p84554571547"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="8.110000000000001%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001164647334_p114551657185413"><a name="zh-cn_topic_0000001164647334_p114551657185413"></a><a name="zh-cn_topic_0000001164647334_p114551657185413"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="47.94%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001164647334_p14455857115415"><a name="zh-cn_topic_0000001164647334_p14455857115415"></a><a name="zh-cn_topic_0000001164647334_p14455857115415"></a>获取进程的有效组标识。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001164647334_row184551357135416"><td class="cellrowborder" valign="top" width="14.399999999999999%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001164647334_p8455135711544"><a name="zh-cn_topic_0000001164647334_p8455135711544"></a><a name="zh-cn_topic_0000001164647334_p8455135711544"></a>getEuid</p>
</td>
<td class="cellrowborder" valign="top" width="21.16%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001164647334_p6943158185519"><a name="zh-cn_topic_0000001164647334_p6943158185519"></a><a name="zh-cn_topic_0000001164647334_p6943158185519"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="8.39%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001164647334_p3455185745417"><a name="zh-cn_topic_0000001164647334_p3455185745417"></a><a name="zh-cn_topic_0000001164647334_p3455185745417"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="8.110000000000001%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001164647334_p2045585717548"><a name="zh-cn_topic_0000001164647334_p2045585717548"></a><a name="zh-cn_topic_0000001164647334_p2045585717548"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="47.94%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001164647334_p94821125817"><a name="zh-cn_topic_0000001164647334_p94821125817"></a><a name="zh-cn_topic_0000001164647334_p94821125817"></a>获取进程的有效用户身份。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001164647334_row3455357115411"><td class="cellrowborder" valign="top" width="14.399999999999999%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001164647334_p1345585785412"><a name="zh-cn_topic_0000001164647334_p1345585785412"></a><a name="zh-cn_topic_0000001164647334_p1345585785412"></a>getGid</p>
</td>
<td class="cellrowborder" valign="top" width="21.16%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001164647334_p136661259155511"><a name="zh-cn_topic_0000001164647334_p136661259155511"></a><a name="zh-cn_topic_0000001164647334_p136661259155511"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="8.39%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001164647334_p04561457185415"><a name="zh-cn_topic_0000001164647334_p04561457185415"></a><a name="zh-cn_topic_0000001164647334_p04561457185415"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="8.110000000000001%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001164647334_p64561757195414"><a name="zh-cn_topic_0000001164647334_p64561757195414"></a><a name="zh-cn_topic_0000001164647334_p64561757195414"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="47.94%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001164647334_p6455857135420"><a name="zh-cn_topic_0000001164647334_p6455857135420"></a><a name="zh-cn_topic_0000001164647334_p6455857135420"></a>获取进程的组标识。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001164647334_row1456857195411"><td class="cellrowborder" valign="top" width="14.399999999999999%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001164647334_p1145614577542"><a name="zh-cn_topic_0000001164647334_p1145614577542"></a><a name="zh-cn_topic_0000001164647334_p1145614577542"></a>getUid</p>
</td>
<td class="cellrowborder" valign="top" width="21.16%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001164647334_p105921606564"><a name="zh-cn_topic_0000001164647334_p105921606564"></a><a name="zh-cn_topic_0000001164647334_p105921606564"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="8.39%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001164647334_p16456125755417"><a name="zh-cn_topic_0000001164647334_p16456125755417"></a><a name="zh-cn_topic_0000001164647334_p16456125755417"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="8.110000000000001%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001164647334_p3456257165416"><a name="zh-cn_topic_0000001164647334_p3456257165416"></a><a name="zh-cn_topic_0000001164647334_p3456257165416"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="47.94%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001164647334_p1545610579549"><a name="zh-cn_topic_0000001164647334_p1545610579549"></a><a name="zh-cn_topic_0000001164647334_p1545610579549"></a>获取进程的用户标识。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001164647334_row134569575540"><td class="cellrowborder" valign="top" width="14.399999999999999%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001164647334_p5456155775414"><a name="zh-cn_topic_0000001164647334_p5456155775414"></a><a name="zh-cn_topic_0000001164647334_p5456155775414"></a>getGroups</p>
</td>
<td class="cellrowborder" valign="top" width="21.16%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001164647334_p1094449195614"><a name="zh-cn_topic_0000001164647334_p1094449195614"></a><a name="zh-cn_topic_0000001164647334_p1094449195614"></a>number[]</p>
</td>
<td class="cellrowborder" valign="top" width="8.39%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001164647334_p1745695725412"><a name="zh-cn_topic_0000001164647334_p1745695725412"></a><a name="zh-cn_topic_0000001164647334_p1745695725412"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="8.110000000000001%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001164647334_p19456195718542"><a name="zh-cn_topic_0000001164647334_p19456195718542"></a><a name="zh-cn_topic_0000001164647334_p19456195718542"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="47.94%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001164647334_p12456257145411"><a name="zh-cn_topic_0000001164647334_p12456257145411"></a><a name="zh-cn_topic_0000001164647334_p12456257145411"></a>获取一个带有补充组id的数组。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001164647334_row2456155735410"><td class="cellrowborder" valign="top" width="14.399999999999999%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001164647334_p145695716545"><a name="zh-cn_topic_0000001164647334_p145695716545"></a><a name="zh-cn_topic_0000001164647334_p145695716545"></a>getPid</p>
</td>
<td class="cellrowborder" valign="top" width="21.16%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001164647334_p917781619565"><a name="zh-cn_topic_0000001164647334_p917781619565"></a><a name="zh-cn_topic_0000001164647334_p917781619565"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="8.39%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001164647334_p145625711546"><a name="zh-cn_topic_0000001164647334_p145625711546"></a><a name="zh-cn_topic_0000001164647334_p145625711546"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="8.110000000000001%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001164647334_p17456105745419"><a name="zh-cn_topic_0000001164647334_p17456105745419"></a><a name="zh-cn_topic_0000001164647334_p17456105745419"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="47.94%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001164647334_p1545612577543"><a name="zh-cn_topic_0000001164647334_p1545612577543"></a><a name="zh-cn_topic_0000001164647334_p1545612577543"></a>获取当前进程的pid。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001164647334_row195001712125615"><td class="cellrowborder" valign="top" width="14.399999999999999%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001164647334_p0501171213567"><a name="zh-cn_topic_0000001164647334_p0501171213567"></a><a name="zh-cn_topic_0000001164647334_p0501171213567"></a>getPpid</p>
</td>
<td class="cellrowborder" valign="top" width="21.16%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001164647334_p69521816125613"><a name="zh-cn_topic_0000001164647334_p69521816125613"></a><a name="zh-cn_topic_0000001164647334_p69521816125613"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="8.39%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001164647334_p550171217569"><a name="zh-cn_topic_0000001164647334_p550171217569"></a><a name="zh-cn_topic_0000001164647334_p550171217569"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="8.110000000000001%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001164647334_p19501612175616"><a name="zh-cn_topic_0000001164647334_p19501612175616"></a><a name="zh-cn_topic_0000001164647334_p19501612175616"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="47.94%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001164647334_p2050111216567"><a name="zh-cn_topic_0000001164647334_p2050111216567"></a><a name="zh-cn_topic_0000001164647334_p2050111216567"></a>获取当前进程的父进程的pid。</p>
</td>
</tr>
</tbody>
</table>

## ChildProcess<a name="zh-cn_topic_0000001164647334_section6521387200"></a>

主进程可以获取子进程的标准输入输出，以及发送信号和关闭子进程。

### 属性<a name="zh-cn_topic_0000001164647334_section18482944113517"></a>

<a name="zh-cn_topic_0000001164647334_table20482104463514"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001164647334_row1348214444357"><th class="cellrowborder" valign="top" width="15.870000000000001%" id="mcps1.1.6.1.1"><p id="zh-cn_topic_0000001164647334_p184822443351"><a name="zh-cn_topic_0000001164647334_p184822443351"></a><a name="zh-cn_topic_0000001164647334_p184822443351"></a>名称</p>
</th>
<th class="cellrowborder" valign="top" width="10.86%" id="mcps1.1.6.1.2"><p id="zh-cn_topic_0000001164647334_p1648254415353"><a name="zh-cn_topic_0000001164647334_p1648254415353"></a><a name="zh-cn_topic_0000001164647334_p1648254415353"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="9.34%" id="mcps1.1.6.1.3"><p id="zh-cn_topic_0000001164647334_p9482124413355"><a name="zh-cn_topic_0000001164647334_p9482124413355"></a><a name="zh-cn_topic_0000001164647334_p9482124413355"></a>可读</p>
</th>
<th class="cellrowborder" valign="top" width="11.51%" id="mcps1.1.6.1.4"><p id="zh-cn_topic_0000001164647334_p3482124493515"><a name="zh-cn_topic_0000001164647334_p3482124493515"></a><a name="zh-cn_topic_0000001164647334_p3482124493515"></a>可写</p>
</th>
<th class="cellrowborder" valign="top" width="52.42%" id="mcps1.1.6.1.5"><p id="zh-cn_topic_0000001164647334_p12482104483513"><a name="zh-cn_topic_0000001164647334_p12482104483513"></a><a name="zh-cn_topic_0000001164647334_p12482104483513"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001164647334_row148254473513"><td class="cellrowborder" valign="top" width="15.870000000000001%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001164647334_p188761547113820"><a name="zh-cn_topic_0000001164647334_p188761547113820"></a><a name="zh-cn_topic_0000001164647334_p188761547113820"></a>pid</p>
</td>
<td class="cellrowborder" valign="top" width="10.86%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001164647334_p3482124417356"><a name="zh-cn_topic_0000001164647334_p3482124417356"></a><a name="zh-cn_topic_0000001164647334_p3482124417356"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="9.34%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001164647334_p16483194443514"><a name="zh-cn_topic_0000001164647334_p16483194443514"></a><a name="zh-cn_topic_0000001164647334_p16483194443514"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="11.51%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001164647334_p64838449351"><a name="zh-cn_topic_0000001164647334_p64838449351"></a><a name="zh-cn_topic_0000001164647334_p64838449351"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="52.42%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001164647334_p7678105615402"><a name="zh-cn_topic_0000001164647334_p7678105615402"></a><a name="zh-cn_topic_0000001164647334_p7678105615402"></a>子进程的pid。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001164647334_row1483164414352"><td class="cellrowborder" valign="top" width="15.870000000000001%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001164647334_p17483184419352"><a name="zh-cn_topic_0000001164647334_p17483184419352"></a><a name="zh-cn_topic_0000001164647334_p17483184419352"></a>ppid</p>
</td>
<td class="cellrowborder" valign="top" width="10.86%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001164647334_p9483184410355"><a name="zh-cn_topic_0000001164647334_p9483184410355"></a><a name="zh-cn_topic_0000001164647334_p9483184410355"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="9.34%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001164647334_p1348384415359"><a name="zh-cn_topic_0000001164647334_p1348384415359"></a><a name="zh-cn_topic_0000001164647334_p1348384415359"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="11.51%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001164647334_p1448312449355"><a name="zh-cn_topic_0000001164647334_p1448312449355"></a><a name="zh-cn_topic_0000001164647334_p1448312449355"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="52.42%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001164647334_p19949102034110"><a name="zh-cn_topic_0000001164647334_p19949102034110"></a><a name="zh-cn_topic_0000001164647334_p19949102034110"></a>子进程的父进程的pid。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001164647334_row13483164419353"><td class="cellrowborder" valign="top" width="15.870000000000001%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001164647334_p10260103644215"><a name="zh-cn_topic_0000001164647334_p10260103644215"></a><a name="zh-cn_topic_0000001164647334_p10260103644215"></a>exitCode</p>
</td>
<td class="cellrowborder" valign="top" width="10.86%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001164647334_p4483174443517"><a name="zh-cn_topic_0000001164647334_p4483174443517"></a><a name="zh-cn_topic_0000001164647334_p4483174443517"></a>number</p>
</td>
<td class="cellrowborder" valign="top" width="9.34%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001164647334_p1483134419353"><a name="zh-cn_topic_0000001164647334_p1483134419353"></a><a name="zh-cn_topic_0000001164647334_p1483134419353"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="11.51%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001164647334_p648354483510"><a name="zh-cn_topic_0000001164647334_p648354483510"></a><a name="zh-cn_topic_0000001164647334_p648354483510"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="52.42%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001164647334_p348319442351"><a name="zh-cn_topic_0000001164647334_p348319442351"></a><a name="zh-cn_topic_0000001164647334_p348319442351"></a>子进程的退出码。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001164647334_row1818591014310"><td class="cellrowborder" valign="top" width="15.870000000000001%" headers="mcps1.1.6.1.1 "><p id="zh-cn_topic_0000001164647334_p133731715204318"><a name="zh-cn_topic_0000001164647334_p133731715204318"></a><a name="zh-cn_topic_0000001164647334_p133731715204318"></a>killed</p>
</td>
<td class="cellrowborder" valign="top" width="10.86%" headers="mcps1.1.6.1.2 "><p id="zh-cn_topic_0000001164647334_p20186181084318"><a name="zh-cn_topic_0000001164647334_p20186181084318"></a><a name="zh-cn_topic_0000001164647334_p20186181084318"></a>boolean</p>
</td>
<td class="cellrowborder" valign="top" width="9.34%" headers="mcps1.1.6.1.3 "><p id="zh-cn_topic_0000001164647334_p61861510174314"><a name="zh-cn_topic_0000001164647334_p61861510174314"></a><a name="zh-cn_topic_0000001164647334_p61861510174314"></a>是</p>
</td>
<td class="cellrowborder" valign="top" width="11.51%" headers="mcps1.1.6.1.4 "><p id="zh-cn_topic_0000001164647334_p6186151034317"><a name="zh-cn_topic_0000001164647334_p6186151034317"></a><a name="zh-cn_topic_0000001164647334_p6186151034317"></a>否</p>
</td>
<td class="cellrowborder" valign="top" width="52.42%" headers="mcps1.1.6.1.5 "><p id="zh-cn_topic_0000001164647334_p518611015431"><a name="zh-cn_topic_0000001164647334_p518611015431"></a><a name="zh-cn_topic_0000001164647334_p518611015431"></a>父进程给子进程发信号是否成功。</p>
</td>
</tr>
</tbody>
</table>

### wait<a name="zh-cn_topic_0000001164647334_section9594134194318"></a>

wait\(\): Promise<number\>

等待子进程运行结束，返回promise对象，其值为子进程的退出码。

-   返回值：

    <a name="zh-cn_topic_0000001164647334_table37864874412"></a>
    <table><thead align="left"><tr id="zh-cn_topic_0000001164647334_row1778638104418"><th class="cellrowborder" valign="top" width="25.790000000000003%" id="mcps1.1.3.1.1"><p id="zh-cn_topic_0000001164647334_p1778613834415"><a name="zh-cn_topic_0000001164647334_p1778613834415"></a><a name="zh-cn_topic_0000001164647334_p1778613834415"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="74.21%" id="mcps1.1.3.1.2"><p id="zh-cn_topic_0000001164647334_p6786118124414"><a name="zh-cn_topic_0000001164647334_p6786118124414"></a><a name="zh-cn_topic_0000001164647334_p6786118124414"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="zh-cn_topic_0000001164647334_row678611818445"><td class="cellrowborder" valign="top" width="25.790000000000003%" headers="mcps1.1.3.1.1 "><p id="zh-cn_topic_0000001164647334_p731033633210"><a name="zh-cn_topic_0000001164647334_p731033633210"></a><a name="zh-cn_topic_0000001164647334_p731033633210"></a>Promise&lt;number&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="74.21%" headers="mcps1.1.3.1.2 "><p id="zh-cn_topic_0000001164647334_p6786118144419"><a name="zh-cn_topic_0000001164647334_p6786118144419"></a><a name="zh-cn_topic_0000001164647334_p6786118144419"></a>异步返回子进程的退出码。</p>
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


### getOutput<a name="zh-cn_topic_0000001164647334_section1732152812716"></a>

getOutput\(\): Promise<Uint8Array\>

获取子进程的标准输出。

-   返回值：

    <a name="zh-cn_topic_0000001164647334_table034112818718"></a>
    <table><thead align="left"><tr id="zh-cn_topic_0000001164647334_row10341728976"><th class="cellrowborder" valign="top" width="30.98%" id="mcps1.1.3.1.1"><p id="zh-cn_topic_0000001164647334_p234182810716"><a name="zh-cn_topic_0000001164647334_p234182810716"></a><a name="zh-cn_topic_0000001164647334_p234182810716"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="69.02000000000001%" id="mcps1.1.3.1.2"><p id="zh-cn_topic_0000001164647334_p83412820713"><a name="zh-cn_topic_0000001164647334_p83412820713"></a><a name="zh-cn_topic_0000001164647334_p83412820713"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="zh-cn_topic_0000001164647334_row183552814711"><td class="cellrowborder" valign="top" width="30.98%" headers="mcps1.1.3.1.1 "><p id="zh-cn_topic_0000001164647334_p035328878"><a name="zh-cn_topic_0000001164647334_p035328878"></a><a name="zh-cn_topic_0000001164647334_p035328878"></a>Promise&lt;Uint8Array&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="69.02000000000001%" headers="mcps1.1.3.1.2 "><p id="zh-cn_topic_0000001164647334_p83512284717"><a name="zh-cn_topic_0000001164647334_p83512284717"></a><a name="zh-cn_topic_0000001164647334_p83512284717"></a>异步返回标准输出的字节流。</p>
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


### getErrorOutput<a name="zh-cn_topic_0000001164647334_section14671040141315"></a>

getErrorOutput\(\): Promise<Uint8Array\>

getErrorOutput函数用来获取子进程的标准错误输出。

-   返回值：

    <a name="zh-cn_topic_0000001164647334_table76721340131314"></a>
    <table><thead align="left"><tr id="zh-cn_topic_0000001164647334_row46721040191315"><th class="cellrowborder" valign="top" width="30.36%" id="mcps1.1.3.1.1"><p id="zh-cn_topic_0000001164647334_p3672140111313"><a name="zh-cn_topic_0000001164647334_p3672140111313"></a><a name="zh-cn_topic_0000001164647334_p3672140111313"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="69.64%" id="mcps1.1.3.1.2"><p id="zh-cn_topic_0000001164647334_p967214407133"><a name="zh-cn_topic_0000001164647334_p967214407133"></a><a name="zh-cn_topic_0000001164647334_p967214407133"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="zh-cn_topic_0000001164647334_row767214407135"><td class="cellrowborder" valign="top" width="30.36%" headers="mcps1.1.3.1.1 "><p id="zh-cn_topic_0000001164647334_p767294017137"><a name="zh-cn_topic_0000001164647334_p767294017137"></a><a name="zh-cn_topic_0000001164647334_p767294017137"></a>Promise&lt;Uint8Array&gt;</p>
    </td>
    <td class="cellrowborder" valign="top" width="69.64%" headers="mcps1.1.3.1.2 "><p id="zh-cn_topic_0000001164647334_p9672144081314"><a name="zh-cn_topic_0000001164647334_p9672144081314"></a><a name="zh-cn_topic_0000001164647334_p9672144081314"></a>异步返回标准错误输出的字节流。</p>
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


### close<a name="zh-cn_topic_0000001164647334_section28221257121518"></a>

close\(\):  void

关闭正在运行的子进程。

-   示例：

    ```
    import process from '@ohos.process';
    var child = process.runCmd('sleep 5; ls');
    child.close();
    ```


### kill<a name="zh-cn_topic_0000001164647334_section9528134162114"></a>

kill\(signal: number | string\): void

kill函数用来发送信号给子进程，结束指定进程。

-   参数：

    <a name="zh-cn_topic_0000001164647334_table157841181443"></a>
    <table><thead align="left"><tr id="zh-cn_topic_0000001164647334_row10784188164412"><th class="cellrowborder" valign="top" width="14.82%" id="mcps1.1.5.1.1"><p id="zh-cn_topic_0000001164647334_p167847814420"><a name="zh-cn_topic_0000001164647334_p167847814420"></a><a name="zh-cn_topic_0000001164647334_p167847814420"></a>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="26.71%" id="mcps1.1.5.1.2"><p id="zh-cn_topic_0000001164647334_p078418815441"><a name="zh-cn_topic_0000001164647334_p078418815441"></a><a name="zh-cn_topic_0000001164647334_p078418815441"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="12.879999999999999%" id="mcps1.1.5.1.3"><p id="zh-cn_topic_0000001164647334_p14784082449"><a name="zh-cn_topic_0000001164647334_p14784082449"></a><a name="zh-cn_topic_0000001164647334_p14784082449"></a>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="45.59%" id="mcps1.1.5.1.4"><p id="zh-cn_topic_0000001164647334_p1878468104412"><a name="zh-cn_topic_0000001164647334_p1878468104412"></a><a name="zh-cn_topic_0000001164647334_p1878468104412"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="zh-cn_topic_0000001164647334_row27851385447"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001164647334_p2785284442"><a name="zh-cn_topic_0000001164647334_p2785284442"></a><a name="zh-cn_topic_0000001164647334_p2785284442"></a>signal</p>
    </td>
    <td class="cellrowborder" valign="top" width="26.71%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001164647334_p47857813448"><a name="zh-cn_topic_0000001164647334_p47857813448"></a><a name="zh-cn_topic_0000001164647334_p47857813448"></a>number | string</p>
    </td>
    <td class="cellrowborder" valign="top" width="12.879999999999999%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001164647334_p147859815443"><a name="zh-cn_topic_0000001164647334_p147859815443"></a><a name="zh-cn_topic_0000001164647334_p147859815443"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="45.59%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000001164647334_p2078588194411"><a name="zh-cn_topic_0000001164647334_p2078588194411"></a><a name="zh-cn_topic_0000001164647334_p2078588194411"></a>数字或字符串。</p>
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


## process.runCmd<a name="zh-cn_topic_0000001164647334_section19358326587"></a>

runCmd\(command: string, options?: \{ timeout : number, killSignal ：number | string, maxBuffer : number \}\) : ChildProcess

通过runcmd可以fork一个新的进程来运行一段shell，并返回ChildProcess对象。

-   参数：

    <a name="zh-cn_topic_0000001164647334_table1112161035716"></a>
    <table><thead align="left"><tr id="zh-cn_topic_0000001164647334_row191251055716"><th class="cellrowborder" valign="top" width="14.82%" id="mcps1.1.5.1.1"><p id="zh-cn_topic_0000001164647334_p1812191011573"><a name="zh-cn_topic_0000001164647334_p1812191011573"></a><a name="zh-cn_topic_0000001164647334_p1812191011573"></a>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="14.729999999999999%" id="mcps1.1.5.1.2"><p id="zh-cn_topic_0000001164647334_p111231095720"><a name="zh-cn_topic_0000001164647334_p111231095720"></a><a name="zh-cn_topic_0000001164647334_p111231095720"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="9.16%" id="mcps1.1.5.1.3"><p id="zh-cn_topic_0000001164647334_p812161055714"><a name="zh-cn_topic_0000001164647334_p812161055714"></a><a name="zh-cn_topic_0000001164647334_p812161055714"></a>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="61.29%" id="mcps1.1.5.1.4"><p id="zh-cn_topic_0000001164647334_p131331025718"><a name="zh-cn_topic_0000001164647334_p131331025718"></a><a name="zh-cn_topic_0000001164647334_p131331025718"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="zh-cn_topic_0000001164647334_row12131310175711"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001164647334_p131301018576"><a name="zh-cn_topic_0000001164647334_p131301018576"></a><a name="zh-cn_topic_0000001164647334_p131301018576"></a>command</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.729999999999999%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001164647334_p813151075720"><a name="zh-cn_topic_0000001164647334_p813151075720"></a><a name="zh-cn_topic_0000001164647334_p813151075720"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001164647334_p313121025712"><a name="zh-cn_topic_0000001164647334_p313121025712"></a><a name="zh-cn_topic_0000001164647334_p313121025712"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000001164647334_p1613131075715"><a name="zh-cn_topic_0000001164647334_p1613131075715"></a><a name="zh-cn_topic_0000001164647334_p1613131075715"></a>shell命令。</p>
    </td>
    </tr>
    <tr id="zh-cn_topic_0000001164647334_row187851287441"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001164647334_p187851487447"><a name="zh-cn_topic_0000001164647334_p187851487447"></a><a name="zh-cn_topic_0000001164647334_p187851487447"></a>options</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.729999999999999%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001164647334_p13785987448"><a name="zh-cn_topic_0000001164647334_p13785987448"></a><a name="zh-cn_topic_0000001164647334_p13785987448"></a>Object</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001164647334_p1878538154411"><a name="zh-cn_topic_0000001164647334_p1878538154411"></a><a name="zh-cn_topic_0000001164647334_p1878538154411"></a>否</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000001164647334_p127684914432"><a name="zh-cn_topic_0000001164647334_p127684914432"></a><a name="zh-cn_topic_0000001164647334_p127684914432"></a>相关选项参数。</p>
    </td>
    </tr>
    </tbody>
    </table>

    **表 1**  options

    <a name="zh-cn_topic_0000001164647334_table395819335512"></a>
    <table><thead align="left"><tr id="zh-cn_topic_0000001164647334_row4958133185116"><th class="cellrowborder" valign="top" width="14.56%" id="mcps1.2.5.1.1"><p id="zh-cn_topic_0000001164647334_p1795813315511"><a name="zh-cn_topic_0000001164647334_p1795813315511"></a><a name="zh-cn_topic_0000001164647334_p1795813315511"></a>名称</p>
    </th>
    <th class="cellrowborder" valign="top" width="20.48%" id="mcps1.2.5.1.2"><p id="zh-cn_topic_0000001164647334_p1895883395120"><a name="zh-cn_topic_0000001164647334_p1895883395120"></a><a name="zh-cn_topic_0000001164647334_p1895883395120"></a>参数类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="9.700000000000001%" id="mcps1.2.5.1.3"><p id="zh-cn_topic_0000001164647334_p17958633125116"><a name="zh-cn_topic_0000001164647334_p17958633125116"></a><a name="zh-cn_topic_0000001164647334_p17958633125116"></a>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="55.26%" id="mcps1.2.5.1.4"><p id="zh-cn_topic_0000001164647334_p15958133312518"><a name="zh-cn_topic_0000001164647334_p15958133312518"></a><a name="zh-cn_topic_0000001164647334_p15958133312518"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="zh-cn_topic_0000001164647334_row1958833125117"><td class="cellrowborder" valign="top" width="14.56%" headers="mcps1.2.5.1.1 "><p id="zh-cn_topic_0000001164647334_p1984204213513"><a name="zh-cn_topic_0000001164647334_p1984204213513"></a><a name="zh-cn_topic_0000001164647334_p1984204213513"></a>timeout</p>
    </td>
    <td class="cellrowborder" valign="top" width="20.48%" headers="mcps1.2.5.1.2 "><p id="zh-cn_topic_0000001164647334_p11958733115110"><a name="zh-cn_topic_0000001164647334_p11958733115110"></a><a name="zh-cn_topic_0000001164647334_p11958733115110"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.700000000000001%" headers="mcps1.2.5.1.3 "><p id="zh-cn_topic_0000001164647334_p1995817337517"><a name="zh-cn_topic_0000001164647334_p1995817337517"></a><a name="zh-cn_topic_0000001164647334_p1995817337517"></a>否</p>
    </td>
    <td class="cellrowborder" valign="top" width="55.26%" headers="mcps1.2.5.1.4 "><p id="zh-cn_topic_0000001164647334_p3958113385114"><a name="zh-cn_topic_0000001164647334_p3958113385114"></a><a name="zh-cn_topic_0000001164647334_p3958113385114"></a>子进程运行的ms数，当子进程运行时间超出此时间，则父进程发送killSignal信号给子进程。timeout默认为0。</p>
    </td>
    </tr>
    <tr id="zh-cn_topic_0000001164647334_row15974103410012"><td class="cellrowborder" valign="top" width="14.56%" headers="mcps1.2.5.1.1 "><p id="zh-cn_topic_0000001164647334_p18974173412018"><a name="zh-cn_topic_0000001164647334_p18974173412018"></a><a name="zh-cn_topic_0000001164647334_p18974173412018"></a>killSignal</p>
    </td>
    <td class="cellrowborder" valign="top" width="20.48%" headers="mcps1.2.5.1.2 "><p id="zh-cn_topic_0000001164647334_p1397433413014"><a name="zh-cn_topic_0000001164647334_p1397433413014"></a><a name="zh-cn_topic_0000001164647334_p1397433413014"></a>number  | string</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.700000000000001%" headers="mcps1.2.5.1.3 "><p id="zh-cn_topic_0000001164647334_p1497411347015"><a name="zh-cn_topic_0000001164647334_p1497411347015"></a><a name="zh-cn_topic_0000001164647334_p1497411347015"></a>否</p>
    </td>
    <td class="cellrowborder" valign="top" width="55.26%" headers="mcps1.2.5.1.4 "><p id="zh-cn_topic_0000001164647334_p6975134106"><a name="zh-cn_topic_0000001164647334_p6975134106"></a><a name="zh-cn_topic_0000001164647334_p6975134106"></a>子进程运行时间超出timeout时，父进程发送killSignal 信号给子进程。killSignal 默认为'SIGTERM'。</p>
    </td>
    </tr>
    <tr id="zh-cn_topic_0000001164647334_row7848832602"><td class="cellrowborder" valign="top" width="14.56%" headers="mcps1.2.5.1.1 "><p id="zh-cn_topic_0000001164647334_p138496321602"><a name="zh-cn_topic_0000001164647334_p138496321602"></a><a name="zh-cn_topic_0000001164647334_p138496321602"></a>maxBuffer</p>
    </td>
    <td class="cellrowborder" valign="top" width="20.48%" headers="mcps1.2.5.1.2 "><p id="zh-cn_topic_0000001164647334_p138499328017"><a name="zh-cn_topic_0000001164647334_p138499328017"></a><a name="zh-cn_topic_0000001164647334_p138499328017"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.700000000000001%" headers="mcps1.2.5.1.3 "><p id="zh-cn_topic_0000001164647334_p784919321409"><a name="zh-cn_topic_0000001164647334_p784919321409"></a><a name="zh-cn_topic_0000001164647334_p784919321409"></a>否</p>
    </td>
    <td class="cellrowborder" valign="top" width="55.26%" headers="mcps1.2.5.1.4 "><p id="zh-cn_topic_0000001164647334_p610211102610"><a name="zh-cn_topic_0000001164647334_p610211102610"></a><a name="zh-cn_topic_0000001164647334_p610211102610"></a>子进程标准输入输出的最大缓冲区大小，当超出此大小时则终止子进程。maxBuffer默认1024*1024。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   返回值：

    <a name="zh-cn_topic_0000001164647334_table214161065718"></a>
    <table><thead align="left"><tr id="zh-cn_topic_0000001164647334_row21412108574"><th class="cellrowborder" valign="top" width="20.990000000000002%" id="mcps1.1.3.1.1"><p id="zh-cn_topic_0000001164647334_p714201014577"><a name="zh-cn_topic_0000001164647334_p714201014577"></a><a name="zh-cn_topic_0000001164647334_p714201014577"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="79.01%" id="mcps1.1.3.1.2"><p id="zh-cn_topic_0000001164647334_p2014131085719"><a name="zh-cn_topic_0000001164647334_p2014131085719"></a><a name="zh-cn_topic_0000001164647334_p2014131085719"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="zh-cn_topic_0000001164647334_row1715121005719"><td class="cellrowborder" valign="top" width="20.990000000000002%" headers="mcps1.1.3.1.1 "><p id="zh-cn_topic_0000001164647334_p915110115714"><a name="zh-cn_topic_0000001164647334_p915110115714"></a><a name="zh-cn_topic_0000001164647334_p915110115714"></a><a href="#zh-cn_topic_0000001164647334_section6521387200">ChildProcess</a></p>
    </td>
    <td class="cellrowborder" valign="top" width="79.01%" headers="mcps1.1.3.1.2 "><p id="zh-cn_topic_0000001164647334_p1738116141104"><a name="zh-cn_topic_0000001164647334_p1738116141104"></a><a name="zh-cn_topic_0000001164647334_p1738116141104"></a>子进程对象。</p>
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


## process.abort<a name="zh-cn_topic_0000001164647334_section564715329325"></a>

abort\(\): void

该方法会导致进程立即退出并生成一个核心文件，谨慎使用。

-   示例：

    ```
    import process from '@ohos.process';
    process.abort();
    ```


## process.on<a name="zh-cn_topic_0000001164647334_section2394161818344"></a>

on\(type: string, listener: EventListener\): void

用该方法来存储用户所触发的事件。

-   参数：

    <a name="zh-cn_topic_0000001164647334_table97411514490"></a>
    <table><thead align="left"><tr id="zh-cn_topic_0000001164647334_row137601516499"><th class="cellrowborder" valign="top" width="14.82%" id="mcps1.1.5.1.1"><p id="zh-cn_topic_0000001164647334_p27631520491"><a name="zh-cn_topic_0000001164647334_p27631520491"></a><a name="zh-cn_topic_0000001164647334_p27631520491"></a>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="22.68%" id="mcps1.1.5.1.2"><p id="zh-cn_topic_0000001164647334_p167691514913"><a name="zh-cn_topic_0000001164647334_p167691514913"></a><a name="zh-cn_topic_0000001164647334_p167691514913"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="10.12%" id="mcps1.1.5.1.3"><p id="zh-cn_topic_0000001164647334_p676101554917"><a name="zh-cn_topic_0000001164647334_p676101554917"></a><a name="zh-cn_topic_0000001164647334_p676101554917"></a>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="52.38%" id="mcps1.1.5.1.4"><p id="zh-cn_topic_0000001164647334_p9774157491"><a name="zh-cn_topic_0000001164647334_p9774157491"></a><a name="zh-cn_topic_0000001164647334_p9774157491"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="zh-cn_topic_0000001164647334_row107791514917"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001164647334_p12771515144912"><a name="zh-cn_topic_0000001164647334_p12771515144912"></a><a name="zh-cn_topic_0000001164647334_p12771515144912"></a>type</p>
    </td>
    <td class="cellrowborder" valign="top" width="22.68%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001164647334_p10771815134911"><a name="zh-cn_topic_0000001164647334_p10771815134911"></a><a name="zh-cn_topic_0000001164647334_p10771815134911"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="10.12%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001164647334_p97771554918"><a name="zh-cn_topic_0000001164647334_p97771554918"></a><a name="zh-cn_topic_0000001164647334_p97771554918"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="52.38%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000001164647334_p137713153495"><a name="zh-cn_topic_0000001164647334_p137713153495"></a><a name="zh-cn_topic_0000001164647334_p137713153495"></a>存储事件的type。</p>
    </td>
    </tr>
    <tr id="zh-cn_topic_0000001164647334_row158298389506"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001164647334_p38301938105018"><a name="zh-cn_topic_0000001164647334_p38301938105018"></a><a name="zh-cn_topic_0000001164647334_p38301938105018"></a>listener</p>
    </td>
    <td class="cellrowborder" valign="top" width="22.68%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001164647334_p118305385503"><a name="zh-cn_topic_0000001164647334_p118305385503"></a><a name="zh-cn_topic_0000001164647334_p118305385503"></a><a href="#zh-cn_topic_0000001164647334_table4113811060">EventListener</a></p>
    </td>
    <td class="cellrowborder" valign="top" width="10.12%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001164647334_p18927121585115"><a name="zh-cn_topic_0000001164647334_p18927121585115"></a><a name="zh-cn_topic_0000001164647334_p18927121585115"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="52.38%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000001164647334_p1883013382505"><a name="zh-cn_topic_0000001164647334_p1883013382505"></a><a name="zh-cn_topic_0000001164647334_p1883013382505"></a>回调的事件。</p>
    </td>
    </tr>
    </tbody>
    </table>

    **表 2**  EventListener

    <a name="zh-cn_topic_0000001164647334_table4113811060"></a>
    <table><thead align="left"><tr id="zh-cn_topic_0000001164647334_row181132115610"><th class="cellrowborder" valign="top" width="50%" id="mcps1.2.3.1.1"><p id="zh-cn_topic_0000001164647334_p5113191361"><a name="zh-cn_topic_0000001164647334_p5113191361"></a><a name="zh-cn_topic_0000001164647334_p5113191361"></a>名称</p>
    </th>
    <th class="cellrowborder" valign="top" width="50%" id="mcps1.2.3.1.2"><p id="zh-cn_topic_0000001164647334_p161131811561"><a name="zh-cn_topic_0000001164647334_p161131811561"></a><a name="zh-cn_topic_0000001164647334_p161131811561"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="zh-cn_topic_0000001164647334_row5113313614"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="zh-cn_topic_0000001164647334_p241813217619"><a name="zh-cn_topic_0000001164647334_p241813217619"></a><a name="zh-cn_topic_0000001164647334_p241813217619"></a>EventListener = (evt: Object) <span>=</span><span>&gt;</span> void</p>
    </td>
    <td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="zh-cn_topic_0000001164647334_p12175123914388"><a name="zh-cn_topic_0000001164647334_p12175123914388"></a><a name="zh-cn_topic_0000001164647334_p12175123914388"></a>用户存储的事件</p>
    </td>
    </tr>
    </tbody>
    </table>

-   示例：

    ```
    import process from '@ohos.process';
    process.on("data", (e)=>{
        console.log("data callback);
    })
    ```


## process.off<a name="zh-cn_topic_0000001164647334_section1228205293415"></a>

off\(type: string\): boolean

用该方法来删除用户存储的事件。

-   参数：

    <a name="zh-cn_topic_0000001164647334_table15223195413589"></a>
    <table><thead align="left"><tr id="zh-cn_topic_0000001164647334_row722305475810"><th class="cellrowborder" valign="top" width="14.82%" id="mcps1.1.5.1.1"><p id="zh-cn_topic_0000001164647334_p1722375495810"><a name="zh-cn_topic_0000001164647334_p1722375495810"></a><a name="zh-cn_topic_0000001164647334_p1722375495810"></a>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="14.729999999999999%" id="mcps1.1.5.1.2"><p id="zh-cn_topic_0000001164647334_p1222315547583"><a name="zh-cn_topic_0000001164647334_p1222315547583"></a><a name="zh-cn_topic_0000001164647334_p1222315547583"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="9.16%" id="mcps1.1.5.1.3"><p id="zh-cn_topic_0000001164647334_p10223165410588"><a name="zh-cn_topic_0000001164647334_p10223165410588"></a><a name="zh-cn_topic_0000001164647334_p10223165410588"></a>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="61.29%" id="mcps1.1.5.1.4"><p id="zh-cn_topic_0000001164647334_p192238546586"><a name="zh-cn_topic_0000001164647334_p192238546586"></a><a name="zh-cn_topic_0000001164647334_p192238546586"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="zh-cn_topic_0000001164647334_row112232547583"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001164647334_p1014218415590"><a name="zh-cn_topic_0000001164647334_p1014218415590"></a><a name="zh-cn_topic_0000001164647334_p1014218415590"></a>type</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.729999999999999%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001164647334_p1314216415913"><a name="zh-cn_topic_0000001164647334_p1314216415913"></a><a name="zh-cn_topic_0000001164647334_p1314216415913"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001164647334_p71427411593"><a name="zh-cn_topic_0000001164647334_p71427411593"></a><a name="zh-cn_topic_0000001164647334_p71427411593"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000001164647334_p14142749591"><a name="zh-cn_topic_0000001164647334_p14142749591"></a><a name="zh-cn_topic_0000001164647334_p14142749591"></a>删除事件的type。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   返回值：

    <a name="zh-cn_topic_0000001164647334_table922785415814"></a>
    <table><thead align="left"><tr id="zh-cn_topic_0000001164647334_row92271854115813"><th class="cellrowborder" valign="top" width="20.990000000000002%" id="mcps1.1.3.1.1"><p id="zh-cn_topic_0000001164647334_p1822715542582"><a name="zh-cn_topic_0000001164647334_p1822715542582"></a><a name="zh-cn_topic_0000001164647334_p1822715542582"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="79.01%" id="mcps1.1.3.1.2"><p id="zh-cn_topic_0000001164647334_p1622725445816"><a name="zh-cn_topic_0000001164647334_p1622725445816"></a><a name="zh-cn_topic_0000001164647334_p1622725445816"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="zh-cn_topic_0000001164647334_row322716540586"><td class="cellrowborder" valign="top" width="20.990000000000002%" headers="mcps1.1.3.1.1 "><p id="zh-cn_topic_0000001164647334_p4227105415813"><a name="zh-cn_topic_0000001164647334_p4227105415813"></a><a name="zh-cn_topic_0000001164647334_p4227105415813"></a>boolean</p>
    </td>
    <td class="cellrowborder" valign="top" width="79.01%" headers="mcps1.1.3.1.2 "><p id="zh-cn_topic_0000001164647334_p20227155415582"><a name="zh-cn_topic_0000001164647334_p20227155415582"></a><a name="zh-cn_topic_0000001164647334_p20227155415582"></a>事件是否删除成功。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   示例：

    ```
    import process from '@ohos.process';
    process.on("data", (e)=>{
        console.log("data callback);
    })
    var result = process.off("data");
    ```


## process.exit<a name="zh-cn_topic_0000001164647334_section114951112414"></a>

exit\(code: number\): void

用该方法终止程序，谨慎使用。

-   参数：

    <a name="zh-cn_topic_0000001164647334_table691919201218"></a>
    <table><thead align="left"><tr id="zh-cn_topic_0000001164647334_row14919182012210"><th class="cellrowborder" valign="top" width="14.82%" id="mcps1.1.5.1.1"><p id="zh-cn_topic_0000001164647334_p79202201623"><a name="zh-cn_topic_0000001164647334_p79202201623"></a><a name="zh-cn_topic_0000001164647334_p79202201623"></a>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="14.729999999999999%" id="mcps1.1.5.1.2"><p id="zh-cn_topic_0000001164647334_p2092052010218"><a name="zh-cn_topic_0000001164647334_p2092052010218"></a><a name="zh-cn_topic_0000001164647334_p2092052010218"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="9.16%" id="mcps1.1.5.1.3"><p id="zh-cn_topic_0000001164647334_p89201020123"><a name="zh-cn_topic_0000001164647334_p89201020123"></a><a name="zh-cn_topic_0000001164647334_p89201020123"></a>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="61.29%" id="mcps1.1.5.1.4"><p id="zh-cn_topic_0000001164647334_p2920142015220"><a name="zh-cn_topic_0000001164647334_p2920142015220"></a><a name="zh-cn_topic_0000001164647334_p2920142015220"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="zh-cn_topic_0000001164647334_row19200201225"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001164647334_p169201020724"><a name="zh-cn_topic_0000001164647334_p169201020724"></a><a name="zh-cn_topic_0000001164647334_p169201020724"></a>code</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.729999999999999%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001164647334_p18920132014217"><a name="zh-cn_topic_0000001164647334_p18920132014217"></a><a name="zh-cn_topic_0000001164647334_p18920132014217"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001164647334_p13920320023"><a name="zh-cn_topic_0000001164647334_p13920320023"></a><a name="zh-cn_topic_0000001164647334_p13920320023"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000001164647334_p592018206215"><a name="zh-cn_topic_0000001164647334_p592018206215"></a><a name="zh-cn_topic_0000001164647334_p592018206215"></a>进程的退出码。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   示例：

    ```
    import process from '@ohos.process';
    process.exit(0);
    ```


## process.cwd<a name="zh-cn_topic_0000001164647334_section13686195712218"></a>

cwd\(\): string

用该方法获取进程的工作目录。

-   示例：

    ```
    import process from '@ohos.process';
    var path = process.cwd();
    ```


## process.chdir<a name="zh-cn_topic_0000001164647334_section43111956114115"></a>

chdir\(dir: string\): void

用该方法更改进程的当前工作目录。

-   参数：

    <a name="zh-cn_topic_0000001164647334_table202677324416"></a>
    <table><thead align="left"><tr id="zh-cn_topic_0000001164647334_row162681432743"><th class="cellrowborder" valign="top" width="14.82%" id="mcps1.1.5.1.1"><p id="zh-cn_topic_0000001164647334_p1426818321943"><a name="zh-cn_topic_0000001164647334_p1426818321943"></a><a name="zh-cn_topic_0000001164647334_p1426818321943"></a>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="14.729999999999999%" id="mcps1.1.5.1.2"><p id="zh-cn_topic_0000001164647334_p6268173214416"><a name="zh-cn_topic_0000001164647334_p6268173214416"></a><a name="zh-cn_topic_0000001164647334_p6268173214416"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="9.16%" id="mcps1.1.5.1.3"><p id="zh-cn_topic_0000001164647334_p4268183211410"><a name="zh-cn_topic_0000001164647334_p4268183211410"></a><a name="zh-cn_topic_0000001164647334_p4268183211410"></a>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="61.29%" id="mcps1.1.5.1.4"><p id="zh-cn_topic_0000001164647334_p16268932748"><a name="zh-cn_topic_0000001164647334_p16268932748"></a><a name="zh-cn_topic_0000001164647334_p16268932748"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="zh-cn_topic_0000001164647334_row19268183217420"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001164647334_p82682321645"><a name="zh-cn_topic_0000001164647334_p82682321645"></a><a name="zh-cn_topic_0000001164647334_p82682321645"></a>dir</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.729999999999999%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001164647334_p1226813321641"><a name="zh-cn_topic_0000001164647334_p1226813321641"></a><a name="zh-cn_topic_0000001164647334_p1226813321641"></a>string</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001164647334_p726915322416"><a name="zh-cn_topic_0000001164647334_p726915322416"></a><a name="zh-cn_topic_0000001164647334_p726915322416"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000001164647334_p026913215412"><a name="zh-cn_topic_0000001164647334_p026913215412"></a><a name="zh-cn_topic_0000001164647334_p026913215412"></a>路径。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   示例：

    ```
    import process from '@ohos.process';
    process.chdir('/system');
    ```


## process.uptime<a name="zh-cn_topic_0000001164647334_section167881439204913"></a>

uptime\(\): number

获取当前系统已运行的秒数。

-   返回值：

    <a name="zh-cn_topic_0000001164647334_table1447184441513"></a>
    <table><thead align="left"><tr id="zh-cn_topic_0000001164647334_row134819448158"><th class="cellrowborder" valign="top" width="21.02%" id="mcps1.1.3.1.1"><p id="zh-cn_topic_0000001164647334_p34812447155"><a name="zh-cn_topic_0000001164647334_p34812447155"></a><a name="zh-cn_topic_0000001164647334_p34812447155"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="78.97999999999999%" id="mcps1.1.3.1.2"><p id="zh-cn_topic_0000001164647334_p548204471513"><a name="zh-cn_topic_0000001164647334_p548204471513"></a><a name="zh-cn_topic_0000001164647334_p548204471513"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="zh-cn_topic_0000001164647334_row114894411519"><td class="cellrowborder" valign="top" width="21.02%" headers="mcps1.1.3.1.1 "><p id="zh-cn_topic_0000001164647334_p848104412156"><a name="zh-cn_topic_0000001164647334_p848104412156"></a><a name="zh-cn_topic_0000001164647334_p848104412156"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="78.97999999999999%" headers="mcps1.1.3.1.2 "><p id="zh-cn_topic_0000001164647334_p17605112914167"><a name="zh-cn_topic_0000001164647334_p17605112914167"></a><a name="zh-cn_topic_0000001164647334_p17605112914167"></a>当前系统已运行的秒数。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   示例：

    ```
    import process from '@ohos.process';
    var time = process.uptime();
    ```


## process.kill<a name="zh-cn_topic_0000001164647334_section3121181316503"></a>

kill\(pid: number，signal: number \): boolean

用该方法发送signal到指定的进程，结束指定进程。

-   参数：

    <a name="zh-cn_topic_0000001164647334_table320419413195"></a>
    <table><thead align="left"><tr id="zh-cn_topic_0000001164647334_row17204104113196"><th class="cellrowborder" valign="top" width="14.82%" id="mcps1.1.5.1.1"><p id="zh-cn_topic_0000001164647334_p192040414196"><a name="zh-cn_topic_0000001164647334_p192040414196"></a><a name="zh-cn_topic_0000001164647334_p192040414196"></a>参数名</p>
    </th>
    <th class="cellrowborder" valign="top" width="14.729999999999999%" id="mcps1.1.5.1.2"><p id="zh-cn_topic_0000001164647334_p112051141111917"><a name="zh-cn_topic_0000001164647334_p112051141111917"></a><a name="zh-cn_topic_0000001164647334_p112051141111917"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="9.16%" id="mcps1.1.5.1.3"><p id="zh-cn_topic_0000001164647334_p1820513411192"><a name="zh-cn_topic_0000001164647334_p1820513411192"></a><a name="zh-cn_topic_0000001164647334_p1820513411192"></a>必填</p>
    </th>
    <th class="cellrowborder" valign="top" width="61.29%" id="mcps1.1.5.1.4"><p id="zh-cn_topic_0000001164647334_p10205104171912"><a name="zh-cn_topic_0000001164647334_p10205104171912"></a><a name="zh-cn_topic_0000001164647334_p10205104171912"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="zh-cn_topic_0000001164647334_row16205124115197"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001164647334_p17205194119198"><a name="zh-cn_topic_0000001164647334_p17205194119198"></a><a name="zh-cn_topic_0000001164647334_p17205194119198"></a>pid</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.729999999999999%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001164647334_p9206154111912"><a name="zh-cn_topic_0000001164647334_p9206154111912"></a><a name="zh-cn_topic_0000001164647334_p9206154111912"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001164647334_p129831811973"><a name="zh-cn_topic_0000001164647334_p129831811973"></a><a name="zh-cn_topic_0000001164647334_p129831811973"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000001164647334_p4206174101910"><a name="zh-cn_topic_0000001164647334_p4206174101910"></a><a name="zh-cn_topic_0000001164647334_p4206174101910"></a>进程的id。</p>
    </td>
    </tr>
    <tr id="zh-cn_topic_0000001164647334_row468541102118"><td class="cellrowborder" valign="top" width="14.82%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001164647334_p36851112210"><a name="zh-cn_topic_0000001164647334_p36851112210"></a><a name="zh-cn_topic_0000001164647334_p36851112210"></a>signal</p>
    </td>
    <td class="cellrowborder" valign="top" width="14.729999999999999%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001164647334_p1368614117219"><a name="zh-cn_topic_0000001164647334_p1368614117219"></a><a name="zh-cn_topic_0000001164647334_p1368614117219"></a>number</p>
    </td>
    <td class="cellrowborder" valign="top" width="9.16%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001164647334_p56868110217"><a name="zh-cn_topic_0000001164647334_p56868110217"></a><a name="zh-cn_topic_0000001164647334_p56868110217"></a>是</p>
    </td>
    <td class="cellrowborder" valign="top" width="61.29%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000001164647334_p166869118217"><a name="zh-cn_topic_0000001164647334_p166869118217"></a><a name="zh-cn_topic_0000001164647334_p166869118217"></a>发送的信号。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   返回值：

    <a name="zh-cn_topic_0000001164647334_table320610411199"></a>
    <table><thead align="left"><tr id="zh-cn_topic_0000001164647334_row19206941101910"><th class="cellrowborder" valign="top" width="20.990000000000002%" id="mcps1.1.3.1.1"><p id="zh-cn_topic_0000001164647334_p16207134111917"><a name="zh-cn_topic_0000001164647334_p16207134111917"></a><a name="zh-cn_topic_0000001164647334_p16207134111917"></a>类型</p>
    </th>
    <th class="cellrowborder" valign="top" width="79.01%" id="mcps1.1.3.1.2"><p id="zh-cn_topic_0000001164647334_p3207124181912"><a name="zh-cn_topic_0000001164647334_p3207124181912"></a><a name="zh-cn_topic_0000001164647334_p3207124181912"></a>说明</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="zh-cn_topic_0000001164647334_row15207741141911"><td class="cellrowborder" valign="top" width="20.990000000000002%" headers="mcps1.1.3.1.1 "><p id="zh-cn_topic_0000001164647334_p1620714412197"><a name="zh-cn_topic_0000001164647334_p1620714412197"></a><a name="zh-cn_topic_0000001164647334_p1620714412197"></a>boolean</p>
    </td>
    <td class="cellrowborder" valign="top" width="79.01%" headers="mcps1.1.3.1.2 "><p id="zh-cn_topic_0000001164647334_p7207194141914"><a name="zh-cn_topic_0000001164647334_p7207194141914"></a><a name="zh-cn_topic_0000001164647334_p7207194141914"></a>信号是否发送成功。</p>
    </td>
    </tr>
    </tbody>
    </table>

-   示例：

    ```
    import process from '@ohos.process'
    var pres = process.getPid
    var result = that.kill(pres, 28)
    ```


