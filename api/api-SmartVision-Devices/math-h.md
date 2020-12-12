# math.h<a name="ZH-CN_TOPIC_0000001055547980"></a>

-   [Overview](#section1227546439165628)
-   [Summary](#section961569372165628)
-   [Macros](#define-members)
-   [Functions](#func-members)

## **Overview**<a name="section1227546439165628"></a>

**Related Modules:**

[MATH](MATH.md)

**Description:**

Provides common math functions. 

You can use the functions provided in this file to perform mathematical operations during development. The functions include trigonometric, inverse trigonometric, hyperbolic, inverse hyperbolic, rounding, exponential, logarithmic, and Bessel functions. When using these functions, pay attention to the value range of their input parameters. 

**Since:**

1.0

**Version:**

1.0

## **Summary**<a name="section961569372165628"></a>

## Macros<a name="define-members"></a>

<a name="table395066977165628"></a>
<table><thead align="left"><tr id="row1762325584165628"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p191189352165628"><a name="p191189352165628"></a><a name="p191189352165628"></a>Macro Name and Value</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p2050025862165628"><a name="p2050025862165628"></a><a name="p2050025862165628"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1396182598165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p220780481165628"><a name="p220780481165628"></a><a name="p220780481165628"></a><a href="MATH.md#ga8abfcc76130f3f991d124dd22d7e69bc">NAN</a>   (0.0f/0.0f)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1681155128165628"><a name="p1681155128165628"></a><a name="p1681155128165628"></a>Indicates an undefined or unrepresentable value. </p>
</td>
</tr>
<tr id="row213082749165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p835328087165628"><a name="p835328087165628"></a><a name="p835328087165628"></a><a href="MATH.md#ga956e2723d559858d08644ac99146e910">INFINITY</a>   1e5000f</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1208493897165628"><a name="p1208493897165628"></a><a name="p1208493897165628"></a>Indicates an infinity. </p>
</td>
</tr>
<tr id="row1707074796165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1808791484165628"><a name="p1808791484165628"></a><a name="p1808791484165628"></a><a href="MATH.md#gacd69981d54c27fe0ff514645dbfc6359">HUGE_VALF</a>   <a href="MATH.md#ga956e2723d559858d08644ac99146e910">INFINITY</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1768956319165628"><a name="p1768956319165628"></a><a name="p1768956319165628"></a>Indicates a float infinity. </p>
</td>
</tr>
<tr id="row156760768165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1952682326165628"><a name="p1952682326165628"></a><a name="p1952682326165628"></a><a href="MATH.md#gaf2164b2db92d8a0ed3838ad5c28db971">HUGE_VAL</a>   ((double)<a href="MATH.md#ga956e2723d559858d08644ac99146e910">INFINITY</a>)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p170203257165628"><a name="p170203257165628"></a><a name="p170203257165628"></a>Indicates a double infinity. </p>
</td>
</tr>
<tr id="row181614790165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2086974926165628"><a name="p2086974926165628"></a><a name="p2086974926165628"></a><a href="MATH.md#gab8b359c356d4311bf5d4ae6c03f43182">HUGE_VALL</a>   ((long double)<a href="MATH.md#ga956e2723d559858d08644ac99146e910">INFINITY</a>)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1597777406165628"><a name="p1597777406165628"></a><a name="p1597777406165628"></a>Indicates a long double infinity. </p>
</td>
</tr>
<tr id="row2020882257165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p108048242165628"><a name="p108048242165628"></a><a name="p108048242165628"></a><a href="MATH.md#ga42b212d215eab7142f8272fefcd1c938">MATH_ERRNO</a>   1</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1684678319165628"><a name="p1684678319165628"></a><a name="p1684678319165628"></a>Indicates an error that occurs in floating-point operations. </p>
</td>
</tr>
<tr id="row1363911117165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p616343297165628"><a name="p616343297165628"></a><a name="p616343297165628"></a><a href="MATH.md#gae05ce3fe3745507c8e989f6e9efe0a83">MATH_ERREXCEPT</a>   2</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1534209740165628"><a name="p1534209740165628"></a><a name="p1534209740165628"></a>Indicates a floating-point exception. </p>
</td>
</tr>
<tr id="row1537065518165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p420601653165628"><a name="p420601653165628"></a><a name="p420601653165628"></a><a href="MATH.md#gaa8618aec27dedcd32f494ccf22f3ed42">math_errhandling</a>   2</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1420391555165628"><a name="p1420391555165628"></a><a name="p1420391555165628"></a>Indicates the error handling mechanism employed by math functions. </p>
</td>
</tr>
<tr id="row154591853165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p161782396165628"><a name="p161782396165628"></a><a name="p161782396165628"></a><a href="MATH.md#ga01e2e5be97c739a5bdcbc619b44f9742">FP_ILOGBNAN</a>   (-1-0x7fffffff)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1142534011165628"><a name="p1142534011165628"></a><a name="p1142534011165628"></a>Indicates the calculation result of <a href="MATH.md#ga600dd249210d15af31b9a29c2d09d255">ilogb</a>(<a href="MATH.md#ga8abfcc76130f3f991d124dd22d7e69bc">NAN</a>). </p>
</td>
</tr>
<tr id="row1363079995165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p898920442165628"><a name="p898920442165628"></a><a name="p898920442165628"></a><a href="MATH.md#ga9ec0e31304d15c42262b2c4a3b58443c">FP_ILOGB0</a>   <a href="MATH.md#ga01e2e5be97c739a5bdcbc619b44f9742">FP_ILOGBNAN</a></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p88938407165628"><a name="p88938407165628"></a><a name="p88938407165628"></a>Indicates the calculation result of <a href="MATH.md#ga600dd249210d15af31b9a29c2d09d255">ilogb</a>(0). </p>
</td>
</tr>
<tr id="row1816382395165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1628915464165628"><a name="p1628915464165628"></a><a name="p1628915464165628"></a><a href="MATH.md#ga1d481cc6e6a8ff729147ed46e61a4c9f">FP_NAN</a>   0</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1126124008165628"><a name="p1126124008165628"></a><a name="p1126124008165628"></a>Indicates a Not-a-Number (NaN) value. </p>
</td>
</tr>
<tr id="row101350572165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1501293405165628"><a name="p1501293405165628"></a><a name="p1501293405165628"></a><a href="MATH.md#ga4f64bcc64f8b84dd9daf5a4e56abf0ca">FP_INFINITE</a>   1</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p397599403165628"><a name="p397599403165628"></a><a name="p397599403165628"></a>Indicates an infinity. </p>
</td>
</tr>
<tr id="row2002787780165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p561085870165628"><a name="p561085870165628"></a><a name="p561085870165628"></a><a href="MATH.md#ga32eba50da417c9f303ba49583d5b9f40">FP_ZERO</a>   2</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1487995066165628"><a name="p1487995066165628"></a><a name="p1487995066165628"></a>Indicates value <strong id="b1271859284165628"><a name="b1271859284165628"></a><a name="b1271859284165628"></a>0</strong>. </p>
</td>
</tr>
<tr id="row643481784165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2080217192165628"><a name="p2080217192165628"></a><a name="p2080217192165628"></a><a href="MATH.md#gadbc0a13ec75c05d238ca12ef1f8c6b2b">FP_SUBNORMAL</a>   3</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1822581370165628"><a name="p1822581370165628"></a><a name="p1822581370165628"></a>Indicates a subnormal. </p>
</td>
</tr>
<tr id="row159639514165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p519825773165628"><a name="p519825773165628"></a><a name="p519825773165628"></a><a href="MATH.md#gab9e29bb9e853934c4ba647c840b7e5de">FP_NORMAL</a>   4</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1494475926165628"><a name="p1494475926165628"></a><a name="p1494475926165628"></a>Indicates a normal value. </p>
</td>
</tr>
<tr id="row1753782973165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1372891516165628"><a name="p1372891516165628"></a><a name="p1372891516165628"></a><a href="MATH.md#ga2a266c767456556e5c0da234b602b18b">isinf</a>(x)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p159870088165628"><a name="p159870088165628"></a><a name="p159870088165628"></a>Checks whether the floating-point value <strong id="b1131583547165628"><a name="b1131583547165628"></a><a name="b1131583547165628"></a>x</strong> is an infinity. </p>
</td>
</tr>
<tr id="row958421167165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p88015829165628"><a name="p88015829165628"></a><a name="p88015829165628"></a><a href="MATH.md#ga2e1baae9134e580910322362dc23290e">isnan</a>(x)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1657956389165628"><a name="p1657956389165628"></a><a name="p1657956389165628"></a>Checks whether the floating-point value <strong id="b1764146042165628"><a name="b1764146042165628"></a><a name="b1764146042165628"></a>x</strong> is a NaN value. </p>
</td>
</tr>
<tr id="row1036936304165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p483863449165628"><a name="p483863449165628"></a><a name="p483863449165628"></a><a href="MATH.md#gad83f5949c4b5d810225b9a834840bac9">isnormal</a>(x)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p592957264165628"><a name="p592957264165628"></a><a name="p592957264165628"></a>Checks whether the floating-point value <strong id="b1107735219165628"><a name="b1107735219165628"></a><a name="b1107735219165628"></a>x</strong> is a normal value. </p>
</td>
</tr>
<tr id="row1957887557165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p659700404165628"><a name="p659700404165628"></a><a name="p659700404165628"></a><a href="MATH.md#ga256d70a32c03904ce13c999c1e9dc35d">isfinite</a>(x)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1005530398165628"><a name="p1005530398165628"></a><a name="p1005530398165628"></a>Checks whether the floating-point value <strong id="b1716250903165628"><a name="b1716250903165628"></a><a name="b1716250903165628"></a>x</strong> is finite. </p>
</td>
</tr>
<tr id="row1939020382165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p849801631165628"><a name="p849801631165628"></a><a name="p849801631165628"></a><a href="MATH.md#gaa63ffa98f213f62e536b073c28cb3cd8">signbit</a>(x)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p949209857165628"><a name="p949209857165628"></a><a name="p949209857165628"></a>Checks whether the sign of the floating-point value <strong id="b1819793201165628"><a name="b1819793201165628"></a><a name="b1819793201165628"></a>x</strong> is negative. </p>
</td>
</tr>
<tr id="row762508686165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p930822913165628"><a name="p930822913165628"></a><a name="p930822913165628"></a><a href="MATH.md#ga33daf51eb7138d477e0b0985c51e4fad">isunordered</a>(x, y)   (<a href="MATH.md#ga2e1baae9134e580910322362dc23290e">isnan</a>((x)) ? ((void)(y),1) : <a href="MATH.md#ga2e1baae9134e580910322362dc23290e">isnan</a>((y)))</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2006210231165628"><a name="p2006210231165628"></a><a name="p2006210231165628"></a>Checks whether floating-point value <strong id="b1308833230165628"><a name="b1308833230165628"></a><a name="b1308833230165628"></a>x</strong> or <strong id="b841263580165628"><a name="b841263580165628"></a><a name="b841263580165628"></a>y</strong> is unordered. </p>
</td>
</tr>
<tr id="row376654994165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p385831972165628"><a name="p385831972165628"></a><a name="p385831972165628"></a><a href="MATH.md#ga61079b32084130da4345c2eea93e0d61">isless</a>(x, y)   __tg_pred_2(x, y, __isless)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p362585365165628"><a name="p362585365165628"></a><a name="p362585365165628"></a>Checks whether floating-point value <strong id="b1970835408165628"><a name="b1970835408165628"></a><a name="b1970835408165628"></a>x</strong> is less than <strong id="b1640186383165628"><a name="b1640186383165628"></a><a name="b1640186383165628"></a>y</strong>. </p>
</td>
</tr>
<tr id="row195785083165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p45767636165628"><a name="p45767636165628"></a><a name="p45767636165628"></a><a href="MATH.md#gabf3cb1e5a0aaa1c42dffa9ebb1d78c30">islessequal</a>(x, y)   __tg_pred_2(x, y, __islessequal)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p929755019165628"><a name="p929755019165628"></a><a name="p929755019165628"></a>Checks whether floating-point value <strong id="b1806248138165628"><a name="b1806248138165628"></a><a name="b1806248138165628"></a>x</strong> is less than or equal to <strong id="b404889615165628"><a name="b404889615165628"></a><a name="b404889615165628"></a>y</strong>. </p>
</td>
</tr>
<tr id="row1874559551165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p555601800165628"><a name="p555601800165628"></a><a name="p555601800165628"></a><a href="MATH.md#ga5e534756b747fd2e9ee19f8fdd93b30b">islessgreater</a>(x, y)   __tg_pred_2(x, y, __islessgreater)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1568840699165628"><a name="p1568840699165628"></a><a name="p1568840699165628"></a>Checks whether floating-point value <strong id="b1433094796165628"><a name="b1433094796165628"></a><a name="b1433094796165628"></a>x</strong> is either less than or greater than <strong id="b1254986659165628"><a name="b1254986659165628"></a><a name="b1254986659165628"></a>y</strong>. </p>
</td>
</tr>
<tr id="row741235569165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p603352228165628"><a name="p603352228165628"></a><a name="p603352228165628"></a><a href="MATH.md#gada788e9d6ce0ca927874ec4e53af1f77">isgreater</a>(x, y)   __tg_pred_2(x, y, __isgreater)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1927135442165628"><a name="p1927135442165628"></a><a name="p1927135442165628"></a>Checks whether floating-point value <strong id="b2029420308165628"><a name="b2029420308165628"></a><a name="b2029420308165628"></a>x</strong> is greater than <strong id="b2135490250165628"><a name="b2135490250165628"></a><a name="b2135490250165628"></a>y</strong>. </p>
</td>
</tr>
<tr id="row342193672165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1907624948165628"><a name="p1907624948165628"></a><a name="p1907624948165628"></a><a href="MATH.md#ga5a7f86a4d3e6139e4913e2e8eba52612">isgreaterequal</a>(x, y)   __tg_pred_2(x, y, __isgreaterequal)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1944313157165628"><a name="p1944313157165628"></a><a name="p1944313157165628"></a>Checks whether floating-point value <strong id="b1572437688165628"><a name="b1572437688165628"></a><a name="b1572437688165628"></a>x</strong> is greater than or equal to <strong id="b1743225016165628"><a name="b1743225016165628"></a><a name="b1743225016165628"></a>y</strong>. </p>
</td>
</tr>
<tr id="row997767961165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2056532922165628"><a name="p2056532922165628"></a><a name="p2056532922165628"></a><a href="MATH.md#ga5e9e29217f6ec61105a4520ec5942225">MAXFLOAT</a>   3.40282346638528859812e+38F</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1897913768165628"><a name="p1897913768165628"></a><a name="p1897913768165628"></a>Maximum value of type float. </p>
</td>
</tr>
<tr id="row2005122559165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1616704218165628"><a name="p1616704218165628"></a><a name="p1616704218165628"></a><a href="MATH.md#ga9bf5d952c5c93c70f9e66c9794d406c9">M_E</a>   2.7182818284590452354 /* e */</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1429677473165628"><a name="p1429677473165628"></a><a name="p1429677473165628"></a>Base e of natural logarithms. </p>
</td>
</tr>
<tr id="row621493731165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2143268911165628"><a name="p2143268911165628"></a><a name="p2143268911165628"></a><a href="MATH.md#gac5c747ee5bcbe892875672a0b9d8171c">M_LOG2E</a>   1.4426950408889634074 /* log_2 e */</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p147029544165628"><a name="p147029544165628"></a><a name="p147029544165628"></a>Logarithm to base 2 of <strong id="b376051351165628"><a name="b376051351165628"></a><a name="b376051351165628"></a>M_E</strong> </p>
</td>
</tr>
<tr id="row1732934829165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2020432825165628"><a name="p2020432825165628"></a><a name="p2020432825165628"></a><a href="MATH.md#ga9ed2b5582226f3896424ff6d2a3ebb14">M_LOG10E</a>   0.43429448190325182765 /* log_10 e */</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p458110309165628"><a name="p458110309165628"></a><a name="p458110309165628"></a>Logarithm to base 10 of <strong id="b802686043165628"><a name="b802686043165628"></a><a name="b802686043165628"></a>M_E</strong> </p>
</td>
</tr>
<tr id="row82929072165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2110886400165628"><a name="p2110886400165628"></a><a name="p2110886400165628"></a><a href="MATH.md#ga92428112a5d24721208748774a4f23e6">M_LN2</a>   0.69314718055994530942 /* log_e 2 */</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1726762299165628"><a name="p1726762299165628"></a><a name="p1726762299165628"></a>Natural logarithm of <strong id="b678845006165628"><a name="b678845006165628"></a><a name="b678845006165628"></a>2</strong> </p>
</td>
</tr>
<tr id="row909684430165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1539024775165628"><a name="p1539024775165628"></a><a name="p1539024775165628"></a><a href="MATH.md#ga0a53871497a155afe91424c28a8ec3c4">M_LN10</a>   2.30258509299404568402 /* log_e 10 */</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1514792117165628"><a name="p1514792117165628"></a><a name="p1514792117165628"></a>Natural logarithm of <strong id="b70596155165628"><a name="b70596155165628"></a><a name="b70596155165628"></a>10</strong> </p>
</td>
</tr>
<tr id="row530549447165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1623429169165628"><a name="p1623429169165628"></a><a name="p1623429169165628"></a><a href="MATH.md#gae71449b1cc6e6250b91f539153a7a0d3">M_PI</a>   3.14159265358979323846 /* pi */</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1993563185165628"><a name="p1993563185165628"></a><a name="p1993563185165628"></a>Ratio of a circle's circumference to its diameter. </p>
</td>
</tr>
<tr id="row360814757165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p653075220165628"><a name="p653075220165628"></a><a name="p653075220165628"></a><a href="MATH.md#ga958e4508ed28ee5cc04249144312c15f">M_PI_2</a>   1.57079632679489661923 /* pi/2 */</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1026357893165628"><a name="p1026357893165628"></a><a name="p1026357893165628"></a>Pi divided by <strong id="b2085997252165628"><a name="b2085997252165628"></a><a name="b2085997252165628"></a>2</strong> </p>
</td>
</tr>
<tr id="row131474380165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1037421854165628"><a name="p1037421854165628"></a><a name="p1037421854165628"></a><a href="MATH.md#gaeb24420b096a677f3a2dc5a72b36bf22">M_PI_4</a>   0.78539816339744830962 /* pi/4 */</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1743137411165628"><a name="p1743137411165628"></a><a name="p1743137411165628"></a>Pi divided by <strong id="b1855166704165628"><a name="b1855166704165628"></a><a name="b1855166704165628"></a>4</strong> </p>
</td>
</tr>
<tr id="row200010283165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1746096581165628"><a name="p1746096581165628"></a><a name="p1746096581165628"></a><a href="MATH.md#ga08dfac3cca9601a02fc88356cc078e1d">M_1_PI</a>   0.31830988618379067154 /* 1/pi */</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1749791723165628"><a name="p1749791723165628"></a><a name="p1749791723165628"></a>Reciprocal of pi. </p>
</td>
</tr>
<tr id="row1568279918165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p623266974165628"><a name="p623266974165628"></a><a name="p623266974165628"></a><a href="MATH.md#ga97f6d6514d3d3dd50c3a2a6d622673db">M_2_PI</a>   0.63661977236758134308 /* 2/pi */</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p457975802165628"><a name="p457975802165628"></a><a name="p457975802165628"></a>Two times the reciprocal of pi. </p>
</td>
</tr>
<tr id="row876501435165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2064470253165628"><a name="p2064470253165628"></a><a name="p2064470253165628"></a><a href="MATH.md#ga631ff334c4a1a6db2e8a7ff4acbe48a5">M_2_SQRTPI</a>   1.12837916709551257390 /* 2/<a href="MATH.md#gab87521a75ef827a85807f89a6c10629a">sqrt</a>(pi) */</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1377126430165628"><a name="p1377126430165628"></a><a name="p1377126430165628"></a>Two times the reciprocal of the square root of pi. </p>
</td>
</tr>
<tr id="row1059547728165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1214734300165628"><a name="p1214734300165628"></a><a name="p1214734300165628"></a><a href="MATH.md#ga66b3ab30f1332874326ed93969e496e0">M_SQRT2</a>   1.41421356237309504880 /* <a href="MATH.md#gab87521a75ef827a85807f89a6c10629a">sqrt</a>(2) */</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p97527745165628"><a name="p97527745165628"></a><a name="p97527745165628"></a>Square root of <strong id="b835893615165628"><a name="b835893615165628"></a><a name="b835893615165628"></a>2</strong> </p>
</td>
</tr>
<tr id="row539183434165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1195706670165628"><a name="p1195706670165628"></a><a name="p1195706670165628"></a><a href="MATH.md#gacdbb2c2f9429f08916f03c8786d2d2d7">M_SQRT1_2</a>   0.70710678118654752440 /* 1/<a href="MATH.md#gab87521a75ef827a85807f89a6c10629a">sqrt</a>(2) */</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p644534991165628"><a name="p644534991165628"></a><a name="p644534991165628"></a>Reciprocal of the square root of <strong id="b1469870513165628"><a name="b1469870513165628"></a><a name="b1469870513165628"></a>2</strong> </p>
</td>
</tr>
</tbody>
</table>

## Functions<a name="func-members"></a>

<a name="table128748734165628"></a>
<table><thead align="left"><tr id="row2069387170165628"><th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.1"><p id="p359290588165628"><a name="p359290588165628"></a><a name="p359290588165628"></a>Function</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.3.1.2"><p id="p202874876165628"><a name="p202874876165628"></a><a name="p202874876165628"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row386276957165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p199124885165628"><a name="p199124885165628"></a><a name="p199124885165628"></a><a href="MATH.md#gae93afe22ff34c79ee97ea3eaf77557db">acos</a> (double x)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p519839650165628"><a name="p519839650165628"></a><a name="p519839650165628"></a>double </p>
<p id="p1792480750165628"><a name="p1792480750165628"></a><a name="p1792480750165628"></a>Calculates the arc cosine of the double value <strong id="b720662966165628"><a name="b720662966165628"></a><a name="b720662966165628"></a>x</strong>. </p>
</td>
</tr>
<tr id="row1318952179165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p684850993165628"><a name="p684850993165628"></a><a name="p684850993165628"></a><a href="MATH.md#ga983a9e1aa7568df39153ea4d8e16653b">acosf</a> (float x)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2126177739165628"><a name="p2126177739165628"></a><a name="p2126177739165628"></a>float </p>
<p id="p402967861165628"><a name="p402967861165628"></a><a name="p402967861165628"></a>Calculates the arc cosine of the float value <strong id="b2073241892165628"><a name="b2073241892165628"></a><a name="b2073241892165628"></a>x</strong>. </p>
</td>
</tr>
<tr id="row342956452165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p203287111165628"><a name="p203287111165628"></a><a name="p203287111165628"></a><a href="MATH.md#gae84dc6cff92b3417098f16a1811635e4">acosl</a> (long double x)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1914923817165628"><a name="p1914923817165628"></a><a name="p1914923817165628"></a>long double </p>
<p id="p1101156073165628"><a name="p1101156073165628"></a><a name="p1101156073165628"></a>Calculates the arc cosine of the long double value <strong id="b1630517815165628"><a name="b1630517815165628"></a><a name="b1630517815165628"></a>x</strong>. </p>
</td>
</tr>
<tr id="row707965524165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p388326722165628"><a name="p388326722165628"></a><a name="p388326722165628"></a><a href="MATH.md#gac862445bcb46911b1782c284829d5e46">acosh</a> (double x)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1675447233165628"><a name="p1675447233165628"></a><a name="p1675447233165628"></a>double </p>
<p id="p1015097179165628"><a name="p1015097179165628"></a><a name="p1015097179165628"></a>Calculates the inverse hyperbolic cosine of the double value <strong id="b144732495165628"><a name="b144732495165628"></a><a name="b144732495165628"></a>x</strong>. </p>
</td>
</tr>
<tr id="row1966743053165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1176649150165628"><a name="p1176649150165628"></a><a name="p1176649150165628"></a><a href="MATH.md#ga84cfd14c3432390f70b6233d24ad173b">acoshf</a> (float x)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1276900300165628"><a name="p1276900300165628"></a><a name="p1276900300165628"></a>float </p>
<p id="p1965087326165628"><a name="p1965087326165628"></a><a name="p1965087326165628"></a>Calculates the inverse hyperbolic cosine of float value <strong id="b812382835165628"><a name="b812382835165628"></a><a name="b812382835165628"></a>x</strong>. </p>
</td>
</tr>
<tr id="row1812600987165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p339468221165628"><a name="p339468221165628"></a><a name="p339468221165628"></a><a href="MATH.md#ga104456314ba05665d6cbb805e823dd10">acoshl</a> (long double x)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p301064676165628"><a name="p301064676165628"></a><a name="p301064676165628"></a>long double </p>
<p id="p1027862078165628"><a name="p1027862078165628"></a><a name="p1027862078165628"></a>Calculates the inverse hyperbolic cosine of the long double value <strong id="b2058858196165628"><a name="b2058858196165628"></a><a name="b2058858196165628"></a>x</strong>. </p>
</td>
</tr>
<tr id="row1634914320165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p156756503165628"><a name="p156756503165628"></a><a name="p156756503165628"></a><a href="MATH.md#gaa9528d92a3ae44ad6484da0774604454">asin</a> (double x)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p766376271165628"><a name="p766376271165628"></a><a name="p766376271165628"></a>double </p>
<p id="p1092116665165628"><a name="p1092116665165628"></a><a name="p1092116665165628"></a>Calculates the arc sine of the double value <strong id="b1725582424165628"><a name="b1725582424165628"></a><a name="b1725582424165628"></a>x</strong>. </p>
</td>
</tr>
<tr id="row1107987356165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1912310951165628"><a name="p1912310951165628"></a><a name="p1912310951165628"></a><a href="MATH.md#ga7447a7400ca474ba42d127b04d6ee2b7">asinf</a> (float x)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1124147987165628"><a name="p1124147987165628"></a><a name="p1124147987165628"></a>float </p>
<p id="p1849768024165628"><a name="p1849768024165628"></a><a name="p1849768024165628"></a>Calculates the arc sine of the float value <strong id="b405834506165628"><a name="b405834506165628"></a><a name="b405834506165628"></a>x</strong>. </p>
</td>
</tr>
<tr id="row348792229165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2067708787165628"><a name="p2067708787165628"></a><a name="p2067708787165628"></a><a href="MATH.md#ga3ace56b4f2a4a9364993a5af676793c5">asinl</a> (long double x)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1757517231165628"><a name="p1757517231165628"></a><a name="p1757517231165628"></a>long double </p>
<p id="p995519774165628"><a name="p995519774165628"></a><a name="p995519774165628"></a>Calculates the arc sine of the long double value <strong id="b499782286165628"><a name="b499782286165628"></a><a name="b499782286165628"></a>x</strong>. </p>
</td>
</tr>
<tr id="row600056694165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2084219331165628"><a name="p2084219331165628"></a><a name="p2084219331165628"></a><a href="MATH.md#ga907297107e93ea9c8a0c8409a8e65079">asinh</a> (double x)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1246592624165628"><a name="p1246592624165628"></a><a name="p1246592624165628"></a>double </p>
<p id="p1828451881165628"><a name="p1828451881165628"></a><a name="p1828451881165628"></a>Calculates the inverse hyperbolic sine of the double value <strong id="b544247532165628"><a name="b544247532165628"></a><a name="b544247532165628"></a>x</strong>. </p>
</td>
</tr>
<tr id="row1699052320165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p502396733165628"><a name="p502396733165628"></a><a name="p502396733165628"></a><a href="MATH.md#ga1131c65ac49f31ed6774d27106c6394d">asinhf</a> (float x)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1579164900165628"><a name="p1579164900165628"></a><a name="p1579164900165628"></a>float </p>
<p id="p286886520165628"><a name="p286886520165628"></a><a name="p286886520165628"></a>Calculates the inverse hyperbolic sine of the float value <strong id="b1383098954165628"><a name="b1383098954165628"></a><a name="b1383098954165628"></a>x</strong>. </p>
</td>
</tr>
<tr id="row1613108401165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2041790422165628"><a name="p2041790422165628"></a><a name="p2041790422165628"></a><a href="MATH.md#ga98df355372e19c11634992e4b7e35784">asinhl</a> (long double x)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p48224588165628"><a name="p48224588165628"></a><a name="p48224588165628"></a>long double </p>
<p id="p1275125059165628"><a name="p1275125059165628"></a><a name="p1275125059165628"></a>Calculates the inverse hyperbolic sine of the long double value <strong id="b1192412881165628"><a name="b1192412881165628"></a><a name="b1192412881165628"></a>x</strong>. </p>
</td>
</tr>
<tr id="row1620246734165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1802314655165628"><a name="p1802314655165628"></a><a name="p1802314655165628"></a><a href="MATH.md#ga1e2f8f6d64eaa95131bc63fee34970ea">atan</a> (double x)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p620981625165628"><a name="p620981625165628"></a><a name="p620981625165628"></a>double </p>
<p id="p305265671165628"><a name="p305265671165628"></a><a name="p305265671165628"></a>Calculates the arc tangent of the double value <strong id="b884358358165628"><a name="b884358358165628"></a><a name="b884358358165628"></a>x</strong>. </p>
</td>
</tr>
<tr id="row1140324522165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p862321264165628"><a name="p862321264165628"></a><a name="p862321264165628"></a><a href="MATH.md#gaa582bc257e477e805f4ec384a39a3a8e">atanf</a> (float x)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1092507730165628"><a name="p1092507730165628"></a><a name="p1092507730165628"></a>float </p>
<p id="p440787699165628"><a name="p440787699165628"></a><a name="p440787699165628"></a>Calculates the arc tangent of the float value <strong id="b2110367237165628"><a name="b2110367237165628"></a><a name="b2110367237165628"></a>x</strong>. </p>
</td>
</tr>
<tr id="row21769186165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p449955693165628"><a name="p449955693165628"></a><a name="p449955693165628"></a><a href="MATH.md#ga650d8dd23c16c6699d84651a18827d37">atanl</a> (long double x)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1145254362165628"><a name="p1145254362165628"></a><a name="p1145254362165628"></a>long double </p>
<p id="p1052804416165628"><a name="p1052804416165628"></a><a name="p1052804416165628"></a>Calculates the arc tangent of the long double value <strong id="b268775404165628"><a name="b268775404165628"></a><a name="b268775404165628"></a>x</strong>. </p>
</td>
</tr>
<tr id="row1238297788165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p155889795165628"><a name="p155889795165628"></a><a name="p155889795165628"></a><a href="MATH.md#ga349377202ca14f79eb335b1a421fe4d8">atan2</a> (double y, double x)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p485220895165628"><a name="p485220895165628"></a><a name="p485220895165628"></a>double </p>
<p id="p358722608165628"><a name="p358722608165628"></a><a name="p358722608165628"></a>Calculates the arc tangent of two double values <strong id="b710309054165628"><a name="b710309054165628"></a><a name="b710309054165628"></a>x</strong> and <strong id="b1385268812165628"><a name="b1385268812165628"></a><a name="b1385268812165628"></a>y</strong>. </p>
</td>
</tr>
<tr id="row302886633165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1489406323165628"><a name="p1489406323165628"></a><a name="p1489406323165628"></a><a href="MATH.md#gaf9e5469acf7a7bf82f29d86a77f539d4">atan2f</a> (float y, float x)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1339857567165628"><a name="p1339857567165628"></a><a name="p1339857567165628"></a>float </p>
<p id="p511250541165628"><a name="p511250541165628"></a><a name="p511250541165628"></a>Calculates the arc tangent of two float values <strong id="b933627816165628"><a name="b933627816165628"></a><a name="b933627816165628"></a>x</strong> and <strong id="b261047152165628"><a name="b261047152165628"></a><a name="b261047152165628"></a>y</strong>. </p>
</td>
</tr>
<tr id="row980619720165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1533462087165628"><a name="p1533462087165628"></a><a name="p1533462087165628"></a><a href="MATH.md#gaa983bf34c931b97d66be8b7bfd03dc48">atan2l</a> (long double y, long double x)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1018358143165628"><a name="p1018358143165628"></a><a name="p1018358143165628"></a>long double </p>
<p id="p1386995208165628"><a name="p1386995208165628"></a><a name="p1386995208165628"></a>Calculates the arc tangent of two long double values <strong id="b1135665868165628"><a name="b1135665868165628"></a><a name="b1135665868165628"></a>x</strong> and <strong id="b1480882820165628"><a name="b1480882820165628"></a><a name="b1480882820165628"></a>y</strong>. </p>
</td>
</tr>
<tr id="row784552835165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2064571303165628"><a name="p2064571303165628"></a><a name="p2064571303165628"></a><a href="MATH.md#gac07fd7b77fa341563abccf9efcc1a711">atanh</a> (double x)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p766698841165628"><a name="p766698841165628"></a><a name="p766698841165628"></a>double </p>
<p id="p1466521428165628"><a name="p1466521428165628"></a><a name="p1466521428165628"></a>Calculates the inverse hyperbolic tangent of the double value <strong id="b191762482165628"><a name="b191762482165628"></a><a name="b191762482165628"></a>x</strong>. </p>
</td>
</tr>
<tr id="row201805217165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1644120432165628"><a name="p1644120432165628"></a><a name="p1644120432165628"></a><a href="MATH.md#ga626d9d6644848e74188f37f0f3ddd4f4">atanhf</a> (float x)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1218182120165628"><a name="p1218182120165628"></a><a name="p1218182120165628"></a>float </p>
<p id="p789702654165628"><a name="p789702654165628"></a><a name="p789702654165628"></a>Calculates the inverse hyperbolic tangent of the float value <strong id="b2015256478165628"><a name="b2015256478165628"></a><a name="b2015256478165628"></a>x</strong>. </p>
</td>
</tr>
<tr id="row849079299165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p932035013165628"><a name="p932035013165628"></a><a name="p932035013165628"></a><a href="MATH.md#gab25c31215118cd62672c38f80f010d66">atanhl</a> (long double x)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p196312760165628"><a name="p196312760165628"></a><a name="p196312760165628"></a>long double </p>
<p id="p1168788274165628"><a name="p1168788274165628"></a><a name="p1168788274165628"></a>Calculates the inverse hyperbolic tangent of the long double value <strong id="b572810724165628"><a name="b572810724165628"></a><a name="b572810724165628"></a>x</strong>. </p>
</td>
</tr>
<tr id="row1406912178165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p91444730165628"><a name="p91444730165628"></a><a name="p91444730165628"></a><a href="MATH.md#ga8af00e2203928978e0242b4afd1d899f">cbrt</a> (double x)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2085061272165628"><a name="p2085061272165628"></a><a name="p2085061272165628"></a>double </p>
<p id="p1183672070165628"><a name="p1183672070165628"></a><a name="p1183672070165628"></a>Calculates the cube root of the double value <strong id="b2112050193165628"><a name="b2112050193165628"></a><a name="b2112050193165628"></a>x</strong>. </p>
</td>
</tr>
<tr id="row57621691165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p800711846165628"><a name="p800711846165628"></a><a name="p800711846165628"></a><a href="MATH.md#ga396c6a553500a355627741e234045bf4">cbrtf</a> (float x)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1958028789165628"><a name="p1958028789165628"></a><a name="p1958028789165628"></a>float </p>
<p id="p402948849165628"><a name="p402948849165628"></a><a name="p402948849165628"></a>Calculates the cube root of the float value <strong id="b194926317165628"><a name="b194926317165628"></a><a name="b194926317165628"></a>x</strong>. </p>
</td>
</tr>
<tr id="row898785992165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1270952638165628"><a name="p1270952638165628"></a><a name="p1270952638165628"></a><a href="MATH.md#ga521c2f4c10b7bb5363bad058ef56794c">cbrtl</a> (long double x)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p545799247165628"><a name="p545799247165628"></a><a name="p545799247165628"></a>long double </p>
<p id="p2027586346165628"><a name="p2027586346165628"></a><a name="p2027586346165628"></a>Calculates the cube root of the long double value <strong id="b390127791165628"><a name="b390127791165628"></a><a name="b390127791165628"></a>x</strong>. </p>
</td>
</tr>
<tr id="row1526197608165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1418090572165628"><a name="p1418090572165628"></a><a name="p1418090572165628"></a><a href="MATH.md#ga1ea6d7b591132268abc2e843ababd084">ceil</a> (double x)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1506750109165628"><a name="p1506750109165628"></a><a name="p1506750109165628"></a>double </p>
<p id="p143512912165628"><a name="p143512912165628"></a><a name="p143512912165628"></a>Calculates the minimum integer greater than or equal to the double value <strong id="b1064327697165628"><a name="b1064327697165628"></a><a name="b1064327697165628"></a>x</strong>. </p>
</td>
</tr>
<tr id="row152971710165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p636219587165628"><a name="p636219587165628"></a><a name="p636219587165628"></a><a href="MATH.md#ga8c1a8db0710bb3f25f643a0fca68fc60">ceilf</a> (float x)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p492115016165628"><a name="p492115016165628"></a><a name="p492115016165628"></a>float </p>
<p id="p1275456364165628"><a name="p1275456364165628"></a><a name="p1275456364165628"></a>Calculates the minimum integer greater than or equal to the float value <strong id="b577097703165628"><a name="b577097703165628"></a><a name="b577097703165628"></a>x</strong>. </p>
</td>
</tr>
<tr id="row975377496165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1802501007165628"><a name="p1802501007165628"></a><a name="p1802501007165628"></a><a href="MATH.md#gae11b7781f057eb7ba5d7ed95be7fdbee">ceill</a> (long double x)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1469354043165628"><a name="p1469354043165628"></a><a name="p1469354043165628"></a>long double </p>
<p id="p678569557165628"><a name="p678569557165628"></a><a name="p678569557165628"></a>Calculates the minimum integer greater than or equal to the long double value <strong id="b1919379318165628"><a name="b1919379318165628"></a><a name="b1919379318165628"></a>x</strong>. </p>
</td>
</tr>
<tr id="row886111958165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1939007629165628"><a name="p1939007629165628"></a><a name="p1939007629165628"></a><a href="MATH.md#gad8d1296592a3e783acdd0de21ff58e2e">copysign</a> (double x, double y)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1100257337165628"><a name="p1100257337165628"></a><a name="p1100257337165628"></a>double </p>
<p id="p1897854700165628"><a name="p1897854700165628"></a><a name="p1897854700165628"></a>Generates a value by combining the magnitude of the double value <strong id="b16503484165628"><a name="b16503484165628"></a><a name="b16503484165628"></a>x</strong> and the sign of the double value <strong id="b729225669165628"><a name="b729225669165628"></a><a name="b729225669165628"></a>y</strong>. </p>
</td>
</tr>
<tr id="row175803998165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1448688258165628"><a name="p1448688258165628"></a><a name="p1448688258165628"></a><a href="MATH.md#gaf7eb976cc28d0a9a6f0827d01611f979">copysignf</a> (float x, float y)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1874150182165628"><a name="p1874150182165628"></a><a name="p1874150182165628"></a>float </p>
<p id="p1143269884165628"><a name="p1143269884165628"></a><a name="p1143269884165628"></a>Generates a value by combining the magnitude of the float value <strong id="b1853198531165628"><a name="b1853198531165628"></a><a name="b1853198531165628"></a>x</strong> and the sign of the float value <strong id="b819823364165628"><a name="b819823364165628"></a><a name="b819823364165628"></a>y</strong>. </p>
</td>
</tr>
<tr id="row1388930680165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p467360598165628"><a name="p467360598165628"></a><a name="p467360598165628"></a><a href="MATH.md#gae60d4866e88abf023d92d33c6351ae6f">copysignl</a> (long double x, long double y)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1622195256165628"><a name="p1622195256165628"></a><a name="p1622195256165628"></a>long double </p>
<p id="p1002161958165628"><a name="p1002161958165628"></a><a name="p1002161958165628"></a>Generates a value by combining the magnitude of the long double value <strong id="b1078541774165628"><a name="b1078541774165628"></a><a name="b1078541774165628"></a>x</strong> and the sign of the long double value <strong id="b1904718033165628"><a name="b1904718033165628"></a><a name="b1904718033165628"></a>y</strong>. </p>
</td>
</tr>
<tr id="row652695558165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1477617216165628"><a name="p1477617216165628"></a><a name="p1477617216165628"></a><a href="MATH.md#ga5e7b53a694b3cf0f2d7debd444140fbd">cos</a> (double x)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2099589156165628"><a name="p2099589156165628"></a><a name="p2099589156165628"></a>double </p>
<p id="p398750785165628"><a name="p398750785165628"></a><a name="p398750785165628"></a>Calculates the cosine of the double value <strong id="b10879742165628"><a name="b10879742165628"></a><a name="b10879742165628"></a>x</strong>. </p>
</td>
</tr>
<tr id="row989227909165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1780267592165628"><a name="p1780267592165628"></a><a name="p1780267592165628"></a><a href="MATH.md#ga7b126b2344591e649c21c9ab0b8adb40">cosf</a> (float x)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1259133080165628"><a name="p1259133080165628"></a><a name="p1259133080165628"></a>float </p>
<p id="p671137134165628"><a name="p671137134165628"></a><a name="p671137134165628"></a>Calculates the cosine of the float value <strong id="b648089092165628"><a name="b648089092165628"></a><a name="b648089092165628"></a>x</strong>. </p>
</td>
</tr>
<tr id="row1043339679165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p795010875165628"><a name="p795010875165628"></a><a name="p795010875165628"></a><a href="MATH.md#ga659287f7399efa8d6bc66dc37c8e35f4">cosl</a> (long double x)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p518048726165628"><a name="p518048726165628"></a><a name="p518048726165628"></a>long double </p>
<p id="p673649547165628"><a name="p673649547165628"></a><a name="p673649547165628"></a>Calculates the cosine of the long double value <strong id="b1879310746165628"><a name="b1879310746165628"></a><a name="b1879310746165628"></a>x</strong>. </p>
</td>
</tr>
<tr id="row708285072165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1958604549165628"><a name="p1958604549165628"></a><a name="p1958604549165628"></a><a href="MATH.md#ga3795d3c1f1d30819be56da4e4d67f64b">cosh</a> (double x)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1127798064165628"><a name="p1127798064165628"></a><a name="p1127798064165628"></a>double </p>
<p id="p439358971165628"><a name="p439358971165628"></a><a name="p439358971165628"></a>Calculates the hyperbolic cosine of the double value <strong id="b1838867720165628"><a name="b1838867720165628"></a><a name="b1838867720165628"></a>x</strong>. </p>
</td>
</tr>
<tr id="row411253844165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p798257766165628"><a name="p798257766165628"></a><a name="p798257766165628"></a><a href="MATH.md#ga498b368486b7ce8677820beeb78d8f66">coshf</a> (float x)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1465062887165628"><a name="p1465062887165628"></a><a name="p1465062887165628"></a>float </p>
<p id="p366081302165628"><a name="p366081302165628"></a><a name="p366081302165628"></a>Calculates the hyperbolic cosine of the float value <strong id="b2078122019165628"><a name="b2078122019165628"></a><a name="b2078122019165628"></a>x</strong>. </p>
</td>
</tr>
<tr id="row1442059007165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1717845065165628"><a name="p1717845065165628"></a><a name="p1717845065165628"></a><a href="MATH.md#ga57602cd20f8de2dceea4f05ffb516d82">coshl</a> (long double x)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p553497960165628"><a name="p553497960165628"></a><a name="p553497960165628"></a>long double </p>
<p id="p1467268397165628"><a name="p1467268397165628"></a><a name="p1467268397165628"></a>Calculates the hyperbolic cosine of the long double value <strong id="b106068384165628"><a name="b106068384165628"></a><a name="b106068384165628"></a>x</strong>. </p>
</td>
</tr>
<tr id="row1357796624165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1605749209165628"><a name="p1605749209165628"></a><a name="p1605749209165628"></a><a href="MATH.md#gaa8b35382a71885eed509a5f87bf5e266">erf</a> (double x)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p741928404165628"><a name="p741928404165628"></a><a name="p741928404165628"></a>double </p>
<p id="p423008822165628"><a name="p423008822165628"></a><a name="p423008822165628"></a>Calculates the error function of the double value <strong id="b893318498165628"><a name="b893318498165628"></a><a name="b893318498165628"></a>x</strong>. </p>
</td>
</tr>
<tr id="row334320998165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1245643084165628"><a name="p1245643084165628"></a><a name="p1245643084165628"></a><a href="MATH.md#gaabebdd2dd548c14805831297ac129862">erff</a> (float x)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p795582489165628"><a name="p795582489165628"></a><a name="p795582489165628"></a>float </p>
<p id="p428000733165628"><a name="p428000733165628"></a><a name="p428000733165628"></a>Calculates the error function of the float value <strong id="b457957483165628"><a name="b457957483165628"></a><a name="b457957483165628"></a>x</strong>. </p>
</td>
</tr>
<tr id="row1997587680165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1095620161165628"><a name="p1095620161165628"></a><a name="p1095620161165628"></a><a href="MATH.md#ga6ccdcbbc2f0b22de2add8955e415170e">erfl</a> (long double x)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p591124101165628"><a name="p591124101165628"></a><a name="p591124101165628"></a>long double </p>
<p id="p849399653165628"><a name="p849399653165628"></a><a name="p849399653165628"></a>Calculates the error function of the long double value <strong id="b957470277165628"><a name="b957470277165628"></a><a name="b957470277165628"></a>x</strong>. </p>
</td>
</tr>
<tr id="row671116770165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p495574973165628"><a name="p495574973165628"></a><a name="p495574973165628"></a><a href="MATH.md#ga0b6c4cfae41124da64c9a2dcc09e6045">erfc</a> (double x)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2100805570165628"><a name="p2100805570165628"></a><a name="p2100805570165628"></a>double </p>
<p id="p1173093177165628"><a name="p1173093177165628"></a><a name="p1173093177165628"></a>Calculates the complementary error function of the double value <strong id="b912376782165628"><a name="b912376782165628"></a><a name="b912376782165628"></a>x</strong>. </p>
</td>
</tr>
<tr id="row1820284352165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p753852272165628"><a name="p753852272165628"></a><a name="p753852272165628"></a><a href="MATH.md#gad948b9d3bfcb66c074ffe17326030d41">erfcf</a> (float x)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1661496802165628"><a name="p1661496802165628"></a><a name="p1661496802165628"></a>float </p>
<p id="p1059874907165628"><a name="p1059874907165628"></a><a name="p1059874907165628"></a>Calculates the complementary error function of the float value <strong id="b2024834468165628"><a name="b2024834468165628"></a><a name="b2024834468165628"></a>x</strong>. </p>
</td>
</tr>
<tr id="row856600970165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p812483975165628"><a name="p812483975165628"></a><a name="p812483975165628"></a><a href="MATH.md#ga8ac2c9e0246c0c8106d04762a9623594">erfcl</a> (long double x)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2007586822165628"><a name="p2007586822165628"></a><a name="p2007586822165628"></a>long double </p>
<p id="p1578701121165628"><a name="p1578701121165628"></a><a name="p1578701121165628"></a>Calculates the complementary error function of the long double value <strong id="b1204104987165628"><a name="b1204104987165628"></a><a name="b1204104987165628"></a>x</strong>. </p>
</td>
</tr>
<tr id="row529967872165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1251181314165628"><a name="p1251181314165628"></a><a name="p1251181314165628"></a><a href="MATH.md#gae09128febbbe6372cde4fa0c65608a42">exp</a> (double x)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p834972068165628"><a name="p834972068165628"></a><a name="p834972068165628"></a>double </p>
<p id="p898820768165628"><a name="p898820768165628"></a><a name="p898820768165628"></a>Calculates the base-e exponential function of the double value <strong id="b1248766183165628"><a name="b1248766183165628"></a><a name="b1248766183165628"></a>x</strong>. </p>
</td>
</tr>
<tr id="row309771513165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p93912873165628"><a name="p93912873165628"></a><a name="p93912873165628"></a><a href="MATH.md#ga0c2bc89b8355a89542ac98d9e2120363">expf</a> (float x)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1976599691165628"><a name="p1976599691165628"></a><a name="p1976599691165628"></a>float </p>
<p id="p1113319512165628"><a name="p1113319512165628"></a><a name="p1113319512165628"></a>Calculates the base-e exponential function of the float value <strong id="b1405066180165628"><a name="b1405066180165628"></a><a name="b1405066180165628"></a>x</strong>. </p>
</td>
</tr>
<tr id="row675403891165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1913095036165628"><a name="p1913095036165628"></a><a name="p1913095036165628"></a><a href="MATH.md#gaed4eb11ef1397c751334311ce5b43920">expl</a> (long double x)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1629479452165628"><a name="p1629479452165628"></a><a name="p1629479452165628"></a>long double </p>
<p id="p1584692477165628"><a name="p1584692477165628"></a><a name="p1584692477165628"></a>Calculates the base-e exponential function of the long double value <strong id="b1867125989165628"><a name="b1867125989165628"></a><a name="b1867125989165628"></a>x</strong>. </p>
</td>
</tr>
<tr id="row1697523980165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p155141147165628"><a name="p155141147165628"></a><a name="p155141147165628"></a><a href="MATH.md#ga86e37219434c0b7978453b6ca88fc5fb">exp2</a> (double x)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1893583478165628"><a name="p1893583478165628"></a><a name="p1893583478165628"></a>double </p>
<p id="p1552474080165628"><a name="p1552474080165628"></a><a name="p1552474080165628"></a>Calculates the base-2 exponential function of the double value <strong id="b20634392165628"><a name="b20634392165628"></a><a name="b20634392165628"></a>x</strong>. </p>
</td>
</tr>
<tr id="row1158904361165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1793322010165628"><a name="p1793322010165628"></a><a name="p1793322010165628"></a><a href="MATH.md#gaed26c6708ff2027f9a8214d206eef0e7">exp2f</a> (float x)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1764675264165628"><a name="p1764675264165628"></a><a name="p1764675264165628"></a>float </p>
<p id="p713063077165628"><a name="p713063077165628"></a><a name="p713063077165628"></a>Calculates the base-2 exponential function of the float value <strong id="b235924885165628"><a name="b235924885165628"></a><a name="b235924885165628"></a>x</strong>. </p>
</td>
</tr>
<tr id="row1916468161165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p35023204165628"><a name="p35023204165628"></a><a name="p35023204165628"></a><a href="MATH.md#ga4618e032de8318b72df5cc71f15b5e45">exp2l</a> (long double x)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p208766792165628"><a name="p208766792165628"></a><a name="p208766792165628"></a>long double </p>
<p id="p1931418975165628"><a name="p1931418975165628"></a><a name="p1931418975165628"></a>Calculates the base-2 exponential function of the long double value <strong id="b1729363135165628"><a name="b1729363135165628"></a><a name="b1729363135165628"></a>x</strong>. </p>
</td>
</tr>
<tr id="row155956287165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p709729687165628"><a name="p709729687165628"></a><a name="p709729687165628"></a><a href="MATH.md#gae4963ac40f96d4b1fe8af1b1e90a20bb">expm1</a> (double x)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1384448541165628"><a name="p1384448541165628"></a><a name="p1384448541165628"></a>double </p>
<p id="p385962439165628"><a name="p385962439165628"></a><a name="p385962439165628"></a>Calculates e raised to the power of the double value <strong id="b1659699526165628"><a name="b1659699526165628"></a><a name="b1659699526165628"></a>x</strong> minus one, that is, (e^x)-1. </p>
</td>
</tr>
<tr id="row1752956612165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1954893075165628"><a name="p1954893075165628"></a><a name="p1954893075165628"></a><a href="MATH.md#ga5b8d8815f5c801fdbdb7f7767fbf9af4">expm1f</a> (float x)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p366621163165628"><a name="p366621163165628"></a><a name="p366621163165628"></a>float </p>
<p id="p84849890165628"><a name="p84849890165628"></a><a name="p84849890165628"></a>Calculates e raised to the power of the float value <strong id="b883176826165628"><a name="b883176826165628"></a><a name="b883176826165628"></a>x</strong> minus one. </p>
</td>
</tr>
<tr id="row1891873824165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2069408130165628"><a name="p2069408130165628"></a><a name="p2069408130165628"></a><a href="MATH.md#ga702b0680671cf9ef94017ac04f77358b">expm1l</a> (long double x)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p778784098165628"><a name="p778784098165628"></a><a name="p778784098165628"></a>long double </p>
<p id="p414740991165628"><a name="p414740991165628"></a><a name="p414740991165628"></a>Calculates e raised to the power of the long double value <strong id="b761924674165628"><a name="b761924674165628"></a><a name="b761924674165628"></a>x</strong> minus one. </p>
</td>
</tr>
<tr id="row664314930165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p369925376165628"><a name="p369925376165628"></a><a name="p369925376165628"></a><a href="MATH.md#ga8fb5c0b9b43a108724b355136d29d2f9">fabs</a> (double x)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2021948584165628"><a name="p2021948584165628"></a><a name="p2021948584165628"></a>double </p>
<p id="p1058404294165628"><a name="p1058404294165628"></a><a name="p1058404294165628"></a>Calculates the absolute value of the double value <strong id="b1741776312165628"><a name="b1741776312165628"></a><a name="b1741776312165628"></a>x</strong>. </p>
</td>
</tr>
<tr id="row1689353007165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1344646995165628"><a name="p1344646995165628"></a><a name="p1344646995165628"></a><a href="MATH.md#ga9b02e2f3ebf257ac4f4d3ca1da6147d7">fabsf</a> (float x)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p347621351165628"><a name="p347621351165628"></a><a name="p347621351165628"></a>float </p>
<p id="p1061148274165628"><a name="p1061148274165628"></a><a name="p1061148274165628"></a>Calculates the absolute value of the float value <strong id="b1013585298165628"><a name="b1013585298165628"></a><a name="b1013585298165628"></a>x</strong>. </p>
</td>
</tr>
<tr id="row13379711165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1923663289165628"><a name="p1923663289165628"></a><a name="p1923663289165628"></a><a href="MATH.md#ga404c051ab9afd74c7ceed207683a235f">fabsl</a> (long double x)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p17976790165628"><a name="p17976790165628"></a><a name="p17976790165628"></a>long double </p>
<p id="p1223647462165628"><a name="p1223647462165628"></a><a name="p1223647462165628"></a>Calculates the absolute value of the long double value <strong id="b1895901467165628"><a name="b1895901467165628"></a><a name="b1895901467165628"></a>x</strong>. </p>
</td>
</tr>
<tr id="row1928941290165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p531454145165628"><a name="p531454145165628"></a><a name="p531454145165628"></a><a href="MATH.md#ga800522810eaaed28bd53798bff4b0bfa">fdim</a> (double x, double y)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1983813063165628"><a name="p1983813063165628"></a><a name="p1983813063165628"></a>double </p>
<p id="p126250622165628"><a name="p126250622165628"></a><a name="p126250622165628"></a>Calculates the positive difference between the double value <strong id="b1847404574165628"><a name="b1847404574165628"></a><a name="b1847404574165628"></a>x</strong> and <strong id="b1703887650165628"><a name="b1703887650165628"></a><a name="b1703887650165628"></a>y</strong>. </p>
</td>
</tr>
<tr id="row1571911834165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p242441005165628"><a name="p242441005165628"></a><a name="p242441005165628"></a><a href="MATH.md#gaeee3a0bf2804c53c65199590ac4804cf">fdimf</a> (float x, float y)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1303027397165628"><a name="p1303027397165628"></a><a name="p1303027397165628"></a>float </p>
<p id="p545326803165628"><a name="p545326803165628"></a><a name="p545326803165628"></a>Calculates the positive difference between the float value <strong id="b1226938701165628"><a name="b1226938701165628"></a><a name="b1226938701165628"></a>x</strong> and <strong id="b1448351025165628"><a name="b1448351025165628"></a><a name="b1448351025165628"></a>y</strong>. </p>
</td>
</tr>
<tr id="row1123228067165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2011892404165628"><a name="p2011892404165628"></a><a name="p2011892404165628"></a><a href="MATH.md#gab88ba65d1861deddbbc5cb5384d6a02e">fdiml</a> (long double x, long double y)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1857730102165628"><a name="p1857730102165628"></a><a name="p1857730102165628"></a>long double </p>
<p id="p891305327165628"><a name="p891305327165628"></a><a name="p891305327165628"></a>Calculates the positive difference between the long double value <strong id="b653532058165628"><a name="b653532058165628"></a><a name="b653532058165628"></a>x</strong> and <strong id="b1953481339165628"><a name="b1953481339165628"></a><a name="b1953481339165628"></a>y</strong>. </p>
</td>
</tr>
<tr id="row989483809165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1263214526165628"><a name="p1263214526165628"></a><a name="p1263214526165628"></a><a href="MATH.md#ga6de60a3e907dcf0bfe3ea8d64f1e8873">floor</a> (double x)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1665709580165628"><a name="p1665709580165628"></a><a name="p1665709580165628"></a>double </p>
<p id="p1551471857165628"><a name="p1551471857165628"></a><a name="p1551471857165628"></a>Obtains the largest integer less than or equal to the double value <strong id="b435308803165628"><a name="b435308803165628"></a><a name="b435308803165628"></a>x</strong>. </p>
</td>
</tr>
<tr id="row537510871165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1915205930165628"><a name="p1915205930165628"></a><a name="p1915205930165628"></a><a href="MATH.md#ga0bcc6aa4b3c37bfa73f06ebdecc0d247">floorf</a> (float x)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p332478081165628"><a name="p332478081165628"></a><a name="p332478081165628"></a>float </p>
<p id="p1327248875165628"><a name="p1327248875165628"></a><a name="p1327248875165628"></a>Obtains the largest integer less than or equal to the float value <strong id="b2115976942165628"><a name="b2115976942165628"></a><a name="b2115976942165628"></a>x</strong>. </p>
</td>
</tr>
<tr id="row405904441165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1627415212165628"><a name="p1627415212165628"></a><a name="p1627415212165628"></a><a href="MATH.md#ga211df53cdf5208b9bbfa92e2d9aef97f">floorl</a> (long double x)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p678948625165628"><a name="p678948625165628"></a><a name="p678948625165628"></a>long double </p>
<p id="p550667019165628"><a name="p550667019165628"></a><a name="p550667019165628"></a>Obtains the largest integer less than or equal to the long double value <strong id="b978079021165628"><a name="b978079021165628"></a><a name="b978079021165628"></a>x</strong>. </p>
</td>
</tr>
<tr id="row2080445093165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1743432311165628"><a name="p1743432311165628"></a><a name="p1743432311165628"></a><a href="MATH.md#gac6df7bd41d198a70da3915a80de5452d">fma</a> (double x, double y, double z)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1719346279165628"><a name="p1719346279165628"></a><a name="p1719346279165628"></a>double </p>
<p id="p703838161165628"><a name="p703838161165628"></a><a name="p703838161165628"></a>Calculates the value of <strong id="b1136374437165628"><a name="b1136374437165628"></a><a name="b1136374437165628"></a>x*y+z</strong> and rounds the result up. </p>
</td>
</tr>
<tr id="row1695514438165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1865483848165628"><a name="p1865483848165628"></a><a name="p1865483848165628"></a><a href="MATH.md#gaa6b32a0b7f88680bb59bcfb9c6168ed2">fmaf</a> (float x, float y, float z)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1480576675165628"><a name="p1480576675165628"></a><a name="p1480576675165628"></a>float </p>
<p id="p2108825517165628"><a name="p2108825517165628"></a><a name="p2108825517165628"></a>Calculates the value of <strong id="b1483285714165628"><a name="b1483285714165628"></a><a name="b1483285714165628"></a>x*y+z</strong> and rounds the result up. </p>
</td>
</tr>
<tr id="row1124564329165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1826887258165628"><a name="p1826887258165628"></a><a name="p1826887258165628"></a><a href="MATH.md#gaf30b6b26252979964796ffa55dd30120">fmal</a> (long double x, long double y, long double z)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1267623127165628"><a name="p1267623127165628"></a><a name="p1267623127165628"></a>long double </p>
<p id="p1940932233165628"><a name="p1940932233165628"></a><a name="p1940932233165628"></a>Calculates the value of <strong id="b2062982984165628"><a name="b2062982984165628"></a><a name="b2062982984165628"></a>x*y+z</strong> and rounds the result up. </p>
</td>
</tr>
<tr id="row1655834168165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p755328829165628"><a name="p755328829165628"></a><a name="p755328829165628"></a><a href="MATH.md#ga35e041615ac931b4d848a7b173049301">fmax</a> (double x, double y)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p163517373165628"><a name="p163517373165628"></a><a name="p163517373165628"></a>double </p>
<p id="p182296347165628"><a name="p182296347165628"></a><a name="p182296347165628"></a>Obtains the larger value of two double values <strong id="b1978479022165628"><a name="b1978479022165628"></a><a name="b1978479022165628"></a>x</strong> and <strong id="b756399974165628"><a name="b756399974165628"></a><a name="b756399974165628"></a>y</strong>. </p>
</td>
</tr>
<tr id="row1283301385165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p828252677165628"><a name="p828252677165628"></a><a name="p828252677165628"></a><a href="MATH.md#ga8849bfdbec18ded429fad4772cf60f4b">fmaxf</a> (float x, float y)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p252265812165628"><a name="p252265812165628"></a><a name="p252265812165628"></a>float </p>
<p id="p1324867849165628"><a name="p1324867849165628"></a><a name="p1324867849165628"></a>Obtains the larger value of two float values <strong id="b465089473165628"><a name="b465089473165628"></a><a name="b465089473165628"></a>x</strong> and <strong id="b1997293025165628"><a name="b1997293025165628"></a><a name="b1997293025165628"></a>y</strong>. </p>
</td>
</tr>
<tr id="row711431192165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p806992238165628"><a name="p806992238165628"></a><a name="p806992238165628"></a><a href="MATH.md#ga0e31e170115494fdc03b6556844232f3">fmaxl</a> (long double x, long double y)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1603995778165628"><a name="p1603995778165628"></a><a name="p1603995778165628"></a>long double </p>
<p id="p464180721165628"><a name="p464180721165628"></a><a name="p464180721165628"></a>Obtains the larger value of two long double values <strong id="b813193565165628"><a name="b813193565165628"></a><a name="b813193565165628"></a>x</strong> and <strong id="b1822107478165628"><a name="b1822107478165628"></a><a name="b1822107478165628"></a>y</strong>. </p>
</td>
</tr>
<tr id="row290168635165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1661651984165628"><a name="p1661651984165628"></a><a name="p1661651984165628"></a><a href="MATH.md#gaf0a18b3ac9e461ac48b4cfffb4945a84">fmin</a> (double x, double y)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p690606496165628"><a name="p690606496165628"></a><a name="p690606496165628"></a>double </p>
<p id="p898111706165628"><a name="p898111706165628"></a><a name="p898111706165628"></a>Obtains the smaller value of two double values <strong id="b131682746165628"><a name="b131682746165628"></a><a name="b131682746165628"></a>x</strong> and <strong id="b1850116060165628"><a name="b1850116060165628"></a><a name="b1850116060165628"></a>y</strong>. </p>
</td>
</tr>
<tr id="row173504528165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p160099815165628"><a name="p160099815165628"></a><a name="p160099815165628"></a><a href="MATH.md#ga9b4132c27f31d39c91c3c6063f378103">fminf</a> (float x, float y)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1924004657165628"><a name="p1924004657165628"></a><a name="p1924004657165628"></a>float </p>
<p id="p1143035786165628"><a name="p1143035786165628"></a><a name="p1143035786165628"></a>Obtains the smaller value of two float values <strong id="b1520275324165628"><a name="b1520275324165628"></a><a name="b1520275324165628"></a>x</strong> and <strong id="b474800374165628"><a name="b474800374165628"></a><a name="b474800374165628"></a>y</strong>. </p>
</td>
</tr>
<tr id="row2021144724165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1255041330165628"><a name="p1255041330165628"></a><a name="p1255041330165628"></a><a href="MATH.md#ga8a301190384886aa4e327db265fb5c9f">fminl</a> (long double x, long double y)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1694453996165628"><a name="p1694453996165628"></a><a name="p1694453996165628"></a>long double </p>
<p id="p2034088900165628"><a name="p2034088900165628"></a><a name="p2034088900165628"></a>Obtains the smaller value of two long double values <strong id="b1694382914165628"><a name="b1694382914165628"></a><a name="b1694382914165628"></a>x</strong> and <strong id="b1722588149165628"><a name="b1722588149165628"></a><a name="b1722588149165628"></a>y</strong>. </p>
</td>
</tr>
<tr id="row1556902425165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1107148040165628"><a name="p1107148040165628"></a><a name="p1107148040165628"></a><a href="MATH.md#ga537296d1a8f9fb621676038b99ba7edf">fmod</a> (double x, double y)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1123334841165628"><a name="p1123334841165628"></a><a name="p1123334841165628"></a>double </p>
<p id="p1927119584165628"><a name="p1927119584165628"></a><a name="p1927119584165628"></a>Calculates the remainder of the double value <strong id="b343136000165628"><a name="b343136000165628"></a><a name="b343136000165628"></a>x</strong> divided by the double value <strong id="b1734545949165628"><a name="b1734545949165628"></a><a name="b1734545949165628"></a>y</strong>. </p>
</td>
</tr>
<tr id="row1362066263165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1408072789165628"><a name="p1408072789165628"></a><a name="p1408072789165628"></a><a href="MATH.md#gaf17ec425baca2b5f3882a05b5e19dfb5">fmodf</a> (float x, float y)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p106143790165628"><a name="p106143790165628"></a><a name="p106143790165628"></a>float </p>
<p id="p576785112165628"><a name="p576785112165628"></a><a name="p576785112165628"></a>Calculates the remainder of the float value <strong id="b1037937675165628"><a name="b1037937675165628"></a><a name="b1037937675165628"></a>x</strong> divided by the float value <strong id="b625001303165628"><a name="b625001303165628"></a><a name="b625001303165628"></a>y</strong>. </p>
</td>
</tr>
<tr id="row806689028165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p178843593165628"><a name="p178843593165628"></a><a name="p178843593165628"></a><a href="MATH.md#gaa927d9996fb40db42bd3a6cbe57da9a7">fmodl</a> (long double x, long double y)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1332657807165628"><a name="p1332657807165628"></a><a name="p1332657807165628"></a>long double </p>
<p id="p1176639578165628"><a name="p1176639578165628"></a><a name="p1176639578165628"></a>Calculates the remainder of the long double value <strong id="b349406926165628"><a name="b349406926165628"></a><a name="b349406926165628"></a>x</strong> divided by the long double value <strong id="b1891023683165628"><a name="b1891023683165628"></a><a name="b1891023683165628"></a>y</strong>. </p>
</td>
</tr>
<tr id="row534305649165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2143038087165628"><a name="p2143038087165628"></a><a name="p2143038087165628"></a><a href="MATH.md#gae3fa88adf02f16a693f3dccea3c42ef0">frexp</a> (double x, int *<a href="MATH.md#gae09128febbbe6372cde4fa0c65608a42">exp</a>)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1497680733165628"><a name="p1497680733165628"></a><a name="p1497680733165628"></a>double </p>
<p id="p1968396691165628"><a name="p1968396691165628"></a><a name="p1968396691165628"></a>Decomposes the double value <strong id="b866145602165628"><a name="b866145602165628"></a><a name="b866145602165628"></a>x</strong> into a significand and an integral exponent for 2. </p>
</td>
</tr>
<tr id="row390027066165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p965776488165628"><a name="p965776488165628"></a><a name="p965776488165628"></a><a href="MATH.md#ga12c36e745d8a9eb4f01c7e0eeb426dd3">frexpf</a> (float x, int *<a href="MATH.md#gae09128febbbe6372cde4fa0c65608a42">exp</a>)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1654963574165628"><a name="p1654963574165628"></a><a name="p1654963574165628"></a>float </p>
<p id="p1261744064165628"><a name="p1261744064165628"></a><a name="p1261744064165628"></a>Decomposes float value <strong id="b1698268640165628"><a name="b1698268640165628"></a><a name="b1698268640165628"></a>x</strong> into a binary significand and an integral exponent for 2. </p>
</td>
</tr>
<tr id="row1427871617165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p213052420165628"><a name="p213052420165628"></a><a name="p213052420165628"></a><a href="MATH.md#ga239d50c0595ff8538b9aa3186ac4fd29">frexpl</a> (long double x, int *<a href="MATH.md#gae09128febbbe6372cde4fa0c65608a42">exp</a>)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1354220239165628"><a name="p1354220239165628"></a><a name="p1354220239165628"></a>long double </p>
<p id="p481155604165628"><a name="p481155604165628"></a><a name="p481155604165628"></a>Decomposes long double value <strong id="b506987085165628"><a name="b506987085165628"></a><a name="b506987085165628"></a>x</strong> into a binary significand and an integral exponent for 2. </p>
</td>
</tr>
<tr id="row389762259165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1906476547165628"><a name="p1906476547165628"></a><a name="p1906476547165628"></a><a href="MATH.md#ga6d6a905f61d535f8454190433b8c0ea5">hypot</a> (double x, double y)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2136786273165628"><a name="p2136786273165628"></a><a name="p2136786273165628"></a>double </p>
<p id="p1003769058165628"><a name="p1003769058165628"></a><a name="p1003769058165628"></a>Calculates the hypotenuse of a right triangle whose legs are <strong id="b1475917647165628"><a name="b1475917647165628"></a><a name="b1475917647165628"></a>x</strong> and <strong id="b522221809165628"><a name="b522221809165628"></a><a name="b522221809165628"></a>y</strong>. </p>
</td>
</tr>
<tr id="row1125225816165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1428429581165628"><a name="p1428429581165628"></a><a name="p1428429581165628"></a><a href="MATH.md#ga9fa4a03d7c4abfda7d9ad7b6ff7f6456">hypotf</a> (float x, float y)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2067943482165628"><a name="p2067943482165628"></a><a name="p2067943482165628"></a>float </p>
<p id="p1929714673165628"><a name="p1929714673165628"></a><a name="p1929714673165628"></a>Calculates the hypotenuse of a right triangle whose legs are <strong id="b1917689556165628"><a name="b1917689556165628"></a><a name="b1917689556165628"></a>x</strong> and <strong id="b823804685165628"><a name="b823804685165628"></a><a name="b823804685165628"></a>y</strong>. </p>
</td>
</tr>
<tr id="row2129341702165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1289929080165628"><a name="p1289929080165628"></a><a name="p1289929080165628"></a><a href="MATH.md#ga92a0e76d17c34fc1b3b2e7c0868aea6e">hypotl</a> (long double x, long double y)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p208657800165628"><a name="p208657800165628"></a><a name="p208657800165628"></a>long double </p>
<p id="p67186198165628"><a name="p67186198165628"></a><a name="p67186198165628"></a>Calculates the hypotenuse of a right triangle whose legs are <strong id="b1838236460165628"><a name="b1838236460165628"></a><a name="b1838236460165628"></a>x</strong> and <strong id="b288065305165628"><a name="b288065305165628"></a><a name="b288065305165628"></a>y</strong>. </p>
</td>
</tr>
<tr id="row472896713165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p101909169165628"><a name="p101909169165628"></a><a name="p101909169165628"></a><a href="MATH.md#ga600dd249210d15af31b9a29c2d09d255">ilogb</a> (double x)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1068928779165628"><a name="p1068928779165628"></a><a name="p1068928779165628"></a>int </p>
<p id="p1106493072165628"><a name="p1106493072165628"></a><a name="p1106493072165628"></a>Obtains the integral part of the logarithm of double value <strong id="b1966524951165628"><a name="b1966524951165628"></a><a name="b1966524951165628"></a>x</strong>. </p>
</td>
</tr>
<tr id="row1782817535165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p549050234165628"><a name="p549050234165628"></a><a name="p549050234165628"></a><a href="MATH.md#gaf53f0f07bb80b1a38fb47773a190e7a7">ilogbf</a> (float x)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p458238417165628"><a name="p458238417165628"></a><a name="p458238417165628"></a>int </p>
<p id="p596116009165628"><a name="p596116009165628"></a><a name="p596116009165628"></a>Obtains the integral part of the logarithm of float value <strong id="b1381486589165628"><a name="b1381486589165628"></a><a name="b1381486589165628"></a>x</strong>. </p>
</td>
</tr>
<tr id="row1225827892165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1837198943165628"><a name="p1837198943165628"></a><a name="p1837198943165628"></a><a href="MATH.md#gafbd166ed232a372f090b8f9fa8441423">ilogbl</a> (long double x)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1692381125165628"><a name="p1692381125165628"></a><a name="p1692381125165628"></a>int </p>
<p id="p1893029839165628"><a name="p1893029839165628"></a><a name="p1893029839165628"></a>Obtains the integral part of the logarithm of the long double value <strong id="b1260430828165628"><a name="b1260430828165628"></a><a name="b1260430828165628"></a>x</strong>. </p>
</td>
</tr>
<tr id="row205581233165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p115426945165628"><a name="p115426945165628"></a><a name="p115426945165628"></a><a href="MATH.md#gab3662815756f0bd419dc1b12f4ad905d">ldexp</a> (double x, int <a href="MATH.md#gae09128febbbe6372cde4fa0c65608a42">exp</a>)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p652059544165628"><a name="p652059544165628"></a><a name="p652059544165628"></a>double </p>
<p id="p697280121165628"><a name="p697280121165628"></a><a name="p697280121165628"></a>Multiplies the double value <strong id="b1411700755165628"><a name="b1411700755165628"></a><a name="b1411700755165628"></a>x</strong> by 2 raised to the power of <strong id="b1393355795165628"><a name="b1393355795165628"></a><a name="b1393355795165628"></a>exp</strong>. </p>
</td>
</tr>
<tr id="row865815929165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1950061310165628"><a name="p1950061310165628"></a><a name="p1950061310165628"></a><a href="MATH.md#gaacd370a7830c29f47239dea1ea2eb7f9">ldexpf</a> (float x, int <a href="MATH.md#gae09128febbbe6372cde4fa0c65608a42">exp</a>)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p314644324165628"><a name="p314644324165628"></a><a name="p314644324165628"></a>float </p>
<p id="p1492810581165628"><a name="p1492810581165628"></a><a name="p1492810581165628"></a>Multiplies the float value <strong id="b2054641591165628"><a name="b2054641591165628"></a><a name="b2054641591165628"></a>x</strong> by 2 raised to the power of <strong id="b952631895165628"><a name="b952631895165628"></a><a name="b952631895165628"></a>exp</strong>. </p>
</td>
</tr>
<tr id="row743095350165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1036222793165628"><a name="p1036222793165628"></a><a name="p1036222793165628"></a><a href="MATH.md#ga454187039ef790629dab1e7724c3c3b2">ldexpl</a> (long double x, int <a href="MATH.md#gae09128febbbe6372cde4fa0c65608a42">exp</a>)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1625409302165628"><a name="p1625409302165628"></a><a name="p1625409302165628"></a>long double </p>
<p id="p807886411165628"><a name="p807886411165628"></a><a name="p807886411165628"></a>Multiplies the long double value <strong id="b619207263165628"><a name="b619207263165628"></a><a name="b619207263165628"></a>x</strong> by 2 raised to the power of <strong id="b1754558875165628"><a name="b1754558875165628"></a><a name="b1754558875165628"></a>exp</strong>. </p>
</td>
</tr>
<tr id="row2049843090165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2027886826165628"><a name="p2027886826165628"></a><a name="p2027886826165628"></a><a href="MATH.md#gacd3ebe923fa039624f0b7de3320816bf">lgamma</a> (double x)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1762805891165628"><a name="p1762805891165628"></a><a name="p1762805891165628"></a>double </p>
<p id="p1116039238165628"><a name="p1116039238165628"></a><a name="p1116039238165628"></a>Calculates the natural logarithm of the absolute value of the gamma function of the double value <strong id="b1692760210165628"><a name="b1692760210165628"></a><a name="b1692760210165628"></a>x</strong>. </p>
</td>
</tr>
<tr id="row416856424165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p58191658165628"><a name="p58191658165628"></a><a name="p58191658165628"></a><a href="MATH.md#ga5900f7bf0093757f1ba36b5940b1e10b">lgammaf</a> (float x)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p108884105165628"><a name="p108884105165628"></a><a name="p108884105165628"></a>float </p>
<p id="p842897195165628"><a name="p842897195165628"></a><a name="p842897195165628"></a>Calculates the natural logarithm of the absolute value of the gamma function of the float value <strong id="b560763288165628"><a name="b560763288165628"></a><a name="b560763288165628"></a>x</strong>. </p>
</td>
</tr>
<tr id="row1985828790165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1943693286165628"><a name="p1943693286165628"></a><a name="p1943693286165628"></a><a href="MATH.md#ga4dafd3eb6952c8daabe8a98f4a64a7df">lgammal</a> (long double x)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1959854655165628"><a name="p1959854655165628"></a><a name="p1959854655165628"></a>long double </p>
<p id="p1261134321165628"><a name="p1261134321165628"></a><a name="p1261134321165628"></a>Calculates the natural logarithm of the absolute value of the gamma function of the long double value <strong id="b2056554938165628"><a name="b2056554938165628"></a><a name="b2056554938165628"></a>x</strong>. </p>
</td>
</tr>
<tr id="row889819333165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1370980861165628"><a name="p1370980861165628"></a><a name="p1370980861165628"></a><a href="MATH.md#ga64a4201c82f6ee7043a270bbbc6a5e19">llrint</a> (double x)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p416985190165628"><a name="p416985190165628"></a><a name="p416985190165628"></a>long long int </p>
<p id="p191445049165628"><a name="p191445049165628"></a><a name="p191445049165628"></a>Rounds double value <strong id="b350868777165628"><a name="b350868777165628"></a><a name="b350868777165628"></a>x</strong> to the nearest integer. </p>
</td>
</tr>
<tr id="row1004275708165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p24640254165628"><a name="p24640254165628"></a><a name="p24640254165628"></a><a href="MATH.md#ga33d95711621def731d3f88c4e606323e">llrintf</a> (float x)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p568193961165628"><a name="p568193961165628"></a><a name="p568193961165628"></a>long long int </p>
<p id="p902347377165628"><a name="p902347377165628"></a><a name="p902347377165628"></a>Rounds float value <strong id="b1567596191165628"><a name="b1567596191165628"></a><a name="b1567596191165628"></a>x</strong> to the nearest integer. </p>
</td>
</tr>
<tr id="row414079245165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1401421481165628"><a name="p1401421481165628"></a><a name="p1401421481165628"></a><a href="MATH.md#ga20e0da115f76608eff4695177f2f605a">llrintl</a> (long double x)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2087788803165628"><a name="p2087788803165628"></a><a name="p2087788803165628"></a>long long int </p>
<p id="p1547586248165628"><a name="p1547586248165628"></a><a name="p1547586248165628"></a>Rounds long double value <strong id="b1831490754165628"><a name="b1831490754165628"></a><a name="b1831490754165628"></a>x</strong> to the nearest integer. </p>
</td>
</tr>
<tr id="row1211769024165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1412254144165628"><a name="p1412254144165628"></a><a name="p1412254144165628"></a><a href="MATH.md#ga3e4957daeecea4e616ed1f1870fe4f31">llround</a> (double x)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1237020190165628"><a name="p1237020190165628"></a><a name="p1237020190165628"></a>long long int </p>
<p id="p717618802165628"><a name="p717618802165628"></a><a name="p717618802165628"></a>Rounds double value <strong id="b27020166165628"><a name="b27020166165628"></a><a name="b27020166165628"></a>x</strong> to the nearest integer, rounding away from <strong id="b2120619129165628"><a name="b2120619129165628"></a><a name="b2120619129165628"></a>0</strong>. </p>
</td>
</tr>
<tr id="row40463274165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2081807478165628"><a name="p2081807478165628"></a><a name="p2081807478165628"></a><a href="MATH.md#ga8259999687e8bd4b5509ca0d69b0ad9d">llroundf</a> (float x)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1111261962165628"><a name="p1111261962165628"></a><a name="p1111261962165628"></a>long long int </p>
<p id="p1702320219165628"><a name="p1702320219165628"></a><a name="p1702320219165628"></a>Rounds float value <strong id="b781213455165628"><a name="b781213455165628"></a><a name="b781213455165628"></a>x</strong> to the nearest integer, rounding away from <strong id="b2121445942165628"><a name="b2121445942165628"></a><a name="b2121445942165628"></a>0</strong>. </p>
</td>
</tr>
<tr id="row1547708158165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1376618505165628"><a name="p1376618505165628"></a><a name="p1376618505165628"></a><a href="MATH.md#ga82a6d70a29e839514b93bb0699f07bbe">llroundl</a> (long double x)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p236176460165628"><a name="p236176460165628"></a><a name="p236176460165628"></a>long long int </p>
<p id="p617057733165628"><a name="p617057733165628"></a><a name="p617057733165628"></a>Rounds long double value <strong id="b1678248443165628"><a name="b1678248443165628"></a><a name="b1678248443165628"></a>x</strong> to the nearest integer, rounding away from <strong id="b552540732165628"><a name="b552540732165628"></a><a name="b552540732165628"></a>0</strong>. </p>
</td>
</tr>
<tr id="row340690350165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p738514623165628"><a name="p738514623165628"></a><a name="p738514623165628"></a><a href="MATH.md#gadb302c9aafbaa5e180d9f60ee954bb82">log</a> (double x)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2122649278165628"><a name="p2122649278165628"></a><a name="p2122649278165628"></a>double </p>
<p id="p997178717165628"><a name="p997178717165628"></a><a name="p997178717165628"></a>Calculates the natural logarithm of the double value <strong id="b195481949165628"><a name="b195481949165628"></a><a name="b195481949165628"></a>x</strong>. </p>
</td>
</tr>
<tr id="row2128296309165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p322519247165628"><a name="p322519247165628"></a><a name="p322519247165628"></a><a href="MATH.md#ga8246b3e17a39b137d0c62670d0c6e336">logf</a> (float x)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2134230645165628"><a name="p2134230645165628"></a><a name="p2134230645165628"></a>float </p>
<p id="p1482029889165628"><a name="p1482029889165628"></a><a name="p1482029889165628"></a>Calculates the natural logarithm of the float value <strong id="b1423214253165628"><a name="b1423214253165628"></a><a name="b1423214253165628"></a>x</strong>. </p>
</td>
</tr>
<tr id="row1056293197165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1023745178165628"><a name="p1023745178165628"></a><a name="p1023745178165628"></a><a href="MATH.md#gaf67da1c28ce33b403f955103f201dfb8">logl</a> (long double x)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p489184679165628"><a name="p489184679165628"></a><a name="p489184679165628"></a>long double </p>
<p id="p1718068146165628"><a name="p1718068146165628"></a><a name="p1718068146165628"></a>Calculates the natural logarithm of the long double value <strong id="b381508777165628"><a name="b381508777165628"></a><a name="b381508777165628"></a>x</strong>. </p>
</td>
</tr>
<tr id="row1012105449165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p531855932165628"><a name="p531855932165628"></a><a name="p531855932165628"></a><a href="MATH.md#ga6572e82a4891917a9ba7fb2a964f8182">log10</a> (double x)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p163408623165628"><a name="p163408623165628"></a><a name="p163408623165628"></a>double </p>
<p id="p1334446063165628"><a name="p1334446063165628"></a><a name="p1334446063165628"></a>Calculates the common logarithm (logarithm with base 10) of the double value <strong id="b516455641165628"><a name="b516455641165628"></a><a name="b516455641165628"></a>x</strong>. </p>
</td>
</tr>
<tr id="row1214224194165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1003580889165628"><a name="p1003580889165628"></a><a name="p1003580889165628"></a><a href="MATH.md#gae207b1eb007a6c23394dcb6fc7f16adf">log10f</a> (float x)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1436560141165628"><a name="p1436560141165628"></a><a name="p1436560141165628"></a>float </p>
<p id="p1632415543165628"><a name="p1632415543165628"></a><a name="p1632415543165628"></a>Calculates the common logarithm (logarithm with base 10) of the float value <strong id="b244523194165628"><a name="b244523194165628"></a><a name="b244523194165628"></a>x</strong>. </p>
</td>
</tr>
<tr id="row266100409165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1006293209165628"><a name="p1006293209165628"></a><a name="p1006293209165628"></a><a href="MATH.md#gae824e49a04221dcf66b9791c5df8d6b6">log10l</a> (long double x)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p519503818165628"><a name="p519503818165628"></a><a name="p519503818165628"></a>long double </p>
<p id="p1289479556165628"><a name="p1289479556165628"></a><a name="p1289479556165628"></a>Calculates the common logarithm (logarithm with base 10) of the long double value <strong id="b1677062073165628"><a name="b1677062073165628"></a><a name="b1677062073165628"></a>x</strong>. </p>
</td>
</tr>
<tr id="row1473580852165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p990341562165628"><a name="p990341562165628"></a><a name="p990341562165628"></a><a href="MATH.md#gac2aac20ab1347498e6e4f209148fea84">log1p</a> (double x)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p662061626165628"><a name="p662061626165628"></a><a name="p662061626165628"></a>double </p>
<p id="p436404614165628"><a name="p436404614165628"></a><a name="p436404614165628"></a>Calculates the natural logarithm of one plus the double value <strong id="b1694727366165628"><a name="b1694727366165628"></a><a name="b1694727366165628"></a>x</strong>. </p>
</td>
</tr>
<tr id="row415365159165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1355535091165628"><a name="p1355535091165628"></a><a name="p1355535091165628"></a><a href="MATH.md#gacbf820b74779ce35a3c726a3a62bc8ef">log1pf</a> (float x)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1351447801165628"><a name="p1351447801165628"></a><a name="p1351447801165628"></a>float </p>
<p id="p1026278050165628"><a name="p1026278050165628"></a><a name="p1026278050165628"></a>Calculates the natural logarithm of one plus the float value <strong id="b744738454165628"><a name="b744738454165628"></a><a name="b744738454165628"></a>x</strong>. </p>
</td>
</tr>
<tr id="row1810548726165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1508485262165628"><a name="p1508485262165628"></a><a name="p1508485262165628"></a><a href="MATH.md#ga2a632effaace01f30cba42725ae48dfa">log1pl</a> (long double x)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p245229336165628"><a name="p245229336165628"></a><a name="p245229336165628"></a>long double </p>
<p id="p702328506165628"><a name="p702328506165628"></a><a name="p702328506165628"></a>Calculates the natural logarithm of one plus the long double value <strong id="b516214730165628"><a name="b516214730165628"></a><a name="b516214730165628"></a>x</strong>. </p>
</td>
</tr>
<tr id="row237706948165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p343637584165628"><a name="p343637584165628"></a><a name="p343637584165628"></a><a href="MATH.md#ga38bd88274dc5594b4826fd60c8054c8e">log2</a> (double x)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p448200409165628"><a name="p448200409165628"></a><a name="p448200409165628"></a>double </p>
<p id="p1114035137165628"><a name="p1114035137165628"></a><a name="p1114035137165628"></a>Calculates the binary logarithm (logarithm with base 2) of the double value <strong id="b1782083947165628"><a name="b1782083947165628"></a><a name="b1782083947165628"></a>x</strong>. </p>
</td>
</tr>
<tr id="row938171989165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p123218737165628"><a name="p123218737165628"></a><a name="p123218737165628"></a><a href="MATH.md#ga79fe62234001b88317245f7599158aaf">log2f</a> (float x)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1515398184165628"><a name="p1515398184165628"></a><a name="p1515398184165628"></a>float </p>
<p id="p2042827669165628"><a name="p2042827669165628"></a><a name="p2042827669165628"></a>Calculates the binary logarithm (logarithm with base 2) of the float value <strong id="b1111421862165628"><a name="b1111421862165628"></a><a name="b1111421862165628"></a>x</strong>. </p>
</td>
</tr>
<tr id="row710507038165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1861305646165628"><a name="p1861305646165628"></a><a name="p1861305646165628"></a><a href="MATH.md#gaa383ae0cab6c24f1bcba661dee0fbd70">log2l</a> (long double x)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2048728491165628"><a name="p2048728491165628"></a><a name="p2048728491165628"></a>long double </p>
<p id="p336051141165628"><a name="p336051141165628"></a><a name="p336051141165628"></a>Calculates the binary logarithm (logarithm with base 2) of the long double value <strong id="b1527838238165628"><a name="b1527838238165628"></a><a name="b1527838238165628"></a>x</strong>. </p>
</td>
</tr>
<tr id="row815593531165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p870686218165628"><a name="p870686218165628"></a><a name="p870686218165628"></a><a href="MATH.md#gaa34bf5be5c3dab058c532adc2792113c">logb</a> (double x)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2095009862165628"><a name="p2095009862165628"></a><a name="p2095009862165628"></a>double </p>
<p id="p1775945730165628"><a name="p1775945730165628"></a><a name="p1775945730165628"></a>Calculates the logarithm of the absolute value of the double value <strong id="b712849237165628"><a name="b712849237165628"></a><a name="b712849237165628"></a>x</strong>. </p>
</td>
</tr>
<tr id="row1171734325165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1478271512165628"><a name="p1478271512165628"></a><a name="p1478271512165628"></a><a href="MATH.md#ga6939b8381c2f160d26913646ca7ab6c4">logbf</a> (float x)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1151675161165628"><a name="p1151675161165628"></a><a name="p1151675161165628"></a>float </p>
<p id="p2050011024165628"><a name="p2050011024165628"></a><a name="p2050011024165628"></a>Calculates the logarithm of the absolute value of the float value <strong id="b2109204031165628"><a name="b2109204031165628"></a><a name="b2109204031165628"></a>x</strong>. </p>
</td>
</tr>
<tr id="row123507581165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p487920199165628"><a name="p487920199165628"></a><a name="p487920199165628"></a><a href="MATH.md#ga2f9c0448126d1a838624e3460217bb84">logbl</a> (long double x)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2040515221165628"><a name="p2040515221165628"></a><a name="p2040515221165628"></a>long double </p>
<p id="p2075107078165628"><a name="p2075107078165628"></a><a name="p2075107078165628"></a>Calculates the logarithm of the absolute value of the long double value <strong id="b327304791165628"><a name="b327304791165628"></a><a name="b327304791165628"></a>x</strong>. </p>
</td>
</tr>
<tr id="row1164662433165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p413060124165628"><a name="p413060124165628"></a><a name="p413060124165628"></a><a href="MATH.md#ga3337db086394bad101bd8d42d891640a">lrint</a> (double x)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p372433443165628"><a name="p372433443165628"></a><a name="p372433443165628"></a>long int </p>
<p id="p1506928253165628"><a name="p1506928253165628"></a><a name="p1506928253165628"></a>Rounds the double value <strong id="b1533110819165628"><a name="b1533110819165628"></a><a name="b1533110819165628"></a>x</strong> to the nearest integer. </p>
</td>
</tr>
<tr id="row1390974219165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p735133711165628"><a name="p735133711165628"></a><a name="p735133711165628"></a><a href="MATH.md#ga16173bca19eef93d0230bfb7c86b5740">lrintf</a> (float x)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p509483023165628"><a name="p509483023165628"></a><a name="p509483023165628"></a>long int </p>
<p id="p2127577200165628"><a name="p2127577200165628"></a><a name="p2127577200165628"></a>Rounds the float value <strong id="b1783135295165628"><a name="b1783135295165628"></a><a name="b1783135295165628"></a>x</strong> to the nearest integer. </p>
</td>
</tr>
<tr id="row1191175126165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1721021016165628"><a name="p1721021016165628"></a><a name="p1721021016165628"></a><a href="MATH.md#gac6d217e9b96a145f5eeb2a490e6496e6">lrintl</a> (long double x)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1927960643165628"><a name="p1927960643165628"></a><a name="p1927960643165628"></a>long int </p>
<p id="p1061775724165628"><a name="p1061775724165628"></a><a name="p1061775724165628"></a>Rounds the long double value <strong id="b887695854165628"><a name="b887695854165628"></a><a name="b887695854165628"></a>x</strong> to the nearest integer. </p>
</td>
</tr>
<tr id="row1373155319165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1140815862165628"><a name="p1140815862165628"></a><a name="p1140815862165628"></a><a href="MATH.md#ga5936ef27aa03815e9c17d557e87a33d7">lround</a> (double x)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p388229676165628"><a name="p388229676165628"></a><a name="p388229676165628"></a>long int </p>
<p id="p388898749165628"><a name="p388898749165628"></a><a name="p388898749165628"></a>Rounds double value <strong id="b254023196165628"><a name="b254023196165628"></a><a name="b254023196165628"></a>x</strong> to the nearest integer, rounding away from <strong id="b673477531165628"><a name="b673477531165628"></a><a name="b673477531165628"></a>0</strong>. </p>
</td>
</tr>
<tr id="row1106251022165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p897621889165628"><a name="p897621889165628"></a><a name="p897621889165628"></a><a href="MATH.md#ga0136619b503ddb8ce1a226cd34c9538c">lroundf</a> (float x)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p269138289165628"><a name="p269138289165628"></a><a name="p269138289165628"></a>long int </p>
<p id="p1238662145165628"><a name="p1238662145165628"></a><a name="p1238662145165628"></a>Rounds the float value <strong id="b2017719765165628"><a name="b2017719765165628"></a><a name="b2017719765165628"></a>x</strong> to the nearest integer, rounding away from <strong id="b1909221796165628"><a name="b1909221796165628"></a><a name="b1909221796165628"></a>0</strong>. </p>
</td>
</tr>
<tr id="row236825937165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1020290692165628"><a name="p1020290692165628"></a><a name="p1020290692165628"></a><a href="MATH.md#gafa865c5b70c9311f0f8701a1af60c715">lroundl</a> (long double x)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1608399151165628"><a name="p1608399151165628"></a><a name="p1608399151165628"></a>long int </p>
<p id="p623582753165628"><a name="p623582753165628"></a><a name="p623582753165628"></a>Rounds the long double value <strong id="b526179149165628"><a name="b526179149165628"></a><a name="b526179149165628"></a>x</strong> to the nearest integer, rounding away from <strong id="b276920835165628"><a name="b276920835165628"></a><a name="b276920835165628"></a>0</strong>. </p>
</td>
</tr>
<tr id="row705399263165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p717950239165628"><a name="p717950239165628"></a><a name="p717950239165628"></a><a href="MATH.md#gafcfe25b77e975450988866fea9d3c9f0">modf</a> (double x, double *iptr)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p589696611165628"><a name="p589696611165628"></a><a name="p589696611165628"></a>double </p>
<p id="p213065133165628"><a name="p213065133165628"></a><a name="p213065133165628"></a>Breaks the double value <strong id="b1060694105165628"><a name="b1060694105165628"></a><a name="b1060694105165628"></a>x</strong> into a signed integral and a fractional part. </p>
</td>
</tr>
<tr id="row1782497314165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p61367385165628"><a name="p61367385165628"></a><a name="p61367385165628"></a><a href="MATH.md#gad8314f66dfe8603f3a166eb466261ce1">modff</a> (float x, float *iptr)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2102479200165628"><a name="p2102479200165628"></a><a name="p2102479200165628"></a>float </p>
<p id="p470950221165628"><a name="p470950221165628"></a><a name="p470950221165628"></a>Breaks the float value <strong id="b409334502165628"><a name="b409334502165628"></a><a name="b409334502165628"></a>x</strong> into a signed integral and a fractional part. </p>
</td>
</tr>
<tr id="row181810559165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p305761936165628"><a name="p305761936165628"></a><a name="p305761936165628"></a><a href="MATH.md#gabacf3b74f8d7e30a70da8ae47c8e4e3e">modfl</a> (long double x, long double *iptr)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1725090158165628"><a name="p1725090158165628"></a><a name="p1725090158165628"></a>long double </p>
<p id="p1913230208165628"><a name="p1913230208165628"></a><a name="p1913230208165628"></a>Breaks the long double value <strong id="b1614167516165628"><a name="b1614167516165628"></a><a name="b1614167516165628"></a>x</strong> into a signed integral and a fractional part. </p>
</td>
</tr>
<tr id="row1628230372165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1153723370165628"><a name="p1153723370165628"></a><a name="p1153723370165628"></a><a href="MATH.md#gaa4ee2f416f261bbd71cda3193c4884c9">nan</a> (const char *tagp)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p105210989165628"><a name="p105210989165628"></a><a name="p105210989165628"></a>double </p>
<p id="p904100515165628"><a name="p904100515165628"></a><a name="p904100515165628"></a>Obtains a quiet NaN value of the double type. </p>
</td>
</tr>
<tr id="row1676676403165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1659295884165628"><a name="p1659295884165628"></a><a name="p1659295884165628"></a><a href="MATH.md#ga7fe43d4c86419daea2c133e8c5c1a17d">nanf</a> (const char *tagp)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1763547505165628"><a name="p1763547505165628"></a><a name="p1763547505165628"></a>float </p>
<p id="p397504706165628"><a name="p397504706165628"></a><a name="p397504706165628"></a>Obtains a quiet NaN value of the float type. </p>
</td>
</tr>
<tr id="row784020066165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1719523597165628"><a name="p1719523597165628"></a><a name="p1719523597165628"></a><a href="MATH.md#gac92b1a3a1073a630ae0b7084e596d40f">nanl</a> (const char *tagp)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1612420674165628"><a name="p1612420674165628"></a><a name="p1612420674165628"></a>long double </p>
<p id="p285395718165628"><a name="p285395718165628"></a><a name="p285395718165628"></a>Obtains a quiet NaN value of the long double type. </p>
</td>
</tr>
<tr id="row1759115107165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1719018409165628"><a name="p1719018409165628"></a><a name="p1719018409165628"></a><a href="MATH.md#ga61ba6b3078ccbd5aac518e6ca2a757bd">nearbyint</a> (double x)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p117542846165628"><a name="p117542846165628"></a><a name="p117542846165628"></a>double </p>
<p id="p343398588165628"><a name="p343398588165628"></a><a name="p343398588165628"></a>Rounds the double value <strong id="b776424910165628"><a name="b776424910165628"></a><a name="b776424910165628"></a>x</strong> to an integer in floating-point format. </p>
</td>
</tr>
<tr id="row698277568165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1020522446165628"><a name="p1020522446165628"></a><a name="p1020522446165628"></a><a href="MATH.md#gab3be3fdcb83a6d7cbd10aa5d891f88bf">nearbyintf</a> (float x)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1978794030165628"><a name="p1978794030165628"></a><a name="p1978794030165628"></a>float </p>
<p id="p306691194165628"><a name="p306691194165628"></a><a name="p306691194165628"></a>Rounds the float value <strong id="b1503993810165628"><a name="b1503993810165628"></a><a name="b1503993810165628"></a>x</strong> to an integer in floating-point format. </p>
</td>
</tr>
<tr id="row726521051165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p392989071165628"><a name="p392989071165628"></a><a name="p392989071165628"></a><a href="MATH.md#ga4b51faf338f7d4f31224d0c096a8859b">nearbyintl</a> (long double x)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p411937163165628"><a name="p411937163165628"></a><a name="p411937163165628"></a>long double </p>
<p id="p727069470165628"><a name="p727069470165628"></a><a name="p727069470165628"></a>Rounds the long double value <strong id="b1437248716165628"><a name="b1437248716165628"></a><a name="b1437248716165628"></a>x</strong> to an integer in floating-point format. </p>
</td>
</tr>
<tr id="row1793178273165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p412625612165628"><a name="p412625612165628"></a><a name="p412625612165628"></a><a href="MATH.md#gabed1b7ee913471448c2dbe58dff28db3">nextafter</a> (double x, double y)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1925182529165628"><a name="p1925182529165628"></a><a name="p1925182529165628"></a>double </p>
<p id="p1608360974165628"><a name="p1608360974165628"></a><a name="p1608360974165628"></a>Obtains the next representable value following the double value <strong id="b2053543953165628"><a name="b2053543953165628"></a><a name="b2053543953165628"></a>x</strong> in the direction of the double value <strong id="b446647442165628"><a name="b446647442165628"></a><a name="b446647442165628"></a>y</strong>. </p>
</td>
</tr>
<tr id="row533839211165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p337135135165628"><a name="p337135135165628"></a><a name="p337135135165628"></a><a href="MATH.md#ga57d2446286a54227595950a2118b349b">nextafterf</a> (float x, float y)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1528288889165628"><a name="p1528288889165628"></a><a name="p1528288889165628"></a>float </p>
<p id="p186231584165628"><a name="p186231584165628"></a><a name="p186231584165628"></a>Obtains the next representable value following the float value <strong id="b847122955165628"><a name="b847122955165628"></a><a name="b847122955165628"></a>x</strong> in the direction of the float value <strong id="b657322504165628"><a name="b657322504165628"></a><a name="b657322504165628"></a>y</strong>. </p>
</td>
</tr>
<tr id="row341922406165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p871363164165628"><a name="p871363164165628"></a><a name="p871363164165628"></a><a href="MATH.md#ga38691f2f734e77206e4336cdcddd0e5b">nextafterl</a> (long double x, long double y)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p969297655165628"><a name="p969297655165628"></a><a name="p969297655165628"></a>long double </p>
<p id="p1181558132165628"><a name="p1181558132165628"></a><a name="p1181558132165628"></a>Obtains the next representable value following the long double value <strong id="b1285501321165628"><a name="b1285501321165628"></a><a name="b1285501321165628"></a>x</strong> in the direction of the long double value <strong id="b1887306206165628"><a name="b1887306206165628"></a><a name="b1887306206165628"></a>y</strong>. </p>
</td>
</tr>
<tr id="row612159025165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p578503500165628"><a name="p578503500165628"></a><a name="p578503500165628"></a><a href="MATH.md#gaeb7afe6d08d8daec35aa282c63d7647e">nexttoward</a> (double x, long double y)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p216837755165628"><a name="p216837755165628"></a><a name="p216837755165628"></a>double </p>
<p id="p2119250859165628"><a name="p2119250859165628"></a><a name="p2119250859165628"></a>Obtains the next representable value following the double value <strong id="b515435699165628"><a name="b515435699165628"></a><a name="b515435699165628"></a>x</strong> in the direction of the long double value <strong id="b821151520165628"><a name="b821151520165628"></a><a name="b821151520165628"></a>y</strong>. </p>
</td>
</tr>
<tr id="row1125800854165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1058853350165628"><a name="p1058853350165628"></a><a name="p1058853350165628"></a><a href="MATH.md#ga634a1dabb08aa5a4fa6897920eff3c1d">nexttowardf</a> (float x, long double y)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p927508933165628"><a name="p927508933165628"></a><a name="p927508933165628"></a>float </p>
<p id="p922266385165628"><a name="p922266385165628"></a><a name="p922266385165628"></a>Obtains the next representable value following the float value <strong id="b855385226165628"><a name="b855385226165628"></a><a name="b855385226165628"></a>x</strong> in the direction of the long double value <strong id="b315241110165628"><a name="b315241110165628"></a><a name="b315241110165628"></a>y</strong>. </p>
</td>
</tr>
<tr id="row780198904165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p544244650165628"><a name="p544244650165628"></a><a name="p544244650165628"></a><a href="MATH.md#ga3930cfe4df009d7221db329b910d6e30">nexttowardl</a> (long double x, long double y)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1539567829165628"><a name="p1539567829165628"></a><a name="p1539567829165628"></a>long double </p>
<p id="p465835513165628"><a name="p465835513165628"></a><a name="p465835513165628"></a>Obtains the next representable value following the long double value <strong id="b700343238165628"><a name="b700343238165628"></a><a name="b700343238165628"></a>x</strong> in the direction of the long double value <strong id="b36748729165628"><a name="b36748729165628"></a><a name="b36748729165628"></a>y</strong>. </p>
</td>
</tr>
<tr id="row1723515057165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1809047522165628"><a name="p1809047522165628"></a><a name="p1809047522165628"></a><a href="MATH.md#gaa56c9494c95edf68386375e97d64159b">pow</a> (double x, double y)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1580262152165628"><a name="p1580262152165628"></a><a name="p1580262152165628"></a>double </p>
<p id="p59707591165628"><a name="p59707591165628"></a><a name="p59707591165628"></a>Obtains the double value <strong id="b1925772809165628"><a name="b1925772809165628"></a><a name="b1925772809165628"></a>x</strong> raised to the power of the double value <strong id="b962999799165628"><a name="b962999799165628"></a><a name="b962999799165628"></a>y</strong>. </p>
</td>
</tr>
<tr id="row1713304061165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1023682663165628"><a name="p1023682663165628"></a><a name="p1023682663165628"></a><a href="MATH.md#gac6b287549be087f6f0bf03b6fe30499e">powf</a> (float x, float y)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p933256830165628"><a name="p933256830165628"></a><a name="p933256830165628"></a>float </p>
<p id="p352269072165628"><a name="p352269072165628"></a><a name="p352269072165628"></a>Obtains the float value <strong id="b1965587003165628"><a name="b1965587003165628"></a><a name="b1965587003165628"></a>x</strong> raised to the power of the float value <strong id="b287099145165628"><a name="b287099145165628"></a><a name="b287099145165628"></a>y</strong>. </p>
</td>
</tr>
<tr id="row470755425165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1354874278165628"><a name="p1354874278165628"></a><a name="p1354874278165628"></a><a href="MATH.md#ga2cb598503b85d66abf59e9da06478f1a">pow10f</a> (float x)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p733103037165628"><a name="p733103037165628"></a><a name="p733103037165628"></a>float </p>
<p id="p942419216165628"><a name="p942419216165628"></a><a name="p942419216165628"></a>Calculates the xth power of 10. </p>
</td>
</tr>
<tr id="row1185605404165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1989371408165628"><a name="p1989371408165628"></a><a name="p1989371408165628"></a><a href="MATH.md#ga2f4830e468138e1513b55ca6a92a0f9a">powl</a> (long double x, long double y)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p572283949165628"><a name="p572283949165628"></a><a name="p572283949165628"></a>long double </p>
<p id="p1077134577165628"><a name="p1077134577165628"></a><a name="p1077134577165628"></a>Obtains the long double value <strong id="b456472914165628"><a name="b456472914165628"></a><a name="b456472914165628"></a>x</strong> raised to the power of the long double value <strong id="b164592109165628"><a name="b164592109165628"></a><a name="b164592109165628"></a>y</strong>. </p>
</td>
</tr>
<tr id="row927631906165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1877061865165628"><a name="p1877061865165628"></a><a name="p1877061865165628"></a><a href="MATH.md#ga9baf71e9033dd73a9c225a2fc9cca61d">pow10l</a> (long double x)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p137002609165628"><a name="p137002609165628"></a><a name="p137002609165628"></a>long double </p>
<p id="p249371254165628"><a name="p249371254165628"></a><a name="p249371254165628"></a>Calculates the xth power of 10. </p>
</td>
</tr>
<tr id="row1487749515165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p370798978165628"><a name="p370798978165628"></a><a name="p370798978165628"></a><a href="MATH.md#gaf7df01c4a9038dbf3562b41bc8c3be03">remainder</a> (double x, double y)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2110010488165628"><a name="p2110010488165628"></a><a name="p2110010488165628"></a>double </p>
<p id="p146581329165628"><a name="p146581329165628"></a><a name="p146581329165628"></a>Calculates the remainder of the double value <strong id="b921558806165628"><a name="b921558806165628"></a><a name="b921558806165628"></a>x</strong> divided by the double value <strong id="b2135175565165628"><a name="b2135175565165628"></a><a name="b2135175565165628"></a>y</strong>. </p>
</td>
</tr>
<tr id="row399753216165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p612489150165628"><a name="p612489150165628"></a><a name="p612489150165628"></a><a href="MATH.md#ga370ff5cfa842822bfd8ea0a93d441a33">remainderf</a> (float x, float y)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1016885527165628"><a name="p1016885527165628"></a><a name="p1016885527165628"></a>float </p>
<p id="p617368569165628"><a name="p617368569165628"></a><a name="p617368569165628"></a>Calculates the remainder of the float value <strong id="b1512109363165628"><a name="b1512109363165628"></a><a name="b1512109363165628"></a>x</strong> divided by the float value <strong id="b1661828671165628"><a name="b1661828671165628"></a><a name="b1661828671165628"></a>y</strong>. </p>
</td>
</tr>
<tr id="row1352162552165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p720853193165628"><a name="p720853193165628"></a><a name="p720853193165628"></a><a href="MATH.md#gabadbe61e166bbf3031b979661f0e8336">remainderl</a> (long double x, long double y)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1137886893165628"><a name="p1137886893165628"></a><a name="p1137886893165628"></a>long double </p>
<p id="p1191975994165628"><a name="p1191975994165628"></a><a name="p1191975994165628"></a>Calculates the remainder of the long double value <strong id="b1651521705165628"><a name="b1651521705165628"></a><a name="b1651521705165628"></a>x</strong> divided by the long double value <strong id="b1945701393165628"><a name="b1945701393165628"></a><a name="b1945701393165628"></a>y</strong>. </p>
</td>
</tr>
<tr id="row1718387729165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p858972968165628"><a name="p858972968165628"></a><a name="p858972968165628"></a><a href="MATH.md#gac836dc6a979229173eb3d6e2744d82de">remquo</a> (double x, double y, int *quo)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1424041237165628"><a name="p1424041237165628"></a><a name="p1424041237165628"></a>double </p>
<p id="p275457915165628"><a name="p275457915165628"></a><a name="p275457915165628"></a>Calculates the quotient and remainder of the double value <strong id="b923082418165628"><a name="b923082418165628"></a><a name="b923082418165628"></a>x</strong> divided by the double value <strong id="b166736061165628"><a name="b166736061165628"></a><a name="b166736061165628"></a>y</strong>. </p>
</td>
</tr>
<tr id="row308160172165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1982713822165628"><a name="p1982713822165628"></a><a name="p1982713822165628"></a><a href="MATH.md#ga15ec704e1894cfa573ac37a65afe009a">remquof</a> (float x, float y, int *quo)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p933750429165628"><a name="p933750429165628"></a><a name="p933750429165628"></a>float </p>
<p id="p2130496460165628"><a name="p2130496460165628"></a><a name="p2130496460165628"></a>Calculates the quotient and remainder of the float value <strong id="b1021780625165628"><a name="b1021780625165628"></a><a name="b1021780625165628"></a>x</strong> divided by the float value <strong id="b1879355151165628"><a name="b1879355151165628"></a><a name="b1879355151165628"></a>y</strong>. </p>
</td>
</tr>
<tr id="row1030903521165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p168467696165628"><a name="p168467696165628"></a><a name="p168467696165628"></a><a href="MATH.md#gaacadcc57a95279058f29e657dce4d285">remquol</a> (long double x, long double y, int *quo)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p398167780165628"><a name="p398167780165628"></a><a name="p398167780165628"></a>long double </p>
<p id="p1718953102165628"><a name="p1718953102165628"></a><a name="p1718953102165628"></a>Calculates the quotient and remainder of the long double value <strong id="b1908786734165628"><a name="b1908786734165628"></a><a name="b1908786734165628"></a>x</strong> divided by the long double value <strong id="b1723789923165628"><a name="b1723789923165628"></a><a name="b1723789923165628"></a>y</strong>. </p>
</td>
</tr>
<tr id="row110926737165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p54585055165628"><a name="p54585055165628"></a><a name="p54585055165628"></a><a href="MATH.md#gae1f9edd5049d3ff63b0373a3c15c38c1">rint</a> (double x)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1130624138165628"><a name="p1130624138165628"></a><a name="p1130624138165628"></a>double </p>
<p id="p1283246754165628"><a name="p1283246754165628"></a><a name="p1283246754165628"></a>Rounds the double value <strong id="b2141497709165628"><a name="b2141497709165628"></a><a name="b2141497709165628"></a>x</strong> to the nearest integer. </p>
</td>
</tr>
<tr id="row1482053421165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p422626273165628"><a name="p422626273165628"></a><a name="p422626273165628"></a><a href="MATH.md#ga48f9341b9310fefa5dd1b0c8c84c99df">rintf</a> (float x)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1700866743165628"><a name="p1700866743165628"></a><a name="p1700866743165628"></a>float </p>
<p id="p173065681165628"><a name="p173065681165628"></a><a name="p173065681165628"></a>Rounds the float value <strong id="b1801001637165628"><a name="b1801001637165628"></a><a name="b1801001637165628"></a>x</strong> to the nearest integer. </p>
</td>
</tr>
<tr id="row277373667165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p835079498165628"><a name="p835079498165628"></a><a name="p835079498165628"></a><a href="MATH.md#gaedc37bf10d69d2efa2a478f5f5d4b26b">rintl</a> (long double x)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1320858518165628"><a name="p1320858518165628"></a><a name="p1320858518165628"></a>long double </p>
<p id="p172900158165628"><a name="p172900158165628"></a><a name="p172900158165628"></a>Rounds the long double value <strong id="b571776266165628"><a name="b571776266165628"></a><a name="b571776266165628"></a>x</strong> to the nearest integer. </p>
</td>
</tr>
<tr id="row2131529712165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p268041454165628"><a name="p268041454165628"></a><a name="p268041454165628"></a><a href="MATH.md#ga7df19cf730447c00150569250a4b5e1d">round</a> (double x)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1025178310165628"><a name="p1025178310165628"></a><a name="p1025178310165628"></a>double </p>
<p id="p1391808031165628"><a name="p1391808031165628"></a><a name="p1391808031165628"></a>Rounds the double value <strong id="b1892157970165628"><a name="b1892157970165628"></a><a name="b1892157970165628"></a>x</strong> to the nearest integer, rounding away from <strong id="b1173648512165628"><a name="b1173648512165628"></a><a name="b1173648512165628"></a>0</strong>. </p>
</td>
</tr>
<tr id="row1694160216165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p343083522165628"><a name="p343083522165628"></a><a name="p343083522165628"></a><a href="MATH.md#gade09185c0cf8101fa9e2f25c15041b81">roundf</a> (float x)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1185688637165628"><a name="p1185688637165628"></a><a name="p1185688637165628"></a>float </p>
<p id="p629124408165628"><a name="p629124408165628"></a><a name="p629124408165628"></a>Rounds the float value <strong id="b1776880045165628"><a name="b1776880045165628"></a><a name="b1776880045165628"></a>x</strong> to the nearest integer, rounding away from <strong id="b1824349160165628"><a name="b1824349160165628"></a><a name="b1824349160165628"></a>0</strong>. </p>
</td>
</tr>
<tr id="row1726305306165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1764594573165628"><a name="p1764594573165628"></a><a name="p1764594573165628"></a><a href="MATH.md#ga6565127c023ae8f392ce69e3b3f30aa1">roundl</a> (long double x)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p874718894165628"><a name="p874718894165628"></a><a name="p874718894165628"></a>long double </p>
<p id="p1361240188165628"><a name="p1361240188165628"></a><a name="p1361240188165628"></a>Rounds the long double value <strong id="b1816641092165628"><a name="b1816641092165628"></a><a name="b1816641092165628"></a>x</strong> to the nearest integer, rounding away from <strong id="b131830480165628"><a name="b131830480165628"></a><a name="b131830480165628"></a>0</strong>. </p>
</td>
</tr>
<tr id="row692826387165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1502000227165628"><a name="p1502000227165628"></a><a name="p1502000227165628"></a><a href="MATH.md#ga947d3d0739c0dc7c46d1eec778d4b6af">scalbln</a> (double x, long int <a href="MATH.md#gae09128febbbe6372cde4fa0c65608a42">exp</a>)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p86381619165628"><a name="p86381619165628"></a><a name="p86381619165628"></a>double </p>
<p id="p609775007165628"><a name="p609775007165628"></a><a name="p609775007165628"></a>Multiplies the double value <strong id="b1030908585165628"><a name="b1030908585165628"></a><a name="b1030908585165628"></a>x</strong> by <strong id="b2134214627165628"><a name="b2134214627165628"></a><a name="b2134214627165628"></a>FLT_RADIX</strong> raised to the power of the long int value <strong id="b730726698165628"><a name="b730726698165628"></a><a name="b730726698165628"></a>exp</strong>, that is, <strong id="b260610566165628"><a name="b260610566165628"></a><a name="b260610566165628"></a>x*(<strong id="b273559688165628"><a name="b273559688165628"></a><a name="b273559688165628"></a>FLT_RADIX</strong>)^exp</strong>. </p>
</td>
</tr>
<tr id="row273417143165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1146288626165628"><a name="p1146288626165628"></a><a name="p1146288626165628"></a><a href="MATH.md#ga1aa3cc34e8f84a2a09400c25c578100d">scalblnf</a> (float x, long int <a href="MATH.md#gae09128febbbe6372cde4fa0c65608a42">exp</a>)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1558834923165628"><a name="p1558834923165628"></a><a name="p1558834923165628"></a>float </p>
<p id="p1435021072165628"><a name="p1435021072165628"></a><a name="p1435021072165628"></a>Multiplies the float value <strong id="b1009645766165628"><a name="b1009645766165628"></a><a name="b1009645766165628"></a>x</strong> by <strong id="b641421604165628"><a name="b641421604165628"></a><a name="b641421604165628"></a>FLT_RADIX</strong> raised to the power of the long int value <strong id="b1662203566165628"><a name="b1662203566165628"></a><a name="b1662203566165628"></a>exp</strong>, that is, <strong id="b10750254165628"><a name="b10750254165628"></a><a name="b10750254165628"></a>x*(<strong id="b177853989165628"><a name="b177853989165628"></a><a name="b177853989165628"></a>FLT_RADIX</strong>)^exp</strong>. </p>
</td>
</tr>
<tr id="row486510083165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1352256929165628"><a name="p1352256929165628"></a><a name="p1352256929165628"></a><a href="MATH.md#gaeb098df94536b520ced9df59fd353848">scalblnl</a> (long double x, long int <a href="MATH.md#gae09128febbbe6372cde4fa0c65608a42">exp</a>)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2020270990165628"><a name="p2020270990165628"></a><a name="p2020270990165628"></a>long double </p>
<p id="p1117336984165628"><a name="p1117336984165628"></a><a name="p1117336984165628"></a>Multiplies the long double value <strong id="b595495451165628"><a name="b595495451165628"></a><a name="b595495451165628"></a>x</strong> by <strong id="b1407727750165628"><a name="b1407727750165628"></a><a name="b1407727750165628"></a>FLT_RADIX</strong> raised to the power of the long int value <strong id="b2042496657165628"><a name="b2042496657165628"></a><a name="b2042496657165628"></a>exp</strong>, that is, <strong id="b1425971238165628"><a name="b1425971238165628"></a><a name="b1425971238165628"></a>x*(<strong id="b931039580165628"><a name="b931039580165628"></a><a name="b931039580165628"></a>FLT_RADIX</strong>)^exp</strong>. </p>
</td>
</tr>
<tr id="row1356967159165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p211585776165628"><a name="p211585776165628"></a><a name="p211585776165628"></a><a href="MATH.md#gaa2fbea1fca1faaebedf2deec71c47189">scalbn</a> (double x, int <a href="MATH.md#gae09128febbbe6372cde4fa0c65608a42">exp</a>)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p250250538165628"><a name="p250250538165628"></a><a name="p250250538165628"></a>double </p>
<p id="p1486797049165628"><a name="p1486797049165628"></a><a name="p1486797049165628"></a>Multiplies the double value <strong id="b478643603165628"><a name="b478643603165628"></a><a name="b478643603165628"></a>x</strong> by <strong id="b1567333631165628"><a name="b1567333631165628"></a><a name="b1567333631165628"></a>FLT_RADIX</strong> raised to the power of the int value <strong id="b1905679442165628"><a name="b1905679442165628"></a><a name="b1905679442165628"></a>exp</strong>, that is, <strong id="b1785972165628"><a name="b1785972165628"></a><a name="b1785972165628"></a>x*(<strong id="b1858948613165628"><a name="b1858948613165628"></a><a name="b1858948613165628"></a>FLT_RADIX</strong>)^exp</strong>. </p>
</td>
</tr>
<tr id="row1357602662165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p487255259165628"><a name="p487255259165628"></a><a name="p487255259165628"></a><a href="MATH.md#ga3849b86bb2f39ebccb79b91745f7883f">scalbnf</a> (float x, int <a href="MATH.md#gae09128febbbe6372cde4fa0c65608a42">exp</a>)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p30373062165628"><a name="p30373062165628"></a><a name="p30373062165628"></a>float </p>
<p id="p843894396165628"><a name="p843894396165628"></a><a name="p843894396165628"></a>Multiplies the float value <strong id="b1666599856165628"><a name="b1666599856165628"></a><a name="b1666599856165628"></a>x</strong> by <strong id="b339481699165628"><a name="b339481699165628"></a><a name="b339481699165628"></a>FLT_RADIX</strong> raised to the power of the int value <strong id="b1241109515165628"><a name="b1241109515165628"></a><a name="b1241109515165628"></a>exp</strong>, that is, <strong id="b245237800165628"><a name="b245237800165628"></a><a name="b245237800165628"></a>x*(<strong id="b638565273165628"><a name="b638565273165628"></a><a name="b638565273165628"></a>FLT_RADIX</strong>)^exp</strong>. </p>
</td>
</tr>
<tr id="row1539601650165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p702400919165628"><a name="p702400919165628"></a><a name="p702400919165628"></a><a href="MATH.md#ga284717e9eceed5bc33389ce33170f907">scalbnl</a> (long double x, int <a href="MATH.md#gae09128febbbe6372cde4fa0c65608a42">exp</a>)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p720740258165628"><a name="p720740258165628"></a><a name="p720740258165628"></a>long double </p>
<p id="p483725993165628"><a name="p483725993165628"></a><a name="p483725993165628"></a>Multiplies the long double value <strong id="b1359821349165628"><a name="b1359821349165628"></a><a name="b1359821349165628"></a>x</strong> by <strong id="b1436309214165628"><a name="b1436309214165628"></a><a name="b1436309214165628"></a>FLT_RADIX</strong> raised to the power of the int value <strong id="b2045025836165628"><a name="b2045025836165628"></a><a name="b2045025836165628"></a>exp</strong>, that is, <strong id="b1995882717165628"><a name="b1995882717165628"></a><a name="b1995882717165628"></a>x*(<strong id="b766144403165628"><a name="b766144403165628"></a><a name="b766144403165628"></a>FLT_RADIX</strong>)^exp</strong>. </p>
</td>
</tr>
<tr id="row2140224913165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p960193190165628"><a name="p960193190165628"></a><a name="p960193190165628"></a><a href="MATH.md#gaad4af25633b071b0e2cdb8ebd87eca77">sin</a> (double x)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1631179371165628"><a name="p1631179371165628"></a><a name="p1631179371165628"></a>double </p>
<p id="p1969308603165628"><a name="p1969308603165628"></a><a name="p1969308603165628"></a>Calculates the sine of the double value <strong id="b2048446284165628"><a name="b2048446284165628"></a><a name="b2048446284165628"></a>x</strong>. </p>
</td>
</tr>
<tr id="row620729117165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1735859160165628"><a name="p1735859160165628"></a><a name="p1735859160165628"></a><a href="MATH.md#ga8a7dc2a88e109f4e15b661247665709a">sinf</a> (float x)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1160350810165628"><a name="p1160350810165628"></a><a name="p1160350810165628"></a>float </p>
<p id="p1459310690165628"><a name="p1459310690165628"></a><a name="p1459310690165628"></a>Calculates the sine of the float value <strong id="b676177139165628"><a name="b676177139165628"></a><a name="b676177139165628"></a>x</strong>. </p>
</td>
</tr>
<tr id="row259450707165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1851202461165628"><a name="p1851202461165628"></a><a name="p1851202461165628"></a><a href="MATH.md#gaeb537bfea71fa91192234a666f3a6a25">sinl</a> (long double x)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p424157688165628"><a name="p424157688165628"></a><a name="p424157688165628"></a>long double </p>
<p id="p1978988808165628"><a name="p1978988808165628"></a><a name="p1978988808165628"></a>Calculates the sine of the long double value <strong id="b1922940352165628"><a name="b1922940352165628"></a><a name="b1922940352165628"></a>x</strong>. </p>
</td>
</tr>
<tr id="row1117959900165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1999357250165628"><a name="p1999357250165628"></a><a name="p1999357250165628"></a><a href="MATH.md#ga862012e970c977c482507064e2793b45">sinh</a> (double x)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1558036473165628"><a name="p1558036473165628"></a><a name="p1558036473165628"></a>double </p>
<p id="p1242154534165628"><a name="p1242154534165628"></a><a name="p1242154534165628"></a>Calculates the hyperbolic sine of the double value <strong id="b941536749165628"><a name="b941536749165628"></a><a name="b941536749165628"></a>x</strong>. </p>
</td>
</tr>
<tr id="row1503558245165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p890246833165628"><a name="p890246833165628"></a><a name="p890246833165628"></a><a href="MATH.md#ga1976c7577fb97800f4b926bd042b64ac">sinhf</a> (float x)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p277619076165628"><a name="p277619076165628"></a><a name="p277619076165628"></a>float </p>
<p id="p2106767557165628"><a name="p2106767557165628"></a><a name="p2106767557165628"></a>Calculates the hyperbolic sine of the float value <strong id="b983926970165628"><a name="b983926970165628"></a><a name="b983926970165628"></a>x</strong>. </p>
</td>
</tr>
<tr id="row1277930333165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1167052943165628"><a name="p1167052943165628"></a><a name="p1167052943165628"></a><a href="MATH.md#gad160d5d1bb3f113e96135a4bebe76abe">sinhl</a> (long double x)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p201524606165628"><a name="p201524606165628"></a><a name="p201524606165628"></a>long double </p>
<p id="p1276112151165628"><a name="p1276112151165628"></a><a name="p1276112151165628"></a>Calculates the hyperbolic sine of the long double value <strong id="b1980005039165628"><a name="b1980005039165628"></a><a name="b1980005039165628"></a>x</strong>. </p>
</td>
</tr>
<tr id="row2072441109165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1969518728165628"><a name="p1969518728165628"></a><a name="p1969518728165628"></a><a href="MATH.md#gab87521a75ef827a85807f89a6c10629a">sqrt</a> (double x)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1813494119165628"><a name="p1813494119165628"></a><a name="p1813494119165628"></a>double </p>
<p id="p1260281320165628"><a name="p1260281320165628"></a><a name="p1260281320165628"></a>Calculates the square root of double value <strong id="b1951904095165628"><a name="b1951904095165628"></a><a name="b1951904095165628"></a>x</strong>. </p>
</td>
</tr>
<tr id="row1563853074165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p853010218165628"><a name="p853010218165628"></a><a name="p853010218165628"></a><a href="MATH.md#ga46c9a8d40cde7c4d5ab40a67e55316bb">sqrtf</a> (float x)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1267598889165628"><a name="p1267598889165628"></a><a name="p1267598889165628"></a>float </p>
<p id="p1426915545165628"><a name="p1426915545165628"></a><a name="p1426915545165628"></a>Calculates the square root of the float value <strong id="b1991000268165628"><a name="b1991000268165628"></a><a name="b1991000268165628"></a>x</strong>. </p>
</td>
</tr>
<tr id="row588191517165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1781423625165628"><a name="p1781423625165628"></a><a name="p1781423625165628"></a><a href="MATH.md#ga9c028a87917b3bb9bba9e75f66cdbd43">sqrtl</a> (long double x)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1763602938165628"><a name="p1763602938165628"></a><a name="p1763602938165628"></a>long double </p>
<p id="p1696054989165628"><a name="p1696054989165628"></a><a name="p1696054989165628"></a>Calculates the square root of the long double value <strong id="b1228894793165628"><a name="b1228894793165628"></a><a name="b1228894793165628"></a>x</strong>. </p>
</td>
</tr>
<tr id="row430612899165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p934100666165628"><a name="p934100666165628"></a><a name="p934100666165628"></a><a href="MATH.md#gaa48fdfd5eea5f4f9c33496402b9e4039">tan</a> (double x)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1058335909165628"><a name="p1058335909165628"></a><a name="p1058335909165628"></a>double </p>
<p id="p2097650715165628"><a name="p2097650715165628"></a><a name="p2097650715165628"></a>Calculates the tangent of the double value <strong id="b1301783450165628"><a name="b1301783450165628"></a><a name="b1301783450165628"></a>x</strong>. </p>
</td>
</tr>
<tr id="row984276201165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p984593378165628"><a name="p984593378165628"></a><a name="p984593378165628"></a><a href="MATH.md#ga67d5bfe80effce6adebf5fcbc5a7dae0">tanf</a> (float x)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1369455039165628"><a name="p1369455039165628"></a><a name="p1369455039165628"></a>float </p>
<p id="p1350415318165628"><a name="p1350415318165628"></a><a name="p1350415318165628"></a>Calculates the tangent of the float value <strong id="b529869904165628"><a name="b529869904165628"></a><a name="b529869904165628"></a>x</strong>. </p>
</td>
</tr>
<tr id="row1694760674165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p22346078165628"><a name="p22346078165628"></a><a name="p22346078165628"></a><a href="MATH.md#ga2151fba6c1e9b4fa5d2af2dcb5c68b17">tanl</a> (long double x)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p11136664165628"><a name="p11136664165628"></a><a name="p11136664165628"></a>long double </p>
<p id="p205035591165628"><a name="p205035591165628"></a><a name="p205035591165628"></a>Calculates the tangent of the long double value <strong id="b610698810165628"><a name="b610698810165628"></a><a name="b610698810165628"></a>x</strong>. </p>
</td>
</tr>
<tr id="row616305926165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1022197242165628"><a name="p1022197242165628"></a><a name="p1022197242165628"></a><a href="MATH.md#gaf85bcf153d7ae805733927f12329dac1">tanh</a> (double x)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p2043533383165628"><a name="p2043533383165628"></a><a name="p2043533383165628"></a>double </p>
<p id="p297787060165628"><a name="p297787060165628"></a><a name="p297787060165628"></a>Calculates the hyperbolic tangent of the double value <strong id="b957122173165628"><a name="b957122173165628"></a><a name="b957122173165628"></a>x</strong>. </p>
</td>
</tr>
<tr id="row917395967165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p784119461165628"><a name="p784119461165628"></a><a name="p784119461165628"></a><a href="MATH.md#ga74e8f87bb37a338d2cebbb6b1d696593">tanhf</a> (float x)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1860985537165628"><a name="p1860985537165628"></a><a name="p1860985537165628"></a>float </p>
<p id="p1448378695165628"><a name="p1448378695165628"></a><a name="p1448378695165628"></a>Calculates the hyperbolic tangent of the float value <strong id="b291343134165628"><a name="b291343134165628"></a><a name="b291343134165628"></a>x</strong>. </p>
</td>
</tr>
<tr id="row215663648165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1228555167165628"><a name="p1228555167165628"></a><a name="p1228555167165628"></a><a href="MATH.md#ga94ee8c57b6b2d0bc5466c75bea2bffcf">tanhl</a> (long double x)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p397881066165628"><a name="p397881066165628"></a><a name="p397881066165628"></a>long double </p>
<p id="p847776936165628"><a name="p847776936165628"></a><a name="p847776936165628"></a>Calculates the hyperbolic tangent of the long double value <strong id="b1273810056165628"><a name="b1273810056165628"></a><a name="b1273810056165628"></a>x</strong>. </p>
</td>
</tr>
<tr id="row35006527165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1846536859165628"><a name="p1846536859165628"></a><a name="p1846536859165628"></a><a href="MATH.md#ga54afbf509eea5e9d6f9efdebc572339a">tgamma</a> (double x)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1096985525165628"><a name="p1096985525165628"></a><a name="p1096985525165628"></a>double </p>
<p id="p1110470810165628"><a name="p1110470810165628"></a><a name="p1110470810165628"></a>Calculates the gamma function of the double value <strong id="b889542356165628"><a name="b889542356165628"></a><a name="b889542356165628"></a>x</strong>. </p>
</td>
</tr>
<tr id="row927610453165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1203255658165628"><a name="p1203255658165628"></a><a name="p1203255658165628"></a><a href="MATH.md#ga2ab69de9110cc2c62ca78b5d20a3a3ae">tgammaf</a> (float x)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p220006165628"><a name="p220006165628"></a><a name="p220006165628"></a>float </p>
<p id="p295498565165628"><a name="p295498565165628"></a><a name="p295498565165628"></a>Calculates the gamma function of the float value <strong id="b453828693165628"><a name="b453828693165628"></a><a name="b453828693165628"></a>x</strong>. </p>
</td>
</tr>
<tr id="row2080576795165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1462803001165628"><a name="p1462803001165628"></a><a name="p1462803001165628"></a><a href="MATH.md#ga8eff39a57115761c5025e08ff2e08c6a">tgammal</a> (long double x)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p523835321165628"><a name="p523835321165628"></a><a name="p523835321165628"></a>long double </p>
<p id="p1787320800165628"><a name="p1787320800165628"></a><a name="p1787320800165628"></a>Calculates the gamma function of the long double value <strong id="b1135769609165628"><a name="b1135769609165628"></a><a name="b1135769609165628"></a>x</strong>. </p>
</td>
</tr>
<tr id="row581304677165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p924289622165628"><a name="p924289622165628"></a><a name="p924289622165628"></a><a href="MATH.md#ga82a151adfde56b28fa8a50355c4f2ff6">trunc</a> (double x)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p436847165628"><a name="p436847165628"></a><a name="p436847165628"></a>double </p>
<p id="p892832763165628"><a name="p892832763165628"></a><a name="p892832763165628"></a>Obtains the nearest integer whose absolute value is less than or equal to the absolute value of the double value <strong id="b1213741790165628"><a name="b1213741790165628"></a><a name="b1213741790165628"></a>x</strong>. </p>
</td>
</tr>
<tr id="row1472315259165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p158266375165628"><a name="p158266375165628"></a><a name="p158266375165628"></a><a href="MATH.md#gaa8bb2049c170c9ac5b131fdba029991a">truncf</a> (float x)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p788311741165628"><a name="p788311741165628"></a><a name="p788311741165628"></a>float </p>
<p id="p1597243588165628"><a name="p1597243588165628"></a><a name="p1597243588165628"></a>Obtains the nearest integer whose absolute value is less than or equal to the absolute value of the float value <strong id="b2115390530165628"><a name="b2115390530165628"></a><a name="b2115390530165628"></a>x</strong>. </p>
</td>
</tr>
<tr id="row1435051526165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1815940344165628"><a name="p1815940344165628"></a><a name="p1815940344165628"></a><a href="MATH.md#ga8f9695496a9bb839eb5f728b6bf0c856">truncl</a> (long double x)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p922464648165628"><a name="p922464648165628"></a><a name="p922464648165628"></a>long double </p>
<p id="p227603255165628"><a name="p227603255165628"></a><a name="p227603255165628"></a>Obtains the nearest integer whose absolute value is less than or equal to the absolute value of the long double value <strong id="b760974437165628"><a name="b760974437165628"></a><a name="b760974437165628"></a>x</strong>. </p>
</td>
</tr>
<tr id="row918468736165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p368390762165628"><a name="p368390762165628"></a><a name="p368390762165628"></a><a href="MATH.md#gaffb00730a1127dee798137075951ae21">j0</a> (double x)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p730176280165628"><a name="p730176280165628"></a><a name="p730176280165628"></a>double </p>
<p id="p1041354561165628"><a name="p1041354561165628"></a><a name="p1041354561165628"></a>Calculates the Bessel function of the first kind of order <strong id="b807366417165628"><a name="b807366417165628"></a><a name="b807366417165628"></a>0</strong> for the double value <strong id="b177955804165628"><a name="b177955804165628"></a><a name="b177955804165628"></a>x</strong>. </p>
</td>
</tr>
<tr id="row742589273165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p55382399165628"><a name="p55382399165628"></a><a name="p55382399165628"></a><a href="MATH.md#ga8cac4aa70c418eba481417f1878b4cee">j1</a> (double x)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p774267351165628"><a name="p774267351165628"></a><a name="p774267351165628"></a>double </p>
<p id="p1548194523165628"><a name="p1548194523165628"></a><a name="p1548194523165628"></a>Calculates the Bessel function of the first kind of order <strong id="b859227464165628"><a name="b859227464165628"></a><a name="b859227464165628"></a>1</strong> for the double value <strong id="b839674427165628"><a name="b839674427165628"></a><a name="b839674427165628"></a>x</strong>. </p>
</td>
</tr>
<tr id="row1542585283165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p308145041165628"><a name="p308145041165628"></a><a name="p308145041165628"></a><a href="MATH.md#gadeff843dc8106ffda5caba6df44c591d">jn</a> (int n, double x)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p290050069165628"><a name="p290050069165628"></a><a name="p290050069165628"></a>double </p>
<p id="p1109765215165628"><a name="p1109765215165628"></a><a name="p1109765215165628"></a>Calculates the Bessel function of the first kind of order <strong id="b1375701997165628"><a name="b1375701997165628"></a><a name="b1375701997165628"></a>n</strong> for the double value <strong id="b898473491165628"><a name="b898473491165628"></a><a name="b898473491165628"></a>x</strong>. </p>
</td>
</tr>
<tr id="row922942541165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1894083179165628"><a name="p1894083179165628"></a><a name="p1894083179165628"></a><a href="MATH.md#gafca57fd80386476e5cd1dd52173103c5">y0</a> (double x)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1242969255165628"><a name="p1242969255165628"></a><a name="p1242969255165628"></a>double </p>
<p id="p456919177165628"><a name="p456919177165628"></a><a name="p456919177165628"></a>Calculates the Bessel function of the second kind of order <strong id="b871256430165628"><a name="b871256430165628"></a><a name="b871256430165628"></a>0</strong> for the double value <strong id="b64625866165628"><a name="b64625866165628"></a><a name="b64625866165628"></a>x</strong>. </p>
</td>
</tr>
<tr id="row551439405165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1136179072165628"><a name="p1136179072165628"></a><a name="p1136179072165628"></a><a href="MATH.md#ga369368526a105f3fba6776b11586070c">y1</a> (double x)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p362891089165628"><a name="p362891089165628"></a><a name="p362891089165628"></a>double </p>
<p id="p494426227165628"><a name="p494426227165628"></a><a name="p494426227165628"></a>Calculates the Bessel function of the second kind of order <strong id="b1902731403165628"><a name="b1902731403165628"></a><a name="b1902731403165628"></a>1</strong> for the double value <strong id="b1437987975165628"><a name="b1437987975165628"></a><a name="b1437987975165628"></a>x</strong>. </p>
</td>
</tr>
<tr id="row329943401165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p319114822165628"><a name="p319114822165628"></a><a name="p319114822165628"></a><a href="MATH.md#gae31b4c8c6af724eaa73ad2ebce1aa3ce">yn</a> (int n, double x)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p84831401165628"><a name="p84831401165628"></a><a name="p84831401165628"></a>double </p>
<p id="p1712673917165628"><a name="p1712673917165628"></a><a name="p1712673917165628"></a>Calculates the Bessel function of the second kind of order <strong id="b385444157165628"><a name="b385444157165628"></a><a name="b385444157165628"></a>n</strong> for the double value <strong id="b1447638005165628"><a name="b1447638005165628"></a><a name="b1447638005165628"></a>x</strong>. </p>
</td>
</tr>
<tr id="row399457867165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p600676436165628"><a name="p600676436165628"></a><a name="p600676436165628"></a><a href="MATH.md#ga08e754462e6ec13bc05fd41cff9cdd4a">finite</a> (double x)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p264453521165628"><a name="p264453521165628"></a><a name="p264453521165628"></a>int </p>
<p id="p687546937165628"><a name="p687546937165628"></a><a name="p687546937165628"></a>Checks whether the double value <strong id="b1042670339165628"><a name="b1042670339165628"></a><a name="b1042670339165628"></a>x</strong> is an infinity or a NaN value. </p>
</td>
</tr>
<tr id="row1145173445165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1238084087165628"><a name="p1238084087165628"></a><a name="p1238084087165628"></a><a href="MATH.md#gaea39ac813876c506f8c351e6c14a5cb7">finitef</a> (float x)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1591676570165628"><a name="p1591676570165628"></a><a name="p1591676570165628"></a>int </p>
<p id="p128236597165628"><a name="p128236597165628"></a><a name="p128236597165628"></a>Checks whether the float value <strong id="b1125403371165628"><a name="b1125403371165628"></a><a name="b1125403371165628"></a>x</strong> is an infinity or a NaN value. </p>
</td>
</tr>
<tr id="row1364481610165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p424582142165628"><a name="p424582142165628"></a><a name="p424582142165628"></a><a href="MATH.md#ga14db57dcd8982430d12219bbecd08a05">scalb</a> (double x, double <a href="MATH.md#gae09128febbbe6372cde4fa0c65608a42">exp</a>)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1614195222165628"><a name="p1614195222165628"></a><a name="p1614195222165628"></a>double </p>
<p id="p2082610291165628"><a name="p2082610291165628"></a><a name="p2082610291165628"></a>Multiplies the double value <strong id="b434120159165628"><a name="b434120159165628"></a><a name="b434120159165628"></a>x</strong> by <strong id="b1973477596165628"><a name="b1973477596165628"></a><a name="b1973477596165628"></a>FLT_RADIX</strong> raised to the power of the double value <strong id="b1799212803165628"><a name="b1799212803165628"></a><a name="b1799212803165628"></a>exp</strong>, that is, x*<strong id="b1762278905165628"><a name="b1762278905165628"></a><a name="b1762278905165628"></a>FLT_RADIX</strong>^exp. </p>
</td>
</tr>
<tr id="row267490118165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p240098463165628"><a name="p240098463165628"></a><a name="p240098463165628"></a><a href="MATH.md#ga9c9db25d2ff9973e0d8638cf42df3999">scalbf</a> (float x, float <a href="MATH.md#gae09128febbbe6372cde4fa0c65608a42">exp</a>)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1304744666165628"><a name="p1304744666165628"></a><a name="p1304744666165628"></a>float </p>
<p id="p648824307165628"><a name="p648824307165628"></a><a name="p648824307165628"></a>Multiplies the float value <strong id="b302681606165628"><a name="b302681606165628"></a><a name="b302681606165628"></a>x</strong> by <strong id="b578179751165628"><a name="b578179751165628"></a><a name="b578179751165628"></a>FLT_RADIX</strong> raised to the power of the float value <strong id="b444819850165628"><a name="b444819850165628"></a><a name="b444819850165628"></a>exp</strong>, that is, x*<strong id="b1887408130165628"><a name="b1887408130165628"></a><a name="b1887408130165628"></a>FLT_RADIX</strong>^exp. </p>
</td>
</tr>
<tr id="row53703420165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1976463574165628"><a name="p1976463574165628"></a><a name="p1976463574165628"></a><a href="MATH.md#gafad3bf1f77c516fb8891c72beb51640f">significand</a> (double x)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1118035170165628"><a name="p1118035170165628"></a><a name="p1118035170165628"></a>double </p>
<p id="p1915321854165628"><a name="p1915321854165628"></a><a name="p1915321854165628"></a>Obtains the significand of the double value <strong id="b1832536885165628"><a name="b1832536885165628"></a><a name="b1832536885165628"></a>x</strong> scaled to the range [1,2). </p>
</td>
</tr>
<tr id="row623843899165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1112583851165628"><a name="p1112583851165628"></a><a name="p1112583851165628"></a><a href="MATH.md#gac57d7d88e1a9b57c9a129ee4d4a68c42">significandf</a> (float x)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1699859244165628"><a name="p1699859244165628"></a><a name="p1699859244165628"></a>float </p>
<p id="p1570131904165628"><a name="p1570131904165628"></a><a name="p1570131904165628"></a>Obtains the significand of the float value <strong id="b1006151688165628"><a name="b1006151688165628"></a><a name="b1006151688165628"></a>x</strong> scaled to the range [1,2). </p>
</td>
</tr>
<tr id="row1531618745165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p171725963165628"><a name="p171725963165628"></a><a name="p171725963165628"></a><a href="MATH.md#gafa59b98550749c27995dfb7c70e6783a">j0f</a> (float x)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1807267570165628"><a name="p1807267570165628"></a><a name="p1807267570165628"></a>float </p>
<p id="p1432009119165628"><a name="p1432009119165628"></a><a name="p1432009119165628"></a>Calculates the Bessel function of the first kind of order <strong id="b1465069083165628"><a name="b1465069083165628"></a><a name="b1465069083165628"></a>0</strong> for the float value <strong id="b622233257165628"><a name="b622233257165628"></a><a name="b622233257165628"></a>x</strong>. </p>
</td>
</tr>
<tr id="row1571377343165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2104396911165628"><a name="p2104396911165628"></a><a name="p2104396911165628"></a><a href="MATH.md#ga4b50bbed127a1c57940d600498a3c5c7">j1f</a> (float x)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p863891187165628"><a name="p863891187165628"></a><a name="p863891187165628"></a>float </p>
<p id="p1843827190165628"><a name="p1843827190165628"></a><a name="p1843827190165628"></a>Calculates the Bessel function of the first kind of order <strong id="b1754738953165628"><a name="b1754738953165628"></a><a name="b1754738953165628"></a>1</strong> for the float value <strong id="b1768181986165628"><a name="b1768181986165628"></a><a name="b1768181986165628"></a>x</strong>. </p>
</td>
</tr>
<tr id="row1661583387165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1103091385165628"><a name="p1103091385165628"></a><a name="p1103091385165628"></a><a href="MATH.md#gac3fcdfd92a775eed4ebd673d7da02525">jnf</a> (int n, float x)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1048964911165628"><a name="p1048964911165628"></a><a name="p1048964911165628"></a>float </p>
<p id="p2118219320165628"><a name="p2118219320165628"></a><a name="p2118219320165628"></a>Calculates the Bessel function of the first kind of order <strong id="b1816772320165628"><a name="b1816772320165628"></a><a name="b1816772320165628"></a>n</strong> for the float value <strong id="b1951893738165628"><a name="b1951893738165628"></a><a name="b1951893738165628"></a>x</strong>. </p>
</td>
</tr>
<tr id="row184334717165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1405937436165628"><a name="p1405937436165628"></a><a name="p1405937436165628"></a><a href="MATH.md#gaba3cd2d73c1ae75ec2d01ebb2dfc108c">y0f</a> (float x)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1295184306165628"><a name="p1295184306165628"></a><a name="p1295184306165628"></a>float </p>
<p id="p114926501165628"><a name="p114926501165628"></a><a name="p114926501165628"></a>Calculates the Bessel function of the second kind of order <strong id="b1390835341165628"><a name="b1390835341165628"></a><a name="b1390835341165628"></a>0</strong> for the float value <strong id="b1867226487165628"><a name="b1867226487165628"></a><a name="b1867226487165628"></a>x</strong>. </p>
</td>
</tr>
<tr id="row1057891543165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1154288462165628"><a name="p1154288462165628"></a><a name="p1154288462165628"></a><a href="MATH.md#ga5f37c38e8985dafae6abca2d1782c160">y1f</a> (float x)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p229821199165628"><a name="p229821199165628"></a><a name="p229821199165628"></a>float </p>
<p id="p285264435165628"><a name="p285264435165628"></a><a name="p285264435165628"></a>Calculates the Bessel function of the second kind of order <strong id="b2016138444165628"><a name="b2016138444165628"></a><a name="b2016138444165628"></a>1</strong> for the float value <strong id="b1750046405165628"><a name="b1750046405165628"></a><a name="b1750046405165628"></a>x</strong>. </p>
</td>
</tr>
<tr id="row1767262390165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p379682534165628"><a name="p379682534165628"></a><a name="p379682534165628"></a><a href="MATH.md#ga47f8750942b731456dd7f2cbf5f55806">ynf</a> (int n, float x)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p155935128165628"><a name="p155935128165628"></a><a name="p155935128165628"></a>float </p>
<p id="p1680911408165628"><a name="p1680911408165628"></a><a name="p1680911408165628"></a>Calculates the Bessel function of the second kind of order <strong id="b442084304165628"><a name="b442084304165628"></a><a name="b442084304165628"></a>n</strong> for the float value <strong id="b86231934165628"><a name="b86231934165628"></a><a name="b86231934165628"></a>x</strong>. </p>
</td>
</tr>
<tr id="row814202599165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1726176000165628"><a name="p1726176000165628"></a><a name="p1726176000165628"></a><a href="MATH.md#ga278e86e217081a0268107f0d6876cb9b">lgammal_r</a> (long double x, int *signp)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1645130022165628"><a name="p1645130022165628"></a><a name="p1645130022165628"></a>long double </p>
<p id="p1087114662165628"><a name="p1087114662165628"></a><a name="p1087114662165628"></a>Calculates the natural logarithm of the absolute value of the gamma function of the double value <strong id="b17018572165628"><a name="b17018572165628"></a><a name="b17018572165628"></a>x</strong>. </p>
</td>
</tr>
<tr id="row216586385165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p268668467165628"><a name="p268668467165628"></a><a name="p268668467165628"></a><a href="MATH.md#gaf4509ae544cecab0e9a61efdfccb7530">sincos</a> (double x, double *<a href="MATH.md#gaad4af25633b071b0e2cdb8ebd87eca77">sin</a>, double *<a href="MATH.md#ga5e7b53a694b3cf0f2d7debd444140fbd">cos</a>)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p731666813165628"><a name="p731666813165628"></a><a name="p731666813165628"></a>void </p>
<p id="p333973373165628"><a name="p333973373165628"></a><a name="p333973373165628"></a>Calculates the sine and cosine of the double value <strong id="b1234468002165628"><a name="b1234468002165628"></a><a name="b1234468002165628"></a>x</strong>. </p>
</td>
</tr>
<tr id="row1312891645165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p138553677165628"><a name="p138553677165628"></a><a name="p138553677165628"></a><a href="MATH.md#gac59adab35511be68e92ad9013d63e866">sincosf</a> (float x, float *<a href="MATH.md#gaad4af25633b071b0e2cdb8ebd87eca77">sin</a>, float *<a href="MATH.md#ga5e7b53a694b3cf0f2d7debd444140fbd">cos</a>)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p583792283165628"><a name="p583792283165628"></a><a name="p583792283165628"></a>void </p>
<p id="p1592903873165628"><a name="p1592903873165628"></a><a name="p1592903873165628"></a>Calculates the sine and cosine of the float value <strong id="b243254911165628"><a name="b243254911165628"></a><a name="b243254911165628"></a>x</strong>. </p>
</td>
</tr>
<tr id="row724181082165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p702846987165628"><a name="p702846987165628"></a><a name="p702846987165628"></a><a href="MATH.md#gaf877b78dbe8e265bdf4b975dbc713482">sincosl</a> (long double x, long double *<a href="MATH.md#gaad4af25633b071b0e2cdb8ebd87eca77">sin</a>, long double *<a href="MATH.md#ga5e7b53a694b3cf0f2d7debd444140fbd">cos</a>)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p848409466165628"><a name="p848409466165628"></a><a name="p848409466165628"></a>void </p>
<p id="p1135155738165628"><a name="p1135155738165628"></a><a name="p1135155738165628"></a>Calculates the sine and cosine of the long double value <strong id="b2096753938165628"><a name="b2096753938165628"></a><a name="b2096753938165628"></a>x</strong>. </p>
</td>
</tr>
<tr id="row979607601165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p1384932722165628"><a name="p1384932722165628"></a><a name="p1384932722165628"></a><a href="MATH.md#gaea673cadd2aef111e2ee7a813776b768">exp10</a> (double x)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p971828118165628"><a name="p971828118165628"></a><a name="p971828118165628"></a>double </p>
<p id="p1744907646165628"><a name="p1744907646165628"></a><a name="p1744907646165628"></a>Calculates the base-10 exponential function of the double value <strong id="b1379908971165628"><a name="b1379908971165628"></a><a name="b1379908971165628"></a>x</strong>. </p>
</td>
</tr>
<tr id="row626809607165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p32072999165628"><a name="p32072999165628"></a><a name="p32072999165628"></a><a href="MATH.md#gad27f10a0e30a7fe130c18786bf097e4b">exp10f</a> (float x)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p1145146751165628"><a name="p1145146751165628"></a><a name="p1145146751165628"></a>float </p>
<p id="p1277011258165628"><a name="p1277011258165628"></a><a name="p1277011258165628"></a>Calculates the base-10 exponential function of the float value <strong id="b67817827165628"><a name="b67817827165628"></a><a name="b67817827165628"></a>x</strong>. </p>
</td>
</tr>
<tr id="row1111146799165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p2027268898165628"><a name="p2027268898165628"></a><a name="p2027268898165628"></a><a href="MATH.md#ga28c11df4d7b29c9f59ac733fba51bece">exp10l</a> (long double x)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p738861263165628"><a name="p738861263165628"></a><a name="p738861263165628"></a>long double </p>
<p id="p722172390165628"><a name="p722172390165628"></a><a name="p722172390165628"></a>Calculates the base-10 exponential function of the long double value <strong id="b1338552937165628"><a name="b1338552937165628"></a><a name="b1338552937165628"></a>x</strong>. </p>
</td>
</tr>
<tr id="row1967240420165628"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.1 "><p id="p585625010165628"><a name="p585625010165628"></a><a name="p585625010165628"></a><a href="MATH.md#gafbbc60a3627a8de4845c7e99e6134ec8">pow10</a> (double x)</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.3.1.2 "><p id="p904173913165628"><a name="p904173913165628"></a><a name="p904173913165628"></a>double </p>
<p id="p1193127111165628"><a name="p1193127111165628"></a><a name="p1193127111165628"></a>Calculates the value of 10 raised to the power <strong id="b157830188165628"><a name="b157830188165628"></a><a name="b157830188165628"></a>x</strong>, which is a double value. </p>
</td>
</tr>
</tbody>
</table>

