# @ohos.nfc.tag    
本模块主要用于操作及管理NFC Tag。  
> **说明**   
>本模块首批接口从API version 7开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
## 导入模块  
  
```js    
import tag from '@ohos.nfc.tag'    
```  
    
 **常量：**     
 **系统能力:**  SystemCapability.Communication.NFC.Tag    
| 名称 | 类型 | 值 | 说明 |  
| --------| --------| --------| --------|  
| NFC_A | number | 1 | NFC-A (ISO 14443-3A)技术。 |  
| NFC_B | number | 2 | NFC-B (ISO 14443-3B)技术。 |  
| ISO_DEP | number | 3 | ISO-DEP (ISO 14443-4)技术。 |  
| NFC_F | number | 4 | NFC-F (JIS 6319-4)技术。 |  
| NFC_V | number | 5 | NFC-V (ISO 15693)技术。 |  
| NDEF | number | 6 | NDEF技术。     |  
| NDEF_FORMATABLE<sup>(9+)</sup> | number | 7 |  可以格式化的NDEF技术。 |  
| MIFARE_CLASSIC | number | 8 |  MIFARE Classic技术。 |  
| MIFARE_ULTRALIGHT | number | 9 | MIFARE Utralight技术。  |  
| RTD_TEXT<sup>(9+)</sup> | number[] |  |  |  
| RTD_URI<sup>(9+)</sup> | number[] |  |  |  
    
## TnfType<sup>(9+)</sup>    
    
 **系统能力:**  SystemCapability.Communication.NFC.Tag    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| TNF_EMPTY | 0x0 | Empty。  |  
| TNF_WELL_KNOWN | 0x1 | NFC Forum well-known type [NFC RTD]。  |  
| TNF_MEDIA | 0x2 | Media-type as defined in RFC 2046 [RFC 2046]。 |  
| TNF_ABSOLUTE_URI | 0x3 | Absolute URI as defined in RFC 3986 [RFC 3986]。 |  
| TNF_EXT_APP | 0x4 | NFC Forum external type [NFC RTD]。  |  
| TNF_UNKNOWN | 0x5 | Unknown。 |  
| TNF_UNCHANGED | 0x6 | Unchanged (see section 2.3.3)。 |  
    
## NfcForumType<sup>(9+)</sup>    
    
 **系统能力:**  SystemCapability.Communication.NFC.Tag    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| NFC_FORUM_TYPE_1 | 1 | NFC论坛类型1。     |  
| NFC_FORUM_TYPE_2 | 2 | NFC论坛类型2。 |  
| NFC_FORUM_TYPE_3 | 3 | NFC论坛类型3。 |  
| NFC_FORUM_TYPE_4 | 4 |  NFC论坛类型4。 |  
| MIFARE_CLASSIC | 101 | MIFARE Classic类型。 |  
    
## MifareClassicType<sup>(9+)</sup>    
    
 **系统能力:**  SystemCapability.Communication.NFC.Tag    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| TYPE_UNKNOWN | 0 | 未知的MIFARE类型。 |  
| TYPE_CLASSIC | 1 | MIFARE Classic类型。 |  
| TYPE_PLUS | 2 | MIFARE Plus类型。 |  
| TYPE_PRO | 3 | MIFARE Pro类型。 |  
    
## MifareClassicSize<sup>(9+)</sup>    
    
 **系统能力:**  SystemCapability.Communication.NFC.Tag    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| MC_SIZE_MINI | 320 | 每个标签5个扇区，每个扇区4个块。 |  
| MC_SIZE_1K | 1024 | 每个标签16个扇区，每个扇区4个块。 |  
| MC_SIZE_2K | 2048 | 每个标签32个扇区，每个扇区4个块。 |  
| MC_SIZE_4K | 4096 | 每个标签40个扇区，每个扇区4个块。 |  
    
## MifareUltralightType<sup>(9+)</sup>    
    
 **系统能力:**  SystemCapability.Communication.NFC.Tag    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| TYPE_UNKNOWN | 0 | 未知的 MIFARE 类型。 |  
