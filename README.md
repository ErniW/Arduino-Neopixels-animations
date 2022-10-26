**A reference for light animations using Neopixels. During my classes I usually cover some basics of Neopixels but these examples, based on wave generation and noise function are advanced and not required to pass my course. To understand the code, student must understand how sine wave is made and be proficient in programming.**

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
- *The inspiration were my observations of light effects during large-scale indoor musical events or live streams like this one: https://www.youtube.com/watch?v=wwCX_ywSqFc*
- *Examples can work on 16 MHz Arduino UNO but depending on amount of LED you might need something faster.*
- *I tried to mix some of my animations but mixing more than two becomes difficult and probably you should create one single effect from scratch. Also it's not good when too many things happens at once.*

**Tips and tricks:**
- *In some code examples I'm explicitly using custom map function implementation or multiplication. The Arduino default map is intiger based therfore mapping small number to very large and vice versa produces large approximation error. It's important because trigonometric functions have range between -1 and 1.*
- *The easiest trick to make sine always positive starting from zero is to add one and divide by two. Using absolute produces different effect. Also sine and cosine starts at different phases. Depending on your needs you can add PI or HALF_PI if you wish to start from 0 or 1.*
- *Using FastLed trigonometric functions have better bit resolution and optimized performance. I'm not using them everywhere but be aware of that.*
- *FastLed library has its own linear interpolation to mix two colors. There are other functions to help you.*
- *Sometimes preparing simple program in Processing can help you understand how your wave behaves.*

## List of animations:
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
