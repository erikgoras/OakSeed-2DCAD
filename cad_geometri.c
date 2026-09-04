#include <stdio.h>

// Define struct for a point
typedef struct {
    int x;
    int y;
} Point;

// Define struct for a line
typedef struct {
    Point start;
    Point end;
} Line;

// Define struct for a circle
typedef struct {
    Point center;
    int radius;
} Circle;

// Function to save line and circle to a CSV file
void saveToCSV(Line line, Circle circle, const char *filename) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        perror("Error opening file");
        return;
    }

    // Write line to file
    fprintf(file, "%d,%d,%d,%d\n", line.start.x, line.start.y, line.end.x, line.end.y);

    // Write circle to file
    fprintf(file, "%d,%d,%d\n", circle.center.x, circle.center.y, circle.radius);

    fclose(file);
}

int main() {
    // Create a line
    Line myLine = { {1, 2}, {3, 4} };

    // Create a circle
    Circle myCircle = { {5, 6}, 7 };

    // Save line and circle to a CSV file
    saveToCSV(myLine, myCircle, "data.csv");

    return 0;
}