| TYPE_ULTRALIGHT | 1 | MIFARE Ultralight类型。 |  
| TYPE_ULTRALIGHT_C | 2 | MIFARE UltralightC 类型。 |  
    
## getNfcATag<sup>(deprecated)</sup>    
获取NFC A类型Tag对象，通过该对象可访问NfcA技术类型的Tag。  
 **调用形式：**     
- getNfcATag(tagInfo: TagInfo): NfcATag  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.nfc.tag/tag#getNfcA。  
 **系统能力:**  SystemCapability.Communication.NFC.Tag    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| tagInfo<sup>(deprecated)</sup> | TagInfo | true | 包含Tag技术类型和相关参数，从tag.getTagInfo(want: Want)获取。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| NfcATag | NFC A类型Tag对象。 |  
    
## getNfcA<sup>(9+)</sup>    
获取NFC A类型Tag对象，通过该对象可访问NfcA技术类型的Tag。  
 **调用形式：**     
- getNfcA(tagInfo: TagInfo): NfcATag  
  
 **系统能力:**  SystemCapability.Communication.NFC.Tag    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| tagInfo | TagInfo | true | 包含Tag技术类型和相关参数，从tag.getTagInfo(want: Want)获取。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| NfcATag | NFC A类型Tag对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 801 |  |  
| 3100201 | Tag running state is abnormal in service. |  
    
## getNfcBTag<sup>(deprecated)</sup>    
获取NFC B类型Tag对象，通过该对象可访问NfcB技术类型的Tag。  
 **调用形式：**     
- getNfcBTag(tagInfo: TagInfo): NfcBTag  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.nfc.tag/tag#getNfcB。  
 **系统能力:**  SystemCapability.Communication.NFC.Tag    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| tagInfo<sup>(deprecated)</sup> | TagInfo | true | 获取NFC B类型Tag对象，通过该对象可访问NfcB技术类型的Tag。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| NfcBTag | NFC B类型Tag对象。 |  
    
## getNfcB<sup>(9+)</sup>    
获取NFC B类型Tag对象，通过该对象可访问NfcB技术类型的Tag。  
 **调用形式：**     
- getNfcB(tagInfo: TagInfo): NfcBTag  
  
 **系统能力:**  SystemCapability.Communication.NFC.Tag    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| tagInfo | TagInfo | true | 包含Tag技术类型和相关参数，从tag.getTagInfo(want: Want)获取。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| NfcBTag | NFC B类型Tag对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 801 |  |  
| 3100201 | Tag running state is abnormal in service. |  
    
## getNfcFTag<sup>(deprecated)</sup>    
获取NFC F类型Tag对象，通过该对象可访问NfcF技术类型的Tag。  
 **调用形式：**     
- getNfcFTag(tagInfo: TagInfo): NfcFTag  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.nfc.tag/tag#getNfcF。  
 **系统能力:**  SystemCapability.Communication.NFC.Tag    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| tagInfo<sup>(deprecated)</sup> | TagInfo | true | 包含Tag技术类型和相关参数，从tag.getTagInfo(want: Want)获取。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| NfcFTag | NFC F类型Tag对象。 |  
    
## getNfcF<sup>(9+)</sup>    
获取NFC F类型Tag对象，通过该对象可访问NfcF技术类型的Tag。  
 **调用形式：**     
- getNfcF(tagInfo: TagInfo): NfcFTag  
  
 **系统能力:**  SystemCapability.Communication.NFC.Tag    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| tagInfo | TagInfo | true | 包含Tag技术类型和相关参数，从tag.getTagInfo(want: Want)获取。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| NfcFTag | NFC F类型Tag对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 801 |  |  
| 3100201 | Tag running state is abnormal in service. |  
    
## getNfcVTag<sup>(deprecated)</sup>    
获取NFC V类型Tag对象，通过该对象可访问NfcV技术类型的Tag。  
 **调用形式：**     
