# ICU4C

In today's software market, applications need to support multiple languages for efficient development and maintenance. The International Components for Unicode (ICU) library provides powerful and complete multilingual cultural information processing capability to address this demand.

[ICU4C](https://unicode-org.github.io/icu/userguide/icu4c/) is the C language version of the ICU library. Some APIs have been opened and support the following capabilities:

- Locale and culture division (uloc.h)
- Date and time formatting (udat.h)
- Number formatting and weights and measures formatting (unumberformatter.h and unum.h)
- Calendar and local calendar (ucal.h)
- Sorting (ucol.h)
- Line wrapping (ubrk.h)
- Text normalization (unorm2.h)
- Transliteration (utrans.h)
- Character/text attribute setting (uchar.h and uscript.h)
- Code conversion (ucnv.h)
- Bidirectional text processing (ubidi.h)
- Domain name conversion (uidna.h)
- Unicode string processing (ustring.h)
- ICU text abstract representation (utext.h)

## Introducing ICU4C Internationalization Capabilities

If you need to use ICU4C internationalization capabilities, add the corresponding header file as required. Add the unicode directory prefix to the header file of this module. For example:
```
#include <unicode/uloc.h>
```

Add the following dynamic library to CMakeList.txt:
```
libicu.so
```

## Symbols Exported from the Standard Library

[ICU4C Symbols Exported from Native APIs](icu4c-symbol.md)
