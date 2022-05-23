# Gladiator

## Story

### An email from the client

```
From: Mark Smith <ceo@thepartner.com>

Subject: Ave Imperator, morituri te salutant!

Recently, I've been really into Ancient Rome and Gladiator fights and stuff.
I've watched Spartacus and played Swords & Sandals for dozens of hours.
I think that we have some spare budget for a little inside project,
so I would like to task you with creating a Gladiator Tournament simulator.
You will find the user stories and the details in the attachment below.

Mark
```

Oh, this guy again. Well, let's get to it!

In this project, my primary goal is to design and create some logic behind
the Gladiator Tournament simulator. It means that the program is going
to work in the terminal.


## Tasks


1. Create a base class for all gladiator types, and four subclasses, Swordsman, Archer, Assassin, and Brutal.
    - There is a `BaseGladiator` abstract class that provides all necessary functionalities for all its subclasses.
    - The level of a gladiator can be incremented by invoking the `LevelUp()` method. The level can be accessed using the `Level` property (which has an encapsulated setter).
    - There is a StatisticMultiplier enum type, which has three values, Low, Medium, and High.
    - Within the `BaseGladiator` class, there are three protected abstract properties, which are responsible for returning multipliers for the Gladiator's HP, SP and DEX statistics, respectively. The properties MUST be overriden by every class that inherits from the `Gladiator`.
    - Within the `BaseGladiator` class, there are three public properties that return the maximum available values of the gladiator's statistics (HP, SP, and DEX, respectively). The available value is calculated by the `maximumStatistic = baseStatistic × statisticMultiplier × level` formula.
    - Every gladiator has a current health value. This decreases during a combat when receiving hits from the enemy. When the value goes below zero, the gladiator dies.
    - There is a `Swordsman` subclass of `BaseGladiator`. Its multipliers are: HP: medium, SP: medium, DEX: medium
    - There is an `Archer` subclass of `BaseGladiator`. Its multipliers are: HP: medium, SP: medium, DEX: high.
    - There is an `Assassin` subclass of `BaseGladiator`. Its multipliers are: HP: low, SP: high, DEX: high.
    - There is a `Brutal` subclass of `VaseGladiator`. Its multipliers are: HP: high, SP: high, DEX: low.

2. Implement the `GladiatorFactory` class for creating `Gladiator` instances.
    - The `GenerateRandomGladiator()` method randomly generates a new instance for one of the implemented subclasses of `BaseGladiator`. The `Swordsman` subclass is twice as likely to be created than any other subclass.
    - HP, SP and DEX base statistics are assigned to a random value from range `[25-100]`, and LVL is assigned to a random value from range `[1-5]`.
    - Only one static Random object is used for randomization throughout the whole project.

3. Implement the `Combat` class for simulating duels between gladiators. The fighting mechanic is the same for all `Gladiator` subclasses. The combat simulation is turn-based (A attacks B, then B attacks A, and so on).
    - The `BaseGladiator` class provides methods and properties to be used in battle simulation: `DecreaseHpBy()`, `IsDead`, `HealUp()`, `HP`, `SP`, `DEX`.
    - The `Simulate()` method runs the simulation of the whole fight. If the current health of any gladiator becomes non-positive (<= 0) after an attack, combat is finished, and the attacker is returned as the winner.
    - The first attacker is selected randomly, then the two gladiators take turns.
    - During each turn, the attacker can either hit the enemy or miss. The chance of hitting is calculated by the following method. Take the dexterity difference: `attackerDex - defenderDex` and clamp it (force it into the range `[10-100]`). For example, `attackerDex = 10; defenderDex = 120; -> attackerDex - defenderDex = -110; after clamping the value is 10`. The clamped value is the percentage chance of the attacker hitting the enemy.
    - If the attacker hits the enemy, the damage is subtracted from the current health of the enemy. The damage is calculated by the integer value of the following formula. `damage = attackerSp × R` where `R` is a random number from range `[0.1-0.5]`
    - The Combat class saves logs in a `List` that can be accessed using the `GetCombatLog()` method.
    - If the attacker hits the enemy, the following log is persisted. `"X deals D damage"`, where `X` is the attacker's name and `D` is the damage.
    - If the attacker misses, the following log is persisted. `"X missed"`, where `X` is the attacker's name.
    - At the end of the combat, the following log is persisted. "X has died, Y wins!", where `X` and `Y` are the losing and winning gladiator's names, respectively.

4. Implement a `Tournament` class to be used for arranging and invoking combats in the Colosseum. The `Tournament` class holds the pair of contestants that fight in it. It should be a recursive function which creates a knock-out system within all the contestans, makes a pair, and pushes the winner to the next round until someone wins```
    Julius
        |----____
    Petros      |
                |-----____
    Remus       |
        |----____
    Linus


```
Duel Jupiter versus Nero:
Swordsman Jupiter (371/371 HP, 623 SP, 476 DEX, 7 LVL)
Brutal Nero (790/790 HP, 560 SP, 498 DEX, 8 LVL)

Begin!
- Jupiter missed
- Nero deals 245 damage
- Jupiter missed
- Nero deals 183 damage
Swordsman Jupiter has died, Brutal Nero wins!
```

    - The winner of each combat has his level increased by one (which then affects his stats), then healed-up back to the available HP.
    - The `GetChampion()` method takes a `Tournament`, simulates a series of combats according to the fight hierarchy starting from the bottom, and returns the final winner as the champion.


5. [OPTIONAL] Implement a weapon effect system that can cause additional damage or other advantages during combat.
    - When creating a `Gladiator`, there is a 50% chance that he is granted a special weapon effect. The effect is randomly chosen from the ones mentioned below. The special weapon effects are displayed in the detailed view of the gladiator when announcing the combats.
    - Bleeding – there is a 5% chance that upon receiving a hit, the enemy starts bleeding and receives additional damage in each turn (2% of his available HP per turn) until the end of the combat. There can be "multiple bleedings" at the same time with cumulative effects.
    - Poison – there is a 20% chance that upon receiving a hit, the enemy gets poisoned and receives additional damage for the next three turns (5% of his available HP per turn). If poisoned again, the receiver immediately dies.
    - Burning – there is a 15% chance that upon receiving a hit, the enemy is set on fire and receives additional damage for a random number of turns (in range `[1-5]`) (5% of his available HP per turn). If set on fire again, the duration of burning is extended by a random amount of turns (in range `[1-5]`).
    - Paralyzing – there is a 10% chance that upon receiving a hit, the enemy is paralyzed, which makes him unable to attack or defend himself during the next three turns (effectively, this skips three attacks and deals three hits). If paralyzed again, the duration of the paralyzed state is reset to three turns
    - Using the weapon effect system you have implemented, create an effect of your own. Will it be freezing, magic, or something else? Be creative!
