# 电话服务子系统JS API变更

OpenHarmony 3.2 Beta3版本相较于OpenHarmony 3.2 Beta2版本，电话服务子系统的API变更如下:

## 接口变更

| 模块名 | 类名 | 方法/属性/枚举/常量 | 变更类型 |
|---|---|---|---|
| ohos.telephony.data  | data           | getDefaultCellularDataSlotIdSync(): number;                                                                                                                                                 | 新增 |
| ohos.telephony.radio | ImsServiceType | TYPE_SMS                                                                                                                                                                                             | 新增 |
| ohos.telephony.radio | ImsServiceType | TYPE_UT                                                                                                                                                                                              | 新增 |
| ohos.telephony.radio | ImsServiceType | TYPE_VIDEO                                                                                                                                                                                           | 新增 |
| ohos.telephony.radio | ImsServiceType | TYPE_VOICE                                                                                                                                                                                           | 新增 |
| ohos.telephony.radio | ImsRegInfo     | imsRegTech: ImsRegTech;                                                                                                                                                                              | 新增 |
| ohos.telephony.radio | ImsRegInfo     | imsRegState: ImsRegState;                                                                                                                                                                            | 新增 |
| ohos.telephony.radio | ImsRegTech     | REGISTRATION_TECH_NR                                                                                                                                                                                 | 新增 |
| ohos.telephony.radio | ImsRegTech     | REGISTRATION_TECH_IWLAN                                                                                                                                                                              | 新增 |
| ohos.telephony.radio | ImsRegTech     | REGISTRATION_TECH_LTE                                                                                                                                                                                | 新增 |
| ohos.telephony.radio | ImsRegTech     | REGISTRATION_TECH_NONE                                                                                                                                                                               | 新增 |
| ohos.telephony.radio | ImsRegState    | IMS_REGISTERED                                                                                                                                                                                       | 新增 |
| ohos.telephony.radio | ImsRegState    | IMS_UNREGISTERED                                                                                                                                                                                     | 新增 |
| ohos.telephony.radio | radio          | off(type: 'imsRegStateChange', slotId: number, imsType: ImsServiceType, callback?: Callback\<ImsRegInfo>): void;                                                                           | 新增 |
| ohos.telephony.radio | radio          | on(type: 'imsRegStateChange', slotId: number, imsType: ImsServiceType, callback: Callback\<ImsRegInfo>): void;                                                                              | 新增 |
| ohos.telephony.radio | radio          | getImsRegInfo(slotId: number, imsType: ImsServiceType, callback: AsyncCallback\<ImsRegInfo>): void;<br>getImsRegInfo(slotId: number, imsType: ImsServiceType): Promise\<ImsRegInfo>; | 新增 |
| ohos.telephony.sim   | sim            | getOpName(slotId: number, callback: AsyncCallback\<string>): void;<br>getOpName(slotId: number): Promise\<string>;                                                                 | 新增 |
| ohos.telephony.sim   | sim            | getOpKey(slotId: number, callback: AsyncCallback\<string>): void;<br>getOpKey(slotId: number): Promise\<string>;                                                                   | 新增 |