# Globalization Subsystem Changelog

## cl.global.1 Language Sorting Array Change

**Access Level**

System API

**Reason for Change**

The sequence of the language list array returned by the **getLanguageInfoArray** API is incorrect. For example, if the country/region is **CN**, Simplified Chinese (zh-Hans), Tibetan (bo), and Uyghur (ug) should be placed in the front.

**Change Impact**

The sequence of the language list array is changed.

Before:

| Country/Region             | Input Parameter     | Array Sequence  |
| --------------- | ------- | -------- |
| CN                    | en,zh-Hans,bo,ug,zh-Hant       |   zh-Hans,en,bo,ug,zh-Hant  |
| SG                    | bo,en,zh-Hans,ug,zh-Hant |   zh-Hans,en,bo,ug,zh-Hant  |
| US                    | zh-Hans,bo,en,ug,zh-Hant       |   en,zh-Hant,zh-Hans,ug,bo  |
| HK               | zh-Hans,bo,en,ug,zh-Hant       |   zh-Hant,zh-Hans,en,ug,bo  |
| TW               | zh-Hans,bo,en,ug,zh-Hant       |   zh-Hant,zh-Hans,en,ug,bo  |
| AU               | zh-Hans,bo,en,ug,zh-Hant       |   zh-Hant,zh-Hans,en,ug,bo  |
| NZ               | zh-Hans,bo,en,ug,zh-Hant       |   zh-Hant,zh-Hans,en,ug,bo  |
| IN               | zh-Hans,bo,en,ug,zh-Hant       |   zh-Hant,zh-Hans,en,ug,bo  |
| GB               | zh-Hans,bo,en,ug,zh-Hant       |   zh-Hant,zh-Hans,en,ug,bo  |
| MO               | zh-Hans,bo,en,ug,zh-Hant       |   zh-Hant,zh-Hans,en,ug,bo  |
| CA               | zh-Hans,bo,en,ug,zh-Hant       |   zh-Hant,zh-Hans,en,ug,bo  |

After:

| Country/Region             | Input Parameter     | Array Sequence  |
| --------------- | ------- | -------- |
| CN                    | en,zh-Hans,bo,ug,zh-Hant       |   zh-Hans,ug,bo,zh-Hant,en  |
| SG                    | bo,en,zh-Hans,ug,zh-Hant |   en,zh-Hant,zh-Hans,ug,bo  |
| US                    | zh-Hans,bo,en,ug,zh-Hant       |   en,zh-Hant,zh-Hans,ug,bo  |
| HK               | zh-Hans,bo,en,ug,zh-Hant       |   zh-Hant,en,zh-Hans,ug,bo  |
| TW               | zh-Hans,bo,en,ug,zh-Hant       |   zh-Hant,zh-Hans,en,ug,bo  |
| AU               | zh-Hans,bo,en,ug,zh-Hant       |   en,zh-Hant,zh-Hans,ug,bo  |
| NZ               | zh-Hans,bo,en,ug,zh-Hant       |   en,zh-Hant,zh-Hans,ug,bo  |
| IN               | zh-Hans,bo,en,ug,zh-Hant       |   en,zh-Hant,zh-Hans,ug,bo  |
| GB               | zh-Hans,bo,en,ug,zh-Hant       |   en,zh-Hant,zh-Hans,ug,bo  |
| MO               | zh-Hans,bo,en,ug,zh-Hant       |   zh-Hant,en,zh-Hans,ug,bo  |
| CA               | zh-Hans,bo,en,ug,zh-Hant       |   en,zh-Hant,zh-Hans,ug,bo  |

**Start API Level**

10

**Change Since**

OpenHarmony SDK 5.1.0.48

**Key API/Component Changes**

i18n.SystemLocaleManager.getLanguageInfoArray

**Adaptation Guide**

Use this API in the language list sorting scenario.

## cl.global.2 Country/Region Sorting Array Change

**Access Level**

System API

**Reason for Change**

The sequence of the country/region list array returned by the **getRegionInfoArray** API is incorrect. For example, if the system language is simplified Chinese, only China is displayed in the front.

**Change Impact**

The sequence of the country/region list returned by the API is changed.

Before:

| System Language             | Input Parameter     | Array Sequence  |
| --------------- | ------- | -------- |
| en               | HK,TW,CN,AU,CA,IN,NZ,SG,GB,US,MO       |   US,AU,CA,IN,NZ,SG,GB,CN,HK,MO,TW  |
| zh-Hant          | HK,TW,CN,AU,CA,IN,NZ,SG,GB,US,MO       |   TW,HK,MO,CN,CA,IN,US,GB,NZ,SG,AU  |
| zh-Hans          | HK,TW,CN,AU,CA,IN,NZ,SG,GB,US,MO       |   SG,CN,MO,HK,AU,CA,US,NZ,IN,GB,TW  |
| ug               | HK,TW,CN,AU,CA,IN,NZ,SG,GB,US,MO       |   US,AU,GB,CN,MO,TW,HK,SG,CA,IN,NZ  |
| bo               | HK,TW,CN,AU,CA,IN,NZ,SG,GB,US,MO       |   CN,TW,HK,MO,CA,NZ,GB,SG,IN,US,AU  |

