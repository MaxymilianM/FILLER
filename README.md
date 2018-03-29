# FILLER
Mini-game Filler. The concept is simple: two players gain points by placing on a board, one after the other, the game piece obtained by the game master (in the form of an executable Ruby program). The game ends when the game piece cannot be placed anymore. I realized my own bot "mminenko.filler" and create a visualizer to this mini-game.

To start the game you need to compile all files (use "make") and write this command in terminal:
./filler_vm -f ./resources/maps/map02 -p1 ./resources/players/mminenko.filler -p2 ./resources/players/carli.filler
If you want visualized it add "| ./visual/visualizer" at the end.
