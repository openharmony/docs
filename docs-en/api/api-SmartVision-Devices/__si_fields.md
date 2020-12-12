# \_\_si\_fields<a name="EN-US_TOPIC_0000001054879576"></a>

-   [Overview](#section163186323165636)
-   [Summary](#section561096802165636)
-   [Data Fields](#pub-attribs)
-   [Details](#section946670116165636)
-   [Field](#section1008820208165636)
-   [\_\_piduid](#a0667f2d7854a41064dbb8c4cc0085644)
-   [\_\_sigchld](#a95d074f2446e4a39e78b0a08d40d463c)
-   [\_\_timer](#a4d43ddf3a64ef29d3174ad051ee8ed72)
-   [char\_\_pad](#af2be33102b7e76235a62db547c89e642)
-   [si\_code](#aea37db23af7a01123e78567c63fea57f)
-   [si\_errno](#ad8322ef52a0a0ec711ccd4e99ed4e8bd)
-   [si\_signo](#a1640d7d62d6bf4e0c6f859348ee15fbf)
-   [si\_value](#abedf932f1bdc181052be44232803d6e1)

## **Overview**<a name="section163186323165636"></a>

**Related Modules:**

[IPC](ipc.md)

**Description:**

Describes signal information. 

## **Summary**<a name="section561096802165636"></a>

## Data Fields<a name="pub-attribs"></a>

<a name="table471320935165636"></a>
<table><thead align="left"><tr id="row1459474591165636"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1156079502165636"><a name="p1156079502165636"></a><a name="p1156079502165636"></a>Variable Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p855689461165636"><a name="p855689461165636"></a><a name="p855689461165636"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row124065984165636"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p269375386165636"><a name="p269375386165636"></a><a name="p269375386165636"></a><a href="__si_fields.md#a1640d7d62d6bf4e0c6f859348ee15fbf">si_signo</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p167687440165636"><a name="p167687440165636"></a><a name="p167687440165636"></a>int </p>
</td>
</tr>
<tr id="row1126797406165636"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p551122997165636"><a name="p551122997165636"></a><a name="p551122997165636"></a><a href="__si_fields.md#ad8322ef52a0a0ec711ccd4e99ed4e8bd">si_errno</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p86541603165636"><a name="p86541603165636"></a><a name="p86541603165636"></a>int </p>
</td>
</tr>
<tr id="row744039039165636"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1509350265165636"><a name="p1509350265165636"></a><a name="p1509350265165636"></a><a href="__si_fields.md#aea37db23af7a01123e78567c63fea57f">si_code</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2061585999165636"><a name="p2061585999165636"></a><a name="p2061585999165636"></a>int </p>
</td>
</tr>
<tr id="row1661509718165636"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p491932051165636"><a name="p491932051165636"></a><a name="p491932051165636"></a><a href="__si_fields.md#af2be33102b7e76235a62db547c89e642">char__pad</a> [128 - 2 *sizeof(int) - sizeof(long)]</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 ">&nbsp;&nbsp;</td>
</tr>
<tr id="row1106160010165636"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">&nbsp;&nbsp;</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2025287563165636"><a name="p2025287563165636"></a><a name="p2025287563165636"></a>struct {</p>
</td>
</tr>
<tr id="row1208041480165636"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1317446564165636"><a name="p1317446564165636"></a><a name="p1317446564165636"></a><a href="__si_fields.md#a0667f2d7854a41064dbb8c4cc0085644">__piduid</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p761930524165636"><a name="p761930524165636"></a><a name="p761930524165636"></a>} </p>
</td>
</tr>
<tr id="row2005960533165636"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">&nbsp;&nbsp;</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p576737936165636"><a name="p576737936165636"></a><a name="p576737936165636"></a>struct {</p>
</td>
</tr>
<tr id="row723085689165636"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p335888042165636"><a name="p335888042165636"></a><a name="p335888042165636"></a><a href="__si_fields.md#a4d43ddf3a64ef29d3174ad051ee8ed72">__timer</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1369440103165636"><a name="p1369440103165636"></a><a name="p1369440103165636"></a>} </p>
</td>
</tr>
<tr id="row645150293165636"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2004000129165636"><a name="p2004000129165636"></a><a name="p2004000129165636"></a><a href="__si_fields.md#abedf932f1bdc181052be44232803d6e1">si_value</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2137743137165636"><a name="p2137743137165636"></a><a name="p2137743137165636"></a>union <a href="sigval.md">sigval</a> </p>
</td>
</tr>
<tr id="row585097899165636"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 ">&nbsp;&nbsp;</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p49703100165636"><a name="p49703100165636"></a><a name="p49703100165636"></a>struct {</p>
</td>
</tr>
<tr id="row1678195030165636"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p36268253165636"><a name="p36268253165636"></a><a name="p36268253165636"></a><a href="__si_fields.md#a95d074f2446e4a39e78b0a08d40d463c">__sigchld</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1730043082165636"><a name="p1730043082165636"></a><a name="p1730043082165636"></a>} </p>
</td>
</tr>
</tbody>
</table>

## **Details**<a name="section946670116165636"></a>

## **Field **<a name="section1008820208165636"></a>

## \_\_piduid<a name="a0667f2d7854a41064dbb8c4cc0085644"></a>

```
struct { ... } __si_fields::__piduid
```

 **Description:**

This structure is not supported. 

## \_\_sigchld<a name="a95d074f2446e4a39e78b0a08d40d463c"></a>

```
struct { ... } __si_fields::__sigchld
```

 **Description:**

This structure is not supported. 

## \_\_timer<a name="a4d43ddf3a64ef29d3174ad051ee8ed72"></a>

```
struct { ... } __si_fields::__timer
```

 **Description:**

This structure is not supported. 

## char\_\_pad<a name="af2be33102b7e76235a62db547c89e642"></a>

```
__si_fields::char__pad[128 - 2 *sizeof(int) - sizeof(long)]
```

 **Description:**

Alignment fields 

## si\_code<a name="aea37db23af7a01123e78567c63fea57f"></a>

```
int __si_fields::si_code
```

 **Description:**

Cause of signal generation, which is not supported currently 

## si\_errno<a name="ad8322ef52a0a0ec711ccd4e99ed4e8bd"></a>

```
int __si_fields::si_errno
```

 **Description:**

Error code, which is not supported currently 

## si\_signo<a name="a1640d7d62d6bf4e0c6f859348ee15fbf"></a>

```
int __si_fields::si_signo
```

 **Description:**

Signal number 

## si\_value<a name="abedf932f1bdc181052be44232803d6e1"></a>

```
union [sigval](sigval.md) __si_fields::si_value
```

 **Description:**

**sival\_int**  in the union is supported. 

