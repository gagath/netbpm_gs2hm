/*
 * This file is part of netbpm_gs2hm.
 * Copyright (C) 2015 Romain PORTE.
 *
 * netbpm_gs2hm is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * netbpm_gs2hm is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with netbpm_gs2hm. If not, see <http://www.gnu.org/licenses/>.
 */

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
