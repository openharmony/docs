| Change Type | Old Version | New Version | d.ts File |
| ---- | ------ | ------ | -------- |
|Added|NA|Class name: Contact<br>Method or attribute name: readonly id?: number|@ohos.contact.d.ts|
|Added|NA|Class name: Contact<br>Method or attribute name: readonly key?: string|@ohos.contact.d.ts|
|Added|NA|Class name: Contact<br>Method or attribute name: contactAttributes?: ContactAttributes|@ohos.contact.d.ts|
|Added|NA|Class name: Contact<br>Method or attribute name: emails?: Email[]|@ohos.contact.d.ts|
|Added|NA|Class name: Contact<br>Method or attribute name: events?: Event[]|@ohos.contact.d.ts|
|Added|NA|Class name: Contact<br>Method or attribute name: groups?: Group[]|@ohos.contact.d.ts|
|Added|NA|Class name: Contact<br>Method or attribute name: imAddresses?: ImAddress[]|@ohos.contact.d.ts|
|Added|NA|Class name: Contact<br>Method or attribute name: phoneNumbers?: PhoneNumber[]|@ohos.contact.d.ts|
|Added|NA|Class name: Contact<br>Method or attribute name: portrait?: Portrait|@ohos.contact.d.ts|
|Added|NA|Class name: Contact<br>Method or attribute name: postalAddresses?: PostalAddress[]|@ohos.contact.d.ts|
|Added|NA|Class name: Contact<br>Method or attribute name: relations?: Relation[]|@ohos.contact.d.ts|
|Added|NA|Class name: Contact<br>Method or attribute name: sipAddresses?: SipAddress[]|@ohos.contact.d.ts|
|Added|NA|Class name: Contact<br>Method or attribute name: websites?: Website[]|@ohos.contact.d.ts|
|Added|NA|Class name: Contact<br>Method or attribute name: name?: Name|@ohos.contact.d.ts|
|Added|NA|Class name: Contact<br>Method or attribute name: nickName?: NickName|@ohos.contact.d.ts|
|Added|NA|Class name: Contact<br>Method or attribute name: note?: Note|@ohos.contact.d.ts|
|Added|NA|Class name: Contact<br>Method or attribute name: organization?: Organization|@ohos.contact.d.ts|
|Added|NA|Class name: Email<br>Method or attribute name: labelName?: string|@ohos.contact.d.ts|
|Added|NA|Class name: Email<br>Method or attribute name: displayName?: string|@ohos.contact.d.ts|
|Added|NA|Class name: Email<br>Method or attribute name: labelId?: number|@ohos.contact.d.ts|
|Added|NA|Class name: Event<br>Method or attribute name: labelName?: string|@ohos.contact.d.ts|
|Added|NA|Class name: Event<br>Method or attribute name: labelId?: number|@ohos.contact.d.ts|
|Added|NA|Class name: Group<br>Method or attribute name: groupId?: number|@ohos.contact.d.ts|
|Added|NA|Class name: Holder<br>Method or attribute name: readonly displayName?: string|@ohos.contact.d.ts|
|Added|NA|Class name: Holder<br>Method or attribute name: holderId?: number|@ohos.contact.d.ts|
|Added|NA|Class name: ImAddress<br>Method or attribute name: labelName?: string|@ohos.contact.d.ts|
|Added|NA|Class name: ImAddress<br>Method or attribute name: labelId?: number|@ohos.contact.d.ts|
|Added|NA|Class name: Name<br>Method or attribute name: familyName?: string|@ohos.contact.d.ts|
|Added|NA|Class name: Name<br>Method or attribute name: familyNamePhonetic?: string|@ohos.contact.d.ts|
|Added|NA|Class name: Name<br>Method or attribute name: givenName?: string|@ohos.contact.d.ts|
|Added|NA|Class name: Name<br>Method or attribute name: givenNamePhonetic?: string|@ohos.contact.d.ts|
|Added|NA|Class name: Name<br>Method or attribute name: middleName?: string|@ohos.contact.d.ts|
|Added|NA|Class name: Name<br>Method or attribute name: middleNamePhonetic?: string|@ohos.contact.d.ts|
|Added|NA|Class name: Name<br>Method or attribute name: namePrefix?: string|@ohos.contact.d.ts|
|Added|NA|Class name: Name<br>Method or attribute name: nameSuffix?: string|@ohos.contact.d.ts|
|Added|NA|Class name: Organization<br>Method or attribute name: title?: string|@ohos.contact.d.ts|
|Added|NA|Class name: PhoneNumber<br>Method or attribute name: labelName?: string|@ohos.contact.d.ts|
|Added|NA|Class name: PhoneNumber<br>Method or attribute name: labelId?: number|@ohos.contact.d.ts|
|Added|NA|Class name: PostalAddress<br>Method or attribute name: city?: string|@ohos.contact.d.ts|
|Added|NA|Class name: PostalAddress<br>Method or attribute name: country?: string|@ohos.contact.d.ts|
|Added|NA|Class name: PostalAddress<br>Method or attribute name: labelName?: string|@ohos.contact.d.ts|
|Added|NA|Class name: PostalAddress<br>Method or attribute name: neighborhood?: string|@ohos.contact.d.ts|
|Added|NA|Class name: PostalAddress<br>Method or attribute name: pobox?: string|@ohos.contact.d.ts|
|Added|NA|Class name: PostalAddress<br>Method or attribute name: postcode?: string|@ohos.contact.d.ts|
|Added|NA|Class name: PostalAddress<br>Method or attribute name: region?: string|@ohos.contact.d.ts|
|Added|NA|Class name: PostalAddress<br>Method or attribute name: street?: string|@ohos.contact.d.ts|
|Added|NA|Class name: PostalAddress<br>Method or attribute name: labelId?: number|@ohos.contact.d.ts|
|Added|NA|Class name: Relation<br>Method or attribute name: labelName?: string|@ohos.contact.d.ts|
|Added|NA|Class name: Relation<br>Method or attribute name: labelId?: number|@ohos.contact.d.ts|
|Added|NA|Class name: SipAddress<br>Method or attribute name: labelName?: string|@ohos.contact.d.ts|
|Added|NA|Class name: SipAddress<br>Method or attribute name: labelId?: number|@ohos.contact.d.ts|
|Model changed|Class name: settings<br>Method or attribute name: function getValue(dataAbilityHelper: DataAbilityHelper, name: string, callback: AsyncCallback\<object>): void;<br>Model: N/A|Class name: settings<br>Method or attribute name: function getValue(dataAbilityHelper: DataAbilityHelper, name: string, callback: AsyncCallback\<object>): void;<br>Model: @FAModelOnly|@ohos.settings.d.ts|
|Model changed|Class name: settings<br>Method or attribute name: function getValue(dataAbilityHelper: DataAbilityHelper, name: string): Promise\<object>;<br>Model: N/A|Class name: settings<br>Method or attribute name: function getValue(dataAbilityHelper: DataAbilityHelper, name: string): Promise\<object>;<br>Model: @FAModelOnly|@ohos.settings.d.ts|
|Model changed|Class name: settings<br>Method or attribute name: function setValue(dataAbilityHelper: DataAbilityHelper, name: string, value: object, callback: AsyncCallback\<boolean>): void;<br>Model: N/A|Class name: settings<br>Method or attribute name: function setValue(dataAbilityHelper: DataAbilityHelper, name: string, value: object, callback: AsyncCallback\<boolean>): void;<br>Model: @FAModelOnly|@ohos.settings.d.ts|
|Model changed|Class name: settings<br>Method or attribute name: function setValue(dataAbilityHelper: DataAbilityHelper, name: string, value: object): Promise\<boolean>;<br>Model: N/A|Class name: settings<br>Method or attribute name: function setValue(dataAbilityHelper: DataAbilityHelper, name: string, value: object): Promise\<boolean>;<br>Model: @FAModelOnly|@ohos.settings.d.ts|
|Model changed|Class name: settings<br>Method or attribute name: function getValueSync(dataAbilityHelper: DataAbilityHelper, name: string, defValue: string): string;<br>Model: N/A|Class name: settings<br>Method or attribute name: function getValueSync(dataAbilityHelper: DataAbilityHelper, name: string, defValue: string): string;<br>Model: @FAModelOnly|@ohos.settings.d.ts|
|Model changed|Class name: settings<br>Method or attribute name: function setValueSync(dataAbilityHelper: DataAbilityHelper, name: string, value: string): boolean;<br>Model: N/A|Class name: settings<br>Method or attribute name: function setValueSync(dataAbilityHelper: DataAbilityHelper, name: string, value: string): boolean;<br>Model: @FAModelOnly|@ohos.settings.d.ts|
|Deprecated version changed|Class name: settings<br>Method or attribute name: function getURI(name: string, callback: AsyncCallback\<object>): void;<br>Deprecated version: N/A|Class name: settings<br>Method or attribute name: function getURI(name: string, callback: AsyncCallback\<object>): void;<br>Deprecated version: 9<br>Substitute API: N/A|@ohos.settings.d.ts|
|Deprecated version changed|Class name: settings<br>Method or attribute name: function getURI(name: string): Promise\<object>;<br>Deprecated version: N/A|Class name: settings<br>Method or attribute name: function getURI(name: string): Promise\<object>;<br>Deprecated version: 9<br>Substitute API: N/A|@ohos.settings.d.ts|
|Deprecated version changed|Class name: settings<br>Method or attribute name: function getValue(dataAbilityHelper: DataAbilityHelper, name: string, callback: AsyncCallback\<object>): void;<br>Deprecated version: N/A|Class name: settings<br>Method or attribute name: function getValue(dataAbilityHelper: DataAbilityHelper, name: string, callback: AsyncCallback\<object>): void;<br>Deprecated version: 9<br>Substitute API: N/A|@ohos.settings.d.ts|
|Deprecated version changed|Class name: settings<br>Method or attribute name: function getValue(dataAbilityHelper: DataAbilityHelper, name: string): Promise\<object>;<br>Deprecated version: N/A|Class name: settings<br>Method or attribute name: function getValue(dataAbilityHelper: DataAbilityHelper, name: string): Promise\<object>;<br>Deprecated version: 9<br>Substitute API: N/A|@ohos.settings.d.ts|
|Deprecated version changed|Class name: settings<br>Method or attribute name: function setValue(dataAbilityHelper: DataAbilityHelper, name: string, value: object, callback: AsyncCallback\<boolean>): void;<br>Deprecated version: N/A|Class name: settings<br>Method or attribute name: function setValue(dataAbilityHelper: DataAbilityHelper, name: string, value: object, callback: AsyncCallback\<boolean>): void;<br>Deprecated version: 9<br>Substitute API: N/A|@ohos.settings.d.ts|
|Deprecated version changed|Class name: settings<br>Method or attribute name: function setValue(dataAbilityHelper: DataAbilityHelper, name: string, value: object): Promise\<boolean>;<br>Deprecated version: N/A|Class name: settings<br>Method or attribute name: function setValue(dataAbilityHelper: DataAbilityHelper, name: string, value: object): Promise\<boolean>;<br>Deprecated version: 9<br>Substitute API: N/A|@ohos.settings.d.ts|
|Deprecated version changed|Class name: settings<br>Method or attribute name: function getValueSync(dataAbilityHelper: DataAbilityHelper, name: string, defValue: string): string;<br>Deprecated version: N/A|Class name: settings<br>Method or attribute name: function getValueSync(dataAbilityHelper: DataAbilityHelper, name: string, defValue: string): string;<br>Deprecated version: 9<br>Substitute API: N/A|@ohos.settings.d.ts|
|Deprecated version changed|Class name: settings<br>Method or attribute name: function setValueSync(dataAbilityHelper: DataAbilityHelper, name: string, value: string): boolean;<br>Deprecated version: N/A|Class name: settings<br>Method or attribute name: function setValueSync(dataAbilityHelper: DataAbilityHelper, name: string, value: string): boolean;<br>Deprecated version: 9<br>Substitute API: N/A|@ohos.settings.d.ts|
|Error code added|NA|Class name: call<br>Method or attribute name: function makeCall(phoneNumber: string, callback: AsyncCallback\<void>): void;<br>Error code: 401, 8300001, 8300002, 8300003, 8300999|@ohos.telephony.call.d.ts|
|Error code added|NA|Class name: call<br>Method or attribute name: function makeCall(phoneNumber: string): Promise\<void>;<br>Error code: 401, 8300001, 8300002, 8300003, 8300999|@ohos.telephony.call.d.ts|
|Permission added|Class name: contact<br>Method or attribute name: function addContact(contact: Contact, callback: AsyncCallback\<number>): void;<br>Permission: N/A|Class name: contact<br>Method or attribute name: function addContact(contact: Contact, callback: AsyncCallback\<number>): void;<br>Permission: ohos.permission.WRITE_CONTACTS|@ohos.contact.d.ts|
|Permission added|Class name: contact<br>Method or attribute name: function addContact(contact: Contact): Promise\<number>;<br>Permission: N/A|Class name: contact<br>Method or attribute name: function addContact(contact: Contact): Promise\<number>;<br>Permission: ohos.permission.WRITE_CONTACTS|@ohos.contact.d.ts|
|Permission added|Class name: contact<br>Method or attribute name: function deleteContact(key: string, callback: AsyncCallback\<void>): void;<br>Permission: N/A|Class name: contact<br>Method or attribute name: function deleteContact(key: string, callback: AsyncCallback\<void>): void;<br>Permission: ohos.permission.WRITE_CONTACTS|@ohos.contact.d.ts|
|Permission added|Class name: contact<br>Method or attribute name: function deleteContact(key: string): Promise\<void>;<br>Permission: N/A|Class name: contact<br>Method or attribute name: function deleteContact(key: string): Promise\<void>;<br>Permission: ohos.permission.WRITE_CONTACTS|@ohos.contact.d.ts|
|Permission added|Class name: contact<br>Method or attribute name: function updateContact(contact: Contact, callback: AsyncCallback\<void>): void;<br>Permission: N/A|Class name: contact<br>Method or attribute name: function updateContact(contact: Contact, callback: AsyncCallback\<void>): void;<br>Permission: ohos.permission.WRITE_CONTACTS|@ohos.contact.d.ts|
|Permission added|Class name: contact<br>Method or attribute name: function updateContact(contact: Contact, attrs: ContactAttributes, callback: AsyncCallback\<void>): void;<br>Permission: N/A|Class name: contact<br>Method or attribute name: function updateContact(contact: Contact, attrs: ContactAttributes, callback: AsyncCallback\<void>): void;<br>Permission: ohos.permission.WRITE_CONTACTS|@ohos.contact.d.ts|
|Permission added|Class name: contact<br>Method or attribute name: function updateContact(contact: Contact, attrs?: ContactAttributes): Promise\<void>;<br>Permission: N/A|Class name: contact<br>Method or attribute name: function updateContact(contact: Contact, attrs?: ContactAttributes): Promise\<void>;<br>Permission: ohos.permission.WRITE_CONTACTS|@ohos.contact.d.ts|
|Permission added|Class name: settings<br>Method or attribute name: function setValueSync(dataAbilityHelper: DataAbilityHelper, name: string, value: string): boolean;<br>Permission: N/A|Class name: settings<br>Method or attribute name: function setValueSync(dataAbilityHelper: DataAbilityHelper, name: string, value: string): boolean;<br>Permission: ohos.permission.MANAGE_SECURE_SETTINGS|@ohos.settings.d.ts|
|SysCap changed|Class name: contact<br>Method or attribute name: function selectContact(callback: AsyncCallback\<Array\<Contact>>): void;<br>SysCap:SystemCapability.Applications.ContactsData|Class name: contact<br>Method or attribute name: function selectContact(callback: AsyncCallback\<Array\<Contact>>): void;<br>SysCap:SystemCapability.Applications.Contacts|@ohos.contact.d.ts|
|SysCap changed|Class name: contact<br>Method or attribute name: function selectContact(): Promise\<Array\<Contact>>;<br>SysCap:SystemCapability.Applications.ContactsData|Class name: contact<br>Method or attribute name: function selectContact(): Promise\<Array\<Contact>>;<br>SysCap:SystemCapability.Applications.Contacts|@ohos.contact.d.ts|
