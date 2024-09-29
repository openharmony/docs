# API Info 测试场景1（reference文件夹下）

The result(api-info) of Topic is 3.

> **说明：**
>
> 本模块首批接口从API version 3开始支持。

## Test0-Section<sup>7</sup>

The result(api-info) of Section(Test0-Section) is 7.

### Test4-subSection<sup>(deprecated)</sup>

The result(api-info) of subSection(Test4-subSection) is 9.

> **说明：**
>
> 从API version 9开始支持，从API version 11开始废弃。

### Test5-subSection

The result(api-info) of subSection(Test5-subSection) is 7,(extend the result of Test0-Section).


## Test1-Section

The result(api-info) of Section(Test1-Section) is 3, (extend the result of topic).

### Test3-subSection<sup>8</sup>

The result(api-info) of subSection(Test3-subSection) is 8.

### Test6-subSection

The result(api-info) of subSection(Test6-subSection) is 3,(extend the result of Test1-Section).


## Test2-Section<sup>(deprecated)</sup>

The result(api-info) of Section(Test2-Section) is 6.

> **说明：**
>
> 从API version 6开始支持，从API version 9开始废弃

### Test7-subSection<sup>(deprecated)</sup>

The result(api-info) of subSection(Test7-subSection) is 6,(extend the result of Test2-Section)

## Test8-Section<sup>abc</sup>

The result(api-info) of Section(Test8-Section) is 3, (extend the result of topic).

### Test9-subSection<sup>abc</sup>

The result(api-info) of Section(Test9-subSection) is 3, (extend the result of Test8-Section).

## 中文下测试

结果为3，继承topic下的api-info值

> **说明：**
>
> This API is supported since API version 7 and deprecated since API version 9.