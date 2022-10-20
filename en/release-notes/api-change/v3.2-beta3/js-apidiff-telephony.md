# JS API Changes of the Telephony Subsystem

The table below lists the APIs changes of the telephony subsystem in OpenHarmony 3.2 Beta3 over OpenHarmony 3.2 Beta2.

## API Changes

| Module| Class| Method/Attribute/Enumeration/Constant| Change Type|
|---|---|---|---|
| ohos.telephony.data  | data           | getDefaultCellularDataSlotIdSync(): number;                                                                                                                                                 | Added|
| ohos.telephony.radio | ImsServiceType | TYPE_SMS                                                                                                                                                                                             | Added|
| ohos.telephony.radio | ImsServiceType | TYPE_UT                                                                                                                                                                                              | Added|
| ohos.telephony.radio | ImsServiceType | TYPE_VIDEO                                                                                                                                                                                           | Added|
| ohos.telephony.radio | ImsServiceType | TYPE_VOICE                                                                                                                                                                                           | Added|
| ohos.telephony.radio | ImsRegInfo     | imsRegTech: ImsRegTech;                                                                                                                                                                              | Added|
| ohos.telephony.radio | ImsRegInfo     | imsRegState: ImsRegState;                                                                                                                                                                            | Added|
| ohos.telephony.radio | ImsRegTech     | REGISTRATION_TECH_NR                                                                                                                                                                                 | Added|
| ohos.telephony.radio | ImsRegTech     | REGISTRATION_TECH_IWLAN                                                                                                                                                                              | Added|
| ohos.telephony.radio | ImsRegTech     | REGISTRATION_TECH_LTE                                                                                                                                                                                | Added|
| ohos.telephony.radio | ImsRegTech     | REGISTRATION_TECH_NONE                                                                                                                                                                               | Added|
| ohos.telephony.radio | ImsRegState    | IMS_REGISTERED                                                                                                                                                                                       | Added|
| ohos.telephony.radio | ImsRegState    | IMS_UNREGISTERED                                                                                                                                                                                     | Added|
| ohos.telephony.radio | radio          | off(type: 'imsRegStateChange', slotId: number, imsType: ImsServiceType, callback?: Callback\<ImsRegInfo>): void;                                                                           | Added|
| ohos.telephony.radio | radio          | on(type: 'imsRegStateChange', slotId: number, imsType: ImsServiceType, callback: Callback\<ImsRegInfo>): void;                                                                              | Added|
| ohos.telephony.radio | radio          | getImsRegInfo(slotId: number, imsType: ImsServiceType, callback: AsyncCallback\<ImsRegInfo>): void;<br>getImsRegInfo(slotId: number, imsType: ImsServiceType): Promise\<ImsRegInfo>; | Added|
| ohos.telephony.sim   | sim            | getOpName(slotId: number, callback: AsyncCallback\<string>): void;<br>getOpName(slotId: number): Promise\<string>;                                                                 | Added|
| ohos.telephony.sim   | sim            | getOpKey(slotId: number, callback: AsyncCallback\<string>): void;<br>getOpKey(slotId: number): Promise\<string>;                                                                   | Added|
