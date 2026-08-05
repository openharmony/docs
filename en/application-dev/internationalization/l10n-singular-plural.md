# Singular/Plural Form Selection

<!--Kit: Localization Kit-->
<!--Subsystem: Global-->
<!--Owner: @yliupy-->
<!--Designer: @sunyaozu-->
<!--Tester: @lpw_work-->
<!--Adviser: @ningningW-->
<!-- md-trans-meta sourceCommit=9d4329aa9b07ce81fc1a2c848fb4cea93e274a8e translatedAt=2026-08-04T12:26:51.579Z pushedAt=2026-08-04T13:22:39.204Z -->

During translation, different languages have varying requirements for singular and plural forms of nouns or unit expressions. Some languages do not distinguish between singular and plural, some have two forms, and others have multiple forms. For example, English nouns support two singular/plural forms, whereas Chinese nouns do not distinguish between singular and plural and instead express quantity through measure words.

Singular and plural numbers are usually distinguished by the following categories:

- zero: 0 or numbers ending with 0

- one: 1 or numbers ending with 1

- two: numbers ending with 2

- few: numbers with a small value

- many: numbers with a large value

- other: other cases

For example, in Arabic, the plural rules are as follows:

- zero : 0

- one: 1

- two: 2

- few: 3 to 10, 103 to 110, 1003...

- many: 11 to 26, 111, 1011...

- other: 100 to 102, 200 to 202, 1000, 10000...

## How to Develop

For details about how to use the APIs, see [getIntPluralStringValueSync](../reference/apis-localization-kit/js-apis-resource-manager.md#getintpluralstringvaluesync18).