# 信号<a name="ZH-CN_TOPIC_0000001078912742"></a>

-   [基本概念](#section172788254307)
-   [运行机制](#section1249693812301)

## 基本概念<a name="section172788254307"></a>

信号\(signal\)是一种常用的进程间异步通信机制，用软件的方式模拟中断信号，当一个进程需要传递信息给另一个进程时，则会发送一个信号给内核，再由内核将信号传递至指定进程，而指定进程不必进行等待信号的动作。

## 运行机制<a name="section1249693812301"></a>

信号的运作流程分为三个部分，如表1：

**表 1**  信号的运作流程及相关接口（用户态接口）

<a name="table1316220185211"></a>
<table><thead align="left"><tr id="row191622182021"><th class="cellrowborder" valign="top" width="27.09270927092709%" id="mcps1.2.4.1.1"><p id="p13162121815218"><a name="p13162121815218"></a><a name="p13162121815218"></a>功能分类</p>
</th>
<th class="cellrowborder" valign="top" width="26.49264926492649%" id="mcps1.2.4.1.2"><p id="p12162618623"><a name="p12162618623"></a><a name="p12162618623"></a>接口<strong id="b197068338312"><a name="b197068338312"></a><a name="b197068338312"></a>名称</strong></p>
</th>
<th class="cellrowborder" valign="top" width="46.41464146414641%" id="mcps1.2.4.1.3"><p id="p16162118427"><a name="p16162118427"></a><a name="p16162118427"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row04981218910"><td class="cellrowborder" rowspan="2" valign="top" width="27.09270927092709%" headers="mcps1.2.4.1.1 "><p id="p6462616696"><a name="p6462616696"></a><a name="p6462616696"></a>注册信号回调函数</p>
</td>
<td class="cellrowborder" valign="top" width="26.49264926492649%" headers="mcps1.2.4.1.2 "><p id="p164931214913"><a name="p164931214913"></a><a name="p164931214913"></a>signal</p>
</td>
<td class="cellrowborder" valign="top" width="46.41464146414641%" headers="mcps1.2.4.1.3 "><p id="p8504121996"><a name="p8504121996"></a><a name="p8504121996"></a>注册信号总入口及注册和去注册某信号的回调函数。</p>
</td>
</tr>
<tr id="row5449183942119"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p5450153922110"><a name="p5450153922110"></a><a name="p5450153922110"></a>sigaction</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="p1945083962113"><a name="p1945083962113"></a><a name="p1945083962113"></a>功能同signal，但增加了信号发送相关的配置选项，目前仅支持SIGINFO结构体中的部分参数。</p>
</td>
</tr>
<tr id="row7162101814216"><td class="cellrowborder" rowspan="5" valign="top" width="27.09270927092709%" headers="mcps1.2.4.1.1 "><p id="p37331032985"><a name="p37331032985"></a><a name="p37331032985"></a>发送信号</p>
</td>
<td class="cellrowborder" valign="top" width="26.49264926492649%" headers="mcps1.2.4.1.2 "><p id="p816311185217"><a name="p816311185217"></a><a name="p816311185217"></a>kill</p>
</td>
<td class="cellrowborder" rowspan="5" align="left" valign="top" width="46.41464146414641%" headers="mcps1.2.4.1.3 "><p id="p161632181721"><a name="p161632181721"></a><a name="p161632181721"></a>发送信号给某个进程或进程内发送消息给某线程，为某进程下的线程设置信号标志位。</p>
</td>
</tr>
<tr id="row129182420243"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p149191745248"><a name="p149191745248"></a><a name="p149191745248"></a>pthread_kill</p>
</td>
</tr>
<tr id="row1026214719240"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p1226313762411"><a name="p1226313762411"></a><a name="p1226313762411"></a>raise</p>
</td>
</tr>
<tr id="row05632094242"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p45643914245"><a name="p45643914245"></a><a name="p45643914245"></a>alarm</p>
</td>
</tr>
<tr id="row3241512122417"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="p324211202414"><a name="p324211202414"></a><a name="p324211202414"></a>abort</p>
</td>
</tr>
<tr id="row101631818620"><td class="cellrowborder" valign="top" width="27.09270927092709%" headers="mcps1.2.4.1.1 "><p id="p146111936887"><a name="p146111936887"></a><a name="p146111936887"></a>触发回调</p>
</td>
<td class="cellrowborder" valign="top" width="26.49264926492649%" headers="mcps1.2.4.1.2 "><p id="p71633181125"><a name="p71633181125"></a><a name="p71633181125"></a>无</p>
</td>
<td class="cellrowborder" valign="top" width="46.41464146414641%" headers="mcps1.2.4.1.3 "><p id="p1126941694213"><a name="p1126941694213"></a><a name="p1126941694213"></a>由系统调用与中断触发，内核态与用户态切换前会先进入用户态指定函数并处理完相应回调函数，再回到原用户态程序继续运行。</p>
</td>
</tr>
</tbody>
</table>

>![](../public_sys-resources/icon-note.gif) **说明：** 
>信号机制为提供给用户态程序进程间通信的能力，故推荐使用上表1列出的用户态POSIX相关接口。
>注册回调函数：
>```
>void *signal(int sig, void (*func)(int))(int);
>```
>a. 31 号信号，该信号用来注册该进程的回调函数处理入口，不可重复注册。
>b. 0-30 号信号，该信号段用来注册与去注册回调函数。
>注册回调函数：
>```
>int sigaction(int, const struct sigaction *__restrict, struct sigaction *__restrict);
>```
>支持信号注册的配置修改和配置获取，目前仅支持SIGINFO的选项，SIGINFO内容见sigtimedwait接口内描述。
>发送信号：
>a. 进程接收信号存在默认行为，单不支持POSIX标准所给出的STOP及COTINUE、COREDUMP功能。
>b. 进程无法屏蔽SIGSTOP、SIGKILL、SIGCONT信号。
>c. 某进程后被杀死后，若其父进程不回收该进程，其转为僵尸进程。
>d. 进程接收到某信号后，直到该进程被调度后才会执行信号回调。
>e. 进程结束后会发送SIGCHLD信号给父进程，该发送动作无法取消。
>f. 无法通过信号唤醒处于DELAY状态的进程。

