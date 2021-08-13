# POSIX Support<a name="EN-US_TOPIC_0000001078589734"></a>

-   [Basic Concepts](#section1757915134139)
-   [Development Guidelines](#section1573664211318)
    -   [Available APIs](#section10429150121317)
    -   [Important Notes](#section109174418147)
    -   [Development Example](#section206149278155)


## Basic Concepts<a name="section1757915134139"></a>

The OpenHarmony kernel uses the  **musl libc**  library and self-developed APIs and supports the Portable Operating System Interface \(POSIX\). You can develop components and applications working on the kernel based on the POSIX.

## Development Guidelines<a name="section1573664211318"></a>

### Available APIs<a name="section10429150121317"></a>

**Table  1**  Available APIs

<a name="table895334620813"></a>
<table><thead align="left"><tr id="row395474617817"><th class="cellrowborder" valign="top" width="7.12%" id="mcps1.2.5.1.1"><p id="p6353032359"><a name="p6353032359"></a><a name="p6353032359"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="17.150000000000002%" id="mcps1.2.5.1.2"><p id="p8806202894616"><a name="p8806202894616"></a><a name="p8806202894616"></a>Header File</p>
</th>
<th class="cellrowborder" valign="top" width="52.27%" id="mcps1.2.5.1.3"><p id="p195434611811"><a name="p195434611811"></a><a name="p195434611811"></a>API</p>
</th>
<th class="cellrowborder" valign="top" width="23.46%" id="mcps1.2.5.1.4"><p id="p8954346084"><a name="p8954346084"></a><a name="p8954346084"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row8954646388"><td class="cellrowborder" rowspan="27" valign="top" width="7.12%" headers="mcps1.2.5.1.1 "><p id="p109544461689"><a name="p109544461689"></a><a name="p109544461689"></a>process</p>
</td>
<td class="cellrowborder" valign="top" width="17.150000000000002%" headers="mcps1.2.5.1.2 "><p id="p12806628134615"><a name="p12806628134615"></a><a name="p12806628134615"></a>#include &lt;stdlib.h&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="52.27%" headers="mcps1.2.5.1.3 "><p id="p39542461183"><a name="p39542461183"></a><a name="p39542461183"></a>void abort(void);</p>
</td>
<td class="cellrowborder" valign="top" width="23.46%" headers="mcps1.2.5.1.4 "><p id="p1795410468811"><a name="p1795410468811"></a><a name="p1795410468811"></a>Terminates the execution of a thread.</p>
</td>
</tr>
<tr id="row7559152918428"><td class="cellrowborder" valign="top" headers="mcps1.2.5.1.1 "><p id="p15806112816462"><a name="p15806112816462"></a><a name="p15806112816462"></a>#include &lt;assert.h&gt;</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.5.1.2 "><p id="p14560429154220"><a name="p14560429154220"></a><a name="p14560429154220"></a>void assert(scalar expression);</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.5.1.3 "><p id="p14560162914424"><a name="p14560162914424"></a><a name="p14560162914424"></a>Terminates the thread if the assertion is false.</p>
</td>
</tr>
<tr id="row113215211438"><td class="cellrowborder" valign="top" headers="mcps1.2.5.1.1 "><p id="p1980612289469"><a name="p1980612289469"></a><a name="p1980612289469"></a>#include &lt;pthread.h&gt;</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.5.1.2 "><p id="p21321621194313"><a name="p21321621194313"></a><a name="p21321621194313"></a>int pthread_cond_destroy(pthread_cond_t *cond);</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.5.1.3 "><p id="p161321721154314"><a name="p161321721154314"></a><a name="p161321721154314"></a>Destroys a condition variable.</p>
</td>
</tr>
<tr id="row313302164314"><td class="cellrowborder" valign="top" headers="mcps1.2.5.1.1 "><p id="p128061128114611"><a name="p128061128114611"></a><a name="p128061128114611"></a>#include &lt;pthread.h&gt;</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.5.1.2 "><p id="p10133172144317"><a name="p10133172144317"></a><a name="p10133172144317"></a>int pthread_cond_init(pthread_cond_t *restrict cond, const pthread_condattr_t *restrict attr);</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.5.1.3 "><p id="p513392104319"><a name="p513392104319"></a><a name="p513392104319"></a>Initializes a condition variable.</p>
</td>
</tr>
<tr id="row201421029104316"><td class="cellrowborder" valign="top" headers="mcps1.2.5.1.1 "><p id="p480762815462"><a name="p480762815462"></a><a name="p480762815462"></a>#include &lt;pthread.h&gt;</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.5.1.2 "><p id="p1914212964318"><a name="p1914212964318"></a><a name="p1914212964318"></a>int pthread_cond_timedwait(pthread_cond_t *restrict cond, pthread_mutex_t *restrict mutex, const struct timespec *restrict abstime);</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.5.1.3 "><p id="p14142102984312"><a name="p14142102984312"></a><a name="p14142102984312"></a>Waits for the condition.</p>
</td>
</tr>
<tr id="row91431829124311"><td class="cellrowborder" valign="top" headers="mcps1.2.5.1.1 "><p id="p58071528154619"><a name="p58071528154619"></a><a name="p58071528154619"></a>#include &lt;pthread.h&gt;</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.5.1.2 "><p id="p201431529184319"><a name="p201431529184319"></a><a name="p201431529184319"></a>int pthread_condattr_init(pthread_condattr_t *attr);</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.5.1.3 "><p id="p5143162974313"><a name="p5143162974313"></a><a name="p5143162974313"></a>Initializes a condition variable attribute object.</p>
</td>
</tr>
<tr id="row6659429144818"><td class="cellrowborder" valign="top" headers="mcps1.2.5.1.1 "><p id="p18659162910484"><a name="p18659162910484"></a><a name="p18659162910484"></a>#include &lt;pthread.h&gt;</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.5.1.2 "><p id="p15659182911485"><a name="p15659182911485"></a><a name="p15659182911485"></a>int pthread_mutex_unlock(pthread_mutex_t *mutex);</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.5.1.3 "><p id="p465922994813"><a name="p465922994813"></a><a name="p465922994813"></a>Unlocks a mutex.</p>
</td>
</tr>
<tr id="row5935041188"><td class="cellrowborder" valign="top" headers="mcps1.2.5.1.1 "><p id="p17616642312"><a name="p17616642312"></a><a name="p17616642312"></a>#include &lt;pthread.h&gt;</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.5.1.2 "><p id="p679871717159"><a name="p679871717159"></a><a name="p679871717159"></a>int pthread_create(pthread_t *thread, const pthread_attr_t *attr, void *(*start_routine)(void *), void *arg);</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.5.1.3 "><p id="p13678824091"><a name="p13678824091"></a><a name="p13678824091"></a>Creates a thread.</p>
</td>
</tr>
<tr id="row093624161818"><td class="cellrowborder" valign="top" headers="mcps1.2.5.1.1 "><p id="p442110115321"><a name="p442110115321"></a><a name="p442110115321"></a>#include &lt;pthread.h&gt;</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.5.1.2 "><p id="p747015012202"><a name="p747015012202"></a><a name="p747015012202"></a>int pthread_join(pthread_t thread, void **retval);</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.5.1.3 "><p id="p136799249910"><a name="p136799249910"></a><a name="p136799249910"></a>Waits for a thread to terminate.</p>
</td>
</tr>
<tr id="row1993684181816"><td class="cellrowborder" valign="top" headers="mcps1.2.5.1.1 "><p id="p66791224496"><a name="p66791224496"></a><a name="p66791224496"></a>#include &lt;pthread.h&gt;</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.5.1.2 "><p id="p967910241794"><a name="p967910241794"></a><a name="p967910241794"></a>pthread_t pthread_self(void);</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.5.1.3 "><p id="p196794241196"><a name="p196794241196"></a><a name="p196794241196"></a>Obtains the ID of the current thread.</p>
</td>
</tr>
<tr id="row1693664161817"><td class="cellrowborder" valign="top" headers="mcps1.2.5.1.1 "><p id="p767910241690"><a name="p767910241690"></a><a name="p767910241690"></a>#include &lt;pthread.h&gt;</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.5.1.2 "><p id="p134701550192014"><a name="p134701550192014"></a><a name="p134701550192014"></a>int pthread_getschedparam(pthread_t thread, int *policy, struct sched_param *param);</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.5.1.3 "><p id="p1567914241698"><a name="p1567914241698"></a><a name="p1567914241698"></a>Obtains the scheduling policy and parameters of a thread.</p>
</td>
</tr>
<tr id="row3936146182"><td class="cellrowborder" valign="top" headers="mcps1.2.5.1.1 "><p id="p192131110122014"><a name="p192131110122014"></a><a name="p192131110122014"></a>#include &lt;pthread.h&gt;</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.5.1.2 "><p id="p767922414914"><a name="p767922414914"></a><a name="p767922414914"></a>int pthread_setschedparam(pthread_t thread, int policy, const struct sched_param *param);</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.5.1.3 "><p id="p1980015172155"><a name="p1980015172155"></a><a name="p1980015172155"></a>Sets a scheduling policy and parameters for a thread.</p>
</td>
</tr>
<tr id="row1793684141816"><td class="cellrowborder" valign="top" headers="mcps1.2.5.1.1 "><p id="p5509413122114"><a name="p5509413122114"></a><a name="p5509413122114"></a>#include &lt;pthread.h&gt;</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.5.1.2 "><p id="p1319921111419"><a name="p1319921111419"></a><a name="p1319921111419"></a>int pthread_mutex_init(pthread_mutex_t *__restrict m, const pthread_mutexattr_t *__restrict a);</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.5.1.3 "><p id="p1199313147"><a name="p1199313147"></a><a name="p1199313147"></a>Initializes a mutex.</p>
</td>
</tr>
<tr id="row2093718401811"><td class="cellrowborder" valign="top" headers="mcps1.2.5.1.1 "><p id="p719910161417"><a name="p719910161417"></a><a name="p719910161417"></a>#include &lt;pthread.h&gt;</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.5.1.2 "><p id="p7199417147"><a name="p7199417147"></a><a name="p7199417147"></a>int pthread_mutex_lock(pthread_mutex_t *m);</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.5.1.3 "><p id="p111991415144"><a name="p111991415144"></a><a name="p111991415144"></a>Locks a mutex.</p>
</td>
</tr>
<tr id="row09371421820"><td class="cellrowborder" valign="top" headers="mcps1.2.5.1.1 "><p id="p172001012149"><a name="p172001012149"></a><a name="p172001012149"></a>#include &lt;pthread.h&gt;</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.5.1.2 "><p id="p122003120145"><a name="p122003120145"></a><a name="p122003120145"></a>int pthread_mutex_trylock(pthread_mutex_t *m);</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.5.1.3 "><p id="p1920021121417"><a name="p1920021121417"></a><a name="p1920021121417"></a>Attempts to lock a mutex.</p>
</td>
</tr>
<tr id="row2937346182"><td class="cellrowborder" valign="top" headers="mcps1.2.5.1.1 "><p id="p1983818513394"><a name="p1983818513394"></a><a name="p1983818513394"></a>#include &lt;pthread.h&gt;</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.5.1.2 "><p id="p18471150172017"><a name="p18471150172017"></a><a name="p18471150172017"></a>int pthread_mutex_destroy(pthread_mutex_t *m);</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.5.1.3 "><p id="p720013117146"><a name="p720013117146"></a><a name="p720013117146"></a>Destroys a mutex.</p>
</td>
</tr>
<tr id="row20937849181"><td class="cellrowborder" valign="top" headers="mcps1.2.5.1.1 "><p id="p202000114144"><a name="p202000114144"></a><a name="p202000114144"></a>#include &lt;pthread.h&gt;</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.5.1.2 "><p id="p20471950112011"><a name="p20471950112011"></a><a name="p20471950112011"></a>int pthread_attr_init(pthread_attr_t *attr);</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.5.1.3 "><p id="p1020018101412"><a name="p1020018101412"></a><a name="p1020018101412"></a>Initializes a thread attribute object.</p>
</td>
</tr>
<tr id="row1693844131816"><td class="cellrowborder" valign="top" headers="mcps1.2.5.1.1 "><p id="p6200116141"><a name="p6200116141"></a><a name="p6200116141"></a>#include &lt;pthread.h&gt;</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.5.1.2 "><p id="p2471135014201"><a name="p2471135014201"></a><a name="p2471135014201"></a>int pthread_attr_destroy(pthread_attr_t *attr);</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.5.1.3 "><p id="p72003112144"><a name="p72003112144"></a><a name="p72003112144"></a>Destroys a thread attribute object.</p>
</td>
</tr>
<tr id="row109389413181"><td class="cellrowborder" valign="top" headers="mcps1.2.5.1.1 "><p id="p3200141201420"><a name="p3200141201420"></a><a name="p3200141201420"></a>#include &lt;pthread.h&gt;</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.5.1.2 "><p id="p1947155012207"><a name="p1947155012207"></a><a name="p1947155012207"></a>int pthread_attr_getstacksize(const pthread_attr_t *attr, size_t *stacksize);</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.5.1.3 "><p id="p1620019116144"><a name="p1620019116144"></a><a name="p1620019116144"></a>Obtains the stack size of a thread attribute object.</p>
</td>
</tr>
<tr id="row960061102113"><td class="cellrowborder" valign="top" headers="mcps1.2.5.1.1 "><p id="p1220112113141"><a name="p1220112113141"></a><a name="p1220112113141"></a>#include &lt;pthread.h&gt;</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.5.1.2 "><p id="p4452036191511"><a name="p4452036191511"></a><a name="p4452036191511"></a>int pthread_attr_setstacksize(pthread_attr_t *attr, size_t stacksize);</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.5.1.3 "><p id="p44515367157"><a name="p44515367157"></a><a name="p44515367157"></a>Sets the stack size for a thread attribute object.</p>
</td>
</tr>
<tr id="row860031182111"><td class="cellrowborder" valign="top" headers="mcps1.2.5.1.1 "><p id="p20162113832818"><a name="p20162113832818"></a><a name="p20162113832818"></a>#include &lt;pthread.h&gt;</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.5.1.2 "><p id="p10472185032013"><a name="p10472185032013"></a><a name="p10472185032013"></a>int pthread_attr_getschedparam(const pthread_attr_t *attr, struct sched_param *param);</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.5.1.3 "><p id="p54633611154"><a name="p54633611154"></a><a name="p54633611154"></a>Obtains scheduling parameter attributes of a thread attribute object.</p>
</td>
</tr>
<tr id="row10601911214"><td class="cellrowborder" valign="top" headers="mcps1.2.5.1.1 "><p id="p5959165153018"><a name="p5959165153018"></a><a name="p5959165153018"></a>#include &lt;pthread.h&gt;</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.5.1.2 "><p id="p520117191415"><a name="p520117191415"></a><a name="p520117191415"></a>int pthread_attr_setschedparam(pthread_attr_t *attr, const struct sched_param *param);</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.5.1.3 "><p id="p1746636141515"><a name="p1746636141515"></a><a name="p1746636141515"></a>Sets scheduling parameter attributes for a thread attribute object.</p>
</td>
</tr>
<tr id="row4601414219"><td class="cellrowborder" valign="top" headers="mcps1.2.5.1.1 "><p id="p2040884313384"><a name="p2040884313384"></a><a name="p2040884313384"></a>#include &lt;pthread.h&gt;</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.5.1.2 "><p id="p18472155092016"><a name="p18472155092016"></a><a name="p18472155092016"></a>int pthread_getname_np(pthread_t pthread, char *name, size_t len);</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.5.1.3 "><p id="p1120131121416"><a name="p1120131121416"></a><a name="p1120131121416"></a>Obtains the name of a thread.</p>
</td>
</tr>
<tr id="row18601151112111"><td class="cellrowborder" valign="top" headers="mcps1.2.5.1.1 "><p id="p1020151131420"><a name="p1020151131420"></a><a name="p1020151131420"></a>#include &lt;pthread.h&gt;</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.5.1.2 "><p id="p947235062010"><a name="p947235062010"></a><a name="p947235062010"></a>int pthread_setname_np(pthread_t pthread, const char *name);</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.5.1.3 "><p id="p7201217144"><a name="p7201217144"></a><a name="p7201217144"></a>Set the thread name.</p>
</td>
</tr>
<tr id="row1960111113212"><td class="cellrowborder" valign="top" headers="mcps1.2.5.1.1 "><p id="p1997610185414"><a name="p1997610185414"></a><a name="p1997610185414"></a>#include &lt;pthread.h&gt;</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.5.1.2 "><p id="p18021017141517"><a name="p18021017141517"></a><a name="p18021017141517"></a>int pthread_cond_broadcast(pthread_cond_t *c);</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.5.1.3 "><p id="p1720111112148"><a name="p1720111112148"></a><a name="p1720111112148"></a>Unblocks the threads that are currently blocked on the condition variable.</p>
</td>
</tr>
<tr id="row11602121162114"><td class="cellrowborder" valign="top" headers="mcps1.2.5.1.1 "><p id="p122021518147"><a name="p122021518147"></a><a name="p122021518147"></a>#include &lt;pthread.h&gt;</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.5.1.2 "><p id="p1080291711510"><a name="p1080291711510"></a><a name="p1080291711510"></a>int pthread_cond_signal(pthread_cond_t *c);</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.5.1.3 "><p id="p22026131420"><a name="p22026131420"></a><a name="p22026131420"></a>Unblocks a thread.</p>
</td>
</tr>
<tr id="row86020111212"><td class="cellrowborder" valign="top" headers="mcps1.2.5.1.1 "><p id="p11202141121410"><a name="p11202141121410"></a><a name="p11202141121410"></a>#include &lt;pthread.h&gt;</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.5.1.2 "><p id="p2183310194219"><a name="p2183310194219"></a><a name="p2183310194219"></a>int pthread_cond_wait(pthread_cond_t *__restrict c, pthread_mutex_t *__restrict m);</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.5.1.3 "><p id="p15202412148"><a name="p15202412148"></a><a name="p15202412148"></a>Waits for the condition.</p>
</td>
</tr>
<tr id="row183901254784"><td class="cellrowborder" rowspan="17" valign="top" width="7.12%" headers="mcps1.2.5.1.1 "><p id="p8390105412815"><a name="p8390105412815"></a><a name="p8390105412815"></a>fs</p>
<p id="p16899101444012"><a name="p16899101444012"></a><a name="p16899101444012"></a></p>
</td>
<td class="cellrowborder" valign="top" width="17.150000000000002%" headers="mcps1.2.5.1.2 "><p id="p8807172824612"><a name="p8807172824612"></a><a name="p8807172824612"></a>#include &lt;libgen.h&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="52.27%" headers="mcps1.2.5.1.3 "><p id="p113904541182"><a name="p113904541182"></a><a name="p113904541182"></a>char *dirname(char *path);</p>
</td>
<td class="cellrowborder" valign="top" width="23.46%" headers="mcps1.2.5.1.4 "><p id="p183909541887"><a name="p183909541887"></a><a name="p183909541887"></a>Obtains the folder name.</p>
</td>
</tr>
<tr id="row55791630195011"><td class="cellrowborder" valign="top" headers="mcps1.2.5.1.1 "><p id="p18579330115010"><a name="p18579330115010"></a><a name="p18579330115010"></a>#include &lt;dirent.h&gt;</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.5.1.2 "><p id="p13579330195016"><a name="p13579330195016"></a><a name="p13579330195016"></a>struct dirent *readdir(DIR *dirp);</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.5.1.3 "><p id="p14579163095016"><a name="p14579163095016"></a><a name="p14579163095016"></a>Reads a directory.</p>
</td>
</tr>
<tr id="row10746104216507"><td class="cellrowborder" valign="top" headers="mcps1.2.5.1.1 "><p id="p1033312208571"><a name="p1033312208571"></a><a name="p1033312208571"></a>#include &lt;sys/stat.h&gt;</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.5.1.2 "><p id="p1674794285011"><a name="p1674794285011"></a><a name="p1674794285011"></a>int stat(const char *restrict path, struct stat *restrict buf);</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.5.1.3 "><p id="p07471542115011"><a name="p07471542115011"></a><a name="p07471542115011"></a>Obtains file information.</p>
</td>
</tr>
<tr id="row4747124210502"><td class="cellrowborder" valign="top" headers="mcps1.2.5.1.1 "><p id="p12386142918575"><a name="p12386142918575"></a><a name="p12386142918575"></a>#include &lt;unistd.h&gt;</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.5.1.2 "><p id="p6747142135017"><a name="p6747142135017"></a><a name="p6747142135017"></a>int unlink(const char *pathname);</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.5.1.3 "><p id="p5747174219504"><a name="p5747174219504"></a><a name="p5747174219504"></a>Deletes a file.</p>
</td>
</tr>
<tr id="row117941848155011"><td class="cellrowborder" valign="top" headers="mcps1.2.5.1.1 "><p id="p157951148105019"><a name="p157951148105019"></a><a name="p157951148105019"></a>#include &lt;fcntl.h</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.5.1.2 "><p id="p1086884114190"><a name="p1086884114190"></a><a name="p1086884114190"></a>int open(const char *path, int oflags, ...);</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.5.1.3 "><p id="p16795164855018"><a name="p16795164855018"></a><a name="p16795164855018"></a>Opens a file. If the file does not exist, create a file and open it.</p>
</td>
</tr>
<tr id="row2332345111914"><td class="cellrowborder" valign="top" headers="mcps1.2.5.1.1 "><p id="p6602174417217"><a name="p6602174417217"></a><a name="p6602174417217"></a>#include &lt;nistd.h&gt;</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.5.1.2 "><p id="p8499118131118"><a name="p8499118131118"></a><a name="p8499118131118"></a>int close(int fd);</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.5.1.3 "><p id="p1256220291104"><a name="p1256220291104"></a><a name="p1256220291104"></a>Closes a file.</p>
</td>
</tr>
<tr id="row106411620191012"><td class="cellrowborder" valign="top" headers="mcps1.2.5.1.1 "><p id="p147014220289"><a name="p147014220289"></a><a name="p147014220289"></a>#include &lt;stdio.h&gt;</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.5.1.2 "><p id="p711391141911"><a name="p711391141911"></a><a name="p711391141911"></a>int rename(const char *oldpath, const char *newpath);</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.5.1.3 "><p id="p1764122081011"><a name="p1764122081011"></a><a name="p1764122081011"></a>Rename the specified file.</p>
</td>
</tr>
<tr id="row164172013105"><td class="cellrowborder" valign="top" headers="mcps1.2.5.1.1 "><p id="p1763192712281"><a name="p1763192712281"></a><a name="p1763192712281"></a>#include &lt;dirent.h&gt;</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.5.1.2 "><p id="p6608143134518"><a name="p6608143134518"></a><a name="p6608143134518"></a>DIR  *opendir(const char *dirname);</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.5.1.3 "><p id="p964218202105"><a name="p964218202105"></a><a name="p964218202105"></a>Opens the specified directory.</p>
</td>
</tr>
<tr id="row1964282012105"><td class="cellrowborder" valign="top" headers="mcps1.2.5.1.1 "><p id="p53239286286"><a name="p53239286286"></a><a name="p53239286286"></a>#include &lt;dirent.h&gt;</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.5.1.2 "><p id="p15642820181014"><a name="p15642820181014"></a><a name="p15642820181014"></a>int closedir(DIR *dir);</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.5.1.3 "><p id="p166421201108"><a name="p166421201108"></a><a name="p166421201108"></a>Closes the specified directory.</p>
</td>
</tr>
<tr id="row9642202001013"><td class="cellrowborder" valign="top" headers="mcps1.2.5.1.1 "><p id="p1290215285287"><a name="p1290215285287"></a><a name="p1290215285287"></a>#include &lt;sys/mount.h&gt;</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.5.1.2 "><p id="p1035514388516"><a name="p1035514388516"></a><a name="p1035514388516"></a>int mount(const char *source, const char *target, const char *filesystemtype, unsigned long mountflags, const void *data);</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.5.1.3 "><p id="p1364242013103"><a name="p1364242013103"></a><a name="p1364242013103"></a>Mounts a file system.</p>
</td>
</tr>
<tr id="row364262011011"><td class="cellrowborder" valign="top" headers="mcps1.2.5.1.1 "><p id="p1184802912286"><a name="p1184802912286"></a><a name="p1184802912286"></a>#include &lt;sys/mount.h&gt;</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.5.1.2 "><p id="p1935603885120"><a name="p1935603885120"></a><a name="p1935603885120"></a>int umount(const char *target);</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.5.1.3 "><p id="p26421520191017"><a name="p26421520191017"></a><a name="p26421520191017"></a>Unmounts a file system.</p>
</td>
</tr>
<tr id="row1064252019101"><td class="cellrowborder" valign="top" headers="mcps1.2.5.1.1 "><p id="p12458131122813"><a name="p12458131122813"></a><a name="p12458131122813"></a>#include &lt;sys/mount.h&gt;</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.5.1.2 "><p id="p95296218264"><a name="p95296218264"></a><a name="p95296218264"></a>int umount2(const char *target, int flag);</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.5.1.3 "><p id="p19642420121015"><a name="p19642420121015"></a><a name="p19642420121015"></a>Unmounts a file system.</p>
</td>
</tr>
<tr id="row1450111232125"><td class="cellrowborder" valign="top" headers="mcps1.2.5.1.1 "><p id="p1098616311287"><a name="p1098616311287"></a><a name="p1098616311287"></a>#include &lt;sys/stat.h&gt;</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.5.1.2 "><p id="p2011771842220"><a name="p2011771842220"></a><a name="p2011771842220"></a>int fsync(int fd);</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.5.1.3 "><p id="p250115236125"><a name="p250115236125"></a><a name="p250115236125"></a>Synchronizes the files associated with a specified file descriptor to a storage device.</p>
</td>
</tr>
<tr id="row115013239123"><td class="cellrowborder" valign="top" headers="mcps1.2.5.1.1 "><p id="p3929143214288"><a name="p3929143214288"></a><a name="p3929143214288"></a>#include &lt;sys/stat.h&gt;</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.5.1.2 "><p id="p295910239426"><a name="p295910239426"></a><a name="p295910239426"></a>int mkdir(const char *pathname, mode_t mode);</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.5.1.3 "><p id="p19966195644317"><a name="p19966195644317"></a><a name="p19966195644317"></a>Creates a directory.</p>
</td>
</tr>
<tr id="row105021723101218"><td class="cellrowborder" valign="top" headers="mcps1.2.5.1.1 "><p id="p4792034112819"><a name="p4792034112819"></a><a name="p4792034112819"></a>#include &lt;unistd.h&gt;</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.5.1.2 "><p id="p1118181872214"><a name="p1118181872214"></a><a name="p1118181872214"></a>int rmdir(const char *path);</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.5.1.3 "><p id="p1350214237122"><a name="p1350214237122"></a><a name="p1350214237122"></a>Deletes a directory.</p>
</td>
</tr>
<tr id="row125023236120"><td class="cellrowborder" valign="top" headers="mcps1.2.5.1.1 "><p id="p15620934182817"><a name="p15620934182817"></a><a name="p15620934182817"></a>#include &lt;sys/stat.h&gt;</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.5.1.2 "><p id="p18958172310427"><a name="p18958172310427"></a><a name="p18958172310427"></a>int fstat(int fd, struct stat *buf);</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.5.1.3 "><p id="p550222319127"><a name="p550222319127"></a><a name="p550222319127"></a>Obtains file status information.</p>
</td>
</tr>
<tr id="row789821444016"><td class="cellrowborder" valign="top" headers="mcps1.2.5.1.1 "><p id="p10899514184010"><a name="p10899514184010"></a><a name="p10899514184010"></a>#include &lt;sys/statfs.h&gt;</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.5.1.2 "><p id="p82761152115811"><a name="p82761152115811"></a><a name="p82761152115811"></a>int statfs(const char *path, struct statfs *buf);</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.5.1.3 "><p id="p1489913149409"><a name="p1489913149409"></a><a name="p1489913149409"></a>Obtains the file system information of a file in the specified path.</p>
</td>
</tr>
<tr id="row17474428506"><td class="cellrowborder" rowspan="16" valign="top" width="7.12%" headers="mcps1.2.5.1.1 "><p id="p186578497613"><a name="p186578497613"></a><a name="p186578497613"></a>time</p>
</td>
<td class="cellrowborder" valign="top" width="17.150000000000002%" headers="mcps1.2.5.1.2 "><p id="p117487429505"><a name="p117487429505"></a><a name="p117487429505"></a>#include &lt;sys/time.h&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="52.27%" headers="mcps1.2.5.1.3 "><p id="p3748242125014"><a name="p3748242125014"></a><a name="p3748242125014"></a>int gettimeofday(struct timeval *tv, struct timezone *tz);</p>
</td>
<td class="cellrowborder" valign="top" width="23.46%" headers="mcps1.2.5.1.4 "><p id="p12748242195017"><a name="p12748242195017"></a><a name="p12748242195017"></a>Obtains the time. Time zone is not supported. The return value of <strong id="b854143112452"><a name="b854143112452"></a><a name="b854143112452"></a>tz</strong> is empty.</p>
</td>
</tr>
<tr id="row10748134275014"><td class="cellrowborder" valign="top" headers="mcps1.2.5.1.1 "><p id="p12748134215012"><a name="p12748134215012"></a><a name="p12748134215012"></a>#include &lt;time.h&gt;</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.5.1.2 "><p id="p1574812422505"><a name="p1574812422505"></a><a name="p1574812422505"></a>struct tm *gmtime(const time_t *timep);</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.5.1.3 "><p id="p67488425509"><a name="p67488425509"></a><a name="p67488425509"></a>Converts a date and time to broken-down time or ASCII.</p>
</td>
</tr>
<tr id="row1674894212507"><td class="cellrowborder" valign="top" headers="mcps1.2.5.1.1 "><p id="p1374974225010"><a name="p1374974225010"></a><a name="p1374974225010"></a>#include &lt;time.h&gt;</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.5.1.2 "><p id="p147499420501"><a name="p147499420501"></a><a name="p147499420501"></a>struct tm *localtime(const time_t *timep);</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.5.1.3 "><p id="p1574918423504"><a name="p1574918423504"></a><a name="p1574918423504"></a>Obtains the time.</p>
</td>
</tr>
<tr id="row574915422505"><td class="cellrowborder" valign="top" headers="mcps1.2.5.1.1 "><p id="p19749184214507"><a name="p19749184214507"></a><a name="p19749184214507"></a>#include &lt;time.h&gt;</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.5.1.2 "><p id="p474994245016"><a name="p474994245016"></a><a name="p474994245016"></a>struct tm *localtime_r(const time_t *timep, struct tm *result);</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.5.1.3 "><p id="p77492042135013"><a name="p77492042135013"></a><a name="p77492042135013"></a>Obtains the time.</p>
</td>
</tr>
<tr id="row488185917816"><td class="cellrowborder" valign="top" headers="mcps1.2.5.1.1 "><p id="p980716286465"><a name="p980716286465"></a><a name="p980716286465"></a>#include &lt;time.h&gt;</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.5.1.2 "><p id="p18825917816"><a name="p18825917816"></a><a name="p18825917816"></a>time_t mktime(struct tm *tm);</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.5.1.3 "><p id="p1988125916818"><a name="p1988125916818"></a><a name="p1988125916818"></a>Converts a date and time to broken-down time or ASCII.</p>
</td>
</tr>
<tr id="row1012515199719"><td class="cellrowborder" valign="top" headers="mcps1.2.5.1.1 "><p id="p912513191777"><a name="p912513191777"></a><a name="p912513191777"></a>#include &lt;time.h&gt;</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.5.1.2 "><p id="p8126219872"><a name="p8126219872"></a><a name="p8126219872"></a>size_t strftime(char *s, size_t max, const char *format,const struct tm *tm);</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.5.1.3 "><p id="p712617191776"><a name="p712617191776"></a><a name="p712617191776"></a>Formats the date and time string.</p>
</td>
</tr>
<tr id="row1712610196714"><td class="cellrowborder" valign="top" headers="mcps1.2.5.1.1 "><p id="p2126121910710"><a name="p2126121910710"></a><a name="p2126121910710"></a>#include &lt;time.h&gt;</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.5.1.2 "><p id="p13126419976"><a name="p13126419976"></a><a name="p13126419976"></a>time_t time(time_t *tloc);</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.5.1.3 "><p id="p21261919971"><a name="p21261919971"></a><a name="p21261919971"></a>Obtains the calendar time.</p>
</td>
</tr>
<tr id="row81261319577"><td class="cellrowborder" valign="top" headers="mcps1.2.5.1.1 "><p id="p1112610194718"><a name="p1112610194718"></a><a name="p1112610194718"></a>#include &lt;sys/times.h&gt;</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.5.1.2 "><p id="p171271919878"><a name="p171271919878"></a><a name="p171271919878"></a>clock_t times(struct tms *buf);</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.5.1.3 "><p id="p61272196713"><a name="p61272196713"></a><a name="p61272196713"></a>Obtains the thread time.</p>
</td>
</tr>
<tr id="row1512715191575"><td class="cellrowborder" valign="top" headers="mcps1.2.5.1.1 "><p id="p312714191673"><a name="p312714191673"></a><a name="p312714191673"></a>#include &lt;unistd.h&gt;</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.5.1.2 "><p id="p812751918716"><a name="p812751918716"></a><a name="p812751918716"></a>int usleep(useconds_t usec);</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.5.1.3 "><p id="p31271119773"><a name="p31271119773"></a><a name="p31271119773"></a>Goes to hibernation (in μs).</p>
</td>
</tr>
<tr id="row6399946121118"><td class="cellrowborder" valign="top" headers="mcps1.2.5.1.1 "><p id="p162424341317"><a name="p162424341317"></a><a name="p162424341317"></a>#include &lt;time.h&gt;</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.5.1.2 "><p id="p3262105015216"><a name="p3262105015216"></a><a name="p3262105015216"></a>int nanosleep(const struct timespec *tspec1, struct timespec *tspec2);</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.5.1.3 "><p id="p4399174611118"><a name="p4399174611118"></a><a name="p4399174611118"></a>Pauses the calling thread till the specified time.</p>
</td>
</tr>
<tr id="row4399114691119"><td class="cellrowborder" valign="top" headers="mcps1.2.5.1.1 "><p id="p9738125731717"><a name="p9738125731717"></a><a name="p9738125731717"></a>#include &lt;time.h&gt;</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.5.1.2 "><p id="p940024611116"><a name="p940024611116"></a><a name="p940024611116"></a>int clock_gettime(clockid_t id, struct timespec *tspec);</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.5.1.3 "><p id="p140054661114"><a name="p140054661114"></a><a name="p140054661114"></a>Obtains the clock time.</p>
</td>
</tr>
<tr id="row640044618115"><td class="cellrowborder" valign="top" headers="mcps1.2.5.1.1 "><p id="p1942222152413"><a name="p1942222152413"></a><a name="p1942222152413"></a>#include &lt;time.h&gt;</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.5.1.2 "><p id="p4262185092111"><a name="p4262185092111"></a><a name="p4262185092111"></a>int timer_create(clockid_t id, struct sigevent *__restrict evp, timer_t *__restrict t);</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.5.1.3 "><p id="p10400134620113"><a name="p10400134620113"></a><a name="p10400134620113"></a>Creates a timer for a thread.</p>
</td>
</tr>
<tr id="row19400184614116"><td class="cellrowborder" valign="top" headers="mcps1.2.5.1.1 "><p id="p94001446121110"><a name="p94001446121110"></a><a name="p94001446121110"></a>#include &lt;time.h&gt;</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.5.1.2 "><p id="p1626265012115"><a name="p1626265012115"></a><a name="p1626265012115"></a>int timer_delete(timer_t t);</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.5.1.3 "><p id="p840054610114"><a name="p840054610114"></a><a name="p840054610114"></a>Deletes a thread timer.</p>
</td>
</tr>
<tr id="row18400124618117"><td class="cellrowborder" valign="top" headers="mcps1.2.5.1.1 "><p id="p275111375343"><a name="p275111375343"></a><a name="p275111375343"></a>#include &lt;time.h&gt;</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.5.1.2 "><p id="p626315017218"><a name="p626315017218"></a><a name="p626315017218"></a>int timer_settime(timer_t t, int flags, const struct itimerspec *__restrict val, struct itimerspec *__restrict old);</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.5.1.3 "><p id="p17400184616110"><a name="p17400184616110"></a><a name="p17400184616110"></a>Sets a timer for a thread.</p>
</td>
</tr>
<tr id="row640094661119"><td class="cellrowborder" valign="top" headers="mcps1.2.5.1.1 "><p id="p4779162844815"><a name="p4779162844815"></a><a name="p4779162844815"></a>#include &lt;time.h&gt;</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.5.1.2 "><p id="p39151240396"><a name="p39151240396"></a><a name="p39151240396"></a>time_t time (time_t *t);</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.5.1.3 "><p id="p0400114651120"><a name="p0400114651120"></a><a name="p0400114651120"></a>Obtains the time.</p>
</td>
</tr>
<tr id="row1440064661116"><td class="cellrowborder" valign="top" headers="mcps1.2.5.1.1 "><p id="p1789411519255"><a name="p1789411519255"></a><a name="p1789411519255"></a>#include &lt;time.h&gt;</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.5.1.2 "><p id="p158947156251"><a name="p158947156251"></a><a name="p158947156251"></a>char *strptime(const char *s, const char *format, struct tm *tm);</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.5.1.3 "><p id="p1489561511256"><a name="p1489561511256"></a><a name="p1489561511256"></a>Converts the time string into the time tm structure.</p>
</td>
</tr>
<tr id="row5127111911713"><td class="cellrowborder" rowspan="36" valign="top" width="7.12%" headers="mcps1.2.5.1.1 "><p id="p0660049161215"><a name="p0660049161215"></a><a name="p0660049161215"></a>util</p>
</td>
<td class="cellrowborder" valign="top" width="17.150000000000002%" headers="mcps1.2.5.1.2 "><p id="p1212761918713"><a name="p1212761918713"></a><a name="p1212761918713"></a>#include &lt;stdlib.h&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="52.27%" headers="mcps1.2.5.1.3 "><p id="p141276191079"><a name="p141276191079"></a><a name="p141276191079"></a>int atoi(const char *nptr);</p>
</td>
<td class="cellrowborder" valign="top" width="23.46%" headers="mcps1.2.5.1.4 "><p id="p1312720191774"><a name="p1312720191774"></a><a name="p1312720191774"></a>Converts the character string into an integer (int).</p>
</td>
</tr>
<tr id="row1440314213511"><td class="cellrowborder" valign="top" headers="mcps1.2.5.1.1 "><p id="p1680772884613"><a name="p1680772884613"></a><a name="p1680772884613"></a>#include &lt;stdlib.h&gt;</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.5.1.2 "><p id="p740316421856"><a name="p740316421856"></a><a name="p740316421856"></a>long atol(const char *nptr);</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.5.1.3 "><p id="p17403642554"><a name="p17403642554"></a><a name="p17403642554"></a>Converts the character string into an integer (long).</p>
</td>
</tr>
<tr id="row1796575911219"><td class="cellrowborder" valign="top" headers="mcps1.2.5.1.1 "><p id="p39662597128"><a name="p39662597128"></a><a name="p39662597128"></a>#include &lt;stdlib.h&gt;</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.5.1.2 "><p id="p696665919120"><a name="p696665919120"></a><a name="p696665919120"></a>long long atoll(const char *nptr);</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.5.1.3 "><p id="p13966125916120"><a name="p13966125916120"></a><a name="p13966125916120"></a>Converts the character string into an integer (long long).</p>
</td>
</tr>
<tr id="row1096645981217"><td class="cellrowborder" valign="top" headers="mcps1.2.5.1.1 "><p id="p179664599122"><a name="p179664599122"></a><a name="p179664599122"></a>#include &lt;ctype.h&gt;</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.5.1.2 "><p id="p1896625914128"><a name="p1896625914128"></a><a name="p1896625914128"></a>int isalnum(int c);</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.5.1.3 "><p id="p1966145911128"><a name="p1966145911128"></a><a name="p1966145911128"></a>Checks for alphanumeric characters.</p>
</td>
</tr>
<tr id="row796619598123"><td class="cellrowborder" valign="top" headers="mcps1.2.5.1.1 "><p id="p15967759131219"><a name="p15967759131219"></a><a name="p15967759131219"></a>#include &lt;ctype.h&gt;</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.5.1.2 "><p id="p1896711591122"><a name="p1896711591122"></a><a name="p1896711591122"></a>int isascii(int c);</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.5.1.3 "><p id="p169671059121216"><a name="p169671059121216"></a><a name="p169671059121216"></a>Checks for ASCII.</p>
</td>
</tr>
<tr id="row39678596126"><td class="cellrowborder" valign="top" headers="mcps1.2.5.1.1 "><p id="p14967159111216"><a name="p14967159111216"></a><a name="p14967159111216"></a>#include &lt;ctype.h&gt;</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.5.1.2 "><p id="p109670592121"><a name="p109670592121"></a><a name="p109670592121"></a>int isdigit(int c);</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.5.1.3 "><p id="p296715911125"><a name="p296715911125"></a><a name="p296715911125"></a>Checks for numeric characters.</p>
</td>
</tr>
<tr id="row796795971214"><td class="cellrowborder" valign="top" headers="mcps1.2.5.1.1 "><p id="p1296855918123"><a name="p1296855918123"></a><a name="p1296855918123"></a>#include &lt;ctype.h&gt;</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.5.1.2 "><p id="p179681259151214"><a name="p179681259151214"></a><a name="p179681259151214"></a>int islower(int c);</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.5.1.3 "><p id="p4968175981219"><a name="p4968175981219"></a><a name="p4968175981219"></a>Checks for lowercase letters.</p>
</td>
</tr>
<tr id="row696814594124"><td class="cellrowborder" valign="top" headers="mcps1.2.5.1.1 "><p id="p149681359171212"><a name="p149681359171212"></a><a name="p149681359171212"></a>#include &lt;ctype.h&gt;</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.5.1.2 "><p id="p2968959101214"><a name="p2968959101214"></a><a name="p2968959101214"></a>int isprint(int c);</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.5.1.3 "><p id="p119681659101217"><a name="p119681659101217"></a><a name="p119681659101217"></a>Checks for printable characters, including spaces.</p>
</td>
</tr>
<tr id="row1138618341131"><td class="cellrowborder" valign="top" headers="mcps1.2.5.1.1 "><p id="p1138617346132"><a name="p1138617346132"></a><a name="p1138617346132"></a>#include &lt;ctype.h&gt;</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.5.1.2 "><p id="p43861634121314"><a name="p43861634121314"></a><a name="p43861634121314"></a>int isspace(int c);</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.5.1.3 "><p id="p15386634201320"><a name="p15386634201320"></a><a name="p15386634201320"></a>Checks for a space.</p>
</td>
</tr>
<tr id="row16388334161316"><td class="cellrowborder" valign="top" headers="mcps1.2.5.1.1 "><p id="p238811348133"><a name="p238811348133"></a><a name="p238811348133"></a>#include &lt;ctype.h&gt;</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.5.1.2 "><p id="p1738833451318"><a name="p1738833451318"></a><a name="p1738833451318"></a>int isupper(int c);</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.5.1.3 "><p id="p12388173491319"><a name="p12388173491319"></a><a name="p12388173491319"></a>Checks for uppercase letters.</p>
</td>
</tr>
<tr id="row8388133461313"><td class="cellrowborder" valign="top" headers="mcps1.2.5.1.1 "><p id="p103881534171315"><a name="p103881534171315"></a><a name="p103881534171315"></a>#include &lt;ctype.h&gt;</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.5.1.2 "><p id="p14388434191315"><a name="p14388434191315"></a><a name="p14388434191315"></a>int isxdigit(int c);</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.5.1.3 "><p id="p5388143416136"><a name="p5388143416136"></a><a name="p5388143416136"></a>Checks for hexadecimal digits.</p>
</td>
</tr>
<tr id="row1159217444524"><td class="cellrowborder" valign="top" headers="mcps1.2.5.1.1 "><p id="p1376152816136"><a name="p1376152816136"></a><a name="p1376152816136"></a>#include &lt;stdlib.h&gt;</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.5.1.2 "><p id="p6593344145212"><a name="p6593344145212"></a><a name="p6593344145212"></a>long int random (void);</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.5.1.3 "><p id="p5593194455219"><a name="p5593194455219"></a><a name="p5593194455219"></a>Generates a random number.</p>
</td>
</tr>
<tr id="row113881342131"><td class="cellrowborder" valign="top" headers="mcps1.2.5.1.1 "><p id="p1638913414132"><a name="p1638913414132"></a><a name="p1638913414132"></a>#include &lt;stdlib.h&gt;</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.5.1.2 "><p id="p63897344133"><a name="p63897344133"></a><a name="p63897344133"></a>void srandom(unsigned int seed);</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.5.1.3 "><p id="p73891234131318"><a name="p73891234131318"></a><a name="p73891234131318"></a>Initializes the random number generator.</p>
</td>
</tr>
<tr id="row238953451316"><td class="cellrowborder" valign="top" headers="mcps1.2.5.1.1 "><p id="p1638912344134"><a name="p1638912344134"></a><a name="p1638912344134"></a>#include &lt;ctype.h&gt;</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.5.1.2 "><p id="p938993416137"><a name="p938993416137"></a><a name="p938993416137"></a>int tolower(int c);</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.5.1.3 "><p id="p7389193451315"><a name="p7389193451315"></a><a name="p7389193451315"></a>Converts letters to lowercase letters.</p>
</td>
</tr>
<tr id="row1438933418133"><td class="cellrowborder" valign="top" headers="mcps1.2.5.1.1 "><p id="p3389143421316"><a name="p3389143421316"></a><a name="p3389143421316"></a>#include &lt;ctype.h&gt;</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.5.1.2 "><p id="p5389153413136"><a name="p5389153413136"></a><a name="p5389153413136"></a>int toupper(int c);</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.5.1.3 "><p id="p153891834181319"><a name="p153891834181319"></a><a name="p153891834181319"></a>Converts letters to uppercase letters.</p>
</td>
</tr>
<tr id="row186174504141"><td class="cellrowborder" valign="top" headers="mcps1.2.5.1.1 "><p id="p76184503142"><a name="p76184503142"></a><a name="p76184503142"></a>#include &lt;stdarg.h&gt;</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.5.1.2 "><p id="p106181150201414"><a name="p106181150201414"></a><a name="p106181150201414"></a>type va_arg(va_list ap, type);</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.5.1.3 "><p id="p12618135051410"><a name="p12618135051410"></a><a name="p12618135051410"></a>Obtains the current parameter of a variable parameter, returns the value of the specified type, and moves the pointer to the next parameter.</p>
</td>
</tr>
<tr id="row1061875016140"><td class="cellrowborder" valign="top" headers="mcps1.2.5.1.1 "><p id="p76181150131419"><a name="p76181150131419"></a><a name="p76181150131419"></a>#include &lt;stdarg.h&gt;</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.5.1.2 "><p id="p12618205012148"><a name="p12618205012148"></a><a name="p12618205012148"></a>void va_copy(va_list dest, va_list src);</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.5.1.3 "><p id="p1061815506146"><a name="p1061815506146"></a><a name="p1061815506146"></a>Copies parameters.</p>
</td>
</tr>
<tr id="row176188501144"><td class="cellrowborder" valign="top" headers="mcps1.2.5.1.1 "><p id="p116191950171420"><a name="p116191950171420"></a><a name="p116191950171420"></a>#include &lt;stdarg.h&gt;</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.5.1.2 "><p id="p4619165021416"><a name="p4619165021416"></a><a name="p4619165021416"></a>void va_end(va_list ap);</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.5.1.3 "><p id="p166199506148"><a name="p166199506148"></a><a name="p166199506148"></a>Clears the <strong id="b105664325815"><a name="b105664325815"></a><a name="b105664325815"></a>va_list</strong> variable parameter list.</p>
</td>
</tr>
<tr id="row12671173316302"><td class="cellrowborder" valign="top" headers="mcps1.2.5.1.1 "><p id="p75546311273"><a name="p75546311273"></a><a name="p75546311273"></a>#include &lt;stdarg.h&gt;</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.5.1.2 "><p id="p16254211285"><a name="p16254211285"></a><a name="p16254211285"></a>void va_start(va_list ap, last);</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.5.1.3 "><p id="p19499185722618"><a name="p19499185722618"></a><a name="p19499185722618"></a>Defines the start position of the variable-length parameter list.</p>
</td>
</tr>
<tr id="row4280347300"><td class="cellrowborder" valign="top" headers="mcps1.2.5.1.1 "><p id="p10737184522311"><a name="p10737184522311"></a><a name="p10737184522311"></a>#include &lt;string.h&gt;</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.5.1.2 "><p id="p17737164582311"><a name="p17737164582311"></a><a name="p17737164582311"></a>char *strchr(const char *s, int c);</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.5.1.3 "><p id="p6737945162312"><a name="p6737945162312"></a><a name="p6737945162312"></a>Locates the last occurrence of a character in a string.</p>
</td>
</tr>
<tr id="row1849925772616"><td class="cellrowborder" valign="top" headers="mcps1.2.5.1.1 "><p id="p11738124532311"><a name="p11738124532311"></a><a name="p11738124532311"></a>#include &lt;string.h&gt;</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.5.1.2 "><p id="p273814511233"><a name="p273814511233"></a><a name="p273814511233"></a>int strcmp(const char *s1, const char *s2);</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.5.1.3 "><p id="p173814516232"><a name="p173814516232"></a><a name="p173814516232"></a>Compares strings.</p>
</td>
</tr>
<tr id="row1961831317314"><td class="cellrowborder" valign="top" headers="mcps1.2.5.1.1 "><p id="p573884522316"><a name="p573884522316"></a><a name="p573884522316"></a>#include &lt;string.h&gt;</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.5.1.2 "><p id="p18738645152312"><a name="p18738645152312"></a><a name="p18738645152312"></a>size_t strcspn(const char *s, const char *reject);</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.5.1.3 "><p id="p8738445122318"><a name="p8738445122318"></a><a name="p8738445122318"></a>Obtains the length of the initial segment of a string.</p>
</td>
</tr>
<tr id="row654381720312"><td class="cellrowborder" valign="top" headers="mcps1.2.5.1.1 "><p id="p1283311491214"><a name="p1283311491214"></a><a name="p1283311491214"></a>#include &lt;string.h&gt;</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.5.1.2 "><p id="p2833249132115"><a name="p2833249132115"></a><a name="p2833249132115"></a>char *strdup(const char *s);</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.5.1.3 "><p id="p1083374916219"><a name="p1083374916219"></a><a name="p1083374916219"></a>Copies a string to a new position.</p>
</td>
</tr>
<tr id="row416111248319"><td class="cellrowborder" valign="top" headers="mcps1.2.5.1.1 "><p id="p10880134072114"><a name="p10880134072114"></a><a name="p10880134072114"></a>#include &lt;string.h&gt;</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.5.1.2 "><p id="p1588117403219"><a name="p1588117403219"></a><a name="p1588117403219"></a>size_t strlen(const char *s);</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.5.1.3 "><p id="p118815408213"><a name="p118815408213"></a><a name="p118815408213"></a>Calculates the length of a string.</p>
</td>
</tr>
<tr id="row916122453117"><td class="cellrowborder" valign="top" headers="mcps1.2.5.1.1 "><p id="p1189451515252"><a name="p1189451515252"></a><a name="p1189451515252"></a>#include &lt;strings.h&gt;</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.5.1.2 "><p id="p1389481518258"><a name="p1389481518258"></a><a name="p1389481518258"></a>int strncasecmp(const char *s1, const char *s2, size_t n);</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.5.1.3 "><p id="p58942157251"><a name="p58942157251"></a><a name="p58942157251"></a>Compares fixed-length strings (case-insensitive).</p>
</td>
</tr>
<tr id="row74292820312"><td class="cellrowborder" valign="top" headers="mcps1.2.5.1.1 "><p id="p17737945162315"><a name="p17737945162315"></a><a name="p17737945162315"></a>#include &lt;strings.h&gt;</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.5.1.2 "><p id="p107371459236"><a name="p107371459236"></a><a name="p107371459236"></a>int strcasecmp(const char *s1, const char *s2);</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.5.1.3 "><p id="p0737245142318"><a name="p0737245142318"></a><a name="p0737245142318"></a>Compares strings (case-insensitive).</p>
</td>
</tr>
<tr id="row44320288315"><td class="cellrowborder" valign="top" headers="mcps1.2.5.1.1 "><p id="p2894115152515"><a name="p2894115152515"></a><a name="p2894115152515"></a>#include &lt;string.h&gt;</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.5.1.2 "><p id="p3894315202511"><a name="p3894315202511"></a><a name="p3894315202511"></a>int strncmp(const char *s1, const char *s2, size_t n);</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.5.1.3 "><p id="p198942152256"><a name="p198942152256"></a><a name="p198942152256"></a>Compares strings of the specified length.</p>
</td>
</tr>
<tr id="row12438281317"><td class="cellrowborder" valign="top" headers="mcps1.2.5.1.1 "><p id="p58954152256"><a name="p58954152256"></a><a name="p58954152256"></a>#include &lt;string.h&gt;</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.5.1.2 "><p id="p489501515252"><a name="p489501515252"></a><a name="p489501515252"></a>char *strrchr(const char *s, int c);</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.5.1.3 "><p id="p08951815202511"><a name="p08951815202511"></a><a name="p08951815202511"></a>Locates the last occurrence of a character in a string.</p>
</td>
</tr>
<tr id="row84316284312"><td class="cellrowborder" valign="top" headers="mcps1.2.5.1.1 "><p id="p198841242203010"><a name="p198841242203010"></a><a name="p198841242203010"></a>#include &lt;string.h&gt;</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.5.1.2 "><p id="p4895171542519"><a name="p4895171542519"></a><a name="p4895171542519"></a>char *strstr(const char *haystack, const char *needle);</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.5.1.3 "><p id="p889519152258"><a name="p889519152258"></a><a name="p889519152258"></a>Searches for the specified string <strong id="b991414021816"><a name="b991414021816"></a><a name="b991414021816"></a>needle</strong>.</p>
</td>
</tr>
<tr id="row137113339318"><td class="cellrowborder" valign="top" headers="mcps1.2.5.1.1 "><p id="p7893129102510"><a name="p7893129102510"></a><a name="p7893129102510"></a>#include &lt;stdlib.h&gt;</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.5.1.2 "><p id="p1789315290252"><a name="p1789315290252"></a><a name="p1789315290252"></a>long int strtol(const char *nptr, char **endptr, int base);</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.5.1.3 "><p id="p1289342992512"><a name="p1289342992512"></a><a name="p1289342992512"></a>Converts a string into a long int value.</p>
</td>
</tr>
<tr id="row571133193118"><td class="cellrowborder" valign="top" headers="mcps1.2.5.1.1 "><p id="p19894122922511"><a name="p19894122922511"></a><a name="p19894122922511"></a>#include &lt;stdlib.h&gt;</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.5.1.2 "><p id="p689412912255"><a name="p689412912255"></a><a name="p689412912255"></a>unsigned long int strtoul(const char *nptr, char **endptr, int base);</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.5.1.3 "><p id="p289417291258"><a name="p289417291258"></a><a name="p289417291258"></a>Converts a string into an unsigned long int value.</p>
</td>
</tr>
<tr id="row0719336316"><td class="cellrowborder" valign="top" headers="mcps1.2.5.1.1 "><p id="p14894129122512"><a name="p14894129122512"></a><a name="p14894129122512"></a>#include &lt;stdlib.h&gt;</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.5.1.2 "><p id="p9894829122511"><a name="p9894829122511"></a><a name="p9894829122511"></a>unsigned long long int strtoull(const char *nptr, char **endptr,int base);</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.5.1.3 "><p id="p14894102918252"><a name="p14894102918252"></a><a name="p14894102918252"></a>Converts a string into an unsigned long long int value.</p>
</td>
</tr>
<tr id="row371113310315"><td class="cellrowborder" valign="top" headers="mcps1.2.5.1.1 "><p id="p8981194319341"><a name="p8981194319341"></a><a name="p8981194319341"></a>#include &lt;regex.h&gt;</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.5.1.2 "><p id="p19981124318343"><a name="p19981124318343"></a><a name="p19981124318343"></a>int regcomp(regex_t *preg, const char *regex, int cflags);</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.5.1.3 "><p id="p8981124317348"><a name="p8981124317348"></a><a name="p8981124317348"></a>Compiles a regular expression.</p>
</td>
</tr>
<tr id="row2072103316315"><td class="cellrowborder" valign="top" headers="mcps1.2.5.1.1 "><p id="p119816435341"><a name="p119816435341"></a><a name="p119816435341"></a>#include &lt;regex.h&gt;</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.5.1.2 "><p id="p39812043123415"><a name="p39812043123415"></a><a name="p39812043123415"></a>int regexec(const regex_t *preg, const char *string, size_t nmatch,regmatch_t pmatch[], int eflags);</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.5.1.3 "><p id="p998144310346"><a name="p998144310346"></a><a name="p998144310346"></a>Matches a regular expression.</p>
</td>
</tr>
<tr id="row7727336317"><td class="cellrowborder" valign="top" headers="mcps1.2.5.1.1 "><p id="p193183620342"><a name="p193183620342"></a><a name="p193183620342"></a>#include &lt;regex.h&gt;</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.5.1.2 "><p id="p493116361345"><a name="p493116361345"></a><a name="p493116361345"></a>void regfree(regex_t *preg);</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.5.1.3 "><p id="p39311736183416"><a name="p39311736183416"></a><a name="p39311736183416"></a>Releases a regular expression.</p>
</td>
</tr>
<tr id="row16726334311"><td class="cellrowborder" valign="top" headers="mcps1.2.5.1.1 "><p id="p3932636103411"><a name="p3932636103411"></a><a name="p3932636103411"></a>#include &lt;string.h&gt;</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.5.1.2 "><p id="p11932136113411"><a name="p11932136113411"></a><a name="p11932136113411"></a>char *strerror(int errnum);</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.5.1.3 "><p id="p09325369349"><a name="p09325369349"></a><a name="p09325369349"></a>Returns an error description string of the specified error code.</p>
</td>
</tr>
<tr id="row1161905081418"><td class="cellrowborder" rowspan="5" valign="top" width="7.12%" headers="mcps1.2.5.1.1 "><p id="p4607855121515"><a name="p4607855121515"></a><a name="p4607855121515"></a>math</p>
</td>
<td class="cellrowborder" valign="top" width="17.150000000000002%" headers="mcps1.2.5.1.2 "><p id="p4619145014145"><a name="p4619145014145"></a><a name="p4619145014145"></a>#include &lt;stdlib.h&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="52.27%" headers="mcps1.2.5.1.3 "><p id="p1661915504141"><a name="p1661915504141"></a><a name="p1661915504141"></a>int abs(int i);</p>
</td>
<td class="cellrowborder" valign="top" width="23.46%" headers="mcps1.2.5.1.4 "><p id="p1361918505143"><a name="p1361918505143"></a><a name="p1361918505143"></a>Returns the absolute value.</p>
</td>
</tr>
<tr id="row1161975014142"><td class="cellrowborder" valign="top" headers="mcps1.2.5.1.1 "><p id="p1461915091414"><a name="p1461915091414"></a><a name="p1461915091414"></a>#include &lt;math.h&gt;</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.5.1.2 "><p id="p8620145013147"><a name="p8620145013147"></a><a name="p8620145013147"></a>double log(double x);</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.5.1.3 "><p id="p962010508149"><a name="p962010508149"></a><a name="p962010508149"></a>Returns the natural logarithm (base-e logarithm) of <em id="i789692410344"><a name="i789692410344"></a><a name="i789692410344"></a>x</em>.</p>
</td>
</tr>
<tr id="row3620450191417"><td class="cellrowborder" valign="top" headers="mcps1.2.5.1.1 "><p id="p17620165041418"><a name="p17620165041418"></a><a name="p17620165041418"></a>#include &lt;math.h&gt;</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.5.1.2 "><p id="p862035031414"><a name="p862035031414"></a><a name="p862035031414"></a>double pow(double x, double y);</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.5.1.3 "><p id="p166201750181419"><a name="p166201750181419"></a><a name="p166201750181419"></a>Returns <em id="i859117159342"><a name="i859117159342"></a><a name="i859117159342"></a>x</em> raised to the power of <em id="i8551201915349"><a name="i8551201915349"></a><a name="i8551201915349"></a>y</em>.</p>
</td>
</tr>
<tr id="row25081750751"><td class="cellrowborder" valign="top" headers="mcps1.2.5.1.1 "><p id="p380714285468"><a name="p380714285468"></a><a name="p380714285468"></a>#include &lt;math.h&gt;</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.5.1.2 "><p id="p1250835017514"><a name="p1250835017514"></a><a name="p1250835017514"></a>double round(double x);</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.5.1.3 "><p id="p105085501757"><a name="p105085501757"></a><a name="p105085501757"></a>Rounds off the value from zero to the nearest integer.</p>
</td>
</tr>
<tr id="row6275144481911"><td class="cellrowborder" valign="top" headers="mcps1.2.5.1.1 "><p id="p527624471914"><a name="p527624471914"></a><a name="p527624471914"></a>#include &lt;math.h&gt;</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.5.1.2 "><p id="p1927634416197"><a name="p1927634416197"></a><a name="p1927634416197"></a>double sqrt(double x);</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.5.1.3 "><p id="p1327664471912"><a name="p1327664471912"></a><a name="p1327664471912"></a>Returns the square root of <em id="i720017623418"><a name="i720017623418"></a><a name="i720017623418"></a>x</em>.</p>
</td>
</tr>
<tr id="row172761344151920"><td class="cellrowborder" rowspan="17" valign="top" width="7.12%" headers="mcps1.2.5.1.1 "><p id="p72551033216"><a name="p72551033216"></a><a name="p72551033216"></a>IO</p>
</td>
<td class="cellrowborder" valign="top" width="17.150000000000002%" headers="mcps1.2.5.1.2 "><p id="p0276194451910"><a name="p0276194451910"></a><a name="p0276194451910"></a>#include &lt;stdio.h&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="52.27%" headers="mcps1.2.5.1.3 "><p id="p7276144413194"><a name="p7276144413194"></a><a name="p7276144413194"></a>void clearerr(FILE *stream);</p>
</td>
<td class="cellrowborder" valign="top" width="23.46%" headers="mcps1.2.5.1.4 "><p id="p227616447197"><a name="p227616447197"></a><a name="p227616447197"></a>Clears the file end and error indication of a stream.</p>
</td>
</tr>
<tr id="row142765444190"><td class="cellrowborder" valign="top" headers="mcps1.2.5.1.1 "><p id="p82771344101917"><a name="p82771344101917"></a><a name="p82771344101917"></a>#include &lt;stdio.h&gt;</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.5.1.2 "><p id="p1277174481914"><a name="p1277174481914"></a><a name="p1277174481914"></a>int fclose(FILE *stream);</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.5.1.3 "><p id="p1227774421919"><a name="p1227774421919"></a><a name="p1227774421919"></a>Closes a file stream.</p>
</td>
</tr>
<tr id="row1727714417196"><td class="cellrowborder" valign="top" headers="mcps1.2.5.1.1 "><p id="p027744419198"><a name="p027744419198"></a><a name="p027744419198"></a>#include &lt;stdio.h&gt;</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.5.1.2 "><p id="p112777446192"><a name="p112777446192"></a><a name="p112777446192"></a>FILE *fdopen(int fd, const char *mode);</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.5.1.3 "><p id="p132771344121915"><a name="p132771344121915"></a><a name="p132771344121915"></a>Opens a file stream by using a file descriptor.</p>
</td>
</tr>
<tr id="row1927704410197"><td class="cellrowborder" valign="top" headers="mcps1.2.5.1.1 "><p id="p15278134410196"><a name="p15278134410196"></a><a name="p15278134410196"></a>#include &lt;stdio.h&gt;</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.5.1.2 "><p id="p8278154419194"><a name="p8278154419194"></a><a name="p8278154419194"></a>int feof(FILE *stream);</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.5.1.3 "><p id="p17278194419196"><a name="p17278194419196"></a><a name="p17278194419196"></a>Tests the end-of-file indicator for the specified stream.</p>
</td>
</tr>
<tr id="row12834571052"><td class="cellrowborder" valign="top" headers="mcps1.2.5.1.1 "><p id="p17807122804615"><a name="p17807122804615"></a><a name="p17807122804615"></a>#include &lt;stdio.h&gt;</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.5.1.2 "><p id="p152840571519"><a name="p152840571519"></a><a name="p152840571519"></a>int fflush(FILE *stream);</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.5.1.3 "><p id="p128410571653"><a name="p128410571653"></a><a name="p128410571653"></a>Refreshes a stream.</p>
</td>
</tr>
<tr id="row1387924011217"><td class="cellrowborder" valign="top" headers="mcps1.2.5.1.1 "><p id="p158801940102117"><a name="p158801940102117"></a><a name="p158801940102117"></a>#include &lt;stdio.h&gt;</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.5.1.2 "><p id="p1588084092118"><a name="p1588084092118"></a><a name="p1588084092118"></a>char *fgets(char *s, int size, FILE *stream);</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.5.1.3 "><p id="p18801940102114"><a name="p18801940102114"></a><a name="p18801940102114"></a>Reads the next line of the stream.</p>
</td>
</tr>
<tr id="row13880124002120"><td class="cellrowborder" valign="top" headers="mcps1.2.5.1.1 "><p id="p1880174019211"><a name="p1880174019211"></a><a name="p1880174019211"></a>#include &lt;stdio.h&gt;</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.5.1.2 "><p id="p188020405214"><a name="p188020405214"></a><a name="p188020405214"></a>int fileno(FILE *stream);</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.5.1.3 "><p id="p10880140102118"><a name="p10880140102118"></a><a name="p10880140102118"></a>Returns the file descriptor of a stream.</p>
</td>
</tr>
<tr id="row158312497213"><td class="cellrowborder" valign="top" headers="mcps1.2.5.1.1 "><p id="p883114915212"><a name="p883114915212"></a><a name="p883114915212"></a>#include &lt;stdio.h&gt;</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.5.1.2 "><p id="p98310498214"><a name="p98310498214"></a><a name="p98310498214"></a>FILE *fopen(const char *path, const char *mode);</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.5.1.3 "><p id="p883174917217"><a name="p883174917217"></a><a name="p883174917217"></a>Open a stream.</p>
</td>
</tr>
<tr id="row128311449152119"><td class="cellrowborder" valign="top" headers="mcps1.2.5.1.1 "><p id="p208321449152111"><a name="p208321449152111"></a><a name="p208321449152111"></a>#include &lt;stdio.h&gt;</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.5.1.2 "><p id="p11832184902115"><a name="p11832184902115"></a><a name="p11832184902115"></a>int fputs(const char *s, FILE *stream);</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.5.1.3 "><p id="p783244917218"><a name="p783244917218"></a><a name="p783244917218"></a>Writes a line to a specified stream.</p>
</td>
</tr>
<tr id="row108321649152116"><td class="cellrowborder" valign="top" headers="mcps1.2.5.1.1 "><p id="p168322499216"><a name="p168322499216"></a><a name="p168322499216"></a>#include &lt;stdio.h&gt;</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.5.1.2 "><p id="p13832194915210"><a name="p13832194915210"></a><a name="p13832194915210"></a>size_t fread(void *ptr, size_t size, size_t nmemb, FILE *stream);</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.5.1.3 "><p id="p1083216496219"><a name="p1083216496219"></a><a name="p1083216496219"></a>Reads a stream.</p>
</td>
</tr>
<tr id="row178321249142110"><td class="cellrowborder" valign="top" headers="mcps1.2.5.1.1 "><p id="p13832104942110"><a name="p13832104942110"></a><a name="p13832104942110"></a>#include &lt;stdio.h&gt;</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.5.1.2 "><p id="p178338496215"><a name="p178338496215"></a><a name="p178338496215"></a>int fseek(FILE *stream, long offset, int whence);</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.5.1.3 "><p id="p2833174919213"><a name="p2833174919213"></a><a name="p2833174919213"></a>Sets the position of a stream pointer.</p>
</td>
</tr>
<tr id="row158332049132114"><td class="cellrowborder" valign="top" headers="mcps1.2.5.1.1 "><p id="p1983324972113"><a name="p1983324972113"></a><a name="p1983324972113"></a>#include &lt;stdio.h&gt;</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.5.1.2 "><p id="p188331049112115"><a name="p188331049112115"></a><a name="p188331049112115"></a>long ftell(FILE *stream);</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.5.1.3 "><p id="p1683384912115"><a name="p1683384912115"></a><a name="p1683384912115"></a>Obtains the position of a stream pointer.</p>
</td>
</tr>
<tr id="row2073644522317"><td class="cellrowborder" valign="top" headers="mcps1.2.5.1.1 "><p id="p4736194582316"><a name="p4736194582316"></a><a name="p4736194582316"></a>#include &lt;stdio.h&gt;</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.5.1.2 "><p id="p373674542312"><a name="p373674542312"></a><a name="p373674542312"></a>size_t fwrite(const void *ptr, size_t size, size_t nmemb,FILE *stream);</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.5.1.3 "><p id="p1073616453235"><a name="p1073616453235"></a><a name="p1073616453235"></a>Writes data to a stream.</p>
</td>
</tr>
<tr id="row07364457231"><td class="cellrowborder" valign="top" headers="mcps1.2.5.1.1 "><p id="p8736164572317"><a name="p8736164572317"></a><a name="p8736164572317"></a>#include &lt;stdio.h&gt;</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.5.1.2 "><p id="p37361445142318"><a name="p37361445142318"></a><a name="p37361445142318"></a>void perror(const char *s);</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.5.1.3 "><p id="p10737174515235"><a name="p10737174515235"></a><a name="p10737174515235"></a>Prints system error information.</p>
</td>
</tr>
<tr id="row87371345152315"><td class="cellrowborder" valign="top" headers="mcps1.2.5.1.1 "><p id="p7737124520231"><a name="p7737124520231"></a><a name="p7737124520231"></a>#include &lt;stdio.h&gt;</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.5.1.2 "><p id="p12737124510237"><a name="p12737124510237"></a><a name="p12737124510237"></a>void rewind(FILE *stream);</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.5.1.3 "><p id="p87379453239"><a name="p87379453239"></a><a name="p87379453239"></a>Re-positions a stream.</p>
</td>
</tr>
<tr id="row37372045122317"><td class="cellrowborder" valign="top" headers="mcps1.2.5.1.1 "><p id="p15621929303"><a name="p15621929303"></a><a name="p15621929303"></a>#include &lt;unistd.h&gt;</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.5.1.2 "><p id="p3117118112213"><a name="p3117118112213"></a><a name="p3117118112213"></a>ssize_t write(int fd, const void *buf, size_t size);</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.5.1.3 "><p id="p125627296017"><a name="p125627296017"></a><a name="p125627296017"></a>Writes data to a file.</p>
</td>
</tr>
<tr id="row27383457236"><td class="cellrowborder" valign="top" headers="mcps1.2.5.1.1 "><p id="p171389471520"><a name="p171389471520"></a><a name="p171389471520"></a>#include &lt;unistd.h&gt;</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.5.1.2 "><p id="p35631229609"><a name="p35631229609"></a><a name="p35631229609"></a>ssize_t read(int fd, void *buf, size_t size);</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.5.1.3 "><p id="p35631629504"><a name="p35631629504"></a><a name="p35631629504"></a>Reads data from a file.</p>
</td>
</tr>
<tr id="row98941429132516"><td class="cellrowborder" rowspan="14" valign="top" width="7.12%" headers="mcps1.2.5.1.1 "><p id="p6450611666"><a name="p6450611666"></a><a name="p6450611666"></a>net</p>
</td>
<td class="cellrowborder" valign="top" width="17.150000000000002%" headers="mcps1.2.5.1.2 "><p id="p0895142913259"><a name="p0895142913259"></a><a name="p0895142913259"></a>#include &lt;sys/socket.h&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="52.27%" headers="mcps1.2.5.1.3 "><p id="p88953296252"><a name="p88953296252"></a><a name="p88953296252"></a>void freeaddrinfo(struct addrinfo *res);</p>
</td>
<td class="cellrowborder" valign="top" width="23.46%" headers="mcps1.2.5.1.4 "><p id="p10895129162510"><a name="p10895129162510"></a><a name="p10895129162510"></a>Releases the dynamic memory allocated by calling <strong id="b1419118317499"><a name="b1419118317499"></a><a name="b1419118317499"></a>getaddrinfo</strong>.</p>
</td>
</tr>
<tr id="row11217457334"><td class="cellrowborder" valign="top" headers="mcps1.2.5.1.1 "><p id="p1721715563319"><a name="p1721715563319"></a><a name="p1721715563319"></a>#include &lt;sys/socket.h&gt;</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.5.1.2 "><p id="p821875153315"><a name="p821875153315"></a><a name="p821875153315"></a>int getaddrinfo(const char *restrict nodename,const char *restrict servname,const struct addrinfo *restrict hints,struct addrinfo **restrict res);</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.5.1.3 "><p id="p152188583318"><a name="p152188583318"></a><a name="p152188583318"></a>Performs network address translation.</p>
</td>
</tr>
<tr id="row82182052338"><td class="cellrowborder" valign="top" headers="mcps1.2.5.1.1 "><p id="p6218453336"><a name="p6218453336"></a><a name="p6218453336"></a>#include &lt;sys/socket.h&gt;</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.5.1.2 "><p id="p221835173315"><a name="p221835173315"></a><a name="p221835173315"></a>int getnameinfo(const struct sockaddr *restrict sa, socklen_t salen,char *restrict node, socklen_t nodelen, char *restrict service,socklen_t servicelen, int flags);</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.5.1.3 "><p id="p1218205163319"><a name="p1218205163319"></a><a name="p1218205163319"></a>Performs address-to-name translation in a protocol-independent manner.</p>
</td>
</tr>
<tr id="row14218155123313"><td class="cellrowborder" valign="top" headers="mcps1.2.5.1.1 "><p id="p162181151337"><a name="p162181151337"></a><a name="p162181151337"></a>#include &lt;net/if.h&gt;</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.5.1.2 "><p id="p1921815123316"><a name="p1921815123316"></a><a name="p1921815123316"></a>unsigned int if_nametoindex(const char *ifname);</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.5.1.3 "><p id="p19219115193319"><a name="p19219115193319"></a><a name="p19219115193319"></a>Obtains the index based on the network interface name.</p>
</td>
</tr>
<tr id="row62191151336"><td class="cellrowborder" valign="top" headers="mcps1.2.5.1.1 "><p id="p498318714818"><a name="p498318714818"></a><a name="p498318714818"></a>#include &lt;arpa/inet.h&gt;</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.5.1.2 "><p id="p14219955333"><a name="p14219955333"></a><a name="p14219955333"></a>in_addr_t inet_addr(const char *cp);</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.5.1.3 "><p id="p42195512335"><a name="p42195512335"></a><a name="p42195512335"></a>Converts the network host address from dotted decimal notation to binary format.</p>
</td>
</tr>
<tr id="row9219452334"><td class="cellrowborder" valign="top" headers="mcps1.2.5.1.1 "><p id="p2219250338"><a name="p2219250338"></a><a name="p2219250338"></a>#include &lt;arpa/inet.h&gt;</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.5.1.2 "><p id="p82199563315"><a name="p82199563315"></a><a name="p82199563315"></a>char *inet_ntoa(struct in_addr in);</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.5.1.3 "><p id="p521911553320"><a name="p521911553320"></a><a name="p521911553320"></a>Converts the network host address from binary format to dotted decimal notation.</p>
</td>
</tr>
<tr id="row5219185123313"><td class="cellrowborder" valign="top" headers="mcps1.2.5.1.1 "><p id="p19220852335"><a name="p19220852335"></a><a name="p19220852335"></a>#include &lt;arpa/inet.h&gt;</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.5.1.2 "><p id="p13220165183310"><a name="p13220165183310"></a><a name="p13220165183310"></a>const char *inet_ntop(int af, const void *src,char *dst, socklen_t size);</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.5.1.3 "><p id="p132207512333"><a name="p132207512333"></a><a name="p132207512333"></a>Performs network address translation.</p>
</td>
</tr>
<tr id="row1789532915255"><td class="cellrowborder" valign="top" headers="mcps1.2.5.1.1 "><p id="p2895122920252"><a name="p2895122920252"></a><a name="p2895122920252"></a>#include &lt;arpa/inet.h&gt;</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.5.1.2 "><p id="p1489518294250"><a name="p1489518294250"></a><a name="p1489518294250"></a>int inet_pton(int af, const char *src, void *dst);</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.5.1.3 "><p id="p589562913259"><a name="p589562913259"></a><a name="p589562913259"></a>Performs network address translation.</p>
</td>
</tr>
<tr id="row98812405212"><td class="cellrowborder" valign="top" headers="mcps1.2.5.1.1 "><p id="p18811340142116"><a name="p18811340142116"></a><a name="p18811340142116"></a>#include &lt;sys/socket.h&gt;</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.5.1.2 "><p id="p2881174042110"><a name="p2881174042110"></a><a name="p2881174042110"></a>int listen(int sockfd, int backlog);</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.5.1.3 "><p id="p1688114014216"><a name="p1688114014216"></a><a name="p1688114014216"></a>Listens for sockets.</p>
</td>
</tr>
<tr id="row64501416616"><td class="cellrowborder" valign="top" headers="mcps1.2.5.1.1 "><p id="p5844202419450"><a name="p5844202419450"></a><a name="p5844202419450"></a>#include &lt;sys/socket.h&gt;</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.5.1.2 "><p id="p104501116614"><a name="p104501116614"></a><a name="p104501116614"></a>ssize_t recvmsg(int sockfd, struct msghdr *msg, int flags);</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.5.1.3 "><p id="p184507117613"><a name="p184507117613"></a><a name="p184507117613"></a>Receives a message from a socket. Note that the IOV size can be 1 only, and the ancillary message is not supported.</p>
</td>
</tr>
<tr id="row2979184353412"><td class="cellrowborder" valign="top" headers="mcps1.2.5.1.1 "><p id="p0979343153417"><a name="p0979343153417"></a><a name="p0979343153417"></a>#include &lt;sys/socket.h&gt;</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.5.1.2 "><p id="p129791043153414"><a name="p129791043153414"></a><a name="p129791043153414"></a>ssize_t send(int sockfd, const void *buf, size_t len, int flags);</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.5.1.3 "><p id="p1597954313346"><a name="p1597954313346"></a><a name="p1597954313346"></a>Sends messages from a socket.</p>
</td>
</tr>
<tr id="row139791843153410"><td class="cellrowborder" valign="top" headers="mcps1.2.5.1.1 "><p id="p5980104310349"><a name="p5980104310349"></a><a name="p5980104310349"></a>#include &lt;sys/socket.h&gt;</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.5.1.2 "><p id="p1198012436344"><a name="p1198012436344"></a><a name="p1198012436344"></a>ssize_t sendmsg(int sockfd, const struct msghdr *msg, int flags);</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.5.1.3 "><p id="p13980243183417"><a name="p13980243183417"></a><a name="p13980243183417"></a>Sends messages from a socket. Ancillary messages are not supported.</p>
</td>
</tr>
<tr id="row149807433341"><td class="cellrowborder" valign="top" headers="mcps1.2.5.1.1 "><p id="p15980144323412"><a name="p15980144323412"></a><a name="p15980144323412"></a>#include &lt;sys/socket.h&gt;</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.5.1.2 "><p id="p11980443123414"><a name="p11980443123414"></a><a name="p11980443123414"></a>ssize_t sendto(int sockfd, const void *buf, size_t len, int flags,const struct sockaddr *dest_addr, socklen_t addrlen);</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.5.1.3 "><p id="p7980194311344"><a name="p7980194311344"></a><a name="p7980194311344"></a>Sends messages from a socket.</p>
</td>
</tr>
<tr id="row898074393417"><td class="cellrowborder" valign="top" headers="mcps1.2.5.1.1 "><p id="p15980104333410"><a name="p15980104333410"></a><a name="p15980104333410"></a>#include &lt;sys/socket.h&gt;</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.5.1.2 "><p id="p15980164323416"><a name="p15980164323416"></a><a name="p15980164323416"></a>int setsockopt(int sockfd, int level, int optname,const void *optval, socklen_t optlen);</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.5.1.3 "><p id="p11980043103411"><a name="p11980043103411"></a><a name="p11980043103411"></a>Sets the options associated with a socket.</p>
</td>
</tr>
<tr id="row59327368348"><td class="cellrowborder" rowspan="6" valign="top" width="7.12%" headers="mcps1.2.5.1.1 "><p id="p129931916164016"><a name="p129931916164016"></a><a name="p129931916164016"></a>mem</p>
</td>
<td class="cellrowborder" valign="top" width="17.150000000000002%" headers="mcps1.2.5.1.2 "><p id="p209321136103410"><a name="p209321136103410"></a><a name="p209321136103410"></a>#include &lt;string.h&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="52.27%" headers="mcps1.2.5.1.3 "><p id="p19932103663417"><a name="p19932103663417"></a><a name="p19932103663417"></a>int memcmp(const void *s1, const void *s2, size_t n);</p>
</td>
<td class="cellrowborder" valign="top" width="23.46%" headers="mcps1.2.5.1.4 "><p id="p09321336203411"><a name="p09321336203411"></a><a name="p09321336203411"></a>Compares memory areas.</p>
</td>
</tr>
<tr id="row17437149124012"><td class="cellrowborder" valign="top" headers="mcps1.2.5.1.1 "><p id="p208071728194615"><a name="p208071728194615"></a><a name="p208071728194615"></a>#include &lt;string.h&gt;</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.5.1.2 "><p id="p14389913408"><a name="p14389913408"></a><a name="p14389913408"></a>void *memcpy(void *dest, const void *src, size_t n);</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.5.1.3 "><p id="p1543815917403"><a name="p1543815917403"></a><a name="p1543815917403"></a>Copies memory content.</p>
</td>
</tr>
<tr id="row11684183115320"><td class="cellrowborder" valign="top" headers="mcps1.2.5.1.1 "><p id="p268516355318"><a name="p268516355318"></a><a name="p268516355318"></a>#include &lt;string.h&gt;</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.5.1.2 "><p id="p146851314532"><a name="p146851314532"></a><a name="p146851314532"></a>void *memset(void *s, int c, size_t n);</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.5.1.3 "><p id="p868518395320"><a name="p868518395320"></a><a name="p868518395320"></a>Initializes memory. </p>
</td>
</tr>
<tr id="row2099214166403"><td class="cellrowborder" valign="top" headers="mcps1.2.5.1.1 "><p id="p2807028194619"><a name="p2807028194619"></a><a name="p2807028194619"></a>#include &lt;stdlib.h&gt;</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.5.1.2 "><p id="p79931616194019"><a name="p79931616194019"></a><a name="p79931616194019"></a>void *realloc(void *ptr, size_t size);</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.5.1.3 "><p id="p1299301634017"><a name="p1299301634017"></a><a name="p1299301634017"></a>Reallocates memory.</p>
</td>
</tr>
<tr id="row447918395349"><td class="cellrowborder" valign="top" headers="mcps1.2.5.1.1 "><p id="p12480163913340"><a name="p12480163913340"></a><a name="p12480163913340"></a>#include &lt;stdlib.h&gt;</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.5.1.2 "><p id="p16985123152111"><a name="p16985123152111"></a><a name="p16985123152111"></a>void *malloc(size_t size);</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.5.1.3 "><p id="p3480173919348"><a name="p3480173919348"></a><a name="p3480173919348"></a>Dynamically allocates memory blocks.</p>
</td>
</tr>
<tr id="row4480153914344"><td class="cellrowborder" valign="top" headers="mcps1.2.5.1.1 "><p id="p548053973419"><a name="p548053973419"></a><a name="p548053973419"></a>#include &lt;stdlib.h&gt;</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.5.1.2 "><p id="p17480113923414"><a name="p17480113923414"></a><a name="p17480113923414"></a>void free(void *ptr);</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.5.1.3 "><p id="p1448013943410"><a name="p1448013943410"></a><a name="p1448013943410"></a>Releases the memory space to which the PTR pointer points.</p>
</td>
</tr>
<tr id="row388742014014"><td class="cellrowborder" rowspan="13" valign="top" width="7.12%" headers="mcps1.2.5.1.1 "><p id="p19888162024012"><a name="p19888162024012"></a><a name="p19888162024012"></a>IPC</p>
</td>
<td class="cellrowborder" valign="top" width="17.150000000000002%" headers="mcps1.2.5.1.2 "><p id="p138071928104615"><a name="p138071928104615"></a><a name="p138071928104615"></a>#include &lt;semaphore.h&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="52.27%" headers="mcps1.2.5.1.3 "><p id="p118881820184016"><a name="p118881820184016"></a><a name="p118881820184016"></a>int sem_timedwait(sem_t *sem, const struct timespec *abs_timeout);</p>
</td>
<td class="cellrowborder" valign="top" width="23.46%" headers="mcps1.2.5.1.4 "><p id="p388892013404"><a name="p388892013404"></a><a name="p388892013404"></a>Locks a semaphore for a specified period of time.</p>
</td>
</tr>
<tr id="row357917181295"><td class="cellrowborder" valign="top" headers="mcps1.2.5.1.1 "><p id="p458013181192"><a name="p458013181192"></a><a name="p458013181192"></a>#include &lt;semaphore.h&gt;</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.5.1.2 "><p id="p125801118890"><a name="p125801118890"></a><a name="p125801118890"></a>int sem_destroy(sem_t *sem);</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.5.1.3 "><p id="p25806181194"><a name="p25806181194"></a><a name="p25806181194"></a>Destroys a specified anonymous semaphore.</p>
</td>
</tr>
<tr id="row05803181897"><td class="cellrowborder" valign="top" headers="mcps1.2.5.1.1 "><p id="p965910415379"><a name="p965910415379"></a><a name="p965910415379"></a>#include &lt;semaphore.h&gt;</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.5.1.2 "><p id="p1158019187910"><a name="p1158019187910"></a><a name="p1158019187910"></a>int sem_init(sem_t *sem, int pshared, unsigned int value);</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.5.1.3 "><p id="p7580718798"><a name="p7580718798"></a><a name="p7580718798"></a>Creates and initializes an anonymous semaphore.</p>
</td>
</tr>
<tr id="row15580101816916"><td class="cellrowborder" valign="top" headers="mcps1.2.5.1.1 "><p id="p9921642163719"><a name="p9921642163719"></a><a name="p9921642163719"></a>#include &lt;semaphore.h&gt;</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.5.1.2 "><p id="p1058018181998"><a name="p1058018181998"></a><a name="p1058018181998"></a>int sem_post(sem_t *sem);</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.5.1.3 "><p id="p658019185916"><a name="p658019185916"></a><a name="p658019185916"></a>Increments the semaphore count.</p>
</td>
</tr>
<tr id="row1458017183918"><td class="cellrowborder" valign="top" headers="mcps1.2.5.1.1 "><p id="p85814181393"><a name="p85814181393"></a><a name="p85814181393"></a>#include &lt;semaphore.h&gt;</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.5.1.2 "><p id="p11756161916208"><a name="p11756161916208"></a><a name="p11756161916208"></a>int sem_wait(sem_t *sem);</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.5.1.3 "><p id="p3581618993"><a name="p3581618993"></a><a name="p3581618993"></a>Obtains the semaphore.</p>
</td>
</tr>
<tr id="row56785240910"><td class="cellrowborder" valign="top" headers="mcps1.2.5.1.1 "><p id="p192055120141"><a name="p192055120141"></a><a name="p192055120141"></a>#include &lt;mqueue.h&gt;</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.5.1.2 "><p id="p10205191101411"><a name="p10205191101411"></a><a name="p10205191101411"></a>mqd_t mq_open(const char *mqName, int openFlag, ...);</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.5.1.3 "><p id="p020517151411"><a name="p020517151411"></a><a name="p020517151411"></a>Opens an existing message queue with the specified name or creates a message queue.</p>
</td>
</tr>
<tr id="row16678142410913"><td class="cellrowborder" valign="top" headers="mcps1.2.5.1.1 "><p id="p142057101413"><a name="p142057101413"></a><a name="p142057101413"></a>#include &lt;mqueue.h&gt;</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.5.1.2 "><p id="p129641445193920"><a name="p129641445193920"></a><a name="p129641445193920"></a>int mq_close(mqd_t personal);</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.5.1.3 "><p id="p82058181420"><a name="p82058181420"></a><a name="p82058181420"></a>Closes the message queue with the specified descriptor.</p>
</td>
</tr>
<tr id="row5679162419919"><td class="cellrowborder" valign="top" headers="mcps1.2.5.1.1 "><p id="p11663102233813"><a name="p11663102233813"></a><a name="p11663102233813"></a>#include &lt;mqueue.h&gt;</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.5.1.2 "><p id="p1560314154018"><a name="p1560314154018"></a><a name="p1560314154018"></a>int mq_unlink(const char *mqName);</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.5.1.3 "><p id="p162051116145"><a name="p162051116145"></a><a name="p162051116145"></a>Deletes a specified message queue.</p>
</td>
</tr>
<tr id="row167922416916"><td class="cellrowborder" valign="top" headers="mcps1.2.5.1.1 "><p id="p6882949154012"><a name="p6882949154012"></a><a name="p6882949154012"></a>#include &lt;mqueue.h&gt;</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.5.1.2 "><p id="p78764844116"><a name="p78764844116"></a><a name="p78764844116"></a>int mq_send(mqd_t personal, const char *msg, size_t msgLen, unsigned int msgPrio);</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.5.1.3 "><p id="p5205213140"><a name="p5205213140"></a><a name="p5205213140"></a>Puts a message with the specified content and length into a message queue with the specified descriptor.</p>
</td>
</tr>
<tr id="row20679024593"><td class="cellrowborder" valign="top" headers="mcps1.2.5.1.1 "><p id="p152819617554"><a name="p152819617554"></a><a name="p152819617554"></a>#include &lt;mqueue.h&gt;</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.5.1.2 "><p id="p54441632204118"><a name="p54441632204118"></a><a name="p54441632204118"></a>ssize_t mq_receive(mqd_t personal, char *msg, size_t msgLen, unsigned int *msgPrio);</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.5.1.3 "><p id="p12059120142"><a name="p12059120142"></a><a name="p12059120142"></a>Deletes the oldest message from the message queue with the specified descriptor and places it in the buffer pointed to by <strong id="b1031572273419"><a name="b1031572273419"></a><a name="b1031572273419"></a>msg_ptr</strong>.</p>
</td>
</tr>
<tr id="row719951101419"><td class="cellrowborder" valign="top" headers="mcps1.2.5.1.1 "><p id="p388725965813"><a name="p388725965813"></a><a name="p388725965813"></a>#include &lt;mqueue.h&gt;</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.5.1.2 "><p id="p431245552811"><a name="p431245552811"></a><a name="p431245552811"></a>int mq_timedsend(mqd_t personal, const char *msg, size_t msgLen, unsigned int msgPrio, const struct timespec *absTimeout)</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.5.1.3 "><p id="p192059121411"><a name="p192059121411"></a><a name="p192059121411"></a>Puts a message with the specified content and length into a message queue identified by the specified descriptor within specified time.</p>
</td>
</tr>
<tr id="row4199111181414"><td class="cellrowborder" valign="top" headers="mcps1.2.5.1.1 "><p id="p5206616147"><a name="p5206616147"></a><a name="p5206616147"></a>#include &lt;mqueue.h&gt;</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.5.1.2 "><p id="p118053329296"><a name="p118053329296"></a><a name="p118053329296"></a>ssize_t mq_timedreceive(mqd_t personal, char *msg, size_t msgLen, unsigned int *msgPrio, const struct timespec *absTimeout);</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.5.1.3 "><p id="p1520641121417"><a name="p1520641121417"></a><a name="p1520641121417"></a>Obtains a message with the specified content and length from a message queue specified by the descriptor.</p>
</td>
</tr>
<tr id="row1219914111419"><td class="cellrowborder" valign="top" headers="mcps1.2.5.1.1 "><p id="p112066171415"><a name="p112066171415"></a><a name="p112066171415"></a>#include &lt;mqueue.h&gt;</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.5.1.2 "><p id="p186421481608"><a name="p186421481608"></a><a name="p186421481608"></a>int mq_setattr(mqd_t mqdes, const struct mq_attr *__restrict newattr, struct mq_attr *__restrict oldattr);</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.5.1.3 "><p id="p220661141420"><a name="p220661141420"></a><a name="p220661141420"></a>Sets the attributes of the message queue specified by the descriptor.</p>
</td>
</tr>
<tr id="row9203714147"><td class="cellrowborder" rowspan="2" valign="top" width="7.12%" headers="mcps1.2.5.1.1 "><p id="p127021732195315"><a name="p127021732195315"></a><a name="p127021732195315"></a>version</p>
</td>
<td class="cellrowborder" valign="top" width="17.150000000000002%" headers="mcps1.2.5.1.2 "><p id="p1220411113145"><a name="p1220411113145"></a><a name="p1220411113145"></a>#include &lt;libc.h&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="52.27%" headers="mcps1.2.5.1.3 "><p id="p2821912103011"><a name="p2821912103011"></a><a name="p2821912103011"></a>const char *libc_get_version_string(void);</p>
</td>
<td class="cellrowborder" valign="top" width="23.46%" headers="mcps1.2.5.1.4 "><p id="p132041115142"><a name="p132041115142"></a><a name="p132041115142"></a>Obtains the libc version string.</p>
</td>
</tr>
<tr id="row020441171415"><td class="cellrowborder" valign="top" headers="mcps1.2.5.1.1 "><p id="p6204191161411"><a name="p6204191161411"></a><a name="p6204191161411"></a>#include &lt;libc.h&gt;</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.5.1.2 "><p id="p7821112113010"><a name="p7821112113010"></a><a name="p7821112113010"></a>int libc_get_version(void);</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.5.1.3 "><p id="p7204910140"><a name="p7204910140"></a><a name="p7204910140"></a>Obtains the libc version.</p>
</td>
</tr>
</tbody>
</table>

### Important Notes<a name="section109174418147"></a>

Error codes

<a name="table1461445611617"></a>
<table><thead align="left"><tr id="row361595620166"><th class="cellrowborder" valign="top" width="18.87811218878112%" id="mcps1.1.5.1.1"><p id="p1961585615162"><a name="p1961585615162"></a><a name="p1961585615162"></a>C Name</p>
</th>
<th class="cellrowborder" valign="top" width="8.389161083891612%" id="mcps1.1.5.1.2"><p id="p1161595616164"><a name="p1161595616164"></a><a name="p1161595616164"></a>Value</p>
</th>
<th class="cellrowborder" valign="top" width="39.156084391560846%" id="mcps1.1.5.1.3"><p id="p96151756151619"><a name="p96151756151619"></a><a name="p96151756151619"></a>Description</p>
</th>
<th class="cellrowborder" valign="top" width="33.57664233576642%" id="mcps1.1.5.1.4"><p id="p101874273188"><a name="p101874273188"></a><a name="p101874273188"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row176151756201613"><td class="cellrowborder" valign="top" width="18.87811218878112%" headers="mcps1.1.5.1.1 "><p id="p17615125610163"><a name="p17615125610163"></a><a name="p17615125610163"></a>ENOERR</p>
</td>
<td class="cellrowborder" valign="top" width="8.389161083891612%" headers="mcps1.1.5.1.2 "><p id="p6615185613168"><a name="p6615185613168"></a><a name="p6615185613168"></a>0</p>
</td>
<td class="cellrowborder" valign="top" width="39.156084391560846%" headers="mcps1.1.5.1.3 "><p id="p1161516567163"><a name="p1161516567163"></a><a name="p1161516567163"></a>Success</p>
</td>
<td class="cellrowborder" valign="top" width="33.57664233576642%" headers="mcps1.1.5.1.4 "><p id="p1518722761813"><a name="p1518722761813"></a><a name="p1518722761813"></a>Successful</p>
</td>
</tr>
<tr id="row126154564169"><td class="cellrowborder" valign="top" width="18.87811218878112%" headers="mcps1.1.5.1.1 "><p id="p12615185615169"><a name="p12615185615169"></a><a name="p12615185615169"></a>EPERM</p>
</td>
<td class="cellrowborder" valign="top" width="8.389161083891612%" headers="mcps1.1.5.1.2 "><p id="p13615956201618"><a name="p13615956201618"></a><a name="p13615956201618"></a>1</p>
</td>
<td class="cellrowborder" valign="top" width="39.156084391560846%" headers="mcps1.1.5.1.3 "><p id="p861613566169"><a name="p861613566169"></a><a name="p861613566169"></a>Operation not permitted</p>
</td>
<td class="cellrowborder" valign="top" width="33.57664233576642%" headers="mcps1.1.5.1.4 "><p id="p1118714279189"><a name="p1118714279189"></a><a name="p1118714279189"></a>The operation is not allowed.</p>
</td>
</tr>
<tr id="row166161156171619"><td class="cellrowborder" valign="top" width="18.87811218878112%" headers="mcps1.1.5.1.1 "><p id="p36167568161"><a name="p36167568161"></a><a name="p36167568161"></a>ENOENT</p>
</td>
<td class="cellrowborder" valign="top" width="8.389161083891612%" headers="mcps1.1.5.1.2 "><p id="p8616125613161"><a name="p8616125613161"></a><a name="p8616125613161"></a>2</p>
</td>
<td class="cellrowborder" valign="top" width="39.156084391560846%" headers="mcps1.1.5.1.3 "><p id="p18616195618167"><a name="p18616195618167"></a><a name="p18616195618167"></a>No such file or directory</p>
</td>
<td class="cellrowborder" valign="top" width="33.57664233576642%" headers="mcps1.1.5.1.4 "><p id="p1187827161819"><a name="p1187827161819"></a><a name="p1187827161819"></a>The file or directory does not exist.</p>
</td>
</tr>
<tr id="row1661615691612"><td class="cellrowborder" valign="top" width="18.87811218878112%" headers="mcps1.1.5.1.1 "><p id="p1361655661611"><a name="p1361655661611"></a><a name="p1361655661611"></a>ESRCH</p>
</td>
<td class="cellrowborder" valign="top" width="8.389161083891612%" headers="mcps1.1.5.1.2 "><p id="p1561675613160"><a name="p1561675613160"></a><a name="p1561675613160"></a>3</p>
</td>
<td class="cellrowborder" valign="top" width="39.156084391560846%" headers="mcps1.1.5.1.3 "><p id="p5616115614168"><a name="p5616115614168"></a><a name="p5616115614168"></a>No such process</p>
</td>
<td class="cellrowborder" valign="top" width="33.57664233576642%" headers="mcps1.1.5.1.4 "><p id="p1018714272182"><a name="p1018714272182"></a><a name="p1018714272182"></a>There is no such process (not supported currently).</p>
</td>
</tr>
<tr id="row1461635614168"><td class="cellrowborder" valign="top" width="18.87811218878112%" headers="mcps1.1.5.1.1 "><p id="p3616185610166"><a name="p3616185610166"></a><a name="p3616185610166"></a>EINTR</p>
</td>
<td class="cellrowborder" valign="top" width="8.389161083891612%" headers="mcps1.1.5.1.2 "><p id="p14617956151610"><a name="p14617956151610"></a><a name="p14617956151610"></a>4</p>
</td>
<td class="cellrowborder" valign="top" width="39.156084391560846%" headers="mcps1.1.5.1.3 "><p id="p7617135620164"><a name="p7617135620164"></a><a name="p7617135620164"></a>Interrupted system call</p>
</td>
<td class="cellrowborder" valign="top" width="33.57664233576642%" headers="mcps1.1.5.1.4 "><p id="p4188192741814"><a name="p4188192741814"></a><a name="p4188192741814"></a>The system call is interrupted.</p>
</td>
</tr>
<tr id="row9617256101619"><td class="cellrowborder" valign="top" width="18.87811218878112%" headers="mcps1.1.5.1.1 "><p id="p4617156111610"><a name="p4617156111610"></a><a name="p4617156111610"></a>EIO</p>
</td>
<td class="cellrowborder" valign="top" width="8.389161083891612%" headers="mcps1.1.5.1.2 "><p id="p4617175621618"><a name="p4617175621618"></a><a name="p4617175621618"></a>5</p>
</td>
<td class="cellrowborder" valign="top" width="39.156084391560846%" headers="mcps1.1.5.1.3 "><p id="p961715567163"><a name="p961715567163"></a><a name="p961715567163"></a>I/O error</p>
</td>
<td class="cellrowborder" valign="top" width="33.57664233576642%" headers="mcps1.1.5.1.4 "><p id="p161881127111815"><a name="p161881127111815"></a><a name="p161881127111815"></a>An I/O error occurs. </p>
</td>
</tr>
<tr id="row1361712566166"><td class="cellrowborder" valign="top" width="18.87811218878112%" headers="mcps1.1.5.1.1 "><p id="p126171656171612"><a name="p126171656171612"></a><a name="p126171656171612"></a>ENXIO</p>
</td>
<td class="cellrowborder" valign="top" width="8.389161083891612%" headers="mcps1.1.5.1.2 "><p id="p861715613163"><a name="p861715613163"></a><a name="p861715613163"></a>6</p>
</td>
<td class="cellrowborder" valign="top" width="39.156084391560846%" headers="mcps1.1.5.1.3 "><p id="p2617165612163"><a name="p2617165612163"></a><a name="p2617165612163"></a>No such device or address</p>
</td>
<td class="cellrowborder" valign="top" width="33.57664233576642%" headers="mcps1.1.5.1.4 "><p id="p3188627191815"><a name="p3188627191815"></a><a name="p3188627191815"></a>The device or address does not exist.</p>
</td>
</tr>
<tr id="row6350047161918"><td class="cellrowborder" valign="top" width="18.87811218878112%" headers="mcps1.1.5.1.1 "><p id="p735194715198"><a name="p735194715198"></a><a name="p735194715198"></a>E2BIG</p>
</td>
<td class="cellrowborder" valign="top" width="8.389161083891612%" headers="mcps1.1.5.1.2 "><p id="p5351124711910"><a name="p5351124711910"></a><a name="p5351124711910"></a>7</p>
</td>
<td class="cellrowborder" valign="top" width="39.156084391560846%" headers="mcps1.1.5.1.3 "><p id="p0352134781911"><a name="p0352134781911"></a><a name="p0352134781911"></a>Arg list too long</p>
</td>
<td class="cellrowborder" valign="top" width="33.57664233576642%" headers="mcps1.1.5.1.4 "><p id="p435214761913"><a name="p435214761913"></a><a name="p435214761913"></a>The parameter list is too long.</p>
</td>
</tr>
<tr id="row213975216193"><td class="cellrowborder" valign="top" width="18.87811218878112%" headers="mcps1.1.5.1.1 "><p id="p5140752121916"><a name="p5140752121916"></a><a name="p5140752121916"></a>ENOEXEC</p>
</td>
<td class="cellrowborder" valign="top" width="8.389161083891612%" headers="mcps1.1.5.1.2 "><p id="p714065217191"><a name="p714065217191"></a><a name="p714065217191"></a>8</p>
</td>
<td class="cellrowborder" valign="top" width="39.156084391560846%" headers="mcps1.1.5.1.3 "><p id="p1014011526195"><a name="p1014011526195"></a><a name="p1014011526195"></a>Exec format error</p>
</td>
<td class="cellrowborder" valign="top" width="33.57664233576642%" headers="mcps1.1.5.1.4 "><p id="p16140165210195"><a name="p16140165210195"></a><a name="p16140165210195"></a>The execution format is incorrect.</p>
</td>
</tr>
<tr id="row102512056181910"><td class="cellrowborder" valign="top" width="18.87811218878112%" headers="mcps1.1.5.1.1 "><p id="p192526568193"><a name="p192526568193"></a><a name="p192526568193"></a>EBADF</p>
</td>
<td class="cellrowborder" valign="top" width="8.389161083891612%" headers="mcps1.1.5.1.2 "><p id="p425216569195"><a name="p425216569195"></a><a name="p425216569195"></a>9</p>
</td>
<td class="cellrowborder" valign="top" width="39.156084391560846%" headers="mcps1.1.5.1.3 "><p id="p425275616196"><a name="p425275616196"></a><a name="p425275616196"></a>Bad file number</p>
</td>
<td class="cellrowborder" valign="top" width="33.57664233576642%" headers="mcps1.1.5.1.4 "><p id="p1225255611911"><a name="p1225255611911"></a><a name="p1225255611911"></a>The file descriptor is invalid.</p>
</td>
</tr>
<tr id="row440551118208"><td class="cellrowborder" valign="top" width="18.87811218878112%" headers="mcps1.1.5.1.1 "><p id="p11405181102016"><a name="p11405181102016"></a><a name="p11405181102016"></a>ECHILD</p>
</td>
<td class="cellrowborder" valign="top" width="8.389161083891612%" headers="mcps1.1.5.1.2 "><p id="p440661111200"><a name="p440661111200"></a><a name="p440661111200"></a>10</p>
</td>
<td class="cellrowborder" valign="top" width="39.156084391560846%" headers="mcps1.1.5.1.3 "><p id="p124061211192013"><a name="p124061211192013"></a><a name="p124061211192013"></a>No child processes</p>
</td>
<td class="cellrowborder" valign="top" width="33.57664233576642%" headers="mcps1.1.5.1.4 "><p id="p24067113203"><a name="p24067113203"></a><a name="p24067113203"></a>There is no child process (not supported currently).</p>
</td>
</tr>
<tr id="row17406611142014"><td class="cellrowborder" valign="top" width="18.87811218878112%" headers="mcps1.1.5.1.1 "><p id="p9406181112208"><a name="p9406181112208"></a><a name="p9406181112208"></a>EAGAIN</p>
</td>
<td class="cellrowborder" valign="top" width="8.389161083891612%" headers="mcps1.1.5.1.2 "><p id="p14061911152017"><a name="p14061911152017"></a><a name="p14061911152017"></a>11</p>
</td>
<td class="cellrowborder" valign="top" width="39.156084391560846%" headers="mcps1.1.5.1.3 "><p id="p2040618116209"><a name="p2040618116209"></a><a name="p2040618116209"></a>Try again</p>
</td>
<td class="cellrowborder" valign="top" width="33.57664233576642%" headers="mcps1.1.5.1.4 "><p id="p124061311152012"><a name="p124061311152012"></a><a name="p124061311152012"></a>The resource is temporarily unavailable.</p>
</td>
</tr>
<tr id="row19372181712202"><td class="cellrowborder" valign="top" width="18.87811218878112%" headers="mcps1.1.5.1.1 "><p id="p20372161792018"><a name="p20372161792018"></a><a name="p20372161792018"></a>ENOMEM</p>
</td>
<td class="cellrowborder" valign="top" width="8.389161083891612%" headers="mcps1.1.5.1.2 "><p id="p133721217102014"><a name="p133721217102014"></a><a name="p133721217102014"></a>12</p>
</td>
<td class="cellrowborder" valign="top" width="39.156084391560846%" headers="mcps1.1.5.1.3 "><p id="p1237231772016"><a name="p1237231772016"></a><a name="p1237231772016"></a>Out of memory</p>
</td>
<td class="cellrowborder" valign="top" width="33.57664233576642%" headers="mcps1.1.5.1.4 "><p id="p3372101716207"><a name="p3372101716207"></a><a name="p3372101716207"></a>The memory overflows.</p>
</td>
</tr>
<tr id="row113721617102013"><td class="cellrowborder" valign="top" width="18.87811218878112%" headers="mcps1.1.5.1.1 "><p id="p63721017172015"><a name="p63721017172015"></a><a name="p63721017172015"></a>EACCES</p>
</td>
<td class="cellrowborder" valign="top" width="8.389161083891612%" headers="mcps1.1.5.1.2 "><p id="p5372111712202"><a name="p5372111712202"></a><a name="p5372111712202"></a>13</p>
</td>
<td class="cellrowborder" valign="top" width="39.156084391560846%" headers="mcps1.1.5.1.3 "><p id="p837281772015"><a name="p837281772015"></a><a name="p837281772015"></a>Permission denied</p>
</td>
<td class="cellrowborder" valign="top" width="33.57664233576642%" headers="mcps1.1.5.1.4 "><p id="p63721717192011"><a name="p63721717192011"></a><a name="p63721717192011"></a>The permission is rejected.</p>
</td>
</tr>
<tr id="row1237241712201"><td class="cellrowborder" valign="top" width="18.87811218878112%" headers="mcps1.1.5.1.1 "><p id="p1937381711208"><a name="p1937381711208"></a><a name="p1937381711208"></a>EFAULT</p>
</td>
<td class="cellrowborder" valign="top" width="8.389161083891612%" headers="mcps1.1.5.1.2 "><p id="p6373191717208"><a name="p6373191717208"></a><a name="p6373191717208"></a>14</p>
</td>
<td class="cellrowborder" valign="top" width="39.156084391560846%" headers="mcps1.1.5.1.3 "><p id="p6373717142017"><a name="p6373717142017"></a><a name="p6373717142017"></a>Bad address</p>
</td>
<td class="cellrowborder" valign="top" width="33.57664233576642%" headers="mcps1.1.5.1.4 "><p id="p14373101710201"><a name="p14373101710201"></a><a name="p14373101710201"></a>The address is incorrect.</p>
</td>
</tr>
<tr id="row6373101714204"><td class="cellrowborder" valign="top" width="18.87811218878112%" headers="mcps1.1.5.1.1 "><p id="p9373201719200"><a name="p9373201719200"></a><a name="p9373201719200"></a>ENOTBLK</p>
</td>
<td class="cellrowborder" valign="top" width="8.389161083891612%" headers="mcps1.1.5.1.2 "><p id="p1737331732020"><a name="p1737331732020"></a><a name="p1737331732020"></a>15</p>
</td>
<td class="cellrowborder" valign="top" width="39.156084391560846%" headers="mcps1.1.5.1.3 "><p id="p1837371742015"><a name="p1837371742015"></a><a name="p1837371742015"></a>Block device required</p>
</td>
<td class="cellrowborder" valign="top" width="33.57664233576642%" headers="mcps1.1.5.1.4 "><p id="p3373191716208"><a name="p3373191716208"></a><a name="p3373191716208"></a>A block device is required.</p>
</td>
</tr>
<tr id="row1737381712204"><td class="cellrowborder" valign="top" width="18.87811218878112%" headers="mcps1.1.5.1.1 "><p id="p183731917112019"><a name="p183731917112019"></a><a name="p183731917112019"></a>EBUSY</p>
</td>
<td class="cellrowborder" valign="top" width="8.389161083891612%" headers="mcps1.1.5.1.2 "><p id="p83739178201"><a name="p83739178201"></a><a name="p83739178201"></a>16</p>
</td>
<td class="cellrowborder" valign="top" width="39.156084391560846%" headers="mcps1.1.5.1.3 "><p id="p13731717142019"><a name="p13731717142019"></a><a name="p13731717142019"></a>Device or resource busy</p>
</td>
<td class="cellrowborder" valign="top" width="33.57664233576642%" headers="mcps1.1.5.1.4 "><p id="p5373917182015"><a name="p5373917182015"></a><a name="p5373917182015"></a>The device or resource is engaged.</p>
</td>
</tr>
<tr id="row126222262207"><td class="cellrowborder" valign="top" width="18.87811218878112%" headers="mcps1.1.5.1.1 "><p id="p196221526122019"><a name="p196221526122019"></a><a name="p196221526122019"></a>EEXIST</p>
</td>
<td class="cellrowborder" valign="top" width="8.389161083891612%" headers="mcps1.1.5.1.2 "><p id="p26221526202018"><a name="p26221526202018"></a><a name="p26221526202018"></a>17</p>
</td>
<td class="cellrowborder" valign="top" width="39.156084391560846%" headers="mcps1.1.5.1.3 "><p id="p15622826102020"><a name="p15622826102020"></a><a name="p15622826102020"></a>File exists</p>
</td>
<td class="cellrowborder" valign="top" width="33.57664233576642%" headers="mcps1.1.5.1.4 "><p id="p0622182610202"><a name="p0622182610202"></a><a name="p0622182610202"></a>The file already exists.</p>
</td>
</tr>
<tr id="row262213261209"><td class="cellrowborder" valign="top" width="18.87811218878112%" headers="mcps1.1.5.1.1 "><p id="p362322652010"><a name="p362322652010"></a><a name="p362322652010"></a>EXDEV</p>
</td>
<td class="cellrowborder" valign="top" width="8.389161083891612%" headers="mcps1.1.5.1.2 "><p id="p1362342611204"><a name="p1362342611204"></a><a name="p1362342611204"></a>18</p>
</td>
<td class="cellrowborder" valign="top" width="39.156084391560846%" headers="mcps1.1.5.1.3 "><p id="p196231626192013"><a name="p196231626192013"></a><a name="p196231626192013"></a>Cross-device link</p>
</td>
<td class="cellrowborder" valign="top" width="33.57664233576642%" headers="mcps1.1.5.1.4 "><p id="p1762317261203"><a name="p1762317261203"></a><a name="p1762317261203"></a>The cross-device link is invalid.</p>
</td>
</tr>
<tr id="row196234264205"><td class="cellrowborder" valign="top" width="18.87811218878112%" headers="mcps1.1.5.1.1 "><p id="p16623152620202"><a name="p16623152620202"></a><a name="p16623152620202"></a>ENODEV</p>
</td>
<td class="cellrowborder" valign="top" width="8.389161083891612%" headers="mcps1.1.5.1.2 "><p id="p146232026112020"><a name="p146232026112020"></a><a name="p146232026112020"></a>19</p>
</td>
<td class="cellrowborder" valign="top" width="39.156084391560846%" headers="mcps1.1.5.1.3 "><p id="p7623122611209"><a name="p7623122611209"></a><a name="p7623122611209"></a>No such device</p>
</td>
<td class="cellrowborder" valign="top" width="33.57664233576642%" headers="mcps1.1.5.1.4 "><p id="p762372662018"><a name="p762372662018"></a><a name="p762372662018"></a>The device does not exist.</p>
</td>
</tr>
<tr id="row662392672016"><td class="cellrowborder" valign="top" width="18.87811218878112%" headers="mcps1.1.5.1.1 "><p id="p1662392602016"><a name="p1662392602016"></a><a name="p1662392602016"></a>ENOTDIR</p>
</td>
<td class="cellrowborder" valign="top" width="8.389161083891612%" headers="mcps1.1.5.1.2 "><p id="p15623426162016"><a name="p15623426162016"></a><a name="p15623426162016"></a>20</p>
</td>
<td class="cellrowborder" valign="top" width="39.156084391560846%" headers="mcps1.1.5.1.3 "><p id="p96231426132012"><a name="p96231426132012"></a><a name="p96231426132012"></a>Not a directory</p>
</td>
<td class="cellrowborder" valign="top" width="33.57664233576642%" headers="mcps1.1.5.1.4 "><p id="p46241026132015"><a name="p46241026132015"></a><a name="p46241026132015"></a>It is not a directory.</p>
</td>
</tr>
<tr id="row9624192662010"><td class="cellrowborder" valign="top" width="18.87811218878112%" headers="mcps1.1.5.1.1 "><p id="p136241026102013"><a name="p136241026102013"></a><a name="p136241026102013"></a>EISDIR</p>
</td>
<td class="cellrowborder" valign="top" width="8.389161083891612%" headers="mcps1.1.5.1.2 "><p id="p7624152616208"><a name="p7624152616208"></a><a name="p7624152616208"></a>21</p>
</td>
<td class="cellrowborder" valign="top" width="39.156084391560846%" headers="mcps1.1.5.1.3 "><p id="p3624182610205"><a name="p3624182610205"></a><a name="p3624182610205"></a>Is a directory</p>
</td>
<td class="cellrowborder" valign="top" width="33.57664233576642%" headers="mcps1.1.5.1.4 "><p id="p1662432615206"><a name="p1662432615206"></a><a name="p1662432615206"></a>It is a directory.</p>
</td>
</tr>
<tr id="row17624926132019"><td class="cellrowborder" valign="top" width="18.87811218878112%" headers="mcps1.1.5.1.1 "><p id="p662402642012"><a name="p662402642012"></a><a name="p662402642012"></a>EINVAL</p>
</td>
<td class="cellrowborder" valign="top" width="8.389161083891612%" headers="mcps1.1.5.1.2 "><p id="p12624162632019"><a name="p12624162632019"></a><a name="p12624162632019"></a>22</p>
</td>
<td class="cellrowborder" valign="top" width="39.156084391560846%" headers="mcps1.1.5.1.3 "><p id="p9624126122014"><a name="p9624126122014"></a><a name="p9624126122014"></a>Invalid argument</p>
</td>
<td class="cellrowborder" valign="top" width="33.57664233576642%" headers="mcps1.1.5.1.4 "><p id="p4624132613202"><a name="p4624132613202"></a><a name="p4624132613202"></a>The parameter is invalid.</p>
</td>
</tr>
<tr id="row19624326122011"><td class="cellrowborder" valign="top" width="18.87811218878112%" headers="mcps1.1.5.1.1 "><p id="p96241426192018"><a name="p96241426192018"></a><a name="p96241426192018"></a>ENFILE*</p>
</td>
<td class="cellrowborder" valign="top" width="8.389161083891612%" headers="mcps1.1.5.1.2 "><p id="p7625112619206"><a name="p7625112619206"></a><a name="p7625112619206"></a>23</p>
</td>
<td class="cellrowborder" valign="top" width="39.156084391560846%" headers="mcps1.1.5.1.3 "><p id="p126252026192014"><a name="p126252026192014"></a><a name="p126252026192014"></a>File table overflow</p>
</td>
<td class="cellrowborder" valign="top" width="33.57664233576642%" headers="mcps1.1.5.1.4 "><p id="p1562552618204"><a name="p1562552618204"></a><a name="p1562552618204"></a>The number of file systems opened exceeds the limit.</p>
</td>
</tr>
<tr id="row6625126142011"><td class="cellrowborder" valign="top" width="18.87811218878112%" headers="mcps1.1.5.1.1 "><p id="p186251826142017"><a name="p186251826142017"></a><a name="p186251826142017"></a>EMFILE</p>
</td>
<td class="cellrowborder" valign="top" width="8.389161083891612%" headers="mcps1.1.5.1.2 "><p id="p20625026172012"><a name="p20625026172012"></a><a name="p20625026172012"></a>24</p>
</td>
<td class="cellrowborder" valign="top" width="39.156084391560846%" headers="mcps1.1.5.1.3 "><p id="p1662515264201"><a name="p1662515264201"></a><a name="p1662515264201"></a>Too many open files</p>
</td>
<td class="cellrowborder" valign="top" width="33.57664233576642%" headers="mcps1.1.5.1.4 "><p id="p126259262202"><a name="p126259262202"></a><a name="p126259262202"></a>The number of files opened exceeds the limit.</p>
</td>
</tr>
<tr id="row16636135918198"><td class="cellrowborder" valign="top" width="18.87811218878112%" headers="mcps1.1.5.1.1 "><p id="p263614597194"><a name="p263614597194"></a><a name="p263614597194"></a>EFBIG</p>
</td>
<td class="cellrowborder" valign="top" width="8.389161083891612%" headers="mcps1.1.5.1.2 "><p id="p19636759191913"><a name="p19636759191913"></a><a name="p19636759191913"></a>27</p>
</td>
<td class="cellrowborder" valign="top" width="39.156084391560846%" headers="mcps1.1.5.1.3 "><p id="p15636145917193"><a name="p15636145917193"></a><a name="p15636145917193"></a>File too large</p>
</td>
<td class="cellrowborder" valign="top" width="33.57664233576642%" headers="mcps1.1.5.1.4 "><p id="p1763655971914"><a name="p1763655971914"></a><a name="p1763655971914"></a>The file is too large.</p>
</td>
</tr>
<tr id="row19934164082020"><td class="cellrowborder" valign="top" width="18.87811218878112%" headers="mcps1.1.5.1.1 "><p id="p18935134010206"><a name="p18935134010206"></a><a name="p18935134010206"></a>ENOSPC</p>
</td>
<td class="cellrowborder" valign="top" width="8.389161083891612%" headers="mcps1.1.5.1.2 "><p id="p14935124072017"><a name="p14935124072017"></a><a name="p14935124072017"></a>28</p>
</td>
<td class="cellrowborder" valign="top" width="39.156084391560846%" headers="mcps1.1.5.1.3 "><p id="p19935174017202"><a name="p19935174017202"></a><a name="p19935174017202"></a>No space left on device</p>
</td>
<td class="cellrowborder" valign="top" width="33.57664233576642%" headers="mcps1.1.5.1.4 "><p id="p149351540182020"><a name="p149351540182020"></a><a name="p149351540182020"></a>There is no space on the device.</p>
</td>
</tr>
<tr id="row1493514402208"><td class="cellrowborder" valign="top" width="18.87811218878112%" headers="mcps1.1.5.1.1 "><p id="p1293516403200"><a name="p1293516403200"></a><a name="p1293516403200"></a>ESPIPE</p>
</td>
<td class="cellrowborder" valign="top" width="8.389161083891612%" headers="mcps1.1.5.1.2 "><p id="p0935194012207"><a name="p0935194012207"></a><a name="p0935194012207"></a>29</p>
</td>
<td class="cellrowborder" valign="top" width="39.156084391560846%" headers="mcps1.1.5.1.3 "><p id="p1793554011209"><a name="p1793554011209"></a><a name="p1793554011209"></a>Illegal seek</p>
</td>
<td class="cellrowborder" valign="top" width="33.57664233576642%" headers="mcps1.1.5.1.4 "><p id="p1693554072015"><a name="p1693554072015"></a><a name="p1693554072015"></a>Illegal shift</p>
</td>
</tr>
<tr id="row1593554002016"><td class="cellrowborder" valign="top" width="18.87811218878112%" headers="mcps1.1.5.1.1 "><p id="p6935440162020"><a name="p6935440162020"></a><a name="p6935440162020"></a>EROFS</p>
</td>
<td class="cellrowborder" valign="top" width="8.389161083891612%" headers="mcps1.1.5.1.2 "><p id="p16935184013201"><a name="p16935184013201"></a><a name="p16935184013201"></a>30</p>
</td>
<td class="cellrowborder" valign="top" width="39.156084391560846%" headers="mcps1.1.5.1.3 "><p id="p20935134062015"><a name="p20935134062015"></a><a name="p20935134062015"></a>Read-only file system</p>
</td>
<td class="cellrowborder" valign="top" width="33.57664233576642%" headers="mcps1.1.5.1.4 "><p id="p2936240132017"><a name="p2936240132017"></a><a name="p2936240132017"></a>The file system is read-only.</p>
</td>
</tr>
<tr id="row0936114012013"><td class="cellrowborder" valign="top" width="18.87811218878112%" headers="mcps1.1.5.1.1 "><p id="p79361140172019"><a name="p79361140172019"></a><a name="p79361140172019"></a>EMLINK</p>
</td>
<td class="cellrowborder" valign="top" width="8.389161083891612%" headers="mcps1.1.5.1.2 "><p id="p5936144018202"><a name="p5936144018202"></a><a name="p5936144018202"></a>31</p>
</td>
<td class="cellrowborder" valign="top" width="39.156084391560846%" headers="mcps1.1.5.1.3 "><p id="p17936340182019"><a name="p17936340182019"></a><a name="p17936340182019"></a>Too many links</p>
</td>
<td class="cellrowborder" valign="top" width="33.57664233576642%" headers="mcps1.1.5.1.4 "><p id="p69361540122015"><a name="p69361540122015"></a><a name="p69361540122015"></a>There are too many links.</p>
</td>
</tr>
<tr id="row14936540152011"><td class="cellrowborder" valign="top" width="18.87811218878112%" headers="mcps1.1.5.1.1 "><p id="p109364403207"><a name="p109364403207"></a><a name="p109364403207"></a>EDOM</p>
</td>
<td class="cellrowborder" valign="top" width="8.389161083891612%" headers="mcps1.1.5.1.2 "><p id="p593710401205"><a name="p593710401205"></a><a name="p593710401205"></a>33</p>
</td>
<td class="cellrowborder" valign="top" width="39.156084391560846%" headers="mcps1.1.5.1.3 "><p id="p493714017209"><a name="p493714017209"></a><a name="p493714017209"></a>Math argument out of domain</p>
</td>
<td class="cellrowborder" valign="top" width="33.57664233576642%" headers="mcps1.1.5.1.4 "><p id="p19937194013202"><a name="p19937194013202"></a><a name="p19937194013202"></a>The value is out of range.</p>
</td>
</tr>
<tr id="row0937940142010"><td class="cellrowborder" valign="top" width="18.87811218878112%" headers="mcps1.1.5.1.1 "><p id="p16937104052015"><a name="p16937104052015"></a><a name="p16937104052015"></a>ERANGE</p>
</td>
<td class="cellrowborder" valign="top" width="8.389161083891612%" headers="mcps1.1.5.1.2 "><p id="p393704052010"><a name="p393704052010"></a><a name="p393704052010"></a>34</p>
</td>
<td class="cellrowborder" valign="top" width="39.156084391560846%" headers="mcps1.1.5.1.3 "><p id="p9937104052017"><a name="p9937104052017"></a><a name="p9937104052017"></a>Math result not representable</p>
</td>
<td class="cellrowborder" valign="top" width="33.57664233576642%" headers="mcps1.1.5.1.4 "><p id="p2937184012012"><a name="p2937184012012"></a><a name="p2937184012012"></a>The result is not representative.</p>
</td>
</tr>
<tr id="row0937340112016"><td class="cellrowborder" valign="top" width="18.87811218878112%" headers="mcps1.1.5.1.1 "><p id="p11937144016209"><a name="p11937144016209"></a><a name="p11937144016209"></a>EDEADLK</p>
</td>
<td class="cellrowborder" valign="top" width="8.389161083891612%" headers="mcps1.1.5.1.2 "><p id="p3937164022010"><a name="p3937164022010"></a><a name="p3937164022010"></a>35</p>
</td>
<td class="cellrowborder" valign="top" width="39.156084391560846%" headers="mcps1.1.5.1.3 "><p id="p17937440122016"><a name="p17937440122016"></a><a name="p17937440122016"></a>Resource deadlock would occur</p>
</td>
<td class="cellrowborder" valign="top" width="33.57664233576642%" headers="mcps1.1.5.1.4 "><p id="p159371140152015"><a name="p159371140152015"></a><a name="p159371140152015"></a>Resource deadlock occurs.</p>
</td>
</tr>
<tr id="row1293704015200"><td class="cellrowborder" valign="top" width="18.87811218878112%" headers="mcps1.1.5.1.1 "><p id="p13937184012012"><a name="p13937184012012"></a><a name="p13937184012012"></a>ENAMETOOLONG</p>
</td>
<td class="cellrowborder" valign="top" width="8.389161083891612%" headers="mcps1.1.5.1.2 "><p id="p7938440132016"><a name="p7938440132016"></a><a name="p7938440132016"></a>36</p>
</td>
<td class="cellrowborder" valign="top" width="39.156084391560846%" headers="mcps1.1.5.1.3 "><p id="p1693864022011"><a name="p1693864022011"></a><a name="p1693864022011"></a>Filename too long</p>
</td>
<td class="cellrowborder" valign="top" width="33.57664233576642%" headers="mcps1.1.5.1.4 "><p id="p693816405205"><a name="p693816405205"></a><a name="p693816405205"></a>The file name is too long.</p>
</td>
</tr>
<tr id="row13938140102013"><td class="cellrowborder" valign="top" width="18.87811218878112%" headers="mcps1.1.5.1.1 "><p id="p293894022010"><a name="p293894022010"></a><a name="p293894022010"></a>ENOLCK</p>
</td>
<td class="cellrowborder" valign="top" width="8.389161083891612%" headers="mcps1.1.5.1.2 "><p id="p1693854011202"><a name="p1693854011202"></a><a name="p1693854011202"></a>37</p>
</td>
<td class="cellrowborder" valign="top" width="39.156084391560846%" headers="mcps1.1.5.1.3 "><p id="p159381440172017"><a name="p159381440172017"></a><a name="p159381440172017"></a>No record locks available</p>
</td>
<td class="cellrowborder" valign="top" width="33.57664233576642%" headers="mcps1.1.5.1.4 "><p id="p593814400200"><a name="p593814400200"></a><a name="p593814400200"></a>There is no lock available.</p>
</td>
</tr>
<tr id="row2938134012207"><td class="cellrowborder" valign="top" width="18.87811218878112%" headers="mcps1.1.5.1.1 "><p id="p49389409201"><a name="p49389409201"></a><a name="p49389409201"></a>ENOSYS</p>
</td>
<td class="cellrowborder" valign="top" width="8.389161083891612%" headers="mcps1.1.5.1.2 "><p id="p793854032020"><a name="p793854032020"></a><a name="p793854032020"></a>38</p>
</td>
<td class="cellrowborder" valign="top" width="39.156084391560846%" headers="mcps1.1.5.1.3 "><p id="p11938144014202"><a name="p11938144014202"></a><a name="p11938144014202"></a>Function not implemented</p>
</td>
<td class="cellrowborder" valign="top" width="33.57664233576642%" headers="mcps1.1.5.1.4 "><p id="p119385407204"><a name="p119385407204"></a><a name="p119385407204"></a>The function is not implemented.</p>
</td>
</tr>
<tr id="row793884014206"><td class="cellrowborder" valign="top" width="18.87811218878112%" headers="mcps1.1.5.1.1 "><p id="p79381440152011"><a name="p79381440152011"></a><a name="p79381440152011"></a>ENOTEMPTY</p>
</td>
<td class="cellrowborder" valign="top" width="8.389161083891612%" headers="mcps1.1.5.1.2 "><p id="p1193913402204"><a name="p1193913402204"></a><a name="p1193913402204"></a>39</p>
</td>
<td class="cellrowborder" valign="top" width="39.156084391560846%" headers="mcps1.1.5.1.3 "><p id="p1793914022012"><a name="p1793914022012"></a><a name="p1793914022012"></a>Directory not empty</p>
</td>
<td class="cellrowborder" valign="top" width="33.57664233576642%" headers="mcps1.1.5.1.4 "><p id="p2939640102011"><a name="p2939640102011"></a><a name="p2939640102011"></a>The directory is not empty.</p>
</td>
</tr>
<tr id="row99391740132015"><td class="cellrowborder" valign="top" width="18.87811218878112%" headers="mcps1.1.5.1.1 "><p id="p7939114092019"><a name="p7939114092019"></a><a name="p7939114092019"></a>ELOOP</p>
</td>
<td class="cellrowborder" valign="top" width="8.389161083891612%" headers="mcps1.1.5.1.2 "><p id="p0939154052014"><a name="p0939154052014"></a><a name="p0939154052014"></a>40</p>
</td>
<td class="cellrowborder" valign="top" width="39.156084391560846%" headers="mcps1.1.5.1.3 "><p id="p39391140192013"><a name="p39391140192013"></a><a name="p39391140192013"></a>Too many symbolic links encountered</p>
</td>
<td class="cellrowborder" valign="top" width="33.57664233576642%" headers="mcps1.1.5.1.4 "><p id="p893914002015"><a name="p893914002015"></a><a name="p893914002015"></a>There are too many symbolic link layers.</p>
</td>
</tr>
<tr id="row1293914014205"><td class="cellrowborder" valign="top" width="18.87811218878112%" headers="mcps1.1.5.1.1 "><p id="p993984020209"><a name="p993984020209"></a><a name="p993984020209"></a>ENOMSG</p>
</td>
<td class="cellrowborder" valign="top" width="8.389161083891612%" headers="mcps1.1.5.1.2 "><p id="p99401240132020"><a name="p99401240132020"></a><a name="p99401240132020"></a>42</p>
</td>
<td class="cellrowborder" valign="top" width="39.156084391560846%" headers="mcps1.1.5.1.3 "><p id="p6940104012203"><a name="p6940104012203"></a><a name="p6940104012203"></a>No message of desired type</p>
</td>
<td class="cellrowborder" valign="top" width="33.57664233576642%" headers="mcps1.1.5.1.4 "><p id="p2094044014203"><a name="p2094044014203"></a><a name="p2094044014203"></a>There is no message of the expected type.</p>
</td>
</tr>
<tr id="row29401240102017"><td class="cellrowborder" valign="top" width="18.87811218878112%" headers="mcps1.1.5.1.1 "><p id="p294034010207"><a name="p294034010207"></a><a name="p294034010207"></a>EIDRM</p>
</td>
<td class="cellrowborder" valign="top" width="8.389161083891612%" headers="mcps1.1.5.1.2 "><p id="p209401040172014"><a name="p209401040172014"></a><a name="p209401040172014"></a>43</p>
</td>
<td class="cellrowborder" valign="top" width="39.156084391560846%" headers="mcps1.1.5.1.3 "><p id="p10940540142018"><a name="p10940540142018"></a><a name="p10940540142018"></a>Identifier removed</p>
</td>
<td class="cellrowborder" valign="top" width="33.57664233576642%" headers="mcps1.1.5.1.4 "><p id="p169401740142011"><a name="p169401740142011"></a><a name="p169401740142011"></a>The identifier is removed. </p>
</td>
</tr>
<tr id="row139436408209"><td class="cellrowborder" valign="top" width="18.87811218878112%" headers="mcps1.1.5.1.1 "><p id="p1694318401206"><a name="p1694318401206"></a><a name="p1694318401206"></a>ELNRNG</p>
</td>
<td class="cellrowborder" valign="top" width="8.389161083891612%" headers="mcps1.1.5.1.2 "><p id="p494364022013"><a name="p494364022013"></a><a name="p494364022013"></a>48</p>
</td>
<td class="cellrowborder" valign="top" width="39.156084391560846%" headers="mcps1.1.5.1.3 "><p id="p69431040132015"><a name="p69431040132015"></a><a name="p69431040132015"></a>Link number out of range</p>
</td>
<td class="cellrowborder" valign="top" width="33.57664233576642%" headers="mcps1.1.5.1.4 "><p id="p594374014204"><a name="p594374014204"></a><a name="p594374014204"></a>The number of links exceeds the limit.</p>
</td>
</tr>
<tr id="row134843121315"><td class="cellrowborder" valign="top" width="18.87811218878112%" headers="mcps1.1.5.1.1 "><p id="p14184391312"><a name="p14184391312"></a><a name="p14184391312"></a>EBADR</p>
</td>
<td class="cellrowborder" valign="top" width="8.389161083891612%" headers="mcps1.1.5.1.2 "><p id="p54164319138"><a name="p54164319138"></a><a name="p54164319138"></a>53</p>
</td>
<td class="cellrowborder" valign="top" width="39.156084391560846%" headers="mcps1.1.5.1.3 "><p id="p54164341316"><a name="p54164341316"></a><a name="p54164341316"></a>Invalid request descriptor</p>
</td>
<td class="cellrowborder" valign="top" width="33.57664233576642%" headers="mcps1.1.5.1.4 "><p id="p8474310134"><a name="p8474310134"></a><a name="p8474310134"></a>The requested descriptor is invalid.</p>
</td>
</tr>
<tr id="row05164312134"><td class="cellrowborder" valign="top" width="18.87811218878112%" headers="mcps1.1.5.1.1 "><p id="p155184341315"><a name="p155184341315"></a><a name="p155184341315"></a>EBADRQC</p>
</td>
<td class="cellrowborder" valign="top" width="8.389161083891612%" headers="mcps1.1.5.1.2 "><p id="p13516437131"><a name="p13516437131"></a><a name="p13516437131"></a>56</p>
</td>
<td class="cellrowborder" valign="top" width="39.156084391560846%" headers="mcps1.1.5.1.3 "><p id="p11520433131"><a name="p11520433131"></a><a name="p11520433131"></a>Invalid request code</p>
</td>
<td class="cellrowborder" valign="top" width="33.57664233576642%" headers="mcps1.1.5.1.4 "><p id="p7517431132"><a name="p7517431132"></a><a name="p7517431132"></a>The requested code is invalid.</p>
</td>
</tr>
<tr id="row117194315132"><td class="cellrowborder" valign="top" width="18.87811218878112%" headers="mcps1.1.5.1.1 "><p id="p471343101310"><a name="p471343101310"></a><a name="p471343101310"></a>ENOSTR</p>
</td>
<td class="cellrowborder" valign="top" width="8.389161083891612%" headers="mcps1.1.5.1.2 "><p id="p4754311132"><a name="p4754311132"></a><a name="p4754311132"></a>60</p>
</td>
<td class="cellrowborder" valign="top" width="39.156084391560846%" headers="mcps1.1.5.1.3 "><p id="p19724331315"><a name="p19724331315"></a><a name="p19724331315"></a>Device not a stream</p>
</td>
<td class="cellrowborder" valign="top" width="33.57664233576642%" headers="mcps1.1.5.1.4 "><p id="p147943181312"><a name="p147943181312"></a><a name="p147943181312"></a>The device is not a character stream.</p>
</td>
</tr>
<tr id="row157343101319"><td class="cellrowborder" valign="top" width="18.87811218878112%" headers="mcps1.1.5.1.1 "><p id="p18812437137"><a name="p18812437137"></a><a name="p18812437137"></a>ENODATA</p>
</td>
<td class="cellrowborder" valign="top" width="8.389161083891612%" headers="mcps1.1.5.1.2 "><p id="p986435132"><a name="p986435132"></a><a name="p986435132"></a>61</p>
</td>
<td class="cellrowborder" valign="top" width="39.156084391560846%" headers="mcps1.1.5.1.3 "><p id="p38643181312"><a name="p38643181312"></a><a name="p38643181312"></a>No data available</p>
</td>
<td class="cellrowborder" valign="top" width="33.57664233576642%" headers="mcps1.1.5.1.4 "><p id="p88164321314"><a name="p88164321314"></a><a name="p88164321314"></a>No data is available.</p>
</td>
</tr>
<tr id="row1381443191315"><td class="cellrowborder" valign="top" width="18.87811218878112%" headers="mcps1.1.5.1.1 "><p id="p1587439138"><a name="p1587439138"></a><a name="p1587439138"></a>ETIME</p>
</td>
<td class="cellrowborder" valign="top" width="8.389161083891612%" headers="mcps1.1.5.1.2 "><p id="p58343101315"><a name="p58343101315"></a><a name="p58343101315"></a>62</p>
</td>
<td class="cellrowborder" valign="top" width="39.156084391560846%" headers="mcps1.1.5.1.3 "><p id="p98194371314"><a name="p98194371314"></a><a name="p98194371314"></a>Timer expired</p>
</td>
<td class="cellrowborder" valign="top" width="33.57664233576642%" headers="mcps1.1.5.1.4 "><p id="p1881543131310"><a name="p1881543131310"></a><a name="p1881543131310"></a>The timer has expired.</p>
</td>
</tr>
<tr id="row1911184321313"><td class="cellrowborder" valign="top" width="18.87811218878112%" headers="mcps1.1.5.1.1 "><p id="p19117436135"><a name="p19117436135"></a><a name="p19117436135"></a>EPROTO</p>
</td>
<td class="cellrowborder" valign="top" width="8.389161083891612%" headers="mcps1.1.5.1.2 "><p id="p2111743101319"><a name="p2111743101319"></a><a name="p2111743101319"></a>71</p>
</td>
<td class="cellrowborder" valign="top" width="39.156084391560846%" headers="mcps1.1.5.1.3 "><p id="p111144312132"><a name="p111144312132"></a><a name="p111144312132"></a>Protocol error</p>
</td>
<td class="cellrowborder" valign="top" width="33.57664233576642%" headers="mcps1.1.5.1.4 "><p id="p111194331317"><a name="p111194331317"></a><a name="p111194331317"></a>Protocol error.</p>
</td>
</tr>
<tr id="row712184319136"><td class="cellrowborder" valign="top" width="18.87811218878112%" headers="mcps1.1.5.1.1 "><p id="p31211436132"><a name="p31211436132"></a><a name="p31211436132"></a>EBADMSG</p>
</td>
<td class="cellrowborder" valign="top" width="8.389161083891612%" headers="mcps1.1.5.1.2 "><p id="p1712164319132"><a name="p1712164319132"></a><a name="p1712164319132"></a>74</p>
</td>
<td class="cellrowborder" valign="top" width="39.156084391560846%" headers="mcps1.1.5.1.3 "><p id="p2126438135"><a name="p2126438135"></a><a name="p2126438135"></a>Not a data message</p>
</td>
<td class="cellrowborder" valign="top" width="33.57664233576642%" headers="mcps1.1.5.1.4 "><p id="p11284331314"><a name="p11284331314"></a><a name="p11284331314"></a>It is not a data message.</p>
</td>
</tr>
<tr id="row712174361312"><td class="cellrowborder" valign="top" width="18.87811218878112%" headers="mcps1.1.5.1.1 "><p id="p41384316136"><a name="p41384316136"></a><a name="p41384316136"></a>EOVERFLOW</p>
</td>
<td class="cellrowborder" valign="top" width="8.389161083891612%" headers="mcps1.1.5.1.2 "><p id="p19131443181319"><a name="p19131443181319"></a><a name="p19131443181319"></a>75</p>
</td>
<td class="cellrowborder" valign="top" width="39.156084391560846%" headers="mcps1.1.5.1.3 "><p id="p161334341317"><a name="p161334341317"></a><a name="p161334341317"></a>Value too large for defined data type</p>
</td>
<td class="cellrowborder" valign="top" width="33.57664233576642%" headers="mcps1.1.5.1.4 "><p id="p9132043151316"><a name="p9132043151316"></a><a name="p9132043151316"></a>The value is too large for the data type.</p>
</td>
</tr>
<tr id="row61784351317"><td class="cellrowborder" valign="top" width="18.87811218878112%" headers="mcps1.1.5.1.1 "><p id="p017174351318"><a name="p017174351318"></a><a name="p017174351318"></a>EMSGSIZE</p>
</td>
<td class="cellrowborder" valign="top" width="8.389161083891612%" headers="mcps1.1.5.1.2 "><p id="p81714435138"><a name="p81714435138"></a><a name="p81714435138"></a>90</p>
</td>
<td class="cellrowborder" valign="top" width="39.156084391560846%" headers="mcps1.1.5.1.3 "><p id="p121794331317"><a name="p121794331317"></a><a name="p121794331317"></a>Message too long</p>
</td>
<td class="cellrowborder" valign="top" width="33.57664233576642%" headers="mcps1.1.5.1.4 "><p id="p91718438133"><a name="p91718438133"></a><a name="p91718438133"></a>The message is too long.</p>
</td>
</tr>
</tbody>
</table>

### Development Example<a name="section206149278155"></a>

Demo:

Creates a thread, transfers the information in the parent thread to the child thread, and prints the transferred information and the thread ID in the child thread.

```
#include <stdio.h>
#include <pthread.h>

pthread_t ntid;

void *ThreadFn(void *arg)
{
    pthread_t tid;
    while(1) {
        tid = pthread_self();
        printf("\n++++++++++++++  %s  %s  tid = %d ++++++++++++++\n", (char*)arg, __FUNCTION__, tid);
    }
    return ((void *)0);
}

void DemoForTest()
{
    int err;
    char* str = "Hello world";
    err = pthread_create(&ntid, NULL, ThreadFn, (void*)str);
    if(err != 0) {
        printf("can't create thread\n");
    }
}

```

The execution result of  **DemoForTest**  is as follows:

```
++++++++++++++  Hello world  ThreadFn  tid = 48 ++++++++++++++

++++++++++++++  Hello world  ThreadFn  tid = 48 ++++++++++++++

++++++++++++++  Hello world  ThreadFn  tid = 48 ++++++++++++++
```

