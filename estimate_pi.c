/*
* Author: Simão Sanguinho
* Filename: estimate_pi.c
* Description: the program estimates the constant pi - it creates n_points in a
* cartesian plane with 0 <= x and y <= 1, using the ratio of the the points 
* inside the quarter of a circle (centre on the origin and radius 1) and the 
* total number of points to get to the value of pi 
* link for video: https://www.youtube.com/watch?v=pvimAM_SLic
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define N_POINTS 100   /* number of points used to estimate pi */

typedef struct {
    float x;
    float y;
    float dist;
} Point;


/* returns a number between 0 and 1 randomly distributed */
double r2()
{
    return (double)rand() / (double)((unsigned)RAND_MAX+1) ;
}

/* calculates the distance between a point and the origin (0,0) */
float modulus(Point p)
{
    return(sqrt(p.x*p.x + p.y*p.y));
}

/* creates a new point */
Point newPoint()
{
    Point p;
    p.x = r2();
    p.y = r2();
    p.dist = modulus(p);

    return p;
}

/* estimates the value of the constant pi */
float estimate_pi(int n_points)
{
    int n = 0;
    Point  p;
    int num_points_tot = 0;
    int num_points_in = 0;

    while(n < n_points)
    {
        p = newPoint();
        if(p.dist <= 1)
            num_points_in++;

        num_points_tot++;

        n++;
    }

    return 4*num_points_in/ (float) num_points_tot;
}

int main()
{
    float pi;
    int num_points;

    printf("How many points do you want to use?\n");
    scanf("%d",&num_points);

    /* makes it random outcome different every time program is executed */
    srand(time(0));

    pi = estimate_pi(num_points);
    printf("Estimated value for PI: %f\n", pi);

    return 0;
}