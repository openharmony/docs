# Character Processing

## Use Cases

Character rules vary greatly in different languages, and it is usually difficult to extract expected information from the corresponding text. Character processing makes it possible to process text with similar logic under different language rules.

## How to Develop


### Character Type Identification Using Character Attributes

Character attributes are used to determine the character type, for example, digit, letter, or space, and check whether a character is of the right-to-left (RTL) language or whether a character is an ideographic character (for example, Chinese, Japanese, or Korean).

You can implement these functions by using APIs of the Unicode class. For example, you can use [isDigit](../reference/apis-localization-kit/js-apis-i18n.md#isdigit9) to check whether a character is a digit. The development procedure is as follows:

1. Import the **i18n** module.

   ```ts
   import { i18n } from '@kit.LocalizationKit';
   ```

2. Obtain the character attribute.

   ```ts
   let isDigit: boolean = i18n.Unicode.isDigit(char: string);
   ```

3. Obtain the character type. The following code snippet uses the common type as an example.

   ```ts
   let unicodeType: string = i18n.Unicode.getType(char: string);
   ```

**Development Example**
```ts
// Import the i18n module.
import { i18n } from '@kit.LocalizationKit';

// Check whether the input character is a digit.
let isDigit: boolean = i18n.Unicode.isDigit('1'); // isDigit = true

// Check whether a character is of the RTL language.
let isRTL: boolean = i18n.Unicode.isRTL('a'); // isRTL = false

// Check whether a character is an ideographic character.
let isIdeograph: boolean = i18n.Unicode.isIdeograph ('华'); // isIdeograph = true

// Obtain the character type.
let unicodeType: string = i18n.Unicode.getType('a'); // unicodeType = 'U_LOWERCASE_LETTER'
```


### Transliteration

Transliteration refers to the process of converting text represented by one writing system or alphabet into text represented by another writing system or alphabet with the same pronunciation. It is distinct from translation. You can implement this function by using the [transform](../reference/apis-localization-kit/js-apis-i18n.md#transform9) API of the **Transliterator** class. The development procedure is as follows:

> **NOTE**
> This module enables the conversion of Chinese characters into pinyin. Nevertheless, when the Chinese text includes polyphonic characters, there may be instances where some of these characters fail to be converted into pinyin with the accurate pronunciation.

1. Import the **i18n** module.
   ```ts
   import { i18n } from '@kit.LocalizationKit';
   ```

2. Obtain the list of available transliterator IDs, and create a **Transliterator** object.
   ```ts
   let ids: string[] = i18n.Transliterator.getAvailableIDs(); // Obtain the list of available transliterator IDs.
   let transliterator: i18n.Transliterator = i18n.Transliterator.getInstance(id: string); // Pass in a valid transliterator ID to create a Transliterator object.
   ```

3. Transliterate text.
   ```ts
   let translatedText: string = transliterator.transform(text: string); // Transliterate the text content.
   ```


**Development Example**
```ts
// Import the i18n module.
import { i18n } from '@kit.LocalizationKit';

// Transliterate the text into the Latn format.
let transliterator: i18n.Transliterator = i18n.Transliterator.getInstance('Any-Latn');
let text: string = '中国'
let translatedText: string = transliterator.transform(text); // translatedText = 'zhōng guó'

// Chinese transliteration and tone removal
let toneLessTransliterator: i18n.Transliterator = i18n.Transliterator.getInstance('Any-Latn;Latin-Ascii');
translatedText = toneLessTransliterator.transform ('中国'); // translatedText ='zhong guo'

// Chinese surname pronunciation
let nameTransliterator: i18n.Transliterator = i18n.Transliterator.getInstance('Han-Latin/Names');
translatedText = nameTransliterator.transform('单老师'); // translatedText = 'shàn lǎo shī'
translatedText = nameTransliterator.transform('长孙无忌'); // translatedText = 'zhǎng sūn wú jì'

// Obtain the list of available transliterator IDs.
let ids: string[] = i18n.Transliterator.getAvailableIDs(); // ids = ['ASCII-Latin', 'Accents-Any', ...]
```


### Text Normalization

Text normalization means to the normalize text according to the specified paradigm. You can implement this function by using the [normalize](../reference/apis-localization-kit/js-apis-i18n.md#normalize10) API of the **Normalizer** class. The development procedure is as follows:

1. Import the **i18n** module.
   ```ts
   import { i18n } from '@kit.LocalizationKit';
   ```

2. Create a **Normalizer** object based on the specified text normalization mode. The text normalization mode can be NFC, NFD, NFKC, or NFKD. For details, see [Unicode Normalization Forms](https://www.unicode.org/reports/tr15/#Norm_Forms).
   ```ts
   let normalizer: i18n.Normalizer = i18n.Normalizer.getInstance(mode: NormalizerMode);
   ```

3. Normalize the text.
   ```ts
   let normalizedText: string = normalizer.normalize(text: string); // Normalize the text.
   ```

**Development Example**
```ts
// Import the i18n module.
import { i18n } from '@kit.LocalizationKit';

// Normalize the text in NFC mode.
let normalizer: i18n.Normalizer = i18n.Normalizer.getInstance(i18n.NormalizerMode.NFC);
let normalizedText: string = normalizer.normalize('\u1E9B\u0323'); // normalizedText = 'ẛ̣'
```


### Line Break Point Acquisition

You can use APIs of the [BreakIterator](../reference/apis-localization-kit/js-apis-i18n.md#breakiterator8) class to obtain line break points of the text for the specified locale. The development procedure is as follows:

1. Import the **i18n** module.
   ```ts
   import { i18n } from '@kit.LocalizationKit';
   ```

2. Create a **BreakIterator** object to obtain line break points of the text for the specified locale. The object calculates the line break points in the text according to the rules of the specified locale.

   ```ts
   let iterator: i18n.BreakIterator = i18n.getLineInstance(locale: string);
   ```

3. Set the text to be processed.
   ```ts
   iterator.setLineBreakText(text: string); // Set the text to be processed.
   let breakText: string = iterator.getLineBreakText(); // View the text being processed by the BreakIterator object.
   ```

4. Obtain the position of a line break point.
   ```ts
   let currentPos: number = iterator.current(); // Obtain the position of the BreakIterator object in the text.
   let firstPos: number = iterator.first(); // If the first line break point is specified, its position will be returned. It is always at the beginning of the text, that is, firstPos = 0.
   let nextPos: number = iterator.next(index?: number); // Move the BreakIterator object by the specified number of line break points. If the number is a positive number, the object is moved backward. If the number is a negative number, the object is moved forward. The default value is 1. nextPos indicates the position after movement. If BreakIterator is moved out of the text length range, -1 is returned.
   let isBoundary: boolean = iterator.isBoundary(offset: number); // Check whether the offset position is a line break point.
   ```


**Development Example**
```ts
// Import the i18n module.
import { i18n } from '@kit.LocalizationKit';

// Create a BreakIterator object to obtain line break points.
let iterator: i18n.BreakIterator  = i18n.getLineInstance('en-GB');

// Set the text to be processed.
iterator.setLineBreakText('Apple is my favorite fruit.');

// Move the BreakIterator object to the beginning of the text.
let firstPos: number = iterator.first(); // firstPos = 0

// Move the BreakIterator object backward by two line break points.
let nextPos: number = iterator.next(2); // nextPos = 9

// Check whether a certain position is a line break point.
let isBoundary: boolean = iterator.isBoundary(9); // isBoundary = true

// Obtain the text processed by BreakIterator.
let breakText: string = iterator.getLineBreakText(); // breakText = 'Apple is my favorite fruit.'
```

### File Path Mirroring

File path mirroring means to localize file paths for an RTL language, so as to achieve file path mirroring effect in that language. You can implement this function by using the [getUnicodeWrappedFilePath](../reference/apis-localization-kit/js-apis-i18n.md#getunicodewrappedfilepath18) API of the **I18NUtil** class. The development procedure is as follows:

1. Import the **i18n** module.
   ```ts
   import { i18n, intl } from '@kit.LocalizationKit';
   ```

2. Perform file path mirroring.
   ```ts
   let mirrorPath: string = i18n.I18NUtil.getUnicodeWrappedFilePath(path: string, delimiter?: string, locale?: intl.Locale);
   ```


**Development Example**
```ts
// Import the i18n module.
import { BusinessError } from '@kit.BasicServicesKit';
import { i18n, intl } from '@kit.LocalizationKit';

try {
  // Perform file path mirroring if mirrorPath is passed.
  let path: string = 'data/out/tmp';
  let delimiter: string = '/';
  let locale: intl.Locale = new intl.Locale('ar');
  // mirrorPath = 'tmp/out/data/'
  let mirrorPath: string = i18n.I18NUtil.getUnicodeWrappedFilePath(path, delimiter, locale);

  // Skip file path mirroring if unMirrorPath is passed.
  let localeZh: intl.Locale = new intl.Locale('zh');
  // unMirrorPath = '/data/out/tmp'
  let unMirrorPath: string = i18n.I18NUtil.getUnicodeWrappedFilePath(path, delimiter, localeZh);
} catch (error) {
  console.error(`call I18NUtil.getUnicodeWrappedFilePath failed, error code: ${error.code}, message: ${error.message}.`);
}
```
<!--RP1--><!--RP1End-->

<!--no_check-->