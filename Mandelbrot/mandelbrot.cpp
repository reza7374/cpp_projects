#include <SDL2/SDL.h>
#include <iostream>
#include <numeric>
#include <complex>

// Linear interpolation function
double lerp(double a, double b, double t) {
    return a + t * (b - a);
}



int is_in_set(std::complex<double> c ) {
    std::complex<double> z(0, 0);
    for (int i = 0; i < 250; i++) 
    {
        z = std::pow(z, 2) + c; 
        if (std::norm(z)>10)
        {
            return i;

        }
    }
    return 0;

 }


int main(){
    
    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_Window* window = nullptr;
    SDL_Renderer* renderer = nullptr;
    SDL_CreateWindowAndRenderer(2000, 2000, 0, &window, &renderer);
    SDL_RenderSetScale(renderer, 1, 1);

    for (double x = 0.0; x <1.0; x += 0.001){
        for (double y = 0.0; y <1.0; y += 0.001){
            double point_x = lerp(-2., 2., x);
            double point_y = lerp(-2., 2., y);
            int iters = is_in_set(std::complex<double>(point_x, point_y));
            if (iters == 0){
                SDL_SetRenderDrawColor(renderer, 12, 20, 0, 255);
                SDL_RenderDrawPointF(renderer, x*1000, y*1000);
            }

            else{
                SDL_SetRenderDrawColor(renderer,
                                        42*iters%255, 
                                        3*iters%255,
                                        25*iters%255,
                                        255);
                SDL_RenderDrawPointF(renderer, x*1000, y*1000);
            }
        }
    }

    SDL_RenderPresent(renderer);
    SDL_Delay(5000);
    std::cout<<"mango"<<std::endl;
    return 0;
}
