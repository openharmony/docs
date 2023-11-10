| 操作 | 旧版本 | 新版本 | d.ts文件 |
| ---- | ------ | ------ | -------- |
|新增|NA|类名：calendarManager;<br>方法or属性：function getCalendarManager(context: Context) : CalendarManager;|@ohos.calendarManager.d.ts|
|新增|NA|类名：CalendarManager;<br>方法or属性：createCalendar(calendarAccount: CalendarAccount): Promise\<Calendar>;|@ohos.calendarManager.d.ts|
|新增|NA|类名：CalendarManager;<br>方法or属性：createCalendar(calendarAccount: CalendarAccount, callback: AsyncCallback\<Calendar>): void;|@ohos.calendarManager.d.ts|
|新增|NA|类名：CalendarManager;<br>方法or属性：deleteCalendar(calendar: Calendar): Promise\<void>;|@ohos.calendarManager.d.ts|
|新增|NA|类名：CalendarManager;<br>方法or属性：deleteCalendar(calendar: Calendar, callback: AsyncCallback\<void>): void;|@ohos.calendarManager.d.ts|
|新增|NA|类名：CalendarManager;<br>方法or属性：getCalendar(calendarAccount?: CalendarAccount): Promise\<Calendar>;|@ohos.calendarManager.d.ts|
|新增|NA|类名：CalendarManager;<br>方法or属性：getCalendar(calendarAccount: CalendarAccount, callback: AsyncCallback\<Calendar>): void;|@ohos.calendarManager.d.ts|
|新增|NA|类名：CalendarManager;<br>方法or属性：getCalendar(callback: AsyncCallback\<Calendar>): void;|@ohos.calendarManager.d.ts|
|新增|NA|类名：CalendarManager;<br>方法or属性：getAllCalendars(): Promise\<Calendar[]>;|@ohos.calendarManager.d.ts|
|新增|NA|类名：CalendarManager;<br>方法or属性：getAllCalendars(callback: AsyncCallback\<Calendar[]>): void;|@ohos.calendarManager.d.ts|
|新增|NA|类名：Calendar;<br>方法or属性：readonly id: number|@ohos.calendarManager.d.ts|
|新增|NA|类名：Calendar;<br>方法or属性：addEvent(event: Event): Promise\<number>;|@ohos.calendarManager.d.ts|
|新增|NA|类名：Calendar;<br>方法or属性：addEvent(event: Event, callback: AsyncCallback\<number>): void;|@ohos.calendarManager.d.ts|
|新增|NA|类名：Calendar;<br>方法or属性：addEvents(events: Event[]): Promise\<void>;|@ohos.calendarManager.d.ts|
|新增|NA|类名：Calendar;<br>方法or属性：addEvents(events: Event[], callback: AsyncCallback\<void>): void;|@ohos.calendarManager.d.ts|
|新增|NA|类名：Calendar;<br>方法or属性：deleteEvent(id: number): Promise\<void>;|@ohos.calendarManager.d.ts|
|新增|NA|类名：Calendar;<br>方法or属性：deleteEvent(id: number, callback: AsyncCallback\<void>): void;|@ohos.calendarManager.d.ts|
|新增|NA|类名：Calendar;<br>方法or属性：deleteEvents(ids: number[]): Promise\<void>;|@ohos.calendarManager.d.ts|
|新增|NA|类名：Calendar;<br>方法or属性：deleteEvents(ids: number[], callback: AsyncCallback\<void>): void;|@ohos.calendarManager.d.ts|
|新增|NA|类名：Calendar;<br>方法or属性：updateEvent(event: Event): Promise\<void>;|@ohos.calendarManager.d.ts|
|新增|NA|类名：Calendar;<br>方法or属性：updateEvent(event: Event, callback: AsyncCallback\<void>): void;|@ohos.calendarManager.d.ts|
|新增|NA|类名：Calendar;<br>方法or属性：getEvents(eventFilter?: EventFilter, eventKey?: (keyof Event)[]): Promise\<Event[]>;|@ohos.calendarManager.d.ts|
|新增|NA|类名：Calendar;<br>方法or属性：getEvents(eventFilter: EventFilter, eventKey: (keyof Event)[], callback: AsyncCallback\<Event[]>):void;|@ohos.calendarManager.d.ts|
|新增|NA|类名：Calendar;<br>方法or属性：getEvents(callback: AsyncCallback\<Event[]>):void;|@ohos.calendarManager.d.ts|
|新增|NA|类名：Calendar;<br>方法or属性：getConfig(): CalendarConfig;|@ohos.calendarManager.d.ts|
|新增|NA|类名：Calendar;<br>方法or属性：setConfig(config: CalendarConfig): Promise\<void>;|@ohos.calendarManager.d.ts|
|新增|NA|类名：Calendar;<br>方法or属性：setConfig(config: CalendarConfig, callback: AsyncCallback\<void>): void;|@ohos.calendarManager.d.ts|
|新增|NA|类名：Calendar;<br>方法or属性：getAccount(): CalendarAccount;|@ohos.calendarManager.d.ts|
|新增|NA|类名：CalendarAccount;<br>方法or属性：readonly name: string;|@ohos.calendarManager.d.ts|
|新增|NA|类名：CalendarAccount;<br>方法or属性：type: CalendarType;|@ohos.calendarManager.d.ts|
|新增|NA|类名：CalendarAccount;<br>方法or属性：displayName?: string|@ohos.calendarManager.d.ts|
|新增|NA|类名：CalendarConfig;<br>方法or属性：enableReminder?: boolean;|@ohos.calendarManager.d.ts|
|新增|NA|类名：CalendarConfig;<br>方法or属性：color?: (number \| string);|@ohos.calendarManager.d.ts|
|新增|NA|类名：Event;<br>方法or属性：id?: number;|@ohos.calendarManager.d.ts|
|新增|NA|类名：Event;<br>方法or属性：type: EventType;|@ohos.calendarManager.d.ts|
|新增|NA|类名：Event;<br>方法or属性：title?: string;|@ohos.calendarManager.d.ts|
|新增|NA|类名：Event;<br>方法or属性：location?: Location;|@ohos.calendarManager.d.ts|
|新增|NA|类名：Event;<br>方法or属性：startTime: number;|@ohos.calendarManager.d.ts|
|新增|NA|类名：Event;<br>方法or属性：endTime: number;|@ohos.calendarManager.d.ts|
|新增|NA|类名：Event;<br>方法or属性：isAllDay?: boolean;|@ohos.calendarManager.d.ts|
|新增|NA|类名：Event;<br>方法or属性：attendee?: Attendee[];|@ohos.calendarManager.d.ts|
|新增|NA|类名：Event;<br>方法or属性：timeZone?: string;|@ohos.calendarManager.d.ts|
|新增|NA|类名：Event;<br>方法or属性：reminderTime?: number[];|@ohos.calendarManager.d.ts|
|新增|NA|类名：Event;<br>方法or属性：recurrenceRule?: RecurrenceRule;|@ohos.calendarManager.d.ts|
|新增|NA|类名：Event;<br>方法or属性：description?: string;|@ohos.calendarManager.d.ts|
|新增|NA|类名：EventService;<br>方法or属性：description?: string;|@ohos.calendarManager.d.ts|
|新增|NA|类名：Event;<br>方法or属性：service?: EventService;|@ohos.calendarManager.d.ts|
|新增|NA|类名：CalendarType;<br>方法or属性：LOCAL = 'local'|@ohos.calendarManager.d.ts|
|新增|NA|类名：CalendarType;<br>方法or属性：EMAIL = 'email'|@ohos.calendarManager.d.ts|
|新增|NA|类名：CalendarType;<br>方法or属性：BIRTHDAY = 'birthday'|@ohos.calendarManager.d.ts|
|新增|NA|类名：CalendarType;<br>方法or属性：CALDAV = 'caldav'|@ohos.calendarManager.d.ts|
|新增|NA|类名：CalendarType;<br>方法or属性：SUBSCRIBED = 'subscribed'|@ohos.calendarManager.d.ts|
|新增|NA|类名：Location;<br>方法or属性：location?: string;|@ohos.calendarManager.d.ts|
|新增|NA|类名：Location;<br>方法or属性：longitude?: number;|@ohos.calendarManager.d.ts|
|新增|NA|类名：Location;<br>方法or属性：latitude?: number;|@ohos.calendarManager.d.ts|
|新增|NA|类名：EventFilter;<br>方法or属性：static filterById(ids: number[]): EventFilter;|@ohos.calendarManager.d.ts|
|新增|NA|类名：EventFilter;<br>方法or属性：static filterByTime(start: number, end: number): EventFilter;|@ohos.calendarManager.d.ts|
|新增|NA|类名：EventFilter;<br>方法or属性：static filterByTitle(title: string): EventFilter;|@ohos.calendarManager.d.ts|
|新增|NA|类名：EventType;<br>方法or属性：NORMAL = 0|@ohos.calendarManager.d.ts|
|新增|NA|类名：EventType;<br>方法or属性：IMPORTANT = 1|@ohos.calendarManager.d.ts|
|新增|NA|类名：RecurrenceRule;<br>方法or属性：recurrenceFrequency: RecurrenceFrequency;|@ohos.calendarManager.d.ts|
|新增|NA|类名：RecurrenceRule;<br>方法or属性：expire?: number;|@ohos.calendarManager.d.ts|
|新增|NA|类名：RecurrenceFrequency;<br>方法or属性：YEARLY = 0|@ohos.calendarManager.d.ts|
|新增|NA|类名：RecurrenceFrequency;<br>方法or属性：MONTHLY = 1|@ohos.calendarManager.d.ts|
|新增|NA|类名：RecurrenceFrequency;<br>方法or属性：WEEKLY = 2|@ohos.calendarManager.d.ts|
|新增|NA|类名：RecurrenceFrequency;<br>方法or属性：DAILY = 3|@ohos.calendarManager.d.ts|
|新增|NA|类名：Attendee;<br>方法or属性：name: string;|@ohos.calendarManager.d.ts|
|新增|NA|类名：Attendee;<br>方法or属性：email: string;|@ohos.calendarManager.d.ts|
|新增|NA|类名：EventService;<br>方法or属性：type: ServiceType;|@ohos.calendarManager.d.ts|
|新增|NA|类名：EventService;<br>方法or属性：uri: string;|@ohos.calendarManager.d.ts|
|新增|NA|类名：ServiceType;<br>方法or属性：MEETING = 'Meeting'|@ohos.calendarManager.d.ts|
|新增|NA|类名：ServiceType;<br>方法or属性：WATCHING = 'Watching'|@ohos.calendarManager.d.ts|
|新增|NA|类名：ServiceType;<br>方法or属性：REPAYMENT = 'Repayment'|@ohos.calendarManager.d.ts|
|新增|NA|类名：ServiceType;<br>方法or属性：LIVE = 'Live'|@ohos.calendarManager.d.ts|
|新增|NA|类名：ServiceType;<br>方法or属性：SHOPPING = 'Shopping'|@ohos.calendarManager.d.ts|
|新增|NA|类名：ServiceType;<br>方法or属性：TRIP = 'Trip'|@ohos.calendarManager.d.ts|
|新增|NA|类名：ServiceType;<br>方法or属性：CLASS = 'Class'|@ohos.calendarManager.d.ts|
|新增|NA|类名：ServiceType;<br>方法or属性：SPORTS_EVENTS = 'SportsEvents'|@ohos.calendarManager.d.ts|
|新增|NA|类名：ServiceType;<br>方法or属性：SPORTS_EXERCISE = 'SportsExercise'|@ohos.calendarManager.d.ts|
|新增|NA|类名：contact;<br>方法or属性：function addContact(context: Context, contact: Contact, callback: AsyncCallback\<number>): void;|@ohos.contact.d.ts|
|新增|NA|类名：contact;<br>方法or属性：function addContact(context: Context, contact: Contact): Promise\<number>;|@ohos.contact.d.ts|
|新增|NA|类名：contact;<br>方法or属性：function selectContacts(callback: AsyncCallback\<Array\<Contact>>): void;|@ohos.contact.d.ts|
|新增|NA|类名：contact;<br>方法or属性：function selectContacts(): Promise\<Array\<Contact>>;|@ohos.contact.d.ts|
|新增|NA|类名：contact;<br>方法or属性：function selectContacts(options: ContactSelectionOptions, callback: AsyncCallback\<Array\<Contact>>): void;|@ohos.contact.d.ts|
|新增|NA|类名：contact;<br>方法or属性：function selectContacts(options: ContactSelectionOptions): Promise\<Array\<Contact>>;|@ohos.contact.d.ts|
|新增|NA|类名：contact;<br>方法or属性：function deleteContact(context: Context, key: string, callback: AsyncCallback\<void>): void;|@ohos.contact.d.ts|
|新增|NA|类名：contact;<br>方法or属性：function deleteContact(context: Context, key: string): Promise\<void>;|@ohos.contact.d.ts|
|新增|NA|类名：contact;<br>方法or属性：function queryContact(context: Context, key: string, callback: AsyncCallback\<Contact>): void;|@ohos.contact.d.ts|
|新增|NA|类名：contact;<br>方法or属性：function queryContact(context: Context, key: string, holder: Holder, callback: AsyncCallback\<Contact>): void;|@ohos.contact.d.ts|
|新增|NA|类名：contact;<br>方法or属性：function queryContact(context: Context, key: string, attrs: ContactAttributes, callback: AsyncCallback\<Contact>): void;|@ohos.contact.d.ts|
|新增|NA|类名：contact;<br>方法or属性：function queryContact(context: Context, key: string, holder: Holder, attrs: ContactAttributes, callback: AsyncCallback\<Contact>): void;|@ohos.contact.d.ts|
|新增|NA|类名：contact;<br>方法or属性：function queryContact(context: Context, key: string, holder?: Holder, attrs?: ContactAttributes): Promise\<Contact>;|@ohos.contact.d.ts|
|新增|NA|类名：contact;<br>方法or属性：function queryContacts(context: Context, callback: AsyncCallback\<Array\<Contact>>): void;|@ohos.contact.d.ts|
|新增|NA|类名：contact;<br>方法or属性：function queryContacts(context: Context, holder: Holder, callback: AsyncCallback\<Array\<Contact>>): void;|@ohos.contact.d.ts|
|新增|NA|类名：contact;<br>方法or属性：function queryContacts(context: Context, attrs: ContactAttributes, callback: AsyncCallback\<Array\<Contact>>): void;|@ohos.contact.d.ts|
|新增|NA|类名：contact;<br>方法or属性：function queryContacts(context: Context, holder: Holder, attrs: ContactAttributes, callback: AsyncCallback\<Array\<Contact>>): void;|@ohos.contact.d.ts|
|新增|NA|类名：contact;<br>方法or属性：function queryContacts(context: Context, holder?: Holder, attrs?: ContactAttributes): Promise\<Array\<Contact>>;|@ohos.contact.d.ts|
|新增|NA|类名：contact;<br>方法or属性：function queryContactsByEmail(context: Context, email: string, callback: AsyncCallback\<Array\<Contact>>): void;|@ohos.contact.d.ts|
|新增|NA|类名：contact;<br>方法or属性：function queryContactsByEmail(context: Context, email: string, holder: Holder,<br>    callback: AsyncCallback\<Array\<Contact>>): void;|@ohos.contact.d.ts|
|新增|NA|类名：contact;<br>方法or属性：function queryContactsByEmail(context: Context, email: string, attrs: ContactAttributes,<br>    callback: AsyncCallback\<Array\<Contact>>): void;|@ohos.contact.d.ts|
|新增|NA|类名：contact;<br>方法or属性：function queryContactsByEmail(context: Context, email: string, holder: Holder, attrs: ContactAttributes, callback: AsyncCallback\<Array\<Contact>>): void;|@ohos.contact.d.ts|
|新增|NA|类名：contact;<br>方法or属性：function queryContactsByEmail(context: Context, email: string, holder?: Holder, attrs?: ContactAttributes): Promise\<Array\<Contact>>;|@ohos.contact.d.ts|
|新增|NA|类名：contact;<br>方法or属性：function queryContactsByPhoneNumber(context: Context, phoneNumber: string, callback: AsyncCallback\<Array\<Contact>>): void;|@ohos.contact.d.ts|
|新增|NA|类名：contact;<br>方法or属性：function queryContactsByPhoneNumber(context: Context, phoneNumber: string, holder: Holder, callback: AsyncCallback\<Array\<Contact>>): void;|@ohos.contact.d.ts|
|新增|NA|类名：contact;<br>方法or属性：function queryContactsByPhoneNumber(context: Context, phoneNumber: string, attrs: ContactAttributes, callback: AsyncCallback\<Array\<Contact>>): void;|@ohos.contact.d.ts|
|新增|NA|类名：contact;<br>方法or属性：function queryContactsByPhoneNumber(context: Context, phoneNumber: string, holder: Holder, attrs: ContactAttributes,<br>    callback: AsyncCallback\<Array\<Contact>>): void;|@ohos.contact.d.ts|
|新增|NA|类名：contact;<br>方法or属性：function queryContactsByPhoneNumber(context: Context, phoneNumber: string, holder?: Holder, attrs?: ContactAttributes): Promise\<Array\<Contact>>;|@ohos.contact.d.ts|
|新增|NA|类名：contact;<br>方法or属性：function queryGroups(context: Context, callback: AsyncCallback\<Array\<Group>>): void;|@ohos.contact.d.ts|
|新增|NA|类名：contact;<br>方法or属性：function queryGroups(context: Context, holder: Holder, callback: AsyncCallback\<Array\<Group>>): void;|@ohos.contact.d.ts|
|新增|NA|类名：contact;<br>方法or属性：function queryGroups(context: Context, holder?: Holder): Promise\<Array\<Group>>;|@ohos.contact.d.ts|
|新增|NA|类名：contact;<br>方法or属性：function queryHolders(context: Context, callback: AsyncCallback\<Array\<Holder>>): void;|@ohos.contact.d.ts|
|新增|NA|类名：contact;<br>方法or属性：function queryHolders(context: Context): Promise\<Array\<Holder>>;|@ohos.contact.d.ts|
|新增|NA|类名：contact;<br>方法or属性：function queryKey(context: Context, id: number, callback: AsyncCallback\<string>): void;|@ohos.contact.d.ts|
|新增|NA|类名：contact;<br>方法or属性：function queryKey(context: Context, id: number, holder: Holder, callback: AsyncCallback\<string>): void;|@ohos.contact.d.ts|
|新增|NA|类名：contact;<br>方法or属性：function queryKey(context: Context, id: number, holder?: Holder): Promise\<string>;|@ohos.contact.d.ts|
|新增|NA|类名：contact;<br>方法or属性：function queryMyCard(context: Context, callback: AsyncCallback\<Contact>): void;|@ohos.contact.d.ts|
|新增|NA|类名：contact;<br>方法or属性：function queryMyCard(context: Context, attrs: ContactAttributes, callback: AsyncCallback\<Contact>): void;|@ohos.contact.d.ts|
|新增|NA|类名：contact;<br>方法or属性：function queryMyCard(context: Context, attrs?: ContactAttributes): Promise\<Contact>;|@ohos.contact.d.ts|
|新增|NA|类名：contact;<br>方法or属性：function updateContact(context: Context, contact: Contact, callback: AsyncCallback\<void>): void;|@ohos.contact.d.ts|
|新增|NA|类名：contact;<br>方法or属性：function updateContact(context: Context, contact: Contact, attrs: ContactAttributes, callback: AsyncCallback\<void>): void;|@ohos.contact.d.ts|
|新增|NA|类名：contact;<br>方法or属性：function updateContact(context: Context, contact: Contact, attrs?: ContactAttributes): Promise\<void>;|@ohos.contact.d.ts|
|新增|NA|类名：contact;<br>方法or属性：function isLocalContact(context: Context, id: number, callback: AsyncCallback\<boolean>): void;|@ohos.contact.d.ts|
|新增|NA|类名：contact;<br>方法or属性：function isLocalContact(context: Context, id: number): Promise\<boolean>;|@ohos.contact.d.ts|
|新增|NA|类名：contact;<br>方法or属性：function isMyCard(context: Context, id: number, callback: AsyncCallback\<boolean>): void;|@ohos.contact.d.ts|
|新增|NA|类名：contact;<br>方法or属性：function isMyCard(context: Context, id: number): Promise\<boolean>;|@ohos.contact.d.ts|
|新增|NA|类名：ContactSelectionOptions;<br>方法or属性：isMultiSelect?: boolean;|@ohos.contact.d.ts|
|废弃版本有变化|类名：contact;<br>方法or属性：function addContact(contact: Contact, callback: AsyncCallback\<number>): void;<br>旧版本信息：|类名：contact;<br>方法or属性：function addContact(contact: Contact, callback: AsyncCallback\<number>): void;<br>新版本信息：10<br>代替接口： contact.addContact#addContact|@ohos.contact.d.ts|
|废弃版本有变化|类名：contact;<br>方法or属性：function addContact(contact: Contact): Promise\<number>;<br>旧版本信息：|类名：contact;<br>方法or属性：function addContact(contact: Contact): Promise\<number>;<br>新版本信息：10<br>代替接口： contact.addContact#addContact|@ohos.contact.d.ts|
|废弃版本有变化|类名：contact;<br>方法or属性：function selectContact(callback: AsyncCallback\<Array\<Contact>>): void;<br>旧版本信息：|类名：contact;<br>方法or属性：function selectContact(callback: AsyncCallback\<Array\<Contact>>): void;<br>新版本信息：10<br>代替接口： contact.selectContact#selectContacts|@ohos.contact.d.ts|
|废弃版本有变化|类名：contact;<br>方法or属性：function selectContact(): Promise\<Array\<Contact>>;<br>旧版本信息：|类名：contact;<br>方法or属性：function selectContact(): Promise\<Array\<Contact>>;<br>新版本信息：10<br>代替接口： contact.selectContact#selectContacts|@ohos.contact.d.ts|
|废弃版本有变化|类名：contact;<br>方法or属性：function deleteContact(key: string, callback: AsyncCallback\<void>): void;<br>旧版本信息：|类名：contact;<br>方法or属性：function deleteContact(key: string, callback: AsyncCallback\<void>): void;<br>新版本信息：10<br>代替接口： contact.deleteContact#deleteContact|@ohos.contact.d.ts|
|废弃版本有变化|类名：contact;<br>方法or属性：function deleteContact(key: string): Promise\<void>;<br>旧版本信息：|类名：contact;<br>方法or属性：function deleteContact(key: string): Promise\<void>;<br>新版本信息：10<br>代替接口： contact.deleteContact#deleteContact|@ohos.contact.d.ts|
|废弃版本有变化|类名：contact;<br>方法or属性：function queryContact(key: string, callback: AsyncCallback\<Contact>): void;<br>旧版本信息：|类名：contact;<br>方法or属性：function queryContact(key: string, callback: AsyncCallback\<Contact>): void;<br>新版本信息：10<br>代替接口： contact.queryContact#queryContact|@ohos.contact.d.ts|
|废弃版本有变化|类名：contact;<br>方法or属性：function queryContact(key: string, holder: Holder, callback: AsyncCallback\<Contact>): void;<br>旧版本信息：|类名：contact;<br>方法or属性：function queryContact(key: string, holder: Holder, callback: AsyncCallback\<Contact>): void;<br>新版本信息：10<br>代替接口： contact.queryContact#queryContact|@ohos.contact.d.ts|
|废弃版本有变化|类名：contact;<br>方法or属性：function queryContact(key: string, attrs: ContactAttributes, callback: AsyncCallback\<Contact>): void;<br>旧版本信息：|类名：contact;<br>方法or属性：function queryContact(key: string, attrs: ContactAttributes, callback: AsyncCallback\<Contact>): void;<br>新版本信息：10<br>代替接口： contact.queryContact#queryContact|@ohos.contact.d.ts|
|废弃版本有变化|类名：contact;<br>方法or属性：function queryContact(key: string, holder: Holder, attrs: ContactAttributes, callback: AsyncCallback\<Contact>): void;<br>旧版本信息：|类名：contact;<br>方法or属性：function queryContact(key: string, holder: Holder, attrs: ContactAttributes, callback: AsyncCallback\<Contact>): void;<br>新版本信息：10<br>代替接口： contact.queryContact#queryContact|@ohos.contact.d.ts|
|废弃版本有变化|类名：contact;<br>方法or属性：function queryContact(key: string, holder?: Holder, attrs?: ContactAttributes): Promise\<Contact>;<br>旧版本信息：|类名：contact;<br>方法or属性：function queryContact(key: string, holder?: Holder, attrs?: ContactAttributes): Promise\<Contact>;<br>新版本信息：10<br>代替接口： contact.queryContact#queryContact|@ohos.contact.d.ts|
|废弃版本有变化|类名：contact;<br>方法or属性：function queryContacts(callback: AsyncCallback\<Array\<Contact>>): void;<br>旧版本信息：|类名：contact;<br>方法or属性：function queryContacts(callback: AsyncCallback\<Array\<Contact>>): void;<br>新版本信息：10<br>代替接口： contact.queryContacts#queryContacts|@ohos.contact.d.ts|
|废弃版本有变化|类名：contact;<br>方法or属性：function queryContacts(holder: Holder, callback: AsyncCallback\<Array\<Contact>>): void;<br>旧版本信息：|类名：contact;<br>方法or属性：function queryContacts(holder: Holder, callback: AsyncCallback\<Array\<Contact>>): void;<br>新版本信息：10<br>代替接口： contact.queryContacts#queryContacts|@ohos.contact.d.ts|
|废弃版本有变化|类名：contact;<br>方法or属性：function queryContacts(attrs: ContactAttributes, callback: AsyncCallback\<Array\<Contact>>): void;<br>旧版本信息：|类名：contact;<br>方法or属性：function queryContacts(attrs: ContactAttributes, callback: AsyncCallback\<Array\<Contact>>): void;<br>新版本信息：10<br>代替接口： contact.queryContacts#queryContacts|@ohos.contact.d.ts|
|废弃版本有变化|类名：contact;<br>方法or属性：function queryContacts(holder: Holder, attrs: ContactAttributes, callback: AsyncCallback\<Array\<Contact>>): void;<br>旧版本信息：|类名：contact;<br>方法or属性：function queryContacts(holder: Holder, attrs: ContactAttributes, callback: AsyncCallback\<Array\<Contact>>): void;<br>新版本信息：10<br>代替接口： contact.queryContacts#queryContacts|@ohos.contact.d.ts|
|废弃版本有变化|类名：contact;<br>方法or属性：function queryContacts(holder?: Holder, attrs?: ContactAttributes): Promise\<Array\<Contact>>;<br>旧版本信息：|类名：contact;<br>方法or属性：function queryContacts(holder?: Holder, attrs?: ContactAttributes): Promise\<Array\<Contact>>;<br>新版本信息：10<br>代替接口： contact.queryContacts#queryContacts|@ohos.contact.d.ts|
|废弃版本有变化|类名：contact;<br>方法or属性：function queryContactsByEmail(email: string, callback: AsyncCallback\<Array\<Contact>>): void;<br>旧版本信息：|类名：contact;<br>方法or属性：function queryContactsByEmail(email: string, callback: AsyncCallback\<Array\<Contact>>): void;<br>新版本信息：10<br>代替接口： contact.queryContactsByEmail#queryContactsByEmail|@ohos.contact.d.ts|
|废弃版本有变化|类名：contact;<br>方法or属性：function queryContactsByEmail(email: string, holder: Holder, callback: AsyncCallback\<Array\<Contact>>): void;<br>旧版本信息：|类名：contact;<br>方法or属性：function queryContactsByEmail(email: string, holder: Holder, callback: AsyncCallback\<Array\<Contact>>): void;<br>新版本信息：10<br>代替接口： contact.queryContactsByEmail#queryContactsByEmail|@ohos.contact.d.ts|
|废弃版本有变化|类名：contact;<br>方法or属性：function queryContactsByEmail(email: string, attrs: ContactAttributes, callback: AsyncCallback\<Array\<Contact>>): void;<br>旧版本信息：|类名：contact;<br>方法or属性：function queryContactsByEmail(email: string, attrs: ContactAttributes, callback: AsyncCallback\<Array\<Contact>>): void;<br>新版本信息：10<br>代替接口： contact.queryContactsByEmail#queryContactsByEmail|@ohos.contact.d.ts|
|废弃版本有变化|类名：contact;<br>方法or属性：function queryContactsByEmail(email: string, holder: Holder, attrs: ContactAttributes, callback: AsyncCallback\<Array\<Contact>>): void;<br>旧版本信息：|类名：contact;<br>方法or属性：function queryContactsByEmail(email: string, holder: Holder, attrs: ContactAttributes, callback: AsyncCallback\<Array\<Contact>>): void;<br>新版本信息：10<br>代替接口： contact.queryContactsByEmail#queryContactsByEmail|@ohos.contact.d.ts|
|废弃版本有变化|类名：contact;<br>方法or属性：function queryContactsByEmail(email: string, holder?: Holder, attrs?: ContactAttributes): Promise\<Array\<Contact>>;<br>旧版本信息：|类名：contact;<br>方法or属性：function queryContactsByEmail(email: string, holder?: Holder, attrs?: ContactAttributes): Promise\<Array\<Contact>>;<br>新版本信息：10<br>代替接口： contact.queryContactsByEmail#queryContactsByEmail|@ohos.contact.d.ts|
|废弃版本有变化|类名：contact;<br>方法or属性：function queryContactsByPhoneNumber(phoneNumber: string, callback: AsyncCallback\<Array\<Contact>>): void;<br>旧版本信息：|类名：contact;<br>方法or属性：function queryContactsByPhoneNumber(phoneNumber: string, callback: AsyncCallback\<Array\<Contact>>): void;<br>新版本信息：10<br>代替接口： contact.queryContactsByPhoneNumber#queryContactsByPhoneNumber|@ohos.contact.d.ts|
|废弃版本有变化|类名：contact;<br>方法or属性：function queryContactsByPhoneNumber(phoneNumber: string, holder: Holder, callback: AsyncCallback\<Array\<Contact>>): void;<br>旧版本信息：|类名：contact;<br>方法or属性：function queryContactsByPhoneNumber(phoneNumber: string, holder: Holder, callback: AsyncCallback\<Array\<Contact>>): void;<br>新版本信息：10<br>代替接口： contact.queryContactsByPhoneNumber#queryContactsByPhoneNumber|@ohos.contact.d.ts|
|废弃版本有变化|类名：contact;<br>方法or属性：function queryContactsByPhoneNumber(phoneNumber: string, attrs: ContactAttributes, callback: AsyncCallback\<Array\<Contact>>): void;<br>旧版本信息：|类名：contact;<br>方法or属性：function queryContactsByPhoneNumber(phoneNumber: string, attrs: ContactAttributes, callback: AsyncCallback\<Array\<Contact>>): void;<br>新版本信息：10<br>代替接口： contact.queryContactsByPhoneNumber#queryContactsByPhoneNumber|@ohos.contact.d.ts|
|废弃版本有变化|类名：contact;<br>方法or属性：function queryContactsByPhoneNumber(phoneNumber: string, holder: Holder, attrs: ContactAttributes, callback: AsyncCallback\<Array\<Contact>>): void;<br>旧版本信息：|类名：contact;<br>方法or属性：function queryContactsByPhoneNumber(phoneNumber: string, holder: Holder, attrs: ContactAttributes, callback: AsyncCallback\<Array\<Contact>>): void;<br>新版本信息：10<br>代替接口： contact.queryContactsByPhoneNumber#queryContactsByPhoneNumber|@ohos.contact.d.ts|
|废弃版本有变化|类名：contact;<br>方法or属性：function queryContactsByPhoneNumber(phoneNumber: string, holder?: Holder, attrs?: ContactAttributes): Promise\<Array\<Contact>>;<br>旧版本信息：|类名：contact;<br>方法or属性：function queryContactsByPhoneNumber(phoneNumber: string, holder?: Holder, attrs?: ContactAttributes): Promise\<Array\<Contact>>;<br>新版本信息：10<br>代替接口： contact.queryContactsByPhoneNumber#queryContactsByPhoneNumber|@ohos.contact.d.ts|
|废弃版本有变化|类名：contact;<br>方法or属性：function queryGroups(callback: AsyncCallback\<Array\<Group>>): void;<br>旧版本信息：|类名：contact;<br>方法or属性：function queryGroups(callback: AsyncCallback\<Array\<Group>>): void;<br>新版本信息：10<br>代替接口： contact.queryGroups#queryGroups|@ohos.contact.d.ts|
|废弃版本有变化|类名：contact;<br>方法or属性：function queryGroups(holder: Holder, callback: AsyncCallback\<Array\<Group>>): void;<br>旧版本信息：|类名：contact;<br>方法or属性：function queryGroups(holder: Holder, callback: AsyncCallback\<Array\<Group>>): void;<br>新版本信息：10<br>代替接口： contact.queryGroups#queryGroups|@ohos.contact.d.ts|
|废弃版本有变化|类名：contact;<br>方法or属性：function queryGroups(holder?: Holder): Promise\<Array\<Group>>;<br>旧版本信息：|类名：contact;<br>方法or属性：function queryGroups(holder?: Holder): Promise\<Array\<Group>>;<br>新版本信息：10<br>代替接口： contact.queryGroups#queryGroups|@ohos.contact.d.ts|
|废弃版本有变化|类名：contact;<br>方法or属性：function queryHolders(callback: AsyncCallback\<Array\<Holder>>): void;<br>旧版本信息：|类名：contact;<br>方法or属性：function queryHolders(callback: AsyncCallback\<Array\<Holder>>): void;<br>新版本信息：10<br>代替接口： contact.queryHolders#queryHolders|@ohos.contact.d.ts|
|废弃版本有变化|类名：contact;<br>方法or属性：function queryHolders(): Promise\<Array\<Holder>>;<br>旧版本信息：|类名：contact;<br>方法or属性：function queryHolders(): Promise\<Array\<Holder>>;<br>新版本信息：10<br>代替接口： contact.queryHolders#queryHolders|@ohos.contact.d.ts|
|废弃版本有变化|类名：contact;<br>方法or属性：function queryKey(id: number, callback: AsyncCallback\<string>): void;<br>旧版本信息：|类名：contact;<br>方法or属性：function queryKey(id: number, callback: AsyncCallback\<string>): void;<br>新版本信息：10<br>代替接口： contact.queryKey#queryKey|@ohos.contact.d.ts|
|废弃版本有变化|类名：contact;<br>方法or属性：function queryKey(id: number, holder: Holder, callback: AsyncCallback\<string>): void;<br>旧版本信息：|类名：contact;<br>方法or属性：function queryKey(id: number, holder: Holder, callback: AsyncCallback\<string>): void;<br>新版本信息：10<br>代替接口： contact.queryKey#queryKey|@ohos.contact.d.ts|
|废弃版本有变化|类名：contact;<br>方法or属性：function queryKey(id: number, holder?: Holder): Promise\<string>;<br>旧版本信息：|类名：contact;<br>方法or属性：function queryKey(id: number, holder?: Holder): Promise\<string>;<br>新版本信息：10<br>代替接口： contact.queryKey#queryKey|@ohos.contact.d.ts|
|废弃版本有变化|类名：contact;<br>方法or属性：function queryMyCard(callback: AsyncCallback\<Contact>): void;<br>旧版本信息：|类名：contact;<br>方法or属性：function queryMyCard(callback: AsyncCallback\<Contact>): void;<br>新版本信息：10<br>代替接口： contact.queryMyCard#queryMyCard|@ohos.contact.d.ts|
|废弃版本有变化|类名：contact;<br>方法or属性：function queryMyCard(attrs: ContactAttributes, callback: AsyncCallback\<Contact>): void;<br>旧版本信息：|类名：contact;<br>方法or属性：function queryMyCard(attrs: ContactAttributes, callback: AsyncCallback\<Contact>): void;<br>新版本信息：10<br>代替接口： contact.queryMyCard#queryMyCard|@ohos.contact.d.ts|
|废弃版本有变化|类名：contact;<br>方法or属性：function queryMyCard(attrs?: ContactAttributes): Promise\<Contact>;<br>旧版本信息：|类名：contact;<br>方法or属性：function queryMyCard(attrs?: ContactAttributes): Promise\<Contact>;<br>新版本信息：10<br>代替接口： contact.queryMyCard#queryMyCard|@ohos.contact.d.ts|
|废弃版本有变化|类名：contact;<br>方法or属性：function updateContact(contact: Contact, callback: AsyncCallback\<void>): void;<br>旧版本信息：|类名：contact;<br>方法or属性：function updateContact(contact: Contact, callback: AsyncCallback\<void>): void;<br>新版本信息：10<br>代替接口： contact.updateContact#updateContact|@ohos.contact.d.ts|
|废弃版本有变化|类名：contact;<br>方法or属性：function updateContact(contact: Contact, attrs: ContactAttributes, callback: AsyncCallback\<void>): void;<br>旧版本信息：|类名：contact;<br>方法or属性：function updateContact(contact: Contact, attrs: ContactAttributes, callback: AsyncCallback\<void>): void;<br>新版本信息：10<br>代替接口： contact.updateContact#updateContact|@ohos.contact.d.ts|
|废弃版本有变化|类名：contact;<br>方法or属性：function updateContact(contact: Contact, attrs?: ContactAttributes): Promise\<void>;<br>旧版本信息：|类名：contact;<br>方法or属性：function updateContact(contact: Contact, attrs?: ContactAttributes): Promise\<void>;<br>新版本信息：10<br>代替接口： contact.updateContact#updateContact|@ohos.contact.d.ts|
|废弃版本有变化|类名：contact;<br>方法or属性：function isLocalContact(id: number, callback: AsyncCallback\<boolean>): void;<br>旧版本信息：|类名：contact;<br>方法or属性：function isLocalContact(id: number, callback: AsyncCallback\<boolean>): void;<br>新版本信息：10<br>代替接口： contact.isLocalContact#isLocalContact|@ohos.contact.d.ts|
|废弃版本有变化|类名：contact;<br>方法or属性：function isLocalContact(id: number): Promise\<boolean>;<br>旧版本信息：|类名：contact;<br>方法or属性：function isLocalContact(id: number): Promise\<boolean>;<br>新版本信息：10<br>代替接口： contact.isLocalContact#isLocalContact|@ohos.contact.d.ts|
|废弃版本有变化|类名：contact;<br>方法or属性：function isMyCard(id: number, callback: AsyncCallback\<boolean>): void;<br>旧版本信息：|类名：contact;<br>方法or属性：function isMyCard(id: number, callback: AsyncCallback\<boolean>): void;<br>新版本信息：10<br>代替接口： contact.deleteContact#deleteContact|@ohos.contact.d.ts|
|废弃版本有变化|类名：contact;<br>方法or属性：function isMyCard(id: number): Promise\<boolean>;<br>旧版本信息：|类名：contact;<br>方法or属性：function isMyCard(id: number): Promise\<boolean>;<br>新版本信息：10<br>代替接口： contact.isMyCard#isMyCard|@ohos.contact.d.ts|
|权限有变化|类名：contact;<br>方法or属性：function addContact(contact: Contact): Promise\<number>;<br>旧版本信息：|类名：contact;<br>方法or属性：function addContact(contact: Contact): Promise\<number>;<br>新版本信息：ohos.permission.WRITE_CONTACTS|@ohos.contact.d.ts|
|权限有变化|类名：contact;<br>方法or属性：function selectContact(): Promise\<Array\<Contact>>;<br>旧版本信息：|类名：contact;<br>方法or属性：function selectContact(): Promise\<Array\<Contact>>;<br>新版本信息：ohos.permission.READ_CONTACTS|@ohos.contact.d.ts|
|权限有变化|类名：contact;<br>方法or属性：function deleteContact(key: string): Promise\<void>;<br>旧版本信息：|类名：contact;<br>方法or属性：function deleteContact(key: string): Promise\<void>;<br>新版本信息：ohos.permission.WRITE_CONTACTS|@ohos.contact.d.ts|
|权限有变化|类名：contact;<br>方法or属性：function queryContact(key: string, holder: Holder, callback: AsyncCallback\<Contact>): void;<br>旧版本信息：|类名：contact;<br>方法or属性：function queryContact(key: string, holder: Holder, callback: AsyncCallback\<Contact>): void;<br>新版本信息：ohos.permission.READ_CONTACTS|@ohos.contact.d.ts|
|权限有变化|类名：contact;<br>方法or属性：function queryContact(key: string, attrs: ContactAttributes, callback: AsyncCallback\<Contact>): void;<br>旧版本信息：|类名：contact;<br>方法or属性：function queryContact(key: string, attrs: ContactAttributes, callback: AsyncCallback\<Contact>): void;<br>新版本信息：ohos.permission.READ_CONTACTS|@ohos.contact.d.ts|
|权限有变化|类名：contact;<br>方法or属性：function queryContact(key: string, holder: Holder, attrs: ContactAttributes, callback: AsyncCallback\<Contact>): void;<br>旧版本信息：|类名：contact;<br>方法or属性：function queryContact(key: string, holder: Holder, attrs: ContactAttributes, callback: AsyncCallback\<Contact>): void;<br>新版本信息：ohos.permission.READ_CONTACTS|@ohos.contact.d.ts|
|权限有变化|类名：contact;<br>方法or属性：function queryContact(key: string, holder?: Holder, attrs?: ContactAttributes): Promise\<Contact>;<br>旧版本信息：|类名：contact;<br>方法or属性：function queryContact(key: string, holder?: Holder, attrs?: ContactAttributes): Promise\<Contact>;<br>新版本信息：ohos.permission.READ_CONTACTS|@ohos.contact.d.ts|
|权限有变化|类名：contact;<br>方法or属性：function queryContacts(holder: Holder, callback: AsyncCallback\<Array\<Contact>>): void;<br>旧版本信息：|类名：contact;<br>方法or属性：function queryContacts(holder: Holder, callback: AsyncCallback\<Array\<Contact>>): void;<br>新版本信息：ohos.permission.READ_CONTACTS|@ohos.contact.d.ts|
|权限有变化|类名：contact;<br>方法or属性：function queryContacts(attrs: ContactAttributes, callback: AsyncCallback\<Array\<Contact>>): void;<br>旧版本信息：|类名：contact;<br>方法or属性：function queryContacts(attrs: ContactAttributes, callback: AsyncCallback\<Array\<Contact>>): void;<br>新版本信息：ohos.permission.READ_CONTACTS|@ohos.contact.d.ts|
|权限有变化|类名：contact;<br>方法or属性：function queryContacts(holder: Holder, attrs: ContactAttributes, callback: AsyncCallback\<Array\<Contact>>): void;<br>旧版本信息：|类名：contact;<br>方法or属性：function queryContacts(holder: Holder, attrs: ContactAttributes, callback: AsyncCallback\<Array\<Contact>>): void;<br>新版本信息：ohos.permission.READ_CONTACTS|@ohos.contact.d.ts|
|权限有变化|类名：contact;<br>方法or属性：function queryContacts(holder?: Holder, attrs?: ContactAttributes): Promise\<Array\<Contact>>;<br>旧版本信息：|类名：contact;<br>方法or属性：function queryContacts(holder?: Holder, attrs?: ContactAttributes): Promise\<Array\<Contact>>;<br>新版本信息：ohos.permission.READ_CONTACTS|@ohos.contact.d.ts|
|权限有变化|类名：contact;<br>方法or属性：function queryContactsByEmail(email: string, holder: Holder, callback: AsyncCallback\<Array\<Contact>>): void;<br>旧版本信息：|类名：contact;<br>方法or属性：function queryContactsByEmail(email: string, holder: Holder, callback: AsyncCallback\<Array\<Contact>>): void;<br>新版本信息：ohos.permission.READ_CONTACTS|@ohos.contact.d.ts|
|权限有变化|类名：contact;<br>方法or属性：function queryContactsByEmail(email: string, attrs: ContactAttributes, callback: AsyncCallback\<Array\<Contact>>): void;<br>旧版本信息：|类名：contact;<br>方法or属性：function queryContactsByEmail(email: string, attrs: ContactAttributes, callback: AsyncCallback\<Array\<Contact>>): void;<br>新版本信息：ohos.permission.READ_CONTACTS|@ohos.contact.d.ts|
|权限有变化|类名：contact;<br>方法or属性：function queryContactsByEmail(email: string, holder: Holder, attrs: ContactAttributes, callback: AsyncCallback\<Array\<Contact>>): void;<br>旧版本信息：|类名：contact;<br>方法or属性：function queryContactsByEmail(email: string, holder: Holder, attrs: ContactAttributes, callback: AsyncCallback\<Array\<Contact>>): void;<br>新版本信息：ohos.permission.READ_CONTACTS|@ohos.contact.d.ts|
|权限有变化|类名：contact;<br>方法or属性：function queryContactsByEmail(email: string, holder?: Holder, attrs?: ContactAttributes): Promise\<Array\<Contact>>;<br>旧版本信息：|类名：contact;<br>方法or属性：function queryContactsByEmail(email: string, holder?: Holder, attrs?: ContactAttributes): Promise\<Array\<Contact>>;<br>新版本信息：ohos.permission.READ_CONTACTS|@ohos.contact.d.ts|
|权限有变化|类名：contact;<br>方法or属性：function queryContactsByPhoneNumber(phoneNumber: string, holder: Holder, callback: AsyncCallback\<Array\<Contact>>): void;<br>旧版本信息：|类名：contact;<br>方法or属性：function queryContactsByPhoneNumber(phoneNumber: string, holder: Holder, callback: AsyncCallback\<Array\<Contact>>): void;<br>新版本信息：ohos.permission.READ_CONTACTS|@ohos.contact.d.ts|
|权限有变化|类名：contact;<br>方法or属性：function queryContactsByPhoneNumber(phoneNumber: string, attrs: ContactAttributes, callback: AsyncCallback\<Array\<Contact>>): void;<br>旧版本信息：|类名：contact;<br>方法or属性：function queryContactsByPhoneNumber(phoneNumber: string, attrs: ContactAttributes, callback: AsyncCallback\<Array\<Contact>>): void;<br>新版本信息：ohos.permission.READ_CONTACTS|@ohos.contact.d.ts|
|权限有变化|类名：contact;<br>方法or属性：function queryContactsByPhoneNumber(phoneNumber: string, holder: Holder, attrs: ContactAttributes, callback: AsyncCallback\<Array\<Contact>>): void;<br>旧版本信息：|类名：contact;<br>方法or属性：function queryContactsByPhoneNumber(phoneNumber: string, holder: Holder, attrs: ContactAttributes, callback: AsyncCallback\<Array\<Contact>>): void;<br>新版本信息：ohos.permission.READ_CONTACTS|@ohos.contact.d.ts|
|权限有变化|类名：contact;<br>方法or属性：function queryContactsByPhoneNumber(phoneNumber: string, holder?: Holder, attrs?: ContactAttributes): Promise\<Array\<Contact>>;<br>旧版本信息：|类名：contact;<br>方法or属性：function queryContactsByPhoneNumber(phoneNumber: string, holder?: Holder, attrs?: ContactAttributes): Promise\<Array\<Contact>>;<br>新版本信息：ohos.permission.READ_CONTACTS|@ohos.contact.d.ts|
|权限有变化|类名：contact;<br>方法or属性：function queryGroups(holder: Holder, callback: AsyncCallback\<Array\<Group>>): void;<br>旧版本信息：|类名：contact;<br>方法or属性：function queryGroups(holder: Holder, callback: AsyncCallback\<Array\<Group>>): void;<br>新版本信息：ohos.permission.READ_CONTACTS|@ohos.contact.d.ts|
|权限有变化|类名：contact;<br>方法or属性：function queryGroups(holder?: Holder): Promise\<Array\<Group>>;<br>旧版本信息：|类名：contact;<br>方法or属性：function queryGroups(holder?: Holder): Promise\<Array\<Group>>;<br>新版本信息：ohos.permission.READ_CONTACTS|@ohos.contact.d.ts|
|权限有变化|类名：contact;<br>方法or属性：function queryHolders(): Promise\<Array\<Holder>>;<br>旧版本信息：|类名：contact;<br>方法or属性：function queryHolders(): Promise\<Array\<Holder>>;<br>新版本信息：ohos.permission.READ_CONTACTS|@ohos.contact.d.ts|
|权限有变化|类名：contact;<br>方法or属性：function queryKey(id: number, holder: Holder, callback: AsyncCallback\<string>): void;<br>旧版本信息：|类名：contact;<br>方法or属性：function queryKey(id: number, holder: Holder, callback: AsyncCallback\<string>): void;<br>新版本信息：ohos.permission.READ_CONTACTS|@ohos.contact.d.ts|
|权限有变化|类名：contact;<br>方法or属性：function queryKey(id: number, holder?: Holder): Promise\<string>;<br>旧版本信息：|类名：contact;<br>方法or属性：function queryKey(id: number, holder?: Holder): Promise\<string>;<br>新版本信息：ohos.permission.READ_CONTACTS|@ohos.contact.d.ts|
|权限有变化|类名：contact;<br>方法or属性：function queryMyCard(attrs: ContactAttributes, callback: AsyncCallback\<Contact>): void;<br>旧版本信息：|类名：contact;<br>方法or属性：function queryMyCard(attrs: ContactAttributes, callback: AsyncCallback\<Contact>): void;<br>新版本信息：ohos.permission.READ_CONTACTS|@ohos.contact.d.ts|
|权限有变化|类名：contact;<br>方法or属性：function queryMyCard(attrs?: ContactAttributes): Promise\<Contact>;<br>旧版本信息：|类名：contact;<br>方法or属性：function queryMyCard(attrs?: ContactAttributes): Promise\<Contact>;<br>新版本信息：ohos.permission.READ_CONTACTS|@ohos.contact.d.ts|
|权限有变化|类名：contact;<br>方法or属性：function updateContact(contact: Contact, attrs: ContactAttributes, callback: AsyncCallback\<void>): void;<br>旧版本信息：|类名：contact;<br>方法or属性：function updateContact(contact: Contact, attrs: ContactAttributes, callback: AsyncCallback\<void>): void;<br>新版本信息：ohos.permission.WRITE_CONTACTS|@ohos.contact.d.ts|
|权限有变化|类名：contact;<br>方法or属性：function updateContact(contact: Contact, attrs?: ContactAttributes): Promise\<void>;<br>旧版本信息：|类名：contact;<br>方法or属性：function updateContact(contact: Contact, attrs?: ContactAttributes): Promise\<void>;<br>新版本信息：ohos.permission.WRITE_CONTACTS|@ohos.contact.d.ts|
|权限有变化|类名：contact;<br>方法or属性：function isLocalContact(id: number): Promise\<boolean>;<br>旧版本信息：|类名：contact;<br>方法or属性：function isLocalContact(id: number): Promise\<boolean>;<br>新版本信息：ohos.permission.READ_CONTACTS|@ohos.contact.d.ts|
|权限有变化|类名：contact;<br>方法or属性：function isMyCard(id: number): Promise\<boolean>;<br>旧版本信息：|类名：contact;<br>方法or属性：function isMyCard(id: number): Promise\<boolean>;<br>新版本信息：ohos.permission.READ_CONTACTS|@ohos.contact.d.ts|
|type有变化|类名：Contact;<br>方法or属性：readonly id?: number<br>旧版本信息：|类名：Contact;<br>方法or属性：readonly id?: number<br>新版本信息：?number|@ohos.contact.d.ts|
|type有变化|类名：Contact;<br>方法or属性：readonly key?: string<br>旧版本信息：|类名：Contact;<br>方法or属性：readonly key?: string<br>新版本信息：?string|@ohos.contact.d.ts|
|type有变化|类名：Contact;<br>方法or属性：contactAttributes?: ContactAttributes<br>旧版本信息：|类名：Contact;<br>方法or属性：contactAttributes?: ContactAttributes<br>新版本信息：?ContactAttributes|@ohos.contact.d.ts|
|type有变化|类名：Contact;<br>方法or属性：emails?: Email[]<br>旧版本信息：|类名：Contact;<br>方法or属性：emails?: Email[]<br>新版本信息：?Email[]|@ohos.contact.d.ts|
|type有变化|类名：Contact;<br>方法or属性：events?: Event[]<br>旧版本信息：|类名：Contact;<br>方法or属性：events?: Event[]<br>新版本信息：?Event[]|@ohos.contact.d.ts|
|type有变化|类名：Contact;<br>方法or属性：groups?: Group[]<br>旧版本信息：|类名：Contact;<br>方法or属性：groups?: Group[]<br>新版本信息：?Group[]|@ohos.contact.d.ts|
|type有变化|类名：Contact;<br>方法or属性：imAddresses?: ImAddress[]<br>旧版本信息：|类名：Contact;<br>方法or属性：imAddresses?: ImAddress[]<br>新版本信息：?ImAddress[]|@ohos.contact.d.ts|
|type有变化|类名：Contact;<br>方法or属性：phoneNumbers?: PhoneNumber[]<br>旧版本信息：|类名：Contact;<br>方法or属性：phoneNumbers?: PhoneNumber[]<br>新版本信息：?PhoneNumber[]|@ohos.contact.d.ts|
|type有变化|类名：Contact;<br>方法or属性：portrait?: Portrait<br>旧版本信息：|类名：Contact;<br>方法or属性：portrait?: Portrait<br>新版本信息：?Portrait|@ohos.contact.d.ts|
|type有变化|类名：Contact;<br>方法or属性：postalAddresses?: PostalAddress[]<br>旧版本信息：|类名：Contact;<br>方法or属性：postalAddresses?: PostalAddress[]<br>新版本信息：?PostalAddress[]|@ohos.contact.d.ts|
|type有变化|类名：Contact;<br>方法or属性：relations?: Relation[]<br>旧版本信息：|类名：Contact;<br>方法or属性：relations?: Relation[]<br>新版本信息：?Relation[]|@ohos.contact.d.ts|
|type有变化|类名：Contact;<br>方法or属性：sipAddresses?: SipAddress[]<br>旧版本信息：|类名：Contact;<br>方法or属性：sipAddresses?: SipAddress[]<br>新版本信息：?SipAddress[]|@ohos.contact.d.ts|
|type有变化|类名：Contact;<br>方法or属性：websites?: Website[]<br>旧版本信息：|类名：Contact;<br>方法or属性：websites?: Website[]<br>新版本信息：?Website[]|@ohos.contact.d.ts|
|type有变化|类名：Contact;<br>方法or属性：name?: Name<br>旧版本信息：|类名：Contact;<br>方法or属性：name?: Name<br>新版本信息：?Name|@ohos.contact.d.ts|
|type有变化|类名：Contact;<br>方法or属性：nickName?: NickName<br>旧版本信息：|类名：Contact;<br>方法or属性：nickName?: NickName<br>新版本信息：?NickName|@ohos.contact.d.ts|
|type有变化|类名：Contact;<br>方法or属性：note?: Note<br>旧版本信息：|类名：Contact;<br>方法or属性：note?: Note<br>新版本信息：?Note|@ohos.contact.d.ts|
|type有变化|类名：Contact;<br>方法or属性：organization?: Organization<br>旧版本信息：|类名：Contact;<br>方法or属性：organization?: Organization<br>新版本信息：?Organization|@ohos.contact.d.ts|
|type有变化|类名：ContactAttributes;<br>方法or属性：attributes: Attribute[]<br>旧版本信息：|类名：ContactAttributes;<br>方法or属性：attributes: Attribute[]<br>新版本信息：Attribute[]|@ohos.contact.d.ts|
|type有变化|类名：Email;<br>方法or属性：email: string<br>旧版本信息：|类名：Email;<br>方法or属性：email: string<br>新版本信息：string|@ohos.contact.d.ts|
|type有变化|类名：Email;<br>方法or属性：labelName?: string<br>旧版本信息：|类名：Email;<br>方法or属性：labelName?: string<br>新版本信息：?string|@ohos.contact.d.ts|
|type有变化|类名：Event;<br>方法or属性：labelName?: string<br>旧版本信息：|类名：Event;<br>方法or属性：labelName?: string<br>新版本信息：?string|@ohos.contact.d.ts|
|type有变化|类名：ImAddress;<br>方法or属性：labelName?: string<br>旧版本信息：|类名：ImAddress;<br>方法or属性：labelName?: string<br>新版本信息：?string|@ohos.contact.d.ts|
|type有变化|类名：PhoneNumber;<br>方法or属性：labelName?: string<br>旧版本信息：|类名：PhoneNumber;<br>方法or属性：labelName?: string<br>新版本信息：?string|@ohos.contact.d.ts|
|type有变化|类名：PostalAddress;<br>方法or属性：labelName?: string<br>旧版本信息：|类名：PostalAddress;<br>方法or属性：labelName?: string<br>新版本信息：?string|@ohos.contact.d.ts|
|type有变化|类名：Relation;<br>方法or属性：labelName?: string<br>旧版本信息：|类名：Relation;<br>方法or属性：labelName?: string<br>新版本信息：?string|@ohos.contact.d.ts|
|type有变化|类名：SipAddress;<br>方法or属性：labelName?: string<br>旧版本信息：|类名：SipAddress;<br>方法or属性：labelName?: string<br>新版本信息：?string|@ohos.contact.d.ts|
|type有变化|类名：Email;<br>方法or属性：displayName?: string<br>旧版本信息：|类名：Email;<br>方法or属性：displayName?: string<br>新版本信息：?string|@ohos.contact.d.ts|
|type有变化|类名：Email;<br>方法or属性：labelId?: number<br>旧版本信息：|类名：Email;<br>方法or属性：labelId?: number<br>新版本信息：?number|@ohos.contact.d.ts|
|type有变化|类名：Event;<br>方法or属性：labelId?: number<br>旧版本信息：|类名：Event;<br>方法or属性：labelId?: number<br>新版本信息：?number|@ohos.contact.d.ts|
|type有变化|类名：ImAddress;<br>方法or属性：labelId?: number<br>旧版本信息：|类名：ImAddress;<br>方法or属性：labelId?: number<br>新版本信息：?number|@ohos.contact.d.ts|
|type有变化|类名：PhoneNumber;<br>方法or属性：labelId?: number<br>旧版本信息：|类名：PhoneNumber;<br>方法or属性：labelId?: number<br>新版本信息：?number|@ohos.contact.d.ts|
|type有变化|类名：PostalAddress;<br>方法or属性：labelId?: number<br>旧版本信息：|类名：PostalAddress;<br>方法or属性：labelId?: number<br>新版本信息：?number|@ohos.contact.d.ts|
|type有变化|类名：Relation;<br>方法or属性：labelId?: number<br>旧版本信息：|类名：Relation;<br>方法or属性：labelId?: number<br>新版本信息：?number|@ohos.contact.d.ts|
|type有变化|类名：SipAddress;<br>方法or属性：labelId?: number<br>旧版本信息：|类名：SipAddress;<br>方法or属性：labelId?: number<br>新版本信息：?number|@ohos.contact.d.ts|
|type有变化|类名：Event;<br>方法or属性：eventDate: string<br>旧版本信息：|类名：Event;<br>方法or属性：eventDate: string<br>新版本信息：string|@ohos.contact.d.ts|
|type有变化|类名：Group;<br>方法or属性：groupId?: number<br>旧版本信息：|类名：Group;<br>方法or属性：groupId?: number<br>新版本信息：?number|@ohos.contact.d.ts|
|type有变化|类名：Group;<br>方法or属性：title: string<br>旧版本信息：|类名：Group;<br>方法or属性：title: string<br>新版本信息：string|@ohos.contact.d.ts|
|type有变化|类名：Holder;<br>方法or属性：readonly bundleName: string<br>旧版本信息：|类名：Holder;<br>方法or属性：readonly bundleName: string<br>新版本信息：string|@ohos.contact.d.ts|
|type有变化|类名：Holder;<br>方法or属性：readonly displayName?: string<br>旧版本信息：|类名：Holder;<br>方法or属性：readonly displayName?: string<br>新版本信息：?string|@ohos.contact.d.ts|
|type有变化|类名：Holder;<br>方法or属性：holderId?: number<br>旧版本信息：|类名：Holder;<br>方法or属性：holderId?: number<br>新版本信息：?number|@ohos.contact.d.ts|
|type有变化|类名：ImAddress;<br>方法or属性：imAddress: string<br>旧版本信息：|类名：ImAddress;<br>方法or属性：imAddress: string<br>新版本信息：string|@ohos.contact.d.ts|
|type有变化|类名：Name;<br>方法or属性：familyName?: string<br>旧版本信息：|类名：Name;<br>方法or属性：familyName?: string<br>新版本信息：?string|@ohos.contact.d.ts|
|type有变化|类名：Name;<br>方法or属性：familyNamePhonetic?: string<br>旧版本信息：|类名：Name;<br>方法or属性：familyNamePhonetic?: string<br>新版本信息：?string|@ohos.contact.d.ts|
|type有变化|类名：Name;<br>方法or属性：fullName: string<br>旧版本信息：|类名：Name;<br>方法or属性：fullName: string<br>新版本信息：string|@ohos.contact.d.ts|
|type有变化|类名：Name;<br>方法or属性：givenName?: string<br>旧版本信息：|类名：Name;<br>方法or属性：givenName?: string<br>新版本信息：?string|@ohos.contact.d.ts|
|type有变化|类名：Name;<br>方法or属性：givenNamePhonetic?: string<br>旧版本信息：|类名：Name;<br>方法or属性：givenNamePhonetic?: string<br>新版本信息：?string|@ohos.contact.d.ts|
|type有变化|类名：Name;<br>方法or属性：middleName?: string<br>旧版本信息：|类名：Name;<br>方法or属性：middleName?: string<br>新版本信息：?string|@ohos.contact.d.ts|
|type有变化|类名：Name;<br>方法or属性：middleNamePhonetic?: string<br>旧版本信息：|类名：Name;<br>方法or属性：middleNamePhonetic?: string<br>新版本信息：?string|@ohos.contact.d.ts|
|type有变化|类名：Name;<br>方法or属性：namePrefix?: string<br>旧版本信息：|类名：Name;<br>方法or属性：namePrefix?: string<br>新版本信息：?string|@ohos.contact.d.ts|
|type有变化|类名：Name;<br>方法or属性：nameSuffix?: string<br>旧版本信息：|类名：Name;<br>方法or属性：nameSuffix?: string<br>新版本信息：?string|@ohos.contact.d.ts|
|type有变化|类名：NickName;<br>方法or属性：nickName: string<br>旧版本信息：|类名：NickName;<br>方法or属性：nickName: string<br>新版本信息：string|@ohos.contact.d.ts|
|type有变化|类名：Note;<br>方法or属性：noteContent: string<br>旧版本信息：|类名：Note;<br>方法or属性：noteContent: string<br>新版本信息：string|@ohos.contact.d.ts|
|type有变化|类名：Organization;<br>方法or属性：name: string<br>旧版本信息：|类名：Organization;<br>方法or属性：name: string<br>新版本信息：string|@ohos.contact.d.ts|
|type有变化|类名：Organization;<br>方法or属性：title?: string<br>旧版本信息：|类名：Organization;<br>方法or属性：title?: string<br>新版本信息：?string|@ohos.contact.d.ts|
|type有变化|类名：PhoneNumber;<br>方法or属性：phoneNumber: string<br>旧版本信息：|类名：PhoneNumber;<br>方法or属性：phoneNumber: string<br>新版本信息：string|@ohos.contact.d.ts|
|type有变化|类名：Portrait;<br>方法or属性：uri: string<br>旧版本信息：|类名：Portrait;<br>方法or属性：uri: string<br>新版本信息：string|@ohos.contact.d.ts|
|type有变化|类名：PostalAddress;<br>方法or属性：city?: string<br>旧版本信息：|类名：PostalAddress;<br>方法or属性：city?: string<br>新版本信息：?string|@ohos.contact.d.ts|
|type有变化|类名：PostalAddress;<br>方法or属性：country?: string<br>旧版本信息：|类名：PostalAddress;<br>方法or属性：country?: string<br>新版本信息：?string|@ohos.contact.d.ts|
|type有变化|类名：PostalAddress;<br>方法or属性：neighborhood?: string<br>旧版本信息：|类名：PostalAddress;<br>方法or属性：neighborhood?: string<br>新版本信息：?string|@ohos.contact.d.ts|
|type有变化|类名：PostalAddress;<br>方法or属性：pobox?: string<br>旧版本信息：|类名：PostalAddress;<br>方法or属性：pobox?: string<br>新版本信息：?string|@ohos.contact.d.ts|
|type有变化|类名：PostalAddress;<br>方法or属性：postalAddress: string<br>旧版本信息：|类名：PostalAddress;<br>方法or属性：postalAddress: string<br>新版本信息：string|@ohos.contact.d.ts|
|type有变化|类名：PostalAddress;<br>方法or属性：postcode?: string<br>旧版本信息：|类名：PostalAddress;<br>方法or属性：postcode?: string<br>新版本信息：?string|@ohos.contact.d.ts|
|type有变化|类名：PostalAddress;<br>方法or属性：region?: string<br>旧版本信息：|类名：PostalAddress;<br>方法or属性：region?: string<br>新版本信息：?string|@ohos.contact.d.ts|
|type有变化|类名：PostalAddress;<br>方法or属性：street?: string<br>旧版本信息：|类名：PostalAddress;<br>方法or属性：street?: string<br>新版本信息：?string|@ohos.contact.d.ts|
|type有变化|类名：Relation;<br>方法or属性：relationName: string<br>旧版本信息：|类名：Relation;<br>方法or属性：relationName: string<br>新版本信息：string|@ohos.contact.d.ts|
|type有变化|类名：SipAddress;<br>方法or属性：sipAddress: string<br>旧版本信息：|类名：SipAddress;<br>方法or属性：sipAddress: string<br>新版本信息：string|@ohos.contact.d.ts|
|type有变化|类名：Website;<br>方法or属性：website: string<br>旧版本信息：|类名：Website;<br>方法or属性：website: string<br>新版本信息：string|@ohos.contact.d.ts|
