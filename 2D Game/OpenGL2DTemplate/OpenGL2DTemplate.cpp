#include <vector>
#include <utility>
#include <algorithm>
#include <iostream>
#include <glut.h>

void Display();
void timer(int);
void key(unsigned char,int,int);
float enemy_pos = 500-60;
float player_pos = 460;
float player_posy = 100;
int powerupno = 8;
int enemy_health = 5;
int player_health = 3;
int enemy_direction = 1;
double bullet = 100;
int shoot = 0;
std::vector <std::pair<double,double> > bulletsk;
std::vector <std::pair<double, double> > enemy_bulletsk;
std::vector <std::pair<double, double> > power_ups;
int timera = 0;
int won = 0;
int lost = 0;
int poweredup = 0;
int poweredupt = 0;

int randomNum();


void main(int argc, char** argr) {
	glutInit(&argc, argr);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(1000, 600);
	glutInitWindowPosition(50, 50);
	std::srand(std::time(nullptr));

	glutCreateWindow("chicken game");
	glutDisplayFunc(Display);
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glPointSize(9.0);
	//glLineWidth(9.0);
	glutTimerFunc(0,timer,0);
	glutKeyboardFunc(key);			//call the keyboard function
	gluOrtho2D(0.0, 1000.0, 0.0, 600.0);
	glutMainLoop();
}

