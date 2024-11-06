

#include <stdio.h>
#include <graphics.h>
#include "conio.h"
#include "EasyXPng.h"

#define WIDTH  600
#define HEIGHT 480
#define ROAD_Y 380    // Adjust this value to match your road's y-position
#define FRAMES 4

int speed = 10; // Speed of movement
int x = WIDTH / 2; // Start in the middle of the screen
int y = ROAD_Y; // Start at the road's y-position
int frameIndex = 0; // Current frame index

int main() {
	IMAGE im_bk; // Declare background image
	initgraph(WIDTH, HEIGHT);

	TCHAR filename[100];
	IMAGE img[FRAMES]; // Array for dragon frames

	// Load dragon animation frames
	for (int i = 0; i < FRAMES; i++) {
		_stprintf_s(filename, 100, _T("Z:\\Desktop\\assets\\Materials\\Dragon\\d%d.png"), i); // Dragon frames
		loadimage(&img[i], filename);
	}

	loadimage(&im_bk, _T("Z:\\Desktop\\assets\\Materials\\bg.png")); // Load background image

	BeginBatchDraw();
	while (1) {
		putimage(0, 0, &im_bk); // Draw the background

		// Draw the dragon image
		putimagePng(x, y, &img[frameIndex]); // Draw dragon

		// Handle keyboard input for movement
		if (GetAsyncKeyState(VK_RIGHT) && x < WIDTH - 50) { // Move right
			x += speed;
		}
		if (GetAsyncKeyState(VK_LEFT) && x > 0) { // Move left
			x -= speed;
		}
		if (GetAsyncKeyState(VK_UP) && y > 0) { // Move up
			y -= speed;
		}
		if (GetAsyncKeyState(VK_DOWN) && y < HEIGHT - 50) { // Move down
			y += speed;
		}

		// Update frame index for animation
		frameIndex = (frameIndex + 1) % FRAMES;

		Sleep(60); // Control frame rate
		FlushBatchDraw(); // Refresh the screen

		// Exit condition (press ESC to quit)
		if (GetAsyncKeyState(VK_ESCAPE)) {
			break;
		}
	}

	closegraph();
	return 0;
}
