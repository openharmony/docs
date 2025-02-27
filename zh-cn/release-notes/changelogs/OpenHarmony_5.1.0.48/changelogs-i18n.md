# 全球化子系统Changelog

## cl.global.1 语言排序数组变更

**访问级别**

系统接口

**变更原因**

接口返回数组的顺序错误，例如，系统地区选中国，简体中文（zh-Hans）、藏语（bo）、维吾尔语（ug）应该排在前面。

**变更影响**

影响接口返回的语言列表顺序。

变更前：

| 系统地区              | 接口入参      | 返回数组的顺序   |
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

变更后：

| 系统地区              | 接口入参      | 返回数组的顺序   |
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

**起始API Level**

10

**变更发生版本**

从OpenHarmony SDK 5.1.0.48开始

**变更的接口/组件**

i18n.SystemLocaleManager.getLanguageInfoArray

**适配指导**

该接口适用于语言列表排序场景。

## cl.global.2 地区排序数组变更

**访问级别**

系统接口

**变更原因**

接口返回数组的顺序错误，例如，系统语言选简体中文，应该只有中国排在前面。

**变更影响**

影响接口返回的地区列表顺序。

变更前：

| 系统语言              | 接口入参      | 返回数组的顺序   |
| --------------- | ------- | -------- |
| en               | HK,TW,CN,AU,CA,IN,NZ,SG,GB,US,MO       |   US,AU,CA,IN,NZ,SG,GB,CN,HK,MO,TW  |
| zh-Hant          | HK,TW,CN,AU,CA,IN,NZ,SG,GB,US,MO       |   TW,HK,MO,CN,CA,IN,US,GB,NZ,SG,AU  |
| zh-Hans          | HK,TW,CN,AU,CA,IN,NZ,SG,GB,US,MO       |   SG,CN,MO,HK,AU,CA,US,NZ,IN,GB,TW  |
| ug               | HK,TW,CN,AU,CA,IN,NZ,SG,GB,US,MO       |   US,AU,GB,CN,MO,TW,HK,SG,CA,IN,NZ  |
| bo               | HK,TW,CN,AU,CA,IN,NZ,SG,GB,US,MO       |   CN,TW,HK,MO,CA,NZ,GB,SG,IN,US,AU  |

变更后：

| 系统语言              | 接口入参      | 返回数组的顺序   |
| --------------- | ------- | -------- |
| en               | HK,TW,CN,AU,CA,IN,NZ,SG,GB,US,MO       |   AU,CA,IN,NZ,SG,GB,US,CN,HK,MO,TW  |
| zh-Hant          | HK,TW,CN,AU,CA,IN,NZ,SG,GB,US,MO       |   TW,HK,CN,MO,CA,IN,US,GB,NZ,SG,AU  |
| zh-Hans          | HK,TW,CN,AU,CA,IN,NZ,SG,GB,US,MO       |   CN,AU,CA,US,SG,NZ,IN,GB,MO,TW,HK  |
| ug               | HK,TW,CN,AU,CA,IN,NZ,SG,GB,US,MO       |   CN,US,AU,GB,MO,TW,HK,SG,CA,IN,NZ  |
| bo               | HK,TW,CN,AU,CA,IN,NZ,SG,GB,US,MO       |   CN,TW,HK,MO,CA,NZ,GB,SG,IN,US,AU  |

**起始API Level**

10

**变更发生版本**

从OpenHarmony SDK 5.1.0.48开始

**变更的接口/组件**

i18n.SystemLocaleManager.getRegionInfoArray

**适配指导**

该接口适用于地区列表排序场景。

## cl.global.3 语言地区匹配关系变更

**访问级别**

公开接口

**变更原因**

接口返回值错误，例如语言为简体中文（zh-Hans）、地区为中国香港（HK），语言和地区不匹配，但返回为true。
当isSuggested接口用于语言列表排序时，如果接口的region参数传入系统地区，与系统地区不匹配的语言就会排在前面，影响用户体验。

**变更影响**

该变更不涉及应用适配。

变更前：

| 语言              | 地区      | 返回值   |
| --------------- | ------- | -------- |
| bo                | CN       |   false  |
| en                | AE,AF,AG,AI,AL,AS,AT,AU,BB,BE,BI,BM,BS,BW,BZ,CA,CC,CH,CK,CM,<br>CX,CY,DE,DG,DK,DM,ER,FI,FJ,FK,FM,GB,GD,GG,GH,GI,GM,GU,GY,HK,<br>IE,IL,IM,IN,IO,IR,JE,JM,KE,KI,KN,KY,LC,LR,LS,MG,MH,MO,MP,MS,<br>MT,MU,MV,MW,MY,NA,NF,NG,NL,NR,NU,NZ,PG,PH,PK,PN,PR,PW,RW,SB,<br>SC,SD,SE,SG,SH,SI,SL,SS,SX,SZ,TC,TJ,TK,TM,TO,TT,TV,TZ,UG,UM,<br>VC,VG,VI,VU,WS,ZA,ZM,ZW       |   false  |
| ug                | CN       |   false  |
| zh-Hans                | HK,SG,MO       |   true  |

变更后：

| 语言              | 地区      | 返回值   |
| --------------- | ------- | -------- |
| bo                | CN       |   true  |
| en                | AE,AF,AG,AI,AL,AS,AT,AU,BB,BE,BI,BM,BS,BW,BZ,CA,CC,CH,CK,CM,<br>CX,CY,DE,DG,DK,DM,ER,FI,FJ,FK,FM,GB,GD,GG,GH,GI,GM,GU,GY,HK,<br>IE,IL,IM,IN,IO,IR,JE,JM,KE,KI,KN,KY,LC,LR,LS,MG,MH,MO,MP,MS,<br>MT,MU,MV,MW,MY,NA,NF,NG,NL,NR,NU,NZ,PG,PH,PK,PN,PR,PW,RW,SB,<br>SC,SD,SE,SG,SH,SI,SL,SS,SX,SZ,TC,TJ,TK,TM,TO,TT,TV,TZ,UG,UM,<br>VC,VG,VI,VU,WS,ZA,ZM,ZW       |   true  |
| ug                | CN       |   true  |
| zh-Hans                | HK,SG,MO       |   false  |

**起始API Level**

9

**变更发生版本**

从OpenHarmony SDK 5.1.0.48开始。

**变更的接口/组件**

i18n.System.isSuggested

**适配指导**

默认行为变更，无需适配。
