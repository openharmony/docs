# HiCollie开发指导<a name="ZH-CN_TOPIC_0000001231255509"></a>


## 概述<a name="section3432134085116"></a>

HiCollie提供了软件看门狗功能。针对系统服务死锁、应用主线程阻塞，用户业务流程超时等故障，HiCollie提供了一套统一的用于故障检测和故障日志生成的框架，提供软件超时故障日志，辅助定位软件超时问题。

## 接口说明<a name="section139261151145116"></a>

**表 1**  C++接口功能描述表

<a name="table19452225011"></a>
<table><thead align="left"><tr id="row1517803543518"><th class="cellrowborder" valign="top" width="19.698030196980305%" id="mcps1.2.4.1.1"><p id="p484763319529"><a name="p484763319529"></a><a name="p484763319529"></a>所属类</p>
</th>
<th class="cellrowborder" valign="top" width="35.82641735826417%" id="mcps1.2.4.1.2"><p id="p1684719339523"><a name="p1684719339523"></a><a name="p1684719339523"></a>接口定义</p>
</th>
<th class="cellrowborder" valign="top" width="44.47555244475552%" id="mcps1.2.4.1.3"><p id="p284773315220"><a name="p284773315220"></a><a name="p284773315220"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row1361184632117"><td class="cellrowborder" valign="top" width="19.698030196980305%" headers="mcps1.2.4.1.1 "><p id="p6700155032113"><a name="p6700155032113"></a><a name="p6700155032113"></a>XCollieChecker类接口</p>
</td>
<td class="cellrowborder" valign="top" width="35.82641735826417%" headers="mcps1.2.4.1.2 "><p id="p18699115019217"><a name="p18699115019217"></a><a name="p18699115019217"></a>virtual void CheckBlock()</p>
</td>
<td class="cellrowborder" valign="top" width="44.47555244475552%" headers="mcps1.2.4.1.3 "><p id="p18700175062115"><a name="p18700175062115"></a><a name="p18700175062115"></a>接口功能：卡死检测回调函数。</p>
<p id="p13700125012216"><a name="p13700125012216"></a><a name="p13700125012216"></a>输入参数：无。</p>
<p id="p13700650162114"><a name="p13700650162114"></a><a name="p13700650162114"></a>输出参数：无。</p>
<p id="p3700850192115"><a name="p3700850192115"></a><a name="p3700850192115"></a>返回值：无。</p>
</td>
</tr>
<tr id="row8945182185017"><td class="cellrowborder" valign="top" width="19.698030196980305%" headers="mcps1.2.4.1.1 "><p id="p79451227506"><a name="p79451227506"></a><a name="p79451227506"></a>XCollieChecker类接口</p>
</td>
<td class="cellrowborder" valign="top" width="35.82641735826417%" headers="mcps1.2.4.1.2 "><p id="p647534064612"><a name="p647534064612"></a><a name="p647534064612"></a>virtual void CheckThreadBlock()</p>
</td>
<td class="cellrowborder" valign="top" width="44.47555244475552%" headers="mcps1.2.4.1.3 "><p id="p127630177475"><a name="p127630177475"></a><a name="p127630177475"></a>接口功能：线程卡死检测回调函数。</p>
<p id="p18763111794719"><a name="p18763111794719"></a><a name="p18763111794719"></a>输入参数：无。</p>
<p id="p87631176478"><a name="p87631176478"></a><a name="p87631176478"></a>输出参数：无。</p>
<p id="p3764111718473"><a name="p3764111718473"></a><a name="p3764111718473"></a>返回值：无。</p>
</td>
</tr>
<tr id="row149924222486"><td class="cellrowborder" valign="top" width="19.698030196980305%" headers="mcps1.2.4.1.1 "><p id="p11643173114810"><a name="p11643173114810"></a><a name="p11643173114810"></a>XCollie类接口</p>
</td>
<td class="cellrowborder" valign="top" width="35.82641735826417%" headers="mcps1.2.4.1.2 "><p id="p16289114074812"><a name="p16289114074812"></a><a name="p16289114074812"></a>void RegisterXCollieChecker(const sptr&lt;XCollieChecker&gt; &amp;checker, unsigned int type)</p>
</td>
<td class="cellrowborder" valign="top" width="44.47555244475552%" headers="mcps1.2.4.1.3 "><p id="p186437319482"><a name="p186437319482"></a><a name="p186437319482"></a>接口功能：线程卡死检测回调函数注册。</p>
<p id="p112011591133"><a name="p112011591133"></a><a name="p112011591133"></a>输入参数：</p>
<a name="ul7783192181413"></a><a name="ul7783192181413"></a><ul id="ul7783192181413"><li>checker：XCollieChecker实例指针。</li><li>type：卡死检测类型，取值设置为XCOLLIE_THREAD。</li></ul>
<p id="p166439314482"><a name="p166439314482"></a><a name="p166439314482"></a>输出参数：无。</p>
<p id="p564393112485"><a name="p564393112485"></a><a name="p564393112485"></a>返回值：无。</p>
</td>
</tr>
<tr id="row594519275012"><td class="cellrowborder" valign="top" width="19.698030196980305%" headers="mcps1.2.4.1.1 "><p id="p294512211505"><a name="p294512211505"></a><a name="p294512211505"></a>XCollie类接口</p>
</td>
<td class="cellrowborder" valign="top" width="35.82641735826417%" headers="mcps1.2.4.1.2 "><p id="p81561310145215"><a name="p81561310145215"></a><a name="p81561310145215"></a>int SetTimer(const std::string &amp;name, unsigned int timeout, std::function&lt;void (void *)&gt; func, void *arg, unsigned int flag)</p>
</td>
<td class="cellrowborder" valign="top" width="44.47555244475552%" headers="mcps1.2.4.1.3 "><p id="p174279246538"><a name="p174279246538"></a><a name="p174279246538"></a>接口功能：添加定时器。</p>
<p id="p1998141221410"><a name="p1998141221410"></a><a name="p1998141221410"></a>输入参数：</p>
<a name="ul845512153147"></a><a name="ul845512153147"></a><ul id="ul845512153147"><li>name：定时器名称。</li><li>timeout：超时时间，单位为秒。</li><li>func：超时回调函数。</li><li>arg：超时回调函数参数指针。</li><li>flag：定时器操作类型。<p id="p1242762435310"><a name="p1242762435310"></a><a name="p1242762435310"></a>XCOLLIE_FLAG_DEFAULT  // 其他三个选项功能之和</p>
<p id="p1542712435312"><a name="p1542712435312"></a><a name="p1542712435312"></a>XCOLLIE_FLAG_NOOP // 仅调用超时回调函数</p>
<p id="p15427112416531"><a name="p15427112416531"></a><a name="p15427112416531"></a>XCOLLIE_FLAG_LOG //  生成超时故障日志</p>
<p id="p242762455314"><a name="p242762455314"></a><a name="p242762455314"></a>XCOLLIE_FLAG_RECOVERY //  进程退出</p>
</li></ul>
<p id="p15427102445311"><a name="p15427102445311"></a><a name="p15427102445311"></a>输出参数：无。</p>
<p id="p144271424155316"><a name="p144271424155316"></a><a name="p144271424155316"></a>返回值：成功返回定时器标识，失败返回-1。</p>
</td>
</tr>
<tr id="row1294692165010"><td class="cellrowborder" valign="top" width="19.698030196980305%" headers="mcps1.2.4.1.1 "><p id="p19461929506"><a name="p19461929506"></a><a name="p19461929506"></a>XCollie类接口</p>
</td>
<td class="cellrowborder" valign="top" width="35.82641735826417%" headers="mcps1.2.4.1.2 "><p id="p119467215012"><a name="p119467215012"></a><a name="p119467215012"></a>bool UpdateTimer(int id, unsigned int timeout)</p>
</td>
<td class="cellrowborder" valign="top" width="44.47555244475552%" headers="mcps1.2.4.1.3 "><p id="p3831253185713"><a name="p3831253185713"></a><a name="p3831253185713"></a>接口功能：更新定时器。</p>
<p id="p10649172815148"><a name="p10649172815148"></a><a name="p10649172815148"></a>输入参数：</p>
<a name="ul1628783221411"></a><a name="ul1628783221411"></a><ul id="ul1628783221411"><li>id：定时器标识。</li><li>timeout：超时时间，单位为秒。</li></ul>
<p id="p11831115375719"><a name="p11831115375719"></a><a name="p11831115375719"></a>输出参数：无。</p>
<p id="p38311853105716"><a name="p38311853105716"></a><a name="p38311853105716"></a>返回值：成功返回true，失败返回false。</p>
</td>
</tr>
<tr id="row594682175013"><td class="cellrowborder" valign="top" width="19.698030196980305%" headers="mcps1.2.4.1.1 "><p id="p194614212504"><a name="p194614212504"></a><a name="p194614212504"></a>XCollie类接口</p>
</td>
<td class="cellrowborder" valign="top" width="35.82641735826417%" headers="mcps1.2.4.1.2 "><p id="p1435552713588"><a name="p1435552713588"></a><a name="p1435552713588"></a>void CancelTimer(int id)</p>
</td>
<td class="cellrowborder" valign="top" width="44.47555244475552%" headers="mcps1.2.4.1.3 "><p id="p06791131580"><a name="p06791131580"></a><a name="p06791131580"></a>接口功能：取消定时器。</p>
<p id="p868013165815"><a name="p868013165815"></a><a name="p868013165815"></a>输入参数：定时器标识。</p>
<p id="p12680537587"><a name="p12680537587"></a><a name="p12680537587"></a>输出参数：无。</p>
<p id="p768015317586"><a name="p768015317586"></a><a name="p768015317586"></a>返回值：无。</p>
</td>
</tr>
</tbody>
</table>

