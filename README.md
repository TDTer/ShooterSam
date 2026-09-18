# ShooterSam
# ShooterSam

My Unreal Engine 5.6 third-person shooter project. The gameplay and assets I developed are organized under `Content/MyStuff`.

## MyStuff

The `MyStuff` folder contains the playable shooter setup:

- `AI/` — enemy Blackboard, Behavior Tree, and shooter AI Blueprint.
- `Animation/` — shooter character animation Blueprint and locomotion blend space.
- `Blueprints/` — player, shooter character, rifle, GameMode, PlayerController, and HUD Blueprints.
- `Map/MainLevel.umap` — the main playable level.
- `SFX/` — rifle shot and rifle impact sounds.

## Running the Project

Requirements:

- Unreal Engine **5.6**.
- Visual Studio 2022 with the **Game development with C++** workload.
- Windows 64-bit.

1. Clone the repository:

   ```bash
   git clone https://github.com/TDTer/ShooterSam.git
   cd ShooterSam
   ```

2. Open `ShooterSam.uproject` in Unreal Editor 5.6.
3. Open `Content/MyStuff/Map/MainLevel`.
4. Click **Play** to run the game.

## Project Layout

```text
Content/MyStuff/
??? AI/             # Enemy AI assets
??? Animation/      # Character animation assets
??? Blueprints/     # Gameplay and UI Blueprints
??? Map/            # Main playable level
??? SFX/            # Shooter sound effects
```

## Development

Assets created for this project are kept in `Content/MyStuff` to distinguish them from the other Unreal Engine sample content included in the repository.
