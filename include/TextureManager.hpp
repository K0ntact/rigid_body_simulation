#ifndef TEXTUREMANAGER_HPP
#define TEXTUREMANAGER_HPP

#include <string>
#include <map>

#include "SDL.h"

/* Singleton class */
class TextureManager {
private:
    static TextureManager* s_pInstance;
    TextureManager();

public:
    static TextureManager* Instance() {
        if(s_pInstance == nullptr) {
            s_pInstance = new TextureManager();
            return s_pInstance;
        }
        return s_pInstance;
    }
    ~TextureManager();

    std::map<std::string, SDL_Texture*> m_textureMap;   // map the texture to string for easy access

    /**
     * For loading texture from a sprite sheet, or a single image.
     * After loading, the texture is stored in a map, with a string as key.
     * Use with draw() or drawFrame()
     *
     * @param filePath path to the image file
     * @param id a string to identify the texture
     * @param pRenderer the renderer to draw the texture
     *
     * @return true if successful, false otherwise
     */
    bool load(std::string filePath,
              std::string id,
              SDL_Renderer* pRenderer);

    /**
     * For drawing single image
     *
     * @param id the string used to identify the texture
     * @param x the x coordinate on the screen
     * @param y the y coordinate on the screen
     * @param width the width of the image
     * @param height the height of the image
     * @param pRenderer the renderer to draw the texture
     * @param offset_x x offset on the texture. Default 0
     * @param offset_y y offset on the texture. Default 0
     * @param zoom zoom the image on the screen. Default 1
     * @param flip flip the image. Default SDL_FLIP_NONE
     */
    void draw(std::string id,
              int x, int y, int width, int height,
              SDL_Renderer* pRenderer,
              int offset_x = 0, int offset_y = 0,
              int zoom = 1,
              SDL_RendererFlip flip = SDL_FLIP_NONE);

    /**
     * For drawing sprite sheets
     *
     * @param id the string used to identify the texture
     * @param x x coordinate on the screen
     * @param y y coordinate on the screen
     * @param width width of the image
     * @param height height of the image
     * @param currentRow row position of the image on the sprite sheet. Starts from 0
     * @param currentFrame frame position on the row. Starts from 0
     * @param offset_x x offset on the texture. Default 0
     * @param offset_y y offset on the texture. Default 0
     * @param zoom zoom the image on the screen. Default 1
     * @param flip flip the image. Default SDL_FLIP_NONE
     */
    void drawFrame(std::string id,
                   int x, int y, int width, int height,
                   int currentRow, int currentFrame,
                   SDL_Renderer* pRenderer,
                   int offset_x = 0, int offset_y = 0,
                   int zoom = 1,
                   SDL_RendererFlip flip = SDL_FLIP_NONE);
};

#endif //TEXTUREMANAGER_HPP
