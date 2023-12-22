This repository contains my design of the Ben Eater 8-bit computer.  I call it an 8-CPU instead of a computer because to me it feels more like a CPU.

If you were to do a checkout of this, it is basically a KiCad project folder.  It will not contain all the symbols I used because the ones I designed I made global in KiCad, but I added a PDF of all the schematics.

You will also find my instruction set, the code to program the EEPROM's and the code to program the CPU which includes my test programs.

Below is a little badly written story of my journey.

## 8-bit CPU
I have always been intrigued by electronics by have never done anything with it.

A while back I found a video series by Ben Eater about building an 8-bit computer on breadboards ([YouTube](https://www.youtube.com/playlist?list=PLowKtXNTBypGqImE405J2565dvjafglHU)).  Watching the series I learned a lot about how CPU's (could) work and was really fascinated.  It all did not seem that complicated.

So after thinking about it for a while and checking my finances (It is not really cheap) I decided to build a variation of it.   But first I did some research and set some goals.

The research taught me that I should not skimp on breadboard quality.  There are a lot of people that write about this and the breadboards from BusBoard Prototype Systems seem to be one of the best.

Next I started digging into what types of 74 series logic chips there are.  I learned that the 74LS series that Ben uses are TTL logic chips but they are rather power hungry.  I decided I wanted to go with CMOS logic chips because they are more efficient.  In the end I went for 74HCT chips.  They are CMOS chips with TTL level support.  I went for this because I don't really now anything about this and I was not sure if I needed TTL level support in some parts.

So the chip series was decided and the breadboard brand was decided, now I needed a way to get all these things.  I started searching for those online and found the usual suspects: 
* Farnell
* Digikey
* Mouser
* ...

I live in Belgium so delivery costs, import taxes and VAT were important.  After a test order from [Mouser](https://www.mouser.be/) I learned that they take care of the VAT and the import taxes, and when you order over 50 EUR (excluding VAT) the delivery is free.  Just don't get caught at checkout because the prices on the site are without VAT.

I would also need power supply.  I did not want to use a cut open USB cable but wanted some extra features.
* The device needed a global on/off switch
* I needed to be able to toggle the output on or off 
* Obviously the voltage should be settable
* The amperage should be limited
* I wanted over current protection so the output would be turned off if my creation would draw more than the set amps

On Amazon I found this [device](https://www.amazon.nl/dp/B0C1SMSW9F?ref=ppx_yo2ov_dt_b_product_details&th=1) that had all the features I wanted and it was not out of my budget.

Amazon was also used to buy the [wires](https://www.amazon.com.be/dp/B07V5FVSYL?psc=1&ref=ppx_yo2ov_dt_b_product_details) and initially some [resistors](https://www.amazon.com.be/dp/B0967TG6XR?ref=ppx_yo2ov_dt_b_product_details&th=1).  The wires we great and I ordered multiple of those because it seems this thing needs a lot of wire.  The resistors I hated and did not use.  The legs have a diameter of 0.3 mm which is just too thin.  When you want to insert them into a breadboard they just bend.  The resistors eventually also came from Mouser.

Next up, the goals of this build.
* I wanted a schematic of my build so I learned to use [KiCad](https://www.kicad.org/)
* Have more RAM so I could use all 8 address bits
* Have the RAM split so the first 128 bytes are for application memory and second 128 bytes are for data memory.  I did not want my application to overwrite itself
* Have an X register with +1 / -1 feature to enable specific loops and have it set the carry flag and zero flag
* Have a Stack
* Do not leave any input pins floating
* Have a 220 Ohm resistor on each LED
* Have a 100nF decoupling capacitor for each chip

The 220 Ohm resistor on each LED really made me think about component placement.  It dictated the layout on the breadboards.  Unlike what Ben does in his videos I could not just go from an output pin to ground.

After all the orders arrived I started building my CPU module by module in the order of the videos.  I would first design each module in KiCad and use my design to build it on breadboards.

While building I initially used 10k Ohm resistors to either pull-up or pull-down control signal pins.  That way I could use a jumper wire to switch its state without the pin being floating during the transition.  (The resistors were removed after wiring up the control signals.) The different modules were tested individually once they were finished.

When building the output module I noticed I did not order any 74HCT273 chips.  So I changed my design to use what I had which were 74HCT173 D-type flip flops.  In hindsight this seems to be a blessing in disguise because there seems to be a design issue with using the 74HCT273 as can be seen [here](https://www.youtube.com/playlist?list=PLyHdG0fm3K1j8sfvvdIarTFXVcFDdoBYp).

After finishing the clock, program counter, a register, alu, b register, output, ram and instruction register I decided to combine them and wire them up to the bus.  This is were I got hit with my first problem.

Whenever there were more than 4 LED's active in the RAM value and I would change the RAM output control signal (high to low or low to high) the RAM address register would reset.  I searched for hours what the cause could be but never figured it out.  I rewired stuff, replaced chips, disconnected modules from the bus, added pull-up and pull-down resisters, ... but everything stayed the same.  Motivation really sank so drastic measures needed to be taken.  Given the RAM address gets loaded by the program counter initially I decided I did not need a reset there and removed the reset line and tied the pins to ground.  *Problem solved*.

Next I built the last 4 modules: control logic, CPU flags, X register and stack.  When they were done I wired up everything.  Guess what, things did not work as expected.  Some of the problems I saw:
* The A register would reset randomly
* The X register would reset randomly
* The X register would load data from the bus at random points
* The X register would increment and decrement randomly
* The stack would increment and decrement randomly
* RAM not always writing

Those dreaded random resets were spreading.  Given I have no oscilloscope I could not really see what was going on with reset line but after some mental gymnastics I figured there must be some noise getting to the reset line.  Given I know nothing about electronics I started trying things.  

When I put a 10nF capacitor on the reset line close to the reset pin and ground of the A register it no longer did the random reset but the button to reset everything still worked.  I did the same with the X register and wired up the reset for the RAM address again with a 10nF capacitor.  No more random resets.  I still don't know why this is happening but it is fixed.  *Problem solved*.

Next up were the random actions in the X register and stack.  After searching the internet I found out that when you change the address on an EEPROM there is a period of time where the data is invalid (this is also in the datasheet).  This shows itself by data pins going high or low randomly during the invalid period.  This was triggering the random actions.

The first fix was not to trigger the load of the X register by just using an inverted control signal.  I used the non inverted control signal and the clock through a NAND gate to trigger the load.  This way the loading is tied to a clock transition which is in line with the rest of the design.  This made things better but did not solve everything.

After some more searching on the internet I found a post where someone explained that the entire computer reacts to the rising edge of the clock.  This includes the instruction register and the CPU flags which trigger address changes.  If you were to change the address on the falling edge of the clock the 'blips' on the EEPROM output would not matter.

I first thought about using the inverted clock for the instruction register and the CPU flags but decided against it.  I was not sure if this would have side effects.  Given I had some room below the instruction register I decided to add two more 74HCT173 D-type flip flops to latch the instruction register and the CPU flags on the falling edge of each clock.  These latched values are used as the address lines for the EEPROM's.  This solved all the problems of random actions occurring.

Lastly there was the problem of the RAM not always writing.  I was aware of issues with the RC circuit Ben has in his original design on the clock for the RAM input.  I already put in a diode to prevent back feeding any voltage as the capacitor discharges but I was still suspicious.  Given writing ram works with a push button in programming mode, which does not have an RC circuit on it, I figured it might work without.  After removing the RC circuit and just passing in the clock everything worked.

I now have an 8-bit breadboard CPU which supports addition, subtraction, push, pop, subroutines, ...

#### Some random bits:

I can program the CPU using the dip switches but that got old really quickly.  I wrote a little Arduino application that could program the CPU.  I just hook up the ground, the address lines, the data lines and write signal to the breadboard from an [Arduino Nano Every](https://store.arduino.cc/products/arduino-nano-every).  This saves a lot of time and does not discourage me from making changes and retesting.

On the internet there are many posts that say you have to add a lot of bulk capacitors to the breadboards in order to make it stable.  My CPU does not seem to need it.  It could be the quality of the breadboards, the fact that I used 74HCT chips or the quality of the power supply.  When running my Fibonacci program it draws a maximum of 350 mA.

I used an alternative to the EEPROM programmer designed by Ben.  Given I used an Arduino Nano Every, which has more digital pins, I did not have to combine the write signal into the shift registers.  I did have to rewire it because my EEPROM's did not seems to have the content I expected. 

![Picture](https://raw.githubusercontent.com/nurk/8-bit-cpu/master/images/8-bity-cpu.jpeg)

