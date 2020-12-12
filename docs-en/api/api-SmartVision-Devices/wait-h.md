# wait.h<a name="EN-US_TOPIC_0000001055308041"></a>

-   [Overview](#section683276346165630)
-   [Summary](#section1628212685165630)
-   [Functions](#func-members)

## **Overview**<a name="section683276346165630"></a>

**Related Modules:**

[PROCESS](process.md)

**Description:**

Provides process- and thread-related structures and functions \(for example, waiting for child processes to end and reclaiming resources\). 

**Since:**

1.0

**Version:**

1.0

## **Summary**<a name="section1628212685165630"></a>

## Functions<a name="func-members"></a>

<a name="table2112128782165630"></a>
<table><thead align="left"><tr id="row138460123165630"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1092729563165630"><a name="p1092729563165630"></a><a name="p1092729563165630"></a>Function</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p845995664165630"><a name="p845995664165630"></a><a name="p845995664165630"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1817563872165630"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2086784958165630"><a name="p2086784958165630"></a><a name="p2086784958165630"></a><a href="process.md#gabf2fbcf6df59fd5234e9eed4db1a1804">wait</a> (int *status)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1611549543165630"><a name="p1611549543165630"></a><a name="p1611549543165630"></a><a href="utils.md#ga30c34d3eead853c44f459f21b932984c">pid_t</a> </p>
<p id="p1350155430165630"><a name="p1350155430165630"></a><a name="p1350155430165630"></a>Waits for any child process to end and reclaims its resources. </p>
</td>
</tr>
<tr id="row1916443349165630"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1495535475165630"><a name="p1495535475165630"></a><a name="p1495535475165630"></a><a href="process.md#ga77de8005691d1f125540d66032a3cc62">waitpid</a> (<a href="utils.md#ga30c34d3eead853c44f459f21b932984c">pid_t</a> pid, int *status, int options)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p88798753165630"><a name="p88798753165630"></a><a name="p88798753165630"></a><a href="utils.md#ga30c34d3eead853c44f459f21b932984c">pid_t</a> </p>
<p id="p70173539165630"><a name="p70173539165630"></a><a name="p70173539165630"></a>Waits for a specified child process to end and reclaims its resources. </p>
</td>
</tr>
</tbody>
</table>

