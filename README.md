# Sequential Gears

Bikes have gears. These gears can change how far the wheel rotates compared to how far you rotate the pedals. We use gears to increase the amount of rotation, at the cost of making it harder to pedal. There are gears at the front and back of the bike, connected to the cranksets and rear wheel respectively. Often, cyclists will only use a small range of these gears. I'm trying to create a shifter that makes full use of all the available gear ratios, allowing the cyclist to increase the gear ratio by a percentage, and the system automatically determining the best gears to switch into, accounting for the current gear ratio, distance to (i.e. amount of gears to shift) the new gears, and crosschaining.

## Operation
The program will run on an arduino attached to the bike. The gears will be controlled by either stepper motors or servos to pull the gear cables the required amount.

## What's the point?

There isn't one. This is a silly idea. It is so little effort to change gears manually, and this is so much more effort than it is worth. There will be loads of issues with the chain falling off when switching the front and rear gears together and I'll probably break something on the bike in trying to get it to work. However, it is a fun idea. Also I want to create an E-Bike with the motor being an angle grinder that I have laying about so I might as well go all out and make it even sillier with this.

## Planned Featureset
Gear Shifting
- The user will be able to shift gears up and down as usual.

Gear % Increase
- The user will be able to shift gears up and down by a user specified percentage of the total gear ratio. The software will calculate what the next gear ratio should be, and then determine which actual gear is most appropriate.

Mitigating Crosschaining
- To stop crosschaining from occuring, the program will prioritise keeping the chain on the same side of each derailleur when determining the next gear to shift to.

## Building
Build the program using 
```bash
g++ -o <build-filename> main.cpp
```
