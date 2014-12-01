#include "makepng.h"
#include <cmath>
#include <iostream>
#include "Station.h"

#include "lodepng.h"

#define DISPCOEF 1

using namespace std;

void generateImage(const float xmin, const float xmax,
    const float ymin, const float ymax,
    const float min, const float max,
    const float step, float(*interp)(float, float,vector<Station>&),
    vector<Station> &stations)
{
  //create encoder and set settings and info (optional)
  lodepng::State state;

  //generate palette
  for(int i = min; i < max; i++)
  {
    /*
    unsigned char r = 127 * (1 + std::sin(5 * i * 6.28318531 / 16));
    unsigned char g = 127 * (1 + std::sin(2 * i * 6.28318531 / 16));
    unsigned char b = 127 * (1 + std::sin(3 * i * 6.28318531 / 16));
    unsigned char a = 63 * (1 + std::sin(8 * i * 6.28318531 / 16)) + 128; */ /*alpha channel of the palette (tRNS chunk)*/

    unsigned int range = (max-min);
    unsigned char r =((float) 255.0/range) *i;
    unsigned char g = ((float) 255.0/range) *(range-i);
    unsigned char b = g/2;
    unsigned char a = 155;


    //palette must be added both to input and output color mode, because in this
    //sample both the raw image and the expected PNG image use that palette.
    lodepng_palette_add(&state.info_png.color, r, g, b, a);
    lodepng_palette_add(&state.info_raw, r, g, b, a);
  }

  //both the raw image and the encoded image must get colorType 3 (palette)
  state.info_png.color.colortype = LCT_PALETTE; //if you comment this line, and create the above palette in info_raw instead, then you get the same image in a RGBA PNG.
  state.info_png.color.bitdepth = 4;
  state.info_raw.colortype = LCT_PALETTE;
  state.info_raw.bitdepth = 4;
  state.encoder.auto_convert = 0; //we specify ourselves exactly what output PNG color mode we want

  // Generation of the matrix
  const unsigned w = (unsigned)( (xmax - xmin)/step);
  const unsigned h = (unsigned)( (ymax - ymin)/step);
  std::cerr << xmax << " xmax & xmin " << xmin << endl;
  std::cerr << ymax << " ymax & ymin " << ymin << endl;
  std::cerr << w << " w & h " << h << endl;
  std::vector<unsigned char> image;
  image.resize((w * h * 4 + 7) / 8, 0);
  for(unsigned y = 0; y < h; y++)
  for(unsigned x = 0; x < w; x++)
  {
    size_t byte_index = (y * w + x) / 2;
    bool byte_half = (y * w + x) % 2 == 1;

    /*
    int color = (int)(4 * ((1 + std::sin(2.0 * 6.28318531 * x / (double)w))
                         + (1 + std::sin(2.0 * 6.28318531 * y / (double)h))) );

    */
    //cout << (int)(interp(xmin+step*x,ymin+step*y,stations)*DISPCOEF) 
    //  << " x " << xmin+step*x << " y " << ymin+step*y<<endl;
    int color = (int)(interp(xmin+step*x,ymax-step*y,stations)*0.9);
    image[byte_index] |= (unsigned char)(color << (byte_half ? 0 : 4));
  }

  //encode and save
  std::vector<unsigned char> buffer;
  unsigned error = lodepng::encode(buffer, image.empty() ? 0 : &image[0], w, h, state);
  if(error)
  {
    std::cout << "encoder error " << error << ": "<< lodepng_error_text(error) << std::endl;
  }
  lodepng::save_file(buffer, "interp.png");
}
