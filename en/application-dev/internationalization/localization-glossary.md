# Glossary

<!--Kit: Localization Kit-->
<!--Subsystem: Global-->
<!--Owner: @yliupy-->
<!--Designer: @sunyaozu-->
<!--Tester: @lpw_work-->
<!--Adviser: @ningningW-->
<!-- md-trans-meta sourceCommit=be7e35f23d7f85dfcac628b0e432069d01deb407 translatedAt=2026-08-04T12:27:13.706Z pushedAt=2026-08-04T13:24:01.956Z -->

## A

### Application Preferred Language

 The language preference configured for an application. If an application preferred language is set, the application loads resources for that language. Otherwise, it loads resources for the system preferred language.

## L

### Local Digit

The numeral system used in a specific locale. For example, in Arabic, both the common Arabic numerals (`0123456789`) and Arabic-Indic digits (`٠١٢٣٤٥٦٧٨٩`) can be used.

## S

### System Preferred Language

The language preference configured for the system. The system preferred language is represented as a prioritized language list, where the first language is the system language. When loading resources, the system attempts to load resources in the order of the list, giving priority to the first language. If no matching resources are available, it falls back to the next language in the list. Currently, only the first language in the list is supported for resource loading.