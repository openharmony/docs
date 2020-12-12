# sigaction<a name="ZH-CN_TOPIC_0000001055078187"></a>

-   [Overview](#section846255415165637)
-   [Summary](#section1341923691165637)
-   [Data Fields](#pub-attribs)
-   [Details](#section1183745973165637)
-   [Field](#section1610859264165637)
-   [sa\_flags](#aea0dabe7a03641c8b426521f4406b425)
-   [sa\_handler](#aff7f084aa4099423967033151cec9474)
-   [sa\_mask](#a684e70081d03d46ce70af097ea5cfd49)
-   [sa\_sigaction](#a0bb0cfd311dfcc20aac020e7d3792b1a)

## **Overview**<a name="section846255415165637"></a>

**Related Modules:**

[IPC](IPC.md)

**Description:**

Describes the signal processing actions and related attributes. 

## **Summary**<a name="section1341923691165637"></a>

## Data Fields<a name="pub-attribs"></a>

<a name="table1589457905165637"></a>
<table><thead align="left"><tr id="row1809288714165637"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p197603141165637"><a name="p197603141165637"></a><a name="p197603141165637"></a>Variable Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1011029941165637"><a name="p1011029941165637"></a><a name="p1011029941165637"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1525597911165637"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p364924523165637"><a name="p364924523165637"></a><a name="p364924523165637"></a><a href="sigaction.md#a684e70081d03d46ce70af097ea5cfd49">sa_mask</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1364754494165637"><a name="p1364754494165637"></a><a name="p1364754494165637"></a>sigset_t </p>
</td>
</tr>
<tr id="row1478532409165637"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1784380752165637"><a name="p1784380752165637"></a><a name="p1784380752165637"></a><a href="sigaction.md#aea0dabe7a03641c8b426521f4406b425">sa_flags</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2116595989165637"><a name="p2116595989165637"></a><a name="p2116595989165637"></a>int </p>
</td>
</tr>
<tr id="row242765109165637"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1038181352165637"><a name="p1038181352165637"></a><a name="p1038181352165637"></a><a href="sigaction.md#aff7f084aa4099423967033151cec9474">sa_handler</a> )(int)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p16687296165637"><a name="p16687296165637"></a><a name="p16687296165637"></a>void(* </p>
</td>
</tr>
<tr id="row225547243165637"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1962148647165637"><a name="p1962148647165637"></a><a name="p1962148647165637"></a><a href="sigaction.md#a0bb0cfd311dfcc20aac020e7d3792b1a">sa_sigaction</a> )(int, siginfo_t *, void *)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1089689876165637"><a name="p1089689876165637"></a><a name="p1089689876165637"></a>void(* </p>
</td>
</tr>
</tbody>
</table>

## **Details**<a name="section1183745973165637"></a>

## **Field **<a name="section1610859264165637"></a>

## sa\_flags<a name="aea0dabe7a03641c8b426521f4406b425"></a>

```
int sigaction::sa_flags
```

 **Description:**

Signal flag, which is not supported 

## sa\_handler<a name="aff7f084aa4099423967033151cec9474"></a>

```
void(* sigaction::sa_handler) (int)
```

 **Description:**

Signal callback function type and callback for the processing action 

## sa\_mask<a name="a684e70081d03d46ce70af097ea5cfd49"></a>

```
sigset_t sigaction::sa_mask
```

 **Description:**

Signal to be masked 

## sa\_sigaction<a name="a0bb0cfd311dfcc20aac020e7d3792b1a"></a>

```
void(* sigaction::sa_sigaction) (int, siginfo_t *, void *)
```

 **Description:**

Signal callback function type, which is not supported 

