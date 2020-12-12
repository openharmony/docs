# pthread.h<a name="EN-US_TOPIC_0000001055228018"></a>

-   [Overview](#section1231105050165628)
-   [Summary](#section506638614165628)
-   [Functions](#func-members)

## **Overview**<a name="section1231105050165628"></a>

**Related Modules:**

[PROCESS](process.md)

**Description:**

Provides process- and thread-related structures \(providing fields such as thread attributes\) and functions \(including the functions for creating and destroying threads, and setting the thread detach state and blocking conditions\). 

**Since:**

1.0

**Version:**

1.0

## **Summary**<a name="section506638614165628"></a>

## Functions<a name="func-members"></a>

<a name="table1596945005165628"></a>
<table><thead align="left"><tr id="row1240171604165628"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1933799679165628"><a name="p1933799679165628"></a><a name="p1933799679165628"></a>Function</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p739679658165628"><a name="p739679658165628"></a><a name="p739679658165628"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row908570843165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1020142019165628"><a name="p1020142019165628"></a><a name="p1020142019165628"></a><a href="process.md#gae5d18438d4d20c8a2e42cd2500578d79">pthread_create</a> (<a href="utils.md#ga5250f47a8a0402a78bb51a2133e13c1f">pthread_t</a> *thread, const <a href="utils.md#gac8ee4471bbc35deb7589ac3615deb486">pthread_attr_t</a> *attr, void *(*start_routine)(void *), void *arg)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1562782441165628"><a name="p1562782441165628"></a><a name="p1562782441165628"></a>int </p>
<p id="p370570624165628"><a name="p370570624165628"></a><a name="p370570624165628"></a>Creates a thread. </p>
</td>
</tr>
<tr id="row1447520197165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1990552234165628"><a name="p1990552234165628"></a><a name="p1990552234165628"></a><a href="process.md#ga7c275c509c26566b6dd95a2de1668a2f">pthread_detach</a> (<a href="utils.md#ga5250f47a8a0402a78bb51a2133e13c1f">pthread_t</a> thread)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1447031092165628"><a name="p1447031092165628"></a><a name="p1447031092165628"></a>int </p>
<p id="p279334715165628"><a name="p279334715165628"></a><a name="p279334715165628"></a>Detaches a thread. </p>
</td>
</tr>
<tr id="row1289631326165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p162885031165628"><a name="p162885031165628"></a><a name="p162885031165628"></a><a href="process.md#gaadfb4e5de5a20880c6a40d4e73ce2597">pthread_exit</a> (void *retval)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1834100321165628"><a name="p1834100321165628"></a><a name="p1834100321165628"></a>_Noreturn void </p>
<p id="p143907672165628"><a name="p143907672165628"></a><a name="p143907672165628"></a>Terminates the calling thread. </p>
</td>
</tr>
<tr id="row761650238165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1777967730165628"><a name="p1777967730165628"></a><a name="p1777967730165628"></a><a href="process.md#ga28a15bba47cab57cbc9f5dac9af99c8b">pthread_join</a> (<a href="utils.md#ga5250f47a8a0402a78bb51a2133e13c1f">pthread_t</a> thread, void **retval)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2137750049165628"><a name="p2137750049165628"></a><a name="p2137750049165628"></a>int </p>
<p id="p1992613991165628"><a name="p1992613991165628"></a><a name="p1992613991165628"></a>Waits for a thread to terminate. </p>
</td>
</tr>
<tr id="row1913409959165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p803037853165628"><a name="p803037853165628"></a><a name="p803037853165628"></a><a href="process.md#ga4c4f5f3b4f8f45d9d897847d53b11aaa">pthread_self</a> (void)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1398088780165628"><a name="p1398088780165628"></a><a name="p1398088780165628"></a><a href="utils.md#ga5250f47a8a0402a78bb51a2133e13c1f">pthread_t</a> </p>
<p id="p1471863198165628"><a name="p1471863198165628"></a><a name="p1471863198165628"></a>Obtains the ID of the calling thread. </p>
</td>
</tr>
<tr id="row129394962165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p345867569165628"><a name="p345867569165628"></a><a name="p345867569165628"></a><a href="process.md#ga98ec817164a6641eda2341de473b659d">pthread_equal</a> (<a href="utils.md#ga5250f47a8a0402a78bb51a2133e13c1f">pthread_t</a> t1, <a href="utils.md#ga5250f47a8a0402a78bb51a2133e13c1f">pthread_t</a> t2)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1013761848165628"><a name="p1013761848165628"></a><a name="p1013761848165628"></a>int </p>
<p id="p561026754165628"><a name="p561026754165628"></a><a name="p561026754165628"></a>Compares whether two thread IDs are equal. </p>
</td>
</tr>
<tr id="row1300963427165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p811138167165628"><a name="p811138167165628"></a><a name="p811138167165628"></a><a href="process.md#ga37075410fbbaad7ee93c95375fc86e0e">pthread_setcancelstate</a> (int state, int *oldstate)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1088562675165628"><a name="p1088562675165628"></a><a name="p1088562675165628"></a>int </p>
<p id="p839601730165628"><a name="p839601730165628"></a><a name="p839601730165628"></a>Sets the cancelability state for the calling thread. </p>
</td>
</tr>
<tr id="row531656355165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p586786285165628"><a name="p586786285165628"></a><a name="p586786285165628"></a><a href="process.md#gaab579bcfcf0662a0c1e35fd82162e61d">pthread_setcanceltype</a> (int type, int *oldtype)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1860061381165628"><a name="p1860061381165628"></a><a name="p1860061381165628"></a>int </p>
<p id="p1054072870165628"><a name="p1054072870165628"></a><a name="p1054072870165628"></a>Sets the cancelability type for the calling thread. </p>
</td>
</tr>
<tr id="row467544583165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p111737169165628"><a name="p111737169165628"></a><a name="p111737169165628"></a><a href="process.md#gaf1c95282ab2bea25f0888a19652cd41f">pthread_testcancel</a> (void)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1520329613165628"><a name="p1520329613165628"></a><a name="p1520329613165628"></a>void </p>
<p id="p1866270208165628"><a name="p1866270208165628"></a><a name="p1866270208165628"></a>Requests delivery of any pending cancellation request. </p>
</td>
</tr>
<tr id="row985643552165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1628484260165628"><a name="p1628484260165628"></a><a name="p1628484260165628"></a><a href="process.md#ga9e77a80c073787bf9a593e9c619dce27">pthread_cancel</a> (<a href="utils.md#ga5250f47a8a0402a78bb51a2133e13c1f">pthread_t</a> thread)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p649516888165628"><a name="p649516888165628"></a><a name="p649516888165628"></a>int </p>
<p id="p598492453165628"><a name="p598492453165628"></a><a name="p598492453165628"></a>Sends a cancellation request to a thread. </p>
</td>
</tr>
<tr id="row1804471227165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p482092147165628"><a name="p482092147165628"></a><a name="p482092147165628"></a><a href="process.md#ga5aafacc071cdfafd0eb992004dee3e62">pthread_kill</a> (<a href="utils.md#ga5250f47a8a0402a78bb51a2133e13c1f">pthread_t</a> thread, int sig)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1028440206165628"><a name="p1028440206165628"></a><a name="p1028440206165628"></a>int </p>
<p id="p1486000951165628"><a name="p1486000951165628"></a><a name="p1486000951165628"></a>Sends a signal to a thread. </p>
</td>
</tr>
<tr id="row1528980026165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1956244169165628"><a name="p1956244169165628"></a><a name="p1956244169165628"></a><a href="process.md#gaae9850b3759769c748727e171c4c6e61">pthread_getschedparam</a> (<a href="utils.md#ga5250f47a8a0402a78bb51a2133e13c1f">pthread_t</a> thread, int *policy, struct <a href="sched_param.md">sched_param</a> *param)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p690501857165628"><a name="p690501857165628"></a><a name="p690501857165628"></a>int </p>
<p id="p2013631147165628"><a name="p2013631147165628"></a><a name="p2013631147165628"></a>Obtains the scheduling policy and parameters of a thread. </p>
</td>
</tr>
<tr id="row1982831971165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1351633347165628"><a name="p1351633347165628"></a><a name="p1351633347165628"></a><a href="process.md#ga14f50e1f5d815c90f1f4225eca5d3a8c">pthread_setschedparam</a> (<a href="utils.md#ga5250f47a8a0402a78bb51a2133e13c1f">pthread_t</a> thread, int policy, const struct <a href="sched_param.md">sched_param</a> *param)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1438402460165628"><a name="p1438402460165628"></a><a name="p1438402460165628"></a>int </p>
<p id="p207053907165628"><a name="p207053907165628"></a><a name="p207053907165628"></a>Sets a scheduling policy and parameters for a thread. </p>
</td>
</tr>
<tr id="row341592455165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p807078669165628"><a name="p807078669165628"></a><a name="p807078669165628"></a><a href="process.md#ga7a23cbcfc21a4e3edf531ed65f022370">pthread_setschedprio</a> (<a href="utils.md#ga5250f47a8a0402a78bb51a2133e13c1f">pthread_t</a> thread, int prio)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1763383644165628"><a name="p1763383644165628"></a><a name="p1763383644165628"></a>int </p>
<p id="p956288548165628"><a name="p956288548165628"></a><a name="p956288548165628"></a>Sets a static scheduling priority for a thread. </p>
</td>
</tr>
<tr id="row979898156165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2001231937165628"><a name="p2001231937165628"></a><a name="p2001231937165628"></a><a href="process.md#ga196103ac97710dad7a93fd6c188cc999">pthread_once</a> (<a href="utils.md#gaf46ecab6116bf15713b10ddfab67bc07">pthread_once_t</a> *once_control, void(*init_routine)(void))</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p653645749165628"><a name="p653645749165628"></a><a name="p653645749165628"></a>int </p>
<p id="p2090375769165628"><a name="p2090375769165628"></a><a name="p2090375769165628"></a>Enables the initialization function to be called only once. </p>
</td>
</tr>
<tr id="row1621225803165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1710753777165628"><a name="p1710753777165628"></a><a name="p1710753777165628"></a><a href="process.md#gadd99221596e95a55f70c59c1c712bbde">pthread_mutex_init</a> (<a href="utils.md#ga75eeb2460f33f5f74cec3ff583ad9e94">pthread_mutex_t</a> *__restrict m, const <a href="utils.md#gaf2212c79151cc55f3a41c430908f3909">pthread_mutexattr_t</a> *__restrict a)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p895179603165628"><a name="p895179603165628"></a><a name="p895179603165628"></a>int </p>
<p id="p180794189165628"><a name="p180794189165628"></a><a name="p180794189165628"></a>Initializes a mutex. </p>
</td>
</tr>
<tr id="row1520436673165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p693021200165628"><a name="p693021200165628"></a><a name="p693021200165628"></a><a href="process.md#gafd70d6f2c50e22b996c926fb9d6ad291">pthread_mutex_lock</a> (<a href="utils.md#ga75eeb2460f33f5f74cec3ff583ad9e94">pthread_mutex_t</a> *m)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p608785683165628"><a name="p608785683165628"></a><a name="p608785683165628"></a>int </p>
<p id="p1572014132165628"><a name="p1572014132165628"></a><a name="p1572014132165628"></a>Locks a mutex. </p>
</td>
</tr>
<tr id="row1079147827165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p812500206165628"><a name="p812500206165628"></a><a name="p812500206165628"></a><a href="process.md#ga02a3c64dac70730e226c31c0e7dbb45c">pthread_mutex_unlock</a> (<a href="utils.md#ga75eeb2460f33f5f74cec3ff583ad9e94">pthread_mutex_t</a> *m)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p808893184165628"><a name="p808893184165628"></a><a name="p808893184165628"></a>int </p>
<p id="p1402347072165628"><a name="p1402347072165628"></a><a name="p1402347072165628"></a>Unlocks a mutex. </p>
</td>
</tr>
<tr id="row1981184714165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1415457631165628"><a name="p1415457631165628"></a><a name="p1415457631165628"></a><a href="process.md#gacc1ccbaf3d76572da85a8030bba1ede4">pthread_mutex_trylock</a> (<a href="utils.md#ga75eeb2460f33f5f74cec3ff583ad9e94">pthread_mutex_t</a> *m)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p314110795165628"><a name="p314110795165628"></a><a name="p314110795165628"></a>int </p>
<p id="p1446605887165628"><a name="p1446605887165628"></a><a name="p1446605887165628"></a>Attempts to lock a mutex. </p>
</td>
</tr>
<tr id="row1976555314165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p831626732165628"><a name="p831626732165628"></a><a name="p831626732165628"></a><a href="process.md#gabc6a044b418e942b91121b1babb61708">pthread_mutex_timedlock</a> (<a href="utils.md#ga75eeb2460f33f5f74cec3ff583ad9e94">pthread_mutex_t</a> *__restrict m, const struct <a href="timespec.md">timespec</a> *__restrict at)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1423695081165628"><a name="p1423695081165628"></a><a name="p1423695081165628"></a>int </p>
<p id="p936501045165628"><a name="p936501045165628"></a><a name="p936501045165628"></a>Blocks the calling thread to lock a mutex. </p>
</td>
</tr>
<tr id="row1792531276165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1636123377165628"><a name="p1636123377165628"></a><a name="p1636123377165628"></a><a href="process.md#gaf89d9cfa300f33b46720a96eac83d175">pthread_mutex_destroy</a> (<a href="utils.md#ga75eeb2460f33f5f74cec3ff583ad9e94">pthread_mutex_t</a> *m)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1970133516165628"><a name="p1970133516165628"></a><a name="p1970133516165628"></a>int </p>
<p id="p328955890165628"><a name="p328955890165628"></a><a name="p328955890165628"></a>Destroys a mutex. </p>
</td>
</tr>
<tr id="row1729773686165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p358432895165628"><a name="p358432895165628"></a><a name="p358432895165628"></a><a href="process.md#gabdf02ed57b055f1920991e96e7d67043">pthread_cond_init</a> (<a href="utils.md#gaf2111a9da165bafea75dabf5cb131042">pthread_cond_t</a> *__restrict c, const <a href="utils.md#gaa992c0a75a463b1c095248eec28086d3">pthread_condattr_t</a> *__restrict a)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1294582297165628"><a name="p1294582297165628"></a><a name="p1294582297165628"></a>int </p>
<p id="p1070400181165628"><a name="p1070400181165628"></a><a name="p1070400181165628"></a>Initializes a condition variable. </p>
</td>
</tr>
<tr id="row1561378925165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p644771938165628"><a name="p644771938165628"></a><a name="p644771938165628"></a><a href="process.md#ga7f2a7328ee3a7743686adcd2d51771c4">pthread_cond_destroy</a> (<a href="utils.md#gaf2111a9da165bafea75dabf5cb131042">pthread_cond_t</a> *c)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1474938916165628"><a name="p1474938916165628"></a><a name="p1474938916165628"></a>int </p>
<p id="p1083756052165628"><a name="p1083756052165628"></a><a name="p1083756052165628"></a>Destroys a condition variable. </p>
</td>
</tr>
<tr id="row1726328835165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1523904757165628"><a name="p1523904757165628"></a><a name="p1523904757165628"></a><a href="process.md#gaea601b8ce596a5c54fb12758c56b10a1">pthread_cond_wait</a> (<a href="utils.md#gaf2111a9da165bafea75dabf5cb131042">pthread_cond_t</a> *__restrict c, <a href="utils.md#ga75eeb2460f33f5f74cec3ff583ad9e94">pthread_mutex_t</a> *__restrict m)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p647469733165628"><a name="p647469733165628"></a><a name="p647469733165628"></a>int </p>
<p id="p1639018058165628"><a name="p1639018058165628"></a><a name="p1639018058165628"></a>Blocks the calling thread to wait for the condition set by <strong id="b1666176965165628"><a name="b1666176965165628"></a><a name="b1666176965165628"></a>pthread_con_signal()</strong>. </p>
</td>
</tr>
<tr id="row767261658165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p610009749165628"><a name="p610009749165628"></a><a name="p610009749165628"></a><a href="process.md#ga506c0350d597721ab24bba7129e8e0df">pthread_cond_timedwait</a> (<a href="utils.md#gaf2111a9da165bafea75dabf5cb131042">pthread_cond_t</a> *__restrict c, <a href="utils.md#ga75eeb2460f33f5f74cec3ff583ad9e94">pthread_mutex_t</a> *__restrict m, const struct <a href="timespec.md">timespec</a> *__restrict ts)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1976960410165628"><a name="p1976960410165628"></a><a name="p1976960410165628"></a>int </p>
<p id="p498083352165628"><a name="p498083352165628"></a><a name="p498083352165628"></a>Blocks the calling thread to wait for the condition set by <strong id="b686376510165628"><a name="b686376510165628"></a><a name="b686376510165628"></a>pthread_con_signal()</strong> for a period of time specified by <strong id="b2091089517165628"><a name="b2091089517165628"></a><a name="b2091089517165628"></a>ts</strong>. </p>
</td>
</tr>
<tr id="row1643322703165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1357914676165628"><a name="p1357914676165628"></a><a name="p1357914676165628"></a><a href="process.md#ga1c1ac7c8faaf8ad63e12bc3717f430f3">pthread_cond_broadcast</a> (<a href="utils.md#gaf2111a9da165bafea75dabf5cb131042">pthread_cond_t</a> *c)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1146857929165628"><a name="p1146857929165628"></a><a name="p1146857929165628"></a>int </p>
<p id="p2089278108165628"><a name="p2089278108165628"></a><a name="p2089278108165628"></a>Unblocks all threads that are currently blocked on the condition variable <strong id="b903628954165628"><a name="b903628954165628"></a><a name="b903628954165628"></a>cond</strong>. </p>
</td>
</tr>
<tr id="row1943527661165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p265267199165628"><a name="p265267199165628"></a><a name="p265267199165628"></a><a href="process.md#ga9b0f2c7dead8c628e081d76c86a1addc">pthread_cond_signal</a> (<a href="utils.md#gaf2111a9da165bafea75dabf5cb131042">pthread_cond_t</a> *c)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2034371162165628"><a name="p2034371162165628"></a><a name="p2034371162165628"></a>int </p>
<p id="p172380883165628"><a name="p172380883165628"></a><a name="p172380883165628"></a>Unblocks a thread. </p>
</td>
</tr>
<tr id="row1721450216165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p14681554165628"><a name="p14681554165628"></a><a name="p14681554165628"></a><a href="process.md#ga1cf4bc49696c1a30db31219aef994401">pthread_rwlock_init</a> (<a href="utils.md#gadc0b6b9df00a6c3ed0d7f9afe8934d05">pthread_rwlock_t</a> *__restrict rw, const <a href="utils.md#gaac7b93dc39852a3374d6c0802ceb7aa5">pthread_rwlockattr_t</a> *__restrict a)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2080603131165628"><a name="p2080603131165628"></a><a name="p2080603131165628"></a>int </p>
<p id="p2014881749165628"><a name="p2014881749165628"></a><a name="p2014881749165628"></a>Initializes a read-write lock. </p>
</td>
</tr>
<tr id="row417457010165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1334592386165628"><a name="p1334592386165628"></a><a name="p1334592386165628"></a><a href="process.md#gaa106bb55bdd0e120519d5412823f8b29">pthread_rwlock_destroy</a> (<a href="utils.md#gadc0b6b9df00a6c3ed0d7f9afe8934d05">pthread_rwlock_t</a> *rw)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p799885541165628"><a name="p799885541165628"></a><a name="p799885541165628"></a>int </p>
<p id="p1240505285165628"><a name="p1240505285165628"></a><a name="p1240505285165628"></a>Destroys a read-write lock. </p>
</td>
</tr>
<tr id="row1805893540165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p511120144165628"><a name="p511120144165628"></a><a name="p511120144165628"></a><a href="process.md#ga6153aca32112735053e6cc4a2a290feb">pthread_rwlock_rdlock</a> (<a href="utils.md#gadc0b6b9df00a6c3ed0d7f9afe8934d05">pthread_rwlock_t</a> *rw)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p734069025165628"><a name="p734069025165628"></a><a name="p734069025165628"></a>int </p>
<p id="p1214537471165628"><a name="p1214537471165628"></a><a name="p1214537471165628"></a>Applies a read lock to a read-write lock. </p>
</td>
</tr>
<tr id="row1548802842165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1122359432165628"><a name="p1122359432165628"></a><a name="p1122359432165628"></a><a href="process.md#ga3ba2170f06184d12543c4a5b78715fa7">pthread_rwlock_tryrdlock</a> (<a href="utils.md#gadc0b6b9df00a6c3ed0d7f9afe8934d05">pthread_rwlock_t</a> *rw)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1405667841165628"><a name="p1405667841165628"></a><a name="p1405667841165628"></a>int </p>
<p id="p141169682165628"><a name="p141169682165628"></a><a name="p141169682165628"></a>Attempts to apply a read lock to a read-write lock. </p>
</td>
</tr>
<tr id="row1550350426165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p14575826165628"><a name="p14575826165628"></a><a name="p14575826165628"></a><a href="process.md#ga8edbe14731fd79a80f72384334266715">pthread_rwlock_timedrdlock</a> (<a href="utils.md#gadc0b6b9df00a6c3ed0d7f9afe8934d05">pthread_rwlock_t</a> *__restrict rw, const struct <a href="timespec.md">timespec</a> *__restrict at)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p151168196165628"><a name="p151168196165628"></a><a name="p151168196165628"></a>int </p>
<p id="p268626350165628"><a name="p268626350165628"></a><a name="p268626350165628"></a>Blocks the calling thread to lock a read-write lock for reading. </p>
</td>
</tr>
<tr id="row1894029653165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1962346077165628"><a name="p1962346077165628"></a><a name="p1962346077165628"></a><a href="process.md#gaf2ca5563676ae3ac35d3bc7b3547e7f7">pthread_rwlock_wrlock</a> (<a href="utils.md#gadc0b6b9df00a6c3ed0d7f9afe8934d05">pthread_rwlock_t</a> *rw)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1832802154165628"><a name="p1832802154165628"></a><a name="p1832802154165628"></a>int </p>
<p id="p367303348165628"><a name="p367303348165628"></a><a name="p367303348165628"></a>Applies a write lock to a read-write lock. </p>
</td>
</tr>
<tr id="row445982403165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2094029385165628"><a name="p2094029385165628"></a><a name="p2094029385165628"></a><a href="process.md#ga2b5044e2da304ae9666fdd4e05479905">pthread_rwlock_trywrlock</a> (<a href="utils.md#gadc0b6b9df00a6c3ed0d7f9afe8934d05">pthread_rwlock_t</a> *rw)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p795022711165628"><a name="p795022711165628"></a><a name="p795022711165628"></a>int </p>
<p id="p291068819165628"><a name="p291068819165628"></a><a name="p291068819165628"></a>Attempts to apply a write lock to a read-write lock. </p>
</td>
</tr>
<tr id="row646609903165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1342481176165628"><a name="p1342481176165628"></a><a name="p1342481176165628"></a><a href="process.md#ga3fb8fb33e16653c5ad7b7f092959738e">pthread_rwlock_timedwrlock</a> (<a href="utils.md#gadc0b6b9df00a6c3ed0d7f9afe8934d05">pthread_rwlock_t</a> *__restrict rw, const struct <a href="timespec.md">timespec</a> *__restrict at)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p684259095165628"><a name="p684259095165628"></a><a name="p684259095165628"></a>int </p>
<p id="p1905556357165628"><a name="p1905556357165628"></a><a name="p1905556357165628"></a>Blocks the calling thread to lock a read-write lock for writing. </p>
</td>
</tr>
<tr id="row354888075165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1932936964165628"><a name="p1932936964165628"></a><a name="p1932936964165628"></a><a href="process.md#gaffd8a19e83fc87d865d103d6fbce8c4f">pthread_rwlock_unlock</a> (<a href="utils.md#gadc0b6b9df00a6c3ed0d7f9afe8934d05">pthread_rwlock_t</a> *rw)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1234029130165628"><a name="p1234029130165628"></a><a name="p1234029130165628"></a>int </p>
<p id="p34874219165628"><a name="p34874219165628"></a><a name="p34874219165628"></a>Unlocks a read-write lock. </p>
</td>
</tr>
<tr id="row37782499165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1026793994165628"><a name="p1026793994165628"></a><a name="p1026793994165628"></a><a href="process.md#ga665a56a7bed60c8eaa6c28af40d13cd4">pthread_spin_init</a> (<a href="utils.md#gae13db7661b1f8f7028dd7a88c8185fd2">pthread_spinlock_t</a> *s, int shared)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1855017126165628"><a name="p1855017126165628"></a><a name="p1855017126165628"></a>int </p>
<p id="p98125290165628"><a name="p98125290165628"></a><a name="p98125290165628"></a>Initializes a spin lock. </p>
</td>
</tr>
<tr id="row1563488947165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p65189525165628"><a name="p65189525165628"></a><a name="p65189525165628"></a><a href="process.md#ga822c2ff425ddad4c25b6a6092c6effff">pthread_spin_destroy</a> (<a href="utils.md#gae13db7661b1f8f7028dd7a88c8185fd2">pthread_spinlock_t</a> *s)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1417278465165628"><a name="p1417278465165628"></a><a name="p1417278465165628"></a>int </p>
<p id="p1970654479165628"><a name="p1970654479165628"></a><a name="p1970654479165628"></a>Destroys a spin lock. </p>
</td>
</tr>
<tr id="row1167939812165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1845362102165628"><a name="p1845362102165628"></a><a name="p1845362102165628"></a><a href="process.md#ga62cfd14d1f937a6e8f966e3a331bcf94">pthread_spin_lock</a> (<a href="utils.md#gae13db7661b1f8f7028dd7a88c8185fd2">pthread_spinlock_t</a> *s)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p525735560165628"><a name="p525735560165628"></a><a name="p525735560165628"></a>int </p>
<p id="p1580726242165628"><a name="p1580726242165628"></a><a name="p1580726242165628"></a>Locks a spin lock. </p>
</td>
</tr>
<tr id="row1956994979165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1002594556165628"><a name="p1002594556165628"></a><a name="p1002594556165628"></a><a href="process.md#ga084834fa2d06f173f086ce23ec1ea5d9">pthread_spin_trylock</a> (<a href="utils.md#gae13db7661b1f8f7028dd7a88c8185fd2">pthread_spinlock_t</a> *s)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2132713597165628"><a name="p2132713597165628"></a><a name="p2132713597165628"></a>int </p>
<p id="p1335481563165628"><a name="p1335481563165628"></a><a name="p1335481563165628"></a>Attempts to lock a spin lock. </p>
</td>
</tr>
<tr id="row818347133165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p563454510165628"><a name="p563454510165628"></a><a name="p563454510165628"></a><a href="process.md#ga3fe246007a85cee9d5f7af9b7d592b54">pthread_spin_unlock</a> (<a href="utils.md#gae13db7661b1f8f7028dd7a88c8185fd2">pthread_spinlock_t</a> *s)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p971264555165628"><a name="p971264555165628"></a><a name="p971264555165628"></a>int </p>
<p id="p1098953046165628"><a name="p1098953046165628"></a><a name="p1098953046165628"></a>Unlocks a spin lock. </p>
</td>
</tr>
<tr id="row1512468189165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1567428034165628"><a name="p1567428034165628"></a><a name="p1567428034165628"></a><a href="process.md#ga4a324cd758cae702213ea41882f4cf41">pthread_barrier_init</a> (<a href="utils.md#ga2f6d30b3b873012dbd361d3f7d52db59">pthread_barrier_t</a> *__restrict b, const <a href="utils.md#ga506b5743098d9d38526b2fd1e21f9457">pthread_barrierattr_t</a> *__restrict a, unsigned count)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1513958555165628"><a name="p1513958555165628"></a><a name="p1513958555165628"></a>int </p>
<p id="p2021767223165628"><a name="p2021767223165628"></a><a name="p2021767223165628"></a>Initializes a barrier. </p>
</td>
</tr>
<tr id="row821757953165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p705498383165628"><a name="p705498383165628"></a><a name="p705498383165628"></a><a href="process.md#gab05ae13769e61dea9c53ca7894743c8f">pthread_barrier_destroy</a> (<a href="utils.md#ga2f6d30b3b873012dbd361d3f7d52db59">pthread_barrier_t</a> *b)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p470286838165628"><a name="p470286838165628"></a><a name="p470286838165628"></a>int </p>
<p id="p22288090165628"><a name="p22288090165628"></a><a name="p22288090165628"></a>Destroys a barrier. </p>
</td>
</tr>
<tr id="row1477296675165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1209188129165628"><a name="p1209188129165628"></a><a name="p1209188129165628"></a><a href="process.md#gaf786372165ba080986ae4143928c5436">pthread_barrier_wait</a> (<a href="utils.md#ga2f6d30b3b873012dbd361d3f7d52db59">pthread_barrier_t</a> *b)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2128563697165628"><a name="p2128563697165628"></a><a name="p2128563697165628"></a>int </p>
<p id="p1279280398165628"><a name="p1279280398165628"></a><a name="p1279280398165628"></a>Synchronizes participating threads at a barrier. </p>
</td>
</tr>
<tr id="row1124613570165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p514814629165628"><a name="p514814629165628"></a><a name="p514814629165628"></a><a href="process.md#gaf4b7ced8ecff505380fe8216244a3764">pthread_key_create</a> (<a href="utils.md#gafeedfceab43831b6771f80aff6a519be">pthread_key_t</a> *key, void(*destructor)(void *))</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2138296802165628"><a name="p2138296802165628"></a><a name="p2138296802165628"></a>int </p>
<p id="p1387730872165628"><a name="p1387730872165628"></a><a name="p1387730872165628"></a>Creates a key for thread data. </p>
</td>
</tr>
<tr id="row1693387651165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p234762286165628"><a name="p234762286165628"></a><a name="p234762286165628"></a><a href="process.md#gaee96306dc79294927ee840bb4de2244b">pthread_key_delete</a> (<a href="utils.md#gafeedfceab43831b6771f80aff6a519be">pthread_key_t</a> key)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1834769701165628"><a name="p1834769701165628"></a><a name="p1834769701165628"></a>int </p>
<p id="p1042789955165628"><a name="p1042789955165628"></a><a name="p1042789955165628"></a>Deletes a key for thread data. </p>
</td>
</tr>
<tr id="row491010251165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p282658731165628"><a name="p282658731165628"></a><a name="p282658731165628"></a><a href="process.md#ga31469375891078185bda93f0e4411a2c">pthread_getspecific</a> (<a href="utils.md#gafeedfceab43831b6771f80aff6a519be">pthread_key_t</a> key)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p220895473165628"><a name="p220895473165628"></a><a name="p220895473165628"></a>void * </p>
<p id="p1644567252165628"><a name="p1644567252165628"></a><a name="p1644567252165628"></a>Obtains specific thread data. </p>
</td>
</tr>
<tr id="row711662059165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p362334083165628"><a name="p362334083165628"></a><a name="p362334083165628"></a><a href="process.md#ga2187333dd46ce08d9d2e044f79fad705">pthread_setspecific</a> (<a href="utils.md#gafeedfceab43831b6771f80aff6a519be">pthread_key_t</a> key, const void *value)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p125971931165628"><a name="p125971931165628"></a><a name="p125971931165628"></a>int </p>
<p id="p1341326938165628"><a name="p1341326938165628"></a><a name="p1341326938165628"></a>Sets specific thread data. </p>
</td>
</tr>
<tr id="row533528941165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1059023676165628"><a name="p1059023676165628"></a><a name="p1059023676165628"></a><a href="process.md#ga0b85ebb1e3aac081a4c0a5e85ae3cbe9">pthread_attr_init</a> (<a href="utils.md#gac8ee4471bbc35deb7589ac3615deb486">pthread_attr_t</a> *attr)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p907814237165628"><a name="p907814237165628"></a><a name="p907814237165628"></a>int </p>
<p id="p907186697165628"><a name="p907186697165628"></a><a name="p907186697165628"></a>Initializes a thread attribute object. </p>
</td>
</tr>
<tr id="row51472421165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1091219308165628"><a name="p1091219308165628"></a><a name="p1091219308165628"></a><a href="process.md#ga4bcdbf47c17c7dcc51e9f05f5cb56d81">pthread_attr_destroy</a> (<a href="utils.md#gac8ee4471bbc35deb7589ac3615deb486">pthread_attr_t</a> *attr)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1209553698165628"><a name="p1209553698165628"></a><a name="p1209553698165628"></a>int </p>
<p id="p346774227165628"><a name="p346774227165628"></a><a name="p346774227165628"></a>Destroys a thread attribute object. </p>
</td>
</tr>
<tr id="row1660408521165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1686977156165628"><a name="p1686977156165628"></a><a name="p1686977156165628"></a><a href="process.md#gaa8b692ecc3880fdd49a4d423ba1ce91e">pthread_attr_getguardsize</a> (const <a href="utils.md#gac8ee4471bbc35deb7589ac3615deb486">pthread_attr_t</a> *attr, size_t *guardsize)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2133469776165628"><a name="p2133469776165628"></a><a name="p2133469776165628"></a>int </p>
<p id="p47195628165628"><a name="p47195628165628"></a><a name="p47195628165628"></a>Obtains the guard size of a thread attribute object. </p>
</td>
</tr>
<tr id="row701636876165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p979876891165628"><a name="p979876891165628"></a><a name="p979876891165628"></a><a href="process.md#ga532b31c11a9d87663053c5342400758c">pthread_attr_setguardsize</a> (<a href="utils.md#gac8ee4471bbc35deb7589ac3615deb486">pthread_attr_t</a> *attr, size_t guardsize)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1746471809165628"><a name="p1746471809165628"></a><a name="p1746471809165628"></a>int </p>
<p id="p21729383165628"><a name="p21729383165628"></a><a name="p21729383165628"></a>Sets the guard size for a thread attribute object. </p>
</td>
</tr>
<tr id="row2002087070165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1341405601165628"><a name="p1341405601165628"></a><a name="p1341405601165628"></a><a href="process.md#gae23600d4670359ab12bfba20db2c9a37">pthread_attr_getstacksize</a> (const <a href="utils.md#gac8ee4471bbc35deb7589ac3615deb486">pthread_attr_t</a> *attr, size_t *stacksize)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1413092271165628"><a name="p1413092271165628"></a><a name="p1413092271165628"></a>int </p>
<p id="p1371169292165628"><a name="p1371169292165628"></a><a name="p1371169292165628"></a>Obtains the stack size of a thread attribute object. </p>
</td>
</tr>
<tr id="row1954503642165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p390780972165628"><a name="p390780972165628"></a><a name="p390780972165628"></a><a href="process.md#ga812a9a455ae2ef2bb0dca4fff201a281">pthread_attr_setstacksize</a> (<a href="utils.md#gac8ee4471bbc35deb7589ac3615deb486">pthread_attr_t</a> *attr, size_t stacksize)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p765187955165628"><a name="p765187955165628"></a><a name="p765187955165628"></a>int </p>
<p id="p1754945322165628"><a name="p1754945322165628"></a><a name="p1754945322165628"></a>Sets the stack size for a thread attribute object. </p>
</td>
</tr>
<tr id="row397173073165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1393734740165628"><a name="p1393734740165628"></a><a name="p1393734740165628"></a><a href="process.md#ga391c34da42e68ddd24f5ee0c070d5c4f">pthread_attr_getdetachstate</a> (const <a href="utils.md#gac8ee4471bbc35deb7589ac3615deb486">pthread_attr_t</a> *attr, int *detachstate)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1572412229165628"><a name="p1572412229165628"></a><a name="p1572412229165628"></a>int </p>
<p id="p1069875313165628"><a name="p1069875313165628"></a><a name="p1069875313165628"></a>Obtains the detach state of a thread attribute object. </p>
</td>
</tr>
<tr id="row191986975165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p178616856165628"><a name="p178616856165628"></a><a name="p178616856165628"></a><a href="process.md#gae6ee78c307d8467b34a9b0c330993a54">pthread_attr_setdetachstate</a> (<a href="utils.md#gac8ee4471bbc35deb7589ac3615deb486">pthread_attr_t</a> *attr, int detachstate)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2137569246165628"><a name="p2137569246165628"></a><a name="p2137569246165628"></a>int </p>
<p id="p1768758222165628"><a name="p1768758222165628"></a><a name="p1768758222165628"></a>Sets the detach state for a thread attribute object. </p>
</td>
</tr>
<tr id="row1983509089165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1819756048165628"><a name="p1819756048165628"></a><a name="p1819756048165628"></a><a href="process.md#gaec19ad460995a9fe8aeb4eaf2bb1ed1d">pthread_attr_getstack</a> (const <a href="utils.md#gac8ee4471bbc35deb7589ac3615deb486">pthread_attr_t</a> *attr, void **stackaddr, size_t *stacksize)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1551996798165628"><a name="p1551996798165628"></a><a name="p1551996798165628"></a>int </p>
<p id="p470971483165628"><a name="p470971483165628"></a><a name="p470971483165628"></a>Obtains stack attributes of a thread attribute object. </p>
</td>
</tr>
<tr id="row2092911239165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1791694317165628"><a name="p1791694317165628"></a><a name="p1791694317165628"></a><a href="process.md#ga94ede89b99a3a4fa17e516d30aaf3409">pthread_attr_setstack</a> (<a href="utils.md#gac8ee4471bbc35deb7589ac3615deb486">pthread_attr_t</a> *attr, void *stackaddr, size_t stacksize)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2000561229165628"><a name="p2000561229165628"></a><a name="p2000561229165628"></a>int </p>
<p id="p1799531463165628"><a name="p1799531463165628"></a><a name="p1799531463165628"></a>Sets stack attributes for a thread attribute object. </p>
</td>
</tr>
<tr id="row1299694341165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p28037852165628"><a name="p28037852165628"></a><a name="p28037852165628"></a><a href="process.md#gabfd252cd45081231018030e3878efa06">pthread_attr_getscope</a> (const <a href="utils.md#gac8ee4471bbc35deb7589ac3615deb486">pthread_attr_t</a> *attr, int *scope)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1729838960165628"><a name="p1729838960165628"></a><a name="p1729838960165628"></a>int </p>
<p id="p238788985165628"><a name="p238788985165628"></a><a name="p238788985165628"></a>Obtains contention scope attributes of a thread attribute object. </p>
</td>
</tr>
<tr id="row1701654129165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1981224912165628"><a name="p1981224912165628"></a><a name="p1981224912165628"></a><a href="process.md#ga294aaacf59f34effeef978242cf08cbe">pthread_attr_setscope</a> (<a href="utils.md#gac8ee4471bbc35deb7589ac3615deb486">pthread_attr_t</a> *attr, int scope)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p499365270165628"><a name="p499365270165628"></a><a name="p499365270165628"></a>int </p>
<p id="p1880869208165628"><a name="p1880869208165628"></a><a name="p1880869208165628"></a>Sets contention scope attributes for a thread attribute object. </p>
</td>
</tr>
<tr id="row801231299165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1513476727165628"><a name="p1513476727165628"></a><a name="p1513476727165628"></a><a href="process.md#gaec4d8127833d1a573aa82539f898a8ed">pthread_attr_getschedpolicy</a> (const <a href="utils.md#gac8ee4471bbc35deb7589ac3615deb486">pthread_attr_t</a> *attr, int *schedpolicy)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1117648780165628"><a name="p1117648780165628"></a><a name="p1117648780165628"></a>int </p>
<p id="p1849446680165628"><a name="p1849446680165628"></a><a name="p1849446680165628"></a>Obtains scheduling policy attributes of a thread attribute object. </p>
</td>
</tr>
<tr id="row837474097165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1666209115165628"><a name="p1666209115165628"></a><a name="p1666209115165628"></a><a href="process.md#gab6cb2eb73f04abf328b2f39777c35dca">pthread_attr_setschedpolicy</a> (<a href="utils.md#gac8ee4471bbc35deb7589ac3615deb486">pthread_attr_t</a> *attr, int schedpolicy)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p466225365165628"><a name="p466225365165628"></a><a name="p466225365165628"></a>int </p>
<p id="p418979820165628"><a name="p418979820165628"></a><a name="p418979820165628"></a>Sets scheduling policy attributes for a thread attribute object. </p>
</td>
</tr>
<tr id="row470591909165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p44081326165628"><a name="p44081326165628"></a><a name="p44081326165628"></a><a href="process.md#gafd3d272d702481044f8a8cd253fd9b47">pthread_attr_getschedparam</a> (const <a href="utils.md#gac8ee4471bbc35deb7589ac3615deb486">pthread_attr_t</a> *attr, struct <a href="sched_param.md">sched_param</a> *param)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1036260842165628"><a name="p1036260842165628"></a><a name="p1036260842165628"></a>int </p>
<p id="p965060546165628"><a name="p965060546165628"></a><a name="p965060546165628"></a>Obtains scheduling parameter attributes of a thread attribute object. </p>
</td>
</tr>
<tr id="row1717407726165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p865978512165628"><a name="p865978512165628"></a><a name="p865978512165628"></a><a href="process.md#ga579e6529f0ce482312a5e77ac61cb4d5">pthread_attr_setschedparam</a> (<a href="utils.md#gac8ee4471bbc35deb7589ac3615deb486">pthread_attr_t</a> *attr, const struct <a href="sched_param.md">sched_param</a> *param)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1815588276165628"><a name="p1815588276165628"></a><a name="p1815588276165628"></a>int </p>
<p id="p160636128165628"><a name="p160636128165628"></a><a name="p160636128165628"></a>Sets scheduling parameter attributes for a thread attribute object. </p>
</td>
</tr>
<tr id="row1696738216165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1799707919165628"><a name="p1799707919165628"></a><a name="p1799707919165628"></a><a href="process.md#ga79a77b688c30213e5e52e6be178cde4e">pthread_attr_getinheritsched</a> (const <a href="utils.md#gac8ee4471bbc35deb7589ac3615deb486">pthread_attr_t</a> *attr, int *inheritsched)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1395183449165628"><a name="p1395183449165628"></a><a name="p1395183449165628"></a>int </p>
<p id="p1359979468165628"><a name="p1359979468165628"></a><a name="p1359979468165628"></a>Obtains inherit scheduler attributes of a thread attribute object. </p>
</td>
</tr>
<tr id="row495842861165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2061984335165628"><a name="p2061984335165628"></a><a name="p2061984335165628"></a><a href="process.md#gad437fe8caa3ef9f0cb7d69f6f6479df9">pthread_attr_setinheritsched</a> (<a href="utils.md#gac8ee4471bbc35deb7589ac3615deb486">pthread_attr_t</a> *attr, int inheritsched)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1980836097165628"><a name="p1980836097165628"></a><a name="p1980836097165628"></a>int </p>
<p id="p1206339456165628"><a name="p1206339456165628"></a><a name="p1206339456165628"></a>Sets inherit scheduler attributes for a thread attribute object. </p>
</td>
</tr>
<tr id="row922068658165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1493501604165628"><a name="p1493501604165628"></a><a name="p1493501604165628"></a><a href="process.md#ga2321aabf58224b06021185708d0f9658">pthread_mutexattr_destroy</a> (<a href="utils.md#gaf2212c79151cc55f3a41c430908f3909">pthread_mutexattr_t</a> *attr)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1632550608165628"><a name="p1632550608165628"></a><a name="p1632550608165628"></a>int </p>
<p id="p1163351776165628"><a name="p1163351776165628"></a><a name="p1163351776165628"></a>Destroys a mutex attribute object. </p>
</td>
</tr>
<tr id="row1854511751165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p73133404165628"><a name="p73133404165628"></a><a name="p73133404165628"></a><a href="process.md#ga4789e2d3ada7aab2af1458bfec53ee3c">pthread_mutexattr_gettype</a> (const <a href="utils.md#gaf2212c79151cc55f3a41c430908f3909">pthread_mutexattr_t</a> *__restrict attr, int *__restrict type)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p565910748165628"><a name="p565910748165628"></a><a name="p565910748165628"></a>int </p>
<p id="p417949281165628"><a name="p417949281165628"></a><a name="p417949281165628"></a>Obtains the mutex type attribute. </p>
</td>
</tr>
<tr id="row959330288165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2047732853165628"><a name="p2047732853165628"></a><a name="p2047732853165628"></a><a href="process.md#gaf98f6b6c483077a39d1400b1de1577b8">pthread_mutexattr_init</a> (<a href="utils.md#gaf2212c79151cc55f3a41c430908f3909">pthread_mutexattr_t</a> *attr)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1978495184165628"><a name="p1978495184165628"></a><a name="p1978495184165628"></a>int </p>
<p id="p1880511815165628"><a name="p1880511815165628"></a><a name="p1880511815165628"></a>Initializes a mutex attribute object. </p>
</td>
</tr>
<tr id="row252790083165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1264747965165628"><a name="p1264747965165628"></a><a name="p1264747965165628"></a><a href="process.md#ga8387c80e660e9426f801ac0217ecfae5">pthread_mutexattr_settype</a> (<a href="utils.md#gaf2212c79151cc55f3a41c430908f3909">pthread_mutexattr_t</a> *attr, int type)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1701382776165628"><a name="p1701382776165628"></a><a name="p1701382776165628"></a>int </p>
<p id="p1236447955165628"><a name="p1236447955165628"></a><a name="p1236447955165628"></a>Sets the mutex type attribute. </p>
</td>
</tr>
<tr id="row922919187165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1527793133165628"><a name="p1527793133165628"></a><a name="p1527793133165628"></a><a href="process.md#ga487a919ab54fd47c8464507031957df0">pthread_condattr_init</a> (<a href="utils.md#gaa992c0a75a463b1c095248eec28086d3">pthread_condattr_t</a> *a)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1597150006165628"><a name="p1597150006165628"></a><a name="p1597150006165628"></a>int </p>
<p id="p1859127244165628"><a name="p1859127244165628"></a><a name="p1859127244165628"></a>Initializes a condition variable attribute object. </p>
</td>
</tr>
<tr id="row697905324165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p155729414165628"><a name="p155729414165628"></a><a name="p155729414165628"></a><a href="process.md#ga8ab009937339c899a5197eea2e48e6a1">pthread_condattr_destroy</a> (<a href="utils.md#gaa992c0a75a463b1c095248eec28086d3">pthread_condattr_t</a> *a)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1666384324165628"><a name="p1666384324165628"></a><a name="p1666384324165628"></a>int </p>
<p id="p621413038165628"><a name="p621413038165628"></a><a name="p621413038165628"></a>Destroys a condition variable attribute object. </p>
</td>
</tr>
<tr id="row285807687165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2136049947165628"><a name="p2136049947165628"></a><a name="p2136049947165628"></a><a href="process.md#gaaf7ac0f85233c0effaf850a9c65b6d68">pthread_condattr_setclock</a> (<a href="utils.md#gaa992c0a75a463b1c095248eec28086d3">pthread_condattr_t</a> *a, <a href="utils.md#ga391e4a62662054e5d3e1e071b8e54329">clockid_t</a> clk)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1104125955165628"><a name="p1104125955165628"></a><a name="p1104125955165628"></a>int </p>
<p id="p1770702887165628"><a name="p1770702887165628"></a><a name="p1770702887165628"></a>Sets a clock for a condition variable attribute object. </p>
</td>
</tr>
<tr id="row102321005165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p532042629165628"><a name="p532042629165628"></a><a name="p532042629165628"></a><a href="process.md#gadcf908971c2ea15ced780025772084e3">pthread_condattr_getclock</a> (const <a href="utils.md#gaa992c0a75a463b1c095248eec28086d3">pthread_condattr_t</a> *__restrict a, <a href="utils.md#ga391e4a62662054e5d3e1e071b8e54329">clockid_t</a> *__restrict clk)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1973084691165628"><a name="p1973084691165628"></a><a name="p1973084691165628"></a>int </p>
<p id="p1339068599165628"><a name="p1339068599165628"></a><a name="p1339068599165628"></a>Obtains the clock of a condition variable attribute object. </p>
</td>
</tr>
<tr id="row347467463165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1265940780165628"><a name="p1265940780165628"></a><a name="p1265940780165628"></a><a href="process.md#ga9d831af0179ed16d1b6cbeba0304810b">pthread_rwlockattr_init</a> (<a href="utils.md#gaac7b93dc39852a3374d6c0802ceb7aa5">pthread_rwlockattr_t</a> *attr)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p411170145165628"><a name="p411170145165628"></a><a name="p411170145165628"></a>int </p>
<p id="p947445521165628"><a name="p947445521165628"></a><a name="p947445521165628"></a>Initializes a read-write lock attribute object. </p>
</td>
</tr>
<tr id="row672262484165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p674933286165628"><a name="p674933286165628"></a><a name="p674933286165628"></a><a href="process.md#ga78a54e67f0afe2601dbda0a904fa0bdf">pthread_rwlockattr_destroy</a> (<a href="utils.md#gaac7b93dc39852a3374d6c0802ceb7aa5">pthread_rwlockattr_t</a> *attr)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1422891120165628"><a name="p1422891120165628"></a><a name="p1422891120165628"></a>int </p>
<p id="p199224282165628"><a name="p199224282165628"></a><a name="p199224282165628"></a>Destroys a read-write lock attribute object. </p>
</td>
</tr>
<tr id="row1882117300165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1911792657165628"><a name="p1911792657165628"></a><a name="p1911792657165628"></a><a href="process.md#ga3bd99d89e352ccc51d5b94d157f1218b">pthread_barrierattr_destroy</a> (<a href="utils.md#ga506b5743098d9d38526b2fd1e21f9457">pthread_barrierattr_t</a> *a)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1512477803165628"><a name="p1512477803165628"></a><a name="p1512477803165628"></a>int </p>
<p id="p407997328165628"><a name="p407997328165628"></a><a name="p407997328165628"></a>Destroys a barrier attribute object. </p>
</td>
</tr>
<tr id="row978186324165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2120900637165628"><a name="p2120900637165628"></a><a name="p2120900637165628"></a><a href="process.md#ga2ff720e06488668dc0ae6779755946e6">pthread_barrierattr_init</a> (<a href="utils.md#ga506b5743098d9d38526b2fd1e21f9457">pthread_barrierattr_t</a> *a)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p95492402165628"><a name="p95492402165628"></a><a name="p95492402165628"></a>int </p>
<p id="p1558616504165628"><a name="p1558616504165628"></a><a name="p1558616504165628"></a>Initializes a barrier attribute object. </p>
</td>
</tr>
<tr id="row1885421425165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2050200408165628"><a name="p2050200408165628"></a><a name="p2050200408165628"></a><a href="process.md#ga80008474c3d68e9880da960a53d2f430">pthread_atfork</a> (void(*prepare)(void), void(*parent)(void), void(*child)(void))</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p844642494165628"><a name="p844642494165628"></a><a name="p844642494165628"></a>int </p>
<p id="p1990159209165628"><a name="p1990159209165628"></a><a name="p1990159209165628"></a>Registers a fork handler to be called before and after <a href="utils.md#gaa4e4714e6e8927c80b2553a40094b6d9">fork()</a>. </p>
</td>
</tr>
<tr id="row1841113359165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2139543934165628"><a name="p2139543934165628"></a><a name="p2139543934165628"></a><a href="process.md#ga68bc26522daf418f3cc78360925374ef">pthread_cleanup_push</a> (void(*routine)(void *), void *arg)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1895330178165628"><a name="p1895330178165628"></a><a name="p1895330178165628"></a>void </p>
<p id="p1959478127165628"><a name="p1959478127165628"></a><a name="p1959478127165628"></a>Pushes the routine to the top of the clean-up handler stack. </p>
</td>
</tr>
<tr id="row1369611769165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2109652598165628"><a name="p2109652598165628"></a><a name="p2109652598165628"></a><a href="process.md#gafbe33fb00cd24693796a0870a3374631">pthread_cleanup_pop</a> (int execute)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p641355250165628"><a name="p641355250165628"></a><a name="p641355250165628"></a>void </p>
<p id="p772133073165628"><a name="p772133073165628"></a><a name="p772133073165628"></a>Removes the routine at the top of the clean-up handler stack. </p>
</td>
</tr>
<tr id="row2089854633165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p109691754165628"><a name="p109691754165628"></a><a name="p109691754165628"></a><a href="process.md#ga6bdca4b2c8a436c4651fb5e8d462408b">pthread_getattr_np</a> (<a href="utils.md#ga5250f47a8a0402a78bb51a2133e13c1f">pthread_t</a> thread, <a href="utils.md#gac8ee4471bbc35deb7589ac3615deb486">pthread_attr_t</a> *attr)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p396253411165628"><a name="p396253411165628"></a><a name="p396253411165628"></a>int </p>
<p id="p1560885910165628"><a name="p1560885910165628"></a><a name="p1560885910165628"></a>Obtains the attributes of a created thread. </p>
</td>
</tr>
<tr id="row1658581252165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2114467986165628"><a name="p2114467986165628"></a><a name="p2114467986165628"></a><a href="process.md#ga185584d77295432838d8b839d916f160">pthread_setname_np</a> (<a href="utils.md#ga5250f47a8a0402a78bb51a2133e13c1f">pthread_t</a> pthread, const char *name)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1218800918165628"><a name="p1218800918165628"></a><a name="p1218800918165628"></a>int </p>
<p id="p224475929165628"><a name="p224475929165628"></a><a name="p224475929165628"></a>Sets the thread name. </p>
</td>
</tr>
<tr id="row2107140380165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p489244632165628"><a name="p489244632165628"></a><a name="p489244632165628"></a><a href="process.md#ga051df55ea1131f70f6f9356865a36798">pthread_getaffinity_np</a> (<a href="utils.md#ga5250f47a8a0402a78bb51a2133e13c1f">pthread_t</a> td, size_t size, cpu_set_t *set)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2145988521165628"><a name="p2145988521165628"></a><a name="p2145988521165628"></a>int </p>
<p id="p1739619491165628"><a name="p1739619491165628"></a><a name="p1739619491165628"></a>Gets the thread affinity. </p>
</td>
</tr>
<tr id="row1680459333165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p411846554165628"><a name="p411846554165628"></a><a name="p411846554165628"></a><a href="process.md#ga217f60f9431c453c74b675e72bba307d">pthread_setaffinity_np</a> (<a href="utils.md#ga5250f47a8a0402a78bb51a2133e13c1f">pthread_t</a> td, size_t size, const cpu_set_t *set)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1521529426165628"><a name="p1521529426165628"></a><a name="p1521529426165628"></a>int </p>
<p id="p1038536051165628"><a name="p1038536051165628"></a><a name="p1038536051165628"></a>Sets the thread affinity. </p>
</td>
</tr>
</tbody>
</table>

