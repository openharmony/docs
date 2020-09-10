# Overview<a name="EN-US_TOPIC_0000001054438981"></a>

## Globalization Subsystem<a name="section11516137123416"></a>

Users can set the locale regarding about 68 languages and regions on OpenHarmony devices. As the locale settings are synchronized from one OpenHarmony device to another during interconnection, multi-language resource backtracking and multi-language preference support should be taken into account.

The global resource manager mainly provides the following capabilities:

-   Multi-language resource backtracking: Users in different regions have their own cultural background and use their respective native languages. During resource loading, it is critical to support multi-language locale settings, specifically, to use as few languages as possible to match users' particular cultural background.

-   Multi-language preference support: One of users' multiple preferred languages is selected and displayed for users \(for example, the Swiss\) who have multiple native languages.

## Repositories Involved<a name="section5889165803317"></a>

global\_frameworks\_resmgr\_lite

global\_interfaces\_innerkits\_resmgr\_lite

