Blink-Project
================
Capstone1 - Blink example HW.
-------------
Blink.h contains Blink class.

># 1. Member funcion
>public void Blink::on();
>
>public void Blink::off();
># 2. Member variable
>private int _pin;
># 3. Etc
>* Call Blink::on() to turn on led, Blink::off() to turn off led.
>* At on(), [LOW] was used to parameter - cause led's state(pull up/down) is different.