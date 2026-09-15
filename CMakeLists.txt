cmake_minimum_required(VERSION 3.10)
project(jogo-terminal-c)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

add_executable(jogo-terminal-c
  /home/wallace_dev/segundo-cerebro/01_Projects/jogo-terminal-c/src/combat.c
  /home/wallace_dev/segundo-cerebro/01_Projects/jogo-terminal-c/src/entity.c
  /home/wallace_dev/segundo-cerebro/01_Projects/jogo-terminal-c/src/entitys.c
  /home/wallace_dev/segundo-cerebro/01_Projects/jogo-terminal-c/src/game.c
  /home/wallace_dev/segundo-cerebro/01_Projects/jogo-terminal-c/src/input.c
  /home/wallace_dev/segundo-cerebro/01_Projects/jogo-terminal-c/src/main.c
  /home/wallace_dev/segundo-cerebro/01_Projects/jogo-terminal-c/src/render.c
  /home/wallace_dev/segundo-cerebro/01_Projects/jogo-terminal-c/src/update.c
)