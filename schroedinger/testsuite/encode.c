
#ifdef HAVE_CONFIG_H
#include "config.h"
#endif


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <schroedinger/schro.h>

#define ROUND_UP_2(x) (((x) + 1) & ~1)
#define ROUND_UP_4(x) (((x) + 3) & ~3)
#define ROUND_UP_8(x) (((x) + 7) & ~7)

static void
frame_free (SchroFrame *frame, void *priv)
{
  free (priv);
}

void
test (int w, int h)
{
  int i;
  int size;
  uint8_t *picture;
  SchroEncoder *encoder;
  SchroBuffer *buffer;
  SchroFrame *frame;

  encoder = schro_encoder_new();
  schro_encoder_set_size (encoder, w, h);

  size = ROUND_UP_4 (w) * ROUND_UP_2 (h);
  size += (ROUND_UP_8 (w)/2) * (ROUND_UP_2 (h)/2);
  size += (ROUND_UP_8 (w)/2) * (ROUND_UP_2 (h)/2);

  for(i=0;i<10;i++){
    picture = malloc(size);
    memset(picture, 128, size);

    frame = schro_frame_new_I420 (picture, w, h);

    schro_frame_set_free_callback (frame, frame_free, picture);

    schro_encoder_push_frame (encoder, frame);

    buffer = schro_encoder_encode (encoder);
    if (buffer) {
      schro_buffer_unref (buffer);
    }
  }
  schro_encoder_end_of_stream (encoder);
  while ((buffer = schro_encoder_encode (encoder))) {
    schro_buffer_unref (buffer);
  }

  schro_encoder_free (encoder);
}

int
main (int argc, char *argv[])
{
  int h, w;

  schro_init();

  for(w=64;w<64+16;w++){
    for(h=64;h<64+16;h++){
      test(w,h);
      exit(0);
    }
  }

  return 0;
}


