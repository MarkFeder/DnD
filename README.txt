# Unreal Engine 5.4 Project

## Project Title
Codename: DnD (Dragons & Dungeons)

## Description
UI/UX Frontend Engineer test for CaptureAge (2024).

## Table of Contents
- [Getting Started]
  - [Prerequisites]
  - [Installation]
- [Usage]
- [Structure]
- [License] No license attached.

## Getting Started

### Prerequisites
- Win10/Win11 32/64 bits.
- Unreal Engine 5.4.3
- Visual Studio 2022 // SDK requirements specified on Epic Games official website.
- Git (latest version)

### Installation
- Install Unreal Engine 5.4.3 through Epic Games Launcher (https://www.unrealengine.com/en-US/download).
- Clone the repository to your local machine through git (https://github.com/MarkFeder/DnD).
	git clone https://github.com/MarkFeder/DnD.git
- Right-click on DnD.uproject - Generate Visual Studio Project Files.
- Open DnD.sln (VS solution) in Visual Studio 2022
- Select DnD as Startup project
- Compile/Build Solution Win64 Debug Editor
- Run DnD project

## Usage
- Run DnD project in VS generated solution (F5 key) specified on ###Installation
- Wait for Unreal Editor - DnD to be loaded up in screen.
- Click on |> "Play Button" at the top left (green arrow) to launch the PIE instance.
- If you want to play in another window and not in editor's embeeded screen, then click on the 3 dots piled next to play button and click on "New Editor Window"
- Turn on the volume to enjoy the background music and for the "clicked" events.

## Structure

The Content is structured in the following folders:

- Audio: contains all the audio assets.
- Core: contains the BP assets for the HUD and basic Game Mode.
- Data: contains all the data assets required by the UI that represents a character: name, portrait, preview, race, class and ability scores.
- Levels: contains the available level in the project.
- Textures: contains the referenced textures for portraits / previews for each character.
- UI: contains all the BP required for the HUD, main screen, buttons, selection screen, etc.

## License
No license attached.