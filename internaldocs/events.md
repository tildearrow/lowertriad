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
0x7e| error event
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

events that happen during scene rendering.

 ID       | Type               | Description                                   | Data
----------|--------------------|-----------------------------------------------|----------------
0x0f000000| pre-clear event    | executed before SDL_RenderClear               | none
0x0f000001| pre-render event   | executed before rendering scene               | none
0x0f000002| render event       | executed while rendering scene                | none
0x0f000003| post-render event  | executed after rendering scene                | none
0x0f000004| overlay event      | executed while rendering overlay              | none
0x0f000005| post-present event | executed after SDL_RenderPresent              | none

#### Keyboard event

events related to keyboard input.

 ID       | Type                  | Description              | Data
----------|-----------------------|--------------------------|-------------------------
0x100xxxxx| key event             |                          | none
0x101xxxxx| key press event       |                          | none
0x102xxxxx| key release event     |                          | none
0x103xxxxx| raw key event         | uses raw keycodes        | none
0x104xxxxx| raw key press event   |                          | none
0x105xxxxx| raw key release event |                          | none
0x10fffff0| any key event         | note: 'any' is not a key | `int key`, `int rawkey`
0x10fffff1| any key press event   |                          | `int key`, `int rawkey`
0x10fffff2| any key release event |                          | `int key`, `int rawkey`

#### Mouse event

everything mouse.

 ID       | Type                     | Description                                | Data
----------|--------------------------|--------------------------------------------|------------------------------------------------------------------------------
0x110xxxxx| mouse event              | pressure only for supported mouses         | `double pressure`
0x111xxxxx| mouse press event        |                                            | `double pressure`
0x112xxxxx| mouse release event      |                                            | `double pressure`
0x1130xxxx| mouse wheel down event   |                                            | none
0x1131xxxx| mouse wheel up event     |                                            | none
0x113fxxxx| mouse wheel raw event    |                                            | `int position`, `int delta`
0x114xxxxx| mouse here event         |                                            | `double pressure`
0x115xxxxx| mouse here press event   |                                            | `double pressure`
0x116xxxxx| mouse here release event |                                            | `double pressure`
0x117yxxxx| mouse here wheel event   | follows same format as normal wheel events | none
0x118xxxxx| mouse touch event        | for mouses with/or touchpad surfaces       | `int finger`, `double x`, `double y`, `double pressure`, `double fingersize`

#### Joystick event

like, everything joystick.

 ID       | Type                          | Description                           | Data
----------|-------------------------------|---------------------------------------|------------------------------------------------------------------------------
0x120xxxxx| joystick button event         | pressure only for supported joysticks | `double pressure`
0x121xxxxx| joystick button press event   |                                       | `double pressure`
0x122xxxxx| joystick button release event |                                       | `double pressure`
0x123yxxxx| joystick d-pad event          | y=directional pad index               | `double pressure`
0x124yxxxx| joystick d-pad press event    |                                       | `double pressure`
0x125yxxxx| joystick d-pad release event  |                                       | `double pressure`
0x126yxxxx| joystick touch event          | for joysticks with touchpads          | none
0x127yxxxx| joystick touch press event    |                                       | none
0x128yxxxx| joystick touch release event  |                                       | none

#### Touch event

everything touchscreens.

 ID       | Type                | Description                           | Data
----------|---------------------|---------------------------------------|------------------------------------------------------------------------------
0x130xxxxx| touch event         |                                       | none
0x131xxxxx| touch press event   |                                       | `int finger`, `int fingersize`, `int pressure`
0x132xxxxx| touch release event |                                       | `int finger`, `int fingersize`, `int pressure` 

#### Other input event

for mostly unusual devices.

didn't find any yet.

#### Scene event

 ID       | Type                  | Description              | Data
----------|-----------------------|--------------------------|-------------------------
0x20000000| scene load event      |                          | `bool reload`, `int prevscene`
0x20000001| scene finish event    |                          | none

#### Timer event

events that happen after a global timer.

 ID       | Type               | Description                                      | Data
----------|--------------------|--------------------------------------------------|---------------------
0x21xxxxxx| global timer event | happens when a global timer reaches zero.        | none

#### Game event

 ID       | Type               | Description           | Data
----------|--------------------|-----------------------|---------------------
0x70000000| game null event    | should not happen.    | none
0x70000001| game start event   |                       | none
0x70000002| game exit event    |                       | none
0x70000003| game restart event |                       | none
0x70000004| close button       |                       | none

#### Error event

all regarding signals or End Task.

 ID       | Type                         | Description                            | Data
----------|------------------------------|----------------------------------------|---------------------
0x7e000000| any terminating signal event | happens on INT, TERM, HUP or End Task. | `int signal`
0x7e000001| any error signal event       | happens on any error signal or crash.  | `int signal`
0x7e000002| any signal event             | happens on any signal.                 | `int signal`
0x7e1xxxxx| signal event                 | OS X, Linux and other Unix[-like] only |

#### User event

events completely triggered by the game and not the engine or external factors.

 ID       | Type       | Description | Data
----------|------------|-------------|--------------
0x7fxxxxxx| user event | user event  | `void* data`