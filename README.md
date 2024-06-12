# 42 - Cub3d

![42 School](https://img.shields.io/badge/42%20School-Project-blue)
![Git](https://img.shields.io/badge/Git-F05032?logo=git&logoColor=white)
![C](https://img.shields.io/badge/C-A8B9CC?logo=c&logoColor=white)
![Grade](https://img.shields.io/badge/Grade-105-brightgreen)

## Description

Cub3d is a project from 42 School that involves creating a 3D graphical representation of a maze using raycasting techniques in C. The goal of this project is to gain a deeper understanding of how raycasting works and to develop advanced programming skills in C and graphics programming.

## Features

- Real-time rendering of a 3D maze using raycasting.
- Textured walls and sprites.
- Player movement and collision detection.

## Requirements

- Unix-based operating system (Linux or macOS)
- GCC compiler
- MLX42 library for graphics (provided by 42 School)
- In Linux:

    ```sh
    sudo apt install build-essential libx11-dev libglfw3-dev libglfw3 xorg-dev
    ```

## Installation

1. Clone the repository:

    ```sh
    git clone https://github.com/pablovilchez/42-cub3d.git
    ```

2. Navigate to the project directory:

    ```sh
    cd cub3d
    ```

3. Compile the project:

    ```sh
    make
    ```

## Usage

Run the program by executing the following command:

```sh
./cub3d [map_file.cub]
```

## Example

```sh
./cub3d maps/map.cub
```

## Controls

- Move forward: W
- Move backward: S
- Strafe left: A
- Strafe right: D
- Rotate left: Left arrow
- Rotate right: Right arrow
- Exit the program: ESC

## Co-author

- **Davyd** - [github.com/BredyByte](https://github.com/gkrusta)

## License

This project is licensed under the MIT License.

## Acknowledgments

- Thanks to 42 School for the project guidelines and support.
- Special thanks to my teammate Davyd for his incredible effort, hard work, and for putting up with me throughout the project.

---
