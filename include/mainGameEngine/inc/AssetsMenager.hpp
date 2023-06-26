#pragma once

#include <memory>
#include <vector>

#include <SFML/Graphics.hpp>

#include <AssetsMenagerIf.hpp>

class AssetsMenager : public AssetsMenagerIf
{
public:
  AssetsMenager();
  ~AssetsMenager() = default;

  AssetsMenager(AssetsMenager&& ) = delete;
  AssetsMenager(const AssetsMenager& ) = delete;
  AssetsMenager& operator=(const AssetsMenager& ) = delete;
  AssetsMenager& operator=(AssetsMenager&& ) = delete;

  void loadBasicFont() override;
  void loadBasicTexture() override;

  std::shared_ptr<sf::Font> getBasicFont();
  std::shared_ptr<sf::Texture> getBasicTexture();

protected:

private:

  std::shared_ptr<sf::Font> m_upMainFont;
  std::shared_ptr<sf::Texture> m_texture;
  //std::unique_ptr<DrawableManagerIf> sp_mDrawable;

  //std::unique_ptr<sf::Text> m_upText;
};