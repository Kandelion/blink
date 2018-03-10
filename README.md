Blink-Project
================
# 1. Blink example HW
>Blink.h contains Blink class.
>
>## 1. Member funcion
>---------------
>- public void Blink::on();  
>Turn on the LED.
>
>- public void Blink::off();  
>Turn off the LED.
>
>## 2. Member variable
>---------------
>- private int _pin;  
>LED's pin number.
>
>## 3. Etc
>---------------
>* Call Blink::on() to turn on led, Blink::off() to turn off led.
>* At on(), [LOW] was used to parameter - cause led's state(pull up/down) is different.

# 2. Dallas temperature example HW
>temp.h contains TEMP class.
>
>## 1. Member function
>---------------
>- public void TEMP::Connect();  
>Try connect to [server][link_dallas_server].
> 
>- public void TEMP::Send(String);  
>Try send temperature data to [channel][link_dallas_channel].
>
>- private String getMsg(String);  
>Return http msg string.
> 
>## 2. Member variable
>---------------
>- private String apikey;  
>The apikey of thingspeak channel.  

[link_dallas_server]: www.thingspeak.com
[link_dallas_channel]: https://thingspeak.com/channels/445920