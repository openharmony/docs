# lconv<a name="ZH-CN_TOPIC_0000001055358154"></a>

-   [Overview](#section1714470981165637)
-   [Summary](#section1987561679165637)
-   [Data Fields](#pub-attribs)
-   [Details](#section1738794711165637)
-   [Field](#section931934608165637)
-   [currency\_symbol](#af3657bb8bf2a83a868cdeb0b108ab921)
-   [decimal\_point](#a445e27fc7f797c8cca97b381f062fb60)
-   [frac\_digits](#aa16e32ff4dcc95445742b5b165ffb071)
-   [grouping](#a46e468755a823be50de20f36be5ff2be)
-   [int\_curr\_symbol](#abaeeafb02b68ba58c549458b196b9325)
-   [int\_frac\_digits](#a6b652f28cafc3092258b47c8099fe905)
-   [int\_n\_cs\_precedes](#a36121c68c5571e40145365dd1edecbb7)
-   [int\_n\_sep\_by\_space](#ad9cfa63e25f4a2aa02f6c7ca540177a2)
-   [int\_n\_sign\_posn](#a642a9096f724fad40fe9f1711e92b323)
-   [int\_p\_cs\_precedes](#a1a78cbc82f07601c2acb643f8dffdf64)
-   [int\_p\_sep\_by\_space](#ae77e798ef92e86d58100b16fb8163443)
-   [int\_p\_sign\_posn](#a266ed42f4bb087d1efac551940c42f6f)
-   [mon\_decimal\_point](#a1aa08afe707c1d5d40b4d01369176480)
-   [mon\_grouping](#a12ecf5d2f7ceb0cfe0f66fd3200eef54)
-   [mon\_thousands\_sep](#a4f04f4fd9ea670d21fc76fb5c77c032d)
-   [n\_cs\_precedes](#ad118b68a229527f7e96538ac875169ad)
-   [n\_sep\_by\_space](#ab7ac20ce034900155183b32fc3c6d9a3)
-   [n\_sign\_posn](#ae0bbe6f545952daef5a8cbdd054a184e)
-   [negative\_sign](#a40dbb1b1d7fdf4926145138f5d8f6f5f)
-   [p\_cs\_precedes](#af0651922c77fc926609bdd8746784e63)
-   [p\_sep\_by\_space](#a3ae3cb36f4426158e4ab2ea6dc4278ad)
-   [p\_sign\_posn](#a1fdead36abe5c2ca673142ea401478e8)
-   [positive\_sign](#a74bf5f6f32624be629f7de0dabd58a96)
-   [thousands\_sep](#aede8dfaac91d7b4e6b7fb0d96184d74d)

## **Overview**<a name="section1714470981165637"></a>

**Related Modules:**

[IO](IO.md)

**Description:**

Indicates format information about a number. 

## **Summary**<a name="section1987561679165637"></a>

## Data Fields<a name="pub-attribs"></a>

<a name="table1045136913165637"></a>
<table><thead align="left"><tr id="row972946656165637"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p1983431199165637"><a name="p1983431199165637"></a><a name="p1983431199165637"></a>Variable Name</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p1961990732165637"><a name="p1961990732165637"></a><a name="p1961990732165637"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1964261283165637"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p93919687165637"><a name="p93919687165637"></a><a name="p93919687165637"></a><a href="lconv.md#a445e27fc7f797c8cca97b381f062fb60">decimal_point</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1455419965165637"><a name="p1455419965165637"></a><a name="p1455419965165637"></a>char * </p>
</td>
</tr>
<tr id="row1819347134165637"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1918459196165637"><a name="p1918459196165637"></a><a name="p1918459196165637"></a><a href="lconv.md#aede8dfaac91d7b4e6b7fb0d96184d74d">thousands_sep</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p165413857165637"><a name="p165413857165637"></a><a name="p165413857165637"></a>char * </p>
</td>
</tr>
<tr id="row1811009885165637"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p333235461165637"><a name="p333235461165637"></a><a name="p333235461165637"></a><a href="lconv.md#a46e468755a823be50de20f36be5ff2be">grouping</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p717129156165637"><a name="p717129156165637"></a><a name="p717129156165637"></a>char * </p>
</td>
</tr>
<tr id="row1028921954165637"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1077442019165637"><a name="p1077442019165637"></a><a name="p1077442019165637"></a><a href="lconv.md#abaeeafb02b68ba58c549458b196b9325">int_curr_symbol</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1565959115165637"><a name="p1565959115165637"></a><a name="p1565959115165637"></a>char * </p>
</td>
</tr>
<tr id="row335671533165637"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p809182825165637"><a name="p809182825165637"></a><a name="p809182825165637"></a><a href="lconv.md#af3657bb8bf2a83a868cdeb0b108ab921">currency_symbol</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1408457044165637"><a name="p1408457044165637"></a><a name="p1408457044165637"></a>char * </p>
</td>
</tr>
<tr id="row550225527165637"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1111683332165637"><a name="p1111683332165637"></a><a name="p1111683332165637"></a><a href="lconv.md#a1aa08afe707c1d5d40b4d01369176480">mon_decimal_point</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p285165035165637"><a name="p285165035165637"></a><a name="p285165035165637"></a>char * </p>
</td>
</tr>
<tr id="row1520590031165637"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1997245215165637"><a name="p1997245215165637"></a><a name="p1997245215165637"></a><a href="lconv.md#a4f04f4fd9ea670d21fc76fb5c77c032d">mon_thousands_sep</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p496474290165637"><a name="p496474290165637"></a><a name="p496474290165637"></a>char * </p>
</td>
</tr>
<tr id="row912139767165637"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1559875330165637"><a name="p1559875330165637"></a><a name="p1559875330165637"></a><a href="lconv.md#a12ecf5d2f7ceb0cfe0f66fd3200eef54">mon_grouping</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1031629197165637"><a name="p1031629197165637"></a><a name="p1031629197165637"></a>char * </p>
</td>
</tr>
<tr id="row1301930662165637"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1172011145165637"><a name="p1172011145165637"></a><a name="p1172011145165637"></a><a href="lconv.md#a74bf5f6f32624be629f7de0dabd58a96">positive_sign</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1541498976165637"><a name="p1541498976165637"></a><a name="p1541498976165637"></a>char * </p>
</td>
</tr>
<tr id="row727334318165637"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1014236127165637"><a name="p1014236127165637"></a><a name="p1014236127165637"></a><a href="lconv.md#a40dbb1b1d7fdf4926145138f5d8f6f5f">negative_sign</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1660339824165637"><a name="p1660339824165637"></a><a name="p1660339824165637"></a>char * </p>
</td>
</tr>
<tr id="row2007450407165637"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1594782586165637"><a name="p1594782586165637"></a><a name="p1594782586165637"></a><a href="lconv.md#a6b652f28cafc3092258b47c8099fe905">int_frac_digits</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p162426478165637"><a name="p162426478165637"></a><a name="p162426478165637"></a>char </p>
</td>
</tr>
<tr id="row1513654430165637"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1064819570165637"><a name="p1064819570165637"></a><a name="p1064819570165637"></a><a href="lconv.md#aa16e32ff4dcc95445742b5b165ffb071">frac_digits</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p338111907165637"><a name="p338111907165637"></a><a name="p338111907165637"></a>char </p>
</td>
</tr>
<tr id="row446886619165637"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1959616151165637"><a name="p1959616151165637"></a><a name="p1959616151165637"></a><a href="lconv.md#af0651922c77fc926609bdd8746784e63">p_cs_precedes</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1403697180165637"><a name="p1403697180165637"></a><a name="p1403697180165637"></a>char </p>
</td>
</tr>
<tr id="row384430012165637"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p920136929165637"><a name="p920136929165637"></a><a name="p920136929165637"></a><a href="lconv.md#a3ae3cb36f4426158e4ab2ea6dc4278ad">p_sep_by_space</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1765995602165637"><a name="p1765995602165637"></a><a name="p1765995602165637"></a>char </p>
</td>
</tr>
<tr id="row1546655449165637"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1863003969165637"><a name="p1863003969165637"></a><a name="p1863003969165637"></a><a href="lconv.md#ad118b68a229527f7e96538ac875169ad">n_cs_precedes</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1912502236165637"><a name="p1912502236165637"></a><a name="p1912502236165637"></a>char </p>
</td>
</tr>
<tr id="row2135763471165637"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1945263751165637"><a name="p1945263751165637"></a><a name="p1945263751165637"></a><a href="lconv.md#ab7ac20ce034900155183b32fc3c6d9a3">n_sep_by_space</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1688627054165637"><a name="p1688627054165637"></a><a name="p1688627054165637"></a>char </p>
</td>
</tr>
<tr id="row679343910165637"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1925364729165637"><a name="p1925364729165637"></a><a name="p1925364729165637"></a><a href="lconv.md#a1fdead36abe5c2ca673142ea401478e8">p_sign_posn</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p324130272165637"><a name="p324130272165637"></a><a name="p324130272165637"></a>char </p>
</td>
</tr>
<tr id="row1279619293165637"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2014025583165637"><a name="p2014025583165637"></a><a name="p2014025583165637"></a><a href="lconv.md#ae0bbe6f545952daef5a8cbdd054a184e">n_sign_posn</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p985579744165637"><a name="p985579744165637"></a><a name="p985579744165637"></a>char </p>
</td>
</tr>
<tr id="row2136790443165637"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2041372234165637"><a name="p2041372234165637"></a><a name="p2041372234165637"></a><a href="lconv.md#a1a78cbc82f07601c2acb643f8dffdf64">int_p_cs_precedes</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p761340529165637"><a name="p761340529165637"></a><a name="p761340529165637"></a>char </p>
</td>
</tr>
<tr id="row2002867097165637"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1720022649165637"><a name="p1720022649165637"></a><a name="p1720022649165637"></a><a href="lconv.md#ae77e798ef92e86d58100b16fb8163443">int_p_sep_by_space</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1545555213165637"><a name="p1545555213165637"></a><a name="p1545555213165637"></a>char </p>
</td>
</tr>
<tr id="row576880402165637"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p870287174165637"><a name="p870287174165637"></a><a name="p870287174165637"></a><a href="lconv.md#a36121c68c5571e40145365dd1edecbb7">int_n_cs_precedes</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2024410111165637"><a name="p2024410111165637"></a><a name="p2024410111165637"></a>char </p>
</td>
</tr>
<tr id="row304158684165637"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p263604024165637"><a name="p263604024165637"></a><a name="p263604024165637"></a><a href="lconv.md#ad9cfa63e25f4a2aa02f6c7ca540177a2">int_n_sep_by_space</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1254591254165637"><a name="p1254591254165637"></a><a name="p1254591254165637"></a>char </p>
</td>
</tr>
<tr id="row2074226547165637"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1452227284165637"><a name="p1452227284165637"></a><a name="p1452227284165637"></a><a href="lconv.md#a266ed42f4bb087d1efac551940c42f6f">int_p_sign_posn</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1454184682165637"><a name="p1454184682165637"></a><a name="p1454184682165637"></a>char </p>
</td>
</tr>
<tr id="row664719761165637"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1049769195165637"><a name="p1049769195165637"></a><a name="p1049769195165637"></a><a href="lconv.md#a642a9096f724fad40fe9f1711e92b323">int_n_sign_posn</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p739709028165637"><a name="p739709028165637"></a><a name="p739709028165637"></a>char </p>
</td>
</tr>
</tbody>
</table>

## **Details**<a name="section1738794711165637"></a>

## **Field **<a name="section931934608165637"></a>

## currency\_symbol<a name="af3657bb8bf2a83a868cdeb0b108ab921"></a>

```
char* lconv::currency_symbol
```

 **Description:**

Local currency symbol, for example, $ for dollar and ¥ for Chinese Yuan. 

## decimal\_point<a name="a445e27fc7f797c8cca97b381f062fb60"></a>

```
char* lconv::decimal_point
```

 **Description:**

Separator between the integer part and decimal part of decimal values. The default separator is  **.**. 

## frac\_digits<a name="aa16e32ff4dcc95445742b5b165ffb071"></a>

```
char lconv::frac_digits
```

 **Description:**

Maximum number of decimal parts of a currency value, which is not supported in the current system 

## grouping<a name="a46e468755a823be50de20f36be5ff2be"></a>

```
char* lconv::grouping
```

 **Description:**

Specifies that decimal values are separated by a group of digits. No separator is used in the system by default. 

## int\_curr\_symbol<a name="abaeeafb02b68ba58c549458b196b9325"></a>

```
char* lconv::int_curr_symbol
```

 **Description:**

International currency symbol, for example, USD for dollar and CNY for Chinese Yuan. For details, see ISO-4217. 

## int\_frac\_digits<a name="a6b652f28cafc3092258b47c8099fe905"></a>

```
char lconv::int_frac_digits
```

 **Description:**

Maximum number of decimal parts of a value, which is not supported in the current system 

## int\_n\_cs\_precedes<a name="a36121c68c5571e40145365dd1edecbb7"></a>

```
char lconv::int_n_cs_precedes
```

 **Description:**

Specifies whether to add an international currency symbol before a negative currency value. This parameter is not supported in the current system. 

## int\_n\_sep\_by\_space<a name="ad9cfa63e25f4a2aa02f6c7ca540177a2"></a>

```
char lconv::int_n_sep_by_space
```

 **Description:**

Specifies whether to add a space before a negative currency value as a separator. This parameter is not supported in the current system. 

## int\_n\_sign\_posn<a name="a642a9096f724fad40fe9f1711e92b323"></a>

```
char lconv::int_n_sign_posn
```

 **Description:**

Symbol position of a negative currency value, which is not supported in the current system 

## int\_p\_cs\_precedes<a name="a1a78cbc82f07601c2acb643f8dffdf64"></a>

```
char lconv::int_p_cs_precedes
```

 **Description:**

Specifies whether to add an international currency symbol before a non-negative currency value. This parameter is not supported in the current system. 

## int\_p\_sep\_by\_space<a name="ae77e798ef92e86d58100b16fb8163443"></a>

```
char lconv::int_p_sep_by_space
```

 **Description:**

Specifies whether to add a space before a non-negative currency value as a separator. This parameter is not supported in the current system. 

## int\_p\_sign\_posn<a name="a266ed42f4bb087d1efac551940c42f6f"></a>

```
char lconv::int_p_sign_posn
```

 **Description:**

Symbol position of a non-negative currency value, which is not supported in the current system 

## mon\_decimal\_point<a name="a1aa08afe707c1d5d40b4d01369176480"></a>

```
char* lconv::mon_decimal_point
```

 **Description:**

Separator between the integer part and decimal part of currency values. The system does not support this separator. 

## mon\_grouping<a name="a12ecf5d2f7ceb0cfe0f66fd3200eef54"></a>

```
char* lconv::mon_grouping
```

 **Description:**

Specifies that currency values are separated by a group of digits. No separator is used in the system by default. 

## mon\_thousands\_sep<a name="a4f04f4fd9ea670d21fc76fb5c77c032d"></a>

```
char* lconv::mon_thousands_sep
```

 **Description:**

The currency values are separated by thousands, that is, three digits form a group. The system does not support this separator. 

## n\_cs\_precedes<a name="ad118b68a229527f7e96538ac875169ad"></a>

```
char lconv::n_cs_precedes
```

 **Description:**

Specifies whether to add a currency symbol before a negative currency value. This parameter is not supported in the current system. 

## n\_sep\_by\_space<a name="ab7ac20ce034900155183b32fc3c6d9a3"></a>

```
char lconv::n_sep_by_space
```

 **Description:**

Specifies whether to add a space before a negative currency value as a separator. This parameter is not supported in the current system. 

## n\_sign\_posn<a name="ae0bbe6f545952daef5a8cbdd054a184e"></a>

```
char lconv::n_sign_posn
```

 **Description:**

Symbol position of a negative currency value, which is not supported in the current system 

## negative\_sign<a name="a40dbb1b1d7fdf4926145138f5d8f6f5f"></a>

```
char* lconv::negative_sign
```

 **Description:**

Symbol of a negative currency value, which is not supported in the current system 

## p\_cs\_precedes<a name="af0651922c77fc926609bdd8746784e63"></a>

```
char lconv::p_cs_precedes
```

 **Description:**

Specifies whether to add a currency symbol before a non-negative currency value. This parameter is not supported in the current system. 

## p\_sep\_by\_space<a name="a3ae3cb36f4426158e4ab2ea6dc4278ad"></a>

```
char lconv::p_sep_by_space
```

 **Description:**

Specifies whether to add a space before a non-negative currency value as a separator. This parameter is not supported in the current system. 

## p\_sign\_posn<a name="a1fdead36abe5c2ca673142ea401478e8"></a>

```
char lconv::p_sign_posn
```

 **Description:**

Symbol position of a non-negative currency value, which is not supported in the current system 

## positive\_sign<a name="a74bf5f6f32624be629f7de0dabd58a96"></a>

```
char* lconv::positive_sign
```

 **Description:**

Symbol of a non-negative currency value, which is not supported in the current system 

## thousands\_sep<a name="aede8dfaac91d7b4e6b7fb0d96184d74d"></a>

```
char* lconv::thousands_sep
```

 **Description:**

The decimal values are separated by thousands, that is, three digits form a group. No separator is used in the system by default. 

