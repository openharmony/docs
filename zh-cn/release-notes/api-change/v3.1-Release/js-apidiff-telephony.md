# 电话服务子系统JS API变更

OpenHarmony 3.1 Release版本相较于OpenHarmony 3.0 LTS版本，电话服务子系统的API变更如下:

## 接口变更

| 模块名 | 类名 | 方法/属性/枚举/常量 | 变更类型 |
|---|---|---|---|
| ohos.telephony.sms | sms | function hasSmsCapability(): boolean; | 新增 |
| ohos.telephony.sim | CardType | SINGLE_MODE_ISIM_CARD = 60 | 新增 |
| ohos.telephony.sim | CardType | DUAL_MODE_UG_CARD = 50 | 新增 |
| ohos.telephony.sim | CardType | DUAL_MODE_TELECOM_LTE_CARD = 43 | 新增 |
| ohos.telephony.sim | CardType | CU_DUAL_MODE_CARD = 42 | 新增 |
| ohos.telephony.sim | CardType | CT_NATIONAL_ROAMING_CARD = 41 | 新增 |
| ohos.telephony.sim | CardType | DUAL_MODE_CG_CARD = 40 | 新增 |
| ohos.telephony.sim | CardType | SINGLE_MODE_RUIM_CARD = 30 | 新增 |
| ohos.telephony.sim | CardType | SINGLE_MODE_USIM_CARD = 20 | 新增 |
| ohos.telephony.sim | CardType | SINGLE_MODE_SIM_CARD = 10 | 新增 |
| ohos.telephony.sim | CardType | UNKNOWN_CARD = -1 | 新增 |
| ohos.telephony.sim | sim | function hasSimCard(slotId: number, callback: AsyncCallback<boolean>): void;<br>function hasSimCard(slotId: number): Promise<boolean>; | 新增 |
| ohos.telephony.sim | sim | function getMaxSimCount(): number; | 新增 |
| ohos.telephony.sim | sim | function getCardType(slotId: number, callback: AsyncCallback<CardType>): void;<br>function getCardType(slotId: number): Promise<CardType>; | 新增 |
| ohos.telephony.sim | sim | function hasOperatorPrivileges(slotId: number, callback: AsyncCallback<boolean>): void;<br>function hasOperatorPrivileges(slotId: number): Promise<boolean>; | 新增 |
| ohos.telephony.sim | sim | function isSimActive(slotId: number, callback: AsyncCallback<boolean>): void;<br>function isSimActive(slotId: number): Promise<boolean>; | 新增 |
| ohos.telephony.radio | NetworkState | cfgTech: RadioTechnology; | 新增 |
| ohos.telephony.radio | radio | function getOperatorName(slotId: number, callback: AsyncCallback<string>): void;<br>function getOperatorName(slotId: number): Promise<string>; | 新增 |
| ohos.telephony.radio | radio | function isNrSupported(): boolean;<br>function isNrSupported(slotId: number): boolean; | 新增 |
| ohos.telephony.radio | radio | function getPrimarySlotId(callback: AsyncCallback<number>): void;<br>function getPrimarySlotId(): Promise<number>; | 新增 |
| ohos.telephony.observer | LockReason | SIM_SIM_PUK | 新增 |
| ohos.telephony.observer | LockReason | SIM_SIM_PIN | 新增 |
| ohos.telephony.observer | LockReason | SIM_PC_PUK | 新增 |
| ohos.telephony.observer | LockReason | SIM_PC_PIN | 新增 |
| ohos.telephony.observer | LockReason | SIM_PP_PUK | 新增 |
| ohos.telephony.observer | LockReason | SIM_PP_PIN | 新增 |
| ohos.telephony.observer | LockReason | SIM_PU_PUK | 新增 |
| ohos.telephony.observer | LockReason | SIM_PU_PIN | 新增 |
| ohos.telephony.observer | LockReason | SIM_PN_PUK | 新增 |
| ohos.telephony.observer | LockReason | SIM_PN_PIN | 新增 |
| ohos.telephony.observer | LockReason | SIM_PUK | 新增 |
| ohos.telephony.observer | LockReason | SIM_PIN | 新增 |
| ohos.telephony.observer | LockReason | SIM_NONE | 新增 |
| ohos.telephony.observer | SimStateData | reason: LockReason; | 新增 |
| ohos.telephony.observer | SimStateData | state: SimState; | 新增 |
| ohos.telephony.observer | SimStateData | type: CardType; | 新增 |
| ohos.telephony.observer | observer | function off(type: 'simStateChange', callback?: Callback<SimStateData>): void; | 新增 |
| ohos.telephony.observer | observer | function on(type: 'simStateChange', callback: Callback<SimStateData>): void;<br>function on(type: 'simStateChange', options: { slotId: number }, callback: Callback<SimStateData>): void; | 新增 |
| ohos.telephony.observer | observer | function off(type: 'cellularDataFlowChange', callback?: Callback<DataFlowType>): void; | 新增 |
| ohos.telephony.observer | observer | function on(type: 'cellularDataFlowChange', callback: Callback<DataFlowType>): void;<br>function on(type: 'cellularDataFlowChange', options: { slotId: number },callback: Callback<DataFlowType>): void;| 新增 |
| ohos.telephony.observer | observer | function off(type: 'cellularDataConnectionStateChange',callback?: Callback<{ state: DataConnectState, network: RatType }>): void;| 新增 |
| ohos.telephony.observer | observer | function on(type: 'cellularDataConnectionStateChange', callback: Callback<{ state: DataConnectState, network: RatType }>): void;<br>function on(type: 'cellularDataConnectionStateChange', options: { slotId: number }, callback: Callback<{ state: DataConnectState, network: RatType }>): void; | 新增 |
| ohos.telephony.data | DataConnectState | DATA_STATE_SUSPENDED = 3 | 新增 |
| ohos.telephony.data | DataConnectState | DATA_STATE_CONNECTED = 2 | 新增 |
| ohos.telephony.data | DataConnectState | DATA_STATE_CONNECTING = 1 | 新增 |
| ohos.telephony.data | DataConnectState | DATA_STATE_DISCONNECTED = 0 | 新增 |
| ohos.telephony.data | DataConnectState | DATA_STATE_UNKNOWN = -1 | 新增 |
| ohos.telephony.data | DataFlowType | DATA_FLOW_TYPE_DORMANT = 4 | 新增 |
| ohos.telephony.data | DataFlowType | DATA_FLOW_TYPE_UP_DOWN = 3 | 新增 |
| ohos.telephony.data | DataFlowType | DATA_FLOW_TYPE_UP = 2 | 新增 |
| ohos.telephony.data | DataFlowType | DATA_FLOW_TYPE_DOWN = 1 | 新增 |
| ohos.telephony.data | DataFlowType | DATA_FLOW_TYPE_NONE = 0 | 新增 |
| ohos.telephony.data | data | function isCellularDataRoamingEnabled(slotId: number, callback: AsyncCallback<boolean>): void;<br>function isCellularDataRoamingEnabled(slotId: number): Promise<boolean>; | 新增 |
| ohos.telephony.data | data | function isCellularDataEnabled(callback: AsyncCallback<boolean>): void;<br>function isCellularDataEnabled(): Promise<boolean>; | 新增 |
| ohos.telephony.data | data | function getCellularDataState(callback: AsyncCallback<DataConnectState>): void;<br>function getCellularDataState(): Promise<DataConnectState>; | 新增 |
| ohos.telephony.data | data | function getCellularDataFlowType(callback: AsyncCallback<DataFlowType>): void;<br>function getCellularDataFlowType(): Promise<DataFlowType>; | 新增 |
| ohos.telephony.data | data | function getDefaultCellularDataSlotId(callback: AsyncCallback<number>): void;<br>function getDefaultCellularDataSlotId(): Promise<number>; | 新增 |
| ohos.telephony.call | call | function hasVoiceCapability(): boolean; | 新增 |
| ohos.telephony.call | call | function makeCall(phoneNumber: string, callback: AsyncCallback<void>): void;<br>function makeCall(phoneNumber: string): Promise<void>; | 新增 |
| ohos.contact | Website | website: string | 新增 |
| ohos.contact | SipAddress | labelId: number | 新增 |
| ohos.contact | SipAddress | sipAddress: string | 新增 |
| ohos.contact | SipAddress | labelName: string | 新增 |
| ohos.contact | SipAddress | static readonly INVALID_LABEL_ID: -1 | 新增 |
| ohos.contact | SipAddress | static readonly SIP_OTHER: 3 | 新增 |
| ohos.contact | SipAddress | static readonly SIP_WORK: 2 | 新增 |
| ohos.contact | SipAddress | static readonly SIP_HOME: 1 | 新增 |
| ohos.contact | SipAddress | static readonly CUSTOM_LABEL: 0 | 新增 |
| ohos.contact | Relation | labelId: number | 新增 |
| ohos.contact | Relation | relationName: string | 新增 |
| ohos.contact | Relation | labelName: string | 新增 |
| ohos.contact | Relation | static readonly INVALID_LABEL_ID: -1 | 新增 |
| ohos.contact | Relation | static readonly RELATION_SPOUSE: 14 | 新增 |
| ohos.contact | Relation | static readonly RELATION_SISTER: 13 | 新增 |
| ohos.contact | Relation | static readonly RELATION_RELATIVE: 12 | 新增 |
| ohos.contact | Relation | static readonly RELATION_REFERRED_BY: 11 | 新增 |
| ohos.contact | Relation | static readonly RELATION_PARTNER: 10 | 新增 |
| ohos.contact | Relation | static readonly RELATION_PARENT: 9 | 新增 |
| ohos.contact | Relation | static readonly RELATION_MOTHER: 8 | 新增 |
| ohos.contact | Relation | static readonly RELATION_MANAGER: 7 | 新增 |
| ohos.contact | Relation | static readonly RELATION_FRIEND: 6 | 新增 |
| ohos.contact | Relation | static readonly RELATION_FATHER: 5 | 新增 |
| ohos.contact | Relation | static readonly RELATION_DOMESTIC_PARTNER: 4 | 新增 |
| ohos.contact | Relation | static readonly RELATION_CHILD: 3 | 新增 |
| ohos.contact | Relation | static readonly RELATION_BROTHER: 2 | 新增 |
| ohos.contact | Relation | static readonly RELATION_ASSISTANT: 1 | 新增 |
| ohos.contact | Relation | static readonly CUSTOM_LABEL: 0 | 新增 |
| ohos.contact | PostalAddress | labelId: number | 新增 |
| ohos.contact | PostalAddress | street: string | 新增 |
| ohos.contact | PostalAddress | region: string | 新增 |
| ohos.contact | PostalAddress | postcode: string | 新增 |
| ohos.contact | PostalAddress | postalAddress: string | 新增 |
| ohos.contact | PostalAddress | pobox: string | 新增 |
| ohos.contact | PostalAddress | neighborhood: string | 新增 |
| ohos.contact | PostalAddress | labelName: string | 新增 |
| ohos.contact | PostalAddress | country: string | 新增 |
| ohos.contact | PostalAddress | city: string | 新增 |
| ohos.contact | PostalAddress | static readonly INVALID_LABEL_ID: -1 | 新增 |
| ohos.contact | PostalAddress | static readonly ADDR_OTHER: 3 | 新增 |
| ohos.contact | PostalAddress | static readonly ADDR_WORK: 2 | 新增 |
| ohos.contact | PostalAddress | static readonly ADDR_HOME: 1 | 新增 |
| ohos.contact | PostalAddress | static readonly CUSTOM_LABEL: 0 | 新增 |
| ohos.contact | Portrait | uri: string | 新增 |
| ohos.contact | PhoneNumber | labelId: number | 新增 |
| ohos.contact | PhoneNumber | phoneNumber: string | 新增 |
| ohos.contact | PhoneNumber | labelName: string | 新增 |
| ohos.contact | PhoneNumber | static readonly INVALID_LABEL_ID: -1 | 新增 |
| ohos.contact | PhoneNumber | static readonly NUM_MMS: 20 | 新增 |
| ohos.contact | PhoneNumber | static readonly NUM_ASSISTANT: 19 | 新增 |
| ohos.contact | PhoneNumber | static readonly NUM_WORK_PAGER: 18 | 新增 |
| ohos.contact | PhoneNumber | static readonly NUM_WORK_MOBILE: 17 | 新增 |
| ohos.contact | PhoneNumber | static readonly NUM_TTY_TDD: 16 | 新增 |
| ohos.contact | PhoneNumber | static readonly NUM_TELEX: 15 | 新增 |
| ohos.contact | PhoneNumber | static readonly NUM_RADIO: 14 | 新增 |
| ohos.contact | PhoneNumber | static readonly NUM_OTHER_FAX: 13 | 新增 |
| ohos.contact | PhoneNumber | static readonly NUM_MAIN: 12 | 新增 |
| ohos.contact | PhoneNumber | static readonly NUM_ISDN: 11 | 新增 |
| ohos.contact | PhoneNumber | static readonly NUM_COMPANY_MAIN: 10 | 新增 |
| ohos.contact | PhoneNumber | static readonly NUM_CAR: 9 | 新增 |
| ohos.contact | PhoneNumber | static readonly NUM_CALLBACK: 8 | 新增 |
| ohos.contact | PhoneNumber | static readonly NUM_OTHER: 7 | 新增 |
| ohos.contact | PhoneNumber | static readonly NUM_PAGER: 6 | 新增 |
| ohos.contact | PhoneNumber | static readonly NUM_FAX_HOME: 5 | 新增 |
| ohos.contact | PhoneNumber | static readonly NUM_FAX_WORK: 4 | 新增 |
| ohos.contact | PhoneNumber | static readonly NUM_WORK: 3 | 新增 |
| ohos.contact | PhoneNumber | static readonly NUM_MOBILE: 2 | 新增 |
| ohos.contact | PhoneNumber | static readonly NUM_HOME: 1 | 新增 |
| ohos.contact | PhoneNumber | static readonly CUSTOM_LABEL: 0 | 新增 |
| ohos.contact | Organization | title: string | 新增 |
| ohos.contact | Organization | name: string | 新增 |
| ohos.contact | Note | noteContent: string | 新增 |
| ohos.contact | NickName | nickName: string | 新增 |
| ohos.contact | Name | nameSuffix: string | 新增 |
| ohos.contact | Name | namePrefix: string | 新增 |
| ohos.contact | Name | middleNamePhonetic: string | 新增 |
| ohos.contact | Name | middleName: string | 新增 |
| ohos.contact | Name | givenNamePhonetic: string | 新增 |
| ohos.contact | Name | givenName: string | 新增 |
| ohos.contact | Name | fullName: string | 新增 |
| ohos.contact | Name | familyNamePhonetic: string | 新增 |
| ohos.contact | Name | familyName: string | 新增 |
| ohos.contact | ImAddress | labelId: number | 新增 |
| ohos.contact | ImAddress | labelName: string | 新增 |
| ohos.contact | ImAddress | imAddress: string | 新增 |
| ohos.contact | ImAddress | static readonly INVALID_LABEL_ID: -2 | 新增 |
| ohos.contact | ImAddress | static readonly IM_JABBER: 7 | 新增 |
| ohos.contact | ImAddress | static readonly IM_ICQ: 6 | 新增 |
| ohos.contact | ImAddress | static readonly IM_QQ: 4 | 新增 |
| ohos.contact | ImAddress | static readonly IM_SKYPE: 3 | 新增 |
| ohos.contact | ImAddress | static readonly IM_YAHOO: 2 | 新增 |
| ohos.contact | ImAddress | static readonly IM_MSN: 1 | 新增 |
| ohos.contact | ImAddress | static readonly IM_AIM: 0 | 新增 |
| ohos.contact | ImAddress | static readonly CUSTOM_LABEL: -1 | 新增 |
| ohos.contact | Holder | holderId: number | 新增 |
| ohos.contact | Holder | readonly displayName: string | 新增 |
| ohos.contact | Holder | readonly bundleName: string | 新增 |
| ohos.contact | Group | title: string | 新增 |
| ohos.contact | Group | groupId: number | 新增 |
| ohos.contact | Event | labelId: number | 新增 |
| ohos.contact | Event | labelName: string | 新增 |
| ohos.contact | Event | eventDate: string | 新增 |
| ohos.contact | Event | static readonly INVALID_LABEL_ID: -1 | 新增 |
| ohos.contact | Event | static readonly EVENT_BIRTHDAY: 3 | 新增 |
| ohos.contact | Event | static readonly EVENT_OTHER: 2 | 新增 |
| ohos.contact | Event | static readonly EVENT_ANNIVERSARY: 1 | 新增 |
| ohos.contact | Event | static readonly CUSTOM_LABEL: 0 | 新增 |
| ohos.contact | Email | labelId: number | 新增 |
| ohos.contact | Email | displayName: string | 新增 |
| ohos.contact | Email | labelName: string | 新增 |
| ohos.contact | Email | email: string | 新增 |
| ohos.contact | Email | static readonly INVALID_LABEL_ID: -1 | 新增 |
| ohos.contact | Email | static readonly EMAIL_OTHER: 3 | 新增 |
| ohos.contact | Email | static readonly EMAIL_WORK: 2 | 新增 |
| ohos.contact | Email | static readonly EMAIL_HOME: 1 | 新增 |
| ohos.contact | Email | static readonly CUSTOM_LABEL: 0 | 新增 |
| ohos.contact | Attribute | ATTR_WEBSITE | 新增 |
| ohos.contact | Attribute | ATTR_SIP_ADDRESS | 新增 |
| ohos.contact | Attribute | ATTR_RELATION | 新增 |
| ohos.contact | Attribute | ATTR_POSTAL_ADDRESS | 新增 |
| ohos.contact | Attribute | ATTR_PORTRAIT | 新增 |
| ohos.contact | Attribute | ATTR_PHONE | 新增 |
| ohos.contact | Attribute | ATTR_ORGANIZATION | 新增 |
| ohos.contact | Attribute | ATTR_NOTE | 新增 |
| ohos.contact | Attribute | ATTR_NICKNAME | 新增 |
| ohos.contact | Attribute | ATTR_NAME | 新增 |
| ohos.contact | Attribute | ATTR_IM | 新增 |
| ohos.contact | Attribute | ATTR_GROUP_MEMBERSHIP | 新增 |
| ohos.contact | Attribute | ATTR_EMAIL | 新增 |
| ohos.contact | Attribute | ATTR_CONTACT_EVENT | 新增 |
| ohos.contact | ContactAttributes | attributes: Attribute[] | 新增 |
| ohos.contact | Contact | organization: Organization | 新增 |
| ohos.contact | Contact | note: Note | 新增 |
| ohos.contact | Contact | nickName: NickName | 新增 |
| ohos.contact | Contact | name: Name | 新增 |
| ohos.contact | Contact | websites: Website[] | 新增 |
| ohos.contact | Contact | sipAddresses: SipAddress[] | 新增 |
| ohos.contact | Contact | relations: Relation[] | 新增 |
| ohos.contact | Contact | postalAddresses: PostalAddress[] | 新增 |
| ohos.contact | Contact | portrait: Portrait | 新增 |
| ohos.contact | Contact | phoneNumbers: PhoneNumber[] | 新增 |
| ohos.contact | Contact | imAddresses: ImAddress[] | 新增 |
| ohos.contact | Contact | groups: Group[] | 新增 |
| ohos.contact | Contact | events: Event[] | 新增 |
| ohos.contact | Contact | emails: Email[] | 新增 |
| ohos.contact | Contact | contactAttributes: ContactAttributes | 新增 |
| ohos.contact | Contact | readonly key: string | 新增 |
| ohos.contact | Contact | readonly id: number | 新增 |
| ohos.contact | Contact | static readonly INVALID_CONTACT_ID: -1 | 新增 |
| ohos.contact | contact | function isMyCard(id: number, callback: AsyncCallback<boolean>): void;<br>function isMyCard(id: number): Promise<boolean>; | 新增 |
| ohos.contact | contact | function isLocalContact(id: number, callback: AsyncCallback<boolean>): void;<br>function isLocalContact(id: number): Promise<boolean>; | 新增 |
| ohos.contact | contact | function updateContact(contact: Contact, callback: AsyncCallback<void>): void;<br>function updateContact(contact: Contact, attrs: ContactAttributes, callback: AsyncCallback<void>): void;<br>function updateContact(contact: Contact, attrs?: ContactAttributes): Promise<void>; | 新增 |
| ohos.contact | contact | function queryMyCard(callback: AsyncCallback<Contact>): void;<br>function queryMyCard(attrs: ContactAttributes, callback: AsyncCallback<Contact>): void;<br>function queryMyCard(attrs?: ContactAttributes): Promise<Contact>; | 新增 |
| ohos.contact | contact | function queryKey(id: number, callback: AsyncCallback<string>): void;<br>function queryKey(id: number, holder: Holder, callback: AsyncCallback<string>): void;<br>function queryKey(id: number, holder?: Holder): Promise<string>; | 新增 |
| ohos.contact | contact | function queryHolders(callback: AsyncCallback<Array<Holder>>): void;<br>function queryHolders(): Promise<Array<Holder>>; | 新增 |
| ohos.contact | contact | function queryGroups(callback: AsyncCallback<Array<Group>>): void;<br>function queryGroups(holder: Holder, callback: AsyncCallback<Array<Group>>): void;<br>function queryGroups(holder?: Holder): Promise<Array<Group>>; | 新增 |
| ohos.contact | contact | function queryContactsByPhoneNumber(phoneNumber: string, callback: AsyncCallback<Array<Contact>>): void;<br>function queryContactsByPhoneNumber(phoneNumber: string, holder: Holder, callback: AsyncCallback<Array<Contact>>): void;<br>function queryContactsByPhoneNumber(phoneNumber: string, attrs: ContactAttributes, callback: AsyncCallback<Array<Contact>>): void;<br>function queryContactsByPhoneNumber(phoneNumber: string, holder: Holder, attrs: ContactAttributes, callback: AsyncCallback<Array<Contact>>): void;<br>function queryContactsByPhoneNumber(phoneNumber: string, holder?: Holder, attrs?: ContactAttributes): Promise<Array<Contact>>; | 新增 |
| ohos.contact | contact | function queryContactsByEmail(email: string, callback: AsyncCallback<Array<Contact>>): void;<br>function queryContactsByEmail(email: string, holder: Holder, callback: AsyncCallback<Array<Contact>>): void;<br>function queryContactsByEmail(email: string, attrs: ContactAttributes, callback: AsyncCallback<Array<Contact>>): void;<br>function queryContactsByEmail(email: string, holder: Holder, attrs: ContactAttributes, callback: AsyncCallback<Array<Contact>>): void;<br>function queryContactsByEmail(email: string, holder?: Holder, attrs?: ContactAttributes): Promise<Array<Contact>>; | 新增 |
| ohos.contact | contact | function queryContacts(callback: AsyncCallback<Array<Contact>>): void;<br>function queryContacts(holder: Holder, callback: AsyncCallback<Array<Contact>>): void;<br>function queryContacts(attrs: ContactAttributes, callback: AsyncCallback<Array<Contact>>): void;<br>function queryContacts(holder: Holder, attrs: ContactAttributes, callback: AsyncCallback<Array<Contact>>): void;<br>function queryContacts(holder?: Holder, attrs?: ContactAttributes): Promise<Array<Contact>>; | 新增 |
| ohos.contact | contact | function queryContact(key: string, callback: AsyncCallback<Contact>): void;<br>function queryContact(key: string, holder: Holder, callback: AsyncCallback<Contact>): void;<br>function queryContact(key: string, attrs: ContactAttributes, callback: AsyncCallback<Contact>): void;<br>function queryContact(key: string, holder: Holder, attrs: ContactAttributes, callback: AsyncCallback<Contact>): void;<br>function queryContact(key: string, holder?: Holder, attrs?: ContactAttributes): Promise<Contact>; | 新增 |
| ohos.contact | contact | function deleteContact(key: string, callback: AsyncCallback<void>): void;<br>function deleteContact(key: string): Promise<void>; | 新增 |
| ohos.contact | contact | function selectContact(callback: AsyncCallback<Array<Contact>>): void;<br>function selectContact(): Promise<Array<Contact>>; | 新增 |
| ohos.contact | contact | function addContact(contact: Contact, callback: AsyncCallback<number>): void;<br>function addContact(contact: Contact): Promise<number>; | 新增 |
