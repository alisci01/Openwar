#pragma once

#include "gameplay.h"

class HWResManager;

using namespace gameplay;

/**
 * Main game class.
 */
class OpenwarGame: public Game
{
// members
protected:
	HWResManager* hardwarResManager;

private:
	Scene* _scene;
	bool _wireframe;

// functions
public:

	/**
	 * Constructor.
	 */
    OpenwarGame();

	/**
	 * @see Game::keyEvent
	 */
	void keyEvent(Keyboard::KeyEvent evt, int key) override;
	
	/**
	 * @see Game::touchEvent
	 */
	void touchEvent(Touch::TouchEvent evt, int x, int y, unsigned int contactIndex) override;

protected:

	/**
	 * @see Game::initialize
	 */
	void initialize() override;

	/**
	 * @see Game::finalize
	 */
	void finalize() override;

	/**
	 * @see Game::update
	 */
	void update(float elapsedTime) override;

	/**
	 * @see Game::render
	 */
	void render(float elapsedTime) override;

private:

    /**
     * Draws the scene each frame.
     */
    bool drawScene(Node* node);
};