# Internationalization Overview


If an application is targeted for users and markets in different regions with different languages and time zones, it is necessary for you to provide localized versions to ensure good experience for your users.


Internationalization capabilities determine how hard or easy application localization will be. With the rich internationalization APIs provided by the system, localization is much more efficient and cost-effective, accelerating your design and implementation of a well-internationalized application.


## Basic Concepts

- Locale: an abstract representation of the commonalities of a group in terms of language, script, country or region, and other regional features such as calendar, sorting, and currency.

- Preferred language: the language that the user prefers to use in a service or system. You can add a preferred language by choosing **Settings** &gt; **System &amp; updates** &gt; **Language &amp; input** &gt; **Language and region** &gt; **ADD LANGUAGE** on your device.


## Working Principles

You just need to specify a locale when calling internationalization APIs, and localization will be automatically implemented for that locale. Locale information can be hard coded, but it is more common for users to set the system language and region by themselves.


## Constraints

None
