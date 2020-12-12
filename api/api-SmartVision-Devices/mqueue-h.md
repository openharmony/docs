# mqueue.h<a name="ZH-CN_TOPIC_0000001055707980"></a>

-   [Overview](#section1491034778165628)
-   [Summary](#section636051123165628)
-   [Data Structures](#nested-classes)
-   [Typedefs](#typedef-members)
-   [Functions](#func-members)

## **Overview**<a name="section1491034778165628"></a>

**Related Modules:**

[IPC](IPC.md)

**Description:**

Provides message queue operation functions and related structures. 

For example, you can use the functions to create, open, close, delete, read, and write a message queue, and to obtain and set its attributes.

**Since:**

1.0

**Version:**

1.0

## **Summary**<a name="section636051123165628"></a>

## Data Structures<a name="nested-classes"></a>

<a name="table2100401365165628"></a>
<table><thead align="left"><tr id="row1047184059165628"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1384415785165628"><a name="p1384415785165628"></a><a name="p1384415785165628"></a>Data Structure Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p439596399165628"><a name="p439596399165628"></a><a name="p439596399165628"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1064103480165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1392905226165628"><a name="p1392905226165628"></a><a name="p1392905226165628"></a><a href="mq_attr.md">mq_attr</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2144928861165628"><a name="p2144928861165628"></a><a name="p2144928861165628"></a>Describes message queue attributes. </p>
</td>
</tr>
</tbody>
</table>

## Typedefs<a name="typedef-members"></a>

<a name="table1970830954165628"></a>
<table><thead align="left"><tr id="row194137190165628"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p2011712715165628"><a name="p2011712715165628"></a><a name="p2011712715165628"></a>Typedef Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p540641268165628"><a name="p540641268165628"></a><a name="p540641268165628"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1223451664165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p566782475165628"><a name="p566782475165628"></a><a name="p566782475165628"></a><a href="IPC.md#ga4820b065fbcbb30569e78e64ef5ad809">mqd_t</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p297097593165628"><a name="p297097593165628"></a><a name="p297097593165628"></a> typedef int </p>
<p id="p63535455165628"><a name="p63535455165628"></a><a name="p63535455165628"></a>Represents the data type of a message queue. </p>
</td>
</tr>
</tbody>
</table>

## Functions<a name="func-members"></a>

<a name="table299348251165628"></a>
<table><thead align="left"><tr id="row1684732811165628"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1327396842165628"><a name="p1327396842165628"></a><a name="p1327396842165628"></a>Function</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p457659305165628"><a name="p457659305165628"></a><a name="p457659305165628"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1021530365165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1812154826165628"><a name="p1812154826165628"></a><a name="p1812154826165628"></a><a href="IPC.md#ga3fbd3906296be63451c64d69be2bc371">mq_close</a> (<a href="IPC.md#ga4820b065fbcbb30569e78e64ef5ad809">mqd_t</a> mqdes)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1288054161165628"><a name="p1288054161165628"></a><a name="p1288054161165628"></a>int </p>
<p id="p945222396165628"><a name="p945222396165628"></a><a name="p945222396165628"></a>Closes a message queue that is no longer used. </p>
</td>
</tr>
<tr id="row1309653656165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p362282286165628"><a name="p362282286165628"></a><a name="p362282286165628"></a><a href="IPC.md#ga8fafe8b1183830322f8ff875f4e6cb4c">mq_getattr</a> (<a href="IPC.md#ga4820b065fbcbb30569e78e64ef5ad809">mqd_t</a> mqdes, struct <a href="mq_attr.md">mq_attr</a> *attr)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p95915196165628"><a name="p95915196165628"></a><a name="p95915196165628"></a>int </p>
<p id="p1788990053165628"><a name="p1788990053165628"></a><a name="p1788990053165628"></a>Obtains the attributes of the message queue specified by the descriptor. The values of <strong id="b1301883766165628"><a name="b1301883766165628"></a><a name="b1301883766165628"></a>mq_maxmsg</strong>, <strong id="b484286674165628"><a name="b484286674165628"></a><a name="b484286674165628"></a>mq_msgsize</strong>, and <strong id="b1254293583165628"><a name="b1254293583165628"></a><a name="b1254293583165628"></a>mq_curmsgs</strong> are fixed. </p>
</td>
</tr>
<tr id="row1305902537165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1808792083165628"><a name="p1808792083165628"></a><a name="p1808792083165628"></a><a href="IPC.md#gaf5d8bf423701bd1783849119511381a5">mq_open</a> (const char *name, int oflag,...)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p22499932165628"><a name="p22499932165628"></a><a name="p22499932165628"></a><a href="IPC.md#ga4820b065fbcbb30569e78e64ef5ad809">mqd_t</a> </p>
<p id="p1911639915165628"><a name="p1911639915165628"></a><a name="p1911639915165628"></a>Creates a message queue or opens an existing message queue. </p>
</td>
</tr>
<tr id="row1693301157165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p749613674165628"><a name="p749613674165628"></a><a name="p749613674165628"></a><a href="IPC.md#gafcd715bf914289ca502136ef7022eab7">mq_receive</a> (<a href="IPC.md#ga4820b065fbcbb30569e78e64ef5ad809">mqd_t</a> mqdes, char *buffer, size_t size, unsigned *prioptr)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1353939611165628"><a name="p1353939611165628"></a><a name="p1353939611165628"></a>ssize_t </p>
<p id="p526149870165628"><a name="p526149870165628"></a><a name="p526149870165628"></a>Receives a message from a specified message queue. </p>
</td>
</tr>
<tr id="row1605540558165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p637599648165628"><a name="p637599648165628"></a><a name="p637599648165628"></a><a href="IPC.md#ga2d07e256d809a61bdc82178cb0dd1ba1">mq_send</a> (<a href="IPC.md#ga4820b065fbcbb30569e78e64ef5ad809">mqd_t</a> mqdes, const char *buffer, size_t size, unsigned prio)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p965934303165628"><a name="p965934303165628"></a><a name="p965934303165628"></a>int </p>
<p id="p27152942165628"><a name="p27152942165628"></a><a name="p27152942165628"></a>Sends a message to a specified message queue. </p>
</td>
</tr>
<tr id="row1454942468165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p428083465165628"><a name="p428083465165628"></a><a name="p428083465165628"></a><a href="IPC.md#gaf5cc07adf7823fac8611200b55fc3a27">mq_setattr</a> (<a href="IPC.md#ga4820b065fbcbb30569e78e64ef5ad809">mqd_t</a> mqdes, const struct <a href="mq_attr.md">mq_attr</a> *__restrict newattr, struct <a href="mq_attr.md">mq_attr</a> *__restrict oldattr)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p949561898165628"><a name="p949561898165628"></a><a name="p949561898165628"></a>int </p>
<p id="p762803739165628"><a name="p762803739165628"></a><a name="p762803739165628"></a>Sets the attributes of the message queue specified by the descriptor. The <strong id="b1121550602165628"><a name="b1121550602165628"></a><a name="b1121550602165628"></a>mq_maxmsg</strong>, <strong id="b1392606765165628"><a name="b1392606765165628"></a><a name="b1392606765165628"></a>mq_msgsize</strong>, and <strong id="b1084812696165628"><a name="b1084812696165628"></a><a name="b1084812696165628"></a>mq_curmsgs</strong> attributes cannot be modified. <strong id="b2094652801165628"><a name="b2094652801165628"></a><a name="b2094652801165628"></a>mq_flags</strong> supports the <strong id="b1882172352165628"><a name="b1882172352165628"></a><a name="b1882172352165628"></a>O_NONBLOCK</strong> attribute only. </p>
</td>
</tr>
<tr id="row2006146875165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2062241187165628"><a name="p2062241187165628"></a><a name="p2062241187165628"></a><a href="IPC.md#gaa291cc1bc8bb02fd24bd0d4c563350f4">mq_timedreceive</a> (<a href="IPC.md#ga4820b065fbcbb30569e78e64ef5ad809">mqd_t</a> mqdes, char *__restrict buffer, size_t size, unsigned *__restrict prioptr, const struct <a href="timespec.md">timespec</a> *__restrict timeout)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1872506426165628"><a name="p1872506426165628"></a><a name="p1872506426165628"></a>ssize_t </p>
<p id="p132221054165628"><a name="p132221054165628"></a><a name="p132221054165628"></a>Receives a message from the message queue, with a timeout period specified. </p>
</td>
</tr>
<tr id="row2124356571165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1994658936165628"><a name="p1994658936165628"></a><a name="p1994658936165628"></a><a href="IPC.md#gae59709d01cc34d009edfeae9900568cb">mq_timedsend</a> (<a href="IPC.md#ga4820b065fbcbb30569e78e64ef5ad809">mqd_t</a> mqdes, const char *buffer, size_t size, unsigned prio, const struct <a href="timespec.md">timespec</a> *timeout)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1595931843165628"><a name="p1595931843165628"></a><a name="p1595931843165628"></a>int </p>
<p id="p3618479165628"><a name="p3618479165628"></a><a name="p3618479165628"></a>Sends a message to a specified message queue, with a timeout period specified. </p>
</td>
</tr>
<tr id="row987982389165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p44425642165628"><a name="p44425642165628"></a><a name="p44425642165628"></a><a href="IPC.md#gaccd8c5ee36e60d990963e1d544ef4140">mq_unlink</a> (const char *name)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1733470881165628"><a name="p1733470881165628"></a><a name="p1733470881165628"></a>int </p>
<p id="p82884973165628"><a name="p82884973165628"></a><a name="p82884973165628"></a>Decreases the reference count of the message queue by 1, or deletes the message queue if the reference count is <strong id="b1084221323165628"><a name="b1084221323165628"></a><a name="b1084221323165628"></a>0</strong>. </p>
</td>
</tr>
</tbody>
</table>

