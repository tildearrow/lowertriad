# Events

## Event IDs

the 8 MSBs are used to represent the event type, and the rest for event ID.

this gives a total of ~16 million possible events in a type.

### List of event types

 ID | Type
----|--------------------------
0x00| entity event
0x01| frame event
0x02| collision event
0x03| timer event
0x0f| render event
0x10| keyboard input event
0x11| mouse input event
0x12| joystick input event
0x13| touch input event
0x1f| other input event
0x20| scene event
0x21| global timer event
0x70| game event
0x7f| user event

### List of event IDs

#### Entity event

events that correspond to actions that happen to an entity.

 ID       | Type               | Description                                   | Data
----------|--------------------|-----------------------------------------------|----------------
0x00000000| null event         | is never raised.                              | none
0x00000001| pre-creation event | entity is created. put into constructor code. | none
0x00000002| creation event     | entity is created. it happens once.           | none
0x00000003| destruction event  | entity is destroyed. it happens once.         | none
0x00000004| destructor event   | entity is destroyed. put into destructor code.| none

#### Frame event

events that happen during a frame.

 ID       | Type               | Description                                      | Data
----------|--------------------|--------------------------------------------------|----------------
0x01000000| null frame event   | is never raised.                                 | none
0x01000001| pre-frame event    | executed every frame at the beginning of update. | none
0x01000002| frame event        | executed every frame during update.              | none
0x01000003| post-frame event   | executed every frame at the end of update.       | none

#### Collision event

events that happen during a collision.

 ID       | Type                     | Description                                                      | Data
----------|--------------------------|------------------------------------------------------------------|------------------
0x01yxxxxx| etype collision event    | when this entity collides with any etype entity. y can't be 0xe. | `int collider`
0x01exxxxx| group collision event    | when this entity collides with any entity of a specific group.   | `int etype`, `int collider`
0x01fffff0| global collision event   | when this entity collides with any entity.                       | none
0x01fffff1| boundary collision event | when this entity collides with the scene's boundaries.           | none
0x01fffff2| out of scene event       | when this entity is outside the scene.                           | none
0x01fffff3| viewport boundary event  | when this entity collides with a viewport's boundaries.          | `int vpid`
0x01fffff4| out of viewport event    | when this entity is outside a viewport.                          | `int vpid`
0x01ffffff| unknown collision event  | should not happen.                                               | none

#### Timer event

events that happen after a timer.

 ID       | Type          | Description                                      | Data
----------|---------------|--------------------------------------------------|---------------------
0x03xxxxxx| timer event   | happens when a timer reaches zero.               | none

#### Render event

adding information about this and more later. goodnight.