#include "termily.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Variable to store the player's score
i16 score;

// Text buffer to display the player's score
char text[64];

// Graphics struct used for rendering to the screen
graph_t graph;

// Actor representing the player
actor_t player;

// Actor representing the coin
actor_t coin;

int main(int argc, char* argv[]) {
    // Seed the random number generator using the current time
    srand(time(NULL));

    // Create a window for graphics with dimensions 30x15 characters
    makeGraph(&graph, 30, 15);

    // Create an actor for the player. The player is represented by the character '+'
    // The actor will be added to the graph when a draw call occurs
    makeActor(&player, &graph, '+');

    // Create an actor for the coin. The coin is represented by the character '0'
    // The actor will be added to the graph when a draw call occurs
    makeActor(&coin, &graph, '0');

    // Set the initial position of the player to the middle of the screen
    setPos(&player, 15, 7);

    // Set the initial position of the coin to a random position within the graph boundaries
    setPos(&coin, rand() % (27 - 3 + 1) + 3, rand() % (13 - 3 + 1) + 3);

    // Game loop
    while (1) {
        // Check user input and update player position accordingly
        if (checkKeyDown(&key_up)) {
            player.y--;
        }
        if (checkKeyDown(&key_down)) {
            player.y++;
        }
        if (checkKeyDown(&key_left)) {
            player.x--;
        }
        if (checkKeyDown(&key_right)) {
            player.x++;
        }
    
        // Check if the player collides with the coin
        if (checkCollide(&player, &coin)) {
            // If collision occurs, move the coin to a new random position within the graph boundaries
    		setPos(&coin, rand() % (27 - 3 + 1) + 3, rand() % (13 - 3 + 1) + 3);
            // Increment the player's score
            score++;
        }

		printf("%d %d", coin.x, coin.y);
        // Generate text to display the player's score
        sprintf_s(text, sizeof(text), "score %d", score);
        // Render the score text to the screen
        drawText(&graph, text, 1, 1);
        // Render player and coin actors to the screen
        drawActor(&player);
        drawActor(&coin);
        // Draw the entire screen
        drawGraphic(&graph);
        // Clear the screen before the next frame
        clearScreen(&graph);
        // Sleep for a short duration to stabilize frame rate (optional)
        Sleep(5);
    }   
    
    return 0;
}

