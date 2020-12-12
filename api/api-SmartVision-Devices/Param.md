# Param<a name="ZH-CN_TOPIC_0000001054718161"></a>

-   [Overview](#section1918344634165635)
-   [Summary](#section1254589222165635)
-   [Data Fields](#pub-attribs)
-   [Details](#section990879802165635)
-   [Field](#section745735996165635)
-   [key](#ace6f19effda894bc68afd60d5425a4a8)
-   [size](#a4f68079ff933352feeef5364436bc402)
-   [val](#a375689df3cbcede96a3fb20ab6e0a086)

## **Overview**<a name="section1918344634165635"></a>

**Related Modules:**

[Codec](Codec.md)

**Description:**

Describes the dynamic parameter structure, which is mainly used by  [CodecCreate](Codec.md#ga74aa0395a51f004390f7a92fb68faddd)  and  [CodecSetParameter](Codec.md#gaa080cf23aa5f77b30f3b90a026d97cc0). 

## **Summary**<a name="section1254589222165635"></a>

## Data Fields<a name="pub-attribs"></a>

<a name="table949182134165635"></a>
<table><thead align="left"><tr id="row1112009114165635"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1363026838165635"><a name="p1363026838165635"></a><a name="p1363026838165635"></a>Variable Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1323027780165635"><a name="p1323027780165635"></a><a name="p1323027780165635"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row581812498165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p391962496165635"><a name="p391962496165635"></a><a name="p391962496165635"></a><a href="Param.md#ace6f19effda894bc68afd60d5425a4a8">key</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p563985887165635"><a name="p563985887165635"></a><a name="p563985887165635"></a><a href="Codec.md#ga575c56a2d6b42c48881cf47b0008d5a6">ParamKey</a> </p>
</td>
</tr>
<tr id="row1486768283165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p553797008165635"><a name="p553797008165635"></a><a name="p553797008165635"></a><a href="Param.md#a375689df3cbcede96a3fb20ab6e0a086">val</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1768374466165635"><a name="p1768374466165635"></a><a name="p1768374466165635"></a>void * </p>
</td>
</tr>
<tr id="row1104252123165635"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p495988895165635"><a name="p495988895165635"></a><a name="p495988895165635"></a><a href="Param.md#a4f68079ff933352feeef5364436bc402">size</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p568194776165635"><a name="p568194776165635"></a><a name="p568194776165635"></a>int </p>
</td>
</tr>
</tbody>
</table>

## **Details**<a name="section990879802165635"></a>

## **Field **<a name="section745735996165635"></a>

## key<a name="ace6f19effda894bc68afd60d5425a4a8"></a>

```
[ParamKey](Codec.md#ga575c56a2d6b42c48881cf47b0008d5a6) Param::key
```

 **Description:**

Parameter type index 

## size<a name="a4f68079ff933352feeef5364436bc402"></a>

```
int Param::size
```

 **Description:**

Parameter value size 

## val<a name="a375689df3cbcede96a3fb20ab6e0a086"></a>

```
void* Param::val
```

 **Description:**

Pointer to the parameter value 

