# 全球化子系统Changelog

## cl.global.1 语言地区匹配关系变更

**访问级别**

公开接口

**变更原因**

 1、接口返回值错误，例如简体中文（zh-Hans）和中国香港（HK）是不匹配的却返回了true。

**变更影响**

该变更为不兼容性变更。

变更前：

| 语言              | 地区      | 返回值   |
| --------------- | ------- | -------- |
| bo                | CN       |   false  |
| en                | AE,AF,AG,AI,AL,AS,AT,AU,BB,BE,BI,BM,BS,BW,<br>BZ,CA,CC,CH,CK,CM,CX,CY,DE,DG,DK,DM,ER,FI,FJ,FK,FM,GB,GD,GG,GH,<br>GI,GM,GU,GY,HK,IE,IL,IM,IN,IO,IR,JE,JM,KE,KI,KN,KY,LC,LR,LS,MG,<br>MH,MO,MP,MS,MT,MU,MV,MW,MY,NA,NF,NG,NL,NR,NU,NZ,PG,PH,PK,PN,PR,PW,<br>RW,SB,SC,SD,SE,SG,SH,SI,SL,SS,SX,SZ,TC,TJ,TK,TM,TO,TT,TV,TZ,UG,<br>UM,VC,VG,VI,VU,WS,ZA,ZM,ZW       |   false  |
| ug                | CN       |   false  |
| zh-Hans                | HK,SG,MO       |   true  |

变更后：

| 语言              | 地区      | 返回值   |
| --------------- | ------- | -------- |
| bo                | CN       |   true  |
| en                | AE,AF,AG,AI,AL,AS,AT,AU,BB,BE,BI,BM,BS,BW,<br>BZ,CA,CC,CH,CK,CM,CX,CY,DE,DG,DK,DM,ER,FI,FJ,FK,FM,GB,GD,GG,GH,<br>GI,GM,GU,GY,HK,IE,IL,IM,IN,IO,IR,JE,JM,KE,KI,KN,KY,LC,LR,LS,MG,<br>MH,MO,MP,MS,MT,MU,MV,MW,MY,NA,NF,NG,NL,NR,NU,NZ,PG,PH,PK,PN,PR,PW,<br>RW,SB,SC,SD,SE,SG,SH,SI,SL,SS,SX,SZ,TC,TJ,TK,TM,TO,TT,TV,TZ,UG,<br>UM,VC,VG,VI,VU,WS,ZA,ZM,ZW       |   true  |
| ug                | CN       |   true  |
| zh-Hans                | HK,SG,MO       |   false  |

**起始API Level**

9

**变更发生版本**

从OpenHarmony SDK 5.1.0.47开始

**变更的接口/组件**

i18n.system.isSuggested

**适配指导**

该接口适用于语言列表排序场景。