void Display() {
	glClear(GL_COLOR_BUFFER_BIT);
	glPushMatrix();
	glBegin(GL_POINTS);
	glColor3f(1.0f, 0.7f, 0.0f);
	if (powerupno==1) {
		glVertex3f(250.0f, 200.0f, 0.0f);

	}
	if (powerupno == 2) {
		glVertex3f(450.0f, 200.0f, 0.0f);

	}
	if (powerupno == 3) {
		glVertex3f(650.0f, 200.0f, 0.0f);

	}
	if (powerupno == 4) {
		glVertex3f(150.0f, 300.0f, 0.0f);

	}
	if (powerupno == 5) {
		glVertex3f(350.0f, 300.0f, 0.0f);

	}
	if (powerupno == 6) {
		glVertex3f(750.0f, 300.0f, 0.0f);

	}
	if (powerupno == 7) {
		glVertex3f(550.0f, 300.0f, 0.0f);

	}

	glEnd();
	glPopMatrix();



	glPushMatrix();

	glTranslatef(750.0f, 550.0f, 0.0f);
	glScalef(0.4f, 0.8f, 1.0f);
	glBegin(GL_POLYGON);
	glColor3f(1.0f, 1.0f, 1.0f);

	glVertex3f(-460.0f,0.0f, 0.0f);
	glVertex3f(-460.0f, 30.0f, 0.0f);
	glVertex3f(460.0f, 30.0f, 0.0f);
	glVertex3f(460.0f, 0.0f, 0.0f);
	glEnd();
	if (enemy_health==5) {
		glBegin(GL_POLYGON);
		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex3f(-450.0f, 5.0f, 0.0f);
		glVertex3f(-450.0f, 25.0f, 0.0f);
		glVertex3f(450.0f, 25.0f, 0.0f);
		glVertex3f(450.0f, 5.0f, 0.0f);
		glEnd();
	}
	if (enemy_health == 4) {
		glBegin(GL_POLYGON);
		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex3f(-270.0f, 5.0f, 0.0f);
		glVertex3f(-270.0f, 25.0f, 0.0f);
		glVertex3f(450.0f, 25.0f, 0.0f);
		glVertex3f(450.0f, 5.0f, 0.0f);
		glEnd();
	}
	if (enemy_health == 3) {
		glBegin(GL_POLYGON);
		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex3f(-90.0f, 5.0f, 0.0f);
		glVertex3f(-90.0f, 25.0f, 0.0f);
		glVertex3f(450.0f, 25.0f, 0.0f);
		glVertex3f(450.0f, 5.0f, 0.0f);
		glEnd();
	}
	if (enemy_health == 2) {
		glBegin(GL_POLYGON);
		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex3f(90.0f, 5.0f, 0.0f);
		glVertex3f(90.0f, 25.0f, 0.0f);
		glVertex3f(450.0f, 25.0f, 0.0f);
		glVertex3f(450.0f, 5.0f, 0.0f);
		glEnd();
	}
	if (enemy_health == 1) {
		glBegin(GL_POLYGON);
		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex3f(270.0f, 5.0f, 0.0f);
		glVertex3f(270.0f, 25.0f, 0.0f);
		glVertex3f(450.0f, 25.0f, 0.0f);
		glVertex3f(450.0f, 5.0f, 0.0f);
		glEnd();
	}
	glPopMatrix();

	glPushMatrix();
	glTranslatef(250.0f, 550.0f, 0.0f);
	glScalef(0.4f, 0.8f, 1.0f);
	glBegin(GL_POLYGON);
	glColor3f(1.0f, 1.0f, 1.0f);

	glVertex3f(-460.0f, 0.0f, 0.0f);
	glVertex3f(-460.0f, 30.0f, 0.0f);
	glVertex3f(460.0f, 30.0f, 0.0f);
	glVertex3f(460.0f, 0.0f, 0.0f);
	glEnd();
	if (poweredup ==1) {
		glColor3f(1.0f, 0.7f, 0.0f);

	}else{
		glColor3f(0.0f, 1.0f, 0.0f);
	}

	if (player_health==3) {
		glBegin(GL_POLYGON);
		
		glVertex3f(-450.0f, 5.0f, 0.0f);
		glVertex3f(-450.0f, 25.0f, 0.0f);
		glVertex3f(450.0f, 25.0f, 0.0f);
		glVertex3f(450.0f, 5.0f, 0.0f);
		glEnd();
	}

	if (player_health == 2) {
		glBegin(GL_POLYGON);
		
		glVertex3f(-450.0f, 5.0f, 0.0f);
		glVertex3f(-450.0f, 25.0f, 0.0f);
		glVertex3f(150.0f, 25.0f, 0.0f);
		glVertex3f(150.0f, 5.0f, 0.0f);
		glEnd();
	}
	if (player_health == 1) {
		glBegin(GL_POLYGON);
		if (poweredup == 1) {
			glColor3f(1.0f, 0.7f, 0.0f);

		}
		else {
			glColor3f(1.0f, 0.0f, 0.0f);
		}		glVertex3f(-450.0f, 5.0f, 0.0f);
		glVertex3f(-450.0f, 25.0f, 0.0f);
		glVertex3f(-150.0f, 25.0f, 0.0f);
		glVertex3f(-150.0f, 5.0f, 0.0f);
		glEnd();
	}
	glPopMatrix();


	//bullet				jjjj															jjjjjjj	jjjjjjj
	for (auto& x : bulletsk) {
		glPushMatrix();

		glBegin(GL_POINTS);
		glColor3f(0.3f, 0.8f, 1.0f);
		if (!won) {
			glVertex3f(x.first, x.second, 0.0f);
		}
		glEnd();
		glPopMatrix();
	}
	
	for (auto& x : enemy_bulletsk) {
		glPushMatrix();

		glBegin(GL_POINTS);
		glColor3f(1.0f, 0.0f, 0.0f);
		if (!won) {
			glVertex3f(x.first, x.second, 0.0f);
		}
		glEnd();
		glPopMatrix();
	}
	

	glPushMatrix();
	
	glTranslatef(player_pos, player_posy, 0.0f);
	glScalef(0.7, 0.7, 1);
	glColor3f(0.0f, 0.50f, 1.0f);
	glBegin(GL_POLYGON);
	glVertex3f(5.0f, 60.0f, 0.0f);
	glVertex3f(25.0f, 60.0f, 0.0f);
	glVertex3f(25.0f, 95.0f, 0.0f);
	glVertex3f(5.0f, 95.0f, 0.0f);
	glEnd();

	if (player_health==1) {
		glColor3f(0.55f, 0.55f, 0.55f);

	}
	else if (player_health == 2) {
		glColor3f(0.65f, 0.65f, 0.65f);

	}
	else {
		glColor3f(0.75f, 0.75f, 0.75f);
	}
	glBegin(GL_POLYGON);
	glVertex3f(0.0f, 0.0f, 0.0f);
	glVertex3f(30.0f, 0.0f, 0.0f);
	glVertex3f(30.0f, 100.0f, 0.0f);
	glColor3f(0.8f, 0.8f, 0.8f);
	glVertex3f(15.0f, 130.0f, 0.0f);
	glVertex3f(0.0f, 100.0f, 0.0f);
	glEnd();
	
	/*/
	glBegin(GL_POLYGON);
	glVertex3f(-30.0f, -40.0f, 0.0f);
	glVertex3f(60.0f, -40.0f, 0.0f);
	glVertex3f(60.0f, -60.0f, 0.0f);
	glVertex3f(-30.0f, -60.0f, 0.0f);
	glEnd();
	if (player_health == 3) {
		glBegin(GL_POLYGON);
		glColor3f(0.0f, 0.9f, 0.0f);

		glVertex3f(-25.0f, -45.0f, 0.0f);
		glVertex3f(55.0f, -45.0f, 0.0f);
		glVertex3f(55.0f, -55.0f, 0.0f);
		glVertex3f(-25.0f, -55.0f, 0.0f);
		glEnd();
	}

	if (player_health == 2) {
		glBegin(GL_POLYGON);
		glColor3f(0.0f, 0.9f, 0.0f);

		glVertex3f(-25.0f, -45.0f, 0.0f);
		glVertex3f(25.0f, -45.0f, 0.0f);
		glVertex3f(25.0f, -55.0f, 0.0f);
		glVertex3f(-25.0f, -55.0f, 0.0f);
		glEnd();
	}

	if (player_health == 1) {
		glBegin(GL_POLYGON);
		glColor3f(1.0f, 0.0f, 0.0f);

		glVertex3f(-25.0f, -45.0f, 0.0f);
		glVertex3f(-5.0f, -45.0f, 0.0f);
		glVertex3f(-5.0f, -55.0f, 0.0f);
		glVertex3f(-25.0f, -55.0f, 0.0f);
		glEnd();
	}
	//*/
	if (player_health==3) {
		glBegin(GL_POLYGON);
		glColor3f(0.9f, 0.9f, 0.9f);
		glVertex3f(30.0f, 50.0f, 0.0f);
		glVertex3f(55.0f, 20.0f, 0.0f);
		glVertex3f(55.0f, -30.0f, 0.0f);
		glVertex3f(30.0f, 0.0f, 0.0f);
	}
	if (player_health == 2 || player_health == 1) {
		glBegin(GL_POLYGON);
		glColor3f(0.5f, 0.5f, 0.5f);
		glVertex3f(30.0f, 50.0f, 0.0f);
		glVertex3f(55.0f, 20.0f, 0.0f);
		glVertex3f(55.0f, -30.0f, 0.0f);
		glVertex3f(30.0f, 0.0f, 0.0f);
	}
	

	if (player_health==1||player_health==2) {
		glColor3f(0.5f, 0.5f, 0.5f);
	}
	else {
		glColor3f(0.9f, 0.9f, 0.9f);
	}
	
	glEnd();
	glBegin(GL_POLYGON);
	//glColor3f(0.9f, 0.9f, 0.9f);
	glVertex3f(0.0f, 50.0f, 0.0f);
	glVertex3f(-25.0f, 20.0f, 0.0f);
	glVertex3f(-25.0f, -30.0f, 0.0f);
	glVertex3f(0.0f, 0.0f, 0.0f);


	glEnd();
	glColor3f(0.7f, 0.7f, 1.0f);
	if (player_health == 3) {
		glBegin(GL_POLYGON);
		glVertex3f(5.0f, 60.0f, 0.0f);
		glVertex3f(25.0f, 60.0f, 0.0f);
		glColor3f(0.3f, 0.50f, 1.0f);
		glVertex3f(25.0f, 95.0f, 0.0f);
		glVertex3f(15.0f, 110.0f, 0.0f);
		glVertex3f(5.0f, 95.0f, 0.0f);
		glEnd();
	}

	if (player_health == 2 || player_health==1) {
		glBegin(GL_POLYGON);
		glVertex3f(5.0f, 60.0f, 0.0f);
		glVertex3f(25.0f, 60.0f, 0.0f);
		glColor3f(0.3f, 0.50f, 1.0f);
		glVertex3f(25.0f, 95.0f, 0.0f);
		glColor3f(0.75f, 0.75f, 0.75f);
		glVertex3f(15.0f, 110.0f, 0.0f);
		glVertex3f(5.0f, 95.0f, 0.0f);
		glEnd();
	}

	if (player_health == 1) {
		glBegin(GL_POLYGON);
		glVertex3f(5.0f, 60.0f, 0.0f);
		glColor3f(0.75f, 0.75f, 0.75f);

		glVertex3f(25.0f, 60.0f, 0.0f);
		glColor3f(0.3f, 0.50f, 1.0f);
		glVertex3f(25.0f, 95.0f, 0.0f);
		glColor3f(0.75f, 0.75f, 0.75f);
		glVertex3f(15.0f, 110.0f, 0.0f);
		glVertex3f(5.0f, 95.0f, 0.0f);
		glEnd();
	}
	

	glEnd();
	glColor3f(0.4f, 0.4f, 0.4f);
	glBegin(GL_POLYGON);
	glVertex3f(5.0f, 0.0f, 0.0f);
	glVertex3f(25.0f, 0.0f, 0.0f);
	glVertex3f(30.0f, -10.0f, 0.0f);
	glVertex3f(0.0f, -10.0f, 0.0f);
	glEnd();


	glPopMatrix();
	
	


	glPushMatrix();

	glTranslatef(enemy_pos, 400, 0.0f);

	glScalef(1.6, 1.6, 1);

	glColor3f(0.4f, 0.4f, 0.4f);
	glBegin(GL_POLYGON);

	
	glVertex3f(0.0f, 0.0f, 0.0f);
	glVertex3f(50.0f, 0.0f, 0.0f);
	glVertex3f(50.0f, 50.0f, 0.0f);
	glVertex3f(0.0f, 50.0f, 0.0f);

	glEnd();

	glBegin(GL_POLYGON);


	glVertex3f(-20.0f, -15.0f, 0.0f);
	glVertex3f(-35.0f, -15.0f, 0.0f);
	glVertex3f(-35.0f, 75.0f, 0.0f);
	glVertex3f(-20.0f, 75.0f, 0.0f);

	glEnd();

	glBegin(GL_POLYGON);


	glVertex3f(70.0f, -15.0f, 0.0f);
	glVertex3f(85.0f, -15.0f, 0.0f);
	glVertex3f(85.0f, 75.0f, 0.0f);
	glVertex3f(70.0f, 75.0f, 0.0f);

	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.25f, 0.25f, 0.25f);

	glVertex3f(0.0f, 20.0f, 0.0f);
	glVertex3f(0.0f, 30.0f, 0.0f);
	glVertex3f(-20.0f, 30.0f, 0.0f);
	glVertex3f(-20.0f, 20.0f, 0.0f);

	glEnd();

	glBegin(GL_POLYGON);


	glVertex3f(50.0f, 20.0f, 0.0f);
	glVertex3f(50.0f, 30.0f, 0.0f);
	glVertex3f(70.0f, 30.0f, 0.0f);
	glVertex3f(70.0f, 20.0f, 0.0f);

	glEnd();

	glBegin(GL_POLYGON);

	glColor3f(1.0f, 0.0f, 0.0f);

	glVertex3f(10.0f, 15.0f, 0.0f);
	glVertex3f(40.0f, 15.0f, 0.0f);
	glVertex3f(40.0f, 21.0f, 0.0f);
	glVertex3f(10.0f, 21.0f, 0.0f);

	glEnd();

	glBegin(GL_POLYGON);

	glColor3f(1.0f, 0.0f, 0.0f);

	glVertex3f(12.0f, 30.0f, 0.0f);
	glVertex3f(38.0f, 30.0f, 0.0f);
	glVertex3f(38.0f, 40.0f, 0.0f);
	glVertex3f(12.0f, 40.0f, 0.0f);

	glEnd();
	glPopMatrix();
	glPushMatrix();

	if (enemy_health <= 0) {
		won = 1;
		glBegin(GL_POLYGON);
		glColor3f(0.0f, 1.0f, 0.0f);

		glVertex3f(0.0f, 0.0f, 0.0f);
		glVertex3f(0.0f, 600.0f, 0.0f);
		glVertex3f(1000.0f, 600.0f, 0.0f);
		glVertex3f(1000.0f, 0.0f, 0.0f);
		glEnd();
	}
	if (player_health <= 0) {
		lost = 1;
		glBegin(GL_POLYGON);
		glColor3f(1.0f, 0.0f, 0.0f);

		glVertex3f(0.0f, 0.0f, 0.0f);
		glVertex3f(0.0f, 600.0f, 0.0f);
		glVertex3f(1000.0f, 600.0f, 0.0f);
		glVertex3f(1000.0f, 0.0f, 0.0f);
		glEnd();
	}
	glPopMatrix();

	glFlush();
}

