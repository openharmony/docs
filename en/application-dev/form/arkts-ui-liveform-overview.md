# Overview of Interactive Widgets

<!--Kit: Form Kit-->
<!--Subsystem: Ability-->
<!--Owner: @Qian-Win-->
<!--Designer: @cx983299475-->
<!--Tester: @mahailong123456-->
<!--Adviser: @HelloShuo-->
<!-- md-trans-meta sourceCommit=a08d450b4f575e3d4749ddeef9dd32275ec0a19e translatedAt=2026-08-03T02:23:08.667Z pushedAt=2026-08-03T03:00:59.966Z -->

Supported since API version 20, interactive widgets provide animation capabilities such as overflow animations, rich information notifications, and shallow interactions, greatly enhancing user experience.

## Scenarios

There are two types of interactive widgets: fun-based widget and scene-based widget.

### Fun-based Widget

Users can tap a fun-based widget to play mini games. Currently, this feature can be developed only based on quick games. For details, see [Developing a Fun-based Widget](arkts-ui-liveform-funinteraction-development.md).

**Figure 1** Example of a fun-based widget

![live-form-game-demo.gif](figures/live-form-game-demo.gif)

### Scene-based Widget

Scene-based widgets support scene animations. For example, a weather widget activates and triggers its weather animation effect when the weather changes to a thunderstorm. Once the animation ends, the widget reverts to its original display. For details, see [Overview of Scene-based Widgets](arkts-ui-liveform-sceneanimation-overview.md).

## Constraints

- As an enhancement of the widget functionality, the widget's own service logic cannot be heavily dependent on the interactive widget animation capabilities.

<!--RP1--><!--RP1End-->