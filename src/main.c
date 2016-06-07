
#include <SDL.h>
#include <stdio.h>
#include <stdbool.h>

void render_box(SDL_Renderer* rdr, float mX, float mY, float perc)
{
    float x1, x2, y1, y2;
    x1 = mX * perc;
    y1 = mY * perc;
    x2 = 1024 - ( (1024 - mX) * perc );
    y2 = 768 - ( (768 - mY) * perc );

    SDL_RenderDrawLine(rdr, x1, y1, x2, y1); // Top-Left to Bot-Left
    SDL_RenderDrawLine(rdr, x1, y1, x1, y2); // Top-Left to Top-Right
    SDL_RenderDrawLine(rdr, x2, y1, x2, y2); // Bot-Left to Bot-Right
    SDL_RenderDrawLine(rdr, x1, y2, x2, y2); // Top-Right to Bot-Left
}

int main(int argc, char** argv)
{   
    SDL_Init(SDL_INIT_VIDEO);

    SDL_Window* win = SDL_CreateWindow(
        "C SDL Test",
        SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED,
        1024,
        768,
        SDL_WINDOW_OPENGL
    );

    if (!win) 
    {
        printf("Error creating SDL Window %s\n", SDL_GetError());
        return 1;
    }

    SDL_Renderer* rdr = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED);

    float mX, mY;
    mX = mY = 0.0f;

    bool running = true;
    SDL_Event evt;
    while (running)
    {
        while (SDL_PollEvent(&evt))
        {
            switch (evt.type)
            {
                case SDL_QUIT:
                    running = false;
                    break;
                case SDL_KEYDOWN:

                    break;
                case SDL_MOUSEBUTTONDOWN: 

                    break;
                case SDL_MOUSEMOTION:
                    mX = evt.motion.x;
                    mY = evt.motion.y;
                    break;
            }
        }

        SDL_RenderClear(rdr);

        render_box(rdr, mX, mY, 0.2f);
        render_box(rdr, mX, mY, 0.4f);
        render_box(rdr, mX, mY, 0.6f);
        render_box(rdr, mX, mY, 0.8f);

        SDL_RenderDrawLine(rdr, 0, 0, mX, mY);
        SDL_RenderDrawLine(rdr, 1024, 0, mX, mY);
        SDL_RenderDrawLine(rdr, 0, 768, mX, mY);
        SDL_RenderDrawLine(rdr, 1024, 768, mX, mY);
        SDL_RenderPresent(rdr);
    }    

    SDL_DestroyRenderer(rdr);
    SDL_DestroyWindow(win);
    SDL_Quit();
    return 0;
}