void timer (int x){
	glutPostRedisplay();
	glutTimerFunc(1000/60,timer,0);
	if (bullet<700 && shoot ==1) {
		bullet = bullet + 10;

	}

	timera++;

	if (enemy_health!=0 ) {
		switch (enemy_direction) {

		case 1:
			if (enemy_pos < 1000 - 140) {
				enemy_pos = enemy_pos + 5;
			}
			else {
				enemy_direction = -1;
			}break;
		case -1:
			if (enemy_pos > 60) {
				enemy_pos = enemy_pos - 5;
			}
			else {
				enemy_direction = +1;
			}break;
		}
	}

	std::vector <std::pair<double, double> > bulletskm;
	std::copy_if(bulletsk.begin(), bulletsk.end(), std::back_inserter(bulletskm), [](std::pair<double, double> ay_haga) {
		return ay_haga.second < 650;
		});

	bulletsk = bulletskm;

	for (auto& x:bulletsk) {
		x.second += 10;
		if ((x.first +25 < enemy_pos+170 && x.first +25 > enemy_pos - 50) && x.second == 400) {
			if (!won) {
				enemy_health--;
			}
		
			x.second += 300;

		}
	}
	if (timera%75 ==0) {
		enemy_bulletsk.push_back({ enemy_pos + 25,400+25});
	}

	if (timera % 500 == 0) {
		powerupno = randomNum();
	}

	std::vector <std::pair<double, double> > enemy_bulletskm;
	std::copy_if(enemy_bulletsk.begin(), enemy_bulletsk.end(), std::back_inserter(enemy_bulletskm), [](std::pair<double, double> ay_haga) {
		return ay_haga.second > 0;
		});

	enemy_bulletsk = enemy_bulletskm;

	for (auto& x : enemy_bulletsk) {
		x.second -= 5;
		if ((x.first > player_pos && x.first < player_pos + 20 && x.second > player_posy && x.second < player_posy + 100)||(x.first > player_pos-20 && x.first < player_pos && x.second > player_posy && x.second < player_posy + 25)|| (x.first > player_pos + 20 && x.first < player_pos+40 && x.second > player_posy && x.second < player_posy + 25)) {
			if ((!won) &&(poweredup!=1)) {
				player_health--;
			}

			x.second = -10;

		}
		
	}

	//powerup collision 
	if (powerupno == 1) {
		int x = 250;
		int y = 200;

		if ((x > player_pos && x < player_pos + 20 && y > player_posy && y < player_posy + 100) || (x > player_pos - 20 && x < player_pos && x > player_posy && x < player_posy + 25) || (x > player_pos + 20 && x < player_pos + 40 && y > player_posy && y < player_posy + 25)) {
			poweredup = 1;
			poweredupt = 0;
			powerupno = 8;
		}
	}
	if (powerupno == 2) {
		int x = 450;
		int y = 200;
		if ((x > player_pos && x < player_pos + 20 && y > player_posy && y < player_posy + 100) || (x > player_pos - 20 && x < player_pos && x > player_posy && x < player_posy + 25) || (x > player_pos + 20 && x < player_pos + 40 && y > player_posy && y < player_posy + 25)) {
			poweredup = 1;
			poweredupt = 0;
			powerupno = 8;
		}
	}
	if (powerupno == 3) {
		int x = 650;
		int y = 200;
		if ((x > player_pos && x < player_pos + 20 && y > player_posy && y < player_posy + 100) || (x > player_pos - 20 && x < player_pos && x > player_posy && x < player_posy + 25) || (x > player_pos + 20 && x < player_pos + 40 && y > player_posy && y < player_posy + 25)) {
			poweredup = 1;
			poweredupt = 0;
			powerupno = 8;
		}
	}
	if (powerupno == 4) {
		int x = 150;
		int y = 300;
		if ((x > player_pos && x < player_pos + 20 && y > player_posy && y < player_posy + 100) || (x > player_pos - 20 && x < player_pos && x > player_posy && x < player_posy + 25) || (x > player_pos + 20 && x < player_pos + 40 && y > player_posy && y < player_posy + 25)) {
			poweredup = 1;
			poweredupt = 0;
			powerupno = 8;
		}
	}
	if (powerupno == 5) {
		int x = 350;
		int y = 300;
		if ((x > player_pos && x < player_pos + 20 && y > player_posy && y < player_posy + 100) || (x > player_pos - 20 && x < player_pos && x > player_posy && x < player_posy + 25) || (x > player_pos + 20 && x < player_pos + 40 && y > player_posy && y < player_posy + 25)) {
			poweredup = 1;
			poweredupt = 0;
			powerupno = 8;
		}
	}
	if (powerupno == 6) {
		int x = 750;
		int y = 300;
		if ((x > player_pos && x < player_pos + 20 && y > player_posy && y < player_posy + 100) || (x > player_pos - 20 && x < player_pos && x > player_posy && x < player_posy + 25) || (x > player_pos + 20 && x < player_pos + 40 && y > player_posy && y < player_posy + 25)) {
			poweredup = 1;
			poweredupt = 0;
			powerupno = 8;
		}
	}
	if (powerupno == 7) {
		int x = 550;
		int y = 300;
		if ((x > player_pos && x < player_pos + 20 && y > player_posy && y < player_posy + 100) || (x > player_pos - 20 && x < player_pos && x > player_posy && x < player_posy + 25) || (x > player_pos + 20 && x < player_pos + 40 && y > player_posy && y < player_posy + 25)) {
			poweredup = 1;
			poweredupt = 0;
			powerupno = 8;
		}
	}

	poweredupt++;
	//powerdown
	if (poweredupt==200) {
		poweredupt = 0;
		poweredup = 0;
	}
}

