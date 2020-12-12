# \_\_ucontext<a name="EN-US_TOPIC_0000001055039560"></a>

-   [Overview](#section1736534574165636)
-   [Summary](#section1372466770165636)
-   [Data Fields](#pub-attribs)
-   [Details](#section56269389165636)
-   [Field](#section241535797165636)
-   [uc\_flags](#a37d6c2fd659ca179dac3b3e201caf721)
-   [uc\_link](#ac959c5e5cf5dc08fe790c048f7c7f802)
-   [uc\_mcontext](#a7b1df7352cb1f09948bcfa9af895eac1)
-   [uc\_regspace](#a93ddd393e196ec5f6c436e3179c5d19c)
-   [uc\_sigmask](#a2edf70532d013389f4362252f749f14c)
-   [uc\_stack](#ad53e410e77eb4014fffad71484aee872)

## **Overview**<a name="section1736534574165636"></a>

**Related Modules:**

[IPC](ipc.md)

**Description:**

Describes the user execution context. 

## **Summary**<a name="section1372466770165636"></a>

## Data Fields<a name="pub-attribs"></a>

<a name="table232045278165636"></a>
<table><thead align="left"><tr id="row21826321165636"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1997409400165636"><a name="p1997409400165636"></a><a name="p1997409400165636"></a>Variable Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1705651048165636"><a name="p1705651048165636"></a><a name="p1705651048165636"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1875554545165636"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1025151437165636"><a name="p1025151437165636"></a><a name="p1025151437165636"></a><a href="__ucontext.md#a37d6c2fd659ca179dac3b3e201caf721">uc_flags</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p707183978165636"><a name="p707183978165636"></a><a name="p707183978165636"></a>unsigned long </p>
</td>
</tr>
<tr id="row723901237165636"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p703627967165636"><a name="p703627967165636"></a><a name="p703627967165636"></a><a href="__ucontext.md#ac959c5e5cf5dc08fe790c048f7c7f802">uc_link</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1967362939165636"><a name="p1967362939165636"></a><a name="p1967362939165636"></a>struct <a href="__ucontext.md">__ucontext</a> * </p>
</td>
</tr>
<tr id="row396220309165636"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p628043763165636"><a name="p628043763165636"></a><a name="p628043763165636"></a><a href="__ucontext.md#ad53e410e77eb4014fffad71484aee872">uc_stack</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1783772085165636"><a name="p1783772085165636"></a><a name="p1783772085165636"></a>stack_t </p>
</td>
</tr>
<tr id="row1363185738165636"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1748586909165636"><a name="p1748586909165636"></a><a name="p1748586909165636"></a><a href="__ucontext.md#a7b1df7352cb1f09948bcfa9af895eac1">uc_mcontext</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1943818969165636"><a name="p1943818969165636"></a><a name="p1943818969165636"></a>mcontext_t </p>
</td>
</tr>
<tr id="row516814973165636"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p74494066165636"><a name="p74494066165636"></a><a name="p74494066165636"></a><a href="__ucontext.md#a2edf70532d013389f4362252f749f14c">uc_sigmask</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p949416012165636"><a name="p949416012165636"></a><a name="p949416012165636"></a>sigset_t </p>
</td>
</tr>
<tr id="row831876732165636"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p651401277165636"><a name="p651401277165636"></a><a name="p651401277165636"></a><a href="__ucontext.md#a93ddd393e196ec5f6c436e3179c5d19c">uc_regspace</a> [64]</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p268948616165636"><a name="p268948616165636"></a><a name="p268948616165636"></a>unsigned long long </p>
</td>
</tr>
</tbody>
</table>

## **Details**<a name="section56269389165636"></a>

## **Field **<a name="section241535797165636"></a>

## uc\_flags<a name="a37d6c2fd659ca179dac3b3e201caf721"></a>

```
unsigned long __ucontext::uc_flags
```

 **Description:**

Flag 

## uc\_link<a name="ac959c5e5cf5dc08fe790c048f7c7f802"></a>

```
struct [__ucontext](__ucontext.md)* __ucontext::uc_link
```

 **Description:**

Context linked-list 

## uc\_mcontext<a name="a7b1df7352cb1f09948bcfa9af895eac1"></a>

```
mcontext_t __ucontext::uc_mcontext
```

 **Description:**

Related signal context 

## uc\_regspace<a name="a93ddd393e196ec5f6c436e3179c5d19c"></a>

```
unsigned long long __ucontext::uc_regspace[64]
```

 **Description:**

User register space 

## uc\_sigmask<a name="a2edf70532d013389f4362252f749f14c"></a>

```
sigset_t __ucontext::uc_sigmask
```

 **Description:**

User signal mask 

## uc\_stack<a name="ad53e410e77eb4014fffad71484aee872"></a>

```
stack_t __ucontext::uc_stack
```

 **Description:**

User stack 

