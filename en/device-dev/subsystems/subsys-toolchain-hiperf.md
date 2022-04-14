# hiperf<a name="EN-US_TOPIC_0000001186476620"></a>

-   [list](#section121805449461)
    -   [Parameters](#section42124492494)
    -   [Example](#section122129443486)

-   [stat](#section12940163061016)
    -   [Parameters](#section36541920145018)
    -   [Example](#section1132495515502)
    -   [Field Description](#section1958985055118)

-   [record](#section168751927524)
    -   [Parameters](#section113617912522)
    -   [Example](#section15998181516549)

-   [report](#section16327635174818)
-   [Example](#section1197655116513)

hiperf is a performance sampling and analysis tool provided for developers. It extends the user-mode capabilities based on the kernel perf mechanism and can conduct performance sampling of the specified application or the entire system.

You can run the  **hiperf -h**  command to display the commands supported by hiperf.

The following describes the common commands \(**list**,  **stat**,  **record**, and  **report**\) supported by hiperf.

## list<a name="section121805449461"></a>

### Parameters<a name="section42124492494"></a>

The  **list**  command lists all the perf events supported by the device. The event names are used for the  **-e**  and  **-g**  parameters of the  **stat**  and  **record**  commands.

```
hiperf list [event type]
```

<a name="table054835774714"></a>
<table><thead align="left"><tr id="row125483575471"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p269191018489"><a name="p269191018489"></a><a name="p269191018489"></a>Parameter</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p186911610174814"><a name="p186911610174814"></a><a name="p186911610174814"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row944214284815"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p44371223487"><a name="p44371223487"></a><a name="p44371223487"></a>hw</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p343715244814"><a name="p343715244814"></a><a name="p343715244814"></a>Lists the hardware events supported by the performance monitoring unit (PMU).</p>
</td>
</tr>
<tr id="row64421627484"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1743715294812"><a name="p1743715294812"></a><a name="p1743715294812"></a>sw</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p843752174819"><a name="p843752174819"></a><a name="p843752174819"></a>Lists the software events supported.</p>
</td>
</tr>
<tr id="row1544215254810"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p124375234814"><a name="p124375234814"></a><a name="p124375234814"></a>tp</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p18437202124820"><a name="p18437202124820"></a><a name="p18437202124820"></a>Lists the tracepotint events supported.</p>
</td>
</tr>
<tr id="row844232124811"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p12437124484"><a name="p12437124484"></a><a name="p12437124484"></a>cache</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p84377213482"><a name="p84377213482"></a><a name="p84377213482"></a>Lists the cache events supported by the PMU.</p>
</td>
</tr>
<tr id="row16442132104817"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1343716224819"><a name="p1343716224819"></a><a name="p1343716224819"></a>raw</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p44372274819"><a name="p44372274819"></a><a name="p44372274819"></a>Lists the raw PMU events supported.</p>
</td>
</tr>
</tbody>
</table>

### Example<a name="section122129443486"></a>

List the hardware events supported by the PMU. The command also lists the events that are not supported by the PMU.

```
hiperf list hw
event not support hw-stalled-cycles-backend
event not support hw-stalled-cycles-frontend
event not support hw-ref-cpu-cycles

Supported events for hardware:
        hw-cpu-cycles
        hw-instructions
        hw-cache-references
        hw-cache-misses
        hw-branch-instructions
        hw-branch-misses
        hw-bus-cycles
```

## stat<a name="section12940163061016"></a>

### Parameters<a name="section36541920145018"></a>

The  **stat**  command monitors the specified application and periodically prints the values of performance counters.

```
hiperf stat [options]
       Collect performance counter information.
```

<a name="table181891426171117"></a>
<table><thead align="left"><tr id="row618932661119"><th class="cellrowborder" valign="top" width="49.94%" id="mcps1.1.3.1.1"><p id="p107231837131118"><a name="p107231837131118"></a><a name="p107231837131118"></a>Parameter</p>
</th>
<th class="cellrowborder" valign="top" width="50.06%" id="mcps1.1.3.1.2"><p id="p12723143721114"><a name="p12723143721114"></a><a name="p12723143721114"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row271743271111"><td class="cellrowborder" valign="top" width="49.94%" headers="mcps1.1.3.1.1 "><p id="p37071332131112"><a name="p37071332131112"></a><a name="p37071332131112"></a>-a</p>
</td>
<td class="cellrowborder" valign="top" width="50.06%" headers="mcps1.1.3.1.2 "><p id="p36451134216"><a name="p36451134216"></a><a name="p36451134216"></a>Collects the values of all threads and default performance counters of the system.</p>
</td>
</tr>
<tr id="row071733271113"><td class="cellrowborder" valign="top" width="49.94%" headers="mcps1.1.3.1.1 "><p id="p1870773214115"><a name="p1870773214115"></a><a name="p1870773214115"></a>-c</p>
</td>
<td class="cellrowborder" valign="top" width="50.06%" headers="mcps1.1.3.1.2 "><p id="p147074321111"><a name="p147074321111"></a><a name="p147074321111"></a>Specifies the IDs of the CPUs to monitor. Use commas (,) to separate multiple CPU IDs, for example <strong id="b88710447518"><a name="b88710447518"></a><a name="b88710447518"></a>0,1,2</strong>.</p>
</td>
</tr>
<tr id="row13717103217111"><td class="cellrowborder" valign="top" width="49.94%" headers="mcps1.1.3.1.1 "><p id="p15707153214114"><a name="p15707153214114"></a><a name="p15707153214114"></a>-d &lt;<em id="i49311018174719"><a name="i49311018174719"></a><a name="i49311018174719"></a>sec</em>&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="50.06%" headers="mcps1.1.3.1.2 "><p id="p117073321117"><a name="p117073321117"></a><a name="p117073321117"></a>Specifies the monitoring period, in seconds.</p>
</td>
</tr>
<tr id="row207174327118"><td class="cellrowborder" valign="top" width="49.94%" headers="mcps1.1.3.1.1 "><p id="p147074320115"><a name="p147074320115"></a><a name="p147074320115"></a>-i &lt;<em id="i1889952124717"><a name="i1889952124717"></a><a name="i1889952124717"></a>ms</em>&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="50.06%" headers="mcps1.1.3.1.2 "><p id="p13707173261112"><a name="p13707173261112"></a><a name="p13707173261112"></a>Specifies the interval for printing the monitored events, in milliseconds.</p>
</td>
</tr>
<tr id="row12717132161112"><td class="cellrowborder" valign="top" width="49.94%" headers="mcps1.1.3.1.1 "><p id="p157071532161119"><a name="p157071532161119"></a><a name="p157071532161119"></a>-e</p>
</td>
<td class="cellrowborder" valign="top" width="50.06%" headers="mcps1.1.3.1.2 "><p id="p16443201119320"><a name="p16443201119320"></a><a name="p16443201119320"></a>Specifies the events to monitor. You can run the <strong id="b9161172815551"><a name="b9161172815551"></a><a name="b9161172815551"></a>list</strong> command to list all the events supported. <strong id="b111611225613"><a name="b111611225613"></a><a name="b111611225613"></a>event:u</strong> indicates an event in the user space, and <strong id="b2282748195610"><a name="b2282748195610"></a><a name="b2282748195610"></a>event:k</strong> indicates an event in the kernel space.</p>
</td>
</tr>
<tr id="row15717143220113"><td class="cellrowborder" valign="top" width="49.94%" headers="mcps1.1.3.1.1 "><p id="p7707203221119"><a name="p7707203221119"></a><a name="p7707203221119"></a>-g</p>
</td>
<td class="cellrowborder" valign="top" width="50.06%" headers="mcps1.1.3.1.2 "><p id="p20870204817311"><a name="p20870204817311"></a><a name="p20870204817311"></a>Specifies a group of events to monitor. The events in the same group are monitored by the same PMU.</p>
</td>
</tr>
<tr id="row1071703213119"><td class="cellrowborder" valign="top" width="49.94%" headers="mcps1.1.3.1.1 "><p id="p87071432101115"><a name="p87071432101115"></a><a name="p87071432101115"></a>--no-inherit</p>
</td>
<td class="cellrowborder" valign="top" width="50.06%" headers="mcps1.1.3.1.2 "><p id="p13323958634"><a name="p13323958634"></a><a name="p13323958634"></a>Leaves the sub-threads of the target thread or process not monitored.</p>
</td>
</tr>
<tr id="row18717113261118"><td class="cellrowborder" valign="top" width="49.94%" headers="mcps1.1.3.1.1 "><p id="p17708123215111"><a name="p17708123215111"></a><a name="p17708123215111"></a>-p</p>
</td>
<td class="cellrowborder" valign="top" width="50.06%" headers="mcps1.1.3.1.2 "><p id="p1270803261116"><a name="p1270803261116"></a><a name="p1270803261116"></a>Specifies the process IDs (PIDs) to monitor.</p>
</td>
</tr>
<tr id="row471793281116"><td class="cellrowborder" valign="top" width="49.94%" headers="mcps1.1.3.1.1 "><p id="p0708532191110"><a name="p0708532191110"></a><a name="p0708532191110"></a>-t</p>
</td>
<td class="cellrowborder" valign="top" width="50.06%" headers="mcps1.1.3.1.2 "><p id="p47081632101118"><a name="p47081632101118"></a><a name="p47081632101118"></a>Specifies the thread IDs (TIDs) to monitor.</p>
</td>
</tr>
<tr id="row1471616324115"><td class="cellrowborder" valign="top" width="49.94%" headers="mcps1.1.3.1.1 "><p id="p870883210110"><a name="p870883210110"></a><a name="p870883210110"></a>--verbose</p>
</td>
<td class="cellrowborder" valign="top" width="50.06%" headers="mcps1.1.3.1.2 "><p id="p137083323111"><a name="p137083323111"></a><a name="p137083323111"></a>Displays detailed report, including raw time data.</p>
</td>
</tr>
</tbody>
</table>

### Example<a name="section1132495515502"></a>

Monitor the entire system for 3 seconds.

```
hiperf stat -d 3 -a
this is root mode, perfEventParanoid assume as -1
Start Profiling...
Timeout exit (total 3009 ms)
                count                           name | comment                          | coverage
               132523         hw-branch-instructions | 15.750 M/sec                     | (100%)
                62554               hw-branch-misses | 47.202372% miss rate             | (100%)
              6994768                  hw-cpu-cycles | 0.832068 GHz                     | (100%)
              1237627                hw-instructions | 5.651758 cycles per instruction  | (100%)
                  248            sw-context-switches | 29.959 K/sec                     | (100%)
                    0                 sw-page-faults | 0.000 /sec                       | (100%)
              9402580                  sw-task-clock | 0.002758 cpus used               | (100%)
```

### Field Description<a name="section1958985055118"></a>

<a name="table6123145517124"></a>
<table><thead align="left"><tr id="row2123755101216"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p75490001315"><a name="p75490001315"></a><a name="p75490001315"></a>Field</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p4549600137"><a name="p4549600137"></a><a name="p4549600137"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row127291156151218"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p672420567127"><a name="p672420567127"></a><a name="p672420567127"></a>count</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p47259563126"><a name="p47259563126"></a><a name="p47259563126"></a>Indicates the times that an event occurred.</p>
</td>
</tr>
<tr id="row20729165611219"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p97258561122"><a name="p97258561122"></a><a name="p97258561122"></a>name</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p10725756151210"><a name="p10725756151210"></a><a name="p10725756151210"></a>Indicates the event name. You can run the <strong id="b1275144172219"><a name="b1275144172219"></a><a name="b1275144172219"></a>list</strong> command to list all the supported events. <strong id="b146319013236"><a name="b146319013236"></a><a name="b146319013236"></a>hw</strong> stands for hardware, and <strong id="b21781210132315"><a name="b21781210132315"></a><a name="b21781210132315"></a>sw</strong> stands for software.</p>
</td>
</tr>
<tr id="row4729056121212"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1572511564124"><a name="p1572511564124"></a><a name="p1572511564124"></a>comment</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p972514566125"><a name="p972514566125"></a><a name="p972514566125"></a>Provides values calculated from those in the <strong id="b3976203310251"><a name="b3976203310251"></a><a name="b3976203310251"></a>Count</strong> column for easy understanding. For example, the CPU frequency (<strong id="b17911439162616"><a name="b17911439162616"></a><a name="b17911439162616"></a>hw-cpu-cycles</strong>) is converted to <strong id="b415132419274"><a name="b415132419274"></a><a name="b415132419274"></a>0.832068</strong> GHz from <strong id="b1471832922712"><a name="b1471832922712"></a><a name="b1471832922712"></a>6994768</strong>.</p>
</td>
</tr>
<tr id="row1772855651216"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1372575617129"><a name="p1372575617129"></a><a name="p1372575617129"></a>coverage</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p3725105621211"><a name="p3725105621211"></a><a name="p3725105621211"></a>Indicates the percentage of PMU resources occupied by the event. The number of events to be monitored by a PMU varies depending on the number of PMUs.</p>
</td>
</tr>
</tbody>
</table>

## record<a name="section168751927524"></a>

### Parameters<a name="section113617912522"></a>

The  **record**  command samples the specified application and saves the sampling data to a file \(**perf.data**  by default\).

```
hiperf record [options]
       Collect performance sampling information.
```

<a name="table1567661165313"></a>
<table><thead align="left"><tr id="row196764115319"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p139171022105315"><a name="p139171022105315"></a><a name="p139171022105315"></a>Parameter</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p10917152255310"><a name="p10917152255310"></a><a name="p10917152255310"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row2374121795310"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p935011178536"><a name="p935011178536"></a><a name="p935011178536"></a>-a</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p835041795311"><a name="p835041795311"></a><a name="p835041795311"></a>Samples all processes and threads in the system.</p>
</td>
</tr>
<tr id="row19374181715539"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p19350517105316"><a name="p19350517105316"></a><a name="p19350517105316"></a>--exclude-hiperf</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2035071717539"><a name="p2035071717539"></a><a name="p2035071717539"></a>Leaves the hiperf process not sampled.</p>
</td>
</tr>
<tr id="row6374181711530"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p193501717185315"><a name="p193501717185315"></a><a name="p193501717185315"></a>-c</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p8350117145310"><a name="p8350117145310"></a><a name="p8350117145310"></a>Specifies the IDs of the CPUs to sample.</p>
</td>
</tr>
<tr id="row33741417105318"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1635011765316"><a name="p1635011765316"></a><a name="p1635011765316"></a>--cpu-limit &lt;<em id="i429116498571"><a name="i429116498571"></a><a name="i429116498571"></a>percent</em>&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p0350171719531"><a name="p0350171719531"></a><a name="p0350171719531"></a>Specifies the maximum percentage of CPU resources occupied by the sampling.</p>
</td>
</tr>
<tr id="row123746177535"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p83505174536"><a name="p83505174536"></a><a name="p83505174536"></a>-d &lt;sec&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p73502017145313"><a name="p73502017145313"></a><a name="p73502017145313"></a>Specifies the sampling duration, in seconds.</p>
</td>
</tr>
<tr id="row1137461711531"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p33501817145317"><a name="p33501817145317"></a><a name="p33501817145317"></a>-f &lt;freq&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p144811511083"><a name="p144811511083"></a><a name="p144811511083"></a>Specifies how often a sampling event is triggered. The default value is 4000 times/second.</p>
<p id="p1035001711532"><a name="p1035001711532"></a><a name="p1035001711532"></a>Note: A higher value indicates heavier CPU load but more sampling data.</p>
</td>
</tr>
<tr id="row133741117145317"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p43505177537"><a name="p43505177537"></a><a name="p43505177537"></a>--period &lt;<em id="i993545255714"><a name="i993545255714"></a><a name="i993545255714"></a>num</em>&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p5350131725316"><a name="p5350131725316"></a><a name="p5350131725316"></a>Specifies the number of occurrence times of an event that triggers a sampling. That is, a sampling is performed once when the event occurs the specified number of times.</p>
</td>
</tr>
<tr id="row837331711539"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1635110175534"><a name="p1635110175534"></a><a name="p1635110175534"></a>-e</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p20351171713531"><a name="p20351171713531"></a><a name="p20351171713531"></a>Specifies the events to monitor. You can run the <strong id="b176932255522"><a name="b176932255522"></a><a name="b176932255522"></a>list</strong> command to list all the events supported. <strong id="b2693625205220"><a name="b2693625205220"></a><a name="b2693625205220"></a>event:u</strong> indicates an event in the user space, and <strong id="b14693225145212"><a name="b14693225145212"></a><a name="b14693225145212"></a>event:k</strong> indicates an event in the kernel space.</p>
</td>
</tr>
<tr id="row3373517175310"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2035151715533"><a name="p2035151715533"></a><a name="p2035151715533"></a>-g</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p335181718535"><a name="p335181718535"></a><a name="p335181718535"></a>Specifies a group of events to monitor. The events in the same group are monitored by the same PMU.</p>
</td>
</tr>
<tr id="row16373151725318"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1735141745318"><a name="p1735141745318"></a><a name="p1735141745318"></a>--no-inherit</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p17351121712533"><a name="p17351121712533"></a><a name="p17351121712533"></a>Leaves the sub-threads of the target thread or process not monitored.</p>
</td>
</tr>
<tr id="row837312172537"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p163511178534"><a name="p163511178534"></a><a name="p163511178534"></a>-p</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p535119176531"><a name="p535119176531"></a><a name="p535119176531"></a>Specifies the processes to monitor.</p>
</td>
</tr>
<tr id="row11373181711531"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p4351017195310"><a name="p4351017195310"></a><a name="p4351017195310"></a>-t</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1735111716534"><a name="p1735111716534"></a><a name="p1735111716534"></a>Specifies the threads to monitor.</p>
</td>
</tr>
<tr id="row193733174531"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p635171735314"><a name="p635171735314"></a><a name="p635171735314"></a>--offcpu</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p23511017135310"><a name="p23511017135310"></a><a name="p23511017135310"></a>Monitors the CPU scheduling event, which is equivalent to the <strong id="b83471327125516"><a name="b83471327125516"></a><a name="b83471327125516"></a>--period 1 -e sched:sched_switch</strong> event.</p>
</td>
</tr>
<tr id="row7373151705310"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p13351111735313"><a name="p13351111735313"></a><a name="p13351111735313"></a>-j &lt;<em id="i193621459165712"><a name="i193621459165712"></a><a name="i193621459165712"></a>branch_filter1</em>&gt;[,<em id="i153235212585"><a name="i153235212585"></a><a name="i153235212585"></a>branch_filter2</em>]...</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p15351217125317"><a name="p15351217125317"></a><a name="p15351217125317"></a>Monitors the branch prediction events. Branch prediction tries to predict the next instruction to be executed if there are multiple <strong id="b1515010251521"><a name="b1515010251521"></a><a name="b1515010251521"></a>if else</strong> conditions.</p>
</td>
</tr>
<tr id="row337311178535"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p635151711536"><a name="p635151711536"></a><a name="p635151711536"></a>-s / --call-stack <span>&lt;</span><em id="i8524129115816"><a name="i8524129115816"></a><a name="i8524129115816"></a>fp \| dwarf[,size]</em><span>&gt;</span></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p14351111735316"><a name="p14351111735316"></a><a name="p14351111735316"></a>Sets the user stack unwinding mode, which can be <strong id="b99242538156"><a name="b99242538156"></a><a name="b99242538156"></a>fp</strong> or <strong id="b18703165914151"><a name="b18703165914151"></a><a name="b18703165914151"></a>dwarf</strong>. If <strong id="b293334361618"><a name="b293334361618"></a><a name="b293334361618"></a>dwarf</strong> is used, you can specify the size of the user stack to be sampled. The default value is <strong id="b162942143188"><a name="b162942143188"></a><a name="b162942143188"></a>65528</strong>.</p>
</td>
</tr>
<tr id="row73731817145318"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p13351171714534"><a name="p13351171714534"></a><a name="p13351171714534"></a>--delay-unwind</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1135112171532"><a name="p1135112171532"></a><a name="p1135112171532"></a>Delays the stack unwinding till the sampling is complete.</p>
</td>
</tr>
<tr id="row12373151717534"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p6351161714534"><a name="p6351161714534"></a><a name="p6351161714534"></a>--disable-unwind</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p17351717115317"><a name="p17351717115317"></a><a name="p17351717115317"></a>Disables stack unwinding. The user register and stack data is stored in <strong id="b628502918229"><a name="b628502918229"></a><a name="b628502918229"></a>perf.data</strong> for offline stack unwinding.</p>
</td>
</tr>
<tr id="row133738178538"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1935118178535"><a name="p1935118178535"></a><a name="p1935118178535"></a>--disable-callstack-expend</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p335171745314"><a name="p335171745314"></a><a name="p335171745314"></a>Disables the unwound call stack information from being combined or extended.</p>
</td>
</tr>
<tr id="row1237310179537"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p193511917175314"><a name="p193511917175314"></a><a name="p193511917175314"></a>--clockid &lt;<em id="i75341226145817"><a name="i75341226145817"></a><a name="i75341226145817"></a>clock type</em>&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p7351717115312"><a name="p7351717115312"></a><a name="p7351717115312"></a>Sets the clock source for the sampling data. The options are <strong id="b11324454271"><a name="b11324454271"></a><a name="b11324454271"></a>monotonic</strong>, <strong id="b2095984822716"><a name="b2095984822716"></a><a name="b2095984822716"></a>boottime</strong>, and <strong id="b173918568274"><a name="b173918568274"></a><a name="b173918568274"></a>realtime</strong>.</p>
</td>
</tr>
<tr id="row23721173538"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p135131765311"><a name="p135131765311"></a><a name="p135131765311"></a>--symbol-dir <span>&lt;</span><em id="i1766243012586"><a name="i1766243012586"></a><a name="i1766243012586"></a>dir</em><span>&gt;</span></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1351181716532"><a name="p1351181716532"></a><a name="p1351181716532"></a>Specifies the directory of the symbol table. The specified symbol table will be preferentially used in stack unwinding.</p>
</td>
</tr>
<tr id="row137221711533"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p63521317135315"><a name="p63521317135315"></a><a name="p63521317135315"></a>-m &lt;<em id="i164097384583"><a name="i164097384583"></a><a name="i164097384583"></a>mmap pages</em>&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p33521617165316"><a name="p33521617165316"></a><a name="p33521617165316"></a>Specifies the cache size, in pages. The default value is <strong id="b1541914432911"><a name="b1541914432911"></a><a name="b1541914432911"></a>1024</strong>. The parameter value must be a power of <strong id="b1731417117306"><a name="b1731417117306"></a><a name="b1731417117306"></a>2</strong>. The value range is [2 - 1024].</p>
<p id="p18627133351018"><a name="p18627133351018"></a><a name="p18627133351018"></a>Note: A higher value indicates a lower event loss rate but higher memory usage.</p>
</td>
</tr>
<tr id="row1337251716532"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p153521617175310"><a name="p153521617175310"></a><a name="p153521617175310"></a>--app &lt;<em id="i45101646195814"><a name="i45101646195814"></a><a name="i45101646195814"></a>package name</em>&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1035251755316"><a name="p1035251755316"></a><a name="p1035251755316"></a>Specifies the bundle name of the target application to be sampled. The default timeout interval is 10 seconds. If the specified application does not exist, the hiperf process exits after 10 seconds.</p>
</td>
</tr>
<tr id="row037212176539"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p935251710537"><a name="p935251710537"></a><a name="p935251710537"></a>--data-limit &lt;<em id="i64491950175817"><a name="i64491950175817"></a><a name="i64491950175817"></a>SIZE[K|M|G]</em>&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p135211718536"><a name="p135211718536"></a><a name="p135211718536"></a>Specifies the maximum size of the sampling result, in KB, MB, or GB. By default, there is no limit on the size.</p>
</td>
</tr>
<tr id="row8372517155320"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p43520171536"><a name="p43520171536"></a><a name="p43520171536"></a>-o &lt;<em id="i1953785410587"><a name="i1953785410587"></a><a name="i1953785410587"></a>output file name</em>&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p935241711539"><a name="p935241711539"></a><a name="p935241711539"></a>Specifies the name of the sampling result file. It is <strong id="b1714216402339"><a name="b1714216402339"></a><a name="b1714216402339"></a>/data/local/tmp/perf.data</strong> by default.</p>
</td>
</tr>
<tr id="row113721417105317"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p335251714534"><a name="p335251714534"></a><a name="p335251714534"></a>-z</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p10352117175319"><a name="p10352117175319"></a><a name="p10352117175319"></a>Saves the output file in .gzip format.</p>
</td>
</tr>
<tr id="row12372111735310"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p335211755313"><a name="p335211755313"></a><a name="p335211755313"></a>--verbose</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p63529178537"><a name="p63529178537"></a><a name="p63529178537"></a>Displays detailed log information during sampling.</p>
</td>
</tr>
</tbody>
</table>

### Example<a name="section15998181516549"></a>

-   Sample all processes in the system for 3 seconds and display detailed log information during the sampling process.

    ```
    hiperf record -d 3 -a --verbose
    ```


-   Enable stack unwinding in fp mode.

    ```
    hiperf record -s fp -d 3 -a
    ```

-   Enable stack unwinding in dwarf mode.

    ```
    hiperf record -s dwarf -d 3 -a
    ```

-   Sample offcpu events.

    ```
    hiperf record --offcpu -s dwarf -d 3 -a
    ```

-   Delay stack unwinding.

    ```
    hiperf record -d 3 -s dwarf --delay-unwind -a
    ```

-   Disable stack unwinding. In this case, the stack data is saved to the  **perf.data**  file.

    ```
    hiperf record -d 3 -s dwarf --disable-unwind -a
    ```

-   Monitor the  **com.ohos.launch**  application. The hiperf process exits after 10 seconds if the process corresponding to the specified bundle name does not exist.

    ```
    hiperf record -d 3 -s dwarf --app com.ohos.launch
    ```

-   Compress the sampling results.

    ```
    hiperf record -z -s dwarf -d 3  -a
    ```


## report<a name="section16327635174818"></a>

The  **report**  command displays the sampling data that is captured by using  **record**.

```
hiperf report [option]
       Report sampling information from perf.data.
```

<a name="table1243113226513"></a>
<table><thead align="left"><tr id="row1843211222514"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1448719421464"><a name="p1448719421464"></a><a name="p1448719421464"></a>Parameter</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p194878425612"><a name="p194878425612"></a><a name="p194878425612"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row0432622150"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p11487154216619"><a name="p11487154216619"></a><a name="p11487154216619"></a>--symbol-dir &lt;<em id="i102111819165910"><a name="i102111819165910"></a><a name="i102111819165910"></a>dir</em>&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p174873421063"><a name="p174873421063"></a><a name="p174873421063"></a>Specifies the directory of the symbol table.</p>
</td>
</tr>
<tr id="row9432132216517"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p144878421961"><a name="p144878421961"></a><a name="p144878421961"></a>--limit-percent &lt;<em id="i250122135915"><a name="i250122135915"></a><a name="i250122135915"></a>number</em>&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p14487184216619"><a name="p14487184216619"></a><a name="p14487184216619"></a>Specifies the minimum percentage of the result to display. The result that is lower than the minimum percentage is not displayed.</p>
</td>
</tr>
<tr id="row1443213226513"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p848717421064"><a name="p848717421064"></a><a name="p848717421064"></a>-s / --call-stack</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p17487042965"><a name="p17487042965"></a><a name="p17487042965"></a>Displays detailed call stack information.</p>
</td>
</tr>
<tr id="row13432622458"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p6487164214611"><a name="p6487164214611"></a><a name="p6487164214611"></a>--call-stack-limit-percent &lt;<em id="i1900525135916"><a name="i1900525135916"></a><a name="i1900525135916"></a>number</em>&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p194879426610"><a name="p194879426610"></a><a name="p194879426610"></a>Specifies the minimum percentage of the call stack to display. The call stack that is lower than the minimum percentage is not displayed.</p>
</td>
</tr>
<tr id="row243210221517"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1248754220618"><a name="p1248754220618"></a><a name="p1248754220618"></a>--proto</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p174877426611"><a name="p174877426611"></a><a name="p174877426611"></a>Converts the <strong id="b7360121984613"><a name="b7360121984613"></a><a name="b7360121984613"></a>perf.data</strong> file into the proto format. The default file name is <strong id="b255114336468"><a name="b255114336468"></a><a name="b255114336468"></a>perf.proto</strong>.</p>
</td>
</tr>
<tr id="row1432122152"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p24878421618"><a name="p24878421618"></a><a name="p24878421618"></a>--json</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p048720421068"><a name="p048720421068"></a><a name="p048720421068"></a>Converts the <strong id="b10736748154614"><a name="b10736748154614"></a><a name="b10736748154614"></a>perf.data</strong> file into the JSON format. The default file name is <strong id="b12526557144615"><a name="b12526557144615"></a><a name="b12526557144615"></a>perf.json</strong>.</p>
</td>
</tr>
<tr id="row3432322251"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p3487142164"><a name="p3487142164"></a><a name="p3487142164"></a>--branch</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p13487942561"><a name="p13487942561"></a><a name="p13487942561"></a>Displays the report based on the branch prediction result address instead of the IP address of the call stack.</p>
</td>
</tr>
<tr id="row3428154963"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p64875421869"><a name="p64875421869"></a><a name="p64875421869"></a>--&lt;<em id="i2792933155916"><a name="i2792933155916"></a><a name="i2792933155916"></a>keys</em>&gt; &lt;<em id="i49299369598"><a name="i49299369598"></a><a name="i49299369598"></a>keyname1</em>&gt;[,<em id="i22921440185914"><a name="i22921440185914"></a><a name="i22921440185914"></a>keyname2</em>][,...]</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p14871342165"><a name="p14871342165"></a><a name="p14871342165"></a>Filters and displays reports based on the given keywords. <strong id="b1718471815494"><a name="b1718471815494"></a><a name="b1718471815494"></a>keys</strong> can be <strong id="b652162620493"><a name="b652162620493"></a><a name="b652162620493"></a>comms</strong>, <strong id="b1926582944916"><a name="b1926582944916"></a><a name="b1926582944916"></a>pids</strong>, and <strong id="b12471434134911"><a name="b12471434134911"></a><a name="b12471434134911"></a>tids</strong>. For example, <strong id="b1794418482490"><a name="b1794418482490"></a><a name="b1794418482490"></a>--comms hiperf,hilog</strong> displays only the records whose process or thread name is <strong id="b195761830195014"><a name="b195761830195014"></a><a name="b195761830195014"></a>hiperf</strong> or <strong id="b2036334115014"><a name="b2036334115014"></a><a name="b2036334115014"></a>hilog</strong>.</p>
</td>
</tr>
<tr id="row16770181015614"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p144875424619"><a name="p144875424619"></a><a name="p144875424619"></a>--sort &lt;<em id="i3355743195911"><a name="i3355743195911"></a><a name="i3355743195911"></a>key1</em>&gt;[,<em id="i13850184612590"><a name="i13850184612590"></a><a name="i13850184612590"></a>key2</em>][,...]</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p94870428610"><a name="p94870428610"></a><a name="p94870428610"></a>Sorts and displays information based on specified keywords, such as <strong id="b114664210512"><a name="b114664210512"></a><a name="b114664210512"></a>pid</strong>, <strong id="b319919248518"><a name="b319919248518"></a><a name="b319919248518"></a>tid</strong>, and <strong id="b1140053135118"><a name="b1140053135118"></a><a name="b1140053135118"></a>comm</strong>. Multiple keywords can be specified.</p>
</td>
</tr>
<tr id="row3442413567"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p14487174219619"><a name="p14487174219619"></a><a name="p14487174219619"></a>-i &lt;<em id="i1398985011592"><a name="i1398985011592"></a><a name="i1398985011592"></a>filename</em>&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p948816422618"><a name="p948816422618"></a><a name="p948816422618"></a>Specifies the sampling data (<strong id="b165437587515"><a name="b165437587515"></a><a name="b165437587515"></a>perf.data</strong> by default).</p>
</td>
</tr>
<tr id="row112915190611"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p114885426613"><a name="p114885426613"></a><a name="p114885426613"></a>-o &lt;<em id="i2284165415591"><a name="i2284165415591"></a><a name="i2284165415591"></a>filename</em>&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p74882421167"><a name="p74882421167"></a><a name="p74882421167"></a>Specifies the name of the report to output.</p>
</td>
</tr>
</tbody>
</table>

## Example<a name="section1197655116513"></a>

-   Output the report of the sampling data \(**perf.data**  by default\).

    ```
    hiperf report
    ```

    Output \(example\):

    ```
    Heating count    comm            pid  tid  dso                                func
     5.68%  15073949 hiperf_example_ 1085 1091 /system/lib/ld-musl-arm.so.1       malloc
     2.57%   6834119 hiperf_example_ 1085 1091 [kernel.kallsyms]                  vector_swi
     2.27%   6013910 hiperf_example_ 1085 1087 /system/lib/ld-musl-arm.so.1       malloc
     2.19%   5805738 hiperf_example_ 1085 1091 /system/lib/ld-musl-arm.so.1       vfprintf
     2.09%   5543362 hiperf_example_ 1085 1091 [kernel.kallsyms]                  ktime_get_ts64
    report done
    ```

-   Output the call stack report of the sampling data.

    ```
    hiperf report -s
    ```

-   Set the symbol table directory.

    ```
    hiperf report -s --symbol-dir /data/local/tmp
    ```

-   Display only the information containing  **libutils.z.so**.

    ```
    hiperf report --dsos libuitls.z.so
    ```

-   Sort the result by  **dso**.

    ```
    hiperf report --sort dso
    ```


