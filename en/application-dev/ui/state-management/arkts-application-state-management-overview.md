# Application State Management Overview

<!--Kit: ArkUI-->
<!--Subsystem: ArkUI-->
<!--Owner: @jiyujia926-->
<!--Designer: @zhangboren-->
<!--Tester: @TerryTsao-->
<!--Adviser: @zhang_yixin13-->
<!-- md-trans-meta sourceCommit=2fe87adc16af5a903a1eb4a9624e4d36fa962e3d translatedAt=2026-07-25T08:55:30.987Z pushedAt=2026-07-25T09:19:21.134Z -->

The decorators introduced in the component state management chapter can only share state variables within a page, that is, on a single component tree. If you want to implement application-level state data sharing or share state across multiple pages, you need to implement application-level state management. ArkTS provides various application state management capabilities based on different characteristics:

- [LocalStorage](arkts-localstorage.md): API for storing the UI state, usually used for state sharing within a [UIAbility](../../reference/apis-ability-kit/js-apis-app-ability-uiAbility.md) or between pages.

- [AppStorage](arkts-appstorage.md): app-level UI state storage, created by the UI framework upon app startup, which provides central storage for app UI state attributes.

- [PersistentStorage](arkts-persiststorage.md): API for persisting application attributes. It is usually used together with AppStorage to persist selected AppStorage attributes to the disk so that their values are the same upon application re-start as they were when the application was closed.

- [Environment](arkts-environment.md): a range of environment parameters regarding the device where the application runs. The environment parameters are synchronized to AppStorage and can be used together with AppStorage.