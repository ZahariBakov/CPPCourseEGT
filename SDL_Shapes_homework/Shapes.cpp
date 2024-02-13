#include "Shapes.h"

#include <math.h>

void Shapes::drawRecnatgle(SDL_Renderer* renderer, int xpos, int ypos, int width, int height, int border) {
	SDL_Rect fillRect = { xpos, ypos, width, height };
	SDL_SetRenderDrawColor(renderer, 0xFF, 0x00, 0x00, 0xFF);
	SDL_RenderFillRect(renderer, &fillRect);

	SDL_Rect secondFillRect = { xpos + border, ypos + border, width - (border * 2), height - (border * 2) };
	SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
	SDL_RenderFillRect(renderer, &secondFillRect);
}

void Shapes::drawPentagon(SDL_Renderer* renderer, int xpos, int ypos, int side) {
	int x, y;
	int n = 5;
	double angle = (2 * M_PI) / n;
	double radius = side / (2 * sin(M_PI / n));
	SDL_Point points[6];
	for (int i = 0; i < n + 1; ++i) {
		y = (int)round(sin(angle * i) * radius);
		x = (int)round(cos(angle * i) * radius);
		points[i] = { x + xpos, y + ypos };
	}
	const SDL_Point* pts = points;
	SDL_RenderDrawLines(renderer, pts, n + 1);
}

void Shapes::drawHexagon(SDL_Renderer* renderer, int xpos, int ypos, int side) {
	int x, y;
	int n = 6;
	double angle = (2 * M_PI) / n;
	double radius = side / (2 * sin(M_PI / n));
	SDL_Point points[7];
	for (int i = 0; i < n + 1; ++i) {
		y = (int)round(sin(angle * i) * radius);
		x = (int)round(cos(angle * i) * radius);
		points[i] = { x + xpos, y + ypos };
	}
	const SDL_Point* pts = points;
	SDL_RenderDrawLines(renderer, pts, n + 1);
}

void Shapes::drawCircle(SDL_Renderer* renderer, int xpos, int ypos, int radius) {
	const int diameter = radius * 2;

	int x = (radius - 1);
	int y = 0;
	int tx = 1;
	int ty = 1;
	int error = tx - diameter;

	while (x >= y) {
		SDL_RenderDrawPoint(renderer, xpos + x, ypos - y);
		SDL_RenderDrawPoint(renderer, xpos + x, ypos + y);
		SDL_RenderDrawPoint(renderer, xpos - x, ypos - y);
		SDL_RenderDrawPoint(renderer, xpos - x, ypos + y);
		SDL_RenderDrawPoint(renderer, xpos + y, ypos - x);
		SDL_RenderDrawPoint(renderer, xpos + y, ypos + x);
		SDL_RenderDrawPoint(renderer, xpos - y, ypos - x);
		SDL_RenderDrawPoint(renderer, xpos - y, ypos + x);

		if (error <= 0) {
			y++;
			error += ty;
			ty += 2;
		}

		if (error > 0) {
			x--;
			tx += 2;
			error += tx - diameter;
		}
	}
}

void Shapes::drawPolygon(SDL_Renderer* renderer, int xpos, int ypos, int side, int radius) {
	int x, y;
	double angle = (2 * M_PI) / side;
	SDL_Point* points = new SDL_Point[side + 1];
	for (int i = 0; i < side + 1; ++i) {
		y = (int)round(sin(angle * i) * radius);
		x = (int)round(cos(angle * i) * radius);
		points[i] = { x + xpos, y + ypos };
	}
	const SDL_Point* pts = points;
	SDL_RenderDrawLines(renderer, pts, side + 1);

	delete[] points;
}

void Shapes::drawEllipse(SDL_Renderer* renderer, int xRad, int yRad, int xpos, int ypos) {
	float dx, dy, d1, d2, x, y;
	x = 0;
	y = yRad;

	// Initial decision parameter of region 1
	d1 = (yRad * yRad) - (xRad * xRad * yRad) + (0.25 * xRad * xRad);
	dx = 2 * yRad * yRad * x;
	dy = 2 * xRad * xRad * y;

	while (dx < dy) {

		// Draw points based on 4-way symmetry
		SDL_RenderDrawPoint(renderer, x + xpos, y + ypos);
		SDL_RenderDrawPoint(renderer, -x + xpos, y + ypos);
		SDL_RenderDrawPoint(renderer, x + xpos, -y + ypos);
		SDL_RenderDrawPoint(renderer, -x + xpos, -y + ypos);

		// Checking and updating value of
		// decision parameter based on algorithm
		if (d1 < 0) {
			x++;
			dx = dx + (2 * yRad * yRad);
			d1 = d1 + dx + (yRad * yRad);
		}
		else {
			x++;
			y--;
			dx = dx + (2 * yRad * yRad);
			dy = dy - (2 * xRad * xRad);
			d1 = d1 + dx - dy + (yRad * yRad);
		}
	}

	// Decision parameter of region 2
	d2 = ((yRad * yRad) * ((x + 0.5) * (x + 0.5))) +
		((xRad * xRad) * ((y - 1) * (y - 1))) -
		(xRad * xRad * yRad * yRad);

	// Plotting points of region 2
	while (y >= 0) {

		// Draw points based on 4-way symmetry
		SDL_RenderDrawPoint(renderer, x + xpos, y + ypos);
		SDL_RenderDrawPoint(renderer, -x + xpos, y + ypos);
		SDL_RenderDrawPoint(renderer, x + xpos, -y + ypos);
		SDL_RenderDrawPoint(renderer, -x + xpos, -y + ypos);

		// Checking and updating parameter
		// value based on algorithm
		if (d2 > 0) {
			y--;
			dy = dy - (2 * xRad * xRad);
			d2 = d2 + (xRad * xRad) - dy;
		}
		else {
			y--;
			x++;
			dx = dx + (2 * yRad * yRad);
			dy = dy - (2 * xRad * xRad);
			d2 = d2 + dx - dy + (xRad * xRad);
		}
	}
}
