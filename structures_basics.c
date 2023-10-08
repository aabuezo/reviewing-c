#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define MAX_DIMENSIONS 3

/* Struct Declaration */
struct GuyStruct
{
    char *name;
    bool active;
    int dimensions;
    double pos[MAX_DIMENSIONS]; // in general you cannot use incomplete arrays, but...
};                              // see Flexible Array Member

/* Aliasing the type with typedef (anonymous struct) */
typedef struct
{
    char *name;
    bool active;
    int dimensions;
    double pos[MAX_DIMENSIONS];
} GuyAnonymous;

/* Aliasing the type with typedef (good practice) */
typedef struct Guy
{
    char *name;
    bool active;
    int dimensions;
    double pos[MAX_DIMENSIONS];
    struct Guy *friend;
} Guy;

typedef struct Motorcycle
{
    char *model;
    double speed;
    Guy owner;
} Motorcycle;

double calc_distance(int dimensions, double a[dimensions], double b[dimensions])
{
    double square_distance = 0;
    for (int i = 0; i < dimensions; i++)
    {
        square_distance += pow(a[i] - b[i], 2);
    }
    return sqrt(square_distance);
}

int main()
{
    /* Let's calculate the distance between two guys */

    /* Implicit initialization */
    Guy elon = {
        "Elon Musk",
        true,
        3,
        {1, 2, 3}};

    /* Explicit initialization */
    Guy bill = {
        .name = "Bill Gates",
        .pos = {3, 2, 1},
        .dimensions = 3,
        .active = true,
    };

    /* Pointer to a structure */
    Guy *pGuy = &bill;
    printf("%s\n", pGuy->name);     // Arrow operator
    printf("%s\n", (*pGuy).name);   

    Motorcycle moto = {
        .model = "honda",
        .speed = 100,
        .owner = {
            .name = "Andrea",
            .dimensions = 3,
            .active = true,
            .pos = {0, 0, 0}},
    };

    /* Copy a whole structure with = */
    Guy anotherGuy = {.name = "someone", .active=false};
    anotherGuy = bill;

    printf("anotherGuy.name = %s\n", anotherGuy.name);

    if (!elon.active || !bill.active)
    {
        printf("%s isn't active now!\n", !elon.active ? elon.name : bill.name);
        return EXIT_FAILURE;
    }

    if (elon.dimensions != bill.dimensions)
    {
        printf("%s and %s are in different dimensions!\n", elon.name, bill.name);
        return EXIT_FAILURE;
    }

    printf("The distance between %s and %s is: %.1f\n",
            elon.name, bill.name, calc_distance(elon.dimensions, elon.pos, bill.pos));

    printf("And a %s motorcycle is running at %.1f km/h and is driven by %s\n",
            moto.model, moto.speed, moto.owner.name);

    moto = (Motorcycle){.model = "Ducati", .speed = 200};

    printf("And a %s motorcycle is running at %.1f km/h and is driven by %s\n",
            moto.model, moto.speed, moto.owner.name);


    /* Walking a single linked list */
    Guy *firstGuy = &bill;
    firstGuy->friend = malloc(sizeof(Guy));
    firstGuy->friend->name = "Elon Musk";
    firstGuy->friend->active = false;

    /* Go through the list... */
    firstGuy->friend->friend = malloc(sizeof(Guy));
    firstGuy->friend->friend->name = "Andrea";

    /* Allocating an array of guys */
    int num = 10;
    Guy *manyGuys = malloc(10 * sizeof(Guy));   // Ten element array of Guys

    manyGuys[0].name = "Mario";
    manyGuys[0].friend = &bill;

    /* Accessing the 2nd element of manyGuys using pointers */
    (manyGuys + 1)->name = "Tom";
    printf("manyGuys[1].name = %s\n", manyGuys[1].name);

    return EXIT_SUCCESS;
}