#pragma once


#include "src/core/game_renderer.h";

namespace GameRenderer {

    void GameRenderer::clearScreen() {
        system("CLS");
    }

    // Function to render the game state
    void GameRenderer::render(ShopGame::Game* game) {
         clearScreen();

          // Calculate FPS
        static auto lastTime = std::chrono::high_resolution_clock::now();
        auto currentTime = std::chrono::high_resolution_clock::now();
        double deltaTime = std::chrono::duration<double, std::milli>(currentTime - lastTime).count();
        lastTime = currentTime;
        double fps = 1000.0 / deltaTime; // Calculate frames per second

        // Smooth the FPS display by updating less frequently
        static double smoothedFps = 0.1;
        const double smoothingFactor = 0.1; // Adjust smoothing factor as needed

        smoothedFps = (smoothingFactor * fps) + ((1.0 - smoothingFactor) * smoothedFps);

 
     
      //  game->getCanvas()->drawText(Vec2( 1, 1), "FPS: " + std::to_string(static_cast<int>(smoothedFps)));


        game->render();
        game->getCanvas()->clear(); //Clear the buffer after rendering the current canvas
       

        std::this_thread::sleep_for(std::chrono::milliseconds(1)); 
    }

} // namespace GameRenderer
