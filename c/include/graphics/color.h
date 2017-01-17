#ifndef COLOR_H
#define COLOR_H

typedef union
{
	float v[4];
	struct {
		float r,g,b,a;
	};
} color_t;

extern const color_t COLOR_CLIFF;
extern const color_t COLOR_DEEP_WATER;
extern const color_t COLOR_WATER;
extern const color_t COLOR_SWAMP;
extern const color_t COLOR_SOFT_SAND;
extern const color_t COLOR_DENSE_BUSHES;
extern const color_t COLOR_TALL_GRASS;
extern const color_t COLOR_HARD_SAND;
extern const color_t COLOR_GRASS;

extern const color_t LIGHT_GRAY;
extern const color_t LIGHT_RED;
extern const color_t LIGHT_GREEN;
extern const color_t LIGHT_BLUE;
extern const color_t LIGHT_CYAN;
extern const color_t LIGHT_MAGENTA;
extern const color_t LIGHT_YELLOW;

extern const color_t WHITE;
extern const color_t GRAY;
extern const color_t BLACK;
extern const color_t RED;
extern const color_t GREEN;
extern const color_t BLUE;
extern const color_t CYAN;
extern const color_t MAGENTA;
extern const color_t YELLOW;

#endif