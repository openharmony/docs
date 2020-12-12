# SimpleVector<a name="ZH-CN_TOPIC_0000001054598199"></a>

-   [Overview](#section1250743270165636)
-   [Summary](#section1410137533165636)
-   [Data Fields](#pub-attribs)
-   [Details](#section508538747165636)
-   [Field](#section1604641307165636)
-   [compare](#a7661926c6a5d659ec2bff6533a7389fa)
-   [data](#a4674672209ae411544383a5399aee85b)
-   [free](#a1ff1e71311df432f11fd2613cdbc1b16)
-   [key](#a3e5edc51c8c7ef2536da2853986981ff)
-   [max](#a68140ca4cc59df48c63963f1eda3f35c)
-   [top](#ac699cefa0c1003b8babbe2c0ea3134db)

## **Overview**<a name="section1250743270165636"></a>

**Related Modules:**

[Samgr](Samgr.md)

**Description:**

Defines the simplified vector class, which is extended by four elements. 

This class is applicable to the C language development scenario where the data volume is small and dynamic expansion is required. 

## **Summary**<a name="section1410137533165636"></a>

## Data Fields<a name="pub-attribs"></a>

<a name="table532565867165636"></a>
<table><thead align="left"><tr id="row1769348829165636"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p859026682165636"><a name="p859026682165636"></a><a name="p859026682165636"></a>Variable Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1519850234165636"><a name="p1519850234165636"></a><a name="p1519850234165636"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1727690191165636"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p535271108165636"><a name="p535271108165636"></a><a name="p535271108165636"></a><a href="SimpleVector.md#a68140ca4cc59df48c63963f1eda3f35c">max</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p15273936165636"><a name="p15273936165636"></a><a name="p15273936165636"></a>int16 </p>
</td>
</tr>
<tr id="row1068391600165636"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p200295114165636"><a name="p200295114165636"></a><a name="p200295114165636"></a><a href="SimpleVector.md#ac699cefa0c1003b8babbe2c0ea3134db">top</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p184590736165636"><a name="p184590736165636"></a><a name="p184590736165636"></a>int16 </p>
</td>
</tr>
<tr id="row1915944282165636"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p76539156165636"><a name="p76539156165636"></a><a name="p76539156165636"></a><a href="SimpleVector.md#a1ff1e71311df432f11fd2613cdbc1b16">free</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1207102292165636"><a name="p1207102292165636"></a><a name="p1207102292165636"></a>int16 </p>
</td>
</tr>
<tr id="row1297328151165636"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1362957956165636"><a name="p1362957956165636"></a><a name="p1362957956165636"></a><a href="SimpleVector.md#a4674672209ae411544383a5399aee85b">data</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1383893730165636"><a name="p1383893730165636"></a><a name="p1383893730165636"></a>void ** </p>
</td>
</tr>
<tr id="row452607675165636"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p643887962165636"><a name="p643887962165636"></a><a name="p643887962165636"></a><a href="SimpleVector.md#a3e5edc51c8c7ef2536da2853986981ff">key</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1211674180165636"><a name="p1211674180165636"></a><a name="p1211674180165636"></a>VECTOR_Key </p>
</td>
</tr>
<tr id="row604166247165636"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1535398806165636"><a name="p1535398806165636"></a><a name="p1535398806165636"></a><a href="SimpleVector.md#a7661926c6a5d659ec2bff6533a7389fa">compare</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p900676943165636"><a name="p900676943165636"></a><a name="p900676943165636"></a>VECTOR_Compare </p>
</td>
</tr>
</tbody>
</table>

## **Details**<a name="section508538747165636"></a>

## **Field **<a name="section1604641307165636"></a>

## compare<a name="a7661926c6a5d659ec2bff6533a7389fa"></a>

```
VECTOR_Compare SimpleVector::compare
```

 **Description:**

Compares the sizes of key1 and key2, which are provided by users. The value  **1**  indicates that key1 is greater than key2, the value  **0**  indicates that key1 is equal to key2, and the value  **-1**  indicates that key1 is less than key2. The default value is  **NULL**. 

## data<a name="a4674672209ae411544383a5399aee85b"></a>

```
void** SimpleVector::data
```

 **Description:**

Data storage pointer 

## free<a name="a1ff1e71311df432f11fd2613cdbc1b16"></a>

```
int16 SimpleVector::free
```

 **Description:**

Number of data records that have been released. The initial value is  **0**. 

## key<a name="a3e5edc51c8c7ef2536da2853986981ff"></a>

```
VECTOR_Key SimpleVector::key
```

 **Description:**

Converts a data element into a key for comparison. The key is provided by users, and the default value is  **NULL**. 

## max<a name="a68140ca4cc59df48c63963f1eda3f35c"></a>

```
int16 SimpleVector::max
```

 **Description:**

Maximum number of data records that can be stored. The initial value is  **0**. 

## top<a name="ac699cefa0c1003b8babbe2c0ea3134db"></a>

```
int16 SimpleVector::top
```

 **Description:**

Peak value of the number of stored data records. The initial value is  **0**. 

