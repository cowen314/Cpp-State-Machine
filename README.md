# Cpp-State-Machine

Review of existing designs:
- Tinyfsm
  - Define a number of events (structs / classes)
    - The events have data associated with them
  - Create a state machine (class)
    - The interface of this class is defined by the available events. There should be a version of the public react(eventType) method for each type of event. These methods should be virtual unless the handling is state-independent.
  - Create states (classes)
    - States inherit from the state machine class (this seems weird). Each state overrides react(eventType) for events where handling is state dependent
  - Thoughts:
    - users could defined protected methods in the state machine class called “actions”.
    - users could define transitions in some arbitrary syntax (not necessarily related to C++). The syntax could be similar to what is done when defining transitions while using the transitions (python) state machine package. C++ files could be automatically generated.
      - This could start to get quite challenging when passing data between actions… and wanting to build custom code into the event handling that occurred between the actions… but… this does make the state logic much more transparent. Also you could make all of the actions void and just rely on class private data.
