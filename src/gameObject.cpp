#include "gameObject.hpp"
#include "TextureManager.hpp"

void GameObject::load(int x, int y, int width, int height, std::string textureID) {
    m_x = x;
    m_y = y;
    m_width = width;
    m_height = height;
    m_textureID = textureID;
}

void GameObject::draw(SDL_Renderer* pRenderer) {
    TextureManager::Instance()->draw(m_textureID, m_x, m_y, m_width, m_height, pRenderer);
}

void GameObject::update() {
    m_x += 1;
    m_y += 1;
}

void GameObject::clean() {

}