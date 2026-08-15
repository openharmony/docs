# Overview of Pseudo-Localization Testing

<!--Kit: Localization Kit-->
<!--Subsystem: Global-->
<!--Owner: @yliupy-->
<!--Designer: @zw_feifei-->
<!--Tester: @lpw_work-->
<!--Adviser: @ningningW-->
<!-- md-trans-meta sourceCommit=1a7fdda7cb0bdacc6b1c367c8fd0def17530cd88 translatedAt=2026-08-15T01:54:19.585Z pushedAt=2026-08-15T08:42:54.274Z -->

Pseudo-localization is also called pseudo-translation. It simulates the localization process to help find potential problems and avoid function defects. It is commonly used in software testing to test whether the software complies with localization and internationalization specifications. Pseudo-localization does not translate the text of the software into a foreign language. Instead, it replaces the text with localized text according to certain rules to simulate the localization process.

For newly developed software or software with great UI changes, the delivery period may be delayed if UI testing is performed after the translation is complete. Besides, software UI is apt to change at the early stage of development and therefore translation of UI text is generally not feasible during this period. If translation is done when the product becomes mature, the translation and testing process may delay the product release. This is no longer a challenge with pseudo-localization testing, which helps to uncover potential problems before you actually begin to localize your product.

It can be categorized into [pseudo-localization testing for translation](pseudo-i18n-testing-translation.md) and [pseudo-localization testing for UI mirroring](pseudo-i18n-testing-mirror.md).