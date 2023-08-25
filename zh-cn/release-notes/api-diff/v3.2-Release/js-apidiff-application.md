| 操作 | 旧版本 | 新版本 | d.ts文件 |
| ---- | ------ | ------ | -------- |
|废弃版本有变化|类名：settings;<br>方法or属性：function getURI(name: string, callback: AsyncCallback\<object>): void;<br>旧版本信息：|类名：settings;<br>方法or属性：function getURI(name: string, callback: AsyncCallback\<object>): void;<br>新版本信息：9<br>代替接口：|@ohos.settings.d.ts|
|废弃版本有变化|类名：settings;<br>方法or属性：function getURI(name: string): Promise\<object>;<br>旧版本信息：|类名：settings;<br>方法or属性：function getURI(name: string): Promise\<object>;<br>新版本信息：9<br>代替接口：|@ohos.settings.d.ts|
|废弃版本有变化|类名：settings;<br>方法or属性：function getValue(dataAbilityHelper: DataAbilityHelper, name: string, callback: AsyncCallback\<object>): void;<br>旧版本信息：|类名：settings;<br>方法or属性：function getValue(dataAbilityHelper: DataAbilityHelper, name: string, callback: AsyncCallback\<object>): void;<br>新版本信息：9<br>代替接口：|@ohos.settings.d.ts|
|废弃版本有变化|类名：settings;<br>方法or属性：function getValue(dataAbilityHelper: DataAbilityHelper, name: string): Promise\<object>;<br>旧版本信息：|类名：settings;<br>方法or属性：function getValue(dataAbilityHelper: DataAbilityHelper, name: string): Promise\<object>;<br>新版本信息：9<br>代替接口：|@ohos.settings.d.ts|
|废弃版本有变化|类名：settings;<br>方法or属性：function setValue(dataAbilityHelper: DataAbilityHelper, name: string, value: object, callback: AsyncCallback\<boolean>): void;<br>旧版本信息：|类名：settings;<br>方法or属性：function setValue(dataAbilityHelper: DataAbilityHelper, name: string, value: object, callback: AsyncCallback\<boolean>): void;<br>新版本信息：9<br>代替接口：|@ohos.settings.d.ts|
|废弃版本有变化|类名：settings;<br>方法or属性：function setValue(dataAbilityHelper: DataAbilityHelper, name: string, value: object): Promise\<boolean>;<br>旧版本信息：|类名：settings;<br>方法or属性：function setValue(dataAbilityHelper: DataAbilityHelper, name: string, value: object): Promise\<boolean>;<br>新版本信息：9<br>代替接口：|@ohos.settings.d.ts|
|废弃版本有变化|类名：settings;<br>方法or属性：function getValueSync(dataAbilityHelper: DataAbilityHelper, name: string, defValue: string): string;<br>旧版本信息：|类名：settings;<br>方法or属性：function getValueSync(dataAbilityHelper: DataAbilityHelper, name: string, defValue: string): string;<br>新版本信息：9<br>代替接口：|@ohos.settings.d.ts|
|废弃版本有变化|类名：settings;<br>方法or属性：function setValueSync(dataAbilityHelper: DataAbilityHelper, name: string, value: string): boolean;<br>旧版本信息：|类名：settings;<br>方法or属性：function setValueSync(dataAbilityHelper: DataAbilityHelper, name: string, value: string): boolean;<br>新版本信息：9<br>代替接口：|@ohos.settings.d.ts|
|新增(错误码)|类名：call;<br>方法or属性：function makeCall(phoneNumber: string, callback: AsyncCallback\<void>): void;<br>旧版本信息：|类名：call;<br>方法or属性：function makeCall(phoneNumber: string, callback: AsyncCallback\<void>): void;<br>新版本信息：401,8300001,8300002,8300003,8300999|@ohos.telephony.call.d.ts|
|新增(错误码)|类名：call;<br>方法or属性：function makeCall(phoneNumber: string): Promise\<void>;<br>旧版本信息：|类名：call;<br>方法or属性：function makeCall(phoneNumber: string): Promise\<void>;<br>新版本信息：401,8300001,8300002,8300003,8300999|@ohos.telephony.call.d.ts|
|权限有变化|类名：contact;<br>方法or属性：function addContact(contact: Contact, callback: AsyncCallback\<number>): void;<br>旧版本信息：|类名：contact;<br>方法or属性：function addContact(contact: Contact, callback: AsyncCallback\<number>): void;<br>新版本信息：ohos.permission.WRITE_CONTACTS|@ohos.contact.d.ts|
|权限有变化|类名：contact;<br>方法or属性：function addContact(contact: Contact): Promise\<number>;<br>旧版本信息：|类名：contact;<br>方法or属性：function addContact(contact: Contact): Promise\<number>;<br>新版本信息：ohos.permission.WRITE_CONTACTS|@ohos.contact.d.ts|
|权限有变化|类名：contact;<br>方法or属性：function deleteContact(key: string, callback: AsyncCallback\<void>): void;<br>旧版本信息：|类名：contact;<br>方法or属性：function deleteContact(key: string, callback: AsyncCallback\<void>): void;<br>新版本信息：ohos.permission.WRITE_CONTACTS|@ohos.contact.d.ts|
|权限有变化|类名：contact;<br>方法or属性：function deleteContact(key: string): Promise\<void>;<br>旧版本信息：|类名：contact;<br>方法or属性：function deleteContact(key: string): Promise\<void>;<br>新版本信息：ohos.permission.WRITE_CONTACTS|@ohos.contact.d.ts|
|权限有变化|类名：contact;<br>方法or属性：function updateContact(contact: Contact, callback: AsyncCallback\<void>): void;<br>旧版本信息：|类名：contact;<br>方法or属性：function updateContact(contact: Contact, callback: AsyncCallback\<void>): void;<br>新版本信息：ohos.permission.WRITE_CONTACTS|@ohos.contact.d.ts|
|权限有变化|类名：contact;<br>方法or属性：function updateContact(contact: Contact, attrs: ContactAttributes, callback: AsyncCallback\<void>): void;<br>旧版本信息：|类名：contact;<br>方法or属性：function updateContact(contact: Contact, attrs: ContactAttributes, callback: AsyncCallback\<void>): void;<br>新版本信息：ohos.permission.WRITE_CONTACTS|@ohos.contact.d.ts|
|权限有变化|类名：contact;<br>方法or属性：function updateContact(contact: Contact, attrs?: ContactAttributes): Promise\<void>;<br>旧版本信息：|类名：contact;<br>方法or属性：function updateContact(contact: Contact, attrs?: ContactAttributes): Promise\<void>;<br>新版本信息：ohos.permission.WRITE_CONTACTS|@ohos.contact.d.ts|
|权限有变化|类名：settings;<br>方法or属性：function setValueSync(dataAbilityHelper: DataAbilityHelper, name: string, value: string): boolean;<br>旧版本信息：|类名：settings;<br>方法or属性：function setValueSync(dataAbilityHelper: DataAbilityHelper, name: string, value: string): boolean;<br>新版本信息：ohos.permission.MANAGE_SECURE_SETTINGS|@ohos.settings.d.ts|
|model有变化|类名：settings;<br>方法or属性：function getValue(dataAbilityHelper: DataAbilityHelper, name: string, callback: AsyncCallback\<object>): void;<br>旧版本信息：|类名：settings;<br>方法or属性：function getValue(dataAbilityHelper: DataAbilityHelper, name: string, callback: AsyncCallback\<object>): void;<br>新版本信息：FAModelOnly|@ohos.settings.d.ts|
|model有变化|类名：settings;<br>方法or属性：function getValue(dataAbilityHelper: DataAbilityHelper, name: string): Promise\<object>;<br>旧版本信息：|类名：settings;<br>方法or属性：function getValue(dataAbilityHelper: DataAbilityHelper, name: string): Promise\<object>;<br>新版本信息：FAModelOnly|@ohos.settings.d.ts|
|model有变化|类名：settings;<br>方法or属性：function setValue(dataAbilityHelper: DataAbilityHelper, name: string, value: object, callback: AsyncCallback\<boolean>): void;<br>旧版本信息：|类名：settings;<br>方法or属性：function setValue(dataAbilityHelper: DataAbilityHelper, name: string, value: object, callback: AsyncCallback\<boolean>): void;<br>新版本信息：FAModelOnly|@ohos.settings.d.ts|
|model有变化|类名：settings;<br>方法or属性：function setValue(dataAbilityHelper: DataAbilityHelper, name: string, value: object): Promise\<boolean>;<br>旧版本信息：|类名：settings;<br>方法or属性：function setValue(dataAbilityHelper: DataAbilityHelper, name: string, value: object): Promise\<boolean>;<br>新版本信息：FAModelOnly|@ohos.settings.d.ts|
|model有变化|类名：settings;<br>方法or属性：function getValueSync(dataAbilityHelper: DataAbilityHelper, name: string, defValue: string): string;<br>旧版本信息：|类名：settings;<br>方法or属性：function getValueSync(dataAbilityHelper: DataAbilityHelper, name: string, defValue: string): string;<br>新版本信息：FAModelOnly|@ohos.settings.d.ts|
|model有变化|类名：settings;<br>方法or属性：function setValueSync(dataAbilityHelper: DataAbilityHelper, name: string, value: string): boolean;<br>旧版本信息：|类名：settings;<br>方法or属性：function setValueSync(dataAbilityHelper: DataAbilityHelper, name: string, value: string): boolean;<br>新版本信息：FAModelOnly|@ohos.settings.d.ts|
|函数有变化|类名：Contact;<br>方法or属性：readonly id: number|类名：Contact;<br>方法or属性：readonly id?: number|@ohos.contact.d.ts|
|函数有变化|类名：Contact;<br>方法or属性：readonly key: string|类名：Contact;<br>方法or属性：readonly key?: string|@ohos.contact.d.ts|
|函数有变化|类名：Contact;<br>方法or属性：contactAttributes: ContactAttributes|类名：Contact;<br>方法or属性：contactAttributes?: ContactAttributes|@ohos.contact.d.ts|
|函数有变化|类名：Contact;<br>方法or属性：emails: Email[]|类名：Contact;<br>方法or属性：emails?: Email[]|@ohos.contact.d.ts|
|函数有变化|类名：Contact;<br>方法or属性：events: Event[]|类名：Contact;<br>方法or属性：events?: Event[]|@ohos.contact.d.ts|
|函数有变化|类名：Contact;<br>方法or属性：groups: Group[]|类名：Contact;<br>方法or属性：groups?: Group[]|@ohos.contact.d.ts|
|函数有变化|类名：Contact;<br>方法or属性：imAddresses: ImAddress[]|类名：Contact;<br>方法or属性：imAddresses?: ImAddress[]|@ohos.contact.d.ts|
|函数有变化|类名：Contact;<br>方法or属性：phoneNumbers: PhoneNumber[]|类名：Contact;<br>方法or属性：phoneNumbers?: PhoneNumber[]|@ohos.contact.d.ts|
|函数有变化|类名：Contact;<br>方法or属性：portrait: Portrait|类名：Contact;<br>方法or属性：portrait?: Portrait|@ohos.contact.d.ts|
|函数有变化|类名：Contact;<br>方法or属性：postalAddresses: PostalAddress[]|类名：Contact;<br>方法or属性：postalAddresses?: PostalAddress[]|@ohos.contact.d.ts|
|函数有变化|类名：Contact;<br>方法or属性：relations: Relation[]|类名：Contact;<br>方法or属性：relations?: Relation[]|@ohos.contact.d.ts|
|函数有变化|类名：Contact;<br>方法or属性：sipAddresses: SipAddress[]|类名：Contact;<br>方法or属性：sipAddresses?: SipAddress[]|@ohos.contact.d.ts|
|函数有变化|类名：Contact;<br>方法or属性：websites: Website[]|类名：Contact;<br>方法or属性：websites?: Website[]|@ohos.contact.d.ts|
|函数有变化|类名：Contact;<br>方法or属性：name: Name|类名：Contact;<br>方法or属性：name?: Name|@ohos.contact.d.ts|
|函数有变化|类名：Contact;<br>方法or属性：nickName: NickName|类名：Contact;<br>方法or属性：nickName?: NickName|@ohos.contact.d.ts|
|函数有变化|类名：Contact;<br>方法or属性：note: Note|类名：Contact;<br>方法or属性：note?: Note|@ohos.contact.d.ts|
|函数有变化|类名：Contact;<br>方法or属性：organization: Organization|类名：Contact;<br>方法or属性：organization?: Organization|@ohos.contact.d.ts|
|函数有变化|类名：Email;<br>方法or属性：labelName: string|类名：Email;<br>方法or属性：labelName?: string|@ohos.contact.d.ts|
|函数有变化|类名：Event;<br>方法or属性：labelName: string|类名：Event;<br>方法or属性：labelName?: string|@ohos.contact.d.ts|
|函数有变化|类名：ImAddress;<br>方法or属性：labelName: string|类名：ImAddress;<br>方法or属性：labelName?: string|@ohos.contact.d.ts|
|函数有变化|类名：PhoneNumber;<br>方法or属性：labelName: string|类名：PhoneNumber;<br>方法or属性：labelName?: string|@ohos.contact.d.ts|
|函数有变化|类名：PostalAddress;<br>方法or属性：labelName: string|类名：PostalAddress;<br>方法or属性：labelName?: string|@ohos.contact.d.ts|
|函数有变化|类名：Relation;<br>方法or属性：labelName: string|类名：Relation;<br>方法or属性：labelName?: string|@ohos.contact.d.ts|
|函数有变化|类名：SipAddress;<br>方法or属性：labelName: string|类名：SipAddress;<br>方法or属性：labelName?: string|@ohos.contact.d.ts|
|函数有变化|类名：Email;<br>方法or属性：displayName: string|类名：Email;<br>方法or属性：displayName?: string|@ohos.contact.d.ts|
|函数有变化|类名：Email;<br>方法or属性：labelId: number|类名：Email;<br>方法or属性：labelId?: number|@ohos.contact.d.ts|
|函数有变化|类名：Event;<br>方法or属性：labelId: number|类名：Event;<br>方法or属性：labelId?: number|@ohos.contact.d.ts|
|函数有变化|类名：ImAddress;<br>方法or属性：labelId: number|类名：ImAddress;<br>方法or属性：labelId?: number|@ohos.contact.d.ts|
|函数有变化|类名：PhoneNumber;<br>方法or属性：labelId: number|类名：PhoneNumber;<br>方法or属性：labelId?: number|@ohos.contact.d.ts|
|函数有变化|类名：PostalAddress;<br>方法or属性：labelId: number|类名：PostalAddress;<br>方法or属性：labelId?: number|@ohos.contact.d.ts|
|函数有变化|类名：Relation;<br>方法or属性：labelId: number|类名：Relation;<br>方法or属性：labelId?: number|@ohos.contact.d.ts|
|函数有变化|类名：SipAddress;<br>方法or属性：labelId: number|类名：SipAddress;<br>方法or属性：labelId?: number|@ohos.contact.d.ts|
|函数有变化|类名：Group;<br>方法or属性：groupId: number|类名：Group;<br>方法or属性：groupId?: number|@ohos.contact.d.ts|
|函数有变化|类名：Holder;<br>方法or属性：readonly displayName: string|类名：Holder;<br>方法or属性：readonly displayName?: string|@ohos.contact.d.ts|
|函数有变化|类名：Holder;<br>方法or属性：holderId: number|类名：Holder;<br>方法or属性：holderId?: number|@ohos.contact.d.ts|
|函数有变化|类名：Name;<br>方法or属性：familyName: string|类名：Name;<br>方法or属性：familyName?: string|@ohos.contact.d.ts|
|函数有变化|类名：Name;<br>方法or属性：familyNamePhonetic: string|类名：Name;<br>方法or属性：familyNamePhonetic?: string|@ohos.contact.d.ts|
|函数有变化|类名：Name;<br>方法or属性：givenName: string|类名：Name;<br>方法or属性：givenName?: string|@ohos.contact.d.ts|
|函数有变化|类名：Name;<br>方法or属性：givenNamePhonetic: string|类名：Name;<br>方法or属性：givenNamePhonetic?: string|@ohos.contact.d.ts|
|函数有变化|类名：Name;<br>方法or属性：middleName: string|类名：Name;<br>方法or属性：middleName?: string|@ohos.contact.d.ts|
|函数有变化|类名：Name;<br>方法or属性：middleNamePhonetic: string|类名：Name;<br>方法or属性：middleNamePhonetic?: string|@ohos.contact.d.ts|
|函数有变化|类名：Name;<br>方法or属性：namePrefix: string|类名：Name;<br>方法or属性：namePrefix?: string|@ohos.contact.d.ts|
|函数有变化|类名：Name;<br>方法or属性：nameSuffix: string|类名：Name;<br>方法or属性：nameSuffix?: string|@ohos.contact.d.ts|
|函数有变化|类名：Organization;<br>方法or属性：title: string|类名：Organization;<br>方法or属性：title?: string|@ohos.contact.d.ts|
|函数有变化|类名：PostalAddress;<br>方法or属性：city: string|类名：PostalAddress;<br>方法or属性：city?: string|@ohos.contact.d.ts|
|函数有变化|类名：PostalAddress;<br>方法or属性：country: string|类名：PostalAddress;<br>方法or属性：country?: string|@ohos.contact.d.ts|
|函数有变化|类名：PostalAddress;<br>方法or属性：neighborhood: string|类名：PostalAddress;<br>方法or属性：neighborhood?: string|@ohos.contact.d.ts|
|函数有变化|类名：PostalAddress;<br>方法or属性：pobox: string|类名：PostalAddress;<br>方法or属性：pobox?: string|@ohos.contact.d.ts|
|函数有变化|类名：PostalAddress;<br>方法or属性：postcode: string|类名：PostalAddress;<br>方法or属性：postcode?: string|@ohos.contact.d.ts|
|函数有变化|类名：PostalAddress;<br>方法or属性：region: string|类名：PostalAddress;<br>方法or属性：region?: string|@ohos.contact.d.ts|
|函数有变化|类名：PostalAddress;<br>方法or属性：street: string|类名：PostalAddress;<br>方法or属性：street?: string|@ohos.contact.d.ts|
