#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* Colorize functions */

float red(float value)
{
	if (value > 0.5f)
	{
		if (value < 0.75f)
			return (value - 0.5f) * 4.f;
		else
			return 1.f;
	}

	return 0.f;
}

float green(float value)
{
	if (value < 0.25f)
		return value * 4.f;
	else if (value > 0.75f)
		return 1 - ((value - 0.75f) * 4.f);

	return 1.f;
}

float blue(float value)
{
	if (value < 0.25f)
		return 1.f;
	else if (value < 0.5f)
		return 1 - ((value - 0.25f) * 4);

	return 0.f;
}

/* IO functions */

void skipline(FILE *f)
{
	while (fgetc(f) != '\n');
}

/* Main program */

int main(void)
{
	int width, height;
	int resolution;
	int i, j;

	int value;
	float fvalue;

	/* Write image header */
	skipline(stdin);
	fprintf(stdout, "P3\n");

	/* Read image size */
	fscanf(stdin, "%d %d\n", &width, &height);
	fprintf(stdout, "%d %d\n", width, height);

	/* Read color resolution */
	fscanf(stdin, "%d\n", &resolution);
	fprintf(stdout, "%d\n", resolution);

	/* Read each pixel, colorize it, and write it */
	for (i = 0; i < height; ++i) {
		for (j = 0; j < width; ++j) {
			fscanf(stdin, "%d", &value);
			fvalue = value / (float) resolution;

			fprintf(stdout, "%d %d %d ",
				(int) (red(fvalue) * resolution),
				(int) (green(fvalue) * resolution),
				(int) (blue(fvalue) * resolution)
			);
		}
		fprintf(stdout, "\n");
	}

	return 0;
}
