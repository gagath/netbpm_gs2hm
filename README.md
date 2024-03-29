# Netpbm Grayscale to Heatmap-like Pixmap

Read an ASCII PGM Grayscale image (`*.pgm`) on stdin and returns an hot-to-cold
ASCII PPM RGB image (`*.ppm`) on stdout.

## Description

This program may be used to convert grayscale images to heatmap-like ones. The
[Netbpm format](https://en.wikipedia.org/wiki/Netpbm_format) is used here for it
simplicity (ASCII support only). Although PGM/PPM are not common file formats,
you may use it as an intermediate result for easy processing on it and then
convert it to an efficient format such as PNG.

You can convert images to ASCII PGM using ImageMagick:

    $ convert input.png -compress none output.png

## Building

This program is written in bare C, you will only need a C compiler and run the
Makefile:

    $ make

No dependencies (apart from the C standard library) are required.

File extensions memento for PPM files:

 - `*.pbm` : portable bitmap (black & white)
 - `*.pgm` : portable greymap (greyscale)
 - `*.ppm` : portable pixmap (RGB)

## Usage

Example usage:

    $ ./netpbm_gs2hm < input.pgm > result.ppm

You can then visualize the resulting image using a Netpbm-compatible image
viewer such as `feh`.

## Sample

![Greyscale version](https://i.imgur.com/DRZ9uwC.png)
![Colorized version](https://i.imgur.com/ZN129Tw.png)

## Copyright

This program is brought to you under GNU General Public License v3+. For
further informations please read the COPYING file.

## References

 - <http://en.wikipedia.org/wiki/Netpbm_format>
 - <http://stackoverflow.com/questions/7706339/grayscale-to-red-green-blue-matlab-jet-color-scale>
