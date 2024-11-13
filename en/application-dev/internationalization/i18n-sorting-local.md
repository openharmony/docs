# Sorting by Local Habits

## Use Cases

The sorting function allows list content, for example, the language list in **Settings**, to be sorted and displayed in line with local user habits.

## How to Develop

The sorting function is implemented by the [compare](../reference/apis-localization-kit/js-apis-intl.md#compare8) API of the [Collator](../reference/apis-localization-kit/js-apis-intl.md#collator8) class. The development procedure is as follows:

1. Import the **intl** module.
   ```ts
   import { intl } from '@kit.LocalizationKit';
   ```

2. Create a **Collator** object.
   You can use **CollatorOptions** to set different sorting formats. For details, see Table 1.
   ```ts
   let collator = new intl.Collator(locale: string | Array<string>, options?: CollatorOptions);
   ```

3. Compare two strings.
   ```ts
   let compareResult = collator.compare(first: string, second: string);
   // If compareResult is a negative number, the first parameter is placed before the second parameter.
   // If compareResult is 0, the first and second parameters are not sorted in sequence.
   // If compareResult is a positive number, the first parameter is placed after the second parameter.
   ```

**Sorting Format Options**

**Table 1** Supported sorting formats and display effects

| Name| Value| Description| Display Effect| 
| -------- | -------- | -------- | -------- |
| localeMatcher | lookup | Fuzzy matching.|  | 
|  | best fit | Exact matching.|  | 
| usage | sort | Sorting.|  | 
|  | search | Search for matched strings.|  | 
| sensitivity | base | Compare different letters.| Example: a ≠ b, a = á, a = A| 
|  | accent | Compare different letters or accents.| Example: a ≠ b, a ≠ á, a = A| 
|  | case | Compare the capitalization of different letters or the same letter.| Example: a ≠ b, a = á, a = A| 
|  | variant | Compare different letters or accents, and other distinctive signs or capitalization.| Example: a ≠ b, a ≠ á, a ≠ A| 
| ignorePunctuation | true | Ignore punctuation.| a,b = ab | 
|  | false | Not ignore punctuation.| a,b &lt; ab | 
| numeric | true | Sort by number.| 1 &lt; 2 &lt; 10 &lt; 11 | 
|  | false | Not sort by number.| 1 &lt; 10 &lt; 11 &lt; 2 | 
| caseFirst | upper | Place uppercase letters in the front.| ab,aB, AB,Ab =&gt; AB &lt; Ab &lt; aB &lt; ab | 
|  | lower | Place lowercase letters in the front.| ab,aB, AB,Ab =&gt; ab &lt; aB &lt; Ab &lt; AB | 
|  | false | Not distinguish first letter capitalization.| ab,aB, AB,Ab =&gt; ab &lt; aB &lt; Ab &lt; AB | 
| collation | big5han | Pinyin sorting for Latin letters.|  | 
|  | compat | Compatibility sorting, only for Arabic.|  | 
|  | dict | Dictionary-style sorting, only for Singhalese.|  | 
|  | direct | Binary code sorting.|  | 
|  | ducet | Default Unicode collation element table.|  | 
|  | eor | European sorting.|  | 
|  | gb2312 | Pinyin sorting, only for Chinese.|  | 
|  | phonebk | Phonebook-style sorting.|  | 
|  | phonetic | Phonetic sorting.|  | 
|  | pinyin | Pinyin sorting.|  | 
|  | reformed | Reformed sorting, only for Swedish.|  | 
|  | searchjl | Special collation type for Korean initial consonant search.|  | 
|  | stroke | Stroke sorting for Chinese.|  | 
|  | trad | Traditional-style sorting, for example, Spanish.|  | 
|  | unihan | Radical-stroke sorting for Han characters, only for Chinese, Japanese, and Korean.|  | 
|  | zhuyin | Zhuyin sorting, only for Chinese.|  | 

**Development Example**

```ts
// Import the i18n module.
import { intl } from '@kit.LocalizationKit';

// Create a Collator object.
let options: intl.CollatorOptions = {
    localeMatcher: "lookup", 
    usage: "sort",
    sensitivity: "case" // Case sensitive
};
let collator = new intl.Collator("zh-CN", options);

// Case-sensitive sorting
let array = ["app", "App", "Apple", "ANIMAL", "animal", "apple", "APPLE"];
array.sort((a, b) => {
    return collator.compare(a, b);
})
console.log("result: ", array);  // animal ANIMAL app App apple Apple APPLE

// Pinyin sorting for Chinese
array = ["Pingguo", "Li", "Xiangjiao", "Shiliu", "Ganzhe", "Putao", "Juzi"];
array.sort((a, b) => {
    return collator.compare(a, b);
})
console.log("result: ", array);  // Ganzhe, Juzi, Li, Pingguo, Putao, Shiliu, Xiangjiao

// Stroke sorting
options = {
    localeMatcher: "lookup", 
    usage: "sort",
    collation: "stroke"
};
collator = new intl.Collator("zh-CN", options);
array = ["苹果", "梨", "香蕉", "石榴", "甘蔗", "葡萄", "橘子"];
array.sort((a, b) => {
    return collator.compare(a, b);
})
console.log("result: ", array);  // 甘蔗,石榴,苹果,香蕉,梨,葡萄,橘子
```
<!--no_check-->