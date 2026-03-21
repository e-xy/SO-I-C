/* --------------- C U B E --------------- */

/* @@@@@@@@@@@@@@@@@@@@@@@@@@@
 * @@@@@@@@@@@@@@@@@@@@@@@@@@@
 * @@@@@@@@@@@@@@@@@@@@@@@@@@@
 * @@@@@@@@@@@@@@@@@@@@@@@@@@@
 * @@@@@@@@@@@@@@@@@@@@@@@@@@@
 * @@@@@@@@@@@@@@@@@@@@@@@@@@@
 * @@@@@@@@@@@@@@@@@@@@@@@@@@@
 * @@@@@@@@@@@@@@@@@@@@@@@@@@@
 * @@@@@@@@@@@@@@@@@@@@@@@@@@@
 * @@@@@@@@@@@@@@@@@@@@@@@@@@@
 * @@@@@@@@@@@@@@@@@@@@@@@@@@@
 * @@@@@@@@@@@@@@@@@@@@@@@@@@@
 */


/* --------------- C U B E --------------- */


/* --------------- Includes n Config --------------- */
#include <stdio.h>
#include <time.h>
#include <stdbool.h>
#include <unistd.h>
#include <signal.h>

#define CLEAR_CODE "\033[2J\033[H"
#define LINE_CODE "\033[2K\r"
#define BOLD "\033[1m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"
#define RESET "\033[0m"

#define FRAME_RATE 30

double f_time;
volatile int running = 1;
int canvas[100][100];
/* --------------- END Includes n Config --------------- */

/* clear this shit */
void clear()
{
	printf("\033[2J\033[H");
	//printf("\033[0m");
	fflush(stdout);	
}

/* handling signal interrupts */
void hdl_sigint(int sig)
{
	running = 0;
}

/* bold logs */
void r_log(char *msg, bool is_bold)
{
	if (is_bold)
	{
		printf(BOLD RED "%s" RESET "\n", msg);
	}
	else
	{
		printf(RED "%s" RESET "\n", msg);
	}
}

/* shows the pre-cube screen */
void display_warning()
{
	clear();
	r_log("WARNING: this program does not have an external stop switch.", true); 
	sleep(2);
	r_log("use your system's termination key to stop the cube!", false);
	sleep(2);
	r_log("the cube will appear in:", false);
	int cnt = 5;
	while(cnt > 0 && running)
	{
		printf("%d", cnt);
		fflush(stdout);
		sleep(1);
		printf(LINE_CODE);
		cnt--;
	}
}

/* some basic stuff for a R^3 point and vector, ijk unit vectors */
struct Pt3
{
	float x;
	float y;
	float z;
};

struct Vec3 
{
	float x_i;
	float y_j;
	float z_k;
};

struct Line3
{
	struct Pt3 r_0;
	struct Vec3 v;
};

/* make a new R^3 line seg
 * Pt3  r_0 <- starting pt
 * Vec3   v <- directional vec
 * Line3  l -> line segment  */
struct Line3 make_line(struct Pt3 r_0, struct Vec3 v)
{
	struct Line3 l;
	l.r_0 = r_0;
	l.v = v;
	return l;
}

/* calculate & get pt on R^3 line
 * Line3 l <- line eq you want to use
 * float t <- scale factor
 * Pt3   r -> r calculated from line seg */
struct Pt3 get_r(struct Line3 l, float t)
{
	struct Pt3 r;
	r.x = l.r_0.x + t * l.v.x_i;
	r.y = l.r_0.y + t * l.v.y_j;
	r.z = l.r_0.z + t * l.v.z_k;
	return r;
}

/* displays spinning cube doesn't
   have a safety check yet */
void display_cube()
{
	f_time = 1.0 / FRAME_RATE;
	int n = 0;
	while (running)		/* run until interrupt */
	{
		printf("%d\n", n);
		clear();
		n++;
	}
}

int main()
{
	signal(SIGINT, hdl_sigint);
	display_warning();
	display_cube();
	// printf("%f\n", f_time);
	
	clear();
	return 0;
}
