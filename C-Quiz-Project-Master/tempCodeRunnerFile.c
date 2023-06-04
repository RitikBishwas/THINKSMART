#include <stdio.h>
#include <unistd.h>

// ANSI escape codes for text colors
#define COLOR_RED     "\x1b[31m"
#define COLOR_GREEN   "\x1b[32m"
#define COLOR_YELLOW  "\x1b[33m"
#define COLOR_CYAN    "\x1b[36m"
#define COLOR_RESET   "\x1b[0m"

void animate() {
    int position = 0;
    int direction = 1;
    const char* colors[] = {COLOR_RED, COLOR_GREEN, COLOR_YELLOW, COLOR_CYAN};

    for (int i = 0; i < 40; i++) {  // Number of animation frames
        // Clear the previous frame by using ANSI escape code
        printf("\033[2J\033[H");

        // Print the character at the current position with alternating colors
        for (int j = 0; j < position; j++)
            printf(" ");
        printf("%s _    _      _     _____ _          _ _ \n", colors[i % 4]);
        for (int j = 0; j < position; j++)
            printf(" ");
        printf("| |  | |    | |   |_   _| |        | | |\n");
        for (int j = 0; j < position; j++)
            printf(" ");
        printf("| |  | |_ __| |__   | | | |__   ___| | |\n");
        for (int j = 0; j < position; j++)
            printf(" ");
        printf("| |  | | '__| '_ \\  | | | '_ \\ / _ \\ | |\n");
        for (int j = 0; j < position; j++)
            printf(" ");
        printf("| |__| | |  | |_) | |_| | | | |  __/ | |\n");
        for (int j = 0; j < position; j++)
            printf(" ");
        printf(" \\____/|_|  |_.__/ \\___/|_| |_|\\___|_|_|\n" COLOR_RESET);

        // Update the position
        position += direction;

        // Reverse direction if reaching the edge of the screen
        if (position >= 20 || position <= 0)
            direction = -direction;

        // Delay for a short time between frames
        usleep(100000);  // Delay for 0.1 seconds (100,000 microseconds)
    }
}

int main() {
    animate();

    return 0;
}
