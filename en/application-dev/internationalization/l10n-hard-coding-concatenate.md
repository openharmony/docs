# Hard Coding and Concatenation Prevention

<!--Kit: Localization Kit-->
<!--Subsystem: Global-->
<!--Owner: @yliupy-->
<!--Designer: @sunyaozu-->
<!--Tester: @lpw_work-->
<!--Adviser: @ningningW-->
<!-- md-trans-meta sourceCommit=2383e10e1c60a543f87f320ad35a31009cf92d39 translatedAt=2026-08-04T12:26:33.393Z pushedAt=2026-08-04T13:20:55.009Z -->

## Use Cases

A key part of localization is the translation of resource files. To improve the translation efficiency, avoid hard coding and concatenation during development.

For example, in the following figure, "Rain tomorrow" and "Bring an umbrella" are directly concatenated, causing a capitalization issue in the sentence.

![information-weather-forecast](figures/information-weather-forecast.png)

## Constraints

1. Avoid using hard coding. Extract the strings to be translated into resource files, separate them from the code, and use dedicated APIs for loading. For details, see [Multilingual Resource Provisioning](./l10n-multilingual-resources.md).

2. Do not directly concatenate strings. If variables (for example, **Video** and **Browser** in **Open Video** and **Open Browser**) are present, use placeholders as the substitute of variables to make the syntax complete.

   Example of a resource placeholder:

   ```ts
   {
     "name": "string1",
     "value": "Open %s"
   }
   ```