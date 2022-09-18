// CS-100 Project 2: p2.c
// by: Maddox Guthrie

#include <stdio.h>
#include <string.h>

int main() {
    char strInput[16];
    int numInput;
    
    // North branch
    printf("north, south, east, or west: ");
    scanf("%s", strInput);
    if(!strcmp(strInput, "north")) {
        printf("enter a positive integer: ");
        scanf("%d", &numInput);
        if(numInput % 2 == 0) {
            printf("yes or no: ");
            scanf("%s", strInput);
            if(!strcmp(strInput,"yes")) {
                printf("lake\n");

            } else if(!strcmp(strInput,"no")) {
                printf("pool\n");

            }

        } else if(numInput % 2 != 0) {
            printf("beach\n");

        }
    }

    // South branch
    if(!strcmp(strInput, "south")) {
        printf("left or right: ");
        scanf("%s", strInput);
        if(!strcmp(strInput,"left")) {
            printf("jog\n");

        } else if(!strcmp(strInput,"right")) {
            printf("fast or slow: ");
            scanf("%s", strInput);
            if(!strcmp(strInput,"fast")) {
                printf("bike\n");

            } else if(!strcmp(strInput,"slow")) {
                printf("big or small: ");
                scanf("%s", strInput);
                if(!strcmp(strInput,"big")) {
                    printf("run\n");

                } else if(!strcmp(strInput,"small")) {
                    printf("walk\n");

                }
            }
        }
    }

    // East branch
    if(!strcmp(strInput, "east")) {
        printf("red, white, or gray: ");
        scanf("%s", strInput);
        if(!strcmp(strInput, "red")) {
            printf("yes or no: ");
            scanf("%s", strInput);
            if(!strcmp(strInput,"yes")) {
                printf("tree-climb\n");

            } else if(!strcmp(strInput,"no")) {
                printf("up or down: ");
                scanf("%s", strInput);
                if(!strcmp(strInput,"up")) {
                    printf("top-rope\n");

                } else if(!strcmp(strInput,"down")) {
                    printf("boulder\n");

                }
            }

        } else if(!strcmp(strInput, "white")) {
            printf("easy or hard:");
            scanf("%s", strInput);
            if(!strcmp(strInput, "easy")) {
                printf("longboard\n");

            } else if(!strcmp(strInput, "hard")) {
                printf("workout\n");

            }

        } else if(!strcmp(strInput, "gray")) {
            printf("left, center, or right: ");
            scanf("%s", strInput);
            if(!strcmp(strInput, "left")) {
                printf("build or destroy: ");
                scanf("%s", strInput);
                if(!strcmp(strInput, "build")) {
                    printf("hike\n");

                } else if(!strcmp(strInput, "destroy")) {
                    printf("spelunk\n");

                }

            } else if(!strcmp(strInput, "center")) {
                printf("open or closed: ");
                scanf("%s", strInput);
                if(!strcmp(strInput, "open")) {
                    printf("zoo\n");

                } else if(!strcmp(strInput, "closed")) {
                    printf("aquarium\n");

                }

            } else if(!strcmp(strInput, "right")) {
                printf("museum\n");

            }
        }
    }

    // West branch
    if(!strcmp(strInput, "west")) {
        printf("enter an integer: ");
        scanf("%d", &numInput);
        if(numInput >= 0) {
            printf("frisbee");

        } else if(numInput < 0) {
            printf("sunny or cloudy: ");
            scanf("%s", strInput);
            if(!strcmp(strInput, "sunny")) {
                printf("tennis\n");

            } else if(!strcmp(strInput, "cloudy")) {
                printf("racquetball\n");

            }
        }
    }

    return 0;
}