void key(unsigned char k, int x, int y)
// k is the key pressed from the keyboard
// x and y are mouse postion when the key was pressed.
{
	if (k == 'd')//if the letter d is pressed, then the object will be translated in the x axis by 10 (moving to the right).
		if (player_pos < 1000 - 45 && player_health != 0) {
			player_pos += 10;
		}
	if (k == 'a')//if the letter a is pressed, then the object will be translated in the x axis by -10 (moving to the left).
		if (player_pos > 25 && player_health != 0) {
			player_pos -= 10;
		}	glutPostRedisplay();//redisplay to update the screen with the changes
	if (k == 'h')//if the letter a is pressed, then the object will be translated in the x axis by -10 (moving to the left).
		if (player_health!=0) { player_health--; }
			glutPostRedisplay();//redisplay to update the screen with the changes
	if (k == 'j')//if the letter a is pressed, then the object will be translated in the x axis by -10 (moving to the left).
		if (enemy_health != 0) { enemy_health--; }

			glutPostRedisplay();//redisplay to update the screen with the changes
	if (k == 'e')//if the letter a is pressed, then the object will be translated in the x axis by -10 (moving to the left).
				if (!won) { bulletsk.push_back({ player_pos + 10,player_posy }); }

			glutPostRedisplay();//redisplay to update the screen with the changes
	if (k == 's')//if the letter a is pressed, then the object will be translated in the x axis by -10 (moving to the left).
				if (player_pos > 25 && player_health != 0) {
					player_posy -= 10;
				}	glutPostRedisplay();//redisplay to update the screen with the changes
	if (k == 'w')//if the letter a is pressed, then the object will be translated in the x axis by -10 (moving to the left).
					if (player_pos > 25 && player_health != 0) {
						player_posy += 10;
					}	glutPostRedisplay();//redisplay to update the screen with the changes

					if (k == 'p')//if the letter a is pressed, then the object will be translated in the x axis by -10 (moving to the left).
						poweredup = 1;
							glutPostRedisplay();//redisplay to update the screen with the changes
}


class player {
public:
	int player_position = player_pos;
	public:int player_health = 3;

	void healthdown() {
		player_health--;
	}
};

int randomNum() {
	return 1 + std::rand() % 7;
}