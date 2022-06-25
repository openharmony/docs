# JS API Changes of the Telephony Subsystem

The table below lists the APIs changes of the Telephony subsystem in OpenHarmony 3.1 Release over OpenHarmony 3.0 LTS.

## API Changes

| Module| Class| Method/Attribute/Enumeration/Constant| Change Type|
|---|---|---|---|
| ohos.telephony.sms | sms | hasSmsCapability(): boolean; | Added|
| ohos.telephony.sim | CardType | SINGLE_MODE_ISIM_CARD = 60 | Added|
| ohos.telephony.sim | CardType | DUAL_MODE_UG_CARD = 50 | Added|
| ohos.telephony.sim | CardType | DUAL_MODE_TELECOM_LTE_CARD = 43 | Added|
| ohos.telephony.sim | CardType | CU_DUAL_MODE_CARD = 42 | Added|
| ohos.telephony.sim | CardType | CT_NATIONAL_ROAMING_CARD = 41 | Added|
| ohos.telephony.sim | CardType | DUAL_MODE_CG_CARD = 40 | Added|
| ohos.telephony.sim | CardType | SINGLE_MODE_RUIM_CARD = 30 | Added|
| ohos.telephony.sim | CardType | SINGLE_MODE_USIM_CARD = 20 | Added|
| ohos.telephony.sim | CardType | SINGLE_MODE_SIM_CARD = 10 | Added|
| ohos.telephony.sim | CardType | UNKNOWN_CARD = -1 | Added|
| ohos.telephony.sim | sim | hasSimCard(slotId: number, callback: AsyncCallback\<boolean>): void;<br>hasSimCard(slotId: number): Promise\<boolean>; | Added|
| ohos.telephony.sim | sim | getMaxSimCount(): number; | Added|
| ohos.telephony.sim | sim | getCardType(slotId: number, callback: AsyncCallback\<CardType>): void;<br>getCardType(slotId: number): Promise\<CardType>; | Added|
| ohos.telephony.sim | sim | hasOperatorPrivileges(slotId: number, callback: AsyncCallback\<boolean>): void;<br>hasOperatorPrivileges(slotId: number): Promise\<boolean>; | Added|
| ohos.telephony.sim | sim | isSimActive(slotId: number, callback: AsyncCallback\<boolean>): void;<br>isSimActive(slotId: number): Promise\<boolean>; | Added|
| ohos.telephony.radio | NetworkState | cfgTech: RadioTechnology; | Added|
| ohos.telephony.radio | radio | getOperatorName(slotId: number, callback: AsyncCallback\<string>): void;<br>getOperatorName(slotId: number): Promise\<string>; | Added|
| ohos.telephony.radio | radio | isNrSupported(): boolean;<br>isNrSupported(slotId: number): boolean; | Added|
| ohos.telephony.radio | radio | getPrimarySlotId(callback: AsyncCallback\<number>): void;<br>getPrimarySlotId(): Promise\<number>; | Added|
| ohos.telephony.observer | LockReason | SIM_SIM_PUK | Added|
| ohos.telephony.observer | LockReason | SIM_SIM_PIN | Added|
| ohos.telephony.observer | LockReason | SIM_PC_PUK | Added|
| ohos.telephony.observer | LockReason | SIM_PC_PIN | Added|
| ohos.telephony.observer | LockReason | SIM_PP_PUK | Added|
| ohos.telephony.observer | LockReason | SIM_PP_PIN | Added|
| ohos.telephony.observer | LockReason | SIM_PU_PUK | Added|
| ohos.telephony.observer | LockReason | SIM_PU_PIN | Added|
| ohos.telephony.observer | LockReason | SIM_PN_PUK | Added|
| ohos.telephony.observer | LockReason | SIM_PN_PIN | Added|
| ohos.telephony.observer | LockReason | SIM_PUK | Added|
| ohos.telephony.observer | LockReason | SIM_PIN | Added|
| ohos.telephony.observer | LockReason | SIM_NONE | Added|
| ohos.telephony.observer | SimStateData | reason: LockReason; | Added|
| ohos.telephony.observer | SimStateData | state: SimState; | Added|
| ohos.telephony.observer | SimStateData | type: CardType; | Added|
| ohos.telephony.observer | observer | off(type: 'simStateChange', callback?: Callback\<SimStateData>): void; | Added|
| ohos.telephony.observer | observer | on(type: 'simStateChange', callback: Callback\<SimStateData>): void;<br>on(type: 'simStateChange', options: { slotId: number }, callback: Callback\<SimStateData>): void; | Added|
| ohos.telephony.observer | observer | off(type: 'cellularDataFlowChange', callback?: Callback\<DataFlowType>): void; | Added|
| ohos.telephony.observer | observer | on(type: 'cellularDataFlowChange', callback: Callback\<DataFlowType>): void;<br>on(type: 'cellularDataFlowChange', options: { slotId: number },callback: Callback\<DataFlowType>): void; | Added|
| ohos.telephony.observer | observer | off(type: 'cellularDataConnectionStateChange',callback?: Callback\<{ state: DataConnectState, network: RatType }>): void; | Added|
| ohos.telephony.observer | observer | on(type: 'cellularDataConnectionStateChange', callback: Callback\<{ state: DataConnectState, network: RatType }>): void;<br>on(type: 'cellularDataConnectionStateChange', options: { slotId: number }, callback: Callback\<{ state: DataConnectState, network: RatType }>): void; | Added|
| ohos.telephony.data | DataConnectState | DATA_STATE_SUSPENDED = 3 | Added|
| ohos.telephony.data | DataConnectState | DATA_STATE_CONNECTED = 2 | Added|
| ohos.telephony.data | DataConnectState | DATA_STATE_CONNECTING = 1 | Added|
| ohos.telephony.data | DataConnectState | DATA_STATE_DISCONNECTED = 0 | Added|
| ohos.telephony.data | DataConnectState | DATA_STATE_UNKNOWN = -1 | Added|
| ohos.telephony.data | DataFlowType | DATA_FLOW_TYPE_DORMANT = 4 | Added|
| ohos.telephony.data | DataFlowType | DATA_FLOW_TYPE_UP_DOWN = 3 | Added|
| ohos.telephony.data | DataFlowType | DATA_FLOW_TYPE_UP = 2 | Added|
| ohos.telephony.data | DataFlowType | DATA_FLOW_TYPE_DOWN = 1 | Added|
| ohos.telephony.data | DataFlowType | DATA_FLOW_TYPE_NONE = 0 | Added|
| ohos.telephony.data | data | isCellularDataRoamingEnabled(slotId: number, callback: AsyncCallback\<boolean>): void;<br>isCellularDataRoamingEnabled(slotId: number): Promise\<boolean>; | Added|
| ohos.telephony.data | data | isCellularDataEnabled(callback: AsyncCallback\<boolean>): void;<br>isCellularDataEnabled(): Promise\<boolean>; | Added|
| ohos.telephony.data | data | getCellularDataState(callback: AsyncCallback\<DataConnectState>): void;<br>getCellularDataState(): Promise\<DataConnectState>; | Added|
| ohos.telephony.data | data | getCellularDataFlowType(callback: AsyncCallback\<DataFlowType>): void;<br>getCellularDataFlowType(): Promise\<DataFlowType>; | Added|
| ohos.telephony.data | data | getDefaultCellularDataSlotId(callback: AsyncCallback\<number>): void;<br>getDefaultCellularDataSlotId(): Promise\<number>; | Added|
| ohos.telephony.call | call | hasVoiceCapability(): boolean; | Added|
| ohos.telephony.call | call | makeCall(phoneNumber: string, callback: AsyncCallback\<void>): void;<br>makeCall(phoneNumber: string): Promise\<void>; | Added|
| ohos.contact | Website | website: string | Added|
| ohos.contact | SipAddress | labelId: number | Added|
| ohos.contact | SipAddress | sipAddress: string | Added|
| ohos.contact | SipAddress | labelName: string | Added|
| ohos.contact | SipAddress | static readonly INVALID_LABEL_ID: -1 | Added|
| ohos.contact | SipAddress | static readonly SIP_OTHER: 3 | Added|
| ohos.contact | SipAddress | static readonly SIP_WORK: 2 | Added|
| ohos.contact | SipAddress | static readonly SIP_HOME: 1 | Added|
| ohos.contact | SipAddress | static readonly CUSTOM_LABEL: 0 | Added|
| ohos.contact | Relation | labelId: number | Added|
| ohos.contact | Relation | relationName: string | Added|
| ohos.contact | Relation | labelName: string | Added|
| ohos.contact | Relation | static readonly INVALID_LABEL_ID: -1 | Added|
| ohos.contact | Relation | static readonly RELATION_SPOUSE: 14 | Added|
| ohos.contact | Relation | static readonly RELATION_SISTER: 13 | Added|
| ohos.contact | Relation | static readonly RELATION_RELATIVE: 12 | Added|
| ohos.contact | Relation | static readonly RELATION_REFERRED_BY: 11 | Added|
| ohos.contact | Relation | static readonly RELATION_PARTNER: 10 | Added|
| ohos.contact | Relation | static readonly RELATION_PARENT: 9 | Added|
| ohos.contact | Relation | static readonly RELATION_MOTHER: 8 | Added|
| ohos.contact | Relation | static readonly RELATION_MANAGER: 7 | Added|
| ohos.contact | Relation | static readonly RELATION_FRIEND: 6 | Added|
| ohos.contact | Relation | static readonly RELATION_FATHER: 5 | Added|
| ohos.contact | Relation | static readonly RELATION_DOMESTIC_PARTNER: 4 | Added|
| ohos.contact | Relation | static readonly RELATION_CHILD: 3 | Added|
| ohos.contact | Relation | static readonly RELATION_BROTHER: 2 | Added|
| ohos.contact | Relation | static readonly RELATION_ASSISTANT: 1 | Added|
| ohos.contact | Relation | static readonly CUSTOM_LABEL: 0 | Added|
| ohos.contact | PostalAddress | labelId: number | Added|
| ohos.contact | PostalAddress | street: string | Added|
| ohos.contact | PostalAddress | region: string | Added|
| ohos.contact | PostalAddress | postcode: string | Added|
| ohos.contact | PostalAddress | postalAddress: string | Added|
| ohos.contact | PostalAddress | pobox: string | Added|
| ohos.contact | PostalAddress | neighborhood: string | Added|
| ohos.contact | PostalAddress | labelName: string | Added|
| ohos.contact | PostalAddress | country: string | Added|
| ohos.contact | PostalAddress | city: string | Added|
| ohos.contact | PostalAddress | static readonly INVALID_LABEL_ID: -1 | Added|
| ohos.contact | PostalAddress | static readonly ADDR_OTHER: 3 | Added|
| ohos.contact | PostalAddress | static readonly ADDR_WORK: 2 | Added|
| ohos.contact | PostalAddress | static readonly ADDR_HOME: 1 | Added|
| ohos.contact | PostalAddress | static readonly CUSTOM_LABEL: 0 | Added|
| ohos.contact | Portrait | uri: string | Added|
| ohos.contact | PhoneNumber | labelId: number | Added|
| ohos.contact | PhoneNumber | phoneNumber: string | Added|
| ohos.contact | PhoneNumber | labelName: string | Added|
| ohos.contact | PhoneNumber | static readonly INVALID_LABEL_ID: -1 | Added|
| ohos.contact | PhoneNumber | static readonly NUM_MMS: 20 | Added|
| ohos.contact | PhoneNumber | static readonly NUM_ASSISTANT: 19 | Added|
| ohos.contact | PhoneNumber | static readonly NUM_WORK_PAGER: 18 | Added|
| ohos.contact | PhoneNumber | static readonly NUM_WORK_MOBILE: 17 | Added|
| ohos.contact | PhoneNumber | static readonly NUM_TTY_TDD: 16 | Added|
| ohos.contact | PhoneNumber | static readonly NUM_TELEX: 15 | Added|
| ohos.contact | PhoneNumber | static readonly NUM_RADIO: 14 | Added|
| ohos.contact | PhoneNumber | static readonly NUM_OTHER_FAX: 13 | Added|
| ohos.contact | PhoneNumber | static readonly NUM_MAIN: 12 | Added|
| ohos.contact | PhoneNumber | static readonly NUM_ISDN: 11 | Added|
| ohos.contact | PhoneNumber | static readonly NUM_COMPANY_MAIN: 10 | Added|
| ohos.contact | PhoneNumber | static readonly NUM_CAR: 9 | Added|
| ohos.contact | PhoneNumber | static readonly NUM_CALLBACK: 8 | Added|
| ohos.contact | PhoneNumber | static readonly NUM_OTHER: 7 | Added|
| ohos.contact | PhoneNumber | static readonly NUM_PAGER: 6 | Added|
| ohos.contact | PhoneNumber | static readonly NUM_FAX_HOME: 5 | Added|
| ohos.contact | PhoneNumber | static readonly NUM_FAX_WORK: 4 | Added|
| ohos.contact | PhoneNumber | static readonly NUM_WORK: 3 | Added|
| ohos.contact | PhoneNumber | static readonly NUM_MOBILE: 2 | Added|
| ohos.contact | PhoneNumber | static readonly NUM_HOME: 1 | Added|
| ohos.contact | PhoneNumber | static readonly CUSTOM_LABEL: 0 | Added|
| ohos.contact | Organization | title: string | Added|
| ohos.contact | Organization | name: string | Added|
| ohos.contact | Note | noteContent: string | Added|
| ohos.contact | NickName | nickName: string | Added|
| ohos.contact | Name | nameSuffix: string | Added|
| ohos.contact | Name | namePrefix: string | Added|
| ohos.contact | Name | middleNamePhonetic: string | Added|
| ohos.contact | Name | middleName: string | Added|
| ohos.contact | Name | givenNamePhonetic: string | Added|
| ohos.contact | Name | givenName: string | Added|
| ohos.contact | Name | fullName: string | Added|
| ohos.contact | Name | familyNamePhonetic: string | Added|
| ohos.contact | Name | familyName: string | Added|
| ohos.contact | ImAddress | labelId: number | Added|
| ohos.contact | ImAddress | labelName: string | Added|
| ohos.contact | ImAddress | imAddress: string | Added|
| ohos.contact | ImAddress | static readonly INVALID_LABEL_ID: -2 | Added|
| ohos.contact | ImAddress | static readonly IM_JABBER: 7 | Added|
| ohos.contact | ImAddress | static readonly IM_ICQ: 6 | Added|
| ohos.contact | ImAddress | static readonly IM_QQ: 4 | Added|
| ohos.contact | ImAddress | static readonly IM_SKYPE: 3 | Added|
| ohos.contact | ImAddress | static readonly IM_YAHOO: 2 | Added|
| ohos.contact | ImAddress | static readonly IM_MSN: 1 | Added|
| ohos.contact | ImAddress | static readonly IM_AIM: 0 | Added|
| ohos.contact | ImAddress | static readonly CUSTOM_LABEL: -1 | Added|
| ohos.contact | Holder | holderId: number | Added|
| ohos.contact | Holder | readonly displayName: string | Added|
| ohos.contact | Holder | readonly bundleName: string | Added|
| ohos.contact | Group | title: string | Added|
| ohos.contact | Group | groupId: number | Added|
| ohos.contact | Event | labelId: number | Added|
| ohos.contact | Event | labelName: string | Added|
| ohos.contact | Event | eventDate: string | Added|
| ohos.contact | Event | static readonly INVALID_LABEL_ID: -1 | Added|
| ohos.contact | Event | static readonly EVENT_BIRTHDAY: 3 | Added|
| ohos.contact | Event | static readonly EVENT_OTHER: 2 | Added|
| ohos.contact | Event | static readonly EVENT_ANNIVERSARY: 1 | Added|
| ohos.contact | Event | static readonly CUSTOM_LABEL: 0 | Added|
| ohos.contact | Email | labelId: number | Added|
| ohos.contact | Email | displayName: string | Added|
| ohos.contact | Email | labelName: string | Added|
| ohos.contact | Email | email: string | Added|
| ohos.contact | Email | static readonly INVALID_LABEL_ID: -1 | Added|
| ohos.contact | Email | static readonly EMAIL_OTHER: 3 | Added|
| ohos.contact | Email | static readonly EMAIL_WORK: 2 | Added|
| ohos.contact | Email | static readonly EMAIL_HOME: 1 | Added|
| ohos.contact | Email | static readonly CUSTOM_LABEL: 0 | Added|
| ohos.contact | Attribute | ATTR_WEBSITE | Added|
| ohos.contact | Attribute | ATTR_SIP_ADDRESS | Added|
| ohos.contact | Attribute | ATTR_RELATION | Added|
| ohos.contact | Attribute | ATTR_POSTAL_ADDRESS | Added|
| ohos.contact | Attribute | ATTR_PORTRAIT | Added|
| ohos.contact | Attribute | ATTR_PHONE | Added|
| ohos.contact | Attribute | ATTR_ORGANIZATION | Added|
| ohos.contact | Attribute | ATTR_NOTE | Added|
| ohos.contact | Attribute | ATTR_NICKNAME | Added|
| ohos.contact | Attribute | ATTR_NAME | Added|
| ohos.contact | Attribute | ATTR_IM | Added|
| ohos.contact | Attribute | ATTR_GROUP_MEMBERSHIP | Added|
| ohos.contact | Attribute | ATTR_EMAIL | Added|
| ohos.contact | Attribute | ATTR_CONTACT_EVENT | Added|
| ohos.contact | ContactAttributes | attributes: Attribute[] | Added|
| ohos.contact | Contact | organization: Organization | Added|
| ohos.contact | Contact | note: Note | Added|
| ohos.contact | Contact | nickName: NickName | Added|
| ohos.contact | Contact | name: Name | Added|
| ohos.contact | Contact | websites: Website[] | Added|
| ohos.contact | Contact | sipAddresses: SipAddress[] | Added|
| ohos.contact | Contact | relations: Relation[] | Added|
| ohos.contact | Contact | postalAddresses: PostalAddress[] | Added|
| ohos.contact | Contact | portrait: Portrait | Added|
| ohos.contact | Contact | phoneNumbers: PhoneNumber[] | Added|
| ohos.contact | Contact | imAddresses: ImAddress[] | Added|
| ohos.contact | Contact | groups: Group[] | Added|
| ohos.contact | Contact | events: Event[] | Added|
| ohos.contact | Contact | emails: Email[] | Added|
| ohos.contact | Contact | contactAttributes: ContactAttributes | Added|
| ohos.contact | Contact | readonly key: string | Added|
| ohos.contact | Contact | readonly id: number | Added|
| ohos.contact | Contact | static readonly INVALID_CONTACT_ID: -1 | Added|
| ohos.contact | contact | isMyCard(id: number, callback: AsyncCallback\<boolean>): void;<br>isMyCard(id: number): Promise\<boolean>; | Added|
| ohos.contact | contact | isLocalContact(id: number, callback: AsyncCallback\<boolean>): void;<br>isLocalContact(id: number): Promise\<boolean>; | Added|
| ohos.contact | contact | updateContact(contact: Contact, callback: AsyncCallback\<void>): void;<br>updateContact(contact: Contact, attrs: ContactAttributes, callback: AsyncCallback\<void>): void;<br>updateContact(contact: Contact, attrs?: ContactAttributes): Promise\<void>; | Added|
| ohos.contact | contact | queryMyCard(callback: AsyncCallback\<Contact>): void;<br>queryMyCard(attrs: ContactAttributes, callback: AsyncCallback\<Contact>): void;<br>queryMyCard(attrs?: ContactAttributes): Promise\<Contact>; | Added|
| ohos.contact | contact | queryKey(id: number, callback: AsyncCallback\<string>): void;<br>queryKey(id: number, holder: Holder, callback: AsyncCallback\<string>): void;<br>queryKey(id: number, holder?: Holder): Promise\<string>; | Added|
| ohos.contact | contact | queryHolders(callback: AsyncCallback\<Array\<Holder>>): void;<br>queryHolders(): Promise\<Array\<Holder>>; | Added|
| ohos.contact | contact | queryGroups(callback: AsyncCallback\<Array\<Group>>): void;<br>queryGroups(holder: Holder, callback: AsyncCallback\<Array\<Group>>): void;<br>queryGroups(holder?: Holder): Promise\<Array\<Group>>; | Added|
| ohos.contact | contact | queryContactsByPhoneNumber(phoneNumber: string, callback: AsyncCallback\<Array\<Contact>>): void;<br>queryContactsByPhoneNumber(phoneNumber: string, holder: Holder, callback: AsyncCallback\<Array\<Contact>>): void;<br>queryContactsByPhoneNumber(phoneNumber: string, attrs: ContactAttributes, callback: AsyncCallback\<Array\<Contact>>): void;<br>queryContactsByPhoneNumber(phoneNumber: string, holder: Holder, attrs: ContactAttributes, callback: AsyncCallback\<Array\<Contact>>): void;<br>queryContactsByPhoneNumber(phoneNumber: string, holder?: Holder, attrs?: ContactAttributes): Promise\<Array\<Contact>>; | Added|
| ohos.contact | contact | queryContactsByEmail(email: string, callback: AsyncCallback\<Array\<Contact>>): void;<br>queryContactsByEmail(email: string, holder: Holder, callback: AsyncCallback\<Array\<Contact>>): void;<br>queryContactsByEmail(email: string, attrs: ContactAttributes, callback: AsyncCallback\<Array\<Contact>>): void;<br>queryContactsByEmail(email: string, holder: Holder, attrs: ContactAttributes, callback: AsyncCallback\<Array\<Contact>>): void;<br>queryContactsByEmail(email: string, holder?: Holder, attrs?: ContactAttributes): Promise\<Array\<Contact>>; | Added|
| ohos.contact | contact | queryContacts(callback: AsyncCallback\<Array\<Contact>>): void;<br>queryContacts(holder: Holder, callback: AsyncCallback\<Array\<Contact>>): void;<br>queryContacts(attrs: ContactAttributes, callback: AsyncCallback\<Array\<Contact>>): void;<br>queryContacts(holder: Holder, attrs: ContactAttributes, callback: AsyncCallback\<Array\<Contact>>): void;<br>queryContacts(holder?: Holder, attrs?: ContactAttributes): Promise\<Array\<Contact>>; | Added|
| ohos.contact | contact | queryContact(key: string, callback: AsyncCallback\<Contact>): void;<br>queryContact(key: string, holder: Holder, callback: AsyncCallback\<Contact>): void;<br>queryContact(key: string, attrs: ContactAttributes, callback: AsyncCallback\<Contact>): void;<br>queryContact(key: string, holder: Holder, attrs: ContactAttributes, callback: AsyncCallback\<Contact>): void;<br>queryContact(key: string, holder?: Holder, attrs?: ContactAttributes): Promise\<Contact>; | Added|
| ohos.contact | contact | deleteContact(key: string, callback: AsyncCallback\<void>): void;<br>deleteContact(key: string): Promise\<void>; | Added|
| ohos.contact | contact | selectContact(callback: AsyncCallback\<Array\<Contact>>): void;<br>selectContact(): Promise\<Array\<Contact>>; | Added|
| ohos.contact | contact | addContact(contact: Contact, callback: AsyncCallback\<number>): void;<br>addContact(contact: Contact): Promise\<number>; | Added|