## 效果<a name="section1589120102458"></a>

日志打印：

```
timeout: TimeoutTimer start at 1611040305 to check 1s ago

----------StacktraceCatcher CurrentTime:2021-01-19 15:11:45 Unexecuted(-1)(LogType:Stacktrace Pid:27689 Process:XCollieTimeoutModuleTest)----------


----- pid 27689 at 2021-01-19 15:11:45 -----
Cmd line: ./XCollieTimeoutModuleTest
ABI: 'arm64'

"XCollieTimeoutM" sysTid=27689
    #01 pc 00000000000174cc  /data/test/XCollieTimeoutModuleTest
```

## 开发实例<a name="section13905646534"></a>

### C++接口开发实例<a name="section9797199145316"></a>

### 线程卡死监控<a name="section1734221332"></a>

线程卡死监控功能需要开发者实现两个卡死检测回调函数，XCollieChecker类的CheckBlock和CheckThreadBlock接口函数。实现了该回调函数之后，开发者还需要通过XCollie类的RegisterXCollieChecker函数，将该回调函数的类实例成功注册。卡死监控线程会定时执行全部已成功注册的回调函数，检查线程逻辑完成标志位，判定已经成功注册的线程逻辑是否被卡死。

1.  源代码开发

    包含头文件：

    ```
    #include "xcollie.h"
    ```

    在业务代码中使用：

    ```
    void MyXCollieChecker::CheckLock()
    {
        /* time consuming job */
    }
    
    void MyXCollieChecker::CheckThreadBlock()
    {
        /* time consuming job */
    }
    
    sptr<XCollieChecker> checker = new MyXCollieChecker("MyXCollieChecker");
    XCollie::GetInstance().RegisterXCollieChecker(checker, 
        (XCOLLIE_LOCK | XCOLLIE_THREAD));
    ......
    ```

2.  编译设置，在BUILD.gn里增加子系统SDK依赖：

    ```
    external_deps = [ "hiviewdfx:libxcollie" ]
    ```


### 超时监控<a name="section2186947140"></a>

单个进程通过SetTimer接口函数添加定时器最多可以设置128个，超过上限则添加定时器操作会失败。

1.  源代码开发

    包含头文件：

    ```
    #include "xcollie.h"
    ```

    在业务代码中使用（添加/更新/取消）：

    ```
    std::function<void(void *)> callback = [](void *args)
    {
        /* dump helpful information */
    };
    
    int id = XCollie::GetInstance().SetTimer("MyXCollieTimer", 10, callback ,nullptr, XCOLLIE_FLAG_LOG);
    /* time consuming job */
    XCollie::GetInstance().UpdateTimer(id, 5);
    /* time consuming job */
    XCollie::GetInstance().CancelTimer(id);
    ......
    ```

2.  编译设置，在BUILD.gn里增加子系统SDK依赖：

    ```
    external_deps = [ "hiviewdfx:libxcollie" ]
    ```


