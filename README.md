**A reference for light animations using Neopixels. During my classes I usually cover some basics of Neopixels but these examples, based on wave generation and noise function are a little more advanced and not required to pass my course. However, for some projects such effects might be necessary to achieve desired results. To understand the code, student must understand how sine wave is made and be proficient in programming.**

### Why some light animations are better than others?
- Trigonometric functions for smooth movement instead of linear increment/decrement, especially in fade-in and fade-out effects. However, there are non-smooth effects that looks great.
- Sine and wave generation for continuous effects.
- Perlin Noise instead of random.
- Non-linear speed and acceleration of animation. 
- Testing animation perceived timing.
- Choosing LED density based on perceived distance between light and observator.
- Proper color selection instead of using rainbow everywhere and avoiding non-smooth transition (unless we want that).
- Understanding differences between RGB and HSB color palette.
- The color theory and perception of different colors or temperatures and how it affects illuminated objects. *It does matter where you put your light installation, its background and color or surface of nearby objects.*

### Notes:
**About code examples:**:
- *I'm using FastLED library (https://fastled.io/). The library includes 16 bit operations, wave and noise generation, HSV colors and is more efficient than Adafruit Neopixel Library. It's easy to use.*
- *Some examples can be tested on small 8 LED strip. However, most of them require at least 1 meter strip to see the effects. Some of them looks better on denser strip, depending on distance from which you are watching the animation.*
- *Such effects are quite common. The inspiration were my observations of light effects during large-scale indoor musical events I've attended or live streams like this : https://www.youtube.com/watch?v=wwCX_ywSqFc* or https://www.youtube.com/watch?v=vitt03C7S5o Probably there was no single line of code written for these installations (they used dedicated DMX software) but searching such video can be great inspiration.
- *Examples can work on 16 MHz Arduino UNO but depending on amount of LED you might need something faster. Arduino's drawback is not allowing to use timers efficiently with interrupts so updating the strip is a blocking operation.*
- *I tried to mix some of my animations but mixing more than two becomes difficult and probably you should create one single effect from scratch. Also it's not good when too many things happens at once.*

**Tips and tricks:**
- *In some code examples I'm explicitly using custom map function implementation or multiplication. The Arduino default map is intiger based therfore mapping small number to very large and vice versa produces large approximation error. It's important because trigonometric functions have range between -1 and 1.*
- *The easiest trick to make sine always positive starting from zero is to add one and divide by two (or not dividing at all but later multiplying by half of range, division in slow for computation). Using absolute produces different effect. Also sine and cosine starts at different phases. Depending on your needs you can add PI or HALF_PI if you wish to start from 0 or 1.*
- *Using FastLed trigonometric functions have better bit resolution and optimized performance. I'm not using them everywhere but be aware of that.*
- *FastLed library has its own linear interpolation to mix two colors. There are other functions to help you.*
- *Sometimes preparing simple program in Processing can help you understand how your wave behaves.*


**Improving performance of code**
I'm not using these things for code clarity. Some of them can affect only very large amount of LEDs.

- Major problem with Arduino libraries is blocking way of updating the strip. You can't do anything else during data transmission. You can't do anything about that unless you want do develop a bare-metal driver.
- WS2812 and WS2812b data transfer frequency is 800kHz. You can't go faster. Maybe check other, faster strips supported by FastLed Library?
- Buy a faster Arduino.
- Avoid operations on float or (depending on board) make sure that floating-point unit is enabled.
- Reduce the division operation which takes a lot of CPU cycles. Instead of using the formula `value = (sine + 1 / 2) * 255` to normalize the value, use `value = (sine + 1) * 127`. Also avoid modulo operation.
- Use optimized FastLed sine operations instead of sine.
- Remove unnecessary Serial transmissions.

## List of animations:

### Sine wave - Number 0 - 10:
Examples introduce basics of creating color effects with sine waves.

-------------

## List of animations:
### Sine wave:
X- **Basic HSB linear rainbow**  for someone who has never seen FastLed library.
X- **Basic HSB rainbow from sine wave** to compare two different kind of rainbows.
X- **White wave fade in and out.**
X- **One color with white sweep**
- **Wave padding** increase or decrease the break between high peaks
?- **HSB rainbow with bloom effect** one sine is controlling hue, another one controls the brightness (opposite direction).
X **Back and forth movement of sine**, moving with another sine.
? **Back and forth movement of sine but slightly moving forward.**
- **Shrink and grow** of single amplitude, centered.
- **Shrink and grow** of moving sine wave.
- **Shrink and grow from wave peak**
- **Shrink and grow from wave peak fragmented** You can define your own amount of pulses or disable movement.
- **Shrink and grow from wave peak fragmented with padding**
- **Snail-like movement**, similar to shrink and grow but moves from tail to head.
X- **Sine wave with linear interpolation between two colours.**
X- **Phase shift with linear interpolation**, switching between two colors at opposite sine wave amplitudes.
- **Scanner effect with sine.**
- **Square wave from sine wave recursion** to generate smooth edges.
X **Fragmented fade-in and fade-out**, instead of fading in and out whole strip it does it fragment by fragment.
- **Sine fading away from center** ????? phase shift na całym

X- fragmented with different phases
- fragmented with sine

single grow to half and then rapid fill

### Perlin noise and random:
- **Random blink** instead of just blinking a randomly chosen LED it creates a single sine pulse gradually fading in and out. To achieve different results you can change its phase, so it can start from peak.
- **Random blink with random spread**, some blinks will appear larger and brighter than others.
- **Random blink and move**, fade in, move, fade out.
- **Random blink triplet** blinks three times with slight movement.
- **Noise liquid**
- **Rust**, it's similar to liquid but it's inversed.
- **Noise movement**
- **Noise movement back and forth**
- **Noise movement with intervals**
- **Double Noise** makes additional bloom effect.
- **Triple noise** bloom and back and forth
- **Noise outer space**, moves from middle toward sides.
- **Noise outer space with intervals**.
- **Different pulses, different speed**

### Mixed effects:
- **Slow and fast fade in of lines**


### Fit into BPM:


---------
*TODO: I should rearrange my sketches and give them proper names.*

- fraction of line (recurrency?), rust, sweep, inversed knightrider, lerp-phase-shift

**Continuous wave:**
- Sine wave basic.
- Sine wave back and forth
- Sine wave with lerp
- Sine wave phase shift with lerp
- Sine wave spread (frequency change)
- Sine wave shrink and grow
- Square wave
- Square wave changing duty cycle
- Square wave via sum of sine waves (for smooth edges).
- Arctan.
- "Knightrider"
- "Snail"
- Sawtooth wave through simple increment.


**Noise and random:**
- Random blink
- Random blink with random spread
- Noise liquid
- Noise outer space
- Rust

**Mixed effects:**
- Sweep: changes the color of noise animation without altering the brightness.
- Scanner: a simple phased overlay.
