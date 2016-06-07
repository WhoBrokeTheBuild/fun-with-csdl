
#include <SDL.h>
#include <stdio.h>
#include <stdbool.h>

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
       
        int stepCount = 20;
        float step = mX / stepCount;
        for (int i = 0; i < stepCount; ++i) 
        {
            SDL_RenderDrawLine(rdr, 0, 0,   mX - (i * step), mY);
            SDL_RenderDrawLine(rdr, 0, 768, mX - (i * step), mY);
        }

        step = (1024 - mX) / stepCount;
        for (int i = 0; i < stepCount; ++i)
        {
            SDL_RenderDrawLine(rdr, 1024, 0,   mX + (i * step), mY);
            SDL_RenderDrawLine(rdr, 1024, 768, mX + (i * step), mY); 
        }

        step = mY / stepCount;
        for (int i = 0; i < stepCount; ++i)
        {
            SDL_RenderDrawLine(rdr, 0,    0, mX, mY - (i * step));
            SDL_RenderDrawLine(rdr, 1024, 0, mX, mY - (i * step)); 
        }

        step = (768 - mY) / stepCount;
        for (int i = 0; i < stepCount; ++i)
        {
            SDL_RenderDrawLine(rdr, 0,    768, mX, mY + (i * step));
            SDL_RenderDrawLine(rdr, 1024, 768, mX, mY + (i * step)); 
        }

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
