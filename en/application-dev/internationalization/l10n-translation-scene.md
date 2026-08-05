# Scene and Context Clarification for Translation

<!--Kit: Localization Kit-->
<!--Subsystem: Global-->
<!--Owner: @yliupy-->
<!--Designer: @sunyaozu-->
<!--Tester: @lpw_work-->
<!--Adviser: @ningningW-->
<!-- md-trans-meta sourceCommit=9d4329aa9b07ce81fc1a2c848fb4cea93e274a8e translatedAt=2026-08-04T12:26:49.018Z pushedAt=2026-08-04T13:22:42.711Z -->

The translation results of the same content may vary greatly in different scenes and contexts. When providing UI strings for translation, clarifying the scene and context can help to avoid translation errors. Translation scene information is usually provided in two ways:

1. Comments and annotations, which are made using string resource files, including the the context, part-of-speech, key word meaning, maximum text length supported by a control, variable meaning, and value range.

2. Screenshots, which are provided to show the actual UI layout and content.