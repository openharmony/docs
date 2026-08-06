# Character Processing

<!--Kit: Localization Kit-->
<!--Subsystem: Global-->
<!--Owner: @yliupy-->
<!--Designer: @sunyaozu-->
<!--Tester: @lpw_work-->
<!--Adviser: @ningningW-->
<!-- md-trans-meta sourceCommit=9d4329aa9b07ce81fc1a2c848fb4cea93e274a8e translatedAt=2026-08-04T12:26:00.248Z pushedAt=2026-08-04T12:38:08.384Z -->

## Function Description

Character rules vary greatly across different languages. Character processing ensures that text can be processed with similar logic under different language rules.

## How to Develop

1. Import the required module.

   <!-- @[import_module](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/International/Internationalization/entry/src/main/ets/i18napplication/CharacterProcessing.ets) -->

   ``` TypeScript
   import { i18n } from '@kit.LocalizationKit';
   ```

2. Usage scenarios.

- Character attributes: Character attributes are used to determine character types, such as whether a character is a digit, letter, space, a character of a right-to-left language, or an ideographic character (mainly Chinese, Japanese, and Korean). You can implement this functionality by using APIs such as [isDigit](../reference/apis-localization-kit/js-apis-i18n.md#isdigit9) of the **Unicode** class. The sample code is as follows:

  <!-- @[identify_character_type](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/International/Internationalization/entry/src/main/ets/i18napplication/CharacterProcessing.ets) -->

  ``` TypeScript
  // Determine whether the character is a digit.
  let isDigit = i18n.Unicode.isDigit('1'); // isDigit = true

  // Determine whether the character belongs to a right-to-left language.
  let isRTL = i18n.Unicode.isRTL('a'); // isRTL = false

  // Determine whether the character is an ideograph.
  let isIdeograph = i18n.Unicode.isIdeograph('华'); // isIdeograph = true

  // Obtain the general category value of the character.
  let unicodeType = i18n.Unicode.getType('a'); // unicodeType = 'U_LOWERCASE_LETTER'
  ```

- Transliteration: Transliteration refers to the process of converting text represented by one writing system or alphabet into text represented by another writing system or alphabet with the same pronunciation. It is different from translation. You can implement transliteration by using the [transform](../reference/apis-localization-kit/js-apis-i18n.md#transform9) API of the **Transliterator** class. The sample code is as follows:

  > **NOTE**
  >
  > This module supports the conversion of Chinese characters into pinyin. However, when the Chinese text contains polyphonic characters, some of them may not be converted into pinyin with the correct pronunciation.

  <!-- @[get_transliteration](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/International/Internationalization/entry/src/main/ets/i18napplication/CharacterProcessing.ets) -->

  ``` TypeScript
  // Transliterate to Latn format.
  let transliterator: i18n.Transliterator = i18n.Transliterator.getInstance('Any-Latn');
  let translatedText = transliterator.transform('中国'); // translatedText = 'zhōng guó'

  // Transliterate Chinese without tones.
  let toneLessTransliterator: i18n.Transliterator = i18n.Transliterator.getInstance('Any-Latn;Latin-Ascii');
  let toneLessTranslatedText = toneLessTransliterator.transform('中国'); // toneLessTranslatedText = 'zhong guo'

  // Transliterate Chinese surname pronunciation.
  let nameTransliterator: i18n.Transliterator = i18n.Transliterator.getInstance('Han-Latin/Names');
  let nameTranslatedText = nameTransliterator.transform('单老师'); // nameTranslatedText = 'shàn lǎo shī'

  // Obtain the list of conversion IDs supported for transliteration.
  let ids = i18n.Transliterator.getAvailableIDs(); // ids = ['ASCII-Latin', 'Accents-Any', ...]
  ```

- Text normalization: Text normalization means to normalize text according to the specified paradigm. The text normalization paradigms include NFC, NFD, NFKC, and NFKD. For details about these paradigms, see [International Standard](https://www.unicode.org/reports/tr15/#Norm_Forms). You can implement text normalization by using the [normalize](../reference/apis-localization-kit/js-apis-i18n.md#normalize10) API of the **Normalizer** class. The sample code is as follows:

  <!-- @[character_normalization](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/International/Internationalization/entry/src/main/ets/i18napplication/CharacterProcessing.ets) -->

  ``` TypeScript
  // Normalize the text according to the NFC normalization form.
  let normalizer: i18n.Normalizer = i18n.Normalizer.getInstance(i18n.NormalizerMode.NFC);
  let normalizedText = normalizer.normalize('\u1E9B\u0323'); // normalizedText = 'ẛ̣'
  ```

- Obtaining line break points of text: You can use APIs of the [BreakIterator](../reference/apis-localization-kit/js-apis-i18n.md#breakiterator8) class to obtain line break points of the text for the specified locale. The sample code is as follows:

  <!-- @[set_text_line_break_settings](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/International/Internationalization/entry/src/main/ets/i18napplication/CharacterProcessing.ets) -->

  ``` TypeScript
  // Create an object for obtaining text break points. The object calculates the positions of break points in the text based on the rules of the specified locale.
  let iterator: i18n.BreakIterator  = i18n.getLineInstance('en-GB');

  // Set the text to be processed.
  iterator.setLineBreakText('Apple is my favorite fruit.');

  // Move the line break iterator to the start of the text.
  let firstPos = iterator.first(); // firstPos = 0

  // Move the line break iterator forward by two break points. nextPos indicates the position in the text after the move. If it exceeds the text length, -1 is returned.
  let nextPos = iterator.next(2); // nextPos = 9

  // Obtain the position of the line break iterator in the text currently being processed.
  let currentPos = iterator.current(); // currentPos = 9

  // Determine whether a position is a break point.
  let isBoundary = iterator.isBoundary(9); // isBoundary = true

  // Obtain the text processed by the BreakIterator object.
  let breakText = iterator.getLineBreakText(); // breakText = 'Apple is my favorite fruit.'
  ```

- File path mirroring: File path mirroring means to localize a file path string when a mirrored language is passed in, so as to achieve the mirroring display effect of the file path in that language. You can implement file path mirroring by using the [getUnicodeWrappedFilePath](../reference/apis-localization-kit/js-apis-i18n.md#getunicodewrappedfilepath20) API of the **I18NUtil** class. The sample code is as follows:

  <!-- @[get_unicode_wrapped_file_path](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/International/Internationalization/entry/src/main/ets/i18napplication/CharacterProcessing.ets) -->

  ``` TypeScript
  let mirrorPath = '';
  let unMirrorPath = '';

  // Perform file path mirroring if mirrorPath is passed.
  let path = 'data/out/tmp';
  
  try {
    let delimiter = '/';
    let locale: Intl.Locale = new Intl.Locale('ar');
    // mirrorPath = 'tmp/out/data/'
    mirrorPath = i18n.I18NUtil.getUnicodeWrappedFilePath(path, delimiter, locale);

    // A non-mirrored language is passed in. The path is not processed.
    let localeZh: Intl.Locale = new Intl.Locale('zh');
    // unMirrorPath = '/data/out/tmp'
    unMirrorPath = i18n.I18NUtil.getUnicodeWrappedFilePath(path, delimiter, localeZh);
  } catch (error) {
    console.error(`call I18NUtil.getUnicodeWrappedFilePath failed, error code: ${error.code}, message: ${error.message}.`);
  }
  ```

<!--RP1--><!--RP1End-->

<!--no_check-->