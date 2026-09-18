# ShooterSam
# ShooterSam

Sample game project built with **Unreal Engine 5.6**, using a combination of C++ and Blueprints. The project focuses on third-person gameplay and includes multiple variants for experimenting with combat, platforming, and side-scrolling systems.

## Features

- Third-person character with orbiting camera controls and Enhanced Input.
- Shooter gameplay with weapons, AI, and Behavior Tree tasks/services.
- Combat variant with:
  - Combo attacks.
  - Charged attacks.
  - Damage dealing, damage reactions, and death.
  - Respawning and a life bar.
- Platforming variant.
- Side-scrolling variant with:
  - NPCs and AI powered by StateTree.
  - Pickups and a pickup counter UI.
  - Jump pads, moving platforms, and soft platforms.
- Unreal Engine plugins including StateTree, GameplayStateTree, Modeling Tools, and Cascade-to-Niagara Converter.

## Requirements

- Unreal Engine **5.6**.
- Visual Studio 2022 with the **Game development with C++** workload.
- Windows 64-bit.
- Git, if cloning the project from the repository.

## Getting Started

1. Clone repository:

   ```bash
   git clone https://github.com/TDTer/ShooterSam.git
   cd ShooterSam
   ```

2. Open `ShooterSam.uproject` with Unreal Editor 5.6.
3. Allow Unreal Engine to generate project files if prompted.
4. If using Visual Studio, open `ShooterSam.sln` and build the `ShooterSamEditor` target with the `Development Editor` / `Win64` configuration.
5. Select a level in the Content Browser and click **Play**.

> The first launch may take additional time while Unreal Engine compiles C++ and shaders, builds modules, and generates temporary data.

## Project Structure

```text
ShooterSam/
??? Config/                         # Unreal Engine configuration
??? Content/                        # Levels, Blueprints, materials, animations, and assets
?   ??? Input/                      # Input Actions and Input Mapping Contexts
?   ??? Variant_Combat/             # Combat variant assets
?   ??? Variant_Platforming/        # Platforming variant assets
?   ??? Variant_SideScrolling/      # Side-scrolling variant assets
??? Source/ShooterSam/              # Main C++ source code
?   ??? Variant_Combat/             # Combat character, AI, UI, and interfaces
?   ??? Variant_Platforming/        # Platforming character and controller
?   ??? Variant_SideScrolling/      # Side-scrolling character, AI, gameplay, and UI
?   ??? *.cpp, *.h                  # Shared gameplay code
??? ShooterSam.uproject             # Unreal Engine project file
??? ShooterSam.sln                 # Visual Studio solution
```

## Notable Source Components

- `ShooterSamCharacter`: base third-person character and camera controls.
- `Gun`: weapon system.
- `ShooterAI` and the `BTTask`/`BTService` classes: AI logic for shooter gameplay.
- `Variant_Combat/CombatCharacter`: melee combat and damage systems.
- `Variant_SideScrolling`: side-scrolling gameplay, pickups, platforms, and StateTree AI.

## Development

- Open the project in Unreal Editor to edit levels, Blueprints, and assets.
- Modify C++ gameplay code in `Source/ShooterSam`, then compile the module from Unreal Editor or Visual Studio.
- Input is configured in `Content/Input` and connected to Enhanced Input in the player characters/controllers.
- Do not commit generated directories such as `Binaries/`, `Intermediate/`, `DerivedDataCache/`, and `Saved/`.

## Status

The project is under active development and may change. Some classes or assets may still be experimental.

## License

No separate license is currently included in the repository. Add a `LICENSE` file if the project is distributed to third parties.