After:

| System Language             | Input Parameter     | Array Sequence  |
| --------------- | ------- | -------- |
| en               | HK,TW,CN,AU,CA,IN,NZ,SG,GB,US,MO       |   AU,CA,IN,NZ,SG,GB,US,CN,HK,MO,TW  |
| zh-Hant          | HK,TW,CN,AU,CA,IN,NZ,SG,GB,US,MO       |   TW,HK,CN,MO,CA,IN,US,GB,NZ,SG,AU  |
| zh-Hans          | HK,TW,CN,AU,CA,IN,NZ,SG,GB,US,MO       |   CN,AU,CA,US,SG,NZ,IN,GB,MO,TW,HK  |
| ug               | HK,TW,CN,AU,CA,IN,NZ,SG,GB,US,MO       |   CN,US,AU,GB,MO,TW,HK,SG,CA,IN,NZ  |
| bo               | HK,TW,CN,AU,CA,IN,NZ,SG,GB,US,MO       |   CN,TW,HK,MO,CA,NZ,GB,SG,IN,US,AU  |

**Start API Level**

10

**Change Since**

OpenHarmony SDK 5.1.0.48

**Key API/Component Changes**

i18n.SystemLocaleManager.getRegionInfoArray

**Adaptation Guide**

Use this API in the country/region list sorting scenario.

## cl.global.3 Language and Country/Region Mapping Change

**Access Level**

Public API

**Reason for Change**

The language and country/region matching rule is incorrect. For example, if the country/region is CN (China) and the language list contains zh-Hans (Simplified Chinese) and ug (Uyghur), the recommended language should be zh-Hans or ug. However, when the country/region is set to **CN** and the language is set to **ug**, the **isSuggested** API returns **false**, and the recommended language contains only **zh-Hans**.

**Change Impact**

This change does not require application adaptation.

Before:

| Language             | Country/Region     | Return Value  |
| --------------- | ------- | -------- |
| bo                | CN       |   false  |
| en                | AE,AF,AG,AI,AL,AS,AT,AU,BB,BE,BI,BM,BS,BW,BZ,CA,CC,CH,CK,CM,<br>CX,CY,DE,DG,DK,DM,ER,FI,FJ,FK,FM,GB,GD,GG,GH,GI,GM,GU,GY,HK,<br>IE,IL,IM,IN,IO,IR,JE,JM,KE,KI,KN,KY,LC,LR,LS,MG,MH,MO,MP,MS,<br>MT,MU,MV,MW,MY,NA,NF,NG,NL,NR,NU,NZ,PG,PH,PK,PN,PR,PW,RW,SB,<br>SC,SD,SE,SG,SH,SI,SL,SS,SX,SZ,TC,TJ,TK,TM,TO,TT,TV,TZ,UG,UM,<br>VC,VG,VI,VU,WS,ZA,ZM,ZW       |   false  |
| ug                | CN       |   false  |
| zh-Hans                | HK,SG,MO       |   true  |

After:

| Language             | Country/Region     | Return Value  |
| --------------- | ------- | -------- |
| bo                | CN       |   true  |
| en                | AE,AF,AG,AI,AL,AS,AT,AU,BB,BE,BI,BM,BS,BW,BZ,CA,CC,CH,CK,CM,<br>CX,CY,DE,DG,DK,DM,ER,FI,FJ,FK,FM,GB,GD,GG,GH,GI,GM,GU,GY,HK,<br>IE,IL,IM,IN,IO,IR,JE,JM,KE,KI,KN,KY,LC,LR,LS,MG,MH,MO,MP,MS,<br>MT,MU,MV,MW,MY,NA,NF,NG,NL,NR,NU,NZ,PG,PH,PK,PN,PR,PW,RW,SB,<br>SC,SD,SE,SG,SH,SI,SL,SS,SX,SZ,TC,TJ,TK,TM,TO,TT,TV,TZ,UG,UM,<br>VC,VG,VI,VU,WS,ZA,ZM,ZW       |   true  |
| ug                | CN       |   true  |
| zh-Hans                | HK,SG,MO       |   false  |

**Start API Level**

9

**Change Since**

OpenHarmony SDK 5.1.0.48

**Key API/Component Changes**

i18n.System.isSuggested

**Adaptation Guide**

No adaptation is required.
