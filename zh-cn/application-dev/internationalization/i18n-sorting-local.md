# 本地习惯排序

## 使用场景

在用户使用到排序的场景下，提供符合用户使用习惯的排序方法展示内容。例如，设置中“系统和语言”的语言列表，需要按照当地用户习惯进行排序。

## 开发步骤

多语言列表按照当地用户习惯进行排序，通过[Collator](../reference/apis-localization-kit/js-apis-intl.md#collator8)类的[compare](../reference/apis-localization-kit/js-apis-intl.md#compare8)接口实现，具体开发步骤如下：

1. 导入模块。
   ```ts
   import { intl } from '@kit.LocalizationKit';
   ```

2. 创建Collator排序对象。
   构造函数支持通过CollatorOptions设置不同的排序格式，具体请参考表1。
   ```ts
   let collator: intl.Collator = new intl.Collator(locale: string | Array<string>, options?: CollatorOptions);
   ```

3. 比较字符串。
   ```ts
   let compareResult: number = collator.compare(first: string, second: string);
   // compareResult 为负数，表示第一个参数排在第二个参数之前
   // compareResult 为0，表示第一个参数与第二个参数排序不分先后
   // compareResult 为正数，表示第一个参数排在第二个参数之后
   ```

**排序格式选项**

**表1** CollatorOptions各参数取值和显示效果

| 名称 | 取值 | 描述 | 显示效果 | 
| -------- | -------- | -------- | -------- |
| localeMatcher | lookup | 模糊匹配 |  | 
|  | best fit | 准确匹配 |  | 
| usage | sort | 用作排序 |  | 
|  | search | 用作查找匹配的字符串 |  | 
| sensitivity | base | 不同的字母比较不相等 | 'a' ≠ 'b', 'a' = 'á', 'a' = 'A' | 
|  | accent | 不同的字母或不同读音的相同字母比较不相等 | 'a' ≠ 'b', 'a' ≠ 'á', 'a' = 'A' | 
|  | case | 不同的字母或相同字母大小写比较不相等 | 'a' ≠ 'b', 'a' = 'á', 'a' ≠ 'A' | 
|  | variant | 不同的字母或读音及其它有区别的标志或大小写都是不相等的 | 'a' ≠ 'b', 'a' ≠ 'á', 'a' ≠ 'A' | 
| ignorePunctuation | true | 忽略标点 | 'a,b' = 'ab' | 
|  | false | 不忽略标点 | 'a,b' &lt; 'ab' | 
| numeric | true | 使用数字排序 | '1' &lt; '2' &lt; '10' &lt; '11' | 
|  | false | 不使用数字排序 | '1' &lt; '10' &lt; '11' &lt; '2' | 
| caseFirst | upper | 大写排前面 | 'AB' &lt; 'Ab' &lt; 'aB' &lt; 'ab' | 
|  | lower | 小写排前面 | 'ab' &lt; 'aB' &lt; 'Ab' &lt; 'AB' | 
|  | false | 不区分首字母大小写 | 'ab' &lt; 'aB' &lt; 'Ab' &lt; 'AB' | 
| collation | big5han | 拉丁字母使用的拼音排序 |  | 
|  | compat | 兼容性排序，仅用于阿拉伯语 |  | 
|  | dict | 词典风格排序，仅用于僧伽罗语 |  | 
|  | direct | 二进制码点排序 |  | 
|  | ducet | Unicode排序规则元素表 |  | 
|  | eor | 欧洲排序规则 |  | 
|  | gb2312 | 拼音排序，仅用于中文排序 |  | 
|  | phonebk | 电话本风格排序 |  | 
|  | phonetic | 发音排序 |  | 
|  | pinyin | 拼音排序 |  | 
|  | reformed | 瑞典语排序 |  | 
|  | searchjl | 韩语初始辅音搜索的特殊排序 |  | 
|  | stroke | 汉语的笔画排序 |  | 
|  | trad | 传统风格排序，如西班牙语 |  | 
|  | unihan | 统一汉字排序，用于日语、韩语、中文等汉字排序 |  | 
|  | zhuyin | 注音排序，仅用于中文排序 |  | 

**开发实例**

```ts
// 导入模块
import { intl } from '@kit.LocalizationKit';

// 创建排序对象
let options: intl.CollatorOptions = {
  localeMatcher: 'lookup',
  usage: 'sort',
  sensitivity: 'case' // 区分大小写
};
let collator: intl.Collator = new intl.Collator('zh-CN', options);

// 区分大小写排序
let array: Array<string> = ['app', 'App', 'Apple', 'ANIMAL', 'animal', 'apple', 'APPLE'];
array.sort((a, b) => { // 排序后，array = ['animal', 'ANIMAL', 'app', 'App', 'apple', 'Apple', 'APPLE']
  return collator.compare(a, b);
})

// 中文拼音排序
array = ['苹果', '梨', '香蕉', '石榴', '甘蔗', '葡萄', '橘子'];
array.sort((a, b) => { // 排序后，array = ['甘蔗', '橘子', '梨', '苹果', '葡萄', '石榴', '香蕉']
  return collator.compare(a, b);
})

// 按笔画排序
options = {
  localeMatcher: 'lookup',
  usage: 'sort',
  collation: 'stroke'
};
let strokeCollator: intl.Collator = new intl.Collator('zh-CN', options);
array = ['苹果', '梨', '香蕉', '石榴', '甘蔗', '葡萄', '橘子'];
array.sort((a, b) => { // 排序后，array = ['甘蔗', '石榴', '苹果', '香蕉', '梨', '葡萄', '橘子']
  return strokeCollator.compare(a, b);
})

// 搜索匹配的字符串
options = {
  usage: 'search',
  sensitivity: 'base'
};
let searchCollator: intl.Collator = new intl.Collator('tr', options);
array = ['Türkiye', 'TüRkiye', 'salt', 'bright'];
let target: string = 'türkiye';
// matches = ['Türkiye', 'TüRkiye']
let matches: string[] = array.filter(item => searchCollator.compare(item, target) === 0); 
```
