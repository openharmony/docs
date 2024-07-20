# Sorting by Indexes

## When to Use

When there are many options in a list, users need to slide the window to search for the target option. Sorting by indexes is here to help them quickly find the target option by way of creating an index for each option. It is actually a kind of labeling. For example, labels ABCD on the right of the contact page correspond to the initial letters of contact names. If you want to find John, clicking J will direct you to a list of names starting with J. When there are many options in a list, users need to slide the window to search for the target option. Sorting by indexes is here to help them quickly find the target option by way of creating an index for each option.

## How to Develop

For details about how to use related APIs, see [IndexUtil](../reference/apis-localization-kit/js-apis-i18n.md#indexutil8).

1. Import the **i18n** module.
   ```ts
   import { i18n } from '@kit.LocalizationKit';
   ```

2. Create an **IndexUtil** object.
   ```ts
   let indexUtil = i18n.getInstance(locale?:string);  // The default value of locale is the current system locale.
   ```

3. Obtain the index list.
   ```ts
   let indexList = indexUtil.getIndexList();
   ```

**Development Example**

```ts
// Import the i18n module.
import { i18n } from '@kit.LocalizationKit';
// Create indexes in a single language.
let indexUtil = i18n.getInstance("zh-CN");
let indexList = indexUtil.getIndexList(); // ["...", "A", "B", "C", "D", "E" ... "X", "Y", "Z", "..."]
// Create indexes in multiple languages.
indexUtil.addLocale("ru-RU");
indexList = indexUtil.getIndexList(); // …,A,B,C,D,E,F,G,H,I,J,K,L,M,N,O,P,Q,R,S,T,U,V,W,X,Y,Z,…,А,Б,В,Г,Д,Е,Ж,З,И,Й,К,Л,М,Н,О,П,Р,С,Т,У,Ф,Х,Ц,Ч,Ш,Щ,Ы,Э,Ю,Я,...
indexUtil.getIndex ("Hello"); // Index H
```
