# HiCollie Development<a name="EN-US_TOPIC_0000001231255509"></a>

-   [Overview](#section3432134085116)
-   [Available APIs](#section139261151145116)
-   [Example](#section1589120102458)
-   [How to Develop](#section13905646534)
    -   [C++](#section9797199145316)
    -   [Thread Suspension Monitoring](#section1734221332)
    -   [Timeout Monitoring](#section2186947140)


## Overview<a name="section3432134085116"></a>

HiCollie provides the software watchdog function. It provides a unified framework for fault detection and fault log generation to help you locate software timeout faults resulting from system service deadlock, application main thread blocking, and service process timeout. 

## Available APIs<a name="section139261151145116"></a>

**Table  1**  Description of C++ APIs

<a name="table19452225011"></a>
<table><thead align="left"><tr id="row1517803543518"><th class="cellrowborder" valign="top" width="19.698030196980305%" id="mcps1.2.4.1.1"><p id="p484763319529"><a name="p484763319529"></a><a name="p484763319529"></a>Class</p>
</th>
<th class="cellrowborder" valign="top" width="35.82641735826417%" id="mcps1.2.4.1.2"><p id="p1684719339523"><a name="p1684719339523"></a><a name="p1684719339523"></a>API</p>
</th>
<th class="cellrowborder" valign="top" width="44.47555244475552%" id="mcps1.2.4.1.3"><p id="p284773315220"><a name="p284773315220"></a><a name="p284773315220"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1361184632117"><td class="cellrowborder" valign="top" width="19.698030196980305%" headers="mcps1.2.4.1.1 "><p id="p6700155032113"><a name="p6700155032113"></a><a name="p6700155032113"></a>XCollieChecker</p>
</td>
<td class="cellrowborder" valign="top" width="35.82641735826417%" headers="mcps1.2.4.1.2 "><p id="p18699115019217"><a name="p18699115019217"></a><a name="p18699115019217"></a>virtual void CheckBlock()</p>
</td>
<td class="cellrowborder" valign="top" width="44.47555244475552%" headers="mcps1.2.4.1.3 "><p id="p18700175062115"><a name="p18700175062115"></a><a name="p18700175062115"></a>Provides the callback of the suspension detection result.</p>
<p id="p13700125012216"><a name="p13700125012216"></a><a name="p13700125012216"></a>Input arguments: none</p>
<p id="p13700650162114"><a name="p13700650162114"></a><a name="p13700650162114"></a>Output arguments: none</p>
<p id="p3700850192115"><a name="p3700850192115"></a><a name="p3700850192115"></a>Return value: none</p>
</td>
</tr>
<tr id="row8945182185017"><td class="cellrowborder" valign="top" width="19.698030196980305%" headers="mcps1.2.4.1.1 "><p id="p79451227506"><a name="p79451227506"></a><a name="p79451227506"></a>XCollieChecker</p>
</td>
<td class="cellrowborder" valign="top" width="35.82641735826417%" headers="mcps1.2.4.1.2 "><p id="p647534064612"><a name="p647534064612"></a><a name="p647534064612"></a>virtual void CheckThreadBlock()</p>
</td>
<td class="cellrowborder" valign="top" width="44.47555244475552%" headers="mcps1.2.4.1.3 "><p id="p127630177475"><a name="p127630177475"></a><a name="p127630177475"></a>Provides the callback of the thread suspension detection result.</p>
<p id="p18763111794719"><a name="p18763111794719"></a><a name="p18763111794719"></a>Input arguments: none</p>
<p id="p87631176478"><a name="p87631176478"></a><a name="p87631176478"></a>Output arguments: none</p>
<p id="p3764111718473"><a name="p3764111718473"></a><a name="p3764111718473"></a>Return value: none</p>
</td>
</tr>
<tr id="row149924222486"><td class="cellrowborder" valign="top" width="19.698030196980305%" headers="mcps1.2.4.1.1 "><p id="p11643173114810"><a name="p11643173114810"></a><a name="p11643173114810"></a>XCollie</p>
</td>
<td class="cellrowborder" valign="top" width="35.82641735826417%" headers="mcps1.2.4.1.2 "><p id="p16289114074812"><a name="p16289114074812"></a><a name="p16289114074812"></a>void RegisterXCollieChecker(const sptr&lt;XCollieChecker&gt; &amp;checker, unsigned int type)</p>
</td>
<td class="cellrowborder" valign="top" width="44.47555244475552%" headers="mcps1.2.4.1.3 "><p id="p186437319482"><a name="p186437319482"></a><a name="p186437319482"></a>Registers the callback of the thread suspension detection result.</p>
<p id="p112011591133"><a name="p112011591133"></a><a name="p112011591133"></a>Input arguments:</p>
<a name="ul7783192181413"></a><a name="ul7783192181413"></a><ul id="ul7783192181413"><li><strong id="b64637561712"><a name="b64637561712"></a><a name="b64637561712"></a>checker</strong>: Indicates the pointer to the XCollieChecker instance.</li><li><strong id="b1947711661711"><a name="b1947711661711"></a><a name="b1947711661711"></a>type</strong>: Indicates the suspension detection type. Set it to <strong id="b259214119717"><a name="b259214119717"></a><a name="b259214119717"></a>XCOLLIE_THREAD</strong>.</li></ul>
<p id="p166439314482"><a name="p166439314482"></a><a name="p166439314482"></a>Output arguments: none</p>
<p id="p564393112485"><a name="p564393112485"></a><a name="p564393112485"></a>Return value: none</p>
</td>
</tr>
<tr id="row594519275012"><td class="cellrowborder" valign="top" width="19.698030196980305%" headers="mcps1.2.4.1.1 "><p id="p294512211505"><a name="p294512211505"></a><a name="p294512211505"></a>XCollie</p>
</td>
<td class="cellrowborder" valign="top" width="35.82641735826417%" headers="mcps1.2.4.1.2 "><p id="p81561310145215"><a name="p81561310145215"></a><a name="p81561310145215"></a>int SetTimer(const std::string &amp;name, unsigned int timeout, std::function&lt;void (void *)&gt; func, void *arg, unsigned int flag)</p>
</td>
<td class="cellrowborder" valign="top" width="44.47555244475552%" headers="mcps1.2.4.1.3 "><p id="p174279246538"><a name="p174279246538"></a><a name="p174279246538"></a>Adds timers.</p>
<p id="p1998141221410"><a name="p1998141221410"></a><a name="p1998141221410"></a>Input arguments:</p>
<a name="ul845512153147"></a><a name="ul845512153147"></a><ul id="ul845512153147"><li><strong id="b44651010141715"><a name="b44651010141715"></a><a name="b44651010141715"></a>name</strong>: Indicates the timer name.</li><li><strong id="b266981221717"><a name="b266981221717"></a><a name="b266981221717"></a>timeout</strong>: Indicates the timeout duration, in seconds.</li><li><strong id="b17158171421710"><a name="b17158171421710"></a><a name="b17158171421710"></a>func</strong>: Indicates the timeout callback.</li><li><strong id="b1950162581810"><a name="b1950162581810"></a><a name="b1950162581810"></a>arg</strong>: Indicates the pointer to the timeout callback.</li><li><strong id="b4949151521714"><a name="b4949151521714"></a><a name="b4949151521714"></a>flag</strong>: Indicates the timer operation type.<p id="p1242762435310"><a name="p1242762435310"></a><a name="p1242762435310"></a>XCOLLIE_FLAG_DEFAULT // Indicates the default flag, which is the combination of the other three options.</p>
<p id="p1542712435312"><a name="p1542712435312"></a><a name="p1542712435312"></a>XCOLLIE_FLAG_NOOP // Calls only the timeout callback.</p>
<p id="p15427112416531"><a name="p15427112416531"></a><a name="p15427112416531"></a>XCOLLIE_FLAG_LOG // Generates a timeout fault log.</p>
<p id="p242762455314"><a name="p242762455314"></a><a name="p242762455314"></a>XCOLLIE_FLAG_RECOVERY // Exits the process.</p>
</li></ul>
<p id="p15427102445311"><a name="p15427102445311"></a><a name="p15427102445311"></a>Output arguments: none</p>
<p id="p144271424155316"><a name="p144271424155316"></a><a name="p144271424155316"></a>Return value: Returns the timer ID if the operation is successful; returns <strong id="b2229713291"><a name="b2229713291"></a><a name="b2229713291"></a>-1</strong> otherwise.</p>
</td>
</tr>
<tr id="row1294692165010"><td class="cellrowborder" valign="top" width="19.698030196980305%" headers="mcps1.2.4.1.1 "><p id="p19461929506"><a name="p19461929506"></a><a name="p19461929506"></a>XCollie</p>
</td>
<td class="cellrowborder" valign="top" width="35.82641735826417%" headers="mcps1.2.4.1.2 "><p id="p119467215012"><a name="p119467215012"></a><a name="p119467215012"></a>bool UpdateTimer(int id, unsigned int timeout)</p>
</td>
<td class="cellrowborder" valign="top" width="44.47555244475552%" headers="mcps1.2.4.1.3 "><p id="p3831253185713"><a name="p3831253185713"></a><a name="p3831253185713"></a>Updates timers.</p>
<p id="p10649172815148"><a name="p10649172815148"></a><a name="p10649172815148"></a>Input arguments:</p>
<a name="ul1628783221411"></a><a name="ul1628783221411"></a><ul id="ul1628783221411"><li><strong id="b61651021161710"><a name="b61651021161710"></a><a name="b61651021161710"></a>id</strong>: Indicates the timer ID.</li><li><strong id="b24661423141717"><a name="b24661423141717"></a><a name="b24661423141717"></a>timeout</strong>: Indicates the timeout duration, in seconds.</li></ul>
<p id="p11831115375719"><a name="p11831115375719"></a><a name="p11831115375719"></a>Output arguments: none</p>
<p id="p38311853105716"><a name="p38311853105716"></a><a name="p38311853105716"></a>Return value: Returns <strong id="b95701352192819"><a name="b95701352192819"></a><a name="b95701352192819"></a>true</strong> if the operation is successful; returns <strong id="b175761652152814"><a name="b175761652152814"></a><a name="b175761652152814"></a>false</strong> otherwise.</p>
</td>
</tr>
<tr id="row594682175013"><td class="cellrowborder" valign="top" width="19.698030196980305%" headers="mcps1.2.4.1.1 "><p id="p194614212504"><a name="p194614212504"></a><a name="p194614212504"></a>XCollie</p>
</td>
<td class="cellrowborder" valign="top" width="35.82641735826417%" headers="mcps1.2.4.1.2 "><p id="p1435552713588"><a name="p1435552713588"></a><a name="p1435552713588"></a>void CancelTimer(int id)</p>
</td>
<td class="cellrowborder" valign="top" width="44.47555244475552%" headers="mcps1.2.4.1.3 "><p id="p06791131580"><a name="p06791131580"></a><a name="p06791131580"></a>Cancels timers.</p>
<p id="p868013165815"><a name="p868013165815"></a><a name="p868013165815"></a>Input arguments:</p>
<p id="p9311488283"><a name="p9311488283"></a><a name="p9311488283"></a><strong id="b9666749171816"><a name="b9666749171816"></a><a name="b9666749171816"></a>id</strong>: Indicates the timer ID.</p>
<p id="p12680537587"><a name="p12680537587"></a><a name="p12680537587"></a>Output arguments: none</p>
<p id="p768015317586"><a name="p768015317586"></a><a name="p768015317586"></a>Return value: none</p>
</td>
</tr>
</tbody>
</table>

## Example<a name="section1589120102458"></a>

Print logs.

```
timeout: TimeoutTimer start at 1611040305 to check 1s ago

----------StacktraceCatcher CurrentTime:2021-01-19 15:11:45 Unexecuted(-1)(LogType:Stacktrace Pid:27689 Process:XCollieTimeoutModuleTest)----------


----- pid 27689 at 2021-01-19 15:11:45 -----
Cmd line: ./XCollieTimeoutModuleTest
ABI: 'arm64'

"XCollieTimeoutM" sysTid=27689
    #01 pc 00000000000174cc  /data/test/XCollieTimeoutModuleTest
```

## How to Develop<a name="section13905646534"></a>

### C++<a name="section9797199145316"></a>

### Thread Suspension Monitoring<a name="section1734221332"></a>

This function requires you to implement two callback functions:  **CheckBlock**  and  **CheckThreadBlock**  of the  **XCollieChecker**  class. After the callbacks are implemented, you need to use the  **RegisterXCollieChecker**  function of the  **XCollie**  class to register their instances. The suspension monitoring thread periodically executes all successfully registered callbacks, checks the thread logic completion flag, and determines whether the service logic of any registered thread is suspended.

1.  Develop the source code.

    Include the  **xcollie**  header file in the source file.

    ```
    #include "xcollie.h"
    ```

    Add the following code to the service code:

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
    ...
    ```

2.  Configure compilation information. Specifically, add the subsystem SDK dependency to  **BUILD.gn**.

    ```
    external_deps = [ "hiviewdfx:libxcollie" ]
    ```


### Timeout Monitoring<a name="section2186947140"></a>

You can add a maximum of 128 timers for a single process by using the  **SetTimer**  function. Adding timers will fail if the number of timers has reached the upper limit.

1.  Develop the source code.

    Include the  **xcollie**  header file in the source file.

    ```
    #include "xcollie.h"
    ```

    Add the code to add, update, and cancel timers.

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
    ...
    ```

2.  Configure compilation information. Specifically, add the subsystem SDK dependency to  **BUILD.gn**.

    ```
    external_deps = [ "hiviewdfx:libxcollie" ]
    ```