- getNfcVTag(tagInfo: TagInfo): NfcVTag  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.nfc.tag/tag#getNfcV。  
 **系统能力:**  SystemCapability.Communication.NFC.Tag    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| tagInfo<sup>(deprecated)</sup> | TagInfo | true | 包含Tag技术类型和相关参数，从tag.getTagInfo(want: Want)获取。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| NfcVTag | NFC V类型Tag对象。 |  
    
## getNfcV<sup>(9+)</sup>    
获取NFC V类型Tag对象，通过该对象可访问NfcV技术类型的Tag。  
 **调用形式：**     
- getNfcV(tagInfo: TagInfo): NfcVTag  
  
 **系统能力:**  SystemCapability.Communication.NFC.Tag    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| tagInfo | TagInfo | true | 包含Tag技术类型和相关参数，从tag.getTagInfo(want: Want)获取。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| NfcVTag | NFC V类型Tag对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 801 |  |  
| 3100201 | Tag running state is abnormal in service. |  
    
## getIsoDep<sup>(9+)</sup>    
获取IsoDep类型Tag对象，通过该对象可访问支持IsoDep技术类型的Tag。  
 **调用形式：**     
- getIsoDep(tagInfo: TagInfo): IsoDepTag  
  
 **系统能力:**  SystemCapability.Communication.NFC.Tag    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| tagInfo | TagInfo | true | 包含Tag技术类型和相关参数，从tag.getTagInfo(want: Want)获取。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| IsoDepTag | IsoDep类型Tag对象，通过该对象访问IsoDep类型的相关接口。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 801 |  |  
| 3100201 | Tag running state is abnormal in service. |  
    
## getNdef<sup>(9+)</sup>    
获取NDEF类型Tag对象，通过该对象可访问支持NDEF技术类型的Tag。  
 **调用形式：**     
- getNdef(tagInfo: TagInfo): NdefTag  
  
 **系统能力:**  SystemCapability.Communication.NFC.Tag    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| tagInfo | TagInfo | true | 包含Tag技术类型和相关参数，从tag.getTagInfo(want: Want)获取。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| NdefTag | NDEF类型Tag对象，通过该对象访问NDEF类型的相关接口。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 801 |  |  
| 3100201 | ag running state is abnormal in service. |  
    
## getMifareClassic<sup>(9+)</sup>    
获取MIFARE Classic类型Tag对象，通过该对象访问支持MIFARE Classic技术类型的Tag。  
 **调用形式：**     
- getMifareClassic(tagInfo: TagInfo): MifareClassicTag  
  
 **系统能力:**  SystemCapability.Communication.NFC.Tag    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| tagInfo | TagInfo | true | 包含Tag技术类型和相关参数，从tag.getTagInfo(want: Want)获取。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| MifareClassicTag | MIFARE Classic类型Tag对象，通过该对象访问MIFARE Classic类型的相关接口。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 801 |  |  
| 3100201 | Tag running state is abnormal in service. |  
    
## getMifareUltralight<sup>(9+)</sup>    
获取MIFARE Ultralight类型Tag对象，通过该对象可访问支持MIFARE Ultralight技术类型的Tag。  
 **调用形式：**     
- getMifareUltralight(tagInfo: TagInfo): MifareUltralightTag  
  
 **系统能力:**  SystemCapability.Communication.NFC.Tag    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| tagInfo | TagInfo | true | 包含Tag技术类型和相关参数，从tag.getTagInfo(want: Want)获取 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| MifareUltralightTag | MIFARE Ultralight类型Tag对象，通过该对象访问MIFARE Ultralight类型的相关接口。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 801 |  |  
| 3100201 | Tag running state is abnormal in service. |  
    
## getNdefFormatable<sup>(9+)</sup>    
获取NDEF Formatable类型Tag对象，通过该对象可访问支持NDEF Formatable技术类型的Tag。  
 **调用形式：**     
- getNdefFormatable(tagInfo: TagInfo): NdefFormatableTag  
  
 **系统能力:**  SystemCapability.Communication.NFC.Tag    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| tagInfo | TagInfo | true |  |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| NdefFormatableTag | NDEF Formatable类型Tag对象，通过该对象访问NDEF Formatable类型的相关接口。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 801 |  |  
