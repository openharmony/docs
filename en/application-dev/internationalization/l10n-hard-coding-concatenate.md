# Hard Coding and Concatenation Prevention

<!--Kit: Localization Kit-->
<!--Subsystem: Global-->
<!--Owner: @yliupy-->
<!--Designer: @zw_feifei-->
<!--Tester: @lpw_work-->
<!--Adviser: @ningningW-->
<!-- md-trans-meta sourceCommit=1a7fdda7cb0bdacc6b1c367c8fd0def17530cd88 translatedAt=2026-08-15T01:53:58.474Z pushedAt=2026-08-15T08:42:37.558Z -->

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