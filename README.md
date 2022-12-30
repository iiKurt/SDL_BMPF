# SDL_BMPF
## SDL Bitmap Font

Add simplest text output to your SDL program. Inline font included. Font collection included.

Has almost no good use cases; however, I found myself reusing this code/font format over
and over, so maybe you would find some use for it too. 

 * If you're serious about inlining your images, use something like
[GRIT][grit] instead.
 * If you're serious about bitmap fonts, a meta-data-less bitmap is not enough,
use [Sfont][sfont] instead.
 * If you're *really* serious about fonts, and want Unicode and italics and
everything, use [SDL_ttf][ttf] instead.

 [grit]: http://www.coranac.com/projects/grit/
 [sfont]: http://www.linux-games.com/sfont/
 [ttf]: http://www.libsdl.org/projects/SDL_ttf/

## Fork notes
This is an edit of the [original code](https://github.com/driedfruit/SDL_inprint). I've removed excess stuff I didn't need and cleaned up the code.
Extra features like line wrapping and text centering is included. Possible bugs too.

## How to use

Build `BMPF.c` with your project.
Include `BMPF.h`.

Now, you can:

```c
    SDL_Surface* bmpSurface = SDL_LoadBMP("fonts/zap-light16.bmp");
    SDL_Texture* bmpTexture = SDL_CreateTextureFromSurface(renderer, bmpSurface);
    BMPF_initalise(bmpTexture);
    SDL_FreeSurface(bmpSurface);

    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    BMPF_print(renderer, "Hello world!", 100, 50);

    BMPF_kill();
```

The whole demo is in 'main.c'.

You would also probably want to automate the inlining into the build process,
which shouldn't be hard. See 'Makefile' for an example.

## Font collection

All the fonts in the 'fonts/' directory are free (or should be free, correct me
when I'm wrong) and adhere to the convention described below. Feel free to add
your fonts or make old ones prettier (it's actually quite fun to work on bitmap
fonts even if you're not that good at graphics). 

A possible exception to this is `zap-light16.bmp` from [The ZAP Group](https://www.zap.org.au/projects/console-fonts-zap/).

## Bitmap fonts

 * First half of ASCII table (128 symbols).
 * Formatted as 16 x 8 table.
 * Color 0 is background.
 * Color 1 is foreground.
 * One Bit Per Pixel. 1BPP. *Bit*map.

## Inline fonts

Inline fonts are in [XBM format][xbm].

 [xbm]: http://en.wikipedia.org/wiki/X_BitMap

You can generate them, using the included `bmp2xbm` tool.