| 3100201 | Tag running state is abnormal in service. |  
    
## getTagInfo<sup>(9+)</sup>    
从Want中获取TagInfo，Want是被NFC服务初始化，包含了TagInfo所需的属性值。  
 **调用形式：**     
- getTagInfo(want: Want): TagInfo  
  
 **系统能力:**  SystemCapability.Communication.NFC.Tag    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| want | Want | true | 分发Ability时，在系统onCreate入口函数的参数中获取。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| TagInfo | TagInfo对象，用于获取不同技术类型的Tag对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 801 |  |  
    
## registerForegroundDispatch<sup>(10+)</sup>    
注册对NFC Tag前台应用读卡事件的监听，通过discTech设置支持的Tag技术类型，通过Callback方式获取读取到Tag的[TagInfo](#taginfo)信息。需要与取消监听接口[tag.unregisterForegroundDispatch](#tagunregisterforegrounddispatch10)成对使用，如果已注册事件监听，需要在页面退出前台或页面销毁前调用取消注册。  
 **调用形式：**     
    
- registerForegroundDispatch(     elementName: ElementName,     discTech: number[],     callback: AsyncCallback\<TagInfo>   ): void    
起始版本： 10  
  
 **系统能力:**  SystemCapability.Communication.NFC.Tag  
 **需要权限：** ohos.permission.NFC_TAG    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| elementName | ElementName | true | 所属应用页面的信息（必须至少包含bundleName、abilityName、moduleName三项）。  |  
| discTech | number[] | true | 前台分发模式支持的技术类型，每个number值表示所支持技术类型的常量值型，根据number值设置NFC读卡轮询的Tag技术类型（支持[NFC_A](#技术类型定义), [NFC_B](#技术类型定义), [NFC_F](#技术类型定义), [NFC_V](#技术类型定义), 技术类型定义中的其他技术类型不属于NFC读卡轮询的Tag技术类型）并关闭卡模拟；当数组长度为0时，同时关闭读卡轮询和卡模拟。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| callback | 前台读卡监听回调函数。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 401 |  |  
| 801 |  |  
    
## unregisterForegroundDispatch<sup>(10+)</sup>    
取消注册对NFC Tag前台应用读卡事件的监听。如果已注册事件监听，需要在页面退出前台或页面销毁前调用取消注册。  
 **调用形式：**     
- unregisterForegroundDispatch(elementName: ElementName): void  
  
 **系统能力:**  SystemCapability.Communication.NFC.Tag  
 **需要权限：** ohos.permission.NFC_TAG    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| elementName | ElementName | true | 所属应用页面的信息（必须至少包含bundleName、abilityName、moduleName三项）。  |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 201 |  |  
| 401 |  |  
| 801 |  |  
    
 **示例代码：**   
```js    
import Want from '@ohos.app.ability.Want'  
import UIAbility from '@ohos.app.ability.UIAbility'  
import tag from '@ohos.nfc.tag';  
import { BusinessError } from '@ohos.base';  
import bundleManager from '@ohos.bundle.bundleManager';  
import AbilityConstant from '@ohos.app.ability.AbilityConstant';  
  
let discTech : number[] = [tag.NFC_A, tag.NFC_B]; // replace with the tech(s) that is needed by foreground ability  
let elementName : bundleManager.ElementName;  
function foregroundCb(err : BusinessError, tagInfo : tag.TagInfo) {  
    if (err as BusinessError) {  
        if (!err) {  
            console.log("foreground callback: tag found tagInfo = ", JSON.stringify(tagInfo));  
        } else {  
            console.log("foreground callback err: " + (err as BusinessError).message);  
            return;  
        }  
    }  
  // other Operations of taginfo  
}  
  
export default class MainAbility extends UIAbility {  
    OnCreate(want : Want, launchParam : AbilityConstant.LaunchParam) {  
        console.log("OnCreate");  
        elementName = {  
            bundleName: want.bundleName as string,  
            abilityName: want.abilityName as string,  
            moduleName: want.moduleName as string  
        }  
    }  
  
    onForeground() {  
        console.log("onForeground");  
        try {  
            tag.registerForegroundDispatch(elementName, discTech, foregroundCb);  
        } catch (e) {  
            console.error("registerForegroundDispatch error: " + (e as BusinessError).message);  
        }  
    }  
  
    onBackground() {  
        console.log("onBackground");  
        try {  
            tag.unregisterForegroundDispatch(elementName);  
        } catch (e) {  
            console.error("registerForegroundDispatch error: " + (e as BusinessError).message);  
        }  
    }  
  
    onWindowStageDestroy() {  
        console.log("onWindowStageDestroy");  
        try {  
            tag.unregisterForegroundDispatch(elementName);  
        } catch (e) {  
            console.error("registerForegroundDispatch error: " + (e as BusinessError).message);  
        }  
    }  
  
  // override other lifecycle functions  
}  
    
```    
  
    
## TagInfo    
NFC服务在读取到标签时给出的对象，通过改对象属性，应用知道该标签支持哪些技术类型，并使用匹配的技术类型来调用相关接口。  
 **系统能力:**  SystemCapability.Communication.NFC.Tag    
### 属性    
 **需要权限：** ohos.permission.NFC_TAG    
 **系统能力:**  SystemCapability.Communication.NFC.Tag    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| uid<sup>(9+)</sup> | number[] | false | true | 标签的uid，每个number值是十六进制表示，范围是0x00~0xFF。  |  
| technology<sup>(9+)</sup> | number[] | false | true | 支持的技术类型，每个number值表示所支持技术类型的常量值。 |  
| supportedProfiles<sup>(deprecated)</sup> | number[] | false | true | 从API version 7 开始支持，从API version 9 开始废弃。建议使用ohos.nfc.tag/tag.TagInfo#technology替代。<br>支持的技术类型，从API9开始不支持，使用[tag.TagInfo#technology](#tagtaginfo)替代。 |  
    
## NdefRecord<sup>(9+)</sup>    
NDEF标签Record属性的定义，参考NDEF标签技术规范《NFCForum-TS-NDEF_1.0》的定义细节。  
 **系统能力:**  SystemCapability.Communication.NFC.Tag    
### 属性    
 **系统能力:**  SystemCapability.Communication.NFC.Tag    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| tnf<sup>(9+)</sup> | number | false | true |  NDEF Record的TNF(Type Name Field)。  |  
| rtdType<sup>(9+)</sup> | number[] | false | true | NDEF Record的RTD(Record Type Definition)类型值，每个number十六进制表示，范围是0x00~0xFF。 |  
| id<sup>(9+)</sup> | number[] | false | true | NDEF Record的ID，每个number十六进制表示，范围是0x00~0xFF。   |  
| payload<sup>(9+)</sup> | number[] | false | true | NDEF Record的PAYLOAD，每个number十六进制表示，范围是0x00~0xFF。           |  
    
## makeUriRecord<sup>(9+)</sup>    
根据输入的URI，构建NDEF标签的Record数据对象。  
 **调用形式：**     
- makeUriRecord(uri: string): NdefRecord  
  
 **系统能力:**  SystemCapability.Communication.NFC.Tag    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| uri | string | true | 写入到NDEF Record里面的数据内容。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| NdefRecord | NDEF标签的Record，详见NDEF技术规范《NFCForum-TS-NDEF_1.0》。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
    
 **示例代码：**   
```js    
import tag from '@ohos.nfc.tag';  
  
try {  
    let uri = "https://gitee.com/openharmony"; // change it to be correct.  
    let ndefRecord = tag.ndef.makeUriRecord(uri);  
    if (ndefRecord != undefined) {  
        console.log("ndefMessage makeUriRecord rtdType: " + ndefRecord.rtdType);  
        console.log("ndefMessage makeUriRecord payload: " + ndefRecord.payload);  
    } else {  
        console.log("ndefMessage makeUriRecord ndefRecord: " + ndefRecord);  
    }  
} catch (busiError) {  
    console.error("ndefMessage makeUriRecord catched busiError: " + busiError);  
}  
    
```    
  
    
## makeTextRecord<sup>(9+)</sup>    
根据输入的文本数据和编码类型，构建NDEF标签的Record。  
 **调用形式：**     
- makeTextRecord(text: string, locale: string): NdefRecord  
  
 **系统能力:**  SystemCapability.Communication.NFC.Tag    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| text | string | true | 写入到NDEF Record里面的文本数据内容。 |  
| locale | string | true | 文本数据内容的编码方式。   |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| NdefRecord | NDEF标签的Record，详见NDEF技术规范《NFCForum-TS-NDEF_1.0》。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
    
 **示例代码：**   
```js    
import tag from '@ohos.nfc.tag';  
  
try {  
    let text = "Hello World";   // change it to be correct.  
    let locale = "en"; // change it to be correct.  
    let ndefRecord = tag.ndef.makeTextRecord(text, locale);  
    if (ndefRecord != undefined) {  
        console.log("ndefMessage makeTextRecord rtdType: " + ndefRecord.rtdType);  
        console.log("ndefMessage makeTextRecord payload: " + ndefRecord.payload);  
    } else {  
        console.log("ndefMessage makeTextRecord ndefRecord: " + ndefRecord);  
    }  
} catch (busiError) {  
    console.error("ndefMessage makeTextRecord catched busiError: " + busiError);  
}  
    
```    
  
    
## makeMimeRecord<sup>(9+)</sup>    
根据输入的MIME数据和类型，构建NDEF标签的Record。  
 **调用形式：**     
- makeMimeRecord(mimeType: string, mimeData: number[]): NdefRecord  
  
 **系统能力:**  SystemCapability.Communication.NFC.Tag    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| mimeType | string | true | 符合RFC规则的MIME类型，比如"text/plain"或"image/jpeg"。 |  
| mimeData | number[] | true | MIME数据内容，每个number十六进制表示，范围是0x00~0xFF。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| NdefRecord | NDEF标签的Record，详见NDEF技术规范《NFCForum-TS-NDEF_1.0》。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
    
 **示例代码：**   
```js    
import tag from '@ohos.nfc.tag';  
  
try {  
    let mimeType = "text/plain";   // change it to be correct.  
    let mimeData = [0x01, 0x02, 0x03, 0x04]; // change it to be correct.  
    let ndefRecord = tag.ndef.makeMimeRecord(mimeType, mimeData);  
    if (ndefRecord != undefined) {  
        console.log("ndefMessage makeMimeRecord rtdType: " + ndefRecord.rtdType);  
        console.log("ndefMessage makeMimeRecord payload: " + ndefRecord.payload);  
    } else {  
        console.log("ndefMessage makeMimeRecord ndefRecord: " + ndefRecord);  
    }  
} catch (busiError) {  
    console.error("ndefMessage makeMimeRecord catched busiError: " + busiError);  
}  
    
```    
  
    
## makeExternalRecord<sup>(9+)</sup>    
根据应用程序特定的外部数据，构建NDEF标签的Record。  
 **调用形式：**     
- makeExternalRecord(domainName: string, type: string, externalData: number[]): NdefRecord  
  
 **系统能力:**  SystemCapability.Communication.NFC.Tag    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| domainName | string | true | 外部数据发布组织的域名，一般是应用程序的包名。  |  
| type | string | true | 外部数据的指定类型。     |  
| externalData | number[] | true | 外部数据内容，每个number十六进制表示，范围是0x00~0xFF。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| NdefRecord | NDEF标签的Record，详见NDEF技术规范《NFCForum-TS-NDEF_1.0》。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
    
 **示例代码：**   
```js    
import tag from '@ohos.nfc.tag';  
  
try {  
    let domainName = "ohos.nfc.application"; // change it to be correct.  
    let type = "test"; // change it to be correct.  
    let externalData = [0x01, 0x02, 0x03, 0x04]; // change it to be correct.  
    let ndefRecord = tag.ndef.makeExternalRecord(domainName, type, externalData);  
    if (ndefRecord != undefined) {  
        console.log("ndefMessage makeExternalRecord rtdType: " + ndefRecord.rtdType);  
        console.log("ndefMessage makeExternalRecord payload: " + ndefRecord.payload);  
    } else {  
        console.log("ndefMessage makeExternalRecord ndefRecord: " + ndefRecord);  
    }  
} catch (busiError) {  
    console.error("ndefMessage makeExternalRecord catched busiError: " + busiError);  
}  
    
```    
  
    
## createNdefMessage<sup>(9+)</sup>    
使用原始字节数据创建NDEF标签的Message。该数据必须符合NDEF Record数据格式，如果不符合格式，则返回的NdeMessage数据对象，所包含的NDE Record列表会为空。  
 **调用形式：**     
- createNdefMessage(data: number[]): NdefMessage  
  
 **系统能力:**  SystemCapability.Communication.NFC.Tag    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| data | number[] | true | 原始字节，每个number十六进制表示，范围是0x00~0xFF。要求必须满足NDEF Record的格式。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| NdefMessage | NDEF标签的Message，详见NDEF技术规范《NFCForum-TS-NDEF_1.0》。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
    
 **示例代码：**   
```js    
import tag from '@ohos.nfc.tag';  
  
let rawData = [0xD1, 0x01, 0x03, 0x54, 0x4E, 0x46, 0x43];  // MUST can be parsed as NDEF Record.  
try {  
    let ndefMessage = tag.ndef.createNdefMessage(rawData);  
    console.log("ndef createNdefMessage, ndefMessage: " + ndefMessage);  
} catch (busiError) {  
    console.error("ndef createNdefMessage busiError: " + busiError);  
}  
    
```    
  
    
## createNdefMessage<sup>(9+)</sup>    
使用NDEF Records列表，创建NDEF Message。  
 **调用形式：**     
- createNdefMessage(ndefRecords: NdefRecord[]): NdefMessage  
  
 **系统能力:**  SystemCapability.Communication.NFC.Tag    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| ndefRecords | NdefRecord[] | true | NDEF标签的Record列表，详见NDEF技术规范《NFCForum-TS-NDEF_1.0》。<br/> |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| NdefMessage | NDEF标签的Message，详见NDEF技术规范《NFCForum-TS-NDEF_1.0》。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
    
 **示例代码：**   
```js    
import tag from '@ohos.nfc.tag';  
  
let uriRecord = tag.ndef.makeUriRecord("https://gitee.com/openharmony");  
let textRecord = tag.ndef.makeTextRecord("Hello World", "en");  
let ndefRecords = [uriRecord, textRecord];  
try {  
    let ndefMessage = tag.ndef.createNdefMessage(ndefRecords);  
    console.log("ndef createNdefMessage ndefMessage: " + ndefMessage);  
} catch (busiError) {  
    console.error("ndef createNdefMessage busiError: " + busiError);  
}  
    
```    
  
    
## messageToBytes<sup>(9+)</sup>    
把输入的NDEF消息数据对象，转换为字节格式的数据。  
 **调用形式：**     
- messageToBytes(ndefMessage: NdefMessage): number[]  
  
 **系统能力:**  SystemCapability.Communication.NFC.Tag    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| ndefMessage | NdefMessage | true | NDEF消息数据对象。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| number[] | NDEF消息数据对象，所转换成的字节格式的数据。每个number十六进制表示，范围是0x00~0xFF。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
    
 **示例代码：**   
```js    
import tag from '@ohos.nfc.tag';  
  
let rawData = [0xD1, 0x01, 0x03, 0x54, 0x4E, 0x46, 0x43]; // MUST can be parsed as NDEF Record.  
try {  
    let ndefMessage = tag.ndef.createNdefMessage(rawData);  
    console.log("ndef createNdefMessage, ndefMessage: " + ndefMessage);  
    let rawData2 = tag.ndef.messageToBytes(ndefMessage);  
    console.log("ndefMessage messageToBytes rawData2: " + rawData2);  
} catch (busiError) {  
    console.error("ndef createNdefMessage busiError: " + busiError);  
}  
    
```    
  
