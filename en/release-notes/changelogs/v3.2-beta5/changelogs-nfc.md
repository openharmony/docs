# Changelog of NFC JS APIs in the Communication Subsystem

## cl.nfc.1 API Change
Deprecated some NFC JS APIs in API versions 6 to 8 because the APIs cannot throw error codes, and added new APIs in API version 9 instead.

You need to adapt your application based on the following information.

 **Change Impact**

The deprecated JS APIs in API versions 6 to 8 are affected. Your application needs to adapt new APIs so that it can properly implement functions in the SDK environment of the new version.

**Key API/Component Changes**

| Module                   | Class               | Method/Attribute/Enumeration/Constant                                         | Change Type|
| ------------------------- | ------------------- | ------------------------------------------------------------ | -------- |
| api/@ohos.nfc.cardEmulation.d.ts        | cardEmulation         | FeatureType  | Deprecated    |
| api/@ohos.nfc.cardEmulation.d.ts        | cardEmulation         | isSupported  | Deprecated    |
| api/@ohos.nfc.cardEmulation.d.ts        | cardEmulation         | hasHceCapability  | Added    |
| api/@ohos.nfc.controller.d.ts        | nfcController         | isNfcAvailable  | Deprecated    |
| api/@ohos.nfc.controller.d.ts        | nfcController         | openNfc  | Deprecated    |
| api/@ohos.nfc.controller.d.ts        | nfcController         | closeNfc  | Deprecated    |
| api/@ohos.nfc.controller.d.ts        | nfcController         | enableNfc  | Added    |
| api/@ohos.nfc.controller.d.ts        | nfcController         | disableNfc  | Added    |
| api/@ohos.nfc.tag.d.ts        | tag         | getNfcATag  | Deprecated    |
| api/@ohos.nfc.tag.d.ts        | tag         | getNfcBTag  | Deprecated    |
| api/@ohos.nfc.tag.d.ts        | tag         | getNfcFTag  | Deprecated    |
| api/@ohos.nfc.tag.d.ts        | tag         | getNfcVTag  | Deprecated    |
| api/@ohos.nfc.tag.d.ts        | tag         | getNfcA  | Added    |
| api/@ohos.nfc.tag.d.ts        | tag         | getNfcB  | Added    |
| api/@ohos.nfc.tag.d.ts        | tag         | getNfcF  | Added    |
| api/@ohos.nfc.tag.d.ts        | tag         | getNfcV  | Added    |
| api/tag/tagSession.d.ts        | TagSession          | getTagInfo  | Deprecated    |
| api/tag/tagSession.d.ts        | TagSession          | connectTag  | Deprecated    |
| api/tag/tagSession.d.ts        | TagSession          | reset  | Deprecated    |
| api/tag/tagSession.d.ts        | TagSession          | isTagConnected  | Deprecated    |
| api/tag/tagSession.d.ts        | TagSession          | setSendDataTimeout  | Deprecated    |
| api/tag/tagSession.d.ts        | TagSession          | getSendDataTimeout  | Deprecated    |
| api/tag/tagSession.d.ts        | TagSession          | sendData  | Deprecated    |
| api/tag/tagSession.d.ts        | TagSession          | getMaxSendLength  | Deprecated    |
| api/tag/tagSession.d.ts        | TagSession          | connect  | Added    |
| api/tag/tagSession.d.ts        | TagSession          | resetConnection  | Added    |
| api/tag/tagSession.d.ts        | TagSession          | isConnected  | Added    |
| api/tag/tagSession.d.ts        | TagSession          | setTimeout  | Added    |
| api/tag/tagSession.d.ts        | TagSession          | getTimeout  | Added    |
| api/tag/tagSession.d.ts        | TagSession          | transmit  | Added    |
| api/tag/tagSession.d.ts        | TagSession          | getMaxTransmitSize  | Added    |

**Adaptation Guide**

See the following:
[@ohos.nfc.cardEmulation (Standard NFC Card Emulation)](../../../application-dev/reference/apis/js-apis-cardEmulation.md)

[@ohos.nfc.controller (Standard NFC)](../../../application-dev/reference/apis/js-apis-nfcController.md)

[@ohos.nfc.tag (Standard NFC Tags)](../../../application-dev/reference/apis/js-apis-nfcTag.md)

[tagSession (Standard NFC Tag Session)](../../../application-dev/reference/apis/js-apis-tagSession.md)
```
